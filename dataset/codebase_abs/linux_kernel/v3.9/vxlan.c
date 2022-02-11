static inline struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
return & V_5 -> V_7 [ F_3 ( V_3 , V_8 ) ] ;
}
static struct V_9 * F_4 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_9 * V_10 ;
F_5 (vxlan, vni_head(net, id), hlist) {
if ( V_10 -> V_11 == V_3 )
return V_10 ;
}
return NULL ;
}
static int F_6 ( struct V_12 * V_13 , struct V_9 * V_10 ,
const struct V_14 * V_15 ,
T_1 V_16 , T_1 V_17 , int type , unsigned int V_18 )
{
unsigned long V_19 = V_20 ;
struct V_21 V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
bool V_27 , V_28 ;
V_24 = F_7 ( V_13 , V_16 , V_17 , type , sizeof( * V_26 ) , V_18 ) ;
if ( V_24 == NULL )
return - V_29 ;
V_26 = F_8 ( V_24 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_28 = V_27 = true ;
if ( type == V_30 ) {
V_26 -> V_31 = V_32 ;
V_27 = V_15 -> V_33 != 0 ;
V_28 = ! F_9 ( V_15 -> V_34 ) ;
} else
V_26 -> V_31 = V_35 ;
V_26 -> V_36 = V_15 -> V_37 ;
V_26 -> V_38 = V_10 -> V_39 -> V_40 ;
V_26 -> V_41 = V_42 ;
V_26 -> V_43 = V_44 ;
if ( V_28 && F_10 ( V_13 , V_45 , V_46 , & V_15 -> V_34 ) )
goto V_47;
if ( V_27 && F_11 ( V_13 , V_44 , V_15 -> V_33 ) )
goto V_47;
V_22 . V_48 = F_12 ( V_19 - V_15 -> V_49 ) ;
V_22 . V_50 = 0 ;
V_22 . V_51 = F_12 ( V_19 - V_15 -> V_52 ) ;
V_22 . V_53 = 0 ;
if ( F_10 ( V_13 , V_54 , sizeof( V_22 ) , & V_22 ) )
goto V_47;
return F_13 ( V_13 , V_24 ) ;
V_47:
F_14 ( V_13 , V_24 ) ;
return - V_29 ;
}
static inline T_2 F_15 ( void )
{
return F_16 ( sizeof( struct V_25 ) )
+ F_17 ( V_46 )
+ F_17 ( sizeof( V_55 ) )
+ F_17 ( sizeof( struct V_21 ) ) ;
}
static void F_18 ( struct V_9 * V_10 ,
const struct V_14 * V_15 , int type )
{
struct V_2 * V_2 = F_19 ( V_10 -> V_39 ) ;
struct V_12 * V_13 ;
int V_56 = - V_57 ;
V_13 = F_20 ( F_15 () , V_58 ) ;
if ( V_13 == NULL )
goto V_59;
V_56 = F_6 ( V_13 , V_10 , V_15 , 0 , 0 , type , 0 ) ;
if ( V_56 < 0 ) {
F_21 ( V_56 == - V_29 ) ;
F_22 ( V_13 ) ;
goto V_59;
}
F_23 ( V_13 , V_2 , 0 , V_60 , NULL , V_58 ) ;
return;
V_59:
if ( V_56 < 0 )
F_24 ( V_2 , V_60 , V_56 ) ;
}
static void F_25 ( struct V_61 * V_39 , V_55 V_62 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_14 V_63 ;
memset ( & V_63 , 0 , sizeof V_63 ) ;
V_63 . V_37 = V_64 ;
V_63 . V_33 = V_62 ;
F_18 ( V_10 , & V_63 , V_30 ) ;
}
static void F_27 ( struct V_9 * V_10 , const T_3 V_34 [ V_46 ] )
{
struct V_14 V_63 ;
memset ( & V_63 , 0 , sizeof V_63 ) ;
V_63 . V_37 = V_64 ;
memcpy ( V_63 . V_34 , V_34 , V_46 ) ;
F_18 ( V_10 , & V_63 , V_30 ) ;
}
static T_1 F_28 ( const unsigned char * V_65 )
{
T_4 V_66 = F_29 ( ( T_4 * ) V_65 ) ;
#ifdef F_30
V_66 >>= 16 ;
#else
V_66 <<= 16 ;
#endif
return F_31 ( V_66 , V_67 ) ;
}
static inline struct V_1 * F_32 ( struct V_9 * V_10 ,
const T_3 * V_68 )
{
return & V_10 -> V_69 [ F_28 ( V_68 ) ] ;
}
static struct V_14 * F_33 ( struct V_9 * V_10 ,
const T_3 * V_68 )
{
struct V_1 * V_70 = F_32 ( V_10 , V_68 ) ;
struct V_14 * V_63 ;
F_5 (f, head, hlist) {
if ( F_34 ( V_68 , V_63 -> V_34 ) == 0 )
return V_63 ;
}
return NULL ;
}
static int F_35 ( struct V_9 * V_10 ,
const T_3 * V_68 , V_55 V_71 ,
T_5 V_37 , T_5 V_18 )
{
struct V_14 * V_63 ;
int V_72 = 0 ;
V_63 = F_33 ( V_10 , V_68 ) ;
if ( V_63 ) {
if ( V_18 & V_73 ) {
F_36 ( V_10 -> V_39 ,
L_1 , V_68 ) ;
return - V_74 ;
}
if ( V_63 -> V_37 != V_37 ) {
V_63 -> V_37 = V_37 ;
V_63 -> V_52 = V_20 ;
V_72 = 1 ;
}
} else {
if ( ! ( V_18 & V_75 ) )
return - V_76 ;
if ( V_10 -> V_77 && V_10 -> V_78 >= V_10 -> V_77 )
return - V_79 ;
F_36 ( V_10 -> V_39 , L_2 , V_68 , & V_71 ) ;
V_63 = F_37 ( sizeof( * V_63 ) , V_58 ) ;
if ( ! V_63 )
return - V_80 ;
V_72 = 1 ;
V_63 -> V_33 = V_71 ;
V_63 -> V_37 = V_37 ;
V_63 -> V_52 = V_63 -> V_49 = V_20 ;
memcpy ( V_63 -> V_34 , V_68 , V_46 ) ;
++ V_10 -> V_78 ;
F_38 ( & V_63 -> V_81 ,
F_32 ( V_10 , V_68 ) ) ;
}
if ( V_72 )
F_18 ( V_10 , V_63 , V_82 ) ;
return 0 ;
}
static void F_39 ( struct V_9 * V_10 , struct V_14 * V_63 )
{
F_36 ( V_10 -> V_39 ,
L_3 , V_63 -> V_34 ) ;
-- V_10 -> V_78 ;
F_18 ( V_10 , V_63 , V_83 ) ;
F_40 ( & V_63 -> V_81 ) ;
F_41 ( V_63 , V_84 ) ;
}
static int F_42 ( struct V_25 * V_26 , struct V_85 * V_86 [] ,
struct V_61 * V_39 ,
const unsigned char * V_65 , T_6 V_18 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
V_55 V_71 ;
int V_56 ;
if ( ! ( V_26 -> V_36 & ( V_87 | V_88 ) ) ) {
F_43 ( L_4 ,
V_26 -> V_36 ) ;
return - V_89 ;
}
if ( V_86 [ V_44 ] == NULL )
return - V_89 ;
if ( F_44 ( V_86 [ V_44 ] ) != sizeof( V_55 ) )
return - V_90 ;
V_71 = F_45 ( V_86 [ V_44 ] ) ;
F_46 ( & V_10 -> V_91 ) ;
V_56 = F_35 ( V_10 , V_65 , V_71 , V_26 -> V_36 , V_18 ) ;
F_47 ( & V_10 -> V_91 ) ;
return V_56 ;
}
static int F_48 ( struct V_25 * V_26 , struct V_85 * V_86 [] ,
struct V_61 * V_39 ,
const unsigned char * V_65 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_14 * V_63 ;
int V_56 = - V_76 ;
F_46 ( & V_10 -> V_91 ) ;
V_63 = F_33 ( V_10 , V_65 ) ;
if ( V_63 ) {
F_39 ( V_10 , V_63 ) ;
V_56 = 0 ;
}
F_47 ( & V_10 -> V_91 ) ;
return V_56 ;
}
static int F_49 ( struct V_12 * V_13 , struct V_92 * V_93 ,
struct V_61 * V_39 , int V_94 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 ) {
struct V_14 * V_63 ;
int V_56 ;
F_5 (f, &vxlan->fdb_head[h], hlist) {
if ( V_94 < V_93 -> args [ 0 ] )
goto V_97;
V_56 = F_6 ( V_13 , V_10 , V_63 ,
F_50 ( V_93 -> V_13 ) . V_16 ,
V_93 -> V_24 -> V_98 ,
V_82 ,
V_99 ) ;
if ( V_56 < 0 )
break;
V_97:
++ V_94 ;
}
}
return V_94 ;
}
static void F_51 ( struct V_61 * V_39 ,
V_55 V_100 , const T_3 * V_101 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_14 * V_63 ;
int V_56 ;
V_63 = F_33 ( V_10 , V_101 ) ;
if ( F_52 ( V_63 ) ) {
V_63 -> V_49 = V_20 ;
if ( F_52 ( V_63 -> V_33 == V_100 ) )
return;
if ( F_53 () )
F_54 ( V_39 ,
L_5 ,
V_101 , & V_63 -> V_33 , & V_100 ) ;
V_63 -> V_33 = V_100 ;
V_63 -> V_52 = V_20 ;
} else {
F_55 ( & V_10 -> V_91 ) ;
V_56 = F_35 ( V_10 , V_101 , V_100 ,
V_88 ,
V_73 | V_75 ) ;
F_56 ( & V_10 -> V_91 ) ;
}
}
static bool F_57 ( struct V_4 * V_5 ,
const struct V_9 * V_102 )
{
const struct V_9 * V_10 ;
unsigned V_95 ;
for ( V_95 = 0 ; V_95 < V_103 ; ++ V_95 )
F_58 (vxlan, &vn->vni_list[h], hlist) {
if ( V_10 == V_102 )
continue;
if ( ! F_59 ( V_10 -> V_39 ) )
continue;
if ( V_10 -> V_104 == V_102 -> V_104 )
return true ;
}
return false ;
}
static int F_60 ( struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( F_19 ( V_39 ) , V_6 ) ;
struct V_105 * V_106 = V_5 -> V_105 -> V_106 ;
struct V_107 V_108 = {
. V_109 . V_110 = V_10 -> V_104 ,
. V_111 = V_10 -> V_112 ,
} ;
int V_56 ;
if ( F_57 ( V_5 , V_10 ) )
return 0 ;
F_61 () ;
F_62 ( V_106 ) ;
V_56 = F_63 ( V_106 , & V_108 ) ;
F_64 ( V_106 ) ;
F_65 () ;
return V_56 ;
}
static int F_66 ( struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( F_19 ( V_39 ) , V_6 ) ;
int V_56 = 0 ;
struct V_105 * V_106 = V_5 -> V_105 -> V_106 ;
struct V_107 V_108 = {
. V_109 . V_110 = V_10 -> V_104 ,
. V_111 = V_10 -> V_112 ,
} ;
if ( F_57 ( V_5 , V_10 ) )
return 0 ;
F_61 () ;
F_62 ( V_106 ) ;
V_56 = F_67 ( V_106 , & V_108 ) ;
F_64 ( V_106 ) ;
F_65 () ;
return V_56 ;
}
static int F_68 ( struct V_105 * V_106 , struct V_12 * V_13 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_9 * V_10 ;
struct V_117 * V_118 ;
T_7 V_11 ;
int V_56 ;
F_69 ( V_13 , sizeof( struct V_119 ) ) ;
if ( ! F_70 ( V_13 , sizeof( struct V_115 ) ) )
goto error;
V_116 = (struct V_115 * ) V_13 -> V_120 ;
if ( V_116 -> V_121 != F_71 ( V_122 ) ||
( V_116 -> V_123 & F_71 ( 0xff ) ) ) {
F_36 ( V_13 -> V_39 , L_6 ,
F_72 ( V_116 -> V_121 ) , F_72 ( V_116 -> V_123 ) ) ;
goto error;
}
F_69 ( V_13 , sizeof( struct V_115 ) ) ;
V_11 = F_72 ( V_116 -> V_123 ) >> 8 ;
V_10 = F_4 ( F_73 ( V_106 ) , V_11 ) ;
if ( ! V_10 ) {
F_36 ( V_13 -> V_39 , L_7 , V_11 ) ;
goto V_124;
}
if ( ! F_70 ( V_13 , V_125 ) ) {
V_10 -> V_39 -> V_118 . V_126 ++ ;
V_10 -> V_39 -> V_118 . V_127 ++ ;
goto V_124;
}
F_74 ( V_13 ) ;
V_114 = F_75 ( V_13 ) ;
V_13 -> V_128 = F_76 ( V_13 , V_10 -> V_39 ) ;
if ( F_34 ( F_77 ( V_13 ) -> V_129 ,
V_10 -> V_39 -> V_130 ) == 0 )
goto V_124;
if ( V_10 -> V_18 & V_131 )
F_51 ( V_13 -> V_39 , V_114 -> V_132 , F_77 ( V_13 ) -> V_129 ) ;
F_78 ( V_13 , V_10 -> V_39 ) ;
F_79 ( V_13 ) ;
if ( V_13 -> V_133 != V_134 || ! V_13 -> V_135 ||
! ( V_10 -> V_39 -> V_136 & V_137 ) )
V_13 -> V_133 = V_138 ;
V_13 -> V_135 = 0 ;
V_56 = F_80 ( V_114 , V_13 ) ;
if ( F_81 ( V_56 ) ) {
if ( V_139 )
F_82 ( L_8 ,
& V_114 -> V_132 , V_114 -> V_140 ) ;
if ( V_56 > 1 ) {
++ V_10 -> V_39 -> V_118 . V_141 ;
++ V_10 -> V_39 -> V_118 . V_127 ;
goto V_124;
}
}
V_118 = F_83 ( V_10 -> V_118 ) ;
F_84 ( & V_118 -> V_142 ) ;
V_118 -> V_143 ++ ;
V_118 -> V_144 += V_13 -> V_145 ;
F_85 ( & V_118 -> V_142 ) ;
F_86 ( V_13 ) ;
return 0 ;
error:
F_87 ( V_13 , sizeof( struct V_119 ) ) ;
return 1 ;
V_124:
F_22 ( V_13 ) ;
return 0 ;
}
static int F_88 ( struct V_61 * V_39 , struct V_12 * V_13 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_146 * V_147 ;
T_3 * V_148 , * V_149 ;
V_55 V_150 , V_151 ;
struct V_152 * V_153 ;
if ( V_39 -> V_18 & V_154 )
goto V_155;
if ( ! F_70 ( V_13 , F_89 ( V_39 ) ) ) {
V_39 -> V_118 . V_156 ++ ;
goto V_155;
}
V_147 = F_90 ( V_13 ) ;
if ( ( V_147 -> V_157 != F_91 ( V_158 ) &&
V_147 -> V_157 != F_91 ( V_159 ) ) ||
V_147 -> V_160 != F_91 ( V_161 ) ||
V_147 -> V_162 != F_91 ( V_163 ) ||
V_147 -> V_164 != V_39 -> V_165 ||
V_147 -> V_166 != 4 )
goto V_155;
V_148 = ( T_3 * ) V_147 + sizeof( struct V_146 ) ;
V_149 = V_148 ;
V_148 += V_39 -> V_165 ;
memcpy ( & V_150 , V_148 , sizeof( V_150 ) ) ;
V_148 += sizeof( V_150 ) ;
V_148 += V_39 -> V_165 ;
memcpy ( & V_151 , V_148 , sizeof( V_151 ) ) ;
if ( F_92 ( V_151 ) ||
F_93 ( V_151 ) )
goto V_155;
V_153 = F_94 ( & V_167 , & V_151 , V_39 ) ;
if ( V_153 ) {
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_14 * V_63 ;
struct V_12 * V_168 ;
if ( ! ( V_153 -> V_169 & V_170 ) ) {
F_95 ( V_153 ) ;
goto V_155;
}
V_63 = F_33 ( V_10 , V_153 -> V_171 ) ;
if ( V_63 && V_63 -> V_33 == 0 ) {
F_95 ( V_153 ) ;
goto V_155;
}
V_168 = F_96 ( V_172 , V_173 , V_150 , V_39 , V_151 , V_149 ,
V_153 -> V_171 , V_149 ) ;
F_95 ( V_153 ) ;
F_74 ( V_168 ) ;
F_69 ( V_168 , F_97 ( V_168 ) ) ;
V_168 -> V_133 = V_134 ;
V_168 -> V_174 = V_175 ;
if ( F_98 ( V_168 ) == V_176 )
V_39 -> V_118 . V_177 ++ ;
} else if ( V_10 -> V_18 & V_178 )
F_25 ( V_39 , V_151 ) ;
V_155:
F_99 ( V_13 ) ;
return V_179 ;
}
static bool F_100 ( struct V_61 * V_39 , struct V_12 * V_13 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_152 * V_153 ;
struct V_113 * V_180 ;
if ( F_101 ( F_77 ( V_13 ) -> V_181 ) )
return false ;
V_153 = NULL ;
switch ( F_102 ( F_77 ( V_13 ) -> V_182 ) ) {
case V_161 :
if ( ! F_70 ( V_13 , sizeof( struct V_113 ) ) )
return false ;
V_180 = F_75 ( V_13 ) ;
V_153 = F_94 ( & V_167 , & V_180 -> V_183 , V_39 ) ;
break;
default:
return false ;
}
if ( V_153 ) {
bool V_184 ;
V_184 = F_34 ( F_77 ( V_13 ) -> V_181 , V_153 -> V_171 ) != 0 ;
if ( V_184 ) {
memcpy ( F_77 ( V_13 ) -> V_129 , F_77 ( V_13 ) -> V_181 ,
V_39 -> V_165 ) ;
memcpy ( F_77 ( V_13 ) -> V_181 , V_153 -> V_171 , V_39 -> V_165 ) ;
}
F_95 ( V_153 ) ;
return V_184 ;
} else if ( V_10 -> V_18 & V_178 )
F_25 ( V_39 , V_180 -> V_183 ) ;
return false ;
}
static inline T_3 F_103 ( const struct V_113 * V_185 ,
const struct V_12 * V_13 )
{
if ( V_13 -> V_128 == F_91 ( V_161 ) )
return V_185 -> V_140 ;
else if ( V_13 -> V_128 == F_91 ( V_186 ) )
return F_104 ( ( const struct V_187 * ) V_185 ) ;
else
return 0 ;
}
static inline T_3 F_105 ( T_3 V_140 ,
const struct V_113 * V_185 ,
const struct V_12 * V_13 )
{
T_3 V_188 = F_103 ( V_185 , V_13 ) ;
return F_106 ( V_140 , V_188 ) ;
}
static void F_107 ( struct V_12 * V_13 )
{
F_108 ( V_13 -> V_106 ) ;
}
static void F_109 ( struct V_61 * V_39 , struct V_12 * V_13 )
{
struct V_4 * V_5 = F_2 ( F_19 ( V_39 ) , V_6 ) ;
struct V_105 * V_106 = V_5 -> V_105 -> V_106 ;
F_110 ( V_13 ) ;
F_111 ( V_106 ) ;
V_13 -> V_106 = V_106 ;
V_13 -> V_189 = F_107 ;
}
static T_6 F_112 ( const struct V_9 * V_10 , struct V_12 * V_13 )
{
unsigned int V_190 = ( V_10 -> V_191 - V_10 -> V_192 ) + 1 ;
T_1 V_193 ;
V_193 = F_113 ( V_13 ) ;
if ( ! V_193 )
V_193 = F_114 ( V_13 -> V_120 , 2 * V_46 ,
( V_194 T_1 ) V_13 -> V_128 ) ;
return ( ( ( T_4 ) V_193 * V_190 ) >> 32 ) + V_10 -> V_192 ;
}
static T_8 F_115 ( struct V_12 * V_13 , struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_195 * V_196 ;
const struct V_113 * V_197 ;
struct V_198 * V_199 ;
struct V_113 * V_185 ;
struct V_115 * V_116 ;
struct V_119 * V_200 ;
struct V_201 V_202 ;
unsigned int V_203 = V_13 -> V_145 ;
V_55 V_204 ;
T_5 V_205 ;
T_9 V_206 = 0 ;
T_10 V_140 , V_207 ;
int V_56 ;
bool V_208 = false ;
const struct V_14 * V_63 ;
F_74 ( V_13 ) ;
V_199 = F_77 ( V_13 ) ;
if ( ( V_10 -> V_18 & V_209 ) && F_102 ( V_199 -> V_182 ) == V_173 )
return F_88 ( V_39 , V_13 ) ;
else if ( ( V_10 -> V_18 & V_210 ) && F_102 ( V_199 -> V_182 ) == V_161 )
V_208 = F_100 ( V_39 , V_13 ) ;
V_63 = F_33 ( V_10 , V_199 -> V_181 ) ;
if ( V_63 == NULL ) {
V_208 = false ;
V_204 = V_10 -> V_104 ;
if ( ! V_204 && ( V_10 -> V_18 & V_211 ) &&
! F_101 ( V_199 -> V_181 ) )
F_27 ( V_10 , V_199 -> V_181 ) ;
} else
V_204 = V_63 -> V_33 ;
if ( ! V_204 ) {
if ( V_208 ) {
F_69 ( V_13 , F_97 ( V_13 ) ) ;
V_13 -> V_133 = V_138 ;
V_13 -> V_174 = V_175 ;
if ( F_86 ( V_13 ) == V_212 ) {
struct V_117 * V_118 =
F_83 ( V_10 -> V_118 ) ;
F_84 ( & V_118 -> V_142 ) ;
V_118 -> V_213 ++ ;
V_118 -> V_214 += V_203 ;
F_85 ( & V_118 -> V_142 ) ;
} else {
V_39 -> V_118 . V_215 ++ ;
V_39 -> V_118 . V_216 ++ ;
}
return V_179 ;
}
goto V_124;
}
if ( ! V_13 -> V_135 ) {
F_116 ( V_13 ) ;
V_13 -> V_135 = 1 ;
}
if ( F_117 ( V_13 , V_217 ) )
goto V_124;
V_197 = F_75 ( V_13 ) ;
V_207 = V_10 -> V_207 ;
if ( ! V_207 && F_118 ( F_72 ( V_204 ) ) )
V_207 = 1 ;
V_140 = V_10 -> V_140 ;
if ( V_140 == 1 )
V_140 = F_103 ( V_197 , V_13 ) ;
V_205 = F_112 ( V_10 , V_13 ) ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_218 = V_10 -> V_112 ;
V_202 . V_219 = F_119 ( V_140 ) ;
V_202 . V_183 = V_204 ;
V_202 . V_132 = V_10 -> V_132 ;
V_196 = F_120 ( F_19 ( V_39 ) , & V_202 ) ;
if ( F_121 ( V_196 ) ) {
F_36 ( V_39 , L_9 , & V_204 ) ;
V_39 -> V_118 . V_220 ++ ;
goto V_221;
}
if ( V_196 -> V_204 . V_39 == V_39 ) {
F_36 ( V_39 , L_10 , & V_204 ) ;
F_122 ( V_196 ) ;
V_39 -> V_118 . V_222 ++ ;
goto V_221;
}
memset ( & ( F_123 ( V_13 ) -> V_223 ) , 0 , sizeof( F_123 ( V_13 ) -> V_223 ) ) ;
F_123 ( V_13 ) -> V_18 &= ~ ( V_224 | V_225 |
V_226 ) ;
F_124 ( V_13 ) ;
F_125 ( V_13 , & V_196 -> V_204 ) ;
V_116 = (struct V_115 * ) F_87 ( V_13 , sizeof( * V_116 ) ) ;
V_116 -> V_121 = F_71 ( V_122 ) ;
V_116 -> V_123 = F_71 ( V_10 -> V_11 << 8 ) ;
F_87 ( V_13 , sizeof( * V_200 ) ) ;
F_126 ( V_13 ) ;
V_200 = F_127 ( V_13 ) ;
V_200 -> V_227 = F_91 ( V_228 ) ;
V_200 -> V_229 = F_91 ( V_205 ) ;
V_200 -> V_145 = F_91 ( V_13 -> V_145 ) ;
V_200 -> V_230 = 0 ;
F_87 ( V_13 , sizeof( * V_185 ) ) ;
F_79 ( V_13 ) ;
V_185 = F_75 ( V_13 ) ;
V_185 -> V_231 = 4 ;
V_185 -> V_232 = sizeof( struct V_113 ) >> 2 ;
V_185 -> V_233 = V_206 ;
V_185 -> V_128 = V_234 ;
V_185 -> V_140 = F_105 ( V_140 , V_197 , V_13 ) ;
V_185 -> V_183 = V_204 ;
V_185 -> V_132 = V_202 . V_132 ;
V_185 -> V_207 = V_207 ? : F_128 ( & V_196 -> V_204 ) ;
F_129 ( V_13 , V_197 , & V_196 -> V_204 ) ;
F_130 ( V_13 ) ;
F_109 ( V_39 , V_13 ) ;
if ( V_13 -> V_133 != V_235 )
V_13 -> V_133 = V_138 ;
V_56 = F_131 ( V_13 ) ;
if ( F_52 ( F_132 ( V_56 ) == 0 ) ) {
struct V_117 * V_118 = F_83 ( V_10 -> V_118 ) ;
F_84 ( & V_118 -> V_142 ) ;
V_118 -> V_213 ++ ;
V_118 -> V_214 += V_203 ;
F_85 ( & V_118 -> V_142 ) ;
} else {
V_39 -> V_118 . V_215 ++ ;
V_39 -> V_118 . V_216 ++ ;
}
return V_179 ;
V_124:
V_39 -> V_118 . V_156 ++ ;
goto V_236;
V_221:
V_39 -> V_118 . V_215 ++ ;
V_236:
F_133 ( V_13 ) ;
return V_179 ;
}
static void F_134 ( unsigned long V_237 )
{
struct V_9 * V_10 = (struct V_9 * ) V_237 ;
unsigned long V_238 = V_20 + V_239 ;
unsigned int V_95 ;
if ( ! F_59 ( V_10 -> V_39 ) )
return;
F_46 ( & V_10 -> V_91 ) ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 ) {
struct V_240 * V_241 , * V_153 ;
F_135 (p, n, &vxlan->fdb_head[h]) {
struct V_14 * V_63
= F_136 ( V_241 , struct V_14 , V_81 ) ;
unsigned long V_242 ;
if ( V_63 -> V_37 & V_87 )
continue;
V_242 = V_63 -> V_49 + V_10 -> V_243 * V_244 ;
if ( F_137 ( V_242 , V_20 ) ) {
F_36 ( V_10 -> V_39 ,
L_11 ,
V_63 -> V_34 ) ;
V_63 -> V_37 = V_64 ;
F_39 ( V_10 , V_63 ) ;
} else if ( F_138 ( V_242 , V_238 ) )
V_238 = V_242 ;
}
}
F_47 ( & V_10 -> V_91 ) ;
F_139 ( & V_10 -> V_245 , V_238 ) ;
}
static int F_140 ( struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
V_10 -> V_118 = F_141 ( struct V_117 ) ;
if ( ! V_10 -> V_118 )
return - V_80 ;
return 0 ;
}
static int F_142 ( struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
int V_56 ;
if ( V_10 -> V_104 ) {
V_56 = F_60 ( V_39 ) ;
if ( V_56 )
return V_56 ;
}
if ( V_10 -> V_243 )
F_139 ( & V_10 -> V_245 , V_20 + V_239 ) ;
return 0 ;
}
static void F_143 ( struct V_9 * V_10 )
{
unsigned V_95 ;
F_46 ( & V_10 -> V_91 ) ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 ) {
struct V_240 * V_241 , * V_153 ;
F_135 (p, n, &vxlan->fdb_head[h]) {
struct V_14 * V_63
= F_136 ( V_241 , struct V_14 , V_81 ) ;
F_39 ( V_10 , V_63 ) ;
}
}
F_47 ( & V_10 -> V_91 ) ;
}
static int F_144 ( struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
if ( V_10 -> V_104 )
F_66 ( V_39 ) ;
F_145 ( & V_10 -> V_245 ) ;
F_143 ( V_10 ) ;
return 0 ;
}
static struct V_246 * F_146 ( struct V_61 * V_39 ,
struct V_246 * V_118 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_117 V_247 , V_248 = { 0 } ;
unsigned int V_249 ;
F_147 (cpu) {
unsigned int V_250 ;
const struct V_117 * V_118
= F_148 ( V_10 -> V_118 , V_249 ) ;
do {
V_250 = F_149 ( & V_118 -> V_142 ) ;
memcpy ( & V_247 , V_118 , sizeof( V_247 ) ) ;
} while ( F_150 ( & V_118 -> V_142 , V_250 ) );
V_248 . V_214 += V_247 . V_214 ;
V_248 . V_213 += V_247 . V_213 ;
V_248 . V_144 += V_247 . V_144 ;
V_248 . V_143 += V_247 . V_143 ;
}
V_118 -> V_214 = V_248 . V_214 ;
V_118 -> V_213 = V_248 . V_213 ;
V_118 -> V_144 = V_248 . V_144 ;
V_118 -> V_143 = V_248 . V_143 ;
V_118 -> V_251 = V_39 -> V_118 . V_251 ;
V_118 -> V_126 = V_39 -> V_118 . V_126 ;
V_118 -> V_141 = V_39 -> V_118 . V_141 ;
V_118 -> V_127 = V_39 -> V_118 . V_127 ;
V_118 -> V_156 = V_39 -> V_118 . V_156 ;
V_118 -> V_220 = V_39 -> V_118 . V_220 ;
V_118 -> V_216 = V_39 -> V_118 . V_216 ;
V_118 -> V_222 = V_39 -> V_118 . V_222 ;
V_118 -> V_215 = V_39 -> V_118 . V_215 ;
return V_118 ;
}
static void F_151 ( struct V_61 * V_39 )
{
}
static void F_152 ( struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
F_153 ( V_10 -> V_118 ) ;
F_154 ( V_39 ) ;
}
static void F_155 ( struct V_61 * V_39 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
unsigned V_95 ;
int V_252 , V_253 ;
F_156 ( V_39 ) ;
F_157 ( V_39 ) ;
V_39 -> V_254 = V_125 + V_217 ;
V_39 -> V_255 = & V_256 ;
V_39 -> V_189 = F_152 ;
F_158 ( V_39 , & V_257 ) ;
V_39 -> V_258 = 0 ;
V_39 -> V_136 |= V_259 ;
V_39 -> V_136 |= V_260 ;
V_39 -> V_136 |= V_261 | V_262 ;
V_39 -> V_136 |= V_137 ;
V_39 -> V_263 |= V_261 | V_262 | V_137 ;
V_39 -> V_264 &= ~ V_265 ;
V_39 -> V_264 |= V_266 ;
F_159 ( & V_10 -> V_91 ) ;
F_160 ( & V_10 -> V_245 ) ;
V_10 -> V_245 . V_267 = F_134 ;
V_10 -> V_245 . V_120 = ( unsigned long ) V_10 ;
F_161 ( & V_252 , & V_253 ) ;
V_10 -> V_192 = V_252 ;
V_10 -> V_191 = V_253 ;
V_10 -> V_39 = V_39 ;
for ( V_95 = 0 ; V_95 < V_96 ; ++ V_95 )
F_162 ( & V_10 -> V_69 [ V_95 ] ) ;
}
static int F_163 ( struct V_85 * V_86 [] , struct V_85 * V_120 [] )
{
if ( V_86 [ V_268 ] ) {
if ( F_44 ( V_86 [ V_268 ] ) != V_46 ) {
F_164 ( L_12 ) ;
return - V_89 ;
}
if ( ! F_165 ( F_166 ( V_86 [ V_268 ] ) ) ) {
F_164 ( L_13 ) ;
return - V_269 ;
}
}
if ( ! V_120 )
return - V_89 ;
if ( V_120 [ V_270 ] ) {
T_7 V_3 = F_167 ( V_120 [ V_270 ] ) ;
if ( V_3 >= V_271 )
return - V_272 ;
}
if ( V_120 [ V_273 ] ) {
V_55 V_104 = F_45 ( V_120 [ V_273 ] ) ;
if ( ! F_118 ( F_72 ( V_104 ) ) ) {
F_164 ( L_14 ) ;
return - V_269 ;
}
}
if ( V_120 [ V_274 ] ) {
const struct V_275 * V_241
= F_166 ( V_120 [ V_274 ] ) ;
if ( F_102 ( V_241 -> V_253 ) < F_102 ( V_241 -> V_252 ) ) {
F_164 ( L_15 ,
F_102 ( V_241 -> V_252 ) , F_102 ( V_241 -> V_253 ) ) ;
return - V_89 ;
}
}
return 0 ;
}
static void F_168 ( struct V_61 * V_276 ,
struct V_277 * V_278 )
{
F_169 ( V_278 -> V_231 , V_279 , sizeof( V_278 -> V_231 ) ) ;
F_169 ( V_278 -> V_280 , L_16 , sizeof( V_278 -> V_280 ) ) ;
}
static int F_170 ( struct V_2 * V_2 , struct V_61 * V_39 ,
struct V_85 * V_86 [] , struct V_85 * V_120 [] )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
T_7 V_11 ;
int V_56 ;
if ( ! V_120 [ V_270 ] )
return - V_89 ;
V_11 = F_167 ( V_120 [ V_270 ] ) ;
if ( F_4 ( V_2 , V_11 ) ) {
F_43 ( L_17 , V_11 ) ;
return - V_74 ;
}
V_10 -> V_11 = V_11 ;
if ( V_120 [ V_273 ] )
V_10 -> V_104 = F_45 ( V_120 [ V_273 ] ) ;
if ( V_120 [ V_281 ] )
V_10 -> V_132 = F_45 ( V_120 [ V_281 ] ) ;
if ( V_120 [ V_282 ] &&
( V_10 -> V_112 = F_167 ( V_120 [ V_282 ] ) ) ) {
struct V_61 * V_283
= F_171 ( V_2 , V_10 -> V_112 ) ;
if ( ! V_283 ) {
F_43 ( L_18 , V_10 -> V_112 ) ;
return - V_284 ;
}
if ( ! V_86 [ V_285 ] )
V_39 -> V_286 = V_283 -> V_286 - V_217 ;
V_39 -> V_254 = V_283 -> V_254 +
V_217 ;
}
if ( V_120 [ V_287 ] )
V_10 -> V_140 = F_172 ( V_120 [ V_287 ] ) ;
if ( V_120 [ V_288 ] )
V_10 -> V_207 = F_172 ( V_120 [ V_288 ] ) ;
if ( ! V_120 [ V_289 ] || F_172 ( V_120 [ V_289 ] ) )
V_10 -> V_18 |= V_131 ;
if ( V_120 [ V_290 ] )
V_10 -> V_243 = F_167 ( V_120 [ V_290 ] ) ;
else
V_10 -> V_243 = V_291 ;
if ( V_120 [ V_292 ] && F_172 ( V_120 [ V_292 ] ) )
V_10 -> V_18 |= V_209 ;
if ( V_120 [ V_293 ] && F_172 ( V_120 [ V_293 ] ) )
V_10 -> V_18 |= V_210 ;
if ( V_120 [ V_294 ] && F_172 ( V_120 [ V_294 ] ) )
V_10 -> V_18 |= V_211 ;
if ( V_120 [ V_295 ] && F_172 ( V_120 [ V_295 ] ) )
V_10 -> V_18 |= V_178 ;
if ( V_120 [ V_296 ] )
V_10 -> V_77 = F_167 ( V_120 [ V_296 ] ) ;
if ( V_120 [ V_274 ] ) {
const struct V_275 * V_241
= F_166 ( V_120 [ V_274 ] ) ;
V_10 -> V_192 = F_102 ( V_241 -> V_252 ) ;
V_10 -> V_191 = F_102 ( V_241 -> V_253 ) ;
}
F_173 ( V_39 , & V_297 ) ;
V_56 = F_174 ( V_39 ) ;
if ( ! V_56 )
F_38 ( & V_10 -> V_81 , F_1 ( V_2 , V_10 -> V_11 ) ) ;
return V_56 ;
}
static void F_175 ( struct V_61 * V_39 , struct V_298 * V_70 )
{
struct V_9 * V_10 = F_26 ( V_39 ) ;
F_40 ( & V_10 -> V_81 ) ;
F_176 ( V_39 , V_70 ) ;
}
static T_2 F_177 ( const struct V_61 * V_39 )
{
return F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( V_55 ) ) +
F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( V_55 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_10 ) ) +
F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( T_7 ) ) +
F_17 ( sizeof( struct V_275 ) ) +
0 ;
}
static int F_178 ( struct V_12 * V_13 , const struct V_61 * V_39 )
{
const struct V_9 * V_10 = F_26 ( V_39 ) ;
struct V_275 V_299 = {
. V_252 = F_91 ( V_10 -> V_192 ) ,
. V_253 = F_91 ( V_10 -> V_191 ) ,
} ;
if ( F_179 ( V_13 , V_270 , V_10 -> V_11 ) )
goto V_47;
if ( V_10 -> V_104 && F_11 ( V_13 , V_273 , V_10 -> V_104 ) )
goto V_47;
if ( V_10 -> V_112 && F_179 ( V_13 , V_282 , V_10 -> V_112 ) )
goto V_47;
if ( V_10 -> V_132 && F_11 ( V_13 , V_281 , V_10 -> V_132 ) )
goto V_47;
if ( F_180 ( V_13 , V_288 , V_10 -> V_207 ) ||
F_180 ( V_13 , V_287 , V_10 -> V_140 ) ||
F_180 ( V_13 , V_289 ,
! ! ( V_10 -> V_18 & V_131 ) ) ||
F_180 ( V_13 , V_292 ,
! ! ( V_10 -> V_18 & V_209 ) ) ||
F_180 ( V_13 , V_293 , ! ! ( V_10 -> V_18 & V_210 ) ) ||
F_180 ( V_13 , V_294 ,
! ! ( V_10 -> V_18 & V_211 ) ) ||
F_180 ( V_13 , V_295 ,
! ! ( V_10 -> V_18 & V_178 ) ) ||
F_179 ( V_13 , V_290 , V_10 -> V_243 ) ||
F_179 ( V_13 , V_296 , V_10 -> V_77 ) )
goto V_47;
if ( F_10 ( V_13 , V_274 , sizeof( V_299 ) , & V_299 ) )
goto V_47;
return 0 ;
V_47:
return - V_29 ;
}
static T_11 int F_181 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
struct V_105 * V_106 ;
struct V_300 V_301 = {
. V_302 = V_32 ,
. V_303 . V_110 = F_71 ( V_304 ) ,
} ;
int V_305 ;
unsigned V_95 ;
V_305 = F_182 ( V_32 , V_306 , V_234 , & V_5 -> V_105 ) ;
if ( V_305 < 0 ) {
F_164 ( L_19 ) ;
return V_305 ;
}
V_106 = V_5 -> V_105 -> V_106 ;
F_183 ( V_106 , V_2 ) ;
V_301 . V_307 = F_91 ( V_228 ) ;
V_305 = F_184 ( V_5 -> V_105 , (struct V_308 * ) & V_301 ,
sizeof( V_301 ) ) ;
if ( V_305 < 0 ) {
F_164 ( L_20 ,
& V_301 . V_303 , F_102 ( V_301 . V_307 ) , V_305 ) ;
F_185 ( V_106 ) ;
V_5 -> V_105 = NULL ;
return V_305 ;
}
F_186 ( V_106 ) -> V_309 = 0 ;
F_187 ( V_106 ) -> V_310 = 1 ;
F_187 ( V_106 ) -> V_311 = F_68 ;
F_188 () ;
for ( V_95 = 0 ; V_95 < V_103 ; ++ V_95 )
F_162 ( & V_5 -> V_7 [ V_95 ] ) ;
return 0 ;
}
static T_12 void F_189 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
struct V_9 * V_10 ;
unsigned V_95 ;
F_65 () ;
for ( V_95 = 0 ; V_95 < V_103 ; ++ V_95 )
F_58 (vxlan, &vn->vni_list[h], hlist)
F_190 ( V_10 -> V_39 ) ;
F_61 () ;
if ( V_5 -> V_105 ) {
F_185 ( V_5 -> V_105 -> V_106 ) ;
V_5 -> V_105 = NULL ;
}
}
static int T_13 F_191 ( void )
{
int V_305 ;
F_192 ( & V_312 , sizeof( V_312 ) ) ;
V_305 = F_193 ( & V_313 ) ;
if ( V_305 )
goto V_314;
V_305 = F_194 ( & V_315 ) ;
if ( V_305 )
goto V_316;
return 0 ;
V_316:
F_195 ( & V_313 ) ;
V_314:
return V_305 ;
}
static void T_14 F_196 ( void )
{
F_197 ( & V_315 ) ;
F_195 ( & V_313 ) ;
}
