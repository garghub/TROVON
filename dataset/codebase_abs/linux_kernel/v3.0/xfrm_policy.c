static inline int
F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = & V_4 -> V_7 . V_8 ;
return F_2 ( & V_6 -> V_9 , & V_2 -> V_9 , V_2 -> V_10 ) &&
F_2 ( & V_6 -> V_11 , & V_2 -> V_11 , V_2 -> V_12 ) &&
! ( ( F_3 ( V_4 , & V_6 -> V_13 ) ^ V_2 -> V_14 ) & V_2 -> V_15 ) &&
! ( ( F_4 ( V_4 , & V_6 -> V_13 ) ^ V_2 -> V_16 ) & V_2 -> V_17 ) &&
( V_6 -> V_18 == V_2 -> V_19 || ! V_2 -> V_19 ) &&
( V_6 -> V_20 == V_2 -> V_21 || ! V_2 -> V_21 ) ;
}
static inline int
F_5 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_22 * V_23 = & V_4 -> V_7 . V_24 ;
return F_2 ( & V_23 -> V_9 , & V_2 -> V_9 , V_2 -> V_10 ) &&
F_2 ( & V_23 -> V_11 , & V_2 -> V_11 , V_2 -> V_12 ) &&
! ( ( F_3 ( V_4 , & V_23 -> V_13 ) ^ V_2 -> V_14 ) & V_2 -> V_15 ) &&
! ( ( F_4 ( V_4 , & V_23 -> V_13 ) ^ V_2 -> V_16 ) & V_2 -> V_17 ) &&
( V_23 -> V_25 == V_2 -> V_19 || ! V_2 -> V_19 ) &&
( V_23 -> V_26 == V_2 -> V_21 || ! V_2 -> V_21 ) ;
}
int F_6 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned short V_27 )
{
switch ( V_27 ) {
case V_28 :
return F_1 ( V_2 , V_4 ) ;
case V_29 :
return F_5 ( V_2 , V_4 ) ;
}
return 0 ;
}
static inline struct V_30 * F_7 ( struct V_31 * V_31 , int V_32 ,
const T_1 * V_11 ,
const T_1 * V_9 ,
int V_27 )
{
struct V_33 * V_34 ;
struct V_30 * V_35 ;
V_34 = F_8 ( V_27 ) ;
if ( F_9 ( V_34 == NULL ) )
return F_10 ( - V_36 ) ;
V_35 = V_34 -> V_37 ( V_31 , V_32 , V_11 , V_9 ) ;
F_11 ( V_34 ) ;
return V_35 ;
}
static inline struct V_30 * F_12 ( struct V_38 * V_39 , int V_32 ,
T_1 * V_40 ,
T_1 * V_41 ,
int V_27 )
{
struct V_31 * V_31 = F_13 ( V_39 ) ;
T_1 * V_11 = & V_39 -> V_42 . V_11 ;
T_1 * V_9 = & V_39 -> V_43 . V_9 ;
struct V_30 * V_35 ;
if ( V_39 -> type -> V_44 & V_45 ) {
V_11 = V_39 -> V_46 ;
V_9 = V_41 ;
}
if ( V_39 -> type -> V_44 & V_47 ) {
V_11 = V_40 ;
V_9 = V_39 -> V_46 ;
}
V_35 = F_7 ( V_31 , V_32 , V_11 , V_9 , V_27 ) ;
if ( ! F_14 ( V_35 ) ) {
if ( V_40 != V_11 )
memcpy ( V_40 , V_11 , sizeof( * V_40 ) ) ;
if ( V_41 != V_9 )
memcpy ( V_41 , V_9 , sizeof( * V_41 ) ) ;
}
return V_35 ;
}
static inline unsigned long F_15 ( long V_48 )
{
if ( V_48 >= ( V_49 - 1 ) / V_50 )
return V_49 - 1 ;
else
return V_48 * V_50 ;
}
static void F_16 ( unsigned long V_51 )
{
struct V_52 * V_53 = (struct V_52 * ) V_51 ;
unsigned long V_54 = F_17 () ;
long V_55 = V_56 ;
int V_57 = 0 ;
int V_58 ;
F_18 ( & V_53 -> V_59 ) ;
if ( F_9 ( V_53 -> V_60 . V_61 ) )
goto V_62;
V_58 = F_19 ( V_53 -> V_63 ) ;
if ( V_53 -> V_64 . V_65 ) {
long V_66 = V_53 -> V_64 . V_65 +
V_53 -> V_67 . V_68 - V_54 ;
if ( V_66 <= 0 )
goto V_69;
if ( V_66 < V_55 )
V_55 = V_66 ;
}
if ( V_53 -> V_64 . V_70 ) {
long V_66 = V_53 -> V_64 . V_70 +
( V_53 -> V_67 . V_71 ? : V_53 -> V_67 . V_68 ) - V_54 ;
if ( V_66 <= 0 )
goto V_69;
if ( V_66 < V_55 )
V_55 = V_66 ;
}
if ( V_53 -> V_64 . V_72 ) {
long V_66 = V_53 -> V_64 . V_72 +
V_53 -> V_67 . V_68 - V_54 ;
if ( V_66 <= 0 ) {
V_57 = 1 ;
V_66 = V_73 ;
}
if ( V_66 < V_55 )
V_55 = V_66 ;
}
if ( V_53 -> V_64 . V_74 ) {
long V_66 = V_53 -> V_64 . V_74 +
( V_53 -> V_67 . V_71 ? : V_53 -> V_67 . V_68 ) - V_54 ;
if ( V_66 <= 0 ) {
V_57 = 1 ;
V_66 = V_73 ;
}
if ( V_66 < V_55 )
V_55 = V_66 ;
}
if ( V_57 )
F_20 ( V_53 , V_58 , 0 , 0 ) ;
if ( V_55 != V_56 &&
! F_21 ( & V_53 -> V_75 , V_76 + F_15 ( V_55 ) ) )
F_22 ( V_53 ) ;
V_62:
F_23 ( & V_53 -> V_59 ) ;
F_24 ( V_53 ) ;
return;
V_69:
F_23 ( & V_53 -> V_59 ) ;
if ( ! F_25 ( V_53 , V_58 ) )
F_20 ( V_53 , V_58 , 1 , 0 ) ;
F_24 ( V_53 ) ;
}
static struct V_77 * F_26 ( struct V_77 * V_78 )
{
struct V_52 * V_79 = F_27 ( V_78 , struct V_52 , V_78 ) ;
if ( F_9 ( V_79 -> V_60 . V_61 ) )
V_78 = NULL ;
else
F_22 ( V_79 ) ;
return V_78 ;
}
static int F_28 ( struct V_77 * V_78 )
{
struct V_52 * V_79 = F_27 ( V_78 , struct V_52 , V_78 ) ;
return ! V_79 -> V_60 . V_61 ;
}
static void F_29 ( struct V_77 * V_78 )
{
F_24 ( F_27 ( V_78 , struct V_52 , V_78 ) ) ;
}
struct V_52 * F_30 ( struct V_31 * V_31 , T_2 V_80 )
{
struct V_52 * V_81 ;
V_81 = F_31 ( sizeof( struct V_52 ) , V_80 ) ;
if ( V_81 ) {
F_32 ( & V_81 -> V_82 , V_31 ) ;
F_33 ( & V_81 -> V_60 . V_83 ) ;
F_34 ( & V_81 -> V_84 ) ;
F_34 ( & V_81 -> V_85 ) ;
F_35 ( & V_81 -> V_59 ) ;
F_36 ( & V_81 -> V_86 , 1 ) ;
F_37 ( & V_81 -> V_75 , F_16 ,
( unsigned long ) V_81 ) ;
V_81 -> V_78 . V_87 = & V_88 ;
}
return V_81 ;
}
void F_38 ( struct V_52 * V_81 )
{
F_39 ( ! V_81 -> V_60 . V_61 ) ;
if ( F_40 ( & V_81 -> V_75 ) )
F_41 () ;
F_42 ( V_81 -> V_89 ) ;
F_43 ( V_81 ) ;
}
static void F_44 ( struct V_52 * V_81 )
{
V_81 -> V_60 . V_61 = 1 ;
F_45 ( & V_81 -> V_90 ) ;
if ( F_40 ( & V_81 -> V_75 ) )
F_24 ( V_81 ) ;
F_24 ( V_81 ) ;
}
static inline unsigned int F_46 ( struct V_31 * V_31 , T_3 V_63 )
{
return F_47 ( V_63 , V_31 -> V_91 . V_92 ) ;
}
static struct V_93 * F_48 ( struct V_31 * V_31 ,
const struct V_1 * V_2 ,
unsigned short V_27 , int V_58 )
{
unsigned int V_94 = V_31 -> V_91 . V_95 [ V_58 ] . V_94 ;
unsigned int V_96 = F_49 ( V_2 , V_27 , V_94 ) ;
return ( V_96 == V_94 + 1 ?
& V_31 -> V_91 . V_97 [ V_58 ] :
V_31 -> V_91 . V_95 [ V_58 ] . V_98 + V_96 ) ;
}
static struct V_93 * F_50 ( struct V_31 * V_31 ,
const T_1 * V_9 ,
const T_1 * V_11 ,
unsigned short V_27 , int V_58 )
{
unsigned int V_94 = V_31 -> V_91 . V_95 [ V_58 ] . V_94 ;
unsigned int V_96 = F_51 ( V_9 , V_11 , V_27 , V_94 ) ;
return V_31 -> V_91 . V_95 [ V_58 ] . V_98 + V_96 ;
}
static void F_52 ( struct V_93 * V_99 ,
struct V_93 * V_100 ,
unsigned int V_101 )
{
struct V_102 * V_103 , * V_104 , * V_105 = NULL ;
struct V_52 * V_79 ;
unsigned int V_106 = 0 ;
V_107:
F_53 (pol, entry, tmp, list, bydst) {
unsigned int V_108 ;
V_108 = F_51 ( & V_79 -> V_109 . V_9 , & V_79 -> V_109 . V_11 ,
V_79 -> V_27 , V_101 ) ;
if ( ! V_105 ) {
F_54 ( V_103 ) ;
F_55 ( & V_79 -> V_84 , V_100 + V_108 ) ;
V_106 = V_108 ;
} else {
if ( V_108 != V_106 )
continue;
F_54 ( V_103 ) ;
F_56 ( V_105 , & V_79 -> V_84 ) ;
}
V_105 = V_103 ;
}
if ( ! F_57 ( V_99 ) ) {
V_105 = NULL ;
goto V_107;
}
}
static void F_58 ( struct V_93 * V_99 ,
struct V_93 * V_110 ,
unsigned int V_101 )
{
struct V_102 * V_103 , * V_104 ;
struct V_52 * V_79 ;
F_53 (pol, entry, tmp, list, byidx) {
unsigned int V_108 ;
V_108 = F_47 ( V_79 -> V_63 , V_101 ) ;
F_55 ( & V_79 -> V_85 , V_110 + V_108 ) ;
}
}
static unsigned long F_59 ( unsigned int V_111 )
{
return ( ( V_111 + 1 ) << 1 ) - 1 ;
}
static void F_60 ( struct V_31 * V_31 , int V_58 )
{
unsigned int V_94 = V_31 -> V_91 . V_95 [ V_58 ] . V_94 ;
unsigned int V_101 = F_59 ( V_94 ) ;
unsigned int V_112 = ( V_101 + 1 ) * sizeof( struct V_93 ) ;
struct V_93 * V_113 = V_31 -> V_91 . V_95 [ V_58 ] . V_98 ;
struct V_93 * V_114 = F_61 ( V_112 ) ;
int V_115 ;
if ( ! V_114 )
return;
F_62 ( & V_116 ) ;
for ( V_115 = V_94 ; V_115 >= 0 ; V_115 -- )
F_52 ( V_113 + V_115 , V_114 , V_101 ) ;
V_31 -> V_91 . V_95 [ V_58 ] . V_98 = V_114 ;
V_31 -> V_91 . V_95 [ V_58 ] . V_94 = V_101 ;
F_63 ( & V_116 ) ;
F_64 ( V_113 , ( V_94 + 1 ) * sizeof( struct V_93 ) ) ;
}
static void F_65 ( struct V_31 * V_31 , int V_117 )
{
unsigned int V_94 = V_31 -> V_91 . V_92 ;
unsigned int V_101 = F_59 ( V_94 ) ;
unsigned int V_112 = ( V_101 + 1 ) * sizeof( struct V_93 ) ;
struct V_93 * V_118 = V_31 -> V_91 . V_119 ;
struct V_93 * V_120 = F_61 ( V_112 ) ;
int V_115 ;
if ( ! V_120 )
return;
F_62 ( & V_116 ) ;
for ( V_115 = V_94 ; V_115 >= 0 ; V_115 -- )
F_58 ( V_118 + V_115 , V_120 , V_101 ) ;
V_31 -> V_91 . V_119 = V_120 ;
V_31 -> V_91 . V_92 = V_101 ;
F_63 ( & V_116 ) ;
F_64 ( V_118 , ( V_94 + 1 ) * sizeof( struct V_93 ) ) ;
}
static inline int F_66 ( struct V_31 * V_31 , int V_58 , int * V_117 )
{
unsigned int V_121 = V_31 -> V_91 . V_122 [ V_58 ] ;
unsigned int V_94 = V_31 -> V_91 . V_95 [ V_58 ] . V_94 ;
if ( V_117 )
* V_117 += V_121 ;
if ( ( V_94 + 1 ) < V_123 &&
V_121 > V_94 )
return 1 ;
return 0 ;
}
static inline int F_67 ( struct V_31 * V_31 , int V_117 )
{
unsigned int V_94 = V_31 -> V_91 . V_92 ;
if ( ( V_94 + 1 ) < V_123 &&
V_117 > V_94 )
return 1 ;
return 0 ;
}
void F_68 ( struct V_31 * V_31 , struct V_124 * V_125 )
{
F_69 ( & V_116 ) ;
V_125 -> V_126 = V_31 -> V_91 . V_122 [ V_127 ] ;
V_125 -> V_128 = V_31 -> V_91 . V_122 [ V_129 ] ;
V_125 -> V_130 = V_31 -> V_91 . V_122 [ V_131 ] ;
V_125 -> V_132 = V_31 -> V_91 . V_122 [ V_127 + V_133 ] ;
V_125 -> V_134 = V_31 -> V_91 . V_122 [ V_129 + V_133 ] ;
V_125 -> V_135 = V_31 -> V_91 . V_122 [ V_131 + V_133 ] ;
V_125 -> V_136 = V_31 -> V_91 . V_92 ;
V_125 -> V_137 = V_123 ;
F_70 ( & V_116 ) ;
}
static void F_71 ( struct V_138 * V_139 )
{
struct V_31 * V_31 = F_27 ( V_139 , struct V_31 , V_91 . V_140 ) ;
int V_58 , V_117 ;
F_72 ( & V_141 ) ;
V_117 = 0 ;
for ( V_58 = 0 ; V_58 < V_133 * 2 ; V_58 ++ ) {
if ( F_66 ( V_31 , V_58 , & V_117 ) )
F_60 ( V_31 , V_58 ) ;
}
if ( F_67 ( V_31 , V_117 ) )
F_65 ( V_31 , V_117 ) ;
F_73 ( & V_141 ) ;
}
static T_3 F_74 ( struct V_31 * V_31 , int V_58 )
{
static T_3 V_142 ;
for (; ; ) {
struct V_102 * V_103 ;
struct V_93 * V_99 ;
struct V_52 * V_143 ;
T_3 V_144 ;
int V_145 ;
V_144 = ( V_142 | V_58 ) ;
V_142 += 8 ;
if ( V_144 == 0 )
V_144 = 8 ;
V_99 = V_31 -> V_91 . V_119 + F_46 ( V_31 , V_144 ) ;
V_145 = 0 ;
F_75 (p, entry, list, byidx) {
if ( V_143 -> V_63 == V_144 ) {
V_145 = 1 ;
break;
}
}
if ( ! V_145 )
return V_144 ;
}
}
static inline int F_76 ( struct V_1 * V_146 , struct V_1 * V_147 )
{
T_3 * V_148 = ( T_3 * ) V_146 ;
T_3 * V_149 = ( T_3 * ) V_147 ;
int V_150 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_150 ; V_115 ++ ) {
if ( V_148 [ V_115 ] != V_149 [ V_115 ] )
return 1 ;
}
return 0 ;
}
int F_77 ( int V_58 , struct V_52 * V_81 , int V_151 )
{
struct V_31 * V_31 = V_82 ( V_81 ) ;
struct V_52 * V_79 ;
struct V_52 * V_152 ;
struct V_93 * V_153 ;
struct V_102 * V_103 , * V_154 ;
T_3 V_155 = V_81 -> V_155 . V_156 & V_81 -> V_155 . V_157 ;
F_62 ( & V_116 ) ;
V_153 = F_48 ( V_31 , & V_81 -> V_109 , V_81 -> V_27 , V_58 ) ;
V_152 = NULL ;
V_154 = NULL ;
F_75 (pol, entry, chain, bydst) {
if ( V_79 -> type == V_81 -> type &&
! F_76 ( & V_79 -> V_109 , & V_81 -> V_109 ) &&
( V_155 & V_79 -> V_155 . V_157 ) == V_79 -> V_155 . V_156 &&
F_78 ( V_79 -> V_89 , V_81 -> V_89 ) &&
! F_79 ( V_152 ) ) {
if ( V_151 ) {
F_63 ( & V_116 ) ;
return - V_158 ;
}
V_152 = V_79 ;
if ( V_81 -> V_159 > V_79 -> V_159 )
continue;
} else if ( V_81 -> V_159 >= V_79 -> V_159 ) {
V_154 = & V_79 -> V_84 ;
continue;
}
if ( V_152 )
break;
}
if ( V_154 )
F_56 ( V_154 , & V_81 -> V_84 ) ;
else
F_55 ( & V_81 -> V_84 , V_153 ) ;
F_22 ( V_81 ) ;
V_31 -> V_91 . V_122 [ V_58 ] ++ ;
F_45 ( & V_160 ) ;
if ( V_152 )
F_80 ( V_152 , V_58 ) ;
V_81 -> V_63 = V_152 ? V_152 -> V_63 : F_74 ( V_31 , V_58 ) ;
F_55 ( & V_81 -> V_85 , V_31 -> V_91 . V_119 + F_46 ( V_31 , V_81 -> V_63 ) ) ;
V_81 -> V_67 . V_68 = F_17 () ;
V_81 -> V_67 . V_71 = 0 ;
if ( ! F_21 ( & V_81 -> V_75 , V_76 + V_50 ) )
F_22 ( V_81 ) ;
F_81 ( & V_81 -> V_60 . V_83 , & V_31 -> V_91 . V_161 ) ;
F_63 ( & V_116 ) ;
if ( V_152 )
F_44 ( V_152 ) ;
else if ( F_66 ( V_31 , V_58 , NULL ) )
F_82 ( & V_31 -> V_91 . V_140 ) ;
return 0 ;
}
struct V_52 * F_83 ( struct V_31 * V_31 , T_3 V_155 , T_4 type ,
int V_58 , struct V_1 * V_2 ,
struct V_162 * V_163 , int V_164 ,
int * V_165 )
{
struct V_52 * V_79 , * V_166 ;
struct V_93 * V_153 ;
struct V_102 * V_103 ;
* V_165 = 0 ;
F_62 ( & V_116 ) ;
V_153 = F_48 ( V_31 , V_2 , V_2 -> V_27 , V_58 ) ;
V_166 = NULL ;
F_75 (pol, entry, chain, bydst) {
if ( V_79 -> type == type &&
( V_155 & V_79 -> V_155 . V_157 ) == V_79 -> V_155 . V_156 &&
! F_76 ( V_2 , & V_79 -> V_109 ) &&
F_78 ( V_163 , V_79 -> V_89 ) ) {
F_22 ( V_79 ) ;
if ( V_164 ) {
* V_165 = F_84 (
V_79 -> V_89 ) ;
if ( * V_165 ) {
F_63 ( & V_116 ) ;
return V_79 ;
}
F_80 ( V_79 , V_58 ) ;
}
V_166 = V_79 ;
break;
}
}
F_63 ( & V_116 ) ;
if ( V_166 && V_164 )
F_44 ( V_166 ) ;
return V_166 ;
}
struct V_52 * F_85 ( struct V_31 * V_31 , T_3 V_155 , T_4 type ,
int V_58 , T_3 V_43 , int V_164 , int * V_165 )
{
struct V_52 * V_79 , * V_166 ;
struct V_93 * V_153 ;
struct V_102 * V_103 ;
* V_165 = - V_167 ;
if ( F_19 ( V_43 ) != V_58 )
return NULL ;
* V_165 = 0 ;
F_62 ( & V_116 ) ;
V_153 = V_31 -> V_91 . V_119 + F_46 ( V_31 , V_43 ) ;
V_166 = NULL ;
F_75 (pol, entry, chain, byidx) {
if ( V_79 -> type == type && V_79 -> V_63 == V_43 &&
( V_155 & V_79 -> V_155 . V_157 ) == V_79 -> V_155 . V_156 ) {
F_22 ( V_79 ) ;
if ( V_164 ) {
* V_165 = F_84 (
V_79 -> V_89 ) ;
if ( * V_165 ) {
F_63 ( & V_116 ) ;
return V_79 ;
}
F_80 ( V_79 , V_58 ) ;
}
V_166 = V_79 ;
break;
}
}
F_63 ( & V_116 ) ;
if ( V_166 && V_164 )
F_44 ( V_166 ) ;
return V_166 ;
}
static inline int
F_86 ( struct V_31 * V_31 , T_4 type , struct V_168 * V_169 )
{
int V_58 , V_165 = 0 ;
for ( V_58 = 0 ; V_58 < V_133 ; V_58 ++ ) {
struct V_52 * V_79 ;
struct V_102 * V_103 ;
int V_115 ;
F_75 (pol, entry,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_79 -> type != type )
continue;
V_165 = F_84 ( V_79 -> V_89 ) ;
if ( V_165 ) {
F_87 ( V_79 , 0 ,
V_169 -> V_170 ,
V_169 -> V_171 ,
V_169 -> V_172 ) ;
return V_165 ;
}
}
for ( V_115 = V_31 -> V_91 . V_95 [ V_58 ] . V_94 ; V_115 >= 0 ; V_115 -- ) {
F_75 (pol, entry,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_79 -> type != type )
continue;
V_165 = F_84 (
V_79 -> V_89 ) ;
if ( V_165 ) {
F_87 ( V_79 , 0 ,
V_169 -> V_170 ,
V_169 -> V_171 ,
V_169 -> V_172 ) ;
return V_165 ;
}
}
}
}
return V_165 ;
}
static inline int
F_86 ( struct V_31 * V_31 , T_4 type , struct V_168 * V_169 )
{
return 0 ;
}
int F_88 ( struct V_31 * V_31 , T_4 type , struct V_168 * V_169 )
{
int V_58 , V_165 = 0 , V_121 = 0 ;
F_62 ( & V_116 ) ;
V_165 = F_86 ( V_31 , type , V_169 ) ;
if ( V_165 )
goto V_62;
for ( V_58 = 0 ; V_58 < V_133 ; V_58 ++ ) {
struct V_52 * V_79 ;
struct V_102 * V_103 ;
int V_115 ;
V_173:
F_75 (pol, entry,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_79 -> type != type )
continue;
F_80 ( V_79 , V_58 ) ;
F_63 ( & V_116 ) ;
V_121 ++ ;
F_87 ( V_79 , 1 , V_169 -> V_170 ,
V_169 -> V_171 ,
V_169 -> V_172 ) ;
F_44 ( V_79 ) ;
F_62 ( & V_116 ) ;
goto V_173;
}
for ( V_115 = V_31 -> V_91 . V_95 [ V_58 ] . V_94 ; V_115 >= 0 ; V_115 -- ) {
V_174:
F_75 (pol, entry,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_79 -> type != type )
continue;
F_80 ( V_79 , V_58 ) ;
F_63 ( & V_116 ) ;
V_121 ++ ;
F_87 ( V_79 , 1 ,
V_169 -> V_170 ,
V_169 -> V_171 ,
V_169 -> V_172 ) ;
F_44 ( V_79 ) ;
F_62 ( & V_116 ) ;
goto V_174;
}
}
}
if ( ! V_121 )
V_165 = - V_175 ;
V_62:
F_63 ( & V_116 ) ;
return V_165 ;
}
int F_89 ( struct V_31 * V_31 , struct F_89 * V_60 ,
int (* F_90)( struct V_52 * , int , int , void * ) ,
void * V_51 )
{
struct V_52 * V_79 ;
struct V_176 * V_39 ;
int error = 0 ;
if ( V_60 -> type >= V_177 &&
V_60 -> type != V_178 )
return - V_179 ;
if ( F_91 ( & V_60 -> V_60 . V_83 ) && V_60 -> V_180 != 0 )
return 0 ;
F_62 ( & V_116 ) ;
if ( F_91 ( & V_60 -> V_60 . V_83 ) )
V_39 = F_92 ( & V_31 -> V_91 . V_161 , struct V_176 , V_83 ) ;
else
V_39 = F_93 ( & V_60 -> V_60 . V_83 , struct V_176 , V_83 ) ;
F_94 (x, &net->xfrm.policy_all, all) {
if ( V_39 -> V_61 )
continue;
V_79 = F_27 ( V_39 , struct V_52 , V_60 ) ;
if ( V_60 -> type != V_178 &&
V_60 -> type != V_79 -> type )
continue;
error = F_90 ( V_79 , F_19 ( V_79 -> V_63 ) ,
V_60 -> V_180 , V_51 ) ;
if ( error ) {
F_95 ( & V_60 -> V_60 . V_83 , & V_39 -> V_83 ) ;
goto V_62;
}
V_60 -> V_180 ++ ;
}
if ( V_60 -> V_180 == 0 ) {
error = - V_167 ;
goto V_62;
}
F_96 ( & V_60 -> V_60 . V_83 ) ;
V_62:
F_63 ( & V_116 ) ;
return error ;
}
void F_97 ( struct F_89 * V_60 , T_4 type )
{
F_33 ( & V_60 -> V_60 . V_83 ) ;
V_60 -> V_60 . V_61 = 1 ;
V_60 -> type = type ;
V_60 -> V_180 = 0 ;
}
void F_98 ( struct F_89 * V_60 )
{
if ( F_91 ( & V_60 -> V_60 . V_83 ) )
return;
F_62 ( & V_116 ) ;
F_99 ( & V_60 -> V_60 . V_83 ) ;
F_63 ( & V_116 ) ;
}
static int F_100 ( const struct V_52 * V_79 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_27 , int V_58 )
{
const struct V_1 * V_2 = & V_79 -> V_109 ;
int V_181 , V_166 = - V_175 ;
if ( V_79 -> V_27 != V_27 ||
( V_4 -> V_182 & V_79 -> V_155 . V_157 ) != V_79 -> V_155 . V_156 ||
V_79 -> type != type )
return V_166 ;
V_181 = F_6 ( V_2 , V_4 , V_27 ) ;
if ( V_181 )
V_166 = F_101 ( V_79 -> V_89 , V_4 -> V_183 ,
V_58 ) ;
return V_166 ;
}
static struct V_52 * F_102 ( struct V_31 * V_31 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_27 , T_4 V_58 )
{
int V_165 ;
struct V_52 * V_79 , * V_166 ;
const T_1 * V_9 , * V_11 ;
struct V_102 * V_103 ;
struct V_93 * V_153 ;
T_3 V_159 = ~ 0U ;
V_9 = F_103 ( V_4 , V_27 ) ;
V_11 = F_104 ( V_4 , V_27 ) ;
if ( F_9 ( ! V_9 || ! V_11 ) )
return NULL ;
F_69 ( & V_116 ) ;
V_153 = F_50 ( V_31 , V_9 , V_11 , V_27 , V_58 ) ;
V_166 = NULL ;
F_75 (pol, entry, chain, bydst) {
V_165 = F_100 ( V_79 , V_4 , type , V_27 , V_58 ) ;
if ( V_165 ) {
if ( V_165 == - V_175 )
continue;
else {
V_166 = F_10 ( V_165 ) ;
goto V_184;
}
} else {
V_166 = V_79 ;
V_159 = V_166 -> V_159 ;
break;
}
}
V_153 = & V_31 -> V_91 . V_97 [ V_58 ] ;
F_75 (pol, entry, chain, bydst) {
V_165 = F_100 ( V_79 , V_4 , type , V_27 , V_58 ) ;
if ( V_165 ) {
if ( V_165 == - V_175 )
continue;
else {
V_166 = F_10 ( V_165 ) ;
goto V_184;
}
} else if ( V_79 -> V_159 < V_159 ) {
V_166 = V_79 ;
break;
}
}
if ( V_166 )
F_22 ( V_166 ) ;
V_184:
F_70 ( & V_116 ) ;
return V_166 ;
}
static struct V_52 *
F_105 ( struct V_31 * V_31 , const struct V_3 * V_4 , T_5 V_27 , T_4 V_58 )
{
#ifdef F_106
struct V_52 * V_79 ;
V_79 = F_102 ( V_31 , V_185 , V_4 , V_27 , V_58 ) ;
if ( V_79 != NULL )
return V_79 ;
#endif
return F_102 ( V_31 , V_186 , V_4 , V_27 , V_58 ) ;
}
static struct V_77 *
F_107 ( struct V_31 * V_31 , const struct V_3 * V_4 , T_5 V_27 ,
T_4 V_58 , struct V_77 * V_187 , void * V_163 )
{
struct V_52 * V_79 ;
if ( V_187 )
F_24 ( F_27 ( V_187 , struct V_52 , V_78 ) ) ;
V_79 = F_105 ( V_31 , V_4 , V_27 , V_58 ) ;
if ( F_108 ( V_79 ) )
return F_109 ( V_79 ) ;
F_22 ( V_79 ) ;
return & V_79 -> V_78 ;
}
static inline int F_110 ( int V_58 )
{
if ( V_127 == V_188 &&
V_129 == V_189 &&
V_131 == V_190 )
return V_58 ;
switch ( V_58 ) {
default:
case V_127 :
return V_188 ;
case V_129 :
return V_189 ;
case V_131 :
return V_190 ;
}
}
static struct V_52 * F_111 ( struct V_191 * V_192 , int V_58 ,
const struct V_3 * V_4 )
{
struct V_52 * V_79 ;
F_69 ( & V_116 ) ;
if ( ( V_79 = V_192 -> V_193 [ V_58 ] ) != NULL ) {
int V_181 = F_6 ( & V_79 -> V_109 , V_4 ,
V_192 -> V_194 ) ;
int V_165 = 0 ;
if ( V_181 ) {
if ( ( V_192 -> V_195 & V_79 -> V_155 . V_157 ) != V_79 -> V_155 . V_156 ) {
V_79 = NULL ;
goto V_62;
}
V_165 = F_101 ( V_79 -> V_89 ,
V_4 -> V_183 ,
F_110 ( V_58 ) ) ;
if ( ! V_165 )
F_22 ( V_79 ) ;
else if ( V_165 == - V_175 )
V_79 = NULL ;
else
V_79 = F_10 ( V_165 ) ;
} else
V_79 = NULL ;
}
V_62:
F_70 ( & V_116 ) ;
return V_79 ;
}
static void F_112 ( struct V_52 * V_79 , int V_58 )
{
struct V_31 * V_31 = V_82 ( V_79 ) ;
struct V_93 * V_153 = F_48 ( V_31 , & V_79 -> V_109 ,
V_79 -> V_27 , V_58 ) ;
F_81 ( & V_79 -> V_60 . V_83 , & V_31 -> V_91 . V_161 ) ;
F_55 ( & V_79 -> V_84 , V_153 ) ;
F_55 ( & V_79 -> V_85 , V_31 -> V_91 . V_119 + F_46 ( V_31 , V_79 -> V_63 ) ) ;
V_31 -> V_91 . V_122 [ V_58 ] ++ ;
F_22 ( V_79 ) ;
if ( F_66 ( V_31 , V_58 , NULL ) )
F_82 ( & V_31 -> V_91 . V_140 ) ;
}
static struct V_52 * F_80 ( struct V_52 * V_79 ,
int V_58 )
{
struct V_31 * V_31 = V_82 ( V_79 ) ;
if ( F_113 ( & V_79 -> V_84 ) )
return NULL ;
F_54 ( & V_79 -> V_84 ) ;
F_54 ( & V_79 -> V_85 ) ;
F_99 ( & V_79 -> V_60 . V_83 ) ;
V_31 -> V_91 . V_122 [ V_58 ] -- ;
return V_79 ;
}
int F_25 ( struct V_52 * V_79 , int V_58 )
{
F_62 ( & V_116 ) ;
V_79 = F_80 ( V_79 , V_58 ) ;
F_63 ( & V_116 ) ;
if ( V_79 ) {
F_44 ( V_79 ) ;
return 0 ;
}
return - V_167 ;
}
int F_114 ( struct V_191 * V_192 , int V_58 , struct V_52 * V_79 )
{
struct V_31 * V_31 = V_82 ( V_79 ) ;
struct V_52 * V_196 ;
#ifdef F_106
if ( V_79 && V_79 -> type != V_186 )
return - V_179 ;
#endif
F_62 ( & V_116 ) ;
V_196 = V_192 -> V_193 [ V_58 ] ;
V_192 -> V_193 [ V_58 ] = V_79 ;
if ( V_79 ) {
V_79 -> V_67 . V_68 = F_17 () ;
V_79 -> V_63 = F_74 ( V_31 , V_133 + V_58 ) ;
F_112 ( V_79 , V_133 + V_58 ) ;
}
if ( V_196 )
F_80 ( V_196 , V_133 + V_58 ) ;
F_63 ( & V_116 ) ;
if ( V_196 ) {
F_44 ( V_196 ) ;
}
return 0 ;
}
static struct V_52 * F_115 ( const struct V_52 * V_197 , int V_58 )
{
struct V_52 * V_198 = F_30 ( V_82 ( V_197 ) , V_199 ) ;
if ( V_198 ) {
V_198 -> V_109 = V_197 -> V_109 ;
if ( F_116 ( V_197 -> V_89 ,
& V_198 -> V_89 ) ) {
F_43 ( V_198 ) ;
return NULL ;
}
V_198 -> V_64 = V_197 -> V_64 ;
V_198 -> V_67 = V_197 -> V_67 ;
V_198 -> V_155 = V_197 -> V_155 ;
V_198 -> V_200 = V_197 -> V_200 ;
V_198 -> V_44 = V_197 -> V_44 ;
V_198 -> V_201 = V_197 -> V_201 ;
V_198 -> V_63 = V_197 -> V_63 ;
V_198 -> type = V_197 -> type ;
memcpy ( V_198 -> V_202 , V_197 -> V_202 ,
V_198 -> V_201 * sizeof( struct V_203 ) ) ;
F_62 ( & V_116 ) ;
F_112 ( V_198 , V_133 + V_58 ) ;
F_63 ( & V_116 ) ;
F_24 ( V_198 ) ;
}
return V_198 ;
}
int F_117 ( struct V_191 * V_192 )
{
struct V_52 * V_204 = V_192 -> V_193 [ 0 ] ,
* V_148 = V_192 -> V_193 [ 1 ] ;
V_192 -> V_193 [ 0 ] = V_192 -> V_193 [ 1 ] = NULL ;
if ( V_204 && ( V_192 -> V_193 [ 0 ] = F_115 ( V_204 , 0 ) ) == NULL )
return - V_205 ;
if ( V_148 && ( V_192 -> V_193 [ 1 ] = F_115 ( V_148 , 1 ) ) == NULL )
return - V_205 ;
return 0 ;
}
static int
F_118 ( struct V_31 * V_31 , T_1 * V_206 , T_1 * V_207 ,
unsigned short V_27 )
{
int V_165 ;
struct V_33 * V_34 = F_8 ( V_27 ) ;
if ( F_9 ( V_34 == NULL ) )
return - V_179 ;
V_165 = V_34 -> V_208 ( V_31 , V_206 , V_207 ) ;
F_11 ( V_34 ) ;
return V_165 ;
}
static int
F_119 ( struct V_52 * V_81 , const struct V_3 * V_4 ,
struct V_38 * * V_91 , unsigned short V_27 )
{
struct V_31 * V_31 = V_82 ( V_81 ) ;
int V_209 ;
int V_115 , error ;
T_1 * V_9 = F_103 ( V_4 , V_27 ) ;
T_1 * V_11 = F_104 ( V_4 , V_27 ) ;
T_1 V_104 ;
for ( V_209 = 0 , V_115 = 0 ; V_115 < V_81 -> V_201 ; V_115 ++ ) {
struct V_38 * V_39 ;
T_1 * V_207 = V_9 ;
T_1 * V_206 = V_11 ;
struct V_203 * V_210 = & V_81 -> V_202 [ V_115 ] ;
if ( V_210 -> V_211 == V_212 ||
V_210 -> V_211 == V_213 ) {
V_207 = & V_210 -> V_43 . V_9 ;
V_206 = & V_210 -> V_11 ;
if ( F_120 ( V_206 , V_210 -> V_214 ) ) {
error = F_118 ( V_31 , & V_104 , V_207 , V_210 -> V_214 ) ;
if ( error )
goto V_184;
V_206 = & V_104 ;
}
}
V_39 = F_121 ( V_207 , V_206 , V_4 , V_210 , V_81 , & error , V_27 ) ;
if ( V_39 && V_39 -> V_215 . V_216 == V_217 ) {
V_91 [ V_209 ++ ] = V_39 ;
V_9 = V_207 ;
V_11 = V_206 ;
continue;
}
if ( V_39 ) {
error = ( V_39 -> V_215 . V_216 == V_218 ?
- V_179 : - V_219 ) ;
F_122 ( V_39 ) ;
}
else if ( error == - V_175 )
error = - V_219 ;
if ( ! V_210 -> V_220 )
goto V_184;
}
return V_209 ;
V_184:
for ( V_209 -- ; V_209 >= 0 ; V_209 -- )
F_122 ( V_91 [ V_209 ] ) ;
return error ;
}
static int
F_123 ( struct V_52 * * V_221 , int V_222 , const struct V_3 * V_4 ,
struct V_38 * * V_91 , unsigned short V_27 )
{
struct V_38 * V_223 [ V_224 ] ;
struct V_38 * * V_225 = ( V_222 > 1 ) ? V_223 : V_91 ;
int V_226 = 0 ;
int error ;
int V_166 ;
int V_115 ;
for ( V_115 = 0 ; V_115 < V_222 ; V_115 ++ ) {
if ( V_226 + V_221 [ V_115 ] -> V_201 >= V_224 ) {
error = - V_227 ;
goto V_184;
}
V_166 = F_119 ( V_221 [ V_115 ] , V_4 , & V_225 [ V_226 ] , V_27 ) ;
if ( V_166 < 0 ) {
error = V_166 ;
goto V_184;
} else
V_226 += V_166 ;
}
if ( V_222 > 1 )
F_124 ( V_91 , V_225 , V_226 , V_27 ) ;
return V_226 ;
V_184:
for ( V_226 -- ; V_226 >= 0 ; V_226 -- )
F_122 ( V_225 [ V_226 ] ) ;
return error ;
}
static inline int F_125 ( const struct V_3 * V_4 , int V_27 )
{
struct V_33 * V_34 = F_8 ( V_27 ) ;
int V_32 ;
if ( ! V_34 )
return - V_179 ;
V_32 = V_34 -> V_228 ( V_4 ) ;
F_11 ( V_34 ) ;
return V_32 ;
}
static struct V_77 * F_126 ( struct V_77 * V_78 )
{
struct V_229 * V_230 = F_27 ( V_78 , struct V_229 , V_78 ) ;
struct V_30 * V_35 = & V_230 -> V_7 . V_35 ;
if ( V_230 -> V_231 == NULL ) {
if ( V_230 -> V_232 > 0 )
return NULL ;
} else {
if ( F_127 ( V_35 ) )
return NULL ;
}
F_128 ( V_35 ) ;
return V_78 ;
}
static int F_129 ( struct V_77 * V_78 )
{
struct V_229 * V_230 = F_27 ( V_78 , struct V_229 , V_78 ) ;
struct V_30 * V_35 = & V_230 -> V_7 . V_35 ;
if ( ! V_230 -> V_231 )
return 0 ;
if ( F_127 ( V_35 ) )
return 0 ;
return 1 ;
}
static void F_130 ( struct V_77 * V_78 )
{
struct V_229 * V_230 = F_27 ( V_78 , struct V_229 , V_78 ) ;
struct V_30 * V_35 = & V_230 -> V_7 . V_35 ;
F_131 ( V_35 ) ;
}
static inline struct V_229 * F_132 ( struct V_31 * V_31 , int V_27 )
{
struct V_33 * V_34 = F_8 ( V_27 ) ;
struct V_233 * V_233 ;
struct V_229 * V_230 ;
if ( ! V_34 )
return F_10 ( - V_179 ) ;
switch ( V_27 ) {
case V_28 :
V_233 = & V_31 -> V_91 . V_234 ;
break;
#if F_133 ( V_235 ) || F_133 ( V_236 )
case V_29 :
V_233 = & V_31 -> V_91 . V_237 ;
break;
#endif
default:
F_41 () ;
}
V_230 = F_134 ( V_233 , NULL , 0 , 0 , 0 ) ;
memset ( & V_230 -> V_7 . V_238 . V_239 , 0 , sizeof( * V_230 ) - sizeof( struct V_30 ) ) ;
F_11 ( V_34 ) ;
if ( F_135 ( V_230 ) )
V_230 -> V_78 . V_87 = & V_240 ;
else
V_230 = F_10 ( - V_227 ) ;
return V_230 ;
}
static inline int F_136 ( struct V_229 * V_241 , struct V_30 * V_35 ,
int V_242 )
{
struct V_33 * V_34 =
F_8 ( V_35 -> V_87 -> V_27 ) ;
int V_165 ;
if ( ! V_34 )
return - V_179 ;
V_165 = V_34 -> V_243 ( V_241 , V_35 , V_242 ) ;
F_11 ( V_34 ) ;
return V_165 ;
}
static inline int F_137 ( struct V_229 * V_230 , struct V_244 * V_245 ,
const struct V_3 * V_4 )
{
struct V_33 * V_34 =
F_8 ( V_230 -> V_7 . V_35 . V_87 -> V_27 ) ;
int V_165 ;
if ( ! V_34 )
return - V_179 ;
V_165 = V_34 -> V_246 ( V_230 , V_245 , V_4 ) ;
F_11 ( V_34 ) ;
return V_165 ;
}
static struct V_30 * F_138 ( struct V_52 * V_81 ,
struct V_38 * * V_91 , int V_209 ,
const struct V_3 * V_4 ,
struct V_30 * V_35 )
{
struct V_31 * V_31 = V_82 ( V_81 ) ;
unsigned long V_54 = V_76 ;
struct V_244 * V_245 ;
struct V_247 * V_248 ;
struct V_30 * V_249 = NULL ;
struct V_30 * V_250 = NULL ;
int V_115 = 0 ;
int V_165 ;
int V_251 = 0 ;
int V_242 = 0 ;
int V_252 = 0 ;
int V_32 ;
int V_27 = V_81 -> V_109 . V_27 ;
T_1 V_11 , V_9 ;
F_139 ( V_4 , & V_11 , & V_9 , V_27 ) ;
V_32 = F_125 ( V_4 , V_27 ) ;
V_165 = V_32 ;
if ( V_32 < 0 )
goto V_253;
F_128 ( V_35 ) ;
for (; V_115 < V_209 ; V_115 ++ ) {
struct V_229 * V_230 = F_132 ( V_31 , V_27 ) ;
struct V_30 * V_254 = & V_230 -> V_7 . V_35 ;
V_165 = F_140 ( V_230 ) ;
if ( F_14 ( V_230 ) ) {
F_141 ( V_35 ) ;
goto V_253;
}
if ( V_91 [ V_115 ] -> V_2 . V_27 == V_255 ) {
V_248 = F_142 ( V_91 [ V_115 ] ,
F_143 ( V_27 ) ) ;
if ( ! V_248 ) {
V_165 = - V_36 ;
F_141 ( V_35 ) ;
goto V_253;
}
} else
V_248 = V_91 [ V_115 ] -> V_248 ;
if ( ! V_249 )
V_250 = V_254 ;
else {
V_249 -> V_256 = F_144 ( V_254 ) ;
V_254 -> V_44 |= V_257 ;
}
V_230 -> V_231 = V_35 ;
F_145 ( V_254 , V_35 ) ;
if ( V_91 [ V_115 ] -> V_42 . V_211 != V_258 ) {
V_27 = V_91 [ V_115 ] -> V_42 . V_27 ;
V_35 = F_12 ( V_91 [ V_115 ] , V_32 , & V_11 , & V_9 ,
V_27 ) ;
V_165 = F_140 ( V_35 ) ;
if ( F_14 ( V_35 ) )
goto V_253;
} else
F_128 ( V_35 ) ;
V_254 -> V_91 = V_91 [ V_115 ] ;
V_230 -> V_259 = V_91 [ V_115 ] -> V_90 ;
V_254 -> V_260 = - 1 ;
V_254 -> V_44 |= V_261 ;
V_254 -> V_262 = V_54 ;
V_254 -> V_263 = V_264 ;
V_254 -> V_265 = V_248 -> V_34 -> V_265 ;
V_254 -> V_55 = V_249 ;
V_249 = V_254 ;
V_251 += V_91 [ V_115 ] -> V_42 . V_251 ;
if ( V_91 [ V_115 ] -> type -> V_44 & V_266 )
V_242 += V_91 [ V_115 ] -> V_42 . V_251 ;
V_252 += V_91 [ V_115 ] -> V_42 . V_252 ;
}
V_249 -> V_256 = V_35 ;
V_250 -> V_241 = V_35 ;
V_165 = - V_267 ;
V_245 = V_35 -> V_245 ;
if ( ! V_245 )
goto V_268;
V_250 -> V_269 = F_146 ( V_35 -> V_269 ) ;
F_136 ( (struct V_229 * ) V_250 , V_35 , V_242 ) ;
F_147 ( V_249 ) ;
for ( V_249 = V_250 ; V_249 != V_35 ; V_249 = V_249 -> V_256 ) {
struct V_229 * V_230 = (struct V_229 * ) V_249 ;
V_165 = F_137 ( V_230 , V_245 , V_4 ) ;
if ( V_165 )
goto V_268;
V_249 -> V_251 = V_251 ;
V_249 -> V_252 = V_252 ;
V_251 -= V_230 -> V_7 . V_35 . V_91 -> V_42 . V_251 ;
V_252 -= V_230 -> V_7 . V_35 . V_91 -> V_42 . V_252 ;
}
V_62:
return V_250 ;
V_253:
for (; V_115 < V_209 ; V_115 ++ )
F_122 ( V_91 [ V_115 ] ) ;
V_268:
if ( V_250 )
F_131 ( V_250 ) ;
V_250 = F_10 ( V_165 ) ;
goto V_62;
}
static int inline
F_148 ( void * * V_270 , const void * V_271 , int V_272 )
{
if ( ! * V_270 ) {
* V_270 = F_149 ( V_272 , V_199 ) ;
if ( ! * V_270 )
return - V_205 ;
}
memcpy ( * V_270 , V_271 , V_272 ) ;
return 0 ;
}
static int inline
F_150 ( struct V_30 * V_35 , const struct V_1 * V_2 )
{
#ifdef F_106
struct V_229 * V_230 = (struct V_229 * ) V_35 ;
return F_148 ( ( void * * ) & ( V_230 -> V_273 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int inline
F_151 ( struct V_30 * V_35 , const struct V_3 * V_4 )
{
#ifdef F_106
struct V_229 * V_230 = (struct V_229 * ) V_35 ;
return F_148 ( ( void * * ) & ( V_230 -> V_274 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_152 ( const struct V_3 * V_4 , T_5 V_27 ,
struct V_52 * * V_221 ,
int * V_275 , int * V_232 )
{
int V_115 ;
if ( * V_275 == 0 || ! V_221 [ 0 ] ) {
* V_275 = 0 ;
* V_232 = 0 ;
return 0 ;
}
if ( F_14 ( V_221 [ 0 ] ) )
return F_140 ( V_221 [ 0 ] ) ;
* V_232 = V_221 [ 0 ] -> V_201 ;
#ifdef F_106
if ( V_221 [ 0 ] && V_221 [ 0 ] -> V_200 == V_276 &&
V_221 [ 0 ] -> type != V_186 ) {
V_221 [ 1 ] = F_102 ( V_82 ( V_221 [ 0 ] ) ,
V_186 ,
V_4 , V_27 ,
V_129 ) ;
if ( V_221 [ 1 ] ) {
if ( F_14 ( V_221 [ 1 ] ) ) {
F_153 ( V_221 , * V_275 ) ;
return F_140 ( V_221 [ 1 ] ) ;
}
( * V_275 ) ++ ;
( * V_232 ) += V_221 [ 1 ] -> V_201 ;
}
}
#endif
for ( V_115 = 0 ; V_115 < * V_275 ; V_115 ++ ) {
if ( V_221 [ V_115 ] -> V_200 != V_276 ) {
* V_232 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_229 *
F_154 ( struct V_52 * * V_221 , int V_275 ,
const struct V_3 * V_4 , T_5 V_27 ,
struct V_30 * V_277 )
{
struct V_31 * V_31 = V_82 ( V_221 [ 0 ] ) ;
struct V_38 * V_91 [ V_224 ] ;
struct V_30 * V_35 ;
struct V_229 * V_230 ;
int V_165 ;
V_165 = F_123 ( V_221 , V_275 , V_4 , V_91 , V_27 ) ;
if ( V_165 <= 0 ) {
if ( V_165 != 0 && V_165 != - V_219 )
F_155 ( V_31 , V_278 ) ;
return F_10 ( V_165 ) ;
}
V_35 = F_138 ( V_221 [ 0 ] , V_91 , V_165 , V_4 , V_277 ) ;
if ( F_14 ( V_35 ) ) {
F_155 ( V_31 , V_279 ) ;
return F_109 ( V_35 ) ;
}
V_230 = (struct V_229 * ) V_35 ;
V_230 -> V_232 = V_165 ;
if ( V_275 > 1 )
V_165 = F_150 ( V_35 , & V_221 [ 1 ] -> V_109 ) ;
else
V_165 = F_151 ( V_35 , V_4 ) ;
if ( F_9 ( V_165 ) ) {
F_131 ( V_35 ) ;
F_155 ( V_31 , V_280 ) ;
return F_10 ( V_165 ) ;
}
V_230 -> V_275 = V_275 ;
memcpy ( V_230 -> V_221 , V_221 , sizeof( struct V_52 * ) * V_275 ) ;
V_230 -> V_281 = F_156 ( & V_221 [ 0 ] -> V_90 ) ;
return V_230 ;
}
static struct V_77 *
F_157 ( struct V_31 * V_31 , const struct V_3 * V_4 , T_5 V_27 , T_4 V_58 ,
struct V_77 * V_282 , void * V_163 )
{
struct V_30 * V_277 = (struct V_30 * ) V_163 ;
struct V_52 * V_221 [ V_177 ] ;
struct V_229 * V_230 , * V_283 ;
int V_275 = 0 , V_232 = 0 , V_115 , V_165 , V_284 ;
V_230 = NULL ;
if ( V_282 ) {
V_230 = F_27 ( V_282 , struct V_229 , V_78 ) ;
V_275 = V_230 -> V_275 ;
V_232 = V_230 -> V_232 ;
V_284 = 0 ;
for ( V_115 = 0 ; V_115 < V_275 ; V_115 ++ ) {
V_221 [ V_115 ] = V_230 -> V_221 [ V_115 ] ;
V_284 |= V_221 [ V_115 ] -> V_60 . V_61 ;
}
if ( V_284 ) {
F_131 ( & V_230 -> V_7 . V_35 ) ;
V_230 = NULL ;
V_275 = 0 ;
V_232 = 0 ;
V_282 = NULL ;
}
}
if ( V_230 == NULL ) {
V_275 = 1 ;
V_221 [ 0 ] = F_105 ( V_31 , V_4 , V_27 , V_58 ) ;
V_165 = F_152 ( V_4 , V_27 , V_221 ,
& V_275 , & V_232 ) ;
if ( V_165 < 0 )
goto V_285;
if ( V_275 == 0 )
return NULL ;
if ( V_232 <= 0 )
goto V_286;
}
V_283 = F_154 ( V_221 , V_275 , V_4 , V_27 , V_277 ) ;
if ( F_14 ( V_283 ) ) {
V_165 = F_140 ( V_283 ) ;
if ( V_165 != - V_219 )
goto error;
if ( V_282 == NULL )
goto V_286;
F_128 ( & V_230 -> V_7 . V_35 ) ;
return V_282 ;
} else if ( V_283 == NULL ) {
V_232 = 0 ;
if ( V_282 == NULL )
goto V_286;
V_230 -> V_232 = 0 ;
F_128 ( & V_230 -> V_7 . V_35 ) ;
return V_282 ;
}
if ( V_230 ) {
V_230 -> V_275 = 0 ;
F_131 ( & V_230 -> V_7 . V_35 ) ;
}
F_128 ( & V_283 -> V_7 . V_35 ) ;
return & V_283 -> V_78 ;
V_286:
V_230 = F_132 ( V_31 , V_27 ) ;
if ( F_14 ( V_230 ) ) {
F_153 ( V_221 , V_275 ) ;
return F_109 ( V_230 ) ;
}
V_230 -> V_275 = V_275 ;
V_230 -> V_232 = V_232 ;
memcpy ( V_230 -> V_221 , V_221 , sizeof( struct V_52 * ) * V_275 ) ;
F_128 ( & V_230 -> V_7 . V_35 ) ;
return & V_230 -> V_78 ;
V_285:
F_155 ( V_31 , V_278 ) ;
error:
if ( V_230 != NULL )
F_131 ( & V_230 -> V_7 . V_35 ) ;
else
F_153 ( V_221 , V_275 ) ;
return F_10 ( V_165 ) ;
}
static struct V_30 * F_158 ( struct V_31 * V_31 , T_5 V_27 ,
struct V_30 * V_277 )
{
struct V_33 * V_34 = F_8 ( V_27 ) ;
struct V_30 * V_166 ;
if ( ! V_34 ) {
F_141 ( V_277 ) ;
V_166 = F_10 ( - V_179 ) ;
} else {
V_166 = V_34 -> V_287 ( V_31 , V_277 ) ;
}
F_11 ( V_34 ) ;
return V_166 ;
}
struct V_30 * F_159 ( struct V_31 * V_31 , struct V_30 * V_277 ,
const struct V_3 * V_4 ,
struct V_191 * V_192 , int V_44 )
{
struct V_52 * V_221 [ V_177 ] ;
struct V_77 * V_78 ;
struct V_229 * V_230 ;
struct V_30 * V_35 , * V_231 ;
T_5 V_27 = V_277 -> V_87 -> V_27 ;
T_4 V_58 = F_110 ( V_129 ) ;
int V_115 , V_165 , V_275 , V_232 = 0 , V_288 = 0 ;
V_289:
V_35 = NULL ;
V_230 = NULL ;
V_231 = NULL ;
if ( V_192 && V_192 -> V_193 [ V_129 ] ) {
V_275 = 1 ;
V_221 [ 0 ] = F_111 ( V_192 , V_129 , V_4 ) ;
V_165 = F_152 ( V_4 , V_27 , V_221 ,
& V_275 , & V_232 ) ;
if ( V_165 < 0 )
goto V_290;
if ( V_275 ) {
if ( V_232 <= 0 ) {
V_288 = V_275 ;
goto V_291;
}
V_230 = F_154 (
V_221 , V_275 , V_4 ,
V_27 , V_277 ) ;
if ( F_14 ( V_230 ) ) {
F_153 ( V_221 , V_275 ) ;
V_165 = F_140 ( V_230 ) ;
goto V_290;
} else if ( V_230 == NULL ) {
V_232 = 0 ;
V_288 = V_275 ;
goto V_291;
}
F_128 ( & V_230 -> V_7 . V_35 ) ;
F_160 ( & V_292 ) ;
V_230 -> V_7 . V_35 . V_55 = V_293 ;
V_293 = & V_230 -> V_7 . V_35 ;
F_161 ( & V_292 ) ;
V_231 = V_230 -> V_231 ;
}
}
if ( V_230 == NULL ) {
if ( ( V_277 -> V_44 & V_294 ) ||
! V_31 -> V_91 . V_122 [ V_129 ] )
goto V_295;
V_78 = F_162 ( V_31 , V_4 , V_27 , V_58 ,
F_157 , V_277 ) ;
if ( V_78 == NULL )
goto V_295;
if ( F_14 ( V_78 ) ) {
V_165 = F_140 ( V_78 ) ;
goto V_290;
}
V_230 = F_27 ( V_78 , struct V_229 , V_78 ) ;
V_275 = V_230 -> V_275 ;
V_232 = V_230 -> V_232 ;
memcpy ( V_221 , V_230 -> V_221 , sizeof( struct V_52 * ) * V_275 ) ;
V_231 = V_230 -> V_231 ;
}
V_35 = & V_230 -> V_7 . V_35 ;
if ( V_231 == NULL && V_232 > 0 ) {
if ( V_31 -> V_91 . V_296 ) {
F_141 ( V_35 ) ;
F_153 ( V_221 , V_288 ) ;
F_155 ( V_31 , V_297 ) ;
return F_158 ( V_31 , V_27 , V_277 ) ;
}
if ( V_4 -> V_298 & V_299 ) {
F_163 ( V_300 , V_301 ) ;
F_164 ( & V_31 -> V_91 . V_302 , & V_300 ) ;
F_165 ( V_303 ) ;
F_166 () ;
F_165 ( V_304 ) ;
F_167 ( & V_31 -> V_91 . V_302 , & V_300 ) ;
if ( ! F_168 ( V_301 ) ) {
F_141 ( V_35 ) ;
goto V_289;
}
V_165 = - V_305 ;
} else
V_165 = - V_219 ;
F_155 ( V_31 , V_297 ) ;
goto error;
}
V_291:
if ( V_275 == 0 )
goto V_295;
if ( ( V_44 & V_306 ) &&
! ( V_221 [ 0 ] -> V_44 & V_307 ) ) {
V_165 = - V_167 ;
goto error;
}
for ( V_115 = 0 ; V_115 < V_275 ; V_115 ++ )
V_221 [ V_115 ] -> V_67 . V_71 = F_17 () ;
if ( V_232 < 0 ) {
F_155 ( V_31 , V_308 ) ;
V_165 = - V_309 ;
goto error;
} else if ( V_232 > 0 ) {
F_141 ( V_277 ) ;
} else {
F_141 ( V_35 ) ;
V_35 = V_277 ;
}
V_310:
F_153 ( V_221 , V_288 ) ;
return V_35 ;
V_295:
if ( ! ( V_44 & V_306 ) ) {
V_35 = V_277 ;
goto V_310;
}
V_165 = - V_167 ;
error:
F_141 ( V_35 ) ;
V_290:
F_141 ( V_277 ) ;
F_153 ( V_221 , V_288 ) ;
return F_10 ( V_165 ) ;
}
static inline int
F_169 ( int V_144 , struct V_311 * V_312 , const struct V_3 * V_4 )
{
struct V_38 * V_39 ;
if ( ! V_312 -> V_313 || V_144 < 0 || V_144 >= V_312 -> V_313 -> V_150 )
return 0 ;
V_39 = V_312 -> V_313 -> V_314 [ V_144 ] ;
if ( ! V_39 -> type -> V_315 )
return 0 ;
return V_39 -> type -> V_315 ( V_39 , V_312 , V_4 ) ;
}
static inline int
F_170 ( const struct V_203 * V_210 , const struct V_38 * V_39 ,
unsigned short V_27 )
{
if ( F_171 ( V_39 ) )
return V_210 -> V_220 && ! F_172 ( V_210 , V_39 , V_210 -> V_214 ) ;
return V_39 -> V_43 . V_19 == V_210 -> V_43 . V_19 &&
( V_39 -> V_43 . V_316 == V_210 -> V_43 . V_316 || ! V_210 -> V_43 . V_316 ) &&
( V_39 -> V_42 . V_317 == V_210 -> V_317 || ! V_210 -> V_317 ) &&
V_39 -> V_42 . V_211 == V_210 -> V_211 &&
( V_210 -> V_318 || ( V_210 -> V_319 & ( 1 << V_39 -> V_42 . V_320 ) ) ||
! ( F_173 ( V_210 -> V_43 . V_19 , V_321 ) ) ) &&
! ( V_39 -> V_42 . V_211 != V_258 &&
F_172 ( V_210 , V_39 , V_27 ) ) ;
}
static inline int
F_174 ( const struct V_203 * V_210 , const struct V_322 * V_313 , int V_323 ,
unsigned short V_27 )
{
int V_144 = V_323 ;
if ( V_210 -> V_220 ) {
if ( V_210 -> V_211 == V_258 )
return V_323 ;
} else
V_323 = - 1 ;
for (; V_144 < V_313 -> V_150 ; V_144 ++ ) {
if ( F_170 ( V_210 , V_313 -> V_314 [ V_144 ] , V_27 ) )
return ++ V_144 ;
if ( V_313 -> V_314 [ V_144 ] -> V_42 . V_211 != V_258 ) {
if ( V_323 == - 1 )
V_323 = - 2 - V_144 ;
break;
}
}
return V_323 ;
}
int F_175 ( struct V_311 * V_312 , struct V_3 * V_4 ,
unsigned int V_27 , int V_324 )
{
struct V_33 * V_34 = F_8 ( V_27 ) ;
int V_165 ;
if ( F_9 ( V_34 == NULL ) )
return - V_36 ;
V_34 -> V_325 ( V_312 , V_4 , V_324 ) ;
V_165 = F_176 ( V_312 , & V_4 -> V_183 ) ;
F_11 ( V_34 ) ;
return V_165 ;
}
static inline int F_177 ( const struct V_322 * V_313 , int V_326 , int * V_327 )
{
for (; V_326 < V_313 -> V_150 ; V_326 ++ ) {
if ( V_313 -> V_314 [ V_326 ] -> V_42 . V_211 != V_258 ) {
* V_327 = V_326 ;
return 1 ;
}
}
return 0 ;
}
int F_178 ( struct V_191 * V_192 , int V_58 , struct V_311 * V_312 ,
unsigned short V_27 )
{
struct V_31 * V_31 = F_179 ( V_312 -> V_245 ) ;
struct V_52 * V_79 ;
struct V_52 * V_221 [ V_177 ] ;
int V_222 = 0 ;
int V_201 ;
int V_328 ;
int V_324 ;
struct V_3 V_4 ;
T_4 V_329 ;
int V_330 = - 1 ;
V_324 = V_58 & ~ V_331 ;
V_58 &= V_331 ;
V_329 = F_110 ( V_58 ) ;
if ( F_175 ( V_312 , & V_4 , V_27 , V_324 ) < 0 ) {
F_155 ( V_31 , V_332 ) ;
return 0 ;
}
F_180 ( V_312 , & V_4 , V_27 ) ;
if ( V_312 -> V_313 ) {
int V_115 ;
for ( V_115 = V_312 -> V_313 -> V_150 - 1 ; V_115 >= 0 ; V_115 -- ) {
struct V_38 * V_39 = V_312 -> V_313 -> V_314 [ V_115 ] ;
if ( ! F_6 ( & V_39 -> V_2 , & V_4 , V_27 ) ) {
F_155 ( V_31 , V_333 ) ;
return 0 ;
}
}
}
V_79 = NULL ;
if ( V_192 && V_192 -> V_193 [ V_58 ] ) {
V_79 = F_111 ( V_192 , V_58 , & V_4 ) ;
if ( F_14 ( V_79 ) ) {
F_155 ( V_31 , V_334 ) ;
return 0 ;
}
}
if ( ! V_79 ) {
struct V_77 * V_78 ;
V_78 = F_162 ( V_31 , & V_4 , V_27 , V_329 ,
F_107 , NULL ) ;
if ( F_108 ( V_78 ) )
V_79 = F_109 ( V_78 ) ;
else
V_79 = F_27 ( V_78 , struct V_52 , V_78 ) ;
}
if ( F_14 ( V_79 ) ) {
F_155 ( V_31 , V_334 ) ;
return 0 ;
}
if ( ! V_79 ) {
if ( V_312 -> V_313 && F_177 ( V_312 -> V_313 , 0 , & V_330 ) ) {
F_169 ( V_330 , V_312 , & V_4 ) ;
F_155 ( V_31 , V_335 ) ;
return 0 ;
}
return 1 ;
}
V_79 -> V_67 . V_71 = F_17 () ;
V_221 [ 0 ] = V_79 ;
V_222 ++ ;
#ifdef F_106
if ( V_221 [ 0 ] -> type != V_186 ) {
V_221 [ 1 ] = F_102 ( V_31 , V_186 ,
& V_4 , V_27 ,
V_127 ) ;
if ( V_221 [ 1 ] ) {
if ( F_14 ( V_221 [ 1 ] ) ) {
F_155 ( V_31 , V_334 ) ;
return 0 ;
}
V_221 [ 1 ] -> V_67 . V_71 = F_17 () ;
V_222 ++ ;
}
}
#endif
if ( V_79 -> V_200 == V_276 ) {
struct V_322 * V_313 ;
static struct V_322 V_336 ;
struct V_203 * V_223 [ V_224 ] ;
struct V_203 * V_337 [ V_224 ] ;
struct V_203 * * V_225 = V_223 ;
int V_338 = 0 ;
int V_115 , V_326 ;
if ( ( V_313 = V_312 -> V_313 ) == NULL )
V_313 = & V_336 ;
for ( V_328 = 0 ; V_328 < V_222 ; V_328 ++ ) {
if ( V_221 [ V_328 ] != V_79 &&
V_221 [ V_328 ] -> V_200 != V_276 ) {
F_155 ( V_31 , V_339 ) ;
goto V_315;
}
if ( V_338 + V_221 [ V_328 ] -> V_201 >= V_224 ) {
F_155 ( V_31 , V_340 ) ;
goto V_341;
}
for ( V_115 = 0 ; V_115 < V_221 [ V_328 ] -> V_201 ; V_115 ++ )
V_225 [ V_338 ++ ] = & V_221 [ V_328 ] -> V_202 [ V_115 ] ;
}
V_201 = V_338 ;
if ( V_222 > 1 ) {
F_181 ( V_337 , V_225 , V_201 , V_27 ) ;
V_225 = V_337 ;
}
for ( V_115 = V_201 - 1 , V_326 = 0 ; V_115 >= 0 ; V_115 -- ) {
V_326 = F_174 ( V_225 [ V_115 ] , V_313 , V_326 , V_27 ) ;
if ( V_326 < 0 ) {
if ( V_326 < - 1 )
V_330 = - ( 2 + V_326 ) ;
F_155 ( V_31 , V_342 ) ;
goto V_315;
}
}
if ( F_177 ( V_313 , V_326 , & V_330 ) ) {
F_155 ( V_31 , V_342 ) ;
goto V_315;
}
F_153 ( V_221 , V_222 ) ;
return 1 ;
}
F_155 ( V_31 , V_339 ) ;
V_315:
F_169 ( V_330 , V_312 , & V_4 ) ;
V_341:
F_153 ( V_221 , V_222 ) ;
return 0 ;
}
int F_182 ( struct V_311 * V_312 , unsigned short V_27 )
{
struct V_31 * V_31 = F_179 ( V_312 -> V_245 ) ;
struct V_3 V_4 ;
struct V_30 * V_35 ;
int V_343 = 1 ;
if ( F_183 ( V_312 , & V_4 , V_27 ) < 0 ) {
F_155 ( V_31 , V_344 ) ;
return 0 ;
}
F_184 ( V_312 ) ;
V_35 = F_159 ( V_31 , F_185 ( V_312 ) , & V_4 , NULL , 0 ) ;
if ( F_14 ( V_35 ) ) {
V_343 = 0 ;
V_35 = NULL ;
}
F_186 ( V_312 , V_35 ) ;
return V_343 ;
}
static struct V_30 * F_187 ( struct V_30 * V_35 , T_3 V_345 )
{
if ( V_35 -> V_260 < 0 && ! F_127 ( V_35 ) )
return V_35 ;
return NULL ;
}
static int F_127 ( struct V_30 * V_35 )
{
return ! F_188 ( (struct V_229 * ) V_35 ) ;
}
void F_189 ( struct V_30 * V_35 , struct V_244 * V_245 )
{
while ( ( V_35 = V_35 -> V_256 ) && V_35 -> V_91 && V_35 -> V_245 == V_245 ) {
V_35 -> V_245 = F_179 ( V_245 ) -> V_346 ;
F_190 ( V_35 -> V_245 ) ;
F_191 ( V_245 ) ;
}
}
static void F_192 ( struct V_311 * V_312 )
{
}
static struct V_30 * F_193 ( struct V_30 * V_35 )
{
if ( V_35 ) {
if ( V_35 -> V_260 ) {
F_141 ( V_35 ) ;
V_35 = NULL ;
}
}
return V_35 ;
}
static void F_194 ( struct V_31 * V_31 )
{
struct V_30 * V_347 , * V_55 ;
F_195 () ;
F_160 ( & V_292 ) ;
V_347 = V_293 ;
V_293 = NULL ;
F_161 ( & V_292 ) ;
while ( V_347 ) {
V_55 = V_347 -> V_55 ;
F_131 ( V_347 ) ;
V_347 = V_55 ;
}
}
static void F_147 ( struct V_30 * V_35 )
{
do {
struct V_229 * V_230 = (struct V_229 * ) V_35 ;
T_3 V_348 , V_349 ;
V_348 = F_196 ( V_35 -> V_256 ) ;
V_230 -> V_350 = V_348 ;
V_348 = F_197 ( V_35 -> V_91 , V_348 ) ;
V_349 = F_196 ( V_230 -> V_231 ) ;
V_230 -> V_349 = V_349 ;
if ( V_348 > V_349 )
V_348 = V_349 ;
F_198 ( V_35 , V_351 , V_348 ) ;
} while ( ( V_35 = V_35 -> V_55 ) );
}
static int F_188 ( struct V_229 * V_352 )
{
struct V_30 * V_35 = & V_352 -> V_7 . V_35 ;
struct V_229 * V_353 ;
T_3 V_354 ;
if ( ! F_199 ( V_35 -> V_241 , ( (struct V_229 * ) V_35 ) -> V_355 ) ||
( V_35 -> V_245 && ! F_200 ( V_35 -> V_245 ) ) )
return 0 ;
V_353 = NULL ;
do {
struct V_229 * V_230 = (struct V_229 * ) V_35 ;
if ( V_35 -> V_91 -> V_215 . V_216 != V_217 )
return 0 ;
if ( V_230 -> V_259 != V_35 -> V_91 -> V_90 )
return 0 ;
if ( V_230 -> V_275 > 0 &&
V_230 -> V_281 != F_156 ( & V_230 -> V_221 [ 0 ] -> V_90 ) )
return 0 ;
V_354 = F_196 ( V_35 -> V_256 ) ;
if ( V_230 -> V_350 != V_354 ) {
V_353 = V_230 ;
V_230 -> V_350 = V_354 ;
}
if ( ! F_199 ( V_230 -> V_231 , V_230 -> V_356 ) )
return 0 ;
V_354 = F_196 ( V_230 -> V_231 ) ;
if ( V_230 -> V_349 != V_354 ) {
V_353 = V_230 ;
V_230 -> V_349 = V_354 ;
}
V_35 = V_35 -> V_256 ;
} while ( V_35 -> V_91 );
if ( F_135 ( ! V_353 ) )
return 1 ;
V_354 = V_353 -> V_350 ;
for (; ; ) {
V_35 = & V_353 -> V_7 . V_35 ;
V_354 = F_197 ( V_35 -> V_91 , V_354 ) ;
if ( V_354 > V_353 -> V_349 )
V_354 = V_353 -> V_349 ;
F_198 ( V_35 , V_351 , V_354 ) ;
if ( V_353 == V_352 )
break;
V_353 = (struct V_229 * ) V_353 -> V_7 . V_35 . V_55 ;
V_353 -> V_350 = V_354 ;
}
return 1 ;
}
static unsigned int F_201 ( const struct V_30 * V_35 )
{
return F_202 ( V_35 -> V_241 ) ;
}
static unsigned int F_203 ( const struct V_30 * V_35 )
{
return F_196 ( V_35 -> V_241 ) ;
}
int F_204 ( struct V_33 * V_34 )
{
struct V_31 * V_31 ;
int V_165 = 0 ;
if ( F_9 ( V_34 == NULL ) )
return - V_179 ;
if ( F_9 ( V_34 -> V_27 >= V_357 ) )
return - V_36 ;
F_62 ( & V_358 ) ;
if ( F_9 ( V_33 [ V_34 -> V_27 ] != NULL ) )
V_165 = - V_227 ;
else {
struct V_233 * V_233 = V_34 -> V_233 ;
if ( F_135 ( V_233 -> V_359 == NULL ) )
V_233 -> V_359 = V_360 ;
if ( F_135 ( V_233 -> V_361 == NULL ) )
V_233 -> V_361 = F_187 ;
if ( F_135 ( V_233 -> V_362 == NULL ) )
V_233 -> V_362 = F_201 ;
if ( F_135 ( V_233 -> V_363 == NULL ) )
V_233 -> V_363 = F_203 ;
if ( F_135 ( V_233 -> V_364 == NULL ) )
V_233 -> V_364 = F_193 ;
if ( F_135 ( V_233 -> V_365 == NULL ) )
V_233 -> V_365 = F_192 ;
if ( F_135 ( V_34 -> V_366 == NULL ) )
V_34 -> V_366 = F_194 ;
V_33 [ V_34 -> V_27 ] = V_34 ;
}
F_63 ( & V_358 ) ;
F_205 () ;
F_206 (net) {
struct V_233 * V_367 ;
switch ( V_34 -> V_27 ) {
case V_28 :
V_367 = & V_31 -> V_91 . V_234 ;
break;
#if F_133 ( V_235 ) || F_133 ( V_236 )
case V_29 :
V_367 = & V_31 -> V_91 . V_237 ;
break;
#endif
default:
F_41 () ;
}
* V_367 = * V_34 -> V_233 ;
}
F_207 () ;
return V_165 ;
}
int F_208 ( struct V_33 * V_34 )
{
int V_165 = 0 ;
if ( F_9 ( V_34 == NULL ) )
return - V_179 ;
if ( F_9 ( V_34 -> V_27 >= V_357 ) )
return - V_36 ;
F_62 ( & V_358 ) ;
if ( F_135 ( V_33 [ V_34 -> V_27 ] != NULL ) ) {
if ( F_9 ( V_33 [ V_34 -> V_27 ] != V_34 ) )
V_165 = - V_179 ;
else {
struct V_233 * V_233 = V_34 -> V_233 ;
V_33 [ V_34 -> V_27 ] = NULL ;
V_233 -> V_359 = NULL ;
V_233 -> V_361 = NULL ;
V_233 -> V_364 = NULL ;
V_233 -> V_365 = NULL ;
V_34 -> V_366 = NULL ;
}
}
F_63 ( & V_358 ) ;
return V_165 ;
}
static void T_6 F_209 ( struct V_31 * V_31 )
{
struct V_33 * V_34 ;
F_69 ( & V_358 ) ;
V_34 = V_33 [ V_28 ] ;
if ( V_34 )
V_31 -> V_91 . V_234 = * V_34 -> V_233 ;
#if F_133 ( V_235 ) || F_133 ( V_236 )
V_34 = V_33 [ V_29 ] ;
if ( V_34 )
V_31 -> V_91 . V_237 = * V_34 -> V_233 ;
#endif
F_70 ( & V_358 ) ;
}
static struct V_33 * F_8 ( unsigned short V_27 )
{
struct V_33 * V_34 ;
if ( F_9 ( V_27 >= V_357 ) )
return NULL ;
F_18 ( & V_358 ) ;
V_34 = V_33 [ V_27 ] ;
if ( F_9 ( ! V_34 ) )
F_23 ( & V_358 ) ;
return V_34 ;
}
static void F_11 ( struct V_33 * V_34 )
{
F_23 ( & V_358 ) ;
}
static int F_210 ( struct V_368 * V_369 , unsigned long V_370 , void * V_371 )
{
struct V_244 * V_245 = V_371 ;
switch ( V_370 ) {
case V_372 :
F_194 ( F_179 ( V_245 ) ) ;
}
return V_373 ;
}
static int T_6 F_211 ( struct V_31 * V_31 )
{
int V_374 ;
if ( F_212 ( ( void V_375 * * ) V_31 -> V_376 . V_377 ,
sizeof( struct V_378 ) ,
F_213 ( struct V_378 ) ) < 0 )
return - V_205 ;
V_374 = F_214 ( V_31 ) ;
if ( V_374 < 0 )
F_215 ( ( void V_375 * * ) V_31 -> V_376 . V_377 ) ;
return V_374 ;
}
static void F_216 ( struct V_31 * V_31 )
{
F_217 ( V_31 ) ;
F_215 ( ( void V_375 * * ) V_31 -> V_376 . V_377 ) ;
}
static int T_6 F_211 ( struct V_31 * V_31 )
{
return 0 ;
}
static void F_216 ( struct V_31 * V_31 )
{
}
static int T_6 F_218 ( struct V_31 * V_31 )
{
unsigned int V_94 , V_379 ;
int V_58 ;
if ( F_219 ( V_31 , & V_380 ) )
V_360 = F_220 ( L_1 ,
sizeof( struct V_229 ) ,
0 , V_381 | V_382 ,
NULL ) ;
V_94 = 8 - 1 ;
V_379 = ( V_94 + 1 ) * sizeof( struct V_93 ) ;
V_31 -> V_91 . V_119 = F_61 ( V_379 ) ;
if ( ! V_31 -> V_91 . V_119 )
goto V_383;
V_31 -> V_91 . V_92 = V_94 ;
for ( V_58 = 0 ; V_58 < V_133 * 2 ; V_58 ++ ) {
struct V_384 * V_385 ;
V_31 -> V_91 . V_122 [ V_58 ] = 0 ;
F_221 ( & V_31 -> V_91 . V_97 [ V_58 ] ) ;
V_385 = & V_31 -> V_91 . V_95 [ V_58 ] ;
V_385 -> V_98 = F_61 ( V_379 ) ;
if ( ! V_385 -> V_98 )
goto V_386;
V_385 -> V_94 = V_94 ;
}
F_33 ( & V_31 -> V_91 . V_161 ) ;
F_222 ( & V_31 -> V_91 . V_140 , F_71 ) ;
if ( F_219 ( V_31 , & V_380 ) )
F_223 ( & V_387 ) ;
return 0 ;
V_386:
for ( V_58 -- ; V_58 >= 0 ; V_58 -- ) {
struct V_384 * V_385 ;
V_385 = & V_31 -> V_91 . V_95 [ V_58 ] ;
F_64 ( V_385 -> V_98 , V_379 ) ;
}
F_64 ( V_31 -> V_91 . V_119 , V_379 ) ;
V_383:
return - V_205 ;
}
static void F_224 ( struct V_31 * V_31 )
{
struct V_168 V_169 ;
unsigned int V_379 ;
int V_58 ;
F_225 ( & V_31 -> V_91 . V_140 ) ;
#ifdef F_106
V_169 . V_170 = - 1 ;
V_169 . V_171 = - 1 ;
V_169 . V_172 = 0 ;
F_88 ( V_31 , V_185 , & V_169 ) ;
#endif
V_169 . V_170 = - 1 ;
V_169 . V_171 = - 1 ;
V_169 . V_172 = 0 ;
F_88 ( V_31 , V_186 , & V_169 ) ;
F_79 ( ! F_91 ( & V_31 -> V_91 . V_161 ) ) ;
for ( V_58 = 0 ; V_58 < V_133 * 2 ; V_58 ++ ) {
struct V_384 * V_385 ;
F_79 ( ! F_57 ( & V_31 -> V_91 . V_97 [ V_58 ] ) ) ;
V_385 = & V_31 -> V_91 . V_95 [ V_58 ] ;
V_379 = ( V_385 -> V_94 + 1 ) ;
F_79 ( ! F_57 ( V_385 -> V_98 ) ) ;
F_64 ( V_385 -> V_98 , V_379 ) ;
}
V_379 = ( V_31 -> V_91 . V_92 + 1 ) * sizeof( struct V_93 ) ;
F_79 ( ! F_57 ( V_31 -> V_91 . V_119 ) ) ;
F_64 ( V_31 -> V_91 . V_119 , V_379 ) ;
}
static int T_6 F_226 ( struct V_31 * V_31 )
{
int V_374 ;
V_374 = F_211 ( V_31 ) ;
if ( V_374 < 0 )
goto V_388;
V_374 = F_227 ( V_31 ) ;
if ( V_374 < 0 )
goto V_389;
V_374 = F_218 ( V_31 ) ;
if ( V_374 < 0 )
goto V_390;
F_209 ( V_31 ) ;
V_374 = F_228 ( V_31 ) ;
if ( V_374 < 0 )
goto V_391;
return 0 ;
V_391:
F_224 ( V_31 ) ;
V_390:
F_229 ( V_31 ) ;
V_389:
F_216 ( V_31 ) ;
V_388:
return V_374 ;
}
static void T_7 F_230 ( struct V_31 * V_31 )
{
F_231 ( V_31 ) ;
F_224 ( V_31 ) ;
F_229 ( V_31 ) ;
F_216 ( V_31 ) ;
}
void T_8 F_232 ( void )
{
F_233 ( & V_392 ) ;
F_234 () ;
}
static void F_235 ( struct V_52 * V_53 ,
struct V_393 * V_394 )
{
struct V_162 * V_163 = V_53 -> V_89 ;
struct V_1 * V_2 = & V_53 -> V_109 ;
if ( V_163 )
F_236 ( V_394 , L_2 ,
V_163 -> V_395 , V_163 -> V_396 , V_163 -> V_397 ) ;
switch( V_2 -> V_27 ) {
case V_28 :
F_236 ( V_394 , L_3 , & V_2 -> V_11 . V_398 ) ;
if ( V_2 -> V_12 != 32 )
F_236 ( V_394 , L_4 ,
V_2 -> V_12 ) ;
F_236 ( V_394 , L_5 , & V_2 -> V_9 . V_398 ) ;
if ( V_2 -> V_10 != 32 )
F_236 ( V_394 , L_6 ,
V_2 -> V_10 ) ;
break;
case V_29 :
F_236 ( V_394 , L_7 , V_2 -> V_11 . V_399 ) ;
if ( V_2 -> V_12 != 128 )
F_236 ( V_394 , L_4 ,
V_2 -> V_12 ) ;
F_236 ( V_394 , L_8 , V_2 -> V_9 . V_399 ) ;
if ( V_2 -> V_10 != 128 )
F_236 ( V_394 , L_6 ,
V_2 -> V_10 ) ;
break;
}
}
void F_237 ( struct V_52 * V_53 , int V_400 ,
T_9 V_401 , T_3 V_171 , T_3 V_172 )
{
struct V_393 * V_394 ;
V_394 = F_238 ( L_9 ) ;
if ( V_394 == NULL )
return;
F_239 ( V_401 , V_171 , V_172 , V_394 ) ;
F_236 ( V_394 , L_10 , V_400 ) ;
F_235 ( V_53 , V_394 ) ;
F_240 ( V_394 ) ;
}
void F_87 ( struct V_52 * V_53 , int V_400 ,
T_9 V_401 , T_3 V_171 , T_3 V_172 )
{
struct V_393 * V_394 ;
V_394 = F_238 ( L_11 ) ;
if ( V_394 == NULL )
return;
F_239 ( V_401 , V_171 , V_172 , V_394 ) ;
F_236 ( V_394 , L_10 , V_400 ) ;
F_235 ( V_53 , V_394 ) ;
F_240 ( V_394 ) ;
}
static int F_241 ( const struct V_1 * V_402 ,
const struct V_1 * V_403 )
{
if ( V_402 -> V_19 == V_404 ) {
if ( V_403 -> V_27 == V_402 -> V_27 &&
F_242 ( & V_403 -> V_9 , & V_402 -> V_9 ,
V_402 -> V_27 ) == 0 &&
F_242 ( & V_403 -> V_11 , & V_402 -> V_11 ,
V_402 -> V_27 ) == 0 &&
V_403 -> V_10 == V_402 -> V_10 &&
V_403 -> V_12 == V_402 -> V_12 ) {
return 1 ;
}
} else {
if ( memcmp ( V_403 , V_402 , sizeof( * V_403 ) ) == 0 ) {
return 1 ;
}
}
return 0 ;
}
static struct V_52 * F_243 ( const struct V_1 * V_2 ,
T_4 V_58 , T_4 type )
{
struct V_52 * V_79 , * V_166 = NULL ;
struct V_102 * V_103 ;
struct V_93 * V_153 ;
T_3 V_159 = ~ 0U ;
F_69 ( & V_116 ) ;
V_153 = F_50 ( & V_380 , & V_2 -> V_9 , & V_2 -> V_11 , V_2 -> V_27 , V_58 ) ;
F_75 (pol, entry, chain, bydst) {
if ( F_241 ( V_2 , & V_79 -> V_109 ) &&
V_79 -> type == type ) {
V_166 = V_79 ;
V_159 = V_166 -> V_159 ;
break;
}
}
V_153 = & V_380 . V_91 . V_97 [ V_58 ] ;
F_75 (pol, entry, chain, bydst) {
if ( F_241 ( V_2 , & V_79 -> V_109 ) &&
V_79 -> type == type &&
V_79 -> V_159 < V_159 ) {
V_166 = V_79 ;
break;
}
}
if ( V_166 )
F_22 ( V_166 ) ;
F_70 ( & V_116 ) ;
return V_166 ;
}
static int F_244 ( const struct V_405 * V_157 , const struct V_203 * V_406 )
{
int V_181 = 0 ;
if ( V_406 -> V_211 == V_157 -> V_211 && V_406 -> V_43 . V_19 == V_157 -> V_19 &&
( V_157 -> V_317 == 0 || V_406 -> V_317 == V_157 -> V_317 ) ) {
switch ( V_406 -> V_211 ) {
case V_212 :
case V_213 :
if ( F_242 ( & V_406 -> V_43 . V_9 , & V_157 -> V_407 ,
V_157 -> V_408 ) == 0 &&
F_242 ( & V_406 -> V_11 , & V_157 -> V_409 ,
V_157 -> V_408 ) == 0 ) {
V_181 = 1 ;
}
break;
case V_258 :
V_181 = 1 ;
break;
default:
break;
}
}
return V_181 ;
}
static int F_245 ( struct V_52 * V_79 ,
struct V_405 * V_157 , int V_410 )
{
struct V_405 * V_411 ;
int V_115 , V_412 , V_413 = 0 ;
F_62 ( & V_79 -> V_59 ) ;
if ( F_9 ( V_79 -> V_60 . V_61 ) ) {
F_63 ( & V_79 -> V_59 ) ;
return - V_167 ;
}
for ( V_115 = 0 ; V_115 < V_79 -> V_201 ; V_115 ++ ) {
for ( V_412 = 0 , V_411 = V_157 ; V_412 < V_410 ; V_412 ++ , V_411 ++ ) {
if ( ! F_244 ( V_411 , & V_79 -> V_202 [ V_115 ] ) )
continue;
V_413 ++ ;
if ( V_79 -> V_202 [ V_115 ] . V_211 != V_212 &&
V_79 -> V_202 [ V_115 ] . V_211 != V_213 )
continue;
memcpy ( & V_79 -> V_202 [ V_115 ] . V_43 . V_9 , & V_411 -> V_414 ,
sizeof( V_79 -> V_202 [ V_115 ] . V_43 . V_9 ) ) ;
memcpy ( & V_79 -> V_202 [ V_115 ] . V_11 , & V_411 -> V_415 ,
sizeof( V_79 -> V_202 [ V_115 ] . V_11 ) ) ;
V_79 -> V_202 [ V_115 ] . V_214 = V_411 -> V_416 ;
F_45 ( & V_79 -> V_90 ) ;
}
}
F_63 ( & V_79 -> V_59 ) ;
if ( ! V_413 )
return - V_417 ;
return 0 ;
}
static int F_246 ( const struct V_405 * V_157 , int V_410 )
{
int V_115 , V_412 ;
if ( V_410 < 1 || V_410 > V_224 )
return - V_179 ;
for ( V_115 = 0 ; V_115 < V_410 ; V_115 ++ ) {
if ( ( F_242 ( & V_157 [ V_115 ] . V_407 , & V_157 [ V_115 ] . V_414 ,
V_157 [ V_115 ] . V_408 ) == 0 ) &&
( F_242 ( & V_157 [ V_115 ] . V_409 , & V_157 [ V_115 ] . V_415 ,
V_157 [ V_115 ] . V_408 ) == 0 ) )
return - V_179 ;
if ( F_120 ( & V_157 [ V_115 ] . V_414 , V_157 [ V_115 ] . V_416 ) ||
F_120 ( & V_157 [ V_115 ] . V_415 , V_157 [ V_115 ] . V_416 ) )
return - V_179 ;
for ( V_412 = V_115 + 1 ; V_412 < V_410 ; V_412 ++ ) {
if ( ! memcmp ( & V_157 [ V_115 ] . V_407 , & V_157 [ V_412 ] . V_407 ,
sizeof( V_157 [ V_115 ] . V_407 ) ) &&
! memcmp ( & V_157 [ V_115 ] . V_409 , & V_157 [ V_412 ] . V_409 ,
sizeof( V_157 [ V_115 ] . V_409 ) ) &&
V_157 [ V_115 ] . V_19 == V_157 [ V_412 ] . V_19 &&
V_157 [ V_115 ] . V_211 == V_157 [ V_412 ] . V_211 &&
V_157 [ V_115 ] . V_317 == V_157 [ V_412 ] . V_317 &&
V_157 [ V_115 ] . V_408 == V_157 [ V_412 ] . V_408 )
return - V_179 ;
}
}
return 0 ;
}
int V_405 ( const struct V_1 * V_2 , T_4 V_58 , T_4 type ,
struct V_405 * V_157 , int V_410 ,
struct V_418 * V_326 )
{
int V_115 , V_165 , V_419 = 0 , V_420 = 0 ;
struct V_52 * V_79 = NULL ;
struct V_38 * V_39 , * V_421 ;
struct V_38 * V_422 [ V_224 ] ;
struct V_38 * V_423 [ V_224 ] ;
struct V_405 * V_411 ;
if ( ( V_165 = F_246 ( V_157 , V_410 ) ) < 0 )
goto V_62;
if ( ( V_79 = F_243 ( V_2 , V_58 , type ) ) == NULL ) {
V_165 = - V_167 ;
goto V_62;
}
for ( V_115 = 0 , V_411 = V_157 ; V_115 < V_410 ; V_115 ++ , V_411 ++ ) {
if ( ( V_39 = F_247 ( V_411 ) ) ) {
V_422 [ V_419 ] = V_39 ;
V_419 ++ ;
if ( ( V_421 = F_248 ( V_39 , V_411 ) ) ) {
V_423 [ V_420 ] = V_421 ;
V_420 ++ ;
} else {
V_165 = - V_417 ;
goto V_424;
}
}
}
if ( ( V_165 = F_245 ( V_79 , V_157 , V_410 ) ) < 0 )
goto V_424;
if ( V_419 ) {
F_249 ( V_422 , V_419 ) ;
F_250 ( V_422 , V_419 ) ;
}
F_251 ( V_2 , V_58 , type , V_157 , V_410 , V_326 ) ;
F_24 ( V_79 ) ;
return 0 ;
V_62:
return V_165 ;
V_424:
if ( V_79 )
F_24 ( V_79 ) ;
if ( V_419 )
F_249 ( V_422 , V_419 ) ;
if ( V_420 )
F_250 ( V_423 , V_420 ) ;
return V_165 ;
}
