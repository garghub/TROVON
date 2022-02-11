static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
int V_8 , V_9 , V_10 , V_11 ;
T_1 V_12 ;
T_2 V_13 , V_14 ;
V_7 = V_2 -> V_15 -> V_16 ;
V_8 = V_4 -> V_17 ? V_4 -> V_17 : 640 ;
V_9 = V_4 -> V_18 ? V_4 -> V_18 : 480 ;
V_10 = V_2 -> V_19 ? F_3 ( V_2 ) -> V_20 -> V_21 [ 0 ] * 8 : 32 ;
V_11 = V_2 -> V_19 ? F_3 ( V_2 ) -> V_22 [ 0 ] : V_8 * V_10 / 8 ;
V_13 = V_7 -> V_23 ? V_2 -> V_24 : V_5 -> V_25 ;
V_14 = V_7 -> V_23 ? V_2 -> V_26 : V_5 -> V_27 ;
if ( V_5 -> V_28 == 0 && V_2 -> V_19 &&
V_5 -> V_29 / V_11 < 0xffff - V_2 -> V_26 &&
V_5 -> V_29 % ( V_10 / 8 ) == 0 ) {
F_4 ( V_30 , V_8 ) ;
F_4 ( V_31 , V_9 ) ;
F_4 ( V_32 , V_11 * 8 / V_10 ) ;
F_4 ( V_33 ,
F_3 ( V_2 ) -> V_20 -> V_21 [ 0 ] * 8 ) ;
F_4 ( V_34 , V_35 ) ;
F_4 (
V_36 ,
V_5 -> V_29 % V_11 / V_10 * 8 + V_2 -> V_24 ) ;
F_4 ( V_37 ,
V_5 -> V_29 / V_11 + V_2 -> V_26 ) ;
}
V_12 = V_38 ;
V_12 |= ( V_2 -> V_19 && ! V_5 -> V_39 ) ?
0 : V_40 ;
V_12 |= V_5 -> V_41 ? V_42 : 0 ;
F_5 ( V_7 -> V_43 , V_5 -> V_28 ,
V_13 , V_14 ,
V_2 -> V_24 * V_10 / 8 + V_2 -> V_26 * V_11 ,
V_11 , V_8 , V_9 ,
V_5 -> V_39 ? 0 : V_10 , V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_15 -> V_16 ;
struct V_44 * V_45 ;
V_45 = F_7 ( V_7 -> V_43 , sizeof( * V_45 ) ,
V_46 , V_47 ) ;
if ( ! V_45 )
return - V_48 ;
V_45 -> V_49 = V_5 -> V_28 ;
V_45 -> V_50 = V_5 -> V_29 ;
V_45 -> V_51 = V_7 -> V_52 - V_5 -> V_29 +
V_5 -> V_28 * V_53 ;
V_45 -> V_54 = V_7 -> V_52 - V_5 -> V_29 ;
F_8 ( V_7 -> V_43 , V_45 ) ;
F_9 ( V_7 -> V_43 , V_45 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_2 -> V_15 -> V_16 ;
switch ( V_4 ) {
case V_55 :
V_5 -> V_39 = false ;
break;
case V_56 :
case V_57 :
case V_58 :
V_5 -> V_39 = true ;
break;
}
F_11 ( & V_7 -> V_59 ) ;
F_1 ( V_2 , & V_2 -> V_60 ) ;
F_12 ( & V_7 -> V_59 ) ;
}
static bool F_13 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_61 )
{
return true ;
}
static bool F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_62 ;
struct V_63 * V_64 ;
struct V_65 * V_66 = NULL ;
bool V_23 = true ;
bool V_67 = V_7 -> V_23 ;
T_1 V_8 = 0 , V_9 = 0 ;
F_15 (crtci, &vbox->dev->mode_config.crtc_list, head) {
if ( ! V_66 ) {
V_66 = F_3 ( V_62 ) ;
if ( F_16 ( V_66 ) == & V_7 -> V_68 -> V_69 )
break;
} else if ( F_3 ( V_62 ) && V_66 != F_3 ( V_62 ) ) {
V_23 = false ;
}
}
if ( V_23 ) {
F_15 (crtci, &vbox->dev->mode_config.crtc_list,
head) {
if ( F_2 ( V_62 ) -> V_28 != 0 )
continue;
V_7 -> V_23 = true ;
V_7 -> V_70 = F_3 ( V_62 ) -> V_8 ;
V_7 -> V_71 = F_3 ( V_62 ) -> V_9 ;
return V_67 !=
V_7 -> V_23 ;
}
}
F_15 (connectori, &vbox->dev->mode_config.connector_list,
head) {
struct V_72 * V_72 =
F_17 ( V_64 ) ;
struct V_5 * V_5 = V_72 -> V_5 ;
V_8 = F_18 ( T_1 , V_8 , V_5 -> V_25 +
V_72 -> V_73 . V_8 ) ;
V_9 = F_18 ( T_1 , V_9 , V_5 -> V_27 +
V_72 -> V_73 . V_9 ) ;
}
V_7 -> V_23 = false ;
V_7 -> V_70 = V_8 ;
V_7 -> V_71 = V_9 ;
return V_67 != V_7 -> V_23 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_65 * V_74 , int V_24 , int V_26 )
{
struct V_6 * V_7 = V_2 -> V_15 -> V_16 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
int V_81 ;
T_3 V_82 ;
if ( V_74 ) {
V_78 = F_16 ( V_74 ) ;
V_76 = V_78 -> V_76 ;
V_80 = F_20 ( V_76 ) ;
V_81 = F_21 ( V_80 , false ) ;
if ( V_81 )
return V_81 ;
F_22 ( V_80 ) ;
F_23 ( V_80 ) ;
}
V_78 = F_16 ( F_3 ( V_2 ) ) ;
V_76 = V_78 -> V_76 ;
V_80 = F_20 ( V_76 ) ;
V_81 = F_21 ( V_80 , false ) ;
if ( V_81 )
return V_81 ;
V_81 = F_24 ( V_80 , V_83 , & V_82 ) ;
if ( V_81 ) {
F_23 ( V_80 ) ;
return V_81 ;
}
if ( & V_7 -> V_68 -> V_69 == V_78 )
F_25 ( V_7 , V_82 ) ;
F_23 ( V_80 ) ;
V_5 -> V_29 = V_82 ;
if ( F_14 ( V_7 ) ) {
struct V_1 * V_62 ;
F_15 (crtci, &vbox->dev->mode_config.crtc_list,
head) {
F_6 ( V_2 ) ;
F_1 ( V_62 , & V_62 -> V_4 ) ;
}
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_24 , int V_26 ,
struct V_65 * V_74 )
{
return F_19 ( V_2 , V_74 , V_24 , V_26 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_61 ,
int V_24 , int V_26 , struct V_65 * V_74 )
{
struct V_6 * V_7 = V_2 -> V_15 -> V_16 ;
int V_81 ;
F_26 ( V_2 , V_24 , V_26 , V_74 ) ;
F_11 ( & V_7 -> V_59 ) ;
V_81 = F_6 ( V_2 ) ;
if ( ! V_81 )
F_1 ( V_2 , V_4 ) ;
F_28 ( V_7 -> V_43 , 0 , 0 ,
V_7 -> V_70 ,
V_7 -> V_71 ) ;
F_12 ( & V_7 -> V_59 ) ;
return V_81 ;
}
static void F_29 ( struct V_1 * V_2 )
{
}
static void F_30 ( struct V_1 * V_2 )
{
}
static void F_31 ( struct V_1 * V_2 )
{
}
static void F_32 ( struct V_1 * V_2 )
{
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
}
static struct V_5 * F_36 ( struct V_84 * V_15 , unsigned int V_85 )
{
struct V_5 * V_5 ;
V_5 = F_37 ( sizeof( * V_5 ) , V_86 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_28 = V_85 ;
F_38 ( V_15 , & V_5 -> V_87 , & V_88 ) ;
F_39 ( & V_5 -> V_87 , 256 ) ;
F_40 ( & V_5 -> V_87 , & V_89 ) ;
return V_5 ;
}
static void F_41 ( struct V_90 * V_91 )
{
F_42 ( V_91 ) ;
F_35 ( V_91 ) ;
}
static struct V_90 * F_43 ( struct V_63
* V_92 )
{
int V_93 = V_92 -> V_94 [ 0 ] ;
if ( V_93 )
return F_44 ( V_92 -> V_15 , V_93 ) ;
return NULL ;
}
static void F_45 ( struct V_90 * V_91 , int V_4 )
{
}
static bool F_46 ( struct V_90 * V_91 ,
const struct V_3 * V_4 ,
struct V_3 * V_61 )
{
return true ;
}
static void F_47 ( struct V_90 * V_91 ,
struct V_3 * V_4 ,
struct V_3 * V_61 )
{
}
static void F_48 ( struct V_90 * V_91 )
{
}
static void F_49 ( struct V_90 * V_91 )
{
}
static struct V_90 * F_50 ( struct V_84 * V_15 ,
unsigned int V_85 )
{
struct V_95 * V_95 ;
V_95 = F_37 ( sizeof( * V_95 ) , V_86 ) ;
if ( ! V_95 )
return NULL ;
F_51 ( V_15 , & V_95 -> V_87 , & V_96 ,
V_97 , NULL ) ;
F_52 ( & V_95 -> V_87 , & V_98 ) ;
V_95 -> V_87 . V_99 = 1 << V_85 ;
return & V_95 -> V_87 ;
}
static void F_53 ( struct V_63 * V_92 , int V_8 ,
int V_9 )
{
enum { V_100 = 128 };
unsigned char V_101 [ V_100 ] = {
0x00 , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0x00 ,
0x58 , 0x58 ,
0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x01 ,
0x00 ,
0x01 , 0x03 ,
0x80 ,
0x00 ,
0x00 ,
0x78 ,
0xEE ,
0xEE , 0x91 , 0xA3 , 0x54 , 0x4C , 0x99 , 0x26 , 0x0F , 0x50 , 0x54 ,
0x00 , 0x00 , 0x00 ,
0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
0x01 , 0x01 ,
0x01 , 0x01 , 0x01 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x06 , 0x00 , 0x00 , 0x06 , 0x00 , 0x02 , 0x02 ,
0x02 , 0x02 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0xFD , 0x00 ,
0x00 , 0xC8 , 0x00 , 0xC8 , 0x64 , 0x00 , 0x0A , 0x20 , 0x20 , 0x20 ,
0x20 , 0x20 ,
0x20 ,
0x00 , 0x00 , 0x00 , 0xFC , 0x00 ,
'V' , 'B' , 'O' , 'X' , ' ' , 'm' , 'o' , 'n' , 'i' , 't' , 'o' , 'r' ,
'\n' ,
0x00 , 0x00 , 0x00 , 0x10 , 0x00 ,
0x0A , 0x20 , 0x20 , 0x20 , 0x20 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x20 ,
0x20 ,
0x00 ,
0x00
} ;
int clock = ( V_8 + 6 ) * ( V_9 + 6 ) * 60 / 10000 ;
unsigned int V_85 , V_102 = 0 ;
V_101 [ 12 ] = V_8 & 0xff ;
V_101 [ 13 ] = V_8 >> 8 ;
V_101 [ 14 ] = V_9 & 0xff ;
V_101 [ 15 ] = V_9 >> 8 ;
V_101 [ 54 ] = clock & 0xff ;
V_101 [ 55 ] = clock >> 8 ;
V_101 [ 56 ] = V_8 & 0xff ;
V_101 [ 58 ] = ( V_8 >> 4 ) & 0xf0 ;
V_101 [ 59 ] = V_9 & 0xff ;
V_101 [ 61 ] = ( V_9 >> 4 ) & 0xf0 ;
for ( V_85 = 0 ; V_85 < V_100 - 1 ; ++ V_85 )
V_102 += V_101 [ V_85 ] ;
V_101 [ V_100 - 1 ] = ( 0x100 - ( V_102 & 0xFF ) ) & 0xFF ;
F_54 ( V_92 , (struct V_101 * ) V_101 ) ;
}
static int F_55 ( struct V_63 * V_92 )
{
struct V_72 * V_72 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_6 * V_7 = NULL ;
unsigned int V_103 = 0 ;
int V_104 , V_105 ;
V_72 = F_17 ( V_92 ) ;
V_7 = V_92 -> V_15 -> V_16 ;
F_56 ( V_7 -> V_43 , F_57 ( V_7 ) +
V_106 ) ;
if ( V_72 -> V_5 -> V_28 == 0 )
F_58 ( V_7 ) ;
if ( ! V_7 -> V_107 ) {
if ( V_72 -> V_5 -> V_28 == 0 ) {
V_7 -> V_107 = true ;
F_59 ( V_7 ) ;
}
return F_60 ( V_92 , 800 , 600 ) ;
}
V_103 = F_60 ( V_92 , 2560 , 1600 ) ;
V_104 = V_72 -> V_73 . V_8 ?
V_72 -> V_73 . V_8 : 1024 ;
V_105 = V_72 -> V_73 . V_9 ?
V_72 -> V_73 . V_9 : 768 ;
V_4 = F_61 ( V_92 -> V_15 , V_104 , V_105 ,
60 , false , false , false ) ;
if ( V_4 ) {
V_4 -> type |= V_108 ;
F_62 ( V_92 , V_4 ) ;
++ V_103 ;
}
F_53 ( V_92 , V_104 , V_105 ) ;
F_63 (
& V_92 -> V_87 , V_7 -> V_15 -> V_109 . V_110 ,
V_72 -> V_5 -> V_25 ) ;
F_63 (
& V_92 -> V_87 , V_7 -> V_15 -> V_109 . V_111 ,
V_72 -> V_5 -> V_27 ) ;
return V_103 ;
}
static int F_64 ( struct V_63 * V_92 ,
struct V_3 * V_4 )
{
return V_112 ;
}
static void F_65 ( struct V_63 * V_92 )
{
F_66 ( V_92 ) ;
F_67 ( V_92 ) ;
F_35 ( V_92 ) ;
}
static enum V_113
F_68 ( struct V_63 * V_92 , bool V_114 )
{
struct V_72 * V_72 ;
V_72 = F_17 ( V_92 ) ;
return V_72 -> V_73 . V_41 ?
V_115 : V_116 ;
}
static int F_69 ( struct V_63 * V_92 , T_4 V_117 ,
T_4 V_118 )
{
struct V_72 * V_72 ;
struct V_84 * V_15 ;
struct V_3 * V_4 , * V_119 ;
V_72 = F_17 ( V_92 ) ;
V_15 = V_72 -> V_87 . V_15 ;
F_70 (mode, iterator, &connector->modes, head) {
F_71 ( & V_4 -> V_120 ) ;
F_72 ( V_15 , V_4 ) ;
}
return F_73 ( V_92 , V_117 , V_118 ) ;
}
static int F_74 ( struct V_84 * V_15 ,
struct V_5 * V_5 ,
struct V_90 * V_91 )
{
struct V_72 * V_72 ;
struct V_63 * V_92 ;
V_72 = F_37 ( sizeof( * V_72 ) , V_86 ) ;
if ( ! V_72 )
return - V_48 ;
V_92 = & V_72 -> V_87 ;
V_72 -> V_5 = V_5 ;
F_75 ( V_15 , V_92 , & V_121 ,
V_122 ) ;
F_76 ( V_92 , & V_123 ) ;
V_92 -> V_124 = 0 ;
V_92 -> V_125 = 0 ;
F_77 ( V_15 ) ;
F_78 ( & V_92 -> V_87 ,
V_15 -> V_109 . V_110 , - 1 ) ;
F_78 ( & V_92 -> V_87 ,
V_15 -> V_109 . V_111 , - 1 ) ;
F_79 ( V_92 ) ;
F_80 ( V_92 , V_91 ) ;
return 0 ;
}
int F_81 ( struct V_84 * V_15 )
{
struct V_6 * V_7 = V_15 -> V_16 ;
struct V_90 * V_91 ;
struct V_5 * V_5 ;
unsigned int V_85 ;
int V_81 ;
for ( V_85 = 0 ; V_85 < V_7 -> V_126 ; ++ V_85 ) {
V_5 = F_36 ( V_15 , V_85 ) ;
if ( ! V_5 )
return - V_48 ;
V_91 = F_50 ( V_15 , V_85 ) ;
if ( ! V_91 )
return - V_48 ;
V_81 = F_74 ( V_15 , V_5 , V_91 ) ;
if ( V_81 )
return V_81 ;
}
return 0 ;
}
void F_82 ( struct V_84 * V_15 )
{
}
static void F_83 ( T_5 * V_127 , T_5 * V_128 , T_4 V_8 , T_4 V_9 ,
T_6 V_129 )
{
T_6 V_130 = ( V_8 + 7 ) / 8 ;
T_4 V_85 , V_131 ;
memcpy ( V_128 + V_129 , V_127 , V_8 * V_9 * 4 ) ;
for ( V_85 = 0 ; V_85 < V_9 ; ++ V_85 )
for ( V_131 = 0 ; V_131 < V_8 ; ++ V_131 )
if ( ( ( T_4 * ) V_127 ) [ V_85 * V_8 + V_131 ] > 0xf0000000 )
V_128 [ V_85 * V_130 + V_131 / 8 ] |= ( 0x80 >> ( V_131 % 8 ) ) ;
}
static int F_84 ( struct V_1 * V_2 , struct V_132 * V_133 ,
T_4 V_134 , T_4 V_8 , T_4 V_9 ,
T_2 V_135 , T_2 V_136 )
{
struct V_6 * V_7 = V_2 -> V_15 -> V_16 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_137 V_138 ;
T_6 V_139 , V_129 ;
struct V_75 * V_76 ;
T_4 V_12 , V_140 = 0 ;
struct V_79 * V_80 ;
bool V_141 ;
T_5 * V_128 = NULL ;
T_5 * V_127 ;
int V_81 ;
F_28 ( V_7 -> V_43 , 0 , 0 ,
V_7 -> V_70 ,
V_7 -> V_71 ) ;
if ( ! V_134 ) {
bool V_142 = false ;
struct V_1 * V_62 ;
V_5 -> V_142 = false ;
F_15 (crtci, &vbox->dev->mode_config.crtc_list,
head) {
if ( F_2 ( V_62 ) -> V_142 )
V_142 = true ;
}
if ( ! V_142 )
F_85 ( V_7 -> V_43 , 0 , 0 , 0 ,
0 , 0 , NULL , 0 ) ;
return 0 ;
}
V_5 -> V_142 = true ;
if ( V_8 > V_143 || V_9 > V_144 ||
V_8 == 0 || V_9 == 0 )
return - V_145 ;
V_81 = F_86 ( V_7 -> V_43 ,
V_146 , & V_140 ) ;
if ( V_81 )
return V_81 ;
if ( ! ( V_140 & V_147 ) ) {
return - V_148 ;
}
V_76 = F_87 ( V_133 , V_134 ) ;
if ( ! V_76 ) {
F_88 ( L_1 , V_134 ) ;
return - V_149 ;
}
V_80 = F_20 ( V_76 ) ;
V_81 = F_21 ( V_80 , false ) ;
if ( V_81 )
goto V_150;
V_129 = ( ( V_8 + 7 ) / 8 * V_9 + 3 ) & ~ 3 ;
V_139 = V_8 * V_9 * 4 + V_129 ;
V_7 -> V_151 = F_89 ( T_4 , F_90 ( V_135 , 0 ) , V_8 ) ;
V_7 -> V_152 = F_89 ( T_4 , F_90 ( V_136 , 0 ) , V_9 ) ;
V_7 -> V_153 = V_8 ;
V_7 -> V_154 = V_9 ;
V_7 -> V_155 = V_139 ;
V_128 = V_7 -> V_156 ;
V_81 = F_91 ( & V_80 -> V_80 , 0 , V_80 -> V_80 . V_157 , & V_138 ) ;
if ( V_81 ) {
V_7 -> V_155 = 0 ;
goto V_158;
}
V_127 = F_92 ( & V_138 , & V_141 ) ;
if ( V_141 ) {
F_88 ( L_2 ) ;
V_81 = - V_159 ;
goto V_160;
}
F_83 ( V_127 , V_128 , V_8 , V_9 , V_129 ) ;
V_12 = V_161 | V_162 |
V_163 ;
V_81 = F_85 ( V_7 -> V_43 , V_12 ,
V_7 -> V_151 , V_7 -> V_152 ,
V_8 , V_9 , V_128 , V_139 ) ;
V_160:
F_93 ( & V_138 ) ;
V_158:
F_23 ( V_80 ) ;
V_150:
F_94 ( V_76 ) ;
return V_81 ;
}
static int F_95 ( struct V_1 * V_2 , int V_24 , int V_26 )
{
struct V_6 * V_7 = V_2 -> V_15 -> V_16 ;
T_4 V_12 = V_161 |
V_162 | V_163 ;
T_2 V_164 =
V_7 -> V_23 ? V_2 -> V_24 : F_2 ( V_2 ) -> V_25 ;
T_2 V_165 =
V_7 -> V_23 ? V_2 -> V_26 : F_2 ( V_2 ) -> V_27 ;
T_4 V_166 , V_167 ;
T_4 V_135 = 0 ;
T_4 V_136 = 0 ;
int V_81 ;
if ( V_24 + V_164 < 0 || V_26 + V_165 < 0 || V_7 -> V_155 == 0 )
return 0 ;
V_81 = F_96 ( V_7 -> V_43 , true , V_24 + V_164 ,
V_26 + V_165 , & V_166 , & V_167 ) ;
if ( V_81 || ( V_166 == 0 && V_167 == 0 ) )
return V_81 ;
if ( V_24 + V_164 < V_166 )
V_135 = F_97 ( V_166 - V_24 - V_164 , V_7 -> V_153 ) ;
if ( V_26 + V_165 < V_167 )
V_136 = F_97 ( V_167 - V_26 - V_165 , V_7 -> V_154 ) ;
if ( V_135 == V_7 -> V_151 && V_136 == V_7 -> V_152 )
return 0 ;
V_7 -> V_151 = V_135 ;
V_7 -> V_152 = V_136 ;
return F_85 ( V_7 -> V_43 , V_12 ,
V_135 , V_136 , V_7 -> V_153 , V_7 -> V_154 ,
V_7 -> V_156 , V_7 -> V_155 ) ;
}
