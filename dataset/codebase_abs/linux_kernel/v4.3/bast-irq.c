static void
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 &= ~ V_5 [ V_2 -> V_6 ] ;
F_3 ( V_3 , V_4 ) ;
}
static void
F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_7 + V_9 ;
F_1 ( V_2 ) ;
V_8 -> V_1 . V_10 -> V_11 ( & V_8 -> V_1 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_4 ) ;
V_3 |= V_5 [ V_2 -> V_6 ] ;
F_3 ( V_3 , V_4 ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
unsigned int V_12 ;
unsigned int V_13 ;
int V_14 ;
V_12 = F_2 ( V_15 ) & 0xf ;
if ( F_7 ( V_12 == 0 ) ) {
V_8 = V_7 + V_9 ;
V_8 -> V_1 . V_10 -> V_11 ( & V_8 -> V_1 ) ;
} else {
for ( V_14 = 0 ; V_12 != 0 ; V_14 ++ , V_12 >>= 1 ) {
if ( V_12 & 1 ) {
V_13 = V_16 [ V_14 ] ;
F_8 ( V_13 ) ;
}
}
}
}
static T_1 int F_9 ( void )
{
unsigned int V_14 ;
if ( F_10 () ) {
F_11 ( V_17 L_1 ) ;
F_3 ( 0x0 , V_4 ) ;
F_12 ( V_9 , F_6 ) ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
unsigned int V_13 = V_16 [ V_14 ] ;
F_13 ( V_13 , & V_18 ,
V_19 ) ;
F_14 ( V_13 , V_20 ) ;
}
}
return 0 ;
}
