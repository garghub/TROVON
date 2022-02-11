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
static const struct V_34 * F_10 ( unsigned short V_31 )
{
const struct V_34 * V_35 ;
if ( F_11 ( V_31 >= F_12 ( V_34 ) ) )
return NULL ;
F_13 () ;
V_35 = F_14 ( V_34 [ V_31 ] ) ;
if ( F_11 ( ! V_35 ) )
F_15 () ;
return V_35 ;
}
static inline struct V_36 * F_16 ( struct V_37 * V_37 ,
int V_38 , int V_39 ,
const T_1 * V_15 ,
const T_1 * V_12 ,
int V_31 )
{
const struct V_34 * V_35 ;
struct V_36 * V_40 ;
V_35 = F_10 ( V_31 ) ;
if ( F_11 ( V_35 == NULL ) )
return F_17 ( - V_41 ) ;
V_40 = V_35 -> V_42 ( V_37 , V_38 , V_39 , V_15 , V_12 ) ;
F_15 () ;
return V_40 ;
}
static inline struct V_36 * F_18 ( struct V_43 * V_44 ,
int V_38 , int V_39 ,
T_1 * V_45 ,
T_1 * V_46 ,
int V_31 )
{
struct V_37 * V_37 = F_19 ( V_44 ) ;
T_1 * V_15 = & V_44 -> V_47 . V_15 ;
T_1 * V_12 = & V_44 -> V_48 . V_12 ;
struct V_36 * V_40 ;
if ( V_44 -> type -> V_49 & V_50 ) {
V_15 = V_44 -> V_51 ;
V_12 = V_46 ;
}
if ( V_44 -> type -> V_49 & V_52 ) {
V_15 = V_45 ;
V_12 = V_44 -> V_51 ;
}
V_40 = F_16 ( V_37 , V_38 , V_39 , V_15 , V_12 , V_31 ) ;
if ( ! F_20 ( V_40 ) ) {
if ( V_45 != V_15 )
memcpy ( V_45 , V_15 , sizeof( * V_45 ) ) ;
if ( V_46 != V_12 )
memcpy ( V_46 , V_12 , sizeof( * V_46 ) ) ;
}
return V_40 ;
}
static inline unsigned long F_21 ( long V_53 )
{
if ( V_53 >= ( V_54 - 1 ) / V_55 )
return V_54 - 1 ;
else
return V_53 * V_55 ;
}
static void F_22 ( unsigned long V_56 )
{
struct V_1 * V_57 = (struct V_1 * ) V_56 ;
unsigned long V_58 = F_23 () ;
long V_59 = V_60 ;
int V_61 = 0 ;
int V_62 ;
F_24 ( & V_57 -> V_63 ) ;
if ( F_11 ( V_57 -> V_64 . V_65 ) )
goto V_66;
V_62 = F_25 ( V_57 -> V_67 ) ;
if ( V_57 -> V_68 . V_69 ) {
long V_70 = V_57 -> V_68 . V_69 +
V_57 -> V_71 . V_72 - V_58 ;
if ( V_70 <= 0 )
goto V_73;
if ( V_70 < V_59 )
V_59 = V_70 ;
}
if ( V_57 -> V_68 . V_74 ) {
long V_70 = V_57 -> V_68 . V_74 +
( V_57 -> V_71 . V_75 ? : V_57 -> V_71 . V_72 ) - V_58 ;
if ( V_70 <= 0 )
goto V_73;
if ( V_70 < V_59 )
V_59 = V_70 ;
}
if ( V_57 -> V_68 . V_76 ) {
long V_70 = V_57 -> V_68 . V_76 +
V_57 -> V_71 . V_72 - V_58 ;
if ( V_70 <= 0 ) {
V_61 = 1 ;
V_70 = V_77 ;
}
if ( V_70 < V_59 )
V_59 = V_70 ;
}
if ( V_57 -> V_68 . V_78 ) {
long V_70 = V_57 -> V_68 . V_78 +
( V_57 -> V_71 . V_75 ? : V_57 -> V_71 . V_72 ) - V_58 ;
if ( V_70 <= 0 ) {
V_61 = 1 ;
V_70 = V_77 ;
}
if ( V_70 < V_59 )
V_59 = V_70 ;
}
if ( V_61 )
F_26 ( V_57 , V_62 , 0 , 0 ) ;
if ( V_59 != V_60 &&
! F_27 ( & V_57 -> V_79 , V_80 + F_21 ( V_59 ) ) )
F_28 ( V_57 ) ;
V_66:
F_29 ( & V_57 -> V_63 ) ;
F_30 ( V_57 ) ;
return;
V_73:
F_29 ( & V_57 -> V_63 ) ;
if ( ! F_31 ( V_57 , V_62 ) )
F_26 ( V_57 , V_62 , 1 , 0 ) ;
F_30 ( V_57 ) ;
}
static struct V_81 * F_32 ( struct V_81 * V_82 )
{
struct V_1 * V_83 = F_33 ( V_82 , struct V_1 , V_82 ) ;
if ( F_11 ( V_83 -> V_64 . V_65 ) )
V_82 = NULL ;
else
F_28 ( V_83 ) ;
return V_82 ;
}
static int F_34 ( struct V_81 * V_82 )
{
struct V_1 * V_83 = F_33 ( V_82 , struct V_1 , V_82 ) ;
return ! V_83 -> V_64 . V_65 ;
}
static void F_35 ( struct V_81 * V_82 )
{
F_30 ( F_33 ( V_82 , struct V_1 , V_82 ) ) ;
}
struct V_1 * F_36 ( struct V_37 * V_37 , T_2 V_84 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_84 ) ;
if ( V_2 ) {
F_38 ( & V_2 -> V_85 , V_37 ) ;
F_39 ( & V_2 -> V_64 . V_86 ) ;
F_40 ( & V_2 -> V_87 ) ;
F_40 ( & V_2 -> V_88 ) ;
F_41 ( & V_2 -> V_63 ) ;
F_42 ( & V_2 -> V_3 , 1 ) ;
F_43 ( & V_2 -> V_89 . V_90 ) ;
F_44 ( & V_2 -> V_79 , F_22 ,
( unsigned long ) V_2 ) ;
F_44 ( & V_2 -> V_89 . V_91 , V_92 ,
( unsigned long ) V_2 ) ;
V_2 -> V_82 . V_93 = & V_94 ;
}
return V_2 ;
}
static void F_45 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_33 ( V_96 , struct V_1 , V_97 ) ;
F_46 ( V_2 -> V_98 ) ;
F_47 ( V_2 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_49 ( ! V_2 -> V_64 . V_65 ) ;
if ( F_50 ( & V_2 -> V_79 ) || F_50 ( & V_2 -> V_89 . V_91 ) )
F_51 () ;
F_52 ( & V_2 -> V_97 , F_45 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
V_2 -> V_64 . V_65 = 1 ;
F_54 ( & V_2 -> V_99 ) ;
if ( F_50 ( & V_2 -> V_89 . V_91 ) )
F_30 ( V_2 ) ;
F_55 ( & V_2 -> V_89 . V_90 ) ;
if ( F_50 ( & V_2 -> V_79 ) )
F_30 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static inline unsigned int F_56 ( struct V_37 * V_37 , T_3 V_67 )
{
return F_57 ( V_67 , V_37 -> V_100 . V_101 ) ;
}
static void F_58 ( struct V_37 * V_37 ,
unsigned short V_31 , int V_62 ,
T_4 * V_102 , T_4 * V_103 )
{
switch ( V_31 ) {
case V_32 :
* V_102 = V_37 -> V_100 . V_104 [ V_62 ] . V_105 ;
* V_103 = V_37 -> V_100 . V_104 [ V_62 ] . V_106 ;
break;
case V_33 :
* V_102 = V_37 -> V_100 . V_104 [ V_62 ] . V_107 ;
* V_103 = V_37 -> V_100 . V_104 [ V_62 ] . V_108 ;
break;
default:
* V_102 = 0 ;
* V_103 = 0 ;
}
}
static struct V_109 * F_59 ( struct V_37 * V_37 ,
const struct V_4 * V_5 ,
unsigned short V_31 , int V_62 )
{
unsigned int V_110 = V_37 -> V_100 . V_104 [ V_62 ] . V_110 ;
unsigned int V_111 ;
T_4 V_102 ;
T_4 V_103 ;
F_58 ( V_37 , V_31 , V_62 , & V_102 , & V_103 ) ;
V_111 = F_60 ( V_5 , V_31 , V_110 , V_102 , V_103 ) ;
if ( V_111 == V_110 + 1 )
return & V_37 -> V_100 . V_112 [ V_62 ] ;
return F_61 ( V_37 -> V_100 . V_104 [ V_62 ] . V_113 ,
F_62 ( & V_37 -> V_100 . V_114 ) ) + V_111 ;
}
static struct V_109 * F_63 ( struct V_37 * V_37 ,
const T_1 * V_12 ,
const T_1 * V_15 ,
unsigned short V_31 , int V_62 )
{
unsigned int V_110 = V_37 -> V_100 . V_104 [ V_62 ] . V_110 ;
unsigned int V_111 ;
T_4 V_102 ;
T_4 V_103 ;
F_58 ( V_37 , V_31 , V_62 , & V_102 , & V_103 ) ;
V_111 = F_64 ( V_12 , V_15 , V_31 , V_110 , V_102 , V_103 ) ;
return F_61 ( V_37 -> V_100 . V_104 [ V_62 ] . V_113 ,
F_62 ( & V_37 -> V_100 . V_114 ) ) + V_111 ;
}
static void F_65 ( struct V_37 * V_37 ,
struct V_109 * V_115 ,
struct V_109 * V_116 ,
unsigned int V_117 ,
int V_62 )
{
struct V_118 * V_119 , * V_120 = NULL ;
struct V_1 * V_83 ;
unsigned int V_121 = 0 ;
T_4 V_102 ;
T_4 V_103 ;
V_122:
F_66 (pol, tmp, list, bydst) {
unsigned int V_123 ;
F_58 ( V_37 , V_83 -> V_31 , V_62 , & V_102 , & V_103 ) ;
V_123 = F_64 ( & V_83 -> V_124 . V_12 , & V_83 -> V_124 . V_15 ,
V_83 -> V_31 , V_117 , V_102 , V_103 ) ;
if ( ! V_120 ) {
F_67 ( & V_83 -> V_87 ) ;
F_68 ( & V_83 -> V_87 , V_116 + V_123 ) ;
V_121 = V_123 ;
} else {
if ( V_123 != V_121 )
continue;
F_67 ( & V_83 -> V_87 ) ;
F_69 ( & V_83 -> V_87 , V_120 ) ;
}
V_120 = & V_83 -> V_87 ;
}
if ( ! F_70 ( V_115 ) ) {
V_120 = NULL ;
goto V_122;
}
}
static void F_71 ( struct V_109 * V_115 ,
struct V_109 * V_125 ,
unsigned int V_117 )
{
struct V_118 * V_119 ;
struct V_1 * V_83 ;
F_66 (pol, tmp, list, byidx) {
unsigned int V_123 ;
V_123 = F_57 ( V_83 -> V_67 , V_117 ) ;
F_72 ( & V_83 -> V_88 , V_125 + V_123 ) ;
}
}
static unsigned long F_73 ( unsigned int V_126 )
{
return ( ( V_126 + 1 ) << 1 ) - 1 ;
}
static void F_74 ( struct V_37 * V_37 , int V_62 )
{
unsigned int V_110 = V_37 -> V_100 . V_104 [ V_62 ] . V_110 ;
unsigned int V_117 = F_73 ( V_110 ) ;
unsigned int V_127 = ( V_117 + 1 ) * sizeof( struct V_109 ) ;
struct V_109 * V_128 = F_75 ( V_127 ) ;
struct V_109 * V_129 ;
int V_130 ;
if ( ! V_128 )
return;
F_76 ( & V_37 -> V_100 . V_114 ) ;
F_77 ( & V_131 ) ;
V_129 = F_78 ( V_37 -> V_100 . V_104 [ V_62 ] . V_113 ,
F_62 ( & V_37 -> V_100 . V_114 ) ) ;
V_129 = F_78 ( V_37 -> V_100 . V_104 [ V_62 ] . V_113 ,
F_62 ( & V_37 -> V_100 . V_114 ) ) ;
for ( V_130 = V_110 ; V_130 >= 0 ; V_130 -- )
F_65 ( V_37 , V_129 + V_130 , V_128 , V_117 , V_62 ) ;
F_79 ( V_37 -> V_100 . V_104 [ V_62 ] . V_113 , V_128 ) ;
V_37 -> V_100 . V_104 [ V_62 ] . V_110 = V_117 ;
F_80 ( & V_131 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
F_82 () ;
F_83 ( V_129 , ( V_110 + 1 ) * sizeof( struct V_109 ) ) ;
}
static void F_84 ( struct V_37 * V_37 , int V_132 )
{
unsigned int V_110 = V_37 -> V_100 . V_101 ;
unsigned int V_117 = F_73 ( V_110 ) ;
unsigned int V_127 = ( V_117 + 1 ) * sizeof( struct V_109 ) ;
struct V_109 * V_133 = V_37 -> V_100 . V_134 ;
struct V_109 * V_135 = F_75 ( V_127 ) ;
int V_130 ;
if ( ! V_135 )
return;
F_76 ( & V_37 -> V_100 . V_114 ) ;
for ( V_130 = V_110 ; V_130 >= 0 ; V_130 -- )
F_71 ( V_133 + V_130 , V_135 , V_117 ) ;
V_37 -> V_100 . V_134 = V_135 ;
V_37 -> V_100 . V_101 = V_117 ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
F_83 ( V_133 , ( V_110 + 1 ) * sizeof( struct V_109 ) ) ;
}
static inline int F_85 ( struct V_37 * V_37 , int V_62 , int * V_132 )
{
unsigned int V_136 = V_37 -> V_100 . V_137 [ V_62 ] ;
unsigned int V_110 = V_37 -> V_100 . V_104 [ V_62 ] . V_110 ;
if ( V_132 )
* V_132 += V_136 ;
if ( ( V_110 + 1 ) < V_138 &&
V_136 > V_110 )
return 1 ;
return 0 ;
}
static inline int F_86 ( struct V_37 * V_37 , int V_132 )
{
unsigned int V_110 = V_37 -> V_100 . V_101 ;
if ( ( V_110 + 1 ) < V_138 &&
V_132 > V_110 )
return 1 ;
return 0 ;
}
void F_87 ( struct V_37 * V_37 , struct V_139 * V_140 )
{
V_140 -> V_141 = V_37 -> V_100 . V_137 [ V_142 ] ;
V_140 -> V_143 = V_37 -> V_100 . V_137 [ V_144 ] ;
V_140 -> V_145 = V_37 -> V_100 . V_137 [ V_146 ] ;
V_140 -> V_147 = V_37 -> V_100 . V_137 [ V_142 + V_148 ] ;
V_140 -> V_149 = V_37 -> V_100 . V_137 [ V_144 + V_148 ] ;
V_140 -> V_150 = V_37 -> V_100 . V_137 [ V_146 + V_148 ] ;
V_140 -> V_151 = V_37 -> V_100 . V_101 ;
V_140 -> V_152 = V_138 ;
}
static void F_88 ( struct V_153 * V_154 )
{
struct V_37 * V_37 = F_33 ( V_154 , struct V_37 , V_100 . V_155 ) ;
int V_62 , V_132 ;
F_89 ( & V_156 ) ;
V_132 = 0 ;
for ( V_62 = 0 ; V_62 < V_148 ; V_62 ++ ) {
if ( F_85 ( V_37 , V_62 , & V_132 ) )
F_74 ( V_37 , V_62 ) ;
}
if ( F_86 ( V_37 , V_132 ) )
F_84 ( V_37 , V_132 ) ;
F_90 ( & V_156 ) ;
}
static void F_91 ( struct V_153 * V_154 )
{
struct V_37 * V_37 = F_33 ( V_154 , struct V_37 ,
V_100 . V_157 . V_154 ) ;
unsigned int V_110 ;
struct V_1 * V_83 ;
struct V_1 * V_2 ;
struct V_109 * V_158 ;
struct V_109 * V_129 ;
struct V_118 * V_159 ;
int V_130 ;
int V_62 ;
unsigned V_160 ;
T_4 V_161 , V_162 , V_163 , V_164 ;
F_89 ( & V_156 ) ;
do {
V_160 = F_92 ( & V_37 -> V_100 . V_157 . V_63 ) ;
V_161 = V_37 -> V_100 . V_157 . V_161 ;
V_162 = V_37 -> V_100 . V_157 . V_162 ;
V_163 = V_37 -> V_100 . V_157 . V_163 ;
V_164 = V_37 -> V_100 . V_157 . V_164 ;
} while ( F_93 ( & V_37 -> V_100 . V_157 . V_63 , V_160 ) );
F_76 ( & V_37 -> V_100 . V_114 ) ;
for ( V_62 = 0 ; V_62 < V_148 ; V_62 ++ ) {
F_94 ( & V_37 -> V_100 . V_112 [ V_62 ] ) ;
V_110 = V_37 -> V_100 . V_104 [ V_62 ] . V_110 ;
V_129 = V_37 -> V_100 . V_104 [ V_62 ] . V_113 ;
for ( V_130 = V_110 ; V_130 >= 0 ; V_130 -- )
F_94 ( V_129 + V_130 ) ;
if ( ( V_62 & V_165 ) == V_144 ) {
V_37 -> V_100 . V_104 [ V_62 ] . V_105 = V_162 ;
V_37 -> V_100 . V_104 [ V_62 ] . V_106 = V_161 ;
V_37 -> V_100 . V_104 [ V_62 ] . V_107 = V_164 ;
V_37 -> V_100 . V_104 [ V_62 ] . V_108 = V_163 ;
} else {
V_37 -> V_100 . V_104 [ V_62 ] . V_105 = V_161 ;
V_37 -> V_100 . V_104 [ V_62 ] . V_106 = V_162 ;
V_37 -> V_100 . V_104 [ V_62 ] . V_107 = V_163 ;
V_37 -> V_100 . V_104 [ V_62 ] . V_108 = V_164 ;
}
}
F_95 (policy, &net->xfrm.policy_all, walk.all) {
if ( F_25 ( V_2 -> V_67 ) >= V_148 ) {
continue;
}
V_159 = NULL ;
V_158 = F_59 ( V_37 , & V_2 -> V_124 ,
V_2 -> V_31 ,
F_25 ( V_2 -> V_67 ) ) ;
F_96 (pol, chain, bydst) {
if ( V_2 -> V_166 >= V_83 -> V_166 )
V_159 = & V_83 -> V_87 ;
else
break;
}
if ( V_159 )
F_97 ( & V_2 -> V_87 , V_159 ) ;
else
F_72 ( & V_2 -> V_87 , V_158 ) ;
}
F_81 ( & V_37 -> V_100 . V_114 ) ;
F_90 ( & V_156 ) ;
}
void F_98 ( struct V_37 * V_37 )
{
F_99 ( & V_37 -> V_100 . V_157 . V_154 ) ;
}
static T_3 F_100 ( struct V_37 * V_37 , int V_62 , T_3 V_67 )
{
static T_3 V_167 ;
for (; ; ) {
struct V_109 * V_115 ;
struct V_1 * V_168 ;
T_3 V_169 ;
int V_170 ;
if ( ! V_67 ) {
V_169 = ( V_167 | V_62 ) ;
V_167 += 8 ;
} else {
V_169 = V_67 ;
V_67 = 0 ;
}
if ( V_169 == 0 )
V_169 = 8 ;
V_115 = V_37 -> V_100 . V_134 + F_56 ( V_37 , V_169 ) ;
V_170 = 0 ;
F_96 (p, list, byidx) {
if ( V_168 -> V_67 == V_169 ) {
V_170 = 1 ;
break;
}
}
if ( ! V_170 )
return V_169 ;
}
}
static inline int F_101 ( struct V_4 * V_171 , struct V_4 * V_172 )
{
T_3 * V_173 = ( T_3 * ) V_171 ;
T_3 * V_174 = ( T_3 * ) V_172 ;
int V_175 = sizeof( struct V_4 ) / sizeof( T_3 ) ;
int V_130 ;
for ( V_130 = 0 ; V_130 < V_175 ; V_130 ++ ) {
if ( V_173 [ V_130 ] != V_174 [ V_130 ] )
return 1 ;
}
return 0 ;
}
static void F_102 ( struct V_1 * V_176 ,
struct V_1 * V_177 )
{
struct V_178 * V_179 = & V_176 -> V_89 ;
struct V_180 V_115 ;
if ( F_103 ( & V_179 -> V_90 ) )
return;
F_104 ( & V_115 ) ;
F_76 ( & V_179 -> V_90 . V_63 ) ;
F_105 ( & V_179 -> V_90 , & V_115 ) ;
if ( F_50 ( & V_179 -> V_91 ) )
F_30 ( V_176 ) ;
F_81 ( & V_179 -> V_90 . V_63 ) ;
V_179 = & V_177 -> V_89 ;
F_76 ( & V_179 -> V_90 . V_63 ) ;
F_106 ( & V_115 , & V_179 -> V_90 ) ;
V_179 -> V_181 = V_182 ;
if ( ! F_27 ( & V_179 -> V_91 , V_80 ) )
F_28 ( V_177 ) ;
F_81 ( & V_179 -> V_90 . V_63 ) ;
}
static bool F_107 ( struct V_1 * V_2 ,
struct V_1 * V_83 )
{
T_3 V_183 = V_2 -> V_183 . V_184 & V_2 -> V_183 . V_185 ;
if ( V_2 -> V_183 . V_184 == V_83 -> V_183 . V_184 && V_2 -> V_183 . V_185 == V_83 -> V_183 . V_185 )
return true ;
if ( ( V_183 & V_83 -> V_183 . V_185 ) == V_83 -> V_183 . V_184 &&
V_2 -> V_166 == V_83 -> V_166 )
return true ;
return false ;
}
int F_108 ( int V_62 , struct V_1 * V_2 , int V_186 )
{
struct V_37 * V_37 = V_85 ( V_2 ) ;
struct V_1 * V_83 ;
struct V_1 * V_187 ;
struct V_109 * V_158 ;
struct V_118 * V_159 ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
V_158 = F_59 ( V_37 , & V_2 -> V_124 , V_2 -> V_31 , V_62 ) ;
V_187 = NULL ;
V_159 = NULL ;
F_96 (pol, chain, bydst) {
if ( V_83 -> type == V_2 -> type &&
! F_101 ( & V_83 -> V_124 , & V_2 -> V_124 ) &&
F_107 ( V_2 , V_83 ) &&
F_109 ( V_83 -> V_98 , V_2 -> V_98 ) &&
! F_110 ( V_187 ) ) {
if ( V_186 ) {
F_81 ( & V_37 -> V_100 . V_114 ) ;
return - V_188 ;
}
V_187 = V_83 ;
if ( V_2 -> V_166 > V_83 -> V_166 )
continue;
} else if ( V_2 -> V_166 >= V_83 -> V_166 ) {
V_159 = & V_83 -> V_87 ;
continue;
}
if ( V_187 )
break;
}
if ( V_159 )
F_97 ( & V_2 -> V_87 , V_159 ) ;
else
F_72 ( & V_2 -> V_87 , V_158 ) ;
F_111 ( V_2 , V_62 ) ;
F_54 ( & V_37 -> V_100 . V_189 ) ;
if ( V_2 -> V_31 == V_32 )
F_112 ( V_37 ) ;
else
F_113 ( V_37 ) ;
if ( V_187 ) {
F_102 ( V_187 , V_2 ) ;
F_114 ( V_187 , V_62 ) ;
}
V_2 -> V_67 = V_187 ? V_187 -> V_67 : F_100 ( V_37 , V_62 , V_2 -> V_67 ) ;
F_72 ( & V_2 -> V_88 , V_37 -> V_100 . V_134 + F_56 ( V_37 , V_2 -> V_67 ) ) ;
V_2 -> V_71 . V_72 = F_23 () ;
V_2 -> V_71 . V_75 = 0 ;
if ( ! F_27 ( & V_2 -> V_79 , V_80 + V_55 ) )
F_28 ( V_2 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
if ( V_187 )
F_53 ( V_187 ) ;
else if ( F_85 ( V_37 , V_62 , NULL ) )
F_99 ( & V_37 -> V_100 . V_155 ) ;
return 0 ;
}
struct V_1 * F_115 ( struct V_37 * V_37 , T_3 V_183 , T_4 type ,
int V_62 , struct V_4 * V_5 ,
struct V_190 * V_191 , int V_192 ,
int * V_193 )
{
struct V_1 * V_83 , * V_194 ;
struct V_109 * V_158 ;
* V_193 = 0 ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
V_158 = F_59 ( V_37 , V_5 , V_5 -> V_31 , V_62 ) ;
V_194 = NULL ;
F_96 (pol, chain, bydst) {
if ( V_83 -> type == type &&
( V_183 & V_83 -> V_183 . V_185 ) == V_83 -> V_183 . V_184 &&
! F_101 ( V_5 , & V_83 -> V_124 ) &&
F_109 ( V_191 , V_83 -> V_98 ) ) {
F_28 ( V_83 ) ;
if ( V_192 ) {
* V_193 = F_116 (
V_83 -> V_98 ) ;
if ( * V_193 ) {
F_81 ( & V_37 -> V_100 . V_114 ) ;
return V_83 ;
}
F_114 ( V_83 , V_62 ) ;
}
V_194 = V_83 ;
break;
}
}
F_81 ( & V_37 -> V_100 . V_114 ) ;
if ( V_194 && V_192 )
F_53 ( V_194 ) ;
return V_194 ;
}
struct V_1 * F_117 ( struct V_37 * V_37 , T_3 V_183 , T_4 type ,
int V_62 , T_3 V_48 , int V_192 , int * V_193 )
{
struct V_1 * V_83 , * V_194 ;
struct V_109 * V_158 ;
* V_193 = - V_195 ;
if ( F_25 ( V_48 ) != V_62 )
return NULL ;
* V_193 = 0 ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
V_158 = V_37 -> V_100 . V_134 + F_56 ( V_37 , V_48 ) ;
V_194 = NULL ;
F_96 (pol, chain, byidx) {
if ( V_83 -> type == type && V_83 -> V_67 == V_48 &&
( V_183 & V_83 -> V_183 . V_185 ) == V_83 -> V_183 . V_184 ) {
F_28 ( V_83 ) ;
if ( V_192 ) {
* V_193 = F_116 (
V_83 -> V_98 ) ;
if ( * V_193 ) {
F_81 ( & V_37 -> V_100 . V_114 ) ;
return V_83 ;
}
F_114 ( V_83 , V_62 ) ;
}
V_194 = V_83 ;
break;
}
}
F_81 ( & V_37 -> V_100 . V_114 ) ;
if ( V_194 && V_192 )
F_53 ( V_194 ) ;
return V_194 ;
}
static inline int
F_118 ( struct V_37 * V_37 , T_4 type , bool V_196 )
{
int V_62 , V_193 = 0 ;
for ( V_62 = 0 ; V_62 < V_148 ; V_62 ++ ) {
struct V_1 * V_83 ;
int V_130 ;
F_96 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_83 -> type != type )
continue;
V_193 = F_116 ( V_83 -> V_98 ) ;
if ( V_193 ) {
F_119 ( V_83 , 0 , V_196 ) ;
return V_193 ;
}
}
for ( V_130 = V_37 -> V_100 . V_104 [ V_62 ] . V_110 ; V_130 >= 0 ; V_130 -- ) {
F_96 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_83 -> type != type )
continue;
V_193 = F_116 (
V_83 -> V_98 ) ;
if ( V_193 ) {
F_119 ( V_83 , 0 ,
V_196 ) ;
return V_193 ;
}
}
}
}
return V_193 ;
}
static inline int
F_118 ( struct V_37 * V_37 , T_4 type , bool V_196 )
{
return 0 ;
}
int F_120 ( struct V_37 * V_37 , T_4 type , bool V_196 )
{
int V_62 , V_193 = 0 , V_136 = 0 ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
V_193 = F_118 ( V_37 , type , V_196 ) ;
if ( V_193 )
goto V_66;
for ( V_62 = 0 ; V_62 < V_148 ; V_62 ++ ) {
struct V_1 * V_83 ;
int V_130 ;
V_197:
F_96 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_83 -> type != type )
continue;
F_114 ( V_83 , V_62 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
V_136 ++ ;
F_119 ( V_83 , 1 , V_196 ) ;
F_53 ( V_83 ) ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
goto V_197;
}
for ( V_130 = V_37 -> V_100 . V_104 [ V_62 ] . V_110 ; V_130 >= 0 ; V_130 -- ) {
V_198:
F_96 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_83 -> type != type )
continue;
F_114 ( V_83 , V_62 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
V_136 ++ ;
F_119 ( V_83 , 1 , V_196 ) ;
F_53 ( V_83 ) ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
goto V_198;
}
}
}
if ( ! V_136 )
V_193 = - V_199 ;
V_66:
F_81 ( & V_37 -> V_100 . V_114 ) ;
if ( V_136 )
F_121 ( V_37 ) ;
return V_193 ;
}
int F_122 ( struct V_37 * V_37 , struct F_122 * V_64 ,
int (* F_123)( struct V_1 * , int , int , void * ) ,
void * V_56 )
{
struct V_1 * V_83 ;
struct V_200 * V_44 ;
int error = 0 ;
if ( V_64 -> type >= V_201 &&
V_64 -> type != V_202 )
return - V_203 ;
if ( F_124 ( & V_64 -> V_64 . V_86 ) && V_64 -> V_160 != 0 )
return 0 ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
if ( F_124 ( & V_64 -> V_64 . V_86 ) )
V_44 = F_125 ( & V_37 -> V_100 . V_204 , struct V_200 , V_86 ) ;
else
V_44 = F_125 ( & V_64 -> V_64 . V_86 ,
struct V_200 , V_86 ) ;
F_126 (x, &net->xfrm.policy_all, all) {
if ( V_44 -> V_65 )
continue;
V_83 = F_33 ( V_44 , struct V_1 , V_64 ) ;
if ( V_64 -> type != V_202 &&
V_64 -> type != V_83 -> type )
continue;
error = F_123 ( V_83 , F_25 ( V_83 -> V_67 ) ,
V_64 -> V_160 , V_56 ) ;
if ( error ) {
F_127 ( & V_64 -> V_64 . V_86 , & V_44 -> V_86 ) ;
goto V_66;
}
V_64 -> V_160 ++ ;
}
if ( V_64 -> V_160 == 0 ) {
error = - V_195 ;
goto V_66;
}
F_128 ( & V_64 -> V_64 . V_86 ) ;
V_66:
F_81 ( & V_37 -> V_100 . V_114 ) ;
return error ;
}
void F_129 ( struct F_122 * V_64 , T_4 type )
{
F_39 ( & V_64 -> V_64 . V_86 ) ;
V_64 -> V_64 . V_65 = 1 ;
V_64 -> type = type ;
V_64 -> V_160 = 0 ;
}
void F_130 ( struct F_122 * V_64 , struct V_37 * V_37 )
{
if ( F_124 ( & V_64 -> V_64 . V_86 ) )
return;
F_76 ( & V_37 -> V_100 . V_114 ) ;
F_131 ( & V_64 -> V_64 . V_86 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
}
static int F_132 ( const struct V_1 * V_83 ,
const struct V_6 * V_7 ,
T_4 type , T_5 V_31 , int V_62 )
{
const struct V_4 * V_5 = & V_83 -> V_124 ;
int V_194 = - V_199 ;
bool V_205 ;
if ( V_83 -> V_31 != V_31 ||
( V_7 -> V_206 & V_83 -> V_183 . V_185 ) != V_83 -> V_183 . V_184 ||
V_83 -> type != type )
return V_194 ;
V_205 = F_9 ( V_5 , V_7 , V_31 ) ;
if ( V_205 )
V_194 = F_133 ( V_83 -> V_98 , V_7 -> V_207 ,
V_62 ) ;
return V_194 ;
}
static struct V_1 * F_134 ( struct V_37 * V_37 , T_4 type ,
const struct V_6 * V_7 ,
T_5 V_31 , T_4 V_62 )
{
int V_193 ;
struct V_1 * V_83 , * V_194 ;
const T_1 * V_12 , * V_15 ;
struct V_109 * V_158 ;
unsigned int V_208 ;
T_3 V_166 ;
V_12 = F_135 ( V_7 , V_31 ) ;
V_15 = F_136 ( V_7 , V_31 ) ;
if ( F_11 ( ! V_12 || ! V_15 ) )
return NULL ;
F_13 () ;
V_209:
do {
V_208 = F_137 ( & V_131 ) ;
V_158 = F_63 ( V_37 , V_12 , V_15 , V_31 , V_62 ) ;
} while ( F_138 ( & V_131 , V_208 ) );
V_166 = ~ 0U ;
V_194 = NULL ;
F_139 (pol, chain, bydst) {
V_193 = F_132 ( V_83 , V_7 , type , V_31 , V_62 ) ;
if ( V_193 ) {
if ( V_193 == - V_199 )
continue;
else {
V_194 = F_17 ( V_193 ) ;
goto V_210;
}
} else {
V_194 = V_83 ;
V_166 = V_194 -> V_166 ;
break;
}
}
V_158 = & V_37 -> V_100 . V_112 [ V_62 ] ;
F_139 (pol, chain, bydst) {
if ( ( V_83 -> V_166 >= V_166 ) && V_194 )
break;
V_193 = F_132 ( V_83 , V_7 , type , V_31 , V_62 ) ;
if ( V_193 ) {
if ( V_193 == - V_199 )
continue;
else {
V_194 = F_17 ( V_193 ) ;
goto V_210;
}
} else {
V_194 = V_83 ;
break;
}
}
if ( F_138 ( & V_131 , V_208 ) )
goto V_209;
if ( V_194 && ! F_1 ( V_194 ) )
goto V_209;
V_210:
F_15 () ;
return V_194 ;
}
static struct V_1 *
F_140 ( struct V_37 * V_37 , const struct V_6 * V_7 , T_5 V_31 , T_4 V_62 )
{
#ifdef F_141
struct V_1 * V_83 ;
V_83 = F_134 ( V_37 , V_211 , V_7 , V_31 , V_62 ) ;
if ( V_83 != NULL )
return V_83 ;
#endif
return F_134 ( V_37 , V_212 , V_7 , V_31 , V_62 ) ;
}
static int F_142 ( int V_62 )
{
if ( V_142 == V_213 &&
V_144 == V_214 &&
V_146 == V_215 )
return V_62 ;
switch ( V_62 ) {
default:
case V_213 :
return V_142 ;
case V_214 :
return V_144 ;
case V_215 :
return V_146 ;
}
}
static struct V_81 *
F_143 ( struct V_37 * V_37 , const struct V_6 * V_7 , T_5 V_31 ,
T_4 V_62 , struct V_81 * V_216 , void * V_191 )
{
struct V_1 * V_83 ;
if ( V_216 )
F_30 ( F_33 ( V_216 , struct V_1 , V_82 ) ) ;
V_83 = F_140 ( V_37 , V_7 , V_31 , F_142 ( V_62 ) ) ;
if ( F_144 ( V_83 ) )
return F_145 ( V_83 ) ;
F_28 ( V_83 ) ;
return & V_83 -> V_82 ;
}
static inline int F_146 ( int V_62 )
{
if ( V_142 == V_213 &&
V_144 == V_214 &&
V_146 == V_215 )
return V_62 ;
switch ( V_62 ) {
default:
case V_142 :
return V_213 ;
case V_144 :
return V_214 ;
case V_146 :
return V_215 ;
}
}
static struct V_1 * F_147 ( const struct V_217 * V_218 , int V_62 ,
const struct V_6 * V_7 , T_5 V_31 )
{
struct V_1 * V_83 ;
F_13 () ;
V_219:
V_83 = F_14 ( V_218 -> V_220 [ V_62 ] ) ;
if ( V_83 != NULL ) {
bool V_205 = F_9 ( & V_83 -> V_124 , V_7 , V_31 ) ;
int V_193 = 0 ;
if ( V_205 ) {
if ( ( V_218 -> V_221 & V_83 -> V_183 . V_185 ) != V_83 -> V_183 . V_184 ) {
V_83 = NULL ;
goto V_66;
}
V_193 = F_133 ( V_83 -> V_98 ,
V_7 -> V_207 ,
F_146 ( V_62 ) ) ;
if ( ! V_193 ) {
if ( ! F_1 ( V_83 ) )
goto V_219;
} else if ( V_193 == - V_199 ) {
V_83 = NULL ;
} else {
V_83 = F_17 ( V_193 ) ;
}
} else
V_83 = NULL ;
}
V_66:
F_15 () ;
return V_83 ;
}
static void F_111 ( struct V_1 * V_83 , int V_62 )
{
struct V_37 * V_37 = V_85 ( V_83 ) ;
F_148 ( & V_83 -> V_64 . V_86 , & V_37 -> V_100 . V_204 ) ;
V_37 -> V_100 . V_137 [ V_62 ] ++ ;
F_28 ( V_83 ) ;
}
static struct V_1 * F_114 ( struct V_1 * V_83 ,
int V_62 )
{
struct V_37 * V_37 = V_85 ( V_83 ) ;
if ( F_124 ( & V_83 -> V_64 . V_86 ) )
return NULL ;
if ( ! F_149 ( & V_83 -> V_87 ) ) {
F_67 ( & V_83 -> V_87 ) ;
F_150 ( & V_83 -> V_88 ) ;
}
F_128 ( & V_83 -> V_64 . V_86 ) ;
V_37 -> V_100 . V_137 [ V_62 ] -- ;
return V_83 ;
}
static void F_151 ( struct V_1 * V_83 , int V_62 )
{
F_111 ( V_83 , V_148 + V_62 ) ;
}
static void F_152 ( struct V_1 * V_83 , int V_62 )
{
F_114 ( V_83 , V_148 + V_62 ) ;
}
int F_31 ( struct V_1 * V_83 , int V_62 )
{
struct V_37 * V_37 = V_85 ( V_83 ) ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
V_83 = F_114 ( V_83 , V_62 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
if ( V_83 ) {
F_53 ( V_83 ) ;
return 0 ;
}
return - V_195 ;
}
int F_153 ( struct V_217 * V_218 , int V_62 , struct V_1 * V_83 )
{
struct V_37 * V_37 = V_85 ( V_83 ) ;
struct V_1 * V_222 ;
#ifdef F_141
if ( V_83 && V_83 -> type != V_212 )
return - V_203 ;
#endif
F_76 ( & V_37 -> V_100 . V_114 ) ;
V_222 = F_78 ( V_218 -> V_220 [ V_62 ] ,
F_62 ( & V_37 -> V_100 . V_114 ) ) ;
if ( V_83 ) {
V_83 -> V_71 . V_72 = F_23 () ;
V_83 -> V_67 = F_100 ( V_37 , V_148 + V_62 , 0 ) ;
F_151 ( V_83 , V_62 ) ;
}
F_79 ( V_218 -> V_220 [ V_62 ] , V_83 ) ;
if ( V_222 ) {
if ( V_83 )
F_102 ( V_222 , V_83 ) ;
F_152 ( V_222 , V_62 ) ;
}
F_81 ( & V_37 -> V_100 . V_114 ) ;
if ( V_222 ) {
F_53 ( V_222 ) ;
}
return 0 ;
}
static struct V_1 * F_154 ( const struct V_1 * V_176 , int V_62 )
{
struct V_1 * V_223 = F_36 ( V_85 ( V_176 ) , V_224 ) ;
struct V_37 * V_37 = V_85 ( V_176 ) ;
if ( V_223 ) {
V_223 -> V_124 = V_176 -> V_124 ;
if ( F_155 ( V_176 -> V_98 ,
& V_223 -> V_98 ) ) {
F_47 ( V_223 ) ;
return NULL ;
}
V_223 -> V_68 = V_176 -> V_68 ;
V_223 -> V_71 = V_176 -> V_71 ;
V_223 -> V_183 = V_176 -> V_183 ;
V_223 -> V_225 = V_176 -> V_225 ;
V_223 -> V_49 = V_176 -> V_49 ;
V_223 -> V_226 = V_176 -> V_226 ;
V_223 -> V_67 = V_176 -> V_67 ;
V_223 -> type = V_176 -> type ;
memcpy ( V_223 -> V_227 , V_176 -> V_227 ,
V_223 -> V_226 * sizeof( struct V_228 ) ) ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
F_151 ( V_223 , V_62 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
F_30 ( V_223 ) ;
}
return V_223 ;
}
int F_156 ( struct V_217 * V_218 , const struct V_217 * V_229 )
{
const struct V_1 * V_168 ;
struct V_1 * V_230 ;
int V_130 , V_194 = 0 ;
F_13 () ;
for ( V_130 = 0 ; V_130 < 2 ; V_130 ++ ) {
V_168 = F_14 ( V_229 -> V_220 [ V_130 ] ) ;
if ( V_168 ) {
V_230 = F_154 ( V_168 , V_130 ) ;
if ( F_11 ( ! V_230 ) ) {
V_194 = - V_231 ;
break;
}
F_79 ( V_218 -> V_220 [ V_130 ] , V_230 ) ;
}
}
F_15 () ;
return V_194 ;
}
static int
F_157 ( struct V_37 * V_37 , int V_39 , T_1 * V_232 ,
T_1 * V_233 , unsigned short V_31 )
{
int V_193 ;
const struct V_34 * V_35 = F_10 ( V_31 ) ;
if ( F_11 ( V_35 == NULL ) )
return - V_203 ;
V_193 = V_35 -> V_234 ( V_37 , V_39 , V_232 , V_233 ) ;
F_15 () ;
return V_193 ;
}
static int
F_158 ( struct V_1 * V_2 , const struct V_6 * V_7 ,
struct V_43 * * V_100 , unsigned short V_31 )
{
struct V_37 * V_37 = V_85 ( V_2 ) ;
int V_235 ;
int V_130 , error ;
T_1 * V_12 = F_135 ( V_7 , V_31 ) ;
T_1 * V_15 = F_136 ( V_7 , V_31 ) ;
T_1 V_119 ;
for ( V_235 = 0 , V_130 = 0 ; V_130 < V_2 -> V_226 ; V_130 ++ ) {
struct V_43 * V_44 ;
T_1 * V_233 = V_12 ;
T_1 * V_232 = V_15 ;
struct V_228 * V_236 = & V_2 -> V_227 [ V_130 ] ;
if ( V_236 -> V_237 == V_238 ||
V_236 -> V_237 == V_239 ) {
V_233 = & V_236 -> V_48 . V_12 ;
V_232 = & V_236 -> V_15 ;
if ( F_159 ( V_232 , V_236 -> V_240 ) ) {
error = F_157 ( V_37 , V_7 -> V_241 ,
& V_119 , V_233 ,
V_236 -> V_240 ) ;
if ( error )
goto V_210;
V_232 = & V_119 ;
}
}
V_44 = F_160 ( V_233 , V_232 , V_7 , V_236 , V_2 , & error , V_31 ) ;
if ( V_44 && V_44 -> V_242 . V_243 == V_244 ) {
V_100 [ V_235 ++ ] = V_44 ;
V_12 = V_233 ;
V_15 = V_232 ;
continue;
}
if ( V_44 ) {
error = ( V_44 -> V_242 . V_243 == V_245 ?
- V_203 : - V_246 ) ;
F_161 ( V_44 ) ;
} else if ( error == - V_199 ) {
error = - V_246 ;
}
if ( ! V_236 -> V_247 )
goto V_210;
}
return V_235 ;
V_210:
for ( V_235 -- ; V_235 >= 0 ; V_235 -- )
F_161 ( V_100 [ V_235 ] ) ;
return error ;
}
static int
F_162 ( struct V_1 * * V_248 , int V_249 , const struct V_6 * V_7 ,
struct V_43 * * V_100 , unsigned short V_31 )
{
struct V_43 * V_250 [ V_251 ] ;
struct V_43 * * V_252 = ( V_249 > 1 ) ? V_250 : V_100 ;
int V_253 = 0 ;
int error ;
int V_194 ;
int V_130 ;
for ( V_130 = 0 ; V_130 < V_249 ; V_130 ++ ) {
if ( V_253 + V_248 [ V_130 ] -> V_226 >= V_251 ) {
error = - V_254 ;
goto V_210;
}
V_194 = F_158 ( V_248 [ V_130 ] , V_7 , & V_252 [ V_253 ] , V_31 ) ;
if ( V_194 < 0 ) {
error = V_194 ;
goto V_210;
} else
V_253 += V_194 ;
}
if ( V_249 > 1 )
F_163 ( V_100 , V_252 , V_253 , V_31 ) ;
return V_253 ;
V_210:
for ( V_253 -- ; V_253 >= 0 ; V_253 -- )
F_161 ( V_252 [ V_253 ] ) ;
return error ;
}
static int F_164 ( const struct V_6 * V_7 , int V_31 )
{
const struct V_34 * V_35 ;
int V_38 = 0 ;
V_35 = F_10 ( V_31 ) ;
V_38 = V_35 ? V_35 -> V_255 ( V_7 ) : 0 ;
F_15 () ;
return V_38 ;
}
static struct V_81 * F_165 ( struct V_81 * V_82 )
{
struct V_256 * V_257 = F_33 ( V_82 , struct V_256 , V_82 ) ;
struct V_36 * V_40 = & V_257 -> V_10 . V_40 ;
if ( V_257 -> V_258 == NULL ) {
if ( V_257 -> V_259 > 0 )
return NULL ;
} else if ( V_40 -> V_49 & V_260 ) {
return NULL ;
} else {
if ( F_166 ( V_40 ) )
return NULL ;
}
F_167 ( V_40 ) ;
return V_82 ;
}
static int F_168 ( struct V_81 * V_82 )
{
struct V_256 * V_257 = F_33 ( V_82 , struct V_256 , V_82 ) ;
struct V_36 * V_40 = & V_257 -> V_10 . V_40 ;
if ( ! V_257 -> V_258 )
return 0 ;
if ( F_166 ( V_40 ) )
return 0 ;
return 1 ;
}
static void F_169 ( struct V_81 * V_82 )
{
struct V_256 * V_257 = F_33 ( V_82 , struct V_256 , V_82 ) ;
struct V_36 * V_40 = & V_257 -> V_10 . V_40 ;
F_170 ( V_40 ) ;
}
static inline struct V_256 * F_171 ( struct V_37 * V_37 , int V_31 )
{
const struct V_34 * V_35 = F_10 ( V_31 ) ;
struct V_261 * V_261 ;
struct V_256 * V_257 ;
if ( ! V_35 )
return F_17 ( - V_203 ) ;
switch ( V_31 ) {
case V_32 :
V_261 = & V_37 -> V_100 . V_262 ;
break;
#if F_172 ( V_263 )
case V_33 :
V_261 = & V_37 -> V_100 . V_264 ;
break;
#endif
default:
F_51 () ;
}
V_257 = F_173 ( V_261 , NULL , 0 , V_265 , 0 ) ;
if ( F_174 ( V_257 ) ) {
struct V_36 * V_40 = & V_257 -> V_10 . V_40 ;
memset ( V_40 + 1 , 0 , sizeof( * V_257 ) - sizeof( * V_40 ) ) ;
V_257 -> V_82 . V_93 = & V_266 ;
} else
V_257 = F_17 ( - V_254 ) ;
F_15 () ;
return V_257 ;
}
static inline int F_175 ( struct V_256 * V_267 , struct V_36 * V_40 ,
int V_268 )
{
const struct V_34 * V_35 =
F_10 ( V_40 -> V_93 -> V_31 ) ;
int V_193 ;
if ( ! V_35 )
return - V_203 ;
V_193 = V_35 -> V_269 ( V_267 , V_40 , V_268 ) ;
F_15 () ;
return V_193 ;
}
static inline int F_176 ( struct V_256 * V_257 , struct V_270 * V_271 ,
const struct V_6 * V_7 )
{
const struct V_34 * V_35 =
F_10 ( V_257 -> V_10 . V_40 . V_93 -> V_31 ) ;
int V_193 ;
if ( ! V_35 )
return - V_203 ;
V_193 = V_35 -> V_272 ( V_257 , V_271 , V_7 ) ;
F_15 () ;
return V_193 ;
}
static struct V_36 * F_177 ( struct V_1 * V_2 ,
struct V_43 * * V_100 , int V_235 ,
const struct V_6 * V_7 ,
struct V_36 * V_40 )
{
struct V_37 * V_37 = V_85 ( V_2 ) ;
unsigned long V_58 = V_80 ;
struct V_270 * V_271 ;
struct V_273 * V_274 ;
struct V_36 * V_275 = NULL ;
struct V_36 * V_276 = NULL ;
int V_130 = 0 ;
int V_193 ;
int V_277 = 0 ;
int V_268 = 0 ;
int V_278 = 0 ;
int V_38 ;
int V_31 = V_2 -> V_124 . V_31 ;
T_1 V_15 , V_12 ;
F_178 ( V_7 , & V_15 , & V_12 , V_31 ) ;
V_38 = F_164 ( V_7 , V_31 ) ;
F_167 ( V_40 ) ;
for (; V_130 < V_235 ; V_130 ++ ) {
struct V_256 * V_257 = F_171 ( V_37 , V_31 ) ;
struct V_36 * V_279 = & V_257 -> V_10 . V_40 ;
V_193 = F_179 ( V_257 ) ;
if ( F_20 ( V_257 ) ) {
F_180 ( V_40 ) ;
goto V_280;
}
if ( V_100 [ V_130 ] -> V_5 . V_31 == V_281 ) {
V_274 = F_181 ( V_100 [ V_130 ] ,
F_182 ( V_31 ) ) ;
if ( ! V_274 ) {
V_193 = - V_41 ;
F_180 ( V_40 ) ;
goto V_280;
}
} else
V_274 = V_100 [ V_130 ] -> V_274 ;
if ( ! V_275 )
V_276 = V_279 ;
else {
V_275 -> V_282 = F_183 ( V_279 ) ;
V_279 -> V_49 |= V_283 ;
}
V_257 -> V_258 = V_40 ;
F_184 ( V_279 , V_40 ) ;
if ( V_100 [ V_130 ] -> V_47 . V_237 != V_284 ) {
V_31 = V_100 [ V_130 ] -> V_47 . V_31 ;
V_40 = F_18 ( V_100 [ V_130 ] , V_38 , V_7 -> V_241 ,
& V_15 , & V_12 , V_31 ) ;
V_193 = F_179 ( V_40 ) ;
if ( F_20 ( V_40 ) )
goto V_280;
} else
F_167 ( V_40 ) ;
V_279 -> V_100 = V_100 [ V_130 ] ;
V_257 -> V_285 = V_100 [ V_130 ] -> V_99 ;
V_279 -> V_286 = V_287 ;
V_279 -> V_49 |= V_288 ;
V_279 -> V_289 = V_58 ;
V_279 -> V_290 = V_291 ;
V_279 -> V_292 = V_274 -> V_35 -> V_292 ;
V_279 -> V_59 = V_275 ;
V_275 = V_279 ;
V_277 += V_100 [ V_130 ] -> V_47 . V_277 ;
if ( V_100 [ V_130 ] -> type -> V_49 & V_293 )
V_268 += V_100 [ V_130 ] -> V_47 . V_277 ;
V_278 += V_100 [ V_130 ] -> V_47 . V_278 ;
}
V_275 -> V_282 = V_40 ;
V_276 -> V_267 = V_40 ;
V_193 = - V_294 ;
V_271 = V_40 -> V_271 ;
if ( ! V_271 )
goto V_295;
F_175 ( (struct V_256 * ) V_276 , V_40 , V_268 ) ;
F_185 ( V_275 ) ;
for ( V_275 = V_276 ; V_275 != V_40 ; V_275 = V_275 -> V_282 ) {
struct V_256 * V_257 = (struct V_256 * ) V_275 ;
V_193 = F_176 ( V_257 , V_271 , V_7 ) ;
if ( V_193 )
goto V_295;
V_275 -> V_277 = V_277 ;
V_275 -> V_278 = V_278 ;
V_277 -= V_257 -> V_10 . V_40 . V_100 -> V_47 . V_277 ;
V_278 -= V_257 -> V_10 . V_40 . V_100 -> V_47 . V_278 ;
}
V_66:
return V_276 ;
V_280:
for (; V_130 < V_235 ; V_130 ++ )
F_161 ( V_100 [ V_130 ] ) ;
V_295:
if ( V_276 )
F_170 ( V_276 ) ;
V_276 = F_17 ( V_193 ) ;
goto V_66;
}
static int F_186 ( void * * V_296 , const void * V_297 , int V_298 )
{
if ( ! * V_296 ) {
* V_296 = F_187 ( V_298 , V_224 ) ;
if ( ! * V_296 )
return - V_231 ;
}
memcpy ( * V_296 , V_297 , V_298 ) ;
return 0 ;
}
static int F_188 ( struct V_36 * V_40 ,
const struct V_4 * V_5 )
{
#ifdef F_141
struct V_256 * V_257 = (struct V_256 * ) V_40 ;
return F_186 ( ( void * * ) & ( V_257 -> V_299 ) ,
V_5 , sizeof( * V_5 ) ) ;
#else
return 0 ;
#endif
}
static int F_189 ( struct V_36 * V_40 ,
const struct V_6 * V_7 )
{
#ifdef F_141
struct V_256 * V_257 = (struct V_256 * ) V_40 ;
return F_186 ( ( void * * ) & ( V_257 -> V_300 ) , V_7 , sizeof( * V_7 ) ) ;
#else
return 0 ;
#endif
}
static int F_190 ( const struct V_6 * V_7 , T_5 V_31 ,
struct V_1 * * V_248 ,
int * V_301 , int * V_259 )
{
int V_130 ;
if ( * V_301 == 0 || ! V_248 [ 0 ] ) {
* V_301 = 0 ;
* V_259 = 0 ;
return 0 ;
}
if ( F_20 ( V_248 [ 0 ] ) )
return F_179 ( V_248 [ 0 ] ) ;
* V_259 = V_248 [ 0 ] -> V_226 ;
#ifdef F_141
if ( V_248 [ 0 ] && V_248 [ 0 ] -> V_225 == V_302 &&
V_248 [ 0 ] -> type != V_212 ) {
V_248 [ 1 ] = F_134 ( V_85 ( V_248 [ 0 ] ) ,
V_212 ,
V_7 , V_31 ,
V_144 ) ;
if ( V_248 [ 1 ] ) {
if ( F_20 ( V_248 [ 1 ] ) ) {
F_191 ( V_248 , * V_301 ) ;
return F_179 ( V_248 [ 1 ] ) ;
}
( * V_301 ) ++ ;
( * V_259 ) += V_248 [ 1 ] -> V_226 ;
}
}
#endif
for ( V_130 = 0 ; V_130 < * V_301 ; V_130 ++ ) {
if ( V_248 [ V_130 ] -> V_225 != V_302 ) {
* V_259 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_256 *
F_192 ( struct V_1 * * V_248 , int V_301 ,
const struct V_6 * V_7 , T_5 V_31 ,
struct V_36 * V_303 )
{
struct V_37 * V_37 = V_85 ( V_248 [ 0 ] ) ;
struct V_43 * V_100 [ V_251 ] ;
struct V_36 * V_40 ;
struct V_256 * V_257 ;
int V_193 ;
V_193 = F_162 ( V_248 , V_301 , V_7 , V_100 , V_31 ) ;
if ( V_193 <= 0 ) {
if ( V_193 != 0 && V_193 != - V_246 )
F_193 ( V_37 , V_304 ) ;
return F_17 ( V_193 ) ;
}
V_40 = F_177 ( V_248 [ 0 ] , V_100 , V_193 , V_7 , V_303 ) ;
if ( F_20 ( V_40 ) ) {
F_193 ( V_37 , V_305 ) ;
return F_145 ( V_40 ) ;
}
V_257 = (struct V_256 * ) V_40 ;
V_257 -> V_259 = V_193 ;
if ( V_301 > 1 )
V_193 = F_188 ( V_40 , & V_248 [ 1 ] -> V_124 ) ;
else
V_193 = F_189 ( V_40 , V_7 ) ;
if ( F_11 ( V_193 ) ) {
F_170 ( V_40 ) ;
F_193 ( V_37 , V_306 ) ;
return F_17 ( V_193 ) ;
}
V_257 -> V_301 = V_301 ;
memcpy ( V_257 -> V_248 , V_248 , sizeof( struct V_1 * ) * V_301 ) ;
V_257 -> V_307 = F_194 ( & V_248 [ 0 ] -> V_99 ) ;
return V_257 ;
}
static void V_92 ( unsigned long V_308 )
{
struct V_309 * V_310 ;
struct V_217 * V_218 ;
struct V_36 * V_40 ;
struct V_1 * V_83 = (struct V_1 * ) V_308 ;
struct V_37 * V_37 = V_85 ( V_83 ) ;
struct V_178 * V_179 = & V_83 -> V_89 ;
struct V_6 V_7 ;
struct V_180 V_115 ;
F_195 ( & V_179 -> V_90 . V_63 ) ;
V_310 = F_196 ( & V_179 -> V_90 ) ;
if ( ! V_310 ) {
F_197 ( & V_179 -> V_90 . V_63 ) ;
goto V_66;
}
V_40 = F_198 ( V_310 ) ;
V_218 = V_310 -> V_218 ;
F_199 ( V_310 , & V_7 , V_40 -> V_93 -> V_31 ) ;
F_197 ( & V_179 -> V_90 . V_63 ) ;
F_167 ( V_40 -> V_267 ) ;
V_40 = F_200 ( V_37 , V_40 -> V_267 , & V_7 , V_218 , 0 ) ;
if ( F_20 ( V_40 ) )
goto V_311;
if ( V_40 -> V_49 & V_260 ) {
F_180 ( V_40 ) ;
if ( V_179 -> V_181 >= V_312 )
goto V_311;
V_179 -> V_181 = V_179 -> V_181 << 1 ;
if ( ! F_27 ( & V_179 -> V_91 , V_80 + V_179 -> V_181 ) )
F_28 ( V_83 ) ;
goto V_66;
}
F_180 ( V_40 ) ;
F_104 ( & V_115 ) ;
F_195 ( & V_179 -> V_90 . V_63 ) ;
V_179 -> V_181 = 0 ;
F_105 ( & V_179 -> V_90 , & V_115 ) ;
F_197 ( & V_179 -> V_90 . V_63 ) ;
while ( ! F_103 ( & V_115 ) ) {
V_310 = F_201 ( & V_115 ) ;
F_199 ( V_310 , & V_7 , F_198 ( V_310 ) -> V_93 -> V_31 ) ;
F_167 ( F_198 ( V_310 ) -> V_267 ) ;
V_40 = F_200 ( V_37 , F_198 ( V_310 ) -> V_267 , & V_7 , V_310 -> V_218 , 0 ) ;
if ( F_20 ( V_40 ) ) {
F_202 ( V_310 ) ;
continue;
}
F_203 ( V_310 ) ;
F_204 ( V_310 ) ;
F_205 ( V_310 , V_40 ) ;
F_206 ( V_37 , V_310 -> V_218 , V_310 ) ;
}
V_66:
F_30 ( V_83 ) ;
return;
V_311:
V_179 -> V_181 = 0 ;
F_55 ( & V_179 -> V_90 ) ;
F_30 ( V_83 ) ;
}
static int F_207 ( struct V_37 * V_37 , struct V_217 * V_218 , struct V_309 * V_310 )
{
unsigned long V_313 ;
struct V_36 * V_40 = F_198 ( V_310 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_40 ;
struct V_1 * V_83 = V_257 -> V_248 [ 0 ] ;
struct V_178 * V_179 = & V_83 -> V_89 ;
if ( F_11 ( F_208 ( V_218 , V_310 ) ) ) {
F_202 ( V_310 ) ;
return 0 ;
}
if ( V_179 -> V_90 . V_314 > V_315 ) {
F_202 ( V_310 ) ;
return - V_246 ;
}
F_209 ( V_310 ) ;
F_76 ( & V_179 -> V_90 . V_63 ) ;
if ( ! V_179 -> V_181 )
V_179 -> V_181 = V_182 ;
V_313 = V_80 + V_179 -> V_181 ;
if ( F_50 ( & V_179 -> V_91 ) ) {
if ( F_210 ( V_179 -> V_91 . V_316 , V_313 ) )
V_313 = V_179 -> V_91 . V_316 ;
F_30 ( V_83 ) ;
}
F_211 ( & V_179 -> V_90 , V_310 ) ;
if ( ! F_27 ( & V_179 -> V_91 , V_313 ) )
F_28 ( V_83 ) ;
F_81 ( & V_179 -> V_90 . V_63 ) ;
return 0 ;
}
static struct V_256 * F_212 ( struct V_37 * V_37 ,
struct V_317 * V_318 ,
const struct V_6 * V_7 ,
int V_259 ,
T_5 V_31 )
{
int V_193 ;
struct V_270 * V_271 ;
struct V_36 * V_40 ;
struct V_36 * V_279 ;
struct V_256 * V_257 ;
V_257 = F_171 ( V_37 , V_31 ) ;
if ( F_20 ( V_257 ) )
return V_257 ;
if ( ! ( V_318 -> V_49 & V_319 ) ||
V_37 -> V_100 . V_320 ||
V_259 <= 0 )
return V_257 ;
V_40 = V_318 -> V_303 ;
V_279 = & V_257 -> V_10 . V_40 ;
F_167 ( V_40 ) ;
V_257 -> V_258 = V_40 ;
F_184 ( V_279 , V_40 ) ;
V_279 -> V_286 = V_287 ;
V_279 -> V_49 |= V_288 | V_260 ;
V_279 -> V_289 = V_80 ;
V_279 -> V_290 = V_291 ;
V_279 -> V_292 = F_207 ;
F_167 ( V_40 ) ;
V_279 -> V_282 = V_40 ;
V_279 -> V_267 = V_40 ;
F_175 ( (struct V_256 * ) V_279 , V_40 , 0 ) ;
V_193 = - V_294 ;
V_271 = V_40 -> V_271 ;
if ( ! V_271 )
goto V_295;
V_193 = F_176 ( V_257 , V_271 , V_7 ) ;
if ( V_193 )
goto V_295;
V_66:
return V_257 ;
V_295:
F_180 ( V_279 ) ;
V_257 = F_17 ( V_193 ) ;
goto V_66;
}
static struct V_81 *
F_213 ( struct V_37 * V_37 , const struct V_6 * V_7 , T_5 V_31 , T_4 V_62 ,
struct V_81 * V_321 , void * V_191 )
{
struct V_317 * V_318 = (struct V_317 * ) V_191 ;
struct V_1 * V_248 [ V_201 ] ;
struct V_256 * V_257 , * V_322 ;
int V_301 = 0 , V_259 = 0 , V_130 , V_193 , V_323 ;
V_257 = NULL ;
if ( V_321 ) {
V_257 = F_33 ( V_321 , struct V_256 , V_82 ) ;
V_301 = V_257 -> V_301 ;
V_259 = V_257 -> V_259 ;
V_323 = 0 ;
for ( V_130 = 0 ; V_130 < V_301 ; V_130 ++ ) {
V_248 [ V_130 ] = V_257 -> V_248 [ V_130 ] ;
V_323 |= V_248 [ V_130 ] -> V_64 . V_65 ;
}
if ( V_323 ) {
F_170 ( & V_257 -> V_10 . V_40 ) ;
V_257 = NULL ;
V_301 = 0 ;
V_259 = 0 ;
V_321 = NULL ;
}
}
if ( V_257 == NULL ) {
V_301 = 1 ;
V_248 [ 0 ] = F_140 ( V_37 , V_7 , V_31 ,
F_142 ( V_62 ) ) ;
V_193 = F_190 ( V_7 , V_31 , V_248 ,
& V_301 , & V_259 ) ;
if ( V_193 < 0 )
goto V_324;
if ( V_301 == 0 )
return NULL ;
if ( V_259 <= 0 )
goto V_325;
}
V_322 = F_192 ( V_248 , V_301 , V_7 , V_31 ,
V_318 -> V_303 ) ;
if ( F_20 ( V_322 ) ) {
V_193 = F_179 ( V_322 ) ;
if ( V_193 != - V_246 )
goto error;
if ( V_321 == NULL )
goto V_325;
F_167 ( & V_257 -> V_10 . V_40 ) ;
return V_321 ;
} else if ( V_322 == NULL ) {
V_259 = 0 ;
if ( V_321 == NULL )
goto V_325;
V_257 -> V_259 = 0 ;
F_167 ( & V_257 -> V_10 . V_40 ) ;
return V_321 ;
}
if ( V_257 ) {
V_257 -> V_301 = 0 ;
F_170 ( & V_257 -> V_10 . V_40 ) ;
}
F_167 ( & V_322 -> V_10 . V_40 ) ;
return & V_322 -> V_82 ;
V_325:
V_257 = F_212 ( V_37 , V_318 , V_7 , V_259 , V_31 ) ;
if ( F_20 ( V_257 ) ) {
F_191 ( V_248 , V_301 ) ;
return F_145 ( V_257 ) ;
}
V_257 -> V_301 = V_301 ;
V_257 -> V_259 = V_259 ;
memcpy ( V_257 -> V_248 , V_248 , sizeof( struct V_1 * ) * V_301 ) ;
F_167 ( & V_257 -> V_10 . V_40 ) ;
return & V_257 -> V_82 ;
V_324:
F_193 ( V_37 , V_304 ) ;
error:
if ( V_257 != NULL )
F_170 ( & V_257 -> V_10 . V_40 ) ;
else
F_191 ( V_248 , V_301 ) ;
return F_17 ( V_193 ) ;
}
static struct V_36 * F_214 ( struct V_37 * V_37 , T_5 V_31 ,
struct V_36 * V_303 )
{
const struct V_34 * V_35 = F_10 ( V_31 ) ;
struct V_36 * V_194 ;
if ( ! V_35 ) {
F_180 ( V_303 ) ;
return F_17 ( - V_203 ) ;
} else {
V_194 = V_35 -> V_326 ( V_37 , V_303 ) ;
}
F_15 () ;
return V_194 ;
}
struct V_36 * F_200 ( struct V_37 * V_37 , struct V_36 * V_303 ,
const struct V_6 * V_7 ,
const struct V_217 * V_218 , int V_49 )
{
struct V_1 * V_248 [ V_201 ] ;
struct V_81 * V_82 ;
struct V_256 * V_257 ;
struct V_36 * V_40 , * V_258 ;
T_5 V_31 = V_303 -> V_93 -> V_31 ;
T_4 V_62 = F_146 ( V_144 ) ;
int V_130 , V_193 , V_301 , V_259 = 0 , V_327 = 0 ;
V_40 = NULL ;
V_257 = NULL ;
V_258 = NULL ;
V_218 = F_215 ( V_218 ) ;
if ( V_218 && V_218 -> V_220 [ V_144 ] ) {
V_301 = 1 ;
V_248 [ 0 ] = F_147 ( V_218 , V_144 , V_7 , V_31 ) ;
V_193 = F_190 ( V_7 , V_31 , V_248 ,
& V_301 , & V_259 ) ;
if ( V_193 < 0 )
goto V_328;
if ( V_301 ) {
if ( V_259 <= 0 ) {
V_327 = V_301 ;
goto V_329;
}
V_257 = F_192 (
V_248 , V_301 , V_7 ,
V_31 , V_303 ) ;
if ( F_20 ( V_257 ) ) {
F_191 ( V_248 , V_301 ) ;
V_193 = F_179 ( V_257 ) ;
goto V_328;
} else if ( V_257 == NULL ) {
V_259 = 0 ;
V_327 = V_301 ;
goto V_329;
}
F_167 ( & V_257 -> V_10 . V_40 ) ;
V_257 -> V_10 . V_40 . V_49 |= V_330 ;
V_258 = V_257 -> V_258 ;
}
}
if ( V_257 == NULL ) {
struct V_317 V_318 ;
V_318 . V_303 = V_303 ;
V_318 . V_49 = V_49 ;
if ( ( V_303 -> V_49 & V_331 ) ||
! V_37 -> V_100 . V_137 [ V_144 ] )
goto V_332;
V_82 = F_216 ( V_37 , V_7 , V_31 , V_62 ,
F_213 , & V_318 ) ;
if ( V_82 == NULL )
goto V_332;
if ( F_20 ( V_82 ) ) {
V_193 = F_179 ( V_82 ) ;
goto V_328;
}
V_257 = F_33 ( V_82 , struct V_256 , V_82 ) ;
V_301 = V_257 -> V_301 ;
V_259 = V_257 -> V_259 ;
memcpy ( V_248 , V_257 -> V_248 , sizeof( struct V_1 * ) * V_301 ) ;
V_258 = V_257 -> V_258 ;
}
V_40 = & V_257 -> V_10 . V_40 ;
if ( V_258 == NULL && V_259 > 0 ) {
if ( V_37 -> V_100 . V_320 ) {
F_193 ( V_37 , V_333 ) ;
V_193 = - V_334 ;
goto error;
}
V_193 = - V_246 ;
F_193 ( V_37 , V_333 ) ;
goto error;
}
V_329:
if ( V_301 == 0 )
goto V_332;
if ( ( V_49 & V_335 ) &&
! ( V_248 [ 0 ] -> V_49 & V_336 ) ) {
V_193 = - V_195 ;
goto error;
}
for ( V_130 = 0 ; V_130 < V_301 ; V_130 ++ )
V_248 [ V_130 ] -> V_71 . V_75 = F_23 () ;
if ( V_259 < 0 ) {
F_193 ( V_37 , V_337 ) ;
V_193 = - V_338 ;
goto error;
} else if ( V_259 > 0 ) {
F_180 ( V_303 ) ;
} else {
F_180 ( V_40 ) ;
V_40 = V_303 ;
}
V_339:
F_191 ( V_248 , V_327 ) ;
if ( V_40 && V_40 -> V_100 &&
V_40 -> V_100 -> V_47 . V_237 == V_238 )
V_40 -> V_49 |= V_340 ;
return V_40 ;
V_332:
if ( ! ( V_49 & V_335 ) ) {
V_40 = V_303 ;
goto V_339;
}
V_193 = - V_195 ;
error:
F_180 ( V_40 ) ;
V_328:
if ( ! ( V_49 & V_341 ) )
F_180 ( V_303 ) ;
F_191 ( V_248 , V_327 ) ;
return F_17 ( V_193 ) ;
}
struct V_36 * F_217 ( struct V_37 * V_37 , struct V_36 * V_303 ,
const struct V_6 * V_7 ,
const struct V_217 * V_218 , int V_49 )
{
struct V_36 * V_40 = F_200 ( V_37 , V_303 , V_7 , V_218 ,
V_49 | V_319 |
V_341 ) ;
if ( F_20 ( V_40 ) && F_179 ( V_40 ) == - V_334 )
return F_214 ( V_37 , V_303 -> V_93 -> V_31 , V_303 ) ;
return V_40 ;
}
static inline int
F_218 ( int V_169 , struct V_309 * V_310 , const struct V_6 * V_7 )
{
struct V_43 * V_44 ;
if ( ! V_310 -> V_342 || V_169 < 0 || V_169 >= V_310 -> V_342 -> V_175 )
return 0 ;
V_44 = V_310 -> V_342 -> V_343 [ V_169 ] ;
if ( ! V_44 -> type -> V_344 )
return 0 ;
return V_44 -> type -> V_344 ( V_44 , V_310 , V_7 ) ;
}
static inline int
F_219 ( const struct V_228 * V_236 , const struct V_43 * V_44 ,
unsigned short V_31 )
{
if ( F_220 ( V_44 ) )
return V_236 -> V_247 && ! F_221 ( V_236 , V_44 , V_236 -> V_240 ) ;
return V_44 -> V_48 . V_23 == V_236 -> V_48 . V_23 &&
( V_44 -> V_48 . V_345 == V_236 -> V_48 . V_345 || ! V_236 -> V_48 . V_345 ) &&
( V_44 -> V_47 . V_346 == V_236 -> V_346 || ! V_236 -> V_346 ) &&
V_44 -> V_47 . V_237 == V_236 -> V_237 &&
( V_236 -> V_347 || ( V_236 -> V_348 & ( 1 << V_44 -> V_47 . V_349 ) ) ||
! ( F_222 ( V_236 -> V_48 . V_23 , V_350 ) ) ) &&
! ( V_44 -> V_47 . V_237 != V_284 &&
F_221 ( V_236 , V_44 , V_31 ) ) ;
}
static inline int
F_223 ( const struct V_228 * V_236 , const struct V_351 * V_342 , int V_352 ,
unsigned short V_31 )
{
int V_169 = V_352 ;
if ( V_236 -> V_247 ) {
if ( V_236 -> V_237 == V_284 )
return V_352 ;
} else
V_352 = - 1 ;
for (; V_169 < V_342 -> V_175 ; V_169 ++ ) {
if ( F_219 ( V_236 , V_342 -> V_343 [ V_169 ] , V_31 ) )
return ++ V_169 ;
if ( V_342 -> V_343 [ V_169 ] -> V_47 . V_237 != V_284 ) {
if ( V_352 == - 1 )
V_352 = - 2 - V_169 ;
break;
}
}
return V_352 ;
}
int F_224 ( struct V_309 * V_310 , struct V_6 * V_7 ,
unsigned int V_31 , int V_353 )
{
const struct V_34 * V_35 = F_10 ( V_31 ) ;
int V_193 ;
if ( F_11 ( V_35 == NULL ) )
return - V_41 ;
V_35 -> V_354 ( V_310 , V_7 , V_353 ) ;
V_193 = F_225 ( V_310 , & V_7 -> V_207 ) ;
F_15 () ;
return V_193 ;
}
static inline int F_226 ( const struct V_351 * V_342 , int V_355 , int * V_356 )
{
for (; V_355 < V_342 -> V_175 ; V_355 ++ ) {
if ( V_342 -> V_343 [ V_355 ] -> V_47 . V_237 != V_284 ) {
* V_356 = V_355 ;
return 1 ;
}
}
return 0 ;
}
int F_227 ( struct V_217 * V_218 , int V_62 , struct V_309 * V_310 ,
unsigned short V_31 )
{
struct V_37 * V_37 = F_228 ( V_310 -> V_271 ) ;
struct V_1 * V_83 ;
struct V_1 * V_248 [ V_201 ] ;
int V_249 = 0 ;
int V_226 ;
int V_357 ;
int V_353 ;
struct V_6 V_7 ;
T_4 V_358 ;
int V_359 = - 1 ;
V_353 = V_62 & ~ V_165 ;
V_62 &= V_165 ;
V_358 = F_146 ( V_62 ) ;
if ( F_224 ( V_310 , & V_7 , V_31 , V_353 ) < 0 ) {
F_193 ( V_37 , V_360 ) ;
return 0 ;
}
F_229 ( V_310 , & V_7 , V_31 ) ;
if ( V_310 -> V_342 ) {
int V_130 ;
for ( V_130 = V_310 -> V_342 -> V_175 - 1 ; V_130 >= 0 ; V_130 -- ) {
struct V_43 * V_44 = V_310 -> V_342 -> V_343 [ V_130 ] ;
if ( ! F_9 ( & V_44 -> V_5 , & V_7 , V_31 ) ) {
F_193 ( V_37 , V_361 ) ;
return 0 ;
}
}
}
V_83 = NULL ;
V_218 = F_230 ( V_218 ) ;
if ( V_218 && V_218 -> V_220 [ V_62 ] ) {
V_83 = F_147 ( V_218 , V_62 , & V_7 , V_31 ) ;
if ( F_20 ( V_83 ) ) {
F_193 ( V_37 , V_362 ) ;
return 0 ;
}
}
if ( ! V_83 ) {
struct V_81 * V_82 ;
V_82 = F_216 ( V_37 , & V_7 , V_31 , V_358 ,
F_143 , NULL ) ;
if ( F_144 ( V_82 ) )
V_83 = F_145 ( V_82 ) ;
else
V_83 = F_33 ( V_82 , struct V_1 , V_82 ) ;
}
if ( F_20 ( V_83 ) ) {
F_193 ( V_37 , V_362 ) ;
return 0 ;
}
if ( ! V_83 ) {
if ( V_310 -> V_342 && F_226 ( V_310 -> V_342 , 0 , & V_359 ) ) {
F_218 ( V_359 , V_310 , & V_7 ) ;
F_193 ( V_37 , V_363 ) ;
return 0 ;
}
return 1 ;
}
V_83 -> V_71 . V_75 = F_23 () ;
V_248 [ 0 ] = V_83 ;
V_249 ++ ;
#ifdef F_141
if ( V_248 [ 0 ] -> type != V_212 ) {
V_248 [ 1 ] = F_134 ( V_37 , V_212 ,
& V_7 , V_31 ,
V_142 ) ;
if ( V_248 [ 1 ] ) {
if ( F_20 ( V_248 [ 1 ] ) ) {
F_193 ( V_37 , V_362 ) ;
return 0 ;
}
V_248 [ 1 ] -> V_71 . V_75 = F_23 () ;
V_249 ++ ;
}
}
#endif
if ( V_83 -> V_225 == V_302 ) {
struct V_351 * V_342 ;
static struct V_351 V_364 ;
struct V_228 * V_250 [ V_251 ] ;
struct V_228 * V_365 [ V_251 ] ;
struct V_228 * * V_252 = V_250 ;
int V_366 = 0 ;
int V_130 , V_355 ;
if ( ( V_342 = V_310 -> V_342 ) == NULL )
V_342 = & V_364 ;
for ( V_357 = 0 ; V_357 < V_249 ; V_357 ++ ) {
if ( V_248 [ V_357 ] != V_83 &&
V_248 [ V_357 ] -> V_225 != V_302 ) {
F_193 ( V_37 , V_367 ) ;
goto V_344;
}
if ( V_366 + V_248 [ V_357 ] -> V_226 >= V_251 ) {
F_193 ( V_37 , V_368 ) ;
goto V_369;
}
for ( V_130 = 0 ; V_130 < V_248 [ V_357 ] -> V_226 ; V_130 ++ )
V_252 [ V_366 ++ ] = & V_248 [ V_357 ] -> V_227 [ V_130 ] ;
}
V_226 = V_366 ;
if ( V_249 > 1 ) {
F_231 ( V_365 , V_252 , V_226 , V_31 , V_37 ) ;
V_252 = V_365 ;
}
for ( V_130 = V_226 - 1 , V_355 = 0 ; V_130 >= 0 ; V_130 -- ) {
V_355 = F_223 ( V_252 [ V_130 ] , V_342 , V_355 , V_31 ) ;
if ( V_355 < 0 ) {
if ( V_355 < - 1 )
V_359 = - ( 2 + V_355 ) ;
F_193 ( V_37 , V_370 ) ;
goto V_344;
}
}
if ( F_226 ( V_342 , V_355 , & V_359 ) ) {
F_193 ( V_37 , V_370 ) ;
goto V_344;
}
F_191 ( V_248 , V_249 ) ;
return 1 ;
}
F_193 ( V_37 , V_367 ) ;
V_344:
F_218 ( V_359 , V_310 , & V_7 ) ;
V_369:
F_191 ( V_248 , V_249 ) ;
return 0 ;
}
int F_232 ( struct V_309 * V_310 , unsigned short V_31 )
{
struct V_37 * V_37 = F_228 ( V_310 -> V_271 ) ;
struct V_6 V_7 ;
struct V_36 * V_40 ;
int V_371 = 1 ;
if ( F_199 ( V_310 , & V_7 , V_31 ) < 0 ) {
F_193 ( V_37 , V_372 ) ;
return 0 ;
}
F_209 ( V_310 ) ;
V_40 = F_200 ( V_37 , F_198 ( V_310 ) , & V_7 , NULL , V_319 ) ;
if ( F_20 ( V_40 ) ) {
V_371 = 0 ;
V_40 = NULL ;
}
F_205 ( V_310 , V_40 ) ;
return V_371 ;
}
static struct V_36 * F_233 ( struct V_36 * V_40 , T_3 V_373 )
{
if ( V_40 -> V_286 < 0 && ! F_166 ( V_40 ) )
return V_40 ;
return NULL ;
}
static int F_166 ( struct V_36 * V_40 )
{
return ! F_234 ( (struct V_256 * ) V_40 ) ;
}
void F_235 ( struct V_36 * V_40 , struct V_270 * V_271 )
{
while ( ( V_40 = V_40 -> V_282 ) && V_40 -> V_100 && V_40 -> V_271 == V_271 ) {
V_40 -> V_271 = F_228 ( V_271 ) -> V_374 ;
F_236 ( V_40 -> V_271 ) ;
F_237 ( V_271 ) ;
}
}
static void F_238 ( struct V_309 * V_310 )
{
}
static struct V_36 * F_239 ( struct V_36 * V_40 )
{
if ( V_40 ) {
if ( V_40 -> V_286 ) {
F_180 ( V_40 ) ;
V_40 = NULL ;
}
}
return V_40 ;
}
void F_121 ( struct V_37 * V_37 )
{
F_240 ( V_37 ) ;
}
void F_241 ( struct V_37 * V_37 )
{
F_242 ( V_37 ) ;
}
static void F_185 ( struct V_36 * V_40 )
{
do {
struct V_256 * V_257 = (struct V_256 * ) V_40 ;
T_3 V_375 , V_376 ;
V_375 = F_243 ( V_40 -> V_282 ) ;
V_257 -> V_377 = V_375 ;
V_375 = F_244 ( V_40 -> V_100 , V_375 ) ;
V_376 = F_243 ( V_257 -> V_258 ) ;
V_257 -> V_376 = V_376 ;
if ( V_375 > V_376 )
V_375 = V_376 ;
F_245 ( V_40 , V_378 , V_375 ) ;
} while ( ( V_40 = V_40 -> V_59 ) );
}
static int F_234 ( struct V_256 * V_379 )
{
struct V_36 * V_40 = & V_379 -> V_10 . V_40 ;
struct V_256 * V_380 ;
T_3 V_381 ;
if ( ! F_246 ( V_40 -> V_267 , ( (struct V_256 * ) V_40 ) -> V_382 ) ||
( V_40 -> V_271 && ! F_247 ( V_40 -> V_271 ) ) )
return 0 ;
if ( V_40 -> V_49 & V_260 )
return 1 ;
V_380 = NULL ;
do {
struct V_256 * V_257 = (struct V_256 * ) V_40 ;
if ( V_40 -> V_100 -> V_242 . V_243 != V_244 )
return 0 ;
if ( V_257 -> V_285 != V_40 -> V_100 -> V_99 )
return 0 ;
if ( V_257 -> V_301 > 0 &&
V_257 -> V_307 != F_194 ( & V_257 -> V_248 [ 0 ] -> V_99 ) )
return 0 ;
V_381 = F_243 ( V_40 -> V_282 ) ;
if ( V_257 -> V_377 != V_381 ) {
V_380 = V_257 ;
V_257 -> V_377 = V_381 ;
}
if ( ! F_246 ( V_257 -> V_258 , V_257 -> V_383 ) )
return 0 ;
V_381 = F_243 ( V_257 -> V_258 ) ;
if ( V_257 -> V_376 != V_381 ) {
V_380 = V_257 ;
V_257 -> V_376 = V_381 ;
}
V_40 = V_40 -> V_282 ;
} while ( V_40 -> V_100 );
if ( F_174 ( ! V_380 ) )
return 1 ;
V_381 = V_380 -> V_377 ;
for (; ; ) {
V_40 = & V_380 -> V_10 . V_40 ;
V_381 = F_244 ( V_40 -> V_100 , V_381 ) ;
if ( V_381 > V_380 -> V_376 )
V_381 = V_380 -> V_376 ;
F_245 ( V_40 , V_378 , V_381 ) ;
if ( V_380 == V_379 )
break;
V_380 = (struct V_256 * ) V_380 -> V_10 . V_40 . V_59 ;
V_380 -> V_377 = V_381 ;
}
return 1 ;
}
static unsigned int F_248 ( const struct V_36 * V_40 )
{
return F_249 ( V_40 -> V_267 ) ;
}
static unsigned int F_250 ( const struct V_36 * V_40 )
{
unsigned int V_381 = F_251 ( V_40 , V_378 ) ;
return V_381 ? : F_243 ( V_40 -> V_267 ) ;
}
static const void * F_252 ( const struct V_36 * V_40 ,
const void * V_12 )
{
const struct V_36 * V_267 = V_40 -> V_267 ;
for (; V_40 != V_267 ; V_40 = V_40 -> V_282 ) {
const struct V_43 * V_100 = V_40 -> V_100 ;
if ( V_100 -> V_47 . V_237 == V_284 )
continue;
if ( V_100 -> type -> V_49 & V_52 )
V_12 = V_100 -> V_51 ;
else if ( ! ( V_100 -> type -> V_49 & V_50 ) )
V_12 = & V_100 -> V_48 . V_12 ;
}
return V_12 ;
}
static struct V_384 * F_253 ( const struct V_36 * V_40 ,
struct V_309 * V_310 ,
const void * V_12 )
{
const struct V_36 * V_267 = V_40 -> V_267 ;
if ( ! V_310 )
V_12 = F_252 ( V_40 , V_12 ) ;
return V_267 -> V_93 -> V_385 ( V_267 , V_310 , V_12 ) ;
}
static void F_254 ( const struct V_36 * V_40 , const void * V_12 )
{
const struct V_36 * V_267 = V_40 -> V_267 ;
V_12 = F_252 ( V_40 , V_12 ) ;
V_267 -> V_93 -> V_386 ( V_267 , V_12 ) ;
}
int F_255 ( const struct V_34 * V_35 , int V_31 )
{
int V_193 = 0 ;
if ( F_110 ( V_31 >= F_12 ( V_34 ) ) )
return - V_41 ;
F_195 ( & V_387 ) ;
if ( F_11 ( V_34 [ V_31 ] != NULL ) )
V_193 = - V_188 ;
else {
struct V_261 * V_261 = V_35 -> V_261 ;
if ( F_174 ( V_261 -> V_388 == NULL ) )
V_261 -> V_388 = V_389 ;
if ( F_174 ( V_261 -> V_390 == NULL ) )
V_261 -> V_390 = F_233 ;
if ( F_174 ( V_261 -> V_391 == NULL ) )
V_261 -> V_391 = F_248 ;
if ( F_174 ( V_261 -> V_381 == NULL ) )
V_261 -> V_381 = F_250 ;
if ( F_174 ( V_261 -> V_392 == NULL ) )
V_261 -> V_392 = F_239 ;
if ( F_174 ( V_261 -> V_393 == NULL ) )
V_261 -> V_393 = F_238 ;
if ( F_174 ( V_261 -> V_385 == NULL ) )
V_261 -> V_385 = F_253 ;
if ( F_174 ( ! V_261 -> V_386 ) )
V_261 -> V_386 = F_254 ;
F_79 ( V_34 [ V_31 ] , V_35 ) ;
}
F_197 ( & V_387 ) ;
return V_193 ;
}
void F_256 ( const struct V_34 * V_35 )
{
struct V_261 * V_261 = V_35 -> V_261 ;
int V_130 ;
for ( V_130 = 0 ; V_130 < F_12 ( V_34 ) ; V_130 ++ ) {
if ( V_34 [ V_130 ] != V_35 )
continue;
F_257 ( V_34 [ V_130 ] , NULL ) ;
break;
}
F_82 () ;
V_261 -> V_388 = NULL ;
V_261 -> V_390 = NULL ;
V_261 -> V_392 = NULL ;
V_261 -> V_393 = NULL ;
}
static int F_258 ( struct V_394 * V_395 , unsigned long V_396 , void * V_397 )
{
struct V_270 * V_271 = F_259 ( V_397 ) ;
switch ( V_396 ) {
case V_398 :
F_121 ( F_228 ( V_271 ) ) ;
}
return V_399 ;
}
static int T_6 F_260 ( struct V_37 * V_37 )
{
int V_400 ;
V_37 -> V_401 . V_402 = F_261 ( struct V_403 ) ;
if ( ! V_37 -> V_401 . V_402 )
return - V_231 ;
V_400 = F_262 ( V_37 ) ;
if ( V_400 < 0 )
F_263 ( V_37 -> V_401 . V_402 ) ;
return V_400 ;
}
static void F_264 ( struct V_37 * V_37 )
{
F_265 ( V_37 ) ;
F_263 ( V_37 -> V_401 . V_402 ) ;
}
static int T_6 F_260 ( struct V_37 * V_37 )
{
return 0 ;
}
static void F_264 ( struct V_37 * V_37 )
{
}
static int T_6 F_266 ( struct V_37 * V_37 )
{
unsigned int V_110 , V_404 ;
int V_62 ;
if ( F_267 ( V_37 , & V_405 ) )
V_389 = F_268 ( L_1 ,
sizeof( struct V_256 ) ,
0 , V_406 | V_407 ,
NULL ) ;
V_110 = 8 - 1 ;
V_404 = ( V_110 + 1 ) * sizeof( struct V_109 ) ;
V_37 -> V_100 . V_134 = F_75 ( V_404 ) ;
if ( ! V_37 -> V_100 . V_134 )
goto V_408;
V_37 -> V_100 . V_101 = V_110 ;
for ( V_62 = 0 ; V_62 < V_148 ; V_62 ++ ) {
struct V_409 * V_410 ;
V_37 -> V_100 . V_137 [ V_62 ] = 0 ;
V_37 -> V_100 . V_137 [ V_148 + V_62 ] = 0 ;
F_94 ( & V_37 -> V_100 . V_112 [ V_62 ] ) ;
V_410 = & V_37 -> V_100 . V_104 [ V_62 ] ;
V_410 -> V_113 = F_75 ( V_404 ) ;
if ( ! V_410 -> V_113 )
goto V_411;
V_410 -> V_110 = V_110 ;
V_410 -> V_105 = 32 ;
V_410 -> V_106 = 32 ;
V_410 -> V_107 = 128 ;
V_410 -> V_108 = 128 ;
}
V_37 -> V_100 . V_157 . V_161 = 32 ;
V_37 -> V_100 . V_157 . V_162 = 32 ;
V_37 -> V_100 . V_157 . V_163 = 128 ;
V_37 -> V_100 . V_157 . V_164 = 128 ;
F_269 ( & V_37 -> V_100 . V_157 . V_63 ) ;
F_39 ( & V_37 -> V_100 . V_204 ) ;
F_270 ( & V_37 -> V_100 . V_155 , F_88 ) ;
F_270 ( & V_37 -> V_100 . V_157 . V_154 , F_91 ) ;
if ( F_267 ( V_37 , & V_405 ) )
F_271 ( & V_412 ) ;
return 0 ;
V_411:
for ( V_62 -- ; V_62 >= 0 ; V_62 -- ) {
struct V_409 * V_410 ;
V_410 = & V_37 -> V_100 . V_104 [ V_62 ] ;
F_83 ( V_410 -> V_113 , V_404 ) ;
}
F_83 ( V_37 -> V_100 . V_134 , V_404 ) ;
V_408:
return - V_231 ;
}
static void F_272 ( struct V_37 * V_37 )
{
unsigned int V_404 ;
int V_62 ;
F_273 ( & V_37 -> V_100 . V_155 ) ;
#ifdef F_141
F_120 ( V_37 , V_211 , false ) ;
#endif
F_120 ( V_37 , V_212 , false ) ;
F_110 ( ! F_124 ( & V_37 -> V_100 . V_204 ) ) ;
for ( V_62 = 0 ; V_62 < V_148 ; V_62 ++ ) {
struct V_409 * V_410 ;
F_110 ( ! F_70 ( & V_37 -> V_100 . V_112 [ V_62 ] ) ) ;
V_410 = & V_37 -> V_100 . V_104 [ V_62 ] ;
V_404 = ( V_410 -> V_110 + 1 ) * sizeof( struct V_109 ) ;
F_110 ( ! F_70 ( V_410 -> V_113 ) ) ;
F_83 ( V_410 -> V_113 , V_404 ) ;
}
V_404 = ( V_37 -> V_100 . V_101 + 1 ) * sizeof( struct V_109 ) ;
F_110 ( ! F_70 ( V_37 -> V_100 . V_134 ) ) ;
F_83 ( V_37 -> V_100 . V_134 , V_404 ) ;
}
static int T_6 F_274 ( struct V_37 * V_37 )
{
int V_400 ;
F_275 ( & V_37 -> V_100 . V_413 ) ;
F_275 ( & V_37 -> V_100 . V_114 ) ;
F_276 ( & V_37 -> V_100 . V_414 ) ;
V_400 = F_260 ( V_37 ) ;
if ( V_400 < 0 )
goto V_415;
V_400 = F_277 ( V_37 ) ;
if ( V_400 < 0 )
goto V_416;
V_400 = F_266 ( V_37 ) ;
if ( V_400 < 0 )
goto V_417;
V_400 = F_278 ( V_37 ) ;
if ( V_400 < 0 )
goto V_418;
V_400 = F_279 ( V_37 ) ;
if ( V_400 < 0 )
goto V_66;
return 0 ;
V_66:
F_280 ( V_37 ) ;
V_418:
F_272 ( V_37 ) ;
V_417:
F_281 ( V_37 ) ;
V_416:
F_264 ( V_37 ) ;
V_415:
return V_400 ;
}
static void T_7 F_282 ( struct V_37 * V_37 )
{
F_283 ( V_37 ) ;
F_280 ( V_37 ) ;
F_272 ( V_37 ) ;
F_281 ( V_37 ) ;
F_264 ( V_37 ) ;
}
void T_8 F_284 ( void )
{
F_285 () ;
F_286 ( & V_419 ) ;
F_287 ( & V_131 ) ;
F_288 () ;
}
static void F_289 ( struct V_1 * V_57 ,
struct V_420 * V_421 )
{
struct V_190 * V_191 = V_57 -> V_98 ;
struct V_4 * V_5 = & V_57 -> V_124 ;
if ( V_191 )
F_290 ( V_421 , L_2 ,
V_191 -> V_422 , V_191 -> V_423 , V_191 -> V_424 ) ;
switch ( V_5 -> V_31 ) {
case V_32 :
F_290 ( V_421 , L_3 , & V_5 -> V_15 . V_13 ) ;
if ( V_5 -> V_16 != 32 )
F_290 ( V_421 , L_4 ,
V_5 -> V_16 ) ;
F_290 ( V_421 , L_5 , & V_5 -> V_12 . V_13 ) ;
if ( V_5 -> V_14 != 32 )
F_290 ( V_421 , L_6 ,
V_5 -> V_14 ) ;
break;
case V_33 :
F_290 ( V_421 , L_7 , V_5 -> V_15 . V_425 ) ;
if ( V_5 -> V_16 != 128 )
F_290 ( V_421 , L_4 ,
V_5 -> V_16 ) ;
F_290 ( V_421 , L_8 , V_5 -> V_12 . V_425 ) ;
if ( V_5 -> V_14 != 128 )
F_290 ( V_421 , L_6 ,
V_5 -> V_14 ) ;
break;
}
}
void F_291 ( struct V_1 * V_57 , int V_426 , bool V_196 )
{
struct V_420 * V_421 ;
V_421 = F_292 ( L_9 ) ;
if ( V_421 == NULL )
return;
F_293 ( V_196 , V_421 ) ;
F_290 ( V_421 , L_10 , V_426 ) ;
F_289 ( V_57 , V_421 ) ;
F_294 ( V_421 ) ;
}
void F_119 ( struct V_1 * V_57 , int V_426 ,
bool V_196 )
{
struct V_420 * V_421 ;
V_421 = F_292 ( L_11 ) ;
if ( V_421 == NULL )
return;
F_293 ( V_196 , V_421 ) ;
F_290 ( V_421 , L_10 , V_426 ) ;
F_289 ( V_57 , V_421 ) ;
F_294 ( V_421 ) ;
}
static bool F_295 ( const struct V_4 * V_427 ,
const struct V_4 * V_428 )
{
if ( V_427 -> V_23 == V_429 ) {
if ( V_428 -> V_31 == V_427 -> V_31 &&
F_296 ( & V_428 -> V_12 , & V_427 -> V_12 ,
V_427 -> V_31 ) &&
F_296 ( & V_428 -> V_15 , & V_427 -> V_15 ,
V_427 -> V_31 ) &&
V_428 -> V_14 == V_427 -> V_14 &&
V_428 -> V_16 == V_427 -> V_16 ) {
return true ;
}
} else {
if ( memcmp ( V_428 , V_427 , sizeof( * V_428 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_1 * F_297 ( const struct V_4 * V_5 ,
T_4 V_62 , T_4 type , struct V_37 * V_37 )
{
struct V_1 * V_83 , * V_194 = NULL ;
struct V_109 * V_158 ;
T_3 V_166 = ~ 0U ;
F_76 ( & V_37 -> V_100 . V_114 ) ;
V_158 = F_63 ( V_37 , & V_5 -> V_12 , & V_5 -> V_15 , V_5 -> V_31 , V_62 ) ;
F_96 (pol, chain, bydst) {
if ( F_295 ( V_5 , & V_83 -> V_124 ) &&
V_83 -> type == type ) {
V_194 = V_83 ;
V_166 = V_194 -> V_166 ;
break;
}
}
V_158 = & V_37 -> V_100 . V_112 [ V_62 ] ;
F_96 (pol, chain, bydst) {
if ( ( V_83 -> V_166 >= V_166 ) && V_194 )
break;
if ( F_295 ( V_5 , & V_83 -> V_124 ) &&
V_83 -> type == type ) {
V_194 = V_83 ;
break;
}
}
F_28 ( V_194 ) ;
F_81 ( & V_37 -> V_100 . V_114 ) ;
return V_194 ;
}
static int F_298 ( const struct V_430 * V_185 , const struct V_228 * V_431 )
{
int V_205 = 0 ;
if ( V_431 -> V_237 == V_185 -> V_237 && V_431 -> V_48 . V_23 == V_185 -> V_23 &&
( V_185 -> V_346 == 0 || V_431 -> V_346 == V_185 -> V_346 ) ) {
switch ( V_431 -> V_237 ) {
case V_238 :
case V_239 :
if ( F_296 ( & V_431 -> V_48 . V_12 , & V_185 -> V_432 ,
V_185 -> V_433 ) &&
F_296 ( & V_431 -> V_15 , & V_185 -> V_434 ,
V_185 -> V_433 ) ) {
V_205 = 1 ;
}
break;
case V_284 :
V_205 = 1 ;
break;
default:
break;
}
}
return V_205 ;
}
static int F_299 ( struct V_1 * V_83 ,
struct V_430 * V_185 , int V_435 )
{
struct V_430 * V_436 ;
int V_130 , V_437 , V_438 = 0 ;
F_300 ( & V_83 -> V_63 ) ;
if ( F_11 ( V_83 -> V_64 . V_65 ) ) {
F_301 ( & V_83 -> V_63 ) ;
return - V_195 ;
}
for ( V_130 = 0 ; V_130 < V_83 -> V_226 ; V_130 ++ ) {
for ( V_437 = 0 , V_436 = V_185 ; V_437 < V_435 ; V_437 ++ , V_436 ++ ) {
if ( ! F_298 ( V_436 , & V_83 -> V_227 [ V_130 ] ) )
continue;
V_438 ++ ;
if ( V_83 -> V_227 [ V_130 ] . V_237 != V_238 &&
V_83 -> V_227 [ V_130 ] . V_237 != V_239 )
continue;
memcpy ( & V_83 -> V_227 [ V_130 ] . V_48 . V_12 , & V_436 -> V_439 ,
sizeof( V_83 -> V_227 [ V_130 ] . V_48 . V_12 ) ) ;
memcpy ( & V_83 -> V_227 [ V_130 ] . V_15 , & V_436 -> V_440 ,
sizeof( V_83 -> V_227 [ V_130 ] . V_15 ) ) ;
V_83 -> V_227 [ V_130 ] . V_240 = V_436 -> V_441 ;
F_54 ( & V_83 -> V_99 ) ;
}
}
F_301 ( & V_83 -> V_63 ) ;
if ( ! V_438 )
return - V_442 ;
return 0 ;
}
static int F_302 ( const struct V_430 * V_185 , int V_435 )
{
int V_130 , V_437 ;
if ( V_435 < 1 || V_435 > V_251 )
return - V_203 ;
for ( V_130 = 0 ; V_130 < V_435 ; V_130 ++ ) {
if ( F_296 ( & V_185 [ V_130 ] . V_432 , & V_185 [ V_130 ] . V_439 ,
V_185 [ V_130 ] . V_433 ) &&
F_296 ( & V_185 [ V_130 ] . V_434 , & V_185 [ V_130 ] . V_440 ,
V_185 [ V_130 ] . V_433 ) )
return - V_203 ;
if ( F_159 ( & V_185 [ V_130 ] . V_439 , V_185 [ V_130 ] . V_441 ) ||
F_159 ( & V_185 [ V_130 ] . V_440 , V_185 [ V_130 ] . V_441 ) )
return - V_203 ;
for ( V_437 = V_130 + 1 ; V_437 < V_435 ; V_437 ++ ) {
if ( ! memcmp ( & V_185 [ V_130 ] . V_432 , & V_185 [ V_437 ] . V_432 ,
sizeof( V_185 [ V_130 ] . V_432 ) ) &&
! memcmp ( & V_185 [ V_130 ] . V_434 , & V_185 [ V_437 ] . V_434 ,
sizeof( V_185 [ V_130 ] . V_434 ) ) &&
V_185 [ V_130 ] . V_23 == V_185 [ V_437 ] . V_23 &&
V_185 [ V_130 ] . V_237 == V_185 [ V_437 ] . V_237 &&
V_185 [ V_130 ] . V_346 == V_185 [ V_437 ] . V_346 &&
V_185 [ V_130 ] . V_433 == V_185 [ V_437 ] . V_433 )
return - V_203 ;
}
}
return 0 ;
}
int V_430 ( const struct V_4 * V_5 , T_4 V_62 , T_4 type ,
struct V_430 * V_185 , int V_435 ,
struct V_443 * V_355 , struct V_37 * V_37 )
{
int V_130 , V_193 , V_444 = 0 , V_445 = 0 ;
struct V_1 * V_83 = NULL ;
struct V_43 * V_44 , * V_446 ;
struct V_43 * V_447 [ V_251 ] ;
struct V_43 * V_448 [ V_251 ] ;
struct V_430 * V_436 ;
if ( ( V_193 = F_302 ( V_185 , V_435 ) ) < 0 )
goto V_66;
if ( ( V_83 = F_297 ( V_5 , V_62 , type , V_37 ) ) == NULL ) {
V_193 = - V_195 ;
goto V_66;
}
for ( V_130 = 0 , V_436 = V_185 ; V_130 < V_435 ; V_130 ++ , V_436 ++ ) {
if ( ( V_44 = F_303 ( V_436 , V_37 ) ) ) {
V_447 [ V_444 ] = V_44 ;
V_444 ++ ;
if ( ( V_446 = F_304 ( V_44 , V_436 ) ) ) {
V_448 [ V_445 ] = V_446 ;
V_445 ++ ;
} else {
V_193 = - V_442 ;
goto V_449;
}
}
}
if ( ( V_193 = F_299 ( V_83 , V_185 , V_435 ) ) < 0 )
goto V_449;
if ( V_444 ) {
F_305 ( V_447 , V_444 ) ;
F_306 ( V_447 , V_444 ) ;
}
F_307 ( V_5 , V_62 , type , V_185 , V_435 , V_355 ) ;
F_30 ( V_83 ) ;
return 0 ;
V_66:
return V_193 ;
V_449:
if ( V_83 )
F_30 ( V_83 ) ;
if ( V_444 )
F_305 ( V_447 , V_444 ) ;
if ( V_445 )
F_306 ( V_448 , V_445 ) ;
return V_193 ;
}
