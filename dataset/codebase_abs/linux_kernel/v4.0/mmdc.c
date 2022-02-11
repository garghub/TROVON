static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
void T_1 * V_7 , * V_8 ;
T_2 V_9 ;
int V_10 = 0x400 ;
V_7 = F_2 ( V_4 , 0 ) ;
F_3 ( ! V_7 ) ;
V_8 = V_7 + V_11 ;
V_9 = F_4 ( V_8 ) ;
V_12 = ( V_9 & V_13 ) >>
V_14 ;
V_8 = V_7 + V_15 ;
V_9 = F_4 ( V_8 ) ;
V_9 &= ~ ( 1 << V_16 ) ;
F_5 ( V_9 , V_8 ) ;
while ( ! ( F_4 ( V_8 ) & 1 << V_17 ) && -- V_10 )
F_6 () ;
if ( F_7 ( ! V_10 ) ) {
F_8 ( L_1 ,
V_18 ) ;
return - V_19 ;
}
return 0 ;
}
int F_9 ( void )
{
return V_12 ;
}
static int T_3 F_10 ( void )
{
return F_11 ( & V_20 ) ;
}
