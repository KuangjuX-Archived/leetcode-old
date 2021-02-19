func minKBitFlips(A []int, K int) int {
    size := len(A);
    queue := make([]int, 0);
    res := 0;
    for index, value := range A {
        if len(queue) > 0 {
            if queue[0] + K -1 < index {
            queue = queue[1:];
            }
        }

        if len(queue)%2 != value{
            continue;
        }
        
        queue = append(queue, index);


        if index + K  > size{
            return -1;
        }

        res += 1;
    }
    return res
}
