static inline struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
return & V_5 -> V_7 [ F_3 ( V_3 , V_8 ) ] ;
}
static struct V_9 * F_4 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
F_5 (vxlan, node, vni_head(net, id), hlist) {
if ( V_10 -> V_13 == V_3 )
return V_10 ;
}
return NULL ;
}
static int F_6 ( struct V_14 * V_15 , struct V_9 * V_10 ,
const struct V_16 * V_17 ,
T_1 V_18 , T_1 V_19 , int type , unsigned int V_20 )
{
unsigned long V_21 = V_22 ;
struct V_23 V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
bool V_29 , V_30 ;
V_26 = F_7 ( V_15 , V_18 , V_19 , type , sizeof( * V_28 ) , V_20 ) ;
if ( V_26 == NULL )
return - V_31 ;
V_28 = F_8 ( V_26 ) ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_30 = V_29 = true ;
if ( type == V_32 ) {
V_28 -> V_33 = V_34 ;
V_29 = V_17 -> V_35 != 0 ;
V_30 = ! F_9 ( V_17 -> V_36 ) ;
} else
V_28 -> V_33 = V_37 ;
V_28 -> V_38 = V_17 -> V_39 ;
V_28 -> V_40 = V_10 -> V_41 -> V_42 ;
V_28 -> V_43 = V_44 ;
V_28 -> V_45 = V_46 ;
if ( V_30 && F_10 ( V_15 , V_47 , V_48 , & V_17 -> V_36 ) )
goto V_49;
if ( V_29 && F_11 ( V_15 , V_46 , V_17 -> V_35 ) )
goto V_49;
V_24 . V_50 = F_12 ( V_21 - V_17 -> V_51 ) ;
V_24 . V_52 = 0 ;
V_24 . V_53 = F_12 ( V_21 - V_17 -> V_54 ) ;
V_24 . V_55 = 0 ;
if ( F_10 ( V_15 , V_56 , sizeof( V_24 ) , & V_24 ) )
goto V_49;
return F_13 ( V_15 , V_26 ) ;
V_49:
F_14 ( V_15 , V_26 ) ;
return - V_31 ;
}
static inline T_2 F_15 ( void )
{
return F_16 ( sizeof( struct V_27 ) )
+ F_17 ( V_48 )
+ F_17 ( sizeof( V_57 ) )
+ F_17 ( sizeof( struct V_23 ) ) ;
}
static void F_18 ( struct V_9 * V_10 ,
const struct V_16 * V_17 , int type )
{
struct V_2 * V_2 = F_19 ( V_10 -> V_41 ) ;
struct V_14 * V_15 ;
int V_58 = - V_59 ;
V_15 = F_20 ( F_15 () , V_60 ) ;
if ( V_15 == NULL )
goto V_61;
V_58 = F_6 ( V_15 , V_10 , V_17 , 0 , 0 , type , 0 ) ;
if ( V_58 < 0 ) {
F_21 ( V_58 == - V_31 ) ;
F_22 ( V_15 ) ;
goto V_61;
}
F_23 ( V_15 , V_2 , 0 , V_62 , NULL , V_60 ) ;
return;
V_61:
if ( V_58 < 0 )
F_24 ( V_2 , V_62 , V_58 ) ;
}
static void F_25 ( struct V_63 * V_41 , V_57 V_64 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_16 V_65 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_39 = V_66 ;
V_65 . V_35 = V_64 ;
F_18 ( V_10 , & V_65 , V_32 ) ;
}
static void F_27 ( struct V_9 * V_10 , const T_3 V_36 [ V_48 ] )
{
struct V_16 V_65 ;
memset ( & V_65 , 0 , sizeof V_65 ) ;
V_65 . V_39 = V_66 ;
memcpy ( V_65 . V_36 , V_36 , V_48 ) ;
F_18 ( V_10 , & V_65 , V_32 ) ;
}
static T_1 F_28 ( const unsigned char * V_67 )
{
T_4 V_68 = F_29 ( ( T_4 * ) V_67 ) ;
#ifdef F_30
V_68 >>= 16 ;
#else
V_68 <<= 16 ;
#endif
return F_31 ( V_68 , V_69 ) ;
}
static inline struct V_1 * F_32 ( struct V_9 * V_10 ,
const T_3 * V_70 )
{
return & V_10 -> V_71 [ F_28 ( V_70 ) ] ;
}
static struct V_16 * F_33 ( struct V_9 * V_10 ,
const T_3 * V_70 )
{
struct V_1 * V_72 = F_32 ( V_10 , V_70 ) ;
struct V_16 * V_65 ;
struct V_11 * V_12 ;
F_5 (f, node, head, hlist) {
if ( F_34 ( V_70 , V_65 -> V_36 ) == 0 )
return V_65 ;
}
return NULL ;
}
static int F_35 ( struct V_9 * V_10 ,
const T_3 * V_70 , V_57 V_73 ,
T_5 V_39 , T_5 V_20 )
{
struct V_16 * V_65 ;
int V_74 = 0 ;
V_65 = F_33 ( V_10 , V_70 ) ;
if ( V_65 ) {
if ( V_20 & V_75 ) {
F_36 ( V_10 -> V_41 ,
L_1 , V_70 ) ;
return - V_76 ;
}
if ( V_65 -> V_39 != V_39 ) {
V_65 -> V_39 = V_39 ;
V_65 -> V_54 = V_22 ;
V_74 = 1 ;
}
} else {
if ( ! ( V_20 & V_77 ) )
return - V_78 ;
if ( V_10 -> V_79 && V_10 -> V_80 >= V_10 -> V_79 )
return - V_81 ;
F_36 ( V_10 -> V_41 , L_2 , V_70 , & V_73 ) ;
V_65 = F_37 ( sizeof( * V_65 ) , V_60 ) ;
if ( ! V_65 )
return - V_82 ;
V_74 = 1 ;
V_65 -> V_35 = V_73 ;
V_65 -> V_39 = V_39 ;
V_65 -> V_54 = V_65 -> V_51 = V_22 ;
memcpy ( V_65 -> V_36 , V_70 , V_48 ) ;
++ V_10 -> V_80 ;
F_38 ( & V_65 -> V_83 ,
F_32 ( V_10 , V_70 ) ) ;
}
if ( V_74 )
F_18 ( V_10 , V_65 , V_84 ) ;
return 0 ;
}
static void F_39 ( struct V_9 * V_10 , struct V_16 * V_65 )
{
F_36 ( V_10 -> V_41 ,
L_3 , V_65 -> V_36 ) ;
-- V_10 -> V_80 ;
F_18 ( V_10 , V_65 , V_85 ) ;
F_40 ( & V_65 -> V_83 ) ;
F_41 ( V_65 , V_86 ) ;
}
static int F_42 ( struct V_27 * V_28 , struct V_87 * V_88 [] ,
struct V_63 * V_41 ,
const unsigned char * V_67 , T_6 V_20 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
V_57 V_73 ;
int V_58 ;
if ( ! ( V_28 -> V_38 & ( V_89 | V_90 ) ) ) {
F_43 ( L_4 ,
V_28 -> V_38 ) ;
return - V_91 ;
}
if ( V_88 [ V_46 ] == NULL )
return - V_91 ;
if ( F_44 ( V_88 [ V_46 ] ) != sizeof( V_57 ) )
return - V_92 ;
V_73 = F_45 ( V_88 [ V_46 ] ) ;
F_46 ( & V_10 -> V_93 ) ;
V_58 = F_35 ( V_10 , V_67 , V_73 , V_28 -> V_38 , V_20 ) ;
F_47 ( & V_10 -> V_93 ) ;
return V_58 ;
}
static int F_48 ( struct V_27 * V_28 , struct V_63 * V_41 ,
const unsigned char * V_67 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_16 * V_65 ;
int V_58 = - V_78 ;
F_46 ( & V_10 -> V_93 ) ;
V_65 = F_33 ( V_10 , V_67 ) ;
if ( V_65 ) {
F_39 ( V_10 , V_65 ) ;
V_58 = 0 ;
}
F_47 ( & V_10 -> V_93 ) ;
return V_58 ;
}
static int F_49 ( struct V_14 * V_15 , struct V_94 * V_95 ,
struct V_63 * V_41 , int V_96 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
unsigned int V_97 ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 ) {
struct V_16 * V_65 ;
struct V_11 * V_99 ;
int V_58 ;
F_5 (f, n, &vxlan->fdb_head[h], hlist) {
if ( V_96 < V_95 -> args [ 0 ] )
goto V_100;
V_58 = F_6 ( V_15 , V_10 , V_65 ,
F_50 ( V_95 -> V_15 ) . V_18 ,
V_95 -> V_26 -> V_101 ,
V_84 ,
V_102 ) ;
if ( V_58 < 0 )
break;
V_100:
++ V_96 ;
}
}
return V_96 ;
}
static void F_51 ( struct V_63 * V_41 ,
V_57 V_103 , const T_3 * V_104 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_16 * V_65 ;
int V_58 ;
V_65 = F_33 ( V_10 , V_104 ) ;
if ( F_52 ( V_65 ) ) {
V_65 -> V_51 = V_22 ;
if ( F_52 ( V_65 -> V_35 == V_103 ) )
return;
if ( F_53 () )
F_54 ( V_41 ,
L_5 ,
V_104 , & V_65 -> V_35 , & V_103 ) ;
V_65 -> V_35 = V_103 ;
V_65 -> V_54 = V_22 ;
} else {
F_55 ( & V_10 -> V_93 ) ;
V_58 = F_35 ( V_10 , V_104 , V_103 ,
V_90 ,
V_75 | V_77 ) ;
F_56 ( & V_10 -> V_93 ) ;
}
}
static bool F_57 ( struct V_4 * V_5 ,
const struct V_9 * V_105 )
{
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned V_97 ;
for ( V_97 = 0 ; V_97 < V_106 ; ++ V_97 )
F_58 (vxlan, node, &vn->vni_list[h], hlist) {
if ( V_10 == V_105 )
continue;
if ( ! F_59 ( V_10 -> V_41 ) )
continue;
if ( V_10 -> V_107 == V_105 -> V_107 )
return true ;
}
return false ;
}
static int F_60 ( struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_4 * V_5 = F_2 ( F_19 ( V_41 ) , V_6 ) ;
struct V_108 * V_109 = V_5 -> V_108 -> V_109 ;
struct V_110 V_111 = {
. V_112 . V_113 = V_10 -> V_107 ,
. V_114 = V_10 -> V_115 ,
} ;
int V_58 ;
if ( F_57 ( V_5 , V_10 ) )
return 0 ;
F_61 () ;
F_62 ( V_109 ) ;
V_58 = F_63 ( V_109 , & V_111 ) ;
F_64 ( V_109 ) ;
F_65 () ;
return V_58 ;
}
static int F_66 ( struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_4 * V_5 = F_2 ( F_19 ( V_41 ) , V_6 ) ;
int V_58 = 0 ;
struct V_108 * V_109 = V_5 -> V_108 -> V_109 ;
struct V_110 V_111 = {
. V_112 . V_113 = V_10 -> V_107 ,
. V_114 = V_10 -> V_115 ,
} ;
if ( F_57 ( V_5 , V_10 ) )
return 0 ;
F_61 () ;
F_62 ( V_109 ) ;
V_58 = F_67 ( V_109 , & V_111 ) ;
F_64 ( V_109 ) ;
F_65 () ;
return V_58 ;
}
static int F_68 ( struct V_108 * V_109 , struct V_14 * V_15 )
{
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_9 * V_10 ;
struct V_120 * V_121 ;
T_7 V_13 ;
int V_58 ;
F_69 ( V_15 , sizeof( struct V_122 ) ) ;
if ( ! F_70 ( V_15 , sizeof( struct V_118 ) ) )
goto error;
V_119 = (struct V_118 * ) V_15 -> V_123 ;
if ( V_119 -> V_124 != F_71 ( V_125 ) ||
( V_119 -> V_126 & F_71 ( 0xff ) ) ) {
F_36 ( V_15 -> V_41 , L_6 ,
F_72 ( V_119 -> V_124 ) , F_72 ( V_119 -> V_126 ) ) ;
goto error;
}
F_69 ( V_15 , sizeof( struct V_118 ) ) ;
V_13 = F_72 ( V_119 -> V_126 ) >> 8 ;
V_10 = F_4 ( F_73 ( V_109 ) , V_13 ) ;
if ( ! V_10 ) {
F_36 ( V_15 -> V_41 , L_7 , V_13 ) ;
goto V_127;
}
if ( ! F_70 ( V_15 , V_128 ) ) {
V_10 -> V_41 -> V_121 . V_129 ++ ;
V_10 -> V_41 -> V_121 . V_130 ++ ;
goto V_127;
}
F_74 ( V_15 ) ;
V_117 = F_75 ( V_15 ) ;
V_15 -> V_131 = F_76 ( V_15 , V_10 -> V_41 ) ;
if ( F_34 ( F_77 ( V_15 ) -> V_132 ,
V_10 -> V_41 -> V_133 ) == 0 )
goto V_127;
if ( V_10 -> V_20 & V_134 )
F_51 ( V_15 -> V_41 , V_117 -> V_135 , F_77 ( V_15 ) -> V_132 ) ;
F_78 ( V_15 , V_10 -> V_41 ) ;
F_79 ( V_15 ) ;
if ( V_15 -> V_136 != V_137 || ! V_15 -> V_138 ||
! ( V_10 -> V_41 -> V_139 & V_140 ) )
V_15 -> V_136 = V_141 ;
V_15 -> V_138 = 0 ;
V_58 = F_80 ( V_117 , V_15 ) ;
if ( F_81 ( V_58 ) ) {
if ( V_142 )
F_82 ( L_8 ,
& V_117 -> V_135 , V_117 -> V_143 ) ;
if ( V_58 > 1 ) {
++ V_10 -> V_41 -> V_121 . V_144 ;
++ V_10 -> V_41 -> V_121 . V_130 ;
goto V_127;
}
}
V_121 = F_83 ( V_10 -> V_121 ) ;
F_84 ( & V_121 -> V_145 ) ;
V_121 -> V_146 ++ ;
V_121 -> V_147 += V_15 -> V_148 ;
F_85 ( & V_121 -> V_145 ) ;
F_86 ( V_15 ) ;
return 0 ;
error:
F_87 ( V_15 , sizeof( struct V_122 ) ) ;
return 1 ;
V_127:
F_22 ( V_15 ) ;
return 0 ;
}
static int F_88 ( struct V_63 * V_41 , struct V_14 * V_15 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_149 * V_150 ;
T_3 * V_151 , * V_152 ;
V_57 V_153 , V_154 ;
struct V_155 * V_99 ;
if ( V_41 -> V_20 & V_156 )
goto V_157;
if ( ! F_70 ( V_15 , F_89 ( V_41 ) ) ) {
V_41 -> V_121 . V_158 ++ ;
goto V_157;
}
V_150 = F_90 ( V_15 ) ;
if ( ( V_150 -> V_159 != F_91 ( V_160 ) &&
V_150 -> V_159 != F_91 ( V_161 ) ) ||
V_150 -> V_162 != F_91 ( V_163 ) ||
V_150 -> V_164 != F_91 ( V_165 ) ||
V_150 -> V_166 != V_41 -> V_167 ||
V_150 -> V_168 != 4 )
goto V_157;
V_151 = ( T_3 * ) V_150 + sizeof( struct V_149 ) ;
V_152 = V_151 ;
V_151 += V_41 -> V_167 ;
memcpy ( & V_153 , V_151 , sizeof( V_153 ) ) ;
V_151 += sizeof( V_153 ) ;
V_151 += V_41 -> V_167 ;
memcpy ( & V_154 , V_151 , sizeof( V_154 ) ) ;
if ( F_92 ( V_154 ) ||
F_93 ( V_154 ) )
goto V_157;
V_99 = F_94 ( & V_169 , & V_154 , V_41 ) ;
if ( V_99 ) {
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_16 * V_65 ;
struct V_14 * V_170 ;
if ( ! ( V_99 -> V_171 & V_172 ) ) {
F_95 ( V_99 ) ;
goto V_157;
}
V_65 = F_33 ( V_10 , V_99 -> V_173 ) ;
if ( V_65 && V_65 -> V_35 == 0 ) {
F_95 ( V_99 ) ;
goto V_157;
}
V_170 = F_96 ( V_174 , V_175 , V_153 , V_41 , V_154 , V_152 ,
V_99 -> V_173 , V_152 ) ;
F_95 ( V_99 ) ;
F_74 ( V_170 ) ;
F_69 ( V_170 , F_97 ( V_170 ) ) ;
V_170 -> V_136 = V_137 ;
V_170 -> V_176 = V_177 ;
if ( F_98 ( V_170 ) == V_178 )
V_41 -> V_121 . V_179 ++ ;
} else if ( V_10 -> V_20 & V_180 )
F_25 ( V_41 , V_154 ) ;
V_157:
F_99 ( V_15 ) ;
return V_181 ;
}
static bool F_100 ( struct V_63 * V_41 , struct V_14 * V_15 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_155 * V_99 ;
struct V_116 * V_182 ;
if ( F_101 ( F_77 ( V_15 ) -> V_183 ) )
return false ;
V_99 = NULL ;
switch ( F_102 ( F_77 ( V_15 ) -> V_184 ) ) {
case V_163 :
if ( ! F_70 ( V_15 , sizeof( struct V_116 ) ) )
return false ;
V_182 = F_75 ( V_15 ) ;
V_99 = F_94 ( & V_169 , & V_182 -> V_185 , V_41 ) ;
break;
default:
return false ;
}
if ( V_99 ) {
bool V_186 ;
V_186 = F_34 ( F_77 ( V_15 ) -> V_183 , V_99 -> V_173 ) != 0 ;
if ( V_186 ) {
memcpy ( F_77 ( V_15 ) -> V_132 , F_77 ( V_15 ) -> V_183 ,
V_41 -> V_167 ) ;
memcpy ( F_77 ( V_15 ) -> V_183 , V_99 -> V_173 , V_41 -> V_167 ) ;
}
F_95 ( V_99 ) ;
return V_186 ;
} else if ( V_10 -> V_20 & V_180 )
F_25 ( V_41 , V_182 -> V_185 ) ;
return false ;
}
static inline T_3 F_103 ( const struct V_116 * V_187 ,
const struct V_14 * V_15 )
{
if ( V_15 -> V_131 == F_91 ( V_163 ) )
return V_187 -> V_143 ;
else if ( V_15 -> V_131 == F_91 ( V_188 ) )
return F_104 ( ( const struct V_189 * ) V_187 ) ;
else
return 0 ;
}
static inline T_3 F_105 ( T_3 V_143 ,
const struct V_116 * V_187 ,
const struct V_14 * V_15 )
{
T_3 V_190 = F_103 ( V_187 , V_15 ) ;
return F_106 ( V_143 , V_190 ) ;
}
static void F_107 ( struct V_14 * V_15 )
{
F_108 ( V_15 -> V_109 ) ;
}
static void F_109 ( struct V_63 * V_41 , struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( F_19 ( V_41 ) , V_6 ) ;
struct V_108 * V_109 = V_5 -> V_108 -> V_109 ;
F_110 ( V_15 ) ;
F_111 ( V_109 ) ;
V_15 -> V_109 = V_109 ;
V_15 -> V_191 = F_107 ;
}
static T_6 F_112 ( const struct V_9 * V_10 , struct V_14 * V_15 )
{
unsigned int V_192 = ( V_10 -> V_193 - V_10 -> V_194 ) + 1 ;
T_1 V_195 ;
V_195 = F_113 ( V_15 ) ;
if ( ! V_195 )
V_195 = F_114 ( V_15 -> V_123 , 2 * V_48 ,
( V_196 T_1 ) V_15 -> V_131 ) ;
return ( ( ( T_4 ) V_195 * V_192 ) >> 32 ) + V_10 -> V_194 ;
}
static T_8 F_115 ( struct V_14 * V_15 , struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_197 * V_198 ;
const struct V_116 * V_199 ;
struct V_200 * V_201 ;
struct V_116 * V_187 ;
struct V_118 * V_119 ;
struct V_122 * V_202 ;
struct V_203 V_204 ;
unsigned int V_205 = V_15 -> V_148 ;
V_57 V_206 ;
T_5 V_207 ;
T_9 V_208 = 0 ;
T_10 V_143 , V_209 ;
int V_58 ;
bool V_210 = false ;
const struct V_16 * V_65 ;
F_74 ( V_15 ) ;
V_201 = F_77 ( V_15 ) ;
if ( ( V_10 -> V_20 & V_211 ) && F_102 ( V_201 -> V_184 ) == V_175 )
return F_88 ( V_41 , V_15 ) ;
else if ( ( V_10 -> V_20 & V_212 ) && F_102 ( V_201 -> V_184 ) == V_163 )
V_210 = F_100 ( V_41 , V_15 ) ;
V_65 = F_33 ( V_10 , V_201 -> V_183 ) ;
if ( V_65 == NULL ) {
V_210 = false ;
V_206 = V_10 -> V_107 ;
if ( ! V_206 && ( V_10 -> V_20 & V_213 ) &&
! F_101 ( V_201 -> V_183 ) )
F_27 ( V_10 , V_201 -> V_183 ) ;
} else
V_206 = V_65 -> V_35 ;
if ( ! V_206 ) {
if ( V_210 ) {
F_69 ( V_15 , F_97 ( V_15 ) ) ;
V_15 -> V_136 = V_141 ;
V_15 -> V_176 = V_177 ;
if ( F_86 ( V_15 ) == V_214 ) {
struct V_120 * V_121 =
F_83 ( V_10 -> V_121 ) ;
F_84 ( & V_121 -> V_145 ) ;
V_121 -> V_215 ++ ;
V_121 -> V_216 += V_205 ;
F_85 ( & V_121 -> V_145 ) ;
} else {
V_41 -> V_121 . V_217 ++ ;
V_41 -> V_121 . V_218 ++ ;
}
return V_181 ;
}
goto V_127;
}
if ( ! V_15 -> V_138 ) {
F_116 ( V_15 ) ;
V_15 -> V_138 = 1 ;
}
if ( F_117 ( V_15 , V_219 ) )
goto V_127;
V_199 = F_75 ( V_15 ) ;
V_209 = V_10 -> V_209 ;
if ( ! V_209 && F_118 ( F_72 ( V_206 ) ) )
V_209 = 1 ;
V_143 = V_10 -> V_143 ;
if ( V_143 == 1 )
V_143 = F_103 ( V_199 , V_15 ) ;
V_207 = F_112 ( V_10 , V_15 ) ;
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_204 . V_220 = V_10 -> V_115 ;
V_204 . V_221 = F_119 ( V_143 ) ;
V_204 . V_185 = V_206 ;
V_204 . V_135 = V_10 -> V_135 ;
V_198 = F_120 ( F_19 ( V_41 ) , & V_204 ) ;
if ( F_121 ( V_198 ) ) {
F_36 ( V_41 , L_9 , & V_206 ) ;
V_41 -> V_121 . V_222 ++ ;
goto V_223;
}
if ( V_198 -> V_206 . V_41 == V_41 ) {
F_36 ( V_41 , L_10 , & V_206 ) ;
F_122 ( V_198 ) ;
V_41 -> V_121 . V_224 ++ ;
goto V_223;
}
memset ( & ( F_123 ( V_15 ) -> V_225 ) , 0 , sizeof( F_123 ( V_15 ) -> V_225 ) ) ;
F_123 ( V_15 ) -> V_20 &= ~ ( V_226 | V_227 |
V_228 ) ;
F_124 ( V_15 ) ;
F_125 ( V_15 , & V_198 -> V_206 ) ;
V_119 = (struct V_118 * ) F_87 ( V_15 , sizeof( * V_119 ) ) ;
V_119 -> V_124 = F_71 ( V_125 ) ;
V_119 -> V_126 = F_71 ( V_10 -> V_13 << 8 ) ;
F_87 ( V_15 , sizeof( * V_202 ) ) ;
F_126 ( V_15 ) ;
V_202 = F_127 ( V_15 ) ;
V_202 -> V_229 = F_91 ( V_230 ) ;
V_202 -> V_231 = F_91 ( V_207 ) ;
V_202 -> V_148 = F_91 ( V_15 -> V_148 ) ;
V_202 -> V_232 = 0 ;
F_87 ( V_15 , sizeof( * V_187 ) ) ;
F_79 ( V_15 ) ;
V_187 = F_75 ( V_15 ) ;
V_187 -> V_233 = 4 ;
V_187 -> V_234 = sizeof( struct V_116 ) >> 2 ;
V_187 -> V_235 = V_208 ;
V_187 -> V_131 = V_236 ;
V_187 -> V_143 = F_105 ( V_143 , V_199 , V_15 ) ;
V_187 -> V_185 = V_206 ;
V_187 -> V_135 = V_204 . V_135 ;
V_187 -> V_209 = V_209 ? : F_128 ( & V_198 -> V_206 ) ;
F_109 ( V_41 , V_15 ) ;
if ( V_15 -> V_136 != V_237 )
V_15 -> V_136 = V_141 ;
F_129 ( V_187 , & V_198 -> V_206 , NULL ) ;
V_58 = F_130 ( V_15 ) ;
if ( F_52 ( F_131 ( V_58 ) == 0 ) ) {
struct V_120 * V_121 = F_83 ( V_10 -> V_121 ) ;
F_84 ( & V_121 -> V_145 ) ;
V_121 -> V_215 ++ ;
V_121 -> V_216 += V_205 ;
F_85 ( & V_121 -> V_145 ) ;
} else {
V_41 -> V_121 . V_217 ++ ;
V_41 -> V_121 . V_218 ++ ;
}
return V_181 ;
V_127:
V_41 -> V_121 . V_158 ++ ;
goto V_238;
V_223:
V_41 -> V_121 . V_217 ++ ;
V_238:
F_132 ( V_15 ) ;
return V_181 ;
}
static void F_133 ( unsigned long V_239 )
{
struct V_9 * V_10 = (struct V_9 * ) V_239 ;
unsigned long V_240 = V_22 + V_241 ;
unsigned int V_97 ;
if ( ! F_59 ( V_10 -> V_41 ) )
return;
F_46 ( & V_10 -> V_93 ) ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 ) {
struct V_11 * V_242 , * V_99 ;
F_134 (p, n, &vxlan->fdb_head[h]) {
struct V_16 * V_65
= F_135 ( V_242 , struct V_16 , V_83 ) ;
unsigned long V_243 ;
if ( V_65 -> V_39 & V_89 )
continue;
V_243 = V_65 -> V_51 + V_10 -> V_244 * V_245 ;
if ( F_136 ( V_243 , V_22 ) ) {
F_36 ( V_10 -> V_41 ,
L_11 ,
V_65 -> V_36 ) ;
V_65 -> V_39 = V_66 ;
F_39 ( V_10 , V_65 ) ;
} else if ( F_137 ( V_243 , V_240 ) )
V_240 = V_243 ;
}
}
F_47 ( & V_10 -> V_93 ) ;
F_138 ( & V_10 -> V_246 , V_240 ) ;
}
static int F_139 ( struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
V_10 -> V_121 = F_140 ( struct V_120 ) ;
if ( ! V_10 -> V_121 )
return - V_82 ;
return 0 ;
}
static int F_141 ( struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
int V_58 ;
if ( V_10 -> V_107 ) {
V_58 = F_60 ( V_41 ) ;
if ( V_58 )
return V_58 ;
}
if ( V_10 -> V_244 )
F_138 ( & V_10 -> V_246 , V_22 + V_241 ) ;
return 0 ;
}
static void F_142 ( struct V_9 * V_10 )
{
unsigned V_97 ;
F_46 ( & V_10 -> V_93 ) ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 ) {
struct V_11 * V_242 , * V_99 ;
F_134 (p, n, &vxlan->fdb_head[h]) {
struct V_16 * V_65
= F_135 ( V_242 , struct V_16 , V_83 ) ;
F_39 ( V_10 , V_65 ) ;
}
}
F_47 ( & V_10 -> V_93 ) ;
}
static int F_143 ( struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
if ( V_10 -> V_107 )
F_66 ( V_41 ) ;
F_144 ( & V_10 -> V_246 ) ;
F_142 ( V_10 ) ;
return 0 ;
}
static struct V_247 * F_145 ( struct V_63 * V_41 ,
struct V_247 * V_121 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_120 V_248 , V_249 = { 0 } ;
unsigned int V_250 ;
F_146 (cpu) {
unsigned int V_251 ;
const struct V_120 * V_121
= F_147 ( V_10 -> V_121 , V_250 ) ;
do {
V_251 = F_148 ( & V_121 -> V_145 ) ;
memcpy ( & V_248 , V_121 , sizeof( V_248 ) ) ;
} while ( F_149 ( & V_121 -> V_145 , V_251 ) );
V_249 . V_216 += V_248 . V_216 ;
V_249 . V_215 += V_248 . V_215 ;
V_249 . V_147 += V_248 . V_147 ;
V_249 . V_146 += V_248 . V_146 ;
}
V_121 -> V_216 = V_249 . V_216 ;
V_121 -> V_215 = V_249 . V_215 ;
V_121 -> V_147 = V_249 . V_147 ;
V_121 -> V_146 = V_249 . V_146 ;
V_121 -> V_252 = V_41 -> V_121 . V_252 ;
V_121 -> V_129 = V_41 -> V_121 . V_129 ;
V_121 -> V_144 = V_41 -> V_121 . V_144 ;
V_121 -> V_130 = V_41 -> V_121 . V_130 ;
V_121 -> V_158 = V_41 -> V_121 . V_158 ;
V_121 -> V_222 = V_41 -> V_121 . V_222 ;
V_121 -> V_218 = V_41 -> V_121 . V_218 ;
V_121 -> V_224 = V_41 -> V_121 . V_224 ;
V_121 -> V_217 = V_41 -> V_121 . V_217 ;
return V_121 ;
}
static void F_150 ( struct V_63 * V_41 )
{
}
static void F_151 ( struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
F_152 ( V_10 -> V_121 ) ;
F_153 ( V_41 ) ;
}
static void F_154 ( struct V_63 * V_41 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
unsigned V_97 ;
int V_253 , V_254 ;
F_155 ( V_41 ) ;
F_156 ( V_41 ) ;
V_41 -> V_255 = V_128 + V_219 ;
V_41 -> V_256 = & V_257 ;
V_41 -> V_191 = F_151 ;
F_157 ( V_41 , & V_258 ) ;
V_41 -> V_259 = 0 ;
V_41 -> V_139 |= V_260 ;
V_41 -> V_139 |= V_261 ;
V_41 -> V_139 |= V_262 | V_263 ;
V_41 -> V_139 |= V_140 ;
V_41 -> V_264 |= V_262 | V_263 | V_140 ;
V_41 -> V_265 &= ~ V_266 ;
V_41 -> V_265 |= V_267 ;
F_158 ( & V_10 -> V_93 ) ;
F_159 ( & V_10 -> V_246 ) ;
V_10 -> V_246 . V_268 = F_133 ;
V_10 -> V_246 . V_123 = ( unsigned long ) V_10 ;
F_160 ( & V_253 , & V_254 ) ;
V_10 -> V_194 = V_253 ;
V_10 -> V_193 = V_254 ;
V_10 -> V_41 = V_41 ;
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 )
F_161 ( & V_10 -> V_71 [ V_97 ] ) ;
}
static int F_162 ( struct V_87 * V_88 [] , struct V_87 * V_123 [] )
{
if ( V_88 [ V_269 ] ) {
if ( F_44 ( V_88 [ V_269 ] ) != V_48 ) {
F_163 ( L_12 ) ;
return - V_91 ;
}
if ( ! F_164 ( F_165 ( V_88 [ V_269 ] ) ) ) {
F_163 ( L_13 ) ;
return - V_270 ;
}
}
if ( ! V_123 )
return - V_91 ;
if ( V_123 [ V_271 ] ) {
T_7 V_3 = F_166 ( V_123 [ V_271 ] ) ;
if ( V_3 >= V_272 )
return - V_273 ;
}
if ( V_123 [ V_274 ] ) {
V_57 V_107 = F_45 ( V_123 [ V_274 ] ) ;
if ( ! F_118 ( F_72 ( V_107 ) ) ) {
F_163 ( L_14 ) ;
return - V_270 ;
}
}
if ( V_123 [ V_275 ] ) {
const struct V_276 * V_242
= F_165 ( V_123 [ V_275 ] ) ;
if ( F_102 ( V_242 -> V_254 ) < F_102 ( V_242 -> V_253 ) ) {
F_163 ( L_15 ,
F_102 ( V_242 -> V_253 ) , F_102 ( V_242 -> V_254 ) ) ;
return - V_91 ;
}
}
return 0 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_63 * V_41 ,
struct V_87 * V_88 [] , struct V_87 * V_123 [] )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
T_7 V_13 ;
int V_58 ;
if ( ! V_123 [ V_271 ] )
return - V_91 ;
V_13 = F_166 ( V_123 [ V_271 ] ) ;
if ( F_4 ( V_2 , V_13 ) ) {
F_43 ( L_16 , V_13 ) ;
return - V_76 ;
}
V_10 -> V_13 = V_13 ;
if ( V_123 [ V_274 ] )
V_10 -> V_107 = F_45 ( V_123 [ V_274 ] ) ;
if ( V_123 [ V_277 ] )
V_10 -> V_135 = F_45 ( V_123 [ V_277 ] ) ;
if ( V_123 [ V_278 ] &&
( V_10 -> V_115 = F_166 ( V_123 [ V_278 ] ) ) ) {
struct V_63 * V_279
= F_168 ( V_2 , V_10 -> V_115 ) ;
if ( ! V_279 ) {
F_43 ( L_17 , V_10 -> V_115 ) ;
return - V_280 ;
}
if ( ! V_88 [ V_281 ] )
V_41 -> V_282 = V_279 -> V_282 - V_219 ;
V_41 -> V_255 = V_279 -> V_255 +
V_219 ;
}
if ( V_123 [ V_283 ] )
V_10 -> V_143 = F_169 ( V_123 [ V_283 ] ) ;
if ( V_123 [ V_284 ] )
V_10 -> V_209 = F_169 ( V_123 [ V_284 ] ) ;
if ( ! V_123 [ V_285 ] || F_169 ( V_123 [ V_285 ] ) )
V_10 -> V_20 |= V_134 ;
if ( V_123 [ V_286 ] )
V_10 -> V_244 = F_166 ( V_123 [ V_286 ] ) ;
else
V_10 -> V_244 = V_287 ;
if ( V_123 [ V_288 ] && F_169 ( V_123 [ V_288 ] ) )
V_10 -> V_20 |= V_211 ;
if ( V_123 [ V_289 ] && F_169 ( V_123 [ V_289 ] ) )
V_10 -> V_20 |= V_212 ;
if ( V_123 [ V_290 ] && F_169 ( V_123 [ V_290 ] ) )
V_10 -> V_20 |= V_213 ;
if ( V_123 [ V_291 ] && F_169 ( V_123 [ V_291 ] ) )
V_10 -> V_20 |= V_180 ;
if ( V_123 [ V_292 ] )
V_10 -> V_79 = F_166 ( V_123 [ V_292 ] ) ;
if ( V_123 [ V_275 ] ) {
const struct V_276 * V_242
= F_165 ( V_123 [ V_275 ] ) ;
V_10 -> V_194 = F_102 ( V_242 -> V_253 ) ;
V_10 -> V_193 = F_102 ( V_242 -> V_254 ) ;
}
V_58 = F_170 ( V_41 ) ;
if ( ! V_58 )
F_38 ( & V_10 -> V_83 , F_1 ( V_2 , V_10 -> V_13 ) ) ;
return V_58 ;
}
static void F_171 ( struct V_63 * V_41 , struct V_293 * V_72 )
{
struct V_9 * V_10 = F_26 ( V_41 ) ;
F_40 ( & V_10 -> V_83 ) ;
F_172 ( V_41 , V_72 ) ;
}
static T_2 F_173 ( const struct V_63 * V_41 )
{
return F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( V_57 ) ) +
F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( V_57 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( struct V_276 ) ) +
0 ;
}
static int F_174 ( struct V_14 * V_15 , const struct V_63 * V_41 )
{
const struct V_9 * V_10 = F_26 ( V_41 ) ;
struct V_276 V_294 = {
. V_253 = F_91 ( V_10 -> V_194 ) ,
. V_254 = F_91 ( V_10 -> V_193 ) ,
} ;
if ( F_175 ( V_15 , V_271 , V_10 -> V_13 ) )
goto V_49;
if ( V_10 -> V_107 && F_11 ( V_15 , V_274 , V_10 -> V_107 ) )
goto V_49;
if ( V_10 -> V_115 && F_175 ( V_15 , V_278 , V_10 -> V_115 ) )
goto V_49;
if ( V_10 -> V_135 && F_11 ( V_15 , V_277 , V_10 -> V_135 ) )
goto V_49;
if ( F_176 ( V_15 , V_284 , V_10 -> V_209 ) ||
F_176 ( V_15 , V_283 , V_10 -> V_143 ) ||
F_176 ( V_15 , V_285 ,
! ! ( V_10 -> V_20 & V_134 ) ) ||
F_176 ( V_15 , V_288 ,
! ! ( V_10 -> V_20 & V_211 ) ) ||
F_176 ( V_15 , V_289 , ! ! ( V_10 -> V_20 & V_212 ) ) ||
F_176 ( V_15 , V_290 ,
! ! ( V_10 -> V_20 & V_213 ) ) ||
F_176 ( V_15 , V_291 ,
! ! ( V_10 -> V_20 & V_180 ) ) ||
F_175 ( V_15 , V_286 , V_10 -> V_244 ) ||
F_175 ( V_15 , V_292 , V_10 -> V_79 ) )
goto V_49;
if ( F_10 ( V_15 , V_275 , sizeof( V_294 ) , & V_294 ) )
goto V_49;
return 0 ;
V_49:
return - V_31 ;
}
static T_11 int F_177 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
struct V_108 * V_109 ;
struct V_295 V_296 = {
. V_297 = V_34 ,
. V_298 . V_113 = F_71 ( V_299 ) ,
} ;
int V_300 ;
unsigned V_97 ;
V_300 = F_178 ( V_34 , V_301 , V_236 , & V_5 -> V_108 ) ;
if ( V_300 < 0 ) {
F_163 ( L_18 ) ;
return V_300 ;
}
V_109 = V_5 -> V_108 -> V_109 ;
F_179 ( V_109 , V_2 ) ;
V_296 . V_302 = F_91 ( V_230 ) ;
V_300 = F_180 ( V_5 -> V_108 , (struct V_303 * ) & V_296 ,
sizeof( V_296 ) ) ;
if ( V_300 < 0 ) {
F_163 ( L_19 ,
& V_296 . V_298 , F_102 ( V_296 . V_302 ) , V_300 ) ;
F_181 ( V_109 ) ;
V_5 -> V_108 = NULL ;
return V_300 ;
}
F_182 ( V_109 ) -> V_304 = 0 ;
F_183 ( V_109 ) -> V_305 = 1 ;
F_183 ( V_109 ) -> V_306 = F_68 ;
F_184 () ;
for ( V_97 = 0 ; V_97 < V_106 ; ++ V_97 )
F_161 ( & V_5 -> V_7 [ V_97 ] ) ;
return 0 ;
}
static T_12 void F_185 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_5 -> V_108 ) {
F_181 ( V_5 -> V_108 -> V_109 ) ;
V_5 -> V_108 = NULL ;
}
}
static int T_13 F_186 ( void )
{
int V_300 ;
F_187 ( & V_307 , sizeof( V_307 ) ) ;
V_300 = F_188 ( & V_308 ) ;
if ( V_300 )
goto V_309;
V_300 = F_189 ( & V_310 ) ;
if ( V_300 )
goto V_311;
return 0 ;
V_311:
F_190 ( & V_308 ) ;
V_309:
return V_300 ;
}
static void T_14 F_191 ( void )
{
F_192 ( & V_310 ) ;
F_190 ( & V_308 ) ;
}
