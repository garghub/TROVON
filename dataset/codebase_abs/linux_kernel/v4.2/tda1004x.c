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
case 6000000 :
F_6 ( V_2 , V_29 , V_26 , sizeof( V_26 ) ) ;
break;
case 7000000 :
F_6 ( V_2 , V_29 , V_27 , sizeof( V_27 ) ) ;
break;
case 8000000 :
F_6 ( V_2 , V_29 , V_28 , sizeof( V_28 ) ) ;
break;
default:
return - V_19 ;
}
F_1 ( V_2 , V_30 , 0 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_2 V_25 )
{
static T_1 V_31 [] = { 0x7b , 0x2e , 0x11 , 0xf0 , 0xd2 } ;
static T_1 V_32 [] = { 0x6a , 0x02 , 0x6a , 0x43 , 0x9f } ;
static T_1 V_33 [] = { 0x5c , 0x32 , 0xc2 , 0x96 , 0x6d } ;
static T_1 V_34 [] = { 0x70 , 0x02 , 0x49 , 0x24 , 0x92 } ;
static T_1 V_35 [] = { 0x60 , 0x02 , 0xaa , 0xaa , 0xab } ;
static T_1 V_36 [] = { 0x54 , 0x03 , 0x0c , 0x30 , 0xc3 } ;
int V_37 ;
if ( ( V_2 -> V_13 -> V_38 == V_39 ) ||
( V_2 -> V_13 -> V_38 == V_40 ) )
V_37 = 0 ;
else
V_37 = 1 ;
switch ( V_25 ) {
case 6000000 :
if ( V_37 )
F_6 ( V_2 , V_41 , V_31 ,
sizeof( V_31 ) ) ;
else
F_6 ( V_2 , V_41 , V_34 ,
sizeof( V_34 ) ) ;
if ( V_2 -> V_13 -> V_38 == V_39 ) {
F_1 ( V_2 , V_42 , 0x0a ) ;
F_1 ( V_2 , V_43 , 0xab ) ;
}
break;
case 7000000 :
if ( V_37 )
F_6 ( V_2 , V_41 , V_32 ,
sizeof( V_32 ) ) ;
else
F_6 ( V_2 , V_41 , V_35 ,
sizeof( V_35 ) ) ;
if ( V_2 -> V_13 -> V_38 == V_39 ) {
F_1 ( V_2 , V_42 , 0x0c ) ;
F_1 ( V_2 , V_43 , 0x00 ) ;
}
break;
case 8000000 :
if ( V_37 )
F_6 ( V_2 , V_41 , V_33 ,
sizeof( V_33 ) ) ;
else
F_6 ( V_2 , V_41 , V_36 ,
sizeof( V_36 ) ) ;
if ( V_2 -> V_13 -> V_38 == V_39 ) {
F_1 ( V_2 , V_42 , 0x0d ) ;
F_1 ( V_2 , V_43 , 0x55 ) ;
}
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
const unsigned char * V_44 , unsigned int V_10 ,
T_1 V_45 , T_1 V_46 )
{
T_1 V_6 [ 65 ] ;
struct V_7 V_47 = { . V_9 = 0 , . V_6 = V_6 , . V_10 = 0 } ;
int V_48 ;
int V_49 = 0 ;
F_1 ( V_2 , V_45 , 0 ) ;
V_47 . V_12 = V_2 -> V_13 -> V_14 ;
F_13 ( V_2 -> V_15 ) ;
V_6 [ 0 ] = V_46 ;
while ( V_49 != V_10 ) {
V_48 = V_10 - V_49 ;
if ( V_48 > 0x10 )
V_48 = 0x10 ;
memcpy ( V_6 + 1 , V_44 + V_49 , V_48 ) ;
V_47 . V_10 = V_48 + 1 ;
if ( F_14 ( V_2 -> V_15 , & V_47 , 1 ) != 1 ) {
F_15 ( V_50 L_9 ) ;
F_16 ( V_2 -> V_15 ) ;
return - V_51 ;
}
V_49 += V_48 ;
F_2 ( L_10 , V_11 , V_49 ) ;
}
F_16 ( V_2 -> V_15 ) ;
F_8 ( 100 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_52 , V_53 ;
unsigned long V_54 ;
if ( V_2 -> V_55 == V_56 ) {
V_54 = V_57 + 2 * V_58 ;
while( ! ( F_4 ( V_2 , V_59 ) & 0x20 ) ) {
if ( F_18 ( V_57 , V_54 ) ) {
F_15 ( V_50 L_11 ) ;
break;
}
F_8 ( 1 ) ;
}
} else
F_8 ( 100 ) ;
F_5 ( V_2 , V_24 , 0x10 , 0 ) ;
F_1 ( V_2 , V_60 , 0x67 ) ;
V_52 = F_4 ( V_2 , V_61 ) ;
V_53 = F_4 ( V_2 , V_62 ) ;
if ( V_52 != 0x67 || V_53 < 0x20 || V_53 > 0x2e ) {
F_15 ( V_63 L_12 , V_53 ) ;
return - V_51 ;
}
F_15 ( V_63 L_13 , V_53 ) ;
return 0 ;
}
static int F_19 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_5 ;
const struct V_67 * V_68 ;
if ( F_17 ( V_2 ) == 0 )
return 0 ;
F_15 ( V_63 L_14 , V_69 ) ;
V_5 = V_2 -> V_13 -> V_70 ( V_65 , & V_68 , V_69 ) ;
if ( V_5 ) {
F_15 ( V_50 L_15 ) ;
return V_5 ;
}
F_5 ( V_2 , V_24 , 0x10 , 0 ) ;
F_5 ( V_2 , V_24 , 8 , 8 ) ;
F_5 ( V_2 , V_24 , 8 , 0 ) ;
F_8 ( 10 ) ;
F_10 ( V_2 , 8000000 ) ;
V_5 = F_12 ( V_2 , V_68 -> V_4 , V_68 -> V_71 , V_72 , V_73 ) ;
F_20 ( V_68 ) ;
if ( V_5 )
return V_5 ;
F_15 ( V_63 L_16 ) ;
F_8 ( 100 ) ;
return F_17 ( V_2 ) ;
}
static void F_21 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_37 ;
if ( ( V_2 -> V_13 -> V_38 == V_39 ) ||
( V_2 -> V_13 -> V_38 == V_40 ) )
V_37 = 0 ;
else
V_37 = 1 ;
F_1 ( V_2 , V_74 , 0xf0 ) ;
if( V_37 ) {
F_15 ( V_63 L_17 ) ;
F_1 ( V_2 , V_75 , 0x08 ) ;
} else {
F_15 ( V_63 L_18 ) ;
F_1 ( V_2 , V_75 , 0x03 ) ;
}
if ( V_2 -> V_13 -> V_76 == V_77 ) {
F_2 ( L_19 , V_11 ) ;
F_1 ( V_2 , V_78 , 0 ) ;
} else {
F_2 ( L_20 , V_11 ) ;
F_1 ( V_2 , V_78 , 3 ) ;
}
if( V_37 )
F_1 ( V_2 , V_79 , 0x67 ) ;
else
F_1 ( V_2 , V_79 , 0x72 ) ;
switch ( V_2 -> V_13 -> V_38 ) {
case V_39 :
F_1 ( V_2 , V_42 , 0x0c ) ;
F_1 ( V_2 , V_43 , 0x00 ) ;
break;
case V_40 :
F_1 ( V_2 , V_42 , 0x0d ) ;
F_1 ( V_2 , V_43 , 0xc7 ) ;
break;
case V_80 :
F_1 ( V_2 , V_42 , 0xd7 ) ;
F_1 ( V_2 , V_43 , 0x59 ) ;
break;
case V_81 :
F_1 ( V_2 , V_42 , 0xd7 ) ;
F_1 ( V_2 , V_43 , 0x3f ) ;
break;
}
F_11 ( V_2 , 8000000 ) ;
F_8 ( 120 ) ;
}
static int F_22 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_5 , V_82 ;
const struct V_67 * V_68 ;
if ( V_2 -> V_13 -> V_76 == V_77 ) {
V_82 = 0 ;
} else {
F_2 ( L_21 , V_11 ) ;
V_82 = 0x80 ;
}
F_1 ( V_2 , V_24 , V_82 ) ;
F_5 ( V_2 , V_83 , 1 , 0 ) ;
if ( V_2 -> V_13 -> V_84 != V_85 ) {
F_1 ( V_2 , V_86 , 0x33 ) ;
F_5 ( V_2 , V_87 , 0x0f , V_2 -> V_13 -> V_84 & 0x0f ) ;
}
F_8 ( 10 ) ;
F_21 ( V_65 ) ;
F_5 ( V_2 , V_88 , 0xc0 , 0 ) ;
if ( F_17 ( V_2 ) == 0 )
return 0 ;
F_15 ( V_63 L_22 ) ;
F_1 ( V_2 , V_24 , 4 ) ;
F_8 ( 300 ) ;
F_1 ( V_2 , V_24 , V_82 ) ;
if ( F_17 ( V_2 ) == 0 )
return 0 ;
if ( V_2 -> V_13 -> V_70 != NULL ) {
F_15 ( V_63 L_23 ) ;
V_5 = V_2 -> V_13 -> V_70 ( V_65 , & V_68 , V_89 ) ;
if ( V_5 ) {
V_5 = V_2 -> V_13 -> V_70 ( V_65 , & V_68 , V_69 ) ;
if ( V_5 ) {
F_15 ( V_50 L_15 ) ;
return V_5 ;
} else {
F_15 ( V_63 L_24 ,
V_89 ) ;
}
}
} else {
F_15 ( V_50 L_25 ) ;
return - V_51 ;
}
F_5 ( V_2 , V_24 , 8 , 8 ) ;
V_5 = F_12 ( V_2 , V_68 -> V_4 , V_68 -> V_71 , V_90 , V_91 ) ;
F_20 ( V_68 ) ;
return F_17 ( V_2 ) ;
}
static int F_23 ( int V_92 )
{
switch ( V_92 ) {
case V_93 :
return 0 ;
case V_94 :
return 1 ;
case V_95 :
return 2 ;
case V_96 :
return 3 ;
case V_97 :
return 4 ;
}
return - V_19 ;
}
static int F_24 ( int V_98 )
{
switch ( V_98 ) {
case 0 :
return V_93 ;
case 1 :
return V_94 ;
case 2 :
return V_95 ;
case 3 :
return V_96 ;
case 4 :
return V_97 ;
}
return - 1 ;
}
static int F_25 ( struct V_64 * V_65 , const T_1 V_6 [] , int V_10 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
if ( V_10 != 2 )
return - V_19 ;
return F_1 ( V_2 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
}
static int F_26 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
F_2 ( L_8 , V_11 ) ;
if ( F_19 ( V_65 ) ) {
F_15 ( L_26 ) ;
return - V_51 ;
}
F_5 ( V_2 , V_99 , 0x10 , 0 ) ;
F_5 ( V_2 , V_24 , 0x20 , 0 ) ;
F_5 ( V_2 , V_100 , 8 , 0 ) ;
F_5 ( V_2 , V_101 , 0x40 , 0 ) ;
F_5 ( V_2 , V_101 , 0x80 , 0x80 ) ;
F_5 ( V_2 , V_100 , 0x10 , 0x10 ) ;
F_5 ( V_2 , V_102 , 0xC0 , 0x0 ) ;
F_1 ( V_2 , V_103 , 0 ) ;
F_1 ( V_2 , V_104 , 0 ) ;
F_5 ( V_2 , V_105 , 0xe0 , 0xa0 ) ;
F_5 ( V_2 , V_101 , 0x10 , 0 ) ;
F_1 ( V_2 , V_99 , 0x2e ) ;
F_5 ( V_2 , 0x1f , 0x01 , V_2 -> V_13 -> V_106 ) ;
return 0 ;
}
static int F_27 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
F_2 ( L_8 , V_11 ) ;
if ( F_22 ( V_65 ) ) {
F_15 ( L_26 ) ;
return - V_51 ;
}
F_5 ( V_2 , V_24 , 0x20 , 0 ) ;
F_1 ( V_2 , V_100 , 0x87 ) ;
F_1 ( V_2 , V_101 , 0x88 ) ;
switch ( V_2 -> V_13 -> V_107 ) {
case V_108 :
F_1 ( V_2 , V_109 , 0x00 ) ;
F_5 ( V_2 , V_87 , 0xf0 , 0x60 ) ;
break;
case V_110 :
F_1 ( V_2 , V_109 , 0x0a ) ;
F_5 ( V_2 , V_87 , 0xf0 , 0x60 ) ;
break;
case V_111 :
F_1 ( V_2 , V_109 , 0x0a ) ;
F_5 ( V_2 , V_87 , 0xf0 , 0x00 ) ;
break;
case V_112 :
F_1 ( V_2 , V_109 , 0x02 ) ;
F_1 ( V_2 , V_113 , 0x70 ) ;
F_1 ( V_2 , V_114 , 0x08 ) ;
F_5 ( V_2 , V_87 , 0xf0 , 0x60 ) ;
break;
}
if ( V_2 -> V_13 -> V_115 == 0 ) {
F_5 ( V_2 , V_83 , 0xc0 , 0x40 ) ;
F_5 ( V_2 , 0x3a , 0x80 , V_2 -> V_13 -> V_106 << 7 ) ;
} else {
F_5 ( V_2 , V_83 , 0xc0 , 0x80 ) ;
F_5 ( V_2 , V_87 , 0x10 ,
V_2 -> V_13 -> V_106 << 4 ) ;
}
F_1 ( V_2 , V_88 , 0x38 ) ;
F_5 ( V_2 , V_83 , 0x3e , 0x38 ) ;
F_1 ( V_2 , V_116 , 0 ) ;
F_1 ( V_2 , V_117 , 0xff ) ;
F_1 ( V_2 , V_118 , 0 ) ;
F_1 ( V_2 , V_119 , 0xff ) ;
F_1 ( V_2 , V_120 , 0x12 ) ;
F_1 ( V_2 , V_121 , 0x1a ) ;
F_1 ( V_2 , V_103 , 7 ) ;
F_1 ( V_2 , V_104 , 0xc0 ) ;
return 0 ;
}
static int F_28 ( struct V_64 * V_65 )
{
struct V_122 * V_123 = & V_65 -> V_124 ;
struct V_1 * V_2 = V_65 -> V_66 ;
int V_125 ;
int V_126 ;
F_2 ( L_8 , V_11 ) ;
if ( V_2 -> V_55 == V_56 ) {
F_5 ( V_2 , V_100 , 0x10 , 0x10 ) ;
F_5 ( V_2 , V_127 , 0x80 , 0 ) ;
F_5 ( V_2 , V_102 , 0xC0 , 0 ) ;
F_5 ( V_2 , V_109 , 4 , 0 ) ;
}
if ( V_65 -> V_128 . V_129 . V_130 ) {
V_65 -> V_128 . V_129 . V_130 ( V_65 ) ;
if ( V_65 -> V_128 . V_131 )
V_65 -> V_128 . V_131 ( V_65 , 0 ) ;
}
if ( V_2 -> V_55 == V_132 ) {
V_123 -> V_133 = V_134 ;
V_123 -> V_135 = V_136 ;
V_123 -> V_137 = V_138 ;
}
if ( ( V_123 -> V_133 == V_134 ) ||
( V_123 -> V_139 == V_134 ) ||
( V_123 -> V_140 == V_141 ) ||
( V_123 -> V_142 == V_143 ) ) {
F_5 ( V_2 , V_100 , 1 , 1 ) ;
F_5 ( V_2 , V_127 , 0x03 , 0 ) ;
F_5 ( V_2 , V_127 , 0x60 , 0 ) ;
F_5 ( V_2 , V_102 , 0x3f , 0 ) ;
} else {
F_5 ( V_2 , V_100 , 1 , 0 ) ;
V_125 = F_23 ( V_123 -> V_133 ) ;
if ( V_125 < 0 )
return V_125 ;
F_5 ( V_2 , V_102 , 7 , V_125 ) ;
V_125 = F_23 ( V_123 -> V_139 ) ;
if ( V_125 < 0 )
return V_125 ;
F_5 ( V_2 , V_102 , 0x38 , V_125 << 3 ) ;
switch ( V_123 -> V_140 ) {
case V_144 :
F_5 ( V_2 , V_127 , 3 , 0 ) ;
break;
case V_145 :
F_5 ( V_2 , V_127 , 3 , 1 ) ;
break;
case V_146 :
F_5 ( V_2 , V_127 , 3 , 2 ) ;
break;
default:
return - V_19 ;
}
switch ( V_123 -> V_142 ) {
case V_147 :
F_5 ( V_2 , V_127 , 0x60 , 0 << 5 ) ;
break;
case V_148 :
F_5 ( V_2 , V_127 , 0x60 , 1 << 5 ) ;
break;
case V_149 :
F_5 ( V_2 , V_127 , 0x60 , 2 << 5 ) ;
break;
case V_150 :
F_5 ( V_2 , V_127 , 0x60 , 3 << 5 ) ;
break;
default:
return - V_19 ;
}
}
switch ( V_2 -> V_55 ) {
case V_132 :
F_10 ( V_2 , V_123 -> V_151 ) ;
break;
case V_56 :
F_11 ( V_2 , V_123 -> V_151 ) ;
break;
}
V_126 = V_123 -> V_126 ;
if ( V_2 -> V_13 -> V_152 )
V_126 = V_126 ? V_153 : V_154 ;
switch ( V_126 ) {
case V_153 :
F_5 ( V_2 , V_101 , 0x20 , 0 ) ;
break;
case V_154 :
F_5 ( V_2 , V_101 , 0x20 , 0x20 ) ;
break;
default:
return - V_19 ;
}
switch ( V_123 -> V_135 ) {
case V_155 :
F_5 ( V_2 , V_100 , 2 , 0 ) ;
F_5 ( V_2 , V_127 , 0x0c , 0 << 2 ) ;
break;
case V_156 :
F_5 ( V_2 , V_100 , 2 , 0 ) ;
F_5 ( V_2 , V_127 , 0x0c , 1 << 2 ) ;
break;
case V_157 :
F_5 ( V_2 , V_100 , 2 , 0 ) ;
F_5 ( V_2 , V_127 , 0x0c , 2 << 2 ) ;
break;
case V_158 :
F_5 ( V_2 , V_100 , 2 , 0 ) ;
F_5 ( V_2 , V_127 , 0x0c , 3 << 2 ) ;
break;
case V_136 :
F_5 ( V_2 , V_100 , 2 , 2 ) ;
F_5 ( V_2 , V_127 , 0x0c , 0 << 2 ) ;
break;
default:
return - V_19 ;
}
switch ( V_123 -> V_137 ) {
case V_159 :
F_5 ( V_2 , V_100 , 4 , 0 ) ;
F_5 ( V_2 , V_127 , 0x10 , 0 << 4 ) ;
break;
case V_160 :
F_5 ( V_2 , V_100 , 4 , 0 ) ;
F_5 ( V_2 , V_127 , 0x10 , 1 << 4 ) ;
break;
case V_138 :
F_5 ( V_2 , V_100 , 4 , 4 ) ;
F_5 ( V_2 , V_127 , 0x10 , 0 ) ;
break;
default:
return - V_19 ;
}
switch ( V_2 -> V_55 ) {
case V_132 :
F_5 ( V_2 , V_24 , 8 , 8 ) ;
F_5 ( V_2 , V_24 , 8 , 0 ) ;
break;
case V_56 :
F_5 ( V_2 , V_100 , 0x40 , 0x40 ) ;
F_8 ( 1 ) ;
F_5 ( V_2 , V_109 , 4 , 1 ) ;
break;
}
F_8 ( 10 ) ;
return 0 ;
}
static int F_29 ( struct V_64 * V_65 )
{
struct V_122 * V_123 = & V_65 -> V_124 ;
struct V_1 * V_2 = V_65 -> V_66 ;
F_2 ( L_8 , V_11 ) ;
V_123 -> V_126 = V_153 ;
if ( F_4 ( V_2 , V_101 ) & 0x20 )
V_123 -> V_126 = V_154 ;
if ( V_2 -> V_13 -> V_152 )
V_123 -> V_126 = V_123 -> V_126 ? V_153 : V_154 ;
switch ( V_2 -> V_55 ) {
case V_132 :
switch ( F_4 ( V_2 , V_161 ) ) {
case 0x14 :
V_123 -> V_151 = 8000000 ;
break;
case 0xdb :
V_123 -> V_151 = 7000000 ;
break;
case 0x4f :
V_123 -> V_151 = 6000000 ;
break;
}
break;
case V_56 :
switch ( F_4 ( V_2 , V_41 ) ) {
case 0x5c :
case 0x54 :
V_123 -> V_151 = 8000000 ;
break;
case 0x6a :
case 0x60 :
V_123 -> V_151 = 7000000 ;
break;
case 0x7b :
case 0x70 :
V_123 -> V_151 = 6000000 ;
break;
}
break;
}
V_123 -> V_133 =
F_24 ( F_4 ( V_2 , V_162 ) & 7 ) ;
V_123 -> V_139 =
F_24 ( ( F_4 ( V_2 , V_162 ) >> 3 ) & 7 ) ;
switch ( F_4 ( V_2 , V_163 ) & 3 ) {
case 0 :
V_123 -> V_140 = V_144 ;
break;
case 1 :
V_123 -> V_140 = V_145 ;
break;
case 2 :
V_123 -> V_140 = V_146 ;
break;
}
V_123 -> V_137 = V_159 ;
if ( F_4 ( V_2 , V_163 ) & 0x10 )
V_123 -> V_137 = V_160 ;
switch ( ( F_4 ( V_2 , V_163 ) & 0x0c ) >> 2 ) {
case 0 :
V_123 -> V_135 = V_155 ;
break;
case 1 :
V_123 -> V_135 = V_156 ;
break;
case 2 :
V_123 -> V_135 = V_157 ;
break;
case 3 :
V_123 -> V_135 = V_158 ;
break;
}
switch ( ( F_4 ( V_2 , V_163 ) & 0x60 ) >> 5 ) {
case 0 :
V_123 -> V_142 = V_147 ;
break;
case 1 :
V_123 -> V_142 = V_148 ;
break;
case 2 :
V_123 -> V_142 = V_149 ;
break;
case 3 :
V_123 -> V_142 = V_150 ;
break;
}
return 0 ;
}
static int F_30 ( struct V_64 * V_65 ,
enum V_164 * V_164 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_165 ;
int V_166 ;
int V_167 ;
F_2 ( L_8 , V_11 ) ;
V_165 = F_4 ( V_2 , V_59 ) ;
if ( V_165 == - 1 )
return - V_51 ;
* V_164 = 0 ;
if ( V_165 & 4 )
* V_164 |= V_168 ;
if ( V_165 & 2 )
* V_164 |= V_169 ;
if ( V_165 & 8 )
* V_164 |= V_170 | V_171 | V_172 ;
if ( ! ( * V_164 & V_170 ) ) {
V_166 = F_4 ( V_2 , V_173 ) ;
if ( V_166 == - 1 )
return - V_51 ;
V_165 = F_4 ( V_2 , V_174 ) ;
if ( V_165 == - 1 )
return - V_51 ;
V_166 |= ( V_165 << 8 ) ;
F_4 ( V_2 , V_175 ) ;
if ( V_166 != 65535 )
* V_164 |= V_170 ;
}
if ( ( * V_164 & V_170 ) && ( ! ( * V_164 & V_171 ) ) ) {
V_167 = F_4 ( V_2 , V_176 ) ;
if ( V_167 == - 1 )
return - V_51 ;
V_165 = F_4 ( V_2 , V_177 ) ;
if ( V_165 == - 1 )
return - V_51 ;
V_167 |= ( V_165 << 8 ) ;
V_165 = F_4 ( V_2 , V_105 ) ;
if ( V_165 == - 1 )
return - V_51 ;
V_167 |= ( V_165 & 0x0f ) << 16 ;
F_4 ( V_2 , V_178 ) ;
if ( V_167 < 16632 )
* V_164 |= V_171 ;
}
F_2 ( L_27 , V_11 , * V_164 ) ;
return 0 ;
}
static int F_31 ( struct V_64 * V_65 , T_3 * signal )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_125 ;
int V_3 = 0 ;
F_2 ( L_8 , V_11 ) ;
switch ( V_2 -> V_55 ) {
case V_132 :
V_3 = V_179 ;
break;
case V_56 :
V_3 = V_180 ;
break;
}
V_125 = F_4 ( V_2 , V_3 ) ;
if ( V_125 < 0 )
return - V_51 ;
* signal = ( V_125 << 8 ) | V_125 ;
F_2 ( L_28 , V_11 , * signal ) ;
return 0 ;
}
static int F_32 ( struct V_64 * V_65 , T_3 * V_181 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_125 ;
F_2 ( L_8 , V_11 ) ;
V_125 = F_4 ( V_2 , V_182 ) ;
if ( V_125 < 0 )
return - V_51 ;
V_125 = 255 - V_125 ;
* V_181 = ( ( V_125 << 8 ) | V_125 ) ;
F_2 ( L_29 , V_11 , * V_181 ) ;
return 0 ;
}
static int F_33 ( struct V_64 * V_65 , T_2 * V_183 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_125 ;
int V_184 ;
int V_185 ;
F_2 ( L_8 , V_11 ) ;
V_185 = 0 ;
V_125 = F_4 ( V_2 , V_186 ) ;
if ( V_125 < 0 )
return - V_51 ;
V_125 &= 0x7f ;
while ( V_185 ++ < 5 ) {
F_5 ( V_2 , V_186 , 0x80 , 0 ) ;
F_5 ( V_2 , V_186 , 0x80 , 0 ) ;
F_5 ( V_2 , V_186 , 0x80 , 0 ) ;
V_184 = F_4 ( V_2 , V_186 ) ;
if ( V_184 < 0 )
return - V_51 ;
V_184 &= 0x7f ;
if ( ( V_184 < V_125 ) || ( V_184 == 0 ) )
break;
}
if ( V_125 != 0x7f )
* V_183 = V_125 ;
else
* V_183 = 0xffffffff ;
F_2 ( L_30 , V_11 , * V_183 ) ;
return 0 ;
}
static int F_34 ( struct V_64 * V_65 , T_2 * V_187 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_125 ;
F_2 ( L_8 , V_11 ) ;
V_125 = F_4 ( V_2 , V_173 ) ;
if ( V_125 < 0 )
return - V_51 ;
* V_187 = V_125 << 1 ;
V_125 = F_4 ( V_2 , V_174 ) ;
if ( V_125 < 0 )
return - V_51 ;
* V_187 |= ( V_125 << 9 ) ;
F_4 ( V_2 , V_175 ) ;
F_2 ( L_31 , V_11 , * V_187 ) ;
return 0 ;
}
static int F_35 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
int V_188 ;
switch ( V_2 -> V_55 ) {
case V_132 :
F_5 ( V_2 , V_99 , 0x10 , 0x10 ) ;
break;
case V_56 :
F_1 ( V_2 , V_83 , 0xff ) ;
V_188 = V_2 -> V_13 -> V_84 ;
if ( V_188 >= V_189 )
F_5 ( V_2 , V_87 , 0x0f ,
( V_188 & 0x0f ) ^ 0x0a ) ;
F_5 ( V_2 , V_88 , 0xc0 , 0xc0 ) ;
F_5 ( V_2 , V_24 , 1 , 1 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_64 * V_65 , int V_190 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
if ( V_190 ) {
return F_7 ( V_2 ) ;
} else {
return F_9 ( V_2 ) ;
}
}
static int F_37 ( struct V_64 * V_65 , struct V_191 * V_192 )
{
V_192 -> V_193 = 800 ;
V_192 -> V_194 = 0 ;
V_192 -> V_195 = 0 ;
return 0 ;
}
static void F_38 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = V_65 -> V_66 ;
F_39 ( V_2 ) ;
}
struct V_64 * F_40 ( const struct V_196 * V_13 ,
struct V_197 * V_15 )
{
struct V_1 * V_2 ;
int V_198 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_199 ) ;
if ( ! V_2 ) {
F_15 ( V_50 L_32 ) ;
return NULL ;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_55 = V_132 ;
V_198 = F_4 ( V_2 , V_200 ) ;
if ( V_198 < 0 ) {
F_15 ( V_50 L_33 ) ;
F_39 ( V_2 ) ;
return NULL ;
}
if ( V_198 != 0x25 ) {
F_15 ( V_50 L_34 , V_198 ) ;
F_39 ( V_2 ) ;
return NULL ;
}
memcpy ( & V_2 -> V_201 . V_128 , & V_202 , sizeof( struct V_203 ) ) ;
V_2 -> V_201 . V_66 = V_2 ;
return & V_2 -> V_201 ;
}
struct V_64 * F_42 ( const struct V_196 * V_13 ,
struct V_197 * V_15 )
{
struct V_1 * V_2 ;
int V_198 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_199 ) ;
if ( ! V_2 ) {
F_15 ( V_50 L_35 ) ;
return NULL ;
}
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_55 = V_56 ;
V_198 = F_4 ( V_2 , V_200 ) ;
if ( V_198 < 0 ) {
F_15 ( V_50 L_36 ) ;
F_39 ( V_2 ) ;
return NULL ;
}
if ( V_198 != 0x46 ) {
F_15 ( V_50 L_34 , V_198 ) ;
F_39 ( V_2 ) ;
return NULL ;
}
memcpy ( & V_2 -> V_201 . V_128 , & V_204 , sizeof( struct V_203 ) ) ;
V_2 -> V_201 . V_66 = V_2 ;
return & V_2 -> V_201 ;
}
