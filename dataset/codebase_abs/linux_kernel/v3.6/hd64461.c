static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
unsigned short V_4 ;
unsigned short V_5 = 1 << ( V_3 - V_6 ) ;
V_4 = F_2 ( V_7 ) ;
V_4 |= V_5 ;
F_3 ( V_4 , V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
unsigned short V_4 ;
unsigned short V_5 = 1 << ( V_3 - V_6 ) ;
V_4 = F_2 ( V_7 ) ;
V_4 &= ~ V_5 ;
F_3 ( V_4 , V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
#ifdef F_6
if ( V_2 -> V_3 == V_6 + 13 )
F_7 ( 0x00 , V_8 ) ;
#endif
}
static void F_8 ( unsigned int V_3 , struct V_9 * V_10 )
{
unsigned short V_11 = F_2 ( V_12 ) ;
unsigned int V_13 = V_6 ;
V_11 &= ( 1 << V_14 ) - 1 ;
for (; V_11 ; V_11 >>= 1 , V_13 ++ ) {
if ( ! ( V_11 & 1 ) )
continue;
F_9 ( V_13 ) ;
}
}
int T_1 F_10 ( void )
{
int V_15 , V_16 ;
F_11 ( V_17
L_1 ,
V_18 , V_19 , V_6 ,
V_6 + 15 ) ;
#if F_12 ( V_20 )
F_3 ( 0x2240 , V_21 ) ;
#endif
F_3 ( 0xffff , V_7 ) ;
V_15 = F_13 ( V_6 , V_6 , 16 , - 1 ) ;
if ( F_14 ( V_15 ) ) {
F_15 ( L_2 , V_22 ) ;
return V_15 ;
}
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ )
F_16 ( V_15 + V_16 , & V_23 ,
V_24 ) ;
F_17 ( V_19 , F_8 ) ;
F_18 ( V_19 , V_25 ) ;
#ifdef F_6
F_11 ( V_17 L_3 ) ;
F_7 ( 0x4c , V_26 ) ;
F_7 ( 0x00 , V_8 ) ;
#endif
return 0 ;
}
