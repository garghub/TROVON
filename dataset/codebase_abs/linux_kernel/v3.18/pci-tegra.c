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
static void F_54 ( struct V_44 * V_26 )
{
if ( F_55 ( V_95 ) ) {
struct V_4 * V_8 = F_3 ( V_26 -> V_45 ) ;
V_26 -> V_96 = & V_8 -> V_96 . V_3 ;
}
}
static struct V_44 * F_56 ( int V_32 , struct V_5 * V_6 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
struct V_44 * V_26 ;
V_26 = F_57 ( V_8 -> V_41 , V_6 -> V_16 , & V_97 , V_6 ,
& V_6 -> V_87 ) ;
if ( ! V_26 )
return NULL ;
F_58 ( V_26 ) ;
return V_26 ;
}
static T_7 F_59 ( int V_94 , void * V_98 )
{
const char * V_99 [] = {
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
struct V_4 * V_8 = V_98 ;
T_1 V_100 , V_101 ;
V_100 = F_6 ( V_8 , V_102 ) & V_103 ;
V_101 = F_6 ( V_8 , V_104 ) ;
F_4 ( V_8 , 0 , V_102 ) ;
if ( V_100 == V_105 )
return V_106 ;
if ( V_100 >= F_60 ( V_99 ) )
V_100 = 0 ;
if ( V_100 == V_107 )
F_61 ( V_8 -> V_41 , L_18 , V_99 [ V_100 ] ,
V_101 ) ;
else
F_19 ( V_8 -> V_41 , L_18 , V_99 [ V_100 ] ,
V_101 ) ;
if ( V_100 == V_108 || V_100 == V_107 ||
V_100 == V_109 ) {
T_1 V_110 = F_6 ( V_8 , V_111 ) & 0xff ;
T_8 V_112 = ( T_8 ) V_110 << 32 | ( V_101 & 0xfffffffc ) ;
if ( V_100 == V_107 )
F_61 ( V_8 -> V_41 , L_19 , V_112 ) ;
else
F_19 ( V_8 -> V_41 , L_19 , V_112 ) ;
}
return V_113 ;
}
static void F_62 ( struct V_4 * V_8 )
{
T_1 V_114 , V_52 , V_115 ;
V_114 = 0xfe100000 ;
V_52 = F_37 ( V_8 -> V_24 ) ;
V_115 = V_8 -> V_24 -> V_25 ;
F_4 ( V_8 , V_115 , V_116 ) ;
F_4 ( V_8 , V_52 >> 12 , V_117 ) ;
F_4 ( V_8 , V_114 , V_118 ) ;
V_114 = 0xfdfc0000 ;
V_52 = F_37 ( & V_8 -> V_91 ) ;
V_115 = V_8 -> V_91 . V_25 ;
F_4 ( V_8 , V_115 , V_119 ) ;
F_4 ( V_8 , V_52 >> 12 , V_120 ) ;
F_4 ( V_8 , V_114 , V_121 ) ;
V_114 = ( ( ( V_8 -> V_86 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_52 = F_37 ( & V_8 -> V_86 ) ;
V_115 = V_8 -> V_86 . V_25 ;
F_4 ( V_8 , V_115 , V_122 ) ;
F_4 ( V_8 , V_52 >> 12 , V_123 ) ;
F_4 ( V_8 , V_114 , V_124 ) ;
V_114 = ( ( ( V_8 -> V_85 . V_25 >> 12 ) & 0x0fffffff ) << 4 ) | 0x1 ;
V_52 = F_37 ( & V_8 -> V_85 ) ;
V_115 = V_8 -> V_85 . V_25 ;
F_4 ( V_8 , V_115 , V_125 ) ;
F_4 ( V_8 , V_52 >> 12 , V_126 ) ;
F_4 ( V_8 , V_114 , V_127 ) ;
F_4 ( V_8 , 0 , V_128 ) ;
F_4 ( V_8 , 0 , V_129 ) ;
F_4 ( V_8 , 0 , V_130 ) ;
F_4 ( V_8 , 0 , V_131 ) ;
F_4 ( V_8 , 0 , V_132 ) ;
F_4 ( V_8 , 0 , V_133 ) ;
F_4 ( V_8 , V_134 , V_135 ) ;
F_4 ( V_8 , 0 , V_136 ) ;
F_4 ( V_8 , 0 , V_137 ) ;
F_4 ( V_8 , 0 , V_138 ) ;
F_4 ( V_8 , 0 , V_139 ) ;
F_4 ( V_8 , 0 , V_140 ) ;
F_4 ( V_8 , 0 , V_141 ) ;
F_4 ( V_8 , 0 , V_140 ) ;
}
static int F_63 ( struct V_4 * V_8 , unsigned long V_142 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
T_1 V_9 ;
V_142 = V_143 + F_64 ( V_142 ) ;
while ( F_65 ( V_143 , V_142 ) ) {
V_9 = F_9 ( V_8 , V_65 -> V_144 ) ;
if ( V_9 & V_145 )
return 0 ;
}
return - V_146 ;
}
static int F_66 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
T_1 V_9 ;
int V_28 ;
F_8 ( V_8 , 0x0 , V_147 ) ;
V_9 = F_9 ( V_8 , V_148 ) ;
V_9 |= V_149 ;
F_8 ( V_8 , V_9 , V_148 ) ;
V_9 = F_9 ( V_8 , V_65 -> V_144 ) ;
V_9 &= ~ ( V_150 | V_151 ) ;
V_9 |= V_152 | V_65 -> V_153 ;
F_8 ( V_8 , V_9 , V_65 -> V_144 ) ;
V_9 = F_9 ( V_8 , V_65 -> V_144 ) ;
V_9 &= ~ V_154 ;
F_8 ( V_8 , V_9 , V_65 -> V_144 ) ;
F_31 ( 20 , 100 ) ;
V_9 = F_9 ( V_8 , V_65 -> V_144 ) ;
V_9 |= V_154 ;
F_8 ( V_8 , V_9 , V_65 -> V_144 ) ;
V_9 = V_155 | ( V_155 << 16 ) ;
F_8 ( V_8 , V_9 , V_156 ) ;
if ( V_65 -> V_157 > 2 )
F_8 ( V_8 , V_155 , V_158 ) ;
V_28 = F_63 ( V_8 , 500 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_20 , V_28 ) ;
return V_28 ;
}
V_9 = F_9 ( V_8 , V_148 ) ;
V_9 &= ~ V_149 ;
F_8 ( V_8 , V_9 , V_148 ) ;
V_9 = F_9 ( V_8 , V_148 ) ;
V_9 |= V_159 | V_160 ;
F_8 ( V_8 , V_9 , V_148 ) ;
return 0 ;
}
static int F_67 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
struct V_48 * V_49 ;
unsigned long V_9 ;
int V_28 ;
if ( V_8 -> V_161 ) {
V_9 = F_6 ( V_8 , V_162 ) ;
V_9 &= ~ V_163 ;
V_9 |= V_164 ;
F_4 ( V_8 , V_9 , V_162 ) ;
}
if ( V_65 -> V_165 )
F_4 ( V_8 , 0 , V_166 ) ;
V_9 = F_6 ( V_8 , V_167 ) ;
V_9 &= ~ V_168 ;
V_9 |= V_169 | V_8 -> V_170 ;
F_23 (port, &pcie->ports, list)
V_9 &= ~ F_68 ( V_49 -> V_50 ) ;
F_4 ( V_8 , V_9 , V_167 ) ;
if ( V_65 -> V_171 ) {
V_9 = F_6 ( V_8 , V_172 ) ;
V_9 &= ~ V_173 ;
F_4 ( V_8 , V_9 , V_172 ) ;
} else {
V_9 = F_6 ( V_8 , V_172 ) ;
V_9 |= V_173 ;
F_4 ( V_8 , V_9 , V_172 ) ;
}
if ( ! V_8 -> V_161 )
V_28 = F_66 ( V_8 ) ;
else
V_28 = F_69 ( V_8 -> V_161 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_21 , V_28 ) ;
return V_28 ;
}
F_70 ( V_8 -> V_174 ) ;
V_9 = F_6 ( V_8 , V_175 ) ;
V_9 |= V_176 ;
F_4 ( V_8 , V_9 , V_175 ) ;
V_9 = V_177 | V_178 |
V_179 | V_180 |
V_181 | V_182 ;
if ( V_65 -> V_183 )
V_9 |= V_184 ;
F_4 ( V_8 , V_9 , V_185 ) ;
F_4 ( V_8 , 0xffffffff , V_186 ) ;
F_4 ( V_8 , V_187 , V_188 ) ;
F_4 ( V_8 , 0 , V_189 ) ;
return 0 ;
}
static void F_71 ( struct V_4 * V_8 )
{
int V_28 ;
V_28 = F_72 ( V_8 -> V_161 ) ;
if ( V_28 < 0 )
F_73 ( V_8 -> V_41 , L_22 , V_28 ) ;
F_74 ( V_8 -> V_174 ) ;
F_74 ( V_8 -> V_190 ) ;
F_74 ( V_8 -> V_191 ) ;
F_75 ( V_192 ) ;
V_28 = F_76 ( V_8 -> V_193 , V_8 -> V_194 ) ;
if ( V_28 < 0 )
F_73 ( V_8 -> V_41 , L_23 , V_28 ) ;
}
static int F_77 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
int V_28 ;
F_74 ( V_8 -> V_174 ) ;
F_74 ( V_8 -> V_190 ) ;
F_74 ( V_8 -> V_191 ) ;
F_75 ( V_192 ) ;
V_28 = F_78 ( V_8 -> V_193 , V_8 -> V_194 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_24 , V_28 ) ;
V_28 = F_79 ( V_192 ,
V_8 -> V_195 ,
V_8 -> V_191 ) ;
if ( V_28 ) {
F_19 ( V_8 -> V_41 , L_25 , V_28 ) ;
return V_28 ;
}
F_70 ( V_8 -> V_190 ) ;
V_28 = F_80 ( V_8 -> V_196 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_26 , V_28 ) ;
return V_28 ;
}
if ( V_65 -> V_197 ) {
V_28 = F_80 ( V_8 -> V_198 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_27 ,
V_28 ) ;
return V_28 ;
}
}
V_28 = F_80 ( V_8 -> V_199 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_28 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
static int F_81 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
V_8 -> V_195 = F_82 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_195 ) )
return F_83 ( V_8 -> V_195 ) ;
V_8 -> V_196 = F_82 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_196 ) )
return F_83 ( V_8 -> V_196 ) ;
V_8 -> V_199 = F_82 ( V_8 -> V_41 , L_31 ) ;
if ( F_24 ( V_8 -> V_199 ) )
return F_83 ( V_8 -> V_199 ) ;
if ( V_65 -> V_197 ) {
V_8 -> V_198 = F_82 ( V_8 -> V_41 , L_32 ) ;
if ( F_24 ( V_8 -> V_198 ) )
return F_83 ( V_8 -> V_198 ) ;
}
return 0 ;
}
static int F_84 ( struct V_4 * V_8 )
{
V_8 -> V_191 = F_85 ( V_8 -> V_41 , L_29 ) ;
if ( F_24 ( V_8 -> V_191 ) )
return F_83 ( V_8 -> V_191 ) ;
V_8 -> V_190 = F_85 ( V_8 -> V_41 , L_30 ) ;
if ( F_24 ( V_8 -> V_190 ) )
return F_83 ( V_8 -> V_190 ) ;
V_8 -> V_174 = F_85 ( V_8 -> V_41 , L_33 ) ;
if ( F_24 ( V_8 -> V_174 ) )
return F_83 ( V_8 -> V_174 ) ;
return 0 ;
}
static int F_86 ( struct V_4 * V_8 )
{
struct V_200 * V_92 = F_87 ( V_8 -> V_41 ) ;
struct V_201 * V_12 , * V_11 , * V_202 ;
int V_28 ;
V_28 = F_81 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_34 , V_28 ) ;
return V_28 ;
}
V_28 = F_84 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_35 , V_28 ) ;
return V_28 ;
}
V_8 -> V_161 = F_88 ( V_8 -> V_41 , L_36 ) ;
if ( F_24 ( V_8 -> V_161 ) ) {
V_28 = F_83 ( V_8 -> V_161 ) ;
F_19 ( & V_92 -> V_41 , L_37 , V_28 ) ;
return V_28 ;
}
V_28 = F_89 ( V_8 -> V_161 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_38 , V_28 ) ;
return V_28 ;
}
V_28 = F_77 ( V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_39 , V_28 ) ;
return V_28 ;
}
V_12 = F_90 ( V_92 , V_203 , L_40 ) ;
V_8 -> V_12 = F_91 ( & V_92 -> V_41 , V_12 ) ;
if ( F_24 ( V_8 -> V_12 ) ) {
V_28 = F_83 ( V_8 -> V_12 ) ;
goto V_204;
}
V_11 = F_90 ( V_92 , V_203 , L_30 ) ;
V_8 -> V_11 = F_91 ( & V_92 -> V_41 , V_11 ) ;
if ( F_24 ( V_8 -> V_11 ) ) {
V_28 = F_83 ( V_8 -> V_11 ) ;
goto V_204;
}
V_202 = F_90 ( V_92 , V_203 , L_41 ) ;
if ( ! V_202 ) {
V_28 = - V_205 ;
goto V_204;
}
V_8 -> V_24 = F_92 ( V_8 -> V_41 , V_202 -> V_25 ,
F_37 ( V_202 ) , V_202 -> V_206 ) ;
if ( ! V_8 -> V_24 ) {
V_28 = - V_205 ;
goto V_204;
}
V_28 = F_93 ( V_92 , L_42 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_43 , V_28 ) ;
goto V_204;
}
V_8 -> V_94 = V_28 ;
V_28 = F_94 ( V_8 -> V_94 , F_59 , V_207 , L_44 , V_8 ) ;
if ( V_28 ) {
F_19 ( & V_92 -> V_41 , L_45 , V_28 ) ;
goto V_204;
}
return 0 ;
V_204:
F_71 ( V_8 ) ;
return V_28 ;
}
static int F_95 ( struct V_4 * V_8 )
{
int V_28 ;
if ( V_8 -> V_94 > 0 )
F_96 ( V_8 -> V_94 , V_8 ) ;
F_71 ( V_8 ) ;
V_28 = F_97 ( V_8 -> V_161 ) ;
if ( V_28 < 0 )
F_19 ( V_8 -> V_41 , L_46 , V_28 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_3 )
{
int V_96 ;
F_99 ( & V_3 -> V_208 ) ;
V_96 = F_100 ( V_3 -> V_209 , V_210 ) ;
if ( V_96 < V_210 )
F_101 ( V_96 , V_3 -> V_209 ) ;
else
V_96 = - V_211 ;
F_102 ( & V_3 -> V_208 ) ;
return V_96 ;
}
static void F_103 ( struct V_1 * V_3 , unsigned long V_94 )
{
struct V_212 * V_41 = V_3 -> V_3 . V_41 ;
F_99 ( & V_3 -> V_208 ) ;
if ( ! F_104 ( V_94 , V_3 -> V_209 ) )
F_19 ( V_41 , L_47 , V_94 ) ;
else
F_105 ( V_94 , V_3 -> V_209 ) ;
F_102 ( & V_3 -> V_208 ) ;
}
static T_7 F_106 ( int V_94 , void * V_213 )
{
struct V_4 * V_8 = V_213 ;
struct V_1 * V_96 = & V_8 -> V_96 ;
unsigned int V_27 , V_214 = 0 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
unsigned long V_73 = F_6 ( V_8 , V_215 + V_27 * 4 ) ;
while ( V_73 ) {
unsigned int V_10 = F_107 ( & V_73 , 32 ) ;
unsigned int V_50 = V_27 * 32 + V_10 ;
unsigned int V_94 ;
F_4 ( V_8 , 1 << V_10 , V_215 + V_27 * 4 ) ;
V_94 = F_108 ( V_96 -> V_216 , V_50 ) ;
if ( V_94 ) {
if ( F_104 ( V_50 , V_96 -> V_209 ) )
F_109 ( V_94 ) ;
else
F_110 ( V_8 -> V_41 , L_48 ) ;
} else {
F_110 ( V_8 -> V_41 , L_49 ) ;
}
V_73 = F_6 ( V_8 , V_215 + V_27 * 4 ) ;
V_214 ++ ;
}
}
return V_214 > 0 ? V_113 : V_106 ;
}
static int F_111 ( struct V_2 * V_3 , struct V_72 * V_92 ,
struct V_217 * V_218 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
struct V_219 V_220 ;
unsigned int V_94 ;
int V_221 ;
V_221 = F_98 ( V_96 ) ;
if ( V_221 < 0 )
return V_221 ;
V_94 = F_112 ( V_96 -> V_216 , V_221 ) ;
if ( ! V_94 ) {
F_103 ( V_96 , V_221 ) ;
return - V_222 ;
}
F_113 ( V_94 , V_218 ) ;
V_220 . V_223 = F_114 ( ( void * ) V_96 -> V_224 ) ;
V_220 . V_225 = 0 ;
V_220 . V_213 = V_221 ;
F_115 ( V_94 , & V_220 ) ;
return 0 ;
}
static void F_116 ( struct V_2 * V_3 , unsigned int V_94 )
{
struct V_1 * V_96 = F_1 ( V_3 ) ;
struct V_226 * V_227 = F_117 ( V_94 ) ;
T_9 V_221 = F_118 ( V_227 ) ;
F_119 ( V_94 ) ;
F_103 ( V_96 , V_221 ) ;
}
static int F_120 ( struct V_228 * V_216 , unsigned int V_94 ,
T_9 V_221 )
{
F_121 ( V_94 , & V_229 , V_230 ) ;
F_122 ( V_94 , V_216 -> V_231 ) ;
F_123 ( V_94 , V_232 ) ;
F_52 () ;
return 0 ;
}
static int F_124 ( struct V_4 * V_8 )
{
struct V_200 * V_92 = F_87 ( V_8 -> V_41 ) ;
const struct V_64 * V_65 = V_8 -> V_66 ;
struct V_1 * V_96 = & V_8 -> V_96 ;
unsigned long V_51 ;
int V_28 ;
T_1 V_73 ;
F_125 ( & V_96 -> V_208 ) ;
V_96 -> V_3 . V_41 = V_8 -> V_41 ;
V_96 -> V_3 . V_233 = F_111 ;
V_96 -> V_3 . V_234 = F_116 ;
V_96 -> V_216 = F_126 ( V_8 -> V_41 -> V_235 , V_210 ,
& V_236 , & V_96 -> V_3 ) ;
if ( ! V_96 -> V_216 ) {
F_19 ( & V_92 -> V_41 , L_50 ) ;
return - V_30 ;
}
V_28 = F_93 ( V_92 , L_51 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_43 , V_28 ) ;
goto V_28;
}
V_96 -> V_94 = V_28 ;
V_28 = F_94 ( V_96 -> V_94 , F_106 , 0 ,
V_229 . V_206 , V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_52 , V_28 ) ;
goto V_28;
}
V_96 -> V_224 = F_127 ( V_29 , 0 ) ;
V_51 = F_114 ( ( void * ) V_96 -> V_224 ) ;
F_4 ( V_8 , V_51 >> V_65 -> V_237 , V_139 ) ;
F_4 ( V_8 , V_51 , V_141 ) ;
F_4 ( V_8 , 1 , V_140 ) ;
F_4 ( V_8 , 0xffffffff , V_238 ) ;
F_4 ( V_8 , 0xffffffff , V_239 ) ;
F_4 ( V_8 , 0xffffffff , V_240 ) ;
F_4 ( V_8 , 0xffffffff , V_241 ) ;
F_4 ( V_8 , 0xffffffff , V_242 ) ;
F_4 ( V_8 , 0xffffffff , V_243 ) ;
F_4 ( V_8 , 0xffffffff , V_244 ) ;
F_4 ( V_8 , 0xffffffff , V_245 ) ;
V_73 = F_6 ( V_8 , V_188 ) ;
V_73 |= V_246 ;
F_4 ( V_8 , V_73 , V_188 ) ;
return 0 ;
V_28:
F_128 ( V_96 -> V_216 ) ;
return V_28 ;
}
static int F_129 ( struct V_4 * V_8 )
{
struct V_1 * V_96 = & V_8 -> V_96 ;
unsigned int V_27 , V_94 ;
T_1 V_9 ;
V_9 = F_6 ( V_8 , V_188 ) ;
V_9 &= ~ V_246 ;
F_4 ( V_8 , V_9 , V_188 ) ;
F_4 ( V_8 , 0 , V_238 ) ;
F_4 ( V_8 , 0 , V_239 ) ;
F_4 ( V_8 , 0 , V_240 ) ;
F_4 ( V_8 , 0 , V_241 ) ;
F_4 ( V_8 , 0 , V_242 ) ;
F_4 ( V_8 , 0 , V_243 ) ;
F_4 ( V_8 , 0 , V_244 ) ;
F_4 ( V_8 , 0 , V_245 ) ;
F_130 ( V_96 -> V_224 , 0 ) ;
if ( V_96 -> V_94 > 0 )
F_96 ( V_96 -> V_94 , V_8 ) ;
for ( V_27 = 0 ; V_27 < V_210 ; V_27 ++ ) {
V_94 = F_108 ( V_96 -> V_216 , V_27 ) ;
if ( V_94 > 0 )
F_119 ( V_94 ) ;
}
F_128 ( V_96 -> V_216 ) ;
return 0 ;
}
static int F_131 ( struct V_4 * V_8 , T_1 V_247 ,
T_1 * V_248 )
{
struct V_249 * V_250 = V_8 -> V_41 -> V_235 ;
if ( F_132 ( V_250 , L_53 ) ) {
switch ( V_247 ) {
case 0x0000104 :
F_110 ( V_8 -> V_41 , L_54 ) ;
* V_248 = V_251 ;
return 0 ;
case 0x0000102 :
F_110 ( V_8 -> V_41 , L_55 ) ;
* V_248 = V_252 ;
return 0 ;
}
} else if ( F_132 ( V_250 , L_56 ) ) {
switch ( V_247 ) {
case 0x00000204 :
F_110 ( V_8 -> V_41 , L_57 ) ;
* V_248 = V_253 ;
return 0 ;
case 0x00020202 :
F_110 ( V_8 -> V_41 , L_58 ) ;
* V_248 = V_254 ;
return 0 ;
case 0x00010104 :
F_110 ( V_8 -> V_41 , L_59 ) ;
* V_248 = V_255 ;
return 0 ;
}
} else if ( F_132 ( V_250 , L_60 ) ) {
switch ( V_247 ) {
case 0x00000004 :
F_110 ( V_8 -> V_41 , L_61 ) ;
* V_248 = V_256 ;
return 0 ;
case 0x00000202 :
F_110 ( V_8 -> V_41 , L_62 ) ;
* V_248 = V_257 ;
return 0 ;
}
}
return - V_222 ;
}
static bool F_133 ( struct V_249 * V_250 ,
struct V_258 * V_194 ,
unsigned int V_193 )
{
char V_259 [ 32 ] ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_193 ; V_27 ++ ) {
snprintf ( V_259 , 32 , L_63 , V_194 [ V_27 ] . V_260 ) ;
if ( F_134 ( V_250 , V_259 , NULL ) == NULL )
return false ;
}
return true ;
}
static int F_135 ( struct V_4 * V_8 )
{
struct V_249 * V_250 = V_8 -> V_41 -> V_235 ;
if ( F_132 ( V_250 , L_56 ) )
V_8 -> V_193 = 3 ;
else if ( F_132 ( V_250 , L_60 ) )
V_8 -> V_193 = 2 ;
if ( V_8 -> V_193 == 0 ) {
F_19 ( V_8 -> V_41 , L_64 ,
V_250 -> V_261 ) ;
return - V_262 ;
}
V_8 -> V_194 = F_136 ( V_8 -> V_41 , V_8 -> V_193 ,
sizeof( * V_8 -> V_194 ) ,
V_29 ) ;
if ( ! V_8 -> V_194 )
return - V_30 ;
V_8 -> V_194 [ 0 ] . V_260 = L_65 ;
V_8 -> V_194 [ 1 ] . V_260 = L_66 ;
if ( V_8 -> V_193 > 2 )
V_8 -> V_194 [ 2 ] . V_260 = L_67 ;
return F_137 ( V_8 -> V_41 , V_8 -> V_193 ,
V_8 -> V_194 ) ;
}
static int F_138 ( struct V_4 * V_8 , T_1 V_263 )
{
struct V_249 * V_250 = V_8 -> V_41 -> V_235 ;
unsigned int V_27 = 0 ;
if ( F_132 ( V_250 , L_53 ) ) {
V_8 -> V_193 = 7 ;
V_8 -> V_194 = F_136 ( V_8 -> V_41 , V_8 -> V_193 ,
sizeof( * V_8 -> V_194 ) ,
V_29 ) ;
if ( ! V_8 -> V_194 )
return - V_30 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_68 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_69 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_70 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_71 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_72 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_73 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_74 ;
} else if ( F_132 ( V_250 , L_56 ) ) {
bool V_264 = false , V_265 = false ;
if ( V_263 & 0x0f )
V_264 = true ;
if ( V_263 & 0x30 )
V_265 = true ;
V_8 -> V_193 = 4 + ( V_264 ? 2 : 0 ) +
( V_265 ? 2 : 0 ) ;
V_8 -> V_194 = F_136 ( V_8 -> V_41 , V_8 -> V_193 ,
sizeof( * V_8 -> V_194 ) ,
V_29 ) ;
if ( ! V_8 -> V_194 )
return - V_30 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_70 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_71 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_73 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_75 ;
if ( V_264 ) {
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_76 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_77 ;
}
if ( V_265 ) {
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_78 ;
V_8 -> V_194 [ V_27 ++ ] . V_260 = L_79 ;
}
} else if ( F_132 ( V_250 , L_60 ) ) {
V_8 -> V_193 = 5 ;
V_8 -> V_194 = F_136 ( V_8 -> V_41 , V_8 -> V_193 ,
sizeof( * V_8 -> V_194 ) ,
V_29 ) ;
if ( ! V_8 -> V_194 )
return - V_30 ;
V_8 -> V_194 [ 0 ] . V_260 = L_80 ;
V_8 -> V_194 [ 1 ] . V_260 = L_81 ;
V_8 -> V_194 [ 2 ] . V_260 = L_70 ;
V_8 -> V_194 [ 3 ] . V_260 = L_75 ;
V_8 -> V_194 [ 4 ] . V_260 = L_82 ;
}
if ( F_133 ( V_8 -> V_41 -> V_235 , V_8 -> V_194 ,
V_8 -> V_193 ) )
return F_137 ( V_8 -> V_41 , V_8 -> V_193 ,
V_8 -> V_194 ) ;
F_110 ( V_8 -> V_41 , L_83 ) ;
F_39 ( V_8 -> V_41 , V_8 -> V_194 ) ;
V_8 -> V_193 = 0 ;
return F_135 ( V_8 ) ;
}
static int F_139 ( struct V_4 * V_8 )
{
const struct V_64 * V_65 = V_8 -> V_66 ;
struct V_249 * V_250 = V_8 -> V_41 -> V_235 , * V_49 ;
struct V_266 V_267 ;
struct V_268 V_269 ;
T_1 V_247 = 0 , V_55 = 0 ;
unsigned int V_270 = 0 ;
struct V_201 V_202 ;
int V_28 ;
memset ( & V_8 -> V_84 , 0 , sizeof( V_8 -> V_84 ) ) ;
V_8 -> V_84 . V_271 = V_203 ;
V_8 -> V_84 . V_206 = V_250 -> V_261 ;
V_8 -> V_84 . V_25 = ~ 0 ;
V_8 -> V_84 . V_272 = 0 ;
if ( F_140 ( & V_267 , V_250 ) ) {
F_19 ( V_8 -> V_41 , L_84 ) ;
return - V_222 ;
}
F_141 (&parser, &range) {
V_28 = F_142 ( & V_269 , V_250 , & V_202 ) ;
if ( V_28 < 0 )
return V_28 ;
switch ( V_202 . V_271 & V_273 ) {
case V_274 :
memcpy ( & V_8 -> V_90 , & V_202 , sizeof( V_202 ) ) ;
V_8 -> V_90 . V_206 = V_250 -> V_261 ;
V_8 -> V_91 . V_25 = V_269 . V_275 ;
V_8 -> V_91 . V_272 = V_269 . V_275 + V_269 . V_52 - 1 ;
V_8 -> V_91 . V_271 = V_203 ;
V_8 -> V_91 . V_206 = L_85 ;
memcpy ( & V_202 , & V_8 -> V_91 , sizeof( V_202 ) ) ;
break;
case V_203 :
if ( V_202 . V_271 & V_276 ) {
memcpy ( & V_8 -> V_86 , & V_202 , sizeof( V_202 ) ) ;
V_8 -> V_86 . V_206 = L_86 ;
} else {
memcpy ( & V_8 -> V_85 , & V_202 , sizeof( V_202 ) ) ;
V_8 -> V_85 . V_206 = L_87 ;
}
break;
}
if ( V_202 . V_25 <= V_8 -> V_84 . V_25 )
V_8 -> V_84 . V_25 = V_202 . V_25 ;
if ( V_202 . V_272 >= V_8 -> V_84 . V_272 )
V_8 -> V_84 . V_272 = V_202 . V_272 ;
}
V_28 = F_47 ( V_8 -> V_41 , & V_277 , & V_8 -> V_84 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_143 ( V_250 , & V_8 -> V_89 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_88 ,
V_28 ) ;
V_8 -> V_89 . V_206 = V_250 -> V_206 ;
V_8 -> V_89 . V_25 = 0 ;
V_8 -> V_89 . V_272 = 0xff ;
V_8 -> V_89 . V_271 = V_278 ;
}
F_144 (np, port) {
struct V_48 * V_279 ;
unsigned int V_50 ;
T_1 V_9 ;
V_28 = F_145 ( V_49 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
V_50 = F_11 ( V_28 ) ;
if ( V_50 < 1 || V_50 > V_65 -> V_157 ) {
F_19 ( V_8 -> V_41 , L_90 , V_50 ) ;
return - V_222 ;
}
V_50 -- ;
V_28 = F_146 ( V_49 , L_91 , & V_9 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_92 ,
V_28 ) ;
return V_28 ;
}
if ( V_9 > 16 ) {
F_19 ( V_8 -> V_41 , L_93 , V_9 ) ;
return - V_222 ;
}
V_247 |= V_9 << ( V_50 << 3 ) ;
if ( ! F_147 ( V_49 ) ) {
V_270 += V_9 ;
continue;
}
V_55 |= ( ( 1 << V_9 ) - 1 ) << V_270 ;
V_270 += V_9 ;
V_279 = F_148 ( V_8 -> V_41 , sizeof( * V_279 ) , V_29 ) ;
if ( ! V_279 )
return - V_30 ;
V_28 = F_149 ( V_49 , 0 , & V_279 -> V_71 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_89 ,
V_28 ) ;
return V_28 ;
}
F_16 ( & V_279 -> V_31 ) ;
V_279 -> V_50 = V_50 ;
V_279 -> V_247 = V_9 ;
V_279 -> V_8 = V_8 ;
V_279 -> V_51 = F_91 ( V_8 -> V_41 , & V_279 -> V_71 ) ;
if ( F_24 ( V_279 -> V_51 ) )
return F_83 ( V_279 -> V_51 ) ;
F_25 ( & V_279 -> V_31 , & V_8 -> V_280 ) ;
}
V_28 = F_131 ( V_8 , V_247 , & V_8 -> V_170 ) ;
if ( V_28 < 0 ) {
F_19 ( V_8 -> V_41 , L_94 ) ;
return V_28 ;
}
V_28 = F_138 ( V_8 , V_55 ) ;
if ( V_28 < 0 )
return V_28 ;
return 0 ;
}
static bool F_150 ( struct V_48 * V_49 )
{
unsigned int V_281 = 3 ;
unsigned long V_9 ;
V_9 = F_7 ( V_49 -> V_51 + V_282 ) ;
V_9 &= ~ V_283 ;
V_9 |= V_284 ;
F_5 ( V_9 , V_49 -> V_51 + V_282 ) ;
do {
unsigned int V_142 = V_285 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_286 ) ;
if ( V_9 & V_287 )
break;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_142 );
if ( ! V_142 ) {
F_19 ( V_49 -> V_8 -> V_41 , L_95 ,
V_49 -> V_50 ) ;
goto V_288;
}
V_142 = V_285 ;
do {
V_9 = F_7 ( V_49 -> V_51 + V_289 ) ;
if ( V_9 & V_290 )
return true ;
F_31 ( 1000 , 2000 ) ;
} while ( -- V_142 );
V_288:
F_30 ( V_49 ) ;
} while ( -- V_281 );
return false ;
}
static int F_151 ( struct V_4 * V_8 )
{
struct V_48 * V_49 , * V_56 ;
struct V_291 V_292 ;
F_152 (port, tmp, &pcie->ports, list) {
F_110 ( V_8 -> V_41 , L_96 ,
V_49 -> V_50 , V_49 -> V_247 ) ;
F_32 ( V_49 ) ;
if ( F_150 ( V_49 ) )
continue;
F_110 ( V_8 -> V_41 , L_97 , V_49 -> V_50 ) ;
F_33 ( V_49 ) ;
F_34 ( V_49 ) ;
}
memset ( & V_292 , 0 , sizeof( V_292 ) ) ;
V_292 . V_293 = 1 ;
V_292 . V_7 = ( void * * ) & V_8 ;
V_292 . V_294 = F_46 ;
V_292 . V_295 = F_51 ;
V_292 . V_296 = F_54 ;
V_292 . V_297 = F_56 ;
V_292 . V_298 = & V_97 ;
F_153 ( V_8 -> V_41 , & V_292 ) ;
return 0 ;
}
static void * F_154 ( struct V_299 * V_300 , T_10 * V_301 )
{
struct V_4 * V_8 = V_300 -> V_302 ;
if ( F_155 ( & V_8 -> V_280 ) )
return NULL ;
F_156 ( V_300 , L_98 ) ;
return F_157 ( & V_8 -> V_280 , * V_301 ) ;
}
static void * F_158 ( struct V_299 * V_300 , void * V_303 , T_10 * V_301 )
{
struct V_4 * V_8 = V_300 -> V_302 ;
return F_159 ( V_303 , & V_8 -> V_280 , V_301 ) ;
}
static void F_160 ( struct V_299 * V_300 , void * V_303 )
{
}
static int F_161 ( struct V_299 * V_300 , void * V_303 )
{
bool V_304 = false , V_305 = false ;
struct V_48 * V_49 ;
unsigned int V_9 ;
V_49 = F_162 ( V_303 , struct V_48 , V_31 ) ;
V_9 = F_7 ( V_49 -> V_51 + V_286 ) ;
if ( V_9 & V_287 )
V_304 = true ;
V_9 = F_7 ( V_49 -> V_51 + V_289 ) ;
if ( V_9 & V_290 )
V_305 = true ;
F_156 ( V_300 , L_99 , V_49 -> V_50 ) ;
if ( V_304 )
F_156 ( V_300 , L_100 ) ;
if ( V_305 ) {
if ( V_304 )
F_156 ( V_300 , L_101 ) ;
F_156 ( V_300 , L_102 ) ;
}
F_156 ( V_300 , L_103 ) ;
return 0 ;
}
static int F_163 ( struct V_306 * V_306 , struct V_307 * V_307 )
{
struct V_4 * V_8 = V_306 -> V_308 ;
struct V_299 * V_300 ;
int V_28 ;
V_28 = F_164 ( V_307 , & V_309 ) ;
if ( V_28 )
return V_28 ;
V_300 = V_307 -> V_7 ;
V_300 -> V_302 = V_8 ;
return 0 ;
}
static int F_165 ( struct V_4 * V_8 )
{
struct V_310 * V_307 ;
V_8 -> V_311 = F_166 ( L_36 , NULL ) ;
if ( ! V_8 -> V_311 )
return - V_30 ;
V_307 = F_167 ( L_104 , V_312 | V_313 , V_8 -> V_311 ,
V_8 , & V_314 ) ;
if ( ! V_307 )
goto remove;
return 0 ;
remove:
F_168 ( V_8 -> V_311 ) ;
V_8 -> V_311 = NULL ;
return - V_30 ;
}
static int F_169 ( struct V_200 * V_92 )
{
const struct V_315 * V_316 ;
struct V_4 * V_8 ;
int V_28 ;
V_316 = F_170 ( V_317 , & V_92 -> V_41 ) ;
if ( ! V_316 )
return - V_262 ;
V_8 = F_148 ( & V_92 -> V_41 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
F_16 ( & V_8 -> V_43 ) ;
F_16 ( & V_8 -> V_280 ) ;
V_8 -> V_66 = V_316 -> V_213 ;
V_8 -> V_41 = & V_92 -> V_41 ;
V_28 = F_139 ( V_8 ) ;
if ( V_28 < 0 )
return V_28 ;
V_318 = 0 ;
V_28 = F_86 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_105 , V_28 ) ;
return V_28 ;
}
V_28 = F_67 ( V_8 ) ;
if ( V_28 )
goto V_319;
F_62 ( V_8 ) ;
if ( F_55 ( V_95 ) ) {
V_28 = F_124 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 ,
L_106 ,
V_28 ) ;
goto V_319;
}
}
V_28 = F_151 ( V_8 ) ;
if ( V_28 < 0 ) {
F_19 ( & V_92 -> V_41 , L_107 , V_28 ) ;
goto V_320;
}
if ( F_55 ( V_321 ) ) {
V_28 = F_165 ( V_8 ) ;
if ( V_28 < 0 )
F_19 ( & V_92 -> V_41 , L_108 ,
V_28 ) ;
}
F_171 ( V_92 , V_8 ) ;
return 0 ;
V_320:
if ( F_55 ( V_95 ) )
F_129 ( V_8 ) ;
V_319:
F_95 ( V_8 ) ;
return V_28 ;
}
