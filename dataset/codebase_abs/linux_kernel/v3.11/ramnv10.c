static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
T_1 V_13 = F_2 ( V_10 , 0x100200 ) ;
int V_14 ;
V_14 = F_3 ( V_2 , V_3 , V_5 , & V_12 ) ;
* V_8 = F_4 ( V_12 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 & 0x00000001 )
V_12 -> type = V_15 ;
else
V_12 -> type = V_16 ;
V_12 -> V_7 = F_2 ( V_10 , 0x10020c ) & 0xff000000 ;
return 0 ;
}
