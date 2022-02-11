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
static T_6 F_49 ( int V_81 , void * V_82 )
{
const char * V_83 [] = {
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
struct V_4 * V_8 = V_82 ;
T_1 V_84 , V_85 ;
V_84 = F_6 ( V_8 , V_86 ) & V_87 ;
V_85 = F_6 ( V_8 , V_88 ) ;
F_4 ( V_8 , 0 , V_86 ) ;
if ( V_84 == V_89 )
return V_90 ;
if ( V_84 >= F_50 ( V_83 ) )
V_84 = 0 ;
if ( V_84 == V_91 )
F_51 ( V_8 -> V_41 , L_18 , V_83 [ V_84 ] ,
V_85 ) ;
else
F_19 ( V_8 -> V_41 , L_18 , V_83 [ V_84 ] ,
V_85 ) ;
if ( V_84 == V_92 || V_84 == V_91 ||
V_84 == V_93 ) {
T_1 V_94 = F_6 ( V_8 , V_95 ) & 0xff ;
T_7 V_96 = ( T_7 ) V_94 << 32 | ( V_85 & 0xfffffffc ) ;
if ( V_84 == V_91 )
F_51 ( V_8 -> V_41 , L_19 , V_96 ) ;
else
F_19 ( V_8 -> V_41 , L_19 , V_96 ) ;
}
return V_97 ;
}
static void F_52 ( struct V_4 * V_8 )
{
T_1 V_98 , V_99 , V_100 ;
V_98 = 0xfe100000 ;
V_99 = F_35 ( V_8 -> V_24 ) ;
V_100 = V_8 -> V_24 -> V_25 ;
F_4 ( V_8 , V_100 , V_101 ) ;
F_4 ( V_8 , V_99 >> 12 , V_102 ) ;
F_4 ( V_8 , V_98 , V_103 ) ;
V_98 = 0xfdfc0000 ;
V_99 = F_35 ( & V_8 -> V_78 ) ;
V_100 = V_8 -> V_78 . V_25 ;
F_4 ( V_8 , V_100 , V_104 ) ;
F_4 ( V_8 , V_99 >> 12 , V_105 ) ;
F_4 ( V_8 , V_98 , V_106 ) ;
V_98 = ( ( ( V_8 -> V_73 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_99 = F_35 ( & V_8 -> V_73 ) ;
V_100 = V_8 -> V_73 . V_25 ;
F_4 ( V_8 , V_100 , V_107 ) ;
F_4 ( V_8 , V_99 >> 12 , V_108 ) ;
F_4 ( V_8 , V_98 , V_109 ) ;
V_98 = ( ( ( V_8 -> V_72 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_99 = F_35 ( & V_8 -> V_72 ) ;
V_100 = V_8 -> V_72 . V_25 ;
F_4 ( V_8 , V_100 , V_110 ) ;
F_4 ( V_8 , V_99 >> 12 , V_111 ) ;
F_4 ( V_8 , V_98 , V_112 ) ;
F_4 ( V_8 , 0 , V_113 ) ;
F_4 ( V_8 , 0 , V_114 ) ;
F_4 ( V_8 , 0 , V_115 ) ;
F_4 ( V_8 , 0 , V_116 ) ;
F_4 ( V_8 , 0 , V_117 ) ;
F_4 ( V_8 , 0 , V_118 ) ;
F_4 ( V_8 , V_119 , V_120 ) ;
F_4 ( V_8 , 0 , V_121 ) ;
F_4 ( V_8 , 0 , V_122 ) ;
F_4 ( V_8 , 0 , V_123 ) ;
F_4 ( V_8 , 0 , V_124 ) ;
F_4 ( V_8 , 0 , V_125 ) ;
F_4 ( V_8 , 0 , V_126 ) ;
F_4 ( V_8 , 0 , V_125 ) ;
}
static int F_53 ( struct V_4 * V_8 , unsigned long V_127 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
T_1 V_9 ;
V_127 = V_128 + F_54 ( V_127 ) ;
while ( F_55 ( V_128 , V_127 ) ) {
V_9 = F_9 ( V_8 , V_59 -> V_129 ) ;
if ( V_9 & V_130 )
return 0 ;
}
return - V_131 ;
}
static int F_56 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
T_1 V_9 ;
int V_28 ;
F_8 ( V_8 , 0x0 , V_132 ) ;
V_9 = F_9 ( V_8 , V_133 ) ;
V_9 |= V_134 ;
F_8 ( V_8 , V_9 , V_133 ) ;
V_9 = F_9 ( V_8 , V_59 -> V_129 ) ;
V_9 &= ~ ( V_135 | V_136 ) ;
V_9 |= V_137 | V_59 -> V_138 ;
F_8 ( V_8 , V_9 , V_59 -> V_129 ) ;
V_9 = F_9 ( V_8 , V_59 -> V_129 ) ;
V_9 &= ~ V_139 ;
F_8 ( V_8 , V_9 , V_59 -> V_129 ) ;
F_29 ( 20 , 100 ) ;
V_9 = F_9 ( V_8 , V_59 -> V_129 ) ;
V_9 |= V_139 ;
F_8 ( V_8 , V_9 , V_59 -> V_129 ) ;
V_9 = V_140 | ( V_140 << 16 ) ;
F_8 ( V_8 , V_9 , V_141 ) ;
if ( V_59 -> V_142 > 2 )
F_8 ( V_8 , V_140 , V_143 ) ;
V_28 = F_53 ( V_8 , 500 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_20 , V_28 ) ;
return V_28 ;
}
V_9 = F_9 ( V_8 , V_133 ) ;
V_9 &= ~ V_134 ;
F_8 ( V_8 , V_9 , V_133 ) ;
V_9 = F_9 ( V_8 , V_133 ) ;
V_9 |= V_144 | V_145 ;
F_8 ( V_8 , V_9 , V_133 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
struct V_48 * V_49 ;
unsigned long V_9 ;
int V_28 ;
if ( V_8 -> V_146 ) {
V_9 = F_6 ( V_8 , V_147 ) ;
V_9 &= ~ V_148 ;
V_9 |= V_149 ;
F_4 ( V_8 , V_9 , V_147 ) ;
}
if ( V_59 -> V_150 )
F_4 ( V_8 , 0 , V_151 ) ;
V_9 = F_6 ( V_8 , V_152 ) ;
V_9 &= ~ V_153 ;
V_9 |= V_154 | V_8 -> V_155 ;
F_23 (port, &pcie->ports, list)
V_9 &= ~ F_58 ( V_49 -> V_50 ) ;
F_4 ( V_8 , V_9 , V_152 ) ;
if ( V_59 -> V_156 ) {
V_9 = F_6 ( V_8 , V_157 ) ;
V_9 &= ~ V_158 ;
F_4 ( V_8 , V_9 , V_157 ) ;
} else {
V_9 = F_6 ( V_8 , V_157 ) ;
V_9 |= V_158 ;
F_4 ( V_8 , V_9 , V_157 ) ;
}
if ( ! V_8 -> V_146 )
V_28 = F_56 ( V_8 ) ;
else
V_28 = F_59 ( V_8 -> V_146 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_21 , V_28 ) ;
return V_28 ;
}
F_60 ( V_8 -> V_159 ) ;
V_9 = F_6 ( V_8 , V_160 ) ;
V_9 |= V_161 ;
F_4 ( V_8 , V_9 , V_160 ) ;
V_9 = V_162 | V_163 |
V_164 | V_165 |
V_166 | V_167 ;
if ( V_59 -> V_168 )
V_9 |= V_169 ;
F_4 ( V_8 , V_9 , V_170 ) ;
F_4 ( V_8 , 0xffffffff , V_171 ) ;
F_4 ( V_8 , V_172 , V_173 ) ;
F_4 ( V_8 , 0 , V_174 ) ;
return 0 ;
}
static void F_61 ( struct V_4 * V_8 )
{
int V_28 ;
V_28 = F_62 ( V_8 -> V_146 ) ;
if ( V_28 < 0 )
F_63 ( V_8 -> V_41 , L_22 , V_28 ) ;
F_64 ( V_8 -> V_159 ) ;
F_64 ( V_8 -> V_175 ) ;
F_64 ( V_8 -> V_176 ) ;
F_65 ( V_177 ) ;
V_28 = F_66 ( V_8 -> V_178 , V_8 -> V_179 ) ;
if ( V_28 < 0 )
F_63 ( V_8 -> V_41 , L_23 , V_28 ) ;
}
static int F_67 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
int V_28 ;
F_64 ( V_8 -> V_159 ) ;
F_64 ( V_8 -> V_175 ) ;
F_64 ( V_8 -> V_176 ) ;
F_65 ( V_177 ) ;
V_28 = F_68 ( V_8 -> V_178 , V_8 -> V_179 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_24 , V_28 ) ;
V_28 = F_69 ( V_177 ,
V_8 -> V_180 ,
V_8 -> V_176 ) ;
if ( V_28 ) {
F_19 ( V_8 -> V_41 , L_25 , V_28 ) ;
return V_28 ;
}
F_60 ( V_8 -> V_175 ) ;
V_28 = F_70 ( V_8 -> V_181 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_26 , V_28 ) ;
return V_28 ;
}
if ( V_59 -> V_182 ) {
V_28 = F_70 ( V_8 -> V_183 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_27 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_70 ( V_8 -> V_184 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_28 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_71 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
V_8 -> V_180 = F_72 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_180 ) )
return F_73 ( V_8 -> V_180 ) ;
V_8 -> V_181 = F_72 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_181 ) )
return F_73 ( V_8 -> V_181 ) ;
V_8 -> V_184 = F_72 ( V_8 -> V_41 , L_31 ) ;
if ( F_24 ( V_8 -> V_184 ) )
return F_73 ( V_8 -> V_184 ) ;
if ( V_59 -> V_182 ) {
V_8 -> V_183 = F_72 ( V_8 -> V_41 , L_32 ) ;
if ( F_24 ( V_8 -> V_183 ) )
return F_73 ( V_8 -> V_183 ) ;
}
return 0 ;
}
static int F_74 ( struct V_4 * V_8 )
{
V_8 -> V_176 = F_75 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_176 ) )
return F_73 ( V_8 -> V_176 ) ;
V_8 -> V_175 = F_75 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_175 ) )
return F_73 ( V_8 -> V_175 ) ;
V_8 -> V_159 = F_75 ( V_8 -> V_41 , L_33 ) ;
if ( F_24 ( V_8 -> V_159 ) )
return F_73 ( V_8 -> V_159 ) ;
return 0 ;
}
static int F_76 ( struct V_4 * V_8 )
{
struct V_185 * V_79 = F_77 ( V_8 -> V_41 ) ;
struct V_186 * V_12 , * V_11 , * V_187 ;
int V_28 ;
V_28 = F_71 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_34 , V_28 ) ;
return V_28 ;
}
V_28 = F_74 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_35 , V_28 ) ;
return V_28 ;
}
V_8 -> V_146 = F_78 ( V_8 -> V_41 , L_36 ) ;
if ( F_24 ( V_8 -> V_146 ) ) {
V_28 = F_73 ( V_8 -> V_146 ) ;
F_19 ( & V_79 -> V_41 , L_37 , V_28 ) ;
return V_28 ;
}
V_28 = F_79 ( V_8 -> V_146 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_38 , V_28 ) ;
return V_28 ;
}
V_28 = F_67 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_39 , V_28 ) ;
return V_28 ;
}
V_12 = F_80 ( V_79 , V_188 , L_40 ) ;
V_8 -> V_12 = F_81 ( & V_79 -> V_41 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_73 ( V_8 -> V_12 ) ;
goto V_189;
}
V_11 = F_80 ( V_79 , V_188 , L_30 ) ;
V_8 -> V_11 = F_81 ( & V_79 -> V_41 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_73 ( V_8 -> V_11 ) ;
goto V_189;
}
V_187 = F_80 ( V_79 , V_188 , L_41 ) ;
if ( ! V_187 ) {
V_28 = - V_190 ;
goto V_189;
}
V_8 -> V_24 = F_82 ( V_8 -> V_41 , V_187 -> V_25 ,
F_35 ( V_187 ) , V_187 -> V_191 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_190 ;
goto V_189;
}
V_28 = F_83 ( V_79 , L_42 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_43 , V_28 ) ;
goto V_189;
}
V_8 -> V_81 = V_28 ;
V_28 = F_84 ( V_8 -> V_81 , F_49 , V_192 , L_44 , V_8 ) ;
if ( V_28 ) {
F_19 ( & V_79 -> V_41 , L_45 , V_28 ) ;
goto V_189;
}
return 0 ;
V_189:
F_61 ( V_8 ) ;
return V_28 ;
}
static int F_85 ( struct V_4 * V_8 )
{
int V_28 ;
if ( V_8 -> V_81 > 0 )
F_86 ( V_8 -> V_81 , V_8 ) ;
F_61 ( V_8 ) ;
V_28 = F_87 ( V_8 -> V_146 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_46 , V_28 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_3 )
{
int V_193 ;
F_89 ( & V_3 -> V_194 ) ;
V_193 = F_90 ( V_3 -> V_195 , V_196 ) ;
if ( V_193 < V_196 )
F_91 ( V_193 , V_3 -> V_195 ) ;
else
V_193 = - V_197 ;
F_92 ( & V_3 -> V_194 ) ;
return V_193 ;
}
static void F_93 ( struct V_1 * V_3 , unsigned long V_81 )
{
struct V_198 * V_41 = V_3 -> V_3 . V_41 ;
F_89 ( & V_3 -> V_194 ) ;
if ( ! F_94 ( V_81 , V_3 -> V_195 ) )
F_19 ( V_41 , L_47 , V_81 ) ;
else
F_95 ( V_81 , V_3 -> V_195 ) ;
F_92 ( & V_3 -> V_194 ) ;
}
static T_6 F_96 ( int V_81 , void * V_199 )
{
struct V_4 * V_8 = V_199 ;
struct V_1 * V_193 = & V_8 -> V_193 ;
unsigned int V_27 , V_200 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_201 = F_6 ( V_8 , V_202 + V_27 * 4 ) ;
while ( V_201 ) {
unsigned int V_10 = F_97 ( & V_201 , 32 ) ;
unsigned int V_50 = V_27 * 32 + V_10 ;
unsigned int V_81 ;
F_4 ( V_8 , 1 << V_10 , V_202 + V_27 * 4 ) ;
V_81 = F_98 ( V_193 -> V_203 , V_50 ) ;
if ( V_81 ) {
if ( F_94 ( V_50 , V_193 -> V_195 ) )
F_99 ( V_81 ) ;
else
F_100 ( V_8 -> V_41 , L_48 ) ;
} else {
F_100 ( V_8 -> V_41 , L_49 ) ;
}
V_201 = F_6 ( V_8 , V_202 + V_27 * 4 ) ;
V_200 ++ ;
}
}
return V_200 > 0 ? V_97 : V_90 ;
}
static int F_101 ( struct V_2 * V_3 ,
struct V_66 * V_79 , struct V_204 * V_205 )
{
struct V_1 * V_193 = F_1 ( V_3 ) ;
struct V_206 V_207 ;
unsigned int V_81 ;
int V_208 ;
V_208 = F_88 ( V_193 ) ;
if ( V_208 < 0 )
return V_208 ;
V_81 = F_102 ( V_193 -> V_203 , V_208 ) ;
if ( ! V_81 ) {
F_93 ( V_193 , V_208 ) ;
return - V_209 ;
}
F_103 ( V_81 , V_205 ) ;
V_207 . V_210 = F_104 ( ( void * ) V_193 -> V_211 ) ;
V_207 . V_212 = 0 ;
V_207 . V_199 = V_208 ;
F_105 ( V_81 , & V_207 ) ;
return 0 ;
}
static void F_106 ( struct V_2 * V_3 ,
unsigned int V_81 )
{
struct V_1 * V_193 = F_1 ( V_3 ) ;
struct V_213 * V_214 = F_107 ( V_81 ) ;
T_8 V_208 = F_108 ( V_214 ) ;
F_109 ( V_81 ) ;
F_93 ( V_193 , V_208 ) ;
}
static int F_110 ( struct V_215 * V_203 , unsigned int V_81 ,
T_8 V_208 )
{
F_111 ( V_81 , & V_216 , V_217 ) ;
F_112 ( V_81 , V_203 -> V_218 ) ;
F_47 () ;
return 0 ;
}
static int F_113 ( struct V_4 * V_8 )
{
struct V_185 * V_79 = F_77 ( V_8 -> V_41 ) ;
const struct V_58 * V_59 = V_8 -> V_60 ;
struct V_1 * V_193 = & V_8 -> V_193 ;
unsigned long V_51 ;
int V_28 ;
T_1 V_201 ;
F_114 ( & V_193 -> V_194 ) ;
V_193 -> V_3 . V_41 = V_8 -> V_41 ;
V_193 -> V_3 . V_219 = F_101 ;
V_193 -> V_3 . V_220 = F_106 ;
V_193 -> V_203 = F_115 ( V_8 -> V_41 -> V_221 , V_196 ,
& V_222 , & V_193 -> V_3 ) ;
if ( ! V_193 -> V_203 ) {
F_19 ( & V_79 -> V_41 , L_50 ) ;
return - V_30 ;
}
V_28 = F_83 ( V_79 , L_51 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_43 , V_28 ) ;
goto V_28;
}
V_193 -> V_81 = V_28 ;
V_28 = F_84 ( V_193 -> V_81 , F_96 , 0 ,
V_216 . V_191 , V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_52 , V_28 ) ;
goto V_28;
}
V_193 -> V_211 = F_116 ( V_29 , 0 ) ;
V_51 = F_104 ( ( void * ) V_193 -> V_211 ) ;
F_4 ( V_8 , V_51 >> V_59 -> V_223 , V_124 ) ;
F_4 ( V_8 , V_51 , V_126 ) ;
F_4 ( V_8 , 1 , V_125 ) ;
F_4 ( V_8 , 0xffffffff , V_224 ) ;
F_4 ( V_8 , 0xffffffff , V_225 ) ;
F_4 ( V_8 , 0xffffffff , V_226 ) ;
F_4 ( V_8 , 0xffffffff , V_227 ) ;
F_4 ( V_8 , 0xffffffff , V_228 ) ;
F_4 ( V_8 , 0xffffffff , V_229 ) ;
F_4 ( V_8 , 0xffffffff , V_230 ) ;
F_4 ( V_8 , 0xffffffff , V_231 ) ;
V_201 = F_6 ( V_8 , V_173 ) ;
V_201 |= V_232 ;
F_4 ( V_8 , V_201 , V_173 ) ;
return 0 ;
V_28:
F_117 ( V_193 -> V_203 ) ;
return V_28 ;
}
static int F_118 ( struct V_4 * V_8 )
{
struct V_1 * V_193 = & V_8 -> V_193 ;
unsigned int V_27 , V_81 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_173 ) ;
V_9 &= ~ V_232 ;
F_4 ( V_8 , V_9 , V_173 ) ;
F_4 ( V_8 , 0 , V_224 ) ;
F_4 ( V_8 , 0 , V_225 ) ;
F_4 ( V_8 , 0 , V_226 ) ;
F_4 ( V_8 , 0 , V_227 ) ;
F_4 ( V_8 , 0 , V_228 ) ;
F_4 ( V_8 , 0 , V_229 ) ;
F_4 ( V_8 , 0 , V_230 ) ;
F_4 ( V_8 , 0 , V_231 ) ;
F_119 ( V_193 -> V_211 , 0 ) ;
if ( V_193 -> V_81 > 0 )
F_86 ( V_193 -> V_81 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_196 ; V_27 ++ ) {
V_81 = F_98 ( V_193 -> V_203 , V_27 ) ;
if ( V_81 > 0 )
F_109 ( V_81 ) ;
}
F_117 ( V_193 -> V_203 ) ;
return 0 ;
}
static int F_120 ( struct V_4 * V_8 , T_1 V_233 ,
T_1 * V_234 )
{
struct V_235 * V_236 = V_8 -> V_41 -> V_221 ;
if ( F_121 ( V_236 , L_53 ) ) {
switch ( V_233 ) {
case 0x0000104 :
F_100 ( V_8 -> V_41 , L_54 ) ;
* V_234 = V_237 ;
return 0 ;
case 0x0000102 :
F_100 ( V_8 -> V_41 , L_55 ) ;
* V_234 = V_238 ;
return 0 ;
}
} else if ( F_121 ( V_236 , L_56 ) ) {
switch ( V_233 ) {
case 0x00000204 :
F_100 ( V_8 -> V_41 , L_57 ) ;
* V_234 = V_239 ;
return 0 ;
case 0x00020202 :
F_100 ( V_8 -> V_41 , L_58 ) ;
* V_234 = V_240 ;
return 0 ;
case 0x00010104 :
F_100 ( V_8 -> V_41 , L_59 ) ;
* V_234 = V_241 ;
return 0 ;
}
} else if ( F_121 ( V_236 , L_60 ) ) {
switch ( V_233 ) {
case 0x00000004 :
F_100 ( V_8 -> V_41 , L_61 ) ;
* V_234 = V_242 ;
return 0 ;
case 0x00000202 :
F_100 ( V_8 -> V_41 , L_62 ) ;
* V_234 = V_243 ;
return 0 ;
}
}
return - V_209 ;
}
static bool F_122 ( struct V_235 * V_236 ,
struct V_244 * V_179 ,
unsigned int V_178 )
{
char V_245 [ 32 ] ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_178 ; V_27 ++ ) {
snprintf ( V_245 , 32 , L_63 , V_179 [ V_27 ] . V_246 ) ;
if ( F_123 ( V_236 , V_245 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_124 ( struct V_4 * V_8 )
{
struct V_235 * V_236 = V_8 -> V_41 -> V_221 ;
if ( F_121 ( V_236 , L_56 ) )
V_8 -> V_178 = 3 ;
else if ( F_121 ( V_236 , L_60 ) )
V_8 -> V_178 = 2 ;
if ( V_8 -> V_178 == 0 ) {
F_19 ( V_8 -> V_41 , L_64 ,
V_236 -> V_247 ) ;
return - V_248 ;
}
V_8 -> V_179 = F_125 ( V_8 -> V_41 , V_8 -> V_178 ,
sizeof( * V_8 -> V_179 ) ,
V_29 ) ;
if ( ! V_8 -> V_179 )
return - V_30 ;
V_8 -> V_179 [ 0 ] . V_246 = L_65 ;
V_8 -> V_179 [ 1 ] . V_246 = L_66 ;
if ( V_8 -> V_178 > 2 )
V_8 -> V_179 [ 2 ] . V_246 = L_67 ;
return F_126 ( V_8 -> V_41 , V_8 -> V_178 ,
V_8 -> V_179 ) ;
}
static int F_127 ( struct V_4 * V_8 , T_1 V_249 )
{
struct V_235 * V_236 = V_8 -> V_41 -> V_221 ;
unsigned int V_27 = 0 ;
if ( F_121 ( V_236 , L_53 ) ) {
V_8 -> V_178 = 7 ;
V_8 -> V_179 = F_125 ( V_8 -> V_41 , V_8 -> V_178 ,
sizeof( * V_8 -> V_179 ) ,
V_29 ) ;
if ( ! V_8 -> V_179 )
return - V_30 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_68 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_69 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_70 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_71 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_72 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_73 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_74 ;
} else if ( F_121 ( V_236 , L_56 ) ) {
bool V_250 = false , V_251 = false ;
if ( V_249 & 0x0f )
V_250 = true ;
if ( V_249 & 0x30 )
V_251 = true ;
V_8 -> V_178 = 4 + ( V_250 ? 2 : 0 ) +
( V_251 ? 2 : 0 ) ;
V_8 -> V_179 = F_125 ( V_8 -> V_41 , V_8 -> V_178 ,
sizeof( * V_8 -> V_179 ) ,
V_29 ) ;
if ( ! V_8 -> V_179 )
return - V_30 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_70 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_71 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_73 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_75 ;
if ( V_250 ) {
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_76 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_77 ;
}
if ( V_251 ) {
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_78 ;
V_8 -> V_179 [ V_27 ++ ] . V_246 = L_79 ;
}
} else if ( F_121 ( V_236 , L_60 ) ) {
V_8 -> V_178 = 5 ;
V_8 -> V_179 = F_125 ( V_8 -> V_41 , V_8 -> V_178 ,
sizeof( * V_8 -> V_179 ) ,
V_29 ) ;
if ( ! V_8 -> V_179 )
return - V_30 ;
V_8 -> V_179 [ 0 ] . V_246 = L_80 ;
V_8 -> V_179 [ 1 ] . V_246 = L_81 ;
V_8 -> V_179 [ 2 ] . V_246 = L_70 ;
V_8 -> V_179 [ 3 ] . V_246 = L_75 ;
V_8 -> V_179 [ 4 ] . V_246 = L_82 ;
}
if ( F_122 ( V_8 -> V_41 -> V_221 , V_8 -> V_179 ,
V_8 -> V_178 ) )
return F_126 ( V_8 -> V_41 , V_8 -> V_178 ,
V_8 -> V_179 ) ;
F_100 ( V_8 -> V_41 , L_83 ) ;
F_37 ( V_8 -> V_41 , V_8 -> V_179 ) ;
V_8 -> V_178 = 0 ;
return F_124 ( V_8 ) ;
}
static int F_128 ( struct V_4 * V_8 )
{
const struct V_58 * V_59 = V_8 -> V_60 ;
struct V_235 * V_236 = V_8 -> V_41 -> V_221 , * V_49 ;
struct V_252 V_253 ;
struct V_254 V_255 ;
T_1 V_233 = 0 , V_256 = 0 ;
unsigned int V_257 = 0 ;
struct V_186 V_187 ;
int V_28 ;
memset ( & V_8 -> V_71 , 0 , sizeof( V_8 -> V_71 ) ) ;
V_8 -> V_71 . V_258 = V_188 ;
V_8 -> V_71 . V_191 = V_236 -> V_247 ;
V_8 -> V_71 . V_25 = ~ 0 ;
V_8 -> V_71 . V_259 = 0 ;
if ( F_129 ( & V_253 , V_236 ) ) {
F_19 ( V_8 -> V_41 , L_84 ) ;
return - V_209 ;
}
F_130 (&parser, &range) {
V_28 = F_131 ( & V_255 , V_236 , & V_187 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_187 . V_258 & V_260 ) {
case V_261 :
memcpy ( & V_8 -> V_77 , & V_187 , sizeof( V_187 ) ) ;
V_8 -> V_77 . V_191 = V_236 -> V_247 ;
V_8 -> V_78 . V_25 = V_255 . V_262 ;
V_8 -> V_78 . V_259 = V_255 . V_262 + V_255 . V_99 - 1 ;
V_8 -> V_78 . V_258 = V_188 ;
V_8 -> V_78 . V_191 = L_85 ;
memcpy ( & V_187 , & V_8 -> V_78 , sizeof( V_187 ) ) ;
break;
case V_188 :
if ( V_187 . V_258 & V_263 ) {
memcpy ( & V_8 -> V_73 , & V_187 , sizeof( V_187 ) ) ;
V_8 -> V_73 . V_191 = L_86 ;
} else {
memcpy ( & V_8 -> V_72 , & V_187 , sizeof( V_187 ) ) ;
V_8 -> V_72 . V_191 = L_87 ;
}
break;
}
if ( V_187 . V_25 <= V_8 -> V_71 . V_25 )
V_8 -> V_71 . V_25 = V_187 . V_25 ;
if ( V_187 . V_259 >= V_8 -> V_71 . V_259 )
V_8 -> V_71 . V_259 = V_187 . V_259 ;
}
V_28 = F_42 ( V_8 -> V_41 , & V_264 , & V_8 -> V_71 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_132 ( V_236 , & V_8 -> V_76 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_88 ,
V_28 ) ;
V_8 -> V_76 . V_191 = V_236 -> V_191 ;
V_8 -> V_76 . V_25 = 0 ;
V_8 -> V_76 . V_259 = 0xff ;
V_8 -> V_76 . V_258 = V_265 ;
}
F_133 (np, port) {
struct V_48 * V_266 ;
unsigned int V_50 ;
T_1 V_9 ;
V_28 = F_134 ( V_49 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
V_50 = F_11 ( V_28 ) ;
if ( V_50 < 1 || V_50 > V_59 -> V_142 ) {
F_19 ( V_8 -> V_41 , L_90 , V_50 ) ;
return - V_209 ;
}
V_50 -- ;
V_28 = F_135 ( V_49 , L_91 , & V_9 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_92 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_19 ( V_8 -> V_41 , L_93 , V_9 ) ;
return - V_209 ;
}
V_233 |= V_9 << ( V_50 << 3 ) ;
if ( ! F_136 ( V_49 ) ) {
V_257 += V_9 ;
continue;
}
V_256 |= ( ( 1 << V_9 ) - 1 ) << V_257 ;
V_257 += V_9 ;
V_266 = F_137 ( V_8 -> V_41 , sizeof( * V_266 ) , V_29 ) ;
if ( ! V_266 )
return - V_30 ;
V_28 = F_138 ( V_49 , 0 , & V_266 -> V_65 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
F_16 ( & V_266 -> V_31 ) ;
V_266 -> V_50 = V_50 ;
V_266 -> V_233 = V_9 ;
V_266 -> V_8 = V_8 ;
V_266 -> V_51 = F_81 ( V_8 -> V_41 , & V_266 -> V_65 ) ;
if ( F_24 ( V_266 -> V_51 ) )
return F_73 ( V_266 -> V_51 ) ;
F_25 ( & V_266 -> V_31 , & V_8 -> V_267 ) ;
}
V_28 = F_120 ( V_8 , V_233 , & V_8 -> V_155 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_94 ) ;
return V_28 ;
}
V_28 = F_127 ( V_8 , V_256 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
static bool F_139 ( struct V_48 * V_49 )
{
unsigned int V_268 = 3 ;
unsigned long V_9 ;
V_9 = F_7 ( V_49 -> V_51 + V_269 ) ;
V_9 &= ~ V_270 ;
V_9 |= V_271 ;
F_5 ( V_9 , V_49 -> V_51 + V_269 ) ;
do {
unsigned int V_127 = V_272 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_273 ) ;
if ( V_9 & V_274 )
break;
F_29 ( 1000 , 2000 ) ;
} while ( -- V_127 );
if ( ! V_127 ) {
F_19 ( V_49 -> V_8 -> V_41 , L_95 ,
V_49 -> V_50 ) ;
goto V_275;
}
V_127 = V_272 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_276 ) ;
if ( V_9 & V_277 )
return true ;
F_29 ( 1000 , 2000 ) ;
} while ( -- V_127 );
V_275:
F_28 ( V_49 ) ;
} while ( -- V_268 );
return false ;
}
static int F_140 ( struct V_4 * V_8 )
{
struct V_48 * V_49 , * V_278 ;
struct V_279 V_280 ;
F_141 (port, tmp, &pcie->ports, list) {
F_100 ( V_8 -> V_41 , L_96 ,
V_49 -> V_50 , V_49 -> V_233 ) ;
F_30 ( V_49 ) ;
if ( F_139 ( V_49 ) )
continue;
F_100 ( V_8 -> V_41 , L_97 , V_49 -> V_50 ) ;
F_31 ( V_49 ) ;
F_32 ( V_49 ) ;
}
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
#ifdef F_142
V_280 . V_281 = & V_8 -> V_193 . V_3 ;
#endif
V_280 . V_282 = 1 ;
V_280 . V_7 = ( void * * ) & V_8 ;
V_280 . V_283 = F_41 ;
V_280 . V_284 = F_46 ;
V_280 . V_285 = & V_286 ;
F_143 ( V_8 -> V_41 , & V_280 ) ;
return 0 ;
}
static void * F_144 ( struct V_287 * V_288 , T_9 * V_289 )
{
struct V_4 * V_8 = V_288 -> V_290 ;
if ( F_145 ( & V_8 -> V_267 ) )
return NULL ;
F_146 ( V_288 , L_98 ) ;
return F_147 ( & V_8 -> V_267 , * V_289 ) ;
}
static void * F_148 ( struct V_287 * V_288 , void * V_291 , T_9 * V_289 )
{
struct V_4 * V_8 = V_288 -> V_290 ;
return F_149 ( V_291 , & V_8 -> V_267 , V_289 ) ;
}
static void F_150 ( struct V_287 * V_288 , void * V_291 )
{
}
static int F_151 ( struct V_287 * V_288 , void * V_291 )
{
bool V_292 = false , V_293 = false ;
struct V_48 * V_49 ;
unsigned int V_9 ;
V_49 = F_152 ( V_291 , struct V_48 , V_31 ) ;
V_9 = F_7 ( V_49 -> V_51 + V_273 ) ;
if ( V_9 & V_274 )
V_292 = true ;
V_9 = F_7 ( V_49 -> V_51 + V_276 ) ;
if ( V_9 & V_277 )
V_293 = true ;
F_146 ( V_288 , L_99 , V_49 -> V_50 ) ;
if ( V_292 )
F_146 ( V_288 , L_100 ) ;
if ( V_293 ) {
if ( V_292 )
F_146 ( V_288 , L_101 ) ;
F_146 ( V_288 , L_102 ) ;
}
F_146 ( V_288 , L_103 ) ;
return 0 ;
}
static int F_153 ( struct V_294 * V_294 , struct V_295 * V_295 )
{
struct V_4 * V_8 = V_294 -> V_296 ;
struct V_287 * V_288 ;
int V_28 ;
V_28 = F_154 ( V_295 , & V_297 ) ;
if ( V_28 )
return V_28 ;
V_288 = V_295 -> V_7 ;
V_288 -> V_290 = V_8 ;
return 0 ;
}
static int F_155 ( struct V_4 * V_8 )
{
struct V_298 * V_295 ;
V_8 -> V_299 = F_156 ( L_36 , NULL ) ;
if ( ! V_8 -> V_299 )
return - V_30 ;
V_295 = F_157 ( L_104 , V_300 | V_301 , V_8 -> V_299 ,
V_8 , & V_302 ) ;
if ( ! V_295 )
goto remove;
return 0 ;
remove:
F_158 ( V_8 -> V_299 ) ;
V_8 -> V_299 = NULL ;
return - V_30 ;
}
static int F_159 ( struct V_185 * V_79 )
{
const struct V_303 * V_304 ;
struct V_4 * V_8 ;
int V_28 ;
V_304 = F_160 ( V_305 , & V_79 -> V_41 ) ;
if ( ! V_304 )
return - V_248 ;
V_8 = F_137 ( & V_79 -> V_41 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_16 ( & V_8 -> V_43 ) ;
F_16 ( & V_8 -> V_267 ) ;
V_8 -> V_60 = V_304 -> V_199 ;
V_8 -> V_41 = & V_79 -> V_41 ;
V_28 = F_128 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_306 = 0 ;
V_28 = F_76 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_105 , V_28 ) ;
return V_28 ;
}
V_28 = F_57 ( V_8 ) ;
if ( V_28 )
goto V_307;
F_52 ( V_8 ) ;
if ( F_161 ( F_142 ) ) {
V_28 = F_113 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 ,
L_106 ,
V_28 ) ;
goto V_307;
}
}
V_28 = F_140 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_79 -> V_41 , L_107 , V_28 ) ;
goto V_308;
}
if ( F_161 ( V_309 ) ) {
V_28 = F_155 ( V_8 ) ;
if ( V_28 < 0 )
F_19 ( & V_79 -> V_41 , L_108 ,
V_28 ) ;
}
F_162 ( V_79 , V_8 ) ;
return 0 ;
V_308:
if ( F_161 ( F_142 ) )
F_118 ( V_8 ) ;
V_307:
F_85 ( V_8 ) ;
return V_28 ;
}
