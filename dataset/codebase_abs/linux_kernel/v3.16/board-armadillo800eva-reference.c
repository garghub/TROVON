static void T_1 F_1 ( void )
{
struct V_1 * system = F_2 ( NULL , L_1 ) ;
struct V_1 * V_2 = F_2 ( NULL , L_2 ) ;
struct V_1 * V_3 = F_2 ( NULL , L_3 ) ;
struct V_1 * V_4 = F_2 ( NULL , L_4 ) ;
if ( F_3 ( system ) ||
F_3 ( V_2 ) ||
F_3 ( V_3 ) ||
F_3 ( V_4 ) ) {
F_4 ( L_5 ) ;
goto V_5;
}
F_5 ( V_2 , 24000000 ) ;
F_6 ( V_3 , system ) ;
F_5 ( V_4 , 12288000 ) ;
V_5:
if ( ! F_3 ( system ) )
F_7 ( system ) ;
if ( ! F_3 ( V_2 ) )
F_7 ( V_2 ) ;
if ( ! F_3 ( V_3 ) )
F_7 ( V_3 ) ;
if ( ! F_3 ( V_4 ) )
F_7 ( V_4 ) ;
}
static void T_1 F_8 ( void )
{
F_9 ( V_6 | V_7 ) ;
F_1 () ;
F_10 () ;
#ifdef F_11
F_12 ( F_13 ( 0xf0002000 ) , 0x00400000 , 0xc20f0fff ) ;
#endif
F_14 () ;
F_15 () ;
}
static void F_16 ( enum V_8 V_9 , const char * V_10 )
{
F_17 ( 1 << 31 , V_11 ) ;
}
