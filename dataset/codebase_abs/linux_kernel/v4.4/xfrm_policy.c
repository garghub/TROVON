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
static inline struct V_34 * F_14 ( struct V_35 * V_35 ,
int V_36 , int V_37 ,
const T_1 * V_12 ,
const T_1 * V_9 ,
int V_28 )
{
struct V_31 * V_32 ;
struct V_34 * V_38 ;
V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return F_15 ( - V_39 ) ;
V_38 = V_32 -> V_40 ( V_35 , V_36 , V_37 , V_12 , V_9 ) ;
F_13 ( V_32 ) ;
return V_38 ;
}
static inline struct V_34 * F_16 ( struct V_41 * V_42 ,
int V_36 , int V_37 ,
T_1 * V_43 ,
T_1 * V_44 ,
int V_28 )
{
struct V_35 * V_35 = F_17 ( V_42 ) ;
T_1 * V_12 = & V_42 -> V_45 . V_12 ;
T_1 * V_9 = & V_42 -> V_46 . V_9 ;
struct V_34 * V_38 ;
if ( V_42 -> type -> V_47 & V_48 ) {
V_12 = V_42 -> V_49 ;
V_9 = V_44 ;
}
if ( V_42 -> type -> V_47 & V_50 ) {
V_12 = V_43 ;
V_9 = V_42 -> V_49 ;
}
V_38 = F_14 ( V_35 , V_36 , V_37 , V_12 , V_9 , V_28 ) ;
if ( ! F_18 ( V_38 ) ) {
if ( V_43 != V_12 )
memcpy ( V_43 , V_12 , sizeof( * V_43 ) ) ;
if ( V_44 != V_9 )
memcpy ( V_44 , V_9 , sizeof( * V_44 ) ) ;
}
return V_38 ;
}
static inline unsigned long F_19 ( long V_51 )
{
if ( V_51 >= ( V_52 - 1 ) / V_53 )
return V_52 - 1 ;
else
return V_51 * V_53 ;
}
static void F_20 ( unsigned long V_54 )
{
struct V_55 * V_56 = (struct V_55 * ) V_54 ;
unsigned long V_57 = F_21 () ;
long V_58 = V_59 ;
int V_60 = 0 ;
int V_61 ;
F_22 ( & V_56 -> V_62 ) ;
if ( F_9 ( V_56 -> V_63 . V_64 ) )
goto V_65;
V_61 = F_23 ( V_56 -> V_66 ) ;
if ( V_56 -> V_67 . V_68 ) {
long V_69 = V_56 -> V_67 . V_68 +
V_56 -> V_70 . V_71 - V_57 ;
if ( V_69 <= 0 )
goto V_72;
if ( V_69 < V_58 )
V_58 = V_69 ;
}
if ( V_56 -> V_67 . V_73 ) {
long V_69 = V_56 -> V_67 . V_73 +
( V_56 -> V_70 . V_74 ? : V_56 -> V_70 . V_71 ) - V_57 ;
if ( V_69 <= 0 )
goto V_72;
if ( V_69 < V_58 )
V_58 = V_69 ;
}
if ( V_56 -> V_67 . V_75 ) {
long V_69 = V_56 -> V_67 . V_75 +
V_56 -> V_70 . V_71 - V_57 ;
if ( V_69 <= 0 ) {
V_60 = 1 ;
V_69 = V_76 ;
}
if ( V_69 < V_58 )
V_58 = V_69 ;
}
if ( V_56 -> V_67 . V_77 ) {
long V_69 = V_56 -> V_67 . V_77 +
( V_56 -> V_70 . V_74 ? : V_56 -> V_70 . V_71 ) - V_57 ;
if ( V_69 <= 0 ) {
V_60 = 1 ;
V_69 = V_76 ;
}
if ( V_69 < V_58 )
V_58 = V_69 ;
}
if ( V_60 )
F_24 ( V_56 , V_61 , 0 , 0 ) ;
if ( V_58 != V_59 &&
! F_25 ( & V_56 -> V_78 , V_79 + F_19 ( V_58 ) ) )
F_26 ( V_56 ) ;
V_65:
F_27 ( & V_56 -> V_62 ) ;
F_28 ( V_56 ) ;
return;
V_72:
F_27 ( & V_56 -> V_62 ) ;
if ( ! F_29 ( V_56 , V_61 ) )
F_24 ( V_56 , V_61 , 1 , 0 ) ;
F_28 ( V_56 ) ;
}
static struct V_80 * F_30 ( struct V_80 * V_81 )
{
struct V_55 * V_82 = F_31 ( V_81 , struct V_55 , V_81 ) ;
if ( F_9 ( V_82 -> V_63 . V_64 ) )
V_81 = NULL ;
else
F_26 ( V_82 ) ;
return V_81 ;
}
static int F_32 ( struct V_80 * V_81 )
{
struct V_55 * V_82 = F_31 ( V_81 , struct V_55 , V_81 ) ;
return ! V_82 -> V_63 . V_64 ;
}
static void F_33 ( struct V_80 * V_81 )
{
F_28 ( F_31 ( V_81 , struct V_55 , V_81 ) ) ;
}
struct V_55 * F_34 ( struct V_35 * V_35 , T_2 V_83 )
{
struct V_55 * V_84 ;
V_84 = F_35 ( sizeof( struct V_55 ) , V_83 ) ;
if ( V_84 ) {
F_36 ( & V_84 -> V_85 , V_35 ) ;
F_37 ( & V_84 -> V_63 . V_86 ) ;
F_38 ( & V_84 -> V_87 ) ;
F_38 ( & V_84 -> V_88 ) ;
F_39 ( & V_84 -> V_62 ) ;
F_40 ( & V_84 -> V_89 , 1 ) ;
F_41 ( & V_84 -> V_90 . V_91 ) ;
F_42 ( & V_84 -> V_78 , F_20 ,
( unsigned long ) V_84 ) ;
F_42 ( & V_84 -> V_90 . V_92 , V_93 ,
( unsigned long ) V_84 ) ;
V_84 -> V_81 . V_94 = & V_95 ;
}
return V_84 ;
}
static void F_43 ( struct V_96 * V_97 )
{
struct V_55 * V_84 = F_31 ( V_97 , struct V_55 , V_98 ) ;
F_44 ( V_84 -> V_99 ) ;
F_45 ( V_84 ) ;
}
void F_46 ( struct V_55 * V_84 )
{
F_47 ( ! V_84 -> V_63 . V_64 ) ;
if ( F_48 ( & V_84 -> V_78 ) || F_48 ( & V_84 -> V_90 . V_92 ) )
F_49 () ;
F_50 ( & V_84 -> V_98 , F_43 ) ;
}
static void F_51 ( struct V_55 * V_84 )
{
V_84 -> V_63 . V_64 = 1 ;
F_52 ( & V_84 -> V_100 ) ;
if ( F_48 ( & V_84 -> V_90 . V_92 ) )
F_28 ( V_84 ) ;
F_53 ( & V_84 -> V_90 . V_91 ) ;
if ( F_48 ( & V_84 -> V_78 ) )
F_28 ( V_84 ) ;
F_28 ( V_84 ) ;
}
static inline unsigned int F_54 ( struct V_35 * V_35 , T_3 V_66 )
{
return F_55 ( V_66 , V_35 -> V_101 . V_102 ) ;
}
static void F_56 ( struct V_35 * V_35 ,
unsigned short V_28 , int V_61 ,
T_4 * V_103 , T_4 * V_104 )
{
switch ( V_28 ) {
case V_29 :
* V_103 = V_35 -> V_101 . V_105 [ V_61 ] . V_106 ;
* V_104 = V_35 -> V_101 . V_105 [ V_61 ] . V_107 ;
break;
case V_30 :
* V_103 = V_35 -> V_101 . V_105 [ V_61 ] . V_108 ;
* V_104 = V_35 -> V_101 . V_105 [ V_61 ] . V_109 ;
break;
default:
* V_103 = 0 ;
* V_104 = 0 ;
}
}
static struct V_110 * F_57 ( struct V_35 * V_35 ,
const struct V_1 * V_2 ,
unsigned short V_28 , int V_61 )
{
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_61 ] . V_111 ;
unsigned int V_112 ;
T_4 V_103 ;
T_4 V_104 ;
F_56 ( V_35 , V_28 , V_61 , & V_103 , & V_104 ) ;
V_112 = F_58 ( V_2 , V_28 , V_111 , V_103 , V_104 ) ;
return ( V_112 == V_111 + 1 ?
& V_35 -> V_101 . V_113 [ V_61 ] :
V_35 -> V_101 . V_105 [ V_61 ] . V_114 + V_112 ) ;
}
static struct V_110 * F_59 ( struct V_35 * V_35 ,
const T_1 * V_9 ,
const T_1 * V_12 ,
unsigned short V_28 , int V_61 )
{
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_61 ] . V_111 ;
unsigned int V_112 ;
T_4 V_103 ;
T_4 V_104 ;
F_56 ( V_35 , V_28 , V_61 , & V_103 , & V_104 ) ;
V_112 = F_60 ( V_9 , V_12 , V_28 , V_111 , V_103 , V_104 ) ;
return V_35 -> V_101 . V_105 [ V_61 ] . V_114 + V_112 ;
}
static void F_61 ( struct V_35 * V_35 ,
struct V_110 * V_115 ,
struct V_110 * V_116 ,
unsigned int V_117 ,
int V_61 )
{
struct V_118 * V_119 , * V_120 = NULL ;
struct V_55 * V_82 ;
unsigned int V_121 = 0 ;
T_4 V_103 ;
T_4 V_104 ;
V_122:
F_62 (pol, tmp, list, bydst) {
unsigned int V_123 ;
F_56 ( V_35 , V_82 -> V_28 , V_61 , & V_103 , & V_104 ) ;
V_123 = F_60 ( & V_82 -> V_124 . V_9 , & V_82 -> V_124 . V_12 ,
V_82 -> V_28 , V_117 , V_103 , V_104 ) ;
if ( ! V_120 ) {
F_63 ( & V_82 -> V_87 ) ;
F_64 ( & V_82 -> V_87 , V_116 + V_123 ) ;
V_121 = V_123 ;
} else {
if ( V_123 != V_121 )
continue;
F_63 ( & V_82 -> V_87 ) ;
F_65 ( & V_82 -> V_87 , V_120 ) ;
}
V_120 = & V_82 -> V_87 ;
}
if ( ! F_66 ( V_115 ) ) {
V_120 = NULL ;
goto V_122;
}
}
static void F_67 ( struct V_110 * V_115 ,
struct V_110 * V_125 ,
unsigned int V_117 )
{
struct V_118 * V_119 ;
struct V_55 * V_82 ;
F_62 (pol, tmp, list, byidx) {
unsigned int V_123 ;
V_123 = F_55 ( V_82 -> V_66 , V_117 ) ;
F_64 ( & V_82 -> V_88 , V_125 + V_123 ) ;
}
}
static unsigned long F_68 ( unsigned int V_126 )
{
return ( ( V_126 + 1 ) << 1 ) - 1 ;
}
static void F_69 ( struct V_35 * V_35 , int V_61 )
{
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_61 ] . V_111 ;
unsigned int V_117 = F_68 ( V_111 ) ;
unsigned int V_127 = ( V_117 + 1 ) * sizeof( struct V_110 ) ;
struct V_110 * V_128 = V_35 -> V_101 . V_105 [ V_61 ] . V_114 ;
struct V_110 * V_129 = F_70 ( V_127 ) ;
int V_130 ;
if ( ! V_129 )
return;
F_71 ( & V_35 -> V_101 . V_131 ) ;
for ( V_130 = V_111 ; V_130 >= 0 ; V_130 -- )
F_61 ( V_35 , V_128 + V_130 , V_129 , V_117 , V_61 ) ;
V_35 -> V_101 . V_105 [ V_61 ] . V_114 = V_129 ;
V_35 -> V_101 . V_105 [ V_61 ] . V_111 = V_117 ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
F_73 ( V_128 , ( V_111 + 1 ) * sizeof( struct V_110 ) ) ;
}
static void F_74 ( struct V_35 * V_35 , int V_132 )
{
unsigned int V_111 = V_35 -> V_101 . V_102 ;
unsigned int V_117 = F_68 ( V_111 ) ;
unsigned int V_127 = ( V_117 + 1 ) * sizeof( struct V_110 ) ;
struct V_110 * V_133 = V_35 -> V_101 . V_134 ;
struct V_110 * V_135 = F_70 ( V_127 ) ;
int V_130 ;
if ( ! V_135 )
return;
F_71 ( & V_35 -> V_101 . V_131 ) ;
for ( V_130 = V_111 ; V_130 >= 0 ; V_130 -- )
F_67 ( V_133 + V_130 , V_135 , V_117 ) ;
V_35 -> V_101 . V_134 = V_135 ;
V_35 -> V_101 . V_102 = V_117 ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
F_73 ( V_133 , ( V_111 + 1 ) * sizeof( struct V_110 ) ) ;
}
static inline int F_75 ( struct V_35 * V_35 , int V_61 , int * V_132 )
{
unsigned int V_136 = V_35 -> V_101 . V_137 [ V_61 ] ;
unsigned int V_111 = V_35 -> V_101 . V_105 [ V_61 ] . V_111 ;
if ( V_132 )
* V_132 += V_136 ;
if ( ( V_111 + 1 ) < V_138 &&
V_136 > V_111 )
return 1 ;
return 0 ;
}
static inline int F_76 ( struct V_35 * V_35 , int V_132 )
{
unsigned int V_111 = V_35 -> V_101 . V_102 ;
if ( ( V_111 + 1 ) < V_138 &&
V_132 > V_111 )
return 1 ;
return 0 ;
}
void F_77 ( struct V_35 * V_35 , struct V_139 * V_140 )
{
F_78 ( & V_35 -> V_101 . V_131 ) ;
V_140 -> V_141 = V_35 -> V_101 . V_137 [ V_142 ] ;
V_140 -> V_143 = V_35 -> V_101 . V_137 [ V_144 ] ;
V_140 -> V_145 = V_35 -> V_101 . V_137 [ V_146 ] ;
V_140 -> V_147 = V_35 -> V_101 . V_137 [ V_142 + V_148 ] ;
V_140 -> V_149 = V_35 -> V_101 . V_137 [ V_144 + V_148 ] ;
V_140 -> V_150 = V_35 -> V_101 . V_137 [ V_146 + V_148 ] ;
V_140 -> V_151 = V_35 -> V_101 . V_102 ;
V_140 -> V_152 = V_138 ;
F_79 ( & V_35 -> V_101 . V_131 ) ;
}
static void F_80 ( struct V_153 * V_154 )
{
struct V_35 * V_35 = F_31 ( V_154 , struct V_35 , V_101 . V_155 ) ;
int V_61 , V_132 ;
F_81 ( & V_156 ) ;
V_132 = 0 ;
for ( V_61 = 0 ; V_61 < V_148 ; V_61 ++ ) {
if ( F_75 ( V_35 , V_61 , & V_132 ) )
F_69 ( V_35 , V_61 ) ;
}
if ( F_76 ( V_35 , V_132 ) )
F_74 ( V_35 , V_132 ) ;
F_82 ( & V_156 ) ;
}
static void F_83 ( struct V_153 * V_154 )
{
struct V_35 * V_35 = F_31 ( V_154 , struct V_35 ,
V_101 . V_157 . V_154 ) ;
unsigned int V_111 ;
struct V_55 * V_82 ;
struct V_55 * V_84 ;
struct V_110 * V_158 ;
struct V_110 * V_128 ;
struct V_118 * V_159 ;
int V_130 ;
int V_61 ;
unsigned V_160 ;
T_4 V_161 , V_162 , V_163 , V_164 ;
F_81 ( & V_156 ) ;
do {
V_160 = F_84 ( & V_35 -> V_101 . V_157 . V_62 ) ;
V_161 = V_35 -> V_101 . V_157 . V_161 ;
V_162 = V_35 -> V_101 . V_157 . V_162 ;
V_163 = V_35 -> V_101 . V_157 . V_163 ;
V_164 = V_35 -> V_101 . V_157 . V_164 ;
} while ( F_85 ( & V_35 -> V_101 . V_157 . V_62 , V_160 ) );
F_71 ( & V_35 -> V_101 . V_131 ) ;
for ( V_61 = 0 ; V_61 < V_148 ; V_61 ++ ) {
F_86 ( & V_35 -> V_101 . V_113 [ V_61 ] ) ;
V_111 = V_35 -> V_101 . V_105 [ V_61 ] . V_111 ;
V_128 = V_35 -> V_101 . V_105 [ V_61 ] . V_114 ;
for ( V_130 = V_111 ; V_130 >= 0 ; V_130 -- )
F_86 ( V_128 + V_130 ) ;
if ( ( V_61 & V_165 ) == V_144 ) {
V_35 -> V_101 . V_105 [ V_61 ] . V_106 = V_162 ;
V_35 -> V_101 . V_105 [ V_61 ] . V_107 = V_161 ;
V_35 -> V_101 . V_105 [ V_61 ] . V_108 = V_164 ;
V_35 -> V_101 . V_105 [ V_61 ] . V_109 = V_163 ;
} else {
V_35 -> V_101 . V_105 [ V_61 ] . V_106 = V_161 ;
V_35 -> V_101 . V_105 [ V_61 ] . V_107 = V_162 ;
V_35 -> V_101 . V_105 [ V_61 ] . V_108 = V_163 ;
V_35 -> V_101 . V_105 [ V_61 ] . V_109 = V_164 ;
}
}
F_87 (policy, &net->xfrm.policy_all, walk.all) {
V_159 = NULL ;
V_158 = F_57 ( V_35 , & V_84 -> V_124 ,
V_84 -> V_28 ,
F_23 ( V_84 -> V_66 ) ) ;
F_88 (pol, chain, bydst) {
if ( V_84 -> V_166 >= V_82 -> V_166 )
V_159 = & V_82 -> V_87 ;
else
break;
}
if ( V_159 )
F_65 ( & V_84 -> V_87 , V_159 ) ;
else
F_64 ( & V_84 -> V_87 , V_158 ) ;
}
F_72 ( & V_35 -> V_101 . V_131 ) ;
F_82 ( & V_156 ) ;
}
void F_89 ( struct V_35 * V_35 )
{
F_90 ( & V_35 -> V_101 . V_157 . V_154 ) ;
}
static T_3 F_91 ( struct V_35 * V_35 , int V_61 , T_3 V_66 )
{
static T_3 V_167 ;
for (; ; ) {
struct V_110 * V_115 ;
struct V_55 * V_168 ;
T_3 V_169 ;
int V_170 ;
if ( ! V_66 ) {
V_169 = ( V_167 | V_61 ) ;
V_167 += 8 ;
} else {
V_169 = V_66 ;
V_66 = 0 ;
}
if ( V_169 == 0 )
V_169 = 8 ;
V_115 = V_35 -> V_101 . V_134 + F_54 ( V_35 , V_169 ) ;
V_170 = 0 ;
F_88 (p, list, byidx) {
if ( V_168 -> V_66 == V_169 ) {
V_170 = 1 ;
break;
}
}
if ( ! V_170 )
return V_169 ;
}
}
static inline int F_92 ( struct V_1 * V_171 , struct V_1 * V_172 )
{
T_3 * V_173 = ( T_3 * ) V_171 ;
T_3 * V_174 = ( T_3 * ) V_172 ;
int V_175 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_130 ;
for ( V_130 = 0 ; V_130 < V_175 ; V_130 ++ ) {
if ( V_173 [ V_130 ] != V_174 [ V_130 ] )
return 1 ;
}
return 0 ;
}
static void F_93 ( struct V_55 * V_176 ,
struct V_55 * V_177 )
{
struct V_178 * V_179 = & V_176 -> V_90 ;
struct V_180 V_115 ;
if ( F_94 ( & V_179 -> V_91 ) )
return;
F_95 ( & V_115 ) ;
F_96 ( & V_179 -> V_91 . V_62 ) ;
F_97 ( & V_179 -> V_91 , & V_115 ) ;
if ( F_48 ( & V_179 -> V_92 ) )
F_28 ( V_176 ) ;
F_98 ( & V_179 -> V_91 . V_62 ) ;
V_179 = & V_177 -> V_90 ;
F_96 ( & V_179 -> V_91 . V_62 ) ;
F_99 ( & V_115 , & V_179 -> V_91 ) ;
V_179 -> V_181 = V_182 ;
if ( ! F_25 ( & V_179 -> V_92 , V_79 ) )
F_26 ( V_177 ) ;
F_98 ( & V_179 -> V_91 . V_62 ) ;
}
static bool F_100 ( struct V_55 * V_84 ,
struct V_55 * V_82 )
{
T_3 V_183 = V_84 -> V_183 . V_184 & V_84 -> V_183 . V_185 ;
if ( V_84 -> V_183 . V_184 == V_82 -> V_183 . V_184 && V_84 -> V_183 . V_185 == V_82 -> V_183 . V_185 )
return true ;
if ( ( V_183 & V_82 -> V_183 . V_185 ) == V_82 -> V_183 . V_184 &&
V_84 -> V_166 == V_82 -> V_166 )
return true ;
return false ;
}
int F_101 ( int V_61 , struct V_55 * V_84 , int V_186 )
{
struct V_35 * V_35 = V_85 ( V_84 ) ;
struct V_55 * V_82 ;
struct V_55 * V_187 ;
struct V_110 * V_158 ;
struct V_118 * V_159 ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
V_158 = F_57 ( V_35 , & V_84 -> V_124 , V_84 -> V_28 , V_61 ) ;
V_187 = NULL ;
V_159 = NULL ;
F_88 (pol, chain, bydst) {
if ( V_82 -> type == V_84 -> type &&
! F_92 ( & V_82 -> V_124 , & V_84 -> V_124 ) &&
F_100 ( V_84 , V_82 ) &&
F_102 ( V_82 -> V_99 , V_84 -> V_99 ) &&
! F_103 ( V_187 ) ) {
if ( V_186 ) {
F_72 ( & V_35 -> V_101 . V_131 ) ;
return - V_188 ;
}
V_187 = V_82 ;
if ( V_84 -> V_166 > V_82 -> V_166 )
continue;
} else if ( V_84 -> V_166 >= V_82 -> V_166 ) {
V_159 = & V_82 -> V_87 ;
continue;
}
if ( V_187 )
break;
}
if ( V_159 )
F_65 ( & V_84 -> V_87 , V_159 ) ;
else
F_64 ( & V_84 -> V_87 , V_158 ) ;
F_104 ( V_84 , V_61 ) ;
F_52 ( & V_35 -> V_101 . V_189 ) ;
if ( V_84 -> V_28 == V_29 )
F_105 ( V_35 ) ;
else
F_106 ( V_35 ) ;
if ( V_187 ) {
F_93 ( V_187 , V_84 ) ;
F_107 ( V_187 , V_61 ) ;
}
V_84 -> V_66 = V_187 ? V_187 -> V_66 : F_91 ( V_35 , V_61 , V_84 -> V_66 ) ;
F_64 ( & V_84 -> V_88 , V_35 -> V_101 . V_134 + F_54 ( V_35 , V_84 -> V_66 ) ) ;
V_84 -> V_70 . V_71 = F_21 () ;
V_84 -> V_70 . V_74 = 0 ;
if ( ! F_25 ( & V_84 -> V_78 , V_79 + V_53 ) )
F_26 ( V_84 ) ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
if ( V_187 )
F_51 ( V_187 ) ;
else if ( F_75 ( V_35 , V_61 , NULL ) )
F_90 ( & V_35 -> V_101 . V_155 ) ;
return 0 ;
}
struct V_55 * F_108 ( struct V_35 * V_35 , T_3 V_183 , T_4 type ,
int V_61 , struct V_1 * V_2 ,
struct V_190 * V_191 , int V_192 ,
int * V_193 )
{
struct V_55 * V_82 , * V_194 ;
struct V_110 * V_158 ;
* V_193 = 0 ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
V_158 = F_57 ( V_35 , V_2 , V_2 -> V_28 , V_61 ) ;
V_194 = NULL ;
F_88 (pol, chain, bydst) {
if ( V_82 -> type == type &&
( V_183 & V_82 -> V_183 . V_185 ) == V_82 -> V_183 . V_184 &&
! F_92 ( V_2 , & V_82 -> V_124 ) &&
F_102 ( V_191 , V_82 -> V_99 ) ) {
F_26 ( V_82 ) ;
if ( V_192 ) {
* V_193 = F_109 (
V_82 -> V_99 ) ;
if ( * V_193 ) {
F_72 ( & V_35 -> V_101 . V_131 ) ;
return V_82 ;
}
F_107 ( V_82 , V_61 ) ;
}
V_194 = V_82 ;
break;
}
}
F_72 ( & V_35 -> V_101 . V_131 ) ;
if ( V_194 && V_192 )
F_51 ( V_194 ) ;
return V_194 ;
}
struct V_55 * F_110 ( struct V_35 * V_35 , T_3 V_183 , T_4 type ,
int V_61 , T_3 V_46 , int V_192 , int * V_193 )
{
struct V_55 * V_82 , * V_194 ;
struct V_110 * V_158 ;
* V_193 = - V_195 ;
if ( F_23 ( V_46 ) != V_61 )
return NULL ;
* V_193 = 0 ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
V_158 = V_35 -> V_101 . V_134 + F_54 ( V_35 , V_46 ) ;
V_194 = NULL ;
F_88 (pol, chain, byidx) {
if ( V_82 -> type == type && V_82 -> V_66 == V_46 &&
( V_183 & V_82 -> V_183 . V_185 ) == V_82 -> V_183 . V_184 ) {
F_26 ( V_82 ) ;
if ( V_192 ) {
* V_193 = F_109 (
V_82 -> V_99 ) ;
if ( * V_193 ) {
F_72 ( & V_35 -> V_101 . V_131 ) ;
return V_82 ;
}
F_107 ( V_82 , V_61 ) ;
}
V_194 = V_82 ;
break;
}
}
F_72 ( & V_35 -> V_101 . V_131 ) ;
if ( V_194 && V_192 )
F_51 ( V_194 ) ;
return V_194 ;
}
static inline int
F_111 ( struct V_35 * V_35 , T_4 type , bool V_196 )
{
int V_61 , V_193 = 0 ;
for ( V_61 = 0 ; V_61 < V_148 ; V_61 ++ ) {
struct V_55 * V_82 ;
int V_130 ;
F_88 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_82 -> type != type )
continue;
V_193 = F_109 ( V_82 -> V_99 ) ;
if ( V_193 ) {
F_112 ( V_82 , 0 , V_196 ) ;
return V_193 ;
}
}
for ( V_130 = V_35 -> V_101 . V_105 [ V_61 ] . V_111 ; V_130 >= 0 ; V_130 -- ) {
F_88 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_82 -> type != type )
continue;
V_193 = F_109 (
V_82 -> V_99 ) ;
if ( V_193 ) {
F_112 ( V_82 , 0 ,
V_196 ) ;
return V_193 ;
}
}
}
}
return V_193 ;
}
static inline int
F_111 ( struct V_35 * V_35 , T_4 type , bool V_196 )
{
return 0 ;
}
int F_113 ( struct V_35 * V_35 , T_4 type , bool V_196 )
{
int V_61 , V_193 = 0 , V_136 = 0 ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
V_193 = F_111 ( V_35 , type , V_196 ) ;
if ( V_193 )
goto V_65;
for ( V_61 = 0 ; V_61 < V_148 ; V_61 ++ ) {
struct V_55 * V_82 ;
int V_130 ;
V_197:
F_88 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_82 -> type != type )
continue;
F_107 ( V_82 , V_61 ) ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
V_136 ++ ;
F_112 ( V_82 , 1 , V_196 ) ;
F_51 ( V_82 ) ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
goto V_197;
}
for ( V_130 = V_35 -> V_101 . V_105 [ V_61 ] . V_111 ; V_130 >= 0 ; V_130 -- ) {
V_198:
F_88 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_82 -> type != type )
continue;
F_107 ( V_82 , V_61 ) ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
V_136 ++ ;
F_112 ( V_82 , 1 , V_196 ) ;
F_51 ( V_82 ) ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
goto V_198;
}
}
}
if ( ! V_136 )
V_193 = - V_199 ;
V_65:
F_72 ( & V_35 -> V_101 . V_131 ) ;
return V_193 ;
}
int F_114 ( struct V_35 * V_35 , struct F_114 * V_63 ,
int (* F_115)( struct V_55 * , int , int , void * ) ,
void * V_54 )
{
struct V_55 * V_82 ;
struct V_200 * V_42 ;
int error = 0 ;
if ( V_63 -> type >= V_201 &&
V_63 -> type != V_202 )
return - V_203 ;
if ( F_116 ( & V_63 -> V_63 . V_86 ) && V_63 -> V_160 != 0 )
return 0 ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
if ( F_116 ( & V_63 -> V_63 . V_86 ) )
V_42 = F_117 ( & V_35 -> V_101 . V_204 , struct V_200 , V_86 ) ;
else
V_42 = F_117 ( & V_63 -> V_63 . V_86 ,
struct V_200 , V_86 ) ;
F_118 (x, &net->xfrm.policy_all, all) {
if ( V_42 -> V_64 )
continue;
V_82 = F_31 ( V_42 , struct V_55 , V_63 ) ;
if ( V_63 -> type != V_202 &&
V_63 -> type != V_82 -> type )
continue;
error = F_115 ( V_82 , F_23 ( V_82 -> V_66 ) ,
V_63 -> V_160 , V_54 ) ;
if ( error ) {
F_119 ( & V_63 -> V_63 . V_86 , & V_42 -> V_86 ) ;
goto V_65;
}
V_63 -> V_160 ++ ;
}
if ( V_63 -> V_160 == 0 ) {
error = - V_195 ;
goto V_65;
}
F_120 ( & V_63 -> V_63 . V_86 ) ;
V_65:
F_72 ( & V_35 -> V_101 . V_131 ) ;
return error ;
}
void F_121 ( struct F_114 * V_63 , T_4 type )
{
F_37 ( & V_63 -> V_63 . V_86 ) ;
V_63 -> V_63 . V_64 = 1 ;
V_63 -> type = type ;
V_63 -> V_160 = 0 ;
}
void F_122 ( struct F_114 * V_63 , struct V_35 * V_35 )
{
if ( F_116 ( & V_63 -> V_63 . V_86 ) )
return;
F_71 ( & V_35 -> V_101 . V_131 ) ;
F_123 ( & V_63 -> V_63 . V_86 ) ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
}
static int F_124 ( const struct V_55 * V_82 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_28 , int V_61 )
{
const struct V_1 * V_2 = & V_82 -> V_124 ;
int V_194 = - V_199 ;
bool V_205 ;
if ( V_82 -> V_28 != V_28 ||
( V_4 -> V_206 & V_82 -> V_183 . V_185 ) != V_82 -> V_183 . V_184 ||
V_82 -> type != type )
return V_194 ;
V_205 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_205 )
V_194 = F_125 ( V_82 -> V_99 , V_4 -> V_207 ,
V_61 ) ;
return V_194 ;
}
static struct V_55 * F_126 ( struct V_35 * V_35 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_28 , T_4 V_61 )
{
int V_193 ;
struct V_55 * V_82 , * V_194 ;
const T_1 * V_9 , * V_12 ;
struct V_110 * V_158 ;
T_3 V_166 = ~ 0U ;
V_9 = F_127 ( V_4 , V_28 ) ;
V_12 = F_128 ( V_4 , V_28 ) ;
if ( F_9 ( ! V_9 || ! V_12 ) )
return NULL ;
F_78 ( & V_35 -> V_101 . V_131 ) ;
V_158 = F_59 ( V_35 , V_9 , V_12 , V_28 , V_61 ) ;
V_194 = NULL ;
F_88 (pol, chain, bydst) {
V_193 = F_124 ( V_82 , V_4 , type , V_28 , V_61 ) ;
if ( V_193 ) {
if ( V_193 == - V_199 )
continue;
else {
V_194 = F_15 ( V_193 ) ;
goto V_208;
}
} else {
V_194 = V_82 ;
V_166 = V_194 -> V_166 ;
break;
}
}
V_158 = & V_35 -> V_101 . V_113 [ V_61 ] ;
F_88 (pol, chain, bydst) {
if ( ( V_82 -> V_166 >= V_166 ) && V_194 )
break;
V_193 = F_124 ( V_82 , V_4 , type , V_28 , V_61 ) ;
if ( V_193 ) {
if ( V_193 == - V_199 )
continue;
else {
V_194 = F_15 ( V_193 ) ;
goto V_208;
}
} else {
V_194 = V_82 ;
break;
}
}
F_26 ( V_194 ) ;
V_208:
F_79 ( & V_35 -> V_101 . V_131 ) ;
return V_194 ;
}
static struct V_55 *
F_129 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_61 )
{
#ifdef F_130
struct V_55 * V_82 ;
V_82 = F_126 ( V_35 , V_209 , V_4 , V_28 , V_61 ) ;
if ( V_82 != NULL )
return V_82 ;
#endif
return F_126 ( V_35 , V_210 , V_4 , V_28 , V_61 ) ;
}
static int F_131 ( int V_61 )
{
if ( V_142 == V_211 &&
V_144 == V_212 &&
V_146 == V_213 )
return V_61 ;
switch ( V_61 ) {
default:
case V_211 :
return V_142 ;
case V_212 :
return V_144 ;
case V_213 :
return V_146 ;
}
}
static struct V_80 *
F_132 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_61 , struct V_80 * V_214 , void * V_191 )
{
struct V_55 * V_82 ;
if ( V_214 )
F_28 ( F_31 ( V_214 , struct V_55 , V_81 ) ) ;
V_82 = F_129 ( V_35 , V_4 , V_28 , F_131 ( V_61 ) ) ;
if ( F_133 ( V_82 ) )
return F_134 ( V_82 ) ;
F_26 ( V_82 ) ;
return & V_82 -> V_81 ;
}
static inline int F_135 ( int V_61 )
{
if ( V_142 == V_211 &&
V_144 == V_212 &&
V_146 == V_213 )
return V_61 ;
switch ( V_61 ) {
default:
case V_142 :
return V_211 ;
case V_144 :
return V_212 ;
case V_146 :
return V_213 ;
}
}
static struct V_55 * F_136 ( const struct V_215 * V_216 , int V_61 ,
const struct V_3 * V_4 )
{
struct V_55 * V_82 ;
struct V_35 * V_35 = F_137 ( V_216 ) ;
F_10 () ;
F_78 ( & V_35 -> V_101 . V_131 ) ;
V_82 = F_11 ( V_216 -> V_217 [ V_61 ] ) ;
if ( V_82 != NULL ) {
bool V_205 = F_7 ( & V_82 -> V_124 , V_4 ,
V_216 -> V_218 ) ;
int V_193 = 0 ;
if ( V_205 ) {
if ( ( V_216 -> V_219 & V_82 -> V_183 . V_185 ) != V_82 -> V_183 . V_184 ) {
V_82 = NULL ;
goto V_65;
}
V_193 = F_125 ( V_82 -> V_99 ,
V_4 -> V_207 ,
F_135 ( V_61 ) ) ;
if ( ! V_193 )
F_26 ( V_82 ) ;
else if ( V_193 == - V_199 )
V_82 = NULL ;
else
V_82 = F_15 ( V_193 ) ;
} else
V_82 = NULL ;
}
V_65:
F_79 ( & V_35 -> V_101 . V_131 ) ;
F_12 () ;
return V_82 ;
}
static void F_104 ( struct V_55 * V_82 , int V_61 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
F_138 ( & V_82 -> V_63 . V_86 , & V_35 -> V_101 . V_204 ) ;
V_35 -> V_101 . V_137 [ V_61 ] ++ ;
F_26 ( V_82 ) ;
}
static struct V_55 * F_107 ( struct V_55 * V_82 ,
int V_61 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
if ( F_116 ( & V_82 -> V_63 . V_86 ) )
return NULL ;
if ( ! F_139 ( & V_82 -> V_87 ) ) {
F_63 ( & V_82 -> V_87 ) ;
F_63 ( & V_82 -> V_88 ) ;
}
F_120 ( & V_82 -> V_63 . V_86 ) ;
V_35 -> V_101 . V_137 [ V_61 ] -- ;
return V_82 ;
}
static void F_140 ( struct V_55 * V_82 , int V_61 )
{
F_104 ( V_82 , V_148 + V_61 ) ;
}
static void F_141 ( struct V_55 * V_82 , int V_61 )
{
F_107 ( V_82 , V_148 + V_61 ) ;
}
int F_29 ( struct V_55 * V_82 , int V_61 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
V_82 = F_107 ( V_82 , V_61 ) ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
if ( V_82 ) {
F_51 ( V_82 ) ;
return 0 ;
}
return - V_195 ;
}
int F_142 ( struct V_215 * V_216 , int V_61 , struct V_55 * V_82 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
struct V_55 * V_220 ;
#ifdef F_130
if ( V_82 && V_82 -> type != V_210 )
return - V_203 ;
#endif
F_71 ( & V_35 -> V_101 . V_131 ) ;
V_220 = F_143 ( V_216 -> V_217 [ V_61 ] ,
F_144 ( & V_35 -> V_101 . V_131 ) ) ;
if ( V_82 ) {
V_82 -> V_70 . V_71 = F_21 () ;
V_82 -> V_66 = F_91 ( V_35 , V_148 + V_61 , 0 ) ;
F_140 ( V_82 , V_61 ) ;
}
F_145 ( V_216 -> V_217 [ V_61 ] , V_82 ) ;
if ( V_220 ) {
if ( V_82 )
F_93 ( V_220 , V_82 ) ;
F_141 ( V_220 , V_61 ) ;
}
F_72 ( & V_35 -> V_101 . V_131 ) ;
if ( V_220 ) {
F_51 ( V_220 ) ;
}
return 0 ;
}
static struct V_55 * F_146 ( const struct V_55 * V_176 , int V_61 )
{
struct V_55 * V_221 = F_34 ( V_85 ( V_176 ) , V_222 ) ;
struct V_35 * V_35 = V_85 ( V_176 ) ;
if ( V_221 ) {
V_221 -> V_124 = V_176 -> V_124 ;
if ( F_147 ( V_176 -> V_99 ,
& V_221 -> V_99 ) ) {
F_45 ( V_221 ) ;
return NULL ;
}
V_221 -> V_67 = V_176 -> V_67 ;
V_221 -> V_70 = V_176 -> V_70 ;
V_221 -> V_183 = V_176 -> V_183 ;
V_221 -> V_223 = V_176 -> V_223 ;
V_221 -> V_47 = V_176 -> V_47 ;
V_221 -> V_224 = V_176 -> V_224 ;
V_221 -> V_66 = V_176 -> V_66 ;
V_221 -> type = V_176 -> type ;
memcpy ( V_221 -> V_225 , V_176 -> V_225 ,
V_221 -> V_224 * sizeof( struct V_226 ) ) ;
F_71 ( & V_35 -> V_101 . V_131 ) ;
F_140 ( V_221 , V_61 ) ;
F_72 ( & V_35 -> V_101 . V_131 ) ;
F_28 ( V_221 ) ;
}
return V_221 ;
}
int F_148 ( struct V_215 * V_216 , const struct V_215 * V_227 )
{
const struct V_55 * V_168 ;
struct V_55 * V_228 ;
int V_130 , V_194 = 0 ;
F_10 () ;
for ( V_130 = 0 ; V_130 < 2 ; V_130 ++ ) {
V_168 = F_11 ( V_227 -> V_217 [ V_130 ] ) ;
if ( V_168 ) {
V_228 = F_146 ( V_168 , V_130 ) ;
if ( F_9 ( ! V_228 ) ) {
V_194 = - V_229 ;
break;
}
F_145 ( V_216 -> V_217 [ V_130 ] , V_228 ) ;
}
}
F_12 () ;
return V_194 ;
}
static int
F_149 ( struct V_35 * V_35 , int V_37 , T_1 * V_230 ,
T_1 * V_231 , unsigned short V_28 )
{
int V_193 ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return - V_203 ;
V_193 = V_32 -> V_232 ( V_35 , V_37 , V_230 , V_231 ) ;
F_13 ( V_32 ) ;
return V_193 ;
}
static int
F_150 ( struct V_55 * V_84 , const struct V_3 * V_4 ,
struct V_41 * * V_101 , unsigned short V_28 )
{
struct V_35 * V_35 = V_85 ( V_84 ) ;
int V_233 ;
int V_130 , error ;
T_1 * V_9 = F_127 ( V_4 , V_28 ) ;
T_1 * V_12 = F_128 ( V_4 , V_28 ) ;
T_1 V_119 ;
for ( V_233 = 0 , V_130 = 0 ; V_130 < V_84 -> V_224 ; V_130 ++ ) {
struct V_41 * V_42 ;
T_1 * V_231 = V_9 ;
T_1 * V_230 = V_12 ;
struct V_226 * V_234 = & V_84 -> V_225 [ V_130 ] ;
if ( V_234 -> V_235 == V_236 ||
V_234 -> V_235 == V_237 ) {
V_231 = & V_234 -> V_46 . V_9 ;
V_230 = & V_234 -> V_12 ;
if ( F_151 ( V_230 , V_234 -> V_238 ) ) {
error = F_149 ( V_35 , V_4 -> V_239 ,
& V_119 , V_231 ,
V_234 -> V_238 ) ;
if ( error )
goto V_208;
V_230 = & V_119 ;
}
}
V_42 = F_152 ( V_231 , V_230 , V_4 , V_234 , V_84 , & error , V_28 ) ;
if ( V_42 && V_42 -> V_240 . V_241 == V_242 ) {
V_101 [ V_233 ++ ] = V_42 ;
V_9 = V_231 ;
V_12 = V_230 ;
continue;
}
if ( V_42 ) {
error = ( V_42 -> V_240 . V_241 == V_243 ?
- V_203 : - V_244 ) ;
F_153 ( V_42 ) ;
} else if ( error == - V_199 ) {
error = - V_244 ;
}
if ( ! V_234 -> V_245 )
goto V_208;
}
return V_233 ;
V_208:
for ( V_233 -- ; V_233 >= 0 ; V_233 -- )
F_153 ( V_101 [ V_233 ] ) ;
return error ;
}
static int
F_154 ( struct V_55 * * V_246 , int V_247 , const struct V_3 * V_4 ,
struct V_41 * * V_101 , unsigned short V_28 )
{
struct V_41 * V_248 [ V_249 ] ;
struct V_41 * * V_250 = ( V_247 > 1 ) ? V_248 : V_101 ;
int V_251 = 0 ;
int error ;
int V_194 ;
int V_130 ;
for ( V_130 = 0 ; V_130 < V_247 ; V_130 ++ ) {
if ( V_251 + V_246 [ V_130 ] -> V_224 >= V_249 ) {
error = - V_252 ;
goto V_208;
}
V_194 = F_150 ( V_246 [ V_130 ] , V_4 , & V_250 [ V_251 ] , V_28 ) ;
if ( V_194 < 0 ) {
error = V_194 ;
goto V_208;
} else
V_251 += V_194 ;
}
if ( V_247 > 1 )
F_155 ( V_101 , V_250 , V_251 , V_28 ) ;
return V_251 ;
V_208:
for ( V_251 -- ; V_251 >= 0 ; V_251 -- )
F_153 ( V_250 [ V_251 ] ) ;
return error ;
}
static inline int F_156 ( const struct V_3 * V_4 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_36 ;
if ( ! V_32 )
return - V_203 ;
V_36 = V_32 -> V_253 ( V_4 ) ;
F_13 ( V_32 ) ;
return V_36 ;
}
static struct V_80 * F_157 ( struct V_80 * V_81 )
{
struct V_254 * V_255 = F_31 ( V_81 , struct V_254 , V_81 ) ;
struct V_34 * V_38 = & V_255 -> V_7 . V_38 ;
if ( V_255 -> V_256 == NULL ) {
if ( V_255 -> V_257 > 0 )
return NULL ;
} else if ( V_38 -> V_47 & V_258 ) {
return NULL ;
} else {
if ( F_158 ( V_38 ) )
return NULL ;
}
F_159 ( V_38 ) ;
return V_81 ;
}
static int F_160 ( struct V_80 * V_81 )
{
struct V_254 * V_255 = F_31 ( V_81 , struct V_254 , V_81 ) ;
struct V_34 * V_38 = & V_255 -> V_7 . V_38 ;
if ( ! V_255 -> V_256 )
return 0 ;
if ( F_158 ( V_38 ) )
return 0 ;
return 1 ;
}
static void F_161 ( struct V_80 * V_81 )
{
struct V_254 * V_255 = F_31 ( V_81 , struct V_254 , V_81 ) ;
struct V_34 * V_38 = & V_255 -> V_7 . V_38 ;
F_162 ( V_38 ) ;
}
static inline struct V_254 * F_163 ( struct V_35 * V_35 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_259 * V_259 ;
struct V_254 * V_255 ;
if ( ! V_32 )
return F_15 ( - V_203 ) ;
switch ( V_28 ) {
case V_29 :
V_259 = & V_35 -> V_101 . V_260 ;
break;
#if F_164 ( V_261 )
case V_30 :
V_259 = & V_35 -> V_101 . V_262 ;
break;
#endif
default:
F_49 () ;
}
V_255 = F_165 ( V_259 , NULL , 0 , V_263 , 0 ) ;
if ( F_166 ( V_255 ) ) {
struct V_34 * V_38 = & V_255 -> V_7 . V_38 ;
memset ( V_38 + 1 , 0 , sizeof( * V_255 ) - sizeof( * V_38 ) ) ;
V_255 -> V_81 . V_94 = & V_264 ;
} else
V_255 = F_15 ( - V_252 ) ;
F_13 ( V_32 ) ;
return V_255 ;
}
static inline int F_167 ( struct V_254 * V_265 , struct V_34 * V_38 ,
int V_266 )
{
struct V_31 * V_32 =
F_8 ( V_38 -> V_94 -> V_28 ) ;
int V_193 ;
if ( ! V_32 )
return - V_203 ;
V_193 = V_32 -> V_267 ( V_265 , V_38 , V_266 ) ;
F_13 ( V_32 ) ;
return V_193 ;
}
static inline int F_168 ( struct V_254 * V_255 , struct V_268 * V_269 ,
const struct V_3 * V_4 )
{
struct V_31 * V_32 =
F_8 ( V_255 -> V_7 . V_38 . V_94 -> V_28 ) ;
int V_193 ;
if ( ! V_32 )
return - V_203 ;
V_193 = V_32 -> V_270 ( V_255 , V_269 , V_4 ) ;
F_13 ( V_32 ) ;
return V_193 ;
}
static struct V_34 * F_169 ( struct V_55 * V_84 ,
struct V_41 * * V_101 , int V_233 ,
const struct V_3 * V_4 ,
struct V_34 * V_38 )
{
struct V_35 * V_35 = V_85 ( V_84 ) ;
unsigned long V_57 = V_79 ;
struct V_268 * V_269 ;
struct V_271 * V_272 ;
struct V_34 * V_273 = NULL ;
struct V_34 * V_274 = NULL ;
int V_130 = 0 ;
int V_193 ;
int V_275 = 0 ;
int V_266 = 0 ;
int V_276 = 0 ;
int V_36 ;
int V_28 = V_84 -> V_124 . V_28 ;
T_1 V_12 , V_9 ;
F_170 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_36 = F_156 ( V_4 , V_28 ) ;
V_193 = V_36 ;
if ( V_36 < 0 )
goto V_277;
F_159 ( V_38 ) ;
for (; V_130 < V_233 ; V_130 ++ ) {
struct V_254 * V_255 = F_163 ( V_35 , V_28 ) ;
struct V_34 * V_278 = & V_255 -> V_7 . V_38 ;
V_193 = F_171 ( V_255 ) ;
if ( F_18 ( V_255 ) ) {
F_172 ( V_38 ) ;
goto V_277;
}
if ( V_101 [ V_130 ] -> V_2 . V_28 == V_279 ) {
V_272 = F_173 ( V_101 [ V_130 ] ,
F_174 ( V_28 ) ) ;
if ( ! V_272 ) {
V_193 = - V_39 ;
F_172 ( V_38 ) ;
goto V_277;
}
} else
V_272 = V_101 [ V_130 ] -> V_272 ;
if ( ! V_273 )
V_274 = V_278 ;
else {
V_273 -> V_280 = F_175 ( V_278 ) ;
V_278 -> V_47 |= V_281 ;
}
V_255 -> V_256 = V_38 ;
F_176 ( V_278 , V_38 ) ;
if ( V_101 [ V_130 ] -> V_45 . V_235 != V_282 ) {
V_28 = V_101 [ V_130 ] -> V_45 . V_28 ;
V_38 = F_16 ( V_101 [ V_130 ] , V_36 , V_4 -> V_239 ,
& V_12 , & V_9 , V_28 ) ;
V_193 = F_171 ( V_38 ) ;
if ( F_18 ( V_38 ) )
goto V_277;
} else
F_159 ( V_38 ) ;
V_278 -> V_101 = V_101 [ V_130 ] ;
V_255 -> V_283 = V_101 [ V_130 ] -> V_100 ;
V_278 -> V_284 = V_285 ;
V_278 -> V_47 |= V_286 ;
V_278 -> V_287 = V_57 ;
V_278 -> V_288 = V_289 ;
V_278 -> V_290 = V_272 -> V_32 -> V_290 ;
V_278 -> V_58 = V_273 ;
V_273 = V_278 ;
V_275 += V_101 [ V_130 ] -> V_45 . V_275 ;
if ( V_101 [ V_130 ] -> type -> V_47 & V_291 )
V_266 += V_101 [ V_130 ] -> V_45 . V_275 ;
V_276 += V_101 [ V_130 ] -> V_45 . V_276 ;
}
V_273 -> V_280 = V_38 ;
V_274 -> V_265 = V_38 ;
V_193 = - V_292 ;
V_269 = V_38 -> V_269 ;
if ( ! V_269 )
goto V_293;
F_167 ( (struct V_254 * ) V_274 , V_38 , V_266 ) ;
F_177 ( V_273 ) ;
for ( V_273 = V_274 ; V_273 != V_38 ; V_273 = V_273 -> V_280 ) {
struct V_254 * V_255 = (struct V_254 * ) V_273 ;
V_193 = F_168 ( V_255 , V_269 , V_4 ) ;
if ( V_193 )
goto V_293;
V_273 -> V_275 = V_275 ;
V_273 -> V_276 = V_276 ;
V_275 -= V_255 -> V_7 . V_38 . V_101 -> V_45 . V_275 ;
V_276 -= V_255 -> V_7 . V_38 . V_101 -> V_45 . V_276 ;
}
V_65:
return V_274 ;
V_277:
for (; V_130 < V_233 ; V_130 ++ )
F_153 ( V_101 [ V_130 ] ) ;
V_293:
if ( V_274 )
F_162 ( V_274 ) ;
V_274 = F_15 ( V_193 ) ;
goto V_65;
}
static int F_178 ( void * * V_294 , const void * V_295 , int V_296 )
{
if ( ! * V_294 ) {
* V_294 = F_179 ( V_296 , V_222 ) ;
if ( ! * V_294 )
return - V_229 ;
}
memcpy ( * V_294 , V_295 , V_296 ) ;
return 0 ;
}
static int F_180 ( struct V_34 * V_38 ,
const struct V_1 * V_2 )
{
#ifdef F_130
struct V_254 * V_255 = (struct V_254 * ) V_38 ;
return F_178 ( ( void * * ) & ( V_255 -> V_297 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int F_181 ( struct V_34 * V_38 ,
const struct V_3 * V_4 )
{
#ifdef F_130
struct V_254 * V_255 = (struct V_254 * ) V_38 ;
return F_178 ( ( void * * ) & ( V_255 -> V_298 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_182 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_55 * * V_246 ,
int * V_299 , int * V_257 )
{
int V_130 ;
if ( * V_299 == 0 || ! V_246 [ 0 ] ) {
* V_299 = 0 ;
* V_257 = 0 ;
return 0 ;
}
if ( F_18 ( V_246 [ 0 ] ) )
return F_171 ( V_246 [ 0 ] ) ;
* V_257 = V_246 [ 0 ] -> V_224 ;
#ifdef F_130
if ( V_246 [ 0 ] && V_246 [ 0 ] -> V_223 == V_300 &&
V_246 [ 0 ] -> type != V_210 ) {
V_246 [ 1 ] = F_126 ( V_85 ( V_246 [ 0 ] ) ,
V_210 ,
V_4 , V_28 ,
V_144 ) ;
if ( V_246 [ 1 ] ) {
if ( F_18 ( V_246 [ 1 ] ) ) {
F_183 ( V_246 , * V_299 ) ;
return F_171 ( V_246 [ 1 ] ) ;
}
( * V_299 ) ++ ;
( * V_257 ) += V_246 [ 1 ] -> V_224 ;
}
}
#endif
for ( V_130 = 0 ; V_130 < * V_299 ; V_130 ++ ) {
if ( V_246 [ V_130 ] -> V_223 != V_300 ) {
* V_257 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_254 *
F_184 ( struct V_55 * * V_246 , int V_299 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_34 * V_301 )
{
struct V_35 * V_35 = V_85 ( V_246 [ 0 ] ) ;
struct V_41 * V_101 [ V_249 ] ;
struct V_34 * V_38 ;
struct V_254 * V_255 ;
int V_193 ;
V_193 = F_154 ( V_246 , V_299 , V_4 , V_101 , V_28 ) ;
if ( V_193 <= 0 ) {
if ( V_193 != 0 && V_193 != - V_244 )
F_185 ( V_35 , V_302 ) ;
return F_15 ( V_193 ) ;
}
V_38 = F_169 ( V_246 [ 0 ] , V_101 , V_193 , V_4 , V_301 ) ;
if ( F_18 ( V_38 ) ) {
F_185 ( V_35 , V_303 ) ;
return F_134 ( V_38 ) ;
}
V_255 = (struct V_254 * ) V_38 ;
V_255 -> V_257 = V_193 ;
if ( V_299 > 1 )
V_193 = F_180 ( V_38 , & V_246 [ 1 ] -> V_124 ) ;
else
V_193 = F_181 ( V_38 , V_4 ) ;
if ( F_9 ( V_193 ) ) {
F_162 ( V_38 ) ;
F_185 ( V_35 , V_304 ) ;
return F_15 ( V_193 ) ;
}
V_255 -> V_299 = V_299 ;
memcpy ( V_255 -> V_246 , V_246 , sizeof( struct V_55 * ) * V_299 ) ;
V_255 -> V_305 = F_186 ( & V_246 [ 0 ] -> V_100 ) ;
return V_255 ;
}
static void V_93 ( unsigned long V_306 )
{
struct V_307 * V_308 ;
struct V_215 * V_216 ;
struct V_34 * V_38 ;
struct V_55 * V_82 = (struct V_55 * ) V_306 ;
struct V_35 * V_35 = V_85 ( V_82 ) ;
struct V_178 * V_179 = & V_82 -> V_90 ;
struct V_3 V_4 ;
struct V_180 V_115 ;
F_187 ( & V_179 -> V_91 . V_62 ) ;
V_308 = F_188 ( & V_179 -> V_91 ) ;
if ( ! V_308 ) {
F_189 ( & V_179 -> V_91 . V_62 ) ;
goto V_65;
}
V_38 = F_190 ( V_308 ) ;
V_216 = V_308 -> V_216 ;
F_191 ( V_308 , & V_4 , V_38 -> V_94 -> V_28 ) ;
F_189 ( & V_179 -> V_91 . V_62 ) ;
F_159 ( V_38 -> V_265 ) ;
V_38 = F_192 ( V_35 , V_38 -> V_265 , & V_4 , V_216 , 0 ) ;
if ( F_18 ( V_38 ) )
goto V_309;
if ( V_38 -> V_47 & V_258 ) {
F_172 ( V_38 ) ;
if ( V_179 -> V_181 >= V_310 )
goto V_309;
V_179 -> V_181 = V_179 -> V_181 << 1 ;
if ( ! F_25 ( & V_179 -> V_92 , V_79 + V_179 -> V_181 ) )
F_26 ( V_82 ) ;
goto V_65;
}
F_172 ( V_38 ) ;
F_95 ( & V_115 ) ;
F_187 ( & V_179 -> V_91 . V_62 ) ;
V_179 -> V_181 = 0 ;
F_97 ( & V_179 -> V_91 , & V_115 ) ;
F_189 ( & V_179 -> V_91 . V_62 ) ;
while ( ! F_94 ( & V_115 ) ) {
V_308 = F_193 ( & V_115 ) ;
F_191 ( V_308 , & V_4 , F_190 ( V_308 ) -> V_94 -> V_28 ) ;
F_159 ( F_190 ( V_308 ) -> V_265 ) ;
V_38 = F_192 ( V_35 , F_190 ( V_308 ) -> V_265 , & V_4 , V_308 -> V_216 , 0 ) ;
if ( F_18 ( V_38 ) ) {
F_194 ( V_308 ) ;
continue;
}
F_195 ( V_308 ) ;
F_196 ( V_308 ) ;
F_197 ( V_308 , V_38 ) ;
F_198 ( V_35 , V_308 -> V_216 , V_308 ) ;
}
V_65:
F_28 ( V_82 ) ;
return;
V_309:
V_179 -> V_181 = 0 ;
F_53 ( & V_179 -> V_91 ) ;
F_28 ( V_82 ) ;
}
static int F_199 ( struct V_35 * V_35 , struct V_215 * V_216 , struct V_307 * V_308 )
{
unsigned long V_311 ;
struct V_34 * V_38 = F_190 ( V_308 ) ;
struct V_254 * V_255 = (struct V_254 * ) V_38 ;
struct V_55 * V_82 = V_255 -> V_246 [ 0 ] ;
struct V_178 * V_179 = & V_82 -> V_90 ;
if ( F_9 ( F_200 ( V_216 , V_308 ) ) ) {
F_194 ( V_308 ) ;
return 0 ;
}
if ( V_179 -> V_91 . V_312 > V_313 ) {
F_194 ( V_308 ) ;
return - V_244 ;
}
F_201 ( V_308 ) ;
F_96 ( & V_179 -> V_91 . V_62 ) ;
if ( ! V_179 -> V_181 )
V_179 -> V_181 = V_182 ;
V_311 = V_79 + V_179 -> V_181 ;
if ( F_48 ( & V_179 -> V_92 ) ) {
if ( F_202 ( V_179 -> V_92 . V_314 , V_311 ) )
V_311 = V_179 -> V_92 . V_314 ;
F_28 ( V_82 ) ;
}
F_203 ( & V_179 -> V_91 , V_308 ) ;
if ( ! F_25 ( & V_179 -> V_92 , V_311 ) )
F_26 ( V_82 ) ;
F_98 ( & V_179 -> V_91 . V_62 ) ;
return 0 ;
}
static struct V_254 * F_204 ( struct V_35 * V_35 ,
struct V_315 * V_316 ,
const struct V_3 * V_4 ,
int V_257 ,
T_5 V_28 )
{
int V_193 ;
struct V_268 * V_269 ;
struct V_34 * V_38 ;
struct V_34 * V_278 ;
struct V_254 * V_255 ;
V_255 = F_163 ( V_35 , V_28 ) ;
if ( F_18 ( V_255 ) )
return V_255 ;
if ( ! ( V_316 -> V_47 & V_317 ) ||
V_35 -> V_101 . V_318 ||
V_257 <= 0 )
return V_255 ;
V_38 = V_316 -> V_301 ;
V_278 = & V_255 -> V_7 . V_38 ;
F_159 ( V_38 ) ;
V_255 -> V_256 = V_38 ;
F_176 ( V_278 , V_38 ) ;
V_278 -> V_284 = V_285 ;
V_278 -> V_47 |= V_286 | V_258 ;
V_278 -> V_287 = V_79 ;
V_278 -> V_288 = V_289 ;
V_278 -> V_290 = F_199 ;
F_159 ( V_38 ) ;
V_278 -> V_280 = V_38 ;
V_278 -> V_265 = V_38 ;
F_167 ( (struct V_254 * ) V_278 , V_38 , 0 ) ;
V_193 = - V_292 ;
V_269 = V_38 -> V_269 ;
if ( ! V_269 )
goto V_293;
V_193 = F_168 ( V_255 , V_269 , V_4 ) ;
if ( V_193 )
goto V_293;
V_65:
return V_255 ;
V_293:
F_172 ( V_278 ) ;
V_255 = F_15 ( V_193 ) ;
goto V_65;
}
static struct V_80 *
F_205 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_61 ,
struct V_80 * V_319 , void * V_191 )
{
struct V_315 * V_316 = (struct V_315 * ) V_191 ;
struct V_55 * V_246 [ V_201 ] ;
struct V_254 * V_255 , * V_320 ;
int V_299 = 0 , V_257 = 0 , V_130 , V_193 , V_321 ;
V_255 = NULL ;
if ( V_319 ) {
V_255 = F_31 ( V_319 , struct V_254 , V_81 ) ;
V_299 = V_255 -> V_299 ;
V_257 = V_255 -> V_257 ;
V_321 = 0 ;
for ( V_130 = 0 ; V_130 < V_299 ; V_130 ++ ) {
V_246 [ V_130 ] = V_255 -> V_246 [ V_130 ] ;
V_321 |= V_246 [ V_130 ] -> V_63 . V_64 ;
}
if ( V_321 ) {
F_162 ( & V_255 -> V_7 . V_38 ) ;
V_255 = NULL ;
V_299 = 0 ;
V_257 = 0 ;
V_319 = NULL ;
}
}
if ( V_255 == NULL ) {
V_299 = 1 ;
V_246 [ 0 ] = F_129 ( V_35 , V_4 , V_28 ,
F_131 ( V_61 ) ) ;
V_193 = F_182 ( V_4 , V_28 , V_246 ,
& V_299 , & V_257 ) ;
if ( V_193 < 0 )
goto V_322;
if ( V_299 == 0 )
return NULL ;
if ( V_257 <= 0 )
goto V_323;
}
V_320 = F_184 ( V_246 , V_299 , V_4 , V_28 ,
V_316 -> V_301 ) ;
if ( F_18 ( V_320 ) ) {
V_193 = F_171 ( V_320 ) ;
if ( V_193 != - V_244 )
goto error;
if ( V_319 == NULL )
goto V_323;
F_159 ( & V_255 -> V_7 . V_38 ) ;
return V_319 ;
} else if ( V_320 == NULL ) {
V_257 = 0 ;
if ( V_319 == NULL )
goto V_323;
V_255 -> V_257 = 0 ;
F_159 ( & V_255 -> V_7 . V_38 ) ;
return V_319 ;
}
if ( V_255 ) {
V_255 -> V_299 = 0 ;
F_162 ( & V_255 -> V_7 . V_38 ) ;
}
F_159 ( & V_320 -> V_7 . V_38 ) ;
return & V_320 -> V_81 ;
V_323:
V_255 = F_204 ( V_35 , V_316 , V_4 , V_257 , V_28 ) ;
if ( F_18 ( V_255 ) ) {
F_183 ( V_246 , V_299 ) ;
return F_134 ( V_255 ) ;
}
V_255 -> V_299 = V_299 ;
V_255 -> V_257 = V_257 ;
memcpy ( V_255 -> V_246 , V_246 , sizeof( struct V_55 * ) * V_299 ) ;
F_159 ( & V_255 -> V_7 . V_38 ) ;
return & V_255 -> V_81 ;
V_322:
F_185 ( V_35 , V_302 ) ;
error:
if ( V_255 != NULL )
F_162 ( & V_255 -> V_7 . V_38 ) ;
else
F_183 ( V_246 , V_299 ) ;
return F_15 ( V_193 ) ;
}
static struct V_34 * F_206 ( struct V_35 * V_35 , T_5 V_28 ,
struct V_34 * V_301 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_34 * V_194 ;
if ( ! V_32 ) {
F_172 ( V_301 ) ;
return F_15 ( - V_203 ) ;
} else {
V_194 = V_32 -> V_324 ( V_35 , V_301 ) ;
}
F_13 ( V_32 ) ;
return V_194 ;
}
struct V_34 * F_192 ( struct V_35 * V_35 , struct V_34 * V_301 ,
const struct V_3 * V_4 ,
const struct V_215 * V_216 , int V_47 )
{
struct V_55 * V_246 [ V_201 ] ;
struct V_80 * V_81 ;
struct V_254 * V_255 ;
struct V_34 * V_38 , * V_256 ;
T_5 V_28 = V_301 -> V_94 -> V_28 ;
T_4 V_61 = F_135 ( V_144 ) ;
int V_130 , V_193 , V_299 , V_257 = 0 , V_325 = 0 ;
V_38 = NULL ;
V_255 = NULL ;
V_256 = NULL ;
V_216 = F_207 ( V_216 ) ;
if ( V_216 && V_216 -> V_217 [ V_144 ] ) {
V_299 = 1 ;
V_246 [ 0 ] = F_136 ( V_216 , V_144 , V_4 ) ;
V_193 = F_182 ( V_4 , V_28 , V_246 ,
& V_299 , & V_257 ) ;
if ( V_193 < 0 )
goto V_326;
if ( V_299 ) {
if ( V_257 <= 0 ) {
V_325 = V_299 ;
goto V_327;
}
V_255 = F_184 (
V_246 , V_299 , V_4 ,
V_28 , V_301 ) ;
if ( F_18 ( V_255 ) ) {
F_183 ( V_246 , V_299 ) ;
V_193 = F_171 ( V_255 ) ;
goto V_326;
} else if ( V_255 == NULL ) {
V_257 = 0 ;
V_325 = V_299 ;
goto V_327;
}
F_159 ( & V_255 -> V_7 . V_38 ) ;
V_255 -> V_7 . V_38 . V_47 |= V_328 ;
V_256 = V_255 -> V_256 ;
}
}
if ( V_255 == NULL ) {
struct V_315 V_316 ;
V_316 . V_301 = V_301 ;
V_316 . V_47 = V_47 ;
if ( ( V_301 -> V_47 & V_329 ) ||
! V_35 -> V_101 . V_137 [ V_144 ] )
goto V_330;
V_81 = F_208 ( V_35 , V_4 , V_28 , V_61 ,
F_205 , & V_316 ) ;
if ( V_81 == NULL )
goto V_330;
if ( F_18 ( V_81 ) ) {
V_193 = F_171 ( V_81 ) ;
goto V_326;
}
V_255 = F_31 ( V_81 , struct V_254 , V_81 ) ;
V_299 = V_255 -> V_299 ;
V_257 = V_255 -> V_257 ;
memcpy ( V_246 , V_255 -> V_246 , sizeof( struct V_55 * ) * V_299 ) ;
V_256 = V_255 -> V_256 ;
}
V_38 = & V_255 -> V_7 . V_38 ;
if ( V_256 == NULL && V_257 > 0 ) {
if ( V_35 -> V_101 . V_318 ) {
F_185 ( V_35 , V_331 ) ;
V_193 = - V_332 ;
goto error;
}
V_193 = - V_244 ;
F_185 ( V_35 , V_331 ) ;
goto error;
}
V_327:
if ( V_299 == 0 )
goto V_330;
if ( ( V_47 & V_333 ) &&
! ( V_246 [ 0 ] -> V_47 & V_334 ) ) {
V_193 = - V_195 ;
goto error;
}
for ( V_130 = 0 ; V_130 < V_299 ; V_130 ++ )
V_246 [ V_130 ] -> V_70 . V_74 = F_21 () ;
if ( V_257 < 0 ) {
F_185 ( V_35 , V_335 ) ;
V_193 = - V_336 ;
goto error;
} else if ( V_257 > 0 ) {
F_172 ( V_301 ) ;
} else {
F_172 ( V_38 ) ;
V_38 = V_301 ;
}
V_337:
F_183 ( V_246 , V_325 ) ;
if ( V_38 && V_38 -> V_101 &&
V_38 -> V_101 -> V_45 . V_235 == V_236 )
V_38 -> V_47 |= V_338 ;
return V_38 ;
V_330:
if ( ! ( V_47 & V_333 ) ) {
V_38 = V_301 ;
goto V_337;
}
V_193 = - V_195 ;
error:
F_172 ( V_38 ) ;
V_326:
if ( ! ( V_47 & V_339 ) )
F_172 ( V_301 ) ;
F_183 ( V_246 , V_325 ) ;
return F_15 ( V_193 ) ;
}
struct V_34 * F_209 ( struct V_35 * V_35 , struct V_34 * V_301 ,
const struct V_3 * V_4 ,
const struct V_215 * V_216 , int V_47 )
{
struct V_34 * V_38 = F_192 ( V_35 , V_301 , V_4 , V_216 ,
V_47 | V_317 |
V_339 ) ;
if ( F_18 ( V_38 ) && F_171 ( V_38 ) == - V_332 )
return F_206 ( V_35 , V_301 -> V_94 -> V_28 , V_301 ) ;
return V_38 ;
}
static inline int
F_210 ( int V_169 , struct V_307 * V_308 , const struct V_3 * V_4 )
{
struct V_41 * V_42 ;
if ( ! V_308 -> V_340 || V_169 < 0 || V_169 >= V_308 -> V_340 -> V_175 )
return 0 ;
V_42 = V_308 -> V_340 -> V_341 [ V_169 ] ;
if ( ! V_42 -> type -> V_342 )
return 0 ;
return V_42 -> type -> V_342 ( V_42 , V_308 , V_4 ) ;
}
static inline int
F_211 ( const struct V_226 * V_234 , const struct V_41 * V_42 ,
unsigned short V_28 )
{
if ( F_212 ( V_42 ) )
return V_234 -> V_245 && ! F_213 ( V_234 , V_42 , V_234 -> V_238 ) ;
return V_42 -> V_46 . V_20 == V_234 -> V_46 . V_20 &&
( V_42 -> V_46 . V_343 == V_234 -> V_46 . V_343 || ! V_234 -> V_46 . V_343 ) &&
( V_42 -> V_45 . V_344 == V_234 -> V_344 || ! V_234 -> V_344 ) &&
V_42 -> V_45 . V_235 == V_234 -> V_235 &&
( V_234 -> V_345 || ( V_234 -> V_346 & ( 1 << V_42 -> V_45 . V_347 ) ) ||
! ( F_214 ( V_234 -> V_46 . V_20 , V_348 ) ) ) &&
! ( V_42 -> V_45 . V_235 != V_282 &&
F_213 ( V_234 , V_42 , V_28 ) ) ;
}
static inline int
F_215 ( const struct V_226 * V_234 , const struct V_349 * V_340 , int V_350 ,
unsigned short V_28 )
{
int V_169 = V_350 ;
if ( V_234 -> V_245 ) {
if ( V_234 -> V_235 == V_282 )
return V_350 ;
} else
V_350 = - 1 ;
for (; V_169 < V_340 -> V_175 ; V_169 ++ ) {
if ( F_211 ( V_234 , V_340 -> V_341 [ V_169 ] , V_28 ) )
return ++ V_169 ;
if ( V_340 -> V_341 [ V_169 ] -> V_45 . V_235 != V_282 ) {
if ( V_350 == - 1 )
V_350 = - 2 - V_169 ;
break;
}
}
return V_350 ;
}
int F_216 ( struct V_307 * V_308 , struct V_3 * V_4 ,
unsigned int V_28 , int V_351 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_193 ;
if ( F_9 ( V_32 == NULL ) )
return - V_39 ;
V_32 -> V_352 ( V_308 , V_4 , V_351 ) ;
V_193 = F_217 ( V_308 , & V_4 -> V_207 ) ;
F_13 ( V_32 ) ;
return V_193 ;
}
static inline int F_218 ( const struct V_349 * V_340 , int V_353 , int * V_354 )
{
for (; V_353 < V_340 -> V_175 ; V_353 ++ ) {
if ( V_340 -> V_341 [ V_353 ] -> V_45 . V_235 != V_282 ) {
* V_354 = V_353 ;
return 1 ;
}
}
return 0 ;
}
int F_219 ( struct V_215 * V_216 , int V_61 , struct V_307 * V_308 ,
unsigned short V_28 )
{
struct V_35 * V_35 = F_220 ( V_308 -> V_269 ) ;
struct V_55 * V_82 ;
struct V_55 * V_246 [ V_201 ] ;
int V_247 = 0 ;
int V_224 ;
int V_355 ;
int V_351 ;
struct V_3 V_4 ;
T_4 V_356 ;
int V_357 = - 1 ;
V_351 = V_61 & ~ V_165 ;
V_61 &= V_165 ;
V_356 = F_135 ( V_61 ) ;
if ( F_216 ( V_308 , & V_4 , V_28 , V_351 ) < 0 ) {
F_185 ( V_35 , V_358 ) ;
return 0 ;
}
F_221 ( V_308 , & V_4 , V_28 ) ;
if ( V_308 -> V_340 ) {
int V_130 ;
for ( V_130 = V_308 -> V_340 -> V_175 - 1 ; V_130 >= 0 ; V_130 -- ) {
struct V_41 * V_42 = V_308 -> V_340 -> V_341 [ V_130 ] ;
if ( ! F_7 ( & V_42 -> V_2 , & V_4 , V_28 ) ) {
F_185 ( V_35 , V_359 ) ;
return 0 ;
}
}
}
V_82 = NULL ;
V_216 = F_222 ( V_216 ) ;
if ( V_216 && V_216 -> V_217 [ V_61 ] ) {
V_82 = F_136 ( V_216 , V_61 , & V_4 ) ;
if ( F_18 ( V_82 ) ) {
F_185 ( V_35 , V_360 ) ;
return 0 ;
}
}
if ( ! V_82 ) {
struct V_80 * V_81 ;
V_81 = F_208 ( V_35 , & V_4 , V_28 , V_356 ,
F_132 , NULL ) ;
if ( F_133 ( V_81 ) )
V_82 = F_134 ( V_81 ) ;
else
V_82 = F_31 ( V_81 , struct V_55 , V_81 ) ;
}
if ( F_18 ( V_82 ) ) {
F_185 ( V_35 , V_360 ) ;
return 0 ;
}
if ( ! V_82 ) {
if ( V_308 -> V_340 && F_218 ( V_308 -> V_340 , 0 , & V_357 ) ) {
F_210 ( V_357 , V_308 , & V_4 ) ;
F_185 ( V_35 , V_361 ) ;
return 0 ;
}
return 1 ;
}
V_82 -> V_70 . V_74 = F_21 () ;
V_246 [ 0 ] = V_82 ;
V_247 ++ ;
#ifdef F_130
if ( V_246 [ 0 ] -> type != V_210 ) {
V_246 [ 1 ] = F_126 ( V_35 , V_210 ,
& V_4 , V_28 ,
V_142 ) ;
if ( V_246 [ 1 ] ) {
if ( F_18 ( V_246 [ 1 ] ) ) {
F_185 ( V_35 , V_360 ) ;
return 0 ;
}
V_246 [ 1 ] -> V_70 . V_74 = F_21 () ;
V_247 ++ ;
}
}
#endif
if ( V_82 -> V_223 == V_300 ) {
struct V_349 * V_340 ;
static struct V_349 V_362 ;
struct V_226 * V_248 [ V_249 ] ;
struct V_226 * V_363 [ V_249 ] ;
struct V_226 * * V_250 = V_248 ;
int V_364 = 0 ;
int V_130 , V_353 ;
if ( ( V_340 = V_308 -> V_340 ) == NULL )
V_340 = & V_362 ;
for ( V_355 = 0 ; V_355 < V_247 ; V_355 ++ ) {
if ( V_246 [ V_355 ] != V_82 &&
V_246 [ V_355 ] -> V_223 != V_300 ) {
F_185 ( V_35 , V_365 ) ;
goto V_342;
}
if ( V_364 + V_246 [ V_355 ] -> V_224 >= V_249 ) {
F_185 ( V_35 , V_366 ) ;
goto V_367;
}
for ( V_130 = 0 ; V_130 < V_246 [ V_355 ] -> V_224 ; V_130 ++ )
V_250 [ V_364 ++ ] = & V_246 [ V_355 ] -> V_225 [ V_130 ] ;
}
V_224 = V_364 ;
if ( V_247 > 1 ) {
F_223 ( V_363 , V_250 , V_224 , V_28 , V_35 ) ;
V_250 = V_363 ;
}
for ( V_130 = V_224 - 1 , V_353 = 0 ; V_130 >= 0 ; V_130 -- ) {
V_353 = F_215 ( V_250 [ V_130 ] , V_340 , V_353 , V_28 ) ;
if ( V_353 < 0 ) {
if ( V_353 < - 1 )
V_357 = - ( 2 + V_353 ) ;
F_185 ( V_35 , V_368 ) ;
goto V_342;
}
}
if ( F_218 ( V_340 , V_353 , & V_357 ) ) {
F_185 ( V_35 , V_368 ) ;
goto V_342;
}
F_183 ( V_246 , V_247 ) ;
return 1 ;
}
F_185 ( V_35 , V_365 ) ;
V_342:
F_210 ( V_357 , V_308 , & V_4 ) ;
V_367:
F_183 ( V_246 , V_247 ) ;
return 0 ;
}
int F_224 ( struct V_307 * V_308 , unsigned short V_28 )
{
struct V_35 * V_35 = F_220 ( V_308 -> V_269 ) ;
struct V_3 V_4 ;
struct V_34 * V_38 ;
int V_369 = 1 ;
if ( F_191 ( V_308 , & V_4 , V_28 ) < 0 ) {
F_185 ( V_35 , V_370 ) ;
return 0 ;
}
F_201 ( V_308 ) ;
V_38 = F_192 ( V_35 , F_190 ( V_308 ) , & V_4 , NULL , V_317 ) ;
if ( F_18 ( V_38 ) ) {
V_369 = 0 ;
V_38 = NULL ;
}
F_197 ( V_308 , V_38 ) ;
return V_369 ;
}
static struct V_34 * F_225 ( struct V_34 * V_38 , T_3 V_371 )
{
if ( V_38 -> V_284 < 0 && ! F_158 ( V_38 ) )
return V_38 ;
return NULL ;
}
static int F_158 ( struct V_34 * V_38 )
{
return ! F_226 ( (struct V_254 * ) V_38 ) ;
}
void F_227 ( struct V_34 * V_38 , struct V_268 * V_269 )
{
while ( ( V_38 = V_38 -> V_280 ) && V_38 -> V_101 && V_38 -> V_269 == V_269 ) {
V_38 -> V_269 = F_220 ( V_269 ) -> V_372 ;
F_228 ( V_38 -> V_269 ) ;
F_229 ( V_269 ) ;
}
}
static void F_230 ( struct V_307 * V_308 )
{
}
static struct V_34 * F_231 ( struct V_34 * V_38 )
{
if ( V_38 ) {
if ( V_38 -> V_284 ) {
F_172 ( V_38 ) ;
V_38 = NULL ;
}
}
return V_38 ;
}
void F_232 ( struct V_35 * V_35 )
{
F_233 ( V_35 ) ;
}
static void F_234 ( struct V_35 * V_35 )
{
F_235 ( V_35 ) ;
}
static void F_177 ( struct V_34 * V_38 )
{
do {
struct V_254 * V_255 = (struct V_254 * ) V_38 ;
T_3 V_373 , V_374 ;
V_373 = F_236 ( V_38 -> V_280 ) ;
V_255 -> V_375 = V_373 ;
V_373 = F_237 ( V_38 -> V_101 , V_373 ) ;
V_374 = F_236 ( V_255 -> V_256 ) ;
V_255 -> V_374 = V_374 ;
if ( V_373 > V_374 )
V_373 = V_374 ;
F_238 ( V_38 , V_376 , V_373 ) ;
} while ( ( V_38 = V_38 -> V_58 ) );
}
static int F_226 ( struct V_254 * V_377 )
{
struct V_34 * V_38 = & V_377 -> V_7 . V_38 ;
struct V_254 * V_378 ;
T_3 V_379 ;
if ( ! F_239 ( V_38 -> V_265 , ( (struct V_254 * ) V_38 ) -> V_380 ) ||
( V_38 -> V_269 && ! F_240 ( V_38 -> V_269 ) ) )
return 0 ;
if ( V_38 -> V_47 & V_258 )
return 1 ;
V_378 = NULL ;
do {
struct V_254 * V_255 = (struct V_254 * ) V_38 ;
if ( V_38 -> V_101 -> V_240 . V_241 != V_242 )
return 0 ;
if ( V_255 -> V_283 != V_38 -> V_101 -> V_100 )
return 0 ;
if ( V_255 -> V_299 > 0 &&
V_255 -> V_305 != F_186 ( & V_255 -> V_246 [ 0 ] -> V_100 ) )
return 0 ;
V_379 = F_236 ( V_38 -> V_280 ) ;
if ( V_255 -> V_375 != V_379 ) {
V_378 = V_255 ;
V_255 -> V_375 = V_379 ;
}
if ( ! F_239 ( V_255 -> V_256 , V_255 -> V_381 ) )
return 0 ;
V_379 = F_236 ( V_255 -> V_256 ) ;
if ( V_255 -> V_374 != V_379 ) {
V_378 = V_255 ;
V_255 -> V_374 = V_379 ;
}
V_38 = V_38 -> V_280 ;
} while ( V_38 -> V_101 );
if ( F_166 ( ! V_378 ) )
return 1 ;
V_379 = V_378 -> V_375 ;
for (; ; ) {
V_38 = & V_378 -> V_7 . V_38 ;
V_379 = F_237 ( V_38 -> V_101 , V_379 ) ;
if ( V_379 > V_378 -> V_374 )
V_379 = V_378 -> V_374 ;
F_238 ( V_38 , V_376 , V_379 ) ;
if ( V_378 == V_377 )
break;
V_378 = (struct V_254 * ) V_378 -> V_7 . V_38 . V_58 ;
V_378 -> V_375 = V_379 ;
}
return 1 ;
}
static unsigned int F_241 ( const struct V_34 * V_38 )
{
return F_242 ( V_38 -> V_265 ) ;
}
static unsigned int F_243 ( const struct V_34 * V_38 )
{
unsigned int V_379 = F_244 ( V_38 , V_376 ) ;
return V_379 ? : F_236 ( V_38 -> V_265 ) ;
}
static struct V_382 * F_245 ( const struct V_34 * V_38 ,
struct V_307 * V_308 ,
const void * V_9 )
{
return V_38 -> V_265 -> V_94 -> V_383 ( V_38 , V_308 , V_9 ) ;
}
int F_246 ( struct V_31 * V_32 )
{
int V_193 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_203 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_39 ;
F_187 ( & V_384 ) ;
if ( F_9 ( V_31 [ V_32 -> V_28 ] != NULL ) )
V_193 = - V_188 ;
else {
struct V_259 * V_259 = V_32 -> V_259 ;
if ( F_166 ( V_259 -> V_385 == NULL ) )
V_259 -> V_385 = V_386 ;
if ( F_166 ( V_259 -> V_387 == NULL ) )
V_259 -> V_387 = F_225 ;
if ( F_166 ( V_259 -> V_388 == NULL ) )
V_259 -> V_388 = F_241 ;
if ( F_166 ( V_259 -> V_379 == NULL ) )
V_259 -> V_379 = F_243 ;
if ( F_166 ( V_259 -> V_389 == NULL ) )
V_259 -> V_389 = F_231 ;
if ( F_166 ( V_259 -> V_390 == NULL ) )
V_259 -> V_390 = F_230 ;
if ( F_166 ( V_259 -> V_383 == NULL ) )
V_259 -> V_383 = F_245 ;
if ( F_166 ( V_32 -> V_391 == NULL ) )
V_32 -> V_391 = F_234 ;
F_145 ( V_31 [ V_32 -> V_28 ] , V_32 ) ;
}
F_189 ( & V_384 ) ;
return V_193 ;
}
int F_247 ( struct V_31 * V_32 )
{
int V_193 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_203 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_39 ;
F_187 ( & V_384 ) ;
if ( F_166 ( V_31 [ V_32 -> V_28 ] != NULL ) ) {
if ( F_9 ( V_31 [ V_32 -> V_28 ] != V_32 ) )
V_193 = - V_203 ;
else
F_248 ( V_31 [ V_32 -> V_28 ] ,
NULL ) ;
}
F_189 ( & V_384 ) ;
if ( ! V_193 ) {
struct V_259 * V_259 = V_32 -> V_259 ;
F_249 () ;
V_259 -> V_385 = NULL ;
V_259 -> V_387 = NULL ;
V_259 -> V_389 = NULL ;
V_259 -> V_390 = NULL ;
V_32 -> V_391 = NULL ;
}
return V_193 ;
}
static int F_250 ( struct V_392 * V_393 , unsigned long V_394 , void * V_395 )
{
struct V_268 * V_269 = F_251 ( V_395 ) ;
switch ( V_394 ) {
case V_396 :
F_232 ( F_220 ( V_269 ) ) ;
}
return V_397 ;
}
static int T_6 F_252 ( struct V_35 * V_35 )
{
int V_398 ;
V_35 -> V_399 . V_400 = F_253 ( struct V_401 ) ;
if ( ! V_35 -> V_399 . V_400 )
return - V_229 ;
V_398 = F_254 ( V_35 ) ;
if ( V_398 < 0 )
F_255 ( V_35 -> V_399 . V_400 ) ;
return V_398 ;
}
static void F_256 ( struct V_35 * V_35 )
{
F_257 ( V_35 ) ;
F_255 ( V_35 -> V_399 . V_400 ) ;
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
unsigned int V_111 , V_402 ;
int V_61 ;
if ( F_259 ( V_35 , & V_403 ) )
V_386 = F_260 ( L_1 ,
sizeof( struct V_254 ) ,
0 , V_404 | V_405 ,
NULL ) ;
V_111 = 8 - 1 ;
V_402 = ( V_111 + 1 ) * sizeof( struct V_110 ) ;
V_35 -> V_101 . V_134 = F_70 ( V_402 ) ;
if ( ! V_35 -> V_101 . V_134 )
goto V_406;
V_35 -> V_101 . V_102 = V_111 ;
for ( V_61 = 0 ; V_61 < V_148 ; V_61 ++ ) {
struct V_407 * V_408 ;
V_35 -> V_101 . V_137 [ V_61 ] = 0 ;
V_35 -> V_101 . V_137 [ V_148 + V_61 ] = 0 ;
F_86 ( & V_35 -> V_101 . V_113 [ V_61 ] ) ;
V_408 = & V_35 -> V_101 . V_105 [ V_61 ] ;
V_408 -> V_114 = F_70 ( V_402 ) ;
if ( ! V_408 -> V_114 )
goto V_409;
V_408 -> V_111 = V_111 ;
V_408 -> V_106 = 32 ;
V_408 -> V_107 = 32 ;
V_408 -> V_108 = 128 ;
V_408 -> V_109 = 128 ;
}
V_35 -> V_101 . V_157 . V_161 = 32 ;
V_35 -> V_101 . V_157 . V_162 = 32 ;
V_35 -> V_101 . V_157 . V_163 = 128 ;
V_35 -> V_101 . V_157 . V_164 = 128 ;
F_261 ( & V_35 -> V_101 . V_157 . V_62 ) ;
F_37 ( & V_35 -> V_101 . V_204 ) ;
F_262 ( & V_35 -> V_101 . V_155 , F_80 ) ;
F_262 ( & V_35 -> V_101 . V_157 . V_154 , F_83 ) ;
if ( F_259 ( V_35 , & V_403 ) )
F_263 ( & V_410 ) ;
return 0 ;
V_409:
for ( V_61 -- ; V_61 >= 0 ; V_61 -- ) {
struct V_407 * V_408 ;
V_408 = & V_35 -> V_101 . V_105 [ V_61 ] ;
F_73 ( V_408 -> V_114 , V_402 ) ;
}
F_73 ( V_35 -> V_101 . V_134 , V_402 ) ;
V_406:
return - V_229 ;
}
static void F_264 ( struct V_35 * V_35 )
{
unsigned int V_402 ;
int V_61 ;
F_265 ( & V_35 -> V_101 . V_155 ) ;
#ifdef F_130
F_113 ( V_35 , V_209 , false ) ;
#endif
F_113 ( V_35 , V_210 , false ) ;
F_103 ( ! F_116 ( & V_35 -> V_101 . V_204 ) ) ;
for ( V_61 = 0 ; V_61 < V_148 ; V_61 ++ ) {
struct V_407 * V_408 ;
F_103 ( ! F_66 ( & V_35 -> V_101 . V_113 [ V_61 ] ) ) ;
V_408 = & V_35 -> V_101 . V_105 [ V_61 ] ;
V_402 = ( V_408 -> V_111 + 1 ) * sizeof( struct V_110 ) ;
F_103 ( ! F_66 ( V_408 -> V_114 ) ) ;
F_73 ( V_408 -> V_114 , V_402 ) ;
}
V_402 = ( V_35 -> V_101 . V_102 + 1 ) * sizeof( struct V_110 ) ;
F_103 ( ! F_66 ( V_35 -> V_101 . V_134 ) ) ;
F_73 ( V_35 -> V_101 . V_134 , V_402 ) ;
}
static int T_6 F_266 ( struct V_35 * V_35 )
{
int V_398 ;
V_398 = F_252 ( V_35 ) ;
if ( V_398 < 0 )
goto V_411;
V_398 = F_267 ( V_35 ) ;
if ( V_398 < 0 )
goto V_412;
V_398 = F_258 ( V_35 ) ;
if ( V_398 < 0 )
goto V_413;
V_398 = F_268 ( V_35 ) ;
if ( V_398 < 0 )
goto V_414;
V_398 = F_269 ( V_35 ) ;
if ( V_398 < 0 )
goto V_65;
F_270 ( & V_35 -> V_101 . V_415 ) ;
F_39 ( & V_35 -> V_101 . V_131 ) ;
F_271 ( & V_35 -> V_101 . V_416 ) ;
return 0 ;
V_65:
F_272 ( V_35 ) ;
V_414:
F_264 ( V_35 ) ;
V_413:
F_273 ( V_35 ) ;
V_412:
F_256 ( V_35 ) ;
V_411:
return V_398 ;
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
F_277 ( & V_417 ) ;
F_278 () ;
}
static void F_279 ( struct V_55 * V_56 ,
struct V_418 * V_419 )
{
struct V_190 * V_191 = V_56 -> V_99 ;
struct V_1 * V_2 = & V_56 -> V_124 ;
if ( V_191 )
F_280 ( V_419 , L_2 ,
V_191 -> V_420 , V_191 -> V_421 , V_191 -> V_422 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_280 ( V_419 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_280 ( V_419 , L_4 ,
V_2 -> V_13 ) ;
F_280 ( V_419 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_280 ( V_419 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_280 ( V_419 , L_7 , V_2 -> V_12 . V_423 ) ;
if ( V_2 -> V_13 != 128 )
F_280 ( V_419 , L_4 ,
V_2 -> V_13 ) ;
F_280 ( V_419 , L_8 , V_2 -> V_9 . V_423 ) ;
if ( V_2 -> V_11 != 128 )
F_280 ( V_419 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_281 ( struct V_55 * V_56 , int V_424 , bool V_196 )
{
struct V_418 * V_419 ;
V_419 = F_282 ( L_9 ) ;
if ( V_419 == NULL )
return;
F_283 ( V_196 , V_419 ) ;
F_280 ( V_419 , L_10 , V_424 ) ;
F_279 ( V_56 , V_419 ) ;
F_284 ( V_419 ) ;
}
void F_112 ( struct V_55 * V_56 , int V_424 ,
bool V_196 )
{
struct V_418 * V_419 ;
V_419 = F_282 ( L_11 ) ;
if ( V_419 == NULL )
return;
F_283 ( V_196 , V_419 ) ;
F_280 ( V_419 , L_10 , V_424 ) ;
F_279 ( V_56 , V_419 ) ;
F_284 ( V_419 ) ;
}
static bool F_285 ( const struct V_1 * V_425 ,
const struct V_1 * V_426 )
{
if ( V_425 -> V_20 == V_427 ) {
if ( V_426 -> V_28 == V_425 -> V_28 &&
F_286 ( & V_426 -> V_9 , & V_425 -> V_9 ,
V_425 -> V_28 ) &&
F_286 ( & V_426 -> V_12 , & V_425 -> V_12 ,
V_425 -> V_28 ) &&
V_426 -> V_11 == V_425 -> V_11 &&
V_426 -> V_13 == V_425 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_426 , V_425 , sizeof( * V_426 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_55 * F_287 ( const struct V_1 * V_2 ,
T_4 V_61 , T_4 type , struct V_35 * V_35 )
{
struct V_55 * V_82 , * V_194 = NULL ;
struct V_110 * V_158 ;
T_3 V_166 = ~ 0U ;
F_78 ( & V_35 -> V_101 . V_131 ) ;
V_158 = F_59 ( V_35 , & V_2 -> V_9 , & V_2 -> V_12 , V_2 -> V_28 , V_61 ) ;
F_88 (pol, chain, bydst) {
if ( F_285 ( V_2 , & V_82 -> V_124 ) &&
V_82 -> type == type ) {
V_194 = V_82 ;
V_166 = V_194 -> V_166 ;
break;
}
}
V_158 = & V_35 -> V_101 . V_113 [ V_61 ] ;
F_88 (pol, chain, bydst) {
if ( ( V_82 -> V_166 >= V_166 ) && V_194 )
break;
if ( F_285 ( V_2 , & V_82 -> V_124 ) &&
V_82 -> type == type ) {
V_194 = V_82 ;
break;
}
}
F_26 ( V_194 ) ;
F_79 ( & V_35 -> V_101 . V_131 ) ;
return V_194 ;
}
static int F_288 ( const struct V_428 * V_185 , const struct V_226 * V_429 )
{
int V_205 = 0 ;
if ( V_429 -> V_235 == V_185 -> V_235 && V_429 -> V_46 . V_20 == V_185 -> V_20 &&
( V_185 -> V_344 == 0 || V_429 -> V_344 == V_185 -> V_344 ) ) {
switch ( V_429 -> V_235 ) {
case V_236 :
case V_237 :
if ( F_286 ( & V_429 -> V_46 . V_9 , & V_185 -> V_430 ,
V_185 -> V_431 ) &&
F_286 ( & V_429 -> V_12 , & V_185 -> V_432 ,
V_185 -> V_431 ) ) {
V_205 = 1 ;
}
break;
case V_282 :
V_205 = 1 ;
break;
default:
break;
}
}
return V_205 ;
}
static int F_289 ( struct V_55 * V_82 ,
struct V_428 * V_185 , int V_433 )
{
struct V_428 * V_434 ;
int V_130 , V_435 , V_436 = 0 ;
F_71 ( & V_82 -> V_62 ) ;
if ( F_9 ( V_82 -> V_63 . V_64 ) ) {
F_72 ( & V_82 -> V_62 ) ;
return - V_195 ;
}
for ( V_130 = 0 ; V_130 < V_82 -> V_224 ; V_130 ++ ) {
for ( V_435 = 0 , V_434 = V_185 ; V_435 < V_433 ; V_435 ++ , V_434 ++ ) {
if ( ! F_288 ( V_434 , & V_82 -> V_225 [ V_130 ] ) )
continue;
V_436 ++ ;
if ( V_82 -> V_225 [ V_130 ] . V_235 != V_236 &&
V_82 -> V_225 [ V_130 ] . V_235 != V_237 )
continue;
memcpy ( & V_82 -> V_225 [ V_130 ] . V_46 . V_9 , & V_434 -> V_437 ,
sizeof( V_82 -> V_225 [ V_130 ] . V_46 . V_9 ) ) ;
memcpy ( & V_82 -> V_225 [ V_130 ] . V_12 , & V_434 -> V_438 ,
sizeof( V_82 -> V_225 [ V_130 ] . V_12 ) ) ;
V_82 -> V_225 [ V_130 ] . V_238 = V_434 -> V_439 ;
F_52 ( & V_82 -> V_100 ) ;
}
}
F_72 ( & V_82 -> V_62 ) ;
if ( ! V_436 )
return - V_440 ;
return 0 ;
}
static int F_290 ( const struct V_428 * V_185 , int V_433 )
{
int V_130 , V_435 ;
if ( V_433 < 1 || V_433 > V_249 )
return - V_203 ;
for ( V_130 = 0 ; V_130 < V_433 ; V_130 ++ ) {
if ( F_286 ( & V_185 [ V_130 ] . V_430 , & V_185 [ V_130 ] . V_437 ,
V_185 [ V_130 ] . V_431 ) &&
F_286 ( & V_185 [ V_130 ] . V_432 , & V_185 [ V_130 ] . V_438 ,
V_185 [ V_130 ] . V_431 ) )
return - V_203 ;
if ( F_151 ( & V_185 [ V_130 ] . V_437 , V_185 [ V_130 ] . V_439 ) ||
F_151 ( & V_185 [ V_130 ] . V_438 , V_185 [ V_130 ] . V_439 ) )
return - V_203 ;
for ( V_435 = V_130 + 1 ; V_435 < V_433 ; V_435 ++ ) {
if ( ! memcmp ( & V_185 [ V_130 ] . V_430 , & V_185 [ V_435 ] . V_430 ,
sizeof( V_185 [ V_130 ] . V_430 ) ) &&
! memcmp ( & V_185 [ V_130 ] . V_432 , & V_185 [ V_435 ] . V_432 ,
sizeof( V_185 [ V_130 ] . V_432 ) ) &&
V_185 [ V_130 ] . V_20 == V_185 [ V_435 ] . V_20 &&
V_185 [ V_130 ] . V_235 == V_185 [ V_435 ] . V_235 &&
V_185 [ V_130 ] . V_344 == V_185 [ V_435 ] . V_344 &&
V_185 [ V_130 ] . V_431 == V_185 [ V_435 ] . V_431 )
return - V_203 ;
}
}
return 0 ;
}
int V_428 ( const struct V_1 * V_2 , T_4 V_61 , T_4 type ,
struct V_428 * V_185 , int V_433 ,
struct V_441 * V_353 , struct V_35 * V_35 )
{
int V_130 , V_193 , V_442 = 0 , V_443 = 0 ;
struct V_55 * V_82 = NULL ;
struct V_41 * V_42 , * V_444 ;
struct V_41 * V_445 [ V_249 ] ;
struct V_41 * V_446 [ V_249 ] ;
struct V_428 * V_434 ;
if ( ( V_193 = F_290 ( V_185 , V_433 ) ) < 0 )
goto V_65;
if ( ( V_82 = F_287 ( V_2 , V_61 , type , V_35 ) ) == NULL ) {
V_193 = - V_195 ;
goto V_65;
}
for ( V_130 = 0 , V_434 = V_185 ; V_130 < V_433 ; V_130 ++ , V_434 ++ ) {
if ( ( V_42 = F_291 ( V_434 , V_35 ) ) ) {
V_445 [ V_442 ] = V_42 ;
V_442 ++ ;
if ( ( V_444 = F_292 ( V_42 , V_434 ) ) ) {
V_446 [ V_443 ] = V_444 ;
V_443 ++ ;
} else {
V_193 = - V_440 ;
goto V_447;
}
}
}
if ( ( V_193 = F_289 ( V_82 , V_185 , V_433 ) ) < 0 )
goto V_447;
if ( V_442 ) {
F_293 ( V_445 , V_442 ) ;
F_294 ( V_445 , V_442 ) ;
}
F_295 ( V_2 , V_61 , type , V_185 , V_433 , V_353 ) ;
F_28 ( V_82 ) ;
return 0 ;
V_65:
return V_193 ;
V_447:
if ( V_82 )
F_28 ( V_82 ) ;
if ( V_442 )
F_293 ( V_445 , V_442 ) ;
if ( V_443 )
F_294 ( V_446 , V_443 ) ;
return V_193 ;
}
