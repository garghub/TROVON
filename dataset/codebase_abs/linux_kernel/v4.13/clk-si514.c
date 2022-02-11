static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
return F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_3 ? V_6 : 0 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_9 ;
T_1 V_10 [ 7 ] ;
V_9 = F_4 ( V_2 -> V_4 , V_11 ,
V_10 , F_5 ( V_10 ) ) ;
if ( V_9 )
return V_9 ;
V_8 -> V_12 = V_10 [ 0 ] | V_10 [ 1 ] << 8 | V_10 [ 2 ] << 16 |
( V_10 [ 3 ] & 0x1F ) << 24 ;
V_8 -> V_13 = ( V_10 [ 4 ] & 0x3f ) << 3 | V_10 [ 3 ] >> 5 ;
V_8 -> V_14 = ( V_10 [ 6 ] >> 4 ) & 0x07 ;
V_8 -> V_15 = ( V_10 [ 6 ] & 0x03 ) << 8 | V_10 [ 5 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_16 ;
T_1 V_10 [ 7 ] ;
int V_9 ;
if ( V_8 -> V_13 < 65 ||
( V_8 -> V_13 == 65 && V_8 -> V_12 <= 139575831 ) )
V_16 = 0x22 ;
else if ( V_8 -> V_13 < 67 ||
( V_8 -> V_13 == 67 && V_8 -> V_12 <= 461581994 ) )
V_16 = 0x23 ;
else if ( V_8 -> V_13 < 72 ||
( V_8 -> V_13 == 72 && V_8 -> V_12 <= 503383578 ) )
V_16 = 0x33 ;
else if ( V_8 -> V_13 < 75 ||
( V_8 -> V_13 == 75 && V_8 -> V_12 <= 452724474 ) )
V_16 = 0x34 ;
else
V_16 = 0x44 ;
V_9 = F_7 ( V_2 -> V_4 , V_17 , V_16 ) ;
if ( V_9 < 0 )
return V_9 ;
V_10 [ 0 ] = V_8 -> V_12 ;
V_10 [ 1 ] = V_8 -> V_12 >> 8 ;
V_10 [ 2 ] = V_8 -> V_12 >> 16 ;
V_10 [ 3 ] = V_8 -> V_12 >> 24 | V_8 -> V_13 << 5 ;
V_10 [ 4 ] = V_8 -> V_13 >> 3 ;
V_10 [ 5 ] = V_8 -> V_15 ;
V_10 [ 6 ] = ( V_8 -> V_15 >> 8 ) | ( V_8 -> V_14 << 4 ) ;
V_9 = F_8 ( V_2 -> V_4 , V_18 , V_10 + 5 , 2 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_8 ( V_2 -> V_4 , V_11 , V_10 , 5 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
unsigned long V_19 )
{
T_2 V_20 ;
T_3 V_21 ;
T_3 V_22 ;
T_1 V_23 ;
if ( ( V_19 < V_24 ) || ( V_19 > V_25 ) )
return - V_26 ;
V_21 = V_19 ;
if ( V_19 >= ( V_27 / V_28 ) )
V_8 -> V_14 = 0 ;
else {
V_23 = 1 ;
V_22 = 2 * V_28 ;
while ( V_22 <= ( V_28 * 32 ) ) {
if ( ( V_19 * V_22 ) >= V_27 )
break;
++ V_23 ;
V_22 <<= 1 ;
}
V_8 -> V_14 = V_23 ;
V_21 = V_19 << V_23 ;
}
V_8 -> V_15 = F_10 ( V_27 >> 1 , V_21 ) << 1 ;
V_20 = ( ( T_2 ) ( V_21 * V_8 -> V_15 ) << 29 ) + ( V_29 / 2 ) ;
F_11 ( V_20 , V_29 ) ;
V_8 -> V_12 = ( T_3 ) V_20 & ( F_12 ( 29 ) - 1 ) ;
V_8 -> V_13 = ( T_3 ) ( V_20 >> 29 ) ;
return 0 ;
}
static unsigned long F_13 ( struct V_7 * V_8 )
{
T_2 V_20 = V_8 -> V_12 | ( ( T_2 ) V_8 -> V_13 << 29 ) ;
T_3 V_30 = V_8 -> V_15 * F_12 ( V_8 -> V_14 ) ;
return ( ( T_3 ) ( ( ( V_20 * V_29 ) + ( V_29 / 2 ) ) >> 29 ) ) / V_30 ;
}
static unsigned long F_14 ( struct V_31 * V_32 ,
unsigned long V_33 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
struct V_7 V_8 ;
int V_9 ;
V_9 = F_3 ( V_2 , & V_8 ) ;
if ( V_9 ) {
F_16 ( & V_2 -> V_34 -> V_35 , L_1 ) ;
return 0 ;
}
return F_13 ( & V_8 ) ;
}
static long F_17 ( struct V_31 * V_32 , unsigned long V_36 ,
unsigned long * V_33 )
{
struct V_7 V_8 ;
int V_9 ;
if ( ! V_36 )
return 0 ;
V_9 = F_9 ( & V_8 , V_36 ) ;
if ( V_9 )
return V_9 ;
return F_13 ( & V_8 ) ;
}
static int F_18 ( struct V_31 * V_32 , unsigned long V_36 ,
unsigned long V_33 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
struct V_7 V_8 ;
int V_9 ;
V_9 = F_9 ( & V_8 , V_36 ) ;
if ( V_9 )
return V_9 ;
F_1 ( V_2 , false ) ;
V_9 = F_6 ( V_2 , & V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_7 ( V_2 -> V_4 , V_5 , V_37 ) ;
if ( V_9 < 0 )
return V_9 ;
F_19 ( 10000 , 12000 ) ;
F_1 ( V_2 , true ) ;
return V_9 ;
}
static bool F_20 ( struct V_38 * V_35 , unsigned int V_10 )
{
switch ( V_10 ) {
case V_5 :
case V_39 :
return true ;
default:
return false ;
}
}
static bool F_21 ( struct V_38 * V_35 , unsigned int V_10 )
{
switch ( V_10 ) {
case V_17 :
case V_11 ... V_40 :
case V_41 :
case V_39 :
case V_5 :
return true ;
default:
return false ;
}
}
static int F_22 ( struct V_34 * V_42 ,
const struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_45 V_46 ;
int V_9 ;
V_2 = F_23 ( & V_42 -> V_35 , sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_46 . V_49 = & V_50 ;
V_46 . V_51 = 0 ;
V_46 . V_52 = 0 ;
V_2 -> V_32 . V_46 = & V_46 ;
V_2 -> V_34 = V_42 ;
if ( F_24 ( V_42 -> V_35 . V_53 , L_2 ,
& V_46 . V_54 ) )
V_46 . V_54 = V_42 -> V_35 . V_53 -> V_54 ;
V_2 -> V_4 = F_25 ( V_42 , & V_55 ) ;
if ( F_26 ( V_2 -> V_4 ) ) {
F_16 ( & V_42 -> V_35 , L_3 ) ;
return F_27 ( V_2 -> V_4 ) ;
}
F_28 ( V_42 , V_2 ) ;
V_9 = F_29 ( & V_42 -> V_35 , & V_2 -> V_32 ) ;
if ( V_9 ) {
F_16 ( & V_42 -> V_35 , L_4 ) ;
return V_9 ;
}
V_9 = F_30 ( V_42 -> V_35 . V_53 , V_56 ,
& V_2 -> V_32 ) ;
if ( V_9 ) {
F_16 ( & V_42 -> V_35 , L_5 ) ;
return V_9 ;
}
return 0 ;
}
static int F_31 ( struct V_34 * V_42 )
{
F_32 ( V_42 -> V_35 . V_53 ) ;
return 0 ;
}
