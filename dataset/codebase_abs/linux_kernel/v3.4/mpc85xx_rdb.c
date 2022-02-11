void T_1 F_1 ( void )
{
struct V_1 * V_1 ;
unsigned long V_2 = F_2 () ;
#ifdef F_3
struct V_3 * V_4 ;
#endif
if ( F_4 ( V_2 , L_1 ) ) {
V_1 = F_5 ( NULL , 0 , V_5 |
V_6 |
V_7 ,
0 , 256 , L_2 ) ;
} else {
V_1 = F_5 ( NULL , 0 ,
V_6 |
V_7 ,
0 , 256 , L_2 ) ;
}
F_6 ( V_1 == NULL ) ;
F_7 ( V_1 ) ;
#ifdef F_3
V_4 = F_8 ( NULL , NULL , L_3 ) ;
if ( V_4 ) {
F_9 ( V_4 , 0 , V_8 ,
V_9 ) ;
F_10 ( V_4 ) ;
} else
F_11 ( L_4 , V_10 ) ;
#endif
}
static void T_1 F_12 ( void )
{
#if F_13 ( V_11 ) || F_13 ( F_3 )
struct V_3 * V_4 ;
#endif
if ( V_12 . V_13 )
V_12 . V_13 ( L_5 , 0 ) ;
#ifdef V_11
F_14 (np, L_6 ) {
if ( F_15 ( V_4 , L_7 ) )
F_16 ( V_4 , 0 ) ;
}
#endif
F_17 () ;
#ifdef F_3
V_4 = F_8 ( NULL , NULL , L_8 ) ;
if ( ! V_4 ) {
F_11 ( L_9 , V_10 ) ;
goto V_14;
}
F_18 () ;
F_10 ( V_4 ) ;
V_4 = F_19 ( NULL , L_10 ) ;
if ( V_4 ) {
struct V_3 * V_15 ;
F_20 ( V_4 ) ;
F_10 ( V_4 ) ;
F_21 (ucc, L_11 )
F_22 ( V_15 ) ;
}
#if F_13 ( V_16 ) || F_13 ( V_17 )
if ( F_23 ( V_18 ) ) {
struct V_19 T_2 * V_20 ;
V_4 = F_19 ( NULL , L_12 ) ;
if ( V_4 ) {
V_20 = F_24 ( V_4 , 0 ) ;
if ( ! V_20 ) {
F_11 ( L_13 ) ;
} else {
F_25 ( & V_20 -> V_21 , F_26 ( 0 ) |
F_26 ( 3 ) |
F_26 ( 9 ) |
F_26 ( 12 ) ) ;
F_27 ( V_20 ) ;
}
F_10 ( V_4 ) ;
}
}
#endif
V_14:
#endif
F_28 ( V_22 L_14 ) ;
}
static int T_1 F_29 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_4 ( V_2 , L_15 ) )
return 1 ;
return 0 ;
}
static int T_1 F_30 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_4 ( V_2 , L_16 ) )
return 1 ;
return 0 ;
}
static int T_1 F_31 ( void )
{
unsigned long V_2 = F_2 () ;
return F_4 ( V_2 , L_17 ) ;
}
static int T_1 F_32 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_4 ( V_2 , L_18 ) )
return 1 ;
return 0 ;
}
static int T_1 F_33 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_4 ( V_2 , L_19 ) )
return 1 ;
return 0 ;
}
static int T_1 F_34 ( void )
{
unsigned long V_2 = F_2 () ;
return F_4 ( V_2 , L_20 ) ;
}
static int T_1 F_35 ( void )
{
unsigned long V_2 = F_2 () ;
return F_4 ( V_2 , L_21 ) ;
}
static int T_1 F_36 ( void )
{
unsigned long V_2 = F_2 () ;
return F_4 ( V_2 , L_22 ) ;
}
