int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 . V_6 ;
struct V_9 * V_10 ;
if ( V_2 -> V_11 . V_12 < sizeof( * V_10 ) ) {
F_2 ( V_6 , L_1
L_2 ,
V_2 -> V_11 . V_12 , sizeof( * V_10 ) ) ;
goto error;
}
V_10 = F_3 ( V_2 -> V_11 . V_13 , struct V_9 , V_13 ) ;
F_4 ( V_6 , L_3 , V_10 -> V_14 [ 0 ] ) ;
if ( V_10 -> V_14 [ 0 ] == V_15 ) {
F_5 ( V_6 , L_4 ) ;
}
return 0 ;
error:
return V_3 ;
}
