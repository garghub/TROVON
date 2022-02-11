static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [] = {
V_6 ,
V_4 -> V_7
} ;
return F_2 ( V_2 , V_5 , F_3 ( V_5 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [] = {
V_8 ,
V_4 -> V_7
} ;
return F_2 ( V_2 , V_5 , F_3 ( V_5 ) ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 -> V_13 ;
void * V_14 = V_2 -> V_14 ;
struct V_15 * V_16 ;
struct V_17 V_18 ;
T_3 V_19 ;
V_16 = V_4 -> V_20 + V_4 -> V_21 ;
if ( V_4 -> V_22 != V_23 &&
F_6 ( V_4 -> V_22 , V_14 ) ) {
V_16 -> V_24 = V_25 ;
( void ) F_4 ( V_2 , V_4 ) ;
F_7 ( V_4 -> V_22 , V_14 ) ;
}
V_19 = F_8 ( V_11 -> V_26 , V_11 -> V_27 , & V_18 , sizeof( V_18 ) ,
sizeof( V_18 ) * V_4 -> V_7 ) ;
if ( V_19 != sizeof( V_18 ) )
return - V_28 ;
V_18 . V_29 = V_9 ;
V_19 = F_9 ( V_11 -> V_26 , V_11 -> V_27 , & V_18 , sizeof( V_18 ) ,
sizeof( V_18 ) * V_4 -> V_7 ) ;
if ( V_19 != sizeof( V_18 ) )
return - V_28 ;
V_4 -> V_22 = V_9 ;
if ( V_9 == V_23 )
return 0 ;
F_10 ( V_9 , V_14 ) ;
V_16 -> V_24 = V_30 ;
V_16 -> V_31 = V_4 -> V_32 ;
return F_1 ( V_2 , V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
( void ) F_5 ( V_2 , V_4 , V_23 ) ;
}
static T_4
F_12 ( struct V_1 * V_2 , T_5 V_33 )
{
const bool V_34 = ( V_33 <= V_35 ) ;
const T_4 V_36 = V_37 / 2 ;
const T_4 V_38 = V_34 ? V_36 : 0 ;
const T_4 V_39 = V_38 + V_36 ;
T_4 V_40 ;
V_40 = F_13 ( V_2 -> V_14 , V_39 , V_38 ) ;
if ( V_40 == V_39 )
V_40 = V_23 ;
F_14 ( L_1 ,
V_34 ? L_2 : L_3 , V_40 ) ;
return V_40 ;
}
static T_5 F_15 ( struct V_1 * V_2 )
{
const T_5 V_41 = F_16 () ;
T_5 V_42 ;
V_42 = F_17 ( V_2 -> V_43 ) ;
V_2 -> V_43 += V_41 ;
F_14 ( L_4 ,
V_42 , V_2 -> V_43 , V_41 ) ;
return V_42 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_44 * V_18 ;
V_18 = V_4 -> V_20 + V_4 -> V_45 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_46 = 0 ;
V_18 -> V_47 = 0 ;
V_18 -> V_48 = V_4 -> V_7 ;
V_18 -> V_49 = V_4 -> V_50 ;
V_18 -> V_51 = V_52 ;
V_18 -> V_33 = V_4 -> V_33 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_53 * V_54 = F_20 ( V_2 ) ;
struct V_55 * V_56 ;
struct V_57 * V_58 = V_4 -> V_59 ;
struct V_17 V_18 ;
struct V_10 * V_11 ;
unsigned int V_60 ;
T_1 V_61 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_62 = V_63 | V_64 ;
V_18 . V_48 = V_4 -> V_7 ;
V_18 . V_33 = V_4 -> V_33 ;
V_18 . V_29 = V_4 -> V_22 ;
F_21 (engine, dev_priv, client->engines, tmp) {
struct V_65 * V_66 = & V_58 -> V_56 [ V_56 -> V_40 ] ;
T_5 V_67 = V_56 -> V_68 ;
struct V_69 * V_70 = & V_18 . V_70 [ V_67 ] ;
if ( ! V_66 -> V_71 )
break;
V_70 -> V_72 = F_22 ( V_66 -> V_73 ) ;
V_70 -> V_74 =
F_23 ( V_66 -> V_71 ) + V_75 * V_76 ;
V_70 -> V_48 = ( V_4 -> V_7 << V_77 ) |
( V_67 << V_78 ) ;
V_70 -> V_79 = F_23 ( V_66 -> V_80 -> V_81 ) ;
V_70 -> V_82 = V_70 -> V_79 + V_66 -> V_80 -> V_83 - 1 ;
V_70 -> V_84 = V_70 -> V_79 ;
V_70 -> V_85 = 0 ;
V_18 . V_86 |= ( 1 << V_67 ) ;
}
F_14 ( L_5 ,
V_4 -> V_87 , V_18 . V_86 ) ;
F_24 ( V_18 . V_86 == 0 ) ;
V_61 = F_23 ( V_4 -> V_81 ) ;
V_18 . V_88 = F_25 ( V_4 -> V_81 -> V_13 -> V_26 ) +
V_4 -> V_21 ;
V_18 . V_89 =
( V_90 ) V_4 -> V_20 + V_4 -> V_21 ;
V_18 . V_91 = V_61 + V_4 -> V_21 ;
V_18 . V_92 = V_61 + V_4 -> V_45 ;
V_18 . V_93 = V_61 + V_4 -> V_94 ;
V_18 . V_50 = V_4 -> V_50 ;
V_18 . V_95 = ( V_90 ) V_4 ;
V_11 = V_2 -> V_12 -> V_13 ;
F_9 ( V_11 -> V_26 , V_11 -> V_27 , & V_18 , sizeof( V_18 ) ,
sizeof( V_18 ) * V_4 -> V_7 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_17 V_18 ;
struct V_10 * V_11 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_11 = V_2 -> V_12 -> V_13 ;
F_9 ( V_11 -> V_26 , V_11 -> V_27 , & V_18 , sizeof( V_18 ) ,
sizeof( V_18 ) * V_4 -> V_7 ) ;
}
int F_27 ( struct V_96 * V_97 )
{
const T_3 V_98 = sizeof( struct V_99 ) ;
struct V_3 * V_4 = V_97 -> V_100 -> V_2 . V_101 ;
struct V_44 * V_18 = V_4 -> V_20 +
V_4 -> V_45 ;
T_1 V_102 ;
int V_103 ;
F_28 ( & V_4 -> V_104 ) ;
V_102 = F_29 ( V_4 -> V_105 , V_18 -> V_106 , V_4 -> V_50 ) ;
V_102 -= V_4 -> V_107 ;
if ( F_30 ( V_102 >= V_98 ) ) {
V_4 -> V_107 += V_98 ;
V_103 = 0 ;
} else {
V_4 -> V_108 ++ ;
V_103 = - V_109 ;
}
F_31 ( & V_4 -> V_104 ) ;
return V_103 ;
}
void F_32 ( struct V_96 * V_97 )
{
const T_3 V_98 = sizeof( struct V_99 ) ;
struct V_3 * V_4 = V_97 -> V_100 -> V_2 . V_101 ;
F_33 ( F_34 ( V_4 -> V_107 ) < V_98 ) ;
F_28 ( & V_4 -> V_104 ) ;
V_4 -> V_107 -= V_98 ;
F_31 ( & V_4 -> V_104 ) ;
}
static void F_35 ( struct V_3 * V_4 ,
struct V_96 * V_110 )
{
const T_3 V_98 = sizeof( struct V_99 ) ;
const T_1 V_111 = V_98 / sizeof( T_1 ) - 1 ;
struct V_55 * V_56 = V_110 -> V_56 ;
struct V_44 * V_18 ;
struct V_99 * V_112 ;
T_1 V_102 , V_113 , V_114 ;
V_18 = V_4 -> V_20 + V_4 -> V_45 ;
V_102 = F_29 ( V_4 -> V_105 , V_18 -> V_106 , V_4 -> V_50 ) ;
F_33 ( V_102 < V_98 ) ;
V_113 = V_110 -> V_113 ;
F_33 ( V_113 & 7 ) ;
V_113 >>= 3 ;
F_33 ( V_113 > V_115 ) ;
F_36 ( V_98 != 16 ) ;
F_33 ( V_4 -> V_107 < V_98 ) ;
V_114 = V_4 -> V_105 ;
F_33 ( V_114 & ( V_98 - 1 ) ) ;
V_4 -> V_105 += V_98 ;
V_4 -> V_105 &= V_4 -> V_50 - 1 ;
V_4 -> V_107 -= V_98 ;
V_112 = V_4 -> V_20 + V_114 + V_116 ;
V_112 -> V_117 = V_118 |
( V_111 << V_119 ) |
( V_56 -> V_68 << V_120 ) |
V_121 ;
V_112 -> V_72 = ( T_1 ) F_37 ( V_110 -> V_58 , V_56 ) ;
V_112 -> V_122 = V_113 << V_123 ;
V_112 -> V_124 = V_110 -> V_125 ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_44 * V_18 ;
union V_126 V_127 , V_128 , V_129 ;
union V_126 * V_130 ;
int V_131 = 2 , V_103 = - V_109 ;
V_18 = V_4 -> V_20 + V_4 -> V_45 ;
V_18 -> V_113 = V_4 -> V_105 ;
V_127 . V_24 = V_30 ;
V_127 . V_31 = V_4 -> V_32 ;
V_128 . V_24 = V_30 ;
V_128 . V_31 = V_4 -> V_32 + 1 ;
if ( V_128 . V_31 == 0 )
V_128 . V_31 = 1 ;
V_130 = V_4 -> V_20 + V_4 -> V_21 ;
while ( V_131 -- ) {
V_129 . V_132 = F_39 ( ( V_133 * ) V_130 ,
V_127 . V_132 , V_128 . V_132 ) ;
if ( V_129 . V_132 == V_127 . V_132 ) {
V_4 -> V_32 = V_128 . V_31 ;
V_103 = 0 ;
break;
}
if ( V_129 . V_24 == V_25 )
break;
F_40 ( L_6 ,
V_127 . V_31 , V_129 . V_31 ) ;
V_127 . V_31 = V_129 . V_31 ;
V_128 . V_31 = V_129 . V_31 + 1 ;
if ( V_128 . V_31 == 0 )
V_128 . V_31 = 1 ;
}
return V_103 ;
}
static void F_41 ( struct V_96 * V_110 )
{
struct V_53 * V_54 = V_110 -> V_100 ;
struct V_55 * V_56 = V_110 -> V_56 ;
unsigned int V_134 = V_56 -> V_40 ;
struct V_1 * V_2 = & V_110 -> V_100 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_101 ;
int V_135 ;
F_28 ( & V_4 -> V_104 ) ;
F_35 ( V_4 , V_110 ) ;
if ( F_42 ( V_110 -> V_80 -> V_81 ) )
F_43 ( V_136 ) ;
V_135 = F_38 ( V_4 ) ;
V_4 -> V_137 [ V_134 ] += 1 ;
V_4 -> V_138 = V_135 ;
if ( V_135 )
V_4 -> V_139 += 1 ;
V_2 -> V_137 [ V_134 ] += 1 ;
V_2 -> V_140 [ V_134 ] = V_110 -> V_125 ;
F_31 ( & V_4 -> V_104 ) ;
}
static void F_44 ( struct V_96 * V_110 )
{
F_45 ( V_110 ) ;
F_41 ( V_110 ) ;
}
struct V_141 * F_46 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_53 * V_54 = F_20 ( V_2 ) ;
struct V_142 * V_143 ;
struct V_141 * V_81 ;
int V_103 ;
V_143 = F_47 ( V_54 , V_83 ) ;
if ( F_48 ( V_143 ) )
return F_49 ( V_143 ) ;
V_81 = F_50 ( V_143 , & V_54 -> V_144 . V_145 , NULL ) ;
if ( F_48 ( V_81 ) )
goto V_146;
V_103 = F_51 ( V_81 , 0 , V_76 ,
V_147 | V_148 | V_149 ) ;
if ( V_103 ) {
V_81 = F_52 ( V_103 ) ;
goto V_146;
}
return V_81 ;
V_146:
F_53 ( V_143 ) ;
return V_81 ;
}
static void
F_54 ( struct V_53 * V_54 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_54 -> V_2 ;
if ( ! V_4 )
return;
if ( V_4 -> V_20 ) {
F_11 ( V_2 , V_4 ) ;
F_55 ( V_4 -> V_81 -> V_143 ) ;
}
F_56 ( & V_4 -> V_81 ) ;
if ( V_4 -> V_7 != V_150 ) {
F_26 ( V_2 , V_4 ) ;
F_57 ( & V_2 -> V_151 , V_4 -> V_7 ) ;
}
F_58 ( V_4 ) ;
}
static bool F_59 ( struct V_1 * V_2 , T_4 V_29 )
{
struct V_53 * V_54 = F_20 ( V_2 ) ;
T_6 V_152 = F_60 ( V_29 ) ;
T_5 V_153 = F_61 ( V_152 ) ;
bool V_154 = ( V_153 & V_30 ) != 0 ;
bool V_155 = F_6 ( V_29 , V_2 -> V_14 ) ;
if ( V_154 == V_155 )
return true ;
F_14 ( L_7 ,
V_29 , V_152 . V_156 , V_153 ,
V_155 ? L_8 : L_9 ) ;
return false ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_101 ;
T_4 V_29 ;
int V_157 , V_146 ;
F_11 ( V_2 , V_4 ) ;
for ( V_157 = 0 ; V_157 < V_37 ; ++ V_157 ) {
if ( F_59 ( V_2 , V_157 ) )
continue;
V_146 = F_5 ( V_2 , V_4 , V_157 ) ;
if ( V_146 )
F_14 ( L_10 ,
V_157 , V_146 ) ;
}
V_29 = F_12 ( V_2 , V_4 -> V_33 ) ;
F_24 ( V_29 == V_23 ) ;
V_146 = F_5 ( V_2 , V_4 , V_29 ) ;
if ( V_146 )
F_40 ( L_11 ,
V_29 , V_146 ) ;
for ( V_157 = 0 ; V_157 < V_37 ; ++ V_157 )
( void ) F_59 ( V_2 , V_157 ) ;
}
static struct V_3 *
F_63 ( struct V_53 * V_54 ,
T_5 V_87 ,
T_5 V_33 ,
struct V_57 * V_58 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 = & V_54 -> V_2 ;
struct V_141 * V_81 ;
void * V_20 ;
T_4 V_29 ;
V_4 = F_64 ( sizeof( * V_4 ) , V_158 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_59 = V_58 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_87 = V_87 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_7 = ( T_5 ) F_65 ( & V_2 -> V_151 , 0 ,
V_159 , V_158 ) ;
if ( V_4 -> V_7 >= V_159 ) {
V_4 -> V_7 = V_150 ;
goto V_146;
}
V_81 = F_46 ( V_2 , V_116 + V_160 ) ;
if ( F_48 ( V_81 ) )
goto V_146;
V_4 -> V_81 = V_81 ;
V_20 = F_66 ( V_81 -> V_143 , V_161 ) ;
if ( F_48 ( V_20 ) )
goto V_146;
V_4 -> V_20 = V_20 ;
F_67 ( & V_4 -> V_104 ) ;
V_4 -> V_94 = V_116 ;
V_4 -> V_50 = V_160 ;
V_29 = F_12 ( V_2 , V_4 -> V_33 ) ;
if ( V_29 == V_23 )
goto V_146;
V_4 -> V_21 = F_15 ( V_2 ) ;
if ( V_4 -> V_21 >= ( V_116 / 2 ) )
V_4 -> V_45 = 0 ;
else
V_4 -> V_45 = ( V_116 / 2 ) ;
F_18 ( V_2 , V_4 ) ;
F_19 ( V_2 , V_4 ) ;
F_14 ( L_12 ,
V_33 , V_4 , V_4 -> V_87 , V_4 -> V_7 ) ;
F_14 ( L_13 ,
V_4 -> V_22 , V_4 -> V_21 ) ;
return V_4 ;
V_146:
F_54 ( V_54 , V_4 ) ;
return NULL ;
}
static void F_68 ( struct V_162 * V_163 )
{
struct V_164 * V_165 ;
T_1 V_166 , V_157 ;
V_163 -> V_167 = 500000 ;
V_163 -> V_168 = V_169 ;
for ( V_166 = 0 ; V_166 < V_170 ; V_166 ++ ) {
for ( V_157 = V_171 ; V_157 < V_172 ; V_157 ++ ) {
V_165 = & V_163 -> V_165 [ V_166 ] [ V_157 ] ;
V_165 -> V_173 = 1000000 ;
V_165 -> V_174 = 500000 ;
V_165 -> V_175 = 250000 ;
V_165 -> V_176 = 0 ;
}
}
V_163 -> V_177 = 1 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = F_20 ( V_2 ) ;
struct V_141 * V_81 ;
struct V_178 * V_179 ;
struct V_162 * V_163 ;
struct V_180 * V_181 ;
struct V_55 * V_56 ;
enum V_182 V_40 ;
struct V_183 * V_183 ;
T_1 V_83 ;
V_83 = sizeof( struct V_178 ) + sizeof( struct V_162 ) +
sizeof( struct V_180 ) +
V_184 * V_76 ;
V_81 = V_2 -> V_185 ;
if ( ! V_81 ) {
V_81 = F_46 ( V_2 , F_70 ( V_83 ) ) ;
if ( F_48 ( V_81 ) )
return;
V_2 -> V_185 = V_81 ;
}
V_183 = F_71 ( V_81 ) ;
V_179 = F_72 ( V_183 ) ;
V_56 = V_54 -> V_56 [ V_186 ] ;
V_179 -> V_187 = V_56 -> V_188 . V_189 ;
F_73 (engine, dev_priv, id)
V_179 -> V_190 [ V_56 -> V_68 ] = F_74 ( V_56 ) ;
V_163 = ( void * ) V_179 + sizeof( struct V_178 ) ;
F_68 ( V_163 ) ;
V_179 -> V_191 =
F_23 ( V_81 ) + sizeof( struct V_178 ) ;
V_181 = ( void * ) V_163 + sizeof( struct V_162 ) ;
F_73 (engine, dev_priv, id) {
V_181 -> V_192 [ V_56 -> V_68 ] . V_193 =
V_56 -> V_194 + V_195 ;
V_181 -> V_192 [ V_56 -> V_68 ] . V_196 = 0 ;
}
V_179 -> V_197 = V_179 -> V_191 +
sizeof( struct V_162 ) ;
V_179 -> V_198 = V_179 -> V_197 +
sizeof( struct V_180 ) ;
F_75 ( V_183 ) ;
}
int F_76 ( struct V_53 * V_54 )
{
const T_3 V_199 = sizeof( struct V_17 ) ;
const T_3 V_200 = V_159 * V_199 ;
const T_3 V_201 = F_77 ( V_200 , V_76 ) ;
struct V_1 * V_2 = & V_54 -> V_2 ;
struct V_141 * V_81 ;
if ( ! F_78 ( V_54 ) )
return 0 ;
F_79 ( V_2 -> V_14 , 0 , V_37 ) ;
F_80 ( V_54 ) ;
if ( ! V_100 . V_202 )
return 0 ;
if ( V_2 -> V_12 )
return 0 ;
V_81 = F_46 ( V_2 , V_201 ) ;
if ( F_48 ( V_81 ) )
return F_81 ( V_81 ) ;
V_2 -> V_12 = V_81 ;
F_82 ( & V_2 -> V_151 ) ;
F_83 ( V_2 ) ;
F_69 ( V_2 ) ;
V_2 -> V_101 = F_63 ( V_54 ,
F_84 ( V_54 ) -> V_203 ,
V_204 ,
V_54 -> V_205 ) ;
if ( ! V_2 -> V_101 ) {
F_85 ( L_14 ) ;
goto V_146;
}
return 0 ;
V_146:
F_86 ( V_54 ) ;
return - V_206 ;
}
static void F_87 ( struct V_3 * V_4 )
{
struct V_44 * V_18 = V_4 -> V_20 +
V_4 -> V_45 ;
V_18 -> V_106 = 0 ;
V_18 -> V_113 = 0 ;
V_4 -> V_105 = 0 ;
}
int F_88 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = & V_54 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_101 ;
struct V_55 * V_56 ;
enum V_182 V_40 ;
if ( ! V_4 )
return - V_207 ;
F_89 ( V_2 ) ;
F_87 ( V_4 ) ;
F_62 ( V_2 ) ;
F_73 (engine, dev_priv, id) {
struct V_96 * V_110 ;
V_56 -> V_208 = F_44 ;
V_56 -> V_209 = NULL ;
F_90 (rq, &engine->timeline->requests, link) {
V_4 -> V_107 += sizeof( struct V_99 ) ;
F_41 ( V_110 ) ;
}
}
return 0 ;
}
void F_80 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = & V_54 -> V_2 ;
if ( ! V_2 -> V_101 )
return;
F_91 ( V_54 ) ;
}
void F_86 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = & V_54 -> V_2 ;
struct V_3 * V_4 ;
V_4 = F_92 ( & V_2 -> V_101 ) ;
if ( ! V_4 )
return;
F_54 ( V_54 , V_4 ) ;
F_56 ( & V_2 -> V_185 ) ;
F_56 ( & V_2 -> log . V_81 ) ;
if ( V_2 -> V_12 )
F_93 ( & V_2 -> V_151 ) ;
F_56 ( & V_2 -> V_12 ) ;
}
int F_94 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = & V_54 -> V_2 ;
struct V_57 * V_58 ;
T_1 V_210 [ 3 ] ;
if ( V_2 -> V_211 . V_212 != V_213 )
return 0 ;
F_95 ( V_54 ) ;
V_58 = V_54 -> V_205 ;
V_210 [ 0 ] = V_214 ;
V_210 [ 1 ] = V_215 ;
V_210 [ 2 ] = F_23 ( V_58 -> V_56 [ V_186 ] . V_71 ) ;
return F_2 ( V_2 , V_210 , F_3 ( V_210 ) ) ;
}
int F_96 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = & V_54 -> V_2 ;
struct V_57 * V_58 ;
T_1 V_210 [ 3 ] ;
if ( V_2 -> V_211 . V_212 != V_213 )
return 0 ;
if ( V_100 . V_216 >= 0 )
F_97 ( V_54 ) ;
V_58 = V_54 -> V_205 ;
V_210 [ 0 ] = V_217 ;
V_210 [ 1 ] = V_218 ;
V_210 [ 2 ] = F_23 ( V_58 -> V_56 [ V_186 ] . V_71 ) ;
return F_2 ( V_2 , V_210 , F_3 ( V_210 ) ) ;
}
