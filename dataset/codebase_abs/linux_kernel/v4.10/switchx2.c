static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
char * V_5 = F_2 ( V_2 , V_6 ) ;
bool V_7 = V_4 -> V_7 ;
memset ( V_5 , 0 , V_6 ) ;
F_3 ( V_5 , V_8 ) ;
F_4 ( V_5 , V_9 ) ;
F_5 ( V_5 , V_10 ) ;
F_6 ( V_5 , V_7 ? V_11 :
V_12 ) ;
F_7 ( V_5 , 0 ) ;
F_8 ( V_5 , V_4 -> V_13 ) ;
F_9 ( V_5 , V_14 ) ;
F_10 ( V_5 , V_7 ? V_15 :
V_16 ) ;
F_11 ( V_5 , V_17 ) ;
F_12 ( V_5 , V_18 ) ;
F_13 ( V_5 , V_19 ) ;
F_14 ( V_5 , V_7 ? V_20 :
V_21 ) ;
F_15 ( V_5 , V_22 ) ;
}
static int F_16 ( struct V_23 * V_23 ,
bool V_24 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_26 [ V_27 ] ;
F_17 ( V_26 , V_23 -> V_13 ,
V_24 ? V_28 :
V_29 ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_31 ) , V_26 ) ;
}
static int F_20 ( struct V_23 * V_23 ,
bool * V_32 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_26 [ V_27 ] ;
T_1 V_33 ;
int V_34 ;
F_17 ( V_26 , V_23 -> V_13 , 0 ) ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_31 ) , V_26 ) ;
if ( V_34 )
return V_34 ;
V_33 = F_22 ( V_26 ) ;
* V_32 = V_33 == V_28 ? true : false ;
return 0 ;
}
static int F_23 ( struct V_23 * V_23 ,
T_2 V_35 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_36 [ V_37 ] ;
int V_38 ;
int V_34 ;
F_24 ( V_36 , V_23 -> V_13 , 0 ) ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_39 ) , V_36 ) ;
if ( V_34 )
return V_34 ;
V_38 = F_25 ( V_36 ) ;
if ( V_35 > V_38 )
return - V_40 ;
F_24 ( V_36 , V_23 -> V_13 , V_35 ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_39 ) , V_36 ) ;
}
static int F_26 ( struct V_23 * V_23 ,
T_2 V_35 )
{
V_35 += V_6 + V_41 ;
return F_23 ( V_23 , V_35 ) ;
}
static int F_27 ( struct V_23 * V_23 ,
T_2 V_35 )
{
return F_23 ( V_23 , V_35 ) ;
}
static int F_28 ( struct V_23 * V_23 ,
T_1 V_42 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_43 [ V_44 ] = { 0 } ;
int V_34 ;
F_29 ( V_43 , V_23 -> V_13 ) ;
F_30 ( V_43 , V_42 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_45 ) , V_43 ) ;
return V_34 ;
}
static int F_31 ( struct V_23 * V_23 , T_1 V_46 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_47 [ V_48 ] ;
F_32 ( V_47 , V_46 , V_23 -> V_13 ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_49 ) , V_47 ) ;
}
static int
F_33 ( struct V_23 * V_23 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_50 [ V_51 ] ;
F_34 ( V_50 , V_23 -> V_13 ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_52 ) , V_50 ) ;
}
static int F_35 ( struct V_25 * V_25 ,
T_1 V_13 , T_1 * V_53 ,
T_1 * V_54 )
{
char V_55 [ V_56 ] ;
int V_34 ;
F_36 ( V_55 , V_13 ) ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_57 ) , V_55 ) ;
if ( V_34 )
return V_34 ;
* V_53 = F_37 ( V_55 , 0 ) ;
* V_54 = F_38 ( V_55 ) ;
return 0 ;
}
static int F_39 ( struct V_58 * V_59 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
int V_34 ;
V_34 = F_16 ( V_23 , true ) ;
if ( V_34 )
return V_34 ;
F_41 ( V_59 ) ;
return 0 ;
}
static int F_42 ( struct V_58 * V_59 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
F_43 ( V_59 ) ;
return F_16 ( V_23 , false ) ;
}
static T_3 F_44 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
struct V_25 * V_25 = V_23 -> V_25 ;
struct V_60 * V_61 ;
const struct V_3 V_4 = {
. V_13 = V_23 -> V_13 ,
. V_7 = false ,
} ;
T_4 V_62 ;
int V_34 ;
if ( F_45 ( V_25 -> V_30 , & V_4 ) )
return V_63 ;
if ( F_46 ( F_47 ( V_2 ) < V_6 ) ) {
struct V_1 * V_64 = V_2 ;
V_2 = F_48 ( V_2 , V_6 ) ;
if ( ! V_2 ) {
F_49 ( V_23 -> V_61 -> V_65 ) ;
F_50 ( V_64 ) ;
return V_66 ;
}
F_51 ( V_64 ) ;
}
F_1 ( V_2 , & V_4 ) ;
V_62 = V_2 -> V_62 - V_6 ;
V_34 = F_52 ( V_25 -> V_30 , V_2 , & V_4 ) ;
if ( ! V_34 ) {
V_61 = F_53 ( V_23 -> V_61 ) ;
F_54 ( & V_61 -> V_67 ) ;
V_61 -> V_68 ++ ;
V_61 -> V_69 += V_62 ;
F_55 ( & V_61 -> V_67 ) ;
} else {
F_49 ( V_23 -> V_61 -> V_65 ) ;
F_50 ( V_2 ) ;
}
return V_66 ;
}
static int F_56 ( struct V_58 * V_59 , int V_35 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
int V_34 ;
V_34 = F_26 ( V_23 , V_35 ) ;
if ( V_34 )
return V_34 ;
V_59 -> V_35 = V_35 ;
return 0 ;
}
static struct V_70 *
F_57 ( struct V_58 * V_59 ,
struct V_70 * V_71 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
struct V_60 * V_72 ;
T_4 V_73 , V_74 , V_68 , V_69 ;
T_5 V_65 = 0 ;
unsigned int V_75 ;
int V_76 ;
F_58 (i) {
V_72 = F_59 ( V_23 -> V_61 , V_76 ) ;
do {
V_75 = F_60 ( & V_72 -> V_67 ) ;
V_73 = V_72 -> V_73 ;
V_74 = V_72 -> V_74 ;
V_68 = V_72 -> V_68 ;
V_69 = V_72 -> V_69 ;
} while ( F_61 ( & V_72 -> V_67 , V_75 ) );
V_71 -> V_73 += V_73 ;
V_71 -> V_74 += V_74 ;
V_71 -> V_68 += V_68 ;
V_71 -> V_69 += V_69 ;
V_65 += V_72 -> V_65 ;
}
V_71 -> V_65 = V_65 ;
return V_71 ;
}
static int F_62 ( struct V_58 * V_59 , char * V_77 ,
T_6 V_62 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
int V_34 ;
V_34 = snprintf ( V_77 , V_62 , L_1 , V_23 -> V_78 . V_79 + 1 ) ;
if ( V_34 >= V_62 )
return - V_40 ;
return 0 ;
}
static void F_63 ( struct V_58 * V_59 ,
struct V_80 * V_81 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
struct V_25 * V_25 = V_23 -> V_25 ;
F_64 ( V_81 -> V_82 , V_83 , sizeof( V_81 -> V_82 ) ) ;
F_64 ( V_81 -> V_84 , V_85 ,
sizeof( V_81 -> V_84 ) ) ;
snprintf ( V_81 -> V_86 , sizeof( V_81 -> V_86 ) ,
L_2 ,
V_25 -> V_87 -> V_88 . V_89 ,
V_25 -> V_87 -> V_88 . V_90 ,
V_25 -> V_87 -> V_88 . V_91 ) ;
F_64 ( V_81 -> V_87 , V_25 -> V_87 -> V_92 ,
sizeof( V_81 -> V_87 ) ) ;
}
static void F_65 ( struct V_58 * V_59 ,
T_5 V_93 , T_1 * V_94 )
{
T_1 * V_72 = V_94 ;
int V_76 ;
switch ( V_93 ) {
case V_95 :
for ( V_76 = 0 ; V_76 < V_96 ; V_76 ++ ) {
memcpy ( V_72 , V_97 [ V_76 ] . V_98 ,
V_99 ) ;
V_72 += V_99 ;
}
break;
}
}
static void F_66 ( struct V_58 * V_59 ,
struct V_100 * V_71 , T_4 * V_94 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
struct V_25 * V_25 = V_23 -> V_25 ;
char V_101 [ V_102 ] ;
int V_76 ;
int V_34 ;
F_67 ( V_101 , V_23 -> V_13 ,
V_103 , 0 ) ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_104 ) , V_101 ) ;
for ( V_76 = 0 ; V_76 < V_96 ; V_76 ++ )
V_94 [ V_76 ] = ! V_34 ? V_97 [ V_76 ] . F_68 ( V_101 ) : 0 ;
}
static int F_69 ( struct V_58 * V_59 , int V_105 )
{
switch ( V_105 ) {
case V_95 :
return V_96 ;
default:
return - V_106 ;
}
}
static T_5 F_70 ( T_5 V_107 )
{
if ( V_107 & ( V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 ) )
return V_114 ;
if ( V_107 & ( V_115 |
V_116 |
V_117 |
V_118 |
V_119 ) )
return V_120 ;
return 0 ;
}
static T_5 F_71 ( T_5 V_107 )
{
T_5 V_121 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_122 ; V_76 ++ ) {
if ( V_107 & V_123 [ V_76 ] . V_124 )
V_121 |= V_123 [ V_76 ] . V_125 ;
}
return V_121 ;
}
static T_5 F_72 ( T_5 V_107 )
{
T_5 V_121 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_122 ; V_76 ++ ) {
if ( V_107 & V_123 [ V_76 ] . V_124 )
V_121 |= V_123 [ V_76 ] . V_126 ;
}
return V_121 ;
}
static void F_73 ( bool V_127 , T_5 V_107 ,
struct V_128 * V_129 )
{
T_5 V_130 = V_131 ;
T_1 V_132 = V_133 ;
int V_76 ;
if ( ! V_127 )
goto V_134;
for ( V_76 = 0 ; V_76 < V_122 ; V_76 ++ ) {
if ( V_107 & V_123 [ V_76 ] . V_124 ) {
V_130 = V_123 [ V_76 ] . V_130 ;
V_132 = V_135 ;
break;
}
}
V_134:
F_74 ( V_129 , V_130 ) ;
V_129 -> V_132 = V_132 ;
}
static T_1 F_75 ( T_5 V_107 )
{
if ( V_107 & ( V_109 |
V_111 |
V_112 |
V_113 ) )
return V_136 ;
if ( V_107 & ( V_108 |
V_110 |
V_137 ) )
return V_138 ;
if ( V_107 & ( V_115 |
V_116 |
V_117 |
V_118 ) )
return V_139 ;
return V_140 ;
}
static int F_76 ( struct V_58 * V_59 ,
struct V_128 * V_129 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
struct V_25 * V_25 = V_23 -> V_25 ;
char V_141 [ V_142 ] ;
T_5 V_143 ;
T_5 V_144 ;
T_5 V_145 ;
int V_34 ;
F_77 ( V_141 , V_23 -> V_13 , 0 ) ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_146 ) , V_141 ) ;
if ( V_34 ) {
F_78 ( V_59 , L_3 ) ;
return V_34 ;
}
F_79 ( V_141 , & V_143 ,
& V_144 , & V_145 ) ;
V_129 -> V_125 = F_70 ( V_143 ) |
F_71 ( V_143 ) |
V_147 | V_148 ;
V_129 -> V_149 = F_72 ( V_144 ) ;
F_73 ( F_80 ( V_59 ) ,
V_145 , V_129 ) ;
V_145 = V_145 ? V_145 : V_143 ;
V_129 -> V_150 = F_75 ( V_145 ) ;
V_129 -> V_151 = F_72 ( V_145 ) ;
V_129 -> V_152 = V_153 ;
return 0 ;
}
static T_5 F_81 ( T_5 V_149 )
{
T_5 V_154 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_122 ; V_76 ++ ) {
if ( V_149 & V_123 [ V_76 ] . V_126 )
V_154 |= V_123 [ V_76 ] . V_124 ;
}
return V_154 ;
}
static T_5 F_82 ( T_5 V_130 )
{
T_5 V_154 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_122 ; V_76 ++ ) {
if ( V_130 == V_123 [ V_76 ] . V_130 )
V_154 |= V_123 [ V_76 ] . V_124 ;
}
return V_154 ;
}
static T_5 F_83 ( T_5 V_155 )
{
T_5 V_154 = 0 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_122 ; V_76 ++ ) {
if ( V_123 [ V_76 ] . V_130 <= V_155 )
V_154 |= V_123 [ V_76 ] . V_124 ;
}
return V_154 ;
}
static int F_84 ( struct V_58 * V_59 ,
struct V_128 * V_129 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
struct V_25 * V_25 = V_23 -> V_25 ;
char V_141 [ V_142 ] ;
T_5 V_130 ;
T_5 V_156 ;
T_5 V_143 ;
T_5 V_144 ;
bool V_24 ;
int V_34 ;
V_130 = F_85 ( V_129 ) ;
V_156 = V_129 -> V_157 == V_158 ?
F_81 ( V_129 -> V_149 ) :
F_82 ( V_130 ) ;
F_77 ( V_141 , V_23 -> V_13 , 0 ) ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_146 ) , V_141 ) ;
if ( V_34 ) {
F_78 ( V_59 , L_3 ) ;
return V_34 ;
}
F_79 ( V_141 , & V_143 , & V_144 ,
NULL ) ;
V_156 = V_156 & V_143 ;
if ( ! V_156 ) {
F_78 ( V_59 , L_4 ) ;
return - V_40 ;
}
if ( V_156 == V_144 )
return 0 ;
F_77 ( V_141 , V_23 -> V_13 ,
V_156 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_146 ) , V_141 ) ;
if ( V_34 ) {
F_78 ( V_59 , L_5 ) ;
return V_34 ;
}
V_34 = F_20 ( V_23 , & V_24 ) ;
if ( V_34 ) {
F_78 ( V_59 , L_6 ) ;
return V_34 ;
}
if ( ! V_24 )
return 0 ;
V_34 = F_16 ( V_23 , false ) ;
if ( V_34 ) {
F_78 ( V_59 , L_7 ) ;
return V_34 ;
}
V_34 = F_16 ( V_23 , true ) ;
if ( V_34 ) {
F_78 ( V_59 , L_7 ) ;
return V_34 ;
}
return 0 ;
}
static int F_86 ( struct V_58 * V_59 ,
struct V_159 * V_160 )
{
struct V_23 * V_23 = F_40 ( V_59 ) ;
struct V_25 * V_25 = V_23 -> V_25 ;
switch ( V_160 -> V_161 ) {
case V_162 :
V_160 -> V_163 . V_164 . V_165 = sizeof( V_25 -> V_166 ) ;
memcpy ( & V_160 -> V_163 . V_164 . V_161 , & V_25 -> V_166 , V_160 -> V_163 . V_164 . V_165 ) ;
break;
default:
return - V_106 ;
}
return 0 ;
}
static int F_87 ( struct V_25 * V_25 )
{
char V_167 [ V_168 ] = { 0 } ;
int V_34 ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_169 ) , V_167 ) ;
if ( V_34 )
return V_34 ;
F_88 ( V_167 , V_25 -> V_166 ) ;
return 0 ;
}
static int F_89 ( struct V_23 * V_23 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
struct V_58 * V_59 = V_23 -> V_59 ;
char V_170 [ V_171 ] ;
int V_34 ;
F_90 ( V_170 , false , 0 ) ;
V_34 = F_21 ( V_25 -> V_30 , F_19 ( V_172 ) , V_170 ) ;
if ( V_34 )
return V_34 ;
F_91 ( V_170 , V_59 -> V_173 ) ;
V_59 -> V_173 [ V_174 - 1 ] += V_23 -> V_13 ;
return 0 ;
}
static int F_92 ( struct V_23 * V_23 ,
T_2 V_175 , enum V_176 V_177 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char * V_178 ;
int V_34 ;
V_178 = F_93 ( V_179 , V_180 ) ;
if ( ! V_178 )
return - V_181 ;
F_94 ( V_178 , V_23 -> V_13 ) ;
F_95 ( V_178 , V_175 , V_177 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_182 ) , V_178 ) ;
F_96 ( V_178 ) ;
return V_34 ;
}
static int F_97 ( struct V_23 * V_23 ,
T_2 V_130 , T_2 V_183 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_141 [ V_142 ] ;
F_98 ( V_141 , V_23 -> V_13 , V_130 ,
V_183 ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_146 ) , V_141 ) ;
}
static int
F_99 ( struct V_23 * V_23 , T_1 V_183 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
T_5 V_155 = V_184 * V_183 ;
char V_141 [ V_142 ] ;
T_5 V_144 ;
V_144 = F_83 ( V_155 ) ;
F_77 ( V_141 , V_23 -> V_13 ,
V_144 ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_146 ) , V_141 ) ;
}
static int
F_100 ( struct V_23 * V_23 ,
enum V_185 V_186 )
{
struct V_25 * V_25 = V_23 -> V_25 ;
char V_187 [ V_188 ] ;
F_101 ( V_187 , V_23 -> V_13 , V_186 ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_189 ) , V_187 ) ;
}
static int F_102 ( struct V_25 * V_25 , T_1 V_13 ,
T_1 V_79 , T_1 V_183 )
{
struct V_23 * V_23 ;
struct V_58 * V_59 ;
int V_34 ;
V_59 = F_103 ( sizeof( struct V_23 ) ) ;
if ( ! V_59 )
return - V_181 ;
F_104 ( V_59 , V_25 -> V_87 -> V_59 ) ;
V_23 = F_40 ( V_59 ) ;
V_23 -> V_59 = V_59 ;
V_23 -> V_25 = V_25 ;
V_23 -> V_13 = V_13 ;
V_23 -> V_78 . V_79 = V_79 ;
V_23 -> V_61 =
F_105 ( struct V_60 ) ;
if ( ! V_23 -> V_61 ) {
V_34 = - V_181 ;
goto V_190;
}
V_59 -> V_191 = & V_192 ;
V_59 -> V_193 = & V_194 ;
V_59 -> V_195 = & V_196 ;
V_34 = F_89 ( V_23 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_8 ,
V_23 -> V_13 ) ;
goto V_197;
}
F_107 ( V_59 ) ;
V_59 -> V_198 |= V_199 | V_200 | V_201 |
V_202 ;
V_59 -> V_203 = 0 ;
V_59 -> V_38 = V_204 ;
V_59 -> V_205 = V_6 ;
V_34 = F_33 ( V_23 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_9 ,
V_23 -> V_13 ) ;
goto V_206;
}
V_34 = F_31 ( V_23 , 0 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_10 ,
V_23 -> V_13 ) ;
goto V_207;
}
V_34 = F_99 ( V_23 , V_183 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_11 ,
V_23 -> V_13 ) ;
goto V_208;
}
V_34 = F_26 ( V_23 , V_209 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_12 ,
V_23 -> V_13 ) ;
goto V_210;
}
V_34 = F_16 ( V_23 , false ) ;
if ( V_34 )
goto V_211;
V_34 = F_92 ( V_23 ,
V_212 ,
V_213 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_13 ,
V_23 -> V_13 ) ;
goto V_214;
}
V_34 = F_100 ( V_23 ,
V_215 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_14 ,
V_23 -> V_13 ) ;
goto V_216;
}
V_34 = F_108 ( V_59 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_15 ,
V_23 -> V_13 ) ;
goto V_217;
}
F_109 ( V_25 -> V_30 , V_23 -> V_13 ,
V_23 , V_59 , false , 0 ) ;
V_25 -> V_218 [ V_13 ] = V_23 ;
return 0 ;
V_217:
V_216:
V_214:
V_211:
V_210:
V_208:
F_31 ( V_23 , V_219 ) ;
V_207:
V_206:
V_197:
F_110 ( V_23 -> V_61 ) ;
V_190:
F_111 ( V_59 ) ;
return V_34 ;
}
static int F_112 ( struct V_25 * V_25 , T_1 V_13 ,
T_1 V_79 , T_1 V_183 )
{
int V_34 ;
V_34 = F_113 ( V_25 -> V_30 , V_13 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_16 ,
V_13 ) ;
return V_34 ;
}
V_34 = F_102 ( V_25 , V_13 , V_79 , V_183 ) ;
if ( V_34 )
goto V_220;
return 0 ;
V_220:
F_114 ( V_25 -> V_30 , V_13 ) ;
return V_34 ;
}
static void F_115 ( struct V_25 * V_25 , T_1 V_13 )
{
struct V_23 * V_23 = V_25 -> V_218 [ V_13 ] ;
F_116 ( V_25 -> V_30 , V_13 , V_25 ) ;
F_117 ( V_23 -> V_59 ) ;
V_25 -> V_218 [ V_13 ] = NULL ;
F_31 ( V_23 , V_219 ) ;
F_110 ( V_23 -> V_61 ) ;
F_111 ( V_23 -> V_59 ) ;
}
static bool F_118 ( struct V_25 * V_25 , T_1 V_13 )
{
return V_25 -> V_218 [ V_13 ] != NULL ;
}
static int F_119 ( struct V_25 * V_25 , T_1 V_13 ,
T_1 V_79 , T_1 V_183 )
{
struct V_23 * V_23 ;
int V_34 ;
V_23 = F_120 ( sizeof( * V_23 ) , V_180 ) ;
if ( ! V_23 )
return - V_181 ;
V_23 -> V_25 = V_25 ;
V_23 -> V_13 = V_13 ;
V_23 -> V_78 . V_79 = V_79 ;
V_34 = F_33 ( V_23 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_9 ,
V_23 -> V_13 ) ;
goto V_206;
}
V_34 = F_31 ( V_23 , 1 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_10 ,
V_23 -> V_13 ) ;
goto V_207;
}
V_34 = F_28 ( V_23 , V_79 + 1 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_17 ,
V_23 -> V_13 ) ;
goto V_221;
}
V_34 = F_97 ( V_23 ,
V_222 - 1 ,
F_121 ( 3 ) - 1 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_11 ,
V_23 -> V_13 ) ;
goto V_208;
}
V_34 = F_27 ( V_23 , V_223 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_12 ,
V_23 -> V_13 ) ;
goto V_210;
}
V_34 = F_16 ( V_23 , true ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_18 ,
V_23 -> V_13 ) ;
goto V_224;
}
F_122 ( V_25 -> V_30 , V_23 -> V_13 ,
V_23 ) ;
V_25 -> V_218 [ V_13 ] = V_23 ;
return 0 ;
V_224:
V_210:
V_208:
V_221:
F_31 ( V_23 , V_219 ) ;
V_207:
V_206:
F_96 ( V_23 ) ;
return V_34 ;
}
static void F_123 ( struct V_25 * V_25 , T_1 V_13 )
{
struct V_23 * V_23 = V_25 -> V_218 [ V_13 ] ;
F_116 ( V_25 -> V_30 , V_13 , V_25 ) ;
V_25 -> V_218 [ V_13 ] = NULL ;
F_16 ( V_23 , false ) ;
F_31 ( V_23 , V_219 ) ;
F_96 ( V_23 ) ;
}
static void F_124 ( struct V_25 * V_25 , T_1 V_13 )
{
enum V_225 V_226 =
F_125 ( V_25 -> V_30 , V_13 ) ;
if ( V_226 == V_227 )
F_115 ( V_25 , V_13 ) ;
else if ( V_226 == V_228 )
F_123 ( V_25 , V_13 ) ;
}
static void F_126 ( struct V_25 * V_25 , T_1 V_13 )
{
F_124 ( V_25 , V_13 ) ;
F_114 ( V_25 -> V_30 , V_13 ) ;
}
static void F_127 ( struct V_25 * V_25 )
{
int V_76 ;
for ( V_76 = 1 ; V_76 < V_229 ; V_76 ++ )
if ( F_118 ( V_25 , V_76 ) )
F_126 ( V_25 , V_76 ) ;
F_96 ( V_25 -> V_218 ) ;
}
static int F_128 ( struct V_25 * V_25 )
{
T_6 V_230 ;
T_1 V_79 , V_183 ;
int V_76 ;
int V_34 ;
V_230 = sizeof( struct V_23 * ) * V_229 ;
V_25 -> V_218 = F_120 ( V_230 , V_180 ) ;
if ( ! V_25 -> V_218 )
return - V_181 ;
for ( V_76 = 1 ; V_76 < V_229 ; V_76 ++ ) {
V_34 = F_35 ( V_25 , V_76 , & V_79 ,
& V_183 ) ;
if ( V_34 )
goto V_231;
if ( ! V_183 )
continue;
V_34 = F_112 ( V_25 , V_76 , V_79 , V_183 ) ;
if ( V_34 )
goto V_220;
}
return 0 ;
V_220:
V_231:
for ( V_76 -- ; V_76 >= 1 ; V_76 -- )
if ( F_118 ( V_25 , V_76 ) )
F_126 ( V_25 , V_76 ) ;
F_96 ( V_25 -> V_218 ) ;
return V_34 ;
}
static void F_129 ( struct V_23 * V_23 ,
enum V_232 V_233 )
{
if ( V_233 == V_234 ) {
F_130 ( V_23 -> V_59 , L_19 ) ;
F_131 ( V_23 -> V_59 ) ;
} else {
F_130 ( V_23 -> V_59 , L_20 ) ;
F_107 ( V_23 -> V_59 ) ;
}
}
static void F_132 ( struct V_23 * V_23 ,
enum V_232 V_233 )
{
if ( V_233 == V_234 )
F_133 ( L_21 ,
V_23 -> V_78 . V_79 + 1 ) ;
else
F_133 ( L_22 ,
V_23 -> V_78 . V_79 + 1 ) ;
}
static void F_134 ( const struct V_235 * V_236 ,
char * V_237 , void * V_238 )
{
struct V_25 * V_25 = V_238 ;
struct V_23 * V_23 ;
enum V_232 V_233 ;
enum V_225 V_226 ;
T_1 V_13 ;
V_13 = F_135 ( V_237 ) ;
V_23 = V_25 -> V_218 [ V_13 ] ;
if ( ! V_23 ) {
F_136 ( V_25 -> V_87 -> V_59 , L_23 ,
V_13 ) ;
return;
}
V_233 = F_137 ( V_237 ) ;
V_226 = F_125 ( V_25 -> V_30 , V_13 ) ;
if ( V_226 == V_227 )
F_129 ( V_23 , V_233 ) ;
else if ( V_226 == V_228 )
F_132 ( V_23 , V_233 ) ;
}
static void F_138 ( struct V_1 * V_2 , T_1 V_13 ,
void * V_238 )
{
struct V_25 * V_25 = V_238 ;
struct V_23 * V_23 = V_25 -> V_218 [ V_13 ] ;
struct V_60 * V_61 ;
if ( F_46 ( ! V_23 ) ) {
F_139 ( V_25 -> V_87 -> V_59 , L_24 ,
V_13 ) ;
return;
}
V_2 -> V_59 = V_23 -> V_59 ;
V_61 = F_53 ( V_23 -> V_61 ) ;
F_54 ( & V_61 -> V_67 ) ;
V_61 -> V_73 ++ ;
V_61 -> V_74 += V_2 -> V_62 ;
F_55 ( & V_61 -> V_67 ) ;
V_2 -> V_239 = F_140 ( V_2 , V_2 -> V_59 ) ;
F_141 ( V_2 ) ;
}
static int F_142 ( struct V_240 * V_240 , T_1 V_13 ,
enum V_225 V_241 )
{
struct V_25 * V_25 = F_143 ( V_240 ) ;
T_1 V_79 , V_183 ;
int V_34 ;
if ( V_241 == V_242 )
return - V_106 ;
F_124 ( V_25 , V_13 ) ;
V_34 = F_35 ( V_25 , V_13 , & V_79 ,
& V_183 ) ;
if ( V_34 )
goto V_231;
if ( V_241 == V_227 )
V_34 = F_102 ( V_25 , V_13 , V_79 ,
V_183 ) ;
else if ( V_241 == V_228 )
V_34 = F_119 ( V_25 , V_13 , V_79 ,
V_183 ) ;
V_231:
return V_34 ;
}
static int F_144 ( struct V_25 * V_25 )
{
char V_243 [ V_244 ] ;
int V_76 ;
int V_34 ;
F_145 ( V_243 , V_245 ,
V_246 ,
V_247 ,
V_248 ) ;
F_146 ( V_243 ,
V_249 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_250 ) , V_243 ) ;
if ( V_34 )
return V_34 ;
F_145 ( V_243 , V_251 ,
V_246 ,
V_247 ,
V_248 ) ;
F_146 ( V_243 ,
V_252 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_250 ) , V_243 ) ;
if ( V_34 )
return V_34 ;
for ( V_76 = 0 ; V_76 < F_147 ( V_253 ) ; V_76 ++ ) {
V_34 = F_148 ( V_25 -> V_30 ,
& V_253 [ V_76 ] ,
V_25 ) ;
if ( V_34 )
goto V_254;
}
return 0 ;
V_254:
for ( V_76 -- ; V_76 >= 0 ; V_76 -- ) {
F_149 ( V_25 -> V_30 ,
& V_253 [ V_76 ] ,
V_25 ) ;
}
return V_34 ;
}
static void F_150 ( struct V_25 * V_25 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < F_147 ( V_253 ) ; V_76 ++ ) {
F_149 ( V_25 -> V_30 ,
& V_253 [ V_76 ] ,
V_25 ) ;
}
}
static int F_151 ( struct V_25 * V_25 )
{
char V_255 [ V_256 ] ;
char V_257 [ V_258 ] ;
char * V_259 ;
int V_34 ;
V_259 = F_93 ( V_260 , V_180 ) ;
if ( ! V_259 )
return - V_181 ;
F_152 ( V_259 , 0 , 0 , V_261 , 0 ,
V_262 , true ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_263 ) , V_259 ) ;
F_96 ( V_259 ) ;
if ( V_34 )
return V_34 ;
F_153 ( V_255 ,
V_264 ,
V_265 ,
V_261 ,
0 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_266 ) , V_255 ) ;
if ( V_34 )
return V_34 ;
F_153 ( V_255 ,
V_267 ,
V_265 ,
V_261 ,
0 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_266 ) , V_255 ) ;
if ( V_34 )
return V_34 ;
F_153 ( V_255 ,
V_268 ,
V_265 ,
V_261 ,
0 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_266 ) , V_255 ) ;
if ( V_34 )
return V_34 ;
F_153 ( V_255 ,
V_269 ,
V_265 ,
V_261 ,
0 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_266 ) , V_255 ) ;
if ( V_34 )
return V_34 ;
F_153 ( V_255 ,
V_270 ,
V_265 ,
V_261 ,
0 ) ;
V_34 = F_18 ( V_25 -> V_30 , F_19 ( V_266 ) , V_255 ) ;
if ( V_34 )
return V_34 ;
F_154 ( V_257 , true ) ;
return F_18 ( V_25 -> V_30 , F_19 ( V_271 ) , V_257 ) ;
}
static int F_155 ( struct V_240 * V_240 )
{
char V_243 [ V_244 ] ;
F_145 ( V_243 , V_272 ,
V_246 ,
V_247 ,
V_248 ) ;
F_156 ( V_243 , V_273 ) ;
F_146 ( V_243 ,
V_274 ) ;
return F_18 ( V_240 , F_19 ( V_250 ) , V_243 ) ;
}
static int F_157 ( struct V_240 * V_240 ,
const struct V_275 * V_275 )
{
struct V_25 * V_25 = F_143 ( V_240 ) ;
int V_34 ;
V_25 -> V_30 = V_240 ;
V_25 -> V_87 = V_275 ;
V_34 = F_87 ( V_25 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_25 ) ;
return V_34 ;
}
V_34 = F_128 ( V_25 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_26 ) ;
return V_34 ;
}
V_34 = F_144 ( V_25 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_27 ) ;
goto V_254;
}
V_34 = F_151 ( V_25 ) ;
if ( V_34 ) {
F_106 ( V_25 -> V_87 -> V_59 , L_28 ) ;
goto V_276;
}
return 0 ;
V_276:
F_150 ( V_25 ) ;
V_254:
F_127 ( V_25 ) ;
return V_34 ;
}
static void F_158 ( struct V_240 * V_240 )
{
struct V_25 * V_25 = F_143 ( V_240 ) ;
F_150 ( V_25 ) ;
F_127 ( V_25 ) ;
}
static int T_7 F_159 ( void )
{
int V_34 ;
V_34 = F_160 ( & V_277 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_161 ( & V_278 ) ;
if ( V_34 )
goto V_279;
return 0 ;
V_279:
F_162 ( & V_277 ) ;
return V_34 ;
}
static void T_8 F_163 ( void )
{
F_164 ( & V_278 ) ;
F_162 ( & V_277 ) ;
}
