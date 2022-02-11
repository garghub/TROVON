void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_7 = V_6 -> V_8 ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
V_6 -> V_9 = V_10 ;
if ( V_7 )
V_6 -> V_8 = V_7 ;
F_3 ( V_2 , L_1 ,
V_11 , V_4 -> V_12 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
V_6 -> V_8 = V_13 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_16 V_17 ;
int V_18 , V_19 ;
V_17 . V_20 = 0 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
if ( ! V_6 -> V_22 [ V_18 ] . V_23 )
break;
V_17 . V_24 = V_6 -> V_22 [ V_18 ] . V_23 ;
if ( V_6 -> V_8 == V_25 ) {
V_17 . V_20 = V_6 -> V_22 [ V_18 ] . V_26 ;
V_17 . V_27 = V_6 -> V_22 [ V_18 ] . V_28 + 1 ;
V_19 = F_6 ( V_2 , & V_17 ) ;
} else {
V_17 . V_27 = ! ! ( V_6 -> V_22 [ V_18 ] . V_28 ) ;
V_19 = F_7 ( V_2 , & V_17 ) ;
}
if ( V_19 ) {
F_8 ( V_15 -> V_29 ,
L_2 ,
V_30 [ V_6 -> V_8 ] , V_17 . V_27 ,
V_17 . V_24 , - V_19 ) ;
break;
}
}
}
void F_9 ( struct V_1 * V_2 ,
enum V_31 V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_14 * V_15 = V_4 -> V_14 ;
enum V_33 V_34 = V_6 -> V_9 ;
F_3 ( V_2 , L_3 ,
V_11 , V_6 -> V_9 , V_32 , V_2 -> V_35 ) ;
switch ( V_34 ) {
case V_10 : {
switch ( V_32 ) {
case V_36 : {
V_6 -> V_9 = V_37 ;
V_6 -> V_38 = V_39 ;
break;
}
case V_40 : {
V_6 -> V_9 = V_41 ;
V_6 -> V_38 = V_42 ;
if ( V_6 -> V_8 == V_25 )
V_6 -> V_38 |= V_43 ;
else
V_6 -> V_38 |= V_44 ;
break;
}
case V_45 : {
break;
}
case V_46 : {
V_6 -> V_9 = V_47 ;
break;
}
default:
goto V_48;
}
break;
}
case V_41 : {
switch ( V_32 ) {
case V_40 : {
break;
}
case V_45 : {
break;
}
case V_46 : {
V_6 -> V_9 = V_47 ;
V_6 -> V_49 = 1 ;
F_10 ( V_2 ) ;
break;
}
default:
goto V_48;
}
break;
}
case V_47 : {
switch ( V_32 ) {
case V_40 : {
break;
}
case V_45 : {
F_5 ( V_2 ) ;
F_1 ( V_2 ) ;
V_6 -> V_9 = V_41 ;
V_6 -> V_38 = V_50 ;
F_10 ( V_2 ) ;
break;
}
case V_46 : {
V_6 -> V_49 = 1 ;
F_10 ( V_2 ) ;
break;
}
default:
goto V_48;
}
break;
}
case V_37 : {
switch ( V_32 ) {
case V_36 : {
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
F_8 ( V_15 -> V_29 , L_4 ,
V_32 ) ;
return;
V_51:
F_8 ( V_15 -> V_29 , L_5 ,
V_34 , V_32 ) ;
}
void F_11 ( struct V_14 * V_15 ,
const struct V_52 * V_53 )
{
const union V_54 * V_55 = & V_53 -> V_56 . V_6 ;
int V_57 = F_12 ( F_13 ( V_53 -> V_58 ) ) ;
struct V_1 * V_2 = V_15 -> V_57 [ V_57 ] ;
struct V_3 * V_4 = F_14 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_59 = V_53 -> V_56 . V_6 . V_60 . type ;
int V_61 ;
if ( V_59 == V_62 ) {
enum V_31 V_63 =
( ( V_53 -> V_56 . V_6 . V_64 . V_65 &
V_66 )
? V_47
: V_41 ) ;
if ( V_6 -> V_8 != V_67 ) {
V_61 = F_15 (
F_16 (
V_53 -> V_56 . V_6 . V_64 . V_68 ) ) ;
if ( V_61 == V_69 ||
V_61 == V_25 ) {
V_6 -> V_8 = V_61 ;
F_17 ( V_15 -> V_29 , L_6 ,
V_2 -> V_35 ,
V_30 [ V_6 -> V_8 ] ) ;
} else {
F_17 ( V_15 -> V_29 ,
L_7 ,
V_30 [ V_6 -> V_8 ] ,
V_30 [ V_61 ] ) ;
V_6 -> V_8 = V_67 ;
}
}
F_9 ( V_2 , V_63 ) ;
return;
}
if ( V_6 -> V_9 == V_10 ||
V_6 -> V_9 == V_37 ) {
F_8 ( V_15 -> V_29 , L_8 ,
V_6 -> V_9 ) ;
return;
}
switch ( V_59 ) {
case V_70 :
V_6 -> V_60 = F_13 ( V_55 -> V_60 . V_60 ) ;
V_6 -> V_71 |= V_72 ;
break;
case V_73 :
V_6 -> V_74 = V_55 -> V_75 . V_76 ;
memcpy ( V_6 -> V_75 , & V_55 -> V_75 . V_75 ,
sizeof( V_6 -> V_75 ) ) ;
memcpy ( V_6 -> V_77 , & V_55 -> V_75 . V_77 ,
sizeof( V_6 -> V_77 ) ) ;
V_6 -> V_71 |= V_78 ;
if ( V_6 -> V_71 & V_72 )
F_18 ( V_2 , V_6 ) ;
break;
case V_79 :
memcpy ( V_6 -> V_80 , & V_55 -> V_80 . V_81 ,
sizeof( V_6 -> V_80 ) ) ;
V_6 -> V_71 |= V_82 ;
break;
case V_83 :
V_6 -> V_84 = V_55 -> V_85 . V_84 ;
V_6 -> V_86 = V_55 -> V_85 . V_87 ;
V_6 -> V_71 |= V_88 ;
F_18 ( V_2 , V_6 ) ;
break;
case V_89 : {
const struct V_90 * V_91 = & V_55 -> V_22 ;
int V_92 = V_91 -> V_92 ;
struct V_22 * V_93 = & V_6 -> V_22 [ V_92 ] ;
struct V_16 V_17 = {
. V_24 = F_16 ( V_91 -> V_23 ) ,
} ;
int V_19 ;
if ( V_6 -> V_8 == V_25 ) {
V_17 . V_27 = ( V_91 -> V_28 + 1 ) ;
V_17 . V_20 = F_19 ( V_91 -> V_26 ) - 1 ;
V_19 = F_20 ( V_2 , & V_17 ) ;
F_18 ( V_2 , V_6 ) ;
} else {
V_17 . V_27 = ! ! ( V_91 -> V_28 ) ;
V_17 . V_20 = V_91 -> V_26 ;
V_19 = F_7 ( V_2 , & V_17 ) ;
}
if ( V_19 )
F_8 ( V_15 -> V_29 ,
L_9 ,
V_17 . V_27 , V_17 . V_24 , V_17 . V_20 , - V_19 ) ;
V_93 -> V_26 = V_91 -> V_26 ;
V_93 -> V_28 = V_91 -> V_28 ;
V_93 -> V_23 = F_16 ( V_91 -> V_23 ) ;
V_6 -> V_71 |= V_94 ;
break;
}
default:
F_8 ( V_15 -> V_29 , L_10 ,
V_59 ) ;
break;
}
}
static T_1 F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 . V_49 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_1 V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 . V_9 == V_37 ) {
V_4 -> V_6 . V_49 = V_49 ;
return 0 ;
}
if ( V_49 != ( V_4 -> V_6 . V_9 == V_47 ) )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , int V_95 ,
T_1 * V_96 , T_1 * V_60 , T_1 * V_97 ,
T_1 * V_98 , int V_99 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_19 ;
* V_96 = * V_60 = * V_97 = * V_98 = 0 ;
if ( V_99 )
F_24 ( V_53 , V_4 -> V_12 ) ;
else
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_60 . type = V_70 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_11 , - V_19 ) ;
return;
}
* V_60 = ( F_13 ( V_53 . V_56 . V_6 . V_60 . V_60 ) >> ( V_95 * 4 ) ) & 0xf ;
if ( V_99 )
F_24 ( V_53 , V_4 -> V_12 ) ;
else
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_75 . type = V_73 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_12 ,
- V_19 ) ;
return;
}
* V_97 = V_53 . V_56 . V_6 . V_75 . V_75 [ * V_60 ] ;
* V_98 = ( 1 << V_95 ) ;
if ( * V_60 != 0xF )
* V_96 = 0x2 ;
}
static void F_27 ( struct V_1 * V_2 , int V_95 ,
T_1 * V_96 , T_1 * V_60 , T_1 * V_97 ,
T_1 * V_98 )
{
return F_23 ( V_2 , ( 7 - V_95 ) , V_96 , V_60 , V_97 ,
V_98 , 1 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_95 ,
T_1 * V_96 , T_1 * V_60 , T_1 * V_97 ,
T_1 * V_98 )
{
return F_23 ( V_2 , ( 7 - V_95 ) , V_96 , V_60 , V_97 ,
V_98 , 0 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_95 ,
T_1 V_96 , T_1 V_60 , T_1 V_97 ,
T_1 V_98 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_102 = 7 - V_95 ;
T_2 V_103 ;
int V_19 ;
if ( V_60 == V_104 )
return;
if ( V_97 == V_104 )
return;
F_24 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_60 . type = V_70 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_11 , - V_19 ) ;
return;
}
V_103 = F_13 ( V_53 . V_56 . V_6 . V_60 . V_60 ) ;
V_103 &= ~ ( 0xF << ( V_102 * 4 ) ) ;
V_103 |= V_60 << ( V_102 * 4 ) ;
V_53 . V_56 . V_6 . V_60 . V_60 = F_30 ( V_103 ) ;
F_31 ( V_53 , V_4 -> V_12 ) ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_13 ,
- V_19 ) ;
return;
}
memset ( & V_53 , 0 , sizeof( struct V_52 ) ) ;
F_24 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_75 . type = V_73 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_12 ,
- V_19 ) ;
return;
}
V_53 . V_56 . V_6 . V_75 . V_75 [ V_60 ] = V_97 ;
F_31 ( V_53 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_37 )
V_53 . V_58 |= F_30 ( V_105 ) ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 )
F_8 ( V_15 -> V_29 , L_14 ,
- V_19 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_60 , T_1 * V_97 ,
int V_99 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_19 ;
if ( V_99 )
F_24 ( V_53 , V_4 -> V_12 ) ;
else
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_75 . type = V_73 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_12 ,
- V_19 ) ;
return;
}
* V_97 = V_53 . V_56 . V_6 . V_75 . V_75 [ V_60 ] ;
}
static void F_33 ( struct V_1 * V_2 , int V_60 , T_1 * V_97 )
{
return F_32 ( V_2 , V_60 , V_97 , 1 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_60 , T_1 * V_97 )
{
return F_32 ( V_2 , V_60 , V_97 , 0 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_60 ,
T_1 V_97 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_19 ;
F_24 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_75 . type = V_73 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_12 ,
- V_19 ) ;
return;
}
V_53 . V_56 . V_6 . V_75 . V_75 [ V_60 ] = V_97 ;
F_31 ( V_53 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_37 )
V_53 . V_58 |= F_30 ( V_105 ) ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 )
F_8 ( V_15 -> V_29 , L_14 ,
- V_19 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_20 , T_1 * V_106 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_6 -> V_9 != V_47 ||
V_20 >= V_107 )
* V_106 = 0 ;
else
* V_106 = ( V_4 -> V_6 . V_84 >> ( 7 - V_20 ) ) & 1 ;
}
static void F_37 ( struct V_1 * V_2 , int V_20 , T_1 V_106 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_19 ;
if ( V_4 -> V_6 . V_9 != V_47 ||
V_20 >= V_107 )
return;
F_31 ( V_53 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_37 )
V_53 . V_58 |= F_30 ( V_105 ) ;
V_53 . V_56 . V_6 . V_85 . type = V_83 ;
V_53 . V_56 . V_6 . V_85 . V_84 = V_4 -> V_6 . V_84 ;
if ( V_106 )
V_53 . V_56 . V_6 . V_85 . V_84 |= ( 1 << ( 7 - V_20 ) ) ;
else
V_53 . V_56 . V_6 . V_85 . V_84 &= ( ~ ( 1 << ( 7 - V_20 ) ) ) ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_15 , - V_19 ) ;
return;
}
V_4 -> V_6 . V_84 = V_53 . V_56 . V_6 . V_85 . V_84 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_1 F_39 ( struct V_1 * V_2 , int V_108 , T_1 * V_109 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
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
* V_109 = V_4 -> V_6 . V_38 ;
break;
default:
* V_109 = false ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , int V_118 , T_1 * V_119 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_118 ) {
case V_120 :
if ( V_4 -> V_6 . V_71 & V_78 )
* V_119 = V_4 -> V_6 . V_74 ;
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
static int F_41 ( struct V_1 * V_2 , int V_118 , T_1 V_119 )
{
return - V_123 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 . V_9 != V_47 )
return false ;
return V_4 -> V_6 . V_84 != 0 ;
}
static void F_43 ( struct V_1 * V_2 , T_1 V_9 )
{
}
static int F_44 ( struct V_1 * V_2 , T_1 V_124 , T_3 V_125 ,
int V_126 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_18 ;
if ( V_4 -> V_6 . V_9 != V_47 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
struct V_52 V_53 ;
int V_19 ;
if ( V_126 )
F_25 ( V_53 , V_4 -> V_12 ) ;
else
F_24 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_22 . type = V_89 ;
V_53 . V_56 . V_6 . V_22 . V_92 = V_18 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_16 ,
- V_19 ) ;
return V_19 ;
}
if ( F_16 ( V_53 . V_56 . V_6 . V_22 . V_23 ) == V_125 )
if ( V_53 . V_56 . V_6 . V_22 . V_28 == V_124 )
return V_53 . V_56 . V_6 . V_22 . V_26 ;
if ( ! V_53 . V_56 . V_6 . V_22 . V_23 )
break;
}
return - V_127 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_124 , T_3 V_125 )
{
return F_44 ( V_2 , V_124 , V_125 , 0 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_124 , T_3 V_125 ,
T_1 V_128 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_18 , V_19 ;
if ( V_4 -> V_6 . V_9 != V_47 )
return - V_122 ;
if ( ! F_47 ( V_2 ) )
return - V_129 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
F_24 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_22 . type = V_89 ;
V_53 . V_56 . V_6 . V_22 . V_92 = V_18 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_17 ,
- V_19 ) ;
return V_19 ;
}
if ( F_16 ( V_53 . V_56 . V_6 . V_22 . V_23 ) == V_125 ) {
V_53 . V_56 . V_6 . V_22 . V_23 = 0 ;
break;
}
if ( ! V_53 . V_56 . V_6 . V_22 . V_23 )
break;
}
if ( V_18 == V_21 ) {
F_8 ( V_15 -> V_29 , L_18 ) ;
return - V_130 ;
}
F_31 ( V_53 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_37 )
V_53 . V_58 |= F_30 ( V_105 ) ;
V_53 . V_56 . V_6 . V_22 . type = V_89 ;
V_53 . V_56 . V_6 . V_22 . V_23 = F_48 ( V_125 ) ;
V_53 . V_56 . V_6 . V_22 . V_28 = V_124 ;
V_53 . V_56 . V_6 . V_22 . V_26 = V_128 ;
V_53 . V_56 . V_6 . V_22 . V_92 = V_18 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_19 ,
- V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_124 , T_3 V_125 ,
T_1 V_128 )
{
int V_131 ;
struct V_16 V_17 = {
. V_27 = V_124 ,
. V_24 = V_125 ,
. V_20 = V_128 ,
} ;
if ( V_124 != V_132 &&
V_124 != V_133 )
return - V_122 ;
V_131 = F_46 ( V_2 , V_124 == V_132 ?
V_124 : 3 , V_125 , V_128 ) ;
if ( V_131 )
return V_131 ;
return F_7 ( V_2 , & V_17 ) ;
}
static inline int
F_50 ( struct V_1 * V_2 ,
enum V_134 V_135 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_135 && ! ( V_6 -> V_71 & V_135 ) )
return 0 ;
return ( V_6 -> V_9 == V_47 &&
( V_6 -> V_38 & V_43 ) ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_136 * V_137 ,
int V_99 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_14 * V_15 = V_4 -> V_14 ;
T_4 V_138 ;
struct V_52 V_53 ;
int V_18 , V_139 , V_19 ;
if ( ! ( V_6 -> V_71 & ( V_72 | V_78 ) ) )
return 0 ;
V_137 -> V_140 = V_6 -> V_74 ;
if ( V_99 ) {
V_137 -> V_141 = 1 ;
F_24 ( V_53 , V_4 -> V_12 ) ;
} else {
F_25 ( V_53 , V_4 -> V_12 ) ;
}
V_53 . V_56 . V_6 . V_60 . type = V_70 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_11 , - V_19 ) ;
return V_19 ;
}
V_138 = F_13 ( V_53 . V_56 . V_6 . V_60 . V_60 ) ;
if ( V_99 )
F_24 ( V_53 , V_4 -> V_12 ) ;
else
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_75 . type = V_73 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_12 ,
- V_19 ) ;
return V_19 ;
}
for ( V_18 = 0 ; V_18 < V_142 ; V_18 ++ ) {
V_139 = ( V_138 >> ( ( 7 - V_18 ) * 4 ) ) & 0xF ;
V_137 -> V_143 [ V_18 ] = V_139 ;
V_137 -> V_144 [ V_18 ] = V_53 . V_56 . V_6 . V_75 . V_75 [ V_18 ] ;
V_137 -> V_145 [ V_18 ] = V_137 -> V_144 [ V_18 ] ;
V_137 -> V_146 [ V_18 ] = V_53 . V_56 . V_6 . V_75 . V_77 [ V_18 ] ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_136 * V_137 )
{
return F_51 ( V_2 , V_137 , 1 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_147 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
memset ( V_85 , 0 , sizeof( struct V_147 ) ) ;
if ( ! ( V_6 -> V_71 & V_88 ) )
return 0 ;
V_85 -> V_148 = V_6 -> V_86 ;
V_85 -> V_149 = F_54 ( V_6 -> V_84 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_136 * V_137 )
{
return F_51 ( V_2 , V_137 , 0 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_150 ;
if ( ! F_50 ( V_2 , V_94 ) )
return - V_122 ;
if ( ! ( V_17 -> V_27 && V_17 -> V_24 ) )
return - V_122 ;
V_150 = F_44 ( V_2 , V_17 -> V_27 - 1 , V_17 -> V_24 , 0 ) ;
if ( V_150 < 0 )
V_150 = F_57 ( V_2 , V_17 ) ;
V_17 -> V_20 = F_19 ( V_150 ) - 1 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_131 ;
if ( ! F_50 ( V_2 , V_94 ) )
return - V_122 ;
if ( ! ( V_17 -> V_27 && V_17 -> V_24 ) )
return - V_122 ;
if ( ! ( V_17 -> V_27 > V_151 &&
V_17 -> V_27 < V_152 ) )
return - V_122 ;
V_131 = F_46 ( V_2 , V_17 -> V_27 - 1 , V_17 -> V_24 ,
( 1 << V_17 -> V_20 ) ) ;
if ( V_131 )
return V_131 ;
return F_20 ( V_2 , V_17 ) ;
}
static T_1 F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 . V_38 ;
}
static T_1 F_60 ( struct V_1 * V_2 , T_1 V_153 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_153 & ( V_50 | V_39 ) )
!= V_153 )
return 1 ;
if ( V_4 -> V_6 . V_9 != V_47 )
return 1 ;
if ( V_153 != V_4 -> V_6 . V_38 )
return 1 ;
V_4 -> V_6 . V_38 = V_153 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_154 * V_155 , T_3 * V_156 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_18 , V_19 = 0 ;
if ( V_4 -> V_6 . V_9 != V_47 )
return 1 ;
V_155 -> V_141 = 0 ;
V_155 -> error = 0 ;
* V_156 = 0 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_22 . type = V_89 ;
V_53 . V_56 . V_6 . V_22 . V_92 = * V_156 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_17 ,
- V_19 ) ;
return V_19 ;
}
if ( ! V_53 . V_56 . V_6 . V_22 . V_23 )
break;
}
* V_156 = V_18 ;
return V_19 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_16 * V_157 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
int V_18 , V_19 = 0 ;
if ( V_4 -> V_6 . V_9 != V_47 )
return 1 ;
for ( V_18 = 0 ; V_18 < V_21 ; V_18 ++ ) {
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_22 . type = V_89 ;
V_53 . V_56 . V_6 . V_22 . V_92 = V_18 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_17 ,
- V_19 ) ;
return V_19 ;
}
if ( ! V_53 . V_56 . V_6 . V_22 . V_23 )
break;
V_157 [ V_18 ] . V_27 = V_53 . V_56 . V_6 . V_22 . V_28 ;
V_157 [ V_18 ] . V_24 =
F_16 ( V_53 . V_56 . V_6 . V_22 . V_23 ) ;
V_157 [ V_18 ] . V_20 =
F_19 ( V_53 . V_56 . V_6 . V_22 . V_26 ) - 1 ;
}
return V_19 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
struct V_52 V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 = V_4 -> V_14 ;
T_2 V_60 ;
int V_18 , V_19 ;
V_159 -> V_141 = true ;
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_60 . type = V_70 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_11 , - V_19 ) ;
return V_19 ;
}
V_60 = F_13 ( V_53 . V_56 . V_6 . V_60 . V_60 ) ;
for ( V_18 = 0 ; V_18 < V_107 ; V_18 ++ )
V_159 -> V_160 [ 7 - V_18 ] = ( V_60 >> ( V_18 * 4 ) ) & 0xF ;
F_25 ( V_53 , V_4 -> V_12 ) ;
V_53 . V_56 . V_6 . V_75 . type = V_73 ;
V_19 = F_26 ( V_15 , V_15 -> V_100 , & V_53 , sizeof( V_53 ) , & V_53 ) ;
if ( V_19 != V_101 ) {
F_8 ( V_15 -> V_29 , L_12 ,
- V_19 ) ;
return V_19 ;
}
for ( V_18 = 0 ; V_18 < V_107 ; V_18 ++ )
V_159 -> V_161 [ V_18 ] = V_53 . V_56 . V_6 . V_75 . V_75 [ V_18 ] ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_162 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_40 ( V_2 , V_121 , & ( V_85 -> V_163 ) ) ;
V_85 -> V_149 = F_54 ( V_4 -> V_6 . V_84 ) ;
return 0 ;
}
