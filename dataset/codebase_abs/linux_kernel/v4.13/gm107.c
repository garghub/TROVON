T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_2 V_6 = F_2 ( V_4 , 0x021c00 ) ;
T_2 V_7 = F_2 ( V_4 , 0x021c04 ) ;
T_1 V_8 = 0ULL ;
if ( V_6 & 0x00000001 )
V_8 |= ( 1ULL << V_9 ) ;
if ( V_6 & 0x00000004 )
V_8 |= ( 1ULL << V_10 ) ;
if ( V_7 & 0x00000001 )
V_8 |= ( 1ULL << V_11 ) ;
return V_8 ;
}
int
F_3 ( struct V_3 * V_4 , int V_12 ,
struct V_1 * * V_13 )
{
return F_4 ( & V_14 , V_4 , V_12 , V_13 ) ;
}
