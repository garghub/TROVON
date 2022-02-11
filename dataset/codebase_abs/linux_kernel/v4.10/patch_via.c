static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 == NULL )
return NULL ;
V_3 -> V_4 = V_4 ;
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = F_4 ( V_3 ) ;
if ( V_4 -> V_7 == V_8 )
V_4 -> V_7 = V_9 ;
V_4 -> V_6 . V_10 = 1 ;
V_4 -> V_6 . V_11 = 1 ;
V_4 -> V_6 . V_12 = V_13 ;
V_4 -> V_6 . V_14 = V_15 ;
V_3 -> V_16 = 1 ;
V_4 -> V_6 . V_17 = 1 ;
V_3 -> V_18 = V_19 ;
return V_4 ;
}
static enum V_20 F_4 ( struct V_2 * V_3 )
{
T_1 V_21 = V_3 -> V_22 . V_21 ;
T_2 V_23 = V_21 >> 16 ;
T_2 V_24 = V_21 & 0xffff ;
enum V_20 V_7 ;
if ( V_23 != 0x1106 )
V_7 = V_25 ;
else if ( V_24 >= 0x1708 && V_24 <= 0x170b )
V_7 = V_26 ;
else if ( V_24 >= 0xe710 && V_24 <= 0xe713 )
V_7 = V_27 ;
else if ( V_24 >= 0xe714 && V_24 <= 0xe717 )
V_7 = V_28 ;
else if ( V_24 >= 0xe720 && V_24 <= 0xe723 ) {
V_7 = V_29 ;
if ( F_5 ( V_3 , 0x16 , V_30 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_24 >= 0xe724 && V_24 <= 0xe727 )
V_7 = V_31 ;
else if ( ( V_24 & 0xfff ) == 0x397
&& ( V_24 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_24 & 0xfff ) == 0x398
&& ( V_24 >> 12 ) < 8 )
V_7 = V_32 ;
else if ( ( V_24 & 0xfff ) == 0x428
&& ( V_24 >> 12 ) < 8 )
V_7 = V_33 ;
else if ( V_24 == 0x0433 || V_24 == 0xa721 )
V_7 = V_34 ;
else if ( V_24 == 0x0441 || V_24 == 0x4441 )
V_7 = V_33 ;
else if ( V_24 == 0x0438 || V_24 == 0x4438 )
V_7 = V_35 ;
else if ( V_24 == 0x0448 )
V_7 = V_36 ;
else if ( V_24 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_24 & 0xfff ) == 0x446 )
V_7 = V_37 ;
else if ( V_24 == 0x4760 )
V_7 = V_38 ;
else if ( V_24 == 0x4761 || V_24 == 0x4762 )
V_7 = V_39 ;
else
V_7 = V_25 ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_26 || ! V_4 -> V_6 . V_40 . V_41 )
return;
if ( V_4 -> V_42 ) {
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
V_3 -> V_43 = 0 ;
F_8 ( & V_3 -> V_44 ) ;
V_4 -> V_42 = false ;
}
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_26 || ! V_4 -> V_6 . V_40 . V_41 )
return;
if ( V_4 -> V_45 ) {
if ( ! V_4 -> V_42 ) {
V_3 -> V_43 = F_10 ( 100 ) ;
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_11 ( & V_3 -> V_44 , 0 ) ;
V_4 -> V_42 = true ;
}
} else if ( ! F_12 ( V_3 ) )
F_6 ( V_3 ) ;
}
static int F_13 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
return F_14 ( V_47 , V_49 ) ;
}
static int F_15 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_16 ( V_47 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_51 -> V_52 . V_53 . V_54 [ 0 ] = V_4 -> V_6 . V_17 ;
return 0 ;
}
static int F_17 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_16 ( V_47 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_55 = ! ! V_51 -> V_52 . V_53 . V_54 [ 0 ] ;
if ( V_55 == V_4 -> V_6 . V_17 )
return 0 ;
V_4 -> V_6 . V_17 = V_55 ;
F_18 ( V_3 ) ;
return 1 ;
}
static inline void F_19 ( struct V_1 * V_4 , T_3 V_56 ,
int V_57 , int V_58 )
{
V_4 -> V_6 . V_59 = V_56 ;
V_4 -> V_60 = F_20 ( V_56 , 1 , V_57 , V_58 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_61 ;
if ( V_4 -> V_60 ) {
const struct V_62 * V_63 ;
for ( V_63 = V_64 ; V_63 -> V_65 ; V_63 ++ ) {
struct V_46 * V_66 ;
V_66 = F_22 ( V_63 , V_3 ) ;
if ( ! V_66 )
return - V_67 ;
V_66 -> V_68 = V_4 -> V_60 ;
V_61 = F_23 ( V_3 , 0 , V_66 ) ;
if ( V_61 < 0 )
return V_61 ;
}
}
return 0 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_56 ;
F_25 (nid, codec)
if ( F_26 ( F_27 ( V_3 , V_56 ) ) == V_69 ) {
F_19 ( V_4 , V_56 , 0 , V_70 ) ;
break;
}
}
static bool F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_71 * V_72 ;
int V_73 , V_74 ;
V_72 = V_4 -> V_6 . V_75 . V_76 ;
if ( ! V_72 )
return true ;
for (; V_72 -> V_56 ; V_72 ++ ) {
for ( V_73 = 0 ; V_73 < 2 ; V_73 ++ ) {
V_74 = F_29 ( V_3 , V_72 -> V_56 , V_73 , V_72 -> V_58 ,
V_72 -> V_57 ) ;
if ( ! ( V_74 & V_77 ) && V_74 > 0 )
return false ;
}
}
return true ;
}
static void F_30 ( struct V_2 * V_3 , bool V_78 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_79 ;
unsigned int V_80 , V_81 ;
if ( ! V_3 -> V_16 )
V_79 = false ;
else
V_79 = F_28 ( V_3 ) && ! V_4 -> V_6 . V_82 ;
if ( V_79 == V_4 -> V_83 && ! V_78 )
return;
V_4 -> V_83 = V_79 ;
switch ( V_4 -> V_7 ) {
case V_29 :
case V_31 :
V_80 = 0xf70 ;
V_81 = V_79 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_33 :
case V_34 :
V_80 = 0xf73 ;
V_81 = V_79 ? 0x51 : 0xe1 ;
break;
case V_32 :
V_80 = 0xf73 ;
V_81 = V_79 ? 0x01 : 0x1d ;
break;
case V_35 :
case V_36 :
case V_37 :
V_80 = 0xf93 ;
V_81 = V_79 ? 0x00 : 0xe0 ;
break;
case V_38 :
case V_39 :
V_80 = 0xf82 ;
V_81 = V_79 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_22 . V_84 , 0 , V_80 , V_81 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
return F_30 ( V_3 , false ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_61 , V_85 ;
V_61 = F_32 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_21 ( V_3 ) ;
if ( V_61 < 0 )
return V_61 ;
V_4 -> V_86 [ V_4 -> V_87 ++ ] = V_88 ;
for ( V_85 = 0 ; V_85 < V_4 -> V_87 ; V_85 ++ ) {
V_61 = F_33 ( V_3 , V_4 -> V_86 [ V_85 ] ) ;
if ( V_61 < 0 )
return V_61 ;
}
return 0 ;
}
static void V_13 ( struct V_89 * V_90 ,
struct V_2 * V_3 ,
struct V_91 * V_92 ,
int V_93 )
{
F_18 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
F_6 ( V_3 ) ;
F_35 ( V_3 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_6 ( V_3 ) ;
if ( V_4 -> V_7 == V_37 )
F_37 ( V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
F_39 ( 10 ) ;
V_3 -> V_18 . V_94 ( V_3 ) ;
F_40 ( V_3 -> V_22 . V_95 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , T_3 V_56 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_18 ( V_3 ) ;
F_9 ( V_3 ) ;
return F_42 ( V_3 , & V_4 -> V_6 . V_75 , V_56 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_3 V_56 )
{
unsigned int V_96 ;
unsigned char V_97 ;
V_96 = F_44 ( V_3 , V_56 ) ;
V_97 = ( unsigned char ) F_45 ( V_96 ) ;
V_97 = ( V_97 << 4 ) | F_46 ( V_96 ) ;
if ( F_47 ( V_96 ) == V_98
&& ( V_97 == 0xf0 || V_97 == 0xff ) ) {
V_96 = V_96 & ( ~ ( V_99 << 30 ) ) ;
F_48 ( V_3 , V_56 , V_96 ) ;
}
return;
}
static int F_49 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_16 ( V_47 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_26 )
return 0 ;
V_51 -> V_52 . integer . V_52 [ 0 ] = V_4 -> V_45 ;
return 0 ;
}
static int F_50 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_16 ( V_47 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_55 ;
if ( V_4 -> V_7 != V_26 )
return 0 ;
V_55 = ! ! V_51 -> V_52 . integer . V_52 [ 0 ] ;
if ( V_4 -> V_45 == V_55 )
return 0 ;
V_4 -> V_45 = V_55 ;
F_9 ( V_3 ) ;
return 1 ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_61 ;
V_4 -> V_6 . V_100 = & V_101 ;
V_4 -> V_6 . V_102 = & V_103 ;
V_61 = F_52 ( V_3 , & V_4 -> V_6 . V_40 , NULL , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
F_24 ( V_3 ) ;
V_61 = F_53 ( V_3 , & V_4 -> V_6 . V_40 ) ;
if ( V_61 < 0 )
return V_61 ;
V_3 -> V_16 = 0 ;
V_4 -> V_6 . V_17 = 0 ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_4 -> V_104 ; V_85 ++ )
F_55 ( V_3 , V_4 -> V_105 [ V_85 ] ) ;
F_30 ( V_3 , true ) ;
F_56 ( V_3 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
int V_61 ;
int V_106 = V_3 -> V_43 ;
V_3 -> V_43 = F_10 ( 100 ) ;
V_61 = F_31 ( V_3 ) ;
V_3 -> V_43 = V_106 ;
return V_61 ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_85 , V_61 ;
V_61 = F_59 ( V_3 ) ;
if ( V_61 < 0 || V_3 -> V_22 . V_21 != 0x11061708 )
return V_61 ;
for ( V_85 = 0 ; V_85 < F_60 ( V_4 -> V_6 . V_107 ) ; V_85 ++ ) {
struct V_108 * V_109 = V_4 -> V_6 . V_107 [ V_85 ] ;
if ( ! V_109 )
continue;
if ( ! V_109 -> V_110 [ V_111 ] . V_112 ||
V_109 -> V_113 != V_114 )
continue;
V_109 -> V_110 [ V_111 ] . V_115 =
V_116 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_3 -> V_18 . V_117 = F_57 ;
V_3 -> V_18 . V_118 = F_58 ;
V_4 -> V_6 . V_119 = 0x17 ;
V_3 -> V_43 = F_10 ( 100 ) ;
V_4 -> V_45 = 1 ;
V_4 -> V_6 . V_120 = 1 ;
V_4 -> V_6 . V_121 = 1 ;
F_43 ( V_3 , V_122 ) ;
F_43 ( V_3 , V_123 ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_86 [ V_4 -> V_87 ++ ] = V_124 ;
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_125 ;
V_3 -> V_43 = 0 ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x18 ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
return 0 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
if ( F_4 ( V_3 ) == V_8 )
return F_64 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x16 ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
return 0 ;
}
static void F_65 ( struct V_2 * V_3 , T_3 V_126 ,
int V_127 , int V_128 , int V_129 )
{
F_66 ( V_3 , V_126 ,
F_27 ( V_3 , V_126 ) | V_130 ) ;
F_67 ( V_3 , V_126 , V_131 ,
( V_127 << V_132 ) |
( V_128 << V_133 ) |
( V_129 << V_134 ) |
( 0 << V_135 ) ) ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x16 ;
F_65 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
if ( F_4 ( V_3 ) == V_8 )
F_68 ( V_3 , L_1 ) ;
if ( V_3 -> V_22 . V_21 == 0x11064397 )
F_68 ( V_3 , L_2 ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_136 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x1a ;
F_67 ( V_3 , 0x1A , V_131 ,
( 0x17 << V_132 ) |
( 0x17 << V_133 ) |
( 0x5 << V_134 ) |
( 1 << V_135 ) ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_137 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_85 , V_138 ;
T_3 V_139 [ 8 ] ;
T_3 V_56 ;
if ( ! V_4 -> V_6 . V_119 )
return 0 ;
V_138 = F_71 ( V_3 , V_4 -> V_6 . V_119 , V_139 ,
F_60 ( V_139 ) - 1 ) ;
for ( V_85 = 0 ; V_85 < V_138 ; V_85 ++ ) {
if ( F_26 ( F_27 ( V_3 , V_139 [ V_85 ] ) ) == V_140 )
return 0 ;
}
F_25 (nid, codec) {
unsigned int V_141 = F_27 ( V_3 , V_56 ) ;
if ( F_26 ( V_141 ) == V_140 &&
! ( V_141 & V_142 ) ) {
V_139 [ V_138 ++ ] = V_56 ;
return F_72 ( V_3 ,
V_4 -> V_6 . V_119 ,
V_138 , V_139 ) ;
}
}
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x21 ;
F_65 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_70 ( V_3 ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_143 ;
return 0 ;
}
static int F_74 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
V_49 -> type = V_144 ;
V_49 -> V_145 = 1 ;
V_49 -> V_52 . integer . V_146 = 0 ;
V_49 -> V_52 . integer . V_147 = 1 ;
return 0 ;
}
static int F_75 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_16 ( V_47 ) ;
int V_148 = 0 ;
V_148 = F_76 ( V_3 , 0x26 , 0 ,
V_149 , 0 ) ;
if ( V_148 != - 1 )
* V_51 -> V_52 . integer . V_52 = V_148 ;
return 0 ;
}
static int F_77 ( struct V_46 * V_47 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_16 ( V_47 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_148 = * V_51 -> V_52 . integer . V_52 ;
F_7 ( V_3 , 0x26 , 0 ,
V_150 , V_148 ) ;
V_4 -> V_151 = V_148 ;
return 1 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x16 ;
F_65 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_152 ;
V_4 -> V_86 [ V_4 -> V_87 ++ ] = V_153 ;
V_4 -> V_86 [ V_4 -> V_87 ++ ] = V_154 ;
return 0 ;
}
static void F_79 ( struct V_2 * V_3 ,
const struct V_155 * V_156 , int V_93 )
{
if ( V_93 == V_157 )
F_65 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
static T_3 V_158 [] = { 0x14 , 0x1c } ;
static T_3 V_159 [] = { 0x1c } ;
F_72 ( V_3 , 0x24 , F_60 ( V_158 ) , V_158 ) ;
F_72 ( V_3 , 0x33 , F_60 ( V_159 ) , V_159 ) ;
}
static int F_81 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x21 ;
F_65 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_7 == V_37 )
F_80 ( V_3 ) ;
F_70 ( V_3 ) ;
F_82 ( V_3 , NULL , V_160 , V_161 ) ;
F_83 ( V_3 , V_157 ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
if ( V_4 -> V_7 == V_37 )
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_162 ;
else
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_163 ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x21 ;
F_65 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_70 ( V_3 ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_164 ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_61 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_67 ;
V_4 -> V_6 . V_119 = 0x3f ;
F_70 ( V_3 ) ;
V_61 = F_51 ( V_3 ) ;
if ( V_61 < 0 ) {
F_34 ( V_3 ) ;
return V_61 ;
}
V_4 -> V_105 [ V_4 -> V_104 ++ ] = V_165 ;
return 0 ;
}
