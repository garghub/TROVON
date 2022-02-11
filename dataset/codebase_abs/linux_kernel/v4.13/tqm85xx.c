static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 ,
V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
F_5 () ;
}
static void T_1 F_6 ( void )
{
if ( V_3 . V_4 )
V_3 . V_4 ( L_2 , 0 ) ;
#ifdef F_7
F_8 () ;
#endif
F_9 () ;
}
static void F_10 ( struct V_5 * V_6 )
{
T_2 V_7 , V_8 , V_9 ;
V_7 = F_11 ( V_10 ) ;
V_8 = F_11 ( V_11 ) ;
F_12 ( V_6 , L_3 ) ;
F_12 ( V_6 , L_4 , V_7 ) ;
F_12 ( V_6 , L_5 , V_8 ) ;
V_9 = F_11 ( V_12 ) ;
F_12 ( V_6 , L_6 , ( ( V_9 >> 24 ) & 0x3f ) ) ;
}
static void F_13 ( struct V_13 * V_14 )
{
unsigned int V_15 ;
if ( ! F_14 ( V_16 ) )
return;
F_15 ( & V_14 -> V_17 , L_7 ) ;
F_16 ( V_14 , 0x80 , & V_15 ) ;
F_17 ( V_14 , 0x80 , V_15 | ( 1 << 27 ) ) ;
}
static int T_1 F_18 ( void )
{
return F_19 ( V_18 , V_19 ) ;
}
