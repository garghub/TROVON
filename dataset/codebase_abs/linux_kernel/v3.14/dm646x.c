int T_1 F_1 ( void )
{
return F_2 ( V_1 ,
F_3 ( V_1 ) ,
& V_2 ) ;
}
void T_1 F_4 ( struct V_3 * V_4 )
{
V_5 . V_6 . V_7 = V_4 ;
F_5 ( & V_5 ) ;
}
void T_1 F_6 ( struct V_3 * V_4 )
{
V_8 . V_6 . V_7 = V_4 ;
F_5 ( & V_8 ) ;
F_5 ( & V_9 ) ;
}
void F_7 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
unsigned int V_14 ;
V_14 = F_8 ( F_9 ( V_15 ) ) ;
V_14 &= ~ V_16 ;
F_10 ( V_14 , F_9 ( V_15 ) ) ;
V_14 = F_8 ( F_9 ( V_17 ) ) ;
V_14 &= ~ V_18 ;
F_10 ( V_14 , F_9 ( V_17 ) ) ;
F_11 ( V_19 ) ;
F_11 ( V_20 ) ;
F_11 ( V_21 ) ;
F_11 ( V_22 ) ;
V_23 . V_6 . V_7 = V_11 ;
V_24 . V_6 . V_7 = V_13 ;
F_5 ( & V_25 ) ;
F_5 ( & V_23 ) ;
F_5 ( & V_24 ) ;
}
int T_1 F_12 ( struct V_26 * V_27 )
{
V_28 . V_27 = V_27 ;
return F_5 ( & V_29 ) ;
}
void T_1 F_13 ( void )
{
F_14 ( & V_30 ) ;
F_15 () ;
}
static int T_1 F_16 ( void )
{
if ( ! F_17 () )
return 0 ;
F_5 ( & V_31 ) ;
F_5 ( & V_32 ) ;
return 0 ;
}
