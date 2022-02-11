static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 V_3 ;
const unsigned int * V_4 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
V_4 = F_3 ( V_2 , L_2 , NULL ) ;
V_3 = F_4 ( V_2 , V_4 ) ;
F_5 ( V_2 ) ;
V_5 = F_6 ( V_3 , V_4 [ 1 ] ) ;
V_2 = F_2 ( NULL , NULL , L_3 ) ;
V_4 = F_3 ( V_2 , L_2 , NULL ) ;
V_3 = F_4 ( V_2 , V_4 ) ;
F_5 ( V_2 ) ;
V_6 = F_6 ( V_3 , V_4 [ 1 ] ) ;
#ifdef F_7
F_8 () ;
#endif
}
static void F_9 ( void )
{
T_3 V_7 ;
F_10 () ;
V_7 = F_11 ( V_5 + V_8 ) ;
V_7 &= 0xFFFF0FFF ;
F_12 ( V_5 + V_8 , V_7 ) ;
V_7 = F_11 ( V_6 + V_9 ) ;
V_7 |= 0x00000004 ;
F_12 ( V_6 + V_9 , V_7 ) ;
V_7 = F_11 ( V_6 + V_10 ) ;
V_7 |= 0x00000004 ;
F_12 ( V_6 + V_10 , V_7 ) ;
V_7 = F_11 ( V_5 + V_11 ) ;
V_7 &= 0xFFFF0FFF ;
F_12 ( V_5 + V_11 , V_7 ) ;
V_7 = F_11 ( V_6 + V_9 ) ;
V_7 |= 0x00080000 ;
F_12 ( V_6 + V_9 , V_7 ) ;
V_7 = F_11 ( V_6 + V_10 ) ;
V_7 |= 0x00080000 ;
F_12 ( V_6 + V_10 , V_7 ) ;
F_12 ( V_6 + V_12 , 0x00080004 ) ;
}
static void F_13 ( char * V_13 )
{
F_9 () ;
F_14 ( 100 ) ;
F_15 ( L_4 ) ;
}
void F_16 ( struct V_14 * V_15 )
{
F_17 ( V_15 , L_5 ) ;
F_17 ( V_15 , L_6 , V_16 ) ;
}
static int T_1 F_18 ( void )
{
unsigned long V_17 = F_19 () ;
if ( ! F_20 ( V_17 , L_7 ) )
return 0 ;
F_21 ( V_18 L_8 ) ;
F_22 ( 0 ) ;
F_22 ( V_19 | V_20 | V_21 ) ;
return 1 ;
}
