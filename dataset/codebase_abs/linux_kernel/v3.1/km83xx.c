static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 . V_4 )
V_3 . V_4 ( L_1 , 0 ) ;
#ifdef F_2
F_3 (np, L_2 , L_3 )
F_4 ( V_2 ) ;
#endif
#ifdef F_5
F_6 () ;
V_2 = F_7 ( NULL , L_4 ) ;
if ( V_2 != NULL ) {
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 (np, L_5 )
F_11 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_7 ( V_2 , L_6 ) ) != NULL ; )
F_11 ( V_2 ) ;
}
V_2 = F_12 ( NULL , L_7 , L_8 ) ;
if ( V_2 != NULL ) {
T_2 V_5 ;
V_5 = F_13 ( V_6 ) ;
if ( F_14 ( V_5 ) == 0x0021 ) {
struct V_1 * V_7 ;
struct V_8 V_9 ;
void T_3 * V_10 ;
int V_11 ;
V_7 = F_7 ( NULL , L_4 ) ;
if ( V_7 == NULL ) {
F_15 ( V_12 L_9 ,
V_13 ) ;
return;
}
V_11 = F_16 ( V_7 , 0 , & V_9 ) ;
if ( V_11 ) {
F_15 ( V_12 L_10 ,
V_13 ) ;
return;
}
V_10 = F_17 ( V_9 . V_14 , F_18 ( & V_9 ) ) ;
F_19 ( ( V_10 + 0xa8 ) , 0x0c003000 ) ;
F_20 ( ( V_10 + 0xac ) , 0xff0 , 0xaa0 ) ;
F_21 ( V_10 ) ;
F_9 ( V_7 ) ;
}
F_9 ( V_2 ) ;
}
#endif
}
static int T_1 F_22 ( void )
{
F_23 ( NULL , V_15 , NULL ) ;
return 0 ;
}
static void T_1 F_24 ( void )
{
struct V_1 * V_2 ;
V_2 = F_12 ( NULL , NULL , L_11 ) ;
if ( ! V_2 ) {
V_2 = F_25 ( NULL , L_12 ) ;
if ( ! V_2 )
return;
}
F_26 ( V_2 , 0 ) ;
F_27 () ;
F_9 ( V_2 ) ;
#ifdef F_5
V_2 = F_12 ( NULL , NULL , L_13 ) ;
if ( ! V_2 ) {
V_2 = F_25 ( NULL , L_14 ) ;
if ( ! V_2 )
return;
}
F_28 ( V_2 , 0 , V_16 , V_17 ) ;
F_9 ( V_2 ) ;
#endif
}
static int T_1 F_29 ( void )
{
unsigned long V_18 = F_30 () ;
int V_19 = 0 ;
while ( V_20 [ V_19 ] ) {
if ( F_31 ( V_18 , V_20 [ V_19 ] ) )
break;
V_19 ++ ;
}
return ( V_20 [ V_19 ] != NULL ) ;
}
