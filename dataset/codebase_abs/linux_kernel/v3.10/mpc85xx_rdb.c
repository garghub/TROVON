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
#ifdef F_3
struct V_3 * V_4 ;
#endif
if ( V_11 . V_12 )
V_11 . V_12 ( L_5 , 0 ) ;
F_13 () ;
F_14 () ;
#ifdef F_3
V_4 = F_8 ( NULL , NULL , L_6 ) ;
if ( ! V_4 ) {
F_11 ( L_7 , V_10 ) ;
goto V_13;
}
F_15 () ;
F_10 ( V_4 ) ;
V_4 = F_16 ( NULL , L_8 ) ;
if ( V_4 ) {
struct V_3 * V_14 ;
F_17 ( V_4 ) ;
F_10 ( V_4 ) ;
F_18 (ucc, L_9 )
F_19 ( V_14 ) ;
}
#if F_20 ( V_15 ) || F_20 ( V_16 )
if ( F_21 ( V_17 ) ) {
struct V_18 T_2 * V_19 ;
V_4 = F_16 ( NULL , L_10 ) ;
if ( V_4 ) {
V_19 = F_22 ( V_4 , 0 ) ;
if ( ! V_19 ) {
F_11 ( L_11 ) ;
} else {
F_23 ( & V_19 -> V_20 , F_24 ( 0 ) |
F_24 ( 3 ) |
F_24 ( 9 ) |
F_24 ( 12 ) ) ;
F_25 ( V_19 ) ;
}
F_10 ( V_4 ) ;
}
}
#endif
V_13:
#endif
F_26 ( V_21 L_12 ) ;
}
static int T_1 F_27 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_4 ( V_2 , L_13 ) )
return 1 ;
return 0 ;
}
static int T_1 F_28 ( void )
{
unsigned long V_2 = F_2 () ;
if ( F_4 ( V_2 , L_14 ) )
return 1 ;
return 0 ;
}
static int T_1 F_29 ( void )
{
unsigned long V_2 = F_2 () ;
return F_4 ( V_2 , L_15 ) ;
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
if ( F_4 ( V_2 , L_17 ) )
return 1 ;
return 0 ;
}
static int T_1 F_32 ( void )
{
unsigned long V_2 = F_2 () ;
return F_4 ( V_2 , L_18 ) ;
}
static int T_1 F_33 ( void )
{
unsigned long V_2 = F_2 () ;
return F_4 ( V_2 , L_19 ) ;
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
