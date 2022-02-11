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
struct V_51 * V_52 ;
unsigned long V_9 ;
int V_28 ;
if ( V_8 -> V_150 ) {
V_9 = F_6 ( V_8 , V_151 ) ;
V_9 &= ~ V_152 ;
V_9 |= V_153 ;
F_4 ( V_8 , V_9 , V_151 ) ;
}
if ( V_62 -> V_154 )
F_4 ( V_8 , 0 , V_155 ) ;
V_9 = F_6 ( V_8 , V_156 ) ;
V_9 &= ~ V_157 ;
V_9 |= V_158 | V_8 -> V_159 ;
F_31 (port, &pcie->ports, list)
V_9 &= ~ F_62 ( V_52 -> V_53 ) ;
F_4 ( V_8 , V_9 , V_156 ) ;
if ( V_62 -> V_160 ) {
V_9 = F_6 ( V_8 , V_161 ) ;
V_9 &= ~ V_162 ;
F_4 ( V_8 , V_9 , V_161 ) ;
} else {
V_9 = F_6 ( V_8 , V_161 ) ;
V_9 |= V_162 ;
F_4 ( V_8 , V_9 , V_161 ) ;
}
if ( ! V_8 -> V_150 )
V_28 = F_60 ( V_8 ) ;
else
V_28 = F_63 ( V_8 -> V_150 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_21 , V_28 ) ;
return V_28 ;
}
F_64 ( V_8 -> V_163 ) ;
V_9 = F_6 ( V_8 , V_164 ) ;
V_9 |= V_165 ;
F_4 ( V_8 , V_9 , V_164 ) ;
V_9 = V_166 | V_167 |
V_168 | V_169 |
V_170 | V_171 ;
if ( V_62 -> V_172 )
V_9 |= V_173 ;
F_4 ( V_8 , V_9 , V_174 ) ;
F_4 ( V_8 , 0xffffffff , V_175 ) ;
F_4 ( V_8 , V_176 , V_177 ) ;
F_4 ( V_8 , 0 , V_178 ) ;
return 0 ;
}
static void F_65 ( struct V_4 * V_8 )
{
int V_28 ;
V_28 = F_66 ( V_8 -> V_150 ) ;
if ( V_28 < 0 )
F_67 ( V_8 -> V_41 , L_22 , V_28 ) ;
F_68 ( V_8 -> V_163 ) ;
F_68 ( V_8 -> V_179 ) ;
F_68 ( V_8 -> V_180 ) ;
F_69 ( V_181 ) ;
V_28 = F_70 ( V_8 -> V_182 , V_8 -> V_183 ) ;
if ( V_28 < 0 )
F_67 ( V_8 -> V_41 , L_23 , V_28 ) ;
}
static int F_71 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
int V_28 ;
F_68 ( V_8 -> V_163 ) ;
F_68 ( V_8 -> V_179 ) ;
F_68 ( V_8 -> V_180 ) ;
F_69 ( V_181 ) ;
V_28 = F_72 ( V_8 -> V_182 , V_8 -> V_183 ) ;
if ( V_28 < 0 )
F_20 ( V_8 -> V_41 , L_24 , V_28 ) ;
V_28 = F_73 ( V_181 ,
V_8 -> V_184 ,
V_8 -> V_180 ) ;
if ( V_28 ) {
F_20 ( V_8 -> V_41 , L_25 , V_28 ) ;
return V_28 ;
}
F_64 ( V_8 -> V_179 ) ;
V_28 = F_74 ( V_8 -> V_185 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_26 , V_28 ) ;
return V_28 ;
}
if ( V_62 -> V_186 ) {
V_28 = F_74 ( V_8 -> V_187 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_27 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_74 ( V_8 -> V_188 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_28 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_75 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
V_8 -> V_184 = F_76 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_184 ) )
return F_25 ( V_8 -> V_184 ) ;
V_8 -> V_185 = F_76 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_185 ) )
return F_25 ( V_8 -> V_185 ) ;
V_8 -> V_188 = F_76 ( V_8 -> V_41 , L_31 ) ;
if ( F_24 ( V_8 -> V_188 ) )
return F_25 ( V_8 -> V_188 ) ;
if ( V_62 -> V_186 ) {
V_8 -> V_187 = F_76 ( V_8 -> V_41 , L_32 ) ;
if ( F_24 ( V_8 -> V_187 ) )
return F_25 ( V_8 -> V_187 ) ;
}
return 0 ;
}
static int F_77 ( struct V_4 * V_8 )
{
V_8 -> V_180 = F_78 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_180 ) )
return F_25 ( V_8 -> V_180 ) ;
V_8 -> V_179 = F_78 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_179 ) )
return F_25 ( V_8 -> V_179 ) ;
V_8 -> V_163 = F_78 ( V_8 -> V_41 , L_33 ) ;
if ( F_24 ( V_8 -> V_163 ) )
return F_25 ( V_8 -> V_163 ) ;
return 0 ;
}
static int F_79 ( struct V_4 * V_8 )
{
struct V_189 * V_84 = F_80 ( V_8 -> V_41 ) ;
struct V_190 * V_12 , * V_11 , * V_191 ;
int V_28 ;
V_28 = F_75 ( V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_34 , V_28 ) ;
return V_28 ;
}
V_28 = F_77 ( V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_35 , V_28 ) ;
return V_28 ;
}
V_8 -> V_150 = F_81 ( V_8 -> V_41 , L_36 ) ;
if ( F_24 ( V_8 -> V_150 ) ) {
V_28 = F_25 ( V_8 -> V_150 ) ;
F_20 ( & V_84 -> V_41 , L_37 , V_28 ) ;
return V_28 ;
}
V_28 = F_82 ( V_8 -> V_150 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_38 , V_28 ) ;
return V_28 ;
}
V_28 = F_71 ( V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_39 , V_28 ) ;
return V_28 ;
}
V_12 = F_83 ( V_84 , V_192 , L_40 ) ;
V_8 -> V_12 = F_84 ( & V_84 -> V_41 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_25 ( V_8 -> V_12 ) ;
goto V_193;
}
V_11 = F_83 ( V_84 , V_192 , L_30 ) ;
V_8 -> V_11 = F_84 ( & V_84 -> V_41 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_25 ( V_8 -> V_11 ) ;
goto V_193;
}
V_191 = F_83 ( V_84 , V_192 , L_41 ) ;
if ( ! V_191 ) {
V_28 = - V_194 ;
goto V_193;
}
V_8 -> V_24 = F_85 ( V_8 -> V_41 , V_191 -> V_25 ,
F_40 ( V_191 ) , V_191 -> V_195 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_194 ;
goto V_193;
}
V_28 = F_86 ( V_84 , L_42 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_43 , V_28 ) ;
goto V_193;
}
V_8 -> V_86 = V_28 ;
V_28 = F_87 ( V_8 -> V_86 , F_53 , V_196 , L_44 , V_8 ) ;
if ( V_28 ) {
F_20 ( & V_84 -> V_41 , L_45 , V_28 ) ;
goto V_193;
}
return 0 ;
V_193:
F_65 ( V_8 ) ;
return V_28 ;
}
static int F_88 ( struct V_4 * V_8 )
{
int V_28 ;
if ( V_8 -> V_86 > 0 )
F_89 ( V_8 -> V_86 , V_8 ) ;
F_65 ( V_8 ) ;
V_28 = F_90 ( V_8 -> V_150 ) ;
if ( V_28 < 0 )
F_20 ( V_8 -> V_41 , L_46 , V_28 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_3 )
{
int V_197 ;
F_92 ( & V_3 -> V_198 ) ;
V_197 = F_93 ( V_3 -> V_199 , V_200 ) ;
if ( V_197 < V_200 )
F_94 ( V_197 , V_3 -> V_199 ) ;
else
V_197 = - V_201 ;
F_95 ( & V_3 -> V_198 ) ;
return V_197 ;
}
static void F_96 ( struct V_1 * V_3 , unsigned long V_86 )
{
struct V_202 * V_41 = V_3 -> V_3 . V_41 ;
F_92 ( & V_3 -> V_198 ) ;
if ( ! F_97 ( V_86 , V_3 -> V_199 ) )
F_20 ( V_41 , L_47 , V_86 ) ;
else
F_98 ( V_86 , V_3 -> V_199 ) ;
F_95 ( & V_3 -> V_198 ) ;
}
static T_6 F_99 ( int V_86 , void * V_203 )
{
struct V_4 * V_8 = V_203 ;
struct V_1 * V_197 = & V_8 -> V_197 ;
unsigned int V_27 , V_204 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_205 = F_6 ( V_8 , V_206 + V_27 * 4 ) ;
while ( V_205 ) {
unsigned int V_10 = F_100 ( & V_205 , 32 ) ;
unsigned int V_53 = V_27 * 32 + V_10 ;
unsigned int V_86 ;
F_4 ( V_8 , 1 << V_10 , V_206 + V_27 * 4 ) ;
V_86 = F_101 ( V_197 -> V_207 , V_53 ) ;
if ( V_86 ) {
if ( F_97 ( V_53 , V_197 -> V_199 ) )
F_102 ( V_86 ) ;
else
F_103 ( V_8 -> V_41 , L_48 ) ;
} else {
F_103 ( V_8 -> V_41 , L_49 ) ;
}
V_205 = F_6 ( V_8 , V_206 + V_27 * 4 ) ;
V_204 ++ ;
}
}
return V_204 > 0 ? V_102 : V_95 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_69 * V_84 , struct V_208 * V_209 )
{
struct V_1 * V_197 = F_1 ( V_3 ) ;
struct V_210 V_211 ;
unsigned int V_86 ;
int V_212 ;
V_212 = F_91 ( V_197 ) ;
if ( V_212 < 0 )
return V_212 ;
V_86 = F_105 ( V_197 -> V_207 , V_212 ) ;
if ( ! V_86 ) {
F_96 ( V_197 , V_212 ) ;
return - V_213 ;
}
F_106 ( V_86 , V_209 ) ;
V_211 . V_214 = F_107 ( ( void * ) V_197 -> V_215 ) ;
V_211 . V_216 = 0 ;
V_211 . V_203 = V_212 ;
F_108 ( V_86 , & V_211 ) ;
return 0 ;
}
static void F_109 ( struct V_2 * V_3 ,
unsigned int V_86 )
{
struct V_1 * V_197 = F_1 ( V_3 ) ;
struct V_217 * V_218 = F_110 ( V_86 ) ;
T_8 V_212 = F_111 ( V_218 ) ;
F_112 ( V_86 ) ;
F_96 ( V_197 , V_212 ) ;
}
static int F_113 ( struct V_219 * V_207 , unsigned int V_86 ,
T_8 V_212 )
{
F_114 ( V_86 , & V_220 , V_221 ) ;
F_115 ( V_86 , V_207 -> V_222 ) ;
F_51 () ;
return 0 ;
}
static int F_116 ( struct V_4 * V_8 )
{
struct V_189 * V_84 = F_80 ( V_8 -> V_41 ) ;
const struct V_61 * V_62 = V_8 -> V_63 ;
struct V_1 * V_197 = & V_8 -> V_197 ;
unsigned long V_54 ;
int V_28 ;
T_1 V_205 ;
F_117 ( & V_197 -> V_198 ) ;
V_197 -> V_3 . V_41 = V_8 -> V_41 ;
V_197 -> V_3 . V_223 = F_104 ;
V_197 -> V_3 . V_224 = F_109 ;
V_197 -> V_207 = F_118 ( V_8 -> V_41 -> V_225 , V_200 ,
& V_226 , & V_197 -> V_3 ) ;
if ( ! V_197 -> V_207 ) {
F_20 ( & V_84 -> V_41 , L_50 ) ;
return - V_30 ;
}
V_28 = F_86 ( V_84 , L_51 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_43 , V_28 ) ;
goto V_28;
}
V_197 -> V_86 = V_28 ;
V_28 = F_87 ( V_197 -> V_86 , F_99 , V_227 ,
V_220 . V_195 , V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_52 , V_28 ) ;
goto V_28;
}
V_197 -> V_215 = F_119 ( V_29 , 0 ) ;
V_54 = F_107 ( ( void * ) V_197 -> V_215 ) ;
F_4 ( V_8 , V_54 >> V_62 -> V_228 , V_128 ) ;
F_4 ( V_8 , V_54 , V_130 ) ;
F_4 ( V_8 , 1 , V_129 ) ;
F_4 ( V_8 , 0xffffffff , V_229 ) ;
F_4 ( V_8 , 0xffffffff , V_230 ) ;
F_4 ( V_8 , 0xffffffff , V_231 ) ;
F_4 ( V_8 , 0xffffffff , V_232 ) ;
F_4 ( V_8 , 0xffffffff , V_233 ) ;
F_4 ( V_8 , 0xffffffff , V_234 ) ;
F_4 ( V_8 , 0xffffffff , V_235 ) ;
F_4 ( V_8 , 0xffffffff , V_236 ) ;
V_205 = F_6 ( V_8 , V_177 ) ;
V_205 |= V_237 ;
F_4 ( V_8 , V_205 , V_177 ) ;
return 0 ;
V_28:
F_120 ( V_197 -> V_207 ) ;
return V_28 ;
}
static int F_121 ( struct V_4 * V_8 )
{
struct V_1 * V_197 = & V_8 -> V_197 ;
unsigned int V_27 , V_86 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_177 ) ;
V_9 &= ~ V_237 ;
F_4 ( V_8 , V_9 , V_177 ) ;
F_4 ( V_8 , 0 , V_229 ) ;
F_4 ( V_8 , 0 , V_230 ) ;
F_4 ( V_8 , 0 , V_231 ) ;
F_4 ( V_8 , 0 , V_232 ) ;
F_4 ( V_8 , 0 , V_233 ) ;
F_4 ( V_8 , 0 , V_234 ) ;
F_4 ( V_8 , 0 , V_235 ) ;
F_4 ( V_8 , 0 , V_236 ) ;
F_122 ( V_197 -> V_215 , 0 ) ;
if ( V_197 -> V_86 > 0 )
F_89 ( V_197 -> V_86 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_200 ; V_27 ++ ) {
V_86 = F_101 ( V_197 -> V_207 , V_27 ) ;
if ( V_86 > 0 )
F_112 ( V_86 ) ;
}
F_120 ( V_197 -> V_207 ) ;
return 0 ;
}
static int F_123 ( struct V_4 * V_8 , T_1 V_238 ,
T_1 * V_239 )
{
struct V_240 * V_241 = V_8 -> V_41 -> V_225 ;
if ( F_124 ( V_241 , L_53 ) ) {
switch ( V_238 ) {
case 0x0000104 :
F_103 ( V_8 -> V_41 , L_54 ) ;
* V_239 = V_242 ;
return 0 ;
case 0x0000102 :
F_103 ( V_8 -> V_41 , L_55 ) ;
* V_239 = V_243 ;
return 0 ;
}
} else if ( F_124 ( V_241 , L_56 ) ) {
switch ( V_238 ) {
case 0x00000204 :
F_103 ( V_8 -> V_41 , L_57 ) ;
* V_239 = V_244 ;
return 0 ;
case 0x00020202 :
F_103 ( V_8 -> V_41 , L_58 ) ;
* V_239 = V_245 ;
return 0 ;
case 0x00010104 :
F_103 ( V_8 -> V_41 , L_59 ) ;
* V_239 = V_246 ;
return 0 ;
}
} else if ( F_124 ( V_241 , L_60 ) ) {
switch ( V_238 ) {
case 0x00000004 :
F_103 ( V_8 -> V_41 , L_61 ) ;
* V_239 = V_247 ;
return 0 ;
case 0x00000202 :
F_103 ( V_8 -> V_41 , L_62 ) ;
* V_239 = V_248 ;
return 0 ;
}
}
return - V_213 ;
}
static bool F_125 ( struct V_240 * V_241 ,
struct V_249 * V_183 ,
unsigned int V_182 )
{
char V_250 [ 32 ] ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_182 ; V_27 ++ ) {
snprintf ( V_250 , 32 , L_63 , V_183 [ V_27 ] . V_251 ) ;
if ( F_126 ( V_241 , V_250 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_127 ( struct V_4 * V_8 )
{
struct V_240 * V_241 = V_8 -> V_41 -> V_225 ;
if ( F_124 ( V_241 , L_56 ) )
V_8 -> V_182 = 3 ;
else if ( F_124 ( V_241 , L_60 ) )
V_8 -> V_182 = 2 ;
if ( V_8 -> V_182 == 0 ) {
F_20 ( V_8 -> V_41 , L_64 ,
V_241 -> V_252 ) ;
return - V_253 ;
}
V_8 -> V_183 = F_128 ( V_8 -> V_41 , V_8 -> V_182 ,
sizeof( * V_8 -> V_183 ) ,
V_29 ) ;
if ( ! V_8 -> V_183 )
return - V_30 ;
V_8 -> V_183 [ 0 ] . V_251 = L_65 ;
V_8 -> V_183 [ 1 ] . V_251 = L_66 ;
if ( V_8 -> V_182 > 2 )
V_8 -> V_183 [ 2 ] . V_251 = L_67 ;
return F_129 ( V_8 -> V_41 , V_8 -> V_182 ,
V_8 -> V_183 ) ;
}
static int F_130 ( struct V_4 * V_8 , T_1 V_254 )
{
struct V_240 * V_241 = V_8 -> V_41 -> V_225 ;
unsigned int V_27 = 0 ;
if ( F_124 ( V_241 , L_53 ) ) {
V_8 -> V_182 = 7 ;
V_8 -> V_183 = F_128 ( V_8 -> V_41 , V_8 -> V_182 ,
sizeof( * V_8 -> V_183 ) ,
V_29 ) ;
if ( ! V_8 -> V_183 )
return - V_30 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_68 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_69 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_70 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_71 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_72 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_73 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_74 ;
} else if ( F_124 ( V_241 , L_56 ) ) {
bool V_255 = false , V_256 = false ;
if ( V_254 & 0x0f )
V_255 = true ;
if ( V_254 & 0x30 )
V_256 = true ;
V_8 -> V_182 = 4 + ( V_255 ? 2 : 0 ) +
( V_256 ? 2 : 0 ) ;
V_8 -> V_183 = F_128 ( V_8 -> V_41 , V_8 -> V_182 ,
sizeof( * V_8 -> V_183 ) ,
V_29 ) ;
if ( ! V_8 -> V_183 )
return - V_30 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_70 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_71 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_73 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_75 ;
if ( V_255 ) {
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_76 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_77 ;
}
if ( V_256 ) {
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_78 ;
V_8 -> V_183 [ V_27 ++ ] . V_251 = L_79 ;
}
} else if ( F_124 ( V_241 , L_60 ) ) {
V_8 -> V_182 = 5 ;
V_8 -> V_183 = F_128 ( V_8 -> V_41 , V_8 -> V_182 ,
sizeof( * V_8 -> V_183 ) ,
V_29 ) ;
if ( ! V_8 -> V_183 )
return - V_30 ;
V_8 -> V_183 [ 0 ] . V_251 = L_80 ;
V_8 -> V_183 [ 1 ] . V_251 = L_81 ;
V_8 -> V_183 [ 2 ] . V_251 = L_70 ;
V_8 -> V_183 [ 3 ] . V_251 = L_75 ;
V_8 -> V_183 [ 4 ] . V_251 = L_82 ;
}
if ( F_125 ( V_8 -> V_41 -> V_225 , V_8 -> V_183 ,
V_8 -> V_182 ) )
return F_129 ( V_8 -> V_41 , V_8 -> V_182 ,
V_8 -> V_183 ) ;
F_103 ( V_8 -> V_41 , L_83 ) ;
F_41 ( V_8 -> V_41 , V_8 -> V_183 ) ;
V_8 -> V_182 = 0 ;
return F_127 ( V_8 ) ;
}
static int F_131 ( struct V_4 * V_8 )
{
const struct V_61 * V_62 = V_8 -> V_63 ;
struct V_240 * V_241 = V_8 -> V_41 -> V_225 , * V_52 ;
struct V_257 V_258 ;
struct V_259 V_260 ;
T_1 V_238 = 0 , V_261 = 0 ;
unsigned int V_262 = 0 ;
struct V_190 V_191 ;
int V_28 ;
memset ( & V_8 -> V_78 , 0 , sizeof( V_8 -> V_78 ) ) ;
V_8 -> V_78 . V_263 = V_192 ;
V_8 -> V_78 . V_195 = V_241 -> V_252 ;
V_8 -> V_78 . V_25 = ~ 0 ;
V_8 -> V_78 . V_264 = 0 ;
if ( F_132 ( & V_258 , V_241 ) ) {
F_20 ( V_8 -> V_41 , L_84 ) ;
return - V_213 ;
}
F_133 (&parser, &range) {
V_28 = F_134 ( & V_260 , V_241 , & V_191 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_191 . V_263 & V_265 ) {
case V_266 :
V_8 -> V_10 . V_77 = V_191 . V_25 - V_260 . V_267 ;
memcpy ( & V_8 -> V_80 , & V_191 , sizeof( V_191 ) ) ;
V_8 -> V_80 . V_195 = V_241 -> V_252 ;
V_8 -> V_77 . V_25 = V_260 . V_268 ;
V_8 -> V_77 . V_264 = V_260 . V_268 + V_260 . V_104 - 1 ;
V_8 -> V_77 . V_263 = V_192 ;
V_8 -> V_77 . V_195 = L_85 ;
memcpy ( & V_191 , & V_8 -> V_77 , sizeof( V_191 ) ) ;
break;
case V_192 :
V_8 -> V_10 . V_75 = V_191 . V_25 - V_260 . V_267 ;
if ( V_191 . V_263 & V_269 ) {
memcpy ( & V_8 -> V_81 , & V_191 , sizeof( V_191 ) ) ;
V_8 -> V_81 . V_195 = L_86 ;
} else {
memcpy ( & V_8 -> V_75 , & V_191 , sizeof( V_191 ) ) ;
V_8 -> V_75 . V_195 = L_87 ;
}
break;
}
if ( V_191 . V_25 <= V_8 -> V_78 . V_25 )
V_8 -> V_78 . V_25 = V_191 . V_25 ;
if ( V_191 . V_264 >= V_8 -> V_78 . V_264 )
V_8 -> V_78 . V_264 = V_191 . V_264 ;
}
V_28 = F_46 ( V_8 -> V_41 , & V_270 , & V_8 -> V_78 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_135 ( V_241 , & V_8 -> V_83 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_88 ,
V_28 ) ;
V_8 -> V_83 . V_195 = V_241 -> V_195 ;
V_8 -> V_83 . V_25 = 0 ;
V_8 -> V_83 . V_264 = 0xff ;
V_8 -> V_83 . V_263 = V_271 ;
}
F_136 (np, port) {
struct V_51 * V_272 ;
unsigned int V_53 ;
T_1 V_9 ;
V_28 = F_137 ( V_52 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
V_53 = F_11 ( V_28 ) ;
if ( V_53 < 1 || V_53 > V_62 -> V_146 ) {
F_20 ( V_8 -> V_41 , L_90 , V_53 ) ;
return - V_213 ;
}
V_53 -- ;
V_28 = F_138 ( V_52 , L_91 , & V_9 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_92 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_20 ( V_8 -> V_41 , L_93 , V_9 ) ;
return - V_213 ;
}
V_238 |= V_9 << ( V_53 << 3 ) ;
if ( ! F_139 ( V_52 ) ) {
V_262 += V_9 ;
continue;
}
V_261 |= ( ( 1 << V_9 ) - 1 ) << V_262 ;
V_262 += V_9 ;
V_272 = F_140 ( V_8 -> V_41 , sizeof( * V_272 ) , V_29 ) ;
if ( ! V_272 )
return - V_30 ;
V_28 = F_141 ( V_52 , 0 , & V_272 -> V_68 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
F_17 ( & V_272 -> V_31 ) ;
V_272 -> V_53 = V_53 ;
V_272 -> V_238 = V_9 ;
V_272 -> V_8 = V_8 ;
V_272 -> V_54 = F_84 ( V_8 -> V_41 , & V_272 -> V_68 ) ;
if ( F_24 ( V_272 -> V_54 ) )
return F_25 ( V_272 -> V_54 ) ;
F_26 ( & V_272 -> V_31 , & V_8 -> V_273 ) ;
}
V_28 = F_123 ( V_8 , V_238 , & V_8 -> V_159 ) ;
if ( V_28 < 0 ) {
F_20 ( V_8 -> V_41 , L_94 ) ;
return V_28 ;
}
V_28 = F_130 ( V_8 , V_261 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
static bool F_142 ( struct V_51 * V_52 )
{
unsigned int V_274 = 3 ;
unsigned long V_9 ;
V_9 = F_7 ( V_52 -> V_54 + V_275 ) ;
V_9 &= ~ V_276 ;
V_9 |= V_277 ;
F_5 ( V_9 , V_52 -> V_54 + V_275 ) ;
do {
unsigned int V_131 = V_278 ;
do {
V_9 = F_7 ( V_52 -> V_54 + V_279 ) ;
if ( V_9 & V_280 )
break;
F_34 ( 1000 , 2000 ) ;
} while ( -- V_131 );
if ( ! V_131 ) {
F_20 ( V_52 -> V_8 -> V_41 , L_95 ,
V_52 -> V_53 ) ;
goto V_281;
}
V_131 = V_278 ;
do {
V_9 = F_7 ( V_52 -> V_54 + V_282 ) ;
if ( V_9 & V_283 )
return true ;
F_34 ( 1000 , 2000 ) ;
} while ( -- V_131 );
V_281:
F_33 ( V_52 ) ;
} while ( -- V_274 );
return false ;
}
static int F_143 ( struct V_4 * V_8 )
{
struct V_51 * V_52 , * V_49 ;
struct V_284 V_285 ;
F_28 (port, tmp, &pcie->ports, list) {
F_103 ( V_8 -> V_41 , L_96 ,
V_52 -> V_53 , V_52 -> V_238 ) ;
F_35 ( V_52 ) ;
if ( F_142 ( V_52 ) )
continue;
F_103 ( V_8 -> V_41 , L_97 , V_52 -> V_53 ) ;
F_36 ( V_52 ) ;
F_37 ( V_52 ) ;
}
memset ( & V_285 , 0 , sizeof( V_285 ) ) ;
#ifdef F_144
V_285 . V_286 = & V_8 -> V_197 . V_3 ;
#endif
V_285 . V_287 = 1 ;
V_285 . V_7 = ( void * * ) & V_8 ;
V_285 . V_288 = F_45 ;
V_285 . V_289 = F_50 ;
V_285 . V_290 = & V_291 ;
F_145 ( V_8 -> V_41 , & V_285 ) ;
return 0 ;
}
static void * F_146 ( struct V_292 * V_293 , T_9 * V_294 )
{
struct V_4 * V_8 = V_293 -> V_295 ;
if ( F_147 ( & V_8 -> V_273 ) )
return NULL ;
F_148 ( V_293 , L_98 ) ;
return F_149 ( & V_8 -> V_273 , * V_294 ) ;
}
static void * F_150 ( struct V_292 * V_293 , void * V_296 , T_9 * V_294 )
{
struct V_4 * V_8 = V_293 -> V_295 ;
return F_151 ( V_296 , & V_8 -> V_273 , V_294 ) ;
}
static void F_152 ( struct V_292 * V_293 , void * V_296 )
{
}
static int F_153 ( struct V_292 * V_293 , void * V_296 )
{
bool V_297 = false , V_298 = false ;
struct V_51 * V_52 ;
unsigned int V_9 ;
V_52 = F_154 ( V_296 , struct V_51 , V_31 ) ;
V_9 = F_7 ( V_52 -> V_54 + V_279 ) ;
if ( V_9 & V_280 )
V_297 = true ;
V_9 = F_7 ( V_52 -> V_54 + V_282 ) ;
if ( V_9 & V_283 )
V_298 = true ;
F_148 ( V_293 , L_99 , V_52 -> V_53 ) ;
if ( V_297 )
F_148 ( V_293 , L_100 ) ;
if ( V_298 ) {
if ( V_297 )
F_148 ( V_293 , L_101 ) ;
F_148 ( V_293 , L_102 ) ;
}
F_148 ( V_293 , L_103 ) ;
return 0 ;
}
static int F_155 ( struct V_299 * V_299 , struct V_300 * V_300 )
{
struct V_4 * V_8 = V_299 -> V_301 ;
struct V_292 * V_293 ;
int V_28 ;
V_28 = F_156 ( V_300 , & V_302 ) ;
if ( V_28 )
return V_28 ;
V_293 = V_300 -> V_7 ;
V_293 -> V_295 = V_8 ;
return 0 ;
}
static int F_157 ( struct V_4 * V_8 )
{
struct V_303 * V_300 ;
V_8 -> V_304 = F_158 ( L_36 , NULL ) ;
if ( ! V_8 -> V_304 )
return - V_30 ;
V_300 = F_159 ( L_104 , V_305 | V_306 , V_8 -> V_304 ,
V_8 , & V_307 ) ;
if ( ! V_300 )
goto remove;
return 0 ;
remove:
F_160 ( V_8 -> V_304 ) ;
V_8 -> V_304 = NULL ;
return - V_30 ;
}
static int F_161 ( struct V_189 * V_84 )
{
const struct V_308 * V_309 ;
struct V_4 * V_8 ;
int V_28 ;
V_309 = F_162 ( V_310 , & V_84 -> V_41 ) ;
if ( ! V_309 )
return - V_253 ;
V_8 = F_140 ( & V_84 -> V_41 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_17 ( & V_8 -> V_47 ) ;
F_17 ( & V_8 -> V_273 ) ;
V_8 -> V_63 = V_309 -> V_203 ;
V_8 -> V_41 = & V_84 -> V_41 ;
V_28 = F_131 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_311 = 0 ;
V_28 = F_79 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_105 , V_28 ) ;
return V_28 ;
}
V_28 = F_61 ( V_8 ) ;
if ( V_28 )
goto V_312;
F_56 ( V_8 ) ;
if ( F_163 ( F_144 ) ) {
V_28 = F_116 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 ,
L_106 ,
V_28 ) ;
goto V_312;
}
}
V_28 = F_143 ( V_8 ) ;
if ( V_28 < 0 ) {
F_20 ( & V_84 -> V_41 , L_107 , V_28 ) ;
goto V_313;
}
if ( F_163 ( V_314 ) ) {
V_28 = F_157 ( V_8 ) ;
if ( V_28 < 0 )
F_20 ( & V_84 -> V_41 , L_108 ,
V_28 ) ;
}
F_164 ( V_84 , V_8 ) ;
return 0 ;
V_313:
if ( F_163 ( F_144 ) )
F_121 ( V_8 ) ;
V_312:
F_88 ( V_8 ) ;
return V_28 ;
}
