static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 [ 2 ] = { V_3 , V_4 } ;
struct V_9 V_10 = { . V_11 = V_6 -> V_12 . V_13 , . V_14 = 0 ,
. V_8 = V_8 , . V_15 = 2 } ;
int V_16 = F_2 ( V_6 -> V_17 , & V_10 , 1 ) ;
if ( V_16 != 1 ) {
F_3 ( L_1 , V_3 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 V_18 [] , int V_19 )
{
int V_16 , V_20 ;
for ( V_20 = 0 ; V_20 < V_19 - 1 ; V_20 ++ )
if ( ( V_16 = F_1 ( V_2 , V_18 [ 0 ] + V_20 , V_18 [ V_20 + 1 ] ) ) )
return V_16 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_3 )
{
int V_21 ;
T_1 V_22 [ 1 ] = { V_3 } ;
T_1 V_23 [ 1 ] = { 0 } ;
struct V_9 V_10 [ 2 ] = { { . V_11 = V_6 -> V_12 . V_13 ,
. V_14 = 0 ,
. V_8 = V_22 , . V_15 = 1 } ,
{ . V_11 = V_6 -> V_12 . V_13 ,
. V_14 = V_24 ,
. V_8 = V_23 , . V_15 = 1 } } ;
V_21 = F_2 ( V_6 -> V_17 , V_10 , 2 ) ;
if ( V_21 != 2 ) {
F_3 ( L_2 ,
V_25 , V_3 , V_21 ) ;
return V_21 ;
}
return V_23 [ 0 ] ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_21 ;
T_1 V_3 ;
for ( V_3 = 0 ; ; V_3 ++ ) {
if ( V_3 % 16 == 0 ) {
if ( V_3 )
F_3 ( V_26 L_3 ) ;
F_3 ( V_27 L_4 , V_3 ) ;
}
V_21 = F_5 ( V_6 , V_3 ) ;
if ( V_21 >= 0 )
F_3 ( V_26 L_5 , ( T_1 ) V_21 ) ;
else
F_3 ( V_26 L_6 ) ;
if ( V_3 == 0xff )
break;
}
F_3 ( V_26 L_3 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
enum V_28 V_29 ,
T_2 * V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_31 = 450560 ;
T_4 V_32 ;
T_1 V_33 ;
if ( V_6 -> V_12 . V_31 )
V_31 = V_6 -> V_12 . V_31 ;
switch ( V_29 ) {
case V_34 :
V_33 = 6 ;
break;
case V_35 :
V_33 = 7 ;
break;
case V_36 :
default:
V_33 = 8 ;
break;
}
V_32 = ( T_4 ) 10 * ( 1 << 23 ) / 7 * 125 ;
V_32 = ( V_33 * V_32 ) + V_31 / 2 ;
F_8 ( V_32 , V_31 ) ;
* V_30 = V_32 ;
F_9 ( L_7 ,
V_25 , V_33 , V_31 , * V_30 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_2 * V_37 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_31 = 450560 ;
int V_38 = 361667 ;
int V_39 ;
T_4 V_32 ;
if ( V_6 -> V_12 . V_31 )
V_31 = V_6 -> V_12 . V_31 ;
if ( V_6 -> V_12 . V_38 )
V_38 = V_6 -> V_12 . V_38 ;
if ( V_31 >= V_38 * 2 )
V_39 = V_38 ;
else {
V_39 = V_31 - ( V_38 % V_31 ) ;
if ( V_39 > V_31 / 2 )
V_39 = V_31 - V_39 ;
}
V_32 = ( T_4 ) 65536 * V_39 + V_31 / 2 ;
F_8 ( V_32 , V_31 ) ;
* V_37 = - V_32 ;
F_9 ( L_8 ,
V_25 , V_38 , V_39 , V_31 , - ( int ) V_32 , * V_37 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
static T_1 V_40 [] = { 0x50 , 0x0C , 0x44 } ;
F_4 ( V_2 , V_40 , sizeof( V_40 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_30 , V_37 ;
T_1 V_43 [ 6 ] = { 0x67 } , V_44 = 0 ;
T_2 V_45 = 0 ;
struct V_46 * V_47 = & V_42 -> V_48 . V_49 ;
V_6 -> V_50 = V_42 -> V_50 ;
F_1 ( V_2 , V_51 , 0x80 ) ;
F_13 ( 200 ) ;
F_1 ( V_2 , 0xEA , 0x01 ) ;
F_13 ( 200 ) ;
F_1 ( V_2 , 0xEA , 0x00 ) ;
F_1 ( V_2 , V_52 , 0x28 ) ;
if ( V_47 -> V_53 != V_54 )
V_44 |= ( 1 << 0 ) ;
if ( V_47 -> V_55 != V_56 )
V_44 |= ( 1 << 1 ) ;
F_1 ( V_2 , V_57 , V_44 ) ;
switch ( V_47 -> V_29 ) {
case V_34 :
F_1 ( V_2 , V_58 , 0x97 ) ;
F_1 ( V_2 , 0x64 , 0x34 ) ;
F_1 ( V_2 , 0xcc , 0xdd ) ;
break;
case V_35 :
F_1 ( V_2 , V_58 , 0x86 ) ;
F_1 ( V_2 , 0x64 , 0x35 ) ;
F_1 ( V_2 , 0xcc , 0x73 ) ;
break;
case V_36 :
default:
F_1 ( V_2 , V_58 , 0x75 ) ;
F_1 ( V_2 , 0x64 , 0x36 ) ;
F_1 ( V_2 , 0xcc , 0x73 ) ;
}
F_7 ( V_2 , V_47 -> V_29 , & V_30 ) ;
F_1 ( V_2 , V_59 , F_14 ( V_30 ) ) ;
F_1 ( V_2 , V_60 , F_15 ( V_30 ) ) ;
V_6 -> V_29 = V_47 -> V_29 ;
F_10 ( V_2 , & V_37 ) ;
F_1 ( V_2 , V_61 , F_14 ( V_37 ) ) ;
F_1 ( V_2 , V_62 , F_15 ( V_37 ) ) ;
switch ( V_47 -> V_63 ) {
case V_64 :
V_45 |= ( 1 << 7 ) ;
break;
case V_65 :
V_45 |= ( 2 << 7 ) ;
break;
case V_66 :
V_45 |= ( 3 << 7 ) ;
break;
case V_67 :
V_45 |= ( 4 << 7 ) ;
break;
case V_68 :
case V_69 :
break;
default:
return - V_70 ;
}
switch ( V_47 -> V_71 ) {
case V_64 :
V_45 |= ( 1 << 4 ) ;
break;
case V_65 :
V_45 |= ( 2 << 4 ) ;
break;
case V_66 :
V_45 |= ( 3 << 4 ) ;
break;
case V_67 :
V_45 |= ( 4 << 4 ) ;
break;
case V_68 :
case V_69 :
break;
case V_72 :
if ( V_47 -> V_73 == V_74 ||
V_47 -> V_73 == V_75 )
break;
default:
return - V_70 ;
}
switch ( V_47 -> V_76 ) {
case V_77 :
break;
case V_78 :
case V_79 :
V_45 |= ( 1 << 13 ) ;
break;
case V_80 :
V_45 |= ( 2 << 13 ) ;
break;
default:
return - V_70 ;
}
switch ( V_47 -> V_53 ) {
case V_81 :
case V_54 :
break;
case V_82 :
V_45 |= ( 1 << 0 ) ;
break;
default:
return - V_70 ;
}
switch ( V_47 -> V_55 ) {
case V_83 :
case V_56 :
break;
case V_84 :
V_45 |= ( 1 << 2 ) ;
break;
case V_85 :
V_45 |= ( 2 << 2 ) ;
break;
case V_86 :
V_45 |= ( 3 << 2 ) ;
break;
default:
return - V_70 ;
}
switch ( V_47 -> V_73 ) {
case V_74 :
case V_75 :
break;
case V_87 :
V_45 |= ( 1 << 10 ) ;
break;
case V_88 :
V_45 |= ( 2 << 10 ) ;
break;
case V_89 :
V_45 |= ( 3 << 10 ) ;
break;
default:
return - V_70 ;
}
F_1 ( V_2 , V_90 , F_14 ( V_45 ) ) ;
F_1 ( V_2 , V_91 , F_15 ( V_45 ) ) ;
if ( V_2 -> V_92 . V_93 )
V_2 -> V_92 . V_93 ( V_2 , 0 ) ;
if ( V_6 -> V_12 . V_94 ) {
if ( V_2 -> V_92 . V_95 . V_96 ) {
V_2 -> V_92 . V_95 . V_96 ( V_2 , V_42 ) ;
if ( V_2 -> V_92 . V_93 )
V_2 -> V_92 . V_93 ( V_2 , 0 ) ;
}
} else if ( V_2 -> V_92 . V_95 . V_97 ) {
V_2 -> V_92 . V_95 . V_97 ( V_2 , V_42 , V_43 + 1 , 5 ) ;
V_43 [ 1 ] <<= 1 ;
F_4 ( V_2 , V_43 , sizeof( V_43 ) ) ;
}
F_1 ( V_2 , 0x5F , 0x13 ) ;
if ( V_6 -> V_12 . V_94 || V_2 -> V_92 . V_95 . V_97 == NULL )
F_1 ( V_2 , V_98 , 0x01 ) ;
else
F_1 ( V_2 , V_99 , 0x01 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_46 * V_47 = & V_42 -> V_48 . V_49 ;
int V_100 , V_101 ;
T_2 V_45 ;
static const T_1 V_102 [ 8 ] = {
V_68 ,
V_64 ,
V_65 ,
V_66 ,
V_67 ,
V_69 ,
V_69 ,
V_69
} ;
V_100 = F_5 ( V_6 , V_103 ) ;
V_101 = F_5 ( V_6 , V_104 ) ;
if ( V_100 < 0 || V_101 < 0 )
return - V_105 ;
if ( ( V_100 & ( 1 << 5 ) ) == 0 || ( V_101 & ( 1 << 4 ) ) == 0 )
return - V_70 ;
V_45 = F_5 ( V_6 , V_106 ) << 8 |
F_5 ( V_6 , V_107 ) ;
V_47 -> V_63 = V_102 [ ( V_45 >> 7 ) & 7 ] ;
V_47 -> V_71 = V_102 [ ( V_45 >> 4 ) & 7 ] ;
switch ( ( V_45 >> 13 ) & 3 ) {
case 0 :
V_47 -> V_76 = V_77 ;
break;
case 1 :
V_47 -> V_76 = V_79 ;
break;
case 2 :
V_47 -> V_76 = V_80 ;
break;
default:
V_47 -> V_76 = V_78 ;
break;
}
V_47 -> V_53 = ( V_45 & 0x01 ) ? V_82 :
V_81 ;
switch ( ( V_45 >> 2 ) & 3 ) {
case 0 :
V_47 -> V_55 = V_83 ;
break;
case 1 :
V_47 -> V_55 = V_84 ;
break;
case 2 :
V_47 -> V_55 = V_85 ;
break;
case 3 :
V_47 -> V_55 = V_86 ;
break;
default:
V_47 -> V_55 = V_56 ;
break;
}
switch ( ( V_45 >> 10 ) & 7 ) {
case 0 :
V_47 -> V_73 = V_75 ;
break;
case 1 :
V_47 -> V_73 = V_87 ;
break;
case 2 :
V_47 -> V_73 = V_88 ;
break;
case 3 :
V_47 -> V_73 = V_89 ;
break;
default:
V_47 -> V_73 = V_74 ;
break;
}
V_42 -> V_50 = V_6 -> V_50 ;
V_47 -> V_29 = V_6 -> V_29 ;
V_42 -> V_108 = V_109 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_5 * V_110 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_100 , V_111 , V_112 ;
if ( ( V_100 = F_5 ( V_6 , V_103 ) ) < 0 )
return - V_105 ;
if ( ( V_111 = F_5 ( V_6 , V_113 ) ) < 0 )
return - V_105 ;
if ( ( V_112 = F_5 ( V_6 , V_114 ) ) < 0 )
return - V_105 ;
* V_110 = 0 ;
if ( V_100 & ( 1 << 2 ) )
* V_110 |= V_115 ;
if ( V_100 & ( 1 << 1 ) )
* V_110 |= V_116 ;
if ( V_100 & ( 1 << 5 ) )
* V_110 |= V_117 ;
if ( V_111 & ( 1 << 4 ) )
* V_110 |= V_118 ;
if ( V_112 & ( 1 << 6 ) )
* V_110 |= V_119 ;
if ( ( * V_110 & ( V_115 | V_116 | V_118 ) ) !=
( V_115 | V_116 | V_118 ) )
* V_110 &= ~ V_117 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 * V_120 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_120 = F_5 ( V_6 , V_121 ) << 16 |
F_5 ( V_6 , V_122 ) << 8 |
F_5 ( V_6 , V_123 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 * V_124 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 signal = F_5 ( V_6 , V_125 ) << 10 |
F_5 ( V_6 , V_126 ) << 2 | 3 ;
* V_124 = ~ signal ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 * V_127 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_128 ;
if ( V_129 )
F_6 ( V_2 ) ;
V_128 = F_5 ( V_6 , V_130 ) ;
* V_127 = ( V_128 << 8 ) | V_128 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_3 * V_131 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_132 = 0 ;
V_132 = F_5 ( V_6 , V_133 ) << 8 |
F_5 ( V_6 , V_134 ) ;
V_6 -> V_131 += V_132 ;
* V_131 = V_6 -> V_131 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_135
* V_136 )
{
V_136 -> V_137 = 1000 ;
V_136 -> V_138 = 0 ;
V_136 -> V_139 = 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_140 [ 6 ] = { 0x50 , 0x03 , 0x64 , 0x46 , 0x15 , 0x0F } ;
int V_141 = 0 ;
if ( V_129 )
F_6 ( V_2 ) ;
if ( V_6 -> V_12 . V_142 )
V_140 [ 2 ] &= ~ 0x20 ;
if ( V_6 -> V_12 . V_143 )
V_140 [ 3 ] = V_6 -> V_12 . V_143 ;
if ( V_6 -> V_12 . V_144 )
V_140 [ 4 ] = V_6 -> V_12 . V_144 ;
if ( F_5 ( V_6 , 0x50 ) != V_140 [ 1 ] ||
F_5 ( V_6 , 0x51 ) != V_140 [ 2 ] ) {
V_141 = F_4 ( V_2 , V_140 ,
sizeof( V_140 ) ) ;
if ( V_129 )
F_6 ( V_2 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_145 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 = 0x0a ;
if ( V_6 -> V_12 . V_146 ) {
return 0 ;
}
if ( V_145 )
V_4 |= 0x10 ;
return F_1 ( V_2 , 0x62 , V_4 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_26 ( V_6 ) ;
}
struct V_1 * F_27 ( const struct V_147 * V_12 ,
struct V_148 * V_17 )
{
struct V_5 * V_6 = NULL ;
int V_149 ;
V_6 = F_28 ( sizeof( struct V_5 ) , V_150 ) ;
if ( V_6 == NULL )
goto error;
V_6 -> V_17 = V_17 ;
memcpy ( & V_6 -> V_12 , V_12 , sizeof( struct V_147 ) ) ;
V_149 = F_5 ( V_6 , V_151 ) ;
if ( ( V_149 != V_152 ) && ( V_149 != V_153 ) && ( V_149 != V_154 ) )
goto error;
memcpy ( & V_6 -> V_155 . V_92 , & V_156 , sizeof( struct V_157 ) ) ;
V_6 -> V_155 . V_7 = V_6 ;
return & V_6 -> V_155 ;
error:
F_26 ( V_6 ) ;
return NULL ;
}
