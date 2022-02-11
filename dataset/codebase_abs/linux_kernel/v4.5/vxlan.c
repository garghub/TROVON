static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ||
F_2 () ;
}
static inline
bool F_3 ( const union V_5 * V_6 , const union V_5 * V_7 )
{
if ( V_6 -> V_8 . V_9 != V_7 -> V_8 . V_9 )
return false ;
if ( V_6 -> V_8 . V_9 == V_10 )
return F_4 ( & V_6 -> V_11 . V_12 , & V_7 -> V_11 . V_12 ) ;
else
return V_6 -> sin . V_13 . V_14 == V_7 -> sin . V_13 . V_14 ;
}
static inline bool F_5 ( const union V_5 * V_15 )
{
if ( V_15 -> V_8 . V_9 == V_10 )
return F_6 ( & V_15 -> V_11 . V_12 ) ;
else
return V_15 -> sin . V_13 . V_14 == F_7 ( V_16 ) ;
}
static inline bool F_8 ( const union V_5 * V_15 )
{
if ( V_15 -> V_8 . V_9 == V_10 )
return F_9 ( & V_15 -> V_11 . V_12 ) ;
else
return F_10 ( F_11 ( V_15 -> sin . V_13 . V_14 ) ) ;
}
static int F_12 ( union V_5 * V_17 , struct V_18 * V_19 )
{
if ( F_13 ( V_19 ) >= sizeof( struct V_20 ) ) {
V_17 -> V_11 . V_12 = F_14 ( V_19 ) ;
V_17 -> V_8 . V_9 = V_10 ;
return 0 ;
} else if ( F_13 ( V_19 ) >= sizeof( V_21 ) ) {
V_17 -> sin . V_13 . V_14 = F_15 ( V_19 ) ;
V_17 -> V_8 . V_9 = V_22 ;
return 0 ;
} else {
return - V_23 ;
}
}
static int F_16 ( struct V_24 * V_25 , int V_26 ,
const union V_5 * V_17 )
{
if ( V_17 -> V_8 . V_9 == V_10 )
return F_17 ( V_25 , V_26 , & V_17 -> V_11 . V_12 ) ;
else
return F_18 ( V_25 , V_26 , V_17 -> sin . V_13 . V_14 ) ;
}
static inline
bool F_3 ( const union V_5 * V_6 , const union V_5 * V_7 )
{
return V_6 -> sin . V_13 . V_14 == V_7 -> sin . V_13 . V_14 ;
}
static inline bool F_5 ( const union V_5 * V_15 )
{
return V_15 -> sin . V_13 . V_14 == F_7 ( V_16 ) ;
}
static inline bool F_8 ( const union V_5 * V_15 )
{
return F_10 ( F_11 ( V_15 -> sin . V_13 . V_14 ) ) ;
}
static int F_12 ( union V_5 * V_17 , struct V_18 * V_19 )
{
if ( F_13 ( V_19 ) >= sizeof( struct V_20 ) ) {
return - V_23 ;
} else if ( F_13 ( V_19 ) >= sizeof( V_21 ) ) {
V_17 -> sin . V_13 . V_14 = F_15 ( V_19 ) ;
V_17 -> V_8 . V_9 = V_22 ;
return 0 ;
} else {
return - V_23 ;
}
}
static int F_16 ( struct V_24 * V_25 , int V_26 ,
const union V_5 * V_17 )
{
return F_18 ( V_25 , V_26 , V_17 -> sin . V_13 . V_14 ) ;
}
static inline struct V_27 * F_19 ( struct V_1 * V_2 , T_1 V_28 )
{
return & V_2 -> V_29 [ F_20 ( V_28 , V_30 ) ] ;
}
static inline struct V_27 * F_21 ( struct V_31 * V_31 , T_2 V_32 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
return & V_34 -> V_36 [ F_20 ( F_23 ( V_32 ) , V_37 ) ] ;
}
static inline struct V_38 * F_24 ( struct V_39 * V_40 )
{
return F_25 ( V_40 -> V_41 . V_42 , struct V_38 , V_43 ) ;
}
static inline struct V_38 * F_26 ( struct V_39 * V_40 )
{
return F_27 ( & V_40 -> V_41 , struct V_38 , V_43 ) ;
}
static struct V_1 * F_28 ( struct V_31 * V_31 , T_3 V_44 ,
T_2 V_32 , T_1 V_3 )
{
struct V_1 * V_2 ;
V_3 &= V_45 ;
F_29 (vs, vs_head(net, port), hlist) {
if ( F_30 ( V_2 -> V_46 -> V_47 ) -> V_48 == V_32 &&
F_31 ( V_2 ) == V_44 &&
V_2 -> V_3 == V_3 )
return V_2 ;
}
return NULL ;
}
static struct V_49 * F_32 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_49 * V_50 ;
F_29 (vxlan, vni_head(vs, id), hlist) {
if ( V_50 -> V_51 . V_52 == V_28 )
return V_50 ;
}
return NULL ;
}
static struct V_49 * F_33 ( struct V_31 * V_31 , T_1 V_28 ,
T_3 V_44 , T_2 V_32 ,
T_1 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_28 ( V_31 , V_44 , V_32 , V_3 ) ;
if ( ! V_2 )
return NULL ;
return F_32 ( V_2 , V_28 ) ;
}
static int F_34 ( struct V_24 * V_25 , struct V_49 * V_50 ,
const struct V_39 * V_40 ,
T_1 V_53 , T_1 V_54 , int type , unsigned int V_3 ,
const struct V_38 * V_55 )
{
unsigned long V_56 = V_57 ;
struct V_58 V_59 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
bool V_64 , V_65 ;
V_61 = F_35 ( V_25 , V_53 , V_54 , type , sizeof( * V_63 ) , V_3 ) ;
if ( V_61 == NULL )
return - V_66 ;
V_63 = F_36 ( V_61 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_65 = V_64 = true ;
if ( type == V_67 ) {
V_63 -> V_68 = V_22 ;
V_64 = ! F_5 ( & V_55 -> V_69 ) ;
V_65 = ! F_37 ( V_40 -> V_70 ) ;
} else
V_63 -> V_68 = V_71 ;
V_63 -> V_72 = V_40 -> V_73 ;
V_63 -> V_74 = V_50 -> V_75 -> V_76 ;
V_63 -> V_77 = V_40 -> V_3 ;
V_63 -> V_78 = V_79 ;
if ( ! F_38 ( F_39 ( V_50 -> V_75 ) , V_50 -> V_31 ) &&
F_40 ( V_25 , V_80 ,
F_41 ( F_39 ( V_50 -> V_75 ) , V_50 -> V_31 ) ) )
goto V_81;
if ( V_65 && F_42 ( V_25 , V_82 , V_83 , & V_40 -> V_70 ) )
goto V_81;
if ( V_64 && F_16 ( V_25 , V_84 , & V_55 -> V_69 ) )
goto V_81;
if ( V_55 -> V_85 && V_55 -> V_85 != V_50 -> V_86 . V_87 &&
F_43 ( V_25 , V_88 , V_55 -> V_85 ) )
goto V_81;
if ( V_55 -> V_52 != V_50 -> V_51 . V_52 &&
F_44 ( V_25 , V_89 , V_55 -> V_52 ) )
goto V_81;
if ( V_55 -> V_90 &&
F_44 ( V_25 , V_91 , V_55 -> V_90 ) )
goto V_81;
V_59 . V_92 = F_45 ( V_56 - V_40 -> V_93 ) ;
V_59 . V_94 = 0 ;
V_59 . V_95 = F_45 ( V_56 - V_40 -> V_96 ) ;
V_59 . V_97 = 0 ;
if ( F_42 ( V_25 , V_98 , sizeof( V_59 ) , & V_59 ) )
goto V_81;
F_46 ( V_25 , V_61 ) ;
return 0 ;
V_81:
F_47 ( V_25 , V_61 ) ;
return - V_66 ;
}
static inline T_4 F_48 ( void )
{
return F_49 ( sizeof( struct V_62 ) )
+ F_50 ( V_83 )
+ F_50 ( sizeof( struct V_20 ) )
+ F_50 ( sizeof( T_2 ) )
+ F_50 ( sizeof( V_21 ) )
+ F_50 ( sizeof( V_99 ) )
+ F_50 ( sizeof( V_100 ) )
+ F_50 ( sizeof( struct V_58 ) ) ;
}
static void F_51 ( struct V_49 * V_50 , struct V_39 * V_40 ,
struct V_38 * V_101 , int type )
{
struct V_31 * V_31 = F_39 ( V_50 -> V_75 ) ;
struct V_24 * V_25 ;
int V_102 = - V_103 ;
V_25 = F_52 ( F_48 () , V_104 ) ;
if ( V_25 == NULL )
goto V_105;
V_102 = F_34 ( V_25 , V_50 , V_40 , 0 , 0 , type , 0 , V_101 ) ;
if ( V_102 < 0 ) {
F_53 ( V_102 == - V_66 ) ;
F_54 ( V_25 ) ;
goto V_105;
}
F_55 ( V_25 , V_31 , 0 , V_106 , NULL , V_104 ) ;
return;
V_105:
if ( V_102 < 0 )
F_56 ( V_31 , V_106 , V_102 ) ;
}
static void F_57 ( struct V_107 * V_75 , union V_5 * V_15 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_39 V_108 = {
. V_73 = V_109 ,
} ;
struct V_38 V_110 = {
. V_69 = * V_15 ,
. V_52 = V_111 ,
} ;
F_51 ( V_50 , & V_108 , & V_110 , V_67 ) ;
}
static void F_59 ( struct V_49 * V_50 , const T_5 V_70 [ V_83 ] )
{
struct V_39 V_108 = {
. V_73 = V_109 ,
} ;
struct V_38 V_110 = { } ;
memcpy ( V_108 . V_70 , V_70 , V_83 ) ;
F_51 ( V_50 , & V_108 , & V_110 , V_67 ) ;
}
static T_1 F_60 ( const unsigned char * V_112 )
{
T_6 V_113 = F_61 ( ( T_6 * ) V_112 ) ;
#ifdef F_62
V_113 >>= 16 ;
#else
V_113 <<= 16 ;
#endif
return F_63 ( V_113 , V_114 ) ;
}
static inline struct V_27 * F_64 ( struct V_49 * V_50 ,
const T_5 * V_115 )
{
return & V_50 -> V_116 [ F_60 ( V_115 ) ] ;
}
static struct V_39 * F_65 ( struct V_49 * V_50 ,
const T_5 * V_115 )
{
struct V_27 * V_117 = F_64 ( V_50 , V_115 ) ;
struct V_39 * V_108 ;
F_29 (f, head, hlist) {
if ( F_66 ( V_115 , V_108 -> V_70 ) )
return V_108 ;
}
return NULL ;
}
static struct V_39 * F_67 ( struct V_49 * V_50 ,
const T_5 * V_115 )
{
struct V_39 * V_108 ;
V_108 = F_65 ( V_50 , V_115 ) ;
if ( V_108 )
V_108 -> V_93 = V_57 ;
return V_108 ;
}
static struct V_38 * F_68 ( struct V_39 * V_108 ,
union V_5 * V_17 , T_2 V_32 ,
V_99 V_118 , V_99 V_76 )
{
struct V_38 * V_101 ;
F_69 (rd, &f->remotes, list) {
if ( F_3 ( & V_101 -> V_69 , V_17 ) &&
V_101 -> V_85 == V_32 &&
V_101 -> V_52 == V_118 &&
V_101 -> V_90 == V_76 )
return V_101 ;
}
return NULL ;
}
static int F_70 ( struct V_39 * V_108 ,
union V_5 * V_17 , T_2 V_32 , V_99 V_118 , V_99 V_76 )
{
struct V_38 * V_101 ;
V_101 = F_68 ( V_108 , V_17 , V_32 , V_118 , V_76 ) ;
if ( V_101 )
return 0 ;
V_101 = F_71 ( & V_108 -> V_41 , struct V_38 , V_43 ) ;
if ( ! V_101 )
return 0 ;
V_101 -> V_69 = * V_17 ;
V_101 -> V_85 = V_32 ;
V_101 -> V_52 = V_118 ;
V_101 -> V_90 = V_76 ;
return 1 ;
}
static int F_72 ( struct V_39 * V_108 ,
union V_5 * V_17 , T_2 V_32 , V_99 V_118 ,
V_99 V_76 , struct V_38 * * V_119 )
{
struct V_38 * V_101 ;
V_101 = F_68 ( V_108 , V_17 , V_32 , V_118 , V_76 ) ;
if ( V_101 )
return 0 ;
V_101 = F_73 ( sizeof( * V_101 ) , V_104 ) ;
if ( V_101 == NULL )
return - V_103 ;
V_101 -> V_69 = * V_17 ;
V_101 -> V_85 = V_32 ;
V_101 -> V_52 = V_118 ;
V_101 -> V_90 = V_76 ;
F_74 ( & V_101 -> V_43 , & V_108 -> V_41 ) ;
* V_119 = V_101 ;
return 1 ;
}
static struct V_120 * F_75 ( struct V_24 * V_25 ,
unsigned int V_121 ,
struct V_120 * V_122 , T_4 V_123 ,
T_1 V_124 , struct V_125 * V_126 ,
bool V_127 )
{
T_4 V_128 , V_129 ;
if ( V_25 -> V_130 )
return V_122 ;
if ( ! F_76 ( V_25 ) -> V_131 )
return NULL ;
V_128 = ( V_124 & V_132 ) << V_133 ;
V_129 = V_128 + ( ( V_124 & V_134 ) ?
F_77 ( struct V_135 , V_136 ) :
F_77 ( struct V_137 , V_136 ) ) ;
V_122 = F_78 ( V_25 , ( void * ) V_122 , V_121 , V_123 ,
V_128 , V_129 , V_126 , V_127 ) ;
V_25 -> V_130 = 1 ;
return V_122 ;
}
static struct V_24 * * F_79 ( struct V_24 * * V_117 ,
struct V_24 * V_25 ,
struct V_138 * V_139 )
{
struct V_24 * V_140 , * * V_141 = NULL ;
struct V_120 * V_122 , * V_142 ;
unsigned int V_143 , V_144 ;
int V_145 = 1 ;
struct V_1 * V_2 = F_80 ( V_139 , struct V_1 ,
V_146 ) ;
T_1 V_3 ;
struct V_125 V_126 ;
F_81 ( & V_126 ) ;
V_144 = F_82 ( V_25 ) ;
V_143 = V_144 + sizeof( * V_122 ) ;
V_122 = F_83 ( V_25 , V_144 ) ;
if ( F_84 ( V_25 , V_143 ) ) {
V_122 = F_85 ( V_25 , V_143 , V_144 ) ;
if ( F_86 ( ! V_122 ) )
goto V_147;
}
F_87 ( V_25 , V_122 , sizeof( struct V_120 ) ) ;
V_3 = F_11 ( V_122 -> V_148 ) ;
if ( ( V_3 & V_149 ) && ( V_2 -> V_3 & V_150 ) ) {
V_122 = F_75 ( V_25 , V_144 , V_122 , sizeof( struct V_120 ) ,
F_11 ( V_122 -> V_151 ) , & V_126 ,
! ! ( V_2 -> V_3 &
V_152 ) ) ;
if ( ! V_122 )
goto V_147;
}
F_88 ( V_25 , sizeof( struct V_120 ) ) ;
V_145 = 0 ;
for ( V_140 = * V_117 ; V_140 ; V_140 = V_140 -> V_42 ) {
if ( ! F_76 ( V_140 ) -> V_153 )
continue;
V_142 = (struct V_120 * ) ( V_140 -> V_124 + V_144 ) ;
if ( V_122 -> V_148 != V_142 -> V_148 ||
V_122 -> V_151 != V_142 -> V_151 ) {
F_76 ( V_140 ) -> V_153 = 0 ;
continue;
}
}
V_141 = F_89 ( V_117 , V_25 ) ;
V_147:
F_90 ( V_25 , & V_126 ) ;
F_76 ( V_25 ) -> V_145 |= V_145 ;
return V_141 ;
}
static int F_91 ( struct V_24 * V_25 , int V_154 ,
struct V_138 * V_139 )
{
F_92 ( V_25 , V_154 ) ;
return F_93 ( V_25 , V_154 + sizeof( struct V_120 ) ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_107 * V_75 ;
struct V_46 * V_47 = V_2 -> V_46 -> V_47 ;
struct V_31 * V_31 = F_95 ( V_47 ) ;
T_3 V_9 = F_31 ( V_2 ) ;
T_2 V_32 = F_30 ( V_47 ) -> V_48 ;
int V_102 ;
if ( V_9 == V_22 ) {
V_102 = F_96 ( V_31 , & V_2 -> V_146 ) ;
if ( V_102 )
F_97 ( L_1 , V_102 ) ;
}
F_98 () ;
F_99 (net, dev) {
if ( V_75 -> V_155 -> V_156 )
V_75 -> V_155 -> V_156 ( V_75 , V_9 ,
V_32 ) ;
}
F_100 () ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_107 * V_75 ;
struct V_46 * V_47 = V_2 -> V_46 -> V_47 ;
struct V_31 * V_31 = F_95 ( V_47 ) ;
T_3 V_9 = F_31 ( V_2 ) ;
T_2 V_32 = F_30 ( V_47 ) -> V_48 ;
F_98 () ;
F_99 (net, dev) {
if ( V_75 -> V_155 -> V_157 )
V_75 -> V_155 -> V_157 ( V_75 , V_9 ,
V_32 ) ;
}
F_100 () ;
if ( V_9 == V_22 )
F_102 ( & V_2 -> V_146 ) ;
}
static int F_103 ( struct V_49 * V_50 ,
const T_5 * V_115 , union V_5 * V_17 ,
T_7 V_73 , T_7 V_3 ,
T_2 V_32 , V_99 V_118 , V_99 V_76 ,
T_8 V_77 )
{
struct V_38 * V_101 = NULL ;
struct V_39 * V_108 ;
int V_158 = 0 ;
V_108 = F_65 ( V_50 , V_115 ) ;
if ( V_108 ) {
if ( V_3 & V_159 ) {
F_104 ( V_50 -> V_75 ,
L_2 , V_115 ) ;
return - V_160 ;
}
if ( V_108 -> V_73 != V_73 ) {
V_108 -> V_73 = V_73 ;
V_108 -> V_96 = V_57 ;
V_158 = 1 ;
}
if ( V_108 -> V_3 != V_77 ) {
V_108 -> V_3 = V_77 ;
V_108 -> V_96 = V_57 ;
V_158 = 1 ;
}
if ( ( V_3 & V_161 ) ) {
if ( ! ( F_105 ( V_108 -> V_70 ) ||
F_37 ( V_108 -> V_70 ) ) ) {
V_158 |= F_70 ( V_108 , V_17 , V_32 , V_118 ,
V_76 ) ;
} else
return - V_162 ;
}
if ( ( V_3 & V_163 ) &&
( F_105 ( V_108 -> V_70 ) ||
F_37 ( V_108 -> V_70 ) ) ) {
int V_164 = F_72 ( V_108 , V_17 , V_32 , V_118 , V_76 ,
& V_101 ) ;
if ( V_164 < 0 )
return V_164 ;
V_158 |= V_164 ;
}
} else {
if ( ! ( V_3 & V_165 ) )
return - V_166 ;
if ( V_50 -> V_86 . V_167 &&
V_50 -> V_168 >= V_50 -> V_86 . V_167 )
return - V_169 ;
if ( ( V_3 & V_161 ) &&
( F_105 ( V_115 ) || F_37 ( V_115 ) ) )
return - V_162 ;
F_104 ( V_50 -> V_75 , L_3 , V_115 , V_17 ) ;
V_108 = F_73 ( sizeof( * V_108 ) , V_104 ) ;
if ( ! V_108 )
return - V_170 ;
V_158 = 1 ;
V_108 -> V_73 = V_73 ;
V_108 -> V_3 = V_77 ;
V_108 -> V_96 = V_108 -> V_93 = V_57 ;
F_106 ( & V_108 -> V_41 ) ;
memcpy ( V_108 -> V_70 , V_115 , V_83 ) ;
F_72 ( V_108 , V_17 , V_32 , V_118 , V_76 , & V_101 ) ;
++ V_50 -> V_168 ;
F_107 ( & V_108 -> V_171 ,
F_64 ( V_50 , V_115 ) ) ;
}
if ( V_158 ) {
if ( V_101 == NULL )
V_101 = F_26 ( V_108 ) ;
F_51 ( V_50 , V_108 , V_101 , V_172 ) ;
}
return 0 ;
}
static void F_108 ( struct V_173 * V_117 )
{
struct V_39 * V_108 = F_80 ( V_117 , struct V_39 , V_174 ) ;
struct V_38 * V_101 , * V_175 ;
F_109 (rd, nd, &f->remotes, list)
F_110 ( V_101 ) ;
F_110 ( V_108 ) ;
}
static void F_111 ( struct V_49 * V_50 , struct V_39 * V_108 )
{
F_104 ( V_50 -> V_75 ,
L_4 , V_108 -> V_70 ) ;
-- V_50 -> V_168 ;
F_51 ( V_50 , V_108 , F_26 ( V_108 ) , V_176 ) ;
F_112 ( & V_108 -> V_171 ) ;
F_113 ( & V_108 -> V_174 , F_108 ) ;
}
static int F_114 ( struct V_18 * V_177 [] , struct V_49 * V_50 ,
union V_5 * V_17 , T_2 * V_32 , T_1 * V_118 , T_1 * V_76 )
{
struct V_31 * V_31 = F_39 ( V_50 -> V_75 ) ;
int V_102 ;
if ( V_177 [ V_84 ] ) {
V_102 = F_12 ( V_17 , V_177 [ V_84 ] ) ;
if ( V_102 )
return V_102 ;
} else {
union V_5 * V_110 = & V_50 -> V_51 . V_69 ;
if ( V_110 -> V_8 . V_9 == V_22 ) {
V_17 -> sin . V_13 . V_14 = F_7 ( V_16 ) ;
V_17 -> V_8 . V_9 = V_22 ;
#if F_115 ( V_178 )
} else {
V_17 -> V_11 . V_12 = V_179 ;
V_17 -> V_8 . V_9 = V_10 ;
#endif
}
}
if ( V_177 [ V_88 ] ) {
if ( F_13 ( V_177 [ V_88 ] ) != sizeof( T_2 ) )
return - V_180 ;
* V_32 = F_116 ( V_177 [ V_88 ] ) ;
} else {
* V_32 = V_50 -> V_86 . V_87 ;
}
if ( V_177 [ V_89 ] ) {
if ( F_13 ( V_177 [ V_89 ] ) != sizeof( T_1 ) )
return - V_180 ;
* V_118 = F_117 ( V_177 [ V_89 ] ) ;
} else {
* V_118 = V_50 -> V_51 . V_52 ;
}
if ( V_177 [ V_91 ] ) {
struct V_107 * V_181 ;
if ( F_13 ( V_177 [ V_91 ] ) != sizeof( T_1 ) )
return - V_180 ;
* V_76 = F_117 ( V_177 [ V_91 ] ) ;
V_181 = F_118 ( V_31 , * V_76 ) ;
if ( ! V_181 )
return - V_182 ;
} else {
* V_76 = 0 ;
}
return 0 ;
}
static int F_119 ( struct V_62 * V_63 , struct V_18 * V_177 [] ,
struct V_107 * V_75 ,
const unsigned char * V_112 , T_9 V_183 , T_9 V_3 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
union V_5 V_17 ;
T_2 V_32 ;
T_1 V_118 , V_76 ;
int V_102 ;
if ( ! ( V_63 -> V_72 & ( V_184 | V_185 ) ) ) {
F_120 ( L_5 ,
V_63 -> V_72 ) ;
return - V_180 ;
}
if ( V_177 [ V_84 ] == NULL )
return - V_180 ;
V_102 = F_114 ( V_177 , V_50 , & V_17 , & V_32 , & V_118 , & V_76 ) ;
if ( V_102 )
return V_102 ;
if ( V_50 -> V_51 . V_69 . V_8 . V_9 != V_17 . V_8 . V_9 )
return - V_23 ;
F_121 ( & V_50 -> V_186 ) ;
V_102 = F_103 ( V_50 , V_112 , & V_17 , V_63 -> V_72 , V_3 ,
V_32 , V_118 , V_76 , V_63 -> V_77 ) ;
F_122 ( & V_50 -> V_186 ) ;
return V_102 ;
}
static int F_123 ( struct V_62 * V_63 , struct V_18 * V_177 [] ,
struct V_107 * V_75 ,
const unsigned char * V_112 , T_9 V_183 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_39 * V_108 ;
struct V_38 * V_101 = NULL ;
union V_5 V_17 ;
T_2 V_32 ;
T_1 V_118 , V_76 ;
int V_102 ;
V_102 = F_114 ( V_177 , V_50 , & V_17 , & V_32 , & V_118 , & V_76 ) ;
if ( V_102 )
return V_102 ;
V_102 = - V_166 ;
F_121 ( & V_50 -> V_186 ) ;
V_108 = F_67 ( V_50 , V_112 ) ;
if ( ! V_108 )
goto V_147;
if ( ! F_5 ( & V_17 ) ) {
V_101 = F_68 ( V_108 , & V_17 , V_32 , V_118 , V_76 ) ;
if ( ! V_101 )
goto V_147;
}
V_102 = 0 ;
if ( V_101 && ! F_124 ( & V_108 -> V_41 ) ) {
F_125 ( & V_101 -> V_43 ) ;
F_51 ( V_50 , V_108 , V_101 , V_176 ) ;
F_126 ( V_101 , V_174 ) ;
goto V_147;
}
F_111 ( V_50 , V_108 ) ;
V_147:
F_122 ( & V_50 -> V_186 ) ;
return V_102 ;
}
static int F_127 ( struct V_24 * V_25 , struct V_187 * V_188 ,
struct V_107 * V_75 ,
struct V_107 * V_189 , int V_190 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
unsigned int V_191 ;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 ) {
struct V_39 * V_108 ;
int V_102 ;
F_29 (f, &vxlan->fdb_head[h], hlist) {
struct V_38 * V_101 ;
F_128 (rd, &f->remotes, list) {
if ( V_190 < V_188 -> args [ 0 ] )
goto V_193;
V_102 = F_34 ( V_25 , V_50 , V_108 ,
F_129 ( V_188 -> V_25 ) . V_53 ,
V_188 -> V_61 -> V_194 ,
V_172 ,
V_195 , V_101 ) ;
if ( V_102 < 0 ) {
V_188 -> args [ 1 ] = V_102 ;
goto V_147;
}
V_193:
++ V_190 ;
}
}
}
V_147:
return V_190 ;
}
static bool F_130 ( struct V_107 * V_75 ,
union V_5 * V_196 , const T_5 * V_197 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_39 * V_108 ;
V_108 = F_67 ( V_50 , V_197 ) ;
if ( F_131 ( V_108 ) ) {
struct V_38 * V_55 = F_24 ( V_108 ) ;
if ( F_131 ( F_3 ( & V_55 -> V_69 , V_196 ) ) )
return false ;
if ( V_108 -> V_73 & V_198 )
return true ;
if ( F_132 () )
F_133 ( V_75 ,
L_6 ,
V_197 , & V_55 -> V_69 . V_8 , & V_196 -> V_8 ) ;
V_55 -> V_69 = * V_196 ;
V_108 -> V_96 = V_57 ;
F_51 ( V_50 , V_108 , V_55 , V_172 ) ;
} else {
F_134 ( & V_50 -> V_186 ) ;
if ( F_135 ( V_75 ) )
F_103 ( V_50 , V_197 , V_196 ,
V_185 ,
V_159 | V_165 ,
V_50 -> V_86 . V_87 ,
V_50 -> V_51 . V_52 ,
0 , V_199 ) ;
F_136 ( & V_50 -> V_186 ) ;
}
return false ;
}
static bool F_137 ( struct V_33 * V_34 , struct V_49 * V_75 )
{
struct V_49 * V_50 ;
unsigned short V_44 = V_75 -> V_51 . V_69 . V_8 . V_9 ;
if ( V_44 == V_22 && V_75 -> V_200 &&
F_138 ( & V_75 -> V_200 -> V_201 ) == 1 )
return false ;
#if F_115 ( V_178 )
if ( V_44 == V_10 && V_75 -> V_202 &&
F_138 ( & V_75 -> V_202 -> V_201 ) == 1 )
return false ;
#endif
F_69 (vxlan, &vn->vxlan_list, next) {
if ( ! F_135 ( V_50 -> V_75 ) || V_50 == V_75 )
continue;
if ( V_44 == V_22 && V_50 -> V_200 != V_75 -> V_200 )
continue;
#if F_115 ( V_178 )
if ( V_44 == V_10 && V_50 -> V_202 != V_75 -> V_202 )
continue;
#endif
if ( ! F_3 ( & V_50 -> V_51 . V_69 ,
& V_75 -> V_51 . V_69 ) )
continue;
if ( V_50 -> V_51 . V_90 !=
V_75 -> V_51 . V_90 )
continue;
return true ;
}
return false ;
}
static void F_139 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
if ( ! V_2 )
return;
if ( ! F_140 ( & V_2 -> V_201 ) )
return;
V_34 = F_22 ( F_95 ( V_2 -> V_46 -> V_47 ) , V_35 ) ;
F_134 ( & V_34 -> V_203 ) ;
F_112 ( & V_2 -> V_171 ) ;
F_101 ( V_2 ) ;
F_136 ( & V_34 -> V_203 ) ;
F_141 ( V_204 , & V_2 -> V_205 ) ;
}
static void F_142 ( struct V_49 * V_50 )
{
F_139 ( V_50 -> V_200 ) ;
#if F_115 ( V_178 )
F_139 ( V_50 -> V_202 ) ;
#endif
}
static int F_143 ( struct V_49 * V_50 )
{
struct V_46 * V_47 ;
union V_5 * V_17 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_90 ;
int V_206 = - V_180 ;
if ( V_17 -> V_8 . V_9 == V_22 ) {
struct V_207 V_208 = {
. V_209 . V_14 = V_17 -> sin . V_13 . V_14 ,
. V_210 = V_76 ,
} ;
V_47 = V_50 -> V_200 -> V_46 -> V_47 ;
F_144 ( V_47 ) ;
V_206 = F_145 ( V_47 , & V_208 ) ;
F_146 ( V_47 ) ;
#if F_115 ( V_178 )
} else {
V_47 = V_50 -> V_202 -> V_46 -> V_47 ;
F_144 ( V_47 ) ;
V_206 = V_211 -> V_212 ( V_47 , V_76 ,
& V_17 -> V_11 . V_12 ) ;
F_146 ( V_47 ) ;
#endif
}
return V_206 ;
}
static int F_147 ( struct V_49 * V_50 )
{
struct V_46 * V_47 ;
union V_5 * V_17 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_90 ;
int V_206 = - V_180 ;
if ( V_17 -> V_8 . V_9 == V_22 ) {
struct V_207 V_208 = {
. V_209 . V_14 = V_17 -> sin . V_13 . V_14 ,
. V_210 = V_76 ,
} ;
V_47 = V_50 -> V_200 -> V_46 -> V_47 ;
F_144 ( V_47 ) ;
V_206 = F_148 ( V_47 , & V_208 ) ;
F_146 ( V_47 ) ;
#if F_115 ( V_178 )
} else {
V_47 = V_50 -> V_202 -> V_46 -> V_47 ;
F_144 ( V_47 ) ;
V_206 = V_211 -> V_213 ( V_47 , V_76 ,
& V_17 -> V_11 . V_12 ) ;
F_146 ( V_47 ) ;
#endif
}
return V_206 ;
}
static struct V_120 * F_149 ( struct V_24 * V_25 , struct V_120 * V_122 ,
T_4 V_123 , T_1 V_124 , bool V_127 )
{
T_4 V_128 , V_129 , V_214 ;
if ( V_25 -> V_130 )
return V_122 ;
V_128 = ( V_124 & V_132 ) << V_133 ;
V_129 = V_128 + ( ( V_124 & V_134 ) ?
F_77 ( struct V_135 , V_136 ) :
F_77 ( struct V_137 , V_136 ) ) ;
V_214 = V_123 + V_129 + sizeof( T_9 ) ;
if ( ! F_150 ( V_25 , V_214 ) )
return NULL ;
V_122 = (struct V_120 * ) ( F_151 ( V_25 ) + 1 ) ;
F_152 ( V_25 , ( void * ) V_122 + V_123 , V_128 , V_129 ,
V_127 ) ;
return V_122 ;
}
static void F_153 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_215 * V_216 , T_1 V_118 ,
struct V_217 * V_218 )
{
struct V_219 * V_220 = NULL ;
struct V_221 * V_222 = NULL ;
struct V_49 * V_50 ;
struct V_223 * V_224 ;
union V_5 V_225 ;
int V_102 = 0 ;
if ( V_2 -> V_3 & V_4 )
V_118 = 0 ;
V_50 = F_32 ( V_2 , V_118 ) ;
if ( ! V_50 )
goto V_226;
F_154 ( V_25 ) ;
F_155 ( V_25 , ! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ) ;
V_25 -> V_227 = F_156 ( V_25 , V_50 -> V_75 ) ;
F_157 ( V_25 , F_158 ( V_25 ) , V_228 ) ;
if ( F_66 ( F_158 ( V_25 ) -> V_229 , V_50 -> V_75 -> V_230 ) )
goto V_226;
if ( F_31 ( V_2 ) == V_22 ) {
V_220 = F_159 ( V_25 ) ;
V_225 . sin . V_13 . V_14 = V_220 -> V_225 ;
V_225 . V_8 . V_9 = V_22 ;
#if F_115 ( V_178 )
} else {
V_222 = F_160 ( V_25 ) ;
V_225 . V_11 . V_12 = V_222 -> V_225 ;
V_225 . V_8 . V_9 = V_10 ;
#endif
}
if ( V_218 ) {
F_161 ( V_25 , (struct V_231 * ) V_218 ) ;
V_218 = NULL ;
}
if ( ( V_50 -> V_3 & V_232 ) &&
F_130 ( V_25 -> V_75 , & V_225 , F_158 ( V_25 ) -> V_229 ) )
goto V_226;
F_162 ( V_25 ) ;
if ( ! ( V_2 -> V_3 & V_4 ) )
V_25 -> V_233 = V_216 -> V_234 ;
if ( V_222 )
V_102 = F_163 ( V_222 , V_25 ) ;
if ( V_220 )
V_102 = F_164 ( V_220 , V_25 ) ;
if ( F_86 ( V_102 ) ) {
if ( V_235 ) {
if ( V_222 )
F_165 ( L_7 ,
& V_222 -> V_225 ) ;
if ( V_220 )
F_165 ( L_8 ,
& V_220 -> V_225 , V_220 -> V_236 ) ;
}
if ( V_102 > 1 ) {
++ V_50 -> V_75 -> V_224 . V_237 ;
++ V_50 -> V_75 -> V_224 . V_238 ;
goto V_226;
}
}
V_224 = F_166 ( V_50 -> V_75 -> V_239 ) ;
F_167 ( & V_224 -> V_240 ) ;
V_224 -> V_241 ++ ;
V_224 -> V_242 += V_25 -> V_243 ;
F_168 ( & V_224 -> V_240 ) ;
F_169 ( & V_50 -> V_244 , V_25 ) ;
return;
V_226:
if ( V_218 )
F_170 ( (struct V_231 * ) V_218 ) ;
F_54 ( V_25 ) ;
}
static int F_171 ( struct V_46 * V_47 , struct V_24 * V_25 )
{
struct V_217 * V_218 = NULL ;
struct V_1 * V_2 ;
struct V_120 * V_245 ;
T_1 V_3 , V_118 ;
struct V_215 V_246 ;
struct V_215 * V_216 = & V_246 ;
if ( ! F_150 ( V_25 , V_247 ) )
goto error;
V_245 = (struct V_120 * ) ( F_151 ( V_25 ) + 1 ) ;
V_3 = F_11 ( V_245 -> V_148 ) ;
V_118 = F_11 ( V_245 -> V_151 ) ;
if ( V_3 & V_248 ) {
V_3 &= ~ V_248 ;
} else {
goto V_249;
}
if ( F_172 ( V_25 , V_247 , F_173 ( V_250 ) ) )
goto V_226;
V_245 = (struct V_120 * ) ( F_151 ( V_25 ) + 1 ) ;
V_2 = F_174 ( V_47 ) ;
if ( ! V_2 )
goto V_226;
if ( ( V_3 & V_149 ) && ( V_2 -> V_3 & V_150 ) ) {
V_245 = F_149 ( V_25 , V_245 , sizeof( struct V_120 ) , V_118 ,
! ! ( V_2 -> V_3 & V_152 ) ) ;
if ( ! V_245 )
goto V_226;
V_3 &= ~ V_149 ;
V_118 &= V_251 ;
}
if ( F_1 ( V_2 ) ) {
V_218 = F_175 ( V_25 , F_31 ( V_2 ) , V_252 ,
F_176 ( V_118 >> 8 ) , sizeof( * V_216 ) ) ;
if ( ! V_218 )
goto V_226;
V_216 = F_177 ( & V_218 -> V_253 . V_254 ) ;
} else {
memset ( V_216 , 0 , sizeof( * V_216 ) ) ;
}
if ( ( V_3 & V_255 ) && ( V_2 -> V_3 & V_256 ) ) {
struct V_257 * V_234 ;
V_234 = (struct V_257 * ) V_245 ;
V_216 -> V_234 = F_23 ( V_234 -> V_258 ) ;
if ( V_218 ) {
V_218 -> V_253 . V_254 . V_259 . V_260 |= V_261 ;
V_218 -> V_253 . V_254 . V_262 = sizeof( * V_216 ) ;
}
if ( V_234 -> V_263 )
V_216 -> V_234 |= V_264 ;
if ( V_234 -> V_265 )
V_216 -> V_234 |= V_266 ;
V_3 &= ~ V_267 ;
}
if ( V_3 || V_118 & ~ V_251 ) {
goto V_249;
}
F_153 ( V_2 , V_25 , V_216 , V_118 >> 8 , V_218 ) ;
return 0 ;
V_226:
F_54 ( V_25 ) ;
return 0 ;
V_249:
F_104 ( V_25 -> V_75 , L_9 ,
F_11 ( V_245 -> V_148 ) , F_11 ( V_245 -> V_151 ) ) ;
error:
if ( V_218 )
F_170 ( (struct V_231 * ) V_218 ) ;
return 1 ;
}
static int F_178 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_268 * V_269 ;
T_5 * V_270 , * V_271 ;
V_21 V_272 , V_273 ;
struct V_274 * V_275 ;
if ( V_75 -> V_3 & V_276 )
goto V_147;
if ( ! F_150 ( V_25 , F_179 ( V_75 ) ) ) {
V_75 -> V_224 . V_277 ++ ;
goto V_147;
}
V_269 = F_180 ( V_25 ) ;
if ( ( V_269 -> V_278 != F_173 ( V_279 ) &&
V_269 -> V_278 != F_173 ( V_280 ) ) ||
V_269 -> V_281 != F_173 ( V_282 ) ||
V_269 -> V_283 != F_173 ( V_284 ) ||
V_269 -> V_285 != V_75 -> V_286 ||
V_269 -> V_287 != 4 )
goto V_147;
V_270 = ( T_5 * ) V_269 + sizeof( struct V_268 ) ;
V_271 = V_270 ;
V_270 += V_75 -> V_286 ;
memcpy ( & V_272 , V_270 , sizeof( V_272 ) ) ;
V_270 += sizeof( V_272 ) ;
V_270 += V_75 -> V_286 ;
memcpy ( & V_273 , V_270 , sizeof( V_273 ) ) ;
if ( F_181 ( V_273 ) ||
F_182 ( V_273 ) )
goto V_147;
V_275 = F_183 ( & V_288 , & V_273 , V_75 ) ;
if ( V_275 ) {
struct V_39 * V_108 ;
struct V_24 * V_289 ;
if ( ! ( V_275 -> V_290 & V_291 ) ) {
F_184 ( V_275 ) ;
goto V_147;
}
V_108 = F_67 ( V_50 , V_275 -> V_292 ) ;
if ( V_108 && F_5 ( & ( F_24 ( V_108 ) -> V_69 ) ) ) {
F_184 ( V_275 ) ;
goto V_147;
}
V_289 = F_185 ( V_293 , V_294 , V_272 , V_75 , V_273 , V_271 ,
V_275 -> V_292 , V_271 ) ;
F_184 ( V_275 ) ;
if ( V_289 == NULL )
goto V_147;
F_154 ( V_289 ) ;
F_186 ( V_289 , F_187 ( V_289 ) ) ;
V_289 -> V_295 = V_296 ;
V_289 -> V_297 = V_298 ;
if ( F_188 ( V_289 ) == V_299 )
V_75 -> V_224 . V_300 ++ ;
} else if ( V_50 -> V_3 & V_301 ) {
union V_5 V_15 = {
. sin . V_13 . V_14 = V_273 ,
. sin . V_302 = V_22 ,
} ;
F_57 ( V_75 , & V_15 ) ;
}
V_147:
F_189 ( V_25 ) ;
return V_303 ;
}
static struct V_24 * F_190 ( struct V_24 * V_304 ,
struct V_274 * V_275 , bool V_305 )
{
struct V_107 * V_75 = V_304 -> V_75 ;
struct V_24 * V_289 ;
struct V_306 * V_307 , * V_308 ;
struct V_221 * V_309 ;
T_5 * V_310 ;
int V_311 = 8 ;
int V_312 ;
int V_313 , V_243 ;
if ( V_75 == NULL )
return NULL ;
V_243 = F_191 ( V_75 ) + sizeof( struct V_221 ) +
sizeof( * V_308 ) + V_311 + V_75 -> V_314 ;
V_289 = F_192 ( V_243 , V_104 ) ;
if ( V_289 == NULL )
return NULL ;
V_289 -> V_227 = F_173 ( V_315 ) ;
V_289 -> V_75 = V_75 ;
F_193 ( V_289 , F_191 ( V_304 -> V_75 ) ) ;
F_194 ( V_289 , sizeof( struct V_316 ) ) ;
F_195 ( V_289 , 0 ) ;
V_307 = (struct V_306 * ) F_196 ( V_304 ) ;
V_310 = F_158 ( V_304 ) -> V_229 ;
V_312 = V_304 -> V_243 - F_197 ( V_304 ) - sizeof( * V_307 ) ;
for ( V_313 = 0 ; V_313 < V_312 - 1 ; V_313 += ( V_307 -> V_317 [ V_313 + 1 ] << 3 ) ) {
if ( V_307 -> V_317 [ V_313 ] == V_318 ) {
V_310 = V_307 -> V_317 + V_313 + sizeof( struct V_319 ) ;
break;
}
}
F_198 ( F_158 ( V_289 ) -> V_320 , V_310 ) ;
F_198 ( F_158 ( V_289 ) -> V_229 , V_275 -> V_292 ) ;
F_158 ( V_289 ) -> V_321 = F_173 ( V_315 ) ;
V_289 -> V_227 = F_173 ( V_315 ) ;
F_199 ( V_289 , sizeof( struct V_316 ) ) ;
F_200 ( V_289 , 0 ) ;
F_201 ( V_289 , sizeof( struct V_221 ) ) ;
V_309 = F_160 ( V_289 ) ;
memset ( V_309 , 0 , sizeof( struct V_221 ) ) ;
V_309 -> V_322 = 6 ;
V_309 -> V_323 = F_160 ( V_304 ) -> V_323 ;
V_309 -> V_324 = V_325 ;
V_309 -> V_326 = 255 ;
V_309 -> V_310 = F_160 ( V_304 ) -> V_225 ;
V_309 -> V_225 = * (struct V_20 * ) V_275 -> V_327 ;
F_199 ( V_289 , sizeof( struct V_221 ) ) ;
F_202 ( V_289 , 0 ) ;
V_308 = (struct V_306 * ) F_201 ( V_289 , sizeof( * V_308 ) + V_311 ) ;
memset ( V_308 , 0 , sizeof( * V_308 ) + V_311 ) ;
V_308 -> V_328 . V_329 = V_330 ;
V_308 -> V_328 . V_331 = V_305 ;
V_308 -> V_328 . V_332 = 1 ;
V_308 -> V_328 . V_333 = 1 ;
V_308 -> V_334 = V_307 -> V_334 ;
F_198 ( & V_308 -> V_317 [ 2 ] , V_275 -> V_292 ) ;
V_308 -> V_317 [ 0 ] = V_335 ;
V_308 -> V_317 [ 1 ] = V_311 >> 3 ;
V_308 -> V_328 . V_336 = F_203 ( & V_309 -> V_225 ,
& V_309 -> V_310 , sizeof( * V_308 ) + V_311 , V_325 ,
F_204 ( V_308 , sizeof( * V_308 ) + V_311 , 0 ) ) ;
V_309 -> V_337 = F_173 ( sizeof( * V_308 ) + V_311 ) ;
F_194 ( V_289 , sizeof( struct V_221 ) ) ;
V_289 -> V_295 = V_296 ;
return V_289 ;
}
static int F_205 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_306 * V_338 ;
const struct V_221 * V_219 ;
const struct V_20 * V_225 , * V_310 ;
struct V_274 * V_275 ;
struct V_339 * V_340 ;
V_340 = F_206 ( V_75 ) ;
if ( ! V_340 )
goto V_147;
V_219 = F_160 ( V_25 ) ;
V_225 = & V_219 -> V_225 ;
V_310 = & V_219 -> V_310 ;
V_338 = (struct V_306 * ) F_196 ( V_25 ) ;
if ( V_338 -> V_328 . V_341 != 0 ||
V_338 -> V_328 . V_329 != V_342 )
goto V_147;
if ( F_207 ( V_310 ) ||
F_9 ( & V_338 -> V_334 ) )
goto V_147;
V_275 = F_183 ( V_211 -> V_343 , & V_338 -> V_334 , V_75 ) ;
if ( V_275 ) {
struct V_39 * V_108 ;
struct V_24 * V_289 ;
if ( ! ( V_275 -> V_290 & V_291 ) ) {
F_184 ( V_275 ) ;
goto V_147;
}
V_108 = F_67 ( V_50 , V_275 -> V_292 ) ;
if ( V_108 && F_5 ( & ( F_24 ( V_108 ) -> V_69 ) ) ) {
F_184 ( V_275 ) ;
goto V_147;
}
V_289 = F_190 ( V_25 , V_275 ,
! ! ( V_108 ? V_108 -> V_3 & V_344 : 0 ) ) ;
F_184 ( V_275 ) ;
if ( V_289 == NULL )
goto V_147;
if ( F_188 ( V_289 ) == V_299 )
V_75 -> V_224 . V_300 ++ ;
} else if ( V_50 -> V_3 & V_301 ) {
union V_5 V_15 = {
. V_11 . V_12 = V_338 -> V_334 ,
. V_11 . V_345 = V_10 ,
} ;
F_57 ( V_75 , & V_15 ) ;
}
V_147:
F_189 ( V_25 ) ;
return V_303 ;
}
static bool F_208 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_274 * V_275 ;
if ( F_105 ( F_158 ( V_25 ) -> V_320 ) )
return false ;
V_275 = NULL ;
switch ( F_23 ( F_158 ( V_25 ) -> V_321 ) ) {
case V_282 :
{
struct V_219 * V_346 ;
if ( ! F_150 ( V_25 , sizeof( struct V_219 ) ) )
return false ;
V_346 = F_159 ( V_25 ) ;
V_275 = F_183 ( & V_288 , & V_346 -> V_310 , V_75 ) ;
if ( ! V_275 && ( V_50 -> V_3 & V_301 ) ) {
union V_5 V_15 = {
. sin . V_13 . V_14 = V_346 -> V_310 ,
. sin . V_302 = V_22 ,
} ;
F_57 ( V_75 , & V_15 ) ;
return false ;
}
break;
}
#if F_115 ( V_178 )
case V_315 :
{
struct V_221 * V_309 ;
if ( ! F_150 ( V_25 , sizeof( struct V_221 ) ) )
return false ;
V_309 = F_160 ( V_25 ) ;
V_275 = F_183 ( V_211 -> V_343 , & V_309 -> V_310 , V_75 ) ;
if ( ! V_275 && ( V_50 -> V_3 & V_301 ) ) {
union V_5 V_15 = {
. V_11 . V_12 = V_309 -> V_310 ,
. V_11 . V_345 = V_10 ,
} ;
F_57 ( V_75 , & V_15 ) ;
return false ;
}
break;
}
#endif
default:
return false ;
}
if ( V_275 ) {
bool V_347 ;
V_347 = ! F_66 ( F_158 ( V_25 ) -> V_320 , V_275 -> V_292 ) ;
if ( V_347 ) {
memcpy ( F_158 ( V_25 ) -> V_229 , F_158 ( V_25 ) -> V_320 ,
V_75 -> V_286 ) ;
memcpy ( F_158 ( V_25 ) -> V_320 , V_275 -> V_292 , V_75 -> V_286 ) ;
}
F_184 ( V_275 ) ;
return V_347 ;
}
return false ;
}
static void F_209 ( struct V_120 * V_245 , T_1 V_348 ,
struct V_215 * V_216 )
{
struct V_257 * V_234 ;
if ( ! V_216 -> V_234 )
return;
V_234 = (struct V_257 * ) V_245 ;
V_245 -> V_148 |= F_7 ( V_255 ) ;
if ( V_216 -> V_234 & V_264 )
V_234 -> V_263 = 1 ;
if ( V_216 -> V_234 & V_266 )
V_234 -> V_265 = 1 ;
V_234 -> V_258 = F_173 ( V_216 -> V_234 & V_349 ) ;
}
static int F_210 ( struct V_231 * V_350 , struct V_46 * V_47 ,
struct V_24 * V_25 ,
struct V_107 * V_75 , struct V_20 * V_225 ,
struct V_20 * V_310 , T_8 V_351 , T_8 V_352 ,
T_2 V_353 , T_2 V_87 , V_21 V_118 ,
struct V_215 * V_216 , bool V_354 , T_1 V_348 )
{
struct V_120 * V_245 ;
int V_355 ;
int V_102 ;
bool V_356 = ! ( V_348 & V_357 ) ;
int type = V_356 ? V_358 : V_359 ;
T_9 V_123 = sizeof( struct V_120 ) ;
if ( ( V_348 & V_360 ) &&
V_25 -> V_295 == V_361 ) {
int V_362 = F_211 ( V_25 ) ;
if ( V_362 <= V_363 &&
! ( V_362 & V_364 ) &&
( V_25 -> V_365 == F_77 ( struct V_135 , V_136 ) ||
V_25 -> V_365 == F_77 ( struct V_137 , V_136 ) ) ) {
V_356 = false ;
type |= V_366 ;
}
}
F_155 ( V_25 , V_354 ) ;
V_355 = F_191 ( V_350 -> V_75 ) + V_350 -> V_367
+ V_247 + sizeof( struct V_221 )
+ ( F_212 ( V_25 ) ? V_368 : 0 ) ;
V_102 = F_213 ( V_25 , V_355 ) ;
if ( F_86 ( V_102 ) ) {
F_54 ( V_25 ) ;
goto V_102;
}
V_25 = F_214 ( V_25 ) ;
if ( F_53 ( ! V_25 ) ) {
V_102 = - V_170 ;
goto V_102;
}
V_25 = F_215 ( V_25 , V_356 , type ) ;
if ( F_216 ( V_25 ) ) {
V_102 = - V_180 ;
goto V_102;
}
V_245 = (struct V_120 * ) F_217 ( V_25 , sizeof( * V_245 ) ) ;
V_245 -> V_148 = F_7 ( V_248 ) ;
V_245 -> V_151 = V_118 ;
if ( type & V_366 ) {
T_1 V_124 = ( F_211 ( V_25 ) - V_123 ) >>
V_133 ;
if ( V_25 -> V_365 == F_77 ( struct V_135 , V_136 ) )
V_124 |= V_134 ;
V_245 -> V_151 |= F_7 ( V_124 ) ;
V_245 -> V_148 |= F_7 ( V_149 ) ;
if ( ! F_218 ( V_25 ) ) {
V_25 -> V_295 = V_369 ;
V_25 -> V_370 = 0 ;
}
}
if ( V_348 & V_256 )
F_209 ( V_245 , V_348 , V_216 ) ;
F_219 ( V_25 , F_173 ( V_250 ) ) ;
F_220 ( V_350 , V_47 , V_25 , V_75 , V_225 , V_310 , V_351 ,
V_352 , V_353 , V_87 ,
! ! ( V_348 & V_357 ) ) ;
return 0 ;
V_102:
F_170 ( V_350 ) ;
return V_102 ;
}
static int F_221 ( struct V_371 * V_372 , struct V_46 * V_47 , struct V_24 * V_25 ,
V_21 V_373 , V_21 V_350 , T_8 V_236 , T_8 V_352 , T_2 V_374 ,
T_2 V_353 , T_2 V_87 , V_21 V_118 ,
struct V_215 * V_216 , bool V_354 , T_1 V_348 )
{
struct V_120 * V_245 ;
int V_355 ;
int V_102 ;
bool V_356 = ! ! ( V_348 & V_375 ) ;
int type = V_356 ? V_358 : V_359 ;
T_9 V_123 = sizeof( struct V_120 ) ;
if ( ( V_348 & V_360 ) &&
V_25 -> V_295 == V_361 ) {
int V_362 = F_211 ( V_25 ) ;
if ( V_362 <= V_363 &&
! ( V_362 & V_364 ) &&
( V_25 -> V_365 == F_77 ( struct V_135 , V_136 ) ||
V_25 -> V_365 == F_77 ( struct V_137 , V_136 ) ) ) {
V_356 = false ;
type |= V_366 ;
}
}
V_355 = F_191 ( V_372 -> V_350 . V_75 ) + V_372 -> V_350 . V_367
+ V_247 + sizeof( struct V_219 )
+ ( F_212 ( V_25 ) ? V_368 : 0 ) ;
V_102 = F_213 ( V_25 , V_355 ) ;
if ( F_86 ( V_102 ) ) {
F_54 ( V_25 ) ;
return V_102 ;
}
V_25 = F_214 ( V_25 ) ;
if ( F_53 ( ! V_25 ) )
return - V_170 ;
V_25 = F_215 ( V_25 , V_356 , type ) ;
if ( F_216 ( V_25 ) )
return F_222 ( V_25 ) ;
V_245 = (struct V_120 * ) F_217 ( V_25 , sizeof( * V_245 ) ) ;
V_245 -> V_148 = F_7 ( V_248 ) ;
V_245 -> V_151 = V_118 ;
if ( type & V_366 ) {
T_1 V_124 = ( F_211 ( V_25 ) - V_123 ) >>
V_133 ;
if ( V_25 -> V_365 == F_77 ( struct V_135 , V_136 ) )
V_124 |= V_134 ;
V_245 -> V_151 |= F_7 ( V_124 ) ;
V_245 -> V_148 |= F_7 ( V_149 ) ;
if ( ! F_218 ( V_25 ) ) {
V_25 -> V_295 = V_369 ;
V_25 -> V_370 = 0 ;
}
}
if ( V_348 & V_256 )
F_209 ( V_245 , V_348 , V_216 ) ;
F_219 ( V_25 , F_173 ( V_250 ) ) ;
F_223 ( V_372 , V_47 , V_25 , V_373 , V_350 , V_236 , V_352 , V_374 ,
V_353 , V_87 , V_354 ,
! ( V_348 & V_375 ) ) ;
return 0 ;
}
static struct V_231 * F_224 ( struct V_49 * V_50 ,
struct V_24 * V_25 , int V_376 ,
const struct V_20 * V_310 ,
struct V_20 * V_225 )
{
struct V_231 * V_377 ;
struct V_378 V_379 ;
int V_102 ;
memset ( & V_379 , 0 , sizeof( V_379 ) ) ;
V_379 . V_380 = V_376 ;
V_379 . V_310 = * V_310 ;
V_379 . V_225 = V_50 -> V_86 . V_225 . V_11 . V_12 ;
V_379 . V_381 = V_25 -> V_233 ;
V_379 . V_382 = V_383 ;
V_102 = V_211 -> V_384 ( V_50 -> V_31 ,
V_50 -> V_202 -> V_46 -> V_47 ,
& V_377 , & V_379 ) ;
if ( V_102 < 0 )
return F_225 ( V_102 ) ;
* V_225 = V_379 . V_225 ;
return V_377 ;
}
static void F_226 ( struct V_24 * V_25 , struct V_49 * V_385 ,
struct V_49 * V_386 )
{
struct V_223 * V_387 , * V_388 ;
union V_5 V_389 ;
union V_5 * V_69 = & V_386 -> V_51 . V_69 ;
struct V_107 * V_75 = V_25 -> V_75 ;
int V_243 = V_25 -> V_243 ;
V_387 = F_166 ( V_385 -> V_75 -> V_239 ) ;
V_388 = F_166 ( V_386 -> V_75 -> V_239 ) ;
V_25 -> V_297 = V_298 ;
V_25 -> V_370 = 0 ;
V_25 -> V_75 = V_386 -> V_75 ;
F_186 ( V_25 , F_187 ( V_25 ) ) ;
if ( V_69 -> V_8 . V_9 == V_22 ) {
V_389 . sin . V_13 . V_14 = F_7 ( V_390 ) ;
V_389 . V_8 . V_9 = V_22 ;
#if F_115 ( V_178 )
} else {
V_389 . V_11 . V_12 = V_391 ;
V_389 . V_8 . V_9 = V_10 ;
#endif
}
if ( V_386 -> V_3 & V_232 )
F_130 ( V_25 -> V_75 , & V_389 , F_158 ( V_25 ) -> V_229 ) ;
F_167 ( & V_387 -> V_240 ) ;
V_387 -> V_392 ++ ;
V_387 -> V_393 += V_243 ;
F_168 ( & V_387 -> V_240 ) ;
if ( F_227 ( V_25 ) == V_394 ) {
F_167 ( & V_388 -> V_240 ) ;
V_388 -> V_241 ++ ;
V_388 -> V_242 += V_243 ;
F_168 ( & V_388 -> V_240 ) ;
} else {
V_75 -> V_224 . V_300 ++ ;
}
}
static void F_228 ( struct V_24 * V_25 , struct V_107 * V_75 ,
struct V_38 * V_55 , bool V_395 )
{
struct V_396 * V_397 ;
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_46 * V_47 ;
struct V_371 * V_372 = NULL ;
const struct V_219 * V_398 ;
struct V_399 V_400 ;
union V_5 * V_350 ;
union V_5 V_69 ;
struct V_215 V_246 ;
struct V_215 * V_216 = & V_246 ;
T_2 V_353 = 0 , V_87 ;
T_1 V_118 ;
T_2 V_374 = 0 ;
T_8 V_236 , V_352 ;
int V_102 ;
T_1 V_3 = V_50 -> V_3 ;
V_397 = F_229 ( V_25 ) ;
if ( V_55 ) {
V_87 = V_55 -> V_85 ? V_55 -> V_85 : V_50 -> V_86 . V_87 ;
V_118 = V_55 -> V_52 ;
V_350 = & V_55 -> V_69 ;
} else {
if ( ! V_397 ) {
F_230 ( 1 , L_10 ,
V_75 -> V_401 ) ;
goto V_226;
}
V_87 = V_397 -> V_259 . V_402 ? : V_50 -> V_86 . V_87 ;
V_118 = F_231 ( V_397 -> V_259 . V_403 ) ;
V_69 . V_8 . V_9 = F_232 ( V_397 ) ;
if ( V_69 . V_8 . V_9 == V_22 )
V_69 . sin . V_13 . V_14 = V_397 -> V_259 . V_253 . V_404 . V_350 ;
else
V_69 . V_11 . V_12 = V_397 -> V_259 . V_253 . V_405 . V_350 ;
V_350 = & V_69 ;
}
if ( F_5 ( V_350 ) ) {
if ( V_395 ) {
F_226 ( V_25 , V_50 , V_50 ) ;
return;
}
goto V_226;
}
V_398 = F_159 ( V_25 ) ;
V_352 = V_50 -> V_86 . V_352 ;
if ( ! V_352 && F_8 ( V_350 ) )
V_352 = 1 ;
V_236 = V_50 -> V_86 . V_236 ;
if ( V_236 == 1 )
V_236 = F_233 ( V_398 , V_25 ) ;
V_353 = F_234 ( F_39 ( V_75 ) , V_25 , V_50 -> V_86 . V_406 ,
V_50 -> V_86 . V_407 , true ) ;
if ( V_397 ) {
V_352 = V_397 -> V_259 . V_352 ;
V_236 = V_397 -> V_259 . V_236 ;
if ( V_397 -> V_262 )
V_216 = F_177 ( V_397 ) ;
} else {
V_216 -> V_234 = V_25 -> V_233 ;
}
if ( V_350 -> V_8 . V_9 == V_22 ) {
if ( ! V_50 -> V_200 )
goto V_226;
V_47 = V_50 -> V_200 -> V_46 -> V_47 ;
if ( V_397 ) {
if ( V_397 -> V_259 . V_260 & V_408 )
V_374 = F_173 ( V_409 ) ;
if ( V_397 -> V_259 . V_260 & V_410 )
V_3 |= V_375 ;
else
V_3 &= ~ V_375 ;
}
memset ( & V_400 , 0 , sizeof( V_400 ) ) ;
V_400 . V_411 = V_55 ? V_55 -> V_90 : 0 ;
V_400 . V_412 = F_235 ( V_236 ) ;
V_400 . V_413 = V_25 -> V_233 ;
V_400 . V_414 = V_383 ;
V_400 . V_310 = V_350 -> sin . V_13 . V_14 ;
V_400 . V_225 = V_50 -> V_86 . V_225 . sin . V_13 . V_14 ;
V_372 = F_236 ( V_50 -> V_31 , & V_400 ) ;
if ( F_216 ( V_372 ) ) {
F_104 ( V_75 , L_11 ,
& V_350 -> sin . V_13 . V_14 ) ;
V_75 -> V_224 . V_415 ++ ;
goto V_416;
}
if ( V_372 -> V_350 . V_75 == V_75 ) {
F_104 ( V_75 , L_12 ,
& V_350 -> sin . V_13 . V_14 ) ;
V_75 -> V_224 . V_417 ++ ;
goto V_418;
}
if ( V_372 -> V_419 & V_420 &&
! ( V_372 -> V_419 & ( V_421 | V_422 ) ) ) {
struct V_49 * V_386 ;
F_237 ( V_372 ) ;
V_386 = F_33 ( V_50 -> V_31 , V_118 ,
V_350 -> V_8 . V_9 , V_87 ,
V_50 -> V_3 ) ;
if ( ! V_386 )
goto V_416;
F_226 ( V_25 , V_50 , V_386 ) ;
return;
}
V_236 = F_238 ( V_236 , V_398 , V_25 ) ;
V_352 = V_352 ? : F_239 ( & V_372 -> V_350 ) ;
V_102 = F_221 ( V_372 , V_47 , V_25 , V_400 . V_225 ,
V_350 -> sin . V_13 . V_14 , V_236 , V_352 , V_374 ,
V_353 , V_87 , F_7 ( V_118 << 8 ) , V_216 ,
! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ,
V_3 ) ;
if ( V_102 < 0 ) {
V_25 = NULL ;
goto V_418;
}
#if F_115 ( V_178 )
} else {
struct V_231 * V_377 ;
struct V_20 V_225 ;
T_1 V_423 ;
if ( ! V_50 -> V_202 )
goto V_226;
V_47 = V_50 -> V_202 -> V_46 -> V_47 ;
V_377 = F_224 ( V_50 , V_25 ,
V_55 ? V_55 -> V_90 : 0 ,
& V_350 -> V_11 . V_12 , & V_225 ) ;
if ( F_216 ( V_377 ) ) {
F_104 ( V_75 , L_13 ,
& V_350 -> V_11 . V_12 ) ;
V_75 -> V_224 . V_415 ++ ;
goto V_416;
}
if ( V_377 -> V_75 == V_75 ) {
F_104 ( V_75 , L_14 ,
& V_350 -> V_11 . V_12 ) ;
F_170 ( V_377 ) ;
V_75 -> V_224 . V_417 ++ ;
goto V_416;
}
V_423 = ( (struct V_424 * ) V_377 ) -> V_423 ;
if ( V_423 & V_425 &&
! ( V_423 & ( V_421 | V_422 ) ) ) {
struct V_49 * V_386 ;
F_170 ( V_377 ) ;
V_386 = F_33 ( V_50 -> V_31 , V_118 ,
V_350 -> V_8 . V_9 , V_87 ,
V_50 -> V_3 ) ;
if ( ! V_386 )
goto V_416;
F_226 ( V_25 , V_50 , V_386 ) ;
return;
}
if ( V_397 ) {
if ( V_397 -> V_259 . V_260 & V_410 )
V_3 &= ~ V_357 ;
else
V_3 |= V_357 ;
}
V_352 = V_352 ? : F_240 ( V_377 ) ;
V_102 = F_210 ( V_377 , V_47 , V_25 , V_75 , & V_225 , & V_350 -> V_11 . V_12 ,
0 , V_352 , V_353 , V_87 , F_7 ( V_118 << 8 ) , V_216 ,
! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ,
V_3 ) ;
#endif
}
return;
V_226:
V_75 -> V_224 . V_277 ++ ;
goto V_426;
V_418:
F_237 ( V_372 ) ;
V_416:
V_75 -> V_224 . V_427 ++ ;
V_426:
F_241 ( V_25 ) ;
}
static T_10 F_242 ( struct V_24 * V_25 , struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
const struct V_396 * V_397 ;
struct V_316 * V_428 ;
bool V_395 = false ;
struct V_38 * V_55 , * V_429 = NULL ;
struct V_39 * V_108 ;
V_397 = F_229 ( V_25 ) ;
F_154 ( V_25 ) ;
V_428 = F_158 ( V_25 ) ;
if ( ( V_50 -> V_3 & V_430 ) ) {
if ( F_23 ( V_428 -> V_321 ) == V_294 )
return F_178 ( V_75 , V_25 ) ;
#if F_115 ( V_178 )
else if ( F_23 ( V_428 -> V_321 ) == V_315 &&
F_150 ( V_25 , sizeof( struct V_221 )
+ sizeof( struct V_306 ) ) &&
F_160 ( V_25 ) -> V_324 == V_325 ) {
struct V_306 * V_338 ;
V_338 = (struct V_306 * ) F_196 ( V_25 ) ;
if ( V_338 -> V_328 . V_341 == 0 &&
V_338 -> V_328 . V_329 == V_342 )
return F_205 ( V_75 , V_25 ) ;
}
V_428 = F_158 ( V_25 ) ;
#endif
}
if ( V_50 -> V_3 & V_4 ) {
if ( V_397 && V_397 -> V_431 & V_432 )
F_228 ( V_25 , V_75 , NULL , false ) ;
else
F_54 ( V_25 ) ;
return V_303 ;
}
V_108 = F_67 ( V_50 , V_428 -> V_320 ) ;
V_395 = false ;
if ( V_108 && ( V_108 -> V_3 & V_344 ) && ( V_50 -> V_3 & V_433 ) &&
( F_23 ( V_428 -> V_321 ) == V_282 ||
F_23 ( V_428 -> V_321 ) == V_315 ) ) {
V_395 = F_208 ( V_75 , V_25 ) ;
if ( V_395 )
V_108 = F_67 ( V_50 , V_428 -> V_320 ) ;
}
if ( V_108 == NULL ) {
V_108 = F_67 ( V_50 , V_434 ) ;
if ( V_108 == NULL ) {
if ( ( V_50 -> V_3 & V_435 ) &&
! F_105 ( V_428 -> V_320 ) )
F_59 ( V_50 , V_428 -> V_320 ) ;
V_75 -> V_224 . V_277 ++ ;
F_54 ( V_25 ) ;
return V_303 ;
}
}
F_128 (rdst, &f->remotes, list) {
struct V_24 * V_436 ;
if ( ! V_429 ) {
V_429 = V_55 ;
continue;
}
V_436 = F_243 ( V_25 , V_104 ) ;
if ( V_436 )
F_228 ( V_436 , V_75 , V_55 , V_395 ) ;
}
if ( V_429 )
F_228 ( V_25 , V_75 , V_429 , V_395 ) ;
else
F_54 ( V_25 ) ;
return V_303 ;
}
static void F_244 ( unsigned long V_437 )
{
struct V_49 * V_50 = (struct V_49 * ) V_437 ;
unsigned long V_438 = V_57 + V_439 ;
unsigned int V_191 ;
if ( ! F_135 ( V_50 -> V_75 ) )
return;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 ) {
struct V_440 * V_140 , * V_275 ;
F_121 ( & V_50 -> V_186 ) ;
F_245 (p, n, &vxlan->fdb_head[h]) {
struct V_39 * V_108
= F_80 ( V_140 , struct V_39 , V_171 ) ;
unsigned long V_441 ;
if ( V_108 -> V_73 & V_184 )
continue;
V_441 = V_108 -> V_93 + V_50 -> V_86 . V_442 * V_443 ;
if ( F_246 ( V_441 , V_57 ) ) {
F_104 ( V_50 -> V_75 ,
L_15 ,
V_108 -> V_70 ) ;
V_108 -> V_73 = V_109 ;
F_111 ( V_50 , V_108 ) ;
} else if ( F_247 ( V_441 , V_438 ) )
V_438 = V_441 ;
}
F_122 ( & V_50 -> V_186 ) ;
}
F_248 ( & V_50 -> V_444 , V_438 ) ;
}
static void F_249 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
V_99 V_118 = V_50 -> V_51 . V_52 ;
F_134 ( & V_34 -> V_203 ) ;
F_107 ( & V_50 -> V_171 , F_19 ( V_2 , V_118 ) ) ;
F_136 ( & V_34 -> V_203 ) ;
}
static int F_250 ( struct V_107 * V_75 )
{
V_75 -> V_239 = F_251 ( struct V_223 ) ;
if ( ! V_75 -> V_239 )
return - V_170 ;
return 0 ;
}
static void F_252 ( struct V_49 * V_50 )
{
struct V_39 * V_108 ;
F_121 ( & V_50 -> V_186 ) ;
V_108 = F_65 ( V_50 , V_434 ) ;
if ( V_108 )
F_111 ( V_50 , V_108 ) ;
F_122 ( & V_50 -> V_186 ) ;
}
static void F_253 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
F_252 ( V_50 ) ;
F_254 ( V_75 -> V_239 ) ;
}
static int F_255 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
int V_206 ;
V_206 = F_256 ( V_50 ) ;
if ( V_206 < 0 )
return V_206 ;
if ( F_8 ( & V_50 -> V_51 . V_69 ) ) {
V_206 = F_143 ( V_50 ) ;
if ( V_206 == - V_445 )
V_206 = 0 ;
if ( V_206 ) {
F_142 ( V_50 ) ;
return V_206 ;
}
}
if ( V_50 -> V_86 . V_442 )
F_248 ( & V_50 -> V_444 , V_57 + V_439 ) ;
return V_206 ;
}
static void F_257 ( struct V_49 * V_50 )
{
unsigned int V_191 ;
F_121 ( & V_50 -> V_186 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 ) {
struct V_440 * V_140 , * V_275 ;
F_245 (p, n, &vxlan->fdb_head[h]) {
struct V_39 * V_108
= F_80 ( V_140 , struct V_39 , V_171 ) ;
if ( ! F_37 ( V_108 -> V_70 ) )
F_111 ( V_50 , V_108 ) ;
}
}
F_122 ( & V_50 -> V_186 ) ;
}
static int F_258 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
int V_206 = 0 ;
if ( F_8 ( & V_50 -> V_51 . V_69 ) &&
! F_137 ( V_34 , V_50 ) )
V_206 = F_147 ( V_50 ) ;
F_259 ( & V_50 -> V_444 ) ;
F_257 ( V_50 ) ;
F_142 ( V_50 ) ;
return V_206 ;
}
static void F_260 ( struct V_107 * V_75 )
{
}
static int F_261 ( struct V_107 * V_75 ,
struct V_107 * V_446 ,
struct V_38 * V_350 , int V_447 , bool V_448 )
{
int V_449 = V_450 ;
if ( V_446 )
V_449 = V_446 -> V_451 ;
if ( V_350 -> V_69 . V_8 . V_9 == V_10 )
V_449 -= V_452 ;
else
V_449 -= V_453 ;
if ( V_447 < 68 )
return - V_180 ;
if ( V_447 > V_449 ) {
if ( V_448 )
return - V_180 ;
V_447 = V_449 ;
}
V_75 -> V_451 = V_447 ;
return 0 ;
}
static int F_262 ( struct V_107 * V_75 , int V_447 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_38 * V_350 = & V_50 -> V_51 ;
struct V_107 * V_446 = F_118 ( V_50 -> V_31 ,
V_350 -> V_90 ) ;
return F_261 ( V_75 , V_446 , V_350 , V_447 , true ) ;
}
static int F_263 ( struct V_107 * V_75 , struct V_24 * V_25 ,
struct V_396 * V_397 ,
T_2 V_454 , T_2 V_455 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_371 * V_372 ;
struct V_399 V_400 ;
memset ( & V_400 , 0 , sizeof( V_400 ) ) ;
V_400 . V_412 = F_235 ( V_397 -> V_259 . V_236 ) ;
V_400 . V_413 = V_25 -> V_233 ;
V_400 . V_414 = V_383 ;
V_400 . V_310 = V_397 -> V_259 . V_253 . V_404 . V_350 ;
V_372 = F_236 ( V_50 -> V_31 , & V_400 ) ;
if ( F_216 ( V_372 ) )
return F_222 ( V_372 ) ;
F_237 ( V_372 ) ;
V_397 -> V_259 . V_253 . V_404 . V_373 = V_400 . V_225 ;
V_397 -> V_259 . V_456 = V_454 ;
V_397 -> V_259 . V_402 = V_455 ;
return 0 ;
}
static int F_264 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_396 * V_397 = F_229 ( V_25 ) ;
T_2 V_454 , V_455 ;
V_454 = F_234 ( F_39 ( V_75 ) , V_25 , V_50 -> V_86 . V_406 ,
V_50 -> V_86 . V_407 , true ) ;
V_455 = V_397 -> V_259 . V_402 ? : V_50 -> V_86 . V_87 ;
if ( F_232 ( V_397 ) == V_22 ) {
if ( ! V_50 -> V_200 )
return - V_180 ;
return F_263 ( V_75 , V_25 , V_397 , V_454 , V_455 ) ;
} else {
#if F_115 ( V_178 )
struct V_231 * V_377 ;
if ( ! V_50 -> V_202 )
return - V_180 ;
V_377 = F_224 ( V_50 , V_25 , 0 ,
& V_397 -> V_259 . V_253 . V_405 . V_350 ,
& V_397 -> V_259 . V_253 . V_405 . V_373 ) ;
if ( F_216 ( V_377 ) )
return F_222 ( V_377 ) ;
F_170 ( V_377 ) ;
V_397 -> V_259 . V_456 = V_454 ;
V_397 -> V_259 . V_402 = V_455 ;
#else
return - V_457 ;
#endif
}
return 0 ;
}
void F_265 ( struct V_107 * V_75 )
{
struct V_1 * V_2 ;
struct V_31 * V_31 = F_39 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
T_3 V_9 ;
T_2 V_32 ;
unsigned int V_313 ;
F_134 ( & V_34 -> V_203 ) ;
for ( V_313 = 0 ; V_313 < V_458 ; ++ V_313 ) {
F_29 (vs, &vn->sock_list[i], hlist) {
V_32 = F_30 ( V_2 -> V_46 -> V_47 ) -> V_48 ;
V_9 = F_31 ( V_2 ) ;
V_75 -> V_155 -> V_156 ( V_75 , V_9 ,
V_32 ) ;
}
}
F_136 ( & V_34 -> V_203 ) ;
}
static void F_266 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
unsigned int V_191 ;
F_267 ( V_75 ) ;
F_268 ( V_75 ) ;
V_75 -> V_155 = & V_459 ;
V_75 -> V_460 = V_461 ;
F_269 ( V_75 , & V_462 ) ;
V_75 -> V_463 |= V_464 ;
V_75 -> V_463 |= V_465 | V_466 ;
V_75 -> V_463 |= V_467 ;
V_75 -> V_463 |= V_468 ;
V_75 -> V_469 = V_75 -> V_463 ;
V_75 -> V_463 |= V_470 | V_471 ;
V_75 -> V_472 |= V_465 | V_466 | V_467 ;
V_75 -> V_472 |= V_468 ;
V_75 -> V_472 |= V_470 | V_471 ;
F_270 ( V_75 ) ;
V_75 -> V_473 &= ~ V_474 ;
V_75 -> V_473 |= V_475 | V_476 ;
F_106 ( & V_50 -> V_42 ) ;
F_271 ( & V_50 -> V_186 ) ;
F_272 ( & V_50 -> V_444 ) ;
V_50 -> V_444 . V_477 = F_244 ;
V_50 -> V_444 . V_124 = ( unsigned long ) V_50 ;
V_50 -> V_86 . V_87 = F_173 ( V_478 ) ;
V_50 -> V_75 = V_75 ;
F_273 ( & V_50 -> V_244 , V_75 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 )
F_274 ( & V_50 -> V_116 [ V_191 ] ) ;
}
static int F_275 ( struct V_18 * V_177 [] , struct V_18 * V_124 [] )
{
if ( V_177 [ V_479 ] ) {
if ( F_13 ( V_177 [ V_479 ] ) != V_83 ) {
F_276 ( L_16 ) ;
return - V_180 ;
}
if ( ! F_277 ( F_278 ( V_177 [ V_479 ] ) ) ) {
F_276 ( L_17 ) ;
return - V_182 ;
}
}
if ( ! V_124 )
return - V_180 ;
if ( V_124 [ V_480 ] ) {
V_99 V_28 = F_117 ( V_124 [ V_480 ] ) ;
if ( V_28 >= V_481 )
return - V_482 ;
}
if ( V_124 [ V_483 ] ) {
const struct V_484 * V_140
= F_278 ( V_124 [ V_483 ] ) ;
if ( F_23 ( V_140 -> V_485 ) < F_23 ( V_140 -> V_486 ) ) {
F_276 ( L_18 ,
F_23 ( V_140 -> V_486 ) , F_23 ( V_140 -> V_485 ) ) ;
return - V_180 ;
}
}
return 0 ;
}
static void F_279 ( struct V_107 * V_487 ,
struct V_488 * V_489 )
{
F_280 ( V_489 -> V_322 , V_490 , sizeof( V_489 -> V_322 ) ) ;
F_280 ( V_489 -> V_491 , L_19 , sizeof( V_489 -> V_491 ) ) ;
}
static void F_281 ( struct V_492 * V_493 )
{
struct V_1 * V_2 = F_80 ( V_493 , struct V_1 , V_205 ) ;
F_282 ( V_2 -> V_46 ) ;
F_126 ( V_2 , V_174 ) ;
}
static struct V_494 * F_283 ( struct V_31 * V_31 , bool V_405 ,
T_2 V_32 , T_1 V_3 )
{
struct V_494 * V_46 ;
struct V_495 V_496 ;
int V_102 ;
memset ( & V_496 , 0 , sizeof( V_496 ) ) ;
if ( V_405 ) {
V_496 . V_44 = V_10 ;
V_496 . V_497 =
! ( V_3 & V_498 ) ;
V_496 . V_499 = 1 ;
} else {
V_496 . V_44 = V_22 ;
}
V_496 . V_500 = V_32 ;
V_102 = F_284 ( V_31 , & V_496 , & V_46 ) ;
if ( V_102 < 0 )
return F_225 ( V_102 ) ;
return V_46 ;
}
static struct V_1 * F_285 ( struct V_31 * V_31 , bool V_405 ,
T_2 V_32 , T_1 V_3 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
struct V_1 * V_2 ;
struct V_494 * V_46 ;
unsigned int V_191 ;
struct V_501 V_502 ;
V_2 = F_286 ( sizeof( * V_2 ) , V_503 ) ;
if ( ! V_2 )
return F_225 ( - V_170 ) ;
for ( V_191 = 0 ; V_191 < V_504 ; ++ V_191 )
F_274 ( & V_2 -> V_29 [ V_191 ] ) ;
F_287 ( & V_2 -> V_205 , F_281 ) ;
V_46 = F_283 ( V_31 , V_405 , V_32 , V_3 ) ;
if ( F_216 ( V_46 ) ) {
F_120 ( L_20 , F_23 ( V_32 ) ,
F_222 ( V_46 ) ) ;
F_110 ( V_2 ) ;
return F_288 ( V_46 ) ;
}
V_2 -> V_46 = V_46 ;
F_289 ( & V_2 -> V_201 , 1 ) ;
V_2 -> V_3 = ( V_3 & V_45 ) ;
V_2 -> V_146 . V_32 = V_32 ;
V_2 -> V_146 . V_505 . V_506 = F_79 ;
V_2 -> V_146 . V_505 . V_507 = F_91 ;
F_134 ( & V_34 -> V_203 ) ;
F_107 ( & V_2 -> V_171 , F_21 ( V_31 , V_32 ) ) ;
F_94 ( V_2 ) ;
F_136 ( & V_34 -> V_203 ) ;
V_502 . V_508 = V_2 ;
V_502 . V_509 = 1 ;
V_502 . V_510 = F_171 ;
V_502 . V_511 = NULL ;
F_290 ( V_31 , V_46 , & V_502 ) ;
return V_2 ;
}
static int F_291 ( struct V_49 * V_50 , bool V_405 )
{
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
struct V_1 * V_2 = NULL ;
if ( ! V_50 -> V_86 . V_512 ) {
F_134 ( & V_34 -> V_203 ) ;
V_2 = F_28 ( V_50 -> V_31 , V_405 ? V_10 : V_22 ,
V_50 -> V_86 . V_87 , V_50 -> V_3 ) ;
if ( V_2 && ! F_292 ( & V_2 -> V_201 , 1 , 0 ) ) {
F_136 ( & V_34 -> V_203 ) ;
return - V_513 ;
}
F_136 ( & V_34 -> V_203 ) ;
}
if ( ! V_2 )
V_2 = F_285 ( V_50 -> V_31 , V_405 ,
V_50 -> V_86 . V_87 , V_50 -> V_3 ) ;
if ( F_216 ( V_2 ) )
return F_222 ( V_2 ) ;
#if F_115 ( V_178 )
if ( V_405 )
V_50 -> V_202 = V_2 ;
else
#endif
V_50 -> V_200 = V_2 ;
F_249 ( V_2 , V_50 ) ;
return 0 ;
}
static int F_256 ( struct V_49 * V_50 )
{
bool V_405 = V_50 -> V_3 & V_514 ;
bool V_515 = V_50 -> V_3 & V_4 ;
int V_206 = 0 ;
V_50 -> V_200 = NULL ;
#if F_115 ( V_178 )
V_50 -> V_202 = NULL ;
if ( V_405 || V_515 )
V_206 = F_291 ( V_50 , true ) ;
#endif
if ( ! V_206 && ( ! V_405 || V_515 ) )
V_206 = F_291 ( V_50 , false ) ;
if ( V_206 < 0 )
F_142 ( V_50 ) ;
return V_206 ;
}
static int F_293 ( struct V_31 * V_516 , struct V_107 * V_75 ,
struct V_517 * V_518 )
{
struct V_33 * V_34 = F_22 ( V_516 , V_35 ) ;
struct V_49 * V_50 = F_58 ( V_75 ) , * V_519 ;
struct V_38 * V_350 = & V_50 -> V_51 ;
unsigned short V_520 = V_228 ;
int V_102 ;
bool V_521 = false ;
T_2 V_522 = V_50 -> V_86 . V_87 ;
struct V_107 * V_446 = NULL ;
V_50 -> V_31 = V_516 ;
V_350 -> V_52 = V_518 -> V_118 ;
memcpy ( & V_350 -> V_69 , & V_518 -> V_69 , sizeof( V_518 -> V_69 ) ) ;
if ( ! V_350 -> V_69 . V_8 . V_9 )
V_350 -> V_69 . V_8 . V_9 = V_22 ;
if ( V_350 -> V_69 . V_8 . V_9 == V_10 ||
V_50 -> V_86 . V_225 . V_8 . V_9 == V_10 ) {
if ( ! F_115 ( V_178 ) )
return - V_457 ;
V_521 = true ;
V_50 -> V_3 |= V_514 ;
}
if ( V_518 -> V_90 ) {
V_446 = F_118 ( V_516 , V_518 -> V_90 ) ;
V_350 -> V_90 = V_518 -> V_90 ;
if ( ! V_446 ) {
F_120 ( L_21 , V_350 -> V_90 ) ;
return - V_523 ;
}
#if F_115 ( V_178 )
if ( V_521 ) {
struct V_339 * V_524 = F_206 ( V_446 ) ;
if ( V_524 && V_524 -> V_525 . V_526 ) {
F_120 ( L_22 ) ;
return - V_527 ;
}
}
#endif
if ( ! V_518 -> V_451 )
V_75 -> V_451 = V_446 -> V_451 - ( V_521 ? V_452 : V_453 ) ;
V_520 = V_446 -> V_528 ;
}
if ( V_518 -> V_451 ) {
V_102 = F_261 ( V_75 , V_446 , V_350 , V_518 -> V_451 , false ) ;
if ( V_102 )
return V_102 ;
}
if ( V_521 || V_518 -> V_3 & V_4 )
V_520 += V_452 ;
else
V_520 += V_453 ;
V_75 -> V_520 = V_520 ;
memcpy ( & V_50 -> V_86 , V_518 , sizeof( * V_518 ) ) ;
if ( ! V_50 -> V_86 . V_87 )
V_50 -> V_86 . V_87 = V_522 ;
V_50 -> V_3 |= V_518 -> V_3 ;
if ( ! V_50 -> V_86 . V_442 )
V_50 -> V_86 . V_442 = V_529 ;
F_69 (tmp, &vn->vxlan_list, next) {
if ( V_519 -> V_86 . V_118 == V_518 -> V_118 &&
( V_519 -> V_51 . V_69 . V_8 . V_9 == V_10 ||
V_519 -> V_86 . V_225 . V_8 . V_9 == V_10 ) == V_521 &&
V_519 -> V_86 . V_87 == V_50 -> V_86 . V_87 &&
( V_519 -> V_3 & V_45 ) ==
( V_50 -> V_3 & V_45 ) )
return - V_160 ;
}
V_75 -> V_530 = & V_531 ;
if ( ! F_5 ( & V_50 -> V_51 . V_69 ) ) {
V_102 = F_103 ( V_50 , V_434 ,
& V_50 -> V_51 . V_69 ,
V_185 | V_184 ,
V_159 | V_165 ,
V_50 -> V_86 . V_87 ,
V_50 -> V_51 . V_52 ,
V_50 -> V_51 . V_90 ,
V_199 ) ;
if ( V_102 )
return V_102 ;
}
V_102 = F_294 ( V_75 ) ;
if ( V_102 ) {
F_252 ( V_50 ) ;
return V_102 ;
}
F_295 ( & V_50 -> V_42 , & V_34 -> V_532 ) ;
return 0 ;
}
struct V_107 * F_296 ( struct V_31 * V_31 , const char * V_401 ,
T_5 V_533 , struct V_517 * V_518 )
{
struct V_18 * V_177 [ V_534 + 1 ] ;
struct V_107 * V_75 ;
int V_102 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_75 = F_297 ( V_31 , V_401 , V_533 ,
& V_535 , V_177 ) ;
if ( F_216 ( V_75 ) )
return V_75 ;
V_102 = F_293 ( V_31 , V_75 , V_518 ) ;
if ( V_102 < 0 ) {
V_461 ( V_75 ) ;
return F_225 ( V_102 ) ;
}
return V_75 ;
}
static int F_298 ( struct V_31 * V_516 , struct V_107 * V_75 ,
struct V_18 * V_177 [] , struct V_18 * V_124 [] )
{
struct V_517 V_518 ;
int V_102 ;
memset ( & V_518 , 0 , sizeof( V_518 ) ) ;
if ( V_124 [ V_480 ] )
V_518 . V_118 = F_117 ( V_124 [ V_480 ] ) ;
if ( V_124 [ V_536 ] ) {
V_518 . V_69 . sin . V_13 . V_14 = F_15 ( V_124 [ V_536 ] ) ;
} else if ( V_124 [ V_537 ] ) {
if ( ! F_115 ( V_178 ) )
return - V_457 ;
V_518 . V_69 . V_11 . V_12 = F_14 ( V_124 [ V_537 ] ) ;
V_518 . V_69 . V_8 . V_9 = V_10 ;
}
if ( V_124 [ V_538 ] ) {
V_518 . V_225 . sin . V_13 . V_14 = F_15 ( V_124 [ V_538 ] ) ;
V_518 . V_225 . V_8 . V_9 = V_22 ;
} else if ( V_124 [ V_539 ] ) {
if ( ! F_115 ( V_178 ) )
return - V_457 ;
V_518 . V_225 . V_11 . V_12 = F_14 ( V_124 [ V_539 ] ) ;
V_518 . V_225 . V_8 . V_9 = V_10 ;
}
if ( V_124 [ V_540 ] )
V_518 . V_90 = F_117 ( V_124 [ V_540 ] ) ;
if ( V_124 [ V_541 ] )
V_518 . V_236 = F_299 ( V_124 [ V_541 ] ) ;
if ( V_124 [ V_542 ] )
V_518 . V_352 = F_299 ( V_124 [ V_542 ] ) ;
if ( ! V_124 [ V_543 ] || F_299 ( V_124 [ V_543 ] ) )
V_518 . V_3 |= V_232 ;
if ( V_124 [ V_544 ] )
V_518 . V_442 = F_117 ( V_124 [ V_544 ] ) ;
if ( V_124 [ V_545 ] && F_299 ( V_124 [ V_545 ] ) )
V_518 . V_3 |= V_430 ;
if ( V_124 [ V_546 ] && F_299 ( V_124 [ V_546 ] ) )
V_518 . V_3 |= V_433 ;
if ( V_124 [ V_547 ] && F_299 ( V_124 [ V_547 ] ) )
V_518 . V_3 |= V_435 ;
if ( V_124 [ V_548 ] && F_299 ( V_124 [ V_548 ] ) )
V_518 . V_3 |= V_301 ;
if ( V_124 [ V_549 ] )
V_518 . V_167 = F_117 ( V_124 [ V_549 ] ) ;
if ( V_124 [ V_550 ] &&
F_299 ( V_124 [ V_550 ] ) )
V_518 . V_3 |= V_4 ;
if ( V_124 [ V_483 ] ) {
const struct V_484 * V_140
= F_278 ( V_124 [ V_483 ] ) ;
V_518 . V_406 = F_23 ( V_140 -> V_486 ) ;
V_518 . V_407 = F_23 ( V_140 -> V_485 ) ;
}
if ( V_124 [ V_551 ] )
V_518 . V_87 = F_116 ( V_124 [ V_551 ] ) ;
if ( V_124 [ V_552 ] && F_299 ( V_124 [ V_552 ] ) )
V_518 . V_3 |= V_375 ;
if ( V_124 [ V_553 ] &&
F_299 ( V_124 [ V_553 ] ) )
V_518 . V_3 |= V_357 ;
if ( V_124 [ V_554 ] &&
F_299 ( V_124 [ V_554 ] ) )
V_518 . V_3 |= V_498 ;
if ( V_124 [ V_555 ] &&
F_299 ( V_124 [ V_555 ] ) )
V_518 . V_3 |= V_360 ;
if ( V_124 [ V_556 ] &&
F_299 ( V_124 [ V_556 ] ) )
V_518 . V_3 |= V_150 ;
if ( V_124 [ V_557 ] )
V_518 . V_3 |= V_256 ;
if ( V_124 [ V_558 ] )
V_518 . V_3 |= V_152 ;
V_102 = F_293 ( V_516 , V_75 , & V_518 ) ;
switch ( V_102 ) {
case - V_523 :
F_120 ( L_21 , V_518 . V_90 ) ;
break;
case - V_527 :
F_120 ( L_22 ) ;
break;
case - V_160 :
F_120 ( L_23 , V_518 . V_118 ) ;
break;
}
return V_102 ;
}
static void F_300 ( struct V_107 * V_75 , struct V_559 * V_117 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
F_134 ( & V_34 -> V_203 ) ;
if ( ! F_301 ( & V_50 -> V_171 ) )
F_112 ( & V_50 -> V_171 ) ;
F_136 ( & V_34 -> V_203 ) ;
F_302 ( & V_50 -> V_244 ) ;
F_303 ( & V_50 -> V_42 ) ;
F_304 ( V_75 , V_117 ) ;
}
static T_4 F_305 ( const struct V_107 * V_75 )
{
return F_50 ( sizeof( V_99 ) ) +
F_50 ( sizeof( struct V_20 ) ) +
F_50 ( sizeof( V_99 ) ) +
F_50 ( sizeof( struct V_20 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( V_99 ) ) +
F_50 ( sizeof( V_99 ) ) +
F_50 ( sizeof( struct V_484 ) ) +
F_50 ( sizeof( T_2 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
0 ;
}
static int F_306 ( struct V_24 * V_25 , const struct V_107 * V_75 )
{
const struct V_49 * V_50 = F_58 ( V_75 ) ;
const struct V_38 * V_350 = & V_50 -> V_51 ;
struct V_484 V_560 = {
. V_486 = F_173 ( V_50 -> V_86 . V_406 ) ,
. V_485 = F_173 ( V_50 -> V_86 . V_407 ) ,
} ;
if ( F_44 ( V_25 , V_480 , V_350 -> V_52 ) )
goto V_81;
if ( ! F_5 ( & V_350 -> V_69 ) ) {
if ( V_350 -> V_69 . V_8 . V_9 == V_22 ) {
if ( F_18 ( V_25 , V_536 ,
V_350 -> V_69 . sin . V_13 . V_14 ) )
goto V_81;
#if F_115 ( V_178 )
} else {
if ( F_17 ( V_25 , V_537 ,
& V_350 -> V_69 . V_11 . V_12 ) )
goto V_81;
#endif
}
}
if ( V_350 -> V_90 && F_44 ( V_25 , V_540 , V_350 -> V_90 ) )
goto V_81;
if ( ! F_5 ( & V_50 -> V_86 . V_225 ) ) {
if ( V_50 -> V_86 . V_225 . V_8 . V_9 == V_22 ) {
if ( F_18 ( V_25 , V_538 ,
V_50 -> V_86 . V_225 . sin . V_13 . V_14 ) )
goto V_81;
#if F_115 ( V_178 )
} else {
if ( F_17 ( V_25 , V_539 ,
& V_50 -> V_86 . V_225 . V_11 . V_12 ) )
goto V_81;
#endif
}
}
if ( F_307 ( V_25 , V_542 , V_50 -> V_86 . V_352 ) ||
F_307 ( V_25 , V_541 , V_50 -> V_86 . V_236 ) ||
F_307 ( V_25 , V_543 ,
! ! ( V_50 -> V_3 & V_232 ) ) ||
F_307 ( V_25 , V_545 ,
! ! ( V_50 -> V_3 & V_430 ) ) ||
F_307 ( V_25 , V_546 , ! ! ( V_50 -> V_3 & V_433 ) ) ||
F_307 ( V_25 , V_547 ,
! ! ( V_50 -> V_3 & V_435 ) ) ||
F_307 ( V_25 , V_548 ,
! ! ( V_50 -> V_3 & V_301 ) ) ||
F_307 ( V_25 , V_550 ,
! ! ( V_50 -> V_3 & V_4 ) ) ||
F_44 ( V_25 , V_544 , V_50 -> V_86 . V_442 ) ||
F_44 ( V_25 , V_549 , V_50 -> V_86 . V_167 ) ||
F_43 ( V_25 , V_551 , V_50 -> V_86 . V_87 ) ||
F_307 ( V_25 , V_552 ,
! ! ( V_50 -> V_3 & V_375 ) ) ||
F_307 ( V_25 , V_553 ,
! ! ( V_50 -> V_3 & V_357 ) ) ||
F_307 ( V_25 , V_554 ,
! ! ( V_50 -> V_3 & V_498 ) ) ||
F_307 ( V_25 , V_555 ,
! ! ( V_50 -> V_3 & V_360 ) ) ||
F_307 ( V_25 , V_556 ,
! ! ( V_50 -> V_3 & V_150 ) ) )
goto V_81;
if ( F_42 ( V_25 , V_483 , sizeof( V_560 ) , & V_560 ) )
goto V_81;
if ( V_50 -> V_3 & V_256 &&
F_308 ( V_25 , V_557 ) )
goto V_81;
if ( V_50 -> V_3 & V_152 &&
F_308 ( V_25 , V_558 ) )
goto V_81;
return 0 ;
V_81:
return - V_66 ;
}
static struct V_31 * F_309 ( const struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
return V_50 -> V_31 ;
}
static void F_310 ( struct V_33 * V_34 ,
struct V_107 * V_75 )
{
struct V_49 * V_50 , * V_42 ;
F_311 ( V_561 ) ;
F_109 (vxlan, next, &vn->vxlan_list, next) {
struct V_38 * V_350 = & V_50 -> V_51 ;
if ( V_350 -> V_90 == V_75 -> V_76 )
F_300 ( V_50 -> V_75 , & V_561 ) ;
}
F_312 ( & V_561 ) ;
}
static int F_313 ( struct V_562 * V_563 ,
unsigned long V_564 , void * V_565 )
{
struct V_107 * V_75 = F_314 ( V_565 ) ;
struct V_33 * V_34 = F_22 ( F_39 ( V_75 ) , V_35 ) ;
if ( V_564 == V_566 )
F_310 ( V_34 , V_75 ) ;
return V_567 ;
}
static T_11 int F_315 ( struct V_31 * V_31 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
unsigned int V_191 ;
F_106 ( & V_34 -> V_532 ) ;
F_271 ( & V_34 -> V_203 ) ;
for ( V_191 = 0 ; V_191 < V_458 ; ++ V_191 )
F_274 ( & V_34 -> V_36 [ V_191 ] ) ;
return 0 ;
}
static void T_12 F_316 ( struct V_31 * V_31 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
struct V_49 * V_50 , * V_42 ;
struct V_107 * V_75 , * V_568 ;
F_311 ( V_43 ) ;
F_317 () ;
F_318 (net, dev, aux)
if ( V_75 -> V_569 == & V_535 )
F_304 ( V_75 , & V_43 ) ;
F_109 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_38 ( F_39 ( V_50 -> V_75 ) , V_31 ) ) {
F_302 ( & V_50 -> V_244 ) ;
F_304 ( V_50 -> V_75 , & V_43 ) ;
}
}
F_312 ( & V_43 ) ;
F_319 () ;
}
static int T_13 F_320 ( void )
{
int V_164 ;
V_204 = F_321 ( L_19 , 0 , 0 ) ;
if ( ! V_204 )
return - V_170 ;
F_322 ( & V_570 , sizeof( V_570 ) ) ;
V_164 = F_323 ( & V_571 ) ;
if ( V_164 )
goto V_572;
V_164 = F_324 ( & V_573 ) ;
if ( V_164 )
goto V_574;
V_164 = F_325 ( & V_535 ) ;
if ( V_164 )
goto V_575;
return 0 ;
V_575:
F_326 ( & V_573 ) ;
V_574:
F_327 ( & V_571 ) ;
V_572:
F_328 ( V_204 ) ;
return V_164 ;
}
static void T_14 F_329 ( void )
{
F_330 ( & V_535 ) ;
F_326 ( & V_573 ) ;
F_328 ( V_204 ) ;
F_327 ( & V_571 ) ;
}
