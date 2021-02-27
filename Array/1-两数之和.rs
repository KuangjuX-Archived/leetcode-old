impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let len = nums.len();
        let mut ret: Vec<i32> = vec![];
        for i in 0..len{
            for j in i+1..len{
                if (nums[i] + nums[j] == target){
                    ret.push(i as i32);
                    ret.push(j as i32);

                }
            }
        }
        ret
    }
}
