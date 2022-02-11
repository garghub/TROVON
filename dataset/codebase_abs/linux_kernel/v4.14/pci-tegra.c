static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline void F_3 ( struct V_4 * V_5 , T_1 V_6 ,
unsigned long V_7 )
{
F_4 ( V_6 , V_5 -> V_8 + V_7 ) ;
}
static inline T_1 F_5 ( struct V_4 * V_5 , unsigned long V_7 )
{
return F_6 ( V_5 -> V_8 + V_7 ) ;
}
static inline void F_7 ( struct V_4 * V_5 , T_1 V_6 ,
unsigned long V_7 )
{
F_4 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static inline T_1 F_8 ( struct V_4 * V_5 , unsigned long V_7 )
{
return F_6 ( V_5 -> V_9 + V_7 ) ;
}
static unsigned long F_9 ( unsigned int V_10 , int V_11 )
{
return ( ( V_11 & 0xf00 ) << 8 ) | ( F_10 ( V_10 ) << 11 ) |
( F_11 ( V_10 ) << 8 ) | ( V_11 & 0xfc ) ;
}
static struct V_12 * F_12 ( struct V_4 * V_5 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
T_2 V_16 = F_13 ( V_17 ) ;
T_3 V_18 = V_5 -> V_18 -> V_19 ;
struct V_12 * V_20 ;
unsigned int V_21 ;
int V_22 ;
V_20 = F_14 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_20 )
return F_15 ( - V_24 ) ;
F_16 ( & V_20 -> V_25 ) ;
V_20 -> V_26 = V_13 ;
V_20 -> V_27 = F_17 ( V_28 , V_29 ) ;
if ( ! V_20 -> V_27 ) {
V_22 = - V_24 ;
goto free;
}
for ( V_21 = 0 ; V_21 < 16 ; V_21 ++ ) {
unsigned long V_30 = ( unsigned long ) V_20 -> V_27 -> V_31 +
V_21 * V_32 ;
T_3 V_33 = V_18 + V_21 * V_34 + V_13 * V_32 ;
V_22 = F_18 ( V_30 , V_30 + V_32 , V_33 , V_16 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_1 , V_22 ) ;
goto V_35;
}
}
return V_20 ;
V_35:
F_20 ( V_20 -> V_27 -> V_31 ) ;
free:
F_21 ( V_20 ) ;
return F_15 ( V_22 ) ;
}
static int F_22 ( struct V_36 * V_20 )
{
struct V_37 * V_38 = F_23 ( V_20 ) ;
struct V_4 * V_5 = F_24 ( V_38 ) ;
struct V_12 * V_39 ;
V_39 = F_12 ( V_5 , V_20 -> V_40 ) ;
if ( F_25 ( V_39 ) )
return F_26 ( V_39 ) ;
F_27 ( & V_39 -> V_25 , & V_5 -> V_41 ) ;
return 0 ;
}
static void F_28 ( struct V_36 * V_42 )
{
struct V_37 * V_38 = F_23 ( V_42 ) ;
struct V_4 * V_5 = F_24 ( V_38 ) ;
struct V_12 * V_20 , * V_43 ;
F_29 (bus, tmp, &pcie->buses, list) {
if ( V_20 -> V_26 == V_42 -> V_40 ) {
F_20 ( V_20 -> V_27 -> V_31 ) ;
F_30 ( & V_20 -> V_25 ) ;
F_21 ( V_20 ) ;
break;
}
}
}
static void T_4 * F_31 ( struct V_36 * V_20 ,
unsigned int V_10 ,
int V_11 )
{
struct V_37 * V_38 = F_23 ( V_20 ) ;
struct V_4 * V_5 = F_24 ( V_38 ) ;
struct V_14 * V_15 = V_5 -> V_15 ;
void T_4 * V_31 = NULL ;
if ( V_20 -> V_40 == 0 ) {
unsigned int V_44 = F_10 ( V_10 ) ;
struct V_45 * V_46 ;
F_32 (port, &pcie->ports, list) {
if ( V_46 -> V_47 + 1 == V_44 ) {
V_31 = V_46 -> V_48 + ( V_11 & ~ 3 ) ;
break;
}
}
} else {
struct V_12 * V_39 ;
F_32 (b, &pcie->buses, list)
if ( V_39 -> V_26 == V_20 -> V_40 )
V_31 = ( void T_4 * ) V_39 -> V_27 -> V_31 ;
if ( ! V_31 ) {
F_19 ( V_15 , L_2 ,
V_20 -> V_40 ) ;
return NULL ;
}
V_31 += F_9 ( V_10 , V_11 ) ;
}
return V_31 ;
}
static unsigned long F_33 ( struct V_45 * V_46 )
{
unsigned long V_49 = 0 ;
switch ( V_46 -> V_47 ) {
case 0 :
V_49 = V_50 ;
break;
case 1 :
V_49 = V_51 ;
break;
case 2 :
V_49 = V_52 ;
break;
}
return V_49 ;
}
static void F_34 ( struct V_45 * V_46 )
{
unsigned long V_53 = F_33 ( V_46 ) ;
unsigned long V_6 ;
V_6 = F_5 ( V_46 -> V_5 , V_53 ) ;
V_6 &= ~ V_54 ;
F_3 ( V_46 -> V_5 , V_6 , V_53 ) ;
F_35 ( 1000 , 2000 ) ;
V_6 = F_5 ( V_46 -> V_5 , V_53 ) ;
V_6 |= V_54 ;
F_3 ( V_46 -> V_5 , V_6 , V_53 ) ;
}
static void F_36 ( struct V_45 * V_46 )
{
unsigned long V_53 = F_33 ( V_46 ) ;
const struct V_55 * V_56 = V_46 -> V_5 -> V_56 ;
unsigned long V_6 ;
V_6 = F_5 ( V_46 -> V_5 , V_53 ) ;
V_6 |= V_57 ;
if ( V_56 -> V_58 )
V_6 |= V_59 ;
V_6 |= V_60 ;
F_3 ( V_46 -> V_5 , V_6 , V_53 ) ;
F_34 ( V_46 ) ;
if ( V_56 -> V_61 ) {
V_6 = F_6 ( V_46 -> V_48 + V_62 ) ;
V_6 |= V_63 ;
F_4 ( V_6 , V_46 -> V_48 + V_62 ) ;
}
}
static void F_37 ( struct V_45 * V_46 )
{
unsigned long V_53 = F_33 ( V_46 ) ;
const struct V_55 * V_56 = V_46 -> V_5 -> V_56 ;
unsigned long V_6 ;
V_6 = F_5 ( V_46 -> V_5 , V_53 ) ;
V_6 &= ~ V_54 ;
F_3 ( V_46 -> V_5 , V_6 , V_53 ) ;
V_6 = F_5 ( V_46 -> V_5 , V_53 ) ;
if ( V_56 -> V_58 )
V_6 &= ~ V_59 ;
V_6 &= ~ V_57 ;
F_3 ( V_46 -> V_5 , V_6 , V_53 ) ;
}
static void F_38 ( struct V_45 * V_46 )
{
struct V_4 * V_5 = V_46 -> V_5 ;
struct V_14 * V_15 = V_5 -> V_15 ;
F_39 ( V_15 , V_46 -> V_48 ) ;
F_40 ( V_15 , V_46 -> V_64 . V_19 ,
F_41 ( & V_46 -> V_64 ) ) ;
F_30 ( & V_46 -> V_25 ) ;
F_42 ( V_15 , V_46 ) ;
}
static void F_43 ( struct V_65 * V_15 )
{
V_15 -> V_66 = V_67 << 8 ;
}
static void F_44 ( struct V_65 * V_15 )
{
F_45 ( V_15 , V_68 , V_69 ) ;
}
static int F_46 ( struct V_4 * V_5 )
{
struct V_37 * V_38 = F_47 ( V_5 ) ;
struct V_70 * V_71 = & V_38 -> V_71 ;
struct V_14 * V_15 = V_5 -> V_15 ;
int V_22 ;
F_48 ( V_71 , & V_5 -> V_72 , V_5 -> V_7 . V_73 ) ;
F_48 ( V_71 , & V_5 -> V_74 , V_5 -> V_7 . V_74 ) ;
F_48 ( V_71 , & V_5 -> V_75 , V_5 -> V_7 . V_74 ) ;
F_49 ( V_71 , & V_5 -> V_76 ) ;
V_22 = F_50 ( V_15 , V_71 ) ;
if ( V_22 < 0 )
return V_22 ;
F_51 ( & V_5 -> V_72 , V_5 -> V_73 . V_19 ) ;
return 0 ;
}
static int F_52 ( const struct V_65 * V_77 , T_5 V_44 , T_5 V_78 )
{
struct V_37 * V_38 = F_23 ( V_77 -> V_20 ) ;
struct V_4 * V_5 = F_24 ( V_38 ) ;
int V_79 ;
F_53 () ;
V_79 = F_54 ( V_77 , V_44 , V_78 ) ;
if ( ! V_79 )
V_79 = V_5 -> V_79 ;
return V_79 ;
}
static T_6 F_55 ( int V_79 , void * V_80 )
{
const char * V_81 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
} ;
struct V_4 * V_5 = V_80 ;
struct V_14 * V_15 = V_5 -> V_15 ;
T_1 V_82 , V_83 ;
V_82 = F_5 ( V_5 , V_84 ) & V_85 ;
V_83 = F_5 ( V_5 , V_86 ) ;
F_3 ( V_5 , 0 , V_84 ) ;
if ( V_82 == V_87 )
return V_88 ;
if ( V_82 >= F_56 ( V_81 ) )
V_82 = 0 ;
if ( V_82 == V_89 )
F_57 ( V_15 , L_18 , V_81 [ V_82 ] , V_83 ) ;
else
F_19 ( V_15 , L_18 , V_81 [ V_82 ] , V_83 ) ;
if ( V_82 == V_90 || V_82 == V_89 ||
V_82 == V_91 ) {
T_1 V_92 = F_5 ( V_5 , V_93 ) & 0xff ;
T_7 V_94 = ( T_7 ) V_92 << 32 | ( V_83 & 0xfffffffc ) ;
if ( V_82 == V_89 )
F_57 ( V_15 , L_19 , V_94 ) ;
else
F_19 ( V_15 , L_19 , V_94 ) ;
}
return V_95 ;
}
static void F_58 ( struct V_4 * V_5 )
{
T_1 V_96 , V_97 , V_98 ;
V_96 = 0xfe100000 ;
V_97 = F_41 ( V_5 -> V_18 ) ;
V_98 = V_5 -> V_18 -> V_19 ;
F_3 ( V_5 , V_98 , V_99 ) ;
F_3 ( V_5 , V_97 >> 12 , V_100 ) ;
F_3 ( V_5 , V_96 , V_101 ) ;
V_96 = 0xfdfc0000 ;
V_97 = F_41 ( & V_5 -> V_73 ) ;
V_98 = V_5 -> V_73 . V_19 ;
F_3 ( V_5 , V_98 , V_102 ) ;
F_3 ( V_5 , V_97 >> 12 , V_103 ) ;
F_3 ( V_5 , V_96 , V_104 ) ;
V_96 = ( ( ( V_5 -> V_75 . V_19 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_97 = F_41 ( & V_5 -> V_75 ) ;
V_98 = V_5 -> V_75 . V_19 ;
F_3 ( V_5 , V_98 , V_105 ) ;
F_3 ( V_5 , V_97 >> 12 , V_106 ) ;
F_3 ( V_5 , V_96 , V_107 ) ;
V_96 = ( ( ( V_5 -> V_74 . V_19 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_97 = F_41 ( & V_5 -> V_74 ) ;
V_98 = V_5 -> V_74 . V_19 ;
F_3 ( V_5 , V_98 , V_108 ) ;
F_3 ( V_5 , V_97 >> 12 , V_109 ) ;
F_3 ( V_5 , V_96 , V_110 ) ;
F_3 ( V_5 , 0 , V_111 ) ;
F_3 ( V_5 , 0 , V_112 ) ;
F_3 ( V_5 , 0 , V_113 ) ;
F_3 ( V_5 , 0 , V_114 ) ;
F_3 ( V_5 , 0 , V_115 ) ;
F_3 ( V_5 , 0 , V_116 ) ;
F_3 ( V_5 , 0 , V_117 ) ;
F_3 ( V_5 , 0 , V_118 ) ;
F_3 ( V_5 , 0 , V_119 ) ;
F_3 ( V_5 , 0 , V_120 ) ;
F_3 ( V_5 , 0 , V_121 ) ;
F_3 ( V_5 , 0 , V_122 ) ;
F_3 ( V_5 , 0 , V_123 ) ;
F_3 ( V_5 , 0 , V_122 ) ;
}
static int F_59 ( struct V_4 * V_5 , unsigned long V_124 )
{
const struct V_55 * V_56 = V_5 -> V_56 ;
T_1 V_6 ;
V_124 = V_125 + F_60 ( V_124 ) ;
while ( F_61 ( V_125 , V_124 ) ) {
V_6 = F_8 ( V_5 , V_56 -> V_126 ) ;
if ( V_6 & V_127 )
return 0 ;
}
return - V_128 ;
}
static int F_62 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
const struct V_55 * V_56 = V_5 -> V_56 ;
T_1 V_6 ;
int V_22 ;
F_7 ( V_5 , 0x0 , V_129 ) ;
V_6 = F_8 ( V_5 , V_130 ) ;
V_6 |= V_131 ;
F_7 ( V_5 , V_6 , V_130 ) ;
V_6 = F_8 ( V_5 , V_56 -> V_126 ) ;
V_6 &= ~ ( V_132 | V_133 ) ;
V_6 |= V_134 | V_56 -> V_135 ;
F_7 ( V_5 , V_6 , V_56 -> V_126 ) ;
V_6 = F_8 ( V_5 , V_56 -> V_126 ) ;
V_6 &= ~ V_136 ;
F_7 ( V_5 , V_6 , V_56 -> V_126 ) ;
F_35 ( 20 , 100 ) ;
V_6 = F_8 ( V_5 , V_56 -> V_126 ) ;
V_6 |= V_136 ;
F_7 ( V_5 , V_6 , V_56 -> V_126 ) ;
V_22 = F_59 ( V_5 , 500 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_20 , V_22 ) ;
return V_22 ;
}
V_6 = F_8 ( V_5 , V_130 ) ;
V_6 &= ~ V_131 ;
F_7 ( V_5 , V_6 , V_130 ) ;
V_6 = F_8 ( V_5 , V_130 ) ;
V_6 |= V_137 | V_138 ;
F_7 ( V_5 , V_6 , V_130 ) ;
return 0 ;
}
static int F_63 ( struct V_4 * V_5 )
{
const struct V_55 * V_56 = V_5 -> V_56 ;
T_1 V_6 ;
V_6 = F_8 ( V_5 , V_130 ) ;
V_6 &= ~ ( V_137 | V_138 ) ;
F_7 ( V_5 , V_6 , V_130 ) ;
V_6 = F_8 ( V_5 , V_130 ) ;
V_6 |= V_131 ;
F_7 ( V_5 , V_6 , V_130 ) ;
V_6 = F_8 ( V_5 , V_56 -> V_126 ) ;
V_6 &= ~ V_136 ;
F_7 ( V_5 , V_6 , V_56 -> V_126 ) ;
F_35 ( 20 , 100 ) ;
return 0 ;
}
static int F_64 ( struct V_45 * V_46 )
{
struct V_14 * V_15 = V_46 -> V_5 -> V_15 ;
unsigned int V_21 ;
int V_22 ;
for ( V_21 = 0 ; V_21 < V_46 -> V_139 ; V_21 ++ ) {
V_22 = F_65 ( V_46 -> V_33 [ V_21 ] ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_21 , V_21 , V_22 ) ;
return V_22 ;
}
}
return 0 ;
}
static int F_66 ( struct V_45 * V_46 )
{
struct V_14 * V_15 = V_46 -> V_5 -> V_15 ;
unsigned int V_21 ;
int V_22 ;
for ( V_21 = 0 ; V_21 < V_46 -> V_139 ; V_21 ++ ) {
V_22 = F_67 ( V_46 -> V_33 [ V_21 ] ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_22 , V_21 ,
V_22 ) ;
return V_22 ;
}
}
return 0 ;
}
static int F_68 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
const struct V_55 * V_56 = V_5 -> V_56 ;
struct V_45 * V_46 ;
int V_22 ;
if ( V_5 -> V_140 ) {
if ( V_5 -> V_141 )
V_22 = F_65 ( V_5 -> V_141 ) ;
else
V_22 = F_62 ( V_5 ) ;
if ( V_22 < 0 )
F_19 ( V_15 , L_23 , V_22 ) ;
return V_22 ;
}
F_32 (port, &pcie->ports, list) {
V_22 = F_64 ( V_46 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 ,
L_24 ,
V_46 -> V_47 , V_22 ) ;
return V_22 ;
}
}
F_7 ( V_5 , V_56 -> V_142 , V_143 ) ;
if ( V_56 -> V_144 > 2 )
F_7 ( V_5 , V_56 -> V_145 , V_146 ) ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_45 * V_46 ;
int V_22 ;
if ( V_5 -> V_140 ) {
if ( V_5 -> V_141 )
V_22 = F_67 ( V_5 -> V_141 ) ;
else
V_22 = F_63 ( V_5 ) ;
if ( V_22 < 0 )
F_19 ( V_15 , L_25 , V_22 ) ;
return V_22 ;
}
F_32 (port, &pcie->ports, list) {
V_22 = F_66 ( V_46 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 ,
L_26 ,
V_46 -> V_47 , V_22 ) ;
return V_22 ;
}
}
return 0 ;
}
static int F_70 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
const struct V_55 * V_56 = V_5 -> V_56 ;
struct V_45 * V_46 ;
unsigned long V_6 ;
int V_22 ;
if ( V_5 -> V_141 ) {
V_6 = F_5 ( V_5 , V_147 ) ;
V_6 &= ~ V_148 ;
V_6 |= V_149 ;
F_3 ( V_5 , V_6 , V_147 ) ;
}
if ( V_56 -> V_150 )
F_3 ( V_5 , 0 , V_151 ) ;
V_6 = F_5 ( V_5 , V_152 ) ;
V_6 &= ~ V_153 ;
V_6 |= V_154 | V_5 -> V_155 ;
F_32 (port, &pcie->ports, list)
V_6 &= ~ F_71 ( V_46 -> V_47 ) ;
F_3 ( V_5 , V_6 , V_152 ) ;
if ( V_56 -> V_156 ) {
V_6 = F_5 ( V_5 , V_157 ) ;
V_6 &= ~ V_158 ;
F_3 ( V_5 , V_6 , V_157 ) ;
} else {
V_6 = F_5 ( V_5 , V_157 ) ;
V_6 |= V_158 ;
F_3 ( V_5 , V_6 , V_157 ) ;
}
V_22 = F_68 ( V_5 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_27 , V_22 ) ;
return V_22 ;
}
F_72 ( V_5 -> V_159 ) ;
V_6 = F_5 ( V_5 , V_160 ) ;
V_6 |= V_161 ;
F_3 ( V_5 , V_6 , V_160 ) ;
V_6 = V_162 | V_163 |
V_164 | V_165 |
V_166 | V_167 ;
if ( V_56 -> V_168 )
V_6 |= V_169 ;
F_3 ( V_5 , V_6 , V_170 ) ;
F_3 ( V_5 , 0xffffffff , V_171 ) ;
F_3 ( V_5 , V_172 , V_173 ) ;
F_3 ( V_5 , 0 , V_174 ) ;
return 0 ;
}
static void F_73 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
int V_22 ;
V_22 = F_69 ( V_5 ) ;
if ( V_22 < 0 )
F_19 ( V_15 , L_28 , V_22 ) ;
F_74 ( V_5 -> V_159 ) ;
F_74 ( V_5 -> V_175 ) ;
F_74 ( V_5 -> V_176 ) ;
F_75 ( V_177 ) ;
V_22 = F_76 ( V_5 -> V_178 , V_5 -> V_179 ) ;
if ( V_22 < 0 )
F_77 ( V_15 , L_29 , V_22 ) ;
}
static int F_78 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
const struct V_55 * V_56 = V_5 -> V_56 ;
int V_22 ;
F_74 ( V_5 -> V_159 ) ;
F_74 ( V_5 -> V_175 ) ;
F_74 ( V_5 -> V_176 ) ;
F_75 ( V_177 ) ;
V_22 = F_79 ( V_5 -> V_178 , V_5 -> V_179 ) ;
if ( V_22 < 0 )
F_19 ( V_15 , L_30 , V_22 ) ;
V_22 = F_80 ( V_177 ,
V_5 -> V_180 ,
V_5 -> V_176 ) ;
if ( V_22 ) {
F_19 ( V_15 , L_31 , V_22 ) ;
return V_22 ;
}
F_72 ( V_5 -> V_175 ) ;
V_22 = F_81 ( V_5 -> V_181 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_32 , V_22 ) ;
return V_22 ;
}
if ( V_56 -> V_182 ) {
V_22 = F_81 ( V_5 -> V_183 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_33 , V_22 ) ;
return V_22 ;
}
}
V_22 = F_81 ( V_5 -> V_184 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_34 , V_22 ) ;
return V_22 ;
}
return 0 ;
}
static int F_82 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
const struct V_55 * V_56 = V_5 -> V_56 ;
V_5 -> V_180 = F_83 ( V_15 , L_35 ) ;
if ( F_25 ( V_5 -> V_180 ) )
return F_26 ( V_5 -> V_180 ) ;
V_5 -> V_181 = F_83 ( V_15 , L_36 ) ;
if ( F_25 ( V_5 -> V_181 ) )
return F_26 ( V_5 -> V_181 ) ;
V_5 -> V_184 = F_83 ( V_15 , L_37 ) ;
if ( F_25 ( V_5 -> V_184 ) )
return F_26 ( V_5 -> V_184 ) ;
if ( V_56 -> V_182 ) {
V_5 -> V_183 = F_83 ( V_15 , L_38 ) ;
if ( F_25 ( V_5 -> V_183 ) )
return F_26 ( V_5 -> V_183 ) ;
}
return 0 ;
}
static int F_84 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
V_5 -> V_176 = F_85 ( V_15 , L_35 ) ;
if ( F_25 ( V_5 -> V_176 ) )
return F_26 ( V_5 -> V_176 ) ;
V_5 -> V_175 = F_85 ( V_15 , L_36 ) ;
if ( F_25 ( V_5 -> V_175 ) )
return F_26 ( V_5 -> V_175 ) ;
V_5 -> V_159 = F_85 ( V_15 , L_39 ) ;
if ( F_25 ( V_5 -> V_159 ) )
return F_26 ( V_5 -> V_159 ) ;
return 0 ;
}
static int F_86 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
int V_22 ;
V_5 -> V_141 = F_87 ( V_15 , L_40 ) ;
if ( F_25 ( V_5 -> V_141 ) ) {
V_22 = F_26 ( V_5 -> V_141 ) ;
F_19 ( V_15 , L_41 , V_22 ) ;
return V_22 ;
}
V_22 = F_88 ( V_5 -> V_141 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_42 , V_22 ) ;
return V_22 ;
}
V_5 -> V_140 = true ;
return 0 ;
}
static struct V_141 * F_89 ( struct V_14 * V_15 ,
struct V_185 * V_186 ,
const char * V_187 ,
unsigned int V_47 )
{
struct V_141 * V_141 ;
char * V_188 ;
V_188 = F_90 ( V_23 , L_43 , V_187 , V_47 ) ;
if ( ! V_188 )
return F_15 ( - V_24 ) ;
V_141 = F_91 ( V_15 , V_186 , V_188 ) ;
F_21 ( V_188 ) ;
if ( F_25 ( V_141 ) && F_26 ( V_141 ) == - V_189 )
V_141 = NULL ;
return V_141 ;
}
static int F_92 ( struct V_45 * V_46 )
{
struct V_14 * V_15 = V_46 -> V_5 -> V_15 ;
struct V_141 * V_141 ;
unsigned int V_21 ;
int V_22 ;
V_46 -> V_33 = F_93 ( V_15 , sizeof( V_141 ) , V_46 -> V_139 , V_23 ) ;
if ( ! V_46 -> V_33 )
return - V_24 ;
for ( V_21 = 0 ; V_21 < V_46 -> V_139 ; V_21 ++ ) {
V_141 = F_89 ( V_15 , V_46 -> V_186 , L_40 , V_21 ) ;
if ( F_25 ( V_141 ) ) {
F_19 ( V_15 , L_44 , V_21 ,
F_26 ( V_141 ) ) ;
return F_26 ( V_141 ) ;
}
V_22 = F_88 ( V_141 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_45 , V_21 ,
V_22 ) ;
return V_22 ;
}
V_46 -> V_33 [ V_21 ] = V_141 ;
}
return 0 ;
}
static int F_94 ( struct V_4 * V_5 )
{
const struct V_55 * V_56 = V_5 -> V_56 ;
struct V_185 * V_186 = V_5 -> V_15 -> V_190 ;
struct V_45 * V_46 ;
int V_22 ;
if ( ! V_56 -> V_156 || F_95 ( V_186 , L_46 , NULL ) != NULL )
return F_86 ( V_5 ) ;
F_32 (port, &pcie->ports, list) {
V_22 = F_92 ( V_46 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
static int F_96 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_191 * V_77 = F_97 ( V_15 ) ;
struct V_192 * V_9 , * V_8 , * V_193 ;
int V_22 ;
V_22 = F_82 ( V_5 ) ;
if ( V_22 ) {
F_19 ( V_15 , L_47 , V_22 ) ;
return V_22 ;
}
V_22 = F_84 ( V_5 ) ;
if ( V_22 ) {
F_19 ( V_15 , L_48 , V_22 ) ;
return V_22 ;
}
V_22 = F_94 ( V_5 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_49 , V_22 ) ;
return V_22 ;
}
V_22 = F_78 ( V_5 ) ;
if ( V_22 ) {
F_19 ( V_15 , L_50 , V_22 ) ;
return V_22 ;
}
V_9 = F_98 ( V_77 , V_194 , L_51 ) ;
V_5 -> V_9 = F_99 ( V_15 , V_9 ) ;
if ( F_25 ( V_5 -> V_9 ) ) {
V_22 = F_26 ( V_5 -> V_9 ) ;
goto V_195;
}
V_8 = F_98 ( V_77 , V_194 , L_36 ) ;
V_5 -> V_8 = F_99 ( V_15 , V_8 ) ;
if ( F_25 ( V_5 -> V_8 ) ) {
V_22 = F_26 ( V_5 -> V_8 ) ;
goto V_195;
}
V_193 = F_98 ( V_77 , V_194 , L_52 ) ;
if ( ! V_193 ) {
V_22 = - V_196 ;
goto V_195;
}
V_5 -> V_18 = F_100 ( V_15 , V_193 -> V_19 ,
F_41 ( V_193 ) , V_193 -> V_188 ) ;
if ( ! V_5 -> V_18 ) {
V_22 = - V_196 ;
goto V_195;
}
V_22 = F_101 ( V_77 , L_53 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_54 , V_22 ) ;
goto V_195;
}
V_5 -> V_79 = V_22 ;
V_22 = F_102 ( V_5 -> V_79 , F_55 , V_197 , L_55 , V_5 ) ;
if ( V_22 ) {
F_19 ( V_15 , L_56 , V_22 ) ;
goto V_195;
}
return 0 ;
V_195:
F_73 ( V_5 ) ;
return V_22 ;
}
static int F_103 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
int V_22 ;
if ( V_5 -> V_79 > 0 )
F_104 ( V_5 -> V_79 , V_5 ) ;
F_73 ( V_5 ) ;
V_22 = F_105 ( V_5 -> V_141 ) ;
if ( V_22 < 0 )
F_19 ( V_15 , L_57 , V_22 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_3 )
{
int V_198 ;
F_107 ( & V_3 -> V_199 ) ;
V_198 = F_108 ( V_3 -> V_200 , V_201 ) ;
if ( V_198 < V_201 )
F_109 ( V_198 , V_3 -> V_200 ) ;
else
V_198 = - V_202 ;
F_110 ( & V_3 -> V_199 ) ;
return V_198 ;
}
static void F_111 ( struct V_1 * V_3 , unsigned long V_79 )
{
struct V_14 * V_15 = V_3 -> V_3 . V_15 ;
F_107 ( & V_3 -> V_199 ) ;
if ( ! F_112 ( V_79 , V_3 -> V_200 ) )
F_19 ( V_15 , L_58 , V_79 ) ;
else
F_113 ( V_79 , V_3 -> V_200 ) ;
F_110 ( & V_3 -> V_199 ) ;
}
static T_6 F_114 ( int V_79 , void * V_203 )
{
struct V_4 * V_5 = V_203 ;
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_1 * V_198 = & V_5 -> V_198 ;
unsigned int V_21 , V_204 = 0 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
unsigned long V_205 = F_5 ( V_5 , V_206 + V_21 * 4 ) ;
while ( V_205 ) {
unsigned int V_7 = F_115 ( & V_205 , 32 ) ;
unsigned int V_47 = V_21 * 32 + V_7 ;
unsigned int V_79 ;
F_3 ( V_5 , 1 << V_7 , V_206 + V_21 * 4 ) ;
V_79 = F_116 ( V_198 -> V_207 , V_47 ) ;
if ( V_79 ) {
if ( F_112 ( V_47 , V_198 -> V_200 ) )
F_117 ( V_79 ) ;
else
F_118 ( V_15 , L_59 ) ;
} else {
F_118 ( V_15 , L_60 ) ;
}
V_205 = F_5 ( V_5 , V_206 + V_21 * 4 ) ;
V_204 ++ ;
}
}
return V_204 > 0 ? V_95 : V_88 ;
}
static int F_119 ( struct V_2 * V_3 ,
struct V_65 * V_77 , struct V_208 * V_209 )
{
struct V_1 * V_198 = F_1 ( V_3 ) ;
struct V_210 V_211 ;
unsigned int V_79 ;
int V_212 ;
V_212 = F_106 ( V_198 ) ;
if ( V_212 < 0 )
return V_212 ;
V_79 = F_120 ( V_198 -> V_207 , V_212 ) ;
if ( ! V_79 ) {
F_111 ( V_198 , V_212 ) ;
return - V_213 ;
}
F_121 ( V_79 , V_209 ) ;
V_211 . V_214 = F_122 ( V_198 -> V_33 ) ;
V_211 . V_215 = F_123 ( V_198 -> V_33 ) ;
V_211 . V_203 = V_212 ;
F_124 ( V_79 , & V_211 ) ;
return 0 ;
}
static void F_125 ( struct V_2 * V_3 ,
unsigned int V_79 )
{
struct V_1 * V_198 = F_1 ( V_3 ) ;
struct V_216 * V_217 = F_126 ( V_79 ) ;
T_8 V_212 = F_127 ( V_217 ) ;
F_128 ( V_79 ) ;
F_111 ( V_198 , V_212 ) ;
}
static int F_129 ( struct V_218 * V_207 , unsigned int V_79 ,
T_8 V_212 )
{
F_130 ( V_79 , & V_219 , V_220 ) ;
F_131 ( V_79 , V_207 -> V_221 ) ;
F_53 () ;
return 0 ;
}
static int F_132 ( struct V_4 * V_5 )
{
struct V_37 * V_38 = F_47 ( V_5 ) ;
struct V_191 * V_77 = F_97 ( V_5 -> V_15 ) ;
const struct V_55 * V_56 = V_5 -> V_56 ;
struct V_1 * V_198 = & V_5 -> V_198 ;
struct V_14 * V_15 = V_5 -> V_15 ;
int V_22 ;
T_1 V_205 ;
F_133 ( & V_198 -> V_199 ) ;
V_198 -> V_3 . V_15 = V_15 ;
V_198 -> V_3 . V_222 = F_119 ;
V_198 -> V_3 . V_223 = F_125 ;
V_198 -> V_207 = F_134 ( V_15 -> V_190 , V_201 ,
& V_224 , & V_198 -> V_3 ) ;
if ( ! V_198 -> V_207 ) {
F_19 ( V_15 , L_61 ) ;
return - V_24 ;
}
V_22 = F_101 ( V_77 , L_62 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_54 , V_22 ) ;
goto V_22;
}
V_198 -> V_79 = V_22 ;
V_22 = F_102 ( V_198 -> V_79 , F_114 , V_225 ,
V_219 . V_188 , V_5 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_63 , V_22 ) ;
goto V_22;
}
V_198 -> V_226 = F_135 ( V_23 , 0 ) ;
V_198 -> V_33 = F_136 ( ( void * ) V_198 -> V_226 ) ;
F_3 ( V_5 , V_198 -> V_33 >> V_56 -> V_227 , V_121 ) ;
F_3 ( V_5 , V_198 -> V_33 , V_123 ) ;
F_3 ( V_5 , 1 , V_122 ) ;
F_3 ( V_5 , 0xffffffff , V_228 ) ;
F_3 ( V_5 , 0xffffffff , V_229 ) ;
F_3 ( V_5 , 0xffffffff , V_230 ) ;
F_3 ( V_5 , 0xffffffff , V_231 ) ;
F_3 ( V_5 , 0xffffffff , V_232 ) ;
F_3 ( V_5 , 0xffffffff , V_233 ) ;
F_3 ( V_5 , 0xffffffff , V_234 ) ;
F_3 ( V_5 , 0xffffffff , V_235 ) ;
V_205 = F_5 ( V_5 , V_173 ) ;
V_205 |= V_236 ;
F_3 ( V_5 , V_205 , V_173 ) ;
V_38 -> V_198 = & V_198 -> V_3 ;
return 0 ;
V_22:
F_137 ( V_198 -> V_207 ) ;
return V_22 ;
}
static int F_138 ( struct V_4 * V_5 )
{
struct V_1 * V_198 = & V_5 -> V_198 ;
unsigned int V_21 , V_79 ;
T_1 V_6 ;
V_6 = F_5 ( V_5 , V_173 ) ;
V_6 &= ~ V_236 ;
F_3 ( V_5 , V_6 , V_173 ) ;
F_3 ( V_5 , 0 , V_228 ) ;
F_3 ( V_5 , 0 , V_229 ) ;
F_3 ( V_5 , 0 , V_230 ) ;
F_3 ( V_5 , 0 , V_231 ) ;
F_3 ( V_5 , 0 , V_232 ) ;
F_3 ( V_5 , 0 , V_233 ) ;
F_3 ( V_5 , 0 , V_234 ) ;
F_3 ( V_5 , 0 , V_235 ) ;
F_139 ( V_198 -> V_226 , 0 ) ;
if ( V_198 -> V_79 > 0 )
F_104 ( V_198 -> V_79 , V_5 ) ;
for ( V_21 = 0 ; V_21 < V_201 ; V_21 ++ ) {
V_79 = F_116 ( V_198 -> V_207 , V_21 ) ;
if ( V_79 > 0 )
F_128 ( V_79 ) ;
}
F_137 ( V_198 -> V_207 ) ;
return 0 ;
}
static int F_140 ( struct V_4 * V_5 , T_1 V_139 ,
T_1 * V_237 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_185 * V_186 = V_15 -> V_190 ;
if ( F_141 ( V_186 , L_64 ) ||
F_141 ( V_186 , L_65 ) ) {
switch ( V_139 ) {
case 0x0000104 :
F_118 ( V_15 , L_66 ) ;
* V_237 = V_238 ;
return 0 ;
case 0x0000102 :
F_118 ( V_15 , L_67 ) ;
* V_237 = V_239 ;
return 0 ;
}
} else if ( F_141 ( V_186 , L_68 ) ) {
switch ( V_139 ) {
case 0x00000204 :
F_118 ( V_15 , L_69 ) ;
* V_237 = V_240 ;
return 0 ;
case 0x00020202 :
F_118 ( V_15 , L_70 ) ;
* V_237 = V_241 ;
return 0 ;
case 0x00010104 :
F_118 ( V_15 , L_71 ) ;
* V_237 = V_242 ;
return 0 ;
}
} else if ( F_141 ( V_186 , L_72 ) ) {
switch ( V_139 ) {
case 0x00000004 :
F_118 ( V_15 , L_73 ) ;
* V_237 = V_243 ;
return 0 ;
case 0x00000202 :
F_118 ( V_15 , L_74 ) ;
* V_237 = V_244 ;
return 0 ;
}
}
return - V_213 ;
}
static bool F_142 ( struct V_185 * V_186 ,
struct V_245 * V_179 ,
unsigned int V_178 )
{
char V_246 [ 32 ] ;
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < V_178 ; V_21 ++ ) {
snprintf ( V_246 , 32 , L_75 , V_179 [ V_21 ] . V_247 ) ;
if ( F_95 ( V_186 , V_246 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_143 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_185 * V_186 = V_15 -> V_190 ;
if ( F_141 ( V_186 , L_68 ) )
V_5 -> V_178 = 3 ;
else if ( F_141 ( V_186 , L_72 ) )
V_5 -> V_178 = 2 ;
if ( V_5 -> V_178 == 0 ) {
F_19 ( V_15 , L_76 , V_186 ) ;
return - V_189 ;
}
V_5 -> V_179 = F_93 ( V_15 , V_5 -> V_178 ,
sizeof( * V_5 -> V_179 ) ,
V_23 ) ;
if ( ! V_5 -> V_179 )
return - V_24 ;
V_5 -> V_179 [ 0 ] . V_247 = L_77 ;
V_5 -> V_179 [ 1 ] . V_247 = L_78 ;
if ( V_5 -> V_178 > 2 )
V_5 -> V_179 [ 2 ] . V_247 = L_79 ;
return F_144 ( V_15 , V_5 -> V_178 , V_5 -> V_179 ) ;
}
static int F_145 ( struct V_4 * V_5 , T_1 V_248 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_185 * V_186 = V_15 -> V_190 ;
unsigned int V_21 = 0 ;
if ( F_141 ( V_186 , L_65 ) ) {
V_5 -> V_178 = 6 ;
V_5 -> V_179 = F_93 ( V_5 -> V_15 , V_5 -> V_178 ,
sizeof( * V_5 -> V_179 ) ,
V_23 ) ;
if ( ! V_5 -> V_179 )
return - V_24 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_80 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_81 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_82 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_83 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_84 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_85 ;
} else if ( F_141 ( V_186 , L_64 ) ) {
V_5 -> V_178 = 7 ;
V_5 -> V_179 = F_93 ( V_15 , V_5 -> V_178 ,
sizeof( * V_5 -> V_179 ) ,
V_23 ) ;
if ( ! V_5 -> V_179 )
return - V_24 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_86 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_82 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_87 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_88 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_84 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_85 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_89 ;
} else if ( F_141 ( V_186 , L_68 ) ) {
bool V_249 = false , V_250 = false ;
if ( V_248 & 0x0f )
V_249 = true ;
if ( V_248 & 0x30 )
V_250 = true ;
V_5 -> V_178 = 4 + ( V_249 ? 2 : 0 ) +
( V_250 ? 2 : 0 ) ;
V_5 -> V_179 = F_93 ( V_15 , V_5 -> V_178 ,
sizeof( * V_5 -> V_179 ) ,
V_23 ) ;
if ( ! V_5 -> V_179 )
return - V_24 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_87 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_88 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_85 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_90 ;
if ( V_249 ) {
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_91 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_92 ;
}
if ( V_250 ) {
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_93 ;
V_5 -> V_179 [ V_21 ++ ] . V_247 = L_94 ;
}
} else if ( F_141 ( V_186 , L_72 ) ) {
V_5 -> V_178 = 5 ;
V_5 -> V_179 = F_93 ( V_15 , V_5 -> V_178 ,
sizeof( * V_5 -> V_179 ) ,
V_23 ) ;
if ( ! V_5 -> V_179 )
return - V_24 ;
V_5 -> V_179 [ 0 ] . V_247 = L_95 ;
V_5 -> V_179 [ 1 ] . V_247 = L_96 ;
V_5 -> V_179 [ 2 ] . V_247 = L_87 ;
V_5 -> V_179 [ 3 ] . V_247 = L_90 ;
V_5 -> V_179 [ 4 ] . V_247 = L_97 ;
}
if ( F_142 ( V_15 -> V_190 , V_5 -> V_179 ,
V_5 -> V_178 ) )
return F_144 ( V_15 , V_5 -> V_178 ,
V_5 -> V_179 ) ;
F_118 ( V_15 , L_98 ) ;
F_42 ( V_15 , V_5 -> V_179 ) ;
V_5 -> V_178 = 0 ;
return F_143 ( V_5 ) ;
}
static int F_146 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_185 * V_186 = V_15 -> V_190 , * V_46 ;
const struct V_55 * V_56 = V_5 -> V_56 ;
struct V_251 V_252 ;
struct V_253 V_254 ;
T_1 V_139 = 0 , V_255 = 0 ;
unsigned int V_256 = 0 ;
struct V_192 V_193 ;
int V_22 ;
if ( F_147 ( & V_252 , V_186 ) ) {
F_19 ( V_15 , L_99 ) ;
return - V_213 ;
}
F_148 (&parser, &range) {
V_22 = F_149 ( & V_254 , V_186 , & V_193 ) ;
if ( V_22 < 0 )
return V_22 ;
switch ( V_193 . V_257 & V_258 ) {
case V_259 :
V_5 -> V_7 . V_73 = V_193 . V_19 - V_254 . V_260 ;
memcpy ( & V_5 -> V_72 , & V_193 , sizeof( V_193 ) ) ;
V_5 -> V_72 . V_188 = V_186 -> V_261 ;
V_5 -> V_73 . V_19 = V_254 . V_262 ;
V_5 -> V_73 . V_263 = V_254 . V_262 + V_254 . V_97 - 1 ;
V_5 -> V_73 . V_257 = V_194 ;
V_5 -> V_73 . V_188 = L_100 ;
memcpy ( & V_193 , & V_5 -> V_73 , sizeof( V_193 ) ) ;
break;
case V_194 :
V_5 -> V_7 . V_74 = V_193 . V_19 - V_254 . V_260 ;
if ( V_193 . V_257 & V_264 ) {
memcpy ( & V_5 -> V_75 , & V_193 , sizeof( V_193 ) ) ;
V_5 -> V_75 . V_188 = L_101 ;
} else {
memcpy ( & V_5 -> V_74 , & V_193 , sizeof( V_193 ) ) ;
V_5 -> V_74 . V_188 = L_102 ;
}
break;
}
}
V_22 = F_150 ( V_186 , & V_5 -> V_76 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_103 , V_22 ) ;
V_5 -> V_76 . V_188 = V_186 -> V_188 ;
V_5 -> V_76 . V_19 = 0 ;
V_5 -> V_76 . V_263 = 0xff ;
V_5 -> V_76 . V_257 = V_265 ;
}
F_151 (np, port) {
struct V_45 * V_266 ;
unsigned int V_47 ;
T_1 V_6 ;
V_22 = F_152 ( V_46 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_104 , V_22 ) ;
return V_22 ;
}
V_47 = F_10 ( V_22 ) ;
if ( V_47 < 1 || V_47 > V_56 -> V_144 ) {
F_19 ( V_15 , L_105 , V_47 ) ;
return - V_213 ;
}
V_47 -- ;
V_22 = F_153 ( V_46 , L_106 , & V_6 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_107 ,
V_22 ) ;
return V_22 ;
}
if ( V_6 > 16 ) {
F_19 ( V_15 , L_108 , V_6 ) ;
return - V_213 ;
}
V_139 |= V_6 << ( V_47 << 3 ) ;
if ( ! F_154 ( V_46 ) ) {
V_256 += V_6 ;
continue;
}
V_255 |= ( ( 1 << V_6 ) - 1 ) << V_256 ;
V_256 += V_6 ;
V_266 = F_155 ( V_15 , sizeof( * V_266 ) , V_23 ) ;
if ( ! V_266 )
return - V_24 ;
V_22 = F_156 ( V_46 , 0 , & V_266 -> V_64 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_104 , V_22 ) ;
return V_22 ;
}
F_16 ( & V_266 -> V_25 ) ;
V_266 -> V_47 = V_47 ;
V_266 -> V_139 = V_6 ;
V_266 -> V_5 = V_5 ;
V_266 -> V_186 = V_46 ;
V_266 -> V_48 = F_157 ( V_15 , & V_266 -> V_64 ) ;
if ( F_25 ( V_266 -> V_48 ) )
return F_26 ( V_266 -> V_48 ) ;
F_27 ( & V_266 -> V_25 , & V_5 -> V_267 ) ;
}
V_22 = F_140 ( V_5 , V_139 , & V_5 -> V_155 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_109 ) ;
return V_22 ;
}
V_22 = F_145 ( V_5 , V_255 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
}
static bool F_158 ( struct V_45 * V_46 )
{
struct V_14 * V_15 = V_46 -> V_5 -> V_15 ;
unsigned int V_268 = 3 ;
unsigned long V_6 ;
V_6 = F_6 ( V_46 -> V_48 + V_269 ) ;
V_6 &= ~ V_270 ;
V_6 |= V_271 ;
F_4 ( V_6 , V_46 -> V_48 + V_269 ) ;
do {
unsigned int V_124 = V_272 ;
do {
V_6 = F_6 ( V_46 -> V_48 + V_273 ) ;
if ( V_6 & V_274 )
break;
F_35 ( 1000 , 2000 ) ;
} while ( -- V_124 );
if ( ! V_124 ) {
F_19 ( V_15 , L_110 , V_46 -> V_47 ) ;
goto V_275;
}
V_124 = V_272 ;
do {
V_6 = F_6 ( V_46 -> V_48 + V_276 ) ;
if ( V_6 & V_277 )
return true ;
F_35 ( 1000 , 2000 ) ;
} while ( -- V_124 );
V_275:
F_34 ( V_46 ) ;
} while ( -- V_268 );
return false ;
}
static void F_159 ( struct V_4 * V_5 )
{
struct V_14 * V_15 = V_5 -> V_15 ;
struct V_45 * V_46 , * V_43 ;
F_29 (port, tmp, &pcie->ports, list) {
F_118 ( V_15 , L_111 ,
V_46 -> V_47 , V_46 -> V_139 ) ;
F_36 ( V_46 ) ;
if ( F_158 ( V_46 ) )
continue;
F_118 ( V_15 , L_112 , V_46 -> V_47 ) ;
F_37 ( V_46 ) ;
F_38 ( V_46 ) ;
}
}
static void * F_160 ( struct V_278 * V_279 , T_9 * V_280 )
{
struct V_4 * V_5 = V_279 -> V_281 ;
if ( F_161 ( & V_5 -> V_267 ) )
return NULL ;
F_162 ( V_279 , L_113 ) ;
return F_163 ( & V_5 -> V_267 , * V_280 ) ;
}
static void * F_164 ( struct V_278 * V_279 , void * V_282 , T_9 * V_280 )
{
struct V_4 * V_5 = V_279 -> V_281 ;
return F_165 ( V_282 , & V_5 -> V_267 , V_280 ) ;
}
static void F_166 ( struct V_278 * V_279 , void * V_282 )
{
}
static int F_167 ( struct V_278 * V_279 , void * V_282 )
{
bool V_283 = false , V_284 = false ;
struct V_45 * V_46 ;
unsigned int V_6 ;
V_46 = F_168 ( V_282 , struct V_45 , V_25 ) ;
V_6 = F_6 ( V_46 -> V_48 + V_273 ) ;
if ( V_6 & V_274 )
V_283 = true ;
V_6 = F_6 ( V_46 -> V_48 + V_276 ) ;
if ( V_6 & V_277 )
V_284 = true ;
F_162 ( V_279 , L_114 , V_46 -> V_47 ) ;
if ( V_283 )
F_162 ( V_279 , L_115 ) ;
if ( V_284 ) {
if ( V_283 )
F_162 ( V_279 , L_116 ) ;
F_162 ( V_279 , L_117 ) ;
}
F_162 ( V_279 , L_118 ) ;
return 0 ;
}
static int F_169 ( struct V_285 * V_285 , struct V_286 * V_286 )
{
struct V_4 * V_5 = V_285 -> V_287 ;
struct V_278 * V_279 ;
int V_22 ;
V_22 = F_170 ( V_286 , & V_288 ) ;
if ( V_22 )
return V_22 ;
V_279 = V_286 -> V_289 ;
V_279 -> V_281 = V_5 ;
return 0 ;
}
static int F_171 ( struct V_4 * V_5 )
{
struct V_290 * V_286 ;
V_5 -> V_291 = F_172 ( L_40 , NULL ) ;
if ( ! V_5 -> V_291 )
return - V_24 ;
V_286 = F_173 ( L_119 , V_292 | V_293 , V_5 -> V_291 ,
V_5 , & V_294 ) ;
if ( ! V_286 )
goto remove;
return 0 ;
remove:
F_174 ( V_5 -> V_291 ) ;
V_5 -> V_291 = NULL ;
return - V_24 ;
}
static int F_175 ( struct V_191 * V_77 )
{
struct V_14 * V_15 = & V_77 -> V_15 ;
struct V_37 * V_38 ;
struct V_4 * V_5 ;
struct V_36 * V_42 ;
int V_22 ;
V_38 = F_176 ( V_15 , sizeof( * V_5 ) ) ;
if ( ! V_38 )
return - V_24 ;
V_5 = F_24 ( V_38 ) ;
V_5 -> V_56 = F_177 ( V_15 ) ;
F_16 ( & V_5 -> V_41 ) ;
F_16 ( & V_5 -> V_267 ) ;
V_5 -> V_15 = V_15 ;
V_22 = F_146 ( V_5 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_96 ( V_5 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_120 , V_22 ) ;
return V_22 ;
}
V_22 = F_70 ( V_5 ) ;
if ( V_22 )
goto V_295;
V_22 = F_46 ( V_5 ) ;
if ( V_22 )
goto V_295;
F_58 ( V_5 ) ;
if ( F_178 ( V_296 ) ) {
V_22 = F_132 ( V_5 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_121 , V_22 ) ;
goto V_295;
}
}
F_159 ( V_5 ) ;
F_179 ( V_297 | V_298 ) ;
V_38 -> V_13 = V_5 -> V_76 . V_19 ;
V_38 -> V_15 . V_299 = & V_77 -> V_15 ;
V_38 -> V_300 = & V_301 ;
V_38 -> V_302 = F_52 ;
V_38 -> V_303 = V_304 ;
V_22 = F_180 ( V_38 ) ;
if ( V_22 < 0 ) {
F_19 ( V_15 , L_122 , V_22 ) ;
goto V_305;
}
F_181 ( V_38 -> V_20 ) ;
F_182 ( V_38 -> V_20 ) ;
F_32 (child, &host->bus->children, node)
F_183 ( V_42 ) ;
F_184 ( V_38 -> V_20 ) ;
if ( F_178 ( V_306 ) ) {
V_22 = F_171 ( V_5 ) ;
if ( V_22 < 0 )
F_19 ( V_15 , L_123 , V_22 ) ;
}
return 0 ;
V_305:
if ( F_178 ( V_296 ) )
F_138 ( V_5 ) ;
V_295:
F_103 ( V_5 ) ;
return V_22 ;
}
