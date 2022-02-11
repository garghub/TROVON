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
const unsigned char * V_108 , T_9 V_171 , T_9 V_53 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
union V_1 V_13 ;
T_2 V_30 ;
T_1 V_114 , V_75 ;
int V_98 ;
if ( ! ( V_62 -> V_71 & ( V_172 | V_173 ) ) ) {
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
F_110 ( & V_48 -> V_174 ) ;
V_98 = F_91 ( V_48 , V_108 , & V_13 , V_62 -> V_71 , V_53 ,
V_30 , V_114 , V_75 , V_62 -> V_76 ) ;
F_111 ( & V_48 -> V_174 ) ;
return V_98 ;
}
static int F_112 ( struct V_61 * V_62 , struct V_14 * V_165 [] ,
struct V_103 * V_74 ,
const unsigned char * V_108 , T_9 V_171 )
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
F_110 ( & V_48 -> V_174 ) ;
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
F_111 ( & V_48 -> V_174 ) ;
return V_98 ;
}
static int F_116 ( struct V_20 * V_21 , struct V_175 * V_176 ,
struct V_103 * V_74 ,
struct V_103 * V_177 , int V_178 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
unsigned int V_179 ;
for ( V_179 = 0 ; V_179 < V_180 ; ++ V_179 ) {
struct V_37 * V_104 ;
int V_98 ;
F_27 (f, &vxlan->fdb_head[h], hlist) {
struct V_36 * V_97 ;
if ( V_178 < V_176 -> args [ 0 ] )
goto V_181;
F_117 (rd, &f->remotes, list) {
V_98 = F_31 ( V_21 , V_48 , V_104 ,
F_118 ( V_176 -> V_21 ) . V_51 ,
V_176 -> V_60 -> V_182 ,
V_160 ,
V_183 , V_97 ) ;
if ( V_98 < 0 )
goto V_130;
}
V_181:
++ V_178 ;
}
}
V_130:
return V_178 ;
}
static bool F_119 ( struct V_103 * V_74 ,
union V_1 * V_184 , const T_5 * V_185 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_37 * V_104 ;
V_104 = F_60 ( V_48 , V_185 ) ;
if ( F_120 ( V_104 ) ) {
struct V_36 * V_54 = F_22 ( V_104 ) ;
if ( F_120 ( F_1 ( & V_54 -> V_68 , V_184 ) ) )
return false ;
if ( V_104 -> V_72 & V_186 )
return true ;
if ( F_121 () )
F_122 ( V_74 ,
L_6 ,
V_185 , & V_54 -> V_68 , & V_184 ) ;
V_54 -> V_68 = * V_184 ;
V_104 -> V_93 = V_56 ;
F_43 ( V_48 , V_104 , V_54 , V_160 ) ;
} else {
F_123 ( & V_48 -> V_174 ) ;
if ( F_124 ( V_74 ) )
F_91 ( V_48 , V_185 , V_184 ,
V_173 ,
V_147 | V_153 ,
V_48 -> V_84 ,
V_48 -> V_49 . V_50 ,
0 , V_187 ) ;
F_125 ( & V_48 -> V_174 ) ;
}
return false ;
}
static bool F_126 ( struct V_31 * V_32 , struct V_47 * V_74 )
{
struct V_47 * V_48 ;
if ( F_127 ( & V_74 -> V_188 -> V_189 ) == 1 )
return false ;
F_62 (vxlan, &vn->vxlan_list, next) {
if ( ! F_124 ( V_48 -> V_74 ) || V_48 == V_74 )
continue;
if ( V_48 -> V_188 != V_74 -> V_188 )
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
F_129 ( & V_25 -> V_189 ) ;
}
void F_130 ( struct V_24 * V_25 )
{
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
struct V_29 * V_29 = F_85 ( V_44 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
if ( ! F_131 ( & V_25 -> V_189 ) )
return;
F_123 ( & V_32 -> V_190 ) ;
F_101 ( & V_25 -> V_159 ) ;
F_89 ( V_25 ) ;
F_125 ( & V_32 -> V_190 ) ;
F_132 ( V_191 , & V_25 -> V_192 ) ;
}
static void F_133 ( struct V_193 * V_194 )
{
struct V_47 * V_48 = F_97 ( V_194 , struct V_47 , V_195 ) ;
struct V_24 * V_25 = V_48 -> V_188 ;
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
union V_1 * V_13 = & V_48 -> V_49 . V_68 ;
int V_75 = V_48 -> V_49 . V_87 ;
F_134 ( V_44 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_196 V_197 = {
. V_198 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_199 = V_75 ,
} ;
F_135 ( V_44 , & V_197 ) ;
#if F_104 ( V_166 )
} else {
V_200 -> V_201 ( V_44 , V_75 ,
& V_13 -> V_7 . V_8 ) ;
#endif
}
F_136 ( V_44 ) ;
F_130 ( V_25 ) ;
F_137 ( V_48 -> V_74 ) ;
}
static void F_138 ( struct V_193 * V_194 )
{
struct V_47 * V_48 = F_97 ( V_194 , struct V_47 , V_202 ) ;
struct V_24 * V_25 = V_48 -> V_188 ;
struct V_43 * V_44 = V_25 -> V_43 -> V_44 ;
union V_1 * V_13 = & V_48 -> V_49 . V_68 ;
int V_75 = V_48 -> V_49 . V_87 ;
F_134 ( V_44 ) ;
if ( V_13 -> V_4 . V_5 == V_18 ) {
struct V_196 V_197 = {
. V_198 . V_10 = V_13 -> sin . V_9 . V_10 ,
. V_199 = V_75 ,
} ;
F_139 ( V_44 , & V_197 ) ;
#if F_104 ( V_166 )
} else {
V_200 -> V_203 ( V_44 , V_75 ,
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
struct V_118 * V_204 ;
if ( ! F_141 ( V_21 , V_205 ) )
goto error;
V_204 = (struct V_118 * ) ( F_142 ( V_21 ) + 1 ) ;
if ( V_204 -> V_206 != F_5 ( V_207 ) ||
( V_204 -> V_133 & F_5 ( 0xff ) ) ) {
F_92 ( V_21 -> V_74 , L_7 ,
F_9 ( V_204 -> V_206 ) , F_9 ( V_204 -> V_133 ) ) ;
goto error;
}
if ( F_143 ( V_21 , V_205 , F_144 ( V_208 ) ) )
goto V_209;
V_25 = F_145 ( V_44 ) ;
if ( ! V_25 )
goto V_209;
V_25 -> V_210 ( V_25 , V_21 , V_204 -> V_133 ) ;
return 0 ;
V_209:
F_47 ( V_21 ) ;
return 0 ;
error:
return 1 ;
}
static void F_146 ( struct V_24 * V_25 ,
struct V_20 * V_21 , V_17 V_133 )
{
struct V_211 * V_212 = NULL ;
struct V_213 * V_214 = NULL ;
struct V_47 * V_48 ;
struct V_215 * V_216 ;
union V_1 V_217 ;
V_96 V_114 ;
int V_98 = 0 ;
union V_1 * V_68 ;
V_114 = F_9 ( V_133 ) >> 8 ;
V_48 = F_29 ( V_25 , V_114 ) ;
if ( ! V_48 )
goto V_209;
V_68 = & V_48 -> V_49 . V_68 ;
F_147 ( V_21 ) ;
F_148 ( V_21 , ! F_149 ( V_48 -> V_29 , F_44 ( V_48 -> V_74 ) ) ) ;
V_21 -> V_218 = F_150 ( V_21 , V_48 -> V_74 ) ;
F_151 ( V_21 , F_152 ( V_21 ) , V_219 ) ;
if ( F_59 ( F_152 ( V_21 ) -> V_220 , V_48 -> V_74 -> V_221 ) )
goto V_209;
if ( V_68 -> V_4 . V_5 == V_18 ) {
V_212 = F_153 ( V_21 ) ;
V_217 . sin . V_9 . V_10 = V_212 -> V_217 ;
V_217 . V_4 . V_5 = V_18 ;
#if F_104 ( V_166 )
} else {
V_214 = F_154 ( V_21 ) ;
V_217 . V_7 . V_8 = V_214 -> V_217 ;
V_217 . V_4 . V_5 = V_6 ;
#endif
}
if ( ( V_48 -> V_53 & V_222 ) &&
F_119 ( V_21 -> V_74 , & V_217 , F_152 ( V_21 ) -> V_220 ) )
goto V_209;
F_155 ( V_21 ) ;
if ( V_214 )
V_98 = F_156 ( V_214 , V_21 ) ;
if ( V_212 )
V_98 = F_157 ( V_212 , V_21 ) ;
if ( F_73 ( V_98 ) ) {
if ( V_223 ) {
if ( V_214 )
F_158 ( L_8 ,
& V_214 -> V_217 ) ;
if ( V_212 )
F_158 ( L_9 ,
& V_212 -> V_217 , V_212 -> V_224 ) ;
}
if ( V_98 > 1 ) {
++ V_48 -> V_74 -> V_216 . V_225 ;
++ V_48 -> V_74 -> V_216 . V_226 ;
goto V_209;
}
}
V_216 = F_159 ( V_48 -> V_74 -> V_227 ) ;
F_160 ( & V_216 -> V_228 ) ;
V_216 -> V_229 ++ ;
V_216 -> V_230 += V_21 -> V_231 ;
F_161 ( & V_216 -> V_228 ) ;
F_162 ( V_21 ) ;
return;
V_209:
F_47 ( V_21 ) ;
}
static int F_163 ( struct V_103 * V_74 , struct V_20 * V_21 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_232 * V_233 ;
T_5 * V_234 , * V_235 ;
V_17 V_236 , V_237 ;
struct V_238 * V_239 ;
if ( V_74 -> V_53 & V_240 )
goto V_130;
if ( ! F_141 ( V_21 , F_164 ( V_74 ) ) ) {
V_74 -> V_216 . V_241 ++ ;
goto V_130;
}
V_233 = F_165 ( V_21 ) ;
if ( ( V_233 -> V_242 != F_144 ( V_243 ) &&
V_233 -> V_242 != F_144 ( V_244 ) ) ||
V_233 -> V_245 != F_144 ( V_246 ) ||
V_233 -> V_247 != F_144 ( V_248 ) ||
V_233 -> V_249 != V_74 -> V_250 ||
V_233 -> V_251 != 4 )
goto V_130;
V_234 = ( T_5 * ) V_233 + sizeof( struct V_232 ) ;
V_235 = V_234 ;
V_234 += V_74 -> V_250 ;
memcpy ( & V_236 , V_234 , sizeof( V_236 ) ) ;
V_234 += sizeof( V_236 ) ;
V_234 += V_74 -> V_250 ;
memcpy ( & V_237 , V_234 , sizeof( V_237 ) ) ;
if ( F_166 ( V_237 ) ||
F_167 ( V_237 ) )
goto V_130;
V_239 = F_168 ( & V_252 , & V_237 , V_74 ) ;
if ( V_239 ) {
struct V_37 * V_104 ;
struct V_20 * V_253 ;
if ( ! ( V_239 -> V_254 & V_255 ) ) {
F_169 ( V_239 ) ;
goto V_130;
}
V_104 = F_60 ( V_48 , V_239 -> V_256 ) ;
if ( V_104 && F_3 ( & ( F_22 ( V_104 ) -> V_68 ) ) ) {
F_169 ( V_239 ) ;
goto V_130;
}
V_253 = F_170 ( V_257 , V_258 , V_236 , V_74 , V_237 , V_235 ,
V_239 -> V_256 , V_235 ) ;
F_169 ( V_239 ) ;
if ( V_253 == NULL )
goto V_130;
F_147 ( V_253 ) ;
F_171 ( V_253 , F_172 ( V_253 ) ) ;
V_253 -> V_259 = V_260 ;
V_253 -> V_261 = V_262 ;
if ( F_173 ( V_253 ) == V_263 )
V_74 -> V_216 . V_264 ++ ;
} else if ( V_48 -> V_53 & V_265 ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_237 ,
. sin . V_266 = V_18 ,
} ;
F_50 ( V_74 , & V_11 ) ;
}
V_130:
F_174 ( V_21 ) ;
return V_267 ;
}
static struct V_20 * F_175 ( struct V_20 * V_268 ,
struct V_238 * V_239 , bool V_269 )
{
struct V_103 * V_74 = V_268 -> V_74 ;
struct V_20 * V_253 ;
struct V_270 * V_271 , * V_272 ;
struct V_213 * V_273 ;
T_5 * V_274 ;
int V_275 = 8 ;
int V_276 ;
int V_277 , V_231 ;
if ( V_74 == NULL )
return NULL ;
V_231 = F_176 ( V_74 ) + sizeof( struct V_213 ) +
sizeof( * V_272 ) + V_275 + V_74 -> V_278 ;
V_253 = F_177 ( V_231 , V_100 ) ;
if ( V_253 == NULL )
return NULL ;
V_253 -> V_218 = F_144 ( V_279 ) ;
V_253 -> V_74 = V_74 ;
F_178 ( V_253 , F_176 ( V_268 -> V_74 ) ) ;
F_179 ( V_253 , sizeof( struct V_121 ) ) ;
F_180 ( V_253 , 0 ) ;
V_271 = (struct V_270 * ) F_181 ( V_268 ) ;
V_274 = F_152 ( V_268 ) -> V_220 ;
V_276 = V_268 -> V_231 - F_182 ( V_268 ) - sizeof( * V_271 ) ;
for ( V_277 = 0 ; V_277 < V_276 - 1 ; V_277 += ( V_271 -> V_280 [ V_277 + 1 ] << 3 ) ) {
if ( V_271 -> V_280 [ V_277 ] == V_281 ) {
V_274 = V_271 -> V_280 + V_277 + sizeof( struct V_282 ) ;
break;
}
}
F_183 ( F_152 ( V_253 ) -> V_283 , V_274 ) ;
F_183 ( F_152 ( V_253 ) -> V_220 , V_239 -> V_256 ) ;
F_152 ( V_253 ) -> V_134 = F_144 ( V_279 ) ;
V_253 -> V_218 = F_144 ( V_279 ) ;
F_184 ( V_253 , sizeof( struct V_121 ) ) ;
F_185 ( V_253 , 0 ) ;
F_186 ( V_253 , sizeof( struct V_213 ) ) ;
V_273 = F_154 ( V_253 ) ;
memset ( V_273 , 0 , sizeof( struct V_213 ) ) ;
V_273 -> V_284 = 6 ;
V_273 -> V_285 = F_154 ( V_268 ) -> V_285 ;
V_273 -> V_286 = V_287 ;
V_273 -> V_288 = 255 ;
V_273 -> V_274 = F_154 ( V_268 ) -> V_217 ;
V_273 -> V_217 = * (struct V_16 * ) V_239 -> V_289 ;
F_184 ( V_253 , sizeof( struct V_213 ) ) ;
F_187 ( V_253 , 0 ) ;
V_272 = (struct V_270 * ) F_186 ( V_253 , sizeof( * V_272 ) + V_275 ) ;
memset ( V_272 , 0 , sizeof( * V_272 ) + V_275 ) ;
V_272 -> V_290 . V_291 = V_292 ;
V_272 -> V_290 . V_293 = V_269 ;
V_272 -> V_290 . V_294 = 1 ;
V_272 -> V_290 . V_295 = 1 ;
V_272 -> V_296 = V_271 -> V_296 ;
F_183 ( & V_272 -> V_280 [ 2 ] , V_239 -> V_256 ) ;
V_272 -> V_280 [ 0 ] = V_297 ;
V_272 -> V_280 [ 1 ] = V_275 >> 3 ;
V_272 -> V_290 . V_298 = F_188 ( & V_273 -> V_217 ,
& V_273 -> V_274 , sizeof( * V_272 ) + V_275 , V_287 ,
F_189 ( V_272 , sizeof( * V_272 ) + V_275 , 0 ) ) ;
V_273 -> V_299 = F_144 ( sizeof( * V_272 ) + V_275 ) ;
F_179 ( V_253 , sizeof( struct V_213 ) ) ;
V_253 -> V_259 = V_260 ;
return V_253 ;
}
static int F_190 ( struct V_103 * V_74 , struct V_20 * V_21 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_270 * V_300 ;
const struct V_213 * V_211 ;
const struct V_16 * V_217 , * V_274 ;
struct V_238 * V_239 ;
struct V_301 * V_302 ;
V_302 = F_191 ( V_74 ) ;
if ( ! V_302 )
goto V_130;
V_211 = F_154 ( V_21 ) ;
V_217 = & V_211 -> V_217 ;
V_274 = & V_211 -> V_274 ;
V_300 = (struct V_270 * ) F_181 ( V_21 ) ;
if ( V_300 -> V_290 . V_303 != 0 ||
V_300 -> V_290 . V_291 != V_304 )
goto V_130;
if ( F_192 ( V_274 ) ||
F_7 ( & V_300 -> V_296 ) )
goto V_130;
V_239 = F_168 ( V_200 -> V_305 , & V_300 -> V_296 , V_74 ) ;
if ( V_239 ) {
struct V_37 * V_104 ;
struct V_20 * V_253 ;
if ( ! ( V_239 -> V_254 & V_255 ) ) {
F_169 ( V_239 ) ;
goto V_130;
}
V_104 = F_60 ( V_48 , V_239 -> V_256 ) ;
if ( V_104 && F_3 ( & ( F_22 ( V_104 ) -> V_68 ) ) ) {
F_169 ( V_239 ) ;
goto V_130;
}
V_253 = F_175 ( V_21 , V_239 ,
! ! ( V_104 ? V_104 -> V_53 & V_306 : 0 ) ) ;
F_169 ( V_239 ) ;
if ( V_253 == NULL )
goto V_130;
if ( F_173 ( V_253 ) == V_263 )
V_74 -> V_216 . V_264 ++ ;
} else if ( V_48 -> V_53 & V_265 ) {
union V_1 V_11 = {
. V_7 . V_8 = V_300 -> V_296 ,
. V_7 . V_307 = V_6 ,
} ;
F_50 ( V_74 , & V_11 ) ;
}
V_130:
F_174 ( V_21 ) ;
return V_267 ;
}
static bool F_193 ( struct V_103 * V_74 , struct V_20 * V_21 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_238 * V_239 ;
if ( F_93 ( F_152 ( V_21 ) -> V_283 ) )
return false ;
V_239 = NULL ;
switch ( F_21 ( F_152 ( V_21 ) -> V_134 ) ) {
case V_246 :
{
struct V_211 * V_308 ;
if ( ! F_141 ( V_21 , sizeof( struct V_211 ) ) )
return false ;
V_308 = F_153 ( V_21 ) ;
V_239 = F_168 ( & V_252 , & V_308 -> V_274 , V_74 ) ;
if ( ! V_239 && ( V_48 -> V_53 & V_265 ) ) {
union V_1 V_11 = {
. sin . V_9 . V_10 = V_308 -> V_274 ,
. sin . V_266 = V_18 ,
} ;
F_50 ( V_74 , & V_11 ) ;
return false ;
}
break;
}
#if F_104 ( V_166 )
case V_279 :
{
struct V_213 * V_273 ;
if ( ! F_141 ( V_21 , sizeof( struct V_213 ) ) )
return false ;
V_273 = F_154 ( V_21 ) ;
V_239 = F_168 ( V_200 -> V_305 , & V_273 -> V_274 , V_74 ) ;
if ( ! V_239 && ( V_48 -> V_53 & V_265 ) ) {
union V_1 V_11 = {
. V_7 . V_8 = V_273 -> V_274 ,
. V_7 . V_307 = V_6 ,
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
if ( V_239 ) {
bool V_309 ;
V_309 = ! F_59 ( F_152 ( V_21 ) -> V_283 , V_239 -> V_256 ) ;
if ( V_309 ) {
memcpy ( F_152 ( V_21 ) -> V_220 , F_152 ( V_21 ) -> V_283 ,
V_74 -> V_250 ) ;
memcpy ( F_152 ( V_21 ) -> V_283 , V_239 -> V_256 , V_74 -> V_250 ) ;
}
F_169 ( V_239 ) ;
return V_309 ;
}
return false ;
}
static int F_194 ( struct V_24 * V_25 ,
struct V_310 * V_311 , struct V_20 * V_21 ,
struct V_103 * V_74 , struct V_16 * V_217 ,
struct V_16 * V_274 , T_8 V_312 , T_8 V_313 ,
T_2 V_314 , T_2 V_84 , V_17 V_114 ,
bool V_315 )
{
struct V_118 * V_204 ;
int V_316 ;
int V_98 ;
bool V_317 = ! F_195 ( V_25 -> V_43 -> V_44 ) ;
V_21 = F_196 ( V_21 , V_317 ) ;
if ( F_197 ( V_21 ) ) {
V_98 = - V_168 ;
goto V_98;
}
F_148 ( V_21 , V_315 ) ;
V_316 = F_176 ( V_311 -> V_74 ) + V_311 -> V_318
+ V_205 + sizeof( struct V_213 )
+ ( F_198 ( V_21 ) ? V_319 : 0 ) ;
V_98 = F_199 ( V_21 , V_316 ) ;
if ( F_73 ( V_98 ) ) {
F_47 ( V_21 ) ;
goto V_98;
}
V_21 = F_200 ( V_21 ) ;
if ( F_46 ( ! V_21 ) ) {
V_98 = - V_158 ;
goto V_98;
}
V_204 = (struct V_118 * ) F_201 ( V_21 , sizeof( * V_204 ) ) ;
V_204 -> V_206 = F_5 ( V_207 ) ;
V_204 -> V_133 = V_114 ;
F_202 ( V_21 , F_144 ( V_208 ) ) ;
F_203 ( V_25 -> V_43 , V_311 , V_21 , V_74 , V_217 , V_274 , V_312 ,
V_313 , V_314 , V_84 ) ;
return 0 ;
V_98:
F_204 ( V_311 ) ;
return V_98 ;
}
int F_205 ( struct V_24 * V_25 ,
struct V_320 * V_321 , struct V_20 * V_21 ,
V_17 V_322 , V_17 V_311 , T_8 V_224 , T_8 V_313 , T_2 V_323 ,
T_2 V_314 , T_2 V_84 , V_17 V_114 , bool V_315 )
{
struct V_118 * V_204 ;
int V_316 ;
int V_98 ;
bool V_317 = ! V_25 -> V_43 -> V_44 -> V_324 ;
V_21 = F_196 ( V_21 , V_317 ) ;
if ( F_197 ( V_21 ) )
return F_206 ( V_21 ) ;
V_316 = F_176 ( V_321 -> V_311 . V_74 ) + V_321 -> V_311 . V_318
+ V_205 + sizeof( struct V_211 )
+ ( F_198 ( V_21 ) ? V_319 : 0 ) ;
V_98 = F_199 ( V_21 , V_316 ) ;
if ( F_73 ( V_98 ) ) {
F_47 ( V_21 ) ;
return V_98 ;
}
V_21 = F_200 ( V_21 ) ;
if ( F_46 ( ! V_21 ) )
return - V_158 ;
V_204 = (struct V_118 * ) F_201 ( V_21 , sizeof( * V_204 ) ) ;
V_204 -> V_206 = F_5 ( V_207 ) ;
V_204 -> V_133 = V_114 ;
F_202 ( V_21 , F_144 ( V_208 ) ) ;
return F_207 ( V_25 -> V_43 , V_321 , V_21 , V_322 , V_311 , V_224 ,
V_313 , V_323 , V_314 , V_84 , V_315 ) ;
}
static void F_208 ( struct V_20 * V_21 , struct V_47 * V_325 ,
struct V_47 * V_326 )
{
struct V_215 * V_327 , * V_328 ;
union V_1 V_329 ;
union V_1 * V_68 = & V_326 -> V_49 . V_68 ;
struct V_103 * V_74 = V_21 -> V_74 ;
int V_231 = V_21 -> V_231 ;
V_327 = F_159 ( V_325 -> V_74 -> V_227 ) ;
V_328 = F_159 ( V_326 -> V_74 -> V_227 ) ;
V_21 -> V_261 = V_262 ;
V_21 -> V_330 = 0 ;
V_21 -> V_74 = V_326 -> V_74 ;
F_171 ( V_21 , F_172 ( V_21 ) ) ;
if ( V_68 -> V_4 . V_5 == V_18 ) {
V_329 . sin . V_9 . V_10 = F_5 ( V_331 ) ;
V_329 . V_4 . V_5 = V_18 ;
#if F_104 ( V_166 )
} else {
V_329 . V_7 . V_8 = V_332 ;
V_329 . V_4 . V_5 = V_6 ;
#endif
}
if ( V_326 -> V_53 & V_222 )
F_119 ( V_21 -> V_74 , & V_329 , F_152 ( V_21 ) -> V_220 ) ;
F_160 ( & V_327 -> V_228 ) ;
V_327 -> V_333 ++ ;
V_327 -> V_334 += V_231 ;
F_161 ( & V_327 -> V_228 ) ;
if ( F_162 ( V_21 ) == V_335 ) {
F_160 ( & V_328 -> V_228 ) ;
V_328 -> V_229 ++ ;
V_328 -> V_230 += V_231 ;
F_161 ( & V_328 -> V_228 ) ;
} else {
V_74 -> V_216 . V_264 ++ ;
}
}
static void F_209 ( struct V_20 * V_21 , struct V_103 * V_74 ,
struct V_36 * V_54 , bool V_336 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_320 * V_321 = NULL ;
const struct V_211 * V_337 ;
struct V_338 V_339 ;
union V_1 * V_311 ;
T_2 V_314 = 0 , V_84 ;
T_1 V_114 ;
T_2 V_323 = 0 ;
T_8 V_224 , V_313 ;
int V_98 ;
V_84 = V_54 -> V_83 ? V_54 -> V_83 : V_48 -> V_84 ;
V_114 = V_54 -> V_50 ;
V_311 = & V_54 -> V_68 ;
if ( F_3 ( V_311 ) ) {
if ( V_336 ) {
F_208 ( V_21 , V_48 , V_48 ) ;
return;
}
goto V_209;
}
V_337 = F_153 ( V_21 ) ;
V_313 = V_48 -> V_313 ;
if ( ! V_313 && F_6 ( V_311 ) )
V_313 = 1 ;
V_224 = V_48 -> V_224 ;
if ( V_224 == 1 )
V_224 = F_210 ( V_337 , V_21 ) ;
V_314 = F_211 ( F_44 ( V_74 ) , V_21 , V_48 -> V_340 ,
V_48 -> V_341 , true ) ;
if ( V_311 -> V_4 . V_5 == V_18 ) {
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
V_339 . V_342 = V_54 -> V_87 ;
V_339 . V_343 = F_212 ( V_224 ) ;
V_339 . V_274 = V_311 -> sin . V_9 . V_10 ;
V_339 . V_217 = V_48 -> V_217 . sin . V_9 . V_10 ;
V_321 = F_213 ( V_48 -> V_29 , & V_339 ) ;
if ( F_197 ( V_321 ) ) {
F_92 ( V_74 , L_10 ,
& V_311 -> sin . V_9 . V_10 ) ;
V_74 -> V_216 . V_344 ++ ;
goto V_345;
}
if ( V_321 -> V_311 . V_74 == V_74 ) {
F_92 ( V_74 , L_11 ,
& V_311 -> sin . V_9 . V_10 ) ;
V_74 -> V_216 . V_346 ++ ;
goto V_347;
}
if ( V_321 -> V_348 & V_349 &&
! ( V_321 -> V_348 & ( V_350 | V_351 ) ) ) {
struct V_47 * V_326 ;
F_214 ( V_321 ) ;
V_326 = F_30 ( V_48 -> V_29 , V_114 ,
V_311 -> V_4 . V_5 , V_84 ) ;
if ( ! V_326 )
goto V_345;
F_208 ( V_21 , V_48 , V_326 ) ;
return;
}
V_224 = F_215 ( V_224 , V_337 , V_21 ) ;
V_313 = V_313 ? : F_216 ( & V_321 -> V_311 ) ;
V_98 = F_205 ( V_48 -> V_188 , V_321 , V_21 ,
V_339 . V_217 , V_311 -> sin . V_9 . V_10 ,
V_224 , V_313 , V_323 , V_314 , V_84 ,
F_5 ( V_114 << 8 ) ,
! F_149 ( V_48 -> V_29 , F_44 ( V_48 -> V_74 ) ) ) ;
if ( V_98 < 0 ) {
V_21 = NULL ;
goto V_347;
}
F_217 ( V_98 , & V_74 -> V_216 , V_74 -> V_227 ) ;
#if F_104 ( V_166 )
} else {
struct V_43 * V_44 = V_48 -> V_188 -> V_43 -> V_44 ;
struct V_310 * V_352 ;
struct V_353 V_354 ;
T_1 V_53 ;
memset ( & V_354 , 0 , sizeof( V_354 ) ) ;
V_354 . V_355 = V_54 -> V_87 ;
V_354 . V_274 = V_311 -> V_7 . V_8 ;
V_354 . V_217 = V_48 -> V_217 . V_7 . V_8 ;
V_354 . V_356 = V_357 ;
if ( V_200 -> V_358 ( V_44 , & V_352 , & V_354 ) ) {
F_92 ( V_74 , L_12 ,
& V_311 -> V_7 . V_8 ) ;
V_74 -> V_216 . V_344 ++ ;
goto V_345;
}
if ( V_352 -> V_74 == V_74 ) {
F_92 ( V_74 , L_13 ,
& V_311 -> V_7 . V_8 ) ;
F_204 ( V_352 ) ;
V_74 -> V_216 . V_346 ++ ;
goto V_345;
}
V_53 = ( (struct V_359 * ) V_352 ) -> V_360 ;
if ( V_53 & V_361 &&
! ( V_53 & ( V_350 | V_351 ) ) ) {
struct V_47 * V_326 ;
F_204 ( V_352 ) ;
V_326 = F_30 ( V_48 -> V_29 , V_114 ,
V_311 -> V_4 . V_5 , V_84 ) ;
if ( ! V_326 )
goto V_345;
F_208 ( V_21 , V_48 , V_326 ) ;
return;
}
V_313 = V_313 ? : F_218 ( V_352 ) ;
V_98 = F_194 ( V_48 -> V_188 , V_352 , V_21 ,
V_74 , & V_354 . V_217 , & V_354 . V_274 , 0 , V_313 ,
V_314 , V_84 , F_5 ( V_114 << 8 ) ,
! F_149 ( V_48 -> V_29 , F_44 ( V_48 -> V_74 ) ) ) ;
#endif
}
return;
V_209:
V_74 -> V_216 . V_241 ++ ;
goto V_362;
V_347:
F_214 ( V_321 ) ;
V_345:
V_74 -> V_216 . V_363 ++ ;
V_362:
F_219 ( V_21 ) ;
}
static T_10 F_220 ( struct V_20 * V_21 , struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_121 * V_364 ;
bool V_336 = false ;
struct V_36 * V_54 , * V_365 = NULL ;
struct V_37 * V_104 ;
F_147 ( V_21 ) ;
V_364 = F_152 ( V_21 ) ;
if ( ( V_48 -> V_53 & V_366 ) ) {
if ( F_21 ( V_364 -> V_134 ) == V_258 )
return F_163 ( V_74 , V_21 ) ;
#if F_104 ( V_166 )
else if ( F_21 ( V_364 -> V_134 ) == V_279 &&
F_141 ( V_21 , sizeof( struct V_213 )
+ sizeof( struct V_270 ) ) &&
F_154 ( V_21 ) -> V_286 == V_287 ) {
struct V_270 * V_300 ;
V_300 = (struct V_270 * ) F_181 ( V_21 ) ;
if ( V_300 -> V_290 . V_303 == 0 &&
V_300 -> V_290 . V_291 == V_304 )
return F_190 ( V_74 , V_21 ) ;
}
V_364 = F_152 ( V_21 ) ;
#endif
}
V_104 = F_60 ( V_48 , V_364 -> V_283 ) ;
V_336 = false ;
if ( V_104 && ( V_104 -> V_53 & V_306 ) && ( V_48 -> V_53 & V_367 ) &&
( F_21 ( V_364 -> V_134 ) == V_246 ||
F_21 ( V_364 -> V_134 ) == V_279 ) ) {
V_336 = F_193 ( V_74 , V_21 ) ;
if ( V_336 )
V_104 = F_60 ( V_48 , V_364 -> V_283 ) ;
}
if ( V_104 == NULL ) {
V_104 = F_60 ( V_48 , V_368 ) ;
if ( V_104 == NULL ) {
if ( ( V_48 -> V_53 & V_369 ) &&
! F_93 ( V_364 -> V_283 ) )
F_52 ( V_48 , V_364 -> V_283 ) ;
V_74 -> V_216 . V_241 ++ ;
F_47 ( V_21 ) ;
return V_267 ;
}
}
F_117 (rdst, &f->remotes, list) {
struct V_20 * V_370 ;
if ( ! V_365 ) {
V_365 = V_54 ;
continue;
}
V_370 = F_221 ( V_21 , V_100 ) ;
if ( V_370 )
F_209 ( V_370 , V_74 , V_54 , V_336 ) ;
}
if ( V_365 )
F_209 ( V_21 , V_74 , V_365 , V_336 ) ;
else
F_47 ( V_21 ) ;
return V_267 ;
}
static void F_222 ( unsigned long V_371 )
{
struct V_47 * V_48 = (struct V_47 * ) V_371 ;
unsigned long V_372 = V_56 + V_373 ;
unsigned int V_179 ;
if ( ! F_124 ( V_48 -> V_74 ) )
return;
F_110 ( & V_48 -> V_174 ) ;
for ( V_179 = 0 ; V_179 < V_180 ; ++ V_179 ) {
struct V_374 * V_116 , * V_239 ;
F_223 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_104
= F_97 ( V_116 , struct V_37 , V_159 ) ;
unsigned long V_375 ;
if ( V_104 -> V_72 & V_172 )
continue;
V_375 = V_104 -> V_90 + V_48 -> V_376 * V_377 ;
if ( F_224 ( V_375 , V_56 ) ) {
F_92 ( V_48 -> V_74 ,
L_14 ,
V_104 -> V_69 ) ;
V_104 -> V_72 = V_105 ;
F_100 ( V_48 , V_104 ) ;
} else if ( F_225 ( V_375 , V_372 ) )
V_372 = V_375 ;
}
}
F_111 ( & V_48 -> V_174 ) ;
F_226 ( & V_48 -> V_378 , V_372 ) ;
}
static void F_227 ( struct V_24 * V_25 , struct V_47 * V_48 )
{
V_96 V_114 = V_48 -> V_49 . V_50 ;
V_48 -> V_188 = V_25 ;
F_95 ( & V_48 -> V_159 , F_17 ( V_25 , V_114 ) ) ;
}
static int F_228 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_48 -> V_29 , V_33 ) ;
struct V_24 * V_25 ;
bool V_379 = V_48 -> V_53 & V_380 ;
V_74 -> V_227 = F_229 ( struct V_215 ) ;
if ( ! V_74 -> V_227 )
return - V_158 ;
F_123 ( & V_32 -> V_190 ) ;
V_25 = F_26 ( V_48 -> V_29 , V_379 ? V_6 : V_18 ,
V_48 -> V_84 ) ;
if ( V_25 && F_230 ( & V_25 -> V_189 , 1 , 0 ) ) {
F_227 ( V_25 , V_48 ) ;
} else {
F_231 ( V_74 ) ;
F_132 ( V_191 , & V_48 -> V_381 ) ;
}
F_125 ( & V_32 -> V_190 ) ;
return 0 ;
}
static void F_232 ( struct V_47 * V_48 )
{
struct V_37 * V_104 ;
F_110 ( & V_48 -> V_174 ) ;
V_104 = F_58 ( V_48 , V_368 ) ;
if ( V_104 )
F_100 ( V_48 , V_104 ) ;
F_111 ( & V_48 -> V_174 ) ;
}
static void F_233 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_24 * V_25 = V_48 -> V_188 ;
F_232 ( V_48 ) ;
if ( V_25 )
F_130 ( V_25 ) ;
F_234 ( V_74 -> V_227 ) ;
}
static int F_235 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_24 * V_25 = V_48 -> V_188 ;
if ( ! V_25 )
return - V_382 ;
if ( F_6 ( & V_48 -> V_49 . V_68 ) ) {
F_128 ( V_25 ) ;
F_231 ( V_74 ) ;
F_132 ( V_191 , & V_48 -> V_195 ) ;
}
if ( V_48 -> V_376 )
F_226 ( & V_48 -> V_378 , V_56 + V_373 ) ;
return 0 ;
}
static void F_236 ( struct V_47 * V_48 )
{
unsigned int V_179 ;
F_110 ( & V_48 -> V_174 ) ;
for ( V_179 = 0 ; V_179 < V_180 ; ++ V_179 ) {
struct V_374 * V_116 , * V_239 ;
F_223 (p, n, &vxlan->fdb_head[h]) {
struct V_37 * V_104
= F_97 ( V_116 , struct V_37 , V_159 ) ;
if ( ! F_34 ( V_104 -> V_69 ) )
F_100 ( V_48 , V_104 ) ;
}
}
F_111 ( & V_48 -> V_174 ) ;
}
static int F_237 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_48 -> V_29 , V_33 ) ;
struct V_24 * V_25 = V_48 -> V_188 ;
if ( V_25 && F_6 ( & V_48 -> V_49 . V_68 ) &&
! F_126 ( V_32 , V_48 ) ) {
F_128 ( V_25 ) ;
F_231 ( V_74 ) ;
F_132 ( V_191 , & V_48 -> V_202 ) ;
}
F_238 ( & V_48 -> V_378 ) ;
F_236 ( V_48 ) ;
return 0 ;
}
static void F_239 ( struct V_103 * V_74 )
{
}
static int F_240 ( struct V_103 * V_74 , int V_383 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_36 * V_311 = & V_48 -> V_49 ;
struct V_103 * V_384 ;
int V_385 ;
V_384 = F_107 ( V_48 -> V_29 , V_311 -> V_87 ) ;
if ( V_384 == NULL )
return F_241 ( V_74 , V_383 ) ;
if ( V_311 -> V_68 . V_4 . V_5 == V_6 )
V_385 = V_384 -> V_386 - V_387 ;
else
V_385 = V_384 -> V_386 - V_388 ;
if ( V_383 < 68 || V_383 > V_385 )
return - V_168 ;
V_74 -> V_386 = V_383 ;
return 0 ;
}
void F_242 ( struct V_103 * V_74 )
{
struct V_24 * V_25 ;
struct V_29 * V_29 = F_44 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_3 V_5 ;
T_2 V_30 ;
unsigned int V_277 ;
F_123 ( & V_32 -> V_190 ) ;
for ( V_277 = 0 ; V_277 < V_389 ; ++ V_277 ) {
F_27 (vs, &vn->sock_list[i], hlist) {
V_30 = F_28 ( V_25 -> V_43 -> V_44 ) -> V_45 ;
V_5 = V_25 -> V_43 -> V_44 -> V_46 ;
V_74 -> V_143 -> V_144 ( V_74 , V_5 ,
V_30 ) ;
}
}
F_125 ( & V_32 -> V_190 ) ;
}
static void F_243 ( struct V_103 * V_74 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
unsigned int V_179 ;
F_244 ( V_74 ) ;
F_245 ( V_74 ) ;
if ( V_48 -> V_49 . V_68 . V_4 . V_5 == V_6 )
V_74 -> V_390 = V_219 + V_387 ;
else
V_74 -> V_390 = V_219 + V_388 ;
V_74 -> V_143 = & V_391 ;
V_74 -> V_392 = V_393 ;
F_246 ( V_74 , & V_394 ) ;
V_74 -> V_395 = 0 ;
V_74 -> V_396 |= V_397 ;
V_74 -> V_396 |= V_398 | V_399 ;
V_74 -> V_396 |= V_400 ;
V_74 -> V_396 |= V_401 ;
V_74 -> V_402 = V_74 -> V_396 ;
V_74 -> V_396 |= V_403 | V_404 ;
V_74 -> V_405 |= V_398 | V_399 | V_400 ;
V_74 -> V_405 |= V_401 ;
V_74 -> V_405 |= V_403 | V_404 ;
F_247 ( V_74 ) ;
V_74 -> V_406 |= V_407 ;
F_94 ( & V_48 -> V_40 ) ;
F_248 ( & V_48 -> V_174 ) ;
F_249 ( & V_48 -> V_195 , F_133 ) ;
F_249 ( & V_48 -> V_202 , F_138 ) ;
F_249 ( & V_48 -> V_381 , V_408 ) ;
F_250 ( & V_48 -> V_378 ) ;
V_48 -> V_378 . V_409 = F_222 ;
V_48 -> V_378 . V_132 = ( unsigned long ) V_48 ;
V_48 -> V_84 = F_144 ( V_410 ) ;
V_48 -> V_74 = V_74 ;
for ( V_179 = 0 ; V_179 < V_180 ; ++ V_179 )
F_251 ( & V_48 -> V_112 [ V_179 ] ) ;
}
static int F_252 ( struct V_14 * V_165 [] , struct V_14 * V_132 [] )
{
if ( V_165 [ V_411 ] ) {
if ( F_11 ( V_165 [ V_411 ] ) != V_80 ) {
F_253 ( L_15 ) ;
return - V_168 ;
}
if ( ! F_254 ( F_255 ( V_165 [ V_411 ] ) ) ) {
F_253 ( L_16 ) ;
return - V_170 ;
}
}
if ( ! V_132 )
return - V_168 ;
if ( V_132 [ V_412 ] ) {
V_96 V_26 = F_106 ( V_132 [ V_412 ] ) ;
if ( V_26 >= V_413 )
return - V_414 ;
}
if ( V_132 [ V_415 ] ) {
const struct V_416 * V_116
= F_255 ( V_132 [ V_415 ] ) ;
if ( F_21 ( V_116 -> V_417 ) < F_21 ( V_116 -> V_418 ) ) {
F_253 ( L_17 ,
F_21 ( V_116 -> V_418 ) , F_21 ( V_116 -> V_417 ) ) ;
return - V_168 ;
}
}
return 0 ;
}
static void F_256 ( struct V_103 * V_419 ,
struct V_420 * V_421 )
{
F_257 ( V_421 -> V_284 , V_422 , sizeof( V_421 -> V_284 ) ) ;
F_257 ( V_421 -> V_423 , L_18 , sizeof( V_421 -> V_423 ) ) ;
}
static void F_258 ( struct V_193 * V_194 )
{
struct V_24 * V_25 = F_97 ( V_194 , struct V_24 , V_192 ) ;
F_259 ( V_25 -> V_43 ) ;
F_115 ( V_25 , V_162 ) ;
}
static struct V_424 * F_260 ( struct V_29 * V_29 , bool V_379 ,
T_2 V_30 , T_1 V_53 )
{
struct V_424 * V_43 ;
struct V_425 V_426 ;
int V_98 ;
memset ( & V_426 , 0 , sizeof( V_426 ) ) ;
if ( V_379 ) {
V_426 . V_42 = V_6 ;
V_426 . V_427 =
! ( V_53 & V_428 ) ;
V_426 . V_429 =
! ( V_53 & V_430 ) ;
} else {
V_426 . V_42 = V_18 ;
V_426 . V_431 . V_10 = V_12 ;
V_426 . V_432 =
! ! ( V_53 & V_433 ) ;
}
V_426 . V_434 = V_30 ;
V_98 = F_261 ( V_29 , & V_426 , & V_43 ) ;
if ( V_98 < 0 )
return F_262 ( V_98 ) ;
return V_43 ;
}
static struct V_24 * F_263 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_210 , void * V_132 ,
T_1 V_53 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
struct V_424 * V_43 ;
unsigned int V_179 ;
bool V_379 = ! ! ( V_53 & V_380 ) ;
struct V_435 V_436 ;
V_25 = F_264 ( sizeof( * V_25 ) , V_437 ) ;
if ( ! V_25 )
return F_262 ( - V_158 ) ;
for ( V_179 = 0 ; V_179 < V_438 ; ++ V_179 )
F_251 ( & V_25 -> V_27 [ V_179 ] ) ;
F_249 ( & V_25 -> V_192 , F_258 ) ;
V_43 = F_260 ( V_29 , V_379 , V_30 , V_53 ) ;
if ( F_197 ( V_43 ) ) {
F_99 ( V_25 ) ;
return F_265 ( V_43 ) ;
}
V_25 -> V_43 = V_43 ;
F_266 ( & V_25 -> V_189 , 1 ) ;
V_25 -> V_210 = V_210 ;
V_25 -> V_132 = V_132 ;
V_25 -> V_142 . V_30 = V_30 ;
V_25 -> V_142 . V_136 . V_137 = F_68 ;
V_25 -> V_142 . V_136 . V_141 = F_81 ;
F_123 ( & V_32 -> V_190 ) ;
F_95 ( & V_25 -> V_159 , F_19 ( V_29 , V_30 ) ) ;
F_84 ( V_25 ) ;
F_125 ( & V_32 -> V_190 ) ;
V_436 . V_439 = V_25 ;
V_436 . V_440 = 1 ;
V_436 . V_441 = F_140 ;
V_436 . V_442 = NULL ;
F_267 ( V_29 , V_43 , & V_436 ) ;
return V_25 ;
}
struct V_24 * F_268 ( struct V_29 * V_29 , T_2 V_30 ,
T_11 * V_210 , void * V_132 ,
bool V_443 , T_1 V_53 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_24 * V_25 ;
bool V_379 = V_53 & V_380 ;
V_25 = F_263 ( V_29 , V_30 , V_210 , V_132 , V_53 ) ;
if ( ! F_197 ( V_25 ) )
return V_25 ;
if ( V_443 )
return V_25 ;
F_123 ( & V_32 -> V_190 ) ;
V_25 = F_26 ( V_29 , V_379 ? V_6 : V_18 , V_30 ) ;
if ( V_25 && ( ( V_25 -> V_210 != V_210 ) ||
! F_230 ( & V_25 -> V_189 , 1 , 0 ) ) )
V_25 = F_262 ( - V_444 ) ;
F_125 ( & V_32 -> V_190 ) ;
if ( ! V_25 )
V_25 = F_262 ( - V_168 ) ;
return V_25 ;
}
static void V_408 ( struct V_193 * V_194 )
{
struct V_47 * V_48 = F_97 ( V_194 , struct V_47 , V_381 ) ;
struct V_29 * V_29 = V_48 -> V_29 ;
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
T_2 V_30 = V_48 -> V_84 ;
struct V_24 * V_445 ;
V_445 = F_268 ( V_29 , V_30 , F_146 , NULL , false , V_48 -> V_53 ) ;
F_123 ( & V_32 -> V_190 ) ;
if ( ! F_197 ( V_445 ) )
F_227 ( V_445 , V_48 ) ;
F_125 ( & V_32 -> V_190 ) ;
F_137 ( V_48 -> V_74 ) ;
}
static int F_269 ( struct V_29 * V_446 , struct V_103 * V_74 ,
struct V_14 * V_165 [] , struct V_14 * V_132 [] )
{
struct V_31 * V_32 = F_20 ( V_446 , V_33 ) ;
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_36 * V_311 = & V_48 -> V_49 ;
V_96 V_114 ;
int V_98 ;
bool V_447 = false ;
if ( ! V_132 [ V_412 ] )
return - V_168 ;
V_48 -> V_29 = V_446 ;
V_114 = F_106 ( V_132 [ V_412 ] ) ;
V_311 -> V_50 = V_114 ;
V_311 -> V_68 . V_4 . V_5 = V_18 ;
if ( V_132 [ V_448 ] ) {
V_311 -> V_68 . sin . V_9 . V_10 = F_13 ( V_132 [ V_448 ] ) ;
} else if ( V_132 [ V_449 ] ) {
if ( ! F_104 ( V_166 ) )
return - V_450 ;
F_12 ( & V_311 -> V_68 . V_7 . V_8 , V_132 [ V_449 ] ,
sizeof( struct V_16 ) ) ;
V_311 -> V_68 . V_4 . V_5 = V_6 ;
V_447 = true ;
}
if ( V_132 [ V_451 ] ) {
V_48 -> V_217 . sin . V_9 . V_10 = F_13 ( V_132 [ V_451 ] ) ;
V_48 -> V_217 . V_4 . V_5 = V_18 ;
} else if ( V_132 [ V_452 ] ) {
if ( ! F_104 ( V_166 ) )
return - V_450 ;
F_12 ( & V_48 -> V_217 . V_7 . V_8 , V_132 [ V_452 ] ,
sizeof( struct V_16 ) ) ;
V_48 -> V_217 . V_4 . V_5 = V_6 ;
V_447 = true ;
}
if ( V_132 [ V_453 ] &&
( V_311 -> V_87 = F_106 ( V_132 [ V_453 ] ) ) ) {
struct V_103 * V_384
= F_107 ( V_446 , V_311 -> V_87 ) ;
if ( ! V_384 ) {
F_109 ( L_19 , V_311 -> V_87 ) ;
return - V_454 ;
}
#if F_104 ( V_166 )
if ( V_447 ) {
struct V_301 * V_455 = F_191 ( V_384 ) ;
if ( V_455 && V_455 -> V_456 . V_457 ) {
F_109 ( L_20 ) ;
return - V_458 ;
}
V_48 -> V_53 |= V_380 ;
}
#endif
if ( ! V_165 [ V_459 ] )
V_74 -> V_386 = V_384 -> V_386 - ( V_447 ? V_387 : V_388 ) ;
V_74 -> V_390 = V_384 -> V_460 +
( V_447 ? V_387 : V_388 ) ;
} else if ( V_447 )
V_48 -> V_53 |= V_380 ;
if ( V_132 [ V_461 ] )
V_48 -> V_224 = F_270 ( V_132 [ V_461 ] ) ;
if ( V_132 [ V_462 ] )
V_48 -> V_313 = F_270 ( V_132 [ V_462 ] ) ;
if ( ! V_132 [ V_463 ] || F_270 ( V_132 [ V_463 ] ) )
V_48 -> V_53 |= V_222 ;
if ( V_132 [ V_464 ] )
V_48 -> V_376 = F_106 ( V_132 [ V_464 ] ) ;
else
V_48 -> V_376 = V_465 ;
if ( V_132 [ V_466 ] && F_270 ( V_132 [ V_466 ] ) )
V_48 -> V_53 |= V_366 ;
if ( V_132 [ V_467 ] && F_270 ( V_132 [ V_467 ] ) )
V_48 -> V_53 |= V_367 ;
if ( V_132 [ V_468 ] && F_270 ( V_132 [ V_468 ] ) )
V_48 -> V_53 |= V_369 ;
if ( V_132 [ V_469 ] && F_270 ( V_132 [ V_469 ] ) )
V_48 -> V_53 |= V_265 ;
if ( V_132 [ V_470 ] )
V_48 -> V_155 = F_106 ( V_132 [ V_470 ] ) ;
if ( V_132 [ V_415 ] ) {
const struct V_416 * V_116
= F_255 ( V_132 [ V_415 ] ) ;
V_48 -> V_340 = F_21 ( V_116 -> V_418 ) ;
V_48 -> V_341 = F_21 ( V_116 -> V_417 ) ;
}
if ( V_132 [ V_471 ] )
V_48 -> V_84 = F_105 ( V_132 [ V_471 ] ) ;
if ( V_132 [ V_472 ] && F_270 ( V_132 [ V_472 ] ) )
V_48 -> V_53 |= V_433 ;
if ( V_132 [ V_473 ] &&
F_270 ( V_132 [ V_473 ] ) )
V_48 -> V_53 |= V_428 ;
if ( V_132 [ V_474 ] &&
F_270 ( V_132 [ V_474 ] ) )
V_48 -> V_53 |= V_430 ;
if ( F_30 ( V_446 , V_114 , V_447 ? V_6 : V_18 ,
V_48 -> V_84 ) ) {
F_109 ( L_21 , V_114 ) ;
return - V_148 ;
}
V_74 -> V_475 = & V_476 ;
if ( ! F_3 ( & V_48 -> V_49 . V_68 ) ) {
V_98 = F_91 ( V_48 , V_368 ,
& V_48 -> V_49 . V_68 ,
V_173 | V_172 ,
V_147 | V_153 ,
V_48 -> V_84 ,
V_48 -> V_49 . V_50 ,
V_48 -> V_49 . V_87 ,
V_187 ) ;
if ( V_98 )
return V_98 ;
}
V_98 = F_271 ( V_74 ) ;
if ( V_98 ) {
F_232 ( V_48 ) ;
return V_98 ;
}
F_272 ( & V_48 -> V_40 , & V_32 -> V_477 ) ;
return 0 ;
}
static void F_273 ( struct V_103 * V_74 , struct V_478 * V_113 )
{
struct V_47 * V_48 = F_51 ( V_74 ) ;
struct V_31 * V_32 = F_20 ( V_48 -> V_29 , V_33 ) ;
F_123 ( & V_32 -> V_190 ) ;
if ( ! F_274 ( & V_48 -> V_159 ) )
F_101 ( & V_48 -> V_159 ) ;
F_125 ( & V_32 -> V_190 ) ;
F_275 ( & V_48 -> V_40 ) ;
F_276 ( V_74 , V_113 ) ;
}
static T_4 F_277 ( const struct V_103 * V_74 )
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
F_42 ( sizeof( struct V_416 ) ) +
F_42 ( sizeof( T_2 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
F_42 ( sizeof( T_8 ) ) +
0 ;
}
static int F_278 ( struct V_20 * V_21 , const struct V_103 * V_74 )
{
const struct V_47 * V_48 = F_51 ( V_74 ) ;
const struct V_36 * V_311 = & V_48 -> V_49 ;
struct V_416 V_479 = {
. V_418 = F_144 ( V_48 -> V_340 ) ,
. V_417 = F_144 ( V_48 -> V_341 ) ,
} ;
if ( F_36 ( V_21 , V_412 , V_311 -> V_50 ) )
goto V_81;
if ( ! F_3 ( & V_311 -> V_68 ) ) {
if ( V_311 -> V_68 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_448 ,
V_311 -> V_68 . sin . V_9 . V_10 ) )
goto V_81;
#if F_104 ( V_166 )
} else {
if ( F_15 ( V_21 , V_449 , sizeof( struct V_16 ) ,
& V_311 -> V_68 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( V_311 -> V_87 && F_36 ( V_21 , V_453 , V_311 -> V_87 ) )
goto V_81;
if ( ! F_3 ( & V_48 -> V_217 ) ) {
if ( V_48 -> V_217 . V_4 . V_5 == V_18 ) {
if ( F_16 ( V_21 , V_451 ,
V_48 -> V_217 . sin . V_9 . V_10 ) )
goto V_81;
#if F_104 ( V_166 )
} else {
if ( F_15 ( V_21 , V_452 , sizeof( struct V_16 ) ,
& V_48 -> V_217 . V_7 . V_8 ) )
goto V_81;
#endif
}
}
if ( F_279 ( V_21 , V_462 , V_48 -> V_313 ) ||
F_279 ( V_21 , V_461 , V_48 -> V_224 ) ||
F_279 ( V_21 , V_463 ,
! ! ( V_48 -> V_53 & V_222 ) ) ||
F_279 ( V_21 , V_466 ,
! ! ( V_48 -> V_53 & V_366 ) ) ||
F_279 ( V_21 , V_467 , ! ! ( V_48 -> V_53 & V_367 ) ) ||
F_279 ( V_21 , V_468 ,
! ! ( V_48 -> V_53 & V_369 ) ) ||
F_279 ( V_21 , V_469 ,
! ! ( V_48 -> V_53 & V_265 ) ) ||
F_36 ( V_21 , V_464 , V_48 -> V_376 ) ||
F_36 ( V_21 , V_470 , V_48 -> V_155 ) ||
F_35 ( V_21 , V_471 , V_48 -> V_84 ) ||
F_279 ( V_21 , V_472 ,
! ! ( V_48 -> V_53 & V_433 ) ) ||
F_279 ( V_21 , V_473 ,
! ! ( V_48 -> V_53 & V_428 ) ) ||
F_279 ( V_21 , V_474 ,
! ! ( V_48 -> V_53 & V_430 ) ) )
goto V_81;
if ( F_15 ( V_21 , V_415 , sizeof( V_479 ) , & V_479 ) )
goto V_81;
return 0 ;
V_81:
return - V_65 ;
}
static void F_280 ( struct V_31 * V_32 ,
struct V_103 * V_74 )
{
struct V_47 * V_48 , * V_40 ;
F_281 ( V_480 ) ;
F_98 (vxlan, next, &vn->vxlan_list, next) {
struct V_36 * V_311 = & V_48 -> V_49 ;
if ( V_311 -> V_87 == V_74 -> V_75 )
F_273 ( V_48 -> V_74 , & V_480 ) ;
}
F_282 ( & V_480 ) ;
}
static int F_283 ( struct V_481 * V_482 ,
unsigned long V_483 , void * V_484 )
{
struct V_103 * V_74 = F_284 ( V_484 ) ;
struct V_31 * V_32 = F_20 ( F_44 ( V_74 ) , V_33 ) ;
if ( V_483 == V_485 )
F_280 ( V_32 , V_74 ) ;
return V_486 ;
}
static T_12 int F_285 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
unsigned int V_179 ;
F_94 ( & V_32 -> V_477 ) ;
F_248 ( & V_32 -> V_190 ) ;
for ( V_179 = 0 ; V_179 < V_389 ; ++ V_179 )
F_251 ( & V_32 -> V_34 [ V_179 ] ) ;
return 0 ;
}
static void T_13 F_286 ( struct V_29 * V_29 )
{
struct V_31 * V_32 = F_20 ( V_29 , V_33 ) ;
struct V_47 * V_48 , * V_40 ;
struct V_103 * V_74 , * V_487 ;
F_281 ( V_41 ) ;
F_287 () ;
F_288 (net, dev, aux)
if ( V_74 -> V_488 == & V_489 )
F_276 ( V_74 , & V_41 ) ;
F_98 (vxlan, next, &vn->vxlan_list, next) {
if ( ! F_149 ( F_44 ( V_48 -> V_74 ) , V_29 ) )
F_276 ( V_74 , & V_41 ) ;
}
F_282 ( & V_41 ) ;
F_289 () ;
}
static int T_14 F_290 ( void )
{
int V_150 ;
V_191 = F_291 ( L_18 , 0 , 0 ) ;
if ( ! V_191 )
return - V_158 ;
F_292 ( & V_490 , sizeof( V_490 ) ) ;
V_150 = F_293 ( & V_491 ) ;
if ( V_150 )
goto V_492;
V_150 = F_294 ( & V_493 ) ;
if ( V_150 )
goto V_494;
V_150 = F_295 ( & V_489 ) ;
if ( V_150 )
goto V_495;
return 0 ;
V_495:
F_296 ( & V_493 ) ;
V_494:
F_297 ( & V_491 ) ;
V_492:
F_298 ( V_191 ) ;
return V_150 ;
}
static void T_15 F_299 ( void )
{
F_300 ( & V_489 ) ;
F_296 ( & V_493 ) ;
F_298 ( V_191 ) ;
F_297 ( & V_491 ) ;
}
