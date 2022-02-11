static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
if ( V_6 -> V_11 == V_12
&& ( V_8 -> V_13 & V_14 ) == V_15 ) {
F_2 ( V_2 , L_1 ,
V_8 -> V_13 , V_6 -> V_11 ) ;
return 0 ;
}
F_2 ( V_2 , L_2 ,
V_8 -> V_13 , V_6 -> V_11 ) ;
return - 1 ;
}
