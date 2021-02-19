func longestOnes(A []int, K int) int {
    size := len(A)
    left, right := 0, 0
    res, sum := 0, 0
    for right < size {
        sum += A[right] ^ 1
        for sum > K {
            sum -= (A[left] ^ 1)
            left += 1
        }

        res = max(res, right-left+1)
        right += 1
    }
    return res
}

func max(a,b int) int{
    if a > b{
        return a
    }
    return b
}
