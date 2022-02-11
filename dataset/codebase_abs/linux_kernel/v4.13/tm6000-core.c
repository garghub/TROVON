int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
int V_9 , V_10 ;
unsigned int V_11 ;
T_1 * V_12 = NULL ;
int V_13 = 5000 ;
if ( V_8 ) {
V_12 = F_2 ( V_8 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
}
F_3 ( & V_2 -> V_16 ) ;
if ( V_3 & V_17 )
V_11 = F_4 ( V_2 -> V_18 , 0 ) ;
else {
V_11 = F_5 ( V_2 -> V_18 , 0 ) ;
memcpy ( V_12 , V_7 , V_8 ) ;
}
if ( V_19 & V_20 ) {
F_6 ( V_21 L_1 , V_2 -> V_18 , V_11 ) ;
F_6 ( V_22 L_2 ,
( V_3 & V_17 ) ? L_3 : L_4 ,
V_3 , V_4 , V_5 & 0xff , V_5 >> 8 , V_6 & 0xff ,
V_6 >> 8 , V_8 & 0xff , V_8 >> 8 ) ;
if ( ! ( V_3 & V_17 ) ) {
F_6 ( V_22 L_5 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_6 ( V_22 L_6 , V_7 [ V_10 ] ) ;
F_6 ( V_22 L_7 ) ;
}
}
V_9 = F_7 ( V_2 -> V_18 , V_11 , V_4 , V_3 , V_5 , V_6 ,
V_12 , V_8 , V_23 ) ;
if ( V_3 & V_17 )
memcpy ( V_7 , V_12 , V_8 ) ;
if ( V_19 & V_20 ) {
if ( V_9 < 0 ) {
if ( V_3 & V_17 )
F_6 ( V_21 L_8 , V_8 ) ;
F_6 ( V_22 L_9 , V_24 , V_9 ) ;
} else if ( V_3 & V_17 ) {
F_6 ( V_22 L_10 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_6 ( V_22 L_6 , V_7 [ V_10 ] ) ;
F_6 ( V_22 L_7 ) ;
}
}
F_8 ( V_12 ) ;
if ( V_2 -> V_25 & V_26 )
V_13 = 0 ;
if ( V_4 == V_27 && ! ( V_3 & V_17 ) ) {
unsigned int V_28 ;
V_28 = ( V_8 * 200 ) + 200 ;
if ( V_28 < V_13 )
V_28 = V_13 ;
F_9 ( V_28 , V_28 + 1000 ) ;
}
else if ( V_13 )
F_9 ( V_13 , V_13 + 1000 ) ;
F_10 ( & V_2 -> V_16 ) ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
return
F_1 ( V_2 , V_29 | V_30 ,
V_4 , V_5 , V_6 , NULL , 0 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_31 ;
T_1 V_7 [ 1 ] ;
V_31 = F_1 ( V_2 , V_17 | V_30 , V_4 ,
V_5 , V_6 , V_7 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
return * V_7 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_32 )
{
int V_31 ;
T_1 V_7 [ 1 ] ;
T_1 V_33 ;
V_31 = F_1 ( V_2 , V_17 | V_30 , V_4 ,
V_5 , 0 , V_7 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
V_33 = ( V_7 [ 0 ] & ~ V_32 ) | ( V_6 & V_32 ) ;
if ( V_33 == V_7 [ 0 ] )
return 0 ;
return F_1 ( V_2 , V_29 | V_30 ,
V_4 , V_5 , V_33 , NULL , 0 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_31 ;
T_1 V_7 [ 2 ] ;
V_31 = F_1 ( V_2 , V_17 | V_30 , V_4 ,
V_5 , V_6 , V_7 , 2 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_7 [ 1 ] | V_7 [ 0 ] << 8 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_31 ;
T_1 V_7 [ 4 ] ;
V_31 = F_1 ( V_2 , V_17 | V_30 , V_4 ,
V_5 , V_6 , V_7 , 4 ) ;
if ( V_31 < 0 )
return V_31 ;
return V_7 [ 3 ] | V_7 [ 2 ] << 8 | V_7 [ 1 ] << 16 | V_7 [ 0 ] << 24 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_28 )
{
int V_31 ;
V_31 = F_11 ( V_2 , V_34 , V_35 , 0 ) ;
if ( V_31 < 0 )
return V_31 ;
F_17 ( V_28 ) ;
V_31 = F_11 ( V_2 , V_34 , V_35 , 1 ) ;
F_17 ( V_28 ) ;
return V_31 ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 == V_37 ) {
int V_38 ;
V_38 = F_12 ( V_2 , V_39 , 0 ) & 0xfc ;
if ( V_2 -> V_40 == V_41 )
F_11 ( V_2 , V_39 , V_38 ) ;
else
F_11 ( V_2 , V_39 , V_38 | 1 ) ;
} else {
if ( V_2 -> V_40 == V_41 )
F_11 ( V_2 , V_42 , 0xd0 ) ;
else
F_11 ( V_2 , V_42 , 0x90 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 == V_37 ) {
F_11 ( V_2 , V_43 , 0x01 ) ;
F_11 ( V_2 , V_44 , 0x27 ) ;
F_11 ( V_2 , V_45 , 0x55 ) ;
F_11 ( V_2 , V_46 , 0x66 ) ;
F_11 ( V_2 , V_47 , 0x66 ) ;
F_11 ( V_2 , V_48 , 0x66 ) ;
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
V_61 , 0x66 ) ;
F_11 ( V_2 ,
V_62 , 0x00 ) ;
F_11 ( V_2 ,
V_63 , 0x00 ) ;
F_11 ( V_2 ,
V_64 , 0x01 ) ;
F_11 ( V_2 ,
V_65 , 0x00 ) ;
F_11 ( V_2 ,
V_66 , 0x02 ) ;
F_11 ( V_2 , V_67 , 0x35 ) ;
F_11 ( V_2 , V_68 , 0xa0 ) ;
F_11 ( V_2 , V_69 , 0x11 ) ;
F_11 ( V_2 , V_70 , 0x4c ) ;
F_11 ( V_2 , V_71 , 0x01 ) ;
F_11 ( V_2 , V_43 , 0x00 ) ;
}
}
int F_20 ( struct V_1 * V_2 )
{
struct V_72 V_73 ;
if ( V_2 -> V_36 == V_37 ) {
T_1 V_74 = V_75 ;
if ( ! V_2 -> V_76 )
V_74 |= V_77 ;
F_13 ( V_2 , V_39 ,
V_74 , 0x60 ) ;
F_13 ( V_2 , V_78 ,
0x00 , 0x40 ) ;
} else {
F_11 ( V_2 , V_43 , 0x01 ) ;
if ( V_2 -> V_79 )
F_11 ( V_2 , V_78 , 0x20 ) ;
else
F_11 ( V_2 , V_78 , 0x80 ) ;
F_11 ( V_2 , V_80 , 0x88 ) ;
F_11 ( V_2 , V_81 , 0x23 ) ;
F_11 ( V_2 , V_82 , 0xc0 ) ;
F_11 ( V_2 , V_83 , 0xd8 ) ;
F_11 ( V_2 , V_84 , 0x06 ) ;
F_11 ( V_2 , V_85 , 0x1f ) ;
F_11 ( V_2 , V_86 , 0x08 ) ;
F_11 ( V_2 , V_86 , 0x00 ) ;
F_18 ( V_2 ) ;
F_11 ( V_2 , V_43 , 0x00 ) ;
}
F_17 ( 20 ) ;
V_73 . V_87 = V_2 -> V_88 ;
F_21 ( & V_2 -> V_89 , 0 , V_90 , V_91 , & V_73 ) ;
F_17 ( 100 ) ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
F_23 ( V_2 , 48000 ) ;
if ( V_2 -> V_92 . V_93 ) {
F_11 ( V_2 , V_34 ,
V_2 -> V_92 . V_93 , 0x01 ) ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 == V_37 ) {
F_13 ( V_2 , V_39 ,
0x00 , 0x60 ) ;
F_13 ( V_2 , V_78 ,
0x40 , 0x40 ) ;
F_11 ( V_2 , V_94 , 0x28 ) ;
F_11 ( V_2 , V_95 , 0xfc ) ;
F_11 ( V_2 , V_96 , 0xff ) ;
} else {
F_11 ( V_2 , V_86 , 0x08 ) ;
F_11 ( V_2 , V_86 , 0x00 ) ;
F_11 ( V_2 , V_43 , 0x01 ) ;
F_11 ( V_2 , V_85 , 0x08 ) ;
F_11 ( V_2 , V_97 , 0x0c ) ;
F_11 ( V_2 , V_98 , 0xff ) ;
F_11 ( V_2 , V_99 , 0xd8 ) ;
F_11 ( V_2 , V_78 , 0x40 ) ;
F_11 ( V_2 , V_42 , 0xd0 ) ;
F_11 ( V_2 , V_80 , 0x09 ) ;
F_11 ( V_2 , V_81 , 0x37 ) ;
F_11 ( V_2 , V_82 , 0xd8 ) ;
F_11 ( V_2 , V_83 , 0xc0 ) ;
F_11 ( V_2 , V_84 , 0x60 ) ;
F_11 ( V_2 , V_97 , 0x0c ) ;
F_11 ( V_2 , V_98 , 0xff ) ;
F_11 ( V_2 , V_99 , 0x08 ) ;
F_17 ( 50 ) ;
F_11 ( V_2 , V_100 , 0x0020 , 0x00 ) ;
F_17 ( 50 ) ;
F_11 ( V_2 , V_100 , 0x0020 , 0x01 ) ;
F_17 ( 50 ) ;
F_11 ( V_2 , V_100 , 0x0020 , 0x00 ) ;
F_17 ( 100 ) ;
}
if ( V_2 -> V_92 . V_93 ) {
F_11 ( V_2 , V_34 ,
V_2 -> V_92 . V_93 , 0x00 ) ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_101 , V_31 = 0 , V_10 , V_102 ;
struct V_103 * V_104 ;
V_101 = F_15 ( V_2 , V_105 , 0 , 0 ) ;
if ( V_101 >= 0 ) {
switch ( V_101 & 0xff ) {
case 0xf3 :
F_6 ( V_106 L_11 ) ;
if ( V_2 -> V_36 != V_107 )
V_2 -> V_36 = V_107 ;
break;
case 0xf4 :
F_6 ( V_106 L_12 ) ;
if ( V_2 -> V_36 != V_37 )
V_2 -> V_36 = V_37 ;
break;
default:
F_6 ( V_106 L_13 , V_101 ) ;
}
} else
F_6 ( V_108 L_14 , V_101 ) ;
if ( V_2 -> V_36 == V_37 ) {
V_104 = V_109 ;
V_102 = F_26 ( V_109 ) ;
} else {
V_104 = V_110 ;
V_102 = F_26 ( V_110 ) ;
}
for ( V_10 = 0 ; V_10 < V_102 ; V_10 ++ ) {
V_31 = F_11 ( V_2 , V_104 [ V_10 ] . V_4 , V_104 [ V_10 ] . V_111 , V_104 [ V_10 ] . V_38 ) ;
if ( V_31 < 0 ) {
F_6 ( V_108 L_15 ,
V_31 ,
V_104 [ V_10 ] . V_4 , V_104 [ V_10 ] . V_111 , V_104 [ V_10 ] . V_38 ) ;
return V_31 ;
}
}
F_17 ( 5 ) ;
V_31 = F_27 ( V_2 ) ;
return V_31 ;
}
int F_23 ( struct V_1 * V_2 , int V_112 )
{
int V_38 = 0 ;
T_1 V_113 = 0x60 ;
T_1 V_114 = 0x91 ;
switch ( V_112 ) {
case 48000 :
V_113 = 0x60 ;
V_114 = 0x91 ;
V_2 -> V_115 = V_112 ;
break;
case 32000 :
V_113 = 0x00 ;
V_114 = 0x90 ;
V_2 -> V_115 = V_112 ;
break;
default:
return - V_116 ;
}
if ( V_2 -> V_36 == V_37 ) {
V_38 = F_11 ( V_2 , V_117 , V_114 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_13 ( V_2 , V_118 ,
V_113 , 0xf0 ) ;
if ( V_38 < 0 )
return V_38 ;
} else {
V_38 = F_13 ( V_2 , V_99 ,
V_113 , 0xf0 ) ;
if ( V_38 < 0 )
return V_38 ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 == V_37 ) {
T_1 V_113 ;
T_1 V_119 = 0x10 ;
switch ( V_2 -> V_120 . V_121 ) {
case V_122 :
case V_123 :
V_113 = 0x03 ;
V_119 = 0x30 ;
break;
case V_124 :
V_113 = 0x00 ;
break;
case V_125 :
V_113 = 0x08 ;
break;
case V_126 :
V_113 = 0x04 ;
break;
default:
F_6 ( V_106 L_16 ,
V_2 -> V_127 ) ;
return 0 ;
break;
}
F_13 ( V_2 , V_118 ,
V_113 , 0x0f ) ;
F_13 ( V_2 , V_128 ,
V_119 , 0xf0 ) ;
} else {
T_1 V_129 ;
switch ( V_2 -> V_120 . V_121 ) {
case V_124 :
V_129 = 0x00 ;
break;
case V_125 :
V_129 = 0x04 ;
break;
default:
F_6 ( V_106 L_16 ,
V_2 -> V_127 ) ;
return 0 ;
break;
}
F_13 ( V_2 , V_99 ,
V_129 , 0x0f ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_130 )
{
T_1 V_131 = 0 ;
if ( V_130 )
V_131 = 0x08 ;
F_13 ( V_2 , V_117 , V_131 , 0x08 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_130 )
{
T_1 V_131 = 0 ;
if ( V_130 )
V_131 = 0x20 ;
if ( V_2 -> V_36 == V_37 ) {
F_13 ( V_2 , V_132 ,
V_131 , 0x20 ) ;
F_13 ( V_2 , V_133 ,
V_131 , 0x20 ) ;
} else {
F_13 ( V_2 , V_134 ,
V_131 , 0x20 ) ;
F_13 ( V_2 , V_135 ,
V_131 , 0x20 ) ;
}
}
int F_31 ( struct V_1 * V_2 , T_1 V_130 )
{
enum V_136 V_137 ;
if ( V_2 -> V_76 )
V_137 = V_2 -> V_120 . V_121 ;
else
V_137 = V_2 -> V_138 [ V_2 -> V_139 ] . V_121 ;
switch ( V_137 ) {
case V_122 :
case V_123 :
if ( V_2 -> V_36 == V_37 )
F_29 ( V_2 , V_130 ) ;
else {
F_6 ( V_106 L_17 ,
V_2 -> V_127 ) ;
return - V_116 ;
}
break;
case V_124 :
case V_125 :
F_30 ( V_2 , V_130 ) ;
break;
default:
return - V_116 ;
break;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , int V_140 )
{
T_1 V_141 ;
V_141 = V_140 & 0x0F ;
if ( V_140 < 0 )
V_141 |= 0x40 ;
F_11 ( V_2 , V_142 , V_141 ) ;
F_11 ( V_2 , V_143 , V_141 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_140 )
{
T_1 V_141 ;
V_141 = ( V_140 + 0x10 ) & 0x1f ;
if ( V_2 -> V_36 == V_37 ) {
F_11 ( V_2 , V_132 , V_141 ) ;
F_11 ( V_2 , V_133 , V_141 ) ;
} else {
F_11 ( V_2 , V_134 , V_141 ) ;
F_11 ( V_2 , V_135 , V_141 ) ;
}
}
void F_34 ( struct V_1 * V_2 , int V_140 )
{
enum V_136 V_137 ;
if ( V_2 -> V_76 ) {
V_137 = V_2 -> V_120 . V_121 ;
V_140 += 8 ;
} else
V_137 = V_2 -> V_138 [ V_2 -> V_139 ] . V_121 ;
switch ( V_137 ) {
case V_122 :
case V_123 :
if ( V_2 -> V_36 == V_37 )
F_32 ( V_2 , V_140 ) ;
else
F_6 ( V_106 L_17 ,
V_2 -> V_127 ) ;
break;
case V_124 :
case V_125 :
F_33 ( V_2 , V_140 ) ;
break;
default:
break;
}
}
void F_35 ( struct V_1 * V_2 )
{
F_3 ( & V_144 ) ;
F_36 ( & V_2 -> V_145 ) ;
F_10 ( & V_144 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_3 ( & V_144 ) ;
F_38 ( & V_2 -> V_145 , & V_146 ) ;
F_10 ( & V_144 ) ;
}
int F_39 ( struct V_1 * V_2 , enum V_147 type ,
char * V_7 , int V_102 )
{
struct V_148 * V_149 = NULL ;
if ( ! F_40 ( & V_150 ) ) {
F_41 (ops, &tm6000_extension_devlist, next) {
if ( V_149 -> V_151 && V_149 -> type == type )
V_149 -> V_151 ( V_2 , V_7 , V_102 ) ;
}
}
return 0 ;
}
int F_42 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = NULL ;
F_3 ( & V_144 ) ;
F_38 ( & V_149 -> V_152 , & V_150 ) ;
F_41 (dev, &tm6000_devlist, devlist) {
V_149 -> V_153 ( V_2 ) ;
F_6 ( V_106 L_18 ,
V_2 -> V_127 , V_149 -> V_127 ) ;
}
F_10 ( & V_144 ) ;
return 0 ;
}
void F_43 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = NULL ;
F_3 ( & V_144 ) ;
F_41 (dev, &tm6000_devlist, devlist)
V_149 -> V_154 ( V_2 ) ;
F_6 ( V_106 L_19 , V_149 -> V_127 ) ;
F_36 ( & V_149 -> V_152 ) ;
F_10 ( & V_144 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_148 * V_149 = NULL ;
F_3 ( & V_144 ) ;
if ( ! F_40 ( & V_150 ) ) {
F_41 (ops, &tm6000_extension_devlist, next) {
if ( V_149 -> V_153 )
V_149 -> V_153 ( V_2 ) ;
}
}
F_10 ( & V_144 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_148 * V_149 = NULL ;
F_3 ( & V_144 ) ;
if ( ! F_40 ( & V_150 ) ) {
F_41 (ops, &tm6000_extension_devlist, next) {
if ( V_149 -> V_154 )
V_149 -> V_154 ( V_2 ) ;
}
}
F_10 ( & V_144 ) ;
}
