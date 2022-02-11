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
static struct V_24 * F_26 ( struct V_29 * V_29 , T_2 V_30 )
{
struct V_24 * V_25 ;
F_27 (vs, vs_head(net, port), hlist) {
if ( F_28 ( V_25 -> V_42 -> V_43 ) -> V_44 == V_30 )
return V_25 ;
}
return NULL ;
}
static struct V_45 * F_29 ( struct V_24 * V_25 , T_1 V_26 )
{
struct V_45 * V_46 ;
F_27 (vxlan, vni_head(vs, id), hlist) {
if ( V_46 -> V_47 . V_48 == V_26 )
return V_46 ;
}
return NULL ;
}
static struct V_45 * F_30 ( struct V_29 * V_29 , T_1 V_26 , T_2 V_30 )
{
struct V_24 * V_25 ;
V_25 = F_26 ( V_29 , V_30 ) ;
if ( ! V_25 )
return NULL ;
return F_29 ( V_25 , V_26 ) ;
}
static int F_31 ( struct V_20 * V_21 , struct V_45 * V_46 ,
const struct V_37 * V_38 ,
T_1 V_49 , T_1 V_50 , int type , unsigned int V_51 ,
const struct V_36 * V_52 )
{
unsigned long V_53 = V_54 ;
struct V_55 V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
bool V_61 , V_62 ;
V_58 = F_32 ( V_21 , V_49 , V_50 , type , sizeof( * V_60 ) , V_51 ) ;
if ( V_58 == NULL )
return - V_63 ;
V_60 = F_33 ( V_58 ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_62 = V_61 = true ;
if ( type == V_64 ) {
V_60 -> V_65 = V_18 ;
V_61 = ! F_3 ( & V_52 -> V_66 ) ;
V_62 = ! F_34 ( V_38 -> V_67 ) ;
} else
V_60 -> V_65 = V_68 ;
V_60 -> V_69 = V_38 -> V_70 ;
V_60 -> V_71 = V_46 -> V_72 -> V_73 ;
V_60 -> V_74 = V_38 -> V_51 ;
V_60 -> V_75 = V_76 ;
if ( V_62 && F_15 ( V_21 , V_77 , V_78 , & V_38 -> V_67 ) )
goto V_79;
if ( V_61 && F_14 ( V_21 , V_76 , & V_52 -> V_66 ) )
goto V_79;
if ( V_52 -> V_80 && V_52 -> V_80 != V_46 -> V_81 &&
F_35 ( V_21 , V_82 , V_52 -> V_80 ) )
goto V_79;
if ( V_52 -> V_48 != V_46 -> V_47 . V_48 &&
F_36 ( V_21 , V_83 , V_52 -> V_48 ) )
goto V_79;
if ( V_52 -> V_84 &&
F_36 ( V_21 , V_85 , V_52 -> V_84 ) )
goto V_79;
V_56 . V_86 = F_37 ( V_53 - V_38 -> V_87 ) ;
V_56 . V_88 = 0 ;
V_56 . V_89 = F_37 ( V_53 - V_38 -> V_90 ) ;
V_56 . V_91 = 0 ;
if ( F_15 ( V_21 , V_92 , sizeof( V_56 ) , & V_56 ) )
goto V_79;
return F_38 ( V_21 , V_58 ) ;
V_79:
F_39 ( V_21 , V_58 ) ;
return - V_63 ;
}
static inline T_3 F_40 ( void )
{
return F_41 ( sizeof( struct V_59 ) )
+ F_42 ( V_78 )
+ F_42 ( sizeof( struct V_16 ) )
+ F_42 ( sizeof( T_2 ) )
+ F_42 ( sizeof( V_17 ) )
+ F_42 ( sizeof( V_93 ) )
+ F_42 ( sizeof( struct V_55 ) ) ;
}
static void F_43 ( struct V_45 * V_46 ,
struct V_37 * V_38 , int type )
{
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
struct V_20 * V_21 ;
int V_94 = - V_95 ;
V_21 = F_45 ( F_40 () , V_96 ) ;
if ( V_21 == NULL )
goto V_97;
V_94 = F_31 ( V_21 , V_46 , V_38 , 0 , 0 , type , 0 ,
F_24 ( V_38 ) ) ;
if ( V_94 < 0 ) {
F_46 ( V_94 == - V_63 ) ;
F_47 ( V_21 ) ;
goto V_97;
}
F_48 ( V_21 , V_29 , 0 , V_98 , NULL , V_96 ) ;
return;
V_97:
if ( V_94 < 0 )
F_49 ( V_29 , V_98 , V_94 ) ;
}
static void F_50 ( struct V_99 * V_72 , union V_1 * V_11 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 V_100 = {
. V_70 = V_101 ,
} ;
struct V_36 V_102 = {
. V_66 = * V_11 ,
. V_48 = V_103 ,
} ;
F_52 ( & V_100 . V_39 ) ;
F_53 ( & V_102 . V_41 , & V_100 . V_39 ) ;
F_43 ( V_46 , & V_100 , V_64 ) ;
}
static void F_54 ( struct V_45 * V_46 , const T_4 V_67 [ V_78 ] )
{
struct V_37 V_100 = {
. V_70 = V_101 ,
} ;
F_52 ( & V_100 . V_39 ) ;
memcpy ( V_100 . V_67 , V_67 , V_78 ) ;
F_43 ( V_46 , & V_100 , V_64 ) ;
}
static T_1 F_55 ( const unsigned char * V_104 )
{
T_5 V_105 = F_56 ( ( T_5 * ) V_104 ) ;
#ifdef F_57
V_105 >>= 16 ;
#else
V_105 <<= 16 ;
#endif
return F_58 ( V_105 , V_106 ) ;
}
static inline struct V_23 * F_59 ( struct V_45 * V_46 ,
const T_4 * V_107 )
{
return & V_46 -> V_108 [ F_55 ( V_107 ) ] ;
}
static struct V_37 * F_60 ( struct V_45 * V_46 ,
const T_4 * V_107 )
{
struct V_23 * V_109 = F_59 ( V_46 , V_107 ) ;
struct V_37 * V_100 ;
F_27 (f, head, hlist) {
if ( F_61 ( V_107 , V_100 -> V_67 ) )
return V_100 ;
}
return NULL ;
}
static struct V_37 * F_62 ( struct V_45 * V_46 ,
const T_4 * V_107 )
{
struct V_37 * V_100 ;
V_100 = F_60 ( V_46 , V_107 ) ;
if ( V_100 )
V_100 -> V_87 = V_54 ;
return V_100 ;
}
static struct V_36 * F_63 ( struct V_37 * V_100 ,
union V_1 * V_13 , T_2 V_30 ,
V_93 V_110 , V_93 V_73 )
{
struct V_36 * V_111 ;
F_64 (rd, &f->remotes, list) {
if ( F_1 ( & V_111 -> V_66 , V_13 ) &&
V_111 -> V_80 == V_30 &&
V_111 -> V_48 == V_110 &&
V_111 -> V_84 == V_73 )
return V_111 ;
}
return NULL ;
}
static int F_65 ( struct V_37 * V_100 ,
union V_1 * V_13 , T_2 V_30 , V_93 V_110 , V_93 V_73 )
{
struct V_36 * V_111 ;
V_111 = F_63 ( V_100 , V_13 , V_30 , V_110 , V_73 ) ;
if ( V_111 )
return 0 ;
V_111 = F_66 ( & V_100 -> V_39 , struct V_36 , V_41 ) ;
if ( ! V_111 )
return 0 ;
V_111 -> V_66 = * V_13 ;
V_111 -> V_80 = V_30 ;
V_111 -> V_48 = V_110 ;
V_111 -> V_84 = V_73 ;
return 1 ;
}
static int F_67 ( struct V_37 * V_100 ,
union V_1 * V_13 , T_2 V_30 , V_93 V_110 , V_93 V_73 )
{
struct V_36 * V_111 ;
V_111 = F_63 ( V_100 , V_13 , V_30 , V_110 , V_73 ) ;
if ( V_111 )
return 0 ;
V_111 = F_68 ( sizeof( * V_111 ) , V_96 ) ;
if ( V_111 == NULL )
return - V_95 ;
V_111 -> V_66 = * V_13 ;
V_111 -> V_80 = V_30 ;
V_111 -> V_48 = V_110 ;
V_111 -> V_84 = V_73 ;
F_69 ( & V_111 -> V_41 , & V_100 -> V_39 ) ;
return 1 ;
}
static struct V_20 * * F_70 ( struct V_20 * * V_109 , struct V_20 * V_21 )
{
struct V_20 * V_112 , * * V_113 = NULL ;
struct V_114 * V_115 , * V_116 ;
struct V_117 * V_118 , * V_119 ;
unsigned int V_120 , V_121 , V_122 ;
const struct V_123 * V_124 ;
T_2 type ;
int V_125 = 1 ;
V_121 = F_71 ( V_21 ) ;
V_120 = V_121 + sizeof( * V_115 ) ;
V_115 = F_72 ( V_21 , V_121 ) ;
if ( F_73 ( V_21 , V_120 ) ) {
V_115 = F_74 ( V_21 , V_120 , V_121 ) ;
if ( F_75 ( ! V_115 ) )
goto V_126;
}
F_76 ( V_21 , sizeof( struct V_114 ) ) ;
V_122 = F_71 ( V_21 ) ;
V_120 = V_122 + sizeof( * V_118 ) ;
V_118 = F_72 ( V_21 , V_122 ) ;
if ( F_73 ( V_21 , V_120 ) ) {
V_118 = F_74 ( V_21 , V_120 , V_122 ) ;
if ( F_75 ( ! V_118 ) )
goto V_126;
}
V_125 = 0 ;
for ( V_112 = * V_109 ; V_112 ; V_112 = V_112 -> V_40 ) {
if ( ! F_77 ( V_112 ) -> V_127 )
continue;
V_116 = (struct V_114 * ) ( V_112 -> V_128 + V_121 ) ;
V_119 = (struct V_117 * ) ( V_112 -> V_128 + V_122 ) ;
if ( V_115 -> V_129 != V_116 -> V_129 || F_78 ( V_118 , V_119 ) ) {
F_77 ( V_112 ) -> V_127 = 0 ;
continue;
}
}
type = V_118 -> V_130 ;
F_79 () ;
V_124 = F_80 ( type ) ;
if ( V_124 == NULL ) {
V_125 = 1 ;
goto V_131;
}
F_76 ( V_21 , sizeof( * V_118 ) ) ;
V_113 = V_124 -> V_132 . V_133 ( V_109 , V_21 ) ;
V_131:
F_81 () ;
V_126:
F_77 ( V_21 ) -> V_125 |= V_125 ;
return V_113 ;
}
static int F_82 ( struct V_20 * V_21 , int V_134 )
{
struct V_117 * V_118 ;
struct V_123 * V_124 ;
T_2 type ;
int V_135 = sizeof( struct V_114 ) + sizeof( struct V_117 ) ;
int V_94 = - V_136 ;
V_118 = (struct V_117 * ) ( V_21 -> V_128 + V_134 + sizeof( struct V_114 ) ) ;
type = V_118 -> V_130 ;
F_79 () ;
V_124 = F_83 ( type ) ;
if ( V_124 != NULL )
V_94 = V_124 -> V_132 . V_137 ( V_21 , V_134 + V_135 ) ;
F_81 () ;
return V_94 ;
}
static void F_84 ( struct V_24 * V_25 )
{
struct V_99 * V_72 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_85 ( V_43 ) ;
T_6 V_5 = V_43 -> V_138 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
int V_94 ;
if ( V_5 == V_18 ) {
V_94 = F_86 ( & V_25 -> V_139 ) ;
if ( V_94 )
F_87 ( L_1 , V_94 ) ;
}
F_79 () ;
F_88 (net, dev) {
if ( V_72 -> V_140 -> V_141 )
V_72 -> V_140 -> V_141 ( V_72 , V_5 ,
V_30 ) ;
}
F_81 () ;
}
static void F_89 ( struct V_24 * V_25 )
{
struct V_99 * V_72 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_85 ( V_43 ) ;
T_6 V_5 = V_43 -> V_138 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
F_79 () ;
F_88 (net, dev) {
if ( V_72 -> V_140 -> V_142 )
V_72 -> V_140 -> V_142 ( V_72 , V_5 ,
V_30 ) ;
}
F_81 () ;
if ( V_5 == V_18 )
F_90 ( & V_25 -> V_139 ) ;
}
static int F_91 ( struct V_45 * V_46 ,
const T_4 * V_107 , union V_1 * V_13 ,
T_7 V_70 , T_7 V_51 ,
T_2 V_30 , V_93 V_110 , V_93 V_73 ,
T_8 V_74 )
{
struct V_37 * V_100 ;
int V_143 = 0 ;
V_100 = F_60 ( V_46 , V_107 ) ;
if ( V_100 ) {
if ( V_51 & V_144 ) {
F_92 ( V_46 -> V_72 ,
L_2 , V_107 ) ;
return - V_145 ;
}
if ( V_100 -> V_70 != V_70 ) {
V_100 -> V_70 = V_70 ;
V_100 -> V_90 = V_54 ;
V_143 = 1 ;
}
if ( V_100 -> V_51 != V_74 ) {
V_100 -> V_51 = V_74 ;
V_100 -> V_90 = V_54 ;
V_143 = 1 ;
}
if ( ( V_51 & V_146 ) ) {
if ( ! ( F_93 ( V_100 -> V_67 ) ||
F_34 ( V_100 -> V_67 ) ) ) {
int V_147 = F_65 ( V_100 , V_13 , V_30 , V_110 ,
V_73 ) ;
if ( V_147 < 0 )
return V_147 ;
V_143 |= V_147 ;
} else
return - V_148 ;
}
if ( ( V_51 & V_149 ) &&
( F_93 ( V_100 -> V_67 ) ||
F_34 ( V_100 -> V_67 ) ) ) {
int V_147 = F_67 ( V_100 , V_13 , V_30 , V_110 , V_73 ) ;
if ( V_147 < 0 )
return V_147 ;
V_143 |= V_147 ;
}
} else {
if ( ! ( V_51 & V_150 ) )
return - V_151 ;
if ( V_46 -> V_152 && V_46 -> V_153 >= V_46 -> V_152 )
return - V_154 ;
if ( ( V_51 & V_146 ) &&
( F_93 ( V_107 ) || F_34 ( V_107 ) ) )
return - V_148 ;
F_92 ( V_46 -> V_72 , L_3 , V_107 , V_13 ) ;
V_100 = F_68 ( sizeof( * V_100 ) , V_96 ) ;
if ( ! V_100 )
return - V_155 ;
V_143 = 1 ;
V_100 -> V_70 = V_70 ;
V_100 -> V_51 = V_74 ;
V_100 -> V_90 = V_100 -> V_87 = V_54 ;
F_52 ( & V_100 -> V_39 ) ;
memcpy ( V_100 -> V_67 , V_107 , V_78 ) ;
F_67 ( V_100 , V_13 , V_30 , V_110 , V_73 ) ;
++ V_46 -> V_153 ;
F_94 ( & V_100 -> V_156 ,
F_59 ( V_46 , V_107 ) ) ;
}
if ( V_143 )
F_43 ( V_46 , V_100 , V_157 ) ;
return 0 ;
}
static void F_95 ( struct V_158 * V_109 )
{
struct V_37 * V_100 = F_96 ( V_109 , struct V_37 , V_159 ) ;
struct V_36 * V_111 , * V_160 ;
F_97 (rd, nd, &f->remotes, list)
F_98 ( V_111 ) ;
F_98 ( V_100 ) ;
}
static void F_99 ( struct V_45 * V_46 , struct V_37 * V_100 )
{
F_92 ( V_46 -> V_72 ,
L_4 , V_100 -> V_67 ) ;
-- V_46 -> V_153 ;
F_43 ( V_46 , V_100 , V_161 ) ;
F_100 ( & V_100 -> V_156 ) ;
F_101 ( & V_100 -> V_159 , F_95 ) ;
}
static int F_102 ( struct V_14 * V_162 [] , struct V_45 * V_46 ,
union V_1 * V_13 , T_2 * V_30 , T_1 * V_110 , T_1 * V_73 )
{
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
int V_94 ;
if ( V_162 [ V_76 ] ) {
V_94 = F_10 ( V_13 , V_162 [ V_76 ] ) ;
if ( V_94 )
return V_94 ;
} else {
union V_1 * V_102 = & V_46 -> V_47 . V_66 ;
if ( V_102 -> V_4 . V_5 == V_18 ) {
V_13 -> sin . V_9 . V_10 = F_5 ( V_12 ) ;
V_13 -> V_4 . V_5 = V_18 ;
#if F_103 ( V_163 )
} else {
V_13 -> V_7 . V_8 = V_164 ;
V_13 -> V_4 . V_5 = V_6 ;
#endif
}
}
if ( V_162 [ V_82 ] ) {
if ( F_11 ( V_162 [ V_82 ] ) != sizeof( T_2 ) )
return - V_165 ;
* V_30 = F_104 ( V_162 [ V_82 ] ) ;
} else {
* V_30 = V_46 -> V_81 ;
}
if ( V_162 [ V_83 ] ) {
if ( F_11 ( V_162 [ V_83 ] ) != sizeof( T_1 ) )
return - V_165 ;
* V_110 = F_105 ( V_162 [ V_83 ] ) ;
} else {
* V_110 = V_46 -> V_47 . V_48 ;
}
if ( V_162 [ V_85 ] ) {
struct V_99 * V_166 ;
if ( F_11 ( V_162 [ V_85 ] ) != sizeof( T_1 ) )
return - V_165 ;
* V_73 = F_105 ( V_162 [ V_85 ] ) ;
V_166 = F_106 ( V_29 , * V_73 ) ;
if ( ! V_166 )
return - V_167 ;
} else {
* V_73 = 0 ;
}
return 0 ;
}
static int F_107 ( struct V_59 * V_60 , struct V_14 * V_162 [] ,
struct V_99 * V_72 ,
const unsigned char * V_104 , T_9 V_51 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_110 , V_73 ;
int V_94 ;
if ( ! ( V_60 -> V_69 & ( V_168 | V_169 ) ) ) {
F_108 ( L_5 ,
V_60 -> V_69 ) ;
return - V_165 ;
}
if ( V_162 [ V_76 ] == NULL )
return - V_165 ;
V_94 = F_102 ( V_162 , V_46 , & V_13 , & V_30 , & V_110 , & V_73 ) ;
if ( V_94 )
return V_94 ;
F_109 ( & V_46 -> V_170 ) ;
V_94 = F_91 ( V_46 , V_104 , & V_13 , V_60 -> V_69 , V_51 ,
V_30 , V_110 , V_73 , V_60 -> V_74 ) ;
F_110 ( & V_46 -> V_170 ) ;
return V_94 ;
}
static int F_111 ( struct V_59 * V_60 , struct V_14 * V_162 [] ,
struct V_99 * V_72 ,
const unsigned char * V_104 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_100 ;
struct V_36 * V_111 = NULL ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_110 , V_73 ;
int V_94 ;
V_94 = F_102 ( V_162 , V_46 , & V_13 , & V_30 , & V_110 , & V_73 ) ;
if ( V_94 )
return V_94 ;
V_94 = - V_151 ;
F_109 ( & V_46 -> V_170 ) ;
V_100 = F_62 ( V_46 , V_104 ) ;
if ( ! V_100 )
goto V_126;
if ( ! F_3 ( & V_13 ) ) {
V_111 = F_63 ( V_100 , & V_13 , V_30 , V_110 , V_73 ) ;
if ( ! V_111 )
goto V_126;
}
V_94 = 0 ;
if ( V_111 && ! F_112 ( & V_100 -> V_39 ) ) {
F_113 ( & V_111 -> V_41 ) ;
F_114 ( V_111 , V_159 ) ;
goto V_126;
}
F_99 ( V_46 , V_100 ) ;
V_126:
F_110 ( & V_46 -> V_170 ) ;
return V_94 ;
}
static int F_115 ( struct V_20 * V_21 , struct V_171 * V_172 ,
struct V_99 * V_72 , int V_173 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_174 ;
for ( V_174 = 0 ; V_174 < V_175 ; ++ V_174 ) {
struct V_37 * V_100 ;
int V_94 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_111 ;
if ( V_173 < V_172 -> args [ 0 ] )
goto V_176;
F_116 (rd, &f->remotes, list) {
V_94 = F_31 ( V_21 , V_46 , V_100 ,
F_117 ( V_172 -> V_21 ) . V_49 ,
V_172 -> V_58 -> V_177 ,
V_157 ,
V_178 , V_111 ) ;
if ( V_94 < 0 )
goto V_126;
}
V_176:
++ V_173 ;
}
}
V_126:
return V_173 ;
}
static bool F_118 ( struct V_99 * V_72 ,
union V_1 * V_179 , const T_4 * V_180 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_100 ;
V_100 = F_62 ( V_46 , V_180 ) ;
if ( F_119 ( V_100 ) ) {
struct V_36 * V_52 = F_22 ( V_100 ) ;
if ( F_119 ( F_1 ( & V_52 -> V_66 , V_179 ) ) )
return false ;
if ( V_100 -> V_70 & V_181 )
return true ;
if ( F_120 () )
F_121 ( V_72 ,
L_6 ,
V_180 , & V_52 -> V_66 , & V_179 ) ;
V_52 -> V_66 = * V_179 ;
V_100 -> V_90 = V_54 ;
F_43 ( V_46 , V_100 , V_157 ) ;
} else {
F_122 ( & V_46 -> V_170 ) ;
if ( F_123 ( V_72 ) )
F_91 ( V_46 , V_180 , V_179 ,
V_169 ,
V_144 | V_150 ,
V_46 -> V_81 ,
V_46 -> V_47 . V_48 ,
0 , V_182 ) ;
F_124 ( & V_46 -> V_170 ) ;
}
return false ;
}
static bool F_125 ( struct V_31 * V_32 , struct V_45 * V_72 )
{
struct V_45 * V_46 ;
if ( F_126 ( & V_72 -> V_183 -> V_184 ) == 1 )
return false ;
F_64 (vxlan, &vn->vxlan_list, next) {
if ( ! F_123 ( V_46 -> V_72 ) || V_46 == V_72 )
continue;
if ( V_46 -> V_183 != V_72 -> V_183 )
continue;
if ( ! F_1 ( & V_46 -> V_47 . V_66 ,
& V_72 -> V_47 . V_66 ) )
continue;
if ( V_46 -> V_47 . V_84 !=
V_72 -> V_47 . V_84 )
continue;
return true ;
}
return false ;
}
static void F_127 ( struct V_24 * V_25 )
{
F_128 ( & V_25 -> V_184 ) ;
}
void F_129 ( struct V_24 * V_25 )
{
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_85 ( V_43 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_130 ( & V_25 -> V_184 ) )
return;
F_122 ( & V_32 -> V_185 ) ;
F_100 ( & V_25 -> V_156 ) ;
F_131 ( V_25 -> V_42 -> V_43 , NULL ) ;
F_89 ( V_25 ) ;
F_124 ( & V_32 -> V_185 ) ;
F_132 ( V_186 , & V_25 -> V_187 ) ;
}
static void F_133 ( struct V_188 * V_189 )
{
struct V_45 * V_46 = F_96 ( V_189 , struct V_45 , V_190 ) ;
struct V_24 * V_25 = V_46 -> V_183 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_84 ;
F_134 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_191 V_192 = {
. V_193 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_194 = V_73 ,
} ;
F_135 ( V_43 , & V_192 ) ;
#if F_103 ( V_163 )
} else {
V_195 -> V_196 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_136 ( V_43 ) ;
F_129 ( V_25 ) ;
F_137 ( V_46 -> V_72 ) ;
}
static void F_138 ( struct V_188 * V_189 )
{
struct V_45 * V_46 = F_96 ( V_189 , struct V_45 , V_197 ) ;
struct V_24 * V_25 = V_46 -> V_183 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_84 ;
F_134 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_191 V_192 = {
. V_193 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_194 = V_73 ,
} ;
F_139 ( V_43 , & V_192 ) ;
#if F_103 ( V_163 )
} else {
V_195 -> V_198 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_136 ( V_43 ) ;
F_129 ( V_25 ) ;
F_137 ( V_46 -> V_72 ) ;
}
static int F_140 ( struct V_42 * V_43 , struct V_20 * V_21 )
{
struct V_24 * V_25 ;
struct V_114 * V_199 ;
T_2 V_30 ;
if ( ! F_141 ( V_21 , V_200 ) )
goto error;
V_199 = (struct V_114 * ) ( F_142 ( V_21 ) + 1 ) ;
if ( V_199 -> V_201 != F_5 ( V_202 ) ||
( V_199 -> V_129 & F_5 ( 0xff ) ) ) {
F_92 ( V_21 -> V_72 , L_7 ,
F_9 ( V_199 -> V_201 ) , F_9 ( V_199 -> V_129 ) ) ;
goto error;
}
if ( F_143 ( V_21 , V_200 , F_144 ( V_203 ) ) )
goto V_204;
V_30 = F_28 ( V_43 ) -> V_44 ;
V_25 = F_145 ( V_43 ) ;
if ( ! V_25 )
goto V_204;
if ( ( V_21 -> V_205 != V_206 && V_21 -> V_205 != V_207 ) ||
! V_21 -> V_208 )
V_21 -> V_205 = V_209 ;
V_21 -> V_208 = 0 ;
V_25 -> V_210 ( V_25 , V_21 , V_199 -> V_129 ) ;
return 0 ;
V_204:
F_47 ( V_21 ) ;
return 0 ;
error:
return 1 ;
}
static void F_146 ( struct V_24 * V_25 ,
struct V_20 * V_21 , V_17 V_129 )
{
struct V_211 * V_212 = NULL ;
struct V_213 * V_214 = NULL ;
struct V_45 * V_46 ;
struct V_215 * V_216 ;
union V_1 V_217 ;
V_93 V_110 ;
int V_94 = 0 ;
union V_1 * V_66 ;
V_110 = F_9 ( V_129 ) >> 8 ;
V_46 = F_29 ( V_25 , V_110 ) ;
if ( ! V_46 )
goto V_204;
V_66 = & V_46 -> V_47 . V_66 ;
F_147 ( V_21 ) ;
V_21 -> V_218 = F_148 ( V_21 , V_46 -> V_72 ) ;
if ( F_61 ( F_149 ( V_21 ) -> V_219 , V_46 -> V_72 -> V_220 ) )
goto V_204;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_212 = F_150 ( V_21 ) ;
V_217 . sin . V_9 . V_10 = V_212 -> V_217 ;
V_217 . V_4 . V_5 = V_18 ;
#if F_103 ( V_163 )
} else {
V_214 = F_151 ( V_21 ) ;
V_217 . V_7 . V_8 = V_214 -> V_217 ;
V_217 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_46 -> V_51 & V_221 ) &&
F_118 ( V_21 -> V_72 , & V_217 , F_149 ( V_21 ) -> V_219 ) )
goto V_204;
F_152 ( V_21 ) ;
if ( V_214 )
V_94 = F_153 ( V_214 , V_21 ) ;
if ( V_212 )
V_94 = F_154 ( V_212 , V_21 ) ;
if ( F_75 ( V_94 ) ) {
if ( V_222 ) {
if ( V_214 )
F_155 ( L_8 ,
& V_214 -> V_217 ) ;
if ( V_212 )
F_155 ( L_9 ,
& V_212 -> V_217 , V_212 -> V_223 ) ;
}
if ( V_94 > 1 ) {
++ V_46 -> V_72 -> V_216 . V_224 ;
++ V_46 -> V_72 -> V_216 . V_225 ;
goto V_204;
}
}
V_216 = F_156 ( V_46 -> V_72 -> V_226 ) ;
F_157 ( & V_216 -> V_227 ) ;
V_216 -> V_228 ++ ;
V_216 -> V_229 += V_21 -> V_230 ;
F_158 ( & V_216 -> V_227 ) ;
F_159 ( V_21 ) ;
return;
V_204:
F_47 ( V_21 ) ;
}
static int F_160 ( struct V_99 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_231 * V_232 ;
T_4 * V_233 , * V_234 ;
V_17 V_235 , V_236 ;
struct V_237 * V_238 ;
if ( V_72 -> V_51 & V_239 )
goto V_126;
if ( ! F_141 ( V_21 , F_161 ( V_72 ) ) ) {
V_72 -> V_216 . V_240 ++ ;
goto V_126;
}
V_232 = F_162 ( V_21 ) ;
if ( ( V_232 -> V_241 != F_144 ( V_242 ) &&
V_232 -> V_241 != F_144 ( V_243 ) ) ||
V_232 -> V_244 != F_144 ( V_245 ) ||
V_232 -> V_246 != F_144 ( V_247 ) ||
V_232 -> V_248 != V_72 -> V_249 ||
V_232 -> V_250 != 4 )
goto V_126;
V_233 = ( T_4 * ) V_232 + sizeof( struct V_231 ) ;
V_234 = V_233 ;
V_233 += V_72 -> V_249 ;
memcpy ( & V_235 , V_233 , sizeof( V_235 ) ) ;
V_233 += sizeof( V_235 ) ;
V_233 += V_72 -> V_249 ;
memcpy ( & V_236 , V_233 , sizeof( V_236 ) ) ;
if ( F_163 ( V_236 ) ||
F_164 ( V_236 ) )
goto V_126;
V_238 = F_165 ( & V_251 , & V_236 , V_72 ) ;
if ( V_238 ) {
struct V_37 * V_100 ;
struct V_20 * V_252 ;
if ( ! ( V_238 -> V_253 & V_254 ) ) {
F_166 ( V_238 ) ;
goto V_126;
}
V_100 = F_62 ( V_46 , V_238 -> V_255 ) ;
if ( V_100 && F_3 ( & ( F_22 ( V_100 ) -> V_66 ) ) ) {
F_166 ( V_238 ) ;
goto V_126;
}
V_252 = F_167 ( V_256 , V_257 , V_235 , V_72 , V_236 , V_234 ,
V_238 -> V_255 , V_234 ) ;
F_166 ( V_238 ) ;
if ( V_252 == NULL )
goto V_126;
F_147 ( V_252 ) ;
F_168 ( V_252 , F_169 ( V_252 ) ) ;
V_252 -> V_205 = V_206 ;
V_252 -> V_258 = V_259 ;
if ( F_170 ( V_252 ) == V_260 )
V_72 -> V_216 . V_261 ++ ;
} else if ( V_46 -> V_51 & V_262 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_236 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_126:
F_171 ( V_21 ) ;
return V_263 ;
}
static struct V_20 * F_172 ( struct V_20 * V_264 ,
struct V_237 * V_238 , bool V_265 )
{
struct V_99 * V_72 = V_264 -> V_72 ;
struct V_20 * V_252 ;
struct V_266 * V_267 , * V_268 ;
struct V_213 * V_269 ;
T_4 * V_270 ;
int V_271 = 8 ;
int V_272 ;
int V_273 , V_230 ;
if ( V_72 == NULL )
return NULL ;
V_230 = F_173 ( V_72 ) + sizeof( struct V_213 ) +
sizeof( * V_268 ) + V_271 + V_72 -> V_274 ;
V_252 = F_174 ( V_230 , V_96 ) ;
if ( V_252 == NULL )
return NULL ;
V_252 -> V_218 = F_144 ( V_275 ) ;
V_252 -> V_72 = V_72 ;
F_175 ( V_252 , F_173 ( V_264 -> V_72 ) ) ;
F_176 ( V_252 , sizeof( struct V_117 ) ) ;
F_177 ( V_252 , 0 ) ;
V_267 = (struct V_266 * ) F_178 ( V_264 ) ;
V_270 = F_149 ( V_264 ) -> V_219 ;
V_272 = V_264 -> V_230 - F_179 ( V_264 ) - sizeof( * V_267 ) ;
for ( V_273 = 0 ; V_273 < V_272 - 1 ; V_273 += ( V_267 -> V_276 [ V_273 + 1 ] << 3 ) ) {
if ( V_267 -> V_276 [ V_273 ] == V_277 ) {
V_270 = V_267 -> V_276 + V_273 + sizeof( struct V_278 ) ;
break;
}
}
F_180 ( F_149 ( V_252 ) -> V_279 , V_270 ) ;
F_180 ( F_149 ( V_252 ) -> V_219 , V_238 -> V_255 ) ;
F_149 ( V_252 ) -> V_130 = F_144 ( V_275 ) ;
V_252 -> V_218 = F_144 ( V_275 ) ;
F_181 ( V_252 , sizeof( struct V_117 ) ) ;
F_182 ( V_252 , 0 ) ;
F_183 ( V_252 , sizeof( struct V_213 ) ) ;
V_269 = F_151 ( V_252 ) ;
memset ( V_269 , 0 , sizeof( struct V_213 ) ) ;
V_269 -> V_280 = 6 ;
V_269 -> V_281 = F_151 ( V_264 ) -> V_281 ;
V_269 -> V_282 = V_283 ;
V_269 -> V_284 = 255 ;
V_269 -> V_270 = F_151 ( V_264 ) -> V_217 ;
V_269 -> V_217 = * (struct V_16 * ) V_238 -> V_285 ;
F_181 ( V_252 , sizeof( struct V_213 ) ) ;
F_184 ( V_252 , 0 ) ;
V_268 = (struct V_266 * ) F_183 ( V_252 , sizeof( * V_268 ) + V_271 ) ;
memset ( V_268 , 0 , sizeof( * V_268 ) + V_271 ) ;
V_268 -> V_286 . V_287 = V_288 ;
V_268 -> V_286 . V_289 = V_265 ;
V_268 -> V_286 . V_290 = 1 ;
V_268 -> V_286 . V_291 = 1 ;
V_268 -> V_292 = V_267 -> V_292 ;
F_180 ( & V_268 -> V_276 [ 2 ] , V_238 -> V_255 ) ;
V_268 -> V_276 [ 0 ] = V_293 ;
V_268 -> V_276 [ 1 ] = V_271 >> 3 ;
V_268 -> V_286 . V_294 = F_185 ( & V_269 -> V_217 ,
& V_269 -> V_270 , sizeof( * V_268 ) + V_271 , V_283 ,
F_186 ( V_268 , sizeof( * V_268 ) + V_271 , 0 ) ) ;
V_269 -> V_295 = F_144 ( sizeof( * V_268 ) + V_271 ) ;
F_176 ( V_252 , sizeof( struct V_213 ) ) ;
V_252 -> V_205 = V_206 ;
return V_252 ;
}
static int F_187 ( struct V_99 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_266 * V_296 ;
const struct V_213 * V_211 ;
const struct V_16 * V_217 , * V_270 ;
struct V_237 * V_238 ;
struct V_297 * V_298 ;
V_298 = F_188 ( V_72 ) ;
if ( ! V_298 )
goto V_126;
if ( ! F_141 ( V_21 , V_21 -> V_230 ) )
goto V_126;
V_211 = F_151 ( V_21 ) ;
V_217 = & V_211 -> V_217 ;
V_270 = & V_211 -> V_270 ;
V_296 = (struct V_266 * ) F_178 ( V_21 ) ;
if ( V_296 -> V_286 . V_299 != 0 ||
V_296 -> V_286 . V_287 != V_300 )
goto V_126;
if ( F_189 ( V_270 ) ||
F_7 ( & V_296 -> V_292 ) )
goto V_126;
V_238 = F_165 ( V_195 -> V_301 , & V_296 -> V_292 , V_72 ) ;
if ( V_238 ) {
struct V_37 * V_100 ;
struct V_20 * V_252 ;
if ( ! ( V_238 -> V_253 & V_254 ) ) {
F_166 ( V_238 ) ;
goto V_126;
}
V_100 = F_62 ( V_46 , V_238 -> V_255 ) ;
if ( V_100 && F_3 ( & ( F_22 ( V_100 ) -> V_66 ) ) ) {
F_166 ( V_238 ) ;
goto V_126;
}
V_252 = F_172 ( V_21 , V_238 ,
! ! ( V_100 ? V_100 -> V_51 & V_302 : 0 ) ) ;
F_166 ( V_238 ) ;
if ( V_252 == NULL )
goto V_126;
if ( F_170 ( V_252 ) == V_260 )
V_72 -> V_216 . V_261 ++ ;
} else if ( V_46 -> V_51 & V_262 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_296 -> V_292 ,
. V_4 . V_5 = V_6 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_126:
F_171 ( V_21 ) ;
return V_263 ;
}
static bool F_190 ( struct V_99 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_237 * V_238 ;
if ( F_93 ( F_149 ( V_21 ) -> V_279 ) )
return false ;
V_238 = NULL ;
switch ( F_21 ( F_149 ( V_21 ) -> V_130 ) ) {
case V_245 :
{
struct V_211 * V_303 ;
if ( ! F_141 ( V_21 , sizeof( struct V_211 ) ) )
return false ;
V_303 = F_150 ( V_21 ) ;
V_238 = F_165 ( & V_251 , & V_303 -> V_270 , V_72 ) ;
if ( ! V_238 && ( V_46 -> V_51 & V_262 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_303 -> V_270 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
return false ;
}
break;
}
#if F_103 ( V_163 )
case V_275 :
{
struct V_213 * V_269 ;
if ( ! F_141 ( V_21 , sizeof( struct V_213 ) ) )
return false ;
V_269 = F_151 ( V_21 ) ;
V_238 = F_165 ( V_195 -> V_301 , & V_269 -> V_270 , V_72 ) ;
if ( ! V_238 && ( V_46 -> V_51 & V_262 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_269 -> V_270 ,
. V_4 . V_5 = V_6 ,
} ;
F_50 ( V_72 , & V_11 ) ;
return false ;
}
break;
}
#endif
default:
return false ;
}
if ( V_238 ) {
bool V_304 ;
V_304 = ! F_61 ( F_149 ( V_21 ) -> V_279 , V_238 -> V_255 ) ;
if ( V_304 ) {
memcpy ( F_149 ( V_21 ) -> V_219 , F_149 ( V_21 ) -> V_279 ,
V_72 -> V_249 ) ;
memcpy ( F_149 ( V_21 ) -> V_279 , V_238 -> V_255 , V_72 -> V_249 ) ;
}
F_166 ( V_238 ) ;
return V_304 ;
}
return false ;
}
T_2 F_191 ( T_7 V_305 , T_7 V_306 , struct V_20 * V_21 )
{
unsigned int V_307 = ( V_306 - V_305 ) + 1 ;
T_1 V_308 ;
V_308 = F_192 ( V_21 ) ;
if ( ! V_308 )
V_308 = F_193 ( V_21 -> V_128 , 2 * V_78 ,
( V_309 T_1 ) V_21 -> V_218 ) ;
return F_144 ( ( ( ( T_5 ) V_308 * V_307 ) >> 32 ) + V_305 ) ;
}
static int F_194 ( struct V_20 * V_21 )
{
if ( F_195 ( V_21 ) ) {
int V_94 = F_196 ( V_21 , V_96 ) ;
if ( F_75 ( V_94 ) )
return V_94 ;
F_197 ( V_21 ) -> V_310 |= V_311 ;
} else if ( V_21 -> V_205 != V_207 )
V_21 -> V_205 = V_209 ;
return 0 ;
}
static int F_198 ( struct V_24 * V_25 ,
struct V_312 * V_313 , struct V_20 * V_21 ,
struct V_99 * V_72 , struct V_16 * V_217 ,
struct V_16 * V_270 , T_8 V_314 , T_8 V_315 ,
T_2 V_316 , T_2 V_81 , V_17 V_110 )
{
struct V_213 * V_317 ;
struct V_114 * V_199 ;
struct V_318 * V_319 ;
int V_320 ;
int V_94 ;
if ( ! V_21 -> V_208 ) {
F_199 ( V_21 ) ;
V_21 -> V_208 = 1 ;
}
F_200 ( V_21 , false ) ;
V_320 = F_173 ( V_313 -> V_72 ) + V_313 -> V_321
+ V_200 + sizeof( struct V_213 )
+ ( F_201 ( V_21 ) ? V_322 : 0 ) ;
V_94 = F_202 ( V_21 , V_320 ) ;
if ( F_75 ( V_94 ) )
return V_94 ;
if ( F_201 ( V_21 ) ) {
if ( F_46 ( ! F_203 ( V_21 ,
V_21 -> V_323 ,
F_204 ( V_21 ) ) ) )
return - V_155 ;
V_21 -> V_324 = 0 ;
}
V_199 = (struct V_114 * ) F_205 ( V_21 , sizeof( * V_199 ) ) ;
V_199 -> V_201 = F_5 ( V_202 ) ;
V_199 -> V_129 = V_110 ;
F_205 ( V_21 , sizeof( * V_319 ) ) ;
F_206 ( V_21 ) ;
V_319 = F_142 ( V_21 ) ;
V_319 -> V_325 = V_81 ;
V_319 -> V_326 = V_316 ;
V_319 -> V_230 = F_144 ( V_21 -> V_230 ) ;
V_319 -> V_327 = 0 ;
memset ( & ( F_207 ( V_21 ) -> V_276 ) , 0 , sizeof( F_207 ( V_21 ) -> V_276 ) ) ;
F_207 ( V_21 ) -> V_51 &= ~ ( V_328 | V_329 |
V_330 ) ;
F_208 ( V_21 , V_313 ) ;
if ( ! F_195 ( V_21 ) && ! ( V_313 -> V_72 -> V_331 & V_332 ) ) {
T_10 V_333 = F_209 ( V_21 , 0 , V_21 -> V_230 , 0 ) ;
V_21 -> V_205 = V_206 ;
V_319 -> V_327 = F_185 ( V_217 , V_270 , V_21 -> V_230 ,
V_334 , V_333 ) ;
if ( V_319 -> V_327 == 0 )
V_319 -> V_327 = V_335 ;
} else {
V_21 -> V_205 = V_207 ;
V_21 -> V_336 = F_178 ( V_21 ) - V_21 -> V_109 ;
V_21 -> V_337 = F_210 ( struct V_318 , V_327 ) ;
V_319 -> V_327 = ~ F_185 ( V_217 , V_270 ,
V_21 -> V_230 , V_334 , 0 ) ;
}
F_205 ( V_21 , sizeof( * V_317 ) ) ;
F_152 ( V_21 ) ;
V_317 = F_151 ( V_21 ) ;
V_317 -> V_280 = 6 ;
V_317 -> V_281 = V_314 ;
V_317 -> V_338 [ 0 ] = 0 ;
V_317 -> V_338 [ 1 ] = 0 ;
V_317 -> V_338 [ 2 ] = 0 ;
V_317 -> V_295 = F_144 ( V_21 -> V_230 ) ;
V_317 -> V_282 = V_334 ;
V_317 -> V_284 = V_315 ;
V_317 -> V_270 = * V_270 ;
V_317 -> V_217 = * V_217 ;
V_94 = F_194 ( V_21 ) ;
if ( V_94 )
return V_94 ;
F_211 ( V_21 , V_72 ) ;
return 0 ;
}
int F_212 ( struct V_24 * V_25 ,
struct V_339 * V_340 , struct V_20 * V_21 ,
V_17 V_341 , V_17 V_313 , T_8 V_223 , T_8 V_315 , T_2 V_342 ,
T_2 V_316 , T_2 V_81 , V_17 V_110 )
{
struct V_114 * V_199 ;
struct V_318 * V_319 ;
int V_320 ;
int V_94 ;
if ( ! V_21 -> V_208 ) {
F_199 ( V_21 ) ;
V_21 -> V_208 = 1 ;
}
V_320 = F_173 ( V_340 -> V_313 . V_72 ) + V_340 -> V_313 . V_321
+ V_200 + sizeof( struct V_211 )
+ ( F_201 ( V_21 ) ? V_322 : 0 ) ;
V_94 = F_202 ( V_21 , V_320 ) ;
if ( F_75 ( V_94 ) )
return V_94 ;
if ( F_201 ( V_21 ) ) {
if ( F_46 ( ! F_203 ( V_21 ,
V_21 -> V_323 ,
F_204 ( V_21 ) ) ) )
return - V_155 ;
V_21 -> V_324 = 0 ;
}
V_199 = (struct V_114 * ) F_205 ( V_21 , sizeof( * V_199 ) ) ;
V_199 -> V_201 = F_5 ( V_202 ) ;
V_199 -> V_129 = V_110 ;
F_205 ( V_21 , sizeof( * V_319 ) ) ;
F_206 ( V_21 ) ;
V_319 = F_142 ( V_21 ) ;
V_319 -> V_325 = V_81 ;
V_319 -> V_326 = V_316 ;
V_319 -> V_230 = F_144 ( V_21 -> V_230 ) ;
V_319 -> V_327 = 0 ;
V_94 = F_194 ( V_21 ) ;
if ( V_94 )
return V_94 ;
return F_213 ( V_340 , V_21 , V_341 , V_313 , V_334 , V_223 , V_315 , V_342 ,
false ) ;
}
static void F_214 ( struct V_20 * V_21 , struct V_45 * V_343 ,
struct V_45 * V_344 )
{
struct V_215 * V_345 , * V_346 ;
union V_1 V_347 ;
union V_1 * V_66 = & V_344 -> V_47 . V_66 ;
V_345 = F_156 ( V_343 -> V_72 -> V_226 ) ;
V_346 = F_156 ( V_344 -> V_72 -> V_226 ) ;
V_21 -> V_258 = V_259 ;
V_21 -> V_208 = 0 ;
V_21 -> V_72 = V_344 -> V_72 ;
F_168 ( V_21 , F_169 ( V_21 ) ) ;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_347 . sin . V_9 . V_10 = F_5 ( V_348 ) ;
V_347 . V_4 . V_5 = V_18 ;
#if F_103 ( V_163 )
} else {
V_347 . V_7 . V_8 = V_349 ;
V_347 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_344 -> V_51 & V_221 )
F_118 ( V_21 -> V_72 , & V_347 , F_149 ( V_21 ) -> V_219 ) ;
F_157 ( & V_345 -> V_227 ) ;
V_345 -> V_350 ++ ;
V_345 -> V_351 += V_21 -> V_230 ;
F_158 ( & V_345 -> V_227 ) ;
if ( F_159 ( V_21 ) == V_352 ) {
F_157 ( & V_346 -> V_227 ) ;
V_346 -> V_228 ++ ;
V_346 -> V_229 += V_21 -> V_230 ;
F_158 ( & V_346 -> V_227 ) ;
} else {
V_21 -> V_72 -> V_216 . V_261 ++ ;
}
}
static void F_215 ( struct V_20 * V_21 , struct V_99 * V_72 ,
struct V_36 * V_52 , bool V_353 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_339 * V_340 = NULL ;
const struct V_211 * V_354 ;
struct V_355 V_356 ;
union V_1 * V_313 ;
T_2 V_316 = 0 , V_81 ;
T_1 V_110 ;
T_2 V_342 = 0 ;
T_8 V_223 , V_315 ;
int V_94 ;
V_81 = V_52 -> V_80 ? V_52 -> V_80 : V_46 -> V_81 ;
V_110 = V_52 -> V_48 ;
V_313 = & V_52 -> V_66 ;
if ( F_3 ( V_313 ) ) {
if ( V_353 ) {
F_214 ( V_21 , V_46 , V_46 ) ;
return;
}
goto V_204;
}
V_354 = F_150 ( V_21 ) ;
V_315 = V_46 -> V_315 ;
if ( ! V_315 && F_6 ( V_313 ) )
V_315 = 1 ;
V_223 = V_46 -> V_223 ;
if ( V_223 == 1 )
V_223 = F_216 ( V_354 , V_21 ) ;
V_316 = F_191 ( V_46 -> V_305 , V_46 -> V_306 , V_21 ) ;
if ( V_313 -> V_4 . V_5 == V_18 ) {
memset ( & V_356 , 0 , sizeof( V_356 ) ) ;
V_356 . V_357 = V_52 -> V_84 ;
V_356 . V_358 = F_217 ( V_223 ) ;
V_356 . V_270 = V_313 -> sin . V_9 . V_10 ;
V_356 . V_217 = V_46 -> V_217 . sin . V_9 . V_10 ;
V_340 = F_218 ( F_44 ( V_72 ) , & V_356 ) ;
if ( F_219 ( V_340 ) ) {
F_92 ( V_72 , L_10 ,
& V_313 -> sin . V_9 . V_10 ) ;
V_72 -> V_216 . V_359 ++ ;
goto V_360;
}
if ( V_340 -> V_313 . V_72 == V_72 ) {
F_92 ( V_72 , L_11 ,
& V_313 -> sin . V_9 . V_10 ) ;
V_72 -> V_216 . V_361 ++ ;
goto V_362;
}
if ( V_340 -> V_363 & V_364 &&
! ( V_340 -> V_363 & ( V_365 | V_366 ) ) ) {
struct V_45 * V_344 ;
F_220 ( V_340 ) ;
V_344 = F_30 ( F_44 ( V_72 ) , V_110 , V_81 ) ;
if ( ! V_344 )
goto V_360;
F_214 ( V_21 , V_46 , V_344 ) ;
return;
}
V_223 = F_221 ( V_223 , V_354 , V_21 ) ;
V_315 = V_315 ? : F_222 ( & V_340 -> V_313 ) ;
V_94 = F_212 ( V_46 -> V_183 , V_340 , V_21 ,
V_356 . V_217 , V_313 -> sin . V_9 . V_10 ,
V_223 , V_315 , V_342 , V_316 , V_81 ,
F_5 ( V_110 << 8 ) ) ;
if ( V_94 < 0 )
goto V_362;
F_223 ( V_94 , & V_72 -> V_216 , V_72 -> V_226 ) ;
#if F_103 ( V_163 )
} else {
struct V_42 * V_43 = V_46 -> V_183 -> V_42 -> V_43 ;
struct V_312 * V_367 ;
struct V_368 V_369 ;
T_1 V_51 ;
memset ( & V_369 , 0 , sizeof( V_369 ) ) ;
V_369 . V_370 = V_52 -> V_84 ;
V_369 . V_270 = V_313 -> V_7 . V_8 ;
V_369 . V_217 = V_46 -> V_217 . V_7 . V_8 ;
V_369 . V_371 = V_334 ;
if ( V_195 -> V_372 ( V_43 , & V_367 , & V_369 ) ) {
F_92 ( V_72 , L_12 ,
& V_313 -> V_7 . V_8 ) ;
V_72 -> V_216 . V_359 ++ ;
goto V_360;
}
if ( V_367 -> V_72 == V_72 ) {
F_92 ( V_72 , L_13 ,
& V_313 -> V_7 . V_8 ) ;
F_224 ( V_367 ) ;
V_72 -> V_216 . V_361 ++ ;
goto V_360;
}
V_51 = ( (struct V_373 * ) V_367 ) -> V_374 ;
if ( V_51 & V_375 &&
! ( V_51 & ( V_365 | V_366 ) ) ) {
struct V_45 * V_344 ;
F_224 ( V_367 ) ;
V_344 = F_30 ( F_44 ( V_72 ) , V_110 , V_81 ) ;
if ( ! V_344 )
goto V_360;
F_214 ( V_21 , V_46 , V_344 ) ;
return;
}
V_315 = V_315 ? : F_225 ( V_367 ) ;
V_94 = F_198 ( V_46 -> V_183 , V_367 , V_21 ,
V_72 , & V_369 . V_217 , & V_369 . V_270 , 0 , V_315 ,
V_316 , V_81 , F_5 ( V_110 << 8 ) ) ;
#endif
}
return;
V_204:
V_72 -> V_216 . V_240 ++ ;
goto V_376;
V_362:
F_220 ( V_340 ) ;
V_360:
V_72 -> V_216 . V_377 ++ ;
V_376:
F_226 ( V_21 ) ;
}
static T_11 F_227 ( struct V_20 * V_21 , struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_117 * V_378 ;
bool V_353 = false ;
struct V_36 * V_52 , * V_379 = NULL ;
struct V_37 * V_100 ;
F_147 ( V_21 ) ;
V_378 = F_149 ( V_21 ) ;
if ( ( V_46 -> V_51 & V_380 ) ) {
if ( F_21 ( V_378 -> V_130 ) == V_257 )
return F_160 ( V_72 , V_21 ) ;
#if F_103 ( V_163 )
else if ( F_21 ( V_378 -> V_130 ) == V_275 &&
V_21 -> V_230 >= sizeof( struct V_213 ) + sizeof( struct V_266 ) &&
F_151 ( V_21 ) -> V_282 == V_283 ) {
struct V_266 * V_296 ;
V_296 = (struct V_266 * ) F_178 ( V_21 ) ;
if ( V_296 -> V_286 . V_299 == 0 &&
V_296 -> V_286 . V_287 == V_300 )
return F_187 ( V_72 , V_21 ) ;
}
#endif
}
V_100 = F_62 ( V_46 , V_378 -> V_279 ) ;
V_353 = false ;
if ( V_100 && ( V_100 -> V_51 & V_302 ) && ( V_46 -> V_51 & V_381 ) &&
( F_21 ( V_378 -> V_130 ) == V_245 ||
F_21 ( V_378 -> V_130 ) == V_275 ) ) {
V_353 = F_190 ( V_72 , V_21 ) ;
if ( V_353 )
V_100 = F_62 ( V_46 , V_378 -> V_279 ) ;
}
if ( V_100 == NULL ) {
V_100 = F_62 ( V_46 , V_382 ) ;
if ( V_100 == NULL ) {
if ( ( V_46 -> V_51 & V_383 ) &&
! F_93 ( V_378 -> V_279 ) )
F_54 ( V_46 , V_378 -> V_279 ) ;
V_72 -> V_216 . V_240 ++ ;
F_47 ( V_21 ) ;
return V_263 ;
}
}
F_116 (rdst, &f->remotes, list) {
struct V_20 * V_384 ;
if ( ! V_379 ) {
V_379 = V_52 ;
continue;
}
V_384 = F_228 ( V_21 , V_96 ) ;
if ( V_384 )
F_215 ( V_384 , V_72 , V_52 , V_353 ) ;
}
if ( V_379 )
F_215 ( V_21 , V_72 , V_379 , V_353 ) ;
else
F_47 ( V_21 ) ;
return V_263 ;
}
static void F_229 ( unsigned long V_385 )
{
struct V_45 * V_46 = (struct V_45 * ) V_385 ;
unsigned long V_386 = V_54 + V_387 ;
unsigned int V_174 ;
if ( ! F_123 ( V_46 -> V_72 ) )
return;
F_109 ( & V_46 -> V_170 ) ;
for ( V_174 = 0 ; V_174 < V_175 ; ++ V_174 ) {
struct V_388 * V_112 , * V_238 ;
F_230 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_100
= F_96 ( V_112 , struct V_37 , V_156 ) ;
unsigned long V_389 ;
if ( V_100 -> V_70 & V_168 )
continue;
V_389 = V_100 -> V_87 + V_46 -> V_390 * V_391 ;
if ( F_231 ( V_389 , V_54 ) ) {
F_92 ( V_46 -> V_72 ,
L_14 ,
V_100 -> V_67 ) ;
V_100 -> V_70 = V_101 ;
F_99 ( V_46 , V_100 ) ;
} else if ( F_232 ( V_389 , V_386 ) )
V_386 = V_389 ;
}
}
F_110 ( & V_46 -> V_170 ) ;
F_233 ( & V_46 -> V_392 , V_386 ) ;
}
static void F_234 ( struct V_24 * V_25 , struct V_45 * V_46 )
{
V_93 V_110 = V_46 -> V_47 . V_48 ;
V_46 -> V_183 = V_25 ;
F_94 ( & V_46 -> V_156 , F_17 ( V_25 , V_110 ) ) ;
}
static int F_235 ( struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_24 * V_25 ;
int V_273 ;
V_72 -> V_226 = F_236 ( struct V_215 ) ;
if ( ! V_72 -> V_226 )
return - V_155 ;
F_237 (i) {
struct V_215 * V_393 ;
V_393 = F_238 ( V_72 -> V_226 , V_273 ) ;
F_239 ( & V_393 -> V_227 ) ;
}
F_122 ( & V_32 -> V_185 ) ;
V_25 = F_26 ( F_44 ( V_72 ) , V_46 -> V_81 ) ;
if ( V_25 ) {
F_128 ( & V_25 -> V_184 ) ;
F_234 ( V_25 , V_46 ) ;
} else {
F_240 ( V_72 ) ;
F_132 ( V_186 , & V_46 -> V_394 ) ;
}
F_124 ( & V_32 -> V_185 ) ;
return 0 ;
}
static void F_241 ( struct V_45 * V_46 )
{
struct V_37 * V_100 ;
F_109 ( & V_46 -> V_170 ) ;
V_100 = F_60 ( V_46 , V_382 ) ;
if ( V_100 )
F_99 ( V_46 , V_100 ) ;
F_110 ( & V_46 -> V_170 ) ;
}
static void F_242 ( struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_183 ;
F_241 ( V_46 ) ;
if ( V_25 )
F_129 ( V_25 ) ;
F_243 ( V_72 -> V_226 ) ;
}
static int F_244 ( struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_183 ;
if ( ! V_25 )
return - V_395 ;
if ( F_6 ( & V_46 -> V_47 . V_66 ) ) {
F_127 ( V_25 ) ;
F_240 ( V_72 ) ;
F_132 ( V_186 , & V_46 -> V_190 ) ;
}
if ( V_46 -> V_390 )
F_233 ( & V_46 -> V_392 , V_54 + V_387 ) ;
return 0 ;
}
static void F_245 ( struct V_45 * V_46 )
{
unsigned int V_174 ;
F_109 ( & V_46 -> V_170 ) ;
for ( V_174 = 0 ; V_174 < V_175 ; ++ V_174 ) {
struct V_388 * V_112 , * V_238 ;
F_230 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_100
= F_96 ( V_112 , struct V_37 , V_156 ) ;
if ( ! F_34 ( V_100 -> V_67 ) )
F_99 ( V_46 , V_100 ) ;
}
}
F_110 ( & V_46 -> V_170 ) ;
}
static int F_246 ( struct V_99 * V_72 )
{
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_183 ;
if ( V_25 && F_6 ( & V_46 -> V_47 . V_66 ) &&
! F_125 ( V_32 , V_46 ) ) {
F_127 ( V_25 ) ;
F_240 ( V_72 ) ;
F_132 ( V_186 , & V_46 -> V_197 ) ;
}
F_247 ( & V_46 -> V_392 ) ;
F_245 ( V_46 ) ;
return 0 ;
}
static void F_248 ( struct V_99 * V_72 )
{
}
static int F_249 ( struct V_99 * V_72 , int V_396 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_313 = & V_46 -> V_47 ;
struct V_99 * V_397 ;
int V_398 ;
V_397 = F_106 ( F_44 ( V_72 ) , V_313 -> V_84 ) ;
if ( V_397 == NULL )
return F_250 ( V_72 , V_396 ) ;
if ( V_313 -> V_66 . V_4 . V_5 == V_6 )
V_398 = V_397 -> V_399 - V_400 ;
else
V_398 = V_397 -> V_399 - V_401 ;
if ( V_396 < 68 || V_396 > V_398 )
return - V_165 ;
V_72 -> V_399 = V_396 ;
return 0 ;
}
void F_251 ( struct V_99 * V_72 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_44 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_6 V_5 ;
T_2 V_30 ;
unsigned int V_273 ;
F_122 ( & V_32 -> V_185 ) ;
for ( V_273 = 0 ; V_273 < V_402 ; ++ V_273 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_42 -> V_43 ) -> V_44 ;
V_5 = V_25 -> V_42 -> V_43 -> V_138 ;
V_72 -> V_140 -> V_141 ( V_72 , V_5 ,
V_30 ) ;
}
}
F_124 ( & V_32 -> V_185 ) ;
}
static void F_252 ( struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_174 ;
int V_403 , V_404 ;
F_253 ( V_72 ) ;
F_254 ( V_72 ) ;
if ( V_46 -> V_47 . V_66 . V_4 . V_5 == V_6 )
V_72 -> V_405 = V_406 + V_400 ;
else
V_72 -> V_405 = V_406 + V_401 ;
V_72 -> V_140 = & V_407 ;
V_72 -> V_408 = V_409 ;
F_255 ( V_72 , & V_410 ) ;
V_72 -> V_411 = 0 ;
V_72 -> V_331 |= V_412 ;
V_72 -> V_331 |= V_413 ;
V_72 -> V_331 |= V_414 | V_415 ;
V_72 -> V_331 |= V_416 ;
V_72 -> V_331 |= V_417 ;
V_72 -> V_418 = V_72 -> V_331 ;
V_72 -> V_331 |= V_419 | V_420 ;
V_72 -> V_421 |= V_414 | V_415 | V_416 ;
V_72 -> V_421 |= V_417 ;
V_72 -> V_421 |= V_419 | V_420 ;
V_72 -> V_422 &= ~ V_423 ;
V_72 -> V_422 |= V_424 ;
F_52 ( & V_46 -> V_40 ) ;
F_256 ( & V_46 -> V_170 ) ;
F_257 ( & V_46 -> V_190 , F_133 ) ;
F_257 ( & V_46 -> V_197 , F_138 ) ;
F_257 ( & V_46 -> V_394 , V_425 ) ;
F_258 ( & V_46 -> V_392 ) ;
V_46 -> V_392 . V_426 = F_229 ;
V_46 -> V_392 . V_128 = ( unsigned long ) V_46 ;
F_259 ( F_44 ( V_72 ) , & V_403 , & V_404 ) ;
V_46 -> V_305 = V_403 ;
V_46 -> V_306 = V_404 ;
V_46 -> V_81 = F_144 ( V_427 ) ;
V_46 -> V_72 = V_72 ;
for ( V_174 = 0 ; V_174 < V_175 ; ++ V_174 )
F_260 ( & V_46 -> V_108 [ V_174 ] ) ;
}
static int F_261 ( struct V_14 * V_162 [] , struct V_14 * V_128 [] )
{
if ( V_162 [ V_428 ] ) {
if ( F_11 ( V_162 [ V_428 ] ) != V_78 ) {
F_262 ( L_15 ) ;
return - V_165 ;
}
if ( ! F_263 ( F_264 ( V_162 [ V_428 ] ) ) ) {
F_262 ( L_16 ) ;
return - V_167 ;
}
}
if ( ! V_128 )
return - V_165 ;
if ( V_128 [ V_429 ] ) {
V_93 V_26 = F_105 ( V_128 [ V_429 ] ) ;
if ( V_26 >= V_430 )
return - V_431 ;
}
if ( V_128 [ V_432 ] ) {
const struct V_433 * V_112
= F_264 ( V_128 [ V_432 ] ) ;
if ( F_21 ( V_112 -> V_404 ) < F_21 ( V_112 -> V_403 ) ) {
F_262 ( L_17 ,
F_21 ( V_112 -> V_403 ) , F_21 ( V_112 -> V_404 ) ) ;
return - V_165 ;
}
}
return 0 ;
}
static void F_265 ( struct V_99 * V_434 ,
struct V_435 * V_436 )
{
F_266 ( V_436 -> V_280 , V_437 , sizeof( V_436 -> V_280 ) ) ;
F_266 ( V_436 -> V_438 , L_18 , sizeof( V_436 -> V_438 ) ) ;
}
static void F_267 ( struct V_188 * V_189 )
{
struct V_24 * V_25 = F_96 ( V_189 , struct V_24 , V_187 ) ;
F_268 ( V_25 -> V_42 -> V_43 ) ;
F_114 ( V_25 , V_159 ) ;
}
static struct V_439 * F_269 ( struct V_29 * V_29 , T_2 V_30 )
{
struct V_42 * V_43 ;
struct V_439 * V_42 ;
struct V_440 V_1 = {
. V_441 = V_6 ,
. V_442 = V_30 ,
} ;
int V_147 , V_443 = 1 ;
V_147 = F_270 ( V_6 , V_444 , V_334 , & V_42 ) ;
if ( V_147 < 0 ) {
F_262 ( L_19 ) ;
return F_271 ( V_147 ) ;
}
V_43 = V_42 -> V_43 ;
F_272 ( V_43 , V_29 ) ;
F_273 ( V_42 , V_445 , V_446 ,
( char * ) & V_443 , sizeof( V_443 ) ) ;
V_147 = F_274 ( V_42 , (struct V_447 * ) & V_1 ,
sizeof( struct V_440 ) ) ;
if ( V_147 < 0 ) {
F_262 ( L_20 ,
& V_1 . V_8 , F_21 ( V_1 . V_442 ) , V_147 ) ;
F_268 ( V_43 ) ;
return F_271 ( V_147 ) ;
}
F_275 ( ! V_195 ) ;
F_28 ( V_43 ) -> V_448 = 0 ;
return V_42 ;
}
static struct V_439 * F_269 ( struct V_29 * V_29 , T_2 V_30 )
{
return F_271 ( - V_449 ) ;
}
static struct V_439 * F_276 ( struct V_29 * V_29 , T_2 V_30 )
{
struct V_42 * V_43 ;
struct V_439 * V_42 ;
struct V_450 V_1 = {
. V_451 = V_18 ,
. V_9 . V_10 = F_5 ( V_12 ) ,
. V_452 = V_30 ,
} ;
int V_147 ;
V_147 = F_270 ( V_18 , V_444 , V_334 , & V_42 ) ;
if ( V_147 < 0 ) {
F_262 ( L_21 ) ;
return F_271 ( V_147 ) ;
}
V_43 = V_42 -> V_43 ;
F_272 ( V_43 , V_29 ) ;
V_147 = F_274 ( V_42 , (struct V_447 * ) & V_1 ,
sizeof( V_1 ) ) ;
if ( V_147 < 0 ) {
F_262 ( L_22 ,
& V_1 . V_9 , F_21 ( V_1 . V_452 ) , V_147 ) ;
F_268 ( V_43 ) ;
return F_271 ( V_147 ) ;
}
F_28 ( V_43 ) -> V_448 = 0 ;
return V_42 ;
}
static struct V_24 * F_277 ( struct V_29 * V_29 , T_2 V_30 ,
T_12 * V_210 , void * V_128 , bool V_453 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_439 * V_42 ;
struct V_42 * V_43 ;
unsigned int V_174 ;
V_25 = F_278 ( sizeof( * V_25 ) , V_454 ) ;
if ( ! V_25 )
return F_271 ( - V_155 ) ;
for ( V_174 = 0 ; V_174 < V_455 ; ++ V_174 )
F_260 ( & V_25 -> V_27 [ V_174 ] ) ;
F_257 ( & V_25 -> V_187 , F_267 ) ;
if ( V_453 )
V_42 = F_269 ( V_29 , V_30 ) ;
else
V_42 = F_276 ( V_29 , V_30 ) ;
if ( F_219 ( V_42 ) ) {
F_98 ( V_25 ) ;
return F_279 ( V_42 ) ;
}
V_25 -> V_42 = V_42 ;
V_43 = V_42 -> V_43 ;
F_280 ( & V_25 -> V_184 , 1 ) ;
V_25 -> V_210 = V_210 ;
V_25 -> V_128 = V_128 ;
F_131 ( V_25 -> V_42 -> V_43 , V_25 ) ;
V_25 -> V_139 . V_30 = V_30 ;
V_25 -> V_139 . V_132 . V_133 = F_70 ;
V_25 -> V_139 . V_132 . V_137 = F_82 ;
F_122 ( & V_32 -> V_185 ) ;
F_94 ( & V_25 -> V_156 , F_19 ( V_29 , V_30 ) ) ;
F_84 ( V_25 ) ;
F_124 ( & V_32 -> V_185 ) ;
F_281 ( V_43 ) -> V_456 = 1 ;
F_281 ( V_43 ) -> V_457 = F_140 ;
#if F_103 ( V_163 )
if ( V_453 )
V_195 -> V_458 () ;
else
#endif
F_282 () ;
return V_25 ;
}
struct V_24 * F_283 ( struct V_29 * V_29 , T_2 V_30 ,
T_12 * V_210 , void * V_128 ,
bool V_459 , bool V_453 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
V_25 = F_277 ( V_29 , V_30 , V_210 , V_128 , V_453 ) ;
if ( ! F_219 ( V_25 ) )
return V_25 ;
if ( V_459 )
return V_25 ;
F_122 ( & V_32 -> V_185 ) ;
V_25 = F_26 ( V_29 , V_30 ) ;
if ( V_25 ) {
if ( V_25 -> V_210 == V_210 )
F_128 ( & V_25 -> V_184 ) ;
else
V_25 = F_271 ( - V_460 ) ;
}
F_124 ( & V_32 -> V_185 ) ;
if ( ! V_25 )
V_25 = F_271 ( - V_165 ) ;
return V_25 ;
}
static void V_425 ( struct V_188 * V_189 )
{
struct V_45 * V_46 = F_96 ( V_189 , struct V_45 , V_394 ) ;
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_46 -> V_81 ;
struct V_24 * V_461 ;
V_461 = F_283 ( V_29 , V_30 , F_146 , NULL , false , V_46 -> V_51 & V_462 ) ;
F_122 ( & V_32 -> V_185 ) ;
if ( ! F_219 ( V_461 ) )
F_234 ( V_461 , V_46 ) ;
F_124 ( & V_32 -> V_185 ) ;
F_137 ( V_46 -> V_72 ) ;
}
static int F_284 ( struct V_29 * V_29 , struct V_99 * V_72 ,
struct V_14 * V_162 [] , struct V_14 * V_128 [] )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_313 = & V_46 -> V_47 ;
V_93 V_110 ;
int V_94 ;
bool V_463 = false ;
if ( ! V_128 [ V_429 ] )
return - V_165 ;
V_110 = F_105 ( V_128 [ V_429 ] ) ;
V_313 -> V_48 = V_110 ;
if ( V_128 [ V_464 ] ) {
V_313 -> V_66 . sin . V_9 . V_10 = F_13 ( V_128 [ V_464 ] ) ;
V_313 -> V_66 . V_4 . V_5 = V_18 ;
} else if ( V_128 [ V_465 ] ) {
if ( ! F_103 ( V_163 ) )
return - V_449 ;
F_12 ( & V_313 -> V_66 . V_7 . V_8 , V_128 [ V_465 ] ,
sizeof( struct V_16 ) ) ;
V_313 -> V_66 . V_4 . V_5 = V_6 ;
V_463 = true ;
}
if ( V_128 [ V_466 ] ) {
V_46 -> V_217 . sin . V_9 . V_10 = F_13 ( V_128 [ V_466 ] ) ;
V_46 -> V_217 . V_4 . V_5 = V_18 ;
} else if ( V_128 [ V_467 ] ) {
if ( ! F_103 ( V_163 ) )
return - V_449 ;
F_12 ( & V_46 -> V_217 . V_7 . V_8 , V_128 [ V_467 ] ,
sizeof( struct V_16 ) ) ;
V_46 -> V_217 . V_4 . V_5 = V_6 ;
V_463 = true ;
}
if ( V_128 [ V_468 ] &&
( V_313 -> V_84 = F_105 ( V_128 [ V_468 ] ) ) ) {
struct V_99 * V_397
= F_106 ( V_29 , V_313 -> V_84 ) ;
if ( ! V_397 ) {
F_108 ( L_23 , V_313 -> V_84 ) ;
return - V_469 ;
}
#if F_103 ( V_163 )
if ( V_463 ) {
struct V_297 * V_470 = F_188 ( V_397 ) ;
if ( V_470 && V_470 -> V_471 . V_472 ) {
F_108 ( L_24 ) ;
return - V_473 ;
}
V_46 -> V_51 |= V_462 ;
}
#endif
if ( ! V_162 [ V_474 ] )
V_72 -> V_399 = V_397 -> V_399 - ( V_463 ? V_400 : V_401 ) ;
V_72 -> V_405 = V_397 -> V_405 +
( V_463 ? V_400 : V_401 ) ;
} else if ( V_463 )
V_46 -> V_51 |= V_462 ;
if ( V_128 [ V_475 ] )
V_46 -> V_223 = F_285 ( V_128 [ V_475 ] ) ;
if ( V_128 [ V_476 ] )
V_46 -> V_315 = F_285 ( V_128 [ V_476 ] ) ;
if ( ! V_128 [ V_477 ] || F_285 ( V_128 [ V_477 ] ) )
V_46 -> V_51 |= V_221 ;
if ( V_128 [ V_478 ] )
V_46 -> V_390 = F_105 ( V_128 [ V_478 ] ) ;
else
V_46 -> V_390 = V_479 ;
if ( V_128 [ V_480 ] && F_285 ( V_128 [ V_480 ] ) )
V_46 -> V_51 |= V_380 ;
if ( V_128 [ V_481 ] && F_285 ( V_128 [ V_481 ] ) )
V_46 -> V_51 |= V_381 ;
if ( V_128 [ V_482 ] && F_285 ( V_128 [ V_482 ] ) )
V_46 -> V_51 |= V_383 ;
if ( V_128 [ V_483 ] && F_285 ( V_128 [ V_483 ] ) )
V_46 -> V_51 |= V_262 ;
if ( V_128 [ V_484 ] )
V_46 -> V_152 = F_105 ( V_128 [ V_484 ] ) ;
if ( V_128 [ V_432 ] ) {
const struct V_433 * V_112
= F_264 ( V_128 [ V_432 ] ) ;
V_46 -> V_305 = F_21 ( V_112 -> V_403 ) ;
V_46 -> V_306 = F_21 ( V_112 -> V_404 ) ;
}
if ( V_128 [ V_485 ] )
V_46 -> V_81 = F_104 ( V_128 [ V_485 ] ) ;
if ( F_30 ( V_29 , V_110 , V_46 -> V_81 ) ) {
F_108 ( L_25 , V_110 ) ;
return - V_145 ;
}
F_286 ( V_72 , & V_486 ) ;
if ( ! F_3 ( & V_46 -> V_47 . V_66 ) ) {
V_94 = F_91 ( V_46 , V_382 ,
& V_46 -> V_47 . V_66 ,
V_169 | V_168 ,
V_144 | V_150 ,
V_46 -> V_81 ,
V_46 -> V_47 . V_48 ,
V_46 -> V_47 . V_84 ,
V_182 ) ;
if ( V_94 )
return V_94 ;
}
V_94 = F_287 ( V_72 ) ;
if ( V_94 ) {
F_241 ( V_46 ) ;
return V_94 ;
}
F_288 ( & V_46 -> V_40 , & V_32 -> V_487 ) ;
return 0 ;
}
static void F_289 ( struct V_99 * V_72 , struct V_488 * V_109 )
{
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
F_122 ( & V_32 -> V_185 ) ;
if ( ! F_290 ( & V_46 -> V_156 ) )
F_100 ( & V_46 -> V_156 ) ;
F_124 ( & V_32 -> V_185 ) ;
F_291 ( & V_46 -> V_40 ) ;
F_292 ( V_72 , V_109 ) ;
}
static T_3 F_293 ( const struct V_99 * V_72 )
{
return F_42 ( sizeof( V_93 ) ) +
F_42 ( sizeof( struct V_16 ) ) +
F_42 ( sizeof( V_93 ) ) +
F_42 ( sizeof( struct V_16 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( V_93 ) ) +
F_42 ( sizeof( V_93 ) ) +
F_42 ( sizeof( struct V_433 ) ) +
F_42 ( sizeof( T_2 ) ) +
0 ;
}
static int F_294 ( struct V_20 * V_21 , const struct V_99 * V_72 )
{
const struct V_45 * V_46 = F_51 ( V_72 ) ;
const struct V_36 * V_313 = & V_46 -> V_47 ;
struct V_433 V_489 = {
. V_403 = F_144 ( V_46 -> V_305 ) ,
. V_404 = F_144 ( V_46 -> V_306 ) ,
} ;
if ( F_36 ( V_21 , V_429 , V_313 -> V_48 ) )
goto V_79;
if ( ! F_3 ( & V_313 -> V_66 ) ) {
if ( V_313 -> V_66 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_464 ,
V_313 -> V_66 . sin . V_9 . V_10 ) )
goto V_79;
#if F_103 ( V_163 )
} else {
if ( F_15 ( V_21 , V_465 , sizeof( struct V_16 ) ,
& V_313 -> V_66 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( V_313 -> V_84 && F_36 ( V_21 , V_468 , V_313 -> V_84 ) )
goto V_79;
if ( ! F_3 ( & V_46 -> V_217 ) ) {
if ( V_46 -> V_217 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_466 ,
V_46 -> V_217 . sin . V_9 . V_10 ) )
goto V_79;
#if F_103 ( V_163 )
} else {
if ( F_15 ( V_21 , V_467 , sizeof( struct V_16 ) ,
& V_46 -> V_217 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( F_295 ( V_21 , V_476 , V_46 -> V_315 ) ||
F_295 ( V_21 , V_475 , V_46 -> V_223 ) ||
F_295 ( V_21 , V_477 ,
! ! ( V_46 -> V_51 & V_221 ) ) ||
F_295 ( V_21 , V_480 ,
! ! ( V_46 -> V_51 & V_380 ) ) ||
F_295 ( V_21 , V_481 , ! ! ( V_46 -> V_51 & V_381 ) ) ||
F_295 ( V_21 , V_482 ,
! ! ( V_46 -> V_51 & V_383 ) ) ||
F_295 ( V_21 , V_483 ,
! ! ( V_46 -> V_51 & V_262 ) ) ||
F_36 ( V_21 , V_478 , V_46 -> V_390 ) ||
F_36 ( V_21 , V_484 , V_46 -> V_152 ) ||
F_35 ( V_21 , V_485 , V_46 -> V_81 ) )
goto V_79;
if ( F_15 ( V_21 , V_432 , sizeof( V_489 ) , & V_489 ) )
goto V_79;
return 0 ;
V_79:
return - V_63 ;
}
static void F_296 ( struct V_31 * V_32 ,
struct V_99 * V_72 )
{
struct V_45 * V_46 , * V_40 ;
F_297 ( V_490 ) ;
F_97 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_313 = & V_46 -> V_47 ;
if ( V_313 -> V_84 == V_72 -> V_73 )
F_289 ( V_46 -> V_72 , & V_490 ) ;
}
F_298 ( & V_490 ) ;
}
static int F_299 ( struct V_491 * V_492 ,
unsigned long V_493 , void * V_494 )
{
struct V_99 * V_72 = F_300 ( V_494 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
if ( V_493 == V_495 )
F_296 ( V_32 , V_72 ) ;
return V_496 ;
}
static T_13 int F_301 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_174 ;
F_52 ( & V_32 -> V_487 ) ;
F_256 ( & V_32 -> V_185 ) ;
for ( V_174 = 0 ; V_174 < V_402 ; ++ V_174 )
F_260 ( & V_32 -> V_34 [ V_174 ] ) ;
return 0 ;
}
static int T_14 F_302 ( void )
{
int V_147 ;
V_186 = F_303 ( L_18 , 0 , 0 ) ;
if ( ! V_186 )
return - V_155 ;
F_304 ( & V_497 , sizeof( V_497 ) ) ;
V_147 = F_305 ( & V_498 ) ;
if ( V_147 )
goto V_499;
V_147 = F_306 ( & V_500 ) ;
if ( V_147 )
goto V_501;
V_147 = F_307 ( & V_502 ) ;
if ( V_147 )
goto V_503;
return 0 ;
V_503:
F_308 ( & V_500 ) ;
V_501:
F_309 ( & V_498 ) ;
V_499:
F_310 ( V_186 ) ;
return V_147 ;
}
static void T_15 F_311 ( void )
{
F_312 ( & V_502 ) ;
F_308 ( & V_500 ) ;
F_310 ( V_186 ) ;
F_309 ( & V_498 ) ;
}
