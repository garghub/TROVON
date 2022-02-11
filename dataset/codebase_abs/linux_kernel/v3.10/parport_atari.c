static unsigned char
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned char V_4 ;
F_2 ( V_3 ) ;
V_5 . V_6 = 15 ;
V_4 = V_5 . V_6 ;
F_3 ( V_3 ) ;
return V_4 ;
}
static void
F_4 ( struct V_1 * V_2 , unsigned char V_4 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_5 . V_6 = 15 ;
V_5 . V_7 = V_4 ;
F_3 ( V_3 ) ;
}
static unsigned char
F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned char V_8 = 0 ;
F_2 ( V_3 ) ;
V_5 . V_6 = 14 ;
if ( ! ( V_5 . V_6 & ( 1 << 5 ) ) )
V_8 = V_9 ;
F_3 ( V_3 ) ;
return V_8 ;
}
static void
F_6 ( struct V_1 * V_2 , unsigned char V_8 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_5 . V_6 = 14 ;
if ( V_8 & V_9 )
V_5 . V_7 = V_5 . V_6 & ~ ( 1 << 5 ) ;
else
V_5 . V_7 = V_5 . V_6 | ( 1 << 5 ) ;
F_3 ( V_3 ) ;
}
static unsigned char
F_7 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char V_11 )
{
unsigned char V_12 = F_5 ( V_2 ) ;
F_6 ( V_2 , ( V_12 & ~ V_10 ) ^ V_11 ) ;
return V_12 ;
}
static unsigned char
F_8 ( struct V_1 * V_2 )
{
return ( ( V_13 . V_14 & 1 ? 0 : V_15 ) |
V_16 | V_17 ) ;
}
static void
F_9 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
}
static void
F_10 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
}
static void
F_11 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
}
static void
F_12 ( struct V_1 * V_2 )
{
F_13 ( V_22 ) ;
}
static void
F_14 ( struct V_1 * V_2 )
{
F_15 ( V_22 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_5 . V_6 = 7 ;
V_5 . V_7 = V_5 . V_6 | 0x40 ;
F_3 ( V_3 ) ;
}
static void
F_17 ( struct V_1 * V_2 )
{
}
static int T_1 F_18 ( void )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
if ( V_23 ) {
F_2 ( V_3 ) ;
V_5 . V_6 = 7 ;
V_5 . V_7 = ( V_5 . V_6 & 0x3f ) | 0xc0 ;
V_5 . V_6 = 14 ;
V_5 . V_7 = V_5 . V_6 | ( 1 << 5 ) ;
F_3 ( V_3 ) ;
V_13 . V_24 &= ~ 1 ;
V_13 . V_25 &= ~ 1 ;
V_2 = F_19 ( ( unsigned long ) & V_5 . V_7 ,
V_22 , V_26 ,
& V_27 ) ;
if ( ! V_2 )
return - V_28 ;
if ( F_20 ( V_22 , V_29 ,
V_30 , V_2 -> V_31 , V_2 ) ) {
F_21 ( V_2 ) ;
return - V_28 ;
}
V_32 = V_2 ;
F_22 ( V_33 L_1 , V_2 -> V_31 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
return - V_28 ;
}
static void T_2 F_24 ( void )
{
F_25 ( V_32 ) ;
if ( V_32 -> V_34 != V_35 )
F_26 ( V_22 , V_32 ) ;
F_21 ( V_32 ) ;
}
