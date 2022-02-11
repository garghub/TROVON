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
static void F_49 ( struct V_96 * V_97 )
{
struct V_98 * V_99 ;
while ( ( V_99 = F_50 ( V_97 ) ) != NULL )
F_51 ( V_99 ) ;
}
static void F_52 ( struct V_54 * V_83 )
{
V_83 -> V_62 . V_63 = 1 ;
F_53 ( & V_83 -> V_100 ) ;
if ( F_45 ( & V_83 -> V_89 . V_91 ) )
F_28 ( V_83 ) ;
F_49 ( & V_83 -> V_89 . V_90 ) ;
if ( F_45 ( & V_83 -> V_77 ) )
F_28 ( V_83 ) ;
F_28 ( V_83 ) ;
}
static inline unsigned int F_54 ( struct V_35 * V_35 , T_3 V_65 )
{
return F_55 ( V_65 , V_35 -> V_101 . V_102 ) ;
}
static void F_56 ( struct V_35 * V_35 ,
unsigned short V_28 , int V_60 ,
T_4 * V_103 , T_4 * V_104 )
{
switch ( V_28 ) {
case V_29 :
* V_103 = V_35 -> V_101 . V_105 [ V_60 ] . V_106 ;
* V_104 = V_35 -> V_101 . V_105 [ V_60 ] . V_107 ;
break;
case V_30 :
* V_103 = V_35 -> V_101 . V_105 [ V_60 ] . V_108 ;
* V_104 = V_35 -> V_101 . V_105 [ V_60 ] . V_109 ;
break;
default:
* V_103 = 0 ;
* V_104 = 0 ;
}
}
static struct V_110 * F_57 ( struct V_35 * V_35 ,
const struct V_1 * V_2 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_60 ] . V_111 ;
unsigned int V_112 ;
T_4 V_103 ;
T_4 V_104 ;
F_56 ( V_35 , V_28 , V_60 , & V_103 , & V_104 ) ;
V_112 = F_58 ( V_2 , V_28 , V_111 , V_103 , V_104 ) ;
return ( V_112 == V_111 + 1 ?
& V_35 -> V_101 . V_113 [ V_60 ] :
V_35 -> V_101 . V_105 [ V_60 ] . V_114 + V_112 ) ;
}
static struct V_110 * F_59 ( struct V_35 * V_35 ,
const T_1 * V_9 ,
const T_1 * V_12 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_60 ] . V_111 ;
unsigned int V_112 ;
T_4 V_103 ;
T_4 V_104 ;
F_56 ( V_35 , V_28 , V_60 , & V_103 , & V_104 ) ;
V_112 = F_60 ( V_9 , V_12 , V_28 , V_111 , V_103 , V_104 ) ;
return V_35 -> V_101 . V_105 [ V_60 ] . V_114 + V_112 ;
}
static void F_61 ( struct V_35 * V_35 ,
struct V_110 * V_97 ,
struct V_110 * V_115 ,
unsigned int V_116 ,
int V_60 )
{
struct V_117 * V_118 , * V_119 = NULL ;
struct V_54 * V_81 ;
unsigned int V_120 = 0 ;
T_4 V_103 ;
T_4 V_104 ;
V_121:
F_62 (pol, tmp, list, bydst) {
unsigned int V_122 ;
F_56 ( V_35 , V_81 -> V_28 , V_60 , & V_103 , & V_104 ) ;
V_122 = F_60 ( & V_81 -> V_123 . V_9 , & V_81 -> V_123 . V_12 ,
V_81 -> V_28 , V_116 , V_103 , V_104 ) ;
if ( ! V_119 ) {
F_63 ( & V_81 -> V_86 ) ;
F_64 ( & V_81 -> V_86 , V_115 + V_122 ) ;
V_120 = V_122 ;
} else {
if ( V_122 != V_120 )
continue;
F_63 ( & V_81 -> V_86 ) ;
F_65 ( & V_81 -> V_86 , V_119 ) ;
}
V_119 = & V_81 -> V_86 ;
}
if ( ! F_66 ( V_97 ) ) {
V_119 = NULL ;
goto V_121;
}
}
static void F_67 ( struct V_110 * V_97 ,
struct V_110 * V_124 ,
unsigned int V_116 )
{
struct V_117 * V_118 ;
struct V_54 * V_81 ;
F_62 (pol, tmp, list, byidx) {
unsigned int V_122 ;
V_122 = F_55 ( V_81 -> V_65 , V_116 ) ;
F_64 ( & V_81 -> V_87 , V_124 + V_122 ) ;
}
}
static unsigned long F_68 ( unsigned int V_125 )
{
return ( ( V_125 + 1 ) << 1 ) - 1 ;
}
static void F_69 ( struct V_35 * V_35 , int V_60 )
{
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_60 ] . V_111 ;
unsigned int V_116 = F_68 ( V_111 ) ;
unsigned int V_126 = ( V_116 + 1 ) * sizeof( struct V_110 ) ;
struct V_110 * V_127 = V_35 -> V_101 . V_105 [ V_60 ] . V_114 ;
struct V_110 * V_128 = F_70 ( V_126 ) ;
int V_129 ;
if ( ! V_128 )
return;
F_71 ( & V_35 -> V_101 . V_130 ) ;
for ( V_129 = V_111 ; V_129 >= 0 ; V_129 -- )
F_61 ( V_35 , V_127 + V_129 , V_128 , V_116 , V_60 ) ;
V_35 -> V_101 . V_105 [ V_60 ] . V_114 = V_128 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_111 = V_116 ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
F_73 ( V_127 , ( V_111 + 1 ) * sizeof( struct V_110 ) ) ;
}
static void F_74 ( struct V_35 * V_35 , int V_131 )
{
unsigned int V_111 = V_35 -> V_101 . V_102 ;
unsigned int V_116 = F_68 ( V_111 ) ;
unsigned int V_126 = ( V_116 + 1 ) * sizeof( struct V_110 ) ;
struct V_110 * V_132 = V_35 -> V_101 . V_133 ;
struct V_110 * V_134 = F_70 ( V_126 ) ;
int V_129 ;
if ( ! V_134 )
return;
F_71 ( & V_35 -> V_101 . V_130 ) ;
for ( V_129 = V_111 ; V_129 >= 0 ; V_129 -- )
F_67 ( V_132 + V_129 , V_134 , V_116 ) ;
V_35 -> V_101 . V_133 = V_134 ;
V_35 -> V_101 . V_102 = V_116 ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
F_73 ( V_132 , ( V_111 + 1 ) * sizeof( struct V_110 ) ) ;
}
static inline int F_75 ( struct V_35 * V_35 , int V_60 , int * V_131 )
{
unsigned int V_135 = V_35 -> V_101 . V_136 [ V_60 ] ;
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_60 ] . V_111 ;
if ( V_131 )
* V_131 += V_135 ;
if ( ( V_111 + 1 ) < V_137 &&
V_135 > V_111 )
return 1 ;
return 0 ;
}
static inline int F_76 ( struct V_35 * V_35 , int V_131 )
{
unsigned int V_111 = V_35 -> V_101 . V_102 ;
if ( ( V_111 + 1 ) < V_137 &&
V_131 > V_111 )
return 1 ;
return 0 ;
}
void F_77 ( struct V_35 * V_35 , struct V_138 * V_139 )
{
F_78 ( & V_35 -> V_101 . V_130 ) ;
V_139 -> V_140 = V_35 -> V_101 . V_136 [ V_141 ] ;
V_139 -> V_142 = V_35 -> V_101 . V_136 [ V_143 ] ;
V_139 -> V_144 = V_35 -> V_101 . V_136 [ V_145 ] ;
V_139 -> V_146 = V_35 -> V_101 . V_136 [ V_141 + V_147 ] ;
V_139 -> V_148 = V_35 -> V_101 . V_136 [ V_143 + V_147 ] ;
V_139 -> V_149 = V_35 -> V_101 . V_136 [ V_145 + V_147 ] ;
V_139 -> V_150 = V_35 -> V_101 . V_102 ;
V_139 -> V_151 = V_137 ;
F_79 ( & V_35 -> V_101 . V_130 ) ;
}
static void F_80 ( struct V_152 * V_153 )
{
struct V_35 * V_35 = F_31 ( V_153 , struct V_35 , V_101 . V_154 ) ;
int V_60 , V_131 ;
F_81 ( & V_155 ) ;
V_131 = 0 ;
for ( V_60 = 0 ; V_60 < V_147 ; V_60 ++ ) {
if ( F_75 ( V_35 , V_60 , & V_131 ) )
F_69 ( V_35 , V_60 ) ;
}
if ( F_76 ( V_35 , V_131 ) )
F_74 ( V_35 , V_131 ) ;
F_82 ( & V_155 ) ;
}
static void F_83 ( struct V_152 * V_153 )
{
struct V_35 * V_35 = F_31 ( V_153 , struct V_35 ,
V_101 . V_156 . V_153 ) ;
unsigned int V_111 ;
struct V_54 * V_81 ;
struct V_54 * V_83 ;
struct V_110 * V_157 ;
struct V_110 * V_127 ;
struct V_117 * V_158 ;
int V_129 ;
int V_60 ;
unsigned V_159 ;
T_4 V_160 , V_161 , V_162 , V_163 ;
F_81 ( & V_155 ) ;
do {
V_159 = F_84 ( & V_35 -> V_101 . V_156 . V_61 ) ;
V_160 = V_35 -> V_101 . V_156 . V_160 ;
V_161 = V_35 -> V_101 . V_156 . V_161 ;
V_162 = V_35 -> V_101 . V_156 . V_162 ;
V_163 = V_35 -> V_101 . V_156 . V_163 ;
} while ( F_85 ( & V_35 -> V_101 . V_156 . V_61 , V_159 ) );
F_71 ( & V_35 -> V_101 . V_130 ) ;
for ( V_60 = 0 ; V_60 < V_147 ; V_60 ++ ) {
F_86 ( & V_35 -> V_101 . V_113 [ V_60 ] ) ;
V_111 = V_35 -> V_101 . V_105 [ V_60 ] . V_111 ;
V_127 = V_35 -> V_101 . V_105 [ V_60 ] . V_114 ;
for ( V_129 = V_111 ; V_129 >= 0 ; V_129 -- )
F_86 ( V_127 + V_129 ) ;
if ( ( V_60 & V_164 ) == V_143 ) {
V_35 -> V_101 . V_105 [ V_60 ] . V_106 = V_161 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_107 = V_160 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_108 = V_163 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_109 = V_162 ;
} else {
V_35 -> V_101 . V_105 [ V_60 ] . V_106 = V_160 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_107 = V_161 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_108 = V_162 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_109 = V_163 ;
}
}
F_87 (policy, &net->xfrm.policy_all, walk.all) {
V_158 = NULL ;
V_157 = F_57 ( V_35 , & V_83 -> V_123 ,
V_83 -> V_28 ,
F_23 ( V_83 -> V_65 ) ) ;
F_88 (pol, chain, bydst) {
if ( V_83 -> V_165 >= V_81 -> V_165 )
V_158 = & V_81 -> V_86 ;
else
break;
}
if ( V_158 )
F_65 ( & V_83 -> V_86 , V_158 ) ;
else
F_64 ( & V_83 -> V_86 , V_157 ) ;
}
F_72 ( & V_35 -> V_101 . V_130 ) ;
F_82 ( & V_155 ) ;
}
void F_89 ( struct V_35 * V_35 )
{
F_90 ( & V_35 -> V_101 . V_156 . V_153 ) ;
}
static T_3 F_91 ( struct V_35 * V_35 , int V_60 , T_3 V_65 )
{
static T_3 V_166 ;
for (; ; ) {
struct V_110 * V_97 ;
struct V_54 * V_167 ;
T_3 V_168 ;
int V_169 ;
if ( ! V_65 ) {
V_168 = ( V_166 | V_60 ) ;
V_166 += 8 ;
} else {
V_168 = V_65 ;
V_65 = 0 ;
}
if ( V_168 == 0 )
V_168 = 8 ;
V_97 = V_35 -> V_101 . V_133 + F_54 ( V_35 , V_168 ) ;
V_169 = 0 ;
F_88 (p, list, byidx) {
if ( V_167 -> V_65 == V_168 ) {
V_169 = 1 ;
break;
}
}
if ( ! V_169 )
return V_168 ;
}
}
static inline int F_92 ( struct V_1 * V_170 , struct V_1 * V_171 )
{
T_3 * V_172 = ( T_3 * ) V_170 ;
T_3 * V_173 = ( T_3 * ) V_171 ;
int V_174 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_174 ; V_129 ++ ) {
if ( V_172 [ V_129 ] != V_173 [ V_129 ] )
return 1 ;
}
return 0 ;
}
static void F_93 ( struct V_54 * V_175 ,
struct V_54 * V_176 )
{
struct V_177 * V_178 = & V_175 -> V_89 ;
struct V_96 V_97 ;
F_94 ( & V_97 ) ;
F_95 ( & V_178 -> V_90 . V_61 ) ;
F_96 ( & V_178 -> V_90 , & V_97 ) ;
if ( F_45 ( & V_178 -> V_91 ) )
F_28 ( V_175 ) ;
F_97 ( & V_178 -> V_90 . V_61 ) ;
if ( F_98 ( & V_97 ) )
return;
V_178 = & V_176 -> V_89 ;
F_95 ( & V_178 -> V_90 . V_61 ) ;
F_99 ( & V_97 , & V_178 -> V_90 ) ;
V_178 -> V_179 = V_180 ;
if ( ! F_25 ( & V_178 -> V_91 , V_78 ) )
F_26 ( V_176 ) ;
F_97 ( & V_178 -> V_90 . V_61 ) ;
}
static bool F_100 ( struct V_54 * V_83 ,
struct V_54 * V_81 )
{
T_3 V_181 = V_83 -> V_181 . V_182 & V_83 -> V_181 . V_183 ;
if ( V_83 -> V_181 . V_182 == V_81 -> V_181 . V_182 && V_83 -> V_181 . V_183 == V_81 -> V_181 . V_183 )
return true ;
if ( ( V_181 & V_81 -> V_181 . V_183 ) == V_81 -> V_181 . V_182 &&
V_83 -> V_165 == V_81 -> V_165 )
return true ;
return false ;
}
int F_101 ( int V_60 , struct V_54 * V_83 , int V_184 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
struct V_54 * V_81 ;
struct V_54 * V_185 ;
struct V_110 * V_157 ;
struct V_117 * V_158 ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
V_157 = F_57 ( V_35 , & V_83 -> V_123 , V_83 -> V_28 , V_60 ) ;
V_185 = NULL ;
V_158 = NULL ;
F_88 (pol, chain, bydst) {
if ( V_81 -> type == V_83 -> type &&
! F_92 ( & V_81 -> V_123 , & V_83 -> V_123 ) &&
F_100 ( V_83 , V_81 ) &&
F_102 ( V_81 -> V_95 , V_83 -> V_95 ) &&
! F_103 ( V_185 ) ) {
if ( V_184 ) {
F_72 ( & V_35 -> V_101 . V_130 ) ;
return - V_186 ;
}
V_185 = V_81 ;
if ( V_83 -> V_165 > V_81 -> V_165 )
continue;
} else if ( V_83 -> V_165 >= V_81 -> V_165 ) {
V_158 = & V_81 -> V_86 ;
continue;
}
if ( V_185 )
break;
}
if ( V_158 )
F_65 ( & V_83 -> V_86 , V_158 ) ;
else
F_64 ( & V_83 -> V_86 , V_157 ) ;
F_104 ( V_83 , V_60 ) ;
F_53 ( & V_35 -> V_101 . V_187 ) ;
if ( V_83 -> V_28 == V_29 )
F_105 ( V_35 ) ;
else
F_106 ( V_35 ) ;
if ( V_185 ) {
F_93 ( V_185 , V_83 ) ;
F_107 ( V_185 , V_60 ) ;
}
V_83 -> V_65 = V_185 ? V_185 -> V_65 : F_91 ( V_35 , V_60 , V_83 -> V_65 ) ;
F_64 ( & V_83 -> V_87 , V_35 -> V_101 . V_133 + F_54 ( V_35 , V_83 -> V_65 ) ) ;
V_83 -> V_69 . V_70 = F_21 () ;
V_83 -> V_69 . V_73 = 0 ;
if ( ! F_25 ( & V_83 -> V_77 , V_78 + V_52 ) )
F_26 ( V_83 ) ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
if ( V_185 )
F_52 ( V_185 ) ;
else if ( F_75 ( V_35 , V_60 , NULL ) )
F_90 ( & V_35 -> V_101 . V_154 ) ;
return 0 ;
}
struct V_54 * F_108 ( struct V_35 * V_35 , T_3 V_181 , T_4 type ,
int V_60 , struct V_1 * V_2 ,
struct V_188 * V_189 , int V_190 ,
int * V_191 )
{
struct V_54 * V_81 , * V_192 ;
struct V_110 * V_157 ;
* V_191 = 0 ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
V_157 = F_57 ( V_35 , V_2 , V_2 -> V_28 , V_60 ) ;
V_192 = NULL ;
F_88 (pol, chain, bydst) {
if ( V_81 -> type == type &&
( V_181 & V_81 -> V_181 . V_183 ) == V_81 -> V_181 . V_182 &&
! F_92 ( V_2 , & V_81 -> V_123 ) &&
F_102 ( V_189 , V_81 -> V_95 ) ) {
F_26 ( V_81 ) ;
if ( V_190 ) {
* V_191 = F_109 (
V_81 -> V_95 ) ;
if ( * V_191 ) {
F_72 ( & V_35 -> V_101 . V_130 ) ;
return V_81 ;
}
F_107 ( V_81 , V_60 ) ;
}
V_192 = V_81 ;
break;
}
}
F_72 ( & V_35 -> V_101 . V_130 ) ;
if ( V_192 && V_190 )
F_52 ( V_192 ) ;
return V_192 ;
}
struct V_54 * F_110 ( struct V_35 * V_35 , T_3 V_181 , T_4 type ,
int V_60 , T_3 V_45 , int V_190 , int * V_191 )
{
struct V_54 * V_81 , * V_192 ;
struct V_110 * V_157 ;
* V_191 = - V_193 ;
if ( F_23 ( V_45 ) != V_60 )
return NULL ;
* V_191 = 0 ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
V_157 = V_35 -> V_101 . V_133 + F_54 ( V_35 , V_45 ) ;
V_192 = NULL ;
F_88 (pol, chain, byidx) {
if ( V_81 -> type == type && V_81 -> V_65 == V_45 &&
( V_181 & V_81 -> V_181 . V_183 ) == V_81 -> V_181 . V_182 ) {
F_26 ( V_81 ) ;
if ( V_190 ) {
* V_191 = F_109 (
V_81 -> V_95 ) ;
if ( * V_191 ) {
F_72 ( & V_35 -> V_101 . V_130 ) ;
return V_81 ;
}
F_107 ( V_81 , V_60 ) ;
}
V_192 = V_81 ;
break;
}
}
F_72 ( & V_35 -> V_101 . V_130 ) ;
if ( V_192 && V_190 )
F_52 ( V_192 ) ;
return V_192 ;
}
static inline int
F_111 ( struct V_35 * V_35 , T_4 type , bool V_194 )
{
int V_60 , V_191 = 0 ;
for ( V_60 = 0 ; V_60 < V_147 ; V_60 ++ ) {
struct V_54 * V_81 ;
int V_129 ;
F_88 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
V_191 = F_109 ( V_81 -> V_95 ) ;
if ( V_191 ) {
F_112 ( V_81 , 0 , V_194 ) ;
return V_191 ;
}
}
for ( V_129 = V_35 -> V_101 . V_105 [ V_60 ] . V_111 ; V_129 >= 0 ; V_129 -- ) {
F_88 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
V_191 = F_109 (
V_81 -> V_95 ) ;
if ( V_191 ) {
F_112 ( V_81 , 0 ,
V_194 ) ;
return V_191 ;
}
}
}
}
return V_191 ;
}
static inline int
F_111 ( struct V_35 * V_35 , T_4 type , bool V_194 )
{
return 0 ;
}
int F_113 ( struct V_35 * V_35 , T_4 type , bool V_194 )
{
int V_60 , V_191 = 0 , V_135 = 0 ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
V_191 = F_111 ( V_35 , type , V_194 ) ;
if ( V_191 )
goto V_64;
for ( V_60 = 0 ; V_60 < V_147 ; V_60 ++ ) {
struct V_54 * V_81 ;
int V_129 ;
V_195:
F_88 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
F_107 ( V_81 , V_60 ) ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
V_135 ++ ;
F_112 ( V_81 , 1 , V_194 ) ;
F_52 ( V_81 ) ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
goto V_195;
}
for ( V_129 = V_35 -> V_101 . V_105 [ V_60 ] . V_111 ; V_129 >= 0 ; V_129 -- ) {
V_196:
F_88 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
F_107 ( V_81 , V_60 ) ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
V_135 ++ ;
F_112 ( V_81 , 1 , V_194 ) ;
F_52 ( V_81 ) ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
goto V_196;
}
}
}
if ( ! V_135 )
V_191 = - V_197 ;
V_64:
F_72 ( & V_35 -> V_101 . V_130 ) ;
return V_191 ;
}
int F_114 ( struct V_35 * V_35 , struct F_114 * V_62 ,
int (* F_115)( struct V_54 * , int , int , void * ) ,
void * V_53 )
{
struct V_54 * V_81 ;
struct V_198 * V_41 ;
int error = 0 ;
if ( V_62 -> type >= V_199 &&
V_62 -> type != V_200 )
return - V_201 ;
if ( F_116 ( & V_62 -> V_62 . V_85 ) && V_62 -> V_159 != 0 )
return 0 ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
if ( F_116 ( & V_62 -> V_62 . V_85 ) )
V_41 = F_117 ( & V_35 -> V_101 . V_202 , struct V_198 , V_85 ) ;
else
V_41 = F_118 ( & V_62 -> V_62 . V_85 , struct V_198 , V_85 ) ;
F_119 (x, &net->xfrm.policy_all, all) {
if ( V_41 -> V_63 )
continue;
V_81 = F_31 ( V_41 , struct V_54 , V_62 ) ;
if ( V_62 -> type != V_200 &&
V_62 -> type != V_81 -> type )
continue;
error = F_115 ( V_81 , F_23 ( V_81 -> V_65 ) ,
V_62 -> V_159 , V_53 ) ;
if ( error ) {
F_120 ( & V_62 -> V_62 . V_85 , & V_41 -> V_85 ) ;
goto V_64;
}
V_62 -> V_159 ++ ;
}
if ( V_62 -> V_159 == 0 ) {
error = - V_193 ;
goto V_64;
}
F_121 ( & V_62 -> V_62 . V_85 ) ;
V_64:
F_72 ( & V_35 -> V_101 . V_130 ) ;
return error ;
}
void F_122 ( struct F_114 * V_62 , T_4 type )
{
F_37 ( & V_62 -> V_62 . V_85 ) ;
V_62 -> V_62 . V_63 = 1 ;
V_62 -> type = type ;
V_62 -> V_159 = 0 ;
}
void F_123 ( struct F_114 * V_62 , struct V_35 * V_35 )
{
if ( F_116 ( & V_62 -> V_62 . V_85 ) )
return;
F_71 ( & V_35 -> V_101 . V_130 ) ;
F_124 ( & V_62 -> V_62 . V_85 ) ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
}
static int F_125 ( const struct V_54 * V_81 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_28 , int V_60 )
{
const struct V_1 * V_2 = & V_81 -> V_123 ;
int V_192 = - V_197 ;
bool V_203 ;
if ( V_81 -> V_28 != V_28 ||
( V_4 -> V_204 & V_81 -> V_181 . V_183 ) != V_81 -> V_181 . V_182 ||
V_81 -> type != type )
return V_192 ;
V_203 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_203 )
V_192 = F_126 ( V_81 -> V_95 , V_4 -> V_205 ,
V_60 ) ;
return V_192 ;
}
static struct V_54 * F_127 ( struct V_35 * V_35 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_28 , T_4 V_60 )
{
int V_191 ;
struct V_54 * V_81 , * V_192 ;
const T_1 * V_9 , * V_12 ;
struct V_110 * V_157 ;
T_3 V_165 = ~ 0U ;
V_9 = F_128 ( V_4 , V_28 ) ;
V_12 = F_129 ( V_4 , V_28 ) ;
if ( F_9 ( ! V_9 || ! V_12 ) )
return NULL ;
F_78 ( & V_35 -> V_101 . V_130 ) ;
V_157 = F_59 ( V_35 , V_9 , V_12 , V_28 , V_60 ) ;
V_192 = NULL ;
F_88 (pol, chain, bydst) {
V_191 = F_125 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_191 ) {
if ( V_191 == - V_197 )
continue;
else {
V_192 = F_15 ( V_191 ) ;
goto V_206;
}
} else {
V_192 = V_81 ;
V_165 = V_192 -> V_165 ;
break;
}
}
V_157 = & V_35 -> V_101 . V_113 [ V_60 ] ;
F_88 (pol, chain, bydst) {
V_191 = F_125 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_191 ) {
if ( V_191 == - V_197 )
continue;
else {
V_192 = F_15 ( V_191 ) ;
goto V_206;
}
} else if ( V_81 -> V_165 < V_165 ) {
V_192 = V_81 ;
break;
}
}
if ( V_192 )
F_26 ( V_192 ) ;
V_206:
F_79 ( & V_35 -> V_101 . V_130 ) ;
return V_192 ;
}
static struct V_54 *
F_130 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 )
{
#ifdef F_131
struct V_54 * V_81 ;
V_81 = F_127 ( V_35 , V_207 , V_4 , V_28 , V_60 ) ;
if ( V_81 != NULL )
return V_81 ;
#endif
return F_127 ( V_35 , V_208 , V_4 , V_28 , V_60 ) ;
}
static int F_132 ( int V_60 )
{
if ( V_141 == V_209 &&
V_143 == V_210 &&
V_145 == V_211 )
return V_60 ;
switch ( V_60 ) {
default:
case V_209 :
return V_141 ;
case V_210 :
return V_143 ;
case V_211 :
return V_145 ;
}
}
static struct V_79 *
F_133 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_60 , struct V_79 * V_212 , void * V_189 )
{
struct V_54 * V_81 ;
if ( V_212 )
F_28 ( F_31 ( V_212 , struct V_54 , V_80 ) ) ;
V_81 = F_130 ( V_35 , V_4 , V_28 , F_132 ( V_60 ) ) ;
if ( F_134 ( V_81 ) )
return F_135 ( V_81 ) ;
F_26 ( V_81 ) ;
return & V_81 -> V_80 ;
}
static inline int F_136 ( int V_60 )
{
if ( V_141 == V_209 &&
V_143 == V_210 &&
V_145 == V_211 )
return V_60 ;
switch ( V_60 ) {
default:
case V_141 :
return V_209 ;
case V_143 :
return V_210 ;
case V_145 :
return V_211 ;
}
}
static struct V_54 * F_137 ( struct V_213 * V_214 , int V_60 ,
const struct V_3 * V_4 )
{
struct V_54 * V_81 ;
struct V_35 * V_35 = F_138 ( V_214 ) ;
F_78 ( & V_35 -> V_101 . V_130 ) ;
if ( ( V_81 = V_214 -> V_215 [ V_60 ] ) != NULL ) {
bool V_203 = F_7 ( & V_81 -> V_123 , V_4 ,
V_214 -> V_216 ) ;
int V_191 = 0 ;
if ( V_203 ) {
if ( ( V_214 -> V_217 & V_81 -> V_181 . V_183 ) != V_81 -> V_181 . V_182 ) {
V_81 = NULL ;
goto V_64;
}
V_191 = F_126 ( V_81 -> V_95 ,
V_4 -> V_205 ,
F_136 ( V_60 ) ) ;
if ( ! V_191 )
F_26 ( V_81 ) ;
else if ( V_191 == - V_197 )
V_81 = NULL ;
else
V_81 = F_15 ( V_191 ) ;
} else
V_81 = NULL ;
}
V_64:
F_79 ( & V_35 -> V_101 . V_130 ) ;
return V_81 ;
}
static void F_104 ( struct V_54 * V_81 , int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
F_139 ( & V_81 -> V_62 . V_85 , & V_35 -> V_101 . V_202 ) ;
V_35 -> V_101 . V_136 [ V_60 ] ++ ;
F_26 ( V_81 ) ;
}
static struct V_54 * F_107 ( struct V_54 * V_81 ,
int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
if ( F_116 ( & V_81 -> V_62 . V_85 ) )
return NULL ;
if ( ! F_140 ( & V_81 -> V_86 ) ) {
F_63 ( & V_81 -> V_86 ) ;
F_63 ( & V_81 -> V_87 ) ;
}
F_121 ( & V_81 -> V_62 . V_85 ) ;
V_35 -> V_101 . V_136 [ V_60 ] -- ;
return V_81 ;
}
static void F_141 ( struct V_54 * V_81 , int V_60 )
{
F_104 ( V_81 , V_147 + V_60 ) ;
}
static void F_142 ( struct V_54 * V_81 , int V_60 )
{
F_107 ( V_81 , V_147 + V_60 ) ;
}
int F_29 ( struct V_54 * V_81 , int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
V_81 = F_107 ( V_81 , V_60 ) ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
if ( V_81 ) {
F_52 ( V_81 ) ;
return 0 ;
}
return - V_193 ;
}
int F_143 ( struct V_213 * V_214 , int V_60 , struct V_54 * V_81 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
struct V_54 * V_218 ;
#ifdef F_131
if ( V_81 && V_81 -> type != V_208 )
return - V_201 ;
#endif
F_71 ( & V_35 -> V_101 . V_130 ) ;
V_218 = V_214 -> V_215 [ V_60 ] ;
V_214 -> V_215 [ V_60 ] = V_81 ;
if ( V_81 ) {
V_81 -> V_69 . V_70 = F_21 () ;
V_81 -> V_65 = F_91 ( V_35 , V_147 + V_60 , 0 ) ;
F_141 ( V_81 , V_60 ) ;
}
if ( V_218 ) {
if ( V_81 )
F_93 ( V_218 , V_81 ) ;
F_142 ( V_218 , V_60 ) ;
}
F_72 ( & V_35 -> V_101 . V_130 ) ;
if ( V_218 ) {
F_52 ( V_218 ) ;
}
return 0 ;
}
static struct V_54 * F_144 ( const struct V_54 * V_175 , int V_60 )
{
struct V_54 * V_219 = F_34 ( V_84 ( V_175 ) , V_220 ) ;
struct V_35 * V_35 = V_84 ( V_175 ) ;
if ( V_219 ) {
V_219 -> V_123 = V_175 -> V_123 ;
if ( F_145 ( V_175 -> V_95 ,
& V_219 -> V_95 ) ) {
F_48 ( V_219 ) ;
return NULL ;
}
V_219 -> V_66 = V_175 -> V_66 ;
V_219 -> V_69 = V_175 -> V_69 ;
V_219 -> V_181 = V_175 -> V_181 ;
V_219 -> V_221 = V_175 -> V_221 ;
V_219 -> V_46 = V_175 -> V_46 ;
V_219 -> V_222 = V_175 -> V_222 ;
V_219 -> V_65 = V_175 -> V_65 ;
V_219 -> type = V_175 -> type ;
memcpy ( V_219 -> V_223 , V_175 -> V_223 ,
V_219 -> V_222 * sizeof( struct V_224 ) ) ;
F_71 ( & V_35 -> V_101 . V_130 ) ;
F_141 ( V_219 , V_60 ) ;
F_72 ( & V_35 -> V_101 . V_130 ) ;
F_28 ( V_219 ) ;
}
return V_219 ;
}
int F_146 ( struct V_213 * V_214 )
{
struct V_54 * V_225 = V_214 -> V_215 [ 0 ] ,
* V_172 = V_214 -> V_215 [ 1 ] ;
V_214 -> V_215 [ 0 ] = V_214 -> V_215 [ 1 ] = NULL ;
if ( V_225 && ( V_214 -> V_215 [ 0 ] = F_144 ( V_225 , 0 ) ) == NULL )
return - V_226 ;
if ( V_172 && ( V_214 -> V_215 [ 1 ] = F_144 ( V_172 , 1 ) ) == NULL )
return - V_226 ;
return 0 ;
}
static int
F_147 ( struct V_35 * V_35 , T_1 * V_227 , T_1 * V_228 ,
unsigned short V_28 )
{
int V_191 ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return - V_201 ;
V_191 = V_32 -> V_229 ( V_35 , V_227 , V_228 ) ;
F_13 ( V_32 ) ;
return V_191 ;
}
static int
F_148 ( struct V_54 * V_83 , const struct V_3 * V_4 ,
struct V_40 * * V_101 , unsigned short V_28 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
int V_230 ;
int V_129 , error ;
T_1 * V_9 = F_128 ( V_4 , V_28 ) ;
T_1 * V_12 = F_129 ( V_4 , V_28 ) ;
T_1 V_118 ;
for ( V_230 = 0 , V_129 = 0 ; V_129 < V_83 -> V_222 ; V_129 ++ ) {
struct V_40 * V_41 ;
T_1 * V_228 = V_9 ;
T_1 * V_227 = V_12 ;
struct V_224 * V_231 = & V_83 -> V_223 [ V_129 ] ;
if ( V_231 -> V_232 == V_233 ||
V_231 -> V_232 == V_234 ) {
V_228 = & V_231 -> V_45 . V_9 ;
V_227 = & V_231 -> V_12 ;
if ( F_149 ( V_227 , V_231 -> V_235 ) ) {
error = F_147 ( V_35 , & V_118 , V_228 , V_231 -> V_235 ) ;
if ( error )
goto V_206;
V_227 = & V_118 ;
}
}
V_41 = F_150 ( V_228 , V_227 , V_4 , V_231 , V_83 , & error , V_28 ) ;
if ( V_41 && V_41 -> V_236 . V_237 == V_238 ) {
V_101 [ V_230 ++ ] = V_41 ;
V_9 = V_228 ;
V_12 = V_227 ;
continue;
}
if ( V_41 ) {
error = ( V_41 -> V_236 . V_237 == V_239 ?
- V_201 : - V_240 ) ;
F_151 ( V_41 ) ;
} else if ( error == - V_197 ) {
error = - V_240 ;
}
if ( ! V_231 -> V_241 )
goto V_206;
}
return V_230 ;
V_206:
for ( V_230 -- ; V_230 >= 0 ; V_230 -- )
F_151 ( V_101 [ V_230 ] ) ;
return error ;
}
static int
F_152 ( struct V_54 * * V_242 , int V_243 , const struct V_3 * V_4 ,
struct V_40 * * V_101 , unsigned short V_28 )
{
struct V_40 * V_244 [ V_245 ] ;
struct V_40 * * V_246 = ( V_243 > 1 ) ? V_244 : V_101 ;
int V_247 = 0 ;
int error ;
int V_192 ;
int V_129 ;
for ( V_129 = 0 ; V_129 < V_243 ; V_129 ++ ) {
if ( V_247 + V_242 [ V_129 ] -> V_222 >= V_245 ) {
error = - V_248 ;
goto V_206;
}
V_192 = F_148 ( V_242 [ V_129 ] , V_4 , & V_246 [ V_247 ] , V_28 ) ;
if ( V_192 < 0 ) {
error = V_192 ;
goto V_206;
} else
V_247 += V_192 ;
}
if ( V_243 > 1 )
F_153 ( V_101 , V_246 , V_247 , V_28 ) ;
return V_247 ;
V_206:
for ( V_247 -- ; V_247 >= 0 ; V_247 -- )
F_151 ( V_246 [ V_247 ] ) ;
return error ;
}
static inline int F_154 ( const struct V_3 * V_4 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_36 ;
if ( ! V_32 )
return - V_201 ;
V_36 = V_32 -> V_249 ( V_4 ) ;
F_13 ( V_32 ) ;
return V_36 ;
}
static struct V_79 * F_155 ( struct V_79 * V_80 )
{
struct V_250 * V_251 = F_31 ( V_80 , struct V_250 , V_80 ) ;
struct V_34 * V_37 = & V_251 -> V_7 . V_37 ;
if ( V_251 -> V_252 == NULL ) {
if ( V_251 -> V_253 > 0 )
return NULL ;
} else if ( V_37 -> V_46 & V_254 ) {
return NULL ;
} else {
if ( F_156 ( V_37 ) )
return NULL ;
}
F_157 ( V_37 ) ;
return V_80 ;
}
static int F_158 ( struct V_79 * V_80 )
{
struct V_250 * V_251 = F_31 ( V_80 , struct V_250 , V_80 ) ;
struct V_34 * V_37 = & V_251 -> V_7 . V_37 ;
if ( ! V_251 -> V_252 )
return 0 ;
if ( F_156 ( V_37 ) )
return 0 ;
return 1 ;
}
static void F_159 ( struct V_79 * V_80 )
{
struct V_250 * V_251 = F_31 ( V_80 , struct V_250 , V_80 ) ;
struct V_34 * V_37 = & V_251 -> V_7 . V_37 ;
F_160 ( V_37 ) ;
}
static inline struct V_250 * F_161 ( struct V_35 * V_35 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_255 * V_255 ;
struct V_250 * V_251 ;
if ( ! V_32 )
return F_15 ( - V_201 ) ;
switch ( V_28 ) {
case V_29 :
V_255 = & V_35 -> V_101 . V_256 ;
break;
#if F_162 ( V_257 )
case V_30 :
V_255 = & V_35 -> V_101 . V_258 ;
break;
#endif
default:
F_46 () ;
}
V_251 = F_163 ( V_255 , NULL , 0 , V_259 , 0 ) ;
if ( F_164 ( V_251 ) ) {
struct V_34 * V_37 = & V_251 -> V_7 . V_37 ;
memset ( V_37 + 1 , 0 , sizeof( * V_251 ) - sizeof( * V_37 ) ) ;
V_251 -> V_80 . V_93 = & V_260 ;
if ( V_32 -> V_261 )
V_32 -> V_261 ( V_35 , V_251 ) ;
} else
V_251 = F_15 ( - V_248 ) ;
F_13 ( V_32 ) ;
return V_251 ;
}
static inline int F_165 ( struct V_250 * V_262 , struct V_34 * V_37 ,
int V_263 )
{
struct V_31 * V_32 =
F_8 ( V_37 -> V_93 -> V_28 ) ;
int V_191 ;
if ( ! V_32 )
return - V_201 ;
V_191 = V_32 -> V_264 ( V_262 , V_37 , V_263 ) ;
F_13 ( V_32 ) ;
return V_191 ;
}
static inline int F_166 ( struct V_250 * V_251 , struct V_265 * V_266 ,
const struct V_3 * V_4 )
{
struct V_31 * V_32 =
F_8 ( V_251 -> V_7 . V_37 . V_93 -> V_28 ) ;
int V_191 ;
if ( ! V_32 )
return - V_201 ;
V_191 = V_32 -> V_267 ( V_251 , V_266 , V_4 ) ;
F_13 ( V_32 ) ;
return V_191 ;
}
static struct V_34 * F_167 ( struct V_54 * V_83 ,
struct V_40 * * V_101 , int V_230 ,
const struct V_3 * V_4 ,
struct V_34 * V_37 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
unsigned long V_56 = V_78 ;
struct V_265 * V_266 ;
struct V_268 * V_269 ;
struct V_34 * V_270 = NULL ;
struct V_34 * V_271 = NULL ;
int V_129 = 0 ;
int V_191 ;
int V_272 = 0 ;
int V_263 = 0 ;
int V_273 = 0 ;
int V_36 ;
int V_28 = V_83 -> V_123 . V_28 ;
T_1 V_12 , V_9 ;
F_168 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_36 = F_154 ( V_4 , V_28 ) ;
V_191 = V_36 ;
if ( V_36 < 0 )
goto V_274;
F_157 ( V_37 ) ;
for (; V_129 < V_230 ; V_129 ++ ) {
struct V_250 * V_251 = F_161 ( V_35 , V_28 ) ;
struct V_34 * V_275 = & V_251 -> V_7 . V_37 ;
V_191 = F_169 ( V_251 ) ;
if ( F_18 ( V_251 ) ) {
F_170 ( V_37 ) ;
goto V_274;
}
if ( V_101 [ V_129 ] -> V_2 . V_28 == V_276 ) {
V_269 = F_171 ( V_101 [ V_129 ] ,
F_172 ( V_28 ) ) ;
if ( ! V_269 ) {
V_191 = - V_38 ;
F_170 ( V_37 ) ;
goto V_274;
}
} else
V_269 = V_101 [ V_129 ] -> V_269 ;
if ( ! V_270 )
V_271 = V_275 ;
else {
V_270 -> V_277 = F_173 ( V_275 ) ;
V_275 -> V_46 |= V_278 ;
}
V_251 -> V_252 = V_37 ;
F_174 ( V_275 , V_37 ) ;
if ( V_101 [ V_129 ] -> V_44 . V_232 != V_279 ) {
V_28 = V_101 [ V_129 ] -> V_44 . V_28 ;
V_37 = F_16 ( V_101 [ V_129 ] , V_36 , & V_12 , & V_9 ,
V_28 ) ;
V_191 = F_169 ( V_37 ) ;
if ( F_18 ( V_37 ) )
goto V_274;
} else
F_157 ( V_37 ) ;
V_275 -> V_101 = V_101 [ V_129 ] ;
V_251 -> V_280 = V_101 [ V_129 ] -> V_100 ;
V_275 -> V_281 = V_282 ;
V_275 -> V_46 |= V_283 ;
V_275 -> V_284 = V_56 ;
V_275 -> V_285 = V_286 ;
V_275 -> V_287 = V_269 -> V_32 -> V_287 ;
V_275 -> V_57 = V_270 ;
V_270 = V_275 ;
V_272 += V_101 [ V_129 ] -> V_44 . V_272 ;
if ( V_101 [ V_129 ] -> type -> V_46 & V_288 )
V_263 += V_101 [ V_129 ] -> V_44 . V_272 ;
V_273 += V_101 [ V_129 ] -> V_44 . V_273 ;
}
V_270 -> V_277 = V_37 ;
V_271 -> V_262 = V_37 ;
V_191 = - V_289 ;
V_266 = V_37 -> V_266 ;
if ( ! V_266 )
goto V_290;
F_165 ( (struct V_250 * ) V_271 , V_37 , V_263 ) ;
F_175 ( V_270 ) ;
for ( V_270 = V_271 ; V_270 != V_37 ; V_270 = V_270 -> V_277 ) {
struct V_250 * V_251 = (struct V_250 * ) V_270 ;
V_191 = F_166 ( V_251 , V_266 , V_4 ) ;
if ( V_191 )
goto V_290;
V_270 -> V_272 = V_272 ;
V_270 -> V_273 = V_273 ;
V_272 -= V_251 -> V_7 . V_37 . V_101 -> V_44 . V_272 ;
V_273 -= V_251 -> V_7 . V_37 . V_101 -> V_44 . V_273 ;
}
V_64:
return V_271 ;
V_274:
for (; V_129 < V_230 ; V_129 ++ )
F_151 ( V_101 [ V_129 ] ) ;
V_290:
if ( V_271 )
F_160 ( V_271 ) ;
V_271 = F_15 ( V_191 ) ;
goto V_64;
}
static int F_176 ( void * * V_291 , const void * V_292 , int V_293 )
{
if ( ! * V_291 ) {
* V_291 = F_177 ( V_293 , V_220 ) ;
if ( ! * V_291 )
return - V_226 ;
}
memcpy ( * V_291 , V_292 , V_293 ) ;
return 0 ;
}
static int F_178 ( struct V_34 * V_37 ,
const struct V_1 * V_2 )
{
#ifdef F_131
struct V_250 * V_251 = (struct V_250 * ) V_37 ;
return F_176 ( ( void * * ) & ( V_251 -> V_294 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int F_179 ( struct V_34 * V_37 ,
const struct V_3 * V_4 )
{
#ifdef F_131
struct V_250 * V_251 = (struct V_250 * ) V_37 ;
return F_176 ( ( void * * ) & ( V_251 -> V_295 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_180 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_54 * * V_242 ,
int * V_296 , int * V_253 )
{
int V_129 ;
if ( * V_296 == 0 || ! V_242 [ 0 ] ) {
* V_296 = 0 ;
* V_253 = 0 ;
return 0 ;
}
if ( F_18 ( V_242 [ 0 ] ) )
return F_169 ( V_242 [ 0 ] ) ;
* V_253 = V_242 [ 0 ] -> V_222 ;
#ifdef F_131
if ( V_242 [ 0 ] && V_242 [ 0 ] -> V_221 == V_297 &&
V_242 [ 0 ] -> type != V_208 ) {
V_242 [ 1 ] = F_127 ( V_84 ( V_242 [ 0 ] ) ,
V_208 ,
V_4 , V_28 ,
V_143 ) ;
if ( V_242 [ 1 ] ) {
if ( F_18 ( V_242 [ 1 ] ) ) {
F_181 ( V_242 , * V_296 ) ;
return F_169 ( V_242 [ 1 ] ) ;
}
( * V_296 ) ++ ;
( * V_253 ) += V_242 [ 1 ] -> V_222 ;
}
}
#endif
for ( V_129 = 0 ; V_129 < * V_296 ; V_129 ++ ) {
if ( V_242 [ V_129 ] -> V_221 != V_297 ) {
* V_253 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_250 *
F_182 ( struct V_54 * * V_242 , int V_296 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_34 * V_298 )
{
struct V_35 * V_35 = V_84 ( V_242 [ 0 ] ) ;
struct V_40 * V_101 [ V_245 ] ;
struct V_34 * V_37 ;
struct V_250 * V_251 ;
int V_191 ;
V_191 = F_152 ( V_242 , V_296 , V_4 , V_101 , V_28 ) ;
if ( V_191 <= 0 ) {
if ( V_191 != 0 && V_191 != - V_240 )
F_183 ( V_35 , V_299 ) ;
return F_15 ( V_191 ) ;
}
V_37 = F_167 ( V_242 [ 0 ] , V_101 , V_191 , V_4 , V_298 ) ;
if ( F_18 ( V_37 ) ) {
F_183 ( V_35 , V_300 ) ;
return F_135 ( V_37 ) ;
}
V_251 = (struct V_250 * ) V_37 ;
V_251 -> V_253 = V_191 ;
if ( V_296 > 1 )
V_191 = F_178 ( V_37 , & V_242 [ 1 ] -> V_123 ) ;
else
V_191 = F_179 ( V_37 , V_4 ) ;
if ( F_9 ( V_191 ) ) {
F_160 ( V_37 ) ;
F_183 ( V_35 , V_301 ) ;
return F_15 ( V_191 ) ;
}
V_251 -> V_296 = V_296 ;
memcpy ( V_251 -> V_242 , V_242 , sizeof( struct V_54 * ) * V_296 ) ;
V_251 -> V_302 = F_184 ( & V_242 [ 0 ] -> V_100 ) ;
return V_251 ;
}
static void V_92 ( unsigned long V_303 )
{
struct V_98 * V_99 ;
struct V_213 * V_214 ;
struct V_34 * V_37 ;
struct V_54 * V_81 = (struct V_54 * ) V_303 ;
struct V_177 * V_178 = & V_81 -> V_89 ;
struct V_3 V_4 ;
struct V_96 V_97 ;
F_185 ( & V_178 -> V_90 . V_61 ) ;
V_99 = F_186 ( & V_178 -> V_90 ) ;
if ( ! V_99 ) {
F_187 ( & V_178 -> V_90 . V_61 ) ;
goto V_64;
}
V_37 = F_188 ( V_99 ) ;
V_214 = V_99 -> V_214 ;
F_189 ( V_99 , & V_4 , V_37 -> V_93 -> V_28 ) ;
F_187 ( & V_178 -> V_90 . V_61 ) ;
F_157 ( V_37 -> V_262 ) ;
V_37 = F_190 ( V_84 ( V_81 ) , V_37 -> V_262 , & V_4 ,
V_214 , 0 ) ;
if ( F_18 ( V_37 ) )
goto V_304;
if ( V_37 -> V_46 & V_254 ) {
F_170 ( V_37 ) ;
if ( V_178 -> V_179 >= V_305 )
goto V_304;
V_178 -> V_179 = V_178 -> V_179 << 1 ;
if ( ! F_25 ( & V_178 -> V_91 , V_78 + V_178 -> V_179 ) )
F_26 ( V_81 ) ;
goto V_64;
}
F_170 ( V_37 ) ;
F_94 ( & V_97 ) ;
F_185 ( & V_178 -> V_90 . V_61 ) ;
V_178 -> V_179 = 0 ;
F_96 ( & V_178 -> V_90 , & V_97 ) ;
F_187 ( & V_178 -> V_90 . V_61 ) ;
while ( ! F_98 ( & V_97 ) ) {
V_99 = F_191 ( & V_97 ) ;
F_189 ( V_99 , & V_4 , F_188 ( V_99 ) -> V_93 -> V_28 ) ;
F_157 ( F_188 ( V_99 ) -> V_262 ) ;
V_37 = F_190 ( V_84 ( V_81 ) , F_188 ( V_99 ) -> V_262 ,
& V_4 , V_99 -> V_214 , 0 ) ;
if ( F_18 ( V_37 ) ) {
F_51 ( V_99 ) ;
continue;
}
F_192 ( V_99 ) ;
F_193 ( V_99 ) ;
F_194 ( V_99 , V_37 ) ;
F_195 ( V_99 ) ;
}
V_64:
F_28 ( V_81 ) ;
return;
V_304:
V_178 -> V_179 = 0 ;
F_49 ( & V_178 -> V_90 ) ;
F_28 ( V_81 ) ;
}
static int F_196 ( struct V_213 * V_214 , struct V_98 * V_99 )
{
unsigned long V_306 ;
struct V_34 * V_37 = F_188 ( V_99 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_37 ;
struct V_54 * V_81 = V_251 -> V_242 [ 0 ] ;
struct V_177 * V_178 = & V_81 -> V_89 ;
if ( F_9 ( F_197 ( V_214 , V_99 ) ) ) {
F_51 ( V_99 ) ;
return 0 ;
}
if ( V_178 -> V_90 . V_307 > V_308 ) {
F_51 ( V_99 ) ;
return - V_240 ;
}
F_198 ( V_99 ) ;
F_95 ( & V_178 -> V_90 . V_61 ) ;
if ( ! V_178 -> V_179 )
V_178 -> V_179 = V_180 ;
V_306 = V_78 + V_178 -> V_179 ;
if ( F_45 ( & V_178 -> V_91 ) ) {
if ( F_199 ( V_178 -> V_91 . V_309 , V_306 ) )
V_306 = V_178 -> V_91 . V_309 ;
F_28 ( V_81 ) ;
}
F_200 ( & V_178 -> V_90 , V_99 ) ;
if ( ! F_25 ( & V_178 -> V_91 , V_306 ) )
F_26 ( V_81 ) ;
F_97 ( & V_178 -> V_90 . V_61 ) ;
return 0 ;
}
static struct V_250 * F_201 ( struct V_35 * V_35 ,
struct V_310 * V_311 ,
const struct V_3 * V_4 ,
int V_253 ,
T_5 V_28 )
{
int V_191 ;
struct V_265 * V_266 ;
struct V_34 * V_37 ;
struct V_34 * V_275 ;
struct V_250 * V_251 ;
V_251 = F_161 ( V_35 , V_28 ) ;
if ( F_18 ( V_251 ) )
return V_251 ;
if ( ! ( V_311 -> V_46 & V_312 ) ||
V_35 -> V_101 . V_313 ||
V_253 <= 0 )
return V_251 ;
V_37 = V_311 -> V_298 ;
V_275 = & V_251 -> V_7 . V_37 ;
F_157 ( V_37 ) ;
V_251 -> V_252 = V_37 ;
F_174 ( V_275 , V_37 ) ;
V_275 -> V_281 = V_282 ;
V_275 -> V_46 |= V_283 | V_254 ;
V_275 -> V_284 = V_78 ;
V_275 -> V_285 = V_286 ;
V_275 -> V_287 = F_196 ;
F_157 ( V_37 ) ;
V_275 -> V_277 = V_37 ;
V_275 -> V_262 = V_37 ;
F_165 ( (struct V_250 * ) V_275 , V_37 , 0 ) ;
V_191 = - V_289 ;
V_266 = V_37 -> V_266 ;
if ( ! V_266 )
goto V_290;
V_191 = F_166 ( V_251 , V_266 , V_4 ) ;
if ( V_191 )
goto V_290;
V_64:
return V_251 ;
V_290:
F_170 ( V_275 ) ;
V_251 = F_15 ( V_191 ) ;
goto V_64;
}
static struct V_79 *
F_202 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 ,
struct V_79 * V_314 , void * V_189 )
{
struct V_310 * V_311 = (struct V_310 * ) V_189 ;
struct V_54 * V_242 [ V_199 ] ;
struct V_250 * V_251 , * V_315 ;
int V_296 = 0 , V_253 = 0 , V_129 , V_191 , V_316 ;
V_251 = NULL ;
if ( V_314 ) {
V_251 = F_31 ( V_314 , struct V_250 , V_80 ) ;
V_296 = V_251 -> V_296 ;
V_253 = V_251 -> V_253 ;
V_316 = 0 ;
for ( V_129 = 0 ; V_129 < V_296 ; V_129 ++ ) {
V_242 [ V_129 ] = V_251 -> V_242 [ V_129 ] ;
V_316 |= V_242 [ V_129 ] -> V_62 . V_63 ;
}
if ( V_316 ) {
F_160 ( & V_251 -> V_7 . V_37 ) ;
V_251 = NULL ;
V_296 = 0 ;
V_253 = 0 ;
V_314 = NULL ;
}
}
if ( V_251 == NULL ) {
V_296 = 1 ;
V_242 [ 0 ] = F_130 ( V_35 , V_4 , V_28 ,
F_132 ( V_60 ) ) ;
V_191 = F_180 ( V_4 , V_28 , V_242 ,
& V_296 , & V_253 ) ;
if ( V_191 < 0 )
goto V_317;
if ( V_296 == 0 )
return NULL ;
if ( V_253 <= 0 )
goto V_318;
}
V_315 = F_182 ( V_242 , V_296 , V_4 , V_28 ,
V_311 -> V_298 ) ;
if ( F_18 ( V_315 ) ) {
V_191 = F_169 ( V_315 ) ;
if ( V_191 != - V_240 )
goto error;
if ( V_314 == NULL )
goto V_318;
F_157 ( & V_251 -> V_7 . V_37 ) ;
return V_314 ;
} else if ( V_315 == NULL ) {
V_253 = 0 ;
if ( V_314 == NULL )
goto V_318;
V_251 -> V_253 = 0 ;
F_157 ( & V_251 -> V_7 . V_37 ) ;
return V_314 ;
}
if ( V_251 ) {
V_251 -> V_296 = 0 ;
F_160 ( & V_251 -> V_7 . V_37 ) ;
}
F_157 ( & V_315 -> V_7 . V_37 ) ;
return & V_315 -> V_80 ;
V_318:
V_251 = F_201 ( V_35 , V_311 , V_4 , V_253 , V_28 ) ;
if ( F_18 ( V_251 ) ) {
F_181 ( V_242 , V_296 ) ;
return F_135 ( V_251 ) ;
}
V_251 -> V_296 = V_296 ;
V_251 -> V_253 = V_253 ;
memcpy ( V_251 -> V_242 , V_242 , sizeof( struct V_54 * ) * V_296 ) ;
F_157 ( & V_251 -> V_7 . V_37 ) ;
return & V_251 -> V_80 ;
V_317:
F_183 ( V_35 , V_299 ) ;
error:
if ( V_251 != NULL )
F_160 ( & V_251 -> V_7 . V_37 ) ;
else
F_181 ( V_242 , V_296 ) ;
return F_15 ( V_191 ) ;
}
static struct V_34 * F_203 ( struct V_35 * V_35 , T_5 V_28 ,
struct V_34 * V_298 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_34 * V_192 ;
if ( ! V_32 ) {
F_170 ( V_298 ) ;
return F_15 ( - V_201 ) ;
} else {
V_192 = V_32 -> V_319 ( V_35 , V_298 ) ;
}
F_13 ( V_32 ) ;
return V_192 ;
}
struct V_34 * F_190 ( struct V_35 * V_35 , struct V_34 * V_298 ,
const struct V_3 * V_4 ,
struct V_213 * V_214 , int V_46 )
{
struct V_54 * V_242 [ V_199 ] ;
struct V_79 * V_80 ;
struct V_250 * V_251 ;
struct V_34 * V_37 , * V_252 ;
T_5 V_28 = V_298 -> V_93 -> V_28 ;
T_4 V_60 = F_136 ( V_143 ) ;
int V_129 , V_191 , V_296 , V_253 = 0 , V_320 = 0 ;
V_37 = NULL ;
V_251 = NULL ;
V_252 = NULL ;
if ( V_214 && V_214 -> V_215 [ V_143 ] ) {
V_296 = 1 ;
V_242 [ 0 ] = F_137 ( V_214 , V_143 , V_4 ) ;
V_191 = F_180 ( V_4 , V_28 , V_242 ,
& V_296 , & V_253 ) ;
if ( V_191 < 0 )
goto V_321;
if ( V_296 ) {
if ( V_253 <= 0 ) {
V_320 = V_296 ;
goto V_322;
}
V_251 = F_182 (
V_242 , V_296 , V_4 ,
V_28 , V_298 ) ;
if ( F_18 ( V_251 ) ) {
F_181 ( V_242 , V_296 ) ;
V_191 = F_169 ( V_251 ) ;
goto V_321;
} else if ( V_251 == NULL ) {
V_253 = 0 ;
V_320 = V_296 ;
goto V_322;
}
F_157 ( & V_251 -> V_7 . V_37 ) ;
V_251 -> V_7 . V_37 . V_46 |= V_323 ;
V_252 = V_251 -> V_252 ;
}
}
if ( V_251 == NULL ) {
struct V_310 V_311 ;
V_311 . V_298 = V_298 ;
V_311 . V_46 = V_46 ;
if ( ( V_298 -> V_46 & V_324 ) ||
! V_35 -> V_101 . V_136 [ V_143 ] )
goto V_325;
V_80 = F_204 ( V_35 , V_4 , V_28 , V_60 ,
F_202 , & V_311 ) ;
if ( V_80 == NULL )
goto V_325;
if ( F_18 ( V_80 ) ) {
V_191 = F_169 ( V_80 ) ;
goto V_321;
}
V_251 = F_31 ( V_80 , struct V_250 , V_80 ) ;
V_296 = V_251 -> V_296 ;
V_253 = V_251 -> V_253 ;
memcpy ( V_242 , V_251 -> V_242 , sizeof( struct V_54 * ) * V_296 ) ;
V_252 = V_251 -> V_252 ;
}
V_37 = & V_251 -> V_7 . V_37 ;
if ( V_252 == NULL && V_253 > 0 ) {
if ( V_35 -> V_101 . V_313 ) {
F_170 ( V_37 ) ;
F_181 ( V_242 , V_320 ) ;
F_183 ( V_35 , V_326 ) ;
return F_15 ( - V_327 ) ;
}
V_191 = - V_240 ;
F_183 ( V_35 , V_326 ) ;
goto error;
}
V_322:
if ( V_296 == 0 )
goto V_325;
if ( ( V_46 & V_328 ) &&
! ( V_242 [ 0 ] -> V_46 & V_329 ) ) {
V_191 = - V_193 ;
goto error;
}
for ( V_129 = 0 ; V_129 < V_296 ; V_129 ++ )
V_242 [ V_129 ] -> V_69 . V_73 = F_21 () ;
if ( V_253 < 0 ) {
F_183 ( V_35 , V_330 ) ;
V_191 = - V_331 ;
goto error;
} else if ( V_253 > 0 ) {
F_170 ( V_298 ) ;
} else {
F_170 ( V_37 ) ;
V_37 = V_298 ;
}
V_332:
F_181 ( V_242 , V_320 ) ;
if ( V_37 && V_37 -> V_101 &&
V_37 -> V_101 -> V_44 . V_232 == V_233 )
V_37 -> V_46 |= V_333 ;
return V_37 ;
V_325:
if ( ! ( V_46 & V_328 ) ) {
V_37 = V_298 ;
goto V_332;
}
V_191 = - V_193 ;
error:
F_170 ( V_37 ) ;
V_321:
F_170 ( V_298 ) ;
F_181 ( V_242 , V_320 ) ;
return F_15 ( V_191 ) ;
}
struct V_34 * F_205 ( struct V_35 * V_35 , struct V_34 * V_298 ,
const struct V_3 * V_4 ,
struct V_213 * V_214 , int V_46 )
{
struct V_34 * V_37 = F_190 ( V_35 , V_298 , V_4 , V_214 ,
V_46 | V_312 ) ;
if ( F_18 ( V_37 ) && F_169 ( V_37 ) == - V_327 )
return F_203 ( V_35 , V_298 -> V_93 -> V_28 , V_298 ) ;
return V_37 ;
}
static inline int
F_206 ( int V_168 , struct V_98 * V_99 , const struct V_3 * V_4 )
{
struct V_40 * V_41 ;
if ( ! V_99 -> V_334 || V_168 < 0 || V_168 >= V_99 -> V_334 -> V_174 )
return 0 ;
V_41 = V_99 -> V_334 -> V_335 [ V_168 ] ;
if ( ! V_41 -> type -> V_336 )
return 0 ;
return V_41 -> type -> V_336 ( V_41 , V_99 , V_4 ) ;
}
static inline int
F_207 ( const struct V_224 * V_231 , const struct V_40 * V_41 ,
unsigned short V_28 )
{
if ( F_208 ( V_41 ) )
return V_231 -> V_241 && ! F_209 ( V_231 , V_41 , V_231 -> V_235 ) ;
return V_41 -> V_45 . V_20 == V_231 -> V_45 . V_20 &&
( V_41 -> V_45 . V_337 == V_231 -> V_45 . V_337 || ! V_231 -> V_45 . V_337 ) &&
( V_41 -> V_44 . V_338 == V_231 -> V_338 || ! V_231 -> V_338 ) &&
V_41 -> V_44 . V_232 == V_231 -> V_232 &&
( V_231 -> V_339 || ( V_231 -> V_340 & ( 1 << V_41 -> V_44 . V_341 ) ) ||
! ( F_210 ( V_231 -> V_45 . V_20 , V_342 ) ) ) &&
! ( V_41 -> V_44 . V_232 != V_279 &&
F_209 ( V_231 , V_41 , V_28 ) ) ;
}
static inline int
F_211 ( const struct V_224 * V_231 , const struct V_343 * V_334 , int V_344 ,
unsigned short V_28 )
{
int V_168 = V_344 ;
if ( V_231 -> V_241 ) {
if ( V_231 -> V_232 == V_279 )
return V_344 ;
} else
V_344 = - 1 ;
for (; V_168 < V_334 -> V_174 ; V_168 ++ ) {
if ( F_207 ( V_231 , V_334 -> V_335 [ V_168 ] , V_28 ) )
return ++ V_168 ;
if ( V_334 -> V_335 [ V_168 ] -> V_44 . V_232 != V_279 ) {
if ( V_344 == - 1 )
V_344 = - 2 - V_168 ;
break;
}
}
return V_344 ;
}
int F_212 ( struct V_98 * V_99 , struct V_3 * V_4 ,
unsigned int V_28 , int V_345 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_191 ;
if ( F_9 ( V_32 == NULL ) )
return - V_38 ;
V_32 -> V_346 ( V_99 , V_4 , V_345 ) ;
V_191 = F_213 ( V_99 , & V_4 -> V_205 ) ;
F_13 ( V_32 ) ;
return V_191 ;
}
static inline int F_214 ( const struct V_343 * V_334 , int V_347 , int * V_348 )
{
for (; V_347 < V_334 -> V_174 ; V_347 ++ ) {
if ( V_334 -> V_335 [ V_347 ] -> V_44 . V_232 != V_279 ) {
* V_348 = V_347 ;
return 1 ;
}
}
return 0 ;
}
int F_215 ( struct V_213 * V_214 , int V_60 , struct V_98 * V_99 ,
unsigned short V_28 )
{
struct V_35 * V_35 = F_216 ( V_99 -> V_266 ) ;
struct V_54 * V_81 ;
struct V_54 * V_242 [ V_199 ] ;
int V_243 = 0 ;
int V_222 ;
int V_349 ;
int V_345 ;
struct V_3 V_4 ;
T_4 V_350 ;
int V_351 = - 1 ;
V_345 = V_60 & ~ V_164 ;
V_60 &= V_164 ;
V_350 = F_136 ( V_60 ) ;
if ( F_212 ( V_99 , & V_4 , V_28 , V_345 ) < 0 ) {
F_183 ( V_35 , V_352 ) ;
return 0 ;
}
F_217 ( V_99 , & V_4 , V_28 ) ;
if ( V_99 -> V_334 ) {
int V_129 ;
for ( V_129 = V_99 -> V_334 -> V_174 - 1 ; V_129 >= 0 ; V_129 -- ) {
struct V_40 * V_41 = V_99 -> V_334 -> V_335 [ V_129 ] ;
if ( ! F_7 ( & V_41 -> V_2 , & V_4 , V_28 ) ) {
F_183 ( V_35 , V_353 ) ;
return 0 ;
}
}
}
V_81 = NULL ;
if ( V_214 && V_214 -> V_215 [ V_60 ] ) {
V_81 = F_137 ( V_214 , V_60 , & V_4 ) ;
if ( F_18 ( V_81 ) ) {
F_183 ( V_35 , V_354 ) ;
return 0 ;
}
}
if ( ! V_81 ) {
struct V_79 * V_80 ;
V_80 = F_204 ( V_35 , & V_4 , V_28 , V_350 ,
F_133 , NULL ) ;
if ( F_134 ( V_80 ) )
V_81 = F_135 ( V_80 ) ;
else
V_81 = F_31 ( V_80 , struct V_54 , V_80 ) ;
}
if ( F_18 ( V_81 ) ) {
F_183 ( V_35 , V_354 ) ;
return 0 ;
}
if ( ! V_81 ) {
if ( V_99 -> V_334 && F_214 ( V_99 -> V_334 , 0 , & V_351 ) ) {
F_206 ( V_351 , V_99 , & V_4 ) ;
F_183 ( V_35 , V_355 ) ;
return 0 ;
}
return 1 ;
}
V_81 -> V_69 . V_73 = F_21 () ;
V_242 [ 0 ] = V_81 ;
V_243 ++ ;
#ifdef F_131
if ( V_242 [ 0 ] -> type != V_208 ) {
V_242 [ 1 ] = F_127 ( V_35 , V_208 ,
& V_4 , V_28 ,
V_141 ) ;
if ( V_242 [ 1 ] ) {
if ( F_18 ( V_242 [ 1 ] ) ) {
F_183 ( V_35 , V_354 ) ;
return 0 ;
}
V_242 [ 1 ] -> V_69 . V_73 = F_21 () ;
V_243 ++ ;
}
}
#endif
if ( V_81 -> V_221 == V_297 ) {
struct V_343 * V_334 ;
static struct V_343 V_356 ;
struct V_224 * V_244 [ V_245 ] ;
struct V_224 * V_357 [ V_245 ] ;
struct V_224 * * V_246 = V_244 ;
int V_358 = 0 ;
int V_129 , V_347 ;
if ( ( V_334 = V_99 -> V_334 ) == NULL )
V_334 = & V_356 ;
for ( V_349 = 0 ; V_349 < V_243 ; V_349 ++ ) {
if ( V_242 [ V_349 ] != V_81 &&
V_242 [ V_349 ] -> V_221 != V_297 ) {
F_183 ( V_35 , V_359 ) ;
goto V_336;
}
if ( V_358 + V_242 [ V_349 ] -> V_222 >= V_245 ) {
F_183 ( V_35 , V_360 ) ;
goto V_361;
}
for ( V_129 = 0 ; V_129 < V_242 [ V_349 ] -> V_222 ; V_129 ++ )
V_246 [ V_358 ++ ] = & V_242 [ V_349 ] -> V_223 [ V_129 ] ;
}
V_222 = V_358 ;
if ( V_243 > 1 ) {
F_218 ( V_357 , V_246 , V_222 , V_28 , V_35 ) ;
V_246 = V_357 ;
}
for ( V_129 = V_222 - 1 , V_347 = 0 ; V_129 >= 0 ; V_129 -- ) {
V_347 = F_211 ( V_246 [ V_129 ] , V_334 , V_347 , V_28 ) ;
if ( V_347 < 0 ) {
if ( V_347 < - 1 )
V_351 = - ( 2 + V_347 ) ;
F_183 ( V_35 , V_362 ) ;
goto V_336;
}
}
if ( F_214 ( V_334 , V_347 , & V_351 ) ) {
F_183 ( V_35 , V_362 ) ;
goto V_336;
}
F_181 ( V_242 , V_243 ) ;
return 1 ;
}
F_183 ( V_35 , V_359 ) ;
V_336:
F_206 ( V_351 , V_99 , & V_4 ) ;
V_361:
F_181 ( V_242 , V_243 ) ;
return 0 ;
}
int F_219 ( struct V_98 * V_99 , unsigned short V_28 )
{
struct V_35 * V_35 = F_216 ( V_99 -> V_266 ) ;
struct V_3 V_4 ;
struct V_34 * V_37 ;
int V_363 = 1 ;
if ( F_189 ( V_99 , & V_4 , V_28 ) < 0 ) {
F_183 ( V_35 , V_364 ) ;
return 0 ;
}
F_198 ( V_99 ) ;
V_37 = F_190 ( V_35 , F_188 ( V_99 ) , & V_4 , NULL , V_312 ) ;
if ( F_18 ( V_37 ) ) {
V_363 = 0 ;
V_37 = NULL ;
}
F_194 ( V_99 , V_37 ) ;
return V_363 ;
}
static struct V_34 * F_220 ( struct V_34 * V_37 , T_3 V_365 )
{
if ( V_37 -> V_281 < 0 && ! F_156 ( V_37 ) )
return V_37 ;
return NULL ;
}
static int F_156 ( struct V_34 * V_37 )
{
return ! F_221 ( (struct V_250 * ) V_37 ) ;
}
void F_222 ( struct V_34 * V_37 , struct V_265 * V_266 )
{
while ( ( V_37 = V_37 -> V_277 ) && V_37 -> V_101 && V_37 -> V_266 == V_266 ) {
V_37 -> V_266 = F_216 ( V_266 ) -> V_366 ;
F_223 ( V_37 -> V_266 ) ;
F_224 ( V_266 ) ;
}
}
static void F_225 ( struct V_98 * V_99 )
{
}
static struct V_34 * F_226 ( struct V_34 * V_37 )
{
if ( V_37 ) {
if ( V_37 -> V_281 ) {
F_170 ( V_37 ) ;
V_37 = NULL ;
}
}
return V_37 ;
}
void F_227 ( struct V_35 * V_35 )
{
F_228 ( V_35 ) ;
}
static void F_229 ( struct V_35 * V_35 )
{
F_230 ( V_35 ) ;
}
static void F_175 ( struct V_34 * V_37 )
{
do {
struct V_250 * V_251 = (struct V_250 * ) V_37 ;
T_3 V_367 , V_368 ;
V_367 = F_231 ( V_37 -> V_277 ) ;
V_251 -> V_369 = V_367 ;
V_367 = F_232 ( V_37 -> V_101 , V_367 ) ;
V_368 = F_231 ( V_251 -> V_252 ) ;
V_251 -> V_368 = V_368 ;
if ( V_367 > V_368 )
V_367 = V_368 ;
F_233 ( V_37 , V_370 , V_367 ) ;
} while ( ( V_37 = V_37 -> V_57 ) );
}
static int F_221 ( struct V_250 * V_371 )
{
struct V_34 * V_37 = & V_371 -> V_7 . V_37 ;
struct V_250 * V_372 ;
T_3 V_373 ;
if ( ! F_234 ( V_37 -> V_262 , ( (struct V_250 * ) V_37 ) -> V_374 ) ||
( V_37 -> V_266 && ! F_235 ( V_37 -> V_266 ) ) )
return 0 ;
if ( V_37 -> V_46 & V_254 )
return 1 ;
V_372 = NULL ;
do {
struct V_250 * V_251 = (struct V_250 * ) V_37 ;
if ( V_37 -> V_101 -> V_236 . V_237 != V_238 )
return 0 ;
if ( V_251 -> V_280 != V_37 -> V_101 -> V_100 )
return 0 ;
if ( V_251 -> V_296 > 0 &&
V_251 -> V_302 != F_184 ( & V_251 -> V_242 [ 0 ] -> V_100 ) )
return 0 ;
V_373 = F_231 ( V_37 -> V_277 ) ;
if ( V_251 -> V_369 != V_373 ) {
V_372 = V_251 ;
V_251 -> V_369 = V_373 ;
}
if ( ! F_234 ( V_251 -> V_252 , V_251 -> V_375 ) )
return 0 ;
V_373 = F_231 ( V_251 -> V_252 ) ;
if ( V_251 -> V_368 != V_373 ) {
V_372 = V_251 ;
V_251 -> V_368 = V_373 ;
}
V_37 = V_37 -> V_277 ;
} while ( V_37 -> V_101 );
if ( F_164 ( ! V_372 ) )
return 1 ;
V_373 = V_372 -> V_369 ;
for (; ; ) {
V_37 = & V_372 -> V_7 . V_37 ;
V_373 = F_232 ( V_37 -> V_101 , V_373 ) ;
if ( V_373 > V_372 -> V_368 )
V_373 = V_372 -> V_368 ;
F_233 ( V_37 , V_370 , V_373 ) ;
if ( V_372 == V_371 )
break;
V_372 = (struct V_250 * ) V_372 -> V_7 . V_37 . V_57 ;
V_372 -> V_369 = V_373 ;
}
return 1 ;
}
static unsigned int F_236 ( const struct V_34 * V_37 )
{
return F_237 ( V_37 -> V_262 ) ;
}
static unsigned int F_238 ( const struct V_34 * V_37 )
{
unsigned int V_373 = F_239 ( V_37 , V_370 ) ;
return V_373 ? : F_231 ( V_37 -> V_262 ) ;
}
static struct V_376 * F_240 ( const struct V_34 * V_37 ,
struct V_98 * V_99 ,
const void * V_9 )
{
return V_37 -> V_262 -> V_93 -> V_377 ( V_37 , V_99 , V_9 ) ;
}
int F_241 ( struct V_31 * V_32 )
{
struct V_35 * V_35 ;
int V_191 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_201 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_185 ( & V_378 ) ;
if ( F_9 ( V_31 [ V_32 -> V_28 ] != NULL ) )
V_191 = - V_248 ;
else {
struct V_255 * V_255 = V_32 -> V_255 ;
if ( F_164 ( V_255 -> V_379 == NULL ) )
V_255 -> V_379 = V_380 ;
if ( F_164 ( V_255 -> V_381 == NULL ) )
V_255 -> V_381 = F_220 ;
if ( F_164 ( V_255 -> V_382 == NULL ) )
V_255 -> V_382 = F_236 ;
if ( F_164 ( V_255 -> V_373 == NULL ) )
V_255 -> V_373 = F_238 ;
if ( F_164 ( V_255 -> V_383 == NULL ) )
V_255 -> V_383 = F_226 ;
if ( F_164 ( V_255 -> V_384 == NULL ) )
V_255 -> V_384 = F_225 ;
if ( F_164 ( V_255 -> V_377 == NULL ) )
V_255 -> V_377 = F_240 ;
if ( F_164 ( V_32 -> V_385 == NULL ) )
V_32 -> V_385 = F_229 ;
F_242 ( V_31 [ V_32 -> V_28 ] , V_32 ) ;
}
F_187 ( & V_378 ) ;
F_243 () ;
F_244 (net) {
struct V_255 * V_386 ;
switch ( V_32 -> V_28 ) {
case V_29 :
V_386 = & V_35 -> V_101 . V_256 ;
break;
#if F_162 ( V_257 )
case V_30 :
V_386 = & V_35 -> V_101 . V_258 ;
break;
#endif
default:
F_46 () ;
}
* V_386 = * V_32 -> V_255 ;
}
F_245 () ;
return V_191 ;
}
int F_246 ( struct V_31 * V_32 )
{
int V_191 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_201 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_185 ( & V_378 ) ;
if ( F_164 ( V_31 [ V_32 -> V_28 ] != NULL ) ) {
if ( F_9 ( V_31 [ V_32 -> V_28 ] != V_32 ) )
V_191 = - V_201 ;
else
F_247 ( V_31 [ V_32 -> V_28 ] ,
NULL ) ;
}
F_187 ( & V_378 ) ;
if ( ! V_191 ) {
struct V_255 * V_255 = V_32 -> V_255 ;
F_248 () ;
V_255 -> V_379 = NULL ;
V_255 -> V_381 = NULL ;
V_255 -> V_383 = NULL ;
V_255 -> V_384 = NULL ;
V_32 -> V_385 = NULL ;
}
return V_191 ;
}
static void T_6 F_249 ( struct V_35 * V_35 )
{
struct V_31 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_31 [ V_29 ] ) ;
if ( V_32 )
V_35 -> V_101 . V_256 = * V_32 -> V_255 ;
#if F_162 ( V_257 )
V_32 = F_11 ( V_31 [ V_30 ] ) ;
if ( V_32 )
V_35 -> V_101 . V_258 = * V_32 -> V_255 ;
#endif
F_12 () ;
}
static int F_250 ( struct V_387 * V_388 , unsigned long V_389 , void * V_390 )
{
struct V_265 * V_266 = F_251 ( V_390 ) ;
switch ( V_389 ) {
case V_391 :
F_227 ( F_216 ( V_266 ) ) ;
}
return V_392 ;
}
static int T_6 F_252 ( struct V_35 * V_35 )
{
int V_393 ;
V_35 -> V_394 . V_395 = F_253 ( struct V_396 ) ;
if ( ! V_35 -> V_394 . V_395 )
return - V_226 ;
V_393 = F_254 ( V_35 ) ;
if ( V_393 < 0 )
F_255 ( V_35 -> V_394 . V_395 ) ;
return V_393 ;
}
static void F_256 ( struct V_35 * V_35 )
{
F_257 ( V_35 ) ;
F_255 ( V_35 -> V_394 . V_395 ) ;
}
static int T_6 F_252 ( struct V_35 * V_35 )
{
return 0 ;
}
static void F_256 ( struct V_35 * V_35 )
{
}
static int T_6 F_258 ( struct V_35 * V_35 )
{
unsigned int V_111 , V_397 ;
int V_60 ;
if ( F_259 ( V_35 , & V_398 ) )
V_380 = F_260 ( L_1 ,
sizeof( struct V_250 ) ,
0 , V_399 | V_400 ,
NULL ) ;
V_111 = 8 - 1 ;
V_397 = ( V_111 + 1 ) * sizeof( struct V_110 ) ;
V_35 -> V_101 . V_133 = F_70 ( V_397 ) ;
if ( ! V_35 -> V_101 . V_133 )
goto V_401;
V_35 -> V_101 . V_102 = V_111 ;
for ( V_60 = 0 ; V_60 < V_147 ; V_60 ++ ) {
struct V_402 * V_403 ;
V_35 -> V_101 . V_136 [ V_60 ] = 0 ;
V_35 -> V_101 . V_136 [ V_147 + V_60 ] = 0 ;
F_86 ( & V_35 -> V_101 . V_113 [ V_60 ] ) ;
V_403 = & V_35 -> V_101 . V_105 [ V_60 ] ;
V_403 -> V_114 = F_70 ( V_397 ) ;
if ( ! V_403 -> V_114 )
goto V_404;
V_403 -> V_111 = V_111 ;
V_403 -> V_106 = 32 ;
V_403 -> V_107 = 32 ;
V_403 -> V_108 = 128 ;
V_403 -> V_109 = 128 ;
}
V_35 -> V_101 . V_156 . V_160 = 32 ;
V_35 -> V_101 . V_156 . V_161 = 32 ;
V_35 -> V_101 . V_156 . V_162 = 128 ;
V_35 -> V_101 . V_156 . V_163 = 128 ;
F_261 ( & V_35 -> V_101 . V_156 . V_61 ) ;
F_37 ( & V_35 -> V_101 . V_202 ) ;
F_262 ( & V_35 -> V_101 . V_154 , F_80 ) ;
F_262 ( & V_35 -> V_101 . V_156 . V_153 , F_83 ) ;
if ( F_259 ( V_35 , & V_398 ) )
F_263 ( & V_405 ) ;
return 0 ;
V_404:
for ( V_60 -- ; V_60 >= 0 ; V_60 -- ) {
struct V_402 * V_403 ;
V_403 = & V_35 -> V_101 . V_105 [ V_60 ] ;
F_73 ( V_403 -> V_114 , V_397 ) ;
}
F_73 ( V_35 -> V_101 . V_133 , V_397 ) ;
V_401:
return - V_226 ;
}
static void F_264 ( struct V_35 * V_35 )
{
unsigned int V_397 ;
int V_60 ;
F_265 ( & V_35 -> V_101 . V_154 ) ;
#ifdef F_131
F_113 ( V_35 , V_207 , false ) ;
#endif
F_113 ( V_35 , V_208 , false ) ;
F_103 ( ! F_116 ( & V_35 -> V_101 . V_202 ) ) ;
for ( V_60 = 0 ; V_60 < V_147 ; V_60 ++ ) {
struct V_402 * V_403 ;
F_103 ( ! F_66 ( & V_35 -> V_101 . V_113 [ V_60 ] ) ) ;
V_403 = & V_35 -> V_101 . V_105 [ V_60 ] ;
V_397 = ( V_403 -> V_111 + 1 ) * sizeof( struct V_110 ) ;
F_103 ( ! F_66 ( V_403 -> V_114 ) ) ;
F_73 ( V_403 -> V_114 , V_397 ) ;
}
V_397 = ( V_35 -> V_101 . V_102 + 1 ) * sizeof( struct V_110 ) ;
F_103 ( ! F_66 ( V_35 -> V_101 . V_133 ) ) ;
F_73 ( V_35 -> V_101 . V_133 , V_397 ) ;
}
static int T_6 F_266 ( struct V_35 * V_35 )
{
int V_393 ;
V_393 = F_252 ( V_35 ) ;
if ( V_393 < 0 )
goto V_406;
V_393 = F_267 ( V_35 ) ;
if ( V_393 < 0 )
goto V_407;
V_393 = F_258 ( V_35 ) ;
if ( V_393 < 0 )
goto V_408;
F_249 ( V_35 ) ;
V_393 = F_268 ( V_35 ) ;
if ( V_393 < 0 )
goto V_409;
V_393 = F_269 ( V_35 ) ;
if ( V_393 < 0 )
goto V_64;
F_270 ( & V_35 -> V_101 . V_410 ) ;
F_39 ( & V_35 -> V_101 . V_130 ) ;
F_271 ( & V_35 -> V_101 . V_411 ) ;
return 0 ;
V_64:
F_272 ( V_35 ) ;
V_409:
F_264 ( V_35 ) ;
V_408:
F_273 ( V_35 ) ;
V_407:
F_256 ( V_35 ) ;
V_406:
return V_393 ;
}
static void T_7 F_274 ( struct V_35 * V_35 )
{
F_275 ( V_35 ) ;
F_272 ( V_35 ) ;
F_264 ( V_35 ) ;
F_273 ( V_35 ) ;
F_256 ( V_35 ) ;
}
void T_8 F_276 ( void )
{
F_277 ( & V_412 ) ;
F_278 () ;
}
static void F_279 ( struct V_54 * V_55 ,
struct V_413 * V_414 )
{
struct V_188 * V_189 = V_55 -> V_95 ;
struct V_1 * V_2 = & V_55 -> V_123 ;
if ( V_189 )
F_280 ( V_414 , L_2 ,
V_189 -> V_415 , V_189 -> V_416 , V_189 -> V_417 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_280 ( V_414 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_280 ( V_414 , L_4 ,
V_2 -> V_13 ) ;
F_280 ( V_414 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_280 ( V_414 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_280 ( V_414 , L_7 , V_2 -> V_12 . V_418 ) ;
if ( V_2 -> V_13 != 128 )
F_280 ( V_414 , L_4 ,
V_2 -> V_13 ) ;
F_280 ( V_414 , L_8 , V_2 -> V_9 . V_418 ) ;
if ( V_2 -> V_11 != 128 )
F_280 ( V_414 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_281 ( struct V_54 * V_55 , int V_419 , bool V_194 )
{
struct V_413 * V_414 ;
V_414 = F_282 ( L_9 ) ;
if ( V_414 == NULL )
return;
F_283 ( V_194 , V_414 ) ;
F_280 ( V_414 , L_10 , V_419 ) ;
F_279 ( V_55 , V_414 ) ;
F_284 ( V_414 ) ;
}
void F_112 ( struct V_54 * V_55 , int V_419 ,
bool V_194 )
{
struct V_413 * V_414 ;
V_414 = F_282 ( L_11 ) ;
if ( V_414 == NULL )
return;
F_283 ( V_194 , V_414 ) ;
F_280 ( V_414 , L_10 , V_419 ) ;
F_279 ( V_55 , V_414 ) ;
F_284 ( V_414 ) ;
}
static bool F_285 ( const struct V_1 * V_420 ,
const struct V_1 * V_421 )
{
if ( V_420 -> V_20 == V_422 ) {
if ( V_421 -> V_28 == V_420 -> V_28 &&
F_286 ( & V_421 -> V_9 , & V_420 -> V_9 ,
V_420 -> V_28 ) &&
F_286 ( & V_421 -> V_12 , & V_420 -> V_12 ,
V_420 -> V_28 ) &&
V_421 -> V_11 == V_420 -> V_11 &&
V_421 -> V_13 == V_420 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_421 , V_420 , sizeof( * V_421 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_54 * F_287 ( const struct V_1 * V_2 ,
T_4 V_60 , T_4 type , struct V_35 * V_35 )
{
struct V_54 * V_81 , * V_192 = NULL ;
struct V_110 * V_157 ;
T_3 V_165 = ~ 0U ;
F_78 ( & V_35 -> V_101 . V_130 ) ;
V_157 = F_59 ( V_35 , & V_2 -> V_9 , & V_2 -> V_12 , V_2 -> V_28 , V_60 ) ;
F_88 (pol, chain, bydst) {
if ( F_285 ( V_2 , & V_81 -> V_123 ) &&
V_81 -> type == type ) {
V_192 = V_81 ;
V_165 = V_192 -> V_165 ;
break;
}
}
V_157 = & V_35 -> V_101 . V_113 [ V_60 ] ;
F_88 (pol, chain, bydst) {
if ( F_285 ( V_2 , & V_81 -> V_123 ) &&
V_81 -> type == type &&
V_81 -> V_165 < V_165 ) {
V_192 = V_81 ;
break;
}
}
if ( V_192 )
F_26 ( V_192 ) ;
F_79 ( & V_35 -> V_101 . V_130 ) ;
return V_192 ;
}
static int F_288 ( const struct V_423 * V_183 , const struct V_224 * V_424 )
{
int V_203 = 0 ;
if ( V_424 -> V_232 == V_183 -> V_232 && V_424 -> V_45 . V_20 == V_183 -> V_20 &&
( V_183 -> V_338 == 0 || V_424 -> V_338 == V_183 -> V_338 ) ) {
switch ( V_424 -> V_232 ) {
case V_233 :
case V_234 :
if ( F_286 ( & V_424 -> V_45 . V_9 , & V_183 -> V_425 ,
V_183 -> V_426 ) &&
F_286 ( & V_424 -> V_12 , & V_183 -> V_427 ,
V_183 -> V_426 ) ) {
V_203 = 1 ;
}
break;
case V_279 :
V_203 = 1 ;
break;
default:
break;
}
}
return V_203 ;
}
static int F_289 ( struct V_54 * V_81 ,
struct V_423 * V_183 , int V_428 )
{
struct V_423 * V_429 ;
int V_129 , V_430 , V_431 = 0 ;
F_71 ( & V_81 -> V_61 ) ;
if ( F_9 ( V_81 -> V_62 . V_63 ) ) {
F_72 ( & V_81 -> V_61 ) ;
return - V_193 ;
}
for ( V_129 = 0 ; V_129 < V_81 -> V_222 ; V_129 ++ ) {
for ( V_430 = 0 , V_429 = V_183 ; V_430 < V_428 ; V_430 ++ , V_429 ++ ) {
if ( ! F_288 ( V_429 , & V_81 -> V_223 [ V_129 ] ) )
continue;
V_431 ++ ;
if ( V_81 -> V_223 [ V_129 ] . V_232 != V_233 &&
V_81 -> V_223 [ V_129 ] . V_232 != V_234 )
continue;
memcpy ( & V_81 -> V_223 [ V_129 ] . V_45 . V_9 , & V_429 -> V_432 ,
sizeof( V_81 -> V_223 [ V_129 ] . V_45 . V_9 ) ) ;
memcpy ( & V_81 -> V_223 [ V_129 ] . V_12 , & V_429 -> V_433 ,
sizeof( V_81 -> V_223 [ V_129 ] . V_12 ) ) ;
V_81 -> V_223 [ V_129 ] . V_235 = V_429 -> V_434 ;
F_53 ( & V_81 -> V_100 ) ;
}
}
F_72 ( & V_81 -> V_61 ) ;
if ( ! V_431 )
return - V_435 ;
return 0 ;
}
static int F_290 ( const struct V_423 * V_183 , int V_428 )
{
int V_129 , V_430 ;
if ( V_428 < 1 || V_428 > V_245 )
return - V_201 ;
for ( V_129 = 0 ; V_129 < V_428 ; V_129 ++ ) {
if ( F_286 ( & V_183 [ V_129 ] . V_425 , & V_183 [ V_129 ] . V_432 ,
V_183 [ V_129 ] . V_426 ) &&
F_286 ( & V_183 [ V_129 ] . V_427 , & V_183 [ V_129 ] . V_433 ,
V_183 [ V_129 ] . V_426 ) )
return - V_201 ;
if ( F_149 ( & V_183 [ V_129 ] . V_432 , V_183 [ V_129 ] . V_434 ) ||
F_149 ( & V_183 [ V_129 ] . V_433 , V_183 [ V_129 ] . V_434 ) )
return - V_201 ;
for ( V_430 = V_129 + 1 ; V_430 < V_428 ; V_430 ++ ) {
if ( ! memcmp ( & V_183 [ V_129 ] . V_425 , & V_183 [ V_430 ] . V_425 ,
sizeof( V_183 [ V_129 ] . V_425 ) ) &&
! memcmp ( & V_183 [ V_129 ] . V_427 , & V_183 [ V_430 ] . V_427 ,
sizeof( V_183 [ V_129 ] . V_427 ) ) &&
V_183 [ V_129 ] . V_20 == V_183 [ V_430 ] . V_20 &&
V_183 [ V_129 ] . V_232 == V_183 [ V_430 ] . V_232 &&
V_183 [ V_129 ] . V_338 == V_183 [ V_430 ] . V_338 &&
V_183 [ V_129 ] . V_426 == V_183 [ V_430 ] . V_426 )
return - V_201 ;
}
}
return 0 ;
}
int V_423 ( const struct V_1 * V_2 , T_4 V_60 , T_4 type ,
struct V_423 * V_183 , int V_428 ,
struct V_436 * V_347 , struct V_35 * V_35 )
{
int V_129 , V_191 , V_437 = 0 , V_438 = 0 ;
struct V_54 * V_81 = NULL ;
struct V_40 * V_41 , * V_439 ;
struct V_40 * V_440 [ V_245 ] ;
struct V_40 * V_441 [ V_245 ] ;
struct V_423 * V_429 ;
if ( ( V_191 = F_290 ( V_183 , V_428 ) ) < 0 )
goto V_64;
if ( ( V_81 = F_287 ( V_2 , V_60 , type , V_35 ) ) == NULL ) {
V_191 = - V_193 ;
goto V_64;
}
for ( V_129 = 0 , V_429 = V_183 ; V_129 < V_428 ; V_129 ++ , V_429 ++ ) {
if ( ( V_41 = F_291 ( V_429 , V_35 ) ) ) {
V_440 [ V_437 ] = V_41 ;
V_437 ++ ;
if ( ( V_439 = F_292 ( V_41 , V_429 ) ) ) {
V_441 [ V_438 ] = V_439 ;
V_438 ++ ;
} else {
V_191 = - V_435 ;
goto V_442;
}
}
}
if ( ( V_191 = F_289 ( V_81 , V_183 , V_428 ) ) < 0 )
goto V_442;
if ( V_437 ) {
F_293 ( V_440 , V_437 ) ;
F_294 ( V_440 , V_437 ) ;
}
F_295 ( V_2 , V_60 , type , V_183 , V_428 , V_347 ) ;
F_28 ( V_81 ) ;
return 0 ;
V_64:
return V_191 ;
V_442:
if ( V_81 )
F_28 ( V_81 ) ;
if ( V_437 )
F_293 ( V_440 , V_437 ) ;
if ( V_438 )
F_294 ( V_441 , V_438 ) ;
return V_191 ;
}
