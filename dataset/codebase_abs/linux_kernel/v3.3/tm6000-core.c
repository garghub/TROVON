int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
int V_9 , V_10 ;
unsigned int V_11 ;
T_1 * V_12 = NULL ;
int V_13 = 5000 ;
F_2 ( & V_2 -> V_14 ) ;
if ( V_8 )
V_12 = F_3 ( V_8 , V_15 ) ;
if ( V_3 & V_16 )
V_11 = F_4 ( V_2 -> V_17 , 0 ) ;
else {
V_11 = F_5 ( V_2 -> V_17 , 0 ) ;
memcpy ( V_12 , V_7 , V_8 ) ;
}
if ( V_18 & V_19 ) {
F_6 ( V_20 L_1 , V_2 -> V_17 , V_11 ) ;
F_6 ( V_21 L_2 ,
( V_3 & V_16 ) ? L_3 : L_4 ,
V_3 , V_4 , V_5 & 0xff , V_5 >> 8 , V_6 & 0xff ,
V_6 >> 8 , V_8 & 0xff , V_8 >> 8 ) ;
if ( ! ( V_3 & V_16 ) ) {
F_6 ( V_21 L_5 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_6 ( V_21 L_6 , V_7 [ V_10 ] ) ;
F_6 ( V_21 L_7 ) ;
}
}
V_9 = F_7 ( V_2 -> V_17 , V_11 , V_4 , V_3 , V_5 , V_6 ,
V_12 , V_8 , V_22 ) ;
if ( V_3 & V_16 )
memcpy ( V_7 , V_12 , V_8 ) ;
if ( V_18 & V_19 ) {
if ( V_9 < 0 ) {
if ( V_3 & V_16 )
F_6 ( V_20 L_8 , V_8 ) ;
F_6 ( V_21 L_9 , V_23 , V_9 ) ;
} else if ( V_3 & V_16 ) {
F_6 ( V_21 L_10 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_6 ( V_21 L_6 , V_7 [ V_10 ] ) ;
F_6 ( V_21 L_7 ) ;
}
}
F_8 ( V_12 ) ;
if ( V_2 -> V_24 & V_25 )
V_13 = 0 ;
if ( V_4 == V_26 && ! ( V_3 & V_16 ) ) {
unsigned int V_27 ;
V_27 = ( V_8 * 200 ) + 200 ;
if ( V_27 < V_13 )
V_27 = V_13 ;
F_9 ( V_27 , V_27 + 1000 ) ;
}
else if ( V_13 )
F_9 ( V_13 , V_13 + 1000 ) ;
F_10 ( & V_2 -> V_14 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
return
F_1 ( V_2 , V_28 | V_29 ,
V_4 , V_5 , V_6 , NULL , 0 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_30 ;
T_1 V_7 [ 1 ] ;
V_30 = F_1 ( V_2 , V_16 | V_29 , V_4 ,
V_5 , V_6 , V_7 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
return * V_7 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_31 )
{
int V_30 ;
T_1 V_7 [ 1 ] ;
T_1 V_32 ;
V_30 = F_1 ( V_2 , V_16 | V_29 , V_4 ,
V_5 , 0 , V_7 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
V_32 = ( V_7 [ 0 ] & ~ V_31 ) | ( V_6 & V_31 ) ;
if ( V_32 == V_7 [ 0 ] )
return 0 ;
return F_1 ( V_2 , V_28 | V_29 ,
V_4 , V_5 , V_32 , NULL , 0 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_30 ;
T_1 V_7 [ 2 ] ;
V_30 = F_1 ( V_2 , V_16 | V_29 , V_4 ,
V_5 , V_6 , V_7 , 2 ) ;
if ( V_30 < 0 )
return V_30 ;
return V_7 [ 1 ] | V_7 [ 0 ] << 8 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_30 ;
T_1 V_7 [ 4 ] ;
V_30 = F_1 ( V_2 , V_16 | V_29 , V_4 ,
V_5 , V_6 , V_7 , 4 ) ;
if ( V_30 < 0 )
return V_30 ;
return V_7 [ 3 ] | V_7 [ 2 ] << 8 | V_7 [ 1 ] << 16 | V_7 [ 0 ] << 24 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_27 )
{
int V_30 ;
V_30 = F_11 ( V_2 , V_33 , V_34 , 0 ) ;
if ( V_30 < 0 )
return V_30 ;
F_17 ( V_27 ) ;
V_30 = F_11 ( V_2 , V_33 , V_34 , 1 ) ;
F_17 ( V_27 ) ;
return V_30 ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 == V_36 ) {
int V_37 ;
V_37 = F_12 ( V_2 , V_38 , 0 ) & 0xfc ;
if ( V_2 -> V_39 == V_40 )
F_11 ( V_2 , V_38 , V_37 ) ;
else
F_11 ( V_2 , V_38 , V_37 | 1 ) ;
} else {
if ( V_2 -> V_39 == V_40 )
F_11 ( V_2 , V_41 , 0xd0 ) ;
else
F_11 ( V_2 , V_41 , 0x90 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 == V_36 ) {
F_11 ( V_2 , V_42 , 0x01 ) ;
F_11 ( V_2 , V_43 , 0x27 ) ;
F_11 ( V_2 , V_44 , 0x55 ) ;
F_11 ( V_2 , V_45 , 0x66 ) ;
F_11 ( V_2 , V_46 , 0x66 ) ;
F_11 ( V_2 , V_47 , 0x66 ) ;
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
V_57 , 0x66 ) ;
F_11 ( V_2 ,
V_58 , 0x66 ) ;
F_11 ( V_2 ,
V_59 , 0x66 ) ;
F_11 ( V_2 ,
V_60 , 0x66 ) ;
F_11 ( V_2 ,
V_61 , 0x00 ) ;
F_11 ( V_2 ,
V_62 , 0x00 ) ;
F_11 ( V_2 ,
V_63 , 0x01 ) ;
F_11 ( V_2 ,
V_64 , 0x00 ) ;
F_11 ( V_2 ,
V_65 , 0x02 ) ;
F_11 ( V_2 , V_66 , 0x35 ) ;
F_11 ( V_2 , V_67 , 0xa0 ) ;
F_11 ( V_2 , V_68 , 0x11 ) ;
F_11 ( V_2 , V_69 , 0x4c ) ;
F_11 ( V_2 , V_70 , 0x01 ) ;
F_11 ( V_2 , V_42 , 0x00 ) ;
}
}
int F_20 ( struct V_1 * V_2 )
{
struct V_71 V_72 ;
if ( V_2 -> V_35 == V_36 ) {
T_1 V_73 = V_74 ;
if ( ! V_2 -> V_75 )
V_73 |= V_76 ;
F_13 ( V_2 , V_38 ,
V_73 , 0x60 ) ;
F_13 ( V_2 , V_77 ,
0x00 , 0x40 ) ;
} else {
F_11 ( V_2 , V_42 , 0x01 ) ;
if ( V_2 -> V_78 )
F_11 ( V_2 , V_77 , 0x20 ) ;
else
F_11 ( V_2 , V_77 , 0x80 ) ;
F_11 ( V_2 , V_79 , 0x88 ) ;
F_11 ( V_2 , V_80 , 0x23 ) ;
F_11 ( V_2 , V_81 , 0xc0 ) ;
F_11 ( V_2 , V_82 , 0xd8 ) ;
F_11 ( V_2 , V_83 , 0x06 ) ;
F_11 ( V_2 , V_84 , 0x1f ) ;
F_11 ( V_2 , V_85 , 0x08 ) ;
F_11 ( V_2 , V_85 , 0x00 ) ;
F_18 ( V_2 ) ;
F_11 ( V_2 , V_42 , 0x00 ) ;
}
F_17 ( 20 ) ;
V_72 . V_86 = V_2 -> V_87 ;
F_21 ( & V_2 -> V_88 , 0 , V_89 , V_90 , & V_72 ) ;
F_17 ( 100 ) ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
F_23 ( V_2 , 48000 ) ;
if ( V_2 -> V_91 . V_92 ) {
F_11 ( V_2 , V_33 ,
V_2 -> V_91 . V_92 , 0x01 ) ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 == V_36 ) {
F_13 ( V_2 , V_38 ,
0x00 , 0x60 ) ;
F_13 ( V_2 , V_77 ,
0x40 , 0x40 ) ;
F_11 ( V_2 , V_93 , 0x28 ) ;
F_11 ( V_2 , V_94 , 0xfc ) ;
F_11 ( V_2 , V_95 , 0xff ) ;
} else {
F_11 ( V_2 , V_85 , 0x08 ) ;
F_11 ( V_2 , V_85 , 0x00 ) ;
F_11 ( V_2 , V_42 , 0x01 ) ;
F_11 ( V_2 , V_84 , 0x08 ) ;
F_11 ( V_2 , V_96 , 0x0c ) ;
F_11 ( V_2 , V_97 , 0xff ) ;
F_11 ( V_2 , V_98 , 0xd8 ) ;
F_11 ( V_2 , V_77 , 0x40 ) ;
F_11 ( V_2 , V_41 , 0xd0 ) ;
F_11 ( V_2 , V_79 , 0x09 ) ;
F_11 ( V_2 , V_80 , 0x37 ) ;
F_11 ( V_2 , V_81 , 0xd8 ) ;
F_11 ( V_2 , V_82 , 0xc0 ) ;
F_11 ( V_2 , V_83 , 0x60 ) ;
F_11 ( V_2 , V_96 , 0x0c ) ;
F_11 ( V_2 , V_97 , 0xff ) ;
F_11 ( V_2 , V_98 , 0x08 ) ;
F_17 ( 50 ) ;
F_11 ( V_2 , V_99 , 0x0020 , 0x00 ) ;
F_17 ( 50 ) ;
F_11 ( V_2 , V_99 , 0x0020 , 0x01 ) ;
F_17 ( 50 ) ;
F_11 ( V_2 , V_99 , 0x0020 , 0x00 ) ;
F_17 ( 100 ) ;
}
if ( V_2 -> V_91 . V_92 ) {
F_11 ( V_2 , V_33 ,
V_2 -> V_91 . V_92 , 0x00 ) ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_100 , V_30 = 0 , V_10 , V_101 ;
struct V_102 * V_103 ;
V_100 = F_15 ( V_2 , V_104 , 0 , 0 ) ;
if ( V_100 >= 0 ) {
switch ( V_100 & 0xff ) {
case 0xf3 :
F_6 ( V_105 L_11 ) ;
if ( V_2 -> V_35 != V_106 )
V_2 -> V_35 = V_106 ;
break;
case 0xf4 :
F_6 ( V_105 L_12 ) ;
if ( V_2 -> V_35 != V_36 )
V_2 -> V_35 = V_36 ;
break;
default:
F_6 ( V_105 L_13 , V_100 ) ;
}
} else
F_6 ( V_107 L_14 , V_100 ) ;
if ( V_2 -> V_35 == V_36 ) {
V_103 = V_108 ;
V_101 = F_26 ( V_108 ) ;
} else {
V_103 = V_109 ;
V_101 = F_26 ( V_109 ) ;
}
for ( V_10 = 0 ; V_10 < V_101 ; V_10 ++ ) {
V_30 = F_11 ( V_2 , V_103 [ V_10 ] . V_4 , V_103 [ V_10 ] . V_110 , V_103 [ V_10 ] . V_37 ) ;
if ( V_30 < 0 ) {
F_6 ( V_107 L_15
L_16 , V_30 ,
V_103 [ V_10 ] . V_4 , V_103 [ V_10 ] . V_110 , V_103 [ V_10 ] . V_37 ) ;
return V_30 ;
}
}
F_17 ( 5 ) ;
V_30 = F_27 ( V_2 ) ;
return V_30 ;
}
int F_23 ( struct V_1 * V_2 , int V_111 )
{
int V_37 = 0 ;
T_1 V_112 = 0x60 ;
T_1 V_113 = 0x91 ;
switch ( V_111 ) {
case 48000 :
V_112 = 0x60 ;
V_113 = 0x91 ;
V_2 -> V_114 = V_111 ;
break;
case 32000 :
V_112 = 0x00 ;
V_113 = 0x90 ;
V_2 -> V_114 = V_111 ;
break;
default:
return - V_115 ;
}
if ( V_2 -> V_35 == V_36 ) {
V_37 = F_11 ( V_2 , V_116 , V_113 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_13 ( V_2 , V_117 ,
V_112 , 0xf0 ) ;
if ( V_37 < 0 )
return V_37 ;
} else {
V_37 = F_13 ( V_2 , V_98 ,
V_112 , 0xf0 ) ;
if ( V_37 < 0 )
return V_37 ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_35 == V_36 ) {
T_1 V_112 ;
T_1 V_118 = 0x10 ;
switch ( V_2 -> V_119 . V_120 ) {
case V_121 :
case V_122 :
V_112 = 0x03 ;
V_118 = 0x30 ;
break;
case V_123 :
V_112 = 0x00 ;
break;
case V_124 :
V_112 = 0x08 ;
break;
case V_125 :
V_112 = 0x04 ;
break;
default:
F_6 ( V_105 L_17 ,
V_2 -> V_126 ) ;
return 0 ;
break;
}
F_13 ( V_2 , V_117 ,
V_112 , 0x0f ) ;
F_13 ( V_2 , V_127 ,
V_118 , 0xf0 ) ;
} else {
T_1 V_128 ;
switch ( V_2 -> V_119 . V_120 ) {
case V_123 :
V_128 = 0x00 ;
break;
case V_124 :
V_128 = 0x04 ;
break;
default:
F_6 ( V_105 L_17 ,
V_2 -> V_126 ) ;
return 0 ;
break;
}
F_13 ( V_2 , V_98 ,
V_128 , 0x0f ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_129 )
{
T_1 V_130 = 0 ;
if ( V_129 )
V_130 = 0x08 ;
F_13 ( V_2 , V_116 , V_130 , 0x08 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_129 )
{
T_1 V_130 = 0 ;
if ( V_129 )
V_130 = 0x20 ;
if ( V_2 -> V_35 == V_36 ) {
F_13 ( V_2 , V_131 ,
V_130 , 0x20 ) ;
F_13 ( V_2 , V_132 ,
V_130 , 0x20 ) ;
} else {
F_13 ( V_2 , V_133 ,
V_130 , 0x20 ) ;
F_13 ( V_2 , V_134 ,
V_130 , 0x20 ) ;
}
}
int F_31 ( struct V_1 * V_2 , T_1 V_129 )
{
enum V_135 V_136 ;
if ( V_2 -> V_75 )
V_136 = V_2 -> V_119 . V_120 ;
else
V_136 = V_2 -> V_137 [ V_2 -> V_138 ] . V_120 ;
switch ( V_136 ) {
case V_121 :
case V_122 :
if ( V_2 -> V_35 == V_36 )
F_29 ( V_2 , V_129 ) ;
else {
F_6 ( V_105 L_18
L_19
L_20 , V_2 -> V_126 ) ;
return - V_115 ;
}
break;
case V_123 :
case V_124 :
F_30 ( V_2 , V_129 ) ;
break;
default:
return - V_115 ;
break;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , int V_139 )
{
T_1 V_140 ;
V_140 = V_139 & 0x0F ;
if ( V_139 < 0 )
V_140 |= 0x40 ;
F_11 ( V_2 , V_141 , V_140 ) ;
F_11 ( V_2 , V_142 , V_140 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_139 )
{
T_1 V_140 ;
V_140 = ( V_139 + 0x10 ) & 0x1f ;
if ( V_2 -> V_35 == V_36 ) {
F_11 ( V_2 , V_131 , V_140 ) ;
F_11 ( V_2 , V_132 , V_140 ) ;
} else {
F_11 ( V_2 , V_133 , V_140 ) ;
F_11 ( V_2 , V_134 , V_140 ) ;
}
}
void F_34 ( struct V_1 * V_2 , int V_139 )
{
enum V_135 V_136 ;
if ( V_2 -> V_75 ) {
V_136 = V_2 -> V_119 . V_120 ;
V_139 += 8 ;
} else
V_136 = V_2 -> V_137 [ V_2 -> V_138 ] . V_120 ;
switch ( V_136 ) {
case V_121 :
case V_122 :
if ( V_2 -> V_35 == V_36 )
F_32 ( V_2 , V_139 ) ;
else
F_6 ( V_105 L_18
L_19
L_20 , V_2 -> V_126 ) ;
break;
case V_123 :
case V_124 :
F_33 ( V_2 , V_139 ) ;
break;
default:
break;
}
}
void F_35 ( struct V_1 * V_2 )
{
F_2 ( & V_143 ) ;
F_36 ( & V_2 -> V_144 ) ;
F_10 ( & V_143 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_2 ( & V_143 ) ;
F_38 ( & V_2 -> V_144 , & V_145 ) ;
F_10 ( & V_143 ) ;
}
int F_39 ( struct V_1 * V_2 , enum V_146 type ,
char * V_7 , int V_101 )
{
struct V_147 * V_148 = NULL ;
if ( ! F_40 ( & V_149 ) ) {
F_41 (ops, &tm6000_extension_devlist, next) {
if ( V_148 -> V_150 && V_148 -> type == type )
V_148 -> V_150 ( V_2 , V_7 , V_101 ) ;
}
}
return 0 ;
}
int F_42 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = NULL ;
F_2 ( & V_143 ) ;
F_38 ( & V_148 -> V_151 , & V_149 ) ;
F_41 (dev, &tm6000_devlist, devlist) {
V_148 -> V_152 ( V_2 ) ;
F_6 ( V_105 L_21 ,
V_2 -> V_126 , V_148 -> V_126 ) ;
}
F_10 ( & V_143 ) ;
return 0 ;
}
void F_43 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = NULL ;
F_2 ( & V_143 ) ;
F_41 (dev, &tm6000_devlist, devlist)
V_148 -> V_153 ( V_2 ) ;
F_6 ( V_105 L_22 , V_148 -> V_126 ) ;
F_36 ( & V_148 -> V_151 ) ;
F_10 ( & V_143 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_147 * V_148 = NULL ;
F_2 ( & V_143 ) ;
if ( ! F_40 ( & V_149 ) ) {
F_41 (ops, &tm6000_extension_devlist, next) {
if ( V_148 -> V_152 )
V_148 -> V_152 ( V_2 ) ;
}
}
F_10 ( & V_143 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_147 * V_148 = NULL ;
F_2 ( & V_143 ) ;
if ( ! F_40 ( & V_149 ) ) {
F_41 (ops, &tm6000_extension_devlist, next) {
if ( V_148 -> V_153 )
V_148 -> V_153 ( V_2 ) ;
}
}
F_10 ( & V_143 ) ;
}
