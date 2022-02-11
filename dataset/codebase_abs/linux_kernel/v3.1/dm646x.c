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
void T_2 * V_13 = F_5 ( V_14 ) ;
V_12 = F_6 ( V_13 + V_15 ) ;
V_12 &= ~ V_16 ;
F_7 ( V_12 , V_13 + V_15 ) ;
V_12 = F_6 ( V_13 + V_17 ) ;
V_12 &= ~ V_18 ;
F_7 ( V_12 , V_13 + V_17 ) ;
F_8 ( V_19 ) ;
F_8 ( V_20 ) ;
F_8 ( V_21 ) ;
F_8 ( V_22 ) ;
V_23 . V_4 . V_5 = V_9 ;
V_24 . V_4 . V_5 = V_11 ;
F_2 ( & V_25 ) ;
F_2 ( & V_23 ) ;
F_2 ( & V_24 ) ;
}
int T_1 F_9 ( struct V_26 * V_27 )
{
V_28 . V_27 = V_27 ;
return F_2 ( & V_29 ) ;
}
void T_1 F_10 ( void )
{
F_11 ( & V_30 ) ;
}
static int T_1 F_12 ( void )
{
if ( ! F_13 () )
return 0 ;
F_2 ( & V_31 ) ;
F_2 ( & V_32 ) ;
F_14 ( NULL , F_15 ( & V_31 . V_4 ) ,
NULL , & V_32 . V_4 ) ;
return 0 ;
}
