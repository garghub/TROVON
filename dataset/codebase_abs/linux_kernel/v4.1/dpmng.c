int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = { 0 } ;
int V_7 ;
V_6 . V_8 = F_2 ( V_9 ,
V_10 , 0 ) ;
V_7 = F_3 ( V_2 , & V_6 ) ;
if ( V_7 )
return V_7 ;
V_4 -> V_11 = F_4 ( V_6 . V_12 [ 0 ] , 0 , 32 ) ;
V_4 -> V_13 = F_4 ( V_6 . V_12 [ 0 ] , 32 , 32 ) ;
V_4 -> V_14 = F_4 ( V_6 . V_12 [ 1 ] , 0 , 32 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , int * V_15 )
{
struct V_5 V_6 = { 0 } ;
int V_7 ;
V_6 . V_8 = F_2 ( V_16 ,
V_10 , 0 ) ;
V_7 = F_3 ( V_2 , & V_6 ) ;
if ( V_7 )
return V_7 ;
* V_15 = F_4 ( V_6 . V_12 [ 0 ] , 0 , 32 ) ;
return 0 ;
}
