static struct V_1 * F_1 ( void )
{
struct V_2 * V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
return V_3 ? & V_3 -> V_5 : NULL ;
}
static int F_3 ( struct V_1 * V_5 , bool V_6 , int V_7 )
{
struct V_2 * V_3 = F_4 ( V_5 , struct V_2 , V_5 ) ;
V_3 -> V_8 = V_7 ;
V_3 -> V_9 = V_6 ;
if ( V_6 || V_7 == 0 ) {
F_5 ( 0 , V_5 -> V_10 ) ;
F_5 ( 0 , V_5 -> V_10 ) ;
F_6 ( V_5 -> V_10 + 3 ) ;
return 0 ;
}
F_5 ( V_7 - 1 , V_5 -> V_10 ) ;
F_7 ( 10 ) ;
F_6 ( V_5 -> V_10 + 2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_5 , T_1 V_11 )
{
struct V_2 * V_3 = F_4 ( V_5 , struct V_2 , V_5 ) ;
struct V_12 * V_13 = & V_5 -> V_13 ;
unsigned long long V_14 , V_15 , V_16 ;
bool V_17 = V_5 -> V_17 ;
int V_18 ;
if ( V_11 == 0 ) {
F_9 ( V_13 , L_1 ) ;
return - V_19 ;
}
V_16 = ( V_11 / 160 - 8800 ) * 2 ;
V_15 = ( unsigned long long ) V_16 + 0x4d1c ;
V_14 = 0xc480402c10080000ull ;
V_18 = 45 ;
F_5 ( 0 , V_5 -> V_10 ) ;
F_5 ( 0 , V_5 -> V_10 ) ;
F_6 ( V_5 -> V_10 + 3 ) ;
F_5 ( 0x40 , V_5 -> V_10 ) ;
F_5 ( 0xc0 , V_5 -> V_10 ) ;
V_14 = ( V_14 ^ ( ( V_15 & 0xff ) << 47 ) ^ ( ( V_15 & 0xff00 ) << 30 ) ^ ( V_17 << 31 ) ) ;
while ( V_18 -- ) {
if ( ( V_14 & 0x8000000000000000ull ) != 0 ) {
F_5 ( 0x80 , V_5 -> V_10 ) ;
F_10 ( 50 ) ;
F_5 ( 0x00 , V_5 -> V_10 ) ;
F_10 ( 50 ) ;
F_5 ( 0x80 , V_5 -> V_10 ) ;
F_10 ( 50 ) ;
} else {
F_5 ( 0xc0 , V_5 -> V_10 ) ;
F_10 ( 50 ) ;
F_5 ( 0x40 , V_5 -> V_10 ) ;
F_10 ( 50 ) ;
F_5 ( 0xc0 , V_5 -> V_10 ) ;
F_10 ( 50 ) ;
}
V_14 *= 2 ;
}
F_5 ( 0x80 , V_5 -> V_10 ) ;
F_5 ( 0xc0 , V_5 -> V_10 ) ;
F_5 ( 0x40 , V_5 -> V_10 ) ;
F_10 ( 1000 ) ;
F_6 ( V_5 -> V_10 + 2 ) ;
F_10 ( 1000 ) ;
return F_3 ( V_5 , V_3 -> V_9 , V_3 -> V_8 ) ;
}
static T_1 F_11 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 , struct V_2 , V_5 ) ;
int V_20 , V_21 ;
F_5 ( 0x00 , V_5 -> V_10 ) ;
F_5 ( V_3 -> V_8 , V_5 -> V_10 ) ;
F_7 ( 20 ) ;
V_20 = F_6 ( V_5 -> V_10 ) ;
F_7 ( 10 ) ;
V_21 = F_6 ( V_5 -> V_10 ) ;
return ( V_20 == V_21 && V_20 == 0xcf ) ?
V_22 : V_23 ;
}
static T_1 F_12 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_4 ( V_5 , struct V_2 , V_5 ) ;
int V_20 , V_21 ;
F_5 ( 0x00 , V_5 -> V_10 ) ;
F_5 ( V_3 -> V_8 , V_5 -> V_10 ) ;
F_7 ( 20 ) ;
V_20 = F_6 ( V_5 -> V_10 ) ;
F_7 ( 10 ) ;
V_21 = F_6 ( V_5 -> V_10 ) ;
if ( V_20 != V_21 )
return 0 ;
return ( V_20 == 0xcf || V_20 == 0xdf || V_20 == 0xef ) ? 0xffff : 0 ;
}
static int F_13 ( struct V_1 * V_5 , bool V_17 )
{
return F_8 ( V_5 , V_5 -> V_11 ) ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_24 . V_25 , V_26 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_24 . V_25 ) ;
}
