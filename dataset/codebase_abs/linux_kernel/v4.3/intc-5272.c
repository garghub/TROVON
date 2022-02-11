static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
T_1 V_6 ;
V_3 -= V_4 ;
V_6 = 0x8 << V_7 [ V_3 ] . V_8 ;
F_2 ( V_6 , V_7 [ V_3 ] . V_9 ) ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
T_1 V_6 ;
V_3 -= V_4 ;
V_6 = 0xd << V_7 [ V_3 ] . V_8 ;
F_2 ( V_6 , V_7 [ V_3 ] . V_9 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
V_3 -= V_4 ;
if ( V_7 [ V_3 ] . V_10 ) {
T_1 V_6 ;
V_6 = F_5 ( V_7 [ V_3 ] . V_9 ) ;
V_6 &= ( 0x7 << V_7 [ V_3 ] . V_8 ) ;
V_6 |= ( 0x8 << V_7 [ V_3 ] . V_8 ) ;
F_2 ( V_6 , V_7 [ V_3 ] . V_9 ) ;
}
}
}
static int F_6 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
V_3 -= V_4 ;
if ( V_7 [ V_3 ] . V_10 ) {
T_1 V_6 ;
V_6 = F_5 ( V_11 ) ;
if ( type == V_12 )
V_6 &= ~ ( 0x1 << ( 32 - V_3 ) ) ;
else
V_6 |= ( 0x1 << ( 32 - V_3 ) ) ;
F_2 ( V_6 , V_11 ) ;
}
}
return 0 ;
}
static void F_7 ( struct V_13 * V_14 )
{
F_8 ( V_14 ) -> F_9 ( & V_14 -> V_1 ) ;
F_10 ( V_14 ) ;
}
void T_2 F_11 ( void )
{
int V_3 , V_15 ;
F_2 ( 0x88888888 , V_16 ) ;
F_2 ( 0x88888888 , V_17 ) ;
F_2 ( 0x88888888 , V_18 ) ;
F_2 ( 0x88888888 , V_19 ) ;
for ( V_3 = 0 ; ( V_3 < V_20 ) ; V_3 ++ ) {
F_12 ( V_3 , & V_21 ) ;
V_15 = 0 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) )
V_15 = V_7 [ V_3 - V_4 ] . V_10 ;
if ( V_15 ) {
F_13 ( V_3 , V_22 ) ;
F_14 ( V_3 , F_7 ) ;
} else {
F_13 ( V_3 , V_23 ) ;
F_14 ( V_3 , V_24 ) ;
}
}
}
