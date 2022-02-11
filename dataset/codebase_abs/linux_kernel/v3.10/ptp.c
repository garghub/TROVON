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
unsigned V_66 = 0 ;
struct V_26 * V_27 = V_2 -> V_8 ;
T_3 V_67 ;
T_3 V_68 ;
struct V_24 V_69 ;
if ( V_61 == 0 )
return - V_70 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
F_19 ( V_59 , & V_27 -> V_43 [ V_63 ] ) ;
V_59 += V_62 ;
}
V_64 = 0 ;
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ )
if ( V_27 -> V_43 [ V_63 ] . V_58 > V_27 -> V_43 [ V_63 ] . V_54 ) {
unsigned V_71 ;
V_71 = V_27 -> V_43 [ V_63 ] . V_58 - V_27 -> V_43 [ V_63 ] . V_54 ;
if ( V_71 >= V_72 &&
V_71 < V_73 ) {
V_64 += V_27 -> V_43 [ V_63 ] . V_58 ;
V_65 ++ ;
V_66 = V_63 ;
}
}
if ( V_65 == 0 ) {
F_22 ( V_2 , V_19 , V_2 -> V_20 ,
L_3 ,
V_27 -> V_74 ) ;
return - V_70 ;
}
V_27 -> V_75 = F_23 ( V_64 , V_65 ) ;
if ( ! V_27 -> V_76 || ( V_27 -> V_75 < V_27 -> V_74 ) ) {
V_27 -> V_76 = true ;
V_27 -> V_74 = V_27 -> V_75 ;
}
V_69 . V_38 =
V_27 -> V_43 [ V_66 ] . V_50 +
V_22 -> V_31 . V_38 -
( V_27 -> V_43 [ V_66 ] . V_46 & V_56 ) ;
V_68 = V_27 -> V_43 [ V_66 ] . V_46 >> V_37 ;
V_67 = V_22 -> V_31 . V_36 & V_77 ;
if ( V_68 != V_67 ) {
if ( ( ( V_68 + 1 ) & V_77 ) != V_67 ) {
F_22 ( V_2 , V_78 , V_2 -> V_20 ,
L_4 ) ;
return - V_70 ;
} else {
V_69 . V_36 = 1 ;
}
} else {
V_69 . V_36 = 0 ;
}
V_27 -> V_79 = * V_22 ;
F_24 ( & V_27 -> V_79 , V_69 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_80 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
T_1 V_59 [ V_81 ] ;
T_2 V_60 ;
int V_82 ;
unsigned long V_83 ;
struct V_21 V_22 = {} ;
unsigned int V_84 = 0 ;
int * V_28 = V_27 -> V_28 . V_30 ;
F_2 ( V_59 , V_5 , V_85 ) ;
F_2 ( V_59 , V_86 ,
V_80 ) ;
F_2 ( V_59 , V_87 ,
( T_3 ) V_27 -> V_28 . V_88 ) ;
F_2 ( V_59 , V_89 ,
( T_3 ) ( ( V_90 ) V_27 -> V_28 . V_88 >> 32 ) ) ;
F_16 ( * V_28 ) = 0 ;
F_26 ( V_2 , V_12 , V_59 ,
V_91 ) ;
V_83 = V_92 + F_27 ( V_93 ) ;
while ( ! F_16 ( * V_28 ) && ( F_28 ( V_92 , V_83 ) ) ) {
F_29 ( 20 ) ;
V_84 ++ ;
}
if ( F_16 ( * V_28 ) )
F_12 ( V_2 , & V_22 ) ;
V_82 = F_30 ( V_2 , V_12 ,
V_91 ,
V_59 , sizeof( V_59 ) ,
& V_60 ) ;
if ( V_82 == 0 )
V_82 = F_21 ( V_2 , V_59 , V_60 ,
& V_22 ) ;
return V_82 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
T_1 * V_94 = V_2 -> V_8 -> V_94 ;
struct V_95 V_96 ;
int V_82 = - V_97 ;
T_2 V_98 = F_32 ( F_33 ( V_18 -> V_98 ) , 4 ) ;
T_1 V_99 [ V_100 ] ;
F_2 ( V_94 , V_5 , V_101 ) ;
F_2 ( V_94 , V_102 , V_18 -> V_98 ) ;
if ( F_34 ( V_18 ) -> V_103 != 0 ) {
V_82 = F_35 ( V_18 ) ;
if ( V_82 != 0 )
goto V_104;
}
if ( V_18 -> V_105 == V_106 ) {
V_82 = F_36 ( V_18 ) ;
if ( V_82 != 0 )
goto V_104;
}
F_37 ( V_18 ,
& V_94 [ V_107 ] ,
V_98 ) ;
V_82 = F_3 ( V_2 , V_12 , V_94 , V_98 , V_99 ,
sizeof( V_99 ) , & V_98 ) ;
if ( V_82 != 0 )
goto V_104;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_108 = F_38 (
F_20 ( V_99 , V_109 ) ,
F_20 ( V_99 , V_110 ) ) ;
F_39 ( V_18 , & V_96 ) ;
V_82 = 0 ;
V_104:
F_40 ( V_18 ) ;
return V_82 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
struct V_111 * V_112 ;
struct V_111 * V_113 ;
F_42 ( & V_27 -> V_114 ) ;
if ( ! F_43 ( & V_27 -> V_115 ) ) {
F_44 (cursor, next, &ptp->evt_list) {
struct V_116 * V_117 ;
V_117 = F_45 ( V_112 , struct V_116 ,
V_118 ) ;
if ( F_46 ( V_92 , V_117 -> V_119 ) ) {
F_47 ( & V_117 -> V_118 , & V_27 -> V_120 ) ;
F_22 ( V_2 , V_78 , V_2 -> V_20 ,
L_5 ) ;
}
}
}
F_48 ( & V_27 -> V_114 ) ;
}
static enum V_121 F_49 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
bool V_122 ;
struct V_111 * V_112 ;
struct V_111 * V_113 ;
struct V_123 * V_124 ;
enum V_121 V_82 = V_125 ;
F_42 ( & V_27 -> V_114 ) ;
V_122 = ! F_43 ( & V_27 -> V_115 ) ;
F_48 ( & V_27 -> V_114 ) ;
if ( ! V_122 )
return V_125 ;
V_124 = (struct V_123 * ) V_18 -> V_126 ;
F_42 ( & V_27 -> V_114 ) ;
F_44 (cursor, next, &ptp->evt_list) {
struct V_116 * V_117 ;
V_117 = F_45 ( V_112 , struct V_116 , V_118 ) ;
if ( ( V_117 -> V_127 == V_124 -> V_128 [ 0 ] ) &&
( V_117 -> V_129 == V_124 -> V_128 [ 1 ] ) ) {
struct V_95 * V_96 ;
V_96 = F_50 ( V_18 ) ;
V_96 -> V_108 = V_117 -> V_130 ;
V_124 -> V_131 = V_132 ;
V_82 = V_132 ;
F_47 ( & V_117 -> V_118 , & V_27 -> V_120 ) ;
break;
}
}
F_48 ( & V_27 -> V_114 ) ;
return V_82 ;
}
static bool F_51 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
bool V_82 = false ;
struct V_17 * V_18 ;
while ( ( V_18 = F_6 ( & V_27 -> V_133 ) ) ) {
struct V_123 * V_124 ;
V_124 = (struct V_123 * ) V_18 -> V_126 ;
if ( V_124 -> V_131 == V_134 ) {
F_52 ( V_16 , V_18 ) ;
} else if ( F_49 ( V_2 , V_18 ) ==
V_132 ) {
V_82 = true ;
F_52 ( V_16 , V_18 ) ;
} else if ( F_46 ( V_92 , V_124 -> V_119 ) ) {
V_124 -> V_131 = V_135 ;
F_22 ( V_2 , V_136 , V_2 -> V_20 ,
L_6 ) ;
F_52 ( V_16 , V_18 ) ;
} else {
F_53 ( & V_27 -> V_133 , V_18 ) ;
break;
}
}
return V_82 ;
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
struct V_137 V_138 ;
int V_82 ;
V_27 -> V_139 = false ;
F_56 ( & V_138 , V_140 , 0 ,
F_57 (
F_58 ( V_27 -> V_9 ) ) ) ;
V_82 = F_59 ( & V_138 , V_141 ,
F_60 ( V_142 ) ,
F_61 ( V_143 ) ) ;
if ( V_82 != 0 )
return V_82 ;
V_82 = F_62 ( V_2 , & V_138 , true ) ;
if ( V_82 < 0 )
return V_82 ;
V_27 -> V_144 = V_82 ;
F_56 ( & V_138 , V_140 , 0 ,
F_57 (
F_58 ( V_27 -> V_9 ) ) ) ;
V_82 = F_59 ( & V_138 , V_141 ,
F_60 ( V_142 ) ,
F_61 ( V_145 ) ) ;
if ( V_82 != 0 )
goto V_104;
V_82 = F_62 ( V_2 , & V_138 , true ) ;
if ( V_82 < 0 )
goto V_104;
V_27 -> V_146 = V_82 ;
V_82 = F_1 ( V_2 ) ;
if ( V_82 != 0 )
goto V_147;
V_27 -> V_148 = 0 ;
V_27 -> V_149 = 0 ;
V_27 -> V_150 = true ;
return 0 ;
V_147:
F_63 ( V_2 , V_140 ,
V_27 -> V_146 ) ;
V_104:
F_63 ( V_2 , V_140 ,
V_27 -> V_144 ) ;
return V_82 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
int V_82 = F_4 ( V_2 ) ;
struct V_111 * V_112 ;
struct V_111 * V_113 ;
if ( V_27 -> V_150 ) {
F_63 ( V_2 , V_140 ,
V_27 -> V_146 ) ;
F_63 ( V_2 , V_140 ,
V_27 -> V_144 ) ;
V_27 -> V_150 = false ;
}
F_5 ( & V_2 -> V_8 -> V_133 ) ;
F_65 ( & V_2 -> V_8 -> V_151 ) ;
F_42 ( & V_2 -> V_8 -> V_114 ) ;
F_44 (cursor, next, &efx->ptp_data->evt_list) {
F_47 ( V_112 , & V_2 -> V_8 -> V_120 ) ;
}
F_48 ( & V_2 -> V_8 -> V_114 ) ;
return V_82 ;
}
static void F_66 ( struct V_152 * V_153 )
{
struct V_26 * V_27 =
F_67 ( V_153 , struct V_26 , V_154 ) ;
struct V_1 * V_2 = V_27 -> V_9 -> V_2 ;
struct V_155 V_156 ;
if ( F_25 ( V_2 , V_157 ) )
return;
V_156 . type = V_158 ;
V_156 . V_159 = V_27 -> V_79 ;
V_155 ( V_27 -> V_160 , & V_156 ) ;
}
static void F_68 ( struct V_152 * V_153 )
{
struct V_26 * V_8 =
F_67 ( V_153 , struct V_26 , V_153 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
struct V_17 * V_18 ;
struct V_15 V_161 ;
if ( V_8 -> V_139 ) {
F_64 ( V_2 ) ;
F_55 ( V_2 ) ;
return;
}
F_41 ( V_2 ) ;
F_69 ( & V_161 ) ;
if ( F_51 ( V_2 , & V_161 ) ||
! F_70 ( & V_8 -> V_151 ) ) {
while ( ( V_18 = F_6 ( & V_8 -> V_151 ) ) )
F_31 ( V_2 , V_18 ) ;
}
while ( ( V_18 = F_71 ( & V_161 ) ) )
F_54 ( V_2 , V_18 ) ;
}
static int F_72 ( struct V_162 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_26 * V_27 ;
int V_82 = 0 ;
unsigned int V_163 ;
V_9 -> V_164 = 0 ;
V_9 -> V_165 . V_166 = 0 ;
V_27 = F_73 ( sizeof( struct V_26 ) , V_167 ) ;
V_2 -> V_8 = V_27 ;
if ( ! V_2 -> V_8 )
return - V_168 ;
V_82 = F_74 ( V_2 , & V_27 -> V_28 , sizeof( int ) ) ;
if ( V_82 != 0 )
goto V_169;
V_27 -> V_9 = V_9 ;
F_75 ( & V_27 -> V_133 ) ;
F_75 ( & V_27 -> V_151 ) ;
V_27 -> V_170 = F_76 ( L_7 ) ;
if ( ! V_27 -> V_170 ) {
V_82 = - V_168 ;
goto V_147;
}
F_77 ( & V_27 -> V_153 , F_68 ) ;
V_27 -> V_171 . V_172 = 0 ;
V_27 -> V_171 . V_173 = V_174 ;
V_27 -> V_171 . V_175 = V_176 ;
F_78 ( & V_27 -> V_115 ) ;
F_78 ( & V_27 -> V_120 ) ;
F_79 ( & V_27 -> V_114 ) ;
for ( V_163 = 0 ; V_163 < V_177 ; V_163 ++ )
F_80 ( & V_27 -> V_178 [ V_163 ] . V_118 , & V_27 -> V_120 ) ;
V_27 -> V_179 . V_180 = V_181 ;
snprintf ( V_27 -> V_179 . V_182 ,
sizeof( V_27 -> V_179 . V_182 ) ,
L_8 , V_2 -> V_20 -> V_183 ) ;
V_27 -> V_179 . V_184 = V_185 ;
V_27 -> V_179 . V_186 = 0 ;
V_27 -> V_179 . V_187 = 0 ;
V_27 -> V_179 . V_188 = 0 ;
V_27 -> V_179 . V_189 = 1 ;
V_27 -> V_179 . V_190 = V_191 ;
V_27 -> V_179 . V_192 = V_193 ;
V_27 -> V_179 . V_194 = V_195 ;
V_27 -> V_179 . V_196 = V_197 ;
V_27 -> V_179 . V_198 = V_199 ;
V_27 -> V_160 = F_81 ( & V_27 -> V_179 ,
& V_2 -> V_200 -> V_201 ) ;
if ( F_82 ( V_27 -> V_160 ) ) {
V_82 = F_83 ( V_27 -> V_160 ) ;
goto V_202;
}
F_77 ( & V_27 -> V_154 , F_66 ) ;
V_27 -> V_203 = F_76 ( L_9 ) ;
if ( ! V_27 -> V_203 ) {
V_82 = - V_168 ;
goto V_204;
}
V_27 -> V_205 = false ;
return 0 ;
V_204:
F_84 ( V_2 -> V_8 -> V_160 ) ;
V_202:
F_85 ( V_2 -> V_8 -> V_170 ) ;
V_147:
F_86 ( V_2 , & V_27 -> V_28 ) ;
V_169:
F_87 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
return V_82 ;
}
static void F_88 ( struct V_162 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( ! V_2 -> V_8 )
return;
( void ) F_4 ( V_9 -> V_2 ) ;
F_89 ( & V_2 -> V_8 -> V_153 ) ;
F_89 ( & V_2 -> V_8 -> V_154 ) ;
F_65 ( & V_2 -> V_8 -> V_133 ) ;
F_65 ( & V_2 -> V_8 -> V_151 ) ;
F_84 ( V_2 -> V_8 -> V_160 ) ;
F_85 ( V_2 -> V_8 -> V_170 ) ;
F_85 ( V_2 -> V_8 -> V_203 ) ;
F_86 ( V_2 , & V_2 -> V_8 -> V_28 ) ;
F_87 ( V_2 -> V_8 ) ;
}
static void F_90 ( struct V_162 * V_9 ,
char * V_206 , T_2 V_98 )
{
snprintf ( V_206 , V_98 , L_10 , V_9 -> V_2 -> V_182 ) ;
}
bool F_91 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
return V_2 -> V_8 &&
V_2 -> V_8 -> V_207 &&
V_18 -> V_98 >= V_208 &&
V_18 -> V_98 <= V_209 &&
F_92 ( V_18 -> V_210 == F_61 ( V_211 ) ) &&
F_93 ( V_18 ) -> V_210 == V_141 &&
F_94 ( V_18 ) -> V_212 == F_61 ( V_143 ) ;
}
static bool F_95 ( struct V_162 * V_9 , struct V_17 * V_18 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_26 * V_27 = V_2 -> V_8 ;
struct V_123 * V_124 = (struct V_123 * ) V_18 -> V_126 ;
T_1 * V_213 , * V_214 ;
unsigned int V_215 ;
V_124 -> V_119 = V_92 + F_27 ( V_216 ) ;
if ( V_27 -> V_11 == V_217 ) {
if ( ! F_96 ( V_18 , V_218 ) ) {
return false ;
}
V_215 = F_97 ( * ( V_219 * ) & V_18 -> V_41 [ V_220 ] ) ;
if ( V_215 != V_221 ) {
return false ;
}
V_213 = V_18 -> V_41 + V_222 ;
V_214 = V_18 -> V_41 + V_222 + 3 ;
} else {
if ( ! F_96 ( V_18 , V_223 ) ) {
return false ;
}
V_215 = V_18 -> V_41 [ V_224 ] ;
if ( ( V_215 & V_225 ) != V_226 ) {
return false ;
}
V_214 = V_18 -> V_41 + V_227 + 5 ;
if ( V_27 -> V_11 == V_228 ) {
V_213 = V_18 -> V_41 + V_227 + 2 ;
} else {
V_213 = V_18 -> V_41 + V_227 + 0 ;
F_98 ( V_27 -> V_11 != V_229 ) ;
}
}
if ( F_97 ( * ( V_219 * ) & V_18 -> V_41 [ V_230 ] ) == V_143 ) {
struct V_95 * V_96 ;
V_124 -> V_131 = V_125 ;
V_96 = F_50 ( V_18 ) ;
memset ( V_96 , 0 , sizeof( * V_96 ) ) ;
F_99 ( V_231 != V_232 ) ;
F_99 ( V_233 != V_234 ) ;
V_124 -> V_128 [ 0 ] = ( V_213 [ 0 ] |
( V_213 [ 1 ] << 8 ) |
( V_213 [ 2 ] << 16 ) |
( V_214 [ 0 ] << 24 ) ) ;
V_124 -> V_128 [ 1 ] = ( V_214 [ 1 ] |
( V_214 [ 2 ] << 8 ) |
( V_18 -> V_41 [ V_231 +
V_233 - 1 ] <<
16 ) ) ;
} else {
V_124 -> V_131 = V_134 ;
}
F_100 ( & V_27 -> V_133 , V_18 ) ;
F_101 ( V_27 -> V_170 , & V_27 -> V_153 ) ;
return true ;
}
int F_102 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
F_100 ( & V_27 -> V_151 , V_18 ) ;
if ( ( F_94 ( V_18 ) -> V_212 == F_61 ( V_143 ) ) &&
( V_18 -> V_98 <= V_209 ) )
F_103 ( V_18 ) ;
F_101 ( V_27 -> V_170 , & V_27 -> V_153 ) ;
return V_235 ;
}
static int F_104 ( struct V_1 * V_2 , bool V_236 ,
unsigned int V_237 )
{
if ( ( V_236 != V_2 -> V_8 -> V_207 ) ||
( V_236 && ( V_2 -> V_8 -> V_11 != V_237 ) ) ) {
int V_82 ;
if ( V_236 ) {
if ( V_2 -> V_8 -> V_207 &&
( V_2 -> V_8 -> V_11 != V_237 ) ) {
V_2 -> V_8 -> V_207 = false ;
V_82 = F_64 ( V_2 ) ;
if ( V_82 != 0 )
return V_82 ;
}
V_2 -> V_8 -> V_11 = V_237 ;
V_82 = F_55 ( V_2 ) ;
if ( V_82 == 0 ) {
V_82 = F_25 ( V_2 ,
V_157 * 2 ) ;
if ( V_82 != 0 )
F_64 ( V_2 ) ;
}
} else {
V_82 = F_64 ( V_2 ) ;
}
if ( V_82 != 0 )
return V_82 ;
V_2 -> V_8 -> V_207 = V_236 ;
}
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_238 * V_239 )
{
bool V_236 = false ;
unsigned int V_237 ;
int V_82 ;
if ( V_239 -> V_172 )
return - V_240 ;
if ( ( V_239 -> V_173 != V_174 ) &&
( V_239 -> V_173 != V_241 ) )
return - V_242 ;
V_237 = V_2 -> V_8 -> V_11 ;
switch ( V_239 -> V_175 ) {
case V_176 :
break;
case V_243 :
case V_244 :
case V_245 :
V_239 -> V_175 = V_243 ;
V_237 = V_217 ;
V_236 = true ;
break;
case V_246 :
case V_247 :
case V_248 :
V_239 -> V_175 = V_246 ;
V_237 = V_229 ;
V_236 = true ;
break;
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
return - V_242 ;
break;
default:
return - V_242 ;
}
if ( V_239 -> V_173 != V_174 )
V_236 = true ;
V_82 = F_104 ( V_2 , V_236 , V_237 ) ;
if ( ( V_82 != 0 ) && ( V_237 == V_229 ) )
V_82 = F_104 ( V_2 , V_236 , V_228 ) ;
if ( V_82 != 0 )
return V_82 ;
V_2 -> V_8 -> V_171 = * V_239 ;
return 0 ;
}
int
F_106 ( struct V_255 * V_20 , struct V_256 * V_257 )
{
struct V_1 * V_2 = F_107 ( V_20 ) ;
struct V_26 * V_27 = V_2 -> V_8 ;
if ( ! V_27 )
return - V_258 ;
V_257 -> V_259 = ( V_260 |
V_261 |
V_262 ) ;
V_257 -> V_263 = F_108 ( V_27 -> V_160 ) ;
V_257 -> V_264 = 1 << V_174 | 1 << V_241 ;
V_257 -> V_265 = ( 1 << V_176 |
1 << V_243 |
1 << V_244 |
1 << V_245 |
1 << V_246 |
1 << V_247 |
1 << V_248 ) ;
return 0 ;
}
int F_109 ( struct V_1 * V_2 , struct V_266 * V_267 , int V_268 )
{
struct V_238 V_171 ;
int V_82 ;
if ( ! V_2 -> V_8 )
return - V_258 ;
if ( F_110 ( & V_171 , V_267 -> V_269 , sizeof( V_171 ) ) )
return - V_270 ;
V_82 = F_105 ( V_2 , & V_171 ) ;
if ( V_82 != 0 )
return V_82 ;
return F_111 ( V_267 -> V_269 , & V_171 , sizeof( V_171 ) )
? - V_270 : 0 ;
}
static void F_112 ( struct V_1 * V_2 , int V_271 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
F_11 ( V_2 , V_78 , V_2 -> V_20 ,
L_11 ,
V_27 -> V_148 , V_271 ) ;
V_27 -> V_139 = true ;
F_101 ( V_27 -> V_170 , & V_27 -> V_153 ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_116 * V_117 = NULL ;
if ( V_27 -> V_148 != 3 ) {
F_112 ( V_2 , 3 ) ;
return;
}
F_42 ( & V_27 -> V_114 ) ;
if ( ! F_43 ( & V_27 -> V_120 ) ) {
V_117 = F_114 ( & V_27 -> V_120 ,
struct V_116 , V_118 ) ;
F_115 ( & V_117 -> V_118 ) ;
V_117 -> V_127 = F_116 ( V_27 -> V_272 [ 2 ] , V_273 ) ;
V_117 -> V_129 = ( F_116 ( V_27 -> V_272 [ 2 ] ,
V_274 ) |
( F_116 ( V_27 -> V_272 [ 1 ] ,
V_274 ) << 8 ) |
( F_116 ( V_27 -> V_272 [ 0 ] ,
V_274 ) << 16 ) ) ;
V_117 -> V_130 = F_38 (
F_116 ( V_27 -> V_272 [ 0 ] , V_273 ) ,
F_116 ( V_27 -> V_272 [ 1 ] , V_273 ) ) ;
V_117 -> V_119 = V_92 + F_27 ( V_216 ) ;
F_117 ( & V_117 -> V_118 , & V_27 -> V_115 ) ;
F_101 ( V_27 -> V_170 , & V_27 -> V_153 ) ;
} else {
F_11 ( V_2 , V_136 , V_2 -> V_20 , L_12 ) ;
}
F_48 ( & V_27 -> V_114 ) ;
}
static void F_118 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_275 = F_116 ( V_27 -> V_272 [ 0 ] , V_273 ) ;
if ( V_27 -> V_148 != 1 ) {
F_112 ( V_2 , 1 ) ;
return;
}
F_11 ( V_2 , V_78 , V_2 -> V_20 , L_13 , V_275 ) ;
}
static void F_119 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( V_27 -> V_205 )
F_101 ( V_27 -> V_203 , & V_27 -> V_154 ) ;
}
void F_120 ( struct V_1 * V_2 , T_4 * V_276 )
{
struct V_26 * V_27 = V_2 -> V_8 ;
int V_275 = F_116 ( * V_276 , V_277 ) ;
if ( ! V_27 -> V_207 )
return;
if ( V_27 -> V_148 == 0 ) {
V_27 -> V_278 = V_275 ;
} else if ( V_27 -> V_278 != V_275 ) {
F_11 ( V_2 , V_78 , V_2 -> V_20 ,
L_14 , V_275 ) ;
V_27 -> V_148 = 0 ;
}
V_27 -> V_272 [ V_27 -> V_148 ++ ] = * V_276 ;
if ( ! F_121 ( * V_276 , V_279 ) ) {
switch ( V_275 ) {
case V_280 :
F_113 ( V_2 , V_27 ) ;
break;
case V_281 :
F_118 ( V_2 , V_27 ) ;
break;
case V_282 :
F_119 ( V_2 , V_27 ) ;
break;
default:
F_11 ( V_2 , V_78 , V_2 -> V_20 ,
L_15 , V_275 ) ;
break;
}
V_27 -> V_148 = 0 ;
} else if ( V_283 == V_27 -> V_148 ) {
F_11 ( V_2 , V_78 , V_2 -> V_20 ,
L_16 ) ;
V_27 -> V_148 = 0 ;
}
}
static int V_191 ( struct V_284 * V_27 , T_5 V_69 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_179 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
T_1 V_285 [ V_286 ] ;
T_6 V_287 ;
int V_82 ;
if ( V_69 > V_185 )
V_69 = V_185 ;
else if ( V_69 < - V_185 )
V_69 = - V_185 ;
V_287 = ( ( ( T_6 ) V_69 * V_288 ) >>
( V_289 + V_290 ) ) ;
F_2 ( V_285 , V_5 , V_291 ) ;
F_2 ( V_285 , V_292 , ( T_3 ) V_287 ) ;
F_2 ( V_285 , V_293 ,
( T_3 ) ( V_287 >> 32 ) ) ;
F_2 ( V_285 , V_294 , 0 ) ;
F_2 ( V_285 , V_295 , 0 ) ;
V_82 = F_3 ( V_2 , V_12 , V_285 , sizeof( V_285 ) ,
NULL , 0 , NULL ) ;
if ( V_82 != 0 )
return V_82 ;
V_8 -> V_149 = V_69 ;
return 0 ;
}
static int V_193 ( struct V_284 * V_27 , T_6 V_69 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_179 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
struct V_24 V_296 = F_122 ( V_69 ) ;
T_1 V_3 [ V_286 ] ;
F_2 ( V_3 , V_5 , V_291 ) ;
F_2 ( V_3 , V_292 , 0 ) ;
F_2 ( V_3 , V_293 , 0 ) ;
F_2 ( V_3 , V_294 , ( T_3 ) V_296 . V_36 ) ;
F_2 ( V_3 , V_295 , ( T_3 ) V_296 . V_38 ) ;
return F_3 ( V_2 , V_12 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static int V_195 ( struct V_284 * V_27 , struct V_24 * V_297 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_179 ) ;
struct V_1 * V_2 = V_8 -> V_9 -> V_2 ;
T_1 V_3 [ V_298 ] ;
T_1 V_299 [ V_300 ] ;
int V_82 ;
F_2 ( V_3 , V_5 , V_301 ) ;
V_82 = F_3 ( V_2 , V_12 , V_3 , sizeof( V_3 ) ,
V_299 , sizeof( V_299 ) , NULL ) ;
if ( V_82 != 0 )
return V_82 ;
V_297 -> V_36 = F_20 ( V_299 , V_302 ) ;
V_297 -> V_38 = F_20 ( V_299 , V_303 ) ;
return 0 ;
}
static int V_197 ( struct V_284 * V_27 ,
const struct V_24 * V_304 )
{
int V_82 ;
struct V_24 V_305 ;
struct V_24 V_69 ;
V_82 = V_195 ( V_27 , & V_305 ) ;
if ( V_82 != 0 )
return V_82 ;
V_69 = F_123 ( * V_304 , V_305 ) ;
V_82 = V_193 ( V_27 , F_124 ( & V_69 ) ) ;
if ( V_82 != 0 )
return V_82 ;
return 0 ;
}
static int V_199 ( struct V_284 * V_27 ,
struct V_306 * V_307 ,
int V_198 )
{
struct V_26 * V_8 = F_67 ( V_27 ,
struct V_26 ,
V_179 ) ;
if ( V_307 -> type != V_308 )
return - V_258 ;
V_8 -> V_205 = ! ! V_198 ;
return 0 ;
}
void F_125 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) == 0 )
V_2 -> V_309 [ V_310 ] =
& V_311 ;
}
