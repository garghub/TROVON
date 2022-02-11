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
V_20 -> V_23 = 0 ;
if ( V_4 -> V_24 . V_25 -> V_26 )
return V_4 -> V_24 . V_25 -> V_26 ( & V_4 -> V_24 ,
V_21 , V_20 ) ;
return true ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_24 -> V_27 ;
struct V_28 * V_28 = F_16 ( V_12 -> V_7 . V_29 ) ;
int V_30 = V_28 -> V_30 ;
T_1 V_31 ;
F_12 ( L_1 ) ;
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 , 0x04 , 0x0004 ) ;
F_5 ( & V_2 -> V_3 ) ;
F_1 ( V_2 ) ;
F_17 ( F_18 ( V_30 ) , V_32 ) ;
F_19 ( 2500 , 3000 ) ;
V_31 = F_20 ( F_21 ( V_30 ) ) ;
F_17 ( F_21 ( V_30 ) , V_31 | V_33 ) ;
F_19 ( 1000 , 1500 ) ;
F_17 ( F_18 ( V_30 ) , V_34 ) ;
F_19 ( 2500 , 3000 ) ;
F_17 ( F_18 ( V_30 ) , V_35 ) ;
F_19 ( 2500 , 3000 ) ;
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_36 * V_24 = V_12 -> V_7 . V_24 ;
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_28 = F_16 ( V_12 -> V_7 . V_29 ) ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
int V_30 = V_28 -> V_30 ;
T_1 V_37 ;
F_12 ( L_1 ) ;
if ( F_10 ( V_4 ) )
F_17 ( F_24 ( V_30 ) , 8 * 4 ) ;
else {
F_25 ( 20 ) ;
F_26 ( V_4 , V_38 , V_39 ) ;
F_25 ( 100 ) ;
if ( V_4 -> V_24 . V_25 -> V_40 )
V_4 -> V_24 . V_25 -> V_40 ( & V_4 -> V_24 ) ;
F_27 ( V_4 ) ;
V_37 = F_20 ( F_21 ( V_30 ) ) & ~ V_41 ;
V_37 = V_37 | V_4 -> V_42 ;
F_17 ( F_21 ( V_30 ) , V_37 | V_43 ) ;
F_28 ( F_21 ( V_30 ) ) ;
}
}
static void F_29 ( struct V_11 * V_12 )
{
struct V_36 * V_24 = V_12 -> V_7 . V_24 ;
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
struct V_28 * V_28 = F_16 ( V_12 -> V_7 . V_29 ) ;
enum V_30 V_30 = V_28 -> V_30 ;
T_1 V_44 ;
F_12 ( L_1 ) ;
V_44 = F_20 ( F_30 ( V_30 ) ) ;
V_44 |= V_45 ;
F_17 ( F_30 ( V_30 ) , V_44 ) ;
V_28 -> V_14 . V_46 . V_47 = V_48 |
V_45 ;
V_44 = F_20 ( V_49 ) ;
V_44 |= V_50 ;
F_17 ( V_49 , V_44 ) ;
F_15 ( V_12 ) ;
F_25 ( V_4 -> V_51 ) ;
if ( V_4 -> V_24 . V_25 -> V_52 )
V_4 -> V_24 . V_25 -> V_52 ( & V_4 -> V_24 ) ;
if ( V_4 -> V_24 . V_25 -> V_53 )
V_4 -> V_24 . V_25 -> V_53 ( & V_4 -> V_24 ) ;
F_27 ( V_4 ) ;
F_22 ( V_12 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
F_12 ( L_1 ) ;
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
F_12 ( L_1 ) ;
if ( F_9 ( V_4 ) ) {
F_26 ( V_4 , V_54 , V_39 ) ;
F_25 ( 10 ) ;
}
}
static void F_33 ( struct V_11 * V_12 )
{
struct V_36 * V_24 = V_12 -> V_7 . V_24 ;
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_28 = F_16 ( V_12 -> V_7 . V_29 ) ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
int V_30 = V_28 -> V_30 ;
T_1 V_37 ;
F_12 ( L_1 ) ;
if ( F_9 ( V_4 ) ) {
F_27 ( V_4 ) ;
V_37 = F_20 ( F_21 ( V_30 ) ) ;
F_17 ( F_21 ( V_30 ) , V_37 & ~ V_43 ) ;
F_28 ( F_21 ( V_30 ) ) ;
F_25 ( 2 ) ;
}
F_17 ( F_18 ( V_30 ) , 0x0 ) ;
V_37 = F_20 ( F_34 ( V_30 ) ) ;
V_37 &= ~ V_55 ;
F_17 ( F_34 ( V_30 ) , V_37 |
V_4 -> V_56 <<
V_57 ) ;
F_17 ( F_35 ( V_30 ) , V_58 ) ;
V_37 = F_20 ( F_36 ( V_30 ) ) ;
V_37 &= ~ V_59 ;
F_17 ( F_36 ( V_30 ) , V_37 ) ;
F_17 ( F_18 ( V_30 ) , 0x1 ) ;
if ( V_4 -> V_24 . V_25 -> V_60 )
V_4 -> V_24 . V_25 -> V_60 ( & V_4 -> V_24 ) ;
F_27 ( V_4 ) ;
}
static void F_37 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_24 -> V_27 ;
struct V_28 * V_28 = F_16 ( V_12 -> V_7 . V_29 ) ;
int V_30 = V_28 -> V_30 ;
T_1 V_31 ;
F_12 ( L_1 ) ;
F_17 ( F_18 ( V_30 ) , V_35 | V_32 ) ;
F_19 ( 2000 , 2500 ) ;
F_17 ( F_18 ( V_30 ) , V_35 | V_34 ) ;
F_19 ( 2000 , 2500 ) ;
F_17 ( F_18 ( V_30 ) , V_35 | V_32 ) ;
F_19 ( 2000 , 2500 ) ;
if ( F_38 ( ( ( F_20 ( F_21 ( V_30 ) ) & V_61 )
== 0x00000 ) , 30 ) )
F_39 ( L_2 ) ;
V_31 = F_20 ( F_21 ( V_30 ) ) ;
F_17 ( F_21 ( V_30 ) , V_31 & ~ V_33 ) ;
F_19 ( 1000 , 1500 ) ;
F_17 ( F_18 ( V_30 ) , 0x00 ) ;
F_19 ( 2000 , 2500 ) ;
F_40 ( V_12 ) ;
}
static void F_41 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_24 -> V_27 ;
struct V_4 * V_4 = F_23 ( & V_12 -> V_7 ) ;
T_1 V_31 ;
F_12 ( L_1 ) ;
F_33 ( V_12 ) ;
F_37 ( V_12 ) ;
V_31 = F_20 ( V_49 ) ;
V_31 &= ~ V_50 ;
F_17 ( V_49 , V_31 ) ;
if ( V_4 -> V_24 . V_25 -> V_62 )
V_4 -> V_24 . V_25 -> V_62 ( & V_4 -> V_24 ) ;
F_25 ( V_4 -> V_63 ) ;
F_25 ( V_4 -> V_64 ) ;
}
static bool F_42 ( struct V_11 * V_12 ,
enum V_30 * V_30 )
{
struct V_1 * V_2 = V_12 -> V_7 . V_24 -> V_27 ;
enum V_65 V_66 ;
T_1 V_67 , V_68 ;
enum V_30 V_69 ;
F_12 ( L_1 ) ;
V_66 = F_43 ( V_12 ) ;
if ( ! F_44 ( V_2 , V_66 ) )
return false ;
for ( V_69 = V_70 ; V_69 <= V_71 ; V_69 ++ ) {
V_67 = F_20 ( F_21 ( V_69 ) ) ;
V_68 = F_20 ( F_36 ( V_69 ) ) ;
if ( ( V_67 & V_43 ) || ( V_68 & V_72 ) ) {
if ( F_20 ( F_18 ( V_69 ) ) & V_35 ) {
* V_30 = V_69 ;
return true ;
}
}
}
return false ;
}
static void F_45 ( struct V_11 * V_12 ,
struct V_13 * V_73 )
{
T_1 V_74 ;
F_12 ( L_1 ) ;
V_73 -> V_46 . V_75 = 0 ;
V_74 = F_46 ( V_12 , V_73 -> V_76 ) ;
if ( ! V_74 )
return;
V_73 -> V_20 . V_77 = V_74 ;
V_73 -> V_78 = V_74 ;
}
static enum V_79
F_47 ( struct V_5 * V_6 ,
struct V_17 * V_21 )
{
struct V_15 * V_15 = F_48 ( V_6 ) ;
struct V_17 * V_18 = V_15 -> V_19 . V_18 ;
struct V_4 * V_4 = F_6 ( V_6 ) ;
F_12 ( L_1 ) ;
if ( V_21 -> V_23 & V_80 ) {
F_12 ( L_3 ) ;
return V_81 ;
}
if ( V_18 ) {
if ( V_21 -> V_82 > V_18 -> V_82 )
return V_83 ;
if ( V_21 -> V_84 > V_18 -> V_84 )
return V_83 ;
}
return V_4 -> V_24 . V_25 -> V_85 ( & V_4 -> V_24 , V_21 ) ;
}
static T_2 F_49 ( T_1 V_86 , unsigned int V_87 )
{
switch ( V_86 ) {
case V_88 :
default:
return 20 * V_87 ;
case V_89 :
return 10 * V_87 ;
case V_90 :
return 5 * V_87 ;
}
}
static T_2 F_50 ( T_2 V_91 , int V_92 , int V_93 )
{
return F_51 ( F_51 ( V_91 * V_92 , 8 ) , V_93 ) ;
}
static void F_52 ( struct V_94 * V_12 ,
const struct V_17 * V_21 )
{
struct V_36 * V_24 = V_12 -> V_24 ;
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_28 = F_16 ( V_12 -> V_29 ) ;
struct V_4 * V_4 = F_23 ( V_12 ) ;
int V_30 = V_28 -> V_30 ;
unsigned int V_92 = V_28 -> V_14 . V_76 ;
unsigned int V_93 = V_4 -> V_93 ;
T_2 V_95 , V_96 , V_97 , V_98 , V_99 , V_100 , V_101 ;
V_95 = V_21 -> V_82 ;
V_96 = V_21 -> V_102 - V_21 -> V_82 ;
V_97 = V_21 -> V_103 - V_21 -> V_102 ;
V_98 = V_21 -> V_104 - V_21 -> V_103 ;
V_99 = V_21 -> V_105 - V_21 -> V_84 ;
V_100 = V_21 -> V_106 - V_21 -> V_105 ;
V_101 = V_21 -> V_107 - V_21 -> V_106 ;
V_95 = F_50 ( V_95 , V_92 , V_93 ) ;
V_96 = F_50 ( V_96 , V_92 , V_93 ) ;
V_97 = F_50 ( V_97 , V_92 , V_93 ) ;
V_98 = F_50 ( V_98 , V_92 , V_93 ) ;
F_17 ( F_53 ( V_30 ) , V_95 ) ;
F_17 ( F_54 ( V_30 ) , V_96 ) ;
F_17 ( F_55 ( V_30 ) , V_97 ) ;
F_17 ( F_56 ( V_30 ) , V_98 ) ;
F_17 ( F_57 ( V_30 ) , V_99 ) ;
F_17 ( F_58 ( V_30 ) , V_100 ) ;
F_17 ( F_59 ( V_30 ) , V_101 ) ;
}
static void F_60 ( struct V_11 * V_11 )
{
struct V_94 * V_12 = & V_11 -> V_7 ;
struct V_36 * V_24 = V_12 -> V_24 ;
struct V_1 * V_2 = V_24 -> V_27 ;
struct V_28 * V_28 = F_16 ( V_12 -> V_29 ) ;
struct V_4 * V_4 = F_23 ( V_12 ) ;
struct V_17 * V_20 =
& V_28 -> V_14 . V_20 ;
int V_30 = V_28 -> V_30 ;
unsigned int V_92 = V_28 -> V_14 . V_76 ;
T_1 V_31 , V_44 ;
F_12 ( L_4 , F_61 ( V_30 ) ) ;
V_44 = F_20 ( F_34 ( 0 ) ) ;
V_44 &= ~ V_55 ;
F_17 ( F_34 ( 0 ) , V_44 | V_88 ) ;
V_44 = F_20 ( F_34 ( V_30 ) ) ;
V_44 &= ~ V_108 ;
F_17 ( F_34 ( V_30 ) , V_44 | V_109 ) ;
F_17 ( F_62 ( V_30 ) , 0xffffffff ) ;
F_17 ( F_63 ( V_30 ) , 0xffffffff ) ;
F_17 ( F_64 ( V_30 ) , V_4 -> V_110 ) ;
F_17 ( F_65 ( V_30 ) ,
V_20 -> V_84 << V_111 |
V_20 -> V_82 << V_112 ) ;
F_52 ( V_12 , V_20 ) ;
V_31 = V_4 -> V_93 << V_113 ;
if ( F_10 ( V_4 ) ) {
V_31 |= V_4 -> V_114 << V_115 ;
V_31 |= V_116 ;
} else {
V_31 |= V_4 -> V_114 << V_117 ;
V_31 |= V_4 -> V_118 ;
}
F_17 ( F_36 ( V_30 ) , V_31 ) ;
if ( F_9 ( V_4 ) &&
V_4 -> V_119 == V_120 ) {
F_17 ( F_66 ( V_30 ) ,
F_50 ( V_20 -> V_104 , V_92 ,
V_4 -> V_93 ) + 1 ) ;
} else {
F_17 ( F_66 ( V_30 ) ,
F_50 ( V_20 -> V_107 *
V_20 -> V_104 ,
V_92 , V_4 -> V_93 ) + 1 ) ;
}
F_17 ( F_67 ( V_30 ) , V_4 -> V_121 ) ;
F_17 ( F_68 ( V_30 ) , V_4 -> V_122 ) ;
F_17 ( F_69 ( V_30 ) , V_4 -> V_123 ) ;
F_17 ( F_70 ( V_30 ) , F_49 ( V_4 -> V_56 , 100 ) ) ;
V_31 = 0 ;
if ( V_4 -> V_124 == 0 )
V_31 |= V_125 ;
if ( V_4 -> V_126 )
V_31 |= V_58 ;
F_17 ( F_35 ( V_30 ) , V_31 ) ;
F_17 ( F_70 ( V_30 ) , V_4 -> V_127 ) ;
F_17 ( F_71 ( V_30 ) ,
V_4 -> V_128 ) ;
F_17 ( F_72 ( V_30 ) , V_4 -> V_129 ) ;
F_17 ( F_73 ( V_30 ) , V_4 -> V_130 ) ;
F_17 ( F_74 ( V_30 ) ,
V_4 -> V_131 << V_132 |
V_4 -> V_133 << V_134 ) ;
if ( F_9 ( V_4 ) )
F_17 ( F_75 ( V_30 ) ,
V_4 -> V_135 |
V_4 -> V_119 |
V_136 |
V_137 ) ;
}
static void F_76 ( struct V_11 * V_12 )
{
F_12 ( L_1 ) ;
F_60 ( V_12 ) ;
F_77 ( V_12 ) ;
}
static enum V_138
F_78 ( struct V_5 * V_6 , bool V_139 )
{
struct V_4 * V_4 = F_6 ( V_6 ) ;
struct V_11 * V_11 = & V_4 -> V_7 ;
enum V_65 V_66 ;
enum V_138 V_140 ;
struct V_1 * V_2 = V_11 -> V_7 . V_24 -> V_27 ;
F_12 ( L_1 ) ;
V_66 = F_43 ( V_11 ) ;
F_79 ( V_2 , V_66 ) ;
V_140 = V_4 -> V_24 . V_25 -> V_141 ( & V_4 -> V_24 ) ;
F_80 ( V_2 , V_66 ) ;
return V_140 ;
}
static int F_81 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_48 ( V_6 ) ;
struct V_17 * V_21 ;
F_12 ( L_1 ) ;
if ( ! V_15 -> V_19 . V_18 ) {
F_12 ( L_5 ) ;
return 0 ;
}
V_21 = F_82 ( V_6 -> V_24 ,
V_15 -> V_19 . V_18 ) ;
if ( ! V_21 ) {
F_12 ( L_6 ) ;
return 0 ;
}
F_83 ( V_6 , V_21 ) ;
return 1 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_15 * V_15 = F_48 ( V_6 ) ;
F_12 ( L_1 ) ;
F_85 ( & V_15 -> V_19 ) ;
F_86 ( V_6 ) ;
F_87 ( V_6 ) ;
}
void F_88 ( struct V_36 * V_24 )
{
struct V_4 * V_4 ;
struct V_11 * V_11 ;
struct V_94 * V_12 ;
struct V_15 * V_15 ;
struct V_5 * V_6 ;
struct V_17 * V_18 = NULL ;
struct V_1 * V_2 = V_24 -> V_27 ;
const struct V_142 * V_143 ;
unsigned int V_144 ;
F_12 ( L_1 ) ;
if ( ! V_2 -> V_145 . V_146 )
return;
if ( F_89 ( V_24 ) ) {
V_2 -> V_147 = V_148 ;
} else {
F_39 ( L_7 ) ;
return;
}
V_4 = F_90 ( sizeof( * V_4 ) , V_149 ) ;
if ( ! V_4 )
return;
V_15 = F_90 ( sizeof( * V_15 ) , V_149 ) ;
if ( ! V_15 ) {
F_87 ( V_4 ) ;
return;
}
V_11 = & V_4 -> V_7 ;
V_12 = & V_11 -> V_7 ;
V_4 -> V_16 = V_15 ;
V_6 = & V_15 -> V_7 ;
F_91 ( V_24 , V_12 , & V_150 , V_151 ) ;
V_11 -> V_152 = F_11 ;
V_11 -> V_153 = F_13 ;
V_11 -> V_154 = F_76 ;
V_11 -> V_155 = F_29 ;
V_11 -> V_40 = F_31 ;
V_11 -> V_60 = F_32 ;
V_11 -> V_156 = F_41 ;
V_11 -> V_157 = F_42 ;
V_11 -> V_158 = F_45 ;
V_15 -> V_157 = V_159 ;
V_15 -> V_160 = V_161 ;
for ( V_144 = 0 ; V_144 < F_92 ( V_162 ) ; V_144 ++ ) {
V_143 = & V_162 [ V_144 ] ;
V_4 -> V_24 = * V_143 ;
if ( V_143 -> V_25 -> V_163 ( & V_4 -> V_24 ) )
break;
}
if ( V_144 == F_92 ( V_162 ) ) {
F_12 ( L_8 ) ;
goto V_164;
}
V_11 -> type = V_165 ;
V_11 -> V_166 = ( 1 << 0 ) ;
V_11 -> V_167 = 0 ;
F_93 ( V_24 , V_6 , & V_168 ,
V_169 ) ;
F_94 ( V_6 , & V_170 ) ;
V_6 -> V_171 . V_172 = V_173 ;
V_6 -> V_174 = false ;
V_6 -> V_175 = false ;
F_95 ( V_15 , V_11 ) ;
F_96 ( V_6 ) ;
V_18 = V_143 -> V_25 -> V_176 ( & V_4 -> V_24 ) ;
if ( ! V_18 ) {
F_12 ( L_5 ) ;
goto V_164;
}
V_18 -> type |= V_177 ;
F_97 ( & V_15 -> V_19 , V_18 , NULL ) ;
return;
V_164:
F_98 ( & V_11 -> V_7 ) ;
F_87 ( V_4 ) ;
F_87 ( V_15 ) ;
}
