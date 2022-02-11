int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
int V_9 , V_10 ;
unsigned int V_11 ;
T_1 * V_12 = NULL ;
F_2 ( & V_2 -> V_13 ) ;
if ( V_8 )
V_12 = F_3 ( V_8 , V_14 ) ;
if ( V_3 & V_15 )
V_11 = F_4 ( V_2 -> V_16 , 0 ) ;
else {
V_11 = F_5 ( V_2 -> V_16 , 0 ) ;
memcpy ( V_12 , V_7 , V_8 ) ;
}
if ( V_17 & V_18 ) {
F_6 ( V_19 L_1 , V_2 -> V_16 , V_11 ) ;
F_6 ( V_20 L_2 ,
( V_3 & V_15 ) ? L_3 : L_4 ,
V_3 , V_4 , V_5 & 0xff , V_5 >> 8 , V_6 & 0xff ,
V_6 >> 8 , V_8 & 0xff , V_8 >> 8 ) ;
if ( ! ( V_3 & V_15 ) ) {
F_6 ( V_20 L_5 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_6 ( V_20 L_6 , V_7 [ V_10 ] ) ;
F_6 ( V_20 L_7 ) ;
}
}
V_9 = F_7 ( V_2 -> V_16 , V_11 , V_4 , V_3 , V_5 , V_6 ,
V_12 , V_8 , V_21 ) ;
if ( V_3 & V_15 )
memcpy ( V_7 , V_12 , V_8 ) ;
if ( V_17 & V_18 ) {
if ( V_9 < 0 ) {
if ( V_3 & V_15 )
F_6 ( V_19 L_8 , V_8 ) ;
F_6 ( V_20 L_9 , V_22 , V_9 ) ;
} else if ( V_3 & V_15 ) {
F_6 ( V_20 L_10 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_6 ( V_20 L_6 , V_7 [ V_10 ] ) ;
F_6 ( V_20 L_7 ) ;
}
}
F_8 ( V_12 ) ;
F_9 ( 5 ) ;
F_10 ( & V_2 -> V_13 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
return
F_1 ( V_2 , V_23 | V_24 ,
V_4 , V_5 , V_6 , NULL , 0 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_25 ;
T_1 V_7 [ 1 ] ;
V_25 = F_1 ( V_2 , V_15 | V_24 , V_4 ,
V_5 , V_6 , V_7 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
return * V_7 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_26 )
{
int V_25 ;
T_1 V_7 [ 1 ] ;
T_1 V_27 ;
V_25 = F_1 ( V_2 , V_15 | V_24 , V_4 ,
V_5 , V_6 , V_7 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_27 = ( V_7 [ 0 ] & ~ V_26 ) | ( V_6 & V_26 ) ;
if ( V_27 == V_6 )
return 0 ;
return F_1 ( V_2 , V_23 | V_24 ,
V_4 , V_5 , V_27 , NULL , 0 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_25 ;
T_1 V_7 [ 2 ] ;
V_25 = F_1 ( V_2 , V_15 | V_24 , V_4 ,
V_5 , V_6 , V_7 , 2 ) ;
if ( V_25 < 0 )
return V_25 ;
return V_7 [ 1 ] | V_7 [ 0 ] << 8 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_25 ;
T_1 V_7 [ 4 ] ;
V_25 = F_1 ( V_2 , V_15 | V_24 , V_4 ,
V_5 , V_6 , V_7 , 4 ) ;
if ( V_25 < 0 )
return V_25 ;
return V_7 [ 3 ] | V_7 [ 2 ] << 8 | V_7 [ 1 ] << 16 | V_7 [ 0 ] << 24 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_28 )
{
int V_25 ;
V_25 = F_11 ( V_2 , V_29 , V_30 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
F_9 ( V_28 ) ;
V_25 = F_11 ( V_2 , V_29 , V_30 , 1 ) ;
F_9 ( V_28 ) ;
return V_25 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == V_32 ) {
int V_33 ;
V_33 = F_12 ( V_2 , V_34 , 0 ) & 0xfc ;
if ( V_2 -> V_35 == V_36 )
F_11 ( V_2 , V_34 , V_33 ) ;
else
F_11 ( V_2 , V_34 , V_33 | 1 ) ;
} else {
if ( V_2 -> V_35 == V_36 )
F_11 ( V_2 , V_37 , 0xd0 ) ;
else
F_11 ( V_2 , V_37 , 0x90 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == V_32 ) {
F_11 ( V_2 , V_38 , 0x01 ) ;
F_11 ( V_2 , V_39 , 0x27 ) ;
F_11 ( V_2 , V_40 , 0x55 ) ;
F_11 ( V_2 , V_41 , 0x66 ) ;
F_11 ( V_2 , V_42 , 0x66 ) ;
F_11 ( V_2 , V_43 , 0x66 ) ;
F_11 ( V_2 ,
V_44 , 0x66 ) ;
F_11 ( V_2 ,
V_45 , 0x66 ) ;
F_11 ( V_2 ,
V_46 , 0x66 ) ;
F_11 ( V_2 ,
V_47 , 0x66 ) ;
F_11 ( V_2 ,
V_48 , 0x66 ) ;
F_11 ( V_2 ,
V_49 , 0x66 ) ;
F_11 ( V_2 ,
V_50 , 0x66 ) ;
F_11 ( V_2 ,
V_51 , 0x66 ) ;
F_11 ( V_2 ,
V_52 , 0x66 ) ;
F_11 ( V_2 ,
V_53 , 0x66 ) ;
F_11 ( V_2 ,
V_54 , 0x66 ) ;
F_11 ( V_2 ,
V_55 , 0x66 ) ;
F_11 ( V_2 ,
V_56 , 0x66 ) ;
F_11 ( V_2 ,
V_57 , 0x00 ) ;
F_11 ( V_2 ,
V_58 , 0x00 ) ;
F_11 ( V_2 ,
V_59 , 0x01 ) ;
F_11 ( V_2 ,
V_60 , 0x00 ) ;
F_11 ( V_2 ,
V_61 , 0x02 ) ;
F_11 ( V_2 , V_62 , 0x35 ) ;
F_11 ( V_2 , V_63 , 0xa0 ) ;
F_11 ( V_2 , V_64 , 0x11 ) ;
F_11 ( V_2 , V_65 , 0x4c ) ;
F_11 ( V_2 , V_66 , 0x01 ) ;
F_11 ( V_2 , V_38 , 0x00 ) ;
}
}
int F_19 ( struct V_1 * V_2 )
{
struct V_67 V_68 ;
if ( V_2 -> V_31 == V_32 ) {
T_1 V_69 = V_70 ;
if ( ! V_2 -> V_71 )
V_69 |= V_72 ;
F_13 ( V_2 , V_34 ,
V_69 , 0x60 ) ;
F_13 ( V_2 , V_73 ,
0x00 , 0x40 ) ;
} else {
F_11 ( V_2 , V_38 , 0x01 ) ;
if ( V_2 -> V_74 )
F_11 ( V_2 , V_73 , 0x20 ) ;
else
F_11 ( V_2 , V_73 , 0x80 ) ;
F_11 ( V_2 , V_75 , 0x88 ) ;
F_11 ( V_2 , V_76 , 0x23 ) ;
F_11 ( V_2 , V_77 , 0xc0 ) ;
F_11 ( V_2 , V_78 , 0xd8 ) ;
F_11 ( V_2 , V_79 , 0x06 ) ;
F_11 ( V_2 , V_80 , 0x1f ) ;
F_11 ( V_2 , V_81 , 0x08 ) ;
F_11 ( V_2 , V_81 , 0x00 ) ;
F_17 ( V_2 ) ;
F_11 ( V_2 , V_38 , 0x00 ) ;
}
F_9 ( 20 ) ;
V_68 . V_82 = V_2 -> V_83 ;
F_20 ( & V_2 -> V_84 , 0 , V_85 , V_86 , & V_68 ) ;
F_9 ( 100 ) ;
F_21 ( V_2 ) ;
F_18 ( V_2 ) ;
F_22 ( V_2 , 48000 ) ;
if ( V_2 -> V_87 . V_88 ) {
F_11 ( V_2 , V_29 ,
V_2 -> V_87 . V_88 , 0x01 ) ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == V_32 ) {
F_13 ( V_2 , V_34 ,
0x00 , 0x60 ) ;
F_13 ( V_2 , V_73 ,
0x40 , 0x40 ) ;
F_11 ( V_2 , V_89 , 0x28 ) ;
F_11 ( V_2 , V_90 , 0xfc ) ;
F_11 ( V_2 , V_91 , 0xff ) ;
} else {
F_11 ( V_2 , V_81 , 0x08 ) ;
F_11 ( V_2 , V_81 , 0x00 ) ;
F_11 ( V_2 , V_38 , 0x01 ) ;
F_11 ( V_2 , V_80 , 0x08 ) ;
F_11 ( V_2 , V_92 , 0x0c ) ;
F_11 ( V_2 , V_93 , 0xff ) ;
F_11 ( V_2 , V_94 , 0xd8 ) ;
F_11 ( V_2 , V_73 , 0x40 ) ;
F_11 ( V_2 , V_37 , 0xd0 ) ;
F_11 ( V_2 , V_75 , 0x09 ) ;
F_11 ( V_2 , V_76 , 0x37 ) ;
F_11 ( V_2 , V_77 , 0xd8 ) ;
F_11 ( V_2 , V_78 , 0xc0 ) ;
F_11 ( V_2 , V_79 , 0x60 ) ;
F_11 ( V_2 , V_92 , 0x0c ) ;
F_11 ( V_2 , V_93 , 0xff ) ;
F_11 ( V_2 , V_94 , 0x08 ) ;
F_9 ( 50 ) ;
F_11 ( V_2 , V_95 , 0x0020 , 0x00 ) ;
F_9 ( 50 ) ;
F_11 ( V_2 , V_95 , 0x0020 , 0x01 ) ;
F_9 ( 50 ) ;
F_11 ( V_2 , V_95 , 0x0020 , 0x00 ) ;
F_9 ( 100 ) ;
}
if ( V_2 -> V_87 . V_88 ) {
F_11 ( V_2 , V_29 ,
V_2 -> V_87 . V_88 , 0x00 ) ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
int V_96 , V_25 = 0 , V_10 , V_97 ;
struct V_98 * V_99 ;
V_96 = F_15 ( V_2 , V_100 , 0 , 0 ) ;
if ( V_96 >= 0 ) {
switch ( V_96 & 0xff ) {
case 0xf3 :
F_6 ( V_101 L_11 ) ;
if ( V_2 -> V_31 != V_102 )
V_2 -> V_31 = V_102 ;
break;
case 0xf4 :
F_6 ( V_101 L_12 ) ;
if ( V_2 -> V_31 != V_32 )
V_2 -> V_31 = V_32 ;
break;
default:
F_6 ( V_101 L_13 , V_96 ) ;
}
} else
F_6 ( V_103 L_14 , V_96 ) ;
if ( V_2 -> V_31 == V_32 ) {
V_99 = V_104 ;
V_97 = F_25 ( V_104 ) ;
} else {
V_99 = V_105 ;
V_97 = F_25 ( V_105 ) ;
}
for ( V_10 = 0 ; V_10 < V_97 ; V_10 ++ ) {
V_25 = F_11 ( V_2 , V_99 [ V_10 ] . V_4 , V_99 [ V_10 ] . V_106 , V_99 [ V_10 ] . V_33 ) ;
if ( V_25 < 0 ) {
F_6 ( V_103 L_15
L_16 , V_25 ,
V_99 [ V_10 ] . V_4 , V_99 [ V_10 ] . V_106 , V_99 [ V_10 ] . V_33 ) ;
return V_25 ;
}
}
F_9 ( 5 ) ;
V_25 = F_26 ( V_2 ) ;
return V_25 ;
}
int F_27 ( struct V_1 * V_2 )
{
int V_11 ;
int V_107 ;
F_9 ( 500 ) ;
V_107 = F_28 ( V_2 -> V_16 , V_2 -> V_108 . V_109 , 0 ) ;
if ( V_107 < 0 ) {
F_29 ( L_17 ,
V_2 -> V_108 . V_109 ) ;
return V_107 ;
}
V_107 = F_30 ( V_2 -> V_16 ) ;
if ( V_107 < 0 ) {
F_29 ( L_18 ) ;
return V_107 ;
}
if ( ( V_2 -> V_110 & V_111 ) == 0 )
F_9 ( 5 ) ;
if ( ! V_2 -> V_112 . V_113 )
return 0 ;
V_107 = F_28 ( V_2 -> V_16 , V_2 -> V_108 . V_109 , 2 ) ;
if ( V_107 < 0 ) {
F_29 ( L_19 ,
V_2 -> V_108 . V_109 ) ;
return V_107 ;
}
F_9 ( 5 ) ;
V_11 = F_31 ( V_2 -> V_16 ,
V_2 -> V_112 . V_113 -> V_114 . V_115 & V_116 ) ;
V_107 = F_32 ( V_2 -> V_16 , V_11 ) ;
if ( V_107 < 0 ) {
F_29 ( L_20 , V_107 ) ;
return V_107 ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , int V_117 )
{
int V_33 = 0 ;
T_1 V_118 = 0x60 ;
T_1 V_119 = 0x91 ;
switch ( V_117 ) {
case 48000 :
V_118 = 0x60 ;
V_119 = 0x91 ;
V_2 -> V_120 = V_117 ;
break;
case 32000 :
V_118 = 0x00 ;
V_119 = 0x90 ;
V_2 -> V_120 = V_117 ;
break;
default:
return - V_121 ;
}
if ( V_2 -> V_31 == V_32 ) {
V_33 = F_11 ( V_2 , V_122 , V_119 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_13 ( V_2 , V_123 ,
V_118 , 0xf0 ) ;
if ( V_33 < 0 )
return V_33 ;
} else {
V_33 = F_13 ( V_2 , V_94 ,
V_118 , 0xf0 ) ;
if ( V_33 < 0 )
return V_33 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == V_32 ) {
T_1 V_118 ;
switch ( V_2 -> V_124 . V_125 ) {
case V_126 :
case V_127 :
V_118 = 0x03 ;
break;
case V_128 :
V_118 = 0x00 ;
break;
case V_129 :
V_118 = 0x08 ;
break;
case V_130 :
V_118 = 0x04 ;
break;
default:
F_6 ( V_101 L_21 ,
V_2 -> V_131 ) ;
return 0 ;
break;
}
F_13 ( V_2 , V_123 ,
V_118 , 0x0f ) ;
} else {
T_1 V_132 ;
switch ( V_2 -> V_124 . V_125 ) {
case V_128 :
V_132 = 0x00 ;
break;
case V_129 :
V_132 = 0x04 ;
break;
default:
F_6 ( V_101 L_21 ,
V_2 -> V_131 ) ;
return 0 ;
break;
}
F_13 ( V_2 , V_94 ,
V_132 , 0x0f ) ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 , T_1 V_133 )
{
T_1 V_134 = 0 ;
if ( V_133 )
V_134 = 0x08 ;
F_13 ( V_2 , V_122 , V_134 , 0x08 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_1 V_133 )
{
T_1 V_134 = 0 ;
if ( V_133 )
V_134 = 0x20 ;
if ( V_2 -> V_31 == V_32 ) {
F_13 ( V_2 , V_135 ,
V_134 , 0x20 ) ;
F_13 ( V_2 , V_136 ,
V_134 , 0x20 ) ;
} else {
F_13 ( V_2 , V_137 ,
V_134 , 0x20 ) ;
F_13 ( V_2 , V_138 ,
V_134 , 0x20 ) ;
}
}
int F_36 ( struct V_1 * V_2 , T_1 V_133 )
{
enum V_139 V_140 ;
if ( V_2 -> V_71 )
V_140 = V_2 -> V_124 . V_125 ;
else
V_140 = V_2 -> V_141 [ V_2 -> V_142 ] . V_125 ;
switch ( V_140 ) {
case V_126 :
case V_127 :
if ( V_2 -> V_31 == V_32 )
F_34 ( V_2 , V_133 ) ;
else {
F_6 ( V_101 L_22
L_23
L_24 , V_2 -> V_131 ) ;
return - V_121 ;
}
break;
case V_128 :
case V_129 :
F_35 ( V_2 , V_133 ) ;
break;
default:
return - V_121 ;
break;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , int V_143 )
{
T_1 V_144 ;
V_144 = V_143 & 0x0F ;
if ( V_143 < 0 )
V_144 |= 0x40 ;
F_11 ( V_2 , V_145 , V_144 ) ;
F_11 ( V_2 , V_146 , V_144 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_143 )
{
T_1 V_144 ;
V_144 = ( V_143 + 0x10 ) & 0x1f ;
if ( V_2 -> V_31 == V_32 ) {
F_11 ( V_2 , V_135 , V_144 ) ;
F_11 ( V_2 , V_136 , V_144 ) ;
} else {
F_11 ( V_2 , V_137 , V_144 ) ;
F_11 ( V_2 , V_138 , V_144 ) ;
}
}
void F_39 ( struct V_1 * V_2 , int V_143 )
{
enum V_139 V_140 ;
if ( V_2 -> V_71 ) {
V_140 = V_2 -> V_124 . V_125 ;
V_143 += 8 ;
} else
V_140 = V_2 -> V_141 [ V_2 -> V_142 ] . V_125 ;
switch ( V_140 ) {
case V_126 :
case V_127 :
if ( V_2 -> V_31 == V_32 )
F_37 ( V_2 , V_143 ) ;
else
F_6 ( V_101 L_22
L_23
L_24 , V_2 -> V_131 ) ;
break;
case V_128 :
case V_129 :
F_38 ( V_2 , V_143 ) ;
break;
default:
break;
}
}
void F_40 ( struct V_1 * V_2 )
{
F_2 ( & V_147 ) ;
F_41 ( & V_2 -> V_148 ) ;
F_10 ( & V_147 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_2 ( & V_147 ) ;
F_43 ( & V_2 -> V_148 , & V_149 ) ;
F_10 ( & V_147 ) ;
}
int F_44 ( struct V_1 * V_2 , enum V_150 type ,
char * V_7 , int V_97 )
{
struct V_151 * V_152 = NULL ;
if ( ! F_45 ( & V_153 ) ) {
F_46 (ops, &tm6000_extension_devlist, next) {
if ( V_152 -> V_154 && V_152 -> type == type )
V_152 -> V_154 ( V_2 , V_7 , V_97 ) ;
}
}
return 0 ;
}
int F_47 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = NULL ;
F_2 ( & V_147 ) ;
F_43 ( & V_152 -> V_155 , & V_153 ) ;
F_46 (dev, &tm6000_devlist, devlist) {
V_152 -> V_156 ( V_2 ) ;
F_6 ( V_101 L_25 ,
V_2 -> V_131 , V_152 -> V_131 ) ;
}
F_10 ( & V_147 ) ;
return 0 ;
}
void F_48 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = NULL ;
F_2 ( & V_147 ) ;
F_46 (dev, &tm6000_devlist, devlist)
V_152 -> V_157 ( V_2 ) ;
F_6 ( V_101 L_26 , V_152 -> V_131 ) ;
F_41 ( & V_152 -> V_155 ) ;
F_10 ( & V_147 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = NULL ;
F_2 ( & V_147 ) ;
if ( ! F_45 ( & V_153 ) ) {
F_46 (ops, &tm6000_extension_devlist, next) {
if ( V_152 -> V_156 )
V_152 -> V_156 ( V_2 ) ;
}
}
F_10 ( & V_147 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_151 * V_152 = NULL ;
F_2 ( & V_147 ) ;
if ( ! F_45 ( & V_153 ) ) {
F_46 (ops, &tm6000_extension_devlist, next) {
if ( V_152 -> V_157 )
V_152 -> V_157 ( V_2 ) ;
}
}
F_10 ( & V_147 ) ;
}
