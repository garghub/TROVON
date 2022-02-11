void T_1 F_1 ( struct V_1 * V_2 )
{
V_3 . V_4 . V_5 = V_2 ;
F_2 ( & V_3 ) ;
}
void T_1 F_3 ( struct V_1 * V_2 )
{
V_6 . V_4 . V_5 = V_2 ;
F_2 ( & V_6 ) ;
F_2 ( & V_7 ) ;
}
void F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
unsigned int V_12 ;
V_12 = F_5 ( F_6 ( V_13 ) ) ;
V_12 &= ~ V_14 ;
F_7 ( V_12 , F_6 ( V_13 ) ) ;
V_12 = F_5 ( F_6 ( V_15 ) ) ;
V_12 &= ~ V_16 ;
F_7 ( V_12 , F_6 ( V_15 ) ) ;
F_8 ( V_17 ) ;
F_8 ( V_18 ) ;
F_8 ( V_19 ) ;
F_8 ( V_20 ) ;
V_21 . V_4 . V_5 = V_9 ;
V_22 . V_4 . V_5 = V_11 ;
F_2 ( & V_23 ) ;
F_2 ( & V_21 ) ;
F_2 ( & V_22 ) ;
}
int T_1 F_9 ( struct V_24 * V_25 )
{
V_26 . V_25 = V_25 ;
return F_2 ( & V_27 ) ;
}
void T_1 F_10 ( void )
{
F_11 ( & V_28 ) ;
F_12 () ;
}
static int T_1 F_13 ( void )
{
if ( ! F_14 () )
return 0 ;
F_2 ( & V_29 ) ;
F_2 ( & V_30 ) ;
return 0 ;
}
