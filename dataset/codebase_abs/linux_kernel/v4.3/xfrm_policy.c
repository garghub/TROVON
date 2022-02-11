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
void F_43 ( struct V_55 * V_84 )
{
F_44 ( ! V_84 -> V_63 . V_64 ) ;
if ( F_45 ( & V_84 -> V_78 ) || F_45 ( & V_84 -> V_90 . V_92 ) )
F_46 () ;
F_47 ( V_84 -> V_96 ) ;
F_48 ( V_84 ) ;
}
static void F_49 ( struct V_55 * V_84 )
{
V_84 -> V_63 . V_64 = 1 ;
F_50 ( & V_84 -> V_97 ) ;
if ( F_45 ( & V_84 -> V_90 . V_92 ) )
F_28 ( V_84 ) ;
F_51 ( & V_84 -> V_90 . V_91 ) ;
if ( F_45 ( & V_84 -> V_78 ) )
F_28 ( V_84 ) ;
F_28 ( V_84 ) ;
}
static inline unsigned int F_52 ( struct V_35 * V_35 , T_3 V_66 )
{
return F_53 ( V_66 , V_35 -> V_98 . V_99 ) ;
}
static void F_54 ( struct V_35 * V_35 ,
unsigned short V_28 , int V_61 ,
T_4 * V_100 , T_4 * V_101 )
{
switch ( V_28 ) {
case V_29 :
* V_100 = V_35 -> V_98 . V_102 [ V_61 ] . V_103 ;
* V_101 = V_35 -> V_98 . V_102 [ V_61 ] . V_104 ;
break;
case V_30 :
* V_100 = V_35 -> V_98 . V_102 [ V_61 ] . V_105 ;
* V_101 = V_35 -> V_98 . V_102 [ V_61 ] . V_106 ;
break;
default:
* V_100 = 0 ;
* V_101 = 0 ;
}
}
static struct V_107 * F_55 ( struct V_35 * V_35 ,
const struct V_1 * V_2 ,
unsigned short V_28 , int V_61 )
{
unsigned int V_108 = V_35 -> V_98 . V_102 [ V_61 ] . V_108 ;
unsigned int V_109 ;
T_4 V_100 ;
T_4 V_101 ;
F_54 ( V_35 , V_28 , V_61 , & V_100 , & V_101 ) ;
V_109 = F_56 ( V_2 , V_28 , V_108 , V_100 , V_101 ) ;
return ( V_109 == V_108 + 1 ?
& V_35 -> V_98 . V_110 [ V_61 ] :
V_35 -> V_98 . V_102 [ V_61 ] . V_111 + V_109 ) ;
}
static struct V_107 * F_57 ( struct V_35 * V_35 ,
const T_1 * V_9 ,
const T_1 * V_12 ,
unsigned short V_28 , int V_61 )
{
unsigned int V_108 = V_35 -> V_98 . V_102 [ V_61 ] . V_108 ;
unsigned int V_109 ;
T_4 V_100 ;
T_4 V_101 ;
F_54 ( V_35 , V_28 , V_61 , & V_100 , & V_101 ) ;
V_109 = F_58 ( V_9 , V_12 , V_28 , V_108 , V_100 , V_101 ) ;
return V_35 -> V_98 . V_102 [ V_61 ] . V_111 + V_109 ;
}
static void F_59 ( struct V_35 * V_35 ,
struct V_107 * V_112 ,
struct V_107 * V_113 ,
unsigned int V_114 ,
int V_61 )
{
struct V_115 * V_116 , * V_117 = NULL ;
struct V_55 * V_82 ;
unsigned int V_118 = 0 ;
T_4 V_100 ;
T_4 V_101 ;
V_119:
F_60 (pol, tmp, list, bydst) {
unsigned int V_120 ;
F_54 ( V_35 , V_82 -> V_28 , V_61 , & V_100 , & V_101 ) ;
V_120 = F_58 ( & V_82 -> V_121 . V_9 , & V_82 -> V_121 . V_12 ,
V_82 -> V_28 , V_114 , V_100 , V_101 ) ;
if ( ! V_117 ) {
F_61 ( & V_82 -> V_87 ) ;
F_62 ( & V_82 -> V_87 , V_113 + V_120 ) ;
V_118 = V_120 ;
} else {
if ( V_120 != V_118 )
continue;
F_61 ( & V_82 -> V_87 ) ;
F_63 ( & V_82 -> V_87 , V_117 ) ;
}
V_117 = & V_82 -> V_87 ;
}
if ( ! F_64 ( V_112 ) ) {
V_117 = NULL ;
goto V_119;
}
}
static void F_65 ( struct V_107 * V_112 ,
struct V_107 * V_122 ,
unsigned int V_114 )
{
struct V_115 * V_116 ;
struct V_55 * V_82 ;
F_60 (pol, tmp, list, byidx) {
unsigned int V_120 ;
V_120 = F_53 ( V_82 -> V_66 , V_114 ) ;
F_62 ( & V_82 -> V_88 , V_122 + V_120 ) ;
}
}
static unsigned long F_66 ( unsigned int V_123 )
{
return ( ( V_123 + 1 ) << 1 ) - 1 ;
}
static void F_67 ( struct V_35 * V_35 , int V_61 )
{
unsigned int V_108 = V_35 -> V_98 . V_102 [ V_61 ] . V_108 ;
unsigned int V_114 = F_66 ( V_108 ) ;
unsigned int V_124 = ( V_114 + 1 ) * sizeof( struct V_107 ) ;
struct V_107 * V_125 = V_35 -> V_98 . V_102 [ V_61 ] . V_111 ;
struct V_107 * V_126 = F_68 ( V_124 ) ;
int V_127 ;
if ( ! V_126 )
return;
F_69 ( & V_35 -> V_98 . V_128 ) ;
for ( V_127 = V_108 ; V_127 >= 0 ; V_127 -- )
F_59 ( V_35 , V_125 + V_127 , V_126 , V_114 , V_61 ) ;
V_35 -> V_98 . V_102 [ V_61 ] . V_111 = V_126 ;
V_35 -> V_98 . V_102 [ V_61 ] . V_108 = V_114 ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
F_71 ( V_125 , ( V_108 + 1 ) * sizeof( struct V_107 ) ) ;
}
static void F_72 ( struct V_35 * V_35 , int V_129 )
{
unsigned int V_108 = V_35 -> V_98 . V_99 ;
unsigned int V_114 = F_66 ( V_108 ) ;
unsigned int V_124 = ( V_114 + 1 ) * sizeof( struct V_107 ) ;
struct V_107 * V_130 = V_35 -> V_98 . V_131 ;
struct V_107 * V_132 = F_68 ( V_124 ) ;
int V_127 ;
if ( ! V_132 )
return;
F_69 ( & V_35 -> V_98 . V_128 ) ;
for ( V_127 = V_108 ; V_127 >= 0 ; V_127 -- )
F_65 ( V_130 + V_127 , V_132 , V_114 ) ;
V_35 -> V_98 . V_131 = V_132 ;
V_35 -> V_98 . V_99 = V_114 ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
F_71 ( V_130 , ( V_108 + 1 ) * sizeof( struct V_107 ) ) ;
}
static inline int F_73 ( struct V_35 * V_35 , int V_61 , int * V_129 )
{
unsigned int V_133 = V_35 -> V_98 . V_134 [ V_61 ] ;
unsigned int V_108 = V_35 -> V_98 . V_102 [ V_61 ] . V_108 ;
if ( V_129 )
* V_129 += V_133 ;
if ( ( V_108 + 1 ) < V_135 &&
V_133 > V_108 )
return 1 ;
return 0 ;
}
static inline int F_74 ( struct V_35 * V_35 , int V_129 )
{
unsigned int V_108 = V_35 -> V_98 . V_99 ;
if ( ( V_108 + 1 ) < V_135 &&
V_129 > V_108 )
return 1 ;
return 0 ;
}
void F_75 ( struct V_35 * V_35 , struct V_136 * V_137 )
{
F_76 ( & V_35 -> V_98 . V_128 ) ;
V_137 -> V_138 = V_35 -> V_98 . V_134 [ V_139 ] ;
V_137 -> V_140 = V_35 -> V_98 . V_134 [ V_141 ] ;
V_137 -> V_142 = V_35 -> V_98 . V_134 [ V_143 ] ;
V_137 -> V_144 = V_35 -> V_98 . V_134 [ V_139 + V_145 ] ;
V_137 -> V_146 = V_35 -> V_98 . V_134 [ V_141 + V_145 ] ;
V_137 -> V_147 = V_35 -> V_98 . V_134 [ V_143 + V_145 ] ;
V_137 -> V_148 = V_35 -> V_98 . V_99 ;
V_137 -> V_149 = V_135 ;
F_77 ( & V_35 -> V_98 . V_128 ) ;
}
static void F_78 ( struct V_150 * V_151 )
{
struct V_35 * V_35 = F_31 ( V_151 , struct V_35 , V_98 . V_152 ) ;
int V_61 , V_129 ;
F_79 ( & V_153 ) ;
V_129 = 0 ;
for ( V_61 = 0 ; V_61 < V_145 ; V_61 ++ ) {
if ( F_73 ( V_35 , V_61 , & V_129 ) )
F_67 ( V_35 , V_61 ) ;
}
if ( F_74 ( V_35 , V_129 ) )
F_72 ( V_35 , V_129 ) ;
F_80 ( & V_153 ) ;
}
static void F_81 ( struct V_150 * V_151 )
{
struct V_35 * V_35 = F_31 ( V_151 , struct V_35 ,
V_98 . V_154 . V_151 ) ;
unsigned int V_108 ;
struct V_55 * V_82 ;
struct V_55 * V_84 ;
struct V_107 * V_155 ;
struct V_107 * V_125 ;
struct V_115 * V_156 ;
int V_127 ;
int V_61 ;
unsigned V_157 ;
T_4 V_158 , V_159 , V_160 , V_161 ;
F_79 ( & V_153 ) ;
do {
V_157 = F_82 ( & V_35 -> V_98 . V_154 . V_62 ) ;
V_158 = V_35 -> V_98 . V_154 . V_158 ;
V_159 = V_35 -> V_98 . V_154 . V_159 ;
V_160 = V_35 -> V_98 . V_154 . V_160 ;
V_161 = V_35 -> V_98 . V_154 . V_161 ;
} while ( F_83 ( & V_35 -> V_98 . V_154 . V_62 , V_157 ) );
F_69 ( & V_35 -> V_98 . V_128 ) ;
for ( V_61 = 0 ; V_61 < V_145 ; V_61 ++ ) {
F_84 ( & V_35 -> V_98 . V_110 [ V_61 ] ) ;
V_108 = V_35 -> V_98 . V_102 [ V_61 ] . V_108 ;
V_125 = V_35 -> V_98 . V_102 [ V_61 ] . V_111 ;
for ( V_127 = V_108 ; V_127 >= 0 ; V_127 -- )
F_84 ( V_125 + V_127 ) ;
if ( ( V_61 & V_162 ) == V_141 ) {
V_35 -> V_98 . V_102 [ V_61 ] . V_103 = V_159 ;
V_35 -> V_98 . V_102 [ V_61 ] . V_104 = V_158 ;
V_35 -> V_98 . V_102 [ V_61 ] . V_105 = V_161 ;
V_35 -> V_98 . V_102 [ V_61 ] . V_106 = V_160 ;
} else {
V_35 -> V_98 . V_102 [ V_61 ] . V_103 = V_158 ;
V_35 -> V_98 . V_102 [ V_61 ] . V_104 = V_159 ;
V_35 -> V_98 . V_102 [ V_61 ] . V_105 = V_160 ;
V_35 -> V_98 . V_102 [ V_61 ] . V_106 = V_161 ;
}
}
F_85 (policy, &net->xfrm.policy_all, walk.all) {
V_156 = NULL ;
V_155 = F_55 ( V_35 , & V_84 -> V_121 ,
V_84 -> V_28 ,
F_23 ( V_84 -> V_66 ) ) ;
F_86 (pol, chain, bydst) {
if ( V_84 -> V_163 >= V_82 -> V_163 )
V_156 = & V_82 -> V_87 ;
else
break;
}
if ( V_156 )
F_63 ( & V_84 -> V_87 , V_156 ) ;
else
F_62 ( & V_84 -> V_87 , V_155 ) ;
}
F_70 ( & V_35 -> V_98 . V_128 ) ;
F_80 ( & V_153 ) ;
}
void F_87 ( struct V_35 * V_35 )
{
F_88 ( & V_35 -> V_98 . V_154 . V_151 ) ;
}
static T_3 F_89 ( struct V_35 * V_35 , int V_61 , T_3 V_66 )
{
static T_3 V_164 ;
for (; ; ) {
struct V_107 * V_112 ;
struct V_55 * V_165 ;
T_3 V_166 ;
int V_167 ;
if ( ! V_66 ) {
V_166 = ( V_164 | V_61 ) ;
V_164 += 8 ;
} else {
V_166 = V_66 ;
V_66 = 0 ;
}
if ( V_166 == 0 )
V_166 = 8 ;
V_112 = V_35 -> V_98 . V_131 + F_52 ( V_35 , V_166 ) ;
V_167 = 0 ;
F_86 (p, list, byidx) {
if ( V_165 -> V_66 == V_166 ) {
V_167 = 1 ;
break;
}
}
if ( ! V_167 )
return V_166 ;
}
}
static inline int F_90 ( struct V_1 * V_168 , struct V_1 * V_169 )
{
T_3 * V_170 = ( T_3 * ) V_168 ;
T_3 * V_171 = ( T_3 * ) V_169 ;
int V_172 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_172 ; V_127 ++ ) {
if ( V_170 [ V_127 ] != V_171 [ V_127 ] )
return 1 ;
}
return 0 ;
}
static void F_91 ( struct V_55 * V_173 ,
struct V_55 * V_174 )
{
struct V_175 * V_176 = & V_173 -> V_90 ;
struct V_177 V_112 ;
if ( F_92 ( & V_176 -> V_91 ) )
return;
F_93 ( & V_112 ) ;
F_94 ( & V_176 -> V_91 . V_62 ) ;
F_95 ( & V_176 -> V_91 , & V_112 ) ;
if ( F_45 ( & V_176 -> V_92 ) )
F_28 ( V_173 ) ;
F_96 ( & V_176 -> V_91 . V_62 ) ;
V_176 = & V_174 -> V_90 ;
F_94 ( & V_176 -> V_91 . V_62 ) ;
F_97 ( & V_112 , & V_176 -> V_91 ) ;
V_176 -> V_178 = V_179 ;
if ( ! F_25 ( & V_176 -> V_92 , V_79 ) )
F_26 ( V_174 ) ;
F_96 ( & V_176 -> V_91 . V_62 ) ;
}
static bool F_98 ( struct V_55 * V_84 ,
struct V_55 * V_82 )
{
T_3 V_180 = V_84 -> V_180 . V_181 & V_84 -> V_180 . V_182 ;
if ( V_84 -> V_180 . V_181 == V_82 -> V_180 . V_181 && V_84 -> V_180 . V_182 == V_82 -> V_180 . V_182 )
return true ;
if ( ( V_180 & V_82 -> V_180 . V_182 ) == V_82 -> V_180 . V_181 &&
V_84 -> V_163 == V_82 -> V_163 )
return true ;
return false ;
}
int F_99 ( int V_61 , struct V_55 * V_84 , int V_183 )
{
struct V_35 * V_35 = V_85 ( V_84 ) ;
struct V_55 * V_82 ;
struct V_55 * V_184 ;
struct V_107 * V_155 ;
struct V_115 * V_156 ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
V_155 = F_55 ( V_35 , & V_84 -> V_121 , V_84 -> V_28 , V_61 ) ;
V_184 = NULL ;
V_156 = NULL ;
F_86 (pol, chain, bydst) {
if ( V_82 -> type == V_84 -> type &&
! F_90 ( & V_82 -> V_121 , & V_84 -> V_121 ) &&
F_98 ( V_84 , V_82 ) &&
F_100 ( V_82 -> V_96 , V_84 -> V_96 ) &&
! F_101 ( V_184 ) ) {
if ( V_183 ) {
F_70 ( & V_35 -> V_98 . V_128 ) ;
return - V_185 ;
}
V_184 = V_82 ;
if ( V_84 -> V_163 > V_82 -> V_163 )
continue;
} else if ( V_84 -> V_163 >= V_82 -> V_163 ) {
V_156 = & V_82 -> V_87 ;
continue;
}
if ( V_184 )
break;
}
if ( V_156 )
F_63 ( & V_84 -> V_87 , V_156 ) ;
else
F_62 ( & V_84 -> V_87 , V_155 ) ;
F_102 ( V_84 , V_61 ) ;
F_50 ( & V_35 -> V_98 . V_186 ) ;
if ( V_84 -> V_28 == V_29 )
F_103 ( V_35 ) ;
else
F_104 ( V_35 ) ;
if ( V_184 ) {
F_91 ( V_184 , V_84 ) ;
F_105 ( V_184 , V_61 ) ;
}
V_84 -> V_66 = V_184 ? V_184 -> V_66 : F_89 ( V_35 , V_61 , V_84 -> V_66 ) ;
F_62 ( & V_84 -> V_88 , V_35 -> V_98 . V_131 + F_52 ( V_35 , V_84 -> V_66 ) ) ;
V_84 -> V_70 . V_71 = F_21 () ;
V_84 -> V_70 . V_74 = 0 ;
if ( ! F_25 ( & V_84 -> V_78 , V_79 + V_53 ) )
F_26 ( V_84 ) ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
if ( V_184 )
F_49 ( V_184 ) ;
else if ( F_73 ( V_35 , V_61 , NULL ) )
F_88 ( & V_35 -> V_98 . V_152 ) ;
return 0 ;
}
struct V_55 * F_106 ( struct V_35 * V_35 , T_3 V_180 , T_4 type ,
int V_61 , struct V_1 * V_2 ,
struct V_187 * V_188 , int V_189 ,
int * V_190 )
{
struct V_55 * V_82 , * V_191 ;
struct V_107 * V_155 ;
* V_190 = 0 ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
V_155 = F_55 ( V_35 , V_2 , V_2 -> V_28 , V_61 ) ;
V_191 = NULL ;
F_86 (pol, chain, bydst) {
if ( V_82 -> type == type &&
( V_180 & V_82 -> V_180 . V_182 ) == V_82 -> V_180 . V_181 &&
! F_90 ( V_2 , & V_82 -> V_121 ) &&
F_100 ( V_188 , V_82 -> V_96 ) ) {
F_26 ( V_82 ) ;
if ( V_189 ) {
* V_190 = F_107 (
V_82 -> V_96 ) ;
if ( * V_190 ) {
F_70 ( & V_35 -> V_98 . V_128 ) ;
return V_82 ;
}
F_105 ( V_82 , V_61 ) ;
}
V_191 = V_82 ;
break;
}
}
F_70 ( & V_35 -> V_98 . V_128 ) ;
if ( V_191 && V_189 )
F_49 ( V_191 ) ;
return V_191 ;
}
struct V_55 * F_108 ( struct V_35 * V_35 , T_3 V_180 , T_4 type ,
int V_61 , T_3 V_46 , int V_189 , int * V_190 )
{
struct V_55 * V_82 , * V_191 ;
struct V_107 * V_155 ;
* V_190 = - V_192 ;
if ( F_23 ( V_46 ) != V_61 )
return NULL ;
* V_190 = 0 ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
V_155 = V_35 -> V_98 . V_131 + F_52 ( V_35 , V_46 ) ;
V_191 = NULL ;
F_86 (pol, chain, byidx) {
if ( V_82 -> type == type && V_82 -> V_66 == V_46 &&
( V_180 & V_82 -> V_180 . V_182 ) == V_82 -> V_180 . V_181 ) {
F_26 ( V_82 ) ;
if ( V_189 ) {
* V_190 = F_107 (
V_82 -> V_96 ) ;
if ( * V_190 ) {
F_70 ( & V_35 -> V_98 . V_128 ) ;
return V_82 ;
}
F_105 ( V_82 , V_61 ) ;
}
V_191 = V_82 ;
break;
}
}
F_70 ( & V_35 -> V_98 . V_128 ) ;
if ( V_191 && V_189 )
F_49 ( V_191 ) ;
return V_191 ;
}
static inline int
F_109 ( struct V_35 * V_35 , T_4 type , bool V_193 )
{
int V_61 , V_190 = 0 ;
for ( V_61 = 0 ; V_61 < V_145 ; V_61 ++ ) {
struct V_55 * V_82 ;
int V_127 ;
F_86 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_82 -> type != type )
continue;
V_190 = F_107 ( V_82 -> V_96 ) ;
if ( V_190 ) {
F_110 ( V_82 , 0 , V_193 ) ;
return V_190 ;
}
}
for ( V_127 = V_35 -> V_98 . V_102 [ V_61 ] . V_108 ; V_127 >= 0 ; V_127 -- ) {
F_86 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_82 -> type != type )
continue;
V_190 = F_107 (
V_82 -> V_96 ) ;
if ( V_190 ) {
F_110 ( V_82 , 0 ,
V_193 ) ;
return V_190 ;
}
}
}
}
return V_190 ;
}
static inline int
F_109 ( struct V_35 * V_35 , T_4 type , bool V_193 )
{
return 0 ;
}
int F_111 ( struct V_35 * V_35 , T_4 type , bool V_193 )
{
int V_61 , V_190 = 0 , V_133 = 0 ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
V_190 = F_109 ( V_35 , type , V_193 ) ;
if ( V_190 )
goto V_65;
for ( V_61 = 0 ; V_61 < V_145 ; V_61 ++ ) {
struct V_55 * V_82 ;
int V_127 ;
V_194:
F_86 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_82 -> type != type )
continue;
F_105 ( V_82 , V_61 ) ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
V_133 ++ ;
F_110 ( V_82 , 1 , V_193 ) ;
F_49 ( V_82 ) ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
goto V_194;
}
for ( V_127 = V_35 -> V_98 . V_102 [ V_61 ] . V_108 ; V_127 >= 0 ; V_127 -- ) {
V_195:
F_86 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_82 -> type != type )
continue;
F_105 ( V_82 , V_61 ) ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
V_133 ++ ;
F_110 ( V_82 , 1 , V_193 ) ;
F_49 ( V_82 ) ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
goto V_195;
}
}
}
if ( ! V_133 )
V_190 = - V_196 ;
V_65:
F_70 ( & V_35 -> V_98 . V_128 ) ;
return V_190 ;
}
int F_112 ( struct V_35 * V_35 , struct F_112 * V_63 ,
int (* F_113)( struct V_55 * , int , int , void * ) ,
void * V_54 )
{
struct V_55 * V_82 ;
struct V_197 * V_42 ;
int error = 0 ;
if ( V_63 -> type >= V_198 &&
V_63 -> type != V_199 )
return - V_200 ;
if ( F_114 ( & V_63 -> V_63 . V_86 ) && V_63 -> V_157 != 0 )
return 0 ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
if ( F_114 ( & V_63 -> V_63 . V_86 ) )
V_42 = F_115 ( & V_35 -> V_98 . V_201 , struct V_197 , V_86 ) ;
else
V_42 = F_115 ( & V_63 -> V_63 . V_86 ,
struct V_197 , V_86 ) ;
F_116 (x, &net->xfrm.policy_all, all) {
if ( V_42 -> V_64 )
continue;
V_82 = F_31 ( V_42 , struct V_55 , V_63 ) ;
if ( V_63 -> type != V_199 &&
V_63 -> type != V_82 -> type )
continue;
error = F_113 ( V_82 , F_23 ( V_82 -> V_66 ) ,
V_63 -> V_157 , V_54 ) ;
if ( error ) {
F_117 ( & V_63 -> V_63 . V_86 , & V_42 -> V_86 ) ;
goto V_65;
}
V_63 -> V_157 ++ ;
}
if ( V_63 -> V_157 == 0 ) {
error = - V_192 ;
goto V_65;
}
F_118 ( & V_63 -> V_63 . V_86 ) ;
V_65:
F_70 ( & V_35 -> V_98 . V_128 ) ;
return error ;
}
void F_119 ( struct F_112 * V_63 , T_4 type )
{
F_37 ( & V_63 -> V_63 . V_86 ) ;
V_63 -> V_63 . V_64 = 1 ;
V_63 -> type = type ;
V_63 -> V_157 = 0 ;
}
void F_120 ( struct F_112 * V_63 , struct V_35 * V_35 )
{
if ( F_114 ( & V_63 -> V_63 . V_86 ) )
return;
F_69 ( & V_35 -> V_98 . V_128 ) ;
F_121 ( & V_63 -> V_63 . V_86 ) ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
}
static int F_122 ( const struct V_55 * V_82 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_28 , int V_61 )
{
const struct V_1 * V_2 = & V_82 -> V_121 ;
int V_191 = - V_196 ;
bool V_202 ;
if ( V_82 -> V_28 != V_28 ||
( V_4 -> V_203 & V_82 -> V_180 . V_182 ) != V_82 -> V_180 . V_181 ||
V_82 -> type != type )
return V_191 ;
V_202 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_202 )
V_191 = F_123 ( V_82 -> V_96 , V_4 -> V_204 ,
V_61 ) ;
return V_191 ;
}
static struct V_55 * F_124 ( struct V_35 * V_35 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_28 , T_4 V_61 )
{
int V_190 ;
struct V_55 * V_82 , * V_191 ;
const T_1 * V_9 , * V_12 ;
struct V_107 * V_155 ;
T_3 V_163 = ~ 0U ;
V_9 = F_125 ( V_4 , V_28 ) ;
V_12 = F_126 ( V_4 , V_28 ) ;
if ( F_9 ( ! V_9 || ! V_12 ) )
return NULL ;
F_76 ( & V_35 -> V_98 . V_128 ) ;
V_155 = F_57 ( V_35 , V_9 , V_12 , V_28 , V_61 ) ;
V_191 = NULL ;
F_86 (pol, chain, bydst) {
V_190 = F_122 ( V_82 , V_4 , type , V_28 , V_61 ) ;
if ( V_190 ) {
if ( V_190 == - V_196 )
continue;
else {
V_191 = F_15 ( V_190 ) ;
goto V_205;
}
} else {
V_191 = V_82 ;
V_163 = V_191 -> V_163 ;
break;
}
}
V_155 = & V_35 -> V_98 . V_110 [ V_61 ] ;
F_86 (pol, chain, bydst) {
if ( ( V_82 -> V_163 >= V_163 ) && V_191 )
break;
V_190 = F_122 ( V_82 , V_4 , type , V_28 , V_61 ) ;
if ( V_190 ) {
if ( V_190 == - V_196 )
continue;
else {
V_191 = F_15 ( V_190 ) ;
goto V_205;
}
} else {
V_191 = V_82 ;
break;
}
}
F_26 ( V_191 ) ;
V_205:
F_77 ( & V_35 -> V_98 . V_128 ) ;
return V_191 ;
}
static struct V_55 *
F_127 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_61 )
{
#ifdef F_128
struct V_55 * V_82 ;
V_82 = F_124 ( V_35 , V_206 , V_4 , V_28 , V_61 ) ;
if ( V_82 != NULL )
return V_82 ;
#endif
return F_124 ( V_35 , V_207 , V_4 , V_28 , V_61 ) ;
}
static int F_129 ( int V_61 )
{
if ( V_139 == V_208 &&
V_141 == V_209 &&
V_143 == V_210 )
return V_61 ;
switch ( V_61 ) {
default:
case V_208 :
return V_139 ;
case V_209 :
return V_141 ;
case V_210 :
return V_143 ;
}
}
static struct V_80 *
F_130 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_61 , struct V_80 * V_211 , void * V_188 )
{
struct V_55 * V_82 ;
if ( V_211 )
F_28 ( F_31 ( V_211 , struct V_55 , V_81 ) ) ;
V_82 = F_127 ( V_35 , V_4 , V_28 , F_129 ( V_61 ) ) ;
if ( F_131 ( V_82 ) )
return F_132 ( V_82 ) ;
F_26 ( V_82 ) ;
return & V_82 -> V_81 ;
}
static inline int F_133 ( int V_61 )
{
if ( V_139 == V_208 &&
V_141 == V_209 &&
V_143 == V_210 )
return V_61 ;
switch ( V_61 ) {
default:
case V_139 :
return V_208 ;
case V_141 :
return V_209 ;
case V_143 :
return V_210 ;
}
}
static struct V_55 * F_134 ( struct V_212 * V_213 , int V_61 ,
const struct V_3 * V_4 )
{
struct V_55 * V_82 ;
struct V_35 * V_35 = F_135 ( V_213 ) ;
F_76 ( & V_35 -> V_98 . V_128 ) ;
if ( ( V_82 = V_213 -> V_214 [ V_61 ] ) != NULL ) {
bool V_202 = F_7 ( & V_82 -> V_121 , V_4 ,
V_213 -> V_215 ) ;
int V_190 = 0 ;
if ( V_202 ) {
if ( ( V_213 -> V_216 & V_82 -> V_180 . V_182 ) != V_82 -> V_180 . V_181 ) {
V_82 = NULL ;
goto V_65;
}
V_190 = F_123 ( V_82 -> V_96 ,
V_4 -> V_204 ,
F_133 ( V_61 ) ) ;
if ( ! V_190 )
F_26 ( V_82 ) ;
else if ( V_190 == - V_196 )
V_82 = NULL ;
else
V_82 = F_15 ( V_190 ) ;
} else
V_82 = NULL ;
}
V_65:
F_77 ( & V_35 -> V_98 . V_128 ) ;
return V_82 ;
}
static void F_102 ( struct V_55 * V_82 , int V_61 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
F_136 ( & V_82 -> V_63 . V_86 , & V_35 -> V_98 . V_201 ) ;
V_35 -> V_98 . V_134 [ V_61 ] ++ ;
F_26 ( V_82 ) ;
}
static struct V_55 * F_105 ( struct V_55 * V_82 ,
int V_61 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
if ( F_114 ( & V_82 -> V_63 . V_86 ) )
return NULL ;
if ( ! F_137 ( & V_82 -> V_87 ) ) {
F_61 ( & V_82 -> V_87 ) ;
F_61 ( & V_82 -> V_88 ) ;
}
F_118 ( & V_82 -> V_63 . V_86 ) ;
V_35 -> V_98 . V_134 [ V_61 ] -- ;
return V_82 ;
}
static void F_138 ( struct V_55 * V_82 , int V_61 )
{
F_102 ( V_82 , V_145 + V_61 ) ;
}
static void F_139 ( struct V_55 * V_82 , int V_61 )
{
F_105 ( V_82 , V_145 + V_61 ) ;
}
int F_29 ( struct V_55 * V_82 , int V_61 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
V_82 = F_105 ( V_82 , V_61 ) ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
if ( V_82 ) {
F_49 ( V_82 ) ;
return 0 ;
}
return - V_192 ;
}
int F_140 ( struct V_212 * V_213 , int V_61 , struct V_55 * V_82 )
{
struct V_35 * V_35 = V_85 ( V_82 ) ;
struct V_55 * V_217 ;
#ifdef F_128
if ( V_82 && V_82 -> type != V_207 )
return - V_200 ;
#endif
F_69 ( & V_35 -> V_98 . V_128 ) ;
V_217 = V_213 -> V_214 [ V_61 ] ;
V_213 -> V_214 [ V_61 ] = V_82 ;
if ( V_82 ) {
V_82 -> V_70 . V_71 = F_21 () ;
V_82 -> V_66 = F_89 ( V_35 , V_145 + V_61 , 0 ) ;
F_138 ( V_82 , V_61 ) ;
}
if ( V_217 ) {
if ( V_82 )
F_91 ( V_217 , V_82 ) ;
F_139 ( V_217 , V_61 ) ;
}
F_70 ( & V_35 -> V_98 . V_128 ) ;
if ( V_217 ) {
F_49 ( V_217 ) ;
}
return 0 ;
}
static struct V_55 * F_141 ( const struct V_55 * V_173 , int V_61 )
{
struct V_55 * V_218 = F_34 ( V_85 ( V_173 ) , V_219 ) ;
struct V_35 * V_35 = V_85 ( V_173 ) ;
if ( V_218 ) {
V_218 -> V_121 = V_173 -> V_121 ;
if ( F_142 ( V_173 -> V_96 ,
& V_218 -> V_96 ) ) {
F_48 ( V_218 ) ;
return NULL ;
}
V_218 -> V_67 = V_173 -> V_67 ;
V_218 -> V_70 = V_173 -> V_70 ;
V_218 -> V_180 = V_173 -> V_180 ;
V_218 -> V_220 = V_173 -> V_220 ;
V_218 -> V_47 = V_173 -> V_47 ;
V_218 -> V_221 = V_173 -> V_221 ;
V_218 -> V_66 = V_173 -> V_66 ;
V_218 -> type = V_173 -> type ;
memcpy ( V_218 -> V_222 , V_173 -> V_222 ,
V_218 -> V_221 * sizeof( struct V_223 ) ) ;
F_69 ( & V_35 -> V_98 . V_128 ) ;
F_138 ( V_218 , V_61 ) ;
F_70 ( & V_35 -> V_98 . V_128 ) ;
F_28 ( V_218 ) ;
}
return V_218 ;
}
int F_143 ( struct V_212 * V_213 )
{
struct V_55 * V_224 = V_213 -> V_214 [ 0 ] ,
* V_170 = V_213 -> V_214 [ 1 ] ;
V_213 -> V_214 [ 0 ] = V_213 -> V_214 [ 1 ] = NULL ;
if ( V_224 && ( V_213 -> V_214 [ 0 ] = F_141 ( V_224 , 0 ) ) == NULL )
return - V_225 ;
if ( V_170 && ( V_213 -> V_214 [ 1 ] = F_141 ( V_170 , 1 ) ) == NULL )
return - V_225 ;
return 0 ;
}
static int
F_144 ( struct V_35 * V_35 , int V_37 , T_1 * V_226 ,
T_1 * V_227 , unsigned short V_28 )
{
int V_190 ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return - V_200 ;
V_190 = V_32 -> V_228 ( V_35 , V_37 , V_226 , V_227 ) ;
F_13 ( V_32 ) ;
return V_190 ;
}
static int
F_145 ( struct V_55 * V_84 , const struct V_3 * V_4 ,
struct V_41 * * V_98 , unsigned short V_28 )
{
struct V_35 * V_35 = V_85 ( V_84 ) ;
int V_229 ;
int V_127 , error ;
T_1 * V_9 = F_125 ( V_4 , V_28 ) ;
T_1 * V_12 = F_126 ( V_4 , V_28 ) ;
T_1 V_116 ;
for ( V_229 = 0 , V_127 = 0 ; V_127 < V_84 -> V_221 ; V_127 ++ ) {
struct V_41 * V_42 ;
T_1 * V_227 = V_9 ;
T_1 * V_226 = V_12 ;
struct V_223 * V_230 = & V_84 -> V_222 [ V_127 ] ;
if ( V_230 -> V_231 == V_232 ||
V_230 -> V_231 == V_233 ) {
V_227 = & V_230 -> V_46 . V_9 ;
V_226 = & V_230 -> V_12 ;
if ( F_146 ( V_226 , V_230 -> V_234 ) ) {
error = F_144 ( V_35 , V_4 -> V_235 ,
& V_116 , V_227 ,
V_230 -> V_234 ) ;
if ( error )
goto V_205;
V_226 = & V_116 ;
}
}
V_42 = F_147 ( V_227 , V_226 , V_4 , V_230 , V_84 , & error , V_28 ) ;
if ( V_42 && V_42 -> V_236 . V_237 == V_238 ) {
V_98 [ V_229 ++ ] = V_42 ;
V_9 = V_227 ;
V_12 = V_226 ;
continue;
}
if ( V_42 ) {
error = ( V_42 -> V_236 . V_237 == V_239 ?
- V_200 : - V_240 ) ;
F_148 ( V_42 ) ;
} else if ( error == - V_196 ) {
error = - V_240 ;
}
if ( ! V_230 -> V_241 )
goto V_205;
}
return V_229 ;
V_205:
for ( V_229 -- ; V_229 >= 0 ; V_229 -- )
F_148 ( V_98 [ V_229 ] ) ;
return error ;
}
static int
F_149 ( struct V_55 * * V_242 , int V_243 , const struct V_3 * V_4 ,
struct V_41 * * V_98 , unsigned short V_28 )
{
struct V_41 * V_244 [ V_245 ] ;
struct V_41 * * V_246 = ( V_243 > 1 ) ? V_244 : V_98 ;
int V_247 = 0 ;
int error ;
int V_191 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_243 ; V_127 ++ ) {
if ( V_247 + V_242 [ V_127 ] -> V_221 >= V_245 ) {
error = - V_248 ;
goto V_205;
}
V_191 = F_145 ( V_242 [ V_127 ] , V_4 , & V_246 [ V_247 ] , V_28 ) ;
if ( V_191 < 0 ) {
error = V_191 ;
goto V_205;
} else
V_247 += V_191 ;
}
if ( V_243 > 1 )
F_150 ( V_98 , V_246 , V_247 , V_28 ) ;
return V_247 ;
V_205:
for ( V_247 -- ; V_247 >= 0 ; V_247 -- )
F_148 ( V_246 [ V_247 ] ) ;
return error ;
}
static inline int F_151 ( const struct V_3 * V_4 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_36 ;
if ( ! V_32 )
return - V_200 ;
V_36 = V_32 -> V_249 ( V_4 ) ;
F_13 ( V_32 ) ;
return V_36 ;
}
static struct V_80 * F_152 ( struct V_80 * V_81 )
{
struct V_250 * V_251 = F_31 ( V_81 , struct V_250 , V_81 ) ;
struct V_34 * V_38 = & V_251 -> V_7 . V_38 ;
if ( V_251 -> V_252 == NULL ) {
if ( V_251 -> V_253 > 0 )
return NULL ;
} else if ( V_38 -> V_47 & V_254 ) {
return NULL ;
} else {
if ( F_153 ( V_38 ) )
return NULL ;
}
F_154 ( V_38 ) ;
return V_81 ;
}
static int F_155 ( struct V_80 * V_81 )
{
struct V_250 * V_251 = F_31 ( V_81 , struct V_250 , V_81 ) ;
struct V_34 * V_38 = & V_251 -> V_7 . V_38 ;
if ( ! V_251 -> V_252 )
return 0 ;
if ( F_153 ( V_38 ) )
return 0 ;
return 1 ;
}
static void F_156 ( struct V_80 * V_81 )
{
struct V_250 * V_251 = F_31 ( V_81 , struct V_250 , V_81 ) ;
struct V_34 * V_38 = & V_251 -> V_7 . V_38 ;
F_157 ( V_38 ) ;
}
static inline struct V_250 * F_158 ( struct V_35 * V_35 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_255 * V_255 ;
struct V_250 * V_251 ;
if ( ! V_32 )
return F_15 ( - V_200 ) ;
switch ( V_28 ) {
case V_29 :
V_255 = & V_35 -> V_98 . V_256 ;
break;
#if F_159 ( V_257 )
case V_30 :
V_255 = & V_35 -> V_98 . V_258 ;
break;
#endif
default:
F_46 () ;
}
V_251 = F_160 ( V_255 , NULL , 0 , V_259 , 0 ) ;
if ( F_161 ( V_251 ) ) {
struct V_34 * V_38 = & V_251 -> V_7 . V_38 ;
memset ( V_38 + 1 , 0 , sizeof( * V_251 ) - sizeof( * V_38 ) ) ;
V_251 -> V_81 . V_94 = & V_260 ;
if ( V_32 -> V_261 )
V_32 -> V_261 ( V_35 , V_251 ) ;
} else
V_251 = F_15 ( - V_248 ) ;
F_13 ( V_32 ) ;
return V_251 ;
}
static inline int F_162 ( struct V_250 * V_262 , struct V_34 * V_38 ,
int V_263 )
{
struct V_31 * V_32 =
F_8 ( V_38 -> V_94 -> V_28 ) ;
int V_190 ;
if ( ! V_32 )
return - V_200 ;
V_190 = V_32 -> V_264 ( V_262 , V_38 , V_263 ) ;
F_13 ( V_32 ) ;
return V_190 ;
}
static inline int F_163 ( struct V_250 * V_251 , struct V_265 * V_266 ,
const struct V_3 * V_4 )
{
struct V_31 * V_32 =
F_8 ( V_251 -> V_7 . V_38 . V_94 -> V_28 ) ;
int V_190 ;
if ( ! V_32 )
return - V_200 ;
V_190 = V_32 -> V_267 ( V_251 , V_266 , V_4 ) ;
F_13 ( V_32 ) ;
return V_190 ;
}
static struct V_34 * F_164 ( struct V_55 * V_84 ,
struct V_41 * * V_98 , int V_229 ,
const struct V_3 * V_4 ,
struct V_34 * V_38 )
{
struct V_35 * V_35 = V_85 ( V_84 ) ;
unsigned long V_57 = V_79 ;
struct V_265 * V_266 ;
struct V_268 * V_269 ;
struct V_34 * V_270 = NULL ;
struct V_34 * V_271 = NULL ;
int V_127 = 0 ;
int V_190 ;
int V_272 = 0 ;
int V_263 = 0 ;
int V_273 = 0 ;
int V_36 ;
int V_28 = V_84 -> V_121 . V_28 ;
T_1 V_12 , V_9 ;
F_165 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_36 = F_151 ( V_4 , V_28 ) ;
V_190 = V_36 ;
if ( V_36 < 0 )
goto V_274;
F_154 ( V_38 ) ;
for (; V_127 < V_229 ; V_127 ++ ) {
struct V_250 * V_251 = F_158 ( V_35 , V_28 ) ;
struct V_34 * V_275 = & V_251 -> V_7 . V_38 ;
V_190 = F_166 ( V_251 ) ;
if ( F_18 ( V_251 ) ) {
F_167 ( V_38 ) ;
goto V_274;
}
if ( V_98 [ V_127 ] -> V_2 . V_28 == V_276 ) {
V_269 = F_168 ( V_98 [ V_127 ] ,
F_169 ( V_28 ) ) ;
if ( ! V_269 ) {
V_190 = - V_39 ;
F_167 ( V_38 ) ;
goto V_274;
}
} else
V_269 = V_98 [ V_127 ] -> V_269 ;
if ( ! V_270 )
V_271 = V_275 ;
else {
V_270 -> V_277 = F_170 ( V_275 ) ;
V_275 -> V_47 |= V_278 ;
}
V_251 -> V_252 = V_38 ;
F_171 ( V_275 , V_38 ) ;
if ( V_98 [ V_127 ] -> V_45 . V_231 != V_279 ) {
V_28 = V_98 [ V_127 ] -> V_45 . V_28 ;
V_38 = F_16 ( V_98 [ V_127 ] , V_36 , V_4 -> V_235 ,
& V_12 , & V_9 , V_28 ) ;
V_190 = F_166 ( V_38 ) ;
if ( F_18 ( V_38 ) )
goto V_274;
} else
F_154 ( V_38 ) ;
V_275 -> V_98 = V_98 [ V_127 ] ;
V_251 -> V_280 = V_98 [ V_127 ] -> V_97 ;
V_275 -> V_281 = V_282 ;
V_275 -> V_47 |= V_283 ;
V_275 -> V_284 = V_57 ;
V_275 -> V_285 = V_286 ;
V_275 -> V_287 = V_269 -> V_32 -> V_287 ;
V_275 -> V_58 = V_270 ;
V_270 = V_275 ;
V_272 += V_98 [ V_127 ] -> V_45 . V_272 ;
if ( V_98 [ V_127 ] -> type -> V_47 & V_288 )
V_263 += V_98 [ V_127 ] -> V_45 . V_272 ;
V_273 += V_98 [ V_127 ] -> V_45 . V_273 ;
}
V_270 -> V_277 = V_38 ;
V_271 -> V_262 = V_38 ;
V_190 = - V_289 ;
V_266 = V_38 -> V_266 ;
if ( ! V_266 )
goto V_290;
F_162 ( (struct V_250 * ) V_271 , V_38 , V_263 ) ;
F_172 ( V_270 ) ;
for ( V_270 = V_271 ; V_270 != V_38 ; V_270 = V_270 -> V_277 ) {
struct V_250 * V_251 = (struct V_250 * ) V_270 ;
V_190 = F_163 ( V_251 , V_266 , V_4 ) ;
if ( V_190 )
goto V_290;
V_270 -> V_272 = V_272 ;
V_270 -> V_273 = V_273 ;
V_272 -= V_251 -> V_7 . V_38 . V_98 -> V_45 . V_272 ;
V_273 -= V_251 -> V_7 . V_38 . V_98 -> V_45 . V_273 ;
}
V_65:
return V_271 ;
V_274:
for (; V_127 < V_229 ; V_127 ++ )
F_148 ( V_98 [ V_127 ] ) ;
V_290:
if ( V_271 )
F_157 ( V_271 ) ;
V_271 = F_15 ( V_190 ) ;
goto V_65;
}
static int F_173 ( void * * V_291 , const void * V_292 , int V_293 )
{
if ( ! * V_291 ) {
* V_291 = F_174 ( V_293 , V_219 ) ;
if ( ! * V_291 )
return - V_225 ;
}
memcpy ( * V_291 , V_292 , V_293 ) ;
return 0 ;
}
static int F_175 ( struct V_34 * V_38 ,
const struct V_1 * V_2 )
{
#ifdef F_128
struct V_250 * V_251 = (struct V_250 * ) V_38 ;
return F_173 ( ( void * * ) & ( V_251 -> V_294 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int F_176 ( struct V_34 * V_38 ,
const struct V_3 * V_4 )
{
#ifdef F_128
struct V_250 * V_251 = (struct V_250 * ) V_38 ;
return F_173 ( ( void * * ) & ( V_251 -> V_295 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_177 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_55 * * V_242 ,
int * V_296 , int * V_253 )
{
int V_127 ;
if ( * V_296 == 0 || ! V_242 [ 0 ] ) {
* V_296 = 0 ;
* V_253 = 0 ;
return 0 ;
}
if ( F_18 ( V_242 [ 0 ] ) )
return F_166 ( V_242 [ 0 ] ) ;
* V_253 = V_242 [ 0 ] -> V_221 ;
#ifdef F_128
if ( V_242 [ 0 ] && V_242 [ 0 ] -> V_220 == V_297 &&
V_242 [ 0 ] -> type != V_207 ) {
V_242 [ 1 ] = F_124 ( V_85 ( V_242 [ 0 ] ) ,
V_207 ,
V_4 , V_28 ,
V_141 ) ;
if ( V_242 [ 1 ] ) {
if ( F_18 ( V_242 [ 1 ] ) ) {
F_178 ( V_242 , * V_296 ) ;
return F_166 ( V_242 [ 1 ] ) ;
}
( * V_296 ) ++ ;
( * V_253 ) += V_242 [ 1 ] -> V_221 ;
}
}
#endif
for ( V_127 = 0 ; V_127 < * V_296 ; V_127 ++ ) {
if ( V_242 [ V_127 ] -> V_220 != V_297 ) {
* V_253 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_250 *
F_179 ( struct V_55 * * V_242 , int V_296 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_34 * V_298 )
{
struct V_35 * V_35 = V_85 ( V_242 [ 0 ] ) ;
struct V_41 * V_98 [ V_245 ] ;
struct V_34 * V_38 ;
struct V_250 * V_251 ;
int V_190 ;
V_190 = F_149 ( V_242 , V_296 , V_4 , V_98 , V_28 ) ;
if ( V_190 <= 0 ) {
if ( V_190 != 0 && V_190 != - V_240 )
F_180 ( V_35 , V_299 ) ;
return F_15 ( V_190 ) ;
}
V_38 = F_164 ( V_242 [ 0 ] , V_98 , V_190 , V_4 , V_298 ) ;
if ( F_18 ( V_38 ) ) {
F_180 ( V_35 , V_300 ) ;
return F_132 ( V_38 ) ;
}
V_251 = (struct V_250 * ) V_38 ;
V_251 -> V_253 = V_190 ;
if ( V_296 > 1 )
V_190 = F_175 ( V_38 , & V_242 [ 1 ] -> V_121 ) ;
else
V_190 = F_176 ( V_38 , V_4 ) ;
if ( F_9 ( V_190 ) ) {
F_157 ( V_38 ) ;
F_180 ( V_35 , V_301 ) ;
return F_15 ( V_190 ) ;
}
V_251 -> V_296 = V_296 ;
memcpy ( V_251 -> V_242 , V_242 , sizeof( struct V_55 * ) * V_296 ) ;
V_251 -> V_302 = F_181 ( & V_242 [ 0 ] -> V_97 ) ;
return V_251 ;
}
static void V_93 ( unsigned long V_303 )
{
struct V_304 * V_305 ;
struct V_212 * V_213 ;
struct V_34 * V_38 ;
struct V_55 * V_82 = (struct V_55 * ) V_303 ;
struct V_175 * V_176 = & V_82 -> V_90 ;
struct V_3 V_4 ;
struct V_177 V_112 ;
F_182 ( & V_176 -> V_91 . V_62 ) ;
V_305 = F_183 ( & V_176 -> V_91 ) ;
if ( ! V_305 ) {
F_184 ( & V_176 -> V_91 . V_62 ) ;
goto V_65;
}
V_38 = F_185 ( V_305 ) ;
V_213 = V_305 -> V_213 ;
F_186 ( V_305 , & V_4 , V_38 -> V_94 -> V_28 ) ;
F_184 ( & V_176 -> V_91 . V_62 ) ;
F_154 ( V_38 -> V_262 ) ;
V_38 = F_187 ( V_85 ( V_82 ) , V_38 -> V_262 , & V_4 ,
V_213 , 0 ) ;
if ( F_18 ( V_38 ) )
goto V_306;
if ( V_38 -> V_47 & V_254 ) {
F_167 ( V_38 ) ;
if ( V_176 -> V_178 >= V_307 )
goto V_306;
V_176 -> V_178 = V_176 -> V_178 << 1 ;
if ( ! F_25 ( & V_176 -> V_92 , V_79 + V_176 -> V_178 ) )
F_26 ( V_82 ) ;
goto V_65;
}
F_167 ( V_38 ) ;
F_93 ( & V_112 ) ;
F_182 ( & V_176 -> V_91 . V_62 ) ;
V_176 -> V_178 = 0 ;
F_95 ( & V_176 -> V_91 , & V_112 ) ;
F_184 ( & V_176 -> V_91 . V_62 ) ;
while ( ! F_92 ( & V_112 ) ) {
V_305 = F_188 ( & V_112 ) ;
F_186 ( V_305 , & V_4 , F_185 ( V_305 ) -> V_94 -> V_28 ) ;
F_154 ( F_185 ( V_305 ) -> V_262 ) ;
V_38 = F_187 ( V_85 ( V_82 ) , F_185 ( V_305 ) -> V_262 ,
& V_4 , V_305 -> V_213 , 0 ) ;
if ( F_18 ( V_38 ) ) {
F_189 ( V_305 ) ;
continue;
}
F_190 ( V_305 ) ;
F_191 ( V_305 ) ;
F_192 ( V_305 , V_38 ) ;
F_193 ( V_305 ) ;
}
V_65:
F_28 ( V_82 ) ;
return;
V_306:
V_176 -> V_178 = 0 ;
F_51 ( & V_176 -> V_91 ) ;
F_28 ( V_82 ) ;
}
static int F_194 ( struct V_212 * V_213 , struct V_304 * V_305 )
{
unsigned long V_308 ;
struct V_34 * V_38 = F_185 ( V_305 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_38 ;
struct V_55 * V_82 = V_251 -> V_242 [ 0 ] ;
struct V_175 * V_176 = & V_82 -> V_90 ;
if ( F_9 ( F_195 ( V_213 , V_305 ) ) ) {
F_189 ( V_305 ) ;
return 0 ;
}
if ( V_176 -> V_91 . V_309 > V_310 ) {
F_189 ( V_305 ) ;
return - V_240 ;
}
F_196 ( V_305 ) ;
F_94 ( & V_176 -> V_91 . V_62 ) ;
if ( ! V_176 -> V_178 )
V_176 -> V_178 = V_179 ;
V_308 = V_79 + V_176 -> V_178 ;
if ( F_45 ( & V_176 -> V_92 ) ) {
if ( F_197 ( V_176 -> V_92 . V_311 , V_308 ) )
V_308 = V_176 -> V_92 . V_311 ;
F_28 ( V_82 ) ;
}
F_198 ( & V_176 -> V_91 , V_305 ) ;
if ( ! F_25 ( & V_176 -> V_92 , V_308 ) )
F_26 ( V_82 ) ;
F_96 ( & V_176 -> V_91 . V_62 ) ;
return 0 ;
}
static struct V_250 * F_199 ( struct V_35 * V_35 ,
struct V_312 * V_313 ,
const struct V_3 * V_4 ,
int V_253 ,
T_5 V_28 )
{
int V_190 ;
struct V_265 * V_266 ;
struct V_34 * V_38 ;
struct V_34 * V_275 ;
struct V_250 * V_251 ;
V_251 = F_158 ( V_35 , V_28 ) ;
if ( F_18 ( V_251 ) )
return V_251 ;
if ( ! ( V_313 -> V_47 & V_314 ) ||
V_35 -> V_98 . V_315 ||
V_253 <= 0 )
return V_251 ;
V_38 = V_313 -> V_298 ;
V_275 = & V_251 -> V_7 . V_38 ;
F_154 ( V_38 ) ;
V_251 -> V_252 = V_38 ;
F_171 ( V_275 , V_38 ) ;
V_275 -> V_281 = V_282 ;
V_275 -> V_47 |= V_283 | V_254 ;
V_275 -> V_284 = V_79 ;
V_275 -> V_285 = V_286 ;
V_275 -> V_287 = F_194 ;
F_154 ( V_38 ) ;
V_275 -> V_277 = V_38 ;
V_275 -> V_262 = V_38 ;
F_162 ( (struct V_250 * ) V_275 , V_38 , 0 ) ;
V_190 = - V_289 ;
V_266 = V_38 -> V_266 ;
if ( ! V_266 )
goto V_290;
V_190 = F_163 ( V_251 , V_266 , V_4 ) ;
if ( V_190 )
goto V_290;
V_65:
return V_251 ;
V_290:
F_167 ( V_275 ) ;
V_251 = F_15 ( V_190 ) ;
goto V_65;
}
static struct V_80 *
F_200 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_61 ,
struct V_80 * V_316 , void * V_188 )
{
struct V_312 * V_313 = (struct V_312 * ) V_188 ;
struct V_55 * V_242 [ V_198 ] ;
struct V_250 * V_251 , * V_317 ;
int V_296 = 0 , V_253 = 0 , V_127 , V_190 , V_318 ;
V_251 = NULL ;
if ( V_316 ) {
V_251 = F_31 ( V_316 , struct V_250 , V_81 ) ;
V_296 = V_251 -> V_296 ;
V_253 = V_251 -> V_253 ;
V_318 = 0 ;
for ( V_127 = 0 ; V_127 < V_296 ; V_127 ++ ) {
V_242 [ V_127 ] = V_251 -> V_242 [ V_127 ] ;
V_318 |= V_242 [ V_127 ] -> V_63 . V_64 ;
}
if ( V_318 ) {
F_157 ( & V_251 -> V_7 . V_38 ) ;
V_251 = NULL ;
V_296 = 0 ;
V_253 = 0 ;
V_316 = NULL ;
}
}
if ( V_251 == NULL ) {
V_296 = 1 ;
V_242 [ 0 ] = F_127 ( V_35 , V_4 , V_28 ,
F_129 ( V_61 ) ) ;
V_190 = F_177 ( V_4 , V_28 , V_242 ,
& V_296 , & V_253 ) ;
if ( V_190 < 0 )
goto V_319;
if ( V_296 == 0 )
return NULL ;
if ( V_253 <= 0 )
goto V_320;
}
V_317 = F_179 ( V_242 , V_296 , V_4 , V_28 ,
V_313 -> V_298 ) ;
if ( F_18 ( V_317 ) ) {
V_190 = F_166 ( V_317 ) ;
if ( V_190 != - V_240 )
goto error;
if ( V_316 == NULL )
goto V_320;
F_154 ( & V_251 -> V_7 . V_38 ) ;
return V_316 ;
} else if ( V_317 == NULL ) {
V_253 = 0 ;
if ( V_316 == NULL )
goto V_320;
V_251 -> V_253 = 0 ;
F_154 ( & V_251 -> V_7 . V_38 ) ;
return V_316 ;
}
if ( V_251 ) {
V_251 -> V_296 = 0 ;
F_157 ( & V_251 -> V_7 . V_38 ) ;
}
F_154 ( & V_317 -> V_7 . V_38 ) ;
return & V_317 -> V_81 ;
V_320:
V_251 = F_199 ( V_35 , V_313 , V_4 , V_253 , V_28 ) ;
if ( F_18 ( V_251 ) ) {
F_178 ( V_242 , V_296 ) ;
return F_132 ( V_251 ) ;
}
V_251 -> V_296 = V_296 ;
V_251 -> V_253 = V_253 ;
memcpy ( V_251 -> V_242 , V_242 , sizeof( struct V_55 * ) * V_296 ) ;
F_154 ( & V_251 -> V_7 . V_38 ) ;
return & V_251 -> V_81 ;
V_319:
F_180 ( V_35 , V_299 ) ;
error:
if ( V_251 != NULL )
F_157 ( & V_251 -> V_7 . V_38 ) ;
else
F_178 ( V_242 , V_296 ) ;
return F_15 ( V_190 ) ;
}
static struct V_34 * F_201 ( struct V_35 * V_35 , T_5 V_28 ,
struct V_34 * V_298 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_34 * V_191 ;
if ( ! V_32 ) {
F_167 ( V_298 ) ;
return F_15 ( - V_200 ) ;
} else {
V_191 = V_32 -> V_321 ( V_35 , V_298 ) ;
}
F_13 ( V_32 ) ;
return V_191 ;
}
struct V_34 * F_187 ( struct V_35 * V_35 , struct V_34 * V_298 ,
const struct V_3 * V_4 ,
struct V_212 * V_213 , int V_47 )
{
struct V_55 * V_242 [ V_198 ] ;
struct V_80 * V_81 ;
struct V_250 * V_251 ;
struct V_34 * V_38 , * V_252 ;
T_5 V_28 = V_298 -> V_94 -> V_28 ;
T_4 V_61 = F_133 ( V_141 ) ;
int V_127 , V_190 , V_296 , V_253 = 0 , V_322 = 0 ;
V_38 = NULL ;
V_251 = NULL ;
V_252 = NULL ;
if ( V_213 && V_213 -> V_214 [ V_141 ] ) {
V_296 = 1 ;
V_242 [ 0 ] = F_134 ( V_213 , V_141 , V_4 ) ;
V_190 = F_177 ( V_4 , V_28 , V_242 ,
& V_296 , & V_253 ) ;
if ( V_190 < 0 )
goto V_323;
if ( V_296 ) {
if ( V_253 <= 0 ) {
V_322 = V_296 ;
goto V_324;
}
V_251 = F_179 (
V_242 , V_296 , V_4 ,
V_28 , V_298 ) ;
if ( F_18 ( V_251 ) ) {
F_178 ( V_242 , V_296 ) ;
V_190 = F_166 ( V_251 ) ;
goto V_323;
} else if ( V_251 == NULL ) {
V_253 = 0 ;
V_322 = V_296 ;
goto V_324;
}
F_154 ( & V_251 -> V_7 . V_38 ) ;
V_251 -> V_7 . V_38 . V_47 |= V_325 ;
V_252 = V_251 -> V_252 ;
}
}
if ( V_251 == NULL ) {
struct V_312 V_313 ;
V_313 . V_298 = V_298 ;
V_313 . V_47 = V_47 ;
if ( ( V_298 -> V_47 & V_326 ) ||
! V_35 -> V_98 . V_134 [ V_141 ] )
goto V_327;
V_81 = F_202 ( V_35 , V_4 , V_28 , V_61 ,
F_200 , & V_313 ) ;
if ( V_81 == NULL )
goto V_327;
if ( F_18 ( V_81 ) ) {
V_190 = F_166 ( V_81 ) ;
goto V_323;
}
V_251 = F_31 ( V_81 , struct V_250 , V_81 ) ;
V_296 = V_251 -> V_296 ;
V_253 = V_251 -> V_253 ;
memcpy ( V_242 , V_251 -> V_242 , sizeof( struct V_55 * ) * V_296 ) ;
V_252 = V_251 -> V_252 ;
}
V_38 = & V_251 -> V_7 . V_38 ;
if ( V_252 == NULL && V_253 > 0 ) {
if ( V_35 -> V_98 . V_315 ) {
F_180 ( V_35 , V_328 ) ;
V_190 = - V_329 ;
goto error;
}
V_190 = - V_240 ;
F_180 ( V_35 , V_328 ) ;
goto error;
}
V_324:
if ( V_296 == 0 )
goto V_327;
if ( ( V_47 & V_330 ) &&
! ( V_242 [ 0 ] -> V_47 & V_331 ) ) {
V_190 = - V_192 ;
goto error;
}
for ( V_127 = 0 ; V_127 < V_296 ; V_127 ++ )
V_242 [ V_127 ] -> V_70 . V_74 = F_21 () ;
if ( V_253 < 0 ) {
F_180 ( V_35 , V_332 ) ;
V_190 = - V_333 ;
goto error;
} else if ( V_253 > 0 ) {
F_167 ( V_298 ) ;
} else {
F_167 ( V_38 ) ;
V_38 = V_298 ;
}
V_334:
F_178 ( V_242 , V_322 ) ;
if ( V_38 && V_38 -> V_98 &&
V_38 -> V_98 -> V_45 . V_231 == V_232 )
V_38 -> V_47 |= V_335 ;
return V_38 ;
V_327:
if ( ! ( V_47 & V_330 ) ) {
V_38 = V_298 ;
goto V_334;
}
V_190 = - V_192 ;
error:
F_167 ( V_38 ) ;
V_323:
if ( ! ( V_47 & V_336 ) )
F_167 ( V_298 ) ;
F_178 ( V_242 , V_322 ) ;
return F_15 ( V_190 ) ;
}
struct V_34 * F_203 ( struct V_35 * V_35 , struct V_34 * V_298 ,
const struct V_3 * V_4 ,
struct V_212 * V_213 , int V_47 )
{
struct V_34 * V_38 = F_187 ( V_35 , V_298 , V_4 , V_213 ,
V_47 | V_314 |
V_336 ) ;
if ( F_18 ( V_38 ) && F_166 ( V_38 ) == - V_329 )
return F_201 ( V_35 , V_298 -> V_94 -> V_28 , V_298 ) ;
return V_38 ;
}
static inline int
F_204 ( int V_166 , struct V_304 * V_305 , const struct V_3 * V_4 )
{
struct V_41 * V_42 ;
if ( ! V_305 -> V_337 || V_166 < 0 || V_166 >= V_305 -> V_337 -> V_172 )
return 0 ;
V_42 = V_305 -> V_337 -> V_338 [ V_166 ] ;
if ( ! V_42 -> type -> V_339 )
return 0 ;
return V_42 -> type -> V_339 ( V_42 , V_305 , V_4 ) ;
}
static inline int
F_205 ( const struct V_223 * V_230 , const struct V_41 * V_42 ,
unsigned short V_28 )
{
if ( F_206 ( V_42 ) )
return V_230 -> V_241 && ! F_207 ( V_230 , V_42 , V_230 -> V_234 ) ;
return V_42 -> V_46 . V_20 == V_230 -> V_46 . V_20 &&
( V_42 -> V_46 . V_340 == V_230 -> V_46 . V_340 || ! V_230 -> V_46 . V_340 ) &&
( V_42 -> V_45 . V_341 == V_230 -> V_341 || ! V_230 -> V_341 ) &&
V_42 -> V_45 . V_231 == V_230 -> V_231 &&
( V_230 -> V_342 || ( V_230 -> V_343 & ( 1 << V_42 -> V_45 . V_344 ) ) ||
! ( F_208 ( V_230 -> V_46 . V_20 , V_345 ) ) ) &&
! ( V_42 -> V_45 . V_231 != V_279 &&
F_207 ( V_230 , V_42 , V_28 ) ) ;
}
static inline int
F_209 ( const struct V_223 * V_230 , const struct V_346 * V_337 , int V_347 ,
unsigned short V_28 )
{
int V_166 = V_347 ;
if ( V_230 -> V_241 ) {
if ( V_230 -> V_231 == V_279 )
return V_347 ;
} else
V_347 = - 1 ;
for (; V_166 < V_337 -> V_172 ; V_166 ++ ) {
if ( F_205 ( V_230 , V_337 -> V_338 [ V_166 ] , V_28 ) )
return ++ V_166 ;
if ( V_337 -> V_338 [ V_166 ] -> V_45 . V_231 != V_279 ) {
if ( V_347 == - 1 )
V_347 = - 2 - V_166 ;
break;
}
}
return V_347 ;
}
int F_210 ( struct V_304 * V_305 , struct V_3 * V_4 ,
unsigned int V_28 , int V_348 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_190 ;
if ( F_9 ( V_32 == NULL ) )
return - V_39 ;
V_32 -> V_349 ( V_305 , V_4 , V_348 ) ;
V_190 = F_211 ( V_305 , & V_4 -> V_204 ) ;
F_13 ( V_32 ) ;
return V_190 ;
}
static inline int F_212 ( const struct V_346 * V_337 , int V_350 , int * V_351 )
{
for (; V_350 < V_337 -> V_172 ; V_350 ++ ) {
if ( V_337 -> V_338 [ V_350 ] -> V_45 . V_231 != V_279 ) {
* V_351 = V_350 ;
return 1 ;
}
}
return 0 ;
}
int F_213 ( struct V_212 * V_213 , int V_61 , struct V_304 * V_305 ,
unsigned short V_28 )
{
struct V_35 * V_35 = F_214 ( V_305 -> V_266 ) ;
struct V_55 * V_82 ;
struct V_55 * V_242 [ V_198 ] ;
int V_243 = 0 ;
int V_221 ;
int V_352 ;
int V_348 ;
struct V_3 V_4 ;
T_4 V_353 ;
int V_354 = - 1 ;
V_348 = V_61 & ~ V_162 ;
V_61 &= V_162 ;
V_353 = F_133 ( V_61 ) ;
if ( F_210 ( V_305 , & V_4 , V_28 , V_348 ) < 0 ) {
F_180 ( V_35 , V_355 ) ;
return 0 ;
}
F_215 ( V_305 , & V_4 , V_28 ) ;
if ( V_305 -> V_337 ) {
int V_127 ;
for ( V_127 = V_305 -> V_337 -> V_172 - 1 ; V_127 >= 0 ; V_127 -- ) {
struct V_41 * V_42 = V_305 -> V_337 -> V_338 [ V_127 ] ;
if ( ! F_7 ( & V_42 -> V_2 , & V_4 , V_28 ) ) {
F_180 ( V_35 , V_356 ) ;
return 0 ;
}
}
}
V_82 = NULL ;
if ( V_213 && V_213 -> V_214 [ V_61 ] ) {
V_82 = F_134 ( V_213 , V_61 , & V_4 ) ;
if ( F_18 ( V_82 ) ) {
F_180 ( V_35 , V_357 ) ;
return 0 ;
}
}
if ( ! V_82 ) {
struct V_80 * V_81 ;
V_81 = F_202 ( V_35 , & V_4 , V_28 , V_353 ,
F_130 , NULL ) ;
if ( F_131 ( V_81 ) )
V_82 = F_132 ( V_81 ) ;
else
V_82 = F_31 ( V_81 , struct V_55 , V_81 ) ;
}
if ( F_18 ( V_82 ) ) {
F_180 ( V_35 , V_357 ) ;
return 0 ;
}
if ( ! V_82 ) {
if ( V_305 -> V_337 && F_212 ( V_305 -> V_337 , 0 , & V_354 ) ) {
F_204 ( V_354 , V_305 , & V_4 ) ;
F_180 ( V_35 , V_358 ) ;
return 0 ;
}
return 1 ;
}
V_82 -> V_70 . V_74 = F_21 () ;
V_242 [ 0 ] = V_82 ;
V_243 ++ ;
#ifdef F_128
if ( V_242 [ 0 ] -> type != V_207 ) {
V_242 [ 1 ] = F_124 ( V_35 , V_207 ,
& V_4 , V_28 ,
V_139 ) ;
if ( V_242 [ 1 ] ) {
if ( F_18 ( V_242 [ 1 ] ) ) {
F_180 ( V_35 , V_357 ) ;
return 0 ;
}
V_242 [ 1 ] -> V_70 . V_74 = F_21 () ;
V_243 ++ ;
}
}
#endif
if ( V_82 -> V_220 == V_297 ) {
struct V_346 * V_337 ;
static struct V_346 V_359 ;
struct V_223 * V_244 [ V_245 ] ;
struct V_223 * V_360 [ V_245 ] ;
struct V_223 * * V_246 = V_244 ;
int V_361 = 0 ;
int V_127 , V_350 ;
if ( ( V_337 = V_305 -> V_337 ) == NULL )
V_337 = & V_359 ;
for ( V_352 = 0 ; V_352 < V_243 ; V_352 ++ ) {
if ( V_242 [ V_352 ] != V_82 &&
V_242 [ V_352 ] -> V_220 != V_297 ) {
F_180 ( V_35 , V_362 ) ;
goto V_339;
}
if ( V_361 + V_242 [ V_352 ] -> V_221 >= V_245 ) {
F_180 ( V_35 , V_363 ) ;
goto V_364;
}
for ( V_127 = 0 ; V_127 < V_242 [ V_352 ] -> V_221 ; V_127 ++ )
V_246 [ V_361 ++ ] = & V_242 [ V_352 ] -> V_222 [ V_127 ] ;
}
V_221 = V_361 ;
if ( V_243 > 1 ) {
F_216 ( V_360 , V_246 , V_221 , V_28 , V_35 ) ;
V_246 = V_360 ;
}
for ( V_127 = V_221 - 1 , V_350 = 0 ; V_127 >= 0 ; V_127 -- ) {
V_350 = F_209 ( V_246 [ V_127 ] , V_337 , V_350 , V_28 ) ;
if ( V_350 < 0 ) {
if ( V_350 < - 1 )
V_354 = - ( 2 + V_350 ) ;
F_180 ( V_35 , V_365 ) ;
goto V_339;
}
}
if ( F_212 ( V_337 , V_350 , & V_354 ) ) {
F_180 ( V_35 , V_365 ) ;
goto V_339;
}
F_178 ( V_242 , V_243 ) ;
return 1 ;
}
F_180 ( V_35 , V_362 ) ;
V_339:
F_204 ( V_354 , V_305 , & V_4 ) ;
V_364:
F_178 ( V_242 , V_243 ) ;
return 0 ;
}
int F_217 ( struct V_304 * V_305 , unsigned short V_28 )
{
struct V_35 * V_35 = F_214 ( V_305 -> V_266 ) ;
struct V_3 V_4 ;
struct V_34 * V_38 ;
int V_366 = 1 ;
if ( F_186 ( V_305 , & V_4 , V_28 ) < 0 ) {
F_180 ( V_35 , V_367 ) ;
return 0 ;
}
F_196 ( V_305 ) ;
V_38 = F_187 ( V_35 , F_185 ( V_305 ) , & V_4 , NULL , V_314 ) ;
if ( F_18 ( V_38 ) ) {
V_366 = 0 ;
V_38 = NULL ;
}
F_192 ( V_305 , V_38 ) ;
return V_366 ;
}
static struct V_34 * F_218 ( struct V_34 * V_38 , T_3 V_368 )
{
if ( V_38 -> V_281 < 0 && ! F_153 ( V_38 ) )
return V_38 ;
return NULL ;
}
static int F_153 ( struct V_34 * V_38 )
{
return ! F_219 ( (struct V_250 * ) V_38 ) ;
}
void F_220 ( struct V_34 * V_38 , struct V_265 * V_266 )
{
while ( ( V_38 = V_38 -> V_277 ) && V_38 -> V_98 && V_38 -> V_266 == V_266 ) {
V_38 -> V_266 = F_214 ( V_266 ) -> V_369 ;
F_221 ( V_38 -> V_266 ) ;
F_222 ( V_266 ) ;
}
}
static void F_223 ( struct V_304 * V_305 )
{
}
static struct V_34 * F_224 ( struct V_34 * V_38 )
{
if ( V_38 ) {
if ( V_38 -> V_281 ) {
F_167 ( V_38 ) ;
V_38 = NULL ;
}
}
return V_38 ;
}
void F_225 ( struct V_35 * V_35 )
{
F_226 ( V_35 ) ;
}
static void F_227 ( struct V_35 * V_35 )
{
F_228 ( V_35 ) ;
}
static void F_172 ( struct V_34 * V_38 )
{
do {
struct V_250 * V_251 = (struct V_250 * ) V_38 ;
T_3 V_370 , V_371 ;
V_370 = F_229 ( V_38 -> V_277 ) ;
V_251 -> V_372 = V_370 ;
V_370 = F_230 ( V_38 -> V_98 , V_370 ) ;
V_371 = F_229 ( V_251 -> V_252 ) ;
V_251 -> V_371 = V_371 ;
if ( V_370 > V_371 )
V_370 = V_371 ;
F_231 ( V_38 , V_373 , V_370 ) ;
} while ( ( V_38 = V_38 -> V_58 ) );
}
static int F_219 ( struct V_250 * V_374 )
{
struct V_34 * V_38 = & V_374 -> V_7 . V_38 ;
struct V_250 * V_375 ;
T_3 V_376 ;
if ( ! F_232 ( V_38 -> V_262 , ( (struct V_250 * ) V_38 ) -> V_377 ) ||
( V_38 -> V_266 && ! F_233 ( V_38 -> V_266 ) ) )
return 0 ;
if ( V_38 -> V_47 & V_254 )
return 1 ;
V_375 = NULL ;
do {
struct V_250 * V_251 = (struct V_250 * ) V_38 ;
if ( V_38 -> V_98 -> V_236 . V_237 != V_238 )
return 0 ;
if ( V_251 -> V_280 != V_38 -> V_98 -> V_97 )
return 0 ;
if ( V_251 -> V_296 > 0 &&
V_251 -> V_302 != F_181 ( & V_251 -> V_242 [ 0 ] -> V_97 ) )
return 0 ;
V_376 = F_229 ( V_38 -> V_277 ) ;
if ( V_251 -> V_372 != V_376 ) {
V_375 = V_251 ;
V_251 -> V_372 = V_376 ;
}
if ( ! F_232 ( V_251 -> V_252 , V_251 -> V_378 ) )
return 0 ;
V_376 = F_229 ( V_251 -> V_252 ) ;
if ( V_251 -> V_371 != V_376 ) {
V_375 = V_251 ;
V_251 -> V_371 = V_376 ;
}
V_38 = V_38 -> V_277 ;
} while ( V_38 -> V_98 );
if ( F_161 ( ! V_375 ) )
return 1 ;
V_376 = V_375 -> V_372 ;
for (; ; ) {
V_38 = & V_375 -> V_7 . V_38 ;
V_376 = F_230 ( V_38 -> V_98 , V_376 ) ;
if ( V_376 > V_375 -> V_371 )
V_376 = V_375 -> V_371 ;
F_231 ( V_38 , V_373 , V_376 ) ;
if ( V_375 == V_374 )
break;
V_375 = (struct V_250 * ) V_375 -> V_7 . V_38 . V_58 ;
V_375 -> V_372 = V_376 ;
}
return 1 ;
}
static unsigned int F_234 ( const struct V_34 * V_38 )
{
return F_235 ( V_38 -> V_262 ) ;
}
static unsigned int F_236 ( const struct V_34 * V_38 )
{
unsigned int V_376 = F_237 ( V_38 , V_373 ) ;
return V_376 ? : F_229 ( V_38 -> V_262 ) ;
}
static struct V_379 * F_238 ( const struct V_34 * V_38 ,
struct V_304 * V_305 ,
const void * V_9 )
{
return V_38 -> V_262 -> V_94 -> V_380 ( V_38 , V_305 , V_9 ) ;
}
int F_239 ( struct V_31 * V_32 )
{
struct V_35 * V_35 ;
int V_190 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_200 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_39 ;
F_182 ( & V_381 ) ;
if ( F_9 ( V_31 [ V_32 -> V_28 ] != NULL ) )
V_190 = - V_185 ;
else {
struct V_255 * V_255 = V_32 -> V_255 ;
if ( F_161 ( V_255 -> V_382 == NULL ) )
V_255 -> V_382 = V_383 ;
if ( F_161 ( V_255 -> V_384 == NULL ) )
V_255 -> V_384 = F_218 ;
if ( F_161 ( V_255 -> V_385 == NULL ) )
V_255 -> V_385 = F_234 ;
if ( F_161 ( V_255 -> V_376 == NULL ) )
V_255 -> V_376 = F_236 ;
if ( F_161 ( V_255 -> V_386 == NULL ) )
V_255 -> V_386 = F_224 ;
if ( F_161 ( V_255 -> V_387 == NULL ) )
V_255 -> V_387 = F_223 ;
if ( F_161 ( V_255 -> V_380 == NULL ) )
V_255 -> V_380 = F_238 ;
if ( F_161 ( V_32 -> V_388 == NULL ) )
V_32 -> V_388 = F_227 ;
F_240 ( V_31 [ V_32 -> V_28 ] , V_32 ) ;
}
F_184 ( & V_381 ) ;
F_241 () ;
F_242 (net) {
struct V_255 * V_389 ;
switch ( V_32 -> V_28 ) {
case V_29 :
V_389 = & V_35 -> V_98 . V_256 ;
break;
#if F_159 ( V_257 )
case V_30 :
V_389 = & V_35 -> V_98 . V_258 ;
break;
#endif
default:
F_46 () ;
}
* V_389 = * V_32 -> V_255 ;
}
F_243 () ;
return V_190 ;
}
int F_244 ( struct V_31 * V_32 )
{
int V_190 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_200 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_39 ;
F_182 ( & V_381 ) ;
if ( F_161 ( V_31 [ V_32 -> V_28 ] != NULL ) ) {
if ( F_9 ( V_31 [ V_32 -> V_28 ] != V_32 ) )
V_190 = - V_200 ;
else
F_245 ( V_31 [ V_32 -> V_28 ] ,
NULL ) ;
}
F_184 ( & V_381 ) ;
if ( ! V_190 ) {
struct V_255 * V_255 = V_32 -> V_255 ;
F_246 () ;
V_255 -> V_382 = NULL ;
V_255 -> V_384 = NULL ;
V_255 -> V_386 = NULL ;
V_255 -> V_387 = NULL ;
V_32 -> V_388 = NULL ;
}
return V_190 ;
}
static void T_6 F_247 ( struct V_35 * V_35 )
{
struct V_31 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_31 [ V_29 ] ) ;
if ( V_32 )
V_35 -> V_98 . V_256 = * V_32 -> V_255 ;
#if F_159 ( V_257 )
V_32 = F_11 ( V_31 [ V_30 ] ) ;
if ( V_32 )
V_35 -> V_98 . V_258 = * V_32 -> V_255 ;
#endif
F_12 () ;
}
static int F_248 ( struct V_390 * V_391 , unsigned long V_392 , void * V_393 )
{
struct V_265 * V_266 = F_249 ( V_393 ) ;
switch ( V_392 ) {
case V_394 :
F_225 ( F_214 ( V_266 ) ) ;
}
return V_395 ;
}
static int T_6 F_250 ( struct V_35 * V_35 )
{
int V_396 ;
V_35 -> V_397 . V_398 = F_251 ( struct V_399 ) ;
if ( ! V_35 -> V_397 . V_398 )
return - V_225 ;
V_396 = F_252 ( V_35 ) ;
if ( V_396 < 0 )
F_253 ( V_35 -> V_397 . V_398 ) ;
return V_396 ;
}
static void F_254 ( struct V_35 * V_35 )
{
F_255 ( V_35 ) ;
F_253 ( V_35 -> V_397 . V_398 ) ;
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
unsigned int V_108 , V_400 ;
int V_61 ;
if ( F_257 ( V_35 , & V_401 ) )
V_383 = F_258 ( L_1 ,
sizeof( struct V_250 ) ,
0 , V_402 | V_403 ,
NULL ) ;
V_108 = 8 - 1 ;
V_400 = ( V_108 + 1 ) * sizeof( struct V_107 ) ;
V_35 -> V_98 . V_131 = F_68 ( V_400 ) ;
if ( ! V_35 -> V_98 . V_131 )
goto V_404;
V_35 -> V_98 . V_99 = V_108 ;
for ( V_61 = 0 ; V_61 < V_145 ; V_61 ++ ) {
struct V_405 * V_406 ;
V_35 -> V_98 . V_134 [ V_61 ] = 0 ;
V_35 -> V_98 . V_134 [ V_145 + V_61 ] = 0 ;
F_84 ( & V_35 -> V_98 . V_110 [ V_61 ] ) ;
V_406 = & V_35 -> V_98 . V_102 [ V_61 ] ;
V_406 -> V_111 = F_68 ( V_400 ) ;
if ( ! V_406 -> V_111 )
goto V_407;
V_406 -> V_108 = V_108 ;
V_406 -> V_103 = 32 ;
V_406 -> V_104 = 32 ;
V_406 -> V_105 = 128 ;
V_406 -> V_106 = 128 ;
}
V_35 -> V_98 . V_154 . V_158 = 32 ;
V_35 -> V_98 . V_154 . V_159 = 32 ;
V_35 -> V_98 . V_154 . V_160 = 128 ;
V_35 -> V_98 . V_154 . V_161 = 128 ;
F_259 ( & V_35 -> V_98 . V_154 . V_62 ) ;
F_37 ( & V_35 -> V_98 . V_201 ) ;
F_260 ( & V_35 -> V_98 . V_152 , F_78 ) ;
F_260 ( & V_35 -> V_98 . V_154 . V_151 , F_81 ) ;
if ( F_257 ( V_35 , & V_401 ) )
F_261 ( & V_408 ) ;
return 0 ;
V_407:
for ( V_61 -- ; V_61 >= 0 ; V_61 -- ) {
struct V_405 * V_406 ;
V_406 = & V_35 -> V_98 . V_102 [ V_61 ] ;
F_71 ( V_406 -> V_111 , V_400 ) ;
}
F_71 ( V_35 -> V_98 . V_131 , V_400 ) ;
V_404:
return - V_225 ;
}
static void F_262 ( struct V_35 * V_35 )
{
unsigned int V_400 ;
int V_61 ;
F_263 ( & V_35 -> V_98 . V_152 ) ;
#ifdef F_128
F_111 ( V_35 , V_206 , false ) ;
#endif
F_111 ( V_35 , V_207 , false ) ;
F_101 ( ! F_114 ( & V_35 -> V_98 . V_201 ) ) ;
for ( V_61 = 0 ; V_61 < V_145 ; V_61 ++ ) {
struct V_405 * V_406 ;
F_101 ( ! F_64 ( & V_35 -> V_98 . V_110 [ V_61 ] ) ) ;
V_406 = & V_35 -> V_98 . V_102 [ V_61 ] ;
V_400 = ( V_406 -> V_108 + 1 ) * sizeof( struct V_107 ) ;
F_101 ( ! F_64 ( V_406 -> V_111 ) ) ;
F_71 ( V_406 -> V_111 , V_400 ) ;
}
V_400 = ( V_35 -> V_98 . V_99 + 1 ) * sizeof( struct V_107 ) ;
F_101 ( ! F_64 ( V_35 -> V_98 . V_131 ) ) ;
F_71 ( V_35 -> V_98 . V_131 , V_400 ) ;
}
static int T_6 F_264 ( struct V_35 * V_35 )
{
int V_396 ;
V_396 = F_250 ( V_35 ) ;
if ( V_396 < 0 )
goto V_409;
V_396 = F_265 ( V_35 ) ;
if ( V_396 < 0 )
goto V_410;
V_396 = F_256 ( V_35 ) ;
if ( V_396 < 0 )
goto V_411;
F_247 ( V_35 ) ;
V_396 = F_266 ( V_35 ) ;
if ( V_396 < 0 )
goto V_412;
V_396 = F_267 ( V_35 ) ;
if ( V_396 < 0 )
goto V_65;
F_268 ( & V_35 -> V_98 . V_413 ) ;
F_39 ( & V_35 -> V_98 . V_128 ) ;
F_269 ( & V_35 -> V_98 . V_414 ) ;
return 0 ;
V_65:
F_270 ( V_35 ) ;
V_412:
F_262 ( V_35 ) ;
V_411:
F_271 ( V_35 ) ;
V_410:
F_254 ( V_35 ) ;
V_409:
return V_396 ;
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
F_275 ( & V_415 ) ;
F_276 () ;
}
static void F_277 ( struct V_55 * V_56 ,
struct V_416 * V_417 )
{
struct V_187 * V_188 = V_56 -> V_96 ;
struct V_1 * V_2 = & V_56 -> V_121 ;
if ( V_188 )
F_278 ( V_417 , L_2 ,
V_188 -> V_418 , V_188 -> V_419 , V_188 -> V_420 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_278 ( V_417 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_278 ( V_417 , L_4 ,
V_2 -> V_13 ) ;
F_278 ( V_417 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_278 ( V_417 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_278 ( V_417 , L_7 , V_2 -> V_12 . V_421 ) ;
if ( V_2 -> V_13 != 128 )
F_278 ( V_417 , L_4 ,
V_2 -> V_13 ) ;
F_278 ( V_417 , L_8 , V_2 -> V_9 . V_421 ) ;
if ( V_2 -> V_11 != 128 )
F_278 ( V_417 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_279 ( struct V_55 * V_56 , int V_422 , bool V_193 )
{
struct V_416 * V_417 ;
V_417 = F_280 ( L_9 ) ;
if ( V_417 == NULL )
return;
F_281 ( V_193 , V_417 ) ;
F_278 ( V_417 , L_10 , V_422 ) ;
F_277 ( V_56 , V_417 ) ;
F_282 ( V_417 ) ;
}
void F_110 ( struct V_55 * V_56 , int V_422 ,
bool V_193 )
{
struct V_416 * V_417 ;
V_417 = F_280 ( L_11 ) ;
if ( V_417 == NULL )
return;
F_281 ( V_193 , V_417 ) ;
F_278 ( V_417 , L_10 , V_422 ) ;
F_277 ( V_56 , V_417 ) ;
F_282 ( V_417 ) ;
}
static bool F_283 ( const struct V_1 * V_423 ,
const struct V_1 * V_424 )
{
if ( V_423 -> V_20 == V_425 ) {
if ( V_424 -> V_28 == V_423 -> V_28 &&
F_284 ( & V_424 -> V_9 , & V_423 -> V_9 ,
V_423 -> V_28 ) &&
F_284 ( & V_424 -> V_12 , & V_423 -> V_12 ,
V_423 -> V_28 ) &&
V_424 -> V_11 == V_423 -> V_11 &&
V_424 -> V_13 == V_423 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_424 , V_423 , sizeof( * V_424 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_55 * F_285 ( const struct V_1 * V_2 ,
T_4 V_61 , T_4 type , struct V_35 * V_35 )
{
struct V_55 * V_82 , * V_191 = NULL ;
struct V_107 * V_155 ;
T_3 V_163 = ~ 0U ;
F_76 ( & V_35 -> V_98 . V_128 ) ;
V_155 = F_57 ( V_35 , & V_2 -> V_9 , & V_2 -> V_12 , V_2 -> V_28 , V_61 ) ;
F_86 (pol, chain, bydst) {
if ( F_283 ( V_2 , & V_82 -> V_121 ) &&
V_82 -> type == type ) {
V_191 = V_82 ;
V_163 = V_191 -> V_163 ;
break;
}
}
V_155 = & V_35 -> V_98 . V_110 [ V_61 ] ;
F_86 (pol, chain, bydst) {
if ( ( V_82 -> V_163 >= V_163 ) && V_191 )
break;
if ( F_283 ( V_2 , & V_82 -> V_121 ) &&
V_82 -> type == type ) {
V_191 = V_82 ;
break;
}
}
F_26 ( V_191 ) ;
F_77 ( & V_35 -> V_98 . V_128 ) ;
return V_191 ;
}
static int F_286 ( const struct V_426 * V_182 , const struct V_223 * V_427 )
{
int V_202 = 0 ;
if ( V_427 -> V_231 == V_182 -> V_231 && V_427 -> V_46 . V_20 == V_182 -> V_20 &&
( V_182 -> V_341 == 0 || V_427 -> V_341 == V_182 -> V_341 ) ) {
switch ( V_427 -> V_231 ) {
case V_232 :
case V_233 :
if ( F_284 ( & V_427 -> V_46 . V_9 , & V_182 -> V_428 ,
V_182 -> V_429 ) &&
F_284 ( & V_427 -> V_12 , & V_182 -> V_430 ,
V_182 -> V_429 ) ) {
V_202 = 1 ;
}
break;
case V_279 :
V_202 = 1 ;
break;
default:
break;
}
}
return V_202 ;
}
static int F_287 ( struct V_55 * V_82 ,
struct V_426 * V_182 , int V_431 )
{
struct V_426 * V_432 ;
int V_127 , V_433 , V_434 = 0 ;
F_69 ( & V_82 -> V_62 ) ;
if ( F_9 ( V_82 -> V_63 . V_64 ) ) {
F_70 ( & V_82 -> V_62 ) ;
return - V_192 ;
}
for ( V_127 = 0 ; V_127 < V_82 -> V_221 ; V_127 ++ ) {
for ( V_433 = 0 , V_432 = V_182 ; V_433 < V_431 ; V_433 ++ , V_432 ++ ) {
if ( ! F_286 ( V_432 , & V_82 -> V_222 [ V_127 ] ) )
continue;
V_434 ++ ;
if ( V_82 -> V_222 [ V_127 ] . V_231 != V_232 &&
V_82 -> V_222 [ V_127 ] . V_231 != V_233 )
continue;
memcpy ( & V_82 -> V_222 [ V_127 ] . V_46 . V_9 , & V_432 -> V_435 ,
sizeof( V_82 -> V_222 [ V_127 ] . V_46 . V_9 ) ) ;
memcpy ( & V_82 -> V_222 [ V_127 ] . V_12 , & V_432 -> V_436 ,
sizeof( V_82 -> V_222 [ V_127 ] . V_12 ) ) ;
V_82 -> V_222 [ V_127 ] . V_234 = V_432 -> V_437 ;
F_50 ( & V_82 -> V_97 ) ;
}
}
F_70 ( & V_82 -> V_62 ) ;
if ( ! V_434 )
return - V_438 ;
return 0 ;
}
static int F_288 ( const struct V_426 * V_182 , int V_431 )
{
int V_127 , V_433 ;
if ( V_431 < 1 || V_431 > V_245 )
return - V_200 ;
for ( V_127 = 0 ; V_127 < V_431 ; V_127 ++ ) {
if ( F_284 ( & V_182 [ V_127 ] . V_428 , & V_182 [ V_127 ] . V_435 ,
V_182 [ V_127 ] . V_429 ) &&
F_284 ( & V_182 [ V_127 ] . V_430 , & V_182 [ V_127 ] . V_436 ,
V_182 [ V_127 ] . V_429 ) )
return - V_200 ;
if ( F_146 ( & V_182 [ V_127 ] . V_435 , V_182 [ V_127 ] . V_437 ) ||
F_146 ( & V_182 [ V_127 ] . V_436 , V_182 [ V_127 ] . V_437 ) )
return - V_200 ;
for ( V_433 = V_127 + 1 ; V_433 < V_431 ; V_433 ++ ) {
if ( ! memcmp ( & V_182 [ V_127 ] . V_428 , & V_182 [ V_433 ] . V_428 ,
sizeof( V_182 [ V_127 ] . V_428 ) ) &&
! memcmp ( & V_182 [ V_127 ] . V_430 , & V_182 [ V_433 ] . V_430 ,
sizeof( V_182 [ V_127 ] . V_430 ) ) &&
V_182 [ V_127 ] . V_20 == V_182 [ V_433 ] . V_20 &&
V_182 [ V_127 ] . V_231 == V_182 [ V_433 ] . V_231 &&
V_182 [ V_127 ] . V_341 == V_182 [ V_433 ] . V_341 &&
V_182 [ V_127 ] . V_429 == V_182 [ V_433 ] . V_429 )
return - V_200 ;
}
}
return 0 ;
}
int V_426 ( const struct V_1 * V_2 , T_4 V_61 , T_4 type ,
struct V_426 * V_182 , int V_431 ,
struct V_439 * V_350 , struct V_35 * V_35 )
{
int V_127 , V_190 , V_440 = 0 , V_441 = 0 ;
struct V_55 * V_82 = NULL ;
struct V_41 * V_42 , * V_442 ;
struct V_41 * V_443 [ V_245 ] ;
struct V_41 * V_444 [ V_245 ] ;
struct V_426 * V_432 ;
if ( ( V_190 = F_288 ( V_182 , V_431 ) ) < 0 )
goto V_65;
if ( ( V_82 = F_285 ( V_2 , V_61 , type , V_35 ) ) == NULL ) {
V_190 = - V_192 ;
goto V_65;
}
for ( V_127 = 0 , V_432 = V_182 ; V_127 < V_431 ; V_127 ++ , V_432 ++ ) {
if ( ( V_42 = F_289 ( V_432 , V_35 ) ) ) {
V_443 [ V_440 ] = V_42 ;
V_440 ++ ;
if ( ( V_442 = F_290 ( V_42 , V_432 ) ) ) {
V_444 [ V_441 ] = V_442 ;
V_441 ++ ;
} else {
V_190 = - V_438 ;
goto V_445;
}
}
}
if ( ( V_190 = F_287 ( V_82 , V_182 , V_431 ) ) < 0 )
goto V_445;
if ( V_440 ) {
F_291 ( V_443 , V_440 ) ;
F_292 ( V_443 , V_440 ) ;
}
F_293 ( V_2 , V_61 , type , V_182 , V_431 , V_350 ) ;
F_28 ( V_82 ) ;
return 0 ;
V_65:
return V_190 ;
V_445:
if ( V_82 )
F_28 ( V_82 ) ;
if ( V_440 )
F_291 ( V_443 , V_440 ) ;
if ( V_441 )
F_292 ( V_444 , V_441 ) ;
return V_190 ;
}
