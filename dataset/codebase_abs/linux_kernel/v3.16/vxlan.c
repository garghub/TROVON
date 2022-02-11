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
if ( V_61 && F_14 ( V_21 , V_80 , & V_52 -> V_66 ) )
goto V_79;
if ( V_52 -> V_81 && V_52 -> V_81 != V_46 -> V_82 &&
F_35 ( V_21 , V_83 , V_52 -> V_81 ) )
goto V_79;
if ( V_52 -> V_48 != V_46 -> V_47 . V_48 &&
F_36 ( V_21 , V_84 , V_52 -> V_48 ) )
goto V_79;
if ( V_52 -> V_85 &&
F_36 ( V_21 , V_86 , V_52 -> V_85 ) )
goto V_79;
V_56 . V_87 = F_37 ( V_53 - V_38 -> V_88 ) ;
V_56 . V_89 = 0 ;
V_56 . V_90 = F_37 ( V_53 - V_38 -> V_91 ) ;
V_56 . V_92 = 0 ;
if ( F_15 ( V_21 , V_93 , sizeof( V_56 ) , & V_56 ) )
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
+ F_42 ( sizeof( V_94 ) )
+ F_42 ( sizeof( struct V_55 ) ) ;
}
static void F_43 ( struct V_45 * V_46 , struct V_37 * V_38 ,
struct V_36 * V_95 , int type )
{
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
struct V_20 * V_21 ;
int V_96 = - V_97 ;
V_21 = F_45 ( F_40 () , V_98 ) ;
if ( V_21 == NULL )
goto V_99;
V_96 = F_31 ( V_21 , V_46 , V_38 , 0 , 0 , type , 0 , V_95 ) ;
if ( V_96 < 0 ) {
F_46 ( V_96 == - V_63 ) ;
F_47 ( V_21 ) ;
goto V_99;
}
F_48 ( V_21 , V_29 , 0 , V_100 , NULL , V_98 ) ;
return;
V_99:
if ( V_96 < 0 )
F_49 ( V_29 , V_100 , V_96 ) ;
}
static void F_50 ( struct V_101 * V_72 , union V_1 * V_11 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 V_102 = {
. V_70 = V_103 ,
} ;
struct V_36 V_104 = {
. V_66 = * V_11 ,
. V_48 = V_105 ,
} ;
F_43 ( V_46 , & V_102 , & V_104 , V_64 ) ;
}
static void F_52 ( struct V_45 * V_46 , const T_4 V_67 [ V_78 ] )
{
struct V_37 V_102 = {
. V_70 = V_103 ,
} ;
struct V_36 V_104 = { } ;
memcpy ( V_102 . V_67 , V_67 , V_78 ) ;
F_43 ( V_46 , & V_102 , & V_104 , V_64 ) ;
}
static T_1 F_53 ( const unsigned char * V_106 )
{
T_5 V_107 = F_54 ( ( T_5 * ) V_106 ) ;
#ifdef F_55
V_107 >>= 16 ;
#else
V_107 <<= 16 ;
#endif
return F_56 ( V_107 , V_108 ) ;
}
static inline struct V_23 * F_57 ( struct V_45 * V_46 ,
const T_4 * V_109 )
{
return & V_46 -> V_110 [ F_53 ( V_109 ) ] ;
}
static struct V_37 * F_58 ( struct V_45 * V_46 ,
const T_4 * V_109 )
{
struct V_23 * V_111 = F_57 ( V_46 , V_109 ) ;
struct V_37 * V_102 ;
F_27 (f, head, hlist) {
if ( F_59 ( V_109 , V_102 -> V_67 ) )
return V_102 ;
}
return NULL ;
}
static struct V_37 * F_60 ( struct V_45 * V_46 ,
const T_4 * V_109 )
{
struct V_37 * V_102 ;
V_102 = F_58 ( V_46 , V_109 ) ;
if ( V_102 )
V_102 -> V_88 = V_54 ;
return V_102 ;
}
static struct V_36 * F_61 ( struct V_37 * V_102 ,
union V_1 * V_13 , T_2 V_30 ,
V_94 V_112 , V_94 V_73 )
{
struct V_36 * V_95 ;
F_62 (rd, &f->remotes, list) {
if ( F_1 ( & V_95 -> V_66 , V_13 ) &&
V_95 -> V_81 == V_30 &&
V_95 -> V_48 == V_112 &&
V_95 -> V_85 == V_73 )
return V_95 ;
}
return NULL ;
}
static int F_63 ( struct V_37 * V_102 ,
union V_1 * V_13 , T_2 V_30 , V_94 V_112 , V_94 V_73 )
{
struct V_36 * V_95 ;
V_95 = F_61 ( V_102 , V_13 , V_30 , V_112 , V_73 ) ;
if ( V_95 )
return 0 ;
V_95 = F_64 ( & V_102 -> V_39 , struct V_36 , V_41 ) ;
if ( ! V_95 )
return 0 ;
V_95 -> V_66 = * V_13 ;
V_95 -> V_81 = V_30 ;
V_95 -> V_48 = V_112 ;
V_95 -> V_85 = V_73 ;
return 1 ;
}
static int F_65 ( struct V_37 * V_102 ,
union V_1 * V_13 , T_2 V_30 , V_94 V_112 ,
V_94 V_73 , struct V_36 * * V_113 )
{
struct V_36 * V_95 ;
V_95 = F_61 ( V_102 , V_13 , V_30 , V_112 , V_73 ) ;
if ( V_95 )
return 0 ;
V_95 = F_66 ( sizeof( * V_95 ) , V_98 ) ;
if ( V_95 == NULL )
return - V_97 ;
V_95 -> V_66 = * V_13 ;
V_95 -> V_81 = V_30 ;
V_95 -> V_48 = V_112 ;
V_95 -> V_85 = V_73 ;
F_67 ( & V_95 -> V_41 , & V_102 -> V_39 ) ;
* V_113 = V_95 ;
return 1 ;
}
static struct V_20 * * F_68 ( struct V_20 * * V_111 , struct V_20 * V_21 )
{
struct V_20 * V_114 , * * V_115 = NULL ;
struct V_116 * V_117 , * V_118 ;
struct V_119 * V_120 , * V_121 ;
unsigned int V_122 , V_123 , V_124 ;
const struct V_125 * V_126 ;
T_2 type ;
int V_127 = 1 ;
V_123 = F_69 ( V_21 ) ;
V_122 = V_123 + sizeof( * V_117 ) ;
V_117 = F_70 ( V_21 , V_123 ) ;
if ( F_71 ( V_21 , V_122 ) ) {
V_117 = F_72 ( V_21 , V_122 , V_123 ) ;
if ( F_73 ( ! V_117 ) )
goto V_128;
}
F_74 ( V_21 , sizeof( struct V_116 ) ) ;
F_75 ( V_21 , V_117 , sizeof( struct V_116 ) ) ;
V_124 = F_69 ( V_21 ) ;
V_122 = V_124 + sizeof( * V_120 ) ;
V_120 = F_70 ( V_21 , V_124 ) ;
if ( F_71 ( V_21 , V_122 ) ) {
V_120 = F_72 ( V_21 , V_122 , V_124 ) ;
if ( F_73 ( ! V_120 ) )
goto V_128;
}
V_127 = 0 ;
for ( V_114 = * V_111 ; V_114 ; V_114 = V_114 -> V_40 ) {
if ( ! F_76 ( V_114 ) -> V_129 )
continue;
V_118 = (struct V_116 * ) ( V_114 -> V_130 + V_123 ) ;
V_121 = (struct V_119 * ) ( V_114 -> V_130 + V_124 ) ;
if ( V_117 -> V_131 != V_118 -> V_131 || F_77 ( V_120 , V_121 ) ) {
F_76 ( V_114 ) -> V_129 = 0 ;
continue;
}
}
type = V_120 -> V_132 ;
F_78 () ;
V_126 = F_79 ( type ) ;
if ( V_126 == NULL ) {
V_127 = 1 ;
goto V_133;
}
F_74 ( V_21 , sizeof( * V_120 ) ) ;
F_75 ( V_21 , V_120 , sizeof( * V_120 ) ) ;
V_115 = V_126 -> V_134 . V_135 ( V_111 , V_21 ) ;
V_133:
F_80 () ;
V_128:
F_76 ( V_21 ) -> V_127 |= V_127 ;
return V_115 ;
}
static int F_81 ( struct V_20 * V_21 , int V_136 )
{
struct V_119 * V_120 ;
struct V_125 * V_126 ;
T_2 type ;
int V_137 = sizeof( struct V_116 ) + sizeof( struct V_119 ) ;
int V_96 = - V_138 ;
V_120 = (struct V_119 * ) ( V_21 -> V_130 + V_136 + sizeof( struct V_116 ) ) ;
type = V_120 -> V_132 ;
F_78 () ;
V_126 = F_82 ( type ) ;
if ( V_126 != NULL )
V_96 = V_126 -> V_134 . V_139 ( V_21 , V_136 + V_137 ) ;
F_80 () ;
return V_96 ;
}
static void F_83 ( struct V_24 * V_25 )
{
struct V_101 * V_72 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_84 ( V_43 ) ;
T_6 V_5 = V_43 -> V_140 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
int V_96 ;
if ( V_5 == V_18 ) {
V_96 = F_85 ( & V_25 -> V_141 ) ;
if ( V_96 )
F_86 ( L_1 , V_96 ) ;
}
F_78 () ;
F_87 (net, dev) {
if ( V_72 -> V_142 -> V_143 )
V_72 -> V_142 -> V_143 ( V_72 , V_5 ,
V_30 ) ;
}
F_80 () ;
}
static void F_88 ( struct V_24 * V_25 )
{
struct V_101 * V_72 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_84 ( V_43 ) ;
T_6 V_5 = V_43 -> V_140 ;
T_2 V_30 = F_28 ( V_43 ) -> V_44 ;
F_78 () ;
F_87 (net, dev) {
if ( V_72 -> V_142 -> V_144 )
V_72 -> V_142 -> V_144 ( V_72 , V_5 ,
V_30 ) ;
}
F_80 () ;
if ( V_5 == V_18 )
F_89 ( & V_25 -> V_141 ) ;
}
static int F_90 ( struct V_45 * V_46 ,
const T_4 * V_109 , union V_1 * V_13 ,
T_7 V_70 , T_7 V_51 ,
T_2 V_30 , V_94 V_112 , V_94 V_73 ,
T_8 V_74 )
{
struct V_36 * V_95 = NULL ;
struct V_37 * V_102 ;
int V_145 = 0 ;
V_102 = F_58 ( V_46 , V_109 ) ;
if ( V_102 ) {
if ( V_51 & V_146 ) {
F_91 ( V_46 -> V_72 ,
L_2 , V_109 ) ;
return - V_147 ;
}
if ( V_102 -> V_70 != V_70 ) {
V_102 -> V_70 = V_70 ;
V_102 -> V_91 = V_54 ;
V_145 = 1 ;
}
if ( V_102 -> V_51 != V_74 ) {
V_102 -> V_51 = V_74 ;
V_102 -> V_91 = V_54 ;
V_145 = 1 ;
}
if ( ( V_51 & V_148 ) ) {
if ( ! ( F_92 ( V_102 -> V_67 ) ||
F_34 ( V_102 -> V_67 ) ) ) {
int V_149 = F_63 ( V_102 , V_13 , V_30 , V_112 ,
V_73 ) ;
if ( V_149 < 0 )
return V_149 ;
V_145 |= V_149 ;
} else
return - V_150 ;
}
if ( ( V_51 & V_151 ) &&
( F_92 ( V_102 -> V_67 ) ||
F_34 ( V_102 -> V_67 ) ) ) {
int V_149 = F_65 ( V_102 , V_13 , V_30 , V_112 , V_73 ,
& V_95 ) ;
if ( V_149 < 0 )
return V_149 ;
V_145 |= V_149 ;
}
} else {
if ( ! ( V_51 & V_152 ) )
return - V_153 ;
if ( V_46 -> V_154 && V_46 -> V_155 >= V_46 -> V_154 )
return - V_156 ;
if ( ( V_51 & V_148 ) &&
( F_92 ( V_109 ) || F_34 ( V_109 ) ) )
return - V_150 ;
F_91 ( V_46 -> V_72 , L_3 , V_109 , V_13 ) ;
V_102 = F_66 ( sizeof( * V_102 ) , V_98 ) ;
if ( ! V_102 )
return - V_157 ;
V_145 = 1 ;
V_102 -> V_70 = V_70 ;
V_102 -> V_51 = V_74 ;
V_102 -> V_91 = V_102 -> V_88 = V_54 ;
F_93 ( & V_102 -> V_39 ) ;
memcpy ( V_102 -> V_67 , V_109 , V_78 ) ;
F_65 ( V_102 , V_13 , V_30 , V_112 , V_73 , & V_95 ) ;
++ V_46 -> V_155 ;
F_94 ( & V_102 -> V_158 ,
F_57 ( V_46 , V_109 ) ) ;
}
if ( V_145 ) {
if ( V_95 == NULL )
V_95 = F_24 ( V_102 ) ;
F_43 ( V_46 , V_102 , V_95 , V_159 ) ;
}
return 0 ;
}
static void F_95 ( struct V_160 * V_111 )
{
struct V_37 * V_102 = F_96 ( V_111 , struct V_37 , V_161 ) ;
struct V_36 * V_95 , * V_162 ;
F_97 (rd, nd, &f->remotes, list)
F_98 ( V_95 ) ;
F_98 ( V_102 ) ;
}
static void F_99 ( struct V_45 * V_46 , struct V_37 * V_102 )
{
F_91 ( V_46 -> V_72 ,
L_4 , V_102 -> V_67 ) ;
-- V_46 -> V_155 ;
F_43 ( V_46 , V_102 , F_24 ( V_102 ) , V_163 ) ;
F_100 ( & V_102 -> V_158 ) ;
F_101 ( & V_102 -> V_161 , F_95 ) ;
}
static int F_102 ( struct V_14 * V_164 [] , struct V_45 * V_46 ,
union V_1 * V_13 , T_2 * V_30 , T_1 * V_112 , T_1 * V_73 )
{
struct V_29 * V_29 = F_44 ( V_46 -> V_72 ) ;
int V_96 ;
if ( V_164 [ V_80 ] ) {
V_96 = F_10 ( V_13 , V_164 [ V_80 ] ) ;
if ( V_96 )
return V_96 ;
} else {
union V_1 * V_104 = & V_46 -> V_47 . V_66 ;
if ( V_104 -> V_4 . V_5 == V_18 ) {
V_13 -> sin . V_9 . V_10 = F_5 ( V_12 ) ;
V_13 -> V_4 . V_5 = V_18 ;
#if F_103 ( V_165 )
} else {
V_13 -> V_7 . V_8 = V_166 ;
V_13 -> V_4 . V_5 = V_6 ;
#endif
}
}
if ( V_164 [ V_83 ] ) {
if ( F_11 ( V_164 [ V_83 ] ) != sizeof( T_2 ) )
return - V_167 ;
* V_30 = F_104 ( V_164 [ V_83 ] ) ;
} else {
* V_30 = V_46 -> V_82 ;
}
if ( V_164 [ V_84 ] ) {
if ( F_11 ( V_164 [ V_84 ] ) != sizeof( T_1 ) )
return - V_167 ;
* V_112 = F_105 ( V_164 [ V_84 ] ) ;
} else {
* V_112 = V_46 -> V_47 . V_48 ;
}
if ( V_164 [ V_86 ] ) {
struct V_101 * V_168 ;
if ( F_11 ( V_164 [ V_86 ] ) != sizeof( T_1 ) )
return - V_167 ;
* V_73 = F_105 ( V_164 [ V_86 ] ) ;
V_168 = F_106 ( V_29 , * V_73 ) ;
if ( ! V_168 )
return - V_169 ;
} else {
* V_73 = 0 ;
}
return 0 ;
}
static int F_107 ( struct V_59 * V_60 , struct V_14 * V_164 [] ,
struct V_101 * V_72 ,
const unsigned char * V_106 , T_9 V_51 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_112 , V_73 ;
int V_96 ;
if ( ! ( V_60 -> V_69 & ( V_170 | V_171 ) ) ) {
F_108 ( L_5 ,
V_60 -> V_69 ) ;
return - V_167 ;
}
if ( V_164 [ V_80 ] == NULL )
return - V_167 ;
V_96 = F_102 ( V_164 , V_46 , & V_13 , & V_30 , & V_112 , & V_73 ) ;
if ( V_96 )
return V_96 ;
if ( V_46 -> V_47 . V_66 . V_4 . V_5 != V_13 . V_4 . V_5 )
return - V_19 ;
F_109 ( & V_46 -> V_172 ) ;
V_96 = F_90 ( V_46 , V_106 , & V_13 , V_60 -> V_69 , V_51 ,
V_30 , V_112 , V_73 , V_60 -> V_74 ) ;
F_110 ( & V_46 -> V_172 ) ;
return V_96 ;
}
static int F_111 ( struct V_59 * V_60 , struct V_14 * V_164 [] ,
struct V_101 * V_72 ,
const unsigned char * V_106 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_102 ;
struct V_36 * V_95 = NULL ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_112 , V_73 ;
int V_96 ;
V_96 = F_102 ( V_164 , V_46 , & V_13 , & V_30 , & V_112 , & V_73 ) ;
if ( V_96 )
return V_96 ;
V_96 = - V_153 ;
F_109 ( & V_46 -> V_172 ) ;
V_102 = F_60 ( V_46 , V_106 ) ;
if ( ! V_102 )
goto V_128;
if ( ! F_3 ( & V_13 ) ) {
V_95 = F_61 ( V_102 , & V_13 , V_30 , V_112 , V_73 ) ;
if ( ! V_95 )
goto V_128;
}
V_96 = 0 ;
if ( V_95 && ! F_112 ( & V_102 -> V_39 ) ) {
F_113 ( & V_95 -> V_41 ) ;
F_43 ( V_46 , V_102 , V_95 , V_163 ) ;
F_114 ( V_95 , V_161 ) ;
goto V_128;
}
F_99 ( V_46 , V_102 ) ;
V_128:
F_110 ( & V_46 -> V_172 ) ;
return V_96 ;
}
static int F_115 ( struct V_20 * V_21 , struct V_173 * V_174 ,
struct V_101 * V_72 , int V_175 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_176 ;
for ( V_176 = 0 ; V_176 < V_177 ; ++ V_176 ) {
struct V_37 * V_102 ;
int V_96 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_95 ;
if ( V_175 < V_174 -> args [ 0 ] )
goto V_178;
F_116 (rd, &f->remotes, list) {
V_96 = F_31 ( V_21 , V_46 , V_102 ,
F_117 ( V_174 -> V_21 ) . V_49 ,
V_174 -> V_58 -> V_179 ,
V_159 ,
V_180 , V_95 ) ;
if ( V_96 < 0 )
goto V_128;
}
V_178:
++ V_175 ;
}
}
V_128:
return V_175 ;
}
static bool F_118 ( struct V_101 * V_72 ,
union V_1 * V_181 , const T_4 * V_182 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_102 ;
V_102 = F_60 ( V_46 , V_182 ) ;
if ( F_119 ( V_102 ) ) {
struct V_36 * V_52 = F_22 ( V_102 ) ;
if ( F_119 ( F_1 ( & V_52 -> V_66 , V_181 ) ) )
return false ;
if ( V_102 -> V_70 & V_183 )
return true ;
if ( F_120 () )
F_121 ( V_72 ,
L_6 ,
V_182 , & V_52 -> V_66 , & V_181 ) ;
V_52 -> V_66 = * V_181 ;
V_102 -> V_91 = V_54 ;
F_43 ( V_46 , V_102 , V_52 , V_159 ) ;
} else {
F_122 ( & V_46 -> V_172 ) ;
if ( F_123 ( V_72 ) )
F_90 ( V_46 , V_182 , V_181 ,
V_171 ,
V_146 | V_152 ,
V_46 -> V_82 ,
V_46 -> V_47 . V_48 ,
0 , V_184 ) ;
F_124 ( & V_46 -> V_172 ) ;
}
return false ;
}
static bool F_125 ( struct V_31 * V_32 , struct V_45 * V_72 )
{
struct V_45 * V_46 ;
if ( F_126 ( & V_72 -> V_185 -> V_186 ) == 1 )
return false ;
F_62 (vxlan, &vn->vxlan_list, next) {
if ( ! F_123 ( V_46 -> V_72 ) || V_46 == V_72 )
continue;
if ( V_46 -> V_185 != V_72 -> V_185 )
continue;
if ( ! F_1 ( & V_46 -> V_47 . V_66 ,
& V_72 -> V_47 . V_66 ) )
continue;
if ( V_46 -> V_47 . V_85 !=
V_72 -> V_47 . V_85 )
continue;
return true ;
}
return false ;
}
static void F_127 ( struct V_24 * V_25 )
{
F_128 ( & V_25 -> V_186 ) ;
}
void F_129 ( struct V_24 * V_25 )
{
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_84 ( V_43 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_130 ( & V_25 -> V_186 ) )
return;
F_122 ( & V_32 -> V_187 ) ;
F_100 ( & V_25 -> V_158 ) ;
F_131 ( V_25 -> V_42 -> V_43 , NULL ) ;
F_88 ( V_25 ) ;
F_124 ( & V_32 -> V_187 ) ;
F_132 ( V_188 , & V_25 -> V_189 ) ;
}
static void F_133 ( struct V_190 * V_191 )
{
struct V_45 * V_46 = F_96 ( V_191 , struct V_45 , V_192 ) ;
struct V_24 * V_25 = V_46 -> V_185 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_85 ;
F_134 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_193 V_194 = {
. V_195 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_196 = V_73 ,
} ;
F_135 ( V_43 , & V_194 ) ;
#if F_103 ( V_165 )
} else {
V_197 -> V_198 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_136 ( V_43 ) ;
F_129 ( V_25 ) ;
F_137 ( V_46 -> V_72 ) ;
}
static void F_138 ( struct V_190 * V_191 )
{
struct V_45 * V_46 = F_96 ( V_191 , struct V_45 , V_199 ) ;
struct V_24 * V_25 = V_46 -> V_185 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_85 ;
F_134 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_193 V_194 = {
. V_195 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_196 = V_73 ,
} ;
F_139 ( V_43 , & V_194 ) ;
#if F_103 ( V_165 )
} else {
V_197 -> V_200 ( V_43 , V_73 ,
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
struct V_116 * V_201 ;
if ( ! F_141 ( V_21 , V_202 ) )
goto error;
V_201 = (struct V_116 * ) ( F_142 ( V_21 ) + 1 ) ;
if ( V_201 -> V_203 != F_5 ( V_204 ) ||
( V_201 -> V_131 & F_5 ( 0xff ) ) ) {
F_91 ( V_21 -> V_72 , L_7 ,
F_9 ( V_201 -> V_203 ) , F_9 ( V_201 -> V_131 ) ) ;
goto error;
}
if ( F_143 ( V_21 , V_202 , F_144 ( V_205 ) ) )
goto V_206;
V_25 = F_145 ( V_43 ) ;
if ( ! V_25 )
goto V_206;
F_146 ( V_21 ) ;
V_25 -> V_207 ( V_25 , V_21 , V_201 -> V_131 ) ;
return 0 ;
V_206:
F_47 ( V_21 ) ;
return 0 ;
error:
return 1 ;
}
static void F_147 ( struct V_24 * V_25 ,
struct V_20 * V_21 , V_17 V_131 )
{
struct V_208 * V_209 = NULL ;
struct V_210 * V_211 = NULL ;
struct V_45 * V_46 ;
struct V_212 * V_213 ;
union V_1 V_214 ;
V_94 V_112 ;
int V_96 = 0 ;
union V_1 * V_66 ;
V_112 = F_9 ( V_131 ) >> 8 ;
V_46 = F_29 ( V_25 , V_112 ) ;
if ( ! V_46 )
goto V_206;
V_66 = & V_46 -> V_47 . V_66 ;
F_148 ( V_21 ) ;
F_149 ( V_21 , ! F_150 ( V_46 -> V_29 , F_44 ( V_46 -> V_72 ) ) ) ;
V_21 -> V_215 = F_151 ( V_21 , V_46 -> V_72 ) ;
F_152 ( V_21 , F_153 ( V_21 ) , V_216 ) ;
if ( F_59 ( F_153 ( V_21 ) -> V_217 , V_46 -> V_72 -> V_218 ) )
goto V_206;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_209 = F_154 ( V_21 ) ;
V_214 . sin . V_9 . V_10 = V_209 -> V_214 ;
V_214 . V_4 . V_5 = V_18 ;
#if F_103 ( V_165 )
} else {
V_211 = F_155 ( V_21 ) ;
V_214 . V_7 . V_8 = V_211 -> V_214 ;
V_214 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_46 -> V_51 & V_219 ) &&
F_118 ( V_21 -> V_72 , & V_214 , F_153 ( V_21 ) -> V_217 ) )
goto V_206;
F_156 ( V_21 ) ;
if ( V_211 )
V_96 = F_157 ( V_211 , V_21 ) ;
if ( V_209 )
V_96 = F_158 ( V_209 , V_21 ) ;
if ( F_73 ( V_96 ) ) {
if ( V_220 ) {
if ( V_211 )
F_159 ( L_8 ,
& V_211 -> V_214 ) ;
if ( V_209 )
F_159 ( L_9 ,
& V_209 -> V_214 , V_209 -> V_221 ) ;
}
if ( V_96 > 1 ) {
++ V_46 -> V_72 -> V_213 . V_222 ;
++ V_46 -> V_72 -> V_213 . V_223 ;
goto V_206;
}
}
V_213 = F_160 ( V_46 -> V_72 -> V_224 ) ;
F_161 ( & V_213 -> V_225 ) ;
V_213 -> V_226 ++ ;
V_213 -> V_227 += V_21 -> V_228 ;
F_162 ( & V_213 -> V_225 ) ;
F_163 ( V_21 ) ;
return;
V_206:
F_47 ( V_21 ) ;
}
static int F_164 ( struct V_101 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_229 * V_230 ;
T_4 * V_231 , * V_232 ;
V_17 V_233 , V_234 ;
struct V_235 * V_236 ;
if ( V_72 -> V_51 & V_237 )
goto V_128;
if ( ! F_141 ( V_21 , F_165 ( V_72 ) ) ) {
V_72 -> V_213 . V_238 ++ ;
goto V_128;
}
V_230 = F_166 ( V_21 ) ;
if ( ( V_230 -> V_239 != F_144 ( V_240 ) &&
V_230 -> V_239 != F_144 ( V_241 ) ) ||
V_230 -> V_242 != F_144 ( V_243 ) ||
V_230 -> V_244 != F_144 ( V_245 ) ||
V_230 -> V_246 != V_72 -> V_247 ||
V_230 -> V_248 != 4 )
goto V_128;
V_231 = ( T_4 * ) V_230 + sizeof( struct V_229 ) ;
V_232 = V_231 ;
V_231 += V_72 -> V_247 ;
memcpy ( & V_233 , V_231 , sizeof( V_233 ) ) ;
V_231 += sizeof( V_233 ) ;
V_231 += V_72 -> V_247 ;
memcpy ( & V_234 , V_231 , sizeof( V_234 ) ) ;
if ( F_167 ( V_234 ) ||
F_168 ( V_234 ) )
goto V_128;
V_236 = F_169 ( & V_249 , & V_234 , V_72 ) ;
if ( V_236 ) {
struct V_37 * V_102 ;
struct V_20 * V_250 ;
if ( ! ( V_236 -> V_251 & V_252 ) ) {
F_170 ( V_236 ) ;
goto V_128;
}
V_102 = F_60 ( V_46 , V_236 -> V_253 ) ;
if ( V_102 && F_3 ( & ( F_22 ( V_102 ) -> V_66 ) ) ) {
F_170 ( V_236 ) ;
goto V_128;
}
V_250 = F_171 ( V_254 , V_255 , V_233 , V_72 , V_234 , V_232 ,
V_236 -> V_253 , V_232 ) ;
F_170 ( V_236 ) ;
if ( V_250 == NULL )
goto V_128;
F_148 ( V_250 ) ;
F_172 ( V_250 , F_173 ( V_250 ) ) ;
V_250 -> V_256 = V_257 ;
V_250 -> V_258 = V_259 ;
if ( F_174 ( V_250 ) == V_260 )
V_72 -> V_213 . V_261 ++ ;
} else if ( V_46 -> V_51 & V_262 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_234 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_128:
F_175 ( V_21 ) ;
return V_263 ;
}
static struct V_20 * F_176 ( struct V_20 * V_264 ,
struct V_235 * V_236 , bool V_265 )
{
struct V_101 * V_72 = V_264 -> V_72 ;
struct V_20 * V_250 ;
struct V_266 * V_267 , * V_268 ;
struct V_210 * V_269 ;
T_4 * V_270 ;
int V_271 = 8 ;
int V_272 ;
int V_273 , V_228 ;
if ( V_72 == NULL )
return NULL ;
V_228 = F_177 ( V_72 ) + sizeof( struct V_210 ) +
sizeof( * V_268 ) + V_271 + V_72 -> V_274 ;
V_250 = F_178 ( V_228 , V_98 ) ;
if ( V_250 == NULL )
return NULL ;
V_250 -> V_215 = F_144 ( V_275 ) ;
V_250 -> V_72 = V_72 ;
F_179 ( V_250 , F_177 ( V_264 -> V_72 ) ) ;
F_180 ( V_250 , sizeof( struct V_119 ) ) ;
F_181 ( V_250 , 0 ) ;
V_267 = (struct V_266 * ) F_182 ( V_264 ) ;
V_270 = F_153 ( V_264 ) -> V_217 ;
V_272 = V_264 -> V_228 - F_183 ( V_264 ) - sizeof( * V_267 ) ;
for ( V_273 = 0 ; V_273 < V_272 - 1 ; V_273 += ( V_267 -> V_276 [ V_273 + 1 ] << 3 ) ) {
if ( V_267 -> V_276 [ V_273 ] == V_277 ) {
V_270 = V_267 -> V_276 + V_273 + sizeof( struct V_278 ) ;
break;
}
}
F_184 ( F_153 ( V_250 ) -> V_279 , V_270 ) ;
F_184 ( F_153 ( V_250 ) -> V_217 , V_236 -> V_253 ) ;
F_153 ( V_250 ) -> V_132 = F_144 ( V_275 ) ;
V_250 -> V_215 = F_144 ( V_275 ) ;
F_185 ( V_250 , sizeof( struct V_119 ) ) ;
F_186 ( V_250 , 0 ) ;
F_187 ( V_250 , sizeof( struct V_210 ) ) ;
V_269 = F_155 ( V_250 ) ;
memset ( V_269 , 0 , sizeof( struct V_210 ) ) ;
V_269 -> V_280 = 6 ;
V_269 -> V_281 = F_155 ( V_264 ) -> V_281 ;
V_269 -> V_282 = V_283 ;
V_269 -> V_284 = 255 ;
V_269 -> V_270 = F_155 ( V_264 ) -> V_214 ;
V_269 -> V_214 = * (struct V_16 * ) V_236 -> V_285 ;
F_185 ( V_250 , sizeof( struct V_210 ) ) ;
F_188 ( V_250 , 0 ) ;
V_268 = (struct V_266 * ) F_187 ( V_250 , sizeof( * V_268 ) + V_271 ) ;
memset ( V_268 , 0 , sizeof( * V_268 ) + V_271 ) ;
V_268 -> V_286 . V_287 = V_288 ;
V_268 -> V_286 . V_289 = V_265 ;
V_268 -> V_286 . V_290 = 1 ;
V_268 -> V_286 . V_291 = 1 ;
V_268 -> V_292 = V_267 -> V_292 ;
F_184 ( & V_268 -> V_276 [ 2 ] , V_236 -> V_253 ) ;
V_268 -> V_276 [ 0 ] = V_293 ;
V_268 -> V_276 [ 1 ] = V_271 >> 3 ;
V_268 -> V_286 . V_294 = F_189 ( & V_269 -> V_214 ,
& V_269 -> V_270 , sizeof( * V_268 ) + V_271 , V_283 ,
F_190 ( V_268 , sizeof( * V_268 ) + V_271 , 0 ) ) ;
V_269 -> V_295 = F_144 ( sizeof( * V_268 ) + V_271 ) ;
F_180 ( V_250 , sizeof( struct V_210 ) ) ;
V_250 -> V_256 = V_257 ;
return V_250 ;
}
static int F_191 ( struct V_101 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_266 * V_296 ;
const struct V_210 * V_208 ;
const struct V_16 * V_214 , * V_270 ;
struct V_235 * V_236 ;
struct V_297 * V_298 ;
V_298 = F_192 ( V_72 ) ;
if ( ! V_298 )
goto V_128;
if ( ! F_141 ( V_21 , V_21 -> V_228 ) )
goto V_128;
V_208 = F_155 ( V_21 ) ;
V_214 = & V_208 -> V_214 ;
V_270 = & V_208 -> V_270 ;
V_296 = (struct V_266 * ) F_182 ( V_21 ) ;
if ( V_296 -> V_286 . V_299 != 0 ||
V_296 -> V_286 . V_287 != V_300 )
goto V_128;
if ( F_193 ( V_270 ) ||
F_7 ( & V_296 -> V_292 ) )
goto V_128;
V_236 = F_169 ( V_197 -> V_301 , & V_296 -> V_292 , V_72 ) ;
if ( V_236 ) {
struct V_37 * V_102 ;
struct V_20 * V_250 ;
if ( ! ( V_236 -> V_251 & V_252 ) ) {
F_170 ( V_236 ) ;
goto V_128;
}
V_102 = F_60 ( V_46 , V_236 -> V_253 ) ;
if ( V_102 && F_3 ( & ( F_22 ( V_102 ) -> V_66 ) ) ) {
F_170 ( V_236 ) ;
goto V_128;
}
V_250 = F_176 ( V_21 , V_236 ,
! ! ( V_102 ? V_102 -> V_51 & V_302 : 0 ) ) ;
F_170 ( V_236 ) ;
if ( V_250 == NULL )
goto V_128;
if ( F_174 ( V_250 ) == V_260 )
V_72 -> V_213 . V_261 ++ ;
} else if ( V_46 -> V_51 & V_262 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_296 -> V_292 ,
. V_4 . V_5 = V_6 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_128:
F_175 ( V_21 ) ;
return V_263 ;
}
static bool F_194 ( struct V_101 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_235 * V_236 ;
if ( F_92 ( F_153 ( V_21 ) -> V_279 ) )
return false ;
V_236 = NULL ;
switch ( F_21 ( F_153 ( V_21 ) -> V_132 ) ) {
case V_243 :
{
struct V_208 * V_303 ;
if ( ! F_141 ( V_21 , sizeof( struct V_208 ) ) )
return false ;
V_303 = F_154 ( V_21 ) ;
V_236 = F_169 ( & V_249 , & V_303 -> V_270 , V_72 ) ;
if ( ! V_236 && ( V_46 -> V_51 & V_262 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_303 -> V_270 ,
. V_4 . V_5 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
return false ;
}
break;
}
#if F_103 ( V_165 )
case V_275 :
{
struct V_210 * V_269 ;
if ( ! F_141 ( V_21 , sizeof( struct V_210 ) ) )
return false ;
V_269 = F_155 ( V_21 ) ;
V_236 = F_169 ( V_197 -> V_301 , & V_269 -> V_270 , V_72 ) ;
if ( ! V_236 && ( V_46 -> V_51 & V_262 ) ) {
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
if ( V_236 ) {
bool V_304 ;
V_304 = ! F_59 ( F_153 ( V_21 ) -> V_279 , V_236 -> V_253 ) ;
if ( V_304 ) {
memcpy ( F_153 ( V_21 ) -> V_217 , F_153 ( V_21 ) -> V_279 ,
V_72 -> V_247 ) ;
memcpy ( F_153 ( V_21 ) -> V_279 , V_236 -> V_253 , V_72 -> V_247 ) ;
}
F_170 ( V_236 ) ;
return V_304 ;
}
return false ;
}
T_2 F_195 ( T_7 V_305 , T_7 V_306 , struct V_20 * V_21 )
{
unsigned int V_307 = ( V_306 - V_305 ) + 1 ;
T_1 V_308 ;
V_308 = F_196 ( V_21 ) ;
if ( ! V_308 )
V_308 = F_197 ( V_21 -> V_130 , 2 * V_78 ,
( V_309 T_1 ) V_21 -> V_215 ) ;
return F_144 ( ( ( ( T_5 ) V_308 * V_307 ) >> 32 ) + V_305 ) ;
}
static inline struct V_20 * F_198 ( struct V_20 * V_21 ,
bool V_310 )
{
int type = V_310 ? V_311 : V_312 ;
return F_199 ( V_21 , V_310 , type ) ;
}
static int F_200 ( struct V_24 * V_25 ,
struct V_313 * V_314 , struct V_20 * V_21 ,
struct V_101 * V_72 , struct V_16 * V_214 ,
struct V_16 * V_270 , T_8 V_315 , T_8 V_316 ,
T_2 V_317 , T_2 V_82 , V_17 V_112 ,
bool V_318 )
{
struct V_210 * V_319 ;
struct V_116 * V_201 ;
struct V_320 * V_321 ;
int V_322 ;
int V_96 ;
V_21 = F_198 ( V_21 , ! F_201 ( V_25 -> V_42 -> V_43 ) ) ;
if ( F_202 ( V_21 ) )
return - V_167 ;
F_149 ( V_21 , V_318 ) ;
V_322 = F_177 ( V_314 -> V_72 ) + V_314 -> V_323
+ V_202 + sizeof( struct V_210 )
+ ( F_203 ( V_21 ) ? V_324 : 0 ) ;
V_96 = F_204 ( V_21 , V_322 ) ;
if ( F_73 ( V_96 ) )
return V_96 ;
if ( F_203 ( V_21 ) ) {
if ( F_46 ( ! F_205 ( V_21 ,
V_21 -> V_325 ,
F_206 ( V_21 ) ) ) )
return - V_157 ;
V_21 -> V_326 = 0 ;
}
V_201 = (struct V_116 * ) F_207 ( V_21 , sizeof( * V_201 ) ) ;
V_201 -> V_203 = F_5 ( V_204 ) ;
V_201 -> V_131 = V_112 ;
F_207 ( V_21 , sizeof( * V_321 ) ) ;
F_208 ( V_21 ) ;
V_321 = F_142 ( V_21 ) ;
V_321 -> V_327 = V_82 ;
V_321 -> V_328 = V_317 ;
V_321 -> V_228 = F_144 ( V_21 -> V_228 ) ;
memset ( & ( F_209 ( V_21 ) -> V_276 ) , 0 , sizeof( F_209 ( V_21 ) -> V_276 ) ) ;
F_209 ( V_21 ) -> V_51 &= ~ ( V_329 | V_330 |
V_331 ) ;
F_210 ( V_21 , V_314 ) ;
F_211 ( F_201 ( V_25 -> V_42 -> V_43 ) , V_21 ,
V_214 , V_270 , V_21 -> V_228 ) ;
F_207 ( V_21 , sizeof( * V_319 ) ) ;
F_156 ( V_21 ) ;
V_319 = F_155 ( V_21 ) ;
V_319 -> V_280 = 6 ;
V_319 -> V_281 = V_315 ;
V_319 -> V_332 [ 0 ] = 0 ;
V_319 -> V_332 [ 1 ] = 0 ;
V_319 -> V_332 [ 2 ] = 0 ;
V_319 -> V_295 = F_144 ( V_21 -> V_228 ) ;
V_319 -> V_282 = V_333 ;
V_319 -> V_284 = V_316 ;
V_319 -> V_270 = * V_270 ;
V_319 -> V_214 = * V_214 ;
F_212 ( V_21 , V_72 ) ;
return 0 ;
}
int F_213 ( struct V_24 * V_25 ,
struct V_334 * V_335 , struct V_20 * V_21 ,
V_17 V_336 , V_17 V_314 , T_8 V_221 , T_8 V_316 , T_2 V_337 ,
T_2 V_317 , T_2 V_82 , V_17 V_112 , bool V_318 )
{
struct V_116 * V_201 ;
struct V_320 * V_321 ;
int V_322 ;
int V_96 ;
V_21 = F_198 ( V_21 , ! V_25 -> V_42 -> V_43 -> V_338 ) ;
if ( F_202 ( V_21 ) )
return - V_167 ;
V_322 = F_177 ( V_335 -> V_314 . V_72 ) + V_335 -> V_314 . V_323
+ V_202 + sizeof( struct V_208 )
+ ( F_203 ( V_21 ) ? V_324 : 0 ) ;
V_96 = F_204 ( V_21 , V_322 ) ;
if ( F_73 ( V_96 ) )
return V_96 ;
if ( F_203 ( V_21 ) ) {
if ( F_46 ( ! F_205 ( V_21 ,
V_21 -> V_325 ,
F_206 ( V_21 ) ) ) )
return - V_157 ;
V_21 -> V_326 = 0 ;
}
V_201 = (struct V_116 * ) F_207 ( V_21 , sizeof( * V_201 ) ) ;
V_201 -> V_203 = F_5 ( V_204 ) ;
V_201 -> V_131 = V_112 ;
F_207 ( V_21 , sizeof( * V_321 ) ) ;
F_208 ( V_21 ) ;
V_321 = F_142 ( V_21 ) ;
V_321 -> V_327 = V_82 ;
V_321 -> V_328 = V_317 ;
V_321 -> V_228 = F_144 ( V_21 -> V_228 ) ;
F_214 ( V_25 -> V_42 -> V_43 -> V_338 , V_21 ,
V_336 , V_314 , V_21 -> V_228 ) ;
return F_215 ( V_25 -> V_42 -> V_43 , V_335 , V_21 , V_336 , V_314 , V_333 ,
V_221 , V_316 , V_337 , V_318 ) ;
}
static void F_216 ( struct V_20 * V_21 , struct V_45 * V_339 ,
struct V_45 * V_340 )
{
struct V_212 * V_341 , * V_342 ;
union V_1 V_343 ;
union V_1 * V_66 = & V_340 -> V_47 . V_66 ;
V_341 = F_160 ( V_339 -> V_72 -> V_224 ) ;
V_342 = F_160 ( V_340 -> V_72 -> V_224 ) ;
V_21 -> V_258 = V_259 ;
V_21 -> V_344 = 0 ;
V_21 -> V_72 = V_340 -> V_72 ;
F_172 ( V_21 , F_173 ( V_21 ) ) ;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_343 . sin . V_9 . V_10 = F_5 ( V_345 ) ;
V_343 . V_4 . V_5 = V_18 ;
#if F_103 ( V_165 )
} else {
V_343 . V_7 . V_8 = V_346 ;
V_343 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_340 -> V_51 & V_219 )
F_118 ( V_21 -> V_72 , & V_343 , F_153 ( V_21 ) -> V_217 ) ;
F_161 ( & V_341 -> V_225 ) ;
V_341 -> V_347 ++ ;
V_341 -> V_348 += V_21 -> V_228 ;
F_162 ( & V_341 -> V_225 ) ;
if ( F_163 ( V_21 ) == V_349 ) {
F_161 ( & V_342 -> V_225 ) ;
V_342 -> V_226 ++ ;
V_342 -> V_227 += V_21 -> V_228 ;
F_162 ( & V_342 -> V_225 ) ;
} else {
V_21 -> V_72 -> V_213 . V_261 ++ ;
}
}
static void F_217 ( struct V_20 * V_21 , struct V_101 * V_72 ,
struct V_36 * V_52 , bool V_350 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_334 * V_335 = NULL ;
const struct V_208 * V_351 ;
struct V_352 V_353 ;
union V_1 * V_314 ;
T_2 V_317 = 0 , V_82 ;
T_1 V_112 ;
T_2 V_337 = 0 ;
T_8 V_221 , V_316 ;
int V_96 ;
V_82 = V_52 -> V_81 ? V_52 -> V_81 : V_46 -> V_82 ;
V_112 = V_52 -> V_48 ;
V_314 = & V_52 -> V_66 ;
if ( F_3 ( V_314 ) ) {
if ( V_350 ) {
F_216 ( V_21 , V_46 , V_46 ) ;
return;
}
goto V_206;
}
V_351 = F_154 ( V_21 ) ;
V_316 = V_46 -> V_316 ;
if ( ! V_316 && F_6 ( V_314 ) )
V_316 = 1 ;
V_221 = V_46 -> V_221 ;
if ( V_221 == 1 )
V_221 = F_218 ( V_351 , V_21 ) ;
V_317 = F_195 ( V_46 -> V_305 , V_46 -> V_306 , V_21 ) ;
if ( V_314 -> V_4 . V_5 == V_18 ) {
memset ( & V_353 , 0 , sizeof( V_353 ) ) ;
V_353 . V_354 = V_52 -> V_85 ;
V_353 . V_355 = F_219 ( V_221 ) ;
V_353 . V_270 = V_314 -> sin . V_9 . V_10 ;
V_353 . V_214 = V_46 -> V_214 . sin . V_9 . V_10 ;
V_335 = F_220 ( V_46 -> V_29 , & V_353 ) ;
if ( F_202 ( V_335 ) ) {
F_91 ( V_72 , L_10 ,
& V_314 -> sin . V_9 . V_10 ) ;
V_72 -> V_213 . V_356 ++ ;
goto V_357;
}
if ( V_335 -> V_314 . V_72 == V_72 ) {
F_91 ( V_72 , L_11 ,
& V_314 -> sin . V_9 . V_10 ) ;
V_72 -> V_213 . V_358 ++ ;
goto V_359;
}
if ( V_335 -> V_360 & V_361 &&
! ( V_335 -> V_360 & ( V_362 | V_363 ) ) ) {
struct V_45 * V_340 ;
F_221 ( V_335 ) ;
V_340 = F_30 ( V_46 -> V_29 , V_112 , V_82 ) ;
if ( ! V_340 )
goto V_357;
F_216 ( V_21 , V_46 , V_340 ) ;
return;
}
V_221 = F_222 ( V_221 , V_351 , V_21 ) ;
V_316 = V_316 ? : F_223 ( & V_335 -> V_314 ) ;
V_96 = F_213 ( V_46 -> V_185 , V_335 , V_21 ,
V_353 . V_214 , V_314 -> sin . V_9 . V_10 ,
V_221 , V_316 , V_337 , V_317 , V_82 ,
F_5 ( V_112 << 8 ) ,
! F_150 ( V_46 -> V_29 , F_44 ( V_46 -> V_72 ) ) ) ;
if ( V_96 < 0 )
goto V_359;
F_224 ( V_96 , & V_72 -> V_213 , V_72 -> V_224 ) ;
#if F_103 ( V_165 )
} else {
struct V_42 * V_43 = V_46 -> V_185 -> V_42 -> V_43 ;
struct V_313 * V_364 ;
struct V_365 V_366 ;
T_1 V_51 ;
memset ( & V_366 , 0 , sizeof( V_366 ) ) ;
V_366 . V_367 = V_52 -> V_85 ;
V_366 . V_270 = V_314 -> V_7 . V_8 ;
V_366 . V_214 = V_46 -> V_214 . V_7 . V_8 ;
V_366 . V_368 = V_333 ;
if ( V_197 -> V_369 ( V_43 , & V_364 , & V_366 ) ) {
F_91 ( V_72 , L_12 ,
& V_314 -> V_7 . V_8 ) ;
V_72 -> V_213 . V_356 ++ ;
goto V_357;
}
if ( V_364 -> V_72 == V_72 ) {
F_91 ( V_72 , L_13 ,
& V_314 -> V_7 . V_8 ) ;
F_225 ( V_364 ) ;
V_72 -> V_213 . V_358 ++ ;
goto V_357;
}
V_51 = ( (struct V_370 * ) V_364 ) -> V_371 ;
if ( V_51 & V_372 &&
! ( V_51 & ( V_362 | V_363 ) ) ) {
struct V_45 * V_340 ;
F_225 ( V_364 ) ;
V_340 = F_30 ( V_46 -> V_29 , V_112 , V_82 ) ;
if ( ! V_340 )
goto V_357;
F_216 ( V_21 , V_46 , V_340 ) ;
return;
}
V_316 = V_316 ? : F_226 ( V_364 ) ;
V_96 = F_200 ( V_46 -> V_185 , V_364 , V_21 ,
V_72 , & V_366 . V_214 , & V_366 . V_270 , 0 , V_316 ,
V_317 , V_82 , F_5 ( V_112 << 8 ) ,
! F_150 ( V_46 -> V_29 , F_44 ( V_46 -> V_72 ) ) ) ;
#endif
}
return;
V_206:
V_72 -> V_213 . V_238 ++ ;
goto V_373;
V_359:
F_221 ( V_335 ) ;
V_357:
V_72 -> V_213 . V_374 ++ ;
V_373:
F_227 ( V_21 ) ;
}
static T_10 F_228 ( struct V_20 * V_21 , struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_119 * V_375 ;
bool V_350 = false ;
struct V_36 * V_52 , * V_376 = NULL ;
struct V_37 * V_102 ;
F_148 ( V_21 ) ;
V_375 = F_153 ( V_21 ) ;
if ( ( V_46 -> V_51 & V_377 ) ) {
if ( F_21 ( V_375 -> V_132 ) == V_255 )
return F_164 ( V_72 , V_21 ) ;
#if F_103 ( V_165 )
else if ( F_21 ( V_375 -> V_132 ) == V_275 &&
V_21 -> V_228 >= sizeof( struct V_210 ) + sizeof( struct V_266 ) &&
F_155 ( V_21 ) -> V_282 == V_283 ) {
struct V_266 * V_296 ;
V_296 = (struct V_266 * ) F_182 ( V_21 ) ;
if ( V_296 -> V_286 . V_299 == 0 &&
V_296 -> V_286 . V_287 == V_300 )
return F_191 ( V_72 , V_21 ) ;
}
#endif
}
V_102 = F_60 ( V_46 , V_375 -> V_279 ) ;
V_350 = false ;
if ( V_102 && ( V_102 -> V_51 & V_302 ) && ( V_46 -> V_51 & V_378 ) &&
( F_21 ( V_375 -> V_132 ) == V_243 ||
F_21 ( V_375 -> V_132 ) == V_275 ) ) {
V_350 = F_194 ( V_72 , V_21 ) ;
if ( V_350 )
V_102 = F_60 ( V_46 , V_375 -> V_279 ) ;
}
if ( V_102 == NULL ) {
V_102 = F_60 ( V_46 , V_379 ) ;
if ( V_102 == NULL ) {
if ( ( V_46 -> V_51 & V_380 ) &&
! F_92 ( V_375 -> V_279 ) )
F_52 ( V_46 , V_375 -> V_279 ) ;
V_72 -> V_213 . V_238 ++ ;
F_47 ( V_21 ) ;
return V_263 ;
}
}
F_116 (rdst, &f->remotes, list) {
struct V_20 * V_381 ;
if ( ! V_376 ) {
V_376 = V_52 ;
continue;
}
V_381 = F_229 ( V_21 , V_98 ) ;
if ( V_381 )
F_217 ( V_381 , V_72 , V_52 , V_350 ) ;
}
if ( V_376 )
F_217 ( V_21 , V_72 , V_376 , V_350 ) ;
else
F_47 ( V_21 ) ;
return V_263 ;
}
static void F_230 ( unsigned long V_382 )
{
struct V_45 * V_46 = (struct V_45 * ) V_382 ;
unsigned long V_383 = V_54 + V_384 ;
unsigned int V_176 ;
if ( ! F_123 ( V_46 -> V_72 ) )
return;
F_109 ( & V_46 -> V_172 ) ;
for ( V_176 = 0 ; V_176 < V_177 ; ++ V_176 ) {
struct V_385 * V_114 , * V_236 ;
F_231 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_102
= F_96 ( V_114 , struct V_37 , V_158 ) ;
unsigned long V_386 ;
if ( V_102 -> V_70 & V_170 )
continue;
V_386 = V_102 -> V_88 + V_46 -> V_387 * V_388 ;
if ( F_232 ( V_386 , V_54 ) ) {
F_91 ( V_46 -> V_72 ,
L_14 ,
V_102 -> V_67 ) ;
V_102 -> V_70 = V_103 ;
F_99 ( V_46 , V_102 ) ;
} else if ( F_233 ( V_386 , V_383 ) )
V_383 = V_386 ;
}
}
F_110 ( & V_46 -> V_172 ) ;
F_234 ( & V_46 -> V_389 , V_383 ) ;
}
static void F_235 ( struct V_24 * V_25 , struct V_45 * V_46 )
{
V_94 V_112 = V_46 -> V_47 . V_48 ;
V_46 -> V_185 = V_25 ;
F_94 ( & V_46 -> V_158 , F_17 ( V_25 , V_112 ) ) ;
}
static int F_236 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_46 -> V_29 , V_33 ) ;
struct V_24 * V_25 ;
V_72 -> V_224 = F_237 ( struct V_212 ) ;
if ( ! V_72 -> V_224 )
return - V_157 ;
F_122 ( & V_32 -> V_187 ) ;
V_25 = F_26 ( V_46 -> V_29 , V_46 -> V_82 ) ;
if ( V_25 ) {
F_128 ( & V_25 -> V_186 ) ;
F_235 ( V_25 , V_46 ) ;
} else {
F_238 ( V_72 ) ;
F_132 ( V_188 , & V_46 -> V_390 ) ;
}
F_124 ( & V_32 -> V_187 ) ;
return 0 ;
}
static void F_239 ( struct V_45 * V_46 )
{
struct V_37 * V_102 ;
F_109 ( & V_46 -> V_172 ) ;
V_102 = F_58 ( V_46 , V_379 ) ;
if ( V_102 )
F_99 ( V_46 , V_102 ) ;
F_110 ( & V_46 -> V_172 ) ;
}
static void F_240 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_185 ;
F_239 ( V_46 ) ;
if ( V_25 )
F_129 ( V_25 ) ;
F_241 ( V_72 -> V_224 ) ;
}
static int F_242 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_185 ;
if ( ! V_25 )
return - V_391 ;
if ( F_6 ( & V_46 -> V_47 . V_66 ) ) {
F_127 ( V_25 ) ;
F_238 ( V_72 ) ;
F_132 ( V_188 , & V_46 -> V_192 ) ;
}
if ( V_46 -> V_387 )
F_234 ( & V_46 -> V_389 , V_54 + V_384 ) ;
return 0 ;
}
static void F_243 ( struct V_45 * V_46 )
{
unsigned int V_176 ;
F_109 ( & V_46 -> V_172 ) ;
for ( V_176 = 0 ; V_176 < V_177 ; ++ V_176 ) {
struct V_385 * V_114 , * V_236 ;
F_231 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_102
= F_96 ( V_114 , struct V_37 , V_158 ) ;
if ( ! F_34 ( V_102 -> V_67 ) )
F_99 ( V_46 , V_102 ) ;
}
}
F_110 ( & V_46 -> V_172 ) ;
}
static int F_244 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_46 -> V_29 , V_33 ) ;
struct V_24 * V_25 = V_46 -> V_185 ;
if ( V_25 && F_6 ( & V_46 -> V_47 . V_66 ) &&
! F_125 ( V_32 , V_46 ) ) {
F_127 ( V_25 ) ;
F_238 ( V_72 ) ;
F_132 ( V_188 , & V_46 -> V_199 ) ;
}
F_245 ( & V_46 -> V_389 ) ;
F_243 ( V_46 ) ;
return 0 ;
}
static void F_246 ( struct V_101 * V_72 )
{
}
static int F_247 ( struct V_101 * V_72 , int V_392 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_314 = & V_46 -> V_47 ;
struct V_101 * V_393 ;
int V_394 ;
V_393 = F_106 ( V_46 -> V_29 , V_314 -> V_85 ) ;
if ( V_393 == NULL )
return F_248 ( V_72 , V_392 ) ;
if ( V_314 -> V_66 . V_4 . V_5 == V_6 )
V_394 = V_393 -> V_395 - V_396 ;
else
V_394 = V_393 -> V_395 - V_397 ;
if ( V_392 < 68 || V_392 > V_394 )
return - V_167 ;
V_72 -> V_395 = V_392 ;
return 0 ;
}
void F_249 ( struct V_101 * V_72 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_44 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_6 V_5 ;
T_2 V_30 ;
unsigned int V_273 ;
F_122 ( & V_32 -> V_187 ) ;
for ( V_273 = 0 ; V_273 < V_398 ; ++ V_273 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_42 -> V_43 ) -> V_44 ;
V_5 = V_25 -> V_42 -> V_43 -> V_140 ;
V_72 -> V_142 -> V_143 ( V_72 , V_5 ,
V_30 ) ;
}
}
F_124 ( & V_32 -> V_187 ) ;
}
static void F_250 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_176 ;
int V_399 , V_400 ;
F_251 ( V_72 ) ;
F_252 ( V_72 ) ;
if ( V_46 -> V_47 . V_66 . V_4 . V_5 == V_6 )
V_72 -> V_401 = V_216 + V_396 ;
else
V_72 -> V_401 = V_216 + V_397 ;
V_72 -> V_142 = & V_402 ;
V_72 -> V_403 = V_404 ;
F_253 ( V_72 , & V_405 ) ;
V_72 -> V_406 = 0 ;
V_72 -> V_407 |= V_408 ;
V_72 -> V_407 |= V_409 | V_410 ;
V_72 -> V_407 |= V_411 ;
V_72 -> V_407 |= V_412 ;
V_72 -> V_413 = V_72 -> V_407 ;
V_72 -> V_407 |= V_414 | V_415 ;
V_72 -> V_416 |= V_409 | V_410 | V_411 ;
V_72 -> V_416 |= V_412 ;
V_72 -> V_416 |= V_414 | V_415 ;
V_72 -> V_417 &= ~ V_418 ;
V_72 -> V_417 |= V_419 ;
F_93 ( & V_46 -> V_40 ) ;
F_254 ( & V_46 -> V_172 ) ;
F_255 ( & V_46 -> V_192 , F_133 ) ;
F_255 ( & V_46 -> V_199 , F_138 ) ;
F_255 ( & V_46 -> V_390 , V_420 ) ;
F_256 ( & V_46 -> V_389 ) ;
V_46 -> V_389 . V_421 = F_230 ;
V_46 -> V_389 . V_130 = ( unsigned long ) V_46 ;
F_257 ( F_44 ( V_72 ) , & V_399 , & V_400 ) ;
V_46 -> V_305 = V_399 ;
V_46 -> V_306 = V_400 ;
V_46 -> V_82 = F_144 ( V_422 ) ;
V_46 -> V_72 = V_72 ;
for ( V_176 = 0 ; V_176 < V_177 ; ++ V_176 )
F_258 ( & V_46 -> V_110 [ V_176 ] ) ;
}
static int F_259 ( struct V_14 * V_164 [] , struct V_14 * V_130 [] )
{
if ( V_164 [ V_423 ] ) {
if ( F_11 ( V_164 [ V_423 ] ) != V_78 ) {
F_260 ( L_15 ) ;
return - V_167 ;
}
if ( ! F_261 ( F_262 ( V_164 [ V_423 ] ) ) ) {
F_260 ( L_16 ) ;
return - V_169 ;
}
}
if ( ! V_130 )
return - V_167 ;
if ( V_130 [ V_424 ] ) {
V_94 V_26 = F_105 ( V_130 [ V_424 ] ) ;
if ( V_26 >= V_425 )
return - V_426 ;
}
if ( V_130 [ V_427 ] ) {
const struct V_428 * V_114
= F_262 ( V_130 [ V_427 ] ) ;
if ( F_21 ( V_114 -> V_400 ) < F_21 ( V_114 -> V_399 ) ) {
F_260 ( L_17 ,
F_21 ( V_114 -> V_399 ) , F_21 ( V_114 -> V_400 ) ) ;
return - V_167 ;
}
}
return 0 ;
}
static void F_263 ( struct V_101 * V_429 ,
struct V_430 * V_431 )
{
F_264 ( V_431 -> V_280 , V_432 , sizeof( V_431 -> V_280 ) ) ;
F_264 ( V_431 -> V_433 , L_18 , sizeof( V_431 -> V_433 ) ) ;
}
static void F_265 ( struct V_190 * V_191 )
{
struct V_24 * V_25 = F_96 ( V_191 , struct V_24 , V_189 ) ;
F_266 ( V_25 -> V_42 -> V_43 ) ;
F_114 ( V_25 , V_161 ) ;
}
static struct V_434 * F_267 ( struct V_29 * V_29 , T_2 V_30 , T_1 V_51 )
{
struct V_42 * V_43 ;
struct V_434 * V_42 ;
struct V_435 V_1 = {
. V_436 = V_6 ,
. V_437 = V_30 ,
} ;
int V_149 , V_438 = 1 ;
V_149 = F_268 ( V_6 , V_439 , V_333 , & V_42 ) ;
if ( V_149 < 0 ) {
F_260 ( L_19 ) ;
return F_269 ( V_149 ) ;
}
V_43 = V_42 -> V_43 ;
F_270 ( V_43 , V_29 ) ;
F_271 ( V_42 , V_440 , V_441 ,
( char * ) & V_438 , sizeof( V_438 ) ) ;
V_149 = F_272 ( V_42 , (struct V_442 * ) & V_1 ,
sizeof( struct V_435 ) ) ;
if ( V_149 < 0 ) {
F_260 ( L_20 ,
& V_1 . V_8 , F_21 ( V_1 . V_437 ) , V_149 ) ;
F_266 ( V_43 ) ;
return F_269 ( V_149 ) ;
}
F_273 ( ! V_197 ) ;
F_28 ( V_43 ) -> V_443 = 0 ;
if ( V_51 & V_444 )
F_274 ( V_43 , true ) ;
if ( V_51 & V_445 )
F_275 ( V_43 , true ) ;
return V_42 ;
}
static struct V_434 * F_267 ( struct V_29 * V_29 , T_2 V_30 , T_1 V_51 )
{
return F_269 ( - V_446 ) ;
}
static struct V_434 * F_276 ( struct V_29 * V_29 , T_2 V_30 , T_1 V_51 )
{
struct V_42 * V_43 ;
struct V_434 * V_42 ;
struct V_447 V_1 = {
. V_448 = V_18 ,
. V_9 . V_10 = F_5 ( V_12 ) ,
. V_449 = V_30 ,
} ;
int V_149 ;
V_149 = F_268 ( V_18 , V_439 , V_333 , & V_42 ) ;
if ( V_149 < 0 ) {
F_260 ( L_21 ) ;
return F_269 ( V_149 ) ;
}
V_43 = V_42 -> V_43 ;
F_270 ( V_43 , V_29 ) ;
V_149 = F_272 ( V_42 , (struct V_442 * ) & V_1 ,
sizeof( V_1 ) ) ;
if ( V_149 < 0 ) {
F_260 ( L_22 ,
& V_1 . V_9 , F_21 ( V_1 . V_449 ) , V_149 ) ;
F_266 ( V_43 ) ;
return F_269 ( V_149 ) ;
}
F_28 ( V_43 ) -> V_443 = 0 ;
if ( ! ( V_51 & V_450 ) )
V_42 -> V_43 -> V_338 = 1 ;
return V_42 ;
}
static struct V_24 * F_277 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_207 , void * V_130 ,
T_1 V_51 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_434 * V_42 ;
struct V_42 * V_43 ;
unsigned int V_176 ;
bool V_451 = ! ! ( V_51 & V_452 ) ;
V_25 = F_278 ( sizeof( * V_25 ) , V_453 ) ;
if ( ! V_25 )
return F_269 ( - V_157 ) ;
for ( V_176 = 0 ; V_176 < V_454 ; ++ V_176 )
F_258 ( & V_25 -> V_27 [ V_176 ] ) ;
F_255 ( & V_25 -> V_189 , F_265 ) ;
if ( V_451 )
V_42 = F_267 ( V_29 , V_30 , V_51 ) ;
else
V_42 = F_276 ( V_29 , V_30 , V_51 ) ;
if ( F_202 ( V_42 ) ) {
F_98 ( V_25 ) ;
return F_279 ( V_42 ) ;
}
V_25 -> V_42 = V_42 ;
V_43 = V_42 -> V_43 ;
F_280 ( & V_25 -> V_186 , 1 ) ;
V_25 -> V_207 = V_207 ;
V_25 -> V_130 = V_130 ;
F_131 ( V_25 -> V_42 -> V_43 , V_25 ) ;
V_25 -> V_141 . V_30 = V_30 ;
V_25 -> V_141 . V_134 . V_135 = F_68 ;
V_25 -> V_141 . V_134 . V_139 = F_81 ;
F_122 ( & V_32 -> V_187 ) ;
F_94 ( & V_25 -> V_158 , F_19 ( V_29 , V_30 ) ) ;
F_83 ( V_25 ) ;
F_124 ( & V_32 -> V_187 ) ;
F_281 ( V_43 ) -> V_455 = 1 ;
F_281 ( V_43 ) -> V_456 = F_140 ;
#if F_103 ( V_165 )
if ( V_451 )
V_197 -> V_457 () ;
else
#endif
F_282 () ;
return V_25 ;
}
struct V_24 * F_283 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_207 , void * V_130 ,
bool V_458 , T_1 V_51 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
V_25 = F_277 ( V_29 , V_30 , V_207 , V_130 , V_51 ) ;
if ( ! F_202 ( V_25 ) )
return V_25 ;
if ( V_458 )
return V_25 ;
F_122 ( & V_32 -> V_187 ) ;
V_25 = F_26 ( V_29 , V_30 ) ;
if ( V_25 ) {
if ( V_25 -> V_207 == V_207 )
F_128 ( & V_25 -> V_186 ) ;
else
V_25 = F_269 ( - V_459 ) ;
}
F_124 ( & V_32 -> V_187 ) ;
if ( ! V_25 )
V_25 = F_269 ( - V_167 ) ;
return V_25 ;
}
static void V_420 ( struct V_190 * V_191 )
{
struct V_45 * V_46 = F_96 ( V_191 , struct V_45 , V_390 ) ;
struct V_29 * V_29 = V_46 -> V_29 ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_46 -> V_82 ;
struct V_24 * V_460 ;
V_460 = F_283 ( V_29 , V_30 , F_147 , NULL , false , V_46 -> V_51 ) ;
F_122 ( & V_32 -> V_187 ) ;
if ( ! F_202 ( V_460 ) )
F_235 ( V_460 , V_46 ) ;
F_124 ( & V_32 -> V_187 ) ;
F_137 ( V_46 -> V_72 ) ;
}
static int F_284 ( struct V_29 * V_29 , struct V_101 * V_72 ,
struct V_14 * V_164 [] , struct V_14 * V_130 [] )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_314 = & V_46 -> V_47 ;
V_94 V_112 ;
int V_96 ;
bool V_461 = false ;
if ( ! V_130 [ V_424 ] )
return - V_167 ;
V_46 -> V_29 = F_44 ( V_72 ) ;
V_112 = F_105 ( V_130 [ V_424 ] ) ;
V_314 -> V_48 = V_112 ;
V_314 -> V_66 . V_4 . V_5 = V_18 ;
if ( V_130 [ V_462 ] ) {
V_314 -> V_66 . sin . V_9 . V_10 = F_13 ( V_130 [ V_462 ] ) ;
} else if ( V_130 [ V_463 ] ) {
if ( ! F_103 ( V_165 ) )
return - V_446 ;
F_12 ( & V_314 -> V_66 . V_7 . V_8 , V_130 [ V_463 ] ,
sizeof( struct V_16 ) ) ;
V_314 -> V_66 . V_4 . V_5 = V_6 ;
V_461 = true ;
}
if ( V_130 [ V_464 ] ) {
V_46 -> V_214 . sin . V_9 . V_10 = F_13 ( V_130 [ V_464 ] ) ;
V_46 -> V_214 . V_4 . V_5 = V_18 ;
} else if ( V_130 [ V_465 ] ) {
if ( ! F_103 ( V_165 ) )
return - V_446 ;
F_12 ( & V_46 -> V_214 . V_7 . V_8 , V_130 [ V_465 ] ,
sizeof( struct V_16 ) ) ;
V_46 -> V_214 . V_4 . V_5 = V_6 ;
V_461 = true ;
}
if ( V_130 [ V_466 ] &&
( V_314 -> V_85 = F_105 ( V_130 [ V_466 ] ) ) ) {
struct V_101 * V_393
= F_106 ( V_29 , V_314 -> V_85 ) ;
if ( ! V_393 ) {
F_108 ( L_23 , V_314 -> V_85 ) ;
return - V_467 ;
}
#if F_103 ( V_165 )
if ( V_461 ) {
struct V_297 * V_468 = F_192 ( V_393 ) ;
if ( V_468 && V_468 -> V_469 . V_470 ) {
F_108 ( L_24 ) ;
return - V_471 ;
}
V_46 -> V_51 |= V_452 ;
}
#endif
if ( ! V_164 [ V_472 ] )
V_72 -> V_395 = V_393 -> V_395 - ( V_461 ? V_396 : V_397 ) ;
V_72 -> V_401 = V_393 -> V_473 +
( V_461 ? V_396 : V_397 ) ;
} else if ( V_461 )
V_46 -> V_51 |= V_452 ;
if ( V_130 [ V_474 ] )
V_46 -> V_221 = F_285 ( V_130 [ V_474 ] ) ;
if ( V_130 [ V_475 ] )
V_46 -> V_316 = F_285 ( V_130 [ V_475 ] ) ;
if ( ! V_130 [ V_476 ] || F_285 ( V_130 [ V_476 ] ) )
V_46 -> V_51 |= V_219 ;
if ( V_130 [ V_477 ] )
V_46 -> V_387 = F_105 ( V_130 [ V_477 ] ) ;
else
V_46 -> V_387 = V_478 ;
if ( V_130 [ V_479 ] && F_285 ( V_130 [ V_479 ] ) )
V_46 -> V_51 |= V_377 ;
if ( V_130 [ V_480 ] && F_285 ( V_130 [ V_480 ] ) )
V_46 -> V_51 |= V_378 ;
if ( V_130 [ V_481 ] && F_285 ( V_130 [ V_481 ] ) )
V_46 -> V_51 |= V_380 ;
if ( V_130 [ V_482 ] && F_285 ( V_130 [ V_482 ] ) )
V_46 -> V_51 |= V_262 ;
if ( V_130 [ V_483 ] )
V_46 -> V_154 = F_105 ( V_130 [ V_483 ] ) ;
if ( V_130 [ V_427 ] ) {
const struct V_428 * V_114
= F_262 ( V_130 [ V_427 ] ) ;
V_46 -> V_305 = F_21 ( V_114 -> V_399 ) ;
V_46 -> V_306 = F_21 ( V_114 -> V_400 ) ;
}
if ( V_130 [ V_484 ] )
V_46 -> V_82 = F_104 ( V_130 [ V_484 ] ) ;
if ( V_130 [ V_485 ] && F_285 ( V_130 [ V_485 ] ) )
V_46 -> V_51 |= V_450 ;
if ( V_130 [ V_486 ] &&
F_285 ( V_130 [ V_486 ] ) )
V_46 -> V_51 |= V_444 ;
if ( V_130 [ V_487 ] &&
F_285 ( V_130 [ V_487 ] ) )
V_46 -> V_51 |= V_445 ;
if ( F_30 ( V_29 , V_112 , V_46 -> V_82 ) ) {
F_108 ( L_25 , V_112 ) ;
return - V_147 ;
}
V_72 -> V_488 = & V_489 ;
if ( ! F_3 ( & V_46 -> V_47 . V_66 ) ) {
V_96 = F_90 ( V_46 , V_379 ,
& V_46 -> V_47 . V_66 ,
V_171 | V_170 ,
V_146 | V_152 ,
V_46 -> V_82 ,
V_46 -> V_47 . V_48 ,
V_46 -> V_47 . V_85 ,
V_184 ) ;
if ( V_96 )
return V_96 ;
}
V_96 = F_286 ( V_72 ) ;
if ( V_96 ) {
F_239 ( V_46 ) ;
return V_96 ;
}
F_287 ( & V_46 -> V_40 , & V_32 -> V_490 ) ;
return 0 ;
}
static void F_288 ( struct V_101 * V_72 , struct V_491 * V_111 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_46 -> V_29 , V_33 ) ;
F_122 ( & V_32 -> V_187 ) ;
if ( ! F_289 ( & V_46 -> V_158 ) )
F_100 ( & V_46 -> V_158 ) ;
F_124 ( & V_32 -> V_187 ) ;
F_290 ( & V_46 -> V_40 ) ;
F_291 ( V_72 , V_111 ) ;
}
static T_3 F_292 ( const struct V_101 * V_72 )
{
return F_42 ( sizeof( V_94 ) ) +
F_42 ( sizeof( struct V_16 ) ) +
F_42 ( sizeof( V_94 ) ) +
F_42 ( sizeof( struct V_16 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( V_94 ) ) +
F_42 ( sizeof( V_94 ) ) +
F_42 ( sizeof( struct V_428 ) ) +
F_42 ( sizeof( T_2 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
0 ;
}
static int F_293 ( struct V_20 * V_21 , const struct V_101 * V_72 )
{
const struct V_45 * V_46 = F_51 ( V_72 ) ;
const struct V_36 * V_314 = & V_46 -> V_47 ;
struct V_428 V_492 = {
. V_399 = F_144 ( V_46 -> V_305 ) ,
. V_400 = F_144 ( V_46 -> V_306 ) ,
} ;
if ( F_36 ( V_21 , V_424 , V_314 -> V_48 ) )
goto V_79;
if ( ! F_3 ( & V_314 -> V_66 ) ) {
if ( V_314 -> V_66 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_462 ,
V_314 -> V_66 . sin . V_9 . V_10 ) )
goto V_79;
#if F_103 ( V_165 )
} else {
if ( F_15 ( V_21 , V_463 , sizeof( struct V_16 ) ,
& V_314 -> V_66 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( V_314 -> V_85 && F_36 ( V_21 , V_466 , V_314 -> V_85 ) )
goto V_79;
if ( ! F_3 ( & V_46 -> V_214 ) ) {
if ( V_46 -> V_214 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_464 ,
V_46 -> V_214 . sin . V_9 . V_10 ) )
goto V_79;
#if F_103 ( V_165 )
} else {
if ( F_15 ( V_21 , V_465 , sizeof( struct V_16 ) ,
& V_46 -> V_214 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( F_294 ( V_21 , V_475 , V_46 -> V_316 ) ||
F_294 ( V_21 , V_474 , V_46 -> V_221 ) ||
F_294 ( V_21 , V_476 ,
! ! ( V_46 -> V_51 & V_219 ) ) ||
F_294 ( V_21 , V_479 ,
! ! ( V_46 -> V_51 & V_377 ) ) ||
F_294 ( V_21 , V_480 , ! ! ( V_46 -> V_51 & V_378 ) ) ||
F_294 ( V_21 , V_481 ,
! ! ( V_46 -> V_51 & V_380 ) ) ||
F_294 ( V_21 , V_482 ,
! ! ( V_46 -> V_51 & V_262 ) ) ||
F_36 ( V_21 , V_477 , V_46 -> V_387 ) ||
F_36 ( V_21 , V_483 , V_46 -> V_154 ) ||
F_35 ( V_21 , V_484 , V_46 -> V_82 ) ||
F_294 ( V_21 , V_485 ,
! ! ( V_46 -> V_51 & V_450 ) ) ||
F_294 ( V_21 , V_486 ,
! ! ( V_46 -> V_51 & V_444 ) ) ||
F_294 ( V_21 , V_487 ,
! ! ( V_46 -> V_51 & V_445 ) ) )
goto V_79;
if ( F_15 ( V_21 , V_427 , sizeof( V_492 ) , & V_492 ) )
goto V_79;
return 0 ;
V_79:
return - V_63 ;
}
static void F_295 ( struct V_31 * V_32 ,
struct V_101 * V_72 )
{
struct V_45 * V_46 , * V_40 ;
F_296 ( V_493 ) ;
F_97 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_314 = & V_46 -> V_47 ;
if ( V_314 -> V_85 == V_72 -> V_73 )
F_288 ( V_46 -> V_72 , & V_493 ) ;
}
F_297 ( & V_493 ) ;
}
static int F_298 ( struct V_494 * V_495 ,
unsigned long V_496 , void * V_497 )
{
struct V_101 * V_72 = F_299 ( V_497 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
if ( V_496 == V_498 )
F_295 ( V_32 , V_72 ) ;
return V_499 ;
}
static T_12 int F_300 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_176 ;
F_93 ( & V_32 -> V_490 ) ;
F_254 ( & V_32 -> V_187 ) ;
for ( V_176 = 0 ; V_176 < V_398 ; ++ V_176 )
F_258 ( & V_32 -> V_34 [ V_176 ] ) ;
return 0 ;
}
static void T_13 F_301 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 , * V_40 ;
struct V_101 * V_72 , * V_500 ;
F_296 ( V_41 ) ;
F_302 () ;
F_303 (net, dev, aux)
if ( V_72 -> V_501 == & V_502 )
F_291 ( V_72 , & V_41 ) ;
F_97 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_150 ( F_44 ( V_46 -> V_72 ) , V_29 ) )
F_291 ( V_72 , & V_41 ) ;
}
F_297 ( & V_41 ) ;
F_304 () ;
}
static int T_14 F_305 ( void )
{
int V_149 ;
V_188 = F_306 ( L_18 , 0 , 0 ) ;
if ( ! V_188 )
return - V_157 ;
F_307 ( & V_503 , sizeof( V_503 ) ) ;
V_149 = F_308 ( & V_504 ) ;
if ( V_149 )
goto V_505;
V_149 = F_309 ( & V_506 ) ;
if ( V_149 )
goto V_507;
V_149 = F_310 ( & V_502 ) ;
if ( V_149 )
goto V_508;
return 0 ;
V_508:
F_311 ( & V_506 ) ;
V_507:
F_312 ( & V_504 ) ;
V_505:
F_313 ( V_188 ) ;
return V_149 ;
}
static void T_15 F_314 ( void )
{
F_315 ( & V_502 ) ;
F_311 ( & V_506 ) ;
F_313 ( V_188 ) ;
F_312 ( & V_504 ) ;
}
