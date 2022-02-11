static int F_1 ( void )
{
T_1 V_1 = F_2 ( 0x903C ) ;
T_1 V_2 = F_2 ( 0x903D ) ;
T_2 V_3 ;
if ( V_1 == 0x04 && V_2 < V_4 )
return 0 ;
V_3 = F_3 ( 0x901E ) ;
V_3 >>= 8 ;
V_3 &= 0x03 ;
if ( V_3 == 3 )
V_3 = 0 ;
return V_3 ;
}
static void F_4 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
static const T_3 V_9 [ 4 ] [ 5 ] = {
{ 0x00009172 , 0x00012171 , 0x00020080 , 0x00032010 , 0x00040010 } ,
{ 0xd1329172 , 0x71212171 , 0x30200080 , 0x20102010 , 0x00100010 } ,
{ 0xfaa3f4f3 , 0xc23232b2 , 0x513101c1 , 0x31213121 , 0x10211021 } ,
{ 0xfff4fff4 , 0xf35353d3 , 0x814102f1 , 0x42314231 , 0x11311131 }
} ;
struct V_10 * V_11 = F_5 ( V_6 -> V_12 -> V_13 ) ;
T_3 V_14 ;
unsigned int V_15 = 0x40 + 0x10 * V_6 -> V_16 ;
int V_17 = V_8 -> V_18 - V_19 ;
F_6 ( V_11 , V_15 + 4 , & V_14 ) ;
V_14 >>= 31 ;
V_14 += F_1 () ;
F_7 ( V_11 , V_15 + 8 * V_8 -> V_20 ,
V_9 [ V_14 ] [ V_17 ] ) ;
}
static void F_8 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
static const T_3 V_21 [ 3 ] [ 3 ] = {
{ 0x00921250 , 0x00911140 , 0x00911030 } ,
{ 0x00932470 , 0x00922260 , 0x00922140 } ,
{ 0x009436A1 , 0x00933481 , 0x00923261 }
} ;
static const T_3 V_22 [ 3 ] [ 3 ] = {
{ 0x00077771 , 0x00012121 , 0x00002020 } ,
{ 0x000BBBB2 , 0x00024241 , 0x00013131 } ,
{ 0x000FFFF3 , 0x00035352 , 0x00015151 }
} ;
int clock = F_1 () ;
struct V_10 * V_11 = F_5 ( V_6 -> V_12 -> V_13 ) ;
unsigned int V_15 = 0x40 + 0x10 * V_6 -> V_16 ;
int V_17 = V_8 -> V_23 ;
T_3 V_14 ;
if ( V_17 >= V_24 )
V_14 = V_21 [ clock ] [ V_17 - V_24 ] ;
else
V_14 = V_22 [ clock ] [ V_17 - V_25 ] ;
if ( V_8 -> V_20 == 0 ) {
T_3 V_26 ;
F_6 ( V_11 , V_15 + 4 , & V_26 ) ;
V_26 &= 0x80000000UL ;
V_26 |= V_14 ;
F_7 ( V_11 , V_15 + 4 , V_26 ) ;
} else
F_7 ( V_11 , V_15 + 12 , V_14 ) ;
}
static unsigned int F_9 ( struct V_27 * V_28 )
{
struct V_5 * V_6 = V_28 -> V_6 ;
struct V_7 * V_8 = V_28 -> V_13 ;
struct V_7 * V_29 = V_6 -> V_30 ;
if ( F_10 ( V_8 ) && V_8 != V_29 && V_29 != NULL ) {
if ( ( F_11 ( V_8 ) && ! F_11 ( V_29 ) ) ||
( F_11 ( V_29 ) && ! F_11 ( V_8 ) ) )
F_8 ( V_6 , V_8 ) ;
}
return F_12 ( V_28 ) ;
}
static int F_13 ( struct V_27 * V_28 )
{
struct V_31 * V_12 = V_28 -> V_6 -> V_12 ;
struct V_5 * V_32 = V_12 -> V_33 [ 1 ^ V_28 -> V_6 -> V_16 ] ;
int V_34 ;
V_34 = F_14 ( V_28 ) ;
if ( V_34 != 0 )
return V_34 ;
if ( V_32 && V_32 -> V_35 )
return V_36 ;
return 0 ;
}
static int F_15 ( struct V_10 * V_13 , const struct V_37 * V_38 )
{
static const struct V_39 V_40 = {
. V_41 = V_42 ,
. V_43 = V_44 ,
. V_45 = V_46 ,
. V_47 = V_48 ,
. V_49 = & V_50
} ;
const struct V_39 * V_51 [] = { & V_40 , NULL } ;
return F_16 ( V_13 , V_51 , & V_52 , NULL , 0 ) ;
}
