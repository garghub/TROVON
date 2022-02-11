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
int V_28 ;
F_67 ( V_8 -> V_164 ) ;
F_67 ( V_8 -> V_180 ) ;
F_67 ( V_8 -> V_181 ) ;
F_68 ( V_182 ) ;
V_28 = F_69 ( V_8 -> V_183 , V_8 -> V_184 ) ;
if ( V_28 < 0 )
F_70 ( V_8 -> V_40 , L_15 , V_28 ) ;
}
static int F_71 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
int V_28 ;
F_67 ( V_8 -> V_164 ) ;
F_67 ( V_8 -> V_180 ) ;
F_67 ( V_8 -> V_181 ) ;
F_68 ( V_182 ) ;
V_28 = F_72 ( V_8 -> V_183 , V_8 -> V_184 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_40 , L_16 , V_28 ) ;
V_28 = F_73 ( V_182 ,
V_8 -> V_185 ,
V_8 -> V_181 ) ;
if ( V_28 ) {
F_19 ( V_8 -> V_40 , L_17 , V_28 ) ;
return V_28 ;
}
F_65 ( V_8 -> V_180 ) ;
V_28 = F_74 ( V_8 -> V_186 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_18 , V_28 ) ;
return V_28 ;
}
if ( V_64 -> V_187 ) {
V_28 = F_74 ( V_8 -> V_188 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_19 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_74 ( V_8 -> V_189 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_20 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_75 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
V_8 -> V_185 = F_76 ( V_8 -> V_40 , L_21 ) ;
if ( F_24 ( V_8 -> V_185 ) )
return F_77 ( V_8 -> V_185 ) ;
V_8 -> V_186 = F_76 ( V_8 -> V_40 , L_22 ) ;
if ( F_24 ( V_8 -> V_186 ) )
return F_77 ( V_8 -> V_186 ) ;
V_8 -> V_189 = F_76 ( V_8 -> V_40 , L_23 ) ;
if ( F_24 ( V_8 -> V_189 ) )
return F_77 ( V_8 -> V_189 ) ;
if ( V_64 -> V_187 ) {
V_8 -> V_188 = F_76 ( V_8 -> V_40 , L_24 ) ;
if ( F_24 ( V_8 -> V_188 ) )
return F_77 ( V_8 -> V_188 ) ;
}
return 0 ;
}
static int F_78 ( struct V_4 * V_8 )
{
V_8 -> V_181 = F_79 ( V_8 -> V_40 , L_21 ) ;
if ( F_24 ( V_8 -> V_181 ) )
return F_77 ( V_8 -> V_181 ) ;
V_8 -> V_180 = F_79 ( V_8 -> V_40 , L_22 ) ;
if ( F_24 ( V_8 -> V_180 ) )
return F_77 ( V_8 -> V_180 ) ;
V_8 -> V_164 = F_79 ( V_8 -> V_40 , L_25 ) ;
if ( F_24 ( V_8 -> V_164 ) )
return F_77 ( V_8 -> V_164 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_8 )
{
struct V_190 * V_88 = F_81 ( V_8 -> V_40 ) ;
struct V_191 * V_12 , * V_11 , * V_192 ;
int V_28 ;
V_28 = F_75 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_26 , V_28 ) ;
return V_28 ;
}
V_28 = F_78 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_27 , V_28 ) ;
return V_28 ;
}
V_28 = F_71 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_28 , V_28 ) ;
return V_28 ;
}
V_12 = F_82 ( V_88 , V_193 , L_29 ) ;
V_8 -> V_12 = F_83 ( & V_88 -> V_40 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_77 ( V_8 -> V_12 ) ;
goto V_194;
}
V_11 = F_82 ( V_88 , V_193 , L_22 ) ;
V_8 -> V_11 = F_83 ( & V_88 -> V_40 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_77 ( V_8 -> V_11 ) ;
goto V_194;
}
V_192 = F_82 ( V_88 , V_193 , L_30 ) ;
if ( ! V_192 ) {
V_28 = - V_195 ;
goto V_194;
}
V_8 -> V_24 = F_84 ( V_8 -> V_40 , V_192 -> V_25 ,
F_37 ( V_192 ) , V_192 -> V_196 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_195 ;
goto V_194;
}
V_28 = F_85 ( V_88 , L_31 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_32 , V_28 ) ;
goto V_194;
}
V_8 -> V_90 = V_28 ;
V_28 = F_86 ( V_8 -> V_90 , F_58 , V_197 , L_33 , V_8 ) ;
if ( V_28 ) {
F_19 ( & V_88 -> V_40 , L_34 , V_28 ) ;
goto V_194;
}
return 0 ;
V_194:
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
F_90 ( & V_3 -> V_198 ) ;
V_92 = F_91 ( V_3 -> V_199 , V_200 ) ;
if ( V_92 < V_200 )
F_92 ( V_92 , V_3 -> V_199 ) ;
else
V_92 = - V_201 ;
F_93 ( & V_3 -> V_198 ) ;
return V_92 ;
}
static void F_94 ( struct V_1 * V_3 , unsigned long V_90 )
{
struct V_202 * V_40 = V_3 -> V_3 . V_40 ;
F_90 ( & V_3 -> V_198 ) ;
if ( ! F_95 ( V_90 , V_3 -> V_199 ) )
F_19 ( V_40 , L_35 , V_90 ) ;
else
F_96 ( V_90 , V_3 -> V_199 ) ;
F_93 ( & V_3 -> V_198 ) ;
}
static T_7 F_97 ( int V_90 , void * V_203 )
{
struct V_4 * V_8 = V_203 ;
struct V_1 * V_92 = & V_8 -> V_92 ;
unsigned int V_27 , V_204 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_71 = F_6 ( V_8 , V_205 + V_27 * 4 ) ;
while ( V_71 ) {
unsigned int V_10 = F_98 ( & V_71 , 32 ) ;
unsigned int V_49 = V_27 * 32 + V_10 ;
unsigned int V_90 ;
F_4 ( V_8 , 1 << V_10 , V_205 + V_27 * 4 ) ;
V_90 = F_99 ( V_92 -> V_206 , V_49 ) ;
if ( V_90 ) {
if ( F_95 ( V_49 , V_92 -> V_199 ) )
F_100 ( V_90 ) ;
else
F_101 ( V_8 -> V_40 , L_36 ) ;
} else {
F_101 ( V_8 -> V_40 , L_37 ) ;
}
V_71 = F_6 ( V_8 , V_205 + V_27 * 4 ) ;
V_204 ++ ;
}
}
return V_204 > 0 ? V_109 : V_102 ;
}
static int F_102 ( struct V_2 * V_3 , struct V_70 * V_88 ,
struct V_207 * V_208 )
{
struct V_1 * V_92 = F_1 ( V_3 ) ;
struct V_209 V_210 ;
unsigned int V_90 ;
int V_211 ;
V_211 = F_89 ( V_92 ) ;
if ( V_211 < 0 )
return V_211 ;
V_90 = F_103 ( V_92 -> V_206 , V_211 ) ;
if ( ! V_90 )
return - V_212 ;
F_104 ( V_90 , V_208 ) ;
V_210 . V_213 = F_105 ( ( void * ) V_92 -> V_214 ) ;
V_210 . V_215 = 0 ;
V_210 . V_203 = V_211 ;
F_106 ( V_90 , & V_210 ) ;
return 0 ;
}
static void F_107 ( struct V_2 * V_3 , unsigned int V_90 )
{
struct V_1 * V_92 = F_1 ( V_3 ) ;
struct V_216 * V_217 = F_108 ( V_90 ) ;
F_94 ( V_92 , V_217 -> V_211 ) ;
}
static int F_109 ( struct V_218 * V_206 , unsigned int V_90 ,
T_9 V_211 )
{
F_110 ( V_90 , & V_219 , V_220 ) ;
F_111 ( V_90 , V_206 -> V_221 ) ;
F_112 ( V_90 , V_222 ) ;
F_51 () ;
return 0 ;
}
static int F_113 ( struct V_4 * V_8 )
{
struct V_190 * V_88 = F_81 ( V_8 -> V_40 ) ;
const struct V_63 * V_64 = V_8 -> V_65 ;
struct V_1 * V_92 = & V_8 -> V_92 ;
unsigned long V_50 ;
int V_28 ;
T_1 V_71 ;
F_114 ( & V_92 -> V_198 ) ;
V_92 -> V_3 . V_40 = V_8 -> V_40 ;
V_92 -> V_3 . V_223 = F_102 ;
V_92 -> V_3 . V_224 = F_107 ;
V_92 -> V_206 = F_115 ( V_8 -> V_40 -> V_225 , V_200 ,
& V_226 , & V_92 -> V_3 ) ;
if ( ! V_92 -> V_206 ) {
F_19 ( & V_88 -> V_40 , L_38 ) ;
return - V_30 ;
}
V_28 = F_85 ( V_88 , L_39 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_32 , V_28 ) ;
goto V_28;
}
V_92 -> V_90 = V_28 ;
V_28 = F_86 ( V_92 -> V_90 , F_97 , 0 ,
V_219 . V_196 , V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_40 , V_28 ) ;
goto V_28;
}
V_92 -> V_214 = F_116 ( V_29 , 0 ) ;
V_50 = F_105 ( ( void * ) V_92 -> V_214 ) ;
F_4 ( V_8 , V_50 >> V_64 -> V_227 , V_135 ) ;
F_4 ( V_8 , V_50 , V_137 ) ;
F_4 ( V_8 , 1 , V_136 ) ;
F_4 ( V_8 , 0xffffffff , V_228 ) ;
F_4 ( V_8 , 0xffffffff , V_229 ) ;
F_4 ( V_8 , 0xffffffff , V_230 ) ;
F_4 ( V_8 , 0xffffffff , V_231 ) ;
F_4 ( V_8 , 0xffffffff , V_232 ) ;
F_4 ( V_8 , 0xffffffff , V_233 ) ;
F_4 ( V_8 , 0xffffffff , V_234 ) ;
F_4 ( V_8 , 0xffffffff , V_235 ) ;
V_71 = F_6 ( V_8 , V_178 ) ;
V_71 |= V_236 ;
F_4 ( V_8 , V_71 , V_178 ) ;
return 0 ;
V_28:
F_117 ( V_92 -> V_206 ) ;
return V_28 ;
}
static int F_118 ( struct V_4 * V_8 )
{
struct V_1 * V_92 = & V_8 -> V_92 ;
unsigned int V_27 , V_90 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_178 ) ;
V_9 &= ~ V_236 ;
F_4 ( V_8 , V_9 , V_178 ) ;
F_4 ( V_8 , 0 , V_228 ) ;
F_4 ( V_8 , 0 , V_229 ) ;
F_4 ( V_8 , 0 , V_230 ) ;
F_4 ( V_8 , 0 , V_231 ) ;
F_4 ( V_8 , 0 , V_232 ) ;
F_4 ( V_8 , 0 , V_233 ) ;
F_4 ( V_8 , 0 , V_234 ) ;
F_4 ( V_8 , 0 , V_235 ) ;
F_119 ( V_92 -> V_214 , 0 ) ;
if ( V_92 -> V_90 > 0 )
F_88 ( V_92 -> V_90 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_200 ; V_27 ++ ) {
V_90 = F_99 ( V_92 -> V_206 , V_27 ) ;
if ( V_90 > 0 )
F_120 ( V_90 ) ;
}
F_117 ( V_92 -> V_206 ) ;
return 0 ;
}
static int F_121 ( struct V_4 * V_8 , T_1 V_237 ,
T_1 * V_238 )
{
struct V_239 * V_240 = V_8 -> V_40 -> V_225 ;
if ( F_122 ( V_240 , L_41 ) ) {
switch ( V_237 ) {
case 0x00000204 :
F_101 ( V_8 -> V_40 , L_42 ) ;
* V_238 = V_241 ;
return 0 ;
case 0x00020202 :
F_101 ( V_8 -> V_40 , L_43 ) ;
* V_238 = V_242 ;
return 0 ;
case 0x00010104 :
F_101 ( V_8 -> V_40 , L_44 ) ;
* V_238 = V_243 ;
return 0 ;
}
} else if ( F_122 ( V_240 , L_45 ) ) {
switch ( V_237 ) {
case 0x00000004 :
F_101 ( V_8 -> V_40 , L_46 ) ;
* V_238 = V_244 ;
return 0 ;
case 0x00000202 :
F_101 ( V_8 -> V_40 , L_47 ) ;
* V_238 = V_245 ;
return 0 ;
}
}
return - V_212 ;
}
static bool F_123 ( struct V_239 * V_240 ,
struct V_246 * V_184 ,
unsigned int V_183 )
{
char V_247 [ 32 ] ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_183 ; V_27 ++ ) {
snprintf ( V_247 , 32 , L_48 , V_184 [ V_27 ] . V_248 ) ;
if ( F_124 ( V_240 , V_247 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_125 ( struct V_4 * V_8 )
{
struct V_239 * V_240 = V_8 -> V_40 -> V_225 ;
if ( F_122 ( V_240 , L_41 ) )
V_8 -> V_183 = 3 ;
else if ( F_122 ( V_240 , L_45 ) )
V_8 -> V_183 = 2 ;
if ( V_8 -> V_183 == 0 ) {
F_19 ( V_8 -> V_40 , L_49 ,
V_240 -> V_249 ) ;
return - V_250 ;
}
V_8 -> V_184 = F_126 ( V_8 -> V_40 , V_8 -> V_183 ,
sizeof( * V_8 -> V_184 ) ,
V_29 ) ;
if ( ! V_8 -> V_184 )
return - V_30 ;
V_8 -> V_184 [ 0 ] . V_248 = L_50 ;
V_8 -> V_184 [ 1 ] . V_248 = L_51 ;
if ( V_8 -> V_183 > 2 )
V_8 -> V_184 [ 2 ] . V_248 = L_52 ;
return F_127 ( V_8 -> V_40 , V_8 -> V_183 ,
V_8 -> V_184 ) ;
}
static int F_128 ( struct V_4 * V_8 , T_1 V_251 )
{
struct V_239 * V_240 = V_8 -> V_40 -> V_225 ;
unsigned int V_27 = 0 ;
if ( F_122 ( V_240 , L_41 ) ) {
bool V_252 = false , V_253 = false ;
if ( V_251 & 0x0f )
V_252 = true ;
if ( V_251 & 0x30 )
V_253 = true ;
V_8 -> V_183 = 4 + ( V_252 ? 2 : 0 ) +
( V_253 ? 2 : 0 ) ;
V_8 -> V_184 = F_126 ( V_8 -> V_40 , V_8 -> V_183 ,
sizeof( * V_8 -> V_184 ) ,
V_29 ) ;
if ( ! V_8 -> V_184 )
return - V_30 ;
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_53 ;
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_54 ;
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_55 ;
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_56 ;
if ( V_252 ) {
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_57 ;
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_58 ;
}
if ( V_253 ) {
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_59 ;
V_8 -> V_184 [ V_27 ++ ] . V_248 = L_60 ;
}
} else if ( F_122 ( V_240 , L_45 ) ) {
V_8 -> V_183 = 5 ;
V_8 -> V_184 = F_126 ( V_8 -> V_40 , V_8 -> V_183 ,
sizeof( * V_8 -> V_184 ) ,
V_29 ) ;
if ( ! V_8 -> V_184 )
return - V_30 ;
V_8 -> V_184 [ 0 ] . V_248 = L_61 ;
V_8 -> V_184 [ 1 ] . V_248 = L_62 ;
V_8 -> V_184 [ 2 ] . V_248 = L_53 ;
V_8 -> V_184 [ 3 ] . V_248 = L_56 ;
V_8 -> V_184 [ 4 ] . V_248 = L_63 ;
}
if ( F_123 ( V_8 -> V_40 -> V_225 , V_8 -> V_184 ,
V_8 -> V_183 ) )
return F_127 ( V_8 -> V_40 , V_8 -> V_183 ,
V_8 -> V_184 ) ;
F_101 ( V_8 -> V_40 , L_64 ) ;
F_39 ( V_8 -> V_40 , V_8 -> V_184 ) ;
V_8 -> V_183 = 0 ;
return F_125 ( V_8 ) ;
}
static int F_129 ( struct V_4 * V_8 )
{
const struct V_63 * V_64 = V_8 -> V_65 ;
struct V_239 * V_240 = V_8 -> V_40 -> V_225 , * V_48 ;
struct V_254 V_255 ;
struct V_256 V_257 ;
T_1 V_237 = 0 , V_54 = 0 ;
unsigned int V_258 = 0 ;
struct V_191 V_192 ;
int V_28 ;
if ( F_130 ( & V_255 , V_240 ) ) {
F_19 ( V_8 -> V_40 , L_65 ) ;
return - V_212 ;
}
F_131 (&parser, &range) {
F_132 ( & V_257 , V_240 , & V_192 ) ;
switch ( V_192 . V_259 & V_260 ) {
case V_261 :
memcpy ( & V_8 -> V_87 , & V_192 , sizeof( V_192 ) ) ;
V_8 -> V_87 . V_196 = L_66 ;
break;
case V_193 :
if ( V_192 . V_259 & V_262 ) {
memcpy ( & V_8 -> V_85 , & V_192 , sizeof( V_192 ) ) ;
V_8 -> V_85 . V_196 = L_67 ;
} else {
memcpy ( & V_8 -> V_83 , & V_192 , sizeof( V_192 ) ) ;
V_8 -> V_83 . V_196 = L_68 ;
}
break;
}
}
V_28 = F_133 ( V_240 , & V_8 -> V_86 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_69 ,
V_28 ) ;
V_8 -> V_86 . V_196 = V_240 -> V_196 ;
V_8 -> V_86 . V_25 = 0 ;
V_8 -> V_86 . V_263 = 0xff ;
V_8 -> V_86 . V_259 = V_264 ;
}
F_134 (np, port) {
struct V_47 * V_265 ;
unsigned int V_49 ;
T_1 V_9 ;
V_28 = F_135 ( V_48 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_70 ,
V_28 ) ;
return V_28 ;
}
V_49 = F_11 ( V_28 ) ;
if ( V_49 < 1 || V_49 > V_64 -> V_158 ) {
F_19 ( V_8 -> V_40 , L_71 , V_49 ) ;
return - V_212 ;
}
V_49 -- ;
V_28 = F_136 ( V_48 , L_72 , & V_9 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_73 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_19 ( V_8 -> V_40 , L_74 , V_9 ) ;
return - V_212 ;
}
V_237 |= V_9 << ( V_49 << 3 ) ;
if ( ! F_137 ( V_48 ) ) {
V_258 += V_9 ;
continue;
}
V_54 |= ( ( 1 << V_9 ) - 1 ) << V_258 ;
V_258 += V_9 ;
V_265 = F_138 ( V_8 -> V_40 , sizeof( * V_265 ) , V_29 ) ;
if ( ! V_265 )
return - V_30 ;
V_28 = F_139 ( V_48 , 0 , & V_265 -> V_69 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_70 ,
V_28 ) ;
return V_28 ;
}
F_16 ( & V_265 -> V_31 ) ;
V_265 -> V_49 = V_49 ;
V_265 -> V_237 = V_9 ;
V_265 -> V_8 = V_8 ;
V_265 -> V_50 = F_83 ( V_8 -> V_40 , & V_265 -> V_69 ) ;
if ( F_24 ( V_265 -> V_50 ) )
return F_77 ( V_265 -> V_50 ) ;
F_25 ( & V_265 -> V_31 , & V_8 -> V_266 ) ;
}
V_28 = F_121 ( V_8 , V_237 , & V_8 -> V_144 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_40 , L_75 ) ;
return V_28 ;
}
V_28 = F_128 ( V_8 , V_54 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
static bool F_140 ( struct V_47 * V_48 )
{
unsigned int V_267 = 3 ;
unsigned long V_9 ;
do {
unsigned int V_138 = V_268 ;
do {
V_9 = F_7 ( V_48 -> V_50 + V_269 ) ;
if ( V_9 & V_270 )
break;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_138 );
if ( ! V_138 ) {
F_19 ( V_48 -> V_8 -> V_40 , L_76 ,
V_48 -> V_49 ) ;
goto V_271;
}
V_138 = V_268 ;
do {
V_9 = F_7 ( V_48 -> V_50 + V_272 ) ;
if ( V_9 & V_273 )
return true ;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_138 );
V_271:
F_30 ( V_48 ) ;
} while ( -- V_267 );
return false ;
}
static int F_141 ( struct V_4 * V_8 )
{
struct V_47 * V_48 , * V_55 ;
struct V_274 V_275 ;
F_142 (port, tmp, &pcie->ports, list) {
F_101 ( V_8 -> V_40 , L_77 ,
V_48 -> V_49 , V_48 -> V_237 ) ;
F_32 ( V_48 ) ;
if ( F_140 ( V_48 ) )
continue;
F_101 ( V_8 -> V_40 , L_78 , V_48 -> V_49 ) ;
F_33 ( V_48 ) ;
F_34 ( V_48 ) ;
}
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
V_275 . V_276 = 1 ;
V_275 . V_7 = ( void * * ) & V_8 ;
V_275 . V_277 = F_46 ;
V_275 . V_278 = F_50 ;
V_275 . V_279 = F_53 ;
V_275 . V_280 = F_55 ;
V_275 . V_281 = & V_93 ;
F_143 ( V_8 -> V_40 , & V_275 ) ;
return 0 ;
}
static void * F_144 ( struct V_282 * V_283 , T_10 * V_284 )
{
struct V_4 * V_8 = V_283 -> V_285 ;
if ( F_145 ( & V_8 -> V_266 ) )
return NULL ;
F_146 ( V_283 , L_79 ) ;
return F_147 ( & V_8 -> V_266 , * V_284 ) ;
}
static void * F_148 ( struct V_282 * V_283 , void * V_286 , T_10 * V_284 )
{
struct V_4 * V_8 = V_283 -> V_285 ;
return F_149 ( V_286 , & V_8 -> V_266 , V_284 ) ;
}
static void F_150 ( struct V_282 * V_283 , void * V_286 )
{
}
static int F_151 ( struct V_282 * V_283 , void * V_286 )
{
bool V_287 = false , V_288 = false ;
struct V_47 * V_48 ;
unsigned int V_9 ;
V_48 = F_152 ( V_286 , struct V_47 , V_31 ) ;
V_9 = F_7 ( V_48 -> V_50 + V_269 ) ;
if ( V_9 & V_270 )
V_287 = true ;
V_9 = F_7 ( V_48 -> V_50 + V_272 ) ;
if ( V_9 & V_273 )
V_288 = true ;
F_146 ( V_283 , L_80 , V_48 -> V_49 ) ;
if ( V_287 )
F_146 ( V_283 , L_81 ) ;
if ( V_288 ) {
if ( V_287 )
F_146 ( V_283 , L_82 ) ;
F_146 ( V_283 , L_83 ) ;
}
F_146 ( V_283 , L_84 ) ;
return 0 ;
}
static int F_153 ( struct V_289 * V_289 , struct V_290 * V_290 )
{
struct V_4 * V_8 = V_289 -> V_291 ;
struct V_282 * V_283 ;
int V_28 ;
V_28 = F_154 ( V_290 , & V_292 ) ;
if ( V_28 )
return V_28 ;
V_283 = V_290 -> V_7 ;
V_283 -> V_285 = V_8 ;
return 0 ;
}
static int F_155 ( struct V_4 * V_8 )
{
struct V_293 * V_290 ;
V_8 -> V_294 = F_156 ( L_85 , NULL ) ;
if ( ! V_8 -> V_294 )
return - V_30 ;
V_290 = F_157 ( L_86 , V_295 | V_296 , V_8 -> V_294 ,
V_8 , & V_297 ) ;
if ( ! V_290 )
goto remove;
return 0 ;
remove:
F_158 ( V_8 -> V_294 ) ;
V_8 -> V_294 = NULL ;
return - V_30 ;
}
static int F_159 ( struct V_190 * V_88 )
{
const struct V_298 * V_299 ;
struct V_4 * V_8 ;
int V_28 ;
V_299 = F_160 ( V_300 , & V_88 -> V_40 ) ;
if ( ! V_299 )
return - V_250 ;
V_8 = F_138 ( & V_88 -> V_40 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_16 ( & V_8 -> V_42 ) ;
F_16 ( & V_8 -> V_266 ) ;
V_8 -> V_65 = V_299 -> V_203 ;
V_8 -> V_40 = & V_88 -> V_40 ;
V_28 = F_129 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_301 = 0 ;
V_28 = F_80 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_87 , V_28 ) ;
return V_28 ;
}
V_28 = F_62 ( V_8 ) ;
if ( V_28 )
goto V_302;
F_61 ( V_8 ) ;
if ( F_54 ( V_91 ) ) {
V_28 = F_113 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 ,
L_88 ,
V_28 ) ;
goto V_302;
}
}
V_28 = F_141 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_88 -> V_40 , L_89 , V_28 ) ;
goto V_303;
}
if ( F_54 ( V_304 ) ) {
V_28 = F_155 ( V_8 ) ;
if ( V_28 < 0 )
F_19 ( & V_88 -> V_40 , L_90 ,
V_28 ) ;
}
F_161 ( V_88 , V_8 ) ;
return 0 ;
V_303:
if ( F_54 ( V_91 ) )
F_118 ( V_8 ) ;
V_302:
F_87 ( V_8 ) ;
return V_28 ;
}
