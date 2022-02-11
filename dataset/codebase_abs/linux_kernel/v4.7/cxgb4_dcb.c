static inline bool F_1 ( enum V_1 V_2 )
{
if ( V_2 == V_3 ||
V_2 == V_4 )
return true ;
else
return false ;
}
void F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
int V_11 = V_10 -> V_12 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_2 = V_13 ;
if ( V_11 )
V_10 -> V_12 = V_11 ;
F_4 ( V_6 , L_1 ,
V_14 , V_8 -> V_15 ) ;
}
void F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
V_10 -> V_12 = V_16 ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_19 V_20 ;
int V_21 , V_22 ;
V_20 . V_23 = 0 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
if ( ! V_10 -> V_25 [ V_21 ] . V_26 )
break;
V_20 . V_27 = V_10 -> V_25 [ V_21 ] . V_26 ;
if ( V_10 -> V_12 == V_28 ) {
V_20 . V_23 = V_10 -> V_25 [ V_21 ] . V_29 ;
V_20 . V_30 = V_10 -> V_25 [ V_21 ] . V_31 + 1 ;
V_22 = F_7 ( V_6 , & V_20 ) ;
} else {
V_20 . V_30 = ! ! ( V_10 -> V_25 [ V_21 ] . V_31 ) ;
V_22 = F_8 ( V_6 , & V_20 ) ;
}
if ( V_22 ) {
F_9 ( V_18 -> V_32 ,
L_2 ,
V_33 [ V_10 -> V_12 ] , V_20 . V_30 ,
V_20 . V_27 , - V_22 ) ;
break;
}
}
}
void F_10 ( struct V_5 * V_6 ,
enum V_34 V_35 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_17 * V_18 = V_8 -> V_17 ;
enum V_1 V_36 = V_10 -> V_2 ;
F_4 ( V_6 , L_3 ,
V_14 , V_10 -> V_2 , V_35 , V_6 -> V_37 ) ;
switch ( V_36 ) {
case V_13 : {
switch ( V_35 ) {
case V_38 : {
V_10 -> V_2 = V_4 ;
V_10 -> V_39 = V_40 ;
break;
}
case V_41 : {
V_10 -> V_2 = V_42 ;
V_10 -> V_39 = V_43 ;
if ( V_10 -> V_12 == V_28 )
V_10 -> V_39 |= V_44 ;
else
V_10 -> V_39 |= V_45 ;
break;
}
case V_46 : {
break;
}
case V_47 : {
V_10 -> V_2 = V_3 ;
break;
}
default:
goto V_48;
}
break;
}
case V_42 : {
switch ( V_35 ) {
case V_41 : {
break;
}
case V_46 : {
break;
}
case V_47 : {
V_10 -> V_2 = V_3 ;
V_10 -> V_49 = 1 ;
F_11 ( V_6 ) ;
break;
}
default:
goto V_48;
}
break;
}
case V_3 : {
switch ( V_35 ) {
case V_41 : {
break;
}
case V_46 : {
F_6 ( V_6 ) ;
F_2 ( V_6 ) ;
V_10 -> V_2 = V_42 ;
V_10 -> V_39 = V_50 ;
F_11 ( V_6 ) ;
break;
}
case V_47 : {
V_10 -> V_49 = 1 ;
F_11 ( V_6 ) ;
break;
}
default:
goto V_48;
}
break;
}
case V_4 : {
switch ( V_35 ) {
case V_38 : {
break;
}
default:
goto V_48;
}
break;
}
default:
goto V_51;
}
return;
V_48:
F_9 ( V_18 -> V_32 , L_4 ,
V_35 ) ;
return;
V_51:
F_9 ( V_18 -> V_32 , L_5 ,
V_36 , V_35 ) ;
}
void F_12 ( struct V_17 * V_18 ,
const struct V_52 * V_53 )
{
const union V_54 * V_55 = & V_53 -> V_56 . V_10 ;
int V_57 = F_13 ( F_14 ( V_53 -> V_58 ) ) ;
struct V_5 * V_6 = V_18 -> V_57 [ V_18 -> V_59 [ V_57 ] ] ;
struct V_7 * V_8 = F_15 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
int V_60 = V_53 -> V_56 . V_10 . V_61 . type ;
int V_62 ;
if ( V_60 == V_63 ) {
enum V_34 V_64 =
( ( V_53 -> V_56 . V_10 . V_65 . V_66 &
V_67 )
? V_3
: V_42 ) ;
if ( V_10 -> V_12 != V_68 ) {
V_62 = F_16 (
F_17 (
V_53 -> V_56 . V_10 . V_65 . V_69 ) ) ;
if ( V_62 == V_70 ||
V_62 == V_28 ) {
V_10 -> V_12 = V_62 ;
F_18 ( V_18 -> V_32 , L_6 ,
V_6 -> V_37 ,
V_33 [ V_10 -> V_12 ] ) ;
} else {
F_18 ( V_18 -> V_32 ,
L_7 ,
V_33 [ V_10 -> V_12 ] ,
V_33 [ V_62 ] ) ;
V_10 -> V_12 = V_68 ;
}
}
F_10 ( V_6 , V_64 ) ;
return;
}
if ( V_10 -> V_2 == V_13 ||
V_10 -> V_2 == V_4 ) {
F_9 ( V_18 -> V_32 , L_8 ,
V_10 -> V_2 ) ;
return;
}
switch ( V_60 ) {
case V_71 :
V_10 -> V_61 = F_14 ( V_55 -> V_61 . V_61 ) ;
V_10 -> V_72 |= V_73 ;
break;
case V_74 :
V_10 -> V_75 = V_55 -> V_76 . V_77 ;
memcpy ( V_10 -> V_76 , & V_55 -> V_76 . V_76 ,
sizeof( V_10 -> V_76 ) ) ;
memcpy ( V_10 -> V_78 , & V_55 -> V_76 . V_78 ,
sizeof( V_10 -> V_78 ) ) ;
V_10 -> V_72 |= V_79 ;
if ( V_10 -> V_72 & V_73 )
F_19 ( V_6 , V_10 ) ;
break;
case V_80 :
memcpy ( V_10 -> V_81 , & V_55 -> V_81 . V_82 ,
sizeof( V_10 -> V_81 ) ) ;
V_10 -> V_72 |= V_83 ;
break;
case V_84 :
V_10 -> V_85 = V_55 -> V_86 . V_85 ;
V_10 -> V_87 = V_55 -> V_86 . V_88 ;
V_10 -> V_72 |= V_89 ;
F_19 ( V_6 , V_10 ) ;
break;
case V_90 : {
const struct V_91 * V_92 = & V_55 -> V_25 ;
int V_93 = V_92 -> V_93 ;
struct V_25 * V_94 = & V_10 -> V_25 [ V_93 ] ;
struct V_19 V_20 = {
. V_27 = F_17 ( V_92 -> V_26 ) ,
} ;
int V_22 ;
if ( V_10 -> V_12 == V_28 ) {
V_20 . V_30 = ( V_92 -> V_31 + 1 ) ;
V_20 . V_23 = F_20 ( V_92 -> V_29 ) - 1 ;
V_22 = F_21 ( V_6 , & V_20 ) ;
F_19 ( V_6 , V_10 ) ;
} else {
V_20 . V_30 = ! ! ( V_92 -> V_31 ) ;
V_20 . V_23 = V_92 -> V_29 ;
V_22 = F_8 ( V_6 , & V_20 ) ;
}
if ( V_22 )
F_9 ( V_18 -> V_32 ,
L_9 ,
V_20 . V_30 , V_20 . V_27 , V_20 . V_23 , - V_22 ) ;
V_94 -> V_29 = V_92 -> V_29 ;
V_94 -> V_31 = V_92 -> V_31 ;
V_94 -> V_26 = F_17 ( V_92 -> V_26 ) ;
V_10 -> V_72 |= V_95 ;
break;
}
default:
F_9 ( V_18 -> V_32 , L_10 ,
V_60 ) ;
break;
}
}
static T_1 F_22 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_10 . V_49 ;
}
static T_1 F_23 ( struct V_5 * V_6 , T_1 V_49 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_10 . V_2 == V_4 ) {
V_8 -> V_10 . V_49 = V_49 ;
return 0 ;
}
if ( V_49 != ( V_8 -> V_10 . V_2 == V_3 ) )
return 1 ;
return 0 ;
}
static void F_24 ( struct V_5 * V_6 , int V_96 ,
T_1 * V_97 , T_1 * V_61 , T_1 * V_98 ,
T_1 * V_99 , int V_100 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
* V_97 = * V_61 = * V_98 = * V_99 = 0 ;
if ( V_100 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_61 . type = V_71 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return;
}
* V_61 = ( F_14 ( V_53 . V_56 . V_10 . V_61 . V_61 ) >> ( V_96 * 4 ) ) & 0xf ;
if ( V_100 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_76 . type = V_74 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
* V_98 = V_53 . V_56 . V_10 . V_76 . V_76 [ * V_61 ] ;
* V_99 = ( 1 << V_96 ) ;
if ( * V_61 != 0xF )
* V_97 = 0x2 ;
}
static void F_28 ( struct V_5 * V_6 , int V_96 ,
T_1 * V_97 , T_1 * V_61 , T_1 * V_98 ,
T_1 * V_99 )
{
return F_24 ( V_6 , ( 7 - V_96 ) , V_97 , V_61 , V_98 ,
V_99 , 1 ) ;
}
static void F_29 ( struct V_5 * V_6 , int V_96 ,
T_1 * V_97 , T_1 * V_61 , T_1 * V_98 ,
T_1 * V_99 )
{
return F_24 ( V_6 , ( 7 - V_96 ) , V_97 , V_61 , V_98 ,
V_99 , 0 ) ;
}
static void F_30 ( struct V_5 * V_6 , int V_96 ,
T_1 V_97 , T_1 V_61 , T_1 V_98 ,
T_1 V_99 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_103 = 7 - V_96 ;
T_2 V_104 ;
int V_22 ;
if ( V_61 == V_105 )
return;
if ( V_98 == V_105 )
return;
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_61 . type = V_71 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return;
}
V_104 = F_14 ( V_53 . V_56 . V_10 . V_61 . V_61 ) ;
V_104 &= ~ ( 0xF << ( V_103 * 4 ) ) ;
V_104 |= V_61 << ( V_103 * 4 ) ;
V_53 . V_56 . V_10 . V_61 . V_61 = F_31 ( V_104 ) ;
F_32 ( V_53 , V_8 -> V_15 ) ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_13 ,
- V_22 ) ;
return;
}
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_76 . type = V_74 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
V_53 . V_56 . V_10 . V_76 . V_76 [ V_61 ] = V_98 ;
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_106 ) ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 )
F_9 ( V_18 -> V_32 , L_14 ,
- V_22 ) ;
}
static void F_33 ( struct V_5 * V_6 , int V_61 , T_1 * V_98 ,
int V_100 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
if ( V_100 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_76 . type = V_74 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
* V_98 = V_53 . V_56 . V_10 . V_76 . V_76 [ V_61 ] ;
}
static void F_34 ( struct V_5 * V_6 , int V_61 , T_1 * V_98 )
{
return F_33 ( V_6 , V_61 , V_98 , 1 ) ;
}
static void F_35 ( struct V_5 * V_6 , int V_61 , T_1 * V_98 )
{
return F_33 ( V_6 , V_61 , V_98 , 0 ) ;
}
static void F_36 ( struct V_5 * V_6 , int V_61 ,
T_1 V_98 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_76 . type = V_74 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
V_53 . V_56 . V_10 . V_76 . V_76 [ V_61 ] = V_98 ;
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_106 ) ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 )
F_9 ( V_18 -> V_32 , L_14 ,
- V_22 ) ;
}
static void F_37 ( struct V_5 * V_6 , int V_23 , T_1 * V_107 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( ! F_1 ( V_10 -> V_2 ) ||
V_23 >= V_108 )
* V_107 = 0 ;
else
* V_107 = ( V_8 -> V_10 . V_85 >> ( 7 - V_23 ) ) & 1 ;
}
static void F_38 ( struct V_5 * V_6 , int V_23 , T_1 V_107 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) ||
V_23 >= V_108 )
return;
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_106 ) ;
V_53 . V_56 . V_10 . V_86 . type = V_84 ;
V_53 . V_56 . V_10 . V_86 . V_85 = V_8 -> V_10 . V_85 ;
if ( V_107 )
V_53 . V_56 . V_10 . V_86 . V_85 |= ( 1 << ( 7 - V_23 ) ) ;
else
V_53 . V_56 . V_10 . V_86 . V_85 &= ( ~ ( 1 << ( 7 - V_23 ) ) ) ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_15 , - V_22 ) ;
return;
}
V_8 -> V_10 . V_85 = V_53 . V_56 . V_10 . V_86 . V_85 ;
}
static T_1 F_39 ( struct V_5 * V_6 )
{
return 0 ;
}
static T_1 F_40 ( struct V_5 * V_6 , int V_109 , T_1 * V_110 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_109 ) {
case V_111 :
case V_112 :
* V_110 = true ;
break;
case V_113 :
* V_110 = 0x80 ;
break;
case V_114 :
* V_110 = 0x80 ;
break;
case V_115 :
* V_110 = true ;
break;
case V_116 :
case V_117 :
* V_110 = false ;
break;
case V_118 :
* V_110 = V_8 -> V_10 . V_39 ;
break;
default:
* V_110 = false ;
}
return 0 ;
}
static int F_41 ( struct V_5 * V_6 , int V_119 , T_1 * V_120 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_119 ) {
case V_121 :
if ( V_8 -> V_10 . V_72 & V_79 )
* V_120 = V_8 -> V_10 . V_75 ;
else
* V_120 = 0x8 ;
break;
case V_122 :
* V_120 = 0x8 ;
break;
default:
return - V_123 ;
}
return 0 ;
}
static int F_42 ( struct V_5 * V_6 , int V_119 , T_1 V_120 )
{
return - V_124 ;
}
static T_1 F_43 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return false ;
return V_8 -> V_10 . V_85 != 0 ;
}
static void F_44 ( struct V_5 * V_6 , T_1 V_2 )
{
}
static int F_45 ( struct V_5 * V_6 , T_1 V_125 , T_3 V_126 ,
int V_127 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 0 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
struct V_52 V_53 ;
int V_22 ;
if ( V_127 )
F_26 ( V_53 , V_8 -> V_15 ) ;
else
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_90 ;
V_53 . V_56 . V_10 . V_25 . V_93 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_16 ,
- V_22 ) ;
return V_22 ;
}
if ( F_17 ( V_53 . V_56 . V_10 . V_25 . V_26 ) == V_126 )
if ( V_53 . V_56 . V_10 . V_25 . V_31 == V_125 )
return V_53 . V_56 . V_10 . V_25 . V_29 ;
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
}
return - V_128 ;
}
static int F_46 ( struct V_5 * V_6 , T_1 V_125 , T_3 V_126 )
{
return F_45 ( V_6 , V_125 == V_129 ?
V_125 : 3 , V_126 , 0 ) ;
}
static int F_47 ( struct V_5 * V_6 , T_1 V_125 , T_3 V_126 ,
T_1 V_130 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 , V_22 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return - V_123 ;
if ( ! F_48 ( V_6 ) )
return - V_131 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_90 ;
V_53 . V_56 . V_10 . V_25 . V_93 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_17 ,
- V_22 ) ;
return V_22 ;
}
if ( F_17 ( V_53 . V_56 . V_10 . V_25 . V_26 ) == V_126 ) {
V_53 . V_56 . V_10 . V_25 . V_26 = 0 ;
break;
}
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
}
if ( V_21 == V_24 ) {
F_9 ( V_18 -> V_32 , L_18 ) ;
return - V_132 ;
}
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_106 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_90 ;
V_53 . V_56 . V_10 . V_25 . V_26 = F_49 ( V_126 ) ;
V_53 . V_56 . V_10 . V_25 . V_31 = V_125 ;
V_53 . V_56 . V_10 . V_25 . V_29 = V_130 ;
V_53 . V_56 . V_10 . V_25 . V_93 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_19 ,
- V_22 ) ;
return V_22 ;
}
return 0 ;
}
static int F_50 ( struct V_5 * V_6 , T_1 V_125 , T_3 V_126 ,
T_1 V_130 )
{
int V_133 ;
struct V_19 V_20 = {
. V_30 = V_125 ,
. V_27 = V_126 ,
. V_23 = V_130 ,
} ;
if ( V_125 != V_129 &&
V_125 != V_134 )
return - V_123 ;
V_133 = F_47 ( V_6 , V_125 == V_129 ?
V_125 : 3 , V_126 , V_130 ) ;
if ( V_133 )
return V_133 ;
return F_8 ( V_6 , & V_20 ) ;
}
static inline int
F_51 ( struct V_5 * V_6 ,
enum V_135 V_136 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( V_10 -> V_2 == V_3 )
if ( V_136 && ! ( V_10 -> V_72 & V_136 ) )
return 0 ;
return ( F_1 ( V_10 -> V_2 ) &&
( V_10 -> V_39 & V_44 ) ) ;
}
static int F_52 ( struct V_5 * V_6 , struct V_137 * V_138 ,
int V_100 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_17 * V_18 = V_8 -> V_17 ;
T_4 V_139 ;
struct V_52 V_53 ;
int V_21 , V_140 , V_22 ;
if ( ! ( V_10 -> V_72 & ( V_73 | V_79 ) ) )
return 0 ;
V_138 -> V_141 = V_10 -> V_75 ;
if ( V_100 ) {
V_138 -> V_142 = 1 ;
F_25 ( V_53 , V_8 -> V_15 ) ;
} else {
F_26 ( V_53 , V_8 -> V_15 ) ;
}
V_53 . V_56 . V_10 . V_61 . type = V_71 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return V_22 ;
}
V_139 = F_14 ( V_53 . V_56 . V_10 . V_61 . V_61 ) ;
if ( V_100 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_76 . type = V_74 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return V_22 ;
}
for ( V_21 = 0 ; V_21 < V_143 ; V_21 ++ ) {
V_140 = ( V_139 >> ( ( 7 - V_21 ) * 4 ) ) & 0xF ;
V_138 -> V_144 [ V_21 ] = V_140 ;
V_138 -> V_145 [ V_21 ] = V_53 . V_56 . V_10 . V_76 . V_76 [ V_21 ] ;
V_138 -> V_146 [ V_21 ] = V_138 -> V_145 [ V_21 ] ;
V_138 -> V_147 [ V_21 ] = V_53 . V_56 . V_10 . V_76 . V_78 [ V_21 ] ;
}
return 0 ;
}
static int F_53 ( struct V_5 * V_6 , struct V_137 * V_138 )
{
return F_52 ( V_6 , V_138 , 1 ) ;
}
static int F_54 ( struct V_5 * V_6 , struct V_148 * V_86 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
memset ( V_86 , 0 , sizeof( struct V_148 ) ) ;
if ( ! ( V_10 -> V_72 & V_89 ) )
return 0 ;
V_86 -> V_149 = V_10 -> V_87 ;
V_86 -> V_150 = F_55 ( V_10 -> V_85 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 , struct V_137 * V_138 )
{
return F_52 ( V_6 , V_138 , 0 ) ;
}
static int F_57 ( struct V_5 * V_6 , struct V_19 * V_20 )
{
int V_151 ;
if ( ! F_51 ( V_6 , V_95 ) )
return - V_123 ;
if ( ! ( V_20 -> V_30 && V_20 -> V_27 ) )
return - V_123 ;
V_151 = F_45 ( V_6 , V_20 -> V_30 - 1 , V_20 -> V_27 , 0 ) ;
if ( V_151 < 0 )
V_151 = F_58 ( V_6 , V_20 ) ;
V_20 -> V_23 = F_20 ( V_151 ) - 1 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , struct V_19 * V_20 )
{
int V_133 ;
if ( ! F_51 ( V_6 , V_95 ) )
return - V_123 ;
if ( ! ( V_20 -> V_30 && V_20 -> V_27 ) )
return - V_123 ;
if ( ! ( V_20 -> V_30 > V_152 &&
V_20 -> V_30 < V_153 ) )
return - V_123 ;
V_133 = F_47 ( V_6 , V_20 -> V_30 - 1 , V_20 -> V_27 ,
( 1 << V_20 -> V_23 ) ) ;
if ( V_133 )
return V_133 ;
return F_21 ( V_6 , V_20 ) ;
}
static T_1 F_60 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_10 . V_39 ;
}
static T_1 F_61 ( struct V_5 * V_6 , T_1 V_154 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ( V_154 & ( V_50 | V_40 ) )
!= V_154 )
return 1 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 1 ;
if ( V_154 != V_8 -> V_10 . V_39 )
return 1 ;
V_8 -> V_10 . V_39 = V_154 ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_155 * V_156 , T_3 * V_157 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 , V_22 = 0 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 1 ;
V_156 -> V_142 = 0 ;
V_156 -> error = 0 ;
* V_157 = 0 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_90 ;
V_53 . V_56 . V_10 . V_25 . V_93 = * V_157 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_17 ,
- V_22 ) ;
return V_22 ;
}
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
}
* V_157 = V_21 ;
return V_22 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_19 * V_158 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 , V_22 = 0 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 1 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_90 ;
V_53 . V_56 . V_10 . V_25 . V_93 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_17 ,
- V_22 ) ;
return V_22 ;
}
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
V_158 [ V_21 ] . V_30 = ( V_53 . V_56 . V_10 . V_25 . V_31 + 1 ) ;
V_158 [ V_21 ] . V_27 =
F_17 ( V_53 . V_56 . V_10 . V_25 . V_26 ) ;
V_158 [ V_21 ] . V_23 =
F_20 ( V_53 . V_56 . V_10 . V_25 . V_29 ) - 1 ;
}
return V_22 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_159 * V_160 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
T_2 V_61 ;
int V_21 , V_22 ;
V_160 -> V_142 = true ;
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_61 . type = V_71 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return V_22 ;
}
V_61 = F_14 ( V_53 . V_56 . V_10 . V_61 . V_61 ) ;
for ( V_21 = 0 ; V_21 < V_108 ; V_21 ++ )
V_160 -> V_161 [ 7 - V_21 ] = ( V_61 >> ( V_21 * 4 ) ) & 0xF ;
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_76 . type = V_74 ;
V_22 = F_27 ( V_18 , V_18 -> V_101 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_102 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return V_22 ;
}
for ( V_21 = 0 ; V_21 < V_108 ; V_21 ++ )
V_160 -> V_162 [ V_21 ] = V_53 . V_56 . V_10 . V_76 . V_76 [ V_21 ] ;
V_160 -> V_163 = V_53 . V_56 . V_10 . V_76 . V_77 ;
return 0 ;
}
static int F_65 ( struct V_5 * V_6 , struct V_164 * V_86 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_41 ( V_6 , V_122 , & ( V_86 -> V_163 ) ) ;
V_86 -> V_150 = F_55 ( V_8 -> V_10 . V_85 ) ;
V_86 -> V_163 = V_8 -> V_10 . V_87 ;
return 0 ;
}
