static struct V_1 * F_1 ( void )
{
struct V_2 * V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
return V_3 ? & V_3 -> V_5 : NULL ;
}
static void F_3 ( struct V_2 * V_3 , int V_6 , ... )
{
unsigned char V_7 , V_8 ;
T_1 args ;
va_start ( args , V_6 ) ;
V_9 ;
V_10 ;
V_11 ;
V_12 ;
V_13 ;
V_11 ;
for (; V_6 ; V_6 -- ) {
V_7 = va_arg ( args , unsigned ) ;
for ( V_8 = 0x80 ; V_8 ; V_8 >>= 1 ) {
if ( V_7 & V_8 )
V_9 ;
else
V_12 ;
V_10 ;
V_11 ;
V_13 ;
V_11 ;
}
V_9 ;
V_10 ;
V_11 ;
V_13 ;
V_11 ;
}
V_12 ;
V_11 ;
V_10 ;
V_11 ;
V_9 ;
V_11 ;
va_end ( args ) ;
}
static int F_4 ( struct V_1 * V_5 , bool V_14 , int V_15 )
{
struct V_2 * V_3 = F_5 ( V_5 , struct V_2 , V_5 ) ;
V_3 -> V_16 = ( V_3 -> V_16 & 0xf7 ) | ( V_14 << 3 ) ;
F_6 ( V_3 -> V_16 , V_5 -> V_17 ) ;
F_3 ( V_3 , 2 , V_18 , V_15 ^ 0x1f ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_5 , bool V_19 )
{
struct V_2 * V_3 = F_5 ( V_5 , struct V_2 , V_5 ) ;
V_3 -> V_16 = ( V_3 -> V_16 & 0xfb ) | ( ! V_19 << 2 ) ;
F_6 ( V_3 -> V_16 , V_5 -> V_17 ) ;
return 0 ;
}
static T_2 F_8 ( struct V_1 * V_5 )
{
int V_20 , V_21 ;
for ( V_20 = 0 , V_21 = 0 ; V_20 < 100 ; V_20 ++ )
V_21 |= F_9 ( V_5 -> V_17 ) ;
return ( V_21 & 1 ) ? 0 : 0xffff ;
}
static int F_10 ( struct V_1 * V_5 , T_2 V_22 )
{
struct V_2 * V_3 = F_5 ( V_5 , struct V_2 , V_5 ) ;
V_22 /= 160 ;
V_22 += 1070 ;
F_3 ( V_3 , 5 , V_23 , ( V_22 << 1 ) | 1 ,
V_22 >> 7 , 0x60 | ( ( V_22 >> 15 ) & 1 ) , 0 ) ;
return 0 ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_5 =
F_5 ( V_25 -> V_26 , struct V_1 , V_27 ) ;
struct V_2 * V_3 = F_5 ( V_5 , struct V_2 , V_5 ) ;
switch ( V_25 -> V_28 ) {
case V_29 :
F_3 ( V_3 , 2 , V_18 , 0x60 | V_30 [ V_25 -> V_7 ] ) ;
return 0 ;
case V_31 :
F_3 ( V_3 , 2 , V_18 , 0x70 | V_30 [ V_25 -> V_7 ] ) ;
return 0 ;
}
return - V_32 ;
}
static int F_12 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_5 ( V_5 , struct V_2 , V_5 ) ;
V_3 -> V_16 = 0xf ;
F_3 ( V_3 , 2 , V_18 , 0x80 ) ;
F_3 ( V_3 , 2 , V_18 , 0xa0 ) ;
F_3 ( V_3 , 2 , V_18 , 0xc0 ) ;
F_3 ( V_3 , 2 , V_18 , 0xe0 ) ;
F_3 ( V_3 , 2 , V_18 , 0x40 ) ;
F_13 ( & V_5 -> V_27 , & V_33 ,
V_29 , 0 , 15 , 1 , 8 ) ;
F_13 ( & V_5 -> V_27 , & V_33 ,
V_31 , 0 , 15 , 1 , 8 ) ;
return V_5 -> V_27 . error ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_34 . V_35 , V_36 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_34 . V_35 ) ;
}
