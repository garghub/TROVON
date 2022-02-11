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
struct V_101 * V_72 ,
struct V_101 * V_175 , int V_176 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_177 ;
for ( V_177 = 0 ; V_177 < V_178 ; ++ V_177 ) {
struct V_37 * V_102 ;
int V_96 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_95 ;
if ( V_176 < V_174 -> args [ 0 ] )
goto V_179;
F_116 (rd, &f->remotes, list) {
V_96 = F_31 ( V_21 , V_46 , V_102 ,
F_117 ( V_174 -> V_21 ) . V_49 ,
V_174 -> V_58 -> V_180 ,
V_159 ,
V_181 , V_95 ) ;
if ( V_96 < 0 )
goto V_128;
}
V_179:
++ V_176 ;
}
}
V_128:
return V_176 ;
}
static bool F_118 ( struct V_101 * V_72 ,
union V_1 * V_182 , const T_4 * V_183 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_37 * V_102 ;
V_102 = F_60 ( V_46 , V_183 ) ;
if ( F_119 ( V_102 ) ) {
struct V_36 * V_52 = F_22 ( V_102 ) ;
if ( F_119 ( F_1 ( & V_52 -> V_66 , V_182 ) ) )
return false ;
if ( V_102 -> V_70 & V_184 )
return true ;
if ( F_120 () )
F_121 ( V_72 ,
L_6 ,
V_183 , & V_52 -> V_66 , & V_182 ) ;
V_52 -> V_66 = * V_182 ;
V_102 -> V_91 = V_54 ;
F_43 ( V_46 , V_102 , V_52 , V_159 ) ;
} else {
F_122 ( & V_46 -> V_172 ) ;
if ( F_123 ( V_72 ) )
F_90 ( V_46 , V_183 , V_182 ,
V_171 ,
V_146 | V_152 ,
V_46 -> V_82 ,
V_46 -> V_47 . V_48 ,
0 , V_185 ) ;
F_124 ( & V_46 -> V_172 ) ;
}
return false ;
}
static bool F_125 ( struct V_31 * V_32 , struct V_45 * V_72 )
{
struct V_45 * V_46 ;
if ( F_126 ( & V_72 -> V_186 -> V_187 ) == 1 )
return false ;
F_62 (vxlan, &vn->vxlan_list, next) {
if ( ! F_123 ( V_46 -> V_72 ) || V_46 == V_72 )
continue;
if ( V_46 -> V_186 != V_72 -> V_186 )
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
F_128 ( & V_25 -> V_187 ) ;
}
void F_129 ( struct V_24 * V_25 )
{
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
struct V_29 * V_29 = F_84 ( V_43 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_130 ( & V_25 -> V_187 ) )
return;
F_122 ( & V_32 -> V_188 ) ;
F_100 ( & V_25 -> V_158 ) ;
F_131 ( V_25 -> V_42 -> V_43 , NULL ) ;
F_88 ( V_25 ) ;
F_124 ( & V_32 -> V_188 ) ;
F_132 ( V_189 , & V_25 -> V_190 ) ;
}
static void F_133 ( struct V_191 * V_192 )
{
struct V_45 * V_46 = F_96 ( V_192 , struct V_45 , V_193 ) ;
struct V_24 * V_25 = V_46 -> V_186 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_85 ;
F_134 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_194 V_195 = {
. V_196 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_197 = V_73 ,
} ;
F_135 ( V_43 , & V_195 ) ;
#if F_103 ( V_165 )
} else {
V_198 -> V_199 ( V_43 , V_73 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_136 ( V_43 ) ;
F_129 ( V_25 ) ;
F_137 ( V_46 -> V_72 ) ;
}
static void F_138 ( struct V_191 * V_192 )
{
struct V_45 * V_46 = F_96 ( V_192 , struct V_45 , V_200 ) ;
struct V_24 * V_25 = V_46 -> V_186 ;
struct V_42 * V_43 = V_25 -> V_42 -> V_43 ;
union V_1 * V_13 = & V_46 -> V_47 . V_66 ;
int V_73 = V_46 -> V_47 . V_85 ;
F_134 ( V_43 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_194 V_195 = {
. V_196 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_197 = V_73 ,
} ;
F_139 ( V_43 , & V_195 ) ;
#if F_103 ( V_165 )
} else {
V_198 -> V_201 ( V_43 , V_73 ,
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
struct V_116 * V_202 ;
if ( ! F_141 ( V_21 , V_203 ) )
goto error;
V_202 = (struct V_116 * ) ( F_142 ( V_21 ) + 1 ) ;
if ( V_202 -> V_204 != F_5 ( V_205 ) ||
( V_202 -> V_131 & F_5 ( 0xff ) ) ) {
F_91 ( V_21 -> V_72 , L_7 ,
F_9 ( V_202 -> V_204 ) , F_9 ( V_202 -> V_131 ) ) ;
goto error;
}
if ( F_143 ( V_21 , V_203 , F_144 ( V_206 ) ) )
goto V_207;
V_25 = F_145 ( V_43 ) ;
if ( ! V_25 )
goto V_207;
F_146 ( V_21 ) ;
V_25 -> V_208 ( V_25 , V_21 , V_202 -> V_131 ) ;
return 0 ;
V_207:
F_47 ( V_21 ) ;
return 0 ;
error:
return 1 ;
}
static void F_147 ( struct V_24 * V_25 ,
struct V_20 * V_21 , V_17 V_131 )
{
struct V_209 * V_210 = NULL ;
struct V_211 * V_212 = NULL ;
struct V_45 * V_46 ;
struct V_213 * V_214 ;
union V_1 V_215 ;
V_94 V_112 ;
int V_96 = 0 ;
union V_1 * V_66 ;
V_112 = F_9 ( V_131 ) >> 8 ;
V_46 = F_29 ( V_25 , V_112 ) ;
if ( ! V_46 )
goto V_207;
V_66 = & V_46 -> V_47 . V_66 ;
F_148 ( V_21 ) ;
F_149 ( V_21 , ! F_150 ( V_46 -> V_29 , F_44 ( V_46 -> V_72 ) ) ) ;
V_21 -> V_216 = F_151 ( V_21 , V_46 -> V_72 ) ;
F_152 ( V_21 , F_153 ( V_21 ) , V_217 ) ;
if ( F_59 ( F_153 ( V_21 ) -> V_218 , V_46 -> V_72 -> V_219 ) )
goto V_207;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_210 = F_154 ( V_21 ) ;
V_215 . sin . V_9 . V_10 = V_210 -> V_215 ;
V_215 . V_4 . V_5 = V_18 ;
#if F_103 ( V_165 )
} else {
V_212 = F_155 ( V_21 ) ;
V_215 . V_7 . V_8 = V_212 -> V_215 ;
V_215 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_46 -> V_51 & V_220 ) &&
F_118 ( V_21 -> V_72 , & V_215 , F_153 ( V_21 ) -> V_218 ) )
goto V_207;
F_156 ( V_21 ) ;
if ( V_212 )
V_96 = F_157 ( V_212 , V_21 ) ;
if ( V_210 )
V_96 = F_158 ( V_210 , V_21 ) ;
if ( F_73 ( V_96 ) ) {
if ( V_221 ) {
if ( V_212 )
F_159 ( L_8 ,
& V_212 -> V_215 ) ;
if ( V_210 )
F_159 ( L_9 ,
& V_210 -> V_215 , V_210 -> V_222 ) ;
}
if ( V_96 > 1 ) {
++ V_46 -> V_72 -> V_214 . V_223 ;
++ V_46 -> V_72 -> V_214 . V_224 ;
goto V_207;
}
}
V_214 = F_160 ( V_46 -> V_72 -> V_225 ) ;
F_161 ( & V_214 -> V_226 ) ;
V_214 -> V_227 ++ ;
V_214 -> V_228 += V_21 -> V_229 ;
F_162 ( & V_214 -> V_226 ) ;
F_163 ( V_21 ) ;
return;
V_207:
F_47 ( V_21 ) ;
}
static int F_164 ( struct V_101 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_230 * V_231 ;
T_4 * V_232 , * V_233 ;
V_17 V_234 , V_235 ;
struct V_236 * V_237 ;
if ( V_72 -> V_51 & V_238 )
goto V_128;
if ( ! F_141 ( V_21 , F_165 ( V_72 ) ) ) {
V_72 -> V_214 . V_239 ++ ;
goto V_128;
}
V_231 = F_166 ( V_21 ) ;
if ( ( V_231 -> V_240 != F_144 ( V_241 ) &&
V_231 -> V_240 != F_144 ( V_242 ) ) ||
V_231 -> V_243 != F_144 ( V_244 ) ||
V_231 -> V_245 != F_144 ( V_246 ) ||
V_231 -> V_247 != V_72 -> V_248 ||
V_231 -> V_249 != 4 )
goto V_128;
V_232 = ( T_4 * ) V_231 + sizeof( struct V_230 ) ;
V_233 = V_232 ;
V_232 += V_72 -> V_248 ;
memcpy ( & V_234 , V_232 , sizeof( V_234 ) ) ;
V_232 += sizeof( V_234 ) ;
V_232 += V_72 -> V_248 ;
memcpy ( & V_235 , V_232 , sizeof( V_235 ) ) ;
if ( F_167 ( V_235 ) ||
F_168 ( V_235 ) )
goto V_128;
V_237 = F_169 ( & V_250 , & V_235 , V_72 ) ;
if ( V_237 ) {
struct V_37 * V_102 ;
struct V_20 * V_251 ;
if ( ! ( V_237 -> V_252 & V_253 ) ) {
F_170 ( V_237 ) ;
goto V_128;
}
V_102 = F_60 ( V_46 , V_237 -> V_254 ) ;
if ( V_102 && F_3 ( & ( F_22 ( V_102 ) -> V_66 ) ) ) {
F_170 ( V_237 ) ;
goto V_128;
}
V_251 = F_171 ( V_255 , V_256 , V_234 , V_72 , V_235 , V_233 ,
V_237 -> V_254 , V_233 ) ;
F_170 ( V_237 ) ;
if ( V_251 == NULL )
goto V_128;
F_148 ( V_251 ) ;
F_172 ( V_251 , F_173 ( V_251 ) ) ;
V_251 -> V_257 = V_258 ;
V_251 -> V_259 = V_260 ;
if ( F_174 ( V_251 ) == V_261 )
V_72 -> V_214 . V_262 ++ ;
} else if ( V_46 -> V_51 & V_263 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_235 ,
. sin . V_264 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_128:
F_175 ( V_21 ) ;
return V_265 ;
}
static struct V_20 * F_176 ( struct V_20 * V_266 ,
struct V_236 * V_237 , bool V_267 )
{
struct V_101 * V_72 = V_266 -> V_72 ;
struct V_20 * V_251 ;
struct V_268 * V_269 , * V_270 ;
struct V_211 * V_271 ;
T_4 * V_272 ;
int V_273 = 8 ;
int V_274 ;
int V_275 , V_229 ;
if ( V_72 == NULL )
return NULL ;
V_229 = F_177 ( V_72 ) + sizeof( struct V_211 ) +
sizeof( * V_270 ) + V_273 + V_72 -> V_276 ;
V_251 = F_178 ( V_229 , V_98 ) ;
if ( V_251 == NULL )
return NULL ;
V_251 -> V_216 = F_144 ( V_277 ) ;
V_251 -> V_72 = V_72 ;
F_179 ( V_251 , F_177 ( V_266 -> V_72 ) ) ;
F_180 ( V_251 , sizeof( struct V_119 ) ) ;
F_181 ( V_251 , 0 ) ;
V_269 = (struct V_268 * ) F_182 ( V_266 ) ;
V_272 = F_153 ( V_266 ) -> V_218 ;
V_274 = V_266 -> V_229 - F_183 ( V_266 ) - sizeof( * V_269 ) ;
for ( V_275 = 0 ; V_275 < V_274 - 1 ; V_275 += ( V_269 -> V_278 [ V_275 + 1 ] << 3 ) ) {
if ( V_269 -> V_278 [ V_275 ] == V_279 ) {
V_272 = V_269 -> V_278 + V_275 + sizeof( struct V_280 ) ;
break;
}
}
F_184 ( F_153 ( V_251 ) -> V_281 , V_272 ) ;
F_184 ( F_153 ( V_251 ) -> V_218 , V_237 -> V_254 ) ;
F_153 ( V_251 ) -> V_132 = F_144 ( V_277 ) ;
V_251 -> V_216 = F_144 ( V_277 ) ;
F_185 ( V_251 , sizeof( struct V_119 ) ) ;
F_186 ( V_251 , 0 ) ;
F_187 ( V_251 , sizeof( struct V_211 ) ) ;
V_271 = F_155 ( V_251 ) ;
memset ( V_271 , 0 , sizeof( struct V_211 ) ) ;
V_271 -> V_282 = 6 ;
V_271 -> V_283 = F_155 ( V_266 ) -> V_283 ;
V_271 -> V_284 = V_285 ;
V_271 -> V_286 = 255 ;
V_271 -> V_272 = F_155 ( V_266 ) -> V_215 ;
V_271 -> V_215 = * (struct V_16 * ) V_237 -> V_287 ;
F_185 ( V_251 , sizeof( struct V_211 ) ) ;
F_188 ( V_251 , 0 ) ;
V_270 = (struct V_268 * ) F_187 ( V_251 , sizeof( * V_270 ) + V_273 ) ;
memset ( V_270 , 0 , sizeof( * V_270 ) + V_273 ) ;
V_270 -> V_288 . V_289 = V_290 ;
V_270 -> V_288 . V_291 = V_267 ;
V_270 -> V_288 . V_292 = 1 ;
V_270 -> V_288 . V_293 = 1 ;
V_270 -> V_294 = V_269 -> V_294 ;
F_184 ( & V_270 -> V_278 [ 2 ] , V_237 -> V_254 ) ;
V_270 -> V_278 [ 0 ] = V_295 ;
V_270 -> V_278 [ 1 ] = V_273 >> 3 ;
V_270 -> V_288 . V_296 = F_189 ( & V_271 -> V_215 ,
& V_271 -> V_272 , sizeof( * V_270 ) + V_273 , V_285 ,
F_190 ( V_270 , sizeof( * V_270 ) + V_273 , 0 ) ) ;
V_271 -> V_297 = F_144 ( sizeof( * V_270 ) + V_273 ) ;
F_180 ( V_251 , sizeof( struct V_211 ) ) ;
V_251 -> V_257 = V_258 ;
return V_251 ;
}
static int F_191 ( struct V_101 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_268 * V_298 ;
const struct V_211 * V_209 ;
const struct V_16 * V_215 , * V_272 ;
struct V_236 * V_237 ;
struct V_299 * V_300 ;
V_300 = F_192 ( V_72 ) ;
if ( ! V_300 )
goto V_128;
if ( ! F_141 ( V_21 , V_21 -> V_229 ) )
goto V_128;
V_209 = F_155 ( V_21 ) ;
V_215 = & V_209 -> V_215 ;
V_272 = & V_209 -> V_272 ;
V_298 = (struct V_268 * ) F_182 ( V_21 ) ;
if ( V_298 -> V_288 . V_301 != 0 ||
V_298 -> V_288 . V_289 != V_302 )
goto V_128;
if ( F_193 ( V_272 ) ||
F_7 ( & V_298 -> V_294 ) )
goto V_128;
V_237 = F_169 ( V_198 -> V_303 , & V_298 -> V_294 , V_72 ) ;
if ( V_237 ) {
struct V_37 * V_102 ;
struct V_20 * V_251 ;
if ( ! ( V_237 -> V_252 & V_253 ) ) {
F_170 ( V_237 ) ;
goto V_128;
}
V_102 = F_60 ( V_46 , V_237 -> V_254 ) ;
if ( V_102 && F_3 ( & ( F_22 ( V_102 ) -> V_66 ) ) ) {
F_170 ( V_237 ) ;
goto V_128;
}
V_251 = F_176 ( V_21 , V_237 ,
! ! ( V_102 ? V_102 -> V_51 & V_304 : 0 ) ) ;
F_170 ( V_237 ) ;
if ( V_251 == NULL )
goto V_128;
if ( F_174 ( V_251 ) == V_261 )
V_72 -> V_214 . V_262 ++ ;
} else if ( V_46 -> V_51 & V_263 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_298 -> V_294 ,
. V_7 . V_305 = V_6 ,
} ;
F_50 ( V_72 , & V_11 ) ;
}
V_128:
F_175 ( V_21 ) ;
return V_265 ;
}
static bool F_194 ( struct V_101 * V_72 , struct V_20 * V_21 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_236 * V_237 ;
if ( F_92 ( F_153 ( V_21 ) -> V_281 ) )
return false ;
V_237 = NULL ;
switch ( F_21 ( F_153 ( V_21 ) -> V_132 ) ) {
case V_244 :
{
struct V_209 * V_306 ;
if ( ! F_141 ( V_21 , sizeof( struct V_209 ) ) )
return false ;
V_306 = F_154 ( V_21 ) ;
V_237 = F_169 ( & V_250 , & V_306 -> V_272 , V_72 ) ;
if ( ! V_237 && ( V_46 -> V_51 & V_263 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_306 -> V_272 ,
. sin . V_264 = V_18 ,
} ;
F_50 ( V_72 , & V_11 ) ;
return false ;
}
break;
}
#if F_103 ( V_165 )
case V_277 :
{
struct V_211 * V_271 ;
if ( ! F_141 ( V_21 , sizeof( struct V_211 ) ) )
return false ;
V_271 = F_155 ( V_21 ) ;
V_237 = F_169 ( V_198 -> V_303 , & V_271 -> V_272 , V_72 ) ;
if ( ! V_237 && ( V_46 -> V_51 & V_263 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_271 -> V_272 ,
. V_7 . V_305 = V_6 ,
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
if ( V_237 ) {
bool V_307 ;
V_307 = ! F_59 ( F_153 ( V_21 ) -> V_281 , V_237 -> V_254 ) ;
if ( V_307 ) {
memcpy ( F_153 ( V_21 ) -> V_218 , F_153 ( V_21 ) -> V_281 ,
V_72 -> V_248 ) ;
memcpy ( F_153 ( V_21 ) -> V_281 , V_237 -> V_254 , V_72 -> V_248 ) ;
}
F_170 ( V_237 ) ;
return V_307 ;
}
return false ;
}
static inline struct V_20 * F_195 ( struct V_20 * V_21 ,
bool V_308 )
{
int type = V_308 ? V_309 : V_310 ;
return F_196 ( V_21 , V_308 , type ) ;
}
static int F_197 ( struct V_24 * V_25 ,
struct V_311 * V_312 , struct V_20 * V_21 ,
struct V_101 * V_72 , struct V_16 * V_215 ,
struct V_16 * V_272 , T_8 V_313 , T_8 V_314 ,
T_2 V_315 , T_2 V_82 , V_17 V_112 ,
bool V_316 )
{
struct V_211 * V_317 ;
struct V_116 * V_202 ;
struct V_318 * V_319 ;
int V_320 ;
int V_96 ;
V_21 = F_195 ( V_21 , ! F_198 ( V_25 -> V_42 -> V_43 ) ) ;
if ( F_199 ( V_21 ) )
return - V_167 ;
F_149 ( V_21 , V_316 ) ;
V_320 = F_177 ( V_312 -> V_72 ) + V_312 -> V_321
+ V_203 + sizeof( struct V_211 )
+ ( F_200 ( V_21 ) ? V_322 : 0 ) ;
V_96 = F_201 ( V_21 , V_320 ) ;
if ( F_73 ( V_96 ) )
return V_96 ;
if ( F_200 ( V_21 ) ) {
if ( F_46 ( ! F_202 ( V_21 ,
V_21 -> V_323 ,
F_203 ( V_21 ) ) ) )
return - V_157 ;
V_21 -> V_324 = 0 ;
}
V_202 = (struct V_116 * ) F_204 ( V_21 , sizeof( * V_202 ) ) ;
V_202 -> V_204 = F_5 ( V_205 ) ;
V_202 -> V_131 = V_112 ;
F_204 ( V_21 , sizeof( * V_319 ) ) ;
F_205 ( V_21 ) ;
V_319 = F_142 ( V_21 ) ;
V_319 -> V_325 = V_82 ;
V_319 -> V_326 = V_315 ;
V_319 -> V_229 = F_144 ( V_21 -> V_229 ) ;
memset ( & ( F_206 ( V_21 ) -> V_278 ) , 0 , sizeof( F_206 ( V_21 ) -> V_278 ) ) ;
F_206 ( V_21 ) -> V_51 &= ~ ( V_327 | V_328 |
V_329 ) ;
F_207 ( V_21 , V_312 ) ;
F_208 ( F_198 ( V_25 -> V_42 -> V_43 ) , V_21 ,
V_215 , V_272 , V_21 -> V_229 ) ;
F_204 ( V_21 , sizeof( * V_317 ) ) ;
F_156 ( V_21 ) ;
V_317 = F_155 ( V_21 ) ;
V_317 -> V_282 = 6 ;
V_317 -> V_283 = V_313 ;
V_317 -> V_330 [ 0 ] = 0 ;
V_317 -> V_330 [ 1 ] = 0 ;
V_317 -> V_330 [ 2 ] = 0 ;
V_317 -> V_297 = F_144 ( V_21 -> V_229 ) ;
V_317 -> V_284 = V_331 ;
V_317 -> V_286 = V_314 ;
V_317 -> V_272 = * V_272 ;
V_317 -> V_215 = * V_215 ;
F_209 ( V_21 , V_72 ) ;
return 0 ;
}
int F_210 ( struct V_24 * V_25 ,
struct V_332 * V_333 , struct V_20 * V_21 ,
V_17 V_334 , V_17 V_312 , T_8 V_222 , T_8 V_314 , T_2 V_335 ,
T_2 V_315 , T_2 V_82 , V_17 V_112 , bool V_316 )
{
struct V_116 * V_202 ;
struct V_318 * V_319 ;
int V_320 ;
int V_96 ;
V_21 = F_195 ( V_21 , ! V_25 -> V_42 -> V_43 -> V_336 ) ;
if ( F_199 ( V_21 ) )
return - V_167 ;
V_320 = F_177 ( V_333 -> V_312 . V_72 ) + V_333 -> V_312 . V_321
+ V_203 + sizeof( struct V_209 )
+ ( F_200 ( V_21 ) ? V_322 : 0 ) ;
V_96 = F_201 ( V_21 , V_320 ) ;
if ( F_73 ( V_96 ) )
return V_96 ;
if ( F_200 ( V_21 ) ) {
if ( F_46 ( ! F_202 ( V_21 ,
V_21 -> V_323 ,
F_203 ( V_21 ) ) ) )
return - V_157 ;
V_21 -> V_324 = 0 ;
}
V_202 = (struct V_116 * ) F_204 ( V_21 , sizeof( * V_202 ) ) ;
V_202 -> V_204 = F_5 ( V_205 ) ;
V_202 -> V_131 = V_112 ;
F_204 ( V_21 , sizeof( * V_319 ) ) ;
F_205 ( V_21 ) ;
V_319 = F_142 ( V_21 ) ;
V_319 -> V_325 = V_82 ;
V_319 -> V_326 = V_315 ;
V_319 -> V_229 = F_144 ( V_21 -> V_229 ) ;
F_211 ( V_25 -> V_42 -> V_43 -> V_336 , V_21 ,
V_334 , V_312 , V_21 -> V_229 ) ;
return F_212 ( V_25 -> V_42 -> V_43 , V_333 , V_21 , V_334 , V_312 , V_331 ,
V_222 , V_314 , V_335 , V_316 ) ;
}
static void F_213 ( struct V_20 * V_21 , struct V_45 * V_337 ,
struct V_45 * V_338 )
{
struct V_213 * V_339 , * V_340 ;
union V_1 V_341 ;
union V_1 * V_66 = & V_338 -> V_47 . V_66 ;
V_339 = F_160 ( V_337 -> V_72 -> V_225 ) ;
V_340 = F_160 ( V_338 -> V_72 -> V_225 ) ;
V_21 -> V_259 = V_260 ;
V_21 -> V_342 = 0 ;
V_21 -> V_72 = V_338 -> V_72 ;
F_172 ( V_21 , F_173 ( V_21 ) ) ;
if ( V_66 -> V_4 . V_5 == V_18 ) {
V_341 . sin . V_9 . V_10 = F_5 ( V_343 ) ;
V_341 . V_4 . V_5 = V_18 ;
#if F_103 ( V_165 )
} else {
V_341 . V_7 . V_8 = V_344 ;
V_341 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_338 -> V_51 & V_220 )
F_118 ( V_21 -> V_72 , & V_341 , F_153 ( V_21 ) -> V_218 ) ;
F_161 ( & V_339 -> V_226 ) ;
V_339 -> V_345 ++ ;
V_339 -> V_346 += V_21 -> V_229 ;
F_162 ( & V_339 -> V_226 ) ;
if ( F_163 ( V_21 ) == V_347 ) {
F_161 ( & V_340 -> V_226 ) ;
V_340 -> V_227 ++ ;
V_340 -> V_228 += V_21 -> V_229 ;
F_162 ( & V_340 -> V_226 ) ;
} else {
V_21 -> V_72 -> V_214 . V_262 ++ ;
}
}
static void F_214 ( struct V_20 * V_21 , struct V_101 * V_72 ,
struct V_36 * V_52 , bool V_348 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_332 * V_333 = NULL ;
const struct V_209 * V_349 ;
struct V_350 V_351 ;
union V_1 * V_312 ;
T_2 V_315 = 0 , V_82 ;
T_1 V_112 ;
T_2 V_335 = 0 ;
T_8 V_222 , V_314 ;
int V_96 ;
V_82 = V_52 -> V_81 ? V_52 -> V_81 : V_46 -> V_82 ;
V_112 = V_52 -> V_48 ;
V_312 = & V_52 -> V_66 ;
if ( F_3 ( V_312 ) ) {
if ( V_348 ) {
F_213 ( V_21 , V_46 , V_46 ) ;
return;
}
goto V_207;
}
V_349 = F_154 ( V_21 ) ;
V_314 = V_46 -> V_314 ;
if ( ! V_314 && F_6 ( V_312 ) )
V_314 = 1 ;
V_222 = V_46 -> V_222 ;
if ( V_222 == 1 )
V_222 = F_215 ( V_349 , V_21 ) ;
V_315 = F_216 ( F_44 ( V_72 ) , V_21 , V_46 -> V_352 ,
V_46 -> V_353 , true ) ;
if ( V_312 -> V_4 . V_5 == V_18 ) {
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
V_351 . V_354 = V_52 -> V_85 ;
V_351 . V_355 = F_217 ( V_222 ) ;
V_351 . V_272 = V_312 -> sin . V_9 . V_10 ;
V_351 . V_215 = V_46 -> V_215 . sin . V_9 . V_10 ;
V_333 = F_218 ( V_46 -> V_29 , & V_351 ) ;
if ( F_199 ( V_333 ) ) {
F_91 ( V_72 , L_10 ,
& V_312 -> sin . V_9 . V_10 ) ;
V_72 -> V_214 . V_356 ++ ;
goto V_357;
}
if ( V_333 -> V_312 . V_72 == V_72 ) {
F_91 ( V_72 , L_11 ,
& V_312 -> sin . V_9 . V_10 ) ;
V_72 -> V_214 . V_358 ++ ;
goto V_359;
}
if ( V_333 -> V_360 & V_361 &&
! ( V_333 -> V_360 & ( V_362 | V_363 ) ) ) {
struct V_45 * V_338 ;
F_219 ( V_333 ) ;
V_338 = F_30 ( V_46 -> V_29 , V_112 , V_82 ) ;
if ( ! V_338 )
goto V_357;
F_213 ( V_21 , V_46 , V_338 ) ;
return;
}
V_222 = F_220 ( V_222 , V_349 , V_21 ) ;
V_314 = V_314 ? : F_221 ( & V_333 -> V_312 ) ;
V_96 = F_210 ( V_46 -> V_186 , V_333 , V_21 ,
V_351 . V_215 , V_312 -> sin . V_9 . V_10 ,
V_222 , V_314 , V_335 , V_315 , V_82 ,
F_5 ( V_112 << 8 ) ,
! F_150 ( V_46 -> V_29 , F_44 ( V_46 -> V_72 ) ) ) ;
if ( V_96 < 0 )
goto V_359;
F_222 ( V_96 , & V_72 -> V_214 , V_72 -> V_225 ) ;
#if F_103 ( V_165 )
} else {
struct V_42 * V_43 = V_46 -> V_186 -> V_42 -> V_43 ;
struct V_311 * V_364 ;
struct V_365 V_366 ;
T_1 V_51 ;
memset ( & V_366 , 0 , sizeof( V_366 ) ) ;
V_366 . V_367 = V_52 -> V_85 ;
V_366 . V_272 = V_312 -> V_7 . V_8 ;
V_366 . V_215 = V_46 -> V_215 . V_7 . V_8 ;
V_366 . V_368 = V_331 ;
if ( V_198 -> V_369 ( V_43 , & V_364 , & V_366 ) ) {
F_91 ( V_72 , L_12 ,
& V_312 -> V_7 . V_8 ) ;
V_72 -> V_214 . V_356 ++ ;
goto V_357;
}
if ( V_364 -> V_72 == V_72 ) {
F_91 ( V_72 , L_13 ,
& V_312 -> V_7 . V_8 ) ;
F_223 ( V_364 ) ;
V_72 -> V_214 . V_358 ++ ;
goto V_357;
}
V_51 = ( (struct V_370 * ) V_364 ) -> V_371 ;
if ( V_51 & V_372 &&
! ( V_51 & ( V_362 | V_363 ) ) ) {
struct V_45 * V_338 ;
F_223 ( V_364 ) ;
V_338 = F_30 ( V_46 -> V_29 , V_112 , V_82 ) ;
if ( ! V_338 )
goto V_357;
F_213 ( V_21 , V_46 , V_338 ) ;
return;
}
V_314 = V_314 ? : F_224 ( V_364 ) ;
V_96 = F_197 ( V_46 -> V_186 , V_364 , V_21 ,
V_72 , & V_366 . V_215 , & V_366 . V_272 , 0 , V_314 ,
V_315 , V_82 , F_5 ( V_112 << 8 ) ,
! F_150 ( V_46 -> V_29 , F_44 ( V_46 -> V_72 ) ) ) ;
#endif
}
return;
V_207:
V_72 -> V_214 . V_239 ++ ;
goto V_373;
V_359:
F_219 ( V_333 ) ;
V_357:
V_72 -> V_214 . V_374 ++ ;
V_373:
F_225 ( V_21 ) ;
}
static T_10 F_226 ( struct V_20 * V_21 , struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_119 * V_375 ;
bool V_348 = false ;
struct V_36 * V_52 , * V_376 = NULL ;
struct V_37 * V_102 ;
F_148 ( V_21 ) ;
V_375 = F_153 ( V_21 ) ;
if ( ( V_46 -> V_51 & V_377 ) ) {
if ( F_21 ( V_375 -> V_132 ) == V_256 )
return F_164 ( V_72 , V_21 ) ;
#if F_103 ( V_165 )
else if ( F_21 ( V_375 -> V_132 ) == V_277 &&
V_21 -> V_229 >= sizeof( struct V_211 ) + sizeof( struct V_268 ) &&
F_155 ( V_21 ) -> V_284 == V_285 ) {
struct V_268 * V_298 ;
V_298 = (struct V_268 * ) F_182 ( V_21 ) ;
if ( V_298 -> V_288 . V_301 == 0 &&
V_298 -> V_288 . V_289 == V_302 )
return F_191 ( V_72 , V_21 ) ;
}
#endif
}
V_102 = F_60 ( V_46 , V_375 -> V_281 ) ;
V_348 = false ;
if ( V_102 && ( V_102 -> V_51 & V_304 ) && ( V_46 -> V_51 & V_378 ) &&
( F_21 ( V_375 -> V_132 ) == V_244 ||
F_21 ( V_375 -> V_132 ) == V_277 ) ) {
V_348 = F_194 ( V_72 , V_21 ) ;
if ( V_348 )
V_102 = F_60 ( V_46 , V_375 -> V_281 ) ;
}
if ( V_102 == NULL ) {
V_102 = F_60 ( V_46 , V_379 ) ;
if ( V_102 == NULL ) {
if ( ( V_46 -> V_51 & V_380 ) &&
! F_92 ( V_375 -> V_281 ) )
F_52 ( V_46 , V_375 -> V_281 ) ;
V_72 -> V_214 . V_239 ++ ;
F_47 ( V_21 ) ;
return V_265 ;
}
}
F_116 (rdst, &f->remotes, list) {
struct V_20 * V_381 ;
if ( ! V_376 ) {
V_376 = V_52 ;
continue;
}
V_381 = F_227 ( V_21 , V_98 ) ;
if ( V_381 )
F_214 ( V_381 , V_72 , V_52 , V_348 ) ;
}
if ( V_376 )
F_214 ( V_21 , V_72 , V_376 , V_348 ) ;
else
F_47 ( V_21 ) ;
return V_265 ;
}
static void F_228 ( unsigned long V_382 )
{
struct V_45 * V_46 = (struct V_45 * ) V_382 ;
unsigned long V_383 = V_54 + V_384 ;
unsigned int V_177 ;
if ( ! F_123 ( V_46 -> V_72 ) )
return;
F_109 ( & V_46 -> V_172 ) ;
for ( V_177 = 0 ; V_177 < V_178 ; ++ V_177 ) {
struct V_385 * V_114 , * V_237 ;
F_229 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_102
= F_96 ( V_114 , struct V_37 , V_158 ) ;
unsigned long V_386 ;
if ( V_102 -> V_70 & V_170 )
continue;
V_386 = V_102 -> V_88 + V_46 -> V_387 * V_388 ;
if ( F_230 ( V_386 , V_54 ) ) {
F_91 ( V_46 -> V_72 ,
L_14 ,
V_102 -> V_67 ) ;
V_102 -> V_70 = V_103 ;
F_99 ( V_46 , V_102 ) ;
} else if ( F_231 ( V_386 , V_383 ) )
V_383 = V_386 ;
}
}
F_110 ( & V_46 -> V_172 ) ;
F_232 ( & V_46 -> V_389 , V_383 ) ;
}
static void F_233 ( struct V_24 * V_25 , struct V_45 * V_46 )
{
V_94 V_112 = V_46 -> V_47 . V_48 ;
V_46 -> V_186 = V_25 ;
F_94 ( & V_46 -> V_158 , F_17 ( V_25 , V_112 ) ) ;
}
static int F_234 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_46 -> V_29 , V_33 ) ;
struct V_24 * V_25 ;
V_72 -> V_225 = F_235 ( struct V_213 ) ;
if ( ! V_72 -> V_225 )
return - V_157 ;
F_122 ( & V_32 -> V_188 ) ;
V_25 = F_26 ( V_46 -> V_29 , V_46 -> V_82 ) ;
if ( V_25 ) {
F_128 ( & V_25 -> V_187 ) ;
F_233 ( V_25 , V_46 ) ;
} else {
F_236 ( V_72 ) ;
F_132 ( V_189 , & V_46 -> V_390 ) ;
}
F_124 ( & V_32 -> V_188 ) ;
return 0 ;
}
static void F_237 ( struct V_45 * V_46 )
{
struct V_37 * V_102 ;
F_109 ( & V_46 -> V_172 ) ;
V_102 = F_58 ( V_46 , V_379 ) ;
if ( V_102 )
F_99 ( V_46 , V_102 ) ;
F_110 ( & V_46 -> V_172 ) ;
}
static void F_238 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_186 ;
F_237 ( V_46 ) ;
if ( V_25 )
F_129 ( V_25 ) ;
F_239 ( V_72 -> V_225 ) ;
}
static int F_240 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_24 * V_25 = V_46 -> V_186 ;
if ( ! V_25 )
return - V_391 ;
if ( F_6 ( & V_46 -> V_47 . V_66 ) ) {
F_127 ( V_25 ) ;
F_236 ( V_72 ) ;
F_132 ( V_189 , & V_46 -> V_193 ) ;
}
if ( V_46 -> V_387 )
F_232 ( & V_46 -> V_389 , V_54 + V_384 ) ;
return 0 ;
}
static void F_241 ( struct V_45 * V_46 )
{
unsigned int V_177 ;
F_109 ( & V_46 -> V_172 ) ;
for ( V_177 = 0 ; V_177 < V_178 ; ++ V_177 ) {
struct V_385 * V_114 , * V_237 ;
F_229 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_102
= F_96 ( V_114 , struct V_37 , V_158 ) ;
if ( ! F_34 ( V_102 -> V_67 ) )
F_99 ( V_46 , V_102 ) ;
}
}
F_110 ( & V_46 -> V_172 ) ;
}
static int F_242 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_46 -> V_29 , V_33 ) ;
struct V_24 * V_25 = V_46 -> V_186 ;
if ( V_25 && F_6 ( & V_46 -> V_47 . V_66 ) &&
! F_125 ( V_32 , V_46 ) ) {
F_127 ( V_25 ) ;
F_236 ( V_72 ) ;
F_132 ( V_189 , & V_46 -> V_200 ) ;
}
F_243 ( & V_46 -> V_389 ) ;
F_241 ( V_46 ) ;
return 0 ;
}
static void F_244 ( struct V_101 * V_72 )
{
}
static int F_245 ( struct V_101 * V_72 , int V_392 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_312 = & V_46 -> V_47 ;
struct V_101 * V_393 ;
int V_394 ;
V_393 = F_106 ( V_46 -> V_29 , V_312 -> V_85 ) ;
if ( V_393 == NULL )
return F_246 ( V_72 , V_392 ) ;
if ( V_312 -> V_66 . V_4 . V_5 == V_6 )
V_394 = V_393 -> V_395 - V_396 ;
else
V_394 = V_393 -> V_395 - V_397 ;
if ( V_392 < 68 || V_392 > V_394 )
return - V_167 ;
V_72 -> V_395 = V_392 ;
return 0 ;
}
void F_247 ( struct V_101 * V_72 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_44 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_6 V_5 ;
T_2 V_30 ;
unsigned int V_275 ;
F_122 ( & V_32 -> V_188 ) ;
for ( V_275 = 0 ; V_275 < V_398 ; ++ V_275 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_42 -> V_43 ) -> V_44 ;
V_5 = V_25 -> V_42 -> V_43 -> V_140 ;
V_72 -> V_142 -> V_143 ( V_72 , V_5 ,
V_30 ) ;
}
}
F_124 ( & V_32 -> V_188 ) ;
}
static void F_248 ( struct V_101 * V_72 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
unsigned int V_177 ;
F_249 ( V_72 ) ;
F_250 ( V_72 ) ;
if ( V_46 -> V_47 . V_66 . V_4 . V_5 == V_6 )
V_72 -> V_399 = V_217 + V_396 ;
else
V_72 -> V_399 = V_217 + V_397 ;
V_72 -> V_142 = & V_400 ;
V_72 -> V_401 = V_402 ;
F_251 ( V_72 , & V_403 ) ;
V_72 -> V_404 = 0 ;
V_72 -> V_405 |= V_406 ;
V_72 -> V_405 |= V_407 | V_408 ;
V_72 -> V_405 |= V_409 ;
V_72 -> V_405 |= V_410 ;
V_72 -> V_411 = V_72 -> V_405 ;
V_72 -> V_405 |= V_412 | V_413 ;
V_72 -> V_414 |= V_407 | V_408 | V_409 ;
V_72 -> V_414 |= V_410 ;
V_72 -> V_414 |= V_412 | V_413 ;
V_72 -> V_415 &= ~ V_416 ;
V_72 -> V_415 |= V_417 ;
F_93 ( & V_46 -> V_40 ) ;
F_252 ( & V_46 -> V_172 ) ;
F_253 ( & V_46 -> V_193 , F_133 ) ;
F_253 ( & V_46 -> V_200 , F_138 ) ;
F_253 ( & V_46 -> V_390 , V_418 ) ;
F_254 ( & V_46 -> V_389 ) ;
V_46 -> V_389 . V_419 = F_228 ;
V_46 -> V_389 . V_130 = ( unsigned long ) V_46 ;
V_46 -> V_82 = F_144 ( V_420 ) ;
V_46 -> V_72 = V_72 ;
for ( V_177 = 0 ; V_177 < V_178 ; ++ V_177 )
F_255 ( & V_46 -> V_110 [ V_177 ] ) ;
}
static int F_256 ( struct V_14 * V_164 [] , struct V_14 * V_130 [] )
{
if ( V_164 [ V_421 ] ) {
if ( F_11 ( V_164 [ V_421 ] ) != V_78 ) {
F_257 ( L_15 ) ;
return - V_167 ;
}
if ( ! F_258 ( F_259 ( V_164 [ V_421 ] ) ) ) {
F_257 ( L_16 ) ;
return - V_169 ;
}
}
if ( ! V_130 )
return - V_167 ;
if ( V_130 [ V_422 ] ) {
V_94 V_26 = F_105 ( V_130 [ V_422 ] ) ;
if ( V_26 >= V_423 )
return - V_424 ;
}
if ( V_130 [ V_425 ] ) {
const struct V_426 * V_114
= F_259 ( V_130 [ V_425 ] ) ;
if ( F_21 ( V_114 -> V_427 ) < F_21 ( V_114 -> V_428 ) ) {
F_257 ( L_17 ,
F_21 ( V_114 -> V_428 ) , F_21 ( V_114 -> V_427 ) ) ;
return - V_167 ;
}
}
return 0 ;
}
static void F_260 ( struct V_101 * V_429 ,
struct V_430 * V_431 )
{
F_261 ( V_431 -> V_282 , V_432 , sizeof( V_431 -> V_282 ) ) ;
F_261 ( V_431 -> V_433 , L_18 , sizeof( V_431 -> V_433 ) ) ;
}
static void F_262 ( struct V_191 * V_192 )
{
struct V_24 * V_25 = F_96 ( V_192 , struct V_24 , V_190 ) ;
F_263 ( V_25 -> V_42 -> V_43 ) ;
F_114 ( V_25 , V_161 ) ;
}
static struct V_434 * F_264 ( struct V_29 * V_29 , bool V_435 ,
T_2 V_30 , T_1 V_51 )
{
struct V_434 * V_42 ;
struct V_436 V_437 ;
int V_96 ;
memset ( & V_437 , 0 , sizeof( V_437 ) ) ;
if ( V_435 ) {
V_437 . V_438 = V_6 ;
V_437 . V_439 =
! ! ( V_51 & V_440 ) ;
V_437 . V_441 =
! ! ( V_51 & V_442 ) ;
} else {
V_437 . V_438 = V_18 ;
V_437 . V_443 . V_10 = V_12 ;
V_437 . V_444 =
! ! ( V_51 & V_445 ) ;
}
V_437 . V_446 = V_30 ;
V_96 = F_265 ( V_29 , & V_437 , & V_42 ) ;
if ( V_96 < 0 )
return F_266 ( V_96 ) ;
F_28 ( V_42 -> V_43 ) -> V_447 = 0 ;
return V_42 ;
}
static struct V_24 * F_267 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_208 , void * V_130 ,
T_1 V_51 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_434 * V_42 ;
struct V_42 * V_43 ;
unsigned int V_177 ;
bool V_435 = ! ! ( V_51 & V_448 ) ;
V_25 = F_268 ( sizeof( * V_25 ) , V_449 ) ;
if ( ! V_25 )
return F_266 ( - V_157 ) ;
for ( V_177 = 0 ; V_177 < V_450 ; ++ V_177 )
F_255 ( & V_25 -> V_27 [ V_177 ] ) ;
F_253 ( & V_25 -> V_190 , F_262 ) ;
V_42 = F_264 ( V_29 , V_435 , V_30 , V_51 ) ;
if ( F_199 ( V_42 ) ) {
F_98 ( V_25 ) ;
return F_269 ( V_42 ) ;
}
V_25 -> V_42 = V_42 ;
V_43 = V_42 -> V_43 ;
F_270 ( & V_25 -> V_187 , 1 ) ;
V_25 -> V_208 = V_208 ;
V_25 -> V_130 = V_130 ;
F_131 ( V_25 -> V_42 -> V_43 , V_25 ) ;
V_25 -> V_141 . V_30 = V_30 ;
V_25 -> V_141 . V_134 . V_135 = F_68 ;
V_25 -> V_141 . V_134 . V_139 = F_81 ;
F_122 ( & V_32 -> V_188 ) ;
F_94 ( & V_25 -> V_158 , F_19 ( V_29 , V_30 ) ) ;
F_83 ( V_25 ) ;
F_124 ( & V_32 -> V_188 ) ;
F_271 ( V_43 ) -> V_451 = 1 ;
F_271 ( V_43 ) -> V_452 = F_140 ;
#if F_103 ( V_165 )
if ( V_435 )
V_198 -> V_453 () ;
else
#endif
F_272 () ;
return V_25 ;
}
struct V_24 * F_273 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_208 , void * V_130 ,
bool V_454 , T_1 V_51 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
V_25 = F_267 ( V_29 , V_30 , V_208 , V_130 , V_51 ) ;
if ( ! F_199 ( V_25 ) )
return V_25 ;
if ( V_454 )
return V_25 ;
F_122 ( & V_32 -> V_188 ) ;
V_25 = F_26 ( V_29 , V_30 ) ;
if ( V_25 ) {
if ( V_25 -> V_208 == V_208 )
F_128 ( & V_25 -> V_187 ) ;
else
V_25 = F_266 ( - V_455 ) ;
}
F_124 ( & V_32 -> V_188 ) ;
if ( ! V_25 )
V_25 = F_266 ( - V_167 ) ;
return V_25 ;
}
static void V_418 ( struct V_191 * V_192 )
{
struct V_45 * V_46 = F_96 ( V_192 , struct V_45 , V_390 ) ;
struct V_29 * V_29 = V_46 -> V_29 ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_46 -> V_82 ;
struct V_24 * V_456 ;
V_456 = F_273 ( V_29 , V_30 , F_147 , NULL , false , V_46 -> V_51 ) ;
F_122 ( & V_32 -> V_188 ) ;
if ( ! F_199 ( V_456 ) )
F_233 ( V_456 , V_46 ) ;
F_124 ( & V_32 -> V_188 ) ;
F_137 ( V_46 -> V_72 ) ;
}
static int F_274 ( struct V_29 * V_29 , struct V_101 * V_72 ,
struct V_14 * V_164 [] , struct V_14 * V_130 [] )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_36 * V_312 = & V_46 -> V_47 ;
V_94 V_112 ;
int V_96 ;
bool V_457 = false ;
if ( ! V_130 [ V_422 ] )
return - V_167 ;
V_46 -> V_29 = F_44 ( V_72 ) ;
V_112 = F_105 ( V_130 [ V_422 ] ) ;
V_312 -> V_48 = V_112 ;
V_312 -> V_66 . V_4 . V_5 = V_18 ;
if ( V_130 [ V_458 ] ) {
V_312 -> V_66 . sin . V_9 . V_10 = F_13 ( V_130 [ V_458 ] ) ;
} else if ( V_130 [ V_459 ] ) {
if ( ! F_103 ( V_165 ) )
return - V_460 ;
F_12 ( & V_312 -> V_66 . V_7 . V_8 , V_130 [ V_459 ] ,
sizeof( struct V_16 ) ) ;
V_312 -> V_66 . V_4 . V_5 = V_6 ;
V_457 = true ;
}
if ( V_130 [ V_461 ] ) {
V_46 -> V_215 . sin . V_9 . V_10 = F_13 ( V_130 [ V_461 ] ) ;
V_46 -> V_215 . V_4 . V_5 = V_18 ;
} else if ( V_130 [ V_462 ] ) {
if ( ! F_103 ( V_165 ) )
return - V_460 ;
F_12 ( & V_46 -> V_215 . V_7 . V_8 , V_130 [ V_462 ] ,
sizeof( struct V_16 ) ) ;
V_46 -> V_215 . V_4 . V_5 = V_6 ;
V_457 = true ;
}
if ( V_130 [ V_463 ] &&
( V_312 -> V_85 = F_105 ( V_130 [ V_463 ] ) ) ) {
struct V_101 * V_393
= F_106 ( V_29 , V_312 -> V_85 ) ;
if ( ! V_393 ) {
F_108 ( L_19 , V_312 -> V_85 ) ;
return - V_464 ;
}
#if F_103 ( V_165 )
if ( V_457 ) {
struct V_299 * V_465 = F_192 ( V_393 ) ;
if ( V_465 && V_465 -> V_466 . V_467 ) {
F_108 ( L_20 ) ;
return - V_468 ;
}
V_46 -> V_51 |= V_448 ;
}
#endif
if ( ! V_164 [ V_469 ] )
V_72 -> V_395 = V_393 -> V_395 - ( V_457 ? V_396 : V_397 ) ;
V_72 -> V_399 = V_393 -> V_470 +
( V_457 ? V_396 : V_397 ) ;
} else if ( V_457 )
V_46 -> V_51 |= V_448 ;
if ( V_130 [ V_471 ] )
V_46 -> V_222 = F_275 ( V_130 [ V_471 ] ) ;
if ( V_130 [ V_472 ] )
V_46 -> V_314 = F_275 ( V_130 [ V_472 ] ) ;
if ( ! V_130 [ V_473 ] || F_275 ( V_130 [ V_473 ] ) )
V_46 -> V_51 |= V_220 ;
if ( V_130 [ V_474 ] )
V_46 -> V_387 = F_105 ( V_130 [ V_474 ] ) ;
else
V_46 -> V_387 = V_475 ;
if ( V_130 [ V_476 ] && F_275 ( V_130 [ V_476 ] ) )
V_46 -> V_51 |= V_377 ;
if ( V_130 [ V_477 ] && F_275 ( V_130 [ V_477 ] ) )
V_46 -> V_51 |= V_378 ;
if ( V_130 [ V_478 ] && F_275 ( V_130 [ V_478 ] ) )
V_46 -> V_51 |= V_380 ;
if ( V_130 [ V_479 ] && F_275 ( V_130 [ V_479 ] ) )
V_46 -> V_51 |= V_263 ;
if ( V_130 [ V_480 ] )
V_46 -> V_154 = F_105 ( V_130 [ V_480 ] ) ;
if ( V_130 [ V_425 ] ) {
const struct V_426 * V_114
= F_259 ( V_130 [ V_425 ] ) ;
V_46 -> V_352 = F_21 ( V_114 -> V_428 ) ;
V_46 -> V_353 = F_21 ( V_114 -> V_427 ) ;
}
if ( V_130 [ V_481 ] )
V_46 -> V_82 = F_104 ( V_130 [ V_481 ] ) ;
if ( V_130 [ V_482 ] && F_275 ( V_130 [ V_482 ] ) )
V_46 -> V_51 |= V_445 ;
if ( V_130 [ V_483 ] &&
F_275 ( V_130 [ V_483 ] ) )
V_46 -> V_51 |= V_440 ;
if ( V_130 [ V_484 ] &&
F_275 ( V_130 [ V_484 ] ) )
V_46 -> V_51 |= V_442 ;
if ( F_30 ( V_29 , V_112 , V_46 -> V_82 ) ) {
F_108 ( L_21 , V_112 ) ;
return - V_147 ;
}
V_72 -> V_485 = & V_486 ;
if ( ! F_3 ( & V_46 -> V_47 . V_66 ) ) {
V_96 = F_90 ( V_46 , V_379 ,
& V_46 -> V_47 . V_66 ,
V_171 | V_170 ,
V_146 | V_152 ,
V_46 -> V_82 ,
V_46 -> V_47 . V_48 ,
V_46 -> V_47 . V_85 ,
V_185 ) ;
if ( V_96 )
return V_96 ;
}
V_96 = F_276 ( V_72 ) ;
if ( V_96 ) {
F_237 ( V_46 ) ;
return V_96 ;
}
F_277 ( & V_46 -> V_40 , & V_32 -> V_487 ) ;
return 0 ;
}
static void F_278 ( struct V_101 * V_72 , struct V_488 * V_111 )
{
struct V_45 * V_46 = F_51 ( V_72 ) ;
struct V_31 * V_32 = F_20 ( V_46 -> V_29 , V_33 ) ;
F_122 ( & V_32 -> V_188 ) ;
if ( ! F_279 ( & V_46 -> V_158 ) )
F_100 ( & V_46 -> V_158 ) ;
F_124 ( & V_32 -> V_188 ) ;
F_280 ( & V_46 -> V_40 ) ;
F_281 ( V_72 , V_111 ) ;
}
static T_3 F_282 ( const struct V_101 * V_72 )
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
F_42 ( sizeof( struct V_426 ) ) +
F_42 ( sizeof( T_2 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
0 ;
}
static int F_283 ( struct V_20 * V_21 , const struct V_101 * V_72 )
{
const struct V_45 * V_46 = F_51 ( V_72 ) ;
const struct V_36 * V_312 = & V_46 -> V_47 ;
struct V_426 V_489 = {
. V_428 = F_144 ( V_46 -> V_352 ) ,
. V_427 = F_144 ( V_46 -> V_353 ) ,
} ;
if ( F_36 ( V_21 , V_422 , V_312 -> V_48 ) )
goto V_79;
if ( ! F_3 ( & V_312 -> V_66 ) ) {
if ( V_312 -> V_66 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_458 ,
V_312 -> V_66 . sin . V_9 . V_10 ) )
goto V_79;
#if F_103 ( V_165 )
} else {
if ( F_15 ( V_21 , V_459 , sizeof( struct V_16 ) ,
& V_312 -> V_66 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( V_312 -> V_85 && F_36 ( V_21 , V_463 , V_312 -> V_85 ) )
goto V_79;
if ( ! F_3 ( & V_46 -> V_215 ) ) {
if ( V_46 -> V_215 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_461 ,
V_46 -> V_215 . sin . V_9 . V_10 ) )
goto V_79;
#if F_103 ( V_165 )
} else {
if ( F_15 ( V_21 , V_462 , sizeof( struct V_16 ) ,
& V_46 -> V_215 . V_7 . V_8 ) )
goto V_79;
#endif
}
}
if ( F_284 ( V_21 , V_472 , V_46 -> V_314 ) ||
F_284 ( V_21 , V_471 , V_46 -> V_222 ) ||
F_284 ( V_21 , V_473 ,
! ! ( V_46 -> V_51 & V_220 ) ) ||
F_284 ( V_21 , V_476 ,
! ! ( V_46 -> V_51 & V_377 ) ) ||
F_284 ( V_21 , V_477 , ! ! ( V_46 -> V_51 & V_378 ) ) ||
F_284 ( V_21 , V_478 ,
! ! ( V_46 -> V_51 & V_380 ) ) ||
F_284 ( V_21 , V_479 ,
! ! ( V_46 -> V_51 & V_263 ) ) ||
F_36 ( V_21 , V_474 , V_46 -> V_387 ) ||
F_36 ( V_21 , V_480 , V_46 -> V_154 ) ||
F_35 ( V_21 , V_481 , V_46 -> V_82 ) ||
F_284 ( V_21 , V_482 ,
! ! ( V_46 -> V_51 & V_445 ) ) ||
F_284 ( V_21 , V_483 ,
! ! ( V_46 -> V_51 & V_440 ) ) ||
F_284 ( V_21 , V_484 ,
! ! ( V_46 -> V_51 & V_442 ) ) )
goto V_79;
if ( F_15 ( V_21 , V_425 , sizeof( V_489 ) , & V_489 ) )
goto V_79;
return 0 ;
V_79:
return - V_63 ;
}
static void F_285 ( struct V_31 * V_32 ,
struct V_101 * V_72 )
{
struct V_45 * V_46 , * V_40 ;
F_286 ( V_490 ) ;
F_97 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_312 = & V_46 -> V_47 ;
if ( V_312 -> V_85 == V_72 -> V_73 )
F_278 ( V_46 -> V_72 , & V_490 ) ;
}
F_287 ( & V_490 ) ;
}
static int F_288 ( struct V_491 * V_492 ,
unsigned long V_493 , void * V_494 )
{
struct V_101 * V_72 = F_289 ( V_494 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_72 ) , V_33 ) ;
if ( V_493 == V_495 )
F_285 ( V_32 , V_72 ) ;
return V_496 ;
}
static T_12 int F_290 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_177 ;
F_93 ( & V_32 -> V_487 ) ;
F_252 ( & V_32 -> V_188 ) ;
for ( V_177 = 0 ; V_177 < V_398 ; ++ V_177 )
F_255 ( & V_32 -> V_34 [ V_177 ] ) ;
return 0 ;
}
static void T_13 F_291 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_45 * V_46 , * V_40 ;
struct V_101 * V_72 , * V_497 ;
F_286 ( V_41 ) ;
F_292 () ;
F_293 (net, dev, aux)
if ( V_72 -> V_498 == & V_499 )
F_281 ( V_72 , & V_41 ) ;
F_97 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_150 ( F_44 ( V_46 -> V_72 ) , V_29 ) )
F_281 ( V_72 , & V_41 ) ;
}
F_287 ( & V_41 ) ;
F_294 () ;
}
static int T_14 F_295 ( void )
{
int V_149 ;
V_189 = F_296 ( L_18 , 0 , 0 ) ;
if ( ! V_189 )
return - V_157 ;
F_297 ( & V_500 , sizeof( V_500 ) ) ;
V_149 = F_298 ( & V_501 ) ;
if ( V_149 )
goto V_502;
V_149 = F_299 ( & V_503 ) ;
if ( V_149 )
goto V_504;
V_149 = F_300 ( & V_499 ) ;
if ( V_149 )
goto V_505;
return 0 ;
V_505:
F_301 ( & V_503 ) ;
V_504:
F_302 ( & V_501 ) ;
V_502:
F_303 ( V_189 ) ;
return V_149 ;
}
static void T_15 F_304 ( void )
{
F_305 ( & V_499 ) ;
F_301 ( & V_503 ) ;
F_303 ( V_189 ) ;
F_302 ( & V_501 ) ;
}
