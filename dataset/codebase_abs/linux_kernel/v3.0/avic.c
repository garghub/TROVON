static int F_1 ( unsigned char V_1 , unsigned char V_2 )
{
unsigned int V_3 ;
unsigned int V_4 = 0x0F << V_1 % 8 * 4 ;
if ( V_1 >= V_5 )
return - V_6 ; ;
V_3 = F_2 ( V_7 + F_3 ( V_1 / 8 ) ) ;
V_3 &= ~ V_4 ;
V_3 |= V_2 & V_4 ;
F_4 ( V_3 , V_7 + F_3 ( V_1 / 8 ) ) ;
return 0 ;
}
static int F_5 ( unsigned int V_1 , unsigned int type )
{
unsigned int V_8 ;
if ( V_1 >= V_5 )
return - V_6 ;
if ( V_1 < V_5 / 2 ) {
V_8 = F_2 ( V_7 + V_9 ) & ~ ( 1 << V_1 ) ;
F_4 ( V_8 | ( ! ! type << V_1 ) , V_7 + V_9 ) ;
} else {
V_1 -= V_5 / 2 ;
V_8 = F_2 ( V_7 + V_10 ) & ~ ( 1 << V_1 ) ;
F_4 ( V_8 | ( ! ! type << V_1 ) , V_7 + V_10 ) ;
}
return 0 ;
}
static void F_6 ( struct V_11 * V_12 )
{
F_4 ( V_12 -> V_1 , V_7 + V_13 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
F_4 ( V_12 -> V_1 , V_7 + V_14 ) ;
}
void T_1 F_8 ( void T_2 * V_15 )
{
int V_16 ;
V_7 = V_15 ;
F_4 ( 0 , V_7 + V_17 ) ;
F_4 ( 0x1f , V_7 + V_18 ) ;
F_4 ( 0 , V_7 + V_19 ) ;
F_4 ( 0 , V_7 + V_20 ) ;
F_4 ( 0 , V_7 + V_10 ) ;
F_4 ( 0 , V_7 + V_9 ) ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ ) {
F_9 ( V_16 , & V_21 . V_22 ,
V_23 ) ;
F_10 ( V_16 , V_24 ) ;
}
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ )
F_4 ( 0 , V_7 + F_3 ( V_16 ) ) ;
#ifdef F_11
F_12 () ;
#endif
F_13 ( V_25 L_1 ) ;
}
