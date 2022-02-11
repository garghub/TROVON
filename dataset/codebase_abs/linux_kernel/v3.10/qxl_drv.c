static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( V_2 -> V_5 < 4 ) {
F_2 ( L_1
L_2 ) ;
return - V_6 ;
}
return F_3 ( V_2 , V_4 , & V_7 ) ;
}
static void
F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
F_6 ( V_9 ) ;
}
static int T_1 F_7 ( void )
{
#ifdef F_8
if ( F_9 () && V_10 == - 1 )
return - V_6 ;
#endif
if ( V_10 == 0 )
return - V_6 ;
V_7 . V_11 = V_12 ;
return F_10 ( & V_7 , & V_13 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_7 , & V_13 ) ;
}
