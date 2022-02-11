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
static struct V_24 * F_26 ( struct V_29 * V_29 ,
T_3 V_42 , T_2 V_30 )
{
struct V_24 * V_25 ;
F_27 (vs, vs_head(net, port), hlist) {
if ( F_28 ( V_25 -> V_43 -> V_44 ) -> V_45 == V_30 &&
F_28 ( V_25 -> V_43 -> V_44 ) -> V_44 . V_46 == V_42 )
return V_25 ;
}
return NULL ;
}
static struct V_47 * F_29 ( struct V_24 * V_25 , T_1 V_26 )
{
struct V_47 * V_48 ;
F_27 (vxlan, vni_head(vs, id), hlist) {
if ( V_48 -> V_49 . V_50 == V_26 )
return V_48 ;
}
return NULL ;
}
static struct V_47 * F_30 ( struct V_29 * V_29 , T_1 V_26 ,
T_3 V_42 , T_2 V_30 )
{
struct V_24 * V_25 ;
V_25 = F_26 ( V_29 , V_42 , V_30 ) ;
if ( ! V_25 )
return NULL ;
return F_29 ( V_25 , V_26 ) ;
}
static int F_31 ( struct V_20 * V_21 , struct V_47 * V_48 ,
const struct V_37 * V_38 ,
T_1 V_51 , T_1 V_52 , int type , unsigned int V_53 ,
const struct V_36 * V_54 )
{
unsigned long V_55 = V_56 ;
struct V_57 V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
bool V_63 , V_64 ;
V_60 = F_32 ( V_21 , V_51 , V_52 , type , sizeof( * V_62 ) , V_53 ) ;
if ( V_60 == NULL )
return - V_65 ;
V_62 = F_33 ( V_60 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_64 = V_63 = true ;
if ( type == V_66 ) {
V_62 -> V_67 = V_18 ;
V_63 = ! F_3 ( & V_54 -> V_68 ) ;
V_64 = ! F_34 ( V_38 -> V_69 ) ;
} else
V_62 -> V_67 = V_70 ;
V_62 -> V_71 = V_38 -> V_72 ;
V_62 -> V_73 = V_48 -> V_74 -> V_75 ;
V_62 -> V_76 = V_38 -> V_53 ;
V_62 -> V_77 = V_78 ;
if ( V_64 && F_15 ( V_21 , V_79 , V_80 , & V_38 -> V_69 ) )
goto V_81;
if ( V_63 && F_14 ( V_21 , V_82 , & V_54 -> V_68 ) )
goto V_81;
if ( V_54 -> V_83 && V_54 -> V_83 != V_48 -> V_84 &&
F_35 ( V_21 , V_85 , V_54 -> V_83 ) )
goto V_81;
if ( V_54 -> V_50 != V_48 -> V_49 . V_50 &&
F_36 ( V_21 , V_86 , V_54 -> V_50 ) )
goto V_81;
if ( V_54 -> V_87 &&
F_36 ( V_21 , V_88 , V_54 -> V_87 ) )
goto V_81;
V_58 . V_89 = F_37 ( V_55 - V_38 -> V_90 ) ;
V_58 . V_91 = 0 ;
V_58 . V_92 = F_37 ( V_55 - V_38 -> V_93 ) ;
V_58 . V_94 = 0 ;
if ( F_15 ( V_21 , V_95 , sizeof( V_58 ) , & V_58 ) )
goto V_81;
return F_38 ( V_21 , V_60 ) ;
V_81:
F_39 ( V_21 , V_60 ) ;
return - V_65 ;
}
static inline T_4 F_40 ( void )
{
return F_41 ( sizeof( struct V_61 ) )
+ F_42 ( V_80 )
+ F_42 ( sizeof( struct V_16 ) )
+ F_42 ( sizeof( T_2 ) )
+ F_42 ( sizeof( V_17 ) )
+ F_42 ( sizeof( V_96 ) )
+ F_42 ( sizeof( struct V_57 ) ) ;
}
static void F_43 ( struct V_47 * V_48 , struct V_37 * V_38 ,
struct V_36 * V_97 , int type )
{
struct V_29 * V_29 = F_44 ( V_48 -> V_74 ) ;
struct V_20 * V_21 ;
int V_98 = - V_99 ;
V_21 = F_45 ( F_40 () , V_100 ) ;
if ( V_21 == NULL )
goto V_101;
V_98 = F_31 ( V_21 , V_48 , V_38 , 0 , 0 , type , 0 , V_97 ) ;
if ( V_98 < 0 ) {
F_46 ( V_98 == - V_65 ) ;
F_47 ( V_21 ) ;
goto V_101;
}
F_48 ( V_21 , V_29 , 0 , V_102 , NULL , V_100 ) ;
return;
V_101:
if ( V_98 < 0 )
F_49 ( V_29 , V_102 , V_98 ) ;
}
static void F_50 ( struct V_103 * V_74 , union V_1 * V_11 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_37 V_104 = {
. V_72 = V_105 ,
} ;
struct V_36 V_106 = {
. V_68 = * V_11 ,
. V_50 = V_107 ,
} ;
F_43 ( V_48 , & V_104 , & V_106 , V_66 ) ;
}
static void F_52 ( struct V_47 * V_48 , const T_5 V_69 [ V_80 ] )
{
struct V_37 V_104 = {
. V_72 = V_105 ,
} ;
struct V_36 V_106 = { } ;
memcpy ( V_104 . V_69 , V_69 , V_80 ) ;
F_43 ( V_48 , & V_104 , & V_106 , V_66 ) ;
}
static T_1 F_53 ( const unsigned char * V_108 )
{
T_6 V_109 = F_54 ( ( T_6 * ) V_108 ) ;
#ifdef F_55
V_109 >>= 16 ;
#else
V_109 <<= 16 ;
#endif
return F_56 ( V_109 , V_110 ) ;
}
static inline struct V_23 * F_57 ( struct V_47 * V_48 ,
const T_5 * V_111 )
{
return & V_48 -> V_112 [ F_53 ( V_111 ) ] ;
}
static struct V_37 * F_58 ( struct V_47 * V_48 ,
const T_5 * V_111 )
{
struct V_23 * V_113 = F_57 ( V_48 , V_111 ) ;
struct V_37 * V_104 ;
F_27 (f, head, hlist) {
if ( F_59 ( V_111 , V_104 -> V_69 ) )
return V_104 ;
}
return NULL ;
}
static struct V_37 * F_60 ( struct V_47 * V_48 ,
const T_5 * V_111 )
{
struct V_37 * V_104 ;
V_104 = F_58 ( V_48 , V_111 ) ;
if ( V_104 )
V_104 -> V_90 = V_56 ;
return V_104 ;
}
static struct V_36 * F_61 ( struct V_37 * V_104 ,
union V_1 * V_13 , T_2 V_30 ,
V_96 V_114 , V_96 V_75 )
{
struct V_36 * V_97 ;
F_62 (rd, &f->remotes, list) {
if ( F_1 ( & V_97 -> V_68 , V_13 ) &&
V_97 -> V_83 == V_30 &&
V_97 -> V_50 == V_114 &&
V_97 -> V_87 == V_75 )
return V_97 ;
}
return NULL ;
}
static int F_63 ( struct V_37 * V_104 ,
union V_1 * V_13 , T_2 V_30 , V_96 V_114 , V_96 V_75 )
{
struct V_36 * V_97 ;
V_97 = F_61 ( V_104 , V_13 , V_30 , V_114 , V_75 ) ;
if ( V_97 )
return 0 ;
V_97 = F_64 ( & V_104 -> V_39 , struct V_36 , V_41 ) ;
if ( ! V_97 )
return 0 ;
V_97 -> V_68 = * V_13 ;
V_97 -> V_83 = V_30 ;
V_97 -> V_50 = V_114 ;
V_97 -> V_87 = V_75 ;
return 1 ;
}
static int F_65 ( struct V_37 * V_104 ,
union V_1 * V_13 , T_2 V_30 , V_96 V_114 ,
V_96 V_75 , struct V_36 * * V_115 )
{
struct V_36 * V_97 ;
V_97 = F_61 ( V_104 , V_13 , V_30 , V_114 , V_75 ) ;
if ( V_97 )
return 0 ;
V_97 = F_66 ( sizeof( * V_97 ) , V_100 ) ;
if ( V_97 == NULL )
return - V_99 ;
V_97 -> V_68 = * V_13 ;
V_97 -> V_83 = V_30 ;
V_97 -> V_50 = V_114 ;
V_97 -> V_87 = V_75 ;
F_67 ( & V_97 -> V_41 , & V_104 -> V_39 ) ;
* V_115 = V_97 ;
return 1 ;
}
static struct V_20 * * F_68 ( struct V_20 * * V_113 , struct V_20 * V_21 )
{
struct V_20 * V_116 , * * V_117 = NULL ;
struct V_118 * V_119 , * V_120 ;
struct V_121 * V_122 , * V_123 ;
unsigned int V_124 , V_125 , V_126 ;
const struct V_127 * V_128 ;
T_2 type ;
int V_129 = 1 ;
V_125 = F_69 ( V_21 ) ;
V_124 = V_125 + sizeof( * V_119 ) ;
V_119 = F_70 ( V_21 , V_125 ) ;
if ( F_71 ( V_21 , V_124 ) ) {
V_119 = F_72 ( V_21 , V_124 , V_125 ) ;
if ( F_73 ( ! V_119 ) )
goto V_130;
}
F_74 ( V_21 , sizeof( struct V_118 ) ) ;
F_75 ( V_21 , V_119 , sizeof( struct V_118 ) ) ;
V_126 = F_69 ( V_21 ) ;
V_124 = V_126 + sizeof( * V_122 ) ;
V_122 = F_70 ( V_21 , V_126 ) ;
if ( F_71 ( V_21 , V_124 ) ) {
V_122 = F_72 ( V_21 , V_124 , V_126 ) ;
if ( F_73 ( ! V_122 ) )
goto V_130;
}
V_129 = 0 ;
for ( V_116 = * V_113 ; V_116 ; V_116 = V_116 -> V_40 ) {
if ( ! F_76 ( V_116 ) -> V_131 )
continue;
V_120 = (struct V_118 * ) ( V_116 -> V_132 + V_125 ) ;
V_123 = (struct V_121 * ) ( V_116 -> V_132 + V_126 ) ;
if ( V_119 -> V_133 != V_120 -> V_133 || F_77 ( V_122 , V_123 ) ) {
F_76 ( V_116 ) -> V_131 = 0 ;
continue;
}
}
type = V_122 -> V_134 ;
F_78 () ;
V_128 = F_79 ( type ) ;
if ( V_128 == NULL ) {
V_129 = 1 ;
goto V_135;
}
F_74 ( V_21 , sizeof( * V_122 ) ) ;
F_75 ( V_21 , V_122 , sizeof( * V_122 ) ) ;
V_117 = V_128 -> V_136 . V_137 ( V_113 , V_21 ) ;
V_135:
F_80 () ;
V_130:
F_76 ( V_21 ) -> V_129 |= V_129 ;
return V_117 ;
}
static int F_81 ( struct V_20 * V_21 , int V_138 )
{
struct V_121 * V_122 ;
struct V_127 * V_128 ;
T_2 type ;
int V_139 = sizeof( struct V_118 ) + sizeof( struct V_121 ) ;
int V_98 = - V_140 ;
F_82 ( V_21 , V_138 ) ;
V_122 = (struct V_121 * ) ( V_21 -> V_132 + V_138 + sizeof( struct V_118 ) ) ;
type = V_122 -> V_134 ;
F_78 () ;
V_128 = F_83 ( type ) ;
if ( V_128 != NULL )
V_98 = V_128 -> V_136 . V_141 ( V_21 , V_138 + V_139 ) ;
F_80 () ;
return V_98 ;
}
static void F_84 ( struct V_24 * V_25 )
{
struct V_103 * V_74 ;
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
struct V_29 * V_29 = F_85 ( V_44 ) ;
T_3 V_5 = V_44 -> V_46 ;
T_2 V_30 = F_28 ( V_44 ) -> V_45 ;
int V_98 ;
if ( V_5 == V_18 ) {
V_98 = F_86 ( & V_25 -> V_142 ) ;
if ( V_98 )
F_87 ( L_1 , V_98 ) ;
}
F_78 () ;
F_88 (net, dev) {
if ( V_74 -> V_143 -> V_144 )
V_74 -> V_143 -> V_144 ( V_74 , V_5 ,
V_30 ) ;
}
F_80 () ;
}
static void F_89 ( struct V_24 * V_25 )
{
struct V_103 * V_74 ;
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
struct V_29 * V_29 = F_85 ( V_44 ) ;
T_3 V_5 = V_44 -> V_46 ;
T_2 V_30 = F_28 ( V_44 ) -> V_45 ;
F_78 () ;
F_88 (net, dev) {
if ( V_74 -> V_143 -> V_145 )
V_74 -> V_143 -> V_145 ( V_74 , V_5 ,
V_30 ) ;
}
F_80 () ;
if ( V_5 == V_18 )
F_90 ( & V_25 -> V_142 ) ;
}
static int F_91 ( struct V_47 * V_48 ,
const T_5 * V_111 , union V_1 * V_13 ,
T_7 V_72 , T_7 V_53 ,
T_2 V_30 , V_96 V_114 , V_96 V_75 ,
T_8 V_76 )
{
struct V_36 * V_97 = NULL ;
struct V_37 * V_104 ;
int V_146 = 0 ;
V_104 = F_58 ( V_48 , V_111 ) ;
if ( V_104 ) {
if ( V_53 & V_147 ) {
F_92 ( V_48 -> V_74 ,
L_2 , V_111 ) ;
return - V_148 ;
}
if ( V_104 -> V_72 != V_72 ) {
V_104 -> V_72 = V_72 ;
V_104 -> V_93 = V_56 ;
V_146 = 1 ;
}
if ( V_104 -> V_53 != V_76 ) {
V_104 -> V_53 = V_76 ;
V_104 -> V_93 = V_56 ;
V_146 = 1 ;
}
if ( ( V_53 & V_149 ) ) {
if ( ! ( F_93 ( V_104 -> V_69 ) ||
F_34 ( V_104 -> V_69 ) ) ) {
int V_150 = F_63 ( V_104 , V_13 , V_30 , V_114 ,
V_75 ) ;
if ( V_150 < 0 )
return V_150 ;
V_146 |= V_150 ;
} else
return - V_151 ;
}
if ( ( V_53 & V_152 ) &&
( F_93 ( V_104 -> V_69 ) ||
F_34 ( V_104 -> V_69 ) ) ) {
int V_150 = F_65 ( V_104 , V_13 , V_30 , V_114 , V_75 ,
& V_97 ) ;
if ( V_150 < 0 )
return V_150 ;
V_146 |= V_150 ;
}
} else {
if ( ! ( V_53 & V_153 ) )
return - V_154 ;
if ( V_48 -> V_155 && V_48 -> V_156 >= V_48 -> V_155 )
return - V_157 ;
if ( ( V_53 & V_149 ) &&
( F_93 ( V_111 ) || F_34 ( V_111 ) ) )
return - V_151 ;
F_92 ( V_48 -> V_74 , L_3 , V_111 , V_13 ) ;
V_104 = F_66 ( sizeof( * V_104 ) , V_100 ) ;
if ( ! V_104 )
return - V_158 ;
V_146 = 1 ;
V_104 -> V_72 = V_72 ;
V_104 -> V_53 = V_76 ;
V_104 -> V_93 = V_104 -> V_90 = V_56 ;
F_94 ( & V_104 -> V_39 ) ;
memcpy ( V_104 -> V_69 , V_111 , V_80 ) ;
F_65 ( V_104 , V_13 , V_30 , V_114 , V_75 , & V_97 ) ;
++ V_48 -> V_156 ;
F_95 ( & V_104 -> V_159 ,
F_57 ( V_48 , V_111 ) ) ;
}
if ( V_146 ) {
if ( V_97 == NULL )
V_97 = F_24 ( V_104 ) ;
F_43 ( V_48 , V_104 , V_97 , V_160 ) ;
}
return 0 ;
}
static void F_96 ( struct V_161 * V_113 )
{
struct V_37 * V_104 = F_97 ( V_113 , struct V_37 , V_162 ) ;
struct V_36 * V_97 , * V_163 ;
F_98 (rd, nd, &f->remotes, list)
F_99 ( V_97 ) ;
F_99 ( V_104 ) ;
}
static void F_100 ( struct V_47 * V_48 , struct V_37 * V_104 )
{
F_92 ( V_48 -> V_74 ,
L_4 , V_104 -> V_69 ) ;
-- V_48 -> V_156 ;
F_43 ( V_48 , V_104 , F_24 ( V_104 ) , V_164 ) ;
F_101 ( & V_104 -> V_159 ) ;
F_102 ( & V_104 -> V_162 , F_96 ) ;
}
static int F_103 ( struct V_14 * V_165 [] , struct V_47 * V_48 ,
union V_1 * V_13 , T_2 * V_30 , T_1 * V_114 , T_1 * V_75 )
{
struct V_29 * V_29 = F_44 ( V_48 -> V_74 ) ;
int V_98 ;
if ( V_165 [ V_82 ] ) {
V_98 = F_10 ( V_13 , V_165 [ V_82 ] ) ;
if ( V_98 )
return V_98 ;
} else {
union V_1 * V_106 = & V_48 -> V_49 . V_68 ;
if ( V_106 -> V_4 . V_5 == V_18 ) {
V_13 -> sin . V_9 . V_10 = F_5 ( V_12 ) ;
V_13 -> V_4 . V_5 = V_18 ;
#if F_104 ( V_166 )
} else {
V_13 -> V_7 . V_8 = V_167 ;
V_13 -> V_4 . V_5 = V_6 ;
#endif
}
}
if ( V_165 [ V_85 ] ) {
if ( F_11 ( V_165 [ V_85 ] ) != sizeof( T_2 ) )
return - V_168 ;
* V_30 = F_105 ( V_165 [ V_85 ] ) ;
} else {
* V_30 = V_48 -> V_84 ;
}
if ( V_165 [ V_86 ] ) {
if ( F_11 ( V_165 [ V_86 ] ) != sizeof( T_1 ) )
return - V_168 ;
* V_114 = F_106 ( V_165 [ V_86 ] ) ;
} else {
* V_114 = V_48 -> V_49 . V_50 ;
}
if ( V_165 [ V_88 ] ) {
struct V_103 * V_169 ;
if ( F_11 ( V_165 [ V_88 ] ) != sizeof( T_1 ) )
return - V_168 ;
* V_75 = F_106 ( V_165 [ V_88 ] ) ;
V_169 = F_107 ( V_29 , * V_75 ) ;
if ( ! V_169 )
return - V_170 ;
} else {
* V_75 = 0 ;
}
return 0 ;
}
static int F_108 ( struct V_61 * V_62 , struct V_14 * V_165 [] ,
struct V_103 * V_74 ,
const unsigned char * V_108 , T_9 V_53 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_114 , V_75 ;
int V_98 ;
if ( ! ( V_62 -> V_71 & ( V_171 | V_172 ) ) ) {
F_109 ( L_5 ,
V_62 -> V_71 ) ;
return - V_168 ;
}
if ( V_165 [ V_82 ] == NULL )
return - V_168 ;
V_98 = F_103 ( V_165 , V_48 , & V_13 , & V_30 , & V_114 , & V_75 ) ;
if ( V_98 )
return V_98 ;
if ( V_48 -> V_49 . V_68 . V_4 . V_5 != V_13 . V_4 . V_5 )
return - V_19 ;
F_110 ( & V_48 -> V_173 ) ;
V_98 = F_91 ( V_48 , V_108 , & V_13 , V_62 -> V_71 , V_53 ,
V_30 , V_114 , V_75 , V_62 -> V_76 ) ;
F_111 ( & V_48 -> V_173 ) ;
return V_98 ;
}
static int F_112 ( struct V_61 * V_62 , struct V_14 * V_165 [] ,
struct V_103 * V_74 ,
const unsigned char * V_108 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_37 * V_104 ;
struct V_36 * V_97 = NULL ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_114 , V_75 ;
int V_98 ;
V_98 = F_103 ( V_165 , V_48 , & V_13 , & V_30 , & V_114 , & V_75 ) ;
if ( V_98 )
return V_98 ;
V_98 = - V_154 ;
F_110 ( & V_48 -> V_173 ) ;
V_104 = F_60 ( V_48 , V_108 ) ;
if ( ! V_104 )
goto V_130;
if ( ! F_3 ( & V_13 ) ) {
V_97 = F_61 ( V_104 , & V_13 , V_30 , V_114 , V_75 ) ;
if ( ! V_97 )
goto V_130;
}
V_98 = 0 ;
if ( V_97 && ! F_113 ( & V_104 -> V_39 ) ) {
F_114 ( & V_97 -> V_41 ) ;
F_43 ( V_48 , V_104 , V_97 , V_164 ) ;
F_115 ( V_97 , V_162 ) ;
goto V_130;
}
F_100 ( V_48 , V_104 ) ;
V_130:
F_111 ( & V_48 -> V_173 ) ;
return V_98 ;
}
static int F_116 ( struct V_20 * V_21 , struct V_174 * V_175 ,
struct V_103 * V_74 ,
struct V_103 * V_176 , int V_177 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
unsigned int V_178 ;
for ( V_178 = 0 ; V_178 < V_179 ; ++ V_178 ) {
struct V_37 * V_104 ;
int V_98 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_97 ;
if ( V_177 < V_175 -> args [ 0 ] )
goto V_180;
F_117 (rd, &f->remotes, list) {
V_98 = F_31 ( V_21 , V_48 , V_104 ,
F_118 ( V_175 -> V_21 ) . V_51 ,
V_175 -> V_60 -> V_181 ,
V_160 ,
V_182 , V_97 ) ;
if ( V_98 < 0 )
goto V_130;
}
V_180:
++ V_177 ;
}
}
V_130:
return V_177 ;
}
static bool F_119 ( struct V_103 * V_74 ,
union V_1 * V_183 , const T_5 * V_184 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_37 * V_104 ;
V_104 = F_60 ( V_48 , V_184 ) ;
if ( F_120 ( V_104 ) ) {
struct V_36 * V_54 = F_22 ( V_104 ) ;
if ( F_120 ( F_1 ( & V_54 -> V_68 , V_183 ) ) )
return false ;
if ( V_104 -> V_72 & V_185 )
return true ;
if ( F_121 () )
F_122 ( V_74 ,
L_6 ,
V_184 , & V_54 -> V_68 , & V_183 ) ;
V_54 -> V_68 = * V_183 ;
V_104 -> V_93 = V_56 ;
F_43 ( V_48 , V_104 , V_54 , V_160 ) ;
} else {
F_123 ( & V_48 -> V_173 ) ;
if ( F_124 ( V_74 ) )
F_91 ( V_48 , V_184 , V_183 ,
V_172 ,
V_147 | V_153 ,
V_48 -> V_84 ,
V_48 -> V_49 . V_50 ,
0 , V_186 ) ;
F_125 ( & V_48 -> V_173 ) ;
}
return false ;
}
static bool F_126 ( struct V_31 * V_32 , struct V_47 * V_74 )
{
struct V_47 * V_48 ;
if ( F_127 ( & V_74 -> V_187 -> V_188 ) == 1 )
return false ;
F_62 (vxlan, &vn->vxlan_list, next) {
if ( ! F_124 ( V_48 -> V_74 ) || V_48 == V_74 )
continue;
if ( V_48 -> V_187 != V_74 -> V_187 )
continue;
if ( ! F_1 ( & V_48 -> V_49 . V_68 ,
& V_74 -> V_49 . V_68 ) )
continue;
if ( V_48 -> V_49 . V_87 !=
V_74 -> V_49 . V_87 )
continue;
return true ;
}
return false ;
}
static void F_128 ( struct V_24 * V_25 )
{
F_129 ( & V_25 -> V_188 ) ;
}
void F_130 ( struct V_24 * V_25 )
{
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
struct V_29 * V_29 = F_85 ( V_44 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_131 ( & V_25 -> V_188 ) )
return;
F_123 ( & V_32 -> V_189 ) ;
F_101 ( & V_25 -> V_159 ) ;
F_89 ( V_25 ) ;
F_125 ( & V_32 -> V_189 ) ;
F_132 ( V_190 , & V_25 -> V_191 ) ;
}
static void F_133 ( struct V_192 * V_193 )
{
struct V_47 * V_48 = F_97 ( V_193 , struct V_47 , V_194 ) ;
struct V_24 * V_25 = V_48 -> V_187 ;
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
union V_1 * V_13 = & V_48 -> V_49 . V_68 ;
int V_75 = V_48 -> V_49 . V_87 ;
F_134 ( V_44 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_195 V_196 = {
. V_197 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_198 = V_75 ,
} ;
F_135 ( V_44 , & V_196 ) ;
#if F_104 ( V_166 )
} else {
V_199 -> V_200 ( V_44 , V_75 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_136 ( V_44 ) ;
F_130 ( V_25 ) ;
F_137 ( V_48 -> V_74 ) ;
}
static void F_138 ( struct V_192 * V_193 )
{
struct V_47 * V_48 = F_97 ( V_193 , struct V_47 , V_201 ) ;
struct V_24 * V_25 = V_48 -> V_187 ;
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
union V_1 * V_13 = & V_48 -> V_49 . V_68 ;
int V_75 = V_48 -> V_49 . V_87 ;
F_134 ( V_44 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_195 V_196 = {
. V_197 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_198 = V_75 ,
} ;
F_139 ( V_44 , & V_196 ) ;
#if F_104 ( V_166 )
} else {
V_199 -> V_202 ( V_44 , V_75 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_136 ( V_44 ) ;
F_130 ( V_25 ) ;
F_137 ( V_48 -> V_74 ) ;
}
static int F_140 ( struct V_43 * V_44 , struct V_20 * V_21 )
{
struct V_24 * V_25 ;
struct V_118 * V_203 ;
if ( ! F_141 ( V_21 , V_204 ) )
goto error;
V_203 = (struct V_118 * ) ( F_142 ( V_21 ) + 1 ) ;
if ( V_203 -> V_205 != F_5 ( V_206 ) ||
( V_203 -> V_133 & F_5 ( 0xff ) ) ) {
F_92 ( V_21 -> V_74 , L_7 ,
F_9 ( V_203 -> V_205 ) , F_9 ( V_203 -> V_133 ) ) ;
goto error;
}
if ( F_143 ( V_21 , V_204 , F_144 ( V_207 ) ) )
goto V_208;
V_25 = F_145 ( V_44 ) ;
if ( ! V_25 )
goto V_208;
V_25 -> V_209 ( V_25 , V_21 , V_203 -> V_133 ) ;
return 0 ;
V_208:
F_47 ( V_21 ) ;
return 0 ;
error:
return 1 ;
}
static void F_146 ( struct V_24 * V_25 ,
struct V_20 * V_21 , V_17 V_133 )
{
struct V_210 * V_211 = NULL ;
struct V_212 * V_213 = NULL ;
struct V_47 * V_48 ;
struct V_214 * V_215 ;
union V_1 V_216 ;
V_96 V_114 ;
int V_98 = 0 ;
union V_1 * V_68 ;
V_114 = F_9 ( V_133 ) >> 8 ;
V_48 = F_29 ( V_25 , V_114 ) ;
if ( ! V_48 )
goto V_208;
V_68 = & V_48 -> V_49 . V_68 ;
F_147 ( V_21 ) ;
F_148 ( V_21 , ! F_149 ( V_48 -> V_29 , F_44 ( V_48 -> V_74 ) ) ) ;
V_21 -> V_217 = F_150 ( V_21 , V_48 -> V_74 ) ;
F_151 ( V_21 , F_152 ( V_21 ) , V_218 ) ;
if ( F_59 ( F_152 ( V_21 ) -> V_219 , V_48 -> V_74 -> V_220 ) )
goto V_208;
if ( V_68 -> V_4 . V_5 == V_18 ) {
V_211 = F_153 ( V_21 ) ;
V_216 . sin . V_9 . V_10 = V_211 -> V_216 ;
V_216 . V_4 . V_5 = V_18 ;
#if F_104 ( V_166 )
} else {
V_213 = F_154 ( V_21 ) ;
V_216 . V_7 . V_8 = V_213 -> V_216 ;
V_216 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_48 -> V_53 & V_221 ) &&
F_119 ( V_21 -> V_74 , & V_216 , F_152 ( V_21 ) -> V_219 ) )
goto V_208;
F_155 ( V_21 ) ;
if ( V_213 )
V_98 = F_156 ( V_213 , V_21 ) ;
if ( V_211 )
V_98 = F_157 ( V_211 , V_21 ) ;
if ( F_73 ( V_98 ) ) {
if ( V_222 ) {
if ( V_213 )
F_158 ( L_8 ,
& V_213 -> V_216 ) ;
if ( V_211 )
F_158 ( L_9 ,
& V_211 -> V_216 , V_211 -> V_223 ) ;
}
if ( V_98 > 1 ) {
++ V_48 -> V_74 -> V_215 . V_224 ;
++ V_48 -> V_74 -> V_215 . V_225 ;
goto V_208;
}
}
V_215 = F_159 ( V_48 -> V_74 -> V_226 ) ;
F_160 ( & V_215 -> V_227 ) ;
V_215 -> V_228 ++ ;
V_215 -> V_229 += V_21 -> V_230 ;
F_161 ( & V_215 -> V_227 ) ;
F_162 ( V_21 ) ;
return;
V_208:
F_47 ( V_21 ) ;
}
static int F_163 ( struct V_103 * V_74 , struct V_20 * V_21 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_231 * V_232 ;
T_5 * V_233 , * V_234 ;
V_17 V_235 , V_236 ;
struct V_237 * V_238 ;
if ( V_74 -> V_53 & V_239 )
goto V_130;
if ( ! F_141 ( V_21 , F_164 ( V_74 ) ) ) {
V_74 -> V_215 . V_240 ++ ;
goto V_130;
}
V_232 = F_165 ( V_21 ) ;
if ( ( V_232 -> V_241 != F_144 ( V_242 ) &&
V_232 -> V_241 != F_144 ( V_243 ) ) ||
V_232 -> V_244 != F_144 ( V_245 ) ||
V_232 -> V_246 != F_144 ( V_247 ) ||
V_232 -> V_248 != V_74 -> V_249 ||
V_232 -> V_250 != 4 )
goto V_130;
V_233 = ( T_5 * ) V_232 + sizeof( struct V_231 ) ;
V_234 = V_233 ;
V_233 += V_74 -> V_249 ;
memcpy ( & V_235 , V_233 , sizeof( V_235 ) ) ;
V_233 += sizeof( V_235 ) ;
V_233 += V_74 -> V_249 ;
memcpy ( & V_236 , V_233 , sizeof( V_236 ) ) ;
if ( F_166 ( V_236 ) ||
F_167 ( V_236 ) )
goto V_130;
V_238 = F_168 ( & V_251 , & V_236 , V_74 ) ;
if ( V_238 ) {
struct V_37 * V_104 ;
struct V_20 * V_252 ;
if ( ! ( V_238 -> V_253 & V_254 ) ) {
F_169 ( V_238 ) ;
goto V_130;
}
V_104 = F_60 ( V_48 , V_238 -> V_255 ) ;
if ( V_104 && F_3 ( & ( F_22 ( V_104 ) -> V_68 ) ) ) {
F_169 ( V_238 ) ;
goto V_130;
}
V_252 = F_170 ( V_256 , V_257 , V_235 , V_74 , V_236 , V_234 ,
V_238 -> V_255 , V_234 ) ;
F_169 ( V_238 ) ;
if ( V_252 == NULL )
goto V_130;
F_147 ( V_252 ) ;
F_171 ( V_252 , F_172 ( V_252 ) ) ;
V_252 -> V_258 = V_259 ;
V_252 -> V_260 = V_261 ;
if ( F_173 ( V_252 ) == V_262 )
V_74 -> V_215 . V_263 ++ ;
} else if ( V_48 -> V_53 & V_264 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_236 ,
. sin . V_265 = V_18 ,
} ;
F_50 ( V_74 , & V_11 ) ;
}
V_130:
F_174 ( V_21 ) ;
return V_266 ;
}
static struct V_20 * F_175 ( struct V_20 * V_267 ,
struct V_237 * V_238 , bool V_268 )
{
struct V_103 * V_74 = V_267 -> V_74 ;
struct V_20 * V_252 ;
struct V_269 * V_270 , * V_271 ;
struct V_212 * V_272 ;
T_5 * V_273 ;
int V_274 = 8 ;
int V_275 ;
int V_276 , V_230 ;
if ( V_74 == NULL )
return NULL ;
V_230 = F_176 ( V_74 ) + sizeof( struct V_212 ) +
sizeof( * V_271 ) + V_274 + V_74 -> V_277 ;
V_252 = F_177 ( V_230 , V_100 ) ;
if ( V_252 == NULL )
return NULL ;
V_252 -> V_217 = F_144 ( V_278 ) ;
V_252 -> V_74 = V_74 ;
F_178 ( V_252 , F_176 ( V_267 -> V_74 ) ) ;
F_179 ( V_252 , sizeof( struct V_121 ) ) ;
F_180 ( V_252 , 0 ) ;
V_270 = (struct V_269 * ) F_181 ( V_267 ) ;
V_273 = F_152 ( V_267 ) -> V_219 ;
V_275 = V_267 -> V_230 - F_182 ( V_267 ) - sizeof( * V_270 ) ;
for ( V_276 = 0 ; V_276 < V_275 - 1 ; V_276 += ( V_270 -> V_279 [ V_276 + 1 ] << 3 ) ) {
if ( V_270 -> V_279 [ V_276 ] == V_280 ) {
V_273 = V_270 -> V_279 + V_276 + sizeof( struct V_281 ) ;
break;
}
}
F_183 ( F_152 ( V_252 ) -> V_282 , V_273 ) ;
F_183 ( F_152 ( V_252 ) -> V_219 , V_238 -> V_255 ) ;
F_152 ( V_252 ) -> V_134 = F_144 ( V_278 ) ;
V_252 -> V_217 = F_144 ( V_278 ) ;
F_184 ( V_252 , sizeof( struct V_121 ) ) ;
F_185 ( V_252 , 0 ) ;
F_186 ( V_252 , sizeof( struct V_212 ) ) ;
V_272 = F_154 ( V_252 ) ;
memset ( V_272 , 0 , sizeof( struct V_212 ) ) ;
V_272 -> V_283 = 6 ;
V_272 -> V_284 = F_154 ( V_267 ) -> V_284 ;
V_272 -> V_285 = V_286 ;
V_272 -> V_287 = 255 ;
V_272 -> V_273 = F_154 ( V_267 ) -> V_216 ;
V_272 -> V_216 = * (struct V_16 * ) V_238 -> V_288 ;
F_184 ( V_252 , sizeof( struct V_212 ) ) ;
F_187 ( V_252 , 0 ) ;
V_271 = (struct V_269 * ) F_186 ( V_252 , sizeof( * V_271 ) + V_274 ) ;
memset ( V_271 , 0 , sizeof( * V_271 ) + V_274 ) ;
V_271 -> V_289 . V_290 = V_291 ;
V_271 -> V_289 . V_292 = V_268 ;
V_271 -> V_289 . V_293 = 1 ;
V_271 -> V_289 . V_294 = 1 ;
V_271 -> V_295 = V_270 -> V_295 ;
F_183 ( & V_271 -> V_279 [ 2 ] , V_238 -> V_255 ) ;
V_271 -> V_279 [ 0 ] = V_296 ;
V_271 -> V_279 [ 1 ] = V_274 >> 3 ;
V_271 -> V_289 . V_297 = F_188 ( & V_272 -> V_216 ,
& V_272 -> V_273 , sizeof( * V_271 ) + V_274 , V_286 ,
F_189 ( V_271 , sizeof( * V_271 ) + V_274 , 0 ) ) ;
V_272 -> V_298 = F_144 ( sizeof( * V_271 ) + V_274 ) ;
F_179 ( V_252 , sizeof( struct V_212 ) ) ;
V_252 -> V_258 = V_259 ;
return V_252 ;
}
static int F_190 ( struct V_103 * V_74 , struct V_20 * V_21 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_269 * V_299 ;
const struct V_212 * V_210 ;
const struct V_16 * V_216 , * V_273 ;
struct V_237 * V_238 ;
struct V_300 * V_301 ;
V_301 = F_191 ( V_74 ) ;
if ( ! V_301 )
goto V_130;
V_210 = F_154 ( V_21 ) ;
V_216 = & V_210 -> V_216 ;
V_273 = & V_210 -> V_273 ;
V_299 = (struct V_269 * ) F_181 ( V_21 ) ;
if ( V_299 -> V_289 . V_302 != 0 ||
V_299 -> V_289 . V_290 != V_303 )
goto V_130;
if ( F_192 ( V_273 ) ||
F_7 ( & V_299 -> V_295 ) )
goto V_130;
V_238 = F_168 ( V_199 -> V_304 , & V_299 -> V_295 , V_74 ) ;
if ( V_238 ) {
struct V_37 * V_104 ;
struct V_20 * V_252 ;
if ( ! ( V_238 -> V_253 & V_254 ) ) {
F_169 ( V_238 ) ;
goto V_130;
}
V_104 = F_60 ( V_48 , V_238 -> V_255 ) ;
if ( V_104 && F_3 ( & ( F_22 ( V_104 ) -> V_68 ) ) ) {
F_169 ( V_238 ) ;
goto V_130;
}
V_252 = F_175 ( V_21 , V_238 ,
! ! ( V_104 ? V_104 -> V_53 & V_305 : 0 ) ) ;
F_169 ( V_238 ) ;
if ( V_252 == NULL )
goto V_130;
if ( F_173 ( V_252 ) == V_262 )
V_74 -> V_215 . V_263 ++ ;
} else if ( V_48 -> V_53 & V_264 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_299 -> V_295 ,
. V_7 . V_306 = V_6 ,
} ;
F_50 ( V_74 , & V_11 ) ;
}
V_130:
F_174 ( V_21 ) ;
return V_266 ;
}
static bool F_193 ( struct V_103 * V_74 , struct V_20 * V_21 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_237 * V_238 ;
if ( F_93 ( F_152 ( V_21 ) -> V_282 ) )
return false ;
V_238 = NULL ;
switch ( F_21 ( F_152 ( V_21 ) -> V_134 ) ) {
case V_245 :
{
struct V_210 * V_307 ;
if ( ! F_141 ( V_21 , sizeof( struct V_210 ) ) )
return false ;
V_307 = F_153 ( V_21 ) ;
V_238 = F_168 ( & V_251 , & V_307 -> V_273 , V_74 ) ;
if ( ! V_238 && ( V_48 -> V_53 & V_264 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_307 -> V_273 ,
. sin . V_265 = V_18 ,
} ;
F_50 ( V_74 , & V_11 ) ;
return false ;
}
break;
}
#if F_104 ( V_166 )
case V_278 :
{
struct V_212 * V_272 ;
if ( ! F_141 ( V_21 , sizeof( struct V_212 ) ) )
return false ;
V_272 = F_154 ( V_21 ) ;
V_238 = F_168 ( V_199 -> V_304 , & V_272 -> V_273 , V_74 ) ;
if ( ! V_238 && ( V_48 -> V_53 & V_264 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_272 -> V_273 ,
. V_7 . V_306 = V_6 ,
} ;
F_50 ( V_74 , & V_11 ) ;
return false ;
}
break;
}
#endif
default:
return false ;
}
if ( V_238 ) {
bool V_308 ;
V_308 = ! F_59 ( F_152 ( V_21 ) -> V_282 , V_238 -> V_255 ) ;
if ( V_308 ) {
memcpy ( F_152 ( V_21 ) -> V_219 , F_152 ( V_21 ) -> V_282 ,
V_74 -> V_249 ) ;
memcpy ( F_152 ( V_21 ) -> V_282 , V_238 -> V_255 , V_74 -> V_249 ) ;
}
F_169 ( V_238 ) ;
return V_308 ;
}
return false ;
}
static int F_194 ( struct V_24 * V_25 ,
struct V_309 * V_310 , struct V_20 * V_21 ,
struct V_103 * V_74 , struct V_16 * V_216 ,
struct V_16 * V_273 , T_8 V_311 , T_8 V_312 ,
T_2 V_313 , T_2 V_84 , V_17 V_114 ,
bool V_314 )
{
struct V_118 * V_203 ;
int V_315 ;
int V_98 ;
bool V_316 = ! F_195 ( V_25 -> V_43 -> V_44 ) ;
V_21 = F_196 ( V_21 , V_316 ) ;
if ( F_197 ( V_21 ) )
return - V_168 ;
F_148 ( V_21 , V_314 ) ;
V_315 = F_176 ( V_310 -> V_74 ) + V_310 -> V_317
+ V_204 + sizeof( struct V_212 )
+ ( F_198 ( V_21 ) ? V_318 : 0 ) ;
V_98 = F_199 ( V_21 , V_315 ) ;
if ( F_73 ( V_98 ) )
return V_98 ;
if ( F_198 ( V_21 ) ) {
if ( F_46 ( ! F_200 ( V_21 ,
V_21 -> V_319 ,
F_201 ( V_21 ) ) ) )
return - V_158 ;
V_21 -> V_320 = 0 ;
}
V_203 = (struct V_118 * ) F_202 ( V_21 , sizeof( * V_203 ) ) ;
V_203 -> V_205 = F_5 ( V_206 ) ;
V_203 -> V_133 = V_114 ;
F_203 ( V_21 , F_144 ( V_207 ) ) ;
F_204 ( V_25 -> V_43 , V_310 , V_21 , V_74 , V_216 , V_273 , V_311 ,
V_312 , V_313 , V_84 ) ;
return 0 ;
}
int F_205 ( struct V_24 * V_25 ,
struct V_321 * V_322 , struct V_20 * V_21 ,
V_17 V_323 , V_17 V_310 , T_8 V_223 , T_8 V_312 , T_2 V_324 ,
T_2 V_313 , T_2 V_84 , V_17 V_114 , bool V_314 )
{
struct V_118 * V_203 ;
int V_315 ;
int V_98 ;
bool V_316 = ! V_25 -> V_43 -> V_44 -> V_325 ;
V_21 = F_196 ( V_21 , V_316 ) ;
if ( F_197 ( V_21 ) )
return - V_168 ;
V_315 = F_176 ( V_322 -> V_310 . V_74 ) + V_322 -> V_310 . V_317
+ V_204 + sizeof( struct V_210 )
+ ( F_198 ( V_21 ) ? V_318 : 0 ) ;
V_98 = F_199 ( V_21 , V_315 ) ;
if ( F_73 ( V_98 ) )
return V_98 ;
if ( F_198 ( V_21 ) ) {
if ( F_46 ( ! F_200 ( V_21 ,
V_21 -> V_319 ,
F_201 ( V_21 ) ) ) )
return - V_158 ;
V_21 -> V_320 = 0 ;
}
V_203 = (struct V_118 * ) F_202 ( V_21 , sizeof( * V_203 ) ) ;
V_203 -> V_205 = F_5 ( V_206 ) ;
V_203 -> V_133 = V_114 ;
F_203 ( V_21 , F_144 ( V_207 ) ) ;
return F_206 ( V_25 -> V_43 , V_322 , V_21 , V_323 , V_310 , V_223 ,
V_312 , V_324 , V_313 , V_84 , V_314 ) ;
}
static void F_207 ( struct V_20 * V_21 , struct V_47 * V_326 ,
struct V_47 * V_327 )
{
struct V_214 * V_328 , * V_329 ;
union V_1 V_330 ;
union V_1 * V_68 = & V_327 -> V_49 . V_68 ;
struct V_103 * V_74 = V_21 -> V_74 ;
int V_230 = V_21 -> V_230 ;
V_328 = F_159 ( V_326 -> V_74 -> V_226 ) ;
V_329 = F_159 ( V_327 -> V_74 -> V_226 ) ;
V_21 -> V_260 = V_261 ;
V_21 -> V_331 = 0 ;
V_21 -> V_74 = V_327 -> V_74 ;
F_171 ( V_21 , F_172 ( V_21 ) ) ;
if ( V_68 -> V_4 . V_5 == V_18 ) {
V_330 . sin . V_9 . V_10 = F_5 ( V_332 ) ;
V_330 . V_4 . V_5 = V_18 ;
#if F_104 ( V_166 )
} else {
V_330 . V_7 . V_8 = V_333 ;
V_330 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_327 -> V_53 & V_221 )
F_119 ( V_21 -> V_74 , & V_330 , F_152 ( V_21 ) -> V_219 ) ;
F_160 ( & V_328 -> V_227 ) ;
V_328 -> V_334 ++ ;
V_328 -> V_335 += V_230 ;
F_161 ( & V_328 -> V_227 ) ;
if ( F_162 ( V_21 ) == V_336 ) {
F_160 ( & V_329 -> V_227 ) ;
V_329 -> V_228 ++ ;
V_329 -> V_229 += V_230 ;
F_161 ( & V_329 -> V_227 ) ;
} else {
V_74 -> V_215 . V_263 ++ ;
}
}
static void F_208 ( struct V_20 * V_21 , struct V_103 * V_74 ,
struct V_36 * V_54 , bool V_337 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_321 * V_322 = NULL ;
const struct V_210 * V_338 ;
struct V_339 V_340 ;
union V_1 * V_310 ;
T_2 V_313 = 0 , V_84 ;
T_1 V_114 ;
T_2 V_324 = 0 ;
T_8 V_223 , V_312 ;
int V_98 ;
V_84 = V_54 -> V_83 ? V_54 -> V_83 : V_48 -> V_84 ;
V_114 = V_54 -> V_50 ;
V_310 = & V_54 -> V_68 ;
if ( F_3 ( V_310 ) ) {
if ( V_337 ) {
F_207 ( V_21 , V_48 , V_48 ) ;
return;
}
goto V_208;
}
V_338 = F_153 ( V_21 ) ;
V_312 = V_48 -> V_312 ;
if ( ! V_312 && F_6 ( V_310 ) )
V_312 = 1 ;
V_223 = V_48 -> V_223 ;
if ( V_223 == 1 )
V_223 = F_209 ( V_338 , V_21 ) ;
V_313 = F_210 ( F_44 ( V_74 ) , V_21 , V_48 -> V_341 ,
V_48 -> V_342 , true ) ;
if ( V_310 -> V_4 . V_5 == V_18 ) {
memset ( & V_340 , 0 , sizeof( V_340 ) ) ;
V_340 . V_343 = V_54 -> V_87 ;
V_340 . V_344 = F_211 ( V_223 ) ;
V_340 . V_273 = V_310 -> sin . V_9 . V_10 ;
V_340 . V_216 = V_48 -> V_216 . sin . V_9 . V_10 ;
V_322 = F_212 ( V_48 -> V_29 , & V_340 ) ;
if ( F_197 ( V_322 ) ) {
F_92 ( V_74 , L_10 ,
& V_310 -> sin . V_9 . V_10 ) ;
V_74 -> V_215 . V_345 ++ ;
goto V_346;
}
if ( V_322 -> V_310 . V_74 == V_74 ) {
F_92 ( V_74 , L_11 ,
& V_310 -> sin . V_9 . V_10 ) ;
V_74 -> V_215 . V_347 ++ ;
goto V_348;
}
if ( V_322 -> V_349 & V_350 &&
! ( V_322 -> V_349 & ( V_351 | V_352 ) ) ) {
struct V_47 * V_327 ;
F_213 ( V_322 ) ;
V_327 = F_30 ( V_48 -> V_29 , V_114 ,
V_310 -> V_4 . V_5 , V_84 ) ;
if ( ! V_327 )
goto V_346;
F_207 ( V_21 , V_48 , V_327 ) ;
return;
}
V_223 = F_214 ( V_223 , V_338 , V_21 ) ;
V_312 = V_312 ? : F_215 ( & V_322 -> V_310 ) ;
V_98 = F_205 ( V_48 -> V_187 , V_322 , V_21 ,
V_340 . V_216 , V_310 -> sin . V_9 . V_10 ,
V_223 , V_312 , V_324 , V_313 , V_84 ,
F_5 ( V_114 << 8 ) ,
! F_149 ( V_48 -> V_29 , F_44 ( V_48 -> V_74 ) ) ) ;
if ( V_98 < 0 )
goto V_348;
F_216 ( V_98 , & V_74 -> V_215 , V_74 -> V_226 ) ;
#if F_104 ( V_166 )
} else {
struct V_43 * V_44 = V_48 -> V_187 -> V_43 -> V_44 ;
struct V_309 * V_353 ;
struct V_354 V_355 ;
T_1 V_53 ;
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
V_355 . V_356 = V_54 -> V_87 ;
V_355 . V_273 = V_310 -> V_7 . V_8 ;
V_355 . V_216 = V_48 -> V_216 . V_7 . V_8 ;
V_355 . V_357 = V_358 ;
if ( V_199 -> V_359 ( V_44 , & V_353 , & V_355 ) ) {
F_92 ( V_74 , L_12 ,
& V_310 -> V_7 . V_8 ) ;
V_74 -> V_215 . V_345 ++ ;
goto V_346;
}
if ( V_353 -> V_74 == V_74 ) {
F_92 ( V_74 , L_13 ,
& V_310 -> V_7 . V_8 ) ;
F_217 ( V_353 ) ;
V_74 -> V_215 . V_347 ++ ;
goto V_346;
}
V_53 = ( (struct V_360 * ) V_353 ) -> V_361 ;
if ( V_53 & V_362 &&
! ( V_53 & ( V_351 | V_352 ) ) ) {
struct V_47 * V_327 ;
F_217 ( V_353 ) ;
V_327 = F_30 ( V_48 -> V_29 , V_114 ,
V_310 -> V_4 . V_5 , V_84 ) ;
if ( ! V_327 )
goto V_346;
F_207 ( V_21 , V_48 , V_327 ) ;
return;
}
V_312 = V_312 ? : F_218 ( V_353 ) ;
V_98 = F_194 ( V_48 -> V_187 , V_353 , V_21 ,
V_74 , & V_355 . V_216 , & V_355 . V_273 , 0 , V_312 ,
V_313 , V_84 , F_5 ( V_114 << 8 ) ,
! F_149 ( V_48 -> V_29 , F_44 ( V_48 -> V_74 ) ) ) ;
#endif
}
return;
V_208:
V_74 -> V_215 . V_240 ++ ;
goto V_363;
V_348:
F_213 ( V_322 ) ;
V_346:
V_74 -> V_215 . V_364 ++ ;
V_363:
F_219 ( V_21 ) ;
}
static T_10 F_220 ( struct V_20 * V_21 , struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_121 * V_365 ;
bool V_337 = false ;
struct V_36 * V_54 , * V_366 = NULL ;
struct V_37 * V_104 ;
F_147 ( V_21 ) ;
V_365 = F_152 ( V_21 ) ;
if ( ( V_48 -> V_53 & V_367 ) ) {
if ( F_21 ( V_365 -> V_134 ) == V_257 )
return F_163 ( V_74 , V_21 ) ;
#if F_104 ( V_166 )
else if ( F_21 ( V_365 -> V_134 ) == V_278 &&
F_141 ( V_21 , sizeof( struct V_212 )
+ sizeof( struct V_269 ) ) &&
F_154 ( V_21 ) -> V_285 == V_286 ) {
struct V_269 * V_299 ;
V_299 = (struct V_269 * ) F_181 ( V_21 ) ;
if ( V_299 -> V_289 . V_302 == 0 &&
V_299 -> V_289 . V_290 == V_303 )
return F_190 ( V_74 , V_21 ) ;
}
V_365 = F_152 ( V_21 ) ;
#endif
}
V_104 = F_60 ( V_48 , V_365 -> V_282 ) ;
V_337 = false ;
if ( V_104 && ( V_104 -> V_53 & V_305 ) && ( V_48 -> V_53 & V_368 ) &&
( F_21 ( V_365 -> V_134 ) == V_245 ||
F_21 ( V_365 -> V_134 ) == V_278 ) ) {
V_337 = F_193 ( V_74 , V_21 ) ;
if ( V_337 )
V_104 = F_60 ( V_48 , V_365 -> V_282 ) ;
}
if ( V_104 == NULL ) {
V_104 = F_60 ( V_48 , V_369 ) ;
if ( V_104 == NULL ) {
if ( ( V_48 -> V_53 & V_370 ) &&
! F_93 ( V_365 -> V_282 ) )
F_52 ( V_48 , V_365 -> V_282 ) ;
V_74 -> V_215 . V_240 ++ ;
F_47 ( V_21 ) ;
return V_266 ;
}
}
F_117 (rdst, &f->remotes, list) {
struct V_20 * V_371 ;
if ( ! V_366 ) {
V_366 = V_54 ;
continue;
}
V_371 = F_221 ( V_21 , V_100 ) ;
if ( V_371 )
F_208 ( V_371 , V_74 , V_54 , V_337 ) ;
}
if ( V_366 )
F_208 ( V_21 , V_74 , V_366 , V_337 ) ;
else
F_47 ( V_21 ) ;
return V_266 ;
}
static void F_222 ( unsigned long V_372 )
{
struct V_47 * V_48 = (struct V_47 * ) V_372 ;
unsigned long V_373 = V_56 + V_374 ;
unsigned int V_178 ;
if ( ! F_124 ( V_48 -> V_74 ) )
return;
F_110 ( & V_48 -> V_173 ) ;
for ( V_178 = 0 ; V_178 < V_179 ; ++ V_178 ) {
struct V_375 * V_116 , * V_238 ;
F_223 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_104
= F_97 ( V_116 , struct V_37 , V_159 ) ;
unsigned long V_376 ;
if ( V_104 -> V_72 & V_171 )
continue;
V_376 = V_104 -> V_90 + V_48 -> V_377 * V_378 ;
if ( F_224 ( V_376 , V_56 ) ) {
F_92 ( V_48 -> V_74 ,
L_14 ,
V_104 -> V_69 ) ;
V_104 -> V_72 = V_105 ;
F_100 ( V_48 , V_104 ) ;
} else if ( F_225 ( V_376 , V_373 ) )
V_373 = V_376 ;
}
}
F_111 ( & V_48 -> V_173 ) ;
F_226 ( & V_48 -> V_379 , V_373 ) ;
}
static void F_227 ( struct V_24 * V_25 , struct V_47 * V_48 )
{
V_96 V_114 = V_48 -> V_49 . V_50 ;
V_48 -> V_187 = V_25 ;
F_95 ( & V_48 -> V_159 , F_17 ( V_25 , V_114 ) ) ;
}
static int F_228 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_48 -> V_29 , V_33 ) ;
struct V_24 * V_25 ;
bool V_380 = V_48 -> V_53 & V_381 ;
V_74 -> V_226 = F_229 ( struct V_214 ) ;
if ( ! V_74 -> V_226 )
return - V_158 ;
F_123 ( & V_32 -> V_189 ) ;
V_25 = F_26 ( V_48 -> V_29 , V_380 ? V_6 : V_18 ,
V_48 -> V_84 ) ;
if ( V_25 ) {
F_129 ( & V_25 -> V_188 ) ;
F_227 ( V_25 , V_48 ) ;
} else {
F_230 ( V_74 ) ;
F_132 ( V_190 , & V_48 -> V_382 ) ;
}
F_125 ( & V_32 -> V_189 ) ;
return 0 ;
}
static void F_231 ( struct V_47 * V_48 )
{
struct V_37 * V_104 ;
F_110 ( & V_48 -> V_173 ) ;
V_104 = F_58 ( V_48 , V_369 ) ;
if ( V_104 )
F_100 ( V_48 , V_104 ) ;
F_111 ( & V_48 -> V_173 ) ;
}
static void F_232 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_24 * V_25 = V_48 -> V_187 ;
F_231 ( V_48 ) ;
if ( V_25 )
F_130 ( V_25 ) ;
F_233 ( V_74 -> V_226 ) ;
}
static int F_234 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_24 * V_25 = V_48 -> V_187 ;
if ( ! V_25 )
return - V_383 ;
if ( F_6 ( & V_48 -> V_49 . V_68 ) ) {
F_128 ( V_25 ) ;
F_230 ( V_74 ) ;
F_132 ( V_190 , & V_48 -> V_194 ) ;
}
if ( V_48 -> V_377 )
F_226 ( & V_48 -> V_379 , V_56 + V_374 ) ;
return 0 ;
}
static void F_235 ( struct V_47 * V_48 )
{
unsigned int V_178 ;
F_110 ( & V_48 -> V_173 ) ;
for ( V_178 = 0 ; V_178 < V_179 ; ++ V_178 ) {
struct V_375 * V_116 , * V_238 ;
F_223 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_104
= F_97 ( V_116 , struct V_37 , V_159 ) ;
if ( ! F_34 ( V_104 -> V_69 ) )
F_100 ( V_48 , V_104 ) ;
}
}
F_111 ( & V_48 -> V_173 ) ;
}
static int F_236 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_48 -> V_29 , V_33 ) ;
struct V_24 * V_25 = V_48 -> V_187 ;
if ( V_25 && F_6 ( & V_48 -> V_49 . V_68 ) &&
! F_126 ( V_32 , V_48 ) ) {
F_128 ( V_25 ) ;
F_230 ( V_74 ) ;
F_132 ( V_190 , & V_48 -> V_201 ) ;
}
F_237 ( & V_48 -> V_379 ) ;
F_235 ( V_48 ) ;
return 0 ;
}
static void F_238 ( struct V_103 * V_74 )
{
}
static int F_239 ( struct V_103 * V_74 , int V_384 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_36 * V_310 = & V_48 -> V_49 ;
struct V_103 * V_385 ;
int V_386 ;
V_385 = F_107 ( V_48 -> V_29 , V_310 -> V_87 ) ;
if ( V_385 == NULL )
return F_240 ( V_74 , V_384 ) ;
if ( V_310 -> V_68 . V_4 . V_5 == V_6 )
V_386 = V_385 -> V_387 - V_388 ;
else
V_386 = V_385 -> V_387 - V_389 ;
if ( V_384 < 68 || V_384 > V_386 )
return - V_168 ;
V_74 -> V_387 = V_384 ;
return 0 ;
}
void F_241 ( struct V_103 * V_74 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_44 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_3 V_5 ;
T_2 V_30 ;
unsigned int V_276 ;
F_123 ( & V_32 -> V_189 ) ;
for ( V_276 = 0 ; V_276 < V_390 ; ++ V_276 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_43 -> V_44 ) -> V_45 ;
V_5 = V_25 -> V_43 -> V_44 -> V_46 ;
V_74 -> V_143 -> V_144 ( V_74 , V_5 ,
V_30 ) ;
}
}
F_125 ( & V_32 -> V_189 ) ;
}
static void F_242 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
unsigned int V_178 ;
F_243 ( V_74 ) ;
F_244 ( V_74 ) ;
if ( V_48 -> V_49 . V_68 . V_4 . V_5 == V_6 )
V_74 -> V_391 = V_218 + V_388 ;
else
V_74 -> V_391 = V_218 + V_389 ;
V_74 -> V_143 = & V_392 ;
V_74 -> V_393 = V_394 ;
F_245 ( V_74 , & V_395 ) ;
V_74 -> V_396 = 0 ;
V_74 -> V_397 |= V_398 ;
V_74 -> V_397 |= V_399 | V_400 ;
V_74 -> V_397 |= V_401 ;
V_74 -> V_397 |= V_402 ;
V_74 -> V_403 = V_74 -> V_397 ;
V_74 -> V_397 |= V_404 | V_405 ;
V_74 -> V_406 |= V_399 | V_400 | V_401 ;
V_74 -> V_406 |= V_402 ;
V_74 -> V_406 |= V_404 | V_405 ;
F_246 ( V_74 ) ;
V_74 -> V_407 |= V_408 ;
F_94 ( & V_48 -> V_40 ) ;
F_247 ( & V_48 -> V_173 ) ;
F_248 ( & V_48 -> V_194 , F_133 ) ;
F_248 ( & V_48 -> V_201 , F_138 ) ;
F_248 ( & V_48 -> V_382 , V_409 ) ;
F_249 ( & V_48 -> V_379 ) ;
V_48 -> V_379 . V_410 = F_222 ;
V_48 -> V_379 . V_132 = ( unsigned long ) V_48 ;
V_48 -> V_84 = F_144 ( V_411 ) ;
V_48 -> V_74 = V_74 ;
for ( V_178 = 0 ; V_178 < V_179 ; ++ V_178 )
F_250 ( & V_48 -> V_112 [ V_178 ] ) ;
}
static int F_251 ( struct V_14 * V_165 [] , struct V_14 * V_132 [] )
{
if ( V_165 [ V_412 ] ) {
if ( F_11 ( V_165 [ V_412 ] ) != V_80 ) {
F_252 ( L_15 ) ;
return - V_168 ;
}
if ( ! F_253 ( F_254 ( V_165 [ V_412 ] ) ) ) {
F_252 ( L_16 ) ;
return - V_170 ;
}
}
if ( ! V_132 )
return - V_168 ;
if ( V_132 [ V_413 ] ) {
V_96 V_26 = F_106 ( V_132 [ V_413 ] ) ;
if ( V_26 >= V_414 )
return - V_415 ;
}
if ( V_132 [ V_416 ] ) {
const struct V_417 * V_116
= F_254 ( V_132 [ V_416 ] ) ;
if ( F_21 ( V_116 -> V_418 ) < F_21 ( V_116 -> V_419 ) ) {
F_252 ( L_17 ,
F_21 ( V_116 -> V_419 ) , F_21 ( V_116 -> V_418 ) ) ;
return - V_168 ;
}
}
return 0 ;
}
static void F_255 ( struct V_103 * V_420 ,
struct V_421 * V_422 )
{
F_256 ( V_422 -> V_283 , V_423 , sizeof( V_422 -> V_283 ) ) ;
F_256 ( V_422 -> V_424 , L_18 , sizeof( V_422 -> V_424 ) ) ;
}
static void F_257 ( struct V_192 * V_193 )
{
struct V_24 * V_25 = F_97 ( V_193 , struct V_24 , V_191 ) ;
F_258 ( V_25 -> V_43 ) ;
F_115 ( V_25 , V_162 ) ;
}
static struct V_425 * F_259 ( struct V_29 * V_29 , bool V_380 ,
T_2 V_30 , T_1 V_53 )
{
struct V_425 * V_43 ;
struct V_426 V_427 ;
int V_98 ;
memset ( & V_427 , 0 , sizeof( V_427 ) ) ;
if ( V_380 ) {
V_427 . V_42 = V_6 ;
V_427 . V_428 =
! ( V_53 & V_429 ) ;
V_427 . V_430 =
! ( V_53 & V_431 ) ;
} else {
V_427 . V_42 = V_18 ;
V_427 . V_432 . V_10 = V_12 ;
V_427 . V_433 =
! ! ( V_53 & V_434 ) ;
}
V_427 . V_435 = V_30 ;
V_98 = F_260 ( V_29 , & V_427 , & V_43 ) ;
if ( V_98 < 0 )
return F_261 ( V_98 ) ;
return V_43 ;
}
static struct V_24 * F_262 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_209 , void * V_132 ,
T_1 V_53 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_425 * V_43 ;
unsigned int V_178 ;
bool V_380 = ! ! ( V_53 & V_381 ) ;
struct V_436 V_437 ;
V_25 = F_263 ( sizeof( * V_25 ) , V_438 ) ;
if ( ! V_25 )
return F_261 ( - V_158 ) ;
for ( V_178 = 0 ; V_178 < V_439 ; ++ V_178 )
F_250 ( & V_25 -> V_27 [ V_178 ] ) ;
F_248 ( & V_25 -> V_191 , F_257 ) ;
V_43 = F_259 ( V_29 , V_380 , V_30 , V_53 ) ;
if ( F_197 ( V_43 ) ) {
F_99 ( V_25 ) ;
return F_264 ( V_43 ) ;
}
V_25 -> V_43 = V_43 ;
F_265 ( & V_25 -> V_188 , 1 ) ;
V_25 -> V_209 = V_209 ;
V_25 -> V_132 = V_132 ;
V_25 -> V_142 . V_30 = V_30 ;
V_25 -> V_142 . V_136 . V_137 = F_68 ;
V_25 -> V_142 . V_136 . V_141 = F_81 ;
F_123 ( & V_32 -> V_189 ) ;
F_95 ( & V_25 -> V_159 , F_19 ( V_29 , V_30 ) ) ;
F_84 ( V_25 ) ;
F_125 ( & V_32 -> V_189 ) ;
V_437 . V_440 = V_25 ;
V_437 . V_441 = 1 ;
V_437 . V_442 = F_140 ;
V_437 . V_443 = NULL ;
F_266 ( V_29 , V_43 , & V_437 ) ;
return V_25 ;
}
struct V_24 * F_267 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_209 , void * V_132 ,
bool V_444 , T_1 V_53 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
bool V_380 = V_53 & V_381 ;
V_25 = F_262 ( V_29 , V_30 , V_209 , V_132 , V_53 ) ;
if ( ! F_197 ( V_25 ) )
return V_25 ;
if ( V_444 )
return V_25 ;
F_123 ( & V_32 -> V_189 ) ;
V_25 = F_26 ( V_29 , V_380 ? V_6 : V_18 , V_30 ) ;
if ( V_25 ) {
if ( V_25 -> V_209 == V_209 )
F_129 ( & V_25 -> V_188 ) ;
else
V_25 = F_261 ( - V_445 ) ;
}
F_125 ( & V_32 -> V_189 ) ;
if ( ! V_25 )
V_25 = F_261 ( - V_168 ) ;
return V_25 ;
}
static void V_409 ( struct V_192 * V_193 )
{
struct V_47 * V_48 = F_97 ( V_193 , struct V_47 , V_382 ) ;
struct V_29 * V_29 = V_48 -> V_29 ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_48 -> V_84 ;
struct V_24 * V_446 ;
V_446 = F_267 ( V_29 , V_30 , F_146 , NULL , false , V_48 -> V_53 ) ;
F_123 ( & V_32 -> V_189 ) ;
if ( ! F_197 ( V_446 ) )
F_227 ( V_446 , V_48 ) ;
F_125 ( & V_32 -> V_189 ) ;
F_137 ( V_48 -> V_74 ) ;
}
static int F_268 ( struct V_29 * V_29 , struct V_103 * V_74 ,
struct V_14 * V_165 [] , struct V_14 * V_132 [] )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_36 * V_310 = & V_48 -> V_49 ;
V_96 V_114 ;
int V_98 ;
bool V_447 = false ;
if ( ! V_132 [ V_413 ] )
return - V_168 ;
V_48 -> V_29 = F_44 ( V_74 ) ;
V_114 = F_106 ( V_132 [ V_413 ] ) ;
V_310 -> V_50 = V_114 ;
V_310 -> V_68 . V_4 . V_5 = V_18 ;
if ( V_132 [ V_448 ] ) {
V_310 -> V_68 . sin . V_9 . V_10 = F_13 ( V_132 [ V_448 ] ) ;
} else if ( V_132 [ V_449 ] ) {
if ( ! F_104 ( V_166 ) )
return - V_450 ;
F_12 ( & V_310 -> V_68 . V_7 . V_8 , V_132 [ V_449 ] ,
sizeof( struct V_16 ) ) ;
V_310 -> V_68 . V_4 . V_5 = V_6 ;
V_447 = true ;
}
if ( V_132 [ V_451 ] ) {
V_48 -> V_216 . sin . V_9 . V_10 = F_13 ( V_132 [ V_451 ] ) ;
V_48 -> V_216 . V_4 . V_5 = V_18 ;
} else if ( V_132 [ V_452 ] ) {
if ( ! F_104 ( V_166 ) )
return - V_450 ;
F_12 ( & V_48 -> V_216 . V_7 . V_8 , V_132 [ V_452 ] ,
sizeof( struct V_16 ) ) ;
V_48 -> V_216 . V_4 . V_5 = V_6 ;
V_447 = true ;
}
if ( V_132 [ V_453 ] &&
( V_310 -> V_87 = F_106 ( V_132 [ V_453 ] ) ) ) {
struct V_103 * V_385
= F_107 ( V_29 , V_310 -> V_87 ) ;
if ( ! V_385 ) {
F_109 ( L_19 , V_310 -> V_87 ) ;
return - V_454 ;
}
#if F_104 ( V_166 )
if ( V_447 ) {
struct V_300 * V_455 = F_191 ( V_385 ) ;
if ( V_455 && V_455 -> V_456 . V_457 ) {
F_109 ( L_20 ) ;
return - V_458 ;
}
V_48 -> V_53 |= V_381 ;
}
#endif
if ( ! V_165 [ V_459 ] )
V_74 -> V_387 = V_385 -> V_387 - ( V_447 ? V_388 : V_389 ) ;
V_74 -> V_391 = V_385 -> V_460 +
( V_447 ? V_388 : V_389 ) ;
} else if ( V_447 )
V_48 -> V_53 |= V_381 ;
if ( V_132 [ V_461 ] )
V_48 -> V_223 = F_269 ( V_132 [ V_461 ] ) ;
if ( V_132 [ V_462 ] )
V_48 -> V_312 = F_269 ( V_132 [ V_462 ] ) ;
if ( ! V_132 [ V_463 ] || F_269 ( V_132 [ V_463 ] ) )
V_48 -> V_53 |= V_221 ;
if ( V_132 [ V_464 ] )
V_48 -> V_377 = F_106 ( V_132 [ V_464 ] ) ;
else
V_48 -> V_377 = V_465 ;
if ( V_132 [ V_466 ] && F_269 ( V_132 [ V_466 ] ) )
V_48 -> V_53 |= V_367 ;
if ( V_132 [ V_467 ] && F_269 ( V_132 [ V_467 ] ) )
V_48 -> V_53 |= V_368 ;
if ( V_132 [ V_468 ] && F_269 ( V_132 [ V_468 ] ) )
V_48 -> V_53 |= V_370 ;
if ( V_132 [ V_469 ] && F_269 ( V_132 [ V_469 ] ) )
V_48 -> V_53 |= V_264 ;
if ( V_132 [ V_470 ] )
V_48 -> V_155 = F_106 ( V_132 [ V_470 ] ) ;
if ( V_132 [ V_416 ] ) {
const struct V_417 * V_116
= F_254 ( V_132 [ V_416 ] ) ;
V_48 -> V_341 = F_21 ( V_116 -> V_419 ) ;
V_48 -> V_342 = F_21 ( V_116 -> V_418 ) ;
}
if ( V_132 [ V_471 ] )
V_48 -> V_84 = F_105 ( V_132 [ V_471 ] ) ;
if ( V_132 [ V_472 ] && F_269 ( V_132 [ V_472 ] ) )
V_48 -> V_53 |= V_434 ;
if ( V_132 [ V_473 ] &&
F_269 ( V_132 [ V_473 ] ) )
V_48 -> V_53 |= V_429 ;
if ( V_132 [ V_474 ] &&
F_269 ( V_132 [ V_474 ] ) )
V_48 -> V_53 |= V_431 ;
if ( F_30 ( V_29 , V_114 , V_447 ? V_6 : V_18 ,
V_48 -> V_84 ) ) {
F_109 ( L_21 , V_114 ) ;
return - V_148 ;
}
V_74 -> V_475 = & V_476 ;
if ( ! F_3 ( & V_48 -> V_49 . V_68 ) ) {
V_98 = F_91 ( V_48 , V_369 ,
& V_48 -> V_49 . V_68 ,
V_172 | V_171 ,
V_147 | V_153 ,
V_48 -> V_84 ,
V_48 -> V_49 . V_50 ,
V_48 -> V_49 . V_87 ,
V_186 ) ;
if ( V_98 )
return V_98 ;
}
V_98 = F_270 ( V_74 ) ;
if ( V_98 ) {
F_231 ( V_48 ) ;
return V_98 ;
}
F_271 ( & V_48 -> V_40 , & V_32 -> V_477 ) ;
return 0 ;
}
static void F_272 ( struct V_103 * V_74 , struct V_478 * V_113 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_48 -> V_29 , V_33 ) ;
F_123 ( & V_32 -> V_189 ) ;
if ( ! F_273 ( & V_48 -> V_159 ) )
F_101 ( & V_48 -> V_159 ) ;
F_125 ( & V_32 -> V_189 ) ;
F_274 ( & V_48 -> V_40 ) ;
F_275 ( V_74 , V_113 ) ;
}
static T_4 F_276 ( const struct V_103 * V_74 )
{
return F_42 ( sizeof( V_96 ) ) +
F_42 ( sizeof( struct V_16 ) ) +
F_42 ( sizeof( V_96 ) ) +
F_42 ( sizeof( struct V_16 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( V_96 ) ) +
F_42 ( sizeof( V_96 ) ) +
F_42 ( sizeof( struct V_417 ) ) +
F_42 ( sizeof( T_2 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
0 ;
}
static int F_277 ( struct V_20 * V_21 , const struct V_103 * V_74 )
{
const struct V_47 * V_48 = F_51 ( V_74 ) ;
const struct V_36 * V_310 = & V_48 -> V_49 ;
struct V_417 V_479 = {
. V_419 = F_144 ( V_48 -> V_341 ) ,
. V_418 = F_144 ( V_48 -> V_342 ) ,
} ;
if ( F_36 ( V_21 , V_413 , V_310 -> V_50 ) )
goto V_81;
if ( ! F_3 ( & V_310 -> V_68 ) ) {
if ( V_310 -> V_68 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_448 ,
V_310 -> V_68 . sin . V_9 . V_10 ) )
goto V_81;
#if F_104 ( V_166 )
} else {
if ( F_15 ( V_21 , V_449 , sizeof( struct V_16 ) ,
& V_310 -> V_68 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( V_310 -> V_87 && F_36 ( V_21 , V_453 , V_310 -> V_87 ) )
goto V_81;
if ( ! F_3 ( & V_48 -> V_216 ) ) {
if ( V_48 -> V_216 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_451 ,
V_48 -> V_216 . sin . V_9 . V_10 ) )
goto V_81;
#if F_104 ( V_166 )
} else {
if ( F_15 ( V_21 , V_452 , sizeof( struct V_16 ) ,
& V_48 -> V_216 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( F_278 ( V_21 , V_462 , V_48 -> V_312 ) ||
F_278 ( V_21 , V_461 , V_48 -> V_223 ) ||
F_278 ( V_21 , V_463 ,
! ! ( V_48 -> V_53 & V_221 ) ) ||
F_278 ( V_21 , V_466 ,
! ! ( V_48 -> V_53 & V_367 ) ) ||
F_278 ( V_21 , V_467 , ! ! ( V_48 -> V_53 & V_368 ) ) ||
F_278 ( V_21 , V_468 ,
! ! ( V_48 -> V_53 & V_370 ) ) ||
F_278 ( V_21 , V_469 ,
! ! ( V_48 -> V_53 & V_264 ) ) ||
F_36 ( V_21 , V_464 , V_48 -> V_377 ) ||
F_36 ( V_21 , V_470 , V_48 -> V_155 ) ||
F_35 ( V_21 , V_471 , V_48 -> V_84 ) ||
F_278 ( V_21 , V_472 ,
! ! ( V_48 -> V_53 & V_434 ) ) ||
F_278 ( V_21 , V_473 ,
! ! ( V_48 -> V_53 & V_429 ) ) ||
F_278 ( V_21 , V_474 ,
! ! ( V_48 -> V_53 & V_431 ) ) )
goto V_81;
if ( F_15 ( V_21 , V_416 , sizeof( V_479 ) , & V_479 ) )
goto V_81;
return 0 ;
V_81:
return - V_65 ;
}
static void F_279 ( struct V_31 * V_32 ,
struct V_103 * V_74 )
{
struct V_47 * V_48 , * V_40 ;
F_280 ( V_480 ) ;
F_98 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_310 = & V_48 -> V_49 ;
if ( V_310 -> V_87 == V_74 -> V_75 )
F_272 ( V_48 -> V_74 , & V_480 ) ;
}
F_281 ( & V_480 ) ;
}
static int F_282 ( struct V_481 * V_482 ,
unsigned long V_483 , void * V_484 )
{
struct V_103 * V_74 = F_283 ( V_484 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_74 ) , V_33 ) ;
if ( V_483 == V_485 )
F_279 ( V_32 , V_74 ) ;
return V_486 ;
}
static T_12 int F_284 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_178 ;
F_94 ( & V_32 -> V_477 ) ;
F_247 ( & V_32 -> V_189 ) ;
for ( V_178 = 0 ; V_178 < V_390 ; ++ V_178 )
F_250 ( & V_32 -> V_34 [ V_178 ] ) ;
return 0 ;
}
static void T_13 F_285 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_47 * V_48 , * V_40 ;
struct V_103 * V_74 , * V_487 ;
F_280 ( V_41 ) ;
F_286 () ;
F_287 (net, dev, aux)
if ( V_74 -> V_488 == & V_489 )
F_275 ( V_74 , & V_41 ) ;
F_98 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_149 ( F_44 ( V_48 -> V_74 ) , V_29 ) )
F_275 ( V_74 , & V_41 ) ;
}
F_281 ( & V_41 ) ;
F_288 () ;
}
static int T_14 F_289 ( void )
{
int V_150 ;
V_190 = F_290 ( L_18 , 0 , 0 ) ;
if ( ! V_190 )
return - V_158 ;
F_291 ( & V_490 , sizeof( V_490 ) ) ;
V_150 = F_292 ( & V_491 ) ;
if ( V_150 )
goto V_492;
V_150 = F_293 ( & V_493 ) ;
if ( V_150 )
goto V_494;
V_150 = F_294 ( & V_489 ) ;
if ( V_150 )
goto V_495;
return 0 ;
V_495:
F_295 ( & V_493 ) ;
V_494:
F_296 ( & V_491 ) ;
V_492:
F_297 ( V_190 ) ;
return V_150 ;
}
static void T_15 F_298 ( void )
{
F_299 ( & V_489 ) ;
F_295 ( & V_493 ) ;
F_297 ( V_190 ) ;
F_296 ( & V_491 ) ;
}
