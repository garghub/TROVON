static void F_1 ( struct V_1 * V_1 ,
unsigned int V_2 , unsigned int V_3 )
{
int V_4 ;
unsigned int V_5 ;
V_5 = F_2 ( V_1 , V_6 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
if ( ! ( ( 1 << V_4 ) & V_2 ) )
continue;
V_5 &= ( ~ ( 3 << ( V_4 << 1 ) ) ) ;
V_5 |= ( ( V_3 & 3 ) << ( V_4 << 1 ) ) ;
}
F_3 ( V_1 , V_6 , V_5 ) ;
V_5 = F_2 ( V_1 , V_7 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
if ( ! ( ( 1 << ( V_4 + 16 ) ) & V_2 ) )
continue;
if ( ! V_3 )
V_5 &= ~ ( 1 << V_4 ) ;
else
V_5 |= 1 << V_4 ;
}
V_5 |= 0xffff0000 ;
F_3 ( V_1 , V_7 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_1 , unsigned int V_8 )
{
F_3 ( V_1 , V_9 ,
F_2 ( V_1 , V_9 ) | V_8 ) ;
}
static void F_5 ( struct V_1 * V_1 , unsigned int V_8 )
{
F_3 ( V_1 , V_9 ,
F_2 ( V_1 , V_9 ) & ~ V_8 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_1 ( V_1 , 0x30 , 1 ) ;
F_5 ( V_1 , 0x30 ) ;
F_7 ( 100 ) ;
F_4 ( V_1 , 0x30 ) ;
F_7 ( 100 ) ;
F_1 ( V_1 , 0x0f , 2 ) ;
F_1 ( V_1 , 0xff00 , 1 ) ;
F_5 ( V_1 , 0xff00 ) ;
F_1 ( V_1 , 0xffff0000 , 0 ) ;
}
static int F_8 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
int V_5 , V_3 ;
struct V_1 * V_1 = F_9 ( V_11 ) ;
if ( V_12 < 8 ) {
V_5 = F_2 ( V_1 , V_6 ) ;
V_3 = 3 & ( V_5 >> ( ( V_12 + 8 ) * 2 ) ) ;
} else {
V_5 = F_2 ( V_1 , V_7 ) ;
V_3 = 1 & ( V_5 >> ( V_12 - 8 ) ) ;
}
if ( ! V_3 )
return 1 ;
else if ( V_3 == 1 )
return 0 ;
return - 1 ;
}
static int F_10 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
return - 1 ;
}
static int F_11 ( struct V_10 * V_11 ,
unsigned int V_12 , int V_8 )
{
return - 1 ;
}
static int F_12 ( struct V_10 * V_11 ,
unsigned int V_12 )
{
int V_5 ;
struct V_1 * V_1 = F_9 ( V_11 ) ;
V_5 = F_2 ( V_1 , V_13 ) ;
return 1 & ( V_5 >> ( V_12 + 8 ) ) ;
}
static void F_13 ( struct V_10 * V_11 ,
unsigned int V_12 , int V_8 )
{
struct V_1 * V_1 = F_9 ( V_11 ) ;
if ( V_8 )
F_4 ( V_1 , 1 << ( V_12 + 8 ) ) ;
else
F_5 ( V_1 , 1 << ( V_12 + 8 ) ) ;
}
int F_14 ( struct V_1 * V_1 )
{
int V_5 ;
F_6 ( V_1 ) ;
#ifdef F_15
V_1 -> V_14 . V_15 = V_16 L_1 ;
V_1 -> V_14 . V_17 = & V_1 -> V_18 -> V_19 ;
V_1 -> V_14 . V_20 = V_21 ;
V_1 -> V_14 . V_22 = - 1 ;
V_1 -> V_14 . V_23 = 24 ;
V_1 -> V_14 . V_24 = 0 ;
V_1 -> V_14 . V_25 = F_8 ;
V_1 -> V_14 . V_26 = F_10 ;
V_1 -> V_14 . V_27 = F_11 ;
V_1 -> V_14 . V_28 = F_12 ;
V_1 -> V_14 . V_29 = F_13 ;
V_5 = F_16 ( & V_1 -> V_14 , V_1 ) ;
if ( V_5 ) {
V_1 -> V_14 . V_15 = NULL ;
return - 1 ;
}
#endif
return 0 ;
}
void F_17 ( struct V_1 * V_1 )
{
#ifdef F_15
if ( V_1 -> V_14 . V_15 ) {
F_18 ( & V_1 -> V_14 ) ;
V_1 -> V_14 . V_15 = NULL ;
}
#endif
F_5 ( V_1 , 0x30 ) ;
F_6 ( V_1 ) ;
}
