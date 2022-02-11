static void T_1 F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , F_4 ( V_1 ) ) ;
}
static void T_1 F_5 ( void )
{
F_6 () ;
F_7 ( 0xffffffff , V_2 ) ;
F_7 ( 0x3fffffff , V_3 ) ;
F_7 ( 0xfffffff0 , V_4 ) ;
F_7 ( 0xfff7ffff , V_5 ) ;
F_7 ( 0xfffbffdf , V_6 ) ;
F_7 ( 0xbffffffc , V_7 ) ;
F_7 ( 0x003fee3f , V_8 ) ;
}
static T_2 T_1 F_8 ( void )
{
static T_2 V_9 ;
static bool V_10 ;
if ( ! V_10 ) {
void T_3 * V_11 = F_9 ( V_12 , V_13 ) ;
F_10 ( ! V_11 ) ;
V_9 = F_11 ( V_11 ) ;
F_12 ( V_11 ) ;
V_10 = true ;
}
return V_9 ;
}
static void T_1 F_13 ( void )
{
F_14 ( F_8 () ) ;
F_15 () ;
}
