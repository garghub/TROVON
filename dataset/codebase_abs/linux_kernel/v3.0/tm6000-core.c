int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_2 V_5 , T_2 V_6 , T_1 * V_7 , T_2 V_8 )
{
int V_9 , V_10 ;
unsigned int V_11 ;
T_1 * V_12 = NULL ;
if ( V_8 )
V_12 = F_2 ( V_8 , V_13 ) ;
if ( V_3 & V_14 )
V_11 = F_3 ( V_2 -> V_15 , 0 ) ;
else {
V_11 = F_4 ( V_2 -> V_15 , 0 ) ;
memcpy ( V_12 , V_7 , V_8 ) ;
}
if ( V_16 & V_17 ) {
F_5 ( L_1 , V_2 -> V_15 , V_11 ) ;
F_5 ( L_2 ,
( V_3 & V_14 ) ? L_3 : L_4 ,
V_3 , V_4 , V_5 & 0xff , V_5 >> 8 , V_6 & 0xff ,
V_6 >> 8 , V_8 & 0xff , V_8 >> 8 ) ;
if ( ! ( V_3 & V_14 ) ) {
F_5 ( L_5 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_5 ( L_6 , V_7 [ V_10 ] ) ;
F_5 ( L_7 ) ;
}
}
V_9 = F_6 ( V_2 -> V_15 , V_11 , V_4 , V_3 , V_5 , V_6 ,
V_12 , V_8 , V_18 ) ;
if ( V_3 & V_14 )
memcpy ( V_7 , V_12 , V_8 ) ;
if ( V_16 & V_17 ) {
if ( V_9 < 0 ) {
if ( V_3 & V_14 )
F_5 ( L_8 , V_8 ) ;
F_5 ( L_9 , V_19 , V_9 ) ;
} else if ( V_3 & V_14 ) {
F_5 ( L_10 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_5 ( L_6 , V_7 [ V_10 ] ) ;
F_5 ( L_7 ) ;
}
}
F_7 ( V_12 ) ;
F_8 ( 5 ) ;
return V_9 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
return
F_1 ( V_2 , V_20 | V_21 ,
V_4 , V_5 , V_6 , NULL , 0 ) ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_22 ;
T_1 V_7 [ 1 ] ;
V_22 = F_1 ( V_2 , V_14 | V_21 , V_4 ,
V_5 , V_6 , V_7 , 1 ) ;
if ( V_22 < 0 )
return V_22 ;
return * V_7 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_23 )
{
int V_22 ;
T_1 V_7 [ 1 ] ;
T_1 V_24 ;
V_22 = F_1 ( V_2 , V_14 | V_21 , V_4 ,
V_5 , V_6 , V_7 , 1 ) ;
if ( V_22 < 0 )
return V_22 ;
V_24 = ( V_7 [ 0 ] & ~ V_23 ) | ( V_6 & V_23 ) ;
if ( V_24 == V_6 )
return 0 ;
return F_1 ( V_2 , V_20 | V_21 ,
V_4 , V_5 , V_24 , NULL , 0 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_22 ;
T_1 V_7 [ 2 ] ;
V_22 = F_1 ( V_2 , V_14 | V_21 , V_4 ,
V_5 , V_6 , V_7 , 2 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_7 [ 1 ] | V_7 [ 0 ] << 8 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_4 , T_2 V_5 , T_2 V_6 )
{
int V_22 ;
T_1 V_7 [ 4 ] ;
V_22 = F_1 ( V_2 , V_14 | V_21 , V_4 ,
V_5 , V_6 , V_7 , 4 ) ;
if ( V_22 < 0 )
return V_22 ;
return V_7 [ 3 ] | V_7 [ 2 ] << 8 | V_7 [ 1 ] << 16 | V_7 [ 0 ] << 24 ;
}
int F_14 ( struct V_1 * V_2 , T_2 V_25 )
{
int V_22 ;
V_22 = F_9 ( V_2 , V_26 , V_27 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
F_8 ( V_25 ) ;
V_22 = F_9 ( V_2 , V_26 , V_27 , 1 ) ;
F_8 ( V_25 ) ;
return V_22 ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 == V_29 ) {
int V_30 ;
V_30 = F_10 ( V_2 , V_31 , 0 ) & 0xfc ;
if ( V_2 -> V_32 == V_33 )
F_9 ( V_2 , V_31 , V_30 ) ;
else
F_9 ( V_2 , V_31 , V_30 | 1 ) ;
} else {
if ( V_2 -> V_32 == V_33 )
F_9 ( V_2 , V_34 , 0xd0 ) ;
else
F_9 ( V_2 , V_34 , 0x90 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 == V_29 ) {
F_9 ( V_2 , V_35 , 0x01 ) ;
F_9 ( V_2 , V_36 , 0x27 ) ;
F_9 ( V_2 , V_37 , 0x55 ) ;
F_9 ( V_2 , V_38 , 0x66 ) ;
F_9 ( V_2 , V_39 , 0x66 ) ;
F_9 ( V_2 , V_40 , 0x66 ) ;
F_9 ( V_2 ,
V_41 , 0x66 ) ;
F_9 ( V_2 ,
V_42 , 0x66 ) ;
F_9 ( V_2 ,
V_43 , 0x66 ) ;
F_9 ( V_2 ,
V_44 , 0x66 ) ;
F_9 ( V_2 ,
V_45 , 0x66 ) ;
F_9 ( V_2 ,
V_46 , 0x66 ) ;
F_9 ( V_2 ,
V_47 , 0x66 ) ;
F_9 ( V_2 ,
V_48 , 0x66 ) ;
F_9 ( V_2 ,
V_49 , 0x66 ) ;
F_9 ( V_2 ,
V_50 , 0x66 ) ;
F_9 ( V_2 ,
V_51 , 0x66 ) ;
F_9 ( V_2 ,
V_52 , 0x66 ) ;
F_9 ( V_2 ,
V_53 , 0x66 ) ;
F_9 ( V_2 ,
V_54 , 0x00 ) ;
F_9 ( V_2 ,
V_55 , 0x00 ) ;
F_9 ( V_2 ,
V_56 , 0x01 ) ;
F_9 ( V_2 ,
V_57 , 0x00 ) ;
F_9 ( V_2 ,
V_58 , 0x02 ) ;
F_9 ( V_2 , V_59 , 0x35 ) ;
F_9 ( V_2 , V_60 , 0xa0 ) ;
F_9 ( V_2 , V_61 , 0x11 ) ;
F_9 ( V_2 , V_62 , 0x4c ) ;
F_9 ( V_2 , V_63 , 0x01 ) ;
F_9 ( V_2 , V_35 , 0x00 ) ;
}
}
int F_17 ( struct V_1 * V_2 )
{
struct V_64 V_65 ;
if ( V_2 -> V_28 == V_29 ) {
F_11 ( V_2 , V_31 ,
0x60 , 0x60 ) ;
F_11 ( V_2 , V_66 ,
0x00 , 0x40 ) ;
} else {
F_9 ( V_2 , V_35 , 0x01 ) ;
if ( V_2 -> V_67 )
F_9 ( V_2 , V_66 , 0x20 ) ;
else
F_9 ( V_2 , V_66 , 0x80 ) ;
F_9 ( V_2 , V_68 , 0x88 ) ;
F_9 ( V_2 , V_69 , 0x23 ) ;
F_9 ( V_2 , V_70 , 0xc0 ) ;
F_9 ( V_2 , V_71 , 0xd8 ) ;
F_9 ( V_2 , V_72 , 0x06 ) ;
F_9 ( V_2 , V_73 , 0x1f ) ;
F_9 ( V_2 , V_74 , 0x08 ) ;
F_9 ( V_2 , V_74 , 0x00 ) ;
F_15 ( V_2 ) ;
F_9 ( V_2 , V_35 , 0x00 ) ;
}
F_8 ( 20 ) ;
V_65 . V_75 = V_2 -> V_76 ;
F_18 ( & V_2 -> V_77 , 0 , V_78 , V_79 , & V_65 ) ;
F_8 ( 100 ) ;
F_19 ( V_2 ) ;
F_16 ( V_2 ) ;
F_20 ( V_2 , 48000 ) ;
if ( V_2 -> V_80 . V_81 ) {
F_9 ( V_2 , V_26 ,
V_2 -> V_80 . V_81 , 0x01 ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 == V_29 ) {
F_11 ( V_2 , V_31 ,
0x00 , 0x60 ) ;
F_11 ( V_2 , V_66 ,
0x40 , 0x40 ) ;
F_9 ( V_2 , V_82 , 0x28 ) ;
F_9 ( V_2 , V_83 , 0xfc ) ;
F_9 ( V_2 , V_84 , 0xff ) ;
} else {
F_9 ( V_2 , V_74 , 0x08 ) ;
F_9 ( V_2 , V_74 , 0x00 ) ;
F_9 ( V_2 , V_35 , 0x01 ) ;
F_9 ( V_2 , V_73 , 0x08 ) ;
F_9 ( V_2 , V_85 , 0x0c ) ;
F_9 ( V_2 , V_86 , 0xff ) ;
F_9 ( V_2 , V_87 , 0xd8 ) ;
F_9 ( V_2 , V_66 , 0x40 ) ;
F_9 ( V_2 , V_34 , 0xd0 ) ;
F_9 ( V_2 , V_68 , 0x09 ) ;
F_9 ( V_2 , V_69 , 0x37 ) ;
F_9 ( V_2 , V_70 , 0xd8 ) ;
F_9 ( V_2 , V_71 , 0xc0 ) ;
F_9 ( V_2 , V_72 , 0x60 ) ;
F_9 ( V_2 , V_85 , 0x0c ) ;
F_9 ( V_2 , V_86 , 0xff ) ;
F_9 ( V_2 , V_87 , 0x08 ) ;
F_8 ( 50 ) ;
F_9 ( V_2 , V_88 , 0x0020 , 0x00 ) ;
F_8 ( 50 ) ;
F_9 ( V_2 , V_88 , 0x0020 , 0x01 ) ;
F_8 ( 50 ) ;
F_9 ( V_2 , V_88 , 0x0020 , 0x00 ) ;
F_8 ( 100 ) ;
}
if ( V_2 -> V_80 . V_81 ) {
F_9 ( V_2 , V_26 ,
V_2 -> V_80 . V_81 , 0x00 ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_89 , V_22 = 0 , V_10 , V_90 ;
struct V_91 * V_92 ;
V_89 = F_13 ( V_2 , V_93 , 0 , 0 ) ;
if ( V_89 >= 0 ) {
switch ( V_89 & 0xff ) {
case 0xf3 :
F_5 ( V_94 L_11 ) ;
if ( V_2 -> V_28 != V_95 )
V_2 -> V_28 = V_95 ;
break;
case 0xf4 :
F_5 ( V_94 L_12 ) ;
if ( V_2 -> V_28 != V_29 )
V_2 -> V_28 = V_29 ;
break;
default:
F_5 ( V_94 L_13 , V_89 ) ;
}
} else
F_5 ( V_96 L_14 , V_89 ) ;
if ( V_2 -> V_28 == V_29 ) {
V_92 = V_97 ;
V_90 = F_23 ( V_97 ) ;
} else {
V_92 = V_98 ;
V_90 = F_23 ( V_98 ) ;
}
for ( V_10 = 0 ; V_10 < V_90 ; V_10 ++ ) {
V_22 = F_9 ( V_2 , V_92 [ V_10 ] . V_4 , V_92 [ V_10 ] . V_99 , V_92 [ V_10 ] . V_30 ) ;
if ( V_22 < 0 ) {
F_5 ( V_96 L_15
L_16 , V_22 ,
V_92 [ V_10 ] . V_4 , V_92 [ V_10 ] . V_99 , V_92 [ V_10 ] . V_30 ) ;
return V_22 ;
}
}
F_8 ( 5 ) ;
V_22 = F_24 ( V_2 ) ;
return V_22 ;
}
int F_20 ( struct V_1 * V_2 , int V_100 )
{
int V_30 = 0 ;
T_1 V_101 = 0x60 ;
T_1 V_102 = 0x91 ;
switch ( V_100 ) {
case 48000 :
V_101 = 0x60 ;
V_102 = 0x91 ;
V_2 -> V_103 = V_100 ;
break;
case 32000 :
V_101 = 0x00 ;
V_102 = 0x90 ;
V_2 -> V_103 = V_100 ;
break;
default:
return - V_104 ;
}
if ( V_2 -> V_28 == V_29 ) {
V_30 = F_9 ( V_2 , V_105 , V_102 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_11 ( V_2 , V_106 ,
V_101 , 0xf0 ) ;
if ( V_30 < 0 )
return V_30 ;
} else {
V_30 = F_11 ( V_2 , V_87 ,
V_101 , 0xf0 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 == V_29 ) {
T_1 V_101 ;
switch ( V_2 -> V_107 . V_108 ) {
case V_109 :
case V_110 :
V_101 = 0x03 ;
break;
case V_111 :
V_101 = 0x00 ;
break;
case V_112 :
V_101 = 0x08 ;
break;
case V_113 :
V_101 = 0x04 ;
break;
default:
F_5 ( V_94 L_17 ,
V_2 -> V_114 ) ;
return 0 ;
break;
}
F_11 ( V_2 , V_106 ,
V_101 , 0x0f ) ;
} else {
T_1 V_115 ;
switch ( V_2 -> V_107 . V_108 ) {
case V_111 :
V_115 = 0x00 ;
break;
case V_112 :
V_115 = 0x04 ;
break;
default:
F_5 ( V_94 L_17 ,
V_2 -> V_114 ) ;
return 0 ;
break;
}
F_11 ( V_2 , V_87 ,
V_115 , 0x0f ) ;
}
return 0 ;
}
void F_26 ( struct V_1 * V_2 , T_1 V_116 )
{
T_1 V_117 = 0 ;
if ( V_116 )
V_117 = 0x08 ;
F_11 ( V_2 , V_105 , V_117 , 0x08 ) ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_116 )
{
T_1 V_117 = 0 ;
if ( V_116 )
V_117 = 0x20 ;
if ( V_2 -> V_28 == V_29 ) {
F_11 ( V_2 , V_118 ,
V_117 , 0x20 ) ;
F_11 ( V_2 , V_119 ,
V_117 , 0x20 ) ;
} else {
F_11 ( V_2 , V_120 ,
V_117 , 0x20 ) ;
F_11 ( V_2 , V_121 ,
V_117 , 0x20 ) ;
}
}
int F_28 ( struct V_1 * V_2 , T_1 V_116 )
{
enum V_122 V_123 ;
if ( V_2 -> V_124 )
V_123 = V_2 -> V_107 . V_108 ;
else
V_123 = V_2 -> V_125 [ V_2 -> V_126 ] . V_108 ;
switch ( V_123 ) {
case V_109 :
case V_110 :
if ( V_2 -> V_28 == V_29 )
F_26 ( V_2 , V_116 ) ;
else {
F_5 ( V_94 L_18
L_19
L_20 , V_2 -> V_114 ) ;
return - V_104 ;
}
break;
case V_111 :
case V_112 :
F_27 ( V_2 , V_116 ) ;
break;
default:
return - V_104 ;
break;
}
return 0 ;
}
void F_29 ( struct V_1 * V_2 , int V_127 )
{
T_1 V_128 ;
V_128 = V_127 & 0x0F ;
if ( V_127 < 0 )
V_128 |= 0x40 ;
F_9 ( V_2 , V_129 , V_128 ) ;
F_9 ( V_2 , V_130 , V_128 ) ;
}
void F_30 ( struct V_1 * V_2 , int V_127 )
{
T_1 V_128 ;
V_128 = ( V_127 + 0x10 ) & 0x1f ;
if ( V_2 -> V_28 == V_29 ) {
F_9 ( V_2 , V_118 , V_128 ) ;
F_9 ( V_2 , V_119 , V_128 ) ;
} else {
F_9 ( V_2 , V_120 , V_128 ) ;
F_9 ( V_2 , V_121 , V_128 ) ;
}
}
void F_31 ( struct V_1 * V_2 , int V_127 )
{
enum V_122 V_123 ;
if ( V_2 -> V_124 ) {
V_123 = V_2 -> V_107 . V_108 ;
V_127 += 8 ;
} else
V_123 = V_2 -> V_125 [ V_2 -> V_126 ] . V_108 ;
switch ( V_123 ) {
case V_109 :
case V_110 :
if ( V_2 -> V_28 == V_29 )
F_29 ( V_2 , V_127 ) ;
else
F_5 ( V_94 L_18
L_19
L_20 , V_2 -> V_114 ) ;
break;
case V_111 :
case V_112 :
F_30 ( V_2 , V_127 ) ;
break;
default:
break;
}
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( & V_131 ) ;
F_34 ( & V_2 -> V_132 ) ;
F_35 ( & V_131 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_33 ( & V_131 ) ;
F_37 ( & V_2 -> V_132 , & V_133 ) ;
F_35 ( & V_131 ) ;
}
int F_38 ( struct V_1 * V_2 , enum V_134 type ,
char * V_7 , int V_90 )
{
struct V_135 * V_136 = NULL ;
if ( ! F_39 ( & V_137 ) ) {
F_40 (ops, &tm6000_extension_devlist, next) {
if ( V_136 -> V_138 && V_136 -> type == type )
V_136 -> V_138 ( V_2 , V_7 , V_90 ) ;
}
}
return 0 ;
}
int F_41 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = NULL ;
F_33 ( & V_131 ) ;
F_37 ( & V_136 -> V_139 , & V_137 ) ;
F_40 (dev, &tm6000_devlist, devlist) {
V_136 -> V_140 ( V_2 ) ;
F_5 ( V_94 L_21 ,
V_2 -> V_114 , V_136 -> V_114 ) ;
}
F_35 ( & V_131 ) ;
return 0 ;
}
void F_42 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = NULL ;
F_33 ( & V_131 ) ;
F_40 (dev, &tm6000_devlist, devlist)
V_136 -> V_141 ( V_2 ) ;
F_5 ( V_94 L_22 , V_136 -> V_114 ) ;
F_34 ( & V_136 -> V_139 ) ;
F_35 ( & V_131 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = NULL ;
F_33 ( & V_131 ) ;
if ( ! F_39 ( & V_137 ) ) {
F_40 (ops, &tm6000_extension_devlist, next) {
if ( V_136 -> V_140 )
V_136 -> V_140 ( V_2 ) ;
}
}
F_35 ( & V_131 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_135 * V_136 = NULL ;
F_33 ( & V_131 ) ;
if ( ! F_39 ( & V_137 ) ) {
F_40 (ops, &tm6000_extension_devlist, next) {
if ( V_136 -> V_141 )
V_136 -> V_141 ( V_2 ) ;
}
}
F_35 ( & V_131 ) ;
}
