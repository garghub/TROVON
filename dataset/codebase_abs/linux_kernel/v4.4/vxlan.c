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
if ( V_218 )
V_218 -> V_253 . V_254 . V_259 . V_260 |= V_261 ;
if ( V_234 -> V_262 )
V_216 -> V_234 |= V_263 ;
if ( V_234 -> V_264 )
V_216 -> V_234 |= V_265 ;
V_3 &= ~ V_266 ;
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
struct V_267 * V_268 ;
T_5 * V_269 , * V_270 ;
V_21 V_271 , V_272 ;
struct V_273 * V_274 ;
if ( V_75 -> V_3 & V_275 )
goto V_147;
if ( ! F_150 ( V_25 , F_179 ( V_75 ) ) ) {
V_75 -> V_224 . V_276 ++ ;
goto V_147;
}
V_268 = F_180 ( V_25 ) ;
if ( ( V_268 -> V_277 != F_173 ( V_278 ) &&
V_268 -> V_277 != F_173 ( V_279 ) ) ||
V_268 -> V_280 != F_173 ( V_281 ) ||
V_268 -> V_282 != F_173 ( V_283 ) ||
V_268 -> V_284 != V_75 -> V_285 ||
V_268 -> V_286 != 4 )
goto V_147;
V_269 = ( T_5 * ) V_268 + sizeof( struct V_267 ) ;
V_270 = V_269 ;
V_269 += V_75 -> V_285 ;
memcpy ( & V_271 , V_269 , sizeof( V_271 ) ) ;
V_269 += sizeof( V_271 ) ;
V_269 += V_75 -> V_285 ;
memcpy ( & V_272 , V_269 , sizeof( V_272 ) ) ;
if ( F_181 ( V_272 ) ||
F_182 ( V_272 ) )
goto V_147;
V_274 = F_183 ( & V_287 , & V_272 , V_75 ) ;
if ( V_274 ) {
struct V_39 * V_108 ;
struct V_24 * V_288 ;
if ( ! ( V_274 -> V_289 & V_290 ) ) {
F_184 ( V_274 ) ;
goto V_147;
}
V_108 = F_67 ( V_50 , V_274 -> V_291 ) ;
if ( V_108 && F_5 ( & ( F_24 ( V_108 ) -> V_69 ) ) ) {
F_184 ( V_274 ) ;
goto V_147;
}
V_288 = F_185 ( V_292 , V_293 , V_271 , V_75 , V_272 , V_270 ,
V_274 -> V_291 , V_270 ) ;
F_184 ( V_274 ) ;
if ( V_288 == NULL )
goto V_147;
F_154 ( V_288 ) ;
F_186 ( V_288 , F_187 ( V_288 ) ) ;
V_288 -> V_294 = V_295 ;
V_288 -> V_296 = V_297 ;
if ( F_188 ( V_288 ) == V_298 )
V_75 -> V_224 . V_299 ++ ;
} else if ( V_50 -> V_3 & V_300 ) {
union V_5 V_15 = {
. sin . V_13 . V_14 = V_272 ,
. sin . V_301 = V_22 ,
} ;
F_57 ( V_75 , & V_15 ) ;
}
V_147:
F_189 ( V_25 ) ;
return V_302 ;
}
static struct V_24 * F_190 ( struct V_24 * V_303 ,
struct V_273 * V_274 , bool V_304 )
{
struct V_107 * V_75 = V_303 -> V_75 ;
struct V_24 * V_288 ;
struct V_305 * V_306 , * V_307 ;
struct V_221 * V_308 ;
T_5 * V_309 ;
int V_310 = 8 ;
int V_311 ;
int V_312 , V_243 ;
if ( V_75 == NULL )
return NULL ;
V_243 = F_191 ( V_75 ) + sizeof( struct V_221 ) +
sizeof( * V_307 ) + V_310 + V_75 -> V_313 ;
V_288 = F_192 ( V_243 , V_104 ) ;
if ( V_288 == NULL )
return NULL ;
V_288 -> V_227 = F_173 ( V_314 ) ;
V_288 -> V_75 = V_75 ;
F_193 ( V_288 , F_191 ( V_303 -> V_75 ) ) ;
F_194 ( V_288 , sizeof( struct V_315 ) ) ;
F_195 ( V_288 , 0 ) ;
V_306 = (struct V_305 * ) F_196 ( V_303 ) ;
V_309 = F_158 ( V_303 ) -> V_229 ;
V_311 = V_303 -> V_243 - F_197 ( V_303 ) - sizeof( * V_306 ) ;
for ( V_312 = 0 ; V_312 < V_311 - 1 ; V_312 += ( V_306 -> V_316 [ V_312 + 1 ] << 3 ) ) {
if ( V_306 -> V_316 [ V_312 ] == V_317 ) {
V_309 = V_306 -> V_316 + V_312 + sizeof( struct V_318 ) ;
break;
}
}
F_198 ( F_158 ( V_288 ) -> V_319 , V_309 ) ;
F_198 ( F_158 ( V_288 ) -> V_229 , V_274 -> V_291 ) ;
F_158 ( V_288 ) -> V_320 = F_173 ( V_314 ) ;
V_288 -> V_227 = F_173 ( V_314 ) ;
F_199 ( V_288 , sizeof( struct V_315 ) ) ;
F_200 ( V_288 , 0 ) ;
F_201 ( V_288 , sizeof( struct V_221 ) ) ;
V_308 = F_160 ( V_288 ) ;
memset ( V_308 , 0 , sizeof( struct V_221 ) ) ;
V_308 -> V_321 = 6 ;
V_308 -> V_322 = F_160 ( V_303 ) -> V_322 ;
V_308 -> V_323 = V_324 ;
V_308 -> V_325 = 255 ;
V_308 -> V_309 = F_160 ( V_303 ) -> V_225 ;
V_308 -> V_225 = * (struct V_20 * ) V_274 -> V_326 ;
F_199 ( V_288 , sizeof( struct V_221 ) ) ;
F_202 ( V_288 , 0 ) ;
V_307 = (struct V_305 * ) F_201 ( V_288 , sizeof( * V_307 ) + V_310 ) ;
memset ( V_307 , 0 , sizeof( * V_307 ) + V_310 ) ;
V_307 -> V_327 . V_328 = V_329 ;
V_307 -> V_327 . V_330 = V_304 ;
V_307 -> V_327 . V_331 = 1 ;
V_307 -> V_327 . V_332 = 1 ;
V_307 -> V_333 = V_306 -> V_333 ;
F_198 ( & V_307 -> V_316 [ 2 ] , V_274 -> V_291 ) ;
V_307 -> V_316 [ 0 ] = V_334 ;
V_307 -> V_316 [ 1 ] = V_310 >> 3 ;
V_307 -> V_327 . V_335 = F_203 ( & V_308 -> V_225 ,
& V_308 -> V_309 , sizeof( * V_307 ) + V_310 , V_324 ,
F_204 ( V_307 , sizeof( * V_307 ) + V_310 , 0 ) ) ;
V_308 -> V_336 = F_173 ( sizeof( * V_307 ) + V_310 ) ;
F_194 ( V_288 , sizeof( struct V_221 ) ) ;
V_288 -> V_294 = V_295 ;
return V_288 ;
}
static int F_205 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_305 * V_337 ;
const struct V_221 * V_219 ;
const struct V_20 * V_225 , * V_309 ;
struct V_273 * V_274 ;
struct V_338 * V_339 ;
V_339 = F_206 ( V_75 ) ;
if ( ! V_339 )
goto V_147;
V_219 = F_160 ( V_25 ) ;
V_225 = & V_219 -> V_225 ;
V_309 = & V_219 -> V_309 ;
V_337 = (struct V_305 * ) F_196 ( V_25 ) ;
if ( V_337 -> V_327 . V_340 != 0 ||
V_337 -> V_327 . V_328 != V_341 )
goto V_147;
if ( F_207 ( V_309 ) ||
F_9 ( & V_337 -> V_333 ) )
goto V_147;
V_274 = F_183 ( V_211 -> V_342 , & V_337 -> V_333 , V_75 ) ;
if ( V_274 ) {
struct V_39 * V_108 ;
struct V_24 * V_288 ;
if ( ! ( V_274 -> V_289 & V_290 ) ) {
F_184 ( V_274 ) ;
goto V_147;
}
V_108 = F_67 ( V_50 , V_274 -> V_291 ) ;
if ( V_108 && F_5 ( & ( F_24 ( V_108 ) -> V_69 ) ) ) {
F_184 ( V_274 ) ;
goto V_147;
}
V_288 = F_190 ( V_25 , V_274 ,
! ! ( V_108 ? V_108 -> V_3 & V_343 : 0 ) ) ;
F_184 ( V_274 ) ;
if ( V_288 == NULL )
goto V_147;
if ( F_188 ( V_288 ) == V_298 )
V_75 -> V_224 . V_299 ++ ;
} else if ( V_50 -> V_3 & V_300 ) {
union V_5 V_15 = {
. V_11 . V_12 = V_337 -> V_333 ,
. V_11 . V_344 = V_10 ,
} ;
F_57 ( V_75 , & V_15 ) ;
}
V_147:
F_189 ( V_25 ) ;
return V_302 ;
}
static bool F_208 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_273 * V_274 ;
if ( F_105 ( F_158 ( V_25 ) -> V_319 ) )
return false ;
V_274 = NULL ;
switch ( F_23 ( F_158 ( V_25 ) -> V_320 ) ) {
case V_281 :
{
struct V_219 * V_345 ;
if ( ! F_150 ( V_25 , sizeof( struct V_219 ) ) )
return false ;
V_345 = F_159 ( V_25 ) ;
V_274 = F_183 ( & V_287 , & V_345 -> V_309 , V_75 ) ;
if ( ! V_274 && ( V_50 -> V_3 & V_300 ) ) {
union V_5 V_15 = {
. sin . V_13 . V_14 = V_345 -> V_309 ,
. sin . V_301 = V_22 ,
} ;
F_57 ( V_75 , & V_15 ) ;
return false ;
}
break;
}
#if F_115 ( V_178 )
case V_314 :
{
struct V_221 * V_308 ;
if ( ! F_150 ( V_25 , sizeof( struct V_221 ) ) )
return false ;
V_308 = F_160 ( V_25 ) ;
V_274 = F_183 ( V_211 -> V_342 , & V_308 -> V_309 , V_75 ) ;
if ( ! V_274 && ( V_50 -> V_3 & V_300 ) ) {
union V_5 V_15 = {
. V_11 . V_12 = V_308 -> V_309 ,
. V_11 . V_344 = V_10 ,
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
if ( V_274 ) {
bool V_346 ;
V_346 = ! F_66 ( F_158 ( V_25 ) -> V_319 , V_274 -> V_291 ) ;
if ( V_346 ) {
memcpy ( F_158 ( V_25 ) -> V_229 , F_158 ( V_25 ) -> V_319 ,
V_75 -> V_285 ) ;
memcpy ( F_158 ( V_25 ) -> V_319 , V_274 -> V_291 , V_75 -> V_285 ) ;
}
F_184 ( V_274 ) ;
return V_346 ;
}
return false ;
}
static void F_209 ( struct V_120 * V_245 , T_1 V_347 ,
struct V_215 * V_216 )
{
struct V_257 * V_234 ;
if ( ! V_216 -> V_234 )
return;
V_234 = (struct V_257 * ) V_245 ;
V_245 -> V_148 |= F_7 ( V_255 ) ;
if ( V_216 -> V_234 & V_263 )
V_234 -> V_262 = 1 ;
if ( V_216 -> V_234 & V_265 )
V_234 -> V_264 = 1 ;
V_234 -> V_258 = F_173 ( V_216 -> V_234 & V_348 ) ;
}
static int F_210 ( struct V_231 * V_349 , struct V_46 * V_47 ,
struct V_24 * V_25 ,
struct V_107 * V_75 , struct V_20 * V_225 ,
struct V_20 * V_309 , T_8 V_350 , T_8 V_351 ,
T_2 V_352 , T_2 V_87 , V_21 V_118 ,
struct V_215 * V_216 , bool V_353 , T_1 V_347 )
{
struct V_120 * V_245 ;
int V_354 ;
int V_102 ;
bool V_355 = ! ( V_347 & V_356 ) ;
int type = V_355 ? V_357 : V_358 ;
T_9 V_123 = sizeof( struct V_120 ) ;
if ( ( V_347 & V_359 ) &&
V_25 -> V_294 == V_360 ) {
int V_361 = F_211 ( V_25 ) ;
if ( V_361 <= V_362 &&
! ( V_361 & V_363 ) &&
( V_25 -> V_364 == F_77 ( struct V_135 , V_136 ) ||
V_25 -> V_364 == F_77 ( struct V_137 , V_136 ) ) ) {
V_355 = false ;
type |= V_365 ;
}
}
F_155 ( V_25 , V_353 ) ;
V_354 = F_191 ( V_349 -> V_75 ) + V_349 -> V_366
+ V_247 + sizeof( struct V_221 )
+ ( F_212 ( V_25 ) ? V_367 : 0 ) ;
V_102 = F_213 ( V_25 , V_354 ) ;
if ( F_86 ( V_102 ) ) {
F_54 ( V_25 ) ;
goto V_102;
}
V_25 = F_214 ( V_25 ) ;
if ( F_53 ( ! V_25 ) ) {
V_102 = - V_170 ;
goto V_102;
}
V_25 = F_215 ( V_25 , V_355 , type ) ;
if ( F_216 ( V_25 ) ) {
V_102 = - V_180 ;
goto V_102;
}
V_245 = (struct V_120 * ) F_217 ( V_25 , sizeof( * V_245 ) ) ;
V_245 -> V_148 = F_7 ( V_248 ) ;
V_245 -> V_151 = V_118 ;
if ( type & V_365 ) {
T_1 V_124 = ( F_211 ( V_25 ) - V_123 ) >>
V_133 ;
if ( V_25 -> V_364 == F_77 ( struct V_135 , V_136 ) )
V_124 |= V_134 ;
V_245 -> V_151 |= F_7 ( V_124 ) ;
V_245 -> V_148 |= F_7 ( V_149 ) ;
if ( ! F_218 ( V_25 ) ) {
V_25 -> V_294 = V_368 ;
V_25 -> V_369 = 0 ;
}
}
if ( V_347 & V_256 )
F_209 ( V_245 , V_347 , V_216 ) ;
F_219 ( V_25 , F_173 ( V_250 ) ) ;
F_220 ( V_349 , V_47 , V_25 , V_75 , V_225 , V_309 , V_350 ,
V_351 , V_352 , V_87 ,
! ! ( V_347 & V_356 ) ) ;
return 0 ;
V_102:
F_170 ( V_349 ) ;
return V_102 ;
}
static int F_221 ( struct V_370 * V_371 , struct V_46 * V_47 , struct V_24 * V_25 ,
V_21 V_372 , V_21 V_349 , T_8 V_236 , T_8 V_351 , T_2 V_373 ,
T_2 V_352 , T_2 V_87 , V_21 V_118 ,
struct V_215 * V_216 , bool V_353 , T_1 V_347 )
{
struct V_120 * V_245 ;
int V_354 ;
int V_102 ;
bool V_355 = ! ! ( V_347 & V_374 ) ;
int type = V_355 ? V_357 : V_358 ;
T_9 V_123 = sizeof( struct V_120 ) ;
if ( ( V_347 & V_359 ) &&
V_25 -> V_294 == V_360 ) {
int V_361 = F_211 ( V_25 ) ;
if ( V_361 <= V_362 &&
! ( V_361 & V_363 ) &&
( V_25 -> V_364 == F_77 ( struct V_135 , V_136 ) ||
V_25 -> V_364 == F_77 ( struct V_137 , V_136 ) ) ) {
V_355 = false ;
type |= V_365 ;
}
}
V_354 = F_191 ( V_371 -> V_349 . V_75 ) + V_371 -> V_349 . V_366
+ V_247 + sizeof( struct V_219 )
+ ( F_212 ( V_25 ) ? V_367 : 0 ) ;
V_102 = F_213 ( V_25 , V_354 ) ;
if ( F_86 ( V_102 ) ) {
F_54 ( V_25 ) ;
return V_102 ;
}
V_25 = F_214 ( V_25 ) ;
if ( F_53 ( ! V_25 ) )
return - V_170 ;
V_25 = F_215 ( V_25 , V_355 , type ) ;
if ( F_216 ( V_25 ) )
return F_222 ( V_25 ) ;
V_245 = (struct V_120 * ) F_217 ( V_25 , sizeof( * V_245 ) ) ;
V_245 -> V_148 = F_7 ( V_248 ) ;
V_245 -> V_151 = V_118 ;
if ( type & V_365 ) {
T_1 V_124 = ( F_211 ( V_25 ) - V_123 ) >>
V_133 ;
if ( V_25 -> V_364 == F_77 ( struct V_135 , V_136 ) )
V_124 |= V_134 ;
V_245 -> V_151 |= F_7 ( V_124 ) ;
V_245 -> V_148 |= F_7 ( V_149 ) ;
if ( ! F_218 ( V_25 ) ) {
V_25 -> V_294 = V_368 ;
V_25 -> V_369 = 0 ;
}
}
if ( V_347 & V_256 )
F_209 ( V_245 , V_347 , V_216 ) ;
F_219 ( V_25 , F_173 ( V_250 ) ) ;
return F_223 ( V_371 , V_47 , V_25 , V_372 , V_349 , V_236 ,
V_351 , V_373 , V_352 , V_87 , V_353 ,
! ( V_347 & V_374 ) ) ;
}
static struct V_231 * F_224 ( struct V_49 * V_50 ,
struct V_24 * V_25 , int V_375 ,
const struct V_20 * V_309 ,
struct V_20 * V_225 )
{
struct V_231 * V_376 ;
struct V_377 V_378 ;
int V_102 ;
memset ( & V_378 , 0 , sizeof( V_378 ) ) ;
V_378 . V_379 = V_375 ;
V_378 . V_309 = * V_309 ;
V_378 . V_225 = V_50 -> V_86 . V_225 . V_11 . V_12 ;
V_378 . V_380 = V_25 -> V_233 ;
V_378 . V_381 = V_382 ;
V_102 = V_211 -> V_383 ( V_50 -> V_31 ,
V_50 -> V_202 -> V_46 -> V_47 ,
& V_376 , & V_378 ) ;
if ( V_102 < 0 )
return F_225 ( V_102 ) ;
* V_225 = V_378 . V_225 ;
return V_376 ;
}
static void F_226 ( struct V_24 * V_25 , struct V_49 * V_384 ,
struct V_49 * V_385 )
{
struct V_223 * V_386 , * V_387 ;
union V_5 V_388 ;
union V_5 * V_69 = & V_385 -> V_51 . V_69 ;
struct V_107 * V_75 = V_25 -> V_75 ;
int V_243 = V_25 -> V_243 ;
V_386 = F_166 ( V_384 -> V_75 -> V_239 ) ;
V_387 = F_166 ( V_385 -> V_75 -> V_239 ) ;
V_25 -> V_296 = V_297 ;
V_25 -> V_369 = 0 ;
V_25 -> V_75 = V_385 -> V_75 ;
F_186 ( V_25 , F_187 ( V_25 ) ) ;
if ( V_69 -> V_8 . V_9 == V_22 ) {
V_388 . sin . V_13 . V_14 = F_7 ( V_389 ) ;
V_388 . V_8 . V_9 = V_22 ;
#if F_115 ( V_178 )
} else {
V_388 . V_11 . V_12 = V_390 ;
V_388 . V_8 . V_9 = V_10 ;
#endif
}
if ( V_385 -> V_3 & V_232 )
F_130 ( V_25 -> V_75 , & V_388 , F_158 ( V_25 ) -> V_229 ) ;
F_167 ( & V_386 -> V_240 ) ;
V_386 -> V_391 ++ ;
V_386 -> V_392 += V_243 ;
F_168 ( & V_386 -> V_240 ) ;
if ( F_227 ( V_25 ) == V_393 ) {
F_167 ( & V_387 -> V_240 ) ;
V_387 -> V_241 ++ ;
V_387 -> V_242 += V_243 ;
F_168 ( & V_387 -> V_240 ) ;
} else {
V_75 -> V_224 . V_299 ++ ;
}
}
static void F_228 ( struct V_24 * V_25 , struct V_107 * V_75 ,
struct V_38 * V_55 , bool V_394 )
{
struct V_395 * V_396 ;
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_46 * V_47 ;
struct V_370 * V_371 = NULL ;
const struct V_219 * V_397 ;
struct V_398 V_399 ;
union V_5 * V_349 ;
union V_5 V_69 ;
struct V_215 V_246 ;
struct V_215 * V_216 = & V_246 ;
T_2 V_352 = 0 , V_87 ;
T_1 V_118 ;
T_2 V_373 = 0 ;
T_8 V_236 , V_351 ;
int V_102 ;
T_1 V_3 = V_50 -> V_3 ;
V_396 = F_229 ( V_25 ) ;
if ( V_55 ) {
V_87 = V_55 -> V_85 ? V_55 -> V_85 : V_50 -> V_86 . V_87 ;
V_118 = V_55 -> V_52 ;
V_349 = & V_55 -> V_69 ;
} else {
if ( ! V_396 ) {
F_230 ( 1 , L_10 ,
V_75 -> V_400 ) ;
goto V_226;
}
V_87 = V_396 -> V_259 . V_401 ? : V_50 -> V_86 . V_87 ;
V_118 = F_231 ( V_396 -> V_259 . V_402 ) ;
V_69 . V_8 . V_9 = F_232 ( V_396 ) ;
if ( V_69 . V_8 . V_9 == V_22 )
V_69 . sin . V_13 . V_14 = V_396 -> V_259 . V_253 . V_403 . V_349 ;
else
V_69 . V_11 . V_12 = V_396 -> V_259 . V_253 . V_404 . V_349 ;
V_349 = & V_69 ;
}
if ( F_5 ( V_349 ) ) {
if ( V_394 ) {
F_226 ( V_25 , V_50 , V_50 ) ;
return;
}
goto V_226;
}
V_397 = F_159 ( V_25 ) ;
V_351 = V_50 -> V_86 . V_351 ;
if ( ! V_351 && F_8 ( V_349 ) )
V_351 = 1 ;
V_236 = V_50 -> V_86 . V_236 ;
if ( V_236 == 1 )
V_236 = F_233 ( V_397 , V_25 ) ;
V_352 = F_234 ( F_39 ( V_75 ) , V_25 , V_50 -> V_86 . V_405 ,
V_50 -> V_86 . V_406 , true ) ;
if ( V_396 ) {
if ( V_396 -> V_259 . V_260 & V_407 )
V_3 |= V_374 ;
else
V_3 &= ~ V_374 ;
V_351 = V_396 -> V_259 . V_351 ;
V_236 = V_396 -> V_259 . V_236 ;
if ( V_396 -> V_408 )
V_216 = F_177 ( V_396 ) ;
} else {
V_216 -> V_234 = V_25 -> V_233 ;
}
if ( V_349 -> V_8 . V_9 == V_22 ) {
if ( ! V_50 -> V_200 )
goto V_226;
V_47 = V_50 -> V_200 -> V_46 -> V_47 ;
if ( V_396 && ( V_396 -> V_259 . V_260 & V_409 ) )
V_373 = F_173 ( V_410 ) ;
memset ( & V_399 , 0 , sizeof( V_399 ) ) ;
V_399 . V_411 = V_55 ? V_55 -> V_90 : 0 ;
V_399 . V_412 = F_235 ( V_236 ) ;
V_399 . V_413 = V_25 -> V_233 ;
V_399 . V_414 = V_382 ;
V_399 . V_309 = V_349 -> sin . V_13 . V_14 ;
V_399 . V_225 = V_50 -> V_86 . V_225 . sin . V_13 . V_14 ;
V_371 = F_236 ( V_50 -> V_31 , & V_399 ) ;
if ( F_216 ( V_371 ) ) {
F_104 ( V_75 , L_11 ,
& V_349 -> sin . V_13 . V_14 ) ;
V_75 -> V_224 . V_415 ++ ;
goto V_416;
}
if ( V_371 -> V_349 . V_75 == V_75 ) {
F_104 ( V_75 , L_12 ,
& V_349 -> sin . V_13 . V_14 ) ;
V_75 -> V_224 . V_417 ++ ;
goto V_418;
}
if ( V_371 -> V_419 & V_420 &&
! ( V_371 -> V_419 & ( V_421 | V_422 ) ) ) {
struct V_49 * V_385 ;
F_237 ( V_371 ) ;
V_385 = F_33 ( V_50 -> V_31 , V_118 ,
V_349 -> V_8 . V_9 , V_87 ,
V_50 -> V_3 ) ;
if ( ! V_385 )
goto V_416;
F_226 ( V_25 , V_50 , V_385 ) ;
return;
}
V_236 = F_238 ( V_236 , V_397 , V_25 ) ;
V_351 = V_351 ? : F_239 ( & V_371 -> V_349 ) ;
V_102 = F_221 ( V_371 , V_47 , V_25 , V_399 . V_225 ,
V_349 -> sin . V_13 . V_14 , V_236 , V_351 , V_373 ,
V_352 , V_87 , F_7 ( V_118 << 8 ) , V_216 ,
! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ,
V_3 ) ;
if ( V_102 < 0 ) {
V_25 = NULL ;
goto V_418;
}
F_240 ( V_102 , & V_75 -> V_224 , V_75 -> V_239 ) ;
#if F_115 ( V_178 )
} else {
struct V_231 * V_376 ;
struct V_20 V_225 ;
T_1 V_423 ;
if ( ! V_50 -> V_202 )
goto V_226;
V_47 = V_50 -> V_202 -> V_46 -> V_47 ;
V_376 = F_224 ( V_50 , V_25 ,
V_55 ? V_55 -> V_90 : 0 ,
& V_349 -> V_11 . V_12 , & V_225 ) ;
if ( F_216 ( V_376 ) ) {
F_104 ( V_75 , L_13 ,
& V_349 -> V_11 . V_12 ) ;
V_75 -> V_224 . V_415 ++ ;
goto V_416;
}
if ( V_376 -> V_75 == V_75 ) {
F_104 ( V_75 , L_14 ,
& V_349 -> V_11 . V_12 ) ;
F_170 ( V_376 ) ;
V_75 -> V_224 . V_417 ++ ;
goto V_416;
}
V_423 = ( (struct V_424 * ) V_376 ) -> V_423 ;
if ( V_423 & V_425 &&
! ( V_423 & ( V_421 | V_422 ) ) ) {
struct V_49 * V_385 ;
F_170 ( V_376 ) ;
V_385 = F_33 ( V_50 -> V_31 , V_118 ,
V_349 -> V_8 . V_9 , V_87 ,
V_50 -> V_3 ) ;
if ( ! V_385 )
goto V_416;
F_226 ( V_25 , V_50 , V_385 ) ;
return;
}
V_351 = V_351 ? : F_241 ( V_376 ) ;
V_102 = F_210 ( V_376 , V_47 , V_25 , V_75 , & V_225 , & V_349 -> V_11 . V_12 ,
0 , V_351 , V_352 , V_87 , F_7 ( V_118 << 8 ) , V_216 ,
! F_38 ( V_50 -> V_31 , F_39 ( V_50 -> V_75 ) ) ,
V_3 ) ;
#endif
}
return;
V_226:
V_75 -> V_224 . V_276 ++ ;
goto V_426;
V_418:
F_237 ( V_371 ) ;
V_416:
V_75 -> V_224 . V_427 ++ ;
V_426:
F_242 ( V_25 ) ;
}
static T_10 F_243 ( struct V_24 * V_25 , struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
const struct V_395 * V_396 ;
struct V_315 * V_428 ;
bool V_394 = false ;
struct V_38 * V_55 , * V_429 = NULL ;
struct V_39 * V_108 ;
V_396 = F_229 ( V_25 ) ;
F_154 ( V_25 ) ;
V_428 = F_158 ( V_25 ) ;
if ( ( V_50 -> V_3 & V_430 ) ) {
if ( F_23 ( V_428 -> V_320 ) == V_293 )
return F_178 ( V_75 , V_25 ) ;
#if F_115 ( V_178 )
else if ( F_23 ( V_428 -> V_320 ) == V_314 &&
F_150 ( V_25 , sizeof( struct V_221 )
+ sizeof( struct V_305 ) ) &&
F_160 ( V_25 ) -> V_323 == V_324 ) {
struct V_305 * V_337 ;
V_337 = (struct V_305 * ) F_196 ( V_25 ) ;
if ( V_337 -> V_327 . V_340 == 0 &&
V_337 -> V_327 . V_328 == V_341 )
return F_205 ( V_75 , V_25 ) ;
}
V_428 = F_158 ( V_25 ) ;
#endif
}
if ( V_50 -> V_3 & V_4 &&
V_396 && V_396 -> V_431 & V_432 ) {
F_228 ( V_25 , V_75 , NULL , false ) ;
return V_302 ;
}
V_108 = F_67 ( V_50 , V_428 -> V_319 ) ;
V_394 = false ;
if ( V_108 && ( V_108 -> V_3 & V_343 ) && ( V_50 -> V_3 & V_433 ) &&
( F_23 ( V_428 -> V_320 ) == V_281 ||
F_23 ( V_428 -> V_320 ) == V_314 ) ) {
V_394 = F_208 ( V_75 , V_25 ) ;
if ( V_394 )
V_108 = F_67 ( V_50 , V_428 -> V_319 ) ;
}
if ( V_108 == NULL ) {
V_108 = F_67 ( V_50 , V_434 ) ;
if ( V_108 == NULL ) {
if ( ( V_50 -> V_3 & V_435 ) &&
! F_105 ( V_428 -> V_319 ) )
F_59 ( V_50 , V_428 -> V_319 ) ;
V_75 -> V_224 . V_276 ++ ;
F_54 ( V_25 ) ;
return V_302 ;
}
}
F_128 (rdst, &f->remotes, list) {
struct V_24 * V_436 ;
if ( ! V_429 ) {
V_429 = V_55 ;
continue;
}
V_436 = F_244 ( V_25 , V_104 ) ;
if ( V_436 )
F_228 ( V_436 , V_75 , V_55 , V_394 ) ;
}
if ( V_429 )
F_228 ( V_25 , V_75 , V_429 , V_394 ) ;
else
F_54 ( V_25 ) ;
return V_302 ;
}
static void F_245 ( unsigned long V_437 )
{
struct V_49 * V_50 = (struct V_49 * ) V_437 ;
unsigned long V_438 = V_57 + V_439 ;
unsigned int V_191 ;
if ( ! F_135 ( V_50 -> V_75 ) )
return;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 ) {
struct V_440 * V_140 , * V_274 ;
F_121 ( & V_50 -> V_186 ) ;
F_246 (p, n, &vxlan->fdb_head[h]) {
struct V_39 * V_108
= F_80 ( V_140 , struct V_39 , V_171 ) ;
unsigned long V_441 ;
if ( V_108 -> V_73 & V_184 )
continue;
V_441 = V_108 -> V_93 + V_50 -> V_86 . V_442 * V_443 ;
if ( F_247 ( V_441 , V_57 ) ) {
F_104 ( V_50 -> V_75 ,
L_15 ,
V_108 -> V_70 ) ;
V_108 -> V_73 = V_109 ;
F_111 ( V_50 , V_108 ) ;
} else if ( F_248 ( V_441 , V_438 ) )
V_438 = V_441 ;
}
F_122 ( & V_50 -> V_186 ) ;
}
F_249 ( & V_50 -> V_444 , V_438 ) ;
}
static void F_250 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
V_99 V_118 = V_50 -> V_51 . V_52 ;
F_134 ( & V_34 -> V_203 ) ;
F_107 ( & V_50 -> V_171 , F_19 ( V_2 , V_118 ) ) ;
F_136 ( & V_34 -> V_203 ) ;
}
static int F_251 ( struct V_107 * V_75 )
{
V_75 -> V_239 = F_252 ( struct V_223 ) ;
if ( ! V_75 -> V_239 )
return - V_170 ;
return 0 ;
}
static void F_253 ( struct V_49 * V_50 )
{
struct V_39 * V_108 ;
F_121 ( & V_50 -> V_186 ) ;
V_108 = F_65 ( V_50 , V_434 ) ;
if ( V_108 )
F_111 ( V_50 , V_108 ) ;
F_122 ( & V_50 -> V_186 ) ;
}
static void F_254 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
F_253 ( V_50 ) ;
F_255 ( V_75 -> V_239 ) ;
}
static int F_256 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
int V_206 ;
V_206 = F_257 ( V_50 ) ;
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
F_249 ( & V_50 -> V_444 , V_57 + V_439 ) ;
return V_206 ;
}
static void F_258 ( struct V_49 * V_50 )
{
unsigned int V_191 ;
F_121 ( & V_50 -> V_186 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 ) {
struct V_440 * V_140 , * V_274 ;
F_246 (p, n, &vxlan->fdb_head[h]) {
struct V_39 * V_108
= F_80 ( V_140 , struct V_39 , V_171 ) ;
if ( ! F_37 ( V_108 -> V_70 ) )
F_111 ( V_50 , V_108 ) ;
}
}
F_122 ( & V_50 -> V_186 ) ;
}
static int F_259 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
int V_206 = 0 ;
if ( F_8 ( & V_50 -> V_51 . V_69 ) &&
! F_137 ( V_34 , V_50 ) )
V_206 = F_147 ( V_50 ) ;
F_260 ( & V_50 -> V_444 ) ;
F_258 ( V_50 ) ;
F_142 ( V_50 ) ;
return V_206 ;
}
static void F_261 ( struct V_107 * V_75 )
{
}
static int F_262 ( struct V_107 * V_75 , int V_446 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_38 * V_349 = & V_50 -> V_51 ;
struct V_107 * V_447 ;
int V_448 ;
V_447 = F_118 ( V_50 -> V_31 , V_349 -> V_90 ) ;
if ( V_447 == NULL )
return F_263 ( V_75 , V_446 ) ;
if ( V_349 -> V_69 . V_8 . V_9 == V_10 )
V_448 = V_447 -> V_449 - V_450 ;
else
V_448 = V_447 -> V_449 - V_451 ;
if ( V_446 < 68 || V_446 > V_448 )
return - V_180 ;
V_75 -> V_449 = V_446 ;
return 0 ;
}
static int F_264 ( struct V_107 * V_75 , struct V_24 * V_25 ,
struct V_395 * V_396 ,
T_2 V_452 , T_2 V_453 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_370 * V_371 ;
struct V_398 V_399 ;
memset ( & V_399 , 0 , sizeof( V_399 ) ) ;
V_399 . V_412 = F_235 ( V_396 -> V_259 . V_236 ) ;
V_399 . V_413 = V_25 -> V_233 ;
V_399 . V_414 = V_382 ;
V_399 . V_309 = V_396 -> V_259 . V_253 . V_403 . V_349 ;
V_371 = F_236 ( V_50 -> V_31 , & V_399 ) ;
if ( F_216 ( V_371 ) )
return F_222 ( V_371 ) ;
F_237 ( V_371 ) ;
V_396 -> V_259 . V_253 . V_403 . V_372 = V_399 . V_225 ;
V_396 -> V_259 . V_454 = V_452 ;
V_396 -> V_259 . V_401 = V_453 ;
return 0 ;
}
static int F_265 ( struct V_107 * V_75 , struct V_24 * V_25 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_395 * V_396 = F_229 ( V_25 ) ;
T_2 V_452 , V_453 ;
V_452 = F_234 ( F_39 ( V_75 ) , V_25 , V_50 -> V_86 . V_405 ,
V_50 -> V_86 . V_406 , true ) ;
V_453 = V_396 -> V_259 . V_401 ? : V_50 -> V_86 . V_87 ;
if ( F_232 ( V_396 ) == V_22 ) {
if ( ! V_50 -> V_200 )
return - V_180 ;
return F_264 ( V_75 , V_25 , V_396 , V_452 , V_453 ) ;
} else {
#if F_115 ( V_178 )
struct V_231 * V_376 ;
if ( ! V_50 -> V_202 )
return - V_180 ;
V_376 = F_224 ( V_50 , V_25 , 0 ,
& V_396 -> V_259 . V_253 . V_404 . V_349 ,
& V_396 -> V_259 . V_253 . V_404 . V_372 ) ;
if ( F_216 ( V_376 ) )
return F_222 ( V_376 ) ;
F_170 ( V_376 ) ;
V_396 -> V_259 . V_454 = V_452 ;
V_396 -> V_259 . V_401 = V_453 ;
#else
return - V_455 ;
#endif
}
return 0 ;
}
void F_266 ( struct V_107 * V_75 )
{
struct V_1 * V_2 ;
struct V_31 * V_31 = F_39 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
T_3 V_9 ;
T_2 V_32 ;
unsigned int V_312 ;
F_134 ( & V_34 -> V_203 ) ;
for ( V_312 = 0 ; V_312 < V_456 ; ++ V_312 ) {
F_29 (vs, &vn->sock_list[i], hlist) {
V_32 = F_30 ( V_2 -> V_46 -> V_47 ) -> V_48 ;
V_9 = F_31 ( V_2 ) ;
V_75 -> V_155 -> V_156 ( V_75 , V_9 ,
V_32 ) ;
}
}
F_136 ( & V_34 -> V_203 ) ;
}
static void F_267 ( struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
unsigned int V_191 ;
F_268 ( V_75 ) ;
F_269 ( V_75 ) ;
V_75 -> V_155 = & V_457 ;
V_75 -> V_458 = V_459 ;
F_270 ( V_75 , & V_460 ) ;
V_75 -> V_461 |= V_462 ;
V_75 -> V_461 |= V_463 | V_464 ;
V_75 -> V_461 |= V_465 ;
V_75 -> V_461 |= V_466 ;
V_75 -> V_467 = V_75 -> V_461 ;
V_75 -> V_461 |= V_468 | V_469 ;
V_75 -> V_470 |= V_463 | V_464 | V_465 ;
V_75 -> V_470 |= V_466 ;
V_75 -> V_470 |= V_468 | V_469 ;
F_271 ( V_75 ) ;
V_75 -> V_471 |= V_472 | V_473 ;
F_106 ( & V_50 -> V_42 ) ;
F_272 ( & V_50 -> V_186 ) ;
F_273 ( & V_50 -> V_444 ) ;
V_50 -> V_444 . V_474 = F_245 ;
V_50 -> V_444 . V_124 = ( unsigned long ) V_50 ;
V_50 -> V_86 . V_87 = F_173 ( V_475 ) ;
V_50 -> V_75 = V_75 ;
F_274 ( & V_50 -> V_244 , V_75 ) ;
for ( V_191 = 0 ; V_191 < V_192 ; ++ V_191 )
F_275 ( & V_50 -> V_116 [ V_191 ] ) ;
}
static int F_276 ( struct V_18 * V_177 [] , struct V_18 * V_124 [] )
{
if ( V_177 [ V_476 ] ) {
if ( F_13 ( V_177 [ V_476 ] ) != V_83 ) {
F_277 ( L_16 ) ;
return - V_180 ;
}
if ( ! F_278 ( F_279 ( V_177 [ V_476 ] ) ) ) {
F_277 ( L_17 ) ;
return - V_182 ;
}
}
if ( ! V_124 )
return - V_180 ;
if ( V_124 [ V_477 ] ) {
V_99 V_28 = F_117 ( V_124 [ V_477 ] ) ;
if ( V_28 >= V_478 )
return - V_479 ;
}
if ( V_124 [ V_480 ] ) {
const struct V_481 * V_140
= F_279 ( V_124 [ V_480 ] ) ;
if ( F_23 ( V_140 -> V_482 ) < F_23 ( V_140 -> V_483 ) ) {
F_277 ( L_18 ,
F_23 ( V_140 -> V_483 ) , F_23 ( V_140 -> V_482 ) ) ;
return - V_180 ;
}
}
return 0 ;
}
static void F_280 ( struct V_107 * V_484 ,
struct V_485 * V_486 )
{
F_281 ( V_486 -> V_321 , V_487 , sizeof( V_486 -> V_321 ) ) ;
F_281 ( V_486 -> V_488 , L_19 , sizeof( V_486 -> V_488 ) ) ;
}
static void F_282 ( struct V_489 * V_490 )
{
struct V_1 * V_2 = F_80 ( V_490 , struct V_1 , V_205 ) ;
F_283 ( V_2 -> V_46 ) ;
F_126 ( V_2 , V_174 ) ;
}
static struct V_491 * F_284 ( struct V_31 * V_31 , bool V_404 ,
T_2 V_32 , T_1 V_3 )
{
struct V_491 * V_46 ;
struct V_492 V_493 ;
int V_102 ;
memset ( & V_493 , 0 , sizeof( V_493 ) ) ;
if ( V_404 ) {
V_493 . V_44 = V_10 ;
V_493 . V_494 =
! ( V_3 & V_495 ) ;
V_493 . V_496 = 1 ;
} else {
V_493 . V_44 = V_22 ;
}
V_493 . V_497 = V_32 ;
V_102 = F_285 ( V_31 , & V_493 , & V_46 ) ;
if ( V_102 < 0 )
return F_225 ( V_102 ) ;
return V_46 ;
}
static struct V_1 * F_286 ( struct V_31 * V_31 , bool V_404 ,
T_2 V_32 , T_1 V_3 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
struct V_1 * V_2 ;
struct V_491 * V_46 ;
unsigned int V_191 ;
struct V_498 V_499 ;
V_2 = F_287 ( sizeof( * V_2 ) , V_500 ) ;
if ( ! V_2 )
return F_225 ( - V_170 ) ;
for ( V_191 = 0 ; V_191 < V_501 ; ++ V_191 )
F_275 ( & V_2 -> V_29 [ V_191 ] ) ;
F_288 ( & V_2 -> V_205 , F_282 ) ;
V_46 = F_284 ( V_31 , V_404 , V_32 , V_3 ) ;
if ( F_216 ( V_46 ) ) {
F_120 ( L_20 , F_23 ( V_32 ) ,
F_222 ( V_46 ) ) ;
F_110 ( V_2 ) ;
return F_289 ( V_46 ) ;
}
V_2 -> V_46 = V_46 ;
F_290 ( & V_2 -> V_201 , 1 ) ;
V_2 -> V_3 = ( V_3 & V_45 ) ;
V_2 -> V_146 . V_32 = V_32 ;
V_2 -> V_146 . V_502 . V_503 = F_79 ;
V_2 -> V_146 . V_502 . V_504 = F_91 ;
F_134 ( & V_34 -> V_203 ) ;
F_107 ( & V_2 -> V_171 , F_21 ( V_31 , V_32 ) ) ;
F_94 ( V_2 ) ;
F_136 ( & V_34 -> V_203 ) ;
V_499 . V_505 = V_2 ;
V_499 . V_506 = 1 ;
V_499 . V_507 = F_171 ;
V_499 . V_508 = NULL ;
F_291 ( V_31 , V_46 , & V_499 ) ;
return V_2 ;
}
static int F_292 ( struct V_49 * V_50 , bool V_404 )
{
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
struct V_1 * V_2 = NULL ;
if ( ! V_50 -> V_86 . V_509 ) {
F_134 ( & V_34 -> V_203 ) ;
V_2 = F_28 ( V_50 -> V_31 , V_404 ? V_10 : V_22 ,
V_50 -> V_86 . V_87 , V_50 -> V_3 ) ;
if ( V_2 && ! F_293 ( & V_2 -> V_201 , 1 , 0 ) ) {
F_136 ( & V_34 -> V_203 ) ;
return - V_510 ;
}
F_136 ( & V_34 -> V_203 ) ;
}
if ( ! V_2 )
V_2 = F_286 ( V_50 -> V_31 , V_404 ,
V_50 -> V_86 . V_87 , V_50 -> V_3 ) ;
if ( F_216 ( V_2 ) )
return F_222 ( V_2 ) ;
#if F_115 ( V_178 )
if ( V_404 )
V_50 -> V_202 = V_2 ;
else
#endif
V_50 -> V_200 = V_2 ;
F_250 ( V_2 , V_50 ) ;
return 0 ;
}
static int F_257 ( struct V_49 * V_50 )
{
bool V_404 = V_50 -> V_3 & V_511 ;
bool V_512 = V_50 -> V_3 & V_4 ;
int V_206 = 0 ;
V_50 -> V_200 = NULL ;
#if F_115 ( V_178 )
V_50 -> V_202 = NULL ;
if ( V_404 || V_512 )
V_206 = F_292 ( V_50 , true ) ;
#endif
if ( ! V_206 && ( ! V_404 || V_512 ) )
V_206 = F_292 ( V_50 , false ) ;
if ( V_206 < 0 )
F_142 ( V_50 ) ;
return V_206 ;
}
static int F_294 ( struct V_31 * V_513 , struct V_107 * V_75 ,
struct V_514 * V_515 )
{
struct V_33 * V_34 = F_22 ( V_513 , V_35 ) ;
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_38 * V_349 = & V_50 -> V_51 ;
unsigned short V_516 = V_228 ;
int V_102 ;
bool V_517 = false ;
T_2 V_518 = V_50 -> V_86 . V_87 ;
V_50 -> V_31 = V_513 ;
V_349 -> V_52 = V_515 -> V_118 ;
memcpy ( & V_349 -> V_69 , & V_515 -> V_69 , sizeof( V_515 -> V_69 ) ) ;
if ( ! V_349 -> V_69 . V_8 . V_9 )
V_349 -> V_69 . V_8 . V_9 = V_22 ;
if ( V_349 -> V_69 . V_8 . V_9 == V_10 ||
V_50 -> V_86 . V_225 . V_8 . V_9 == V_10 ) {
if ( ! F_115 ( V_178 ) )
return - V_455 ;
V_517 = true ;
V_50 -> V_3 |= V_511 ;
}
if ( V_515 -> V_90 ) {
struct V_107 * V_447
= F_118 ( V_513 , V_515 -> V_90 ) ;
V_349 -> V_90 = V_515 -> V_90 ;
if ( ! V_447 ) {
F_120 ( L_21 , V_349 -> V_90 ) ;
return - V_519 ;
}
#if F_115 ( V_178 )
if ( V_517 ) {
struct V_338 * V_520 = F_206 ( V_447 ) ;
if ( V_520 && V_520 -> V_521 . V_522 ) {
F_120 ( L_22 ) ;
return - V_523 ;
}
}
#endif
if ( ! V_515 -> V_449 )
V_75 -> V_449 = V_447 -> V_449 - ( V_517 ? V_450 : V_451 ) ;
V_516 = V_447 -> V_524 ;
}
if ( V_517 || V_515 -> V_3 & V_4 )
V_516 += V_450 ;
else
V_516 += V_451 ;
V_75 -> V_516 = V_516 ;
memcpy ( & V_50 -> V_86 , V_515 , sizeof( * V_515 ) ) ;
if ( ! V_50 -> V_86 . V_87 )
V_50 -> V_86 . V_87 = V_518 ;
V_50 -> V_3 |= V_515 -> V_3 ;
if ( ! V_50 -> V_86 . V_442 )
V_50 -> V_86 . V_442 = V_525 ;
if ( F_33 ( V_513 , V_515 -> V_118 , V_517 ? V_10 : V_22 ,
V_50 -> V_86 . V_87 , V_50 -> V_3 ) )
return - V_160 ;
V_75 -> V_526 = & V_527 ;
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
V_102 = F_295 ( V_75 ) ;
if ( V_102 ) {
F_253 ( V_50 ) ;
return V_102 ;
}
F_296 ( & V_50 -> V_42 , & V_34 -> V_528 ) ;
return 0 ;
}
struct V_107 * F_297 ( struct V_31 * V_31 , const char * V_400 ,
T_5 V_529 , struct V_514 * V_515 )
{
struct V_18 * V_177 [ V_530 + 1 ] ;
struct V_107 * V_75 ;
int V_102 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_75 = F_298 ( V_31 , V_400 , V_529 ,
& V_531 , V_177 ) ;
if ( F_216 ( V_75 ) )
return V_75 ;
V_102 = F_294 ( V_31 , V_75 , V_515 ) ;
if ( V_102 < 0 ) {
V_459 ( V_75 ) ;
return F_225 ( V_102 ) ;
}
return V_75 ;
}
static int F_299 ( struct V_31 * V_513 , struct V_107 * V_75 ,
struct V_18 * V_177 [] , struct V_18 * V_124 [] )
{
struct V_514 V_515 ;
int V_102 ;
memset ( & V_515 , 0 , sizeof( V_515 ) ) ;
if ( V_124 [ V_477 ] )
V_515 . V_118 = F_117 ( V_124 [ V_477 ] ) ;
if ( V_124 [ V_532 ] ) {
V_515 . V_69 . sin . V_13 . V_14 = F_15 ( V_124 [ V_532 ] ) ;
} else if ( V_124 [ V_533 ] ) {
if ( ! F_115 ( V_178 ) )
return - V_455 ;
V_515 . V_69 . V_11 . V_12 = F_14 ( V_124 [ V_533 ] ) ;
V_515 . V_69 . V_8 . V_9 = V_10 ;
}
if ( V_124 [ V_534 ] ) {
V_515 . V_225 . sin . V_13 . V_14 = F_15 ( V_124 [ V_534 ] ) ;
V_515 . V_225 . V_8 . V_9 = V_22 ;
} else if ( V_124 [ V_535 ] ) {
if ( ! F_115 ( V_178 ) )
return - V_455 ;
V_515 . V_225 . V_11 . V_12 = F_14 ( V_124 [ V_535 ] ) ;
V_515 . V_225 . V_8 . V_9 = V_10 ;
}
if ( V_124 [ V_536 ] )
V_515 . V_90 = F_117 ( V_124 [ V_536 ] ) ;
if ( V_124 [ V_537 ] )
V_515 . V_236 = F_300 ( V_124 [ V_537 ] ) ;
if ( V_124 [ V_538 ] )
V_515 . V_351 = F_300 ( V_124 [ V_538 ] ) ;
if ( ! V_124 [ V_539 ] || F_300 ( V_124 [ V_539 ] ) )
V_515 . V_3 |= V_232 ;
if ( V_124 [ V_540 ] )
V_515 . V_442 = F_117 ( V_124 [ V_540 ] ) ;
if ( V_124 [ V_541 ] && F_300 ( V_124 [ V_541 ] ) )
V_515 . V_3 |= V_430 ;
if ( V_124 [ V_542 ] && F_300 ( V_124 [ V_542 ] ) )
V_515 . V_3 |= V_433 ;
if ( V_124 [ V_543 ] && F_300 ( V_124 [ V_543 ] ) )
V_515 . V_3 |= V_435 ;
if ( V_124 [ V_544 ] && F_300 ( V_124 [ V_544 ] ) )
V_515 . V_3 |= V_300 ;
if ( V_124 [ V_545 ] )
V_515 . V_167 = F_117 ( V_124 [ V_545 ] ) ;
if ( V_124 [ V_546 ] &&
F_300 ( V_124 [ V_546 ] ) )
V_515 . V_3 |= V_4 ;
if ( V_124 [ V_480 ] ) {
const struct V_481 * V_140
= F_279 ( V_124 [ V_480 ] ) ;
V_515 . V_405 = F_23 ( V_140 -> V_483 ) ;
V_515 . V_406 = F_23 ( V_140 -> V_482 ) ;
}
if ( V_124 [ V_547 ] )
V_515 . V_87 = F_116 ( V_124 [ V_547 ] ) ;
if ( V_124 [ V_548 ] && F_300 ( V_124 [ V_548 ] ) )
V_515 . V_3 |= V_374 ;
if ( V_124 [ V_549 ] &&
F_300 ( V_124 [ V_549 ] ) )
V_515 . V_3 |= V_356 ;
if ( V_124 [ V_550 ] &&
F_300 ( V_124 [ V_550 ] ) )
V_515 . V_3 |= V_495 ;
if ( V_124 [ V_551 ] &&
F_300 ( V_124 [ V_551 ] ) )
V_515 . V_3 |= V_359 ;
if ( V_124 [ V_552 ] &&
F_300 ( V_124 [ V_552 ] ) )
V_515 . V_3 |= V_150 ;
if ( V_124 [ V_553 ] )
V_515 . V_3 |= V_256 ;
if ( V_124 [ V_554 ] )
V_515 . V_3 |= V_152 ;
V_102 = F_294 ( V_513 , V_75 , & V_515 ) ;
switch ( V_102 ) {
case - V_519 :
F_120 ( L_21 , V_515 . V_90 ) ;
break;
case - V_523 :
F_120 ( L_22 ) ;
break;
case - V_160 :
F_120 ( L_23 , V_515 . V_118 ) ;
break;
}
return V_102 ;
}
static void F_301 ( struct V_107 * V_75 , struct V_555 * V_117 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
struct V_33 * V_34 = F_22 ( V_50 -> V_31 , V_35 ) ;
F_134 ( & V_34 -> V_203 ) ;
if ( ! F_302 ( & V_50 -> V_171 ) )
F_112 ( & V_50 -> V_171 ) ;
F_136 ( & V_34 -> V_203 ) ;
F_303 ( & V_50 -> V_244 ) ;
F_304 ( & V_50 -> V_42 ) ;
F_305 ( V_75 , V_117 ) ;
}
static T_4 F_306 ( const struct V_107 * V_75 )
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
F_50 ( sizeof( struct V_481 ) ) +
F_50 ( sizeof( T_2 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
F_50 ( sizeof( T_8 ) ) +
0 ;
}
static int F_307 ( struct V_24 * V_25 , const struct V_107 * V_75 )
{
const struct V_49 * V_50 = F_58 ( V_75 ) ;
const struct V_38 * V_349 = & V_50 -> V_51 ;
struct V_481 V_556 = {
. V_483 = F_173 ( V_50 -> V_86 . V_405 ) ,
. V_482 = F_173 ( V_50 -> V_86 . V_406 ) ,
} ;
if ( F_44 ( V_25 , V_477 , V_349 -> V_52 ) )
goto V_81;
if ( ! F_5 ( & V_349 -> V_69 ) ) {
if ( V_349 -> V_69 . V_8 . V_9 == V_22 ) {
if ( F_18 ( V_25 , V_532 ,
V_349 -> V_69 . sin . V_13 . V_14 ) )
goto V_81;
#if F_115 ( V_178 )
} else {
if ( F_17 ( V_25 , V_533 ,
& V_349 -> V_69 . V_11 . V_12 ) )
goto V_81;
#endif
}
}
if ( V_349 -> V_90 && F_44 ( V_25 , V_536 , V_349 -> V_90 ) )
goto V_81;
if ( ! F_5 ( & V_50 -> V_86 . V_225 ) ) {
if ( V_50 -> V_86 . V_225 . V_8 . V_9 == V_22 ) {
if ( F_18 ( V_25 , V_534 ,
V_50 -> V_86 . V_225 . sin . V_13 . V_14 ) )
goto V_81;
#if F_115 ( V_178 )
} else {
if ( F_17 ( V_25 , V_535 ,
& V_50 -> V_86 . V_225 . V_11 . V_12 ) )
goto V_81;
#endif
}
}
if ( F_308 ( V_25 , V_538 , V_50 -> V_86 . V_351 ) ||
F_308 ( V_25 , V_537 , V_50 -> V_86 . V_236 ) ||
F_308 ( V_25 , V_539 ,
! ! ( V_50 -> V_3 & V_232 ) ) ||
F_308 ( V_25 , V_541 ,
! ! ( V_50 -> V_3 & V_430 ) ) ||
F_308 ( V_25 , V_542 , ! ! ( V_50 -> V_3 & V_433 ) ) ||
F_308 ( V_25 , V_543 ,
! ! ( V_50 -> V_3 & V_435 ) ) ||
F_308 ( V_25 , V_544 ,
! ! ( V_50 -> V_3 & V_300 ) ) ||
F_308 ( V_25 , V_546 ,
! ! ( V_50 -> V_3 & V_4 ) ) ||
F_44 ( V_25 , V_540 , V_50 -> V_86 . V_442 ) ||
F_44 ( V_25 , V_545 , V_50 -> V_86 . V_167 ) ||
F_43 ( V_25 , V_547 , V_50 -> V_86 . V_87 ) ||
F_308 ( V_25 , V_548 ,
! ! ( V_50 -> V_3 & V_374 ) ) ||
F_308 ( V_25 , V_549 ,
! ! ( V_50 -> V_3 & V_356 ) ) ||
F_308 ( V_25 , V_550 ,
! ! ( V_50 -> V_3 & V_495 ) ) ||
F_308 ( V_25 , V_551 ,
! ! ( V_50 -> V_3 & V_359 ) ) ||
F_308 ( V_25 , V_552 ,
! ! ( V_50 -> V_3 & V_150 ) ) )
goto V_81;
if ( F_42 ( V_25 , V_480 , sizeof( V_556 ) , & V_556 ) )
goto V_81;
if ( V_50 -> V_3 & V_256 &&
F_309 ( V_25 , V_553 ) )
goto V_81;
if ( V_50 -> V_3 & V_152 &&
F_309 ( V_25 , V_554 ) )
goto V_81;
return 0 ;
V_81:
return - V_66 ;
}
static struct V_31 * F_310 ( const struct V_107 * V_75 )
{
struct V_49 * V_50 = F_58 ( V_75 ) ;
return V_50 -> V_31 ;
}
static void F_311 ( struct V_33 * V_34 ,
struct V_107 * V_75 )
{
struct V_49 * V_50 , * V_42 ;
F_312 ( V_557 ) ;
F_109 (vxlan, next, &vn->vxlan_list, next) {
struct V_38 * V_349 = & V_50 -> V_51 ;
if ( V_349 -> V_90 == V_75 -> V_76 )
F_301 ( V_50 -> V_75 , & V_557 ) ;
}
F_313 ( & V_557 ) ;
}
static int F_314 ( struct V_558 * V_559 ,
unsigned long V_560 , void * V_561 )
{
struct V_107 * V_75 = F_315 ( V_561 ) ;
struct V_33 * V_34 = F_22 ( F_39 ( V_75 ) , V_35 ) ;
if ( V_560 == V_562 )
F_311 ( V_34 , V_75 ) ;
return V_563 ;
}
static T_11 int F_316 ( struct V_31 * V_31 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
unsigned int V_191 ;
F_106 ( & V_34 -> V_528 ) ;
F_272 ( & V_34 -> V_203 ) ;
for ( V_191 = 0 ; V_191 < V_456 ; ++ V_191 )
F_275 ( & V_34 -> V_36 [ V_191 ] ) ;
return 0 ;
}
static void T_12 F_317 ( struct V_31 * V_31 )
{
struct V_33 * V_34 = F_22 ( V_31 , V_35 ) ;
struct V_49 * V_50 , * V_42 ;
struct V_107 * V_75 , * V_564 ;
F_312 ( V_43 ) ;
F_318 () ;
F_319 (net, dev, aux)
if ( V_75 -> V_565 == & V_531 )
F_305 ( V_75 , & V_43 ) ;
F_109 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_38 ( F_39 ( V_50 -> V_75 ) , V_31 ) ) {
F_303 ( & V_50 -> V_244 ) ;
F_305 ( V_50 -> V_75 , & V_43 ) ;
}
}
F_313 ( & V_43 ) ;
F_320 () ;
}
static int T_13 F_321 ( void )
{
int V_164 ;
V_204 = F_322 ( L_19 , 0 , 0 ) ;
if ( ! V_204 )
return - V_170 ;
F_323 ( & V_566 , sizeof( V_566 ) ) ;
V_164 = F_324 ( & V_567 ) ;
if ( V_164 )
goto V_568;
V_164 = F_325 ( & V_569 ) ;
if ( V_164 )
goto V_570;
V_164 = F_326 ( & V_531 ) ;
if ( V_164 )
goto V_571;
return 0 ;
V_571:
F_327 ( & V_569 ) ;
V_570:
F_328 ( & V_567 ) ;
V_568:
F_329 ( V_204 ) ;
return V_164 ;
}
static void T_14 F_330 ( void )
{
F_331 ( & V_531 ) ;
F_327 ( & V_569 ) ;
F_329 ( V_204 ) ;
F_328 ( & V_567 ) ;
}
