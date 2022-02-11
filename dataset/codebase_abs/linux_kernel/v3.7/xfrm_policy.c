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
F_41 ( & V_83 -> V_77 , F_20 ,
( unsigned long ) V_83 ) ;
V_83 -> V_80 . V_89 = & V_90 ;
}
return V_83 ;
}
void F_42 ( struct V_54 * V_83 )
{
F_43 ( ! V_83 -> V_62 . V_63 ) ;
if ( F_44 ( & V_83 -> V_77 ) )
F_45 () ;
F_46 ( V_83 -> V_91 ) ;
F_47 ( V_83 ) ;
}
static void F_48 ( struct V_54 * V_83 )
{
V_83 -> V_62 . V_63 = 1 ;
F_49 ( & V_83 -> V_92 ) ;
if ( F_44 ( & V_83 -> V_77 ) )
F_28 ( V_83 ) ;
F_28 ( V_83 ) ;
}
static inline unsigned int F_50 ( struct V_35 * V_35 , T_3 V_65 )
{
return F_51 ( V_65 , V_35 -> V_93 . V_94 ) ;
}
static struct V_95 * F_52 ( struct V_35 * V_35 ,
const struct V_1 * V_2 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_96 = V_35 -> V_93 . V_97 [ V_60 ] . V_96 ;
unsigned int V_98 = F_53 ( V_2 , V_28 , V_96 ) ;
return ( V_98 == V_96 + 1 ?
& V_35 -> V_93 . V_99 [ V_60 ] :
V_35 -> V_93 . V_97 [ V_60 ] . V_100 + V_98 ) ;
}
static struct V_95 * F_54 ( struct V_35 * V_35 ,
const T_1 * V_9 ,
const T_1 * V_12 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_96 = V_35 -> V_93 . V_97 [ V_60 ] . V_96 ;
unsigned int V_98 = F_55 ( V_9 , V_12 , V_28 , V_96 ) ;
return V_35 -> V_93 . V_97 [ V_60 ] . V_100 + V_98 ;
}
static void F_56 ( struct V_95 * V_101 ,
struct V_95 * V_102 ,
unsigned int V_103 )
{
struct V_104 * V_105 , * V_106 , * V_107 = NULL ;
struct V_54 * V_81 ;
unsigned int V_108 = 0 ;
V_109:
F_57 (pol, entry, tmp, list, bydst) {
unsigned int V_110 ;
V_110 = F_55 ( & V_81 -> V_111 . V_9 , & V_81 -> V_111 . V_12 ,
V_81 -> V_28 , V_103 ) ;
if ( ! V_107 ) {
F_58 ( V_105 ) ;
F_59 ( & V_81 -> V_86 , V_102 + V_110 ) ;
V_108 = V_110 ;
} else {
if ( V_110 != V_108 )
continue;
F_58 ( V_105 ) ;
F_60 ( V_107 , & V_81 -> V_86 ) ;
}
V_107 = V_105 ;
}
if ( ! F_61 ( V_101 ) ) {
V_107 = NULL ;
goto V_109;
}
}
static void F_62 ( struct V_95 * V_101 ,
struct V_95 * V_112 ,
unsigned int V_103 )
{
struct V_104 * V_105 , * V_106 ;
struct V_54 * V_81 ;
F_57 (pol, entry, tmp, list, byidx) {
unsigned int V_110 ;
V_110 = F_51 ( V_81 -> V_65 , V_103 ) ;
F_59 ( & V_81 -> V_87 , V_112 + V_110 ) ;
}
}
static unsigned long F_63 ( unsigned int V_113 )
{
return ( ( V_113 + 1 ) << 1 ) - 1 ;
}
static void F_64 ( struct V_35 * V_35 , int V_60 )
{
unsigned int V_96 = V_35 -> V_93 . V_97 [ V_60 ] . V_96 ;
unsigned int V_103 = F_63 ( V_96 ) ;
unsigned int V_114 = ( V_103 + 1 ) * sizeof( struct V_95 ) ;
struct V_95 * V_115 = V_35 -> V_93 . V_97 [ V_60 ] . V_100 ;
struct V_95 * V_116 = F_65 ( V_114 ) ;
int V_117 ;
if ( ! V_116 )
return;
F_66 ( & V_118 ) ;
for ( V_117 = V_96 ; V_117 >= 0 ; V_117 -- )
F_56 ( V_115 + V_117 , V_116 , V_103 ) ;
V_35 -> V_93 . V_97 [ V_60 ] . V_100 = V_116 ;
V_35 -> V_93 . V_97 [ V_60 ] . V_96 = V_103 ;
F_67 ( & V_118 ) ;
F_68 ( V_115 , ( V_96 + 1 ) * sizeof( struct V_95 ) ) ;
}
static void F_69 ( struct V_35 * V_35 , int V_119 )
{
unsigned int V_96 = V_35 -> V_93 . V_94 ;
unsigned int V_103 = F_63 ( V_96 ) ;
unsigned int V_114 = ( V_103 + 1 ) * sizeof( struct V_95 ) ;
struct V_95 * V_120 = V_35 -> V_93 . V_121 ;
struct V_95 * V_122 = F_65 ( V_114 ) ;
int V_117 ;
if ( ! V_122 )
return;
F_66 ( & V_118 ) ;
for ( V_117 = V_96 ; V_117 >= 0 ; V_117 -- )
F_62 ( V_120 + V_117 , V_122 , V_103 ) ;
V_35 -> V_93 . V_121 = V_122 ;
V_35 -> V_93 . V_94 = V_103 ;
F_67 ( & V_118 ) ;
F_68 ( V_120 , ( V_96 + 1 ) * sizeof( struct V_95 ) ) ;
}
static inline int F_70 ( struct V_35 * V_35 , int V_60 , int * V_119 )
{
unsigned int V_123 = V_35 -> V_93 . V_124 [ V_60 ] ;
unsigned int V_96 = V_35 -> V_93 . V_97 [ V_60 ] . V_96 ;
if ( V_119 )
* V_119 += V_123 ;
if ( ( V_96 + 1 ) < V_125 &&
V_123 > V_96 )
return 1 ;
return 0 ;
}
static inline int F_71 ( struct V_35 * V_35 , int V_119 )
{
unsigned int V_96 = V_35 -> V_93 . V_94 ;
if ( ( V_96 + 1 ) < V_125 &&
V_119 > V_96 )
return 1 ;
return 0 ;
}
void F_72 ( struct V_35 * V_35 , struct V_126 * V_127 )
{
F_73 ( & V_118 ) ;
V_127 -> V_128 = V_35 -> V_93 . V_124 [ V_129 ] ;
V_127 -> V_130 = V_35 -> V_93 . V_124 [ V_131 ] ;
V_127 -> V_132 = V_35 -> V_93 . V_124 [ V_133 ] ;
V_127 -> V_134 = V_35 -> V_93 . V_124 [ V_129 + V_135 ] ;
V_127 -> V_136 = V_35 -> V_93 . V_124 [ V_131 + V_135 ] ;
V_127 -> V_137 = V_35 -> V_93 . V_124 [ V_133 + V_135 ] ;
V_127 -> V_138 = V_35 -> V_93 . V_94 ;
V_127 -> V_139 = V_125 ;
F_74 ( & V_118 ) ;
}
static void F_75 ( struct V_140 * V_141 )
{
struct V_35 * V_35 = F_31 ( V_141 , struct V_35 , V_93 . V_142 ) ;
int V_60 , V_119 ;
F_76 ( & V_143 ) ;
V_119 = 0 ;
for ( V_60 = 0 ; V_60 < V_135 * 2 ; V_60 ++ ) {
if ( F_70 ( V_35 , V_60 , & V_119 ) )
F_64 ( V_35 , V_60 ) ;
}
if ( F_71 ( V_35 , V_119 ) )
F_69 ( V_35 , V_119 ) ;
F_77 ( & V_143 ) ;
}
static T_3 F_78 ( struct V_35 * V_35 , int V_60 )
{
static T_3 V_144 ;
for (; ; ) {
struct V_104 * V_105 ;
struct V_95 * V_101 ;
struct V_54 * V_145 ;
T_3 V_146 ;
int V_147 ;
V_146 = ( V_144 | V_60 ) ;
V_144 += 8 ;
if ( V_146 == 0 )
V_146 = 8 ;
V_101 = V_35 -> V_93 . V_121 + F_50 ( V_35 , V_146 ) ;
V_147 = 0 ;
F_79 (p, entry, list, byidx) {
if ( V_145 -> V_65 == V_146 ) {
V_147 = 1 ;
break;
}
}
if ( ! V_147 )
return V_146 ;
}
}
static inline int F_80 ( struct V_1 * V_148 , struct V_1 * V_149 )
{
T_3 * V_150 = ( T_3 * ) V_148 ;
T_3 * V_151 = ( T_3 * ) V_149 ;
int V_152 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_152 ; V_117 ++ ) {
if ( V_150 [ V_117 ] != V_151 [ V_117 ] )
return 1 ;
}
return 0 ;
}
int F_81 ( int V_60 , struct V_54 * V_83 , int V_153 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
struct V_54 * V_81 ;
struct V_54 * V_154 ;
struct V_95 * V_155 ;
struct V_104 * V_105 , * V_156 ;
T_3 V_157 = V_83 -> V_157 . V_158 & V_83 -> V_157 . V_159 ;
F_66 ( & V_118 ) ;
V_155 = F_52 ( V_35 , & V_83 -> V_111 , V_83 -> V_28 , V_60 ) ;
V_154 = NULL ;
V_156 = NULL ;
F_79 (pol, entry, chain, bydst) {
if ( V_81 -> type == V_83 -> type &&
! F_80 ( & V_81 -> V_111 , & V_83 -> V_111 ) &&
( V_157 & V_81 -> V_157 . V_159 ) == V_81 -> V_157 . V_158 &&
F_82 ( V_81 -> V_91 , V_83 -> V_91 ) &&
! F_83 ( V_154 ) ) {
if ( V_153 ) {
F_67 ( & V_118 ) ;
return - V_160 ;
}
V_154 = V_81 ;
if ( V_83 -> V_161 > V_81 -> V_161 )
continue;
} else if ( V_83 -> V_161 >= V_81 -> V_161 ) {
V_156 = & V_81 -> V_86 ;
continue;
}
if ( V_154 )
break;
}
if ( V_156 )
F_60 ( V_156 , & V_83 -> V_86 ) ;
else
F_59 ( & V_83 -> V_86 , V_155 ) ;
F_26 ( V_83 ) ;
V_35 -> V_93 . V_124 [ V_60 ] ++ ;
F_49 ( & V_162 ) ;
F_84 ( V_35 ) ;
if ( V_154 )
F_85 ( V_154 , V_60 ) ;
V_83 -> V_65 = V_154 ? V_154 -> V_65 : F_78 ( V_35 , V_60 ) ;
F_59 ( & V_83 -> V_87 , V_35 -> V_93 . V_121 + F_50 ( V_35 , V_83 -> V_65 ) ) ;
V_83 -> V_69 . V_70 = F_21 () ;
V_83 -> V_69 . V_73 = 0 ;
if ( ! F_25 ( & V_83 -> V_77 , V_78 + V_52 ) )
F_26 ( V_83 ) ;
F_86 ( & V_83 -> V_62 . V_85 , & V_35 -> V_93 . V_163 ) ;
F_67 ( & V_118 ) ;
if ( V_154 )
F_48 ( V_154 ) ;
else if ( F_70 ( V_35 , V_60 , NULL ) )
F_87 ( & V_35 -> V_93 . V_142 ) ;
return 0 ;
}
struct V_54 * F_88 ( struct V_35 * V_35 , T_3 V_157 , T_4 type ,
int V_60 , struct V_1 * V_2 ,
struct V_164 * V_165 , int V_166 ,
int * V_167 )
{
struct V_54 * V_81 , * V_168 ;
struct V_95 * V_155 ;
struct V_104 * V_105 ;
* V_167 = 0 ;
F_66 ( & V_118 ) ;
V_155 = F_52 ( V_35 , V_2 , V_2 -> V_28 , V_60 ) ;
V_168 = NULL ;
F_79 (pol, entry, chain, bydst) {
if ( V_81 -> type == type &&
( V_157 & V_81 -> V_157 . V_159 ) == V_81 -> V_157 . V_158 &&
! F_80 ( V_2 , & V_81 -> V_111 ) &&
F_82 ( V_165 , V_81 -> V_91 ) ) {
F_26 ( V_81 ) ;
if ( V_166 ) {
* V_167 = F_89 (
V_81 -> V_91 ) ;
if ( * V_167 ) {
F_67 ( & V_118 ) ;
return V_81 ;
}
F_85 ( V_81 , V_60 ) ;
}
V_168 = V_81 ;
break;
}
}
F_67 ( & V_118 ) ;
if ( V_168 && V_166 )
F_48 ( V_168 ) ;
return V_168 ;
}
struct V_54 * F_90 ( struct V_35 * V_35 , T_3 V_157 , T_4 type ,
int V_60 , T_3 V_45 , int V_166 , int * V_167 )
{
struct V_54 * V_81 , * V_168 ;
struct V_95 * V_155 ;
struct V_104 * V_105 ;
* V_167 = - V_169 ;
if ( F_23 ( V_45 ) != V_60 )
return NULL ;
* V_167 = 0 ;
F_66 ( & V_118 ) ;
V_155 = V_35 -> V_93 . V_121 + F_50 ( V_35 , V_45 ) ;
V_168 = NULL ;
F_79 (pol, entry, chain, byidx) {
if ( V_81 -> type == type && V_81 -> V_65 == V_45 &&
( V_157 & V_81 -> V_157 . V_159 ) == V_81 -> V_157 . V_158 ) {
F_26 ( V_81 ) ;
if ( V_166 ) {
* V_167 = F_89 (
V_81 -> V_91 ) ;
if ( * V_167 ) {
F_67 ( & V_118 ) ;
return V_81 ;
}
F_85 ( V_81 , V_60 ) ;
}
V_168 = V_81 ;
break;
}
}
F_67 ( & V_118 ) ;
if ( V_168 && V_166 )
F_48 ( V_168 ) ;
return V_168 ;
}
static inline int
F_91 ( struct V_35 * V_35 , T_4 type , struct V_170 * V_171 )
{
int V_60 , V_167 = 0 ;
for ( V_60 = 0 ; V_60 < V_135 ; V_60 ++ ) {
struct V_54 * V_81 ;
struct V_104 * V_105 ;
int V_117 ;
F_79 (pol, entry,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
V_167 = F_89 ( V_81 -> V_91 ) ;
if ( V_167 ) {
F_92 ( V_81 , 0 ,
V_171 -> V_172 ,
V_171 -> V_173 ,
V_171 -> V_174 ) ;
return V_167 ;
}
}
for ( V_117 = V_35 -> V_93 . V_97 [ V_60 ] . V_96 ; V_117 >= 0 ; V_117 -- ) {
F_79 (pol, entry,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
V_167 = F_89 (
V_81 -> V_91 ) ;
if ( V_167 ) {
F_92 ( V_81 , 0 ,
V_171 -> V_172 ,
V_171 -> V_173 ,
V_171 -> V_174 ) ;
return V_167 ;
}
}
}
}
return V_167 ;
}
static inline int
F_91 ( struct V_35 * V_35 , T_4 type , struct V_170 * V_171 )
{
return 0 ;
}
int F_93 ( struct V_35 * V_35 , T_4 type , struct V_170 * V_171 )
{
int V_60 , V_167 = 0 , V_123 = 0 ;
F_66 ( & V_118 ) ;
V_167 = F_91 ( V_35 , type , V_171 ) ;
if ( V_167 )
goto V_64;
for ( V_60 = 0 ; V_60 < V_135 ; V_60 ++ ) {
struct V_54 * V_81 ;
struct V_104 * V_105 ;
int V_117 ;
V_175:
F_79 (pol, entry,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
F_85 ( V_81 , V_60 ) ;
F_67 ( & V_118 ) ;
V_123 ++ ;
F_92 ( V_81 , 1 , V_171 -> V_172 ,
V_171 -> V_173 ,
V_171 -> V_174 ) ;
F_48 ( V_81 ) ;
F_66 ( & V_118 ) ;
goto V_175;
}
for ( V_117 = V_35 -> V_93 . V_97 [ V_60 ] . V_96 ; V_117 >= 0 ; V_117 -- ) {
V_176:
F_79 (pol, entry,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
F_85 ( V_81 , V_60 ) ;
F_67 ( & V_118 ) ;
V_123 ++ ;
F_92 ( V_81 , 1 ,
V_171 -> V_172 ,
V_171 -> V_173 ,
V_171 -> V_174 ) ;
F_48 ( V_81 ) ;
F_66 ( & V_118 ) ;
goto V_176;
}
}
}
if ( ! V_123 )
V_167 = - V_177 ;
V_64:
F_67 ( & V_118 ) ;
return V_167 ;
}
int F_94 ( struct V_35 * V_35 , struct F_94 * V_62 ,
int (* F_95)( struct V_54 * , int , int , void * ) ,
void * V_53 )
{
struct V_54 * V_81 ;
struct V_178 * V_41 ;
int error = 0 ;
if ( V_62 -> type >= V_179 &&
V_62 -> type != V_180 )
return - V_181 ;
if ( F_96 ( & V_62 -> V_62 . V_85 ) && V_62 -> V_182 != 0 )
return 0 ;
F_66 ( & V_118 ) ;
if ( F_96 ( & V_62 -> V_62 . V_85 ) )
V_41 = F_97 ( & V_35 -> V_93 . V_163 , struct V_178 , V_85 ) ;
else
V_41 = F_98 ( & V_62 -> V_62 . V_85 , struct V_178 , V_85 ) ;
F_99 (x, &net->xfrm.policy_all, all) {
if ( V_41 -> V_63 )
continue;
V_81 = F_31 ( V_41 , struct V_54 , V_62 ) ;
if ( V_62 -> type != V_180 &&
V_62 -> type != V_81 -> type )
continue;
error = F_95 ( V_81 , F_23 ( V_81 -> V_65 ) ,
V_62 -> V_182 , V_53 ) ;
if ( error ) {
F_100 ( & V_62 -> V_62 . V_85 , & V_41 -> V_85 ) ;
goto V_64;
}
V_62 -> V_182 ++ ;
}
if ( V_62 -> V_182 == 0 ) {
error = - V_169 ;
goto V_64;
}
F_101 ( & V_62 -> V_62 . V_85 ) ;
V_64:
F_67 ( & V_118 ) ;
return error ;
}
void F_102 ( struct F_94 * V_62 , T_4 type )
{
F_37 ( & V_62 -> V_62 . V_85 ) ;
V_62 -> V_62 . V_63 = 1 ;
V_62 -> type = type ;
V_62 -> V_182 = 0 ;
}
void F_103 ( struct F_94 * V_62 )
{
if ( F_96 ( & V_62 -> V_62 . V_85 ) )
return;
F_66 ( & V_118 ) ;
F_104 ( & V_62 -> V_62 . V_85 ) ;
F_67 ( & V_118 ) ;
}
static int F_105 ( const struct V_54 * V_81 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_28 , int V_60 )
{
const struct V_1 * V_2 = & V_81 -> V_111 ;
int V_168 = - V_177 ;
bool V_183 ;
if ( V_81 -> V_28 != V_28 ||
( V_4 -> V_184 & V_81 -> V_157 . V_159 ) != V_81 -> V_157 . V_158 ||
V_81 -> type != type )
return V_168 ;
V_183 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_183 )
V_168 = F_106 ( V_81 -> V_91 , V_4 -> V_185 ,
V_60 ) ;
return V_168 ;
}
static struct V_54 * F_107 ( struct V_35 * V_35 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_28 , T_4 V_60 )
{
int V_167 ;
struct V_54 * V_81 , * V_168 ;
const T_1 * V_9 , * V_12 ;
struct V_104 * V_105 ;
struct V_95 * V_155 ;
T_3 V_161 = ~ 0U ;
V_9 = F_108 ( V_4 , V_28 ) ;
V_12 = F_109 ( V_4 , V_28 ) ;
if ( F_9 ( ! V_9 || ! V_12 ) )
return NULL ;
F_73 ( & V_118 ) ;
V_155 = F_54 ( V_35 , V_9 , V_12 , V_28 , V_60 ) ;
V_168 = NULL ;
F_79 (pol, entry, chain, bydst) {
V_167 = F_105 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_167 ) {
if ( V_167 == - V_177 )
continue;
else {
V_168 = F_15 ( V_167 ) ;
goto V_186;
}
} else {
V_168 = V_81 ;
V_161 = V_168 -> V_161 ;
break;
}
}
V_155 = & V_35 -> V_93 . V_99 [ V_60 ] ;
F_79 (pol, entry, chain, bydst) {
V_167 = F_105 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_167 ) {
if ( V_167 == - V_177 )
continue;
else {
V_168 = F_15 ( V_167 ) ;
goto V_186;
}
} else if ( V_81 -> V_161 < V_161 ) {
V_168 = V_81 ;
break;
}
}
if ( V_168 )
F_26 ( V_168 ) ;
V_186:
F_74 ( & V_118 ) ;
return V_168 ;
}
static struct V_54 *
F_110 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 )
{
#ifdef F_111
struct V_54 * V_81 ;
V_81 = F_107 ( V_35 , V_187 , V_4 , V_28 , V_60 ) ;
if ( V_81 != NULL )
return V_81 ;
#endif
return F_107 ( V_35 , V_188 , V_4 , V_28 , V_60 ) ;
}
static struct V_79 *
F_112 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_60 , struct V_79 * V_189 , void * V_165 )
{
struct V_54 * V_81 ;
if ( V_189 )
F_28 ( F_31 ( V_189 , struct V_54 , V_80 ) ) ;
V_81 = F_110 ( V_35 , V_4 , V_28 , V_60 ) ;
if ( F_113 ( V_81 ) )
return F_114 ( V_81 ) ;
F_26 ( V_81 ) ;
return & V_81 -> V_80 ;
}
static inline int F_115 ( int V_60 )
{
if ( V_129 == V_190 &&
V_131 == V_191 &&
V_133 == V_192 )
return V_60 ;
switch ( V_60 ) {
default:
case V_129 :
return V_190 ;
case V_131 :
return V_191 ;
case V_133 :
return V_192 ;
}
}
static struct V_54 * F_116 ( struct V_193 * V_194 , int V_60 ,
const struct V_3 * V_4 )
{
struct V_54 * V_81 ;
F_73 ( & V_118 ) ;
if ( ( V_81 = V_194 -> V_195 [ V_60 ] ) != NULL ) {
bool V_183 = F_7 ( & V_81 -> V_111 , V_4 ,
V_194 -> V_196 ) ;
int V_167 = 0 ;
if ( V_183 ) {
if ( ( V_194 -> V_197 & V_81 -> V_157 . V_159 ) != V_81 -> V_157 . V_158 ) {
V_81 = NULL ;
goto V_64;
}
V_167 = F_106 ( V_81 -> V_91 ,
V_4 -> V_185 ,
F_115 ( V_60 ) ) ;
if ( ! V_167 )
F_26 ( V_81 ) ;
else if ( V_167 == - V_177 )
V_81 = NULL ;
else
V_81 = F_15 ( V_167 ) ;
} else
V_81 = NULL ;
}
V_64:
F_74 ( & V_118 ) ;
return V_81 ;
}
static void F_117 ( struct V_54 * V_81 , int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
struct V_95 * V_155 = F_52 ( V_35 , & V_81 -> V_111 ,
V_81 -> V_28 , V_60 ) ;
F_86 ( & V_81 -> V_62 . V_85 , & V_35 -> V_93 . V_163 ) ;
F_59 ( & V_81 -> V_86 , V_155 ) ;
F_59 ( & V_81 -> V_87 , V_35 -> V_93 . V_121 + F_50 ( V_35 , V_81 -> V_65 ) ) ;
V_35 -> V_93 . V_124 [ V_60 ] ++ ;
F_26 ( V_81 ) ;
if ( F_70 ( V_35 , V_60 , NULL ) )
F_87 ( & V_35 -> V_93 . V_142 ) ;
}
static struct V_54 * F_85 ( struct V_54 * V_81 ,
int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
if ( F_118 ( & V_81 -> V_86 ) )
return NULL ;
F_58 ( & V_81 -> V_86 ) ;
F_58 ( & V_81 -> V_87 ) ;
F_104 ( & V_81 -> V_62 . V_85 ) ;
V_35 -> V_93 . V_124 [ V_60 ] -- ;
return V_81 ;
}
int F_29 ( struct V_54 * V_81 , int V_60 )
{
F_66 ( & V_118 ) ;
V_81 = F_85 ( V_81 , V_60 ) ;
F_67 ( & V_118 ) ;
if ( V_81 ) {
F_48 ( V_81 ) ;
return 0 ;
}
return - V_169 ;
}
int F_119 ( struct V_193 * V_194 , int V_60 , struct V_54 * V_81 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
struct V_54 * V_198 ;
#ifdef F_111
if ( V_81 && V_81 -> type != V_188 )
return - V_181 ;
#endif
F_66 ( & V_118 ) ;
V_198 = V_194 -> V_195 [ V_60 ] ;
V_194 -> V_195 [ V_60 ] = V_81 ;
if ( V_81 ) {
V_81 -> V_69 . V_70 = F_21 () ;
V_81 -> V_65 = F_78 ( V_35 , V_135 + V_60 ) ;
F_117 ( V_81 , V_135 + V_60 ) ;
}
if ( V_198 )
F_85 ( V_198 , V_135 + V_60 ) ;
F_67 ( & V_118 ) ;
if ( V_198 ) {
F_48 ( V_198 ) ;
}
return 0 ;
}
static struct V_54 * F_120 ( const struct V_54 * V_199 , int V_60 )
{
struct V_54 * V_200 = F_34 ( V_84 ( V_199 ) , V_201 ) ;
if ( V_200 ) {
V_200 -> V_111 = V_199 -> V_111 ;
if ( F_121 ( V_199 -> V_91 ,
& V_200 -> V_91 ) ) {
F_47 ( V_200 ) ;
return NULL ;
}
V_200 -> V_66 = V_199 -> V_66 ;
V_200 -> V_69 = V_199 -> V_69 ;
V_200 -> V_157 = V_199 -> V_157 ;
V_200 -> V_202 = V_199 -> V_202 ;
V_200 -> V_46 = V_199 -> V_46 ;
V_200 -> V_203 = V_199 -> V_203 ;
V_200 -> V_65 = V_199 -> V_65 ;
V_200 -> type = V_199 -> type ;
memcpy ( V_200 -> V_204 , V_199 -> V_204 ,
V_200 -> V_203 * sizeof( struct V_205 ) ) ;
F_66 ( & V_118 ) ;
F_117 ( V_200 , V_135 + V_60 ) ;
F_67 ( & V_118 ) ;
F_28 ( V_200 ) ;
}
return V_200 ;
}
int F_122 ( struct V_193 * V_194 )
{
struct V_54 * V_206 = V_194 -> V_195 [ 0 ] ,
* V_150 = V_194 -> V_195 [ 1 ] ;
V_194 -> V_195 [ 0 ] = V_194 -> V_195 [ 1 ] = NULL ;
if ( V_206 && ( V_194 -> V_195 [ 0 ] = F_120 ( V_206 , 0 ) ) == NULL )
return - V_207 ;
if ( V_150 && ( V_194 -> V_195 [ 1 ] = F_120 ( V_150 , 1 ) ) == NULL )
return - V_207 ;
return 0 ;
}
static int
F_123 ( struct V_35 * V_35 , T_1 * V_208 , T_1 * V_209 ,
unsigned short V_28 )
{
int V_167 ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return - V_181 ;
V_167 = V_32 -> V_210 ( V_35 , V_208 , V_209 ) ;
F_13 ( V_32 ) ;
return V_167 ;
}
static int
F_124 ( struct V_54 * V_83 , const struct V_3 * V_4 ,
struct V_40 * * V_93 , unsigned short V_28 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
int V_211 ;
int V_117 , error ;
T_1 * V_9 = F_108 ( V_4 , V_28 ) ;
T_1 * V_12 = F_109 ( V_4 , V_28 ) ;
T_1 V_106 ;
for ( V_211 = 0 , V_117 = 0 ; V_117 < V_83 -> V_203 ; V_117 ++ ) {
struct V_40 * V_41 ;
T_1 * V_209 = V_9 ;
T_1 * V_208 = V_12 ;
struct V_205 * V_212 = & V_83 -> V_204 [ V_117 ] ;
if ( V_212 -> V_213 == V_214 ||
V_212 -> V_213 == V_215 ) {
V_209 = & V_212 -> V_45 . V_9 ;
V_208 = & V_212 -> V_12 ;
if ( F_125 ( V_208 , V_212 -> V_216 ) ) {
error = F_123 ( V_35 , & V_106 , V_209 , V_212 -> V_216 ) ;
if ( error )
goto V_186;
V_208 = & V_106 ;
}
}
V_41 = F_126 ( V_209 , V_208 , V_4 , V_212 , V_83 , & error , V_28 ) ;
if ( V_41 && V_41 -> V_217 . V_218 == V_219 ) {
V_93 [ V_211 ++ ] = V_41 ;
V_9 = V_209 ;
V_12 = V_208 ;
continue;
}
if ( V_41 ) {
error = ( V_41 -> V_217 . V_218 == V_220 ?
- V_181 : - V_221 ) ;
F_127 ( V_41 ) ;
}
else if ( error == - V_177 )
error = - V_221 ;
if ( ! V_212 -> V_222 )
goto V_186;
}
return V_211 ;
V_186:
for ( V_211 -- ; V_211 >= 0 ; V_211 -- )
F_127 ( V_93 [ V_211 ] ) ;
return error ;
}
static int
F_128 ( struct V_54 * * V_223 , int V_224 , const struct V_3 * V_4 ,
struct V_40 * * V_93 , unsigned short V_28 )
{
struct V_40 * V_225 [ V_226 ] ;
struct V_40 * * V_227 = ( V_224 > 1 ) ? V_225 : V_93 ;
int V_228 = 0 ;
int error ;
int V_168 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_224 ; V_117 ++ ) {
if ( V_228 + V_223 [ V_117 ] -> V_203 >= V_226 ) {
error = - V_229 ;
goto V_186;
}
V_168 = F_124 ( V_223 [ V_117 ] , V_4 , & V_227 [ V_228 ] , V_28 ) ;
if ( V_168 < 0 ) {
error = V_168 ;
goto V_186;
} else
V_228 += V_168 ;
}
if ( V_224 > 1 )
F_129 ( V_93 , V_227 , V_228 , V_28 ) ;
return V_228 ;
V_186:
for ( V_228 -- ; V_228 >= 0 ; V_228 -- )
F_127 ( V_227 [ V_228 ] ) ;
return error ;
}
static inline int F_130 ( const struct V_3 * V_4 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_36 ;
if ( ! V_32 )
return - V_181 ;
V_36 = V_32 -> V_230 ( V_4 ) ;
F_13 ( V_32 ) ;
return V_36 ;
}
static struct V_79 * F_131 ( struct V_79 * V_80 )
{
struct V_231 * V_232 = F_31 ( V_80 , struct V_231 , V_80 ) ;
struct V_34 * V_37 = & V_232 -> V_7 . V_37 ;
if ( V_232 -> V_233 == NULL ) {
if ( V_232 -> V_234 > 0 )
return NULL ;
} else {
if ( F_132 ( V_37 ) )
return NULL ;
}
F_133 ( V_37 ) ;
return V_80 ;
}
static int F_134 ( struct V_79 * V_80 )
{
struct V_231 * V_232 = F_31 ( V_80 , struct V_231 , V_80 ) ;
struct V_34 * V_37 = & V_232 -> V_7 . V_37 ;
if ( ! V_232 -> V_233 )
return 0 ;
if ( F_132 ( V_37 ) )
return 0 ;
return 1 ;
}
static void F_135 ( struct V_79 * V_80 )
{
struct V_231 * V_232 = F_31 ( V_80 , struct V_231 , V_80 ) ;
struct V_34 * V_37 = & V_232 -> V_7 . V_37 ;
F_136 ( V_37 ) ;
}
static inline struct V_231 * F_137 ( struct V_35 * V_35 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_235 * V_235 ;
struct V_231 * V_232 ;
if ( ! V_32 )
return F_15 ( - V_181 ) ;
switch ( V_28 ) {
case V_29 :
V_235 = & V_35 -> V_93 . V_236 ;
break;
#if F_138 ( V_237 )
case V_30 :
V_235 = & V_35 -> V_93 . V_238 ;
break;
#endif
default:
F_45 () ;
}
V_232 = F_139 ( V_235 , NULL , 0 , V_239 , 0 ) ;
if ( F_140 ( V_232 ) ) {
struct V_34 * V_37 = & V_232 -> V_7 . V_37 ;
memset ( V_37 + 1 , 0 , sizeof( * V_232 ) - sizeof( * V_37 ) ) ;
V_232 -> V_80 . V_89 = & V_240 ;
if ( V_32 -> V_241 )
V_32 -> V_241 ( V_35 , V_232 ) ;
} else
V_232 = F_15 ( - V_229 ) ;
F_13 ( V_32 ) ;
return V_232 ;
}
static inline int F_141 ( struct V_231 * V_242 , struct V_34 * V_37 ,
int V_243 )
{
struct V_31 * V_32 =
F_8 ( V_37 -> V_89 -> V_28 ) ;
int V_167 ;
if ( ! V_32 )
return - V_181 ;
V_167 = V_32 -> V_244 ( V_242 , V_37 , V_243 ) ;
F_13 ( V_32 ) ;
return V_167 ;
}
static inline int F_142 ( struct V_231 * V_232 , struct V_245 * V_246 ,
const struct V_3 * V_4 )
{
struct V_31 * V_32 =
F_8 ( V_232 -> V_7 . V_37 . V_89 -> V_28 ) ;
int V_167 ;
if ( ! V_32 )
return - V_181 ;
V_167 = V_32 -> V_247 ( V_232 , V_246 , V_4 ) ;
F_13 ( V_32 ) ;
return V_167 ;
}
static struct V_34 * F_143 ( struct V_54 * V_83 ,
struct V_40 * * V_93 , int V_211 ,
const struct V_3 * V_4 ,
struct V_34 * V_37 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
unsigned long V_56 = V_78 ;
struct V_245 * V_246 ;
struct V_248 * V_249 ;
struct V_34 * V_250 = NULL ;
struct V_34 * V_251 = NULL ;
int V_117 = 0 ;
int V_167 ;
int V_252 = 0 ;
int V_243 = 0 ;
int V_253 = 0 ;
int V_36 ;
int V_28 = V_83 -> V_111 . V_28 ;
T_1 V_12 , V_9 ;
F_144 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_36 = F_130 ( V_4 , V_28 ) ;
V_167 = V_36 ;
if ( V_36 < 0 )
goto V_254;
F_133 ( V_37 ) ;
for (; V_117 < V_211 ; V_117 ++ ) {
struct V_231 * V_232 = F_137 ( V_35 , V_28 ) ;
struct V_34 * V_255 = & V_232 -> V_7 . V_37 ;
V_167 = F_145 ( V_232 ) ;
if ( F_18 ( V_232 ) ) {
F_146 ( V_37 ) ;
goto V_254;
}
if ( V_93 [ V_117 ] -> V_2 . V_28 == V_256 ) {
V_249 = F_147 ( V_93 [ V_117 ] ,
F_148 ( V_28 ) ) ;
if ( ! V_249 ) {
V_167 = - V_38 ;
F_146 ( V_37 ) ;
goto V_254;
}
} else
V_249 = V_93 [ V_117 ] -> V_249 ;
if ( ! V_250 )
V_251 = V_255 ;
else {
V_250 -> V_257 = F_149 ( V_255 ) ;
V_255 -> V_46 |= V_258 ;
}
V_232 -> V_233 = V_37 ;
F_150 ( V_255 , V_37 ) ;
if ( V_93 [ V_117 ] -> V_44 . V_213 != V_259 ) {
V_28 = V_93 [ V_117 ] -> V_44 . V_28 ;
V_37 = F_16 ( V_93 [ V_117 ] , V_36 , & V_12 , & V_9 ,
V_28 ) ;
V_167 = F_145 ( V_37 ) ;
if ( F_18 ( V_37 ) )
goto V_254;
} else
F_133 ( V_37 ) ;
V_255 -> V_93 = V_93 [ V_117 ] ;
V_232 -> V_260 = V_93 [ V_117 ] -> V_92 ;
V_255 -> V_261 = V_262 ;
V_255 -> V_46 |= V_263 ;
V_255 -> V_264 = V_56 ;
V_255 -> V_265 = V_266 ;
V_255 -> V_267 = V_249 -> V_32 -> V_267 ;
V_255 -> V_57 = V_250 ;
V_250 = V_255 ;
V_252 += V_93 [ V_117 ] -> V_44 . V_252 ;
if ( V_93 [ V_117 ] -> type -> V_46 & V_268 )
V_243 += V_93 [ V_117 ] -> V_44 . V_252 ;
V_253 += V_93 [ V_117 ] -> V_44 . V_253 ;
}
V_250 -> V_257 = V_37 ;
V_251 -> V_242 = V_37 ;
V_167 = - V_269 ;
V_246 = V_37 -> V_246 ;
if ( ! V_246 )
goto V_270;
F_141 ( (struct V_231 * ) V_251 , V_37 , V_243 ) ;
F_151 ( V_250 ) ;
for ( V_250 = V_251 ; V_250 != V_37 ; V_250 = V_250 -> V_257 ) {
struct V_231 * V_232 = (struct V_231 * ) V_250 ;
V_167 = F_142 ( V_232 , V_246 , V_4 ) ;
if ( V_167 )
goto V_270;
V_250 -> V_252 = V_252 ;
V_250 -> V_253 = V_253 ;
V_252 -= V_232 -> V_7 . V_37 . V_93 -> V_44 . V_252 ;
V_253 -= V_232 -> V_7 . V_37 . V_93 -> V_44 . V_253 ;
}
V_64:
return V_251 ;
V_254:
for (; V_117 < V_211 ; V_117 ++ )
F_127 ( V_93 [ V_117 ] ) ;
V_270:
if ( V_251 )
F_136 ( V_251 ) ;
V_251 = F_15 ( V_167 ) ;
goto V_64;
}
static int inline
F_152 ( void * * V_271 , const void * V_272 , int V_273 )
{
if ( ! * V_271 ) {
* V_271 = F_153 ( V_273 , V_201 ) ;
if ( ! * V_271 )
return - V_207 ;
}
memcpy ( * V_271 , V_272 , V_273 ) ;
return 0 ;
}
static int inline
F_154 ( struct V_34 * V_37 , const struct V_1 * V_2 )
{
#ifdef F_111
struct V_231 * V_232 = (struct V_231 * ) V_37 ;
return F_152 ( ( void * * ) & ( V_232 -> V_274 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int inline
F_155 ( struct V_34 * V_37 , const struct V_3 * V_4 )
{
#ifdef F_111
struct V_231 * V_232 = (struct V_231 * ) V_37 ;
return F_152 ( ( void * * ) & ( V_232 -> V_275 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_156 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_54 * * V_223 ,
int * V_276 , int * V_234 )
{
int V_117 ;
if ( * V_276 == 0 || ! V_223 [ 0 ] ) {
* V_276 = 0 ;
* V_234 = 0 ;
return 0 ;
}
if ( F_18 ( V_223 [ 0 ] ) )
return F_145 ( V_223 [ 0 ] ) ;
* V_234 = V_223 [ 0 ] -> V_203 ;
#ifdef F_111
if ( V_223 [ 0 ] && V_223 [ 0 ] -> V_202 == V_277 &&
V_223 [ 0 ] -> type != V_188 ) {
V_223 [ 1 ] = F_107 ( V_84 ( V_223 [ 0 ] ) ,
V_188 ,
V_4 , V_28 ,
V_131 ) ;
if ( V_223 [ 1 ] ) {
if ( F_18 ( V_223 [ 1 ] ) ) {
F_157 ( V_223 , * V_276 ) ;
return F_145 ( V_223 [ 1 ] ) ;
}
( * V_276 ) ++ ;
( * V_234 ) += V_223 [ 1 ] -> V_203 ;
}
}
#endif
for ( V_117 = 0 ; V_117 < * V_276 ; V_117 ++ ) {
if ( V_223 [ V_117 ] -> V_202 != V_277 ) {
* V_234 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_231 *
F_158 ( struct V_54 * * V_223 , int V_276 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_34 * V_278 )
{
struct V_35 * V_35 = V_84 ( V_223 [ 0 ] ) ;
struct V_40 * V_93 [ V_226 ] ;
struct V_34 * V_37 ;
struct V_231 * V_232 ;
int V_167 ;
V_167 = F_128 ( V_223 , V_276 , V_4 , V_93 , V_28 ) ;
if ( V_167 <= 0 ) {
if ( V_167 != 0 && V_167 != - V_221 )
F_159 ( V_35 , V_279 ) ;
return F_15 ( V_167 ) ;
}
V_37 = F_143 ( V_223 [ 0 ] , V_93 , V_167 , V_4 , V_278 ) ;
if ( F_18 ( V_37 ) ) {
F_159 ( V_35 , V_280 ) ;
return F_114 ( V_37 ) ;
}
V_232 = (struct V_231 * ) V_37 ;
V_232 -> V_234 = V_167 ;
if ( V_276 > 1 )
V_167 = F_154 ( V_37 , & V_223 [ 1 ] -> V_111 ) ;
else
V_167 = F_155 ( V_37 , V_4 ) ;
if ( F_9 ( V_167 ) ) {
F_136 ( V_37 ) ;
F_159 ( V_35 , V_281 ) ;
return F_15 ( V_167 ) ;
}
V_232 -> V_276 = V_276 ;
memcpy ( V_232 -> V_223 , V_223 , sizeof( struct V_54 * ) * V_276 ) ;
V_232 -> V_282 = F_160 ( & V_223 [ 0 ] -> V_92 ) ;
return V_232 ;
}
static struct V_79 *
F_161 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 ,
struct V_79 * V_283 , void * V_165 )
{
struct V_34 * V_278 = (struct V_34 * ) V_165 ;
struct V_54 * V_223 [ V_179 ] ;
struct V_231 * V_232 , * V_284 ;
int V_276 = 0 , V_234 = 0 , V_117 , V_167 , V_285 ;
V_232 = NULL ;
if ( V_283 ) {
V_232 = F_31 ( V_283 , struct V_231 , V_80 ) ;
V_276 = V_232 -> V_276 ;
V_234 = V_232 -> V_234 ;
V_285 = 0 ;
for ( V_117 = 0 ; V_117 < V_276 ; V_117 ++ ) {
V_223 [ V_117 ] = V_232 -> V_223 [ V_117 ] ;
V_285 |= V_223 [ V_117 ] -> V_62 . V_63 ;
}
if ( V_285 ) {
F_136 ( & V_232 -> V_7 . V_37 ) ;
V_232 = NULL ;
V_276 = 0 ;
V_234 = 0 ;
V_283 = NULL ;
}
}
if ( V_232 == NULL ) {
V_276 = 1 ;
V_223 [ 0 ] = F_110 ( V_35 , V_4 , V_28 , V_60 ) ;
V_167 = F_156 ( V_4 , V_28 , V_223 ,
& V_276 , & V_234 ) ;
if ( V_167 < 0 )
goto V_286;
if ( V_276 == 0 )
return NULL ;
if ( V_234 <= 0 )
goto V_287;
}
V_284 = F_158 ( V_223 , V_276 , V_4 , V_28 , V_278 ) ;
if ( F_18 ( V_284 ) ) {
V_167 = F_145 ( V_284 ) ;
if ( V_167 != - V_221 )
goto error;
if ( V_283 == NULL )
goto V_287;
F_133 ( & V_232 -> V_7 . V_37 ) ;
return V_283 ;
} else if ( V_284 == NULL ) {
V_234 = 0 ;
if ( V_283 == NULL )
goto V_287;
V_232 -> V_234 = 0 ;
F_133 ( & V_232 -> V_7 . V_37 ) ;
return V_283 ;
}
if ( V_232 ) {
V_232 -> V_276 = 0 ;
F_136 ( & V_232 -> V_7 . V_37 ) ;
}
F_133 ( & V_284 -> V_7 . V_37 ) ;
return & V_284 -> V_80 ;
V_287:
V_232 = F_137 ( V_35 , V_28 ) ;
if ( F_18 ( V_232 ) ) {
F_157 ( V_223 , V_276 ) ;
return F_114 ( V_232 ) ;
}
V_232 -> V_276 = V_276 ;
V_232 -> V_234 = V_234 ;
memcpy ( V_232 -> V_223 , V_223 , sizeof( struct V_54 * ) * V_276 ) ;
F_133 ( & V_232 -> V_7 . V_37 ) ;
return & V_232 -> V_80 ;
V_286:
F_159 ( V_35 , V_279 ) ;
error:
if ( V_232 != NULL )
F_136 ( & V_232 -> V_7 . V_37 ) ;
else
F_157 ( V_223 , V_276 ) ;
return F_15 ( V_167 ) ;
}
static struct V_34 * F_162 ( struct V_35 * V_35 , T_5 V_28 ,
struct V_34 * V_278 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_34 * V_168 ;
if ( ! V_32 ) {
F_146 ( V_278 ) ;
return F_15 ( - V_181 ) ;
} else {
V_168 = V_32 -> V_288 ( V_35 , V_278 ) ;
}
F_13 ( V_32 ) ;
return V_168 ;
}
struct V_34 * F_163 ( struct V_35 * V_35 , struct V_34 * V_278 ,
const struct V_3 * V_4 ,
struct V_193 * V_194 , int V_46 )
{
struct V_54 * V_223 [ V_179 ] ;
struct V_79 * V_80 ;
struct V_231 * V_232 ;
struct V_34 * V_37 , * V_233 ;
T_5 V_28 = V_278 -> V_89 -> V_28 ;
T_4 V_60 = F_115 ( V_131 ) ;
int V_117 , V_167 , V_276 , V_234 = 0 , V_289 = 0 ;
V_290:
V_37 = NULL ;
V_232 = NULL ;
V_233 = NULL ;
if ( V_194 && V_194 -> V_195 [ V_131 ] ) {
V_276 = 1 ;
V_223 [ 0 ] = F_116 ( V_194 , V_131 , V_4 ) ;
V_167 = F_156 ( V_4 , V_28 , V_223 ,
& V_276 , & V_234 ) ;
if ( V_167 < 0 )
goto V_291;
if ( V_276 ) {
if ( V_234 <= 0 ) {
V_289 = V_276 ;
goto V_292;
}
V_232 = F_158 (
V_223 , V_276 , V_4 ,
V_28 , V_278 ) ;
if ( F_18 ( V_232 ) ) {
F_157 ( V_223 , V_276 ) ;
V_167 = F_145 ( V_232 ) ;
goto V_291;
} else if ( V_232 == NULL ) {
V_234 = 0 ;
V_289 = V_276 ;
goto V_292;
}
F_133 ( & V_232 -> V_7 . V_37 ) ;
F_164 ( & V_293 ) ;
V_232 -> V_7 . V_37 . V_57 = V_294 ;
V_294 = & V_232 -> V_7 . V_37 ;
F_165 ( & V_293 ) ;
V_233 = V_232 -> V_233 ;
}
}
if ( V_232 == NULL ) {
if ( ( V_278 -> V_46 & V_295 ) ||
! V_35 -> V_93 . V_124 [ V_131 ] )
goto V_296;
V_80 = F_166 ( V_35 , V_4 , V_28 , V_60 ,
F_161 , V_278 ) ;
if ( V_80 == NULL )
goto V_296;
if ( F_18 ( V_80 ) ) {
V_167 = F_145 ( V_80 ) ;
goto V_291;
}
V_232 = F_31 ( V_80 , struct V_231 , V_80 ) ;
V_276 = V_232 -> V_276 ;
V_234 = V_232 -> V_234 ;
memcpy ( V_223 , V_232 -> V_223 , sizeof( struct V_54 * ) * V_276 ) ;
V_233 = V_232 -> V_233 ;
}
V_37 = & V_232 -> V_7 . V_37 ;
if ( V_233 == NULL && V_234 > 0 ) {
if ( V_35 -> V_93 . V_297 ) {
F_146 ( V_37 ) ;
F_157 ( V_223 , V_289 ) ;
F_159 ( V_35 , V_298 ) ;
return F_162 ( V_35 , V_28 , V_278 ) ;
}
if ( V_4 -> V_299 & V_300 ) {
F_167 ( V_301 , V_302 ) ;
F_168 ( & V_35 -> V_93 . V_303 , & V_301 ) ;
F_169 ( V_304 ) ;
F_170 () ;
F_169 ( V_305 ) ;
F_171 ( & V_35 -> V_93 . V_303 , & V_301 ) ;
if ( ! F_172 ( V_302 ) ) {
F_146 ( V_37 ) ;
goto V_290;
}
V_167 = - V_306 ;
} else
V_167 = - V_221 ;
F_159 ( V_35 , V_298 ) ;
goto error;
}
V_292:
if ( V_276 == 0 )
goto V_296;
if ( ( V_46 & V_307 ) &&
! ( V_223 [ 0 ] -> V_46 & V_308 ) ) {
V_167 = - V_169 ;
goto error;
}
for ( V_117 = 0 ; V_117 < V_276 ; V_117 ++ )
V_223 [ V_117 ] -> V_69 . V_73 = F_21 () ;
if ( V_234 < 0 ) {
F_159 ( V_35 , V_309 ) ;
V_167 = - V_310 ;
goto error;
} else if ( V_234 > 0 ) {
F_146 ( V_278 ) ;
} else {
F_146 ( V_37 ) ;
V_37 = V_278 ;
}
V_311:
F_157 ( V_223 , V_289 ) ;
if ( V_37 && V_37 -> V_93 &&
V_37 -> V_93 -> V_44 . V_213 == V_214 )
V_37 -> V_46 |= V_312 ;
return V_37 ;
V_296:
if ( ! ( V_46 & V_307 ) ) {
V_37 = V_278 ;
goto V_311;
}
V_167 = - V_169 ;
error:
F_146 ( V_37 ) ;
V_291:
F_146 ( V_278 ) ;
F_157 ( V_223 , V_289 ) ;
return F_15 ( V_167 ) ;
}
static inline int
F_173 ( int V_146 , struct V_313 * V_314 , const struct V_3 * V_4 )
{
struct V_40 * V_41 ;
if ( ! V_314 -> V_315 || V_146 < 0 || V_146 >= V_314 -> V_315 -> V_152 )
return 0 ;
V_41 = V_314 -> V_315 -> V_316 [ V_146 ] ;
if ( ! V_41 -> type -> V_317 )
return 0 ;
return V_41 -> type -> V_317 ( V_41 , V_314 , V_4 ) ;
}
static inline int
F_174 ( const struct V_205 * V_212 , const struct V_40 * V_41 ,
unsigned short V_28 )
{
if ( F_175 ( V_41 ) )
return V_212 -> V_222 && ! F_176 ( V_212 , V_41 , V_212 -> V_216 ) ;
return V_41 -> V_45 . V_20 == V_212 -> V_45 . V_20 &&
( V_41 -> V_45 . V_318 == V_212 -> V_45 . V_318 || ! V_212 -> V_45 . V_318 ) &&
( V_41 -> V_44 . V_319 == V_212 -> V_319 || ! V_212 -> V_319 ) &&
V_41 -> V_44 . V_213 == V_212 -> V_213 &&
( V_212 -> V_320 || ( V_212 -> V_321 & ( 1 << V_41 -> V_44 . V_322 ) ) ||
! ( F_177 ( V_212 -> V_45 . V_20 , V_323 ) ) ) &&
! ( V_41 -> V_44 . V_213 != V_259 &&
F_176 ( V_212 , V_41 , V_28 ) ) ;
}
static inline int
F_178 ( const struct V_205 * V_212 , const struct V_324 * V_315 , int V_325 ,
unsigned short V_28 )
{
int V_146 = V_325 ;
if ( V_212 -> V_222 ) {
if ( V_212 -> V_213 == V_259 )
return V_325 ;
} else
V_325 = - 1 ;
for (; V_146 < V_315 -> V_152 ; V_146 ++ ) {
if ( F_174 ( V_212 , V_315 -> V_316 [ V_146 ] , V_28 ) )
return ++ V_146 ;
if ( V_315 -> V_316 [ V_146 ] -> V_44 . V_213 != V_259 ) {
if ( V_325 == - 1 )
V_325 = - 2 - V_146 ;
break;
}
}
return V_325 ;
}
int F_179 ( struct V_313 * V_314 , struct V_3 * V_4 ,
unsigned int V_28 , int V_326 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_167 ;
if ( F_9 ( V_32 == NULL ) )
return - V_38 ;
V_32 -> V_327 ( V_314 , V_4 , V_326 ) ;
V_167 = F_180 ( V_314 , & V_4 -> V_185 ) ;
F_13 ( V_32 ) ;
return V_167 ;
}
static inline int F_181 ( const struct V_324 * V_315 , int V_328 , int * V_329 )
{
for (; V_328 < V_315 -> V_152 ; V_328 ++ ) {
if ( V_315 -> V_316 [ V_328 ] -> V_44 . V_213 != V_259 ) {
* V_329 = V_328 ;
return 1 ;
}
}
return 0 ;
}
int F_182 ( struct V_193 * V_194 , int V_60 , struct V_313 * V_314 ,
unsigned short V_28 )
{
struct V_35 * V_35 = F_183 ( V_314 -> V_246 ) ;
struct V_54 * V_81 ;
struct V_54 * V_223 [ V_179 ] ;
int V_224 = 0 ;
int V_203 ;
int V_330 ;
int V_326 ;
struct V_3 V_4 ;
T_4 V_331 ;
int V_332 = - 1 ;
V_326 = V_60 & ~ V_333 ;
V_60 &= V_333 ;
V_331 = F_115 ( V_60 ) ;
if ( F_179 ( V_314 , & V_4 , V_28 , V_326 ) < 0 ) {
F_159 ( V_35 , V_334 ) ;
return 0 ;
}
F_184 ( V_314 , & V_4 , V_28 ) ;
if ( V_314 -> V_315 ) {
int V_117 ;
for ( V_117 = V_314 -> V_315 -> V_152 - 1 ; V_117 >= 0 ; V_117 -- ) {
struct V_40 * V_41 = V_314 -> V_315 -> V_316 [ V_117 ] ;
if ( ! F_7 ( & V_41 -> V_2 , & V_4 , V_28 ) ) {
F_159 ( V_35 , V_335 ) ;
return 0 ;
}
}
}
V_81 = NULL ;
if ( V_194 && V_194 -> V_195 [ V_60 ] ) {
V_81 = F_116 ( V_194 , V_60 , & V_4 ) ;
if ( F_18 ( V_81 ) ) {
F_159 ( V_35 , V_336 ) ;
return 0 ;
}
}
if ( ! V_81 ) {
struct V_79 * V_80 ;
V_80 = F_166 ( V_35 , & V_4 , V_28 , V_331 ,
F_112 , NULL ) ;
if ( F_113 ( V_80 ) )
V_81 = F_114 ( V_80 ) ;
else
V_81 = F_31 ( V_80 , struct V_54 , V_80 ) ;
}
if ( F_18 ( V_81 ) ) {
F_159 ( V_35 , V_336 ) ;
return 0 ;
}
if ( ! V_81 ) {
if ( V_314 -> V_315 && F_181 ( V_314 -> V_315 , 0 , & V_332 ) ) {
F_173 ( V_332 , V_314 , & V_4 ) ;
F_159 ( V_35 , V_337 ) ;
return 0 ;
}
return 1 ;
}
V_81 -> V_69 . V_73 = F_21 () ;
V_223 [ 0 ] = V_81 ;
V_224 ++ ;
#ifdef F_111
if ( V_223 [ 0 ] -> type != V_188 ) {
V_223 [ 1 ] = F_107 ( V_35 , V_188 ,
& V_4 , V_28 ,
V_129 ) ;
if ( V_223 [ 1 ] ) {
if ( F_18 ( V_223 [ 1 ] ) ) {
F_159 ( V_35 , V_336 ) ;
return 0 ;
}
V_223 [ 1 ] -> V_69 . V_73 = F_21 () ;
V_224 ++ ;
}
}
#endif
if ( V_81 -> V_202 == V_277 ) {
struct V_324 * V_315 ;
static struct V_324 V_338 ;
struct V_205 * V_225 [ V_226 ] ;
struct V_205 * V_339 [ V_226 ] ;
struct V_205 * * V_227 = V_225 ;
int V_340 = 0 ;
int V_117 , V_328 ;
if ( ( V_315 = V_314 -> V_315 ) == NULL )
V_315 = & V_338 ;
for ( V_330 = 0 ; V_330 < V_224 ; V_330 ++ ) {
if ( V_223 [ V_330 ] != V_81 &&
V_223 [ V_330 ] -> V_202 != V_277 ) {
F_159 ( V_35 , V_341 ) ;
goto V_317;
}
if ( V_340 + V_223 [ V_330 ] -> V_203 >= V_226 ) {
F_159 ( V_35 , V_342 ) ;
goto V_343;
}
for ( V_117 = 0 ; V_117 < V_223 [ V_330 ] -> V_203 ; V_117 ++ )
V_227 [ V_340 ++ ] = & V_223 [ V_330 ] -> V_204 [ V_117 ] ;
}
V_203 = V_340 ;
if ( V_224 > 1 ) {
F_185 ( V_339 , V_227 , V_203 , V_28 ) ;
V_227 = V_339 ;
}
for ( V_117 = V_203 - 1 , V_328 = 0 ; V_117 >= 0 ; V_117 -- ) {
V_328 = F_178 ( V_227 [ V_117 ] , V_315 , V_328 , V_28 ) ;
if ( V_328 < 0 ) {
if ( V_328 < - 1 )
V_332 = - ( 2 + V_328 ) ;
F_159 ( V_35 , V_344 ) ;
goto V_317;
}
}
if ( F_181 ( V_315 , V_328 , & V_332 ) ) {
F_159 ( V_35 , V_344 ) ;
goto V_317;
}
F_157 ( V_223 , V_224 ) ;
return 1 ;
}
F_159 ( V_35 , V_341 ) ;
V_317:
F_173 ( V_332 , V_314 , & V_4 ) ;
V_343:
F_157 ( V_223 , V_224 ) ;
return 0 ;
}
int F_186 ( struct V_313 * V_314 , unsigned short V_28 )
{
struct V_35 * V_35 = F_183 ( V_314 -> V_246 ) ;
struct V_3 V_4 ;
struct V_34 * V_37 ;
int V_345 = 1 ;
if ( F_187 ( V_314 , & V_4 , V_28 ) < 0 ) {
F_159 ( V_35 , V_346 ) ;
return 0 ;
}
F_188 ( V_314 ) ;
V_37 = F_163 ( V_35 , F_189 ( V_314 ) , & V_4 , NULL , 0 ) ;
if ( F_18 ( V_37 ) ) {
V_345 = 0 ;
V_37 = NULL ;
}
F_190 ( V_314 , V_37 ) ;
return V_345 ;
}
static struct V_34 * F_191 ( struct V_34 * V_37 , T_3 V_347 )
{
if ( V_37 -> V_261 < 0 && ! F_132 ( V_37 ) )
return V_37 ;
return NULL ;
}
static int F_132 ( struct V_34 * V_37 )
{
return ! F_192 ( (struct V_231 * ) V_37 ) ;
}
void F_193 ( struct V_34 * V_37 , struct V_245 * V_246 )
{
while ( ( V_37 = V_37 -> V_257 ) && V_37 -> V_93 && V_37 -> V_246 == V_246 ) {
V_37 -> V_246 = F_183 ( V_246 ) -> V_348 ;
F_194 ( V_37 -> V_246 ) ;
F_195 ( V_246 ) ;
}
}
static void F_196 ( struct V_313 * V_314 )
{
}
static struct V_34 * F_197 ( struct V_34 * V_37 )
{
if ( V_37 ) {
if ( V_37 -> V_261 ) {
F_146 ( V_37 ) ;
V_37 = NULL ;
}
}
return V_37 ;
}
static void F_198 ( struct V_35 * V_35 )
{
struct V_34 * V_349 , * V_57 ;
F_164 ( & V_293 ) ;
V_349 = V_294 ;
V_294 = NULL ;
F_165 ( & V_293 ) ;
while ( V_349 ) {
V_57 = V_349 -> V_57 ;
F_136 ( V_349 ) ;
V_349 = V_57 ;
}
}
static void F_199 ( struct V_35 * V_35 )
{
F_200 () ;
F_198 ( V_35 ) ;
}
static void F_201 ( struct V_35 * V_35 )
{
F_202 () ;
F_198 ( V_35 ) ;
}
static void F_151 ( struct V_34 * V_37 )
{
do {
struct V_231 * V_232 = (struct V_231 * ) V_37 ;
T_3 V_350 , V_351 ;
V_350 = F_203 ( V_37 -> V_257 ) ;
V_232 -> V_352 = V_350 ;
V_350 = F_204 ( V_37 -> V_93 , V_350 ) ;
V_351 = F_203 ( V_232 -> V_233 ) ;
V_232 -> V_351 = V_351 ;
if ( V_350 > V_351 )
V_350 = V_351 ;
F_205 ( V_37 , V_353 , V_350 ) ;
} while ( ( V_37 = V_37 -> V_57 ) );
}
static int F_192 ( struct V_231 * V_354 )
{
struct V_34 * V_37 = & V_354 -> V_7 . V_37 ;
struct V_231 * V_355 ;
T_3 V_356 ;
if ( ! F_206 ( V_37 -> V_242 , ( (struct V_231 * ) V_37 ) -> V_357 ) ||
( V_37 -> V_246 && ! F_207 ( V_37 -> V_246 ) ) )
return 0 ;
V_355 = NULL ;
do {
struct V_231 * V_232 = (struct V_231 * ) V_37 ;
if ( V_37 -> V_93 -> V_217 . V_218 != V_219 )
return 0 ;
if ( V_232 -> V_260 != V_37 -> V_93 -> V_92 )
return 0 ;
if ( V_232 -> V_276 > 0 &&
V_232 -> V_282 != F_160 ( & V_232 -> V_223 [ 0 ] -> V_92 ) )
return 0 ;
V_356 = F_203 ( V_37 -> V_257 ) ;
if ( V_232 -> V_352 != V_356 ) {
V_355 = V_232 ;
V_232 -> V_352 = V_356 ;
}
if ( ! F_206 ( V_232 -> V_233 , V_232 -> V_358 ) )
return 0 ;
V_356 = F_203 ( V_232 -> V_233 ) ;
if ( V_232 -> V_351 != V_356 ) {
V_355 = V_232 ;
V_232 -> V_351 = V_356 ;
}
V_37 = V_37 -> V_257 ;
} while ( V_37 -> V_93 );
if ( F_140 ( ! V_355 ) )
return 1 ;
V_356 = V_355 -> V_352 ;
for (; ; ) {
V_37 = & V_355 -> V_7 . V_37 ;
V_356 = F_204 ( V_37 -> V_93 , V_356 ) ;
if ( V_356 > V_355 -> V_351 )
V_356 = V_355 -> V_351 ;
F_205 ( V_37 , V_353 , V_356 ) ;
if ( V_355 == V_354 )
break;
V_355 = (struct V_231 * ) V_355 -> V_7 . V_37 . V_57 ;
V_355 -> V_352 = V_356 ;
}
return 1 ;
}
static unsigned int F_208 ( const struct V_34 * V_37 )
{
return F_209 ( V_37 -> V_242 ) ;
}
static unsigned int F_210 ( const struct V_34 * V_37 )
{
unsigned int V_356 = F_211 ( V_37 , V_353 ) ;
return V_356 ? : F_203 ( V_37 -> V_242 ) ;
}
static struct V_359 * F_212 ( const struct V_34 * V_37 ,
struct V_313 * V_314 ,
const void * V_9 )
{
return V_37 -> V_242 -> V_89 -> V_360 ( V_37 , V_314 , V_9 ) ;
}
int F_213 ( struct V_31 * V_32 )
{
struct V_35 * V_35 ;
int V_167 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_181 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_214 ( & V_361 ) ;
if ( F_9 ( V_31 [ V_32 -> V_28 ] != NULL ) )
V_167 = - V_229 ;
else {
struct V_235 * V_235 = V_32 -> V_235 ;
if ( F_140 ( V_235 -> V_362 == NULL ) )
V_235 -> V_362 = V_363 ;
if ( F_140 ( V_235 -> V_364 == NULL ) )
V_235 -> V_364 = F_191 ;
if ( F_140 ( V_235 -> V_365 == NULL ) )
V_235 -> V_365 = F_208 ;
if ( F_140 ( V_235 -> V_356 == NULL ) )
V_235 -> V_356 = F_210 ;
if ( F_140 ( V_235 -> V_366 == NULL ) )
V_235 -> V_366 = F_197 ;
if ( F_140 ( V_235 -> V_367 == NULL ) )
V_235 -> V_367 = F_196 ;
if ( F_140 ( V_235 -> V_360 == NULL ) )
V_235 -> V_360 = F_212 ;
if ( F_140 ( V_32 -> V_368 == NULL ) )
V_32 -> V_368 = F_201 ;
F_215 ( V_31 [ V_32 -> V_28 ] , V_32 ) ;
}
F_216 ( & V_361 ) ;
F_217 () ;
F_218 (net) {
struct V_235 * V_369 ;
switch ( V_32 -> V_28 ) {
case V_29 :
V_369 = & V_35 -> V_93 . V_236 ;
break;
#if F_138 ( V_237 )
case V_30 :
V_369 = & V_35 -> V_93 . V_238 ;
break;
#endif
default:
F_45 () ;
}
* V_369 = * V_32 -> V_235 ;
}
F_219 () ;
return V_167 ;
}
int F_220 ( struct V_31 * V_32 )
{
int V_167 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_181 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_214 ( & V_361 ) ;
if ( F_140 ( V_31 [ V_32 -> V_28 ] != NULL ) ) {
if ( F_9 ( V_31 [ V_32 -> V_28 ] != V_32 ) )
V_167 = - V_181 ;
else
F_221 ( V_31 [ V_32 -> V_28 ] ,
NULL ) ;
}
F_216 ( & V_361 ) ;
if ( ! V_167 ) {
struct V_235 * V_235 = V_32 -> V_235 ;
F_222 () ;
V_235 -> V_362 = NULL ;
V_235 -> V_364 = NULL ;
V_235 -> V_366 = NULL ;
V_235 -> V_367 = NULL ;
V_32 -> V_368 = NULL ;
}
return V_167 ;
}
static void T_6 F_223 ( struct V_35 * V_35 )
{
struct V_31 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_31 [ V_29 ] ) ;
if ( V_32 )
V_35 -> V_93 . V_236 = * V_32 -> V_235 ;
#if F_138 ( V_237 )
V_32 = F_11 ( V_31 [ V_30 ] ) ;
if ( V_32 )
V_35 -> V_93 . V_238 = * V_32 -> V_235 ;
#endif
F_12 () ;
}
static int F_224 ( struct V_370 * V_371 , unsigned long V_372 , void * V_373 )
{
struct V_245 * V_246 = V_373 ;
switch ( V_372 ) {
case V_374 :
F_199 ( F_183 ( V_246 ) ) ;
}
return V_375 ;
}
static int T_6 F_225 ( struct V_35 * V_35 )
{
int V_376 ;
if ( F_226 ( ( void V_377 * * ) V_35 -> V_378 . V_379 ,
sizeof( struct V_380 ) ,
F_227 ( struct V_380 ) ) < 0 )
return - V_207 ;
V_376 = F_228 ( V_35 ) ;
if ( V_376 < 0 )
F_229 ( ( void V_377 * * ) V_35 -> V_378 . V_379 ) ;
return V_376 ;
}
static void F_230 ( struct V_35 * V_35 )
{
F_231 ( V_35 ) ;
F_229 ( ( void V_377 * * ) V_35 -> V_378 . V_379 ) ;
}
static int T_6 F_225 ( struct V_35 * V_35 )
{
return 0 ;
}
static void F_230 ( struct V_35 * V_35 )
{
}
static int T_6 F_232 ( struct V_35 * V_35 )
{
unsigned int V_96 , V_381 ;
int V_60 ;
if ( F_233 ( V_35 , & V_382 ) )
V_363 = F_234 ( L_1 ,
sizeof( struct V_231 ) ,
0 , V_383 | V_384 ,
NULL ) ;
V_96 = 8 - 1 ;
V_381 = ( V_96 + 1 ) * sizeof( struct V_95 ) ;
V_35 -> V_93 . V_121 = F_65 ( V_381 ) ;
if ( ! V_35 -> V_93 . V_121 )
goto V_385;
V_35 -> V_93 . V_94 = V_96 ;
for ( V_60 = 0 ; V_60 < V_135 * 2 ; V_60 ++ ) {
struct V_386 * V_387 ;
V_35 -> V_93 . V_124 [ V_60 ] = 0 ;
F_235 ( & V_35 -> V_93 . V_99 [ V_60 ] ) ;
V_387 = & V_35 -> V_93 . V_97 [ V_60 ] ;
V_387 -> V_100 = F_65 ( V_381 ) ;
if ( ! V_387 -> V_100 )
goto V_388;
V_387 -> V_96 = V_96 ;
}
F_37 ( & V_35 -> V_93 . V_163 ) ;
F_236 ( & V_35 -> V_93 . V_142 , F_75 ) ;
if ( F_233 ( V_35 , & V_382 ) )
F_237 ( & V_389 ) ;
return 0 ;
V_388:
for ( V_60 -- ; V_60 >= 0 ; V_60 -- ) {
struct V_386 * V_387 ;
V_387 = & V_35 -> V_93 . V_97 [ V_60 ] ;
F_68 ( V_387 -> V_100 , V_381 ) ;
}
F_68 ( V_35 -> V_93 . V_121 , V_381 ) ;
V_385:
return - V_207 ;
}
static void F_238 ( struct V_35 * V_35 )
{
struct V_170 V_171 ;
unsigned int V_381 ;
int V_60 ;
F_239 ( & V_35 -> V_93 . V_142 ) ;
#ifdef F_111
V_171 . V_172 = V_390 ;
V_171 . V_173 = - 1 ;
V_171 . V_174 = 0 ;
F_93 ( V_35 , V_187 , & V_171 ) ;
#endif
V_171 . V_172 = V_390 ;
V_171 . V_173 = - 1 ;
V_171 . V_174 = 0 ;
F_93 ( V_35 , V_188 , & V_171 ) ;
F_83 ( ! F_96 ( & V_35 -> V_93 . V_163 ) ) ;
for ( V_60 = 0 ; V_60 < V_135 * 2 ; V_60 ++ ) {
struct V_386 * V_387 ;
F_83 ( ! F_61 ( & V_35 -> V_93 . V_99 [ V_60 ] ) ) ;
V_387 = & V_35 -> V_93 . V_97 [ V_60 ] ;
V_381 = ( V_387 -> V_96 + 1 ) ;
F_83 ( ! F_61 ( V_387 -> V_100 ) ) ;
F_68 ( V_387 -> V_100 , V_381 ) ;
}
V_381 = ( V_35 -> V_93 . V_94 + 1 ) * sizeof( struct V_95 ) ;
F_83 ( ! F_61 ( V_35 -> V_93 . V_121 ) ) ;
F_68 ( V_35 -> V_93 . V_121 , V_381 ) ;
}
static int T_6 F_240 ( struct V_35 * V_35 )
{
int V_376 ;
V_376 = F_225 ( V_35 ) ;
if ( V_376 < 0 )
goto V_391;
V_376 = F_241 ( V_35 ) ;
if ( V_376 < 0 )
goto V_392;
V_376 = F_232 ( V_35 ) ;
if ( V_376 < 0 )
goto V_393;
F_223 ( V_35 ) ;
V_376 = F_242 ( V_35 ) ;
if ( V_376 < 0 )
goto V_394;
return 0 ;
V_394:
F_238 ( V_35 ) ;
V_393:
F_243 ( V_35 ) ;
V_392:
F_230 ( V_35 ) ;
V_391:
return V_376 ;
}
static void T_7 F_244 ( struct V_35 * V_35 )
{
F_245 ( V_35 ) ;
F_238 ( V_35 ) ;
F_243 ( V_35 ) ;
F_230 ( V_35 ) ;
}
void T_8 F_246 ( void )
{
F_247 ( & V_395 ) ;
F_248 () ;
}
static void F_249 ( struct V_54 * V_55 ,
struct V_396 * V_397 )
{
struct V_164 * V_165 = V_55 -> V_91 ;
struct V_1 * V_2 = & V_55 -> V_111 ;
if ( V_165 )
F_250 ( V_397 , L_2 ,
V_165 -> V_398 , V_165 -> V_399 , V_165 -> V_400 ) ;
switch( V_2 -> V_28 ) {
case V_29 :
F_250 ( V_397 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_250 ( V_397 , L_4 ,
V_2 -> V_13 ) ;
F_250 ( V_397 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_250 ( V_397 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_250 ( V_397 , L_7 , V_2 -> V_12 . V_401 ) ;
if ( V_2 -> V_13 != 128 )
F_250 ( V_397 , L_4 ,
V_2 -> V_13 ) ;
F_250 ( V_397 , L_8 , V_2 -> V_9 . V_401 ) ;
if ( V_2 -> V_11 != 128 )
F_250 ( V_397 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_251 ( struct V_54 * V_55 , int V_402 ,
T_9 V_403 , T_3 V_173 , T_3 V_174 )
{
struct V_396 * V_397 ;
V_397 = F_252 ( L_9 ) ;
if ( V_397 == NULL )
return;
F_253 ( V_403 , V_173 , V_174 , V_397 ) ;
F_250 ( V_397 , L_10 , V_402 ) ;
F_249 ( V_55 , V_397 ) ;
F_254 ( V_397 ) ;
}
void F_92 ( struct V_54 * V_55 , int V_402 ,
T_9 V_403 , T_3 V_173 , T_3 V_174 )
{
struct V_396 * V_397 ;
V_397 = F_252 ( L_11 ) ;
if ( V_397 == NULL )
return;
F_253 ( V_403 , V_173 , V_174 , V_397 ) ;
F_250 ( V_397 , L_10 , V_402 ) ;
F_249 ( V_55 , V_397 ) ;
F_254 ( V_397 ) ;
}
static bool F_255 ( const struct V_1 * V_404 ,
const struct V_1 * V_405 )
{
if ( V_404 -> V_20 == V_406 ) {
if ( V_405 -> V_28 == V_404 -> V_28 &&
F_256 ( & V_405 -> V_9 , & V_404 -> V_9 ,
V_404 -> V_28 ) == 0 &&
F_256 ( & V_405 -> V_12 , & V_404 -> V_12 ,
V_404 -> V_28 ) == 0 &&
V_405 -> V_11 == V_404 -> V_11 &&
V_405 -> V_13 == V_404 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_405 , V_404 , sizeof( * V_405 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_54 * F_257 ( const struct V_1 * V_2 ,
T_4 V_60 , T_4 type )
{
struct V_54 * V_81 , * V_168 = NULL ;
struct V_104 * V_105 ;
struct V_95 * V_155 ;
T_3 V_161 = ~ 0U ;
F_73 ( & V_118 ) ;
V_155 = F_54 ( & V_382 , & V_2 -> V_9 , & V_2 -> V_12 , V_2 -> V_28 , V_60 ) ;
F_79 (pol, entry, chain, bydst) {
if ( F_255 ( V_2 , & V_81 -> V_111 ) &&
V_81 -> type == type ) {
V_168 = V_81 ;
V_161 = V_168 -> V_161 ;
break;
}
}
V_155 = & V_382 . V_93 . V_99 [ V_60 ] ;
F_79 (pol, entry, chain, bydst) {
if ( F_255 ( V_2 , & V_81 -> V_111 ) &&
V_81 -> type == type &&
V_81 -> V_161 < V_161 ) {
V_168 = V_81 ;
break;
}
}
if ( V_168 )
F_26 ( V_168 ) ;
F_74 ( & V_118 ) ;
return V_168 ;
}
static int F_258 ( const struct V_407 * V_159 , const struct V_205 * V_408 )
{
int V_183 = 0 ;
if ( V_408 -> V_213 == V_159 -> V_213 && V_408 -> V_45 . V_20 == V_159 -> V_20 &&
( V_159 -> V_319 == 0 || V_408 -> V_319 == V_159 -> V_319 ) ) {
switch ( V_408 -> V_213 ) {
case V_214 :
case V_215 :
if ( F_256 ( & V_408 -> V_45 . V_9 , & V_159 -> V_409 ,
V_159 -> V_410 ) == 0 &&
F_256 ( & V_408 -> V_12 , & V_159 -> V_411 ,
V_159 -> V_410 ) == 0 ) {
V_183 = 1 ;
}
break;
case V_259 :
V_183 = 1 ;
break;
default:
break;
}
}
return V_183 ;
}
static int F_259 ( struct V_54 * V_81 ,
struct V_407 * V_159 , int V_412 )
{
struct V_407 * V_413 ;
int V_117 , V_414 , V_415 = 0 ;
F_66 ( & V_81 -> V_61 ) ;
if ( F_9 ( V_81 -> V_62 . V_63 ) ) {
F_67 ( & V_81 -> V_61 ) ;
return - V_169 ;
}
for ( V_117 = 0 ; V_117 < V_81 -> V_203 ; V_117 ++ ) {
for ( V_414 = 0 , V_413 = V_159 ; V_414 < V_412 ; V_414 ++ , V_413 ++ ) {
if ( ! F_258 ( V_413 , & V_81 -> V_204 [ V_117 ] ) )
continue;
V_415 ++ ;
if ( V_81 -> V_204 [ V_117 ] . V_213 != V_214 &&
V_81 -> V_204 [ V_117 ] . V_213 != V_215 )
continue;
memcpy ( & V_81 -> V_204 [ V_117 ] . V_45 . V_9 , & V_413 -> V_416 ,
sizeof( V_81 -> V_204 [ V_117 ] . V_45 . V_9 ) ) ;
memcpy ( & V_81 -> V_204 [ V_117 ] . V_12 , & V_413 -> V_417 ,
sizeof( V_81 -> V_204 [ V_117 ] . V_12 ) ) ;
V_81 -> V_204 [ V_117 ] . V_216 = V_413 -> V_418 ;
F_49 ( & V_81 -> V_92 ) ;
}
}
F_67 ( & V_81 -> V_61 ) ;
if ( ! V_415 )
return - V_419 ;
return 0 ;
}
static int F_260 ( const struct V_407 * V_159 , int V_412 )
{
int V_117 , V_414 ;
if ( V_412 < 1 || V_412 > V_226 )
return - V_181 ;
for ( V_117 = 0 ; V_117 < V_412 ; V_117 ++ ) {
if ( ( F_256 ( & V_159 [ V_117 ] . V_409 , & V_159 [ V_117 ] . V_416 ,
V_159 [ V_117 ] . V_410 ) == 0 ) &&
( F_256 ( & V_159 [ V_117 ] . V_411 , & V_159 [ V_117 ] . V_417 ,
V_159 [ V_117 ] . V_410 ) == 0 ) )
return - V_181 ;
if ( F_125 ( & V_159 [ V_117 ] . V_416 , V_159 [ V_117 ] . V_418 ) ||
F_125 ( & V_159 [ V_117 ] . V_417 , V_159 [ V_117 ] . V_418 ) )
return - V_181 ;
for ( V_414 = V_117 + 1 ; V_414 < V_412 ; V_414 ++ ) {
if ( ! memcmp ( & V_159 [ V_117 ] . V_409 , & V_159 [ V_414 ] . V_409 ,
sizeof( V_159 [ V_117 ] . V_409 ) ) &&
! memcmp ( & V_159 [ V_117 ] . V_411 , & V_159 [ V_414 ] . V_411 ,
sizeof( V_159 [ V_117 ] . V_411 ) ) &&
V_159 [ V_117 ] . V_20 == V_159 [ V_414 ] . V_20 &&
V_159 [ V_117 ] . V_213 == V_159 [ V_414 ] . V_213 &&
V_159 [ V_117 ] . V_319 == V_159 [ V_414 ] . V_319 &&
V_159 [ V_117 ] . V_410 == V_159 [ V_414 ] . V_410 )
return - V_181 ;
}
}
return 0 ;
}
int V_407 ( const struct V_1 * V_2 , T_4 V_60 , T_4 type ,
struct V_407 * V_159 , int V_412 ,
struct V_420 * V_328 )
{
int V_117 , V_167 , V_421 = 0 , V_422 = 0 ;
struct V_54 * V_81 = NULL ;
struct V_40 * V_41 , * V_423 ;
struct V_40 * V_424 [ V_226 ] ;
struct V_40 * V_425 [ V_226 ] ;
struct V_407 * V_413 ;
if ( ( V_167 = F_260 ( V_159 , V_412 ) ) < 0 )
goto V_64;
if ( ( V_81 = F_257 ( V_2 , V_60 , type ) ) == NULL ) {
V_167 = - V_169 ;
goto V_64;
}
for ( V_117 = 0 , V_413 = V_159 ; V_117 < V_412 ; V_117 ++ , V_413 ++ ) {
if ( ( V_41 = F_261 ( V_413 ) ) ) {
V_424 [ V_421 ] = V_41 ;
V_421 ++ ;
if ( ( V_423 = F_262 ( V_41 , V_413 ) ) ) {
V_425 [ V_422 ] = V_423 ;
V_422 ++ ;
} else {
V_167 = - V_419 ;
goto V_426;
}
}
}
if ( ( V_167 = F_259 ( V_81 , V_159 , V_412 ) ) < 0 )
goto V_426;
if ( V_421 ) {
F_263 ( V_424 , V_421 ) ;
F_264 ( V_424 , V_421 ) ;
}
F_265 ( V_2 , V_60 , type , V_159 , V_412 , V_328 ) ;
F_28 ( V_81 ) ;
return 0 ;
V_64:
return V_167 ;
V_426:
if ( V_81 )
F_28 ( V_81 ) ;
if ( V_421 )
F_263 ( V_424 , V_421 ) ;
if ( V_422 )
F_264 ( V_425 , V_422 ) ;
return V_167 ;
}
