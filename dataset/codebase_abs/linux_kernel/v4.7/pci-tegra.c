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
T_2 V_17 = F_14 ( V_18 | V_19 | V_20 |
V_21 | V_22 | V_23 ) ;
T_3 V_24 = V_8 -> V_24 -> V_25 ;
struct V_15 * V_26 ;
unsigned int V_27 ;
int V_28 ;
V_26 = F_15 ( sizeof( * V_26 ) , V_29 ) ;
if ( ! V_26 )
return F_16 ( - V_30 ) ;
F_17 ( & V_26 -> V_31 ) ;
V_26 -> V_32 = V_16 ;
V_26 -> V_33 = F_18 ( V_34 , V_35 ) ;
if ( ! V_26 -> V_33 ) {
V_28 = - V_30 ;
goto free;
}
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ ) {
unsigned long V_36 = ( unsigned long ) V_26 -> V_33 -> V_37 +
V_27 * V_38 ;
T_3 V_39 = V_24 + V_27 * V_40 + V_16 * V_38 ;
V_28 = F_19 ( V_36 , V_36 + V_38 , V_39 , V_17 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_1 ,
V_28 ) ;
goto V_42;
}
}
return V_26 ;
V_42:
F_21 ( V_26 -> V_33 -> V_37 ) ;
free:
F_22 ( V_26 ) ;
return F_16 ( V_28 ) ;
}
static int F_23 ( struct V_43 * V_26 )
{
struct V_4 * V_8 = F_3 ( V_26 -> V_44 ) ;
struct V_15 * V_45 ;
V_45 = F_13 ( V_8 , V_26 -> V_46 ) ;
if ( F_24 ( V_45 ) )
return F_25 ( V_45 ) ;
F_26 ( & V_45 -> V_31 , & V_8 -> V_47 ) ;
return 0 ;
}
static void F_27 ( struct V_43 * V_48 )
{
struct V_4 * V_8 = F_3 ( V_48 -> V_44 ) ;
struct V_15 * V_26 , * V_49 ;
F_28 (bus, tmp, &pcie->buses, list) {
if ( V_26 -> V_32 == V_48 -> V_46 ) {
F_21 ( V_26 -> V_33 -> V_37 ) ;
F_29 ( & V_26 -> V_31 ) ;
F_22 ( V_26 ) ;
break;
}
}
}
static void T_4 * F_30 ( struct V_43 * V_26 ,
unsigned int V_13 ,
int V_14 )
{
struct V_4 * V_8 = F_3 ( V_26 -> V_44 ) ;
void T_4 * V_37 = NULL ;
if ( V_26 -> V_46 == 0 ) {
unsigned int V_50 = F_11 ( V_13 ) ;
struct V_51 * V_52 ;
F_31 (port, &pcie->ports, list) {
if ( V_52 -> V_53 + 1 == V_50 ) {
V_37 = V_52 -> V_54 + ( V_14 & ~ 3 ) ;
break;
}
}
} else {
struct V_15 * V_45 ;
F_31 (b, &pcie->buses, list)
if ( V_45 -> V_32 == V_26 -> V_46 )
V_37 = ( void T_4 * ) V_45 -> V_33 -> V_37 ;
if ( ! V_37 ) {
F_20 ( V_8 -> V_41 ,
L_2 ,
V_26 -> V_46 ) ;
return NULL ;
}
V_37 += F_10 ( V_13 , V_14 ) ;
}
return V_37 ;
}
static unsigned long F_32 ( struct V_51 * V_52 )
{
unsigned long V_55 = 0 ;
switch ( V_52 -> V_53 ) {
case 0 :
V_55 = V_56 ;
break;
case 1 :
V_55 = V_57 ;
break;
case 2 :
V_55 = V_58 ;
break;
}
return V_55 ;
}
static void F_33 ( struct V_51 * V_52 )
{
unsigned long V_59 = F_32 ( V_52 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_52 -> V_8 , V_59 ) ;
V_9 &= ~ V_60 ;
F_4 ( V_52 -> V_8 , V_9 , V_59 ) ;
F_34 ( 1000 , 2000 ) ;
V_9 = F_6 ( V_52 -> V_8 , V_59 ) ;
V_9 |= V_60 ;
F_4 ( V_52 -> V_8 , V_9 , V_59 ) ;
}
static void F_35 ( struct V_51 * V_52 )
{
const struct V_61 * V_62 = V_52 -> V_8 -> V_63 ;
unsigned long V_59 = F_32 ( V_52 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_52 -> V_8 , V_59 ) ;
V_9 |= V_64 ;
if ( V_62 -> V_65 )
V_9 |= V_66 ;
V_9 |= V_67 ;
F_4 ( V_52 -> V_8 , V_9 , V_59 ) ;
F_33 ( V_52 ) ;
}
static void F_36 ( struct V_51 * V_52 )
{
const struct V_61 * V_62 = V_52 -> V_8 -> V_63 ;
unsigned long V_59 = F_32 ( V_52 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_52 -> V_8 , V_59 ) ;
V_9 &= ~ V_60 ;
F_4 ( V_52 -> V_8 , V_9 , V_59 ) ;
V_9 = F_6 ( V_52 -> V_8 , V_59 ) ;
if ( V_62 -> V_65 )
V_9 &= ~ V_66 ;
V_9 &= ~ V_64 ;
F_4 ( V_52 -> V_8 , V_9 , V_59 ) ;
}
static void F_37 ( struct V_51 * V_52 )
{
struct V_4 * V_8 = V_52 -> V_8 ;
F_38 ( V_8 -> V_41 , V_52 -> V_54 ) ;
F_39 ( V_8 -> V_41 , V_52 -> V_68 . V_25 ,
F_40 ( & V_52 -> V_68 ) ) ;
F_29 ( & V_52 -> V_31 ) ;
F_41 ( V_8 -> V_41 , V_52 ) ;
}
static void F_42 ( struct V_69 * V_41 )
{
V_41 -> V_70 = V_71 << 8 ;
}
static void F_43 ( struct V_69 * V_41 )
{
F_44 ( V_41 , V_72 , V_73 ) ;
}
static int F_45 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
int V_28 ;
V_6 -> V_74 = V_8 -> V_10 . V_75 ;
V_6 -> V_76 = V_8 -> V_10 . V_77 ;
V_28 = F_46 ( V_8 -> V_41 , & V_8 -> V_78 , & V_8 -> V_77 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_46 ( V_8 -> V_41 , & V_79 , & V_8 -> V_80 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_46 ( V_8 -> V_41 , & V_8 -> V_78 , & V_8 -> V_75 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_46 ( V_8 -> V_41 , & V_8 -> V_78 , & V_8 -> V_81 ) ;
if ( V_28 )
return V_28 ;
F_47 ( & V_6 -> V_82 , & V_8 -> V_80 , V_6 -> V_76 ) ;
F_47 ( & V_6 -> V_82 , & V_8 -> V_75 , V_6 -> V_74 ) ;
F_47 ( & V_6 -> V_82 , & V_8 -> V_81 ,
V_6 -> V_74 ) ;
F_48 ( & V_6 -> V_82 , & V_8 -> V_83 ) ;
F_49 ( V_8 -> V_80 . V_25 , V_8 -> V_77 . V_25 ) ;
return 1 ;
}
static int F_50 ( const struct V_69 * V_84 , T_5 V_50 , T_5 V_85 )
{
struct V_4 * V_8 = F_3 ( V_84 -> V_26 -> V_44 ) ;
int V_86 ;
F_51 () ;
V_86 = F_52 ( V_84 , V_50 , V_85 ) ;
if ( ! V_86 )
V_86 = V_8 -> V_86 ;
return V_86 ;
}
static T_6 F_53 ( int V_86 , void * V_87 )
{
const char * V_88 [] = {
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
struct V_4 * V_8 = V_87 ;
T_1 V_89 , V_90 ;
V_89 = F_6 ( V_8 , V_91 ) & V_92 ;
V_90 = F_6 ( V_8 , V_93 ) ;
F_4 ( V_8 , 0 , V_91 ) ;
if ( V_89 == V_94 )
return V_95 ;
if ( V_89 >= F_54 ( V_88 ) )
V_89 = 0 ;
if ( V_89 == V_96 )
F_55 ( V_8 -> V_41 , L_18 , V_88 [ V_89 ] ,
V_90 ) ;
else
F_20 ( V_8 -> V_41 , L_18 , V_88 [ V_89 ] ,
V_90 ) ;
if ( V_89 == V_97 || V_89 == V_96 ||
V_89 == V_98 ) {
T_1 V_99 = F_6 ( V_8 , V_100 ) & 0xff ;
T_7 V_101 = ( T_7 ) V_99 << 32 | ( V_90 & 0xfffffffc ) ;
if ( V_89 == V_96 )
F_55 ( V_8 -> V_41 , L_19 , V_101 ) ;
else
F_20 ( V_8 -> V_41 , L_19 , V_101 ) ;
}
return V_102 ;
}
static void F_56 ( struct V_4 * V_8 )
{
T_1 V_103 , V_104 , V_105 ;
V_103 = 0xfe100000 ;
V_104 = F_40 ( V_8 -> V_24 ) ;
V_105 = V_8 -> V_24 -> V_25 ;
F_4 ( V_8 , V_105 , V_106 ) ;
F_4 ( V_8 , V_104 >> 12 , V_107 ) ;
F_4 ( V_8 , V_103 , V_108 ) ;
V_103 = 0xfdfc0000 ;
V_104 = F_40 ( & V_8 -> V_77 ) ;
V_105 = V_8 -> V_77 . V_25 ;
F_4 ( V_8 , V_105 , V_109 ) ;
F_4 ( V_8 , V_104 >> 12 , V_110 ) ;
F_4 ( V_8 , V_103 , V_111 ) ;
V_103 = ( ( ( V_8 -> V_81 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_104 = F_40 ( & V_8 -> V_81 ) ;
V_105 = V_8 -> V_81 . V_25 ;
F_4 ( V_8 , V_105 , V_112 ) ;
F_4 ( V_8 , V_104 >> 12 , V_113 ) ;
F_4 ( V_8 , V_103 , V_114 ) ;
V_103 = ( ( ( V_8 -> V_75 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_104 = F_40 ( & V_8 -> V_75 ) ;
V_105 = V_8 -> V_75 . V_25 ;
F_4 ( V_8 , V_105 , V_115 ) ;
F_4 ( V_8 , V_104 >> 12 , V_116 ) ;
F_4 ( V_8 , V_103 , V_117 ) ;
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
F_4 ( V_8 , 0 , V_130 ) ;
F_4 ( V_8 , 0 , V_129 ) ;
}
static int F_57 ( struct V_4 * V_8 , unsigned long V_131 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
T_1 V_9 ;
V_131 = V_132 + F_58 ( V_131 ) ;
while ( F_59 ( V_132 , V_131 ) ) {
V_9 = F_9 ( V_8 , V_62 -> V_133 ) ;
if ( V_9 & V_134 )
return 0 ;
}
return - V_135 ;
}
static int F_60 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
T_1 V_9 ;
int V_28 ;
F_8 ( V_8 , 0x0 , V_136 ) ;
V_9 = F_9 ( V_8 , V_137 ) ;
V_9 |= V_138 ;
F_8 ( V_8 , V_9 , V_137 ) ;
V_9 = F_9 ( V_8 , V_62 -> V_133 ) ;
V_9 &= ~ ( V_139 | V_140 ) ;
V_9 |= V_141 | V_62 -> V_142 ;
F_8 ( V_8 , V_9 , V_62 -> V_133 ) ;
V_9 = F_9 ( V_8 , V_62 -> V_133 ) ;
V_9 &= ~ V_143 ;
F_8 ( V_8 , V_9 , V_62 -> V_133 ) ;
F_34 ( 20 , 100 ) ;
V_9 = F_9 ( V_8 , V_62 -> V_133 ) ;
V_9 |= V_143 ;
F_8 ( V_8 , V_9 , V_62 -> V_133 ) ;
V_9 = V_144 | ( V_144 << 16 ) ;
F_8 ( V_8 , V_9 , V_145 ) ;
if ( V_62 -> V_146 > 2 )
F_8 ( V_8 , V_144 , V_147 ) ;
V_28 = F_57 ( V_8 , 500 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_20 , V_28 ) ;
return V_28 ;
}
V_9 = F_9 ( V_8 , V_137 ) ;
V_9 &= ~ V_138 ;
F_8 ( V_8 , V_9 , V_137 ) ;
V_9 = F_9 ( V_8 , V_137 ) ;
V_9 |= V_148 | V_149 ;
F_8 ( V_8 , V_9 , V_137 ) ;
return 0 ;
}
static int F_61 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
T_1 V_9 ;
V_9 = F_9 ( V_8 , V_137 ) ;
V_9 &= ~ ( V_148 | V_149 ) ;
F_8 ( V_8 , V_9 , V_137 ) ;
V_9 = F_9 ( V_8 , V_137 ) ;
V_9 |= V_138 ;
F_8 ( V_8 , V_137 , V_9 ) ;
V_9 = F_9 ( V_8 , V_62 -> V_133 ) ;
V_9 &= ~ V_143 ;
F_8 ( V_8 , V_9 , V_62 -> V_133 ) ;
F_34 ( 20 , 100 ) ;
return 0 ;
}
static int F_62 ( struct V_51 * V_52 )
{
struct V_150 * V_41 = V_52 -> V_8 -> V_41 ;
unsigned int V_27 ;
int V_28 ;
for ( V_27 = 0 ; V_27 < V_52 -> V_151 ; V_27 ++ ) {
V_28 = F_63 ( V_52 -> V_39 [ V_27 ] ) ;
if ( V_28 < 0 ) {
F_20 ( V_41 , L_21 , V_27 ,
V_28 ) ;
return V_28 ;
}
}
return 0 ;
}
static int F_64 ( struct V_51 * V_52 )
{
struct V_150 * V_41 = V_52 -> V_8 -> V_41 ;
unsigned int V_27 ;
int V_28 ;
for ( V_27 = 0 ; V_27 < V_52 -> V_151 ; V_27 ++ ) {
V_28 = F_65 ( V_52 -> V_39 [ V_27 ] ) ;
if ( V_28 < 0 ) {
F_20 ( V_41 , L_22 , V_27 ,
V_28 ) ;
return V_28 ;
}
}
return 0 ;
}
static int F_66 ( struct V_4 * V_8 )
{
struct V_51 * V_52 ;
int V_28 ;
if ( V_8 -> V_152 ) {
if ( V_8 -> V_153 )
V_28 = F_63 ( V_8 -> V_153 ) ;
else
V_28 = F_60 ( V_8 ) ;
if ( V_28 < 0 )
F_20 ( V_8 -> V_41 , L_23 , V_28 ) ;
return V_28 ;
}
F_31 (port, &pcie->ports, list) {
V_28 = F_62 ( V_52 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 ,
L_24 ,
V_52 -> V_53 , V_28 ) ;
return V_28 ;
}
}
return 0 ;
}
static int F_67 ( struct V_4 * V_8 )
{
struct V_51 * V_52 ;
int V_28 ;
if ( V_8 -> V_152 ) {
if ( V_8 -> V_153 )
V_28 = F_65 ( V_8 -> V_153 ) ;
else
V_28 = F_61 ( V_8 ) ;
if ( V_28 < 0 )
F_20 ( V_8 -> V_41 , L_25 ,
V_28 ) ;
return V_28 ;
}
F_31 (port, &pcie->ports, list) {
V_28 = F_64 ( V_52 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 ,
L_26 ,
V_52 -> V_53 , V_28 ) ;
return V_28 ;
}
}
return 0 ;
}
static int F_68 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
struct V_51 * V_52 ;
unsigned long V_9 ;
int V_28 ;
if ( V_8 -> V_153 ) {
V_9 = F_6 ( V_8 , V_154 ) ;
V_9 &= ~ V_155 ;
V_9 |= V_156 ;
F_4 ( V_8 , V_9 , V_154 ) ;
}
if ( V_62 -> V_157 )
F_4 ( V_8 , 0 , V_158 ) ;
V_9 = F_6 ( V_8 , V_159 ) ;
V_9 &= ~ V_160 ;
V_9 |= V_161 | V_8 -> V_162 ;
F_31 (port, &pcie->ports, list)
V_9 &= ~ F_69 ( V_52 -> V_53 ) ;
F_4 ( V_8 , V_9 , V_159 ) ;
if ( V_62 -> V_163 ) {
V_9 = F_6 ( V_8 , V_164 ) ;
V_9 &= ~ V_165 ;
F_4 ( V_8 , V_9 , V_164 ) ;
} else {
V_9 = F_6 ( V_8 , V_164 ) ;
V_9 |= V_165 ;
F_4 ( V_8 , V_9 , V_164 ) ;
}
V_28 = F_66 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_27 , V_28 ) ;
return V_28 ;
}
F_70 ( V_8 -> V_166 ) ;
V_9 = F_6 ( V_8 , V_167 ) ;
V_9 |= V_168 ;
F_4 ( V_8 , V_9 , V_167 ) ;
V_9 = V_169 | V_170 |
V_171 | V_172 |
V_173 | V_174 ;
if ( V_62 -> V_175 )
V_9 |= V_176 ;
F_4 ( V_8 , V_9 , V_177 ) ;
F_4 ( V_8 , 0xffffffff , V_178 ) ;
F_4 ( V_8 , V_179 , V_180 ) ;
F_4 ( V_8 , 0 , V_181 ) ;
return 0 ;
}
static void F_71 ( struct V_4 * V_8 )
{
int V_28 ;
V_28 = F_67 ( V_8 ) ;
if ( V_28 < 0 )
F_20 ( V_8 -> V_41 , L_28 , V_28 ) ;
F_72 ( V_8 -> V_166 ) ;
F_72 ( V_8 -> V_182 ) ;
F_72 ( V_8 -> V_183 ) ;
F_73 ( V_184 ) ;
V_28 = F_74 ( V_8 -> V_185 , V_8 -> V_186 ) ;
if ( V_28 < 0 )
F_75 ( V_8 -> V_41 , L_29 , V_28 ) ;
}
static int F_76 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
int V_28 ;
F_72 ( V_8 -> V_166 ) ;
F_72 ( V_8 -> V_182 ) ;
F_72 ( V_8 -> V_183 ) ;
F_73 ( V_184 ) ;
V_28 = F_77 ( V_8 -> V_185 , V_8 -> V_186 ) ;
if ( V_28 < 0 )
F_20 ( V_8 -> V_41 , L_30 , V_28 ) ;
V_28 = F_78 ( V_184 ,
V_8 -> V_187 ,
V_8 -> V_183 ) ;
if ( V_28 ) {
F_20 ( V_8 -> V_41 , L_31 , V_28 ) ;
return V_28 ;
}
F_70 ( V_8 -> V_182 ) ;
V_28 = F_79 ( V_8 -> V_188 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_32 , V_28 ) ;
return V_28 ;
}
if ( V_62 -> V_189 ) {
V_28 = F_79 ( V_8 -> V_190 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_33 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_79 ( V_8 -> V_191 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_34 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_80 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
V_8 -> V_187 = F_81 ( V_8 -> V_41 , L_35 ) ;
if ( F_24 ( V_8 -> V_187 ) )
return F_25 ( V_8 -> V_187 ) ;
V_8 -> V_188 = F_81 ( V_8 -> V_41 , L_36 ) ;
if ( F_24 ( V_8 -> V_188 ) )
return F_25 ( V_8 -> V_188 ) ;
V_8 -> V_191 = F_81 ( V_8 -> V_41 , L_37 ) ;
if ( F_24 ( V_8 -> V_191 ) )
return F_25 ( V_8 -> V_191 ) ;
if ( V_62 -> V_189 ) {
V_8 -> V_190 = F_81 ( V_8 -> V_41 , L_38 ) ;
if ( F_24 ( V_8 -> V_190 ) )
return F_25 ( V_8 -> V_190 ) ;
}
return 0 ;
}
static int F_82 ( struct V_4 * V_8 )
{
V_8 -> V_183 = F_83 ( V_8 -> V_41 , L_35 ) ;
if ( F_24 ( V_8 -> V_183 ) )
return F_25 ( V_8 -> V_183 ) ;
V_8 -> V_182 = F_83 ( V_8 -> V_41 , L_36 ) ;
if ( F_24 ( V_8 -> V_182 ) )
return F_25 ( V_8 -> V_182 ) ;
V_8 -> V_166 = F_83 ( V_8 -> V_41 , L_39 ) ;
if ( F_24 ( V_8 -> V_166 ) )
return F_25 ( V_8 -> V_166 ) ;
return 0 ;
}
static int F_84 ( struct V_4 * V_8 )
{
int V_28 ;
V_8 -> V_153 = F_85 ( V_8 -> V_41 , L_40 ) ;
if ( F_24 ( V_8 -> V_153 ) ) {
V_28 = F_25 ( V_8 -> V_153 ) ;
F_20 ( V_8 -> V_41 , L_41 , V_28 ) ;
return V_28 ;
}
V_28 = F_86 ( V_8 -> V_153 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_42 , V_28 ) ;
return V_28 ;
}
V_8 -> V_152 = true ;
return 0 ;
}
static struct V_153 * F_87 ( struct V_150 * V_41 ,
struct V_192 * V_193 ,
const char * V_194 ,
unsigned int V_53 )
{
struct V_153 * V_153 ;
char * V_195 ;
V_195 = F_88 ( V_29 , L_43 , V_194 , V_53 ) ;
if ( ! V_195 )
return F_16 ( - V_30 ) ;
V_153 = F_89 ( V_41 , V_193 , V_195 ) ;
F_22 ( V_195 ) ;
if ( F_24 ( V_153 ) && F_25 ( V_153 ) == - V_196 )
V_153 = NULL ;
return V_153 ;
}
static int F_90 ( struct V_51 * V_52 )
{
struct V_150 * V_41 = V_52 -> V_8 -> V_41 ;
struct V_153 * V_153 ;
unsigned int V_27 ;
int V_28 ;
V_52 -> V_39 = F_91 ( V_41 , sizeof( V_153 ) , V_52 -> V_151 , V_29 ) ;
if ( ! V_52 -> V_39 )
return - V_30 ;
for ( V_27 = 0 ; V_27 < V_52 -> V_151 ; V_27 ++ ) {
V_153 = F_87 ( V_41 , V_52 -> V_193 , L_40 , V_27 ) ;
if ( F_24 ( V_153 ) ) {
F_20 ( V_41 , L_44 , V_27 ,
F_25 ( V_153 ) ) ;
return F_25 ( V_153 ) ;
}
V_28 = F_86 ( V_153 ) ;
if ( V_28 < 0 ) {
F_20 ( V_41 , L_45 , V_27 ,
V_28 ) ;
return V_28 ;
}
V_52 -> V_39 [ V_27 ] = V_153 ;
}
return 0 ;
}
static int F_92 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
struct V_192 * V_193 = V_8 -> V_41 -> V_197 ;
struct V_51 * V_52 ;
int V_28 ;
if ( ! V_62 -> V_163 || F_93 ( V_193 , L_46 , NULL ) != NULL )
return F_84 ( V_8 ) ;
F_31 (port, &pcie->ports, list) {
V_28 = F_90 ( V_52 ) ;
if ( V_28 < 0 )
return V_28 ;
}
return 0 ;
}
static int F_94 ( struct V_4 * V_8 )
{
struct V_198 * V_84 = F_95 ( V_8 -> V_41 ) ;
struct V_199 * V_12 , * V_11 , * V_200 ;
int V_28 ;
V_28 = F_80 ( V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_47 , V_28 ) ;
return V_28 ;
}
V_28 = F_82 ( V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_48 , V_28 ) ;
return V_28 ;
}
V_28 = F_92 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_49 , V_28 ) ;
return V_28 ;
}
V_28 = F_76 ( V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_50 , V_28 ) ;
return V_28 ;
}
V_12 = F_96 ( V_84 , V_201 , L_51 ) ;
V_8 -> V_12 = F_97 ( & V_84 -> V_41 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_25 ( V_8 -> V_12 ) ;
goto V_202;
}
V_11 = F_96 ( V_84 , V_201 , L_36 ) ;
V_8 -> V_11 = F_97 ( & V_84 -> V_41 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_25 ( V_8 -> V_11 ) ;
goto V_202;
}
V_200 = F_96 ( V_84 , V_201 , L_52 ) ;
if ( ! V_200 ) {
V_28 = - V_203 ;
goto V_202;
}
V_8 -> V_24 = F_98 ( V_8 -> V_41 , V_200 -> V_25 ,
F_40 ( V_200 ) , V_200 -> V_195 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_203 ;
goto V_202;
}
V_28 = F_99 ( V_84 , L_53 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_54 , V_28 ) ;
goto V_202;
}
V_8 -> V_86 = V_28 ;
V_28 = F_100 ( V_8 -> V_86 , F_53 , V_204 , L_55 , V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_56 , V_28 ) ;
goto V_202;
}
return 0 ;
V_202:
F_71 ( V_8 ) ;
return V_28 ;
}
static int F_101 ( struct V_4 * V_8 )
{
int V_28 ;
if ( V_8 -> V_86 > 0 )
F_102 ( V_8 -> V_86 , V_8 ) ;
F_71 ( V_8 ) ;
V_28 = F_103 ( V_8 -> V_153 ) ;
if ( V_28 < 0 )
F_20 ( V_8 -> V_41 , L_57 , V_28 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_3 )
{
int V_205 ;
F_105 ( & V_3 -> V_206 ) ;
V_205 = F_106 ( V_3 -> V_207 , V_208 ) ;
if ( V_205 < V_208 )
F_107 ( V_205 , V_3 -> V_207 ) ;
else
V_205 = - V_209 ;
F_108 ( & V_3 -> V_206 ) ;
return V_205 ;
}
static void F_109 ( struct V_1 * V_3 , unsigned long V_86 )
{
struct V_150 * V_41 = V_3 -> V_3 . V_41 ;
F_105 ( & V_3 -> V_206 ) ;
if ( ! F_110 ( V_86 , V_3 -> V_207 ) )
F_20 ( V_41 , L_58 , V_86 ) ;
else
F_111 ( V_86 , V_3 -> V_207 ) ;
F_108 ( & V_3 -> V_206 ) ;
}
static T_6 F_112 ( int V_86 , void * V_210 )
{
struct V_4 * V_8 = V_210 ;
struct V_1 * V_205 = & V_8 -> V_205 ;
unsigned int V_27 , V_211 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_212 = F_6 ( V_8 , V_213 + V_27 * 4 ) ;
while ( V_212 ) {
unsigned int V_10 = F_113 ( & V_212 , 32 ) ;
unsigned int V_53 = V_27 * 32 + V_10 ;
unsigned int V_86 ;
F_4 ( V_8 , 1 << V_10 , V_213 + V_27 * 4 ) ;
V_86 = F_114 ( V_205 -> V_214 , V_53 ) ;
if ( V_86 ) {
if ( F_110 ( V_53 , V_205 -> V_207 ) )
F_115 ( V_86 ) ;
else
F_116 ( V_8 -> V_41 , L_59 ) ;
} else {
F_116 ( V_8 -> V_41 , L_60 ) ;
}
V_212 = F_6 ( V_8 , V_213 + V_27 * 4 ) ;
V_211 ++ ;
}
}
return V_211 > 0 ? V_102 : V_95 ;
}
static int F_117 ( struct V_2 * V_3 ,
struct V_69 * V_84 , struct V_215 * V_216 )
{
struct V_1 * V_205 = F_1 ( V_3 ) ;
struct V_217 V_218 ;
unsigned int V_86 ;
int V_219 ;
V_219 = F_104 ( V_205 ) ;
if ( V_219 < 0 )
return V_219 ;
V_86 = F_118 ( V_205 -> V_214 , V_219 ) ;
if ( ! V_86 ) {
F_109 ( V_205 , V_219 ) ;
return - V_220 ;
}
F_119 ( V_86 , V_216 ) ;
V_218 . V_221 = F_120 ( ( void * ) V_205 -> V_222 ) ;
V_218 . V_223 = 0 ;
V_218 . V_210 = V_219 ;
F_121 ( V_86 , & V_218 ) ;
return 0 ;
}
static void F_122 ( struct V_2 * V_3 ,
unsigned int V_86 )
{
struct V_1 * V_205 = F_1 ( V_3 ) ;
struct V_224 * V_225 = F_123 ( V_86 ) ;
T_8 V_219 = F_124 ( V_225 ) ;
F_125 ( V_86 ) ;
F_109 ( V_205 , V_219 ) ;
}
static int F_126 ( struct V_226 * V_214 , unsigned int V_86 ,
T_8 V_219 )
{
F_127 ( V_86 , & V_227 , V_228 ) ;
F_128 ( V_86 , V_214 -> V_229 ) ;
F_51 () ;
return 0 ;
}
static int F_129 ( struct V_4 * V_8 )
{
struct V_198 * V_84 = F_95 ( V_8 -> V_41 ) ;
const struct V_61 * V_62 = V_8 -> V_63 ;
struct V_1 * V_205 = & V_8 -> V_205 ;
unsigned long V_54 ;
int V_28 ;
T_1 V_212 ;
F_130 ( & V_205 -> V_206 ) ;
V_205 -> V_3 . V_41 = V_8 -> V_41 ;
V_205 -> V_3 . V_230 = F_117 ;
V_205 -> V_3 . V_231 = F_122 ;
V_205 -> V_214 = F_131 ( V_8 -> V_41 -> V_197 , V_208 ,
& V_232 , & V_205 -> V_3 ) ;
if ( ! V_205 -> V_214 ) {
F_20 ( & V_84 -> V_41 , L_61 ) ;
return - V_30 ;
}
V_28 = F_99 ( V_84 , L_62 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_54 , V_28 ) ;
goto V_28;
}
V_205 -> V_86 = V_28 ;
V_28 = F_100 ( V_205 -> V_86 , F_112 , V_233 ,
V_227 . V_195 , V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_63 , V_28 ) ;
goto V_28;
}
V_205 -> V_222 = F_132 ( V_29 , 0 ) ;
V_54 = F_120 ( ( void * ) V_205 -> V_222 ) ;
F_4 ( V_8 , V_54 >> V_62 -> V_234 , V_128 ) ;
F_4 ( V_8 , V_54 , V_130 ) ;
F_4 ( V_8 , 1 , V_129 ) ;
F_4 ( V_8 , 0xffffffff , V_235 ) ;
F_4 ( V_8 , 0xffffffff , V_236 ) ;
F_4 ( V_8 , 0xffffffff , V_237 ) ;
F_4 ( V_8 , 0xffffffff , V_238 ) ;
F_4 ( V_8 , 0xffffffff , V_239 ) ;
F_4 ( V_8 , 0xffffffff , V_240 ) ;
F_4 ( V_8 , 0xffffffff , V_241 ) ;
F_4 ( V_8 , 0xffffffff , V_242 ) ;
V_212 = F_6 ( V_8 , V_180 ) ;
V_212 |= V_243 ;
F_4 ( V_8 , V_212 , V_180 ) ;
return 0 ;
V_28:
F_133 ( V_205 -> V_214 ) ;
return V_28 ;
}
static int F_134 ( struct V_4 * V_8 )
{
struct V_1 * V_205 = & V_8 -> V_205 ;
unsigned int V_27 , V_86 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_180 ) ;
V_9 &= ~ V_243 ;
F_4 ( V_8 , V_9 , V_180 ) ;
F_4 ( V_8 , 0 , V_235 ) ;
F_4 ( V_8 , 0 , V_236 ) ;
F_4 ( V_8 , 0 , V_237 ) ;
F_4 ( V_8 , 0 , V_238 ) ;
F_4 ( V_8 , 0 , V_239 ) ;
F_4 ( V_8 , 0 , V_240 ) ;
F_4 ( V_8 , 0 , V_241 ) ;
F_4 ( V_8 , 0 , V_242 ) ;
F_135 ( V_205 -> V_222 , 0 ) ;
if ( V_205 -> V_86 > 0 )
F_102 ( V_205 -> V_86 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_208 ; V_27 ++ ) {
V_86 = F_114 ( V_205 -> V_214 , V_27 ) ;
if ( V_86 > 0 )
F_125 ( V_86 ) ;
}
F_133 ( V_205 -> V_214 ) ;
return 0 ;
}
static int F_136 ( struct V_4 * V_8 , T_1 V_151 ,
T_1 * V_244 )
{
struct V_192 * V_193 = V_8 -> V_41 -> V_197 ;
if ( F_137 ( V_193 , L_64 ) ) {
switch ( V_151 ) {
case 0x0000104 :
F_116 ( V_8 -> V_41 , L_65 ) ;
* V_244 = V_245 ;
return 0 ;
case 0x0000102 :
F_116 ( V_8 -> V_41 , L_66 ) ;
* V_244 = V_246 ;
return 0 ;
}
} else if ( F_137 ( V_193 , L_67 ) ) {
switch ( V_151 ) {
case 0x00000204 :
F_116 ( V_8 -> V_41 , L_68 ) ;
* V_244 = V_247 ;
return 0 ;
case 0x00020202 :
F_116 ( V_8 -> V_41 , L_69 ) ;
* V_244 = V_248 ;
return 0 ;
case 0x00010104 :
F_116 ( V_8 -> V_41 , L_70 ) ;
* V_244 = V_249 ;
return 0 ;
}
} else if ( F_137 ( V_193 , L_71 ) ) {
switch ( V_151 ) {
case 0x00000004 :
F_116 ( V_8 -> V_41 , L_72 ) ;
* V_244 = V_250 ;
return 0 ;
case 0x00000202 :
F_116 ( V_8 -> V_41 , L_73 ) ;
* V_244 = V_251 ;
return 0 ;
}
}
return - V_220 ;
}
static bool F_138 ( struct V_192 * V_193 ,
struct V_252 * V_186 ,
unsigned int V_185 )
{
char V_253 [ 32 ] ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_185 ; V_27 ++ ) {
snprintf ( V_253 , 32 , L_74 , V_186 [ V_27 ] . V_254 ) ;
if ( F_93 ( V_193 , V_253 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_139 ( struct V_4 * V_8 )
{
struct V_192 * V_193 = V_8 -> V_41 -> V_197 ;
if ( F_137 ( V_193 , L_67 ) )
V_8 -> V_185 = 3 ;
else if ( F_137 ( V_193 , L_71 ) )
V_8 -> V_185 = 2 ;
if ( V_8 -> V_185 == 0 ) {
F_20 ( V_8 -> V_41 , L_75 ,
V_193 -> V_255 ) ;
return - V_196 ;
}
V_8 -> V_186 = F_91 ( V_8 -> V_41 , V_8 -> V_185 ,
sizeof( * V_8 -> V_186 ) ,
V_29 ) ;
if ( ! V_8 -> V_186 )
return - V_30 ;
V_8 -> V_186 [ 0 ] . V_254 = L_76 ;
V_8 -> V_186 [ 1 ] . V_254 = L_77 ;
if ( V_8 -> V_185 > 2 )
V_8 -> V_186 [ 2 ] . V_254 = L_78 ;
return F_140 ( V_8 -> V_41 , V_8 -> V_185 ,
V_8 -> V_186 ) ;
}
static int F_141 ( struct V_4 * V_8 , T_1 V_256 )
{
struct V_192 * V_193 = V_8 -> V_41 -> V_197 ;
unsigned int V_27 = 0 ;
if ( F_137 ( V_193 , L_64 ) ) {
V_8 -> V_185 = 7 ;
V_8 -> V_186 = F_91 ( V_8 -> V_41 , V_8 -> V_185 ,
sizeof( * V_8 -> V_186 ) ,
V_29 ) ;
if ( ! V_8 -> V_186 )
return - V_30 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_79 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_80 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_81 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_82 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_83 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_84 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_85 ;
} else if ( F_137 ( V_193 , L_67 ) ) {
bool V_257 = false , V_258 = false ;
if ( V_256 & 0x0f )
V_257 = true ;
if ( V_256 & 0x30 )
V_258 = true ;
V_8 -> V_185 = 4 + ( V_257 ? 2 : 0 ) +
( V_258 ? 2 : 0 ) ;
V_8 -> V_186 = F_91 ( V_8 -> V_41 , V_8 -> V_185 ,
sizeof( * V_8 -> V_186 ) ,
V_29 ) ;
if ( ! V_8 -> V_186 )
return - V_30 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_81 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_82 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_84 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_86 ;
if ( V_257 ) {
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_87 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_88 ;
}
if ( V_258 ) {
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_89 ;
V_8 -> V_186 [ V_27 ++ ] . V_254 = L_90 ;
}
} else if ( F_137 ( V_193 , L_71 ) ) {
V_8 -> V_185 = 5 ;
V_8 -> V_186 = F_91 ( V_8 -> V_41 , V_8 -> V_185 ,
sizeof( * V_8 -> V_186 ) ,
V_29 ) ;
if ( ! V_8 -> V_186 )
return - V_30 ;
V_8 -> V_186 [ 0 ] . V_254 = L_91 ;
V_8 -> V_186 [ 1 ] . V_254 = L_92 ;
V_8 -> V_186 [ 2 ] . V_254 = L_81 ;
V_8 -> V_186 [ 3 ] . V_254 = L_86 ;
V_8 -> V_186 [ 4 ] . V_254 = L_93 ;
}
if ( F_138 ( V_8 -> V_41 -> V_197 , V_8 -> V_186 ,
V_8 -> V_185 ) )
return F_140 ( V_8 -> V_41 , V_8 -> V_185 ,
V_8 -> V_186 ) ;
F_116 ( V_8 -> V_41 , L_94 ) ;
F_41 ( V_8 -> V_41 , V_8 -> V_186 ) ;
V_8 -> V_185 = 0 ;
return F_139 ( V_8 ) ;
}
static int F_142 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
struct V_192 * V_193 = V_8 -> V_41 -> V_197 , * V_52 ;
struct V_259 V_260 ;
struct V_261 V_262 ;
T_1 V_151 = 0 , V_263 = 0 ;
unsigned int V_264 = 0 ;
struct V_199 V_200 ;
int V_28 ;
memset ( & V_8 -> V_78 , 0 , sizeof( V_8 -> V_78 ) ) ;
V_8 -> V_78 . V_265 = V_201 ;
V_8 -> V_78 . V_195 = V_193 -> V_255 ;
V_8 -> V_78 . V_25 = ~ 0 ;
V_8 -> V_78 . V_266 = 0 ;
if ( F_143 ( & V_260 , V_193 ) ) {
F_20 ( V_8 -> V_41 , L_95 ) ;
return - V_220 ;
}
F_144 (&parser, &range) {
V_28 = F_145 ( & V_262 , V_193 , & V_200 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_200 . V_265 & V_267 ) {
case V_268 :
V_8 -> V_10 . V_77 = V_200 . V_25 - V_262 . V_269 ;
memcpy ( & V_8 -> V_80 , & V_200 , sizeof( V_200 ) ) ;
V_8 -> V_80 . V_195 = V_193 -> V_255 ;
V_8 -> V_77 . V_25 = V_262 . V_270 ;
V_8 -> V_77 . V_266 = V_262 . V_270 + V_262 . V_104 - 1 ;
V_8 -> V_77 . V_265 = V_201 ;
V_8 -> V_77 . V_195 = L_96 ;
memcpy ( & V_200 , & V_8 -> V_77 , sizeof( V_200 ) ) ;
break;
case V_201 :
V_8 -> V_10 . V_75 = V_200 . V_25 - V_262 . V_269 ;
if ( V_200 . V_265 & V_271 ) {
memcpy ( & V_8 -> V_81 , & V_200 , sizeof( V_200 ) ) ;
V_8 -> V_81 . V_195 = L_97 ;
} else {
memcpy ( & V_8 -> V_75 , & V_200 , sizeof( V_200 ) ) ;
V_8 -> V_75 . V_195 = L_98 ;
}
break;
}
if ( V_200 . V_25 <= V_8 -> V_78 . V_25 )
V_8 -> V_78 . V_25 = V_200 . V_25 ;
if ( V_200 . V_266 >= V_8 -> V_78 . V_266 )
V_8 -> V_78 . V_266 = V_200 . V_266 ;
}
V_28 = F_46 ( V_8 -> V_41 , & V_272 , & V_8 -> V_78 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_146 ( V_193 , & V_8 -> V_83 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_99 ,
V_28 ) ;
V_8 -> V_83 . V_195 = V_193 -> V_195 ;
V_8 -> V_83 . V_25 = 0 ;
V_8 -> V_83 . V_266 = 0xff ;
V_8 -> V_83 . V_265 = V_273 ;
}
F_147 (np, port) {
struct V_51 * V_274 ;
unsigned int V_53 ;
T_1 V_9 ;
V_28 = F_148 ( V_52 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_100 ,
V_28 ) ;
return V_28 ;
}
V_53 = F_11 ( V_28 ) ;
if ( V_53 < 1 || V_53 > V_62 -> V_146 ) {
F_20 ( V_8 -> V_41 , L_101 , V_53 ) ;
return - V_220 ;
}
V_53 -- ;
V_28 = F_149 ( V_52 , L_102 , & V_9 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_103 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_20 ( V_8 -> V_41 , L_104 , V_9 ) ;
return - V_220 ;
}
V_151 |= V_9 << ( V_53 << 3 ) ;
if ( ! F_150 ( V_52 ) ) {
V_264 += V_9 ;
continue;
}
V_263 |= ( ( 1 << V_9 ) - 1 ) << V_264 ;
V_264 += V_9 ;
V_274 = F_151 ( V_8 -> V_41 , sizeof( * V_274 ) , V_29 ) ;
if ( ! V_274 )
return - V_30 ;
V_28 = F_152 ( V_52 , 0 , & V_274 -> V_68 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_100 ,
V_28 ) ;
return V_28 ;
}
F_17 ( & V_274 -> V_31 ) ;
V_274 -> V_53 = V_53 ;
V_274 -> V_151 = V_9 ;
V_274 -> V_8 = V_8 ;
V_274 -> V_193 = V_52 ;
V_274 -> V_54 = F_97 ( V_8 -> V_41 , & V_274 -> V_68 ) ;
if ( F_24 ( V_274 -> V_54 ) )
return F_25 ( V_274 -> V_54 ) ;
F_26 ( & V_274 -> V_31 , & V_8 -> V_275 ) ;
}
V_28 = F_136 ( V_8 , V_151 , & V_8 -> V_162 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_105 ) ;
return V_28 ;
}
V_28 = F_141 ( V_8 , V_263 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
static bool F_153 ( struct V_51 * V_52 )
{
unsigned int V_276 = 3 ;
unsigned long V_9 ;
V_9 = F_7 ( V_52 -> V_54 + V_277 ) ;
V_9 &= ~ V_278 ;
V_9 |= V_279 ;
F_5 ( V_9 , V_52 -> V_54 + V_277 ) ;
do {
unsigned int V_131 = V_280 ;
do {
V_9 = F_7 ( V_52 -> V_54 + V_281 ) ;
if ( V_9 & V_282 )
break;
F_34 ( 1000 , 2000 ) ;
} while ( -- V_131 );
if ( ! V_131 ) {
F_20 ( V_52 -> V_8 -> V_41 , L_106 ,
V_52 -> V_53 ) ;
goto V_283;
}
V_131 = V_280 ;
do {
V_9 = F_7 ( V_52 -> V_54 + V_284 ) ;
if ( V_9 & V_285 )
return true ;
F_34 ( 1000 , 2000 ) ;
} while ( -- V_131 );
V_283:
F_33 ( V_52 ) ;
} while ( -- V_276 );
return false ;
}
static int F_154 ( struct V_4 * V_8 )
{
struct V_51 * V_52 , * V_49 ;
struct V_286 V_287 ;
F_28 (port, tmp, &pcie->ports, list) {
F_116 ( V_8 -> V_41 , L_107 ,
V_52 -> V_53 , V_52 -> V_151 ) ;
F_35 ( V_52 ) ;
if ( F_153 ( V_52 ) )
continue;
F_116 ( V_8 -> V_41 , L_108 , V_52 -> V_53 ) ;
F_36 ( V_52 ) ;
F_37 ( V_52 ) ;
}
memset ( & V_287 , 0 , sizeof( V_287 ) ) ;
#ifdef F_155
V_287 . V_288 = & V_8 -> V_205 . V_3 ;
#endif
V_287 . V_289 = 1 ;
V_287 . V_7 = ( void * * ) & V_8 ;
V_287 . V_290 = F_45 ;
V_287 . V_291 = F_50 ;
V_287 . V_292 = & V_293 ;
F_156 ( V_8 -> V_41 , & V_287 ) ;
return 0 ;
}
static void * F_157 ( struct V_294 * V_295 , T_9 * V_296 )
{
struct V_4 * V_8 = V_295 -> V_297 ;
if ( F_158 ( & V_8 -> V_275 ) )
return NULL ;
F_159 ( V_295 , L_109 ) ;
return F_160 ( & V_8 -> V_275 , * V_296 ) ;
}
static void * F_161 ( struct V_294 * V_295 , void * V_298 , T_9 * V_296 )
{
struct V_4 * V_8 = V_295 -> V_297 ;
return F_162 ( V_298 , & V_8 -> V_275 , V_296 ) ;
}
static void F_163 ( struct V_294 * V_295 , void * V_298 )
{
}
static int F_164 ( struct V_294 * V_295 , void * V_298 )
{
bool V_299 = false , V_300 = false ;
struct V_51 * V_52 ;
unsigned int V_9 ;
V_52 = F_165 ( V_298 , struct V_51 , V_31 ) ;
V_9 = F_7 ( V_52 -> V_54 + V_281 ) ;
if ( V_9 & V_282 )
V_299 = true ;
V_9 = F_7 ( V_52 -> V_54 + V_284 ) ;
if ( V_9 & V_285 )
V_300 = true ;
F_159 ( V_295 , L_110 , V_52 -> V_53 ) ;
if ( V_299 )
F_159 ( V_295 , L_111 ) ;
if ( V_300 ) {
if ( V_299 )
F_159 ( V_295 , L_112 ) ;
F_159 ( V_295 , L_113 ) ;
}
F_159 ( V_295 , L_114 ) ;
return 0 ;
}
static int F_166 ( struct V_301 * V_301 , struct V_302 * V_302 )
{
struct V_4 * V_8 = V_301 -> V_303 ;
struct V_294 * V_295 ;
int V_28 ;
V_28 = F_167 ( V_302 , & V_304 ) ;
if ( V_28 )
return V_28 ;
V_295 = V_302 -> V_7 ;
V_295 -> V_297 = V_8 ;
return 0 ;
}
static int F_168 ( struct V_4 * V_8 )
{
struct V_305 * V_302 ;
V_8 -> V_306 = F_169 ( L_40 , NULL ) ;
if ( ! V_8 -> V_306 )
return - V_30 ;
V_302 = F_170 ( L_115 , V_307 | V_308 , V_8 -> V_306 ,
V_8 , & V_309 ) ;
if ( ! V_302 )
goto remove;
return 0 ;
remove:
F_171 ( V_8 -> V_306 ) ;
V_8 -> V_306 = NULL ;
return - V_30 ;
}
static int F_172 ( struct V_198 * V_84 )
{
const struct V_310 * V_311 ;
struct V_4 * V_8 ;
int V_28 ;
V_311 = F_173 ( V_312 , & V_84 -> V_41 ) ;
if ( ! V_311 )
return - V_196 ;
V_8 = F_151 ( & V_84 -> V_41 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_17 ( & V_8 -> V_47 ) ;
F_17 ( & V_8 -> V_275 ) ;
V_8 -> V_63 = V_311 -> V_210 ;
V_8 -> V_41 = & V_84 -> V_41 ;
V_28 = F_142 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_313 = 0 ;
V_28 = F_94 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_116 , V_28 ) ;
return V_28 ;
}
V_28 = F_68 ( V_8 ) ;
if ( V_28 )
goto V_314;
F_56 ( V_8 ) ;
if ( F_174 ( F_155 ) ) {
V_28 = F_129 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 ,
L_117 ,
V_28 ) ;
goto V_314;
}
}
V_28 = F_154 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_118 , V_28 ) ;
goto V_315;
}
if ( F_174 ( V_316 ) ) {
V_28 = F_168 ( V_8 ) ;
if ( V_28 < 0 )
F_20 ( & V_84 -> V_41 , L_119 ,
V_28 ) ;
}
F_175 ( V_84 , V_8 ) ;
return 0 ;
V_315:
if ( F_174 ( F_155 ) )
F_134 ( V_8 ) ;
V_314:
F_101 ( V_8 ) ;
return V_28 ;
}
