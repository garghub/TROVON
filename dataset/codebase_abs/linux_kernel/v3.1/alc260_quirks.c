static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
* V_6 -> V_9 . integer . V_9 = ! V_8 -> V_10 ;
return 0 ;
}
static int F_5 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
int V_11 = ! * V_6 -> V_9 . integer . V_9 ;
if ( V_11 == V_8 -> V_10 )
return 0 ;
V_8 -> V_10 = V_11 ;
F_1 ( V_2 ) ;
return 1 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
V_8 -> V_12 . V_13 [ 0 ] = 0x0f ;
V_8 -> V_12 . V_14 [ 0 ] = 0x10 ;
V_8 -> V_12 . V_14 [ 1 ] = 0x11 ;
V_8 -> V_15 = 1 ;
V_8 -> V_16 = V_17 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
V_8 -> V_12 . V_13 [ 0 ] = 0x15 ;
V_8 -> V_12 . V_14 [ 0 ] = 0x10 ;
V_8 -> V_12 . V_14 [ 1 ] = 0x11 ;
V_8 -> V_15 = 1 ;
V_8 -> V_16 = V_17 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
V_8 -> V_12 . V_13 [ 0 ] = 0x10 ;
V_8 -> V_12 . V_14 [ 0 ] = 0x0f ;
V_8 -> V_12 . V_14 [ 1 ] = 0x11 ;
V_8 -> V_12 . V_14 [ 2 ] = 0x15 ;
V_8 -> V_15 = 1 ;
V_8 -> V_16 = V_17 ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_18 ;
V_18 = F_10 ( V_2 , 0x0f ) ;
if ( V_18 ) {
F_11 ( V_2 , 0x01 , 0 ,
V_19 , 1 ) ;
F_11 ( V_2 , 0x0f , 0 ,
V_20 ,
V_21 ) ;
} else {
F_11 ( V_2 , 0x01 , 0 ,
V_19 , 0 ) ;
F_11 ( V_2 , 0x0f , 0 ,
V_20 ,
V_22 ) ;
}
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
if ( ( V_23 >> 26 ) == V_24 )
F_9 ( V_2 ) ;
}
