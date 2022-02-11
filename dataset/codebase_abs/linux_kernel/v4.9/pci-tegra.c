static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ;
}
static inline void F_4 ( struct V_4 * V_8 , T_1 V_9 ,
unsigned long V_10 )
{
F_5 ( V_9 , V_8 -> V_11 + V_10 ) ;
}
static inline T_1 F_6 ( struct V_4 * V_8 , unsigned long V_10 )
{
return F_7 ( V_8 -> V_11 + V_10 ) ;
}
static inline void F_8 ( struct V_4 * V_8 , T_1 V_9 ,
unsigned long V_10 )
{
F_5 ( V_9 , V_8 -> V_12 + V_10 ) ;
}
static inline T_1 F_9 ( struct V_4 * V_8 , unsigned long V_10 )
{
return F_7 ( V_8 -> V_12 + V_10 ) ;
}
static unsigned long F_10 ( unsigned int V_13 , int V_14 )
{
return ( ( V_14 & 0xf00 ) << 8 ) | ( F_11 ( V_13 ) << 11 ) |
( F_12 ( V_13 ) << 8 ) | ( V_14 & 0xfc ) ;
}
static struct V_15 * F_13 ( struct V_4 * V_8 ,
unsigned int V_16 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
T_2 V_19 = F_14 ( V_20 | V_21 | V_22 |
V_23 | V_24 | V_25 ) ;
T_3 V_26 = V_8 -> V_26 -> V_27 ;
struct V_15 * V_28 ;
unsigned int V_29 ;
int V_30 ;
V_28 = F_15 ( sizeof( * V_28 ) , V_31 ) ;
if ( ! V_28 )
return F_16 ( - V_32 ) ;
F_17 ( & V_28 -> V_33 ) ;
V_28 -> V_34 = V_16 ;
V_28 -> V_35 = F_18 ( V_36 , V_37 ) ;
if ( ! V_28 -> V_35 ) {
V_30 = - V_32 ;
goto free;
}
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
unsigned long V_38 = ( unsigned long ) V_28 -> V_35 -> V_39 +
V_29 * V_40 ;
T_3 V_41 = V_26 + V_29 * V_42 + V_16 * V_40 ;
V_30 = F_19 ( V_38 , V_38 + V_40 , V_41 , V_19 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_1 , V_30 ) ;
goto V_43;
}
}
return V_28 ;
V_43:
F_21 ( V_28 -> V_35 -> V_39 ) ;
free:
F_22 ( V_28 ) ;
return F_16 ( V_30 ) ;
}
static int F_23 ( struct V_44 * V_28 )
{
struct V_4 * V_8 = F_3 ( V_28 -> V_45 ) ;
struct V_15 * V_46 ;
V_46 = F_13 ( V_8 , V_28 -> V_47 ) ;
if ( F_24 ( V_46 ) )
return F_25 ( V_46 ) ;
F_26 ( & V_46 -> V_33 , & V_8 -> V_48 ) ;
return 0 ;
}
static void F_27 ( struct V_44 * V_49 )
{
struct V_4 * V_8 = F_3 ( V_49 -> V_45 ) ;
struct V_15 * V_28 , * V_50 ;
F_28 (bus, tmp, &pcie->buses, list) {
if ( V_28 -> V_34 == V_49 -> V_47 ) {
F_21 ( V_28 -> V_35 -> V_39 ) ;
F_29 ( & V_28 -> V_33 ) ;
F_22 ( V_28 ) ;
break;
}
}
}
static void T_4 * F_30 ( struct V_44 * V_28 ,
unsigned int V_13 ,
int V_14 )
{
struct V_4 * V_8 = F_3 ( V_28 -> V_45 ) ;
struct V_17 * V_18 = V_8 -> V_18 ;
void T_4 * V_39 = NULL ;
if ( V_28 -> V_47 == 0 ) {
unsigned int V_51 = F_11 ( V_13 ) ;
struct V_52 * V_53 ;
F_31 (port, &pcie->ports, list) {
if ( V_53 -> V_54 + 1 == V_51 ) {
V_39 = V_53 -> V_55 + ( V_14 & ~ 3 ) ;
break;
}
}
} else {
struct V_15 * V_46 ;
F_31 (b, &pcie->buses, list)
if ( V_46 -> V_34 == V_28 -> V_47 )
V_39 = ( void T_4 * ) V_46 -> V_35 -> V_39 ;
if ( ! V_39 ) {
F_20 ( V_18 , L_2 ,
V_28 -> V_47 ) ;
return NULL ;
}
V_39 += F_10 ( V_13 , V_14 ) ;
}
return V_39 ;
}
static unsigned long F_32 ( struct V_52 * V_53 )
{
unsigned long V_56 = 0 ;
switch ( V_53 -> V_54 ) {
case 0 :
V_56 = V_57 ;
break;
case 1 :
V_56 = V_58 ;
break;
case 2 :
V_56 = V_59 ;
break;
}
return V_56 ;
}
static void F_33 ( struct V_52 * V_53 )
{
unsigned long V_60 = F_32 ( V_53 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_53 -> V_8 , V_60 ) ;
V_9 &= ~ V_61 ;
F_4 ( V_53 -> V_8 , V_9 , V_60 ) ;
F_34 ( 1000 , 2000 ) ;
V_9 = F_6 ( V_53 -> V_8 , V_60 ) ;
V_9 |= V_61 ;
F_4 ( V_53 -> V_8 , V_9 , V_60 ) ;
}
static void F_35 ( struct V_52 * V_53 )
{
unsigned long V_60 = F_32 ( V_53 ) ;
const struct V_62 * V_63 = V_53 -> V_8 -> V_63 ;
unsigned long V_9 ;
V_9 = F_6 ( V_53 -> V_8 , V_60 ) ;
V_9 |= V_64 ;
if ( V_63 -> V_65 )
V_9 |= V_66 ;
V_9 |= V_67 ;
F_4 ( V_53 -> V_8 , V_9 , V_60 ) ;
F_33 ( V_53 ) ;
}
static void F_36 ( struct V_52 * V_53 )
{
unsigned long V_60 = F_32 ( V_53 ) ;
const struct V_62 * V_63 = V_53 -> V_8 -> V_63 ;
unsigned long V_9 ;
V_9 = F_6 ( V_53 -> V_8 , V_60 ) ;
V_9 &= ~ V_61 ;
F_4 ( V_53 -> V_8 , V_9 , V_60 ) ;
V_9 = F_6 ( V_53 -> V_8 , V_60 ) ;
if ( V_63 -> V_65 )
V_9 &= ~ V_66 ;
V_9 &= ~ V_64 ;
F_4 ( V_53 -> V_8 , V_9 , V_60 ) ;
}
static void F_37 ( struct V_52 * V_53 )
{
struct V_4 * V_8 = V_53 -> V_8 ;
struct V_17 * V_18 = V_8 -> V_18 ;
F_38 ( V_18 , V_53 -> V_55 ) ;
F_39 ( V_18 , V_53 -> V_68 . V_27 ,
F_40 ( & V_53 -> V_68 ) ) ;
F_29 ( & V_53 -> V_33 ) ;
F_41 ( V_18 , V_53 ) ;
}
static void F_42 ( struct V_69 * V_18 )
{
V_18 -> V_70 = V_71 << 8 ;
}
static void F_43 ( struct V_69 * V_18 )
{
F_44 ( V_18 , V_72 , V_73 ) ;
}
static int F_45 ( int V_34 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
struct V_17 * V_18 = V_8 -> V_18 ;
int V_30 ;
V_6 -> V_74 = V_8 -> V_10 . V_75 ;
V_6 -> V_76 = V_8 -> V_10 . V_77 ;
V_30 = F_46 ( V_18 , & V_78 , & V_8 -> V_77 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_47 ( & V_8 -> V_79 , V_8 -> V_77 . V_27 ) ;
if ( ! V_30 )
F_48 ( & V_6 -> V_80 , & V_8 -> V_79 ,
V_6 -> V_76 ) ;
F_48 ( & V_6 -> V_80 , & V_8 -> V_75 , V_6 -> V_74 ) ;
F_48 ( & V_6 -> V_80 , & V_8 -> V_81 ,
V_6 -> V_74 ) ;
F_49 ( & V_6 -> V_80 , & V_8 -> V_82 ) ;
V_30 = F_50 ( V_18 , & V_6 -> V_80 ) ;
if ( V_30 < 0 )
return V_30 ;
return 1 ;
}
static int F_51 ( const struct V_69 * V_83 , T_5 V_51 , T_5 V_84 )
{
struct V_4 * V_8 = F_3 ( V_83 -> V_28 -> V_45 ) ;
int V_85 ;
F_52 () ;
V_85 = F_53 ( V_83 , V_51 , V_84 ) ;
if ( ! V_85 )
V_85 = V_8 -> V_85 ;
return V_85 ;
}
static T_6 F_54 ( int V_85 , void * V_86 )
{
const char * V_87 [] = {
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
struct V_4 * V_8 = V_86 ;
struct V_17 * V_18 = V_8 -> V_18 ;
T_1 V_88 , V_89 ;
V_88 = F_6 ( V_8 , V_90 ) & V_91 ;
V_89 = F_6 ( V_8 , V_92 ) ;
F_4 ( V_8 , 0 , V_90 ) ;
if ( V_88 == V_93 )
return V_94 ;
if ( V_88 >= F_55 ( V_87 ) )
V_88 = 0 ;
if ( V_88 == V_95 )
F_56 ( V_18 , L_18 , V_87 [ V_88 ] , V_89 ) ;
else
F_20 ( V_18 , L_18 , V_87 [ V_88 ] , V_89 ) ;
if ( V_88 == V_96 || V_88 == V_95 ||
V_88 == V_97 ) {
T_1 V_98 = F_6 ( V_8 , V_99 ) & 0xff ;
T_7 V_100 = ( T_7 ) V_98 << 32 | ( V_89 & 0xfffffffc ) ;
if ( V_88 == V_95 )
F_56 ( V_18 , L_19 , V_100 ) ;
else
F_20 ( V_18 , L_19 , V_100 ) ;
}
return V_101 ;
}
static void F_57 ( struct V_4 * V_8 )
{
T_1 V_102 , V_103 , V_104 ;
V_102 = 0xfe100000 ;
V_103 = F_40 ( V_8 -> V_26 ) ;
V_104 = V_8 -> V_26 -> V_27 ;
F_4 ( V_8 , V_104 , V_105 ) ;
F_4 ( V_8 , V_103 >> 12 , V_106 ) ;
F_4 ( V_8 , V_102 , V_107 ) ;
V_102 = 0xfdfc0000 ;
V_103 = F_40 ( & V_8 -> V_77 ) ;
V_104 = V_8 -> V_77 . V_27 ;
F_4 ( V_8 , V_104 , V_108 ) ;
F_4 ( V_8 , V_103 >> 12 , V_109 ) ;
F_4 ( V_8 , V_102 , V_110 ) ;
V_102 = ( ( ( V_8 -> V_81 . V_27 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_103 = F_40 ( & V_8 -> V_81 ) ;
V_104 = V_8 -> V_81 . V_27 ;
F_4 ( V_8 , V_104 , V_111 ) ;
F_4 ( V_8 , V_103 >> 12 , V_112 ) ;
F_4 ( V_8 , V_102 , V_113 ) ;
V_102 = ( ( ( V_8 -> V_75 . V_27 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_103 = F_40 ( & V_8 -> V_75 ) ;
V_104 = V_8 -> V_75 . V_27 ;
F_4 ( V_8 , V_104 , V_114 ) ;
F_4 ( V_8 , V_103 >> 12 , V_115 ) ;
F_4 ( V_8 , V_102 , V_116 ) ;
F_4 ( V_8 , 0 , V_117 ) ;
F_4 ( V_8 , 0 , V_118 ) ;
F_4 ( V_8 , 0 , V_119 ) ;
F_4 ( V_8 , 0 , V_120 ) ;
F_4 ( V_8 , 0 , V_121 ) ;
F_4 ( V_8 , 0 , V_122 ) ;
F_4 ( V_8 , 0 , V_123 ) ;
F_4 ( V_8 , 0 , V_124 ) ;
F_4 ( V_8 , 0 , V_125 ) ;
F_4 ( V_8 , 0 , V_126 ) ;
F_4 ( V_8 , 0 , V_127 ) ;
F_4 ( V_8 , 0 , V_128 ) ;
F_4 ( V_8 , 0 , V_129 ) ;
F_4 ( V_8 , 0 , V_128 ) ;
}
static int F_58 ( struct V_4 * V_8 , unsigned long V_130 )
{
const struct V_62 * V_63 = V_8 -> V_63 ;
T_1 V_9 ;
V_130 = V_131 + F_59 ( V_130 ) ;
while ( F_60 ( V_131 , V_130 ) ) {
V_9 = F_9 ( V_8 , V_63 -> V_132 ) ;
if ( V_9 & V_133 )
return 0 ;
}
return - V_134 ;
}
static int F_61 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
const struct V_62 * V_63 = V_8 -> V_63 ;
T_1 V_9 ;
int V_30 ;
F_8 ( V_8 , 0x0 , V_135 ) ;
V_9 = F_9 ( V_8 , V_136 ) ;
V_9 |= V_137 ;
F_8 ( V_8 , V_9 , V_136 ) ;
V_9 = F_9 ( V_8 , V_63 -> V_132 ) ;
V_9 &= ~ ( V_138 | V_139 ) ;
V_9 |= V_140 | V_63 -> V_141 ;
F_8 ( V_8 , V_9 , V_63 -> V_132 ) ;
V_9 = F_9 ( V_8 , V_63 -> V_132 ) ;
V_9 &= ~ V_142 ;
F_8 ( V_8 , V_9 , V_63 -> V_132 ) ;
F_34 ( 20 , 100 ) ;
V_9 = F_9 ( V_8 , V_63 -> V_132 ) ;
V_9 |= V_142 ;
F_8 ( V_8 , V_9 , V_63 -> V_132 ) ;
V_30 = F_58 ( V_8 , 500 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_20 , V_30 ) ;
return V_30 ;
}
V_9 = F_9 ( V_8 , V_136 ) ;
V_9 &= ~ V_137 ;
F_8 ( V_8 , V_9 , V_136 ) ;
V_9 = F_9 ( V_8 , V_136 ) ;
V_9 |= V_143 | V_144 ;
F_8 ( V_8 , V_9 , V_136 ) ;
return 0 ;
}
static int F_62 ( struct V_4 * V_8 )
{
const struct V_62 * V_63 = V_8 -> V_63 ;
T_1 V_9 ;
V_9 = F_9 ( V_8 , V_136 ) ;
V_9 &= ~ ( V_143 | V_144 ) ;
F_8 ( V_8 , V_9 , V_136 ) ;
V_9 = F_9 ( V_8 , V_136 ) ;
V_9 |= V_137 ;
F_8 ( V_8 , V_9 , V_136 ) ;
V_9 = F_9 ( V_8 , V_63 -> V_132 ) ;
V_9 &= ~ V_142 ;
F_8 ( V_8 , V_9 , V_63 -> V_132 ) ;
F_34 ( 20 , 100 ) ;
return 0 ;
}
static int F_63 ( struct V_52 * V_53 )
{
struct V_17 * V_18 = V_53 -> V_8 -> V_18 ;
unsigned int V_29 ;
int V_30 ;
for ( V_29 = 0 ; V_29 < V_53 -> V_145 ; V_29 ++ ) {
V_30 = F_64 ( V_53 -> V_41 [ V_29 ] ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_21 , V_29 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_65 ( struct V_52 * V_53 )
{
struct V_17 * V_18 = V_53 -> V_8 -> V_18 ;
unsigned int V_29 ;
int V_30 ;
for ( V_29 = 0 ; V_29 < V_53 -> V_145 ; V_29 ++ ) {
V_30 = F_66 ( V_53 -> V_41 [ V_29 ] ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_22 , V_29 ,
V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_67 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
const struct V_62 * V_63 = V_8 -> V_63 ;
struct V_52 * V_53 ;
int V_30 ;
if ( V_8 -> V_146 ) {
if ( V_8 -> V_147 )
V_30 = F_64 ( V_8 -> V_147 ) ;
else
V_30 = F_61 ( V_8 ) ;
if ( V_30 < 0 )
F_20 ( V_18 , L_23 , V_30 ) ;
return V_30 ;
}
F_31 (port, &pcie->ports, list) {
V_30 = F_63 ( V_53 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 ,
L_24 ,
V_53 -> V_54 , V_30 ) ;
return V_30 ;
}
}
F_8 ( V_8 , V_63 -> V_148 , V_149 ) ;
if ( V_63 -> V_150 > 2 )
F_8 ( V_8 , V_63 -> V_151 , V_152 ) ;
return 0 ;
}
static int F_68 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_52 * V_53 ;
int V_30 ;
if ( V_8 -> V_146 ) {
if ( V_8 -> V_147 )
V_30 = F_66 ( V_8 -> V_147 ) ;
else
V_30 = F_62 ( V_8 ) ;
if ( V_30 < 0 )
F_20 ( V_18 , L_25 , V_30 ) ;
return V_30 ;
}
F_31 (port, &pcie->ports, list) {
V_30 = F_65 ( V_53 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 ,
L_26 ,
V_53 -> V_54 , V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_69 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
const struct V_62 * V_63 = V_8 -> V_63 ;
struct V_52 * V_53 ;
unsigned long V_9 ;
int V_30 ;
if ( V_8 -> V_147 ) {
V_9 = F_6 ( V_8 , V_153 ) ;
V_9 &= ~ V_154 ;
V_9 |= V_155 ;
F_4 ( V_8 , V_9 , V_153 ) ;
}
if ( V_63 -> V_156 )
F_4 ( V_8 , 0 , V_157 ) ;
V_9 = F_6 ( V_8 , V_158 ) ;
V_9 &= ~ V_159 ;
V_9 |= V_160 | V_8 -> V_161 ;
F_31 (port, &pcie->ports, list)
V_9 &= ~ F_70 ( V_53 -> V_54 ) ;
F_4 ( V_8 , V_9 , V_158 ) ;
if ( V_63 -> V_162 ) {
V_9 = F_6 ( V_8 , V_163 ) ;
V_9 &= ~ V_164 ;
F_4 ( V_8 , V_9 , V_163 ) ;
} else {
V_9 = F_6 ( V_8 , V_163 ) ;
V_9 |= V_164 ;
F_4 ( V_8 , V_9 , V_163 ) ;
}
V_30 = F_67 ( V_8 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_27 , V_30 ) ;
return V_30 ;
}
F_71 ( V_8 -> V_165 ) ;
V_9 = F_6 ( V_8 , V_166 ) ;
V_9 |= V_167 ;
F_4 ( V_8 , V_9 , V_166 ) ;
V_9 = V_168 | V_169 |
V_170 | V_171 |
V_172 | V_173 ;
if ( V_63 -> V_174 )
V_9 |= V_175 ;
F_4 ( V_8 , V_9 , V_176 ) ;
F_4 ( V_8 , 0xffffffff , V_177 ) ;
F_4 ( V_8 , V_178 , V_179 ) ;
F_4 ( V_8 , 0 , V_180 ) ;
return 0 ;
}
static void F_72 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
int V_30 ;
V_30 = F_68 ( V_8 ) ;
if ( V_30 < 0 )
F_20 ( V_18 , L_28 , V_30 ) ;
F_73 ( V_8 -> V_165 ) ;
F_73 ( V_8 -> V_181 ) ;
F_73 ( V_8 -> V_182 ) ;
F_74 ( V_183 ) ;
V_30 = F_75 ( V_8 -> V_184 , V_8 -> V_185 ) ;
if ( V_30 < 0 )
F_76 ( V_18 , L_29 , V_30 ) ;
}
static int F_77 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
const struct V_62 * V_63 = V_8 -> V_63 ;
int V_30 ;
F_73 ( V_8 -> V_165 ) ;
F_73 ( V_8 -> V_181 ) ;
F_73 ( V_8 -> V_182 ) ;
F_74 ( V_183 ) ;
V_30 = F_78 ( V_8 -> V_184 , V_8 -> V_185 ) ;
if ( V_30 < 0 )
F_20 ( V_18 , L_30 , V_30 ) ;
V_30 = F_79 ( V_183 ,
V_8 -> V_186 ,
V_8 -> V_182 ) ;
if ( V_30 ) {
F_20 ( V_18 , L_31 , V_30 ) ;
return V_30 ;
}
F_71 ( V_8 -> V_181 ) ;
V_30 = F_80 ( V_8 -> V_187 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_32 , V_30 ) ;
return V_30 ;
}
if ( V_63 -> V_188 ) {
V_30 = F_80 ( V_8 -> V_189 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_33 , V_30 ) ;
return V_30 ;
}
}
V_30 = F_80 ( V_8 -> V_190 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_34 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int F_81 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
const struct V_62 * V_63 = V_8 -> V_63 ;
V_8 -> V_186 = F_82 ( V_18 , L_35 ) ;
if ( F_24 ( V_8 -> V_186 ) )
return F_25 ( V_8 -> V_186 ) ;
V_8 -> V_187 = F_82 ( V_18 , L_36 ) ;
if ( F_24 ( V_8 -> V_187 ) )
return F_25 ( V_8 -> V_187 ) ;
V_8 -> V_190 = F_82 ( V_18 , L_37 ) ;
if ( F_24 ( V_8 -> V_190 ) )
return F_25 ( V_8 -> V_190 ) ;
if ( V_63 -> V_188 ) {
V_8 -> V_189 = F_82 ( V_18 , L_38 ) ;
if ( F_24 ( V_8 -> V_189 ) )
return F_25 ( V_8 -> V_189 ) ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
V_8 -> V_182 = F_84 ( V_18 , L_35 ) ;
if ( F_24 ( V_8 -> V_182 ) )
return F_25 ( V_8 -> V_182 ) ;
V_8 -> V_181 = F_84 ( V_18 , L_36 ) ;
if ( F_24 ( V_8 -> V_181 ) )
return F_25 ( V_8 -> V_181 ) ;
V_8 -> V_165 = F_84 ( V_18 , L_39 ) ;
if ( F_24 ( V_8 -> V_165 ) )
return F_25 ( V_8 -> V_165 ) ;
return 0 ;
}
static int F_85 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
int V_30 ;
V_8 -> V_147 = F_86 ( V_18 , L_40 ) ;
if ( F_24 ( V_8 -> V_147 ) ) {
V_30 = F_25 ( V_8 -> V_147 ) ;
F_20 ( V_18 , L_41 , V_30 ) ;
return V_30 ;
}
V_30 = F_87 ( V_8 -> V_147 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_42 , V_30 ) ;
return V_30 ;
}
V_8 -> V_146 = true ;
return 0 ;
}
static struct V_147 * F_88 ( struct V_17 * V_18 ,
struct V_191 * V_192 ,
const char * V_193 ,
unsigned int V_54 )
{
struct V_147 * V_147 ;
char * V_194 ;
V_194 = F_89 ( V_31 , L_43 , V_193 , V_54 ) ;
if ( ! V_194 )
return F_16 ( - V_32 ) ;
V_147 = F_90 ( V_18 , V_192 , V_194 ) ;
F_22 ( V_194 ) ;
if ( F_24 ( V_147 ) && F_25 ( V_147 ) == - V_195 )
V_147 = NULL ;
return V_147 ;
}
static int F_91 ( struct V_52 * V_53 )
{
struct V_17 * V_18 = V_53 -> V_8 -> V_18 ;
struct V_147 * V_147 ;
unsigned int V_29 ;
int V_30 ;
V_53 -> V_41 = F_92 ( V_18 , sizeof( V_147 ) , V_53 -> V_145 , V_31 ) ;
if ( ! V_53 -> V_41 )
return - V_32 ;
for ( V_29 = 0 ; V_29 < V_53 -> V_145 ; V_29 ++ ) {
V_147 = F_88 ( V_18 , V_53 -> V_192 , L_40 , V_29 ) ;
if ( F_24 ( V_147 ) ) {
F_20 ( V_18 , L_44 , V_29 ,
F_25 ( V_147 ) ) ;
return F_25 ( V_147 ) ;
}
V_30 = F_87 ( V_147 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_45 , V_29 ,
V_30 ) ;
return V_30 ;
}
V_53 -> V_41 [ V_29 ] = V_147 ;
}
return 0 ;
}
static int F_93 ( struct V_4 * V_8 )
{
const struct V_62 * V_63 = V_8 -> V_63 ;
struct V_191 * V_192 = V_8 -> V_18 -> V_196 ;
struct V_52 * V_53 ;
int V_30 ;
if ( ! V_63 -> V_162 || F_94 ( V_192 , L_46 , NULL ) != NULL )
return F_85 ( V_8 ) ;
F_31 (port, &pcie->ports, list) {
V_30 = F_91 ( V_53 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
static int F_95 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_197 * V_83 = F_96 ( V_18 ) ;
struct V_198 * V_12 , * V_11 , * V_199 ;
int V_30 ;
V_30 = F_81 ( V_8 ) ;
if ( V_30 ) {
F_20 ( V_18 , L_47 , V_30 ) ;
return V_30 ;
}
V_30 = F_83 ( V_8 ) ;
if ( V_30 ) {
F_20 ( V_18 , L_48 , V_30 ) ;
return V_30 ;
}
V_30 = F_93 ( V_8 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_49 , V_30 ) ;
return V_30 ;
}
V_30 = F_77 ( V_8 ) ;
if ( V_30 ) {
F_20 ( V_18 , L_50 , V_30 ) ;
return V_30 ;
}
V_12 = F_97 ( V_83 , V_200 , L_51 ) ;
V_8 -> V_12 = F_98 ( V_18 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_30 = F_25 ( V_8 -> V_12 ) ;
goto V_201;
}
V_11 = F_97 ( V_83 , V_200 , L_36 ) ;
V_8 -> V_11 = F_98 ( V_18 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_30 = F_25 ( V_8 -> V_11 ) ;
goto V_201;
}
V_199 = F_97 ( V_83 , V_200 , L_52 ) ;
if ( ! V_199 ) {
V_30 = - V_202 ;
goto V_201;
}
V_8 -> V_26 = F_99 ( V_18 , V_199 -> V_27 ,
F_40 ( V_199 ) , V_199 -> V_194 ) ;
if ( ! V_8 -> V_26 ) {
V_30 = - V_202 ;
goto V_201;
}
V_30 = F_100 ( V_83 , L_53 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_54 , V_30 ) ;
goto V_201;
}
V_8 -> V_85 = V_30 ;
V_30 = F_101 ( V_8 -> V_85 , F_54 , V_203 , L_55 , V_8 ) ;
if ( V_30 ) {
F_20 ( V_18 , L_56 , V_30 ) ;
goto V_201;
}
return 0 ;
V_201:
F_72 ( V_8 ) ;
return V_30 ;
}
static int F_102 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
int V_30 ;
if ( V_8 -> V_85 > 0 )
F_103 ( V_8 -> V_85 , V_8 ) ;
F_72 ( V_8 ) ;
V_30 = F_104 ( V_8 -> V_147 ) ;
if ( V_30 < 0 )
F_20 ( V_18 , L_57 , V_30 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_3 )
{
int V_204 ;
F_106 ( & V_3 -> V_205 ) ;
V_204 = F_107 ( V_3 -> V_206 , V_207 ) ;
if ( V_204 < V_207 )
F_108 ( V_204 , V_3 -> V_206 ) ;
else
V_204 = - V_208 ;
F_109 ( & V_3 -> V_205 ) ;
return V_204 ;
}
static void F_110 ( struct V_1 * V_3 , unsigned long V_85 )
{
struct V_17 * V_18 = V_3 -> V_3 . V_18 ;
F_106 ( & V_3 -> V_205 ) ;
if ( ! F_111 ( V_85 , V_3 -> V_206 ) )
F_20 ( V_18 , L_58 , V_85 ) ;
else
F_112 ( V_85 , V_3 -> V_206 ) ;
F_109 ( & V_3 -> V_205 ) ;
}
static T_6 F_113 ( int V_85 , void * V_209 )
{
struct V_4 * V_8 = V_209 ;
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_1 * V_204 = & V_8 -> V_204 ;
unsigned int V_29 , V_210 = 0 ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
unsigned long V_211 = F_6 ( V_8 , V_212 + V_29 * 4 ) ;
while ( V_211 ) {
unsigned int V_10 = F_114 ( & V_211 , 32 ) ;
unsigned int V_54 = V_29 * 32 + V_10 ;
unsigned int V_85 ;
F_4 ( V_8 , 1 << V_10 , V_212 + V_29 * 4 ) ;
V_85 = F_115 ( V_204 -> V_213 , V_54 ) ;
if ( V_85 ) {
if ( F_111 ( V_54 , V_204 -> V_206 ) )
F_116 ( V_85 ) ;
else
F_117 ( V_18 , L_59 ) ;
} else {
F_117 ( V_18 , L_60 ) ;
}
V_211 = F_6 ( V_8 , V_212 + V_29 * 4 ) ;
V_210 ++ ;
}
}
return V_210 > 0 ? V_101 : V_94 ;
}
static int F_118 ( struct V_2 * V_3 ,
struct V_69 * V_83 , struct V_214 * V_215 )
{
struct V_1 * V_204 = F_1 ( V_3 ) ;
struct V_216 V_217 ;
unsigned int V_85 ;
int V_218 ;
V_218 = F_105 ( V_204 ) ;
if ( V_218 < 0 )
return V_218 ;
V_85 = F_119 ( V_204 -> V_213 , V_218 ) ;
if ( ! V_85 ) {
F_110 ( V_204 , V_218 ) ;
return - V_219 ;
}
F_120 ( V_85 , V_215 ) ;
V_217 . V_220 = F_121 ( ( void * ) V_204 -> V_221 ) ;
V_217 . V_222 = 0 ;
V_217 . V_209 = V_218 ;
F_122 ( V_85 , & V_217 ) ;
return 0 ;
}
static void F_123 ( struct V_2 * V_3 ,
unsigned int V_85 )
{
struct V_1 * V_204 = F_1 ( V_3 ) ;
struct V_223 * V_224 = F_124 ( V_85 ) ;
T_8 V_218 = F_125 ( V_224 ) ;
F_126 ( V_85 ) ;
F_110 ( V_204 , V_218 ) ;
}
static int F_127 ( struct V_225 * V_213 , unsigned int V_85 ,
T_8 V_218 )
{
F_128 ( V_85 , & V_226 , V_227 ) ;
F_129 ( V_85 , V_213 -> V_228 ) ;
F_52 () ;
return 0 ;
}
static int F_130 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_197 * V_83 = F_96 ( V_18 ) ;
const struct V_62 * V_63 = V_8 -> V_63 ;
struct V_1 * V_204 = & V_8 -> V_204 ;
unsigned long V_55 ;
int V_30 ;
T_1 V_211 ;
F_131 ( & V_204 -> V_205 ) ;
V_204 -> V_3 . V_18 = V_18 ;
V_204 -> V_3 . V_229 = F_118 ;
V_204 -> V_3 . V_230 = F_123 ;
V_204 -> V_213 = F_132 ( V_18 -> V_196 , V_207 ,
& V_231 , & V_204 -> V_3 ) ;
if ( ! V_204 -> V_213 ) {
F_20 ( V_18 , L_61 ) ;
return - V_32 ;
}
V_30 = F_100 ( V_83 , L_62 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_54 , V_30 ) ;
goto V_30;
}
V_204 -> V_85 = V_30 ;
V_30 = F_101 ( V_204 -> V_85 , F_113 , V_232 ,
V_226 . V_194 , V_8 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_63 , V_30 ) ;
goto V_30;
}
V_204 -> V_221 = F_133 ( V_31 , 0 ) ;
V_55 = F_121 ( ( void * ) V_204 -> V_221 ) ;
F_4 ( V_8 , V_55 >> V_63 -> V_233 , V_127 ) ;
F_4 ( V_8 , V_55 , V_129 ) ;
F_4 ( V_8 , 1 , V_128 ) ;
F_4 ( V_8 , 0xffffffff , V_234 ) ;
F_4 ( V_8 , 0xffffffff , V_235 ) ;
F_4 ( V_8 , 0xffffffff , V_236 ) ;
F_4 ( V_8 , 0xffffffff , V_237 ) ;
F_4 ( V_8 , 0xffffffff , V_238 ) ;
F_4 ( V_8 , 0xffffffff , V_239 ) ;
F_4 ( V_8 , 0xffffffff , V_240 ) ;
F_4 ( V_8 , 0xffffffff , V_241 ) ;
V_211 = F_6 ( V_8 , V_179 ) ;
V_211 |= V_242 ;
F_4 ( V_8 , V_211 , V_179 ) ;
return 0 ;
V_30:
F_134 ( V_204 -> V_213 ) ;
return V_30 ;
}
static int F_135 ( struct V_4 * V_8 )
{
struct V_1 * V_204 = & V_8 -> V_204 ;
unsigned int V_29 , V_85 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_179 ) ;
V_9 &= ~ V_242 ;
F_4 ( V_8 , V_9 , V_179 ) ;
F_4 ( V_8 , 0 , V_234 ) ;
F_4 ( V_8 , 0 , V_235 ) ;
F_4 ( V_8 , 0 , V_236 ) ;
F_4 ( V_8 , 0 , V_237 ) ;
F_4 ( V_8 , 0 , V_238 ) ;
F_4 ( V_8 , 0 , V_239 ) ;
F_4 ( V_8 , 0 , V_240 ) ;
F_4 ( V_8 , 0 , V_241 ) ;
F_136 ( V_204 -> V_221 , 0 ) ;
if ( V_204 -> V_85 > 0 )
F_103 ( V_204 -> V_85 , V_8 ) ;
for ( V_29 = 0 ; V_29 < V_207 ; V_29 ++ ) {
V_85 = F_115 ( V_204 -> V_213 , V_29 ) ;
if ( V_85 > 0 )
F_126 ( V_85 ) ;
}
F_134 ( V_204 -> V_213 ) ;
return 0 ;
}
static int F_137 ( struct V_4 * V_8 , T_1 V_145 ,
T_1 * V_243 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_191 * V_192 = V_18 -> V_196 ;
if ( F_138 ( V_192 , L_64 ) ) {
switch ( V_145 ) {
case 0x0000104 :
F_117 ( V_18 , L_65 ) ;
* V_243 = V_244 ;
return 0 ;
case 0x0000102 :
F_117 ( V_18 , L_66 ) ;
* V_243 = V_245 ;
return 0 ;
}
} else if ( F_138 ( V_192 , L_67 ) ) {
switch ( V_145 ) {
case 0x00000204 :
F_117 ( V_18 , L_68 ) ;
* V_243 = V_246 ;
return 0 ;
case 0x00020202 :
F_117 ( V_18 , L_69 ) ;
* V_243 = V_247 ;
return 0 ;
case 0x00010104 :
F_117 ( V_18 , L_70 ) ;
* V_243 = V_248 ;
return 0 ;
}
} else if ( F_138 ( V_192 , L_71 ) ) {
switch ( V_145 ) {
case 0x00000004 :
F_117 ( V_18 , L_72 ) ;
* V_243 = V_249 ;
return 0 ;
case 0x00000202 :
F_117 ( V_18 , L_73 ) ;
* V_243 = V_250 ;
return 0 ;
}
}
return - V_219 ;
}
static bool F_139 ( struct V_191 * V_192 ,
struct V_251 * V_185 ,
unsigned int V_184 )
{
char V_252 [ 32 ] ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_184 ; V_29 ++ ) {
snprintf ( V_252 , 32 , L_74 , V_185 [ V_29 ] . V_253 ) ;
if ( F_94 ( V_192 , V_252 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_140 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_191 * V_192 = V_18 -> V_196 ;
if ( F_138 ( V_192 , L_67 ) )
V_8 -> V_184 = 3 ;
else if ( F_138 ( V_192 , L_71 ) )
V_8 -> V_184 = 2 ;
if ( V_8 -> V_184 == 0 ) {
F_20 ( V_18 , L_75 ,
V_192 -> V_254 ) ;
return - V_195 ;
}
V_8 -> V_185 = F_92 ( V_18 , V_8 -> V_184 ,
sizeof( * V_8 -> V_185 ) ,
V_31 ) ;
if ( ! V_8 -> V_185 )
return - V_32 ;
V_8 -> V_185 [ 0 ] . V_253 = L_76 ;
V_8 -> V_185 [ 1 ] . V_253 = L_77 ;
if ( V_8 -> V_184 > 2 )
V_8 -> V_185 [ 2 ] . V_253 = L_78 ;
return F_141 ( V_18 , V_8 -> V_184 , V_8 -> V_185 ) ;
}
static int F_142 ( struct V_4 * V_8 , T_1 V_255 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_191 * V_192 = V_18 -> V_196 ;
unsigned int V_29 = 0 ;
if ( F_138 ( V_192 , L_64 ) ) {
V_8 -> V_184 = 7 ;
V_8 -> V_185 = F_92 ( V_18 , V_8 -> V_184 ,
sizeof( * V_8 -> V_185 ) ,
V_31 ) ;
if ( ! V_8 -> V_185 )
return - V_32 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_79 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_80 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_81 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_82 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_83 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_84 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_85 ;
} else if ( F_138 ( V_192 , L_67 ) ) {
bool V_256 = false , V_257 = false ;
if ( V_255 & 0x0f )
V_256 = true ;
if ( V_255 & 0x30 )
V_257 = true ;
V_8 -> V_184 = 4 + ( V_256 ? 2 : 0 ) +
( V_257 ? 2 : 0 ) ;
V_8 -> V_185 = F_92 ( V_18 , V_8 -> V_184 ,
sizeof( * V_8 -> V_185 ) ,
V_31 ) ;
if ( ! V_8 -> V_185 )
return - V_32 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_81 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_82 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_84 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_86 ;
if ( V_256 ) {
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_87 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_88 ;
}
if ( V_257 ) {
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_89 ;
V_8 -> V_185 [ V_29 ++ ] . V_253 = L_90 ;
}
} else if ( F_138 ( V_192 , L_71 ) ) {
V_8 -> V_184 = 5 ;
V_8 -> V_185 = F_92 ( V_18 , V_8 -> V_184 ,
sizeof( * V_8 -> V_185 ) ,
V_31 ) ;
if ( ! V_8 -> V_185 )
return - V_32 ;
V_8 -> V_185 [ 0 ] . V_253 = L_91 ;
V_8 -> V_185 [ 1 ] . V_253 = L_92 ;
V_8 -> V_185 [ 2 ] . V_253 = L_81 ;
V_8 -> V_185 [ 3 ] . V_253 = L_86 ;
V_8 -> V_185 [ 4 ] . V_253 = L_93 ;
}
if ( F_139 ( V_18 -> V_196 , V_8 -> V_185 ,
V_8 -> V_184 ) )
return F_141 ( V_18 , V_8 -> V_184 ,
V_8 -> V_185 ) ;
F_117 ( V_18 , L_94 ) ;
F_41 ( V_18 , V_8 -> V_185 ) ;
V_8 -> V_184 = 0 ;
return F_140 ( V_8 ) ;
}
static int F_143 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_191 * V_192 = V_18 -> V_196 , * V_53 ;
const struct V_62 * V_63 = V_8 -> V_63 ;
struct V_258 V_259 ;
struct V_260 V_261 ;
T_1 V_145 = 0 , V_262 = 0 ;
unsigned int V_263 = 0 ;
struct V_198 V_199 ;
int V_30 ;
if ( F_144 ( & V_259 , V_192 ) ) {
F_20 ( V_18 , L_95 ) ;
return - V_219 ;
}
F_145 (&parser, &range) {
V_30 = F_146 ( & V_261 , V_192 , & V_199 ) ;
if ( V_30 < 0 )
return V_30 ;
switch ( V_199 . V_264 & V_265 ) {
case V_266 :
V_8 -> V_10 . V_77 = V_199 . V_27 - V_261 . V_267 ;
memcpy ( & V_8 -> V_79 , & V_199 , sizeof( V_199 ) ) ;
V_8 -> V_79 . V_194 = V_192 -> V_254 ;
V_8 -> V_77 . V_27 = V_261 . V_268 ;
V_8 -> V_77 . V_269 = V_261 . V_268 + V_261 . V_103 - 1 ;
V_8 -> V_77 . V_264 = V_200 ;
V_8 -> V_77 . V_194 = L_96 ;
memcpy ( & V_199 , & V_8 -> V_77 , sizeof( V_199 ) ) ;
break;
case V_200 :
V_8 -> V_10 . V_75 = V_199 . V_27 - V_261 . V_267 ;
if ( V_199 . V_264 & V_270 ) {
memcpy ( & V_8 -> V_81 , & V_199 , sizeof( V_199 ) ) ;
V_8 -> V_81 . V_194 = L_97 ;
} else {
memcpy ( & V_8 -> V_75 , & V_199 , sizeof( V_199 ) ) ;
V_8 -> V_75 . V_194 = L_98 ;
}
break;
}
}
V_30 = F_147 ( V_192 , & V_8 -> V_82 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_99 , V_30 ) ;
V_8 -> V_82 . V_194 = V_192 -> V_194 ;
V_8 -> V_82 . V_27 = 0 ;
V_8 -> V_82 . V_269 = 0xff ;
V_8 -> V_82 . V_264 = V_271 ;
}
F_148 (np, port) {
struct V_52 * V_272 ;
unsigned int V_54 ;
T_1 V_9 ;
V_30 = F_149 ( V_53 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_100 , V_30 ) ;
return V_30 ;
}
V_54 = F_11 ( V_30 ) ;
if ( V_54 < 1 || V_54 > V_63 -> V_150 ) {
F_20 ( V_18 , L_101 , V_54 ) ;
return - V_219 ;
}
V_54 -- ;
V_30 = F_150 ( V_53 , L_102 , & V_9 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_103 ,
V_30 ) ;
return V_30 ;
}
if ( V_9 > 16 ) {
F_20 ( V_18 , L_104 , V_9 ) ;
return - V_219 ;
}
V_145 |= V_9 << ( V_54 << 3 ) ;
if ( ! F_151 ( V_53 ) ) {
V_263 += V_9 ;
continue;
}
V_262 |= ( ( 1 << V_9 ) - 1 ) << V_263 ;
V_263 += V_9 ;
V_272 = F_152 ( V_18 , sizeof( * V_272 ) , V_31 ) ;
if ( ! V_272 )
return - V_32 ;
V_30 = F_153 ( V_53 , 0 , & V_272 -> V_68 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_100 , V_30 ) ;
return V_30 ;
}
F_17 ( & V_272 -> V_33 ) ;
V_272 -> V_54 = V_54 ;
V_272 -> V_145 = V_9 ;
V_272 -> V_8 = V_8 ;
V_272 -> V_192 = V_53 ;
V_272 -> V_55 = F_98 ( V_18 , & V_272 -> V_68 ) ;
if ( F_24 ( V_272 -> V_55 ) )
return F_25 ( V_272 -> V_55 ) ;
F_26 ( & V_272 -> V_33 , & V_8 -> V_273 ) ;
}
V_30 = F_137 ( V_8 , V_145 , & V_8 -> V_161 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_105 ) ;
return V_30 ;
}
V_30 = F_142 ( V_8 , V_262 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
static bool F_154 ( struct V_52 * V_53 )
{
struct V_17 * V_18 = V_53 -> V_8 -> V_18 ;
unsigned int V_274 = 3 ;
unsigned long V_9 ;
V_9 = F_7 ( V_53 -> V_55 + V_275 ) ;
V_9 &= ~ V_276 ;
V_9 |= V_277 ;
F_5 ( V_9 , V_53 -> V_55 + V_275 ) ;
do {
unsigned int V_130 = V_278 ;
do {
V_9 = F_7 ( V_53 -> V_55 + V_279 ) ;
if ( V_9 & V_280 )
break;
F_34 ( 1000 , 2000 ) ;
} while ( -- V_130 );
if ( ! V_130 ) {
F_20 ( V_18 , L_106 , V_53 -> V_54 ) ;
goto V_281;
}
V_130 = V_278 ;
do {
V_9 = F_7 ( V_53 -> V_55 + V_282 ) ;
if ( V_9 & V_283 )
return true ;
F_34 ( 1000 , 2000 ) ;
} while ( -- V_130 );
V_281:
F_33 ( V_53 ) ;
} while ( -- V_274 );
return false ;
}
static int F_155 ( struct V_4 * V_8 )
{
struct V_17 * V_18 = V_8 -> V_18 ;
struct V_52 * V_53 , * V_50 ;
struct V_284 V_285 ;
F_28 (port, tmp, &pcie->ports, list) {
F_117 ( V_18 , L_107 ,
V_53 -> V_54 , V_53 -> V_145 ) ;
F_35 ( V_53 ) ;
if ( F_154 ( V_53 ) )
continue;
F_117 ( V_18 , L_108 , V_53 -> V_54 ) ;
F_36 ( V_53 ) ;
F_37 ( V_53 ) ;
}
memset ( & V_285 , 0 , sizeof( V_285 ) ) ;
#ifdef F_156
V_285 . V_286 = & V_8 -> V_204 . V_3 ;
#endif
V_285 . V_287 = 1 ;
V_285 . V_7 = ( void * * ) & V_8 ;
V_285 . V_288 = F_45 ;
V_285 . V_289 = F_51 ;
V_285 . V_290 = & V_291 ;
F_157 ( V_18 , & V_285 ) ;
return 0 ;
}
static void * F_158 ( struct V_292 * V_293 , T_9 * V_294 )
{
struct V_4 * V_8 = V_293 -> V_295 ;
if ( F_159 ( & V_8 -> V_273 ) )
return NULL ;
F_160 ( V_293 , L_109 ) ;
return F_161 ( & V_8 -> V_273 , * V_294 ) ;
}
static void * F_162 ( struct V_292 * V_293 , void * V_296 , T_9 * V_294 )
{
struct V_4 * V_8 = V_293 -> V_295 ;
return F_163 ( V_296 , & V_8 -> V_273 , V_294 ) ;
}
static void F_164 ( struct V_292 * V_293 , void * V_296 )
{
}
static int F_165 ( struct V_292 * V_293 , void * V_296 )
{
bool V_297 = false , V_298 = false ;
struct V_52 * V_53 ;
unsigned int V_9 ;
V_53 = F_166 ( V_296 , struct V_52 , V_33 ) ;
V_9 = F_7 ( V_53 -> V_55 + V_279 ) ;
if ( V_9 & V_280 )
V_297 = true ;
V_9 = F_7 ( V_53 -> V_55 + V_282 ) ;
if ( V_9 & V_283 )
V_298 = true ;
F_160 ( V_293 , L_110 , V_53 -> V_54 ) ;
if ( V_297 )
F_160 ( V_293 , L_111 ) ;
if ( V_298 ) {
if ( V_297 )
F_160 ( V_293 , L_112 ) ;
F_160 ( V_293 , L_113 ) ;
}
F_160 ( V_293 , L_114 ) ;
return 0 ;
}
static int F_167 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
struct V_4 * V_8 = V_299 -> V_301 ;
struct V_292 * V_293 ;
int V_30 ;
V_30 = F_168 ( V_300 , & V_302 ) ;
if ( V_30 )
return V_30 ;
V_293 = V_300 -> V_7 ;
V_293 -> V_295 = V_8 ;
return 0 ;
}
static int F_169 ( struct V_4 * V_8 )
{
struct V_303 * V_300 ;
V_8 -> V_304 = F_170 ( L_40 , NULL ) ;
if ( ! V_8 -> V_304 )
return - V_32 ;
V_300 = F_171 ( L_115 , V_305 | V_306 , V_8 -> V_304 ,
V_8 , & V_307 ) ;
if ( ! V_300 )
goto remove;
return 0 ;
remove:
F_172 ( V_8 -> V_304 ) ;
V_8 -> V_304 = NULL ;
return - V_32 ;
}
static int F_173 ( struct V_197 * V_83 )
{
struct V_17 * V_18 = & V_83 -> V_18 ;
struct V_4 * V_8 ;
int V_30 ;
V_8 = F_152 ( V_18 , sizeof( * V_8 ) , V_31 ) ;
if ( ! V_8 )
return - V_32 ;
V_8 -> V_63 = F_174 ( V_18 ) ;
F_17 ( & V_8 -> V_48 ) ;
F_17 ( & V_8 -> V_273 ) ;
V_8 -> V_18 = V_18 ;
V_30 = F_143 ( V_8 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_95 ( V_8 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_116 , V_30 ) ;
return V_30 ;
}
V_30 = F_69 ( V_8 ) ;
if ( V_30 )
goto V_308;
F_57 ( V_8 ) ;
if ( F_175 ( F_156 ) ) {
V_30 = F_130 ( V_8 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_117 , V_30 ) ;
goto V_308;
}
}
V_30 = F_155 ( V_8 ) ;
if ( V_30 < 0 ) {
F_20 ( V_18 , L_118 , V_30 ) ;
goto V_309;
}
if ( F_175 ( V_310 ) ) {
V_30 = F_169 ( V_8 ) ;
if ( V_30 < 0 )
F_20 ( V_18 , L_119 , V_30 ) ;
}
return 0 ;
V_309:
if ( F_175 ( F_156 ) )
F_135 ( V_8 ) ;
V_308:
F_102 ( V_8 ) ;
return V_30 ;
}
