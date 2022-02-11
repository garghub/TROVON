int
F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
T_1 V_8 = F_2 ( V_6 , 0x10020c ) & 0xff000000 ;
T_1 V_9 = F_2 ( V_6 , 0x100200 ) ;
enum V_10 type ;
if ( V_9 & 0x00000001 )
type = V_11 ;
else
type = V_12 ;
return F_3 ( & V_13 , V_2 , type , V_8 , 0 , V_4 ) ;
}
