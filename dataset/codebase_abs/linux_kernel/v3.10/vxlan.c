static inline struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
return & V_5 -> V_7 [ F_3 ( V_3 , V_8 ) ] ;
}
static struct V_9 * F_4 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_9 * V_10 ;
F_5 (vxlan, vni_head(net, id), hlist) {
if ( V_10 -> V_11 . V_12 == V_3 )
return V_10 ;
}
return NULL ;
}
static int F_6 ( struct V_13 * V_14 , struct V_9 * V_10 ,
const struct V_15 * V_16 ,
T_1 V_17 , T_1 V_18 , int type , unsigned int V_19 ,
const struct V_20 * V_21 )
{
unsigned long V_22 = V_23 ;
struct V_24 V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
bool V_30 , V_31 ;
V_27 = F_7 ( V_14 , V_17 , V_18 , type , sizeof( * V_29 ) , V_19 ) ;
if ( V_27 == NULL )
return - V_32 ;
V_29 = F_8 ( V_27 ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_31 = V_30 = true ;
if ( type == V_33 ) {
V_29 -> V_34 = V_35 ;
V_30 = V_21 -> V_36 != F_9 ( V_37 ) ;
V_31 = ! F_10 ( V_16 -> V_38 ) ;
} else
V_29 -> V_34 = V_39 ;
V_29 -> V_40 = V_16 -> V_41 ;
V_29 -> V_42 = V_10 -> V_43 -> V_44 ;
V_29 -> V_45 = V_16 -> V_19 ;
V_29 -> V_46 = V_47 ;
if ( V_31 && F_11 ( V_14 , V_48 , V_49 , & V_16 -> V_38 ) )
goto V_50;
if ( V_30 && F_12 ( V_14 , V_47 , V_21 -> V_36 ) )
goto V_50;
if ( V_21 -> V_51 && V_21 -> V_51 != V_10 -> V_52 &&
F_13 ( V_14 , V_53 , V_21 -> V_51 ) )
goto V_50;
if ( V_21 -> V_12 != V_10 -> V_11 . V_12 &&
F_12 ( V_14 , V_54 , V_21 -> V_12 ) )
goto V_50;
if ( V_21 -> V_55 &&
F_14 ( V_14 , V_56 , V_21 -> V_55 ) )
goto V_50;
V_25 . V_57 = F_15 ( V_22 - V_16 -> V_58 ) ;
V_25 . V_59 = 0 ;
V_25 . V_60 = F_15 ( V_22 - V_16 -> V_61 ) ;
V_25 . V_62 = 0 ;
if ( F_11 ( V_14 , V_63 , sizeof( V_25 ) , & V_25 ) )
goto V_50;
return F_16 ( V_14 , V_27 ) ;
V_50:
F_17 ( V_14 , V_27 ) ;
return - V_32 ;
}
static inline T_2 F_18 ( void )
{
return F_19 ( sizeof( struct V_28 ) )
+ F_20 ( V_49 )
+ F_20 ( sizeof( V_64 ) )
+ F_20 ( sizeof( V_65 ) )
+ F_20 ( sizeof( V_64 ) )
+ F_20 ( sizeof( V_66 ) )
+ F_20 ( sizeof( struct V_24 ) ) ;
}
static void F_21 ( struct V_9 * V_10 ,
const struct V_15 * V_16 , int type )
{
struct V_2 * V_2 = F_22 ( V_10 -> V_43 ) ;
struct V_13 * V_14 ;
int V_67 = - V_68 ;
V_14 = F_23 ( F_18 () , V_69 ) ;
if ( V_14 == NULL )
goto V_70;
V_67 = F_6 ( V_14 , V_10 , V_16 , 0 , 0 , type , 0 , & V_16 -> V_71 ) ;
if ( V_67 < 0 ) {
F_24 ( V_67 == - V_32 ) ;
F_25 ( V_14 ) ;
goto V_70;
}
F_26 ( V_14 , V_2 , 0 , V_72 , NULL , V_69 ) ;
return;
V_70:
if ( V_67 < 0 )
F_27 ( V_2 , V_72 , V_67 ) ;
}
static void F_28 ( struct V_73 * V_43 , V_64 V_74 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_15 V_75 ;
memset ( & V_75 , 0 , sizeof V_75 ) ;
V_75 . V_41 = V_76 ;
V_75 . V_71 . V_36 = V_74 ;
V_75 . V_71 . V_12 = V_77 ;
F_21 ( V_10 , & V_75 , V_33 ) ;
}
static void F_30 ( struct V_9 * V_10 , const T_3 V_38 [ V_49 ] )
{
struct V_15 V_75 ;
memset ( & V_75 , 0 , sizeof V_75 ) ;
V_75 . V_41 = V_76 ;
memcpy ( V_75 . V_38 , V_38 , V_49 ) ;
F_21 ( V_10 , & V_75 , V_33 ) ;
}
static T_1 F_31 ( const unsigned char * V_78 )
{
T_4 V_79 = F_32 ( ( T_4 * ) V_78 ) ;
#ifdef F_33
V_79 >>= 16 ;
#else
V_79 <<= 16 ;
#endif
return F_34 ( V_79 , V_80 ) ;
}
static inline struct V_1 * F_35 ( struct V_9 * V_10 ,
const T_3 * V_81 )
{
return & V_10 -> V_82 [ F_31 ( V_81 ) ] ;
}
static struct V_15 * F_36 ( struct V_9 * V_10 ,
const T_3 * V_81 )
{
struct V_1 * V_83 = F_35 ( V_10 , V_81 ) ;
struct V_15 * V_75 ;
F_5 (f, head, hlist) {
if ( F_37 ( V_81 , V_75 -> V_38 ) == 0 )
return V_75 ;
}
return NULL ;
}
static struct V_15 * F_38 ( struct V_9 * V_10 ,
const T_3 * V_81 )
{
struct V_15 * V_75 ;
V_75 = F_36 ( V_10 , V_81 ) ;
if ( V_75 )
V_75 -> V_58 = V_23 ;
return V_75 ;
}
static int F_39 ( struct V_15 * V_75 ,
V_64 V_84 , V_65 V_85 , V_66 V_86 , V_66 V_44 )
{
struct V_20 * V_87 , * V_88 ;
V_87 = NULL ;
for ( V_88 = & V_75 -> V_71 ; V_88 ; V_88 = V_88 -> V_89 ) {
if ( V_88 -> V_36 == V_84 &&
V_88 -> V_51 == V_85 &&
V_88 -> V_12 == V_86 &&
V_88 -> V_55 == V_44 )
return 0 ;
V_87 = V_88 ;
}
V_88 = F_40 ( sizeof( * V_88 ) , V_69 ) ;
if ( V_88 == NULL )
return - V_68 ;
V_88 -> V_36 = V_84 ;
V_88 -> V_51 = V_85 ;
V_88 -> V_12 = V_86 ;
V_88 -> V_55 = V_44 ;
V_88 -> V_89 = NULL ;
V_87 -> V_89 = V_88 ;
return 1 ;
}
static int F_41 ( struct V_9 * V_10 ,
const T_3 * V_81 , V_64 V_84 ,
T_5 V_41 , T_5 V_19 ,
V_65 V_85 , V_66 V_86 , V_66 V_44 ,
T_6 V_45 )
{
struct V_15 * V_75 ;
int V_90 = 0 ;
V_75 = F_36 ( V_10 , V_81 ) ;
if ( V_75 ) {
if ( V_19 & V_91 ) {
F_42 ( V_10 -> V_43 ,
L_1 , V_81 ) ;
return - V_92 ;
}
if ( V_75 -> V_41 != V_41 ) {
V_75 -> V_41 = V_41 ;
V_75 -> V_61 = V_23 ;
V_90 = 1 ;
}
if ( V_75 -> V_19 != V_45 ) {
V_75 -> V_19 = V_45 ;
V_75 -> V_61 = V_23 ;
V_90 = 1 ;
}
if ( ( V_19 & V_93 ) &&
F_43 ( V_75 -> V_38 ) ) {
int V_94 = F_39 ( V_75 , V_84 , V_85 , V_86 , V_44 ) ;
if ( V_94 < 0 )
return V_94 ;
V_90 |= V_94 ;
}
} else {
if ( ! ( V_19 & V_95 ) )
return - V_96 ;
if ( V_10 -> V_97 && V_10 -> V_98 >= V_10 -> V_97 )
return - V_99 ;
F_42 ( V_10 -> V_43 , L_2 , V_81 , & V_84 ) ;
V_75 = F_40 ( sizeof( * V_75 ) , V_69 ) ;
if ( ! V_75 )
return - V_100 ;
V_90 = 1 ;
V_75 -> V_71 . V_36 = V_84 ;
V_75 -> V_71 . V_51 = V_85 ;
V_75 -> V_71 . V_12 = V_86 ;
V_75 -> V_71 . V_55 = V_44 ;
V_75 -> V_71 . V_89 = NULL ;
V_75 -> V_41 = V_41 ;
V_75 -> V_19 = V_45 ;
V_75 -> V_61 = V_75 -> V_58 = V_23 ;
memcpy ( V_75 -> V_38 , V_81 , V_49 ) ;
++ V_10 -> V_98 ;
F_44 ( & V_75 -> V_101 ,
F_35 ( V_10 , V_81 ) ) ;
}
if ( V_90 )
F_21 ( V_10 , V_75 , V_102 ) ;
return 0 ;
}
static void F_45 ( struct V_103 * V_83 )
{
struct V_15 * V_75 = F_46 ( V_83 , struct V_15 , V_104 ) ;
while ( V_75 -> V_71 . V_89 ) {
struct V_20 * V_88 = V_75 -> V_71 . V_89 ;
V_75 -> V_71 . V_89 = V_88 -> V_89 ;
F_47 ( V_88 ) ;
}
F_47 ( V_75 ) ;
}
static void F_48 ( struct V_9 * V_10 , struct V_15 * V_75 )
{
F_42 ( V_10 -> V_43 ,
L_3 , V_75 -> V_38 ) ;
-- V_10 -> V_98 ;
F_21 ( V_10 , V_75 , V_105 ) ;
F_49 ( & V_75 -> V_101 ) ;
F_50 ( & V_75 -> V_104 , F_45 ) ;
}
static int F_51 ( struct V_28 * V_29 , struct V_106 * V_107 [] ,
struct V_73 * V_43 ,
const unsigned char * V_78 , T_7 V_19 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_2 * V_2 = F_22 ( V_10 -> V_43 ) ;
V_64 V_84 ;
V_65 V_85 ;
T_1 V_86 , V_44 ;
int V_67 ;
if ( ! ( V_29 -> V_40 & ( V_108 | V_109 ) ) ) {
F_52 ( L_4 ,
V_29 -> V_40 ) ;
return - V_110 ;
}
if ( V_107 [ V_47 ] == NULL )
return - V_110 ;
if ( F_53 ( V_107 [ V_47 ] ) != sizeof( V_64 ) )
return - V_111 ;
V_84 = F_54 ( V_107 [ V_47 ] ) ;
if ( V_107 [ V_53 ] ) {
if ( F_53 ( V_107 [ V_53 ] ) != sizeof( V_65 ) )
return - V_110 ;
V_85 = F_55 ( V_107 [ V_53 ] ) ;
} else
V_85 = V_10 -> V_52 ;
if ( V_107 [ V_54 ] ) {
if ( F_53 ( V_107 [ V_54 ] ) != sizeof( T_1 ) )
return - V_110 ;
V_86 = F_56 ( V_107 [ V_54 ] ) ;
} else
V_86 = V_10 -> V_11 . V_12 ;
if ( V_107 [ V_56 ] ) {
struct V_73 * V_112 ;
if ( F_53 ( V_107 [ V_56 ] ) != sizeof( T_1 ) )
return - V_110 ;
V_44 = F_56 ( V_107 [ V_56 ] ) ;
V_112 = F_57 ( V_2 , V_44 ) ;
if ( ! V_112 )
return - V_113 ;
F_58 ( V_112 ) ;
} else
V_44 = 0 ;
F_59 ( & V_10 -> V_114 ) ;
V_67 = F_41 ( V_10 , V_78 , V_84 , V_29 -> V_40 , V_19 ,
V_85 , V_86 , V_44 , V_29 -> V_45 ) ;
F_60 ( & V_10 -> V_114 ) ;
return V_67 ;
}
static int F_61 ( struct V_28 * V_29 , struct V_106 * V_107 [] ,
struct V_73 * V_43 ,
const unsigned char * V_78 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_15 * V_75 ;
int V_67 = - V_96 ;
F_59 ( & V_10 -> V_114 ) ;
V_75 = F_38 ( V_10 , V_78 ) ;
if ( V_75 ) {
F_48 ( V_10 , V_75 ) ;
V_67 = 0 ;
}
F_60 ( & V_10 -> V_114 ) ;
return V_67 ;
}
static int F_62 ( struct V_13 * V_14 , struct V_115 * V_116 ,
struct V_73 * V_43 , int V_117 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
unsigned int V_118 ;
for ( V_118 = 0 ; V_118 < V_119 ; ++ V_118 ) {
struct V_15 * V_75 ;
int V_67 ;
F_5 (f, &vxlan->fdb_head[h], hlist) {
struct V_20 * V_88 ;
for ( V_88 = & V_75 -> V_71 ; V_88 ; V_88 = V_88 -> V_89 ) {
if ( V_117 < V_116 -> args [ 0 ] )
goto V_120;
V_67 = F_6 ( V_14 , V_10 , V_75 ,
F_63 ( V_116 -> V_14 ) . V_17 ,
V_116 -> V_27 -> V_121 ,
V_102 ,
V_122 , V_88 ) ;
if ( V_67 < 0 )
break;
V_120:
++ V_117 ;
}
}
}
return V_117 ;
}
static bool F_64 ( struct V_73 * V_43 ,
V_64 V_123 , const T_3 * V_124 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_15 * V_75 ;
V_75 = F_38 ( V_10 , V_124 ) ;
if ( F_65 ( V_75 ) ) {
if ( F_65 ( V_75 -> V_71 . V_36 == V_123 ) )
return false ;
if ( V_75 -> V_41 & V_125 )
return true ;
if ( F_66 () )
F_67 ( V_43 ,
L_5 ,
V_124 , & V_75 -> V_71 . V_36 , & V_123 ) ;
V_75 -> V_71 . V_36 = V_123 ;
V_75 -> V_61 = V_23 ;
} else {
F_68 ( & V_10 -> V_114 ) ;
if ( F_69 ( V_43 ) )
F_41 ( V_10 , V_124 , V_123 ,
V_109 ,
V_91 | V_95 ,
V_10 -> V_52 ,
V_10 -> V_11 . V_12 ,
0 , V_126 ) ;
F_70 ( & V_10 -> V_114 ) ;
}
return false ;
}
static bool F_71 ( struct V_4 * V_5 ,
const struct V_9 * V_127 )
{
const struct V_9 * V_10 ;
unsigned V_118 ;
for ( V_118 = 0 ; V_118 < V_128 ; ++ V_118 )
F_72 (vxlan, &vn->vni_list[h], hlist) {
if ( V_10 == V_127 )
continue;
if ( ! F_69 ( V_10 -> V_43 ) )
continue;
if ( V_10 -> V_11 . V_36 == V_127 -> V_11 . V_36 )
return true ;
}
return false ;
}
static int F_73 ( struct V_73 * V_43 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_4 * V_5 = F_2 ( F_22 ( V_43 ) , V_6 ) ;
struct V_129 * V_130 = V_5 -> V_129 -> V_130 ;
struct V_131 V_132 = {
. V_133 . V_134 = V_10 -> V_11 . V_36 ,
. V_135 = V_10 -> V_11 . V_55 ,
} ;
int V_67 ;
if ( F_71 ( V_5 , V_10 ) )
return 0 ;
F_74 () ;
F_75 ( V_130 ) ;
V_67 = F_76 ( V_130 , & V_132 ) ;
F_77 ( V_130 ) ;
F_78 () ;
return V_67 ;
}
static int F_79 ( struct V_73 * V_43 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_4 * V_5 = F_2 ( F_22 ( V_43 ) , V_6 ) ;
int V_67 = 0 ;
struct V_129 * V_130 = V_5 -> V_129 -> V_130 ;
struct V_131 V_132 = {
. V_133 . V_134 = V_10 -> V_11 . V_36 ,
. V_135 = V_10 -> V_11 . V_55 ,
} ;
if ( F_71 ( V_5 , V_10 ) )
return 0 ;
F_74 () ;
F_75 ( V_130 ) ;
V_67 = F_80 ( V_130 , & V_132 ) ;
F_77 ( V_130 ) ;
F_78 () ;
return V_67 ;
}
static int F_81 ( struct V_129 * V_130 , struct V_13 * V_14 )
{
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_9 * V_10 ;
struct V_140 * V_141 ;
V_66 V_86 ;
int V_67 ;
F_82 ( V_14 , sizeof( struct V_142 ) ) ;
if ( ! F_83 ( V_14 , sizeof( struct V_138 ) ) )
goto error;
V_139 = (struct V_138 * ) V_14 -> V_143 ;
if ( V_139 -> V_144 != F_9 ( V_145 ) ||
( V_139 -> V_146 & F_9 ( 0xff ) ) ) {
F_42 ( V_14 -> V_43 , L_6 ,
F_84 ( V_139 -> V_144 ) , F_84 ( V_139 -> V_146 ) ) ;
goto error;
}
F_82 ( V_14 , sizeof( struct V_138 ) ) ;
V_86 = F_84 ( V_139 -> V_146 ) >> 8 ;
V_10 = F_4 ( F_85 ( V_130 ) , V_86 ) ;
if ( ! V_10 ) {
F_42 ( V_14 -> V_43 , L_7 , V_86 ) ;
goto V_147;
}
if ( ! F_83 ( V_14 , V_148 ) ) {
V_10 -> V_43 -> V_141 . V_149 ++ ;
V_10 -> V_43 -> V_141 . V_150 ++ ;
goto V_147;
}
F_86 ( V_14 ) ;
V_137 = F_87 ( V_14 ) ;
V_14 -> V_151 = F_88 ( V_14 , V_10 -> V_43 ) ;
if ( F_37 ( F_89 ( V_14 ) -> V_152 ,
V_10 -> V_43 -> V_153 ) == 0 )
goto V_147;
if ( ( V_10 -> V_19 & V_154 ) &&
F_64 ( V_14 -> V_43 , V_137 -> V_155 , F_89 ( V_14 ) -> V_152 ) )
goto V_147;
F_90 ( V_14 , V_10 -> V_43 ) ;
F_91 ( V_14 ) ;
if ( V_14 -> V_156 != V_157 || ! V_14 -> V_158 ||
! ( V_10 -> V_43 -> V_159 & V_160 ) )
V_14 -> V_156 = V_161 ;
V_14 -> V_158 = 0 ;
V_67 = F_92 ( V_137 , V_14 ) ;
if ( F_93 ( V_67 ) ) {
if ( V_162 )
F_94 ( L_8 ,
& V_137 -> V_155 , V_137 -> V_163 ) ;
if ( V_67 > 1 ) {
++ V_10 -> V_43 -> V_141 . V_164 ;
++ V_10 -> V_43 -> V_141 . V_150 ;
goto V_147;
}
}
V_141 = F_95 ( V_10 -> V_43 -> V_165 ) ;
F_96 ( & V_141 -> V_166 ) ;
V_141 -> V_167 ++ ;
V_141 -> V_168 += V_14 -> V_169 ;
F_97 ( & V_141 -> V_166 ) ;
F_98 ( V_14 ) ;
return 0 ;
error:
F_99 ( V_14 , sizeof( struct V_142 ) ) ;
return 1 ;
V_147:
F_25 ( V_14 ) ;
return 0 ;
}
static int F_100 ( struct V_73 * V_43 , struct V_13 * V_14 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_170 * V_171 ;
T_3 * V_172 , * V_173 ;
V_64 V_174 , V_175 ;
struct V_176 * V_177 ;
if ( V_43 -> V_19 & V_178 )
goto V_179;
if ( ! F_83 ( V_14 , F_101 ( V_43 ) ) ) {
V_43 -> V_141 . V_180 ++ ;
goto V_179;
}
V_171 = F_102 ( V_14 ) ;
if ( ( V_171 -> V_181 != F_103 ( V_182 ) &&
V_171 -> V_181 != F_103 ( V_183 ) ) ||
V_171 -> V_184 != F_103 ( V_185 ) ||
V_171 -> V_186 != F_103 ( V_187 ) ||
V_171 -> V_188 != V_43 -> V_189 ||
V_171 -> V_190 != 4 )
goto V_179;
V_172 = ( T_3 * ) V_171 + sizeof( struct V_170 ) ;
V_173 = V_172 ;
V_172 += V_43 -> V_189 ;
memcpy ( & V_174 , V_172 , sizeof( V_174 ) ) ;
V_172 += sizeof( V_174 ) ;
V_172 += V_43 -> V_189 ;
memcpy ( & V_175 , V_172 , sizeof( V_175 ) ) ;
if ( F_104 ( V_175 ) ||
F_105 ( V_175 ) )
goto V_179;
V_177 = F_106 ( & V_191 , & V_175 , V_43 ) ;
if ( V_177 ) {
struct V_15 * V_75 ;
struct V_13 * V_192 ;
if ( ! ( V_177 -> V_193 & V_194 ) ) {
F_107 ( V_177 ) ;
goto V_179;
}
V_75 = F_38 ( V_10 , V_177 -> V_195 ) ;
if ( V_75 && V_75 -> V_71 . V_36 == F_9 ( V_37 ) ) {
F_107 ( V_177 ) ;
goto V_179;
}
V_192 = F_108 ( V_196 , V_197 , V_174 , V_43 , V_175 , V_173 ,
V_177 -> V_195 , V_173 ) ;
F_107 ( V_177 ) ;
F_86 ( V_192 ) ;
F_82 ( V_192 , F_109 ( V_192 ) ) ;
V_192 -> V_156 = V_157 ;
V_192 -> V_198 = V_199 ;
if ( F_110 ( V_192 ) == V_200 )
V_43 -> V_141 . V_201 ++ ;
} else if ( V_10 -> V_19 & V_202 )
F_28 ( V_43 , V_175 ) ;
V_179:
F_111 ( V_14 ) ;
return V_203 ;
}
static bool F_112 ( struct V_73 * V_43 , struct V_13 * V_14 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_176 * V_177 ;
struct V_136 * V_204 ;
if ( F_43 ( F_89 ( V_14 ) -> V_205 ) )
return false ;
V_177 = NULL ;
switch ( F_113 ( F_89 ( V_14 ) -> V_206 ) ) {
case V_185 :
if ( ! F_83 ( V_14 , sizeof( struct V_136 ) ) )
return false ;
V_204 = F_87 ( V_14 ) ;
V_177 = F_106 ( & V_191 , & V_204 -> V_207 , V_43 ) ;
break;
default:
return false ;
}
if ( V_177 ) {
bool V_208 ;
V_208 = F_37 ( F_89 ( V_14 ) -> V_205 , V_177 -> V_195 ) != 0 ;
if ( V_208 ) {
memcpy ( F_89 ( V_14 ) -> V_152 , F_89 ( V_14 ) -> V_205 ,
V_43 -> V_189 ) ;
memcpy ( F_89 ( V_14 ) -> V_205 , V_177 -> V_195 , V_43 -> V_189 ) ;
}
F_107 ( V_177 ) ;
return V_208 ;
} else if ( V_10 -> V_19 & V_202 )
F_28 ( V_43 , V_204 -> V_207 ) ;
return false ;
}
static void F_114 ( struct V_13 * V_14 )
{
F_115 ( V_14 -> V_130 ) ;
}
static void F_116 ( struct V_73 * V_43 , struct V_13 * V_14 )
{
struct V_4 * V_5 = F_2 ( F_22 ( V_43 ) , V_6 ) ;
struct V_129 * V_130 = V_5 -> V_129 -> V_130 ;
F_117 ( V_14 ) ;
F_118 ( V_130 ) ;
V_14 -> V_130 = V_130 ;
V_14 -> V_209 = F_114 ;
}
static V_65 F_119 ( const struct V_9 * V_10 , struct V_13 * V_14 )
{
unsigned int V_210 = ( V_10 -> V_211 - V_10 -> V_212 ) + 1 ;
T_1 V_213 ;
V_213 = F_120 ( V_14 ) ;
if ( ! V_213 )
V_213 = F_121 ( V_14 -> V_143 , 2 * V_49 ,
( V_214 T_1 ) V_14 -> V_151 ) ;
return F_103 ( ( ( ( T_4 ) V_213 * V_210 ) >> 32 ) + V_10 -> V_212 ) ;
}
static int F_122 ( struct V_13 * V_14 )
{
if ( F_123 ( V_14 ) ) {
int V_67 = F_124 ( V_14 , V_69 ) ;
if ( F_93 ( V_67 ) )
return V_67 ;
F_125 ( V_14 ) -> V_215 |= V_216 ;
} else if ( V_14 -> V_156 != V_217 )
V_14 -> V_156 = V_161 ;
return 0 ;
}
static void F_126 ( struct V_13 * V_14 , struct V_9 * V_218 ,
struct V_9 * V_219 )
{
struct V_140 * V_220 = F_95 ( V_218 -> V_43 -> V_165 ) ;
struct V_140 * V_221 = F_95 ( V_219 -> V_43 -> V_165 ) ;
V_14 -> V_198 = V_199 ;
V_14 -> V_158 = 0 ;
V_14 -> V_43 = V_219 -> V_43 ;
F_82 ( V_14 , F_109 ( V_14 ) ) ;
if ( V_219 -> V_19 & V_154 )
F_64 ( V_14 -> V_43 , F_9 ( V_222 ) ,
F_89 ( V_14 ) -> V_152 ) ;
F_96 ( & V_220 -> V_166 ) ;
V_220 -> V_223 ++ ;
V_220 -> V_224 += V_14 -> V_169 ;
F_97 ( & V_220 -> V_166 ) ;
if ( F_98 ( V_14 ) == V_225 ) {
F_96 ( & V_221 -> V_166 ) ;
V_221 -> V_167 ++ ;
V_221 -> V_168 += V_14 -> V_169 ;
F_97 ( & V_221 -> V_166 ) ;
} else {
V_14 -> V_43 -> V_141 . V_201 ++ ;
}
}
static T_8 F_127 ( struct V_13 * V_14 , struct V_73 * V_43 ,
struct V_20 * V_21 , bool V_226 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_227 * V_228 ;
const struct V_136 * V_229 ;
struct V_136 * V_230 ;
struct V_138 * V_139 ;
struct V_142 * V_231 ;
struct V_232 V_233 ;
V_64 V_234 ;
V_65 V_235 , V_52 ;
T_1 V_86 ;
V_65 V_236 = 0 ;
T_6 V_163 , V_237 ;
V_52 = V_21 -> V_51 ? V_21 -> V_51 : V_10 -> V_52 ;
V_86 = V_21 -> V_12 ;
V_234 = V_21 -> V_36 ;
if ( ! V_234 ) {
if ( V_226 ) {
F_126 ( V_14 , V_10 , V_10 ) ;
return V_203 ;
}
goto V_147;
}
if ( ! V_14 -> V_158 ) {
F_128 ( V_14 ) ;
V_14 -> V_158 = 1 ;
}
if ( F_129 ( V_14 , V_238 ) )
goto V_147;
V_229 = F_87 ( V_14 ) ;
V_237 = V_10 -> V_237 ;
if ( ! V_237 && F_130 ( F_84 ( V_234 ) ) )
V_237 = 1 ;
V_163 = V_10 -> V_163 ;
if ( V_163 == 1 )
V_163 = F_131 ( V_229 , V_14 ) ;
V_235 = F_119 ( V_10 , V_14 ) ;
memset ( & V_233 , 0 , sizeof( V_233 ) ) ;
V_233 . V_239 = V_21 -> V_55 ;
V_233 . V_240 = F_132 ( V_163 ) ;
V_233 . V_207 = V_234 ;
V_233 . V_155 = V_10 -> V_155 ;
V_228 = F_133 ( F_22 ( V_43 ) , & V_233 ) ;
if ( F_134 ( V_228 ) ) {
F_42 ( V_43 , L_9 , & V_234 ) ;
V_43 -> V_141 . V_241 ++ ;
goto V_242;
}
if ( V_228 -> V_234 . V_43 == V_43 ) {
F_42 ( V_43 , L_10 , & V_234 ) ;
F_135 ( V_228 ) ;
V_43 -> V_141 . V_243 ++ ;
goto V_242;
}
if ( V_228 -> V_244 & V_245 &&
! ( V_228 -> V_244 & ( V_246 | V_247 ) ) ) {
struct V_9 * V_219 ;
F_135 ( V_228 ) ;
V_219 = F_4 ( F_22 ( V_43 ) , V_86 ) ;
if ( ! V_219 )
goto V_242;
F_126 ( V_14 , V_10 , V_219 ) ;
return V_203 ;
}
memset ( & ( F_136 ( V_14 ) -> V_248 ) , 0 , sizeof( F_136 ( V_14 ) -> V_248 ) ) ;
F_136 ( V_14 ) -> V_19 &= ~ ( V_249 | V_250 |
V_251 ) ;
F_137 ( V_14 ) ;
F_138 ( V_14 , & V_228 -> V_234 ) ;
V_139 = (struct V_138 * ) F_99 ( V_14 , sizeof( * V_139 ) ) ;
V_139 -> V_144 = F_9 ( V_145 ) ;
V_139 -> V_146 = F_9 ( V_86 << 8 ) ;
F_99 ( V_14 , sizeof( * V_231 ) ) ;
F_139 ( V_14 ) ;
V_231 = F_140 ( V_14 ) ;
V_231 -> V_252 = V_52 ;
V_231 -> V_253 = V_235 ;
V_231 -> V_169 = F_103 ( V_14 -> V_169 ) ;
V_231 -> V_254 = 0 ;
F_99 ( V_14 , sizeof( * V_230 ) ) ;
F_91 ( V_14 ) ;
V_230 = F_87 ( V_14 ) ;
V_230 -> V_255 = 4 ;
V_230 -> V_256 = sizeof( struct V_136 ) >> 2 ;
V_230 -> V_257 = V_236 ;
V_230 -> V_151 = V_258 ;
V_230 -> V_163 = F_141 ( V_163 , V_229 , V_14 ) ;
V_230 -> V_207 = V_234 ;
V_230 -> V_155 = V_233 . V_155 ;
V_230 -> V_237 = V_237 ? : F_142 ( & V_228 -> V_234 ) ;
F_143 ( V_14 , V_229 , & V_228 -> V_234 ) ;
F_144 ( V_14 ) ;
F_116 ( V_43 , V_14 ) ;
if ( F_122 ( V_14 ) )
goto V_147;
F_145 ( V_14 , V_43 ) ;
return V_203 ;
V_147:
V_43 -> V_141 . V_180 ++ ;
goto V_259;
V_242:
V_43 -> V_141 . V_260 ++ ;
V_259:
F_146 ( V_14 ) ;
return V_203 ;
}
static T_8 F_147 ( struct V_13 * V_14 , struct V_73 * V_43 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_261 * V_262 ;
bool V_226 = false ;
struct V_20 * V_263 , * V_21 ;
struct V_15 * V_75 ;
int V_264 , V_94 ;
F_86 ( V_14 ) ;
V_262 = F_89 ( V_14 ) ;
if ( ( V_10 -> V_19 & V_265 ) && F_113 ( V_262 -> V_206 ) == V_197 )
return F_100 ( V_43 , V_14 ) ;
V_75 = F_38 ( V_10 , V_262 -> V_205 ) ;
V_226 = false ;
if ( V_75 && ( V_75 -> V_19 & V_266 ) && ( V_10 -> V_19 & V_267 ) &&
F_113 ( V_262 -> V_206 ) == V_185 ) {
V_226 = F_112 ( V_43 , V_14 ) ;
if ( V_226 )
V_75 = F_38 ( V_10 , V_262 -> V_205 ) ;
}
if ( V_75 == NULL ) {
V_263 = & V_10 -> V_11 ;
if ( V_263 -> V_36 == F_9 ( V_37 ) &&
( V_10 -> V_19 & V_268 ) &&
! F_43 ( V_262 -> V_205 ) )
F_30 ( V_10 , V_262 -> V_205 ) ;
} else
V_263 = & V_75 -> V_71 ;
V_94 = V_203 ;
for ( V_21 = V_263 -> V_89 ; V_21 ; V_21 = V_21 -> V_89 ) {
struct V_13 * V_269 ;
V_269 = F_148 ( V_14 , V_69 ) ;
if ( V_269 ) {
V_264 = F_127 ( V_269 , V_43 , V_21 , V_226 ) ;
if ( V_94 == V_203 )
V_94 = V_264 ;
}
}
V_264 = F_127 ( V_14 , V_43 , V_263 , V_226 ) ;
if ( V_94 == V_203 )
V_94 = V_264 ;
return V_94 ;
}
static void F_149 ( unsigned long V_270 )
{
struct V_9 * V_10 = (struct V_9 * ) V_270 ;
unsigned long V_271 = V_23 + V_272 ;
unsigned int V_118 ;
if ( ! F_69 ( V_10 -> V_43 ) )
return;
F_59 ( & V_10 -> V_114 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; ++ V_118 ) {
struct V_273 * V_274 , * V_177 ;
F_150 (p, n, &vxlan->fdb_head[h]) {
struct V_15 * V_75
= F_46 ( V_274 , struct V_15 , V_101 ) ;
unsigned long V_275 ;
if ( V_75 -> V_41 & V_108 )
continue;
V_275 = V_75 -> V_58 + V_10 -> V_276 * V_277 ;
if ( F_151 ( V_275 , V_23 ) ) {
F_42 ( V_10 -> V_43 ,
L_11 ,
V_75 -> V_38 ) ;
V_75 -> V_41 = V_76 ;
F_48 ( V_10 , V_75 ) ;
} else if ( F_152 ( V_275 , V_271 ) )
V_271 = V_275 ;
}
}
F_60 ( & V_10 -> V_114 ) ;
F_153 ( & V_10 -> V_278 , V_271 ) ;
}
static int F_154 ( struct V_73 * V_43 )
{
V_43 -> V_165 = F_155 ( struct V_140 ) ;
if ( ! V_43 -> V_165 )
return - V_100 ;
return 0 ;
}
static int F_156 ( struct V_73 * V_43 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
int V_67 ;
if ( F_130 ( F_84 ( V_10 -> V_11 . V_36 ) ) ) {
V_67 = F_73 ( V_43 ) ;
if ( V_67 )
return V_67 ;
}
if ( V_10 -> V_276 )
F_153 ( & V_10 -> V_278 , V_23 + V_272 ) ;
return 0 ;
}
static void F_157 ( struct V_9 * V_10 )
{
unsigned V_118 ;
F_59 ( & V_10 -> V_114 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; ++ V_118 ) {
struct V_273 * V_274 , * V_177 ;
F_150 (p, n, &vxlan->fdb_head[h]) {
struct V_15 * V_75
= F_46 ( V_274 , struct V_15 , V_101 ) ;
F_48 ( V_10 , V_75 ) ;
}
}
F_60 ( & V_10 -> V_114 ) ;
}
static int F_158 ( struct V_73 * V_43 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
if ( F_130 ( F_84 ( V_10 -> V_11 . V_36 ) ) )
F_79 ( V_43 ) ;
F_159 ( & V_10 -> V_278 ) ;
F_157 ( V_10 ) ;
return 0 ;
}
static void F_160 ( struct V_73 * V_43 )
{
}
static void F_161 ( struct V_73 * V_43 )
{
F_162 ( V_43 -> V_165 ) ;
F_163 ( V_43 ) ;
}
static void F_164 ( struct V_73 * V_43 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
unsigned V_118 ;
int V_279 , V_280 ;
F_165 ( V_43 ) ;
F_166 ( V_43 ) ;
V_43 -> V_281 = V_148 + V_238 ;
V_43 -> V_282 = & V_283 ;
V_43 -> V_209 = F_161 ;
F_167 ( V_43 , & V_284 ) ;
V_43 -> V_285 = 0 ;
V_43 -> V_159 |= V_286 ;
V_43 -> V_159 |= V_287 ;
V_43 -> V_159 |= V_288 | V_289 ;
V_43 -> V_159 |= V_160 ;
V_43 -> V_159 |= V_290 ;
V_43 -> V_291 |= V_288 | V_289 | V_160 ;
V_43 -> V_291 |= V_290 ;
V_43 -> V_292 &= ~ V_293 ;
V_43 -> V_292 |= V_294 ;
F_168 ( & V_10 -> V_114 ) ;
F_169 ( & V_10 -> V_278 ) ;
V_10 -> V_278 . V_295 = F_149 ;
V_10 -> V_278 . V_143 = ( unsigned long ) V_10 ;
F_170 ( & V_279 , & V_280 ) ;
V_10 -> V_212 = V_279 ;
V_10 -> V_211 = V_280 ;
V_10 -> V_52 = F_103 ( V_296 ) ;
V_10 -> V_43 = V_43 ;
for ( V_118 = 0 ; V_118 < V_119 ; ++ V_118 )
F_171 ( & V_10 -> V_82 [ V_118 ] ) ;
}
static int F_172 ( struct V_106 * V_107 [] , struct V_106 * V_143 [] )
{
if ( V_107 [ V_297 ] ) {
if ( F_53 ( V_107 [ V_297 ] ) != V_49 ) {
F_173 ( L_12 ) ;
return - V_110 ;
}
if ( ! F_174 ( F_175 ( V_107 [ V_297 ] ) ) ) {
F_173 ( L_13 ) ;
return - V_113 ;
}
}
if ( ! V_143 )
return - V_110 ;
if ( V_143 [ V_298 ] ) {
V_66 V_3 = F_56 ( V_143 [ V_298 ] ) ;
if ( V_3 >= V_299 )
return - V_300 ;
}
if ( V_143 [ V_301 ] ) {
const struct V_302 * V_274
= F_175 ( V_143 [ V_301 ] ) ;
if ( F_113 ( V_274 -> V_280 ) < F_113 ( V_274 -> V_279 ) ) {
F_173 ( L_14 ,
F_113 ( V_274 -> V_279 ) , F_113 ( V_274 -> V_280 ) ) ;
return - V_110 ;
}
}
return 0 ;
}
static void F_176 ( struct V_73 * V_303 ,
struct V_304 * V_305 )
{
F_177 ( V_305 -> V_255 , V_306 , sizeof( V_305 -> V_255 ) ) ;
F_177 ( V_305 -> V_307 , L_15 , sizeof( V_305 -> V_307 ) ) ;
}
static int F_178 ( struct V_2 * V_2 , struct V_73 * V_43 ,
struct V_106 * V_107 [] , struct V_106 * V_143 [] )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
struct V_20 * V_234 = & V_10 -> V_11 ;
V_66 V_86 ;
int V_67 ;
if ( ! V_143 [ V_298 ] )
return - V_110 ;
V_86 = F_56 ( V_143 [ V_298 ] ) ;
if ( F_4 ( V_2 , V_86 ) ) {
F_52 ( L_16 , V_86 ) ;
return - V_92 ;
}
V_234 -> V_12 = V_86 ;
if ( V_143 [ V_308 ] )
V_234 -> V_36 = F_54 ( V_143 [ V_308 ] ) ;
if ( V_143 [ V_309 ] )
V_10 -> V_155 = F_54 ( V_143 [ V_309 ] ) ;
if ( V_143 [ V_310 ] &&
( V_234 -> V_55 = F_56 ( V_143 [ V_310 ] ) ) ) {
struct V_73 * V_311
= F_179 ( V_2 , V_234 -> V_55 ) ;
if ( ! V_311 ) {
F_52 ( L_17 , V_234 -> V_55 ) ;
return - V_312 ;
}
if ( ! V_107 [ V_313 ] )
V_43 -> V_314 = V_311 -> V_314 - V_238 ;
V_43 -> V_281 = V_311 -> V_281 +
V_238 ;
}
if ( V_143 [ V_315 ] )
V_10 -> V_163 = F_180 ( V_143 [ V_315 ] ) ;
if ( V_143 [ V_316 ] )
V_10 -> V_237 = F_180 ( V_143 [ V_316 ] ) ;
if ( ! V_143 [ V_317 ] || F_180 ( V_143 [ V_317 ] ) )
V_10 -> V_19 |= V_154 ;
if ( V_143 [ V_318 ] )
V_10 -> V_276 = F_56 ( V_143 [ V_318 ] ) ;
else
V_10 -> V_276 = V_319 ;
if ( V_143 [ V_320 ] && F_180 ( V_143 [ V_320 ] ) )
V_10 -> V_19 |= V_265 ;
if ( V_143 [ V_321 ] && F_180 ( V_143 [ V_321 ] ) )
V_10 -> V_19 |= V_267 ;
if ( V_143 [ V_322 ] && F_180 ( V_143 [ V_322 ] ) )
V_10 -> V_19 |= V_268 ;
if ( V_143 [ V_323 ] && F_180 ( V_143 [ V_323 ] ) )
V_10 -> V_19 |= V_202 ;
if ( V_143 [ V_324 ] )
V_10 -> V_97 = F_56 ( V_143 [ V_324 ] ) ;
if ( V_143 [ V_301 ] ) {
const struct V_302 * V_274
= F_175 ( V_143 [ V_301 ] ) ;
V_10 -> V_212 = F_113 ( V_274 -> V_279 ) ;
V_10 -> V_211 = F_113 ( V_274 -> V_280 ) ;
}
if ( V_143 [ V_325 ] )
V_10 -> V_52 = F_55 ( V_143 [ V_325 ] ) ;
F_181 ( V_43 , & V_326 ) ;
V_67 = F_182 ( V_43 ) ;
if ( ! V_67 )
F_44 ( & V_10 -> V_101 , F_1 ( V_2 , V_234 -> V_12 ) ) ;
return V_67 ;
}
static void F_183 ( struct V_73 * V_43 , struct V_327 * V_83 )
{
struct V_9 * V_10 = F_29 ( V_43 ) ;
F_49 ( & V_10 -> V_101 ) ;
F_184 ( V_43 , V_83 ) ;
}
static T_2 F_185 ( const struct V_73 * V_43 )
{
return F_20 ( sizeof( V_66 ) ) +
F_20 ( sizeof( V_64 ) ) +
F_20 ( sizeof( V_66 ) ) +
F_20 ( sizeof( V_64 ) ) +
F_20 ( sizeof( T_6 ) ) +
F_20 ( sizeof( T_6 ) ) +
F_20 ( sizeof( T_6 ) ) +
F_20 ( sizeof( T_6 ) ) +
F_20 ( sizeof( T_6 ) ) +
F_20 ( sizeof( T_6 ) ) +
F_20 ( sizeof( T_6 ) ) +
F_20 ( sizeof( V_66 ) ) +
F_20 ( sizeof( V_66 ) ) +
F_20 ( sizeof( struct V_302 ) ) +
F_20 ( sizeof( V_65 ) ) +
0 ;
}
static int F_186 ( struct V_13 * V_14 , const struct V_73 * V_43 )
{
const struct V_9 * V_10 = F_29 ( V_43 ) ;
const struct V_20 * V_234 = & V_10 -> V_11 ;
struct V_302 V_328 = {
. V_279 = F_103 ( V_10 -> V_212 ) ,
. V_280 = F_103 ( V_10 -> V_211 ) ,
} ;
if ( F_14 ( V_14 , V_298 , V_234 -> V_12 ) )
goto V_50;
if ( V_234 -> V_36 && F_12 ( V_14 , V_308 , V_234 -> V_36 ) )
goto V_50;
if ( V_234 -> V_55 && F_14 ( V_14 , V_310 , V_234 -> V_55 ) )
goto V_50;
if ( V_10 -> V_155 && F_12 ( V_14 , V_309 , V_10 -> V_155 ) )
goto V_50;
if ( F_187 ( V_14 , V_316 , V_10 -> V_237 ) ||
F_187 ( V_14 , V_315 , V_10 -> V_163 ) ||
F_187 ( V_14 , V_317 ,
! ! ( V_10 -> V_19 & V_154 ) ) ||
F_187 ( V_14 , V_320 ,
! ! ( V_10 -> V_19 & V_265 ) ) ||
F_187 ( V_14 , V_321 , ! ! ( V_10 -> V_19 & V_267 ) ) ||
F_187 ( V_14 , V_322 ,
! ! ( V_10 -> V_19 & V_268 ) ) ||
F_187 ( V_14 , V_323 ,
! ! ( V_10 -> V_19 & V_202 ) ) ||
F_14 ( V_14 , V_318 , V_10 -> V_276 ) ||
F_14 ( V_14 , V_324 , V_10 -> V_97 ) ||
F_13 ( V_14 , V_325 , V_10 -> V_52 ) )
goto V_50;
if ( F_11 ( V_14 , V_301 , sizeof( V_328 ) , & V_328 ) )
goto V_50;
return 0 ;
V_50:
return - V_32 ;
}
static T_9 int F_188 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
struct V_129 * V_130 ;
struct V_329 V_330 = {
. V_331 = V_35 ,
. V_332 . V_134 = F_9 ( V_37 ) ,
} ;
int V_94 ;
unsigned V_118 ;
V_94 = F_189 ( V_35 , V_333 , V_258 , & V_5 -> V_129 ) ;
if ( V_94 < 0 ) {
F_173 ( L_18 ) ;
return V_94 ;
}
V_130 = V_5 -> V_129 -> V_130 ;
F_190 ( V_130 , V_2 ) ;
V_330 . V_334 = F_103 ( V_296 ) ;
V_94 = F_191 ( V_5 -> V_129 , (struct V_335 * ) & V_330 ,
sizeof( V_330 ) ) ;
if ( V_94 < 0 ) {
F_173 ( L_19 ,
& V_330 . V_332 , F_113 ( V_330 . V_334 ) , V_94 ) ;
F_192 ( V_130 ) ;
V_5 -> V_129 = NULL ;
return V_94 ;
}
F_193 ( V_130 ) -> V_336 = 0 ;
F_194 ( V_130 ) -> V_337 = 1 ;
F_194 ( V_130 ) -> V_338 = F_81 ;
F_195 () ;
for ( V_118 = 0 ; V_118 < V_128 ; ++ V_118 )
F_171 ( & V_5 -> V_7 [ V_118 ] ) ;
return 0 ;
}
static T_10 void F_196 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
struct V_9 * V_10 ;
unsigned V_118 ;
F_78 () ;
for ( V_118 = 0 ; V_118 < V_128 ; ++ V_118 )
F_72 (vxlan, &vn->vni_list[h], hlist)
F_197 ( V_10 -> V_43 ) ;
F_74 () ;
if ( V_5 -> V_129 ) {
F_192 ( V_5 -> V_129 -> V_130 ) ;
V_5 -> V_129 = NULL ;
}
}
static int T_11 F_198 ( void )
{
int V_94 ;
F_199 ( & V_339 , sizeof( V_339 ) ) ;
V_94 = F_200 ( & V_340 ) ;
if ( V_94 )
goto V_341;
V_94 = F_201 ( & V_342 ) ;
if ( V_94 )
goto V_343;
return 0 ;
V_343:
F_202 ( & V_340 ) ;
V_341:
return V_94 ;
}
static void T_12 F_203 ( void )
{
F_204 ( & V_342 ) ;
F_202 ( & V_340 ) ;
F_205 () ;
}
