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
struct V_36 * F_16 ( struct V_37 * V_37 , int V_38 , int V_39 ,
const T_1 * V_15 ,
const T_1 * V_12 ,
int V_31 , T_2 V_40 )
{
const struct V_34 * V_35 ;
struct V_36 * V_41 ;
V_35 = F_10 ( V_31 ) ;
if ( F_11 ( V_35 == NULL ) )
return F_17 ( - V_42 ) ;
V_41 = V_35 -> V_43 ( V_37 , V_38 , V_39 , V_15 , V_12 , V_40 ) ;
F_15 () ;
return V_41 ;
}
static inline struct V_36 * F_18 ( struct V_44 * V_45 ,
int V_38 , int V_39 ,
T_1 * V_46 ,
T_1 * V_47 ,
int V_31 , T_2 V_40 )
{
struct V_37 * V_37 = F_19 ( V_45 ) ;
T_1 * V_15 = & V_45 -> V_48 . V_15 ;
T_1 * V_12 = & V_45 -> V_49 . V_12 ;
struct V_36 * V_41 ;
if ( V_45 -> type -> V_50 & V_51 ) {
V_15 = V_45 -> V_52 ;
V_12 = V_47 ;
}
if ( V_45 -> type -> V_50 & V_53 ) {
V_15 = V_46 ;
V_12 = V_45 -> V_52 ;
}
V_41 = F_16 ( V_37 , V_38 , V_39 , V_15 , V_12 , V_31 , V_40 ) ;
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
struct V_1 * F_32 ( struct V_37 * V_37 , T_3 V_82 )
{
struct V_1 * V_2 ;
V_2 = F_33 ( sizeof( struct V_1 ) , V_82 ) ;
if ( V_2 ) {
F_34 ( & V_2 -> V_83 , V_37 ) ;
F_35 ( & V_2 -> V_65 . V_84 ) ;
F_36 ( & V_2 -> V_85 ) ;
F_36 ( & V_2 -> V_86 ) ;
F_37 ( & V_2 -> V_64 ) ;
F_38 ( & V_2 -> V_3 , 1 ) ;
F_39 ( & V_2 -> V_87 . V_88 ) ;
F_40 ( & V_2 -> V_80 , F_22 ,
( unsigned long ) V_2 ) ;
F_40 ( & V_2 -> V_87 . V_89 , V_90 ,
( unsigned long ) V_2 ) ;
}
return V_2 ;
}
static void F_41 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_42 ( V_92 , struct V_1 , V_93 ) ;
F_43 ( V_2 -> V_94 ) ;
F_44 ( V_2 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_46 ( ! V_2 -> V_65 . V_66 ) ;
if ( F_47 ( & V_2 -> V_80 ) || F_47 ( & V_2 -> V_87 . V_89 ) )
F_48 () ;
F_49 ( & V_2 -> V_93 , F_41 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_65 . V_66 = 1 ;
F_51 ( & V_2 -> V_95 ) ;
if ( F_47 ( & V_2 -> V_87 . V_89 ) )
F_30 ( V_2 ) ;
F_52 ( & V_2 -> V_87 . V_88 ) ;
if ( F_47 ( & V_2 -> V_80 ) )
F_30 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static inline unsigned int F_53 ( struct V_37 * V_37 , T_2 V_68 )
{
return F_54 ( V_68 , V_37 -> V_96 . V_97 ) ;
}
static void F_55 ( struct V_37 * V_37 ,
unsigned short V_31 , int V_63 ,
T_4 * V_98 , T_4 * V_99 )
{
switch ( V_31 ) {
case V_32 :
* V_98 = V_37 -> V_96 . V_100 [ V_63 ] . V_101 ;
* V_99 = V_37 -> V_96 . V_100 [ V_63 ] . V_102 ;
break;
case V_33 :
* V_98 = V_37 -> V_96 . V_100 [ V_63 ] . V_103 ;
* V_99 = V_37 -> V_96 . V_100 [ V_63 ] . V_104 ;
break;
default:
* V_98 = 0 ;
* V_99 = 0 ;
}
}
static struct V_105 * F_56 ( struct V_37 * V_37 ,
const struct V_4 * V_5 ,
unsigned short V_31 , int V_63 )
{
unsigned int V_106 = V_37 -> V_96 . V_100 [ V_63 ] . V_106 ;
unsigned int V_107 ;
T_4 V_98 ;
T_4 V_99 ;
F_55 ( V_37 , V_31 , V_63 , & V_98 , & V_99 ) ;
V_107 = F_57 ( V_5 , V_31 , V_106 , V_98 , V_99 ) ;
if ( V_107 == V_106 + 1 )
return & V_37 -> V_96 . V_108 [ V_63 ] ;
return F_58 ( V_37 -> V_96 . V_100 [ V_63 ] . V_109 ,
F_59 ( & V_37 -> V_96 . V_110 ) ) + V_107 ;
}
static struct V_105 * F_60 ( struct V_37 * V_37 ,
const T_1 * V_12 ,
const T_1 * V_15 ,
unsigned short V_31 , int V_63 )
{
unsigned int V_106 = V_37 -> V_96 . V_100 [ V_63 ] . V_106 ;
unsigned int V_107 ;
T_4 V_98 ;
T_4 V_99 ;
F_55 ( V_37 , V_31 , V_63 , & V_98 , & V_99 ) ;
V_107 = F_61 ( V_12 , V_15 , V_31 , V_106 , V_98 , V_99 ) ;
return F_58 ( V_37 -> V_96 . V_100 [ V_63 ] . V_109 ,
F_59 ( & V_37 -> V_96 . V_110 ) ) + V_107 ;
}
static void F_62 ( struct V_37 * V_37 ,
struct V_105 * V_111 ,
struct V_105 * V_112 ,
unsigned int V_113 ,
int V_63 )
{
struct V_114 * V_115 , * V_116 = NULL ;
struct V_1 * V_117 ;
unsigned int V_118 = 0 ;
T_4 V_98 ;
T_4 V_99 ;
V_119:
F_63 (pol, tmp, list, bydst) {
unsigned int V_120 ;
F_55 ( V_37 , V_117 -> V_31 , V_63 , & V_98 , & V_99 ) ;
V_120 = F_61 ( & V_117 -> V_121 . V_12 , & V_117 -> V_121 . V_15 ,
V_117 -> V_31 , V_113 , V_98 , V_99 ) ;
if ( ! V_116 ) {
F_64 ( & V_117 -> V_85 ) ;
F_65 ( & V_117 -> V_85 , V_112 + V_120 ) ;
V_118 = V_120 ;
} else {
if ( V_120 != V_118 )
continue;
F_64 ( & V_117 -> V_85 ) ;
F_66 ( & V_117 -> V_85 , V_116 ) ;
}
V_116 = & V_117 -> V_85 ;
}
if ( ! F_67 ( V_111 ) ) {
V_116 = NULL ;
goto V_119;
}
}
static void F_68 ( struct V_105 * V_111 ,
struct V_105 * V_122 ,
unsigned int V_113 )
{
struct V_114 * V_115 ;
struct V_1 * V_117 ;
F_63 (pol, tmp, list, byidx) {
unsigned int V_120 ;
V_120 = F_54 ( V_117 -> V_68 , V_113 ) ;
F_69 ( & V_117 -> V_86 , V_122 + V_120 ) ;
}
}
static unsigned long F_70 ( unsigned int V_123 )
{
return ( ( V_123 + 1 ) << 1 ) - 1 ;
}
static void F_71 ( struct V_37 * V_37 , int V_63 )
{
unsigned int V_106 = V_37 -> V_96 . V_100 [ V_63 ] . V_106 ;
unsigned int V_113 = F_70 ( V_106 ) ;
unsigned int V_124 = ( V_113 + 1 ) * sizeof( struct V_105 ) ;
struct V_105 * V_125 = F_72 ( V_124 ) ;
struct V_105 * V_126 ;
int V_127 ;
if ( ! V_125 )
return;
F_73 ( & V_37 -> V_96 . V_110 ) ;
F_74 ( & V_128 ) ;
V_126 = F_75 ( V_37 -> V_96 . V_100 [ V_63 ] . V_109 ,
F_59 ( & V_37 -> V_96 . V_110 ) ) ;
V_126 = F_75 ( V_37 -> V_96 . V_100 [ V_63 ] . V_109 ,
F_59 ( & V_37 -> V_96 . V_110 ) ) ;
for ( V_127 = V_106 ; V_127 >= 0 ; V_127 -- )
F_62 ( V_37 , V_126 + V_127 , V_125 , V_113 , V_63 ) ;
F_76 ( V_37 -> V_96 . V_100 [ V_63 ] . V_109 , V_125 ) ;
V_37 -> V_96 . V_100 [ V_63 ] . V_106 = V_113 ;
F_77 ( & V_128 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
F_79 () ;
F_80 ( V_126 , ( V_106 + 1 ) * sizeof( struct V_105 ) ) ;
}
static void F_81 ( struct V_37 * V_37 , int V_129 )
{
unsigned int V_106 = V_37 -> V_96 . V_97 ;
unsigned int V_113 = F_70 ( V_106 ) ;
unsigned int V_124 = ( V_113 + 1 ) * sizeof( struct V_105 ) ;
struct V_105 * V_130 = V_37 -> V_96 . V_131 ;
struct V_105 * V_132 = F_72 ( V_124 ) ;
int V_127 ;
if ( ! V_132 )
return;
F_73 ( & V_37 -> V_96 . V_110 ) ;
for ( V_127 = V_106 ; V_127 >= 0 ; V_127 -- )
F_68 ( V_130 + V_127 , V_132 , V_113 ) ;
V_37 -> V_96 . V_131 = V_132 ;
V_37 -> V_96 . V_97 = V_113 ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
F_80 ( V_130 , ( V_106 + 1 ) * sizeof( struct V_105 ) ) ;
}
static inline int F_82 ( struct V_37 * V_37 , int V_63 , int * V_129 )
{
unsigned int V_133 = V_37 -> V_96 . V_134 [ V_63 ] ;
unsigned int V_106 = V_37 -> V_96 . V_100 [ V_63 ] . V_106 ;
if ( V_129 )
* V_129 += V_133 ;
if ( ( V_106 + 1 ) < V_135 &&
V_133 > V_106 )
return 1 ;
return 0 ;
}
static inline int F_83 ( struct V_37 * V_37 , int V_129 )
{
unsigned int V_106 = V_37 -> V_96 . V_97 ;
if ( ( V_106 + 1 ) < V_135 &&
V_129 > V_106 )
return 1 ;
return 0 ;
}
void F_84 ( struct V_37 * V_37 , struct V_136 * V_137 )
{
V_137 -> V_138 = V_37 -> V_96 . V_134 [ V_139 ] ;
V_137 -> V_140 = V_37 -> V_96 . V_134 [ V_141 ] ;
V_137 -> V_142 = V_37 -> V_96 . V_134 [ V_143 ] ;
V_137 -> V_144 = V_37 -> V_96 . V_134 [ V_139 + V_145 ] ;
V_137 -> V_146 = V_37 -> V_96 . V_134 [ V_141 + V_145 ] ;
V_137 -> V_147 = V_37 -> V_96 . V_134 [ V_143 + V_145 ] ;
V_137 -> V_148 = V_37 -> V_96 . V_97 ;
V_137 -> V_149 = V_135 ;
}
static void F_85 ( struct V_150 * V_151 )
{
struct V_37 * V_37 = F_42 ( V_151 , struct V_37 , V_96 . V_152 ) ;
int V_63 , V_129 ;
F_86 ( & V_153 ) ;
V_129 = 0 ;
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
if ( F_82 ( V_37 , V_63 , & V_129 ) )
F_71 ( V_37 , V_63 ) ;
}
if ( F_83 ( V_37 , V_129 ) )
F_81 ( V_37 , V_129 ) ;
F_87 ( & V_153 ) ;
}
static void F_88 ( struct V_150 * V_151 )
{
struct V_37 * V_37 = F_42 ( V_151 , struct V_37 ,
V_96 . V_154 . V_151 ) ;
unsigned int V_106 ;
struct V_1 * V_117 ;
struct V_1 * V_2 ;
struct V_105 * V_155 ;
struct V_105 * V_126 ;
struct V_114 * V_156 ;
int V_127 ;
int V_63 ;
unsigned V_157 ;
T_4 V_158 , V_159 , V_160 , V_161 ;
F_86 ( & V_153 ) ;
do {
V_157 = F_89 ( & V_37 -> V_96 . V_154 . V_64 ) ;
V_158 = V_37 -> V_96 . V_154 . V_158 ;
V_159 = V_37 -> V_96 . V_154 . V_159 ;
V_160 = V_37 -> V_96 . V_154 . V_160 ;
V_161 = V_37 -> V_96 . V_154 . V_161 ;
} while ( F_90 ( & V_37 -> V_96 . V_154 . V_64 , V_157 ) );
F_73 ( & V_37 -> V_96 . V_110 ) ;
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
F_91 ( & V_37 -> V_96 . V_108 [ V_63 ] ) ;
V_106 = V_37 -> V_96 . V_100 [ V_63 ] . V_106 ;
V_126 = V_37 -> V_96 . V_100 [ V_63 ] . V_109 ;
for ( V_127 = V_106 ; V_127 >= 0 ; V_127 -- )
F_91 ( V_126 + V_127 ) ;
if ( ( V_63 & V_162 ) == V_141 ) {
V_37 -> V_96 . V_100 [ V_63 ] . V_101 = V_159 ;
V_37 -> V_96 . V_100 [ V_63 ] . V_102 = V_158 ;
V_37 -> V_96 . V_100 [ V_63 ] . V_103 = V_161 ;
V_37 -> V_96 . V_100 [ V_63 ] . V_104 = V_160 ;
} else {
V_37 -> V_96 . V_100 [ V_63 ] . V_101 = V_158 ;
V_37 -> V_96 . V_100 [ V_63 ] . V_102 = V_159 ;
V_37 -> V_96 . V_100 [ V_63 ] . V_103 = V_160 ;
V_37 -> V_96 . V_100 [ V_63 ] . V_104 = V_161 ;
}
}
F_92 (policy, &net->xfrm.policy_all, walk.all) {
if ( F_25 ( V_2 -> V_68 ) >= V_145 ) {
continue;
}
V_156 = NULL ;
V_155 = F_56 ( V_37 , & V_2 -> V_121 ,
V_2 -> V_31 ,
F_25 ( V_2 -> V_68 ) ) ;
F_93 (pol, chain, bydst) {
if ( V_2 -> V_163 >= V_117 -> V_163 )
V_156 = & V_117 -> V_85 ;
else
break;
}
if ( V_156 )
F_94 ( & V_2 -> V_85 , V_156 ) ;
else
F_69 ( & V_2 -> V_85 , V_155 ) ;
}
F_78 ( & V_37 -> V_96 . V_110 ) ;
F_87 ( & V_153 ) ;
}
void F_95 ( struct V_37 * V_37 )
{
F_96 ( & V_37 -> V_96 . V_154 . V_151 ) ;
}
static T_2 F_97 ( struct V_37 * V_37 , int V_63 , T_2 V_68 )
{
static T_2 V_164 ;
for (; ; ) {
struct V_105 * V_111 ;
struct V_1 * V_165 ;
T_2 V_166 ;
int V_167 ;
if ( ! V_68 ) {
V_166 = ( V_164 | V_63 ) ;
V_164 += 8 ;
} else {
V_166 = V_68 ;
V_68 = 0 ;
}
if ( V_166 == 0 )
V_166 = 8 ;
V_111 = V_37 -> V_96 . V_131 + F_53 ( V_37 , V_166 ) ;
V_167 = 0 ;
F_93 (p, list, byidx) {
if ( V_165 -> V_68 == V_166 ) {
V_167 = 1 ;
break;
}
}
if ( ! V_167 )
return V_166 ;
}
}
static inline int F_98 ( struct V_4 * V_168 , struct V_4 * V_169 )
{
T_2 * V_170 = ( T_2 * ) V_168 ;
T_2 * V_171 = ( T_2 * ) V_169 ;
int V_172 = sizeof( struct V_4 ) / sizeof( T_2 ) ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_172 ; V_127 ++ ) {
if ( V_170 [ V_127 ] != V_171 [ V_127 ] )
return 1 ;
}
return 0 ;
}
static void F_99 ( struct V_1 * V_173 ,
struct V_1 * V_174 )
{
struct V_175 * V_176 = & V_173 -> V_87 ;
struct V_177 V_111 ;
if ( F_100 ( & V_176 -> V_88 ) )
return;
F_101 ( & V_111 ) ;
F_73 ( & V_176 -> V_88 . V_64 ) ;
F_102 ( & V_176 -> V_88 , & V_111 ) ;
if ( F_47 ( & V_176 -> V_89 ) )
F_30 ( V_173 ) ;
F_78 ( & V_176 -> V_88 . V_64 ) ;
V_176 = & V_174 -> V_87 ;
F_73 ( & V_176 -> V_88 . V_64 ) ;
F_103 ( & V_111 , & V_176 -> V_88 ) ;
V_176 -> V_178 = V_179 ;
if ( ! F_27 ( & V_176 -> V_89 , V_81 ) )
F_28 ( V_174 ) ;
F_78 ( & V_176 -> V_88 . V_64 ) ;
}
static bool F_104 ( struct V_1 * V_2 ,
struct V_1 * V_117 )
{
T_2 V_40 = V_2 -> V_40 . V_180 & V_2 -> V_40 . V_181 ;
if ( V_2 -> V_40 . V_180 == V_117 -> V_40 . V_180 && V_2 -> V_40 . V_181 == V_117 -> V_40 . V_181 )
return true ;
if ( ( V_40 & V_117 -> V_40 . V_181 ) == V_117 -> V_40 . V_180 &&
V_2 -> V_163 == V_117 -> V_163 )
return true ;
return false ;
}
int F_105 ( int V_63 , struct V_1 * V_2 , int V_182 )
{
struct V_37 * V_37 = V_83 ( V_2 ) ;
struct V_1 * V_117 ;
struct V_1 * V_183 ;
struct V_105 * V_155 ;
struct V_114 * V_156 ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
V_155 = F_56 ( V_37 , & V_2 -> V_121 , V_2 -> V_31 , V_63 ) ;
V_183 = NULL ;
V_156 = NULL ;
F_93 (pol, chain, bydst) {
if ( V_117 -> type == V_2 -> type &&
! F_98 ( & V_117 -> V_121 , & V_2 -> V_121 ) &&
F_104 ( V_2 , V_117 ) &&
F_106 ( V_117 -> V_94 , V_2 -> V_94 ) &&
! F_107 ( V_183 ) ) {
if ( V_182 ) {
F_78 ( & V_37 -> V_96 . V_110 ) ;
return - V_184 ;
}
V_183 = V_117 ;
if ( V_2 -> V_163 > V_117 -> V_163 )
continue;
} else if ( V_2 -> V_163 >= V_117 -> V_163 ) {
V_156 = & V_117 -> V_85 ;
continue;
}
if ( V_183 )
break;
}
if ( V_156 )
F_94 ( & V_2 -> V_85 , V_156 ) ;
else
F_69 ( & V_2 -> V_85 , V_155 ) ;
F_108 ( V_2 , V_63 ) ;
if ( V_2 -> V_31 == V_32 )
F_109 ( V_37 ) ;
else
F_110 ( V_37 ) ;
if ( V_183 ) {
F_99 ( V_183 , V_2 ) ;
F_111 ( V_183 , V_63 ) ;
}
V_2 -> V_68 = V_183 ? V_183 -> V_68 : F_97 ( V_37 , V_63 , V_2 -> V_68 ) ;
F_69 ( & V_2 -> V_86 , V_37 -> V_96 . V_131 + F_53 ( V_37 , V_2 -> V_68 ) ) ;
V_2 -> V_72 . V_73 = F_23 () ;
V_2 -> V_72 . V_76 = 0 ;
if ( ! F_27 ( & V_2 -> V_80 , V_81 + V_56 ) )
F_28 ( V_2 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
if ( V_183 )
F_50 ( V_183 ) ;
else if ( F_82 ( V_37 , V_63 , NULL ) )
F_96 ( & V_37 -> V_96 . V_152 ) ;
return 0 ;
}
struct V_1 * F_112 ( struct V_37 * V_37 , T_2 V_40 , T_4 type ,
int V_63 , struct V_4 * V_5 ,
struct V_185 * V_186 , int V_187 ,
int * V_188 )
{
struct V_1 * V_117 , * V_189 ;
struct V_105 * V_155 ;
* V_188 = 0 ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
V_155 = F_56 ( V_37 , V_5 , V_5 -> V_31 , V_63 ) ;
V_189 = NULL ;
F_93 (pol, chain, bydst) {
if ( V_117 -> type == type &&
( V_40 & V_117 -> V_40 . V_181 ) == V_117 -> V_40 . V_180 &&
! F_98 ( V_5 , & V_117 -> V_121 ) &&
F_106 ( V_186 , V_117 -> V_94 ) ) {
F_28 ( V_117 ) ;
if ( V_187 ) {
* V_188 = F_113 (
V_117 -> V_94 ) ;
if ( * V_188 ) {
F_78 ( & V_37 -> V_96 . V_110 ) ;
return V_117 ;
}
F_111 ( V_117 , V_63 ) ;
}
V_189 = V_117 ;
break;
}
}
F_78 ( & V_37 -> V_96 . V_110 ) ;
if ( V_189 && V_187 )
F_50 ( V_189 ) ;
return V_189 ;
}
struct V_1 * F_114 ( struct V_37 * V_37 , T_2 V_40 , T_4 type ,
int V_63 , T_2 V_49 , int V_187 , int * V_188 )
{
struct V_1 * V_117 , * V_189 ;
struct V_105 * V_155 ;
* V_188 = - V_190 ;
if ( F_25 ( V_49 ) != V_63 )
return NULL ;
* V_188 = 0 ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
V_155 = V_37 -> V_96 . V_131 + F_53 ( V_37 , V_49 ) ;
V_189 = NULL ;
F_93 (pol, chain, byidx) {
if ( V_117 -> type == type && V_117 -> V_68 == V_49 &&
( V_40 & V_117 -> V_40 . V_181 ) == V_117 -> V_40 . V_180 ) {
F_28 ( V_117 ) ;
if ( V_187 ) {
* V_188 = F_113 (
V_117 -> V_94 ) ;
if ( * V_188 ) {
F_78 ( & V_37 -> V_96 . V_110 ) ;
return V_117 ;
}
F_111 ( V_117 , V_63 ) ;
}
V_189 = V_117 ;
break;
}
}
F_78 ( & V_37 -> V_96 . V_110 ) ;
if ( V_189 && V_187 )
F_50 ( V_189 ) ;
return V_189 ;
}
static inline int
F_115 ( struct V_37 * V_37 , T_4 type , bool V_191 )
{
int V_63 , V_188 = 0 ;
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
struct V_1 * V_117 ;
int V_127 ;
F_93 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_117 -> type != type )
continue;
V_188 = F_113 ( V_117 -> V_94 ) ;
if ( V_188 ) {
F_116 ( V_117 , 0 , V_191 ) ;
return V_188 ;
}
}
for ( V_127 = V_37 -> V_96 . V_100 [ V_63 ] . V_106 ; V_127 >= 0 ; V_127 -- ) {
F_93 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_117 -> type != type )
continue;
V_188 = F_113 (
V_117 -> V_94 ) ;
if ( V_188 ) {
F_116 ( V_117 , 0 ,
V_191 ) ;
return V_188 ;
}
}
}
}
return V_188 ;
}
static inline int
F_115 ( struct V_37 * V_37 , T_4 type , bool V_191 )
{
return 0 ;
}
int F_117 ( struct V_37 * V_37 , T_4 type , bool V_191 )
{
int V_63 , V_188 = 0 , V_133 = 0 ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
V_188 = F_115 ( V_37 , type , V_191 ) ;
if ( V_188 )
goto V_67;
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
struct V_1 * V_117 ;
int V_127 ;
V_192:
F_93 (pol,
&net->xfrm.policy_inexact[dir], bydst) {
if ( V_117 -> type != type )
continue;
F_111 ( V_117 , V_63 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
V_133 ++ ;
F_116 ( V_117 , 1 , V_191 ) ;
F_50 ( V_117 ) ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
goto V_192;
}
for ( V_127 = V_37 -> V_96 . V_100 [ V_63 ] . V_106 ; V_127 >= 0 ; V_127 -- ) {
V_193:
F_93 (pol,
net->xfrm.policy_bydst[dir].table + i,
bydst) {
if ( V_117 -> type != type )
continue;
F_111 ( V_117 , V_63 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
V_133 ++ ;
F_116 ( V_117 , 1 , V_191 ) ;
F_50 ( V_117 ) ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
goto V_193;
}
}
}
if ( ! V_133 )
V_188 = - V_194 ;
else
F_118 () ;
V_67:
F_78 ( & V_37 -> V_96 . V_110 ) ;
return V_188 ;
}
int F_119 ( struct V_37 * V_37 , struct F_119 * V_65 ,
int (* F_120)( struct V_1 * , int , int , void * ) ,
void * V_57 )
{
struct V_1 * V_117 ;
struct V_195 * V_45 ;
int error = 0 ;
if ( V_65 -> type >= V_196 &&
V_65 -> type != V_197 )
return - V_198 ;
if ( F_121 ( & V_65 -> V_65 . V_84 ) && V_65 -> V_157 != 0 )
return 0 ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
if ( F_121 ( & V_65 -> V_65 . V_84 ) )
V_45 = F_122 ( & V_37 -> V_96 . V_199 , struct V_195 , V_84 ) ;
else
V_45 = F_122 ( & V_65 -> V_65 . V_84 ,
struct V_195 , V_84 ) ;
F_123 (x, &net->xfrm.policy_all, all) {
if ( V_45 -> V_66 )
continue;
V_117 = F_42 ( V_45 , struct V_1 , V_65 ) ;
if ( V_65 -> type != V_197 &&
V_65 -> type != V_117 -> type )
continue;
error = F_120 ( V_117 , F_25 ( V_117 -> V_68 ) ,
V_65 -> V_157 , V_57 ) ;
if ( error ) {
F_124 ( & V_65 -> V_65 . V_84 , & V_45 -> V_84 ) ;
goto V_67;
}
V_65 -> V_157 ++ ;
}
if ( V_65 -> V_157 == 0 ) {
error = - V_190 ;
goto V_67;
}
F_125 ( & V_65 -> V_65 . V_84 ) ;
V_67:
F_78 ( & V_37 -> V_96 . V_110 ) ;
return error ;
}
void F_126 ( struct F_119 * V_65 , T_4 type )
{
F_35 ( & V_65 -> V_65 . V_84 ) ;
V_65 -> V_65 . V_66 = 1 ;
V_65 -> type = type ;
V_65 -> V_157 = 0 ;
}
void F_127 ( struct F_119 * V_65 , struct V_37 * V_37 )
{
if ( F_121 ( & V_65 -> V_65 . V_84 ) )
return;
F_73 ( & V_37 -> V_96 . V_110 ) ;
F_128 ( & V_65 -> V_65 . V_84 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
}
static int F_129 ( const struct V_1 * V_117 ,
const struct V_6 * V_7 ,
T_4 type , T_5 V_31 , int V_63 )
{
const struct V_4 * V_5 = & V_117 -> V_121 ;
int V_189 = - V_194 ;
bool V_200 ;
if ( V_117 -> V_31 != V_31 ||
( V_7 -> V_201 & V_117 -> V_40 . V_181 ) != V_117 -> V_40 . V_180 ||
V_117 -> type != type )
return V_189 ;
V_200 = F_9 ( V_5 , V_7 , V_31 ) ;
if ( V_200 )
V_189 = F_130 ( V_117 -> V_94 , V_7 -> V_202 ,
V_63 ) ;
return V_189 ;
}
static struct V_1 * F_131 ( struct V_37 * V_37 , T_4 type ,
const struct V_6 * V_7 ,
T_5 V_31 , T_4 V_63 )
{
int V_188 ;
struct V_1 * V_117 , * V_189 ;
const T_1 * V_12 , * V_15 ;
struct V_105 * V_155 ;
unsigned int V_203 ;
T_2 V_163 ;
V_12 = F_132 ( V_7 , V_31 ) ;
V_15 = F_133 ( V_7 , V_31 ) ;
if ( F_11 ( ! V_12 || ! V_15 ) )
return NULL ;
F_13 () ;
V_204:
do {
V_203 = F_134 ( & V_128 ) ;
V_155 = F_60 ( V_37 , V_12 , V_15 , V_31 , V_63 ) ;
} while ( F_135 ( & V_128 , V_203 ) );
V_163 = ~ 0U ;
V_189 = NULL ;
F_136 (pol, chain, bydst) {
V_188 = F_129 ( V_117 , V_7 , type , V_31 , V_63 ) ;
if ( V_188 ) {
if ( V_188 == - V_194 )
continue;
else {
V_189 = F_17 ( V_188 ) ;
goto V_205;
}
} else {
V_189 = V_117 ;
V_163 = V_189 -> V_163 ;
break;
}
}
V_155 = & V_37 -> V_96 . V_108 [ V_63 ] ;
F_136 (pol, chain, bydst) {
if ( ( V_117 -> V_163 >= V_163 ) && V_189 )
break;
V_188 = F_129 ( V_117 , V_7 , type , V_31 , V_63 ) ;
if ( V_188 ) {
if ( V_188 == - V_194 )
continue;
else {
V_189 = F_17 ( V_188 ) ;
goto V_205;
}
} else {
V_189 = V_117 ;
break;
}
}
if ( F_135 ( & V_128 , V_203 ) )
goto V_204;
if ( V_189 && ! F_1 ( V_189 ) )
goto V_204;
V_205:
F_15 () ;
return V_189 ;
}
static struct V_1 *
F_137 ( struct V_37 * V_37 , const struct V_6 * V_7 , T_5 V_31 , T_4 V_63 )
{
#ifdef F_138
struct V_1 * V_117 ;
V_117 = F_131 ( V_37 , V_206 , V_7 , V_31 , V_63 ) ;
if ( V_117 != NULL )
return V_117 ;
#endif
return F_131 ( V_37 , V_207 , V_7 , V_31 , V_63 ) ;
}
static struct V_1 * F_139 ( const struct V_208 * V_209 , int V_63 ,
const struct V_6 * V_7 , T_5 V_31 )
{
struct V_1 * V_117 ;
F_13 () ;
V_210:
V_117 = F_14 ( V_209 -> V_211 [ V_63 ] ) ;
if ( V_117 != NULL ) {
bool V_200 = F_9 ( & V_117 -> V_121 , V_7 , V_31 ) ;
int V_188 = 0 ;
if ( V_200 ) {
if ( ( V_209 -> V_212 & V_117 -> V_40 . V_181 ) != V_117 -> V_40 . V_180 ) {
V_117 = NULL ;
goto V_67;
}
V_188 = F_130 ( V_117 -> V_94 ,
V_7 -> V_202 ,
V_63 ) ;
if ( ! V_188 ) {
if ( ! F_1 ( V_117 ) )
goto V_210;
} else if ( V_188 == - V_194 ) {
V_117 = NULL ;
} else {
V_117 = F_17 ( V_188 ) ;
}
} else
V_117 = NULL ;
}
V_67:
F_15 () ;
return V_117 ;
}
static void F_108 ( struct V_1 * V_117 , int V_63 )
{
struct V_37 * V_37 = V_83 ( V_117 ) ;
F_140 ( & V_117 -> V_65 . V_84 , & V_37 -> V_96 . V_199 ) ;
V_37 -> V_96 . V_134 [ V_63 ] ++ ;
F_28 ( V_117 ) ;
}
static struct V_1 * F_111 ( struct V_1 * V_117 ,
int V_63 )
{
struct V_37 * V_37 = V_83 ( V_117 ) ;
if ( F_121 ( & V_117 -> V_65 . V_84 ) )
return NULL ;
if ( ! F_141 ( & V_117 -> V_85 ) ) {
F_64 ( & V_117 -> V_85 ) ;
F_142 ( & V_117 -> V_86 ) ;
}
F_125 ( & V_117 -> V_65 . V_84 ) ;
V_37 -> V_96 . V_134 [ V_63 ] -- ;
return V_117 ;
}
static void F_143 ( struct V_1 * V_117 , int V_63 )
{
F_108 ( V_117 , V_145 + V_63 ) ;
}
static void F_144 ( struct V_1 * V_117 , int V_63 )
{
F_111 ( V_117 , V_145 + V_63 ) ;
}
int F_31 ( struct V_1 * V_117 , int V_63 )
{
struct V_37 * V_37 = V_83 ( V_117 ) ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
V_117 = F_111 ( V_117 , V_63 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
if ( V_117 ) {
F_50 ( V_117 ) ;
return 0 ;
}
return - V_190 ;
}
int F_145 ( struct V_208 * V_209 , int V_63 , struct V_1 * V_117 )
{
struct V_37 * V_37 = V_83 ( V_117 ) ;
struct V_1 * V_213 ;
#ifdef F_138
if ( V_117 && V_117 -> type != V_207 )
return - V_198 ;
#endif
F_73 ( & V_37 -> V_96 . V_110 ) ;
V_213 = F_75 ( V_209 -> V_211 [ V_63 ] ,
F_59 ( & V_37 -> V_96 . V_110 ) ) ;
if ( V_117 ) {
V_117 -> V_72 . V_73 = F_23 () ;
V_117 -> V_68 = F_97 ( V_37 , V_145 + V_63 , 0 ) ;
F_143 ( V_117 , V_63 ) ;
}
F_76 ( V_209 -> V_211 [ V_63 ] , V_117 ) ;
if ( V_213 ) {
if ( V_117 )
F_99 ( V_213 , V_117 ) ;
F_144 ( V_213 , V_63 ) ;
}
F_78 ( & V_37 -> V_96 . V_110 ) ;
if ( V_213 ) {
F_50 ( V_213 ) ;
}
return 0 ;
}
static struct V_1 * F_146 ( const struct V_1 * V_173 , int V_63 )
{
struct V_1 * V_214 = F_32 ( V_83 ( V_173 ) , V_215 ) ;
struct V_37 * V_37 = V_83 ( V_173 ) ;
if ( V_214 ) {
V_214 -> V_121 = V_173 -> V_121 ;
if ( F_147 ( V_173 -> V_94 ,
& V_214 -> V_94 ) ) {
F_44 ( V_214 ) ;
return NULL ;
}
V_214 -> V_69 = V_173 -> V_69 ;
V_214 -> V_72 = V_173 -> V_72 ;
V_214 -> V_40 = V_173 -> V_40 ;
V_214 -> V_216 = V_173 -> V_216 ;
V_214 -> V_50 = V_173 -> V_50 ;
V_214 -> V_217 = V_173 -> V_217 ;
V_214 -> V_68 = V_173 -> V_68 ;
V_214 -> type = V_173 -> type ;
memcpy ( V_214 -> V_218 , V_173 -> V_218 ,
V_214 -> V_217 * sizeof( struct V_219 ) ) ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
F_143 ( V_214 , V_63 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
F_30 ( V_214 ) ;
}
return V_214 ;
}
int F_148 ( struct V_208 * V_209 , const struct V_208 * V_220 )
{
const struct V_1 * V_165 ;
struct V_1 * V_221 ;
int V_127 , V_189 = 0 ;
F_13 () ;
for ( V_127 = 0 ; V_127 < 2 ; V_127 ++ ) {
V_165 = F_14 ( V_220 -> V_211 [ V_127 ] ) ;
if ( V_165 ) {
V_221 = F_146 ( V_165 , V_127 ) ;
if ( F_11 ( ! V_221 ) ) {
V_189 = - V_222 ;
break;
}
F_76 ( V_209 -> V_211 [ V_127 ] , V_221 ) ;
}
}
F_15 () ;
return V_189 ;
}
static int
F_149 ( struct V_37 * V_37 , int V_39 , T_1 * V_223 ,
T_1 * V_224 , unsigned short V_31 , T_2 V_40 )
{
int V_188 ;
const struct V_34 * V_35 = F_10 ( V_31 ) ;
if ( F_11 ( V_35 == NULL ) )
return - V_198 ;
V_188 = V_35 -> V_225 ( V_37 , V_39 , V_223 , V_224 , V_40 ) ;
F_15 () ;
return V_188 ;
}
static int
F_150 ( struct V_1 * V_2 , const struct V_6 * V_7 ,
struct V_44 * * V_96 , unsigned short V_31 )
{
struct V_37 * V_37 = V_83 ( V_2 ) ;
int V_226 ;
int V_127 , error ;
T_1 V_115 ;
for ( V_226 = 0 , V_127 = 0 ; V_127 < V_2 -> V_217 ; V_127 ++ ) {
struct V_44 * V_45 ;
T_1 * V_223 ;
T_1 * V_224 ;
struct V_219 * V_227 = & V_2 -> V_218 [ V_127 ] ;
V_224 = & V_227 -> V_49 . V_12 ;
V_223 = & V_227 -> V_15 ;
if ( F_151 ( V_223 , V_227 -> V_228 ) ) {
error = F_149 ( V_37 , V_7 -> V_229 ,
& V_115 , V_224 ,
V_227 -> V_228 , 0 ) ;
if ( error )
goto V_205;
V_223 = & V_115 ;
}
V_45 = F_152 ( V_224 , V_223 , V_7 , V_227 , V_2 , & error , V_31 ) ;
if ( V_45 && V_45 -> V_230 . V_231 == V_232 ) {
V_96 [ V_226 ++ ] = V_45 ;
continue;
}
if ( V_45 ) {
error = ( V_45 -> V_230 . V_231 == V_233 ?
- V_198 : - V_234 ) ;
F_153 ( V_45 ) ;
} else if ( error == - V_194 ) {
error = - V_234 ;
}
if ( ! V_227 -> V_235 )
goto V_205;
}
return V_226 ;
V_205:
for ( V_226 -- ; V_226 >= 0 ; V_226 -- )
F_153 ( V_96 [ V_226 ] ) ;
return error ;
}
static int
F_154 ( struct V_1 * * V_236 , int V_237 , const struct V_6 * V_7 ,
struct V_44 * * V_96 , unsigned short V_31 )
{
struct V_44 * V_238 [ V_239 ] ;
struct V_44 * * V_240 = ( V_237 > 1 ) ? V_238 : V_96 ;
int V_241 = 0 ;
int error ;
int V_189 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_237 ; V_127 ++ ) {
if ( V_241 + V_236 [ V_127 ] -> V_217 >= V_239 ) {
error = - V_242 ;
goto V_205;
}
V_189 = F_150 ( V_236 [ V_127 ] , V_7 , & V_240 [ V_241 ] , V_31 ) ;
if ( V_189 < 0 ) {
error = V_189 ;
goto V_205;
} else
V_241 += V_189 ;
}
if ( V_237 > 1 )
F_155 ( V_96 , V_240 , V_241 , V_31 ) ;
return V_241 ;
V_205:
for ( V_241 -- ; V_241 >= 0 ; V_241 -- )
F_153 ( V_240 [ V_241 ] ) ;
return error ;
}
static int F_156 ( const struct V_6 * V_7 , int V_31 )
{
const struct V_34 * V_35 ;
int V_38 = 0 ;
V_35 = F_10 ( V_31 ) ;
V_38 = V_35 ? V_35 -> V_243 ( V_7 ) : 0 ;
F_15 () ;
return V_38 ;
}
static inline struct V_244 * F_157 ( struct V_37 * V_37 , int V_31 )
{
const struct V_34 * V_35 = F_10 ( V_31 ) ;
struct V_245 * V_245 ;
struct V_244 * V_246 ;
if ( ! V_35 )
return F_17 ( - V_198 ) ;
switch ( V_31 ) {
case V_32 :
V_245 = & V_37 -> V_96 . V_247 ;
break;
#if F_158 ( V_248 )
case V_33 :
V_245 = & V_37 -> V_96 . V_249 ;
break;
#endif
default:
F_48 () ;
}
V_246 = F_159 ( V_245 , NULL , 1 , V_250 , 0 ) ;
if ( F_160 ( V_246 ) ) {
struct V_36 * V_41 = & V_246 -> V_10 . V_41 ;
memset ( V_41 + 1 , 0 , sizeof( * V_246 ) - sizeof( * V_41 ) ) ;
} else
V_246 = F_17 ( - V_242 ) ;
F_15 () ;
return V_246 ;
}
static inline int F_161 ( struct V_244 * V_251 , struct V_36 * V_41 ,
int V_252 )
{
const struct V_34 * V_35 =
F_10 ( V_41 -> V_253 -> V_31 ) ;
int V_188 ;
if ( ! V_35 )
return - V_198 ;
V_188 = V_35 -> V_254 ( V_251 , V_41 , V_252 ) ;
F_15 () ;
return V_188 ;
}
static inline int F_162 ( struct V_244 * V_246 , struct V_255 * V_256 ,
const struct V_6 * V_7 )
{
const struct V_34 * V_35 =
F_10 ( V_246 -> V_10 . V_41 . V_253 -> V_31 ) ;
int V_188 ;
if ( ! V_35 )
return - V_198 ;
V_188 = V_35 -> V_257 ( V_246 , V_256 , V_7 ) ;
F_15 () ;
return V_188 ;
}
static struct V_36 * F_163 ( struct V_1 * V_2 ,
struct V_44 * * V_96 , int V_226 ,
const struct V_6 * V_7 ,
struct V_36 * V_41 )
{
struct V_37 * V_37 = V_83 ( V_2 ) ;
unsigned long V_59 = V_81 ;
struct V_255 * V_256 ;
struct V_258 * V_259 ;
struct V_36 * V_260 = NULL ;
struct V_36 * V_261 = NULL ;
int V_127 = 0 ;
int V_188 ;
int V_262 = 0 ;
int V_252 = 0 ;
int V_263 = 0 ;
int V_38 ;
int V_31 = V_2 -> V_121 . V_31 ;
T_1 V_15 , V_12 ;
F_164 ( V_7 , & V_15 , & V_12 , V_31 ) ;
V_38 = F_156 ( V_7 , V_31 ) ;
F_165 ( V_41 ) ;
for (; V_127 < V_226 ; V_127 ++ ) {
struct V_244 * V_246 = F_157 ( V_37 , V_31 ) ;
struct V_36 * V_264 = & V_246 -> V_10 . V_41 ;
V_188 = F_166 ( V_246 ) ;
if ( F_20 ( V_246 ) ) {
F_167 ( V_41 ) ;
goto V_265;
}
if ( ! V_260 )
V_261 = V_264 ;
else
V_260 -> V_266 = V_264 ;
if ( V_96 [ V_127 ] -> V_5 . V_31 == V_267 ) {
V_259 = F_168 ( V_96 [ V_127 ] ,
F_169 ( V_31 ) ) ;
if ( ! V_259 ) {
V_188 = - V_42 ;
F_167 ( V_41 ) ;
goto V_265;
}
} else
V_259 = V_96 [ V_127 ] -> V_259 ;
V_246 -> V_268 = V_41 ;
F_170 ( V_264 , V_41 ) ;
if ( V_96 [ V_127 ] -> V_48 . V_269 != V_270 ) {
V_31 = V_96 [ V_127 ] -> V_48 . V_31 ;
V_41 = F_18 ( V_96 [ V_127 ] , V_38 , V_7 -> V_229 ,
& V_15 , & V_12 , V_31 ,
V_96 [ V_127 ] -> V_48 . V_271 ) ;
V_188 = F_166 ( V_41 ) ;
if ( F_20 ( V_41 ) )
goto V_265;
} else
F_165 ( V_41 ) ;
V_264 -> V_96 = V_96 [ V_127 ] ;
V_246 -> V_272 = V_96 [ V_127 ] -> V_95 ;
V_264 -> V_273 = V_274 ;
V_264 -> V_50 |= V_275 ;
V_264 -> V_276 = V_59 ;
V_264 -> V_277 = V_278 ;
V_264 -> V_279 = V_259 -> V_35 -> V_279 ;
V_264 -> V_60 = V_260 ;
V_260 = V_264 ;
V_262 += V_96 [ V_127 ] -> V_48 . V_262 ;
if ( V_96 [ V_127 ] -> type -> V_50 & V_280 )
V_252 += V_96 [ V_127 ] -> V_48 . V_262 ;
V_263 += V_96 [ V_127 ] -> V_48 . V_263 ;
}
V_260 -> V_266 = V_41 ;
V_261 -> V_251 = V_41 ;
V_188 = - V_281 ;
V_256 = V_41 -> V_256 ;
if ( ! V_256 )
goto V_282;
F_161 ( (struct V_244 * ) V_261 , V_41 , V_252 ) ;
F_171 ( V_260 ) ;
for ( V_260 = V_261 ; V_260 != V_41 ; V_260 = V_260 -> V_266 ) {
struct V_244 * V_246 = (struct V_244 * ) V_260 ;
V_188 = F_162 ( V_246 , V_256 , V_7 ) ;
if ( V_188 )
goto V_282;
V_260 -> V_262 = V_262 ;
V_260 -> V_263 = V_263 ;
V_262 -= V_246 -> V_10 . V_41 . V_96 -> V_48 . V_262 ;
V_263 -= V_246 -> V_10 . V_41 . V_96 -> V_48 . V_263 ;
}
V_67:
return V_261 ;
V_265:
for (; V_127 < V_226 ; V_127 ++ )
F_153 ( V_96 [ V_127 ] ) ;
V_282:
if ( V_261 )
F_172 ( V_261 ) ;
V_261 = F_17 ( V_188 ) ;
goto V_67;
}
static int F_173 ( const struct V_6 * V_7 , T_5 V_31 ,
struct V_1 * * V_236 ,
int * V_283 , int * V_284 )
{
int V_127 ;
if ( * V_283 == 0 || ! V_236 [ 0 ] ) {
* V_283 = 0 ;
* V_284 = 0 ;
return 0 ;
}
if ( F_20 ( V_236 [ 0 ] ) )
return F_166 ( V_236 [ 0 ] ) ;
* V_284 = V_236 [ 0 ] -> V_217 ;
#ifdef F_138
if ( V_236 [ 0 ] && V_236 [ 0 ] -> V_216 == V_285 &&
V_236 [ 0 ] -> type != V_207 ) {
V_236 [ 1 ] = F_131 ( V_83 ( V_236 [ 0 ] ) ,
V_207 ,
V_7 , V_31 ,
V_141 ) ;
if ( V_236 [ 1 ] ) {
if ( F_20 ( V_236 [ 1 ] ) ) {
F_174 ( V_236 , * V_283 ) ;
return F_166 ( V_236 [ 1 ] ) ;
}
( * V_283 ) ++ ;
( * V_284 ) += V_236 [ 1 ] -> V_217 ;
}
}
#endif
for ( V_127 = 0 ; V_127 < * V_283 ; V_127 ++ ) {
if ( V_236 [ V_127 ] -> V_216 != V_285 ) {
* V_284 = - 1 ;
break;
}
}
return 0 ;
}
static void F_175 ( struct V_244 * V_246 , struct V_244 * V_173 )
{
F_176 ( V_286 , V_246 ) ;
if ( V_173 )
F_167 ( & V_173 -> V_10 . V_41 ) ;
}
static void F_177 ( void )
{
struct V_244 * V_173 ;
V_173 = F_178 ( V_286 ) ;
if ( V_173 && ! F_179 ( V_173 ) )
F_175 ( NULL , V_173 ) ;
}
static void F_180 ( struct V_150 * V_151 )
{
F_181 () ;
F_13 () ;
F_177 () ;
F_15 () ;
F_182 () ;
}
void F_118 ( void )
{
struct V_244 * V_173 ;
bool V_167 = 0 ;
int V_287 ;
F_181 () ;
F_13 () ;
F_183 (cpu) {
V_173 = F_184 ( V_286 , V_287 ) ;
if ( V_173 && ! F_179 ( V_173 ) ) {
if ( F_185 () == V_287 ) {
F_177 () ;
continue;
}
V_167 = true ;
break;
}
}
F_15 () ;
F_182 () ;
if ( ! V_167 )
return;
F_186 () ;
F_183 (cpu) {
bool V_288 ;
F_13 () ;
V_173 = F_184 ( V_286 , V_287 ) ;
V_288 = V_173 && ! F_179 ( V_173 ) ;
F_15 () ;
if ( ! V_288 )
continue;
if ( F_187 ( V_287 ) ) {
F_188 ( V_287 , & V_289 [ V_287 ] ) ;
continue;
}
F_13 () ;
V_173 = F_184 ( V_286 , V_287 ) ;
if ( V_173 && ! F_179 ( V_173 ) ) {
F_184 ( V_286 , V_287 ) = NULL ;
F_167 ( & V_173 -> V_10 . V_41 ) ;
}
F_15 () ;
}
F_189 () ;
}
static bool F_190 ( struct V_244 * V_246 ,
struct V_44 * const V_96 [] ,
int V_290 )
{
const struct V_36 * V_41 = & V_246 -> V_10 . V_41 ;
int V_127 ;
if ( V_246 -> V_284 != V_290 )
return false ;
for ( V_127 = 0 ; V_127 < V_290 ; V_127 ++ ) {
if ( ! V_41 || V_41 -> V_96 != V_96 [ V_127 ] )
return false ;
V_41 = V_41 -> V_266 ;
}
return F_179 ( V_246 ) ;
}
static struct V_244 *
F_191 ( struct V_1 * * V_236 , int V_283 ,
const struct V_6 * V_7 , T_5 V_31 ,
struct V_36 * V_291 )
{
struct V_37 * V_37 = V_83 ( V_236 [ 0 ] ) ;
struct V_44 * V_96 [ V_239 ] ;
struct V_244 * V_246 , * V_173 ;
struct V_36 * V_41 ;
int V_188 ;
V_188 = F_154 ( V_236 , V_283 , V_7 , V_96 , V_31 ) ;
if ( V_188 <= 0 ) {
if ( V_188 != 0 && V_188 != - V_234 )
F_192 ( V_37 , V_292 ) ;
return F_17 ( V_188 ) ;
}
V_246 = F_178 ( V_286 ) ;
if ( V_246 &&
V_246 -> V_10 . V_41 . V_256 == V_291 -> V_256 &&
V_246 -> V_283 == V_283 &&
memcmp ( V_246 -> V_236 , V_236 ,
sizeof( struct V_1 * ) * V_283 ) == 0 &&
F_190 ( V_246 , V_96 , V_188 ) ) {
F_165 ( & V_246 -> V_10 . V_41 ) ;
while ( V_188 > 0 )
F_153 ( V_96 [ -- V_188 ] ) ;
return V_246 ;
}
V_173 = V_246 ;
V_41 = F_163 ( V_236 [ 0 ] , V_96 , V_188 , V_7 , V_291 ) ;
if ( F_20 ( V_41 ) ) {
F_192 ( V_37 , V_293 ) ;
return F_193 ( V_41 ) ;
}
V_246 = (struct V_244 * ) V_41 ;
V_246 -> V_284 = V_188 ;
V_246 -> V_283 = V_283 ;
memcpy ( V_246 -> V_236 , V_236 , sizeof( struct V_1 * ) * V_283 ) ;
V_246 -> V_294 = F_194 ( & V_236 [ 0 ] -> V_95 ) ;
F_195 ( & V_246 -> V_10 . V_41 . V_295 , 2 ) ;
F_175 ( V_246 , V_173 ) ;
return V_246 ;
}
static void V_90 ( unsigned long V_296 )
{
struct V_297 * V_298 ;
struct V_208 * V_209 ;
struct V_36 * V_41 ;
struct V_1 * V_117 = (struct V_1 * ) V_296 ;
struct V_37 * V_37 = V_83 ( V_117 ) ;
struct V_175 * V_176 = & V_117 -> V_87 ;
struct V_6 V_7 ;
struct V_177 V_111 ;
F_196 ( & V_176 -> V_88 . V_64 ) ;
V_298 = F_197 ( & V_176 -> V_88 ) ;
if ( ! V_298 ) {
F_198 ( & V_176 -> V_88 . V_64 ) ;
goto V_67;
}
V_41 = F_199 ( V_298 ) ;
V_209 = V_298 -> V_209 ;
F_200 ( V_298 , & V_7 , V_41 -> V_253 -> V_31 ) ;
F_198 ( & V_176 -> V_88 . V_64 ) ;
F_165 ( V_41 -> V_251 ) ;
V_41 = F_201 ( V_37 , V_41 -> V_251 , & V_7 , V_209 , 0 ) ;
if ( F_20 ( V_41 ) )
goto V_299;
if ( V_41 -> V_50 & V_300 ) {
F_167 ( V_41 ) ;
if ( V_176 -> V_178 >= V_301 )
goto V_299;
V_176 -> V_178 = V_176 -> V_178 << 1 ;
if ( ! F_27 ( & V_176 -> V_89 , V_81 + V_176 -> V_178 ) )
F_28 ( V_117 ) ;
goto V_67;
}
F_167 ( V_41 ) ;
F_101 ( & V_111 ) ;
F_196 ( & V_176 -> V_88 . V_64 ) ;
V_176 -> V_178 = 0 ;
F_102 ( & V_176 -> V_88 , & V_111 ) ;
F_198 ( & V_176 -> V_88 . V_64 ) ;
while ( ! F_100 ( & V_111 ) ) {
V_298 = F_202 ( & V_111 ) ;
F_200 ( V_298 , & V_7 , F_199 ( V_298 ) -> V_253 -> V_31 ) ;
F_165 ( F_199 ( V_298 ) -> V_251 ) ;
V_41 = F_201 ( V_37 , F_199 ( V_298 ) -> V_251 , & V_7 , V_298 -> V_209 , 0 ) ;
if ( F_20 ( V_41 ) ) {
F_203 ( V_298 ) ;
continue;
}
F_204 ( V_298 ) ;
F_205 ( V_298 ) ;
F_206 ( V_298 , V_41 ) ;
F_207 ( V_37 , V_298 -> V_209 , V_298 ) ;
}
V_67:
F_30 ( V_117 ) ;
return;
V_299:
V_176 -> V_178 = 0 ;
F_52 ( & V_176 -> V_88 ) ;
F_30 ( V_117 ) ;
}
static int F_208 ( struct V_37 * V_37 , struct V_208 * V_209 , struct V_297 * V_298 )
{
unsigned long V_302 ;
struct V_36 * V_41 = F_199 ( V_298 ) ;
struct V_244 * V_246 = (struct V_244 * ) V_41 ;
struct V_1 * V_117 = V_246 -> V_236 [ 0 ] ;
struct V_175 * V_176 = & V_117 -> V_87 ;
if ( F_11 ( F_209 ( V_209 , V_298 ) ) ) {
F_203 ( V_298 ) ;
return 0 ;
}
if ( V_176 -> V_88 . V_303 > V_304 ) {
F_203 ( V_298 ) ;
return - V_234 ;
}
F_210 ( V_298 ) ;
F_73 ( & V_176 -> V_88 . V_64 ) ;
if ( ! V_176 -> V_178 )
V_176 -> V_178 = V_179 ;
V_302 = V_81 + V_176 -> V_178 ;
if ( F_47 ( & V_176 -> V_89 ) ) {
if ( F_211 ( V_176 -> V_89 . V_305 , V_302 ) )
V_302 = V_176 -> V_89 . V_305 ;
F_30 ( V_117 ) ;
}
F_212 ( & V_176 -> V_88 , V_298 ) ;
if ( ! F_27 ( & V_176 -> V_89 , V_302 ) )
F_28 ( V_117 ) ;
F_78 ( & V_176 -> V_88 . V_64 ) ;
return 0 ;
}
static struct V_244 * F_213 ( struct V_37 * V_37 ,
struct V_306 * V_307 ,
const struct V_6 * V_7 ,
int V_284 ,
T_5 V_31 )
{
int V_188 ;
struct V_255 * V_256 ;
struct V_36 * V_41 ;
struct V_36 * V_264 ;
struct V_244 * V_246 ;
V_246 = F_157 ( V_37 , V_31 ) ;
if ( F_20 ( V_246 ) )
return V_246 ;
if ( ! ( V_307 -> V_50 & V_308 ) ||
V_37 -> V_96 . V_309 ||
V_284 <= 0 )
return V_246 ;
V_41 = V_307 -> V_291 ;
V_264 = & V_246 -> V_10 . V_41 ;
F_165 ( V_41 ) ;
V_246 -> V_268 = V_41 ;
F_170 ( V_264 , V_41 ) ;
V_264 -> V_273 = V_274 ;
V_264 -> V_50 |= V_275 | V_300 ;
V_264 -> V_276 = V_81 ;
V_264 -> V_277 = V_278 ;
V_264 -> V_279 = F_208 ;
F_165 ( V_41 ) ;
V_264 -> V_266 = V_41 ;
V_264 -> V_251 = V_41 ;
F_161 ( (struct V_244 * ) V_264 , V_41 , 0 ) ;
V_188 = - V_281 ;
V_256 = V_41 -> V_256 ;
if ( ! V_256 )
goto V_282;
V_188 = F_162 ( V_246 , V_256 , V_7 ) ;
if ( V_188 )
goto V_282;
V_67:
return V_246 ;
V_282:
F_167 ( V_264 ) ;
V_246 = F_17 ( V_188 ) ;
goto V_67;
}
static struct V_244 *
F_214 ( struct V_37 * V_37 , const struct V_6 * V_7 , T_5 V_31 , T_4 V_63 , struct V_306 * V_307 )
{
struct V_1 * V_236 [ V_196 ] ;
int V_283 = 0 , V_284 = 0 , V_188 ;
struct V_244 * V_246 ;
V_283 = 1 ;
V_236 [ 0 ] = F_137 ( V_37 , V_7 , V_31 , V_63 ) ;
V_188 = F_173 ( V_7 , V_31 , V_236 ,
& V_283 , & V_284 ) ;
if ( V_188 < 0 )
goto V_310;
if ( V_283 == 0 )
return NULL ;
if ( V_284 <= 0 )
goto V_311;
V_246 = F_191 ( V_236 , V_283 , V_7 , V_31 ,
V_307 -> V_291 ) ;
if ( F_20 ( V_246 ) ) {
V_188 = F_166 ( V_246 ) ;
if ( V_188 != - V_234 )
goto error;
goto V_311;
} else if ( V_246 == NULL ) {
V_284 = 0 ;
goto V_311;
}
return V_246 ;
V_311:
V_246 = F_213 ( V_37 , V_307 , V_7 , V_284 , V_31 ) ;
if ( F_20 ( V_246 ) ) {
F_174 ( V_236 , V_283 ) ;
return F_193 ( V_246 ) ;
}
V_246 -> V_283 = V_283 ;
V_246 -> V_284 = V_284 ;
memcpy ( V_246 -> V_236 , V_236 , sizeof( struct V_1 * ) * V_283 ) ;
return V_246 ;
V_310:
F_192 ( V_37 , V_292 ) ;
error:
F_174 ( V_236 , V_283 ) ;
return F_17 ( V_188 ) ;
}
static struct V_36 * F_215 ( struct V_37 * V_37 , T_5 V_31 ,
struct V_36 * V_291 )
{
const struct V_34 * V_35 = F_10 ( V_31 ) ;
struct V_36 * V_189 ;
if ( ! V_35 ) {
F_167 ( V_291 ) ;
return F_17 ( - V_198 ) ;
} else {
V_189 = V_35 -> V_312 ( V_37 , V_291 ) ;
}
F_15 () ;
return V_189 ;
}
struct V_36 * F_201 ( struct V_37 * V_37 , struct V_36 * V_291 ,
const struct V_6 * V_7 ,
const struct V_208 * V_209 , int V_50 )
{
struct V_1 * V_236 [ V_196 ] ;
struct V_244 * V_246 ;
struct V_36 * V_41 , * V_268 ;
T_5 V_31 = V_291 -> V_253 -> V_31 ;
T_4 V_63 = V_141 ;
int V_127 , V_188 , V_283 , V_284 = 0 , V_313 = 0 ;
V_41 = NULL ;
V_246 = NULL ;
V_268 = NULL ;
V_209 = F_216 ( V_209 ) ;
if ( V_209 && V_209 -> V_211 [ V_141 ] ) {
V_283 = 1 ;
V_236 [ 0 ] = F_139 ( V_209 , V_141 , V_7 , V_31 ) ;
V_188 = F_173 ( V_7 , V_31 , V_236 ,
& V_283 , & V_284 ) ;
if ( V_188 < 0 )
goto V_314;
if ( V_283 ) {
if ( V_284 <= 0 ) {
V_313 = V_283 ;
goto V_315;
}
V_246 = F_191 (
V_236 , V_283 , V_7 ,
V_31 , V_291 ) ;
if ( F_20 ( V_246 ) ) {
F_174 ( V_236 , V_283 ) ;
V_188 = F_166 ( V_246 ) ;
goto V_314;
} else if ( V_246 == NULL ) {
V_284 = 0 ;
V_313 = V_283 ;
goto V_315;
}
V_268 = V_246 -> V_268 ;
}
}
if ( V_246 == NULL ) {
struct V_306 V_307 ;
V_307 . V_291 = V_291 ;
V_307 . V_50 = V_50 ;
if ( ( V_291 -> V_50 & V_316 ) ||
! V_37 -> V_96 . V_134 [ V_141 ] )
goto V_317;
V_246 = F_214 ( V_37 , V_7 , V_31 , V_63 , & V_307 ) ;
if ( V_246 == NULL )
goto V_317;
if ( F_20 ( V_246 ) ) {
V_188 = F_166 ( V_246 ) ;
goto V_314;
}
V_283 = V_246 -> V_283 ;
V_284 = V_246 -> V_284 ;
memcpy ( V_236 , V_246 -> V_236 , sizeof( struct V_1 * ) * V_283 ) ;
V_268 = V_246 -> V_268 ;
}
V_41 = & V_246 -> V_10 . V_41 ;
if ( V_268 == NULL && V_284 > 0 ) {
if ( V_37 -> V_96 . V_309 ) {
F_192 ( V_37 , V_318 ) ;
V_188 = - V_319 ;
goto error;
}
V_188 = - V_234 ;
F_192 ( V_37 , V_318 ) ;
goto error;
}
V_315:
if ( V_283 == 0 )
goto V_317;
if ( ( V_50 & V_320 ) &&
! ( V_236 [ 0 ] -> V_50 & V_321 ) ) {
V_188 = - V_190 ;
goto error;
}
for ( V_127 = 0 ; V_127 < V_283 ; V_127 ++ )
V_236 [ V_127 ] -> V_72 . V_76 = F_23 () ;
if ( V_284 < 0 ) {
F_192 ( V_37 , V_322 ) ;
V_188 = - V_323 ;
goto error;
} else if ( V_284 > 0 ) {
F_167 ( V_291 ) ;
} else {
F_167 ( V_41 ) ;
V_41 = V_291 ;
}
V_324:
F_174 ( V_236 , V_313 ) ;
if ( V_41 && V_41 -> V_96 &&
V_41 -> V_96 -> V_48 . V_269 == V_325 )
V_41 -> V_50 |= V_326 ;
return V_41 ;
V_317:
if ( ! ( V_50 & V_320 ) ) {
V_41 = V_291 ;
goto V_324;
}
V_188 = - V_190 ;
error:
F_167 ( V_41 ) ;
V_314:
if ( ! ( V_50 & V_327 ) )
F_167 ( V_291 ) ;
F_174 ( V_236 , V_313 ) ;
return F_17 ( V_188 ) ;
}
struct V_36 * F_217 ( struct V_37 * V_37 , struct V_36 * V_291 ,
const struct V_6 * V_7 ,
const struct V_208 * V_209 , int V_50 )
{
struct V_36 * V_41 = F_201 ( V_37 , V_291 , V_7 , V_209 ,
V_50 | V_308 |
V_327 ) ;
if ( F_20 ( V_41 ) && F_166 ( V_41 ) == - V_319 )
return F_215 ( V_37 , V_291 -> V_253 -> V_31 , V_291 ) ;
return V_41 ;
}
static inline int
F_218 ( int V_166 , struct V_297 * V_298 , const struct V_6 * V_7 )
{
struct V_44 * V_45 ;
if ( ! V_298 -> V_328 || V_166 < 0 || V_166 >= V_298 -> V_328 -> V_172 )
return 0 ;
V_45 = V_298 -> V_328 -> V_329 [ V_166 ] ;
if ( ! V_45 -> type -> V_330 )
return 0 ;
return V_45 -> type -> V_330 ( V_45 , V_298 , V_7 ) ;
}
static inline int
F_219 ( const struct V_219 * V_227 , const struct V_44 * V_45 ,
unsigned short V_31 )
{
if ( F_220 ( V_45 ) )
return V_227 -> V_235 && ! F_221 ( V_227 , V_45 , V_227 -> V_228 ) ;
return V_45 -> V_49 . V_23 == V_227 -> V_49 . V_23 &&
( V_45 -> V_49 . V_331 == V_227 -> V_49 . V_331 || ! V_227 -> V_49 . V_331 ) &&
( V_45 -> V_48 . V_332 == V_227 -> V_332 || ! V_227 -> V_332 ) &&
V_45 -> V_48 . V_269 == V_227 -> V_269 &&
( V_227 -> V_333 || ( V_227 -> V_334 & ( 1 << V_45 -> V_48 . V_335 ) ) ||
! ( F_222 ( V_227 -> V_49 . V_23 , V_336 ) ) ) &&
! ( V_45 -> V_48 . V_269 != V_270 &&
F_221 ( V_227 , V_45 , V_31 ) ) ;
}
static inline int
F_223 ( const struct V_219 * V_227 , const struct V_337 * V_328 , int V_338 ,
unsigned short V_31 )
{
int V_166 = V_338 ;
if ( V_227 -> V_235 ) {
if ( V_227 -> V_269 == V_270 )
return V_338 ;
} else
V_338 = - 1 ;
for (; V_166 < V_328 -> V_172 ; V_166 ++ ) {
if ( F_219 ( V_227 , V_328 -> V_329 [ V_166 ] , V_31 ) )
return ++ V_166 ;
if ( V_328 -> V_329 [ V_166 ] -> V_48 . V_269 != V_270 ) {
if ( V_338 == - 1 )
V_338 = - 2 - V_166 ;
break;
}
}
return V_338 ;
}
int F_224 ( struct V_297 * V_298 , struct V_6 * V_7 ,
unsigned int V_31 , int V_339 )
{
const struct V_34 * V_35 = F_10 ( V_31 ) ;
int V_188 ;
if ( F_11 ( V_35 == NULL ) )
return - V_42 ;
V_35 -> V_340 ( V_298 , V_7 , V_339 ) ;
V_188 = F_225 ( V_298 , & V_7 -> V_202 ) ;
F_15 () ;
return V_188 ;
}
static inline int F_226 ( const struct V_337 * V_328 , int V_341 , int * V_342 )
{
for (; V_341 < V_328 -> V_172 ; V_341 ++ ) {
if ( V_328 -> V_329 [ V_341 ] -> V_48 . V_269 != V_270 ) {
* V_342 = V_341 ;
return 1 ;
}
}
return 0 ;
}
int F_227 ( struct V_208 * V_209 , int V_63 , struct V_297 * V_298 ,
unsigned short V_31 )
{
struct V_37 * V_37 = F_228 ( V_298 -> V_256 ) ;
struct V_1 * V_117 ;
struct V_1 * V_236 [ V_196 ] ;
int V_237 = 0 ;
int V_217 ;
int V_343 ;
int V_339 ;
struct V_6 V_7 ;
int V_344 = - 1 ;
V_339 = V_63 & ~ V_162 ;
V_63 &= V_162 ;
if ( F_224 ( V_298 , & V_7 , V_31 , V_339 ) < 0 ) {
F_192 ( V_37 , V_345 ) ;
return 0 ;
}
F_229 ( V_298 , & V_7 , V_31 ) ;
if ( V_298 -> V_328 ) {
int V_127 ;
for ( V_127 = V_298 -> V_328 -> V_172 - 1 ; V_127 >= 0 ; V_127 -- ) {
struct V_44 * V_45 = V_298 -> V_328 -> V_329 [ V_127 ] ;
if ( ! F_9 ( & V_45 -> V_5 , & V_7 , V_31 ) ) {
F_192 ( V_37 , V_346 ) ;
return 0 ;
}
}
}
V_117 = NULL ;
V_209 = F_230 ( V_209 ) ;
if ( V_209 && V_209 -> V_211 [ V_63 ] ) {
V_117 = F_139 ( V_209 , V_63 , & V_7 , V_31 ) ;
if ( F_20 ( V_117 ) ) {
F_192 ( V_37 , V_347 ) ;
return 0 ;
}
}
if ( ! V_117 )
V_117 = F_137 ( V_37 , & V_7 , V_31 , V_63 ) ;
if ( F_20 ( V_117 ) ) {
F_192 ( V_37 , V_347 ) ;
return 0 ;
}
if ( ! V_117 ) {
if ( V_298 -> V_328 && F_226 ( V_298 -> V_328 , 0 , & V_344 ) ) {
F_218 ( V_344 , V_298 , & V_7 ) ;
F_192 ( V_37 , V_348 ) ;
return 0 ;
}
return 1 ;
}
V_117 -> V_72 . V_76 = F_23 () ;
V_236 [ 0 ] = V_117 ;
V_237 ++ ;
#ifdef F_138
if ( V_236 [ 0 ] -> type != V_207 ) {
V_236 [ 1 ] = F_131 ( V_37 , V_207 ,
& V_7 , V_31 ,
V_139 ) ;
if ( V_236 [ 1 ] ) {
if ( F_20 ( V_236 [ 1 ] ) ) {
F_192 ( V_37 , V_347 ) ;
return 0 ;
}
V_236 [ 1 ] -> V_72 . V_76 = F_23 () ;
V_237 ++ ;
}
}
#endif
if ( V_117 -> V_216 == V_285 ) {
struct V_337 * V_328 ;
static struct V_337 V_349 ;
struct V_219 * V_238 [ V_239 ] ;
struct V_219 * V_350 [ V_239 ] ;
struct V_219 * * V_240 = V_238 ;
int V_351 = 0 ;
int V_127 , V_341 ;
if ( ( V_328 = V_298 -> V_328 ) == NULL )
V_328 = & V_349 ;
for ( V_343 = 0 ; V_343 < V_237 ; V_343 ++ ) {
if ( V_236 [ V_343 ] != V_117 &&
V_236 [ V_343 ] -> V_216 != V_285 ) {
F_192 ( V_37 , V_352 ) ;
goto V_330;
}
if ( V_351 + V_236 [ V_343 ] -> V_217 >= V_239 ) {
F_192 ( V_37 , V_353 ) ;
goto V_354;
}
for ( V_127 = 0 ; V_127 < V_236 [ V_343 ] -> V_217 ; V_127 ++ )
V_240 [ V_351 ++ ] = & V_236 [ V_343 ] -> V_218 [ V_127 ] ;
}
V_217 = V_351 ;
if ( V_237 > 1 ) {
F_231 ( V_350 , V_240 , V_217 , V_31 , V_37 ) ;
V_240 = V_350 ;
}
for ( V_127 = V_217 - 1 , V_341 = 0 ; V_127 >= 0 ; V_127 -- ) {
V_341 = F_223 ( V_240 [ V_127 ] , V_328 , V_341 , V_31 ) ;
if ( V_341 < 0 ) {
if ( V_341 < - 1 )
V_344 = - ( 2 + V_341 ) ;
F_192 ( V_37 , V_355 ) ;
goto V_330;
}
}
if ( F_226 ( V_328 , V_341 , & V_344 ) ) {
F_192 ( V_37 , V_355 ) ;
goto V_330;
}
F_174 ( V_236 , V_237 ) ;
return 1 ;
}
F_192 ( V_37 , V_352 ) ;
V_330:
F_218 ( V_344 , V_298 , & V_7 ) ;
V_354:
F_174 ( V_236 , V_237 ) ;
return 0 ;
}
int F_232 ( struct V_297 * V_298 , unsigned short V_31 )
{
struct V_37 * V_37 = F_228 ( V_298 -> V_256 ) ;
struct V_6 V_7 ;
struct V_36 * V_41 ;
int V_356 = 1 ;
if ( F_200 ( V_298 , & V_7 , V_31 ) < 0 ) {
F_192 ( V_37 , V_357 ) ;
return 0 ;
}
F_210 ( V_298 ) ;
V_41 = F_201 ( V_37 , F_199 ( V_298 ) , & V_7 , NULL , V_308 ) ;
if ( F_20 ( V_41 ) ) {
V_356 = 0 ;
V_41 = NULL ;
}
F_206 ( V_298 , V_41 ) ;
return V_356 ;
}
static struct V_36 * F_233 ( struct V_36 * V_41 , T_2 V_358 )
{
if ( V_41 -> V_273 < 0 && ! F_234 ( V_41 ) )
return V_41 ;
return NULL ;
}
static int F_234 ( struct V_36 * V_41 )
{
return ! F_179 ( (struct V_244 * ) V_41 ) ;
}
void F_235 ( struct V_36 * V_41 , struct V_255 * V_256 )
{
while ( ( V_41 = V_41 -> V_266 ) && V_41 -> V_96 && V_41 -> V_256 == V_256 ) {
V_41 -> V_256 = F_228 ( V_256 ) -> V_359 ;
F_236 ( V_41 -> V_256 ) ;
F_237 ( V_256 ) ;
}
}
static void F_238 ( struct V_297 * V_298 )
{
}
static struct V_36 * F_239 ( struct V_36 * V_41 )
{
if ( V_41 ) {
if ( V_41 -> V_273 ) {
F_167 ( V_41 ) ;
V_41 = NULL ;
}
}
return V_41 ;
}
static void F_171 ( struct V_36 * V_41 )
{
do {
struct V_244 * V_246 = (struct V_244 * ) V_41 ;
T_2 V_360 , V_361 ;
V_360 = F_240 ( V_41 -> V_266 ) ;
V_246 -> V_362 = V_360 ;
V_360 = F_241 ( V_41 -> V_96 , V_360 ) ;
V_361 = F_240 ( V_246 -> V_268 ) ;
V_246 -> V_361 = V_361 ;
if ( V_360 > V_361 )
V_360 = V_361 ;
F_242 ( V_41 , V_363 , V_360 ) ;
} while ( ( V_41 = V_41 -> V_60 ) );
}
static int F_179 ( struct V_244 * V_364 )
{
struct V_36 * V_41 = & V_364 -> V_10 . V_41 ;
struct V_244 * V_365 ;
T_2 V_366 ;
if ( ! F_243 ( V_41 -> V_251 , ( (struct V_244 * ) V_41 ) -> V_367 ) ||
( V_41 -> V_256 && ! F_244 ( V_41 -> V_256 ) ) )
return 0 ;
if ( V_41 -> V_50 & V_300 )
return 1 ;
V_365 = NULL ;
do {
struct V_244 * V_246 = (struct V_244 * ) V_41 ;
if ( V_41 -> V_96 -> V_230 . V_231 != V_232 )
return 0 ;
if ( V_246 -> V_272 != V_41 -> V_96 -> V_95 )
return 0 ;
if ( V_246 -> V_283 > 0 &&
V_246 -> V_294 != F_194 ( & V_246 -> V_236 [ 0 ] -> V_95 ) )
return 0 ;
V_366 = F_240 ( V_41 -> V_266 ) ;
if ( V_246 -> V_362 != V_366 ) {
V_365 = V_246 ;
V_246 -> V_362 = V_366 ;
}
if ( ! F_243 ( V_246 -> V_268 , V_246 -> V_368 ) )
return 0 ;
V_366 = F_240 ( V_246 -> V_268 ) ;
if ( V_246 -> V_361 != V_366 ) {
V_365 = V_246 ;
V_246 -> V_361 = V_366 ;
}
V_41 = V_41 -> V_266 ;
} while ( V_41 -> V_96 );
if ( F_160 ( ! V_365 ) )
return 1 ;
V_366 = V_365 -> V_362 ;
for (; ; ) {
V_41 = & V_365 -> V_10 . V_41 ;
V_366 = F_241 ( V_41 -> V_96 , V_366 ) ;
if ( V_366 > V_365 -> V_361 )
V_366 = V_365 -> V_361 ;
F_242 ( V_41 , V_363 , V_366 ) ;
if ( V_365 == V_364 )
break;
V_365 = (struct V_244 * ) V_365 -> V_10 . V_41 . V_60 ;
V_365 -> V_362 = V_366 ;
}
return 1 ;
}
static unsigned int F_245 ( const struct V_36 * V_41 )
{
return F_246 ( V_41 -> V_251 ) ;
}
static unsigned int F_247 ( const struct V_36 * V_41 )
{
unsigned int V_366 = F_248 ( V_41 , V_363 ) ;
return V_366 ? : F_240 ( V_41 -> V_251 ) ;
}
static const void * F_249 ( const struct V_36 * V_41 ,
const void * V_12 )
{
const struct V_36 * V_251 = V_41 -> V_251 ;
for (; V_41 != V_251 ; V_41 = V_41 -> V_266 ) {
const struct V_44 * V_96 = V_41 -> V_96 ;
if ( V_96 -> V_48 . V_269 == V_270 )
continue;
if ( V_96 -> type -> V_50 & V_53 )
V_12 = V_96 -> V_52 ;
else if ( ! ( V_96 -> type -> V_50 & V_51 ) )
V_12 = & V_96 -> V_49 . V_12 ;
}
return V_12 ;
}
static struct V_369 * F_250 ( const struct V_36 * V_41 ,
struct V_297 * V_298 ,
const void * V_12 )
{
const struct V_36 * V_251 = V_41 -> V_251 ;
if ( ! V_298 )
V_12 = F_249 ( V_41 , V_12 ) ;
return V_251 -> V_253 -> V_370 ( V_251 , V_298 , V_12 ) ;
}
static void F_251 ( const struct V_36 * V_41 , const void * V_12 )
{
const struct V_36 * V_251 = V_41 -> V_251 ;
V_12 = F_249 ( V_41 , V_12 ) ;
V_251 -> V_253 -> V_371 ( V_251 , V_12 ) ;
}
int F_252 ( const struct V_34 * V_35 , int V_31 )
{
int V_188 = 0 ;
if ( F_107 ( V_31 >= F_12 ( V_34 ) ) )
return - V_42 ;
F_196 ( & V_372 ) ;
if ( F_11 ( V_34 [ V_31 ] != NULL ) )
V_188 = - V_184 ;
else {
struct V_245 * V_245 = V_35 -> V_245 ;
if ( F_160 ( V_245 -> V_373 == NULL ) )
V_245 -> V_373 = V_374 ;
if ( F_160 ( V_245 -> V_375 == NULL ) )
V_245 -> V_375 = F_233 ;
if ( F_160 ( V_245 -> V_376 == NULL ) )
V_245 -> V_376 = F_245 ;
if ( F_160 ( V_245 -> V_366 == NULL ) )
V_245 -> V_366 = F_247 ;
if ( F_160 ( V_245 -> V_377 == NULL ) )
V_245 -> V_377 = F_239 ;
if ( F_160 ( V_245 -> V_378 == NULL ) )
V_245 -> V_378 = F_238 ;
if ( F_160 ( V_245 -> V_370 == NULL ) )
V_245 -> V_370 = F_250 ;
if ( F_160 ( ! V_245 -> V_371 ) )
V_245 -> V_371 = F_251 ;
F_76 ( V_34 [ V_31 ] , V_35 ) ;
}
F_198 ( & V_372 ) ;
return V_188 ;
}
void F_253 ( const struct V_34 * V_35 )
{
struct V_245 * V_245 = V_35 -> V_245 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < F_12 ( V_34 ) ; V_127 ++ ) {
if ( V_34 [ V_127 ] != V_35 )
continue;
F_254 ( V_34 [ V_127 ] , NULL ) ;
break;
}
F_79 () ;
V_245 -> V_373 = NULL ;
V_245 -> V_375 = NULL ;
V_245 -> V_377 = NULL ;
V_245 -> V_378 = NULL ;
}
static int T_6 F_255 ( struct V_37 * V_37 )
{
int V_379 ;
V_37 -> V_380 . V_381 = F_256 ( struct V_382 ) ;
if ( ! V_37 -> V_380 . V_381 )
return - V_222 ;
V_379 = F_257 ( V_37 ) ;
if ( V_379 < 0 )
F_258 ( V_37 -> V_380 . V_381 ) ;
return V_379 ;
}
static void F_259 ( struct V_37 * V_37 )
{
F_260 ( V_37 ) ;
F_258 ( V_37 -> V_380 . V_381 ) ;
}
static int T_6 F_255 ( struct V_37 * V_37 )
{
return 0 ;
}
static void F_259 ( struct V_37 * V_37 )
{
}
static int T_6 F_261 ( struct V_37 * V_37 )
{
unsigned int V_106 , V_383 ;
int V_63 ;
if ( F_262 ( V_37 , & V_384 ) )
V_374 = F_263 ( L_1 ,
sizeof( struct V_244 ) ,
0 , V_385 | V_386 ,
NULL ) ;
V_106 = 8 - 1 ;
V_383 = ( V_106 + 1 ) * sizeof( struct V_105 ) ;
V_37 -> V_96 . V_131 = F_72 ( V_383 ) ;
if ( ! V_37 -> V_96 . V_131 )
goto V_387;
V_37 -> V_96 . V_97 = V_106 ;
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
struct V_388 * V_389 ;
V_37 -> V_96 . V_134 [ V_63 ] = 0 ;
V_37 -> V_96 . V_134 [ V_145 + V_63 ] = 0 ;
F_91 ( & V_37 -> V_96 . V_108 [ V_63 ] ) ;
V_389 = & V_37 -> V_96 . V_100 [ V_63 ] ;
V_389 -> V_109 = F_72 ( V_383 ) ;
if ( ! V_389 -> V_109 )
goto V_390;
V_389 -> V_106 = V_106 ;
V_389 -> V_101 = 32 ;
V_389 -> V_102 = 32 ;
V_389 -> V_103 = 128 ;
V_389 -> V_104 = 128 ;
}
V_37 -> V_96 . V_154 . V_158 = 32 ;
V_37 -> V_96 . V_154 . V_159 = 32 ;
V_37 -> V_96 . V_154 . V_160 = 128 ;
V_37 -> V_96 . V_154 . V_161 = 128 ;
F_264 ( & V_37 -> V_96 . V_154 . V_64 ) ;
F_35 ( & V_37 -> V_96 . V_199 ) ;
F_265 ( & V_37 -> V_96 . V_152 , F_85 ) ;
F_265 ( & V_37 -> V_96 . V_154 . V_151 , F_88 ) ;
if ( F_262 ( V_37 , & V_384 ) )
F_266 () ;
return 0 ;
V_390:
for ( V_63 -- ; V_63 >= 0 ; V_63 -- ) {
struct V_388 * V_389 ;
V_389 = & V_37 -> V_96 . V_100 [ V_63 ] ;
F_80 ( V_389 -> V_109 , V_383 ) ;
}
F_80 ( V_37 -> V_96 . V_131 , V_383 ) ;
V_387:
return - V_222 ;
}
static void F_267 ( struct V_37 * V_37 )
{
unsigned int V_383 ;
int V_63 ;
F_268 ( & V_37 -> V_96 . V_152 ) ;
#ifdef F_138
F_117 ( V_37 , V_206 , false ) ;
#endif
F_117 ( V_37 , V_207 , false ) ;
F_107 ( ! F_121 ( & V_37 -> V_96 . V_199 ) ) ;
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
struct V_388 * V_389 ;
F_107 ( ! F_67 ( & V_37 -> V_96 . V_108 [ V_63 ] ) ) ;
V_389 = & V_37 -> V_96 . V_100 [ V_63 ] ;
V_383 = ( V_389 -> V_106 + 1 ) * sizeof( struct V_105 ) ;
F_107 ( ! F_67 ( V_389 -> V_109 ) ) ;
F_80 ( V_389 -> V_109 , V_383 ) ;
}
V_383 = ( V_37 -> V_96 . V_97 + 1 ) * sizeof( struct V_105 ) ;
F_107 ( ! F_67 ( V_37 -> V_96 . V_131 ) ) ;
F_80 ( V_37 -> V_96 . V_131 , V_383 ) ;
}
static int T_6 F_269 ( struct V_37 * V_37 )
{
int V_379 ;
F_270 ( & V_37 -> V_96 . V_391 ) ;
F_270 ( & V_37 -> V_96 . V_110 ) ;
F_271 ( & V_37 -> V_96 . V_392 ) ;
V_379 = F_255 ( V_37 ) ;
if ( V_379 < 0 )
goto V_393;
V_379 = F_272 ( V_37 ) ;
if ( V_379 < 0 )
goto V_394;
V_379 = F_261 ( V_37 ) ;
if ( V_379 < 0 )
goto V_395;
V_379 = F_273 ( V_37 ) ;
if ( V_379 < 0 )
goto V_396;
return 0 ;
V_396:
F_267 ( V_37 ) ;
V_395:
F_274 ( V_37 ) ;
V_394:
F_259 ( V_37 ) ;
V_393:
return V_379 ;
}
static void T_7 F_275 ( struct V_37 * V_37 )
{
F_276 ( V_37 ) ;
F_267 ( V_37 ) ;
F_274 ( V_37 ) ;
F_259 ( V_37 ) ;
}
void T_8 F_277 ( void )
{
int V_127 ;
V_289 = F_278 ( V_397 , sizeof( * V_289 ) ,
V_398 ) ;
F_46 ( ! V_289 ) ;
for ( V_127 = 0 ; V_127 < V_397 ; V_127 ++ )
F_265 ( & V_289 [ V_127 ] , F_180 ) ;
F_279 ( & V_399 ) ;
F_280 ( & V_128 ) ;
F_281 () ;
}
static void F_282 ( struct V_1 * V_58 ,
struct V_400 * V_401 )
{
struct V_185 * V_186 = V_58 -> V_94 ;
struct V_4 * V_5 = & V_58 -> V_121 ;
if ( V_186 )
F_283 ( V_401 , L_2 ,
V_186 -> V_402 , V_186 -> V_403 , V_186 -> V_404 ) ;
switch ( V_5 -> V_31 ) {
case V_32 :
F_283 ( V_401 , L_3 , & V_5 -> V_15 . V_13 ) ;
if ( V_5 -> V_16 != 32 )
F_283 ( V_401 , L_4 ,
V_5 -> V_16 ) ;
F_283 ( V_401 , L_5 , & V_5 -> V_12 . V_13 ) ;
if ( V_5 -> V_14 != 32 )
F_283 ( V_401 , L_6 ,
V_5 -> V_14 ) ;
break;
case V_33 :
F_283 ( V_401 , L_7 , V_5 -> V_15 . V_405 ) ;
if ( V_5 -> V_16 != 128 )
F_283 ( V_401 , L_4 ,
V_5 -> V_16 ) ;
F_283 ( V_401 , L_8 , V_5 -> V_12 . V_405 ) ;
if ( V_5 -> V_14 != 128 )
F_283 ( V_401 , L_6 ,
V_5 -> V_14 ) ;
break;
}
}
void F_284 ( struct V_1 * V_58 , int V_406 , bool V_191 )
{
struct V_400 * V_401 ;
V_401 = F_285 ( L_9 ) ;
if ( V_401 == NULL )
return;
F_286 ( V_191 , V_401 ) ;
F_283 ( V_401 , L_10 , V_406 ) ;
F_282 ( V_58 , V_401 ) ;
F_287 ( V_401 ) ;
}
void F_116 ( struct V_1 * V_58 , int V_406 ,
bool V_191 )
{
struct V_400 * V_401 ;
V_401 = F_285 ( L_11 ) ;
if ( V_401 == NULL )
return;
F_286 ( V_191 , V_401 ) ;
F_283 ( V_401 , L_10 , V_406 ) ;
F_282 ( V_58 , V_401 ) ;
F_287 ( V_401 ) ;
}
static bool F_288 ( const struct V_4 * V_407 ,
const struct V_4 * V_408 )
{
if ( V_407 -> V_23 == V_409 ) {
if ( V_408 -> V_31 == V_407 -> V_31 &&
F_289 ( & V_408 -> V_12 , & V_407 -> V_12 ,
V_407 -> V_31 ) &&
F_289 ( & V_408 -> V_15 , & V_407 -> V_15 ,
V_407 -> V_31 ) &&
V_408 -> V_14 == V_407 -> V_14 &&
V_408 -> V_16 == V_407 -> V_16 ) {
return true ;
}
} else {
if ( memcmp ( V_408 , V_407 , sizeof( * V_408 ) ) == 0 ) {
return true ;
}
}
return false ;
}
static struct V_1 * F_290 ( const struct V_4 * V_5 ,
T_4 V_63 , T_4 type , struct V_37 * V_37 )
{
struct V_1 * V_117 , * V_189 = NULL ;
struct V_105 * V_155 ;
T_2 V_163 = ~ 0U ;
F_73 ( & V_37 -> V_96 . V_110 ) ;
V_155 = F_60 ( V_37 , & V_5 -> V_12 , & V_5 -> V_15 , V_5 -> V_31 , V_63 ) ;
F_93 (pol, chain, bydst) {
if ( F_288 ( V_5 , & V_117 -> V_121 ) &&
V_117 -> type == type ) {
V_189 = V_117 ;
V_163 = V_189 -> V_163 ;
break;
}
}
V_155 = & V_37 -> V_96 . V_108 [ V_63 ] ;
F_93 (pol, chain, bydst) {
if ( ( V_117 -> V_163 >= V_163 ) && V_189 )
break;
if ( F_288 ( V_5 , & V_117 -> V_121 ) &&
V_117 -> type == type ) {
V_189 = V_117 ;
break;
}
}
F_28 ( V_189 ) ;
F_78 ( & V_37 -> V_96 . V_110 ) ;
return V_189 ;
}
static int F_291 ( const struct V_410 * V_181 , const struct V_219 * V_411 )
{
int V_200 = 0 ;
if ( V_411 -> V_269 == V_181 -> V_269 && V_411 -> V_49 . V_23 == V_181 -> V_23 &&
( V_181 -> V_332 == 0 || V_411 -> V_332 == V_181 -> V_332 ) ) {
switch ( V_411 -> V_269 ) {
case V_325 :
case V_412 :
if ( F_289 ( & V_411 -> V_49 . V_12 , & V_181 -> V_413 ,
V_181 -> V_414 ) &&
F_289 ( & V_411 -> V_15 , & V_181 -> V_415 ,
V_181 -> V_414 ) ) {
V_200 = 1 ;
}
break;
case V_270 :
V_200 = 1 ;
break;
default:
break;
}
}
return V_200 ;
}
static int F_292 ( struct V_1 * V_117 ,
struct V_410 * V_181 , int V_416 )
{
struct V_410 * V_417 ;
int V_127 , V_418 , V_419 = 0 ;
F_293 ( & V_117 -> V_64 ) ;
if ( F_11 ( V_117 -> V_65 . V_66 ) ) {
F_294 ( & V_117 -> V_64 ) ;
return - V_190 ;
}
for ( V_127 = 0 ; V_127 < V_117 -> V_217 ; V_127 ++ ) {
for ( V_418 = 0 , V_417 = V_181 ; V_418 < V_416 ; V_418 ++ , V_417 ++ ) {
if ( ! F_291 ( V_417 , & V_117 -> V_218 [ V_127 ] ) )
continue;
V_419 ++ ;
if ( V_117 -> V_218 [ V_127 ] . V_269 != V_325 &&
V_117 -> V_218 [ V_127 ] . V_269 != V_412 )
continue;
memcpy ( & V_117 -> V_218 [ V_127 ] . V_49 . V_12 , & V_417 -> V_420 ,
sizeof( V_117 -> V_218 [ V_127 ] . V_49 . V_12 ) ) ;
memcpy ( & V_117 -> V_218 [ V_127 ] . V_15 , & V_417 -> V_421 ,
sizeof( V_117 -> V_218 [ V_127 ] . V_15 ) ) ;
V_117 -> V_218 [ V_127 ] . V_228 = V_417 -> V_422 ;
F_51 ( & V_117 -> V_95 ) ;
}
}
F_294 ( & V_117 -> V_64 ) ;
if ( ! V_419 )
return - V_423 ;
return 0 ;
}
static int F_295 ( const struct V_410 * V_181 , int V_416 )
{
int V_127 , V_418 ;
if ( V_416 < 1 || V_416 > V_239 )
return - V_198 ;
for ( V_127 = 0 ; V_127 < V_416 ; V_127 ++ ) {
if ( F_151 ( & V_181 [ V_127 ] . V_420 , V_181 [ V_127 ] . V_422 ) ||
F_151 ( & V_181 [ V_127 ] . V_421 , V_181 [ V_127 ] . V_422 ) )
return - V_198 ;
for ( V_418 = V_127 + 1 ; V_418 < V_416 ; V_418 ++ ) {
if ( ! memcmp ( & V_181 [ V_127 ] . V_413 , & V_181 [ V_418 ] . V_413 ,
sizeof( V_181 [ V_127 ] . V_413 ) ) &&
! memcmp ( & V_181 [ V_127 ] . V_415 , & V_181 [ V_418 ] . V_415 ,
sizeof( V_181 [ V_127 ] . V_415 ) ) &&
V_181 [ V_127 ] . V_23 == V_181 [ V_418 ] . V_23 &&
V_181 [ V_127 ] . V_269 == V_181 [ V_418 ] . V_269 &&
V_181 [ V_127 ] . V_332 == V_181 [ V_418 ] . V_332 &&
V_181 [ V_127 ] . V_414 == V_181 [ V_418 ] . V_414 )
return - V_198 ;
}
}
return 0 ;
}
int V_410 ( const struct V_4 * V_5 , T_4 V_63 , T_4 type ,
struct V_410 * V_181 , int V_416 ,
struct V_424 * V_341 , struct V_37 * V_37 ,
struct V_425 * V_426 )
{
int V_127 , V_188 , V_427 = 0 , V_428 = 0 ;
struct V_1 * V_117 = NULL ;
struct V_44 * V_45 , * V_429 ;
struct V_44 * V_430 [ V_239 ] ;
struct V_44 * V_431 [ V_239 ] ;
struct V_410 * V_417 ;
if ( ( V_188 = F_295 ( V_181 , V_416 ) ) < 0 )
goto V_67;
if ( V_63 >= V_145 ) {
V_188 = - V_198 ;
goto V_67;
}
if ( ( V_117 = F_290 ( V_5 , V_63 , type , V_37 ) ) == NULL ) {
V_188 = - V_190 ;
goto V_67;
}
for ( V_127 = 0 , V_417 = V_181 ; V_127 < V_416 ; V_127 ++ , V_417 ++ ) {
if ( ( V_45 = F_296 ( V_417 , V_37 ) ) ) {
V_430 [ V_427 ] = V_45 ;
V_427 ++ ;
V_429 = F_297 ( V_45 , V_417 , V_426 ) ;
if ( V_429 ) {
V_431 [ V_428 ] = V_429 ;
V_428 ++ ;
} else {
V_188 = - V_423 ;
goto V_432;
}
}
}
if ( ( V_188 = F_292 ( V_117 , V_181 , V_416 ) ) < 0 )
goto V_432;
if ( V_427 ) {
F_298 ( V_430 , V_427 ) ;
F_299 ( V_430 , V_427 ) ;
}
F_300 ( V_5 , V_63 , type , V_181 , V_416 , V_341 , V_426 ) ;
F_30 ( V_117 ) ;
return 0 ;
V_67:
return V_188 ;
V_432:
if ( V_117 )
F_30 ( V_117 ) ;
if ( V_427 )
F_298 ( V_430 , V_427 ) ;
if ( V_428 )
F_299 ( V_431 , V_428 ) ;
return V_188 ;
}
