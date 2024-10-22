#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* cur = head;
        vector<int>vec;
        while (cur) {
            vec.push_back(cur->val);
            cur = cur->next;
        }
        sort(vec.begin(), vec.end());
        cur = head;
        for (auto& i : vec) {
            cur->val = i;
            cur = cur->next;
        }
        return head;
    }
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)return NULL;
        ListNode* cur1=new ListNode(-5001, head), * cur2 = head;
        while (cur2&&cur2->next) {
            if (cur2->next->val >= cur2->val) {
                cur2 = cur2->next;
                continue;
            }
            ListNode* temp = cur1;
            while (temp->next&&temp->next->val < cur2->next->val) {
                temp = temp->next;
            }
            ListNode* node1 = temp->next;
            ListNode* node2 = cur2->next->next;
            temp->next = cur2->next;
            cur2->next->next = node1;
            cur2->next = node2;
        }
        return cur1->next;
    }
};
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)return NULL;
        return dfs(node);
    }
    unordered_map<Node*, Node*>mp;
    Node* dfs(Node* node) {
        if (mp[node])return mp[node];
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for (auto& i : node->neighbors) {
            clone->neighbors.push_back(dfs(i));
        }
        return clone;
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size(), col = triangle.back().size();
        vector<vector<int>>dp(row, vector<int>(col, 0));
        for (int i = 0; i < col; i++)dp[row - 1][i] = triangle[row - 1][i];
        for (int i = row - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        ListNode* cur = head;
        while (cur) {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        return build(nums, 0, nums.size());
    }
    TreeNode* build(vector<int>&nums,int l,int r) {
        if (l > r)return NULL;
        int mid = (l + r) / 2;
        if(mid>=0&&mid<nums.size())
        {
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(nums, l, mid);
            root->right = build(nums, mid + 1, r);
            return root;
        }
        return NULL;
    }
};