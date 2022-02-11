static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 - V_4 ;
unsigned long V_5 ;
T_1 V_6 , V_7 ;
#ifdef F_2
V_5 = ( V_3 & 0x40 ) ? F_2 : V_8 ;
#else
V_5 = V_8 ;
#endif
V_5 += ( V_3 & 0x20 ) ? V_9 : V_10 ;
V_7 = 0x1 << ( V_3 & 0x1f ) ;
V_6 = F_3 ( V_5 ) ;
F_4 ( V_6 | V_7 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 - V_4 ;
unsigned long V_5 ;
T_1 V_6 , V_7 ;
#ifdef F_2
V_5 = ( V_3 & 0x40 ) ? F_2 : V_8 ;
#else
V_5 = V_8 ;
#endif
V_5 += ( ( V_3 & 0x20 ) ? V_9 : V_10 ) ;
V_7 = 0x1 << ( V_3 & 0x1f ) ;
if ( ( V_3 & 0x20 ) == 0 )
V_7 |= 0x1 ;
V_6 = F_3 ( V_5 ) ;
F_4 ( V_6 & ~ V_7 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
F_7 ( 0x1 << ( V_3 - V_11 ) , V_12 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 - V_4 ;
unsigned long V_13 ;
#ifdef F_2
V_13 = ( V_3 & 0x40 ) ? F_2 : V_8 ;
#else
V_13 = V_8 ;
#endif
V_13 += V_14 + ( V_3 & 0x3f ) ;
if ( F_9 ( V_13 ) == 0 )
F_7 ( V_15 -- , V_13 ) ;
V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_16 ) && ( V_3 <= V_17 ) ) {
T_2 V_18 ;
V_3 -= V_11 ;
V_18 = F_9 ( V_19 ) ;
F_7 ( V_18 & ~ ( 0x1 << V_3 ) , V_19 ) ;
V_18 = F_9 ( V_20 ) ;
F_7 ( V_18 | ( 0x1 << V_3 ) , V_20 ) ;
}
F_5 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_3 = V_2 -> V_3 ;
T_3 V_21 , V_22 ;
switch ( type ) {
case V_23 :
V_22 = 0x1 ;
break;
case V_24 :
V_22 = 0x2 ;
break;
case V_25 :
V_22 = 0x3 ;
break;
default:
V_22 = 0 ;
break;
}
if ( V_22 )
F_11 ( V_3 , V_26 ) ;
V_3 -= V_11 ;
V_21 = F_12 ( V_27 ) ;
V_21 = ( V_21 & ~ ( 0x3 << ( V_3 * 2 ) ) ) | ( V_22 << ( V_3 * 2 ) ) ;
F_13 ( V_21 , V_27 ) ;
return 0 ;
}
void T_4 F_14 ( void )
{
int V_3 ;
F_15 () ;
F_4 ( 0x1 , V_8 + V_10 ) ;
#ifdef F_2
F_4 ( 0x1 , F_2 + V_10 ) ;
#endif
for ( V_3 = V_4 ; ( V_3 < V_4 + V_28 ) ; V_3 ++ ) {
if ( ( V_3 >= V_16 ) && ( V_3 <= V_17 ) )
F_16 ( V_3 , & V_29 ) ;
else
F_16 ( V_3 , & V_30 ) ;
F_17 ( V_3 , V_31 ) ;
F_11 ( V_3 , V_32 ) ;
}
}
