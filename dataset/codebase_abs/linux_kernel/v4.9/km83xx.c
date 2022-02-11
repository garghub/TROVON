static void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_5 V_6 ;
void T_2 * V_7 ;
int V_8 ;
V_4 = F_3 ( NULL , L_1 ) ;
if ( V_4 == NULL ) {
F_4 ( L_2 , V_9 ) ;
return;
}
V_8 = F_5 ( V_4 , 0 , & V_6 ) ;
if ( V_8 ) {
F_4 ( L_3 , V_9 ) ;
return;
}
V_7 = F_6 ( V_6 . V_10 , V_6 . V_11 - V_6 . V_10 + 1 ) ;
F_7 ( ( V_7 + 0xa8 ) , 0x0c00f000 , 0x04005000 ) ;
F_7 ( ( V_7 + 0xac ) , 0x0000cff0 , 0x00004550 ) ;
if ( F_8 ( V_1 ) == 0x0021 ) {
F_7 ( ( V_7 + 0xac ) , 0x000000f0 , 0x000000a0 ) ;
} else if ( F_8 ( V_1 ) == 0x0020 ) {
F_9 ( ( V_7 + 0xa8 ) , 0x00003000 ) ;
F_9 ( ( V_7 + 0xa8 ) , 0x0c000000 ) ;
F_9 ( ( V_7 + 0xac ) , 0x0000c000 ) ;
}
F_10 ( V_7 ) ;
F_11 ( V_4 ) ;
}
static void T_3 F_12 ( void )
{
#ifdef F_13
struct V_3 * V_12 ;
#endif
F_14 () ;
#ifdef F_13
V_12 = F_3 ( NULL , L_1 ) ;
if ( V_12 != NULL ) {
F_15 ( V_12 ) ;
F_11 ( V_12 ) ;
F_16 (np, L_4 )
F_17 ( V_12 ) ;
F_16 (np, L_5 )
F_17 ( V_12 ) ;
V_12 = F_18 ( NULL , L_6 , L_7 ) ;
if ( V_12 != NULL ) {
F_1 () ;
F_11 ( V_12 ) ;
}
}
#endif
}
static int T_3 F_19 ( void )
{
int V_13 = 0 ;
while ( V_14 [ V_13 ] ) {
if ( F_20 ( V_14 [ V_13 ] ) )
break;
V_13 ++ ;
}
return ( V_14 [ V_13 ] != NULL ) ;
}
