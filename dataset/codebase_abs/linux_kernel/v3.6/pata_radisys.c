static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_6 - V_7 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_9 ) ;
T_1 V_11 ;
int V_12 = 0 ;
static const
T_2 V_13 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 1 } ,
{ 2 , 2 } ,
{ 3 , 3 } , } ;
if ( V_5 > 0 )
V_12 |= 1 ;
if ( F_3 ( V_4 ) )
V_12 |= 2 ;
F_4 ( V_9 , 0x40 , & V_11 ) ;
V_11 &= 0xCCCC ;
V_11 |= ( V_12 << ( 4 * V_4 -> V_14 ) ) ;
V_11 |= ( V_13 [ V_5 ] [ 0 ] << 12 ) |
( V_13 [ V_5 ] [ 1 ] << 8 ) ;
F_5 ( V_9 , 0x40 , V_11 ) ;
V_2 -> V_15 = V_4 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_9 ) ;
T_1 V_11 ;
T_2 V_16 ;
static const
T_2 V_13 [] [ 2 ] = { { 0 , 0 } ,
{ 0 , 0 } ,
{ 1 , 1 } ,
{ 2 , 2 } ,
{ 3 , 3 } , } ;
F_4 ( V_9 , 0x40 , & V_11 ) ;
F_7 ( V_9 , 0x48 , & V_16 ) ;
if ( V_4 -> V_17 < V_18 ) {
unsigned int V_19 = V_4 -> V_17 - V_20 ;
const unsigned int V_21 [ 3 ] = {
V_7 , V_22 , V_23
} ;
int V_5 = V_21 [ V_19 ] - V_7 ;
int V_12 = 3 ;
if ( V_4 -> V_6 < V_21 [ V_19 ] )
V_12 = 1 ;
V_11 &= 0xCCCC ;
V_11 |= V_12 << ( 4 * V_4 -> V_14 ) ;
V_11 |= ( V_13 [ V_5 ] [ 0 ] << 12 ) | ( V_13 [ V_5 ] [ 1 ] << 8 ) ;
V_16 &= ~ ( 1 << V_4 -> V_14 ) ;
} else {
T_2 V_24 ;
F_7 ( V_9 , 0x4A , & V_24 ) ;
if ( V_4 -> V_25 == V_26 )
V_24 &= ~ ( 2 << ( V_4 -> V_14 * 4 ) ) ;
else
V_24 |= ( 2 << ( V_4 -> V_14 * 4 ) ) ;
F_8 ( V_9 , 0x4A , V_24 ) ;
V_16 |= ( 1 << V_4 -> V_14 ) ;
}
F_5 ( V_9 , 0x40 , V_11 ) ;
F_8 ( V_9 , 0x48 , V_16 ) ;
V_2 -> V_15 = V_4 ;
}
static unsigned int F_9 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_3 * V_4 = V_28 -> V_9 ;
if ( V_4 != V_2 -> V_15 ) {
if ( V_4 -> V_17 < V_18 ) {
if ( V_4 -> V_17 )
F_6 ( V_2 , V_4 ) ;
else if ( V_4 -> V_6 )
F_1 ( V_2 , V_4 ) ;
}
}
return F_10 ( V_28 ) ;
}
static int F_11 ( struct V_8 * V_29 , const struct V_30 * V_31 )
{
static const struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = V_37 ,
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = & V_43 ,
} ;
const struct V_32 * V_44 [] = { & V_33 , NULL } ;
F_12 ( & V_29 -> V_9 , V_45 ) ;
return F_13 ( V_29 , V_44 , & V_46 , NULL , 0 ) ;
}
