static void T_1 F_1 ( void )
{
void T_2 * V_1 = F_2 ( 0xe6180000 ) ;
F_3 ( 0x0131000e , V_1 + V_2 ) ;
F_3 ( 0 , V_1 + V_3 ) ;
}
static inline void F_1 ( void ) {}
void T_1 F_4 ( void )
{
void T_2 * V_4 ;
T_3 V_5 ;
static int V_6 ;
if ( V_6 ++ )
return;
V_4 = F_5 ( V_7 , V_8 ) ;
F_6 ( V_4 , V_9 , V_8 ) ;
F_7 ( V_4 ) ;
V_4 = F_5 ( V_10 , 0x63 ) ;
V_5 = ( V_7 >> 8 ) & 0xfffffc00 ;
F_8 ( V_5 , V_4 + V_11 ) ;
F_8 ( V_5 , V_4 + V_12 ) ;
F_8 ( V_5 | 0x10 , V_4 + V_11 ) ;
F_8 ( V_5 | 0x10 , V_4 + V_12 ) ;
F_8 ( ( F_9 ( V_4 + V_13 ) & ~ 0x0f ) | 0xa5a50000 ,
V_4 + V_13 ) ;
F_8 ( ( F_9 ( V_4 + V_14 ) & ~ 0x0f ) | 0x5a5a0000 ,
V_4 + V_14 ) ;
F_7 ( V_4 ) ;
F_1 () ;
F_10 () ;
}
