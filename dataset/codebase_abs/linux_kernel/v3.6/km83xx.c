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
F_8 (np, L_4 )
F_9 ( V_2 ) ;
}
V_2 = F_10 ( NULL , L_5 , L_6 ) ;
if ( V_2 != NULL ) {
T_2 V_5 = F_11 ( V_6 ) ;
struct V_1 * V_7 ;
struct V_8 V_9 ;
void T_3 * V_10 ;
int V_11 ;
V_7 = F_5 ( NULL , L_2 ) ;
if ( V_7 == NULL ) {
F_12 ( V_12 L_7 ,
V_13 ) ;
return;
}
V_11 = F_13 ( V_7 , 0 , & V_9 ) ;
if ( V_11 ) {
F_12 ( V_12 L_8 ,
V_13 ) ;
return;
}
V_10 = F_14 ( V_9 . V_14 , V_9 . V_15 - V_9 . V_14 + 1 ) ;
F_15 ( ( V_10 + 0xa8 ) , 0x0c00f000 , 0x04005000 ) ;
F_15 ( ( V_10 + 0xac ) , 0x0000cff0 , 0x00004550 ) ;
if ( F_16 ( V_5 ) == 0x0021 ) {
F_15 ( ( V_10 + 0xac ) , 0x000000f0 , 0x000000a0 ) ;
} else if ( F_16 ( V_5 ) == 0x0020 ) {
F_17 ( ( V_10 + 0xa8 ) , 0x00003000 ) ;
F_17 ( ( V_10 + 0xa8 ) , 0x0c000000 ) ;
F_17 ( ( V_10 + 0xac ) , 0x0000c000 ) ;
}
F_18 ( V_10 ) ;
F_7 ( V_7 ) ;
F_7 ( V_2 ) ;
}
#endif
}
static int T_1 F_19 ( void )
{
unsigned long V_16 = F_20 () ;
int V_17 = 0 ;
while ( V_18 [ V_17 ] ) {
if ( F_21 ( V_16 , V_18 [ V_17 ] ) )
break;
V_17 ++ ;
}
return ( V_18 [ V_17 ] != NULL ) ;
}
