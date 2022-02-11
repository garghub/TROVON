static inline bool
F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = & V_4 -> V_7 . V_8 ;
return F_2 ( V_6 -> V_9 , V_2 -> V_9 . V_10 , V_2 -> V_11 ) &&
F_2 ( V_6 -> V_12 , V_2 -> V_12 . V_10 , V_2 -> V_13 ) &&
! ( ( F_3 ( V_4 , & V_6 -> V_14 ) ^ V_2 -> V_15 ) & V_2 -> V_16 ) &&
! ( ( F_4 ( V_4 , & V_6 -> V_14 ) ^ V_2 -> V_17 ) & V_2 -> V_18 ) &&
( V_6 -> V_19 == V_2 -> V_20 || ! V_2 -> V_20 ) &&
( V_6 -> V_21 == V_2 -> V_22 || ! V_2 -> V_22 ) ;
}
static inline bool
F_5 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_23 * V_24 = & V_4 -> V_7 . V_25 ;
return F_6 ( & V_24 -> V_9 , & V_2 -> V_9 , V_2 -> V_11 ) &&
F_6 ( & V_24 -> V_12 , & V_2 -> V_12 , V_2 -> V_13 ) &&
! ( ( F_3 ( V_4 , & V_24 -> V_14 ) ^ V_2 -> V_15 ) & V_2 -> V_16 ) &&
! ( ( F_4 ( V_4 , & V_24 -> V_14 ) ^ V_2 -> V_17 ) & V_2 -> V_18 ) &&
( V_24 -> V_26 == V_2 -> V_20 || ! V_2 -> V_20 ) &&
( V_24 -> V_27 == V_2 -> V_22 || ! V_2 -> V_22 ) ;
}
bool F_7 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned short V_28 )
{
switch ( V_28 ) {
case V_29 :
return F_1 ( V_2 , V_4 ) ;
case V_30 :
return F_5 ( V_2 , V_4 ) ;
}
return false ;
}
static struct V_31 * F_8 ( unsigned short V_28 )
{
struct V_31 * V_32 ;
if ( F_9 ( V_28 >= V_33 ) )
return NULL ;
F_10 () ;
V_32 = F_11 ( V_31 [ V_28 ] ) ;
if ( F_9 ( ! V_32 ) )
F_12 () ;
return V_32 ;
}
static void F_13 ( struct V_31 * V_32 )
{
F_12 () ;
}
static inline struct V_34 * F_14 ( struct V_35 * V_35 , int V_36 ,
const T_1 * V_12 ,
const T_1 * V_9 ,
int V_28 )
{
struct V_31 * V_32 ;
struct V_34 * V_37 ;
V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return F_15 ( - V_38 ) ;
V_37 = V_32 -> V_39 ( V_35 , V_36 , V_12 , V_9 ) ;
F_13 ( V_32 ) ;
return V_37 ;
}
static inline struct V_34 * F_16 ( struct V_40 * V_41 , int V_36 ,
T_1 * V_42 ,
T_1 * V_43 ,
int V_28 )
{
struct V_35 * V_35 = F_17 ( V_41 ) ;
T_1 * V_12 = & V_41 -> V_44 . V_12 ;
T_1 * V_9 = & V_41 -> V_45 . V_9 ;
struct V_34 * V_37 ;
if ( V_41 -> type -> V_46 & V_47 ) {
V_12 = V_41 -> V_48 ;
V_9 = V_43 ;
}
if ( V_41 -> type -> V_46 & V_49 ) {
V_12 = V_42 ;
V_9 = V_41 -> V_48 ;
}
V_37 = F_14 ( V_35 , V_36 , V_12 , V_9 , V_28 ) ;
if ( ! F_18 ( V_37 ) ) {
if ( V_42 != V_12 )
memcpy ( V_42 , V_12 , sizeof( * V_42 ) ) ;
if ( V_43 != V_9 )
memcpy ( V_43 , V_9 , sizeof( * V_43 ) ) ;
}
return V_37 ;
}
static inline unsigned long F_19 ( long V_50 )
{
if ( V_50 >= ( V_51 - 1 ) / V_52 )
return V_51 - 1 ;
else
return V_50 * V_52 ;
}
static void F_20 ( unsigned long V_53 )
{
struct V_54 * V_55 = (struct V_54 * ) V_53 ;
unsigned long V_56 = F_21 () ;
long V_57 = V_58 ;
int V_59 = 0 ;
int V_60 ;
F_22 ( & V_55 -> V_61 ) ;
if ( F_9 ( V_55 -> V_62 . V_63 ) )
goto V_64;
V_60 = F_23 ( V_55 -> V_65 ) ;
if ( V_55 -> V_66 . V_67 ) {
long V_68 = V_55 -> V_66 . V_67 +
V_55 -> V_69 . V_70 - V_56 ;
if ( V_68 <= 0 )
goto V_71;
if ( V_68 < V_57 )
V_57 = V_68 ;
}
if ( V_55 -> V_66 . V_72 ) {
long V_68 = V_55 -> V_66 . V_72 +
( V_55 -> V_69 . V_73 ? : V_55 -> V_69 . V_70 ) - V_56 ;
if ( V_68 <= 0 )
goto V_71;
if ( V_68 < V_57 )
V_57 = V_68 ;
}
if ( V_55 -> V_66 . V_74 ) {
long V_68 = V_55 -> V_66 . V_74 +
V_55 -> V_69 . V_70 - V_56 ;
if ( V_68 <= 0 ) {
V_59 = 1 ;
V_68 = V_75 ;
}
if ( V_68 < V_57 )
V_57 = V_68 ;
}
if ( V_55 -> V_66 . V_76 ) {
long V_68 = V_55 -> V_66 . V_76 +
( V_55 -> V_69 . V_73 ? : V_55 -> V_69 . V_70 ) - V_56 ;
if ( V_68 <= 0 ) {
V_59 = 1 ;
V_68 = V_75 ;
}
if ( V_68 < V_57 )
V_57 = V_68 ;
}
if ( V_59 )
F_24 ( V_55 , V_60 , 0 , 0 ) ;
if ( V_57 != V_58 &&
! F_25 ( & V_55 -> V_77 , V_78 + F_19 ( V_57 ) ) )
F_26 ( V_55 ) ;
V_64:
F_27 ( & V_55 -> V_61 ) ;
F_28 ( V_55 ) ;
return;
V_71:
F_27 ( & V_55 -> V_61 ) ;
if ( ! F_29 ( V_55 , V_60 ) )
F_24 ( V_55 , V_60 , 1 , 0 ) ;
F_28 ( V_55 ) ;
}
static struct V_79 * F_30 ( struct V_79 * V_80 )
{
struct V_54 * V_81 = F_31 ( V_80 , struct V_54 , V_80 ) ;
if ( F_9 ( V_81 -> V_62 . V_63 ) )
V_80 = NULL ;
else
F_26 ( V_81 ) ;
return V_80 ;
}
static int F_32 ( struct V_79 * V_80 )
{
struct V_54 * V_81 = F_31 ( V_80 , struct V_54 , V_80 ) ;
return ! V_81 -> V_62 . V_63 ;
}
static void F_33 ( struct V_79 * V_80 )
{
F_28 ( F_31 ( V_80 , struct V_54 , V_80 ) ) ;
}
struct V_54 * F_34 ( struct V_35 * V_35 , T_2 V_82 )
{
struct V_54 * V_83 ;
V_83 = F_35 ( sizeof( struct V_54 ) , V_82 ) ;
if ( V_83 ) {
F_36 ( & V_83 -> V_84 , V_35 ) ;
F_37 ( & V_83 -> V_62 . V_85 ) ;
F_38 ( & V_83 -> V_86 ) ;
F_38 ( & V_83 -> V_87 ) ;
F_39 ( & V_83 -> V_61 ) ;
F_40 ( & V_83 -> V_88 , 1 ) ;
F_41 ( & V_83 -> V_89 . V_90 ) ;
F_42 ( & V_83 -> V_77 , F_20 ,
( unsigned long ) V_83 ) ;
F_42 ( & V_83 -> V_89 . V_91 , V_92 ,
( unsigned long ) V_83 ) ;
V_83 -> V_80 . V_93 = & V_94 ;
}
return V_83 ;
}
void F_43 ( struct V_54 * V_83 )
{
F_44 ( ! V_83 -> V_62 . V_63 ) ;
if ( F_45 ( & V_83 -> V_77 ) || F_45 ( & V_83 -> V_89 . V_91 ) )
F_46 () ;
F_47 ( V_83 -> V_95 ) ;
F_48 ( V_83 ) ;
}
static void F_49 ( struct V_54 * V_83 )
{
V_83 -> V_62 . V_63 = 1 ;
F_50 ( & V_83 -> V_96 ) ;
if ( F_45 ( & V_83 -> V_89 . V_91 ) )
F_28 ( V_83 ) ;
F_51 ( & V_83 -> V_89 . V_90 ) ;
if ( F_45 ( & V_83 -> V_77 ) )
F_28 ( V_83 ) ;
F_28 ( V_83 ) ;
}
static inline unsigned int F_52 ( struct V_35 * V_35 , T_3 V_65 )
{
return F_53 ( V_65 , V_35 -> V_97 . V_98 ) ;
}
static void F_54 ( struct V_35 * V_35 ,
unsigned short V_28 , int V_60 ,
T_4 * V_99 , T_4 * V_100 )
{
switch ( V_28 ) {
case V_29 :
* V_99 = V_35 -> V_97 . V_101 [ V_60 ] . V_102 ;
* V_100 = V_35 -> V_97 . V_101 [ V_60 ] . V_103 ;
break;
case V_30 :
* V_99 = V_35 -> V_97 . V_101 [ V_60 ] . V_104 ;
* V_100 = V_35 -> V_97 . V_101 [ V_60 ] . V_105 ;
break;
default:
* V_99 = 0 ;
* V_100 = 0 ;
}
}
static struct V_106 * F_55 ( struct V_35 * V_35 ,
const struct V_1 * V_2 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_107 = V_35 -> V_97 . V_101 [ V_60 ] . V_107 ;
unsigned int V_108 ;
T_4 V_99 ;
T_4 V_100 ;
F_54 ( V_35 , V_28 , V_60 , & V_99 , & V_100 ) ;
V_108 = F_56 ( V_2 , V_28 , V_107 , V_99 , V_100 ) ;
return ( V_108 == V_107 + 1 ?
& V_35 -> V_97 . V_109 [ V_60 ] :
V_35 -> V_97 . V_101 [ V_60 ] . V_110 + V_108 ) ;
}
static struct V_106 * F_57 ( struct V_35 * V_35 ,
const T_1 * V_9 ,
const T_1 * V_12 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_107 = V_35 -> V_97 . V_101 [ V_60 ] . V_107 ;
unsigned int V_108 ;
T_4 V_99 ;
T_4 V_100 ;
F_54 ( V_35 , V_28 , V_60 , & V_99 , & V_100 ) ;
V_108 = F_58 ( V_9 , V_12 , V_28 , V_107 , V_99 , V_100 ) ;
return V_35 -> V_97 . V_101 [ V_60 ] . V_110 + V_108 ;
}
static void F_59 ( struct V_35 * V_35 ,
struct V_106 * V_111 ,
struct V_106 * V_112 ,
unsigned int V_113 ,
int V_60 )
{
struct V_114 * V_115 , * V_116 = NULL ;
struct V_54 * V_81 ;
unsigned int V_117 = 0 ;
T_4 V_99 ;
T_4 V_100 ;
V_118:
F_60 (pol, tmp, list, bydst) {
unsigned int V_119 ;
F_54 ( V_35 , V_81 -> V_28 , V_60 , & V_99 , & V_100 ) ;
V_119 = F_58 ( & V_81 -> V_120 . V_9 , & V_81 -> V_120 . V_12 ,
V_81 -> V_28 , V_113 , V_99 , V_100 ) ;
if ( ! V_116 ) {
F_61 ( & V_81 -> V_86 ) ;
F_62 ( & V_81 -> V_86 , V_112 + V_119 ) ;
V_117 = V_119 ;
} else {
if ( V_119 != V_117 )
continue;
F_61 ( & V_81 -> V_86 ) ;
F_63 ( & V_81 -> V_86 , V_116 ) ;
}
V_116 = & V_81 -> V_86 ;
}
if ( ! F_64 ( V_111 ) ) {
V_116 = NULL ;
goto V_118;
}
}
static void F_65 ( struct V_106 * V_111 ,
struct V_106 * V_121 ,
unsigned int V_113 )
{
struct V_114 * V_115 ;
struct V_54 * V_81 ;
F_60 (pol, tmp, list, byidx) {
unsigned int V_119 ;
V_119 = F_53 ( V_81 -> V_65 , V_113 ) ;
F_62 ( & V_81 -> V_87 , V_121 + V_119 ) ;
}
}
static unsigned long F_66 ( unsigned int V_122 )
{
return ( ( V_122 + 1 ) << 1 ) - 1 ;
}
static void F_67 ( struct V_35 * V_35 , int V_60 )
{
unsigned int V_107 = V_35 -> V_97 . V_101 [ V_60 ] . V_107 ;
unsigned int V_113 = F_66 ( V_107 ) ;
unsigned int V_123 = ( V_113 + 1 ) * sizeof( struct V_106 ) ;
struct V_106 * V_124 = V_35 -> V_97 . V_101 [ V_60 ] . V_110 ;
struct V_106 * V_125 = F_68 ( V_123 ) ;
int V_126 ;
if ( ! V_125 )
return;
F_69 ( & V_35 -> V_97 . V_127 ) ;
for ( V_126 = V_107 ; V_126 >= 0 ; V_126 -- )
F_59 ( V_35 , V_124 + V_126 , V_125 , V_113 , V_60 ) ;
V_35 -> V_97 . V_101 [ V_60 ] . V_110 = V_125 ;
V_35 -> V_97 . V_101 [ V_60 ] . V_107 = V_113 ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
F_71 ( V_124 , ( V_107 + 1 ) * sizeof( struct V_106 ) ) ;
}
static void F_72 ( struct V_35 * V_35 , int V_128 )
{
unsigned int V_107 = V_35 -> V_97 . V_98 ;
unsigned int V_113 = F_66 ( V_107 ) ;
unsigned int V_123 = ( V_113 + 1 ) * sizeof( struct V_106 ) ;
struct V_106 * V_129 = V_35 -> V_97 . V_130 ;
struct V_106 * V_131 = F_68 ( V_123 ) ;
int V_126 ;
if ( ! V_131 )
return;
F_69 ( & V_35 -> V_97 . V_127 ) ;
for ( V_126 = V_107 ; V_126 >= 0 ; V_126 -- )
F_65 ( V_129 + V_126 , V_131 , V_113 ) ;
V_35 -> V_97 . V_130 = V_131 ;
V_35 -> V_97 . V_98 = V_113 ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
F_71 ( V_129 , ( V_107 + 1 ) * sizeof( struct V_106 ) ) ;
}
static inline int F_73 ( struct V_35 * V_35 , int V_60 , int * V_128 )
{
unsigned int V_132 = V_35 -> V_97 . V_133 [ V_60 ] ;
unsigned int V_107 = V_35 -> V_97 . V_101 [ V_60 ] . V_107 ;
if ( V_128 )
* V_128 += V_132 ;
if ( ( V_107 + 1 ) < V_134 &&
V_132 > V_107 )
return 1 ;
return 0 ;
}
static inline int F_74 ( struct V_35 * V_35 , int V_128 )
{
unsigned int V_107 = V_35 -> V_97 . V_98 ;
if ( ( V_107 + 1 ) < V_134 &&
V_128 > V_107 )
return 1 ;
return 0 ;
}
void F_75 ( struct V_35 * V_35 , struct V_135 * V_136 )
{
F_76 ( & V_35 -> V_97 . V_127 ) ;
V_136 -> V_137 = V_35 -> V_97 . V_133 [ V_138 ] ;
V_136 -> V_139 = V_35 -> V_97 . V_133 [ V_140 ] ;
V_136 -> V_141 = V_35 -> V_97 . V_133 [ V_142 ] ;
V_136 -> V_143 = V_35 -> V_97 . V_133 [ V_138 + V_144 ] ;
V_136 -> V_145 = V_35 -> V_97 . V_133 [ V_140 + V_144 ] ;
V_136 -> V_146 = V_35 -> V_97 . V_133 [ V_142 + V_144 ] ;
V_136 -> V_147 = V_35 -> V_97 . V_98 ;
V_136 -> V_148 = V_134 ;
F_77 ( & V_35 -> V_97 . V_127 ) ;
}
static void F_78 ( struct V_149 * V_150 )
{
struct V_35 * V_35 = F_31 ( V_150 , struct V_35 , V_97 . V_151 ) ;
int V_60 , V_128 ;
F_79 ( & V_152 ) ;
V_128 = 0 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ ) {
if ( F_73 ( V_35 , V_60 , & V_128 ) )
F_67 ( V_35 , V_60 ) ;
}
if ( F_74 ( V_35 , V_128 ) )
F_72 ( V_35 , V_128 ) ;
F_80 ( & V_152 ) ;
}
static void F_81 ( struct V_149 * V_150 )
{
struct V_35 * V_35 = F_31 ( V_150 , struct V_35 ,
V_97 . V_153 . V_150 ) ;
unsigned int V_107 ;
struct V_54 * V_81 ;
struct V_54 * V_83 ;
struct V_106 * V_154 ;
struct V_106 * V_124 ;
struct V_114 * V_155 ;
int V_126 ;
int V_60 ;
unsigned V_156 ;
T_4 V_157 , V_158 , V_159 , V_160 ;
F_79 ( & V_152 ) ;
do {
V_156 = F_82 ( & V_35 -> V_97 . V_153 . V_61 ) ;
V_157 = V_35 -> V_97 . V_153 . V_157 ;
V_158 = V_35 -> V_97 . V_153 . V_158 ;
V_159 = V_35 -> V_97 . V_153 . V_159 ;
V_160 = V_35 -> V_97 . V_153 . V_160 ;
} while ( F_83 ( & V_35 -> V_97 . V_153 . V_61 , V_156 ) );
F_69 ( & V_35 -> V_97 . V_127 ) ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ ) {
F_84 ( & V_35 -> V_97 . V_109 [ V_60 ] ) ;
V_107 = V_35 -> V_97 . V_101 [ V_60 ] . V_107 ;
V_124 = V_35 -> V_97 . V_101 [ V_60 ] . V_110 ;
for ( V_126 = V_107 ; V_126 >= 0 ; V_126 -- )
F_84 ( V_124 + V_126 ) ;
if ( ( V_60 & V_161 ) == V_140 ) {
V_35 -> V_97 . V_101 [ V_60 ] . V_102 = V_158 ;
V_35 -> V_97 . V_101 [ V_60 ] . V_103 = V_157 ;
V_35 -> V_97 . V_101 [ V_60 ] . V_104 = V_160 ;
V_35 -> V_97 . V_101 [ V_60 ] . V_105 = V_159 ;
} else {
V_35 -> V_97 . V_101 [ V_60 ] . V_102 = V_157 ;
V_35 -> V_97 . V_101 [ V_60 ] . V_103 = V_158 ;
V_35 -> V_97 . V_101 [ V_60 ] . V_104 = V_159 ;
V_35 -> V_97 . V_101 [ V_60 ] . V_105 = V_160 ;
}
}
F_85 (policy, &net->xfrm.policy_all, walk.all) {
V_155 = NULL ;
V_154 = F_55 ( V_35 , & V_83 -> V_120 ,
V_83 -> V_28 ,
F_23 ( V_83 -> V_65 ) ) ;
F_86 (pol, chain, bydst) {
if ( V_83 -> V_162 >= V_81 -> V_162 )
V_155 = & V_81 -> V_86 ;
else
break;
}
if ( V_155 )
F_63 ( & V_83 -> V_86 , V_155 ) ;
else
F_62 ( & V_83 -> V_86 , V_154 ) ;
}
F_70 ( & V_35 -> V_97 . V_127 ) ;
F_80 ( & V_152 ) ;
}
void F_87 ( struct V_35 * V_35 )
{
F_88 ( & V_35 -> V_97 . V_153 . V_150 ) ;
}
static T_3 F_89 ( struct V_35 * V_35 , int V_60 , T_3 V_65 )
{
static T_3 V_163 ;
for (; ; ) {
struct V_106 * V_111 ;
struct V_54 * V_164 ;
T_3 V_165 ;
int V_166 ;
if ( ! V_65 ) {
V_165 = ( V_163 | V_60 ) ;
V_163 += 8 ;
} else {
V_165 = V_65 ;
V_65 = 0 ;
}
if ( V_165 == 0 )
V_165 = 8 ;
V_111 = V_35 -> V_97 . V_130 + F_52 ( V_35 , V_165 ) ;
V_166 = 0 ;
F_86 (p, list, byidx) {
if ( V_164 -> V_65 == V_165 ) {
V_166 = 1 ;
break;
}
}
if ( ! V_166 )
return V_165 ;
}
}
static inline int F_90 ( struct V_1 * V_167 , struct V_1 * V_168 )
{
T_3 * V_169 = ( T_3 * ) V_167 ;
T_3 * V_170 = ( T_3 * ) V_168 ;
int V_171 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_126 ;
for ( V_126 = 0 ; V_126 < V_171 ; V_126 ++ ) {
if ( V_169 [ V_126 ] != V_170 [ V_126 ] )
return 1 ;
}
return 0 ;
}
static void F_91 ( struct V_54 * V_172 ,
struct V_54 * V_173 )
{
struct V_174 * V_175 = & V_172 -> V_89 ;
struct V_176 V_111 ;
if ( F_92 ( & V_175 -> V_90 ) )
return;
F_93 ( & V_111 ) ;
F_94 ( & V_175 -> V_90 . V_61 ) ;
F_95 ( & V_175 -> V_90 , & V_111 ) ;
if ( F_45 ( & V_175 -> V_91 ) )
F_28 ( V_172 ) ;
F_96 ( & V_175 -> V_90 . V_61 ) ;
V_175 = & V_173 -> V_89 ;
F_94 ( & V_175 -> V_90 . V_61 ) ;
F_97 ( & V_111 , & V_175 -> V_90 ) ;
V_175 -> V_177 = V_178 ;
if ( ! F_25 ( & V_175 -> V_91 , V_78 ) )
F_26 ( V_173 ) ;
F_96 ( & V_175 -> V_90 . V_61 ) ;
}
static bool F_98 ( struct V_54 * V_83 ,
struct V_54 * V_81 )
{
T_3 V_179 = V_83 -> V_179 . V_180 & V_83 -> V_179 . V_181 ;
if ( V_83 -> V_179 . V_180 == V_81 -> V_179 . V_180 && V_83 -> V_179 . V_181 == V_81 -> V_179 . V_181 )
return true ;
if ( ( V_179 & V_81 -> V_179 . V_181 ) == V_81 -> V_179 . V_180 &&
V_83 -> V_162 == V_81 -> V_162 )
return true ;
return false ;
}
int F_99 ( int V_60 , struct V_54 * V_83 , int V_182 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
struct V_54 * V_81 ;
struct V_54 * V_183 ;
struct V_106 * V_154 ;
struct V_114 * V_155 ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
V_154 = F_55 ( V_35 , & V_83 -> V_120 , V_83 -> V_28 , V_60 ) ;
V_183 = NULL ;
V_155 = NULL ;
F_86 (pol, chain, bydst) {
if ( V_81 -> type == V_83 -> type &&
! F_90 ( & V_81 -> V_120 , & V_83 -> V_120 ) &&
F_98 ( V_83 , V_81 ) &&
F_100 ( V_81 -> V_95 , V_83 -> V_95 ) &&
! F_101 ( V_183 ) ) {
if ( V_182 ) {
F_70 ( & V_35 -> V_97 . V_127 ) ;
return - V_184 ;
}
V_183 = V_81 ;
if ( V_83 -> V_162 > V_81 -> V_162 )
continue;
} else if ( V_83 -> V_162 >= V_81 -> V_162 ) {
V_155 = & V_81 -> V_86 ;
continue;
}
if ( V_183 )
break;
}
if ( V_155 )
F_63 ( & V_83 -> V_86 , V_155 ) ;
else
F_62 ( & V_83 -> V_86 , V_154 ) ;
F_102 ( V_83 , V_60 ) ;
F_50 ( & V_35 -> V_97 . V_185 ) ;
if ( V_83 -> V_28 == V_29 )
F_103 ( V_35 ) ;
else
F_104 ( V_35 ) ;
if ( V_183 ) {
F_91 ( V_183 , V_83 ) ;
F_105 ( V_183 , V_60 ) ;
}
V_83 -> V_65 = V_183 ? V_183 -> V_65 : F_89 ( V_35 , V_60 , V_83 -> V_65 ) ;
F_62 ( & V_83 -> V_87 , V_35 -> V_97 . V_130 + F_52 ( V_35 , V_83 -> V_65 ) ) ;
V_83 -> V_69 . V_70 = F_21 () ;
V_83 -> V_69 . V_73 = 0 ;
if ( ! F_25 ( & V_83 -> V_77 , V_78 + V_52 ) )
F_26 ( V_83 ) ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
if ( V_183 )
F_49 ( V_183 ) ;
else if ( F_73 ( V_35 , V_60 , NULL ) )
F_88 ( & V_35 -> V_97 . V_151 ) ;
return 0 ;
}
struct V_54 * F_106 ( struct V_35 * V_35 , T_3 V_179 , T_4 type ,
int V_60 , struct V_1 * V_2 ,
struct V_186 * V_187 , int V_188 ,
int * V_189 )
{
struct V_54 * V_81 , * V_190 ;
struct V_106 * V_154 ;
* V_189 = 0 ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
V_154 = F_55 ( V_35 , V_2 , V_2 -> V_28 , V_60 ) ;
V_190 = NULL ;
F_86 (pol, chain, bydst) {
if ( V_81 -> type == type &&
( V_179 & V_81 -> V_179 . V_181 ) == V_81 -> V_179 . V_180 &&
! F_90 ( V_2 , & V_81 -> V_120 ) &&
F_100 ( V_187 , V_81 -> V_95 ) ) {
F_26 ( V_81 ) ;
if ( V_188 ) {
* V_189 = F_107 (
V_81 -> V_95 ) ;
if ( * V_189 ) {
F_70 ( & V_35 -> V_97 . V_127 ) ;
return V_81 ;
}
F_105 ( V_81 , V_60 ) ;
}
V_190 = V_81 ;
break;
}
}
F_70 ( & V_35 -> V_97 . V_127 ) ;
if ( V_190 && V_188 )
F_49 ( V_190 ) ;
return V_190 ;
}
struct V_54 * F_108 ( struct V_35 * V_35 , T_3 V_179 , T_4 type ,
int V_60 , T_3 V_45 , int V_188 , int * V_189 )
{
struct V_54 * V_81 , * V_190 ;
struct V_106 * V_154 ;
* V_189 = - V_191 ;
if ( F_23 ( V_45 ) != V_60 )
return NULL ;
* V_189 = 0 ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
V_154 = V_35 -> V_97 . V_130 + F_52 ( V_35 , V_45 ) ;
V_190 = NULL ;
F_86 (pol, chain, byidx) {
if ( V_81 -> type == type && V_81 -> V_65 == V_45 &&
( V_179 & V_81 -> V_179 . V_181 ) == V_81 -> V_179 . V_180 ) {
F_26 ( V_81 ) ;
if ( V_188 ) {
* V_189 = F_107 (
V_81 -> V_95 ) ;
if ( * V_189 ) {
F_70 ( & V_35 -> V_97 . V_127 ) ;
return V_81 ;
}
F_105 ( V_81 , V_60 ) ;
}
V_190 = V_81 ;
break;
}
}
F_70 ( & V_35 -> V_97 . V_127 ) ;
if ( V_190 && V_188 )
F_49 ( V_190 ) ;
return V_190 ;
}
static inline int
F_109 ( struct V_35 * V_35 , T_4 type , bool V_192 )
{
int V_60 , V_189 = 0 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ ) {
struct V_54 * V_81 ;
int V_126 ;
F_86 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
V_189 = F_107 ( V_81 -> V_95 ) ;
if ( V_189 ) {
F_110 ( V_81 , 0 , V_192 ) ;
return V_189 ;
}
}
for ( V_126 = V_35 -> V_97 . V_101 [ V_60 ] . V_107 ; V_126 >= 0 ; V_126 -- ) {
F_86 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
V_189 = F_107 (
V_81 -> V_95 ) ;
if ( V_189 ) {
F_110 ( V_81 , 0 ,
V_192 ) ;
return V_189 ;
}
}
}
}
return V_189 ;
}
static inline int
F_109 ( struct V_35 * V_35 , T_4 type , bool V_192 )
{
return 0 ;
}
int F_111 ( struct V_35 * V_35 , T_4 type , bool V_192 )
{
int V_60 , V_189 = 0 , V_132 = 0 ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
V_189 = F_109 ( V_35 , type , V_192 ) ;
if ( V_189 )
goto V_64;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ ) {
struct V_54 * V_81 ;
int V_126 ;
V_193:
F_86 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
F_105 ( V_81 , V_60 ) ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
V_132 ++ ;
F_110 ( V_81 , 1 , V_192 ) ;
F_49 ( V_81 ) ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
goto V_193;
}
for ( V_126 = V_35 -> V_97 . V_101 [ V_60 ] . V_107 ; V_126 >= 0 ; V_126 -- ) {
V_194:
F_86 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
F_105 ( V_81 , V_60 ) ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
V_132 ++ ;
F_110 ( V_81 , 1 , V_192 ) ;
F_49 ( V_81 ) ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
goto V_194;
}
}
}
if ( ! V_132 )
V_189 = - V_195 ;
V_64:
F_70 ( & V_35 -> V_97 . V_127 ) ;
return V_189 ;
}
int F_112 ( struct V_35 * V_35 , struct F_112 * V_62 ,
int (* F_113)( struct V_54 * , int , int , void * ) ,
void * V_53 )
{
struct V_54 * V_81 ;
struct V_196 * V_41 ;
int error = 0 ;
if ( V_62 -> type >= V_197 &&
V_62 -> type != V_198 )
return - V_199 ;
if ( F_114 ( & V_62 -> V_62 . V_85 ) && V_62 -> V_156 != 0 )
return 0 ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
if ( F_114 ( & V_62 -> V_62 . V_85 ) )
V_41 = F_115 ( & V_35 -> V_97 . V_200 , struct V_196 , V_85 ) ;
else
V_41 = F_115 ( & V_62 -> V_62 . V_85 ,
struct V_196 , V_85 ) ;
F_116 (x, &net->xfrm.policy_all, all) {
if ( V_41 -> V_63 )
continue;
V_81 = F_31 ( V_41 , struct V_54 , V_62 ) ;
if ( V_62 -> type != V_198 &&
V_62 -> type != V_81 -> type )
continue;
error = F_113 ( V_81 , F_23 ( V_81 -> V_65 ) ,
V_62 -> V_156 , V_53 ) ;
if ( error ) {
F_117 ( & V_62 -> V_62 . V_85 , & V_41 -> V_85 ) ;
goto V_64;
}
V_62 -> V_156 ++ ;
}
if ( V_62 -> V_156 == 0 ) {
error = - V_191 ;
goto V_64;
}
F_118 ( & V_62 -> V_62 . V_85 ) ;
V_64:
F_70 ( & V_35 -> V_97 . V_127 ) ;
return error ;
}
void F_119 ( struct F_112 * V_62 , T_4 type )
{
F_37 ( & V_62 -> V_62 . V_85 ) ;
V_62 -> V_62 . V_63 = 1 ;
V_62 -> type = type ;
V_62 -> V_156 = 0 ;
}
void F_120 ( struct F_112 * V_62 , struct V_35 * V_35 )
{
if ( F_114 ( & V_62 -> V_62 . V_85 ) )
return;
F_69 ( & V_35 -> V_97 . V_127 ) ;
F_121 ( & V_62 -> V_62 . V_85 ) ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
}
static int F_122 ( const struct V_54 * V_81 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_28 , int V_60 )
{
const struct V_1 * V_2 = & V_81 -> V_120 ;
int V_190 = - V_195 ;
bool V_201 ;
if ( V_81 -> V_28 != V_28 ||
( V_4 -> V_202 & V_81 -> V_179 . V_181 ) != V_81 -> V_179 . V_180 ||
V_81 -> type != type )
return V_190 ;
V_201 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_201 )
V_190 = F_123 ( V_81 -> V_95 , V_4 -> V_203 ,
V_60 ) ;
return V_190 ;
}
static struct V_54 * F_124 ( struct V_35 * V_35 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_28 , T_4 V_60 )
{
int V_189 ;
struct V_54 * V_81 , * V_190 ;
const T_1 * V_9 , * V_12 ;
struct V_106 * V_154 ;
T_3 V_162 = ~ 0U ;
V_9 = F_125 ( V_4 , V_28 ) ;
V_12 = F_126 ( V_4 , V_28 ) ;
if ( F_9 ( ! V_9 || ! V_12 ) )
return NULL ;
F_76 ( & V_35 -> V_97 . V_127 ) ;
V_154 = F_57 ( V_35 , V_9 , V_12 , V_28 , V_60 ) ;
V_190 = NULL ;
F_86 (pol, chain, bydst) {
V_189 = F_122 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_189 ) {
if ( V_189 == - V_195 )
continue;
else {
V_190 = F_15 ( V_189 ) ;
goto V_204;
}
} else {
V_190 = V_81 ;
V_162 = V_190 -> V_162 ;
break;
}
}
V_154 = & V_35 -> V_97 . V_109 [ V_60 ] ;
F_86 (pol, chain, bydst) {
if ( ( V_81 -> V_162 >= V_162 ) && V_190 )
break;
V_189 = F_122 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_189 ) {
if ( V_189 == - V_195 )
continue;
else {
V_190 = F_15 ( V_189 ) ;
goto V_204;
}
} else {
V_190 = V_81 ;
break;
}
}
F_26 ( V_190 ) ;
V_204:
F_77 ( & V_35 -> V_97 . V_127 ) ;
return V_190 ;
}
static struct V_54 *
F_127 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 )
{
#ifdef F_128
struct V_54 * V_81 ;
V_81 = F_124 ( V_35 , V_205 , V_4 , V_28 , V_60 ) ;
if ( V_81 != NULL )
return V_81 ;
#endif
return F_124 ( V_35 , V_206 , V_4 , V_28 , V_60 ) ;
}
static int F_129 ( int V_60 )
{
if ( V_138 == V_207 &&
V_140 == V_208 &&
V_142 == V_209 )
return V_60 ;
switch ( V_60 ) {
default:
case V_207 :
return V_138 ;
case V_208 :
return V_140 ;
case V_209 :
return V_142 ;
}
}
static struct V_79 *
F_130 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_60 , struct V_79 * V_210 , void * V_187 )
{
struct V_54 * V_81 ;
if ( V_210 )
F_28 ( F_31 ( V_210 , struct V_54 , V_80 ) ) ;
V_81 = F_127 ( V_35 , V_4 , V_28 , F_129 ( V_60 ) ) ;
if ( F_131 ( V_81 ) )
return F_132 ( V_81 ) ;
F_26 ( V_81 ) ;
return & V_81 -> V_80 ;
}
static inline int F_133 ( int V_60 )
{
if ( V_138 == V_207 &&
V_140 == V_208 &&
V_142 == V_209 )
return V_60 ;
switch ( V_60 ) {
default:
case V_138 :
return V_207 ;
case V_140 :
return V_208 ;
case V_142 :
return V_209 ;
}
}
static struct V_54 * F_134 ( struct V_211 * V_212 , int V_60 ,
const struct V_3 * V_4 )
{
struct V_54 * V_81 ;
struct V_35 * V_35 = F_135 ( V_212 ) ;
F_76 ( & V_35 -> V_97 . V_127 ) ;
if ( ( V_81 = V_212 -> V_213 [ V_60 ] ) != NULL ) {
bool V_201 = F_7 ( & V_81 -> V_120 , V_4 ,
V_212 -> V_214 ) ;
int V_189 = 0 ;
if ( V_201 ) {
if ( ( V_212 -> V_215 & V_81 -> V_179 . V_181 ) != V_81 -> V_179 . V_180 ) {
V_81 = NULL ;
goto V_64;
}
V_189 = F_123 ( V_81 -> V_95 ,
V_4 -> V_203 ,
F_133 ( V_60 ) ) ;
if ( ! V_189 )
F_26 ( V_81 ) ;
else if ( V_189 == - V_195 )
V_81 = NULL ;
else
V_81 = F_15 ( V_189 ) ;
} else
V_81 = NULL ;
}
V_64:
F_77 ( & V_35 -> V_97 . V_127 ) ;
return V_81 ;
}
static void F_102 ( struct V_54 * V_81 , int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
F_136 ( & V_81 -> V_62 . V_85 , & V_35 -> V_97 . V_200 ) ;
V_35 -> V_97 . V_133 [ V_60 ] ++ ;
F_26 ( V_81 ) ;
}
static struct V_54 * F_105 ( struct V_54 * V_81 ,
int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
if ( F_114 ( & V_81 -> V_62 . V_85 ) )
return NULL ;
if ( ! F_137 ( & V_81 -> V_86 ) ) {
F_61 ( & V_81 -> V_86 ) ;
F_61 ( & V_81 -> V_87 ) ;
}
F_118 ( & V_81 -> V_62 . V_85 ) ;
V_35 -> V_97 . V_133 [ V_60 ] -- ;
return V_81 ;
}
static void F_138 ( struct V_54 * V_81 , int V_60 )
{
F_102 ( V_81 , V_144 + V_60 ) ;
}
static void F_139 ( struct V_54 * V_81 , int V_60 )
{
F_105 ( V_81 , V_144 + V_60 ) ;
}
int F_29 ( struct V_54 * V_81 , int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
V_81 = F_105 ( V_81 , V_60 ) ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
if ( V_81 ) {
F_49 ( V_81 ) ;
return 0 ;
}
return - V_191 ;
}
int F_140 ( struct V_211 * V_212 , int V_60 , struct V_54 * V_81 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
struct V_54 * V_216 ;
#ifdef F_128
if ( V_81 && V_81 -> type != V_206 )
return - V_199 ;
#endif
F_69 ( & V_35 -> V_97 . V_127 ) ;
V_216 = V_212 -> V_213 [ V_60 ] ;
V_212 -> V_213 [ V_60 ] = V_81 ;
if ( V_81 ) {
V_81 -> V_69 . V_70 = F_21 () ;
V_81 -> V_65 = F_89 ( V_35 , V_144 + V_60 , 0 ) ;
F_138 ( V_81 , V_60 ) ;
}
if ( V_216 ) {
if ( V_81 )
F_91 ( V_216 , V_81 ) ;
F_139 ( V_216 , V_60 ) ;
}
F_70 ( & V_35 -> V_97 . V_127 ) ;
if ( V_216 ) {
F_49 ( V_216 ) ;
}
return 0 ;
}
static struct V_54 * F_141 ( const struct V_54 * V_172 , int V_60 )
{
struct V_54 * V_217 = F_34 ( V_84 ( V_172 ) , V_218 ) ;
struct V_35 * V_35 = V_84 ( V_172 ) ;
if ( V_217 ) {
V_217 -> V_120 = V_172 -> V_120 ;
if ( F_142 ( V_172 -> V_95 ,
& V_217 -> V_95 ) ) {
F_48 ( V_217 ) ;
return NULL ;
}
V_217 -> V_66 = V_172 -> V_66 ;
V_217 -> V_69 = V_172 -> V_69 ;
V_217 -> V_179 = V_172 -> V_179 ;
V_217 -> V_219 = V_172 -> V_219 ;
V_217 -> V_46 = V_172 -> V_46 ;
V_217 -> V_220 = V_172 -> V_220 ;
V_217 -> V_65 = V_172 -> V_65 ;
V_217 -> type = V_172 -> type ;
memcpy ( V_217 -> V_221 , V_172 -> V_221 ,
V_217 -> V_220 * sizeof( struct V_222 ) ) ;
F_69 ( & V_35 -> V_97 . V_127 ) ;
F_138 ( V_217 , V_60 ) ;
F_70 ( & V_35 -> V_97 . V_127 ) ;
F_28 ( V_217 ) ;
}
return V_217 ;
}
int F_143 ( struct V_211 * V_212 )
{
struct V_54 * V_223 = V_212 -> V_213 [ 0 ] ,
* V_169 = V_212 -> V_213 [ 1 ] ;
V_212 -> V_213 [ 0 ] = V_212 -> V_213 [ 1 ] = NULL ;
if ( V_223 && ( V_212 -> V_213 [ 0 ] = F_141 ( V_223 , 0 ) ) == NULL )
return - V_224 ;
if ( V_169 && ( V_212 -> V_213 [ 1 ] = F_141 ( V_169 , 1 ) ) == NULL )
return - V_224 ;
return 0 ;
}
static int
F_144 ( struct V_35 * V_35 , T_1 * V_225 , T_1 * V_226 ,
unsigned short V_28 )
{
int V_189 ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return - V_199 ;
V_189 = V_32 -> V_227 ( V_35 , V_225 , V_226 ) ;
F_13 ( V_32 ) ;
return V_189 ;
}
static int
F_145 ( struct V_54 * V_83 , const struct V_3 * V_4 ,
struct V_40 * * V_97 , unsigned short V_28 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
int V_228 ;
int V_126 , error ;
T_1 * V_9 = F_125 ( V_4 , V_28 ) ;
T_1 * V_12 = F_126 ( V_4 , V_28 ) ;
T_1 V_115 ;
for ( V_228 = 0 , V_126 = 0 ; V_126 < V_83 -> V_220 ; V_126 ++ ) {
struct V_40 * V_41 ;
T_1 * V_226 = V_9 ;
T_1 * V_225 = V_12 ;
struct V_222 * V_229 = & V_83 -> V_221 [ V_126 ] ;
if ( V_229 -> V_230 == V_231 ||
V_229 -> V_230 == V_232 ) {
V_226 = & V_229 -> V_45 . V_9 ;
V_225 = & V_229 -> V_12 ;
if ( F_146 ( V_225 , V_229 -> V_233 ) ) {
error = F_144 ( V_35 , & V_115 , V_226 , V_229 -> V_233 ) ;
if ( error )
goto V_204;
V_225 = & V_115 ;
}
}
V_41 = F_147 ( V_226 , V_225 , V_4 , V_229 , V_83 , & error , V_28 ) ;
if ( V_41 && V_41 -> V_234 . V_235 == V_236 ) {
V_97 [ V_228 ++ ] = V_41 ;
V_9 = V_226 ;
V_12 = V_225 ;
continue;
}
if ( V_41 ) {
error = ( V_41 -> V_234 . V_235 == V_237 ?
- V_199 : - V_238 ) ;
F_148 ( V_41 ) ;
} else if ( error == - V_195 ) {
error = - V_238 ;
}
if ( ! V_229 -> V_239 )
goto V_204;
}
return V_228 ;
V_204:
for ( V_228 -- ; V_228 >= 0 ; V_228 -- )
F_148 ( V_97 [ V_228 ] ) ;
return error ;
}
static int
F_149 ( struct V_54 * * V_240 , int V_241 , const struct V_3 * V_4 ,
struct V_40 * * V_97 , unsigned short V_28 )
{
struct V_40 * V_242 [ V_243 ] ;
struct V_40 * * V_244 = ( V_241 > 1 ) ? V_242 : V_97 ;
int V_245 = 0 ;
int error ;
int V_190 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < V_241 ; V_126 ++ ) {
if ( V_245 + V_240 [ V_126 ] -> V_220 >= V_243 ) {
error = - V_246 ;
goto V_204;
}
V_190 = F_145 ( V_240 [ V_126 ] , V_4 , & V_244 [ V_245 ] , V_28 ) ;
if ( V_190 < 0 ) {
error = V_190 ;
goto V_204;
} else
V_245 += V_190 ;
}
if ( V_241 > 1 )
F_150 ( V_97 , V_244 , V_245 , V_28 ) ;
return V_245 ;
V_204:
for ( V_245 -- ; V_245 >= 0 ; V_245 -- )
F_148 ( V_244 [ V_245 ] ) ;
return error ;
}
static inline int F_151 ( const struct V_3 * V_4 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_36 ;
if ( ! V_32 )
return - V_199 ;
V_36 = V_32 -> V_247 ( V_4 ) ;
F_13 ( V_32 ) ;
return V_36 ;
}
static struct V_79 * F_152 ( struct V_79 * V_80 )
{
struct V_248 * V_249 = F_31 ( V_80 , struct V_248 , V_80 ) ;
struct V_34 * V_37 = & V_249 -> V_7 . V_37 ;
if ( V_249 -> V_250 == NULL ) {
if ( V_249 -> V_251 > 0 )
return NULL ;
} else if ( V_37 -> V_46 & V_252 ) {
return NULL ;
} else {
if ( F_153 ( V_37 ) )
return NULL ;
}
F_154 ( V_37 ) ;
return V_80 ;
}
static int F_155 ( struct V_79 * V_80 )
{
struct V_248 * V_249 = F_31 ( V_80 , struct V_248 , V_80 ) ;
struct V_34 * V_37 = & V_249 -> V_7 . V_37 ;
if ( ! V_249 -> V_250 )
return 0 ;
if ( F_153 ( V_37 ) )
return 0 ;
return 1 ;
}
static void F_156 ( struct V_79 * V_80 )
{
struct V_248 * V_249 = F_31 ( V_80 , struct V_248 , V_80 ) ;
struct V_34 * V_37 = & V_249 -> V_7 . V_37 ;
F_157 ( V_37 ) ;
}
static inline struct V_248 * F_158 ( struct V_35 * V_35 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_253 * V_253 ;
struct V_248 * V_249 ;
if ( ! V_32 )
return F_15 ( - V_199 ) ;
switch ( V_28 ) {
case V_29 :
V_253 = & V_35 -> V_97 . V_254 ;
break;
#if F_159 ( V_255 )
case V_30 :
V_253 = & V_35 -> V_97 . V_256 ;
break;
#endif
default:
F_46 () ;
}
V_249 = F_160 ( V_253 , NULL , 0 , V_257 , 0 ) ;
if ( F_161 ( V_249 ) ) {
struct V_34 * V_37 = & V_249 -> V_7 . V_37 ;
memset ( V_37 + 1 , 0 , sizeof( * V_249 ) - sizeof( * V_37 ) ) ;
V_249 -> V_80 . V_93 = & V_258 ;
if ( V_32 -> V_259 )
V_32 -> V_259 ( V_35 , V_249 ) ;
} else
V_249 = F_15 ( - V_246 ) ;
F_13 ( V_32 ) ;
return V_249 ;
}
static inline int F_162 ( struct V_248 * V_260 , struct V_34 * V_37 ,
int V_261 )
{
struct V_31 * V_32 =
F_8 ( V_37 -> V_93 -> V_28 ) ;
int V_189 ;
if ( ! V_32 )
return - V_199 ;
V_189 = V_32 -> V_262 ( V_260 , V_37 , V_261 ) ;
F_13 ( V_32 ) ;
return V_189 ;
}
static inline int F_163 ( struct V_248 * V_249 , struct V_263 * V_264 ,
const struct V_3 * V_4 )
{
struct V_31 * V_32 =
F_8 ( V_249 -> V_7 . V_37 . V_93 -> V_28 ) ;
int V_189 ;
if ( ! V_32 )
return - V_199 ;
V_189 = V_32 -> V_265 ( V_249 , V_264 , V_4 ) ;
F_13 ( V_32 ) ;
return V_189 ;
}
static struct V_34 * F_164 ( struct V_54 * V_83 ,
struct V_40 * * V_97 , int V_228 ,
const struct V_3 * V_4 ,
struct V_34 * V_37 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
unsigned long V_56 = V_78 ;
struct V_263 * V_264 ;
struct V_266 * V_267 ;
struct V_34 * V_268 = NULL ;
struct V_34 * V_269 = NULL ;
int V_126 = 0 ;
int V_189 ;
int V_270 = 0 ;
int V_261 = 0 ;
int V_271 = 0 ;
int V_36 ;
int V_28 = V_83 -> V_120 . V_28 ;
T_1 V_12 , V_9 ;
F_165 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_36 = F_151 ( V_4 , V_28 ) ;
V_189 = V_36 ;
if ( V_36 < 0 )
goto V_272;
F_154 ( V_37 ) ;
for (; V_126 < V_228 ; V_126 ++ ) {
struct V_248 * V_249 = F_158 ( V_35 , V_28 ) ;
struct V_34 * V_273 = & V_249 -> V_7 . V_37 ;
V_189 = F_166 ( V_249 ) ;
if ( F_18 ( V_249 ) ) {
F_167 ( V_37 ) ;
goto V_272;
}
if ( V_97 [ V_126 ] -> V_2 . V_28 == V_274 ) {
V_267 = F_168 ( V_97 [ V_126 ] ,
F_169 ( V_28 ) ) ;
if ( ! V_267 ) {
V_189 = - V_38 ;
F_167 ( V_37 ) ;
goto V_272;
}
} else
V_267 = V_97 [ V_126 ] -> V_267 ;
if ( ! V_268 )
V_269 = V_273 ;
else {
V_268 -> V_275 = F_170 ( V_273 ) ;
V_273 -> V_46 |= V_276 ;
}
V_249 -> V_250 = V_37 ;
F_171 ( V_273 , V_37 ) ;
if ( V_97 [ V_126 ] -> V_44 . V_230 != V_277 ) {
V_28 = V_97 [ V_126 ] -> V_44 . V_28 ;
V_37 = F_16 ( V_97 [ V_126 ] , V_36 , & V_12 , & V_9 ,
V_28 ) ;
V_189 = F_166 ( V_37 ) ;
if ( F_18 ( V_37 ) )
goto V_272;
} else
F_154 ( V_37 ) ;
V_273 -> V_97 = V_97 [ V_126 ] ;
V_249 -> V_278 = V_97 [ V_126 ] -> V_96 ;
V_273 -> V_279 = V_280 ;
V_273 -> V_46 |= V_281 ;
V_273 -> V_282 = V_56 ;
V_273 -> V_283 = V_284 ;
V_273 -> V_285 = V_267 -> V_32 -> V_285 ;
V_273 -> V_57 = V_268 ;
V_268 = V_273 ;
V_270 += V_97 [ V_126 ] -> V_44 . V_270 ;
if ( V_97 [ V_126 ] -> type -> V_46 & V_286 )
V_261 += V_97 [ V_126 ] -> V_44 . V_270 ;
V_271 += V_97 [ V_126 ] -> V_44 . V_271 ;
}
V_268 -> V_275 = V_37 ;
V_269 -> V_260 = V_37 ;
V_189 = - V_287 ;
V_264 = V_37 -> V_264 ;
if ( ! V_264 )
goto V_288;
F_162 ( (struct V_248 * ) V_269 , V_37 , V_261 ) ;
F_172 ( V_268 ) ;
for ( V_268 = V_269 ; V_268 != V_37 ; V_268 = V_268 -> V_275 ) {
struct V_248 * V_249 = (struct V_248 * ) V_268 ;
V_189 = F_163 ( V_249 , V_264 , V_4 ) ;
if ( V_189 )
goto V_288;
V_268 -> V_270 = V_270 ;
V_268 -> V_271 = V_271 ;
V_270 -= V_249 -> V_7 . V_37 . V_97 -> V_44 . V_270 ;
V_271 -= V_249 -> V_7 . V_37 . V_97 -> V_44 . V_271 ;
}
V_64:
return V_269 ;
V_272:
for (; V_126 < V_228 ; V_126 ++ )
F_148 ( V_97 [ V_126 ] ) ;
V_288:
if ( V_269 )
F_157 ( V_269 ) ;
V_269 = F_15 ( V_189 ) ;
goto V_64;
}
static int F_173 ( void * * V_289 , const void * V_290 , int V_291 )
{
if ( ! * V_289 ) {
* V_289 = F_174 ( V_291 , V_218 ) ;
if ( ! * V_289 )
return - V_224 ;
}
memcpy ( * V_289 , V_290 , V_291 ) ;
return 0 ;
}
static int F_175 ( struct V_34 * V_37 ,
const struct V_1 * V_2 )
{
#ifdef F_128
struct V_248 * V_249 = (struct V_248 * ) V_37 ;
return F_173 ( ( void * * ) & ( V_249 -> V_292 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int F_176 ( struct V_34 * V_37 ,
const struct V_3 * V_4 )
{
#ifdef F_128
struct V_248 * V_249 = (struct V_248 * ) V_37 ;
return F_173 ( ( void * * ) & ( V_249 -> V_293 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_177 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_54 * * V_240 ,
int * V_294 , int * V_251 )
{
int V_126 ;
if ( * V_294 == 0 || ! V_240 [ 0 ] ) {
* V_294 = 0 ;
* V_251 = 0 ;
return 0 ;
}
if ( F_18 ( V_240 [ 0 ] ) )
return F_166 ( V_240 [ 0 ] ) ;
* V_251 = V_240 [ 0 ] -> V_220 ;
#ifdef F_128
if ( V_240 [ 0 ] && V_240 [ 0 ] -> V_219 == V_295 &&
V_240 [ 0 ] -> type != V_206 ) {
V_240 [ 1 ] = F_124 ( V_84 ( V_240 [ 0 ] ) ,
V_206 ,
V_4 , V_28 ,
V_140 ) ;
if ( V_240 [ 1 ] ) {
if ( F_18 ( V_240 [ 1 ] ) ) {
F_178 ( V_240 , * V_294 ) ;
return F_166 ( V_240 [ 1 ] ) ;
}
( * V_294 ) ++ ;
( * V_251 ) += V_240 [ 1 ] -> V_220 ;
}
}
#endif
for ( V_126 = 0 ; V_126 < * V_294 ; V_126 ++ ) {
if ( V_240 [ V_126 ] -> V_219 != V_295 ) {
* V_251 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_248 *
F_179 ( struct V_54 * * V_240 , int V_294 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_34 * V_296 )
{
struct V_35 * V_35 = V_84 ( V_240 [ 0 ] ) ;
struct V_40 * V_97 [ V_243 ] ;
struct V_34 * V_37 ;
struct V_248 * V_249 ;
int V_189 ;
V_189 = F_149 ( V_240 , V_294 , V_4 , V_97 , V_28 ) ;
if ( V_189 <= 0 ) {
if ( V_189 != 0 && V_189 != - V_238 )
F_180 ( V_35 , V_297 ) ;
return F_15 ( V_189 ) ;
}
V_37 = F_164 ( V_240 [ 0 ] , V_97 , V_189 , V_4 , V_296 ) ;
if ( F_18 ( V_37 ) ) {
F_180 ( V_35 , V_298 ) ;
return F_132 ( V_37 ) ;
}
V_249 = (struct V_248 * ) V_37 ;
V_249 -> V_251 = V_189 ;
if ( V_294 > 1 )
V_189 = F_175 ( V_37 , & V_240 [ 1 ] -> V_120 ) ;
else
V_189 = F_176 ( V_37 , V_4 ) ;
if ( F_9 ( V_189 ) ) {
F_157 ( V_37 ) ;
F_180 ( V_35 , V_299 ) ;
return F_15 ( V_189 ) ;
}
V_249 -> V_294 = V_294 ;
memcpy ( V_249 -> V_240 , V_240 , sizeof( struct V_54 * ) * V_294 ) ;
V_249 -> V_300 = F_181 ( & V_240 [ 0 ] -> V_96 ) ;
return V_249 ;
}
static void V_92 ( unsigned long V_301 )
{
struct V_302 * V_303 ;
struct V_211 * V_212 ;
struct V_34 * V_37 ;
struct V_54 * V_81 = (struct V_54 * ) V_301 ;
struct V_174 * V_175 = & V_81 -> V_89 ;
struct V_3 V_4 ;
struct V_176 V_111 ;
F_182 ( & V_175 -> V_90 . V_61 ) ;
V_303 = F_183 ( & V_175 -> V_90 ) ;
if ( ! V_303 ) {
F_184 ( & V_175 -> V_90 . V_61 ) ;
goto V_64;
}
V_37 = F_185 ( V_303 ) ;
V_212 = V_303 -> V_212 ;
F_186 ( V_303 , & V_4 , V_37 -> V_93 -> V_28 ) ;
F_184 ( & V_175 -> V_90 . V_61 ) ;
F_154 ( V_37 -> V_260 ) ;
V_37 = F_187 ( V_84 ( V_81 ) , V_37 -> V_260 , & V_4 ,
V_212 , 0 ) ;
if ( F_18 ( V_37 ) )
goto V_304;
if ( V_37 -> V_46 & V_252 ) {
F_167 ( V_37 ) ;
if ( V_175 -> V_177 >= V_305 )
goto V_304;
V_175 -> V_177 = V_175 -> V_177 << 1 ;
if ( ! F_25 ( & V_175 -> V_91 , V_78 + V_175 -> V_177 ) )
F_26 ( V_81 ) ;
goto V_64;
}
F_167 ( V_37 ) ;
F_93 ( & V_111 ) ;
F_182 ( & V_175 -> V_90 . V_61 ) ;
V_175 -> V_177 = 0 ;
F_95 ( & V_175 -> V_90 , & V_111 ) ;
F_184 ( & V_175 -> V_90 . V_61 ) ;
while ( ! F_92 ( & V_111 ) ) {
V_303 = F_188 ( & V_111 ) ;
F_186 ( V_303 , & V_4 , F_185 ( V_303 ) -> V_93 -> V_28 ) ;
F_154 ( F_185 ( V_303 ) -> V_260 ) ;
V_37 = F_187 ( V_84 ( V_81 ) , F_185 ( V_303 ) -> V_260 ,
& V_4 , V_303 -> V_212 , 0 ) ;
if ( F_18 ( V_37 ) ) {
F_189 ( V_303 ) ;
continue;
}
F_190 ( V_303 ) ;
F_191 ( V_303 ) ;
F_192 ( V_303 , V_37 ) ;
F_193 ( V_303 ) ;
}
V_64:
F_28 ( V_81 ) ;
return;
V_304:
V_175 -> V_177 = 0 ;
F_51 ( & V_175 -> V_90 ) ;
F_28 ( V_81 ) ;
}
static int F_194 ( struct V_211 * V_212 , struct V_302 * V_303 )
{
unsigned long V_306 ;
struct V_34 * V_37 = F_185 ( V_303 ) ;
struct V_248 * V_249 = (struct V_248 * ) V_37 ;
struct V_54 * V_81 = V_249 -> V_240 [ 0 ] ;
struct V_174 * V_175 = & V_81 -> V_89 ;
if ( F_9 ( F_195 ( V_212 , V_303 ) ) ) {
F_189 ( V_303 ) ;
return 0 ;
}
if ( V_175 -> V_90 . V_307 > V_308 ) {
F_189 ( V_303 ) ;
return - V_238 ;
}
F_196 ( V_303 ) ;
F_94 ( & V_175 -> V_90 . V_61 ) ;
if ( ! V_175 -> V_177 )
V_175 -> V_177 = V_178 ;
V_306 = V_78 + V_175 -> V_177 ;
if ( F_45 ( & V_175 -> V_91 ) ) {
if ( F_197 ( V_175 -> V_91 . V_309 , V_306 ) )
V_306 = V_175 -> V_91 . V_309 ;
F_28 ( V_81 ) ;
}
F_198 ( & V_175 -> V_90 , V_303 ) ;
if ( ! F_25 ( & V_175 -> V_91 , V_306 ) )
F_26 ( V_81 ) ;
F_96 ( & V_175 -> V_90 . V_61 ) ;
return 0 ;
}
static struct V_248 * F_199 ( struct V_35 * V_35 ,
struct V_310 * V_311 ,
const struct V_3 * V_4 ,
int V_251 ,
T_5 V_28 )
{
int V_189 ;
struct V_263 * V_264 ;
struct V_34 * V_37 ;
struct V_34 * V_273 ;
struct V_248 * V_249 ;
V_249 = F_158 ( V_35 , V_28 ) ;
if ( F_18 ( V_249 ) )
return V_249 ;
if ( ! ( V_311 -> V_46 & V_312 ) ||
V_35 -> V_97 . V_313 ||
V_251 <= 0 )
return V_249 ;
V_37 = V_311 -> V_296 ;
V_273 = & V_249 -> V_7 . V_37 ;
F_154 ( V_37 ) ;
V_249 -> V_250 = V_37 ;
F_171 ( V_273 , V_37 ) ;
V_273 -> V_279 = V_280 ;
V_273 -> V_46 |= V_281 | V_252 ;
V_273 -> V_282 = V_78 ;
V_273 -> V_283 = V_284 ;
V_273 -> V_285 = F_194 ;
F_154 ( V_37 ) ;
V_273 -> V_275 = V_37 ;
V_273 -> V_260 = V_37 ;
F_162 ( (struct V_248 * ) V_273 , V_37 , 0 ) ;
V_189 = - V_287 ;
V_264 = V_37 -> V_264 ;
if ( ! V_264 )
goto V_288;
V_189 = F_163 ( V_249 , V_264 , V_4 ) ;
if ( V_189 )
goto V_288;
V_64:
return V_249 ;
V_288:
F_167 ( V_273 ) ;
V_249 = F_15 ( V_189 ) ;
goto V_64;
}
static struct V_79 *
F_200 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 ,
struct V_79 * V_314 , void * V_187 )
{
struct V_310 * V_311 = (struct V_310 * ) V_187 ;
struct V_54 * V_240 [ V_197 ] ;
struct V_248 * V_249 , * V_315 ;
int V_294 = 0 , V_251 = 0 , V_126 , V_189 , V_316 ;
V_249 = NULL ;
if ( V_314 ) {
V_249 = F_31 ( V_314 , struct V_248 , V_80 ) ;
V_294 = V_249 -> V_294 ;
V_251 = V_249 -> V_251 ;
V_316 = 0 ;
for ( V_126 = 0 ; V_126 < V_294 ; V_126 ++ ) {
V_240 [ V_126 ] = V_249 -> V_240 [ V_126 ] ;
V_316 |= V_240 [ V_126 ] -> V_62 . V_63 ;
}
if ( V_316 ) {
F_157 ( & V_249 -> V_7 . V_37 ) ;
V_249 = NULL ;
V_294 = 0 ;
V_251 = 0 ;
V_314 = NULL ;
}
}
if ( V_249 == NULL ) {
V_294 = 1 ;
V_240 [ 0 ] = F_127 ( V_35 , V_4 , V_28 ,
F_129 ( V_60 ) ) ;
V_189 = F_177 ( V_4 , V_28 , V_240 ,
& V_294 , & V_251 ) ;
if ( V_189 < 0 )
goto V_317;
if ( V_294 == 0 )
return NULL ;
if ( V_251 <= 0 )
goto V_318;
}
V_315 = F_179 ( V_240 , V_294 , V_4 , V_28 ,
V_311 -> V_296 ) ;
if ( F_18 ( V_315 ) ) {
V_189 = F_166 ( V_315 ) ;
if ( V_189 != - V_238 )
goto error;
if ( V_314 == NULL )
goto V_318;
F_154 ( & V_249 -> V_7 . V_37 ) ;
return V_314 ;
} else if ( V_315 == NULL ) {
V_251 = 0 ;
if ( V_314 == NULL )
goto V_318;
V_249 -> V_251 = 0 ;
F_154 ( & V_249 -> V_7 . V_37 ) ;
return V_314 ;
}
if ( V_249 ) {
V_249 -> V_294 = 0 ;
F_157 ( & V_249 -> V_7 . V_37 ) ;
}
F_154 ( & V_315 -> V_7 . V_37 ) ;
return & V_315 -> V_80 ;
V_318:
V_249 = F_199 ( V_35 , V_311 , V_4 , V_251 , V_28 ) ;
if ( F_18 ( V_249 ) ) {
F_178 ( V_240 , V_294 ) ;
return F_132 ( V_249 ) ;
}
V_249 -> V_294 = V_294 ;
V_249 -> V_251 = V_251 ;
memcpy ( V_249 -> V_240 , V_240 , sizeof( struct V_54 * ) * V_294 ) ;
F_154 ( & V_249 -> V_7 . V_37 ) ;
return & V_249 -> V_80 ;
V_317:
F_180 ( V_35 , V_297 ) ;
error:
if ( V_249 != NULL )
F_157 ( & V_249 -> V_7 . V_37 ) ;
else
F_178 ( V_240 , V_294 ) ;
return F_15 ( V_189 ) ;
}
static struct V_34 * F_201 ( struct V_35 * V_35 , T_5 V_28 ,
struct V_34 * V_296 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_34 * V_190 ;
if ( ! V_32 ) {
F_167 ( V_296 ) ;
return F_15 ( - V_199 ) ;
} else {
V_190 = V_32 -> V_319 ( V_35 , V_296 ) ;
}
F_13 ( V_32 ) ;
return V_190 ;
}
struct V_34 * F_187 ( struct V_35 * V_35 , struct V_34 * V_296 ,
const struct V_3 * V_4 ,
struct V_211 * V_212 , int V_46 )
{
struct V_54 * V_240 [ V_197 ] ;
struct V_79 * V_80 ;
struct V_248 * V_249 ;
struct V_34 * V_37 , * V_250 ;
T_5 V_28 = V_296 -> V_93 -> V_28 ;
T_4 V_60 = F_133 ( V_140 ) ;
int V_126 , V_189 , V_294 , V_251 = 0 , V_320 = 0 ;
V_37 = NULL ;
V_249 = NULL ;
V_250 = NULL ;
if ( V_212 && V_212 -> V_213 [ V_140 ] ) {
V_294 = 1 ;
V_240 [ 0 ] = F_134 ( V_212 , V_140 , V_4 ) ;
V_189 = F_177 ( V_4 , V_28 , V_240 ,
& V_294 , & V_251 ) ;
if ( V_189 < 0 )
goto V_321;
if ( V_294 ) {
if ( V_251 <= 0 ) {
V_320 = V_294 ;
goto V_322;
}
V_249 = F_179 (
V_240 , V_294 , V_4 ,
V_28 , V_296 ) ;
if ( F_18 ( V_249 ) ) {
F_178 ( V_240 , V_294 ) ;
V_189 = F_166 ( V_249 ) ;
goto V_321;
} else if ( V_249 == NULL ) {
V_251 = 0 ;
V_320 = V_294 ;
goto V_322;
}
F_154 ( & V_249 -> V_7 . V_37 ) ;
V_249 -> V_7 . V_37 . V_46 |= V_323 ;
V_250 = V_249 -> V_250 ;
}
}
if ( V_249 == NULL ) {
struct V_310 V_311 ;
V_311 . V_296 = V_296 ;
V_311 . V_46 = V_46 ;
if ( ( V_296 -> V_46 & V_324 ) ||
! V_35 -> V_97 . V_133 [ V_140 ] )
goto V_325;
V_80 = F_202 ( V_35 , V_4 , V_28 , V_60 ,
F_200 , & V_311 ) ;
if ( V_80 == NULL )
goto V_325;
if ( F_18 ( V_80 ) ) {
V_189 = F_166 ( V_80 ) ;
goto V_321;
}
V_249 = F_31 ( V_80 , struct V_248 , V_80 ) ;
V_294 = V_249 -> V_294 ;
V_251 = V_249 -> V_251 ;
memcpy ( V_240 , V_249 -> V_240 , sizeof( struct V_54 * ) * V_294 ) ;
V_250 = V_249 -> V_250 ;
}
V_37 = & V_249 -> V_7 . V_37 ;
if ( V_250 == NULL && V_251 > 0 ) {
if ( V_35 -> V_97 . V_313 ) {
F_180 ( V_35 , V_326 ) ;
V_189 = - V_327 ;
goto error;
}
V_189 = - V_238 ;
F_180 ( V_35 , V_326 ) ;
goto error;
}
V_322:
if ( V_294 == 0 )
goto V_325;
if ( ( V_46 & V_328 ) &&
! ( V_240 [ 0 ] -> V_46 & V_329 ) ) {
V_189 = - V_191 ;
goto error;
}
for ( V_126 = 0 ; V_126 < V_294 ; V_126 ++ )
V_240 [ V_126 ] -> V_69 . V_73 = F_21 () ;
if ( V_251 < 0 ) {
F_180 ( V_35 , V_330 ) ;
V_189 = - V_331 ;
goto error;
} else if ( V_251 > 0 ) {
F_167 ( V_296 ) ;
} else {
F_167 ( V_37 ) ;
V_37 = V_296 ;
}
V_332:
F_178 ( V_240 , V_320 ) ;
if ( V_37 && V_37 -> V_97 &&
V_37 -> V_97 -> V_44 . V_230 == V_231 )
V_37 -> V_46 |= V_333 ;
return V_37 ;
V_325:
if ( ! ( V_46 & V_328 ) ) {
V_37 = V_296 ;
goto V_332;
}
V_189 = - V_191 ;
error:
F_167 ( V_37 ) ;
V_321:
if ( ! ( V_46 & V_334 ) )
F_167 ( V_296 ) ;
F_178 ( V_240 , V_320 ) ;
return F_15 ( V_189 ) ;
}
struct V_34 * F_203 ( struct V_35 * V_35 , struct V_34 * V_296 ,
const struct V_3 * V_4 ,
struct V_211 * V_212 , int V_46 )
{
struct V_34 * V_37 = F_187 ( V_35 , V_296 , V_4 , V_212 ,
V_46 | V_312 |
V_334 ) ;
if ( F_18 ( V_37 ) && F_166 ( V_37 ) == - V_327 )
return F_201 ( V_35 , V_296 -> V_93 -> V_28 , V_296 ) ;
return V_37 ;
}
static inline int
F_204 ( int V_165 , struct V_302 * V_303 , const struct V_3 * V_4 )
{
struct V_40 * V_41 ;
if ( ! V_303 -> V_335 || V_165 < 0 || V_165 >= V_303 -> V_335 -> V_171 )
return 0 ;
V_41 = V_303 -> V_335 -> V_336 [ V_165 ] ;
if ( ! V_41 -> type -> V_337 )
return 0 ;
return V_41 -> type -> V_337 ( V_41 , V_303 , V_4 ) ;
}
static inline int
F_205 ( const struct V_222 * V_229 , const struct V_40 * V_41 ,
unsigned short V_28 )
{
if ( F_206 ( V_41 ) )
return V_229 -> V_239 && ! F_207 ( V_229 , V_41 , V_229 -> V_233 ) ;
return V_41 -> V_45 . V_20 == V_229 -> V_45 . V_20 &&
( V_41 -> V_45 . V_338 == V_229 -> V_45 . V_338 || ! V_229 -> V_45 . V_338 ) &&
( V_41 -> V_44 . V_339 == V_229 -> V_339 || ! V_229 -> V_339 ) &&
V_41 -> V_44 . V_230 == V_229 -> V_230 &&
( V_229 -> V_340 || ( V_229 -> V_341 & ( 1 << V_41 -> V_44 . V_342 ) ) ||
! ( F_208 ( V_229 -> V_45 . V_20 , V_343 ) ) ) &&
! ( V_41 -> V_44 . V_230 != V_277 &&
F_207 ( V_229 , V_41 , V_28 ) ) ;
}
static inline int
F_209 ( const struct V_222 * V_229 , const struct V_344 * V_335 , int V_345 ,
unsigned short V_28 )
{
int V_165 = V_345 ;
if ( V_229 -> V_239 ) {
if ( V_229 -> V_230 == V_277 )
return V_345 ;
} else
V_345 = - 1 ;
for (; V_165 < V_335 -> V_171 ; V_165 ++ ) {
if ( F_205 ( V_229 , V_335 -> V_336 [ V_165 ] , V_28 ) )
return ++ V_165 ;
if ( V_335 -> V_336 [ V_165 ] -> V_44 . V_230 != V_277 ) {
if ( V_345 == - 1 )
V_345 = - 2 - V_165 ;
break;
}
}
return V_345 ;
}
int F_210 ( struct V_302 * V_303 , struct V_3 * V_4 ,
unsigned int V_28 , int V_346 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_189 ;
if ( F_9 ( V_32 == NULL ) )
return - V_38 ;
V_32 -> V_347 ( V_303 , V_4 , V_346 ) ;
V_189 = F_211 ( V_303 , & V_4 -> V_203 ) ;
F_13 ( V_32 ) ;
return V_189 ;
}
static inline int F_212 ( const struct V_344 * V_335 , int V_348 , int * V_349 )
{
for (; V_348 < V_335 -> V_171 ; V_348 ++ ) {
if ( V_335 -> V_336 [ V_348 ] -> V_44 . V_230 != V_277 ) {
* V_349 = V_348 ;
return 1 ;
}
}
return 0 ;
}
int F_213 ( struct V_211 * V_212 , int V_60 , struct V_302 * V_303 ,
unsigned short V_28 )
{
struct V_35 * V_35 = F_214 ( V_303 -> V_264 ) ;
struct V_54 * V_81 ;
struct V_54 * V_240 [ V_197 ] ;
int V_241 = 0 ;
int V_220 ;
int V_350 ;
int V_346 ;
struct V_3 V_4 ;
T_4 V_351 ;
int V_352 = - 1 ;
V_346 = V_60 & ~ V_161 ;
V_60 &= V_161 ;
V_351 = F_133 ( V_60 ) ;
if ( F_210 ( V_303 , & V_4 , V_28 , V_346 ) < 0 ) {
F_180 ( V_35 , V_353 ) ;
return 0 ;
}
F_215 ( V_303 , & V_4 , V_28 ) ;
if ( V_303 -> V_335 ) {
int V_126 ;
for ( V_126 = V_303 -> V_335 -> V_171 - 1 ; V_126 >= 0 ; V_126 -- ) {
struct V_40 * V_41 = V_303 -> V_335 -> V_336 [ V_126 ] ;
if ( ! F_7 ( & V_41 -> V_2 , & V_4 , V_28 ) ) {
F_180 ( V_35 , V_354 ) ;
return 0 ;
}
}
}
V_81 = NULL ;
if ( V_212 && V_212 -> V_213 [ V_60 ] ) {
V_81 = F_134 ( V_212 , V_60 , & V_4 ) ;
if ( F_18 ( V_81 ) ) {
F_180 ( V_35 , V_355 ) ;
return 0 ;
}
}
if ( ! V_81 ) {
struct V_79 * V_80 ;
V_80 = F_202 ( V_35 , & V_4 , V_28 , V_351 ,
F_130 , NULL ) ;
if ( F_131 ( V_80 ) )
V_81 = F_132 ( V_80 ) ;
else
V_81 = F_31 ( V_80 , struct V_54 , V_80 ) ;
}
if ( F_18 ( V_81 ) ) {
F_180 ( V_35 , V_355 ) ;
return 0 ;
}
if ( ! V_81 ) {
if ( V_303 -> V_335 && F_212 ( V_303 -> V_335 , 0 , & V_352 ) ) {
F_204 ( V_352 , V_303 , & V_4 ) ;
F_180 ( V_35 , V_356 ) ;
return 0 ;
}
return 1 ;
}
V_81 -> V_69 . V_73 = F_21 () ;
V_240 [ 0 ] = V_81 ;
V_241 ++ ;
#ifdef F_128
if ( V_240 [ 0 ] -> type != V_206 ) {
V_240 [ 1 ] = F_124 ( V_35 , V_206 ,
& V_4 , V_28 ,
V_138 ) ;
if ( V_240 [ 1 ] ) {
if ( F_18 ( V_240 [ 1 ] ) ) {
F_180 ( V_35 , V_355 ) ;
return 0 ;
}
V_240 [ 1 ] -> V_69 . V_73 = F_21 () ;
V_241 ++ ;
}
}
#endif
if ( V_81 -> V_219 == V_295 ) {
struct V_344 * V_335 ;
static struct V_344 V_357 ;
struct V_222 * V_242 [ V_243 ] ;
struct V_222 * V_358 [ V_243 ] ;
struct V_222 * * V_244 = V_242 ;
int V_359 = 0 ;
int V_126 , V_348 ;
if ( ( V_335 = V_303 -> V_335 ) == NULL )
V_335 = & V_357 ;
for ( V_350 = 0 ; V_350 < V_241 ; V_350 ++ ) {
if ( V_240 [ V_350 ] != V_81 &&
V_240 [ V_350 ] -> V_219 != V_295 ) {
F_180 ( V_35 , V_360 ) ;
goto V_337;
}
if ( V_359 + V_240 [ V_350 ] -> V_220 >= V_243 ) {
F_180 ( V_35 , V_361 ) ;
goto V_362;
}
for ( V_126 = 0 ; V_126 < V_240 [ V_350 ] -> V_220 ; V_126 ++ )
V_244 [ V_359 ++ ] = & V_240 [ V_350 ] -> V_221 [ V_126 ] ;
}
V_220 = V_359 ;
if ( V_241 > 1 ) {
F_216 ( V_358 , V_244 , V_220 , V_28 , V_35 ) ;
V_244 = V_358 ;
}
for ( V_126 = V_220 - 1 , V_348 = 0 ; V_126 >= 0 ; V_126 -- ) {
V_348 = F_209 ( V_244 [ V_126 ] , V_335 , V_348 , V_28 ) ;
if ( V_348 < 0 ) {
if ( V_348 < - 1 )
V_352 = - ( 2 + V_348 ) ;
F_180 ( V_35 , V_363 ) ;
goto V_337;
}
}
if ( F_212 ( V_335 , V_348 , & V_352 ) ) {
F_180 ( V_35 , V_363 ) ;
goto V_337;
}
F_178 ( V_240 , V_241 ) ;
return 1 ;
}
F_180 ( V_35 , V_360 ) ;
V_337:
F_204 ( V_352 , V_303 , & V_4 ) ;
V_362:
F_178 ( V_240 , V_241 ) ;
return 0 ;
}
int F_217 ( struct V_302 * V_303 , unsigned short V_28 )
{
struct V_35 * V_35 = F_214 ( V_303 -> V_264 ) ;
struct V_3 V_4 ;
struct V_34 * V_37 ;
int V_364 = 1 ;
if ( F_186 ( V_303 , & V_4 , V_28 ) < 0 ) {
F_180 ( V_35 , V_365 ) ;
return 0 ;
}
F_196 ( V_303 ) ;
V_37 = F_187 ( V_35 , F_185 ( V_303 ) , & V_4 , NULL , V_312 ) ;
if ( F_18 ( V_37 ) ) {
V_364 = 0 ;
V_37 = NULL ;
}
F_192 ( V_303 , V_37 ) ;
return V_364 ;
}
static struct V_34 * F_218 ( struct V_34 * V_37 , T_3 V_366 )
{
if ( V_37 -> V_279 < 0 && ! F_153 ( V_37 ) )
return V_37 ;
return NULL ;
}
static int F_153 ( struct V_34 * V_37 )
{
return ! F_219 ( (struct V_248 * ) V_37 ) ;
}
void F_220 ( struct V_34 * V_37 , struct V_263 * V_264 )
{
while ( ( V_37 = V_37 -> V_275 ) && V_37 -> V_97 && V_37 -> V_264 == V_264 ) {
V_37 -> V_264 = F_214 ( V_264 ) -> V_367 ;
F_221 ( V_37 -> V_264 ) ;
F_222 ( V_264 ) ;
}
}
static void F_223 ( struct V_302 * V_303 )
{
}
static struct V_34 * F_224 ( struct V_34 * V_37 )
{
if ( V_37 ) {
if ( V_37 -> V_279 ) {
F_167 ( V_37 ) ;
V_37 = NULL ;
}
}
return V_37 ;
}
void F_225 ( struct V_35 * V_35 )
{
F_226 ( V_35 ) ;
}
static void F_227 ( struct V_35 * V_35 )
{
F_228 ( V_35 ) ;
}
static void F_172 ( struct V_34 * V_37 )
{
do {
struct V_248 * V_249 = (struct V_248 * ) V_37 ;
T_3 V_368 , V_369 ;
V_368 = F_229 ( V_37 -> V_275 ) ;
V_249 -> V_370 = V_368 ;
V_368 = F_230 ( V_37 -> V_97 , V_368 ) ;
V_369 = F_229 ( V_249 -> V_250 ) ;
V_249 -> V_369 = V_369 ;
if ( V_368 > V_369 )
V_368 = V_369 ;
F_231 ( V_37 , V_371 , V_368 ) ;
} while ( ( V_37 = V_37 -> V_57 ) );
}
static int F_219 ( struct V_248 * V_372 )
{
struct V_34 * V_37 = & V_372 -> V_7 . V_37 ;
struct V_248 * V_373 ;
T_3 V_374 ;
if ( ! F_232 ( V_37 -> V_260 , ( (struct V_248 * ) V_37 ) -> V_375 ) ||
( V_37 -> V_264 && ! F_233 ( V_37 -> V_264 ) ) )
return 0 ;
if ( V_37 -> V_46 & V_252 )
return 1 ;
V_373 = NULL ;
do {
struct V_248 * V_249 = (struct V_248 * ) V_37 ;
if ( V_37 -> V_97 -> V_234 . V_235 != V_236 )
return 0 ;
if ( V_249 -> V_278 != V_37 -> V_97 -> V_96 )
return 0 ;
if ( V_249 -> V_294 > 0 &&
V_249 -> V_300 != F_181 ( & V_249 -> V_240 [ 0 ] -> V_96 ) )
return 0 ;
V_374 = F_229 ( V_37 -> V_275 ) ;
if ( V_249 -> V_370 != V_374 ) {
V_373 = V_249 ;
V_249 -> V_370 = V_374 ;
}
if ( ! F_232 ( V_249 -> V_250 , V_249 -> V_376 ) )
return 0 ;
V_374 = F_229 ( V_249 -> V_250 ) ;
if ( V_249 -> V_369 != V_374 ) {
V_373 = V_249 ;
V_249 -> V_369 = V_374 ;
}
V_37 = V_37 -> V_275 ;
} while ( V_37 -> V_97 );
if ( F_161 ( ! V_373 ) )
return 1 ;
V_374 = V_373 -> V_370 ;
for (; ; ) {
V_37 = & V_373 -> V_7 . V_37 ;
V_374 = F_230 ( V_37 -> V_97 , V_374 ) ;
if ( V_374 > V_373 -> V_369 )
V_374 = V_373 -> V_369 ;
F_231 ( V_37 , V_371 , V_374 ) ;
if ( V_373 == V_372 )
break;
V_373 = (struct V_248 * ) V_373 -> V_7 . V_37 . V_57 ;
V_373 -> V_370 = V_374 ;
}
return 1 ;
}
static unsigned int F_234 ( const struct V_34 * V_37 )
{
return F_235 ( V_37 -> V_260 ) ;
}
static unsigned int F_236 ( const struct V_34 * V_37 )
{
unsigned int V_374 = F_237 ( V_37 , V_371 ) ;
return V_374 ? : F_229 ( V_37 -> V_260 ) ;
}
static struct V_377 * F_238 ( const struct V_34 * V_37 ,
struct V_302 * V_303 ,
const void * V_9 )
{
return V_37 -> V_260 -> V_93 -> V_378 ( V_37 , V_303 , V_9 ) ;
}
int F_239 ( struct V_31 * V_32 )
{
struct V_35 * V_35 ;
int V_189 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_199 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_182 ( & V_379 ) ;
if ( F_9 ( V_31 [ V_32 -> V_28 ] != NULL ) )
V_189 = - V_184 ;
else {
struct V_253 * V_253 = V_32 -> V_253 ;
if ( F_161 ( V_253 -> V_380 == NULL ) )
V_253 -> V_380 = V_381 ;
if ( F_161 ( V_253 -> V_382 == NULL ) )
V_253 -> V_382 = F_218 ;
if ( F_161 ( V_253 -> V_383 == NULL ) )
V_253 -> V_383 = F_234 ;
if ( F_161 ( V_253 -> V_374 == NULL ) )
V_253 -> V_374 = F_236 ;
if ( F_161 ( V_253 -> V_384 == NULL ) )
V_253 -> V_384 = F_224 ;
if ( F_161 ( V_253 -> V_385 == NULL ) )
V_253 -> V_385 = F_223 ;
if ( F_161 ( V_253 -> V_378 == NULL ) )
V_253 -> V_378 = F_238 ;
if ( F_161 ( V_32 -> V_386 == NULL ) )
V_32 -> V_386 = F_227 ;
F_240 ( V_31 [ V_32 -> V_28 ] , V_32 ) ;
}
F_184 ( & V_379 ) ;
F_241 () ;
F_242 (net) {
struct V_253 * V_387 ;
switch ( V_32 -> V_28 ) {
case V_29 :
V_387 = & V_35 -> V_97 . V_254 ;
break;
#if F_159 ( V_255 )
case V_30 :
V_387 = & V_35 -> V_97 . V_256 ;
break;
#endif
default:
F_46 () ;
}
* V_387 = * V_32 -> V_253 ;
}
F_243 () ;
return V_189 ;
}
int F_244 ( struct V_31 * V_32 )
{
int V_189 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_199 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_182 ( & V_379 ) ;
if ( F_161 ( V_31 [ V_32 -> V_28 ] != NULL ) ) {
if ( F_9 ( V_31 [ V_32 -> V_28 ] != V_32 ) )
V_189 = - V_199 ;
else
F_245 ( V_31 [ V_32 -> V_28 ] ,
NULL ) ;
}
F_184 ( & V_379 ) ;
if ( ! V_189 ) {
struct V_253 * V_253 = V_32 -> V_253 ;
F_246 () ;
V_253 -> V_380 = NULL ;
V_253 -> V_382 = NULL ;
V_253 -> V_384 = NULL ;
V_253 -> V_385 = NULL ;
V_32 -> V_386 = NULL ;
}
return V_189 ;
}
static void T_6 F_247 ( struct V_35 * V_35 )
{
struct V_31 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_31 [ V_29 ] ) ;
if ( V_32 )
V_35 -> V_97 . V_254 = * V_32 -> V_253 ;
#if F_159 ( V_255 )
V_32 = F_11 ( V_31 [ V_30 ] ) ;
if ( V_32 )
V_35 -> V_97 . V_256 = * V_32 -> V_253 ;
#endif
F_12 () ;
}
static int F_248 ( struct V_388 * V_389 , unsigned long V_390 , void * V_391 )
{
struct V_263 * V_264 = F_249 ( V_391 ) ;
switch ( V_390 ) {
case V_392 :
F_225 ( F_214 ( V_264 ) ) ;
}
return V_393 ;
}
static int T_6 F_250 ( struct V_35 * V_35 )
{
int V_394 ;
V_35 -> V_395 . V_396 = F_251 ( struct V_397 ) ;
if ( ! V_35 -> V_395 . V_396 )
return - V_224 ;
V_394 = F_252 ( V_35 ) ;
if ( V_394 < 0 )
F_253 ( V_35 -> V_395 . V_396 ) ;
return V_394 ;
}
static void F_254 ( struct V_35 * V_35 )
{
F_255 ( V_35 ) ;
F_253 ( V_35 -> V_395 . V_396 ) ;
}
static int T_6 F_250 ( struct V_35 * V_35 )
{
return 0 ;
}
static void F_254 ( struct V_35 * V_35 )
{
}
static int T_6 F_256 ( struct V_35 * V_35 )
{
unsigned int V_107 , V_398 ;
int V_60 ;
if ( F_257 ( V_35 , & V_399 ) )
V_381 = F_258 ( L_1 ,
sizeof( struct V_248 ) ,
0 , V_400 | V_401 ,
NULL ) ;
V_107 = 8 - 1 ;
V_398 = ( V_107 + 1 ) * sizeof( struct V_106 ) ;
V_35 -> V_97 . V_130 = F_68 ( V_398 ) ;
if ( ! V_35 -> V_97 . V_130 )
goto V_402;
V_35 -> V_97 . V_98 = V_107 ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ ) {
struct V_403 * V_404 ;
V_35 -> V_97 . V_133 [ V_60 ] = 0 ;
V_35 -> V_97 . V_133 [ V_144 + V_60 ] = 0 ;
F_84 ( & V_35 -> V_97 . V_109 [ V_60 ] ) ;
V_404 = & V_35 -> V_97 . V_101 [ V_60 ] ;
V_404 -> V_110 = F_68 ( V_398 ) ;
if ( ! V_404 -> V_110 )
goto V_405;
V_404 -> V_107 = V_107 ;
V_404 -> V_102 = 32 ;
V_404 -> V_103 = 32 ;
V_404 -> V_104 = 128 ;
V_404 -> V_105 = 128 ;
}
V_35 -> V_97 . V_153 . V_157 = 32 ;
V_35 -> V_97 . V_153 . V_158 = 32 ;
V_35 -> V_97 . V_153 . V_159 = 128 ;
V_35 -> V_97 . V_153 . V_160 = 128 ;
F_259 ( & V_35 -> V_97 . V_153 . V_61 ) ;
F_37 ( & V_35 -> V_97 . V_200 ) ;
F_260 ( & V_35 -> V_97 . V_151 , F_78 ) ;
F_260 ( & V_35 -> V_97 . V_153 . V_150 , F_81 ) ;
if ( F_257 ( V_35 , & V_399 ) )
F_261 ( & V_406 ) ;
return 0 ;
V_405:
for ( V_60 -- ; V_60 >= 0 ; V_60 -- ) {
struct V_403 * V_404 ;
V_404 = & V_35 -> V_97 . V_101 [ V_60 ] ;
F_71 ( V_404 -> V_110 , V_398 ) ;
}
F_71 ( V_35 -> V_97 . V_130 , V_398 ) ;
V_402:
return - V_224 ;
}
static void F_262 ( struct V_35 * V_35 )
{
unsigned int V_398 ;
int V_60 ;
F_263 ( & V_35 -> V_97 . V_151 ) ;
#ifdef F_128
F_111 ( V_35 , V_205 , false ) ;
#endif
F_111 ( V_35 , V_206 , false ) ;
F_101 ( ! F_114 ( & V_35 -> V_97 . V_200 ) ) ;
for ( V_60 = 0 ; V_60 < V_144 ; V_60 ++ ) {
struct V_403 * V_404 ;
F_101 ( ! F_64 ( & V_35 -> V_97 . V_109 [ V_60 ] ) ) ;
V_404 = & V_35 -> V_97 . V_101 [ V_60 ] ;
V_398 = ( V_404 -> V_107 + 1 ) * sizeof( struct V_106 ) ;
F_101 ( ! F_64 ( V_404 -> V_110 ) ) ;
F_71 ( V_404 -> V_110 , V_398 ) ;
}
V_398 = ( V_35 -> V_97 . V_98 + 1 ) * sizeof( struct V_106 ) ;
F_101 ( ! F_64 ( V_35 -> V_97 . V_130 ) ) ;
F_71 ( V_35 -> V_97 . V_130 , V_398 ) ;
}
static int T_6 F_264 ( struct V_35 * V_35 )
{
int V_394 ;
V_394 = F_250 ( V_35 ) ;
if ( V_394 < 0 )
goto V_407;
V_394 = F_265 ( V_35 ) ;
if ( V_394 < 0 )
goto V_408;
V_394 = F_256 ( V_35 ) ;
if ( V_394 < 0 )
goto V_409;
F_247 ( V_35 ) ;
V_394 = F_266 ( V_35 ) ;
if ( V_394 < 0 )
goto V_410;
V_394 = F_267 ( V_35 ) ;
if ( V_394 < 0 )
goto V_64;
F_268 ( & V_35 -> V_97 . V_411 ) ;
F_39 ( & V_35 -> V_97 . V_127 ) ;
F_269 ( & V_35 -> V_97 . V_412 ) ;
return 0 ;
V_64:
F_270 ( V_35 ) ;
V_410:
F_262 ( V_35 ) ;
V_409:
F_271 ( V_35 ) ;
V_408:
F_254 ( V_35 ) ;
V_407:
return V_394 ;
}
static void T_7 F_272 ( struct V_35 * V_35 )
{
F_273 ( V_35 ) ;
F_270 ( V_35 ) ;
F_262 ( V_35 ) ;
F_271 ( V_35 ) ;
F_254 ( V_35 ) ;
}
void T_8 F_274 ( void )
{
F_275 ( & V_413 ) ;
F_276 () ;
}
static void F_277 ( struct V_54 * V_55 ,
struct V_414 * V_415 )
{
struct V_186 * V_187 = V_55 -> V_95 ;
struct V_1 * V_2 = & V_55 -> V_120 ;
if ( V_187 )
F_278 ( V_415 , L_2 ,
V_187 -> V_416 , V_187 -> V_417 , V_187 -> V_418 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_278 ( V_415 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_278 ( V_415 , L_4 ,
V_2 -> V_13 ) ;
F_278 ( V_415 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_278 ( V_415 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_278 ( V_415 , L_7 , V_2 -> V_12 . V_419 ) ;
if ( V_2 -> V_13 != 128 )
F_278 ( V_415 , L_4 ,
V_2 -> V_13 ) ;
F_278 ( V_415 , L_8 , V_2 -> V_9 . V_419 ) ;
if ( V_2 -> V_11 != 128 )
F_278 ( V_415 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_279 ( struct V_54 * V_55 , int V_420 , bool V_192 )
{
struct V_414 * V_415 ;
V_415 = F_280 ( L_9 ) ;
if ( V_415 == NULL )
return;
F_281 ( V_192 , V_415 ) ;
F_278 ( V_415 , L_10 , V_420 ) ;
F_277 ( V_55 , V_415 ) ;
F_282 ( V_415 ) ;
}
void F_110 ( struct V_54 * V_55 , int V_420 ,
bool V_192 )
{
struct V_414 * V_415 ;
V_415 = F_280 ( L_11 ) ;
if ( V_415 == NULL )
return;
F_281 ( V_192 , V_415 ) ;
F_278 ( V_415 , L_10 , V_420 ) ;
F_277 ( V_55 , V_415 ) ;
F_282 ( V_415 ) ;
}
static bool F_283 ( const struct V_1 * V_421 ,
const struct V_1 * V_422 )
{
if ( V_421 -> V_20 == V_423 ) {
if ( V_422 -> V_28 == V_421 -> V_28 &&
F_284 ( & V_422 -> V_9 , & V_421 -> V_9 ,
V_421 -> V_28 ) &&
F_284 ( & V_422 -> V_12 , & V_421 -> V_12 ,
V_421 -> V_28 ) &&
V_422 -> V_11 == V_421 -> V_11 &&
V_422 -> V_13 == V_421 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_422 , V_421 , sizeof( * V_422 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_54 * F_285 ( const struct V_1 * V_2 ,
T_4 V_60 , T_4 type , struct V_35 * V_35 )
{
struct V_54 * V_81 , * V_190 = NULL ;
struct V_106 * V_154 ;
T_3 V_162 = ~ 0U ;
F_76 ( & V_35 -> V_97 . V_127 ) ;
V_154 = F_57 ( V_35 , & V_2 -> V_9 , & V_2 -> V_12 , V_2 -> V_28 , V_60 ) ;
F_86 (pol, chain, bydst) {
if ( F_283 ( V_2 , & V_81 -> V_120 ) &&
V_81 -> type == type ) {
V_190 = V_81 ;
V_162 = V_190 -> V_162 ;
break;
}
}
V_154 = & V_35 -> V_97 . V_109 [ V_60 ] ;
F_86 (pol, chain, bydst) {
if ( ( V_81 -> V_162 >= V_162 ) && V_190 )
break;
if ( F_283 ( V_2 , & V_81 -> V_120 ) &&
V_81 -> type == type ) {
V_190 = V_81 ;
break;
}
}
F_26 ( V_190 ) ;
F_77 ( & V_35 -> V_97 . V_127 ) ;
return V_190 ;
}
static int F_286 ( const struct V_424 * V_181 , const struct V_222 * V_425 )
{
int V_201 = 0 ;
if ( V_425 -> V_230 == V_181 -> V_230 && V_425 -> V_45 . V_20 == V_181 -> V_20 &&
( V_181 -> V_339 == 0 || V_425 -> V_339 == V_181 -> V_339 ) ) {
switch ( V_425 -> V_230 ) {
case V_231 :
case V_232 :
if ( F_284 ( & V_425 -> V_45 . V_9 , & V_181 -> V_426 ,
V_181 -> V_427 ) &&
F_284 ( & V_425 -> V_12 , & V_181 -> V_428 ,
V_181 -> V_427 ) ) {
V_201 = 1 ;
}
break;
case V_277 :
V_201 = 1 ;
break;
default:
break;
}
}
return V_201 ;
}
static int F_287 ( struct V_54 * V_81 ,
struct V_424 * V_181 , int V_429 )
{
struct V_424 * V_430 ;
int V_126 , V_431 , V_432 = 0 ;
F_69 ( & V_81 -> V_61 ) ;
if ( F_9 ( V_81 -> V_62 . V_63 ) ) {
F_70 ( & V_81 -> V_61 ) ;
return - V_191 ;
}
for ( V_126 = 0 ; V_126 < V_81 -> V_220 ; V_126 ++ ) {
for ( V_431 = 0 , V_430 = V_181 ; V_431 < V_429 ; V_431 ++ , V_430 ++ ) {
if ( ! F_286 ( V_430 , & V_81 -> V_221 [ V_126 ] ) )
continue;
V_432 ++ ;
if ( V_81 -> V_221 [ V_126 ] . V_230 != V_231 &&
V_81 -> V_221 [ V_126 ] . V_230 != V_232 )
continue;
memcpy ( & V_81 -> V_221 [ V_126 ] . V_45 . V_9 , & V_430 -> V_433 ,
sizeof( V_81 -> V_221 [ V_126 ] . V_45 . V_9 ) ) ;
memcpy ( & V_81 -> V_221 [ V_126 ] . V_12 , & V_430 -> V_434 ,
sizeof( V_81 -> V_221 [ V_126 ] . V_12 ) ) ;
V_81 -> V_221 [ V_126 ] . V_233 = V_430 -> V_435 ;
F_50 ( & V_81 -> V_96 ) ;
}
}
F_70 ( & V_81 -> V_61 ) ;
if ( ! V_432 )
return - V_436 ;
return 0 ;
}
static int F_288 ( const struct V_424 * V_181 , int V_429 )
{
int V_126 , V_431 ;
if ( V_429 < 1 || V_429 > V_243 )
return - V_199 ;
for ( V_126 = 0 ; V_126 < V_429 ; V_126 ++ ) {
if ( F_284 ( & V_181 [ V_126 ] . V_426 , & V_181 [ V_126 ] . V_433 ,
V_181 [ V_126 ] . V_427 ) &&
F_284 ( & V_181 [ V_126 ] . V_428 , & V_181 [ V_126 ] . V_434 ,
V_181 [ V_126 ] . V_427 ) )
return - V_199 ;
if ( F_146 ( & V_181 [ V_126 ] . V_433 , V_181 [ V_126 ] . V_435 ) ||
F_146 ( & V_181 [ V_126 ] . V_434 , V_181 [ V_126 ] . V_435 ) )
return - V_199 ;
for ( V_431 = V_126 + 1 ; V_431 < V_429 ; V_431 ++ ) {
if ( ! memcmp ( & V_181 [ V_126 ] . V_426 , & V_181 [ V_431 ] . V_426 ,
sizeof( V_181 [ V_126 ] . V_426 ) ) &&
! memcmp ( & V_181 [ V_126 ] . V_428 , & V_181 [ V_431 ] . V_428 ,
sizeof( V_181 [ V_126 ] . V_428 ) ) &&
V_181 [ V_126 ] . V_20 == V_181 [ V_431 ] . V_20 &&
V_181 [ V_126 ] . V_230 == V_181 [ V_431 ] . V_230 &&
V_181 [ V_126 ] . V_339 == V_181 [ V_431 ] . V_339 &&
V_181 [ V_126 ] . V_427 == V_181 [ V_431 ] . V_427 )
return - V_199 ;
}
}
return 0 ;
}
int V_424 ( const struct V_1 * V_2 , T_4 V_60 , T_4 type ,
struct V_424 * V_181 , int V_429 ,
struct V_437 * V_348 , struct V_35 * V_35 )
{
int V_126 , V_189 , V_438 = 0 , V_439 = 0 ;
struct V_54 * V_81 = NULL ;
struct V_40 * V_41 , * V_440 ;
struct V_40 * V_441 [ V_243 ] ;
struct V_40 * V_442 [ V_243 ] ;
struct V_424 * V_430 ;
if ( ( V_189 = F_288 ( V_181 , V_429 ) ) < 0 )
goto V_64;
if ( ( V_81 = F_285 ( V_2 , V_60 , type , V_35 ) ) == NULL ) {
V_189 = - V_191 ;
goto V_64;
}
for ( V_126 = 0 , V_430 = V_181 ; V_126 < V_429 ; V_126 ++ , V_430 ++ ) {
if ( ( V_41 = F_289 ( V_430 , V_35 ) ) ) {
V_441 [ V_438 ] = V_41 ;
V_438 ++ ;
if ( ( V_440 = F_290 ( V_41 , V_430 ) ) ) {
V_442 [ V_439 ] = V_440 ;
V_439 ++ ;
} else {
V_189 = - V_436 ;
goto V_443;
}
}
}
if ( ( V_189 = F_287 ( V_81 , V_181 , V_429 ) ) < 0 )
goto V_443;
if ( V_438 ) {
F_291 ( V_441 , V_438 ) ;
F_292 ( V_441 , V_438 ) ;
}
F_293 ( V_2 , V_60 , type , V_181 , V_429 , V_348 ) ;
F_28 ( V_81 ) ;
return 0 ;
V_64:
return V_189 ;
V_443:
if ( V_81 )
F_28 ( V_81 ) ;
if ( V_438 )
F_291 ( V_441 , V_438 ) ;
if ( V_439 )
F_292 ( V_442 , V_439 ) ;
return V_189 ;
}
