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
static inline struct V_31 * F_8 ( struct V_32 * V_32 , int V_33 ,
const T_1 * V_12 ,
const T_1 * V_9 ,
int V_28 )
{
struct V_34 * V_35 ;
struct V_31 * V_36 ;
V_35 = F_9 ( V_28 ) ;
if ( F_10 ( V_35 == NULL ) )
return F_11 ( - V_37 ) ;
V_36 = V_35 -> V_38 ( V_32 , V_33 , V_12 , V_9 ) ;
F_12 ( V_35 ) ;
return V_36 ;
}
static inline struct V_31 * F_13 ( struct V_39 * V_40 , int V_33 ,
T_1 * V_41 ,
T_1 * V_42 ,
int V_28 )
{
struct V_32 * V_32 = F_14 ( V_40 ) ;
T_1 * V_12 = & V_40 -> V_43 . V_12 ;
T_1 * V_9 = & V_40 -> V_44 . V_9 ;
struct V_31 * V_36 ;
if ( V_40 -> type -> V_45 & V_46 ) {
V_12 = V_40 -> V_47 ;
V_9 = V_42 ;
}
if ( V_40 -> type -> V_45 & V_48 ) {
V_12 = V_41 ;
V_9 = V_40 -> V_47 ;
}
V_36 = F_8 ( V_32 , V_33 , V_12 , V_9 , V_28 ) ;
if ( ! F_15 ( V_36 ) ) {
if ( V_41 != V_12 )
memcpy ( V_41 , V_12 , sizeof( * V_41 ) ) ;
if ( V_42 != V_9 )
memcpy ( V_42 , V_9 , sizeof( * V_42 ) ) ;
}
return V_36 ;
}
static inline unsigned long F_16 ( long V_49 )
{
if ( V_49 >= ( V_50 - 1 ) / V_51 )
return V_50 - 1 ;
else
return V_49 * V_51 ;
}
static void F_17 ( unsigned long V_52 )
{
struct V_53 * V_54 = (struct V_53 * ) V_52 ;
unsigned long V_55 = F_18 () ;
long V_56 = V_57 ;
int V_58 = 0 ;
int V_59 ;
F_19 ( & V_54 -> V_60 ) ;
if ( F_10 ( V_54 -> V_61 . V_62 ) )
goto V_63;
V_59 = F_20 ( V_54 -> V_64 ) ;
if ( V_54 -> V_65 . V_66 ) {
long V_67 = V_54 -> V_65 . V_66 +
V_54 -> V_68 . V_69 - V_55 ;
if ( V_67 <= 0 )
goto V_70;
if ( V_67 < V_56 )
V_56 = V_67 ;
}
if ( V_54 -> V_65 . V_71 ) {
long V_67 = V_54 -> V_65 . V_71 +
( V_54 -> V_68 . V_72 ? : V_54 -> V_68 . V_69 ) - V_55 ;
if ( V_67 <= 0 )
goto V_70;
if ( V_67 < V_56 )
V_56 = V_67 ;
}
if ( V_54 -> V_65 . V_73 ) {
long V_67 = V_54 -> V_65 . V_73 +
V_54 -> V_68 . V_69 - V_55 ;
if ( V_67 <= 0 ) {
V_58 = 1 ;
V_67 = V_74 ;
}
if ( V_67 < V_56 )
V_56 = V_67 ;
}
if ( V_54 -> V_65 . V_75 ) {
long V_67 = V_54 -> V_65 . V_75 +
( V_54 -> V_68 . V_72 ? : V_54 -> V_68 . V_69 ) - V_55 ;
if ( V_67 <= 0 ) {
V_58 = 1 ;
V_67 = V_74 ;
}
if ( V_67 < V_56 )
V_56 = V_67 ;
}
if ( V_58 )
F_21 ( V_54 , V_59 , 0 , 0 ) ;
if ( V_56 != V_57 &&
! F_22 ( & V_54 -> V_76 , V_77 + F_16 ( V_56 ) ) )
F_23 ( V_54 ) ;
V_63:
F_24 ( & V_54 -> V_60 ) ;
F_25 ( V_54 ) ;
return;
V_70:
F_24 ( & V_54 -> V_60 ) ;
if ( ! F_26 ( V_54 , V_59 ) )
F_21 ( V_54 , V_59 , 1 , 0 ) ;
F_25 ( V_54 ) ;
}
static struct V_78 * F_27 ( struct V_78 * V_79 )
{
struct V_53 * V_80 = F_28 ( V_79 , struct V_53 , V_79 ) ;
if ( F_10 ( V_80 -> V_61 . V_62 ) )
V_79 = NULL ;
else
F_23 ( V_80 ) ;
return V_79 ;
}
static int F_29 ( struct V_78 * V_79 )
{
struct V_53 * V_80 = F_28 ( V_79 , struct V_53 , V_79 ) ;
return ! V_80 -> V_61 . V_62 ;
}
static void F_30 ( struct V_78 * V_79 )
{
F_25 ( F_28 ( V_79 , struct V_53 , V_79 ) ) ;
}
struct V_53 * F_31 ( struct V_32 * V_32 , T_2 V_81 )
{
struct V_53 * V_82 ;
V_82 = F_32 ( sizeof( struct V_53 ) , V_81 ) ;
if ( V_82 ) {
F_33 ( & V_82 -> V_83 , V_32 ) ;
F_34 ( & V_82 -> V_61 . V_84 ) ;
F_35 ( & V_82 -> V_85 ) ;
F_35 ( & V_82 -> V_86 ) ;
F_36 ( & V_82 -> V_60 ) ;
F_37 ( & V_82 -> V_87 , 1 ) ;
F_38 ( & V_82 -> V_76 , F_17 ,
( unsigned long ) V_82 ) ;
V_82 -> V_79 . V_88 = & V_89 ;
}
return V_82 ;
}
void F_39 ( struct V_53 * V_82 )
{
F_40 ( ! V_82 -> V_61 . V_62 ) ;
if ( F_41 ( & V_82 -> V_76 ) )
F_42 () ;
F_43 ( V_82 -> V_90 ) ;
F_44 ( V_82 ) ;
}
static void F_45 ( struct V_53 * V_82 )
{
V_82 -> V_61 . V_62 = 1 ;
F_46 ( & V_82 -> V_91 ) ;
if ( F_41 ( & V_82 -> V_76 ) )
F_25 ( V_82 ) ;
F_25 ( V_82 ) ;
}
static inline unsigned int F_47 ( struct V_32 * V_32 , T_3 V_64 )
{
return F_48 ( V_64 , V_32 -> V_92 . V_93 ) ;
}
static struct V_94 * F_49 ( struct V_32 * V_32 ,
const struct V_1 * V_2 ,
unsigned short V_28 , int V_59 )
{
unsigned int V_95 = V_32 -> V_92 . V_96 [ V_59 ] . V_95 ;
unsigned int V_97 = F_50 ( V_2 , V_28 , V_95 ) ;
return ( V_97 == V_95 + 1 ?
& V_32 -> V_92 . V_98 [ V_59 ] :
V_32 -> V_92 . V_96 [ V_59 ] . V_99 + V_97 ) ;
}
static struct V_94 * F_51 ( struct V_32 * V_32 ,
const T_1 * V_9 ,
const T_1 * V_12 ,
unsigned short V_28 , int V_59 )
{
unsigned int V_95 = V_32 -> V_92 . V_96 [ V_59 ] . V_95 ;
unsigned int V_97 = F_52 ( V_9 , V_12 , V_28 , V_95 ) ;
return V_32 -> V_92 . V_96 [ V_59 ] . V_99 + V_97 ;
}
static void F_53 ( struct V_94 * V_100 ,
struct V_94 * V_101 ,
unsigned int V_102 )
{
struct V_103 * V_104 , * V_105 , * V_106 = NULL ;
struct V_53 * V_80 ;
unsigned int V_107 = 0 ;
V_108:
F_54 (pol, entry, tmp, list, bydst) {
unsigned int V_109 ;
V_109 = F_52 ( & V_80 -> V_110 . V_9 , & V_80 -> V_110 . V_12 ,
V_80 -> V_28 , V_102 ) ;
if ( ! V_106 ) {
F_55 ( V_104 ) ;
F_56 ( & V_80 -> V_85 , V_101 + V_109 ) ;
V_107 = V_109 ;
} else {
if ( V_109 != V_107 )
continue;
F_55 ( V_104 ) ;
F_57 ( V_106 , & V_80 -> V_85 ) ;
}
V_106 = V_104 ;
}
if ( ! F_58 ( V_100 ) ) {
V_106 = NULL ;
goto V_108;
}
}
static void F_59 ( struct V_94 * V_100 ,
struct V_94 * V_111 ,
unsigned int V_102 )
{
struct V_103 * V_104 , * V_105 ;
struct V_53 * V_80 ;
F_54 (pol, entry, tmp, list, byidx) {
unsigned int V_109 ;
V_109 = F_48 ( V_80 -> V_64 , V_102 ) ;
F_56 ( & V_80 -> V_86 , V_111 + V_109 ) ;
}
}
static unsigned long F_60 ( unsigned int V_112 )
{
return ( ( V_112 + 1 ) << 1 ) - 1 ;
}
static void F_61 ( struct V_32 * V_32 , int V_59 )
{
unsigned int V_95 = V_32 -> V_92 . V_96 [ V_59 ] . V_95 ;
unsigned int V_102 = F_60 ( V_95 ) ;
unsigned int V_113 = ( V_102 + 1 ) * sizeof( struct V_94 ) ;
struct V_94 * V_114 = V_32 -> V_92 . V_96 [ V_59 ] . V_99 ;
struct V_94 * V_115 = F_62 ( V_113 ) ;
int V_116 ;
if ( ! V_115 )
return;
F_63 ( & V_117 ) ;
for ( V_116 = V_95 ; V_116 >= 0 ; V_116 -- )
F_53 ( V_114 + V_116 , V_115 , V_102 ) ;
V_32 -> V_92 . V_96 [ V_59 ] . V_99 = V_115 ;
V_32 -> V_92 . V_96 [ V_59 ] . V_95 = V_102 ;
F_64 ( & V_117 ) ;
F_65 ( V_114 , ( V_95 + 1 ) * sizeof( struct V_94 ) ) ;
}
static void F_66 ( struct V_32 * V_32 , int V_118 )
{
unsigned int V_95 = V_32 -> V_92 . V_93 ;
unsigned int V_102 = F_60 ( V_95 ) ;
unsigned int V_113 = ( V_102 + 1 ) * sizeof( struct V_94 ) ;
struct V_94 * V_119 = V_32 -> V_92 . V_120 ;
struct V_94 * V_121 = F_62 ( V_113 ) ;
int V_116 ;
if ( ! V_121 )
return;
F_63 ( & V_117 ) ;
for ( V_116 = V_95 ; V_116 >= 0 ; V_116 -- )
F_59 ( V_119 + V_116 , V_121 , V_102 ) ;
V_32 -> V_92 . V_120 = V_121 ;
V_32 -> V_92 . V_93 = V_102 ;
F_64 ( & V_117 ) ;
F_65 ( V_119 , ( V_95 + 1 ) * sizeof( struct V_94 ) ) ;
}
static inline int F_67 ( struct V_32 * V_32 , int V_59 , int * V_118 )
{
unsigned int V_122 = V_32 -> V_92 . V_123 [ V_59 ] ;
unsigned int V_95 = V_32 -> V_92 . V_96 [ V_59 ] . V_95 ;
if ( V_118 )
* V_118 += V_122 ;
if ( ( V_95 + 1 ) < V_124 &&
V_122 > V_95 )
return 1 ;
return 0 ;
}
static inline int F_68 ( struct V_32 * V_32 , int V_118 )
{
unsigned int V_95 = V_32 -> V_92 . V_93 ;
if ( ( V_95 + 1 ) < V_124 &&
V_118 > V_95 )
return 1 ;
return 0 ;
}
void F_69 ( struct V_32 * V_32 , struct V_125 * V_126 )
{
F_70 ( & V_117 ) ;
V_126 -> V_127 = V_32 -> V_92 . V_123 [ V_128 ] ;
V_126 -> V_129 = V_32 -> V_92 . V_123 [ V_130 ] ;
V_126 -> V_131 = V_32 -> V_92 . V_123 [ V_132 ] ;
V_126 -> V_133 = V_32 -> V_92 . V_123 [ V_128 + V_134 ] ;
V_126 -> V_135 = V_32 -> V_92 . V_123 [ V_130 + V_134 ] ;
V_126 -> V_136 = V_32 -> V_92 . V_123 [ V_132 + V_134 ] ;
V_126 -> V_137 = V_32 -> V_92 . V_93 ;
V_126 -> V_138 = V_124 ;
F_71 ( & V_117 ) ;
}
static void F_72 ( struct V_139 * V_140 )
{
struct V_32 * V_32 = F_28 ( V_140 , struct V_32 , V_92 . V_141 ) ;
int V_59 , V_118 ;
F_73 ( & V_142 ) ;
V_118 = 0 ;
for ( V_59 = 0 ; V_59 < V_134 * 2 ; V_59 ++ ) {
if ( F_67 ( V_32 , V_59 , & V_118 ) )
F_61 ( V_32 , V_59 ) ;
}
if ( F_68 ( V_32 , V_118 ) )
F_66 ( V_32 , V_118 ) ;
F_74 ( & V_142 ) ;
}
static T_3 F_75 ( struct V_32 * V_32 , int V_59 )
{
static T_3 V_143 ;
for (; ; ) {
struct V_103 * V_104 ;
struct V_94 * V_100 ;
struct V_53 * V_144 ;
T_3 V_145 ;
int V_146 ;
V_145 = ( V_143 | V_59 ) ;
V_143 += 8 ;
if ( V_145 == 0 )
V_145 = 8 ;
V_100 = V_32 -> V_92 . V_120 + F_47 ( V_32 , V_145 ) ;
V_146 = 0 ;
F_76 (p, entry, list, byidx) {
if ( V_144 -> V_64 == V_145 ) {
V_146 = 1 ;
break;
}
}
if ( ! V_146 )
return V_145 ;
}
}
static inline int F_77 ( struct V_1 * V_147 , struct V_1 * V_148 )
{
T_3 * V_149 = ( T_3 * ) V_147 ;
T_3 * V_150 = ( T_3 * ) V_148 ;
int V_151 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_116 ;
for ( V_116 = 0 ; V_116 < V_151 ; V_116 ++ ) {
if ( V_149 [ V_116 ] != V_150 [ V_116 ] )
return 1 ;
}
return 0 ;
}
int F_78 ( int V_59 , struct V_53 * V_82 , int V_152 )
{
struct V_32 * V_32 = V_83 ( V_82 ) ;
struct V_53 * V_80 ;
struct V_53 * V_153 ;
struct V_94 * V_154 ;
struct V_103 * V_104 , * V_155 ;
T_3 V_156 = V_82 -> V_156 . V_157 & V_82 -> V_156 . V_158 ;
F_63 ( & V_117 ) ;
V_154 = F_49 ( V_32 , & V_82 -> V_110 , V_82 -> V_28 , V_59 ) ;
V_153 = NULL ;
V_155 = NULL ;
F_76 (pol, entry, chain, bydst) {
if ( V_80 -> type == V_82 -> type &&
! F_77 ( & V_80 -> V_110 , & V_82 -> V_110 ) &&
( V_156 & V_80 -> V_156 . V_158 ) == V_80 -> V_156 . V_157 &&
F_79 ( V_80 -> V_90 , V_82 -> V_90 ) &&
! F_80 ( V_153 ) ) {
if ( V_152 ) {
F_64 ( & V_117 ) ;
return - V_159 ;
}
V_153 = V_80 ;
if ( V_82 -> V_160 > V_80 -> V_160 )
continue;
} else if ( V_82 -> V_160 >= V_80 -> V_160 ) {
V_155 = & V_80 -> V_85 ;
continue;
}
if ( V_153 )
break;
}
if ( V_155 )
F_57 ( V_155 , & V_82 -> V_85 ) ;
else
F_56 ( & V_82 -> V_85 , V_154 ) ;
F_23 ( V_82 ) ;
V_32 -> V_92 . V_123 [ V_59 ] ++ ;
F_46 ( & V_161 ) ;
F_81 ( V_32 ) ;
if ( V_153 )
F_82 ( V_153 , V_59 ) ;
V_82 -> V_64 = V_153 ? V_153 -> V_64 : F_75 ( V_32 , V_59 ) ;
F_56 ( & V_82 -> V_86 , V_32 -> V_92 . V_120 + F_47 ( V_32 , V_82 -> V_64 ) ) ;
V_82 -> V_68 . V_69 = F_18 () ;
V_82 -> V_68 . V_72 = 0 ;
if ( ! F_22 ( & V_82 -> V_76 , V_77 + V_51 ) )
F_23 ( V_82 ) ;
F_83 ( & V_82 -> V_61 . V_84 , & V_32 -> V_92 . V_162 ) ;
F_64 ( & V_117 ) ;
if ( V_153 )
F_45 ( V_153 ) ;
else if ( F_67 ( V_32 , V_59 , NULL ) )
F_84 ( & V_32 -> V_92 . V_141 ) ;
return 0 ;
}
struct V_53 * F_85 ( struct V_32 * V_32 , T_3 V_156 , T_4 type ,
int V_59 , struct V_1 * V_2 ,
struct V_163 * V_164 , int V_165 ,
int * V_166 )
{
struct V_53 * V_80 , * V_167 ;
struct V_94 * V_154 ;
struct V_103 * V_104 ;
* V_166 = 0 ;
F_63 ( & V_117 ) ;
V_154 = F_49 ( V_32 , V_2 , V_2 -> V_28 , V_59 ) ;
V_167 = NULL ;
F_76 (pol, entry, chain, bydst) {
if ( V_80 -> type == type &&
( V_156 & V_80 -> V_156 . V_158 ) == V_80 -> V_156 . V_157 &&
! F_77 ( V_2 , & V_80 -> V_110 ) &&
F_79 ( V_164 , V_80 -> V_90 ) ) {
F_23 ( V_80 ) ;
if ( V_165 ) {
* V_166 = F_86 (
V_80 -> V_90 ) ;
if ( * V_166 ) {
F_64 ( & V_117 ) ;
return V_80 ;
}
F_82 ( V_80 , V_59 ) ;
}
V_167 = V_80 ;
break;
}
}
F_64 ( & V_117 ) ;
if ( V_167 && V_165 )
F_45 ( V_167 ) ;
return V_167 ;
}
struct V_53 * F_87 ( struct V_32 * V_32 , T_3 V_156 , T_4 type ,
int V_59 , T_3 V_44 , int V_165 , int * V_166 )
{
struct V_53 * V_80 , * V_167 ;
struct V_94 * V_154 ;
struct V_103 * V_104 ;
* V_166 = - V_168 ;
if ( F_20 ( V_44 ) != V_59 )
return NULL ;
* V_166 = 0 ;
F_63 ( & V_117 ) ;
V_154 = V_32 -> V_92 . V_120 + F_47 ( V_32 , V_44 ) ;
V_167 = NULL ;
F_76 (pol, entry, chain, byidx) {
if ( V_80 -> type == type && V_80 -> V_64 == V_44 &&
( V_156 & V_80 -> V_156 . V_158 ) == V_80 -> V_156 . V_157 ) {
F_23 ( V_80 ) ;
if ( V_165 ) {
* V_166 = F_86 (
V_80 -> V_90 ) ;
if ( * V_166 ) {
F_64 ( & V_117 ) ;
return V_80 ;
}
F_82 ( V_80 , V_59 ) ;
}
V_167 = V_80 ;
break;
}
}
F_64 ( & V_117 ) ;
if ( V_167 && V_165 )
F_45 ( V_167 ) ;
return V_167 ;
}
static inline int
F_88 ( struct V_32 * V_32 , T_4 type , struct V_169 * V_170 )
{
int V_59 , V_166 = 0 ;
for ( V_59 = 0 ; V_59 < V_134 ; V_59 ++ ) {
struct V_53 * V_80 ;
struct V_103 * V_104 ;
int V_116 ;
F_76 (pol, entry,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_80 -> type != type )
continue;
V_166 = F_86 ( V_80 -> V_90 ) ;
if ( V_166 ) {
F_89 ( V_80 , 0 ,
V_170 -> V_171 ,
V_170 -> V_172 ,
V_170 -> V_173 ) ;
return V_166 ;
}
}
for ( V_116 = V_32 -> V_92 . V_96 [ V_59 ] . V_95 ; V_116 >= 0 ; V_116 -- ) {
F_76 (pol, entry,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_80 -> type != type )
continue;
V_166 = F_86 (
V_80 -> V_90 ) ;
if ( V_166 ) {
F_89 ( V_80 , 0 ,
V_170 -> V_171 ,
V_170 -> V_172 ,
V_170 -> V_173 ) ;
return V_166 ;
}
}
}
}
return V_166 ;
}
static inline int
F_88 ( struct V_32 * V_32 , T_4 type , struct V_169 * V_170 )
{
return 0 ;
}
int F_90 ( struct V_32 * V_32 , T_4 type , struct V_169 * V_170 )
{
int V_59 , V_166 = 0 , V_122 = 0 ;
F_63 ( & V_117 ) ;
V_166 = F_88 ( V_32 , type , V_170 ) ;
if ( V_166 )
goto V_63;
for ( V_59 = 0 ; V_59 < V_134 ; V_59 ++ ) {
struct V_53 * V_80 ;
struct V_103 * V_104 ;
int V_116 ;
V_174:
F_76 (pol, entry,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_80 -> type != type )
continue;
F_82 ( V_80 , V_59 ) ;
F_64 ( & V_117 ) ;
V_122 ++ ;
F_89 ( V_80 , 1 , V_170 -> V_171 ,
V_170 -> V_172 ,
V_170 -> V_173 ) ;
F_45 ( V_80 ) ;
F_63 ( & V_117 ) ;
goto V_174;
}
for ( V_116 = V_32 -> V_92 . V_96 [ V_59 ] . V_95 ; V_116 >= 0 ; V_116 -- ) {
V_175:
F_76 (pol, entry,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_80 -> type != type )
continue;
F_82 ( V_80 , V_59 ) ;
F_64 ( & V_117 ) ;
V_122 ++ ;
F_89 ( V_80 , 1 ,
V_170 -> V_171 ,
V_170 -> V_172 ,
V_170 -> V_173 ) ;
F_45 ( V_80 ) ;
F_63 ( & V_117 ) ;
goto V_175;
}
}
}
if ( ! V_122 )
V_166 = - V_176 ;
V_63:
F_64 ( & V_117 ) ;
return V_166 ;
}
int F_91 ( struct V_32 * V_32 , struct F_91 * V_61 ,
int (* F_92)( struct V_53 * , int , int , void * ) ,
void * V_52 )
{
struct V_53 * V_80 ;
struct V_177 * V_40 ;
int error = 0 ;
if ( V_61 -> type >= V_178 &&
V_61 -> type != V_179 )
return - V_180 ;
if ( F_93 ( & V_61 -> V_61 . V_84 ) && V_61 -> V_181 != 0 )
return 0 ;
F_63 ( & V_117 ) ;
if ( F_93 ( & V_61 -> V_61 . V_84 ) )
V_40 = F_94 ( & V_32 -> V_92 . V_162 , struct V_177 , V_84 ) ;
else
V_40 = F_95 ( & V_61 -> V_61 . V_84 , struct V_177 , V_84 ) ;
F_96 (x, &net->xfrm.policy_all, all) {
if ( V_40 -> V_62 )
continue;
V_80 = F_28 ( V_40 , struct V_53 , V_61 ) ;
if ( V_61 -> type != V_179 &&
V_61 -> type != V_80 -> type )
continue;
error = F_92 ( V_80 , F_20 ( V_80 -> V_64 ) ,
V_61 -> V_181 , V_52 ) ;
if ( error ) {
F_97 ( & V_61 -> V_61 . V_84 , & V_40 -> V_84 ) ;
goto V_63;
}
V_61 -> V_181 ++ ;
}
if ( V_61 -> V_181 == 0 ) {
error = - V_168 ;
goto V_63;
}
F_98 ( & V_61 -> V_61 . V_84 ) ;
V_63:
F_64 ( & V_117 ) ;
return error ;
}
void F_99 ( struct F_91 * V_61 , T_4 type )
{
F_34 ( & V_61 -> V_61 . V_84 ) ;
V_61 -> V_61 . V_62 = 1 ;
V_61 -> type = type ;
V_61 -> V_181 = 0 ;
}
void F_100 ( struct F_91 * V_61 )
{
if ( F_93 ( & V_61 -> V_61 . V_84 ) )
return;
F_63 ( & V_117 ) ;
F_101 ( & V_61 -> V_61 . V_84 ) ;
F_64 ( & V_117 ) ;
}
static int F_102 ( const struct V_53 * V_80 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_28 , int V_59 )
{
const struct V_1 * V_2 = & V_80 -> V_110 ;
int V_167 = - V_176 ;
bool V_182 ;
if ( V_80 -> V_28 != V_28 ||
( V_4 -> V_183 & V_80 -> V_156 . V_158 ) != V_80 -> V_156 . V_157 ||
V_80 -> type != type )
return V_167 ;
V_182 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_182 )
V_167 = F_103 ( V_80 -> V_90 , V_4 -> V_184 ,
V_59 ) ;
return V_167 ;
}
static struct V_53 * F_104 ( struct V_32 * V_32 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_28 , T_4 V_59 )
{
int V_166 ;
struct V_53 * V_80 , * V_167 ;
const T_1 * V_9 , * V_12 ;
struct V_103 * V_104 ;
struct V_94 * V_154 ;
T_3 V_160 = ~ 0U ;
V_9 = F_105 ( V_4 , V_28 ) ;
V_12 = F_106 ( V_4 , V_28 ) ;
if ( F_10 ( ! V_9 || ! V_12 ) )
return NULL ;
F_70 ( & V_117 ) ;
V_154 = F_51 ( V_32 , V_9 , V_12 , V_28 , V_59 ) ;
V_167 = NULL ;
F_76 (pol, entry, chain, bydst) {
V_166 = F_102 ( V_80 , V_4 , type , V_28 , V_59 ) ;
if ( V_166 ) {
if ( V_166 == - V_176 )
continue;
else {
V_167 = F_11 ( V_166 ) ;
goto V_185;
}
} else {
V_167 = V_80 ;
V_160 = V_167 -> V_160 ;
break;
}
}
V_154 = & V_32 -> V_92 . V_98 [ V_59 ] ;
F_76 (pol, entry, chain, bydst) {
V_166 = F_102 ( V_80 , V_4 , type , V_28 , V_59 ) ;
if ( V_166 ) {
if ( V_166 == - V_176 )
continue;
else {
V_167 = F_11 ( V_166 ) ;
goto V_185;
}
} else if ( V_80 -> V_160 < V_160 ) {
V_167 = V_80 ;
break;
}
}
if ( V_167 )
F_23 ( V_167 ) ;
V_185:
F_71 ( & V_117 ) ;
return V_167 ;
}
static struct V_53 *
F_107 ( struct V_32 * V_32 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_59 )
{
#ifdef F_108
struct V_53 * V_80 ;
V_80 = F_104 ( V_32 , V_186 , V_4 , V_28 , V_59 ) ;
if ( V_80 != NULL )
return V_80 ;
#endif
return F_104 ( V_32 , V_187 , V_4 , V_28 , V_59 ) ;
}
static struct V_78 *
F_109 ( struct V_32 * V_32 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_59 , struct V_78 * V_188 , void * V_164 )
{
struct V_53 * V_80 ;
if ( V_188 )
F_25 ( F_28 ( V_188 , struct V_53 , V_79 ) ) ;
V_80 = F_107 ( V_32 , V_4 , V_28 , V_59 ) ;
if ( F_110 ( V_80 ) )
return F_111 ( V_80 ) ;
F_23 ( V_80 ) ;
return & V_80 -> V_79 ;
}
static inline int F_112 ( int V_59 )
{
if ( V_128 == V_189 &&
V_130 == V_190 &&
V_132 == V_191 )
return V_59 ;
switch ( V_59 ) {
default:
case V_128 :
return V_189 ;
case V_130 :
return V_190 ;
case V_132 :
return V_191 ;
}
}
static struct V_53 * F_113 ( struct V_192 * V_193 , int V_59 ,
const struct V_3 * V_4 )
{
struct V_53 * V_80 ;
F_70 ( & V_117 ) ;
if ( ( V_80 = V_193 -> V_194 [ V_59 ] ) != NULL ) {
bool V_182 = F_7 ( & V_80 -> V_110 , V_4 ,
V_193 -> V_195 ) ;
int V_166 = 0 ;
if ( V_182 ) {
if ( ( V_193 -> V_196 & V_80 -> V_156 . V_158 ) != V_80 -> V_156 . V_157 ) {
V_80 = NULL ;
goto V_63;
}
V_166 = F_103 ( V_80 -> V_90 ,
V_4 -> V_184 ,
F_112 ( V_59 ) ) ;
if ( ! V_166 )
F_23 ( V_80 ) ;
else if ( V_166 == - V_176 )
V_80 = NULL ;
else
V_80 = F_11 ( V_166 ) ;
} else
V_80 = NULL ;
}
V_63:
F_71 ( & V_117 ) ;
return V_80 ;
}
static void F_114 ( struct V_53 * V_80 , int V_59 )
{
struct V_32 * V_32 = V_83 ( V_80 ) ;
struct V_94 * V_154 = F_49 ( V_32 , & V_80 -> V_110 ,
V_80 -> V_28 , V_59 ) ;
F_83 ( & V_80 -> V_61 . V_84 , & V_32 -> V_92 . V_162 ) ;
F_56 ( & V_80 -> V_85 , V_154 ) ;
F_56 ( & V_80 -> V_86 , V_32 -> V_92 . V_120 + F_47 ( V_32 , V_80 -> V_64 ) ) ;
V_32 -> V_92 . V_123 [ V_59 ] ++ ;
F_23 ( V_80 ) ;
if ( F_67 ( V_32 , V_59 , NULL ) )
F_84 ( & V_32 -> V_92 . V_141 ) ;
}
static struct V_53 * F_82 ( struct V_53 * V_80 ,
int V_59 )
{
struct V_32 * V_32 = V_83 ( V_80 ) ;
if ( F_115 ( & V_80 -> V_85 ) )
return NULL ;
F_55 ( & V_80 -> V_85 ) ;
F_55 ( & V_80 -> V_86 ) ;
F_101 ( & V_80 -> V_61 . V_84 ) ;
V_32 -> V_92 . V_123 [ V_59 ] -- ;
return V_80 ;
}
int F_26 ( struct V_53 * V_80 , int V_59 )
{
F_63 ( & V_117 ) ;
V_80 = F_82 ( V_80 , V_59 ) ;
F_64 ( & V_117 ) ;
if ( V_80 ) {
F_45 ( V_80 ) ;
return 0 ;
}
return - V_168 ;
}
int F_116 ( struct V_192 * V_193 , int V_59 , struct V_53 * V_80 )
{
struct V_32 * V_32 = V_83 ( V_80 ) ;
struct V_53 * V_197 ;
#ifdef F_108
if ( V_80 && V_80 -> type != V_187 )
return - V_180 ;
#endif
F_63 ( & V_117 ) ;
V_197 = V_193 -> V_194 [ V_59 ] ;
V_193 -> V_194 [ V_59 ] = V_80 ;
if ( V_80 ) {
V_80 -> V_68 . V_69 = F_18 () ;
V_80 -> V_64 = F_75 ( V_32 , V_134 + V_59 ) ;
F_114 ( V_80 , V_134 + V_59 ) ;
}
if ( V_197 )
F_82 ( V_197 , V_134 + V_59 ) ;
F_64 ( & V_117 ) ;
if ( V_197 ) {
F_45 ( V_197 ) ;
}
return 0 ;
}
static struct V_53 * F_117 ( const struct V_53 * V_198 , int V_59 )
{
struct V_53 * V_199 = F_31 ( V_83 ( V_198 ) , V_200 ) ;
if ( V_199 ) {
V_199 -> V_110 = V_198 -> V_110 ;
if ( F_118 ( V_198 -> V_90 ,
& V_199 -> V_90 ) ) {
F_44 ( V_199 ) ;
return NULL ;
}
V_199 -> V_65 = V_198 -> V_65 ;
V_199 -> V_68 = V_198 -> V_68 ;
V_199 -> V_156 = V_198 -> V_156 ;
V_199 -> V_201 = V_198 -> V_201 ;
V_199 -> V_45 = V_198 -> V_45 ;
V_199 -> V_202 = V_198 -> V_202 ;
V_199 -> V_64 = V_198 -> V_64 ;
V_199 -> type = V_198 -> type ;
memcpy ( V_199 -> V_203 , V_198 -> V_203 ,
V_199 -> V_202 * sizeof( struct V_204 ) ) ;
F_63 ( & V_117 ) ;
F_114 ( V_199 , V_134 + V_59 ) ;
F_64 ( & V_117 ) ;
F_25 ( V_199 ) ;
}
return V_199 ;
}
int F_119 ( struct V_192 * V_193 )
{
struct V_53 * V_205 = V_193 -> V_194 [ 0 ] ,
* V_149 = V_193 -> V_194 [ 1 ] ;
V_193 -> V_194 [ 0 ] = V_193 -> V_194 [ 1 ] = NULL ;
if ( V_205 && ( V_193 -> V_194 [ 0 ] = F_117 ( V_205 , 0 ) ) == NULL )
return - V_206 ;
if ( V_149 && ( V_193 -> V_194 [ 1 ] = F_117 ( V_149 , 1 ) ) == NULL )
return - V_206 ;
return 0 ;
}
static int
F_120 ( struct V_32 * V_32 , T_1 * V_207 , T_1 * V_208 ,
unsigned short V_28 )
{
int V_166 ;
struct V_34 * V_35 = F_9 ( V_28 ) ;
if ( F_10 ( V_35 == NULL ) )
return - V_180 ;
V_166 = V_35 -> V_209 ( V_32 , V_207 , V_208 ) ;
F_12 ( V_35 ) ;
return V_166 ;
}
static int
F_121 ( struct V_53 * V_82 , const struct V_3 * V_4 ,
struct V_39 * * V_92 , unsigned short V_28 )
{
struct V_32 * V_32 = V_83 ( V_82 ) ;
int V_210 ;
int V_116 , error ;
T_1 * V_9 = F_105 ( V_4 , V_28 ) ;
T_1 * V_12 = F_106 ( V_4 , V_28 ) ;
T_1 V_105 ;
for ( V_210 = 0 , V_116 = 0 ; V_116 < V_82 -> V_202 ; V_116 ++ ) {
struct V_39 * V_40 ;
T_1 * V_208 = V_9 ;
T_1 * V_207 = V_12 ;
struct V_204 * V_211 = & V_82 -> V_203 [ V_116 ] ;
if ( V_211 -> V_212 == V_213 ||
V_211 -> V_212 == V_214 ) {
V_208 = & V_211 -> V_44 . V_9 ;
V_207 = & V_211 -> V_12 ;
if ( F_122 ( V_207 , V_211 -> V_215 ) ) {
error = F_120 ( V_32 , & V_105 , V_208 , V_211 -> V_215 ) ;
if ( error )
goto V_185;
V_207 = & V_105 ;
}
}
V_40 = F_123 ( V_208 , V_207 , V_4 , V_211 , V_82 , & error , V_28 ) ;
if ( V_40 && V_40 -> V_216 . V_217 == V_218 ) {
V_92 [ V_210 ++ ] = V_40 ;
V_9 = V_208 ;
V_12 = V_207 ;
continue;
}
if ( V_40 ) {
error = ( V_40 -> V_216 . V_217 == V_219 ?
- V_180 : - V_220 ) ;
F_124 ( V_40 ) ;
}
else if ( error == - V_176 )
error = - V_220 ;
if ( ! V_211 -> V_221 )
goto V_185;
}
return V_210 ;
V_185:
for ( V_210 -- ; V_210 >= 0 ; V_210 -- )
F_124 ( V_92 [ V_210 ] ) ;
return error ;
}
static int
F_125 ( struct V_53 * * V_222 , int V_223 , const struct V_3 * V_4 ,
struct V_39 * * V_92 , unsigned short V_28 )
{
struct V_39 * V_224 [ V_225 ] ;
struct V_39 * * V_226 = ( V_223 > 1 ) ? V_224 : V_92 ;
int V_227 = 0 ;
int error ;
int V_167 ;
int V_116 ;
for ( V_116 = 0 ; V_116 < V_223 ; V_116 ++ ) {
if ( V_227 + V_222 [ V_116 ] -> V_202 >= V_225 ) {
error = - V_228 ;
goto V_185;
}
V_167 = F_121 ( V_222 [ V_116 ] , V_4 , & V_226 [ V_227 ] , V_28 ) ;
if ( V_167 < 0 ) {
error = V_167 ;
goto V_185;
} else
V_227 += V_167 ;
}
if ( V_223 > 1 )
F_126 ( V_92 , V_226 , V_227 , V_28 ) ;
return V_227 ;
V_185:
for ( V_227 -- ; V_227 >= 0 ; V_227 -- )
F_124 ( V_226 [ V_227 ] ) ;
return error ;
}
static inline int F_127 ( const struct V_3 * V_4 , int V_28 )
{
struct V_34 * V_35 = F_9 ( V_28 ) ;
int V_33 ;
if ( ! V_35 )
return - V_180 ;
V_33 = V_35 -> V_229 ( V_4 ) ;
F_12 ( V_35 ) ;
return V_33 ;
}
static struct V_78 * F_128 ( struct V_78 * V_79 )
{
struct V_230 * V_231 = F_28 ( V_79 , struct V_230 , V_79 ) ;
struct V_31 * V_36 = & V_231 -> V_7 . V_36 ;
if ( V_231 -> V_232 == NULL ) {
if ( V_231 -> V_233 > 0 )
return NULL ;
} else {
if ( F_129 ( V_36 ) )
return NULL ;
}
F_130 ( V_36 ) ;
return V_79 ;
}
static int F_131 ( struct V_78 * V_79 )
{
struct V_230 * V_231 = F_28 ( V_79 , struct V_230 , V_79 ) ;
struct V_31 * V_36 = & V_231 -> V_7 . V_36 ;
if ( ! V_231 -> V_232 )
return 0 ;
if ( F_129 ( V_36 ) )
return 0 ;
return 1 ;
}
static void F_132 ( struct V_78 * V_79 )
{
struct V_230 * V_231 = F_28 ( V_79 , struct V_230 , V_79 ) ;
struct V_31 * V_36 = & V_231 -> V_7 . V_36 ;
F_133 ( V_36 ) ;
}
static inline struct V_230 * F_134 ( struct V_32 * V_32 , int V_28 )
{
struct V_34 * V_35 = F_9 ( V_28 ) ;
struct V_234 * V_234 ;
struct V_230 * V_231 ;
if ( ! V_35 )
return F_11 ( - V_180 ) ;
switch ( V_28 ) {
case V_29 :
V_234 = & V_32 -> V_92 . V_235 ;
break;
#if F_135 ( V_236 )
case V_30 :
V_234 = & V_32 -> V_92 . V_237 ;
break;
#endif
default:
F_42 () ;
}
V_231 = F_136 ( V_234 , NULL , 0 , V_238 , 0 ) ;
if ( F_137 ( V_231 ) ) {
struct V_31 * V_36 = & V_231 -> V_7 . V_36 ;
memset ( V_36 + 1 , 0 , sizeof( * V_231 ) - sizeof( * V_36 ) ) ;
V_231 -> V_79 . V_88 = & V_239 ;
if ( V_35 -> V_240 )
V_35 -> V_240 ( V_32 , V_231 ) ;
} else
V_231 = F_11 ( - V_228 ) ;
F_12 ( V_35 ) ;
return V_231 ;
}
static inline int F_138 ( struct V_230 * V_241 , struct V_31 * V_36 ,
int V_242 )
{
struct V_34 * V_35 =
F_9 ( V_36 -> V_88 -> V_28 ) ;
int V_166 ;
if ( ! V_35 )
return - V_180 ;
V_166 = V_35 -> V_243 ( V_241 , V_36 , V_242 ) ;
F_12 ( V_35 ) ;
return V_166 ;
}
static inline int F_139 ( struct V_230 * V_231 , struct V_244 * V_245 ,
const struct V_3 * V_4 )
{
struct V_34 * V_35 =
F_9 ( V_231 -> V_7 . V_36 . V_88 -> V_28 ) ;
int V_166 ;
if ( ! V_35 )
return - V_180 ;
V_166 = V_35 -> V_246 ( V_231 , V_245 , V_4 ) ;
F_12 ( V_35 ) ;
return V_166 ;
}
static struct V_31 * F_140 ( struct V_53 * V_82 ,
struct V_39 * * V_92 , int V_210 ,
const struct V_3 * V_4 ,
struct V_31 * V_36 )
{
struct V_32 * V_32 = V_83 ( V_82 ) ;
unsigned long V_55 = V_77 ;
struct V_244 * V_245 ;
struct V_247 * V_248 ;
struct V_31 * V_249 = NULL ;
struct V_31 * V_250 = NULL ;
int V_116 = 0 ;
int V_166 ;
int V_251 = 0 ;
int V_242 = 0 ;
int V_252 = 0 ;
int V_33 ;
int V_28 = V_82 -> V_110 . V_28 ;
T_1 V_12 , V_9 ;
F_141 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_33 = F_127 ( V_4 , V_28 ) ;
V_166 = V_33 ;
if ( V_33 < 0 )
goto V_253;
F_130 ( V_36 ) ;
for (; V_116 < V_210 ; V_116 ++ ) {
struct V_230 * V_231 = F_134 ( V_32 , V_28 ) ;
struct V_31 * V_254 = & V_231 -> V_7 . V_36 ;
V_166 = F_142 ( V_231 ) ;
if ( F_15 ( V_231 ) ) {
F_143 ( V_36 ) ;
goto V_253;
}
if ( V_92 [ V_116 ] -> V_2 . V_28 == V_255 ) {
V_248 = F_144 ( V_92 [ V_116 ] ,
F_145 ( V_28 ) ) ;
if ( ! V_248 ) {
V_166 = - V_37 ;
F_143 ( V_36 ) ;
goto V_253;
}
} else
V_248 = V_92 [ V_116 ] -> V_248 ;
if ( ! V_249 )
V_250 = V_254 ;
else {
V_249 -> V_256 = F_146 ( V_254 ) ;
V_254 -> V_45 |= V_257 ;
}
V_231 -> V_232 = V_36 ;
F_147 ( V_254 , V_36 ) ;
if ( V_92 [ V_116 ] -> V_43 . V_212 != V_258 ) {
V_28 = V_92 [ V_116 ] -> V_43 . V_28 ;
V_36 = F_13 ( V_92 [ V_116 ] , V_33 , & V_12 , & V_9 ,
V_28 ) ;
V_166 = F_142 ( V_36 ) ;
if ( F_15 ( V_36 ) )
goto V_253;
} else
F_130 ( V_36 ) ;
V_254 -> V_92 = V_92 [ V_116 ] ;
V_231 -> V_259 = V_92 [ V_116 ] -> V_91 ;
V_254 -> V_260 = V_261 ;
V_254 -> V_45 |= V_262 ;
V_254 -> V_263 = V_55 ;
V_254 -> V_264 = V_265 ;
V_254 -> V_266 = V_248 -> V_35 -> V_266 ;
V_254 -> V_56 = V_249 ;
V_249 = V_254 ;
V_251 += V_92 [ V_116 ] -> V_43 . V_251 ;
if ( V_92 [ V_116 ] -> type -> V_45 & V_267 )
V_242 += V_92 [ V_116 ] -> V_43 . V_251 ;
V_252 += V_92 [ V_116 ] -> V_43 . V_252 ;
}
V_249 -> V_256 = V_36 ;
V_250 -> V_241 = V_36 ;
V_166 = - V_268 ;
V_245 = V_36 -> V_245 ;
if ( ! V_245 )
goto V_269;
F_138 ( (struct V_230 * ) V_250 , V_36 , V_242 ) ;
F_148 ( V_249 ) ;
for ( V_249 = V_250 ; V_249 != V_36 ; V_249 = V_249 -> V_256 ) {
struct V_230 * V_231 = (struct V_230 * ) V_249 ;
V_166 = F_139 ( V_231 , V_245 , V_4 ) ;
if ( V_166 )
goto V_269;
V_249 -> V_251 = V_251 ;
V_249 -> V_252 = V_252 ;
V_251 -= V_231 -> V_7 . V_36 . V_92 -> V_43 . V_251 ;
V_252 -= V_231 -> V_7 . V_36 . V_92 -> V_43 . V_252 ;
}
V_63:
return V_250 ;
V_253:
for (; V_116 < V_210 ; V_116 ++ )
F_124 ( V_92 [ V_116 ] ) ;
V_269:
if ( V_250 )
F_133 ( V_250 ) ;
V_250 = F_11 ( V_166 ) ;
goto V_63;
}
static int inline
F_149 ( void * * V_270 , const void * V_271 , int V_272 )
{
if ( ! * V_270 ) {
* V_270 = F_150 ( V_272 , V_200 ) ;
if ( ! * V_270 )
return - V_206 ;
}
memcpy ( * V_270 , V_271 , V_272 ) ;
return 0 ;
}
static int inline
F_151 ( struct V_31 * V_36 , const struct V_1 * V_2 )
{
#ifdef F_108
struct V_230 * V_231 = (struct V_230 * ) V_36 ;
return F_149 ( ( void * * ) & ( V_231 -> V_273 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int inline
F_152 ( struct V_31 * V_36 , const struct V_3 * V_4 )
{
#ifdef F_108
struct V_230 * V_231 = (struct V_230 * ) V_36 ;
return F_149 ( ( void * * ) & ( V_231 -> V_274 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_153 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_53 * * V_222 ,
int * V_275 , int * V_233 )
{
int V_116 ;
if ( * V_275 == 0 || ! V_222 [ 0 ] ) {
* V_275 = 0 ;
* V_233 = 0 ;
return 0 ;
}
if ( F_15 ( V_222 [ 0 ] ) )
return F_142 ( V_222 [ 0 ] ) ;
* V_233 = V_222 [ 0 ] -> V_202 ;
#ifdef F_108
if ( V_222 [ 0 ] && V_222 [ 0 ] -> V_201 == V_276 &&
V_222 [ 0 ] -> type != V_187 ) {
V_222 [ 1 ] = F_104 ( V_83 ( V_222 [ 0 ] ) ,
V_187 ,
V_4 , V_28 ,
V_130 ) ;
if ( V_222 [ 1 ] ) {
if ( F_15 ( V_222 [ 1 ] ) ) {
F_154 ( V_222 , * V_275 ) ;
return F_142 ( V_222 [ 1 ] ) ;
}
( * V_275 ) ++ ;
( * V_233 ) += V_222 [ 1 ] -> V_202 ;
}
}
#endif
for ( V_116 = 0 ; V_116 < * V_275 ; V_116 ++ ) {
if ( V_222 [ V_116 ] -> V_201 != V_276 ) {
* V_233 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_230 *
F_155 ( struct V_53 * * V_222 , int V_275 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_31 * V_277 )
{
struct V_32 * V_32 = V_83 ( V_222 [ 0 ] ) ;
struct V_39 * V_92 [ V_225 ] ;
struct V_31 * V_36 ;
struct V_230 * V_231 ;
int V_166 ;
V_166 = F_125 ( V_222 , V_275 , V_4 , V_92 , V_28 ) ;
if ( V_166 <= 0 ) {
if ( V_166 != 0 && V_166 != - V_220 )
F_156 ( V_32 , V_278 ) ;
return F_11 ( V_166 ) ;
}
V_36 = F_140 ( V_222 [ 0 ] , V_92 , V_166 , V_4 , V_277 ) ;
if ( F_15 ( V_36 ) ) {
F_156 ( V_32 , V_279 ) ;
return F_111 ( V_36 ) ;
}
V_231 = (struct V_230 * ) V_36 ;
V_231 -> V_233 = V_166 ;
if ( V_275 > 1 )
V_166 = F_151 ( V_36 , & V_222 [ 1 ] -> V_110 ) ;
else
V_166 = F_152 ( V_36 , V_4 ) ;
if ( F_10 ( V_166 ) ) {
F_133 ( V_36 ) ;
F_156 ( V_32 , V_280 ) ;
return F_11 ( V_166 ) ;
}
V_231 -> V_275 = V_275 ;
memcpy ( V_231 -> V_222 , V_222 , sizeof( struct V_53 * ) * V_275 ) ;
V_231 -> V_281 = F_157 ( & V_222 [ 0 ] -> V_91 ) ;
return V_231 ;
}
static struct V_78 *
F_158 ( struct V_32 * V_32 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_59 ,
struct V_78 * V_282 , void * V_164 )
{
struct V_31 * V_277 = (struct V_31 * ) V_164 ;
struct V_53 * V_222 [ V_178 ] ;
struct V_230 * V_231 , * V_283 ;
int V_275 = 0 , V_233 = 0 , V_116 , V_166 , V_284 ;
V_231 = NULL ;
if ( V_282 ) {
V_231 = F_28 ( V_282 , struct V_230 , V_79 ) ;
V_275 = V_231 -> V_275 ;
V_233 = V_231 -> V_233 ;
V_284 = 0 ;
for ( V_116 = 0 ; V_116 < V_275 ; V_116 ++ ) {
V_222 [ V_116 ] = V_231 -> V_222 [ V_116 ] ;
V_284 |= V_222 [ V_116 ] -> V_61 . V_62 ;
}
if ( V_284 ) {
F_133 ( & V_231 -> V_7 . V_36 ) ;
V_231 = NULL ;
V_275 = 0 ;
V_233 = 0 ;
V_282 = NULL ;
}
}
if ( V_231 == NULL ) {
V_275 = 1 ;
V_222 [ 0 ] = F_107 ( V_32 , V_4 , V_28 , V_59 ) ;
V_166 = F_153 ( V_4 , V_28 , V_222 ,
& V_275 , & V_233 ) ;
if ( V_166 < 0 )
goto V_285;
if ( V_275 == 0 )
return NULL ;
if ( V_233 <= 0 )
goto V_286;
}
V_283 = F_155 ( V_222 , V_275 , V_4 , V_28 , V_277 ) ;
if ( F_15 ( V_283 ) ) {
V_166 = F_142 ( V_283 ) ;
if ( V_166 != - V_220 )
goto error;
if ( V_282 == NULL )
goto V_286;
F_130 ( & V_231 -> V_7 . V_36 ) ;
return V_282 ;
} else if ( V_283 == NULL ) {
V_233 = 0 ;
if ( V_282 == NULL )
goto V_286;
V_231 -> V_233 = 0 ;
F_130 ( & V_231 -> V_7 . V_36 ) ;
return V_282 ;
}
if ( V_231 ) {
V_231 -> V_275 = 0 ;
F_133 ( & V_231 -> V_7 . V_36 ) ;
}
F_130 ( & V_283 -> V_7 . V_36 ) ;
return & V_283 -> V_79 ;
V_286:
V_231 = F_134 ( V_32 , V_28 ) ;
if ( F_15 ( V_231 ) ) {
F_154 ( V_222 , V_275 ) ;
return F_111 ( V_231 ) ;
}
V_231 -> V_275 = V_275 ;
V_231 -> V_233 = V_233 ;
memcpy ( V_231 -> V_222 , V_222 , sizeof( struct V_53 * ) * V_275 ) ;
F_130 ( & V_231 -> V_7 . V_36 ) ;
return & V_231 -> V_79 ;
V_285:
F_156 ( V_32 , V_278 ) ;
error:
if ( V_231 != NULL )
F_133 ( & V_231 -> V_7 . V_36 ) ;
else
F_154 ( V_222 , V_275 ) ;
return F_11 ( V_166 ) ;
}
static struct V_31 * F_159 ( struct V_32 * V_32 , T_5 V_28 ,
struct V_31 * V_277 )
{
struct V_34 * V_35 = F_9 ( V_28 ) ;
struct V_31 * V_167 ;
if ( ! V_35 ) {
F_143 ( V_277 ) ;
return F_11 ( - V_180 ) ;
} else {
V_167 = V_35 -> V_287 ( V_32 , V_277 ) ;
}
F_12 ( V_35 ) ;
return V_167 ;
}
struct V_31 * F_160 ( struct V_32 * V_32 , struct V_31 * V_277 ,
const struct V_3 * V_4 ,
struct V_192 * V_193 , int V_45 )
{
struct V_53 * V_222 [ V_178 ] ;
struct V_78 * V_79 ;
struct V_230 * V_231 ;
struct V_31 * V_36 , * V_232 ;
T_5 V_28 = V_277 -> V_88 -> V_28 ;
T_4 V_59 = F_112 ( V_130 ) ;
int V_116 , V_166 , V_275 , V_233 = 0 , V_288 = 0 ;
V_289:
V_36 = NULL ;
V_231 = NULL ;
V_232 = NULL ;
if ( V_193 && V_193 -> V_194 [ V_130 ] ) {
V_275 = 1 ;
V_222 [ 0 ] = F_113 ( V_193 , V_130 , V_4 ) ;
V_166 = F_153 ( V_4 , V_28 , V_222 ,
& V_275 , & V_233 ) ;
if ( V_166 < 0 )
goto V_290;
if ( V_275 ) {
if ( V_233 <= 0 ) {
V_288 = V_275 ;
goto V_291;
}
V_231 = F_155 (
V_222 , V_275 , V_4 ,
V_28 , V_277 ) ;
if ( F_15 ( V_231 ) ) {
F_154 ( V_222 , V_275 ) ;
V_166 = F_142 ( V_231 ) ;
goto V_290;
} else if ( V_231 == NULL ) {
V_233 = 0 ;
V_288 = V_275 ;
goto V_291;
}
F_130 ( & V_231 -> V_7 . V_36 ) ;
F_161 ( & V_292 ) ;
V_231 -> V_7 . V_36 . V_56 = V_293 ;
V_293 = & V_231 -> V_7 . V_36 ;
F_162 ( & V_292 ) ;
V_232 = V_231 -> V_232 ;
}
}
if ( V_231 == NULL ) {
if ( ( V_277 -> V_45 & V_294 ) ||
! V_32 -> V_92 . V_123 [ V_130 ] )
goto V_295;
V_79 = F_163 ( V_32 , V_4 , V_28 , V_59 ,
F_158 , V_277 ) ;
if ( V_79 == NULL )
goto V_295;
if ( F_15 ( V_79 ) ) {
V_166 = F_142 ( V_79 ) ;
goto V_290;
}
V_231 = F_28 ( V_79 , struct V_230 , V_79 ) ;
V_275 = V_231 -> V_275 ;
V_233 = V_231 -> V_233 ;
memcpy ( V_222 , V_231 -> V_222 , sizeof( struct V_53 * ) * V_275 ) ;
V_232 = V_231 -> V_232 ;
}
V_36 = & V_231 -> V_7 . V_36 ;
if ( V_232 == NULL && V_233 > 0 ) {
if ( V_32 -> V_92 . V_296 ) {
F_143 ( V_36 ) ;
F_154 ( V_222 , V_288 ) ;
F_156 ( V_32 , V_297 ) ;
return F_159 ( V_32 , V_28 , V_277 ) ;
}
if ( V_4 -> V_298 & V_299 ) {
F_164 ( V_300 , V_301 ) ;
F_165 ( & V_32 -> V_92 . V_302 , & V_300 ) ;
F_166 ( V_303 ) ;
F_167 () ;
F_166 ( V_304 ) ;
F_168 ( & V_32 -> V_92 . V_302 , & V_300 ) ;
if ( ! F_169 ( V_301 ) ) {
F_143 ( V_36 ) ;
goto V_289;
}
V_166 = - V_305 ;
} else
V_166 = - V_220 ;
F_156 ( V_32 , V_297 ) ;
goto error;
}
V_291:
if ( V_275 == 0 )
goto V_295;
if ( ( V_45 & V_306 ) &&
! ( V_222 [ 0 ] -> V_45 & V_307 ) ) {
V_166 = - V_168 ;
goto error;
}
for ( V_116 = 0 ; V_116 < V_275 ; V_116 ++ )
V_222 [ V_116 ] -> V_68 . V_72 = F_18 () ;
if ( V_233 < 0 ) {
F_156 ( V_32 , V_308 ) ;
V_166 = - V_309 ;
goto error;
} else if ( V_233 > 0 ) {
F_143 ( V_277 ) ;
} else {
F_143 ( V_36 ) ;
V_36 = V_277 ;
}
V_310:
F_154 ( V_222 , V_288 ) ;
if ( V_36 && V_36 -> V_92 &&
V_36 -> V_92 -> V_43 . V_212 == V_213 )
V_36 -> V_45 |= V_311 ;
return V_36 ;
V_295:
if ( ! ( V_45 & V_306 ) ) {
V_36 = V_277 ;
goto V_310;
}
V_166 = - V_168 ;
error:
F_143 ( V_36 ) ;
V_290:
F_143 ( V_277 ) ;
F_154 ( V_222 , V_288 ) ;
return F_11 ( V_166 ) ;
}
static inline int
F_170 ( int V_145 , struct V_312 * V_313 , const struct V_3 * V_4 )
{
struct V_39 * V_40 ;
if ( ! V_313 -> V_314 || V_145 < 0 || V_145 >= V_313 -> V_314 -> V_151 )
return 0 ;
V_40 = V_313 -> V_314 -> V_315 [ V_145 ] ;
if ( ! V_40 -> type -> V_316 )
return 0 ;
return V_40 -> type -> V_316 ( V_40 , V_313 , V_4 ) ;
}
static inline int
F_171 ( const struct V_204 * V_211 , const struct V_39 * V_40 ,
unsigned short V_28 )
{
if ( F_172 ( V_40 ) )
return V_211 -> V_221 && ! F_173 ( V_211 , V_40 , V_211 -> V_215 ) ;
return V_40 -> V_44 . V_20 == V_211 -> V_44 . V_20 &&
( V_40 -> V_44 . V_317 == V_211 -> V_44 . V_317 || ! V_211 -> V_44 . V_317 ) &&
( V_40 -> V_43 . V_318 == V_211 -> V_318 || ! V_211 -> V_318 ) &&
V_40 -> V_43 . V_212 == V_211 -> V_212 &&
( V_211 -> V_319 || ( V_211 -> V_320 & ( 1 << V_40 -> V_43 . V_321 ) ) ||
! ( F_174 ( V_211 -> V_44 . V_20 , V_322 ) ) ) &&
! ( V_40 -> V_43 . V_212 != V_258 &&
F_173 ( V_211 , V_40 , V_28 ) ) ;
}
static inline int
F_175 ( const struct V_204 * V_211 , const struct V_323 * V_314 , int V_324 ,
unsigned short V_28 )
{
int V_145 = V_324 ;
if ( V_211 -> V_221 ) {
if ( V_211 -> V_212 == V_258 )
return V_324 ;
} else
V_324 = - 1 ;
for (; V_145 < V_314 -> V_151 ; V_145 ++ ) {
if ( F_171 ( V_211 , V_314 -> V_315 [ V_145 ] , V_28 ) )
return ++ V_145 ;
if ( V_314 -> V_315 [ V_145 ] -> V_43 . V_212 != V_258 ) {
if ( V_324 == - 1 )
V_324 = - 2 - V_145 ;
break;
}
}
return V_324 ;
}
int F_176 ( struct V_312 * V_313 , struct V_3 * V_4 ,
unsigned int V_28 , int V_325 )
{
struct V_34 * V_35 = F_9 ( V_28 ) ;
int V_166 ;
if ( F_10 ( V_35 == NULL ) )
return - V_37 ;
V_35 -> V_326 ( V_313 , V_4 , V_325 ) ;
V_166 = F_177 ( V_313 , & V_4 -> V_184 ) ;
F_12 ( V_35 ) ;
return V_166 ;
}
static inline int F_178 ( const struct V_323 * V_314 , int V_327 , int * V_328 )
{
for (; V_327 < V_314 -> V_151 ; V_327 ++ ) {
if ( V_314 -> V_315 [ V_327 ] -> V_43 . V_212 != V_258 ) {
* V_328 = V_327 ;
return 1 ;
}
}
return 0 ;
}
int F_179 ( struct V_192 * V_193 , int V_59 , struct V_312 * V_313 ,
unsigned short V_28 )
{
struct V_32 * V_32 = F_180 ( V_313 -> V_245 ) ;
struct V_53 * V_80 ;
struct V_53 * V_222 [ V_178 ] ;
int V_223 = 0 ;
int V_202 ;
int V_329 ;
int V_325 ;
struct V_3 V_4 ;
T_4 V_330 ;
int V_331 = - 1 ;
V_325 = V_59 & ~ V_332 ;
V_59 &= V_332 ;
V_330 = F_112 ( V_59 ) ;
if ( F_176 ( V_313 , & V_4 , V_28 , V_325 ) < 0 ) {
F_156 ( V_32 , V_333 ) ;
return 0 ;
}
F_181 ( V_313 , & V_4 , V_28 ) ;
if ( V_313 -> V_314 ) {
int V_116 ;
for ( V_116 = V_313 -> V_314 -> V_151 - 1 ; V_116 >= 0 ; V_116 -- ) {
struct V_39 * V_40 = V_313 -> V_314 -> V_315 [ V_116 ] ;
if ( ! F_7 ( & V_40 -> V_2 , & V_4 , V_28 ) ) {
F_156 ( V_32 , V_334 ) ;
return 0 ;
}
}
}
V_80 = NULL ;
if ( V_193 && V_193 -> V_194 [ V_59 ] ) {
V_80 = F_113 ( V_193 , V_59 , & V_4 ) ;
if ( F_15 ( V_80 ) ) {
F_156 ( V_32 , V_335 ) ;
return 0 ;
}
}
if ( ! V_80 ) {
struct V_78 * V_79 ;
V_79 = F_163 ( V_32 , & V_4 , V_28 , V_330 ,
F_109 , NULL ) ;
if ( F_110 ( V_79 ) )
V_80 = F_111 ( V_79 ) ;
else
V_80 = F_28 ( V_79 , struct V_53 , V_79 ) ;
}
if ( F_15 ( V_80 ) ) {
F_156 ( V_32 , V_335 ) ;
return 0 ;
}
if ( ! V_80 ) {
if ( V_313 -> V_314 && F_178 ( V_313 -> V_314 , 0 , & V_331 ) ) {
F_170 ( V_331 , V_313 , & V_4 ) ;
F_156 ( V_32 , V_336 ) ;
return 0 ;
}
return 1 ;
}
V_80 -> V_68 . V_72 = F_18 () ;
V_222 [ 0 ] = V_80 ;
V_223 ++ ;
#ifdef F_108
if ( V_222 [ 0 ] -> type != V_187 ) {
V_222 [ 1 ] = F_104 ( V_32 , V_187 ,
& V_4 , V_28 ,
V_128 ) ;
if ( V_222 [ 1 ] ) {
if ( F_15 ( V_222 [ 1 ] ) ) {
F_156 ( V_32 , V_335 ) ;
return 0 ;
}
V_222 [ 1 ] -> V_68 . V_72 = F_18 () ;
V_223 ++ ;
}
}
#endif
if ( V_80 -> V_201 == V_276 ) {
struct V_323 * V_314 ;
static struct V_323 V_337 ;
struct V_204 * V_224 [ V_225 ] ;
struct V_204 * V_338 [ V_225 ] ;
struct V_204 * * V_226 = V_224 ;
int V_339 = 0 ;
int V_116 , V_327 ;
if ( ( V_314 = V_313 -> V_314 ) == NULL )
V_314 = & V_337 ;
for ( V_329 = 0 ; V_329 < V_223 ; V_329 ++ ) {
if ( V_222 [ V_329 ] != V_80 &&
V_222 [ V_329 ] -> V_201 != V_276 ) {
F_156 ( V_32 , V_340 ) ;
goto V_316;
}
if ( V_339 + V_222 [ V_329 ] -> V_202 >= V_225 ) {
F_156 ( V_32 , V_341 ) ;
goto V_342;
}
for ( V_116 = 0 ; V_116 < V_222 [ V_329 ] -> V_202 ; V_116 ++ )
V_226 [ V_339 ++ ] = & V_222 [ V_329 ] -> V_203 [ V_116 ] ;
}
V_202 = V_339 ;
if ( V_223 > 1 ) {
F_182 ( V_338 , V_226 , V_202 , V_28 ) ;
V_226 = V_338 ;
}
for ( V_116 = V_202 - 1 , V_327 = 0 ; V_116 >= 0 ; V_116 -- ) {
V_327 = F_175 ( V_226 [ V_116 ] , V_314 , V_327 , V_28 ) ;
if ( V_327 < 0 ) {
if ( V_327 < - 1 )
V_331 = - ( 2 + V_327 ) ;
F_156 ( V_32 , V_343 ) ;
goto V_316;
}
}
if ( F_178 ( V_314 , V_327 , & V_331 ) ) {
F_156 ( V_32 , V_343 ) ;
goto V_316;
}
F_154 ( V_222 , V_223 ) ;
return 1 ;
}
F_156 ( V_32 , V_340 ) ;
V_316:
F_170 ( V_331 , V_313 , & V_4 ) ;
V_342:
F_154 ( V_222 , V_223 ) ;
return 0 ;
}
int F_183 ( struct V_312 * V_313 , unsigned short V_28 )
{
struct V_32 * V_32 = F_180 ( V_313 -> V_245 ) ;
struct V_3 V_4 ;
struct V_31 * V_36 ;
int V_344 = 1 ;
if ( F_184 ( V_313 , & V_4 , V_28 ) < 0 ) {
F_156 ( V_32 , V_345 ) ;
return 0 ;
}
F_185 ( V_313 ) ;
V_36 = F_160 ( V_32 , F_186 ( V_313 ) , & V_4 , NULL , 0 ) ;
if ( F_15 ( V_36 ) ) {
V_344 = 0 ;
V_36 = NULL ;
}
F_187 ( V_313 , V_36 ) ;
return V_344 ;
}
static struct V_31 * F_188 ( struct V_31 * V_36 , T_3 V_346 )
{
if ( V_36 -> V_260 < 0 && ! F_129 ( V_36 ) )
return V_36 ;
return NULL ;
}
static int F_129 ( struct V_31 * V_36 )
{
return ! F_189 ( (struct V_230 * ) V_36 ) ;
}
void F_190 ( struct V_31 * V_36 , struct V_244 * V_245 )
{
while ( ( V_36 = V_36 -> V_256 ) && V_36 -> V_92 && V_36 -> V_245 == V_245 ) {
V_36 -> V_245 = F_180 ( V_245 ) -> V_347 ;
F_191 ( V_36 -> V_245 ) ;
F_192 ( V_245 ) ;
}
}
static void F_193 ( struct V_312 * V_313 )
{
}
static struct V_31 * F_194 ( struct V_31 * V_36 )
{
if ( V_36 ) {
if ( V_36 -> V_260 ) {
F_143 ( V_36 ) ;
V_36 = NULL ;
}
}
return V_36 ;
}
static void F_195 ( struct V_32 * V_32 )
{
struct V_31 * V_348 , * V_56 ;
F_161 ( & V_292 ) ;
V_348 = V_293 ;
V_293 = NULL ;
F_162 ( & V_292 ) ;
while ( V_348 ) {
V_56 = V_348 -> V_56 ;
F_133 ( V_348 ) ;
V_348 = V_56 ;
}
}
static void F_196 ( struct V_32 * V_32 )
{
F_197 () ;
F_195 ( V_32 ) ;
}
static void F_198 ( struct V_32 * V_32 )
{
F_199 () ;
F_195 ( V_32 ) ;
}
static void F_148 ( struct V_31 * V_36 )
{
do {
struct V_230 * V_231 = (struct V_230 * ) V_36 ;
T_3 V_349 , V_350 ;
V_349 = F_200 ( V_36 -> V_256 ) ;
V_231 -> V_351 = V_349 ;
V_349 = F_201 ( V_36 -> V_92 , V_349 ) ;
V_350 = F_200 ( V_231 -> V_232 ) ;
V_231 -> V_350 = V_350 ;
if ( V_349 > V_350 )
V_349 = V_350 ;
F_202 ( V_36 , V_352 , V_349 ) ;
} while ( ( V_36 = V_36 -> V_56 ) );
}
static int F_189 ( struct V_230 * V_353 )
{
struct V_31 * V_36 = & V_353 -> V_7 . V_36 ;
struct V_230 * V_354 ;
T_3 V_355 ;
if ( ! F_203 ( V_36 -> V_241 , ( (struct V_230 * ) V_36 ) -> V_356 ) ||
( V_36 -> V_245 && ! F_204 ( V_36 -> V_245 ) ) )
return 0 ;
V_354 = NULL ;
do {
struct V_230 * V_231 = (struct V_230 * ) V_36 ;
if ( V_36 -> V_92 -> V_216 . V_217 != V_218 )
return 0 ;
if ( V_231 -> V_259 != V_36 -> V_92 -> V_91 )
return 0 ;
if ( V_231 -> V_275 > 0 &&
V_231 -> V_281 != F_157 ( & V_231 -> V_222 [ 0 ] -> V_91 ) )
return 0 ;
V_355 = F_200 ( V_36 -> V_256 ) ;
if ( V_231 -> V_351 != V_355 ) {
V_354 = V_231 ;
V_231 -> V_351 = V_355 ;
}
if ( ! F_203 ( V_231 -> V_232 , V_231 -> V_357 ) )
return 0 ;
V_355 = F_200 ( V_231 -> V_232 ) ;
if ( V_231 -> V_350 != V_355 ) {
V_354 = V_231 ;
V_231 -> V_350 = V_355 ;
}
V_36 = V_36 -> V_256 ;
} while ( V_36 -> V_92 );
if ( F_137 ( ! V_354 ) )
return 1 ;
V_355 = V_354 -> V_351 ;
for (; ; ) {
V_36 = & V_354 -> V_7 . V_36 ;
V_355 = F_201 ( V_36 -> V_92 , V_355 ) ;
if ( V_355 > V_354 -> V_350 )
V_355 = V_354 -> V_350 ;
F_202 ( V_36 , V_352 , V_355 ) ;
if ( V_354 == V_353 )
break;
V_354 = (struct V_230 * ) V_354 -> V_7 . V_36 . V_56 ;
V_354 -> V_351 = V_355 ;
}
return 1 ;
}
static unsigned int F_205 ( const struct V_31 * V_36 )
{
return F_206 ( V_36 -> V_241 ) ;
}
static unsigned int F_207 ( const struct V_31 * V_36 )
{
unsigned int V_355 = F_208 ( V_36 , V_352 ) ;
return V_355 ? : F_200 ( V_36 -> V_241 ) ;
}
static struct V_358 * F_209 ( const struct V_31 * V_36 ,
struct V_312 * V_313 ,
const void * V_9 )
{
return V_36 -> V_241 -> V_88 -> V_359 ( V_36 , V_313 , V_9 ) ;
}
int F_210 ( struct V_34 * V_35 )
{
struct V_32 * V_32 ;
int V_166 = 0 ;
if ( F_10 ( V_35 == NULL ) )
return - V_180 ;
if ( F_10 ( V_35 -> V_28 >= V_360 ) )
return - V_37 ;
F_63 ( & V_361 ) ;
if ( F_10 ( V_34 [ V_35 -> V_28 ] != NULL ) )
V_166 = - V_228 ;
else {
struct V_234 * V_234 = V_35 -> V_234 ;
if ( F_137 ( V_234 -> V_362 == NULL ) )
V_234 -> V_362 = V_363 ;
if ( F_137 ( V_234 -> V_364 == NULL ) )
V_234 -> V_364 = F_188 ;
if ( F_137 ( V_234 -> V_365 == NULL ) )
V_234 -> V_365 = F_205 ;
if ( F_137 ( V_234 -> V_355 == NULL ) )
V_234 -> V_355 = F_207 ;
if ( F_137 ( V_234 -> V_366 == NULL ) )
V_234 -> V_366 = F_194 ;
if ( F_137 ( V_234 -> V_367 == NULL ) )
V_234 -> V_367 = F_193 ;
if ( F_137 ( V_234 -> V_359 == NULL ) )
V_234 -> V_359 = F_209 ;
if ( F_137 ( V_35 -> V_368 == NULL ) )
V_35 -> V_368 = F_198 ;
V_34 [ V_35 -> V_28 ] = V_35 ;
}
F_64 ( & V_361 ) ;
F_211 () ;
F_212 (net) {
struct V_234 * V_369 ;
switch ( V_35 -> V_28 ) {
case V_29 :
V_369 = & V_32 -> V_92 . V_235 ;
break;
#if F_135 ( V_236 )
case V_30 :
V_369 = & V_32 -> V_92 . V_237 ;
break;
#endif
default:
F_42 () ;
}
* V_369 = * V_35 -> V_234 ;
}
F_213 () ;
return V_166 ;
}
int F_214 ( struct V_34 * V_35 )
{
int V_166 = 0 ;
if ( F_10 ( V_35 == NULL ) )
return - V_180 ;
if ( F_10 ( V_35 -> V_28 >= V_360 ) )
return - V_37 ;
F_63 ( & V_361 ) ;
if ( F_137 ( V_34 [ V_35 -> V_28 ] != NULL ) ) {
if ( F_10 ( V_34 [ V_35 -> V_28 ] != V_35 ) )
V_166 = - V_180 ;
else {
struct V_234 * V_234 = V_35 -> V_234 ;
V_34 [ V_35 -> V_28 ] = NULL ;
V_234 -> V_362 = NULL ;
V_234 -> V_364 = NULL ;
V_234 -> V_366 = NULL ;
V_234 -> V_367 = NULL ;
V_35 -> V_368 = NULL ;
}
}
F_64 ( & V_361 ) ;
return V_166 ;
}
static void T_6 F_215 ( struct V_32 * V_32 )
{
struct V_34 * V_35 ;
F_70 ( & V_361 ) ;
V_35 = V_34 [ V_29 ] ;
if ( V_35 )
V_32 -> V_92 . V_235 = * V_35 -> V_234 ;
#if F_135 ( V_236 )
V_35 = V_34 [ V_30 ] ;
if ( V_35 )
V_32 -> V_92 . V_237 = * V_35 -> V_234 ;
#endif
F_71 ( & V_361 ) ;
}
static struct V_34 * F_9 ( unsigned short V_28 )
{
struct V_34 * V_35 ;
if ( F_10 ( V_28 >= V_360 ) )
return NULL ;
F_19 ( & V_361 ) ;
V_35 = V_34 [ V_28 ] ;
if ( F_10 ( ! V_35 ) )
F_24 ( & V_361 ) ;
return V_35 ;
}
static void F_12 ( struct V_34 * V_35 )
{
F_24 ( & V_361 ) ;
}
static int F_216 ( struct V_370 * V_371 , unsigned long V_372 , void * V_373 )
{
struct V_244 * V_245 = V_373 ;
switch ( V_372 ) {
case V_374 :
F_196 ( F_180 ( V_245 ) ) ;
}
return V_375 ;
}
static int T_6 F_217 ( struct V_32 * V_32 )
{
int V_376 ;
if ( F_218 ( ( void V_377 * * ) V_32 -> V_378 . V_379 ,
sizeof( struct V_380 ) ,
F_219 ( struct V_380 ) ) < 0 )
return - V_206 ;
V_376 = F_220 ( V_32 ) ;
if ( V_376 < 0 )
F_221 ( ( void V_377 * * ) V_32 -> V_378 . V_379 ) ;
return V_376 ;
}
static void F_222 ( struct V_32 * V_32 )
{
F_223 ( V_32 ) ;
F_221 ( ( void V_377 * * ) V_32 -> V_378 . V_379 ) ;
}
static int T_6 F_217 ( struct V_32 * V_32 )
{
return 0 ;
}
static void F_222 ( struct V_32 * V_32 )
{
}
static int T_6 F_224 ( struct V_32 * V_32 )
{
unsigned int V_95 , V_381 ;
int V_59 ;
if ( F_225 ( V_32 , & V_382 ) )
V_363 = F_226 ( L_1 ,
sizeof( struct V_230 ) ,
0 , V_383 | V_384 ,
NULL ) ;
V_95 = 8 - 1 ;
V_381 = ( V_95 + 1 ) * sizeof( struct V_94 ) ;
V_32 -> V_92 . V_120 = F_62 ( V_381 ) ;
if ( ! V_32 -> V_92 . V_120 )
goto V_385;
V_32 -> V_92 . V_93 = V_95 ;
for ( V_59 = 0 ; V_59 < V_134 * 2 ; V_59 ++ ) {
struct V_386 * V_387 ;
V_32 -> V_92 . V_123 [ V_59 ] = 0 ;
F_227 ( & V_32 -> V_92 . V_98 [ V_59 ] ) ;
V_387 = & V_32 -> V_92 . V_96 [ V_59 ] ;
V_387 -> V_99 = F_62 ( V_381 ) ;
if ( ! V_387 -> V_99 )
goto V_388;
V_387 -> V_95 = V_95 ;
}
F_34 ( & V_32 -> V_92 . V_162 ) ;
F_228 ( & V_32 -> V_92 . V_141 , F_72 ) ;
if ( F_225 ( V_32 , & V_382 ) )
F_229 ( & V_389 ) ;
return 0 ;
V_388:
for ( V_59 -- ; V_59 >= 0 ; V_59 -- ) {
struct V_386 * V_387 ;
V_387 = & V_32 -> V_92 . V_96 [ V_59 ] ;
F_65 ( V_387 -> V_99 , V_381 ) ;
}
F_65 ( V_32 -> V_92 . V_120 , V_381 ) ;
V_385:
return - V_206 ;
}
static void F_230 ( struct V_32 * V_32 )
{
struct V_169 V_170 ;
unsigned int V_381 ;
int V_59 ;
F_231 ( & V_32 -> V_92 . V_141 ) ;
#ifdef F_108
V_170 . V_171 = - 1 ;
V_170 . V_172 = - 1 ;
V_170 . V_173 = 0 ;
F_90 ( V_32 , V_186 , & V_170 ) ;
#endif
V_170 . V_171 = - 1 ;
V_170 . V_172 = - 1 ;
V_170 . V_173 = 0 ;
F_90 ( V_32 , V_187 , & V_170 ) ;
F_80 ( ! F_93 ( & V_32 -> V_92 . V_162 ) ) ;
for ( V_59 = 0 ; V_59 < V_134 * 2 ; V_59 ++ ) {
struct V_386 * V_387 ;
F_80 ( ! F_58 ( & V_32 -> V_92 . V_98 [ V_59 ] ) ) ;
V_387 = & V_32 -> V_92 . V_96 [ V_59 ] ;
V_381 = ( V_387 -> V_95 + 1 ) ;
F_80 ( ! F_58 ( V_387 -> V_99 ) ) ;
F_65 ( V_387 -> V_99 , V_381 ) ;
}
V_381 = ( V_32 -> V_92 . V_93 + 1 ) * sizeof( struct V_94 ) ;
F_80 ( ! F_58 ( V_32 -> V_92 . V_120 ) ) ;
F_65 ( V_32 -> V_92 . V_120 , V_381 ) ;
}
static int T_6 F_232 ( struct V_32 * V_32 )
{
int V_376 ;
V_376 = F_217 ( V_32 ) ;
if ( V_376 < 0 )
goto V_390;
V_376 = F_233 ( V_32 ) ;
if ( V_376 < 0 )
goto V_391;
V_376 = F_224 ( V_32 ) ;
if ( V_376 < 0 )
goto V_392;
F_215 ( V_32 ) ;
V_376 = F_234 ( V_32 ) ;
if ( V_376 < 0 )
goto V_393;
return 0 ;
V_393:
F_230 ( V_32 ) ;
V_392:
F_235 ( V_32 ) ;
V_391:
F_222 ( V_32 ) ;
V_390:
return V_376 ;
}
static void T_7 F_236 ( struct V_32 * V_32 )
{
F_237 ( V_32 ) ;
F_230 ( V_32 ) ;
F_235 ( V_32 ) ;
F_222 ( V_32 ) ;
}
void T_8 F_238 ( void )
{
F_239 ( & V_394 ) ;
F_240 () ;
}
static void F_241 ( struct V_53 * V_54 ,
struct V_395 * V_396 )
{
struct V_163 * V_164 = V_54 -> V_90 ;
struct V_1 * V_2 = & V_54 -> V_110 ;
if ( V_164 )
F_242 ( V_396 , L_2 ,
V_164 -> V_397 , V_164 -> V_398 , V_164 -> V_399 ) ;
switch( V_2 -> V_28 ) {
case V_29 :
F_242 ( V_396 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_242 ( V_396 , L_4 ,
V_2 -> V_13 ) ;
F_242 ( V_396 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_242 ( V_396 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_242 ( V_396 , L_7 , V_2 -> V_12 . V_400 ) ;
if ( V_2 -> V_13 != 128 )
F_242 ( V_396 , L_4 ,
V_2 -> V_13 ) ;
F_242 ( V_396 , L_8 , V_2 -> V_9 . V_400 ) ;
if ( V_2 -> V_11 != 128 )
F_242 ( V_396 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_243 ( struct V_53 * V_54 , int V_401 ,
T_9 V_402 , T_3 V_172 , T_3 V_173 )
{
struct V_395 * V_396 ;
V_396 = F_244 ( L_9 ) ;
if ( V_396 == NULL )
return;
F_245 ( V_402 , V_172 , V_173 , V_396 ) ;
F_242 ( V_396 , L_10 , V_401 ) ;
F_241 ( V_54 , V_396 ) ;
F_246 ( V_396 ) ;
}
void F_89 ( struct V_53 * V_54 , int V_401 ,
T_9 V_402 , T_3 V_172 , T_3 V_173 )
{
struct V_395 * V_396 ;
V_396 = F_244 ( L_11 ) ;
if ( V_396 == NULL )
return;
F_245 ( V_402 , V_172 , V_173 , V_396 ) ;
F_242 ( V_396 , L_10 , V_401 ) ;
F_241 ( V_54 , V_396 ) ;
F_246 ( V_396 ) ;
}
static bool F_247 ( const struct V_1 * V_403 ,
const struct V_1 * V_404 )
{
if ( V_403 -> V_20 == V_405 ) {
if ( V_404 -> V_28 == V_403 -> V_28 &&
F_248 ( & V_404 -> V_9 , & V_403 -> V_9 ,
V_403 -> V_28 ) == 0 &&
F_248 ( & V_404 -> V_12 , & V_403 -> V_12 ,
V_403 -> V_28 ) == 0 &&
V_404 -> V_11 == V_403 -> V_11 &&
V_404 -> V_13 == V_403 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_404 , V_403 , sizeof( * V_404 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_53 * F_249 ( const struct V_1 * V_2 ,
T_4 V_59 , T_4 type )
{
struct V_53 * V_80 , * V_167 = NULL ;
struct V_103 * V_104 ;
struct V_94 * V_154 ;
T_3 V_160 = ~ 0U ;
F_70 ( & V_117 ) ;
V_154 = F_51 ( & V_382 , & V_2 -> V_9 , & V_2 -> V_12 , V_2 -> V_28 , V_59 ) ;
F_76 (pol, entry, chain, bydst) {
if ( F_247 ( V_2 , & V_80 -> V_110 ) &&
V_80 -> type == type ) {
V_167 = V_80 ;
V_160 = V_167 -> V_160 ;
break;
}
}
V_154 = & V_382 . V_92 . V_98 [ V_59 ] ;
F_76 (pol, entry, chain, bydst) {
if ( F_247 ( V_2 , & V_80 -> V_110 ) &&
V_80 -> type == type &&
V_80 -> V_160 < V_160 ) {
V_167 = V_80 ;
break;
}
}
if ( V_167 )
F_23 ( V_167 ) ;
F_71 ( & V_117 ) ;
return V_167 ;
}
static int F_250 ( const struct V_406 * V_158 , const struct V_204 * V_407 )
{
int V_182 = 0 ;
if ( V_407 -> V_212 == V_158 -> V_212 && V_407 -> V_44 . V_20 == V_158 -> V_20 &&
( V_158 -> V_318 == 0 || V_407 -> V_318 == V_158 -> V_318 ) ) {
switch ( V_407 -> V_212 ) {
case V_213 :
case V_214 :
if ( F_248 ( & V_407 -> V_44 . V_9 , & V_158 -> V_408 ,
V_158 -> V_409 ) == 0 &&
F_248 ( & V_407 -> V_12 , & V_158 -> V_410 ,
V_158 -> V_409 ) == 0 ) {
V_182 = 1 ;
}
break;
case V_258 :
V_182 = 1 ;
break;
default:
break;
}
}
return V_182 ;
}
static int F_251 ( struct V_53 * V_80 ,
struct V_406 * V_158 , int V_411 )
{
struct V_406 * V_412 ;
int V_116 , V_413 , V_414 = 0 ;
F_63 ( & V_80 -> V_60 ) ;
if ( F_10 ( V_80 -> V_61 . V_62 ) ) {
F_64 ( & V_80 -> V_60 ) ;
return - V_168 ;
}
for ( V_116 = 0 ; V_116 < V_80 -> V_202 ; V_116 ++ ) {
for ( V_413 = 0 , V_412 = V_158 ; V_413 < V_411 ; V_413 ++ , V_412 ++ ) {
if ( ! F_250 ( V_412 , & V_80 -> V_203 [ V_116 ] ) )
continue;
V_414 ++ ;
if ( V_80 -> V_203 [ V_116 ] . V_212 != V_213 &&
V_80 -> V_203 [ V_116 ] . V_212 != V_214 )
continue;
memcpy ( & V_80 -> V_203 [ V_116 ] . V_44 . V_9 , & V_412 -> V_415 ,
sizeof( V_80 -> V_203 [ V_116 ] . V_44 . V_9 ) ) ;
memcpy ( & V_80 -> V_203 [ V_116 ] . V_12 , & V_412 -> V_416 ,
sizeof( V_80 -> V_203 [ V_116 ] . V_12 ) ) ;
V_80 -> V_203 [ V_116 ] . V_215 = V_412 -> V_417 ;
F_46 ( & V_80 -> V_91 ) ;
}
}
F_64 ( & V_80 -> V_60 ) ;
if ( ! V_414 )
return - V_418 ;
return 0 ;
}
static int F_252 ( const struct V_406 * V_158 , int V_411 )
{
int V_116 , V_413 ;
if ( V_411 < 1 || V_411 > V_225 )
return - V_180 ;
for ( V_116 = 0 ; V_116 < V_411 ; V_116 ++ ) {
if ( ( F_248 ( & V_158 [ V_116 ] . V_408 , & V_158 [ V_116 ] . V_415 ,
V_158 [ V_116 ] . V_409 ) == 0 ) &&
( F_248 ( & V_158 [ V_116 ] . V_410 , & V_158 [ V_116 ] . V_416 ,
V_158 [ V_116 ] . V_409 ) == 0 ) )
return - V_180 ;
if ( F_122 ( & V_158 [ V_116 ] . V_415 , V_158 [ V_116 ] . V_417 ) ||
F_122 ( & V_158 [ V_116 ] . V_416 , V_158 [ V_116 ] . V_417 ) )
return - V_180 ;
for ( V_413 = V_116 + 1 ; V_413 < V_411 ; V_413 ++ ) {
if ( ! memcmp ( & V_158 [ V_116 ] . V_408 , & V_158 [ V_413 ] . V_408 ,
sizeof( V_158 [ V_116 ] . V_408 ) ) &&
! memcmp ( & V_158 [ V_116 ] . V_410 , & V_158 [ V_413 ] . V_410 ,
sizeof( V_158 [ V_116 ] . V_410 ) ) &&
V_158 [ V_116 ] . V_20 == V_158 [ V_413 ] . V_20 &&
V_158 [ V_116 ] . V_212 == V_158 [ V_413 ] . V_212 &&
V_158 [ V_116 ] . V_318 == V_158 [ V_413 ] . V_318 &&
V_158 [ V_116 ] . V_409 == V_158 [ V_413 ] . V_409 )
return - V_180 ;
}
}
return 0 ;
}
int V_406 ( const struct V_1 * V_2 , T_4 V_59 , T_4 type ,
struct V_406 * V_158 , int V_411 ,
struct V_419 * V_327 )
{
int V_116 , V_166 , V_420 = 0 , V_421 = 0 ;
struct V_53 * V_80 = NULL ;
struct V_39 * V_40 , * V_422 ;
struct V_39 * V_423 [ V_225 ] ;
struct V_39 * V_424 [ V_225 ] ;
struct V_406 * V_412 ;
if ( ( V_166 = F_252 ( V_158 , V_411 ) ) < 0 )
goto V_63;
if ( ( V_80 = F_249 ( V_2 , V_59 , type ) ) == NULL ) {
V_166 = - V_168 ;
goto V_63;
}
for ( V_116 = 0 , V_412 = V_158 ; V_116 < V_411 ; V_116 ++ , V_412 ++ ) {
if ( ( V_40 = F_253 ( V_412 ) ) ) {
V_423 [ V_420 ] = V_40 ;
V_420 ++ ;
if ( ( V_422 = F_254 ( V_40 , V_412 ) ) ) {
V_424 [ V_421 ] = V_422 ;
V_421 ++ ;
} else {
V_166 = - V_418 ;
goto V_425;
}
}
}
if ( ( V_166 = F_251 ( V_80 , V_158 , V_411 ) ) < 0 )
goto V_425;
if ( V_420 ) {
F_255 ( V_423 , V_420 ) ;
F_256 ( V_423 , V_420 ) ;
}
F_257 ( V_2 , V_59 , type , V_158 , V_411 , V_327 ) ;
F_25 ( V_80 ) ;
return 0 ;
V_63:
return V_166 ;
V_425:
if ( V_80 )
F_25 ( V_80 ) ;
if ( V_420 )
F_255 ( V_423 , V_420 ) ;
if ( V_421 )
F_256 ( V_424 , V_421 ) ;
return V_166 ;
}
