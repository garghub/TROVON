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
if ( V_2 -> V_12 == V_30 )
V_26 |= V_31 ;
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
T_1 V_32 [ 2 ] ;
V_13 = F_3 ( V_2 -> V_8 ,
V_33 , & V_32 [ 0 ] , 2 ) ;
if ( V_13 < 0 )
return V_13 ;
return ( V_32 [ 0 ] << 8 ) + V_32 [ 1 ] ;
}
static int F_12 ( const struct V_1 * V_2 , int * V_34 )
{
int V_25 = F_11 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_2 -> V_4 < 0 )
V_25 -= 0xFFFF ;
* V_34 = F_1 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_13 ( const struct V_1 * V_2 , int V_34 )
{
int V_13 ;
T_1 V_35 [ 2 ] ;
T_1 V_36 ;
T_2 V_25 ;
V_25 = F_2 ( V_2 , V_34 ) ;
if ( V_2 -> V_4 < 0 )
V_25 += 0xFFFF ;
if ( ( V_25 < 0 ) || ( V_25 > 0xFFFF ) )
return - V_37 ;
V_13 = F_3 ( V_2 -> V_8 ,
V_27 , & V_36 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_36 |= V_38 ;
V_13 = F_7 ( V_2 -> V_8 ,
V_27 , & V_36 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_35 [ 0 ] = F_14 ( V_25 ) ;
V_35 [ 1 ] = F_15 ( V_25 ) ;
V_13 = F_7 ( V_2 -> V_8 ,
V_33 , & V_35 [ 0 ] , 2 ) ;
if ( V_13 < 0 )
goto V_28;
V_28:
V_36 &= ~ V_38 ;
V_13 = F_7 ( V_2 -> V_8 ,
V_27 , & V_36 , 1 ) ;
return V_13 < 0 ? V_13 : 0 ;
}
static int F_16 (
const struct V_1 * V_2 , int * V_34 )
{
int V_25 = F_11 ( V_2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 -= V_39 ;
* V_34 = F_1 ( V_2 , V_25 ) ;
return 0 ;
}
static int F_17 ( const struct V_1 * V_2 , int * V_34 )
{
int V_13 ;
T_1 V_32 [ 2 ] ;
T_3 V_25 ;
V_13 = F_3 ( V_2 -> V_8 ,
V_40 , & V_32 [ 0 ] , 2 ) ;
V_25 = ( V_32 [ 0 ] << 8 ) | V_32 [ 1 ] ;
* V_34 = ( ( V_25 * 23600 ) / 0xFFFF ) * 1000 ;
return V_13 ;
}
static int F_18 ( const struct V_1 * V_2 , int * V_34 )
{
int V_13 ;
T_1 V_32 [ 2 ] ;
T_2 V_25 ;
V_13 = F_3 ( V_2 -> V_8 ,
V_41 , & V_32 [ 0 ] , 2 ) ;
V_25 = ( V_32 [ 0 ] << 8 ) | V_32 [ 1 ] ;
V_25 -= 0x7FFF ;
* V_34 = 1000 * ( ( 60000 * V_25 ) / ( V_2 -> V_42 * 0x7FFF ) ) ;
return V_13 ;
}
static int F_19 ( const struct V_1 * V_2 , int * V_34 )
{
int V_13 ;
T_1 V_32 [ 2 ] ;
T_3 V_25 ;
V_13 = F_3 ( V_2 -> V_8 ,
V_43 , & V_32 [ 0 ] , 2 ) ;
V_25 = ( V_32 [ 0 ] << 8 ) | V_32 [ 1 ] ;
* V_34 = ( ( ( 51000 * V_25 ) / 0xFFFF ) - 27215 ) ;
return V_13 ;
}
static int F_20 ( struct V_44 * V_45 ,
enum V_46 V_47 ,
union V_48 * V_34 )
{
struct V_1 * V_2 =
F_21 ( V_45 , struct V_1 , V_49 ) ;
switch ( V_47 ) {
case V_50 :
return F_12 ( V_2 , & V_34 -> V_51 ) ;
case V_52 :
return F_16 ( V_2 , & V_34 -> V_51 ) ;
case V_53 :
return F_17 ( V_2 , & V_34 -> V_51 ) ;
case V_54 :
return F_18 ( V_2 , & V_34 -> V_51 ) ;
case V_55 :
return F_19 ( V_2 , & V_34 -> V_51 ) ;
default:
return - V_37 ;
}
}
static int F_22 ( struct V_44 * V_45 ,
enum V_46 V_56 ,
const union V_48 * V_34 )
{
struct V_1 * V_2 =
F_21 ( V_45 , struct V_1 , V_49 ) ;
switch ( V_56 ) {
case V_50 :
return F_13 ( V_2 , V_34 -> V_51 ) ;
default:
return - V_57 ;
}
}
static int F_23 (
struct V_44 * V_45 , enum V_46 V_56 )
{
switch ( V_56 ) {
case V_50 :
return 1 ;
default:
return 0 ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
int V_58 = F_11 ( V_2 ) ;
if ( V_58 != V_2 -> V_58 ) {
V_2 -> V_58 = V_58 ;
F_25 ( & V_2 -> V_49 ) ;
}
}
static void F_26 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
V_2 = F_21 ( V_60 , struct V_1 , V_60 . V_60 ) ;
F_24 ( V_2 ) ;
F_27 ( & V_2 -> V_60 , V_61 * V_62 ) ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_29 ( V_8 ) ;
F_30 ( & V_2 -> V_60 ) ;
F_31 ( & V_2 -> V_49 ) ;
F_32 ( V_2 -> V_49 . V_63 ) ;
F_33 ( & V_64 ) ;
F_34 ( & V_65 , V_2 -> V_66 ) ;
F_35 ( & V_64 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 ,
const struct V_67 * V_66 )
{
struct V_1 * V_2 ;
int V_13 ;
int V_68 ;
T_3 V_24 ;
T_2 V_42 ;
struct V_69 * V_70 ;
F_33 ( & V_64 ) ;
V_13 = F_37 ( & V_65 , V_8 , 0 , 0 , V_71 ) ;
F_35 ( & V_64 ) ;
if ( V_13 < 0 )
goto V_72;
V_68 = V_13 ;
V_2 = F_38 ( & V_8 -> V_22 , sizeof( * V_2 ) , V_71 ) ;
if ( V_2 == NULL ) {
V_13 = - V_73 ;
goto V_74;
}
F_39 ( V_8 , V_2 ) ;
V_2 -> V_12 = V_66 -> V_75 ;
V_2 -> V_49 . V_63 = F_40 ( V_71 , L_6 , V_8 -> V_63 , V_68 ) ;
if ( ! V_2 -> V_49 . V_63 ) {
V_13 = - V_73 ;
goto V_76;
}
V_70 = F_41 ( V_8 -> V_22 . V_77 ) ;
V_13 = F_42 ( V_70 , L_7 , & V_42 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_8 -> V_22 ,
L_8 ) ;
goto V_76;
}
V_2 -> V_42 = V_42 ;
V_13 = F_42 ( V_70 , L_9 ,
& V_24 ) ;
if ( V_13 < 0 ) {
F_43 ( & V_8 -> V_22 ,
L_10 ) ;
V_24 = V_78 ;
}
if ( V_2 -> V_12 == V_30 ) {
if ( V_24 > V_79 )
V_24 = V_79 ;
V_2 -> V_4 = ( ( 340 * 50000 ) / V_42 ) /
( 4096 / ( 1 << ( 2 * V_24 ) ) ) ;
} else {
if ( V_24 > V_78 )
V_24 = V_78 ;
V_2 -> V_4 = ( ( 58 * 50000 ) / V_42 ) /
( 128 / ( 1 << V_24 ) ) ;
}
V_2 -> V_8 = V_8 ;
V_2 -> V_66 = V_68 ;
V_2 -> V_49 . type = V_80 ;
V_2 -> V_49 . V_81 = V_82 ;
if ( V_2 -> V_12 >= V_83 )
V_2 -> V_49 . V_84 =
F_44 ( V_82 ) ;
else if ( V_2 -> V_12 >= V_85 )
V_2 -> V_49 . V_84 =
F_44 ( V_82 ) - 1 ;
else if ( V_2 -> V_12 >= V_86 )
V_2 -> V_49 . V_84 =
F_44 ( V_82 ) - 2 ;
else
V_2 -> V_49 . V_84 =
F_44 ( V_82 ) - 3 ;
V_2 -> V_49 . V_87 = F_20 ;
V_2 -> V_49 . V_88 = F_22 ;
V_2 -> V_49 . V_89 = F_23 ;
V_2 -> V_49 . V_90 = NULL ;
F_45 ( & V_2 -> V_60 , F_26 ) ;
V_13 = F_9 ( V_2 , V_24 ) ;
if ( V_13 < 0 ) {
F_5 ( & V_8 -> V_22 , L_11 ) ;
goto V_91;
}
V_13 = F_46 ( & V_8 -> V_22 , & V_2 -> V_49 ) ;
if ( V_13 ) {
F_5 ( & V_8 -> V_22 , L_12 ) ;
goto V_92;
} else {
F_27 ( & V_2 -> V_60 , V_61 * V_62 ) ;
}
return 0 ;
V_92:
F_32 ( V_2 -> V_49 . V_63 ) ;
V_91:
V_76:
V_74:
F_33 ( & V_64 ) ;
F_34 ( & V_65 , V_68 ) ;
F_35 ( & V_64 ) ;
V_72:
return V_13 ;
}
static int F_47 ( struct V_93 * V_22 )
{
struct V_7 * V_8 = F_48 ( V_22 ) ;
struct V_1 * V_2 = F_29 ( V_8 ) ;
F_30 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_49 ( struct V_93 * V_22 )
{
struct V_7 * V_8 = F_48 ( V_22 ) ;
struct V_1 * V_2 = F_29 ( V_8 ) ;
F_27 ( & V_2 -> V_60 , V_61 * V_62 ) ;
return 0 ;
}
