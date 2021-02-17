func matrixReshape(nums [][]int, r int, c int) [][]int {
    row := len(nums)
    col := len(nums[0])
    if r*c != row*col {
        return nums
    }

    // var res [][]int
    res := make([][]int, r)
    for i:=0; i<r; i++{
        res[i] = make([]int, c)
    }

    for i:=0; i<row; i++{
        for j:=0; j<col; j++{
            total := col*i+j
            x := total / c
            y := total % c
            res[x][y] = nums[i][j]
        }
    }
    return res
}
