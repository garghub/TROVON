void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 = F_2 ( V_1 ) ;
F_3 ( ( ( V_4 & ~ V_2 ) | V_3 ) , V_1 ) ;
}
int F_4 ( struct V_5 * V_6 )
{
int V_7 ;
F_5 ( & V_6 -> V_8 ) ;
F_6 ( V_6 ) ;
F_7 ( V_6 ) ;
V_7 = F_8 ( V_6 ) ;
F_9 ( & V_6 -> V_8 ) ;
return V_7 ;
}
static int F_10 ( struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 =
F_11 ( V_10 , struct V_12 , V_10 ) ;
struct V_5 * V_6 = F_12 ( V_13 -> V_14 ) ;
struct V_15 * V_16 = V_13 -> V_16 ;
int V_17 = 0 ;
F_13 ( V_6 , V_13 , & V_17 , V_11 ) ;
if ( V_17 < V_11 ) {
F_14 ( V_10 ) ;
V_16 -> V_2 |= V_13 -> V_18 ;
F_3 ( V_16 -> V_2 , V_6 -> V_19 + V_20 ) ;
}
return V_17 ;
}
static int F_15 ( struct V_21 * V_22 , struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
return F_16 ( V_6 , & V_6 -> V_24 , V_22 ) ;
}
T_3 F_17 ( int V_25 , void * V_4 )
{
struct V_15 * V_16 = V_4 ;
struct V_5 * V_6 =
F_11 ( V_16 , struct V_5 , V_16 ) ;
struct V_12 * V_13 = & V_6 -> V_13 ;
T_2 V_26 , V_27 ;
F_3 ( 0 , V_6 -> V_19 + V_20 ) ;
V_26 = F_18 ( V_6 -> V_19 + V_28 ) ;
V_27 = V_26 & V_16 -> V_2 ;
if ( V_27 == 0 )
goto exit;
if ( V_27 & V_29 ) {
F_19 ( V_6 , V_18 , V_6 -> V_14 ,
L_1 ,
V_27 & V_29 ) ;
F_20 ( & V_6 -> V_30 ) ;
}
if ( V_27 & V_13 -> V_18 ) {
if ( F_21 ( & V_13 -> V_10 ) ) {
V_16 -> V_2 &= ~ V_13 -> V_18 ;
F_22 ( & V_13 -> V_10 ) ;
}
}
if ( V_27 & V_31 )
F_23 ( V_6 , & V_6 -> V_24 ) ;
if ( V_27 & V_32 )
F_24 ( L_2 ) ;
if ( V_27 & V_33 )
F_25 ( V_6 -> V_34 , ! ! ( V_27 & V_35 ) ) ;
exit:
F_3 ( V_16 -> V_2 , V_6 -> V_19 + V_20 ) ;
return V_36 ;
}
static int F_26 ( struct V_23 * V_14 ,
T_4 V_37 )
{
T_4 V_38 = V_37 ^ V_14 -> V_37 ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
if ( ! ( V_38 & ( V_39 | V_40 ) ) )
return 0 ;
if ( ! F_27 ( V_14 ) )
return 0 ;
V_14 -> V_37 = V_37 ;
return F_4 ( V_6 ) ;
}
static void F_28 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
struct V_41 * V_42 ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 (ha, netdev)
F_32 ( V_6 , V_42 -> V_1 ) ;
}
static int F_33 ( struct V_23 * V_14 , int V_43 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_34 ( V_6 , V_44 , V_6 -> V_14 ,
L_3 , V_14 -> V_45 ,
V_43 ) ;
V_14 -> V_45 = V_43 ;
if ( F_27 ( V_14 ) )
return F_4 ( V_6 ) ;
return 0 ;
}
static int F_35 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
int V_7 ;
V_7 = F_36 ( V_6 ) ;
if ( V_7 ) {
F_37 ( V_6 -> V_14 , L_4 ) ;
return V_7 ;
}
V_7 = F_8 ( V_6 ) ;
if ( V_7 ) {
F_38 ( V_6 ) ;
return V_7 ;
}
F_39 ( V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_5 ( & V_6 -> V_8 ) ;
F_6 ( V_6 ) ;
F_38 ( V_6 ) ;
F_9 ( & V_6 -> V_8 ) ;
return 0 ;
}
static void F_41 ( struct V_23 * V_14 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_20 ( & V_6 -> V_30 ) ;
}
static int F_42 ( struct V_23 * V_14 , struct V_46 * V_47 , int V_48 )
{
if ( ! F_27 ( V_14 ) )
return - V_49 ;
if ( ! V_14 -> V_34 )
return - V_50 ;
return F_43 ( V_14 -> V_34 , V_47 , V_48 ) ;
}
static struct V_51 * F_44 ( struct V_23 * V_14 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = F_12 ( V_14 ) ;
unsigned int V_1 = V_53 ;
struct V_54 * V_55 = & V_6 -> V_55 ;
T_5 * V_56 = & V_6 -> V_55 . V_57 ;
T_2 V_3 ;
F_45 ( & V_55 -> V_58 ) ;
while ( V_1 <= V_59 ) {
V_3 = F_18 ( V_6 -> V_19 + V_1 ) ;
* V_56 += V_3 ;
V_56 ++ ;
V_1 += sizeof( T_2 ) ;
}
V_3 = F_18 ( V_6 -> V_19 + V_60 ) ;
V_6 -> V_55 . V_61 += V_3 ;
V_3 = F_18 ( V_6 -> V_19 + V_62 ) ;
V_6 -> V_55 . V_63 += V_3 ;
V_1 = V_64 ;
V_56 = & V_6 -> V_55 . V_65 ;
while ( V_1 <= V_66 ) {
V_3 = F_18 ( V_6 -> V_19 + V_1 ) ;
* V_56 += V_3 ;
++ V_56 ;
V_1 += sizeof( T_2 ) ;
}
V_3 = F_18 ( V_6 -> V_19 + V_67 ) ;
V_6 -> V_55 . V_68 += V_3 ;
V_52 -> V_69 = V_55 -> V_57 ;
V_52 -> V_70 = V_55 -> V_65 ;
V_52 -> V_71 = V_55 -> V_72 ;
V_52 -> V_73 = V_55 -> V_74 ;
V_52 -> V_75 = V_55 -> V_76 ;
V_52 -> V_77 = V_55 -> V_78 + V_55 -> V_79 * 2 +
V_55 -> V_80 + V_55 -> V_81 ;
V_52 -> V_82 = V_55 -> V_83 + V_55 -> V_84 +
V_55 -> V_85 + V_55 -> V_86 +
V_55 -> V_87 ;
V_52 -> V_88 = V_55 -> V_89 ;
V_52 -> V_90 = V_55 -> V_85 ;
V_52 -> V_91 = V_55 -> V_84 ;
V_52 -> V_92 = V_55 -> V_87 ;
V_52 -> V_93 = V_55 -> V_89 ;
V_52 -> V_94 = V_55 -> V_89 ;
V_52 -> V_95 = V_55 -> V_80 + V_55 -> V_81 +
V_55 -> V_96 + V_55 -> V_97 ;
V_52 -> V_98 = V_55 -> V_96 ;
V_52 -> V_99 = V_55 -> V_81 ;
V_52 -> V_100 = V_55 -> V_80 ;
F_46 ( & V_55 -> V_58 ) ;
return V_52 ;
}
static void F_47 ( struct V_101 * V_102 )
{
struct V_5 * V_6 =
F_11 ( V_102 , struct V_5 , V_30 ) ;
F_4 ( V_6 ) ;
}
static void F_48 ( struct V_5 * V_6 )
{
T_2 V_103 ;
V_6 -> V_104 = V_105 ;
V_6 -> V_106 = V_107 ;
V_6 -> V_108 = V_109 ;
V_6 -> V_110 = V_111 ;
V_6 -> V_112 = V_113 ;
V_6 -> V_114 = V_115 ;
V_6 -> V_116 = V_117 ;
V_6 -> V_118 = V_119 ;
V_6 -> V_120 = V_121 ;
V_103 = ( ( V_122 >> 1 ) << V_123 ) |
( ( V_124 >> 1 ) << V_125 ) ;
V_6 -> V_126 = V_103 ;
V_6 -> V_127 = V_128 ;
}
static int F_49 ( struct V_129 * V_130 ,
struct V_5 * V_6 )
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
struct V_133 * V_133 = F_50 ( & V_130 -> V_134 , V_135 [ V_131 ] ) ;
if ( F_51 ( V_133 ) ) {
F_52 ( & V_130 -> V_134 ,
L_5 ,
V_135 [ V_131 ] , F_53 ( V_133 ) ) ;
return F_53 ( V_133 ) ;
}
V_6 -> V_133 [ V_131 ] = V_133 ;
}
return 0 ;
}
static int F_54 ( struct V_129 * V_130 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( F_55 ( & V_130 -> V_134 ) )
return 0 ;
V_7 = F_49 ( V_130 , V_6 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_133 [ V_136 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_133 [ V_137 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_133 [ V_138 ] , 19200000 ) ;
if ( V_7 )
return V_7 ;
return F_56 ( V_6 -> V_133 [ V_138 ] ) ;
}
static int F_58 ( struct V_129 * V_130 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( F_55 ( & V_130 -> V_134 ) )
return 0 ;
V_7 = F_57 ( V_6 -> V_133 [ V_139 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_133 [ V_139 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_133 [ V_138 ] , 125000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_57 ( V_6 -> V_133 [ V_140 ] , 25000000 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_133 [ V_140 ] ) ;
if ( V_7 )
return V_7 ;
V_7 = F_56 ( V_6 -> V_133 [ V_141 ] ) ;
if ( V_7 )
return V_7 ;
return F_56 ( V_6 -> V_133 [ V_142 ] ) ;
}
static void F_59 ( struct V_5 * V_6 )
{
unsigned int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ )
F_60 ( V_6 -> V_133 [ V_131 ] ) ;
}
static int F_61 ( struct V_129 * V_130 ,
struct V_5 * V_6 )
{
struct V_23 * V_14 = V_6 -> V_14 ;
struct V_143 * V_144 ;
char V_145 [ V_146 ] ;
int V_7 = 0 ;
if ( F_62 ( & V_130 -> V_134 , V_145 , V_146 ) )
F_63 ( V_14 -> V_147 , V_145 ) ;
else
F_64 ( V_14 ) ;
V_7 = F_65 ( V_130 , 0 ) ;
if ( V_7 < 0 ) {
F_52 ( & V_130 -> V_134 ,
L_6 , V_7 ) ;
return V_7 ;
}
V_6 -> V_16 . V_16 = V_7 ;
V_144 = F_66 ( V_130 , V_148 , 0 ) ;
V_6 -> V_19 = F_67 ( & V_130 -> V_134 , V_144 ) ;
if ( F_51 ( V_6 -> V_19 ) )
return F_53 ( V_6 -> V_19 ) ;
V_144 = F_66 ( V_130 , V_148 , 1 ) ;
V_6 -> V_149 = F_67 ( & V_130 -> V_134 , V_144 ) ;
if ( F_51 ( V_6 -> V_149 ) )
return F_53 ( V_6 -> V_149 ) ;
V_14 -> V_150 = ( unsigned long ) V_6 -> V_19 ;
return 0 ;
}
static int F_68 ( struct V_129 * V_130 )
{
struct V_23 * V_14 ;
struct V_5 * V_6 ;
struct V_151 * V_152 ;
T_6 V_153 , V_154 ;
T_2 V_103 ;
int V_7 ;
V_7 = F_69 ( & V_130 -> V_134 , F_70 ( 64 ) ) ;
if ( V_7 ) {
V_7 = F_69 ( & V_130 -> V_134 , F_70 ( 32 ) ) ;
if ( V_7 ) {
F_52 ( & V_130 -> V_134 , L_7 ) ;
return V_7 ;
}
}
V_14 = F_71 ( sizeof( struct V_5 ) ) ;
if ( ! V_14 )
return - V_155 ;
F_72 ( & V_130 -> V_134 , V_14 ) ;
F_73 ( V_14 , & V_130 -> V_134 ) ;
V_6 = F_12 ( V_14 ) ;
V_6 -> V_14 = V_14 ;
V_6 -> V_156 = V_157 ;
V_152 = & V_6 -> V_152 ;
F_74 ( & V_6 -> V_8 ) ;
F_75 ( & V_6 -> V_55 . V_58 ) ;
V_6 -> V_16 . V_2 = V_158 | V_159 ;
V_7 = F_61 ( V_130 , V_6 ) ;
if ( V_7 )
goto V_160;
V_7 = F_54 ( V_130 , V_6 ) ;
if ( V_7 ) {
F_52 ( & V_130 -> V_134 , L_8 ) ;
goto V_160;
}
V_14 -> V_161 = V_162 ;
V_14 -> V_16 = V_6 -> V_16 . V_16 ;
V_6 -> V_163 = V_164 ;
V_6 -> V_165 = V_166 ;
V_6 -> V_167 = V_168 ;
V_14 -> V_169 = & V_170 ;
F_48 ( V_6 ) ;
V_7 = F_76 ( V_130 , V_6 ) ;
if ( V_7 )
goto V_171;
V_7 = F_77 ( V_130 , V_6 ) ;
if ( V_7 )
goto V_172;
V_7 = F_58 ( V_130 , V_6 ) ;
if ( V_7 ) {
F_52 ( & V_130 -> V_134 , L_8 ) ;
goto V_172;
}
F_78 ( V_6 ) ;
V_14 -> V_37 = V_173 | V_174 | V_175 |
V_176 | V_177 | V_40 |
V_39 ;
V_14 -> V_178 = V_14 -> V_37 ;
V_14 -> V_179 |= V_173 | V_174 |
V_176 | V_177 ;
V_14 -> V_180 = V_181 -
( V_182 + V_183 + V_184 ) ;
V_14 -> V_185 = V_186 -
( V_182 + V_183 + V_184 ) ;
F_79 ( & V_6 -> V_30 , F_47 ) ;
F_80 ( V_130 , V_6 ) ;
F_81 ( V_14 , & V_6 -> V_13 . V_10 , F_10 ,
V_187 ) ;
V_7 = F_82 ( V_14 ) ;
if ( V_7 ) {
F_52 ( & V_130 -> V_134 , L_9 ) ;
goto V_188;
}
V_103 = F_18 ( V_6 -> V_19 + V_189 ) ;
V_153 = ( V_103 & V_190 ) >> V_191 ;
V_154 = ( V_103 & V_192 ) >> V_193 ;
V_103 = F_18 ( V_6 -> V_19 + V_194 ) ;
F_34 ( V_6 , V_195 , V_14 ,
L_10 ,
V_153 , V_154 ,
( V_103 & V_196 ) >> V_197 ,
( V_103 & V_198 ) >> V_199 ,
( V_103 & V_200 ) >> V_201 ) ;
return 0 ;
V_188:
F_83 ( & V_6 -> V_13 . V_10 ) ;
V_172:
F_84 ( & V_6 -> V_34 -> V_202 . V_134 ) ;
F_85 ( V_6 -> V_203 ) ;
V_171:
F_59 ( V_6 ) ;
V_160:
F_86 ( V_14 ) ;
return V_7 ;
}
static int F_87 ( struct V_129 * V_130 )
{
struct V_23 * V_14 = F_88 ( & V_130 -> V_134 ) ;
struct V_5 * V_6 = F_12 ( V_14 ) ;
F_89 ( V_14 ) ;
F_83 ( & V_6 -> V_13 . V_10 ) ;
F_59 ( V_6 ) ;
F_84 ( & V_6 -> V_34 -> V_202 . V_134 ) ;
F_85 ( V_6 -> V_203 ) ;
F_86 ( V_14 ) ;
if ( V_6 -> V_152 . V_204 )
F_90 ( V_6 -> V_152 . V_204 ) ;
F_90 ( V_6 -> V_152 . V_19 ) ;
return 0 ;
}
