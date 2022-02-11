static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * * V_6 ,
int * V_7 )
{
if ( V_4 -> V_8 == 12 ) {
V_4 -> V_9 . V_10 = & V_11 ;
* V_6 = V_12 ;
* V_7 = F_2 ( V_12 ) ;
} else {
V_4 -> V_9 . V_10 = & V_13 ;
* V_6 = V_14 ;
* V_7 = F_2 ( V_14 ) ;
}
}
static void T_1 F_3 ( void )
{
F_4 ( V_15 ) ;
F_4 ( V_16 ) ;
}
static int T_1 F_5 ( void )
{
V_17 . V_18 . V_19 = & V_20 ;
V_21 . V_18 . V_19 = & V_22 ;
V_23 . V_18 . V_19 = & V_24 ;
V_25 . V_18 . V_19 = & V_26 ;
F_6 ( & V_27 ) ;
F_6 ( & V_28 ) ;
F_7 ( V_29 ,
F_2 ( V_29 ) ) ;
if ( V_30 ) {
F_8 ( & V_31 ) ;
F_8 ( & V_32 ) ;
}
return F_9 ( V_33 ,
F_2 ( V_33 ) ) ;
}
static T_1 int F_10 ( char * V_34 )
{
V_26 . V_35 = 1 ;
V_30 = true ;
return 1 ;
}
static int T_1 F_11 ( void )
{
F_12 ( V_36 L_1 ,
V_30 ? L_2 : L_3 ) ;
F_3 () ;
if ( F_5 () )
F_13 ( L_4 ) ;
return 0 ;
}
