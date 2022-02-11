int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_6 V_7 = { 0 } ;
int V_8 ;
V_7 . V_9 = F_2 ( V_10 ,
V_3 ,
0 ) ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
return V_8 ;
V_5 -> V_11 = F_4 ( V_7 . V_12 [ 0 ] , 0 , 32 ) ;
V_5 -> V_13 = F_4 ( V_7 . V_12 [ 0 ] , 32 , 32 ) ;
V_5 -> V_14 = F_4 ( V_7 . V_12 [ 1 ] , 0 , 32 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
T_1 V_3 ,
int * V_15 )
{
struct V_6 V_7 = { 0 } ;
int V_8 ;
V_7 . V_9 = F_2 ( V_16 ,
V_3 ,
0 ) ;
V_8 = F_3 ( V_2 , & V_7 ) ;
if ( V_8 )
return V_8 ;
* V_15 = F_4 ( V_7 . V_12 [ 0 ] , 0 , 32 ) ;
return 0 ;
}
