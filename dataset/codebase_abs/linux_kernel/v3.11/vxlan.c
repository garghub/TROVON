static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
return & V_3 -> V_5 [ F_2 ( V_4 , V_6 ) ] ;
}
static inline struct V_1 * F_3 ( struct V_7 * V_7 , T_2 V_8 )
{
struct V_9 * V_10 = F_4 ( V_7 , V_11 ) ;
return & V_10 -> V_12 [ F_2 ( F_5 ( V_8 ) , V_13 ) ] ;
}
static inline struct V_14 * F_6 ( struct V_15 * V_16 )
{
return F_7 ( & V_16 -> V_17 , struct V_14 , V_18 ) ;
}
static struct V_2 * F_8 ( struct V_7 * V_7 , T_2 V_8 )
{
struct V_2 * V_3 ;
F_9 (vs, vs_head(net, port), hlist) {
if ( F_10 ( V_3 -> V_19 -> V_20 ) -> V_21 == V_8 )
return V_3 ;
}
return NULL ;
}
static struct V_22 * F_11 ( struct V_7 * V_7 , T_1 V_4 , T_2 V_8 )
{
struct V_2 * V_3 ;
struct V_22 * V_23 ;
V_3 = F_8 ( V_7 , V_8 ) ;
if ( ! V_3 )
return NULL ;
F_9 (vxlan, vni_head(vs, id), hlist) {
if ( V_23 -> V_24 . V_25 == V_4 )
return V_23 ;
}
return NULL ;
}
static int F_12 ( struct V_26 * V_27 , struct V_22 * V_23 ,
const struct V_15 * V_16 ,
T_1 V_28 , T_1 V_29 , int type , unsigned int V_30 ,
const struct V_14 * V_31 )
{
unsigned long V_32 = V_33 ;
struct V_34 V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
bool V_40 , V_41 ;
V_37 = F_13 ( V_27 , V_28 , V_29 , type , sizeof( * V_39 ) , V_30 ) ;
if ( V_37 == NULL )
return - V_42 ;
V_39 = F_14 ( V_37 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_41 = V_40 = true ;
if ( type == V_43 ) {
V_39 -> V_44 = V_45 ;
V_40 = V_31 -> V_46 != F_15 ( V_47 ) ;
V_41 = ! F_16 ( V_16 -> V_48 ) ;
} else
V_39 -> V_44 = V_49 ;
V_39 -> V_50 = V_16 -> V_51 ;
V_39 -> V_52 = V_23 -> V_53 -> V_54 ;
V_39 -> V_55 = V_16 -> V_30 ;
V_39 -> V_56 = V_57 ;
if ( V_41 && F_17 ( V_27 , V_58 , V_59 , & V_16 -> V_48 ) )
goto V_60;
if ( V_40 && F_18 ( V_27 , V_57 , V_31 -> V_46 ) )
goto V_60;
if ( V_31 -> V_61 && V_31 -> V_61 != V_23 -> V_62 &&
F_19 ( V_27 , V_63 , V_31 -> V_61 ) )
goto V_60;
if ( V_31 -> V_25 != V_23 -> V_24 . V_25 &&
F_20 ( V_27 , V_64 , V_31 -> V_25 ) )
goto V_60;
if ( V_31 -> V_65 &&
F_20 ( V_27 , V_66 , V_31 -> V_65 ) )
goto V_60;
V_35 . V_67 = F_21 ( V_32 - V_16 -> V_68 ) ;
V_35 . V_69 = 0 ;
V_35 . V_70 = F_21 ( V_32 - V_16 -> V_71 ) ;
V_35 . V_72 = 0 ;
if ( F_17 ( V_27 , V_73 , sizeof( V_35 ) , & V_35 ) )
goto V_60;
return F_22 ( V_27 , V_37 ) ;
V_60:
F_23 ( V_27 , V_37 ) ;
return - V_42 ;
}
static inline T_3 F_24 ( void )
{
return F_25 ( sizeof( struct V_38 ) )
+ F_26 ( V_59 )
+ F_26 ( sizeof( V_74 ) )
+ F_26 ( sizeof( T_2 ) )
+ F_26 ( sizeof( V_74 ) )
+ F_26 ( sizeof( V_75 ) )
+ F_26 ( sizeof( struct V_34 ) ) ;
}
static void F_27 ( struct V_22 * V_23 ,
struct V_15 * V_16 , int type )
{
struct V_7 * V_7 = F_28 ( V_23 -> V_53 ) ;
struct V_26 * V_27 ;
int V_76 = - V_77 ;
V_27 = F_29 ( F_24 () , V_78 ) ;
if ( V_27 == NULL )
goto V_79;
V_76 = F_12 ( V_27 , V_23 , V_16 , 0 , 0 , type , 0 , F_6 ( V_16 ) ) ;
if ( V_76 < 0 ) {
F_30 ( V_76 == - V_42 ) ;
F_31 ( V_27 ) ;
goto V_79;
}
F_32 ( V_27 , V_7 , 0 , V_80 , NULL , V_78 ) ;
return;
V_79:
if ( V_76 < 0 )
F_33 ( V_7 , V_80 , V_76 ) ;
}
static void F_34 ( struct V_81 * V_53 , V_74 V_82 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_15 V_83 = {
. V_51 = V_84 ,
} ;
struct V_14 V_85 = {
. V_46 = V_82 ,
. V_25 = V_86 ,
} ;
F_36 ( & V_83 . V_17 ) ;
F_37 ( & V_85 . V_18 , & V_83 . V_17 ) ;
F_27 ( V_23 , & V_83 , V_43 ) ;
}
static void F_38 ( struct V_22 * V_23 , const T_4 V_48 [ V_59 ] )
{
struct V_15 V_83 = {
. V_51 = V_84 ,
} ;
F_36 ( & V_83 . V_17 ) ;
memcpy ( V_83 . V_48 , V_48 , V_59 ) ;
F_27 ( V_23 , & V_83 , V_43 ) ;
}
static T_1 F_39 ( const unsigned char * V_87 )
{
T_5 V_88 = F_40 ( ( T_5 * ) V_87 ) ;
#ifdef F_41
V_88 >>= 16 ;
#else
V_88 <<= 16 ;
#endif
return F_42 ( V_88 , V_89 ) ;
}
static inline struct V_1 * F_43 ( struct V_22 * V_23 ,
const T_4 * V_90 )
{
return & V_23 -> V_91 [ F_39 ( V_90 ) ] ;
}
static struct V_15 * F_44 ( struct V_22 * V_23 ,
const T_4 * V_90 )
{
struct V_1 * V_92 = F_43 ( V_23 , V_90 ) ;
struct V_15 * V_83 ;
F_9 (f, head, hlist) {
if ( F_45 ( V_90 , V_83 -> V_48 ) == 0 )
return V_83 ;
}
return NULL ;
}
static struct V_15 * F_46 ( struct V_22 * V_23 ,
const T_4 * V_90 )
{
struct V_15 * V_83 ;
V_83 = F_44 ( V_23 , V_90 ) ;
if ( V_83 )
V_83 -> V_68 = V_33 ;
return V_83 ;
}
static struct V_14 * F_47 ( struct V_15 * V_83 ,
V_74 V_93 , T_2 V_8 ,
V_75 V_94 , V_75 V_54 )
{
struct V_14 * V_95 ;
F_48 (rd, &f->remotes, list) {
if ( V_95 -> V_46 == V_93 &&
V_95 -> V_61 == V_8 &&
V_95 -> V_25 == V_94 &&
V_95 -> V_65 == V_54 )
return V_95 ;
}
return NULL ;
}
static int F_49 ( struct V_15 * V_83 ,
V_74 V_93 , T_2 V_8 , V_75 V_94 , V_75 V_54 )
{
struct V_14 * V_95 ;
V_95 = F_47 ( V_83 , V_93 , V_8 , V_94 , V_54 ) ;
if ( V_95 )
return 0 ;
V_95 = F_50 ( sizeof( * V_95 ) , V_78 ) ;
if ( V_95 == NULL )
return - V_77 ;
V_95 -> V_46 = V_93 ;
V_95 -> V_61 = V_8 ;
V_95 -> V_25 = V_94 ;
V_95 -> V_65 = V_54 ;
F_51 ( & V_95 -> V_18 , & V_83 -> V_17 ) ;
return 1 ;
}
static int F_52 ( struct V_22 * V_23 ,
const T_4 * V_90 , V_74 V_93 ,
T_6 V_51 , T_6 V_30 ,
T_2 V_8 , V_75 V_94 , V_75 V_54 ,
T_7 V_55 )
{
struct V_15 * V_83 ;
int V_96 = 0 ;
V_83 = F_44 ( V_23 , V_90 ) ;
if ( V_83 ) {
if ( V_30 & V_97 ) {
F_53 ( V_23 -> V_53 ,
L_1 , V_90 ) ;
return - V_98 ;
}
if ( V_83 -> V_51 != V_51 ) {
V_83 -> V_51 = V_51 ;
V_83 -> V_71 = V_33 ;
V_96 = 1 ;
}
if ( V_83 -> V_30 != V_55 ) {
V_83 -> V_30 = V_55 ;
V_83 -> V_71 = V_33 ;
V_96 = 1 ;
}
if ( ( V_30 & V_99 ) &&
( F_54 ( V_83 -> V_48 ) ||
F_16 ( V_83 -> V_48 ) ) ) {
int V_100 = F_49 ( V_83 , V_93 , V_8 , V_94 , V_54 ) ;
if ( V_100 < 0 )
return V_100 ;
V_96 |= V_100 ;
}
} else {
if ( ! ( V_30 & V_101 ) )
return - V_102 ;
if ( V_23 -> V_103 && V_23 -> V_104 >= V_23 -> V_103 )
return - V_105 ;
F_53 ( V_23 -> V_53 , L_2 , V_90 , & V_93 ) ;
V_83 = F_50 ( sizeof( * V_83 ) , V_78 ) ;
if ( ! V_83 )
return - V_106 ;
V_96 = 1 ;
V_83 -> V_51 = V_51 ;
V_83 -> V_30 = V_55 ;
V_83 -> V_71 = V_83 -> V_68 = V_33 ;
F_36 ( & V_83 -> V_17 ) ;
memcpy ( V_83 -> V_48 , V_90 , V_59 ) ;
F_49 ( V_83 , V_93 , V_8 , V_94 , V_54 ) ;
++ V_23 -> V_104 ;
F_55 ( & V_83 -> V_107 ,
F_43 ( V_23 , V_90 ) ) ;
}
if ( V_96 )
F_27 ( V_23 , V_83 , V_108 ) ;
return 0 ;
}
static void F_56 ( struct V_109 * V_92 )
{
struct V_14 * V_95 = F_57 ( V_92 , struct V_14 , V_110 ) ;
F_58 ( V_95 ) ;
}
static void F_59 ( struct V_109 * V_92 )
{
struct V_15 * V_83 = F_57 ( V_92 , struct V_15 , V_110 ) ;
struct V_14 * V_95 , * V_111 ;
F_60 (rd, nd, &f->remotes, list)
F_58 ( V_95 ) ;
F_58 ( V_83 ) ;
}
static void F_61 ( struct V_22 * V_23 , struct V_15 * V_83 )
{
F_53 ( V_23 -> V_53 ,
L_3 , V_83 -> V_48 ) ;
-- V_23 -> V_104 ;
F_27 ( V_23 , V_83 , V_112 ) ;
F_62 ( & V_83 -> V_107 ) ;
F_63 ( & V_83 -> V_110 , F_59 ) ;
}
static int F_64 ( struct V_113 * V_114 [] , struct V_22 * V_23 ,
V_74 * V_93 , T_2 * V_8 , T_1 * V_94 , T_1 * V_54 )
{
struct V_7 * V_7 = F_28 ( V_23 -> V_53 ) ;
if ( V_114 [ V_57 ] ) {
if ( F_65 ( V_114 [ V_57 ] ) != sizeof( V_74 ) )
return - V_115 ;
* V_93 = F_66 ( V_114 [ V_57 ] ) ;
} else {
* V_93 = F_15 ( V_47 ) ;
}
if ( V_114 [ V_63 ] ) {
if ( F_65 ( V_114 [ V_63 ] ) != sizeof( T_2 ) )
return - V_116 ;
* V_8 = F_67 ( V_114 [ V_63 ] ) ;
} else {
* V_8 = V_23 -> V_62 ;
}
if ( V_114 [ V_64 ] ) {
if ( F_65 ( V_114 [ V_64 ] ) != sizeof( T_1 ) )
return - V_116 ;
* V_94 = F_68 ( V_114 [ V_64 ] ) ;
} else {
* V_94 = V_23 -> V_24 . V_25 ;
}
if ( V_114 [ V_66 ] ) {
struct V_81 * V_117 ;
if ( F_65 ( V_114 [ V_66 ] ) != sizeof( T_1 ) )
return - V_116 ;
* V_54 = F_68 ( V_114 [ V_66 ] ) ;
V_117 = F_69 ( V_7 , * V_54 ) ;
if ( ! V_117 )
return - V_118 ;
F_70 ( V_117 ) ;
} else {
* V_54 = 0 ;
}
return 0 ;
}
static int F_71 ( struct V_38 * V_39 , struct V_113 * V_114 [] ,
struct V_81 * V_53 ,
const unsigned char * V_87 , T_8 V_30 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
V_74 V_93 ;
T_2 V_8 ;
T_1 V_94 , V_54 ;
int V_76 ;
if ( ! ( V_39 -> V_50 & ( V_119 | V_120 ) ) ) {
F_72 ( L_4 ,
V_39 -> V_50 ) ;
return - V_116 ;
}
if ( V_114 [ V_57 ] == NULL )
return - V_116 ;
V_76 = F_64 ( V_114 , V_23 , & V_93 , & V_8 , & V_94 , & V_54 ) ;
if ( V_76 )
return V_76 ;
F_73 ( & V_23 -> V_121 ) ;
V_76 = F_52 ( V_23 , V_87 , V_93 , V_39 -> V_50 , V_30 ,
V_8 , V_94 , V_54 , V_39 -> V_55 ) ;
F_74 ( & V_23 -> V_121 ) ;
return V_76 ;
}
static int F_75 ( struct V_38 * V_39 , struct V_113 * V_114 [] ,
struct V_81 * V_53 ,
const unsigned char * V_87 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_15 * V_83 ;
struct V_14 * V_95 = NULL ;
V_74 V_93 ;
T_2 V_8 ;
T_1 V_94 , V_54 ;
int V_76 ;
V_76 = F_64 ( V_114 , V_23 , & V_93 , & V_8 , & V_94 , & V_54 ) ;
if ( V_76 )
return V_76 ;
V_76 = - V_102 ;
F_73 ( & V_23 -> V_121 ) ;
V_83 = F_46 ( V_23 , V_87 ) ;
if ( ! V_83 )
goto V_122;
if ( V_93 != F_15 ( V_47 ) ) {
V_95 = F_47 ( V_83 , V_93 , V_8 , V_94 , V_54 ) ;
if ( ! V_95 )
goto V_122;
}
V_76 = 0 ;
if ( V_95 && ! F_76 ( & V_83 -> V_17 ) ) {
F_77 ( & V_95 -> V_18 ) ;
F_63 ( & V_95 -> V_110 , F_56 ) ;
goto V_122;
}
F_61 ( V_23 , V_83 ) ;
V_122:
F_74 ( & V_23 -> V_121 ) ;
return V_76 ;
}
static int F_78 ( struct V_26 * V_27 , struct V_123 * V_124 ,
struct V_81 * V_53 , int V_125 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
unsigned int V_126 ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
struct V_15 * V_83 ;
int V_76 ;
F_9 (f, &vxlan->fdb_head[h], hlist) {
struct V_14 * V_95 ;
if ( V_125 < V_124 -> args [ 0 ] )
goto V_128;
F_79 (rd, &f->remotes, list) {
V_76 = F_12 ( V_27 , V_23 , V_83 ,
F_80 ( V_124 -> V_27 ) . V_28 ,
V_124 -> V_37 -> V_129 ,
V_108 ,
V_130 , V_95 ) ;
if ( V_76 < 0 )
goto V_122;
}
V_128:
++ V_125 ;
}
}
V_122:
return V_125 ;
}
static bool F_81 ( struct V_81 * V_53 ,
V_74 V_131 , const T_4 * V_132 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_15 * V_83 ;
V_83 = F_46 ( V_23 , V_132 ) ;
if ( F_82 ( V_83 ) ) {
struct V_14 * V_31 = F_6 ( V_83 ) ;
if ( F_82 ( V_31 -> V_46 == V_131 ) )
return false ;
if ( V_83 -> V_51 & V_133 )
return true ;
if ( F_83 () )
F_84 ( V_53 ,
L_5 ,
V_132 , & V_31 -> V_46 , & V_131 ) ;
V_31 -> V_46 = V_131 ;
V_83 -> V_71 = V_33 ;
F_27 ( V_23 , V_83 , V_108 ) ;
} else {
F_85 ( & V_23 -> V_121 ) ;
if ( F_86 ( V_53 ) )
F_52 ( V_23 , V_132 , V_131 ,
V_120 ,
V_97 | V_101 ,
V_23 -> V_62 ,
V_23 -> V_24 . V_25 ,
0 , V_134 ) ;
F_87 ( & V_23 -> V_121 ) ;
}
return false ;
}
static bool F_88 ( struct V_9 * V_10 , V_74 V_46 )
{
struct V_22 * V_23 ;
F_48 (vxlan, &vn->vxlan_list, next) {
if ( ! F_86 ( V_23 -> V_53 ) )
continue;
if ( V_23 -> V_24 . V_46 == V_46 )
return true ;
}
return false ;
}
static void F_89 ( struct V_2 * V_3 )
{
F_90 ( & V_3 -> V_135 ) ;
}
static void F_91 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
if ( ! F_92 ( & V_3 -> V_135 ) )
return;
F_85 ( & V_10 -> V_136 ) ;
F_62 ( & V_3 -> V_107 ) ;
F_87 ( & V_10 -> V_136 ) ;
F_93 ( V_137 , & V_3 -> V_138 ) ;
}
static void F_94 ( struct V_139 * V_140 )
{
struct V_22 * V_23 = F_57 ( V_140 , struct V_22 , V_141 ) ;
struct V_9 * V_10 = F_4 ( F_28 ( V_23 -> V_53 ) , V_11 ) ;
struct V_2 * V_3 = V_23 -> V_142 ;
struct V_19 * V_20 = V_3 -> V_19 -> V_20 ;
struct V_143 V_144 = {
. V_145 . V_146 = V_23 -> V_24 . V_46 ,
. V_147 = V_23 -> V_24 . V_65 ,
} ;
F_95 ( V_20 ) ;
F_96 ( V_20 , & V_144 ) ;
F_97 ( V_20 ) ;
F_91 ( V_10 , V_3 ) ;
F_70 ( V_23 -> V_53 ) ;
}
static void F_98 ( struct V_139 * V_140 )
{
struct V_22 * V_23 = F_57 ( V_140 , struct V_22 , V_148 ) ;
struct V_9 * V_10 = F_4 ( F_28 ( V_23 -> V_53 ) , V_11 ) ;
struct V_2 * V_3 = V_23 -> V_142 ;
struct V_19 * V_20 = V_3 -> V_19 -> V_20 ;
struct V_143 V_144 = {
. V_145 . V_146 = V_23 -> V_24 . V_46 ,
. V_147 = V_23 -> V_24 . V_65 ,
} ;
F_95 ( V_20 ) ;
F_99 ( V_20 , & V_144 ) ;
F_97 ( V_20 ) ;
F_91 ( V_10 , V_3 ) ;
F_70 ( V_23 -> V_53 ) ;
}
static int F_100 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
struct V_22 * V_23 ;
struct V_153 * V_154 ;
T_2 V_8 ;
V_75 V_94 ;
int V_76 ;
F_101 ( V_27 , sizeof( struct V_155 ) ) ;
if ( ! F_102 ( V_27 , sizeof( struct V_151 ) ) )
goto error;
V_152 = (struct V_151 * ) V_27 -> V_156 ;
if ( V_152 -> V_157 != F_15 ( V_158 ) ||
( V_152 -> V_159 & F_15 ( 0xff ) ) ) {
F_53 ( V_27 -> V_53 , L_6 ,
F_103 ( V_152 -> V_157 ) , F_103 ( V_152 -> V_159 ) ) ;
goto error;
}
F_101 ( V_27 , sizeof( struct V_151 ) ) ;
V_94 = F_103 ( V_152 -> V_159 ) >> 8 ;
V_8 = F_10 ( V_20 ) -> V_21 ;
V_23 = F_11 ( F_104 ( V_20 ) , V_94 , V_8 ) ;
if ( ! V_23 ) {
F_53 ( V_27 -> V_53 , L_7 ,
V_94 , F_5 ( V_8 ) ) ;
goto V_160;
}
if ( ! F_102 ( V_27 , V_161 ) ) {
V_23 -> V_53 -> V_154 . V_162 ++ ;
V_23 -> V_53 -> V_154 . V_163 ++ ;
goto V_160;
}
F_105 ( V_27 ) ;
V_150 = F_106 ( V_27 ) ;
V_27 -> V_164 = F_107 ( V_27 , V_23 -> V_53 ) ;
if ( F_45 ( F_108 ( V_27 ) -> V_165 ,
V_23 -> V_53 -> V_166 ) == 0 )
goto V_160;
if ( ( V_23 -> V_30 & V_167 ) &&
F_81 ( V_27 -> V_53 , V_150 -> V_168 , F_108 ( V_27 ) -> V_165 ) )
goto V_160;
F_109 ( V_27 , V_23 -> V_53 ) ;
F_110 ( V_27 ) ;
if ( V_27 -> V_169 != V_170 || ! V_27 -> V_171 ||
! ( V_23 -> V_53 -> V_172 & V_173 ) )
V_27 -> V_169 = V_174 ;
V_27 -> V_171 = 0 ;
V_76 = F_111 ( V_150 , V_27 ) ;
if ( F_112 ( V_76 ) ) {
if ( V_175 )
F_113 ( L_8 ,
& V_150 -> V_168 , V_150 -> V_176 ) ;
if ( V_76 > 1 ) {
++ V_23 -> V_53 -> V_154 . V_177 ;
++ V_23 -> V_53 -> V_154 . V_163 ;
goto V_160;
}
}
V_154 = F_114 ( V_23 -> V_53 -> V_178 ) ;
F_115 ( & V_154 -> V_179 ) ;
V_154 -> V_180 ++ ;
V_154 -> V_181 += V_27 -> V_182 ;
F_116 ( & V_154 -> V_179 ) ;
F_117 ( V_27 ) ;
return 0 ;
error:
F_118 ( V_27 , sizeof( struct V_155 ) ) ;
return 1 ;
V_160:
F_31 ( V_27 ) ;
return 0 ;
}
static int F_119 ( struct V_81 * V_53 , struct V_26 * V_27 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_183 * V_184 ;
T_4 * V_185 , * V_186 ;
V_74 V_187 , V_188 ;
struct V_189 * V_190 ;
if ( V_53 -> V_30 & V_191 )
goto V_122;
if ( ! F_102 ( V_27 , F_120 ( V_53 ) ) ) {
V_53 -> V_154 . V_192 ++ ;
goto V_122;
}
V_184 = F_121 ( V_27 ) ;
if ( ( V_184 -> V_193 != F_122 ( V_194 ) &&
V_184 -> V_193 != F_122 ( V_195 ) ) ||
V_184 -> V_196 != F_122 ( V_197 ) ||
V_184 -> V_198 != F_122 ( V_199 ) ||
V_184 -> V_200 != V_53 -> V_201 ||
V_184 -> V_202 != 4 )
goto V_122;
V_185 = ( T_4 * ) V_184 + sizeof( struct V_183 ) ;
V_186 = V_185 ;
V_185 += V_53 -> V_201 ;
memcpy ( & V_187 , V_185 , sizeof( V_187 ) ) ;
V_185 += sizeof( V_187 ) ;
V_185 += V_53 -> V_201 ;
memcpy ( & V_188 , V_185 , sizeof( V_188 ) ) ;
if ( F_123 ( V_188 ) ||
F_124 ( V_188 ) )
goto V_122;
V_190 = F_125 ( & V_203 , & V_188 , V_53 ) ;
if ( V_190 ) {
struct V_15 * V_83 ;
struct V_26 * V_204 ;
if ( ! ( V_190 -> V_205 & V_206 ) ) {
F_126 ( V_190 ) ;
goto V_122;
}
V_83 = F_46 ( V_23 , V_190 -> V_207 ) ;
if ( V_83 && F_6 ( V_83 ) -> V_46 == F_15 ( V_47 ) ) {
F_126 ( V_190 ) ;
goto V_122;
}
V_204 = F_127 ( V_208 , V_209 , V_187 , V_53 , V_188 , V_186 ,
V_190 -> V_207 , V_186 ) ;
F_126 ( V_190 ) ;
F_105 ( V_204 ) ;
F_101 ( V_204 , F_128 ( V_204 ) ) ;
V_204 -> V_169 = V_170 ;
V_204 -> V_210 = V_211 ;
if ( F_129 ( V_204 ) == V_212 )
V_53 -> V_154 . V_213 ++ ;
} else if ( V_23 -> V_30 & V_214 )
F_34 ( V_53 , V_188 ) ;
V_122:
F_130 ( V_27 ) ;
return V_215 ;
}
static bool F_131 ( struct V_81 * V_53 , struct V_26 * V_27 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_189 * V_190 ;
struct V_149 * V_216 ;
if ( F_54 ( F_108 ( V_27 ) -> V_217 ) )
return false ;
V_190 = NULL ;
switch ( F_5 ( F_108 ( V_27 ) -> V_218 ) ) {
case V_197 :
if ( ! F_102 ( V_27 , sizeof( struct V_149 ) ) )
return false ;
V_216 = F_106 ( V_27 ) ;
V_190 = F_125 ( & V_203 , & V_216 -> V_219 , V_53 ) ;
break;
default:
return false ;
}
if ( V_190 ) {
bool V_220 ;
V_220 = F_45 ( F_108 ( V_27 ) -> V_217 , V_190 -> V_207 ) != 0 ;
if ( V_220 ) {
memcpy ( F_108 ( V_27 ) -> V_165 , F_108 ( V_27 ) -> V_217 ,
V_53 -> V_201 ) ;
memcpy ( F_108 ( V_27 ) -> V_217 , V_190 -> V_207 , V_53 -> V_201 ) ;
}
F_126 ( V_190 ) ;
return V_220 ;
} else if ( V_23 -> V_30 & V_214 )
F_34 ( V_53 , V_216 -> V_219 ) ;
return false ;
}
static void F_132 ( struct V_26 * V_27 )
{
F_133 ( V_27 -> V_20 ) ;
}
static void F_134 ( struct V_81 * V_53 , struct V_26 * V_27 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_19 * V_20 = V_23 -> V_142 -> V_19 -> V_20 ;
F_135 ( V_27 ) ;
F_136 ( V_20 ) ;
V_27 -> V_20 = V_20 ;
V_27 -> V_221 = F_132 ;
}
static T_2 F_137 ( const struct V_22 * V_23 , struct V_26 * V_27 )
{
unsigned int V_222 = ( V_23 -> V_223 - V_23 -> V_224 ) + 1 ;
T_1 V_225 ;
V_225 = F_138 ( V_27 ) ;
if ( ! V_225 )
V_225 = F_139 ( V_27 -> V_156 , 2 * V_59 ,
( V_226 T_1 ) V_27 -> V_164 ) ;
return F_122 ( ( ( ( T_5 ) V_225 * V_222 ) >> 32 ) + V_23 -> V_224 ) ;
}
static int F_140 ( struct V_26 * V_27 )
{
if ( F_141 ( V_27 ) ) {
int V_76 = F_142 ( V_27 , V_78 ) ;
if ( F_112 ( V_76 ) )
return V_76 ;
F_143 ( V_27 ) -> V_227 |= V_228 ;
} else if ( V_27 -> V_169 != V_229 )
V_27 -> V_169 = V_174 ;
return 0 ;
}
static void F_144 ( struct V_26 * V_27 , struct V_22 * V_230 ,
struct V_22 * V_231 )
{
struct V_153 * V_232 = F_114 ( V_230 -> V_53 -> V_178 ) ;
struct V_153 * V_233 = F_114 ( V_231 -> V_53 -> V_178 ) ;
V_27 -> V_210 = V_211 ;
V_27 -> V_171 = 0 ;
V_27 -> V_53 = V_231 -> V_53 ;
F_101 ( V_27 , F_128 ( V_27 ) ) ;
if ( V_231 -> V_30 & V_167 )
F_81 ( V_27 -> V_53 , F_15 ( V_234 ) ,
F_108 ( V_27 ) -> V_165 ) ;
F_115 ( & V_232 -> V_179 ) ;
V_232 -> V_235 ++ ;
V_232 -> V_236 += V_27 -> V_182 ;
F_116 ( & V_232 -> V_179 ) ;
if ( F_117 ( V_27 ) == V_237 ) {
F_115 ( & V_233 -> V_179 ) ;
V_233 -> V_180 ++ ;
V_233 -> V_181 += V_27 -> V_182 ;
F_116 ( & V_233 -> V_179 ) ;
} else {
V_27 -> V_53 -> V_154 . V_213 ++ ;
}
}
static void F_145 ( struct V_26 * V_27 , struct V_81 * V_53 ,
struct V_14 * V_31 , bool V_238 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_239 * V_240 ;
const struct V_149 * V_241 ;
struct V_151 * V_152 ;
struct V_155 * V_242 ;
struct V_243 V_244 ;
V_74 V_245 ;
T_2 V_246 , V_62 ;
T_1 V_94 ;
T_2 V_247 = 0 ;
T_7 V_176 , V_248 ;
int V_76 ;
V_62 = V_31 -> V_61 ? V_31 -> V_61 : V_23 -> V_62 ;
V_94 = V_31 -> V_25 ;
V_245 = V_31 -> V_46 ;
if ( ! V_245 ) {
if ( V_238 ) {
F_144 ( V_27 , V_23 , V_23 ) ;
return;
}
goto V_160;
}
if ( ! V_27 -> V_171 ) {
F_146 ( V_27 ) ;
V_27 -> V_171 = 1 ;
}
if ( F_147 ( V_27 , V_249 ) )
goto V_160;
V_241 = F_106 ( V_27 ) ;
V_248 = V_23 -> V_248 ;
if ( ! V_248 && F_148 ( F_103 ( V_245 ) ) )
V_248 = 1 ;
V_176 = V_23 -> V_176 ;
if ( V_176 == 1 )
V_176 = F_149 ( V_241 , V_27 ) ;
V_246 = F_137 ( V_23 , V_27 ) ;
memset ( & V_244 , 0 , sizeof( V_244 ) ) ;
V_244 . V_250 = V_31 -> V_65 ;
V_244 . V_251 = F_150 ( V_176 ) ;
V_244 . V_219 = V_245 ;
V_244 . V_168 = V_23 -> V_168 ;
V_240 = F_151 ( F_28 ( V_53 ) , & V_244 ) ;
if ( F_152 ( V_240 ) ) {
F_53 ( V_53 , L_9 , & V_245 ) ;
V_53 -> V_154 . V_252 ++ ;
goto V_253;
}
if ( V_240 -> V_245 . V_53 == V_53 ) {
F_53 ( V_53 , L_10 , & V_245 ) ;
F_153 ( V_240 ) ;
V_53 -> V_154 . V_254 ++ ;
goto V_253;
}
if ( V_240 -> V_255 & V_256 &&
! ( V_240 -> V_255 & ( V_257 | V_258 ) ) ) {
struct V_22 * V_231 ;
F_153 ( V_240 ) ;
V_231 = F_11 ( F_28 ( V_53 ) , V_94 , V_62 ) ;
if ( ! V_231 )
goto V_253;
F_144 ( V_27 , V_23 , V_231 ) ;
return;
}
V_152 = (struct V_151 * ) F_118 ( V_27 , sizeof( * V_152 ) ) ;
V_152 -> V_157 = F_15 ( V_158 ) ;
V_152 -> V_159 = F_15 ( V_94 << 8 ) ;
F_118 ( V_27 , sizeof( * V_242 ) ) ;
F_154 ( V_27 ) ;
V_242 = F_155 ( V_27 ) ;
V_242 -> V_259 = V_62 ;
V_242 -> V_260 = V_246 ;
V_242 -> V_182 = F_122 ( V_27 -> V_182 ) ;
V_242 -> V_261 = 0 ;
F_134 ( V_53 , V_27 ) ;
if ( F_140 ( V_27 ) )
goto V_160;
V_176 = F_156 ( V_176 , V_241 , V_27 ) ;
V_248 = V_248 ? : F_157 ( & V_240 -> V_245 ) ;
V_76 = F_158 ( F_28 ( V_53 ) , V_240 , V_27 , V_244 . V_168 , V_245 ,
V_262 , V_176 , V_248 , V_247 ) ;
F_159 ( V_76 , & V_53 -> V_154 , V_53 -> V_178 ) ;
return;
V_160:
V_53 -> V_154 . V_192 ++ ;
goto V_263;
V_253:
V_53 -> V_154 . V_264 ++ ;
V_263:
F_160 ( V_27 ) ;
}
static T_9 F_161 ( struct V_26 * V_27 , struct V_81 * V_53 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_265 * V_266 ;
bool V_238 = false ;
struct V_14 * V_31 ;
struct V_15 * V_83 ;
F_105 ( V_27 ) ;
V_266 = F_108 ( V_27 ) ;
if ( ( V_23 -> V_30 & V_267 ) && F_5 ( V_266 -> V_218 ) == V_209 )
return F_119 ( V_53 , V_27 ) ;
V_83 = F_46 ( V_23 , V_266 -> V_217 ) ;
V_238 = false ;
if ( V_83 && ( V_83 -> V_30 & V_268 ) && ( V_23 -> V_30 & V_269 ) &&
F_5 ( V_266 -> V_218 ) == V_197 ) {
V_238 = F_131 ( V_53 , V_27 ) ;
if ( V_238 )
V_83 = F_46 ( V_23 , V_266 -> V_217 ) ;
}
if ( V_83 == NULL ) {
V_83 = F_46 ( V_23 , V_270 ) ;
if ( V_83 == NULL ) {
if ( ( V_23 -> V_30 & V_271 ) &&
! F_54 ( V_266 -> V_217 ) )
F_38 ( V_23 , V_266 -> V_217 ) ;
V_53 -> V_154 . V_192 ++ ;
F_160 ( V_27 ) ;
return V_215 ;
}
}
F_79 (rdst, &f->remotes, list) {
struct V_26 * V_272 ;
V_272 = F_162 ( V_27 , V_78 ) ;
if ( V_272 )
F_145 ( V_272 , V_53 , V_31 , V_238 ) ;
}
F_160 ( V_27 ) ;
return V_215 ;
}
static void F_163 ( unsigned long V_273 )
{
struct V_22 * V_23 = (struct V_22 * ) V_273 ;
unsigned long V_274 = V_33 + V_275 ;
unsigned int V_126 ;
if ( ! F_86 ( V_23 -> V_53 ) )
return;
F_73 ( & V_23 -> V_121 ) ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
struct V_276 * V_277 , * V_190 ;
F_164 (p, n, &vxlan->fdb_head[h]) {
struct V_15 * V_83
= F_57 ( V_277 , struct V_15 , V_107 ) ;
unsigned long V_278 ;
if ( V_83 -> V_51 & V_119 )
continue;
V_278 = V_83 -> V_68 + V_23 -> V_279 * V_280 ;
if ( F_165 ( V_278 , V_33 ) ) {
F_53 ( V_23 -> V_53 ,
L_11 ,
V_83 -> V_48 ) ;
V_83 -> V_51 = V_84 ;
F_61 ( V_23 , V_83 ) ;
} else if ( F_166 ( V_278 , V_274 ) )
V_274 = V_278 ;
}
}
F_74 ( & V_23 -> V_121 ) ;
F_167 ( & V_23 -> V_281 , V_274 ) ;
}
static int F_168 ( struct V_81 * V_53 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_9 * V_10 = F_4 ( F_28 ( V_53 ) , V_11 ) ;
struct V_2 * V_3 ;
V_75 V_94 = V_23 -> V_24 . V_25 ;
V_53 -> V_178 = F_169 ( struct V_153 ) ;
if ( ! V_53 -> V_178 )
return - V_106 ;
F_85 ( & V_10 -> V_136 ) ;
V_3 = F_8 ( F_28 ( V_53 ) , V_23 -> V_62 ) ;
if ( V_3 ) {
F_90 ( & V_3 -> V_135 ) ;
V_23 -> V_142 = V_3 ;
F_55 ( & V_23 -> V_107 , F_1 ( V_3 , V_94 ) ) ;
} else {
F_170 ( V_53 ) ;
F_93 ( V_137 , & V_23 -> V_282 ) ;
}
F_87 ( & V_10 -> V_136 ) ;
return 0 ;
}
static void F_171 ( struct V_22 * V_23 )
{
struct V_15 * V_83 ;
F_73 ( & V_23 -> V_121 ) ;
V_83 = F_44 ( V_23 , V_270 ) ;
if ( V_83 )
F_61 ( V_23 , V_83 ) ;
F_74 ( & V_23 -> V_121 ) ;
}
static void F_172 ( struct V_81 * V_53 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_9 * V_10 = F_4 ( F_28 ( V_53 ) , V_11 ) ;
struct V_2 * V_3 = V_23 -> V_142 ;
F_171 ( V_23 ) ;
if ( V_3 )
F_91 ( V_10 , V_3 ) ;
F_173 ( V_53 -> V_178 ) ;
}
static int F_174 ( struct V_81 * V_53 )
{
struct V_9 * V_10 = F_4 ( F_28 ( V_53 ) , V_11 ) ;
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_2 * V_3 = V_23 -> V_142 ;
if ( ! V_3 )
return - V_283 ;
if ( F_148 ( F_103 ( V_23 -> V_24 . V_46 ) ) &&
F_88 ( V_10 , V_23 -> V_24 . V_46 ) ) {
F_89 ( V_3 ) ;
F_170 ( V_53 ) ;
F_93 ( V_137 , & V_23 -> V_141 ) ;
}
if ( V_23 -> V_279 )
F_167 ( & V_23 -> V_281 , V_33 + V_275 ) ;
return 0 ;
}
static void F_175 ( struct V_22 * V_23 )
{
unsigned int V_126 ;
F_73 ( & V_23 -> V_121 ) ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 ) {
struct V_276 * V_277 , * V_190 ;
F_164 (p, n, &vxlan->fdb_head[h]) {
struct V_15 * V_83
= F_57 ( V_277 , struct V_15 , V_107 ) ;
if ( ! F_16 ( V_83 -> V_48 ) )
F_61 ( V_23 , V_83 ) ;
}
}
F_74 ( & V_23 -> V_121 ) ;
}
static int F_176 ( struct V_81 * V_53 )
{
struct V_9 * V_10 = F_4 ( F_28 ( V_53 ) , V_11 ) ;
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_2 * V_3 = V_23 -> V_142 ;
if ( V_3 && F_148 ( F_103 ( V_23 -> V_24 . V_46 ) ) &&
! F_88 ( V_10 , V_23 -> V_24 . V_46 ) ) {
F_89 ( V_3 ) ;
F_170 ( V_53 ) ;
F_93 ( V_137 , & V_23 -> V_148 ) ;
}
F_177 ( & V_23 -> V_281 ) ;
F_175 ( V_23 ) ;
return 0 ;
}
static void F_178 ( struct V_81 * V_53 )
{
}
static void F_179 ( struct V_81 * V_53 )
{
struct V_22 * V_23 = F_35 ( V_53 ) ;
unsigned int V_126 ;
int V_284 , V_285 ;
F_180 ( V_53 ) ;
F_181 ( V_53 ) ;
V_53 -> V_286 = V_161 + V_249 ;
V_53 -> V_287 = & V_288 ;
V_53 -> V_221 = V_289 ;
F_182 ( V_53 , & V_290 ) ;
V_53 -> V_291 = 0 ;
V_53 -> V_172 |= V_292 ;
V_53 -> V_172 |= V_293 ;
V_53 -> V_172 |= V_294 | V_295 ;
V_53 -> V_172 |= V_173 ;
V_53 -> V_172 |= V_296 ;
V_53 -> V_297 |= V_294 | V_295 | V_173 ;
V_53 -> V_297 |= V_296 ;
V_53 -> V_298 &= ~ V_299 ;
V_53 -> V_298 |= V_300 ;
F_36 ( & V_23 -> V_301 ) ;
F_183 ( & V_23 -> V_121 ) ;
F_184 ( & V_23 -> V_141 , F_94 ) ;
F_184 ( & V_23 -> V_148 , F_98 ) ;
F_184 ( & V_23 -> V_282 , V_302 ) ;
F_185 ( & V_23 -> V_281 ) ;
V_23 -> V_281 . V_303 = F_163 ;
V_23 -> V_281 . V_156 = ( unsigned long ) V_23 ;
F_186 ( & V_284 , & V_285 ) ;
V_23 -> V_224 = V_284 ;
V_23 -> V_223 = V_285 ;
V_23 -> V_62 = F_122 ( V_304 ) ;
V_23 -> V_53 = V_53 ;
for ( V_126 = 0 ; V_126 < V_127 ; ++ V_126 )
F_187 ( & V_23 -> V_91 [ V_126 ] ) ;
}
static int F_188 ( struct V_113 * V_114 [] , struct V_113 * V_156 [] )
{
if ( V_114 [ V_305 ] ) {
if ( F_65 ( V_114 [ V_305 ] ) != V_59 ) {
F_189 ( L_12 ) ;
return - V_116 ;
}
if ( ! F_190 ( F_191 ( V_114 [ V_305 ] ) ) ) {
F_189 ( L_13 ) ;
return - V_118 ;
}
}
if ( ! V_156 )
return - V_116 ;
if ( V_156 [ V_306 ] ) {
V_75 V_4 = F_68 ( V_156 [ V_306 ] ) ;
if ( V_4 >= V_307 )
return - V_308 ;
}
if ( V_156 [ V_309 ] ) {
const struct V_310 * V_277
= F_191 ( V_156 [ V_309 ] ) ;
if ( F_5 ( V_277 -> V_285 ) < F_5 ( V_277 -> V_284 ) ) {
F_189 ( L_14 ,
F_5 ( V_277 -> V_284 ) , F_5 ( V_277 -> V_285 ) ) ;
return - V_116 ;
}
}
return 0 ;
}
static void F_192 ( struct V_81 * V_311 ,
struct V_312 * V_313 )
{
F_193 ( V_313 -> V_314 , V_315 , sizeof( V_313 -> V_314 ) ) ;
F_193 ( V_313 -> V_316 , L_15 , sizeof( V_313 -> V_316 ) ) ;
}
static void F_194 ( struct V_139 * V_140 )
{
struct V_2 * V_3 = F_57 ( V_140 , struct V_2 , V_138 ) ;
F_195 ( V_3 -> V_19 -> V_20 ) ;
F_196 ( V_3 , V_110 ) ;
}
static struct V_2 * F_197 ( struct V_7 * V_7 , T_2 V_8 )
{
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_317 V_318 = {
. V_319 = V_45 ,
. V_320 . V_146 = F_15 ( V_47 ) ,
. V_321 = V_8 ,
} ;
int V_100 ;
unsigned int V_126 ;
V_3 = F_50 ( sizeof( * V_3 ) , V_322 ) ;
if ( ! V_3 )
return F_198 ( - V_106 ) ;
for ( V_126 = 0 ; V_126 < V_323 ; ++ V_126 )
F_187 ( & V_3 -> V_5 [ V_126 ] ) ;
F_184 ( & V_3 -> V_138 , F_194 ) ;
V_100 = F_199 ( V_45 , V_324 , V_262 , & V_3 -> V_19 ) ;
if ( V_100 < 0 ) {
F_189 ( L_16 ) ;
F_58 ( V_3 ) ;
return F_198 ( V_100 ) ;
}
V_20 = V_3 -> V_19 -> V_20 ;
F_200 ( V_20 , V_7 ) ;
V_100 = F_201 ( V_3 -> V_19 , (struct V_325 * ) & V_318 ,
sizeof( V_318 ) ) ;
if ( V_100 < 0 ) {
F_189 ( L_17 ,
& V_318 . V_320 , F_5 ( V_318 . V_321 ) , V_100 ) ;
F_195 ( V_20 ) ;
F_58 ( V_3 ) ;
return F_198 ( V_100 ) ;
}
F_10 ( V_20 ) -> V_326 = 0 ;
F_202 ( V_20 ) -> V_327 = 1 ;
F_202 ( V_20 ) -> V_328 = F_100 ;
F_203 () ;
F_204 ( & V_3 -> V_135 , 1 ) ;
return V_3 ;
}
static void V_302 ( struct V_139 * V_140 )
{
struct V_22 * V_23
= F_57 ( V_140 , struct V_22 , V_282 ) ;
struct V_81 * V_53 = V_23 -> V_53 ;
struct V_7 * V_7 = F_28 ( V_53 ) ;
V_75 V_94 = V_23 -> V_24 . V_25 ;
T_2 V_8 = V_23 -> V_62 ;
struct V_9 * V_10 = F_4 ( V_7 , V_11 ) ;
struct V_2 * V_329 , * V_330 ;
V_329 = F_197 ( V_7 , V_8 ) ;
if ( F_152 ( V_329 ) ) {
F_205 ( V_23 -> V_53 , L_18 ,
F_206 ( V_329 ) ) ;
goto V_122;
}
F_85 ( & V_10 -> V_136 ) ;
V_330 = F_8 ( V_7 , V_8 ) ;
if ( V_330 ) {
F_90 ( & V_330 -> V_135 ) ;
V_23 -> V_142 = V_330 ;
F_55 ( & V_23 -> V_107 , F_1 ( V_330 , V_94 ) ) ;
F_87 ( & V_10 -> V_136 ) ;
F_195 ( V_329 -> V_19 -> V_20 ) ;
F_58 ( V_329 ) ;
} else {
V_23 -> V_142 = V_329 ;
F_55 ( & V_329 -> V_107 , F_3 ( V_7 , V_8 ) ) ;
F_55 ( & V_23 -> V_107 , F_1 ( V_329 , V_94 ) ) ;
F_87 ( & V_10 -> V_136 ) ;
}
V_122:
F_70 ( V_53 ) ;
}
static int F_207 ( struct V_7 * V_7 , struct V_81 * V_53 ,
struct V_113 * V_114 [] , struct V_113 * V_156 [] )
{
struct V_9 * V_10 = F_4 ( V_7 , V_11 ) ;
struct V_22 * V_23 = F_35 ( V_53 ) ;
struct V_14 * V_245 = & V_23 -> V_24 ;
V_75 V_94 ;
int V_76 ;
if ( ! V_156 [ V_306 ] )
return - V_116 ;
V_94 = F_68 ( V_156 [ V_306 ] ) ;
V_245 -> V_25 = V_94 ;
if ( V_156 [ V_331 ] )
V_245 -> V_46 = F_66 ( V_156 [ V_331 ] ) ;
if ( V_156 [ V_332 ] )
V_23 -> V_168 = F_66 ( V_156 [ V_332 ] ) ;
if ( V_156 [ V_333 ] &&
( V_245 -> V_65 = F_68 ( V_156 [ V_333 ] ) ) ) {
struct V_81 * V_334
= F_208 ( V_7 , V_245 -> V_65 ) ;
if ( ! V_334 ) {
F_72 ( L_19 , V_245 -> V_65 ) ;
return - V_335 ;
}
if ( ! V_114 [ V_336 ] )
V_53 -> V_337 = V_334 -> V_337 - V_249 ;
V_53 -> V_286 = V_334 -> V_286 +
V_249 ;
}
if ( V_156 [ V_338 ] )
V_23 -> V_176 = F_209 ( V_156 [ V_338 ] ) ;
if ( V_156 [ V_339 ] )
V_23 -> V_248 = F_209 ( V_156 [ V_339 ] ) ;
if ( ! V_156 [ V_340 ] || F_209 ( V_156 [ V_340 ] ) )
V_23 -> V_30 |= V_167 ;
if ( V_156 [ V_341 ] )
V_23 -> V_279 = F_68 ( V_156 [ V_341 ] ) ;
else
V_23 -> V_279 = V_342 ;
if ( V_156 [ V_343 ] && F_209 ( V_156 [ V_343 ] ) )
V_23 -> V_30 |= V_267 ;
if ( V_156 [ V_344 ] && F_209 ( V_156 [ V_344 ] ) )
V_23 -> V_30 |= V_269 ;
if ( V_156 [ V_345 ] && F_209 ( V_156 [ V_345 ] ) )
V_23 -> V_30 |= V_271 ;
if ( V_156 [ V_346 ] && F_209 ( V_156 [ V_346 ] ) )
V_23 -> V_30 |= V_214 ;
if ( V_156 [ V_347 ] )
V_23 -> V_103 = F_68 ( V_156 [ V_347 ] ) ;
if ( V_156 [ V_309 ] ) {
const struct V_310 * V_277
= F_191 ( V_156 [ V_309 ] ) ;
V_23 -> V_224 = F_5 ( V_277 -> V_284 ) ;
V_23 -> V_223 = F_5 ( V_277 -> V_285 ) ;
}
if ( V_156 [ V_348 ] )
V_23 -> V_62 = F_67 ( V_156 [ V_348 ] ) ;
if ( F_11 ( V_7 , V_94 , V_23 -> V_62 ) ) {
F_72 ( L_20 , V_94 ) ;
return - V_98 ;
}
F_210 ( V_53 , & V_349 ) ;
V_76 = F_52 ( V_23 , V_270 ,
V_23 -> V_24 . V_46 ,
V_120 | V_119 ,
V_97 | V_101 ,
V_23 -> V_62 , V_23 -> V_24 . V_25 ,
V_23 -> V_24 . V_65 , V_134 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_211 ( V_53 ) ;
if ( V_76 ) {
F_171 ( V_23 ) ;
return V_76 ;
}
F_212 ( & V_23 -> V_301 , & V_10 -> V_350 ) ;
return 0 ;
}
static void F_213 ( struct V_81 * V_53 , struct V_351 * V_92 )
{
struct V_9 * V_10 = F_4 ( F_28 ( V_53 ) , V_11 ) ;
struct V_22 * V_23 = F_35 ( V_53 ) ;
F_85 ( & V_10 -> V_136 ) ;
F_62 ( & V_23 -> V_107 ) ;
F_87 ( & V_10 -> V_136 ) ;
F_214 ( & V_23 -> V_301 ) ;
F_215 ( V_53 , V_92 ) ;
}
static T_3 F_216 ( const struct V_81 * V_53 )
{
return F_26 ( sizeof( V_75 ) ) +
F_26 ( sizeof( V_74 ) ) +
F_26 ( sizeof( V_75 ) ) +
F_26 ( sizeof( V_74 ) ) +
F_26 ( sizeof( T_7 ) ) +
F_26 ( sizeof( T_7 ) ) +
F_26 ( sizeof( T_7 ) ) +
F_26 ( sizeof( T_7 ) ) +
F_26 ( sizeof( T_7 ) ) +
F_26 ( sizeof( T_7 ) ) +
F_26 ( sizeof( T_7 ) ) +
F_26 ( sizeof( V_75 ) ) +
F_26 ( sizeof( V_75 ) ) +
F_26 ( sizeof( struct V_310 ) ) +
F_26 ( sizeof( T_2 ) ) +
0 ;
}
static int F_217 ( struct V_26 * V_27 , const struct V_81 * V_53 )
{
const struct V_22 * V_23 = F_35 ( V_53 ) ;
const struct V_14 * V_245 = & V_23 -> V_24 ;
struct V_310 V_352 = {
. V_284 = F_122 ( V_23 -> V_224 ) ,
. V_285 = F_122 ( V_23 -> V_223 ) ,
} ;
if ( F_20 ( V_27 , V_306 , V_245 -> V_25 ) )
goto V_60;
if ( V_245 -> V_46 && F_18 ( V_27 , V_331 , V_245 -> V_46 ) )
goto V_60;
if ( V_245 -> V_65 && F_20 ( V_27 , V_333 , V_245 -> V_65 ) )
goto V_60;
if ( V_23 -> V_168 && F_18 ( V_27 , V_332 , V_23 -> V_168 ) )
goto V_60;
if ( F_218 ( V_27 , V_339 , V_23 -> V_248 ) ||
F_218 ( V_27 , V_338 , V_23 -> V_176 ) ||
F_218 ( V_27 , V_340 ,
! ! ( V_23 -> V_30 & V_167 ) ) ||
F_218 ( V_27 , V_343 ,
! ! ( V_23 -> V_30 & V_267 ) ) ||
F_218 ( V_27 , V_344 , ! ! ( V_23 -> V_30 & V_269 ) ) ||
F_218 ( V_27 , V_345 ,
! ! ( V_23 -> V_30 & V_271 ) ) ||
F_218 ( V_27 , V_346 ,
! ! ( V_23 -> V_30 & V_214 ) ) ||
F_20 ( V_27 , V_341 , V_23 -> V_279 ) ||
F_20 ( V_27 , V_347 , V_23 -> V_103 ) ||
F_19 ( V_27 , V_348 , V_23 -> V_62 ) )
goto V_60;
if ( F_17 ( V_27 , V_309 , sizeof( V_352 ) , & V_352 ) )
goto V_60;
return 0 ;
V_60:
return - V_42 ;
}
static T_10 int F_219 ( struct V_7 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 , V_11 ) ;
unsigned int V_126 ;
F_36 ( & V_10 -> V_350 ) ;
F_183 ( & V_10 -> V_136 ) ;
for ( V_126 = 0 ; V_126 < V_353 ; ++ V_126 )
F_187 ( & V_10 -> V_12 [ V_126 ] ) ;
return 0 ;
}
static T_11 void F_220 ( struct V_7 * V_7 )
{
struct V_9 * V_10 = F_4 ( V_7 , V_11 ) ;
struct V_22 * V_23 ;
F_221 ( V_18 ) ;
F_222 () ;
F_48 (vxlan, &vn->vxlan_list, next)
F_215 ( V_23 -> V_53 , & V_18 ) ;
F_223 ( & V_18 ) ;
F_224 () ;
}
static int T_12 F_225 ( void )
{
int V_100 ;
V_137 = F_226 ( L_15 , 0 , 0 ) ;
if ( ! V_137 )
return - V_106 ;
F_227 ( & V_354 , sizeof( V_354 ) ) ;
V_100 = F_228 ( & V_355 ) ;
if ( V_100 )
goto V_356;
V_100 = F_229 ( & V_357 ) ;
if ( V_100 )
goto V_358;
return 0 ;
V_358:
F_230 ( & V_355 ) ;
V_356:
F_231 ( V_137 ) ;
return V_100 ;
}
static void T_13 F_232 ( void )
{
F_233 ( & V_357 ) ;
F_231 ( V_137 ) ;
F_230 ( & V_355 ) ;
F_234 () ;
}
