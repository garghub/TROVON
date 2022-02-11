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
T_3 V_39 = V_24 + V_27 * V_34 + V_16 * V_38 ;
V_28 = F_18 ( V_36 , V_36 + V_38 , V_39 , V_17 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_1 ,
V_28 ) ;
goto V_41;
}
}
return V_26 ;
V_41:
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
F_25 ( & V_26 -> V_31 , & V_8 -> V_42 ) ;
return ( void T_4 * ) V_26 -> V_33 -> V_37 ;
}
static void T_4 * F_26 ( struct V_43 * V_26 ,
unsigned int V_13 ,
int V_14 )
{
struct V_4 * V_8 = F_3 ( V_26 -> V_44 ) ;
void T_4 * V_37 = NULL ;
if ( V_26 -> V_45 == 0 ) {
unsigned int V_46 = F_11 ( V_13 ) ;
struct V_47 * V_48 ;
F_23 (port, &pcie->ports, list) {
if ( V_48 -> V_49 + 1 == V_46 ) {
V_37 = V_48 -> V_50 + ( V_14 & ~ 3 ) ;
break;
}
}
} else {
V_37 = F_22 ( V_8 , V_26 -> V_45 ) ;
if ( ! V_37 ) {
F_19 ( V_8 -> V_40 ,
L_2 ,
V_26 -> V_45 ) ;
return NULL ;
}
V_37 += F_10 ( V_13 , V_14 ) ;
}
return V_37 ;
}
static int F_27 ( struct V_43 * V_26 , unsigned int V_13 ,
int V_14 , int V_51 , T_1 * V_9 )
{
void T_4 * V_37 ;
V_37 = F_26 ( V_26 , V_13 , V_14 ) ;
if ( ! V_37 ) {
* V_9 = 0xffffffff ;
return V_52 ;
}
* V_9 = F_7 ( V_37 ) ;
if ( V_51 == 1 )
* V_9 = ( * V_9 >> ( 8 * ( V_14 & 3 ) ) ) & 0xff ;
else if ( V_51 == 2 )
* V_9 = ( * V_9 >> ( 8 * ( V_14 & 3 ) ) ) & 0xffff ;
return V_53 ;
}
static int F_28 ( struct V_43 * V_26 , unsigned int V_13 ,
int V_14 , int V_51 , T_1 V_9 )
{
void T_4 * V_37 ;
T_1 V_54 , V_55 ;
V_37 = F_26 ( V_26 , V_13 , V_14 ) ;
if ( ! V_37 )
return V_52 ;
if ( V_51 == 4 ) {
F_5 ( V_9 , V_37 ) ;
return V_53 ;
}
if ( V_51 == 2 )
V_54 = ~ ( 0xffff << ( ( V_14 & 0x3 ) * 8 ) ) ;
else if ( V_51 == 1 )
V_54 = ~ ( 0xff << ( ( V_14 & 0x3 ) * 8 ) ) ;
else
return V_56 ;
V_55 = F_7 ( V_37 ) & V_54 ;
V_55 |= V_9 << ( ( V_14 & 0x3 ) * 8 ) ;
F_5 ( V_55 , V_37 ) ;
return V_53 ;
}
static unsigned long F_29 ( struct V_47 * V_48 )
{
unsigned long V_57 = 0 ;
switch ( V_48 -> V_49 ) {
case 0 :
V_57 = V_58 ;
break;
case 1 :
V_57 = V_59 ;
break;
case 2 :
V_57 = V_60 ;
break;
}
return V_57 ;
}
static void F_30 ( struct V_47 * V_48 )
{
unsigned long V_61 = F_29 ( V_48 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_48 -> V_8 , V_61 ) ;
V_9 &= ~ V_62 ;
F_4 ( V_48 -> V_8 , V_9 , V_61 ) ;
F_31 ( 1000 , 2000 ) ;
V_9 = F_6 ( V_48 -> V_8 , V_61 ) ;
V_9 |= V_62 ;
F_4 ( V_48 -> V_8 , V_9 , V_61 ) ;
}
static void F_32 ( struct V_47 * V_48 )
{
const struct V_63 * V_64 = V_48 -> V_8 -> V_65 ;
unsigned long V_61 = F_29 ( V_48 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_48 -> V_8 , V_61 ) ;
V_9 |= V_66 ;
if ( V_64 -> V_67 )
V_9 |= V_68 ;
F_4 ( V_48 -> V_8 , V_9 , V_61 ) ;
F_30 ( V_48 ) ;
}
static void F_33 ( struct V_47 * V_48 )
{
unsigned long V_61 = F_29 ( V_48 ) ;
unsigned long V_9 ;
V_9 = F_6 ( V_48 -> V_8 , V_61 ) ;
V_9 &= ~ V_62 ;
F_4 ( V_48 -> V_8 , V_9 , V_61 ) ;
V_9 = F_6 ( V_48 -> V_8 , V_61 ) ;
V_9 &= ~ V_66 ;
F_4 ( V_48 -> V_8 , V_9 , V_61 ) ;
}
static void F_34 ( struct V_47 * V_48 )
{
struct V_4 * V_8 = V_48 -> V_8 ;
F_35 ( V_8 -> V_40 , V_48 -> V_50 ) ;
F_36 ( V_8 -> V_40 , V_48 -> V_69 . V_25 ,
F_37 ( & V_48 -> V_69 ) ) ;
F_38 ( & V_48 -> V_31 ) ;
F_39 ( V_8 -> V_40 , V_48 ) ;
}
static void F_40 ( struct V_70 * V_40 )
{
T_5 V_71 ;
if ( ( V_40 -> V_72 >> 16 ) == V_73 ) {
F_41 ( V_40 , V_74 , & V_71 ) ;
V_71 |= ( V_75 | V_76 |
V_77 | V_78 ) ;
F_42 ( V_40 , V_74 , V_71 ) ;
}
}
static void F_43 ( struct V_70 * V_40 )
{
V_40 -> V_72 = V_79 << 8 ;
}
static void F_44 ( struct V_70 * V_40 )
{
F_45 ( V_40 , V_80 , V_81 ) ;
}
static int F_46 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
F_47 ( & V_6 -> V_82 , & V_8 -> V_83 , V_6 -> V_84 ) ;
F_47 ( & V_6 -> V_82 , & V_8 -> V_85 ,
V_6 -> V_84 ) ;
F_48 ( & V_6 -> V_82 , & V_8 -> V_86 ) ;
F_49 ( V_32 * V_38 , V_8 -> V_87 . V_25 ) ;
return 1 ;
}
static int F_50 ( const struct V_70 * V_88 , T_6 V_46 , T_6 V_89 )
{
struct V_4 * V_8 = F_3 ( V_88 -> V_26 -> V_44 ) ;
int V_90 ;
F_51 () ;
V_90 = F_52 ( V_88 , V_46 , V_89 ) ;
if ( ! V_90 )
V_90 = V_8 -> V_90 ;
return V_90 ;
}
static void F_53 ( struct V_43 * V_26 )
{
if ( F_54 ( V_91 ) ) {
struct V_4 * V_8 = F_3 ( V_26 -> V_44 ) ;
V_26 -> V_92 = & V_8 -> V_92 . V_3 ;
}
}
static struct V_43 * F_55 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
struct V_43 * V_26 ;
V_26 = F_56 ( V_8 -> V_40 , V_6 -> V_16 , & V_93 , V_6 ,
& V_6 -> V_82 ) ;
if ( ! V_26 )
return NULL ;
F_57 ( V_26 ) ;
return V_26 ;
}
static T_7 F_58 ( int V_90 , void * V_94 )
{
const char * V_95 [] = {
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
} ;
struct V_4 * V_8 = V_94 ;
T_1 V_96 , V_97 ;
V_96 = F_6 ( V_8 , V_98 ) & V_99 ;
V_97 = F_6 ( V_8 , V_100 ) ;
F_4 ( V_8 , 0 , V_98 ) ;
if ( V_96 == V_101 )
return V_102 ;
if ( V_96 >= F_59 ( V_95 ) )
V_96 = 0 ;
if ( V_96 == V_103 )
F_60 ( V_8 -> V_40 , L_12 , V_95 [ V_96 ] ,
V_97 ) ;
else
F_19 ( V_8 -> V_40 , L_12 , V_95 [ V_96 ] ,
V_97 ) ;
if ( V_96 == V_104 || V_96 == V_103 ||
V_96 == V_105 ) {
T_1 V_106 = F_6 ( V_8 , V_107 ) & 0xff ;
T_8 V_108 = ( T_8 ) V_106 << 32 | ( V_97 & 0xfffffffc ) ;
if ( V_96 == V_103 )
F_60 ( V_8 -> V_40 , L_13 , V_108 ) ;
else
F_19 ( V_8 -> V_40 , L_13 , V_108 ) ;
}
return V_109 ;
}
static void F_61 ( struct V_4 * V_8 )
{
T_1 V_110 , V_51 , V_111 ;
V_110 = 0xfe100000 ;
V_51 = F_37 ( V_8 -> V_24 ) ;
V_111 = V_8 -> V_24 -> V_25 ;
F_4 ( V_8 , V_111 , V_112 ) ;
F_4 ( V_8 , V_51 >> 12 , V_113 ) ;
F_4 ( V_8 , V_110 , V_114 ) ;
V_110 = 0xfdfc0000 ;
V_51 = F_37 ( & V_8 -> V_87 ) ;
V_111 = V_8 -> V_87 . V_25 ;
F_4 ( V_8 , V_111 , V_115 ) ;
F_4 ( V_8 , V_51 >> 12 , V_116 ) ;
F_4 ( V_8 , V_110 , V_117 ) ;
V_110 = ( ( ( V_8 -> V_85 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_51 = F_37 ( & V_8 -> V_85 ) ;
V_111 = V_8 -> V_85 . V_25 ;
F_4 ( V_8 , V_111 , V_118 ) ;
F_4 ( V_8 , V_51 >> 12 , V_119 ) ;
F_4 ( V_8 , V_110 , V_120 ) ;
V_110 = ( ( ( V_8 -> V_83 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_51 = F_37 ( & V_8 -> V_83 ) ;
V_111 = V_8 -> V_83 . V_25 ;
F_4 ( V_8 , V_111 , V_121 ) ;
F_4 ( V_8 , V_51 >> 12 , V_122 ) ;
F_4 ( V_8 , V_110 , V_123 ) ;
F_4 ( V_8 , 0 , V_124 ) ;
F_4 ( V_8 , 0 , V_125 ) ;
F_4 ( V_8 , 0 , V_126 ) ;
F_4 ( V_8 , 0 , V_127 ) ;
F_4 ( V_8 , 0 , V_128 ) ;
F_4 ( V_8 , 0 , V_129 ) ;
F_4 ( V_8 , V_130 , V_131 ) ;
F_4 ( V_8 , 0 , V_132 ) ;
F_4 ( V_8 , 0 , V_133 ) ;
F_4 ( V_8 , 0 , V_134 ) ;
F_4 ( V_8 , 0 , V_135 ) ;
F_4 ( V_8 , 0 , V_136 ) ;
F_4 ( V_8 , 0 , V_137 ) ;
F_4 ( V_8 , 0 , V_136 ) ;
}
static int F_62 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
struct V_47 * V_48 ;
unsigned int V_138 ;
unsigned long V_9 ;
if ( V_64 -> V_139 )
F_4 ( V_8 , 0 , V_140 ) ;
V_9 = F_6 ( V_8 , V_141 ) ;
V_9 &= ~ V_142 ;
V_9 |= V_143 | V_8 -> V_144 ;
F_23 (port, &pcie->ports, list)
V_9 &= ~ F_63 ( V_48 -> V_49 ) ;
F_4 ( V_8 , V_9 , V_141 ) ;
V_9 = F_6 ( V_8 , V_145 ) ;
V_9 |= V_146 ;
F_4 ( V_8 , V_9 , V_145 ) ;
F_8 ( V_8 , 0x0 , V_147 ) ;
V_9 = F_9 ( V_8 , V_148 ) ;
V_9 |= V_149 ;
F_8 ( V_8 , V_9 , V_148 ) ;
V_9 = F_9 ( V_8 , V_64 -> V_150 ) ;
V_9 &= ~ ( V_151 | V_152 ) ;
V_9 |= V_153 | V_64 -> V_154 ;
F_8 ( V_8 , V_9 , V_64 -> V_150 ) ;
V_9 = F_9 ( V_8 , V_64 -> V_150 ) ;
V_9 |= V_155 ;
F_8 ( V_8 , V_9 , V_64 -> V_150 ) ;
V_9 = V_156 | ( V_156 << 16 ) ;
F_8 ( V_8 , V_9 , V_157 ) ;
if ( V_64 -> V_158 > 2 )
F_8 ( V_8 , V_156 , V_159 ) ;
V_138 = 300 ;
do {
V_9 = F_9 ( V_8 , V_64 -> V_150 ) ;
F_31 ( 1000 , 2000 ) ;
if ( -- V_138 == 0 ) {
F_64 ( L_14 ) ;
return - V_160 ;
}
} while ( ! ( V_9 & V_161 ) );
V_9 = F_9 ( V_8 , V_148 ) ;
V_9 &= ~ V_149 ;
F_8 ( V_8 , V_9 , V_148 ) ;
V_9 = F_9 ( V_8 , V_148 ) ;
V_9 |= V_162 | V_163 ;
F_8 ( V_8 , V_9 , V_148 ) ;
F_65 ( V_8 -> V_164 ) ;
V_9 = F_6 ( V_8 , V_165 ) ;
V_9 |= V_166 ;
F_4 ( V_8 , V_9 , V_165 ) ;
V_9 = V_167 | V_168 |
V_169 | V_170 |
V_171 | V_172 ;
if ( V_64 -> V_173 )
V_9 |= V_174 ;
F_4 ( V_8 , V_9 , V_175 ) ;
F_4 ( V_8 , 0xffffffff , V_176 ) ;
F_4 ( V_8 , V_177 , V_178 ) ;
F_4 ( V_8 , 0 , V_179 ) ;
return 0 ;
}
static void F_66 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
int V_28 ;
F_67 ( V_8 -> V_164 ) ;
F_67 ( V_8 -> V_180 ) ;
F_67 ( V_8 -> V_181 ) ;
F_68 ( V_182 ) ;
if ( V_64 -> V_183 ) {
V_28 = F_69 ( V_8 -> V_184 ) ;
if ( V_28 < 0 )
F_70 ( V_8 -> V_40 ,
L_15 ,
V_28 ) ;
}
V_28 = F_69 ( V_8 -> V_185 ) ;
if ( V_28 < 0 )
F_70 ( V_8 -> V_40 , L_16 ,
V_28 ) ;
V_28 = F_69 ( V_8 -> V_186 ) ;
if ( V_28 < 0 )
F_70 ( V_8 -> V_40 , L_17 ,
V_28 ) ;
}
static int F_71 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
int V_28 ;
F_67 ( V_8 -> V_164 ) ;
F_67 ( V_8 -> V_180 ) ;
F_67 ( V_8 -> V_181 ) ;
F_68 ( V_182 ) ;
V_28 = F_72 ( V_8 -> V_186 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_18 , V_28 ) ;
return V_28 ;
}
V_28 = F_72 ( V_8 -> V_185 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_19 ,
V_28 ) ;
return V_28 ;
}
if ( V_64 -> V_183 ) {
V_28 = F_72 ( V_8 -> V_184 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 ,
L_20 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_73 ( V_182 ,
V_8 -> V_187 ,
V_8 -> V_181 ) ;
if ( V_28 ) {
F_19 ( V_8 -> V_40 , L_21 , V_28 ) ;
return V_28 ;
}
F_65 ( V_8 -> V_180 ) ;
V_28 = F_74 ( V_8 -> V_188 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_22 , V_28 ) ;
return V_28 ;
}
if ( V_64 -> V_189 ) {
V_28 = F_74 ( V_8 -> V_190 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_23 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_74 ( V_8 -> V_191 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_24 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_75 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
V_8 -> V_187 = F_76 ( V_8 -> V_40 , L_25 ) ;
if ( F_24 ( V_8 -> V_187 ) )
return F_77 ( V_8 -> V_187 ) ;
V_8 -> V_188 = F_76 ( V_8 -> V_40 , L_26 ) ;
if ( F_24 ( V_8 -> V_188 ) )
return F_77 ( V_8 -> V_188 ) ;
V_8 -> V_191 = F_76 ( V_8 -> V_40 , L_27 ) ;
if ( F_24 ( V_8 -> V_191 ) )
return F_77 ( V_8 -> V_191 ) ;
if ( V_64 -> V_189 ) {
V_8 -> V_190 = F_76 ( V_8 -> V_40 , L_28 ) ;
if ( F_24 ( V_8 -> V_190 ) )
return F_77 ( V_8 -> V_190 ) ;
}
return 0 ;
}
static int F_78 ( struct V_4 * V_8 )
{
V_8 -> V_181 = F_79 ( V_8 -> V_40 , L_25 ) ;
if ( F_24 ( V_8 -> V_181 ) )
return F_77 ( V_8 -> V_181 ) ;
V_8 -> V_180 = F_79 ( V_8 -> V_40 , L_26 ) ;
if ( F_24 ( V_8 -> V_180 ) )
return F_77 ( V_8 -> V_180 ) ;
V_8 -> V_164 = F_79 ( V_8 -> V_40 , L_29 ) ;
if ( F_24 ( V_8 -> V_164 ) )
return F_77 ( V_8 -> V_164 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_8 )
{
struct V_192 * V_88 = F_81 ( V_8 -> V_40 ) ;
struct V_193 * V_12 , * V_11 , * V_194 ;
int V_28 ;
V_28 = F_75 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_30 , V_28 ) ;
return V_28 ;
}
V_28 = F_78 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_31 , V_28 ) ;
return V_28 ;
}
V_28 = F_71 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_32 , V_28 ) ;
return V_28 ;
}
V_12 = F_82 ( V_88 , V_195 , L_33 ) ;
V_8 -> V_12 = F_83 ( & V_88 -> V_40 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_77 ( V_8 -> V_12 ) ;
goto V_196;
}
V_11 = F_82 ( V_88 , V_195 , L_26 ) ;
V_8 -> V_11 = F_83 ( & V_88 -> V_40 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_77 ( V_8 -> V_11 ) ;
goto V_196;
}
V_194 = F_82 ( V_88 , V_195 , L_34 ) ;
if ( ! V_194 ) {
V_28 = - V_197 ;
goto V_196;
}
V_8 -> V_24 = F_84 ( V_8 -> V_40 , V_194 -> V_25 ,
F_37 ( V_194 ) , V_194 -> V_198 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_197 ;
goto V_196;
}
V_28 = F_85 ( V_88 , L_35 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_36 , V_28 ) ;
goto V_196;
}
V_8 -> V_90 = V_28 ;
V_28 = F_86 ( V_8 -> V_90 , F_58 , V_199 , L_37 , V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_38 , V_28 ) ;
goto V_196;
}
return 0 ;
V_196:
F_66 ( V_8 ) ;
return V_28 ;
}
static int F_87 ( struct V_4 * V_8 )
{
if ( V_8 -> V_90 > 0 )
F_88 ( V_8 -> V_90 , V_8 ) ;
F_66 ( V_8 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_3 )
{
int V_92 ;
F_90 ( & V_3 -> V_200 ) ;
V_92 = F_91 ( V_3 -> V_201 , V_202 ) ;
if ( V_92 < V_202 )
F_92 ( V_92 , V_3 -> V_201 ) ;
else
V_92 = - V_203 ;
F_93 ( & V_3 -> V_200 ) ;
return V_92 ;
}
static void F_94 ( struct V_1 * V_3 , unsigned long V_90 )
{
struct V_204 * V_40 = V_3 -> V_3 . V_40 ;
F_90 ( & V_3 -> V_200 ) ;
if ( ! F_95 ( V_90 , V_3 -> V_201 ) )
F_19 ( V_40 , L_39 , V_90 ) ;
else
F_96 ( V_90 , V_3 -> V_201 ) ;
F_93 ( & V_3 -> V_200 ) ;
}
static T_7 F_97 ( int V_90 , void * V_205 )
{
struct V_4 * V_8 = V_205 ;
struct V_1 * V_92 = & V_8 -> V_92 ;
unsigned int V_27 , V_206 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_71 = F_6 ( V_8 , V_207 + V_27 * 4 ) ;
while ( V_71 ) {
unsigned int V_10 = F_98 ( & V_71 , 32 ) ;
unsigned int V_49 = V_27 * 32 + V_10 ;
unsigned int V_90 ;
F_4 ( V_8 , 1 << V_10 , V_207 + V_27 * 4 ) ;
V_90 = F_99 ( V_92 -> V_208 , V_49 ) ;
if ( V_90 ) {
if ( F_95 ( V_49 , V_92 -> V_201 ) )
F_100 ( V_90 ) ;
else
F_101 ( V_8 -> V_40 , L_40 ) ;
} else {
F_101 ( V_8 -> V_40 , L_41 ) ;
}
V_71 = F_6 ( V_8 , V_207 + V_27 * 4 ) ;
V_206 ++ ;
}
}
return V_206 > 0 ? V_109 : V_102 ;
}
static int F_102 ( struct V_2 * V_3 , struct V_70 * V_88 ,
struct V_209 * V_210 )
{
struct V_1 * V_92 = F_1 ( V_3 ) ;
struct V_211 V_212 ;
unsigned int V_90 ;
int V_213 ;
V_213 = F_89 ( V_92 ) ;
if ( V_213 < 0 )
return V_213 ;
V_90 = F_103 ( V_92 -> V_208 , V_213 ) ;
if ( ! V_90 )
return - V_214 ;
F_104 ( V_90 , V_210 ) ;
V_212 . V_215 = F_105 ( ( void * ) V_92 -> V_216 ) ;
V_212 . V_217 = 0 ;
V_212 . V_205 = V_213 ;
F_106 ( V_90 , & V_212 ) ;
return 0 ;
}
static void F_107 ( struct V_2 * V_3 , unsigned int V_90 )
{
struct V_1 * V_92 = F_1 ( V_3 ) ;
struct V_218 * V_219 = F_108 ( V_90 ) ;
F_94 ( V_92 , V_219 -> V_213 ) ;
}
static int F_109 ( struct V_220 * V_208 , unsigned int V_90 ,
T_9 V_213 )
{
F_110 ( V_90 , & V_221 , V_222 ) ;
F_111 ( V_90 , V_208 -> V_223 ) ;
F_112 ( V_90 , V_224 ) ;
F_51 () ;
return 0 ;
}
static int F_113 ( struct V_4 * V_8 )
{
struct V_192 * V_88 = F_81 ( V_8 -> V_40 ) ;
const struct V_63 * V_64 = V_8 -> V_65 ;
struct V_1 * V_92 = & V_8 -> V_92 ;
unsigned long V_50 ;
int V_28 ;
T_1 V_71 ;
F_114 ( & V_92 -> V_200 ) ;
V_92 -> V_3 . V_40 = V_8 -> V_40 ;
V_92 -> V_3 . V_225 = F_102 ;
V_92 -> V_3 . V_226 = F_107 ;
V_92 -> V_208 = F_115 ( V_8 -> V_40 -> V_227 , V_202 ,
& V_228 , & V_92 -> V_3 ) ;
if ( ! V_92 -> V_208 ) {
F_19 ( & V_88 -> V_40 , L_42 ) ;
return - V_30 ;
}
V_28 = F_85 ( V_88 , L_43 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_36 , V_28 ) ;
goto V_28;
}
V_92 -> V_90 = V_28 ;
V_28 = F_86 ( V_92 -> V_90 , F_97 , 0 ,
V_221 . V_198 , V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_44 , V_28 ) ;
goto V_28;
}
V_92 -> V_216 = F_116 ( V_29 , 0 ) ;
V_50 = F_105 ( ( void * ) V_92 -> V_216 ) ;
F_4 ( V_8 , V_50 >> V_64 -> V_229 , V_135 ) ;
F_4 ( V_8 , V_50 , V_137 ) ;
F_4 ( V_8 , 1 , V_136 ) ;
F_4 ( V_8 , 0xffffffff , V_230 ) ;
F_4 ( V_8 , 0xffffffff , V_231 ) ;
F_4 ( V_8 , 0xffffffff , V_232 ) ;
F_4 ( V_8 , 0xffffffff , V_233 ) ;
F_4 ( V_8 , 0xffffffff , V_234 ) ;
F_4 ( V_8 , 0xffffffff , V_235 ) ;
F_4 ( V_8 , 0xffffffff , V_236 ) ;
F_4 ( V_8 , 0xffffffff , V_237 ) ;
V_71 = F_6 ( V_8 , V_178 ) ;
V_71 |= V_238 ;
F_4 ( V_8 , V_71 , V_178 ) ;
return 0 ;
V_28:
F_117 ( V_92 -> V_208 ) ;
return V_28 ;
}
static int F_118 ( struct V_4 * V_8 )
{
struct V_1 * V_92 = & V_8 -> V_92 ;
unsigned int V_27 , V_90 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_178 ) ;
V_9 &= ~ V_238 ;
F_4 ( V_8 , V_9 , V_178 ) ;
F_4 ( V_8 , 0 , V_230 ) ;
F_4 ( V_8 , 0 , V_231 ) ;
F_4 ( V_8 , 0 , V_232 ) ;
F_4 ( V_8 , 0 , V_233 ) ;
F_4 ( V_8 , 0 , V_234 ) ;
F_4 ( V_8 , 0 , V_235 ) ;
F_4 ( V_8 , 0 , V_236 ) ;
F_4 ( V_8 , 0 , V_237 ) ;
F_119 ( V_92 -> V_216 , 0 ) ;
if ( V_92 -> V_90 > 0 )
F_88 ( V_92 -> V_90 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_202 ; V_27 ++ ) {
V_90 = F_99 ( V_92 -> V_208 , V_27 ) ;
if ( V_90 > 0 )
F_120 ( V_90 ) ;
}
F_117 ( V_92 -> V_208 ) ;
return 0 ;
}
static int F_121 ( struct V_4 * V_8 , T_1 V_239 ,
T_1 * V_240 )
{
struct V_241 * V_242 = V_8 -> V_40 -> V_227 ;
if ( F_122 ( V_242 , L_45 ) ) {
switch ( V_239 ) {
case 0x00000204 :
F_101 ( V_8 -> V_40 , L_46 ) ;
* V_240 = V_243 ;
return 0 ;
case 0x00020202 :
F_101 ( V_8 -> V_40 , L_47 ) ;
* V_240 = V_244 ;
return 0 ;
case 0x00010104 :
F_101 ( V_8 -> V_40 , L_48 ) ;
* V_240 = V_245 ;
return 0 ;
}
} else if ( F_122 ( V_242 , L_49 ) ) {
switch ( V_239 ) {
case 0x00000004 :
F_101 ( V_8 -> V_40 , L_50 ) ;
* V_240 = V_246 ;
return 0 ;
case 0x00000202 :
F_101 ( V_8 -> V_40 , L_51 ) ;
* V_240 = V_247 ;
return 0 ;
}
}
return - V_214 ;
}
static int F_123 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
struct V_241 * V_242 = V_8 -> V_40 -> V_227 , * V_48 ;
struct V_248 V_249 ;
struct V_250 V_251 ;
struct V_193 V_194 ;
T_1 V_239 = 0 ;
int V_28 ;
if ( F_124 ( & V_249 , V_242 ) ) {
F_19 ( V_8 -> V_40 , L_52 ) ;
return - V_214 ;
}
V_8 -> V_186 = F_125 ( V_8 -> V_40 , L_53 ) ;
if ( F_24 ( V_8 -> V_186 ) )
return F_77 ( V_8 -> V_186 ) ;
V_8 -> V_185 = F_125 ( V_8 -> V_40 , L_54 ) ;
if ( F_24 ( V_8 -> V_185 ) )
return F_77 ( V_8 -> V_185 ) ;
if ( V_64 -> V_183 ) {
V_8 -> V_184 = F_125 ( V_8 -> V_40 , L_55 ) ;
if ( F_24 ( V_8 -> V_184 ) )
return F_77 ( V_8 -> V_184 ) ;
}
F_126 (&parser, &range) {
F_127 ( & V_251 , V_242 , & V_194 ) ;
switch ( V_194 . V_252 & V_253 ) {
case V_254 :
memcpy ( & V_8 -> V_87 , & V_194 , sizeof( V_194 ) ) ;
V_8 -> V_87 . V_198 = L_56 ;
break;
case V_195 :
if ( V_194 . V_252 & V_255 ) {
memcpy ( & V_8 -> V_85 , & V_194 , sizeof( V_194 ) ) ;
V_8 -> V_85 . V_198 = L_57 ;
} else {
memcpy ( & V_8 -> V_83 , & V_194 , sizeof( V_194 ) ) ;
V_8 -> V_83 . V_198 = L_58 ;
}
break;
}
}
V_28 = F_128 ( V_242 , & V_8 -> V_86 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_59 ,
V_28 ) ;
V_8 -> V_86 . V_198 = V_242 -> V_198 ;
V_8 -> V_86 . V_25 = 0 ;
V_8 -> V_86 . V_256 = 0xff ;
V_8 -> V_86 . V_252 = V_257 ;
}
F_129 (np, port) {
struct V_47 * V_258 ;
unsigned int V_49 ;
T_1 V_9 ;
V_28 = F_130 ( V_48 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_60 ,
V_28 ) ;
return V_28 ;
}
V_49 = F_11 ( V_28 ) ;
if ( V_49 < 1 || V_49 > V_64 -> V_158 ) {
F_19 ( V_8 -> V_40 , L_61 , V_49 ) ;
return - V_214 ;
}
V_49 -- ;
V_28 = F_131 ( V_48 , L_62 , & V_9 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_63 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_19 ( V_8 -> V_40 , L_64 , V_9 ) ;
return - V_214 ;
}
V_239 |= V_9 << ( V_49 << 3 ) ;
if ( ! F_132 ( V_48 ) )
continue;
V_258 = F_133 ( V_8 -> V_40 , sizeof( * V_258 ) , V_29 ) ;
if ( ! V_258 )
return - V_30 ;
V_28 = F_134 ( V_48 , 0 , & V_258 -> V_69 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_60 ,
V_28 ) ;
return V_28 ;
}
F_16 ( & V_258 -> V_31 ) ;
V_258 -> V_49 = V_49 ;
V_258 -> V_239 = V_9 ;
V_258 -> V_8 = V_8 ;
V_258 -> V_50 = F_83 ( V_8 -> V_40 , & V_258 -> V_69 ) ;
if ( F_24 ( V_258 -> V_50 ) )
return F_77 ( V_258 -> V_50 ) ;
F_25 ( & V_258 -> V_31 , & V_8 -> V_259 ) ;
}
V_28 = F_121 ( V_8 , V_239 , & V_8 -> V_144 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_65 ) ;
return V_28 ;
}
return 0 ;
}
static bool F_135 ( struct V_47 * V_48 )
{
unsigned int V_260 = 3 ;
unsigned long V_9 ;
do {
unsigned int V_138 = V_261 ;
do {
V_9 = F_7 ( V_48 -> V_50 + V_262 ) ;
if ( V_9 & V_263 )
break;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_138 );
if ( ! V_138 ) {
F_19 ( V_48 -> V_8 -> V_40 , L_66 ,
V_48 -> V_49 ) ;
goto V_264;
}
V_138 = V_261 ;
do {
V_9 = F_7 ( V_48 -> V_50 + V_265 ) ;
if ( V_9 & V_266 )
return true ;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_138 );
V_264:
F_30 ( V_48 ) ;
} while ( -- V_260 );
return false ;
}
static int F_136 ( struct V_4 * V_8 )
{
struct V_47 * V_48 , * V_55 ;
struct V_267 V_268 ;
F_137 (port, tmp, &pcie->ports, list) {
F_101 ( V_8 -> V_40 , L_67 ,
V_48 -> V_49 , V_48 -> V_239 ) ;
F_32 ( V_48 ) ;
if ( F_135 ( V_48 ) )
continue;
F_101 ( V_8 -> V_40 , L_68 , V_48 -> V_49 ) ;
F_33 ( V_48 ) ;
F_34 ( V_48 ) ;
}
memset ( & V_268 , 0 , sizeof( V_268 ) ) ;
V_268 . V_269 = 1 ;
V_268 . V_7 = ( void * * ) & V_8 ;
V_268 . V_270 = F_46 ;
V_268 . V_271 = F_50 ;
V_268 . V_272 = F_53 ;
V_268 . V_273 = F_55 ;
V_268 . V_274 = & V_93 ;
F_138 ( V_8 -> V_40 , & V_268 ) ;
return 0 ;
}
static int F_139 ( struct V_192 * V_88 )
{
const struct V_275 * V_276 ;
struct V_4 * V_8 ;
int V_28 ;
V_276 = F_140 ( V_277 , & V_88 -> V_40 ) ;
if ( ! V_276 )
return - V_278 ;
V_8 = F_133 ( & V_88 -> V_40 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_16 ( & V_8 -> V_42 ) ;
F_16 ( & V_8 -> V_259 ) ;
V_8 -> V_65 = V_276 -> V_205 ;
V_8 -> V_40 = & V_88 -> V_40 ;
V_28 = F_123 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_279 = 0 ;
V_28 = F_80 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_69 , V_28 ) ;
return V_28 ;
}
V_28 = F_62 ( V_8 ) ;
if ( V_28 )
goto V_280;
F_61 ( V_8 ) ;
if ( F_54 ( V_91 ) ) {
V_28 = F_113 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 ,
L_70 ,
V_28 ) ;
goto V_280;
}
}
V_28 = F_136 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_71 , V_28 ) ;
goto V_281;
}
F_141 ( V_88 , V_8 ) ;
return 0 ;
V_281:
if ( F_54 ( V_91 ) )
F_118 ( V_8 ) ;
V_280:
F_87 ( V_8 ) ;
return V_28 ;
}
