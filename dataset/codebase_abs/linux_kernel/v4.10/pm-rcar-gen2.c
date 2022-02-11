static void T_1 F_1 ( T_2 V_1 )
{
F_2 ( 0xe6180000 , V_1 ) ;
}
static inline void F_1 ( T_2 V_1 ) {}
void T_1 F_3 ( void )
{
void T_3 * V_2 ;
T_2 V_3 ;
static int V_4 ;
struct V_5 * V_6 , * V_7 ;
bool V_8 = false ;
bool V_9 = false ;
T_4 V_10 = V_11 ;
T_2 V_1 = 0 ;
if ( V_4 ++ )
return;
V_7 = F_4 ( L_1 ) ;
if ( ! V_7 )
return;
F_5 (cpus, np) {
if ( F_6 ( V_6 , L_2 ) )
V_9 = true ;
else if ( F_6 ( V_6 , L_3 ) )
V_8 = true ;
}
if ( F_7 ( L_4 ) )
V_1 = 0x013111ef ;
else if ( F_7 ( L_5 ) )
V_1 = 0x00111003 ;
V_2 = F_8 ( V_10 , V_12 ) ;
F_9 ( V_2 , V_13 , V_12 ) ;
F_10 ( V_2 ) ;
V_2 = F_8 ( V_14 , 0x63 ) ;
V_3 = ( V_10 >> 8 ) & 0xfffffc00 ;
if ( V_9 ) {
F_11 ( V_3 , V_2 + V_15 ) ;
F_11 ( V_3 | 0x10 , V_2 + V_15 ) ;
F_11 ( ( F_12 ( V_2 + V_16 ) & ~ 0x0f ) |
0xa5a50000 , V_2 + V_16 ) ;
}
if ( V_8 ) {
F_11 ( V_3 , V_2 + V_17 ) ;
F_11 ( V_3 | 0x10 , V_2 + V_17 ) ;
F_11 ( ( F_12 ( V_2 + V_18 ) & ~ 0x0f ) |
0x5a5a0000 , V_2 + V_18 ) ;
}
F_10 ( V_2 ) ;
F_1 ( V_1 ) ;
F_13 () ;
}
