static inline bool F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
T_1 V_4 = F_2 ( F_3 ( 0 ) ) ;
* V_3 = V_4 ;
return F_4 ( V_4 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_1 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_1 V_3 ;
int V_9 ;
int V_10 ;
if ( F_7 ( V_8 < 1 || V_8 > 15 ) )
return - V_11 ;
F_8 ( & V_6 -> V_12 ) ;
F_9 ( V_2 , V_13 ) ;
V_2 -> V_6 . V_14 += 1 ;
V_2 -> V_6 . V_15 = V_7 [ 0 ] ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_10 ( F_3 ( V_9 ) , V_7 [ V_9 ] ) ;
F_11 ( F_3 ( V_9 - 1 ) ) ;
F_10 ( V_16 , V_17 ) ;
V_10 = F_12 ( F_1 ( V_2 , & V_3 ) , 10 ) ;
if ( V_10 )
V_10 = F_13 ( F_1 ( V_2 , & V_3 ) , 10 ) ;
if ( V_3 != V_18 ) {
if ( V_10 != - V_19 )
V_10 = - V_20 ;
F_14 ( L_1 ,
V_7 [ 0 ] , V_10 , V_3 , F_2 ( F_3 ( 15 ) ) ) ;
V_2 -> V_6 . V_21 += 1 ;
V_2 -> V_6 . V_22 = V_10 ;
}
V_2 -> V_6 . V_23 = V_3 ;
F_15 ( V_2 , V_13 ) ;
F_16 ( & V_6 -> V_12 ) ;
return V_10 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_26 ;
V_7 [ 1 ] = V_25 -> V_27 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_28 ;
V_7 [ 1 ] = V_25 -> V_27 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_29 ;
if ( ! F_20 () || F_21 ( V_2 ) )
V_7 [ 1 ] = 0 ;
else
V_7 [ 1 ] = V_30 | V_31 ;
return F_5 ( V_6 , V_7 , F_22 ( V_7 ) ) ;
}
static int F_23 ( struct V_5 * V_6 )
{
T_1 V_7 [ 1 ] ;
V_7 [ 0 ] = V_32 ;
return F_5 ( V_6 , V_7 , 1 ) ;
}
static int F_24 ( struct V_5 * V_6 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_33 ;
V_7 [ 1 ] = 0 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_25 ( struct V_5 * V_6 , T_1 V_34 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_35 ;
V_7 [ 1 ] = V_34 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_24 * V_25 ,
T_2 V_36 )
{
struct V_37 * V_38 = V_6 -> V_39 -> V_40 ;
void * V_41 = V_6 -> V_41 ;
struct V_42 * V_43 ;
struct V_44 V_45 ;
T_3 V_8 ;
V_43 = V_25 -> V_46 + V_25 -> V_47 ;
if ( V_25 -> V_48 != V_49 &&
F_27 ( V_25 -> V_48 , V_41 ) ) {
V_43 -> V_50 = V_51 ;
( void ) F_18 ( V_6 , V_25 ) ;
F_28 ( V_25 -> V_48 , V_41 ) ;
}
V_8 = F_29 ( V_38 -> V_52 , V_38 -> V_53 , & V_45 , sizeof( V_45 ) ,
sizeof( V_45 ) * V_25 -> V_27 ) ;
if ( V_8 != sizeof( V_45 ) )
return - V_54 ;
V_45 . V_55 = V_36 ;
V_8 = F_30 ( V_38 -> V_52 , V_38 -> V_53 , & V_45 , sizeof( V_45 ) ,
sizeof( V_45 ) * V_25 -> V_27 ) ;
if ( V_8 != sizeof( V_45 ) )
return - V_54 ;
V_25 -> V_48 = V_36 ;
if ( V_36 == V_49 )
return 0 ;
F_31 ( V_36 , V_41 ) ;
V_43 -> V_56 = 0 ;
V_43 -> V_50 = V_57 ;
return F_17 ( V_6 , V_25 ) ;
}
static int F_32 ( struct V_5 * V_6 ,
struct V_24 * V_25 ,
T_4 V_55 )
{
return F_26 ( V_6 , V_25 , V_55 ) ;
}
static void F_33 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
( void ) F_26 ( V_6 , V_25 , V_49 ) ;
}
static T_4
F_34 ( struct V_5 * V_6 , T_5 V_58 )
{
const bool V_59 = ( V_58 <= V_60 ) ;
const T_4 V_61 = V_62 / 2 ;
const T_4 V_63 = V_59 ? V_61 : 0 ;
const T_4 V_64 = V_63 + V_61 ;
T_4 V_65 ;
V_65 = F_35 ( V_6 -> V_41 , V_64 , V_63 ) ;
if ( V_65 == V_64 )
V_65 = V_49 ;
F_36 ( L_2 ,
V_59 ? L_3 : L_4 , V_65 ) ;
return V_65 ;
}
static T_5 F_37 ( struct V_5 * V_6 )
{
const T_5 V_66 = F_38 () ;
T_5 V_67 ;
V_67 = F_39 ( V_6 -> V_68 ) ;
V_6 -> V_68 += V_66 ;
F_36 ( L_5 ,
V_67 , V_6 -> V_68 , V_66 ) ;
return V_67 ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_69 * V_45 ;
V_45 = V_25 -> V_46 + V_25 -> V_70 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_71 = 0 ;
V_45 -> V_72 = 0 ;
V_45 -> V_73 = V_25 -> V_27 ;
V_45 -> V_74 = V_25 -> V_75 ;
V_45 -> V_76 = V_77 ;
V_45 -> V_58 = V_25 -> V_58 ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_78 * V_79 ;
struct V_80 * V_81 = V_25 -> V_82 ;
struct V_44 V_45 ;
struct V_37 * V_38 ;
unsigned int V_83 ;
T_1 V_84 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_85 = V_86 | V_87 ;
V_45 . V_73 = V_25 -> V_27 ;
V_45 . V_58 = V_25 -> V_58 ;
V_45 . V_55 = V_25 -> V_48 ;
F_42 (engine, dev_priv, client->engines, tmp) {
struct V_88 * V_89 = & V_81 -> V_79 [ V_79 -> V_65 ] ;
T_5 V_90 = V_79 -> V_91 ;
struct V_92 * V_93 = & V_45 . V_93 [ V_90 ] ;
if ( ! V_89 -> V_94 )
break;
V_93 -> V_95 = F_43 ( V_89 -> V_96 ) ;
V_93 -> V_97 =
F_44 ( V_89 -> V_94 ) + V_98 * V_99 ;
V_93 -> V_73 = ( V_25 -> V_27 << V_100 ) |
( V_90 << V_101 ) ;
V_93 -> V_102 = F_44 ( V_89 -> V_103 -> V_104 ) ;
V_93 -> V_105 = V_93 -> V_102 + V_89 -> V_103 -> V_106 - 1 ;
V_93 -> V_107 = V_93 -> V_102 ;
V_93 -> V_108 = 0 ;
V_45 . V_109 |= ( 1 << V_90 ) ;
}
F_36 ( L_6 ,
V_25 -> V_110 , V_45 . V_109 ) ;
F_7 ( V_45 . V_109 == 0 ) ;
V_84 = F_44 ( V_25 -> V_104 ) ;
V_45 . V_111 = F_45 ( V_25 -> V_104 -> V_40 -> V_52 ) +
V_25 -> V_47 ;
V_45 . V_112 =
( V_113 ) V_25 -> V_46 + V_25 -> V_47 ;
V_45 . V_114 = V_84 + V_25 -> V_47 ;
V_45 . V_115 = V_84 + V_25 -> V_70 ;
V_45 . V_116 = V_84 + V_25 -> V_117 ;
V_45 . V_75 = V_25 -> V_75 ;
V_45 . V_118 = ( V_113 ) V_25 ;
V_38 = V_6 -> V_39 -> V_40 ;
F_30 ( V_38 -> V_52 , V_38 -> V_53 , & V_45 , sizeof( V_45 ) ,
sizeof( V_45 ) * V_25 -> V_27 ) ;
}
static void F_46 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_44 V_45 ;
struct V_37 * V_38 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_38 = V_6 -> V_39 -> V_40 ;
F_30 ( V_38 -> V_52 , V_38 -> V_53 , & V_45 , sizeof( V_45 ) ,
sizeof( V_45 ) * V_25 -> V_27 ) ;
}
int F_47 ( struct V_119 * V_120 )
{
const T_3 V_121 = sizeof( struct V_122 ) ;
struct V_24 * V_123 = V_120 -> V_124 -> V_6 . V_125 ;
struct V_69 * V_45 = V_123 -> V_46 + V_123 -> V_70 ;
T_1 V_126 ;
int V_10 ;
F_48 ( & V_123 -> V_127 ) ;
V_126 = F_49 ( V_123 -> V_128 , V_45 -> V_129 , V_123 -> V_75 ) ;
V_126 -= V_123 -> V_130 ;
if ( F_50 ( V_126 >= V_121 ) ) {
V_123 -> V_130 += V_121 ;
V_10 = 0 ;
} else {
V_123 -> V_131 ++ ;
V_10 = - V_132 ;
}
F_51 ( & V_123 -> V_127 ) ;
return V_10 ;
}
void F_52 ( struct V_119 * V_120 )
{
const T_3 V_121 = sizeof( struct V_122 ) ;
struct V_24 * V_123 = V_120 -> V_124 -> V_6 . V_125 ;
F_53 ( F_54 ( V_123 -> V_130 ) < V_121 ) ;
F_48 ( & V_123 -> V_127 ) ;
V_123 -> V_130 -= V_121 ;
F_51 ( & V_123 -> V_127 ) ;
}
static void F_55 ( struct V_24 * V_123 ,
struct V_119 * V_133 )
{
const T_3 V_121 = sizeof( struct V_122 ) ;
const T_1 V_134 = V_121 / sizeof( T_1 ) - 1 ;
struct V_78 * V_79 = V_133 -> V_79 ;
struct V_69 * V_45 ;
struct V_122 * V_135 ;
T_1 V_126 , V_136 , V_137 ;
V_45 = V_123 -> V_46 + V_123 -> V_70 ;
V_126 = F_49 ( V_123 -> V_128 , V_45 -> V_129 , V_123 -> V_75 ) ;
F_53 ( V_126 < V_121 ) ;
V_136 = V_133 -> V_136 ;
F_53 ( V_136 & 7 ) ;
V_136 >>= 3 ;
F_53 ( V_136 > V_138 ) ;
F_56 ( V_121 != 16 ) ;
F_53 ( V_123 -> V_130 < V_121 ) ;
V_137 = V_123 -> V_128 ;
F_53 ( V_137 & ( V_121 - 1 ) ) ;
V_123 -> V_128 += V_121 ;
V_123 -> V_128 &= V_123 -> V_75 - 1 ;
V_123 -> V_130 -= V_121 ;
V_135 = V_123 -> V_46 + V_137 + V_139 ;
V_135 -> V_140 = V_141 |
( V_134 << V_142 ) |
( V_79 -> V_91 << V_143 ) |
V_144 ;
V_135 -> V_95 = ( T_1 ) F_57 ( V_133 -> V_81 , V_79 ) ;
V_135 -> V_145 = V_136 << V_146 ;
V_135 -> V_147 = V_133 -> V_148 ;
}
static int F_58 ( struct V_24 * V_123 )
{
struct V_69 * V_45 ;
union V_149 V_150 , V_151 , V_152 ;
union V_149 * V_153 ;
int V_154 = 2 , V_10 = - V_132 ;
V_45 = V_123 -> V_46 + V_123 -> V_70 ;
V_45 -> V_136 = V_123 -> V_128 ;
V_150 . V_50 = V_57 ;
V_150 . V_56 = V_123 -> V_56 ;
V_151 . V_50 = V_57 ;
V_151 . V_56 = V_123 -> V_56 + 1 ;
if ( V_151 . V_56 == 0 )
V_151 . V_56 = 1 ;
V_153 = V_123 -> V_46 + V_123 -> V_47 ;
while ( V_154 -- ) {
V_152 . V_155 = F_59 ( ( V_156 * ) V_153 ,
V_150 . V_155 , V_151 . V_155 ) ;
if ( V_152 . V_155 == V_150 . V_155 ) {
V_123 -> V_56 = V_151 . V_56 ;
V_10 = 0 ;
break;
}
if ( V_152 . V_50 == V_51 )
break;
F_14 ( L_7 ,
V_150 . V_56 , V_152 . V_56 ) ;
V_150 . V_56 = V_152 . V_56 ;
V_151 . V_56 = V_152 . V_56 + 1 ;
if ( V_151 . V_56 == 0 )
V_151 . V_56 = 1 ;
}
return V_10 ;
}
static void F_60 ( struct V_119 * V_133 )
{
struct V_1 * V_2 = V_133 -> V_124 ;
struct V_78 * V_79 = V_133 -> V_79 ;
unsigned int V_157 = V_79 -> V_65 ;
struct V_5 * V_6 = & V_133 -> V_124 -> V_6 ;
struct V_24 * V_25 = V_6 -> V_125 ;
int V_158 ;
V_133 -> V_159 = V_79 -> V_160 ;
V_79 -> V_160 = V_133 -> V_81 ;
F_61 ( V_133 ) ;
F_48 ( & V_25 -> V_127 ) ;
F_55 ( V_25 , V_133 ) ;
if ( F_62 ( V_133 -> V_103 -> V_104 ) )
F_63 ( V_161 ) ;
V_158 = F_58 ( V_25 ) ;
V_25 -> V_162 [ V_157 ] += 1 ;
V_25 -> V_163 = V_158 ;
if ( V_158 )
V_25 -> V_164 += 1 ;
V_6 -> V_162 [ V_157 ] += 1 ;
V_6 -> V_165 [ V_157 ] = V_133 -> V_148 ;
F_51 ( & V_25 -> V_127 ) ;
}
static struct V_166 * F_64 ( struct V_5 * V_6 , T_1 V_106 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_167 * V_168 ;
struct V_166 * V_104 ;
int V_10 ;
V_168 = F_65 ( & V_2 -> V_169 , V_106 ) ;
if ( F_66 ( V_168 ) )
return F_67 ( V_168 ) ;
V_104 = F_68 ( V_168 , & V_2 -> V_170 . V_171 , NULL ) ;
if ( F_66 ( V_104 ) )
goto V_172;
V_10 = F_69 ( V_104 , 0 , V_99 ,
V_173 | V_174 | V_175 ) ;
if ( V_10 ) {
V_104 = F_70 ( V_10 ) ;
goto V_172;
}
F_10 ( V_176 , V_177 ) ;
return V_104 ;
V_172:
F_71 ( V_168 ) ;
return V_104 ;
}
static void
F_72 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_25 )
return;
if ( V_25 -> V_46 ) {
F_33 ( V_6 , V_25 ) ;
F_73 ( V_25 -> V_104 -> V_168 ) ;
}
F_74 ( & V_25 -> V_104 ) ;
if ( V_25 -> V_27 != V_178 ) {
F_46 ( V_6 , V_25 ) ;
F_75 ( & V_6 -> V_179 , V_25 -> V_27 ) ;
}
F_76 ( V_25 ) ;
}
static bool F_77 ( struct V_5 * V_6 , T_4 V_55 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_6 V_180 = F_78 ( V_55 ) ;
T_5 V_181 = F_2 ( V_180 ) ;
bool V_182 = ( V_181 & V_57 ) != 0 ;
bool V_183 = F_27 ( V_55 , V_6 -> V_41 ) ;
if ( V_182 == V_183 )
return true ;
F_36 ( L_8 ,
V_55 , V_180 . V_184 , V_181 ,
V_183 ? L_9 : L_10 ) ;
return false ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_24 * V_25 = V_6 -> V_125 ;
T_4 V_55 ;
int V_9 , V_172 ;
V_55 = V_25 -> V_48 ;
for ( V_9 = 0 ; V_9 < V_62 ; ++ V_9 ) {
if ( F_77 ( V_6 , V_9 ) )
continue;
V_172 = F_26 ( V_6 , V_25 , V_9 ) ;
if ( V_172 )
F_36 ( L_11 ,
V_9 , V_172 ) ;
}
V_172 = F_26 ( V_6 , V_25 , V_55 ) ;
if ( V_172 )
F_14 ( L_12 ,
V_55 , V_172 ) ;
for ( V_9 = 0 ; V_9 < V_62 ; ++ V_9 )
( void ) F_77 ( V_6 , V_9 ) ;
}
static struct V_24 *
F_80 ( struct V_1 * V_2 ,
T_5 V_110 ,
T_5 V_58 ,
struct V_80 * V_81 )
{
struct V_24 * V_25 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_166 * V_104 ;
void * V_46 ;
T_4 V_55 ;
V_25 = F_81 ( sizeof( * V_25 ) , V_185 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_82 = V_81 ;
V_25 -> V_6 = V_6 ;
V_25 -> V_110 = V_110 ;
V_25 -> V_58 = V_58 ;
V_25 -> V_48 = V_49 ;
V_25 -> V_27 = ( T_5 ) F_82 ( & V_6 -> V_179 , 0 ,
V_186 , V_185 ) ;
if ( V_25 -> V_27 >= V_186 ) {
V_25 -> V_27 = V_178 ;
goto V_172;
}
V_104 = F_64 ( V_6 , V_139 + V_187 ) ;
if ( F_66 ( V_104 ) )
goto V_172;
V_25 -> V_104 = V_104 ;
V_46 = F_83 ( V_104 -> V_168 , V_188 ) ;
if ( F_66 ( V_46 ) )
goto V_172;
V_25 -> V_46 = V_46 ;
F_84 ( & V_25 -> V_127 ) ;
V_25 -> V_117 = V_139 ;
V_25 -> V_75 = V_187 ;
V_55 = F_34 ( V_6 , V_25 -> V_58 ) ;
if ( V_55 == V_49 )
goto V_172;
V_25 -> V_47 = F_37 ( V_6 ) ;
if ( V_25 -> V_47 >= ( V_139 / 2 ) )
V_25 -> V_70 = 0 ;
else
V_25 -> V_70 = ( V_139 / 2 ) ;
F_40 ( V_6 , V_25 ) ;
F_41 ( V_6 , V_25 ) ;
if ( F_32 ( V_6 , V_25 , V_55 ) )
goto V_172;
F_36 ( L_13 ,
V_58 , V_25 , V_25 -> V_110 , V_25 -> V_27 ) ;
F_36 ( L_14 ,
V_25 -> V_48 , V_25 -> V_47 ) ;
return V_25 ;
V_172:
F_72 ( V_2 , V_25 ) ;
return NULL ;
}
static int F_85 ( struct V_189 * V_190 ,
void * V_191 ,
void * V_192 ,
T_3 V_193 )
{
if ( F_86 ( V_190 ) )
return 0 ;
return 1 ;
}
static struct V_194 * F_87 ( const char * V_195 ,
struct V_194 * V_196 ,
T_7 V_197 ,
struct V_189 * V_190 ,
int * V_198 )
{
struct V_194 * V_199 ;
* V_198 = 1 ;
if ( ! V_196 )
return NULL ;
V_199 = F_88 ( L_15 , V_197 ,
V_196 , V_190 , & V_200 ) ;
return V_199 ;
}
static int F_89 ( struct V_194 * V_194 )
{
F_90 ( V_194 ) ;
return 0 ;
}
static void F_91 ( struct V_5 * V_6 )
{
F_92 ( V_6 -> log . V_201 ) ;
}
static int F_93 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_202 * V_203 ;
T_3 V_204 , V_205 ;
V_205 = V_6 -> log . V_104 -> V_168 -> V_171 . V_106 ;
V_204 = 8 ;
V_203 = F_94 ( NULL , NULL , V_205 ,
V_204 , & V_206 , V_2 ) ;
if ( ! V_203 ) {
F_95 ( L_16 ) ;
return - V_207 ;
}
F_53 ( V_203 -> V_205 < V_205 ) ;
V_6 -> log . V_201 = V_203 ;
return 0 ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_194 * V_208 ;
int V_10 ;
V_208 = V_2 -> V_169 . V_209 -> V_210 ;
if ( ! V_208 ) {
F_95 ( L_17 ) ;
return - V_211 ;
}
V_10 = F_97 ( V_6 -> log . V_201 , L_15 , V_208 ) ;
if ( V_10 ) {
F_95 ( L_18 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static void F_98 ( struct V_5 * V_6 )
{
F_99 () ;
F_100 ( V_6 -> log . V_201 , V_6 -> log . V_104 -> V_168 -> V_171 . V_106 ) ;
F_101 ( V_6 -> log . V_201 ) ;
}
static void * F_102 ( struct V_5 * V_6 )
{
if ( ! V_6 -> log . V_201 )
return NULL ;
return F_100 ( V_6 -> log . V_201 , 0 ) ;
}
static bool
F_103 ( struct V_5 * V_6 ,
enum V_212 type , unsigned int V_213 )
{
unsigned int V_214 = V_6 -> log . V_215 [ type ] ;
bool V_216 = false ;
if ( V_213 != V_214 ) {
V_216 = true ;
V_6 -> log . V_215 [ type ] = V_213 ;
V_6 -> log . V_217 [ type ] += V_213 - V_214 ;
if ( V_213 < V_214 ) {
V_6 -> log . V_217 [ type ] += 16 ;
}
F_104 ( L_19 ) ;
}
return V_216 ;
}
static unsigned int F_105 ( enum V_212 type )
{
switch ( type ) {
case V_218 :
return ( V_219 + 1 ) * V_99 ;
case V_220 :
return ( V_221 + 1 ) * V_99 ;
case V_222 :
return ( V_223 + 1 ) * V_99 ;
default:
F_106 ( type ) ;
}
return 0 ;
}
static void F_107 ( struct V_5 * V_6 )
{
unsigned int V_224 , V_225 , V_226 , V_227 , V_213 ;
struct V_228 * V_229 , * V_230 ;
struct V_228 V_231 ;
enum V_212 type ;
void * V_232 , * V_233 ;
bool V_234 ;
if ( F_7 ( ! V_6 -> log . V_235 ) )
return;
V_229 = V_232 = V_6 -> log . V_235 ;
V_230 = V_233 = F_102 ( V_6 ) ;
V_232 += V_99 ;
V_233 += V_99 ;
for ( type = V_218 ; type < V_236 ; type ++ ) {
memcpy ( & V_231 , V_229 ,
sizeof( struct V_228 ) ) ;
V_224 = F_105 ( type ) ;
V_225 = V_231 . V_237 ;
V_226 = V_231 . V_238 ;
V_213 = V_231 . V_239 ;
V_6 -> log . V_240 [ type ] += V_231 . V_241 ;
V_234 = F_103 ( V_6 , type , V_213 ) ;
V_229 -> V_237 = V_226 ;
V_229 -> V_241 = 0 ;
V_229 ++ ;
if ( F_108 ( ! V_230 ) )
continue;
memcpy ( V_230 , & V_231 ,
sizeof( struct V_228 ) ) ;
V_230 -> V_242 = V_226 ;
V_230 ++ ;
if ( F_108 ( V_234 ) ) {
V_225 = 0 ;
V_226 = V_224 ;
} else if ( F_108 ( ( V_225 > V_224 ) ||
( V_226 > V_224 ) ) ) {
F_95 ( L_20 ) ;
V_225 = 0 ;
V_226 = V_224 ;
}
if ( V_225 > V_226 ) {
F_109 ( V_233 , V_232 , V_226 ) ;
V_227 = V_224 - V_225 ;
} else {
V_227 = V_226 - V_225 ;
}
F_109 ( V_233 + V_225 ,
V_232 + V_225 , V_227 ) ;
V_232 += V_224 ;
V_233 += V_224 ;
}
if ( V_230 )
F_98 ( V_6 ) ;
else {
F_104 ( L_21 ) ;
V_6 -> log . V_243 ++ ;
}
}
static void F_110 ( struct V_244 * V_245 )
{
struct V_1 * V_2 =
F_111 ( V_245 , struct V_1 , V_6 . log . V_246 ) ;
F_112 ( V_2 ) ;
}
static void F_113 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
F_114 ( & V_2 -> V_169 . V_247 ) ;
F_115 ( V_2 ) ;
if ( V_6 -> log . V_248 )
F_116 ( V_6 -> log . V_248 ) ;
V_6 -> log . V_248 = NULL ;
if ( V_6 -> log . V_201 )
F_91 ( V_6 ) ;
V_6 -> log . V_201 = NULL ;
if ( V_6 -> log . V_235 )
F_73 ( V_6 -> log . V_104 -> V_168 ) ;
V_6 -> log . V_235 = NULL ;
}
static int F_117 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
void * V_46 ;
int V_10 ;
F_114 ( & V_2 -> V_169 . V_247 ) ;
if ( V_124 . V_249 < 0 )
return 0 ;
if ( ! V_6 -> log . V_235 ) {
V_46 = F_83 ( V_6 -> log . V_104 -> V_168 , V_250 ) ;
if ( F_66 ( V_46 ) ) {
V_10 = F_118 ( V_46 ) ;
F_95 ( L_22 , V_10 ) ;
return V_10 ;
}
V_6 -> log . V_235 = V_46 ;
}
if ( ! V_6 -> log . V_201 ) {
V_10 = F_93 ( V_6 ) ;
if ( V_10 )
return V_10 ;
}
if ( ! V_6 -> log . V_248 ) {
F_119 ( & V_6 -> log . V_246 , F_110 ) ;
V_6 -> log . V_248 = F_120 ( L_23 ,
V_251 | V_252 ) ;
if ( V_6 -> log . V_248 == NULL ) {
F_95 ( L_24 ) ;
return - V_207 ;
}
}
return 0 ;
}
static void F_121 ( struct V_5 * V_6 )
{
struct V_166 * V_104 ;
unsigned long V_67 ;
T_5 V_106 , V_253 ;
if ( V_124 . V_249 > V_254 )
V_124 . V_249 = V_254 ;
V_106 = ( 1 + V_221 + 1 +
V_219 + 1 +
V_223 + 1 ) << V_255 ;
V_104 = V_6 -> log . V_104 ;
if ( ! V_104 ) {
if ( F_7 ( ! F_109 ( NULL , NULL , 0 ) ) ) {
V_124 . V_249 = - 1 ;
return;
}
V_104 = F_64 ( V_6 , V_106 ) ;
if ( F_66 ( V_104 ) ) {
V_124 . V_249 = - 1 ;
return;
}
V_6 -> log . V_104 = V_104 ;
if ( F_117 ( V_6 ) ) {
F_113 ( V_6 ) ;
F_74 ( & V_6 -> log . V_104 ) ;
V_124 . V_249 = - 1 ;
return;
}
}
V_253 = V_256 | V_257 |
( V_221 << V_258 ) |
( V_219 << V_259 ) |
( V_223 << V_260 ) ;
V_67 = F_44 ( V_104 ) >> V_255 ;
V_6 -> log . V_253 = ( V_67 << V_261 ) | V_253 ;
}
static int F_122 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
int V_10 ;
F_114 ( & V_2 -> V_169 . V_247 ) ;
if ( V_124 . V_249 < 0 )
return - V_11 ;
V_10 = F_117 ( V_6 ) ;
if ( V_10 )
goto V_172;
V_10 = F_96 ( V_6 ) ;
if ( V_10 )
goto V_172;
return 0 ;
V_172:
F_113 ( V_6 ) ;
V_124 . V_249 = - 1 ;
return V_10 ;
}
static void F_123 ( struct V_262 * V_263 )
{
struct V_264 * V_265 ;
T_1 V_266 , V_9 ;
V_263 -> V_267 = 500000 ;
V_263 -> V_268 = V_269 ;
for ( V_266 = 0 ; V_266 < V_270 ; V_266 ++ ) {
for ( V_9 = V_271 ; V_9 < V_272 ; V_9 ++ ) {
V_265 = & V_263 -> V_265 [ V_266 ] [ V_9 ] ;
V_265 -> V_273 = 1000000 ;
V_265 -> V_274 = 500000 ;
V_265 -> V_275 = 250000 ;
V_265 -> V_276 = 0 ;
}
}
V_263 -> V_277 = 1 ;
}
static void F_124 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_166 * V_104 ;
struct V_278 * V_279 ;
struct V_262 * V_263 ;
struct V_280 * V_281 ;
struct V_78 * V_79 ;
enum V_282 V_65 ;
struct V_283 * V_283 ;
T_1 V_106 ;
V_106 = sizeof( struct V_278 ) + sizeof( struct V_262 ) +
sizeof( struct V_280 ) +
V_284 * V_99 ;
V_104 = V_6 -> V_285 ;
if ( ! V_104 ) {
V_104 = F_64 ( V_6 , F_125 ( V_106 ) ) ;
if ( F_66 ( V_104 ) )
return;
V_6 -> V_285 = V_104 ;
}
V_283 = F_126 ( V_104 ) ;
V_279 = F_127 ( V_283 ) ;
V_79 = V_2 -> V_79 [ V_286 ] ;
V_279 -> V_287 = V_79 -> V_288 . V_289 ;
F_128 (engine, dev_priv, id)
V_279 -> V_290 [ V_79 -> V_91 ] = F_129 ( V_79 ) ;
V_263 = ( void * ) V_279 + sizeof( struct V_278 ) ;
F_123 ( V_263 ) ;
V_279 -> V_291 =
F_44 ( V_104 ) + sizeof( struct V_278 ) ;
V_281 = ( void * ) V_263 + sizeof( struct V_262 ) ;
F_128 (engine, dev_priv, id) {
V_281 -> V_292 [ V_79 -> V_91 ] . V_293 =
V_79 -> V_294 + V_295 ;
V_281 -> V_292 [ V_79 -> V_91 ] . V_296 = 0 ;
}
V_279 -> V_297 = V_279 -> V_291 +
sizeof( struct V_262 ) ;
V_279 -> V_298 = V_279 -> V_297 +
sizeof( struct V_280 ) ;
F_130 ( V_283 ) ;
}
int F_131 ( struct V_1 * V_2 )
{
const T_3 V_299 = sizeof( struct V_44 ) ;
const T_3 V_300 = V_186 * V_299 ;
const T_3 V_301 = F_132 ( V_300 , V_99 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_166 * V_104 ;
F_133 ( V_6 -> V_41 , 0 , V_62 ) ;
F_134 ( V_2 ) ;
if ( ! V_124 . V_302 )
return 0 ;
if ( V_6 -> V_39 )
return 0 ;
V_104 = F_64 ( V_6 , V_301 ) ;
if ( F_66 ( V_104 ) )
return F_118 ( V_104 ) ;
V_6 -> V_39 = V_104 ;
F_135 ( & V_6 -> V_179 ) ;
F_136 ( & V_6 -> V_12 ) ;
F_121 ( V_6 ) ;
F_124 ( V_6 ) ;
return 0 ;
}
int F_137 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_119 * V_120 ;
struct V_24 * V_25 ;
struct V_78 * V_79 ;
enum V_282 V_65 ;
V_25 = F_80 ( V_2 ,
F_138 ( V_2 ) -> V_303 ,
V_304 ,
V_2 -> V_305 ) ;
if ( ! V_25 ) {
F_95 ( L_25 ) ;
return - V_207 ;
}
V_6 -> V_125 = V_25 ;
F_19 ( V_6 , V_25 ) ;
F_79 ( V_6 ) ;
F_128 (engine, dev_priv, id) {
V_79 -> V_306 = F_60 ;
V_79 -> V_307 = NULL ;
F_139 (request,
&engine->timeline->requests, link) {
V_25 -> V_130 += sizeof( struct V_122 ) ;
if ( F_140 ( & V_120 -> V_308 ) )
F_60 ( V_120 ) ;
}
}
return 0 ;
}
void F_134 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_6 -> V_125 )
return;
F_141 ( V_2 ) ;
F_72 ( V_2 , V_6 -> V_125 ) ;
V_6 -> V_125 = NULL ;
}
void F_142 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
F_74 ( & V_6 -> V_285 ) ;
F_74 ( & V_6 -> log . V_104 ) ;
if ( V_6 -> V_39 )
F_143 ( & V_6 -> V_179 ) ;
F_74 ( & V_6 -> V_39 ) ;
}
int F_144 ( struct V_309 * V_310 )
{
struct V_1 * V_2 = F_145 ( V_310 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_80 * V_81 ;
T_1 V_7 [ 3 ] ;
if ( V_6 -> V_311 . V_312 != V_313 )
return 0 ;
F_115 ( V_2 ) ;
V_81 = V_2 -> V_305 ;
V_7 [ 0 ] = V_314 ;
V_7 [ 1 ] = V_315 ;
V_7 [ 2 ] = F_44 ( V_81 -> V_79 [ V_286 ] . V_94 ) ;
return F_5 ( V_6 , V_7 , F_22 ( V_7 ) ) ;
}
int F_146 ( struct V_309 * V_310 )
{
struct V_1 * V_2 = F_145 ( V_310 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_80 * V_81 ;
T_1 V_7 [ 3 ] ;
if ( V_6 -> V_311 . V_312 != V_313 )
return 0 ;
if ( V_124 . V_249 >= 0 )
F_147 ( V_2 ) ;
V_81 = V_2 -> V_305 ;
V_7 [ 0 ] = V_316 ;
V_7 [ 1 ] = V_317 ;
V_7 [ 2 ] = F_44 ( V_81 -> V_79 [ V_286 ] . V_94 ) ;
return F_5 ( V_6 , V_7 , F_22 ( V_7 ) ) ;
}
void F_112 ( struct V_1 * V_2 )
{
F_107 ( & V_2 -> V_6 ) ;
F_148 ( V_2 ) ;
F_23 ( & V_2 -> V_6 ) ;
F_149 ( V_2 ) ;
}
void F_150 ( struct V_1 * V_2 )
{
if ( ! V_124 . V_302 || ( V_124 . V_249 < 0 ) )
return;
F_115 ( V_2 ) ;
V_246 ( & V_2 -> V_6 . log . V_246 ) ;
F_24 ( & V_2 -> V_6 ) ;
F_112 ( V_2 ) ;
}
void F_151 ( struct V_1 * V_2 )
{
if ( ! V_124 . V_302 )
return;
F_8 ( & V_2 -> V_169 . V_247 ) ;
F_113 ( & V_2 -> V_6 ) ;
F_16 ( & V_2 -> V_169 . V_247 ) ;
}
void F_152 ( struct V_1 * V_2 )
{
if ( ! V_124 . V_302 )
return;
F_8 ( & V_2 -> V_169 . V_247 ) ;
F_122 ( & V_2 -> V_6 ) ;
F_16 ( & V_2 -> V_169 . V_247 ) ;
}
int F_153 ( struct V_1 * V_2 , T_8 V_34 )
{
union V_318 V_319 ;
int V_10 ;
V_319 . V_181 = V_34 ;
if ( V_319 . V_320 < V_321 ||
V_319 . V_320 > V_254 )
return - V_11 ;
if ( ! V_319 . V_322 && ( V_124 . V_249 < 0 ) )
return 0 ;
V_10 = F_25 ( & V_2 -> V_6 , V_319 . V_181 ) ;
if ( V_10 < 0 ) {
F_36 ( L_26 , V_10 ) ;
return V_10 ;
}
V_124 . V_249 = V_319 . V_320 ;
if ( ! V_2 -> V_6 . log . V_201 ) {
V_10 = F_122 ( & V_2 -> V_6 ) ;
if ( ! V_10 )
F_147 ( V_2 ) ;
} else if ( ! V_319 . V_322 ) {
F_150 ( V_2 ) ;
V_124 . V_249 = - 1 ;
} else {
F_147 ( V_2 ) ;
}
return V_10 ;
}
