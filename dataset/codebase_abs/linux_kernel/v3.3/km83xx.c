static void T_1 F_1 ( void )
{
#ifdef F_2
struct V_1 * V_2 ;
#endif
if ( V_3 . V_4 )
V_3 . V_4 ( L_1 , 0 ) ;
F_3 () ;
#ifdef F_2
F_4 () ;
V_2 = F_5 ( NULL , L_2 ) ;
if ( V_2 != NULL ) {
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 (np, L_3 )
F_9 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_5 ( V_2 , L_4 ) ) != NULL ; )
F_9 ( V_2 ) ;
}
V_2 = F_10 ( NULL , L_5 , L_6 ) ;
if ( V_2 != NULL ) {
T_2 V_5 ;
V_5 = F_11 ( V_6 ) ;
if ( F_12 ( V_5 ) == 0x0021 ) {
struct V_1 * V_7 ;
struct V_8 V_9 ;
void T_3 * V_10 ;
int V_11 ;
V_7 = F_5 ( NULL , L_2 ) ;
if ( V_7 == NULL ) {
F_13 ( V_12 L_7 ,
V_13 ) ;
return;
}
V_11 = F_14 ( V_7 , 0 , & V_9 ) ;
if ( V_11 ) {
F_13 ( V_12 L_8 ,
V_13 ) ;
return;
}
V_10 = F_15 ( V_9 . V_14 , F_16 ( & V_9 ) ) ;
F_17 ( ( V_10 + 0xa8 ) , 0x0c003000 ) ;
F_18 ( ( V_10 + 0xac ) , 0xff0 , 0xaa0 ) ;
F_19 ( V_10 ) ;
F_7 ( V_7 ) ;
}
F_7 ( V_2 ) ;
}
#endif
}
static int T_1 F_20 ( void )
{
unsigned long V_15 = F_21 () ;
int V_16 = 0 ;
while ( V_17 [ V_16 ] ) {
if ( F_22 ( V_15 , V_17 [ V_16 ] ) )
break;
V_16 ++ ;
}
return ( V_17 [ V_16 ] != NULL ) ;
}
