func getRow(rowIndex int) []int {
    tmp := make([][]int, 34);
    for i:=0; i<34; i++{
        tmp[i] = make([]int, 34);
    }
    tmp[1][0] = 1;
    tmp[1][1] = 1;
    res := make([]int, 0);
    if rowIndex == 0{
        res = append(res, 1);
        return res;
    }
    for i:=0; i<=rowIndex/2; i++{
        res = append(res, getNum(rowIndex, i, &tmp));
    }

    for i:= (rowIndex-1)/2; i>=0; i--{
        res = append(res, res[i]);
    }

    return res;
}

func getNum(rowIndex, colIndex int, tmp *[][]int) int {
    if(rowIndex < 1 || colIndex < 0){
        return 0;
    }
    if((*tmp)[rowIndex][colIndex] > 0){
        return (*tmp)[rowIndex][colIndex];
    }
    res := getNum(rowIndex-1, colIndex, tmp) + getNum(rowIndex-1, colIndex-1, tmp);
    (*tmp)[rowIndex][colIndex] = res;
    return res;
}
