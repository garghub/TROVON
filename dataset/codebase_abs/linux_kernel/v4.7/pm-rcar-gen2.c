static void T_1 F_1 ( T_2 V_1 )
{
void T_3 * V_2 = F_2 ( 0xe6180000 ) ;
F_3 ( V_1 , V_2 + V_3 ) ;
F_3 ( 0 , V_2 + V_4 ) ;
}
static inline void F_1 ( T_2 V_1 ) {}
void T_1 F_4 ( void )
{
void T_3 * V_5 ;
T_2 V_6 ;
static int V_7 ;
struct V_8 * V_9 , * V_10 ;
bool V_11 = false ;
bool V_12 = false ;
T_4 V_13 = 0 ;
T_2 V_1 = 0 ;
if ( V_7 ++ )
return;
V_10 = F_5 ( L_1 ) ;
if ( ! V_10 )
return;
F_6 (cpus, np) {
if ( F_7 ( V_9 , L_2 ) )
V_12 = true ;
else if ( F_7 ( V_9 , L_3 ) )
V_11 = true ;
}
if ( F_8 ( L_4 ) ) {
V_13 = V_14 ;
V_1 = 0x013111ef ;
} else if ( F_8 ( L_5 ) ) {
V_13 = V_15 ;
V_1 = 0x00111003 ;
}
V_5 = F_9 ( V_13 , V_16 ) ;
F_10 ( V_5 , V_17 , V_16 ) ;
F_11 ( V_5 ) ;
V_5 = F_9 ( V_18 , 0x63 ) ;
V_6 = ( V_13 >> 8 ) & 0xfffffc00 ;
if ( V_12 ) {
F_12 ( V_6 , V_5 + V_19 ) ;
F_12 ( V_6 | 0x10 , V_5 + V_19 ) ;
F_12 ( ( F_13 ( V_5 + V_20 ) & ~ 0x0f ) |
0xa5a50000 , V_5 + V_20 ) ;
}
if ( V_11 ) {
F_12 ( V_6 , V_5 + V_21 ) ;
F_12 ( V_6 | 0x10 , V_5 + V_21 ) ;
F_12 ( ( F_13 ( V_5 + V_22 ) & ~ 0x0f ) |
0x5a5a0000 , V_5 + V_22 ) ;
}
F_11 ( V_5 ) ;
F_1 ( V_1 ) ;
F_14 () ;
}
