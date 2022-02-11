static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) -> V_7 ;
T_2 V_8 [] = { V_3 , V_4 } ;
int V_9 ;
V_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_1 , V_9 , V_3 ) ;
}
static T_2
F_6 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) -> V_7 ;
T_2 V_4 ;
int V_9 ;
V_9 = F_3 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_7 ( V_6 , & V_4 , sizeof( V_4 ) ) ;
if ( V_9 < 0 )
goto V_11;
return V_4 ;
V_11:
F_5 ( & V_6 -> V_10 , L_2 , V_9 , V_3 ) ;
return 0 ;
}
static void
F_8 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_9 ( V_12 ) != V_14 -> V_15 ) {
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_8 [] = {
V_16 , F_9 (reg)
} ;
int V_9 = F_3 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_3 , V_9 ) ;
V_14 -> V_15 = F_9 ( V_12 ) ;
}
}
static int
F_11 ( struct V_1 * V_2 , T_1 V_12 , char * V_8 , int V_17 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_3 = F_12 ( V_12 ) ;
int V_9 ;
F_8 ( V_2 , V_12 ) ;
V_9 = F_3 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_7 ( V_6 , V_8 , V_17 ) ;
if ( V_9 < 0 )
goto V_11;
return V_9 ;
V_11:
F_5 ( & V_6 -> V_10 , L_4 , V_9 , V_12 ) ;
return V_9 ;
}
static T_2
F_13 ( struct V_1 * V_2 , T_1 V_12 )
{
T_2 V_4 = 0 ;
F_11 ( V_2 , V_12 , & V_4 , sizeof( V_4 ) ) ;
return V_4 ;
}
static void
F_14 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_8 [] = { F_12 ( V_12 ) , V_4 } ;
int V_9 ;
F_8 ( V_2 , V_12 ) ;
V_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_4 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_8 [] = { F_12 ( V_12 ) , V_4 >> 8 , V_4 } ;
int V_9 ;
F_8 ( V_2 , V_12 ) ;
V_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static void
F_16 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
F_14 ( V_2 , V_12 , F_13 ( V_2 , V_12 ) | V_4 ) ;
}
static void
F_17 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
F_14 ( V_2 , V_12 , F_13 ( V_2 , V_12 ) & ~ V_4 ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_18 , V_19 | V_20 ) ;
F_19 ( 50 ) ;
F_17 ( V_2 , V_18 , V_19 | V_20 ) ;
F_19 ( 50 ) ;
F_16 ( V_2 , V_21 , V_22 ) ;
F_17 ( V_2 , V_21 , V_22 ) ;
F_14 ( V_2 , V_23 , 0x00 ) ;
F_14 ( V_2 , V_24 , F_20 ( 1 ) ) ;
F_14 ( V_2 , V_25 , 0x00 ) ;
F_14 ( V_2 , V_26 , 0x00 ) ;
F_14 ( V_2 , V_27 , 0x00 ) ;
F_14 ( V_2 , V_28 , 0x00 ) ;
F_14 ( V_2 , V_29 , 0x03 ) ;
F_14 ( V_2 , V_30 , V_31 | V_32 ) ;
F_14 ( V_2 , V_33 , 0xfa ) ;
F_14 ( V_2 , V_34 , 0x00 ) ;
F_14 ( V_2 , V_35 , 0x5b ) ;
F_14 ( V_2 , V_36 , 0x00 ) ;
F_14 ( V_2 , V_37 , 0x10 ) ;
}
static void
F_21 ( struct V_1 * V_2 , void * V_38 )
{
}
static void
F_22 ( struct V_1 * V_2 , int V_39 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( V_39 != V_40 )
V_39 = V_41 ;
if ( V_39 == V_14 -> V_42 )
return;
switch ( V_39 ) {
case V_40 :
F_14 ( V_2 , V_43 , 0xff ) ;
F_14 ( V_2 , V_44 , 0xff ) ;
F_14 ( V_2 , V_45 , 0xff ) ;
F_14 ( V_2 , V_46 , 0xff ) ;
F_14 ( V_2 , V_47 ,
F_23 ( 2 ) | F_24 ( 3 ) ) ;
F_14 ( V_2 , V_48 ,
F_25 ( 0 ) | F_26 ( 1 ) ) ;
F_14 ( V_2 , V_49 ,
F_27 ( 4 ) | F_28 ( 5 ) ) ;
break;
case V_41 :
F_14 ( V_2 , V_43 , 0x00 ) ;
F_14 ( V_2 , V_44 , 0x00 ) ;
F_14 ( V_2 , V_45 , 0x00 ) ;
F_14 ( V_2 , V_46 , 0x00 ) ;
break;
}
V_14 -> V_42 = V_39 ;
}
static void
F_29 ( struct V_1 * V_2 )
{
F_30 ( L_6 ) ;
}
static void
F_31 ( struct V_1 * V_2 )
{
F_30 ( L_6 ) ;
}
static bool
F_32 ( struct V_1 * V_2 ,
const struct V_50 * V_39 ,
struct V_50 * V_51 )
{
return true ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_50 * V_39 )
{
return V_52 ;
}
static void
F_34 ( struct V_1 * V_2 ,
struct V_50 * V_39 ,
struct V_50 * V_51 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
T_1 V_53 , V_54 , V_55 , V_56 ;
T_1 V_57 , V_58 , V_59 , V_60 ;
T_1 V_61 , V_62 , V_63 ;
T_2 V_12 , div , V_64 ;
V_53 = V_39 -> V_65 - V_39 -> V_66 ;
V_54 = V_39 -> V_67 - V_39 -> V_66 ;
V_55 = 1 ;
V_56 = 1 + V_39 -> V_68 - V_39 -> V_69 ;
V_57 = V_39 -> V_70 - V_39 -> V_69 ;
V_58 = V_57 + V_39 -> V_71 ;
V_59 = V_39 -> V_72 - V_39 -> V_66 ;
V_60 = V_39 -> V_72 ;
V_63 = 0 ;
if ( V_39 -> V_73 & V_74 )
V_63 = ( V_39 -> V_72 / 2 ) + V_53 ;
V_62 = 2 ;
V_61 = 3 + V_53 ;
div = 148500 / V_39 -> clock ;
F_30 ( L_7 , V_39 -> clock , div ) ;
F_30 ( L_8 ,
V_53 , V_54 , V_55 , V_56 ) ;
F_30 ( L_9 ,
V_57 , V_58 , V_59 , V_60 ) ;
F_30 ( L_10 ,
V_62 , V_61 , V_63 ) ;
F_16 ( V_2 , V_75 , V_76 ) ;
F_16 ( V_2 , V_77 , V_78 ) ;
F_17 ( V_2 , V_79 , V_80 ) ;
F_14 ( V_2 , V_81 , F_35 ( 0 ) ) ;
F_14 ( V_2 , V_82 , F_36 ( 0 ) |
F_37 ( 0 ) ) ;
F_14 ( V_2 , V_83 , F_38 ( 0 ) ) ;
F_14 ( V_2 , V_84 , F_39 ( 0 ) |
F_40 ( 0 ) ) ;
F_17 ( V_2 , V_25 , V_85 ) ;
F_17 ( V_2 , V_23 , V_86 ) ;
F_17 ( V_2 , V_25 , V_87 ) ;
F_14 ( V_2 , V_26 , 0 ) ;
F_14 ( V_2 , V_88 , F_41 ( 0 ) ) ;
V_64 = 0 ;
F_14 ( V_2 , V_89 , 0 ) ;
F_14 ( V_2 , V_30 , F_42 ( 0 ) |
V_31 | V_32 ) ;
F_14 ( V_2 , V_24 , F_20 ( div ) |
F_43 ( V_64 ) ) ;
F_15 ( V_2 , V_90 , V_63 ) ;
F_15 ( V_2 , V_91 , V_63 ) ;
F_16 ( V_2 , V_92 , V_93 ) ;
F_14 ( V_2 , V_94 , 0x09 ) ;
F_17 ( V_2 , V_95 , V_96 ) ;
F_14 ( V_2 , V_97 , 0 ) ;
F_16 ( V_2 , V_97 , V_98 ) ;
if ( V_39 -> V_73 & V_99 )
F_16 ( V_2 , V_97 , V_100 ) ;
if ( V_39 -> V_73 & V_101 )
F_16 ( V_2 , V_97 , V_102 ) ;
F_14 ( V_2 , V_103 , 0x00 ) ;
F_15 ( V_2 , V_104 , V_39 -> V_66 - 1 ) ;
F_15 ( V_2 , V_105 , V_39 -> V_71 - 1 ) ;
F_15 ( V_2 , V_106 , V_55 ) ;
F_15 ( V_2 , V_107 , V_56 ) ;
F_15 ( V_2 , V_108 , V_53 ) ;
F_15 ( V_2 , V_109 , V_53 ) ;
F_15 ( V_2 , V_110 , V_53 ) ;
F_15 ( V_2 , V_111 , V_54 ) ;
F_15 ( V_2 , V_112 , V_57 ) ;
F_15 ( V_2 , V_113 , V_58 ) ;
F_15 ( V_2 , V_114 , V_59 ) ;
F_15 ( V_2 , V_115 , V_60 ) ;
if ( V_14 -> V_116 == V_117 ) {
F_14 ( V_2 , V_118 , 0x01 ) ;
}
F_15 ( V_2 , V_119 , V_61 ) ;
F_15 ( V_2 , V_120 , V_62 ) ;
V_12 = V_121 |
V_122 |
V_123 |
V_78 |
V_124 ;
if ( V_39 -> V_73 & ( V_99 | V_101 ) )
V_12 |= V_125 ;
F_16 ( V_2 , V_77 , V_12 ) ;
F_17 ( V_2 , V_95 , V_126 ) ;
}
static enum V_127
F_44 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
T_2 V_4 = F_6 ( V_2 , V_130 ) ;
return ( V_4 & V_131 ) ? V_132 :
V_133 ;
}
static int
F_45 ( struct V_1 * V_2 , T_2 * V_8 , int V_134 )
{
T_2 V_135 , V_136 ;
int V_9 , V_137 ;
F_16 ( V_2 , V_138 , V_139 ) ;
V_135 = ( V_134 & 1 ) ? 128 : 0 ;
V_136 = V_134 / 2 ;
F_14 ( V_2 , V_140 , 0xa0 ) ;
F_14 ( V_2 , V_141 , V_135 ) ;
F_14 ( V_2 , V_142 , 0x60 ) ;
F_14 ( V_2 , V_143 , V_136 ) ;
F_14 ( V_2 , V_144 , 0x1 ) ;
F_14 ( V_2 , V_144 , 0x0 ) ;
for ( V_137 = 100 ; V_137 > 0 ; V_137 -- ) {
T_2 V_4 = F_13 ( V_2 , V_138 ) ;
if ( V_4 & V_139 )
break;
F_19 ( 1 ) ;
}
if ( V_137 == 0 )
return - V_145 ;
V_9 = F_11 ( V_2 , V_146 , V_8 , V_147 ) ;
if ( V_9 != V_147 ) {
F_5 ( V_2 -> V_10 -> V_10 , L_11 ,
V_134 , V_9 ) ;
return V_9 ;
}
F_17 ( V_2 , V_138 , V_139 ) ;
return 0 ;
}
static T_2 *
F_46 ( struct V_1 * V_2 )
{
int V_148 = 0 , V_149 = 0 ;
T_2 * V_150 , * V_151 ;
bool V_152 = V_153 & V_154 ;
if ( ( V_150 = F_47 ( V_147 , V_155 ) ) == NULL )
return NULL ;
if ( F_45 ( V_2 , V_150 , 0 ) )
goto V_11;
if ( ! F_48 ( V_150 , 0 , V_152 ) )
goto V_11;
if ( V_150 [ 0x7e ] == 0 )
return V_150 ;
V_151 = F_49 ( V_150 , ( V_150 [ 0x7e ] + 1 ) * V_147 , V_155 ) ;
if ( ! V_151 )
goto V_11;
V_150 = V_151 ;
for ( V_148 = 1 ; V_148 <= V_150 [ 0x7e ] ; V_148 ++ ) {
T_2 * V_156 = V_150 + ( V_149 + 1 ) * V_147 ;
if ( F_45 ( V_2 , V_156 , V_148 ) )
goto V_11;
if ( ! F_48 ( V_156 , V_148 , V_152 ) )
goto V_11;
V_149 ++ ;
}
if ( V_149 != V_150 [ 0x7e ] ) {
V_150 [ V_147 - 1 ] += V_150 [ 0x7e ] - V_149 ;
V_150 [ 0x7e ] = V_149 ;
V_151 = F_49 ( V_150 , ( V_149 + 1 ) * V_147 , V_155 ) ;
if ( ! V_151 )
goto V_11;
V_150 = V_151 ;
}
return V_150 ;
V_11:
F_50 ( V_2 -> V_10 -> V_10 , L_12 ) ;
F_51 ( V_150 ) ;
return NULL ;
}
static int
F_52 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
struct V_157 * V_157 = (struct V_157 * ) F_46 ( V_2 ) ;
int V_158 = 0 ;
if ( V_157 ) {
F_53 ( V_129 , V_157 ) ;
V_158 = F_54 ( V_129 , V_157 ) ;
F_51 ( V_157 ) ;
}
return V_158 ;
}
static int
F_55 ( struct V_1 * V_2 ,
struct V_128 * V_129 )
{
F_30 ( L_6 ) ;
return 0 ;
}
static int
F_56 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
struct V_159 * V_160 ,
T_3 V_4 )
{
F_30 ( L_6 ) ;
return 0 ;
}
static void
F_57 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
F_58 ( V_2 ) ;
F_51 ( V_14 ) ;
}
static int
F_59 ( struct V_5 * V_6 , const struct V_161 * V_162 )
{
return 0 ;
}
static int
F_60 ( struct V_5 * V_6 )
{
return 0 ;
}
static int
F_61 ( struct V_5 * V_6 ,
struct V_163 * V_10 ,
struct V_164 * V_165 )
{
struct V_1 * V_2 = & V_165 -> V_166 ;
struct V_13 * V_14 ;
V_14 = F_62 ( sizeof( * V_14 ) , V_155 ) ;
if ( ! V_14 )
return - V_167 ;
V_14 -> V_15 = 0 ;
V_14 -> V_7 = F_63 ( V_6 -> V_168 , 0x34 ) ;
V_14 -> V_42 = V_41 ;
V_165 -> V_169 = V_14 ;
V_165 -> V_170 = & V_171 ;
F_1 ( V_2 , V_172 ,
V_173 | V_174 ) ;
F_18 ( V_2 ) ;
V_14 -> V_116 = F_13 ( V_2 , V_175 ) |
F_13 ( V_2 , V_176 ) << 8 ;
V_14 -> V_116 &= ~ 0x30 ;
switch ( V_14 -> V_116 ) {
case V_177 : F_64 ( V_10 -> V_10 , L_13 ) ; break;
case V_178 : F_64 ( V_10 -> V_10 , L_14 ) ; break;
case V_179 : F_64 ( V_10 -> V_10 , L_15 ) ; break;
case V_117 : F_64 ( V_10 -> V_10 , L_16 ) ; break;
default:
F_30 ( L_17 , V_14 -> V_116 ) ;
goto V_11;
}
F_14 ( V_2 , V_180 , 0x00 ) ;
F_14 ( V_2 , V_181 , 39 ) ;
if ( V_14 -> V_116 == V_178 )
F_16 ( V_2 , V_182 , V_183 ) ;
F_1 ( V_2 , V_184 ,
V_185 | V_186 ) ;
return 0 ;
V_11:
if ( V_14 -> V_7 )
F_65 ( V_14 -> V_7 ) ;
F_51 ( V_14 ) ;
V_165 -> V_169 = NULL ;
V_165 -> V_170 = NULL ;
return - V_187 ;
}
static int T_4
F_66 ( void )
{
F_30 ( L_6 ) ;
return F_67 ( V_188 , & V_189 ) ;
}
static void T_5
F_68 ( void )
{
F_30 ( L_6 ) ;
F_69 ( & V_189 ) ;
}
