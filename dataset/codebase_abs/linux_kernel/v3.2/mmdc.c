static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
void T_2 * V_7 , * V_8 ;
T_3 V_9 ;
int V_10 = 0x400 ;
V_7 = F_2 ( V_4 , 0 ) ;
F_3 ( ! V_7 ) ;
V_8 = V_7 + V_11 ;
V_9 = F_4 ( V_8 ) ;
V_9 &= ~ ( 1 << V_12 ) ;
F_5 ( V_9 , V_8 ) ;
while ( ! ( F_4 ( V_8 ) & 1 << V_13 ) && -- V_10 )
F_6 () ;
if ( F_7 ( ! V_10 ) ) {
F_8 ( L_1 ,
V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static int T_4 F_9 ( void )
{
return F_10 ( & V_16 ) ;
}
