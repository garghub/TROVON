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
return V_4 ;
}
static enum V_18 F_4 ( struct V_2 * V_3 )
{
T_1 V_19 = V_3 -> V_20 . V_19 ;
T_2 V_21 = V_19 >> 16 ;
T_2 V_22 = V_19 & 0xffff ;
enum V_18 V_7 ;
if ( V_21 != 0x1106 )
V_7 = V_23 ;
else if ( V_22 >= 0x1708 && V_22 <= 0x170b )
V_7 = V_24 ;
else if ( V_22 >= 0xe710 && V_22 <= 0xe713 )
V_7 = V_25 ;
else if ( V_22 >= 0xe714 && V_22 <= 0xe717 )
V_7 = V_26 ;
else if ( V_22 >= 0xe720 && V_22 <= 0xe723 ) {
V_7 = V_27 ;
if ( F_5 ( V_3 , 0x16 , V_28 ) == 0x7 )
V_7 = V_8 ;
} else if ( V_22 >= 0xe724 && V_22 <= 0xe727 )
V_7 = V_29 ;
else if ( ( V_22 & 0xfff ) == 0x397
&& ( V_22 >> 12 ) < 8 )
V_7 = V_9 ;
else if ( ( V_22 & 0xfff ) == 0x398
&& ( V_22 >> 12 ) < 8 )
V_7 = V_30 ;
else if ( ( V_22 & 0xfff ) == 0x428
&& ( V_22 >> 12 ) < 8 )
V_7 = V_31 ;
else if ( V_22 == 0x0433 || V_22 == 0xa721 )
V_7 = V_32 ;
else if ( V_22 == 0x0441 || V_22 == 0x4441 )
V_7 = V_31 ;
else if ( V_22 == 0x0438 || V_22 == 0x4438 )
V_7 = V_33 ;
else if ( V_22 == 0x0448 )
V_7 = V_34 ;
else if ( V_22 == 0x0440 )
V_7 = V_9 ;
else if ( ( V_22 & 0xfff ) == 0x446 )
V_7 = V_35 ;
else if ( V_22 == 0x4760 )
V_7 = V_36 ;
else if ( V_22 == 0x4761 || V_22 == 0x4762 )
V_7 = V_37 ;
else
V_7 = V_23 ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_24 || ! V_4 -> V_6 . V_38 . V_39 )
return;
if ( V_4 -> V_40 ) {
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 1 ) ;
V_3 -> V_41 = 0 ;
F_8 ( & V_3 -> V_42 ) ;
V_4 -> V_40 = false ;
}
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_24 || ! V_4 -> V_6 . V_38 . V_39 )
return;
if ( V_4 -> V_43 ) {
if ( ! V_4 -> V_40 ) {
V_3 -> V_41 = F_10 ( 100 ) ;
F_7 ( V_3 , 0x1 , 0 , 0xf81 , 0 ) ;
F_11 ( & V_3 -> V_42 , 0 ) ;
V_4 -> V_40 = true ;
}
} else if ( ! F_12 ( V_3 ) )
F_6 ( V_3 ) ;
}
static int F_13 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
return F_14 ( V_45 , V_47 ) ;
}
static int F_15 ( struct V_44 * V_45 ,
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_45 ) ;
V_49 -> V_50 . V_51 . V_52 [ 0 ] = V_3 -> V_16 ;
return 0 ;
}
static int F_17 ( struct V_44 * V_45 ,
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_45 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_53 = ! ! V_49 -> V_50 . V_51 . V_52 [ 0 ] ;
if ( V_53 == V_3 -> V_16 )
return 0 ;
V_3 -> V_16 = V_53 ;
V_4 -> V_6 . V_17 = V_53 ;
F_18 ( V_3 ) ;
return 1 ;
}
static inline void F_19 ( struct V_1 * V_4 , T_3 V_54 ,
int V_55 , int V_56 )
{
V_4 -> V_6 . V_57 = V_54 ;
V_4 -> V_58 = F_20 ( V_54 , 1 , V_55 , V_56 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_59 ;
if ( V_4 -> V_58 ) {
const struct V_60 * V_61 ;
for ( V_61 = V_62 ; V_61 -> V_63 ; V_61 ++ ) {
struct V_44 * V_64 ;
V_64 = F_22 ( V_61 , V_3 ) ;
if ( ! V_64 )
return - V_65 ;
V_64 -> V_66 = V_4 -> V_58 ;
V_59 = F_23 ( V_3 , 0 , V_64 ) ;
if ( V_59 < 0 )
return V_59 ;
}
}
return 0 ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_54 ;
F_25 (nid, codec)
if ( F_26 ( F_27 ( V_3 , V_54 ) ) == V_67 ) {
F_19 ( V_4 , V_54 , 0 , V_68 ) ;
break;
}
}
static bool F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_69 * V_70 ;
int V_71 , V_72 ;
V_70 = V_4 -> V_6 . V_73 . V_74 ;
if ( ! V_70 )
return true ;
for (; V_70 -> V_54 ; V_70 ++ ) {
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_72 = F_29 ( V_3 , V_70 -> V_54 , V_71 , V_70 -> V_56 ,
V_70 -> V_55 ) ;
if ( ! ( V_72 & V_75 ) && V_72 > 0 )
return false ;
}
}
return true ;
}
static void F_30 ( struct V_2 * V_3 , bool V_76 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
bool V_77 ;
unsigned int V_78 , V_79 ;
if ( ! V_3 -> V_16 )
V_77 = false ;
else
V_77 = F_28 ( V_3 ) && ! V_4 -> V_6 . V_80 ;
if ( V_77 == V_4 -> V_81 && ! V_76 )
return;
V_4 -> V_81 = V_77 ;
switch ( V_4 -> V_7 ) {
case V_27 :
case V_29 :
V_78 = 0xf70 ;
V_79 = V_77 ? 0x02 : 0x00 ;
break;
case V_9 :
case V_31 :
case V_32 :
V_78 = 0xf73 ;
V_79 = V_77 ? 0x51 : 0xe1 ;
break;
case V_30 :
V_78 = 0xf73 ;
V_79 = V_77 ? 0x01 : 0x1d ;
break;
case V_33 :
case V_34 :
case V_35 :
V_78 = 0xf93 ;
V_79 = V_77 ? 0x00 : 0xe0 ;
break;
case V_36 :
case V_37 :
V_78 = 0xf82 ;
V_79 = V_77 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_7 ( V_3 , V_3 -> V_20 . V_82 , 0 , V_78 , V_79 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
return F_30 ( V_3 , false ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_59 , V_83 ;
V_59 = F_32 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_21 ( V_3 ) ;
if ( V_59 < 0 )
return V_59 ;
V_4 -> V_84 [ V_4 -> V_85 ++ ] = V_86 ;
for ( V_83 = 0 ; V_83 < V_4 -> V_85 ; V_83 ++ ) {
V_59 = F_33 ( V_3 , V_4 -> V_84 [ V_83 ] ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
static void V_13 ( struct V_87 * V_88 ,
struct V_2 * V_3 ,
struct V_89 * V_90 ,
int V_91 )
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
if ( V_4 -> V_7 == V_35 )
F_37 ( V_3 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
F_39 ( 10 ) ;
V_3 -> V_92 . V_93 ( V_3 ) ;
F_40 ( V_3 -> V_20 . V_94 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , T_3 V_54 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_18 ( V_3 ) ;
F_9 ( V_3 ) ;
return F_42 ( V_3 , & V_4 -> V_6 . V_73 , V_54 ) ;
}
static void F_43 ( struct V_2 * V_3 , T_3 V_54 )
{
unsigned int V_95 ;
unsigned char V_96 ;
V_95 = F_44 ( V_3 , V_54 ) ;
V_96 = ( unsigned char ) F_45 ( V_95 ) ;
V_96 = ( V_96 << 4 ) | F_46 ( V_95 ) ;
if ( F_47 ( V_95 ) == V_97
&& ( V_96 == 0xf0 || V_96 == 0xff ) ) {
V_95 = V_95 & ( ~ ( V_98 << 30 ) ) ;
F_48 ( V_3 , V_54 , V_95 ) ;
}
return;
}
static int F_49 ( struct V_44 * V_45 ,
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_45 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_7 != V_24 )
return 0 ;
V_49 -> V_50 . integer . V_50 [ 0 ] = V_4 -> V_43 ;
return 0 ;
}
static int F_50 ( struct V_44 * V_45 ,
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_45 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_53 ;
if ( V_4 -> V_7 != V_24 )
return 0 ;
V_53 = ! ! V_49 -> V_50 . integer . V_50 [ 0 ] ;
if ( V_4 -> V_43 == V_53 )
return 0 ;
V_4 -> V_43 = V_53 ;
F_9 ( V_3 ) ;
return 1 ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_59 ;
V_4 -> V_6 . V_99 = & V_100 ;
V_4 -> V_6 . V_101 = & V_102 ;
V_59 = F_52 ( V_3 , & V_4 -> V_6 . V_38 , NULL , 0 ) ;
if ( V_59 < 0 )
return V_59 ;
F_24 ( V_3 ) ;
V_59 = F_53 ( V_3 , & V_4 -> V_6 . V_38 ) ;
if ( V_59 < 0 )
return V_59 ;
V_3 -> V_16 = 0 ;
V_4 -> V_6 . V_17 = 0 ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_4 -> V_103 ; V_83 ++ )
F_55 ( V_3 , V_4 -> V_104 [ V_83 ] ) ;
F_30 ( V_3 , true ) ;
F_56 ( V_3 ) ;
F_9 ( V_3 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
int V_59 ;
int V_105 = V_3 -> V_41 ;
V_3 -> V_41 = F_10 ( 100 ) ;
V_59 = F_31 ( V_3 ) ;
V_3 -> V_41 = V_105 ;
return V_59 ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_83 , V_59 ;
V_59 = F_59 ( V_3 ) ;
if ( V_59 < 0 || V_3 -> V_20 . V_19 != 0x11061708 )
return V_59 ;
for ( V_83 = 0 ; V_83 < F_60 ( V_4 -> V_6 . V_106 ) ; V_83 ++ ) {
struct V_107 * V_108 = V_4 -> V_6 . V_106 [ V_83 ] ;
if ( ! V_108 )
continue;
if ( ! V_108 -> V_109 [ V_110 ] . V_111 ||
V_108 -> V_112 != V_113 )
continue;
V_108 -> V_109 [ V_110 ] . V_114 =
V_115 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x17 ;
V_3 -> V_41 = F_10 ( 100 ) ;
V_4 -> V_43 = 1 ;
V_4 -> V_6 . V_117 = 1 ;
V_4 -> V_6 . V_118 = 1 ;
F_43 ( V_3 , V_119 ) ;
F_43 ( V_3 , V_120 ) ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_84 [ V_4 -> V_85 ++ ] = V_121 ;
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_122 ;
V_3 -> V_92 = V_123 ;
V_3 -> V_92 . V_124 = F_57 ;
V_3 -> V_92 . V_125 = F_58 ;
V_3 -> V_41 = 0 ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x18 ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_3 -> V_92 = V_123 ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
if ( F_4 ( V_3 ) == V_8 )
return F_64 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x16 ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_3 -> V_92 = V_123 ;
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
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x16 ;
F_65 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
if ( F_4 ( V_3 ) == V_8 ) {
F_68 ( V_3 -> V_20 . V_136 ) ;
V_3 -> V_20 . V_136 = F_69 ( L_1 , V_5 ) ;
snprintf ( V_3 -> V_137 -> V_138 ,
sizeof( V_3 -> V_137 -> V_138 ) ,
L_2 , V_3 -> V_20 . V_139 , V_3 -> V_20 . V_136 ) ;
}
if ( V_3 -> V_20 . V_19 == 0x11064397 ) {
F_68 ( V_3 -> V_20 . V_136 ) ;
V_3 -> V_20 . V_136 = F_69 ( L_3 , V_5 ) ;
snprintf ( V_3 -> V_137 -> V_138 ,
sizeof( V_3 -> V_137 -> V_138 ) ,
L_2 , V_3 -> V_20 . V_139 , V_3 -> V_20 . V_136 ) ;
}
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_140 ;
V_3 -> V_92 = V_123 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x1a ;
F_67 ( V_3 , 0x1A , V_131 ,
( 0x17 << V_132 ) |
( 0x17 << V_133 ) |
( 0x5 << V_134 ) |
( 1 << V_135 ) ) ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_141 ;
V_3 -> V_92 = V_123 ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_83 , V_142 ;
T_3 V_143 [ 8 ] ;
T_3 V_54 ;
if ( ! V_4 -> V_6 . V_116 )
return 0 ;
V_142 = F_72 ( V_3 , V_4 -> V_6 . V_116 , V_143 ,
F_60 ( V_143 ) - 1 ) ;
for ( V_83 = 0 ; V_83 < V_142 ; V_83 ++ ) {
if ( F_26 ( F_27 ( V_3 , V_143 [ V_83 ] ) ) == V_144 )
return 0 ;
}
F_25 (nid, codec) {
unsigned int V_145 = F_27 ( V_3 , V_54 ) ;
if ( F_26 ( V_145 ) == V_144 &&
! ( V_145 & V_146 ) ) {
V_143 [ V_142 ++ ] = V_54 ;
return F_73 ( V_3 ,
V_4 -> V_6 . V_116 ,
V_142 , V_143 ) ;
}
}
return 0 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x21 ;
F_65 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_71 ( V_3 ) ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_147 ;
V_3 -> V_92 = V_123 ;
return 0 ;
}
static int F_75 ( struct V_44 * V_45 ,
struct V_46 * V_47 )
{
V_47 -> type = V_148 ;
V_47 -> V_149 = 1 ;
V_47 -> V_50 . integer . V_150 = 0 ;
V_47 -> V_50 . integer . V_151 = 1 ;
return 0 ;
}
static int F_76 ( struct V_44 * V_45 ,
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_45 ) ;
int V_152 = 0 ;
V_152 = F_77 ( V_3 , 0x26 , 0 ,
V_153 , 0 ) ;
if ( V_152 != - 1 )
* V_49 -> V_50 . integer . V_50 = V_152 ;
return 0 ;
}
static int F_78 ( struct V_44 * V_45 ,
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_16 ( V_45 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_152 = * V_49 -> V_50 . integer . V_50 ;
F_7 ( V_3 , 0x26 , 0 ,
V_154 , V_152 ) ;
V_4 -> V_155 = V_152 ;
return 1 ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x16 ;
F_65 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_156 ;
V_4 -> V_84 [ V_4 -> V_85 ++ ] = V_157 ;
V_4 -> V_84 [ V_4 -> V_85 ++ ] = V_158 ;
V_3 -> V_92 = V_123 ;
return 0 ;
}
static void F_80 ( struct V_2 * V_3 ,
const struct V_159 * V_160 , int V_91 )
{
if ( V_91 == V_161 )
F_65 ( V_3 , 0x30 , 0 , 2 , 40 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
static T_3 V_162 [] = { 0x14 , 0x1c } ;
static T_3 V_163 [] = { 0x1c } ;
F_73 ( V_3 , 0x24 , F_60 ( V_162 ) , V_162 ) ;
F_73 ( V_3 , 0x33 , F_60 ( V_163 ) , V_163 ) ;
}
static int F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x21 ;
F_65 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
if ( V_4 -> V_7 == V_35 )
F_81 ( V_3 ) ;
F_71 ( V_3 ) ;
F_83 ( V_3 , NULL , V_164 , V_165 ) ;
F_84 ( V_3 , V_161 ) ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
if ( V_4 -> V_7 == V_35 )
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_166 ;
else
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_167 ;
V_3 -> V_92 = V_123 ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x21 ;
F_65 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_65 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
F_71 ( V_3 ) ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_168 ;
V_3 -> V_92 = V_123 ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_59 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_65 ;
V_4 -> V_6 . V_116 = 0x3f ;
F_71 ( V_3 ) ;
V_59 = F_51 ( V_3 ) ;
if ( V_59 < 0 ) {
F_34 ( V_3 ) ;
return V_59 ;
}
V_4 -> V_104 [ V_4 -> V_103 ++ ] = V_169 ;
V_3 -> V_92 = V_123 ;
return 0 ;
}
