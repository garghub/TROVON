static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_4 ] ;
F_2 ( V_3 , V_5 , V_6 ) ;
F_2 ( V_3 , V_7 ,
V_2 -> V_8 -> V_9 -> V_9 ) ;
F_2 ( V_3 , V_10 , V_2 -> V_8 -> V_11 ) ;
return F_3 ( V_2 , V_12 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_13 ] ;
F_2 ( V_3 , V_5 , V_14 ) ;
return F_3 ( V_2 , V_12 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static void F_5 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
while ( ( V_18 = F_6 ( V_16 ) ) ) {
F_7 () ;
F_8 ( V_18 ) ;
F_9 () ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_19 , V_2 -> V_20 ,
L_1
L_2 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_21 V_23 ;
struct V_24 V_25 ;
struct V_26 * V_27 = V_2 -> V_8 ;
struct V_24 V_28 ;
int * V_29 = V_27 -> V_28 . V_30 ;
F_13 ( & V_23 ) ;
V_28 = V_23 . V_31 ;
V_25 = V_23 . V_31 ;
F_14 ( & V_25 , V_32 ) ;
while ( ( F_15 ( & V_23 . V_31 , & V_25 ) < 0 ) &&
F_16 ( * V_29 ) ) {
struct V_24 V_33 ;
unsigned int V_34 ;
V_33 = V_23 . V_31 ;
F_14 ( & V_33 , V_35 ) ;
do {
F_13 ( & V_23 ) ;
} while ( ( F_15 ( & V_23 . V_31 , & V_33 ) < 0 ) &&
F_16 ( * V_29 ) );
V_34 = ( V_23 . V_31 . V_36 << V_37 |
V_23 . V_31 . V_38 ) ;
F_17 ( V_2 , F_18 ( V_34 ) ,
V_39 + V_40 ) ;
}
* V_22 = V_23 ;
}
static void F_19 ( T_1 * V_41 , struct V_42 * V_43 )
{
unsigned V_44 , V_45 ;
V_43 -> V_46 = F_20 ( V_41 , V_47 ) ;
V_43 -> V_48 = F_20 ( V_41 , V_49 ) ;
V_43 -> V_50 = F_20 ( V_41 ,
V_51 ) ;
V_43 -> V_52 = F_20 ( V_41 , V_53 ) ,
V_43 -> V_54 = F_20 ( V_41 , V_55 ) ;
V_44 = V_43 -> V_46 & V_56 ;
V_45 = V_43 -> V_52 & V_56 ;
if ( V_45 < V_44 )
V_45 += V_57 ;
V_43 -> V_58 = V_45 - V_44 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 * V_59 ,
T_2 V_60 ,
const struct V_21 * V_22 )
{
unsigned V_61 = ( V_60 /
V_62 ) ;
unsigned V_63 ;
unsigned V_64 ;
unsigned V_65 = 0 ;
unsigned V_66 ;
unsigned V_67 = 0 ;
unsigned V_68 = 0 ;
struct V_26 * V_27 = V_2 -> V_8 ;
bool V_69 = false ;
T_3 V_70 ;
T_3 V_71 ;
struct V_24 V_72 ;
if ( V_61 == 0 )
return - V_73 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
F_19 ( V_59 , & V_27 -> V_43 [ V_63 ] ) ;
V_59 += V_62 ;
if ( V_27 -> V_43 [ V_63 ] . V_58 > V_35 ) {
if ( V_69 ) {
if ( V_27 -> V_43 [ V_63 ] . V_58 < V_65 )
V_65 = V_27 -> V_43 [ V_63 ] . V_58 ;
} else {
V_69 = true ;
V_65 = V_27 -> V_43 [ V_63 ] . V_58 ;
}
}
}
if ( V_69 ) {
if ( V_27 -> V_74 && ( V_65 > V_27 -> V_75 ) )
V_64 = V_27 -> V_75 ;
else
V_64 = V_65 ;
} else {
V_64 = V_35 ;
}
V_66 = 0 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ )
if ( V_27 -> V_43 [ V_63 ] . V_58 > V_27 -> V_43 [ V_63 ] . V_54 ) {
unsigned V_76 ;
V_76 = V_27 -> V_43 [ V_63 ] . V_58 - V_27 -> V_43 [ V_63 ] . V_54 ;
if ( V_76 >= V_77 &&
V_76 < V_78 ) {
V_66 += V_27 -> V_43 [ V_63 ] . V_58 ;
V_67 ++ ;
V_68 = V_63 ;
}
}
if ( V_67 == 0 ) {
F_22 ( V_2 , V_19 , V_2 -> V_20 ,
L_3 ,
V_27 -> V_75 , V_65 ) ;
return - V_73 ;
}
V_27 -> V_79 = F_23 ( V_66 , V_67 ) ;
if ( ! V_27 -> V_74 || ( V_27 -> V_79 < V_27 -> V_75 ) ) {
V_27 -> V_74 = true ;
V_27 -> V_75 = V_27 -> V_79 ;
}
V_72 . V_38 =
V_27 -> V_43 [ V_68 ] . V_50 +
V_22 -> V_31 . V_38 -
( V_27 -> V_43 [ V_68 ] . V_46 & V_56 ) ;
V_71 = V_27 -> V_43 [ V_68 ] . V_46 >> V_37 ;
V_70 = V_22 -> V_31 . V_36 & V_80 ;
if ( V_71 != V_70 ) {
if ( ( ( V_71 + 1 ) & V_80 ) != V_70 ) {
F_22 ( V_2 , V_81 , V_2 -> V_20 ,
L_4 ) ;
return - V_73 ;
} else {
V_72 . V_36 = 1 ;
}
} else {
V_72 . V_36 = 0 ;
}
V_27 -> V_82 = * V_22 ;
F_24 ( & V_27 -> V_82 , V_72 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_83 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
T_1 V_59 [ V_84 ] ;
T_2 V_60 ;
int V_85 ;
unsigned long V_86 ;
struct V_21 V_22 = {} ;
unsigned int V_87 = 0 ;
int * V_28 = V_27 -> V_28 . V_30 ;
F_2 ( V_59 , V_5 , V_88 ) ;
F_2 ( V_59 , V_89 ,
V_83 ) ;
F_2 ( V_59 , V_90 ,
( T_3 ) V_27 -> V_28 . V_91 ) ;
F_2 ( V_59 , V_92 ,
( T_3 ) ( ( V_93 ) V_27 -> V_28 . V_91 >> 32 ) ) ;
F_16 ( * V_28 ) = 0 ;
F_26 ( V_2 , V_12 , V_59 ,
V_94 ) ;
V_86 = V_95 + F_27 ( V_96 ) ;
while ( ! F_16 ( * V_28 ) && ( F_28 ( V_95 , V_86 ) ) ) {
F_29 ( 20 ) ;
V_87 ++ ;
}
if ( F_16 ( * V_28 ) )
F_12 ( V_2 , & V_22 ) ;
V_85 = F_30 ( V_2 , V_12 ,
V_94 ,
V_59 , sizeof( V_59 ) ,
& V_60 ) ;
if ( V_85 == 0 )
V_85 = F_21 ( V_2 , V_59 , V_60 ,
& V_22 ) ;
return V_85 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
T_1 * V_97 = V_2 -> V_8 -> V_97 ;
struct V_98 V_99 ;
int V_85 = - V_100 ;
T_2 V_101 = F_32 ( F_33 ( V_18 -> V_101 ) , 4 ) ;
T_1 V_102 [ V_103 ] ;
F_2 ( V_97 , V_5 , V_104 ) ;
F_2 ( V_97 , V_105 , V_18 -> V_101 ) ;
if ( F_34 ( V_18 ) -> V_106 != 0 ) {
V_85 = F_35 ( V_18 ) ;
if ( V_85 != 0 )
goto V_107;
}
if ( V_18 -> V_108 == V_109 ) {
V_85 = F_36 ( V_18 ) ;
if ( V_85 != 0 )
goto V_107;
}
F_37 ( V_18 ,
& V_97 [ V_110 ] ,
V_101 ) ;
V_85 = F_3 ( V_2 , V_12 , V_97 , V_101 , V_102 ,
sizeof( V_102 ) , & V_101 ) ;
if ( V_85 != 0 )
goto V_107;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_111 = F_38 (
F_20 ( V_102 , V_112 ) ,
F_20 ( V_102 , V_113 ) ) ;
F_39 ( V_18 , & V_99 ) ;
V_85 = 0 ;
V_107:
F_40 ( V_18 ) ;
return V_85 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
struct V_114 * V_115 ;
struct V_114 * V_116 ;
F_42 ( & V_27 -> V_117 ) ;
if ( ! F_43 ( & V_27 -> V_118 ) ) {
F_44 (cursor, next, &ptp->evt_list) {
struct V_119 * V_120 ;
V_120 = F_45 ( V_115 , struct V_119 ,
V_121 ) ;
if ( F_46 ( V_95 , V_120 -> V_122 ) ) {
F_47 ( & V_120 -> V_121 , & V_27 -> V_123 ) ;
F_22 ( V_2 , V_81 , V_2 -> V_20 ,
L_5 ) ;
}
}
}
F_48 ( & V_27 -> V_117 ) ;
}
static enum V_124 F_49 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
bool V_125 ;
struct V_114 * V_115 ;
struct V_114 * V_116 ;
struct V_126 * V_127 ;
enum V_124 V_85 = V_128 ;
F_42 ( & V_27 -> V_117 ) ;
V_125 = ! F_43 ( & V_27 -> V_118 ) ;
F_48 ( & V_27 -> V_117 ) ;
if ( ! V_125 )
return V_128 ;
V_127 = (struct V_126 * ) V_18 -> V_129 ;
F_42 ( & V_27 -> V_117 ) ;
F_44 (cursor, next, &ptp->evt_list) {
struct V_119 * V_120 ;
V_120 = F_45 ( V_115 , struct V_119 , V_121 ) ;
if ( ( V_120 -> V_130 == V_127 -> V_131 [ 0 ] ) &&
( V_120 -> V_132 == V_127 -> V_131 [ 1 ] ) ) {
struct V_98 * V_99 ;
V_99 = F_50 ( V_18 ) ;
V_99 -> V_111 = V_120 -> V_133 ;
V_127 -> V_134 = V_135 ;
V_85 = V_135 ;
F_47 ( & V_120 -> V_121 , & V_27 -> V_123 ) ;
break;
}
}
F_48 ( & V_27 -> V_117 ) ;
return V_85 ;
}
static bool F_51 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
bool V_85 = false ;
struct V_17 * V_18 ;
while ( ( V_18 = F_6 ( & V_27 -> V_136 ) ) ) {
struct V_126 * V_127 ;
V_127 = (struct V_126 * ) V_18 -> V_129 ;
if ( V_127 -> V_134 == V_137 ) {
F_52 ( V_16 , V_18 ) ;
} else if ( F_49 ( V_2 , V_18 ) ==
V_135 ) {
V_85 = true ;
F_52 ( V_16 , V_18 ) ;
} else if ( F_46 ( V_95 , V_127 -> V_122 ) ) {
V_127 -> V_134 = V_138 ;
F_22 ( V_2 , V_139 , V_2 -> V_20 ,
L_6 ) ;
F_52 ( V_16 , V_18 ) ;
} else {
F_53 ( & V_27 -> V_136 , V_18 ) ;
break;
}
}
return V_85 ;
}
static inline void F_54 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
F_7 () ;
F_8 ( V_18 ) ;
F_9 () ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
struct V_140 V_141 ;
int V_85 ;
V_27 -> V_142 = false ;
F_56 ( & V_141 , V_143 , 0 ,
F_57 (
F_58 ( V_27 -> V_9 ) ) ) ;
V_85 = F_59 ( & V_141 , V_144 ,
F_60 ( V_145 ) ,
F_61 ( V_146 ) ) ;
if ( V_85 != 0 )
return V_85 ;
V_85 = F_62 ( V_2 , & V_141 , true ) ;
if ( V_85 < 0 )
return V_85 ;
V_27 -> V_147 = V_85 ;
F_56 ( & V_141 , V_143 , 0 ,
F_57 (
F_58 ( V_27 -> V_9 ) ) ) ;
V_85 = F_59 ( & V_141 , V_144 ,
F_60 ( V_145 ) ,
F_61 ( V_148 ) ) ;
if ( V_85 != 0 )
goto V_107;
V_85 = F_62 ( V_2 , & V_141 , true ) ;
if ( V_85 < 0 )
goto V_107;
V_27 -> V_149 = V_85 ;
V_85 = F_1 ( V_2 ) ;
if ( V_85 != 0 )
goto V_150;
V_27 -> V_151 = 0 ;
V_27 -> V_152 = 0 ;
V_27 -> V_153 = true ;
return 0 ;
V_150:
F_63 ( V_2 , V_143 ,
V_27 -> V_149 ) ;
V_107:
F_63 ( V_2 , V_143 ,
V_27 -> V_147 ) ;
return V_85 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
int V_85 = F_4 ( V_2 ) ;
struct V_114 * V_115 ;
struct V_114 * V_116 ;
if ( V_27 -> V_153 ) {
F_63 ( V_2 , V_143 ,
V_27 -> V_149 ) ;
F_63 ( V_2 , V_143 ,
V_27 -> V_147 ) ;
V_27 -> V_153 = false ;
}
F_5 ( & V_2 -> V_8 -> V_136 ) ;
F_65 ( & V_2 -> V_8 -> V_154 ) ;
F_42 ( & V_2 -> V_8 -> V_117 ) ;
F_44 (cursor, next, &efx->ptp_data->evt_list) {
F_47 ( V_115 , & V_2 -> V_8 -> V_123 ) ;
}
F_48 ( & V_2 -> V_8 -> V_117 ) ;
return V_85 ;
}
static void F_66 ( struct V_155 * V_156 )
{
struct V_26 * V_27 =
F_67 ( V_156 , struct V_26 , V_157 ) ;
struct V_1 * V_2 = V_27 -> V_9 -> V_2 ;
struct V_158 V_159 ;
if ( F_25 ( V_2 , V_160 ) )
return;
V_159 . type = V_161 ;
V_159 . V_162 = V_27 -> V_82 ;
V_158 ( V_27 -> V_163 , & V_159 ) ;
}
static void F_68 ( struct V_155 * V_156 )
{
struct V_26 * V_8 =
F_67 ( V_156 , struct V_26 , V_156 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
struct V_17 * V_18 ;
struct V_15 V_164 ;
if ( V_8 -> V_142 ) {
F_64 ( V_2 ) ;
F_55 ( V_2 ) ;
return;
}
F_41 ( V_2 ) ;
F_69 ( & V_164 ) ;
if ( F_51 ( V_2 , & V_164 ) ||
! F_70 ( & V_8 -> V_154 ) ) {
while ( ( V_18 = F_6 ( & V_8 -> V_154 ) ) )
F_31 ( V_2 , V_18 ) ;
}
while ( ( V_18 = F_71 ( & V_164 ) ) )
F_54 ( V_2 , V_18 ) ;
}
static int F_72 ( struct V_165 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_26 * V_27 ;
int V_85 = 0 ;
unsigned int V_166 ;
V_9 -> V_167 = 0 ;
V_9 -> V_168 . V_169 = 0 ;
V_27 = F_73 ( sizeof( struct V_26 ) , V_170 ) ;
V_2 -> V_8 = V_27 ;
if ( ! V_2 -> V_8 )
return - V_171 ;
V_85 = F_74 ( V_2 , & V_27 -> V_28 , sizeof( int ) ) ;
if ( V_85 != 0 )
goto V_172;
V_27 -> V_9 = V_9 ;
F_75 ( & V_27 -> V_136 ) ;
F_75 ( & V_27 -> V_154 ) ;
V_27 -> V_173 = F_76 ( L_7 ) ;
if ( ! V_27 -> V_173 ) {
V_85 = - V_171 ;
goto V_150;
}
F_77 ( & V_27 -> V_156 , F_68 ) ;
V_27 -> V_174 . V_175 = 0 ;
V_27 -> V_174 . V_176 = V_177 ;
V_27 -> V_174 . V_178 = V_179 ;
F_78 ( & V_27 -> V_118 ) ;
F_78 ( & V_27 -> V_123 ) ;
F_79 ( & V_27 -> V_117 ) ;
for ( V_166 = 0 ; V_166 < V_180 ; V_166 ++ )
F_80 ( & V_27 -> V_181 [ V_166 ] . V_121 , & V_27 -> V_123 ) ;
V_27 -> V_182 . V_183 = V_184 ;
snprintf ( V_27 -> V_182 . V_185 ,
sizeof( V_27 -> V_182 . V_185 ) ,
L_8 , V_2 -> V_20 -> V_186 ) ;
V_27 -> V_182 . V_187 = V_188 ;
V_27 -> V_182 . V_189 = 0 ;
V_27 -> V_182 . V_190 = 0 ;
V_27 -> V_182 . V_191 = 0 ;
V_27 -> V_182 . V_192 = 1 ;
V_27 -> V_182 . V_193 = V_194 ;
V_27 -> V_182 . V_195 = V_196 ;
V_27 -> V_182 . V_197 = V_198 ;
V_27 -> V_182 . V_199 = V_200 ;
V_27 -> V_182 . V_201 = V_202 ;
V_27 -> V_163 = F_81 ( & V_27 -> V_182 ,
& V_2 -> V_203 -> V_204 ) ;
if ( ! V_27 -> V_163 )
goto V_205;
F_77 ( & V_27 -> V_157 , F_66 ) ;
V_27 -> V_206 = F_76 ( L_9 ) ;
if ( ! V_27 -> V_206 ) {
V_85 = - V_171 ;
goto V_207;
}
V_27 -> V_208 = false ;
return 0 ;
V_207:
F_82 ( V_2 -> V_8 -> V_163 ) ;
V_205:
F_83 ( V_2 -> V_8 -> V_173 ) ;
V_150:
F_84 ( V_2 , & V_27 -> V_28 ) ;
V_172:
F_85 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
return V_85 ;
}
static void F_86 ( struct V_165 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( ! V_2 -> V_8 )
return;
( void ) F_4 ( V_9 -> V_2 ) ;
F_87 ( & V_2 -> V_8 -> V_156 ) ;
F_87 ( & V_2 -> V_8 -> V_157 ) ;
F_65 ( & V_2 -> V_8 -> V_136 ) ;
F_65 ( & V_2 -> V_8 -> V_154 ) ;
F_82 ( V_2 -> V_8 -> V_163 ) ;
F_83 ( V_2 -> V_8 -> V_173 ) ;
F_83 ( V_2 -> V_8 -> V_206 ) ;
F_84 ( V_2 , & V_2 -> V_8 -> V_28 ) ;
F_85 ( V_2 -> V_8 ) ;
}
static void F_88 ( struct V_165 * V_9 ,
char * V_209 , T_2 V_101 )
{
snprintf ( V_209 , V_101 , L_10 , V_9 -> V_2 -> V_185 ) ;
}
bool F_89 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
return V_2 -> V_8 &&
V_2 -> V_8 -> V_210 &&
V_18 -> V_101 >= V_211 &&
V_18 -> V_101 <= V_212 &&
F_90 ( V_18 -> V_213 == F_61 ( V_214 ) ) &&
F_91 ( V_18 ) -> V_213 == V_144 &&
F_92 ( V_18 ) -> V_215 == F_61 ( V_146 ) ;
}
static void F_93 ( struct V_165 * V_9 , struct V_17 * V_18 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_26 * V_27 = V_2 -> V_8 ;
struct V_126 * V_127 = (struct V_126 * ) V_18 -> V_129 ;
T_1 * V_41 ;
unsigned int V_216 ;
V_127 -> V_122 = V_95 + F_27 ( V_217 ) ;
if ( V_27 -> V_11 == V_218 ) {
if ( V_18 -> V_101 < V_219 ) {
F_8 ( V_18 ) ;
return;
}
V_216 = F_94 ( * ( V_220 * ) & V_18 -> V_41 [ V_221 ] ) ;
if ( V_216 != V_222 ) {
F_8 ( V_18 ) ;
return;
}
} else {
if ( V_18 -> V_101 < V_223 ) {
F_8 ( V_18 ) ;
return;
}
V_216 = V_18 -> V_41 [ V_224 ] ;
F_95 ( V_27 -> V_11 != V_225 ) ;
F_96 ( V_226 != V_227 ) ;
F_96 ( V_228 != V_229 ) ;
F_96 ( V_230 != V_231 ) ;
F_96 ( V_232 != V_233 ) ;
if ( ( V_216 & V_234 ) != V_235 ) {
F_8 ( V_18 ) ;
return;
}
}
if ( F_94 ( * ( V_220 * ) & V_18 -> V_41 [ V_236 ] ) == V_146 ) {
struct V_98 * V_99 ;
V_127 -> V_134 = V_128 ;
V_99 = F_50 ( V_18 ) ;
memset ( V_99 , 0 , sizeof( * V_99 ) ) ;
V_41 = V_18 -> V_41 + V_226 ;
V_127 -> V_131 [ 0 ] = ( V_41 [ 0 ] |
( V_41 [ 1 ] << 8 ) |
( V_41 [ 2 ] << 16 ) |
( V_41 [ 3 ] << 24 ) ) ;
V_127 -> V_131 [ 1 ] = ( V_41 [ 4 ] |
( V_41 [ 5 ] << 8 ) |
( V_18 -> V_41 [ V_230 +
V_232 - 1 ] <<
16 ) ) ;
} else {
V_127 -> V_134 = V_137 ;
}
F_97 ( & V_27 -> V_136 , V_18 ) ;
F_98 ( V_27 -> V_173 , & V_27 -> V_156 ) ;
}
int F_99 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
F_97 ( & V_27 -> V_154 , V_18 ) ;
if ( ( F_92 ( V_18 ) -> V_215 == F_61 ( V_146 ) ) &&
( V_18 -> V_101 <= V_212 ) )
F_100 ( V_18 ) ;
F_98 ( V_27 -> V_173 , & V_27 -> V_156 ) ;
return V_237 ;
}
static int F_101 ( struct V_1 * V_2 , bool V_238 ,
unsigned int V_239 )
{
if ( ( V_238 != V_2 -> V_8 -> V_210 ) ||
( V_238 && ( V_2 -> V_8 -> V_11 != V_239 ) ) ) {
int V_85 ;
if ( V_238 ) {
if ( V_2 -> V_8 -> V_210 &&
( V_2 -> V_8 -> V_11 != V_239 ) ) {
V_2 -> V_8 -> V_210 = false ;
V_85 = F_64 ( V_2 ) ;
if ( V_85 != 0 )
return V_85 ;
}
V_2 -> V_8 -> V_11 = V_239 ;
V_85 = F_55 ( V_2 ) ;
if ( V_85 == 0 ) {
V_85 = F_25 ( V_2 ,
V_160 * 2 ) ;
if ( V_85 != 0 )
F_64 ( V_2 ) ;
}
} else {
V_85 = F_64 ( V_2 ) ;
}
if ( V_85 != 0 )
return V_85 ;
V_2 -> V_8 -> V_210 = V_238 ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_240 * V_241 )
{
bool V_238 = false ;
unsigned int V_239 ;
int V_85 ;
if ( V_241 -> V_175 )
return - V_242 ;
if ( ( V_241 -> V_176 != V_177 ) &&
( V_241 -> V_176 != V_243 ) )
return - V_244 ;
V_239 = V_2 -> V_8 -> V_11 ;
switch ( V_241 -> V_178 ) {
case V_179 :
break;
case V_245 :
case V_246 :
case V_247 :
V_241 -> V_178 = V_245 ;
V_239 = V_218 ;
V_238 = true ;
break;
case V_248 :
case V_249 :
case V_250 :
V_241 -> V_178 = V_248 ;
V_239 = V_225 ;
V_238 = true ;
break;
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
return - V_244 ;
break;
default:
return - V_244 ;
}
if ( V_241 -> V_176 != V_177 )
V_238 = true ;
V_85 = F_101 ( V_2 , V_238 , V_239 ) ;
if ( V_85 != 0 )
return V_85 ;
V_2 -> V_8 -> V_174 = * V_241 ;
return 0 ;
}
int
F_103 ( struct V_257 * V_20 , struct V_258 * V_259 )
{
struct V_1 * V_2 = F_104 ( V_20 ) ;
struct V_26 * V_27 = V_2 -> V_8 ;
if ( ! V_27 )
return - V_260 ;
V_259 -> V_261 = ( V_262 |
V_263 |
V_264 ) ;
V_259 -> V_265 = F_105 ( V_27 -> V_163 ) ;
V_259 -> V_266 = 1 << V_177 | 1 << V_243 ;
V_259 -> V_267 = ( 1 << V_179 |
1 << V_245 |
1 << V_246 |
1 << V_247 |
1 << V_248 |
1 << V_249 |
1 << V_250 ) ;
return 0 ;
}
int F_106 ( struct V_1 * V_2 , struct V_268 * V_269 , int V_270 )
{
struct V_240 V_174 ;
int V_85 ;
if ( ! V_2 -> V_8 )
return - V_260 ;
if ( F_107 ( & V_174 , V_269 -> V_271 , sizeof( V_174 ) ) )
return - V_272 ;
V_85 = F_102 ( V_2 , & V_174 ) ;
if ( V_85 != 0 )
return V_85 ;
return F_108 ( V_269 -> V_271 , & V_174 , sizeof( V_174 ) )
? - V_272 : 0 ;
}
static void F_109 ( struct V_1 * V_2 , int V_273 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
F_11 ( V_2 , V_81 , V_2 -> V_20 ,
L_11 ,
V_27 -> V_151 , V_273 ) ;
V_27 -> V_142 = true ;
F_98 ( V_27 -> V_173 , & V_27 -> V_156 ) ;
}
static void F_110 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_119 * V_120 = NULL ;
if ( V_27 -> V_151 != 3 ) {
F_109 ( V_2 , 3 ) ;
return;
}
F_42 ( & V_27 -> V_117 ) ;
if ( ! F_43 ( & V_27 -> V_123 ) ) {
V_120 = F_111 ( & V_27 -> V_123 ,
struct V_119 , V_121 ) ;
F_112 ( & V_120 -> V_121 ) ;
V_120 -> V_130 = F_113 ( V_27 -> V_274 [ 2 ] , V_275 ) ;
V_120 -> V_132 = ( F_113 ( V_27 -> V_274 [ 2 ] ,
V_276 ) |
( F_113 ( V_27 -> V_274 [ 1 ] ,
V_276 ) << 8 ) |
( F_113 ( V_27 -> V_274 [ 0 ] ,
V_276 ) << 16 ) ) ;
V_120 -> V_133 = F_38 (
F_113 ( V_27 -> V_274 [ 0 ] , V_275 ) ,
F_113 ( V_27 -> V_274 [ 1 ] , V_275 ) ) ;
V_120 -> V_122 = V_95 + F_27 ( V_217 ) ;
F_114 ( & V_120 -> V_121 , & V_27 -> V_118 ) ;
F_98 ( V_27 -> V_173 , & V_27 -> V_156 ) ;
} else {
F_11 ( V_2 , V_139 , V_2 -> V_20 , L_12 ) ;
}
F_48 ( & V_27 -> V_117 ) ;
}
static void F_115 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_277 = F_113 ( V_27 -> V_274 [ 0 ] , V_275 ) ;
if ( V_27 -> V_151 != 1 ) {
F_109 ( V_2 , 1 ) ;
return;
}
F_11 ( V_2 , V_81 , V_2 -> V_20 , L_13 , V_277 ) ;
}
static void F_116 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( V_27 -> V_208 )
F_98 ( V_27 -> V_206 , & V_27 -> V_157 ) ;
}
void F_117 ( struct V_1 * V_2 , T_4 * V_278 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
int V_277 = F_113 ( * V_278 , V_279 ) ;
if ( ! V_27 -> V_210 )
return;
if ( V_27 -> V_151 == 0 ) {
V_27 -> V_280 = V_277 ;
} else if ( V_27 -> V_280 != V_277 ) {
F_11 ( V_2 , V_81 , V_2 -> V_20 ,
L_14 , V_277 ) ;
V_27 -> V_151 = 0 ;
}
V_27 -> V_274 [ V_27 -> V_151 ++ ] = * V_278 ;
if ( ! F_118 ( * V_278 , V_281 ) ) {
switch ( V_277 ) {
case V_282 :
F_110 ( V_2 , V_27 ) ;
break;
case V_283 :
F_115 ( V_2 , V_27 ) ;
break;
case V_284 :
F_116 ( V_2 , V_27 ) ;
break;
default:
F_11 ( V_2 , V_81 , V_2 -> V_20 ,
L_15 , V_277 ) ;
break;
}
V_27 -> V_151 = 0 ;
} else if ( V_285 == V_27 -> V_151 ) {
F_11 ( V_2 , V_81 , V_2 -> V_20 ,
L_16 ) ;
V_27 -> V_151 = 0 ;
}
}
static int V_194 ( struct V_286 * V_27 , T_5 V_72 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_182 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
T_1 V_287 [ V_288 ] ;
T_6 V_289 ;
int V_85 ;
if ( V_72 > V_188 )
V_72 = V_188 ;
else if ( V_72 < - V_188 )
V_72 = - V_188 ;
V_289 = ( ( ( T_6 ) V_72 * V_290 ) >>
( V_291 + V_292 ) ) ;
F_2 ( V_287 , V_5 , V_293 ) ;
F_2 ( V_287 , V_294 , ( T_3 ) V_289 ) ;
F_2 ( V_287 , V_295 ,
( T_3 ) ( V_289 >> 32 ) ) ;
F_2 ( V_287 , V_296 , 0 ) ;
F_2 ( V_287 , V_297 , 0 ) ;
V_85 = F_3 ( V_2 , V_12 , V_287 , sizeof( V_287 ) ,
NULL , 0 , NULL ) ;
if ( V_85 != 0 )
return V_85 ;
V_8 -> V_152 = V_72 ;
return 0 ;
}
static int V_196 ( struct V_286 * V_27 , T_6 V_72 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_182 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
struct V_24 V_298 = F_119 ( V_72 ) ;
T_1 V_3 [ V_288 ] ;
F_2 ( V_3 , V_5 , V_293 ) ;
F_2 ( V_3 , V_294 , 0 ) ;
F_2 ( V_3 , V_295 , 0 ) ;
F_2 ( V_3 , V_296 , ( T_3 ) V_298 . V_36 ) ;
F_2 ( V_3 , V_297 , ( T_3 ) V_298 . V_38 ) ;
return F_3 ( V_2 , V_12 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static int V_198 ( struct V_286 * V_27 , struct V_24 * V_299 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_182 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
T_1 V_3 [ V_300 ] ;
T_1 V_301 [ V_302 ] ;
int V_85 ;
F_2 ( V_3 , V_5 , V_303 ) ;
V_85 = F_3 ( V_2 , V_12 , V_3 , sizeof( V_3 ) ,
V_301 , sizeof( V_301 ) , NULL ) ;
if ( V_85 != 0 )
return V_85 ;
V_299 -> V_36 = F_20 ( V_301 , V_304 ) ;
V_299 -> V_38 = F_20 ( V_301 , V_305 ) ;
return 0 ;
}
static int V_200 ( struct V_286 * V_27 ,
const struct V_24 * V_306 )
{
int V_85 ;
struct V_24 V_307 ;
struct V_24 V_72 ;
V_85 = V_198 ( V_27 , & V_307 ) ;
if ( V_85 != 0 )
return V_85 ;
V_72 = F_120 ( * V_306 , V_307 ) ;
V_85 = V_196 ( V_27 , F_121 ( & V_72 ) ) ;
if ( V_85 != 0 )
return V_85 ;
return 0 ;
}
static int V_202 ( struct V_286 * V_27 ,
struct V_308 * V_309 ,
int V_201 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_182 ) ;
if ( V_309 -> type != V_310 )
return - V_260 ;
V_8 -> V_208 = ! ! V_201 ;
return 0 ;
}
void F_122 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) == 0 )
V_2 -> V_311 [ V_312 ] =
& V_313 ;
}
