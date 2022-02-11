static inline bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static inline bool
F_3 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
const struct V_8 * V_9 = & V_7 -> V_10 . V_11 ;
return F_4 ( V_9 -> V_12 , V_5 -> V_12 . V_13 , V_5 -> V_14 ) &&
F_4 ( V_9 -> V_15 , V_5 -> V_15 . V_13 , V_5 -> V_16 ) &&
! ( ( F_5 ( V_7 , & V_9 -> V_17 ) ^ V_5 -> V_18 ) & V_5 -> V_19 ) &&
! ( ( F_6 ( V_7 , & V_9 -> V_17 ) ^ V_5 -> V_20 ) & V_5 -> V_21 ) &&
( V_9 -> V_22 == V_5 -> V_23 || ! V_5 -> V_23 ) &&
( V_9 -> V_24 == V_5 -> V_25 || ! V_5 -> V_25 ) ;
}
static inline bool
F_7 ( const struct V_4 * V_5 , const struct V_6 * V_7 )
{
const struct V_26 * V_27 = & V_7 -> V_10 . V_28 ;
return F_8 ( & V_27 -> V_12 , & V_5 -> V_12 , V_5 -> V_14 ) &&
F_8 ( & V_27 -> V_15 , & V_5 -> V_15 , V_5 -> V_16 ) &&
! ( ( F_5 ( V_7 , & V_27 -> V_17 ) ^ V_5 -> V_18 ) & V_5 -> V_19 ) &&
! ( ( F_6 ( V_7 , & V_27 -> V_17 ) ^ V_5 -> V_20 ) & V_5 -> V_21 ) &&
( V_27 -> V_29 == V_5 -> V_23 || ! V_5 -> V_23 ) &&
( V_27 -> V_30 == V_5 -> V_25 || ! V_5 -> V_25 ) ;
}
bool F_9 ( const struct V_4 * V_5 , const struct V_6 * V_7 ,
unsigned short V_31 )
{
switch ( V_31 ) {
case V_32 :
return F_3 ( V_5 , V_7 ) ;
case V_33 :
return F_7 ( V_5 , V_7 ) ;
}
return false ;
}
static struct V_34 * F_10 ( unsigned short V_31 )
{
struct V_34 * V_35 ;
if ( F_11 ( V_31 >= V_36 ) )
return NULL ;
F_12 () ;
V_35 = F_13 ( V_34 [ V_31 ] ) ;
if ( F_11 ( ! V_35 ) )
F_14 () ;
return V_35 ;
}
static void F_15 ( struct V_34 * V_35 )
{
F_14 () ;
}
static inline struct V_37 * F_16 ( struct V_38 * V_38 ,
int V_39 , int V_40 ,
const T_1 * V_15 ,
const T_1 * V_12 ,
int V_31 )
{
struct V_34 * V_35 ;
struct V_37 * V_41 ;
V_35 = F_10 ( V_31 ) ;
if ( F_11 ( V_35 == NULL ) )
return F_17 ( - V_42 ) ;
V_41 = V_35 -> V_43 ( V_38 , V_39 , V_40 , V_15 , V_12 ) ;
F_15 ( V_35 ) ;
return V_41 ;
}
static inline struct V_37 * F_18 ( struct V_44 * V_45 ,
int V_39 , int V_40 ,
T_1 * V_46 ,
T_1 * V_47 ,
int V_31 )
{
struct V_38 * V_38 = F_19 ( V_45 ) ;
T_1 * V_15 = & V_45 -> V_48 . V_15 ;
T_1 * V_12 = & V_45 -> V_49 . V_12 ;
struct V_37 * V_41 ;
if ( V_45 -> type -> V_50 & V_51 ) {
V_15 = V_45 -> V_52 ;
V_12 = V_47 ;
}
if ( V_45 -> type -> V_50 & V_53 ) {
V_15 = V_46 ;
V_12 = V_45 -> V_52 ;
}
V_41 = F_16 ( V_38 , V_39 , V_40 , V_15 , V_12 , V_31 ) ;
if ( ! F_20 ( V_41 ) ) {
if ( V_46 != V_15 )
memcpy ( V_46 , V_15 , sizeof( * V_46 ) ) ;
if ( V_47 != V_12 )
memcpy ( V_47 , V_12 , sizeof( * V_47 ) ) ;
}
return V_41 ;
}
static inline unsigned long F_21 ( long V_54 )
{
if ( V_54 >= ( V_55 - 1 ) / V_56 )
return V_55 - 1 ;
else
return V_54 * V_56 ;
}
static void F_22 ( unsigned long V_57 )
{
struct V_1 * V_58 = (struct V_1 * ) V_57 ;
unsigned long V_59 = F_23 () ;
long V_60 = V_61 ;
int V_62 = 0 ;
int V_63 ;
F_24 ( & V_58 -> V_64 ) ;
if ( F_11 ( V_58 -> V_65 . V_66 ) )
goto V_67;
V_63 = F_25 ( V_58 -> V_68 ) ;
if ( V_58 -> V_69 . V_70 ) {
long V_71 = V_58 -> V_69 . V_70 +
V_58 -> V_72 . V_73 - V_59 ;
if ( V_71 <= 0 )
goto V_74;
if ( V_71 < V_60 )
V_60 = V_71 ;
}
if ( V_58 -> V_69 . V_75 ) {
long V_71 = V_58 -> V_69 . V_75 +
( V_58 -> V_72 . V_76 ? : V_58 -> V_72 . V_73 ) - V_59 ;
if ( V_71 <= 0 )
goto V_74;
if ( V_71 < V_60 )
V_60 = V_71 ;
}
if ( V_58 -> V_69 . V_77 ) {
long V_71 = V_58 -> V_69 . V_77 +
V_58 -> V_72 . V_73 - V_59 ;
if ( V_71 <= 0 ) {
V_62 = 1 ;
V_71 = V_78 ;
}
if ( V_71 < V_60 )
V_60 = V_71 ;
}
if ( V_58 -> V_69 . V_79 ) {
long V_71 = V_58 -> V_69 . V_79 +
( V_58 -> V_72 . V_76 ? : V_58 -> V_72 . V_73 ) - V_59 ;
if ( V_71 <= 0 ) {
V_62 = 1 ;
V_71 = V_78 ;
}
if ( V_71 < V_60 )
V_60 = V_71 ;
}
if ( V_62 )
F_26 ( V_58 , V_63 , 0 , 0 ) ;
if ( V_60 != V_61 &&
! F_27 ( & V_58 -> V_80 , V_81 + F_21 ( V_60 ) ) )
F_28 ( V_58 ) ;
V_67:
F_29 ( & V_58 -> V_64 ) ;
F_30 ( V_58 ) ;
return;
V_74:
F_29 ( & V_58 -> V_64 ) ;
if ( ! F_31 ( V_58 , V_63 ) )
F_26 ( V_58 , V_63 , 1 , 0 ) ;
F_30 ( V_58 ) ;
}
static struct V_82 * F_32 ( struct V_82 * V_83 )
{
struct V_1 * V_84 = F_33 ( V_83 , struct V_1 , V_83 ) ;
if ( F_11 ( V_84 -> V_65 . V_66 ) )
V_83 = NULL ;
else
F_28 ( V_84 ) ;
return V_83 ;
}
static int F_34 ( struct V_82 * V_83 )
{
struct V_1 * V_84 = F_33 ( V_83 , struct V_1 , V_83 ) ;
return ! V_84 -> V_65 . V_66 ;
}
static void F_35 ( struct V_82 * V_83 )
{
F_30 ( F_33 ( V_83 , struct V_1 , V_83 ) ) ;
}
struct V_1 * F_36 ( struct V_38 * V_38 , T_2 V_85 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_85 ) ;
if ( V_2 ) {
F_38 ( & V_2 -> V_86 , V_38 ) ;
F_39 ( & V_2 -> V_65 . V_87 ) ;
F_40 ( & V_2 -> V_88 ) ;
F_40 ( & V_2 -> V_89 ) ;
F_41 ( & V_2 -> V_64 ) ;
F_42 ( & V_2 -> V_3 , 1 ) ;
F_43 ( & V_2 -> V_90 . V_91 ) ;
F_44 ( & V_2 -> V_80 , F_22 ,
( unsigned long ) V_2 ) ;
F_44 ( & V_2 -> V_90 . V_92 , V_93 ,
( unsigned long ) V_2 ) ;
V_2 -> V_83 . V_94 = & V_95 ;
}
return V_2 ;
}
static void F_45 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_33 ( V_97 , struct V_1 , V_98 ) ;
F_46 ( V_2 -> V_99 ) ;
F_47 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_49 ( ! V_2 -> V_65 . V_66 ) ;
if ( F_50 ( & V_2 -> V_80 ) || F_50 ( & V_2 -> V_90 . V_92 ) )
F_51 () ;
F_52 ( & V_2 -> V_98 , F_45 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
V_2 -> V_65 . V_66 = 1 ;
F_54 ( & V_2 -> V_100 ) ;
if ( F_50 ( & V_2 -> V_90 . V_92 ) )
F_30 ( V_2 ) ;
F_55 ( & V_2 -> V_90 . V_91 ) ;
if ( F_50 ( & V_2 -> V_80 ) )
F_30 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static inline unsigned int F_56 ( struct V_38 * V_38 , T_3 V_68 )
{
return F_57 ( V_68 , V_38 -> V_101 . V_102 ) ;
}
static void F_58 ( struct V_38 * V_38 ,
unsigned short V_31 , int V_63 ,
T_4 * V_103 , T_4 * V_104 )
{
switch ( V_31 ) {
case V_32 :
* V_103 = V_38 -> V_101 . V_105 [ V_63 ] . V_106 ;
* V_104 = V_38 -> V_101 . V_105 [ V_63 ] . V_107 ;
break;
case V_33 :
* V_103 = V_38 -> V_101 . V_105 [ V_63 ] . V_108 ;
* V_104 = V_38 -> V_101 . V_105 [ V_63 ] . V_109 ;
break;
default:
* V_103 = 0 ;
* V_104 = 0 ;
}
}
static struct V_110 * F_59 ( struct V_38 * V_38 ,
const struct V_4 * V_5 ,
unsigned short V_31 , int V_63 )
{
unsigned int V_111 = V_38 -> V_101 . V_105 [ V_63 ] . V_111 ;
unsigned int V_112 ;
T_4 V_103 ;
T_4 V_104 ;
F_58 ( V_38 , V_31 , V_63 , & V_103 , & V_104 ) ;
V_112 = F_60 ( V_5 , V_31 , V_111 , V_103 , V_104 ) ;
if ( V_112 == V_111 + 1 )
return & V_38 -> V_101 . V_113 [ V_63 ] ;
return F_61 ( V_38 -> V_101 . V_105 [ V_63 ] . V_114 ,
F_62 ( & V_38 -> V_101 . V_115 ) ) + V_112 ;
}
static struct V_110 * F_63 ( struct V_38 * V_38 ,
const T_1 * V_12 ,
const T_1 * V_15 ,
unsigned short V_31 , int V_63 )
{
unsigned int V_111 = V_38 -> V_101 . V_105 [ V_63 ] . V_111 ;
unsigned int V_112 ;
T_4 V_103 ;
T_4 V_104 ;
F_58 ( V_38 , V_31 , V_63 , & V_103 , & V_104 ) ;
V_112 = F_64 ( V_12 , V_15 , V_31 , V_111 , V_103 , V_104 ) ;
return F_61 ( V_38 -> V_101 . V_105 [ V_63 ] . V_114 ,
F_62 ( & V_38 -> V_101 . V_115 ) ) + V_112 ;
}
static void F_65 ( struct V_38 * V_38 ,
struct V_110 * V_116 ,
struct V_110 * V_117 ,
unsigned int V_118 ,
int V_63 )
{
struct V_119 * V_120 , * V_121 = NULL ;
struct V_1 * V_84 ;
unsigned int V_122 = 0 ;
T_4 V_103 ;
T_4 V_104 ;
V_123:
F_66 (pol, tmp, list, bydst) {
unsigned int V_124 ;
F_58 ( V_38 , V_84 -> V_31 , V_63 , & V_103 , & V_104 ) ;
V_124 = F_64 ( & V_84 -> V_125 . V_12 , & V_84 -> V_125 . V_15 ,
V_84 -> V_31 , V_118 , V_103 , V_104 ) ;
if ( ! V_121 ) {
F_67 ( & V_84 -> V_88 ) ;
F_68 ( & V_84 -> V_88 , V_117 + V_124 ) ;
V_122 = V_124 ;
} else {
if ( V_124 != V_122 )
continue;
F_67 ( & V_84 -> V_88 ) ;
F_69 ( & V_84 -> V_88 , V_121 ) ;
}
V_121 = & V_84 -> V_88 ;
}
if ( ! F_70 ( V_116 ) ) {
V_121 = NULL ;
goto V_123;
}
}
static void F_71 ( struct V_110 * V_116 ,
struct V_110 * V_126 ,
unsigned int V_118 )
{
struct V_119 * V_120 ;
struct V_1 * V_84 ;
F_66 (pol, tmp, list, byidx) {
unsigned int V_124 ;
V_124 = F_57 ( V_84 -> V_68 , V_118 ) ;
F_72 ( & V_84 -> V_89 , V_126 + V_124 ) ;
}
}
static unsigned long F_73 ( unsigned int V_127 )
{
return ( ( V_127 + 1 ) << 1 ) - 1 ;
}
static void F_74 ( struct V_38 * V_38 , int V_63 )
{
unsigned int V_111 = V_38 -> V_101 . V_105 [ V_63 ] . V_111 ;
unsigned int V_118 = F_73 ( V_111 ) ;
unsigned int V_128 = ( V_118 + 1 ) * sizeof( struct V_110 ) ;
struct V_110 * V_129 = F_75 ( V_128 ) ;
struct V_110 * V_130 ;
int V_131 ;
if ( ! V_129 )
return;
F_76 ( & V_38 -> V_101 . V_115 ) ;
F_77 ( & V_132 ) ;
V_130 = F_78 ( V_38 -> V_101 . V_105 [ V_63 ] . V_114 ,
F_62 ( & V_38 -> V_101 . V_115 ) ) ;
V_130 = F_78 ( V_38 -> V_101 . V_105 [ V_63 ] . V_114 ,
F_62 ( & V_38 -> V_101 . V_115 ) ) ;
for ( V_131 = V_111 ; V_131 >= 0 ; V_131 -- )
F_65 ( V_38 , V_130 + V_131 , V_129 , V_118 , V_63 ) ;
F_79 ( V_38 -> V_101 . V_105 [ V_63 ] . V_114 , V_129 ) ;
V_38 -> V_101 . V_105 [ V_63 ] . V_111 = V_118 ;
F_80 ( & V_132 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
F_82 () ;
F_83 ( V_130 , ( V_111 + 1 ) * sizeof( struct V_110 ) ) ;
}
static void F_84 ( struct V_38 * V_38 , int V_133 )
{
unsigned int V_111 = V_38 -> V_101 . V_102 ;
unsigned int V_118 = F_73 ( V_111 ) ;
unsigned int V_128 = ( V_118 + 1 ) * sizeof( struct V_110 ) ;
struct V_110 * V_134 = V_38 -> V_101 . V_135 ;
struct V_110 * V_136 = F_75 ( V_128 ) ;
int V_131 ;
if ( ! V_136 )
return;
F_76 ( & V_38 -> V_101 . V_115 ) ;
for ( V_131 = V_111 ; V_131 >= 0 ; V_131 -- )
F_71 ( V_134 + V_131 , V_136 , V_118 ) ;
V_38 -> V_101 . V_135 = V_136 ;
V_38 -> V_101 . V_102 = V_118 ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
F_83 ( V_134 , ( V_111 + 1 ) * sizeof( struct V_110 ) ) ;
}
static inline int F_85 ( struct V_38 * V_38 , int V_63 , int * V_133 )
{
unsigned int V_137 = V_38 -> V_101 . V_138 [ V_63 ] ;
unsigned int V_111 = V_38 -> V_101 . V_105 [ V_63 ] . V_111 ;
if ( V_133 )
* V_133 += V_137 ;
if ( ( V_111 + 1 ) < V_139 &&
V_137 > V_111 )
return 1 ;
return 0 ;
}
static inline int F_86 ( struct V_38 * V_38 , int V_133 )
{
unsigned int V_111 = V_38 -> V_101 . V_102 ;
if ( ( V_111 + 1 ) < V_139 &&
V_133 > V_111 )
return 1 ;
return 0 ;
}
void F_87 ( struct V_38 * V_38 , struct V_140 * V_141 )
{
V_141 -> V_142 = V_38 -> V_101 . V_138 [ V_143 ] ;
V_141 -> V_144 = V_38 -> V_101 . V_138 [ V_145 ] ;
V_141 -> V_146 = V_38 -> V_101 . V_138 [ V_147 ] ;
V_141 -> V_148 = V_38 -> V_101 . V_138 [ V_143 + V_149 ] ;
V_141 -> V_150 = V_38 -> V_101 . V_138 [ V_145 + V_149 ] ;
V_141 -> V_151 = V_38 -> V_101 . V_138 [ V_147 + V_149 ] ;
V_141 -> V_152 = V_38 -> V_101 . V_102 ;
V_141 -> V_153 = V_139 ;
}
static void F_88 ( struct V_154 * V_155 )
{
struct V_38 * V_38 = F_33 ( V_155 , struct V_38 , V_101 . V_156 ) ;
int V_63 , V_133 ;
F_89 ( & V_157 ) ;
V_133 = 0 ;
for ( V_63 = 0 ; V_63 < V_149 ; V_63 ++ ) {
if ( F_85 ( V_38 , V_63 , & V_133 ) )
F_74 ( V_38 , V_63 ) ;
}
if ( F_86 ( V_38 , V_133 ) )
F_84 ( V_38 , V_133 ) ;
F_90 ( & V_157 ) ;
}
static void F_91 ( struct V_154 * V_155 )
{
struct V_38 * V_38 = F_33 ( V_155 , struct V_38 ,
V_101 . V_158 . V_155 ) ;
unsigned int V_111 ;
struct V_1 * V_84 ;
struct V_1 * V_2 ;
struct V_110 * V_159 ;
struct V_110 * V_130 ;
struct V_119 * V_160 ;
int V_131 ;
int V_63 ;
unsigned V_161 ;
T_4 V_162 , V_163 , V_164 , V_165 ;
F_89 ( & V_157 ) ;
do {
V_161 = F_92 ( & V_38 -> V_101 . V_158 . V_64 ) ;
V_162 = V_38 -> V_101 . V_158 . V_162 ;
V_163 = V_38 -> V_101 . V_158 . V_163 ;
V_164 = V_38 -> V_101 . V_158 . V_164 ;
V_165 = V_38 -> V_101 . V_158 . V_165 ;
} while ( F_93 ( & V_38 -> V_101 . V_158 . V_64 , V_161 ) );
F_76 ( & V_38 -> V_101 . V_115 ) ;
for ( V_63 = 0 ; V_63 < V_149 ; V_63 ++ ) {
F_94 ( & V_38 -> V_101 . V_113 [ V_63 ] ) ;
V_111 = V_38 -> V_101 . V_105 [ V_63 ] . V_111 ;
V_130 = V_38 -> V_101 . V_105 [ V_63 ] . V_114 ;
for ( V_131 = V_111 ; V_131 >= 0 ; V_131 -- )
F_94 ( V_130 + V_131 ) ;
if ( ( V_63 & V_166 ) == V_145 ) {
V_38 -> V_101 . V_105 [ V_63 ] . V_106 = V_163 ;
V_38 -> V_101 . V_105 [ V_63 ] . V_107 = V_162 ;
V_38 -> V_101 . V_105 [ V_63 ] . V_108 = V_165 ;
V_38 -> V_101 . V_105 [ V_63 ] . V_109 = V_164 ;
} else {
V_38 -> V_101 . V_105 [ V_63 ] . V_106 = V_162 ;
V_38 -> V_101 . V_105 [ V_63 ] . V_107 = V_163 ;
V_38 -> V_101 . V_105 [ V_63 ] . V_108 = V_164 ;
V_38 -> V_101 . V_105 [ V_63 ] . V_109 = V_165 ;
}
}
F_95 (policy, &net->xfrm.policy_all, walk.all) {
if ( F_25 ( V_2 -> V_68 ) >= V_149 ) {
continue;
}
V_160 = NULL ;
V_159 = F_59 ( V_38 , & V_2 -> V_125 ,
V_2 -> V_31 ,
F_25 ( V_2 -> V_68 ) ) ;
F_96 (pol, chain, bydst) {
if ( V_2 -> V_167 >= V_84 -> V_167 )
V_160 = & V_84 -> V_88 ;
else
break;
}
if ( V_160 )
F_97 ( & V_2 -> V_88 , V_160 ) ;
else
F_72 ( & V_2 -> V_88 , V_159 ) ;
}
F_81 ( & V_38 -> V_101 . V_115 ) ;
F_90 ( & V_157 ) ;
}
void F_98 ( struct V_38 * V_38 )
{
F_99 ( & V_38 -> V_101 . V_158 . V_155 ) ;
}
static T_3 F_100 ( struct V_38 * V_38 , int V_63 , T_3 V_68 )
{
static T_3 V_168 ;
for (; ; ) {
struct V_110 * V_116 ;
struct V_1 * V_169 ;
T_3 V_170 ;
int V_171 ;
if ( ! V_68 ) {
V_170 = ( V_168 | V_63 ) ;
V_168 += 8 ;
} else {
V_170 = V_68 ;
V_68 = 0 ;
}
if ( V_170 == 0 )
V_170 = 8 ;
V_116 = V_38 -> V_101 . V_135 + F_56 ( V_38 , V_170 ) ;
V_171 = 0 ;
F_96 (p, list, byidx) {
if ( V_169 -> V_68 == V_170 ) {
V_171 = 1 ;
break;
}
}
if ( ! V_171 )
return V_170 ;
}
}
static inline int F_101 ( struct V_4 * V_172 , struct V_4 * V_173 )
{
T_3 * V_174 = ( T_3 * ) V_172 ;
T_3 * V_175 = ( T_3 * ) V_173 ;
int V_176 = sizeof( struct V_4 ) / sizeof( T_3 ) ;
int V_131 ;
for ( V_131 = 0 ; V_131 < V_176 ; V_131 ++ ) {
if ( V_174 [ V_131 ] != V_175 [ V_131 ] )
return 1 ;
}
return 0 ;
}
static void F_102 ( struct V_1 * V_177 ,
struct V_1 * V_178 )
{
struct V_179 * V_180 = & V_177 -> V_90 ;
struct V_181 V_116 ;
if ( F_103 ( & V_180 -> V_91 ) )
return;
F_104 ( & V_116 ) ;
F_76 ( & V_180 -> V_91 . V_64 ) ;
F_105 ( & V_180 -> V_91 , & V_116 ) ;
if ( F_50 ( & V_180 -> V_92 ) )
F_30 ( V_177 ) ;
F_81 ( & V_180 -> V_91 . V_64 ) ;
V_180 = & V_178 -> V_90 ;
F_76 ( & V_180 -> V_91 . V_64 ) ;
F_106 ( & V_116 , & V_180 -> V_91 ) ;
V_180 -> V_182 = V_183 ;
if ( ! F_27 ( & V_180 -> V_92 , V_81 ) )
F_28 ( V_178 ) ;
F_81 ( & V_180 -> V_91 . V_64 ) ;
}
static bool F_107 ( struct V_1 * V_2 ,
struct V_1 * V_84 )
{
T_3 V_184 = V_2 -> V_184 . V_185 & V_2 -> V_184 . V_186 ;
if ( V_2 -> V_184 . V_185 == V_84 -> V_184 . V_185 && V_2 -> V_184 . V_186 == V_84 -> V_184 . V_186 )
return true ;
if ( ( V_184 & V_84 -> V_184 . V_186 ) == V_84 -> V_184 . V_185 &&
V_2 -> V_167 == V_84 -> V_167 )
return true ;
return false ;
}
int F_108 ( int V_63 , struct V_1 * V_2 , int V_187 )
{
struct V_38 * V_38 = V_86 ( V_2 ) ;
struct V_1 * V_84 ;
struct V_1 * V_188 ;
struct V_110 * V_159 ;
struct V_119 * V_160 ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
V_159 = F_59 ( V_38 , & V_2 -> V_125 , V_2 -> V_31 , V_63 ) ;
V_188 = NULL ;
V_160 = NULL ;
F_96 (pol, chain, bydst) {
if ( V_84 -> type == V_2 -> type &&
! F_101 ( & V_84 -> V_125 , & V_2 -> V_125 ) &&
F_107 ( V_2 , V_84 ) &&
F_109 ( V_84 -> V_99 , V_2 -> V_99 ) &&
! F_110 ( V_188 ) ) {
if ( V_187 ) {
F_81 ( & V_38 -> V_101 . V_115 ) ;
return - V_189 ;
}
V_188 = V_84 ;
if ( V_2 -> V_167 > V_84 -> V_167 )
continue;
} else if ( V_2 -> V_167 >= V_84 -> V_167 ) {
V_160 = & V_84 -> V_88 ;
continue;
}
if ( V_188 )
break;
}
if ( V_160 )
F_97 ( & V_2 -> V_88 , V_160 ) ;
else
F_72 ( & V_2 -> V_88 , V_159 ) ;
F_111 ( V_2 , V_63 ) ;
F_54 ( & V_38 -> V_101 . V_190 ) ;
if ( V_2 -> V_31 == V_32 )
F_112 ( V_38 ) ;
else
F_113 ( V_38 ) ;
if ( V_188 ) {
F_102 ( V_188 , V_2 ) ;
F_114 ( V_188 , V_63 ) ;
}
V_2 -> V_68 = V_188 ? V_188 -> V_68 : F_100 ( V_38 , V_63 , V_2 -> V_68 ) ;
F_72 ( & V_2 -> V_89 , V_38 -> V_101 . V_135 + F_56 ( V_38 , V_2 -> V_68 ) ) ;
V_2 -> V_72 . V_73 = F_23 () ;
V_2 -> V_72 . V_76 = 0 ;
if ( ! F_27 ( & V_2 -> V_80 , V_81 + V_56 ) )
F_28 ( V_2 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
if ( V_188 )
F_53 ( V_188 ) ;
else if ( F_85 ( V_38 , V_63 , NULL ) )
F_99 ( & V_38 -> V_101 . V_156 ) ;
return 0 ;
}
struct V_1 * F_115 ( struct V_38 * V_38 , T_3 V_184 , T_4 type ,
int V_63 , struct V_4 * V_5 ,
struct V_191 * V_192 , int V_193 ,
int * V_194 )
{
struct V_1 * V_84 , * V_195 ;
struct V_110 * V_159 ;
* V_194 = 0 ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
V_159 = F_59 ( V_38 , V_5 , V_5 -> V_31 , V_63 ) ;
V_195 = NULL ;
F_96 (pol, chain, bydst) {
if ( V_84 -> type == type &&
( V_184 & V_84 -> V_184 . V_186 ) == V_84 -> V_184 . V_185 &&
! F_101 ( V_5 , & V_84 -> V_125 ) &&
F_109 ( V_192 , V_84 -> V_99 ) ) {
F_28 ( V_84 ) ;
if ( V_193 ) {
* V_194 = F_116 (
V_84 -> V_99 ) ;
if ( * V_194 ) {
F_81 ( & V_38 -> V_101 . V_115 ) ;
return V_84 ;
}
F_114 ( V_84 , V_63 ) ;
}
V_195 = V_84 ;
break;
}
}
F_81 ( & V_38 -> V_101 . V_115 ) ;
if ( V_195 && V_193 )
F_53 ( V_195 ) ;
return V_195 ;
}
struct V_1 * F_117 ( struct V_38 * V_38 , T_3 V_184 , T_4 type ,
int V_63 , T_3 V_49 , int V_193 , int * V_194 )
{
struct V_1 * V_84 , * V_195 ;
struct V_110 * V_159 ;
* V_194 = - V_196 ;
if ( F_25 ( V_49 ) != V_63 )
return NULL ;
* V_194 = 0 ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
V_159 = V_38 -> V_101 . V_135 + F_56 ( V_38 , V_49 ) ;
V_195 = NULL ;
F_96 (pol, chain, byidx) {
if ( V_84 -> type == type && V_84 -> V_68 == V_49 &&
( V_184 & V_84 -> V_184 . V_186 ) == V_84 -> V_184 . V_185 ) {
F_28 ( V_84 ) ;
if ( V_193 ) {
* V_194 = F_116 (
V_84 -> V_99 ) ;
if ( * V_194 ) {
F_81 ( & V_38 -> V_101 . V_115 ) ;
return V_84 ;
}
F_114 ( V_84 , V_63 ) ;
}
V_195 = V_84 ;
break;
}
}
F_81 ( & V_38 -> V_101 . V_115 ) ;
if ( V_195 && V_193 )
F_53 ( V_195 ) ;
return V_195 ;
}
static inline int
F_118 ( struct V_38 * V_38 , T_4 type , bool V_197 )
{
int V_63 , V_194 = 0 ;
for ( V_63 = 0 ; V_63 < V_149 ; V_63 ++ ) {
struct V_1 * V_84 ;
int V_131 ;
F_96 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_84 -> type != type )
continue;
V_194 = F_116 ( V_84 -> V_99 ) ;
if ( V_194 ) {
F_119 ( V_84 , 0 , V_197 ) ;
return V_194 ;
}
}
for ( V_131 = V_38 -> V_101 . V_105 [ V_63 ] . V_111 ; V_131 >= 0 ; V_131 -- ) {
F_96 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_84 -> type != type )
continue;
V_194 = F_116 (
V_84 -> V_99 ) ;
if ( V_194 ) {
F_119 ( V_84 , 0 ,
V_197 ) ;
return V_194 ;
}
}
}
}
return V_194 ;
}
static inline int
F_118 ( struct V_38 * V_38 , T_4 type , bool V_197 )
{
return 0 ;
}
int F_120 ( struct V_38 * V_38 , T_4 type , bool V_197 )
{
int V_63 , V_194 = 0 , V_137 = 0 ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
V_194 = F_118 ( V_38 , type , V_197 ) ;
if ( V_194 )
goto V_67;
for ( V_63 = 0 ; V_63 < V_149 ; V_63 ++ ) {
struct V_1 * V_84 ;
int V_131 ;
V_198:
F_96 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_84 -> type != type )
continue;
F_114 ( V_84 , V_63 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
V_137 ++ ;
F_119 ( V_84 , 1 , V_197 ) ;
F_53 ( V_84 ) ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
goto V_198;
}
for ( V_131 = V_38 -> V_101 . V_105 [ V_63 ] . V_111 ; V_131 >= 0 ; V_131 -- ) {
V_199:
F_96 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_84 -> type != type )
continue;
F_114 ( V_84 , V_63 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
V_137 ++ ;
F_119 ( V_84 , 1 , V_197 ) ;
F_53 ( V_84 ) ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
goto V_199;
}
}
}
if ( ! V_137 )
V_194 = - V_200 ;
V_67:
F_81 ( & V_38 -> V_101 . V_115 ) ;
return V_194 ;
}
int F_121 ( struct V_38 * V_38 , struct F_121 * V_65 ,
int (* F_122)( struct V_1 * , int , int , void * ) ,
void * V_57 )
{
struct V_1 * V_84 ;
struct V_201 * V_45 ;
int error = 0 ;
if ( V_65 -> type >= V_202 &&
V_65 -> type != V_203 )
return - V_204 ;
if ( F_123 ( & V_65 -> V_65 . V_87 ) && V_65 -> V_161 != 0 )
return 0 ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
if ( F_123 ( & V_65 -> V_65 . V_87 ) )
V_45 = F_124 ( & V_38 -> V_101 . V_205 , struct V_201 , V_87 ) ;
else
V_45 = F_124 ( & V_65 -> V_65 . V_87 ,
struct V_201 , V_87 ) ;
F_125 (x, &net->xfrm.policy_all, all) {
if ( V_45 -> V_66 )
continue;
V_84 = F_33 ( V_45 , struct V_1 , V_65 ) ;
if ( V_65 -> type != V_203 &&
V_65 -> type != V_84 -> type )
continue;
error = F_122 ( V_84 , F_25 ( V_84 -> V_68 ) ,
V_65 -> V_161 , V_57 ) ;
if ( error ) {
F_126 ( & V_65 -> V_65 . V_87 , & V_45 -> V_87 ) ;
goto V_67;
}
V_65 -> V_161 ++ ;
}
if ( V_65 -> V_161 == 0 ) {
error = - V_196 ;
goto V_67;
}
F_127 ( & V_65 -> V_65 . V_87 ) ;
V_67:
F_81 ( & V_38 -> V_101 . V_115 ) ;
return error ;
}
void F_128 ( struct F_121 * V_65 , T_4 type )
{
F_39 ( & V_65 -> V_65 . V_87 ) ;
V_65 -> V_65 . V_66 = 1 ;
V_65 -> type = type ;
V_65 -> V_161 = 0 ;
}
void F_129 ( struct F_121 * V_65 , struct V_38 * V_38 )
{
if ( F_123 ( & V_65 -> V_65 . V_87 ) )
return;
F_76 ( & V_38 -> V_101 . V_115 ) ;
F_130 ( & V_65 -> V_65 . V_87 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
}
static int F_131 ( const struct V_1 * V_84 ,
const struct V_6 * V_7 ,
T_4 type , T_5 V_31 , int V_63 )
{
const struct V_4 * V_5 = & V_84 -> V_125 ;
int V_195 = - V_200 ;
bool V_206 ;
if ( V_84 -> V_31 != V_31 ||
( V_7 -> V_207 & V_84 -> V_184 . V_186 ) != V_84 -> V_184 . V_185 ||
V_84 -> type != type )
return V_195 ;
V_206 = F_9 ( V_5 , V_7 , V_31 ) ;
if ( V_206 )
V_195 = F_132 ( V_84 -> V_99 , V_7 -> V_208 ,
V_63 ) ;
return V_195 ;
}
static struct V_1 * F_133 ( struct V_38 * V_38 , T_4 type ,
const struct V_6 * V_7 ,
T_5 V_31 , T_4 V_63 )
{
int V_194 ;
struct V_1 * V_84 , * V_195 ;
const T_1 * V_12 , * V_15 ;
struct V_110 * V_159 ;
unsigned int V_209 ;
T_3 V_167 ;
V_12 = F_134 ( V_7 , V_31 ) ;
V_15 = F_135 ( V_7 , V_31 ) ;
if ( F_11 ( ! V_12 || ! V_15 ) )
return NULL ;
F_12 () ;
V_210:
do {
V_209 = F_136 ( & V_132 ) ;
V_159 = F_63 ( V_38 , V_12 , V_15 , V_31 , V_63 ) ;
} while ( F_137 ( & V_132 , V_209 ) );
V_167 = ~ 0U ;
V_195 = NULL ;
F_138 (pol, chain, bydst) {
V_194 = F_131 ( V_84 , V_7 , type , V_31 , V_63 ) ;
if ( V_194 ) {
if ( V_194 == - V_200 )
continue;
else {
V_195 = F_17 ( V_194 ) ;
goto V_211;
}
} else {
V_195 = V_84 ;
V_167 = V_195 -> V_167 ;
break;
}
}
V_159 = & V_38 -> V_101 . V_113 [ V_63 ] ;
F_138 (pol, chain, bydst) {
if ( ( V_84 -> V_167 >= V_167 ) && V_195 )
break;
V_194 = F_131 ( V_84 , V_7 , type , V_31 , V_63 ) ;
if ( V_194 ) {
if ( V_194 == - V_200 )
continue;
else {
V_195 = F_17 ( V_194 ) ;
goto V_211;
}
} else {
V_195 = V_84 ;
break;
}
}
if ( F_137 ( & V_132 , V_209 ) )
goto V_210;
if ( V_195 && ! F_1 ( V_195 ) )
goto V_210;
V_211:
F_14 () ;
return V_195 ;
}
static struct V_1 *
F_139 ( struct V_38 * V_38 , const struct V_6 * V_7 , T_5 V_31 , T_4 V_63 )
{
#ifdef F_140
struct V_1 * V_84 ;
V_84 = F_133 ( V_38 , V_212 , V_7 , V_31 , V_63 ) ;
if ( V_84 != NULL )
return V_84 ;
#endif
return F_133 ( V_38 , V_213 , V_7 , V_31 , V_63 ) ;
}
static int F_141 ( int V_63 )
{
if ( V_143 == V_214 &&
V_145 == V_215 &&
V_147 == V_216 )
return V_63 ;
switch ( V_63 ) {
default:
case V_214 :
return V_143 ;
case V_215 :
return V_145 ;
case V_216 :
return V_147 ;
}
}
static struct V_82 *
F_142 ( struct V_38 * V_38 , const struct V_6 * V_7 , T_5 V_31 ,
T_4 V_63 , struct V_82 * V_217 , void * V_192 )
{
struct V_1 * V_84 ;
if ( V_217 )
F_30 ( F_33 ( V_217 , struct V_1 , V_83 ) ) ;
V_84 = F_139 ( V_38 , V_7 , V_31 , F_141 ( V_63 ) ) ;
if ( F_143 ( V_84 ) )
return F_144 ( V_84 ) ;
F_28 ( V_84 ) ;
return & V_84 -> V_83 ;
}
static inline int F_145 ( int V_63 )
{
if ( V_143 == V_214 &&
V_145 == V_215 &&
V_147 == V_216 )
return V_63 ;
switch ( V_63 ) {
default:
case V_143 :
return V_214 ;
case V_145 :
return V_215 ;
case V_147 :
return V_216 ;
}
}
static struct V_1 * F_146 ( const struct V_218 * V_219 , int V_63 ,
const struct V_6 * V_7 )
{
struct V_1 * V_84 ;
F_12 () ;
V_220:
V_84 = F_13 ( V_219 -> V_221 [ V_63 ] ) ;
if ( V_84 != NULL ) {
bool V_206 = F_9 ( & V_84 -> V_125 , V_7 ,
V_219 -> V_222 ) ;
int V_194 = 0 ;
if ( V_206 ) {
if ( ( V_219 -> V_223 & V_84 -> V_184 . V_186 ) != V_84 -> V_184 . V_185 ) {
V_84 = NULL ;
goto V_67;
}
V_194 = F_132 ( V_84 -> V_99 ,
V_7 -> V_208 ,
F_145 ( V_63 ) ) ;
if ( ! V_194 ) {
if ( ! F_1 ( V_84 ) )
goto V_220;
} else if ( V_194 == - V_200 ) {
V_84 = NULL ;
} else {
V_84 = F_17 ( V_194 ) ;
}
} else
V_84 = NULL ;
}
V_67:
F_14 () ;
return V_84 ;
}
static void F_111 ( struct V_1 * V_84 , int V_63 )
{
struct V_38 * V_38 = V_86 ( V_84 ) ;
F_147 ( & V_84 -> V_65 . V_87 , & V_38 -> V_101 . V_205 ) ;
V_38 -> V_101 . V_138 [ V_63 ] ++ ;
F_28 ( V_84 ) ;
}
static struct V_1 * F_114 ( struct V_1 * V_84 ,
int V_63 )
{
struct V_38 * V_38 = V_86 ( V_84 ) ;
if ( F_123 ( & V_84 -> V_65 . V_87 ) )
return NULL ;
if ( ! F_148 ( & V_84 -> V_88 ) ) {
F_67 ( & V_84 -> V_88 ) ;
F_149 ( & V_84 -> V_89 ) ;
}
F_127 ( & V_84 -> V_65 . V_87 ) ;
V_38 -> V_101 . V_138 [ V_63 ] -- ;
return V_84 ;
}
static void F_150 ( struct V_1 * V_84 , int V_63 )
{
F_111 ( V_84 , V_149 + V_63 ) ;
}
static void F_151 ( struct V_1 * V_84 , int V_63 )
{
F_114 ( V_84 , V_149 + V_63 ) ;
}
int F_31 ( struct V_1 * V_84 , int V_63 )
{
struct V_38 * V_38 = V_86 ( V_84 ) ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
V_84 = F_114 ( V_84 , V_63 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
if ( V_84 ) {
F_53 ( V_84 ) ;
return 0 ;
}
return - V_196 ;
}
int F_152 ( struct V_218 * V_219 , int V_63 , struct V_1 * V_84 )
{
struct V_38 * V_38 = V_86 ( V_84 ) ;
struct V_1 * V_224 ;
#ifdef F_140
if ( V_84 && V_84 -> type != V_213 )
return - V_204 ;
#endif
F_76 ( & V_38 -> V_101 . V_115 ) ;
V_224 = F_78 ( V_219 -> V_221 [ V_63 ] ,
F_62 ( & V_38 -> V_101 . V_115 ) ) ;
if ( V_84 ) {
V_84 -> V_72 . V_73 = F_23 () ;
V_84 -> V_68 = F_100 ( V_38 , V_149 + V_63 , 0 ) ;
F_150 ( V_84 , V_63 ) ;
}
F_79 ( V_219 -> V_221 [ V_63 ] , V_84 ) ;
if ( V_224 ) {
if ( V_84 )
F_102 ( V_224 , V_84 ) ;
F_151 ( V_224 , V_63 ) ;
}
F_81 ( & V_38 -> V_101 . V_115 ) ;
if ( V_224 ) {
F_53 ( V_224 ) ;
}
return 0 ;
}
static struct V_1 * F_153 ( const struct V_1 * V_177 , int V_63 )
{
struct V_1 * V_225 = F_36 ( V_86 ( V_177 ) , V_226 ) ;
struct V_38 * V_38 = V_86 ( V_177 ) ;
if ( V_225 ) {
V_225 -> V_125 = V_177 -> V_125 ;
if ( F_154 ( V_177 -> V_99 ,
& V_225 -> V_99 ) ) {
F_47 ( V_225 ) ;
return NULL ;
}
V_225 -> V_69 = V_177 -> V_69 ;
V_225 -> V_72 = V_177 -> V_72 ;
V_225 -> V_184 = V_177 -> V_184 ;
V_225 -> V_227 = V_177 -> V_227 ;
V_225 -> V_50 = V_177 -> V_50 ;
V_225 -> V_228 = V_177 -> V_228 ;
V_225 -> V_68 = V_177 -> V_68 ;
V_225 -> type = V_177 -> type ;
memcpy ( V_225 -> V_229 , V_177 -> V_229 ,
V_225 -> V_228 * sizeof( struct V_230 ) ) ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
F_150 ( V_225 , V_63 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
F_30 ( V_225 ) ;
}
return V_225 ;
}
int F_155 ( struct V_218 * V_219 , const struct V_218 * V_231 )
{
const struct V_1 * V_169 ;
struct V_1 * V_232 ;
int V_131 , V_195 = 0 ;
F_12 () ;
for ( V_131 = 0 ; V_131 < 2 ; V_131 ++ ) {
V_169 = F_13 ( V_231 -> V_221 [ V_131 ] ) ;
if ( V_169 ) {
V_232 = F_153 ( V_169 , V_131 ) ;
if ( F_11 ( ! V_232 ) ) {
V_195 = - V_233 ;
break;
}
F_79 ( V_219 -> V_221 [ V_131 ] , V_232 ) ;
}
}
F_14 () ;
return V_195 ;
}
static int
F_156 ( struct V_38 * V_38 , int V_40 , T_1 * V_234 ,
T_1 * V_235 , unsigned short V_31 )
{
int V_194 ;
struct V_34 * V_35 = F_10 ( V_31 ) ;
if ( F_11 ( V_35 == NULL ) )
return - V_204 ;
V_194 = V_35 -> V_236 ( V_38 , V_40 , V_234 , V_235 ) ;
F_15 ( V_35 ) ;
return V_194 ;
}
static int
F_157 ( struct V_1 * V_2 , const struct V_6 * V_7 ,
struct V_44 * * V_101 , unsigned short V_31 )
{
struct V_38 * V_38 = V_86 ( V_2 ) ;
int V_237 ;
int V_131 , error ;
T_1 * V_12 = F_134 ( V_7 , V_31 ) ;
T_1 * V_15 = F_135 ( V_7 , V_31 ) ;
T_1 V_120 ;
for ( V_237 = 0 , V_131 = 0 ; V_131 < V_2 -> V_228 ; V_131 ++ ) {
struct V_44 * V_45 ;
T_1 * V_235 = V_12 ;
T_1 * V_234 = V_15 ;
struct V_230 * V_238 = & V_2 -> V_229 [ V_131 ] ;
if ( V_238 -> V_239 == V_240 ||
V_238 -> V_239 == V_241 ) {
V_235 = & V_238 -> V_49 . V_12 ;
V_234 = & V_238 -> V_15 ;
if ( F_158 ( V_234 , V_238 -> V_242 ) ) {
error = F_156 ( V_38 , V_7 -> V_243 ,
& V_120 , V_235 ,
V_238 -> V_242 ) ;
if ( error )
goto V_211;
V_234 = & V_120 ;
}
}
V_45 = F_159 ( V_235 , V_234 , V_7 , V_238 , V_2 , & error , V_31 ) ;
if ( V_45 && V_45 -> V_244 . V_245 == V_246 ) {
V_101 [ V_237 ++ ] = V_45 ;
V_12 = V_235 ;
V_15 = V_234 ;
continue;
}
if ( V_45 ) {
error = ( V_45 -> V_244 . V_245 == V_247 ?
- V_204 : - V_248 ) ;
F_160 ( V_45 ) ;
} else if ( error == - V_200 ) {
error = - V_248 ;
}
if ( ! V_238 -> V_249 )
goto V_211;
}
return V_237 ;
V_211:
for ( V_237 -- ; V_237 >= 0 ; V_237 -- )
F_160 ( V_101 [ V_237 ] ) ;
return error ;
}
static int
F_161 ( struct V_1 * * V_250 , int V_251 , const struct V_6 * V_7 ,
struct V_44 * * V_101 , unsigned short V_31 )
{
struct V_44 * V_252 [ V_253 ] ;
struct V_44 * * V_254 = ( V_251 > 1 ) ? V_252 : V_101 ;
int V_255 = 0 ;
int error ;
int V_195 ;
int V_131 ;
for ( V_131 = 0 ; V_131 < V_251 ; V_131 ++ ) {
if ( V_255 + V_250 [ V_131 ] -> V_228 >= V_253 ) {
error = - V_256 ;
goto V_211;
}
V_195 = F_157 ( V_250 [ V_131 ] , V_7 , & V_254 [ V_255 ] , V_31 ) ;
if ( V_195 < 0 ) {
error = V_195 ;
goto V_211;
} else
V_255 += V_195 ;
}
if ( V_251 > 1 )
F_162 ( V_101 , V_254 , V_255 , V_31 ) ;
return V_255 ;
V_211:
for ( V_255 -- ; V_255 >= 0 ; V_255 -- )
F_160 ( V_254 [ V_255 ] ) ;
return error ;
}
static inline int F_163 ( const struct V_6 * V_7 , int V_31 )
{
struct V_34 * V_35 = F_10 ( V_31 ) ;
int V_39 ;
if ( ! V_35 )
return - V_204 ;
V_39 = V_35 -> V_257 ( V_7 ) ;
F_15 ( V_35 ) ;
return V_39 ;
}
static struct V_82 * F_164 ( struct V_82 * V_83 )
{
struct V_258 * V_259 = F_33 ( V_83 , struct V_258 , V_83 ) ;
struct V_37 * V_41 = & V_259 -> V_10 . V_41 ;
if ( V_259 -> V_260 == NULL ) {
if ( V_259 -> V_261 > 0 )
return NULL ;
} else if ( V_41 -> V_50 & V_262 ) {
return NULL ;
} else {
if ( F_165 ( V_41 ) )
return NULL ;
}
F_166 ( V_41 ) ;
return V_83 ;
}
static int F_167 ( struct V_82 * V_83 )
{
struct V_258 * V_259 = F_33 ( V_83 , struct V_258 , V_83 ) ;
struct V_37 * V_41 = & V_259 -> V_10 . V_41 ;
if ( ! V_259 -> V_260 )
return 0 ;
if ( F_165 ( V_41 ) )
return 0 ;
return 1 ;
}
static void F_168 ( struct V_82 * V_83 )
{
struct V_258 * V_259 = F_33 ( V_83 , struct V_258 , V_83 ) ;
struct V_37 * V_41 = & V_259 -> V_10 . V_41 ;
F_169 ( V_41 ) ;
}
static inline struct V_258 * F_170 ( struct V_38 * V_38 , int V_31 )
{
struct V_34 * V_35 = F_10 ( V_31 ) ;
struct V_263 * V_263 ;
struct V_258 * V_259 ;
if ( ! V_35 )
return F_17 ( - V_204 ) ;
switch ( V_31 ) {
case V_32 :
V_263 = & V_38 -> V_101 . V_264 ;
break;
#if F_171 ( V_265 )
case V_33 :
V_263 = & V_38 -> V_101 . V_266 ;
break;
#endif
default:
F_51 () ;
}
V_259 = F_172 ( V_263 , NULL , 0 , V_267 , 0 ) ;
if ( F_173 ( V_259 ) ) {
struct V_37 * V_41 = & V_259 -> V_10 . V_41 ;
memset ( V_41 + 1 , 0 , sizeof( * V_259 ) - sizeof( * V_41 ) ) ;
V_259 -> V_83 . V_94 = & V_268 ;
} else
V_259 = F_17 ( - V_256 ) ;
F_15 ( V_35 ) ;
return V_259 ;
}
static inline int F_174 ( struct V_258 * V_269 , struct V_37 * V_41 ,
int V_270 )
{
struct V_34 * V_35 =
F_10 ( V_41 -> V_94 -> V_31 ) ;
int V_194 ;
if ( ! V_35 )
return - V_204 ;
V_194 = V_35 -> V_271 ( V_269 , V_41 , V_270 ) ;
F_15 ( V_35 ) ;
return V_194 ;
}
static inline int F_175 ( struct V_258 * V_259 , struct V_272 * V_273 ,
const struct V_6 * V_7 )
{
struct V_34 * V_35 =
F_10 ( V_259 -> V_10 . V_41 . V_94 -> V_31 ) ;
int V_194 ;
if ( ! V_35 )
return - V_204 ;
V_194 = V_35 -> V_274 ( V_259 , V_273 , V_7 ) ;
F_15 ( V_35 ) ;
return V_194 ;
}
static struct V_37 * F_176 ( struct V_1 * V_2 ,
struct V_44 * * V_101 , int V_237 ,
const struct V_6 * V_7 ,
struct V_37 * V_41 )
{
struct V_38 * V_38 = V_86 ( V_2 ) ;
unsigned long V_59 = V_81 ;
struct V_272 * V_273 ;
struct V_275 * V_276 ;
struct V_37 * V_277 = NULL ;
struct V_37 * V_278 = NULL ;
int V_131 = 0 ;
int V_194 ;
int V_279 = 0 ;
int V_270 = 0 ;
int V_280 = 0 ;
int V_39 ;
int V_31 = V_2 -> V_125 . V_31 ;
T_1 V_15 , V_12 ;
F_177 ( V_7 , & V_15 , & V_12 , V_31 ) ;
V_39 = F_163 ( V_7 , V_31 ) ;
V_194 = V_39 ;
if ( V_39 < 0 )
goto V_281;
F_166 ( V_41 ) ;
for (; V_131 < V_237 ; V_131 ++ ) {
struct V_258 * V_259 = F_170 ( V_38 , V_31 ) ;
struct V_37 * V_282 = & V_259 -> V_10 . V_41 ;
V_194 = F_178 ( V_259 ) ;
if ( F_20 ( V_259 ) ) {
F_179 ( V_41 ) ;
goto V_281;
}
if ( V_101 [ V_131 ] -> V_5 . V_31 == V_283 ) {
V_276 = F_180 ( V_101 [ V_131 ] ,
F_181 ( V_31 ) ) ;
if ( ! V_276 ) {
V_194 = - V_42 ;
F_179 ( V_41 ) ;
goto V_281;
}
} else
V_276 = V_101 [ V_131 ] -> V_276 ;
if ( ! V_277 )
V_278 = V_282 ;
else {
V_277 -> V_284 = F_182 ( V_282 ) ;
V_282 -> V_50 |= V_285 ;
}
V_259 -> V_260 = V_41 ;
F_183 ( V_282 , V_41 ) ;
if ( V_101 [ V_131 ] -> V_48 . V_239 != V_286 ) {
V_31 = V_101 [ V_131 ] -> V_48 . V_31 ;
V_41 = F_18 ( V_101 [ V_131 ] , V_39 , V_7 -> V_243 ,
& V_15 , & V_12 , V_31 ) ;
V_194 = F_178 ( V_41 ) ;
if ( F_20 ( V_41 ) )
goto V_281;
} else
F_166 ( V_41 ) ;
V_282 -> V_101 = V_101 [ V_131 ] ;
V_259 -> V_287 = V_101 [ V_131 ] -> V_100 ;
V_282 -> V_288 = V_289 ;
V_282 -> V_50 |= V_290 ;
V_282 -> V_291 = V_59 ;
V_282 -> V_292 = V_293 ;
V_282 -> V_294 = V_276 -> V_35 -> V_294 ;
V_282 -> V_60 = V_277 ;
V_277 = V_282 ;
V_279 += V_101 [ V_131 ] -> V_48 . V_279 ;
if ( V_101 [ V_131 ] -> type -> V_50 & V_295 )
V_270 += V_101 [ V_131 ] -> V_48 . V_279 ;
V_280 += V_101 [ V_131 ] -> V_48 . V_280 ;
}
V_277 -> V_284 = V_41 ;
V_278 -> V_269 = V_41 ;
V_194 = - V_296 ;
V_273 = V_41 -> V_273 ;
if ( ! V_273 )
goto V_297;
F_174 ( (struct V_258 * ) V_278 , V_41 , V_270 ) ;
F_184 ( V_277 ) ;
for ( V_277 = V_278 ; V_277 != V_41 ; V_277 = V_277 -> V_284 ) {
struct V_258 * V_259 = (struct V_258 * ) V_277 ;
V_194 = F_175 ( V_259 , V_273 , V_7 ) ;
if ( V_194 )
goto V_297;
V_277 -> V_279 = V_279 ;
V_277 -> V_280 = V_280 ;
V_279 -= V_259 -> V_10 . V_41 . V_101 -> V_48 . V_279 ;
V_280 -= V_259 -> V_10 . V_41 . V_101 -> V_48 . V_280 ;
}
V_67:
return V_278 ;
V_281:
for (; V_131 < V_237 ; V_131 ++ )
F_160 ( V_101 [ V_131 ] ) ;
V_297:
if ( V_278 )
F_169 ( V_278 ) ;
V_278 = F_17 ( V_194 ) ;
goto V_67;
}
static int F_185 ( void * * V_298 , const void * V_299 , int V_300 )
{
if ( ! * V_298 ) {
* V_298 = F_186 ( V_300 , V_226 ) ;
if ( ! * V_298 )
return - V_233 ;
}
memcpy ( * V_298 , V_299 , V_300 ) ;
return 0 ;
}
static int F_187 ( struct V_37 * V_41 ,
const struct V_4 * V_5 )
{
#ifdef F_140
struct V_258 * V_259 = (struct V_258 * ) V_41 ;
return F_185 ( ( void * * ) & ( V_259 -> V_301 ) ,
V_5 , sizeof( * V_5 ) ) ;
#else
return 0 ;
#endif
}
static int F_188 ( struct V_37 * V_41 ,
const struct V_6 * V_7 )
{
#ifdef F_140
struct V_258 * V_259 = (struct V_258 * ) V_41 ;
return F_185 ( ( void * * ) & ( V_259 -> V_302 ) , V_7 , sizeof( * V_7 ) ) ;
#else
return 0 ;
#endif
}
static int F_189 ( const struct V_6 * V_7 , T_5 V_31 ,
struct V_1 * * V_250 ,
int * V_303 , int * V_261 )
{
int V_131 ;
if ( * V_303 == 0 || ! V_250 [ 0 ] ) {
* V_303 = 0 ;
* V_261 = 0 ;
return 0 ;
}
if ( F_20 ( V_250 [ 0 ] ) )
return F_178 ( V_250 [ 0 ] ) ;
* V_261 = V_250 [ 0 ] -> V_228 ;
#ifdef F_140
if ( V_250 [ 0 ] && V_250 [ 0 ] -> V_227 == V_304 &&
V_250 [ 0 ] -> type != V_213 ) {
V_250 [ 1 ] = F_133 ( V_86 ( V_250 [ 0 ] ) ,
V_213 ,
V_7 , V_31 ,
V_145 ) ;
if ( V_250 [ 1 ] ) {
if ( F_20 ( V_250 [ 1 ] ) ) {
F_190 ( V_250 , * V_303 ) ;
return F_178 ( V_250 [ 1 ] ) ;
}
( * V_303 ) ++ ;
( * V_261 ) += V_250 [ 1 ] -> V_228 ;
}
}
#endif
for ( V_131 = 0 ; V_131 < * V_303 ; V_131 ++ ) {
if ( V_250 [ V_131 ] -> V_227 != V_304 ) {
* V_261 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_258 *
F_191 ( struct V_1 * * V_250 , int V_303 ,
const struct V_6 * V_7 , T_5 V_31 ,
struct V_37 * V_305 )
{
struct V_38 * V_38 = V_86 ( V_250 [ 0 ] ) ;
struct V_44 * V_101 [ V_253 ] ;
struct V_37 * V_41 ;
struct V_258 * V_259 ;
int V_194 ;
V_194 = F_161 ( V_250 , V_303 , V_7 , V_101 , V_31 ) ;
if ( V_194 <= 0 ) {
if ( V_194 != 0 && V_194 != - V_248 )
F_192 ( V_38 , V_306 ) ;
return F_17 ( V_194 ) ;
}
V_41 = F_176 ( V_250 [ 0 ] , V_101 , V_194 , V_7 , V_305 ) ;
if ( F_20 ( V_41 ) ) {
F_192 ( V_38 , V_307 ) ;
return F_144 ( V_41 ) ;
}
V_259 = (struct V_258 * ) V_41 ;
V_259 -> V_261 = V_194 ;
if ( V_303 > 1 )
V_194 = F_187 ( V_41 , & V_250 [ 1 ] -> V_125 ) ;
else
V_194 = F_188 ( V_41 , V_7 ) ;
if ( F_11 ( V_194 ) ) {
F_169 ( V_41 ) ;
F_192 ( V_38 , V_308 ) ;
return F_17 ( V_194 ) ;
}
V_259 -> V_303 = V_303 ;
memcpy ( V_259 -> V_250 , V_250 , sizeof( struct V_1 * ) * V_303 ) ;
V_259 -> V_309 = F_193 ( & V_250 [ 0 ] -> V_100 ) ;
return V_259 ;
}
static void V_93 ( unsigned long V_310 )
{
struct V_311 * V_312 ;
struct V_218 * V_219 ;
struct V_37 * V_41 ;
struct V_1 * V_84 = (struct V_1 * ) V_310 ;
struct V_38 * V_38 = V_86 ( V_84 ) ;
struct V_179 * V_180 = & V_84 -> V_90 ;
struct V_6 V_7 ;
struct V_181 V_116 ;
F_194 ( & V_180 -> V_91 . V_64 ) ;
V_312 = F_195 ( & V_180 -> V_91 ) ;
if ( ! V_312 ) {
F_196 ( & V_180 -> V_91 . V_64 ) ;
goto V_67;
}
V_41 = F_197 ( V_312 ) ;
V_219 = V_312 -> V_219 ;
F_198 ( V_312 , & V_7 , V_41 -> V_94 -> V_31 ) ;
F_196 ( & V_180 -> V_91 . V_64 ) ;
F_166 ( V_41 -> V_269 ) ;
V_41 = F_199 ( V_38 , V_41 -> V_269 , & V_7 , V_219 , 0 ) ;
if ( F_20 ( V_41 ) )
goto V_313;
if ( V_41 -> V_50 & V_262 ) {
F_179 ( V_41 ) ;
if ( V_180 -> V_182 >= V_314 )
goto V_313;
V_180 -> V_182 = V_180 -> V_182 << 1 ;
if ( ! F_27 ( & V_180 -> V_92 , V_81 + V_180 -> V_182 ) )
F_28 ( V_84 ) ;
goto V_67;
}
F_179 ( V_41 ) ;
F_104 ( & V_116 ) ;
F_194 ( & V_180 -> V_91 . V_64 ) ;
V_180 -> V_182 = 0 ;
F_105 ( & V_180 -> V_91 , & V_116 ) ;
F_196 ( & V_180 -> V_91 . V_64 ) ;
while ( ! F_103 ( & V_116 ) ) {
V_312 = F_200 ( & V_116 ) ;
F_198 ( V_312 , & V_7 , F_197 ( V_312 ) -> V_94 -> V_31 ) ;
F_166 ( F_197 ( V_312 ) -> V_269 ) ;
V_41 = F_199 ( V_38 , F_197 ( V_312 ) -> V_269 , & V_7 , V_312 -> V_219 , 0 ) ;
if ( F_20 ( V_41 ) ) {
F_201 ( V_312 ) ;
continue;
}
F_202 ( V_312 ) ;
F_203 ( V_312 ) ;
F_204 ( V_312 , V_41 ) ;
F_205 ( V_38 , V_312 -> V_219 , V_312 ) ;
}
V_67:
F_30 ( V_84 ) ;
return;
V_313:
V_180 -> V_182 = 0 ;
F_55 ( & V_180 -> V_91 ) ;
F_30 ( V_84 ) ;
}
static int F_206 ( struct V_38 * V_38 , struct V_218 * V_219 , struct V_311 * V_312 )
{
unsigned long V_315 ;
struct V_37 * V_41 = F_197 ( V_312 ) ;
struct V_258 * V_259 = (struct V_258 * ) V_41 ;
struct V_1 * V_84 = V_259 -> V_250 [ 0 ] ;
struct V_179 * V_180 = & V_84 -> V_90 ;
if ( F_11 ( F_207 ( V_219 , V_312 ) ) ) {
F_201 ( V_312 ) ;
return 0 ;
}
if ( V_180 -> V_91 . V_316 > V_317 ) {
F_201 ( V_312 ) ;
return - V_248 ;
}
F_208 ( V_312 ) ;
F_76 ( & V_180 -> V_91 . V_64 ) ;
if ( ! V_180 -> V_182 )
V_180 -> V_182 = V_183 ;
V_315 = V_81 + V_180 -> V_182 ;
if ( F_50 ( & V_180 -> V_92 ) ) {
if ( F_209 ( V_180 -> V_92 . V_318 , V_315 ) )
V_315 = V_180 -> V_92 . V_318 ;
F_30 ( V_84 ) ;
}
F_210 ( & V_180 -> V_91 , V_312 ) ;
if ( ! F_27 ( & V_180 -> V_92 , V_315 ) )
F_28 ( V_84 ) ;
F_81 ( & V_180 -> V_91 . V_64 ) ;
return 0 ;
}
static struct V_258 * F_211 ( struct V_38 * V_38 ,
struct V_319 * V_320 ,
const struct V_6 * V_7 ,
int V_261 ,
T_5 V_31 )
{
int V_194 ;
struct V_272 * V_273 ;
struct V_37 * V_41 ;
struct V_37 * V_282 ;
struct V_258 * V_259 ;
V_259 = F_170 ( V_38 , V_31 ) ;
if ( F_20 ( V_259 ) )
return V_259 ;
if ( ! ( V_320 -> V_50 & V_321 ) ||
V_38 -> V_101 . V_322 ||
V_261 <= 0 )
return V_259 ;
V_41 = V_320 -> V_305 ;
V_282 = & V_259 -> V_10 . V_41 ;
F_166 ( V_41 ) ;
V_259 -> V_260 = V_41 ;
F_183 ( V_282 , V_41 ) ;
V_282 -> V_288 = V_289 ;
V_282 -> V_50 |= V_290 | V_262 ;
V_282 -> V_291 = V_81 ;
V_282 -> V_292 = V_293 ;
V_282 -> V_294 = F_206 ;
F_166 ( V_41 ) ;
V_282 -> V_284 = V_41 ;
V_282 -> V_269 = V_41 ;
F_174 ( (struct V_258 * ) V_282 , V_41 , 0 ) ;
V_194 = - V_296 ;
V_273 = V_41 -> V_273 ;
if ( ! V_273 )
goto V_297;
V_194 = F_175 ( V_259 , V_273 , V_7 ) ;
if ( V_194 )
goto V_297;
V_67:
return V_259 ;
V_297:
F_179 ( V_282 ) ;
V_259 = F_17 ( V_194 ) ;
goto V_67;
}
static struct V_82 *
F_212 ( struct V_38 * V_38 , const struct V_6 * V_7 , T_5 V_31 , T_4 V_63 ,
struct V_82 * V_323 , void * V_192 )
{
struct V_319 * V_320 = (struct V_319 * ) V_192 ;
struct V_1 * V_250 [ V_202 ] ;
struct V_258 * V_259 , * V_324 ;
int V_303 = 0 , V_261 = 0 , V_131 , V_194 , V_325 ;
V_259 = NULL ;
if ( V_323 ) {
V_259 = F_33 ( V_323 , struct V_258 , V_83 ) ;
V_303 = V_259 -> V_303 ;
V_261 = V_259 -> V_261 ;
V_325 = 0 ;
for ( V_131 = 0 ; V_131 < V_303 ; V_131 ++ ) {
V_250 [ V_131 ] = V_259 -> V_250 [ V_131 ] ;
V_325 |= V_250 [ V_131 ] -> V_65 . V_66 ;
}
if ( V_325 ) {
F_169 ( & V_259 -> V_10 . V_41 ) ;
V_259 = NULL ;
V_303 = 0 ;
V_261 = 0 ;
V_323 = NULL ;
}
}
if ( V_259 == NULL ) {
V_303 = 1 ;
V_250 [ 0 ] = F_139 ( V_38 , V_7 , V_31 ,
F_141 ( V_63 ) ) ;
V_194 = F_189 ( V_7 , V_31 , V_250 ,
& V_303 , & V_261 ) ;
if ( V_194 < 0 )
goto V_326;
if ( V_303 == 0 )
return NULL ;
if ( V_261 <= 0 )
goto V_327;
}
V_324 = F_191 ( V_250 , V_303 , V_7 , V_31 ,
V_320 -> V_305 ) ;
if ( F_20 ( V_324 ) ) {
V_194 = F_178 ( V_324 ) ;
if ( V_194 != - V_248 )
goto error;
if ( V_323 == NULL )
goto V_327;
F_166 ( & V_259 -> V_10 . V_41 ) ;
return V_323 ;
} else if ( V_324 == NULL ) {
V_261 = 0 ;
if ( V_323 == NULL )
goto V_327;
V_259 -> V_261 = 0 ;
F_166 ( & V_259 -> V_10 . V_41 ) ;
return V_323 ;
}
if ( V_259 ) {
V_259 -> V_303 = 0 ;
F_169 ( & V_259 -> V_10 . V_41 ) ;
}
F_166 ( & V_324 -> V_10 . V_41 ) ;
return & V_324 -> V_83 ;
V_327:
V_259 = F_211 ( V_38 , V_320 , V_7 , V_261 , V_31 ) ;
if ( F_20 ( V_259 ) ) {
F_190 ( V_250 , V_303 ) ;
return F_144 ( V_259 ) ;
}
V_259 -> V_303 = V_303 ;
V_259 -> V_261 = V_261 ;
memcpy ( V_259 -> V_250 , V_250 , sizeof( struct V_1 * ) * V_303 ) ;
F_166 ( & V_259 -> V_10 . V_41 ) ;
return & V_259 -> V_83 ;
V_326:
F_192 ( V_38 , V_306 ) ;
error:
if ( V_259 != NULL )
F_169 ( & V_259 -> V_10 . V_41 ) ;
else
F_190 ( V_250 , V_303 ) ;
return F_17 ( V_194 ) ;
}
static struct V_37 * F_213 ( struct V_38 * V_38 , T_5 V_31 ,
struct V_37 * V_305 )
{
struct V_34 * V_35 = F_10 ( V_31 ) ;
struct V_37 * V_195 ;
if ( ! V_35 ) {
F_179 ( V_305 ) ;
return F_17 ( - V_204 ) ;
} else {
V_195 = V_35 -> V_328 ( V_38 , V_305 ) ;
}
F_15 ( V_35 ) ;
return V_195 ;
}
struct V_37 * F_199 ( struct V_38 * V_38 , struct V_37 * V_305 ,
const struct V_6 * V_7 ,
const struct V_218 * V_219 , int V_50 )
{
struct V_1 * V_250 [ V_202 ] ;
struct V_82 * V_83 ;
struct V_258 * V_259 ;
struct V_37 * V_41 , * V_260 ;
T_5 V_31 = V_305 -> V_94 -> V_31 ;
T_4 V_63 = F_145 ( V_145 ) ;
int V_131 , V_194 , V_303 , V_261 = 0 , V_329 = 0 ;
V_41 = NULL ;
V_259 = NULL ;
V_260 = NULL ;
V_219 = F_214 ( V_219 ) ;
if ( V_219 && V_219 -> V_221 [ V_145 ] ) {
V_303 = 1 ;
V_250 [ 0 ] = F_146 ( V_219 , V_145 , V_7 ) ;
V_194 = F_189 ( V_7 , V_31 , V_250 ,
& V_303 , & V_261 ) ;
if ( V_194 < 0 )
goto V_330;
if ( V_303 ) {
if ( V_261 <= 0 ) {
V_329 = V_303 ;
goto V_331;
}
V_259 = F_191 (
V_250 , V_303 , V_7 ,
V_31 , V_305 ) ;
if ( F_20 ( V_259 ) ) {
F_190 ( V_250 , V_303 ) ;
V_194 = F_178 ( V_259 ) ;
goto V_330;
} else if ( V_259 == NULL ) {
V_261 = 0 ;
V_329 = V_303 ;
goto V_331;
}
F_166 ( & V_259 -> V_10 . V_41 ) ;
V_259 -> V_10 . V_41 . V_50 |= V_332 ;
V_260 = V_259 -> V_260 ;
}
}
if ( V_259 == NULL ) {
struct V_319 V_320 ;
V_320 . V_305 = V_305 ;
V_320 . V_50 = V_50 ;
if ( ( V_305 -> V_50 & V_333 ) ||
! V_38 -> V_101 . V_138 [ V_145 ] )
goto V_334;
V_83 = F_215 ( V_38 , V_7 , V_31 , V_63 ,
F_212 , & V_320 ) ;
if ( V_83 == NULL )
goto V_334;
if ( F_20 ( V_83 ) ) {
V_194 = F_178 ( V_83 ) ;
goto V_330;
}
V_259 = F_33 ( V_83 , struct V_258 , V_83 ) ;
V_303 = V_259 -> V_303 ;
V_261 = V_259 -> V_261 ;
memcpy ( V_250 , V_259 -> V_250 , sizeof( struct V_1 * ) * V_303 ) ;
V_260 = V_259 -> V_260 ;
}
V_41 = & V_259 -> V_10 . V_41 ;
if ( V_260 == NULL && V_261 > 0 ) {
if ( V_38 -> V_101 . V_322 ) {
F_192 ( V_38 , V_335 ) ;
V_194 = - V_336 ;
goto error;
}
V_194 = - V_248 ;
F_192 ( V_38 , V_335 ) ;
goto error;
}
V_331:
if ( V_303 == 0 )
goto V_334;
if ( ( V_50 & V_337 ) &&
! ( V_250 [ 0 ] -> V_50 & V_338 ) ) {
V_194 = - V_196 ;
goto error;
}
for ( V_131 = 0 ; V_131 < V_303 ; V_131 ++ )
V_250 [ V_131 ] -> V_72 . V_76 = F_23 () ;
if ( V_261 < 0 ) {
F_192 ( V_38 , V_339 ) ;
V_194 = - V_340 ;
goto error;
} else if ( V_261 > 0 ) {
F_179 ( V_305 ) ;
} else {
F_179 ( V_41 ) ;
V_41 = V_305 ;
}
V_341:
F_190 ( V_250 , V_329 ) ;
if ( V_41 && V_41 -> V_101 &&
V_41 -> V_101 -> V_48 . V_239 == V_240 )
V_41 -> V_50 |= V_342 ;
return V_41 ;
V_334:
if ( ! ( V_50 & V_337 ) ) {
V_41 = V_305 ;
goto V_341;
}
V_194 = - V_196 ;
error:
F_179 ( V_41 ) ;
V_330:
if ( ! ( V_50 & V_343 ) )
F_179 ( V_305 ) ;
F_190 ( V_250 , V_329 ) ;
return F_17 ( V_194 ) ;
}
struct V_37 * F_216 ( struct V_38 * V_38 , struct V_37 * V_305 ,
const struct V_6 * V_7 ,
const struct V_218 * V_219 , int V_50 )
{
struct V_37 * V_41 = F_199 ( V_38 , V_305 , V_7 , V_219 ,
V_50 | V_321 |
V_343 ) ;
if ( F_20 ( V_41 ) && F_178 ( V_41 ) == - V_336 )
return F_213 ( V_38 , V_305 -> V_94 -> V_31 , V_305 ) ;
return V_41 ;
}
static inline int
F_217 ( int V_170 , struct V_311 * V_312 , const struct V_6 * V_7 )
{
struct V_44 * V_45 ;
if ( ! V_312 -> V_344 || V_170 < 0 || V_170 >= V_312 -> V_344 -> V_176 )
return 0 ;
V_45 = V_312 -> V_344 -> V_345 [ V_170 ] ;
if ( ! V_45 -> type -> V_346 )
return 0 ;
return V_45 -> type -> V_346 ( V_45 , V_312 , V_7 ) ;
}
static inline int
F_218 ( const struct V_230 * V_238 , const struct V_44 * V_45 ,
unsigned short V_31 )
{
if ( F_219 ( V_45 ) )
return V_238 -> V_249 && ! F_220 ( V_238 , V_45 , V_238 -> V_242 ) ;
return V_45 -> V_49 . V_23 == V_238 -> V_49 . V_23 &&
( V_45 -> V_49 . V_347 == V_238 -> V_49 . V_347 || ! V_238 -> V_49 . V_347 ) &&
( V_45 -> V_48 . V_348 == V_238 -> V_348 || ! V_238 -> V_348 ) &&
V_45 -> V_48 . V_239 == V_238 -> V_239 &&
( V_238 -> V_349 || ( V_238 -> V_350 & ( 1 << V_45 -> V_48 . V_351 ) ) ||
! ( F_221 ( V_238 -> V_49 . V_23 , V_352 ) ) ) &&
! ( V_45 -> V_48 . V_239 != V_286 &&
F_220 ( V_238 , V_45 , V_31 ) ) ;
}
static inline int
F_222 ( const struct V_230 * V_238 , const struct V_353 * V_344 , int V_354 ,
unsigned short V_31 )
{
int V_170 = V_354 ;
if ( V_238 -> V_249 ) {
if ( V_238 -> V_239 == V_286 )
return V_354 ;
} else
V_354 = - 1 ;
for (; V_170 < V_344 -> V_176 ; V_170 ++ ) {
if ( F_218 ( V_238 , V_344 -> V_345 [ V_170 ] , V_31 ) )
return ++ V_170 ;
if ( V_344 -> V_345 [ V_170 ] -> V_48 . V_239 != V_286 ) {
if ( V_354 == - 1 )
V_354 = - 2 - V_170 ;
break;
}
}
return V_354 ;
}
int F_223 ( struct V_311 * V_312 , struct V_6 * V_7 ,
unsigned int V_31 , int V_355 )
{
struct V_34 * V_35 = F_10 ( V_31 ) ;
int V_194 ;
if ( F_11 ( V_35 == NULL ) )
return - V_42 ;
V_35 -> V_356 ( V_312 , V_7 , V_355 ) ;
V_194 = F_224 ( V_312 , & V_7 -> V_208 ) ;
F_15 ( V_35 ) ;
return V_194 ;
}
static inline int F_225 ( const struct V_353 * V_344 , int V_357 , int * V_358 )
{
for (; V_357 < V_344 -> V_176 ; V_357 ++ ) {
if ( V_344 -> V_345 [ V_357 ] -> V_48 . V_239 != V_286 ) {
* V_358 = V_357 ;
return 1 ;
}
}
return 0 ;
}
int F_226 ( struct V_218 * V_219 , int V_63 , struct V_311 * V_312 ,
unsigned short V_31 )
{
struct V_38 * V_38 = F_227 ( V_312 -> V_273 ) ;
struct V_1 * V_84 ;
struct V_1 * V_250 [ V_202 ] ;
int V_251 = 0 ;
int V_228 ;
int V_359 ;
int V_355 ;
struct V_6 V_7 ;
T_4 V_360 ;
int V_361 = - 1 ;
V_355 = V_63 & ~ V_166 ;
V_63 &= V_166 ;
V_360 = F_145 ( V_63 ) ;
if ( F_223 ( V_312 , & V_7 , V_31 , V_355 ) < 0 ) {
F_192 ( V_38 , V_362 ) ;
return 0 ;
}
F_228 ( V_312 , & V_7 , V_31 ) ;
if ( V_312 -> V_344 ) {
int V_131 ;
for ( V_131 = V_312 -> V_344 -> V_176 - 1 ; V_131 >= 0 ; V_131 -- ) {
struct V_44 * V_45 = V_312 -> V_344 -> V_345 [ V_131 ] ;
if ( ! F_9 ( & V_45 -> V_5 , & V_7 , V_31 ) ) {
F_192 ( V_38 , V_363 ) ;
return 0 ;
}
}
}
V_84 = NULL ;
V_219 = F_229 ( V_219 ) ;
if ( V_219 && V_219 -> V_221 [ V_63 ] ) {
V_84 = F_146 ( V_219 , V_63 , & V_7 ) ;
if ( F_20 ( V_84 ) ) {
F_192 ( V_38 , V_364 ) ;
return 0 ;
}
}
if ( ! V_84 ) {
struct V_82 * V_83 ;
V_83 = F_215 ( V_38 , & V_7 , V_31 , V_360 ,
F_142 , NULL ) ;
if ( F_143 ( V_83 ) )
V_84 = F_144 ( V_83 ) ;
else
V_84 = F_33 ( V_83 , struct V_1 , V_83 ) ;
}
if ( F_20 ( V_84 ) ) {
F_192 ( V_38 , V_364 ) ;
return 0 ;
}
if ( ! V_84 ) {
if ( V_312 -> V_344 && F_225 ( V_312 -> V_344 , 0 , & V_361 ) ) {
F_217 ( V_361 , V_312 , & V_7 ) ;
F_192 ( V_38 , V_365 ) ;
return 0 ;
}
return 1 ;
}
V_84 -> V_72 . V_76 = F_23 () ;
V_250 [ 0 ] = V_84 ;
V_251 ++ ;
#ifdef F_140
if ( V_250 [ 0 ] -> type != V_213 ) {
V_250 [ 1 ] = F_133 ( V_38 , V_213 ,
& V_7 , V_31 ,
V_143 ) ;
if ( V_250 [ 1 ] ) {
if ( F_20 ( V_250 [ 1 ] ) ) {
F_192 ( V_38 , V_364 ) ;
return 0 ;
}
V_250 [ 1 ] -> V_72 . V_76 = F_23 () ;
V_251 ++ ;
}
}
#endif
if ( V_84 -> V_227 == V_304 ) {
struct V_353 * V_344 ;
static struct V_353 V_366 ;
struct V_230 * V_252 [ V_253 ] ;
struct V_230 * V_367 [ V_253 ] ;
struct V_230 * * V_254 = V_252 ;
int V_368 = 0 ;
int V_131 , V_357 ;
if ( ( V_344 = V_312 -> V_344 ) == NULL )
V_344 = & V_366 ;
for ( V_359 = 0 ; V_359 < V_251 ; V_359 ++ ) {
if ( V_250 [ V_359 ] != V_84 &&
V_250 [ V_359 ] -> V_227 != V_304 ) {
F_192 ( V_38 , V_369 ) ;
goto V_346;
}
if ( V_368 + V_250 [ V_359 ] -> V_228 >= V_253 ) {
F_192 ( V_38 , V_370 ) ;
goto V_371;
}
for ( V_131 = 0 ; V_131 < V_250 [ V_359 ] -> V_228 ; V_131 ++ )
V_254 [ V_368 ++ ] = & V_250 [ V_359 ] -> V_229 [ V_131 ] ;
}
V_228 = V_368 ;
if ( V_251 > 1 ) {
F_230 ( V_367 , V_254 , V_228 , V_31 , V_38 ) ;
V_254 = V_367 ;
}
for ( V_131 = V_228 - 1 , V_357 = 0 ; V_131 >= 0 ; V_131 -- ) {
V_357 = F_222 ( V_254 [ V_131 ] , V_344 , V_357 , V_31 ) ;
if ( V_357 < 0 ) {
if ( V_357 < - 1 )
V_361 = - ( 2 + V_357 ) ;
F_192 ( V_38 , V_372 ) ;
goto V_346;
}
}
if ( F_225 ( V_344 , V_357 , & V_361 ) ) {
F_192 ( V_38 , V_372 ) ;
goto V_346;
}
F_190 ( V_250 , V_251 ) ;
return 1 ;
}
F_192 ( V_38 , V_369 ) ;
V_346:
F_217 ( V_361 , V_312 , & V_7 ) ;
V_371:
F_190 ( V_250 , V_251 ) ;
return 0 ;
}
int F_231 ( struct V_311 * V_312 , unsigned short V_31 )
{
struct V_38 * V_38 = F_227 ( V_312 -> V_273 ) ;
struct V_6 V_7 ;
struct V_37 * V_41 ;
int V_373 = 1 ;
if ( F_198 ( V_312 , & V_7 , V_31 ) < 0 ) {
F_192 ( V_38 , V_374 ) ;
return 0 ;
}
F_208 ( V_312 ) ;
V_41 = F_199 ( V_38 , F_197 ( V_312 ) , & V_7 , NULL , V_321 ) ;
if ( F_20 ( V_41 ) ) {
V_373 = 0 ;
V_41 = NULL ;
}
F_204 ( V_312 , V_41 ) ;
return V_373 ;
}
static struct V_37 * F_232 ( struct V_37 * V_41 , T_3 V_375 )
{
if ( V_41 -> V_288 < 0 && ! F_165 ( V_41 ) )
return V_41 ;
return NULL ;
}
static int F_165 ( struct V_37 * V_41 )
{
return ! F_233 ( (struct V_258 * ) V_41 ) ;
}
void F_234 ( struct V_37 * V_41 , struct V_272 * V_273 )
{
while ( ( V_41 = V_41 -> V_284 ) && V_41 -> V_101 && V_41 -> V_273 == V_273 ) {
V_41 -> V_273 = F_227 ( V_273 ) -> V_376 ;
F_235 ( V_41 -> V_273 ) ;
F_236 ( V_273 ) ;
}
}
static void F_237 ( struct V_311 * V_312 )
{
}
static struct V_37 * F_238 ( struct V_37 * V_41 )
{
if ( V_41 ) {
if ( V_41 -> V_288 ) {
F_179 ( V_41 ) ;
V_41 = NULL ;
}
}
return V_41 ;
}
void F_239 ( struct V_38 * V_38 )
{
F_240 ( V_38 ) ;
}
static void F_241 ( struct V_38 * V_38 )
{
F_242 ( V_38 ) ;
}
static void F_184 ( struct V_37 * V_41 )
{
do {
struct V_258 * V_259 = (struct V_258 * ) V_41 ;
T_3 V_377 , V_378 ;
V_377 = F_243 ( V_41 -> V_284 ) ;
V_259 -> V_379 = V_377 ;
V_377 = F_244 ( V_41 -> V_101 , V_377 ) ;
V_378 = F_243 ( V_259 -> V_260 ) ;
V_259 -> V_378 = V_378 ;
if ( V_377 > V_378 )
V_377 = V_378 ;
F_245 ( V_41 , V_380 , V_377 ) ;
} while ( ( V_41 = V_41 -> V_60 ) );
}
static int F_233 ( struct V_258 * V_381 )
{
struct V_37 * V_41 = & V_381 -> V_10 . V_41 ;
struct V_258 * V_382 ;
T_3 V_383 ;
if ( ! F_246 ( V_41 -> V_269 , ( (struct V_258 * ) V_41 ) -> V_384 ) ||
( V_41 -> V_273 && ! F_247 ( V_41 -> V_273 ) ) )
return 0 ;
if ( V_41 -> V_50 & V_262 )
return 1 ;
V_382 = NULL ;
do {
struct V_258 * V_259 = (struct V_258 * ) V_41 ;
if ( V_41 -> V_101 -> V_244 . V_245 != V_246 )
return 0 ;
if ( V_259 -> V_287 != V_41 -> V_101 -> V_100 )
return 0 ;
if ( V_259 -> V_303 > 0 &&
V_259 -> V_309 != F_193 ( & V_259 -> V_250 [ 0 ] -> V_100 ) )
return 0 ;
V_383 = F_243 ( V_41 -> V_284 ) ;
if ( V_259 -> V_379 != V_383 ) {
V_382 = V_259 ;
V_259 -> V_379 = V_383 ;
}
if ( ! F_246 ( V_259 -> V_260 , V_259 -> V_385 ) )
return 0 ;
V_383 = F_243 ( V_259 -> V_260 ) ;
if ( V_259 -> V_378 != V_383 ) {
V_382 = V_259 ;
V_259 -> V_378 = V_383 ;
}
V_41 = V_41 -> V_284 ;
} while ( V_41 -> V_101 );
if ( F_173 ( ! V_382 ) )
return 1 ;
V_383 = V_382 -> V_379 ;
for (; ; ) {
V_41 = & V_382 -> V_10 . V_41 ;
V_383 = F_244 ( V_41 -> V_101 , V_383 ) ;
if ( V_383 > V_382 -> V_378 )
V_383 = V_382 -> V_378 ;
F_245 ( V_41 , V_380 , V_383 ) ;
if ( V_382 == V_381 )
break;
V_382 = (struct V_258 * ) V_382 -> V_10 . V_41 . V_60 ;
V_382 -> V_379 = V_383 ;
}
return 1 ;
}
static unsigned int F_248 ( const struct V_37 * V_41 )
{
return F_249 ( V_41 -> V_269 ) ;
}
static unsigned int F_250 ( const struct V_37 * V_41 )
{
unsigned int V_383 = F_251 ( V_41 , V_380 ) ;
return V_383 ? : F_243 ( V_41 -> V_269 ) ;
}
static struct V_386 * F_252 ( const struct V_37 * V_41 ,
struct V_311 * V_312 ,
const void * V_12 )
{
return V_41 -> V_269 -> V_94 -> V_387 ( V_41 , V_312 , V_12 ) ;
}
int F_253 ( struct V_34 * V_35 )
{
int V_194 = 0 ;
if ( F_11 ( V_35 == NULL ) )
return - V_204 ;
if ( F_11 ( V_35 -> V_31 >= V_36 ) )
return - V_42 ;
F_194 ( & V_388 ) ;
if ( F_11 ( V_34 [ V_35 -> V_31 ] != NULL ) )
V_194 = - V_189 ;
else {
struct V_263 * V_263 = V_35 -> V_263 ;
if ( F_173 ( V_263 -> V_389 == NULL ) )
V_263 -> V_389 = V_390 ;
if ( F_173 ( V_263 -> V_391 == NULL ) )
V_263 -> V_391 = F_232 ;
if ( F_173 ( V_263 -> V_392 == NULL ) )
V_263 -> V_392 = F_248 ;
if ( F_173 ( V_263 -> V_383 == NULL ) )
V_263 -> V_383 = F_250 ;
if ( F_173 ( V_263 -> V_393 == NULL ) )
V_263 -> V_393 = F_238 ;
if ( F_173 ( V_263 -> V_394 == NULL ) )
V_263 -> V_394 = F_237 ;
if ( F_173 ( V_263 -> V_387 == NULL ) )
V_263 -> V_387 = F_252 ;
if ( F_173 ( V_35 -> V_395 == NULL ) )
V_35 -> V_395 = F_241 ;
F_79 ( V_34 [ V_35 -> V_31 ] , V_35 ) ;
}
F_196 ( & V_388 ) ;
return V_194 ;
}
int F_254 ( struct V_34 * V_35 )
{
int V_194 = 0 ;
if ( F_11 ( V_35 == NULL ) )
return - V_204 ;
if ( F_11 ( V_35 -> V_31 >= V_36 ) )
return - V_42 ;
F_194 ( & V_388 ) ;
if ( F_173 ( V_34 [ V_35 -> V_31 ] != NULL ) ) {
if ( F_11 ( V_34 [ V_35 -> V_31 ] != V_35 ) )
V_194 = - V_204 ;
else
F_255 ( V_34 [ V_35 -> V_31 ] ,
NULL ) ;
}
F_196 ( & V_388 ) ;
if ( ! V_194 ) {
struct V_263 * V_263 = V_35 -> V_263 ;
F_82 () ;
V_263 -> V_389 = NULL ;
V_263 -> V_391 = NULL ;
V_263 -> V_393 = NULL ;
V_263 -> V_394 = NULL ;
V_35 -> V_395 = NULL ;
}
return V_194 ;
}
static int F_256 ( struct V_396 * V_397 , unsigned long V_398 , void * V_399 )
{
struct V_272 * V_273 = F_257 ( V_399 ) ;
switch ( V_398 ) {
case V_400 :
F_239 ( F_227 ( V_273 ) ) ;
}
return V_401 ;
}
static int T_6 F_258 ( struct V_38 * V_38 )
{
int V_402 ;
V_38 -> V_403 . V_404 = F_259 ( struct V_405 ) ;
if ( ! V_38 -> V_403 . V_404 )
return - V_233 ;
V_402 = F_260 ( V_38 ) ;
if ( V_402 < 0 )
F_261 ( V_38 -> V_403 . V_404 ) ;
return V_402 ;
}
static void F_262 ( struct V_38 * V_38 )
{
F_263 ( V_38 ) ;
F_261 ( V_38 -> V_403 . V_404 ) ;
}
static int T_6 F_258 ( struct V_38 * V_38 )
{
return 0 ;
}
static void F_262 ( struct V_38 * V_38 )
{
}
static int T_6 F_264 ( struct V_38 * V_38 )
{
unsigned int V_111 , V_406 ;
int V_63 ;
if ( F_265 ( V_38 , & V_407 ) )
V_390 = F_266 ( L_1 ,
sizeof( struct V_258 ) ,
0 , V_408 | V_409 ,
NULL ) ;
V_111 = 8 - 1 ;
V_406 = ( V_111 + 1 ) * sizeof( struct V_110 ) ;
V_38 -> V_101 . V_135 = F_75 ( V_406 ) ;
if ( ! V_38 -> V_101 . V_135 )
goto V_410;
V_38 -> V_101 . V_102 = V_111 ;
for ( V_63 = 0 ; V_63 < V_149 ; V_63 ++ ) {
struct V_411 * V_412 ;
V_38 -> V_101 . V_138 [ V_63 ] = 0 ;
V_38 -> V_101 . V_138 [ V_149 + V_63 ] = 0 ;
F_94 ( & V_38 -> V_101 . V_113 [ V_63 ] ) ;
V_412 = & V_38 -> V_101 . V_105 [ V_63 ] ;
V_412 -> V_114 = F_75 ( V_406 ) ;
if ( ! V_412 -> V_114 )
goto V_413;
V_412 -> V_111 = V_111 ;
V_412 -> V_106 = 32 ;
V_412 -> V_107 = 32 ;
V_412 -> V_108 = 128 ;
V_412 -> V_109 = 128 ;
}
V_38 -> V_101 . V_158 . V_162 = 32 ;
V_38 -> V_101 . V_158 . V_163 = 32 ;
V_38 -> V_101 . V_158 . V_164 = 128 ;
V_38 -> V_101 . V_158 . V_165 = 128 ;
F_267 ( & V_38 -> V_101 . V_158 . V_64 ) ;
F_39 ( & V_38 -> V_101 . V_205 ) ;
F_268 ( & V_38 -> V_101 . V_156 , F_88 ) ;
F_268 ( & V_38 -> V_101 . V_158 . V_155 , F_91 ) ;
if ( F_265 ( V_38 , & V_407 ) )
F_269 ( & V_414 ) ;
return 0 ;
V_413:
for ( V_63 -- ; V_63 >= 0 ; V_63 -- ) {
struct V_411 * V_412 ;
V_412 = & V_38 -> V_101 . V_105 [ V_63 ] ;
F_83 ( V_412 -> V_114 , V_406 ) ;
}
F_83 ( V_38 -> V_101 . V_135 , V_406 ) ;
V_410:
return - V_233 ;
}
static void F_270 ( struct V_38 * V_38 )
{
unsigned int V_406 ;
int V_63 ;
F_271 ( & V_38 -> V_101 . V_156 ) ;
#ifdef F_140
F_120 ( V_38 , V_212 , false ) ;
#endif
F_120 ( V_38 , V_213 , false ) ;
F_110 ( ! F_123 ( & V_38 -> V_101 . V_205 ) ) ;
for ( V_63 = 0 ; V_63 < V_149 ; V_63 ++ ) {
struct V_411 * V_412 ;
F_110 ( ! F_70 ( & V_38 -> V_101 . V_113 [ V_63 ] ) ) ;
V_412 = & V_38 -> V_101 . V_105 [ V_63 ] ;
V_406 = ( V_412 -> V_111 + 1 ) * sizeof( struct V_110 ) ;
F_110 ( ! F_70 ( V_412 -> V_114 ) ) ;
F_83 ( V_412 -> V_114 , V_406 ) ;
}
V_406 = ( V_38 -> V_101 . V_102 + 1 ) * sizeof( struct V_110 ) ;
F_110 ( ! F_70 ( V_38 -> V_101 . V_135 ) ) ;
F_83 ( V_38 -> V_101 . V_135 , V_406 ) ;
}
static int T_6 F_272 ( struct V_38 * V_38 )
{
int V_402 ;
V_402 = F_258 ( V_38 ) ;
if ( V_402 < 0 )
goto V_415;
V_402 = F_273 ( V_38 ) ;
if ( V_402 < 0 )
goto V_416;
V_402 = F_264 ( V_38 ) ;
if ( V_402 < 0 )
goto V_417;
V_402 = F_274 ( V_38 ) ;
if ( V_402 < 0 )
goto V_418;
V_402 = F_275 ( V_38 ) ;
if ( V_402 < 0 )
goto V_67;
F_276 ( & V_38 -> V_101 . V_419 ) ;
F_276 ( & V_38 -> V_101 . V_115 ) ;
F_277 ( & V_38 -> V_101 . V_420 ) ;
return 0 ;
V_67:
F_278 ( V_38 ) ;
V_418:
F_270 ( V_38 ) ;
V_417:
F_279 ( V_38 ) ;
V_416:
F_262 ( V_38 ) ;
V_415:
return V_402 ;
}
static void T_7 F_280 ( struct V_38 * V_38 )
{
F_281 ( V_38 ) ;
F_278 ( V_38 ) ;
F_270 ( V_38 ) ;
F_279 ( V_38 ) ;
F_262 ( V_38 ) ;
}
void T_8 F_282 ( void )
{
F_283 () ;
F_284 ( & V_421 ) ;
F_285 ( & V_132 ) ;
F_286 () ;
}
static void F_287 ( struct V_1 * V_58 ,
struct V_422 * V_423 )
{
struct V_191 * V_192 = V_58 -> V_99 ;
struct V_4 * V_5 = & V_58 -> V_125 ;
if ( V_192 )
F_288 ( V_423 , L_2 ,
V_192 -> V_424 , V_192 -> V_425 , V_192 -> V_426 ) ;
switch ( V_5 -> V_31 ) {
case V_32 :
F_288 ( V_423 , L_3 , & V_5 -> V_15 . V_13 ) ;
if ( V_5 -> V_16 != 32 )
F_288 ( V_423 , L_4 ,
V_5 -> V_16 ) ;
F_288 ( V_423 , L_5 , & V_5 -> V_12 . V_13 ) ;
if ( V_5 -> V_14 != 32 )
F_288 ( V_423 , L_6 ,
V_5 -> V_14 ) ;
break;
case V_33 :
F_288 ( V_423 , L_7 , V_5 -> V_15 . V_427 ) ;
if ( V_5 -> V_16 != 128 )
F_288 ( V_423 , L_4 ,
V_5 -> V_16 ) ;
F_288 ( V_423 , L_8 , V_5 -> V_12 . V_427 ) ;
if ( V_5 -> V_14 != 128 )
F_288 ( V_423 , L_6 ,
V_5 -> V_14 ) ;
break;
}
}
void F_289 ( struct V_1 * V_58 , int V_428 , bool V_197 )
{
struct V_422 * V_423 ;
V_423 = F_290 ( L_9 ) ;
if ( V_423 == NULL )
return;
F_291 ( V_197 , V_423 ) ;
F_288 ( V_423 , L_10 , V_428 ) ;
F_287 ( V_58 , V_423 ) ;
F_292 ( V_423 ) ;
}
void F_119 ( struct V_1 * V_58 , int V_428 ,
bool V_197 )
{
struct V_422 * V_423 ;
V_423 = F_290 ( L_11 ) ;
if ( V_423 == NULL )
return;
F_291 ( V_197 , V_423 ) ;
F_288 ( V_423 , L_10 , V_428 ) ;
F_287 ( V_58 , V_423 ) ;
F_292 ( V_423 ) ;
}
static bool F_293 ( const struct V_4 * V_429 ,
const struct V_4 * V_430 )
{
if ( V_429 -> V_23 == V_431 ) {
if ( V_430 -> V_31 == V_429 -> V_31 &&
F_294 ( & V_430 -> V_12 , & V_429 -> V_12 ,
V_429 -> V_31 ) &&
F_294 ( & V_430 -> V_15 , & V_429 -> V_15 ,
V_429 -> V_31 ) &&
V_430 -> V_14 == V_429 -> V_14 &&
V_430 -> V_16 == V_429 -> V_16 ) {
return true ;
}
} else {
if ( memcmp ( V_430 , V_429 , sizeof( * V_430 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_1 * F_295 ( const struct V_4 * V_5 ,
T_4 V_63 , T_4 type , struct V_38 * V_38 )
{
struct V_1 * V_84 , * V_195 = NULL ;
struct V_110 * V_159 ;
T_3 V_167 = ~ 0U ;
F_76 ( & V_38 -> V_101 . V_115 ) ;
V_159 = F_63 ( V_38 , & V_5 -> V_12 , & V_5 -> V_15 , V_5 -> V_31 , V_63 ) ;
F_96 (pol, chain, bydst) {
if ( F_293 ( V_5 , & V_84 -> V_125 ) &&
V_84 -> type == type ) {
V_195 = V_84 ;
V_167 = V_195 -> V_167 ;
break;
}
}
V_159 = & V_38 -> V_101 . V_113 [ V_63 ] ;
F_96 (pol, chain, bydst) {
if ( ( V_84 -> V_167 >= V_167 ) && V_195 )
break;
if ( F_293 ( V_5 , & V_84 -> V_125 ) &&
V_84 -> type == type ) {
V_195 = V_84 ;
break;
}
}
F_28 ( V_195 ) ;
F_81 ( & V_38 -> V_101 . V_115 ) ;
return V_195 ;
}
static int F_296 ( const struct V_432 * V_186 , const struct V_230 * V_433 )
{
int V_206 = 0 ;
if ( V_433 -> V_239 == V_186 -> V_239 && V_433 -> V_49 . V_23 == V_186 -> V_23 &&
( V_186 -> V_348 == 0 || V_433 -> V_348 == V_186 -> V_348 ) ) {
switch ( V_433 -> V_239 ) {
case V_240 :
case V_241 :
if ( F_294 ( & V_433 -> V_49 . V_12 , & V_186 -> V_434 ,
V_186 -> V_435 ) &&
F_294 ( & V_433 -> V_15 , & V_186 -> V_436 ,
V_186 -> V_435 ) ) {
V_206 = 1 ;
}
break;
case V_286 :
V_206 = 1 ;
break;
default:
break;
}
}
return V_206 ;
}
static int F_297 ( struct V_1 * V_84 ,
struct V_432 * V_186 , int V_437 )
{
struct V_432 * V_438 ;
int V_131 , V_439 , V_440 = 0 ;
F_298 ( & V_84 -> V_64 ) ;
if ( F_11 ( V_84 -> V_65 . V_66 ) ) {
F_299 ( & V_84 -> V_64 ) ;
return - V_196 ;
}
for ( V_131 = 0 ; V_131 < V_84 -> V_228 ; V_131 ++ ) {
for ( V_439 = 0 , V_438 = V_186 ; V_439 < V_437 ; V_439 ++ , V_438 ++ ) {
if ( ! F_296 ( V_438 , & V_84 -> V_229 [ V_131 ] ) )
continue;
V_440 ++ ;
if ( V_84 -> V_229 [ V_131 ] . V_239 != V_240 &&
V_84 -> V_229 [ V_131 ] . V_239 != V_241 )
continue;
memcpy ( & V_84 -> V_229 [ V_131 ] . V_49 . V_12 , & V_438 -> V_441 ,
sizeof( V_84 -> V_229 [ V_131 ] . V_49 . V_12 ) ) ;
memcpy ( & V_84 -> V_229 [ V_131 ] . V_15 , & V_438 -> V_442 ,
sizeof( V_84 -> V_229 [ V_131 ] . V_15 ) ) ;
V_84 -> V_229 [ V_131 ] . V_242 = V_438 -> V_443 ;
F_54 ( & V_84 -> V_100 ) ;
}
}
F_299 ( & V_84 -> V_64 ) ;
if ( ! V_440 )
return - V_444 ;
return 0 ;
}
static int F_300 ( const struct V_432 * V_186 , int V_437 )
{
int V_131 , V_439 ;
if ( V_437 < 1 || V_437 > V_253 )
return - V_204 ;
for ( V_131 = 0 ; V_131 < V_437 ; V_131 ++ ) {
if ( F_294 ( & V_186 [ V_131 ] . V_434 , & V_186 [ V_131 ] . V_441 ,
V_186 [ V_131 ] . V_435 ) &&
F_294 ( & V_186 [ V_131 ] . V_436 , & V_186 [ V_131 ] . V_442 ,
V_186 [ V_131 ] . V_435 ) )
return - V_204 ;
if ( F_158 ( & V_186 [ V_131 ] . V_441 , V_186 [ V_131 ] . V_443 ) ||
F_158 ( & V_186 [ V_131 ] . V_442 , V_186 [ V_131 ] . V_443 ) )
return - V_204 ;
for ( V_439 = V_131 + 1 ; V_439 < V_437 ; V_439 ++ ) {
if ( ! memcmp ( & V_186 [ V_131 ] . V_434 , & V_186 [ V_439 ] . V_434 ,
sizeof( V_186 [ V_131 ] . V_434 ) ) &&
! memcmp ( & V_186 [ V_131 ] . V_436 , & V_186 [ V_439 ] . V_436 ,
sizeof( V_186 [ V_131 ] . V_436 ) ) &&
V_186 [ V_131 ] . V_23 == V_186 [ V_439 ] . V_23 &&
V_186 [ V_131 ] . V_239 == V_186 [ V_439 ] . V_239 &&
V_186 [ V_131 ] . V_348 == V_186 [ V_439 ] . V_348 &&
V_186 [ V_131 ] . V_435 == V_186 [ V_439 ] . V_435 )
return - V_204 ;
}
}
return 0 ;
}
int V_432 ( const struct V_4 * V_5 , T_4 V_63 , T_4 type ,
struct V_432 * V_186 , int V_437 ,
struct V_445 * V_357 , struct V_38 * V_38 )
{
int V_131 , V_194 , V_446 = 0 , V_447 = 0 ;
struct V_1 * V_84 = NULL ;
struct V_44 * V_45 , * V_448 ;
struct V_44 * V_449 [ V_253 ] ;
struct V_44 * V_450 [ V_253 ] ;
struct V_432 * V_438 ;
if ( ( V_194 = F_300 ( V_186 , V_437 ) ) < 0 )
goto V_67;
if ( ( V_84 = F_295 ( V_5 , V_63 , type , V_38 ) ) == NULL ) {
V_194 = - V_196 ;
goto V_67;
}
for ( V_131 = 0 , V_438 = V_186 ; V_131 < V_437 ; V_131 ++ , V_438 ++ ) {
if ( ( V_45 = F_301 ( V_438 , V_38 ) ) ) {
V_449 [ V_446 ] = V_45 ;
V_446 ++ ;
if ( ( V_448 = F_302 ( V_45 , V_438 ) ) ) {
V_450 [ V_447 ] = V_448 ;
V_447 ++ ;
} else {
V_194 = - V_444 ;
goto V_451;
}
}
}
if ( ( V_194 = F_297 ( V_84 , V_186 , V_437 ) ) < 0 )
goto V_451;
if ( V_446 ) {
F_303 ( V_449 , V_446 ) ;
F_304 ( V_449 , V_446 ) ;
}
F_305 ( V_5 , V_63 , type , V_186 , V_437 , V_357 ) ;
F_30 ( V_84 ) ;
return 0 ;
V_67:
return V_194 ;
V_451:
if ( V_84 )
F_30 ( V_84 ) ;
if ( V_446 )
F_303 ( V_449 , V_446 ) ;
if ( V_447 )
F_304 ( V_450 , V_447 ) ;
return V_194 ;
}
