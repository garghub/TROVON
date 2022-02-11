static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
F_2 ( V_7 , V_4 -> V_8 ) ;
V_6 = 10 ;
while ( ( F_3 ( V_4 -> V_8 + 0x4 ) & V_7 )
!= V_7 ) {
if ( V_6 == 0 ) {
F_4 ( V_9 L_1 ,
F_5 ( V_2 ) ) ;
return - V_10 ;
}
V_6 -- ;
F_6 ( 100 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
F_2 ( 0 , V_4 -> V_8 ) ;
V_6 = 10 ;
while ( F_3 ( V_4 -> V_8 + 0x4 ) & V_7 ) {
if ( V_6 == 0 ) {
F_4 ( V_9 L_2 ,
F_5 ( V_2 ) ) ;
return - V_10 ;
}
V_6 -- ;
F_6 ( 100 ) ;
}
return 0 ;
}
