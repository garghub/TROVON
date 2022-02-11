static void F_1 ( unsigned long * V_1 ,
unsigned int V_2 ,
T_1 * V_3 )
{
enum V_4 V_5 ;
T_1 V_6 ;
int V_7 ;
* V_3 &= ~ V_8 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
V_5 = F_2 ( V_1 [ V_7 ] ) ;
V_6 = F_3 ( V_1 [ V_7 ] ) ;
if ( ( V_5 == V_9 ) ||
( V_5 == V_10 ) ) {
* V_3 |= V_11 ;
return;
}
}
}
static int F_4 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
unsigned V_16 , bool V_17 )
{
struct V_18 * V_19 = F_5 ( V_13 ) ;
struct V_20 * V_21 = V_19 -> V_21 ;
const struct V_22 * V_23 ;
T_1 V_24 ;
V_23 = & V_21 -> V_25 [ V_16 ] ;
if ( V_23 -> V_26 == - 1 )
return - V_27 ;
V_24 = F_6 ( V_19 -> V_28 + V_23 -> V_26 ) ;
if ( V_17 )
V_24 = ( V_24 & ~ V_29 ) | V_30 ;
else
V_24 = ( V_24 & ~ V_30 ) | V_29 ;
F_7 ( V_24 , V_19 -> V_28 + V_23 -> V_26 ) ;
return 0 ;
}
static int F_8 ( struct V_31 * V_32 )
{
return F_9 ( V_32 , & V_33 ) ;
}
static int T_2 F_10 ( void )
{
return F_11 ( & V_34 ) ;
}
