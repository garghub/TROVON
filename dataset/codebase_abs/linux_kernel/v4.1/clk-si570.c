static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 , unsigned int * V_5 )
{
int V_6 ;
T_2 V_7 [ 6 ] ;
T_1 V_8 ;
V_6 = F_2 ( V_2 -> V_9 , V_10 + V_2 -> V_11 ,
V_7 , F_3 ( V_7 ) ) ;
if ( V_6 )
return V_6 ;
* V_5 = ( ( V_7 [ 0 ] & V_12 ) >> V_13 ) + V_14 ;
* V_4 = ( ( V_7 [ 0 ] & V_15 ) << 2 ) + ( ( V_7 [ 1 ] & V_16 ) >> 6 ) + 1 ;
if ( * V_4 > 1 )
* V_4 &= ~ 1 ;
V_8 = V_7 [ 1 ] & V_17 ;
V_8 = ( V_8 << 8 ) + V_7 [ 2 ] ;
V_8 = ( V_8 << 8 ) + V_7 [ 3 ] ;
V_8 = ( V_8 << 8 ) + V_7 [ 4 ] ;
V_8 = ( V_8 << 8 ) + V_7 [ 5 ] ;
* V_3 = V_8 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_18 )
{
int V_6 ;
T_1 V_19 ;
F_5 ( V_2 -> V_9 , V_20 , V_21 ) ;
V_6 = F_1 ( V_2 , & V_2 -> V_3 , & V_2 -> V_4 , & V_2 -> V_5 ) ;
if ( V_6 )
return V_6 ;
V_19 = V_18 * V_2 -> V_4 * V_2 -> V_5 ;
if ( V_19 >= ( 1LL << 36 ) )
V_2 -> V_22 = F_6 ( V_19 << 24 , V_2 -> V_3 >> 4 ) ;
else
V_2 -> V_22 = F_6 ( V_19 << 28 , V_2 -> V_3 ) ;
V_2 -> V_23 = V_18 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_2 V_7 [ 5 ] ;
V_7 [ 0 ] = ( ( V_2 -> V_4 - 1 ) << 6 ) |
( ( V_2 -> V_3 >> 32 ) & V_17 ) ;
V_7 [ 1 ] = ( V_2 -> V_3 >> 24 ) & 0xff ;
V_7 [ 2 ] = ( V_2 -> V_3 >> 16 ) & 0xff ;
V_7 [ 3 ] = ( V_2 -> V_3 >> 8 ) & 0xff ;
V_7 [ 4 ] = V_2 -> V_3 & 0xff ;
return F_8 ( V_2 -> V_9 , V_24 +
V_2 -> V_11 , V_7 , F_3 ( V_7 ) ) ;
}
static int F_9 ( unsigned long V_23 , struct V_1 * V_2 ,
T_1 * V_25 , unsigned int * V_26 , unsigned int * V_27 )
{
int V_28 ;
unsigned int V_4 , V_5 ;
T_1 V_19 , V_29 = V_30 ;
static const T_3 V_31 [] = { 11 , 9 , 7 , 6 , 5 , 4 } ;
for ( V_28 = 0 ; V_28 < F_3 ( V_31 ) ; V_28 ++ ) {
V_5 = V_31 [ V_28 ] ;
V_4 = F_10 ( F_10 ( V_32 , V_5 ) , V_23 ) ;
if ( ! V_4 || ( V_4 & 1 ) )
V_4 ++ ;
while ( V_4 <= 128 ) {
V_19 = ( T_1 ) V_23 * ( T_1 ) V_5 * ( T_1 ) V_4 ;
if ( V_19 > V_33 )
break;
if ( V_19 >= V_32 && V_19 < V_29 ) {
* V_26 = V_4 ;
* V_27 = V_5 ;
* V_25 = F_6 ( V_19 << 28 , V_2 -> V_22 ) ;
V_29 = V_19 ;
}
V_4 += ( V_4 == 1 ? 1 : 2 ) ;
}
}
if ( V_29 == V_30 )
return - V_34 ;
return 0 ;
}
static unsigned long F_11 ( struct V_35 * V_36 ,
unsigned long V_37 )
{
int V_6 ;
T_1 V_3 , V_38 ;
unsigned int V_4 , V_5 ;
struct V_1 * V_2 = F_12 ( V_36 ) ;
V_6 = F_1 ( V_2 , & V_3 , & V_4 , & V_5 ) ;
if ( V_6 ) {
F_13 ( & V_2 -> V_39 -> V_40 , L_1 ) ;
return V_2 -> V_23 ;
}
V_3 = F_10 ( V_3 , V_5 * V_4 ) ;
V_38 = ( V_2 -> V_22 * V_3 ) >> 28 ;
return V_38 ;
}
static long F_14 ( struct V_35 * V_36 , unsigned long V_38 ,
unsigned long * V_37 )
{
int V_6 ;
T_1 V_3 ;
unsigned int V_4 , V_5 ;
struct V_1 * V_2 = F_12 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
if ( F_6 ( abs ( V_38 - V_2 -> V_23 ) * 10000LL ,
V_2 -> V_23 ) < 35 ) {
V_3 = F_6 ( ( V_2 -> V_3 * V_38 ) +
F_6 ( V_2 -> V_23 , 2 ) , V_2 -> V_23 ) ;
V_4 = V_2 -> V_4 ;
V_5 = V_2 -> V_5 ;
} else {
V_6 = F_9 ( V_38 , V_2 , & V_3 , & V_4 , & V_5 ) ;
if ( V_6 ) {
F_13 ( & V_2 -> V_39 -> V_40 ,
L_2 ) ;
return 0 ;
}
}
return V_38 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_23 )
{
int V_6 ;
V_6 = F_9 ( V_23 , V_2 , & V_2 -> V_3 , & V_2 -> V_4 ,
& V_2 -> V_5 ) ;
if ( V_6 )
return V_6 ;
F_5 ( V_2 -> V_9 , V_41 , V_42 ) ;
F_5 ( V_2 -> V_9 , V_10 + V_2 -> V_11 ,
( ( V_2 -> V_5 - V_14 ) << V_13 ) |
( ( ( V_2 -> V_4 - 1 ) >> 2 ) & V_15 ) ) ;
F_7 ( V_2 ) ;
F_5 ( V_2 -> V_9 , V_41 , 0 ) ;
F_5 ( V_2 -> V_9 , V_20 , V_43 ) ;
F_16 ( 10000 , 12000 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned long V_23 )
{
V_2 -> V_3 = F_6 ( ( V_2 -> V_3 * V_23 ) +
F_10 ( V_2 -> V_23 , 2 ) , V_2 -> V_23 ) ;
F_5 ( V_2 -> V_9 , V_20 , V_44 ) ;
F_7 ( V_2 ) ;
F_5 ( V_2 -> V_9 , V_20 , 0 ) ;
F_16 ( 100 , 200 ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_36 , unsigned long V_38 ,
unsigned long V_37 )
{
struct V_1 * V_2 = F_12 ( V_36 ) ;
struct V_39 * V_45 = V_2 -> V_39 ;
int V_6 ;
if ( V_38 < V_46 || V_38 > V_2 -> V_47 ) {
F_13 ( & V_45 -> V_40 ,
L_3 , V_38 ) ;
return - V_34 ;
}
if ( F_6 ( abs ( V_38 - V_2 -> V_23 ) * 10000LL ,
V_2 -> V_23 ) < 35 )
V_6 = F_17 ( V_2 , V_38 ) ;
else
V_6 = F_15 ( V_2 , V_38 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_23 = V_38 ;
return 0 ;
}
static bool F_19 ( struct V_48 * V_40 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_20 :
return true ;
default:
return false ;
}
}
static bool F_20 ( struct V_48 * V_40 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_10 ... ( V_49 + V_50 ) :
case V_20 :
case V_41 :
return true ;
default:
return false ;
}
}
static int F_21 ( struct V_39 * V_45 ,
const struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_53 V_54 ;
struct V_55 * V_55 ;
T_4 V_56 , V_57 , V_58 ;
int V_6 ;
enum V_59 V_60 = V_52 -> V_61 ;
V_2 = F_22 ( & V_45 -> V_40 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_54 . V_64 = & V_65 ;
V_54 . V_66 = V_67 ;
V_54 . V_68 = 0 ;
V_2 -> V_36 . V_54 = & V_54 ;
V_2 -> V_39 = V_45 ;
if ( V_60 == V_69 ) {
V_6 = F_23 ( V_45 -> V_40 . V_70 ,
L_4 , & V_58 ) ;
if ( V_6 ) {
F_13 ( & V_45 -> V_40 ,
L_5 ) ;
return V_6 ;
}
if ( V_58 == 7 )
V_2 -> V_11 = V_50 ;
V_2 -> V_47 = V_71 ;
} else {
V_2 -> V_47 = V_72 ;
}
if ( F_24 ( V_45 -> V_40 . V_70 , L_6 ,
& V_54 . V_73 ) )
V_54 . V_73 = V_45 -> V_40 . V_70 -> V_73 ;
V_6 = F_23 ( V_45 -> V_40 . V_70 , L_7 ,
& V_57 ) ;
if ( V_6 ) {
F_13 ( & V_45 -> V_40 , L_8 ) ;
return V_6 ;
}
V_2 -> V_9 = F_25 ( V_45 , & V_74 ) ;
if ( F_26 ( V_2 -> V_9 ) ) {
F_13 ( & V_45 -> V_40 , L_9 ) ;
return F_27 ( V_2 -> V_9 ) ;
}
F_28 ( V_45 , V_2 ) ;
V_6 = F_4 ( V_2 , V_57 ) ;
if ( V_6 )
return V_6 ;
V_55 = F_29 ( & V_45 -> V_40 , & V_2 -> V_36 ) ;
if ( F_26 ( V_55 ) ) {
F_13 ( & V_45 -> V_40 , L_10 ) ;
return F_27 ( V_55 ) ;
}
V_6 = F_30 ( V_45 -> V_40 . V_70 , V_75 ,
V_55 ) ;
if ( V_6 ) {
F_13 ( & V_45 -> V_40 , L_11 ) ;
return V_6 ;
}
if ( ! F_23 ( V_45 -> V_40 . V_70 , L_12 ,
& V_56 ) ) {
V_6 = F_31 ( V_55 , V_56 ) ;
if ( V_6 ) {
F_32 ( V_45 -> V_40 . V_70 ) ;
return V_6 ;
}
}
F_33 ( & V_45 -> V_40 , L_13 ,
V_2 -> V_23 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_45 )
{
F_32 ( V_45 -> V_40 . V_70 ) ;
return 0 ;
}
