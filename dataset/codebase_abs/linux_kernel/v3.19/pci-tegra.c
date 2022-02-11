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
static int F_27 ( struct V_44 * V_26 , unsigned int V_13 ,
int V_14 , int V_52 , T_1 * V_9 )
{
void T_4 * V_37 ;
V_37 = F_26 ( V_26 , V_13 , V_14 ) ;
if ( ! V_37 ) {
* V_9 = 0xffffffff ;
return V_53 ;
}
* V_9 = F_7 ( V_37 ) ;
if ( V_52 == 1 )
* V_9 = ( * V_9 >> ( 8 * ( V_14 & 3 ) ) ) & 0xff ;
else if ( V_52 == 2 )
* V_9 = ( * V_9 >> ( 8 * ( V_14 & 3 ) ) ) & 0xffff ;
return V_54 ;
}
static int F_28 ( struct V_44 * V_26 , unsigned int V_13 ,
int V_14 , int V_52 , T_1 V_9 )
{
void T_4 * V_37 ;
T_1 V_55 , V_56 ;
V_37 = F_26 ( V_26 , V_13 , V_14 ) ;
if ( ! V_37 )
return V_53 ;
if ( V_52 == 4 ) {
F_5 ( V_9 , V_37 ) ;
return V_54 ;
}
if ( V_52 == 2 )
V_55 = ~ ( 0xffff << ( ( V_14 & 0x3 ) * 8 ) ) ;
else if ( V_52 == 1 )
V_55 = ~ ( 0xff << ( ( V_14 & 0x3 ) * 8 ) ) ;
else
return V_57 ;
V_56 = F_7 ( V_37 ) & V_55 ;
V_56 |= V_9 << ( ( V_14 & 0x3 ) * 8 ) ;
F_5 ( V_56 , V_37 ) ;
return V_54 ;
}
static unsigned long F_29 ( struct V_48 * V_49 )
{
unsigned long V_58 = 0 ;
switch ( V_49 -> V_50 ) {
case 0 :
V_58 = V_59 ;
break;
case 1 :
V_58 = V_60 ;
break;
case 2 :
V_58 = V_61 ;
break;
}
return V_58 ;
}
static void F_30 ( struct V_48 * V_49 )
{
unsigned long V_62 = F_29 ( V_49 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_49 -> V_8 , V_62 ) ;
V_9 &= ~ V_63 ;
F_4 ( V_49 -> V_8 , V_9 , V_62 ) ;
F_31 ( 1000 , 2000 ) ;
V_9 = F_6 ( V_49 -> V_8 , V_62 ) ;
V_9 |= V_63 ;
F_4 ( V_49 -> V_8 , V_9 , V_62 ) ;
}
static void F_32 ( struct V_48 * V_49 )
{
const struct V_64 * V_65 = V_49 -> V_8 -> V_66 ;
unsigned long V_62 = F_29 ( V_49 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_49 -> V_8 , V_62 ) ;
V_9 |= V_67 ;
if ( V_65 -> V_68 )
V_9 |= V_69 ;
V_9 |= V_70 ;
F_4 ( V_49 -> V_8 , V_9 , V_62 ) ;
F_30 ( V_49 ) ;
}
static void F_33 ( struct V_48 * V_49 )
{
const struct V_64 * V_65 = V_49 -> V_8 -> V_66 ;
unsigned long V_62 = F_29 ( V_49 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_49 -> V_8 , V_62 ) ;
V_9 &= ~ V_63 ;
F_4 ( V_49 -> V_8 , V_9 , V_62 ) ;
V_9 = F_6 ( V_49 -> V_8 , V_62 ) ;
if ( V_65 -> V_68 )
V_9 &= ~ V_69 ;
V_9 &= ~ V_67 ;
F_4 ( V_49 -> V_8 , V_9 , V_62 ) ;
}
static void F_34 ( struct V_48 * V_49 )
{
struct V_4 * V_8 = V_49 -> V_8 ;
F_35 ( V_8 -> V_41 , V_49 -> V_51 ) ;
F_36 ( V_8 -> V_41 , V_49 -> V_71 . V_25 ,
F_37 ( & V_49 -> V_71 ) ) ;
F_38 ( & V_49 -> V_31 ) ;
F_39 ( V_8 -> V_41 , V_49 ) ;
}
static void F_40 ( struct V_72 * V_41 )
{
T_5 V_73 ;
if ( ( V_41 -> V_74 >> 16 ) == V_75 ) {
F_41 ( V_41 , V_76 , & V_73 ) ;
V_73 |= ( V_77 | V_78 |
V_79 | V_80 ) ;
F_42 ( V_41 , V_76 , V_73 ) ;
}
}
static void F_43 ( struct V_72 * V_41 )
{
V_41 -> V_74 = V_81 << 8 ;
}
static void F_44 ( struct V_72 * V_41 )
{
F_45 ( V_41 , V_82 , V_83 ) ;
}
static int F_46 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
int V_28 ;
V_28 = F_47 ( V_8 -> V_41 , & V_8 -> V_84 , & V_8 -> V_85 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_47 ( V_8 -> V_41 , & V_8 -> V_84 , & V_8 -> V_86 ) ;
if ( V_28 )
return V_28 ;
F_48 ( & V_6 -> V_87 , & V_8 -> V_85 , V_6 -> V_88 ) ;
F_48 ( & V_6 -> V_87 , & V_8 -> V_86 ,
V_6 -> V_88 ) ;
F_49 ( & V_6 -> V_87 , & V_8 -> V_89 ) ;
F_50 ( V_8 -> V_90 . V_25 , V_8 -> V_91 . V_25 ) ;
return 1 ;
}
static int F_51 ( const struct V_72 * V_92 , T_6 V_47 , T_6 V_93 )
{
struct V_4 * V_8 = F_3 ( V_92 -> V_26 -> V_45 ) ;
int V_94 ;
F_52 () ;
V_94 = F_53 ( V_92 , V_47 , V_93 ) ;
if ( ! V_94 )
V_94 = V_8 -> V_94 ;
return V_94 ;
}
static struct V_44 * F_54 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
struct V_44 * V_26 ;
V_26 = F_55 ( V_8 -> V_41 , V_6 -> V_16 , & V_95 , V_6 ,
& V_6 -> V_87 ) ;
if ( ! V_26 )
return NULL ;
F_56 ( V_26 ) ;
return V_26 ;
}
static T_7 F_57 ( int V_94 , void * V_96 )
{
const char * V_97 [] = {
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
struct V_4 * V_8 = V_96 ;
T_1 V_98 , V_99 ;
V_98 = F_6 ( V_8 , V_100 ) & V_101 ;
V_99 = F_6 ( V_8 , V_102 ) ;
F_4 ( V_8 , 0 , V_100 ) ;
if ( V_98 == V_103 )
return V_104 ;
if ( V_98 >= F_58 ( V_97 ) )
V_98 = 0 ;
if ( V_98 == V_105 )
F_59 ( V_8 -> V_41 , L_18 , V_97 [ V_98 ] ,
V_99 ) ;
else
F_19 ( V_8 -> V_41 , L_18 , V_97 [ V_98 ] ,
V_99 ) ;
if ( V_98 == V_106 || V_98 == V_105 ||
V_98 == V_107 ) {
T_1 V_108 = F_6 ( V_8 , V_109 ) & 0xff ;
T_8 V_110 = ( T_8 ) V_108 << 32 | ( V_99 & 0xfffffffc ) ;
if ( V_98 == V_105 )
F_59 ( V_8 -> V_41 , L_19 , V_110 ) ;
else
F_19 ( V_8 -> V_41 , L_19 , V_110 ) ;
}
return V_111 ;
}
static void F_60 ( struct V_4 * V_8 )
{
T_1 V_112 , V_52 , V_113 ;
V_112 = 0xfe100000 ;
V_52 = F_37 ( V_8 -> V_24 ) ;
V_113 = V_8 -> V_24 -> V_25 ;
F_4 ( V_8 , V_113 , V_114 ) ;
F_4 ( V_8 , V_52 >> 12 , V_115 ) ;
F_4 ( V_8 , V_112 , V_116 ) ;
V_112 = 0xfdfc0000 ;
V_52 = F_37 ( & V_8 -> V_91 ) ;
V_113 = V_8 -> V_91 . V_25 ;
F_4 ( V_8 , V_113 , V_117 ) ;
F_4 ( V_8 , V_52 >> 12 , V_118 ) ;
F_4 ( V_8 , V_112 , V_119 ) ;
V_112 = ( ( ( V_8 -> V_86 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_52 = F_37 ( & V_8 -> V_86 ) ;
V_113 = V_8 -> V_86 . V_25 ;
F_4 ( V_8 , V_113 , V_120 ) ;
F_4 ( V_8 , V_52 >> 12 , V_121 ) ;
F_4 ( V_8 , V_112 , V_122 ) ;
V_112 = ( ( ( V_8 -> V_85 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_52 = F_37 ( & V_8 -> V_85 ) ;
V_113 = V_8 -> V_85 . V_25 ;
F_4 ( V_8 , V_113 , V_123 ) ;
F_4 ( V_8 , V_52 >> 12 , V_124 ) ;
F_4 ( V_8 , V_112 , V_125 ) ;
F_4 ( V_8 , 0 , V_126 ) ;
F_4 ( V_8 , 0 , V_127 ) ;
F_4 ( V_8 , 0 , V_128 ) ;
F_4 ( V_8 , 0 , V_129 ) ;
F_4 ( V_8 , 0 , V_130 ) ;
F_4 ( V_8 , 0 , V_131 ) ;
F_4 ( V_8 , V_132 , V_133 ) ;
F_4 ( V_8 , 0 , V_134 ) ;
F_4 ( V_8 , 0 , V_135 ) ;
F_4 ( V_8 , 0 , V_136 ) ;
F_4 ( V_8 , 0 , V_137 ) ;
F_4 ( V_8 , 0 , V_138 ) ;
F_4 ( V_8 , 0 , V_139 ) ;
F_4 ( V_8 , 0 , V_138 ) ;
}
static int F_61 ( struct V_4 * V_8 , unsigned long V_140 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
T_1 V_9 ;
V_140 = V_141 + F_62 ( V_140 ) ;
while ( F_63 ( V_141 , V_140 ) ) {
V_9 = F_9 ( V_8 , V_65 -> V_142 ) ;
if ( V_9 & V_143 )
return 0 ;
}
return - V_144 ;
}
static int F_64 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
T_1 V_9 ;
int V_28 ;
F_8 ( V_8 , 0x0 , V_145 ) ;
V_9 = F_9 ( V_8 , V_146 ) ;
V_9 |= V_147 ;
F_8 ( V_8 , V_9 , V_146 ) ;
V_9 = F_9 ( V_8 , V_65 -> V_142 ) ;
V_9 &= ~ ( V_148 | V_149 ) ;
V_9 |= V_150 | V_65 -> V_151 ;
F_8 ( V_8 , V_9 , V_65 -> V_142 ) ;
V_9 = F_9 ( V_8 , V_65 -> V_142 ) ;
V_9 &= ~ V_152 ;
F_8 ( V_8 , V_9 , V_65 -> V_142 ) ;
F_31 ( 20 , 100 ) ;
V_9 = F_9 ( V_8 , V_65 -> V_142 ) ;
V_9 |= V_152 ;
F_8 ( V_8 , V_9 , V_65 -> V_142 ) ;
V_9 = V_153 | ( V_153 << 16 ) ;
F_8 ( V_8 , V_9 , V_154 ) ;
if ( V_65 -> V_155 > 2 )
F_8 ( V_8 , V_153 , V_156 ) ;
V_28 = F_61 ( V_8 , 500 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_20 , V_28 ) ;
return V_28 ;
}
V_9 = F_9 ( V_8 , V_146 ) ;
V_9 &= ~ V_147 ;
F_8 ( V_8 , V_9 , V_146 ) ;
V_9 = F_9 ( V_8 , V_146 ) ;
V_9 |= V_157 | V_158 ;
F_8 ( V_8 , V_9 , V_146 ) ;
return 0 ;
}
static int F_65 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
struct V_48 * V_49 ;
unsigned long V_9 ;
int V_28 ;
if ( V_8 -> V_159 ) {
V_9 = F_6 ( V_8 , V_160 ) ;
V_9 &= ~ V_161 ;
V_9 |= V_162 ;
F_4 ( V_8 , V_9 , V_160 ) ;
}
if ( V_65 -> V_163 )
F_4 ( V_8 , 0 , V_164 ) ;
V_9 = F_6 ( V_8 , V_165 ) ;
V_9 &= ~ V_166 ;
V_9 |= V_167 | V_8 -> V_168 ;
F_23 (port, &pcie->ports, list)
V_9 &= ~ F_66 ( V_49 -> V_50 ) ;
F_4 ( V_8 , V_9 , V_165 ) ;
if ( V_65 -> V_169 ) {
V_9 = F_6 ( V_8 , V_170 ) ;
V_9 &= ~ V_171 ;
F_4 ( V_8 , V_9 , V_170 ) ;
} else {
V_9 = F_6 ( V_8 , V_170 ) ;
V_9 |= V_171 ;
F_4 ( V_8 , V_9 , V_170 ) ;
}
if ( ! V_8 -> V_159 )
V_28 = F_64 ( V_8 ) ;
else
V_28 = F_67 ( V_8 -> V_159 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_21 , V_28 ) ;
return V_28 ;
}
F_68 ( V_8 -> V_172 ) ;
V_9 = F_6 ( V_8 , V_173 ) ;
V_9 |= V_174 ;
F_4 ( V_8 , V_9 , V_173 ) ;
V_9 = V_175 | V_176 |
V_177 | V_178 |
V_179 | V_180 ;
if ( V_65 -> V_181 )
V_9 |= V_182 ;
F_4 ( V_8 , V_9 , V_183 ) ;
F_4 ( V_8 , 0xffffffff , V_184 ) ;
F_4 ( V_8 , V_185 , V_186 ) ;
F_4 ( V_8 , 0 , V_187 ) ;
return 0 ;
}
static void F_69 ( struct V_4 * V_8 )
{
int V_28 ;
V_28 = F_70 ( V_8 -> V_159 ) ;
if ( V_28 < 0 )
F_71 ( V_8 -> V_41 , L_22 , V_28 ) ;
F_72 ( V_8 -> V_172 ) ;
F_72 ( V_8 -> V_188 ) ;
F_72 ( V_8 -> V_189 ) ;
F_73 ( V_190 ) ;
V_28 = F_74 ( V_8 -> V_191 , V_8 -> V_192 ) ;
if ( V_28 < 0 )
F_71 ( V_8 -> V_41 , L_23 , V_28 ) ;
}
static int F_75 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
int V_28 ;
F_72 ( V_8 -> V_172 ) ;
F_72 ( V_8 -> V_188 ) ;
F_72 ( V_8 -> V_189 ) ;
F_73 ( V_190 ) ;
V_28 = F_76 ( V_8 -> V_191 , V_8 -> V_192 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_24 , V_28 ) ;
V_28 = F_77 ( V_190 ,
V_8 -> V_193 ,
V_8 -> V_189 ) ;
if ( V_28 ) {
F_19 ( V_8 -> V_41 , L_25 , V_28 ) ;
return V_28 ;
}
F_68 ( V_8 -> V_188 ) ;
V_28 = F_78 ( V_8 -> V_194 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_26 , V_28 ) ;
return V_28 ;
}
if ( V_65 -> V_195 ) {
V_28 = F_78 ( V_8 -> V_196 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_27 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_78 ( V_8 -> V_197 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_28 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_79 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
V_8 -> V_193 = F_80 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_193 ) )
return F_81 ( V_8 -> V_193 ) ;
V_8 -> V_194 = F_80 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_194 ) )
return F_81 ( V_8 -> V_194 ) ;
V_8 -> V_197 = F_80 ( V_8 -> V_41 , L_31 ) ;
if ( F_24 ( V_8 -> V_197 ) )
return F_81 ( V_8 -> V_197 ) ;
if ( V_65 -> V_195 ) {
V_8 -> V_196 = F_80 ( V_8 -> V_41 , L_32 ) ;
if ( F_24 ( V_8 -> V_196 ) )
return F_81 ( V_8 -> V_196 ) ;
}
return 0 ;
}
static int F_82 ( struct V_4 * V_8 )
{
V_8 -> V_189 = F_83 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_189 ) )
return F_81 ( V_8 -> V_189 ) ;
V_8 -> V_188 = F_83 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_188 ) )
return F_81 ( V_8 -> V_188 ) ;
V_8 -> V_172 = F_83 ( V_8 -> V_41 , L_33 ) ;
if ( F_24 ( V_8 -> V_172 ) )
return F_81 ( V_8 -> V_172 ) ;
return 0 ;
}
static int F_84 ( struct V_4 * V_8 )
{
struct V_198 * V_92 = F_85 ( V_8 -> V_41 ) ;
struct V_199 * V_12 , * V_11 , * V_200 ;
int V_28 ;
V_28 = F_79 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_34 , V_28 ) ;
return V_28 ;
}
V_28 = F_82 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_35 , V_28 ) ;
return V_28 ;
}
V_8 -> V_159 = F_86 ( V_8 -> V_41 , L_36 ) ;
if ( F_24 ( V_8 -> V_159 ) ) {
V_28 = F_81 ( V_8 -> V_159 ) ;
F_19 ( & V_92 -> V_41 , L_37 , V_28 ) ;
return V_28 ;
}
V_28 = F_87 ( V_8 -> V_159 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_38 , V_28 ) ;
return V_28 ;
}
V_28 = F_75 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_39 , V_28 ) ;
return V_28 ;
}
V_12 = F_88 ( V_92 , V_201 , L_40 ) ;
V_8 -> V_12 = F_89 ( & V_92 -> V_41 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_81 ( V_8 -> V_12 ) ;
goto V_202;
}
V_11 = F_88 ( V_92 , V_201 , L_30 ) ;
V_8 -> V_11 = F_89 ( & V_92 -> V_41 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_81 ( V_8 -> V_11 ) ;
goto V_202;
}
V_200 = F_88 ( V_92 , V_201 , L_41 ) ;
if ( ! V_200 ) {
V_28 = - V_203 ;
goto V_202;
}
V_8 -> V_24 = F_90 ( V_8 -> V_41 , V_200 -> V_25 ,
F_37 ( V_200 ) , V_200 -> V_204 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_203 ;
goto V_202;
}
V_28 = F_91 ( V_92 , L_42 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_43 , V_28 ) ;
goto V_202;
}
V_8 -> V_94 = V_28 ;
V_28 = F_92 ( V_8 -> V_94 , F_57 , V_205 , L_44 , V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_45 , V_28 ) ;
goto V_202;
}
return 0 ;
V_202:
F_69 ( V_8 ) ;
return V_28 ;
}
static int F_93 ( struct V_4 * V_8 )
{
int V_28 ;
if ( V_8 -> V_94 > 0 )
F_94 ( V_8 -> V_94 , V_8 ) ;
F_69 ( V_8 ) ;
V_28 = F_95 ( V_8 -> V_159 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_46 , V_28 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_3 )
{
int V_206 ;
F_97 ( & V_3 -> V_207 ) ;
V_206 = F_98 ( V_3 -> V_208 , V_209 ) ;
if ( V_206 < V_209 )
F_99 ( V_206 , V_3 -> V_208 ) ;
else
V_206 = - V_210 ;
F_100 ( & V_3 -> V_207 ) ;
return V_206 ;
}
static void F_101 ( struct V_1 * V_3 , unsigned long V_94 )
{
struct V_211 * V_41 = V_3 -> V_3 . V_41 ;
F_97 ( & V_3 -> V_207 ) ;
if ( ! F_102 ( V_94 , V_3 -> V_208 ) )
F_19 ( V_41 , L_47 , V_94 ) ;
else
F_103 ( V_94 , V_3 -> V_208 ) ;
F_100 ( & V_3 -> V_207 ) ;
}
static T_7 F_104 ( int V_94 , void * V_212 )
{
struct V_4 * V_8 = V_212 ;
struct V_1 * V_206 = & V_8 -> V_206 ;
unsigned int V_27 , V_213 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_73 = F_6 ( V_8 , V_214 + V_27 * 4 ) ;
while ( V_73 ) {
unsigned int V_10 = F_105 ( & V_73 , 32 ) ;
unsigned int V_50 = V_27 * 32 + V_10 ;
unsigned int V_94 ;
F_4 ( V_8 , 1 << V_10 , V_214 + V_27 * 4 ) ;
V_94 = F_106 ( V_206 -> V_215 , V_50 ) ;
if ( V_94 ) {
if ( F_102 ( V_50 , V_206 -> V_208 ) )
F_107 ( V_94 ) ;
else
F_108 ( V_8 -> V_41 , L_48 ) ;
} else {
F_108 ( V_8 -> V_41 , L_49 ) ;
}
V_73 = F_6 ( V_8 , V_214 + V_27 * 4 ) ;
V_213 ++ ;
}
}
return V_213 > 0 ? V_111 : V_104 ;
}
static int F_109 ( struct V_2 * V_3 ,
struct V_72 * V_92 , struct V_216 * V_217 )
{
struct V_1 * V_206 = F_1 ( V_3 ) ;
struct V_218 V_219 ;
unsigned int V_94 ;
int V_220 ;
V_220 = F_96 ( V_206 ) ;
if ( V_220 < 0 )
return V_220 ;
V_94 = F_110 ( V_206 -> V_215 , V_220 ) ;
if ( ! V_94 ) {
F_101 ( V_206 , V_220 ) ;
return - V_221 ;
}
F_111 ( V_94 , V_217 ) ;
V_219 . V_222 = F_112 ( ( void * ) V_206 -> V_223 ) ;
V_219 . V_224 = 0 ;
V_219 . V_212 = V_220 ;
F_113 ( V_94 , & V_219 ) ;
return 0 ;
}
static void F_114 ( struct V_2 * V_3 ,
unsigned int V_94 )
{
struct V_1 * V_206 = F_1 ( V_3 ) ;
struct V_225 * V_226 = F_115 ( V_94 ) ;
T_9 V_220 = F_116 ( V_226 ) ;
F_117 ( V_94 ) ;
F_101 ( V_206 , V_220 ) ;
}
static int F_118 ( struct V_227 * V_215 , unsigned int V_94 ,
T_9 V_220 )
{
F_119 ( V_94 , & V_228 , V_229 ) ;
F_120 ( V_94 , V_215 -> V_230 ) ;
F_121 ( V_94 , V_231 ) ;
F_52 () ;
return 0 ;
}
static int F_122 ( struct V_4 * V_8 )
{
struct V_198 * V_92 = F_85 ( V_8 -> V_41 ) ;
const struct V_64 * V_65 = V_8 -> V_66 ;
struct V_1 * V_206 = & V_8 -> V_206 ;
unsigned long V_51 ;
int V_28 ;
T_1 V_73 ;
F_123 ( & V_206 -> V_207 ) ;
V_206 -> V_3 . V_41 = V_8 -> V_41 ;
V_206 -> V_3 . V_232 = F_109 ;
V_206 -> V_3 . V_233 = F_114 ;
V_206 -> V_215 = F_124 ( V_8 -> V_41 -> V_234 , V_209 ,
& V_235 , & V_206 -> V_3 ) ;
if ( ! V_206 -> V_215 ) {
F_19 ( & V_92 -> V_41 , L_50 ) ;
return - V_30 ;
}
V_28 = F_91 ( V_92 , L_51 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_43 , V_28 ) ;
goto V_28;
}
V_206 -> V_94 = V_28 ;
V_28 = F_92 ( V_206 -> V_94 , F_104 , 0 ,
V_228 . V_204 , V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_52 , V_28 ) ;
goto V_28;
}
V_206 -> V_223 = F_125 ( V_29 , 0 ) ;
V_51 = F_112 ( ( void * ) V_206 -> V_223 ) ;
F_4 ( V_8 , V_51 >> V_65 -> V_236 , V_137 ) ;
F_4 ( V_8 , V_51 , V_139 ) ;
F_4 ( V_8 , 1 , V_138 ) ;
F_4 ( V_8 , 0xffffffff , V_237 ) ;
F_4 ( V_8 , 0xffffffff , V_238 ) ;
F_4 ( V_8 , 0xffffffff , V_239 ) ;
F_4 ( V_8 , 0xffffffff , V_240 ) ;
F_4 ( V_8 , 0xffffffff , V_241 ) ;
F_4 ( V_8 , 0xffffffff , V_242 ) ;
F_4 ( V_8 , 0xffffffff , V_243 ) ;
F_4 ( V_8 , 0xffffffff , V_244 ) ;
V_73 = F_6 ( V_8 , V_186 ) ;
V_73 |= V_245 ;
F_4 ( V_8 , V_73 , V_186 ) ;
return 0 ;
V_28:
F_126 ( V_206 -> V_215 ) ;
return V_28 ;
}
static int F_127 ( struct V_4 * V_8 )
{
struct V_1 * V_206 = & V_8 -> V_206 ;
unsigned int V_27 , V_94 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_186 ) ;
V_9 &= ~ V_245 ;
F_4 ( V_8 , V_9 , V_186 ) ;
F_4 ( V_8 , 0 , V_237 ) ;
F_4 ( V_8 , 0 , V_238 ) ;
F_4 ( V_8 , 0 , V_239 ) ;
F_4 ( V_8 , 0 , V_240 ) ;
F_4 ( V_8 , 0 , V_241 ) ;
F_4 ( V_8 , 0 , V_242 ) ;
F_4 ( V_8 , 0 , V_243 ) ;
F_4 ( V_8 , 0 , V_244 ) ;
F_128 ( V_206 -> V_223 , 0 ) ;
if ( V_206 -> V_94 > 0 )
F_94 ( V_206 -> V_94 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_209 ; V_27 ++ ) {
V_94 = F_106 ( V_206 -> V_215 , V_27 ) ;
if ( V_94 > 0 )
F_117 ( V_94 ) ;
}
F_126 ( V_206 -> V_215 ) ;
return 0 ;
}
static int F_129 ( struct V_4 * V_8 , T_1 V_246 ,
T_1 * V_247 )
{
struct V_248 * V_249 = V_8 -> V_41 -> V_234 ;
if ( F_130 ( V_249 , L_53 ) ) {
switch ( V_246 ) {
case 0x0000104 :
F_108 ( V_8 -> V_41 , L_54 ) ;
* V_247 = V_250 ;
return 0 ;
case 0x0000102 :
F_108 ( V_8 -> V_41 , L_55 ) ;
* V_247 = V_251 ;
return 0 ;
}
} else if ( F_130 ( V_249 , L_56 ) ) {
switch ( V_246 ) {
case 0x00000204 :
F_108 ( V_8 -> V_41 , L_57 ) ;
* V_247 = V_252 ;
return 0 ;
case 0x00020202 :
F_108 ( V_8 -> V_41 , L_58 ) ;
* V_247 = V_253 ;
return 0 ;
case 0x00010104 :
F_108 ( V_8 -> V_41 , L_59 ) ;
* V_247 = V_254 ;
return 0 ;
}
} else if ( F_130 ( V_249 , L_60 ) ) {
switch ( V_246 ) {
case 0x00000004 :
F_108 ( V_8 -> V_41 , L_61 ) ;
* V_247 = V_255 ;
return 0 ;
case 0x00000202 :
F_108 ( V_8 -> V_41 , L_62 ) ;
* V_247 = V_256 ;
return 0 ;
}
}
return - V_221 ;
}
static bool F_131 ( struct V_248 * V_249 ,
struct V_257 * V_192 ,
unsigned int V_191 )
{
char V_258 [ 32 ] ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_191 ; V_27 ++ ) {
snprintf ( V_258 , 32 , L_63 , V_192 [ V_27 ] . V_259 ) ;
if ( F_132 ( V_249 , V_258 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_133 ( struct V_4 * V_8 )
{
struct V_248 * V_249 = V_8 -> V_41 -> V_234 ;
if ( F_130 ( V_249 , L_56 ) )
V_8 -> V_191 = 3 ;
else if ( F_130 ( V_249 , L_60 ) )
V_8 -> V_191 = 2 ;
if ( V_8 -> V_191 == 0 ) {
F_19 ( V_8 -> V_41 , L_64 ,
V_249 -> V_260 ) ;
return - V_261 ;
}
V_8 -> V_192 = F_134 ( V_8 -> V_41 , V_8 -> V_191 ,
sizeof( * V_8 -> V_192 ) ,
V_29 ) ;
if ( ! V_8 -> V_192 )
return - V_30 ;
V_8 -> V_192 [ 0 ] . V_259 = L_65 ;
V_8 -> V_192 [ 1 ] . V_259 = L_66 ;
if ( V_8 -> V_191 > 2 )
V_8 -> V_192 [ 2 ] . V_259 = L_67 ;
return F_135 ( V_8 -> V_41 , V_8 -> V_191 ,
V_8 -> V_192 ) ;
}
static int F_136 ( struct V_4 * V_8 , T_1 V_262 )
{
struct V_248 * V_249 = V_8 -> V_41 -> V_234 ;
unsigned int V_27 = 0 ;
if ( F_130 ( V_249 , L_53 ) ) {
V_8 -> V_191 = 7 ;
V_8 -> V_192 = F_134 ( V_8 -> V_41 , V_8 -> V_191 ,
sizeof( * V_8 -> V_192 ) ,
V_29 ) ;
if ( ! V_8 -> V_192 )
return - V_30 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_68 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_69 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_70 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_71 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_72 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_73 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_74 ;
} else if ( F_130 ( V_249 , L_56 ) ) {
bool V_263 = false , V_264 = false ;
if ( V_262 & 0x0f )
V_263 = true ;
if ( V_262 & 0x30 )
V_264 = true ;
V_8 -> V_191 = 4 + ( V_263 ? 2 : 0 ) +
( V_264 ? 2 : 0 ) ;
V_8 -> V_192 = F_134 ( V_8 -> V_41 , V_8 -> V_191 ,
sizeof( * V_8 -> V_192 ) ,
V_29 ) ;
if ( ! V_8 -> V_192 )
return - V_30 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_70 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_71 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_73 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_75 ;
if ( V_263 ) {
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_76 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_77 ;
}
if ( V_264 ) {
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_78 ;
V_8 -> V_192 [ V_27 ++ ] . V_259 = L_79 ;
}
} else if ( F_130 ( V_249 , L_60 ) ) {
V_8 -> V_191 = 5 ;
V_8 -> V_192 = F_134 ( V_8 -> V_41 , V_8 -> V_191 ,
sizeof( * V_8 -> V_192 ) ,
V_29 ) ;
if ( ! V_8 -> V_192 )
return - V_30 ;
V_8 -> V_192 [ 0 ] . V_259 = L_80 ;
V_8 -> V_192 [ 1 ] . V_259 = L_81 ;
V_8 -> V_192 [ 2 ] . V_259 = L_70 ;
V_8 -> V_192 [ 3 ] . V_259 = L_75 ;
V_8 -> V_192 [ 4 ] . V_259 = L_82 ;
}
if ( F_131 ( V_8 -> V_41 -> V_234 , V_8 -> V_192 ,
V_8 -> V_191 ) )
return F_135 ( V_8 -> V_41 , V_8 -> V_191 ,
V_8 -> V_192 ) ;
F_108 ( V_8 -> V_41 , L_83 ) ;
F_39 ( V_8 -> V_41 , V_8 -> V_192 ) ;
V_8 -> V_191 = 0 ;
return F_133 ( V_8 ) ;
}
static int F_137 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
struct V_248 * V_249 = V_8 -> V_41 -> V_234 , * V_49 ;
struct V_265 V_266 ;
struct V_267 V_268 ;
T_1 V_246 = 0 , V_55 = 0 ;
unsigned int V_269 = 0 ;
struct V_199 V_200 ;
int V_28 ;
memset ( & V_8 -> V_84 , 0 , sizeof( V_8 -> V_84 ) ) ;
V_8 -> V_84 . V_270 = V_201 ;
V_8 -> V_84 . V_204 = V_249 -> V_260 ;
V_8 -> V_84 . V_25 = ~ 0 ;
V_8 -> V_84 . V_271 = 0 ;
if ( F_138 ( & V_266 , V_249 ) ) {
F_19 ( V_8 -> V_41 , L_84 ) ;
return - V_221 ;
}
F_139 (&parser, &range) {
V_28 = F_140 ( & V_268 , V_249 , & V_200 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_200 . V_270 & V_272 ) {
case V_273 :
memcpy ( & V_8 -> V_90 , & V_200 , sizeof( V_200 ) ) ;
V_8 -> V_90 . V_204 = V_249 -> V_260 ;
V_8 -> V_91 . V_25 = V_268 . V_274 ;
V_8 -> V_91 . V_271 = V_268 . V_274 + V_268 . V_52 - 1 ;
V_8 -> V_91 . V_270 = V_201 ;
V_8 -> V_91 . V_204 = L_85 ;
memcpy ( & V_200 , & V_8 -> V_91 , sizeof( V_200 ) ) ;
break;
case V_201 :
if ( V_200 . V_270 & V_275 ) {
memcpy ( & V_8 -> V_86 , & V_200 , sizeof( V_200 ) ) ;
V_8 -> V_86 . V_204 = L_86 ;
} else {
memcpy ( & V_8 -> V_85 , & V_200 , sizeof( V_200 ) ) ;
V_8 -> V_85 . V_204 = L_87 ;
}
break;
}
if ( V_200 . V_25 <= V_8 -> V_84 . V_25 )
V_8 -> V_84 . V_25 = V_200 . V_25 ;
if ( V_200 . V_271 >= V_8 -> V_84 . V_271 )
V_8 -> V_84 . V_271 = V_200 . V_271 ;
}
V_28 = F_47 ( V_8 -> V_41 , & V_276 , & V_8 -> V_84 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_141 ( V_249 , & V_8 -> V_89 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_88 ,
V_28 ) ;
V_8 -> V_89 . V_204 = V_249 -> V_204 ;
V_8 -> V_89 . V_25 = 0 ;
V_8 -> V_89 . V_271 = 0xff ;
V_8 -> V_89 . V_270 = V_277 ;
}
F_142 (np, port) {
struct V_48 * V_278 ;
unsigned int V_50 ;
T_1 V_9 ;
V_28 = F_143 ( V_49 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
V_50 = F_11 ( V_28 ) ;
if ( V_50 < 1 || V_50 > V_65 -> V_155 ) {
F_19 ( V_8 -> V_41 , L_90 , V_50 ) ;
return - V_221 ;
}
V_50 -- ;
V_28 = F_144 ( V_49 , L_91 , & V_9 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_92 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_19 ( V_8 -> V_41 , L_93 , V_9 ) ;
return - V_221 ;
}
V_246 |= V_9 << ( V_50 << 3 ) ;
if ( ! F_145 ( V_49 ) ) {
V_269 += V_9 ;
continue;
}
V_55 |= ( ( 1 << V_9 ) - 1 ) << V_269 ;
V_269 += V_9 ;
V_278 = F_146 ( V_8 -> V_41 , sizeof( * V_278 ) , V_29 ) ;
if ( ! V_278 )
return - V_30 ;
V_28 = F_147 ( V_49 , 0 , & V_278 -> V_71 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
F_16 ( & V_278 -> V_31 ) ;
V_278 -> V_50 = V_50 ;
V_278 -> V_246 = V_9 ;
V_278 -> V_8 = V_8 ;
V_278 -> V_51 = F_89 ( V_8 -> V_41 , & V_278 -> V_71 ) ;
if ( F_24 ( V_278 -> V_51 ) )
return F_81 ( V_278 -> V_51 ) ;
F_25 ( & V_278 -> V_31 , & V_8 -> V_279 ) ;
}
V_28 = F_129 ( V_8 , V_246 , & V_8 -> V_168 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_94 ) ;
return V_28 ;
}
V_28 = F_136 ( V_8 , V_55 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
static bool F_148 ( struct V_48 * V_49 )
{
unsigned int V_280 = 3 ;
unsigned long V_9 ;
V_9 = F_7 ( V_49 -> V_51 + V_281 ) ;
V_9 &= ~ V_282 ;
V_9 |= V_283 ;
F_5 ( V_9 , V_49 -> V_51 + V_281 ) ;
do {
unsigned int V_140 = V_284 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_285 ) ;
if ( V_9 & V_286 )
break;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_140 );
if ( ! V_140 ) {
F_19 ( V_49 -> V_8 -> V_41 , L_95 ,
V_49 -> V_50 ) ;
goto V_287;
}
V_140 = V_284 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_288 ) ;
if ( V_9 & V_289 )
return true ;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_140 );
V_287:
F_30 ( V_49 ) ;
} while ( -- V_280 );
return false ;
}
static int F_149 ( struct V_4 * V_8 )
{
struct V_48 * V_49 , * V_56 ;
struct V_290 V_291 ;
F_150 (port, tmp, &pcie->ports, list) {
F_108 ( V_8 -> V_41 , L_96 ,
V_49 -> V_50 , V_49 -> V_246 ) ;
F_32 ( V_49 ) ;
if ( F_148 ( V_49 ) )
continue;
F_108 ( V_8 -> V_41 , L_97 , V_49 -> V_50 ) ;
F_33 ( V_49 ) ;
F_34 ( V_49 ) ;
}
memset ( & V_291 , 0 , sizeof( V_291 ) ) ;
#ifdef F_151
V_291 . V_292 = & V_8 -> V_206 . V_3 ;
#endif
V_291 . V_293 = 1 ;
V_291 . V_7 = ( void * * ) & V_8 ;
V_291 . V_294 = F_46 ;
V_291 . V_295 = F_51 ;
V_291 . V_296 = F_54 ;
V_291 . V_297 = & V_95 ;
F_152 ( V_8 -> V_41 , & V_291 ) ;
return 0 ;
}
static void * F_153 ( struct V_298 * V_299 , T_10 * V_300 )
{
struct V_4 * V_8 = V_299 -> V_301 ;
if ( F_154 ( & V_8 -> V_279 ) )
return NULL ;
F_155 ( V_299 , L_98 ) ;
return F_156 ( & V_8 -> V_279 , * V_300 ) ;
}
static void * F_157 ( struct V_298 * V_299 , void * V_302 , T_10 * V_300 )
{
struct V_4 * V_8 = V_299 -> V_301 ;
return F_158 ( V_302 , & V_8 -> V_279 , V_300 ) ;
}
static void F_159 ( struct V_298 * V_299 , void * V_302 )
{
}
static int F_160 ( struct V_298 * V_299 , void * V_302 )
{
bool V_303 = false , V_304 = false ;
struct V_48 * V_49 ;
unsigned int V_9 ;
V_49 = F_161 ( V_302 , struct V_48 , V_31 ) ;
V_9 = F_7 ( V_49 -> V_51 + V_285 ) ;
if ( V_9 & V_286 )
V_303 = true ;
V_9 = F_7 ( V_49 -> V_51 + V_288 ) ;
if ( V_9 & V_289 )
V_304 = true ;
F_155 ( V_299 , L_99 , V_49 -> V_50 ) ;
if ( V_303 )
F_155 ( V_299 , L_100 ) ;
if ( V_304 ) {
if ( V_303 )
F_155 ( V_299 , L_101 ) ;
F_155 ( V_299 , L_102 ) ;
}
F_155 ( V_299 , L_103 ) ;
return 0 ;
}
static int F_162 ( struct V_305 * V_305 , struct V_306 * V_306 )
{
struct V_4 * V_8 = V_305 -> V_307 ;
struct V_298 * V_299 ;
int V_28 ;
V_28 = F_163 ( V_306 , & V_308 ) ;
if ( V_28 )
return V_28 ;
V_299 = V_306 -> V_7 ;
V_299 -> V_301 = V_8 ;
return 0 ;
}
static int F_164 ( struct V_4 * V_8 )
{
struct V_309 * V_306 ;
V_8 -> V_310 = F_165 ( L_36 , NULL ) ;
if ( ! V_8 -> V_310 )
return - V_30 ;
V_306 = F_166 ( L_104 , V_311 | V_312 , V_8 -> V_310 ,
V_8 , & V_313 ) ;
if ( ! V_306 )
goto remove;
return 0 ;
remove:
F_167 ( V_8 -> V_310 ) ;
V_8 -> V_310 = NULL ;
return - V_30 ;
}
static int F_168 ( struct V_198 * V_92 )
{
const struct V_314 * V_315 ;
struct V_4 * V_8 ;
int V_28 ;
V_315 = F_169 ( V_316 , & V_92 -> V_41 ) ;
if ( ! V_315 )
return - V_261 ;
V_8 = F_146 ( & V_92 -> V_41 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_16 ( & V_8 -> V_43 ) ;
F_16 ( & V_8 -> V_279 ) ;
V_8 -> V_66 = V_315 -> V_212 ;
V_8 -> V_41 = & V_92 -> V_41 ;
V_28 = F_137 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_317 = 0 ;
V_28 = F_84 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_105 , V_28 ) ;
return V_28 ;
}
V_28 = F_65 ( V_8 ) ;
if ( V_28 )
goto V_318;
F_60 ( V_8 ) ;
if ( F_170 ( F_151 ) ) {
V_28 = F_122 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 ,
L_106 ,
V_28 ) ;
goto V_318;
}
}
V_28 = F_149 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_107 , V_28 ) ;
goto V_319;
}
if ( F_170 ( V_320 ) ) {
V_28 = F_164 ( V_8 ) ;
if ( V_28 < 0 )
F_19 ( & V_92 -> V_41 , L_108 ,
V_28 ) ;
}
F_171 ( V_92 , V_8 ) ;
return 0 ;
V_319:
if ( F_170 ( F_151 ) )
F_127 ( V_8 ) ;
V_318:
F_93 ( V_8 ) ;
return V_28 ;
}
