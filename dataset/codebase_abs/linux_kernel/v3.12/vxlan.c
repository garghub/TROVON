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
static void F_70 ( struct V_42 * V_43 )
{
struct V_99 * V_72 ;
struct V_29 * V_29 = F_71 ( V_43 ) ;
T_6 V_5 = V_43 -> V_112 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
F_72 () ;
F_73 (net, dev) {
if ( V_72 -> V_113 -> V_114 )
V_72 -> V_113 -> V_114 ( V_72 , V_5 ,
V_30 ) ;
}
F_74 () ;
}
static void F_75 ( struct V_42 * V_43 )
{
struct V_99 * V_72 ;
struct V_29 * V_29 = F_71 ( V_43 ) ;
T_6 V_5 = V_43 -> V_112 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
F_72 () ;
F_73 (net, dev) {
if ( V_72 -> V_113 -> V_115 )
V_72 -> V_113 -> V_115 ( V_72 , V_5 ,
V_30 ) ;
}
F_74 () ;
}
static int F_76 ( struct V_45 * V_46 ,
const T_4 * V_107 , union V_1 * V_13 ,
T_7 V_70 , T_7 V_51 ,
T_2 V_30 , V_93 V_110 , V_93 V_73 ,
T_8 V_74 )
{
struct V_37 * V_100 ;
int V_116 = 0 ;
V_100 = F_60 ( V_46 , V_107 ) ;
if ( V_100 ) {
if ( V_51 & V_117 ) {
F_77 ( V_46 -> V_72 ,
L_1 , V_107 ) ;
return - V_118 ;
}
if ( V_100 -> V_70 != V_70 ) {
V_100 -> V_70 = V_70 ;
V_100 -> V_90 = V_54 ;
V_116 = 1 ;
}
if ( V_100 -> V_51 != V_74 ) {
V_100 -> V_51 = V_74 ;
V_100 -> V_90 = V_54 ;
V_116 = 1 ;
}
if ( ( V_51 & V_119 ) ) {
if ( ! ( F_78 ( V_100 -> V_67 ) ||
F_34 ( V_100 -> V_67 ) ) ) {
int V_120 = F_65 ( V_100 , V_13 , V_30 , V_110 ,
V_73 ) ;
if ( V_120 < 0 )
return V_120 ;
V_116 |= V_120 ;
} else
return - V_121 ;
}
if ( ( V_51 & V_122 ) &&
( F_78 ( V_100 -> V_67 ) ||
F_34 ( V_100 -> V_67 ) ) ) {
int V_120 = F_67 ( V_100 , V_13 , V_30 , V_110 , V_73 ) ;
if ( V_120 < 0 )
return V_120 ;
V_116 |= V_120 ;
}
} else {
if ( ! ( V_51 & V_123 ) )
return - V_124 ;
if ( V_46 -> V_125 && V_46 -> V_126 >= V_46 -> V_125 )
return - V_127 ;
if ( ( V_51 & V_119 ) &&
( F_78 ( V_107 ) || F_34 ( V_107 ) ) )
return - V_121 ;
F_77 ( V_46 -> V_72 , L_2 , V_107 , V_13 ) ;
V_100 = F_68 ( sizeof( * V_100 ) , V_96 ) ;
if ( ! V_100 )
return - V_128 ;
V_116 = 1 ;
V_100 -> V_70 = V_70 ;
V_100 -> V_51 = V_74 ;
V_100 -> V_90 = V_100 -> V_87 = V_54 ;
F_52 ( & V_100 -> V_39 ) ;
memcpy ( V_100 -> V_67 , V_107 , V_78 ) ;
F_67 ( V_100 , V_13 , V_30 , V_110 , V_73 ) ;
++ V_46 -> V_126 ;
F_79 ( & V_100 -> V_129 ,
F_59 ( V_46 , V_107 ) ) ;
}
if ( V_116 )
F_43 ( V_46 , V_100 , V_130 ) ;
return 0 ;
}
static void F_80 ( struct V_131 * V_109 )
{
struct V_37 * V_100 = F_81 ( V_109 , struct V_37 , V_132 ) ;
struct V_36 * V_111 , * V_133 ;
F_82 (rd, nd, &f->remotes, list)
F_83 ( V_111 ) ;
F_83 ( V_100 ) ;
}
static void F_84 ( struct V_45 * V_46 , struct V_37 * V_100 )
{
F_77 ( V_46 -> V_72 ,
L_3 , V_100 -> V_67 ) ;
-- V_46 -> V_126 ;
F_43 ( V_46 , V_100 , V_134 ) ;
F_85 ( & V_100 -> V_129 ) ;
F_86 ( & V_100 -> V_132 , F_80 ) ;
}
static int F_87 ( struct V_14 * V_135 [] , struct V_45 * V_46 ,
union V_1 * V_13 , T_2 * V_30 , T_1 * V_110 , T_1 * V_73 )
{
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
int V_94 ;
if ( V_135 [ V_76 ] ) {
V_94 = F_10 ( V_13 , V_135 [ V_76 ] ) ;
if ( V_94 )
return V_94 ;
} else {
union V_1 * V_102 = & V_46 -> V_47 . V_66 ;
if ( V_102 -> V_4 . V_5 == V_18 ) {
V_13 -> sin . V_9 . V_10 = F_5 ( V_12 ) ;
V_13 -> V_4 . V_5 = V_18 ;
#if F_88 ( V_136 )
} else {
V_13 -> V_7 . V_8 = V_137 ;
V_13 -> V_4 . V_5 = V_6 ;
#endif
}
}
if ( V_135 [ V_82 ] ) {
if ( F_11 ( V_135 [ V_82 ] ) != sizeof( T_2 ) )
return - V_138 ;
* V_30 = F_89 ( V_135 [ V_82 ] ) ;
} else {
* V_30 = V_46 -> V_81 ;
}
if ( V_135 [ V_83 ] ) {
if ( F_11 ( V_135 [ V_83 ] ) != sizeof( T_1 ) )
return - V_138 ;
* V_110 = F_90 ( V_135 [ V_83 ] ) ;
} else {
* V_110 = V_46 -> V_47 . V_48 ;
}
if ( V_135 [ V_85 ] ) {
struct V_99 * V_139 ;
if ( F_11 ( V_135 [ V_85 ] ) != sizeof( T_1 ) )
return - V_138 ;
* V_73 = F_90 ( V_135 [ V_85 ] ) ;
V_139 = F_91 ( V_29 , * V_73 ) ;
if ( ! V_139 )
return - V_140 ;
F_92 ( V_139 ) ;
} else {
* V_73 = 0 ;
}
return 0 ;
}
static int F_93 ( struct V_59 * V_60 , struct V_14 * V_135 [] ,
struct V_99 * V_72 ,
const unsigned char * V_104 , T_9 V_51 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_110 , V_73 ;
int V_94 ;
if ( ! ( V_60 -> V_69 & ( V_141 | V_142 ) ) ) {
F_94 ( L_4 ,
V_60 -> V_69 ) ;
return - V_138 ;
}
if ( V_135 [ V_76 ] == NULL )
return - V_138 ;
V_94 = F_87 ( V_135 , V_46 , & V_13 , & V_30 , & V_110 , & V_73 ) ;
if ( V_94 )
return V_94 ;
F_95 ( & V_46 -> V_143 ) ;
V_94 = F_76 ( V_46 , V_104 , & V_13 , V_60 -> V_69 , V_51 ,
V_30 , V_110 , V_73 , V_60 -> V_74 ) ;
F_96 ( & V_46 -> V_143 ) ;
return V_94 ;
}
static int F_97 ( struct V_59 * V_60 , struct V_14 * V_135 [] ,
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
V_94 = F_87 ( V_135 , V_46 , & V_13 , & V_30 , & V_110 , & V_73 ) ;
if ( V_94 )
return V_94 ;
V_94 = - V_124 ;
F_95 ( & V_46 -> V_143 ) ;
V_100 = F_62 ( V_46 , V_104 ) ;
if ( ! V_100 )
goto V_144;
if ( ! F_3 ( & V_13 ) ) {
V_111 = F_63 ( V_100 , & V_13 , V_30 , V_110 , V_73 ) ;
if ( ! V_111 )
goto V_144;
}
V_94 = 0 ;
if ( V_111 && ! F_98 ( & V_100 -> V_39 ) ) {
F_99 ( & V_111 -> V_41 ) ;
F_100 ( V_111 , V_132 ) ;
goto V_144;
}
F_84 ( V_46 , V_100 ) ;
V_144:
F_96 ( & V_46 -> V_143 ) ;
return V_94 ;
}
static int F_101 ( struct V_20 * V_21 , struct V_145 * V_146 ,
struct V_99 * V_72 , int V_147 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_148 ;
for ( V_148 = 0 ; V_148 < V_149 ; ++ V_148 ) {
struct V_37 * V_100 ;
int V_94 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_111 ;
if ( V_147 < V_146 -> args [ 0 ] )
goto V_150;
F_102 (rd, &f->remotes, list) {
V_94 = F_31 ( V_21 , V_46 , V_100 ,
F_103 ( V_146 -> V_21 ) . V_49 ,
V_146 -> V_58 -> V_151 ,
V_130 ,
V_152 , V_111 ) ;
if ( V_94 < 0 )
goto V_144;
}
V_150:
++ V_147 ;
}
}
V_144:
return V_147 ;
}
static bool F_104 ( struct V_99 * V_72 ,
union V_1 * V_153 , const T_4 * V_154 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_100 ;
V_100 = F_62 ( V_46 , V_154 ) ;
if ( F_105 ( V_100 ) ) {
struct V_36 * V_52 = F_22 ( V_100 ) ;
if ( F_105 ( F_1 ( & V_52 -> V_66 , V_153 ) ) )
return false ;
if ( V_100 -> V_70 & V_155 )
return true ;
if ( F_106 () )
F_107 ( V_72 ,
L_5 ,
V_154 , & V_52 -> V_66 , & V_153 ) ;
V_52 -> V_66 = * V_153 ;
V_100 -> V_90 = V_54 ;
F_43 ( V_46 , V_100 , V_130 ) ;
} else {
F_108 ( & V_46 -> V_143 ) ;
if ( F_109 ( V_72 ) )
F_76 ( V_46 , V_154 , V_153 ,
V_142 ,
V_117 | V_123 ,
V_46 -> V_81 ,
V_46 -> V_47 . V_48 ,
0 , V_156 ) ;
F_110 ( & V_46 -> V_143 ) ;
}
return false ;
}
static bool F_111 ( struct V_31 * V_32 , union V_1 * V_66 )
{
struct V_45 * V_46 ;
F_64 (vxlan, &vn->vxlan_list, next) {
if ( ! F_109 ( V_46 -> V_72 ) )
continue;
if ( F_1 ( & V_46 -> V_47 . V_66 ,
V_66 ) )
return true ;
}
return false ;
}
static void F_112 ( struct V_24 * V_25 )
{
F_113 ( & V_25 -> V_157 ) ;
}
void F_114 ( struct V_24 * V_25 )
{
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_71 ( V_43 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_115 ( & V_25 -> V_157 ) )
return;
F_108 ( & V_32 -> V_158 ) ;
F_85 ( & V_25 -> V_129 ) ;
F_116 ( V_25 -> V_42 -> V_43 , NULL ) ;
F_75 ( V_43 ) ;
F_110 ( & V_32 -> V_158 ) ;
F_117 ( V_159 , & V_25 -> V_160 ) ;
}
static void F_118 ( struct V_161 * V_162 )
{
struct V_45 * V_46 = F_81 ( V_162 , struct V_45 , V_163 ) ;
struct V_24 * V_25 = V_46 -> V_164 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_84 ;
F_119 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_165 V_166 = {
. V_167 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_168 = V_73 ,
} ;
F_120 ( V_43 , & V_166 ) ;
#if F_88 ( V_136 )
} else {
V_169 -> V_170 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_121 ( V_43 ) ;
F_114 ( V_25 ) ;
F_92 ( V_46 -> V_72 ) ;
}
static void F_122 ( struct V_161 * V_162 )
{
struct V_45 * V_46 = F_81 ( V_162 , struct V_45 , V_171 ) ;
struct V_24 * V_25 = V_46 -> V_164 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_84 ;
F_119 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_165 V_166 = {
. V_167 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_168 = V_73 ,
} ;
F_123 ( V_43 , & V_166 ) ;
#if F_88 ( V_136 )
} else {
V_169 -> V_172 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_121 ( V_43 ) ;
F_114 ( V_25 ) ;
F_92 ( V_46 -> V_72 ) ;
}
static int F_124 ( struct V_42 * V_43 , struct V_20 * V_21 )
{
struct V_24 * V_25 ;
struct V_173 * V_174 ;
T_2 V_30 ;
if ( ! F_125 ( V_21 , V_175 ) )
goto error;
V_174 = (struct V_173 * ) ( F_126 ( V_21 ) + 1 ) ;
if ( V_174 -> V_176 != F_5 ( V_177 ) ||
( V_174 -> V_178 & F_5 ( 0xff ) ) ) {
F_77 ( V_21 -> V_72 , L_6 ,
F_9 ( V_174 -> V_176 ) , F_9 ( V_174 -> V_178 ) ) ;
goto error;
}
if ( F_127 ( V_21 , V_175 , F_128 ( V_179 ) ) )
goto V_180;
V_30 = F_28 ( V_43 ) -> V_44 ;
V_25 = F_129 ( V_43 ) ;
if ( ! V_25 )
goto V_180;
V_25 -> V_181 ( V_25 , V_21 , V_174 -> V_178 ) ;
return 0 ;
V_180:
F_47 ( V_21 ) ;
return 0 ;
error:
return 1 ;
}
static void F_130 ( struct V_24 * V_25 ,
struct V_20 * V_21 , V_17 V_178 )
{
struct V_182 * V_183 = NULL ;
struct V_184 * V_185 = NULL ;
struct V_45 * V_46 ;
struct V_186 * V_187 ;
union V_1 V_188 ;
V_93 V_110 ;
int V_94 = 0 ;
union V_1 * V_66 ;
V_110 = F_9 ( V_178 ) >> 8 ;
V_46 = F_29 ( V_25 , V_110 ) ;
if ( ! V_46 )
goto V_180;
V_66 = & V_46 -> V_47 . V_66 ;
F_131 ( V_21 ) ;
V_21 -> V_189 = F_132 ( V_21 , V_46 -> V_72 ) ;
if ( F_61 ( F_133 ( V_21 ) -> V_190 , V_46 -> V_72 -> V_191 ) )
goto V_180;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_183 = F_134 ( V_21 ) ;
V_188 . sin . V_9 . V_10 = V_183 -> V_188 ;
V_188 . V_4 . V_5 = V_18 ;
#if F_88 ( V_136 )
} else {
V_185 = F_135 ( V_21 ) ;
V_188 . V_7 . V_8 = V_185 -> V_188 ;
V_188 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_46 -> V_51 & V_192 ) &&
F_104 ( V_21 -> V_72 , & V_188 , F_133 ( V_21 ) -> V_190 ) )
goto V_180;
F_136 ( V_21 ) ;
if ( V_21 -> V_193 != V_194 || ! V_21 -> V_195 ||
! ( V_46 -> V_72 -> V_196 & V_197 ) )
V_21 -> V_193 = V_198 ;
V_21 -> V_195 = 0 ;
if ( V_185 )
V_94 = F_137 ( V_185 , V_21 ) ;
if ( V_183 )
V_94 = F_138 ( V_183 , V_21 ) ;
if ( F_139 ( V_94 ) ) {
if ( V_199 ) {
if ( V_185 )
F_140 ( L_7 ,
& V_185 -> V_188 ) ;
if ( V_183 )
F_140 ( L_8 ,
& V_183 -> V_188 , V_183 -> V_200 ) ;
}
if ( V_94 > 1 ) {
++ V_46 -> V_72 -> V_187 . V_201 ;
++ V_46 -> V_72 -> V_187 . V_202 ;
goto V_180;
}
}
V_187 = F_141 ( V_46 -> V_72 -> V_203 ) ;
F_142 ( & V_187 -> V_204 ) ;
V_187 -> V_205 ++ ;
V_187 -> V_206 += V_21 -> V_207 ;
F_143 ( & V_187 -> V_204 ) ;
F_144 ( V_21 ) ;
return;
V_180:
F_47 ( V_21 ) ;
}
static int F_145 ( struct V_99 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_208 * V_209 ;
T_4 * V_210 , * V_211 ;
V_17 V_212 , V_213 ;
struct V_214 * V_215 ;
if ( V_72 -> V_51 & V_216 )
goto V_144;
if ( ! F_125 ( V_21 , F_146 ( V_72 ) ) ) {
V_72 -> V_187 . V_217 ++ ;
goto V_144;
}
V_209 = F_147 ( V_21 ) ;
if ( ( V_209 -> V_218 != F_128 ( V_219 ) &&
V_209 -> V_218 != F_128 ( V_220 ) ) ||
V_209 -> V_221 != F_128 ( V_222 ) ||
V_209 -> V_223 != F_128 ( V_224 ) ||
V_209 -> V_225 != V_72 -> V_226 ||
V_209 -> V_227 != 4 )
goto V_144;
V_210 = ( T_4 * ) V_209 + sizeof( struct V_208 ) ;
V_211 = V_210 ;
V_210 += V_72 -> V_226 ;
memcpy ( & V_212 , V_210 , sizeof( V_212 ) ) ;
V_210 += sizeof( V_212 ) ;
V_210 += V_72 -> V_226 ;
memcpy ( & V_213 , V_210 , sizeof( V_213 ) ) ;
if ( F_148 ( V_213 ) ||
F_149 ( V_213 ) )
goto V_144;
V_215 = F_150 ( & V_228 , & V_213 , V_72 ) ;
if ( V_215 ) {
struct V_37 * V_100 ;
struct V_20 * V_229 ;
if ( ! ( V_215 -> V_230 & V_231 ) ) {
F_151 ( V_215 ) ;
goto V_144;
}
V_100 = F_62 ( V_46 , V_215 -> V_232 ) ;
if ( V_100 && F_3 ( & ( F_22 ( V_100 ) -> V_66 ) ) ) {
F_151 ( V_215 ) ;
goto V_144;
}
V_229 = F_152 ( V_233 , V_234 , V_212 , V_72 , V_213 , V_211 ,
V_215 -> V_232 , V_211 ) ;
F_151 ( V_215 ) ;
F_131 ( V_229 ) ;
F_153 ( V_229 , F_154 ( V_229 ) ) ;
V_229 -> V_193 = V_194 ;
V_229 -> V_235 = V_236 ;
if ( F_155 ( V_229 ) == V_237 )
V_72 -> V_187 . V_238 ++ ;
} else if ( V_46 -> V_51 & V_239 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_213 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_144:
F_156 ( V_21 ) ;
return V_240 ;
}
static int F_157 ( struct V_99 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_214 * V_215 ;
union V_1 V_11 ;
const struct V_184 * V_182 ;
const struct V_16 * V_188 , * V_241 ;
struct V_242 * V_243 ;
struct V_244 * V_245 = NULL ;
V_245 = F_158 ( V_72 ) ;
if ( ! V_245 )
goto V_144;
if ( ! F_125 ( V_21 , V_21 -> V_207 ) )
goto V_144;
V_182 = F_135 ( V_21 ) ;
V_188 = & V_182 -> V_188 ;
V_241 = & V_182 -> V_241 ;
if ( F_159 ( V_241 ) ||
F_7 ( V_241 ) )
goto V_144;
V_243 = (struct V_242 * ) F_160 ( V_21 ) ;
if ( V_243 -> V_246 . V_247 != 0 ||
V_243 -> V_246 . V_248 != V_249 )
goto V_144;
V_215 = F_150 ( V_169 -> V_250 , V_241 , V_72 ) ;
if ( V_215 ) {
struct V_37 * V_100 ;
if ( ! ( V_215 -> V_230 & V_231 ) ) {
F_151 ( V_215 ) ;
goto V_144;
}
V_100 = F_62 ( V_46 , V_215 -> V_232 ) ;
if ( V_100 && F_3 ( & ( F_22 ( V_100 ) -> V_66 ) ) ) {
F_151 ( V_215 ) ;
goto V_144;
}
V_169 -> V_251 ( V_72 , V_215 , V_188 , & V_243 -> V_252 ,
! ! V_245 -> V_253 . V_254 ,
true , false , false ) ;
F_151 ( V_215 ) ;
} else if ( V_46 -> V_51 & V_239 ) {
V_11 . V_7 . V_8 = * V_241 ;
V_11 . V_4 . V_5 = V_6 ;
F_50 ( V_72 , & V_11 ) ;
}
V_144:
F_156 ( V_21 ) ;
return V_240 ;
}
static bool F_161 ( struct V_99 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_214 * V_215 ;
if ( F_78 ( F_133 ( V_21 ) -> V_255 ) )
return false ;
V_215 = NULL ;
switch ( F_21 ( F_133 ( V_21 ) -> V_256 ) ) {
case V_222 :
{
struct V_182 * V_257 ;
if ( ! F_125 ( V_21 , sizeof( struct V_182 ) ) )
return false ;
V_257 = F_134 ( V_21 ) ;
V_215 = F_150 ( & V_228 , & V_257 -> V_241 , V_72 ) ;
if ( ! V_215 && ( V_46 -> V_51 & V_239 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_257 -> V_241 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
return false ;
}
break;
}
#if F_88 ( V_136 )
case V_258 :
{
struct V_184 * V_259 ;
if ( ! F_125 ( V_21 , sizeof( struct V_184 ) ) )
return false ;
V_259 = F_135 ( V_21 ) ;
V_215 = F_150 ( V_169 -> V_250 , & V_259 -> V_241 , V_72 ) ;
if ( ! V_215 && ( V_46 -> V_51 & V_239 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_259 -> V_241 ,
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
if ( V_215 ) {
bool V_260 ;
V_260 = ! F_61 ( F_133 ( V_21 ) -> V_255 , V_215 -> V_232 ) ;
if ( V_260 ) {
memcpy ( F_133 ( V_21 ) -> V_190 , F_133 ( V_21 ) -> V_255 ,
V_72 -> V_226 ) ;
memcpy ( F_133 ( V_21 ) -> V_255 , V_215 -> V_232 , V_72 -> V_226 ) ;
}
F_151 ( V_215 ) ;
return V_260 ;
}
return false ;
}
static void F_162 ( struct V_20 * V_21 )
{
F_163 ( V_21 -> V_43 ) ;
}
static void F_164 ( struct V_42 * V_43 , struct V_20 * V_21 )
{
F_165 ( V_21 ) ;
F_166 ( V_43 ) ;
V_21 -> V_43 = V_43 ;
V_21 -> V_261 = F_162 ;
}
T_2 F_167 ( T_7 V_262 , T_7 V_263 , struct V_20 * V_21 )
{
unsigned int V_264 = ( V_263 - V_262 ) + 1 ;
T_1 V_265 ;
V_265 = F_168 ( V_21 ) ;
if ( ! V_265 )
V_265 = F_169 ( V_21 -> V_266 , 2 * V_78 ,
( V_267 T_1 ) V_21 -> V_189 ) ;
return F_128 ( ( ( ( T_5 ) V_265 * V_264 ) >> 32 ) + V_262 ) ;
}
static int F_170 ( struct V_20 * V_21 )
{
if ( F_171 ( V_21 ) ) {
int V_94 = F_172 ( V_21 , V_96 ) ;
if ( F_139 ( V_94 ) )
return V_94 ;
F_173 ( V_21 ) -> V_268 |= V_269 ;
} else if ( V_21 -> V_193 != V_270 )
V_21 -> V_193 = V_198 ;
return 0 ;
}
static int F_174 ( struct V_24 * V_25 ,
struct V_271 * V_272 , struct V_20 * V_21 ,
struct V_99 * V_72 , struct V_16 * V_188 ,
struct V_16 * V_241 , T_8 V_273 , T_8 V_274 ,
T_2 V_275 , T_2 V_81 , V_17 V_110 )
{
struct V_184 * V_276 ;
struct V_173 * V_174 ;
struct V_277 * V_278 ;
int V_279 ;
int V_94 ;
if ( ! V_21 -> V_195 ) {
F_175 ( V_21 ) ;
V_21 -> V_195 = 1 ;
}
F_176 ( V_21 , false ) ;
V_279 = F_177 ( V_272 -> V_72 ) + V_272 -> V_280
+ V_175 + sizeof( struct V_184 )
+ ( F_178 ( V_21 ) ? V_281 : 0 ) ;
V_94 = F_179 ( V_21 , V_279 ) ;
if ( F_139 ( V_94 ) )
return V_94 ;
if ( F_178 ( V_21 ) ) {
if ( F_46 ( ! F_180 ( V_21 ,
V_21 -> V_282 ,
F_181 ( V_21 ) ) ) )
return - V_128 ;
V_21 -> V_283 = 0 ;
}
V_174 = (struct V_173 * ) F_182 ( V_21 , sizeof( * V_174 ) ) ;
V_174 -> V_176 = F_5 ( V_177 ) ;
V_174 -> V_178 = V_110 ;
F_182 ( V_21 , sizeof( * V_278 ) ) ;
F_183 ( V_21 ) ;
V_278 = F_126 ( V_21 ) ;
V_278 -> V_284 = V_81 ;
V_278 -> V_285 = V_275 ;
V_278 -> V_207 = F_128 ( V_21 -> V_207 ) ;
V_278 -> V_286 = 0 ;
memset ( & ( F_184 ( V_21 ) -> V_287 ) , 0 , sizeof( F_184 ( V_21 ) -> V_287 ) ) ;
F_184 ( V_21 ) -> V_51 &= ~ ( V_288 | V_289 |
V_290 ) ;
F_185 ( V_21 , V_272 ) ;
if ( ! F_171 ( V_21 ) && ! ( V_272 -> V_72 -> V_196 & V_291 ) ) {
T_10 V_292 = F_186 ( V_21 , 0 , V_21 -> V_207 , 0 ) ;
V_21 -> V_193 = V_194 ;
V_278 -> V_286 = F_187 ( V_188 , V_241 , V_21 -> V_207 ,
V_293 , V_292 ) ;
if ( V_278 -> V_286 == 0 )
V_278 -> V_286 = V_294 ;
} else {
V_21 -> V_193 = V_270 ;
V_21 -> V_295 = F_160 ( V_21 ) - V_21 -> V_109 ;
V_21 -> V_296 = F_188 ( struct V_277 , V_286 ) ;
V_278 -> V_286 = ~ F_187 ( V_188 , V_241 ,
V_21 -> V_207 , V_293 , 0 ) ;
}
F_182 ( V_21 , sizeof( * V_276 ) ) ;
F_136 ( V_21 ) ;
V_276 = F_135 ( V_21 ) ;
V_276 -> V_297 = 6 ;
V_276 -> V_298 = V_273 ;
V_276 -> V_299 [ 0 ] = 0 ;
V_276 -> V_299 [ 1 ] = 0 ;
V_276 -> V_299 [ 2 ] = 0 ;
V_276 -> V_300 = F_128 ( V_21 -> V_207 ) ;
V_276 -> V_301 = V_293 ;
V_276 -> V_302 = V_274 ;
V_276 -> V_241 = * V_241 ;
V_276 -> V_188 = * V_188 ;
F_164 ( V_25 -> V_42 -> V_43 , V_21 ) ;
V_94 = F_170 ( V_21 ) ;
if ( V_94 )
return V_94 ;
F_189 ( V_21 , V_72 ) ;
return 0 ;
}
int F_190 ( struct V_24 * V_25 ,
struct V_303 * V_304 , struct V_20 * V_21 ,
V_17 V_305 , V_17 V_272 , T_8 V_200 , T_8 V_274 , T_2 V_306 ,
T_2 V_275 , T_2 V_81 , V_17 V_110 )
{
struct V_173 * V_174 ;
struct V_277 * V_278 ;
int V_279 ;
int V_94 ;
if ( ! V_21 -> V_195 ) {
F_175 ( V_21 ) ;
V_21 -> V_195 = 1 ;
}
V_279 = F_177 ( V_304 -> V_272 . V_72 ) + V_304 -> V_272 . V_280
+ V_175 + sizeof( struct V_182 )
+ ( F_178 ( V_21 ) ? V_281 : 0 ) ;
V_94 = F_179 ( V_21 , V_279 ) ;
if ( F_139 ( V_94 ) )
return V_94 ;
if ( F_178 ( V_21 ) ) {
if ( F_46 ( ! F_180 ( V_21 ,
V_21 -> V_282 ,
F_181 ( V_21 ) ) ) )
return - V_128 ;
V_21 -> V_283 = 0 ;
}
V_174 = (struct V_173 * ) F_182 ( V_21 , sizeof( * V_174 ) ) ;
V_174 -> V_176 = F_5 ( V_177 ) ;
V_174 -> V_178 = V_110 ;
F_182 ( V_21 , sizeof( * V_278 ) ) ;
F_183 ( V_21 ) ;
V_278 = F_126 ( V_21 ) ;
V_278 -> V_284 = V_81 ;
V_278 -> V_285 = V_275 ;
V_278 -> V_207 = F_128 ( V_21 -> V_207 ) ;
V_278 -> V_286 = 0 ;
F_164 ( V_25 -> V_42 -> V_43 , V_21 ) ;
V_94 = F_170 ( V_21 ) ;
if ( V_94 )
return V_94 ;
return F_191 ( V_304 , V_21 , V_305 , V_272 , V_293 , V_200 , V_274 , V_306 ,
false ) ;
}
static void F_192 ( struct V_20 * V_21 , struct V_45 * V_307 ,
struct V_45 * V_308 )
{
struct V_186 * V_309 = F_141 ( V_307 -> V_72 -> V_203 ) ;
struct V_186 * V_310 = F_141 ( V_308 -> V_72 -> V_203 ) ;
union V_1 V_311 ;
union V_1 * V_66 = & V_308 -> V_47 . V_66 ;
V_21 -> V_235 = V_236 ;
V_21 -> V_195 = 0 ;
V_21 -> V_72 = V_308 -> V_72 ;
F_153 ( V_21 , F_154 ( V_21 ) ) ;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_311 . sin . V_9 . V_10 = F_5 ( V_312 ) ;
V_311 . V_4 . V_5 = V_18 ;
#if F_88 ( V_136 )
} else {
V_311 . V_7 . V_8 = V_313 ;
V_311 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_308 -> V_51 & V_192 )
F_104 ( V_21 -> V_72 , & V_311 , F_133 ( V_21 ) -> V_190 ) ;
F_142 ( & V_309 -> V_204 ) ;
V_309 -> V_314 ++ ;
V_309 -> V_315 += V_21 -> V_207 ;
F_143 ( & V_309 -> V_204 ) ;
if ( F_144 ( V_21 ) == V_316 ) {
F_142 ( & V_310 -> V_204 ) ;
V_310 -> V_205 ++ ;
V_310 -> V_206 += V_21 -> V_207 ;
F_143 ( & V_310 -> V_204 ) ;
} else {
V_21 -> V_72 -> V_187 . V_238 ++ ;
}
}
static void F_193 ( struct V_20 * V_21 , struct V_99 * V_72 ,
struct V_36 * V_52 , bool V_317 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_303 * V_304 = NULL ;
const struct V_182 * V_318 ;
struct V_319 V_320 ;
union V_1 * V_272 ;
T_2 V_275 = 0 , V_81 ;
T_1 V_110 ;
T_2 V_306 = 0 ;
T_8 V_200 , V_274 ;
int V_94 ;
V_81 = V_52 -> V_80 ? V_52 -> V_80 : V_46 -> V_81 ;
V_110 = V_52 -> V_48 ;
V_272 = & V_52 -> V_66 ;
if ( F_3 ( V_272 ) ) {
if ( V_317 ) {
F_192 ( V_21 , V_46 , V_46 ) ;
return;
}
goto V_180;
}
V_318 = F_134 ( V_21 ) ;
V_274 = V_46 -> V_274 ;
if ( ! V_274 && F_6 ( V_272 ) )
V_274 = 1 ;
V_200 = V_46 -> V_200 ;
if ( V_200 == 1 )
V_200 = F_194 ( V_318 , V_21 ) ;
V_275 = F_167 ( V_46 -> V_262 , V_46 -> V_263 , V_21 ) ;
if ( V_272 -> V_4 . V_5 == V_18 ) {
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
V_320 . V_321 = V_52 -> V_84 ;
V_320 . V_322 = F_195 ( V_200 ) ;
V_320 . V_241 = V_272 -> sin . V_9 . V_10 ;
V_320 . V_188 = V_46 -> V_188 . sin . V_9 . V_10 ;
V_304 = F_196 ( F_44 ( V_72 ) , & V_320 ) ;
if ( F_197 ( V_304 ) ) {
F_77 ( V_72 , L_9 ,
& V_272 -> sin . V_9 . V_10 ) ;
V_72 -> V_187 . V_323 ++ ;
goto V_324;
}
if ( V_304 -> V_272 . V_72 == V_72 ) {
F_77 ( V_72 , L_10 ,
& V_272 -> sin . V_9 . V_10 ) ;
V_72 -> V_187 . V_325 ++ ;
goto V_324;
}
if ( V_304 -> V_326 & V_327 &&
! ( V_304 -> V_326 & ( V_328 | V_329 ) ) ) {
struct V_45 * V_308 ;
F_198 ( V_304 ) ;
V_308 = F_30 ( F_44 ( V_72 ) , V_110 , V_81 ) ;
if ( ! V_308 )
goto V_324;
F_192 ( V_21 , V_46 , V_308 ) ;
return;
}
V_200 = F_199 ( V_200 , V_318 , V_21 ) ;
V_274 = V_274 ? : F_200 ( & V_304 -> V_272 ) ;
V_94 = F_190 ( V_46 -> V_164 , V_304 , V_21 ,
V_320 . V_188 , V_272 -> sin . V_9 . V_10 ,
V_200 , V_274 , V_306 , V_275 , V_81 ,
F_5 ( V_110 << 8 ) ) ;
if ( V_94 < 0 )
goto V_330;
F_201 ( V_94 , & V_72 -> V_187 , V_72 -> V_203 ) ;
#if F_88 ( V_136 )
} else {
struct V_42 * V_43 = V_46 -> V_164 -> V_42 -> V_43 ;
struct V_271 * V_331 ;
struct V_332 V_333 ;
T_1 V_51 ;
memset ( & V_333 , 0 , sizeof( V_333 ) ) ;
V_333 . V_334 = V_52 -> V_84 ;
V_333 . V_241 = V_272 -> V_7 . V_8 ;
V_333 . V_188 = V_46 -> V_188 . V_7 . V_8 ;
V_333 . V_335 = V_293 ;
if ( V_169 -> V_336 ( V_43 , & V_331 , & V_333 ) ) {
F_77 ( V_72 , L_11 ,
& V_272 -> V_7 . V_8 ) ;
V_72 -> V_187 . V_323 ++ ;
goto V_324;
}
if ( V_331 -> V_72 == V_72 ) {
F_77 ( V_72 , L_12 ,
& V_272 -> V_7 . V_8 ) ;
F_202 ( V_331 ) ;
V_72 -> V_187 . V_325 ++ ;
goto V_324;
}
V_51 = ( (struct V_337 * ) V_331 ) -> V_338 ;
if ( V_51 & V_339 &&
! ( V_51 & ( V_328 | V_329 ) ) ) {
struct V_45 * V_308 ;
F_202 ( V_331 ) ;
V_308 = F_30 ( F_44 ( V_72 ) , V_110 , V_81 ) ;
if ( ! V_308 )
goto V_324;
F_192 ( V_21 , V_46 , V_308 ) ;
return;
}
V_274 = V_274 ? : F_203 ( V_331 ) ;
V_94 = F_174 ( V_46 -> V_164 , V_331 , V_21 ,
V_72 , & V_333 . V_188 , & V_333 . V_241 , 0 , V_274 ,
V_275 , V_81 , F_5 ( V_110 << 8 ) ) ;
#endif
}
return;
V_180:
V_72 -> V_187 . V_217 ++ ;
goto V_340;
V_330:
F_198 ( V_304 ) ;
V_324:
V_72 -> V_187 . V_341 ++ ;
V_340:
F_204 ( V_21 ) ;
}
static T_11 F_205 ( struct V_20 * V_21 , struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_342 * V_343 ;
bool V_317 = false ;
struct V_36 * V_52 ;
struct V_37 * V_100 ;
F_131 ( V_21 ) ;
V_343 = F_133 ( V_21 ) ;
if ( ( V_46 -> V_51 & V_344 ) ) {
if ( F_21 ( V_343 -> V_256 ) == V_234 )
return F_145 ( V_72 , V_21 ) ;
#if F_88 ( V_136 )
else if ( F_21 ( V_343 -> V_256 ) == V_258 &&
V_21 -> V_207 >= sizeof( struct V_184 ) + sizeof( struct V_242 ) &&
F_135 ( V_21 ) -> V_301 == V_345 ) {
struct V_242 * V_243 ;
V_243 = (struct V_242 * ) F_160 ( V_21 ) ;
if ( V_243 -> V_246 . V_247 == 0 &&
V_243 -> V_246 . V_248 == V_249 )
return F_157 ( V_72 , V_21 ) ;
}
#endif
}
V_100 = F_62 ( V_46 , V_343 -> V_255 ) ;
V_317 = false ;
if ( V_100 && ( V_100 -> V_51 & V_346 ) && ( V_46 -> V_51 & V_347 ) &&
( F_21 ( V_343 -> V_256 ) == V_222 ||
F_21 ( V_343 -> V_256 ) == V_258 ) ) {
V_317 = F_161 ( V_72 , V_21 ) ;
if ( V_317 )
V_100 = F_62 ( V_46 , V_343 -> V_255 ) ;
}
if ( V_100 == NULL ) {
V_100 = F_62 ( V_46 , V_348 ) ;
if ( V_100 == NULL ) {
if ( ( V_46 -> V_51 & V_349 ) &&
! F_78 ( V_343 -> V_255 ) )
F_54 ( V_46 , V_343 -> V_255 ) ;
V_72 -> V_187 . V_217 ++ ;
F_204 ( V_21 ) ;
return V_240 ;
}
}
F_102 (rdst, &f->remotes, list) {
struct V_20 * V_350 ;
V_350 = F_206 ( V_21 , V_96 ) ;
if ( V_350 )
F_193 ( V_350 , V_72 , V_52 , V_317 ) ;
}
F_204 ( V_21 ) ;
return V_240 ;
}
static void F_207 ( unsigned long V_351 )
{
struct V_45 * V_46 = (struct V_45 * ) V_351 ;
unsigned long V_352 = V_54 + V_353 ;
unsigned int V_148 ;
if ( ! F_109 ( V_46 -> V_72 ) )
return;
F_95 ( & V_46 -> V_143 ) ;
for ( V_148 = 0 ; V_148 < V_149 ; ++ V_148 ) {
struct V_354 * V_355 , * V_215 ;
F_208 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_100
= F_81 ( V_355 , struct V_37 , V_129 ) ;
unsigned long V_356 ;
if ( V_100 -> V_70 & V_141 )
continue;
V_356 = V_100 -> V_87 + V_46 -> V_357 * V_358 ;
if ( F_209 ( V_356 , V_54 ) ) {
F_77 ( V_46 -> V_72 ,
L_13 ,
V_100 -> V_67 ) ;
V_100 -> V_70 = V_101 ;
F_84 ( V_46 , V_100 ) ;
} else if ( F_210 ( V_356 , V_352 ) )
V_352 = V_356 ;
}
}
F_96 ( & V_46 -> V_143 ) ;
F_211 ( & V_46 -> V_359 , V_352 ) ;
}
static void F_212 ( struct V_24 * V_25 , struct V_45 * V_46 )
{
V_93 V_110 = V_46 -> V_47 . V_48 ;
V_46 -> V_164 = V_25 ;
F_79 ( & V_46 -> V_129 , F_17 ( V_25 , V_110 ) ) ;
}
static int F_213 ( struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_24 * V_25 ;
V_72 -> V_203 = F_214 ( struct V_186 ) ;
if ( ! V_72 -> V_203 )
return - V_128 ;
F_108 ( & V_32 -> V_158 ) ;
V_25 = F_26 ( F_44 ( V_72 ) , V_46 -> V_81 ) ;
if ( V_25 ) {
F_113 ( & V_25 -> V_157 ) ;
F_212 ( V_25 , V_46 ) ;
} else {
F_215 ( V_72 ) ;
F_117 ( V_159 , & V_46 -> V_360 ) ;
}
F_110 ( & V_32 -> V_158 ) ;
return 0 ;
}
static void F_216 ( struct V_45 * V_46 )
{
struct V_37 * V_100 ;
F_95 ( & V_46 -> V_143 ) ;
V_100 = F_60 ( V_46 , V_348 ) ;
if ( V_100 )
F_84 ( V_46 , V_100 ) ;
F_96 ( & V_46 -> V_143 ) ;
}
static void F_217 ( struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_164 ;
F_216 ( V_46 ) ;
if ( V_25 )
F_114 ( V_25 ) ;
F_218 ( V_72 -> V_203 ) ;
}
static int F_219 ( struct V_99 * V_72 )
{
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_164 ;
if ( ! V_25 )
return - V_361 ;
if ( F_6 ( & V_46 -> V_47 . V_66 ) &&
F_111 ( V_32 , & V_46 -> V_47 . V_66 ) ) {
F_112 ( V_25 ) ;
F_215 ( V_72 ) ;
F_117 ( V_159 , & V_46 -> V_163 ) ;
}
if ( V_46 -> V_357 )
F_211 ( & V_46 -> V_359 , V_54 + V_353 ) ;
return 0 ;
}
static void F_220 ( struct V_45 * V_46 )
{
unsigned int V_148 ;
F_95 ( & V_46 -> V_143 ) ;
for ( V_148 = 0 ; V_148 < V_149 ; ++ V_148 ) {
struct V_354 * V_355 , * V_215 ;
F_208 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_100
= F_81 ( V_355 , struct V_37 , V_129 ) ;
if ( ! F_34 ( V_100 -> V_67 ) )
F_84 ( V_46 , V_100 ) ;
}
}
F_96 ( & V_46 -> V_143 ) ;
}
static int F_221 ( struct V_99 * V_72 )
{
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_164 ;
if ( V_25 && F_6 ( & V_46 -> V_47 . V_66 ) &&
! F_111 ( V_32 , & V_46 -> V_47 . V_66 ) ) {
F_112 ( V_25 ) ;
F_215 ( V_72 ) ;
F_117 ( V_159 , & V_46 -> V_171 ) ;
}
F_222 ( & V_46 -> V_359 ) ;
F_220 ( V_46 ) ;
return 0 ;
}
static void F_223 ( struct V_99 * V_72 )
{
}
void F_224 ( struct V_99 * V_72 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_44 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_6 V_5 ;
T_2 V_30 ;
unsigned int V_362 ;
F_108 ( & V_32 -> V_158 ) ;
for ( V_362 = 0 ; V_362 < V_363 ; ++ V_362 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_42 -> V_43 ) -> V_44 ;
V_5 = V_25 -> V_42 -> V_43 -> V_112 ;
V_72 -> V_113 -> V_114 ( V_72 , V_5 ,
V_30 ) ;
}
}
F_110 ( & V_32 -> V_158 ) ;
}
static void F_225 ( struct V_99 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_148 ;
int V_364 , V_365 ;
F_226 ( V_72 ) ;
F_227 ( V_72 ) ;
if ( V_46 -> V_47 . V_66 . V_4 . V_5 == V_6 )
V_72 -> V_366 = V_367 + V_368 ;
else
V_72 -> V_366 = V_367 + V_369 ;
V_72 -> V_113 = & V_370 ;
V_72 -> V_261 = V_371 ;
F_228 ( V_72 , & V_372 ) ;
V_72 -> V_373 = 0 ;
V_72 -> V_196 |= V_374 ;
V_72 -> V_196 |= V_375 ;
V_72 -> V_196 |= V_376 | V_377 ;
V_72 -> V_196 |= V_197 ;
V_72 -> V_196 |= V_378 ;
V_72 -> V_379 = V_72 -> V_196 ;
V_72 -> V_196 |= V_380 | V_381 ;
V_72 -> V_382 |= V_376 | V_377 | V_197 ;
V_72 -> V_382 |= V_378 ;
V_72 -> V_382 |= V_380 | V_381 ;
V_72 -> V_383 &= ~ V_384 ;
V_72 -> V_383 |= V_385 ;
F_52 ( & V_46 -> V_40 ) ;
F_229 ( & V_46 -> V_143 ) ;
F_230 ( & V_46 -> V_163 , F_118 ) ;
F_230 ( & V_46 -> V_171 , F_122 ) ;
F_230 ( & V_46 -> V_360 , V_386 ) ;
F_231 ( & V_46 -> V_359 ) ;
V_46 -> V_359 . V_387 = F_207 ;
V_46 -> V_359 . V_266 = ( unsigned long ) V_46 ;
F_232 ( & V_364 , & V_365 ) ;
V_46 -> V_262 = V_364 ;
V_46 -> V_263 = V_365 ;
V_46 -> V_81 = F_128 ( V_388 ) ;
V_46 -> V_72 = V_72 ;
for ( V_148 = 0 ; V_148 < V_149 ; ++ V_148 )
F_233 ( & V_46 -> V_108 [ V_148 ] ) ;
}
static int F_234 ( struct V_14 * V_135 [] , struct V_14 * V_266 [] )
{
if ( V_135 [ V_389 ] ) {
if ( F_11 ( V_135 [ V_389 ] ) != V_78 ) {
F_235 ( L_14 ) ;
return - V_138 ;
}
if ( ! F_236 ( F_237 ( V_135 [ V_389 ] ) ) ) {
F_235 ( L_15 ) ;
return - V_140 ;
}
}
if ( ! V_266 )
return - V_138 ;
if ( V_266 [ V_390 ] ) {
V_93 V_26 = F_90 ( V_266 [ V_390 ] ) ;
if ( V_26 >= V_391 )
return - V_392 ;
}
if ( V_266 [ V_393 ] ) {
const struct V_394 * V_355
= F_237 ( V_266 [ V_393 ] ) ;
if ( F_21 ( V_355 -> V_365 ) < F_21 ( V_355 -> V_364 ) ) {
F_235 ( L_16 ,
F_21 ( V_355 -> V_364 ) , F_21 ( V_355 -> V_365 ) ) ;
return - V_138 ;
}
}
return 0 ;
}
static void F_238 ( struct V_99 * V_395 ,
struct V_396 * V_397 )
{
F_239 ( V_397 -> V_297 , V_398 , sizeof( V_397 -> V_297 ) ) ;
F_239 ( V_397 -> V_399 , L_17 , sizeof( V_397 -> V_399 ) ) ;
}
static void F_240 ( struct V_161 * V_162 )
{
struct V_24 * V_25 = F_81 ( V_162 , struct V_24 , V_160 ) ;
F_241 ( V_25 -> V_42 -> V_43 ) ;
F_100 ( V_25 , V_132 ) ;
}
static int F_242 ( struct V_29 * V_29 , T_2 V_30 , struct V_400 * * V_401 )
{
struct V_42 * V_43 ;
struct V_400 * V_42 ;
struct V_402 V_1 = {
. V_403 = V_6 ,
. V_404 = V_30 ,
} ;
int V_120 , V_405 = 1 ;
V_120 = F_243 ( V_6 , V_406 , V_293 , & V_42 ) ;
if ( V_120 < 0 ) {
F_235 ( L_18 ) ;
return V_120 ;
}
V_43 = V_42 -> V_43 ;
F_244 ( V_43 , V_29 ) ;
F_245 ( V_42 , V_407 , V_408 ,
( char * ) & V_405 , sizeof( V_405 ) ) ;
V_120 = F_246 ( V_42 , (struct V_409 * ) & V_1 ,
sizeof( struct V_402 ) ) ;
if ( V_120 < 0 ) {
F_235 ( L_19 ,
& V_1 . V_8 , F_21 ( V_1 . V_404 ) , V_120 ) ;
F_241 ( V_43 ) ;
return V_120 ;
}
F_247 ( ! V_169 ) ;
* V_401 = V_42 ;
F_28 ( V_43 ) -> V_410 = 0 ;
return 0 ;
}
static int F_242 ( struct V_29 * V_29 , T_2 V_30 , struct V_400 * * V_401 )
{
return - V_411 ;
}
static int F_248 ( struct V_29 * V_29 , T_2 V_30 , struct V_400 * * V_401 )
{
struct V_42 * V_43 ;
struct V_400 * V_42 ;
struct V_412 V_1 = {
. V_413 = V_18 ,
. V_9 . V_10 = F_5 ( V_12 ) ,
. V_414 = V_30 ,
} ;
int V_120 ;
V_120 = F_243 ( V_18 , V_406 , V_293 , & V_42 ) ;
if ( V_120 < 0 ) {
F_235 ( L_20 ) ;
return V_120 ;
}
V_43 = V_42 -> V_43 ;
F_244 ( V_43 , V_29 ) ;
V_120 = F_246 ( V_42 , (struct V_409 * ) & V_1 ,
sizeof( V_1 ) ) ;
if ( V_120 < 0 ) {
F_235 ( L_21 ,
& V_1 . V_9 , F_21 ( V_1 . V_414 ) , V_120 ) ;
F_241 ( V_43 ) ;
return V_120 ;
}
* V_401 = V_42 ;
F_28 ( V_43 ) -> V_410 = 0 ;
return 0 ;
}
static struct V_24 * F_249 ( struct V_29 * V_29 , T_2 V_30 ,
T_12 * V_181 , void * V_266 , bool V_415 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_400 * V_42 ;
struct V_42 * V_43 ;
int V_120 = 0 ;
unsigned int V_148 ;
V_25 = F_68 ( sizeof( * V_25 ) , V_416 ) ;
if ( ! V_25 )
return F_250 ( - V_128 ) ;
for ( V_148 = 0 ; V_148 < V_417 ; ++ V_148 )
F_233 ( & V_25 -> V_27 [ V_148 ] ) ;
F_230 ( & V_25 -> V_160 , F_240 ) ;
if ( V_415 )
V_120 = F_242 ( V_29 , V_30 , & V_42 ) ;
else
V_120 = F_248 ( V_29 , V_30 , & V_42 ) ;
if ( V_120 < 0 ) {
F_83 ( V_25 ) ;
return F_250 ( V_120 ) ;
}
V_25 -> V_42 = V_42 ;
V_43 = V_42 -> V_43 ;
F_251 ( & V_25 -> V_157 , 1 ) ;
V_25 -> V_181 = V_181 ;
V_25 -> V_266 = V_266 ;
F_116 ( V_25 -> V_42 -> V_43 , V_25 ) ;
F_108 ( & V_32 -> V_158 ) ;
F_79 ( & V_25 -> V_129 , F_19 ( V_29 , V_30 ) ) ;
F_70 ( V_43 ) ;
F_110 ( & V_32 -> V_158 ) ;
F_252 ( V_43 ) -> V_418 = 1 ;
F_252 ( V_43 ) -> V_419 = F_124 ;
#if F_88 ( V_136 )
if ( V_415 )
V_169 -> V_420 () ;
else
#endif
F_253 () ;
return V_25 ;
}
struct V_24 * F_254 ( struct V_29 * V_29 , T_2 V_30 ,
T_12 * V_181 , void * V_266 ,
bool V_421 , bool V_415 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
V_25 = F_249 ( V_29 , V_30 , V_181 , V_266 , V_415 ) ;
if ( ! F_197 ( V_25 ) )
return V_25 ;
if ( V_421 )
return V_25 ;
F_108 ( & V_32 -> V_158 ) ;
V_25 = F_26 ( V_29 , V_30 ) ;
if ( V_25 ) {
if ( V_25 -> V_181 == V_181 )
F_113 ( & V_25 -> V_157 ) ;
else
V_25 = F_250 ( - V_422 ) ;
}
F_110 ( & V_32 -> V_158 ) ;
if ( ! V_25 )
V_25 = F_250 ( - V_138 ) ;
return V_25 ;
}
static void V_386 ( struct V_161 * V_162 )
{
struct V_45 * V_46 = F_81 ( V_162 , struct V_45 , V_360 ) ;
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_46 -> V_81 ;
struct V_24 * V_423 ;
V_423 = F_254 ( V_29 , V_30 , F_130 , NULL , false , V_46 -> V_51 & V_424 ) ;
F_108 ( & V_32 -> V_158 ) ;
if ( ! F_197 ( V_423 ) )
F_212 ( V_423 , V_46 ) ;
F_110 ( & V_32 -> V_158 ) ;
F_92 ( V_46 -> V_72 ) ;
}
static int F_255 ( struct V_29 * V_29 , struct V_99 * V_72 ,
struct V_14 * V_135 [] , struct V_14 * V_266 [] )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_272 = & V_46 -> V_47 ;
V_93 V_110 ;
int V_94 ;
bool V_425 = false ;
if ( ! V_266 [ V_390 ] )
return - V_138 ;
V_110 = F_90 ( V_266 [ V_390 ] ) ;
V_272 -> V_48 = V_110 ;
if ( V_266 [ V_426 ] ) {
V_272 -> V_66 . sin . V_9 . V_10 = F_13 ( V_266 [ V_426 ] ) ;
V_272 -> V_66 . V_4 . V_5 = V_18 ;
} else if ( V_266 [ V_427 ] ) {
if ( ! F_88 ( V_136 ) )
return - V_411 ;
F_12 ( & V_272 -> V_66 . V_7 . V_8 , V_266 [ V_427 ] ,
sizeof( struct V_16 ) ) ;
V_272 -> V_66 . V_4 . V_5 = V_6 ;
V_425 = true ;
}
if ( V_266 [ V_428 ] ) {
V_46 -> V_188 . sin . V_9 . V_10 = F_13 ( V_266 [ V_428 ] ) ;
V_46 -> V_188 . V_4 . V_5 = V_18 ;
} else if ( V_266 [ V_429 ] ) {
if ( ! F_88 ( V_136 ) )
return - V_411 ;
F_12 ( & V_46 -> V_188 . V_7 . V_8 , V_266 [ V_429 ] ,
sizeof( struct V_16 ) ) ;
V_46 -> V_188 . V_4 . V_5 = V_6 ;
V_425 = true ;
}
if ( V_266 [ V_430 ] &&
( V_272 -> V_84 = F_90 ( V_266 [ V_430 ] ) ) ) {
struct V_99 * V_431
= F_256 ( V_29 , V_272 -> V_84 ) ;
if ( ! V_431 ) {
F_94 ( L_22 , V_272 -> V_84 ) ;
return - V_432 ;
}
#if F_88 ( V_136 )
if ( V_425 ) {
struct V_244 * V_433 = F_158 ( V_431 ) ;
if ( V_433 && V_433 -> V_253 . V_434 ) {
F_94 ( L_23 ) ;
return - V_435 ;
}
V_46 -> V_51 |= V_424 ;
}
#endif
if ( ! V_135 [ V_436 ] )
V_72 -> V_437 = V_431 -> V_437 - ( V_425 ? V_368 : V_369 ) ;
V_72 -> V_366 = V_431 -> V_366 +
( V_425 ? V_368 : V_369 ) ;
}
if ( V_266 [ V_438 ] )
V_46 -> V_200 = F_257 ( V_266 [ V_438 ] ) ;
if ( V_266 [ V_439 ] )
V_46 -> V_274 = F_257 ( V_266 [ V_439 ] ) ;
if ( ! V_266 [ V_440 ] || F_257 ( V_266 [ V_440 ] ) )
V_46 -> V_51 |= V_192 ;
if ( V_266 [ V_441 ] )
V_46 -> V_357 = F_90 ( V_266 [ V_441 ] ) ;
else
V_46 -> V_357 = V_442 ;
if ( V_266 [ V_443 ] && F_257 ( V_266 [ V_443 ] ) )
V_46 -> V_51 |= V_344 ;
if ( V_266 [ V_444 ] && F_257 ( V_266 [ V_444 ] ) )
V_46 -> V_51 |= V_347 ;
if ( V_266 [ V_445 ] && F_257 ( V_266 [ V_445 ] ) )
V_46 -> V_51 |= V_349 ;
if ( V_266 [ V_446 ] && F_257 ( V_266 [ V_446 ] ) )
V_46 -> V_51 |= V_239 ;
if ( V_266 [ V_447 ] )
V_46 -> V_125 = F_90 ( V_266 [ V_447 ] ) ;
if ( V_266 [ V_393 ] ) {
const struct V_394 * V_355
= F_237 ( V_266 [ V_393 ] ) ;
V_46 -> V_262 = F_21 ( V_355 -> V_364 ) ;
V_46 -> V_263 = F_21 ( V_355 -> V_365 ) ;
}
if ( V_266 [ V_448 ] )
V_46 -> V_81 = F_89 ( V_266 [ V_448 ] ) ;
if ( F_30 ( V_29 , V_110 , V_46 -> V_81 ) ) {
F_94 ( L_24 , V_110 ) ;
return - V_118 ;
}
F_258 ( V_72 , & V_449 ) ;
if ( ! F_3 ( & V_46 -> V_47 . V_66 ) ) {
V_94 = F_76 ( V_46 , V_348 ,
& V_46 -> V_47 . V_66 ,
V_142 | V_141 ,
V_117 | V_123 ,
V_46 -> V_81 ,
V_46 -> V_47 . V_48 ,
V_46 -> V_47 . V_84 ,
V_156 ) ;
if ( V_94 )
return V_94 ;
}
V_94 = F_259 ( V_72 ) ;
if ( V_94 ) {
F_216 ( V_46 ) ;
return V_94 ;
}
F_260 ( & V_46 -> V_40 , & V_32 -> V_450 ) ;
return 0 ;
}
static void F_261 ( struct V_99 * V_72 , struct V_451 * V_109 )
{
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
F_108 ( & V_32 -> V_158 ) ;
if ( ! F_262 ( & V_46 -> V_129 ) )
F_85 ( & V_46 -> V_129 ) ;
F_110 ( & V_32 -> V_158 ) ;
F_263 ( & V_46 -> V_40 ) ;
F_264 ( V_72 , V_109 ) ;
}
static T_3 F_265 ( const struct V_99 * V_72 )
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
F_42 ( sizeof( struct V_394 ) ) +
F_42 ( sizeof( T_2 ) ) +
0 ;
}
static int F_266 ( struct V_20 * V_21 , const struct V_99 * V_72 )
{
const struct V_45 * V_46 = F_51 ( V_72 ) ;
const struct V_36 * V_272 = & V_46 -> V_47 ;
struct V_394 V_452 = {
. V_364 = F_128 ( V_46 -> V_262 ) ,
. V_365 = F_128 ( V_46 -> V_263 ) ,
} ;
if ( F_36 ( V_21 , V_390 , V_272 -> V_48 ) )
goto V_79;
if ( ! F_3 ( & V_272 -> V_66 ) ) {
if ( V_272 -> V_66 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_426 ,
V_272 -> V_66 . sin . V_9 . V_10 ) )
goto V_79;
#if F_88 ( V_136 )
} else {
if ( F_15 ( V_21 , V_427 , sizeof( struct V_16 ) ,
& V_272 -> V_66 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( V_272 -> V_84 && F_36 ( V_21 , V_430 , V_272 -> V_84 ) )
goto V_79;
if ( ! F_3 ( & V_46 -> V_188 ) ) {
if ( V_46 -> V_188 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_428 ,
V_46 -> V_188 . sin . V_9 . V_10 ) )
goto V_79;
#if F_88 ( V_136 )
} else {
if ( F_15 ( V_21 , V_429 , sizeof( struct V_16 ) ,
& V_46 -> V_188 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( F_267 ( V_21 , V_439 , V_46 -> V_274 ) ||
F_267 ( V_21 , V_438 , V_46 -> V_200 ) ||
F_267 ( V_21 , V_440 ,
! ! ( V_46 -> V_51 & V_192 ) ) ||
F_267 ( V_21 , V_443 ,
! ! ( V_46 -> V_51 & V_344 ) ) ||
F_267 ( V_21 , V_444 , ! ! ( V_46 -> V_51 & V_347 ) ) ||
F_267 ( V_21 , V_445 ,
! ! ( V_46 -> V_51 & V_349 ) ) ||
F_267 ( V_21 , V_446 ,
! ! ( V_46 -> V_51 & V_239 ) ) ||
F_36 ( V_21 , V_441 , V_46 -> V_357 ) ||
F_36 ( V_21 , V_447 , V_46 -> V_125 ) ||
F_35 ( V_21 , V_448 , V_46 -> V_81 ) )
goto V_79;
if ( F_15 ( V_21 , V_393 , sizeof( V_452 ) , & V_452 ) )
goto V_79;
return 0 ;
V_79:
return - V_63 ;
}
static T_13 int F_268 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_148 ;
F_52 ( & V_32 -> V_450 ) ;
F_229 ( & V_32 -> V_158 ) ;
for ( V_148 = 0 ; V_148 < V_363 ; ++ V_148 )
F_233 ( & V_32 -> V_34 [ V_148 ] ) ;
return 0 ;
}
static T_14 void F_269 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 ;
F_270 ( V_41 ) ;
F_271 () ;
F_64 (vxlan, &vn->vxlan_list, next)
F_264 ( V_46 -> V_72 , & V_41 ) ;
F_272 ( & V_41 ) ;
F_273 () ;
}
static int T_15 F_274 ( void )
{
int V_120 ;
V_159 = F_275 ( L_17 , 0 , 0 ) ;
if ( ! V_159 )
return - V_128 ;
F_276 ( & V_453 , sizeof( V_453 ) ) ;
V_120 = F_277 ( & V_454 ) ;
if ( V_120 )
goto V_455;
V_120 = F_278 ( & V_456 ) ;
if ( V_120 )
goto V_457;
return 0 ;
V_457:
F_279 ( & V_454 ) ;
V_455:
F_280 ( V_159 ) ;
return V_120 ;
}
static void T_16 F_281 ( void )
{
F_282 ( & V_456 ) ;
F_280 ( V_159 ) ;
F_279 ( & V_454 ) ;
F_283 () ;
}
