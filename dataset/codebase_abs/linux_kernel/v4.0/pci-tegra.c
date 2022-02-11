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
T_2 V_17 = V_18 | V_19 | V_20 | V_21 |
V_22 | V_23 ;
T_3 V_24 = V_8 -> V_24 -> V_25 ;
struct V_15 * V_26 ;
unsigned int V_27 ;
int V_28 ;
V_26 = F_14 ( sizeof( * V_26 ) , V_29 ) ;
if ( ! V_26 )
return F_15 ( - V_30 ) ;
F_16 ( & V_26 -> V_31 ) ;
V_26 -> V_32 = V_16 ;
V_26 -> V_33 = F_17 ( V_34 , V_35 ) ;
if ( ! V_26 -> V_33 ) {
V_28 = - V_30 ;
goto free;
}
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ ) {
unsigned long V_36 = ( unsigned long ) V_26 -> V_33 -> V_37 +
V_27 * V_38 ;
T_3 V_39 = V_24 + V_27 * V_40 + V_16 * V_38 ;
V_28 = F_18 ( V_36 , V_36 + V_38 , V_39 , V_17 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_1 ,
V_28 ) ;
goto V_42;
}
}
return V_26 ;
V_42:
F_20 ( V_26 -> V_33 -> V_37 ) ;
free:
F_21 ( V_26 ) ;
return F_15 ( V_28 ) ;
}
static void T_4 * F_22 ( struct V_4 * V_8 ,
unsigned int V_16 )
{
struct V_15 * V_26 ;
F_23 (bus, &pcie->buses, list)
if ( V_26 -> V_32 == V_16 )
return ( void T_4 * ) V_26 -> V_33 -> V_37 ;
V_26 = F_13 ( V_8 , V_16 ) ;
if ( F_24 ( V_26 ) )
return NULL ;
F_25 ( & V_26 -> V_31 , & V_8 -> V_43 ) ;
return ( void T_4 * ) V_26 -> V_33 -> V_37 ;
}
static void T_4 * F_26 ( struct V_44 * V_26 ,
unsigned int V_13 ,
int V_14 )
{
struct V_4 * V_8 = F_3 ( V_26 -> V_45 ) ;
void T_4 * V_37 = NULL ;
if ( V_26 -> V_46 == 0 ) {
unsigned int V_47 = F_11 ( V_13 ) ;
struct V_48 * V_49 ;
F_23 (port, &pcie->ports, list) {
if ( V_49 -> V_50 + 1 == V_47 ) {
V_37 = V_49 -> V_51 + ( V_14 & ~ 3 ) ;
break;
}
}
} else {
V_37 = F_22 ( V_8 , V_26 -> V_46 ) ;
if ( ! V_37 ) {
F_19 ( V_8 -> V_41 ,
L_2 ,
V_26 -> V_46 ) ;
return NULL ;
}
V_37 += F_10 ( V_13 , V_14 ) ;
}
return V_37 ;
}
static unsigned long F_27 ( struct V_48 * V_49 )
{
unsigned long V_52 = 0 ;
switch ( V_49 -> V_50 ) {
case 0 :
V_52 = V_53 ;
break;
case 1 :
V_52 = V_54 ;
break;
case 2 :
V_52 = V_55 ;
break;
}
return V_52 ;
}
static void F_28 ( struct V_48 * V_49 )
{
unsigned long V_56 = F_27 ( V_49 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_49 -> V_8 , V_56 ) ;
V_9 &= ~ V_57 ;
F_4 ( V_49 -> V_8 , V_9 , V_56 ) ;
F_29 ( 1000 , 2000 ) ;
V_9 = F_6 ( V_49 -> V_8 , V_56 ) ;
V_9 |= V_57 ;
F_4 ( V_49 -> V_8 , V_9 , V_56 ) ;
}
static void F_30 ( struct V_48 * V_49 )
{
const struct V_58 * V_59 = V_49 -> V_8 -> V_60 ;
unsigned long V_56 = F_27 ( V_49 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_49 -> V_8 , V_56 ) ;
V_9 |= V_61 ;
if ( V_59 -> V_62 )
V_9 |= V_63 ;
V_9 |= V_64 ;
F_4 ( V_49 -> V_8 , V_9 , V_56 ) ;
F_28 ( V_49 ) ;
}
static void F_31 ( struct V_48 * V_49 )
{
const struct V_58 * V_59 = V_49 -> V_8 -> V_60 ;
unsigned long V_56 = F_27 ( V_49 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_49 -> V_8 , V_56 ) ;
V_9 &= ~ V_57 ;
F_4 ( V_49 -> V_8 , V_9 , V_56 ) ;
V_9 = F_6 ( V_49 -> V_8 , V_56 ) ;
if ( V_59 -> V_62 )
V_9 &= ~ V_63 ;
V_9 &= ~ V_61 ;
F_4 ( V_49 -> V_8 , V_9 , V_56 ) ;
}
static void F_32 ( struct V_48 * V_49 )
{
struct V_4 * V_8 = V_49 -> V_8 ;
F_33 ( V_8 -> V_41 , V_49 -> V_51 ) ;
F_34 ( V_8 -> V_41 , V_49 -> V_65 . V_25 ,
F_35 ( & V_49 -> V_65 ) ) ;
F_36 ( & V_49 -> V_31 ) ;
F_37 ( V_8 -> V_41 , V_49 ) ;
}
static void F_38 ( struct V_66 * V_41 )
{
V_41 -> V_67 = V_68 << 8 ;
}
static void F_39 ( struct V_66 * V_41 )
{
F_40 ( V_41 , V_69 , V_70 ) ;
}
static int F_41 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
int V_28 ;
V_28 = F_42 ( V_8 -> V_41 , & V_8 -> V_71 , & V_8 -> V_72 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_42 ( V_8 -> V_41 , & V_8 -> V_71 , & V_8 -> V_73 ) ;
if ( V_28 )
return V_28 ;
F_43 ( & V_6 -> V_74 , & V_8 -> V_72 , V_6 -> V_75 ) ;
F_43 ( & V_6 -> V_74 , & V_8 -> V_73 ,
V_6 -> V_75 ) ;
F_44 ( & V_6 -> V_74 , & V_8 -> V_76 ) ;
F_45 ( V_8 -> V_77 . V_25 , V_8 -> V_78 . V_25 ) ;
return 1 ;
}
static int F_46 ( const struct V_66 * V_79 , T_5 V_47 , T_5 V_80 )
{
struct V_4 * V_8 = F_3 ( V_79 -> V_26 -> V_45 ) ;
int V_81 ;
F_47 () ;
V_81 = F_48 ( V_79 , V_47 , V_80 ) ;
if ( ! V_81 )
V_81 = V_8 -> V_81 ;
return V_81 ;
}
static struct V_44 * F_49 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
struct V_44 * V_26 ;
V_26 = F_50 ( V_8 -> V_41 , V_6 -> V_16 , & V_82 , V_6 ,
& V_6 -> V_74 ) ;
if ( ! V_26 )
return NULL ;
F_51 ( V_26 ) ;
return V_26 ;
}
static T_6 F_52 ( int V_81 , void * V_83 )
{
const char * V_84 [] = {
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
struct V_4 * V_8 = V_83 ;
T_1 V_85 , V_86 ;
V_85 = F_6 ( V_8 , V_87 ) & V_88 ;
V_86 = F_6 ( V_8 , V_89 ) ;
F_4 ( V_8 , 0 , V_87 ) ;
if ( V_85 == V_90 )
return V_91 ;
if ( V_85 >= F_53 ( V_84 ) )
V_85 = 0 ;
if ( V_85 == V_92 )
F_54 ( V_8 -> V_41 , L_18 , V_84 [ V_85 ] ,
V_86 ) ;
else
F_19 ( V_8 -> V_41 , L_18 , V_84 [ V_85 ] ,
V_86 ) ;
if ( V_85 == V_93 || V_85 == V_92 ||
V_85 == V_94 ) {
T_1 V_95 = F_6 ( V_8 , V_96 ) & 0xff ;
T_7 V_97 = ( T_7 ) V_95 << 32 | ( V_86 & 0xfffffffc ) ;
if ( V_85 == V_92 )
F_54 ( V_8 -> V_41 , L_19 , V_97 ) ;
else
F_19 ( V_8 -> V_41 , L_19 , V_97 ) ;
}
return V_98 ;
}
static void F_55 ( struct V_4 * V_8 )
{
T_1 V_99 , V_100 , V_101 ;
V_99 = 0xfe100000 ;
V_100 = F_35 ( V_8 -> V_24 ) ;
V_101 = V_8 -> V_24 -> V_25 ;
F_4 ( V_8 , V_101 , V_102 ) ;
F_4 ( V_8 , V_100 >> 12 , V_103 ) ;
F_4 ( V_8 , V_99 , V_104 ) ;
V_99 = 0xfdfc0000 ;
V_100 = F_35 ( & V_8 -> V_78 ) ;
V_101 = V_8 -> V_78 . V_25 ;
F_4 ( V_8 , V_101 , V_105 ) ;
F_4 ( V_8 , V_100 >> 12 , V_106 ) ;
F_4 ( V_8 , V_99 , V_107 ) ;
V_99 = ( ( ( V_8 -> V_73 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_100 = F_35 ( & V_8 -> V_73 ) ;
V_101 = V_8 -> V_73 . V_25 ;
F_4 ( V_8 , V_101 , V_108 ) ;
F_4 ( V_8 , V_100 >> 12 , V_109 ) ;
F_4 ( V_8 , V_99 , V_110 ) ;
V_99 = ( ( ( V_8 -> V_72 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_100 = F_35 ( & V_8 -> V_72 ) ;
V_101 = V_8 -> V_72 . V_25 ;
F_4 ( V_8 , V_101 , V_111 ) ;
F_4 ( V_8 , V_100 >> 12 , V_112 ) ;
F_4 ( V_8 , V_99 , V_113 ) ;
F_4 ( V_8 , 0 , V_114 ) ;
F_4 ( V_8 , 0 , V_115 ) ;
F_4 ( V_8 , 0 , V_116 ) ;
F_4 ( V_8 , 0 , V_117 ) ;
F_4 ( V_8 , 0 , V_118 ) ;
F_4 ( V_8 , 0 , V_119 ) ;
F_4 ( V_8 , V_120 , V_121 ) ;
F_4 ( V_8 , 0 , V_122 ) ;
F_4 ( V_8 , 0 , V_123 ) ;
F_4 ( V_8 , 0 , V_124 ) ;
F_4 ( V_8 , 0 , V_125 ) ;
F_4 ( V_8 , 0 , V_126 ) ;
F_4 ( V_8 , 0 , V_127 ) ;
F_4 ( V_8 , 0 , V_126 ) ;
}
static int F_56 ( struct V_4 * V_8 , unsigned long V_128 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
T_1 V_9 ;
V_128 = V_129 + F_57 ( V_128 ) ;
while ( F_58 ( V_129 , V_128 ) ) {
V_9 = F_9 ( V_8 , V_59 -> V_130 ) ;
if ( V_9 & V_131 )
return 0 ;
}
return - V_132 ;
}
static int F_59 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
T_1 V_9 ;
int V_28 ;
F_8 ( V_8 , 0x0 , V_133 ) ;
V_9 = F_9 ( V_8 , V_134 ) ;
V_9 |= V_135 ;
F_8 ( V_8 , V_9 , V_134 ) ;
V_9 = F_9 ( V_8 , V_59 -> V_130 ) ;
V_9 &= ~ ( V_136 | V_137 ) ;
V_9 |= V_138 | V_59 -> V_139 ;
F_8 ( V_8 , V_9 , V_59 -> V_130 ) ;
V_9 = F_9 ( V_8 , V_59 -> V_130 ) ;
V_9 &= ~ V_140 ;
F_8 ( V_8 , V_9 , V_59 -> V_130 ) ;
F_29 ( 20 , 100 ) ;
V_9 = F_9 ( V_8 , V_59 -> V_130 ) ;
V_9 |= V_140 ;
F_8 ( V_8 , V_9 , V_59 -> V_130 ) ;
V_9 = V_141 | ( V_141 << 16 ) ;
F_8 ( V_8 , V_9 , V_142 ) ;
if ( V_59 -> V_143 > 2 )
F_8 ( V_8 , V_141 , V_144 ) ;
V_28 = F_56 ( V_8 , 500 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_20 , V_28 ) ;
return V_28 ;
}
V_9 = F_9 ( V_8 , V_134 ) ;
V_9 &= ~ V_135 ;
F_8 ( V_8 , V_9 , V_134 ) ;
V_9 = F_9 ( V_8 , V_134 ) ;
V_9 |= V_145 | V_146 ;
F_8 ( V_8 , V_9 , V_134 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
struct V_48 * V_49 ;
unsigned long V_9 ;
int V_28 ;
if ( V_8 -> V_147 ) {
V_9 = F_6 ( V_8 , V_148 ) ;
V_9 &= ~ V_149 ;
V_9 |= V_150 ;
F_4 ( V_8 , V_9 , V_148 ) ;
}
if ( V_59 -> V_151 )
F_4 ( V_8 , 0 , V_152 ) ;
V_9 = F_6 ( V_8 , V_153 ) ;
V_9 &= ~ V_154 ;
V_9 |= V_155 | V_8 -> V_156 ;
F_23 (port, &pcie->ports, list)
V_9 &= ~ F_61 ( V_49 -> V_50 ) ;
F_4 ( V_8 , V_9 , V_153 ) ;
if ( V_59 -> V_157 ) {
V_9 = F_6 ( V_8 , V_158 ) ;
V_9 &= ~ V_159 ;
F_4 ( V_8 , V_9 , V_158 ) ;
} else {
V_9 = F_6 ( V_8 , V_158 ) ;
V_9 |= V_159 ;
F_4 ( V_8 , V_9 , V_158 ) ;
}
if ( ! V_8 -> V_147 )
V_28 = F_59 ( V_8 ) ;
else
V_28 = F_62 ( V_8 -> V_147 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_21 , V_28 ) ;
return V_28 ;
}
F_63 ( V_8 -> V_160 ) ;
V_9 = F_6 ( V_8 , V_161 ) ;
V_9 |= V_162 ;
F_4 ( V_8 , V_9 , V_161 ) ;
V_9 = V_163 | V_164 |
V_165 | V_166 |
V_167 | V_168 ;
if ( V_59 -> V_169 )
V_9 |= V_170 ;
F_4 ( V_8 , V_9 , V_171 ) ;
F_4 ( V_8 , 0xffffffff , V_172 ) ;
F_4 ( V_8 , V_173 , V_174 ) ;
F_4 ( V_8 , 0 , V_175 ) ;
return 0 ;
}
static void F_64 ( struct V_4 * V_8 )
{
int V_28 ;
V_28 = F_65 ( V_8 -> V_147 ) ;
if ( V_28 < 0 )
F_66 ( V_8 -> V_41 , L_22 , V_28 ) ;
F_67 ( V_8 -> V_160 ) ;
F_67 ( V_8 -> V_176 ) ;
F_67 ( V_8 -> V_177 ) ;
F_68 ( V_178 ) ;
V_28 = F_69 ( V_8 -> V_179 , V_8 -> V_180 ) ;
if ( V_28 < 0 )
F_66 ( V_8 -> V_41 , L_23 , V_28 ) ;
}
static int F_70 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
int V_28 ;
F_67 ( V_8 -> V_160 ) ;
F_67 ( V_8 -> V_176 ) ;
F_67 ( V_8 -> V_177 ) ;
F_68 ( V_178 ) ;
V_28 = F_71 ( V_8 -> V_179 , V_8 -> V_180 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_24 , V_28 ) ;
V_28 = F_72 ( V_178 ,
V_8 -> V_181 ,
V_8 -> V_177 ) ;
if ( V_28 ) {
F_19 ( V_8 -> V_41 , L_25 , V_28 ) ;
return V_28 ;
}
F_63 ( V_8 -> V_176 ) ;
V_28 = F_73 ( V_8 -> V_182 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_26 , V_28 ) ;
return V_28 ;
}
if ( V_59 -> V_183 ) {
V_28 = F_73 ( V_8 -> V_184 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_27 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_73 ( V_8 -> V_185 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_28 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_74 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
V_8 -> V_181 = F_75 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_181 ) )
return F_76 ( V_8 -> V_181 ) ;
V_8 -> V_182 = F_75 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_182 ) )
return F_76 ( V_8 -> V_182 ) ;
V_8 -> V_185 = F_75 ( V_8 -> V_41 , L_31 ) ;
if ( F_24 ( V_8 -> V_185 ) )
return F_76 ( V_8 -> V_185 ) ;
if ( V_59 -> V_183 ) {
V_8 -> V_184 = F_75 ( V_8 -> V_41 , L_32 ) ;
if ( F_24 ( V_8 -> V_184 ) )
return F_76 ( V_8 -> V_184 ) ;
}
return 0 ;
}
static int F_77 ( struct V_4 * V_8 )
{
V_8 -> V_177 = F_78 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_177 ) )
return F_76 ( V_8 -> V_177 ) ;
V_8 -> V_176 = F_78 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_176 ) )
return F_76 ( V_8 -> V_176 ) ;
V_8 -> V_160 = F_78 ( V_8 -> V_41 , L_33 ) ;
if ( F_24 ( V_8 -> V_160 ) )
return F_76 ( V_8 -> V_160 ) ;
return 0 ;
}
static int F_79 ( struct V_4 * V_8 )
{
struct V_186 * V_79 = F_80 ( V_8 -> V_41 ) ;
struct V_187 * V_12 , * V_11 , * V_188 ;
int V_28 ;
V_28 = F_74 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_34 , V_28 ) ;
return V_28 ;
}
V_28 = F_77 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_35 , V_28 ) ;
return V_28 ;
}
V_8 -> V_147 = F_81 ( V_8 -> V_41 , L_36 ) ;
if ( F_24 ( V_8 -> V_147 ) ) {
V_28 = F_76 ( V_8 -> V_147 ) ;
F_19 ( & V_79 -> V_41 , L_37 , V_28 ) ;
return V_28 ;
}
V_28 = F_82 ( V_8 -> V_147 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_38 , V_28 ) ;
return V_28 ;
}
V_28 = F_70 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_39 , V_28 ) ;
return V_28 ;
}
V_12 = F_83 ( V_79 , V_189 , L_40 ) ;
V_8 -> V_12 = F_84 ( & V_79 -> V_41 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_76 ( V_8 -> V_12 ) ;
goto V_190;
}
V_11 = F_83 ( V_79 , V_189 , L_30 ) ;
V_8 -> V_11 = F_84 ( & V_79 -> V_41 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_76 ( V_8 -> V_11 ) ;
goto V_190;
}
V_188 = F_83 ( V_79 , V_189 , L_41 ) ;
if ( ! V_188 ) {
V_28 = - V_191 ;
goto V_190;
}
V_8 -> V_24 = F_85 ( V_8 -> V_41 , V_188 -> V_25 ,
F_35 ( V_188 ) , V_188 -> V_192 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_191 ;
goto V_190;
}
V_28 = F_86 ( V_79 , L_42 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_43 , V_28 ) ;
goto V_190;
}
V_8 -> V_81 = V_28 ;
V_28 = F_87 ( V_8 -> V_81 , F_52 , V_193 , L_44 , V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_45 , V_28 ) ;
goto V_190;
}
return 0 ;
V_190:
F_64 ( V_8 ) ;
return V_28 ;
}
static int F_88 ( struct V_4 * V_8 )
{
int V_28 ;
if ( V_8 -> V_81 > 0 )
F_89 ( V_8 -> V_81 , V_8 ) ;
F_64 ( V_8 ) ;
V_28 = F_90 ( V_8 -> V_147 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_46 , V_28 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_3 )
{
int V_194 ;
F_92 ( & V_3 -> V_195 ) ;
V_194 = F_93 ( V_3 -> V_196 , V_197 ) ;
if ( V_194 < V_197 )
F_94 ( V_194 , V_3 -> V_196 ) ;
else
V_194 = - V_198 ;
F_95 ( & V_3 -> V_195 ) ;
return V_194 ;
}
static void F_96 ( struct V_1 * V_3 , unsigned long V_81 )
{
struct V_199 * V_41 = V_3 -> V_3 . V_41 ;
F_92 ( & V_3 -> V_195 ) ;
if ( ! F_97 ( V_81 , V_3 -> V_196 ) )
F_19 ( V_41 , L_47 , V_81 ) ;
else
F_98 ( V_81 , V_3 -> V_196 ) ;
F_95 ( & V_3 -> V_195 ) ;
}
static T_6 F_99 ( int V_81 , void * V_200 )
{
struct V_4 * V_8 = V_200 ;
struct V_1 * V_194 = & V_8 -> V_194 ;
unsigned int V_27 , V_201 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_202 = F_6 ( V_8 , V_203 + V_27 * 4 ) ;
while ( V_202 ) {
unsigned int V_10 = F_100 ( & V_202 , 32 ) ;
unsigned int V_50 = V_27 * 32 + V_10 ;
unsigned int V_81 ;
F_4 ( V_8 , 1 << V_10 , V_203 + V_27 * 4 ) ;
V_81 = F_101 ( V_194 -> V_204 , V_50 ) ;
if ( V_81 ) {
if ( F_97 ( V_50 , V_194 -> V_196 ) )
F_102 ( V_81 ) ;
else
F_103 ( V_8 -> V_41 , L_48 ) ;
} else {
F_103 ( V_8 -> V_41 , L_49 ) ;
}
V_202 = F_6 ( V_8 , V_203 + V_27 * 4 ) ;
V_201 ++ ;
}
}
return V_201 > 0 ? V_98 : V_91 ;
}
static int F_104 ( struct V_2 * V_3 ,
struct V_66 * V_79 , struct V_205 * V_206 )
{
struct V_1 * V_194 = F_1 ( V_3 ) ;
struct V_207 V_208 ;
unsigned int V_81 ;
int V_209 ;
V_209 = F_91 ( V_194 ) ;
if ( V_209 < 0 )
return V_209 ;
V_81 = F_105 ( V_194 -> V_204 , V_209 ) ;
if ( ! V_81 ) {
F_96 ( V_194 , V_209 ) ;
return - V_210 ;
}
F_106 ( V_81 , V_206 ) ;
V_208 . V_211 = F_107 ( ( void * ) V_194 -> V_212 ) ;
V_208 . V_213 = 0 ;
V_208 . V_200 = V_209 ;
F_108 ( V_81 , & V_208 ) ;
return 0 ;
}
static void F_109 ( struct V_2 * V_3 ,
unsigned int V_81 )
{
struct V_1 * V_194 = F_1 ( V_3 ) ;
struct V_214 * V_215 = F_110 ( V_81 ) ;
T_8 V_209 = F_111 ( V_215 ) ;
F_112 ( V_81 ) ;
F_96 ( V_194 , V_209 ) ;
}
static int F_113 ( struct V_216 * V_204 , unsigned int V_81 ,
T_8 V_209 )
{
F_114 ( V_81 , & V_217 , V_218 ) ;
F_115 ( V_81 , V_204 -> V_219 ) ;
F_116 ( V_81 , V_220 ) ;
F_47 () ;
return 0 ;
}
static int F_117 ( struct V_4 * V_8 )
{
struct V_186 * V_79 = F_80 ( V_8 -> V_41 ) ;
const struct V_58 * V_59 = V_8 -> V_60 ;
struct V_1 * V_194 = & V_8 -> V_194 ;
unsigned long V_51 ;
int V_28 ;
T_1 V_202 ;
F_118 ( & V_194 -> V_195 ) ;
V_194 -> V_3 . V_41 = V_8 -> V_41 ;
V_194 -> V_3 . V_221 = F_104 ;
V_194 -> V_3 . V_222 = F_109 ;
V_194 -> V_204 = F_119 ( V_8 -> V_41 -> V_223 , V_197 ,
& V_224 , & V_194 -> V_3 ) ;
if ( ! V_194 -> V_204 ) {
F_19 ( & V_79 -> V_41 , L_50 ) ;
return - V_30 ;
}
V_28 = F_86 ( V_79 , L_51 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_43 , V_28 ) ;
goto V_28;
}
V_194 -> V_81 = V_28 ;
V_28 = F_87 ( V_194 -> V_81 , F_99 , 0 ,
V_217 . V_192 , V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_52 , V_28 ) ;
goto V_28;
}
V_194 -> V_212 = F_120 ( V_29 , 0 ) ;
V_51 = F_107 ( ( void * ) V_194 -> V_212 ) ;
F_4 ( V_8 , V_51 >> V_59 -> V_225 , V_125 ) ;
F_4 ( V_8 , V_51 , V_127 ) ;
F_4 ( V_8 , 1 , V_126 ) ;
F_4 ( V_8 , 0xffffffff , V_226 ) ;
F_4 ( V_8 , 0xffffffff , V_227 ) ;
F_4 ( V_8 , 0xffffffff , V_228 ) ;
F_4 ( V_8 , 0xffffffff , V_229 ) ;
F_4 ( V_8 , 0xffffffff , V_230 ) ;
F_4 ( V_8 , 0xffffffff , V_231 ) ;
F_4 ( V_8 , 0xffffffff , V_232 ) ;
F_4 ( V_8 , 0xffffffff , V_233 ) ;
V_202 = F_6 ( V_8 , V_174 ) ;
V_202 |= V_234 ;
F_4 ( V_8 , V_202 , V_174 ) ;
return 0 ;
V_28:
F_121 ( V_194 -> V_204 ) ;
return V_28 ;
}
static int F_122 ( struct V_4 * V_8 )
{
struct V_1 * V_194 = & V_8 -> V_194 ;
unsigned int V_27 , V_81 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_174 ) ;
V_9 &= ~ V_234 ;
F_4 ( V_8 , V_9 , V_174 ) ;
F_4 ( V_8 , 0 , V_226 ) ;
F_4 ( V_8 , 0 , V_227 ) ;
F_4 ( V_8 , 0 , V_228 ) ;
F_4 ( V_8 , 0 , V_229 ) ;
F_4 ( V_8 , 0 , V_230 ) ;
F_4 ( V_8 , 0 , V_231 ) ;
F_4 ( V_8 , 0 , V_232 ) ;
F_4 ( V_8 , 0 , V_233 ) ;
F_123 ( V_194 -> V_212 , 0 ) ;
if ( V_194 -> V_81 > 0 )
F_89 ( V_194 -> V_81 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_197 ; V_27 ++ ) {
V_81 = F_101 ( V_194 -> V_204 , V_27 ) ;
if ( V_81 > 0 )
F_112 ( V_81 ) ;
}
F_121 ( V_194 -> V_204 ) ;
return 0 ;
}
static int F_124 ( struct V_4 * V_8 , T_1 V_235 ,
T_1 * V_236 )
{
struct V_237 * V_238 = V_8 -> V_41 -> V_223 ;
if ( F_125 ( V_238 , L_53 ) ) {
switch ( V_235 ) {
case 0x0000104 :
F_103 ( V_8 -> V_41 , L_54 ) ;
* V_236 = V_239 ;
return 0 ;
case 0x0000102 :
F_103 ( V_8 -> V_41 , L_55 ) ;
* V_236 = V_240 ;
return 0 ;
}
} else if ( F_125 ( V_238 , L_56 ) ) {
switch ( V_235 ) {
case 0x00000204 :
F_103 ( V_8 -> V_41 , L_57 ) ;
* V_236 = V_241 ;
return 0 ;
case 0x00020202 :
F_103 ( V_8 -> V_41 , L_58 ) ;
* V_236 = V_242 ;
return 0 ;
case 0x00010104 :
F_103 ( V_8 -> V_41 , L_59 ) ;
* V_236 = V_243 ;
return 0 ;
}
} else if ( F_125 ( V_238 , L_60 ) ) {
switch ( V_235 ) {
case 0x00000004 :
F_103 ( V_8 -> V_41 , L_61 ) ;
* V_236 = V_244 ;
return 0 ;
case 0x00000202 :
F_103 ( V_8 -> V_41 , L_62 ) ;
* V_236 = V_245 ;
return 0 ;
}
}
return - V_210 ;
}
static bool F_126 ( struct V_237 * V_238 ,
struct V_246 * V_180 ,
unsigned int V_179 )
{
char V_247 [ 32 ] ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_179 ; V_27 ++ ) {
snprintf ( V_247 , 32 , L_63 , V_180 [ V_27 ] . V_248 ) ;
if ( F_127 ( V_238 , V_247 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_128 ( struct V_4 * V_8 )
{
struct V_237 * V_238 = V_8 -> V_41 -> V_223 ;
if ( F_125 ( V_238 , L_56 ) )
V_8 -> V_179 = 3 ;
else if ( F_125 ( V_238 , L_60 ) )
V_8 -> V_179 = 2 ;
if ( V_8 -> V_179 == 0 ) {
F_19 ( V_8 -> V_41 , L_64 ,
V_238 -> V_249 ) ;
return - V_250 ;
}
V_8 -> V_180 = F_129 ( V_8 -> V_41 , V_8 -> V_179 ,
sizeof( * V_8 -> V_180 ) ,
V_29 ) ;
if ( ! V_8 -> V_180 )
return - V_30 ;
V_8 -> V_180 [ 0 ] . V_248 = L_65 ;
V_8 -> V_180 [ 1 ] . V_248 = L_66 ;
if ( V_8 -> V_179 > 2 )
V_8 -> V_180 [ 2 ] . V_248 = L_67 ;
return F_130 ( V_8 -> V_41 , V_8 -> V_179 ,
V_8 -> V_180 ) ;
}
static int F_131 ( struct V_4 * V_8 , T_1 V_251 )
{
struct V_237 * V_238 = V_8 -> V_41 -> V_223 ;
unsigned int V_27 = 0 ;
if ( F_125 ( V_238 , L_53 ) ) {
V_8 -> V_179 = 7 ;
V_8 -> V_180 = F_129 ( V_8 -> V_41 , V_8 -> V_179 ,
sizeof( * V_8 -> V_180 ) ,
V_29 ) ;
if ( ! V_8 -> V_180 )
return - V_30 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_68 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_69 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_70 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_71 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_72 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_73 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_74 ;
} else if ( F_125 ( V_238 , L_56 ) ) {
bool V_252 = false , V_253 = false ;
if ( V_251 & 0x0f )
V_252 = true ;
if ( V_251 & 0x30 )
V_253 = true ;
V_8 -> V_179 = 4 + ( V_252 ? 2 : 0 ) +
( V_253 ? 2 : 0 ) ;
V_8 -> V_180 = F_129 ( V_8 -> V_41 , V_8 -> V_179 ,
sizeof( * V_8 -> V_180 ) ,
V_29 ) ;
if ( ! V_8 -> V_180 )
return - V_30 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_70 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_71 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_73 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_75 ;
if ( V_252 ) {
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_76 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_77 ;
}
if ( V_253 ) {
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_78 ;
V_8 -> V_180 [ V_27 ++ ] . V_248 = L_79 ;
}
} else if ( F_125 ( V_238 , L_60 ) ) {
V_8 -> V_179 = 5 ;
V_8 -> V_180 = F_129 ( V_8 -> V_41 , V_8 -> V_179 ,
sizeof( * V_8 -> V_180 ) ,
V_29 ) ;
if ( ! V_8 -> V_180 )
return - V_30 ;
V_8 -> V_180 [ 0 ] . V_248 = L_80 ;
V_8 -> V_180 [ 1 ] . V_248 = L_81 ;
V_8 -> V_180 [ 2 ] . V_248 = L_70 ;
V_8 -> V_180 [ 3 ] . V_248 = L_75 ;
V_8 -> V_180 [ 4 ] . V_248 = L_82 ;
}
if ( F_126 ( V_8 -> V_41 -> V_223 , V_8 -> V_180 ,
V_8 -> V_179 ) )
return F_130 ( V_8 -> V_41 , V_8 -> V_179 ,
V_8 -> V_180 ) ;
F_103 ( V_8 -> V_41 , L_83 ) ;
F_37 ( V_8 -> V_41 , V_8 -> V_180 ) ;
V_8 -> V_179 = 0 ;
return F_128 ( V_8 ) ;
}
static int F_132 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
struct V_237 * V_238 = V_8 -> V_41 -> V_223 , * V_49 ;
struct V_254 V_255 ;
struct V_256 V_257 ;
T_1 V_235 = 0 , V_258 = 0 ;
unsigned int V_259 = 0 ;
struct V_187 V_188 ;
int V_28 ;
memset ( & V_8 -> V_71 , 0 , sizeof( V_8 -> V_71 ) ) ;
V_8 -> V_71 . V_260 = V_189 ;
V_8 -> V_71 . V_192 = V_238 -> V_249 ;
V_8 -> V_71 . V_25 = ~ 0 ;
V_8 -> V_71 . V_261 = 0 ;
if ( F_133 ( & V_255 , V_238 ) ) {
F_19 ( V_8 -> V_41 , L_84 ) ;
return - V_210 ;
}
F_134 (&parser, &range) {
V_28 = F_135 ( & V_257 , V_238 , & V_188 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_188 . V_260 & V_262 ) {
case V_263 :
memcpy ( & V_8 -> V_77 , & V_188 , sizeof( V_188 ) ) ;
V_8 -> V_77 . V_192 = V_238 -> V_249 ;
V_8 -> V_78 . V_25 = V_257 . V_264 ;
V_8 -> V_78 . V_261 = V_257 . V_264 + V_257 . V_100 - 1 ;
V_8 -> V_78 . V_260 = V_189 ;
V_8 -> V_78 . V_192 = L_85 ;
memcpy ( & V_188 , & V_8 -> V_78 , sizeof( V_188 ) ) ;
break;
case V_189 :
if ( V_188 . V_260 & V_265 ) {
memcpy ( & V_8 -> V_73 , & V_188 , sizeof( V_188 ) ) ;
V_8 -> V_73 . V_192 = L_86 ;
} else {
memcpy ( & V_8 -> V_72 , & V_188 , sizeof( V_188 ) ) ;
V_8 -> V_72 . V_192 = L_87 ;
}
break;
}
if ( V_188 . V_25 <= V_8 -> V_71 . V_25 )
V_8 -> V_71 . V_25 = V_188 . V_25 ;
if ( V_188 . V_261 >= V_8 -> V_71 . V_261 )
V_8 -> V_71 . V_261 = V_188 . V_261 ;
}
V_28 = F_42 ( V_8 -> V_41 , & V_266 , & V_8 -> V_71 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_136 ( V_238 , & V_8 -> V_76 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_88 ,
V_28 ) ;
V_8 -> V_76 . V_192 = V_238 -> V_192 ;
V_8 -> V_76 . V_25 = 0 ;
V_8 -> V_76 . V_261 = 0xff ;
V_8 -> V_76 . V_260 = V_267 ;
}
F_137 (np, port) {
struct V_48 * V_268 ;
unsigned int V_50 ;
T_1 V_9 ;
V_28 = F_138 ( V_49 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
V_50 = F_11 ( V_28 ) ;
if ( V_50 < 1 || V_50 > V_59 -> V_143 ) {
F_19 ( V_8 -> V_41 , L_90 , V_50 ) ;
return - V_210 ;
}
V_50 -- ;
V_28 = F_139 ( V_49 , L_91 , & V_9 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_92 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_19 ( V_8 -> V_41 , L_93 , V_9 ) ;
return - V_210 ;
}
V_235 |= V_9 << ( V_50 << 3 ) ;
if ( ! F_140 ( V_49 ) ) {
V_259 += V_9 ;
continue;
}
V_258 |= ( ( 1 << V_9 ) - 1 ) << V_259 ;
V_259 += V_9 ;
V_268 = F_141 ( V_8 -> V_41 , sizeof( * V_268 ) , V_29 ) ;
if ( ! V_268 )
return - V_30 ;
V_28 = F_142 ( V_49 , 0 , & V_268 -> V_65 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
F_16 ( & V_268 -> V_31 ) ;
V_268 -> V_50 = V_50 ;
V_268 -> V_235 = V_9 ;
V_268 -> V_8 = V_8 ;
V_268 -> V_51 = F_84 ( V_8 -> V_41 , & V_268 -> V_65 ) ;
if ( F_24 ( V_268 -> V_51 ) )
return F_76 ( V_268 -> V_51 ) ;
F_25 ( & V_268 -> V_31 , & V_8 -> V_269 ) ;
}
V_28 = F_124 ( V_8 , V_235 , & V_8 -> V_156 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_94 ) ;
return V_28 ;
}
V_28 = F_131 ( V_8 , V_258 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
static bool F_143 ( struct V_48 * V_49 )
{
unsigned int V_270 = 3 ;
unsigned long V_9 ;
V_9 = F_7 ( V_49 -> V_51 + V_271 ) ;
V_9 &= ~ V_272 ;
V_9 |= V_273 ;
F_5 ( V_9 , V_49 -> V_51 + V_271 ) ;
do {
unsigned int V_128 = V_274 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_275 ) ;
if ( V_9 & V_276 )
break;
F_29 ( 1000 , 2000 ) ;
} while ( -- V_128 );
if ( ! V_128 ) {
F_19 ( V_49 -> V_8 -> V_41 , L_95 ,
V_49 -> V_50 ) ;
goto V_277;
}
V_128 = V_274 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_278 ) ;
if ( V_9 & V_279 )
return true ;
F_29 ( 1000 , 2000 ) ;
} while ( -- V_128 );
V_277:
F_28 ( V_49 ) ;
} while ( -- V_270 );
return false ;
}
static int F_144 ( struct V_4 * V_8 )
{
struct V_48 * V_49 , * V_280 ;
struct V_281 V_282 ;
F_145 (port, tmp, &pcie->ports, list) {
F_103 ( V_8 -> V_41 , L_96 ,
V_49 -> V_50 , V_49 -> V_235 ) ;
F_30 ( V_49 ) ;
if ( F_143 ( V_49 ) )
continue;
F_103 ( V_8 -> V_41 , L_97 , V_49 -> V_50 ) ;
F_31 ( V_49 ) ;
F_32 ( V_49 ) ;
}
memset ( & V_282 , 0 , sizeof( V_282 ) ) ;
#ifdef F_146
V_282 . V_283 = & V_8 -> V_194 . V_3 ;
#endif
V_282 . V_284 = 1 ;
V_282 . V_7 = ( void * * ) & V_8 ;
V_282 . V_285 = F_41 ;
V_282 . V_286 = F_46 ;
V_282 . V_287 = F_49 ;
V_282 . V_288 = & V_82 ;
F_147 ( V_8 -> V_41 , & V_282 ) ;
return 0 ;
}
static void * F_148 ( struct V_289 * V_290 , T_9 * V_291 )
{
struct V_4 * V_8 = V_290 -> V_292 ;
if ( F_149 ( & V_8 -> V_269 ) )
return NULL ;
F_150 ( V_290 , L_98 ) ;
return F_151 ( & V_8 -> V_269 , * V_291 ) ;
}
static void * F_152 ( struct V_289 * V_290 , void * V_293 , T_9 * V_291 )
{
struct V_4 * V_8 = V_290 -> V_292 ;
return F_153 ( V_293 , & V_8 -> V_269 , V_291 ) ;
}
static void F_154 ( struct V_289 * V_290 , void * V_293 )
{
}
static int F_155 ( struct V_289 * V_290 , void * V_293 )
{
bool V_294 = false , V_295 = false ;
struct V_48 * V_49 ;
unsigned int V_9 ;
V_49 = F_156 ( V_293 , struct V_48 , V_31 ) ;
V_9 = F_7 ( V_49 -> V_51 + V_275 ) ;
if ( V_9 & V_276 )
V_294 = true ;
V_9 = F_7 ( V_49 -> V_51 + V_278 ) ;
if ( V_9 & V_279 )
V_295 = true ;
F_150 ( V_290 , L_99 , V_49 -> V_50 ) ;
if ( V_294 )
F_150 ( V_290 , L_100 ) ;
if ( V_295 ) {
if ( V_294 )
F_150 ( V_290 , L_101 ) ;
F_150 ( V_290 , L_102 ) ;
}
F_150 ( V_290 , L_103 ) ;
return 0 ;
}
static int F_157 ( struct V_296 * V_296 , struct V_297 * V_297 )
{
struct V_4 * V_8 = V_296 -> V_298 ;
struct V_289 * V_290 ;
int V_28 ;
V_28 = F_158 ( V_297 , & V_299 ) ;
if ( V_28 )
return V_28 ;
V_290 = V_297 -> V_7 ;
V_290 -> V_292 = V_8 ;
return 0 ;
}
static int F_159 ( struct V_4 * V_8 )
{
struct V_300 * V_297 ;
V_8 -> V_301 = F_160 ( L_36 , NULL ) ;
if ( ! V_8 -> V_301 )
return - V_30 ;
V_297 = F_161 ( L_104 , V_302 | V_303 , V_8 -> V_301 ,
V_8 , & V_304 ) ;
if ( ! V_297 )
goto remove;
return 0 ;
remove:
F_162 ( V_8 -> V_301 ) ;
V_8 -> V_301 = NULL ;
return - V_30 ;
}
static int F_163 ( struct V_186 * V_79 )
{
const struct V_305 * V_306 ;
struct V_4 * V_8 ;
int V_28 ;
V_306 = F_164 ( V_307 , & V_79 -> V_41 ) ;
if ( ! V_306 )
return - V_250 ;
V_8 = F_141 ( & V_79 -> V_41 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_16 ( & V_8 -> V_43 ) ;
F_16 ( & V_8 -> V_269 ) ;
V_8 -> V_60 = V_306 -> V_200 ;
V_8 -> V_41 = & V_79 -> V_41 ;
V_28 = F_132 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_308 = 0 ;
V_28 = F_79 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_105 , V_28 ) ;
return V_28 ;
}
V_28 = F_60 ( V_8 ) ;
if ( V_28 )
goto V_309;
F_55 ( V_8 ) ;
if ( F_165 ( F_146 ) ) {
V_28 = F_117 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 ,
L_106 ,
V_28 ) ;
goto V_309;
}
}
V_28 = F_144 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_107 , V_28 ) ;
goto V_310;
}
if ( F_165 ( V_311 ) ) {
V_28 = F_159 ( V_8 ) ;
if ( V_28 < 0 )
F_19 ( & V_79 -> V_41 , L_108 ,
V_28 ) ;
}
F_166 ( V_79 , V_8 ) ;
return 0 ;
V_310:
if ( F_165 ( F_146 ) )
F_122 ( V_8 ) ;
V_309:
F_88 ( V_8 ) ;
return V_28 ;
}
