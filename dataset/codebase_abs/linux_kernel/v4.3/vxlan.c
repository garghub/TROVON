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
V_102 = F_96 ( & V_2 -> V_146 ) ;
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
if ( V_102 < 0 )
goto V_147;
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
if ( F_138 ( & V_75 -> V_200 -> V_201 ) == 1 )
return false ;
F_69 (vxlan, &vn->vxlan_list, next) {
if ( ! F_135 ( V_50 -> V_75 ) || V_50 == V_75 )
continue;
if ( V_50 -> V_200 != V_75 -> V_200 )
continue;
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
struct V_46 * V_47 = V_2 -> V_46 -> V_47 ;
struct V_31 * V_31 = F_95 ( V_47 ) ;
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
if ( ! F_140 ( & V_2 -> V_201 ) )
return;
F_134 ( & V_34 -> V_202 ) ;
F_112 ( & V_2 -> V_171 ) ;
F_101 ( V_2 ) ;
F_136 ( & V_34 -> V_202 ) ;
F_141 ( V_203 , & V_2 -> V_204 ) ;
}
static int F_142 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_200 ;
struct V_46 * V_47 = V_2 -> V_46 -> V_47 ;
union V_5 * V_17 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_90 ;
int V_205 = - V_180 ;
F_143 ( V_47 ) ;
if ( V_17 -> V_8 . V_9 == V_22 ) {
struct V_206 V_207 = {
. V_208 . V_14 = V_17 -> sin . V_13 . V_14 ,
. V_209 = V_76 ,
} ;
V_205 = F_144 ( V_47 , & V_207 ) ;
#if F_115 ( V_178 )
} else {
V_205 = V_210 -> V_211 ( V_47 , V_76 ,
& V_17 -> V_11 . V_12 ) ;
#endif
}
F_145 ( V_47 ) ;
return V_205 ;
}
static int F_146 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_200 ;
struct V_46 * V_47 = V_2 -> V_46 -> V_47 ;
union V_5 * V_17 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_90 ;
int V_205 = - V_180 ;
F_143 ( V_47 ) ;
if ( V_17 -> V_8 . V_9 == V_22 ) {
struct V_206 V_207 = {
. V_208 . V_14 = V_17 -> sin . V_13 . V_14 ,
. V_209 = V_76 ,
} ;
V_205 = F_147 ( V_47 , & V_207 ) ;
#if F_115 ( V_178 )
} else {
V_205 = V_210 -> V_212 ( V_47 , V_76 ,
& V_17 -> V_11 . V_12 ) ;
#endif
}
F_145 ( V_47 ) ;
return V_205 ;
}
static struct V_120 * F_148 ( struct V_24 * V_25 , struct V_120 * V_122 ,
T_4 V_123 , T_1 V_124 , bool V_127 )
{
T_4 V_128 , V_129 , V_213 ;
if ( V_25 -> V_130 )
return V_122 ;
V_128 = ( V_124 & V_132 ) << V_133 ;
V_129 = V_128 + ( ( V_124 & V_134 ) ?
F_77 ( struct V_135 , V_136 ) :
F_77 ( struct V_137 , V_136 ) ) ;
V_213 = V_123 + V_129 + sizeof( T_9 ) ;
if ( ! F_149 ( V_25 , V_213 ) )
return NULL ;
V_122 = (struct V_120 * ) ( F_150 ( V_25 ) + 1 ) ;
F_151 ( V_25 , ( void * ) V_122 + V_123 , V_128 , V_129 ,
V_127 ) ;
return V_122 ;
}
static void F_152 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_214 * V_215 , T_1 V_118 ,
struct V_216 * V_217 )
{
struct V_218 * V_219 = NULL ;
struct V_220 * V_221 = NULL ;
struct V_49 * V_50 ;
struct V_222 * V_223 ;
union V_5 V_224 ;
int V_102 = 0 ;
union V_5 * V_69 ;
if ( V_2 -> V_3 & V_4 )
V_118 = 0 ;
V_50 = F_32 ( V_2 , V_118 ) ;
if ( ! V_50 )
goto V_225;
V_69 = & V_50 -> V_51 . V_69 ;
F_153 ( V_25 ) ;
F_154 ( V_25 , ! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ) ;
V_25 -> V_226 = F_155 ( V_25 , V_50 -> V_75 ) ;
F_156 ( V_25 , F_157 ( V_25 ) , V_227 ) ;
if ( F_66 ( F_157 ( V_25 ) -> V_228 , V_50 -> V_75 -> V_229 ) )
goto V_225;
if ( V_69 -> V_8 . V_9 == V_22 ) {
V_219 = F_158 ( V_25 ) ;
V_224 . sin . V_13 . V_14 = V_219 -> V_224 ;
V_224 . V_8 . V_9 = V_22 ;
#if F_115 ( V_178 )
} else {
V_221 = F_159 ( V_25 ) ;
V_224 . V_11 . V_12 = V_221 -> V_224 ;
V_224 . V_8 . V_9 = V_10 ;
#endif
}
if ( V_217 ) {
F_160 ( V_25 , (struct V_230 * ) V_217 ) ;
V_217 = NULL ;
}
if ( ( V_50 -> V_3 & V_231 ) &&
F_130 ( V_25 -> V_75 , & V_224 , F_157 ( V_25 ) -> V_228 ) )
goto V_225;
F_161 ( V_25 ) ;
if ( ! ( V_2 -> V_3 & V_4 ) )
V_25 -> V_232 = V_215 -> V_233 ;
if ( V_221 )
V_102 = F_162 ( V_221 , V_25 ) ;
if ( V_219 )
V_102 = F_163 ( V_219 , V_25 ) ;
if ( F_86 ( V_102 ) ) {
if ( V_234 ) {
if ( V_221 )
F_164 ( L_7 ,
& V_221 -> V_224 ) ;
if ( V_219 )
F_164 ( L_8 ,
& V_219 -> V_224 , V_219 -> V_235 ) ;
}
if ( V_102 > 1 ) {
++ V_50 -> V_75 -> V_223 . V_236 ;
++ V_50 -> V_75 -> V_223 . V_237 ;
goto V_225;
}
}
V_223 = F_165 ( V_50 -> V_75 -> V_238 ) ;
F_166 ( & V_223 -> V_239 ) ;
V_223 -> V_240 ++ ;
V_223 -> V_241 += V_25 -> V_242 ;
F_167 ( & V_223 -> V_239 ) ;
F_168 ( & V_50 -> V_243 , V_25 ) ;
return;
V_225:
if ( V_217 )
F_169 ( (struct V_230 * ) V_217 ) ;
F_54 ( V_25 ) ;
}
static int F_170 ( struct V_46 * V_47 , struct V_24 * V_25 )
{
struct V_216 * V_217 = NULL ;
struct V_1 * V_2 ;
struct V_120 * V_244 ;
T_1 V_3 , V_118 ;
struct V_214 V_245 ;
struct V_214 * V_215 = & V_245 ;
if ( ! F_149 ( V_25 , V_246 ) )
goto error;
V_244 = (struct V_120 * ) ( F_150 ( V_25 ) + 1 ) ;
V_3 = F_11 ( V_244 -> V_148 ) ;
V_118 = F_11 ( V_244 -> V_151 ) ;
if ( V_3 & V_247 ) {
V_3 &= ~ V_247 ;
} else {
goto V_248;
}
if ( F_171 ( V_25 , V_246 , F_172 ( V_249 ) ) )
goto V_225;
V_244 = (struct V_120 * ) ( F_150 ( V_25 ) + 1 ) ;
V_2 = F_173 ( V_47 ) ;
if ( ! V_2 )
goto V_225;
if ( ( V_3 & V_149 ) && ( V_2 -> V_3 & V_150 ) ) {
V_244 = F_148 ( V_25 , V_244 , sizeof( struct V_120 ) , V_118 ,
! ! ( V_2 -> V_3 & V_152 ) ) ;
if ( ! V_244 )
goto V_225;
V_3 &= ~ V_149 ;
V_118 &= V_250 ;
}
if ( F_1 ( V_2 ) ) {
V_217 = F_174 ( V_25 , F_31 ( V_2 ) , V_251 ,
F_175 ( V_118 >> 8 ) , sizeof( * V_215 ) ) ;
if ( ! V_217 )
goto V_225;
V_215 = F_176 ( & V_217 -> V_252 . V_253 ) ;
} else {
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
}
if ( ( V_3 & V_254 ) && ( V_2 -> V_3 & V_255 ) ) {
struct V_256 * V_233 ;
V_233 = (struct V_256 * ) V_244 ;
V_215 -> V_233 = F_23 ( V_233 -> V_257 ) ;
if ( V_217 )
V_217 -> V_252 . V_253 . V_258 . V_259 |= V_260 ;
if ( V_233 -> V_261 )
V_215 -> V_233 |= V_262 ;
if ( V_233 -> V_263 )
V_215 -> V_233 |= V_264 ;
V_3 &= ~ V_265 ;
}
if ( V_3 || V_118 & ~ V_250 ) {
goto V_248;
}
F_152 ( V_2 , V_25 , V_215 , V_118 >> 8 , V_217 ) ;
return 0 ;
V_225:
F_54 ( V_25 ) ;
return 0 ;
V_248:
F_104 ( V_25 -> V_75 , L_9 ,
F_11 ( V_244 -> V_148 ) , F_11 ( V_244 -> V_151 ) ) ;
error:
if ( V_217 )
F_169 ( (struct V_230 * ) V_217 ) ;
return 1 ;
}
static int F_177 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_266 * V_267 ;
T_5 * V_268 , * V_269 ;
V_21 V_270 , V_271 ;
struct V_272 * V_273 ;
if ( V_75 -> V_3 & V_274 )
goto V_147;
if ( ! F_149 ( V_25 , F_178 ( V_75 ) ) ) {
V_75 -> V_223 . V_275 ++ ;
goto V_147;
}
V_267 = F_179 ( V_25 ) ;
if ( ( V_267 -> V_276 != F_172 ( V_277 ) &&
V_267 -> V_276 != F_172 ( V_278 ) ) ||
V_267 -> V_279 != F_172 ( V_280 ) ||
V_267 -> V_281 != F_172 ( V_282 ) ||
V_267 -> V_283 != V_75 -> V_284 ||
V_267 -> V_285 != 4 )
goto V_147;
V_268 = ( T_5 * ) V_267 + sizeof( struct V_266 ) ;
V_269 = V_268 ;
V_268 += V_75 -> V_284 ;
memcpy ( & V_270 , V_268 , sizeof( V_270 ) ) ;
V_268 += sizeof( V_270 ) ;
V_268 += V_75 -> V_284 ;
memcpy ( & V_271 , V_268 , sizeof( V_271 ) ) ;
if ( F_180 ( V_271 ) ||
F_181 ( V_271 ) )
goto V_147;
V_273 = F_182 ( & V_286 , & V_271 , V_75 ) ;
if ( V_273 ) {
struct V_39 * V_108 ;
struct V_24 * V_287 ;
if ( ! ( V_273 -> V_288 & V_289 ) ) {
F_183 ( V_273 ) ;
goto V_147;
}
V_108 = F_67 ( V_50 , V_273 -> V_290 ) ;
if ( V_108 && F_5 ( & ( F_24 ( V_108 ) -> V_69 ) ) ) {
F_183 ( V_273 ) ;
goto V_147;
}
V_287 = F_184 ( V_291 , V_292 , V_270 , V_75 , V_271 , V_269 ,
V_273 -> V_290 , V_269 ) ;
F_183 ( V_273 ) ;
if ( V_287 == NULL )
goto V_147;
F_153 ( V_287 ) ;
F_185 ( V_287 , F_186 ( V_287 ) ) ;
V_287 -> V_293 = V_294 ;
V_287 -> V_295 = V_296 ;
if ( F_187 ( V_287 ) == V_297 )
V_75 -> V_223 . V_298 ++ ;
} else if ( V_50 -> V_3 & V_299 ) {
union V_5 V_15 = {
. sin . V_13 . V_14 = V_271 ,
. sin . V_300 = V_22 ,
} ;
F_57 ( V_75 , & V_15 ) ;
}
V_147:
F_188 ( V_25 ) ;
return V_301 ;
}
static struct V_24 * F_189 ( struct V_24 * V_302 ,
struct V_272 * V_273 , bool V_303 )
{
struct V_107 * V_75 = V_302 -> V_75 ;
struct V_24 * V_287 ;
struct V_304 * V_305 , * V_306 ;
struct V_220 * V_307 ;
T_5 * V_308 ;
int V_309 = 8 ;
int V_310 ;
int V_311 , V_242 ;
if ( V_75 == NULL )
return NULL ;
V_242 = F_190 ( V_75 ) + sizeof( struct V_220 ) +
sizeof( * V_306 ) + V_309 + V_75 -> V_312 ;
V_287 = F_191 ( V_242 , V_104 ) ;
if ( V_287 == NULL )
return NULL ;
V_287 -> V_226 = F_172 ( V_313 ) ;
V_287 -> V_75 = V_75 ;
F_192 ( V_287 , F_190 ( V_302 -> V_75 ) ) ;
F_193 ( V_287 , sizeof( struct V_314 ) ) ;
F_194 ( V_287 , 0 ) ;
V_305 = (struct V_304 * ) F_195 ( V_302 ) ;
V_308 = F_157 ( V_302 ) -> V_228 ;
V_310 = V_302 -> V_242 - F_196 ( V_302 ) - sizeof( * V_305 ) ;
for ( V_311 = 0 ; V_311 < V_310 - 1 ; V_311 += ( V_305 -> V_315 [ V_311 + 1 ] << 3 ) ) {
if ( V_305 -> V_315 [ V_311 ] == V_316 ) {
V_308 = V_305 -> V_315 + V_311 + sizeof( struct V_317 ) ;
break;
}
}
F_197 ( F_157 ( V_287 ) -> V_318 , V_308 ) ;
F_197 ( F_157 ( V_287 ) -> V_228 , V_273 -> V_290 ) ;
F_157 ( V_287 ) -> V_319 = F_172 ( V_313 ) ;
V_287 -> V_226 = F_172 ( V_313 ) ;
F_198 ( V_287 , sizeof( struct V_314 ) ) ;
F_199 ( V_287 , 0 ) ;
F_200 ( V_287 , sizeof( struct V_220 ) ) ;
V_307 = F_159 ( V_287 ) ;
memset ( V_307 , 0 , sizeof( struct V_220 ) ) ;
V_307 -> V_320 = 6 ;
V_307 -> V_321 = F_159 ( V_302 ) -> V_321 ;
V_307 -> V_322 = V_323 ;
V_307 -> V_324 = 255 ;
V_307 -> V_308 = F_159 ( V_302 ) -> V_224 ;
V_307 -> V_224 = * (struct V_20 * ) V_273 -> V_325 ;
F_198 ( V_287 , sizeof( struct V_220 ) ) ;
F_201 ( V_287 , 0 ) ;
V_306 = (struct V_304 * ) F_200 ( V_287 , sizeof( * V_306 ) + V_309 ) ;
memset ( V_306 , 0 , sizeof( * V_306 ) + V_309 ) ;
V_306 -> V_326 . V_327 = V_328 ;
V_306 -> V_326 . V_329 = V_303 ;
V_306 -> V_326 . V_330 = 1 ;
V_306 -> V_326 . V_331 = 1 ;
V_306 -> V_332 = V_305 -> V_332 ;
F_197 ( & V_306 -> V_315 [ 2 ] , V_273 -> V_290 ) ;
V_306 -> V_315 [ 0 ] = V_333 ;
V_306 -> V_315 [ 1 ] = V_309 >> 3 ;
V_306 -> V_326 . V_334 = F_202 ( & V_307 -> V_224 ,
& V_307 -> V_308 , sizeof( * V_306 ) + V_309 , V_323 ,
F_203 ( V_306 , sizeof( * V_306 ) + V_309 , 0 ) ) ;
V_307 -> V_335 = F_172 ( sizeof( * V_306 ) + V_309 ) ;
F_193 ( V_287 , sizeof( struct V_220 ) ) ;
V_287 -> V_293 = V_294 ;
return V_287 ;
}
static int F_204 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_304 * V_336 ;
const struct V_220 * V_218 ;
const struct V_20 * V_224 , * V_308 ;
struct V_272 * V_273 ;
struct V_337 * V_338 ;
V_338 = F_205 ( V_75 ) ;
if ( ! V_338 )
goto V_147;
V_218 = F_159 ( V_25 ) ;
V_224 = & V_218 -> V_224 ;
V_308 = & V_218 -> V_308 ;
V_336 = (struct V_304 * ) F_195 ( V_25 ) ;
if ( V_336 -> V_326 . V_339 != 0 ||
V_336 -> V_326 . V_327 != V_340 )
goto V_147;
if ( F_206 ( V_308 ) ||
F_9 ( & V_336 -> V_332 ) )
goto V_147;
V_273 = F_182 ( V_210 -> V_341 , & V_336 -> V_332 , V_75 ) ;
if ( V_273 ) {
struct V_39 * V_108 ;
struct V_24 * V_287 ;
if ( ! ( V_273 -> V_288 & V_289 ) ) {
F_183 ( V_273 ) ;
goto V_147;
}
V_108 = F_67 ( V_50 , V_273 -> V_290 ) ;
if ( V_108 && F_5 ( & ( F_24 ( V_108 ) -> V_69 ) ) ) {
F_183 ( V_273 ) ;
goto V_147;
}
V_287 = F_189 ( V_25 , V_273 ,
! ! ( V_108 ? V_108 -> V_3 & V_342 : 0 ) ) ;
F_183 ( V_273 ) ;
if ( V_287 == NULL )
goto V_147;
if ( F_187 ( V_287 ) == V_297 )
V_75 -> V_223 . V_298 ++ ;
} else if ( V_50 -> V_3 & V_299 ) {
union V_5 V_15 = {
. V_11 . V_12 = V_336 -> V_332 ,
. V_11 . V_343 = V_10 ,
} ;
F_57 ( V_75 , & V_15 ) ;
}
V_147:
F_188 ( V_25 ) ;
return V_301 ;
}
static bool F_207 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_272 * V_273 ;
if ( F_105 ( F_157 ( V_25 ) -> V_318 ) )
return false ;
V_273 = NULL ;
switch ( F_23 ( F_157 ( V_25 ) -> V_319 ) ) {
case V_280 :
{
struct V_218 * V_344 ;
if ( ! F_149 ( V_25 , sizeof( struct V_218 ) ) )
return false ;
V_344 = F_158 ( V_25 ) ;
V_273 = F_182 ( & V_286 , & V_344 -> V_308 , V_75 ) ;
if ( ! V_273 && ( V_50 -> V_3 & V_299 ) ) {
union V_5 V_15 = {
. sin . V_13 . V_14 = V_344 -> V_308 ,
. sin . V_300 = V_22 ,
} ;
F_57 ( V_75 , & V_15 ) ;
return false ;
}
break;
}
#if F_115 ( V_178 )
case V_313 :
{
struct V_220 * V_307 ;
if ( ! F_149 ( V_25 , sizeof( struct V_220 ) ) )
return false ;
V_307 = F_159 ( V_25 ) ;
V_273 = F_182 ( V_210 -> V_341 , & V_307 -> V_308 , V_75 ) ;
if ( ! V_273 && ( V_50 -> V_3 & V_299 ) ) {
union V_5 V_15 = {
. V_11 . V_12 = V_307 -> V_308 ,
. V_11 . V_343 = V_10 ,
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
if ( V_273 ) {
bool V_345 ;
V_345 = ! F_66 ( F_157 ( V_25 ) -> V_318 , V_273 -> V_290 ) ;
if ( V_345 ) {
memcpy ( F_157 ( V_25 ) -> V_228 , F_157 ( V_25 ) -> V_318 ,
V_75 -> V_284 ) ;
memcpy ( F_157 ( V_25 ) -> V_318 , V_273 -> V_290 , V_75 -> V_284 ) ;
}
F_183 ( V_273 ) ;
return V_345 ;
}
return false ;
}
static void F_208 ( struct V_120 * V_244 , T_1 V_346 ,
struct V_214 * V_215 )
{
struct V_256 * V_233 ;
if ( ! V_215 -> V_233 )
return;
V_233 = (struct V_256 * ) V_244 ;
V_244 -> V_148 |= F_7 ( V_254 ) ;
if ( V_215 -> V_233 & V_262 )
V_233 -> V_261 = 1 ;
if ( V_215 -> V_233 & V_264 )
V_233 -> V_263 = 1 ;
V_233 -> V_257 = F_172 ( V_215 -> V_233 & V_347 ) ;
}
static int F_209 ( struct V_230 * V_348 , struct V_46 * V_47 ,
struct V_24 * V_25 ,
struct V_107 * V_75 , struct V_20 * V_224 ,
struct V_20 * V_308 , T_8 V_349 , T_8 V_350 ,
T_2 V_351 , T_2 V_87 , V_21 V_118 ,
struct V_214 * V_215 , bool V_352 , T_1 V_346 )
{
struct V_120 * V_244 ;
int V_353 ;
int V_102 ;
bool V_354 = ! ( V_346 & V_355 ) ;
int type = V_354 ? V_356 : V_357 ;
T_9 V_123 = sizeof( struct V_120 ) ;
if ( ( V_346 & V_358 ) &&
V_25 -> V_293 == V_359 ) {
int V_360 = F_210 ( V_25 ) ;
if ( V_360 <= V_361 &&
! ( V_360 & V_362 ) &&
( V_25 -> V_363 == F_77 ( struct V_135 , V_136 ) ||
V_25 -> V_363 == F_77 ( struct V_137 , V_136 ) ) ) {
V_354 = false ;
type |= V_364 ;
}
}
F_154 ( V_25 , V_352 ) ;
V_353 = F_190 ( V_348 -> V_75 ) + V_348 -> V_365
+ V_246 + sizeof( struct V_220 )
+ ( F_211 ( V_25 ) ? V_366 : 0 ) ;
V_102 = F_212 ( V_25 , V_353 ) ;
if ( F_86 ( V_102 ) ) {
F_54 ( V_25 ) ;
goto V_102;
}
V_25 = F_213 ( V_25 ) ;
if ( F_53 ( ! V_25 ) ) {
V_102 = - V_170 ;
goto V_102;
}
V_25 = F_214 ( V_25 , V_354 , type ) ;
if ( F_215 ( V_25 ) ) {
V_102 = - V_180 ;
goto V_102;
}
V_244 = (struct V_120 * ) F_216 ( V_25 , sizeof( * V_244 ) ) ;
V_244 -> V_148 = F_7 ( V_247 ) ;
V_244 -> V_151 = V_118 ;
if ( type & V_364 ) {
T_1 V_124 = ( F_210 ( V_25 ) - V_123 ) >>
V_133 ;
if ( V_25 -> V_363 == F_77 ( struct V_135 , V_136 ) )
V_124 |= V_134 ;
V_244 -> V_151 |= F_7 ( V_124 ) ;
V_244 -> V_148 |= F_7 ( V_149 ) ;
if ( ! F_217 ( V_25 ) ) {
V_25 -> V_293 = V_367 ;
V_25 -> V_368 = 0 ;
}
}
if ( V_346 & V_255 )
F_208 ( V_244 , V_346 , V_215 ) ;
F_218 ( V_25 , F_172 ( V_249 ) ) ;
F_219 ( V_348 , V_47 , V_25 , V_75 , V_224 , V_308 , V_349 ,
V_350 , V_351 , V_87 ,
! ! ( V_346 & V_355 ) ) ;
return 0 ;
V_102:
F_169 ( V_348 ) ;
return V_102 ;
}
static int F_220 ( struct V_369 * V_370 , struct V_46 * V_47 , struct V_24 * V_25 ,
V_21 V_371 , V_21 V_348 , T_8 V_235 , T_8 V_350 , T_2 V_372 ,
T_2 V_351 , T_2 V_87 , V_21 V_118 ,
struct V_214 * V_215 , bool V_352 , T_1 V_346 )
{
struct V_120 * V_244 ;
int V_353 ;
int V_102 ;
bool V_354 = ! ! ( V_346 & V_373 ) ;
int type = V_354 ? V_356 : V_357 ;
T_9 V_123 = sizeof( struct V_120 ) ;
if ( ( V_346 & V_358 ) &&
V_25 -> V_293 == V_359 ) {
int V_360 = F_210 ( V_25 ) ;
if ( V_360 <= V_361 &&
! ( V_360 & V_362 ) &&
( V_25 -> V_363 == F_77 ( struct V_135 , V_136 ) ||
V_25 -> V_363 == F_77 ( struct V_137 , V_136 ) ) ) {
V_354 = false ;
type |= V_364 ;
}
}
V_353 = F_190 ( V_370 -> V_348 . V_75 ) + V_370 -> V_348 . V_365
+ V_246 + sizeof( struct V_218 )
+ ( F_211 ( V_25 ) ? V_366 : 0 ) ;
V_102 = F_212 ( V_25 , V_353 ) ;
if ( F_86 ( V_102 ) ) {
F_54 ( V_25 ) ;
return V_102 ;
}
V_25 = F_213 ( V_25 ) ;
if ( F_53 ( ! V_25 ) )
return - V_170 ;
V_25 = F_214 ( V_25 , V_354 , type ) ;
if ( F_215 ( V_25 ) )
return F_221 ( V_25 ) ;
V_244 = (struct V_120 * ) F_216 ( V_25 , sizeof( * V_244 ) ) ;
V_244 -> V_148 = F_7 ( V_247 ) ;
V_244 -> V_151 = V_118 ;
if ( type & V_364 ) {
T_1 V_124 = ( F_210 ( V_25 ) - V_123 ) >>
V_133 ;
if ( V_25 -> V_363 == F_77 ( struct V_135 , V_136 ) )
V_124 |= V_134 ;
V_244 -> V_151 |= F_7 ( V_124 ) ;
V_244 -> V_148 |= F_7 ( V_149 ) ;
if ( ! F_217 ( V_25 ) ) {
V_25 -> V_293 = V_367 ;
V_25 -> V_368 = 0 ;
}
}
if ( V_346 & V_255 )
F_208 ( V_244 , V_346 , V_215 ) ;
F_218 ( V_25 , F_172 ( V_249 ) ) ;
return F_222 ( V_370 , V_47 , V_25 , V_371 , V_348 , V_235 ,
V_350 , V_372 , V_351 , V_87 , V_352 ,
! ( V_346 & V_373 ) ) ;
}
static void F_223 ( struct V_24 * V_25 , struct V_49 * V_374 ,
struct V_49 * V_375 )
{
struct V_222 * V_376 , * V_377 ;
union V_5 V_378 ;
union V_5 * V_69 = & V_375 -> V_51 . V_69 ;
struct V_107 * V_75 = V_25 -> V_75 ;
int V_242 = V_25 -> V_242 ;
V_376 = F_165 ( V_374 -> V_75 -> V_238 ) ;
V_377 = F_165 ( V_375 -> V_75 -> V_238 ) ;
V_25 -> V_295 = V_296 ;
V_25 -> V_368 = 0 ;
V_25 -> V_75 = V_375 -> V_75 ;
F_185 ( V_25 , F_186 ( V_25 ) ) ;
if ( V_69 -> V_8 . V_9 == V_22 ) {
V_378 . sin . V_13 . V_14 = F_7 ( V_379 ) ;
V_378 . V_8 . V_9 = V_22 ;
#if F_115 ( V_178 )
} else {
V_378 . V_11 . V_12 = V_380 ;
V_378 . V_8 . V_9 = V_10 ;
#endif
}
if ( V_375 -> V_3 & V_231 )
F_130 ( V_25 -> V_75 , & V_378 , F_157 ( V_25 ) -> V_228 ) ;
F_166 ( & V_376 -> V_239 ) ;
V_376 -> V_381 ++ ;
V_376 -> V_382 += V_242 ;
F_167 ( & V_376 -> V_239 ) ;
if ( F_224 ( V_25 ) == V_383 ) {
F_166 ( & V_377 -> V_239 ) ;
V_377 -> V_240 ++ ;
V_377 -> V_241 += V_242 ;
F_167 ( & V_377 -> V_239 ) ;
} else {
V_75 -> V_223 . V_298 ++ ;
}
}
static void F_225 ( struct V_24 * V_25 , struct V_107 * V_75 ,
struct V_38 * V_55 , bool V_384 )
{
struct V_385 * V_386 ;
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_46 * V_47 = V_50 -> V_200 -> V_46 -> V_47 ;
unsigned short V_44 = F_31 ( V_50 -> V_200 ) ;
struct V_369 * V_370 = NULL ;
const struct V_218 * V_387 ;
struct V_388 V_389 ;
union V_5 * V_348 ;
union V_5 V_69 ;
struct V_214 V_245 ;
struct V_214 * V_215 = & V_245 ;
T_2 V_351 = 0 , V_87 ;
T_1 V_118 ;
T_2 V_372 = 0 ;
T_8 V_235 , V_350 ;
int V_102 ;
T_1 V_3 = V_50 -> V_3 ;
V_386 = F_226 ( V_25 ) ;
if ( V_55 ) {
V_87 = V_55 -> V_85 ? V_55 -> V_85 : V_50 -> V_86 . V_87 ;
V_118 = V_55 -> V_52 ;
V_348 = & V_55 -> V_69 ;
} else {
if ( ! V_386 ) {
F_227 ( 1 , L_10 ,
V_75 -> V_390 ) ;
goto V_225;
}
if ( V_44 != F_228 ( V_386 ) )
goto V_225;
V_87 = V_386 -> V_258 . V_391 ? : V_50 -> V_86 . V_87 ;
V_118 = F_229 ( V_386 -> V_258 . V_392 ) ;
V_69 . V_8 . V_9 = V_44 ;
if ( V_44 == V_22 )
V_69 . sin . V_13 . V_14 = V_386 -> V_258 . V_252 . V_393 . V_348 ;
else
V_69 . V_11 . V_12 = V_386 -> V_258 . V_252 . V_394 . V_348 ;
V_348 = & V_69 ;
}
if ( F_5 ( V_348 ) ) {
if ( V_384 ) {
F_223 ( V_25 , V_50 , V_50 ) ;
return;
}
goto V_225;
}
V_387 = F_158 ( V_25 ) ;
V_350 = V_50 -> V_86 . V_350 ;
if ( ! V_350 && F_8 ( V_348 ) )
V_350 = 1 ;
V_235 = V_50 -> V_86 . V_235 ;
if ( V_235 == 1 )
V_235 = F_230 ( V_387 , V_25 ) ;
V_351 = F_231 ( F_39 ( V_75 ) , V_25 , V_50 -> V_86 . V_395 ,
V_50 -> V_86 . V_396 , true ) ;
if ( V_386 ) {
if ( V_386 -> V_258 . V_259 & V_397 )
V_3 |= V_373 ;
else
V_3 &= ~ V_373 ;
V_350 = V_386 -> V_258 . V_350 ;
V_235 = V_386 -> V_258 . V_235 ;
if ( V_386 -> V_398 )
V_215 = F_176 ( V_386 ) ;
} else {
V_215 -> V_233 = V_25 -> V_232 ;
}
if ( V_348 -> V_8 . V_9 == V_22 ) {
if ( V_386 && ( V_386 -> V_258 . V_259 & V_399 ) )
V_372 = F_172 ( V_400 ) ;
memset ( & V_389 , 0 , sizeof( V_389 ) ) ;
V_389 . V_401 = V_55 ? V_55 -> V_90 : 0 ;
V_389 . V_402 = F_232 ( V_235 ) ;
V_389 . V_403 = V_25 -> V_232 ;
V_389 . V_404 = V_405 ;
V_389 . V_308 = V_348 -> sin . V_13 . V_14 ;
V_389 . V_224 = V_50 -> V_86 . V_224 . sin . V_13 . V_14 ;
V_370 = F_233 ( V_50 -> V_31 , & V_389 ) ;
if ( F_215 ( V_370 ) ) {
F_104 ( V_75 , L_11 ,
& V_348 -> sin . V_13 . V_14 ) ;
V_75 -> V_223 . V_406 ++ ;
goto V_407;
}
if ( V_370 -> V_348 . V_75 == V_75 ) {
F_104 ( V_75 , L_12 ,
& V_348 -> sin . V_13 . V_14 ) ;
V_75 -> V_223 . V_408 ++ ;
goto V_409;
}
if ( V_370 -> V_410 & V_411 &&
! ( V_370 -> V_410 & ( V_412 | V_413 ) ) ) {
struct V_49 * V_375 ;
F_234 ( V_370 ) ;
V_375 = F_33 ( V_50 -> V_31 , V_118 ,
V_348 -> V_8 . V_9 , V_87 ,
V_50 -> V_3 ) ;
if ( ! V_375 )
goto V_407;
F_223 ( V_25 , V_50 , V_375 ) ;
return;
}
V_235 = F_235 ( V_235 , V_387 , V_25 ) ;
V_350 = V_350 ? : F_236 ( & V_370 -> V_348 ) ;
V_102 = F_220 ( V_370 , V_47 , V_25 , V_389 . V_224 ,
V_348 -> sin . V_13 . V_14 , V_235 , V_350 , V_372 ,
V_351 , V_87 , F_7 ( V_118 << 8 ) , V_215 ,
! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ,
V_3 ) ;
if ( V_102 < 0 ) {
V_25 = NULL ;
goto V_409;
}
F_237 ( V_102 , & V_75 -> V_223 , V_75 -> V_238 ) ;
#if F_115 ( V_178 )
} else {
struct V_230 * V_414 ;
struct V_415 V_416 ;
T_1 V_417 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
V_416 . V_418 = V_55 ? V_55 -> V_90 : 0 ;
V_416 . V_308 = V_348 -> V_11 . V_12 ;
V_416 . V_224 = V_50 -> V_86 . V_224 . V_11 . V_12 ;
V_416 . V_419 = V_25 -> V_232 ;
V_416 . V_420 = V_405 ;
if ( V_210 -> V_421 ( V_50 -> V_31 , V_47 , & V_414 , & V_416 ) ) {
F_104 ( V_75 , L_13 ,
& V_348 -> V_11 . V_12 ) ;
V_75 -> V_223 . V_406 ++ ;
goto V_407;
}
if ( V_414 -> V_75 == V_75 ) {
F_104 ( V_75 , L_14 ,
& V_348 -> V_11 . V_12 ) ;
F_169 ( V_414 ) ;
V_75 -> V_223 . V_408 ++ ;
goto V_407;
}
V_417 = ( (struct V_422 * ) V_414 ) -> V_417 ;
if ( V_417 & V_423 &&
! ( V_417 & ( V_412 | V_413 ) ) ) {
struct V_49 * V_375 ;
F_169 ( V_414 ) ;
V_375 = F_33 ( V_50 -> V_31 , V_118 ,
V_348 -> V_8 . V_9 , V_87 ,
V_50 -> V_3 ) ;
if ( ! V_375 )
goto V_407;
F_223 ( V_25 , V_50 , V_375 ) ;
return;
}
V_350 = V_350 ? : F_238 ( V_414 ) ;
V_102 = F_209 ( V_414 , V_47 , V_25 , V_75 , & V_416 . V_224 , & V_416 . V_308 ,
0 , V_350 , V_351 , V_87 , F_7 ( V_118 << 8 ) , V_215 ,
! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ,
V_3 ) ;
#endif
}
return;
V_225:
V_75 -> V_223 . V_275 ++ ;
goto V_424;
V_409:
F_234 ( V_370 ) ;
V_407:
V_75 -> V_223 . V_425 ++ ;
V_424:
F_239 ( V_25 ) ;
}
static T_10 F_240 ( struct V_24 * V_25 , struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
const struct V_385 * V_386 ;
struct V_314 * V_426 ;
bool V_384 = false ;
struct V_38 * V_55 , * V_427 = NULL ;
struct V_39 * V_108 ;
V_386 = F_226 ( V_25 ) ;
F_153 ( V_25 ) ;
V_426 = F_157 ( V_25 ) ;
if ( ( V_50 -> V_3 & V_428 ) ) {
if ( F_23 ( V_426 -> V_319 ) == V_292 )
return F_177 ( V_75 , V_25 ) ;
#if F_115 ( V_178 )
else if ( F_23 ( V_426 -> V_319 ) == V_313 &&
F_149 ( V_25 , sizeof( struct V_220 )
+ sizeof( struct V_304 ) ) &&
F_159 ( V_25 ) -> V_322 == V_323 ) {
struct V_304 * V_336 ;
V_336 = (struct V_304 * ) F_195 ( V_25 ) ;
if ( V_336 -> V_326 . V_339 == 0 &&
V_336 -> V_326 . V_327 == V_340 )
return F_204 ( V_75 , V_25 ) ;
}
V_426 = F_157 ( V_25 ) ;
#endif
}
if ( V_50 -> V_3 & V_4 &&
V_386 && V_386 -> V_429 & V_430 ) {
F_225 ( V_25 , V_75 , NULL , false ) ;
return V_301 ;
}
V_108 = F_67 ( V_50 , V_426 -> V_318 ) ;
V_384 = false ;
if ( V_108 && ( V_108 -> V_3 & V_342 ) && ( V_50 -> V_3 & V_431 ) &&
( F_23 ( V_426 -> V_319 ) == V_280 ||
F_23 ( V_426 -> V_319 ) == V_313 ) ) {
V_384 = F_207 ( V_75 , V_25 ) ;
if ( V_384 )
V_108 = F_67 ( V_50 , V_426 -> V_318 ) ;
}
if ( V_108 == NULL ) {
V_108 = F_67 ( V_50 , V_432 ) ;
if ( V_108 == NULL ) {
if ( ( V_50 -> V_3 & V_433 ) &&
! F_105 ( V_426 -> V_318 ) )
F_59 ( V_50 , V_426 -> V_318 ) ;
V_75 -> V_223 . V_275 ++ ;
F_54 ( V_25 ) ;
return V_301 ;
}
}
F_128 (rdst, &f->remotes, list) {
struct V_24 * V_434 ;
if ( ! V_427 ) {
V_427 = V_55 ;
continue;
}
V_434 = F_241 ( V_25 , V_104 ) ;
if ( V_434 )
F_225 ( V_434 , V_75 , V_55 , V_384 ) ;
}
if ( V_427 )
F_225 ( V_25 , V_75 , V_427 , V_384 ) ;
else
F_54 ( V_25 ) ;
return V_301 ;
}
static void F_242 ( unsigned long V_435 )
{
struct V_49 * V_50 = (struct V_49 * ) V_435 ;
unsigned long V_436 = V_57 + V_437 ;
unsigned int V_191 ;
if ( ! F_135 ( V_50 -> V_75 ) )
return;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 ) {
struct V_438 * V_140 , * V_273 ;
F_121 ( & V_50 -> V_186 ) ;
F_243 (p, n, &vxlan->fdb_head[h]) {
struct V_39 * V_108
= F_80 ( V_140 , struct V_39 , V_171 ) ;
unsigned long V_439 ;
if ( V_108 -> V_73 & V_184 )
continue;
V_439 = V_108 -> V_93 + V_50 -> V_86 . V_440 * V_441 ;
if ( F_244 ( V_439 , V_57 ) ) {
F_104 ( V_50 -> V_75 ,
L_15 ,
V_108 -> V_70 ) ;
V_108 -> V_73 = V_109 ;
F_111 ( V_50 , V_108 ) ;
} else if ( F_245 ( V_439 , V_436 ) )
V_436 = V_439 ;
}
F_122 ( & V_50 -> V_186 ) ;
}
F_246 ( & V_50 -> V_442 , V_436 ) ;
}
static void F_247 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
V_99 V_118 = V_50 -> V_51 . V_52 ;
V_50 -> V_200 = V_2 ;
F_134 ( & V_34 -> V_202 ) ;
F_107 ( & V_50 -> V_171 , F_19 ( V_2 , V_118 ) ) ;
F_136 ( & V_34 -> V_202 ) ;
}
static int F_248 ( struct V_107 * V_75 )
{
V_75 -> V_238 = F_249 ( struct V_222 ) ;
if ( ! V_75 -> V_238 )
return - V_170 ;
return 0 ;
}
static void F_250 ( struct V_49 * V_50 )
{
struct V_39 * V_108 ;
F_121 ( & V_50 -> V_186 ) ;
V_108 = F_65 ( V_50 , V_432 ) ;
if ( V_108 )
F_111 ( V_50 , V_108 ) ;
F_122 ( & V_50 -> V_186 ) ;
}
static void F_251 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
F_250 ( V_50 ) ;
F_252 ( V_75 -> V_238 ) ;
}
static int F_253 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_1 * V_2 ;
int V_205 = 0 ;
V_2 = F_254 ( V_50 -> V_31 , V_50 -> V_86 . V_87 ,
V_50 -> V_86 . V_443 , V_50 -> V_3 ) ;
if ( F_215 ( V_2 ) )
return F_221 ( V_2 ) ;
F_247 ( V_2 , V_50 ) ;
if ( F_8 ( & V_50 -> V_51 . V_69 ) ) {
V_205 = F_142 ( V_50 ) ;
if ( V_205 == - V_444 )
V_205 = 0 ;
if ( V_205 ) {
F_139 ( V_2 ) ;
return V_205 ;
}
}
if ( V_50 -> V_86 . V_440 )
F_246 ( & V_50 -> V_442 , V_57 + V_437 ) ;
return V_205 ;
}
static void F_255 ( struct V_49 * V_50 )
{
unsigned int V_191 ;
F_121 ( & V_50 -> V_186 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 ) {
struct V_438 * V_140 , * V_273 ;
F_243 (p, n, &vxlan->fdb_head[h]) {
struct V_39 * V_108
= F_80 ( V_140 , struct V_39 , V_171 ) ;
if ( ! F_37 ( V_108 -> V_70 ) )
F_111 ( V_50 , V_108 ) ;
}
}
F_122 ( & V_50 -> V_186 ) ;
}
static int F_256 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
struct V_1 * V_2 = V_50 -> V_200 ;
int V_205 = 0 ;
if ( F_8 ( & V_50 -> V_51 . V_69 ) &&
! F_137 ( V_34 , V_50 ) )
V_205 = F_146 ( V_50 ) ;
F_257 ( & V_50 -> V_442 ) ;
F_255 ( V_50 ) ;
F_139 ( V_2 ) ;
return V_205 ;
}
static void F_258 ( struct V_107 * V_75 )
{
}
static int F_259 ( struct V_107 * V_75 , int V_445 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_38 * V_348 = & V_50 -> V_51 ;
struct V_107 * V_446 ;
int V_447 ;
V_446 = F_118 ( V_50 -> V_31 , V_348 -> V_90 ) ;
if ( V_446 == NULL )
return F_260 ( V_75 , V_445 ) ;
if ( V_348 -> V_69 . V_8 . V_9 == V_10 )
V_447 = V_446 -> V_448 - V_449 ;
else
V_447 = V_446 -> V_448 - V_450 ;
if ( V_445 < 68 || V_445 > V_447 )
return - V_180 ;
V_75 -> V_448 = V_445 ;
return 0 ;
}
static int F_261 ( struct V_107 * V_75 , struct V_24 * V_25 ,
struct V_385 * V_386 ,
T_2 V_451 , T_2 V_452 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_369 * V_370 ;
struct V_388 V_389 ;
memset ( & V_389 , 0 , sizeof( V_389 ) ) ;
V_389 . V_402 = F_232 ( V_386 -> V_258 . V_235 ) ;
V_389 . V_403 = V_25 -> V_232 ;
V_389 . V_404 = V_405 ;
V_389 . V_308 = V_386 -> V_258 . V_252 . V_393 . V_348 ;
V_370 = F_233 ( V_50 -> V_31 , & V_389 ) ;
if ( F_215 ( V_370 ) )
return F_221 ( V_370 ) ;
F_234 ( V_370 ) ;
V_386 -> V_258 . V_252 . V_393 . V_371 = V_389 . V_224 ;
V_386 -> V_258 . V_453 = V_451 ;
V_386 -> V_258 . V_391 = V_452 ;
return 0 ;
}
static int F_262 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_385 * V_386 = F_226 ( V_25 ) ;
T_2 V_451 , V_452 ;
V_451 = F_231 ( F_39 ( V_75 ) , V_25 , V_50 -> V_86 . V_395 ,
V_50 -> V_86 . V_396 , true ) ;
V_452 = V_386 -> V_258 . V_391 ? : V_50 -> V_86 . V_87 ;
if ( F_228 ( V_386 ) == V_22 )
return F_261 ( V_75 , V_25 , V_386 , V_451 , V_452 ) ;
return - V_180 ;
}
void F_263 ( struct V_107 * V_75 )
{
struct V_1 * V_2 ;
struct V_31 * V_31 = F_39 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
T_3 V_9 ;
T_2 V_32 ;
unsigned int V_311 ;
F_134 ( & V_34 -> V_202 ) ;
for ( V_311 = 0 ; V_311 < V_454 ; ++ V_311 ) {
F_29 (vs, &vn->sock_list[i], hlist) {
V_32 = F_30 ( V_2 -> V_46 -> V_47 ) -> V_48 ;
V_9 = F_31 ( V_2 ) ;
V_75 -> V_155 -> V_156 ( V_75 , V_9 ,
V_32 ) ;
}
}
F_136 ( & V_34 -> V_202 ) ;
}
static void F_264 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
unsigned int V_191 ;
F_265 ( V_75 ) ;
F_266 ( V_75 ) ;
V_75 -> V_155 = & V_455 ;
V_75 -> V_456 = V_457 ;
F_267 ( V_75 , & V_458 ) ;
V_75 -> V_459 |= V_460 ;
V_75 -> V_459 |= V_461 | V_462 ;
V_75 -> V_459 |= V_463 ;
V_75 -> V_459 |= V_464 ;
V_75 -> V_465 = V_75 -> V_459 ;
V_75 -> V_459 |= V_466 | V_467 ;
V_75 -> V_468 |= V_461 | V_462 | V_463 ;
V_75 -> V_468 |= V_464 ;
V_75 -> V_468 |= V_466 | V_467 ;
F_268 ( V_75 ) ;
V_75 -> V_469 |= V_470 | V_471 ;
F_106 ( & V_50 -> V_42 ) ;
F_269 ( & V_50 -> V_186 ) ;
F_270 ( & V_50 -> V_442 ) ;
V_50 -> V_442 . V_472 = F_242 ;
V_50 -> V_442 . V_124 = ( unsigned long ) V_50 ;
V_50 -> V_86 . V_87 = F_172 ( V_473 ) ;
V_50 -> V_75 = V_75 ;
F_271 ( & V_50 -> V_243 , V_75 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 )
F_272 ( & V_50 -> V_116 [ V_191 ] ) ;
}
static int F_273 ( struct V_18 * V_177 [] , struct V_18 * V_124 [] )
{
if ( V_177 [ V_474 ] ) {
if ( F_13 ( V_177 [ V_474 ] ) != V_83 ) {
F_274 ( L_16 ) ;
return - V_180 ;
}
if ( ! F_275 ( F_276 ( V_177 [ V_474 ] ) ) ) {
F_274 ( L_17 ) ;
return - V_182 ;
}
}
if ( ! V_124 )
return - V_180 ;
if ( V_124 [ V_475 ] ) {
V_99 V_28 = F_117 ( V_124 [ V_475 ] ) ;
if ( V_28 >= V_476 )
return - V_477 ;
}
if ( V_124 [ V_478 ] ) {
const struct V_479 * V_140
= F_276 ( V_124 [ V_478 ] ) ;
if ( F_23 ( V_140 -> V_480 ) < F_23 ( V_140 -> V_481 ) ) {
F_274 ( L_18 ,
F_23 ( V_140 -> V_481 ) , F_23 ( V_140 -> V_480 ) ) ;
return - V_180 ;
}
}
return 0 ;
}
static void F_277 ( struct V_107 * V_482 ,
struct V_483 * V_484 )
{
F_278 ( V_484 -> V_320 , V_485 , sizeof( V_484 -> V_320 ) ) ;
F_278 ( V_484 -> V_486 , L_19 , sizeof( V_484 -> V_486 ) ) ;
}
static void F_279 ( struct V_487 * V_488 )
{
struct V_1 * V_2 = F_80 ( V_488 , struct V_1 , V_204 ) ;
F_280 ( V_2 -> V_46 ) ;
F_126 ( V_2 , V_174 ) ;
}
static struct V_489 * F_281 ( struct V_31 * V_31 , bool V_394 ,
T_2 V_32 , T_1 V_3 )
{
struct V_489 * V_46 ;
struct V_490 V_491 ;
int V_102 ;
memset ( & V_491 , 0 , sizeof( V_491 ) ) ;
if ( V_394 ) {
V_491 . V_44 = V_10 ;
V_491 . V_492 =
! ( V_3 & V_493 ) ;
V_491 . V_494 = 1 ;
} else {
V_491 . V_44 = V_22 ;
}
V_491 . V_495 = V_32 ;
V_102 = F_282 ( V_31 , & V_491 , & V_46 ) ;
if ( V_102 < 0 )
return F_283 ( V_102 ) ;
return V_46 ;
}
static struct V_1 * F_284 ( struct V_31 * V_31 , T_2 V_32 ,
T_1 V_3 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
struct V_1 * V_2 ;
struct V_489 * V_46 ;
unsigned int V_191 ;
bool V_394 = ! ! ( V_3 & V_496 ) ;
struct V_497 V_498 ;
V_2 = F_285 ( sizeof( * V_2 ) , V_499 ) ;
if ( ! V_2 )
return F_283 ( - V_170 ) ;
for ( V_191 = 0 ; V_191 < V_500 ; ++ V_191 )
F_272 ( & V_2 -> V_29 [ V_191 ] ) ;
F_286 ( & V_2 -> V_204 , F_279 ) ;
V_46 = F_281 ( V_31 , V_394 , V_32 , V_3 ) ;
if ( F_215 ( V_46 ) ) {
F_120 ( L_20 , F_23 ( V_32 ) ,
F_221 ( V_46 ) ) ;
F_110 ( V_2 ) ;
return F_287 ( V_46 ) ;
}
V_2 -> V_46 = V_46 ;
F_288 ( & V_2 -> V_201 , 1 ) ;
V_2 -> V_3 = ( V_3 & V_45 ) ;
V_2 -> V_146 . V_32 = V_32 ;
V_2 -> V_146 . V_501 . V_502 = F_79 ;
V_2 -> V_146 . V_501 . V_503 = F_91 ;
F_134 ( & V_34 -> V_202 ) ;
F_107 ( & V_2 -> V_171 , F_21 ( V_31 , V_32 ) ) ;
F_94 ( V_2 ) ;
F_136 ( & V_34 -> V_202 ) ;
V_498 . V_504 = V_2 ;
V_498 . V_505 = 1 ;
V_498 . V_506 = F_170 ;
V_498 . V_507 = NULL ;
F_289 ( V_31 , V_46 , & V_498 ) ;
return V_2 ;
}
static struct V_1 * F_254 ( struct V_31 * V_31 , T_2 V_32 ,
bool V_443 , T_1 V_3 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
struct V_1 * V_2 ;
bool V_394 = V_3 & V_496 ;
if ( ! V_443 ) {
F_134 ( & V_34 -> V_202 ) ;
V_2 = F_28 ( V_31 , V_394 ? V_10 : V_22 , V_32 ,
V_3 ) ;
if ( V_2 ) {
if ( ! F_290 ( & V_2 -> V_201 , 1 , 0 ) )
V_2 = F_283 ( - V_508 ) ;
F_136 ( & V_34 -> V_202 ) ;
return V_2 ;
}
F_136 ( & V_34 -> V_202 ) ;
}
return F_284 ( V_31 , V_32 , V_3 ) ;
}
static int F_291 ( struct V_31 * V_509 , struct V_107 * V_75 ,
struct V_510 * V_511 )
{
struct V_33 * V_34 = F_22 ( V_509 , V_35 ) ;
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_38 * V_348 = & V_50 -> V_51 ;
int V_102 ;
bool V_512 = false ;
T_2 V_513 = V_50 -> V_86 . V_87 ;
V_50 -> V_31 = V_509 ;
V_348 -> V_52 = V_511 -> V_118 ;
memcpy ( & V_348 -> V_69 , & V_511 -> V_69 , sizeof( V_511 -> V_69 ) ) ;
if ( ! V_348 -> V_69 . V_8 . V_9 )
V_348 -> V_69 . V_8 . V_9 = V_22 ;
if ( V_348 -> V_69 . V_8 . V_9 == V_10 ||
V_50 -> V_86 . V_224 . V_8 . V_9 == V_10 ) {
if ( ! F_115 ( V_178 ) )
return - V_514 ;
V_512 = true ;
}
if ( V_511 -> V_90 ) {
struct V_107 * V_446
= F_118 ( V_509 , V_511 -> V_90 ) ;
V_348 -> V_90 = V_511 -> V_90 ;
if ( ! V_446 ) {
F_120 ( L_21 , V_348 -> V_90 ) ;
return - V_515 ;
}
#if F_115 ( V_178 )
if ( V_512 ) {
struct V_337 * V_516 = F_205 ( V_446 ) ;
if ( V_516 && V_516 -> V_517 . V_518 ) {
F_120 ( L_22 ) ;
return - V_519 ;
}
V_50 -> V_3 |= V_496 ;
}
#endif
if ( ! V_511 -> V_448 )
V_75 -> V_448 = V_446 -> V_448 - ( V_512 ? V_449 : V_450 ) ;
V_75 -> V_520 = V_446 -> V_521 +
( V_512 ? V_449 : V_450 ) ;
} else if ( V_512 ) {
V_50 -> V_3 |= V_496 ;
V_75 -> V_520 = V_227 + V_449 ;
} else {
V_75 -> V_520 = V_227 + V_450 ;
}
memcpy ( & V_50 -> V_86 , V_511 , sizeof( * V_511 ) ) ;
if ( ! V_50 -> V_86 . V_87 )
V_50 -> V_86 . V_87 = V_513 ;
V_50 -> V_3 |= V_511 -> V_3 ;
if ( ! V_50 -> V_86 . V_440 )
V_50 -> V_86 . V_440 = V_522 ;
if ( F_33 ( V_509 , V_511 -> V_118 , V_512 ? V_10 : V_22 ,
V_50 -> V_86 . V_87 , V_50 -> V_3 ) )
return - V_160 ;
V_75 -> V_523 = & V_524 ;
if ( ! F_5 ( & V_50 -> V_51 . V_69 ) ) {
V_102 = F_103 ( V_50 , V_432 ,
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
V_102 = F_292 ( V_75 ) ;
if ( V_102 ) {
F_250 ( V_50 ) ;
return V_102 ;
}
F_293 ( & V_50 -> V_42 , & V_34 -> V_525 ) ;
return 0 ;
}
struct V_107 * F_294 ( struct V_31 * V_31 , const char * V_390 ,
T_5 V_526 , struct V_510 * V_511 )
{
struct V_18 * V_177 [ V_527 + 1 ] ;
struct V_107 * V_75 ;
int V_102 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_75 = F_295 ( V_31 , V_390 , V_526 ,
& V_528 , V_177 ) ;
if ( F_215 ( V_75 ) )
return V_75 ;
V_102 = F_291 ( V_31 , V_75 , V_511 ) ;
if ( V_102 < 0 ) {
V_457 ( V_75 ) ;
return F_283 ( V_102 ) ;
}
return V_75 ;
}
static int F_296 ( struct V_31 * V_509 , struct V_107 * V_75 ,
struct V_18 * V_177 [] , struct V_18 * V_124 [] )
{
struct V_510 V_511 ;
int V_102 ;
memset ( & V_511 , 0 , sizeof( V_511 ) ) ;
if ( V_124 [ V_475 ] )
V_511 . V_118 = F_117 ( V_124 [ V_475 ] ) ;
if ( V_124 [ V_529 ] ) {
V_511 . V_69 . sin . V_13 . V_14 = F_15 ( V_124 [ V_529 ] ) ;
} else if ( V_124 [ V_530 ] ) {
if ( ! F_115 ( V_178 ) )
return - V_514 ;
V_511 . V_69 . V_11 . V_12 = F_14 ( V_124 [ V_530 ] ) ;
V_511 . V_69 . V_8 . V_9 = V_10 ;
}
if ( V_124 [ V_531 ] ) {
V_511 . V_224 . sin . V_13 . V_14 = F_15 ( V_124 [ V_531 ] ) ;
V_511 . V_224 . V_8 . V_9 = V_22 ;
} else if ( V_124 [ V_532 ] ) {
if ( ! F_115 ( V_178 ) )
return - V_514 ;
V_511 . V_224 . V_11 . V_12 = F_14 ( V_124 [ V_532 ] ) ;
V_511 . V_224 . V_8 . V_9 = V_10 ;
}
if ( V_124 [ V_533 ] )
V_511 . V_90 = F_117 ( V_124 [ V_533 ] ) ;
if ( V_124 [ V_534 ] )
V_511 . V_235 = F_297 ( V_124 [ V_534 ] ) ;
if ( V_124 [ V_535 ] )
V_511 . V_350 = F_297 ( V_124 [ V_535 ] ) ;
if ( ! V_124 [ V_536 ] || F_297 ( V_124 [ V_536 ] ) )
V_511 . V_3 |= V_231 ;
if ( V_124 [ V_537 ] )
V_511 . V_440 = F_117 ( V_124 [ V_537 ] ) ;
if ( V_124 [ V_538 ] && F_297 ( V_124 [ V_538 ] ) )
V_511 . V_3 |= V_428 ;
if ( V_124 [ V_539 ] && F_297 ( V_124 [ V_539 ] ) )
V_511 . V_3 |= V_431 ;
if ( V_124 [ V_540 ] && F_297 ( V_124 [ V_540 ] ) )
V_511 . V_3 |= V_433 ;
if ( V_124 [ V_541 ] && F_297 ( V_124 [ V_541 ] ) )
V_511 . V_3 |= V_299 ;
if ( V_124 [ V_542 ] )
V_511 . V_167 = F_117 ( V_124 [ V_542 ] ) ;
if ( V_124 [ V_543 ] &&
F_297 ( V_124 [ V_543 ] ) )
V_511 . V_3 |= V_4 ;
if ( V_124 [ V_478 ] ) {
const struct V_479 * V_140
= F_276 ( V_124 [ V_478 ] ) ;
V_511 . V_395 = F_23 ( V_140 -> V_481 ) ;
V_511 . V_396 = F_23 ( V_140 -> V_480 ) ;
}
if ( V_124 [ V_544 ] )
V_511 . V_87 = F_116 ( V_124 [ V_544 ] ) ;
if ( V_124 [ V_545 ] && F_297 ( V_124 [ V_545 ] ) )
V_511 . V_3 |= V_373 ;
if ( V_124 [ V_546 ] &&
F_297 ( V_124 [ V_546 ] ) )
V_511 . V_3 |= V_355 ;
if ( V_124 [ V_547 ] &&
F_297 ( V_124 [ V_547 ] ) )
V_511 . V_3 |= V_493 ;
if ( V_124 [ V_548 ] &&
F_297 ( V_124 [ V_548 ] ) )
V_511 . V_3 |= V_358 ;
if ( V_124 [ V_549 ] &&
F_297 ( V_124 [ V_549 ] ) )
V_511 . V_3 |= V_150 ;
if ( V_124 [ V_550 ] )
V_511 . V_3 |= V_255 ;
if ( V_124 [ V_551 ] )
V_511 . V_3 |= V_152 ;
V_102 = F_291 ( V_509 , V_75 , & V_511 ) ;
switch ( V_102 ) {
case - V_515 :
F_120 ( L_21 , V_511 . V_90 ) ;
break;
case - V_519 :
F_120 ( L_22 ) ;
break;
case - V_160 :
F_120 ( L_23 , V_511 . V_118 ) ;
break;
}
return V_102 ;
}
static void F_298 ( struct V_107 * V_75 , struct V_552 * V_117 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
F_134 ( & V_34 -> V_202 ) ;
if ( ! F_299 ( & V_50 -> V_171 ) )
F_112 ( & V_50 -> V_171 ) ;
F_136 ( & V_34 -> V_202 ) ;
F_300 ( & V_50 -> V_243 ) ;
F_301 ( & V_50 -> V_42 ) ;
F_302 ( V_75 , V_117 ) ;
}
static T_4 F_303 ( const struct V_107 * V_75 )
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
F_50 ( sizeof( struct V_479 ) ) +
F_50 ( sizeof( T_2 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
0 ;
}
static int F_304 ( struct V_24 * V_25 , const struct V_107 * V_75 )
{
const struct V_49 * V_50 = F_58 ( V_75 ) ;
const struct V_38 * V_348 = & V_50 -> V_51 ;
struct V_479 V_553 = {
. V_481 = F_172 ( V_50 -> V_86 . V_395 ) ,
. V_480 = F_172 ( V_50 -> V_86 . V_396 ) ,
} ;
if ( F_44 ( V_25 , V_475 , V_348 -> V_52 ) )
goto V_81;
if ( ! F_5 ( & V_348 -> V_69 ) ) {
if ( V_348 -> V_69 . V_8 . V_9 == V_22 ) {
if ( F_18 ( V_25 , V_529 ,
V_348 -> V_69 . sin . V_13 . V_14 ) )
goto V_81;
#if F_115 ( V_178 )
} else {
if ( F_17 ( V_25 , V_530 ,
& V_348 -> V_69 . V_11 . V_12 ) )
goto V_81;
#endif
}
}
if ( V_348 -> V_90 && F_44 ( V_25 , V_533 , V_348 -> V_90 ) )
goto V_81;
if ( ! F_5 ( & V_50 -> V_86 . V_224 ) ) {
if ( V_50 -> V_86 . V_224 . V_8 . V_9 == V_22 ) {
if ( F_18 ( V_25 , V_531 ,
V_50 -> V_86 . V_224 . sin . V_13 . V_14 ) )
goto V_81;
#if F_115 ( V_178 )
} else {
if ( F_17 ( V_25 , V_532 ,
& V_50 -> V_86 . V_224 . V_11 . V_12 ) )
goto V_81;
#endif
}
}
if ( F_305 ( V_25 , V_535 , V_50 -> V_86 . V_350 ) ||
F_305 ( V_25 , V_534 , V_50 -> V_86 . V_235 ) ||
F_305 ( V_25 , V_536 ,
! ! ( V_50 -> V_3 & V_231 ) ) ||
F_305 ( V_25 , V_538 ,
! ! ( V_50 -> V_3 & V_428 ) ) ||
F_305 ( V_25 , V_539 , ! ! ( V_50 -> V_3 & V_431 ) ) ||
F_305 ( V_25 , V_540 ,
! ! ( V_50 -> V_3 & V_433 ) ) ||
F_305 ( V_25 , V_541 ,
! ! ( V_50 -> V_3 & V_299 ) ) ||
F_305 ( V_25 , V_543 ,
! ! ( V_50 -> V_3 & V_4 ) ) ||
F_44 ( V_25 , V_537 , V_50 -> V_86 . V_440 ) ||
F_44 ( V_25 , V_542 , V_50 -> V_86 . V_167 ) ||
F_43 ( V_25 , V_544 , V_50 -> V_86 . V_87 ) ||
F_305 ( V_25 , V_545 ,
! ! ( V_50 -> V_3 & V_373 ) ) ||
F_305 ( V_25 , V_546 ,
! ! ( V_50 -> V_3 & V_355 ) ) ||
F_305 ( V_25 , V_547 ,
! ! ( V_50 -> V_3 & V_493 ) ) ||
F_305 ( V_25 , V_548 ,
! ! ( V_50 -> V_3 & V_358 ) ) ||
F_305 ( V_25 , V_549 ,
! ! ( V_50 -> V_3 & V_150 ) ) )
goto V_81;
if ( F_42 ( V_25 , V_478 , sizeof( V_553 ) , & V_553 ) )
goto V_81;
if ( V_50 -> V_3 & V_255 &&
F_306 ( V_25 , V_550 ) )
goto V_81;
if ( V_50 -> V_3 & V_152 &&
F_306 ( V_25 , V_551 ) )
goto V_81;
return 0 ;
V_81:
return - V_66 ;
}
static struct V_31 * F_307 ( const struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
return V_50 -> V_31 ;
}
static void F_308 ( struct V_33 * V_34 ,
struct V_107 * V_75 )
{
struct V_49 * V_50 , * V_42 ;
F_309 ( V_554 ) ;
F_109 (vxlan, next, &vn->vxlan_list, next) {
struct V_38 * V_348 = & V_50 -> V_51 ;
if ( V_348 -> V_90 == V_75 -> V_76 )
F_298 ( V_50 -> V_75 , & V_554 ) ;
}
F_310 ( & V_554 ) ;
}
static int F_311 ( struct V_555 * V_556 ,
unsigned long V_557 , void * V_558 )
{
struct V_107 * V_75 = F_312 ( V_558 ) ;
struct V_33 * V_34 = F_22 ( F_39 ( V_75 ) , V_35 ) ;
if ( V_557 == V_559 )
F_308 ( V_34 , V_75 ) ;
return V_560 ;
}
static T_11 int F_313 ( struct V_31 * V_31 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
unsigned int V_191 ;
F_106 ( & V_34 -> V_525 ) ;
F_269 ( & V_34 -> V_202 ) ;
for ( V_191 = 0 ; V_191 < V_454 ; ++ V_191 )
F_272 ( & V_34 -> V_36 [ V_191 ] ) ;
return 0 ;
}
static void T_12 F_314 ( struct V_31 * V_31 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
struct V_49 * V_50 , * V_42 ;
struct V_107 * V_75 , * V_561 ;
F_309 ( V_43 ) ;
F_315 () ;
F_316 (net, dev, aux)
if ( V_75 -> V_562 == & V_528 )
F_302 ( V_75 , & V_43 ) ;
F_109 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_38 ( F_39 ( V_50 -> V_75 ) , V_31 ) ) {
F_300 ( & V_50 -> V_243 ) ;
F_302 ( V_50 -> V_75 , & V_43 ) ;
}
}
F_310 ( & V_43 ) ;
F_317 () ;
}
static int T_13 F_318 ( void )
{
int V_164 ;
V_203 = F_319 ( L_19 , 0 , 0 ) ;
if ( ! V_203 )
return - V_170 ;
F_320 ( & V_563 , sizeof( V_563 ) ) ;
V_164 = F_321 ( & V_564 ) ;
if ( V_164 )
goto V_565;
V_164 = F_322 ( & V_566 ) ;
if ( V_164 )
goto V_567;
V_164 = F_323 ( & V_528 ) ;
if ( V_164 )
goto V_568;
return 0 ;
V_568:
F_324 ( & V_566 ) ;
V_567:
F_325 ( & V_564 ) ;
V_565:
F_326 ( V_203 ) ;
return V_164 ;
}
static void T_14 F_327 ( void )
{
F_328 ( & V_528 ) ;
F_324 ( & V_566 ) ;
F_326 ( V_203 ) ;
F_325 ( & V_564 ) ;
}
