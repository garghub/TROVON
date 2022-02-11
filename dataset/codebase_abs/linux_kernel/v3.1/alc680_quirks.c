static T_1 F_1 ( struct V_1 * V_2 )
{
static T_1 V_3 [] = { 0x18 , 0x19 } ;
static T_1 V_4 [] = { 0x08 , 0x09 } ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_3 ) ; V_5 ++ ) {
if ( ! F_3 ( V_2 , V_3 [ V_5 ] ) )
continue;
if ( F_4 ( V_2 , V_3 [ V_5 ] ) )
return V_4 [ V_5 ] ;
}
return 0x07 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 = F_1 ( V_2 ) ;
if ( V_7 -> V_9 && V_8 != V_7 -> V_9 ) {
F_6 ( V_2 , V_7 -> V_9 , 1 ) ;
V_7 -> V_9 = V_8 ;
F_7 ( V_2 , V_8 ,
V_7 -> V_10 , 0 ,
V_7 -> V_11 ) ;
}
}
static int F_8 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
unsigned int V_14 ,
unsigned int V_15 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_8 = F_1 ( V_2 ) ;
V_7 -> V_9 = V_8 ;
V_7 -> V_10 = V_14 ;
V_7 -> V_11 = V_15 ;
F_7 ( V_2 , V_8 , V_14 , 0 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_10 ( V_2 , V_7 -> V_9 ) ;
V_7 -> V_9 = 0 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_7 -> V_18 . V_19 [ 0 ] = 0x16 ;
V_7 -> V_18 . V_20 [ 0 ] = 0x14 ;
V_7 -> V_18 . V_20 [ 1 ] = 0x15 ;
V_7 -> V_18 . V_21 = 2 ;
V_7 -> V_18 . V_22 [ 0 ] . V_23 = 0x18 ;
V_7 -> V_18 . V_22 [ 0 ] . type = V_24 ;
V_7 -> V_18 . V_22 [ 1 ] . V_23 = 0x19 ;
V_7 -> V_18 . V_22 [ 1 ] . type = V_25 ;
V_7 -> V_26 = 1 ;
V_7 -> V_27 = V_28 ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
if ( ( V_29 >> 26 ) == V_30 )
F_13 ( V_2 ) ;
if ( ( V_29 >> 26 ) == V_31 )
F_5 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_5 ( V_2 ) ;
}
