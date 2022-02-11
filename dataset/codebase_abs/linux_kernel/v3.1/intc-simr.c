static unsigned int inline F_1 ( unsigned int V_1 )
{
return V_2 [ V_1 - V_3 ] ;
}
static unsigned int inline F_1 ( unsigned int V_1 )
{
return V_1 - V_3 ;
}
static void F_2 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 - V_6 ;
if ( V_7 && ( V_1 > 64 ) )
F_3 ( V_1 - 64 , V_7 ) ;
else
F_3 ( V_1 , V_8 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 - V_6 ;
if ( V_9 && ( V_1 > 64 ) )
F_3 ( V_1 - 64 , V_9 ) ;
else
F_3 ( V_1 , V_10 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
unsigned int V_11 = F_1 ( V_5 -> V_1 ) ;
F_3 ( 0x1 << V_11 , V_12 ) ;
}
static unsigned int F_6 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 ;
if ( ( V_1 >= V_13 ) && ( V_1 <= V_14 ) ) {
unsigned int V_11 = F_1 ( V_1 ) ;
T_1 V_15 ;
V_15 = F_7 ( V_16 ) ;
F_3 ( V_15 & ~ ( 0x1 << V_11 ) , V_16 ) ;
V_15 = F_7 ( V_17 ) ;
F_3 ( V_15 | ( 0x1 << V_11 ) , V_17 ) ;
}
V_1 -= V_6 ;
if ( V_18 && ( V_1 > 64 ) )
F_3 ( 5 , V_18 + V_1 - 64 ) ;
else
F_3 ( 5 , V_19 + V_1 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 , unsigned int type )
{
unsigned int V_11 , V_1 = V_5 -> V_1 ;
T_2 V_20 , V_21 ;
switch ( type ) {
case V_22 :
V_21 = 0x1 ;
break;
case V_23 :
V_21 = 0x2 ;
break;
case V_24 :
V_21 = 0x3 ;
break;
default:
V_21 = 0 ;
break;
}
if ( V_21 )
F_9 ( V_1 , V_25 ) ;
V_11 = F_1 ( V_1 ) * 2 ;
V_20 = F_10 ( V_26 ) ;
V_20 = ( V_20 & ~ ( 0x3 << V_11 ) ) | ( V_21 << V_11 ) ;
F_11 ( V_20 , V_26 ) ;
return 0 ;
}
void T_3 F_12 ( void )
{
int V_1 , V_27 ;
F_3 ( 0xff , V_8 ) ;
if ( V_7 )
F_3 ( 0xff , V_7 ) ;
V_27 = V_6 + 64 + ( V_18 ? 64 : 0 ) ;
for ( V_1 = V_6 ; ( V_1 < V_27 ) ; V_1 ++ ) {
if ( ( V_1 >= V_13 ) && ( V_1 <= V_14 ) )
F_13 ( V_1 , & V_28 ) ;
else
F_13 ( V_1 , & V_29 ) ;
F_14 ( V_1 , V_30 ) ;
F_9 ( V_1 , V_31 ) ;
}
}
