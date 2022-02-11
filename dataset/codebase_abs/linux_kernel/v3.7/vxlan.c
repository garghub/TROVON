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
V_26 = F_7 ( V_15 , V_18 , V_19 , type , sizeof( * V_28 ) , V_20 ) ;
if ( V_26 == NULL )
return - V_29 ;
V_28 = F_8 ( V_26 ) ;
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_30 = V_31 ;
V_28 -> V_32 = V_17 -> V_33 ;
V_28 -> V_34 = V_10 -> V_35 -> V_36 ;
V_28 -> V_37 = V_38 ;
V_28 -> V_39 = V_40 ;
if ( F_9 ( V_15 , V_41 , V_42 , & V_17 -> V_43 ) )
goto V_44;
if ( F_10 ( V_15 , V_40 , V_17 -> V_45 ) )
goto V_44;
V_24 . V_46 = F_11 ( V_21 - V_17 -> V_47 ) ;
V_24 . V_48 = 0 ;
V_24 . V_49 = F_11 ( V_21 - V_17 -> V_50 ) ;
V_24 . V_51 = 0 ;
if ( F_9 ( V_15 , V_52 , sizeof( V_24 ) , & V_24 ) )
goto V_44;
return F_12 ( V_15 , V_26 ) ;
V_44:
F_13 ( V_15 , V_26 ) ;
return - V_29 ;
}
static inline T_2 F_14 ( void )
{
return F_15 ( sizeof( struct V_27 ) )
+ F_16 ( V_42 )
+ F_16 ( sizeof( V_53 ) )
+ F_16 ( sizeof( struct V_23 ) ) ;
}
static void F_17 ( struct V_9 * V_10 ,
const struct V_16 * V_17 , int type )
{
struct V_2 * V_2 = F_18 ( V_10 -> V_35 ) ;
struct V_14 * V_15 ;
int V_54 = - V_55 ;
V_15 = F_19 ( F_14 () , V_56 ) ;
if ( V_15 == NULL )
goto V_57;
V_54 = F_6 ( V_15 , V_10 , V_17 , 0 , 0 , type , 0 ) ;
if ( V_54 < 0 ) {
F_20 ( V_54 == - V_29 ) ;
F_21 ( V_15 ) ;
goto V_57;
}
F_22 ( V_15 , V_2 , 0 , V_58 , NULL , V_56 ) ;
return;
V_57:
if ( V_54 < 0 )
F_23 ( V_2 , V_58 , V_54 ) ;
}
static T_1 F_24 ( const unsigned char * V_59 )
{
T_3 V_60 = F_25 ( ( T_3 * ) V_59 ) ;
#ifdef F_26
V_60 >>= 16 ;
#else
V_60 <<= 16 ;
#endif
return F_27 ( V_60 , V_61 ) ;
}
static inline struct V_1 * F_28 ( struct V_9 * V_10 ,
const T_4 * V_62 )
{
return & V_10 -> V_63 [ F_24 ( V_62 ) ] ;
}
static struct V_16 * F_29 ( struct V_9 * V_10 ,
const T_4 * V_62 )
{
struct V_1 * V_64 = F_28 ( V_10 , V_62 ) ;
struct V_16 * V_65 ;
struct V_11 * V_12 ;
F_5 (f, node, head, hlist) {
if ( F_30 ( V_62 , V_65 -> V_43 ) == 0 )
return V_65 ;
}
return NULL ;
}
static int F_31 ( struct V_9 * V_10 ,
const T_4 * V_62 , V_53 V_66 ,
T_5 V_33 , T_5 V_20 )
{
struct V_16 * V_65 ;
int V_67 = 0 ;
V_65 = F_29 ( V_10 , V_62 ) ;
if ( V_65 ) {
if ( V_20 & V_68 ) {
F_32 ( V_10 -> V_35 ,
L_1 , V_62 ) ;
return - V_69 ;
}
if ( V_65 -> V_33 != V_33 ) {
V_65 -> V_33 = V_33 ;
V_65 -> V_50 = V_22 ;
V_67 = 1 ;
}
} else {
if ( ! ( V_20 & V_70 ) )
return - V_71 ;
if ( V_10 -> V_72 && V_10 -> V_73 >= V_10 -> V_72 )
return - V_74 ;
F_32 ( V_10 -> V_35 , L_2 , V_62 , & V_66 ) ;
V_65 = F_33 ( sizeof( * V_65 ) , V_56 ) ;
if ( ! V_65 )
return - V_75 ;
V_67 = 1 ;
V_65 -> V_45 = V_66 ;
V_65 -> V_33 = V_33 ;
V_65 -> V_50 = V_65 -> V_47 = V_22 ;
memcpy ( V_65 -> V_43 , V_62 , V_42 ) ;
++ V_10 -> V_73 ;
F_34 ( & V_65 -> V_76 ,
F_28 ( V_10 , V_62 ) ) ;
}
if ( V_67 )
F_17 ( V_10 , V_65 , V_77 ) ;
return 0 ;
}
static void F_35 ( struct V_9 * V_10 , struct V_16 * V_65 )
{
F_32 ( V_10 -> V_35 ,
L_3 , V_65 -> V_43 ) ;
-- V_10 -> V_73 ;
F_17 ( V_10 , V_65 , V_78 ) ;
F_36 ( & V_65 -> V_76 ) ;
F_37 ( V_65 , V_79 ) ;
}
static int F_38 ( struct V_27 * V_28 , struct V_80 * V_81 [] ,
struct V_82 * V_35 ,
const unsigned char * V_59 , T_6 V_20 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
V_53 V_66 ;
int V_54 ;
if ( ! ( V_28 -> V_32 & ( V_83 | V_84 ) ) ) {
F_40 ( L_4 ,
V_28 -> V_32 ) ;
return - V_85 ;
}
if ( V_81 [ V_40 ] == NULL )
return - V_85 ;
if ( F_41 ( V_81 [ V_40 ] ) != sizeof( V_53 ) )
return - V_86 ;
V_66 = F_42 ( V_81 [ V_40 ] ) ;
F_43 ( & V_10 -> V_87 ) ;
V_54 = F_31 ( V_10 , V_59 , V_66 , V_28 -> V_32 , V_20 ) ;
F_44 ( & V_10 -> V_87 ) ;
return V_54 ;
}
static int F_45 ( struct V_27 * V_28 , struct V_82 * V_35 ,
const unsigned char * V_59 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
struct V_16 * V_65 ;
int V_54 = - V_71 ;
F_43 ( & V_10 -> V_87 ) ;
V_65 = F_29 ( V_10 , V_59 ) ;
if ( V_65 ) {
F_35 ( V_10 , V_65 ) ;
V_54 = 0 ;
}
F_44 ( & V_10 -> V_87 ) ;
return V_54 ;
}
static int F_46 ( struct V_14 * V_15 , struct V_88 * V_89 ,
struct V_82 * V_35 , int V_90 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
unsigned int V_91 ;
for ( V_91 = 0 ; V_91 < V_92 ; ++ V_91 ) {
struct V_16 * V_65 ;
struct V_11 * V_93 ;
int V_54 ;
F_5 (f, n, &vxlan->fdb_head[h], hlist) {
if ( V_90 < V_89 -> args [ 0 ] )
goto V_94;
V_54 = F_6 ( V_15 , V_10 , V_65 ,
F_47 ( V_89 -> V_15 ) . V_18 ,
V_89 -> V_26 -> V_95 ,
V_77 ,
V_96 ) ;
if ( V_54 < 0 )
break;
V_94:
++ V_90 ;
}
}
return V_90 ;
}
static void F_48 ( struct V_82 * V_35 ,
V_53 V_97 , const T_4 * V_98 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
struct V_16 * V_65 ;
int V_54 ;
V_65 = F_29 ( V_10 , V_98 ) ;
if ( F_49 ( V_65 ) ) {
V_65 -> V_47 = V_22 ;
if ( F_49 ( V_65 -> V_45 == V_97 ) )
return;
if ( F_50 () )
F_51 ( V_35 ,
L_5 ,
V_98 , & V_65 -> V_45 , & V_97 ) ;
V_65 -> V_45 = V_97 ;
V_65 -> V_50 = V_22 ;
} else {
F_52 ( & V_10 -> V_87 ) ;
V_54 = F_31 ( V_10 , V_98 , V_97 ,
V_84 ,
V_68 | V_70 ) ;
F_53 ( & V_10 -> V_87 ) ;
}
}
static bool F_54 ( struct V_4 * V_5 ,
const struct V_9 * V_99 )
{
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned V_91 ;
for ( V_91 = 0 ; V_91 < V_100 ; ++ V_91 )
F_55 (vxlan, node, &vn->vni_list[h], hlist) {
if ( V_10 == V_99 )
continue;
if ( ! F_56 ( V_10 -> V_35 ) )
continue;
if ( V_10 -> V_101 == V_99 -> V_101 )
return true ;
}
return false ;
}
static int F_57 ( struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
struct V_4 * V_5 = F_2 ( F_18 ( V_35 ) , V_6 ) ;
struct V_102 * V_103 = V_5 -> V_102 -> V_103 ;
struct V_104 V_105 = {
. V_106 . V_107 = V_10 -> V_101 ,
} ;
int V_54 ;
if ( F_54 ( V_5 , V_10 ) )
return 0 ;
F_58 () ;
F_59 ( V_103 ) ;
V_54 = F_60 ( V_103 , & V_105 ) ;
F_61 ( V_103 ) ;
F_62 () ;
return V_54 ;
}
static int F_63 ( struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
struct V_4 * V_5 = F_2 ( F_18 ( V_35 ) , V_6 ) ;
int V_54 = 0 ;
struct V_102 * V_103 = V_5 -> V_102 -> V_103 ;
struct V_104 V_105 = {
. V_106 . V_107 = V_10 -> V_101 ,
} ;
if ( F_54 ( V_5 , V_10 ) )
return 0 ;
F_58 () ;
F_59 ( V_103 ) ;
V_54 = F_64 ( V_103 , & V_105 ) ;
F_61 ( V_103 ) ;
F_62 () ;
return V_54 ;
}
static int F_65 ( struct V_102 * V_103 , struct V_14 * V_15 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_9 * V_10 ;
struct V_112 * V_113 ;
T_7 V_13 ;
int V_54 ;
F_66 ( V_15 , sizeof( struct V_114 ) ) ;
if ( ! F_67 ( V_15 , sizeof( struct V_110 ) ) )
goto error;
V_111 = (struct V_110 * ) V_15 -> V_115 ;
if ( V_111 -> V_116 != F_68 ( V_117 ) ||
( V_111 -> V_118 & F_68 ( 0xff ) ) ) {
F_32 ( V_15 -> V_35 , L_6 ,
F_69 ( V_111 -> V_116 ) , F_69 ( V_111 -> V_118 ) ) ;
goto error;
}
F_66 ( V_15 , sizeof( struct V_110 ) ) ;
V_13 = F_69 ( V_111 -> V_118 ) >> 8 ;
V_10 = F_4 ( F_70 ( V_103 ) , V_13 ) ;
if ( ! V_10 ) {
F_32 ( V_15 -> V_35 , L_7 , V_13 ) ;
goto V_119;
}
if ( ! F_67 ( V_15 , V_120 ) ) {
V_10 -> V_35 -> V_113 . V_121 ++ ;
V_10 -> V_35 -> V_113 . V_122 ++ ;
goto V_119;
}
V_109 = F_71 ( V_15 ) ;
V_15 -> V_123 = F_72 ( V_15 , V_10 -> V_35 ) ;
if ( F_30 ( F_73 ( V_15 ) -> V_124 ,
V_10 -> V_35 -> V_125 ) == 0 )
goto V_119;
if ( V_10 -> V_126 )
F_48 ( V_15 -> V_35 , V_109 -> V_127 , F_73 ( V_15 ) -> V_124 ) ;
F_74 ( V_15 , V_10 -> V_35 ) ;
F_75 ( V_15 ) ;
V_15 -> V_128 = V_129 ;
V_54 = F_76 ( V_109 , V_15 ) ;
if ( F_77 ( V_54 ) ) {
if ( V_130 )
F_78 ( L_8 ,
& V_109 -> V_127 , V_109 -> V_131 ) ;
if ( V_54 > 1 ) {
++ V_10 -> V_35 -> V_113 . V_132 ;
++ V_10 -> V_35 -> V_113 . V_122 ;
goto V_119;
}
}
V_113 = F_79 ( V_10 -> V_113 ) ;
F_80 ( & V_113 -> V_133 ) ;
V_113 -> V_134 ++ ;
V_113 -> V_135 += V_15 -> V_136 ;
F_81 ( & V_113 -> V_133 ) ;
F_82 ( V_15 ) ;
return 0 ;
error:
F_83 ( V_15 , sizeof( struct V_114 ) ) ;
return 1 ;
V_119:
F_21 ( V_15 ) ;
return 0 ;
}
static inline T_4 F_84 ( const struct V_108 * V_137 ,
const struct V_14 * V_15 )
{
if ( V_15 -> V_123 == F_85 ( V_138 ) )
return V_137 -> V_131 ;
else if ( V_15 -> V_123 == F_85 ( V_139 ) )
return F_86 ( ( const struct V_140 * ) V_137 ) ;
else
return 0 ;
}
static inline T_4 F_87 ( T_4 V_131 ,
const struct V_108 * V_137 ,
const struct V_14 * V_15 )
{
T_4 V_141 = F_84 ( V_137 , V_15 ) ;
return F_88 ( V_131 , V_141 ) ;
}
static V_53 F_89 ( struct V_9 * V_10 , struct V_14 * V_15 )
{
const struct V_142 * V_143 = (struct V_142 * ) V_15 -> V_115 ;
const struct V_16 * V_65 ;
if ( F_90 ( V_143 -> V_144 ) )
return V_10 -> V_101 ;
V_65 = F_29 ( V_10 , V_143 -> V_144 ) ;
if ( V_65 )
return V_65 -> V_45 ;
else
return V_10 -> V_101 ;
}
static void F_91 ( struct V_14 * V_15 )
{
F_92 ( V_15 -> V_103 ) ;
}
static void F_93 ( struct V_82 * V_35 , struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( F_18 ( V_35 ) , V_6 ) ;
struct V_102 * V_103 = V_5 -> V_102 -> V_103 ;
F_94 ( V_15 ) ;
F_95 ( V_103 ) ;
V_15 -> V_103 = V_103 ;
V_15 -> V_145 = F_91 ;
}
static T_6 F_96 ( const struct V_9 * V_10 , struct V_14 * V_15 )
{
unsigned int V_146 = ( V_10 -> V_147 - V_10 -> V_148 ) + 1 ;
T_1 V_149 ;
V_149 = F_97 ( V_15 ) ;
if ( ! V_149 )
V_149 = F_98 ( V_15 -> V_115 , 2 * V_42 ,
( V_150 T_1 ) V_15 -> V_123 ) ;
return ( ( ( T_3 ) V_149 * V_146 ) >> 32 ) + V_10 -> V_148 ;
}
static T_8 F_99 ( struct V_14 * V_15 , struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
struct V_151 * V_152 ;
const struct V_108 * V_153 ;
struct V_108 * V_137 ;
struct V_110 * V_111 ;
struct V_114 * V_154 ;
struct V_155 V_156 ;
unsigned int V_157 = V_15 -> V_136 ;
V_53 V_158 ;
T_5 V_159 ;
T_9 V_160 = 0 ;
T_10 V_131 , V_161 ;
int V_54 ;
V_158 = F_89 ( V_10 , V_15 ) ;
if ( ! V_158 )
goto V_119;
if ( F_100 ( V_15 , V_162 ) )
goto V_119;
V_153 = F_71 ( V_15 ) ;
V_161 = V_10 -> V_161 ;
if ( ! V_161 && F_101 ( F_69 ( V_158 ) ) )
V_161 = 1 ;
V_131 = V_10 -> V_131 ;
if ( V_131 == 1 )
V_131 = F_84 ( V_153 , V_15 ) ;
V_159 = F_96 ( V_10 , V_15 ) ;
memset ( & V_156 , 0 , sizeof( V_156 ) ) ;
V_156 . V_163 = V_10 -> V_164 ;
V_156 . V_165 = F_102 ( V_131 ) ;
V_156 . V_166 = V_158 ;
V_156 . V_127 = V_10 -> V_127 ;
V_152 = F_103 ( F_18 ( V_35 ) , & V_156 ) ;
if ( F_104 ( V_152 ) ) {
F_32 ( V_35 , L_9 , & V_158 ) ;
V_35 -> V_113 . V_167 ++ ;
goto V_168;
}
if ( V_152 -> V_158 . V_35 == V_35 ) {
F_32 ( V_35 , L_10 , & V_158 ) ;
F_105 ( V_152 ) ;
V_35 -> V_113 . V_169 ++ ;
goto V_168;
}
memset ( & ( F_106 ( V_15 ) -> V_170 ) , 0 , sizeof( F_106 ( V_15 ) -> V_170 ) ) ;
F_106 ( V_15 ) -> V_20 &= ~ ( V_171 | V_172 |
V_173 ) ;
F_107 ( V_15 ) ;
F_108 ( V_15 , & V_152 -> V_158 ) ;
V_111 = (struct V_110 * ) F_83 ( V_15 , sizeof( * V_111 ) ) ;
V_111 -> V_116 = F_68 ( V_117 ) ;
V_111 -> V_118 = F_68 ( V_10 -> V_13 << 8 ) ;
F_83 ( V_15 , sizeof( * V_154 ) ) ;
F_109 ( V_15 ) ;
V_154 = F_110 ( V_15 ) ;
V_154 -> V_174 = F_85 ( V_175 ) ;
V_154 -> V_176 = F_85 ( V_159 ) ;
V_154 -> V_136 = F_85 ( V_15 -> V_136 ) ;
V_154 -> V_177 = 0 ;
F_83 ( V_15 , sizeof( * V_137 ) ) ;
F_75 ( V_15 ) ;
V_137 = F_71 ( V_15 ) ;
V_137 -> V_178 = 4 ;
V_137 -> V_179 = sizeof( struct V_108 ) >> 2 ;
V_137 -> V_180 = V_160 ;
V_137 -> V_123 = V_181 ;
V_137 -> V_131 = F_87 ( V_131 , V_153 , V_15 ) ;
V_137 -> V_166 = V_158 ;
V_137 -> V_127 = V_156 . V_127 ;
V_137 -> V_161 = V_161 ? : F_111 ( & V_152 -> V_158 ) ;
F_93 ( V_35 , V_15 ) ;
V_15 -> V_128 = V_129 ;
F_112 ( V_137 , & V_152 -> V_158 , NULL ) ;
V_54 = F_113 ( V_15 ) ;
if ( F_49 ( F_114 ( V_54 ) == 0 ) ) {
struct V_112 * V_113 = F_79 ( V_10 -> V_113 ) ;
F_80 ( & V_113 -> V_133 ) ;
V_113 -> V_182 ++ ;
V_113 -> V_183 += V_157 ;
F_81 ( & V_113 -> V_133 ) ;
} else {
V_35 -> V_113 . V_184 ++ ;
V_35 -> V_113 . V_185 ++ ;
}
return V_186 ;
V_119:
V_35 -> V_113 . V_187 ++ ;
goto V_188;
V_168:
V_35 -> V_113 . V_184 ++ ;
V_188:
F_115 ( V_15 ) ;
return V_186 ;
}
static void F_116 ( unsigned long V_189 )
{
struct V_9 * V_10 = (struct V_9 * ) V_189 ;
unsigned long V_190 = V_22 + V_191 ;
unsigned int V_91 ;
if ( ! F_56 ( V_10 -> V_35 ) )
return;
F_43 ( & V_10 -> V_87 ) ;
for ( V_91 = 0 ; V_91 < V_92 ; ++ V_91 ) {
struct V_11 * V_192 , * V_93 ;
F_117 (p, n, &vxlan->fdb_head[h]) {
struct V_16 * V_65
= F_118 ( V_192 , struct V_16 , V_76 ) ;
unsigned long V_193 ;
if ( V_65 -> V_33 & V_83 )
continue;
V_193 = V_65 -> V_47 + V_10 -> V_194 * V_195 ;
if ( F_119 ( V_193 , V_22 ) ) {
F_32 ( V_10 -> V_35 ,
L_11 ,
V_65 -> V_43 ) ;
V_65 -> V_33 = V_196 ;
F_35 ( V_10 , V_65 ) ;
} else if ( F_120 ( V_193 , V_190 ) )
V_190 = V_193 ;
}
}
F_44 ( & V_10 -> V_87 ) ;
F_121 ( & V_10 -> V_197 , V_190 ) ;
}
static int F_122 ( struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
V_10 -> V_113 = F_123 ( struct V_112 ) ;
if ( ! V_10 -> V_113 )
return - V_75 ;
return 0 ;
}
static int F_124 ( struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
int V_54 ;
if ( V_10 -> V_101 ) {
V_54 = F_57 ( V_35 ) ;
if ( V_54 )
return V_54 ;
}
if ( V_10 -> V_194 )
F_121 ( & V_10 -> V_197 , V_22 + V_191 ) ;
return 0 ;
}
static void F_125 ( struct V_9 * V_10 )
{
unsigned V_91 ;
F_43 ( & V_10 -> V_87 ) ;
for ( V_91 = 0 ; V_91 < V_92 ; ++ V_91 ) {
struct V_11 * V_192 , * V_93 ;
F_117 (p, n, &vxlan->fdb_head[h]) {
struct V_16 * V_65
= F_118 ( V_192 , struct V_16 , V_76 ) ;
F_35 ( V_10 , V_65 ) ;
}
}
F_44 ( & V_10 -> V_87 ) ;
}
static int F_126 ( struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
if ( V_10 -> V_101 )
F_63 ( V_35 ) ;
F_127 ( & V_10 -> V_197 ) ;
F_125 ( V_10 ) ;
return 0 ;
}
static struct V_198 * F_128 ( struct V_82 * V_35 ,
struct V_198 * V_113 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
struct V_112 V_199 , V_200 = { 0 } ;
unsigned int V_201 ;
F_129 (cpu) {
unsigned int V_202 ;
const struct V_112 * V_113
= F_130 ( V_10 -> V_113 , V_201 ) ;
do {
V_202 = F_131 ( & V_113 -> V_133 ) ;
memcpy ( & V_199 , V_113 , sizeof( V_199 ) ) ;
} while ( F_132 ( & V_113 -> V_133 , V_202 ) );
V_200 . V_183 += V_199 . V_183 ;
V_200 . V_182 += V_199 . V_182 ;
V_200 . V_135 += V_199 . V_135 ;
V_200 . V_134 += V_199 . V_134 ;
}
V_113 -> V_183 = V_200 . V_183 ;
V_113 -> V_182 = V_200 . V_182 ;
V_113 -> V_135 = V_200 . V_135 ;
V_113 -> V_134 = V_200 . V_134 ;
V_113 -> V_203 = V_35 -> V_113 . V_203 ;
V_113 -> V_121 = V_35 -> V_113 . V_121 ;
V_113 -> V_132 = V_35 -> V_113 . V_132 ;
V_113 -> V_122 = V_35 -> V_113 . V_122 ;
V_113 -> V_187 = V_35 -> V_113 . V_187 ;
V_113 -> V_167 = V_35 -> V_113 . V_167 ;
V_113 -> V_185 = V_35 -> V_113 . V_185 ;
V_113 -> V_169 = V_35 -> V_113 . V_169 ;
V_113 -> V_184 = V_35 -> V_113 . V_184 ;
return V_113 ;
}
static void F_133 ( struct V_82 * V_35 )
{
}
static void F_134 ( struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
F_135 ( V_10 -> V_113 ) ;
F_136 ( V_35 ) ;
}
static void F_137 ( struct V_82 * V_35 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
unsigned V_91 ;
int V_204 , V_205 ;
F_138 ( V_35 ) ;
F_139 ( V_35 ) ;
V_35 -> V_206 = V_120 + V_162 ;
V_35 -> V_207 = & V_208 ;
V_35 -> V_145 = F_134 ;
F_140 ( V_35 , & V_209 ) ;
V_35 -> V_210 = 0 ;
V_35 -> V_211 |= V_212 ;
V_35 -> V_211 |= V_213 ;
V_35 -> V_214 &= ~ V_215 ;
F_141 ( & V_10 -> V_87 ) ;
F_142 ( & V_10 -> V_197 ) ;
V_10 -> V_197 . V_216 = F_116 ;
V_10 -> V_197 . V_115 = ( unsigned long ) V_10 ;
F_143 ( & V_204 , & V_205 ) ;
V_10 -> V_148 = V_204 ;
V_10 -> V_147 = V_205 ;
V_10 -> V_35 = V_35 ;
for ( V_91 = 0 ; V_91 < V_92 ; ++ V_91 )
F_144 ( & V_10 -> V_63 [ V_91 ] ) ;
}
static int F_145 ( struct V_80 * V_81 [] , struct V_80 * V_115 [] )
{
if ( V_81 [ V_217 ] ) {
if ( F_41 ( V_81 [ V_217 ] ) != V_42 ) {
F_146 ( L_12 ) ;
return - V_85 ;
}
if ( ! F_147 ( F_148 ( V_81 [ V_217 ] ) ) ) {
F_146 ( L_13 ) ;
return - V_218 ;
}
}
if ( ! V_115 )
return - V_85 ;
if ( V_115 [ V_219 ] ) {
T_7 V_3 = F_149 ( V_115 [ V_219 ] ) ;
if ( V_3 >= V_220 )
return - V_221 ;
}
if ( V_115 [ V_222 ] ) {
V_53 V_101 = F_42 ( V_115 [ V_222 ] ) ;
if ( ! F_101 ( F_69 ( V_101 ) ) ) {
F_146 ( L_14 ) ;
return - V_218 ;
}
}
if ( V_115 [ V_223 ] ) {
const struct V_224 * V_192
= F_148 ( V_115 [ V_223 ] ) ;
if ( F_150 ( V_192 -> V_205 ) < F_150 ( V_192 -> V_204 ) ) {
F_146 ( L_15 ,
F_150 ( V_192 -> V_204 ) , F_150 ( V_192 -> V_205 ) ) ;
return - V_85 ;
}
}
return 0 ;
}
static int F_151 ( struct V_2 * V_2 , struct V_82 * V_35 ,
struct V_80 * V_81 [] , struct V_80 * V_115 [] )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
T_7 V_13 ;
int V_54 ;
if ( ! V_115 [ V_219 ] )
return - V_85 ;
V_13 = F_149 ( V_115 [ V_219 ] ) ;
if ( F_4 ( V_2 , V_13 ) ) {
F_40 ( L_16 , V_13 ) ;
return - V_69 ;
}
V_10 -> V_13 = V_13 ;
if ( V_115 [ V_222 ] )
V_10 -> V_101 = F_42 ( V_115 [ V_222 ] ) ;
if ( V_115 [ V_225 ] )
V_10 -> V_127 = F_42 ( V_115 [ V_225 ] ) ;
if ( V_115 [ V_226 ] &&
( V_10 -> V_164 = F_149 ( V_115 [ V_226 ] ) ) ) {
struct V_82 * V_227
= F_152 ( V_2 , V_10 -> V_164 ) ;
if ( ! V_227 ) {
F_40 ( L_17 , V_10 -> V_164 ) ;
return - V_228 ;
}
if ( ! V_81 [ V_229 ] )
V_35 -> V_230 = V_227 -> V_230 - V_162 ;
V_35 -> V_206 = V_227 -> V_206 +
V_162 ;
}
if ( V_115 [ V_231 ] )
V_10 -> V_131 = F_153 ( V_115 [ V_231 ] ) ;
if ( ! V_115 [ V_232 ] || F_153 ( V_115 [ V_232 ] ) )
V_10 -> V_126 = true ;
if ( V_115 [ V_233 ] )
V_10 -> V_194 = F_149 ( V_115 [ V_233 ] ) ;
else
V_10 -> V_194 = V_234 ;
if ( V_115 [ V_235 ] )
V_10 -> V_72 = F_149 ( V_115 [ V_235 ] ) ;
if ( V_115 [ V_223 ] ) {
const struct V_224 * V_192
= F_148 ( V_115 [ V_223 ] ) ;
V_10 -> V_148 = F_150 ( V_192 -> V_204 ) ;
V_10 -> V_147 = F_150 ( V_192 -> V_205 ) ;
}
V_54 = F_154 ( V_35 ) ;
if ( ! V_54 )
F_34 ( & V_10 -> V_76 , F_1 ( V_2 , V_10 -> V_13 ) ) ;
return V_54 ;
}
static void F_155 ( struct V_82 * V_35 , struct V_236 * V_64 )
{
struct V_9 * V_10 = F_39 ( V_35 ) ;
F_36 ( & V_10 -> V_76 ) ;
F_156 ( V_35 , V_64 ) ;
}
static T_2 F_157 ( const struct V_82 * V_35 )
{
return F_16 ( sizeof( T_7 ) ) +
F_16 ( sizeof( V_53 ) ) +
F_16 ( sizeof( T_7 ) ) +
F_16 ( sizeof( V_53 ) ) +
F_16 ( sizeof( T_10 ) ) +
F_16 ( sizeof( T_10 ) ) +
F_16 ( sizeof( T_10 ) ) +
F_16 ( sizeof( T_7 ) ) +
F_16 ( sizeof( T_7 ) ) +
F_16 ( sizeof( struct V_224 ) ) +
0 ;
}
static int F_158 ( struct V_14 * V_15 , const struct V_82 * V_35 )
{
const struct V_9 * V_10 = F_39 ( V_35 ) ;
struct V_224 V_237 = {
. V_204 = F_85 ( V_10 -> V_148 ) ,
. V_205 = F_85 ( V_10 -> V_147 ) ,
} ;
if ( F_159 ( V_15 , V_219 , V_10 -> V_13 ) )
goto V_44;
if ( V_10 -> V_101 && F_10 ( V_15 , V_222 , V_10 -> V_101 ) )
goto V_44;
if ( V_10 -> V_164 && F_159 ( V_15 , V_226 , V_10 -> V_164 ) )
goto V_44;
if ( V_10 -> V_127 && F_10 ( V_15 , V_225 , V_10 -> V_127 ) )
goto V_44;
if ( F_160 ( V_15 , V_238 , V_10 -> V_161 ) ||
F_160 ( V_15 , V_231 , V_10 -> V_131 ) ||
F_160 ( V_15 , V_232 , V_10 -> V_126 ) ||
F_159 ( V_15 , V_233 , V_10 -> V_194 ) ||
F_159 ( V_15 , V_235 , V_10 -> V_72 ) )
goto V_44;
if ( F_9 ( V_15 , V_223 , sizeof( V_237 ) , & V_237 ) )
goto V_44;
return 0 ;
V_44:
return - V_29 ;
}
static T_11 int F_161 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
struct V_102 * V_103 ;
struct V_239 V_240 = {
. V_241 = V_242 ,
. V_243 . V_107 = F_68 ( V_244 ) ,
} ;
int V_245 ;
unsigned V_91 ;
V_245 = F_162 ( V_242 , V_246 , V_181 , & V_5 -> V_102 ) ;
if ( V_245 < 0 ) {
F_146 ( L_18 ) ;
return V_245 ;
}
V_103 = V_5 -> V_102 -> V_103 ;
F_163 ( V_103 , V_2 ) ;
V_240 . V_247 = F_85 ( V_175 ) ;
V_245 = F_164 ( V_5 -> V_102 , (struct V_248 * ) & V_240 ,
sizeof( V_240 ) ) ;
if ( V_245 < 0 ) {
F_146 ( L_19 ,
& V_240 . V_243 , F_150 ( V_240 . V_247 ) , V_245 ) ;
F_165 ( V_103 ) ;
V_5 -> V_102 = NULL ;
return V_245 ;
}
F_166 ( V_103 ) -> V_249 = 0 ;
F_167 ( V_103 ) -> V_250 = 1 ;
F_167 ( V_103 ) -> V_251 = F_65 ;
F_168 () ;
for ( V_91 = 0 ; V_91 < V_100 ; ++ V_91 )
F_144 ( & V_5 -> V_7 [ V_91 ] ) ;
return 0 ;
}
static T_12 void F_169 ( struct V_2 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_5 -> V_102 ) {
F_165 ( V_5 -> V_102 -> V_103 ) ;
V_5 -> V_102 = NULL ;
}
}
static int T_13 F_170 ( void )
{
int V_245 ;
F_171 ( & V_252 , sizeof( V_252 ) ) ;
V_245 = F_172 ( & V_253 ) ;
if ( V_245 )
goto V_254;
V_245 = F_173 ( & V_255 ) ;
if ( V_245 )
goto V_256;
return 0 ;
V_256:
F_174 ( & V_253 ) ;
V_254:
return V_245 ;
}
static void T_14 F_175 ( void )
{
F_176 ( & V_255 ) ;
F_174 ( & V_253 ) ;
}
