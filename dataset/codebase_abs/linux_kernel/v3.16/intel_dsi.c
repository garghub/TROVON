static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 , 0x08 , 0x0001 ) ;
F_3 ( V_2 , 0x0F , 0x0005 ) ;
F_3 ( V_2 , 0x0F , 0x0025 ) ;
F_4 ( 150 ) ;
F_3 ( V_2 , 0x0F , 0x0000 ) ;
F_3 ( V_2 , 0x08 , 0x0000 ) ;
F_5 ( & V_2 -> V_3 ) ;
}
static struct V_4 * F_6 ( struct V_5 * V_6 )
{
return F_7 ( F_8 ( V_6 ) ,
struct V_4 , V_7 ) ;
}
static inline bool F_9 ( struct V_4 * V_4 )
{
return V_4 -> V_8 == V_9 ;
}
static inline bool F_10 ( struct V_4 * V_4 )
{
return V_4 -> V_8 == V_10 ;
}
static void F_11 ( struct V_11 * V_12 )
{
F_12 ( L_1 ) ;
}
static bool F_13 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_4 * V_4 = F_7 ( V_12 , struct V_4 ,
V_7 ) ;
struct V_15 * V_15 = V_4 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_19 . V_18 ;
struct V_17 * V_20 = & V_14 -> V_20 ;
struct V_17 * V_21 = & V_14 -> V_22 ;
F_12 ( L_1 ) ;
if ( V_18 )
F_14 ( V_18 , V_20 ) ;
if ( V_4 -> V_23 . V_24 -> V_25 )
return V_4 -> V_23 . V_24 -> V_25 ( & V_4 -> V_23 ,
V_21 , V_20 ) ;
return true ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_23 -> V_26 ;
struct V_27 * V_27 = F_16 ( V_12 -> V_7 . V_28 ) ;
int V_29 = V_27 -> V_29 ;
T_1 V_30 ;
F_12 ( L_1 ) ;
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 , 0x04 , 0x0004 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_1 ( V_2 ) ;
F_17 ( F_18 ( V_29 ) , V_31 ) ;
F_19 ( 2500 , 3000 ) ;
V_30 = F_20 ( F_21 ( V_29 ) ) ;
F_17 ( F_21 ( V_29 ) , V_30 | V_32 ) ;
F_19 ( 1000 , 1500 ) ;
F_17 ( F_18 ( V_29 ) , V_33 ) ;
F_19 ( 2500 , 3000 ) ;
F_17 ( F_18 ( V_29 ) , V_34 ) ;
F_19 ( 2500 , 3000 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_35 * V_23 = V_12 -> V_7 . V_23 ;
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_27 * V_27 = F_16 ( V_12 -> V_7 . V_28 ) ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
int V_29 = V_27 -> V_29 ;
T_1 V_36 ;
F_12 ( L_1 ) ;
if ( F_10 ( V_4 ) )
F_17 ( F_24 ( V_29 ) , 8 * 4 ) ;
else {
F_25 ( 20 ) ;
F_26 ( V_4 , V_37 , V_38 ) ;
F_25 ( 100 ) ;
if ( V_4 -> V_23 . V_24 -> V_39 )
V_4 -> V_23 . V_24 -> V_39 ( & V_4 -> V_23 ) ;
V_36 = F_20 ( F_21 ( V_29 ) ) & ~ V_40 ;
V_36 = V_36 | V_4 -> V_41 ;
F_17 ( F_21 ( V_29 ) , V_36 | V_42 ) ;
F_27 ( F_21 ( V_29 ) ) ;
}
}
static void F_28 ( struct V_11 * V_12 )
{
struct V_35 * V_23 = V_12 -> V_7 . V_23 ;
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
struct V_27 * V_27 = F_16 ( V_12 -> V_7 . V_28 ) ;
enum V_29 V_29 = V_27 -> V_29 ;
T_1 V_43 ;
F_12 ( L_1 ) ;
V_43 = F_20 ( F_29 ( V_29 ) ) ;
V_43 |= V_44 ;
F_17 ( F_29 ( V_29 ) , V_43 ) ;
V_43 = F_20 ( V_45 ) ;
V_43 |= V_46 ;
F_17 ( V_45 , V_43 ) ;
F_15 ( V_12 ) ;
F_25 ( V_4 -> V_47 ) ;
if ( V_4 -> V_23 . V_24 -> V_48 )
V_4 -> V_23 . V_24 -> V_48 ( & V_4 -> V_23 ) ;
if ( V_4 -> V_23 . V_24 -> V_49 )
V_4 -> V_23 . V_24 -> V_49 ( & V_4 -> V_23 ) ;
F_22 ( V_12 ) ;
}
static void F_30 ( struct V_11 * V_12 )
{
F_12 ( L_1 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
F_12 ( L_1 ) ;
if ( F_9 ( V_4 ) ) {
F_26 ( V_4 , V_50 , V_38 ) ;
F_25 ( 10 ) ;
}
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_35 * V_23 = V_12 -> V_7 . V_23 ;
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_27 * V_27 = F_16 ( V_12 -> V_7 . V_28 ) ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
int V_29 = V_27 -> V_29 ;
T_1 V_36 ;
F_12 ( L_1 ) ;
if ( F_9 ( V_4 ) ) {
V_36 = F_20 ( F_21 ( V_29 ) ) ;
F_17 ( F_21 ( V_29 ) , V_36 & ~ V_42 ) ;
F_27 ( F_21 ( V_29 ) ) ;
F_25 ( 2 ) ;
}
F_17 ( F_18 ( V_29 ) , 0x0 ) ;
V_36 = F_20 ( F_33 ( V_29 ) ) ;
V_36 &= ~ V_51 ;
F_17 ( F_33 ( V_29 ) , V_36 |
V_4 -> V_52 <<
V_53 ) ;
F_17 ( F_34 ( V_29 ) , V_54 ) ;
V_36 = F_20 ( F_35 ( V_29 ) ) ;
V_36 &= ~ V_55 ;
F_17 ( F_35 ( V_29 ) , V_36 ) ;
F_17 ( F_18 ( V_29 ) , 0x1 ) ;
if ( V_4 -> V_23 . V_24 -> V_56 )
V_4 -> V_23 . V_24 -> V_56 ( & V_4 -> V_23 ) ;
}
static void F_36 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_23 -> V_26 ;
struct V_27 * V_27 = F_16 ( V_12 -> V_7 . V_28 ) ;
int V_29 = V_27 -> V_29 ;
T_1 V_30 ;
F_12 ( L_1 ) ;
F_17 ( F_18 ( V_29 ) , V_34 | V_31 ) ;
F_19 ( 2000 , 2500 ) ;
F_17 ( F_18 ( V_29 ) , V_34 | V_33 ) ;
F_19 ( 2000 , 2500 ) ;
F_17 ( F_18 ( V_29 ) , V_34 | V_31 ) ;
F_19 ( 2000 , 2500 ) ;
if ( F_37 ( ( ( F_20 ( F_21 ( V_29 ) ) & V_57 )
== 0x00000 ) , 30 ) )
F_38 ( L_2 ) ;
V_30 = F_20 ( F_21 ( V_29 ) ) ;
F_17 ( F_21 ( V_29 ) , V_30 & ~ V_32 ) ;
F_19 ( 1000 , 1500 ) ;
F_17 ( F_18 ( V_29 ) , 0x00 ) ;
F_19 ( 2000 , 2500 ) ;
F_39 ( V_12 ) ;
}
static void F_40 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_23 -> V_26 ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
T_1 V_30 ;
F_12 ( L_1 ) ;
F_32 ( V_12 ) ;
F_36 ( V_12 ) ;
V_30 = F_20 ( V_45 ) ;
V_30 &= ~ V_46 ;
F_17 ( V_45 , V_30 ) ;
if ( V_4 -> V_23 . V_24 -> V_58 )
V_4 -> V_23 . V_24 -> V_58 ( & V_4 -> V_23 ) ;
F_25 ( V_4 -> V_59 ) ;
F_25 ( V_4 -> V_60 ) ;
}
static bool F_41 ( struct V_11 * V_12 ,
enum V_29 * V_29 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_23 -> V_26 ;
enum V_61 V_62 ;
T_1 V_63 , V_64 ;
enum V_29 V_65 ;
F_12 ( L_1 ) ;
V_62 = F_42 ( V_12 ) ;
if ( ! F_43 ( V_2 , V_62 ) )
return false ;
for ( V_65 = V_66 ; V_65 <= V_67 ; V_65 ++ ) {
V_63 = F_20 ( F_21 ( V_65 ) ) ;
V_64 = F_20 ( F_35 ( V_65 ) ) ;
if ( ( V_63 & V_42 ) || ( V_64 & V_68 ) ) {
if ( F_20 ( F_18 ( V_65 ) ) & V_34 ) {
* V_29 = V_65 ;
return true ;
}
}
}
return false ;
}
static void F_44 ( struct V_11 * V_12 ,
struct V_13 * V_69 )
{
F_12 ( L_1 ) ;
}
static enum V_70
F_45 ( struct V_5 * V_6 ,
struct V_17 * V_21 )
{
struct V_15 * V_15 = F_46 ( V_6 ) ;
struct V_17 * V_18 = V_15 -> V_19 . V_18 ;
struct V_4 * V_4 = F_6 ( V_6 ) ;
F_12 ( L_1 ) ;
if ( V_21 -> V_71 & V_72 ) {
F_12 ( L_3 ) ;
return V_73 ;
}
if ( V_18 ) {
if ( V_21 -> V_74 > V_18 -> V_74 )
return V_75 ;
if ( V_21 -> V_76 > V_18 -> V_76 )
return V_75 ;
}
return V_4 -> V_23 . V_24 -> V_77 ( & V_4 -> V_23 , V_21 ) ;
}
static T_2 F_47 ( T_1 V_78 , unsigned int V_79 )
{
switch ( V_78 ) {
case V_80 :
default:
return 20 * V_79 ;
case V_81 :
return 10 * V_79 ;
case V_82 :
return 5 * V_79 ;
}
}
static T_2 F_48 ( T_2 V_83 , int V_84 , int V_85 )
{
return F_49 ( F_49 ( V_83 * V_84 , 8 ) , V_85 ) ;
}
static void F_50 ( struct V_86 * V_12 ,
const struct V_17 * V_21 )
{
struct V_35 * V_23 = V_12 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_27 * V_27 = F_16 ( V_12 -> V_28 ) ;
struct V_4 * V_4 = F_23 ( V_12 ) ;
int V_29 = V_27 -> V_29 ;
unsigned int V_84 = V_27 -> V_14 . V_87 ;
unsigned int V_85 = V_4 -> V_85 ;
T_2 V_88 , V_89 , V_90 , V_91 , V_92 , V_93 , V_94 ;
V_88 = V_21 -> V_74 ;
V_89 = V_21 -> V_95 - V_21 -> V_74 ;
V_90 = V_21 -> V_96 - V_21 -> V_95 ;
V_91 = V_21 -> V_97 - V_21 -> V_96 ;
V_92 = V_21 -> V_98 - V_21 -> V_76 ;
V_93 = V_21 -> V_99 - V_21 -> V_98 ;
V_94 = V_21 -> V_100 - V_21 -> V_99 ;
V_88 = F_48 ( V_88 , V_84 , V_85 ) ;
V_89 = F_48 ( V_89 , V_84 , V_85 ) ;
V_90 = F_48 ( V_90 , V_84 , V_85 ) ;
V_91 = F_48 ( V_91 , V_84 , V_85 ) ;
F_17 ( F_51 ( V_29 ) , V_88 ) ;
F_17 ( F_52 ( V_29 ) , V_89 ) ;
F_17 ( F_53 ( V_29 ) , V_90 ) ;
F_17 ( F_54 ( V_29 ) , V_91 ) ;
F_17 ( F_55 ( V_29 ) , V_92 ) ;
F_17 ( F_56 ( V_29 ) , V_93 ) ;
F_17 ( F_57 ( V_29 ) , V_94 ) ;
}
static void F_58 ( struct V_11 * V_11 )
{
struct V_86 * V_12 = & V_11 -> V_7 ;
struct V_35 * V_23 = V_12 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_26 ;
struct V_27 * V_27 = F_16 ( V_12 -> V_28 ) ;
struct V_4 * V_4 = F_23 ( V_12 ) ;
struct V_17 * V_20 =
& V_27 -> V_14 . V_20 ;
int V_29 = V_27 -> V_29 ;
unsigned int V_84 = V_27 -> V_14 . V_87 ;
T_1 V_30 , V_43 ;
F_12 ( L_4 , F_59 ( V_29 ) ) ;
V_43 = F_20 ( F_33 ( 0 ) ) ;
V_43 &= ~ V_51 ;
F_17 ( F_33 ( 0 ) , V_43 | V_80 ) ;
V_43 = F_20 ( F_33 ( V_29 ) ) ;
V_43 &= ~ V_101 ;
F_17 ( F_33 ( V_29 ) , V_43 | V_102 ) ;
F_17 ( F_60 ( V_29 ) , 0xffffffff ) ;
F_17 ( F_61 ( V_29 ) , 0xffffffff ) ;
F_17 ( F_62 ( V_29 ) , V_4 -> V_103 ) ;
F_17 ( F_63 ( V_29 ) ,
V_20 -> V_76 << V_104 |
V_20 -> V_74 << V_105 ) ;
F_50 ( V_12 , V_20 ) ;
V_30 = V_4 -> V_85 << V_106 ;
if ( F_10 ( V_4 ) ) {
V_30 |= V_4 -> V_107 << V_108 ;
V_30 |= V_109 ;
} else {
V_30 |= V_4 -> V_107 << V_110 ;
V_30 |= V_4 -> V_111 ;
}
F_17 ( F_35 ( V_29 ) , V_30 ) ;
if ( F_9 ( V_4 ) &&
V_4 -> V_112 == V_113 ) {
F_17 ( F_64 ( V_29 ) ,
F_48 ( V_20 -> V_97 , V_84 ,
V_4 -> V_85 ) + 1 ) ;
} else {
F_17 ( F_64 ( V_29 ) ,
F_48 ( V_20 -> V_100 *
V_20 -> V_97 ,
V_84 , V_4 -> V_85 ) + 1 ) ;
}
F_17 ( F_65 ( V_29 ) , V_4 -> V_114 ) ;
F_17 ( F_66 ( V_29 ) , V_4 -> V_115 ) ;
F_17 ( F_67 ( V_29 ) , V_4 -> V_116 ) ;
F_17 ( F_68 ( V_29 ) , F_47 ( V_4 -> V_52 , 100 ) ) ;
V_30 = 0 ;
if ( V_4 -> V_117 == 0 )
V_30 |= V_118 ;
if ( V_4 -> V_119 )
V_30 |= V_54 ;
F_17 ( F_34 ( V_29 ) , V_30 ) ;
F_17 ( F_68 ( V_29 ) , V_4 -> V_120 ) ;
F_17 ( F_69 ( V_29 ) ,
V_4 -> V_121 ) ;
F_17 ( F_70 ( V_29 ) , V_4 -> V_122 ) ;
F_17 ( F_71 ( V_29 ) , V_4 -> V_123 ) ;
F_17 ( F_72 ( V_29 ) ,
V_4 -> V_124 << V_125 |
V_4 -> V_126 << V_127 ) ;
if ( F_9 ( V_4 ) )
F_17 ( F_73 ( V_29 ) ,
V_4 -> V_128 |
V_4 -> V_112 |
V_129 |
V_130 ) ;
}
static void F_74 ( struct V_11 * V_12 )
{
F_12 ( L_1 ) ;
F_58 ( V_12 ) ;
F_75 ( V_12 ) ;
}
static enum V_131
F_76 ( struct V_5 * V_6 , bool V_132 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
struct V_11 * V_11 = & V_4 -> V_7 ;
enum V_61 V_62 ;
enum V_131 V_133 ;
struct V_1 * V_2 = V_11 -> V_7 . V_23 -> V_26 ;
F_12 ( L_1 ) ;
V_62 = F_42 ( V_11 ) ;
F_77 ( V_2 , V_62 ) ;
V_133 = V_4 -> V_23 . V_24 -> V_134 ( & V_4 -> V_23 ) ;
F_78 ( V_2 , V_62 ) ;
return V_133 ;
}
static int F_79 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_46 ( V_6 ) ;
struct V_17 * V_21 ;
F_12 ( L_1 ) ;
if ( ! V_15 -> V_19 . V_18 ) {
F_12 ( L_5 ) ;
return 0 ;
}
V_21 = F_80 ( V_6 -> V_23 ,
V_15 -> V_19 . V_18 ) ;
if ( ! V_21 ) {
F_12 ( L_6 ) ;
return 0 ;
}
F_81 ( V_6 , V_21 ) ;
return 1 ;
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_46 ( V_6 ) ;
F_12 ( L_1 ) ;
F_83 ( & V_15 -> V_19 ) ;
F_84 ( V_6 ) ;
F_85 ( V_6 ) ;
}
bool F_86 ( struct V_35 * V_23 )
{
struct V_4 * V_4 ;
struct V_11 * V_11 ;
struct V_86 * V_12 ;
struct V_15 * V_15 ;
struct V_5 * V_6 ;
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 = V_23 -> V_26 ;
const struct V_135 * V_136 ;
unsigned int V_137 ;
F_12 ( L_1 ) ;
if ( ! V_2 -> V_138 . V_139 )
return false ;
V_4 = F_87 ( sizeof( * V_4 ) , V_140 ) ;
if ( ! V_4 )
return false ;
V_15 = F_87 ( sizeof( * V_15 ) , V_140 ) ;
if ( ! V_15 ) {
F_85 ( V_4 ) ;
return false ;
}
V_11 = & V_4 -> V_7 ;
V_12 = & V_11 -> V_7 ;
V_4 -> V_16 = V_15 ;
if ( F_88 ( V_23 ) ) {
V_2 -> V_141 = V_142 ;
} else {
F_38 ( L_7 ) ;
return false ;
}
V_6 = & V_15 -> V_7 ;
F_89 ( V_23 , V_12 , & V_143 , V_144 ) ;
V_11 -> V_145 = F_11 ;
V_11 -> V_146 = F_13 ;
V_11 -> V_147 = F_74 ;
V_11 -> V_148 = F_28 ;
V_11 -> V_39 = F_30 ;
V_11 -> V_56 = F_31 ;
V_11 -> V_149 = F_40 ;
V_11 -> V_150 = F_41 ;
V_11 -> V_151 = F_44 ;
V_15 -> V_150 = V_152 ;
V_15 -> V_153 = V_154 ;
for ( V_137 = 0 ; V_137 < F_90 ( V_155 ) ; V_137 ++ ) {
V_136 = & V_155 [ V_137 ] ;
V_4 -> V_23 = * V_136 ;
if ( V_136 -> V_24 -> V_156 ( & V_4 -> V_23 ) )
break;
}
if ( V_137 == F_90 ( V_155 ) ) {
F_12 ( L_8 ) ;
goto V_157;
}
V_11 -> type = V_158 ;
V_11 -> V_159 = ( 1 << 0 ) ;
V_11 -> V_160 = 0 ;
F_91 ( V_23 , V_6 , & V_161 ,
V_162 ) ;
F_92 ( V_6 , & V_163 ) ;
V_6 -> V_164 . V_165 = V_166 ;
V_6 -> V_167 = false ;
V_6 -> V_168 = false ;
F_93 ( V_15 , V_11 ) ;
F_94 ( V_6 ) ;
V_18 = V_136 -> V_24 -> V_169 ( & V_4 -> V_23 ) ;
if ( ! V_18 ) {
F_12 ( L_5 ) ;
goto V_157;
}
V_18 -> type |= V_170 ;
F_95 ( & V_15 -> V_19 , V_18 , NULL ) ;
return true ;
V_157:
F_96 ( & V_11 -> V_7 ) ;
F_85 ( V_4 ) ;
F_85 ( V_15 ) ;
return false ;
}
