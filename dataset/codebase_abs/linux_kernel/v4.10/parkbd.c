static int F_1 ( void )
{
return ( F_2 ( V_1 -> V_2 ) >> 6 ) ^ 2 ;
}
static void F_3 ( int V_3 )
{
F_4 ( V_1 -> V_2 , ( ~ V_3 & 3 ) | 0x10 ) ;
}
static int F_5 ( struct V_4 * V_2 , unsigned char V_5 )
{
unsigned char V_6 ;
if ( ! V_7 ) return - 1 ;
V_6 = V_5 ^ ( V_5 >> 4 ) ;
V_6 = V_6 ^ ( V_6 >> 2 ) ;
V_6 = V_6 ^ ( V_6 >> 1 ) ;
V_8 = 0 ;
V_9 = 1 ;
V_10 = V_5 | ( ( ( int ) ( ~ V_6 & 1 ) ) << 8 ) | 0x600 ;
F_3 ( 2 ) ;
return 0 ;
}
static void F_6 ( void * V_11 )
{
if ( V_9 ) {
if ( V_8 && ( ( V_8 == 11 ) || F_7 ( V_12 , V_13 + V_14 / 100 ) ) ) {
V_8 = 0 ;
V_10 = 0 ;
V_9 = 0 ;
F_3 ( 3 ) ;
return;
}
F_3 ( ( ( V_10 >> V_8 ++ ) & 1 ) | 2 ) ;
if ( V_8 == 11 ) {
V_8 = 0 ;
V_10 = 0 ;
V_9 = 0 ;
F_3 ( 3 ) ;
}
} else {
if ( ( V_8 == V_7 + 10 ) || F_7 ( V_12 , V_13 + V_14 / 100 ) ) {
V_8 = 0 ;
V_10 = 0 ;
}
V_10 |= ( F_1 () >> 1 ) << V_8 ++ ;
if ( V_8 == V_7 + 10 )
F_8 ( V_15 , ( V_10 >> ( 2 - V_7 ) ) & 0xff , 0 ) ;
}
V_13 = V_12 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_18 V_19 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_20 = F_6 ;
V_19 . V_21 = V_22 ;
V_1 = F_10 ( V_17 , L_1 ,
& V_19 , 0 ) ;
if ( ! V_1 )
return - V_23 ;
if ( F_11 ( V_1 ) ) {
F_12 ( V_1 ) ;
return - V_24 ;
}
V_25 = V_12 ;
return 0 ;
}
static struct V_4 * F_13 ( void )
{
struct V_4 * V_4 ;
V_4 = F_14 ( sizeof( struct V_4 ) , V_26 ) ;
if ( V_4 ) {
V_4 -> V_27 . type = V_7 ;
V_4 -> V_28 = F_5 ,
F_15 ( V_4 -> V_29 , L_2 , sizeof( V_4 -> V_29 ) ) ;
snprintf ( V_4 -> V_30 , sizeof( V_4 -> V_30 ) , L_3 , V_1 -> V_2 -> V_29 ) ;
}
return V_4 ;
}
static void F_16 ( struct V_16 * V_17 )
{
if ( V_17 -> V_31 != V_32 ) {
F_17 ( L_4 , V_17 -> V_31 ) ;
return;
}
if ( F_9 ( V_17 ) )
return;
V_15 = F_13 () ;
if ( ! V_15 ) {
F_18 ( V_1 ) ;
F_12 ( V_1 ) ;
return;
}
F_3 ( 3 ) ;
F_19 ( V_15 ) ;
F_20 ( V_33 L_5 ,
V_7 ? L_6 : L_7 , V_1 -> V_2 -> V_29 ) ;
return;
}
static void F_21 ( struct V_16 * V_2 )
{
if ( ! V_15 || V_2 -> V_31 != V_32 )
return;
F_18 ( V_1 ) ;
F_22 ( V_15 ) ;
F_12 ( V_1 ) ;
V_15 = NULL ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_34 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_34 ) ;
}
