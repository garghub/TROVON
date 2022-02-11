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
F_53 ( & V_35 -> V_101 . V_174 ) ;
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
F_104 ( struct V_35 * V_35 , T_4 type , bool V_182 )
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
F_105 ( V_81 , 0 , V_182 ) ;
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
V_182 ) ;
return V_179 ;
}
}
}
}
return V_179 ;
}
static inline int
F_104 ( struct V_35 * V_35 , T_4 type , bool V_182 )
{
return 0 ;
}
int F_106 ( struct V_35 * V_35 , T_4 type , bool V_182 )
{
int V_60 , V_179 = 0 , V_129 = 0 ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_179 = F_104 ( V_35 , type , V_182 ) ;
if ( V_179 )
goto V_64;
for ( V_60 = 0 ; V_60 < V_141 ; V_60 ++ ) {
struct V_54 * V_81 ;
int V_123 ;
V_183:
F_83 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_81 -> type != type )
continue;
F_98 ( V_81 , V_60 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
V_129 ++ ;
F_105 ( V_81 , 1 , V_182 ) ;
F_52 ( V_81 ) ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
goto V_183;
}
for ( V_123 = V_35 -> V_101 . V_105 [ V_60 ] . V_104 ; V_123 >= 0 ; V_123 -- ) {
V_184:
F_83 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_81 -> type != type )
continue;
F_98 ( V_81 , V_60 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
V_129 ++ ;
F_105 ( V_81 , 1 , V_182 ) ;
F_52 ( V_81 ) ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
goto V_184;
}
}
}
if ( ! V_129 )
V_179 = - V_185 ;
V_64:
F_71 ( & V_35 -> V_101 . V_124 ) ;
return V_179 ;
}
int F_107 ( struct V_35 * V_35 , struct F_107 * V_62 ,
int (* F_108)( struct V_54 * , int , int , void * ) ,
void * V_53 )
{
struct V_54 * V_81 ;
struct V_186 * V_41 ;
int error = 0 ;
if ( V_62 -> type >= V_187 &&
V_62 -> type != V_188 )
return - V_189 ;
if ( F_109 ( & V_62 -> V_62 . V_85 ) && V_62 -> V_190 != 0 )
return 0 ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
if ( F_109 ( & V_62 -> V_62 . V_85 ) )
V_41 = F_110 ( & V_35 -> V_101 . V_175 , struct V_186 , V_85 ) ;
else
V_41 = F_111 ( & V_62 -> V_62 . V_85 , struct V_186 , V_85 ) ;
F_112 (x, &net->xfrm.policy_all, all) {
if ( V_41 -> V_63 )
continue;
V_81 = F_31 ( V_41 , struct V_54 , V_62 ) ;
if ( V_62 -> type != V_188 &&
V_62 -> type != V_81 -> type )
continue;
error = F_108 ( V_81 , F_23 ( V_81 -> V_65 ) ,
V_62 -> V_190 , V_53 ) ;
if ( error ) {
F_113 ( & V_62 -> V_62 . V_85 , & V_41 -> V_85 ) ;
goto V_64;
}
V_62 -> V_190 ++ ;
}
if ( V_62 -> V_190 == 0 ) {
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
V_62 -> V_190 = 0 ;
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
int V_180 = - V_185 ;
bool V_191 ;
if ( V_81 -> V_28 != V_28 ||
( V_4 -> V_192 & V_81 -> V_165 . V_167 ) != V_81 -> V_165 . V_166 ||
V_81 -> type != type )
return V_180 ;
V_191 = F_7 ( V_2 , V_4 , V_28 ) ;
if ( V_191 )
V_180 = F_119 ( V_81 -> V_95 , V_4 -> V_193 ,
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
if ( V_179 == - V_185 )
continue;
else {
V_180 = F_15 ( V_179 ) ;
goto V_194;
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
if ( V_179 == - V_185 )
continue;
else {
V_180 = F_15 ( V_179 ) ;
goto V_194;
}
} else if ( V_81 -> V_168 < V_168 ) {
V_180 = V_81 ;
break;
}
}
if ( V_180 )
F_26 ( V_180 ) ;
V_194:
F_78 ( & V_35 -> V_101 . V_124 ) ;
return V_180 ;
}
static struct V_54 *
F_123 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 )
{
#ifdef F_124
struct V_54 * V_81 ;
V_81 = F_120 ( V_35 , V_195 , V_4 , V_28 , V_60 ) ;
if ( V_81 != NULL )
return V_81 ;
#endif
return F_120 ( V_35 , V_196 , V_4 , V_28 , V_60 ) ;
}
static int F_125 ( int V_60 )
{
if ( V_135 == V_197 &&
V_137 == V_198 &&
V_139 == V_199 )
return V_60 ;
switch ( V_60 ) {
default:
case V_197 :
return V_135 ;
case V_198 :
return V_137 ;
case V_199 :
return V_139 ;
}
}
static struct V_79 *
F_126 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 ,
T_4 V_60 , struct V_79 * V_200 , void * V_177 )
{
struct V_54 * V_81 ;
if ( V_200 )
F_28 ( F_31 ( V_200 , struct V_54 , V_80 ) ) ;
V_81 = F_123 ( V_35 , V_4 , V_28 , F_125 ( V_60 ) ) ;
if ( F_127 ( V_81 ) )
return F_128 ( V_81 ) ;
F_26 ( V_81 ) ;
return & V_81 -> V_80 ;
}
static inline int F_129 ( int V_60 )
{
if ( V_135 == V_197 &&
V_137 == V_198 &&
V_139 == V_199 )
return V_60 ;
switch ( V_60 ) {
default:
case V_135 :
return V_197 ;
case V_137 :
return V_198 ;
case V_139 :
return V_199 ;
}
}
static struct V_54 * F_130 ( struct V_201 * V_202 , int V_60 ,
const struct V_3 * V_4 )
{
struct V_54 * V_81 ;
struct V_35 * V_35 = F_131 ( V_202 ) ;
F_77 ( & V_35 -> V_101 . V_124 ) ;
if ( ( V_81 = V_202 -> V_203 [ V_60 ] ) != NULL ) {
bool V_191 = F_7 ( & V_81 -> V_117 , V_4 ,
V_202 -> V_204 ) ;
int V_179 = 0 ;
if ( V_191 ) {
if ( ( V_202 -> V_205 & V_81 -> V_165 . V_167 ) != V_81 -> V_165 . V_166 ) {
V_81 = NULL ;
goto V_64;
}
V_179 = F_119 ( V_81 -> V_95 ,
V_4 -> V_193 ,
F_129 ( V_60 ) ) ;
if ( ! V_179 )
F_26 ( V_81 ) ;
else if ( V_179 == - V_185 )
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
int F_135 ( struct V_201 * V_202 , int V_60 , struct V_54 * V_81 )
{
struct V_35 * V_35 = V_84 ( V_81 ) ;
struct V_54 * V_206 ;
#ifdef F_124
if ( V_81 && V_81 -> type != V_196 )
return - V_189 ;
#endif
F_70 ( & V_35 -> V_101 . V_124 ) ;
V_206 = V_202 -> V_203 [ V_60 ] ;
V_202 -> V_203 [ V_60 ] = V_81 ;
if ( V_81 ) {
V_81 -> V_69 . V_70 = F_21 () ;
V_81 -> V_65 = F_82 ( V_35 , V_141 + V_60 , 0 ) ;
F_132 ( V_81 , V_141 + V_60 ) ;
}
if ( V_206 ) {
if ( V_81 )
F_85 ( V_206 , V_81 ) ;
F_98 ( V_206 , V_141 + V_60 ) ;
}
F_71 ( & V_35 -> V_101 . V_124 ) ;
if ( V_206 ) {
F_52 ( V_206 ) ;
}
return 0 ;
}
static struct V_54 * F_136 ( const struct V_54 * V_159 , int V_60 )
{
struct V_54 * V_207 = F_34 ( V_84 ( V_159 ) , V_208 ) ;
struct V_35 * V_35 = V_84 ( V_159 ) ;
if ( V_207 ) {
V_207 -> V_117 = V_159 -> V_117 ;
if ( F_137 ( V_159 -> V_95 ,
& V_207 -> V_95 ) ) {
F_48 ( V_207 ) ;
return NULL ;
}
V_207 -> V_66 = V_159 -> V_66 ;
V_207 -> V_69 = V_159 -> V_69 ;
V_207 -> V_165 = V_159 -> V_165 ;
V_207 -> V_209 = V_159 -> V_209 ;
V_207 -> V_46 = V_159 -> V_46 ;
V_207 -> V_210 = V_159 -> V_210 ;
V_207 -> V_65 = V_159 -> V_65 ;
V_207 -> type = V_159 -> type ;
memcpy ( V_207 -> V_211 , V_159 -> V_211 ,
V_207 -> V_210 * sizeof( struct V_212 ) ) ;
F_70 ( & V_35 -> V_101 . V_124 ) ;
F_132 ( V_207 , V_141 + V_60 ) ;
F_71 ( & V_35 -> V_101 . V_124 ) ;
F_28 ( V_207 ) ;
}
return V_207 ;
}
int F_138 ( struct V_201 * V_202 )
{
struct V_54 * V_213 = V_202 -> V_203 [ 0 ] ,
* V_156 = V_202 -> V_203 [ 1 ] ;
V_202 -> V_203 [ 0 ] = V_202 -> V_203 [ 1 ] = NULL ;
if ( V_213 && ( V_202 -> V_203 [ 0 ] = F_136 ( V_213 , 0 ) ) == NULL )
return - V_214 ;
if ( V_156 && ( V_202 -> V_203 [ 1 ] = F_136 ( V_156 , 1 ) ) == NULL )
return - V_214 ;
return 0 ;
}
static int
F_139 ( struct V_35 * V_35 , T_1 * V_215 , T_1 * V_216 ,
unsigned short V_28 )
{
int V_179 ;
struct V_31 * V_32 = F_8 ( V_28 ) ;
if ( F_9 ( V_32 == NULL ) )
return - V_189 ;
V_179 = V_32 -> V_217 ( V_35 , V_215 , V_216 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static int
F_140 ( struct V_54 * V_83 , const struct V_3 * V_4 ,
struct V_40 * * V_101 , unsigned short V_28 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
int V_218 ;
int V_123 , error ;
T_1 * V_9 = F_121 ( V_4 , V_28 ) ;
T_1 * V_12 = F_122 ( V_4 , V_28 ) ;
T_1 V_112 ;
for ( V_218 = 0 , V_123 = 0 ; V_123 < V_83 -> V_210 ; V_123 ++ ) {
struct V_40 * V_41 ;
T_1 * V_216 = V_9 ;
T_1 * V_215 = V_12 ;
struct V_212 * V_219 = & V_83 -> V_211 [ V_123 ] ;
if ( V_219 -> V_220 == V_221 ||
V_219 -> V_220 == V_222 ) {
V_216 = & V_219 -> V_45 . V_9 ;
V_215 = & V_219 -> V_12 ;
if ( F_141 ( V_215 , V_219 -> V_223 ) ) {
error = F_139 ( V_35 , & V_112 , V_216 , V_219 -> V_223 ) ;
if ( error )
goto V_194;
V_215 = & V_112 ;
}
}
V_41 = F_142 ( V_216 , V_215 , V_4 , V_219 , V_83 , & error , V_28 ) ;
if ( V_41 && V_41 -> V_224 . V_225 == V_226 ) {
V_101 [ V_218 ++ ] = V_41 ;
V_9 = V_216 ;
V_12 = V_215 ;
continue;
}
if ( V_41 ) {
error = ( V_41 -> V_224 . V_225 == V_227 ?
- V_189 : - V_228 ) ;
F_143 ( V_41 ) ;
} else if ( error == - V_185 ) {
error = - V_228 ;
}
if ( ! V_219 -> V_229 )
goto V_194;
}
return V_218 ;
V_194:
for ( V_218 -- ; V_218 >= 0 ; V_218 -- )
F_143 ( V_101 [ V_218 ] ) ;
return error ;
}
static int
F_144 ( struct V_54 * * V_230 , int V_231 , const struct V_3 * V_4 ,
struct V_40 * * V_101 , unsigned short V_28 )
{
struct V_40 * V_232 [ V_233 ] ;
struct V_40 * * V_234 = ( V_231 > 1 ) ? V_232 : V_101 ;
int V_235 = 0 ;
int error ;
int V_180 ;
int V_123 ;
for ( V_123 = 0 ; V_123 < V_231 ; V_123 ++ ) {
if ( V_235 + V_230 [ V_123 ] -> V_210 >= V_233 ) {
error = - V_236 ;
goto V_194;
}
V_180 = F_140 ( V_230 [ V_123 ] , V_4 , & V_234 [ V_235 ] , V_28 ) ;
if ( V_180 < 0 ) {
error = V_180 ;
goto V_194;
} else
V_235 += V_180 ;
}
if ( V_231 > 1 )
F_145 ( V_101 , V_234 , V_235 , V_28 ) ;
return V_235 ;
V_194:
for ( V_235 -- ; V_235 >= 0 ; V_235 -- )
F_143 ( V_234 [ V_235 ] ) ;
return error ;
}
static inline int F_146 ( const struct V_3 * V_4 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_36 ;
if ( ! V_32 )
return - V_189 ;
V_36 = V_32 -> V_237 ( V_4 ) ;
F_13 ( V_32 ) ;
return V_36 ;
}
static struct V_79 * F_147 ( struct V_79 * V_80 )
{
struct V_238 * V_239 = F_31 ( V_80 , struct V_238 , V_80 ) ;
struct V_34 * V_37 = & V_239 -> V_7 . V_37 ;
if ( V_239 -> V_240 == NULL ) {
if ( V_239 -> V_241 > 0 )
return NULL ;
} else if ( V_37 -> V_46 & V_242 ) {
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
struct V_238 * V_239 = F_31 ( V_80 , struct V_238 , V_80 ) ;
struct V_34 * V_37 = & V_239 -> V_7 . V_37 ;
if ( ! V_239 -> V_240 )
return 0 ;
if ( F_148 ( V_37 ) )
return 0 ;
return 1 ;
}
static void F_151 ( struct V_79 * V_80 )
{
struct V_238 * V_239 = F_31 ( V_80 , struct V_238 , V_80 ) ;
struct V_34 * V_37 = & V_239 -> V_7 . V_37 ;
F_152 ( V_37 ) ;
}
static inline struct V_238 * F_153 ( struct V_35 * V_35 , int V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_243 * V_243 ;
struct V_238 * V_239 ;
if ( ! V_32 )
return F_15 ( - V_189 ) ;
switch ( V_28 ) {
case V_29 :
V_243 = & V_35 -> V_101 . V_244 ;
break;
#if F_154 ( V_245 )
case V_30 :
V_243 = & V_35 -> V_101 . V_246 ;
break;
#endif
default:
F_46 () ;
}
V_239 = F_155 ( V_243 , NULL , 0 , V_247 , 0 ) ;
if ( F_156 ( V_239 ) ) {
struct V_34 * V_37 = & V_239 -> V_7 . V_37 ;
memset ( V_37 + 1 , 0 , sizeof( * V_239 ) - sizeof( * V_37 ) ) ;
V_239 -> V_80 . V_93 = & V_248 ;
if ( V_32 -> V_249 )
V_32 -> V_249 ( V_35 , V_239 ) ;
} else
V_239 = F_15 ( - V_236 ) ;
F_13 ( V_32 ) ;
return V_239 ;
}
static inline int F_157 ( struct V_238 * V_250 , struct V_34 * V_37 ,
int V_251 )
{
struct V_31 * V_32 =
F_8 ( V_37 -> V_93 -> V_28 ) ;
int V_179 ;
if ( ! V_32 )
return - V_189 ;
V_179 = V_32 -> V_252 ( V_250 , V_37 , V_251 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static inline int F_158 ( struct V_238 * V_239 , struct V_253 * V_254 ,
const struct V_3 * V_4 )
{
struct V_31 * V_32 =
F_8 ( V_239 -> V_7 . V_37 . V_93 -> V_28 ) ;
int V_179 ;
if ( ! V_32 )
return - V_189 ;
V_179 = V_32 -> V_255 ( V_239 , V_254 , V_4 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static struct V_34 * F_159 ( struct V_54 * V_83 ,
struct V_40 * * V_101 , int V_218 ,
const struct V_3 * V_4 ,
struct V_34 * V_37 )
{
struct V_35 * V_35 = V_84 ( V_83 ) ;
unsigned long V_56 = V_78 ;
struct V_253 * V_254 ;
struct V_256 * V_257 ;
struct V_34 * V_258 = NULL ;
struct V_34 * V_259 = NULL ;
int V_123 = 0 ;
int V_179 ;
int V_260 = 0 ;
int V_251 = 0 ;
int V_261 = 0 ;
int V_36 ;
int V_28 = V_83 -> V_117 . V_28 ;
T_1 V_12 , V_9 ;
F_160 ( V_4 , & V_12 , & V_9 , V_28 ) ;
V_36 = F_146 ( V_4 , V_28 ) ;
V_179 = V_36 ;
if ( V_36 < 0 )
goto V_262;
F_149 ( V_37 ) ;
for (; V_123 < V_218 ; V_123 ++ ) {
struct V_238 * V_239 = F_153 ( V_35 , V_28 ) ;
struct V_34 * V_263 = & V_239 -> V_7 . V_37 ;
V_179 = F_161 ( V_239 ) ;
if ( F_18 ( V_239 ) ) {
F_162 ( V_37 ) ;
goto V_262;
}
if ( V_101 [ V_123 ] -> V_2 . V_28 == V_264 ) {
V_257 = F_163 ( V_101 [ V_123 ] ,
F_164 ( V_28 ) ) ;
if ( ! V_257 ) {
V_179 = - V_38 ;
F_162 ( V_37 ) ;
goto V_262;
}
} else
V_257 = V_101 [ V_123 ] -> V_257 ;
if ( ! V_258 )
V_259 = V_263 ;
else {
V_258 -> V_265 = F_165 ( V_263 ) ;
V_263 -> V_46 |= V_266 ;
}
V_239 -> V_240 = V_37 ;
F_166 ( V_263 , V_37 ) ;
if ( V_101 [ V_123 ] -> V_44 . V_220 != V_267 ) {
V_28 = V_101 [ V_123 ] -> V_44 . V_28 ;
V_37 = F_16 ( V_101 [ V_123 ] , V_36 , & V_12 , & V_9 ,
V_28 ) ;
V_179 = F_161 ( V_37 ) ;
if ( F_18 ( V_37 ) )
goto V_262;
} else
F_149 ( V_37 ) ;
V_263 -> V_101 = V_101 [ V_123 ] ;
V_239 -> V_268 = V_101 [ V_123 ] -> V_100 ;
V_263 -> V_269 = V_270 ;
V_263 -> V_46 |= V_271 ;
V_263 -> V_272 = V_56 ;
V_263 -> V_273 = V_274 ;
V_263 -> V_275 = V_257 -> V_32 -> V_275 ;
V_263 -> V_57 = V_258 ;
V_258 = V_263 ;
V_260 += V_101 [ V_123 ] -> V_44 . V_260 ;
if ( V_101 [ V_123 ] -> type -> V_46 & V_276 )
V_251 += V_101 [ V_123 ] -> V_44 . V_260 ;
V_261 += V_101 [ V_123 ] -> V_44 . V_261 ;
}
V_258 -> V_265 = V_37 ;
V_259 -> V_250 = V_37 ;
V_179 = - V_277 ;
V_254 = V_37 -> V_254 ;
if ( ! V_254 )
goto V_278;
F_157 ( (struct V_238 * ) V_259 , V_37 , V_251 ) ;
F_167 ( V_258 ) ;
for ( V_258 = V_259 ; V_258 != V_37 ; V_258 = V_258 -> V_265 ) {
struct V_238 * V_239 = (struct V_238 * ) V_258 ;
V_179 = F_158 ( V_239 , V_254 , V_4 ) ;
if ( V_179 )
goto V_278;
V_258 -> V_260 = V_260 ;
V_258 -> V_261 = V_261 ;
V_260 -= V_239 -> V_7 . V_37 . V_101 -> V_44 . V_260 ;
V_261 -= V_239 -> V_7 . V_37 . V_101 -> V_44 . V_261 ;
}
V_64:
return V_259 ;
V_262:
for (; V_123 < V_218 ; V_123 ++ )
F_143 ( V_101 [ V_123 ] ) ;
V_278:
if ( V_259 )
F_152 ( V_259 ) ;
V_259 = F_15 ( V_179 ) ;
goto V_64;
}
static int F_168 ( void * * V_279 , const void * V_280 , int V_281 )
{
if ( ! * V_279 ) {
* V_279 = F_169 ( V_281 , V_208 ) ;
if ( ! * V_279 )
return - V_214 ;
}
memcpy ( * V_279 , V_280 , V_281 ) ;
return 0 ;
}
static int F_170 ( struct V_34 * V_37 ,
const struct V_1 * V_2 )
{
#ifdef F_124
struct V_238 * V_239 = (struct V_238 * ) V_37 ;
return F_168 ( ( void * * ) & ( V_239 -> V_282 ) ,
V_2 , sizeof( * V_2 ) ) ;
#else
return 0 ;
#endif
}
static int F_171 ( struct V_34 * V_37 ,
const struct V_3 * V_4 )
{
#ifdef F_124
struct V_238 * V_239 = (struct V_238 * ) V_37 ;
return F_168 ( ( void * * ) & ( V_239 -> V_283 ) , V_4 , sizeof( * V_4 ) ) ;
#else
return 0 ;
#endif
}
static int F_172 ( const struct V_3 * V_4 , T_5 V_28 ,
struct V_54 * * V_230 ,
int * V_284 , int * V_241 )
{
int V_123 ;
if ( * V_284 == 0 || ! V_230 [ 0 ] ) {
* V_284 = 0 ;
* V_241 = 0 ;
return 0 ;
}
if ( F_18 ( V_230 [ 0 ] ) )
return F_161 ( V_230 [ 0 ] ) ;
* V_241 = V_230 [ 0 ] -> V_210 ;
#ifdef F_124
if ( V_230 [ 0 ] && V_230 [ 0 ] -> V_209 == V_285 &&
V_230 [ 0 ] -> type != V_196 ) {
V_230 [ 1 ] = F_120 ( V_84 ( V_230 [ 0 ] ) ,
V_196 ,
V_4 , V_28 ,
V_137 ) ;
if ( V_230 [ 1 ] ) {
if ( F_18 ( V_230 [ 1 ] ) ) {
F_173 ( V_230 , * V_284 ) ;
return F_161 ( V_230 [ 1 ] ) ;
}
( * V_284 ) ++ ;
( * V_241 ) += V_230 [ 1 ] -> V_210 ;
}
}
#endif
for ( V_123 = 0 ; V_123 < * V_284 ; V_123 ++ ) {
if ( V_230 [ V_123 ] -> V_209 != V_285 ) {
* V_241 = - 1 ;
break;
}
}
return 0 ;
}
static struct V_238 *
F_174 ( struct V_54 * * V_230 , int V_284 ,
const struct V_3 * V_4 , T_5 V_28 ,
struct V_34 * V_286 )
{
struct V_35 * V_35 = V_84 ( V_230 [ 0 ] ) ;
struct V_40 * V_101 [ V_233 ] ;
struct V_34 * V_37 ;
struct V_238 * V_239 ;
int V_179 ;
V_179 = F_144 ( V_230 , V_284 , V_4 , V_101 , V_28 ) ;
if ( V_179 <= 0 ) {
if ( V_179 != 0 && V_179 != - V_228 )
F_175 ( V_35 , V_287 ) ;
return F_15 ( V_179 ) ;
}
V_37 = F_159 ( V_230 [ 0 ] , V_101 , V_179 , V_4 , V_286 ) ;
if ( F_18 ( V_37 ) ) {
F_175 ( V_35 , V_288 ) ;
return F_128 ( V_37 ) ;
}
V_239 = (struct V_238 * ) V_37 ;
V_239 -> V_241 = V_179 ;
if ( V_284 > 1 )
V_179 = F_170 ( V_37 , & V_230 [ 1 ] -> V_117 ) ;
else
V_179 = F_171 ( V_37 , V_4 ) ;
if ( F_9 ( V_179 ) ) {
F_152 ( V_37 ) ;
F_175 ( V_35 , V_289 ) ;
return F_15 ( V_179 ) ;
}
V_239 -> V_284 = V_284 ;
memcpy ( V_239 -> V_230 , V_230 , sizeof( struct V_54 * ) * V_284 ) ;
V_239 -> V_290 = F_176 ( & V_230 [ 0 ] -> V_100 ) ;
return V_239 ;
}
static void V_92 ( unsigned long V_291 )
{
int V_179 = 0 ;
struct V_98 * V_99 ;
struct V_201 * V_202 ;
struct V_34 * V_37 ;
struct V_54 * V_81 = (struct V_54 * ) V_291 ;
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
V_202 = V_99 -> V_202 ;
F_181 ( V_99 , & V_4 , V_37 -> V_93 -> V_28 ) ;
F_179 ( & V_162 -> V_90 . V_61 ) ;
F_149 ( V_37 -> V_250 ) ;
V_37 = F_182 ( V_84 ( V_81 ) , V_37 -> V_250 , & V_4 ,
V_202 , 0 ) ;
if ( F_18 ( V_37 ) )
goto V_292;
if ( V_37 -> V_46 & V_242 ) {
F_162 ( V_37 ) ;
if ( V_162 -> V_163 >= V_293 )
goto V_292;
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
F_149 ( F_180 ( V_99 ) -> V_250 ) ;
V_37 = F_182 ( V_84 ( V_81 ) , F_180 ( V_99 ) -> V_250 ,
& V_4 , V_99 -> V_202 , 0 ) ;
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
V_292:
V_162 -> V_163 = 0 ;
F_49 ( & V_162 -> V_90 ) ;
F_28 ( V_81 ) ;
}
static int F_188 ( struct V_201 * V_202 , struct V_98 * V_99 )
{
unsigned long V_294 ;
struct V_34 * V_37 = F_180 ( V_99 ) ;
struct V_238 * V_239 = (struct V_238 * ) V_37 ;
struct V_54 * V_81 = V_239 -> V_230 [ 0 ] ;
struct V_161 * V_162 = & V_81 -> V_89 ;
const struct V_98 * V_295 = V_99 + 1 ;
if ( F_9 ( V_99 -> V_295 == V_296 &&
V_295 -> V_295 == V_297 ) ) {
F_51 ( V_99 ) ;
return 0 ;
}
if ( V_162 -> V_90 . V_298 > V_299 ) {
F_51 ( V_99 ) ;
return - V_228 ;
}
F_189 ( V_99 ) ;
F_87 ( & V_162 -> V_90 . V_61 ) ;
if ( ! V_162 -> V_163 )
V_162 -> V_163 = V_164 ;
V_294 = V_78 + V_162 -> V_163 ;
if ( F_45 ( & V_162 -> V_91 ) ) {
if ( F_190 ( V_162 -> V_91 . V_300 , V_294 ) )
V_294 = V_162 -> V_91 . V_300 ;
F_28 ( V_81 ) ;
}
F_191 ( & V_162 -> V_90 , V_99 ) ;
if ( ! F_25 ( & V_162 -> V_91 , V_294 ) )
F_26 ( V_81 ) ;
F_89 ( & V_162 -> V_90 . V_61 ) ;
return 0 ;
}
static struct V_238 * F_192 ( struct V_35 * V_35 ,
struct V_34 * V_37 ,
const struct V_3 * V_4 ,
int V_241 ,
T_5 V_28 )
{
int V_179 ;
struct V_253 * V_254 ;
struct V_34 * V_263 ;
struct V_238 * V_239 ;
V_239 = F_153 ( V_35 , V_28 ) ;
if ( F_18 ( V_239 ) )
return V_239 ;
if ( V_35 -> V_101 . V_301 || V_241 <= 0 )
return V_239 ;
V_263 = & V_239 -> V_7 . V_37 ;
F_149 ( V_37 ) ;
V_239 -> V_240 = V_37 ;
F_166 ( V_263 , V_37 ) ;
V_263 -> V_269 = V_270 ;
V_263 -> V_46 |= V_271 | V_242 ;
V_263 -> V_272 = V_78 ;
V_263 -> V_273 = V_274 ;
V_263 -> V_275 = F_188 ;
F_149 ( V_37 ) ;
V_263 -> V_265 = V_37 ;
V_263 -> V_250 = V_37 ;
F_157 ( (struct V_238 * ) V_263 , V_37 , 0 ) ;
V_179 = - V_277 ;
V_254 = V_37 -> V_254 ;
if ( ! V_254 )
goto V_278;
V_179 = F_158 ( V_239 , V_254 , V_4 ) ;
if ( V_179 )
goto V_278;
V_64:
return V_239 ;
V_278:
F_162 ( V_263 ) ;
V_239 = F_15 ( V_179 ) ;
goto V_64;
}
static struct V_79 *
F_193 ( struct V_35 * V_35 , const struct V_3 * V_4 , T_5 V_28 , T_4 V_60 ,
struct V_79 * V_302 , void * V_177 )
{
struct V_34 * V_286 = (struct V_34 * ) V_177 ;
struct V_54 * V_230 [ V_187 ] ;
struct V_238 * V_239 , * V_303 ;
int V_284 = 0 , V_241 = 0 , V_123 , V_179 , V_304 ;
V_239 = NULL ;
if ( V_302 ) {
V_239 = F_31 ( V_302 , struct V_238 , V_80 ) ;
V_284 = V_239 -> V_284 ;
V_241 = V_239 -> V_241 ;
V_304 = 0 ;
for ( V_123 = 0 ; V_123 < V_284 ; V_123 ++ ) {
V_230 [ V_123 ] = V_239 -> V_230 [ V_123 ] ;
V_304 |= V_230 [ V_123 ] -> V_62 . V_63 ;
}
if ( V_304 ) {
F_152 ( & V_239 -> V_7 . V_37 ) ;
V_239 = NULL ;
V_284 = 0 ;
V_241 = 0 ;
V_302 = NULL ;
}
}
if ( V_239 == NULL ) {
V_284 = 1 ;
V_230 [ 0 ] = F_123 ( V_35 , V_4 , V_28 ,
F_125 ( V_60 ) ) ;
V_179 = F_172 ( V_4 , V_28 , V_230 ,
& V_284 , & V_241 ) ;
if ( V_179 < 0 )
goto V_305;
if ( V_284 == 0 )
return NULL ;
if ( V_241 <= 0 )
goto V_306;
}
V_303 = F_174 ( V_230 , V_284 , V_4 , V_28 , V_286 ) ;
if ( F_18 ( V_303 ) ) {
V_179 = F_161 ( V_303 ) ;
if ( V_179 != - V_228 )
goto error;
if ( V_302 == NULL )
goto V_306;
F_149 ( & V_239 -> V_7 . V_37 ) ;
return V_302 ;
} else if ( V_303 == NULL ) {
V_241 = 0 ;
if ( V_302 == NULL )
goto V_306;
V_239 -> V_241 = 0 ;
F_149 ( & V_239 -> V_7 . V_37 ) ;
return V_302 ;
}
if ( V_239 ) {
V_239 -> V_284 = 0 ;
F_152 ( & V_239 -> V_7 . V_37 ) ;
}
F_149 ( & V_303 -> V_7 . V_37 ) ;
return & V_303 -> V_80 ;
V_306:
V_239 = F_192 ( V_35 , V_286 , V_4 , V_241 , V_28 ) ;
if ( F_18 ( V_239 ) ) {
F_173 ( V_230 , V_284 ) ;
return F_128 ( V_239 ) ;
}
V_239 -> V_284 = V_284 ;
V_239 -> V_241 = V_241 ;
memcpy ( V_239 -> V_230 , V_230 , sizeof( struct V_54 * ) * V_284 ) ;
F_149 ( & V_239 -> V_7 . V_37 ) ;
return & V_239 -> V_80 ;
V_305:
F_175 ( V_35 , V_287 ) ;
error:
if ( V_239 != NULL )
F_152 ( & V_239 -> V_7 . V_37 ) ;
else
F_173 ( V_230 , V_284 ) ;
return F_15 ( V_179 ) ;
}
static struct V_34 * F_194 ( struct V_35 * V_35 , T_5 V_28 ,
struct V_34 * V_286 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
struct V_34 * V_180 ;
if ( ! V_32 ) {
F_162 ( V_286 ) ;
return F_15 ( - V_189 ) ;
} else {
V_180 = V_32 -> V_307 ( V_35 , V_286 ) ;
}
F_13 ( V_32 ) ;
return V_180 ;
}
struct V_34 * F_182 ( struct V_35 * V_35 , struct V_34 * V_286 ,
const struct V_3 * V_4 ,
struct V_201 * V_202 , int V_46 )
{
struct V_54 * V_230 [ V_187 ] ;
struct V_79 * V_80 ;
struct V_238 * V_239 ;
struct V_34 * V_37 , * V_240 ;
T_5 V_28 = V_286 -> V_93 -> V_28 ;
T_4 V_60 = F_129 ( V_137 ) ;
int V_123 , V_179 , V_284 , V_241 = 0 , V_308 = 0 ;
V_37 = NULL ;
V_239 = NULL ;
V_240 = NULL ;
if ( V_202 && V_202 -> V_203 [ V_137 ] ) {
V_284 = 1 ;
V_230 [ 0 ] = F_130 ( V_202 , V_137 , V_4 ) ;
V_179 = F_172 ( V_4 , V_28 , V_230 ,
& V_284 , & V_241 ) ;
if ( V_179 < 0 )
goto V_309;
if ( V_284 ) {
if ( V_241 <= 0 ) {
V_308 = V_284 ;
goto V_310;
}
V_239 = F_174 (
V_230 , V_284 , V_4 ,
V_28 , V_286 ) ;
if ( F_18 ( V_239 ) ) {
F_173 ( V_230 , V_284 ) ;
V_179 = F_161 ( V_239 ) ;
goto V_309;
} else if ( V_239 == NULL ) {
V_241 = 0 ;
V_308 = V_284 ;
goto V_310;
}
F_149 ( & V_239 -> V_7 . V_37 ) ;
V_239 -> V_7 . V_37 . V_46 |= V_311 ;
V_240 = V_239 -> V_240 ;
}
}
if ( V_239 == NULL ) {
if ( ( V_286 -> V_46 & V_312 ) ||
! V_35 -> V_101 . V_130 [ V_137 ] )
goto V_313;
V_80 = F_195 ( V_35 , V_4 , V_28 , V_60 ,
F_193 , V_286 ) ;
if ( V_80 == NULL )
goto V_313;
if ( F_18 ( V_80 ) ) {
V_179 = F_161 ( V_80 ) ;
goto V_309;
}
V_239 = F_31 ( V_80 , struct V_238 , V_80 ) ;
V_284 = V_239 -> V_284 ;
V_241 = V_239 -> V_241 ;
memcpy ( V_230 , V_239 -> V_230 , sizeof( struct V_54 * ) * V_284 ) ;
V_240 = V_239 -> V_240 ;
}
V_37 = & V_239 -> V_7 . V_37 ;
if ( V_240 == NULL && V_241 > 0 ) {
if ( V_35 -> V_101 . V_301 ) {
F_162 ( V_37 ) ;
F_173 ( V_230 , V_308 ) ;
F_175 ( V_35 , V_314 ) ;
return F_194 ( V_35 , V_28 , V_286 ) ;
}
V_179 = - V_228 ;
F_175 ( V_35 , V_314 ) ;
goto error;
}
V_310:
if ( V_284 == 0 )
goto V_313;
if ( ( V_46 & V_315 ) &&
! ( V_230 [ 0 ] -> V_46 & V_316 ) ) {
V_179 = - V_181 ;
goto error;
}
for ( V_123 = 0 ; V_123 < V_284 ; V_123 ++ )
V_230 [ V_123 ] -> V_69 . V_73 = F_21 () ;
if ( V_241 < 0 ) {
F_175 ( V_35 , V_317 ) ;
V_179 = - V_318 ;
goto error;
} else if ( V_241 > 0 ) {
F_162 ( V_286 ) ;
} else {
F_162 ( V_37 ) ;
V_37 = V_286 ;
}
V_319:
F_173 ( V_230 , V_308 ) ;
if ( V_37 && V_37 -> V_101 &&
V_37 -> V_101 -> V_44 . V_220 == V_221 )
V_37 -> V_46 |= V_320 ;
return V_37 ;
V_313:
if ( ! ( V_46 & V_315 ) ) {
V_37 = V_286 ;
goto V_319;
}
V_179 = - V_181 ;
error:
F_162 ( V_37 ) ;
V_309:
F_162 ( V_286 ) ;
F_173 ( V_230 , V_308 ) ;
return F_15 ( V_179 ) ;
}
static inline int
F_196 ( int V_152 , struct V_98 * V_99 , const struct V_3 * V_4 )
{
struct V_40 * V_41 ;
if ( ! V_99 -> V_321 || V_152 < 0 || V_152 >= V_99 -> V_321 -> V_158 )
return 0 ;
V_41 = V_99 -> V_321 -> V_322 [ V_152 ] ;
if ( ! V_41 -> type -> V_323 )
return 0 ;
return V_41 -> type -> V_323 ( V_41 , V_99 , V_4 ) ;
}
static inline int
F_197 ( const struct V_212 * V_219 , const struct V_40 * V_41 ,
unsigned short V_28 )
{
if ( F_198 ( V_41 ) )
return V_219 -> V_229 && ! F_199 ( V_219 , V_41 , V_219 -> V_223 ) ;
return V_41 -> V_45 . V_20 == V_219 -> V_45 . V_20 &&
( V_41 -> V_45 . V_324 == V_219 -> V_45 . V_324 || ! V_219 -> V_45 . V_324 ) &&
( V_41 -> V_44 . V_325 == V_219 -> V_325 || ! V_219 -> V_325 ) &&
V_41 -> V_44 . V_220 == V_219 -> V_220 &&
( V_219 -> V_326 || ( V_219 -> V_327 & ( 1 << V_41 -> V_44 . V_328 ) ) ||
! ( F_200 ( V_219 -> V_45 . V_20 , V_329 ) ) ) &&
! ( V_41 -> V_44 . V_220 != V_267 &&
F_199 ( V_219 , V_41 , V_28 ) ) ;
}
static inline int
F_201 ( const struct V_212 * V_219 , const struct V_330 * V_321 , int V_331 ,
unsigned short V_28 )
{
int V_152 = V_331 ;
if ( V_219 -> V_229 ) {
if ( V_219 -> V_220 == V_267 )
return V_331 ;
} else
V_331 = - 1 ;
for (; V_152 < V_321 -> V_158 ; V_152 ++ ) {
if ( F_197 ( V_219 , V_321 -> V_322 [ V_152 ] , V_28 ) )
return ++ V_152 ;
if ( V_321 -> V_322 [ V_152 ] -> V_44 . V_220 != V_267 ) {
if ( V_331 == - 1 )
V_331 = - 2 - V_152 ;
break;
}
}
return V_331 ;
}
int F_202 ( struct V_98 * V_99 , struct V_3 * V_4 ,
unsigned int V_28 , int V_332 )
{
struct V_31 * V_32 = F_8 ( V_28 ) ;
int V_179 ;
if ( F_9 ( V_32 == NULL ) )
return - V_38 ;
V_32 -> V_333 ( V_99 , V_4 , V_332 ) ;
V_179 = F_203 ( V_99 , & V_4 -> V_193 ) ;
F_13 ( V_32 ) ;
return V_179 ;
}
static inline int F_204 ( const struct V_330 * V_321 , int V_334 , int * V_335 )
{
for (; V_334 < V_321 -> V_158 ; V_334 ++ ) {
if ( V_321 -> V_322 [ V_334 ] -> V_44 . V_220 != V_267 ) {
* V_335 = V_334 ;
return 1 ;
}
}
return 0 ;
}
int F_205 ( struct V_201 * V_202 , int V_60 , struct V_98 * V_99 ,
unsigned short V_28 )
{
struct V_35 * V_35 = F_206 ( V_99 -> V_254 ) ;
struct V_54 * V_81 ;
struct V_54 * V_230 [ V_187 ] ;
int V_231 = 0 ;
int V_210 ;
int V_336 ;
int V_332 ;
struct V_3 V_4 ;
T_4 V_337 ;
int V_338 = - 1 ;
V_332 = V_60 & ~ V_339 ;
V_60 &= V_339 ;
V_337 = F_129 ( V_60 ) ;
if ( F_202 ( V_99 , & V_4 , V_28 , V_332 ) < 0 ) {
F_175 ( V_35 , V_340 ) ;
return 0 ;
}
F_207 ( V_99 , & V_4 , V_28 ) ;
if ( V_99 -> V_321 ) {
int V_123 ;
for ( V_123 = V_99 -> V_321 -> V_158 - 1 ; V_123 >= 0 ; V_123 -- ) {
struct V_40 * V_41 = V_99 -> V_321 -> V_322 [ V_123 ] ;
if ( ! F_7 ( & V_41 -> V_2 , & V_4 , V_28 ) ) {
F_175 ( V_35 , V_341 ) ;
return 0 ;
}
}
}
V_81 = NULL ;
if ( V_202 && V_202 -> V_203 [ V_60 ] ) {
V_81 = F_130 ( V_202 , V_60 , & V_4 ) ;
if ( F_18 ( V_81 ) ) {
F_175 ( V_35 , V_342 ) ;
return 0 ;
}
}
if ( ! V_81 ) {
struct V_79 * V_80 ;
V_80 = F_195 ( V_35 , & V_4 , V_28 , V_337 ,
F_126 , NULL ) ;
if ( F_127 ( V_80 ) )
V_81 = F_128 ( V_80 ) ;
else
V_81 = F_31 ( V_80 , struct V_54 , V_80 ) ;
}
if ( F_18 ( V_81 ) ) {
F_175 ( V_35 , V_342 ) ;
return 0 ;
}
if ( ! V_81 ) {
if ( V_99 -> V_321 && F_204 ( V_99 -> V_321 , 0 , & V_338 ) ) {
F_196 ( V_338 , V_99 , & V_4 ) ;
F_175 ( V_35 , V_343 ) ;
return 0 ;
}
return 1 ;
}
V_81 -> V_69 . V_73 = F_21 () ;
V_230 [ 0 ] = V_81 ;
V_231 ++ ;
#ifdef F_124
if ( V_230 [ 0 ] -> type != V_196 ) {
V_230 [ 1 ] = F_120 ( V_35 , V_196 ,
& V_4 , V_28 ,
V_135 ) ;
if ( V_230 [ 1 ] ) {
if ( F_18 ( V_230 [ 1 ] ) ) {
F_175 ( V_35 , V_342 ) ;
return 0 ;
}
V_230 [ 1 ] -> V_69 . V_73 = F_21 () ;
V_231 ++ ;
}
}
#endif
if ( V_81 -> V_209 == V_285 ) {
struct V_330 * V_321 ;
static struct V_330 V_344 ;
struct V_212 * V_232 [ V_233 ] ;
struct V_212 * V_345 [ V_233 ] ;
struct V_212 * * V_234 = V_232 ;
int V_346 = 0 ;
int V_123 , V_334 ;
if ( ( V_321 = V_99 -> V_321 ) == NULL )
V_321 = & V_344 ;
for ( V_336 = 0 ; V_336 < V_231 ; V_336 ++ ) {
if ( V_230 [ V_336 ] != V_81 &&
V_230 [ V_336 ] -> V_209 != V_285 ) {
F_175 ( V_35 , V_347 ) ;
goto V_323;
}
if ( V_346 + V_230 [ V_336 ] -> V_210 >= V_233 ) {
F_175 ( V_35 , V_348 ) ;
goto V_349;
}
for ( V_123 = 0 ; V_123 < V_230 [ V_336 ] -> V_210 ; V_123 ++ )
V_234 [ V_346 ++ ] = & V_230 [ V_336 ] -> V_211 [ V_123 ] ;
}
V_210 = V_346 ;
if ( V_231 > 1 ) {
F_208 ( V_345 , V_234 , V_210 , V_28 , V_35 ) ;
V_234 = V_345 ;
}
for ( V_123 = V_210 - 1 , V_334 = 0 ; V_123 >= 0 ; V_123 -- ) {
V_334 = F_201 ( V_234 [ V_123 ] , V_321 , V_334 , V_28 ) ;
if ( V_334 < 0 ) {
if ( V_334 < - 1 )
V_338 = - ( 2 + V_334 ) ;
F_175 ( V_35 , V_350 ) ;
goto V_323;
}
}
if ( F_204 ( V_321 , V_334 , & V_338 ) ) {
F_175 ( V_35 , V_350 ) ;
goto V_323;
}
F_173 ( V_230 , V_231 ) ;
return 1 ;
}
F_175 ( V_35 , V_347 ) ;
V_323:
F_196 ( V_338 , V_99 , & V_4 ) ;
V_349:
F_173 ( V_230 , V_231 ) ;
return 0 ;
}
int F_209 ( struct V_98 * V_99 , unsigned short V_28 )
{
struct V_35 * V_35 = F_206 ( V_99 -> V_254 ) ;
struct V_3 V_4 ;
struct V_34 * V_37 ;
int V_351 = 1 ;
if ( F_181 ( V_99 , & V_4 , V_28 ) < 0 ) {
F_175 ( V_35 , V_352 ) ;
return 0 ;
}
F_189 ( V_99 ) ;
V_37 = F_182 ( V_35 , F_180 ( V_99 ) , & V_4 , NULL , 0 ) ;
if ( F_18 ( V_37 ) ) {
V_351 = 0 ;
V_37 = NULL ;
}
F_186 ( V_99 , V_37 ) ;
return V_351 ;
}
static struct V_34 * F_210 ( struct V_34 * V_37 , T_3 V_353 )
{
if ( V_37 -> V_269 < 0 && ! F_148 ( V_37 ) )
return V_37 ;
return NULL ;
}
static int F_148 ( struct V_34 * V_37 )
{
return ! F_211 ( (struct V_238 * ) V_37 ) ;
}
void F_212 ( struct V_34 * V_37 , struct V_253 * V_254 )
{
while ( ( V_37 = V_37 -> V_265 ) && V_37 -> V_101 && V_37 -> V_254 == V_254 ) {
V_37 -> V_254 = F_206 ( V_254 ) -> V_354 ;
F_213 ( V_37 -> V_254 ) ;
F_214 ( V_254 ) ;
}
}
static void F_215 ( struct V_98 * V_99 )
{
}
static struct V_34 * F_216 ( struct V_34 * V_37 )
{
if ( V_37 ) {
if ( V_37 -> V_269 ) {
F_162 ( V_37 ) ;
V_37 = NULL ;
}
}
return V_37 ;
}
void F_217 ( struct V_35 * V_35 )
{
F_218 ( V_35 ) ;
}
static void F_219 ( struct V_35 * V_35 )
{
F_220 ( V_35 ) ;
}
static void F_167 ( struct V_34 * V_37 )
{
do {
struct V_238 * V_239 = (struct V_238 * ) V_37 ;
T_3 V_355 , V_356 ;
V_355 = F_221 ( V_37 -> V_265 ) ;
V_239 -> V_357 = V_355 ;
V_355 = F_222 ( V_37 -> V_101 , V_355 ) ;
V_356 = F_221 ( V_239 -> V_240 ) ;
V_239 -> V_356 = V_356 ;
if ( V_355 > V_356 )
V_355 = V_356 ;
F_223 ( V_37 , V_358 , V_355 ) ;
} while ( ( V_37 = V_37 -> V_57 ) );
}
static int F_211 ( struct V_238 * V_359 )
{
struct V_34 * V_37 = & V_359 -> V_7 . V_37 ;
struct V_238 * V_360 ;
T_3 V_361 ;
if ( ! F_224 ( V_37 -> V_250 , ( (struct V_238 * ) V_37 ) -> V_362 ) ||
( V_37 -> V_254 && ! F_225 ( V_37 -> V_254 ) ) )
return 0 ;
if ( V_37 -> V_46 & V_242 )
return 1 ;
V_360 = NULL ;
do {
struct V_238 * V_239 = (struct V_238 * ) V_37 ;
if ( V_37 -> V_101 -> V_224 . V_225 != V_226 )
return 0 ;
if ( V_239 -> V_268 != V_37 -> V_101 -> V_100 )
return 0 ;
if ( V_239 -> V_284 > 0 &&
V_239 -> V_290 != F_176 ( & V_239 -> V_230 [ 0 ] -> V_100 ) )
return 0 ;
V_361 = F_221 ( V_37 -> V_265 ) ;
if ( V_239 -> V_357 != V_361 ) {
V_360 = V_239 ;
V_239 -> V_357 = V_361 ;
}
if ( ! F_224 ( V_239 -> V_240 , V_239 -> V_363 ) )
return 0 ;
V_361 = F_221 ( V_239 -> V_240 ) ;
if ( V_239 -> V_356 != V_361 ) {
V_360 = V_239 ;
V_239 -> V_356 = V_361 ;
}
V_37 = V_37 -> V_265 ;
} while ( V_37 -> V_101 );
if ( F_156 ( ! V_360 ) )
return 1 ;
V_361 = V_360 -> V_357 ;
for (; ; ) {
V_37 = & V_360 -> V_7 . V_37 ;
V_361 = F_222 ( V_37 -> V_101 , V_361 ) ;
if ( V_361 > V_360 -> V_356 )
V_361 = V_360 -> V_356 ;
F_223 ( V_37 , V_358 , V_361 ) ;
if ( V_360 == V_359 )
break;
V_360 = (struct V_238 * ) V_360 -> V_7 . V_37 . V_57 ;
V_360 -> V_357 = V_361 ;
}
return 1 ;
}
static unsigned int F_226 ( const struct V_34 * V_37 )
{
return F_227 ( V_37 -> V_250 ) ;
}
static unsigned int F_228 ( const struct V_34 * V_37 )
{
unsigned int V_361 = F_229 ( V_37 , V_358 ) ;
return V_361 ? : F_221 ( V_37 -> V_250 ) ;
}
static struct V_364 * F_230 ( const struct V_34 * V_37 ,
struct V_98 * V_99 ,
const void * V_9 )
{
return V_37 -> V_250 -> V_93 -> V_365 ( V_37 , V_99 , V_9 ) ;
}
int F_231 ( struct V_31 * V_32 )
{
struct V_35 * V_35 ;
int V_179 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_189 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_177 ( & V_366 ) ;
if ( F_9 ( V_31 [ V_32 -> V_28 ] != NULL ) )
V_179 = - V_236 ;
else {
struct V_243 * V_243 = V_32 -> V_243 ;
if ( F_156 ( V_243 -> V_367 == NULL ) )
V_243 -> V_367 = V_368 ;
if ( F_156 ( V_243 -> V_369 == NULL ) )
V_243 -> V_369 = F_210 ;
if ( F_156 ( V_243 -> V_370 == NULL ) )
V_243 -> V_370 = F_226 ;
if ( F_156 ( V_243 -> V_361 == NULL ) )
V_243 -> V_361 = F_228 ;
if ( F_156 ( V_243 -> V_371 == NULL ) )
V_243 -> V_371 = F_216 ;
if ( F_156 ( V_243 -> V_372 == NULL ) )
V_243 -> V_372 = F_215 ;
if ( F_156 ( V_243 -> V_365 == NULL ) )
V_243 -> V_365 = F_230 ;
if ( F_156 ( V_32 -> V_373 == NULL ) )
V_32 -> V_373 = F_219 ;
F_232 ( V_31 [ V_32 -> V_28 ] , V_32 ) ;
}
F_179 ( & V_366 ) ;
F_233 () ;
F_234 (net) {
struct V_243 * V_374 ;
switch ( V_32 -> V_28 ) {
case V_29 :
V_374 = & V_35 -> V_101 . V_244 ;
break;
#if F_154 ( V_245 )
case V_30 :
V_374 = & V_35 -> V_101 . V_246 ;
break;
#endif
default:
F_46 () ;
}
* V_374 = * V_32 -> V_243 ;
}
F_235 () ;
return V_179 ;
}
int F_236 ( struct V_31 * V_32 )
{
int V_179 = 0 ;
if ( F_9 ( V_32 == NULL ) )
return - V_189 ;
if ( F_9 ( V_32 -> V_28 >= V_33 ) )
return - V_38 ;
F_177 ( & V_366 ) ;
if ( F_156 ( V_31 [ V_32 -> V_28 ] != NULL ) ) {
if ( F_9 ( V_31 [ V_32 -> V_28 ] != V_32 ) )
V_179 = - V_189 ;
else
F_237 ( V_31 [ V_32 -> V_28 ] ,
NULL ) ;
}
F_179 ( & V_366 ) ;
if ( ! V_179 ) {
struct V_243 * V_243 = V_32 -> V_243 ;
F_238 () ;
V_243 -> V_367 = NULL ;
V_243 -> V_369 = NULL ;
V_243 -> V_371 = NULL ;
V_243 -> V_372 = NULL ;
V_32 -> V_373 = NULL ;
}
return V_179 ;
}
static void T_6 F_239 ( struct V_35 * V_35 )
{
struct V_31 * V_32 ;
F_10 () ;
V_32 = F_11 ( V_31 [ V_29 ] ) ;
if ( V_32 )
V_35 -> V_101 . V_244 = * V_32 -> V_243 ;
#if F_154 ( V_245 )
V_32 = F_11 ( V_31 [ V_30 ] ) ;
if ( V_32 )
V_35 -> V_101 . V_246 = * V_32 -> V_243 ;
#endif
F_12 () ;
}
static int F_240 ( struct V_375 * V_376 , unsigned long V_377 , void * V_378 )
{
struct V_253 * V_254 = F_241 ( V_378 ) ;
switch ( V_377 ) {
case V_379 :
F_217 ( F_206 ( V_254 ) ) ;
}
return V_380 ;
}
static int T_6 F_242 ( struct V_35 * V_35 )
{
int V_381 ;
V_35 -> V_382 . V_383 = F_243 ( struct V_384 ) ;
if ( ! V_35 -> V_382 . V_383 )
return - V_214 ;
V_381 = F_244 ( V_35 ) ;
if ( V_381 < 0 )
F_245 ( V_35 -> V_382 . V_383 ) ;
return V_381 ;
}
static void F_246 ( struct V_35 * V_35 )
{
F_247 ( V_35 ) ;
F_245 ( V_35 -> V_382 . V_383 ) ;
}
static int T_6 F_242 ( struct V_35 * V_35 )
{
return 0 ;
}
static void F_246 ( struct V_35 * V_35 )
{
}
static int T_6 F_248 ( struct V_35 * V_35 )
{
unsigned int V_104 , V_385 ;
int V_60 ;
if ( F_249 ( V_35 , & V_386 ) )
V_368 = F_250 ( L_1 ,
sizeof( struct V_238 ) ,
0 , V_387 | V_388 ,
NULL ) ;
V_104 = 8 - 1 ;
V_385 = ( V_104 + 1 ) * sizeof( struct V_103 ) ;
V_35 -> V_101 . V_127 = F_69 ( V_385 ) ;
if ( ! V_35 -> V_101 . V_127 )
goto V_389;
V_35 -> V_101 . V_102 = V_104 ;
for ( V_60 = 0 ; V_60 < V_141 * 2 ; V_60 ++ ) {
struct V_390 * V_391 ;
V_35 -> V_101 . V_130 [ V_60 ] = 0 ;
F_251 ( & V_35 -> V_101 . V_107 [ V_60 ] ) ;
V_391 = & V_35 -> V_101 . V_105 [ V_60 ] ;
V_391 -> V_108 = F_69 ( V_385 ) ;
if ( ! V_391 -> V_108 )
goto V_392;
V_391 -> V_104 = V_104 ;
}
F_37 ( & V_35 -> V_101 . V_175 ) ;
F_252 ( & V_35 -> V_101 . V_148 , F_79 ) ;
if ( F_249 ( V_35 , & V_386 ) )
F_253 ( & V_393 ) ;
return 0 ;
V_392:
for ( V_60 -- ; V_60 >= 0 ; V_60 -- ) {
struct V_390 * V_391 ;
V_391 = & V_35 -> V_101 . V_105 [ V_60 ] ;
F_72 ( V_391 -> V_108 , V_385 ) ;
}
F_72 ( V_35 -> V_101 . V_127 , V_385 ) ;
V_389:
return - V_214 ;
}
static void F_254 ( struct V_35 * V_35 )
{
unsigned int V_385 ;
int V_60 ;
F_255 ( & V_35 -> V_101 . V_148 ) ;
#ifdef F_124
F_106 ( V_35 , V_195 , false ) ;
#endif
F_106 ( V_35 , V_196 , false ) ;
F_95 ( ! F_109 ( & V_35 -> V_101 . V_175 ) ) ;
for ( V_60 = 0 ; V_60 < V_141 * 2 ; V_60 ++ ) {
struct V_390 * V_391 ;
F_95 ( ! F_65 ( & V_35 -> V_101 . V_107 [ V_60 ] ) ) ;
V_391 = & V_35 -> V_101 . V_105 [ V_60 ] ;
V_385 = ( V_391 -> V_104 + 1 ) * sizeof( struct V_103 ) ;
F_95 ( ! F_65 ( V_391 -> V_108 ) ) ;
F_72 ( V_391 -> V_108 , V_385 ) ;
}
V_385 = ( V_35 -> V_101 . V_102 + 1 ) * sizeof( struct V_103 ) ;
F_95 ( ! F_65 ( V_35 -> V_101 . V_127 ) ) ;
F_72 ( V_35 -> V_101 . V_127 , V_385 ) ;
}
static int T_6 F_256 ( struct V_35 * V_35 )
{
int V_381 ;
V_381 = F_242 ( V_35 ) ;
if ( V_381 < 0 )
goto V_394;
V_381 = F_257 ( V_35 ) ;
if ( V_381 < 0 )
goto V_395;
V_381 = F_248 ( V_35 ) ;
if ( V_381 < 0 )
goto V_396;
F_239 ( V_35 ) ;
V_381 = F_258 ( V_35 ) ;
if ( V_381 < 0 )
goto V_397;
V_381 = F_259 ( V_35 ) ;
if ( V_381 < 0 )
goto V_64;
F_260 ( & V_35 -> V_101 . V_398 ) ;
F_39 ( & V_35 -> V_101 . V_124 ) ;
F_261 ( & V_35 -> V_101 . V_399 ) ;
return 0 ;
V_64:
F_262 ( V_35 ) ;
V_397:
F_254 ( V_35 ) ;
V_396:
F_263 ( V_35 ) ;
V_395:
F_246 ( V_35 ) ;
V_394:
return V_381 ;
}
static void T_7 F_264 ( struct V_35 * V_35 )
{
F_265 ( V_35 ) ;
F_262 ( V_35 ) ;
F_254 ( V_35 ) ;
F_263 ( V_35 ) ;
F_246 ( V_35 ) ;
}
void T_8 F_266 ( void )
{
F_267 ( & V_400 ) ;
F_268 () ;
}
static void F_269 ( struct V_54 * V_55 ,
struct V_401 * V_402 )
{
struct V_176 * V_177 = V_55 -> V_95 ;
struct V_1 * V_2 = & V_55 -> V_117 ;
if ( V_177 )
F_270 ( V_402 , L_2 ,
V_177 -> V_403 , V_177 -> V_404 , V_177 -> V_405 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_270 ( V_402 , L_3 , & V_2 -> V_12 . V_10 ) ;
if ( V_2 -> V_13 != 32 )
F_270 ( V_402 , L_4 ,
V_2 -> V_13 ) ;
F_270 ( V_402 , L_5 , & V_2 -> V_9 . V_10 ) ;
if ( V_2 -> V_11 != 32 )
F_270 ( V_402 , L_6 ,
V_2 -> V_11 ) ;
break;
case V_30 :
F_270 ( V_402 , L_7 , V_2 -> V_12 . V_406 ) ;
if ( V_2 -> V_13 != 128 )
F_270 ( V_402 , L_4 ,
V_2 -> V_13 ) ;
F_270 ( V_402 , L_8 , V_2 -> V_9 . V_406 ) ;
if ( V_2 -> V_11 != 128 )
F_270 ( V_402 , L_6 ,
V_2 -> V_11 ) ;
break;
}
}
void F_271 ( struct V_54 * V_55 , int V_407 , bool V_182 )
{
struct V_401 * V_402 ;
V_402 = F_272 ( L_9 ) ;
if ( V_402 == NULL )
return;
F_273 ( V_182 , V_402 ) ;
F_270 ( V_402 , L_10 , V_407 ) ;
F_269 ( V_55 , V_402 ) ;
F_274 ( V_402 ) ;
}
void F_105 ( struct V_54 * V_55 , int V_407 ,
bool V_182 )
{
struct V_401 * V_402 ;
V_402 = F_272 ( L_11 ) ;
if ( V_402 == NULL )
return;
F_273 ( V_182 , V_402 ) ;
F_270 ( V_402 , L_10 , V_407 ) ;
F_269 ( V_55 , V_402 ) ;
F_274 ( V_402 ) ;
}
static bool F_275 ( const struct V_1 * V_408 ,
const struct V_1 * V_409 )
{
if ( V_408 -> V_20 == V_410 ) {
if ( V_409 -> V_28 == V_408 -> V_28 &&
F_276 ( & V_409 -> V_9 , & V_408 -> V_9 ,
V_408 -> V_28 ) &&
F_276 ( & V_409 -> V_12 , & V_408 -> V_12 ,
V_408 -> V_28 ) &&
V_409 -> V_11 == V_408 -> V_11 &&
V_409 -> V_13 == V_408 -> V_13 ) {
return true ;
}
} else {
if ( memcmp ( V_409 , V_408 , sizeof( * V_409 ) ) == 0 ) {
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
static int F_278 ( const struct V_411 * V_167 , const struct V_212 * V_412 )
{
int V_191 = 0 ;
if ( V_412 -> V_220 == V_167 -> V_220 && V_412 -> V_45 . V_20 == V_167 -> V_20 &&
( V_167 -> V_325 == 0 || V_412 -> V_325 == V_167 -> V_325 ) ) {
switch ( V_412 -> V_220 ) {
case V_221 :
case V_222 :
if ( F_276 ( & V_412 -> V_45 . V_9 , & V_167 -> V_413 ,
V_167 -> V_414 ) &&
F_276 ( & V_412 -> V_12 , & V_167 -> V_415 ,
V_167 -> V_414 ) ) {
V_191 = 1 ;
}
break;
case V_267 :
V_191 = 1 ;
break;
default:
break;
}
}
return V_191 ;
}
static int F_279 ( struct V_54 * V_81 ,
struct V_411 * V_167 , int V_416 )
{
struct V_411 * V_417 ;
int V_123 , V_418 , V_419 = 0 ;
F_70 ( & V_81 -> V_61 ) ;
if ( F_9 ( V_81 -> V_62 . V_63 ) ) {
F_71 ( & V_81 -> V_61 ) ;
return - V_181 ;
}
for ( V_123 = 0 ; V_123 < V_81 -> V_210 ; V_123 ++ ) {
for ( V_418 = 0 , V_417 = V_167 ; V_418 < V_416 ; V_418 ++ , V_417 ++ ) {
if ( ! F_278 ( V_417 , & V_81 -> V_211 [ V_123 ] ) )
continue;
V_419 ++ ;
if ( V_81 -> V_211 [ V_123 ] . V_220 != V_221 &&
V_81 -> V_211 [ V_123 ] . V_220 != V_222 )
continue;
memcpy ( & V_81 -> V_211 [ V_123 ] . V_45 . V_9 , & V_417 -> V_420 ,
sizeof( V_81 -> V_211 [ V_123 ] . V_45 . V_9 ) ) ;
memcpy ( & V_81 -> V_211 [ V_123 ] . V_12 , & V_417 -> V_421 ,
sizeof( V_81 -> V_211 [ V_123 ] . V_12 ) ) ;
V_81 -> V_211 [ V_123 ] . V_223 = V_417 -> V_422 ;
F_53 ( & V_81 -> V_100 ) ;
}
}
F_71 ( & V_81 -> V_61 ) ;
if ( ! V_419 )
return - V_423 ;
return 0 ;
}
static int F_280 ( const struct V_411 * V_167 , int V_416 )
{
int V_123 , V_418 ;
if ( V_416 < 1 || V_416 > V_233 )
return - V_189 ;
for ( V_123 = 0 ; V_123 < V_416 ; V_123 ++ ) {
if ( F_276 ( & V_167 [ V_123 ] . V_413 , & V_167 [ V_123 ] . V_420 ,
V_167 [ V_123 ] . V_414 ) &&
F_276 ( & V_167 [ V_123 ] . V_415 , & V_167 [ V_123 ] . V_421 ,
V_167 [ V_123 ] . V_414 ) )
return - V_189 ;
if ( F_141 ( & V_167 [ V_123 ] . V_420 , V_167 [ V_123 ] . V_422 ) ||
F_141 ( & V_167 [ V_123 ] . V_421 , V_167 [ V_123 ] . V_422 ) )
return - V_189 ;
for ( V_418 = V_123 + 1 ; V_418 < V_416 ; V_418 ++ ) {
if ( ! memcmp ( & V_167 [ V_123 ] . V_413 , & V_167 [ V_418 ] . V_413 ,
sizeof( V_167 [ V_123 ] . V_413 ) ) &&
! memcmp ( & V_167 [ V_123 ] . V_415 , & V_167 [ V_418 ] . V_415 ,
sizeof( V_167 [ V_123 ] . V_415 ) ) &&
V_167 [ V_123 ] . V_20 == V_167 [ V_418 ] . V_20 &&
V_167 [ V_123 ] . V_220 == V_167 [ V_418 ] . V_220 &&
V_167 [ V_123 ] . V_325 == V_167 [ V_418 ] . V_325 &&
V_167 [ V_123 ] . V_414 == V_167 [ V_418 ] . V_414 )
return - V_189 ;
}
}
return 0 ;
}
int V_411 ( const struct V_1 * V_2 , T_4 V_60 , T_4 type ,
struct V_411 * V_167 , int V_416 ,
struct V_424 * V_334 , struct V_35 * V_35 )
{
int V_123 , V_179 , V_425 = 0 , V_426 = 0 ;
struct V_54 * V_81 = NULL ;
struct V_40 * V_41 , * V_427 ;
struct V_40 * V_428 [ V_233 ] ;
struct V_40 * V_429 [ V_233 ] ;
struct V_411 * V_417 ;
if ( ( V_179 = F_280 ( V_167 , V_416 ) ) < 0 )
goto V_64;
if ( ( V_81 = F_277 ( V_2 , V_60 , type , V_35 ) ) == NULL ) {
V_179 = - V_181 ;
goto V_64;
}
for ( V_123 = 0 , V_417 = V_167 ; V_123 < V_416 ; V_123 ++ , V_417 ++ ) {
if ( ( V_41 = F_281 ( V_417 , V_35 ) ) ) {
V_428 [ V_425 ] = V_41 ;
V_425 ++ ;
if ( ( V_427 = F_282 ( V_41 , V_417 ) ) ) {
V_429 [ V_426 ] = V_427 ;
V_426 ++ ;
} else {
V_179 = - V_423 ;
goto V_430;
}
}
}
if ( ( V_179 = F_279 ( V_81 , V_167 , V_416 ) ) < 0 )
goto V_430;
if ( V_425 ) {
F_283 ( V_428 , V_425 ) ;
F_284 ( V_428 , V_425 ) ;
}
F_285 ( V_2 , V_60 , type , V_167 , V_416 , V_334 ) ;
F_28 ( V_81 ) ;
return 0 ;
V_64:
return V_179 ;
V_430:
if ( V_81 )
F_28 ( V_81 ) ;
if ( V_425 )
F_283 ( V_428 , V_425 ) ;
if ( V_426 )
F_284 ( V_429 , V_426 ) ;
return V_179 ;
}
