static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
T_1 V_6 ;
V_3 -= V_4 ;
V_6 = 0x8 << V_7 [ V_3 ] . V_8 ;
F_2 ( V_6 , V_9 + V_7 [ V_3 ] . V_10 ) ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
T_1 V_6 ;
V_3 -= V_4 ;
V_6 = 0xd << V_7 [ V_3 ] . V_8 ;
F_2 ( V_6 , V_9 + V_7 [ V_3 ] . V_10 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
V_3 -= V_4 ;
if ( V_7 [ V_3 ] . V_11 ) {
T_1 V_6 ;
V_6 = F_5 ( V_9 + V_7 [ V_3 ] . V_10 ) ;
V_6 &= ( 0x7 << V_7 [ V_3 ] . V_8 ) ;
V_6 |= ( 0x8 << V_7 [ V_3 ] . V_8 ) ;
F_2 ( V_6 , V_9 + V_7 [ V_3 ] . V_10 ) ;
}
}
}
static int F_6 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_3 = V_2 -> V_3 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) ) {
V_3 -= V_4 ;
if ( V_7 [ V_3 ] . V_11 ) {
T_1 V_6 ;
V_6 = F_5 ( V_9 + V_12 ) ;
if ( type == V_13 )
V_6 &= ~ ( 0x1 << ( 32 - V_3 ) ) ;
else
V_6 |= ( 0x1 << ( 32 - V_3 ) ) ;
F_2 ( V_6 , V_9 + V_12 ) ;
}
}
return 0 ;
}
static void F_7 ( unsigned int V_3 , struct V_14 * V_15 )
{
F_8 ( V_15 ) -> F_9 ( & V_15 -> V_1 ) ;
F_10 ( V_3 , V_15 ) ;
}
void T_2 F_11 ( void )
{
int V_3 , V_16 ;
F_2 ( 0x88888888 , V_9 + V_17 ) ;
F_2 ( 0x88888888 , V_9 + V_18 ) ;
F_2 ( 0x88888888 , V_9 + V_19 ) ;
F_2 ( 0x88888888 , V_9 + V_20 ) ;
for ( V_3 = 0 ; ( V_3 < V_21 ) ; V_3 ++ ) {
F_12 ( V_3 , & V_22 ) ;
V_16 = 0 ;
if ( ( V_3 >= V_4 ) && ( V_3 <= V_5 ) )
V_16 = V_7 [ V_3 - V_4 ] . V_11 ;
if ( V_16 ) {
F_13 ( V_3 , V_23 ) ;
F_14 ( V_3 , F_7 ) ;
} else {
F_13 ( V_3 , V_24 ) ;
F_14 ( V_3 , V_25 ) ;
}
}
}
