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
V_13 -> V_7 . V_8 = F_12 ( V_15 ) ;
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
return F_15 ( V_21 , V_22 , & V_13 -> V_7 . V_8 ) ;
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
if ( V_65 && F_39 ( V_21 , V_82 , V_83 , & V_38 -> V_70 ) )
goto V_81;
if ( V_64 && F_14 ( V_21 , V_84 , & V_55 -> V_69 ) )
goto V_81;
if ( V_55 -> V_85 && V_55 -> V_85 != V_50 -> V_86 &&
F_40 ( V_21 , V_87 , V_55 -> V_85 ) )
goto V_81;
if ( V_55 -> V_52 != V_50 -> V_51 . V_52 &&
F_41 ( V_21 , V_88 , V_55 -> V_52 ) )
goto V_81;
if ( V_55 -> V_89 &&
F_41 ( V_21 , V_90 , V_55 -> V_89 ) )
goto V_81;
V_59 . V_91 = F_42 ( V_56 - V_38 -> V_92 ) ;
V_59 . V_93 = 0 ;
V_59 . V_94 = F_42 ( V_56 - V_38 -> V_95 ) ;
V_59 . V_96 = 0 ;
if ( F_39 ( V_21 , V_97 , sizeof( V_59 ) , & V_59 ) )
goto V_81;
F_43 ( V_21 , V_61 ) ;
return 0 ;
V_81:
F_44 ( V_21 , V_61 ) ;
return - V_66 ;
}
static inline T_4 F_45 ( void )
{
return F_46 ( sizeof( struct V_62 ) )
+ F_47 ( V_83 )
+ F_47 ( sizeof( struct V_16 ) )
+ F_47 ( sizeof( T_2 ) )
+ F_47 ( sizeof( V_17 ) )
+ F_47 ( sizeof( V_98 ) )
+ F_47 ( sizeof( V_99 ) )
+ F_47 ( sizeof( struct V_58 ) ) ;
}
static void F_48 ( struct V_49 * V_50 , struct V_37 * V_38 ,
struct V_36 * V_100 , int type )
{
struct V_29 * V_29 = F_36 ( V_50 -> V_75 ) ;
struct V_20 * V_21 ;
int V_101 = - V_102 ;
V_21 = F_49 ( F_45 () , V_103 ) ;
if ( V_21 == NULL )
goto V_104;
V_101 = F_31 ( V_21 , V_50 , V_38 , 0 , 0 , type , 0 , V_100 ) ;
if ( V_101 < 0 ) {
F_50 ( V_101 == - V_66 ) ;
F_51 ( V_21 ) ;
goto V_104;
}
F_52 ( V_21 , V_29 , 0 , V_105 , NULL , V_103 ) ;
return;
V_104:
if ( V_101 < 0 )
F_53 ( V_29 , V_105 , V_101 ) ;
}
static void F_54 ( struct V_106 * V_75 , union V_1 * V_11 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_37 V_107 = {
. V_73 = V_108 ,
} ;
struct V_36 V_109 = {
. V_69 = * V_11 ,
. V_52 = V_110 ,
} ;
F_48 ( V_50 , & V_107 , & V_109 , V_67 ) ;
}
static void F_56 ( struct V_49 * V_50 , const T_5 V_70 [ V_83 ] )
{
struct V_37 V_107 = {
. V_73 = V_108 ,
} ;
struct V_36 V_109 = { } ;
memcpy ( V_107 . V_70 , V_70 , V_83 ) ;
F_48 ( V_50 , & V_107 , & V_109 , V_67 ) ;
}
static T_1 F_57 ( const unsigned char * V_111 )
{
T_6 V_112 = F_58 ( ( T_6 * ) V_111 ) ;
#ifdef F_59
V_112 >>= 16 ;
#else
V_112 <<= 16 ;
#endif
return F_60 ( V_112 , V_113 ) ;
}
static inline struct V_23 * F_61 ( struct V_49 * V_50 ,
const T_5 * V_114 )
{
return & V_50 -> V_115 [ F_57 ( V_114 ) ] ;
}
static struct V_37 * F_62 ( struct V_49 * V_50 ,
const T_5 * V_114 )
{
struct V_23 * V_116 = F_61 ( V_50 , V_114 ) ;
struct V_37 * V_107 ;
F_27 (f, head, hlist) {
if ( F_63 ( V_114 , V_107 -> V_70 ) )
return V_107 ;
}
return NULL ;
}
static struct V_37 * F_64 ( struct V_49 * V_50 ,
const T_5 * V_114 )
{
struct V_37 * V_107 ;
V_107 = F_62 ( V_50 , V_114 ) ;
if ( V_107 )
V_107 -> V_92 = V_57 ;
return V_107 ;
}
static struct V_36 * F_65 ( struct V_37 * V_107 ,
union V_1 * V_13 , T_2 V_30 ,
V_98 V_117 , V_98 V_76 )
{
struct V_36 * V_100 ;
F_66 (rd, &f->remotes, list) {
if ( F_1 ( & V_100 -> V_69 , V_13 ) &&
V_100 -> V_85 == V_30 &&
V_100 -> V_52 == V_117 &&
V_100 -> V_89 == V_76 )
return V_100 ;
}
return NULL ;
}
static int F_67 ( struct V_37 * V_107 ,
union V_1 * V_13 , T_2 V_30 , V_98 V_117 , V_98 V_76 )
{
struct V_36 * V_100 ;
V_100 = F_65 ( V_107 , V_13 , V_30 , V_117 , V_76 ) ;
if ( V_100 )
return 0 ;
V_100 = F_68 ( & V_107 -> V_39 , struct V_36 , V_41 ) ;
if ( ! V_100 )
return 0 ;
V_100 -> V_69 = * V_13 ;
V_100 -> V_85 = V_30 ;
V_100 -> V_52 = V_117 ;
V_100 -> V_89 = V_76 ;
return 1 ;
}
static int F_69 ( struct V_37 * V_107 ,
union V_1 * V_13 , T_2 V_30 , V_98 V_117 ,
V_98 V_76 , struct V_36 * * V_118 )
{
struct V_36 * V_100 ;
V_100 = F_65 ( V_107 , V_13 , V_30 , V_117 , V_76 ) ;
if ( V_100 )
return 0 ;
V_100 = F_70 ( sizeof( * V_100 ) , V_103 ) ;
if ( V_100 == NULL )
return - V_102 ;
V_100 -> V_69 = * V_13 ;
V_100 -> V_85 = V_30 ;
V_100 -> V_52 = V_117 ;
V_100 -> V_89 = V_76 ;
F_71 ( & V_100 -> V_41 , & V_107 -> V_39 ) ;
* V_118 = V_100 ;
return 1 ;
}
static struct V_119 * F_72 ( struct V_20 * V_21 ,
unsigned int V_120 ,
struct V_119 * V_121 , T_4 V_122 ,
T_1 V_123 , struct V_124 * V_125 ,
bool V_126 )
{
T_4 V_127 , V_128 , V_129 ;
if ( V_21 -> V_130 )
return NULL ;
if ( ! F_73 ( V_21 ) -> V_131 )
return NULL ;
V_127 = ( V_123 & V_132 ) << V_133 ;
V_128 = V_127 + ( ( V_123 & V_134 ) ?
F_74 ( struct V_135 , V_136 ) :
F_74 ( struct V_137 , V_136 ) ) ;
V_129 = V_122 + V_128 + sizeof( V_138 ) ;
if ( F_75 ( V_21 , V_120 + V_129 ) ) {
V_121 = F_76 ( V_21 , V_120 + V_129 , V_120 ) ;
if ( ! V_121 )
return NULL ;
}
F_77 ( V_21 , ( void * ) V_121 + V_122 ,
V_127 , V_128 , V_125 , V_126 ) ;
V_21 -> V_130 = 1 ;
return V_121 ;
}
static struct V_20 * * F_78 ( struct V_20 * * V_116 ,
struct V_20 * V_21 ,
struct V_139 * V_140 )
{
struct V_20 * V_141 , * * V_142 = NULL ;
struct V_119 * V_121 , * V_143 ;
unsigned int V_144 , V_145 ;
int V_146 = 1 ;
struct V_24 * V_25 = F_79 ( V_140 , struct V_24 ,
V_147 ) ;
T_1 V_43 ;
struct V_124 V_125 ;
F_80 ( & V_125 ) ;
V_145 = F_81 ( V_21 ) ;
V_144 = V_145 + sizeof( * V_121 ) ;
V_121 = F_82 ( V_21 , V_145 ) ;
if ( F_75 ( V_21 , V_144 ) ) {
V_121 = F_76 ( V_21 , V_144 , V_145 ) ;
if ( F_83 ( ! V_121 ) )
goto V_148;
}
F_84 ( V_21 , sizeof( struct V_119 ) ) ;
F_85 ( V_21 , V_121 , sizeof( struct V_119 ) ) ;
V_43 = F_9 ( V_121 -> V_149 ) ;
if ( ( V_43 & V_150 ) && ( V_25 -> V_43 & V_151 ) ) {
V_121 = F_72 ( V_21 , V_145 , V_121 , sizeof( struct V_119 ) ,
F_9 ( V_121 -> V_152 ) , & V_125 ,
! ! ( V_25 -> V_43 &
V_153 ) ) ;
if ( ! V_121 )
goto V_148;
}
V_146 = 0 ;
for ( V_141 = * V_116 ; V_141 ; V_141 = V_141 -> V_40 ) {
if ( ! F_73 ( V_141 ) -> V_154 )
continue;
V_143 = (struct V_119 * ) ( V_141 -> V_123 + V_145 ) ;
if ( V_121 -> V_149 != V_143 -> V_149 ||
V_121 -> V_152 != V_143 -> V_152 ) {
F_73 ( V_141 ) -> V_154 = 0 ;
continue;
}
}
V_142 = F_86 ( V_116 , V_21 ) ;
V_148:
F_87 ( V_21 , & V_125 ) ;
F_73 ( V_21 ) -> V_146 |= V_146 ;
return V_142 ;
}
static int F_88 ( struct V_20 * V_21 , int V_155 ,
struct V_139 * V_140 )
{
F_89 ( V_21 , V_155 ) ;
return F_90 ( V_21 , V_155 + sizeof( struct V_119 ) ) ;
}
static void F_91 ( struct V_24 * V_25 )
{
struct V_106 * V_75 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
struct V_29 * V_29 = F_92 ( V_46 ) ;
T_3 V_5 = V_46 -> V_48 ;
T_2 V_30 = F_28 ( V_46 ) -> V_47 ;
int V_101 ;
if ( V_5 == V_18 ) {
V_101 = F_93 ( & V_25 -> V_147 ) ;
if ( V_101 )
F_94 ( L_1 , V_101 ) ;
}
F_95 () ;
F_96 (net, dev) {
if ( V_75 -> V_156 -> V_157 )
V_75 -> V_156 -> V_157 ( V_75 , V_5 ,
V_30 ) ;
}
F_97 () ;
}
static void F_98 ( struct V_24 * V_25 )
{
struct V_106 * V_75 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
struct V_29 * V_29 = F_92 ( V_46 ) ;
T_3 V_5 = V_46 -> V_48 ;
T_2 V_30 = F_28 ( V_46 ) -> V_47 ;
F_95 () ;
F_96 (net, dev) {
if ( V_75 -> V_156 -> V_158 )
V_75 -> V_156 -> V_158 ( V_75 , V_5 ,
V_30 ) ;
}
F_97 () ;
if ( V_5 == V_18 )
F_99 ( & V_25 -> V_147 ) ;
}
static int F_100 ( struct V_49 * V_50 ,
const T_5 * V_114 , union V_1 * V_13 ,
T_7 V_73 , T_7 V_43 ,
T_2 V_30 , V_98 V_117 , V_98 V_76 ,
T_8 V_77 )
{
struct V_36 * V_100 = NULL ;
struct V_37 * V_107 ;
int V_159 = 0 ;
V_107 = F_62 ( V_50 , V_114 ) ;
if ( V_107 ) {
if ( V_43 & V_160 ) {
F_101 ( V_50 -> V_75 ,
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
if ( ! ( F_102 ( V_107 -> V_70 ) ||
F_34 ( V_107 -> V_70 ) ) ) {
V_159 |= F_67 ( V_107 , V_13 , V_30 , V_117 ,
V_76 ) ;
} else
return - V_163 ;
}
if ( ( V_43 & V_164 ) &&
( F_102 ( V_107 -> V_70 ) ||
F_34 ( V_107 -> V_70 ) ) ) {
int V_165 = F_69 ( V_107 , V_13 , V_30 , V_117 , V_76 ,
& V_100 ) ;
if ( V_165 < 0 )
return V_165 ;
V_159 |= V_165 ;
}
} else {
if ( ! ( V_43 & V_166 ) )
return - V_167 ;
if ( V_50 -> V_168 && V_50 -> V_169 >= V_50 -> V_168 )
return - V_170 ;
if ( ( V_43 & V_162 ) &&
( F_102 ( V_114 ) || F_34 ( V_114 ) ) )
return - V_163 ;
F_101 ( V_50 -> V_75 , L_3 , V_114 , V_13 ) ;
V_107 = F_70 ( sizeof( * V_107 ) , V_103 ) ;
if ( ! V_107 )
return - V_171 ;
V_159 = 1 ;
V_107 -> V_73 = V_73 ;
V_107 -> V_43 = V_77 ;
V_107 -> V_95 = V_107 -> V_92 = V_57 ;
F_103 ( & V_107 -> V_39 ) ;
memcpy ( V_107 -> V_70 , V_114 , V_83 ) ;
F_69 ( V_107 , V_13 , V_30 , V_117 , V_76 , & V_100 ) ;
++ V_50 -> V_169 ;
F_104 ( & V_107 -> V_172 ,
F_61 ( V_50 , V_114 ) ) ;
}
if ( V_159 ) {
if ( V_100 == NULL )
V_100 = F_24 ( V_107 ) ;
F_48 ( V_50 , V_107 , V_100 , V_173 ) ;
}
return 0 ;
}
static void F_105 ( struct V_174 * V_116 )
{
struct V_37 * V_107 = F_79 ( V_116 , struct V_37 , V_175 ) ;
struct V_36 * V_100 , * V_176 ;
F_106 (rd, nd, &f->remotes, list)
F_107 ( V_100 ) ;
F_107 ( V_107 ) ;
}
static void F_108 ( struct V_49 * V_50 , struct V_37 * V_107 )
{
F_101 ( V_50 -> V_75 ,
L_4 , V_107 -> V_70 ) ;
-- V_50 -> V_169 ;
F_48 ( V_50 , V_107 , F_24 ( V_107 ) , V_177 ) ;
F_109 ( & V_107 -> V_172 ) ;
F_110 ( & V_107 -> V_175 , F_105 ) ;
}
static int F_111 ( struct V_14 * V_178 [] , struct V_49 * V_50 ,
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
#if F_112 ( V_179 )
} else {
V_13 -> V_7 . V_8 = V_180 ;
V_13 -> V_4 . V_5 = V_6 ;
#endif
}
}
if ( V_178 [ V_87 ] ) {
if ( F_11 ( V_178 [ V_87 ] ) != sizeof( T_2 ) )
return - V_181 ;
* V_30 = F_113 ( V_178 [ V_87 ] ) ;
} else {
* V_30 = V_50 -> V_86 ;
}
if ( V_178 [ V_88 ] ) {
if ( F_11 ( V_178 [ V_88 ] ) != sizeof( T_1 ) )
return - V_181 ;
* V_117 = F_114 ( V_178 [ V_88 ] ) ;
} else {
* V_117 = V_50 -> V_51 . V_52 ;
}
if ( V_178 [ V_90 ] ) {
struct V_106 * V_182 ;
if ( F_11 ( V_178 [ V_90 ] ) != sizeof( T_1 ) )
return - V_181 ;
* V_76 = F_114 ( V_178 [ V_90 ] ) ;
V_182 = F_115 ( V_29 , * V_76 ) ;
if ( ! V_182 )
return - V_183 ;
} else {
* V_76 = 0 ;
}
return 0 ;
}
static int F_116 ( struct V_62 * V_63 , struct V_14 * V_178 [] ,
struct V_106 * V_75 ,
const unsigned char * V_111 , V_138 V_184 , V_138 V_43 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_117 , V_76 ;
int V_101 ;
if ( ! ( V_63 -> V_72 & ( V_185 | V_186 ) ) ) {
F_117 ( L_5 ,
V_63 -> V_72 ) ;
return - V_181 ;
}
if ( V_178 [ V_84 ] == NULL )
return - V_181 ;
V_101 = F_111 ( V_178 , V_50 , & V_13 , & V_30 , & V_117 , & V_76 ) ;
if ( V_101 )
return V_101 ;
if ( V_50 -> V_51 . V_69 . V_4 . V_5 != V_13 . V_4 . V_5 )
return - V_19 ;
F_118 ( & V_50 -> V_187 ) ;
V_101 = F_100 ( V_50 , V_111 , & V_13 , V_63 -> V_72 , V_43 ,
V_30 , V_117 , V_76 , V_63 -> V_77 ) ;
F_119 ( & V_50 -> V_187 ) ;
return V_101 ;
}
static int F_120 ( struct V_62 * V_63 , struct V_14 * V_178 [] ,
struct V_106 * V_75 ,
const unsigned char * V_111 , V_138 V_184 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_37 * V_107 ;
struct V_36 * V_100 = NULL ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_117 , V_76 ;
int V_101 ;
V_101 = F_111 ( V_178 , V_50 , & V_13 , & V_30 , & V_117 , & V_76 ) ;
if ( V_101 )
return V_101 ;
V_101 = - V_167 ;
F_118 ( & V_50 -> V_187 ) ;
V_107 = F_64 ( V_50 , V_111 ) ;
if ( ! V_107 )
goto V_148;
if ( ! F_3 ( & V_13 ) ) {
V_100 = F_65 ( V_107 , & V_13 , V_30 , V_117 , V_76 ) ;
if ( ! V_100 )
goto V_148;
}
V_101 = 0 ;
if ( V_100 && ! F_121 ( & V_107 -> V_39 ) ) {
F_122 ( & V_100 -> V_41 ) ;
F_48 ( V_50 , V_107 , V_100 , V_177 ) ;
F_123 ( V_100 , V_175 ) ;
goto V_148;
}
F_108 ( V_50 , V_107 ) ;
V_148:
F_119 ( & V_50 -> V_187 ) ;
return V_101 ;
}
static int F_124 ( struct V_20 * V_21 , struct V_188 * V_189 ,
struct V_106 * V_75 ,
struct V_106 * V_190 , int V_191 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
unsigned int V_192 ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 ) {
struct V_37 * V_107 ;
int V_101 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_100 ;
if ( V_191 < V_189 -> args [ 0 ] )
goto V_194;
F_125 (rd, &f->remotes, list) {
V_101 = F_31 ( V_21 , V_50 , V_107 ,
F_126 ( V_189 -> V_21 ) . V_53 ,
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
static bool F_127 ( struct V_106 * V_75 ,
union V_1 * V_197 , const T_5 * V_198 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_37 * V_107 ;
V_107 = F_64 ( V_50 , V_198 ) ;
if ( F_128 ( V_107 ) ) {
struct V_36 * V_55 = F_22 ( V_107 ) ;
if ( F_128 ( F_1 ( & V_55 -> V_69 , V_197 ) ) )
return false ;
if ( V_107 -> V_73 & V_199 )
return true ;
if ( F_129 () )
F_130 ( V_75 ,
L_6 ,
V_198 , & V_55 -> V_69 . V_4 , & V_197 -> V_4 ) ;
V_55 -> V_69 = * V_197 ;
V_107 -> V_95 = V_57 ;
F_48 ( V_50 , V_107 , V_55 , V_173 ) ;
} else {
F_131 ( & V_50 -> V_187 ) ;
if ( F_132 ( V_75 ) )
F_100 ( V_50 , V_198 , V_197 ,
V_186 ,
V_160 | V_166 ,
V_50 -> V_86 ,
V_50 -> V_51 . V_52 ,
0 , V_200 ) ;
F_133 ( & V_50 -> V_187 ) ;
}
return false ;
}
static bool F_134 ( struct V_31 * V_32 , struct V_49 * V_75 )
{
struct V_49 * V_50 ;
if ( F_135 ( & V_75 -> V_201 -> V_202 ) == 1 )
return false ;
F_66 (vxlan, &vn->vxlan_list, next) {
if ( ! F_132 ( V_50 -> V_75 ) || V_50 == V_75 )
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
void F_136 ( struct V_24 * V_25 )
{
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
struct V_29 * V_29 = F_92 ( V_46 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_137 ( & V_25 -> V_202 ) )
return;
F_131 ( & V_32 -> V_203 ) ;
F_109 ( & V_25 -> V_172 ) ;
F_98 ( V_25 ) ;
F_133 ( & V_32 -> V_203 ) ;
F_138 ( V_204 , & V_25 -> V_205 ) ;
}
static int F_139 ( struct V_49 * V_50 )
{
struct V_24 * V_25 = V_50 -> V_201 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
union V_1 * V_13 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_89 ;
int V_206 = - V_181 ;
F_140 ( V_46 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_207 V_208 = {
. V_209 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_210 = V_76 ,
} ;
V_206 = F_141 ( V_46 , & V_208 ) ;
#if F_112 ( V_179 )
} else {
V_206 = V_211 -> V_212 ( V_46 , V_76 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_142 ( V_46 ) ;
return V_206 ;
}
static int F_143 ( struct V_49 * V_50 )
{
struct V_24 * V_25 = V_50 -> V_201 ;
struct V_45 * V_46 = V_25 -> V_45 -> V_46 ;
union V_1 * V_13 = & V_50 -> V_51 . V_69 ;
int V_76 = V_50 -> V_51 . V_89 ;
int V_206 = - V_181 ;
F_140 ( V_46 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_207 V_208 = {
. V_209 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_210 = V_76 ,
} ;
V_206 = F_144 ( V_46 , & V_208 ) ;
#if F_112 ( V_179 )
} else {
V_206 = V_211 -> V_213 ( V_46 , V_76 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_142 ( V_46 ) ;
return V_206 ;
}
static struct V_119 * F_145 ( struct V_20 * V_21 , struct V_119 * V_121 ,
T_4 V_122 , T_1 V_123 , bool V_126 )
{
T_4 V_127 , V_128 , V_129 ;
V_127 = ( V_123 & V_132 ) << V_133 ;
V_128 = V_127 + ( ( V_123 & V_134 ) ?
F_74 ( struct V_135 , V_136 ) :
F_74 ( struct V_137 , V_136 ) ) ;
V_129 = V_122 + V_128 + sizeof( V_138 ) ;
if ( ! F_146 ( V_21 , V_129 ) )
return NULL ;
V_121 = (struct V_119 * ) ( F_147 ( V_21 ) + 1 ) ;
F_148 ( V_21 , ( void * ) V_121 + V_122 , V_127 , V_128 ,
V_126 ) ;
return V_121 ;
}
static int F_149 ( struct V_45 * V_46 , struct V_20 * V_21 )
{
struct V_24 * V_25 ;
struct V_119 * V_214 ;
T_1 V_43 , V_117 ;
struct V_215 V_216 = { 0 } ;
if ( ! F_146 ( V_21 , V_217 ) )
goto error;
V_214 = (struct V_119 * ) ( F_147 ( V_21 ) + 1 ) ;
V_43 = F_9 ( V_214 -> V_149 ) ;
V_117 = F_9 ( V_214 -> V_152 ) ;
if ( V_43 & V_218 ) {
V_43 &= ~ V_218 ;
} else {
goto V_219;
}
if ( F_150 ( V_21 , V_217 , F_151 ( V_220 ) ) )
goto V_221;
V_214 = (struct V_119 * ) ( F_147 ( V_21 ) + 1 ) ;
V_25 = F_152 ( V_46 ) ;
if ( ! V_25 )
goto V_221;
if ( ( V_43 & V_150 ) && ( V_25 -> V_43 & V_151 ) ) {
V_214 = F_145 ( V_21 , V_214 , sizeof( struct V_119 ) , V_117 ,
! ! ( V_25 -> V_43 & V_153 ) ) ;
if ( ! V_214 )
goto V_221;
V_43 &= ~ V_150 ;
V_117 &= V_222 ;
}
if ( ( V_43 & V_223 ) && ( V_25 -> V_43 & V_224 ) ) {
struct V_225 * V_226 ;
V_226 = (struct V_225 * ) V_214 ;
V_216 . V_226 = F_21 ( V_226 -> V_227 ) ;
if ( V_226 -> V_228 )
V_216 . V_226 |= V_229 ;
if ( V_226 -> V_230 )
V_216 . V_226 |= V_231 ;
V_43 &= ~ V_232 ;
}
if ( V_43 || V_117 & ~ V_222 ) {
goto V_219;
}
V_216 . V_117 = V_214 -> V_152 ;
V_25 -> V_233 ( V_25 , V_21 , & V_216 ) ;
return 0 ;
V_221:
F_51 ( V_21 ) ;
return 0 ;
V_219:
F_101 ( V_21 -> V_75 , L_7 ,
F_9 ( V_214 -> V_149 ) , F_9 ( V_214 -> V_152 ) ) ;
error:
return 1 ;
}
static void F_153 ( struct V_24 * V_25 , struct V_20 * V_21 ,
struct V_215 * V_216 )
{
struct V_234 * V_235 = NULL ;
struct V_236 * V_237 = NULL ;
struct V_49 * V_50 ;
struct V_238 * V_239 ;
union V_1 V_240 ;
V_98 V_117 ;
int V_101 = 0 ;
union V_1 * V_69 ;
V_117 = F_9 ( V_216 -> V_117 ) >> 8 ;
V_50 = F_29 ( V_25 , V_117 ) ;
if ( ! V_50 )
goto V_221;
V_69 = & V_50 -> V_51 . V_69 ;
F_154 ( V_21 ) ;
F_155 ( V_21 , ! F_35 ( V_50 -> V_29 , F_36 ( V_50 -> V_75 ) ) ) ;
V_21 -> V_241 = F_156 ( V_21 , V_50 -> V_75 ) ;
F_157 ( V_21 , F_158 ( V_21 ) , V_242 ) ;
if ( F_63 ( F_158 ( V_21 ) -> V_243 , V_50 -> V_75 -> V_244 ) )
goto V_221;
if ( V_69 -> V_4 . V_5 == V_18 ) {
V_235 = F_159 ( V_21 ) ;
V_240 . sin . V_9 . V_10 = V_235 -> V_240 ;
V_240 . V_4 . V_5 = V_18 ;
#if F_112 ( V_179 )
} else {
V_237 = F_160 ( V_21 ) ;
V_240 . V_7 . V_8 = V_237 -> V_240 ;
V_240 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_50 -> V_43 & V_245 ) &&
F_127 ( V_21 -> V_75 , & V_240 , F_158 ( V_21 ) -> V_243 ) )
goto V_221;
F_161 ( V_21 ) ;
V_21 -> V_246 = V_216 -> V_226 ;
if ( V_237 )
V_101 = F_162 ( V_237 , V_21 ) ;
if ( V_235 )
V_101 = F_163 ( V_235 , V_21 ) ;
if ( F_83 ( V_101 ) ) {
if ( V_247 ) {
if ( V_237 )
F_164 ( L_8 ,
& V_237 -> V_240 ) ;
if ( V_235 )
F_164 ( L_9 ,
& V_235 -> V_240 , V_235 -> V_248 ) ;
}
if ( V_101 > 1 ) {
++ V_50 -> V_75 -> V_239 . V_249 ;
++ V_50 -> V_75 -> V_239 . V_250 ;
goto V_221;
}
}
V_239 = F_165 ( V_50 -> V_75 -> V_251 ) ;
F_166 ( & V_239 -> V_252 ) ;
V_239 -> V_253 ++ ;
V_239 -> V_254 += V_21 -> V_255 ;
F_167 ( & V_239 -> V_252 ) ;
F_168 ( V_21 ) ;
return;
V_221:
F_51 ( V_21 ) ;
}
static int F_169 ( struct V_106 * V_75 , struct V_20 * V_21 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_256 * V_257 ;
T_5 * V_258 , * V_259 ;
V_17 V_260 , V_261 ;
struct V_262 * V_263 ;
if ( V_75 -> V_43 & V_264 )
goto V_148;
if ( ! F_146 ( V_21 , F_170 ( V_75 ) ) ) {
V_75 -> V_239 . V_265 ++ ;
goto V_148;
}
V_257 = F_171 ( V_21 ) ;
if ( ( V_257 -> V_266 != F_151 ( V_267 ) &&
V_257 -> V_266 != F_151 ( V_268 ) ) ||
V_257 -> V_269 != F_151 ( V_270 ) ||
V_257 -> V_271 != F_151 ( V_272 ) ||
V_257 -> V_273 != V_75 -> V_274 ||
V_257 -> V_275 != 4 )
goto V_148;
V_258 = ( T_5 * ) V_257 + sizeof( struct V_256 ) ;
V_259 = V_258 ;
V_258 += V_75 -> V_274 ;
memcpy ( & V_260 , V_258 , sizeof( V_260 ) ) ;
V_258 += sizeof( V_260 ) ;
V_258 += V_75 -> V_274 ;
memcpy ( & V_261 , V_258 , sizeof( V_261 ) ) ;
if ( F_172 ( V_261 ) ||
F_173 ( V_261 ) )
goto V_148;
V_263 = F_174 ( & V_276 , & V_261 , V_75 ) ;
if ( V_263 ) {
struct V_37 * V_107 ;
struct V_20 * V_277 ;
if ( ! ( V_263 -> V_278 & V_279 ) ) {
F_175 ( V_263 ) ;
goto V_148;
}
V_107 = F_64 ( V_50 , V_263 -> V_280 ) ;
if ( V_107 && F_3 ( & ( F_22 ( V_107 ) -> V_69 ) ) ) {
F_175 ( V_263 ) ;
goto V_148;
}
V_277 = F_176 ( V_281 , V_282 , V_260 , V_75 , V_261 , V_259 ,
V_263 -> V_280 , V_259 ) ;
F_175 ( V_263 ) ;
if ( V_277 == NULL )
goto V_148;
F_154 ( V_277 ) ;
F_177 ( V_277 , F_178 ( V_277 ) ) ;
V_277 -> V_283 = V_284 ;
V_277 -> V_285 = V_286 ;
if ( F_179 ( V_277 ) == V_287 )
V_75 -> V_239 . V_288 ++ ;
} else if ( V_50 -> V_43 & V_289 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_261 ,
. sin . V_290 = V_18 ,
} ;
F_54 ( V_75 , & V_11 ) ;
}
V_148:
F_180 ( V_21 ) ;
return V_291 ;
}
static struct V_20 * F_181 ( struct V_20 * V_292 ,
struct V_262 * V_263 , bool V_293 )
{
struct V_106 * V_75 = V_292 -> V_75 ;
struct V_20 * V_277 ;
struct V_294 * V_295 , * V_296 ;
struct V_236 * V_297 ;
T_5 * V_298 ;
int V_299 = 8 ;
int V_300 ;
int V_301 , V_255 ;
if ( V_75 == NULL )
return NULL ;
V_255 = F_182 ( V_75 ) + sizeof( struct V_236 ) +
sizeof( * V_296 ) + V_299 + V_75 -> V_302 ;
V_277 = F_183 ( V_255 , V_103 ) ;
if ( V_277 == NULL )
return NULL ;
V_277 -> V_241 = F_151 ( V_303 ) ;
V_277 -> V_75 = V_75 ;
F_184 ( V_277 , F_182 ( V_292 -> V_75 ) ) ;
F_185 ( V_277 , sizeof( struct V_304 ) ) ;
F_186 ( V_277 , 0 ) ;
V_295 = (struct V_294 * ) F_187 ( V_292 ) ;
V_298 = F_158 ( V_292 ) -> V_243 ;
V_300 = V_292 -> V_255 - F_188 ( V_292 ) - sizeof( * V_295 ) ;
for ( V_301 = 0 ; V_301 < V_300 - 1 ; V_301 += ( V_295 -> V_305 [ V_301 + 1 ] << 3 ) ) {
if ( V_295 -> V_305 [ V_301 ] == V_306 ) {
V_298 = V_295 -> V_305 + V_301 + sizeof( struct V_307 ) ;
break;
}
}
F_189 ( F_158 ( V_277 ) -> V_308 , V_298 ) ;
F_189 ( F_158 ( V_277 ) -> V_243 , V_263 -> V_280 ) ;
F_158 ( V_277 ) -> V_309 = F_151 ( V_303 ) ;
V_277 -> V_241 = F_151 ( V_303 ) ;
F_190 ( V_277 , sizeof( struct V_304 ) ) ;
F_191 ( V_277 , 0 ) ;
F_192 ( V_277 , sizeof( struct V_236 ) ) ;
V_297 = F_160 ( V_277 ) ;
memset ( V_297 , 0 , sizeof( struct V_236 ) ) ;
V_297 -> V_310 = 6 ;
V_297 -> V_311 = F_160 ( V_292 ) -> V_311 ;
V_297 -> V_312 = V_313 ;
V_297 -> V_314 = 255 ;
V_297 -> V_298 = F_160 ( V_292 ) -> V_240 ;
V_297 -> V_240 = * (struct V_16 * ) V_263 -> V_315 ;
F_190 ( V_277 , sizeof( struct V_236 ) ) ;
F_193 ( V_277 , 0 ) ;
V_296 = (struct V_294 * ) F_192 ( V_277 , sizeof( * V_296 ) + V_299 ) ;
memset ( V_296 , 0 , sizeof( * V_296 ) + V_299 ) ;
V_296 -> V_316 . V_317 = V_318 ;
V_296 -> V_316 . V_319 = V_293 ;
V_296 -> V_316 . V_320 = 1 ;
V_296 -> V_316 . V_321 = 1 ;
V_296 -> V_322 = V_295 -> V_322 ;
F_189 ( & V_296 -> V_305 [ 2 ] , V_263 -> V_280 ) ;
V_296 -> V_305 [ 0 ] = V_323 ;
V_296 -> V_305 [ 1 ] = V_299 >> 3 ;
V_296 -> V_316 . V_324 = F_194 ( & V_297 -> V_240 ,
& V_297 -> V_298 , sizeof( * V_296 ) + V_299 , V_313 ,
F_195 ( V_296 , sizeof( * V_296 ) + V_299 , 0 ) ) ;
V_297 -> V_325 = F_151 ( sizeof( * V_296 ) + V_299 ) ;
F_185 ( V_277 , sizeof( struct V_236 ) ) ;
V_277 -> V_283 = V_284 ;
return V_277 ;
}
static int F_196 ( struct V_106 * V_75 , struct V_20 * V_21 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_294 * V_326 ;
const struct V_236 * V_234 ;
const struct V_16 * V_240 , * V_298 ;
struct V_262 * V_263 ;
struct V_327 * V_328 ;
V_328 = F_197 ( V_75 ) ;
if ( ! V_328 )
goto V_148;
V_234 = F_160 ( V_21 ) ;
V_240 = & V_234 -> V_240 ;
V_298 = & V_234 -> V_298 ;
V_326 = (struct V_294 * ) F_187 ( V_21 ) ;
if ( V_326 -> V_316 . V_329 != 0 ||
V_326 -> V_316 . V_317 != V_330 )
goto V_148;
if ( F_198 ( V_298 ) ||
F_7 ( & V_326 -> V_322 ) )
goto V_148;
V_263 = F_174 ( V_211 -> V_331 , & V_326 -> V_322 , V_75 ) ;
if ( V_263 ) {
struct V_37 * V_107 ;
struct V_20 * V_277 ;
if ( ! ( V_263 -> V_278 & V_279 ) ) {
F_175 ( V_263 ) ;
goto V_148;
}
V_107 = F_64 ( V_50 , V_263 -> V_280 ) ;
if ( V_107 && F_3 ( & ( F_22 ( V_107 ) -> V_69 ) ) ) {
F_175 ( V_263 ) ;
goto V_148;
}
V_277 = F_181 ( V_21 , V_263 ,
! ! ( V_107 ? V_107 -> V_43 & V_332 : 0 ) ) ;
F_175 ( V_263 ) ;
if ( V_277 == NULL )
goto V_148;
if ( F_179 ( V_277 ) == V_287 )
V_75 -> V_239 . V_288 ++ ;
} else if ( V_50 -> V_43 & V_289 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_326 -> V_322 ,
. V_7 . V_333 = V_6 ,
} ;
F_54 ( V_75 , & V_11 ) ;
}
V_148:
F_180 ( V_21 ) ;
return V_291 ;
}
static bool F_199 ( struct V_106 * V_75 , struct V_20 * V_21 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_262 * V_263 ;
if ( F_102 ( F_158 ( V_21 ) -> V_308 ) )
return false ;
V_263 = NULL ;
switch ( F_21 ( F_158 ( V_21 ) -> V_309 ) ) {
case V_270 :
{
struct V_234 * V_334 ;
if ( ! F_146 ( V_21 , sizeof( struct V_234 ) ) )
return false ;
V_334 = F_159 ( V_21 ) ;
V_263 = F_174 ( & V_276 , & V_334 -> V_298 , V_75 ) ;
if ( ! V_263 && ( V_50 -> V_43 & V_289 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_334 -> V_298 ,
. sin . V_290 = V_18 ,
} ;
F_54 ( V_75 , & V_11 ) ;
return false ;
}
break;
}
#if F_112 ( V_179 )
case V_303 :
{
struct V_236 * V_297 ;
if ( ! F_146 ( V_21 , sizeof( struct V_236 ) ) )
return false ;
V_297 = F_160 ( V_21 ) ;
V_263 = F_174 ( V_211 -> V_331 , & V_297 -> V_298 , V_75 ) ;
if ( ! V_263 && ( V_50 -> V_43 & V_289 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_297 -> V_298 ,
. V_7 . V_333 = V_6 ,
} ;
F_54 ( V_75 , & V_11 ) ;
return false ;
}
break;
}
#endif
default:
return false ;
}
if ( V_263 ) {
bool V_335 ;
V_335 = ! F_63 ( F_158 ( V_21 ) -> V_308 , V_263 -> V_280 ) ;
if ( V_335 ) {
memcpy ( F_158 ( V_21 ) -> V_243 , F_158 ( V_21 ) -> V_308 ,
V_75 -> V_274 ) ;
memcpy ( F_158 ( V_21 ) -> V_308 , V_263 -> V_280 , V_75 -> V_274 ) ;
}
F_175 ( V_263 ) ;
return V_335 ;
}
return false ;
}
static void F_200 ( struct V_119 * V_214 , T_1 V_336 ,
struct V_215 * V_216 )
{
struct V_225 * V_226 ;
if ( ! V_216 -> V_226 )
return;
V_226 = (struct V_225 * ) V_214 ;
V_214 -> V_149 |= F_5 ( V_223 ) ;
if ( V_216 -> V_226 & V_229 )
V_226 -> V_228 = 1 ;
if ( V_216 -> V_226 & V_231 )
V_226 -> V_230 = 1 ;
V_226 -> V_227 = F_151 ( V_216 -> V_226 & V_337 ) ;
}
static int F_201 ( struct V_338 * V_339 , struct V_45 * V_46 ,
struct V_20 * V_21 ,
struct V_106 * V_75 , struct V_16 * V_240 ,
struct V_16 * V_298 , T_8 V_340 , T_8 V_341 ,
T_2 V_342 , T_2 V_86 ,
struct V_215 * V_216 , bool V_343 , T_1 V_336 )
{
struct V_119 * V_214 ;
int V_344 ;
int V_101 ;
bool V_345 = ! ( V_336 & V_346 ) ;
int type = V_345 ? V_347 : V_348 ;
V_138 V_122 = sizeof( struct V_119 ) ;
if ( ( V_336 & V_349 ) &&
V_21 -> V_283 == V_350 ) {
int V_351 = F_202 ( V_21 ) ;
if ( V_351 <= V_352 &&
! ( V_351 & V_353 ) &&
( V_21 -> V_354 == F_74 ( struct V_135 , V_136 ) ||
V_21 -> V_354 == F_74 ( struct V_137 , V_136 ) ) ) {
V_345 = false ;
type |= V_355 ;
}
}
F_155 ( V_21 , V_343 ) ;
V_344 = F_182 ( V_339 -> V_75 ) + V_339 -> V_356
+ V_217 + sizeof( struct V_236 )
+ ( F_203 ( V_21 ) ? V_357 : 0 ) ;
V_101 = F_204 ( V_21 , V_344 ) ;
if ( F_83 ( V_101 ) ) {
F_51 ( V_21 ) ;
goto V_101;
}
V_21 = F_205 ( V_21 ) ;
if ( F_50 ( ! V_21 ) ) {
V_101 = - V_171 ;
goto V_101;
}
V_21 = F_206 ( V_21 , V_345 , type ) ;
if ( F_207 ( V_21 ) ) {
V_101 = - V_181 ;
goto V_101;
}
V_214 = (struct V_119 * ) F_208 ( V_21 , sizeof( * V_214 ) ) ;
V_214 -> V_149 = F_5 ( V_218 ) ;
V_214 -> V_152 = V_216 -> V_117 ;
if ( type & V_355 ) {
T_1 V_123 = ( F_202 ( V_21 ) - V_122 ) >>
V_133 ;
if ( V_21 -> V_354 == F_74 ( struct V_135 , V_136 ) )
V_123 |= V_134 ;
V_214 -> V_152 |= F_5 ( V_123 ) ;
V_214 -> V_149 |= F_5 ( V_150 ) ;
if ( ! F_209 ( V_21 ) ) {
V_21 -> V_283 = V_358 ;
V_21 -> V_359 = 0 ;
}
}
if ( V_336 & V_224 )
F_200 ( V_214 , V_336 , V_216 ) ;
F_210 ( V_21 , F_151 ( V_220 ) ) ;
F_211 ( V_339 , V_46 , V_21 , V_75 , V_240 , V_298 , V_340 ,
V_341 , V_342 , V_86 ,
! ! ( V_336 & V_346 ) ) ;
return 0 ;
V_101:
F_212 ( V_339 ) ;
return V_101 ;
}
int F_213 ( struct V_360 * V_361 , struct V_45 * V_46 , struct V_20 * V_21 ,
V_17 V_362 , V_17 V_339 , T_8 V_248 , T_8 V_341 , T_2 V_363 ,
T_2 V_342 , T_2 V_86 ,
struct V_215 * V_216 , bool V_343 , T_1 V_336 )
{
struct V_119 * V_214 ;
int V_344 ;
int V_101 ;
bool V_345 = ! ! ( V_336 & V_364 ) ;
int type = V_345 ? V_347 : V_348 ;
V_138 V_122 = sizeof( struct V_119 ) ;
if ( ( V_336 & V_349 ) &&
V_21 -> V_283 == V_350 ) {
int V_351 = F_202 ( V_21 ) ;
if ( V_351 <= V_352 &&
! ( V_351 & V_353 ) &&
( V_21 -> V_354 == F_74 ( struct V_135 , V_136 ) ||
V_21 -> V_354 == F_74 ( struct V_137 , V_136 ) ) ) {
V_345 = false ;
type |= V_355 ;
}
}
V_344 = F_182 ( V_361 -> V_339 . V_75 ) + V_361 -> V_339 . V_356
+ V_217 + sizeof( struct V_234 )
+ ( F_203 ( V_21 ) ? V_357 : 0 ) ;
V_101 = F_204 ( V_21 , V_344 ) ;
if ( F_83 ( V_101 ) ) {
F_51 ( V_21 ) ;
return V_101 ;
}
V_21 = F_205 ( V_21 ) ;
if ( F_50 ( ! V_21 ) )
return - V_171 ;
V_21 = F_206 ( V_21 , V_345 , type ) ;
if ( F_207 ( V_21 ) )
return F_214 ( V_21 ) ;
V_214 = (struct V_119 * ) F_208 ( V_21 , sizeof( * V_214 ) ) ;
V_214 -> V_149 = F_5 ( V_218 ) ;
V_214 -> V_152 = V_216 -> V_117 ;
if ( type & V_355 ) {
T_1 V_123 = ( F_202 ( V_21 ) - V_122 ) >>
V_133 ;
if ( V_21 -> V_354 == F_74 ( struct V_135 , V_136 ) )
V_123 |= V_134 ;
V_214 -> V_152 |= F_5 ( V_123 ) ;
V_214 -> V_149 |= F_5 ( V_150 ) ;
if ( ! F_209 ( V_21 ) ) {
V_21 -> V_283 = V_358 ;
V_21 -> V_359 = 0 ;
}
}
if ( V_336 & V_224 )
F_200 ( V_214 , V_336 , V_216 ) ;
F_210 ( V_21 , F_151 ( V_220 ) ) ;
return F_215 ( V_361 , V_46 , V_21 , V_362 , V_339 , V_248 ,
V_341 , V_363 , V_342 , V_86 , V_343 ,
! ( V_336 & V_364 ) ) ;
}
static void F_216 ( struct V_20 * V_21 , struct V_49 * V_365 ,
struct V_49 * V_366 )
{
struct V_238 * V_367 , * V_368 ;
union V_1 V_369 ;
union V_1 * V_69 = & V_366 -> V_51 . V_69 ;
struct V_106 * V_75 = V_21 -> V_75 ;
int V_255 = V_21 -> V_255 ;
V_367 = F_165 ( V_365 -> V_75 -> V_251 ) ;
V_368 = F_165 ( V_366 -> V_75 -> V_251 ) ;
V_21 -> V_285 = V_286 ;
V_21 -> V_359 = 0 ;
V_21 -> V_75 = V_366 -> V_75 ;
F_177 ( V_21 , F_178 ( V_21 ) ) ;
if ( V_69 -> V_4 . V_5 == V_18 ) {
V_369 . sin . V_9 . V_10 = F_5 ( V_370 ) ;
V_369 . V_4 . V_5 = V_18 ;
#if F_112 ( V_179 )
} else {
V_369 . V_7 . V_8 = V_371 ;
V_369 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_366 -> V_43 & V_245 )
F_127 ( V_21 -> V_75 , & V_369 , F_158 ( V_21 ) -> V_243 ) ;
F_166 ( & V_367 -> V_252 ) ;
V_367 -> V_372 ++ ;
V_367 -> V_373 += V_255 ;
F_167 ( & V_367 -> V_252 ) ;
if ( F_168 ( V_21 ) == V_374 ) {
F_166 ( & V_368 -> V_252 ) ;
V_368 -> V_253 ++ ;
V_368 -> V_254 += V_255 ;
F_167 ( & V_368 -> V_252 ) ;
} else {
V_75 -> V_239 . V_288 ++ ;
}
}
static void F_217 ( struct V_20 * V_21 , struct V_106 * V_75 ,
struct V_36 * V_55 , bool V_375 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_45 * V_46 = V_50 -> V_201 -> V_45 -> V_46 ;
struct V_360 * V_361 = NULL ;
const struct V_234 * V_376 ;
struct V_377 V_378 ;
union V_1 * V_339 ;
struct V_215 V_216 ;
T_2 V_342 = 0 , V_86 ;
T_1 V_117 ;
T_2 V_363 = 0 ;
T_8 V_248 , V_341 ;
int V_101 ;
V_86 = V_55 -> V_85 ? V_55 -> V_85 : V_50 -> V_86 ;
V_117 = V_55 -> V_52 ;
V_339 = & V_55 -> V_69 ;
if ( F_3 ( V_339 ) ) {
if ( V_375 ) {
F_216 ( V_21 , V_50 , V_50 ) ;
return;
}
goto V_221;
}
V_376 = F_159 ( V_21 ) ;
V_341 = V_50 -> V_341 ;
if ( ! V_341 && F_6 ( V_339 ) )
V_341 = 1 ;
V_248 = V_50 -> V_248 ;
if ( V_248 == 1 )
V_248 = F_218 ( V_376 , V_21 ) ;
V_342 = F_219 ( F_36 ( V_75 ) , V_21 , V_50 -> V_379 ,
V_50 -> V_380 , true ) ;
if ( V_339 -> V_4 . V_5 == V_18 ) {
memset ( & V_378 , 0 , sizeof( V_378 ) ) ;
V_378 . V_381 = V_55 -> V_89 ;
V_378 . V_382 = F_220 ( V_248 ) ;
V_378 . V_298 = V_339 -> sin . V_9 . V_10 ;
V_378 . V_240 = V_50 -> V_240 . sin . V_9 . V_10 ;
V_361 = F_221 ( V_50 -> V_29 , & V_378 ) ;
if ( F_207 ( V_361 ) ) {
F_101 ( V_75 , L_10 ,
& V_339 -> sin . V_9 . V_10 ) ;
V_75 -> V_239 . V_383 ++ ;
goto V_384;
}
if ( V_361 -> V_339 . V_75 == V_75 ) {
F_101 ( V_75 , L_11 ,
& V_339 -> sin . V_9 . V_10 ) ;
V_75 -> V_239 . V_385 ++ ;
goto V_386;
}
if ( V_361 -> V_387 & V_388 &&
! ( V_361 -> V_387 & ( V_389 | V_390 ) ) ) {
struct V_49 * V_366 ;
F_222 ( V_361 ) ;
V_366 = F_30 ( V_50 -> V_29 , V_117 ,
V_339 -> V_4 . V_5 , V_86 ,
V_50 -> V_43 ) ;
if ( ! V_366 )
goto V_384;
F_216 ( V_21 , V_50 , V_366 ) ;
return;
}
V_248 = F_223 ( V_248 , V_376 , V_21 ) ;
V_341 = V_341 ? : F_224 ( & V_361 -> V_339 ) ;
V_216 . V_117 = F_5 ( V_117 << 8 ) ;
V_216 . V_226 = V_21 -> V_246 ;
V_101 = F_213 ( V_361 , V_46 , V_21 , V_378 . V_240 ,
V_339 -> sin . V_9 . V_10 , V_248 , V_341 , V_363 ,
V_342 , V_86 , & V_216 ,
! F_35 ( V_50 -> V_29 , F_36 ( V_50 -> V_75 ) ) ,
V_50 -> V_43 ) ;
if ( V_101 < 0 ) {
V_21 = NULL ;
goto V_386;
}
F_225 ( V_101 , & V_75 -> V_239 , V_75 -> V_251 ) ;
#if F_112 ( V_179 )
} else {
struct V_338 * V_391 ;
struct V_392 V_393 ;
T_1 V_43 ;
memset ( & V_393 , 0 , sizeof( V_393 ) ) ;
V_393 . V_394 = V_55 -> V_89 ;
V_393 . V_298 = V_339 -> V_7 . V_8 ;
V_393 . V_240 = V_50 -> V_240 . V_7 . V_8 ;
V_393 . V_395 = V_396 ;
if ( V_211 -> V_397 ( V_46 , & V_391 , & V_393 ) ) {
F_101 ( V_75 , L_12 ,
& V_339 -> V_7 . V_8 ) ;
V_75 -> V_239 . V_383 ++ ;
goto V_384;
}
if ( V_391 -> V_75 == V_75 ) {
F_101 ( V_75 , L_13 ,
& V_339 -> V_7 . V_8 ) ;
F_212 ( V_391 ) ;
V_75 -> V_239 . V_385 ++ ;
goto V_384;
}
V_43 = ( (struct V_398 * ) V_391 ) -> V_399 ;
if ( V_43 & V_400 &&
! ( V_43 & ( V_389 | V_390 ) ) ) {
struct V_49 * V_366 ;
F_212 ( V_391 ) ;
V_366 = F_30 ( V_50 -> V_29 , V_117 ,
V_339 -> V_4 . V_5 , V_86 ,
V_50 -> V_43 ) ;
if ( ! V_366 )
goto V_384;
F_216 ( V_21 , V_50 , V_366 ) ;
return;
}
V_341 = V_341 ? : F_226 ( V_391 ) ;
V_216 . V_117 = F_5 ( V_117 << 8 ) ;
V_216 . V_226 = V_21 -> V_246 ;
V_101 = F_201 ( V_391 , V_46 , V_21 , V_75 , & V_393 . V_240 , & V_393 . V_298 ,
0 , V_341 , V_342 , V_86 , & V_216 ,
! F_35 ( V_50 -> V_29 , F_36 ( V_50 -> V_75 ) ) ,
V_50 -> V_43 ) ;
#endif
}
return;
V_221:
V_75 -> V_239 . V_265 ++ ;
goto V_401;
V_386:
F_222 ( V_361 ) ;
V_384:
V_75 -> V_239 . V_402 ++ ;
V_401:
F_227 ( V_21 ) ;
}
static T_9 F_228 ( struct V_20 * V_21 , struct V_106 * V_75 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_304 * V_403 ;
bool V_375 = false ;
struct V_36 * V_55 , * V_404 = NULL ;
struct V_37 * V_107 ;
F_154 ( V_21 ) ;
V_403 = F_158 ( V_21 ) ;
if ( ( V_50 -> V_43 & V_405 ) ) {
if ( F_21 ( V_403 -> V_309 ) == V_282 )
return F_169 ( V_75 , V_21 ) ;
#if F_112 ( V_179 )
else if ( F_21 ( V_403 -> V_309 ) == V_303 &&
F_146 ( V_21 , sizeof( struct V_236 )
+ sizeof( struct V_294 ) ) &&
F_160 ( V_21 ) -> V_312 == V_313 ) {
struct V_294 * V_326 ;
V_326 = (struct V_294 * ) F_187 ( V_21 ) ;
if ( V_326 -> V_316 . V_329 == 0 &&
V_326 -> V_316 . V_317 == V_330 )
return F_196 ( V_75 , V_21 ) ;
}
V_403 = F_158 ( V_21 ) ;
#endif
}
V_107 = F_64 ( V_50 , V_403 -> V_308 ) ;
V_375 = false ;
if ( V_107 && ( V_107 -> V_43 & V_332 ) && ( V_50 -> V_43 & V_406 ) &&
( F_21 ( V_403 -> V_309 ) == V_270 ||
F_21 ( V_403 -> V_309 ) == V_303 ) ) {
V_375 = F_199 ( V_75 , V_21 ) ;
if ( V_375 )
V_107 = F_64 ( V_50 , V_403 -> V_308 ) ;
}
if ( V_107 == NULL ) {
V_107 = F_64 ( V_50 , V_407 ) ;
if ( V_107 == NULL ) {
if ( ( V_50 -> V_43 & V_408 ) &&
! F_102 ( V_403 -> V_308 ) )
F_56 ( V_50 , V_403 -> V_308 ) ;
V_75 -> V_239 . V_265 ++ ;
F_51 ( V_21 ) ;
return V_291 ;
}
}
F_125 (rdst, &f->remotes, list) {
struct V_20 * V_409 ;
if ( ! V_404 ) {
V_404 = V_55 ;
continue;
}
V_409 = F_229 ( V_21 , V_103 ) ;
if ( V_409 )
F_217 ( V_409 , V_75 , V_55 , V_375 ) ;
}
if ( V_404 )
F_217 ( V_21 , V_75 , V_404 , V_375 ) ;
else
F_51 ( V_21 ) ;
return V_291 ;
}
static void F_230 ( unsigned long V_410 )
{
struct V_49 * V_50 = (struct V_49 * ) V_410 ;
unsigned long V_411 = V_57 + V_412 ;
unsigned int V_192 ;
if ( ! F_132 ( V_50 -> V_75 ) )
return;
F_118 ( & V_50 -> V_187 ) ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 ) {
struct V_413 * V_141 , * V_263 ;
F_231 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_107
= F_79 ( V_141 , struct V_37 , V_172 ) ;
unsigned long V_414 ;
if ( V_107 -> V_73 & V_185 )
continue;
V_414 = V_107 -> V_92 + V_50 -> V_415 * V_416 ;
if ( F_232 ( V_414 , V_57 ) ) {
F_101 ( V_50 -> V_75 ,
L_14 ,
V_107 -> V_70 ) ;
V_107 -> V_73 = V_108 ;
F_108 ( V_50 , V_107 ) ;
} else if ( F_233 ( V_414 , V_411 ) )
V_411 = V_414 ;
}
}
F_119 ( & V_50 -> V_187 ) ;
F_234 ( & V_50 -> V_417 , V_411 ) ;
}
static void F_235 ( struct V_24 * V_25 , struct V_49 * V_50 )
{
struct V_31 * V_32 = F_20 ( V_50 -> V_29 , V_33 ) ;
V_98 V_117 = V_50 -> V_51 . V_52 ;
V_50 -> V_201 = V_25 ;
F_131 ( & V_32 -> V_203 ) ;
F_104 ( & V_50 -> V_172 , F_17 ( V_25 , V_117 ) ) ;
F_133 ( & V_32 -> V_203 ) ;
}
static int F_236 ( struct V_106 * V_75 )
{
V_75 -> V_251 = F_237 ( struct V_238 ) ;
if ( ! V_75 -> V_251 )
return - V_171 ;
return 0 ;
}
static void F_238 ( struct V_49 * V_50 )
{
struct V_37 * V_107 ;
F_118 ( & V_50 -> V_187 ) ;
V_107 = F_62 ( V_50 , V_407 ) ;
if ( V_107 )
F_108 ( V_50 , V_107 ) ;
F_119 ( & V_50 -> V_187 ) ;
}
static void F_239 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
F_238 ( V_50 ) ;
F_240 ( V_75 -> V_251 ) ;
}
static int F_241 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_24 * V_25 ;
int V_206 = 0 ;
V_25 = F_242 ( V_50 -> V_29 , V_50 -> V_86 , F_153 , NULL ,
false , V_50 -> V_43 ) ;
if ( F_207 ( V_25 ) )
return F_214 ( V_25 ) ;
F_235 ( V_25 , V_50 ) ;
if ( F_6 ( & V_50 -> V_51 . V_69 ) ) {
V_206 = F_139 ( V_50 ) ;
if ( V_206 ) {
F_136 ( V_25 ) ;
return V_206 ;
}
}
if ( V_50 -> V_415 )
F_234 ( & V_50 -> V_417 , V_57 + V_412 ) ;
return V_206 ;
}
static void F_243 ( struct V_49 * V_50 )
{
unsigned int V_192 ;
F_118 ( & V_50 -> V_187 ) ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 ) {
struct V_413 * V_141 , * V_263 ;
F_231 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_107
= F_79 ( V_141 , struct V_37 , V_172 ) ;
if ( ! F_34 ( V_107 -> V_70 ) )
F_108 ( V_50 , V_107 ) ;
}
}
F_119 ( & V_50 -> V_187 ) ;
}
static int F_244 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_31 * V_32 = F_20 ( V_50 -> V_29 , V_33 ) ;
struct V_24 * V_25 = V_50 -> V_201 ;
int V_206 = 0 ;
if ( F_6 ( & V_50 -> V_51 . V_69 ) &&
! F_134 ( V_32 , V_50 ) )
V_206 = F_143 ( V_50 ) ;
F_245 ( & V_50 -> V_417 ) ;
F_243 ( V_50 ) ;
F_136 ( V_25 ) ;
return V_206 ;
}
static void F_246 ( struct V_106 * V_75 )
{
}
static int F_247 ( struct V_106 * V_75 , int V_418 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_36 * V_339 = & V_50 -> V_51 ;
struct V_106 * V_419 ;
int V_420 ;
V_419 = F_115 ( V_50 -> V_29 , V_339 -> V_89 ) ;
if ( V_419 == NULL )
return F_248 ( V_75 , V_418 ) ;
if ( V_339 -> V_69 . V_4 . V_5 == V_6 )
V_420 = V_419 -> V_421 - V_422 ;
else
V_420 = V_419 -> V_421 - V_423 ;
if ( V_418 < 68 || V_418 > V_420 )
return - V_181 ;
V_75 -> V_421 = V_418 ;
return 0 ;
}
void F_249 ( struct V_106 * V_75 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_36 ( V_75 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_3 V_5 ;
T_2 V_30 ;
unsigned int V_301 ;
F_131 ( & V_32 -> V_203 ) ;
for ( V_301 = 0 ; V_301 < V_424 ; ++ V_301 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_45 -> V_46 ) -> V_47 ;
V_5 = V_25 -> V_45 -> V_46 -> V_48 ;
V_75 -> V_156 -> V_157 ( V_75 , V_5 ,
V_30 ) ;
}
}
F_133 ( & V_32 -> V_203 ) ;
}
static void F_250 ( struct V_106 * V_75 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
unsigned int V_192 ;
F_251 ( V_75 ) ;
F_252 ( V_75 ) ;
if ( V_50 -> V_51 . V_69 . V_4 . V_5 == V_6 )
V_75 -> V_425 = V_242 + V_422 ;
else
V_75 -> V_425 = V_242 + V_423 ;
V_75 -> V_156 = & V_426 ;
V_75 -> V_427 = V_428 ;
F_253 ( V_75 , & V_429 ) ;
V_75 -> V_430 = 0 ;
V_75 -> V_431 |= V_432 ;
V_75 -> V_431 |= V_433 | V_434 ;
V_75 -> V_431 |= V_435 ;
V_75 -> V_431 |= V_436 ;
V_75 -> V_437 = V_75 -> V_431 ;
V_75 -> V_431 |= V_438 | V_439 ;
V_75 -> V_440 |= V_433 | V_434 | V_435 ;
V_75 -> V_440 |= V_436 ;
V_75 -> V_440 |= V_438 | V_439 ;
F_254 ( V_75 ) ;
V_75 -> V_441 |= V_442 ;
F_103 ( & V_50 -> V_40 ) ;
F_255 ( & V_50 -> V_187 ) ;
F_256 ( & V_50 -> V_417 ) ;
V_50 -> V_417 . V_443 = F_230 ;
V_50 -> V_417 . V_123 = ( unsigned long ) V_50 ;
V_50 -> V_86 = F_151 ( V_444 ) ;
V_50 -> V_75 = V_75 ;
for ( V_192 = 0 ; V_192 < V_193 ; ++ V_192 )
F_257 ( & V_50 -> V_115 [ V_192 ] ) ;
}
static int F_258 ( struct V_14 * V_178 [] , struct V_14 * V_123 [] )
{
if ( V_178 [ V_445 ] ) {
if ( F_11 ( V_178 [ V_445 ] ) != V_83 ) {
F_259 ( L_15 ) ;
return - V_181 ;
}
if ( ! F_260 ( F_261 ( V_178 [ V_445 ] ) ) ) {
F_259 ( L_16 ) ;
return - V_183 ;
}
}
if ( ! V_123 )
return - V_181 ;
if ( V_123 [ V_446 ] ) {
V_98 V_26 = F_114 ( V_123 [ V_446 ] ) ;
if ( V_26 >= V_447 )
return - V_448 ;
}
if ( V_123 [ V_449 ] ) {
const struct V_450 * V_141
= F_261 ( V_123 [ V_449 ] ) ;
if ( F_21 ( V_141 -> V_451 ) < F_21 ( V_141 -> V_452 ) ) {
F_259 ( L_17 ,
F_21 ( V_141 -> V_452 ) , F_21 ( V_141 -> V_451 ) ) ;
return - V_181 ;
}
}
return 0 ;
}
static void F_262 ( struct V_106 * V_453 ,
struct V_454 * V_455 )
{
F_263 ( V_455 -> V_310 , V_456 , sizeof( V_455 -> V_310 ) ) ;
F_263 ( V_455 -> V_457 , L_18 , sizeof( V_455 -> V_457 ) ) ;
}
static void F_264 ( struct V_458 * V_459 )
{
struct V_24 * V_25 = F_79 ( V_459 , struct V_24 , V_205 ) ;
F_265 ( V_25 -> V_45 ) ;
F_123 ( V_25 , V_175 ) ;
}
static struct V_460 * F_266 ( struct V_29 * V_29 , bool V_461 ,
T_2 V_30 , T_1 V_43 )
{
struct V_460 * V_45 ;
struct V_462 V_463 ;
int V_101 ;
memset ( & V_463 , 0 , sizeof( V_463 ) ) ;
if ( V_461 ) {
V_463 . V_42 = V_6 ;
V_463 . V_464 =
! ( V_43 & V_465 ) ;
} else {
V_463 . V_42 = V_18 ;
}
V_463 . V_466 = V_30 ;
V_101 = F_267 ( V_29 , & V_463 , & V_45 ) ;
if ( V_101 < 0 )
return F_268 ( V_101 ) ;
return V_45 ;
}
static struct V_24 * F_269 ( struct V_29 * V_29 , T_2 V_30 ,
T_10 * V_233 , void * V_123 ,
T_1 V_43 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_460 * V_45 ;
unsigned int V_192 ;
bool V_461 = ! ! ( V_43 & V_467 ) ;
struct V_468 V_469 ;
V_25 = F_270 ( sizeof( * V_25 ) , V_470 ) ;
if ( ! V_25 )
return F_268 ( - V_171 ) ;
for ( V_192 = 0 ; V_192 < V_471 ; ++ V_192 )
F_257 ( & V_25 -> V_27 [ V_192 ] ) ;
F_271 ( & V_25 -> V_205 , F_264 ) ;
V_45 = F_266 ( V_29 , V_461 , V_30 , V_43 ) ;
if ( F_207 ( V_45 ) ) {
F_117 ( L_19 , F_21 ( V_30 ) ,
F_214 ( V_45 ) ) ;
F_107 ( V_25 ) ;
return F_272 ( V_45 ) ;
}
V_25 -> V_45 = V_45 ;
F_273 ( & V_25 -> V_202 , 1 ) ;
V_25 -> V_233 = V_233 ;
V_25 -> V_123 = V_123 ;
V_25 -> V_43 = ( V_43 & V_44 ) ;
V_25 -> V_147 . V_30 = V_30 ;
V_25 -> V_147 . V_472 . V_473 = F_78 ;
V_25 -> V_147 . V_472 . V_474 = F_88 ;
F_131 ( & V_32 -> V_203 ) ;
F_104 ( & V_25 -> V_172 , F_19 ( V_29 , V_30 ) ) ;
F_91 ( V_25 ) ;
F_133 ( & V_32 -> V_203 ) ;
V_469 . V_475 = V_25 ;
V_469 . V_476 = 1 ;
V_469 . V_477 = F_149 ;
V_469 . V_478 = NULL ;
F_274 ( V_29 , V_45 , & V_469 ) ;
return V_25 ;
}
struct V_24 * F_242 ( struct V_29 * V_29 , T_2 V_30 ,
T_10 * V_233 , void * V_123 ,
bool V_479 , T_1 V_43 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
bool V_461 = V_43 & V_467 ;
if ( ! V_479 ) {
F_131 ( & V_32 -> V_203 ) ;
V_25 = F_26 ( V_29 , V_461 ? V_6 : V_18 , V_30 ,
V_43 ) ;
if ( V_25 && V_25 -> V_233 == V_233 ) {
if ( ! F_275 ( & V_25 -> V_202 , 1 , 0 ) )
V_25 = F_268 ( - V_480 ) ;
F_133 ( & V_32 -> V_203 ) ;
return V_25 ;
}
F_133 ( & V_32 -> V_203 ) ;
}
return F_269 ( V_29 , V_30 , V_233 , V_123 , V_43 ) ;
}
static int F_276 ( struct V_29 * V_481 , struct V_106 * V_75 ,
struct V_14 * V_178 [] , struct V_14 * V_123 [] )
{
struct V_31 * V_32 = F_20 ( V_481 , V_33 ) ;
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_36 * V_339 = & V_50 -> V_51 ;
V_98 V_117 ;
int V_101 ;
bool V_482 = false ;
if ( ! V_123 [ V_446 ] )
return - V_181 ;
V_50 -> V_29 = V_481 ;
V_117 = F_114 ( V_123 [ V_446 ] ) ;
V_339 -> V_52 = V_117 ;
V_339 -> V_69 . V_4 . V_5 = V_18 ;
if ( V_123 [ V_483 ] ) {
V_339 -> V_69 . sin . V_9 . V_10 = F_13 ( V_123 [ V_483 ] ) ;
} else if ( V_123 [ V_484 ] ) {
if ( ! F_112 ( V_179 ) )
return - V_485 ;
V_339 -> V_69 . V_7 . V_8 = F_12 ( V_123 [ V_484 ] ) ;
V_339 -> V_69 . V_4 . V_5 = V_6 ;
V_482 = true ;
}
if ( V_123 [ V_486 ] ) {
V_50 -> V_240 . sin . V_9 . V_10 = F_13 ( V_123 [ V_486 ] ) ;
V_50 -> V_240 . V_4 . V_5 = V_18 ;
} else if ( V_123 [ V_487 ] ) {
if ( ! F_112 ( V_179 ) )
return - V_485 ;
V_50 -> V_240 . V_7 . V_8 = F_12 ( V_123 [ V_487 ] ) ;
V_50 -> V_240 . V_4 . V_5 = V_6 ;
V_482 = true ;
}
if ( V_123 [ V_488 ] &&
( V_339 -> V_89 = F_114 ( V_123 [ V_488 ] ) ) ) {
struct V_106 * V_419
= F_115 ( V_481 , V_339 -> V_89 ) ;
if ( ! V_419 ) {
F_117 ( L_20 , V_339 -> V_89 ) ;
return - V_489 ;
}
#if F_112 ( V_179 )
if ( V_482 ) {
struct V_327 * V_490 = F_197 ( V_419 ) ;
if ( V_490 && V_490 -> V_491 . V_492 ) {
F_117 ( L_21 ) ;
return - V_493 ;
}
V_50 -> V_43 |= V_467 ;
}
#endif
if ( ! V_178 [ V_494 ] )
V_75 -> V_421 = V_419 -> V_421 - ( V_482 ? V_422 : V_423 ) ;
V_75 -> V_425 = V_419 -> V_495 +
( V_482 ? V_422 : V_423 ) ;
} else if ( V_482 )
V_50 -> V_43 |= V_467 ;
if ( V_123 [ V_496 ] )
V_50 -> V_248 = F_277 ( V_123 [ V_496 ] ) ;
if ( V_123 [ V_497 ] )
V_50 -> V_341 = F_277 ( V_123 [ V_497 ] ) ;
if ( ! V_123 [ V_498 ] || F_277 ( V_123 [ V_498 ] ) )
V_50 -> V_43 |= V_245 ;
if ( V_123 [ V_499 ] )
V_50 -> V_415 = F_114 ( V_123 [ V_499 ] ) ;
else
V_50 -> V_415 = V_500 ;
if ( V_123 [ V_501 ] && F_277 ( V_123 [ V_501 ] ) )
V_50 -> V_43 |= V_405 ;
if ( V_123 [ V_502 ] && F_277 ( V_123 [ V_502 ] ) )
V_50 -> V_43 |= V_406 ;
if ( V_123 [ V_503 ] && F_277 ( V_123 [ V_503 ] ) )
V_50 -> V_43 |= V_408 ;
if ( V_123 [ V_504 ] && F_277 ( V_123 [ V_504 ] ) )
V_50 -> V_43 |= V_289 ;
if ( V_123 [ V_505 ] )
V_50 -> V_168 = F_114 ( V_123 [ V_505 ] ) ;
if ( V_123 [ V_449 ] ) {
const struct V_450 * V_141
= F_261 ( V_123 [ V_449 ] ) ;
V_50 -> V_379 = F_21 ( V_141 -> V_452 ) ;
V_50 -> V_380 = F_21 ( V_141 -> V_451 ) ;
}
if ( V_123 [ V_506 ] )
V_50 -> V_86 = F_113 ( V_123 [ V_506 ] ) ;
if ( V_123 [ V_507 ] && F_277 ( V_123 [ V_507 ] ) )
V_50 -> V_43 |= V_364 ;
if ( V_123 [ V_508 ] &&
F_277 ( V_123 [ V_508 ] ) )
V_50 -> V_43 |= V_346 ;
if ( V_123 [ V_509 ] &&
F_277 ( V_123 [ V_509 ] ) )
V_50 -> V_43 |= V_465 ;
if ( V_123 [ V_510 ] &&
F_277 ( V_123 [ V_510 ] ) )
V_50 -> V_43 |= V_349 ;
if ( V_123 [ V_511 ] &&
F_277 ( V_123 [ V_511 ] ) )
V_50 -> V_43 |= V_151 ;
if ( V_123 [ V_512 ] )
V_50 -> V_43 |= V_224 ;
if ( V_123 [ V_513 ] )
V_50 -> V_43 |= V_153 ;
if ( F_30 ( V_481 , V_117 , V_482 ? V_6 : V_18 ,
V_50 -> V_86 , V_50 -> V_43 ) ) {
F_117 ( L_22 , V_117 ) ;
return - V_161 ;
}
V_75 -> V_514 = & V_515 ;
if ( ! F_3 ( & V_50 -> V_51 . V_69 ) ) {
V_101 = F_100 ( V_50 , V_407 ,
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
V_101 = F_278 ( V_75 ) ;
if ( V_101 ) {
F_238 ( V_50 ) ;
return V_101 ;
}
F_279 ( & V_50 -> V_40 , & V_32 -> V_516 ) ;
return 0 ;
}
static void F_280 ( struct V_106 * V_75 , struct V_517 * V_116 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
struct V_31 * V_32 = F_20 ( V_50 -> V_29 , V_33 ) ;
F_131 ( & V_32 -> V_203 ) ;
if ( ! F_281 ( & V_50 -> V_172 ) )
F_109 ( & V_50 -> V_172 ) ;
F_133 ( & V_32 -> V_203 ) ;
F_282 ( & V_50 -> V_40 ) ;
F_283 ( V_75 , V_116 ) ;
}
static T_4 F_284 ( const struct V_106 * V_75 )
{
return F_47 ( sizeof( V_98 ) ) +
F_47 ( sizeof( struct V_16 ) ) +
F_47 ( sizeof( V_98 ) ) +
F_47 ( sizeof( struct V_16 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( V_98 ) ) +
F_47 ( sizeof( V_98 ) ) +
F_47 ( sizeof( struct V_450 ) ) +
F_47 ( sizeof( T_2 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
F_47 ( sizeof( T_8 ) ) +
0 ;
}
static int F_285 ( struct V_20 * V_21 , const struct V_106 * V_75 )
{
const struct V_49 * V_50 = F_55 ( V_75 ) ;
const struct V_36 * V_339 = & V_50 -> V_51 ;
struct V_450 V_518 = {
. V_452 = F_151 ( V_50 -> V_379 ) ,
. V_451 = F_151 ( V_50 -> V_380 ) ,
} ;
if ( F_41 ( V_21 , V_446 , V_339 -> V_52 ) )
goto V_81;
if ( ! F_3 ( & V_339 -> V_69 ) ) {
if ( V_339 -> V_69 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_483 ,
V_339 -> V_69 . sin . V_9 . V_10 ) )
goto V_81;
#if F_112 ( V_179 )
} else {
if ( F_15 ( V_21 , V_484 ,
& V_339 -> V_69 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( V_339 -> V_89 && F_41 ( V_21 , V_488 , V_339 -> V_89 ) )
goto V_81;
if ( ! F_3 ( & V_50 -> V_240 ) ) {
if ( V_50 -> V_240 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_486 ,
V_50 -> V_240 . sin . V_9 . V_10 ) )
goto V_81;
#if F_112 ( V_179 )
} else {
if ( F_15 ( V_21 , V_487 ,
& V_50 -> V_240 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( F_286 ( V_21 , V_497 , V_50 -> V_341 ) ||
F_286 ( V_21 , V_496 , V_50 -> V_248 ) ||
F_286 ( V_21 , V_498 ,
! ! ( V_50 -> V_43 & V_245 ) ) ||
F_286 ( V_21 , V_501 ,
! ! ( V_50 -> V_43 & V_405 ) ) ||
F_286 ( V_21 , V_502 , ! ! ( V_50 -> V_43 & V_406 ) ) ||
F_286 ( V_21 , V_503 ,
! ! ( V_50 -> V_43 & V_408 ) ) ||
F_286 ( V_21 , V_504 ,
! ! ( V_50 -> V_43 & V_289 ) ) ||
F_41 ( V_21 , V_499 , V_50 -> V_415 ) ||
F_41 ( V_21 , V_505 , V_50 -> V_168 ) ||
F_40 ( V_21 , V_506 , V_50 -> V_86 ) ||
F_286 ( V_21 , V_507 ,
! ! ( V_50 -> V_43 & V_364 ) ) ||
F_286 ( V_21 , V_508 ,
! ! ( V_50 -> V_43 & V_346 ) ) ||
F_286 ( V_21 , V_509 ,
! ! ( V_50 -> V_43 & V_465 ) ) ||
F_286 ( V_21 , V_510 ,
! ! ( V_50 -> V_43 & V_349 ) ) ||
F_286 ( V_21 , V_511 ,
! ! ( V_50 -> V_43 & V_151 ) ) )
goto V_81;
if ( F_39 ( V_21 , V_449 , sizeof( V_518 ) , & V_518 ) )
goto V_81;
if ( V_50 -> V_43 & V_224 &&
F_287 ( V_21 , V_512 ) )
goto V_81;
if ( V_50 -> V_43 & V_153 &&
F_287 ( V_21 , V_513 ) )
goto V_81;
return 0 ;
V_81:
return - V_66 ;
}
static struct V_29 * F_288 ( const struct V_106 * V_75 )
{
struct V_49 * V_50 = F_55 ( V_75 ) ;
return V_50 -> V_29 ;
}
static void F_289 ( struct V_31 * V_32 ,
struct V_106 * V_75 )
{
struct V_49 * V_50 , * V_40 ;
F_290 ( V_519 ) ;
F_106 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_339 = & V_50 -> V_51 ;
if ( V_339 -> V_89 == V_75 -> V_76 )
F_280 ( V_50 -> V_75 , & V_519 ) ;
}
F_291 ( & V_519 ) ;
}
static int F_292 ( struct V_520 * V_521 ,
unsigned long V_522 , void * V_523 )
{
struct V_106 * V_75 = F_293 ( V_523 ) ;
struct V_31 * V_32 = F_20 ( F_36 ( V_75 ) , V_33 ) ;
if ( V_522 == V_524 )
F_289 ( V_32 , V_75 ) ;
return V_525 ;
}
static T_11 int F_294 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_192 ;
F_103 ( & V_32 -> V_516 ) ;
F_255 ( & V_32 -> V_203 ) ;
for ( V_192 = 0 ; V_192 < V_424 ; ++ V_192 )
F_257 ( & V_32 -> V_34 [ V_192 ] ) ;
return 0 ;
}
static void T_12 F_295 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_49 * V_50 , * V_40 ;
struct V_106 * V_75 , * V_526 ;
F_290 ( V_41 ) ;
F_296 () ;
F_297 (net, dev, aux)
if ( V_75 -> V_527 == & V_528 )
F_283 ( V_75 , & V_41 ) ;
F_106 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_35 ( F_36 ( V_50 -> V_75 ) , V_29 ) )
F_283 ( V_50 -> V_75 , & V_41 ) ;
}
F_291 ( & V_41 ) ;
F_298 () ;
}
static int T_13 F_299 ( void )
{
int V_165 ;
V_204 = F_300 ( L_18 , 0 , 0 ) ;
if ( ! V_204 )
return - V_171 ;
F_301 ( & V_529 , sizeof( V_529 ) ) ;
V_165 = F_302 ( & V_530 ) ;
if ( V_165 )
goto V_531;
V_165 = F_303 ( & V_532 ) ;
if ( V_165 )
goto V_533;
V_165 = F_304 ( & V_528 ) ;
if ( V_165 )
goto V_534;
return 0 ;
V_534:
F_305 ( & V_532 ) ;
V_533:
F_306 ( & V_530 ) ;
V_531:
F_307 ( V_204 ) ;
return V_165 ;
}
static void T_14 F_308 ( void )
{
F_309 ( & V_528 ) ;
F_305 ( & V_532 ) ;
F_307 ( V_204 ) ;
F_306 ( & V_530 ) ;
}
