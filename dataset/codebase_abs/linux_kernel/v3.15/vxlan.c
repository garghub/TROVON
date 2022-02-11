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
static void F_43 ( struct V_45 * V_46 , struct V_37 * V_38 ,
struct V_36 * V_94 , int type )
{
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
struct V_20 * V_21 ;
int V_95 = - V_96 ;
V_21 = F_45 ( F_40 () , V_97 ) ;
if ( V_21 == NULL )
goto V_98;
V_95 = F_31 ( V_21 , V_46 , V_38 , 0 , 0 , type , 0 , V_94 ) ;
if ( V_95 < 0 ) {
F_46 ( V_95 == - V_63 ) ;
F_47 ( V_21 ) ;
goto V_98;
}
F_48 ( V_21 , V_29 , 0 , V_99 , NULL , V_97 ) ;
return;
V_98:
if ( V_95 < 0 )
F_49 ( V_29 , V_99 , V_95 ) ;
}
static void F_50 ( struct V_100 * V_72 , union V_1 * V_11 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 V_101 = {
. V_70 = V_102 ,
} ;
struct V_36 V_103 = {
. V_66 = * V_11 ,
. V_48 = V_104 ,
} ;
F_43 ( V_46 , & V_101 , & V_103 , V_64 ) ;
}
static void F_52 ( struct V_45 * V_46 , const T_4 V_67 [ V_78 ] )
{
struct V_37 V_101 = {
. V_70 = V_102 ,
} ;
struct V_36 V_103 = { } ;
memcpy ( V_101 . V_67 , V_67 , V_78 ) ;
F_43 ( V_46 , & V_101 , & V_103 , V_64 ) ;
}
static T_1 F_53 ( const unsigned char * V_105 )
{
T_5 V_106 = F_54 ( ( T_5 * ) V_105 ) ;
#ifdef F_55
V_106 >>= 16 ;
#else
V_106 <<= 16 ;
#endif
return F_56 ( V_106 , V_107 ) ;
}
static inline struct V_23 * F_57 ( struct V_45 * V_46 ,
const T_4 * V_108 )
{
return & V_46 -> V_109 [ F_53 ( V_108 ) ] ;
}
static struct V_37 * F_58 ( struct V_45 * V_46 ,
const T_4 * V_108 )
{
struct V_23 * V_110 = F_57 ( V_46 , V_108 ) ;
struct V_37 * V_101 ;
F_27 (f, head, hlist) {
if ( F_59 ( V_108 , V_101 -> V_67 ) )
return V_101 ;
}
return NULL ;
}
static struct V_37 * F_60 ( struct V_45 * V_46 ,
const T_4 * V_108 )
{
struct V_37 * V_101 ;
V_101 = F_58 ( V_46 , V_108 ) ;
if ( V_101 )
V_101 -> V_87 = V_54 ;
return V_101 ;
}
static struct V_36 * F_61 ( struct V_37 * V_101 ,
union V_1 * V_13 , T_2 V_30 ,
V_93 V_111 , V_93 V_73 )
{
struct V_36 * V_94 ;
F_62 (rd, &f->remotes, list) {
if ( F_1 ( & V_94 -> V_66 , V_13 ) &&
V_94 -> V_80 == V_30 &&
V_94 -> V_48 == V_111 &&
V_94 -> V_84 == V_73 )
return V_94 ;
}
return NULL ;
}
static int F_63 ( struct V_37 * V_101 ,
union V_1 * V_13 , T_2 V_30 , V_93 V_111 , V_93 V_73 )
{
struct V_36 * V_94 ;
V_94 = F_61 ( V_101 , V_13 , V_30 , V_111 , V_73 ) ;
if ( V_94 )
return 0 ;
V_94 = F_64 ( & V_101 -> V_39 , struct V_36 , V_41 ) ;
if ( ! V_94 )
return 0 ;
V_94 -> V_66 = * V_13 ;
V_94 -> V_80 = V_30 ;
V_94 -> V_48 = V_111 ;
V_94 -> V_84 = V_73 ;
return 1 ;
}
static int F_65 ( struct V_37 * V_101 ,
union V_1 * V_13 , T_2 V_30 , V_93 V_111 ,
V_93 V_73 , struct V_36 * * V_112 )
{
struct V_36 * V_94 ;
V_94 = F_61 ( V_101 , V_13 , V_30 , V_111 , V_73 ) ;
if ( V_94 )
return 0 ;
V_94 = F_66 ( sizeof( * V_94 ) , V_97 ) ;
if ( V_94 == NULL )
return - V_96 ;
V_94 -> V_66 = * V_13 ;
V_94 -> V_80 = V_30 ;
V_94 -> V_48 = V_111 ;
V_94 -> V_84 = V_73 ;
F_67 ( & V_94 -> V_41 , & V_101 -> V_39 ) ;
* V_112 = V_94 ;
return 1 ;
}
static struct V_20 * * F_68 ( struct V_20 * * V_110 , struct V_20 * V_21 )
{
struct V_20 * V_113 , * * V_114 = NULL ;
struct V_115 * V_116 , * V_117 ;
struct V_118 * V_119 , * V_120 ;
unsigned int V_121 , V_122 , V_123 ;
const struct V_124 * V_125 ;
T_2 type ;
int V_126 = 1 ;
V_122 = F_69 ( V_21 ) ;
V_121 = V_122 + sizeof( * V_116 ) ;
V_116 = F_70 ( V_21 , V_122 ) ;
if ( F_71 ( V_21 , V_121 ) ) {
V_116 = F_72 ( V_21 , V_121 , V_122 ) ;
if ( F_73 ( ! V_116 ) )
goto V_127;
}
F_74 ( V_21 , sizeof( struct V_115 ) ) ;
V_123 = F_69 ( V_21 ) ;
V_121 = V_123 + sizeof( * V_119 ) ;
V_119 = F_70 ( V_21 , V_123 ) ;
if ( F_71 ( V_21 , V_121 ) ) {
V_119 = F_72 ( V_21 , V_121 , V_123 ) ;
if ( F_73 ( ! V_119 ) )
goto V_127;
}
V_126 = 0 ;
for ( V_113 = * V_110 ; V_113 ; V_113 = V_113 -> V_40 ) {
if ( ! F_75 ( V_113 ) -> V_128 )
continue;
V_117 = (struct V_115 * ) ( V_113 -> V_129 + V_122 ) ;
V_120 = (struct V_118 * ) ( V_113 -> V_129 + V_123 ) ;
if ( V_116 -> V_130 != V_117 -> V_130 || F_76 ( V_119 , V_120 ) ) {
F_75 ( V_113 ) -> V_128 = 0 ;
continue;
}
}
type = V_119 -> V_131 ;
F_77 () ;
V_125 = F_78 ( type ) ;
if ( V_125 == NULL ) {
V_126 = 1 ;
goto V_132;
}
F_74 ( V_21 , sizeof( * V_119 ) ) ;
V_114 = V_125 -> V_133 . V_134 ( V_110 , V_21 ) ;
V_132:
F_79 () ;
V_127:
F_75 ( V_21 ) -> V_126 |= V_126 ;
return V_114 ;
}
static int F_80 ( struct V_20 * V_21 , int V_135 )
{
struct V_118 * V_119 ;
struct V_124 * V_125 ;
T_2 type ;
int V_136 = sizeof( struct V_115 ) + sizeof( struct V_118 ) ;
int V_95 = - V_137 ;
V_119 = (struct V_118 * ) ( V_21 -> V_129 + V_135 + sizeof( struct V_115 ) ) ;
type = V_119 -> V_131 ;
F_77 () ;
V_125 = F_81 ( type ) ;
if ( V_125 != NULL )
V_95 = V_125 -> V_133 . V_138 ( V_21 , V_135 + V_136 ) ;
F_79 () ;
return V_95 ;
}
static void F_82 ( struct V_24 * V_25 )
{
struct V_100 * V_72 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_83 ( V_43 ) ;
T_6 V_5 = V_43 -> V_139 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
int V_95 ;
if ( V_5 == V_18 ) {
V_95 = F_84 ( & V_25 -> V_140 ) ;
if ( V_95 )
F_85 ( L_1 , V_95 ) ;
}
F_77 () ;
F_86 (net, dev) {
if ( V_72 -> V_141 -> V_142 )
V_72 -> V_141 -> V_142 ( V_72 , V_5 ,
V_30 ) ;
}
F_79 () ;
}
static void F_87 ( struct V_24 * V_25 )
{
struct V_100 * V_72 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_83 ( V_43 ) ;
T_6 V_5 = V_43 -> V_139 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
F_77 () ;
F_86 (net, dev) {
if ( V_72 -> V_141 -> V_143 )
V_72 -> V_141 -> V_143 ( V_72 , V_5 ,
V_30 ) ;
}
F_79 () ;
if ( V_5 == V_18 )
F_88 ( & V_25 -> V_140 ) ;
}
static int F_89 ( struct V_45 * V_46 ,
const T_4 * V_108 , union V_1 * V_13 ,
T_7 V_70 , T_7 V_51 ,
T_2 V_30 , V_93 V_111 , V_93 V_73 ,
T_8 V_74 )
{
struct V_36 * V_94 = NULL ;
struct V_37 * V_101 ;
int V_144 = 0 ;
V_101 = F_58 ( V_46 , V_108 ) ;
if ( V_101 ) {
if ( V_51 & V_145 ) {
F_90 ( V_46 -> V_72 ,
L_2 , V_108 ) ;
return - V_146 ;
}
if ( V_101 -> V_70 != V_70 ) {
V_101 -> V_70 = V_70 ;
V_101 -> V_90 = V_54 ;
V_144 = 1 ;
}
if ( V_101 -> V_51 != V_74 ) {
V_101 -> V_51 = V_74 ;
V_101 -> V_90 = V_54 ;
V_144 = 1 ;
}
if ( ( V_51 & V_147 ) ) {
if ( ! ( F_91 ( V_101 -> V_67 ) ||
F_34 ( V_101 -> V_67 ) ) ) {
int V_148 = F_63 ( V_101 , V_13 , V_30 , V_111 ,
V_73 ) ;
if ( V_148 < 0 )
return V_148 ;
V_144 |= V_148 ;
} else
return - V_149 ;
}
if ( ( V_51 & V_150 ) &&
( F_91 ( V_101 -> V_67 ) ||
F_34 ( V_101 -> V_67 ) ) ) {
int V_148 = F_65 ( V_101 , V_13 , V_30 , V_111 , V_73 ,
& V_94 ) ;
if ( V_148 < 0 )
return V_148 ;
V_144 |= V_148 ;
}
} else {
if ( ! ( V_51 & V_151 ) )
return - V_152 ;
if ( V_46 -> V_153 && V_46 -> V_154 >= V_46 -> V_153 )
return - V_155 ;
if ( ( V_51 & V_147 ) &&
( F_91 ( V_108 ) || F_34 ( V_108 ) ) )
return - V_149 ;
F_90 ( V_46 -> V_72 , L_3 , V_108 , V_13 ) ;
V_101 = F_66 ( sizeof( * V_101 ) , V_97 ) ;
if ( ! V_101 )
return - V_156 ;
V_144 = 1 ;
V_101 -> V_70 = V_70 ;
V_101 -> V_51 = V_74 ;
V_101 -> V_90 = V_101 -> V_87 = V_54 ;
F_92 ( & V_101 -> V_39 ) ;
memcpy ( V_101 -> V_67 , V_108 , V_78 ) ;
F_65 ( V_101 , V_13 , V_30 , V_111 , V_73 , & V_94 ) ;
++ V_46 -> V_154 ;
F_93 ( & V_101 -> V_157 ,
F_57 ( V_46 , V_108 ) ) ;
}
if ( V_144 ) {
if ( V_94 == NULL )
V_94 = F_24 ( V_101 ) ;
F_43 ( V_46 , V_101 , V_94 , V_158 ) ;
}
return 0 ;
}
static void F_94 ( struct V_159 * V_110 )
{
struct V_37 * V_101 = F_95 ( V_110 , struct V_37 , V_160 ) ;
struct V_36 * V_94 , * V_161 ;
F_96 (rd, nd, &f->remotes, list)
F_97 ( V_94 ) ;
F_97 ( V_101 ) ;
}
static void F_98 ( struct V_45 * V_46 , struct V_37 * V_101 )
{
F_90 ( V_46 -> V_72 ,
L_4 , V_101 -> V_67 ) ;
-- V_46 -> V_154 ;
F_43 ( V_46 , V_101 , F_24 ( V_101 ) , V_162 ) ;
F_99 ( & V_101 -> V_157 ) ;
F_100 ( & V_101 -> V_160 , F_94 ) ;
}
static int F_101 ( struct V_14 * V_163 [] , struct V_45 * V_46 ,
union V_1 * V_13 , T_2 * V_30 , T_1 * V_111 , T_1 * V_73 )
{
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
int V_95 ;
if ( V_163 [ V_76 ] ) {
V_95 = F_10 ( V_13 , V_163 [ V_76 ] ) ;
if ( V_95 )
return V_95 ;
} else {
union V_1 * V_103 = & V_46 -> V_47 . V_66 ;
if ( V_103 -> V_4 . V_5 == V_18 ) {
V_13 -> sin . V_9 . V_10 = F_5 ( V_12 ) ;
V_13 -> V_4 . V_5 = V_18 ;
#if F_102 ( V_164 )
} else {
V_13 -> V_7 . V_8 = V_165 ;
V_13 -> V_4 . V_5 = V_6 ;
#endif
}
}
if ( V_163 [ V_82 ] ) {
if ( F_11 ( V_163 [ V_82 ] ) != sizeof( T_2 ) )
return - V_166 ;
* V_30 = F_103 ( V_163 [ V_82 ] ) ;
} else {
* V_30 = V_46 -> V_81 ;
}
if ( V_163 [ V_83 ] ) {
if ( F_11 ( V_163 [ V_83 ] ) != sizeof( T_1 ) )
return - V_166 ;
* V_111 = F_104 ( V_163 [ V_83 ] ) ;
} else {
* V_111 = V_46 -> V_47 . V_48 ;
}
if ( V_163 [ V_85 ] ) {
struct V_100 * V_167 ;
if ( F_11 ( V_163 [ V_85 ] ) != sizeof( T_1 ) )
return - V_166 ;
* V_73 = F_104 ( V_163 [ V_85 ] ) ;
V_167 = F_105 ( V_29 , * V_73 ) ;
if ( ! V_167 )
return - V_168 ;
} else {
* V_73 = 0 ;
}
return 0 ;
}
static int F_106 ( struct V_59 * V_60 , struct V_14 * V_163 [] ,
struct V_100 * V_72 ,
const unsigned char * V_105 , T_9 V_51 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_111 , V_73 ;
int V_95 ;
if ( ! ( V_60 -> V_69 & ( V_169 | V_170 ) ) ) {
F_107 ( L_5 ,
V_60 -> V_69 ) ;
return - V_166 ;
}
if ( V_163 [ V_76 ] == NULL )
return - V_166 ;
V_95 = F_101 ( V_163 , V_46 , & V_13 , & V_30 , & V_111 , & V_73 ) ;
if ( V_95 )
return V_95 ;
if ( V_46 -> V_47 . V_66 . V_4 . V_5 != V_13 . V_4 . V_5 )
return - V_19 ;
F_108 ( & V_46 -> V_171 ) ;
V_95 = F_89 ( V_46 , V_105 , & V_13 , V_60 -> V_69 , V_51 ,
V_30 , V_111 , V_73 , V_60 -> V_74 ) ;
F_109 ( & V_46 -> V_171 ) ;
return V_95 ;
}
static int F_110 ( struct V_59 * V_60 , struct V_14 * V_163 [] ,
struct V_100 * V_72 ,
const unsigned char * V_105 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_101 ;
struct V_36 * V_94 = NULL ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_111 , V_73 ;
int V_95 ;
V_95 = F_101 ( V_163 , V_46 , & V_13 , & V_30 , & V_111 , & V_73 ) ;
if ( V_95 )
return V_95 ;
V_95 = - V_152 ;
F_108 ( & V_46 -> V_171 ) ;
V_101 = F_60 ( V_46 , V_105 ) ;
if ( ! V_101 )
goto V_127;
if ( ! F_3 ( & V_13 ) ) {
V_94 = F_61 ( V_101 , & V_13 , V_30 , V_111 , V_73 ) ;
if ( ! V_94 )
goto V_127;
}
V_95 = 0 ;
if ( V_94 && ! F_111 ( & V_101 -> V_39 ) ) {
F_112 ( & V_94 -> V_41 ) ;
F_43 ( V_46 , V_101 , V_94 , V_162 ) ;
F_113 ( V_94 , V_160 ) ;
goto V_127;
}
F_98 ( V_46 , V_101 ) ;
V_127:
F_109 ( & V_46 -> V_171 ) ;
return V_95 ;
}
static int F_114 ( struct V_20 * V_21 , struct V_172 * V_173 ,
struct V_100 * V_72 , int V_174 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_175 ;
for ( V_175 = 0 ; V_175 < V_176 ; ++ V_175 ) {
struct V_37 * V_101 ;
int V_95 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_94 ;
if ( V_174 < V_173 -> args [ 0 ] )
goto V_177;
F_115 (rd, &f->remotes, list) {
V_95 = F_31 ( V_21 , V_46 , V_101 ,
F_116 ( V_173 -> V_21 ) . V_49 ,
V_173 -> V_58 -> V_178 ,
V_158 ,
V_179 , V_94 ) ;
if ( V_95 < 0 )
goto V_127;
}
V_177:
++ V_174 ;
}
}
V_127:
return V_174 ;
}
static bool F_117 ( struct V_100 * V_72 ,
union V_1 * V_180 , const T_4 * V_181 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_101 ;
V_101 = F_60 ( V_46 , V_181 ) ;
if ( F_118 ( V_101 ) ) {
struct V_36 * V_52 = F_22 ( V_101 ) ;
if ( F_118 ( F_1 ( & V_52 -> V_66 , V_180 ) ) )
return false ;
if ( V_101 -> V_70 & V_182 )
return true ;
if ( F_119 () )
F_120 ( V_72 ,
L_6 ,
V_181 , & V_52 -> V_66 , & V_180 ) ;
V_52 -> V_66 = * V_180 ;
V_101 -> V_90 = V_54 ;
F_43 ( V_46 , V_101 , V_52 , V_158 ) ;
} else {
F_121 ( & V_46 -> V_171 ) ;
if ( F_122 ( V_72 ) )
F_89 ( V_46 , V_181 , V_180 ,
V_170 ,
V_145 | V_151 ,
V_46 -> V_81 ,
V_46 -> V_47 . V_48 ,
0 , V_183 ) ;
F_123 ( & V_46 -> V_171 ) ;
}
return false ;
}
static bool F_124 ( struct V_31 * V_32 , struct V_45 * V_72 )
{
struct V_45 * V_46 ;
if ( F_125 ( & V_72 -> V_184 -> V_185 ) == 1 )
return false ;
F_62 (vxlan, &vn->vxlan_list, next) {
if ( ! F_122 ( V_46 -> V_72 ) || V_46 == V_72 )
continue;
if ( V_46 -> V_184 != V_72 -> V_184 )
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
static void F_126 ( struct V_24 * V_25 )
{
F_127 ( & V_25 -> V_185 ) ;
}
void F_128 ( struct V_24 * V_25 )
{
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_83 ( V_43 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_129 ( & V_25 -> V_185 ) )
return;
F_121 ( & V_32 -> V_186 ) ;
F_99 ( & V_25 -> V_157 ) ;
F_130 ( V_25 -> V_42 -> V_43 , NULL ) ;
F_87 ( V_25 ) ;
F_123 ( & V_32 -> V_186 ) ;
F_131 ( V_187 , & V_25 -> V_188 ) ;
}
static void F_132 ( struct V_189 * V_190 )
{
struct V_45 * V_46 = F_95 ( V_190 , struct V_45 , V_191 ) ;
struct V_24 * V_25 = V_46 -> V_184 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_84 ;
F_133 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_192 V_193 = {
. V_194 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_195 = V_73 ,
} ;
F_134 ( V_43 , & V_193 ) ;
#if F_102 ( V_164 )
} else {
V_196 -> V_197 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_135 ( V_43 ) ;
F_128 ( V_25 ) ;
F_136 ( V_46 -> V_72 ) ;
}
static void F_137 ( struct V_189 * V_190 )
{
struct V_45 * V_46 = F_95 ( V_190 , struct V_45 , V_198 ) ;
struct V_24 * V_25 = V_46 -> V_184 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_84 ;
F_133 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_192 V_193 = {
. V_194 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_195 = V_73 ,
} ;
F_138 ( V_43 , & V_193 ) ;
#if F_102 ( V_164 )
} else {
V_196 -> V_199 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_135 ( V_43 ) ;
F_128 ( V_25 ) ;
F_136 ( V_46 -> V_72 ) ;
}
static int F_139 ( struct V_42 * V_43 , struct V_20 * V_21 )
{
struct V_24 * V_25 ;
struct V_115 * V_200 ;
if ( ! F_140 ( V_21 , V_201 ) )
goto error;
V_200 = (struct V_115 * ) ( F_141 ( V_21 ) + 1 ) ;
if ( V_200 -> V_202 != F_5 ( V_203 ) ||
( V_200 -> V_130 & F_5 ( 0xff ) ) ) {
F_90 ( V_21 -> V_72 , L_7 ,
F_9 ( V_200 -> V_202 ) , F_9 ( V_200 -> V_130 ) ) ;
goto error;
}
if ( F_142 ( V_21 , V_201 , F_143 ( V_204 ) ) )
goto V_205;
V_25 = F_144 ( V_43 ) ;
if ( ! V_25 )
goto V_205;
if ( ( V_21 -> V_206 != V_207 && V_21 -> V_206 != V_208 ) ||
! V_21 -> V_209 )
V_21 -> V_206 = V_210 ;
V_21 -> V_209 = 0 ;
V_25 -> V_211 ( V_25 , V_21 , V_200 -> V_130 ) ;
return 0 ;
V_205:
F_47 ( V_21 ) ;
return 0 ;
error:
return 1 ;
}
static void F_145 ( struct V_24 * V_25 ,
struct V_20 * V_21 , V_17 V_130 )
{
struct V_212 * V_213 = NULL ;
struct V_214 * V_215 = NULL ;
struct V_45 * V_46 ;
struct V_216 * V_217 ;
union V_1 V_218 ;
V_93 V_111 ;
int V_95 = 0 ;
union V_1 * V_66 ;
V_111 = F_9 ( V_130 ) >> 8 ;
V_46 = F_29 ( V_25 , V_111 ) ;
if ( ! V_46 )
goto V_205;
V_66 = & V_46 -> V_47 . V_66 ;
F_146 ( V_21 ) ;
V_21 -> V_219 = F_147 ( V_21 , V_46 -> V_72 ) ;
if ( F_59 ( F_148 ( V_21 ) -> V_220 , V_46 -> V_72 -> V_221 ) )
goto V_205;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_213 = F_149 ( V_21 ) ;
V_218 . sin . V_9 . V_10 = V_213 -> V_218 ;
V_218 . V_4 . V_5 = V_18 ;
#if F_102 ( V_164 )
} else {
V_215 = F_150 ( V_21 ) ;
V_218 . V_7 . V_8 = V_215 -> V_218 ;
V_218 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_46 -> V_51 & V_222 ) &&
F_117 ( V_21 -> V_72 , & V_218 , F_148 ( V_21 ) -> V_220 ) )
goto V_205;
F_151 ( V_21 ) ;
if ( V_215 )
V_95 = F_152 ( V_215 , V_21 ) ;
if ( V_213 )
V_95 = F_153 ( V_213 , V_21 ) ;
if ( F_73 ( V_95 ) ) {
if ( V_223 ) {
if ( V_215 )
F_154 ( L_8 ,
& V_215 -> V_218 ) ;
if ( V_213 )
F_154 ( L_9 ,
& V_213 -> V_218 , V_213 -> V_224 ) ;
}
if ( V_95 > 1 ) {
++ V_46 -> V_72 -> V_217 . V_225 ;
++ V_46 -> V_72 -> V_217 . V_226 ;
goto V_205;
}
}
V_217 = F_155 ( V_46 -> V_72 -> V_227 ) ;
F_156 ( & V_217 -> V_228 ) ;
V_217 -> V_229 ++ ;
V_217 -> V_230 += V_21 -> V_231 ;
F_157 ( & V_217 -> V_228 ) ;
F_158 ( V_21 ) ;
return;
V_205:
F_47 ( V_21 ) ;
}
static int F_159 ( struct V_100 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_232 * V_233 ;
T_4 * V_234 , * V_235 ;
V_17 V_236 , V_237 ;
struct V_238 * V_239 ;
if ( V_72 -> V_51 & V_240 )
goto V_127;
if ( ! F_140 ( V_21 , F_160 ( V_72 ) ) ) {
V_72 -> V_217 . V_241 ++ ;
goto V_127;
}
V_233 = F_161 ( V_21 ) ;
if ( ( V_233 -> V_242 != F_143 ( V_243 ) &&
V_233 -> V_242 != F_143 ( V_244 ) ) ||
V_233 -> V_245 != F_143 ( V_246 ) ||
V_233 -> V_247 != F_143 ( V_248 ) ||
V_233 -> V_249 != V_72 -> V_250 ||
V_233 -> V_251 != 4 )
goto V_127;
V_234 = ( T_4 * ) V_233 + sizeof( struct V_232 ) ;
V_235 = V_234 ;
V_234 += V_72 -> V_250 ;
memcpy ( & V_236 , V_234 , sizeof( V_236 ) ) ;
V_234 += sizeof( V_236 ) ;
V_234 += V_72 -> V_250 ;
memcpy ( & V_237 , V_234 , sizeof( V_237 ) ) ;
if ( F_162 ( V_237 ) ||
F_163 ( V_237 ) )
goto V_127;
V_239 = F_164 ( & V_252 , & V_237 , V_72 ) ;
if ( V_239 ) {
struct V_37 * V_101 ;
struct V_20 * V_253 ;
if ( ! ( V_239 -> V_254 & V_255 ) ) {
F_165 ( V_239 ) ;
goto V_127;
}
V_101 = F_60 ( V_46 , V_239 -> V_256 ) ;
if ( V_101 && F_3 ( & ( F_22 ( V_101 ) -> V_66 ) ) ) {
F_165 ( V_239 ) ;
goto V_127;
}
V_253 = F_166 ( V_257 , V_258 , V_236 , V_72 , V_237 , V_235 ,
V_239 -> V_256 , V_235 ) ;
F_165 ( V_239 ) ;
if ( V_253 == NULL )
goto V_127;
F_146 ( V_253 ) ;
F_167 ( V_253 , F_168 ( V_253 ) ) ;
V_253 -> V_206 = V_207 ;
V_253 -> V_259 = V_260 ;
if ( F_169 ( V_253 ) == V_261 )
V_72 -> V_217 . V_262 ++ ;
} else if ( V_46 -> V_51 & V_263 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_237 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_127:
F_170 ( V_21 ) ;
return V_264 ;
}
static struct V_20 * F_171 ( struct V_20 * V_265 ,
struct V_238 * V_239 , bool V_266 )
{
struct V_100 * V_72 = V_265 -> V_72 ;
struct V_20 * V_253 ;
struct V_267 * V_268 , * V_269 ;
struct V_214 * V_270 ;
T_4 * V_271 ;
int V_272 = 8 ;
int V_273 ;
int V_274 , V_231 ;
if ( V_72 == NULL )
return NULL ;
V_231 = F_172 ( V_72 ) + sizeof( struct V_214 ) +
sizeof( * V_269 ) + V_272 + V_72 -> V_275 ;
V_253 = F_173 ( V_231 , V_97 ) ;
if ( V_253 == NULL )
return NULL ;
V_253 -> V_219 = F_143 ( V_276 ) ;
V_253 -> V_72 = V_72 ;
F_174 ( V_253 , F_172 ( V_265 -> V_72 ) ) ;
F_175 ( V_253 , sizeof( struct V_118 ) ) ;
F_176 ( V_253 , 0 ) ;
V_268 = (struct V_267 * ) F_177 ( V_265 ) ;
V_271 = F_148 ( V_265 ) -> V_220 ;
V_273 = V_265 -> V_231 - F_178 ( V_265 ) - sizeof( * V_268 ) ;
for ( V_274 = 0 ; V_274 < V_273 - 1 ; V_274 += ( V_268 -> V_277 [ V_274 + 1 ] << 3 ) ) {
if ( V_268 -> V_277 [ V_274 ] == V_278 ) {
V_271 = V_268 -> V_277 + V_274 + sizeof( struct V_279 ) ;
break;
}
}
F_179 ( F_148 ( V_253 ) -> V_280 , V_271 ) ;
F_179 ( F_148 ( V_253 ) -> V_220 , V_239 -> V_256 ) ;
F_148 ( V_253 ) -> V_131 = F_143 ( V_276 ) ;
V_253 -> V_219 = F_143 ( V_276 ) ;
F_180 ( V_253 , sizeof( struct V_118 ) ) ;
F_181 ( V_253 , 0 ) ;
F_182 ( V_253 , sizeof( struct V_214 ) ) ;
V_270 = F_150 ( V_253 ) ;
memset ( V_270 , 0 , sizeof( struct V_214 ) ) ;
V_270 -> V_281 = 6 ;
V_270 -> V_282 = F_150 ( V_265 ) -> V_282 ;
V_270 -> V_283 = V_284 ;
V_270 -> V_285 = 255 ;
V_270 -> V_271 = F_150 ( V_265 ) -> V_218 ;
V_270 -> V_218 = * (struct V_16 * ) V_239 -> V_286 ;
F_180 ( V_253 , sizeof( struct V_214 ) ) ;
F_183 ( V_253 , 0 ) ;
V_269 = (struct V_267 * ) F_182 ( V_253 , sizeof( * V_269 ) + V_272 ) ;
memset ( V_269 , 0 , sizeof( * V_269 ) + V_272 ) ;
V_269 -> V_287 . V_288 = V_289 ;
V_269 -> V_287 . V_290 = V_266 ;
V_269 -> V_287 . V_291 = 1 ;
V_269 -> V_287 . V_292 = 1 ;
V_269 -> V_293 = V_268 -> V_293 ;
F_179 ( & V_269 -> V_277 [ 2 ] , V_239 -> V_256 ) ;
V_269 -> V_277 [ 0 ] = V_294 ;
V_269 -> V_277 [ 1 ] = V_272 >> 3 ;
V_269 -> V_287 . V_295 = F_184 ( & V_270 -> V_218 ,
& V_270 -> V_271 , sizeof( * V_269 ) + V_272 , V_284 ,
F_185 ( V_269 , sizeof( * V_269 ) + V_272 , 0 ) ) ;
V_270 -> V_296 = F_143 ( sizeof( * V_269 ) + V_272 ) ;
F_175 ( V_253 , sizeof( struct V_214 ) ) ;
V_253 -> V_206 = V_207 ;
return V_253 ;
}
static int F_186 ( struct V_100 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_267 * V_297 ;
const struct V_214 * V_212 ;
const struct V_16 * V_218 , * V_271 ;
struct V_238 * V_239 ;
struct V_298 * V_299 ;
V_299 = F_187 ( V_72 ) ;
if ( ! V_299 )
goto V_127;
if ( ! F_140 ( V_21 , V_21 -> V_231 ) )
goto V_127;
V_212 = F_150 ( V_21 ) ;
V_218 = & V_212 -> V_218 ;
V_271 = & V_212 -> V_271 ;
V_297 = (struct V_267 * ) F_177 ( V_21 ) ;
if ( V_297 -> V_287 . V_300 != 0 ||
V_297 -> V_287 . V_288 != V_301 )
goto V_127;
if ( F_188 ( V_271 ) ||
F_7 ( & V_297 -> V_293 ) )
goto V_127;
V_239 = F_164 ( V_196 -> V_302 , & V_297 -> V_293 , V_72 ) ;
if ( V_239 ) {
struct V_37 * V_101 ;
struct V_20 * V_253 ;
if ( ! ( V_239 -> V_254 & V_255 ) ) {
F_165 ( V_239 ) ;
goto V_127;
}
V_101 = F_60 ( V_46 , V_239 -> V_256 ) ;
if ( V_101 && F_3 ( & ( F_22 ( V_101 ) -> V_66 ) ) ) {
F_165 ( V_239 ) ;
goto V_127;
}
V_253 = F_171 ( V_21 , V_239 ,
! ! ( V_101 ? V_101 -> V_51 & V_303 : 0 ) ) ;
F_165 ( V_239 ) ;
if ( V_253 == NULL )
goto V_127;
if ( F_169 ( V_253 ) == V_261 )
V_72 -> V_217 . V_262 ++ ;
} else if ( V_46 -> V_51 & V_263 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_297 -> V_293 ,
. V_4 . V_5 = V_6 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_127:
F_170 ( V_21 ) ;
return V_264 ;
}
static bool F_189 ( struct V_100 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_238 * V_239 ;
if ( F_91 ( F_148 ( V_21 ) -> V_280 ) )
return false ;
V_239 = NULL ;
switch ( F_21 ( F_148 ( V_21 ) -> V_131 ) ) {
case V_246 :
{
struct V_212 * V_304 ;
if ( ! F_140 ( V_21 , sizeof( struct V_212 ) ) )
return false ;
V_304 = F_149 ( V_21 ) ;
V_239 = F_164 ( & V_252 , & V_304 -> V_271 , V_72 ) ;
if ( ! V_239 && ( V_46 -> V_51 & V_263 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_304 -> V_271 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
return false ;
}
break;
}
#if F_102 ( V_164 )
case V_276 :
{
struct V_214 * V_270 ;
if ( ! F_140 ( V_21 , sizeof( struct V_214 ) ) )
return false ;
V_270 = F_150 ( V_21 ) ;
V_239 = F_164 ( V_196 -> V_302 , & V_270 -> V_271 , V_72 ) ;
if ( ! V_239 && ( V_46 -> V_51 & V_263 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_270 -> V_271 ,
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
if ( V_239 ) {
bool V_305 ;
V_305 = ! F_59 ( F_148 ( V_21 ) -> V_280 , V_239 -> V_256 ) ;
if ( V_305 ) {
memcpy ( F_148 ( V_21 ) -> V_220 , F_148 ( V_21 ) -> V_280 ,
V_72 -> V_250 ) ;
memcpy ( F_148 ( V_21 ) -> V_280 , V_239 -> V_256 , V_72 -> V_250 ) ;
}
F_165 ( V_239 ) ;
return V_305 ;
}
return false ;
}
T_2 F_190 ( T_7 V_306 , T_7 V_307 , struct V_20 * V_21 )
{
unsigned int V_308 = ( V_307 - V_306 ) + 1 ;
T_1 V_309 ;
V_309 = F_191 ( V_21 ) ;
if ( ! V_309 )
V_309 = F_192 ( V_21 -> V_129 , 2 * V_78 ,
( V_310 T_1 ) V_21 -> V_219 ) ;
return F_143 ( ( ( ( T_5 ) V_309 * V_308 ) >> 32 ) + V_306 ) ;
}
static int F_193 ( struct V_20 * V_21 )
{
if ( F_194 ( V_21 ) ) {
int V_95 = F_195 ( V_21 , V_97 ) ;
if ( F_73 ( V_95 ) )
return V_95 ;
F_196 ( V_21 ) -> V_311 |= V_312 ;
} else if ( V_21 -> V_206 != V_208 )
V_21 -> V_206 = V_210 ;
return 0 ;
}
static int F_197 ( struct V_24 * V_25 ,
struct V_313 * V_314 , struct V_20 * V_21 ,
struct V_100 * V_72 , struct V_16 * V_218 ,
struct V_16 * V_271 , T_8 V_315 , T_8 V_316 ,
T_2 V_317 , T_2 V_81 , V_17 V_111 )
{
struct V_214 * V_318 ;
struct V_115 * V_200 ;
struct V_319 * V_320 ;
int V_321 ;
int V_95 ;
if ( ! V_21 -> V_209 ) {
F_198 ( V_21 ) ;
V_21 -> V_209 = 1 ;
}
F_199 ( V_21 , false ) ;
V_321 = F_172 ( V_314 -> V_72 ) + V_314 -> V_322
+ V_201 + sizeof( struct V_214 )
+ ( F_200 ( V_21 ) ? V_323 : 0 ) ;
V_95 = F_201 ( V_21 , V_321 ) ;
if ( F_73 ( V_95 ) )
return V_95 ;
if ( F_200 ( V_21 ) ) {
if ( F_46 ( ! F_202 ( V_21 ,
V_21 -> V_324 ,
F_203 ( V_21 ) ) ) )
return - V_156 ;
V_21 -> V_325 = 0 ;
}
V_200 = (struct V_115 * ) F_204 ( V_21 , sizeof( * V_200 ) ) ;
V_200 -> V_202 = F_5 ( V_203 ) ;
V_200 -> V_130 = V_111 ;
F_204 ( V_21 , sizeof( * V_320 ) ) ;
F_205 ( V_21 ) ;
V_320 = F_141 ( V_21 ) ;
V_320 -> V_326 = V_81 ;
V_320 -> V_327 = V_317 ;
V_320 -> V_231 = F_143 ( V_21 -> V_231 ) ;
V_320 -> V_328 = 0 ;
memset ( & ( F_206 ( V_21 ) -> V_277 ) , 0 , sizeof( F_206 ( V_21 ) -> V_277 ) ) ;
F_206 ( V_21 ) -> V_51 &= ~ ( V_329 | V_330 |
V_331 ) ;
F_207 ( V_21 , V_314 ) ;
if ( ! F_194 ( V_21 ) && ! ( V_314 -> V_72 -> V_332 & V_333 ) ) {
T_10 V_334 = F_208 ( V_21 , 0 , V_21 -> V_231 , 0 ) ;
V_21 -> V_206 = V_207 ;
V_320 -> V_328 = F_184 ( V_218 , V_271 , V_21 -> V_231 ,
V_335 , V_334 ) ;
if ( V_320 -> V_328 == 0 )
V_320 -> V_328 = V_336 ;
} else {
V_21 -> V_206 = V_208 ;
V_21 -> V_337 = F_177 ( V_21 ) - V_21 -> V_110 ;
V_21 -> V_338 = F_209 ( struct V_319 , V_328 ) ;
V_320 -> V_328 = ~ F_184 ( V_218 , V_271 ,
V_21 -> V_231 , V_335 , 0 ) ;
}
F_204 ( V_21 , sizeof( * V_318 ) ) ;
F_151 ( V_21 ) ;
V_318 = F_150 ( V_21 ) ;
V_318 -> V_281 = 6 ;
V_318 -> V_282 = V_315 ;
V_318 -> V_339 [ 0 ] = 0 ;
V_318 -> V_339 [ 1 ] = 0 ;
V_318 -> V_339 [ 2 ] = 0 ;
V_318 -> V_296 = F_143 ( V_21 -> V_231 ) ;
V_318 -> V_283 = V_335 ;
V_318 -> V_285 = V_316 ;
V_318 -> V_271 = * V_271 ;
V_318 -> V_218 = * V_218 ;
V_95 = F_193 ( V_21 ) ;
if ( V_95 )
return V_95 ;
F_210 ( V_21 , V_72 ) ;
return 0 ;
}
int F_211 ( struct V_24 * V_25 ,
struct V_340 * V_341 , struct V_20 * V_21 ,
V_17 V_342 , V_17 V_314 , T_8 V_224 , T_8 V_316 , T_2 V_343 ,
T_2 V_317 , T_2 V_81 , V_17 V_111 )
{
struct V_115 * V_200 ;
struct V_319 * V_320 ;
int V_321 ;
int V_95 ;
if ( ! V_21 -> V_209 ) {
F_198 ( V_21 ) ;
V_21 -> V_209 = 1 ;
}
V_321 = F_172 ( V_341 -> V_314 . V_72 ) + V_341 -> V_314 . V_322
+ V_201 + sizeof( struct V_212 )
+ ( F_200 ( V_21 ) ? V_323 : 0 ) ;
V_95 = F_201 ( V_21 , V_321 ) ;
if ( F_73 ( V_95 ) )
return V_95 ;
if ( F_200 ( V_21 ) ) {
if ( F_46 ( ! F_202 ( V_21 ,
V_21 -> V_324 ,
F_203 ( V_21 ) ) ) )
return - V_156 ;
V_21 -> V_325 = 0 ;
}
V_200 = (struct V_115 * ) F_204 ( V_21 , sizeof( * V_200 ) ) ;
V_200 -> V_202 = F_5 ( V_203 ) ;
V_200 -> V_130 = V_111 ;
F_204 ( V_21 , sizeof( * V_320 ) ) ;
F_205 ( V_21 ) ;
V_320 = F_141 ( V_21 ) ;
V_320 -> V_326 = V_81 ;
V_320 -> V_327 = V_317 ;
V_320 -> V_231 = F_143 ( V_21 -> V_231 ) ;
V_320 -> V_328 = 0 ;
V_95 = F_193 ( V_21 ) ;
if ( V_95 )
return V_95 ;
return F_212 ( V_25 -> V_42 -> V_43 , V_341 , V_21 , V_342 , V_314 , V_335 ,
V_224 , V_316 , V_343 , false ) ;
}
static void F_213 ( struct V_20 * V_21 , struct V_45 * V_344 ,
struct V_45 * V_345 )
{
struct V_216 * V_346 , * V_347 ;
union V_1 V_348 ;
union V_1 * V_66 = & V_345 -> V_47 . V_66 ;
V_346 = F_155 ( V_344 -> V_72 -> V_227 ) ;
V_347 = F_155 ( V_345 -> V_72 -> V_227 ) ;
V_21 -> V_259 = V_260 ;
V_21 -> V_209 = 0 ;
V_21 -> V_72 = V_345 -> V_72 ;
F_167 ( V_21 , F_168 ( V_21 ) ) ;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_348 . sin . V_9 . V_10 = F_5 ( V_349 ) ;
V_348 . V_4 . V_5 = V_18 ;
#if F_102 ( V_164 )
} else {
V_348 . V_7 . V_8 = V_350 ;
V_348 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_345 -> V_51 & V_222 )
F_117 ( V_21 -> V_72 , & V_348 , F_148 ( V_21 ) -> V_220 ) ;
F_156 ( & V_346 -> V_228 ) ;
V_346 -> V_351 ++ ;
V_346 -> V_352 += V_21 -> V_231 ;
F_157 ( & V_346 -> V_228 ) ;
if ( F_158 ( V_21 ) == V_353 ) {
F_156 ( & V_347 -> V_228 ) ;
V_347 -> V_229 ++ ;
V_347 -> V_230 += V_21 -> V_231 ;
F_157 ( & V_347 -> V_228 ) ;
} else {
V_21 -> V_72 -> V_217 . V_262 ++ ;
}
}
static void F_214 ( struct V_20 * V_21 , struct V_100 * V_72 ,
struct V_36 * V_52 , bool V_354 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_340 * V_341 = NULL ;
const struct V_212 * V_355 ;
struct V_356 V_357 ;
union V_1 * V_314 ;
T_2 V_317 = 0 , V_81 ;
T_1 V_111 ;
T_2 V_343 = 0 ;
T_8 V_224 , V_316 ;
int V_95 ;
V_81 = V_52 -> V_80 ? V_52 -> V_80 : V_46 -> V_81 ;
V_111 = V_52 -> V_48 ;
V_314 = & V_52 -> V_66 ;
if ( F_3 ( V_314 ) ) {
if ( V_354 ) {
F_213 ( V_21 , V_46 , V_46 ) ;
return;
}
goto V_205;
}
V_355 = F_149 ( V_21 ) ;
V_316 = V_46 -> V_316 ;
if ( ! V_316 && F_6 ( V_314 ) )
V_316 = 1 ;
V_224 = V_46 -> V_224 ;
if ( V_224 == 1 )
V_224 = F_215 ( V_355 , V_21 ) ;
V_317 = F_190 ( V_46 -> V_306 , V_46 -> V_307 , V_21 ) ;
if ( V_314 -> V_4 . V_5 == V_18 ) {
memset ( & V_357 , 0 , sizeof( V_357 ) ) ;
V_357 . V_358 = V_52 -> V_84 ;
V_357 . V_359 = F_216 ( V_224 ) ;
V_357 . V_271 = V_314 -> sin . V_9 . V_10 ;
V_357 . V_218 = V_46 -> V_218 . sin . V_9 . V_10 ;
V_341 = F_217 ( F_44 ( V_72 ) , & V_357 ) ;
if ( F_218 ( V_341 ) ) {
F_90 ( V_72 , L_10 ,
& V_314 -> sin . V_9 . V_10 ) ;
V_72 -> V_217 . V_360 ++ ;
goto V_361;
}
if ( V_341 -> V_314 . V_72 == V_72 ) {
F_90 ( V_72 , L_11 ,
& V_314 -> sin . V_9 . V_10 ) ;
V_72 -> V_217 . V_362 ++ ;
goto V_363;
}
if ( V_341 -> V_364 & V_365 &&
! ( V_341 -> V_364 & ( V_366 | V_367 ) ) ) {
struct V_45 * V_345 ;
F_219 ( V_341 ) ;
V_345 = F_30 ( F_44 ( V_72 ) , V_111 , V_81 ) ;
if ( ! V_345 )
goto V_361;
F_213 ( V_21 , V_46 , V_345 ) ;
return;
}
V_224 = F_220 ( V_224 , V_355 , V_21 ) ;
V_316 = V_316 ? : F_221 ( & V_341 -> V_314 ) ;
V_95 = F_211 ( V_46 -> V_184 , V_341 , V_21 ,
V_357 . V_218 , V_314 -> sin . V_9 . V_10 ,
V_224 , V_316 , V_343 , V_317 , V_81 ,
F_5 ( V_111 << 8 ) ) ;
if ( V_95 < 0 )
goto V_363;
F_222 ( V_95 , & V_72 -> V_217 , V_72 -> V_227 ) ;
#if F_102 ( V_164 )
} else {
struct V_42 * V_43 = V_46 -> V_184 -> V_42 -> V_43 ;
struct V_313 * V_368 ;
struct V_369 V_370 ;
T_1 V_51 ;
memset ( & V_370 , 0 , sizeof( V_370 ) ) ;
V_370 . V_371 = V_52 -> V_84 ;
V_370 . V_271 = V_314 -> V_7 . V_8 ;
V_370 . V_218 = V_46 -> V_218 . V_7 . V_8 ;
V_370 . V_372 = V_335 ;
if ( V_196 -> V_373 ( V_43 , & V_368 , & V_370 ) ) {
F_90 ( V_72 , L_12 ,
& V_314 -> V_7 . V_8 ) ;
V_72 -> V_217 . V_360 ++ ;
goto V_361;
}
if ( V_368 -> V_72 == V_72 ) {
F_90 ( V_72 , L_13 ,
& V_314 -> V_7 . V_8 ) ;
F_223 ( V_368 ) ;
V_72 -> V_217 . V_362 ++ ;
goto V_361;
}
V_51 = ( (struct V_374 * ) V_368 ) -> V_375 ;
if ( V_51 & V_376 &&
! ( V_51 & ( V_366 | V_367 ) ) ) {
struct V_45 * V_345 ;
F_223 ( V_368 ) ;
V_345 = F_30 ( F_44 ( V_72 ) , V_111 , V_81 ) ;
if ( ! V_345 )
goto V_361;
F_213 ( V_21 , V_46 , V_345 ) ;
return;
}
V_316 = V_316 ? : F_224 ( V_368 ) ;
V_95 = F_197 ( V_46 -> V_184 , V_368 , V_21 ,
V_72 , & V_370 . V_218 , & V_370 . V_271 , 0 , V_316 ,
V_317 , V_81 , F_5 ( V_111 << 8 ) ) ;
#endif
}
return;
V_205:
V_72 -> V_217 . V_241 ++ ;
goto V_377;
V_363:
F_219 ( V_341 ) ;
V_361:
V_72 -> V_217 . V_378 ++ ;
V_377:
F_225 ( V_21 ) ;
}
static T_11 F_226 ( struct V_20 * V_21 , struct V_100 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_118 * V_379 ;
bool V_354 = false ;
struct V_36 * V_52 , * V_380 = NULL ;
struct V_37 * V_101 ;
F_146 ( V_21 ) ;
V_379 = F_148 ( V_21 ) ;
if ( ( V_46 -> V_51 & V_381 ) ) {
if ( F_21 ( V_379 -> V_131 ) == V_258 )
return F_159 ( V_72 , V_21 ) ;
#if F_102 ( V_164 )
else if ( F_21 ( V_379 -> V_131 ) == V_276 &&
V_21 -> V_231 >= sizeof( struct V_214 ) + sizeof( struct V_267 ) &&
F_150 ( V_21 ) -> V_283 == V_284 ) {
struct V_267 * V_297 ;
V_297 = (struct V_267 * ) F_177 ( V_21 ) ;
if ( V_297 -> V_287 . V_300 == 0 &&
V_297 -> V_287 . V_288 == V_301 )
return F_186 ( V_72 , V_21 ) ;
}
#endif
}
V_101 = F_60 ( V_46 , V_379 -> V_280 ) ;
V_354 = false ;
if ( V_101 && ( V_101 -> V_51 & V_303 ) && ( V_46 -> V_51 & V_382 ) &&
( F_21 ( V_379 -> V_131 ) == V_246 ||
F_21 ( V_379 -> V_131 ) == V_276 ) ) {
V_354 = F_189 ( V_72 , V_21 ) ;
if ( V_354 )
V_101 = F_60 ( V_46 , V_379 -> V_280 ) ;
}
if ( V_101 == NULL ) {
V_101 = F_60 ( V_46 , V_383 ) ;
if ( V_101 == NULL ) {
if ( ( V_46 -> V_51 & V_384 ) &&
! F_91 ( V_379 -> V_280 ) )
F_52 ( V_46 , V_379 -> V_280 ) ;
V_72 -> V_217 . V_241 ++ ;
F_47 ( V_21 ) ;
return V_264 ;
}
}
F_115 (rdst, &f->remotes, list) {
struct V_20 * V_385 ;
if ( ! V_380 ) {
V_380 = V_52 ;
continue;
}
V_385 = F_227 ( V_21 , V_97 ) ;
if ( V_385 )
F_214 ( V_385 , V_72 , V_52 , V_354 ) ;
}
if ( V_380 )
F_214 ( V_21 , V_72 , V_380 , V_354 ) ;
else
F_47 ( V_21 ) ;
return V_264 ;
}
static void F_228 ( unsigned long V_386 )
{
struct V_45 * V_46 = (struct V_45 * ) V_386 ;
unsigned long V_387 = V_54 + V_388 ;
unsigned int V_175 ;
if ( ! F_122 ( V_46 -> V_72 ) )
return;
F_108 ( & V_46 -> V_171 ) ;
for ( V_175 = 0 ; V_175 < V_176 ; ++ V_175 ) {
struct V_389 * V_113 , * V_239 ;
F_229 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_101
= F_95 ( V_113 , struct V_37 , V_157 ) ;
unsigned long V_390 ;
if ( V_101 -> V_70 & V_169 )
continue;
V_390 = V_101 -> V_87 + V_46 -> V_391 * V_392 ;
if ( F_230 ( V_390 , V_54 ) ) {
F_90 ( V_46 -> V_72 ,
L_14 ,
V_101 -> V_67 ) ;
V_101 -> V_70 = V_102 ;
F_98 ( V_46 , V_101 ) ;
} else if ( F_231 ( V_390 , V_387 ) )
V_387 = V_390 ;
}
}
F_109 ( & V_46 -> V_171 ) ;
F_232 ( & V_46 -> V_393 , V_387 ) ;
}
static void F_233 ( struct V_24 * V_25 , struct V_45 * V_46 )
{
V_93 V_111 = V_46 -> V_47 . V_48 ;
V_46 -> V_184 = V_25 ;
F_93 ( & V_46 -> V_157 , F_17 ( V_25 , V_111 ) ) ;
}
static int F_234 ( struct V_100 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_24 * V_25 ;
V_72 -> V_227 = F_235 ( struct V_216 ) ;
if ( ! V_72 -> V_227 )
return - V_156 ;
F_121 ( & V_32 -> V_186 ) ;
V_25 = F_26 ( F_44 ( V_72 ) , V_46 -> V_81 ) ;
if ( V_25 ) {
F_127 ( & V_25 -> V_185 ) ;
F_233 ( V_25 , V_46 ) ;
} else {
F_236 ( V_72 ) ;
F_131 ( V_187 , & V_46 -> V_394 ) ;
}
F_123 ( & V_32 -> V_186 ) ;
return 0 ;
}
static void F_237 ( struct V_45 * V_46 )
{
struct V_37 * V_101 ;
F_108 ( & V_46 -> V_171 ) ;
V_101 = F_58 ( V_46 , V_383 ) ;
if ( V_101 )
F_98 ( V_46 , V_101 ) ;
F_109 ( & V_46 -> V_171 ) ;
}
static void F_238 ( struct V_100 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_184 ;
F_237 ( V_46 ) ;
if ( V_25 )
F_128 ( V_25 ) ;
F_239 ( V_72 -> V_227 ) ;
}
static int F_240 ( struct V_100 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_184 ;
if ( ! V_25 )
return - V_395 ;
if ( F_6 ( & V_46 -> V_47 . V_66 ) ) {
F_126 ( V_25 ) ;
F_236 ( V_72 ) ;
F_131 ( V_187 , & V_46 -> V_191 ) ;
}
if ( V_46 -> V_391 )
F_232 ( & V_46 -> V_393 , V_54 + V_388 ) ;
return 0 ;
}
static void F_241 ( struct V_45 * V_46 )
{
unsigned int V_175 ;
F_108 ( & V_46 -> V_171 ) ;
for ( V_175 = 0 ; V_175 < V_176 ; ++ V_175 ) {
struct V_389 * V_113 , * V_239 ;
F_229 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_101
= F_95 ( V_113 , struct V_37 , V_157 ) ;
if ( ! F_34 ( V_101 -> V_67 ) )
F_98 ( V_46 , V_101 ) ;
}
}
F_109 ( & V_46 -> V_171 ) ;
}
static int F_242 ( struct V_100 * V_72 )
{
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_184 ;
if ( V_25 && F_6 ( & V_46 -> V_47 . V_66 ) &&
! F_124 ( V_32 , V_46 ) ) {
F_126 ( V_25 ) ;
F_236 ( V_72 ) ;
F_131 ( V_187 , & V_46 -> V_198 ) ;
}
F_243 ( & V_46 -> V_393 ) ;
F_241 ( V_46 ) ;
return 0 ;
}
static void F_244 ( struct V_100 * V_72 )
{
}
static int F_245 ( struct V_100 * V_72 , int V_396 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_314 = & V_46 -> V_47 ;
struct V_100 * V_397 ;
int V_398 ;
V_397 = F_105 ( F_44 ( V_72 ) , V_314 -> V_84 ) ;
if ( V_397 == NULL )
return F_246 ( V_72 , V_396 ) ;
if ( V_314 -> V_66 . V_4 . V_5 == V_6 )
V_398 = V_397 -> V_399 - V_400 ;
else
V_398 = V_397 -> V_399 - V_401 ;
if ( V_396 < 68 || V_396 > V_398 )
return - V_166 ;
V_72 -> V_399 = V_396 ;
return 0 ;
}
void F_247 ( struct V_100 * V_72 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_44 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_6 V_5 ;
T_2 V_30 ;
unsigned int V_274 ;
F_121 ( & V_32 -> V_186 ) ;
for ( V_274 = 0 ; V_274 < V_402 ; ++ V_274 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_42 -> V_43 ) -> V_44 ;
V_5 = V_25 -> V_42 -> V_43 -> V_139 ;
V_72 -> V_141 -> V_142 ( V_72 , V_5 ,
V_30 ) ;
}
}
F_123 ( & V_32 -> V_186 ) ;
}
static void F_248 ( struct V_100 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_175 ;
int V_403 , V_404 ;
F_249 ( V_72 ) ;
F_250 ( V_72 ) ;
if ( V_46 -> V_47 . V_66 . V_4 . V_5 == V_6 )
V_72 -> V_405 = V_406 + V_400 ;
else
V_72 -> V_405 = V_406 + V_401 ;
V_72 -> V_141 = & V_407 ;
V_72 -> V_408 = V_409 ;
F_251 ( V_72 , & V_410 ) ;
V_72 -> V_411 = 0 ;
V_72 -> V_332 |= V_412 ;
V_72 -> V_332 |= V_413 ;
V_72 -> V_332 |= V_414 | V_415 ;
V_72 -> V_332 |= V_416 ;
V_72 -> V_332 |= V_417 ;
V_72 -> V_418 = V_72 -> V_332 ;
V_72 -> V_332 |= V_419 | V_420 ;
V_72 -> V_421 |= V_414 | V_415 | V_416 ;
V_72 -> V_421 |= V_417 ;
V_72 -> V_421 |= V_419 | V_420 ;
V_72 -> V_422 &= ~ V_423 ;
V_72 -> V_422 |= V_424 ;
F_92 ( & V_46 -> V_40 ) ;
F_252 ( & V_46 -> V_171 ) ;
F_253 ( & V_46 -> V_191 , F_132 ) ;
F_253 ( & V_46 -> V_198 , F_137 ) ;
F_253 ( & V_46 -> V_394 , V_425 ) ;
F_254 ( & V_46 -> V_393 ) ;
V_46 -> V_393 . V_426 = F_228 ;
V_46 -> V_393 . V_129 = ( unsigned long ) V_46 ;
F_255 ( F_44 ( V_72 ) , & V_403 , & V_404 ) ;
V_46 -> V_306 = V_403 ;
V_46 -> V_307 = V_404 ;
V_46 -> V_81 = F_143 ( V_427 ) ;
V_46 -> V_72 = V_72 ;
for ( V_175 = 0 ; V_175 < V_176 ; ++ V_175 )
F_256 ( & V_46 -> V_109 [ V_175 ] ) ;
}
static int F_257 ( struct V_14 * V_163 [] , struct V_14 * V_129 [] )
{
if ( V_163 [ V_428 ] ) {
if ( F_11 ( V_163 [ V_428 ] ) != V_78 ) {
F_258 ( L_15 ) ;
return - V_166 ;
}
if ( ! F_259 ( F_260 ( V_163 [ V_428 ] ) ) ) {
F_258 ( L_16 ) ;
return - V_168 ;
}
}
if ( ! V_129 )
return - V_166 ;
if ( V_129 [ V_429 ] ) {
V_93 V_26 = F_104 ( V_129 [ V_429 ] ) ;
if ( V_26 >= V_430 )
return - V_431 ;
}
if ( V_129 [ V_432 ] ) {
const struct V_433 * V_113
= F_260 ( V_129 [ V_432 ] ) ;
if ( F_21 ( V_113 -> V_404 ) < F_21 ( V_113 -> V_403 ) ) {
F_258 ( L_17 ,
F_21 ( V_113 -> V_403 ) , F_21 ( V_113 -> V_404 ) ) ;
return - V_166 ;
}
}
return 0 ;
}
static void F_261 ( struct V_100 * V_434 ,
struct V_435 * V_436 )
{
F_262 ( V_436 -> V_281 , V_437 , sizeof( V_436 -> V_281 ) ) ;
F_262 ( V_436 -> V_438 , L_18 , sizeof( V_436 -> V_438 ) ) ;
}
static void F_263 ( struct V_189 * V_190 )
{
struct V_24 * V_25 = F_95 ( V_190 , struct V_24 , V_188 ) ;
F_264 ( V_25 -> V_42 -> V_43 ) ;
F_113 ( V_25 , V_160 ) ;
}
static struct V_439 * F_265 ( struct V_29 * V_29 , T_2 V_30 )
{
struct V_42 * V_43 ;
struct V_439 * V_42 ;
struct V_440 V_1 = {
. V_441 = V_6 ,
. V_442 = V_30 ,
} ;
int V_148 , V_443 = 1 ;
V_148 = F_266 ( V_6 , V_444 , V_335 , & V_42 ) ;
if ( V_148 < 0 ) {
F_258 ( L_19 ) ;
return F_267 ( V_148 ) ;
}
V_43 = V_42 -> V_43 ;
F_268 ( V_43 , V_29 ) ;
F_269 ( V_42 , V_445 , V_446 ,
( char * ) & V_443 , sizeof( V_443 ) ) ;
V_148 = F_270 ( V_42 , (struct V_447 * ) & V_1 ,
sizeof( struct V_440 ) ) ;
if ( V_148 < 0 ) {
F_258 ( L_20 ,
& V_1 . V_8 , F_21 ( V_1 . V_442 ) , V_148 ) ;
F_264 ( V_43 ) ;
return F_267 ( V_148 ) ;
}
F_271 ( ! V_196 ) ;
F_28 ( V_43 ) -> V_448 = 0 ;
return V_42 ;
}
static struct V_439 * F_265 ( struct V_29 * V_29 , T_2 V_30 )
{
return F_267 ( - V_449 ) ;
}
static struct V_439 * F_272 ( struct V_29 * V_29 , T_2 V_30 )
{
struct V_42 * V_43 ;
struct V_439 * V_42 ;
struct V_450 V_1 = {
. V_451 = V_18 ,
. V_9 . V_10 = F_5 ( V_12 ) ,
. V_452 = V_30 ,
} ;
int V_148 ;
V_148 = F_266 ( V_18 , V_444 , V_335 , & V_42 ) ;
if ( V_148 < 0 ) {
F_258 ( L_21 ) ;
return F_267 ( V_148 ) ;
}
V_43 = V_42 -> V_43 ;
F_268 ( V_43 , V_29 ) ;
V_148 = F_270 ( V_42 , (struct V_447 * ) & V_1 ,
sizeof( V_1 ) ) ;
if ( V_148 < 0 ) {
F_258 ( L_22 ,
& V_1 . V_9 , F_21 ( V_1 . V_452 ) , V_148 ) ;
F_264 ( V_43 ) ;
return F_267 ( V_148 ) ;
}
F_28 ( V_43 ) -> V_448 = 0 ;
return V_42 ;
}
static struct V_24 * F_273 ( struct V_29 * V_29 , T_2 V_30 ,
T_12 * V_211 , void * V_129 , bool V_453 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_439 * V_42 ;
struct V_42 * V_43 ;
unsigned int V_175 ;
V_25 = F_274 ( sizeof( * V_25 ) , V_454 ) ;
if ( ! V_25 )
return F_267 ( - V_156 ) ;
for ( V_175 = 0 ; V_175 < V_455 ; ++ V_175 )
F_256 ( & V_25 -> V_27 [ V_175 ] ) ;
F_253 ( & V_25 -> V_188 , F_263 ) ;
if ( V_453 )
V_42 = F_265 ( V_29 , V_30 ) ;
else
V_42 = F_272 ( V_29 , V_30 ) ;
if ( F_218 ( V_42 ) ) {
F_97 ( V_25 ) ;
return F_275 ( V_42 ) ;
}
V_25 -> V_42 = V_42 ;
V_43 = V_42 -> V_43 ;
F_276 ( & V_25 -> V_185 , 1 ) ;
V_25 -> V_211 = V_211 ;
V_25 -> V_129 = V_129 ;
F_130 ( V_25 -> V_42 -> V_43 , V_25 ) ;
V_25 -> V_140 . V_30 = V_30 ;
V_25 -> V_140 . V_133 . V_134 = F_68 ;
V_25 -> V_140 . V_133 . V_138 = F_80 ;
F_121 ( & V_32 -> V_186 ) ;
F_93 ( & V_25 -> V_157 , F_19 ( V_29 , V_30 ) ) ;
F_82 ( V_25 ) ;
F_123 ( & V_32 -> V_186 ) ;
F_277 ( V_43 ) -> V_456 = 1 ;
F_277 ( V_43 ) -> V_457 = F_139 ;
#if F_102 ( V_164 )
if ( V_453 )
V_196 -> V_458 () ;
else
#endif
F_278 () ;
return V_25 ;
}
struct V_24 * F_279 ( struct V_29 * V_29 , T_2 V_30 ,
T_12 * V_211 , void * V_129 ,
bool V_459 , bool V_453 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
V_25 = F_273 ( V_29 , V_30 , V_211 , V_129 , V_453 ) ;
if ( ! F_218 ( V_25 ) )
return V_25 ;
if ( V_459 )
return V_25 ;
F_121 ( & V_32 -> V_186 ) ;
V_25 = F_26 ( V_29 , V_30 ) ;
if ( V_25 ) {
if ( V_25 -> V_211 == V_211 )
F_127 ( & V_25 -> V_185 ) ;
else
V_25 = F_267 ( - V_460 ) ;
}
F_123 ( & V_32 -> V_186 ) ;
if ( ! V_25 )
V_25 = F_267 ( - V_166 ) ;
return V_25 ;
}
static void V_425 ( struct V_189 * V_190 )
{
struct V_45 * V_46 = F_95 ( V_190 , struct V_45 , V_394 ) ;
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_46 -> V_81 ;
struct V_24 * V_461 ;
V_461 = F_279 ( V_29 , V_30 , F_145 , NULL , false , V_46 -> V_51 & V_462 ) ;
F_121 ( & V_32 -> V_186 ) ;
if ( ! F_218 ( V_461 ) )
F_233 ( V_461 , V_46 ) ;
F_123 ( & V_32 -> V_186 ) ;
F_136 ( V_46 -> V_72 ) ;
}
static int F_280 ( struct V_29 * V_29 , struct V_100 * V_72 ,
struct V_14 * V_163 [] , struct V_14 * V_129 [] )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_314 = & V_46 -> V_47 ;
V_93 V_111 ;
int V_95 ;
bool V_463 = false ;
if ( ! V_129 [ V_429 ] )
return - V_166 ;
V_111 = F_104 ( V_129 [ V_429 ] ) ;
V_314 -> V_48 = V_111 ;
V_314 -> V_66 . V_4 . V_5 = V_18 ;
if ( V_129 [ V_464 ] ) {
V_314 -> V_66 . sin . V_9 . V_10 = F_13 ( V_129 [ V_464 ] ) ;
} else if ( V_129 [ V_465 ] ) {
if ( ! F_102 ( V_164 ) )
return - V_449 ;
F_12 ( & V_314 -> V_66 . V_7 . V_8 , V_129 [ V_465 ] ,
sizeof( struct V_16 ) ) ;
V_314 -> V_66 . V_4 . V_5 = V_6 ;
V_463 = true ;
}
if ( V_129 [ V_466 ] ) {
V_46 -> V_218 . sin . V_9 . V_10 = F_13 ( V_129 [ V_466 ] ) ;
V_46 -> V_218 . V_4 . V_5 = V_18 ;
} else if ( V_129 [ V_467 ] ) {
if ( ! F_102 ( V_164 ) )
return - V_449 ;
F_12 ( & V_46 -> V_218 . V_7 . V_8 , V_129 [ V_467 ] ,
sizeof( struct V_16 ) ) ;
V_46 -> V_218 . V_4 . V_5 = V_6 ;
V_463 = true ;
}
if ( V_129 [ V_468 ] &&
( V_314 -> V_84 = F_104 ( V_129 [ V_468 ] ) ) ) {
struct V_100 * V_397
= F_105 ( V_29 , V_314 -> V_84 ) ;
if ( ! V_397 ) {
F_107 ( L_23 , V_314 -> V_84 ) ;
return - V_469 ;
}
#if F_102 ( V_164 )
if ( V_463 ) {
struct V_298 * V_470 = F_187 ( V_397 ) ;
if ( V_470 && V_470 -> V_471 . V_472 ) {
F_107 ( L_24 ) ;
return - V_473 ;
}
V_46 -> V_51 |= V_462 ;
}
#endif
if ( ! V_163 [ V_474 ] )
V_72 -> V_399 = V_397 -> V_399 - ( V_463 ? V_400 : V_401 ) ;
V_72 -> V_405 = V_397 -> V_405 +
( V_463 ? V_400 : V_401 ) ;
} else if ( V_463 )
V_46 -> V_51 |= V_462 ;
if ( V_129 [ V_475 ] )
V_46 -> V_224 = F_281 ( V_129 [ V_475 ] ) ;
if ( V_129 [ V_476 ] )
V_46 -> V_316 = F_281 ( V_129 [ V_476 ] ) ;
if ( ! V_129 [ V_477 ] || F_281 ( V_129 [ V_477 ] ) )
V_46 -> V_51 |= V_222 ;
if ( V_129 [ V_478 ] )
V_46 -> V_391 = F_104 ( V_129 [ V_478 ] ) ;
else
V_46 -> V_391 = V_479 ;
if ( V_129 [ V_480 ] && F_281 ( V_129 [ V_480 ] ) )
V_46 -> V_51 |= V_381 ;
if ( V_129 [ V_481 ] && F_281 ( V_129 [ V_481 ] ) )
V_46 -> V_51 |= V_382 ;
if ( V_129 [ V_482 ] && F_281 ( V_129 [ V_482 ] ) )
V_46 -> V_51 |= V_384 ;
if ( V_129 [ V_483 ] && F_281 ( V_129 [ V_483 ] ) )
V_46 -> V_51 |= V_263 ;
if ( V_129 [ V_484 ] )
V_46 -> V_153 = F_104 ( V_129 [ V_484 ] ) ;
if ( V_129 [ V_432 ] ) {
const struct V_433 * V_113
= F_260 ( V_129 [ V_432 ] ) ;
V_46 -> V_306 = F_21 ( V_113 -> V_403 ) ;
V_46 -> V_307 = F_21 ( V_113 -> V_404 ) ;
}
if ( V_129 [ V_485 ] )
V_46 -> V_81 = F_103 ( V_129 [ V_485 ] ) ;
if ( F_30 ( V_29 , V_111 , V_46 -> V_81 ) ) {
F_107 ( L_25 , V_111 ) ;
return - V_146 ;
}
F_282 ( V_72 , & V_486 ) ;
if ( ! F_3 ( & V_46 -> V_47 . V_66 ) ) {
V_95 = F_89 ( V_46 , V_383 ,
& V_46 -> V_47 . V_66 ,
V_170 | V_169 ,
V_145 | V_151 ,
V_46 -> V_81 ,
V_46 -> V_47 . V_48 ,
V_46 -> V_47 . V_84 ,
V_183 ) ;
if ( V_95 )
return V_95 ;
}
V_95 = F_283 ( V_72 ) ;
if ( V_95 ) {
F_237 ( V_46 ) ;
return V_95 ;
}
F_284 ( & V_46 -> V_40 , & V_32 -> V_487 ) ;
return 0 ;
}
static void F_285 ( struct V_100 * V_72 , struct V_488 * V_110 )
{
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
F_121 ( & V_32 -> V_186 ) ;
if ( ! F_286 ( & V_46 -> V_157 ) )
F_99 ( & V_46 -> V_157 ) ;
F_123 ( & V_32 -> V_186 ) ;
F_287 ( & V_46 -> V_40 ) ;
F_288 ( V_72 , V_110 ) ;
}
static T_3 F_289 ( const struct V_100 * V_72 )
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
static int F_290 ( struct V_20 * V_21 , const struct V_100 * V_72 )
{
const struct V_45 * V_46 = F_51 ( V_72 ) ;
const struct V_36 * V_314 = & V_46 -> V_47 ;
struct V_433 V_489 = {
. V_403 = F_143 ( V_46 -> V_306 ) ,
. V_404 = F_143 ( V_46 -> V_307 ) ,
} ;
if ( F_36 ( V_21 , V_429 , V_314 -> V_48 ) )
goto V_79;
if ( ! F_3 ( & V_314 -> V_66 ) ) {
if ( V_314 -> V_66 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_464 ,
V_314 -> V_66 . sin . V_9 . V_10 ) )
goto V_79;
#if F_102 ( V_164 )
} else {
if ( F_15 ( V_21 , V_465 , sizeof( struct V_16 ) ,
& V_314 -> V_66 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( V_314 -> V_84 && F_36 ( V_21 , V_468 , V_314 -> V_84 ) )
goto V_79;
if ( ! F_3 ( & V_46 -> V_218 ) ) {
if ( V_46 -> V_218 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_466 ,
V_46 -> V_218 . sin . V_9 . V_10 ) )
goto V_79;
#if F_102 ( V_164 )
} else {
if ( F_15 ( V_21 , V_467 , sizeof( struct V_16 ) ,
& V_46 -> V_218 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( F_291 ( V_21 , V_476 , V_46 -> V_316 ) ||
F_291 ( V_21 , V_475 , V_46 -> V_224 ) ||
F_291 ( V_21 , V_477 ,
! ! ( V_46 -> V_51 & V_222 ) ) ||
F_291 ( V_21 , V_480 ,
! ! ( V_46 -> V_51 & V_381 ) ) ||
F_291 ( V_21 , V_481 , ! ! ( V_46 -> V_51 & V_382 ) ) ||
F_291 ( V_21 , V_482 ,
! ! ( V_46 -> V_51 & V_384 ) ) ||
F_291 ( V_21 , V_483 ,
! ! ( V_46 -> V_51 & V_263 ) ) ||
F_36 ( V_21 , V_478 , V_46 -> V_391 ) ||
F_36 ( V_21 , V_484 , V_46 -> V_153 ) ||
F_35 ( V_21 , V_485 , V_46 -> V_81 ) )
goto V_79;
if ( F_15 ( V_21 , V_432 , sizeof( V_489 ) , & V_489 ) )
goto V_79;
return 0 ;
V_79:
return - V_63 ;
}
static void F_292 ( struct V_31 * V_32 ,
struct V_100 * V_72 )
{
struct V_45 * V_46 , * V_40 ;
F_293 ( V_490 ) ;
F_96 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_314 = & V_46 -> V_47 ;
if ( V_314 -> V_84 == V_72 -> V_73 )
F_285 ( V_46 -> V_72 , & V_490 ) ;
}
F_294 ( & V_490 ) ;
}
static int F_295 ( struct V_491 * V_492 ,
unsigned long V_493 , void * V_494 )
{
struct V_100 * V_72 = F_296 ( V_494 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
if ( V_493 == V_495 )
F_292 ( V_32 , V_72 ) ;
return V_496 ;
}
static T_13 int F_297 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_175 ;
F_92 ( & V_32 -> V_487 ) ;
F_252 ( & V_32 -> V_186 ) ;
for ( V_175 = 0 ; V_175 < V_402 ; ++ V_175 )
F_256 ( & V_32 -> V_34 [ V_175 ] ) ;
return 0 ;
}
static int T_14 F_298 ( void )
{
int V_148 ;
V_187 = F_299 ( L_18 , 0 , 0 ) ;
if ( ! V_187 )
return - V_156 ;
F_300 ( & V_497 , sizeof( V_497 ) ) ;
V_148 = F_301 ( & V_498 ) ;
if ( V_148 )
goto V_499;
V_148 = F_302 ( & V_500 ) ;
if ( V_148 )
goto V_501;
V_148 = F_303 ( & V_502 ) ;
if ( V_148 )
goto V_503;
return 0 ;
V_503:
F_304 ( & V_500 ) ;
V_501:
F_305 ( & V_498 ) ;
V_499:
F_306 ( V_187 ) ;
return V_148 ;
}
static void T_15 F_307 ( void )
{
F_308 ( & V_502 ) ;
F_304 ( & V_500 ) ;
F_306 ( V_187 ) ;
F_305 ( & V_498 ) ;
}
