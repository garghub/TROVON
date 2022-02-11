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
void F_5 ( struct V_1 * V_2 ,
enum V_14 V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_16 * V_17 = V_4 -> V_16 ;
enum V_18 V_19 = V_6 -> V_9 ;
F_3 ( V_2 , L_2 ,
V_11 , V_6 -> V_9 , V_15 , V_2 -> V_20 ) ;
switch ( V_19 ) {
case V_10 : {
switch ( V_15 ) {
case V_21 : {
V_6 -> V_9 = V_22 ;
V_6 -> V_23 = V_24 ;
V_6 -> V_25 = 1 ;
break;
}
case V_26 : {
V_6 -> V_9 = V_27 ;
V_6 -> V_23 = V_28 ;
break;
}
case V_29 : {
break;
}
case V_30 : {
V_6 -> V_9 = V_31 ;
break;
}
default:
goto V_32;
}
break;
}
case V_27 : {
switch ( V_15 ) {
case V_26 : {
break;
}
case V_29 : {
break;
}
case V_30 : {
V_6 -> V_9 = V_31 ;
V_6 -> V_25 = 1 ;
F_6 ( V_2 ) ;
break;
}
default:
goto V_32;
}
break;
}
case V_31 : {
switch ( V_15 ) {
case V_26 : {
break;
}
case V_29 : {
F_1 ( V_2 ) ;
V_6 -> V_9 = V_27 ;
V_6 -> V_23 = V_28 ;
F_6 ( V_2 ) ;
break;
}
case V_30 : {
V_6 -> V_25 = 1 ;
F_6 ( V_2 ) ;
break;
}
default:
goto V_32;
}
break;
}
case V_22 : {
switch ( V_15 ) {
case V_21 : {
break;
}
default:
goto V_32;
}
break;
}
default:
goto V_33;
}
return;
V_32:
F_7 ( V_17 -> V_34 , L_3 ,
V_15 ) ;
return;
V_33:
F_7 ( V_17 -> V_34 , L_4 ,
V_19 , V_15 ) ;
}
void F_8 ( struct V_16 * V_17 ,
const struct V_35 * V_36 )
{
const union V_37 * V_38 = & V_36 -> V_39 . V_6 ;
int V_40 = F_9 ( F_10 ( V_36 -> V_41 ) ) ;
struct V_1 * V_2 = V_17 -> V_40 [ V_40 ] ;
struct V_3 * V_4 = F_11 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_42 = V_36 -> V_39 . V_6 . V_43 . type ;
int V_44 ;
if ( V_42 == V_45 ) {
enum V_14 V_46 =
( ( V_36 -> V_39 . V_6 . V_47 . V_48 &
V_49 )
? V_31
: V_27 ) ;
if ( V_6 -> V_8 != V_50 ) {
V_44 = F_12 (
F_13 (
V_36 -> V_39 . V_6 . V_47 . V_51 ) ) ;
if ( V_44 == V_52 ||
V_44 == V_53 ) {
V_6 -> V_8 = V_44 ;
F_14 ( V_17 -> V_34 , L_5 ,
V_2 -> V_20 ,
V_54 [ V_6 -> V_8 ] ) ;
} else {
F_14 ( V_17 -> V_34 ,
L_6 ,
V_54 [ V_6 -> V_8 ] ,
V_54 [ V_44 ] ) ;
V_6 -> V_8 = V_50 ;
}
}
F_5 ( V_2 , V_46 ) ;
return;
}
if ( V_6 -> V_9 == V_10 ||
V_6 -> V_9 == V_22 ) {
F_7 ( V_17 -> V_34 , L_7 ,
V_6 -> V_9 ) ;
return;
}
switch ( V_42 ) {
case V_55 :
V_6 -> V_43 = F_10 ( V_38 -> V_43 . V_43 ) ;
V_6 -> V_56 |= V_57 ;
break;
case V_58 :
V_6 -> V_59 = V_38 -> V_60 . V_61 ;
memcpy ( V_6 -> V_60 , & V_38 -> V_60 . V_60 ,
sizeof( V_6 -> V_60 ) ) ;
memcpy ( V_6 -> V_62 , & V_38 -> V_60 . V_62 ,
sizeof( V_6 -> V_62 ) ) ;
V_6 -> V_56 |= V_63 ;
if ( V_6 -> V_56 & V_57 )
F_15 ( V_2 , V_6 ) ;
break;
case V_64 :
memcpy ( V_6 -> V_65 , & V_38 -> V_65 . V_66 ,
sizeof( V_6 -> V_65 ) ) ;
V_6 -> V_56 |= V_67 ;
break;
case V_68 :
V_6 -> V_69 = V_38 -> V_70 . V_69 ;
V_6 -> V_71 = V_38 -> V_70 . V_72 ;
V_6 -> V_56 |= V_73 ;
F_15 ( V_2 , V_6 ) ;
break;
case V_74 : {
const struct V_75 * V_76 = & V_38 -> V_77 ;
int V_78 = V_76 -> V_78 ;
struct V_77 * V_79 = & V_6 -> V_77 [ V_78 ] ;
struct V_80 V_81 = {
. V_82 = F_13 ( V_76 -> V_83 ) ,
} ;
int V_84 ;
if ( V_6 -> V_8 == V_53 ) {
V_81 . V_85 = ( V_76 -> V_86 + 1 ) ;
V_81 . V_87 = F_16 ( V_76 -> V_88 ) - 1 ;
V_84 = F_17 ( V_2 , & V_81 ) ;
F_15 ( V_2 , V_6 ) ;
} else {
V_81 . V_85 = ! ! ( V_76 -> V_86 ) ;
V_81 . V_87 = V_76 -> V_88 ;
V_84 = F_18 ( V_2 , & V_81 ) ;
}
if ( V_84 )
F_7 ( V_17 -> V_34 ,
L_8 ,
V_81 . V_85 , V_81 . V_82 , V_81 . V_87 , - V_84 ) ;
V_79 -> V_88 = V_76 -> V_88 ;
V_79 -> V_86 = V_76 -> V_86 ;
V_79 -> V_83 = F_13 ( V_76 -> V_83 ) ;
V_6 -> V_56 |= V_89 ;
break;
}
default:
F_7 ( V_17 -> V_34 , L_9 ,
V_42 ) ;
break;
}
}
static T_1 F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 . V_25 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_25 != ( V_4 -> V_6 . V_9 == V_31 ) )
return 1 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_90 ,
T_1 * V_91 , T_1 * V_43 , T_1 * V_92 ,
T_1 * V_93 , int V_94 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_84 ;
* V_91 = * V_43 = * V_92 = * V_93 = 0 ;
if ( V_94 )
F_22 ( V_36 , V_4 -> V_12 ) ;
else
F_23 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_43 . type = V_55 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_10 , - V_84 ) ;
return;
}
* V_43 = ( F_10 ( V_36 . V_39 . V_6 . V_43 . V_43 ) >> ( V_90 * 4 ) ) & 0xf ;
F_23 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_60 . type = V_58 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_11 ,
- V_84 ) ;
return;
}
* V_92 = V_36 . V_39 . V_6 . V_60 . V_60 [ * V_43 ] ;
* V_93 = ( 1 << V_90 ) ;
* V_91 = 0x2 ;
}
static void F_25 ( struct V_1 * V_2 , int V_90 ,
T_1 * V_91 , T_1 * V_43 , T_1 * V_92 ,
T_1 * V_93 )
{
return F_21 ( V_2 , V_90 , V_91 , V_43 , V_92 , V_93 , 1 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_90 ,
T_1 * V_91 , T_1 * V_43 , T_1 * V_92 ,
T_1 * V_93 )
{
return F_21 ( V_2 , V_90 , V_91 , V_43 , V_92 , V_93 , 0 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_90 ,
T_1 V_91 , T_1 V_43 , T_1 V_92 ,
T_1 V_93 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
T_2 V_97 ;
int V_84 ;
if ( V_43 == V_98 )
return;
if ( V_92 == V_98 )
return;
F_22 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_43 . type = V_55 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_10 , - V_84 ) ;
return;
}
V_97 = F_10 ( V_36 . V_39 . V_6 . V_43 . V_43 ) ;
V_97 &= ~ ( 0xF << ( V_90 * 4 ) ) ;
V_97 |= V_43 << ( V_90 * 4 ) ;
V_36 . V_39 . V_6 . V_43 . V_43 = F_28 ( V_97 ) ;
F_29 ( V_36 , V_4 -> V_12 ) ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_12 ,
- V_84 ) ;
return;
}
memset ( & V_36 , 0 , sizeof( struct V_35 ) ) ;
F_22 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_60 . type = V_58 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_11 ,
- V_84 ) ;
return;
}
V_36 . V_39 . V_6 . V_60 . V_60 [ V_43 ] = V_92 ;
F_29 ( V_36 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_22 )
V_36 . V_41 |= F_28 ( V_99 ) ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 )
F_7 ( V_17 -> V_34 , L_13 ,
- V_84 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_43 , T_1 * V_92 ,
int V_94 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_84 ;
if ( V_94 )
F_22 ( V_36 , V_4 -> V_12 ) ;
else
F_23 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_60 . type = V_58 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_11 ,
- V_84 ) ;
return;
}
* V_92 = V_36 . V_39 . V_6 . V_60 . V_60 [ V_43 ] ;
}
static void F_31 ( struct V_1 * V_2 , int V_43 , T_1 * V_92 )
{
return F_30 ( V_2 , V_43 , V_92 , 1 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_43 , T_1 * V_92 )
{
return F_30 ( V_2 , V_43 , V_92 , 0 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_43 ,
T_1 V_92 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_84 ;
F_22 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_60 . type = V_58 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_11 ,
- V_84 ) ;
return;
}
V_36 . V_39 . V_6 . V_60 . V_60 [ V_43 ] = V_92 ;
F_29 ( V_36 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_22 )
V_36 . V_41 |= F_28 ( V_99 ) ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 )
F_7 ( V_17 -> V_34 , L_13 ,
- V_84 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_87 , T_1 * V_100 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_6 -> V_9 != V_31 ||
V_87 >= V_101 )
* V_100 = 0 ;
else
* V_100 = ( V_4 -> V_6 . V_69 >> V_87 ) & 1 ;
}
static void F_35 ( struct V_1 * V_2 , int V_87 , T_1 V_100 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_84 ;
if ( V_4 -> V_6 . V_9 != V_31 ||
V_87 >= V_101 )
return;
F_29 ( V_36 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_22 )
V_36 . V_41 |= F_28 ( V_99 ) ;
V_36 . V_39 . V_6 . V_70 . type = V_68 ;
V_36 . V_39 . V_6 . V_70 . V_69 = V_4 -> V_6 . V_69 ;
if ( V_100 )
V_36 . V_39 . V_6 . V_70 . V_69 |= ( 1 << V_87 ) ;
else
V_36 . V_39 . V_6 . V_70 . V_69 &= ( ~ ( 1 << V_87 ) ) ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_14 , - V_84 ) ;
return;
}
V_4 -> V_6 . V_69 = V_36 . V_39 . V_6 . V_70 . V_69 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_1 F_37 ( struct V_1 * V_2 , int V_102 , T_1 * V_103 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_102 ) {
case V_104 :
case V_105 :
* V_103 = true ;
break;
case V_106 :
* V_103 = 0x80 ;
break;
case V_107 :
* V_103 = 0x80 ;
break;
case V_108 :
* V_103 = true ;
break;
case V_109 :
case V_110 :
* V_103 = false ;
break;
case V_111 :
* V_103 = V_4 -> V_6 . V_23 ;
break;
default:
* V_103 = false ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_112 , T_1 * V_113 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_112 ) {
case V_114 :
if ( V_4 -> V_6 . V_56 & V_63 )
* V_113 = V_4 -> V_6 . V_59 ;
else
* V_113 = 0x8 ;
break;
case V_115 :
* V_113 = 0x8 ;
break;
default:
return - V_116 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_112 , T_1 V_113 )
{
return - V_117 ;
}
static T_1 F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 . V_9 != V_31 )
return false ;
return V_4 -> V_6 . V_69 != 0 ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_9 )
{
}
static int F_42 ( struct V_1 * V_2 , T_1 V_118 , T_3 V_119 ,
int V_120 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_121 ;
if ( V_4 -> V_6 . V_9 != V_31 )
return 0 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
struct V_35 V_36 ;
int V_84 ;
if ( V_120 )
F_23 ( V_36 , V_4 -> V_12 ) ;
else
F_22 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_77 . type = V_74 ;
V_36 . V_39 . V_6 . V_77 . V_78 = V_121 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_15 ,
- V_84 ) ;
return V_84 ;
}
if ( F_13 ( V_36 . V_39 . V_6 . V_77 . V_83 ) == V_119 )
if ( V_36 . V_39 . V_6 . V_77 . V_86 == V_118 )
return V_36 . V_39 . V_6 . V_77 . V_88 ;
if ( ! V_36 . V_39 . V_6 . V_77 . V_83 )
break;
}
return - V_123 ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_118 , T_3 V_119 )
{
return F_42 ( V_2 , V_118 , V_119 , 0 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_118 , T_3 V_119 ,
T_1 V_124 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_121 , V_84 ;
if ( V_4 -> V_6 . V_9 != V_31 )
return - V_116 ;
if ( ! F_45 ( V_2 ) )
return - V_125 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
F_22 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_77 . type = V_74 ;
V_36 . V_39 . V_6 . V_77 . V_78 = V_121 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_16 ,
- V_84 ) ;
return V_84 ;
}
if ( F_13 ( V_36 . V_39 . V_6 . V_77 . V_83 ) == V_119 ) {
V_36 . V_39 . V_6 . V_77 . V_83 = 0 ;
break;
}
if ( ! V_36 . V_39 . V_6 . V_77 . V_83 )
break;
}
if ( V_121 == V_122 ) {
F_7 ( V_17 -> V_34 , L_17 ) ;
return - V_126 ;
}
F_29 ( V_36 , V_4 -> V_12 ) ;
if ( V_4 -> V_6 . V_9 == V_22 )
V_36 . V_41 |= F_28 ( V_99 ) ;
V_36 . V_39 . V_6 . V_77 . type = V_74 ;
V_36 . V_39 . V_6 . V_77 . V_83 = F_46 ( V_119 ) ;
V_36 . V_39 . V_6 . V_77 . V_86 = V_118 ;
V_36 . V_39 . V_6 . V_77 . V_88 = V_124 ;
V_36 . V_39 . V_6 . V_77 . V_78 = V_121 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_18 ,
- V_84 ) ;
return V_84 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_118 , T_3 V_119 ,
T_1 V_124 )
{
int V_127 ;
struct V_80 V_81 = {
. V_85 = V_118 ,
. V_82 = V_119 ,
. V_87 = V_124 ,
} ;
if ( V_118 != V_128 &&
V_118 != V_129 )
return - V_116 ;
V_127 = F_44 ( V_2 , V_118 == V_128 ?
V_118 : 3 , V_119 , V_124 ) ;
if ( V_127 )
return V_127 ;
return F_18 ( V_2 , & V_81 ) ;
}
static inline int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
return ( V_6 -> V_9 == V_31 &&
( V_6 -> V_23 & V_130 ) ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
int V_131 ;
if ( ! F_48 ( V_2 ) )
return - V_116 ;
if ( ! ( V_81 -> V_85 && V_81 -> V_82 ) )
return - V_116 ;
V_131 = F_42 ( V_2 , V_81 -> V_85 - 1 , V_81 -> V_82 , 0 ) ;
if ( V_131 < 0 )
V_131 = F_50 ( V_2 , V_81 ) ;
V_81 -> V_87 = F_16 ( V_131 ) - 1 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
int V_127 ;
if ( ! F_48 ( V_2 ) )
return - V_116 ;
if ( ! ( V_81 -> V_85 && V_81 -> V_82 ) )
return - V_116 ;
if ( ! ( V_81 -> V_85 > V_132 &&
V_81 -> V_85 < V_133 ) )
return - V_116 ;
V_127 = F_44 ( V_2 , V_81 -> V_85 - 1 , V_81 -> V_82 ,
( 1 << V_81 -> V_87 ) ) ;
if ( V_127 )
return V_127 ;
return F_17 ( V_2 , V_81 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_6 . V_23 ;
}
static T_1 F_53 ( struct V_1 * V_2 , T_1 V_134 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ( V_134 & ( V_28 | V_24 ) )
!= V_134 )
return 1 ;
if ( V_4 -> V_6 . V_9 != V_31 )
return 1 ;
if ( V_134 != V_4 -> V_6 . V_23 )
return 1 ;
V_4 -> V_6 . V_23 = V_134 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_135 * V_136 , T_3 * V_137 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_121 , V_84 = 0 ;
if ( V_4 -> V_6 . V_9 != V_31 )
return 1 ;
V_136 -> V_138 = 0 ;
V_136 -> error = 0 ;
* V_137 = 0 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
F_23 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_77 . type = V_74 ;
V_36 . V_39 . V_6 . V_77 . V_78 = * V_137 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_16 ,
- V_84 ) ;
return V_84 ;
}
if ( ! V_36 . V_39 . V_6 . V_77 . V_83 )
break;
}
* V_137 = V_121 ;
return V_84 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_80 * V_139 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
int V_121 , V_84 = 0 ;
if ( V_4 -> V_6 . V_9 != V_31 )
return 1 ;
for ( V_121 = 0 ; V_121 < V_122 ; V_121 ++ ) {
F_23 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_77 . type = V_74 ;
V_36 . V_39 . V_6 . V_77 . V_78 = V_121 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_16 ,
- V_84 ) ;
return V_84 ;
}
if ( ! V_36 . V_39 . V_6 . V_77 . V_83 )
break;
V_139 [ V_121 ] . V_85 = V_36 . V_39 . V_6 . V_77 . V_86 ;
V_139 [ V_121 ] . V_82 =
F_13 ( V_36 . V_39 . V_6 . V_77 . V_83 ) ;
V_139 [ V_121 ] . V_87 =
F_16 ( V_36 . V_39 . V_6 . V_77 . V_88 ) - 1 ;
}
return V_84 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
struct V_35 V_36 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_4 -> V_16 ;
T_2 V_43 ;
int V_121 , V_84 ;
V_141 -> V_138 = true ;
F_23 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_43 . type = V_55 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_10 , - V_84 ) ;
return V_84 ;
}
V_43 = F_10 ( V_36 . V_39 . V_6 . V_43 . V_43 ) ;
for ( V_121 = 0 ; V_121 < V_101 ; V_121 ++ )
V_141 -> V_142 [ V_121 ] = ( V_43 >> ( V_121 * 4 ) ) & 0xF ;
F_23 ( V_36 , V_4 -> V_12 ) ;
V_36 . V_39 . V_6 . V_60 . type = V_58 ;
V_84 = F_24 ( V_17 , V_17 -> V_95 , & V_36 , sizeof( V_36 ) , & V_36 ) ;
if ( V_84 != V_96 ) {
F_7 ( V_17 -> V_34 , L_11 ,
- V_84 ) ;
return V_84 ;
}
for ( V_121 = 0 ; V_121 < V_101 ; V_121 ++ )
V_141 -> V_143 [ V_121 ] = V_36 . V_39 . V_6 . V_60 . V_60 [ V_121 ] ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_144 * V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_2 , V_115 , & ( V_70 -> V_145 ) ) ;
V_70 -> V_146 = V_4 -> V_6 . V_69 ;
return 0 ;
}
