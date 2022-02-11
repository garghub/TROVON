static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_5 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_5 ( V_6 , V_2 -> V_7 ) ;
}
static int F_6 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_9 ( void * V_8 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_9 ;
V_9 = F_10 ( V_4 , 124 , & V_4 -> V_10 . V_11 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_11 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 = & V_4 -> V_10 . V_2 ;
sprintf ( V_2 -> V_12 , L_1 ) ;
V_9 = F_13 ( V_4 , V_2 , 512 , & V_4 -> V_10 . V_11 , 0 ) ;
return V_9 ;
}
static int F_14 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_16 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_17 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_13 ;
int V_9 ;
F_18 ( V_4 , 10000 , 10000 ) ;
F_19 ( V_4 , V_14 ) ;
F_20 ( V_4 , true ) ;
V_2 -> V_15 = true ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 ) {
V_2 -> V_15 = false ;
goto V_16;
}
V_9 = F_22 ( V_2 , 10 ) ;
if ( V_9 ) {
F_23 ( L_2 , V_9 ) ;
goto V_16;
}
V_13 = F_24 ( V_17 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_13 = F_24 ( V_18 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
V_13 = F_24 ( V_19 , 0 ) ;
F_25 ( V_2 , V_13 ) ;
F_25 ( V_2 , 0xFFFFF ) ;
F_25 ( V_2 , F_24 ( V_20 , 0 ) ) ;
F_25 ( V_2 , 0x8 ) ;
F_25 ( V_2 , F_24 ( V_21 , 0 ) ) ;
F_25 ( V_2 , 3 ) ;
F_26 ( V_2 ) ;
V_16:
if ( ! V_9 )
F_27 ( L_3 ) ;
return V_9 ;
}
static int F_28 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
if ( F_2 ( V_22 ) != 0 )
F_29 ( V_4 ) ;
V_2 -> V_15 = false ;
return 0 ;
}
static int F_30 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_28 ( V_4 ) ;
if ( V_9 )
return V_9 ;
F_19 ( V_4 , V_23 ) ;
V_9 = F_15 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static int F_31 ( void * V_8 )
{
int V_9 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
V_9 = F_12 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
return V_9 ;
return V_9 ;
}
static void F_32 ( struct V_3 * V_4 )
{
T_2 V_24 ;
T_1 V_25 ;
F_5 ( V_26 ,
F_33 ( V_4 -> V_10 . V_27 ) ) ;
F_5 ( V_28 ,
F_34 ( V_4 -> V_10 . V_27 ) ) ;
V_24 = V_29 ;
V_25 = F_35 ( V_4 -> V_10 . V_30 -> V_25 + 4 ) ;
F_5 ( V_31 , V_24 >> 3 ) ;
F_5 ( V_32 , V_25 ) ;
V_24 += V_25 ;
V_25 = V_33 ;
F_5 ( V_34 , V_24 >> 3 ) ;
F_5 ( V_35 , V_25 ) ;
V_24 += V_25 ;
V_25 = V_36 +
( V_37 * V_4 -> V_10 . V_38 ) ;
F_5 ( V_39 , V_24 >> 3 ) ;
F_5 ( V_40 , V_25 ) ;
F_5 ( V_41 , V_4 -> V_42 . V_43 . V_44 ) ;
F_5 ( V_45 , V_4 -> V_42 . V_43 . V_44 ) ;
F_5 ( V_46 , V_4 -> V_42 . V_43 . V_44 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_10 . V_2 ;
T_1 V_47 , V_13 ;
T_1 V_48 ;
T_1 V_49 ;
int V_50 , V_51 , V_9 ;
F_37 ( V_52 , 0 , ~ ( 1 << 2 ) ) ;
V_48 = 0 ;
V_49 = 0 ;
F_32 ( V_4 ) ;
F_37 ( V_53 , 0 , ~ ( 1 << 1 ) ) ;
F_37 ( V_54 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_38 ( 1 ) ;
F_5 ( V_55 , V_56 |
V_57 | V_58 |
V_59 | V_60 |
V_61 | V_62 |
V_63 ) ;
F_38 ( 5 ) ;
F_37 ( V_64 , 0 , ~ V_65 ) ;
F_38 ( 5 ) ;
F_5 ( V_66 , 0x40 | ( 1 << 8 ) | ( 1 << 13 ) |
( 1 << 21 ) | ( 1 << 9 ) | ( 1 << 20 ) ) ;
#ifdef F_39
V_48 = 0xa ;
V_49 = 0 ;
#endif
F_5 ( V_67 , V_48 ) ;
F_5 ( V_68 , V_49 ) ;
F_5 ( V_69 , 0x40c2040 ) ;
F_5 ( V_70 , 0x0 ) ;
F_5 ( V_71 , 0x40c2040 ) ;
F_5 ( V_72 , 0x0 ) ;
F_5 ( V_73 , 0 ) ;
F_5 ( V_74 , 0x88 ) ;
F_5 ( V_55 , V_57 ) ;
F_38 ( 5 ) ;
F_5 ( V_75 , 1 << 9 ) ;
F_37 ( V_54 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_55 , 0 ) ;
F_38 ( 10 ) ;
for ( V_50 = 0 ; V_50 < 10 ; ++ V_50 ) {
T_1 V_76 ;
for ( V_51 = 0 ; V_51 < 100 ; ++ V_51 ) {
V_76 = F_2 ( V_22 ) ;
if ( V_76 & 2 )
break;
F_38 ( 10 ) ;
}
V_9 = 0 ;
if ( V_76 & 2 )
break;
F_23 ( L_4 ) ;
F_37 ( V_55 , V_57 ,
~ V_57 ) ;
F_38 ( 10 ) ;
F_37 ( V_55 , 0 , ~ V_57 ) ;
F_38 ( 10 ) ;
V_9 = - 1 ;
}
if ( V_9 ) {
F_23 ( L_5 ) ;
return V_9 ;
}
F_37 ( V_53 , 3 << 1 , ~ ( 3 << 1 ) ) ;
F_37 ( V_22 , 0 , ~ ( 2 << 1 ) ) ;
V_47 = F_40 ( V_2 -> V_77 ) ;
V_13 = 0 ;
V_13 = F_41 ( V_13 , V_78 , V_79 , V_47 ) ;
V_13 = F_41 ( V_13 , V_78 , V_80 , 1 ) ;
V_13 = F_41 ( V_13 , V_78 , V_81 , 1 ) ;
V_13 = F_41 ( V_13 , V_78 , V_82 , 0 ) ;
V_13 = F_41 ( V_13 , V_78 , V_83 , 1 ) ;
V_13 = F_41 ( V_13 , V_78 , V_84 , 1 ) ;
F_5 ( V_85 , V_13 ) ;
F_5 ( V_86 , 0 ) ;
F_5 ( V_87 , ( F_34 ( V_2 -> V_27 ) >> 2 ) ) ;
F_5 ( V_88 ,
F_33 ( V_2 -> V_27 ) ) ;
F_5 ( V_89 ,
F_34 ( V_2 -> V_27 ) ) ;
F_5 ( V_5 , 0 ) ;
V_2 -> V_7 = F_2 ( V_5 ) ;
F_5 ( V_6 , V_2 -> V_7 ) ;
F_37 ( V_85 , 0 , ~ V_90 ) ;
return 0 ;
}
static void F_29 ( struct V_3 * V_4 )
{
F_5 ( V_85 , 0x11010101 ) ;
F_37 ( V_54 , 1 << 8 , ~ ( 1 << 8 ) ) ;
F_38 ( 1 ) ;
F_5 ( V_55 , V_57 ) ;
F_38 ( 5 ) ;
F_5 ( V_75 , 0x0 ) ;
F_37 ( V_54 , 0 , ~ ( 1 << 8 ) ) ;
F_5 ( V_22 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 , T_3 V_91 , T_3 V_92 ,
unsigned V_93 )
{
F_43 ( V_93 & V_94 ) ;
F_25 ( V_2 , F_24 ( V_95 , 0 ) ) ;
F_25 ( V_2 , V_92 ) ;
F_25 ( V_2 , F_24 ( V_96 , 0 ) ) ;
F_25 ( V_2 , V_91 & 0xffffffff ) ;
F_25 ( V_2 , F_24 ( V_97 , 0 ) ) ;
F_25 ( V_2 , F_34 ( V_91 ) & 0xff ) ;
F_25 ( V_2 , F_24 ( V_98 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_96 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_97 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
F_25 ( V_2 , F_24 ( V_98 , 0 ) ) ;
F_25 ( V_2 , 2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_99 , 0 ) ) ;
F_25 ( V_2 , 0 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_25 ( V_2 , F_24 ( V_100 , 0 ) ) ;
F_25 ( V_2 , 1 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 = 0 ;
unsigned V_50 ;
int V_9 ;
F_5 ( V_95 , 0xCAFEDEAD ) ;
V_9 = F_22 ( V_2 , 3 ) ;
if ( V_9 ) {
F_23 ( L_6 ,
V_2 -> V_101 , V_9 ) ;
return V_9 ;
}
F_25 ( V_2 , F_24 ( V_95 , 0 ) ) ;
F_25 ( V_2 , 0xDEADBEEF ) ;
F_26 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_4 -> V_102 ; V_50 ++ ) {
V_13 = F_2 ( V_95 ) ;
if ( V_13 == 0xDEADBEEF )
break;
F_47 ( 1 ) ;
}
if ( V_50 < V_4 -> V_102 ) {
F_27 ( L_7 ,
V_2 -> V_101 , V_50 ) ;
} else {
F_23 ( L_8 ,
V_2 -> V_101 , V_13 ) ;
V_9 = - V_103 ;
}
return V_9 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
unsigned V_106 , bool V_107 )
{
F_25 ( V_2 , F_24 ( V_108 , 0 ) ) ;
F_25 ( V_2 , F_33 ( V_105 -> V_27 ) ) ;
F_25 ( V_2 , F_24 ( V_109 , 0 ) ) ;
F_25 ( V_2 , F_34 ( V_105 -> V_27 ) ) ;
F_25 ( V_2 , F_24 ( V_110 , 0 ) ) ;
F_25 ( V_2 , V_105 -> V_111 ) ;
}
static bool F_49 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
return ! ( F_2 ( V_112 ) & V_113 ) ;
}
static int F_50 ( void * V_8 )
{
unsigned V_50 ;
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
for ( V_50 = 0 ; V_50 < V_4 -> V_102 ; V_50 ++ ) {
if ( ! ( F_2 ( V_112 ) & V_113 ) )
return 0 ;
}
return - V_114 ;
}
static int F_51 ( void * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
F_29 ( V_4 ) ;
F_37 ( V_64 , V_65 ,
~ V_65 ) ;
F_38 ( 5 ) ;
return F_36 ( V_4 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_115 * V_116 ,
unsigned type ,
enum V_117 V_118 )
{
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_115 * V_116 ,
struct V_119 * V_120 )
{
F_54 ( L_9 ) ;
F_55 ( & V_4 -> V_10 . V_2 ) ;
return 0 ;
}
static void F_56 ( struct V_3 * V_4 , bool V_121 )
{
T_1 V_122 , V_123 , V_124 ;
V_122 = F_2 ( V_125 ) ;
V_123 = F_2 ( V_126 ) ;
V_124 = V_127 |
V_128 |
V_129 |
V_130 |
V_131 ;
if ( V_121 ) {
V_123 |= ( V_132 |
V_133 |
V_134 |
V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 ) ;
if ( V_4 -> V_150 & V_151 )
V_123 |= V_152 ;
V_123 &= ~ V_153 ;
V_122 |= V_124 ;
} else {
V_123 = 0 ;
V_122 = 0 ;
}
F_5 ( V_125 , V_122 ) ;
F_5 ( V_126 , V_123 ) ;
}
static void F_57 ( struct V_3 * V_4 )
{
T_1 V_154 , V_155 ;
V_154 = F_2 ( V_156 ) ;
V_155 = F_2 ( V_157 ) ;
V_154 &= ~ ( V_158 |
V_159 ) ;
V_154 |= V_160 |
( 1 << F_58 ( V_161 , V_162 ) ) |
( 4 << F_58 ( V_161 , V_163 ) ) ;
V_154 &= ~ ( V_164 |
V_165 |
V_166 |
V_167 |
V_168 |
V_169 |
V_170 |
V_171 |
V_172 |
V_173 |
V_174 |
V_175 |
V_176 |
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_182 |
V_183 |
V_184 ) ;
V_155 &= ~ ( V_185 |
V_186 |
V_187 |
V_188 |
V_189 ) ;
F_5 ( V_156 , V_154 ) ;
F_5 ( V_157 , V_155 ) ;
}
static void F_20 ( struct V_3 * V_4 ,
bool V_121 )
{
T_4 V_190 , V_154 ;
if ( V_121 && ( V_4 -> V_191 & V_192 ) ) {
V_154 = F_59 ( V_193 ) ;
V_154 |= 0xfff ;
F_60 ( V_193 , V_154 ) ;
V_190 = V_154 = F_2 ( V_156 ) ;
V_154 |= V_160 ;
if ( V_190 != V_154 )
F_5 ( V_156 , V_154 ) ;
} else {
V_154 = F_59 ( V_193 ) ;
V_154 &= ~ 0xfff ;
F_60 ( V_193 , V_154 ) ;
V_190 = V_154 = F_2 ( V_156 ) ;
V_154 &= ~ V_160 ;
if ( V_190 != V_154 )
F_5 ( V_156 , V_154 ) ;
}
}
static int F_19 ( void * V_8 ,
enum V_194 V_118 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
bool V_121 = ( V_118 == V_23 ) ? true : false ;
if ( V_121 ) {
if ( F_50 ( V_8 ) )
return - V_195 ;
F_56 ( V_4 , true ) ;
} else {
F_56 ( V_4 , false ) ;
}
F_57 ( V_4 ) ;
return 0 ;
}
static int F_61 ( void * V_8 ,
enum V_196 V_118 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_197 = 0 ;
if ( V_118 == V_198 ) {
F_29 ( V_4 ) ;
} else {
V_197 = F_36 ( V_4 ) ;
if ( V_197 )
goto V_199;
}
V_199:
return V_197 ;
}
static void F_62 ( void * V_8 , T_4 * V_93 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 ;
int V_154 ;
F_63 ( & V_4 -> V_200 . V_201 ) ;
if ( F_64 ( V_202 ) &
V_203 ) {
F_27 ( L_10 ) ;
goto V_199;
}
V_154 = F_2 ( V_156 ) ;
if ( V_154 & V_160 )
* V_93 |= V_192 ;
V_199:
F_65 ( & V_4 -> V_200 . V_201 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_2 . V_204 = & V_205 ;
}
static void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_10 . V_11 . V_206 = 1 ;
V_4 -> V_10 . V_11 . V_204 = & V_207 ;
}
