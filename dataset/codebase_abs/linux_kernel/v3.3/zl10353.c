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
T_2 V_28 ,
T_3 * V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_30 = 450560 ;
T_4 V_31 ;
T_1 V_32 = V_28 / 1000000 ;
if ( V_6 -> V_12 . V_30 )
V_30 = V_6 -> V_12 . V_30 ;
V_31 = ( T_4 ) 10 * ( 1 << 23 ) / 7 * 125 ;
V_31 = ( V_32 * V_31 ) + V_30 / 2 ;
F_8 ( V_31 , V_30 ) ;
* V_29 = V_31 ;
F_9 ( L_7 ,
V_25 , V_32 , V_30 , * V_29 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_3 * V_33 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_30 = 450560 ;
int V_34 = 361667 ;
int V_35 ;
T_4 V_31 ;
if ( V_6 -> V_12 . V_30 )
V_30 = V_6 -> V_12 . V_30 ;
if ( V_6 -> V_12 . V_34 )
V_34 = V_6 -> V_12 . V_34 ;
if ( V_30 >= V_34 * 2 )
V_35 = V_34 ;
else {
V_35 = V_30 - ( V_34 % V_30 ) ;
if ( V_35 > V_30 / 2 )
V_35 = V_30 - V_35 ;
}
V_31 = ( T_4 ) 65536 * V_35 + V_30 / 2 ;
F_8 ( V_31 , V_30 ) ;
* V_33 = - V_31 ;
F_9 ( L_8 ,
V_25 , V_34 , V_35 , V_30 , - ( int ) V_31 , * V_33 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
static T_1 V_36 [] = { 0x50 , 0x0C , 0x44 } ;
F_4 ( V_2 , V_36 , sizeof( V_36 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = & V_2 -> V_39 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_29 , V_33 ;
T_1 V_40 [ 6 ] = { 0x67 } , V_41 = 0 ;
T_3 V_42 = 0 ;
V_6 -> V_43 = V_38 -> V_43 ;
F_1 ( V_2 , V_44 , 0x80 ) ;
F_13 ( 200 ) ;
F_1 ( V_2 , 0xEA , 0x01 ) ;
F_13 ( 200 ) ;
F_1 ( V_2 , 0xEA , 0x00 ) ;
F_1 ( V_2 , V_45 , 0x28 ) ;
if ( V_38 -> V_46 != V_47 )
V_41 |= ( 1 << 0 ) ;
if ( V_38 -> V_48 != V_49 )
V_41 |= ( 1 << 1 ) ;
F_1 ( V_2 , V_50 , V_41 ) ;
switch ( V_38 -> V_51 ) {
case 6000000 :
F_1 ( V_2 , V_52 , 0x97 ) ;
F_1 ( V_2 , 0x64 , 0x34 ) ;
F_1 ( V_2 , 0xcc , 0xdd ) ;
break;
case 7000000 :
F_1 ( V_2 , V_52 , 0x86 ) ;
F_1 ( V_2 , 0x64 , 0x35 ) ;
F_1 ( V_2 , 0xcc , 0x73 ) ;
break;
default:
V_38 -> V_51 = 8000000 ;
case 8000000 :
F_1 ( V_2 , V_52 , 0x75 ) ;
F_1 ( V_2 , 0x64 , 0x36 ) ;
F_1 ( V_2 , 0xcc , 0x73 ) ;
}
F_7 ( V_2 , V_38 -> V_51 , & V_29 ) ;
F_1 ( V_2 , V_53 , F_14 ( V_29 ) ) ;
F_1 ( V_2 , V_54 , F_15 ( V_29 ) ) ;
V_6 -> V_28 = V_38 -> V_51 ;
F_10 ( V_2 , & V_33 ) ;
F_1 ( V_2 , V_55 , F_14 ( V_33 ) ) ;
F_1 ( V_2 , V_56 , F_15 ( V_33 ) ) ;
switch ( V_38 -> V_57 ) {
case V_58 :
V_42 |= ( 1 << 7 ) ;
break;
case V_59 :
V_42 |= ( 2 << 7 ) ;
break;
case V_60 :
V_42 |= ( 3 << 7 ) ;
break;
case V_61 :
V_42 |= ( 4 << 7 ) ;
break;
case V_62 :
case V_63 :
break;
default:
return - V_64 ;
}
switch ( V_38 -> V_65 ) {
case V_58 :
V_42 |= ( 1 << 4 ) ;
break;
case V_59 :
V_42 |= ( 2 << 4 ) ;
break;
case V_60 :
V_42 |= ( 3 << 4 ) ;
break;
case V_61 :
V_42 |= ( 4 << 4 ) ;
break;
case V_62 :
case V_63 :
break;
case V_66 :
if ( V_38 -> V_67 == V_68 ||
V_38 -> V_67 == V_69 )
break;
default:
return - V_64 ;
}
switch ( V_38 -> V_70 ) {
case V_71 :
break;
case V_72 :
case V_73 :
V_42 |= ( 1 << 13 ) ;
break;
case V_74 :
V_42 |= ( 2 << 13 ) ;
break;
default:
return - V_64 ;
}
switch ( V_38 -> V_46 ) {
case V_75 :
case V_47 :
break;
case V_76 :
V_42 |= ( 1 << 0 ) ;
break;
default:
return - V_64 ;
}
switch ( V_38 -> V_48 ) {
case V_77 :
case V_49 :
break;
case V_78 :
V_42 |= ( 1 << 2 ) ;
break;
case V_79 :
V_42 |= ( 2 << 2 ) ;
break;
case V_80 :
V_42 |= ( 3 << 2 ) ;
break;
default:
return - V_64 ;
}
switch ( V_38 -> V_67 ) {
case V_68 :
case V_69 :
break;
case V_81 :
V_42 |= ( 1 << 10 ) ;
break;
case V_82 :
V_42 |= ( 2 << 10 ) ;
break;
case V_83 :
V_42 |= ( 3 << 10 ) ;
break;
default:
return - V_64 ;
}
F_1 ( V_2 , V_84 , F_14 ( V_42 ) ) ;
F_1 ( V_2 , V_85 , F_15 ( V_42 ) ) ;
if ( V_2 -> V_86 . V_87 )
V_2 -> V_86 . V_87 ( V_2 , 0 ) ;
if ( V_6 -> V_12 . V_88 ) {
if ( V_2 -> V_86 . V_89 . V_90 ) {
V_2 -> V_86 . V_89 . V_90 ( V_2 ) ;
if ( V_2 -> V_86 . V_87 )
V_2 -> V_86 . V_87 ( V_2 , 0 ) ;
}
} else if ( V_2 -> V_86 . V_89 . V_91 ) {
V_2 -> V_86 . V_89 . V_91 ( V_2 , V_40 + 1 , 5 ) ;
V_40 [ 1 ] <<= 1 ;
F_4 ( V_2 , V_40 , sizeof( V_40 ) ) ;
}
F_1 ( V_2 , 0x5F , 0x13 ) ;
if ( V_6 -> V_12 . V_88 || V_2 -> V_86 . V_89 . V_91 == NULL )
F_1 ( V_2 , V_92 , 0x01 ) ;
else
F_1 ( V_2 , V_93 , 0x01 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = & V_2 -> V_39 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_94 , V_95 ;
T_3 V_42 ;
static const T_1 V_96 [ 8 ] = {
V_62 ,
V_58 ,
V_59 ,
V_60 ,
V_61 ,
V_63 ,
V_63 ,
V_63
} ;
V_94 = F_5 ( V_6 , V_97 ) ;
V_95 = F_5 ( V_6 , V_98 ) ;
if ( V_94 < 0 || V_95 < 0 )
return - V_99 ;
if ( ( V_94 & ( 1 << 5 ) ) == 0 || ( V_95 & ( 1 << 4 ) ) == 0 )
return - V_64 ;
V_42 = F_5 ( V_6 , V_100 ) << 8 |
F_5 ( V_6 , V_101 ) ;
V_38 -> V_57 = V_96 [ ( V_42 >> 7 ) & 7 ] ;
V_38 -> V_65 = V_96 [ ( V_42 >> 4 ) & 7 ] ;
switch ( ( V_42 >> 13 ) & 3 ) {
case 0 :
V_38 -> V_70 = V_71 ;
break;
case 1 :
V_38 -> V_70 = V_73 ;
break;
case 2 :
V_38 -> V_70 = V_74 ;
break;
default:
V_38 -> V_70 = V_72 ;
break;
}
V_38 -> V_46 = ( V_42 & 0x01 ) ? V_76 :
V_75 ;
switch ( ( V_42 >> 2 ) & 3 ) {
case 0 :
V_38 -> V_48 = V_77 ;
break;
case 1 :
V_38 -> V_48 = V_78 ;
break;
case 2 :
V_38 -> V_48 = V_79 ;
break;
case 3 :
V_38 -> V_48 = V_80 ;
break;
default:
V_38 -> V_48 = V_49 ;
break;
}
switch ( ( V_42 >> 10 ) & 7 ) {
case 0 :
V_38 -> V_67 = V_69 ;
break;
case 1 :
V_38 -> V_67 = V_81 ;
break;
case 2 :
V_38 -> V_67 = V_82 ;
break;
case 3 :
V_38 -> V_67 = V_83 ;
break;
default:
V_38 -> V_67 = V_68 ;
break;
}
V_38 -> V_43 = V_6 -> V_43 ;
V_38 -> V_51 = V_6 -> V_28 ;
V_38 -> V_102 = V_103 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_5 * V_104 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_94 , V_105 , V_106 ;
if ( ( V_94 = F_5 ( V_6 , V_97 ) ) < 0 )
return - V_99 ;
if ( ( V_105 = F_5 ( V_6 , V_107 ) ) < 0 )
return - V_99 ;
if ( ( V_106 = F_5 ( V_6 , V_108 ) ) < 0 )
return - V_99 ;
* V_104 = 0 ;
if ( V_94 & ( 1 << 2 ) )
* V_104 |= V_109 ;
if ( V_94 & ( 1 << 1 ) )
* V_104 |= V_110 ;
if ( V_94 & ( 1 << 5 ) )
* V_104 |= V_111 ;
if ( V_105 & ( 1 << 4 ) )
* V_104 |= V_112 ;
if ( V_106 & ( 1 << 6 ) )
* V_104 |= V_113 ;
if ( ( * V_104 & ( V_109 | V_110 | V_112 ) ) !=
( V_109 | V_110 | V_112 ) )
* V_104 &= ~ V_111 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 * V_114 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_114 = F_5 ( V_6 , V_115 ) << 16 |
F_5 ( V_6 , V_116 ) << 8 |
F_5 ( V_6 , V_117 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_3 * V_118 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 signal = F_5 ( V_6 , V_119 ) << 10 |
F_5 ( V_6 , V_120 ) << 2 | 3 ;
* V_118 = ~ signal ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_3 * V_121 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_122 ;
if ( V_123 )
F_6 ( V_2 ) ;
V_122 = F_5 ( V_6 , V_124 ) ;
* V_121 = ( V_122 << 8 ) | V_122 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 * V_125 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_126 = 0 ;
V_126 = F_5 ( V_6 , V_127 ) << 8 |
F_5 ( V_6 , V_128 ) ;
V_6 -> V_125 += V_126 ;
* V_125 = V_6 -> V_125 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_129
* V_130 )
{
V_130 -> V_131 = 1000 ;
V_130 -> V_132 = 0 ;
V_130 -> V_133 = 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_134 [ 6 ] = { 0x50 , 0x03 , 0x64 , 0x46 , 0x15 , 0x0F } ;
int V_135 = 0 ;
if ( V_123 )
F_6 ( V_2 ) ;
if ( V_6 -> V_12 . V_136 )
V_134 [ 2 ] &= ~ 0x20 ;
if ( V_6 -> V_12 . V_137 )
V_134 [ 3 ] = V_6 -> V_12 . V_137 ;
if ( V_6 -> V_12 . V_138 )
V_134 [ 4 ] = V_6 -> V_12 . V_138 ;
if ( F_5 ( V_6 , 0x50 ) != V_134 [ 1 ] ||
F_5 ( V_6 , 0x51 ) != V_134 [ 2 ] ) {
V_135 = F_4 ( V_2 , V_134 ,
sizeof( V_134 ) ) ;
if ( V_123 )
F_6 ( V_2 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_139 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 = 0x0a ;
if ( V_6 -> V_12 . V_140 ) {
return 0 ;
}
if ( V_139 )
V_4 |= 0x10 ;
return F_1 ( V_2 , 0x62 , V_4 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_26 ( V_6 ) ;
}
struct V_1 * F_27 ( const struct V_141 * V_12 ,
struct V_142 * V_17 )
{
struct V_5 * V_6 = NULL ;
int V_143 ;
V_6 = F_28 ( sizeof( struct V_5 ) , V_144 ) ;
if ( V_6 == NULL )
goto error;
V_6 -> V_17 = V_17 ;
memcpy ( & V_6 -> V_12 , V_12 , sizeof( struct V_141 ) ) ;
V_143 = F_5 ( V_6 , V_145 ) ;
if ( ( V_143 != V_146 ) && ( V_143 != V_147 ) && ( V_143 != V_148 ) )
goto error;
memcpy ( & V_6 -> V_149 . V_86 , & V_150 , sizeof( struct V_151 ) ) ;
V_6 -> V_149 . V_7 = V_6 ;
return & V_6 -> V_149 ;
error:
F_26 ( V_6 ) ;
return NULL ;
}
