static inline
bool F_1 ( const union V_1 * V_2 , const union V_1 * V_3 )
{
if ( V_2 -> V_4 . V_5 != V_3 -> V_4 . V_5 )
return false ;
if ( V_2 -> V_4 . V_5 == V_6 )
return F_2 ( & V_2 -> V_7 . V_8 , & V_3 -> V_7 . V_8 ) ;
else
return V_2 -> sin . V_9 . V_10 == V_3 -> sin . V_9 . V_10 ;
}
static inline bool F_3 ( const union V_1 * V_11 )
{
if ( V_11 -> V_4 . V_5 == V_6 )
return F_4 ( & V_11 -> V_7 . V_8 ) ;
else
return V_11 -> sin . V_9 . V_10 == F_5 ( V_12 ) ;
}
static inline bool F_6 ( const union V_1 * V_11 )
{
if ( V_11 -> V_4 . V_5 == V_6 )
return F_7 ( & V_11 -> V_7 . V_8 ) ;
else
return F_8 ( F_9 ( V_11 -> sin . V_9 . V_10 ) ) ;
}
static int F_10 ( union V_1 * V_13 , struct V_14 * V_15 )
{
if ( F_11 ( V_15 ) >= sizeof( struct V_16 ) ) {
F_12 ( & V_13 -> V_7 . V_8 , V_15 , sizeof( struct V_16 ) ) ;
V_13 -> V_4 . V_5 = V_6 ;
return 0 ;
} else if ( F_11 ( V_15 ) >= sizeof( V_17 ) ) {
V_13 -> sin . V_9 . V_10 = F_13 ( V_15 ) ;
V_13 -> V_4 . V_5 = V_18 ;
return 0 ;
} else {
return - V_19 ;
}
}
static int F_14 ( struct V_20 * V_21 , int V_22 ,
const union V_1 * V_13 )
{
if ( V_13 -> V_4 . V_5 == V_6 )
return F_15 ( V_21 , V_22 , sizeof( struct V_16 ) , & V_13 -> V_7 . V_8 ) ;
else
return F_16 ( V_21 , V_22 , V_13 -> sin . V_9 . V_10 ) ;
}
static inline
bool F_1 ( const union V_1 * V_2 , const union V_1 * V_3 )
{
return V_2 -> sin . V_9 . V_10 == V_3 -> sin . V_9 . V_10 ;
}
static inline bool F_3 ( const union V_1 * V_11 )
{
return V_11 -> sin . V_9 . V_10 == F_5 ( V_12 ) ;
}
static inline bool F_6 ( const union V_1 * V_11 )
{
return F_8 ( F_9 ( V_11 -> sin . V_9 . V_10 ) ) ;
}
static int F_10 ( union V_1 * V_13 , struct V_14 * V_15 )
{
if ( F_11 ( V_15 ) >= sizeof( struct V_16 ) ) {
return - V_19 ;
} else if ( F_11 ( V_15 ) >= sizeof( V_17 ) ) {
V_13 -> sin . V_9 . V_10 = F_13 ( V_15 ) ;
V_13 -> V_4 . V_5 = V_18 ;
return 0 ;
} else {
return - V_19 ;
}
}
static int F_14 ( struct V_20 * V_21 , int V_22 ,
const union V_1 * V_13 )
{
return F_16 ( V_21 , V_22 , V_13 -> sin . V_9 . V_10 ) ;
}
static inline struct V_23 * F_17 ( struct V_24 * V_25 , T_1 V_26 )
{
return & V_25 -> V_27 [ F_18 ( V_26 , V_28 ) ] ;
}
static inline struct V_23 * F_19 ( struct V_29 * V_29 , T_2 V_30 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
return & V_32 -> V_34 [ F_18 ( F_21 ( V_30 ) , V_35 ) ] ;
}
static inline struct V_36 * F_22 ( struct V_37 * V_38 )
{
return F_23 ( V_38 -> V_39 . V_40 , struct V_36 , V_41 ) ;
}
static inline struct V_36 * F_24 ( struct V_37 * V_38 )
{
return F_25 ( & V_38 -> V_39 , struct V_36 , V_41 ) ;
}
static struct V_24 * F_26 ( struct V_29 * V_29 , T_3 V_42 ,
T_2 V_30 , T_1 V_43 )
{
struct V_24 * V_25 ;
V_43 &= V_44 ;
F_27 (vs, vs_head(net, port), hlist) {
if ( F_28 ( V_25 -> V_45 -> V_46 ) -> V_47 == V_30 &&
F_28 ( V_25 -> V_45 -> V_46 ) -> V_46 . V_48 == V_42 &&
V_25 -> V_43 == V_43 )
return V_25 ;
}
return NULL ;
}
static struct V_49 * F_29 ( struct V_24 * V_25 , T_1 V_26 )
{
struct V_49 * V_50 ;
F_27 (vxlan, vni_head(vs, id), hlist) {
if ( V_50 -> V_51 . V_52 == V_26 )
return V_50 ;
}
return NULL ;
}
static struct V_49 * F_30 ( struct V_29 * V_29 , T_1 V_26 ,
T_3 V_42 , T_2 V_30 ,
T_1 V_43 )
{
struct V_24 * V_25 ;
V_25 = F_26 ( V_29 , V_42 , V_30 , V_43 ) ;
if ( ! V_25 )
return NULL ;
return F_29 ( V_25 , V_26 ) ;
}
static int F_31 ( struct V_20 * V_21 , struct V_49 * V_50 ,
const struct V_37 * V_38 ,
T_1 V_53 , T_1 V_54 , int type , unsigned int V_43 ,
const struct V_36 * V_55 )
{
unsigned long V_56 = V_57 ;
struct V_58 V_59 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
bool V_64 , V_65 ;
V_61 = F_32 ( V_21 , V_53 , V_54 , type , sizeof( * V_63 ) , V_43 ) ;
if ( V_61 == NULL )
return - V_66 ;
V_63 = F_33 ( V_61 ) ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_65 = V_64 = true ;
if ( type == V_67 ) {
V_63 -> V_68 = V_18 ;
V_64 = ! F_3 ( & V_55 -> V_69 ) ;
V_65 = ! F_34 ( V_38 -> V_70 ) ;
} else
V_63 -> V_68 = V_71 ;
V_63 -> V_72 = V_38 -> V_73 ;
V_63 -> V_74 = V_50 -> V_75 -> V_76 ;
V_63 -> V_77 = V_38 -> V_43 ;
V_63 -> V_78 = V_79 ;
if ( ! F_35 ( F_36 ( V_50 -> V_75 ) , V_50 -> V_29 ) &&
F_37 ( V_21 , V_80 ,
F_38 ( F_36 ( V_50 -> V_75 ) , V_50 -> V_29 ) ) )
goto V_81;
if ( V_65 && F_15 ( V_21 , V_82 , V_83 , & V_38 -> V_70 ) )
goto V_81;
if ( V_64 && F_14 ( V_21 , V_84 , & V_55 -> V_69 ) )
goto V_81;
if ( V_55 -> V_85 && V_55 -> V_85 != V_50 -> V_86 &&
F_39 ( V_21 , V_87 , V_55 -> V_85 ) )
goto V_81;
if ( V_55 -> V_52 != V_50 -> V_51 . V_52 &&
F_40 ( V_21 , V_88 , V_55 -> V_52 ) )
goto V_81;
if ( V_55 -> V_89 &&
F_40 ( V_21 , V_90 , V_55 -> V_89 ) )
goto V_81;
V_59 . V_91 = F_41 ( V_56 - V_38 -> V_92 ) ;
V_59 . V_93 = 0 ;
V_59 . V_94 = F_41 ( V_56 - V_38 -> V_95 ) ;
V_59 . V_96 = 0 ;
if ( F_15 ( V_21 , V_97 , sizeof( V_59 ) , & V_59 ) )
goto V_81;
F_42 ( V_21 , V_61 ) ;
return 0 ;
V_81:
F_43 ( V_21 , V_61 ) ;
return - V_66 ;
}
static inline T_4 F_44 ( void )
{
return F_45 ( sizeof( struct V_62 ) )
+ F_46 ( V_83 )
+ F_46 ( sizeof( struct V_16 ) )
+ F_46 ( sizeof( T_2 ) )
+ F_46 ( sizeof( V_17 ) )
+ F_46 ( sizeof( V_98 ) )
+ F_46 ( sizeof( V_99 ) )
+ F_46 ( sizeof( struct V_58 ) ) ;
}
static void F_47 ( struct V_49 * V_50 , struct V_37 * V_38 ,
struct V_36 * V_100 , int type )
{
struct V_29 * V_29 = F_36 ( V_50 -> V_75 ) ;
struct V_20 * V_21 ;
int V_101 = - V_102 ;
V_21 = F_48 ( F_44 () , V_103 ) ;
if ( V_21 == NULL )
goto V_104;
V_101 = F_31 ( V_21 , V_50 , V_38 , 0 , 0 , type , 0 , V_100 ) ;
if ( V_101 < 0 ) {
F_49 ( V_101 == - V_66 ) ;
F_50 ( V_21 ) ;
goto V_104;
}
F_51 ( V_21 , V_29 , 0 , V_105 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_52 ( V_29 , V_105 , V_101 ) ;
}
static void F_53 ( struct V_106 * V_75 , union V_1 * V_11 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_37 V_107 = {
. V_73 = V_108 ,
} ;
struct V_36 V_109 = {
. V_69 = * V_11 ,
. V_52 = V_110 ,
} ;
F_47 ( V_50 , & V_107 , & V_109 , V_67 ) ;
}
static void F_55 ( struct V_49 * V_50 , const T_5 V_70 [ V_83 ] )
{
struct V_37 V_107 = {
. V_73 = V_108 ,
} ;
struct V_36 V_109 = { } ;
memcpy ( V_107 . V_70 , V_70 , V_83 ) ;
F_47 ( V_50 , & V_107 , & V_109 , V_67 ) ;
}
static T_1 F_56 ( const unsigned char * V_111 )
{
T_6 V_112 = F_57 ( ( T_6 * ) V_111 ) ;
#ifdef F_58
V_112 >>= 16 ;
#else
V_112 <<= 16 ;
#endif
return F_59 ( V_112 , V_113 ) ;
}
static inline struct V_23 * F_60 ( struct V_49 * V_50 ,
const T_5 * V_114 )
{
return & V_50 -> V_115 [ F_56 ( V_114 ) ] ;
}
static struct V_37 * F_61 ( struct V_49 * V_50 ,
const T_5 * V_114 )
{
struct V_23 * V_116 = F_60 ( V_50 , V_114 ) ;
struct V_37 * V_107 ;
F_27 (f, head, hlist) {
if ( F_62 ( V_114 , V_107 -> V_70 ) )
return V_107 ;
}
return NULL ;
}
static struct V_37 * F_63 ( struct V_49 * V_50 ,
const T_5 * V_114 )
{
struct V_37 * V_107 ;
V_107 = F_61 ( V_50 , V_114 ) ;
if ( V_107 )
V_107 -> V_92 = V_57 ;
return V_107 ;
}
static struct V_36 * F_64 ( struct V_37 * V_107 ,
union V_1 * V_13 , T_2 V_30 ,
V_98 V_117 , V_98 V_76 )
{
struct V_36 * V_100 ;
F_65 (rd, &f->remotes, list) {
if ( F_1 ( & V_100 -> V_69 , V_13 ) &&
V_100 -> V_85 == V_30 &&
V_100 -> V_52 == V_117 &&
V_100 -> V_89 == V_76 )
return V_100 ;
}
return NULL ;
}
static int F_66 ( struct V_37 * V_107 ,
union V_1 * V_13 , T_2 V_30 , V_98 V_117 , V_98 V_76 )
{
struct V_36 * V_100 ;
V_100 = F_64 ( V_107 , V_13 , V_30 , V_117 , V_76 ) ;
if ( V_100 )
return 0 ;
V_100 = F_67 ( & V_107 -> V_39 , struct V_36 , V_41 ) ;
if ( ! V_100 )
return 0 ;
V_100 -> V_69 = * V_13 ;
V_100 -> V_85 = V_30 ;
V_100 -> V_52 = V_117 ;
V_100 -> V_89 = V_76 ;
return 1 ;
}
static int F_68 ( struct V_37 * V_107 ,
union V_1 * V_13 , T_2 V_30 , V_98 V_117 ,
V_98 V_76 , struct V_36 * * V_118 )
{
struct V_36 * V_100 ;
V_100 = F_64 ( V_107 , V_13 , V_30 , V_117 , V_76 ) ;
if ( V_100 )
return 0 ;
V_100 = F_69 ( sizeof( * V_100 ) , V_103 ) ;
if ( V_100 == NULL )
return - V_102 ;
V_100 -> V_69 = * V_13 ;
V_100 -> V_85 = V_30 ;
V_100 -> V_52 = V_117 ;
V_100 -> V_89 = V_76 ;
F_70 ( & V_100 -> V_41 , & V_107 -> V_39 ) ;
* V_118 = V_100 ;
return 1 ;
}
static struct V_119 * F_71 ( struct V_20 * V_21 ,
unsigned int V_120 ,
struct V_119 * V_121 , T_4 V_122 ,
T_1 V_123 , struct V_124 * V_125 ,
bool V_126 )
{
T_4 V_127 , V_128 , V_129 ;
if ( V_21 -> V_130 )
return NULL ;
if ( ! F_72 ( V_21 ) -> V_131 )
return NULL ;
V_127 = ( V_123 & V_132 ) << V_133 ;
V_128 = V_127 + ( ( V_123 & V_134 ) ?
F_73 ( struct V_135 , V_136 ) :
F_73 ( struct V_137 , V_136 ) ) ;
V_129 = V_122 + V_128 + sizeof( V_138 ) ;
if ( F_74 ( V_21 , V_120 + V_129 ) ) {
V_121 = F_75 ( V_21 , V_120 + V_129 , V_120 ) ;
if ( ! V_121 )
return NULL ;
}
F_76 ( V_21 , ( void * ) V_121 + V_122 ,
V_127 , V_128 , V_125 , V_126 ) ;
V_21 -> V_130 = 1 ;
return V_121 ;
}
static struct V_20 * * F_77 ( struct V_20 * * V_116 ,
struct V_20 * V_21 ,
struct V_139 * V_140 )
{
struct V_20 * V_141 , * * V_142 = NULL ;
struct V_119 * V_121 , * V_143 ;
unsigned int V_144 , V_145 ;
int V_146 = 1 ;
struct V_24 * V_25 = F_78 ( V_140 , struct V_24 ,
V_147 ) ;
T_1 V_43 ;
struct V_124 V_125 ;
F_79 ( & V_125 ) ;
V_145 = F_80 ( V_21 ) ;
V_144 = V_145 + sizeof( * V_121 ) ;
V_121 = F_81 ( V_21 , V_145 ) ;
if ( F_74 ( V_21 , V_144 ) ) {
V_121 = F_75 ( V_21 , V_144 , V_145 ) ;
if ( F_82 ( ! V_121 ) )
goto V_148;
}
F_83 ( V_21 , sizeof( struct V_119 ) ) ;
F_84 ( V_21 , V_121 , sizeof( struct V_119 ) ) ;
V_43 = F_9 ( V_121 -> V_149 ) ;
if ( ( V_43 & V_150 ) && ( V_25 -> V_43 & V_151 ) ) {
V_121 = F_71 ( V_21 , V_145 , V_121 , sizeof( struct V_119 ) ,
F_9 ( V_121 -> V_152 ) , & V_125 ,
! ! ( V_25 -> V_43 &
V_153 ) ) ;
if ( ! V_121 )
goto V_148;
}
V_146 = 0 ;
for ( V_141 = * V_116 ; V_141 ; V_141 = V_141 -> V_40 ) {
if ( ! F_72 ( V_141 ) -> V_154 )
continue;
V_143 = (struct V_119 * ) ( V_141 -> V_123 + V_145 ) ;
if ( V_121 -> V_149 != V_143 -> V_149 ||
V_121 -> V_152 != V_143 -> V_152 ) {
F_72 ( V_141 ) -> V_154 = 0 ;
continue;
}
}
V_142 = F_85 ( V_116 , V_21 ) ;
V_148:
F_86 ( V_21 , & V_125 ) ;
F_72 ( V_21 ) -> V_146 |= V_146 ;
return V_142 ;
}
static int F_87 ( struct V_20 * V_21 , int V_155 ,
struct V_139 * V_140 )
{
F_88 ( V_21 , V_155 ) ;
return F_89 ( V_21 , V_155 + sizeof( struct V_119 ) ) ;
}
static void F_90 ( struct V_24 * V_25 )
{
struct V_106 * V_75 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
struct V_29 * V_29 = F_91 ( V_46 ) ;
T_3 V_5 = V_46 -> V_48 ;
T_2 V_30 = F_28 ( V_46 ) -> V_47 ;
int V_101 ;
if ( V_5 == V_18 ) {
V_101 = F_92 ( & V_25 -> V_147 ) ;
if ( V_101 )
F_93 ( L_1 , V_101 ) ;
}
F_94 () ;
F_95 (net, dev) {
if ( V_75 -> V_156 -> V_157 )
V_75 -> V_156 -> V_157 ( V_75 , V_5 ,
V_30 ) ;
}
F_96 () ;
}
static void F_97 ( struct V_24 * V_25 )
{
struct V_106 * V_75 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
struct V_29 * V_29 = F_91 ( V_46 ) ;
T_3 V_5 = V_46 -> V_48 ;
T_2 V_30 = F_28 ( V_46 ) -> V_47 ;
F_94 () ;
F_95 (net, dev) {
if ( V_75 -> V_156 -> V_158 )
V_75 -> V_156 -> V_158 ( V_75 , V_5 ,
V_30 ) ;
}
F_96 () ;
if ( V_5 == V_18 )
F_98 ( & V_25 -> V_147 ) ;
}
static int F_99 ( struct V_49 * V_50 ,
const T_5 * V_114 , union V_1 * V_13 ,
T_7 V_73 , T_7 V_43 ,
T_2 V_30 , V_98 V_117 , V_98 V_76 ,
T_8 V_77 )
{
struct V_36 * V_100 = NULL ;
struct V_37 * V_107 ;
int V_159 = 0 ;
V_107 = F_61 ( V_50 , V_114 ) ;
if ( V_107 ) {
if ( V_43 & V_160 ) {
F_100 ( V_50 -> V_75 ,
L_2 , V_114 ) ;
return - V_161 ;
}
if ( V_107 -> V_73 != V_73 ) {
V_107 -> V_73 = V_73 ;
V_107 -> V_95 = V_57 ;
V_159 = 1 ;
}
if ( V_107 -> V_43 != V_77 ) {
V_107 -> V_43 = V_77 ;
V_107 -> V_95 = V_57 ;
V_159 = 1 ;
}
if ( ( V_43 & V_162 ) ) {
if ( ! ( F_101 ( V_107 -> V_70 ) ||
F_34 ( V_107 -> V_70 ) ) ) {
int V_163 = F_66 ( V_107 , V_13 , V_30 , V_117 ,
V_76 ) ;
if ( V_163 < 0 )
return V_163 ;
V_159 |= V_163 ;
} else
return - V_164 ;
}
if ( ( V_43 & V_165 ) &&
( F_101 ( V_107 -> V_70 ) ||
F_34 ( V_107 -> V_70 ) ) ) {
int V_163 = F_68 ( V_107 , V_13 , V_30 , V_117 , V_76 ,
& V_100 ) ;
if ( V_163 < 0 )
return V_163 ;
V_159 |= V_163 ;
}
} else {
if ( ! ( V_43 & V_166 ) )
return - V_167 ;
if ( V_50 -> V_168 && V_50 -> V_169 >= V_50 -> V_168 )
return - V_170 ;
if ( ( V_43 & V_162 ) &&
( F_101 ( V_114 ) || F_34 ( V_114 ) ) )
return - V_164 ;
F_100 ( V_50 -> V_75 , L_3 , V_114 , V_13 ) ;
V_107 = F_69 ( sizeof( * V_107 ) , V_103 ) ;
if ( ! V_107 )
return - V_171 ;
V_159 = 1 ;
V_107 -> V_73 = V_73 ;
V_107 -> V_43 = V_77 ;
V_107 -> V_95 = V_107 -> V_92 = V_57 ;
F_102 ( & V_107 -> V_39 ) ;
memcpy ( V_107 -> V_70 , V_114 , V_83 ) ;
F_68 ( V_107 , V_13 , V_30 , V_117 , V_76 , & V_100 ) ;
++ V_50 -> V_169 ;
F_103 ( & V_107 -> V_172 ,
F_60 ( V_50 , V_114 ) ) ;
}
if ( V_159 ) {
if ( V_100 == NULL )
V_100 = F_24 ( V_107 ) ;
F_47 ( V_50 , V_107 , V_100 , V_173 ) ;
}
return 0 ;
}
static void F_104 ( struct V_174 * V_116 )
{
struct V_37 * V_107 = F_78 ( V_116 , struct V_37 , V_175 ) ;
struct V_36 * V_100 , * V_176 ;
F_105 (rd, nd, &f->remotes, list)
F_106 ( V_100 ) ;
F_106 ( V_107 ) ;
}
static void F_107 ( struct V_49 * V_50 , struct V_37 * V_107 )
{
F_100 ( V_50 -> V_75 ,
L_4 , V_107 -> V_70 ) ;
-- V_50 -> V_169 ;
F_47 ( V_50 , V_107 , F_24 ( V_107 ) , V_177 ) ;
F_108 ( & V_107 -> V_172 ) ;
F_109 ( & V_107 -> V_175 , F_104 ) ;
}
static int F_110 ( struct V_14 * V_178 [] , struct V_49 * V_50 ,
union V_1 * V_13 , T_2 * V_30 , T_1 * V_117 , T_1 * V_76 )
{
struct V_29 * V_29 = F_36 ( V_50 -> V_75 ) ;
int V_101 ;
if ( V_178 [ V_84 ] ) {
V_101 = F_10 ( V_13 , V_178 [ V_84 ] ) ;
if ( V_101 )
return V_101 ;
} else {
union V_1 * V_109 = & V_50 -> V_51 . V_69 ;
if ( V_109 -> V_4 . V_5 == V_18 ) {
V_13 -> sin . V_9 . V_10 = F_5 ( V_12 ) ;
V_13 -> V_4 . V_5 = V_18 ;
#if F_111 ( V_179 )
} else {
V_13 -> V_7 . V_8 = V_180 ;
V_13 -> V_4 . V_5 = V_6 ;
#endif
}
}
if ( V_178 [ V_87 ] ) {
if ( F_11 ( V_178 [ V_87 ] ) != sizeof( T_2 ) )
return - V_181 ;
* V_30 = F_112 ( V_178 [ V_87 ] ) ;
} else {
* V_30 = V_50 -> V_86 ;
}
if ( V_178 [ V_88 ] ) {
if ( F_11 ( V_178 [ V_88 ] ) != sizeof( T_1 ) )
return - V_181 ;
* V_117 = F_113 ( V_178 [ V_88 ] ) ;
} else {
* V_117 = V_50 -> V_51 . V_52 ;
}
if ( V_178 [ V_90 ] ) {
struct V_106 * V_182 ;
if ( F_11 ( V_178 [ V_90 ] ) != sizeof( T_1 ) )
return - V_181 ;
* V_76 = F_113 ( V_178 [ V_90 ] ) ;
V_182 = F_114 ( V_29 , * V_76 ) ;
if ( ! V_182 )
return - V_183 ;
} else {
* V_76 = 0 ;
}
return 0 ;
}
static int F_115 ( struct V_62 * V_63 , struct V_14 * V_178 [] ,
struct V_106 * V_75 ,
const unsigned char * V_111 , V_138 V_184 , V_138 V_43 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_117 , V_76 ;
int V_101 ;
if ( ! ( V_63 -> V_72 & ( V_185 | V_186 ) ) ) {
F_116 ( L_5 ,
V_63 -> V_72 ) ;
return - V_181 ;
}
if ( V_178 [ V_84 ] == NULL )
return - V_181 ;
V_101 = F_110 ( V_178 , V_50 , & V_13 , & V_30 , & V_117 , & V_76 ) ;
if ( V_101 )
return V_101 ;
if ( V_50 -> V_51 . V_69 . V_4 . V_5 != V_13 . V_4 . V_5 )
return - V_19 ;
F_117 ( & V_50 -> V_187 ) ;
V_101 = F_99 ( V_50 , V_111 , & V_13 , V_63 -> V_72 , V_43 ,
V_30 , V_117 , V_76 , V_63 -> V_77 ) ;
F_118 ( & V_50 -> V_187 ) ;
return V_101 ;
}
static int F_119 ( struct V_62 * V_63 , struct V_14 * V_178 [] ,
struct V_106 * V_75 ,
const unsigned char * V_111 , V_138 V_184 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_37 * V_107 ;
struct V_36 * V_100 = NULL ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_117 , V_76 ;
int V_101 ;
V_101 = F_110 ( V_178 , V_50 , & V_13 , & V_30 , & V_117 , & V_76 ) ;
if ( V_101 )
return V_101 ;
V_101 = - V_167 ;
F_117 ( & V_50 -> V_187 ) ;
V_107 = F_63 ( V_50 , V_111 ) ;
if ( ! V_107 )
goto V_148;
if ( ! F_3 ( & V_13 ) ) {
V_100 = F_64 ( V_107 , & V_13 , V_30 , V_117 , V_76 ) ;
if ( ! V_100 )
goto V_148;
}
V_101 = 0 ;
if ( V_100 && ! F_120 ( & V_107 -> V_39 ) ) {
F_121 ( & V_100 -> V_41 ) ;
F_47 ( V_50 , V_107 , V_100 , V_177 ) ;
F_122 ( V_100 , V_175 ) ;
goto V_148;
}
F_107 ( V_50 , V_107 ) ;
V_148:
F_118 ( & V_50 -> V_187 ) ;
return V_101 ;
}
static int F_123 ( struct V_20 * V_21 , struct V_188 * V_189 ,
struct V_106 * V_75 ,
struct V_106 * V_190 , int V_191 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
unsigned int V_192 ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 ) {
struct V_37 * V_107 ;
int V_101 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_100 ;
if ( V_191 < V_189 -> args [ 0 ] )
goto V_194;
F_124 (rd, &f->remotes, list) {
V_101 = F_31 ( V_21 , V_50 , V_107 ,
F_125 ( V_189 -> V_21 ) . V_53 ,
V_189 -> V_61 -> V_195 ,
V_173 ,
V_196 , V_100 ) ;
if ( V_101 < 0 )
goto V_148;
}
V_194:
++ V_191 ;
}
}
V_148:
return V_191 ;
}
static bool F_126 ( struct V_106 * V_75 ,
union V_1 * V_197 , const T_5 * V_198 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_37 * V_107 ;
V_107 = F_63 ( V_50 , V_198 ) ;
if ( F_127 ( V_107 ) ) {
struct V_36 * V_55 = F_22 ( V_107 ) ;
if ( F_127 ( F_1 ( & V_55 -> V_69 , V_197 ) ) )
return false ;
if ( V_107 -> V_73 & V_199 )
return true ;
if ( F_128 () )
F_129 ( V_75 ,
L_6 ,
V_198 , & V_55 -> V_69 . V_4 , & V_197 -> V_4 ) ;
V_55 -> V_69 = * V_197 ;
V_107 -> V_95 = V_57 ;
F_47 ( V_50 , V_107 , V_55 , V_173 ) ;
} else {
F_130 ( & V_50 -> V_187 ) ;
if ( F_131 ( V_75 ) )
F_99 ( V_50 , V_198 , V_197 ,
V_186 ,
V_160 | V_166 ,
V_50 -> V_86 ,
V_50 -> V_51 . V_52 ,
0 , V_200 ) ;
F_132 ( & V_50 -> V_187 ) ;
}
return false ;
}
static bool F_133 ( struct V_31 * V_32 , struct V_49 * V_75 )
{
struct V_49 * V_50 ;
if ( F_134 ( & V_75 -> V_201 -> V_202 ) == 1 )
return false ;
F_65 (vxlan, &vn->vxlan_list, next) {
if ( ! F_131 ( V_50 -> V_75 ) || V_50 == V_75 )
continue;
if ( V_50 -> V_201 != V_75 -> V_201 )
continue;
if ( ! F_1 ( & V_50 -> V_51 . V_69 ,
& V_75 -> V_51 . V_69 ) )
continue;
if ( V_50 -> V_51 . V_89 !=
V_75 -> V_51 . V_89 )
continue;
return true ;
}
return false ;
}
static void F_135 ( struct V_24 * V_25 )
{
F_136 ( & V_25 -> V_202 ) ;
}
void F_137 ( struct V_24 * V_25 )
{
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
struct V_29 * V_29 = F_91 ( V_46 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_138 ( & V_25 -> V_202 ) )
return;
F_130 ( & V_32 -> V_203 ) ;
F_108 ( & V_25 -> V_172 ) ;
F_97 ( V_25 ) ;
F_132 ( & V_32 -> V_203 ) ;
F_139 ( V_204 , & V_25 -> V_205 ) ;
}
static void F_140 ( struct V_206 * V_207 )
{
struct V_49 * V_50 = F_78 ( V_207 , struct V_49 , V_208 ) ;
struct V_24 * V_25 = V_50 -> V_201 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
union V_1 * V_13 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_89 ;
F_141 ( V_46 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_209 V_210 = {
. V_211 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_212 = V_76 ,
} ;
F_142 ( V_46 , & V_210 ) ;
#if F_111 ( V_179 )
} else {
V_213 -> V_214 ( V_46 , V_76 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_143 ( V_46 ) ;
F_137 ( V_25 ) ;
F_144 ( V_50 -> V_75 ) ;
}
static void F_145 ( struct V_206 * V_207 )
{
struct V_49 * V_50 = F_78 ( V_207 , struct V_49 , V_215 ) ;
struct V_24 * V_25 = V_50 -> V_201 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
union V_1 * V_13 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_89 ;
F_141 ( V_46 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_209 V_210 = {
. V_211 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_212 = V_76 ,
} ;
F_146 ( V_46 , & V_210 ) ;
#if F_111 ( V_179 )
} else {
V_213 -> V_216 ( V_46 , V_76 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_143 ( V_46 ) ;
F_137 ( V_25 ) ;
F_144 ( V_50 -> V_75 ) ;
}
static struct V_119 * F_147 ( struct V_20 * V_21 , struct V_119 * V_121 ,
T_4 V_122 , T_1 V_123 , bool V_126 )
{
T_4 V_127 , V_128 , V_129 ;
V_127 = ( V_123 & V_132 ) << V_133 ;
V_128 = V_127 + ( ( V_123 & V_134 ) ?
F_73 ( struct V_135 , V_136 ) :
F_73 ( struct V_137 , V_136 ) ) ;
V_129 = V_122 + V_128 + sizeof( V_138 ) ;
if ( ! F_148 ( V_21 , V_129 ) )
return NULL ;
V_121 = (struct V_119 * ) ( F_149 ( V_21 ) + 1 ) ;
F_150 ( V_21 , ( void * ) V_121 + V_122 , V_127 , V_128 ,
V_126 ) ;
return V_121 ;
}
static int F_151 ( struct V_45 * V_46 , struct V_20 * V_21 )
{
struct V_24 * V_25 ;
struct V_119 * V_217 ;
T_1 V_43 , V_117 ;
struct V_218 V_219 = { 0 } ;
if ( ! F_148 ( V_21 , V_220 ) )
goto error;
V_217 = (struct V_119 * ) ( F_149 ( V_21 ) + 1 ) ;
V_43 = F_9 ( V_217 -> V_149 ) ;
V_117 = F_9 ( V_217 -> V_152 ) ;
if ( V_43 & V_221 ) {
V_43 &= ~ V_221 ;
} else {
goto V_222;
}
if ( F_152 ( V_21 , V_220 , F_153 ( V_223 ) ) )
goto V_224;
V_217 = (struct V_119 * ) ( F_149 ( V_21 ) + 1 ) ;
V_25 = F_154 ( V_46 ) ;
if ( ! V_25 )
goto V_224;
if ( ( V_43 & V_150 ) && ( V_25 -> V_43 & V_151 ) ) {
V_217 = F_147 ( V_21 , V_217 , sizeof( struct V_119 ) , V_117 ,
! ! ( V_25 -> V_43 & V_153 ) ) ;
if ( ! V_217 )
goto V_224;
V_43 &= ~ V_150 ;
V_117 &= V_225 ;
}
if ( ( V_43 & V_226 ) && ( V_25 -> V_43 & V_227 ) ) {
struct V_228 * V_229 ;
V_229 = (struct V_228 * ) V_217 ;
V_219 . V_229 = F_21 ( V_229 -> V_230 ) ;
if ( V_229 -> V_231 )
V_219 . V_229 |= V_232 ;
if ( V_229 -> V_233 )
V_219 . V_229 |= V_234 ;
V_43 &= ~ V_235 ;
}
if ( V_43 || V_117 & ~ V_225 ) {
goto V_222;
}
V_219 . V_117 = V_217 -> V_152 ;
V_25 -> V_236 ( V_25 , V_21 , & V_219 ) ;
return 0 ;
V_224:
F_50 ( V_21 ) ;
return 0 ;
V_222:
F_100 ( V_21 -> V_75 , L_7 ,
F_9 ( V_217 -> V_149 ) , F_9 ( V_217 -> V_152 ) ) ;
error:
return 1 ;
}
static void F_155 ( struct V_24 * V_25 , struct V_20 * V_21 ,
struct V_218 * V_219 )
{
struct V_237 * V_238 = NULL ;
struct V_239 * V_240 = NULL ;
struct V_49 * V_50 ;
struct V_241 * V_242 ;
union V_1 V_243 ;
V_98 V_117 ;
int V_101 = 0 ;
union V_1 * V_69 ;
V_117 = F_9 ( V_219 -> V_117 ) >> 8 ;
V_50 = F_29 ( V_25 , V_117 ) ;
if ( ! V_50 )
goto V_224;
V_69 = & V_50 -> V_51 . V_69 ;
F_156 ( V_21 ) ;
F_157 ( V_21 , ! F_35 ( V_50 -> V_29 , F_36 ( V_50 -> V_75 ) ) ) ;
V_21 -> V_244 = F_158 ( V_21 , V_50 -> V_75 ) ;
F_159 ( V_21 , F_160 ( V_21 ) , V_245 ) ;
if ( F_62 ( F_160 ( V_21 ) -> V_246 , V_50 -> V_75 -> V_247 ) )
goto V_224;
if ( V_69 -> V_4 . V_5 == V_18 ) {
V_238 = F_161 ( V_21 ) ;
V_243 . sin . V_9 . V_10 = V_238 -> V_243 ;
V_243 . V_4 . V_5 = V_18 ;
#if F_111 ( V_179 )
} else {
V_240 = F_162 ( V_21 ) ;
V_243 . V_7 . V_8 = V_240 -> V_243 ;
V_243 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_50 -> V_43 & V_248 ) &&
F_126 ( V_21 -> V_75 , & V_243 , F_160 ( V_21 ) -> V_246 ) )
goto V_224;
F_163 ( V_21 ) ;
V_21 -> V_249 = V_219 -> V_229 ;
if ( V_240 )
V_101 = F_164 ( V_240 , V_21 ) ;
if ( V_238 )
V_101 = F_165 ( V_238 , V_21 ) ;
if ( F_82 ( V_101 ) ) {
if ( V_250 ) {
if ( V_240 )
F_166 ( L_8 ,
& V_240 -> V_243 ) ;
if ( V_238 )
F_166 ( L_9 ,
& V_238 -> V_243 , V_238 -> V_251 ) ;
}
if ( V_101 > 1 ) {
++ V_50 -> V_75 -> V_242 . V_252 ;
++ V_50 -> V_75 -> V_242 . V_253 ;
goto V_224;
}
}
V_242 = F_167 ( V_50 -> V_75 -> V_254 ) ;
F_168 ( & V_242 -> V_255 ) ;
V_242 -> V_256 ++ ;
V_242 -> V_257 += V_21 -> V_258 ;
F_169 ( & V_242 -> V_255 ) ;
F_170 ( V_21 ) ;
return;
V_224:
F_50 ( V_21 ) ;
}
static int F_171 ( struct V_106 * V_75 , struct V_20 * V_21 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_259 * V_260 ;
T_5 * V_261 , * V_262 ;
V_17 V_263 , V_264 ;
struct V_265 * V_266 ;
if ( V_75 -> V_43 & V_267 )
goto V_148;
if ( ! F_148 ( V_21 , F_172 ( V_75 ) ) ) {
V_75 -> V_242 . V_268 ++ ;
goto V_148;
}
V_260 = F_173 ( V_21 ) ;
if ( ( V_260 -> V_269 != F_153 ( V_270 ) &&
V_260 -> V_269 != F_153 ( V_271 ) ) ||
V_260 -> V_272 != F_153 ( V_273 ) ||
V_260 -> V_274 != F_153 ( V_275 ) ||
V_260 -> V_276 != V_75 -> V_277 ||
V_260 -> V_278 != 4 )
goto V_148;
V_261 = ( T_5 * ) V_260 + sizeof( struct V_259 ) ;
V_262 = V_261 ;
V_261 += V_75 -> V_277 ;
memcpy ( & V_263 , V_261 , sizeof( V_263 ) ) ;
V_261 += sizeof( V_263 ) ;
V_261 += V_75 -> V_277 ;
memcpy ( & V_264 , V_261 , sizeof( V_264 ) ) ;
if ( F_174 ( V_264 ) ||
F_175 ( V_264 ) )
goto V_148;
V_266 = F_176 ( & V_279 , & V_264 , V_75 ) ;
if ( V_266 ) {
struct V_37 * V_107 ;
struct V_20 * V_280 ;
if ( ! ( V_266 -> V_281 & V_282 ) ) {
F_177 ( V_266 ) ;
goto V_148;
}
V_107 = F_63 ( V_50 , V_266 -> V_283 ) ;
if ( V_107 && F_3 ( & ( F_22 ( V_107 ) -> V_69 ) ) ) {
F_177 ( V_266 ) ;
goto V_148;
}
V_280 = F_178 ( V_284 , V_285 , V_263 , V_75 , V_264 , V_262 ,
V_266 -> V_283 , V_262 ) ;
F_177 ( V_266 ) ;
if ( V_280 == NULL )
goto V_148;
F_156 ( V_280 ) ;
F_179 ( V_280 , F_180 ( V_280 ) ) ;
V_280 -> V_286 = V_287 ;
V_280 -> V_288 = V_289 ;
if ( F_181 ( V_280 ) == V_290 )
V_75 -> V_242 . V_291 ++ ;
} else if ( V_50 -> V_43 & V_292 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_264 ,
. sin . V_293 = V_18 ,
} ;
F_53 ( V_75 , & V_11 ) ;
}
V_148:
F_182 ( V_21 ) ;
return V_294 ;
}
static struct V_20 * F_183 ( struct V_20 * V_295 ,
struct V_265 * V_266 , bool V_296 )
{
struct V_106 * V_75 = V_295 -> V_75 ;
struct V_20 * V_280 ;
struct V_297 * V_298 , * V_299 ;
struct V_239 * V_300 ;
T_5 * V_301 ;
int V_302 = 8 ;
int V_303 ;
int V_304 , V_258 ;
if ( V_75 == NULL )
return NULL ;
V_258 = F_184 ( V_75 ) + sizeof( struct V_239 ) +
sizeof( * V_299 ) + V_302 + V_75 -> V_305 ;
V_280 = F_185 ( V_258 , V_103 ) ;
if ( V_280 == NULL )
return NULL ;
V_280 -> V_244 = F_153 ( V_306 ) ;
V_280 -> V_75 = V_75 ;
F_186 ( V_280 , F_184 ( V_295 -> V_75 ) ) ;
F_187 ( V_280 , sizeof( struct V_307 ) ) ;
F_188 ( V_280 , 0 ) ;
V_298 = (struct V_297 * ) F_189 ( V_295 ) ;
V_301 = F_160 ( V_295 ) -> V_246 ;
V_303 = V_295 -> V_258 - F_190 ( V_295 ) - sizeof( * V_298 ) ;
for ( V_304 = 0 ; V_304 < V_303 - 1 ; V_304 += ( V_298 -> V_308 [ V_304 + 1 ] << 3 ) ) {
if ( V_298 -> V_308 [ V_304 ] == V_309 ) {
V_301 = V_298 -> V_308 + V_304 + sizeof( struct V_310 ) ;
break;
}
}
F_191 ( F_160 ( V_280 ) -> V_311 , V_301 ) ;
F_191 ( F_160 ( V_280 ) -> V_246 , V_266 -> V_283 ) ;
F_160 ( V_280 ) -> V_312 = F_153 ( V_306 ) ;
V_280 -> V_244 = F_153 ( V_306 ) ;
F_192 ( V_280 , sizeof( struct V_307 ) ) ;
F_193 ( V_280 , 0 ) ;
F_194 ( V_280 , sizeof( struct V_239 ) ) ;
V_300 = F_162 ( V_280 ) ;
memset ( V_300 , 0 , sizeof( struct V_239 ) ) ;
V_300 -> V_313 = 6 ;
V_300 -> V_314 = F_162 ( V_295 ) -> V_314 ;
V_300 -> V_315 = V_316 ;
V_300 -> V_317 = 255 ;
V_300 -> V_301 = F_162 ( V_295 ) -> V_243 ;
V_300 -> V_243 = * (struct V_16 * ) V_266 -> V_318 ;
F_192 ( V_280 , sizeof( struct V_239 ) ) ;
F_195 ( V_280 , 0 ) ;
V_299 = (struct V_297 * ) F_194 ( V_280 , sizeof( * V_299 ) + V_302 ) ;
memset ( V_299 , 0 , sizeof( * V_299 ) + V_302 ) ;
V_299 -> V_319 . V_320 = V_321 ;
V_299 -> V_319 . V_322 = V_296 ;
V_299 -> V_319 . V_323 = 1 ;
V_299 -> V_319 . V_324 = 1 ;
V_299 -> V_325 = V_298 -> V_325 ;
F_191 ( & V_299 -> V_308 [ 2 ] , V_266 -> V_283 ) ;
V_299 -> V_308 [ 0 ] = V_326 ;
V_299 -> V_308 [ 1 ] = V_302 >> 3 ;
V_299 -> V_319 . V_327 = F_196 ( & V_300 -> V_243 ,
& V_300 -> V_301 , sizeof( * V_299 ) + V_302 , V_316 ,
F_197 ( V_299 , sizeof( * V_299 ) + V_302 , 0 ) ) ;
V_300 -> V_328 = F_153 ( sizeof( * V_299 ) + V_302 ) ;
F_187 ( V_280 , sizeof( struct V_239 ) ) ;
V_280 -> V_286 = V_287 ;
return V_280 ;
}
static int F_198 ( struct V_106 * V_75 , struct V_20 * V_21 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_297 * V_329 ;
const struct V_239 * V_237 ;
const struct V_16 * V_243 , * V_301 ;
struct V_265 * V_266 ;
struct V_330 * V_331 ;
V_331 = F_199 ( V_75 ) ;
if ( ! V_331 )
goto V_148;
V_237 = F_162 ( V_21 ) ;
V_243 = & V_237 -> V_243 ;
V_301 = & V_237 -> V_301 ;
V_329 = (struct V_297 * ) F_189 ( V_21 ) ;
if ( V_329 -> V_319 . V_332 != 0 ||
V_329 -> V_319 . V_320 != V_333 )
goto V_148;
if ( F_200 ( V_301 ) ||
F_7 ( & V_329 -> V_325 ) )
goto V_148;
V_266 = F_176 ( V_213 -> V_334 , & V_329 -> V_325 , V_75 ) ;
if ( V_266 ) {
struct V_37 * V_107 ;
struct V_20 * V_280 ;
if ( ! ( V_266 -> V_281 & V_282 ) ) {
F_177 ( V_266 ) ;
goto V_148;
}
V_107 = F_63 ( V_50 , V_266 -> V_283 ) ;
if ( V_107 && F_3 ( & ( F_22 ( V_107 ) -> V_69 ) ) ) {
F_177 ( V_266 ) ;
goto V_148;
}
V_280 = F_183 ( V_21 , V_266 ,
! ! ( V_107 ? V_107 -> V_43 & V_335 : 0 ) ) ;
F_177 ( V_266 ) ;
if ( V_280 == NULL )
goto V_148;
if ( F_181 ( V_280 ) == V_290 )
V_75 -> V_242 . V_291 ++ ;
} else if ( V_50 -> V_43 & V_292 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_329 -> V_325 ,
. V_7 . V_336 = V_6 ,
} ;
F_53 ( V_75 , & V_11 ) ;
}
V_148:
F_182 ( V_21 ) ;
return V_294 ;
}
static bool F_201 ( struct V_106 * V_75 , struct V_20 * V_21 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_265 * V_266 ;
if ( F_101 ( F_160 ( V_21 ) -> V_311 ) )
return false ;
V_266 = NULL ;
switch ( F_21 ( F_160 ( V_21 ) -> V_312 ) ) {
case V_273 :
{
struct V_237 * V_337 ;
if ( ! F_148 ( V_21 , sizeof( struct V_237 ) ) )
return false ;
V_337 = F_161 ( V_21 ) ;
V_266 = F_176 ( & V_279 , & V_337 -> V_301 , V_75 ) ;
if ( ! V_266 && ( V_50 -> V_43 & V_292 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_337 -> V_301 ,
. sin . V_293 = V_18 ,
} ;
F_53 ( V_75 , & V_11 ) ;
return false ;
}
break;
}
#if F_111 ( V_179 )
case V_306 :
{
struct V_239 * V_300 ;
if ( ! F_148 ( V_21 , sizeof( struct V_239 ) ) )
return false ;
V_300 = F_162 ( V_21 ) ;
V_266 = F_176 ( V_213 -> V_334 , & V_300 -> V_301 , V_75 ) ;
if ( ! V_266 && ( V_50 -> V_43 & V_292 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_300 -> V_301 ,
. V_7 . V_336 = V_6 ,
} ;
F_53 ( V_75 , & V_11 ) ;
return false ;
}
break;
}
#endif
default:
return false ;
}
if ( V_266 ) {
bool V_338 ;
V_338 = ! F_62 ( F_160 ( V_21 ) -> V_311 , V_266 -> V_283 ) ;
if ( V_338 ) {
memcpy ( F_160 ( V_21 ) -> V_246 , F_160 ( V_21 ) -> V_311 ,
V_75 -> V_277 ) ;
memcpy ( F_160 ( V_21 ) -> V_311 , V_266 -> V_283 , V_75 -> V_277 ) ;
}
F_177 ( V_266 ) ;
return V_338 ;
}
return false ;
}
static void F_202 ( struct V_119 * V_217 , T_1 V_339 ,
struct V_218 * V_219 )
{
struct V_228 * V_229 ;
if ( ! V_219 -> V_229 )
return;
V_229 = (struct V_228 * ) V_217 ;
V_217 -> V_149 |= F_5 ( V_226 ) ;
if ( V_219 -> V_229 & V_232 )
V_229 -> V_231 = 1 ;
if ( V_219 -> V_229 & V_234 )
V_229 -> V_233 = 1 ;
V_229 -> V_230 = F_153 ( V_219 -> V_229 & V_340 ) ;
}
static int F_203 ( struct V_341 * V_342 , struct V_20 * V_21 ,
struct V_106 * V_75 , struct V_16 * V_243 ,
struct V_16 * V_301 , T_8 V_343 , T_8 V_344 ,
T_2 V_345 , T_2 V_86 ,
struct V_218 * V_219 , bool V_346 , T_1 V_339 )
{
struct V_119 * V_217 ;
int V_347 ;
int V_101 ;
bool V_348 = ! ( V_339 & V_349 ) ;
int type = V_348 ? V_350 : V_351 ;
V_138 V_122 = sizeof( struct V_119 ) ;
if ( ( V_339 & V_352 ) &&
V_21 -> V_286 == V_353 ) {
int V_354 = F_204 ( V_21 ) ;
if ( V_354 <= V_355 &&
! ( V_354 & V_356 ) &&
( V_21 -> V_357 == F_73 ( struct V_135 , V_136 ) ||
V_21 -> V_357 == F_73 ( struct V_137 , V_136 ) ) ) {
V_348 = false ;
type |= V_358 ;
}
}
V_21 = F_205 ( V_21 , V_348 , type ) ;
if ( F_206 ( V_21 ) ) {
V_101 = - V_181 ;
goto V_101;
}
F_157 ( V_21 , V_346 ) ;
V_347 = F_184 ( V_342 -> V_75 ) + V_342 -> V_359
+ V_220 + sizeof( struct V_239 )
+ ( F_207 ( V_21 ) ? V_360 : 0 ) ;
V_101 = F_208 ( V_21 , V_347 ) ;
if ( F_82 ( V_101 ) ) {
F_50 ( V_21 ) ;
goto V_101;
}
V_21 = F_209 ( V_21 ) ;
if ( F_49 ( ! V_21 ) ) {
V_101 = - V_171 ;
goto V_101;
}
V_217 = (struct V_119 * ) F_210 ( V_21 , sizeof( * V_217 ) ) ;
V_217 -> V_149 = F_5 ( V_221 ) ;
V_217 -> V_152 = V_219 -> V_117 ;
if ( type & V_358 ) {
T_1 V_123 = ( F_204 ( V_21 ) - V_122 ) >>
V_133 ;
if ( V_21 -> V_357 == F_73 ( struct V_135 , V_136 ) )
V_123 |= V_134 ;
V_217 -> V_152 |= F_5 ( V_123 ) ;
V_217 -> V_149 |= F_5 ( V_150 ) ;
if ( ! F_211 ( V_21 ) ) {
V_21 -> V_286 = V_361 ;
V_21 -> V_362 = 0 ;
}
}
if ( V_339 & V_227 )
F_202 ( V_217 , V_339 , V_219 ) ;
F_212 ( V_21 , F_153 ( V_223 ) ) ;
F_213 ( V_342 , V_21 , V_75 , V_243 , V_301 , V_343 ,
V_344 , V_345 , V_86 ,
! ! ( V_339 & V_349 ) ) ;
return 0 ;
V_101:
F_214 ( V_342 ) ;
return V_101 ;
}
int F_215 ( struct V_363 * V_364 , struct V_20 * V_21 ,
V_17 V_365 , V_17 V_342 , T_8 V_251 , T_8 V_344 , T_2 V_366 ,
T_2 V_345 , T_2 V_86 ,
struct V_218 * V_219 , bool V_346 , T_1 V_339 )
{
struct V_119 * V_217 ;
int V_347 ;
int V_101 ;
bool V_348 = ! ! ( V_339 & V_367 ) ;
int type = V_348 ? V_350 : V_351 ;
V_138 V_122 = sizeof( struct V_119 ) ;
if ( ( V_339 & V_352 ) &&
V_21 -> V_286 == V_353 ) {
int V_354 = F_204 ( V_21 ) ;
if ( V_354 <= V_355 &&
! ( V_354 & V_356 ) &&
( V_21 -> V_357 == F_73 ( struct V_135 , V_136 ) ||
V_21 -> V_357 == F_73 ( struct V_137 , V_136 ) ) ) {
V_348 = false ;
type |= V_358 ;
}
}
V_21 = F_205 ( V_21 , V_348 , type ) ;
if ( F_206 ( V_21 ) )
return F_216 ( V_21 ) ;
V_347 = F_184 ( V_364 -> V_342 . V_75 ) + V_364 -> V_342 . V_359
+ V_220 + sizeof( struct V_237 )
+ ( F_207 ( V_21 ) ? V_360 : 0 ) ;
V_101 = F_208 ( V_21 , V_347 ) ;
if ( F_82 ( V_101 ) ) {
F_50 ( V_21 ) ;
return V_101 ;
}
V_21 = F_209 ( V_21 ) ;
if ( F_49 ( ! V_21 ) )
return - V_171 ;
V_217 = (struct V_119 * ) F_210 ( V_21 , sizeof( * V_217 ) ) ;
V_217 -> V_149 = F_5 ( V_221 ) ;
V_217 -> V_152 = V_219 -> V_117 ;
if ( type & V_358 ) {
T_1 V_123 = ( F_204 ( V_21 ) - V_122 ) >>
V_133 ;
if ( V_21 -> V_357 == F_73 ( struct V_135 , V_136 ) )
V_123 |= V_134 ;
V_217 -> V_152 |= F_5 ( V_123 ) ;
V_217 -> V_149 |= F_5 ( V_150 ) ;
if ( ! F_211 ( V_21 ) ) {
V_21 -> V_286 = V_361 ;
V_21 -> V_362 = 0 ;
}
}
if ( V_339 & V_227 )
F_202 ( V_217 , V_339 , V_219 ) ;
F_212 ( V_21 , F_153 ( V_223 ) ) ;
return F_217 ( V_364 , V_21 , V_365 , V_342 , V_251 ,
V_344 , V_366 , V_345 , V_86 , V_346 ,
! ( V_339 & V_367 ) ) ;
}
static void F_218 ( struct V_20 * V_21 , struct V_49 * V_368 ,
struct V_49 * V_369 )
{
struct V_241 * V_370 , * V_371 ;
union V_1 V_372 ;
union V_1 * V_69 = & V_369 -> V_51 . V_69 ;
struct V_106 * V_75 = V_21 -> V_75 ;
int V_258 = V_21 -> V_258 ;
V_370 = F_167 ( V_368 -> V_75 -> V_254 ) ;
V_371 = F_167 ( V_369 -> V_75 -> V_254 ) ;
V_21 -> V_288 = V_289 ;
V_21 -> V_362 = 0 ;
V_21 -> V_75 = V_369 -> V_75 ;
F_179 ( V_21 , F_180 ( V_21 ) ) ;
if ( V_69 -> V_4 . V_5 == V_18 ) {
V_372 . sin . V_9 . V_10 = F_5 ( V_373 ) ;
V_372 . V_4 . V_5 = V_18 ;
#if F_111 ( V_179 )
} else {
V_372 . V_7 . V_8 = V_374 ;
V_372 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_369 -> V_43 & V_248 )
F_126 ( V_21 -> V_75 , & V_372 , F_160 ( V_21 ) -> V_246 ) ;
F_168 ( & V_370 -> V_255 ) ;
V_370 -> V_375 ++ ;
V_370 -> V_376 += V_258 ;
F_169 ( & V_370 -> V_255 ) ;
if ( F_170 ( V_21 ) == V_377 ) {
F_168 ( & V_371 -> V_255 ) ;
V_371 -> V_256 ++ ;
V_371 -> V_257 += V_258 ;
F_169 ( & V_371 -> V_255 ) ;
} else {
V_75 -> V_242 . V_291 ++ ;
}
}
static void F_219 ( struct V_20 * V_21 , struct V_106 * V_75 ,
struct V_36 * V_55 , bool V_378 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_363 * V_364 = NULL ;
const struct V_237 * V_379 ;
struct V_380 V_381 ;
union V_1 * V_342 ;
struct V_218 V_219 ;
T_2 V_345 = 0 , V_86 ;
T_1 V_117 ;
T_2 V_366 = 0 ;
T_8 V_251 , V_344 ;
int V_101 ;
V_86 = V_55 -> V_85 ? V_55 -> V_85 : V_50 -> V_86 ;
V_117 = V_55 -> V_52 ;
V_342 = & V_55 -> V_69 ;
if ( F_3 ( V_342 ) ) {
if ( V_378 ) {
F_218 ( V_21 , V_50 , V_50 ) ;
return;
}
goto V_224;
}
V_379 = F_161 ( V_21 ) ;
V_344 = V_50 -> V_344 ;
if ( ! V_344 && F_6 ( V_342 ) )
V_344 = 1 ;
V_251 = V_50 -> V_251 ;
if ( V_251 == 1 )
V_251 = F_220 ( V_379 , V_21 ) ;
V_345 = F_221 ( F_36 ( V_75 ) , V_21 , V_50 -> V_382 ,
V_50 -> V_383 , true ) ;
if ( V_342 -> V_4 . V_5 == V_18 ) {
memset ( & V_381 , 0 , sizeof( V_381 ) ) ;
V_381 . V_384 = V_55 -> V_89 ;
V_381 . V_385 = F_222 ( V_251 ) ;
V_381 . V_301 = V_342 -> sin . V_9 . V_10 ;
V_381 . V_243 = V_50 -> V_243 . sin . V_9 . V_10 ;
V_364 = F_223 ( V_50 -> V_29 , & V_381 ) ;
if ( F_206 ( V_364 ) ) {
F_100 ( V_75 , L_10 ,
& V_342 -> sin . V_9 . V_10 ) ;
V_75 -> V_242 . V_386 ++ ;
goto V_387;
}
if ( V_364 -> V_342 . V_75 == V_75 ) {
F_100 ( V_75 , L_11 ,
& V_342 -> sin . V_9 . V_10 ) ;
V_75 -> V_242 . V_388 ++ ;
goto V_389;
}
if ( V_364 -> V_390 & V_391 &&
! ( V_364 -> V_390 & ( V_392 | V_393 ) ) ) {
struct V_49 * V_369 ;
F_224 ( V_364 ) ;
V_369 = F_30 ( V_50 -> V_29 , V_117 ,
V_342 -> V_4 . V_5 , V_86 ,
V_50 -> V_43 ) ;
if ( ! V_369 )
goto V_387;
F_218 ( V_21 , V_50 , V_369 ) ;
return;
}
V_251 = F_225 ( V_251 , V_379 , V_21 ) ;
V_344 = V_344 ? : F_226 ( & V_364 -> V_342 ) ;
V_219 . V_117 = F_5 ( V_117 << 8 ) ;
V_219 . V_229 = V_21 -> V_249 ;
V_101 = F_215 ( V_364 , V_21 , V_381 . V_243 ,
V_342 -> sin . V_9 . V_10 , V_251 , V_344 , V_366 ,
V_345 , V_86 , & V_219 ,
! F_35 ( V_50 -> V_29 , F_36 ( V_50 -> V_75 ) ) ,
V_50 -> V_43 ) ;
if ( V_101 < 0 ) {
V_21 = NULL ;
goto V_389;
}
F_227 ( V_101 , & V_75 -> V_242 , V_75 -> V_254 ) ;
#if F_111 ( V_179 )
} else {
struct V_45 * V_46 = V_50 -> V_201 -> V_45 -> V_46 ;
struct V_341 * V_394 ;
struct V_395 V_396 ;
T_1 V_43 ;
memset ( & V_396 , 0 , sizeof( V_396 ) ) ;
V_396 . V_397 = V_55 -> V_89 ;
V_396 . V_301 = V_342 -> V_7 . V_8 ;
V_396 . V_243 = V_50 -> V_243 . V_7 . V_8 ;
V_396 . V_398 = V_399 ;
if ( V_213 -> V_400 ( V_46 , & V_394 , & V_396 ) ) {
F_100 ( V_75 , L_12 ,
& V_342 -> V_7 . V_8 ) ;
V_75 -> V_242 . V_386 ++ ;
goto V_387;
}
if ( V_394 -> V_75 == V_75 ) {
F_100 ( V_75 , L_13 ,
& V_342 -> V_7 . V_8 ) ;
F_214 ( V_394 ) ;
V_75 -> V_242 . V_388 ++ ;
goto V_387;
}
V_43 = ( (struct V_401 * ) V_394 ) -> V_402 ;
if ( V_43 & V_403 &&
! ( V_43 & ( V_392 | V_393 ) ) ) {
struct V_49 * V_369 ;
F_214 ( V_394 ) ;
V_369 = F_30 ( V_50 -> V_29 , V_117 ,
V_342 -> V_4 . V_5 , V_86 ,
V_50 -> V_43 ) ;
if ( ! V_369 )
goto V_387;
F_218 ( V_21 , V_50 , V_369 ) ;
return;
}
V_344 = V_344 ? : F_228 ( V_394 ) ;
V_219 . V_117 = F_5 ( V_117 << 8 ) ;
V_219 . V_229 = V_21 -> V_249 ;
V_101 = F_203 ( V_394 , V_21 , V_75 , & V_396 . V_243 , & V_396 . V_301 ,
0 , V_344 , V_345 , V_86 , & V_219 ,
! F_35 ( V_50 -> V_29 , F_36 ( V_50 -> V_75 ) ) ,
V_50 -> V_43 ) ;
#endif
}
return;
V_224:
V_75 -> V_242 . V_268 ++ ;
goto V_404;
V_389:
F_224 ( V_364 ) ;
V_387:
V_75 -> V_242 . V_405 ++ ;
V_404:
F_229 ( V_21 ) ;
}
static T_9 F_230 ( struct V_20 * V_21 , struct V_106 * V_75 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_307 * V_406 ;
bool V_378 = false ;
struct V_36 * V_55 , * V_407 = NULL ;
struct V_37 * V_107 ;
F_156 ( V_21 ) ;
V_406 = F_160 ( V_21 ) ;
if ( ( V_50 -> V_43 & V_408 ) ) {
if ( F_21 ( V_406 -> V_312 ) == V_285 )
return F_171 ( V_75 , V_21 ) ;
#if F_111 ( V_179 )
else if ( F_21 ( V_406 -> V_312 ) == V_306 &&
F_148 ( V_21 , sizeof( struct V_239 )
+ sizeof( struct V_297 ) ) &&
F_162 ( V_21 ) -> V_315 == V_316 ) {
struct V_297 * V_329 ;
V_329 = (struct V_297 * ) F_189 ( V_21 ) ;
if ( V_329 -> V_319 . V_332 == 0 &&
V_329 -> V_319 . V_320 == V_333 )
return F_198 ( V_75 , V_21 ) ;
}
V_406 = F_160 ( V_21 ) ;
#endif
}
V_107 = F_63 ( V_50 , V_406 -> V_311 ) ;
V_378 = false ;
if ( V_107 && ( V_107 -> V_43 & V_335 ) && ( V_50 -> V_43 & V_409 ) &&
( F_21 ( V_406 -> V_312 ) == V_273 ||
F_21 ( V_406 -> V_312 ) == V_306 ) ) {
V_378 = F_201 ( V_75 , V_21 ) ;
if ( V_378 )
V_107 = F_63 ( V_50 , V_406 -> V_311 ) ;
}
if ( V_107 == NULL ) {
V_107 = F_63 ( V_50 , V_410 ) ;
if ( V_107 == NULL ) {
if ( ( V_50 -> V_43 & V_411 ) &&
! F_101 ( V_406 -> V_311 ) )
F_55 ( V_50 , V_406 -> V_311 ) ;
V_75 -> V_242 . V_268 ++ ;
F_50 ( V_21 ) ;
return V_294 ;
}
}
F_124 (rdst, &f->remotes, list) {
struct V_20 * V_412 ;
if ( ! V_407 ) {
V_407 = V_55 ;
continue;
}
V_412 = F_231 ( V_21 , V_103 ) ;
if ( V_412 )
F_219 ( V_412 , V_75 , V_55 , V_378 ) ;
}
if ( V_407 )
F_219 ( V_21 , V_75 , V_407 , V_378 ) ;
else
F_50 ( V_21 ) ;
return V_294 ;
}
static void F_232 ( unsigned long V_413 )
{
struct V_49 * V_50 = (struct V_49 * ) V_413 ;
unsigned long V_414 = V_57 + V_415 ;
unsigned int V_192 ;
if ( ! F_131 ( V_50 -> V_75 ) )
return;
F_117 ( & V_50 -> V_187 ) ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 ) {
struct V_416 * V_141 , * V_266 ;
F_233 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_107
= F_78 ( V_141 , struct V_37 , V_172 ) ;
unsigned long V_417 ;
if ( V_107 -> V_73 & V_185 )
continue;
V_417 = V_107 -> V_92 + V_50 -> V_418 * V_419 ;
if ( F_234 ( V_417 , V_57 ) ) {
F_100 ( V_50 -> V_75 ,
L_14 ,
V_107 -> V_70 ) ;
V_107 -> V_73 = V_108 ;
F_107 ( V_50 , V_107 ) ;
} else if ( F_235 ( V_417 , V_414 ) )
V_414 = V_417 ;
}
}
F_118 ( & V_50 -> V_187 ) ;
F_236 ( & V_50 -> V_420 , V_414 ) ;
}
static void F_237 ( struct V_24 * V_25 , struct V_49 * V_50 )
{
V_98 V_117 = V_50 -> V_51 . V_52 ;
V_50 -> V_201 = V_25 ;
F_103 ( & V_50 -> V_172 , F_17 ( V_25 , V_117 ) ) ;
}
static int F_238 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_31 * V_32 = F_20 ( V_50 -> V_29 , V_33 ) ;
struct V_24 * V_25 ;
bool V_421 = V_50 -> V_43 & V_422 ;
V_75 -> V_254 = F_239 ( struct V_241 ) ;
if ( ! V_75 -> V_254 )
return - V_171 ;
F_130 ( & V_32 -> V_203 ) ;
V_25 = F_26 ( V_50 -> V_29 , V_421 ? V_6 : V_18 ,
V_50 -> V_86 , V_50 -> V_43 ) ;
if ( V_25 && F_240 ( & V_25 -> V_202 , 1 , 0 ) ) {
F_237 ( V_25 , V_50 ) ;
} else {
F_241 ( V_75 ) ;
F_139 ( V_204 , & V_50 -> V_423 ) ;
}
F_132 ( & V_32 -> V_203 ) ;
return 0 ;
}
static void F_242 ( struct V_49 * V_50 )
{
struct V_37 * V_107 ;
F_117 ( & V_50 -> V_187 ) ;
V_107 = F_61 ( V_50 , V_410 ) ;
if ( V_107 )
F_107 ( V_50 , V_107 ) ;
F_118 ( & V_50 -> V_187 ) ;
}
static void F_243 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_24 * V_25 = V_50 -> V_201 ;
F_242 ( V_50 ) ;
if ( V_25 )
F_137 ( V_25 ) ;
F_244 ( V_75 -> V_254 ) ;
}
static int F_245 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_24 * V_25 = V_50 -> V_201 ;
if ( ! V_25 )
return - V_424 ;
if ( F_6 ( & V_50 -> V_51 . V_69 ) ) {
F_135 ( V_25 ) ;
F_241 ( V_75 ) ;
F_139 ( V_204 , & V_50 -> V_208 ) ;
}
if ( V_50 -> V_418 )
F_236 ( & V_50 -> V_420 , V_57 + V_415 ) ;
return 0 ;
}
static void F_246 ( struct V_49 * V_50 )
{
unsigned int V_192 ;
F_117 ( & V_50 -> V_187 ) ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 ) {
struct V_416 * V_141 , * V_266 ;
F_233 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_107
= F_78 ( V_141 , struct V_37 , V_172 ) ;
if ( ! F_34 ( V_107 -> V_70 ) )
F_107 ( V_50 , V_107 ) ;
}
}
F_118 ( & V_50 -> V_187 ) ;
}
static int F_247 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_31 * V_32 = F_20 ( V_50 -> V_29 , V_33 ) ;
struct V_24 * V_25 = V_50 -> V_201 ;
if ( V_25 && F_6 ( & V_50 -> V_51 . V_69 ) &&
! F_133 ( V_32 , V_50 ) ) {
F_135 ( V_25 ) ;
F_241 ( V_75 ) ;
F_139 ( V_204 , & V_50 -> V_215 ) ;
}
F_248 ( & V_50 -> V_420 ) ;
F_246 ( V_50 ) ;
return 0 ;
}
static void F_249 ( struct V_106 * V_75 )
{
}
static int F_250 ( struct V_106 * V_75 , int V_425 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_36 * V_342 = & V_50 -> V_51 ;
struct V_106 * V_426 ;
int V_427 ;
V_426 = F_114 ( V_50 -> V_29 , V_342 -> V_89 ) ;
if ( V_426 == NULL )
return F_251 ( V_75 , V_425 ) ;
if ( V_342 -> V_69 . V_4 . V_5 == V_6 )
V_427 = V_426 -> V_428 - V_429 ;
else
V_427 = V_426 -> V_428 - V_430 ;
if ( V_425 < 68 || V_425 > V_427 )
return - V_181 ;
V_75 -> V_428 = V_425 ;
return 0 ;
}
void F_252 ( struct V_106 * V_75 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_36 ( V_75 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_3 V_5 ;
T_2 V_30 ;
unsigned int V_304 ;
F_130 ( & V_32 -> V_203 ) ;
for ( V_304 = 0 ; V_304 < V_431 ; ++ V_304 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_45 -> V_46 ) -> V_47 ;
V_5 = V_25 -> V_45 -> V_46 -> V_48 ;
V_75 -> V_156 -> V_157 ( V_75 , V_5 ,
V_30 ) ;
}
}
F_132 ( & V_32 -> V_203 ) ;
}
static void F_253 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
unsigned int V_192 ;
F_254 ( V_75 ) ;
F_255 ( V_75 ) ;
if ( V_50 -> V_51 . V_69 . V_4 . V_5 == V_6 )
V_75 -> V_432 = V_245 + V_429 ;
else
V_75 -> V_432 = V_245 + V_430 ;
V_75 -> V_156 = & V_433 ;
V_75 -> V_434 = V_435 ;
F_256 ( V_75 , & V_436 ) ;
V_75 -> V_437 = 0 ;
V_75 -> V_438 |= V_439 ;
V_75 -> V_438 |= V_440 | V_441 ;
V_75 -> V_438 |= V_442 ;
V_75 -> V_438 |= V_443 ;
V_75 -> V_444 = V_75 -> V_438 ;
V_75 -> V_438 |= V_445 | V_446 ;
V_75 -> V_447 |= V_440 | V_441 | V_442 ;
V_75 -> V_447 |= V_443 ;
V_75 -> V_447 |= V_445 | V_446 ;
F_257 ( V_75 ) ;
V_75 -> V_448 |= V_449 ;
F_102 ( & V_50 -> V_40 ) ;
F_258 ( & V_50 -> V_187 ) ;
F_259 ( & V_50 -> V_208 , F_140 ) ;
F_259 ( & V_50 -> V_215 , F_145 ) ;
F_259 ( & V_50 -> V_423 , V_450 ) ;
F_260 ( & V_50 -> V_420 ) ;
V_50 -> V_420 . V_451 = F_232 ;
V_50 -> V_420 . V_123 = ( unsigned long ) V_50 ;
V_50 -> V_86 = F_153 ( V_452 ) ;
V_50 -> V_75 = V_75 ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 )
F_261 ( & V_50 -> V_115 [ V_192 ] ) ;
}
static int F_262 ( struct V_14 * V_178 [] , struct V_14 * V_123 [] )
{
if ( V_178 [ V_453 ] ) {
if ( F_11 ( V_178 [ V_453 ] ) != V_83 ) {
F_263 ( L_15 ) ;
return - V_181 ;
}
if ( ! F_264 ( F_265 ( V_178 [ V_453 ] ) ) ) {
F_263 ( L_16 ) ;
return - V_183 ;
}
}
if ( ! V_123 )
return - V_181 ;
if ( V_123 [ V_454 ] ) {
V_98 V_26 = F_113 ( V_123 [ V_454 ] ) ;
if ( V_26 >= V_455 )
return - V_456 ;
}
if ( V_123 [ V_457 ] ) {
const struct V_458 * V_141
= F_265 ( V_123 [ V_457 ] ) ;
if ( F_21 ( V_141 -> V_459 ) < F_21 ( V_141 -> V_460 ) ) {
F_263 ( L_17 ,
F_21 ( V_141 -> V_460 ) , F_21 ( V_141 -> V_459 ) ) ;
return - V_181 ;
}
}
return 0 ;
}
static void F_266 ( struct V_106 * V_461 ,
struct V_462 * V_463 )
{
F_267 ( V_463 -> V_313 , V_464 , sizeof( V_463 -> V_313 ) ) ;
F_267 ( V_463 -> V_465 , L_18 , sizeof( V_463 -> V_465 ) ) ;
}
static void F_268 ( struct V_206 * V_207 )
{
struct V_24 * V_25 = F_78 ( V_207 , struct V_24 , V_205 ) ;
F_269 ( V_25 -> V_45 ) ;
F_122 ( V_25 , V_175 ) ;
}
static struct V_466 * F_270 ( struct V_29 * V_29 , bool V_421 ,
T_2 V_30 , T_1 V_43 )
{
struct V_466 * V_45 ;
struct V_467 V_468 ;
int V_101 ;
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
if ( V_421 ) {
V_468 . V_42 = V_6 ;
V_468 . V_469 =
! ( V_43 & V_470 ) ;
} else {
V_468 . V_42 = V_18 ;
V_468 . V_471 . V_10 = V_12 ;
}
V_468 . V_472 = V_30 ;
V_101 = F_271 ( V_29 , & V_468 , & V_45 ) ;
if ( V_101 < 0 )
return F_272 ( V_101 ) ;
return V_45 ;
}
static struct V_24 * F_273 ( struct V_29 * V_29 , T_2 V_30 ,
T_10 * V_236 , void * V_123 ,
T_1 V_43 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_466 * V_45 ;
unsigned int V_192 ;
bool V_421 = ! ! ( V_43 & V_422 ) ;
struct V_473 V_474 ;
V_25 = F_274 ( sizeof( * V_25 ) , V_475 ) ;
if ( ! V_25 )
return F_272 ( - V_171 ) ;
for ( V_192 = 0 ; V_192 < V_476 ; ++ V_192 )
F_261 ( & V_25 -> V_27 [ V_192 ] ) ;
F_259 ( & V_25 -> V_205 , F_268 ) ;
V_45 = F_270 ( V_29 , V_421 , V_30 , V_43 ) ;
if ( F_206 ( V_45 ) ) {
F_106 ( V_25 ) ;
return F_275 ( V_45 ) ;
}
V_25 -> V_45 = V_45 ;
F_276 ( & V_25 -> V_202 , 1 ) ;
V_25 -> V_236 = V_236 ;
V_25 -> V_123 = V_123 ;
V_25 -> V_43 = ( V_43 & V_44 ) ;
V_25 -> V_147 . V_30 = V_30 ;
V_25 -> V_147 . V_477 . V_478 = F_77 ;
V_25 -> V_147 . V_477 . V_479 = F_87 ;
F_130 ( & V_32 -> V_203 ) ;
F_103 ( & V_25 -> V_172 , F_19 ( V_29 , V_30 ) ) ;
F_90 ( V_25 ) ;
F_132 ( & V_32 -> V_203 ) ;
V_474 . V_480 = V_25 ;
V_474 . V_481 = 1 ;
V_474 . V_482 = F_151 ;
V_474 . V_483 = NULL ;
F_277 ( V_29 , V_45 , & V_474 ) ;
return V_25 ;
}
struct V_24 * F_278 ( struct V_29 * V_29 , T_2 V_30 ,
T_10 * V_236 , void * V_123 ,
bool V_484 , T_1 V_43 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
bool V_421 = V_43 & V_422 ;
V_25 = F_273 ( V_29 , V_30 , V_236 , V_123 , V_43 ) ;
if ( ! F_206 ( V_25 ) )
return V_25 ;
if ( V_484 )
return V_25 ;
F_130 ( & V_32 -> V_203 ) ;
V_25 = F_26 ( V_29 , V_421 ? V_6 : V_18 , V_30 , V_43 ) ;
if ( V_25 && ( ( V_25 -> V_236 != V_236 ) ||
! F_240 ( & V_25 -> V_202 , 1 , 0 ) ) )
V_25 = F_272 ( - V_485 ) ;
F_132 ( & V_32 -> V_203 ) ;
if ( ! V_25 )
V_25 = F_272 ( - V_181 ) ;
return V_25 ;
}
static void V_450 ( struct V_206 * V_207 )
{
struct V_49 * V_50 = F_78 ( V_207 , struct V_49 , V_423 ) ;
struct V_29 * V_29 = V_50 -> V_29 ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_50 -> V_86 ;
struct V_24 * V_486 ;
V_486 = F_278 ( V_29 , V_30 , F_155 , NULL , false , V_50 -> V_43 ) ;
F_130 ( & V_32 -> V_203 ) ;
if ( ! F_206 ( V_486 ) )
F_237 ( V_486 , V_50 ) ;
F_132 ( & V_32 -> V_203 ) ;
F_144 ( V_50 -> V_75 ) ;
}
static int F_279 ( struct V_29 * V_487 , struct V_106 * V_75 ,
struct V_14 * V_178 [] , struct V_14 * V_123 [] )
{
struct V_31 * V_32 = F_20 ( V_487 , V_33 ) ;
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_36 * V_342 = & V_50 -> V_51 ;
V_98 V_117 ;
int V_101 ;
bool V_488 = false ;
if ( ! V_123 [ V_454 ] )
return - V_181 ;
V_50 -> V_29 = V_487 ;
V_117 = F_113 ( V_123 [ V_454 ] ) ;
V_342 -> V_52 = V_117 ;
V_342 -> V_69 . V_4 . V_5 = V_18 ;
if ( V_123 [ V_489 ] ) {
V_342 -> V_69 . sin . V_9 . V_10 = F_13 ( V_123 [ V_489 ] ) ;
} else if ( V_123 [ V_490 ] ) {
if ( ! F_111 ( V_179 ) )
return - V_491 ;
F_12 ( & V_342 -> V_69 . V_7 . V_8 , V_123 [ V_490 ] ,
sizeof( struct V_16 ) ) ;
V_342 -> V_69 . V_4 . V_5 = V_6 ;
V_488 = true ;
}
if ( V_123 [ V_492 ] ) {
V_50 -> V_243 . sin . V_9 . V_10 = F_13 ( V_123 [ V_492 ] ) ;
V_50 -> V_243 . V_4 . V_5 = V_18 ;
} else if ( V_123 [ V_493 ] ) {
if ( ! F_111 ( V_179 ) )
return - V_491 ;
F_12 ( & V_50 -> V_243 . V_7 . V_8 , V_123 [ V_493 ] ,
sizeof( struct V_16 ) ) ;
V_50 -> V_243 . V_4 . V_5 = V_6 ;
V_488 = true ;
}
if ( V_123 [ V_494 ] &&
( V_342 -> V_89 = F_113 ( V_123 [ V_494 ] ) ) ) {
struct V_106 * V_426
= F_114 ( V_487 , V_342 -> V_89 ) ;
if ( ! V_426 ) {
F_116 ( L_19 , V_342 -> V_89 ) ;
return - V_495 ;
}
#if F_111 ( V_179 )
if ( V_488 ) {
struct V_330 * V_496 = F_199 ( V_426 ) ;
if ( V_496 && V_496 -> V_497 . V_498 ) {
F_116 ( L_20 ) ;
return - V_499 ;
}
V_50 -> V_43 |= V_422 ;
}
#endif
if ( ! V_178 [ V_500 ] )
V_75 -> V_428 = V_426 -> V_428 - ( V_488 ? V_429 : V_430 ) ;
V_75 -> V_432 = V_426 -> V_501 +
( V_488 ? V_429 : V_430 ) ;
} else if ( V_488 )
V_50 -> V_43 |= V_422 ;
if ( V_123 [ V_502 ] )
V_50 -> V_251 = F_280 ( V_123 [ V_502 ] ) ;
if ( V_123 [ V_503 ] )
V_50 -> V_344 = F_280 ( V_123 [ V_503 ] ) ;
if ( ! V_123 [ V_504 ] || F_280 ( V_123 [ V_504 ] ) )
V_50 -> V_43 |= V_248 ;
if ( V_123 [ V_505 ] )
V_50 -> V_418 = F_113 ( V_123 [ V_505 ] ) ;
else
V_50 -> V_418 = V_506 ;
if ( V_123 [ V_507 ] && F_280 ( V_123 [ V_507 ] ) )
V_50 -> V_43 |= V_408 ;
if ( V_123 [ V_508 ] && F_280 ( V_123 [ V_508 ] ) )
V_50 -> V_43 |= V_409 ;
if ( V_123 [ V_509 ] && F_280 ( V_123 [ V_509 ] ) )
V_50 -> V_43 |= V_411 ;
if ( V_123 [ V_510 ] && F_280 ( V_123 [ V_510 ] ) )
V_50 -> V_43 |= V_292 ;
if ( V_123 [ V_511 ] )
V_50 -> V_168 = F_113 ( V_123 [ V_511 ] ) ;
if ( V_123 [ V_457 ] ) {
const struct V_458 * V_141
= F_265 ( V_123 [ V_457 ] ) ;
V_50 -> V_382 = F_21 ( V_141 -> V_460 ) ;
V_50 -> V_383 = F_21 ( V_141 -> V_459 ) ;
}
if ( V_123 [ V_512 ] )
V_50 -> V_86 = F_112 ( V_123 [ V_512 ] ) ;
if ( V_123 [ V_513 ] && F_280 ( V_123 [ V_513 ] ) )
V_50 -> V_43 |= V_367 ;
if ( V_123 [ V_514 ] &&
F_280 ( V_123 [ V_514 ] ) )
V_50 -> V_43 |= V_349 ;
if ( V_123 [ V_515 ] &&
F_280 ( V_123 [ V_515 ] ) )
V_50 -> V_43 |= V_470 ;
if ( V_123 [ V_516 ] &&
F_280 ( V_123 [ V_516 ] ) )
V_50 -> V_43 |= V_352 ;
if ( V_123 [ V_517 ] &&
F_280 ( V_123 [ V_517 ] ) )
V_50 -> V_43 |= V_151 ;
if ( V_123 [ V_518 ] )
V_50 -> V_43 |= V_227 ;
if ( V_123 [ V_519 ] )
V_50 -> V_43 |= V_153 ;
if ( F_30 ( V_487 , V_117 , V_488 ? V_6 : V_18 ,
V_50 -> V_86 , V_50 -> V_43 ) ) {
F_116 ( L_21 , V_117 ) ;
return - V_161 ;
}
V_75 -> V_520 = & V_521 ;
if ( ! F_3 ( & V_50 -> V_51 . V_69 ) ) {
V_101 = F_99 ( V_50 , V_410 ,
& V_50 -> V_51 . V_69 ,
V_186 | V_185 ,
V_160 | V_166 ,
V_50 -> V_86 ,
V_50 -> V_51 . V_52 ,
V_50 -> V_51 . V_89 ,
V_200 ) ;
if ( V_101 )
return V_101 ;
}
V_101 = F_281 ( V_75 ) ;
if ( V_101 ) {
F_242 ( V_50 ) ;
return V_101 ;
}
F_282 ( & V_50 -> V_40 , & V_32 -> V_522 ) ;
return 0 ;
}
static void F_283 ( struct V_106 * V_75 , struct V_523 * V_116 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
struct V_31 * V_32 = F_20 ( V_50 -> V_29 , V_33 ) ;
F_130 ( & V_32 -> V_203 ) ;
if ( ! F_284 ( & V_50 -> V_172 ) )
F_108 ( & V_50 -> V_172 ) ;
F_132 ( & V_32 -> V_203 ) ;
F_285 ( & V_50 -> V_40 ) ;
F_286 ( V_75 , V_116 ) ;
}
static T_4 F_287 ( const struct V_106 * V_75 )
{
return F_46 ( sizeof( V_98 ) ) +
F_46 ( sizeof( struct V_16 ) ) +
F_46 ( sizeof( V_98 ) ) +
F_46 ( sizeof( struct V_16 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( V_98 ) ) +
F_46 ( sizeof( V_98 ) ) +
F_46 ( sizeof( struct V_458 ) ) +
F_46 ( sizeof( T_2 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
F_46 ( sizeof( T_8 ) ) +
0 ;
}
static int F_288 ( struct V_20 * V_21 , const struct V_106 * V_75 )
{
const struct V_49 * V_50 = F_54 ( V_75 ) ;
const struct V_36 * V_342 = & V_50 -> V_51 ;
struct V_458 V_524 = {
. V_460 = F_153 ( V_50 -> V_382 ) ,
. V_459 = F_153 ( V_50 -> V_383 ) ,
} ;
if ( F_40 ( V_21 , V_454 , V_342 -> V_52 ) )
goto V_81;
if ( ! F_3 ( & V_342 -> V_69 ) ) {
if ( V_342 -> V_69 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_489 ,
V_342 -> V_69 . sin . V_9 . V_10 ) )
goto V_81;
#if F_111 ( V_179 )
} else {
if ( F_15 ( V_21 , V_490 , sizeof( struct V_16 ) ,
& V_342 -> V_69 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( V_342 -> V_89 && F_40 ( V_21 , V_494 , V_342 -> V_89 ) )
goto V_81;
if ( ! F_3 ( & V_50 -> V_243 ) ) {
if ( V_50 -> V_243 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_492 ,
V_50 -> V_243 . sin . V_9 . V_10 ) )
goto V_81;
#if F_111 ( V_179 )
} else {
if ( F_15 ( V_21 , V_493 , sizeof( struct V_16 ) ,
& V_50 -> V_243 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( F_289 ( V_21 , V_503 , V_50 -> V_344 ) ||
F_289 ( V_21 , V_502 , V_50 -> V_251 ) ||
F_289 ( V_21 , V_504 ,
! ! ( V_50 -> V_43 & V_248 ) ) ||
F_289 ( V_21 , V_507 ,
! ! ( V_50 -> V_43 & V_408 ) ) ||
F_289 ( V_21 , V_508 , ! ! ( V_50 -> V_43 & V_409 ) ) ||
F_289 ( V_21 , V_509 ,
! ! ( V_50 -> V_43 & V_411 ) ) ||
F_289 ( V_21 , V_510 ,
! ! ( V_50 -> V_43 & V_292 ) ) ||
F_40 ( V_21 , V_505 , V_50 -> V_418 ) ||
F_40 ( V_21 , V_511 , V_50 -> V_168 ) ||
F_39 ( V_21 , V_512 , V_50 -> V_86 ) ||
F_289 ( V_21 , V_513 ,
! ! ( V_50 -> V_43 & V_367 ) ) ||
F_289 ( V_21 , V_514 ,
! ! ( V_50 -> V_43 & V_349 ) ) ||
F_289 ( V_21 , V_515 ,
! ! ( V_50 -> V_43 & V_470 ) ) ||
F_289 ( V_21 , V_516 ,
! ! ( V_50 -> V_43 & V_352 ) ) ||
F_289 ( V_21 , V_517 ,
! ! ( V_50 -> V_43 & V_151 ) ) )
goto V_81;
if ( F_15 ( V_21 , V_457 , sizeof( V_524 ) , & V_524 ) )
goto V_81;
if ( V_50 -> V_43 & V_227 &&
F_290 ( V_21 , V_518 ) )
goto V_81;
if ( V_50 -> V_43 & V_153 &&
F_290 ( V_21 , V_519 ) )
goto V_81;
return 0 ;
V_81:
return - V_66 ;
}
static struct V_29 * F_291 ( const struct V_106 * V_75 )
{
struct V_49 * V_50 = F_54 ( V_75 ) ;
return V_50 -> V_29 ;
}
static void F_292 ( struct V_31 * V_32 ,
struct V_106 * V_75 )
{
struct V_49 * V_50 , * V_40 ;
F_293 ( V_525 ) ;
F_105 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_342 = & V_50 -> V_51 ;
if ( V_342 -> V_89 == V_75 -> V_76 )
F_283 ( V_50 -> V_75 , & V_525 ) ;
}
F_294 ( & V_525 ) ;
}
static int F_295 ( struct V_526 * V_527 ,
unsigned long V_528 , void * V_529 )
{
struct V_106 * V_75 = F_296 ( V_529 ) ;
struct V_31 * V_32 = F_20 ( F_36 ( V_75 ) , V_33 ) ;
if ( V_528 == V_530 )
F_292 ( V_32 , V_75 ) ;
return V_531 ;
}
static T_11 int F_297 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_192 ;
F_102 ( & V_32 -> V_522 ) ;
F_258 ( & V_32 -> V_203 ) ;
for ( V_192 = 0 ; V_192 < V_431 ; ++ V_192 )
F_261 ( & V_32 -> V_34 [ V_192 ] ) ;
return 0 ;
}
static void T_12 F_298 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_49 * V_50 , * V_40 ;
struct V_106 * V_75 , * V_532 ;
F_293 ( V_41 ) ;
F_299 () ;
F_300 (net, dev, aux)
if ( V_75 -> V_533 == & V_534 )
F_286 ( V_75 , & V_41 ) ;
F_105 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_35 ( F_36 ( V_50 -> V_75 ) , V_29 ) )
F_286 ( V_75 , & V_41 ) ;
}
F_294 ( & V_41 ) ;
F_301 () ;
}
static int T_13 F_302 ( void )
{
int V_163 ;
V_204 = F_303 ( L_18 , 0 , 0 ) ;
if ( ! V_204 )
return - V_171 ;
F_304 ( & V_535 , sizeof( V_535 ) ) ;
V_163 = F_305 ( & V_536 ) ;
if ( V_163 )
goto V_537;
V_163 = F_306 ( & V_538 ) ;
if ( V_163 )
goto V_539;
V_163 = F_307 ( & V_534 ) ;
if ( V_163 )
goto V_540;
return 0 ;
V_540:
F_308 ( & V_538 ) ;
V_539:
F_309 ( & V_536 ) ;
V_537:
F_310 ( V_204 ) ;
return V_163 ;
}
static void T_14 F_311 ( void )
{
F_312 ( & V_534 ) ;
F_308 ( & V_538 ) ;
F_310 ( V_204 ) ;
F_309 ( & V_536 ) ;
}
