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
struct V_5 * V_6 = V_18 -> V_57 [ V_57 ] ;
struct V_7 * V_8 = F_15 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
int V_59 = V_53 -> V_56 . V_10 . V_60 . type ;
int V_61 ;
if ( V_59 == V_62 ) {
enum V_34 V_63 =
( ( V_53 -> V_56 . V_10 . V_64 . V_65 &
V_66 )
? V_3
: V_42 ) ;
if ( V_10 -> V_12 != V_67 ) {
V_61 = F_16 (
F_17 (
V_53 -> V_56 . V_10 . V_64 . V_68 ) ) ;
if ( V_61 == V_69 ||
V_61 == V_28 ) {
V_10 -> V_12 = V_61 ;
F_18 ( V_18 -> V_32 , L_6 ,
V_6 -> V_37 ,
V_33 [ V_10 -> V_12 ] ) ;
} else {
F_18 ( V_18 -> V_32 ,
L_7 ,
V_33 [ V_10 -> V_12 ] ,
V_33 [ V_61 ] ) ;
V_10 -> V_12 = V_67 ;
}
}
F_10 ( V_6 , V_63 ) ;
return;
}
if ( V_10 -> V_2 == V_13 ||
V_10 -> V_2 == V_4 ) {
F_9 ( V_18 -> V_32 , L_8 ,
V_10 -> V_2 ) ;
return;
}
switch ( V_59 ) {
case V_70 :
V_10 -> V_60 = F_14 ( V_55 -> V_60 . V_60 ) ;
V_10 -> V_71 |= V_72 ;
break;
case V_73 :
V_10 -> V_74 = V_55 -> V_75 . V_76 ;
memcpy ( V_10 -> V_75 , & V_55 -> V_75 . V_75 ,
sizeof( V_10 -> V_75 ) ) ;
memcpy ( V_10 -> V_77 , & V_55 -> V_75 . V_77 ,
sizeof( V_10 -> V_77 ) ) ;
V_10 -> V_71 |= V_78 ;
if ( V_10 -> V_71 & V_72 )
F_19 ( V_6 , V_10 ) ;
break;
case V_79 :
memcpy ( V_10 -> V_80 , & V_55 -> V_80 . V_81 ,
sizeof( V_10 -> V_80 ) ) ;
V_10 -> V_71 |= V_82 ;
break;
case V_83 :
V_10 -> V_84 = V_55 -> V_85 . V_84 ;
V_10 -> V_86 = V_55 -> V_85 . V_87 ;
V_10 -> V_71 |= V_88 ;
F_19 ( V_6 , V_10 ) ;
break;
case V_89 : {
const struct V_90 * V_91 = & V_55 -> V_25 ;
int V_92 = V_91 -> V_92 ;
struct V_25 * V_93 = & V_10 -> V_25 [ V_92 ] ;
struct V_19 V_20 = {
. V_27 = F_17 ( V_91 -> V_26 ) ,
} ;
int V_22 ;
if ( V_10 -> V_12 == V_28 ) {
V_20 . V_30 = ( V_91 -> V_31 + 1 ) ;
V_20 . V_23 = F_20 ( V_91 -> V_29 ) - 1 ;
V_22 = F_21 ( V_6 , & V_20 ) ;
F_19 ( V_6 , V_10 ) ;
} else {
V_20 . V_30 = ! ! ( V_91 -> V_31 ) ;
V_20 . V_23 = V_91 -> V_29 ;
V_22 = F_8 ( V_6 , & V_20 ) ;
}
if ( V_22 )
F_9 ( V_18 -> V_32 ,
L_9 ,
V_20 . V_30 , V_20 . V_27 , V_20 . V_23 , - V_22 ) ;
V_93 -> V_29 = V_91 -> V_29 ;
V_93 -> V_31 = V_91 -> V_31 ;
V_93 -> V_26 = F_17 ( V_91 -> V_26 ) ;
V_10 -> V_71 |= V_94 ;
break;
}
default:
F_9 ( V_18 -> V_32 , L_10 ,
V_59 ) ;
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
static void F_24 ( struct V_5 * V_6 , int V_95 ,
T_1 * V_96 , T_1 * V_60 , T_1 * V_97 ,
T_1 * V_98 , int V_99 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
* V_96 = * V_60 = * V_97 = * V_98 = 0 ;
if ( V_99 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_60 . type = V_70 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return;
}
* V_60 = ( F_14 ( V_53 . V_56 . V_10 . V_60 . V_60 ) >> ( V_95 * 4 ) ) & 0xf ;
if ( V_99 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_75 . type = V_73 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
* V_97 = V_53 . V_56 . V_10 . V_75 . V_75 [ * V_60 ] ;
* V_98 = ( 1 << V_95 ) ;
if ( * V_60 != 0xF )
* V_96 = 0x2 ;
}
static void F_28 ( struct V_5 * V_6 , int V_95 ,
T_1 * V_96 , T_1 * V_60 , T_1 * V_97 ,
T_1 * V_98 )
{
return F_24 ( V_6 , ( 7 - V_95 ) , V_96 , V_60 , V_97 ,
V_98 , 1 ) ;
}
static void F_29 ( struct V_5 * V_6 , int V_95 ,
T_1 * V_96 , T_1 * V_60 , T_1 * V_97 ,
T_1 * V_98 )
{
return F_24 ( V_6 , ( 7 - V_95 ) , V_96 , V_60 , V_97 ,
V_98 , 0 ) ;
}
static void F_30 ( struct V_5 * V_6 , int V_95 ,
T_1 V_96 , T_1 V_60 , T_1 V_97 ,
T_1 V_98 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_102 = 7 - V_95 ;
T_2 V_103 ;
int V_22 ;
if ( V_60 == V_104 )
return;
if ( V_97 == V_104 )
return;
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_60 . type = V_70 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return;
}
V_103 = F_14 ( V_53 . V_56 . V_10 . V_60 . V_60 ) ;
V_103 &= ~ ( 0xF << ( V_102 * 4 ) ) ;
V_103 |= V_60 << ( V_102 * 4 ) ;
V_53 . V_56 . V_10 . V_60 . V_60 = F_31 ( V_103 ) ;
F_32 ( V_53 , V_8 -> V_15 ) ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_13 ,
- V_22 ) ;
return;
}
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_75 . type = V_73 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
V_53 . V_56 . V_10 . V_75 . V_75 [ V_60 ] = V_97 ;
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_105 ) ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 )
F_9 ( V_18 -> V_32 , L_14 ,
- V_22 ) ;
}
static void F_33 ( struct V_5 * V_6 , int V_60 , T_1 * V_97 ,
int V_99 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
if ( V_99 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_75 . type = V_73 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
* V_97 = V_53 . V_56 . V_10 . V_75 . V_75 [ V_60 ] ;
}
static void F_34 ( struct V_5 * V_6 , int V_60 , T_1 * V_97 )
{
return F_33 ( V_6 , V_60 , V_97 , 1 ) ;
}
static void F_35 ( struct V_5 * V_6 , int V_60 , T_1 * V_97 )
{
return F_33 ( V_6 , V_60 , V_97 , 0 ) ;
}
static void F_36 ( struct V_5 * V_6 , int V_60 ,
T_1 V_97 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_75 . type = V_73 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return;
}
V_53 . V_56 . V_10 . V_75 . V_75 [ V_60 ] = V_97 ;
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_105 ) ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 )
F_9 ( V_18 -> V_32 , L_14 ,
- V_22 ) ;
}
static void F_37 ( struct V_5 * V_6 , int V_23 , T_1 * V_106 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( ! F_1 ( V_10 -> V_2 ) ||
V_23 >= V_107 )
* V_106 = 0 ;
else
* V_106 = ( V_8 -> V_10 . V_84 >> ( 7 - V_23 ) ) & 1 ;
}
static void F_38 ( struct V_5 * V_6 , int V_23 , T_1 V_106 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_22 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) ||
V_23 >= V_107 )
return;
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_105 ) ;
V_53 . V_56 . V_10 . V_85 . type = V_83 ;
V_53 . V_56 . V_10 . V_85 . V_84 = V_8 -> V_10 . V_84 ;
if ( V_106 )
V_53 . V_56 . V_10 . V_85 . V_84 |= ( 1 << ( 7 - V_23 ) ) ;
else
V_53 . V_56 . V_10 . V_85 . V_84 &= ( ~ ( 1 << ( 7 - V_23 ) ) ) ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_15 , - V_22 ) ;
return;
}
V_8 -> V_10 . V_84 = V_53 . V_56 . V_10 . V_85 . V_84 ;
}
static T_1 F_39 ( struct V_5 * V_6 )
{
return 0 ;
}
static T_1 F_40 ( struct V_5 * V_6 , int V_108 , T_1 * V_109 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_108 ) {
case V_110 :
case V_111 :
* V_109 = true ;
break;
case V_112 :
* V_109 = 0x80 ;
break;
case V_113 :
* V_109 = 0x80 ;
break;
case V_114 :
* V_109 = true ;
break;
case V_115 :
case V_116 :
* V_109 = false ;
break;
case V_117 :
* V_109 = V_8 -> V_10 . V_39 ;
break;
default:
* V_109 = false ;
}
return 0 ;
}
static int F_41 ( struct V_5 * V_6 , int V_118 , T_1 * V_119 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_118 ) {
case V_120 :
if ( V_8 -> V_10 . V_71 & V_78 )
* V_119 = V_8 -> V_10 . V_74 ;
else
* V_119 = 0x8 ;
break;
case V_121 :
* V_119 = 0x8 ;
break;
default:
return - V_122 ;
}
return 0 ;
}
static int F_42 ( struct V_5 * V_6 , int V_118 , T_1 V_119 )
{
return - V_123 ;
}
static T_1 F_43 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return false ;
return V_8 -> V_10 . V_84 != 0 ;
}
static void F_44 ( struct V_5 * V_6 , T_1 V_2 )
{
}
static int F_45 ( struct V_5 * V_6 , T_1 V_124 , T_3 V_125 ,
int V_126 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 0 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
struct V_52 V_53 ;
int V_22 ;
if ( V_126 )
F_26 ( V_53 , V_8 -> V_15 ) ;
else
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_89 ;
V_53 . V_56 . V_10 . V_25 . V_92 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_16 ,
- V_22 ) ;
return V_22 ;
}
if ( F_17 ( V_53 . V_56 . V_10 . V_25 . V_26 ) == V_125 )
if ( V_53 . V_56 . V_10 . V_25 . V_31 == V_124 )
return V_53 . V_56 . V_10 . V_25 . V_29 ;
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
}
return - V_127 ;
}
static int F_46 ( struct V_5 * V_6 , T_1 V_124 , T_3 V_125 )
{
return F_45 ( V_6 , V_124 == V_128 ?
V_124 : 3 , V_125 , 0 ) ;
}
static int F_47 ( struct V_5 * V_6 , T_1 V_124 , T_3 V_125 ,
T_1 V_129 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 , V_22 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return - V_122 ;
if ( ! F_48 ( V_6 ) )
return - V_130 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
F_25 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_89 ;
V_53 . V_56 . V_10 . V_25 . V_92 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_17 ,
- V_22 ) ;
return V_22 ;
}
if ( F_17 ( V_53 . V_56 . V_10 . V_25 . V_26 ) == V_125 ) {
V_53 . V_56 . V_10 . V_25 . V_26 = 0 ;
break;
}
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
}
if ( V_21 == V_24 ) {
F_9 ( V_18 -> V_32 , L_18 ) ;
return - V_131 ;
}
F_32 ( V_53 , V_8 -> V_15 ) ;
if ( V_8 -> V_10 . V_2 == V_4 )
V_53 . V_58 |= F_31 ( V_105 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_89 ;
V_53 . V_56 . V_10 . V_25 . V_26 = F_49 ( V_125 ) ;
V_53 . V_56 . V_10 . V_25 . V_31 = V_124 ;
V_53 . V_56 . V_10 . V_25 . V_29 = V_129 ;
V_53 . V_56 . V_10 . V_25 . V_92 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_19 ,
- V_22 ) ;
return V_22 ;
}
return 0 ;
}
static int F_50 ( struct V_5 * V_6 , T_1 V_124 , T_3 V_125 ,
T_1 V_129 )
{
int V_132 ;
struct V_19 V_20 = {
. V_30 = V_124 ,
. V_27 = V_125 ,
. V_23 = V_129 ,
} ;
if ( V_124 != V_128 &&
V_124 != V_133 )
return - V_122 ;
V_132 = F_47 ( V_6 , V_124 == V_128 ?
V_124 : 3 , V_125 , V_129 ) ;
if ( V_132 )
return V_132 ;
return F_8 ( V_6 , & V_20 ) ;
}
static inline int
F_51 ( struct V_5 * V_6 ,
enum V_134 V_135 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( V_10 -> V_2 == V_3 )
if ( V_135 && ! ( V_10 -> V_71 & V_135 ) )
return 0 ;
return ( F_1 ( V_10 -> V_2 ) &&
( V_10 -> V_39 & V_44 ) ) ;
}
static int F_52 ( struct V_5 * V_6 , struct V_136 * V_137 ,
int V_99 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_17 * V_18 = V_8 -> V_17 ;
T_4 V_138 ;
struct V_52 V_53 ;
int V_21 , V_139 , V_22 ;
if ( ! ( V_10 -> V_71 & ( V_72 | V_78 ) ) )
return 0 ;
V_137 -> V_140 = V_10 -> V_74 ;
if ( V_99 ) {
V_137 -> V_141 = 1 ;
F_25 ( V_53 , V_8 -> V_15 ) ;
} else {
F_26 ( V_53 , V_8 -> V_15 ) ;
}
V_53 . V_56 . V_10 . V_60 . type = V_70 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return V_22 ;
}
V_138 = F_14 ( V_53 . V_56 . V_10 . V_60 . V_60 ) ;
if ( V_99 )
F_25 ( V_53 , V_8 -> V_15 ) ;
else
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_75 . type = V_73 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return V_22 ;
}
for ( V_21 = 0 ; V_21 < V_142 ; V_21 ++ ) {
V_139 = ( V_138 >> ( ( 7 - V_21 ) * 4 ) ) & 0xF ;
V_137 -> V_143 [ V_21 ] = V_139 ;
V_137 -> V_144 [ V_21 ] = V_53 . V_56 . V_10 . V_75 . V_75 [ V_21 ] ;
V_137 -> V_145 [ V_21 ] = V_137 -> V_144 [ V_21 ] ;
V_137 -> V_146 [ V_21 ] = V_53 . V_56 . V_10 . V_75 . V_77 [ V_21 ] ;
}
return 0 ;
}
static int F_53 ( struct V_5 * V_6 , struct V_136 * V_137 )
{
return F_52 ( V_6 , V_137 , 1 ) ;
}
static int F_54 ( struct V_5 * V_6 , struct V_147 * V_85 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
memset ( V_85 , 0 , sizeof( struct V_147 ) ) ;
if ( ! ( V_10 -> V_71 & V_88 ) )
return 0 ;
V_85 -> V_148 = V_10 -> V_86 ;
V_85 -> V_149 = F_55 ( V_10 -> V_84 ) ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 , struct V_136 * V_137 )
{
return F_52 ( V_6 , V_137 , 0 ) ;
}
static int F_57 ( struct V_5 * V_6 , struct V_19 * V_20 )
{
int V_150 ;
if ( ! F_51 ( V_6 , V_94 ) )
return - V_122 ;
if ( ! ( V_20 -> V_30 && V_20 -> V_27 ) )
return - V_122 ;
V_150 = F_45 ( V_6 , V_20 -> V_30 - 1 , V_20 -> V_27 , 0 ) ;
if ( V_150 < 0 )
V_150 = F_58 ( V_6 , V_20 ) ;
V_20 -> V_23 = F_20 ( V_150 ) - 1 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 , struct V_19 * V_20 )
{
int V_132 ;
if ( ! F_51 ( V_6 , V_94 ) )
return - V_122 ;
if ( ! ( V_20 -> V_30 && V_20 -> V_27 ) )
return - V_122 ;
if ( ! ( V_20 -> V_30 > V_151 &&
V_20 -> V_30 < V_152 ) )
return - V_122 ;
V_132 = F_47 ( V_6 , V_20 -> V_30 - 1 , V_20 -> V_27 ,
( 1 << V_20 -> V_23 ) ) ;
if ( V_132 )
return V_132 ;
return F_21 ( V_6 , V_20 ) ;
}
static T_1 F_60 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_10 . V_39 ;
}
static T_1 F_61 ( struct V_5 * V_6 , T_1 V_153 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( ( V_153 & ( V_50 | V_40 ) )
!= V_153 )
return 1 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 1 ;
if ( V_153 != V_8 -> V_10 . V_39 )
return 1 ;
V_8 -> V_10 . V_39 = V_153 ;
return 0 ;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_154 * V_155 , T_3 * V_156 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 , V_22 = 0 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 1 ;
V_155 -> V_141 = 0 ;
V_155 -> error = 0 ;
* V_156 = 0 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_89 ;
V_53 . V_56 . V_10 . V_25 . V_92 = * V_156 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_17 ,
- V_22 ) ;
return V_22 ;
}
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
}
* V_156 = V_21 ;
return V_22 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_19 * V_157 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
int V_21 , V_22 = 0 ;
if ( ! F_1 ( V_8 -> V_10 . V_2 ) )
return 1 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_25 . type = V_89 ;
V_53 . V_56 . V_10 . V_25 . V_92 = V_21 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_17 ,
- V_22 ) ;
return V_22 ;
}
if ( ! V_53 . V_56 . V_10 . V_25 . V_26 )
break;
V_157 [ V_21 ] . V_30 = ( V_53 . V_56 . V_10 . V_25 . V_31 + 1 ) ;
V_157 [ V_21 ] . V_27 =
F_17 ( V_53 . V_56 . V_10 . V_25 . V_26 ) ;
V_157 [ V_21 ] . V_23 =
F_20 ( V_53 . V_56 . V_10 . V_25 . V_29 ) - 1 ;
}
return V_22 ;
}
static int F_64 ( struct V_5 * V_6 , struct V_158 * V_159 )
{
struct V_52 V_53 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_17 ;
T_2 V_60 ;
int V_21 , V_22 ;
V_159 -> V_141 = true ;
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_60 . type = V_70 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_11 , - V_22 ) ;
return V_22 ;
}
V_60 = F_14 ( V_53 . V_56 . V_10 . V_60 . V_60 ) ;
for ( V_21 = 0 ; V_21 < V_107 ; V_21 ++ )
V_159 -> V_160 [ 7 - V_21 ] = ( V_60 >> ( V_21 * 4 ) ) & 0xF ;
F_26 ( V_53 , V_8 -> V_15 ) ;
V_53 . V_56 . V_10 . V_75 . type = V_73 ;
V_22 = F_27 ( V_18 , V_18 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_22 != V_101 ) {
F_9 ( V_18 -> V_32 , L_12 ,
- V_22 ) ;
return V_22 ;
}
for ( V_21 = 0 ; V_21 < V_107 ; V_21 ++ )
V_159 -> V_161 [ V_21 ] = V_53 . V_56 . V_10 . V_75 . V_75 [ V_21 ] ;
V_159 -> V_162 = V_53 . V_56 . V_10 . V_75 . V_76 ;
return 0 ;
}
static int F_65 ( struct V_5 * V_6 , struct V_163 * V_85 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_41 ( V_6 , V_121 , & ( V_85 -> V_162 ) ) ;
V_85 -> V_149 = F_55 ( V_8 -> V_10 . V_84 ) ;
V_85 -> V_162 = V_8 -> V_10 . V_86 ;
return 0 ;
}
