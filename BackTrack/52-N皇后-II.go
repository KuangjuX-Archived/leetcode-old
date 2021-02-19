func totalNQueens(n int) int {
	    res := 0
	        board := make([][]int, n)
		    for i:=0; i<n; i++{
			            board[i] = make([]int, n)
				        }
					    dfs(0, &board, &res, n)
					        return res

					}

					func dfs(row int, board *[][]int, res *int, n int){
						    if row > n-1{
							            *res += 1
								            return
									        }

										    for index:=0; index<n; index++{
											            if isValid(*board, row, index, n) {
													                (*board)[row][index] = 1
															            dfs(row+1, board, res, n)
																                (*board)[row][index] = 0
																		        }else{
																				            continue
																					            }
																						        }
																						}

																						func isValid(board [][]int, row, col, n int) bool{
																							    if row == 0{
																								            return true
																									        }

																										    for x:=0; x<row; x++{
																											            // 判断列是否冲突
																												            if board[x][col] == 1{
																														                return false
																																        }
																																	        // 判断对角线是否冲突
																																		        if x+n > row+col && x< row+col && board[x][row+col-x] == 1{
																																				            return false
																																					            }
																																						           
																																						            if x+col-row <= n-1 && x+col >= row && board[x][x+col-row] == 1{
																																								                return false
																																										        }
																																											    }

																																											        return true
																																											}
