static int F_1 ( unsigned int V_1 , unsigned int type )
{
unsigned int V_2 , V_3 , V_4 ;
V_2 = V_1 >> 5 ;
if ( F_2 ( V_2 >= 4 ) )
return - V_5 ;
V_3 = 1U << ( V_1 & 0x1F ) ;
V_4 = F_3 ( V_6 + F_4 ( V_2 ) ) | V_3 ;
if ( type )
V_4 &= ~ V_3 ;
F_5 ( V_4 , V_6 + F_4 ( V_2 ) ) ;
return 0 ;
}
static void F_6 ( struct V_7 * V_8 )
{
int V_2 , V_9 ;
V_2 = V_8 -> V_1 >> 5 ;
V_9 = V_8 -> V_1 & 0x1F ;
F_5 ( 1 << V_9 , V_6 + F_7 ( V_2 ) ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
int V_2 , V_9 ;
V_2 = V_8 -> V_1 >> 5 ;
V_9 = V_8 -> V_1 & 0x1F ;
F_5 ( 1 << V_9 , V_6 + F_9 ( V_2 ) ) ;
}
static int F_10 ( struct V_7 * V_8 , unsigned int V_10 )
{
unsigned int V_2 , V_9 ;
V_2 = V_8 -> V_1 >> 5 ;
V_9 = V_8 -> V_1 & 0x1F ;
if ( V_2 > 3 )
return - V_5 ;
if ( V_10 )
V_11 [ V_2 ] |= ( 1 << V_9 ) ;
else
V_11 [ V_2 ] &= ~ ( 1 << V_9 ) ;
return 0 ;
}
void T_1 F_11 ( void T_2 * V_12 )
{
int V_13 ;
V_6 = V_12 ;
V_13 = F_3 ( V_6 + V_14 ) ;
F_5 ( 0x80010001 , V_6 + V_14 ) ;
F_5 ( 0x1f , V_6 + V_15 ) ;
F_5 ( 0x02 , V_6 + V_16 ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_4 ( V_13 ) ) ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ )
F_5 ( 0xFFFFFFFF , V_6 + F_7 ( V_13 ) ) ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
F_12 ( V_13 , & V_18 . V_19 ,
V_20 ) ;
F_13 ( V_13 , V_21 ) ;
}
#ifdef F_14
F_15 () ;
#endif
F_16 ( L_1 ) ;
}
int F_17 ( int V_22 )
{
unsigned int V_13 , V_23 ;
F_5 ( 1 , V_6 + V_24 ) ;
if ( F_2 ( F_3 ( V_6 + V_24 ) == 0 ) )
return - V_25 ;
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
V_23 = V_22 ? F_3 ( V_6 + F_9 ( V_13 ) ) :
V_11 [ V_13 ] ;
F_5 ( V_23 , V_6 + F_18 ( V_13 ) ) ;
}
return 0 ;
}
