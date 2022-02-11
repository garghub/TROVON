static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_2 ( V_2 , V_3 , V_5 , & V_12 ) ;
* V_8 = F_3 ( V_12 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_7 = F_4 ( V_10 , 0x10020c ) & 0xff000000 ;
V_12 -> type = V_14 ;
return 0 ;
}
