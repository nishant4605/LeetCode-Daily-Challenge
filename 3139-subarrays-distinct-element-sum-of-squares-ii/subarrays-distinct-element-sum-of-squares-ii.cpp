class Solution {
public:
    const long long MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> seg;
    int n;

    void update(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            seg[node].sq = (seg[node].sq
                + 2 * seg[node].sum
                + (end - start + 1)) % MOD;

            seg[node].sum = (seg[node].sum
                + (end - start + 1)) % MOD;

            seg[node].lazy++;
            return;
        }

        int mid = (start + end) / 2;

        push(node, start, end);

        update(node * 2, start, mid, l, r);
        update(node * 2 + 1, mid + 1, end, l, r);

        seg[node].sum =
            (seg[node * 2].sum + seg[node * 2 + 1].sum) % MOD;

        seg[node].sq =
            (seg[node * 2].sq + seg[node * 2 + 1].sq) % MOD;
    }

    void push(int node, int start, int end) {
        if (seg[node].lazy == 0 || start == end) return;

        long long lazy = seg[node].lazy;
        int mid = (start + end) / 2;

        apply(node * 2, start, mid, lazy);
        apply(node * 2 + 1, mid + 1, end, lazy);

        seg[node].lazy = 0;
    }

    void apply(int node, int start, int end, long long val) {
        long long len = end - start + 1;

        seg[node].sq = (seg[node].sq
            + 2 * val % MOD * seg[node].sum
            + val * val % MOD * len) % MOD;

        seg[node].sum = (seg[node].sum + val * len) % MOD;
        seg[node].lazy += val;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i])) {
                prev = last[nums[i]];
            }

            update(1, 0, n - 1, prev + 1, i);

            last[nums[i]] = i;

            ans = (ans + seg[1].sq) % MOD;
        }

        return ans;
    }
};