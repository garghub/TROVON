void
F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) , 0x000140 , 0x00000000 ) ;
}
int
F_4 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) , 0x000140 , 0x00000001 ) ;
return 0 ;
}
void
F_5 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) , 0x000140 , 0x00000000 ) ;
}
T_1
F_6 ( T_2 )
{
struct V_1 * V_2 = V_3 ;
struct V_4 * V_5 = F_3 ( V_2 ) ;
struct V_6 * V_7 = V_6 ( V_5 ) ;
T_3 V_8 ;
V_8 = F_7 ( V_5 , 0x000100 ) ;
if ( V_8 == 0 || V_8 == ~ 0 )
return V_9 ;
F_8 ( V_7 ) -> F_9 ( F_8 ( V_7 ) ) ;
return V_10 ;
}
int
F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 ) ;
}
void
F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
