void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
#ifdef F_2
struct V_2 * V_3 ;
#endif
if ( F_3 ( L_1 ) ) {
V_1 = F_4 ( NULL , 0 , V_4 |
V_5 |
V_6 ,
0 , 256 , L_2 ) ;
} else {
V_1 = F_4 ( NULL , 0 ,
V_5 |
V_6 ,
0 , 256 , L_2 ) ;
}
F_5 ( V_1 == NULL ) ;
F_6 ( V_1 ) ;
#ifdef F_2
V_3 = F_7 ( NULL , NULL , L_3 ) ;
if ( V_3 ) {
F_8 ( V_3 , 0 , V_7 ,
V_8 ) ;
F_9 ( V_3 ) ;
} else
F_10 ( L_4 , V_9 ) ;
#endif
}
static void T_1 F_11 ( void )
{
if ( V_10 . V_11 )
V_10 . V_11 ( L_5 , 0 ) ;
F_12 () ;
F_13 () ;
#ifdef F_2
F_14 () ;
F_15 () ;
#if F_16 ( V_12 ) || F_16 ( V_13 )
if ( F_17 ( V_14 ) ) {
struct V_2 * V_3 ;
struct V_15 T_2 * V_16 ;
V_3 = F_18 ( NULL , L_6 ) ;
if ( V_3 ) {
V_16 = F_19 ( V_3 , 0 ) ;
if ( ! V_16 ) {
F_10 ( L_7 ) ;
} else {
F_20 ( & V_16 -> V_17 , F_21 ( 0 ) |
F_21 ( 3 ) |
F_21 ( 9 ) |
F_21 ( 12 ) ) ;
F_22 ( V_16 ) ;
}
F_9 ( V_3 ) ;
}
}
#endif
#endif
F_23 ( V_18 L_8 ) ;
}
static int T_1 F_24 ( void )
{
if ( F_3 ( L_9 ) )
return 1 ;
return 0 ;
}
static int T_1 F_25 ( void )
{
if ( F_3 ( L_10 ) )
return 1 ;
return 0 ;
}
static int T_1 F_26 ( void )
{
return F_3 ( L_11 ) ;
}
static int T_1 F_27 ( void )
{
return F_3 ( L_12 ) ;
}
static int T_1 F_28 ( void )
{
if ( F_3 ( L_13 ) )
return 1 ;
return 0 ;
}
static int T_1 F_29 ( void )
{
if ( F_3 ( L_14 ) )
return 1 ;
return 0 ;
}
static int T_1 F_30 ( void )
{
return F_3 ( L_15 ) ;
}
static int T_1 F_31 ( void )
{
return F_3 ( L_16 ) ;
}
static int T_1 F_32 ( void )
{
return F_3 ( L_17 ) ;
}
static int T_1 F_33 ( void )
{
return F_3 ( L_18 ) ;
}
