static inline unsigned int F_1 ( unsigned int V_1 )
{
return V_2 [ V_1 - V_3 ] ;
}
static inline unsigned int F_1 ( unsigned int V_1 )
{
return V_1 - V_3 ;
}
static void F_2 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 - V_6 ;
if ( V_7 && ( V_1 > 128 ) )
F_3 ( V_1 - 128 , V_7 ) ;
else if ( V_8 && ( V_1 > 64 ) )
F_3 ( V_1 - 64 , V_8 ) ;
else
F_3 ( V_1 , V_9 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 - V_6 ;
if ( V_10 && ( V_1 > 128 ) )
F_3 ( V_1 - 128 , V_10 ) ;
else if ( V_11 && ( V_1 > 64 ) )
F_3 ( V_1 - 64 , V_11 ) ;
else
F_3 ( V_1 , V_12 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
unsigned int V_13 = F_1 ( V_5 -> V_1 ) ;
F_3 ( 0x1 << V_13 , V_14 ) ;
}
static unsigned int F_6 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 ;
if ( ( V_1 >= V_15 ) && ( V_1 <= V_16 ) ) {
unsigned int V_13 = F_1 ( V_1 ) ;
T_1 V_17 ;
#if F_7 ( V_18 )
V_17 = F_8 ( V_18 ) ;
F_3 ( V_17 & ~ ( 0x1 << V_13 ) , V_18 ) ;
#endif
V_17 = F_8 ( V_19 ) ;
F_3 ( V_17 | ( 0x1 << V_13 ) , V_19 ) ;
}
V_1 -= V_6 ;
if ( V_20 && ( V_1 > 128 ) )
F_3 ( 5 , V_20 + V_1 - 128 ) ;
else if ( V_21 && ( V_1 > 64 ) )
F_3 ( 5 , V_21 + V_1 - 64 ) ;
else
F_3 ( 5 , V_22 + V_1 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , unsigned int type )
{
unsigned int V_13 , V_1 = V_5 -> V_1 ;
T_2 V_23 , V_24 ;
switch ( type ) {
case V_25 :
V_24 = 0x1 ;
break;
case V_26 :
V_24 = 0x2 ;
break;
case V_27 :
V_24 = 0x3 ;
break;
default:
V_24 = 0 ;
break;
}
if ( V_24 )
F_10 ( V_1 , V_28 ) ;
V_13 = F_1 ( V_1 ) * 2 ;
V_23 = F_11 ( V_29 ) ;
V_23 = ( V_23 & ~ ( 0x3 << V_13 ) ) | ( V_24 << V_13 ) ;
F_12 ( V_23 , V_29 ) ;
return 0 ;
}
void T_3 F_13 ( void )
{
int V_1 , V_30 ;
F_3 ( 0xff , V_9 ) ;
if ( V_8 )
F_3 ( 0xff , V_8 ) ;
if ( V_7 )
F_3 ( 0xff , V_7 ) ;
V_30 = V_6 + 64 + ( V_21 ? 64 : 0 ) +
( V_20 ? 64 : 0 ) ;
for ( V_1 = V_6 ; ( V_1 < V_30 ) ; V_1 ++ ) {
if ( ( V_1 >= V_15 ) && ( V_1 <= V_16 ) )
F_14 ( V_1 , & V_31 ) ;
else
F_14 ( V_1 , & V_32 ) ;
F_15 ( V_1 , V_33 ) ;
F_10 ( V_1 , V_34 ) ;
}
}
