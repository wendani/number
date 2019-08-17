int findDuplicate(vector<int>& nums)
{
	unordered_set<int> exists;

	for (const auto &num : nums) {
		if (exists.count(num)) {
			return num;
		}
		else {
			exists.insert(num);
		}
	}
	return -1;
}

int findDuplicate(vector<int>& nums)
{
	int slowIdx = nums[0];
	int fastIdx = nums[slowIdx];

	while (slowIdx != fastIdx) {
		slowIdx = nums[slowIdx];
		fastIdx = nums[nums[fastIdx]];
	}

	slowIdx = 0;
	while (slowIdx != fastIdx) {
		slowIdx = nums[slowIdx];
		fastIdx = nums[fastIdx];
	}

	return slowIdx;
}
