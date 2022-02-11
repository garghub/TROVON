static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = 0 , . V_6 = V_6 , . V_10 = 2 } ;
F_2 ( L_1 , V_11 , V_3 , V_4 ) ;
V_8 . V_12 = V_2 -> V_13 -> V_14 ;
V_5 = F_3 ( V_2 -> V_15 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_2 ( L_2 ,
V_11 , V_3 , V_4 , V_5 ) ;
F_2 ( L_3 , V_11 ,
V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_5 ;
T_1 V_16 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
struct V_7 V_8 [] = { { . V_9 = 0 , . V_6 = V_16 , . V_10 = 1 } ,
{ . V_9 = V_18 , . V_6 = V_17 , . V_10 = 1 } } ;
F_2 ( L_4 , V_11 , V_3 ) ;
V_8 [ 0 ] . V_12 = V_2 -> V_13 -> V_14 ;
V_8 [ 1 ] . V_12 = V_2 -> V_13 -> V_14 ;
V_5 = F_3 ( V_2 -> V_15 , V_8 , 2 ) ;
if ( V_5 != 2 ) {
F_2 ( L_5 , V_11 , V_3 ,
V_5 ) ;
return - V_19 ;
}
F_2 ( L_3 , V_11 ,
V_3 , V_17 [ 0 ] , V_5 ) ;
return V_17 [ 0 ] ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_20 , int V_4 )
{
int V_21 ;
F_2 ( L_6 , V_11 , V_3 ,
V_20 , V_4 ) ;
V_21 = F_4 ( V_2 , V_3 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = V_21 & ~ V_20 ;
V_21 |= V_4 & 0xff ;
return F_1 ( V_2 , V_3 , V_21 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , unsigned char * V_6 , int V_10 )
{
int V_22 ;
int V_23 ;
F_2 ( L_7 , V_11 , V_3 , V_10 ) ;
V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_10 ; V_22 ++ ) {
V_23 = F_1 ( V_2 , V_3 + V_22 , V_6 [ V_22 ] ) ;
if ( V_23 != 0 )
break;
}
return V_23 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_23 ;
F_2 ( L_8 , V_11 ) ;
V_23 = F_5 ( V_2 , V_24 , 2 , 2 ) ;
F_8 ( 20 ) ;
return V_23 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_2 ( L_8 , V_11 ) ;
return F_5 ( V_2 , V_24 , 2 , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_2 V_25 )
{
static T_1 V_26 [] = { 0x02 , 0x00 , 0x3d , 0x00 , 0x60 , 0x1e , 0xa7 , 0x45 , 0x4f } ;
static T_1 V_27 [] = { 0x02 , 0x00 , 0x37 , 0x00 , 0x4a , 0x2f , 0x6d , 0x76 , 0xdb } ;
static T_1 V_28 [] = { 0x02 , 0x00 , 0x3d , 0x00 , 0x48 , 0x17 , 0x89 , 0xc7 , 0x14 } ;
switch ( V_25 ) {
case V_29 :
F_6 ( V_2 , V_30 , V_26 , sizeof( V_26 ) ) ;
break;
case V_31 :
F_6 ( V_2 , V_30 , V_27 , sizeof( V_27 ) ) ;
break;
case V_32 :
F_6 ( V_2 , V_30 , V_28 , sizeof( V_28 ) ) ;
break;
default:
return - V_19 ;
}
F_1 ( V_2 , V_33 , 0 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_25 )
{
static T_1 V_34 [] = { 0x7b , 0x2e , 0x11 , 0xf0 , 0xd2 } ;
static T_1 V_35 [] = { 0x6a , 0x02 , 0x6a , 0x43 , 0x9f } ;
static T_1 V_36 [] = { 0x5c , 0x32 , 0xc2 , 0x96 , 0x6d } ;
static T_1 V_37 [] = { 0x70 , 0x02 , 0x49 , 0x24 , 0x92 } ;
static T_1 V_38 [] = { 0x60 , 0x02 , 0xaa , 0xaa , 0xab } ;
static T_1 V_39 [] = { 0x54 , 0x03 , 0x0c , 0x30 , 0xc3 } ;
int V_40 ;
if ( ( V_2 -> V_13 -> V_41 == V_42 ) ||
( V_2 -> V_13 -> V_41 == V_43 ) )
V_40 = 0 ;
else
V_40 = 1 ;
switch ( V_25 ) {
case V_29 :
if ( V_40 )
F_6 ( V_2 , V_44 , V_34 ,
sizeof( V_34 ) ) ;
else
F_6 ( V_2 , V_44 , V_37 ,
sizeof( V_37 ) ) ;
if ( V_2 -> V_13 -> V_41 == V_42 ) {
F_1 ( V_2 , V_45 , 0x0a ) ;
F_1 ( V_2 , V_46 , 0xab ) ;
}
break;
case V_31 :
if ( V_40 )
F_6 ( V_2 , V_44 , V_35 ,
sizeof( V_35 ) ) ;
else
F_6 ( V_2 , V_44 , V_38 ,
sizeof( V_38 ) ) ;
if ( V_2 -> V_13 -> V_41 == V_42 ) {
F_1 ( V_2 , V_45 , 0x0c ) ;
F_1 ( V_2 , V_46 , 0x00 ) ;
}
break;
case V_32 :
if ( V_40 )
F_6 ( V_2 , V_44 , V_36 ,
sizeof( V_36 ) ) ;
else
F_6 ( V_2 , V_44 , V_39 ,
sizeof( V_39 ) ) ;
if ( V_2 -> V_13 -> V_41 == V_42 ) {
F_1 ( V_2 , V_45 , 0x0d ) ;
F_1 ( V_2 , V_46 , 0x55 ) ;
}
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
const unsigned char * V_47 , unsigned int V_10 ,
T_1 V_48 , T_1 V_49 )
{
T_1 V_6 [ 65 ] ;
struct V_7 V_50 = { . V_9 = 0 , . V_6 = V_6 , . V_10 = 0 } ;
int V_51 ;
int V_52 = 0 ;
F_1 ( V_2 , V_48 , 0 ) ;
V_50 . V_12 = V_2 -> V_13 -> V_14 ;
V_6 [ 0 ] = V_49 ;
while ( V_52 != V_10 ) {
V_51 = V_10 - V_52 ;
if ( V_51 > 0x10 )
V_51 = 0x10 ;
memcpy ( V_6 + 1 , V_47 + V_52 , V_51 ) ;
V_50 . V_10 = V_51 + 1 ;
if ( F_3 ( V_2 -> V_15 , & V_50 , 1 ) != 1 ) {
F_13 ( V_53 L_9 ) ;
return - V_54 ;
}
V_52 += V_51 ;
F_2 ( L_10 , V_11 , V_52 ) ;
}
F_8 ( 100 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_55 , V_56 ;
unsigned long V_57 ;
if ( V_2 -> V_58 == V_59 ) {
V_57 = V_60 + 2 * V_61 ;
while( ! ( F_4 ( V_2 , V_62 ) & 0x20 ) ) {
if ( F_15 ( V_60 , V_57 ) ) {
F_13 ( V_53 L_11 ) ;
break;
}
F_8 ( 1 ) ;
}
} else
F_8 ( 100 ) ;
F_5 ( V_2 , V_24 , 0x10 , 0 ) ;
F_1 ( V_2 , V_63 , 0x67 ) ;
V_55 = F_4 ( V_2 , V_64 ) ;
V_56 = F_4 ( V_2 , V_65 ) ;
if ( V_55 != 0x67 || V_56 < 0x20 || V_56 > 0x2e ) {
F_13 ( V_66 L_12 , V_56 ) ;
return - V_54 ;
}
F_13 ( V_66 L_13 , V_56 ) ;
return 0 ;
}
static int F_16 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_5 ;
const struct V_70 * V_71 ;
if ( F_14 ( V_2 ) == 0 )
return 0 ;
F_13 ( V_66 L_14 , V_72 ) ;
V_5 = V_2 -> V_13 -> V_73 ( V_68 , & V_71 , V_72 ) ;
if ( V_5 ) {
F_13 ( V_53 L_15 ) ;
return V_5 ;
}
F_5 ( V_2 , V_24 , 0x10 , 0 ) ;
F_5 ( V_2 , V_24 , 8 , 8 ) ;
F_5 ( V_2 , V_24 , 8 , 0 ) ;
F_8 ( 10 ) ;
F_10 ( V_2 , V_32 ) ;
V_5 = F_12 ( V_2 , V_71 -> V_4 , V_71 -> V_74 , V_75 , V_76 ) ;
F_17 ( V_71 ) ;
if ( V_5 )
return V_5 ;
F_13 ( V_66 L_16 ) ;
F_8 ( 100 ) ;
return F_14 ( V_2 ) ;
}
static void F_18 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_40 ;
if ( ( V_2 -> V_13 -> V_41 == V_42 ) ||
( V_2 -> V_13 -> V_41 == V_43 ) )
V_40 = 0 ;
else
V_40 = 1 ;
F_1 ( V_2 , V_77 , 0xf0 ) ;
if( V_40 ) {
F_13 ( V_66 L_17 ) ;
F_1 ( V_2 , V_78 , 0x08 ) ;
} else {
F_13 ( V_66 L_18 ) ;
F_1 ( V_2 , V_78 , 0x03 ) ;
}
if ( V_2 -> V_13 -> V_79 == V_80 ) {
F_2 ( L_19 , V_11 ) ;
F_1 ( V_2 , V_81 , 0 ) ;
} else {
F_2 ( L_20 , V_11 ) ;
F_1 ( V_2 , V_81 , 3 ) ;
}
if( V_40 )
F_1 ( V_2 , V_82 , 0x67 ) ;
else
F_1 ( V_2 , V_82 , 0x72 ) ;
switch ( V_2 -> V_13 -> V_41 ) {
case V_42 :
F_1 ( V_2 , V_45 , 0x0c ) ;
F_1 ( V_2 , V_46 , 0x00 ) ;
break;
case V_43 :
F_1 ( V_2 , V_45 , 0x0d ) ;
F_1 ( V_2 , V_46 , 0xc7 ) ;
break;
case V_83 :
F_1 ( V_2 , V_45 , 0xd7 ) ;
F_1 ( V_2 , V_46 , 0x59 ) ;
break;
case V_84 :
F_1 ( V_2 , V_45 , 0xd7 ) ;
F_1 ( V_2 , V_46 , 0x3f ) ;
break;
}
F_11 ( V_2 , V_32 ) ;
F_8 ( 120 ) ;
}
static int F_19 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_5 , V_85 ;
const struct V_70 * V_71 ;
if ( V_2 -> V_13 -> V_79 == V_80 ) {
V_85 = 0 ;
} else {
F_2 ( L_21 , V_11 ) ;
V_85 = 0x80 ;
}
F_1 ( V_2 , V_24 , V_85 ) ;
F_5 ( V_2 , V_86 , 1 , 0 ) ;
if ( V_2 -> V_13 -> V_87 != V_88 ) {
F_1 ( V_2 , V_89 , 0x33 ) ;
F_5 ( V_2 , V_90 , 0x0f , V_2 -> V_13 -> V_87 & 0x0f ) ;
}
F_8 ( 10 ) ;
F_18 ( V_68 ) ;
F_5 ( V_2 , V_91 , 0xc0 , 0 ) ;
if ( F_14 ( V_2 ) == 0 )
return 0 ;
F_13 ( V_66 L_22 ) ;
F_1 ( V_2 , V_24 , 4 ) ;
F_8 ( 300 ) ;
F_1 ( V_2 , V_24 , V_85 ) ;
if ( F_14 ( V_2 ) == 0 )
return 0 ;
if ( V_2 -> V_13 -> V_73 != NULL ) {
F_13 ( V_66 L_23 ) ;
V_5 = V_2 -> V_13 -> V_73 ( V_68 , & V_71 , V_92 ) ;
if ( V_5 ) {
V_5 = V_2 -> V_13 -> V_73 ( V_68 , & V_71 , V_72 ) ;
if ( V_5 ) {
F_13 ( V_53 L_15 ) ;
return V_5 ;
} else {
F_13 ( V_66 L_24 ,
V_92 ) ;
}
}
} else {
F_13 ( V_53 L_25 ) ;
return - V_54 ;
}
F_5 ( V_2 , V_24 , 8 , 8 ) ;
V_5 = F_12 ( V_2 , V_71 -> V_4 , V_71 -> V_74 , V_93 , V_94 ) ;
F_17 ( V_71 ) ;
return F_14 ( V_2 ) ;
}
static int F_20 ( int V_95 )
{
switch ( V_95 ) {
case V_96 :
return 0 ;
case V_97 :
return 1 ;
case V_98 :
return 2 ;
case V_99 :
return 3 ;
case V_100 :
return 4 ;
}
return - V_19 ;
}
static int F_21 ( int V_101 )
{
switch ( V_101 ) {
case 0 :
return V_96 ;
case 1 :
return V_97 ;
case 2 :
return V_98 ;
case 3 :
return V_99 ;
case 4 :
return V_100 ;
}
return - 1 ;
}
static int F_22 ( struct V_67 * V_68 , const T_1 V_6 [] , int V_10 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
if ( V_10 != 2 )
return - V_19 ;
return F_1 ( V_2 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
}
static int F_23 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
F_2 ( L_8 , V_11 ) ;
if ( F_16 ( V_68 ) ) {
F_13 ( L_26 ) ;
return - V_54 ;
}
F_5 ( V_2 , V_102 , 0x10 , 0 ) ;
F_5 ( V_2 , V_24 , 0x20 , 0 ) ;
F_5 ( V_2 , V_103 , 8 , 0 ) ;
F_5 ( V_2 , V_104 , 0x40 , 0 ) ;
F_5 ( V_2 , V_104 , 0x80 , 0x80 ) ;
F_5 ( V_2 , V_103 , 0x10 , 0x10 ) ;
F_5 ( V_2 , V_105 , 0xC0 , 0x0 ) ;
F_1 ( V_2 , V_106 , 0 ) ;
F_1 ( V_2 , V_107 , 0 ) ;
F_5 ( V_2 , V_108 , 0xe0 , 0xa0 ) ;
F_5 ( V_2 , V_104 , 0x10 , 0 ) ;
F_1 ( V_2 , V_102 , 0x2e ) ;
F_5 ( V_2 , 0x1f , 0x01 , V_2 -> V_13 -> V_109 ) ;
return 0 ;
}
static int F_24 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
F_2 ( L_8 , V_11 ) ;
if ( F_19 ( V_68 ) ) {
F_13 ( L_26 ) ;
return - V_54 ;
}
F_5 ( V_2 , V_24 , 0x20 , 0 ) ;
F_1 ( V_2 , V_103 , 0x87 ) ;
F_1 ( V_2 , V_104 , 0x88 ) ;
switch ( V_2 -> V_13 -> V_110 ) {
case V_111 :
F_1 ( V_2 , V_112 , 0x00 ) ;
F_5 ( V_2 , V_90 , 0xf0 , 0x60 ) ;
break;
case V_113 :
F_1 ( V_2 , V_112 , 0x0a ) ;
F_5 ( V_2 , V_90 , 0xf0 , 0x60 ) ;
break;
case V_114 :
F_1 ( V_2 , V_112 , 0x0a ) ;
F_5 ( V_2 , V_90 , 0xf0 , 0x00 ) ;
break;
case V_115 :
F_1 ( V_2 , V_112 , 0x02 ) ;
F_1 ( V_2 , V_116 , 0x70 ) ;
F_1 ( V_2 , V_117 , 0x08 ) ;
F_5 ( V_2 , V_90 , 0xf0 , 0x60 ) ;
break;
}
if ( V_2 -> V_13 -> V_118 == 0 ) {
F_5 ( V_2 , V_86 , 0xc0 , 0x40 ) ;
F_5 ( V_2 , 0x3a , 0x80 , V_2 -> V_13 -> V_109 << 7 ) ;
} else {
F_5 ( V_2 , V_86 , 0xc0 , 0x80 ) ;
F_5 ( V_2 , V_90 , 0x10 ,
V_2 -> V_13 -> V_109 << 4 ) ;
}
F_1 ( V_2 , V_91 , 0x38 ) ;
F_5 ( V_2 , V_86 , 0x3e , 0x38 ) ;
F_1 ( V_2 , V_119 , 0 ) ;
F_1 ( V_2 , V_120 , 0xff ) ;
F_1 ( V_2 , V_121 , 0 ) ;
F_1 ( V_2 , V_122 , 0xff ) ;
F_1 ( V_2 , V_123 , 0x12 ) ;
F_1 ( V_2 , V_124 , 0x1a ) ;
F_1 ( V_2 , V_106 , 7 ) ;
F_1 ( V_2 , V_107 , 0xc0 ) ;
return 0 ;
}
static int F_25 ( struct V_67 * V_68 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_127 ;
int V_128 ;
F_2 ( L_8 , V_11 ) ;
if ( V_2 -> V_58 == V_59 ) {
F_5 ( V_2 , V_103 , 0x10 , 0x10 ) ;
F_5 ( V_2 , V_129 , 0x80 , 0 ) ;
F_5 ( V_2 , V_105 , 0xC0 , 0 ) ;
F_5 ( V_2 , V_112 , 4 , 0 ) ;
}
if ( V_68 -> V_130 . V_131 . V_132 ) {
V_68 -> V_130 . V_131 . V_132 ( V_68 , V_126 ) ;
if ( V_68 -> V_130 . V_133 )
V_68 -> V_130 . V_133 ( V_68 , 0 ) ;
}
if ( V_2 -> V_58 == V_134 ) {
V_126 -> V_135 . V_136 . V_137 = V_138 ;
V_126 -> V_135 . V_136 . V_139 = V_140 ;
V_126 -> V_135 . V_136 . V_141 = V_142 ;
}
if ( ( V_126 -> V_135 . V_136 . V_137 == V_138 ) ||
( V_126 -> V_135 . V_136 . V_143 == V_138 ) ||
( V_126 -> V_135 . V_136 . V_144 == V_145 ) ||
( V_126 -> V_135 . V_136 . V_146 == V_147 ) ) {
F_5 ( V_2 , V_103 , 1 , 1 ) ;
F_5 ( V_2 , V_129 , 0x03 , 0 ) ;
F_5 ( V_2 , V_129 , 0x60 , 0 ) ;
F_5 ( V_2 , V_105 , 0x3f , 0 ) ;
} else {
F_5 ( V_2 , V_103 , 1 , 0 ) ;
V_127 = F_20 ( V_126 -> V_135 . V_136 . V_137 ) ;
if ( V_127 < 0 )
return V_127 ;
F_5 ( V_2 , V_105 , 7 , V_127 ) ;
V_127 = F_20 ( V_126 -> V_135 . V_136 . V_143 ) ;
if ( V_127 < 0 )
return V_127 ;
F_5 ( V_2 , V_105 , 0x38 , V_127 << 3 ) ;
switch ( V_126 -> V_135 . V_136 . V_144 ) {
case V_148 :
F_5 ( V_2 , V_129 , 3 , 0 ) ;
break;
case V_149 :
F_5 ( V_2 , V_129 , 3 , 1 ) ;
break;
case V_150 :
F_5 ( V_2 , V_129 , 3 , 2 ) ;
break;
default:
return - V_19 ;
}
switch ( V_126 -> V_135 . V_136 . V_146 ) {
case V_151 :
F_5 ( V_2 , V_129 , 0x60 , 0 << 5 ) ;
break;
case V_152 :
F_5 ( V_2 , V_129 , 0x60 , 1 << 5 ) ;
break;
case V_153 :
F_5 ( V_2 , V_129 , 0x60 , 2 << 5 ) ;
break;
case V_154 :
F_5 ( V_2 , V_129 , 0x60 , 3 << 5 ) ;
break;
default:
return - V_19 ;
}
}
switch ( V_2 -> V_58 ) {
case V_134 :
F_10 ( V_2 , V_126 -> V_135 . V_136 . V_25 ) ;
break;
case V_59 :
F_11 ( V_2 , V_126 -> V_135 . V_136 . V_25 ) ;
break;
}
V_128 = V_126 -> V_128 ;
if ( V_2 -> V_13 -> V_155 )
V_128 = V_128 ? V_156 : V_157 ;
switch ( V_128 ) {
case V_156 :
F_5 ( V_2 , V_104 , 0x20 , 0 ) ;
break;
case V_157 :
F_5 ( V_2 , V_104 , 0x20 , 0x20 ) ;
break;
default:
return - V_19 ;
}
switch ( V_126 -> V_135 . V_136 . V_139 ) {
case V_158 :
F_5 ( V_2 , V_103 , 2 , 0 ) ;
F_5 ( V_2 , V_129 , 0x0c , 0 << 2 ) ;
break;
case V_159 :
F_5 ( V_2 , V_103 , 2 , 0 ) ;
F_5 ( V_2 , V_129 , 0x0c , 1 << 2 ) ;
break;
case V_160 :
F_5 ( V_2 , V_103 , 2 , 0 ) ;
F_5 ( V_2 , V_129 , 0x0c , 2 << 2 ) ;
break;
case V_161 :
F_5 ( V_2 , V_103 , 2 , 0 ) ;
F_5 ( V_2 , V_129 , 0x0c , 3 << 2 ) ;
break;
case V_140 :
F_5 ( V_2 , V_103 , 2 , 2 ) ;
F_5 ( V_2 , V_129 , 0x0c , 0 << 2 ) ;
break;
default:
return - V_19 ;
}
switch ( V_126 -> V_135 . V_136 . V_141 ) {
case V_162 :
F_5 ( V_2 , V_103 , 4 , 0 ) ;
F_5 ( V_2 , V_129 , 0x10 , 0 << 4 ) ;
break;
case V_163 :
F_5 ( V_2 , V_103 , 4 , 0 ) ;
F_5 ( V_2 , V_129 , 0x10 , 1 << 4 ) ;
break;
case V_142 :
F_5 ( V_2 , V_103 , 4 , 4 ) ;
F_5 ( V_2 , V_129 , 0x10 , 0 ) ;
break;
default:
return - V_19 ;
}
switch ( V_2 -> V_58 ) {
case V_134 :
F_5 ( V_2 , V_24 , 8 , 8 ) ;
F_5 ( V_2 , V_24 , 8 , 0 ) ;
break;
case V_59 :
F_5 ( V_2 , V_103 , 0x40 , 0x40 ) ;
F_8 ( 1 ) ;
F_5 ( V_2 , V_112 , 4 , 1 ) ;
break;
}
F_8 ( 10 ) ;
return 0 ;
}
static int F_26 ( struct V_67 * V_68 , struct V_125 * V_126 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
F_2 ( L_8 , V_11 ) ;
V_126 -> V_128 = V_156 ;
if ( F_4 ( V_2 , V_104 ) & 0x20 )
V_126 -> V_128 = V_157 ;
if ( V_2 -> V_13 -> V_155 )
V_126 -> V_128 = V_126 -> V_128 ? V_156 : V_157 ;
switch ( V_2 -> V_58 ) {
case V_134 :
switch ( F_4 ( V_2 , V_164 ) ) {
case 0x14 :
V_126 -> V_135 . V_136 . V_25 = V_32 ;
break;
case 0xdb :
V_126 -> V_135 . V_136 . V_25 = V_31 ;
break;
case 0x4f :
V_126 -> V_135 . V_136 . V_25 = V_29 ;
break;
}
break;
case V_59 :
switch ( F_4 ( V_2 , V_44 ) ) {
case 0x5c :
case 0x54 :
V_126 -> V_135 . V_136 . V_25 = V_32 ;
break;
case 0x6a :
case 0x60 :
V_126 -> V_135 . V_136 . V_25 = V_31 ;
break;
case 0x7b :
case 0x70 :
V_126 -> V_135 . V_136 . V_25 = V_29 ;
break;
}
break;
}
V_126 -> V_135 . V_136 . V_137 =
F_21 ( F_4 ( V_2 , V_165 ) & 7 ) ;
V_126 -> V_135 . V_136 . V_143 =
F_21 ( ( F_4 ( V_2 , V_165 ) >> 3 ) & 7 ) ;
switch ( F_4 ( V_2 , V_166 ) & 3 ) {
case 0 :
V_126 -> V_135 . V_136 . V_144 = V_148 ;
break;
case 1 :
V_126 -> V_135 . V_136 . V_144 = V_149 ;
break;
case 2 :
V_126 -> V_135 . V_136 . V_144 = V_150 ;
break;
}
V_126 -> V_135 . V_136 . V_141 = V_162 ;
if ( F_4 ( V_2 , V_166 ) & 0x10 )
V_126 -> V_135 . V_136 . V_141 = V_163 ;
switch ( ( F_4 ( V_2 , V_166 ) & 0x0c ) >> 2 ) {
case 0 :
V_126 -> V_135 . V_136 . V_139 = V_158 ;
break;
case 1 :
V_126 -> V_135 . V_136 . V_139 = V_159 ;
break;
case 2 :
V_126 -> V_135 . V_136 . V_139 = V_160 ;
break;
case 3 :
V_126 -> V_135 . V_136 . V_139 = V_161 ;
break;
}
switch ( ( F_4 ( V_2 , V_166 ) & 0x60 ) >> 5 ) {
case 0 :
V_126 -> V_135 . V_136 . V_146 = V_151 ;
break;
case 1 :
V_126 -> V_135 . V_136 . V_146 = V_152 ;
break;
case 2 :
V_126 -> V_135 . V_136 . V_146 = V_153 ;
break;
case 3 :
V_126 -> V_135 . V_136 . V_146 = V_154 ;
break;
}
return 0 ;
}
static int F_27 ( struct V_67 * V_68 , T_3 * V_167 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_168 ;
int V_169 ;
int V_170 ;
F_2 ( L_8 , V_11 ) ;
V_168 = F_4 ( V_2 , V_62 ) ;
if ( V_168 == - 1 )
return - V_54 ;
* V_167 = 0 ;
if ( V_168 & 4 )
* V_167 |= V_171 ;
if ( V_168 & 2 )
* V_167 |= V_172 ;
if ( V_168 & 8 )
* V_167 |= V_173 | V_174 | V_175 ;
if ( ! ( * V_167 & V_173 ) ) {
V_169 = F_4 ( V_2 , V_176 ) ;
if ( V_169 == - 1 )
return - V_54 ;
V_168 = F_4 ( V_2 , V_177 ) ;
if ( V_168 == - 1 )
return - V_54 ;
V_169 |= ( V_168 << 8 ) ;
F_4 ( V_2 , V_178 ) ;
if ( V_169 != 65535 )
* V_167 |= V_173 ;
}
if ( ( * V_167 & V_173 ) && ( ! ( * V_167 & V_174 ) ) ) {
V_170 = F_4 ( V_2 , V_179 ) ;
if ( V_170 == - 1 )
return - V_54 ;
V_168 = F_4 ( V_2 , V_180 ) ;
if ( V_168 == - 1 )
return - V_54 ;
V_170 |= ( V_168 << 8 ) ;
V_168 = F_4 ( V_2 , V_108 ) ;
if ( V_168 == - 1 )
return - V_54 ;
V_170 |= ( V_168 & 0x0f ) << 16 ;
F_4 ( V_2 , V_181 ) ;
if ( V_170 < 16632 )
* V_167 |= V_174 ;
}
F_2 ( L_27 , V_11 , * V_167 ) ;
return 0 ;
}
static int F_28 ( struct V_67 * V_68 , T_4 * signal )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_127 ;
int V_3 = 0 ;
F_2 ( L_8 , V_11 ) ;
switch ( V_2 -> V_58 ) {
case V_134 :
V_3 = V_182 ;
break;
case V_59 :
V_3 = V_183 ;
break;
}
V_127 = F_4 ( V_2 , V_3 ) ;
if ( V_127 < 0 )
return - V_54 ;
* signal = ( V_127 << 8 ) | V_127 ;
F_2 ( L_28 , V_11 , * signal ) ;
return 0 ;
}
static int F_29 ( struct V_67 * V_68 , T_4 * V_184 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_127 ;
F_2 ( L_8 , V_11 ) ;
V_127 = F_4 ( V_2 , V_185 ) ;
if ( V_127 < 0 )
return - V_54 ;
V_127 = 255 - V_127 ;
* V_184 = ( ( V_127 << 8 ) | V_127 ) ;
F_2 ( L_29 , V_11 , * V_184 ) ;
return 0 ;
}
static int F_30 ( struct V_67 * V_68 , T_5 * V_186 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_127 ;
int V_187 ;
int V_188 ;
F_2 ( L_8 , V_11 ) ;
V_188 = 0 ;
V_127 = F_4 ( V_2 , V_189 ) ;
if ( V_127 < 0 )
return - V_54 ;
V_127 &= 0x7f ;
while ( V_188 ++ < 5 ) {
F_5 ( V_2 , V_189 , 0x80 , 0 ) ;
F_5 ( V_2 , V_189 , 0x80 , 0 ) ;
F_5 ( V_2 , V_189 , 0x80 , 0 ) ;
V_187 = F_4 ( V_2 , V_189 ) ;
if ( V_187 < 0 )
return - V_54 ;
V_187 &= 0x7f ;
if ( ( V_187 < V_127 ) || ( V_187 == 0 ) )
break;
}
if ( V_127 != 0x7f )
* V_186 = V_127 ;
else
* V_186 = 0xffffffff ;
F_2 ( L_30 , V_11 , * V_186 ) ;
return 0 ;
}
static int F_31 ( struct V_67 * V_68 , T_5 * V_190 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_127 ;
F_2 ( L_8 , V_11 ) ;
V_127 = F_4 ( V_2 , V_176 ) ;
if ( V_127 < 0 )
return - V_54 ;
* V_190 = V_127 << 1 ;
V_127 = F_4 ( V_2 , V_177 ) ;
if ( V_127 < 0 )
return - V_54 ;
* V_190 |= ( V_127 << 9 ) ;
F_4 ( V_2 , V_178 ) ;
F_2 ( L_31 , V_11 , * V_190 ) ;
return 0 ;
}
static int F_32 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
int V_191 ;
switch ( V_2 -> V_58 ) {
case V_134 :
F_5 ( V_2 , V_102 , 0x10 , 0x10 ) ;
break;
case V_59 :
F_1 ( V_2 , V_86 , 0xff ) ;
V_191 = V_2 -> V_13 -> V_87 ;
if ( V_191 >= V_192 )
F_5 ( V_2 , V_90 , 0x0f ,
( V_191 & 0x0f ) ^ 0x0a ) ;
F_5 ( V_2 , V_91 , 0xc0 , 0xc0 ) ;
F_5 ( V_2 , V_24 , 1 , 1 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_67 * V_68 , int V_193 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
if ( V_193 ) {
return F_7 ( V_2 ) ;
} else {
return F_9 ( V_2 ) ;
}
}
static int F_34 ( struct V_67 * V_68 , struct V_194 * V_195 )
{
V_195 -> V_196 = 800 ;
V_195 -> V_197 = 0 ;
V_195 -> V_198 = 0 ;
return 0 ;
}
static void F_35 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
F_36 ( V_2 ) ;
}
struct V_67 * F_37 ( const struct V_199 * V_13 ,
struct V_200 * V_15 )
{
struct V_1 * V_2 ;
int V_201 ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_202 ) ;
if ( ! V_2 ) {
F_13 ( V_53 L_32 ) ;
return NULL ;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_58 = V_134 ;
V_201 = F_4 ( V_2 , V_203 ) ;
if ( V_201 < 0 ) {
F_13 ( V_53 L_33 ) ;
F_36 ( V_2 ) ;
return NULL ;
}
if ( V_201 != 0x25 ) {
F_13 ( V_53 L_34 , V_201 ) ;
F_36 ( V_2 ) ;
return NULL ;
}
memcpy ( & V_2 -> V_204 . V_130 , & V_205 , sizeof( struct V_206 ) ) ;
V_2 -> V_204 . V_69 = V_2 ;
return & V_2 -> V_204 ;
}
struct V_67 * F_39 ( const struct V_199 * V_13 ,
struct V_200 * V_15 )
{
struct V_1 * V_2 ;
int V_201 ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_202 ) ;
if ( ! V_2 ) {
F_13 ( V_53 L_35 ) ;
return NULL ;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_58 = V_59 ;
V_201 = F_4 ( V_2 , V_203 ) ;
if ( V_201 < 0 ) {
F_13 ( V_53 L_36 ) ;
F_36 ( V_2 ) ;
return NULL ;
}
if ( V_201 != 0x46 ) {
F_13 ( V_53 L_34 , V_201 ) ;
F_36 ( V_2 ) ;
return NULL ;
}
memcpy ( & V_2 -> V_204 . V_130 , & V_207 , sizeof( struct V_206 ) ) ;
V_2 -> V_204 . V_69 = V_2 ;
return & V_2 -> V_204 ;
}
