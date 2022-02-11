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
static struct V_103 * F_56 ( struct V_35 * V_35 ,
const struct V_1 * V_2 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_104 = V_35 -> V_101 . V_105 [ V_60 ] . V_104 ;
unsigned int V_106 = F_57 ( V_2 , V_28 , V_104 ) ;
return ( V_106 == V_104 + 1 ?
& V_35 -> V_101 . V_107 [ V_60 ] :
V_35 -> V_101 . V_105 [ V_60 ] . V_108 + V_106 ) ;
}
static struct V_103 * F_58 ( struct V_35 * V_35 ,
const T_1 * V_9 ,
const T_1 * V_12 ,
unsigned short V_28 , int V_60 )
{
unsigned int V_104 = V_35 -> V_101 . V_105 [ V_60 ] . V_104 ;
unsigned int V_106 = F_59 ( V_9 , V_12 , V_28 , V_104 ) ;
return V_35 -> V_101 . V_105 [ V_60 ] . V_108 + V_106 ;
}
static void F_60 ( struct V_103 * V_97 ,
struct V_103 * V_109 ,
unsigned int V_110 )
{
struct V_111 * V_112 , * V_113 = NULL ;
struct V_54 * V_81 ;
unsigned int V_114 = 0 ;
V_115:
F_61 (pol, tmp, list, bydst) {
unsigned int V_116 ;
V_116 = F_59 ( & V_81 -> V_117 . V_9 , & V_81 -> V_117 . V_12 ,
V_81 -> V_28 , V_110 ) ;
if ( ! V_113 ) {
F_62 ( & V_81 -> V_86 ) ;
F_63 ( & V_81 -> V_86 , V_109 + V_116 ) ;
V_114 = V_116 ;
} else {
if ( V_116 != V_114 )
continue;
F_62 ( & V_81 -> V_86 ) ;
F_64 ( V_113 , & V_81 -> V_86 ) ;
}
V_113 = & V_81 -> V_86 ;
}
if ( ! F_65 ( V_97 ) ) {
V_113 = NULL ;
goto V_115;
}
}
static void F_66 ( struct V_103 * V_97 ,
struct V_103 * V_118 ,
unsigned int V_110 )
{
struct V_111 * V_112 ;
struct V_54 * V_81 ;
F_61 (pol, tmp, list, byidx) {
unsigned int V_116 ;
V_116 = F_55 ( V_81 -> V_65 , V_110 ) ;
F_63 ( & V_81 -> V_87 , V_118 + V_116 ) ;
}
}
static unsigned long F_67 ( unsigned int V_119 )
{
return ( ( V_119 + 1 ) << 1 ) - 1 ;
}
static void F_68 ( struct V_35 * V_35 , int V_60 )
{
unsigned int V_104 = V_35 -> V_101 . V_105 [ V_60 ] . V_104 ;
unsigned int V_110 = F_67 ( V_104 ) ;
unsigned int V_120 = ( V_110 + 1 ) * sizeof( struct V_103 ) ;
struct V_103 * V_121 = V_35 -> V_101 . V_105 [ V_60 ] . V_108 ;
struct V_103 * V_122 = F_69 ( V_120 ) ;
int V_123 ;
if ( ! V_122 )
return;
F_70 ( & V_35 -> V_101 . V_124 ) ;
for ( V_123 = V_104 ; V_123 >= 0 ; V_123 -- )
F_60 ( V_121 + V_123 , V_122 , V_110 ) ;
V_35 -> V_101 . V_105 [ V_60 ] . V_108 = V_122 ;
V_35 -> V_101 . V_105 [ V_60 ] . V_104 = V_110 ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
F_72 ( V_121 , ( V_104 + 1 ) * sizeof( struct V_103 ) ) ;
}
static void F_73 ( struct V_35 * V_35 , int V_125 )
{
unsigned int V_104 = V_35 -> V_101 . V_102 ;
unsigned int V_110 = F_67 ( V_104 ) ;
unsigned int V_120 = ( V_110 + 1 ) * sizeof( struct V_103 ) ;
struct V_103 * V_126 = V_35 -> V_101 . V_127 ;
struct V_103 * V_128 = F_69 ( V_120 ) ;
int V_123 ;
if ( ! V_128 )
return;
F_70 ( & V_35 -> V_101 . V_124 ) ;
for ( V_123 = V_104 ; V_123 >= 0 ; V_123 -- )
F_66 ( V_126 + V_123 , V_128 , V_110 ) ;
V_35 -> V_101 . V_127 = V_128 ;
V_35 -> V_101 . V_102 = V_110 ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
F_72 ( V_126 , ( V_104 + 1 ) * sizeof( struct V_103 ) ) ;
}
static inline int F_74 ( struct V_35 * V_35 , int V_60 , int * V_125 )
{
unsigned int V_129 = V_35 -> V_101 . V_130 [ V_60 ] ;
unsigned int V_104 = V_35 -> V_101 . V_105 [ V_60 ] . V_104 ;
if ( V_125 )
* V_125 += V_129 ;
if ( ( V_104 + 1 ) < V_131 &&
V_129 > V_104 )
return 1 ;
return 0 ;
}
static inline int F_75 ( struct V_35 * V_35 , int V_125 )
{
unsigned int V_104 = V_35 -> V_101 . V_102 ;
if ( ( V_104 + 1 ) < V_131 &&
V_125 > V_104 )
return 1 ;
return 0 ;
}
void F_76 ( struct V_35 * V_35 , struct V_132 * V_133 )
{
F_77 ( & V_35 -> V_101 . V_124 ) ;
V_133 -> V_134 = V_35 -> V_101 . V_130 [ V_135 ] ;
V_133 -> V_136 = V_35 -> V_101 . V_130 [ V_137 ] ;
V_133 -> V_138 = V_35 -> V_101 . V_130 [ V_139 ] ;
V_133 -> V_140 = V_35 -> V_101 . V_130 [ V_135 + V_141 ] ;
V_133 -> V_142 = V_35 -> V_101 . V_130 [ V_137 + V_141 ] ;
V_133 -> V_143 = V_35 -> V_101 . V_130 [ V_139 + V_141 ] ;
V_133 -> V_144 = V_35 -> V_101 . V_102 ;
V_133 -> V_145 = V_131 ;
F_78 ( & V_35 -> V_101 . V_124 ) ;
}
static void F_79 ( struct V_146 * V_147 )
{
struct V_35 * V_35 = F_31 ( V_147 , struct V_35 , V_101 . V_148 ) ;
int V_60 , V_125 ;
F_80 ( & V_149 ) ;
V_125 = 0 ;
for ( V_60 = 0 ; V_60 < V_141 * 2 ; V_60 ++ ) {
if ( F_74 ( V_35 , V_60 , & V_125 ) )
F_68 ( V_35 , V_60 ) ;
}
if ( F_75 ( V_35 , V_125 ) )
F_73 ( V_35 , V_125 ) ;
F_81 ( & V_149 ) ;
}
static T_3 F_82 ( struct V_35 * V_35 , int V_60 , T_3 V_65 )
{
static T_3 V_150 ;
for (; ; ) {
struct V_103 * V_97 ;
struct V_54 * V_151 ;
T_3 V_152 ;
int V_153 ;
if ( ! V_65 ) {
V_152 = ( V_150 | V_60 ) ;
V_150 += 8 ;
} else {
V_152 = V_65 ;
V_65 = 0 ;
}
if ( V_152 == 0 )
V_152 = 8 ;
V_97 = V_35 -> V_101 . V_127 + F_54 ( V_35 , V_152 ) ;
V_153 = 0 ;
F_83 (p, list, byidx) {
if ( V_151 -> V_65 == V_152 ) {
V_153 = 1 ;
break;
}
}
if ( ! V_153 )
return V_152 ;
}
}
static inline int F_84 ( struct V_1 * V_154 , struct V_1 * V_155 )
{
T_3 * V_156 = ( T_3 * ) V_154 ;
T_3 * V_157 = ( T_3 * ) V_155 ;
int V_158 = sizeof( struct V_1 ) / sizeof( T_3 ) ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_158 ; V_123 ++ ) {
if ( V_156 [ V_123 ] != V_157 [ V_123 ] )
return 1 ;
}
return 0 ;
}
static void F_85 ( struct V_54 * V_159 ,
struct V_54 * V_160 )
{
struct V_161 * V_162 = & V_159 -> V_89 ;
struct V_96 V_97 ;
F_86 ( & V_97 ) ;
F_87 ( & V_162 -> V_90 . V_61 ) ;
F_88 ( & V_162 -> V_90 , & V_97 ) ;
if ( F_45 ( & V_162 -> V_91 ) )
F_28 ( V_159 ) ;
F_89 ( & V_162 -> V_90 . V_61 ) ;
if ( F_90 ( & V_97 ) )
return;
V_162 = & V_160 -> V_89 ;
F_87 ( & V_162 -> V_90 . V_61 ) ;
F_91 ( & V_97 , & V_162 -> V_90 ) ;
V_162 -> V_163 = V_164 ;
if ( ! F_25 ( & V_162 -> V_91 , V_78 ) )
F_26 ( V_160 ) ;
F_89 ( & V_162 -> V_90 . V_61 ) ;
}
static bool F_92 ( struct V_54 * V_83 ,
struct V_54 * V_81 )
{
T_3 V_165 = V_83 -> V_165 . V_166 & V_83 -> V_165 . V_167 ;
if ( V_83 -> V_165 . V_166 == V_81 -> V_165 . V_166 && V_83 -> V_165 . V_167 == V_81 -> V_165 . V_167 )
return true ;
if ( ( V_165 & V_81 -> V_165 . V_167 ) == V_81 -> V_165 . V_166 &&
V_83 -> V_168 == V_81 -> V_168 )
return true ;
return false ;
}
int F_93 ( int V_60 , struct V_54 * V_83 , int V_169 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
struct V_54 * V_81 ;
struct V_54 * V_170 ;
struct V_103 * V_171 ;
struct V_111 * V_172 ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_171 = F_56 ( V_35 , & V_83 -> V_117 , V_83 -> V_28 , V_60 ) ;
V_170 = NULL ;
V_172 = NULL ;
F_83 (pol, chain, bydst) {
if ( V_81 -> type == V_83 -> type &&
! F_84 ( & V_81 -> V_117 , & V_83 -> V_117 ) &&
F_92 ( V_83 , V_81 ) &&
F_94 ( V_81 -> V_95 , V_83 -> V_95 ) &&
! F_95 ( V_170 ) ) {
if ( V_169 ) {
F_71 ( & V_35 -> V_101 . V_124 ) ;
return - V_173 ;
}
V_170 = V_81 ;
if ( V_83 -> V_168 > V_81 -> V_168 )
continue;
} else if ( V_83 -> V_168 >= V_81 -> V_168 ) {
V_172 = & V_81 -> V_86 ;
continue;
}
if ( V_170 )
break;
}
if ( V_172 )
F_64 ( V_172 , & V_83 -> V_86 ) ;
else
F_63 ( & V_83 -> V_86 , V_171 ) ;
F_26 ( V_83 ) ;
V_35 -> V_101 . V_130 [ V_60 ] ++ ;
F_53 ( & V_174 ) ;
if ( V_83 -> V_28 == V_29 )
F_96 ( V_35 ) ;
else
F_97 ( V_35 ) ;
if ( V_170 ) {
F_85 ( V_170 , V_83 ) ;
F_98 ( V_170 , V_60 ) ;
}
V_83 -> V_65 = V_170 ? V_170 -> V_65 : F_82 ( V_35 , V_60 , V_83 -> V_65 ) ;
F_63 ( & V_83 -> V_87 , V_35 -> V_101 . V_127 + F_54 ( V_35 , V_83 -> V_65 ) ) ;
V_83 -> V_69 . V_70 = F_21 () ;
V_83 -> V_69 . V_73 = 0 ;
if ( ! F_25 ( & V_83 -> V_77 , V_78 + V_52 ) )
F_26 ( V_83 ) ;
F_99 ( & V_83 -> V_62 . V_85 , & V_35 -> V_101 . V_175 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
if ( V_170 )
F_52 ( V_170 ) ;
else if ( F_74 ( V_35 , V_60 , NULL ) )
F_100 ( & V_35 -> V_101 . V_148 ) ;
return 0 ;
}
struct V_54 * F_101 ( struct V_35 * V_35 , T_3 V_165 , T_4 type ,
int V_60 , struct V_1 * V_2 ,
struct V_176 * V_177 , int V_178 ,
int * V_179 )
{
struct V_54 * V_81 , * V_180 ;
struct V_103 * V_171 ;
* V_179 = 0 ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_171 = F_56 ( V_35 , V_2 , V_2 -> V_28 , V_60 ) ;
V_180 = NULL ;
F_83 (pol, chain, bydst) {
if ( V_81 -> type == type &&
( V_165 & V_81 -> V_165 . V_167 ) == V_81 -> V_165 . V_166 &&
! F_84 ( V_2 , & V_81 -> V_117 ) &&
F_94 ( V_177 , V_81 -> V_95 ) ) {
F_26 ( V_81 ) ;
if ( V_178 ) {
* V_179 = F_102 (
V_81 -> V_95 ) ;
if ( * V_179 ) {
F_71 ( & V_35 -> V_101 . V_124 ) ;
return V_81 ;
}
F_98 ( V_81 , V_60 ) ;
}
V_180 = V_81 ;
break;
}
}
F_71 ( & V_35 -> V_101 . V_124 ) ;
if ( V_180 && V_178 )
F_52 ( V_180 ) ;
return V_180 ;
}
struct V_54 * F_103 ( struct V_35 * V_35 , T_3 V_165 , T_4 type ,
int V_60 , T_3 V_45 , int V_178 , int * V_179 )
{
struct V_54 * V_81 , * V_180 ;
struct V_103 * V_171 ;
* V_179 = - V_181 ;
if ( F_23 ( V_45 ) != V_60 )
return NULL ;
* V_179 = 0 ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_171 = V_35 -> V_101 . V_127 + F_54 ( V_35 , V_45 ) ;
V_180 = NULL ;
F_83 (pol, chain, byidx) {
if ( V_81 -> type == type && V_81 -> V_65 == V_45 &&
( V_165 & V_81 -> V_165 . V_167 ) == V_81 -> V_165 . V_166 ) {
F_26 ( V_81 ) ;
if ( V_178 ) {
* V_179 = F_102 (
V_81 -> V_95 ) ;
if ( * V_179 ) {
F_71 ( & V_35 -> V_101 . V_124 ) ;
return V_81 ;
}
F_98 ( V_81 , V_60 ) ;
}
V_180 = V_81 ;
break;
}
}
F_71 ( & V_35 -> V_101 . V_124 ) ;
if ( V_180 && V_178 )
F_52 ( V_180 ) ;
return V_180 ;
}
static inline int
F_104 ( struct V_35 * V_35 , T_4 type , struct V_182 * V_183 )
{
int V_60 , V_179 = 0 ;
for ( V_60 = 0 ; V_60 < V_141 ; V_60 ++ ) {
struct V_54 * V_81 ;
int V_123 ;
F_83 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
V_179 = F_102 ( V_81 -> V_95 ) ;
if ( V_179 ) {
F_105 ( V_81 , 0 ,
V_183 -> V_184 ,
V_183 -> V_185 ,
V_183 -> V_186 ) ;
return V_179 ;
}
}
for ( V_123 = V_35 -> V_101 . V_105 [ V_60 ] . V_104 ; V_123 >= 0 ; V_123 -- ) {
F_83 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
V_179 = F_102 (
V_81 -> V_95 ) ;
if ( V_179 ) {
F_105 ( V_81 , 0 ,
V_183 -> V_184 ,
V_183 -> V_185 ,
V_183 -> V_186 ) ;
return V_179 ;
}
}
}
}
return V_179 ;
}
static inline int
F_104 ( struct V_35 * V_35 , T_4 type , struct V_182 * V_183 )
{
return 0 ;
}
int F_106 ( struct V_35 * V_35 , T_4 type , struct V_182 * V_183 )
{
int V_60 , V_179 = 0 , V_129 = 0 ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_179 = F_104 ( V_35 , type , V_183 ) ;
if ( V_179 )
goto V_64;
for ( V_60 = 0 ; V_60 < V_141 ; V_60 ++ ) {
struct V_54 * V_81 ;
int V_123 ;
V_187:
F_83 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
F_98 ( V_81 , V_60 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
V_129 ++ ;
F_105 ( V_81 , 1 , V_183 -> V_184 ,
V_183 -> V_185 ,
V_183 -> V_186 ) ;
F_52 ( V_81 ) ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
goto V_187;
}
for ( V_123 = V_35 -> V_101 . V_105 [ V_60 ] . V_104 ; V_123 >= 0 ; V_123 -- ) {
V_188:
F_83 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
F_98 ( V_81 , V_60 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
V_129 ++ ;
F_105 ( V_81 , 1 ,
V_183 -> V_184 ,
V_183 -> V_185 ,
V_183 -> V_186 ) ;
F_52 ( V_81 ) ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
goto V_188;
}
}
}
if ( ! V_129 )
V_179 = - V_189 ;
V_64:
F_71 ( & V_35 -> V_101 . V_124 ) ;
return V_179 ;
}
int F_107 ( struct V_35 * V_35 , struct F_107 * V_62 ,
int (* F_108)( struct V_54 * , int , int , void * ) ,
void * V_53 )
{
struct V_54 * V_81 ;
struct V_190 * V_41 ;
int error = 0 ;
if ( V_62 -> type >= V_191 &&
V_62 -> type != V_192 )
return - V_193 ;
if ( F_109 ( & V_62 -> V_62 . V_85 ) && V_62 -> V_194 != 0 )
return 0 ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
if ( F_109 ( & V_62 -> V_62 . V_85 ) )
V_41 = F_110 ( & V_35 -> V_101 . V_175 , struct V_190 , V_85 ) ;
else
V_41 = F_111 ( & V_62 -> V_62 . V_85 , struct V_190 , V_85 ) ;
F_112 (x, &net->xfrm.policy_all, all) {
if ( V_41 -> V_63 )
continue;
V_81 = F_31 ( V_41 , struct V_54 , V_62 ) ;
if ( V_62 -> type != V_192 &&
V_62 -> type != V_81 -> type )
continue;
error = F_108 ( V_81 , F_23 ( V_81 -> V_65 ) ,
V_62 -> V_194 , V_53 ) ;
if ( error ) {
F_113 ( & V_62 -> V_62 . V_85 , & V_41 -> V_85 ) ;
goto V_64;
}
V_62 -> V_194 ++ ;
}
if ( V_62 -> V_194 == 0 ) {
error = - V_181 ;
goto V_64;
}
F_114 ( & V_62 -> V_62 . V_85 ) ;
V_64:
F_71 ( & V_35 -> V_101 . V_124 ) ;
return error ;
}
void F_115 ( struct F_107 * V_62 , T_4 type )
{
F_37 ( & V_62 -> V_62 . V_85 ) ;
V_62 -> V_62 . V_63 = 1 ;
V_62 -> type = type ;
V_62 -> V_194 = 0 ;
}
void F_116 ( struct F_107 * V_62 , struct V_35 * V_35 )
{
if ( F_109 ( & V_62 -> V_62 . V_85 ) )
return;
F_70 ( & V_35 -> V_101 . V_124 ) ;
F_117 ( & V_62 -> V_62 . V_85 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
}
static int F_118 ( const struct V_54 * V_81 ,
const struct V_3 * V_4 ,
T_4 type , T_5 V_28 , int V_60 )
{
const struct V_1 * V_2 = & V_81 -> V_117 ;
int V_180 = - V_189 ;
bool V_195 ;
if ( V_81 -> V_28 != V_28 ||
( V_4 -> V_196 & V_81 -> V_165 . V_167 ) != V_81 -> V_165 . V_166 ||
V_81 -> type != type )
return V_180 ;
V_195 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_195 )
V_180 = F_119 ( V_81 -> V_95 , V_4 -> V_197 ,
V_60 ) ;
return V_180 ;
}
static struct V_54 * F_120 ( struct V_35 * V_35 , T_4 type ,
const struct V_3 * V_4 ,
T_5 V_28 , T_4 V_60 )
{
int V_179 ;
struct V_54 * V_81 , * V_180 ;
const T_1 * V_9 , * V_12 ;
struct V_103 * V_171 ;
T_3 V_168 = ~ 0U ;
V_9 = F_121 ( V_4 , V_28 ) ;
V_12 = F_122 ( V_4 , V_28 ) ;
if ( F_9 ( ! V_9 || ! V_12 ) )
return NULL ;
F_77 ( & V_35 -> V_101 . V_124 ) ;
V_171 = F_58 ( V_35 , V_9 , V_12 , V_28 , V_60 ) ;
V_180 = NULL ;
F_83 (pol, chain, bydst) {
V_179 = F_118 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_179 ) {
if ( V_179 == - V_189 )
continue;
else {
V_180 = F_15 ( V_179 ) ;
goto V_198;
}
} else {
V_180 = V_81 ;
V_168 = V_180 -> V_168 ;
break;
}
}
V_171 = & V_35 -> V_101 . V_107 [ V_60 ] ;
F_83 (pol, chain, bydst) {
V_179 = F_118 ( V_81 , V_4 , type , V_28 , V_60 ) ;
if ( V_179 ) {
if ( V_179 == - V_189 )
continue;
else {
V_180 = F_15 ( V_179 ) ;
goto V_198;
}
} else if ( V_81 -> V_168 < V_168 ) {
V_180 = V_81 ;
break;
}
}
if ( V_180 )
F_26 ( V_180 ) ;
V_198:
F_78 ( & V_35 -> V_101 . V_124 ) ;
return V_180 ;
}
static struct V_54 *
F_123 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 )
{
#ifdef F_124
struct V_54 * V_81 ;
V_81 = F_120 ( V_35 , V_199 , V_4 , V_28 , V_60 ) ;
if ( V_81 != NULL )
return V_81 ;
#endif
return F_120 ( V_35 , V_200 , V_4 , V_28 , V_60 ) ;
}
static int F_125 ( int V_60 )
{
if ( V_135 == V_201 &&
V_137 == V_202 &&
V_139 == V_203 )
return V_60 ;
switch ( V_60 ) {
default:
case V_201 :
return V_135 ;
case V_202 :
return V_137 ;
case V_203 :
return V_139 ;
}
}
static struct V_79 *
F_126 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_60 , struct V_79 * V_204 , void * V_177 )
{
struct V_54 * V_81 ;
if ( V_204 )
F_28 ( F_31 ( V_204 , struct V_54 , V_80 ) ) ;
V_81 = F_123 ( V_35 , V_4 , V_28 , F_125 ( V_60 ) ) ;
if ( F_127 ( V_81 ) )
return F_128 ( V_81 ) ;
F_26 ( V_81 ) ;
return & V_81 -> V_80 ;
}
static inline int F_129 ( int V_60 )
{
if ( V_135 == V_201 &&
V_137 == V_202 &&
V_139 == V_203 )
return V_60 ;
switch ( V_60 ) {
default:
case V_135 :
return V_201 ;
case V_137 :
return V_202 ;
case V_139 :
return V_203 ;
}
}
static struct V_54 * F_130 ( struct V_205 * V_206 , int V_60 ,
const struct V_3 * V_4 )
{
struct V_54 * V_81 ;
struct V_35 * V_35 = F_131 ( V_206 ) ;
F_77 ( & V_35 -> V_101 . V_124 ) ;
if ( ( V_81 = V_206 -> V_207 [ V_60 ] ) != NULL ) {
bool V_195 = F_7 ( & V_81 -> V_117 , V_4 ,
V_206 -> V_208 ) ;
int V_179 = 0 ;
if ( V_195 ) {
if ( ( V_206 -> V_209 & V_81 -> V_165 . V_167 ) != V_81 -> V_165 . V_166 ) {
V_81 = NULL ;
goto V_64;
}
V_179 = F_119 ( V_81 -> V_95 ,
V_4 -> V_197 ,
F_129 ( V_60 ) ) ;
if ( ! V_179 )
F_26 ( V_81 ) ;
else if ( V_179 == - V_189 )
V_81 = NULL ;
else
V_81 = F_15 ( V_179 ) ;
} else
V_81 = NULL ;
}
V_64:
F_78 ( & V_35 -> V_101 . V_124 ) ;
return V_81 ;
}
static void F_132 ( struct V_54 * V_81 , int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
struct V_103 * V_171 = F_56 ( V_35 , & V_81 -> V_117 ,
V_81 -> V_28 , V_60 ) ;
F_99 ( & V_81 -> V_62 . V_85 , & V_35 -> V_101 . V_175 ) ;
F_63 ( & V_81 -> V_86 , V_171 ) ;
F_63 ( & V_81 -> V_87 , V_35 -> V_101 . V_127 + F_54 ( V_35 , V_81 -> V_65 ) ) ;
V_35 -> V_101 . V_130 [ V_60 ] ++ ;
F_26 ( V_81 ) ;
if ( F_74 ( V_35 , V_60 , NULL ) )
F_100 ( & V_35 -> V_101 . V_148 ) ;
}
static struct V_54 * F_98 ( struct V_54 * V_81 ,
int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
if ( F_133 ( & V_81 -> V_86 ) )
return NULL ;
F_134 ( & V_81 -> V_86 ) ;
F_62 ( & V_81 -> V_87 ) ;
F_117 ( & V_81 -> V_62 . V_85 ) ;
V_35 -> V_101 . V_130 [ V_60 ] -- ;
return V_81 ;
}
int F_29 ( struct V_54 * V_81 , int V_60 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_81 = F_98 ( V_81 , V_60 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
if ( V_81 ) {
F_52 ( V_81 ) ;
return 0 ;
}
return - V_181 ;
}
int F_135 ( struct V_205 * V_206 , int V_60 , struct V_54 * V_81 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
struct V_54 * V_210 ;
#ifdef F_124
if ( V_81 && V_81 -> type != V_200 )
return - V_193 ;
#endif
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_210 = V_206 -> V_207 [ V_60 ] ;
V_206 -> V_207 [ V_60 ] = V_81 ;
if ( V_81 ) {
V_81 -> V_69 . V_70 = F_21 () ;
V_81 -> V_65 = F_82 ( V_35 , V_141 + V_60 , 0 ) ;
F_132 ( V_81 , V_141 + V_60 ) ;
}
if ( V_210 ) {
if ( V_81 )
F_85 ( V_210 , V_81 ) ;
F_98 ( V_210 , V_141 + V_60 ) ;
}
F_71 ( & V_35 -> V_101 . V_124 ) ;
if ( V_210 ) {
F_52 ( V_210 ) ;
}
return 0 ;
}
static struct V_54 * F_136 ( const struct V_54 * V_159 , int V_60 )
{
struct V_54 * V_211 = F_34 ( V_84 ( V_159 ) , V_212 ) ;
struct V_35 * V_35 = V_84 ( V_159 ) ;
if ( V_211 ) {
V_211 -> V_117 = V_159 -> V_117 ;
if ( F_137 ( V_159 -> V_95 ,
& V_211 -> V_95 ) ) {
F_48 ( V_211 ) ;
return NULL ;
}
V_211 -> V_66 = V_159 -> V_66 ;
V_211 -> V_69 = V_159 -> V_69 ;
V_211 -> V_165 = V_159 -> V_165 ;
V_211 -> V_213 = V_159 -> V_213 ;
V_211 -> V_46 = V_159 -> V_46 ;
V_211 -> V_214 = V_159 -> V_214 ;
V_211 -> V_65 = V_159 -> V_65 ;
V_211 -> type = V_159 -> type ;
memcpy ( V_211 -> V_215 , V_159 -> V_215 ,
V_211 -> V_214 * sizeof( struct V_216 ) ) ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
F_132 ( V_211 , V_141 + V_60 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
F_28 ( V_211 ) ;
}
return V_211 ;
}
int F_138 ( struct V_205 * V_206 )
{
struct V_54 * V_217 = V_206 -> V_207 [ 0 ] ,
* V_156 = V_206 -> V_207 [ 1 ] ;
V_206 -> V_207 [ 0 ] = V_206 -> V_207 [ 1 ] = NULL ;
if ( V_217 && ( V_206 -> V_207 [ 0 ] = F_136 ( V_217 , 0 ) ) == NULL )
return - V_218 ;
if ( V_156 && ( V_206 -> V_207 [ 1 ] = F_136 ( V_156 , 1 ) ) == NULL )
return - V_218 ;
return 0 ;
}
static int
F_139 ( struct V_35 * V_35 , T_1 * V_219 , T_1 * V_220 ,
unsigned short V_28 )
{
int V_179 ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return - V_193 ;
V_179 = V_32 -> V_221 ( V_35 , V_219 , V_220 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static int
F_140 ( struct V_54 * V_83 , const struct V_3 * V_4 ,
struct V_40 * * V_101 , unsigned short V_28 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
int V_222 ;
int V_123 , error ;
T_1 * V_9 = F_121 ( V_4 , V_28 ) ;
T_1 * V_12 = F_122 ( V_4 , V_28 ) ;
T_1 V_112 ;
for ( V_222 = 0 , V_123 = 0 ; V_123 < V_83 -> V_214 ; V_123 ++ ) {
struct V_40 * V_41 ;
T_1 * V_220 = V_9 ;
T_1 * V_219 = V_12 ;
struct V_216 * V_223 = & V_83 -> V_215 [ V_123 ] ;
if ( V_223 -> V_224 == V_225 ||
V_223 -> V_224 == V_226 ) {
V_220 = & V_223 -> V_45 . V_9 ;
V_219 = & V_223 -> V_12 ;
if ( F_141 ( V_219 , V_223 -> V_227 ) ) {
error = F_139 ( V_35 , & V_112 , V_220 , V_223 -> V_227 ) ;
if ( error )
goto V_198;
V_219 = & V_112 ;
}
}
V_41 = F_142 ( V_220 , V_219 , V_4 , V_223 , V_83 , & error , V_28 ) ;
if ( V_41 && V_41 -> V_228 . V_229 == V_230 ) {
V_101 [ V_222 ++ ] = V_41 ;
V_9 = V_220 ;
V_12 = V_219 ;
continue;
}
if ( V_41 ) {
error = ( V_41 -> V_228 . V_229 == V_231 ?
- V_193 : - V_232 ) ;
F_143 ( V_41 ) ;
} else if ( error == - V_189 ) {
error = - V_232 ;
}
if ( ! V_223 -> V_233 )
goto V_198;
}
return V_222 ;
V_198:
for ( V_222 -- ; V_222 >= 0 ; V_222 -- )
F_143 ( V_101 [ V_222 ] ) ;
return error ;
}
static int
F_144 ( struct V_54 * * V_234 , int V_235 , const struct V_3 * V_4 ,
struct V_40 * * V_101 , unsigned short V_28 )
{
struct V_40 * V_236 [ V_237 ] ;
struct V_40 * * V_238 = ( V_235 > 1 ) ? V_236 : V_101 ;
int V_239 = 0 ;
int error ;
int V_180 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_235 ; V_123 ++ ) {
if ( V_239 + V_234 [ V_123 ] -> V_214 >= V_237 ) {
error = - V_240 ;
goto V_198;
}
V_180 = F_140 ( V_234 [ V_123 ] , V_4 , & V_238 [ V_239 ] , V_28 ) ;
if ( V_180 < 0 ) {
error = V_180 ;
goto V_198;
} else
V_239 += V_180 ;
}
if ( V_235 > 1 )
F_145 ( V_101 , V_238 , V_239 , V_28 ) ;
return V_239 ;
V_198:
for ( V_239 -- ; V_239 >= 0 ; V_239 -- )
F_143 ( V_238 [ V_239 ] ) ;
return error ;
}
static inline int F_146 ( const struct V_3 * V_4 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_36 ;
if ( ! V_32 )
return - V_193 ;
V_36 = V_32 -> V_241 ( V_4 ) ;
F_13 ( V_32 ) ;
return V_36 ;
}
static struct V_79 * F_147 ( struct V_79 * V_80 )
{
struct V_242 * V_243 = F_31 ( V_80 , struct V_242 , V_80 ) ;
struct V_34 * V_37 = & V_243 -> V_7 . V_37 ;
if ( V_243 -> V_244 == NULL ) {
if ( V_243 -> V_245 > 0 )
return NULL ;
} else if ( V_37 -> V_46 & V_246 ) {
return NULL ;
} else {
if ( F_148 ( V_37 ) )
return NULL ;
}
F_149 ( V_37 ) ;
return V_80 ;
}
static int F_150 ( struct V_79 * V_80 )
{
struct V_242 * V_243 = F_31 ( V_80 , struct V_242 , V_80 ) ;
struct V_34 * V_37 = & V_243 -> V_7 . V_37 ;
if ( ! V_243 -> V_244 )
return 0 ;
if ( F_148 ( V_37 ) )
return 0 ;
return 1 ;
}
static void F_151 ( struct V_79 * V_80 )
{
struct V_242 * V_243 = F_31 ( V_80 , struct V_242 , V_80 ) ;
struct V_34 * V_37 = & V_243 -> V_7 . V_37 ;
F_152 ( V_37 ) ;
}
static inline struct V_242 * F_153 ( struct V_35 * V_35 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_247 * V_247 ;
struct V_242 * V_243 ;
if ( ! V_32 )
return F_15 ( - V_193 ) ;
switch ( V_28 ) {
case V_29 :
V_247 = & V_35 -> V_101 . V_248 ;
break;
#if F_154 ( V_249 )
case V_30 :
V_247 = & V_35 -> V_101 . V_250 ;
break;
#endif
default:
F_46 () ;
}
V_243 = F_155 ( V_247 , NULL , 0 , V_251 , 0 ) ;
if ( F_156 ( V_243 ) ) {
struct V_34 * V_37 = & V_243 -> V_7 . V_37 ;
memset ( V_37 + 1 , 0 , sizeof( * V_243 ) - sizeof( * V_37 ) ) ;
V_243 -> V_80 . V_93 = & V_252 ;
if ( V_32 -> V_253 )
V_32 -> V_253 ( V_35 , V_243 ) ;
} else
V_243 = F_15 ( - V_240 ) ;
F_13 ( V_32 ) ;
return V_243 ;
}
static inline int F_157 ( struct V_242 * V_254 , struct V_34 * V_37 ,
int V_255 )
{
struct V_31 * V_32 =
F_8 ( V_37 -> V_93 -> V_28 ) ;
int V_179 ;
if ( ! V_32 )
return - V_193 ;
V_179 = V_32 -> V_256 ( V_254 , V_37 , V_255 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static inline int F_158 ( struct V_242 * V_243 , struct V_257 * V_258 ,
const struct V_3 * V_4 )
{
struct V_31 * V_32 =
F_8 ( V_243 -> V_7 . V_37 . V_93 -> V_28 ) ;
int V_179 ;
if ( ! V_32 )
return - V_193 ;
V_179 = V_32 -> V_259 ( V_243 , V_258 , V_4 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static struct V_34 * F_159 ( struct V_54 * V_83 ,
struct V_40 * * V_101 , int V_222 ,
const struct V_3 * V_4 ,
struct V_34 * V_37 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
unsigned long V_56 = V_78 ;
struct V_257 * V_258 ;
struct V_260 * V_261 ;
struct V_34 * V_262 = NULL ;
struct V_34 * V_263 = NULL ;
int V_123 = 0 ;
int V_179 ;
int V_264 = 0 ;
int V_255 = 0 ;
int V_265 = 0 ;
int V_36 ;
int V_28 = V_83 -> V_117 . V_28 ;
T_1 V_12 , V_9 ;
F_160 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_36 = F_146 ( V_4 , V_28 ) ;
V_179 = V_36 ;
if ( V_36 < 0 )
goto V_266;
F_149 ( V_37 ) ;
for (; V_123 < V_222 ; V_123 ++ ) {
struct V_242 * V_243 = F_153 ( V_35 , V_28 ) ;
struct V_34 * V_267 = & V_243 -> V_7 . V_37 ;
V_179 = F_161 ( V_243 ) ;
if ( F_18 ( V_243 ) ) {
F_162 ( V_37 ) ;
goto V_266;
}
if ( V_101 [ V_123 ] -> V_2 . V_28 == V_268 ) {
V_261 = F_163 ( V_101 [ V_123 ] ,
F_164 ( V_28 ) ) ;
if ( ! V_261 ) {
V_179 = - V_38 ;
F_162 ( V_37 ) ;
goto V_266;
}
} else
V_261 = V_101 [ V_123 ] -> V_261 ;
if ( ! V_262 )
V_263 = V_267 ;
else {
V_262 -> V_269 = F_165 ( V_267 ) ;
V_267 -> V_46 |= V_270 ;
}
V_243 -> V_244 = V_37 ;
F_166 ( V_267 , V_37 ) ;
if ( V_101 [ V_123 ] -> V_44 . V_224 != V_271 ) {
V_28 = V_101 [ V_123 ] -> V_44 . V_28 ;
V_37 = F_16 ( V_101 [ V_123 ] , V_36 , & V_12 , & V_9 ,
V_28 ) ;
V_179 = F_161 ( V_37 ) ;
if ( F_18 ( V_37 ) )
goto V_266;
} else
F_149 ( V_37 ) ;
V_267 -> V_101 = V_101 [ V_123 ] ;
V_243 -> V_272 = V_101 [ V_123 ] -> V_100 ;
V_267 -> V_273 = V_274 ;
V_267 -> V_46 |= V_275 ;
V_267 -> V_276 = V_56 ;
V_267 -> V_277 = V_278 ;
V_267 -> V_279 = V_261 -> V_32 -> V_279 ;
V_267 -> V_57 = V_262 ;
V_262 = V_267 ;
V_264 += V_101 [ V_123 ] -> V_44 . V_264 ;
if ( V_101 [ V_123 ] -> type -> V_46 & V_280 )
V_255 += V_101 [ V_123 ] -> V_44 . V_264 ;
V_265 += V_101 [ V_123 ] -> V_44 . V_265 ;
}
V_262 -> V_269 = V_37 ;
V_263 -> V_254 = V_37 ;
V_179 = - V_281 ;
V_258 = V_37 -> V_258 ;
if ( ! V_258 )
goto V_282;
F_157 ( (struct V_242 * ) V_263 , V_37 , V_255 ) ;
F_167 ( V_262 ) ;
for ( V_262 = V_263 ; V_262 != V_37 ; V_262 = V_262 -> V_269 ) {
struct V_242 * V_243 = (struct V_242 * ) V_262 ;
V_179 = F_158 ( V_243 , V_258 , V_4 ) ;
if ( V_179 )
goto V_282;
V_262 -> V_264 = V_264 ;
V_262 -> V_265 = V_265 ;
V_264 -= V_243 -> V_7 . V_37 . V_101 -> V_44 . V_264 ;
V_265 -= V_243 -> V_7 . V_37 . V_101 -> V_44 . V_265 ;
}
V_64:
return V_263 ;
V_266:
for (; V_123 < V_222 ; V_123 ++ )
F_143 ( V_101 [ V_123 ] ) ;
V_282:
if ( V_263 )
F_152 ( V_263 ) ;
V_263 = F_15 ( V_179 ) ;
goto V_64;
}
static int F_168 ( void * * V_283 , const void * V_284 , int V_285 )
{
if ( ! * V_283 ) {
* V_283 = F_169 ( V_285 , V_212 ) ;
if ( ! * V_283 )
return - V_218 ;
}
memcpy ( * V_283 , V_284 , V_285 ) ;
return 0 ;
}
static int F_170 ( struct V_34 * V_37 ,
const struct V_1 * V_2 )
{
#ifdef F_124
struct V_242 * V_243 = (struct V_242 * ) V_37 ;
return F_168 ( ( void * * ) & ( V_243 -> V_286 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int F_171 ( struct V_34 * V_37 ,
const struct V_3 * V_4 )
{
#ifdef F_124
struct V_242 * V_243 = (struct V_242 * ) V_37 ;
return F_168 ( ( void * * ) & ( V_243 -> V_287 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_172 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_54 * * V_234 ,
int * V_288 , int * V_245 )
{
int V_123 ;
if ( * V_288 == 0 || ! V_234 [ 0 ] ) {
* V_288 = 0 ;
* V_245 = 0 ;
return 0 ;
}
if ( F_18 ( V_234 [ 0 ] ) )
return F_161 ( V_234 [ 0 ] ) ;
* V_245 = V_234 [ 0 ] -> V_214 ;
#ifdef F_124
if ( V_234 [ 0 ] && V_234 [ 0 ] -> V_213 == V_289 &&
V_234 [ 0 ] -> type != V_200 ) {
V_234 [ 1 ] = F_120 ( V_84 ( V_234 [ 0 ] ) ,
V_200 ,
V_4 , V_28 ,
V_137 ) ;
if ( V_234 [ 1 ] ) {
if ( F_18 ( V_234 [ 1 ] ) ) {
F_173 ( V_234 , * V_288 ) ;
return F_161 ( V_234 [ 1 ] ) ;
}
( * V_288 ) ++ ;
( * V_245 ) += V_234 [ 1 ] -> V_214 ;
}
}
#endif
for ( V_123 = 0 ; V_123 < * V_288 ; V_123 ++ ) {
if ( V_234 [ V_123 ] -> V_213 != V_289 ) {
* V_245 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_242 *
F_174 ( struct V_54 * * V_234 , int V_288 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_34 * V_290 )
{
struct V_35 * V_35 = V_84 ( V_234 [ 0 ] ) ;
struct V_40 * V_101 [ V_237 ] ;
struct V_34 * V_37 ;
struct V_242 * V_243 ;
int V_179 ;
V_179 = F_144 ( V_234 , V_288 , V_4 , V_101 , V_28 ) ;
if ( V_179 <= 0 ) {
if ( V_179 != 0 && V_179 != - V_232 )
F_175 ( V_35 , V_291 ) ;
return F_15 ( V_179 ) ;
}
V_37 = F_159 ( V_234 [ 0 ] , V_101 , V_179 , V_4 , V_290 ) ;
if ( F_18 ( V_37 ) ) {
F_175 ( V_35 , V_292 ) ;
return F_128 ( V_37 ) ;
}
V_243 = (struct V_242 * ) V_37 ;
V_243 -> V_245 = V_179 ;
if ( V_288 > 1 )
V_179 = F_170 ( V_37 , & V_234 [ 1 ] -> V_117 ) ;
else
V_179 = F_171 ( V_37 , V_4 ) ;
if ( F_9 ( V_179 ) ) {
F_152 ( V_37 ) ;
F_175 ( V_35 , V_293 ) ;
return F_15 ( V_179 ) ;
}
V_243 -> V_288 = V_288 ;
memcpy ( V_243 -> V_234 , V_234 , sizeof( struct V_54 * ) * V_288 ) ;
V_243 -> V_294 = F_176 ( & V_234 [ 0 ] -> V_100 ) ;
return V_243 ;
}
static void V_92 ( unsigned long V_295 )
{
int V_179 = 0 ;
struct V_98 * V_99 ;
struct V_205 * V_206 ;
struct V_34 * V_37 ;
struct V_54 * V_81 = (struct V_54 * ) V_295 ;
struct V_161 * V_162 = & V_81 -> V_89 ;
struct V_3 V_4 ;
struct V_96 V_97 ;
F_177 ( & V_162 -> V_90 . V_61 ) ;
V_99 = F_178 ( & V_162 -> V_90 ) ;
if ( ! V_99 ) {
F_179 ( & V_162 -> V_90 . V_61 ) ;
goto V_64;
}
V_37 = F_180 ( V_99 ) ;
V_206 = V_99 -> V_206 ;
F_181 ( V_99 , & V_4 , V_37 -> V_93 -> V_28 ) ;
F_179 ( & V_162 -> V_90 . V_61 ) ;
F_149 ( V_37 -> V_254 ) ;
V_37 = F_182 ( V_84 ( V_81 ) , V_37 -> V_254 , & V_4 ,
V_206 , 0 ) ;
if ( F_18 ( V_37 ) )
goto V_296;
if ( V_37 -> V_46 & V_246 ) {
F_162 ( V_37 ) ;
if ( V_162 -> V_163 >= V_297 )
goto V_296;
V_162 -> V_163 = V_162 -> V_163 << 1 ;
if ( ! F_25 ( & V_162 -> V_91 , V_78 + V_162 -> V_163 ) )
F_26 ( V_81 ) ;
goto V_64;
}
F_162 ( V_37 ) ;
F_86 ( & V_97 ) ;
F_177 ( & V_162 -> V_90 . V_61 ) ;
V_162 -> V_163 = 0 ;
F_88 ( & V_162 -> V_90 , & V_97 ) ;
F_179 ( & V_162 -> V_90 . V_61 ) ;
while ( ! F_90 ( & V_97 ) ) {
V_99 = F_183 ( & V_97 ) ;
F_181 ( V_99 , & V_4 , F_180 ( V_99 ) -> V_93 -> V_28 ) ;
F_149 ( F_180 ( V_99 ) -> V_254 ) ;
V_37 = F_182 ( V_84 ( V_81 ) , F_180 ( V_99 ) -> V_254 ,
& V_4 , V_99 -> V_206 , 0 ) ;
if ( F_18 ( V_37 ) ) {
F_51 ( V_99 ) ;
continue;
}
F_184 ( V_99 ) ;
F_185 ( V_99 ) ;
F_186 ( V_99 , V_37 ) ;
V_179 = F_187 ( V_99 ) ;
}
V_64:
F_28 ( V_81 ) ;
return;
V_296:
V_162 -> V_163 = 0 ;
F_49 ( & V_162 -> V_90 ) ;
F_28 ( V_81 ) ;
}
static int F_188 ( struct V_98 * V_99 )
{
unsigned long V_298 ;
struct V_34 * V_37 = F_180 ( V_99 ) ;
struct V_242 * V_243 = (struct V_242 * ) V_37 ;
struct V_54 * V_81 = V_243 -> V_234 [ 0 ] ;
struct V_161 * V_162 = & V_81 -> V_89 ;
const struct V_98 * V_299 = V_99 + 1 ;
if ( F_9 ( V_99 -> V_299 == V_300 &&
V_299 -> V_299 == V_301 ) ) {
F_51 ( V_99 ) ;
return 0 ;
}
if ( V_162 -> V_90 . V_302 > V_303 ) {
F_51 ( V_99 ) ;
return - V_232 ;
}
F_189 ( V_99 ) ;
F_87 ( & V_162 -> V_90 . V_61 ) ;
if ( ! V_162 -> V_163 )
V_162 -> V_163 = V_164 ;
V_298 = V_78 + V_162 -> V_163 ;
if ( F_45 ( & V_162 -> V_91 ) ) {
if ( F_190 ( V_162 -> V_91 . V_304 , V_298 ) )
V_298 = V_162 -> V_91 . V_304 ;
F_28 ( V_81 ) ;
}
F_191 ( & V_162 -> V_90 , V_99 ) ;
if ( ! F_25 ( & V_162 -> V_91 , V_298 ) )
F_26 ( V_81 ) ;
F_89 ( & V_162 -> V_90 . V_61 ) ;
return 0 ;
}
static struct V_242 * F_192 ( struct V_35 * V_35 ,
struct V_34 * V_37 ,
const struct V_3 * V_4 ,
int V_245 ,
T_5 V_28 )
{
int V_179 ;
struct V_257 * V_258 ;
struct V_34 * V_267 ;
struct V_242 * V_243 ;
V_243 = F_153 ( V_35 , V_28 ) ;
if ( F_18 ( V_243 ) )
return V_243 ;
if ( V_35 -> V_101 . V_305 || V_245 <= 0 )
return V_243 ;
V_267 = & V_243 -> V_7 . V_37 ;
F_149 ( V_37 ) ;
V_243 -> V_244 = V_37 ;
F_166 ( V_267 , V_37 ) ;
V_267 -> V_273 = V_274 ;
V_267 -> V_46 |= V_275 | V_246 ;
V_267 -> V_276 = V_78 ;
V_267 -> V_277 = V_278 ;
V_267 -> V_279 = F_188 ;
F_149 ( V_37 ) ;
V_267 -> V_269 = V_37 ;
V_267 -> V_254 = V_37 ;
F_157 ( (struct V_242 * ) V_267 , V_37 , 0 ) ;
V_179 = - V_281 ;
V_258 = V_37 -> V_258 ;
if ( ! V_258 )
goto V_282;
V_179 = F_158 ( V_243 , V_258 , V_4 ) ;
if ( V_179 )
goto V_282;
V_64:
return V_243 ;
V_282:
F_162 ( V_267 ) ;
V_243 = F_15 ( V_179 ) ;
goto V_64;
}
static struct V_79 *
F_193 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 ,
struct V_79 * V_306 , void * V_177 )
{
struct V_34 * V_290 = (struct V_34 * ) V_177 ;
struct V_54 * V_234 [ V_191 ] ;
struct V_242 * V_243 , * V_307 ;
int V_288 = 0 , V_245 = 0 , V_123 , V_179 , V_308 ;
V_243 = NULL ;
if ( V_306 ) {
V_243 = F_31 ( V_306 , struct V_242 , V_80 ) ;
V_288 = V_243 -> V_288 ;
V_245 = V_243 -> V_245 ;
V_308 = 0 ;
for ( V_123 = 0 ; V_123 < V_288 ; V_123 ++ ) {
V_234 [ V_123 ] = V_243 -> V_234 [ V_123 ] ;
V_308 |= V_234 [ V_123 ] -> V_62 . V_63 ;
}
if ( V_308 ) {
F_152 ( & V_243 -> V_7 . V_37 ) ;
V_243 = NULL ;
V_288 = 0 ;
V_245 = 0 ;
V_306 = NULL ;
}
}
if ( V_243 == NULL ) {
V_288 = 1 ;
V_234 [ 0 ] = F_123 ( V_35 , V_4 , V_28 ,
F_125 ( V_60 ) ) ;
V_179 = F_172 ( V_4 , V_28 , V_234 ,
& V_288 , & V_245 ) ;
if ( V_179 < 0 )
goto V_309;
if ( V_288 == 0 )
return NULL ;
if ( V_245 <= 0 )
goto V_310;
}
V_307 = F_174 ( V_234 , V_288 , V_4 , V_28 , V_290 ) ;
if ( F_18 ( V_307 ) ) {
V_179 = F_161 ( V_307 ) ;
if ( V_179 != - V_232 )
goto error;
if ( V_306 == NULL )
goto V_310;
F_149 ( & V_243 -> V_7 . V_37 ) ;
return V_306 ;
} else if ( V_307 == NULL ) {
V_245 = 0 ;
if ( V_306 == NULL )
goto V_310;
V_243 -> V_245 = 0 ;
F_149 ( & V_243 -> V_7 . V_37 ) ;
return V_306 ;
}
if ( V_243 ) {
V_243 -> V_288 = 0 ;
F_152 ( & V_243 -> V_7 . V_37 ) ;
}
F_149 ( & V_307 -> V_7 . V_37 ) ;
return & V_307 -> V_80 ;
V_310:
V_243 = F_192 ( V_35 , V_290 , V_4 , V_245 , V_28 ) ;
if ( F_18 ( V_243 ) ) {
F_173 ( V_234 , V_288 ) ;
return F_128 ( V_243 ) ;
}
V_243 -> V_288 = V_288 ;
V_243 -> V_245 = V_245 ;
memcpy ( V_243 -> V_234 , V_234 , sizeof( struct V_54 * ) * V_288 ) ;
F_149 ( & V_243 -> V_7 . V_37 ) ;
return & V_243 -> V_80 ;
V_309:
F_175 ( V_35 , V_291 ) ;
error:
if ( V_243 != NULL )
F_152 ( & V_243 -> V_7 . V_37 ) ;
else
F_173 ( V_234 , V_288 ) ;
return F_15 ( V_179 ) ;
}
static struct V_34 * F_194 ( struct V_35 * V_35 , T_5 V_28 ,
struct V_34 * V_290 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_34 * V_180 ;
if ( ! V_32 ) {
F_162 ( V_290 ) ;
return F_15 ( - V_193 ) ;
} else {
V_180 = V_32 -> V_311 ( V_35 , V_290 ) ;
}
F_13 ( V_32 ) ;
return V_180 ;
}
struct V_34 * F_182 ( struct V_35 * V_35 , struct V_34 * V_290 ,
const struct V_3 * V_4 ,
struct V_205 * V_206 , int V_46 )
{
struct V_54 * V_234 [ V_191 ] ;
struct V_79 * V_80 ;
struct V_242 * V_243 ;
struct V_34 * V_37 , * V_244 ;
T_5 V_28 = V_290 -> V_93 -> V_28 ;
T_4 V_60 = F_129 ( V_137 ) ;
int V_123 , V_179 , V_288 , V_245 = 0 , V_312 = 0 ;
V_37 = NULL ;
V_243 = NULL ;
V_244 = NULL ;
if ( V_206 && V_206 -> V_207 [ V_137 ] ) {
V_288 = 1 ;
V_234 [ 0 ] = F_130 ( V_206 , V_137 , V_4 ) ;
V_179 = F_172 ( V_4 , V_28 , V_234 ,
& V_288 , & V_245 ) ;
if ( V_179 < 0 )
goto V_313;
if ( V_288 ) {
if ( V_245 <= 0 ) {
V_312 = V_288 ;
goto V_314;
}
V_243 = F_174 (
V_234 , V_288 , V_4 ,
V_28 , V_290 ) ;
if ( F_18 ( V_243 ) ) {
F_173 ( V_234 , V_288 ) ;
V_179 = F_161 ( V_243 ) ;
goto V_313;
} else if ( V_243 == NULL ) {
V_245 = 0 ;
V_312 = V_288 ;
goto V_314;
}
F_149 ( & V_243 -> V_7 . V_37 ) ;
F_87 ( & V_35 -> V_101 . V_315 ) ;
V_243 -> V_7 . V_37 . V_57 = V_316 ;
V_316 = & V_243 -> V_7 . V_37 ;
F_89 ( & V_35 -> V_101 . V_315 ) ;
V_244 = V_243 -> V_244 ;
}
}
if ( V_243 == NULL ) {
if ( ( V_290 -> V_46 & V_317 ) ||
! V_35 -> V_101 . V_130 [ V_137 ] )
goto V_318;
V_80 = F_195 ( V_35 , V_4 , V_28 , V_60 ,
F_193 , V_290 ) ;
if ( V_80 == NULL )
goto V_318;
if ( F_18 ( V_80 ) ) {
V_179 = F_161 ( V_80 ) ;
goto V_313;
}
V_243 = F_31 ( V_80 , struct V_242 , V_80 ) ;
V_288 = V_243 -> V_288 ;
V_245 = V_243 -> V_245 ;
memcpy ( V_234 , V_243 -> V_234 , sizeof( struct V_54 * ) * V_288 ) ;
V_244 = V_243 -> V_244 ;
}
V_37 = & V_243 -> V_7 . V_37 ;
if ( V_244 == NULL && V_245 > 0 ) {
if ( V_35 -> V_101 . V_305 ) {
F_162 ( V_37 ) ;
F_173 ( V_234 , V_312 ) ;
F_175 ( V_35 , V_319 ) ;
return F_194 ( V_35 , V_28 , V_290 ) ;
}
V_179 = - V_232 ;
F_175 ( V_35 , V_319 ) ;
goto error;
}
V_314:
if ( V_288 == 0 )
goto V_318;
if ( ( V_46 & V_320 ) &&
! ( V_234 [ 0 ] -> V_46 & V_321 ) ) {
V_179 = - V_181 ;
goto error;
}
for ( V_123 = 0 ; V_123 < V_288 ; V_123 ++ )
V_234 [ V_123 ] -> V_69 . V_73 = F_21 () ;
if ( V_245 < 0 ) {
F_175 ( V_35 , V_322 ) ;
V_179 = - V_323 ;
goto error;
} else if ( V_245 > 0 ) {
F_162 ( V_290 ) ;
} else {
F_162 ( V_37 ) ;
V_37 = V_290 ;
}
V_324:
F_173 ( V_234 , V_312 ) ;
if ( V_37 && V_37 -> V_101 &&
V_37 -> V_101 -> V_44 . V_224 == V_225 )
V_37 -> V_46 |= V_325 ;
return V_37 ;
V_318:
if ( ! ( V_46 & V_320 ) ) {
V_37 = V_290 ;
goto V_324;
}
V_179 = - V_181 ;
error:
F_162 ( V_37 ) ;
V_313:
F_162 ( V_290 ) ;
F_173 ( V_234 , V_312 ) ;
return F_15 ( V_179 ) ;
}
static inline int
F_196 ( int V_152 , struct V_98 * V_99 , const struct V_3 * V_4 )
{
struct V_40 * V_41 ;
if ( ! V_99 -> V_326 || V_152 < 0 || V_152 >= V_99 -> V_326 -> V_158 )
return 0 ;
V_41 = V_99 -> V_326 -> V_327 [ V_152 ] ;
if ( ! V_41 -> type -> V_328 )
return 0 ;
return V_41 -> type -> V_328 ( V_41 , V_99 , V_4 ) ;
}
static inline int
F_197 ( const struct V_216 * V_223 , const struct V_40 * V_41 ,
unsigned short V_28 )
{
if ( F_198 ( V_41 ) )
return V_223 -> V_233 && ! F_199 ( V_223 , V_41 , V_223 -> V_227 ) ;
return V_41 -> V_45 . V_20 == V_223 -> V_45 . V_20 &&
( V_41 -> V_45 . V_329 == V_223 -> V_45 . V_329 || ! V_223 -> V_45 . V_329 ) &&
( V_41 -> V_44 . V_330 == V_223 -> V_330 || ! V_223 -> V_330 ) &&
V_41 -> V_44 . V_224 == V_223 -> V_224 &&
( V_223 -> V_331 || ( V_223 -> V_332 & ( 1 << V_41 -> V_44 . V_333 ) ) ||
! ( F_200 ( V_223 -> V_45 . V_20 , V_334 ) ) ) &&
! ( V_41 -> V_44 . V_224 != V_271 &&
F_199 ( V_223 , V_41 , V_28 ) ) ;
}
static inline int
F_201 ( const struct V_216 * V_223 , const struct V_335 * V_326 , int V_336 ,
unsigned short V_28 )
{
int V_152 = V_336 ;
if ( V_223 -> V_233 ) {
if ( V_223 -> V_224 == V_271 )
return V_336 ;
} else
V_336 = - 1 ;
for (; V_152 < V_326 -> V_158 ; V_152 ++ ) {
if ( F_197 ( V_223 , V_326 -> V_327 [ V_152 ] , V_28 ) )
return ++ V_152 ;
if ( V_326 -> V_327 [ V_152 ] -> V_44 . V_224 != V_271 ) {
if ( V_336 == - 1 )
V_336 = - 2 - V_152 ;
break;
}
}
return V_336 ;
}
int F_202 ( struct V_98 * V_99 , struct V_3 * V_4 ,
unsigned int V_28 , int V_337 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_179 ;
if ( F_9 ( V_32 == NULL ) )
return - V_38 ;
V_32 -> V_338 ( V_99 , V_4 , V_337 ) ;
V_179 = F_203 ( V_99 , & V_4 -> V_197 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static inline int F_204 ( const struct V_335 * V_326 , int V_339 , int * V_340 )
{
for (; V_339 < V_326 -> V_158 ; V_339 ++ ) {
if ( V_326 -> V_327 [ V_339 ] -> V_44 . V_224 != V_271 ) {
* V_340 = V_339 ;
return 1 ;
}
}
return 0 ;
}
int F_205 ( struct V_205 * V_206 , int V_60 , struct V_98 * V_99 ,
unsigned short V_28 )
{
struct V_35 * V_35 = F_206 ( V_99 -> V_258 ) ;
struct V_54 * V_81 ;
struct V_54 * V_234 [ V_191 ] ;
int V_235 = 0 ;
int V_214 ;
int V_341 ;
int V_337 ;
struct V_3 V_4 ;
T_4 V_342 ;
int V_343 = - 1 ;
V_337 = V_60 & ~ V_344 ;
V_60 &= V_344 ;
V_342 = F_129 ( V_60 ) ;
if ( F_202 ( V_99 , & V_4 , V_28 , V_337 ) < 0 ) {
F_175 ( V_35 , V_345 ) ;
return 0 ;
}
F_207 ( V_99 , & V_4 , V_28 ) ;
if ( V_99 -> V_326 ) {
int V_123 ;
for ( V_123 = V_99 -> V_326 -> V_158 - 1 ; V_123 >= 0 ; V_123 -- ) {
struct V_40 * V_41 = V_99 -> V_326 -> V_327 [ V_123 ] ;
if ( ! F_7 ( & V_41 -> V_2 , & V_4 , V_28 ) ) {
F_175 ( V_35 , V_346 ) ;
return 0 ;
}
}
}
V_81 = NULL ;
if ( V_206 && V_206 -> V_207 [ V_60 ] ) {
V_81 = F_130 ( V_206 , V_60 , & V_4 ) ;
if ( F_18 ( V_81 ) ) {
F_175 ( V_35 , V_347 ) ;
return 0 ;
}
}
if ( ! V_81 ) {
struct V_79 * V_80 ;
V_80 = F_195 ( V_35 , & V_4 , V_28 , V_342 ,
F_126 , NULL ) ;
if ( F_127 ( V_80 ) )
V_81 = F_128 ( V_80 ) ;
else
V_81 = F_31 ( V_80 , struct V_54 , V_80 ) ;
}
if ( F_18 ( V_81 ) ) {
F_175 ( V_35 , V_347 ) ;
return 0 ;
}
if ( ! V_81 ) {
if ( V_99 -> V_326 && F_204 ( V_99 -> V_326 , 0 , & V_343 ) ) {
F_196 ( V_343 , V_99 , & V_4 ) ;
F_175 ( V_35 , V_348 ) ;
return 0 ;
}
return 1 ;
}
V_81 -> V_69 . V_73 = F_21 () ;
V_234 [ 0 ] = V_81 ;
V_235 ++ ;
#ifdef F_124
if ( V_234 [ 0 ] -> type != V_200 ) {
V_234 [ 1 ] = F_120 ( V_35 , V_200 ,
& V_4 , V_28 ,
V_135 ) ;
if ( V_234 [ 1 ] ) {
if ( F_18 ( V_234 [ 1 ] ) ) {
F_175 ( V_35 , V_347 ) ;
return 0 ;
}
V_234 [ 1 ] -> V_69 . V_73 = F_21 () ;
V_235 ++ ;
}
}
#endif
if ( V_81 -> V_213 == V_289 ) {
struct V_335 * V_326 ;
static struct V_335 V_349 ;
struct V_216 * V_236 [ V_237 ] ;
struct V_216 * V_350 [ V_237 ] ;
struct V_216 * * V_238 = V_236 ;
int V_351 = 0 ;
int V_123 , V_339 ;
if ( ( V_326 = V_99 -> V_326 ) == NULL )
V_326 = & V_349 ;
for ( V_341 = 0 ; V_341 < V_235 ; V_341 ++ ) {
if ( V_234 [ V_341 ] != V_81 &&
V_234 [ V_341 ] -> V_213 != V_289 ) {
F_175 ( V_35 , V_352 ) ;
goto V_328;
}
if ( V_351 + V_234 [ V_341 ] -> V_214 >= V_237 ) {
F_175 ( V_35 , V_353 ) ;
goto V_354;
}
for ( V_123 = 0 ; V_123 < V_234 [ V_341 ] -> V_214 ; V_123 ++ )
V_238 [ V_351 ++ ] = & V_234 [ V_341 ] -> V_215 [ V_123 ] ;
}
V_214 = V_351 ;
if ( V_235 > 1 ) {
F_208 ( V_350 , V_238 , V_214 , V_28 , V_35 ) ;
V_238 = V_350 ;
}
for ( V_123 = V_214 - 1 , V_339 = 0 ; V_123 >= 0 ; V_123 -- ) {
V_339 = F_201 ( V_238 [ V_123 ] , V_326 , V_339 , V_28 ) ;
if ( V_339 < 0 ) {
if ( V_339 < - 1 )
V_343 = - ( 2 + V_339 ) ;
F_175 ( V_35 , V_355 ) ;
goto V_328;
}
}
if ( F_204 ( V_326 , V_339 , & V_343 ) ) {
F_175 ( V_35 , V_355 ) ;
goto V_328;
}
F_173 ( V_234 , V_235 ) ;
return 1 ;
}
F_175 ( V_35 , V_352 ) ;
V_328:
F_196 ( V_343 , V_99 , & V_4 ) ;
V_354:
F_173 ( V_234 , V_235 ) ;
return 0 ;
}
int F_209 ( struct V_98 * V_99 , unsigned short V_28 )
{
struct V_35 * V_35 = F_206 ( V_99 -> V_258 ) ;
struct V_3 V_4 ;
struct V_34 * V_37 ;
int V_356 = 1 ;
if ( F_181 ( V_99 , & V_4 , V_28 ) < 0 ) {
F_175 ( V_35 , V_357 ) ;
return 0 ;
}
F_189 ( V_99 ) ;
V_37 = F_182 ( V_35 , F_180 ( V_99 ) , & V_4 , NULL , 0 ) ;
if ( F_18 ( V_37 ) ) {
V_356 = 0 ;
V_37 = NULL ;
}
F_186 ( V_99 , V_37 ) ;
return V_356 ;
}
static struct V_34 * F_210 ( struct V_34 * V_37 , T_3 V_358 )
{
if ( V_37 -> V_273 < 0 && ! F_148 ( V_37 ) )
return V_37 ;
return NULL ;
}
static int F_148 ( struct V_34 * V_37 )
{
return ! F_211 ( (struct V_242 * ) V_37 ) ;
}
void F_212 ( struct V_34 * V_37 , struct V_257 * V_258 )
{
while ( ( V_37 = V_37 -> V_269 ) && V_37 -> V_101 && V_37 -> V_258 == V_258 ) {
V_37 -> V_258 = F_206 ( V_258 ) -> V_359 ;
F_213 ( V_37 -> V_258 ) ;
F_214 ( V_258 ) ;
}
}
static void F_215 ( struct V_98 * V_99 )
{
}
static struct V_34 * F_216 ( struct V_34 * V_37 )
{
if ( V_37 ) {
if ( V_37 -> V_273 ) {
F_162 ( V_37 ) ;
V_37 = NULL ;
}
}
return V_37 ;
}
static void F_217 ( struct V_35 * V_35 )
{
struct V_34 * V_360 , * V_57 ;
F_87 ( & V_35 -> V_101 . V_315 ) ;
V_360 = V_316 ;
V_316 = NULL ;
F_89 ( & V_35 -> V_101 . V_315 ) ;
while ( V_360 ) {
V_57 = V_360 -> V_57 ;
F_152 ( V_360 ) ;
V_360 = V_57 ;
}
}
void F_218 ( struct V_35 * V_35 )
{
F_219 () ;
F_217 ( V_35 ) ;
}
static void F_220 ( struct V_35 * V_35 )
{
F_221 () ;
F_217 ( V_35 ) ;
}
static void F_167 ( struct V_34 * V_37 )
{
do {
struct V_242 * V_243 = (struct V_242 * ) V_37 ;
T_3 V_361 , V_362 ;
V_361 = F_222 ( V_37 -> V_269 ) ;
V_243 -> V_363 = V_361 ;
V_361 = F_223 ( V_37 -> V_101 , V_361 ) ;
V_362 = F_222 ( V_243 -> V_244 ) ;
V_243 -> V_362 = V_362 ;
if ( V_361 > V_362 )
V_361 = V_362 ;
F_224 ( V_37 , V_364 , V_361 ) ;
} while ( ( V_37 = V_37 -> V_57 ) );
}
static int F_211 ( struct V_242 * V_365 )
{
struct V_34 * V_37 = & V_365 -> V_7 . V_37 ;
struct V_242 * V_366 ;
T_3 V_367 ;
if ( ! F_225 ( V_37 -> V_254 , ( (struct V_242 * ) V_37 ) -> V_368 ) ||
( V_37 -> V_258 && ! F_226 ( V_37 -> V_258 ) ) )
return 0 ;
if ( V_37 -> V_46 & V_246 )
return 1 ;
V_366 = NULL ;
do {
struct V_242 * V_243 = (struct V_242 * ) V_37 ;
if ( V_37 -> V_101 -> V_228 . V_229 != V_230 )
return 0 ;
if ( V_243 -> V_272 != V_37 -> V_101 -> V_100 )
return 0 ;
if ( V_243 -> V_288 > 0 &&
V_243 -> V_294 != F_176 ( & V_243 -> V_234 [ 0 ] -> V_100 ) )
return 0 ;
V_367 = F_222 ( V_37 -> V_269 ) ;
if ( V_243 -> V_363 != V_367 ) {
V_366 = V_243 ;
V_243 -> V_363 = V_367 ;
}
if ( ! F_225 ( V_243 -> V_244 , V_243 -> V_369 ) )
return 0 ;
V_367 = F_222 ( V_243 -> V_244 ) ;
if ( V_243 -> V_362 != V_367 ) {
V_366 = V_243 ;
V_243 -> V_362 = V_367 ;
}
V_37 = V_37 -> V_269 ;
} while ( V_37 -> V_101 );
if ( F_156 ( ! V_366 ) )
return 1 ;
V_367 = V_366 -> V_363 ;
for (; ; ) {
V_37 = & V_366 -> V_7 . V_37 ;
V_367 = F_223 ( V_37 -> V_101 , V_367 ) ;
if ( V_367 > V_366 -> V_362 )
V_367 = V_366 -> V_362 ;
F_224 ( V_37 , V_364 , V_367 ) ;
if ( V_366 == V_365 )
break;
V_366 = (struct V_242 * ) V_366 -> V_7 . V_37 . V_57 ;
V_366 -> V_363 = V_367 ;
}
return 1 ;
}
static unsigned int F_227 ( const struct V_34 * V_37 )
{
return F_228 ( V_37 -> V_254 ) ;
}
static unsigned int F_229 ( const struct V_34 * V_37 )
{
unsigned int V_367 = F_230 ( V_37 , V_364 ) ;
return V_367 ? : F_222 ( V_37 -> V_254 ) ;
}
static struct V_370 * F_231 ( const struct V_34 * V_37 ,
struct V_98 * V_99 ,
const void * V_9 )
{
return V_37 -> V_254 -> V_93 -> V_371 ( V_37 , V_99 , V_9 ) ;
}
int F_232 ( struct V_31 * V_32 )
{
struct V_35 * V_35 ;
int V_179 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_193 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_177 ( & V_372 ) ;
if ( F_9 ( V_31 [ V_32 -> V_28 ] != NULL ) )
V_179 = - V_240 ;
else {
struct V_247 * V_247 = V_32 -> V_247 ;
if ( F_156 ( V_247 -> V_373 == NULL ) )
V_247 -> V_373 = V_374 ;
if ( F_156 ( V_247 -> V_375 == NULL ) )
V_247 -> V_375 = F_210 ;
if ( F_156 ( V_247 -> V_376 == NULL ) )
V_247 -> V_376 = F_227 ;
if ( F_156 ( V_247 -> V_367 == NULL ) )
V_247 -> V_367 = F_229 ;
if ( F_156 ( V_247 -> V_377 == NULL ) )
V_247 -> V_377 = F_216 ;
if ( F_156 ( V_247 -> V_378 == NULL ) )
V_247 -> V_378 = F_215 ;
if ( F_156 ( V_247 -> V_371 == NULL ) )
V_247 -> V_371 = F_231 ;
if ( F_156 ( V_32 -> V_379 == NULL ) )
V_32 -> V_379 = F_220 ;
F_233 ( V_31 [ V_32 -> V_28 ] , V_32 ) ;
}
F_179 ( & V_372 ) ;
F_234 () ;
F_235 (net) {
struct V_247 * V_380 ;
switch ( V_32 -> V_28 ) {
case V_29 :
V_380 = & V_35 -> V_101 . V_248 ;
break;
#if F_154 ( V_249 )
case V_30 :
V_380 = & V_35 -> V_101 . V_250 ;
break;
#endif
default:
F_46 () ;
}
* V_380 = * V_32 -> V_247 ;
}
F_236 () ;
return V_179 ;
}
int F_237 ( struct V_31 * V_32 )
{
int V_179 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_193 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_177 ( & V_372 ) ;
if ( F_156 ( V_31 [ V_32 -> V_28 ] != NULL ) ) {
if ( F_9 ( V_31 [ V_32 -> V_28 ] != V_32 ) )
V_179 = - V_193 ;
else
F_238 ( V_31 [ V_32 -> V_28 ] ,
NULL ) ;
}
F_179 ( & V_372 ) ;
if ( ! V_179 ) {
struct V_247 * V_247 = V_32 -> V_247 ;
F_239 () ;
V_247 -> V_373 = NULL ;
V_247 -> V_375 = NULL ;
V_247 -> V_377 = NULL ;
V_247 -> V_378 = NULL ;
V_32 -> V_379 = NULL ;
}
return V_179 ;
}
static void T_6 F_240 ( struct V_35 * V_35 )
{
struct V_31 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_31 [ V_29 ] ) ;
if ( V_32 )
V_35 -> V_101 . V_248 = * V_32 -> V_247 ;
#if F_154 ( V_249 )
V_32 = F_11 ( V_31 [ V_30 ] ) ;
if ( V_32 )
V_35 -> V_101 . V_250 = * V_32 -> V_247 ;
#endif
F_12 () ;
}
static int F_241 ( struct V_381 * V_382 , unsigned long V_383 , void * V_384 )
{
struct V_257 * V_258 = F_242 ( V_384 ) ;
switch ( V_383 ) {
case V_385 :
F_218 ( F_206 ( V_258 ) ) ;
}
return V_386 ;
}
static int T_6 F_243 ( struct V_35 * V_35 )
{
int V_387 ;
if ( F_244 ( ( void V_388 * * ) V_35 -> V_389 . V_390 ,
sizeof( struct V_391 ) ,
F_245 ( struct V_391 ) ) < 0 )
return - V_218 ;
V_387 = F_246 ( V_35 ) ;
if ( V_387 < 0 )
F_247 ( ( void V_388 * * ) V_35 -> V_389 . V_390 ) ;
return V_387 ;
}
static void F_248 ( struct V_35 * V_35 )
{
F_249 ( V_35 ) ;
F_247 ( ( void V_388 * * ) V_35 -> V_389 . V_390 ) ;
}
static int T_6 F_243 ( struct V_35 * V_35 )
{
return 0 ;
}
static void F_248 ( struct V_35 * V_35 )
{
}
static int T_6 F_250 ( struct V_35 * V_35 )
{
unsigned int V_104 , V_392 ;
int V_60 ;
if ( F_251 ( V_35 , & V_393 ) )
V_374 = F_252 ( L_1 ,
sizeof( struct V_242 ) ,
0 , V_394 | V_395 ,
NULL ) ;
V_104 = 8 - 1 ;
V_392 = ( V_104 + 1 ) * sizeof( struct V_103 ) ;
V_35 -> V_101 . V_127 = F_69 ( V_392 ) ;
if ( ! V_35 -> V_101 . V_127 )
goto V_396;
V_35 -> V_101 . V_102 = V_104 ;
for ( V_60 = 0 ; V_60 < V_141 * 2 ; V_60 ++ ) {
struct V_397 * V_398 ;
V_35 -> V_101 . V_130 [ V_60 ] = 0 ;
F_253 ( & V_35 -> V_101 . V_107 [ V_60 ] ) ;
V_398 = & V_35 -> V_101 . V_105 [ V_60 ] ;
V_398 -> V_108 = F_69 ( V_392 ) ;
if ( ! V_398 -> V_108 )
goto V_399;
V_398 -> V_104 = V_104 ;
}
F_37 ( & V_35 -> V_101 . V_175 ) ;
F_254 ( & V_35 -> V_101 . V_148 , F_79 ) ;
if ( F_251 ( V_35 , & V_393 ) )
F_255 ( & V_400 ) ;
return 0 ;
V_399:
for ( V_60 -- ; V_60 >= 0 ; V_60 -- ) {
struct V_397 * V_398 ;
V_398 = & V_35 -> V_101 . V_105 [ V_60 ] ;
F_72 ( V_398 -> V_108 , V_392 ) ;
}
F_72 ( V_35 -> V_101 . V_127 , V_392 ) ;
V_396:
return - V_218 ;
}
static void F_256 ( struct V_35 * V_35 )
{
struct V_182 V_183 ;
unsigned int V_392 ;
int V_60 ;
F_257 ( & V_35 -> V_101 . V_148 ) ;
#ifdef F_124
V_183 . V_184 = V_401 ;
V_183 . V_185 = ( unsigned int ) - 1 ;
V_183 . V_186 = 0 ;
F_106 ( V_35 , V_199 , & V_183 ) ;
#endif
V_183 . V_184 = V_401 ;
V_183 . V_185 = ( unsigned int ) - 1 ;
V_183 . V_186 = 0 ;
F_106 ( V_35 , V_200 , & V_183 ) ;
F_95 ( ! F_109 ( & V_35 -> V_101 . V_175 ) ) ;
for ( V_60 = 0 ; V_60 < V_141 * 2 ; V_60 ++ ) {
struct V_397 * V_398 ;
F_95 ( ! F_65 ( & V_35 -> V_101 . V_107 [ V_60 ] ) ) ;
V_398 = & V_35 -> V_101 . V_105 [ V_60 ] ;
V_392 = ( V_398 -> V_104 + 1 ) * sizeof( struct V_103 ) ;
F_95 ( ! F_65 ( V_398 -> V_108 ) ) ;
F_72 ( V_398 -> V_108 , V_392 ) ;
}
V_392 = ( V_35 -> V_101 . V_102 + 1 ) * sizeof( struct V_103 ) ;
F_95 ( ! F_65 ( V_35 -> V_101 . V_127 ) ) ;
F_72 ( V_35 -> V_101 . V_127 , V_392 ) ;
}
static int T_6 F_258 ( struct V_35 * V_35 )
{
int V_387 ;
V_387 = F_243 ( V_35 ) ;
if ( V_387 < 0 )
goto V_402;
V_387 = F_259 ( V_35 ) ;
if ( V_387 < 0 )
goto V_403;
V_387 = F_250 ( V_35 ) ;
if ( V_387 < 0 )
goto V_404;
F_240 ( V_35 ) ;
V_387 = F_260 ( V_35 ) ;
if ( V_387 < 0 )
goto V_405;
F_261 ( & V_35 -> V_101 . V_406 ) ;
F_39 ( & V_35 -> V_101 . V_124 ) ;
F_261 ( & V_35 -> V_101 . V_315 ) ;
F_262 ( & V_35 -> V_101 . V_407 ) ;
return 0 ;
V_405:
F_256 ( V_35 ) ;
V_404:
F_263 ( V_35 ) ;
V_403:
F_248 ( V_35 ) ;
V_402:
return V_387 ;
}
static void T_7 F_264 ( struct V_35 * V_35 )
{
F_265 ( V_35 ) ;
F_256 ( V_35 ) ;
F_263 ( V_35 ) ;
F_248 ( V_35 ) ;
}
void T_8 F_266 ( void )
{
F_267 ( & V_408 ) ;
F_268 () ;
}
static void F_269 ( struct V_54 * V_55 ,
struct V_409 * V_410 )
{
struct V_176 * V_177 = V_55 -> V_95 ;
struct V_1 * V_2 = & V_55 -> V_117 ;
if ( V_177 )
F_270 ( V_410 , L_2 ,
V_177 -> V_411 , V_177 -> V_412 , V_177 -> V_413 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_270 ( V_410 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_270 ( V_410 , L_4 ,
V_2 -> V_13 ) ;
F_270 ( V_410 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_270 ( V_410 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_270 ( V_410 , L_7 , V_2 -> V_12 . V_414 ) ;
if ( V_2 -> V_13 != 128 )
F_270 ( V_410 , L_4 ,
V_2 -> V_13 ) ;
F_270 ( V_410 , L_8 , V_2 -> V_9 . V_414 ) ;
if ( V_2 -> V_11 != 128 )
F_270 ( V_410 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_271 ( struct V_54 * V_55 , int V_415 ,
T_9 V_416 , unsigned int V_185 , T_3 V_186 )
{
struct V_409 * V_410 ;
V_410 = F_272 ( L_9 ) ;
if ( V_410 == NULL )
return;
F_273 ( V_416 , V_185 , V_186 , V_410 ) ;
F_270 ( V_410 , L_10 , V_415 ) ;
F_269 ( V_55 , V_410 ) ;
F_274 ( V_410 ) ;
}
void F_105 ( struct V_54 * V_55 , int V_415 ,
T_9 V_416 , unsigned int V_185 , T_3 V_186 )
{
struct V_409 * V_410 ;
V_410 = F_272 ( L_11 ) ;
if ( V_410 == NULL )
return;
F_273 ( V_416 , V_185 , V_186 , V_410 ) ;
F_270 ( V_410 , L_10 , V_415 ) ;
F_269 ( V_55 , V_410 ) ;
F_274 ( V_410 ) ;
}
static bool F_275 ( const struct V_1 * V_417 ,
const struct V_1 * V_418 )
{
if ( V_417 -> V_20 == V_419 ) {
if ( V_418 -> V_28 == V_417 -> V_28 &&
F_276 ( & V_418 -> V_9 , & V_417 -> V_9 ,
V_417 -> V_28 ) &&
F_276 ( & V_418 -> V_12 , & V_417 -> V_12 ,
V_417 -> V_28 ) &&
V_418 -> V_11 == V_417 -> V_11 &&
V_418 -> V_13 == V_417 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_418 , V_417 , sizeof( * V_418 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_54 * F_277 ( const struct V_1 * V_2 ,
T_4 V_60 , T_4 type , struct V_35 * V_35 )
{
struct V_54 * V_81 , * V_180 = NULL ;
struct V_103 * V_171 ;
T_3 V_168 = ~ 0U ;
F_77 ( & V_35 -> V_101 . V_124 ) ;
V_171 = F_58 ( V_35 , & V_2 -> V_9 , & V_2 -> V_12 , V_2 -> V_28 , V_60 ) ;
F_83 (pol, chain, bydst) {
if ( F_275 ( V_2 , & V_81 -> V_117 ) &&
V_81 -> type == type ) {
V_180 = V_81 ;
V_168 = V_180 -> V_168 ;
break;
}
}
V_171 = & V_35 -> V_101 . V_107 [ V_60 ] ;
F_83 (pol, chain, bydst) {
if ( F_275 ( V_2 , & V_81 -> V_117 ) &&
V_81 -> type == type &&
V_81 -> V_168 < V_168 ) {
V_180 = V_81 ;
break;
}
}
if ( V_180 )
F_26 ( V_180 ) ;
F_78 ( & V_35 -> V_101 . V_124 ) ;
return V_180 ;
}
static int F_278 ( const struct V_420 * V_167 , const struct V_216 * V_421 )
{
int V_195 = 0 ;
if ( V_421 -> V_224 == V_167 -> V_224 && V_421 -> V_45 . V_20 == V_167 -> V_20 &&
( V_167 -> V_330 == 0 || V_421 -> V_330 == V_167 -> V_330 ) ) {
switch ( V_421 -> V_224 ) {
case V_225 :
case V_226 :
if ( F_276 ( & V_421 -> V_45 . V_9 , & V_167 -> V_422 ,
V_167 -> V_423 ) &&
F_276 ( & V_421 -> V_12 , & V_167 -> V_424 ,
V_167 -> V_423 ) ) {
V_195 = 1 ;
}
break;
case V_271 :
V_195 = 1 ;
break;
default:
break;
}
}
return V_195 ;
}
static int F_279 ( struct V_54 * V_81 ,
struct V_420 * V_167 , int V_425 )
{
struct V_420 * V_426 ;
int V_123 , V_427 , V_428 = 0 ;
F_70 ( & V_81 -> V_61 ) ;
if ( F_9 ( V_81 -> V_62 . V_63 ) ) {
F_71 ( & V_81 -> V_61 ) ;
return - V_181 ;
}
for ( V_123 = 0 ; V_123 < V_81 -> V_214 ; V_123 ++ ) {
for ( V_427 = 0 , V_426 = V_167 ; V_427 < V_425 ; V_427 ++ , V_426 ++ ) {
if ( ! F_278 ( V_426 , & V_81 -> V_215 [ V_123 ] ) )
continue;
V_428 ++ ;
if ( V_81 -> V_215 [ V_123 ] . V_224 != V_225 &&
V_81 -> V_215 [ V_123 ] . V_224 != V_226 )
continue;
memcpy ( & V_81 -> V_215 [ V_123 ] . V_45 . V_9 , & V_426 -> V_429 ,
sizeof( V_81 -> V_215 [ V_123 ] . V_45 . V_9 ) ) ;
memcpy ( & V_81 -> V_215 [ V_123 ] . V_12 , & V_426 -> V_430 ,
sizeof( V_81 -> V_215 [ V_123 ] . V_12 ) ) ;
V_81 -> V_215 [ V_123 ] . V_227 = V_426 -> V_431 ;
F_53 ( & V_81 -> V_100 ) ;
}
}
F_71 ( & V_81 -> V_61 ) ;
if ( ! V_428 )
return - V_432 ;
return 0 ;
}
static int F_280 ( const struct V_420 * V_167 , int V_425 )
{
int V_123 , V_427 ;
if ( V_425 < 1 || V_425 > V_237 )
return - V_193 ;
for ( V_123 = 0 ; V_123 < V_425 ; V_123 ++ ) {
if ( F_276 ( & V_167 [ V_123 ] . V_422 , & V_167 [ V_123 ] . V_429 ,
V_167 [ V_123 ] . V_423 ) &&
F_276 ( & V_167 [ V_123 ] . V_424 , & V_167 [ V_123 ] . V_430 ,
V_167 [ V_123 ] . V_423 ) )
return - V_193 ;
if ( F_141 ( & V_167 [ V_123 ] . V_429 , V_167 [ V_123 ] . V_431 ) ||
F_141 ( & V_167 [ V_123 ] . V_430 , V_167 [ V_123 ] . V_431 ) )
return - V_193 ;
for ( V_427 = V_123 + 1 ; V_427 < V_425 ; V_427 ++ ) {
if ( ! memcmp ( & V_167 [ V_123 ] . V_422 , & V_167 [ V_427 ] . V_422 ,
sizeof( V_167 [ V_123 ] . V_422 ) ) &&
! memcmp ( & V_167 [ V_123 ] . V_424 , & V_167 [ V_427 ] . V_424 ,
sizeof( V_167 [ V_123 ] . V_424 ) ) &&
V_167 [ V_123 ] . V_20 == V_167 [ V_427 ] . V_20 &&
V_167 [ V_123 ] . V_224 == V_167 [ V_427 ] . V_224 &&
V_167 [ V_123 ] . V_330 == V_167 [ V_427 ] . V_330 &&
V_167 [ V_123 ] . V_423 == V_167 [ V_427 ] . V_423 )
return - V_193 ;
}
}
return 0 ;
}
int V_420 ( const struct V_1 * V_2 , T_4 V_60 , T_4 type ,
struct V_420 * V_167 , int V_425 ,
struct V_433 * V_339 , struct V_35 * V_35 )
{
int V_123 , V_179 , V_434 = 0 , V_435 = 0 ;
struct V_54 * V_81 = NULL ;
struct V_40 * V_41 , * V_436 ;
struct V_40 * V_437 [ V_237 ] ;
struct V_40 * V_438 [ V_237 ] ;
struct V_420 * V_426 ;
if ( ( V_179 = F_280 ( V_167 , V_425 ) ) < 0 )
goto V_64;
if ( ( V_81 = F_277 ( V_2 , V_60 , type , V_35 ) ) == NULL ) {
V_179 = - V_181 ;
goto V_64;
}
for ( V_123 = 0 , V_426 = V_167 ; V_123 < V_425 ; V_123 ++ , V_426 ++ ) {
if ( ( V_41 = F_281 ( V_426 , V_35 ) ) ) {
V_437 [ V_434 ] = V_41 ;
V_434 ++ ;
if ( ( V_436 = F_282 ( V_41 , V_426 ) ) ) {
V_438 [ V_435 ] = V_436 ;
V_435 ++ ;
} else {
V_179 = - V_432 ;
goto V_439;
}
}
}
if ( ( V_179 = F_279 ( V_81 , V_167 , V_425 ) ) < 0 )
goto V_439;
if ( V_434 ) {
F_283 ( V_437 , V_434 ) ;
F_284 ( V_437 , V_434 ) ;
}
F_285 ( V_2 , V_60 , type , V_167 , V_425 , V_339 ) ;
F_28 ( V_81 ) ;
return 0 ;
V_64:
return V_179 ;
V_439:
if ( V_81 )
F_28 ( V_81 ) ;
if ( V_434 )
F_283 ( V_437 , V_434 ) ;
if ( V_435 )
F_284 ( V_438 , V_435 ) ;
return V_179 ;
}
