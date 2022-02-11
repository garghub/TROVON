static inline int F_1 (
const struct V_1 * V_2 , int V_3 )
{
return ( ( V_3 * ( V_2 -> V_4 / 10 ) ) ) / 100 ;
}
static inline int F_2 (
const struct V_1 * V_2 , int V_5 )
{
int V_3 ;
V_3 = ( V_5 * 100 ) / ( V_2 -> V_4 / 10 ) ;
return ( V_3 < V_6 ) ? V_3 : V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
enum V_9 V_10 , T_1 * V_11 , int V_12 )
{
int V_13 ;
struct V_14 V_15 [ 2 ] = { } ;
T_1 V_16 = V_10 ;
V_15 [ 0 ] . V_17 = V_8 -> V_17 ;
V_15 [ 0 ] . V_18 = 1 ;
V_15 [ 0 ] . V_11 = & V_16 ;
V_15 [ 1 ] . V_17 = V_8 -> V_17 ;
V_15 [ 1 ] . V_18 = V_12 ;
V_15 [ 1 ] . V_11 = V_11 ;
V_15 [ 1 ] . V_19 = V_20 ;
V_13 = F_4 ( V_8 -> V_21 , & V_15 [ 0 ] , 2 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_8 -> V_22 , L_1 ) ;
return V_13 ;
}
F_6 ( & V_8 -> V_22 , L_2 ,
V_23 , V_10 , V_12 , * V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 ,
enum V_9 V_10 , const T_1 * V_11 , int V_12 )
{
int V_13 ;
T_1 V_16 = V_10 ;
V_13 = F_8 ( V_8 , V_16 , V_12 , V_11 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_8 -> V_22 , L_3 ) ;
return V_13 ;
}
F_6 ( & V_8 -> V_22 , L_2 ,
V_23 , V_10 , V_12 , * V_11 ) ;
return 0 ;
}
static int F_9 ( const struct V_1 * V_2 , int V_24 )
{
int V_13 ;
T_1 V_25 ;
T_1 V_26 ;
V_13 = F_3 ( V_2 -> V_8 , V_27 , & V_25 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_2 -> V_8 -> V_22 ,
L_4 ) ;
goto V_28;
}
V_26 = F_10 ( V_24 ) |
V_29 ;
switch ( V_2 -> V_30 ) {
case V_31 :
V_26 |= V_32 ;
break;
case V_33 :
case V_34 :
V_26 |= V_35 ;
break;
default:
break;
}
if ( V_25 != V_26 ) {
V_13 = F_7 ( V_2 -> V_8 ,
V_27 , & V_26 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_2 -> V_8 -> V_22 ,
L_5 ) ;
goto V_28;
}
}
return 0 ;
V_28:
return V_13 ;
}
static int F_11 ( const struct V_1 * V_2 )
{
int V_13 ;
T_1 V_36 [ 2 ] ;
V_13 = F_3 ( V_2 -> V_8 ,
V_37 , & V_36 [ 0 ] , 2 ) ;
if ( V_13 < 0 )
return V_13 ;
return ( V_36 [ 0 ] << 8 ) + V_36 [ 1 ] ;
}
static int F_12 ( const struct V_1 * V_2 , int * V_38 )
{
int V_25 = F_11 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_2 -> V_4 < 0 )
V_25 -= 0xFFFF ;
* V_38 = F_1 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_13 ( const struct V_1 * V_2 , int V_38 )
{
int V_13 ;
T_1 V_39 [ 2 ] ;
T_1 V_40 ;
T_2 V_25 ;
V_25 = F_2 ( V_2 , V_38 ) ;
if ( V_2 -> V_4 < 0 )
V_25 += 0xFFFF ;
if ( ( V_25 < 0 ) || ( V_25 > 0xFFFF ) )
return - V_41 ;
V_13 = F_3 ( V_2 -> V_8 ,
V_27 , & V_40 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_40 |= V_42 ;
V_13 = F_7 ( V_2 -> V_8 ,
V_27 , & V_40 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_39 [ 0 ] = F_14 ( V_25 ) ;
V_39 [ 1 ] = F_15 ( V_25 ) ;
V_13 = F_7 ( V_2 -> V_8 ,
V_37 , & V_39 [ 0 ] , 2 ) ;
if ( V_13 < 0 )
goto V_28;
V_28:
V_40 &= ~ V_42 ;
V_13 = F_7 ( V_2 -> V_8 ,
V_27 , & V_40 , 1 ) ;
return V_13 < 0 ? V_13 : 0 ;
}
static int F_16 (
const struct V_1 * V_2 , int * V_38 )
{
int V_25 = F_11 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 -= V_43 ;
* V_38 = F_1 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_17 ( const struct V_1 * V_2 , int * V_38 )
{
int V_13 ;
T_1 V_36 [ 2 ] ;
T_3 V_25 ;
V_13 = F_3 ( V_2 -> V_8 ,
V_44 , & V_36 [ 0 ] , 2 ) ;
V_25 = ( V_36 [ 0 ] << 8 ) | V_36 [ 1 ] ;
switch ( V_2 -> V_30 ) {
case V_33 :
V_25 *= 23600 * 2 ;
V_25 /= 0xFFFF ;
V_25 *= 1000 / 2 ;
break;
case V_34 :
V_25 *= 70800 / 5 * 4 ;
V_25 /= 0xFFFF ;
V_25 *= 1000 * 5 / 4 ;
break;
default:
V_25 *= 6000 * 10 ;
V_25 /= 0xFFFF ;
V_25 *= 1000 / 10 ;
break;
}
* V_38 = V_25 ;
return V_13 ;
}
static int F_18 ( const struct V_1 * V_2 , int * V_38 )
{
int V_13 ;
T_1 V_36 [ 2 ] ;
T_2 V_25 ;
V_13 = F_3 ( V_2 -> V_8 ,
V_45 , & V_36 [ 0 ] , 2 ) ;
V_25 = ( V_36 [ 0 ] << 8 ) | V_36 [ 1 ] ;
V_25 -= 0x7FFF ;
if ( V_2 -> V_30 == V_34 )
V_25 *= 64000 ;
else
V_25 *= 60000 ;
* V_38 = 1000 * ( V_25 / ( V_2 -> V_46 * 0x7FFF ) ) ;
return V_13 ;
}
static int F_19 ( const struct V_1 * V_2 , int * V_38 )
{
enum V_9 V_10 ;
int V_13 ;
T_1 V_36 [ 2 ] ;
T_3 V_25 ;
if ( V_2 -> V_30 == V_31 ) {
V_10 = V_47 ;
V_25 = 60000 ;
} else {
V_10 = V_48 ;
V_25 = 51000 ;
}
V_13 = F_3 ( V_2 -> V_8 , V_10 , & V_36 [ 0 ] , 2 ) ;
V_25 *= ( V_36 [ 0 ] << 8 ) | V_36 [ 1 ] ;
* V_38 = V_25 / 0xFFFF - 27215 ;
return V_13 ;
}
static int F_20 ( struct V_49 * V_50 ,
enum V_51 V_52 ,
union V_53 * V_38 )
{
struct V_1 * V_2 = F_21 ( V_50 ) ;
switch ( V_52 ) {
case V_54 :
return F_12 ( V_2 , & V_38 -> V_55 ) ;
case V_56 :
return F_16 ( V_2 , & V_38 -> V_55 ) ;
case V_57 :
return F_17 ( V_2 , & V_38 -> V_55 ) ;
case V_58 :
return F_18 ( V_2 , & V_38 -> V_55 ) ;
case V_59 :
return F_19 ( V_2 , & V_38 -> V_55 ) ;
default:
return - V_41 ;
}
}
static int F_22 ( struct V_49 * V_50 ,
enum V_51 V_60 ,
const union V_53 * V_38 )
{
struct V_1 * V_2 = F_21 ( V_50 ) ;
switch ( V_60 ) {
case V_54 :
return F_13 ( V_2 , V_38 -> V_55 ) ;
default:
return - V_61 ;
}
}
static int F_23 (
struct V_49 * V_50 , enum V_51 V_60 )
{
switch ( V_60 ) {
case V_54 :
return 1 ;
default:
return 0 ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
int V_62 = F_11 ( V_2 ) ;
if ( V_62 != V_2 -> V_62 ) {
V_2 -> V_62 = V_62 ;
F_25 ( V_2 -> V_63 ) ;
}
}
static void F_26 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
V_2 = F_27 ( V_65 , struct V_1 , V_65 . V_65 ) ;
F_24 ( V_2 ) ;
F_28 ( & V_2 -> V_65 , V_66 * V_67 ) ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_30 ( V_8 ) ;
F_31 ( & V_2 -> V_65 ) ;
F_32 ( V_2 -> V_63 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 ,
const struct V_68 * V_30 )
{
struct V_69 V_70 = {} ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
int V_13 ;
T_3 V_24 ;
T_2 V_46 ;
T_1 V_73 ;
V_2 = F_34 ( & V_8 -> V_22 , sizeof( * V_2 ) , V_74 ) ;
if ( V_2 == NULL )
return - V_75 ;
F_35 ( V_8 , V_2 ) ;
V_72 = F_36 ( V_8 -> V_22 . V_76 ) ;
V_2 -> V_30 = (enum V_77 ) F_37 ( & V_8 -> V_22 ) ;
V_2 -> V_78 . V_79 = V_72 -> V_79 ;
V_13 = F_38 ( V_72 , L_6 , & V_46 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_8 -> V_22 ,
L_7 ) ;
return V_13 ;
}
V_2 -> V_46 = V_46 ;
V_13 = F_38 ( V_72 , L_8 ,
& V_24 ) ;
if ( V_13 < 0 ) {
F_39 ( & V_8 -> V_22 ,
L_9 ) ;
V_24 = V_80 ;
}
if ( V_2 -> V_30 == V_33 ) {
if ( V_24 > V_81 )
V_24 = V_81 ;
V_2 -> V_4 = ( ( 340 * 50000 ) / V_46 ) /
( 4096 / ( 1 << ( 2 * V_24 ) ) ) ;
} else {
if ( V_24 > V_80 )
V_24 = V_80 ;
V_2 -> V_4 = ( ( 85 * 50000 ) / V_46 ) /
( 128 / ( 1 << V_24 ) ) ;
}
if ( V_2 -> V_30 == V_82 || V_2 -> V_30 == V_31 ) {
V_13 = F_3 ( V_8 , V_83 , & V_73 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_8 -> V_22 ,
L_10 ) ;
return V_13 ;
}
if ( V_73 & V_84 )
V_2 -> V_30 = V_82 ;
else
V_2 -> V_30 = V_31 ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_78 . type = V_85 ;
V_2 -> V_78 . V_86 = V_87 ;
switch ( V_2 -> V_30 ) {
case V_34 :
case V_33 :
V_2 -> V_78 . V_88 =
F_40 ( V_87 ) ;
break;
case V_31 :
V_2 -> V_78 . V_88 =
F_40 ( V_87 ) - 1 ;
break;
case V_82 :
default:
V_2 -> V_78 . V_88 =
F_40 ( V_87 ) - 3 ;
break;
}
V_2 -> V_78 . V_89 = F_20 ;
V_2 -> V_78 . V_90 = F_22 ;
V_2 -> V_78 . V_91 = F_23 ;
V_2 -> V_78 . V_92 = NULL ;
V_70 . V_93 = V_2 ;
F_41 ( & V_2 -> V_65 , F_26 ) ;
V_13 = F_9 ( V_2 , V_24 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_8 -> V_22 , L_11 ) ;
return V_13 ;
}
V_2 -> V_63 = F_42 ( & V_8 -> V_22 , & V_2 -> V_78 ,
& V_70 ) ;
if ( F_43 ( V_2 -> V_63 ) ) {
F_5 ( & V_8 -> V_22 , L_12 ) ;
return F_44 ( V_2 -> V_63 ) ;
} else {
F_28 ( & V_2 -> V_65 , V_66 * V_67 ) ;
}
return 0 ;
}
static int F_45 ( struct V_94 * V_22 )
{
struct V_7 * V_8 = F_46 ( V_22 ) ;
struct V_1 * V_2 = F_30 ( V_8 ) ;
F_31 ( & V_2 -> V_65 ) ;
return 0 ;
}
static int F_47 ( struct V_94 * V_22 )
{
struct V_7 * V_8 = F_46 ( V_22 ) ;
struct V_1 * V_2 = F_30 ( V_8 ) ;
F_28 ( & V_2 -> V_65 , V_66 * V_67 ) ;
return 0 ;
}
