static int F_1 ( const struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
V_3 = F_2 ( V_2 ) ;
V_4 = F_3 ( V_2 ) ;
V_5 = V_3 + 2 * ( F_4 ( V_4 ) - 9 ) ;
if ( V_5 < 0 )
return - 1 ;
else if ( V_5 >= V_6 )
return V_3 + V_6 - 2 ;
return V_5 ;
}
bool F_5 ( struct V_7 * V_8 )
{
return F_6 ( & V_8 -> V_9 ) ||
! F_7 ( & V_8 -> V_10 ) ||
F_8 ( V_8 ) ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
if ( ! F_10 ( & V_8 -> V_9 , V_12 -> V_13 ) )
F_11 ( & V_8 -> V_9 , V_12 -> V_13 ) ;
}
static void F_12 ( struct V_7 * V_8 ,
struct V_11 * V_12 )
{
F_13 ( & V_8 -> V_9 , V_12 -> V_13 ) ;
}
void F_14 ( struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_15 ( & V_15 -> V_17 ) ;
if ( V_16 == 1 ) {
F_16 ( & V_15 -> V_18 ) ;
F_17 ( V_15 , false ) ;
}
}
void F_18 ( struct V_14 * V_15 )
{
F_19 ( V_15 -> V_19 , F_20 ( & V_15 -> V_18 ) ) ;
}
int F_21 ( struct V_14 * V_15 ,
unsigned long V_20 )
{
return F_22 ( V_15 -> V_19 ,
F_20 ( & V_15 -> V_18 ) ,
V_20 ) ;
}
void F_23 ( struct V_14 * V_15 )
{
F_14 ( V_15 ) ;
F_18 ( V_15 ) ;
}
void F_24 ( struct V_14 * V_15 )
{
F_23 ( V_15 ) ;
}
void F_25 ( struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_26 ( & V_15 -> V_17 ) ;
F_27 ( V_16 < 0 ) ;
if ( ! V_16 ) {
F_28 ( & V_15 -> V_18 ) ;
F_29 ( & V_15 -> V_19 ) ;
}
}
void F_30 ( struct V_14 * V_15 )
{
unsigned long V_21 ;
F_31 ( V_15 -> V_22 , V_21 ) ;
F_32 ( V_23 , V_15 ) ;
F_33 ( V_15 -> V_22 , V_21 ) ;
}
void F_34 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
unsigned int V_24 ;
bool V_25 = false ;
F_30 ( V_15 ) ;
F_35 (q, hctx, i) {
if ( V_8 -> V_21 & V_26 )
F_36 ( V_8 -> V_27 ) ;
else
V_25 = true ;
}
if ( V_25 )
F_37 () ;
}
void F_38 ( struct V_14 * V_15 )
{
unsigned long V_21 ;
F_31 ( V_15 -> V_22 , V_21 ) ;
F_39 ( V_23 , V_15 ) ;
F_33 ( V_15 -> V_22 , V_21 ) ;
F_17 ( V_15 , true ) ;
}
void F_40 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
unsigned int V_24 ;
F_35 (q, hctx, i)
if ( F_41 ( V_8 ) )
F_42 ( V_8 -> V_28 , true ) ;
F_29 ( & V_15 -> V_19 ) ;
}
bool F_43 ( struct V_7 * V_8 )
{
return F_44 ( V_8 -> V_28 ) ;
}
static struct V_1 * F_45 ( struct V_29 * V_30 ,
unsigned int V_31 , unsigned int V_32 )
{
struct V_33 * V_28 = F_46 ( V_30 ) ;
struct V_1 * V_2 = V_28 -> V_34 [ V_31 ] ;
V_2 -> V_35 = 0 ;
if ( V_30 -> V_21 & V_36 ) {
V_2 -> V_31 = - 1 ;
V_2 -> V_37 = V_31 ;
} else {
if ( F_47 ( V_30 -> V_8 ) ) {
V_2 -> V_35 = V_38 ;
F_48 ( & V_30 -> V_8 -> V_39 ) ;
}
V_2 -> V_31 = V_31 ;
V_2 -> V_37 = - 1 ;
V_30 -> V_8 -> V_28 -> V_40 [ V_2 -> V_31 ] = V_2 ;
}
F_49 ( & V_2 -> V_41 ) ;
V_2 -> V_15 = V_30 -> V_15 ;
V_2 -> V_42 = V_30 -> V_12 ;
V_2 -> V_43 = V_32 ;
if ( F_50 ( V_30 -> V_15 ) )
V_2 -> V_35 |= V_44 ;
V_2 -> V_45 = - 1 ;
F_51 ( & V_2 -> V_46 ) ;
F_52 ( & V_2 -> V_47 ) ;
V_2 -> V_48 = NULL ;
V_2 -> V_49 = NULL ;
V_2 -> V_50 = V_51 ;
#ifdef F_53
V_2 -> V_52 = NULL ;
F_54 ( V_2 ) ;
V_2 -> V_53 = 0 ;
#endif
V_2 -> V_54 = 0 ;
#if F_55 ( V_55 )
V_2 -> V_56 = 0 ;
#endif
V_2 -> V_57 = NULL ;
V_2 -> V_58 = 0 ;
F_49 ( & V_2 -> V_59 ) ;
V_2 -> V_20 = 0 ;
V_2 -> V_60 = NULL ;
V_2 -> V_61 = NULL ;
V_2 -> V_62 = NULL ;
V_30 -> V_12 -> V_63 [ F_56 ( V_32 ) ] ++ ;
return V_2 ;
}
static struct V_1 * F_57 ( struct V_14 * V_15 ,
struct V_64 * V_64 , unsigned int V_32 ,
struct V_29 * V_30 )
{
struct V_65 * V_66 = V_15 -> V_67 ;
struct V_1 * V_2 ;
unsigned int V_31 ;
struct V_11 * V_68 = NULL ;
F_58 ( V_15 ) ;
V_30 -> V_15 = V_15 ;
if ( F_59 ( ! V_30 -> V_12 ) )
V_30 -> V_12 = V_68 = F_60 ( V_15 ) ;
if ( F_59 ( ! V_30 -> V_8 ) )
V_30 -> V_8 = F_61 ( V_15 , V_30 -> V_12 -> V_45 ) ;
if ( V_32 & V_69 )
V_30 -> V_21 |= V_70 ;
if ( V_66 ) {
V_30 -> V_21 |= V_36 ;
if ( ! F_62 ( V_32 ) && V_66 -> type -> V_71 . V_72 . V_73 )
V_66 -> type -> V_71 . V_72 . V_73 ( V_32 , V_30 ) ;
}
V_31 = F_63 ( V_30 ) ;
if ( V_31 == V_74 ) {
if ( V_68 ) {
F_64 ( V_68 ) ;
V_30 -> V_12 = NULL ;
}
F_65 ( V_15 ) ;
return NULL ;
}
V_2 = F_45 ( V_30 , V_31 , V_32 ) ;
if ( ! F_62 ( V_32 ) ) {
V_2 -> V_75 . V_76 = NULL ;
if ( V_66 && V_66 -> type -> V_71 . V_72 . V_77 ) {
if ( V_66 -> type -> V_78 && F_66 ( V_64 ) )
F_67 ( V_2 , V_64 ) ;
V_66 -> type -> V_71 . V_72 . V_77 ( V_2 , V_64 ) ;
V_2 -> V_35 |= V_79 ;
}
}
V_30 -> V_8 -> V_80 ++ ;
return V_2 ;
}
struct V_1 * F_68 ( struct V_14 * V_15 , unsigned int V_32 ,
unsigned int V_21 )
{
struct V_29 V_81 = { . V_21 = V_21 } ;
struct V_1 * V_2 ;
int V_82 ;
V_82 = F_69 ( V_15 , V_21 & V_70 ) ;
if ( V_82 )
return F_70 ( V_82 ) ;
V_2 = F_57 ( V_15 , NULL , V_32 , & V_81 ) ;
F_65 ( V_15 ) ;
if ( ! V_2 )
return F_70 ( - V_83 ) ;
F_64 ( V_81 . V_12 ) ;
V_2 -> V_84 = 0 ;
V_2 -> V_85 = ( V_86 ) - 1 ;
V_2 -> V_64 = V_2 -> V_87 = NULL ;
return V_2 ;
}
struct V_1 * F_71 ( struct V_14 * V_15 ,
unsigned int V_32 , unsigned int V_21 , unsigned int V_88 )
{
struct V_29 V_81 = { . V_21 = V_21 } ;
struct V_1 * V_2 ;
unsigned int V_45 ;
int V_82 ;
if ( F_27 ( ! ( V_21 & V_70 ) ) )
return F_70 ( - V_89 ) ;
if ( V_88 >= V_15 -> V_90 )
return F_70 ( - V_91 ) ;
V_82 = F_69 ( V_15 , true ) ;
if ( V_82 )
return F_70 ( V_82 ) ;
V_81 . V_8 = V_15 -> V_92 [ V_88 ] ;
if ( ! F_41 ( V_81 . V_8 ) ) {
F_65 ( V_15 ) ;
return F_70 ( - V_93 ) ;
}
V_45 = F_72 ( V_81 . V_8 -> V_94 ) ;
V_81 . V_12 = F_73 ( V_15 , V_45 ) ;
V_2 = F_57 ( V_15 , NULL , V_32 , & V_81 ) ;
F_65 ( V_15 ) ;
if ( ! V_2 )
return F_70 ( - V_83 ) ;
return V_2 ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_65 * V_66 = V_15 -> V_67 ;
struct V_11 * V_12 = V_2 -> V_42 ;
struct V_7 * V_8 = F_61 ( V_15 , V_12 -> V_45 ) ;
const int V_95 = V_2 -> V_37 ;
if ( V_2 -> V_35 & V_79 ) {
if ( V_66 && V_66 -> type -> V_71 . V_72 . V_96 )
V_66 -> type -> V_71 . V_72 . V_96 ( V_2 ) ;
if ( V_2 -> V_75 . V_76 ) {
F_75 ( V_2 -> V_75 . V_76 -> V_97 ) ;
V_2 -> V_75 . V_76 = NULL ;
}
}
V_12 -> V_98 [ F_76 ( V_2 ) ] ++ ;
if ( V_2 -> V_35 & V_38 )
F_77 ( & V_8 -> V_39 ) ;
F_78 ( V_15 -> V_99 , & V_2 -> V_100 ) ;
F_79 ( V_101 , & V_2 -> V_102 ) ;
F_79 ( V_103 , & V_2 -> V_102 ) ;
if ( V_2 -> V_31 != - 1 )
F_80 ( V_8 , V_8 -> V_28 , V_12 , V_2 -> V_31 ) ;
if ( V_95 != - 1 )
F_80 ( V_8 , V_8 -> V_104 , V_12 , V_95 ) ;
F_81 ( V_8 ) ;
F_65 ( V_15 ) ;
}
inline void F_82 ( struct V_1 * V_2 , T_1 error )
{
F_83 ( V_2 ) ;
if ( V_2 -> V_60 ) {
F_78 ( V_2 -> V_15 -> V_99 , & V_2 -> V_100 ) ;
V_2 -> V_60 ( V_2 , error ) ;
} else {
if ( F_84 ( F_85 ( V_2 ) ) )
F_74 ( V_2 -> V_62 ) ;
F_74 ( V_2 ) ;
}
}
void F_86 ( struct V_1 * V_2 , T_1 error )
{
if ( F_87 ( V_2 , error , F_3 ( V_2 ) ) )
F_88 () ;
F_82 ( V_2 , error ) ;
}
static void F_89 ( void * V_30 )
{
struct V_1 * V_2 = V_30 ;
V_2 -> V_15 -> V_105 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_42 ;
bool V_106 = false ;
int V_45 ;
if ( V_2 -> V_37 != - 1 )
F_91 ( V_2 ) ;
if ( V_2 -> V_35 & V_107 ) {
F_92 ( V_2 -> V_15 ) ;
F_93 ( V_2 ) ;
}
if ( ! F_94 ( V_108 , & V_2 -> V_15 -> V_109 ) ) {
V_2 -> V_15 -> V_105 ( V_2 ) ;
return;
}
V_45 = F_95 () ;
if ( ! F_94 ( V_110 , & V_2 -> V_15 -> V_109 ) )
V_106 = F_96 ( V_45 , V_12 -> V_45 ) ;
if ( V_45 != V_12 -> V_45 && ! V_106 && F_97 ( V_12 -> V_45 ) ) {
V_2 -> V_111 . V_112 = F_89 ;
V_2 -> V_111 . V_113 = V_2 ;
V_2 -> V_111 . V_21 = 0 ;
F_98 ( V_12 -> V_45 , & V_2 -> V_111 ) ;
} else {
V_2 -> V_15 -> V_105 ( V_2 ) ;
}
F_99 () ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( F_84 ( F_101 ( V_15 ) ) )
return;
if ( ! F_102 ( V_2 ) )
F_90 ( V_2 ) ;
}
int F_103 ( struct V_1 * V_2 )
{
return F_94 ( V_101 , & V_2 -> V_102 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_105 ( V_2 ) ;
F_106 ( V_15 , V_2 ) ;
if ( F_94 ( V_114 , & V_15 -> V_109 ) ) {
F_107 ( & V_2 -> V_100 , F_108 ( V_2 ) ) ;
V_2 -> V_35 |= V_107 ;
F_109 ( V_15 -> V_99 , & V_2 -> V_100 ) ;
}
F_110 ( V_2 ) ;
F_111 () ;
if ( ! F_94 ( V_101 , & V_2 -> V_102 ) )
F_112 ( V_101 , & V_2 -> V_102 ) ;
if ( F_94 ( V_115 , & V_2 -> V_102 ) )
F_79 ( V_115 , & V_2 -> V_102 ) ;
if ( V_15 -> V_116 && F_3 ( V_2 ) ) {
V_2 -> V_54 ++ ;
}
}
static void F_113 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_114 ( V_15 , V_2 ) ;
F_115 ( V_15 -> V_99 , & V_2 -> V_100 ) ;
F_116 ( V_2 ) ;
if ( F_117 ( V_101 , & V_2 -> V_102 ) ) {
if ( V_15 -> V_116 && F_3 ( V_2 ) )
V_2 -> V_54 -- ;
}
}
void F_118 ( struct V_1 * V_2 , bool V_117 )
{
F_113 ( V_2 ) ;
F_119 ( F_120 ( V_2 ) ) ;
F_121 ( V_2 , true , V_117 ) ;
}
static void F_122 ( struct V_118 * V_119 )
{
struct V_14 * V_15 =
F_123 ( V_119 , struct V_14 , V_120 . V_119 ) ;
F_124 ( V_121 ) ;
struct V_1 * V_2 , * V_122 ;
unsigned long V_21 ;
F_31 ( & V_15 -> V_123 , V_21 ) ;
F_125 ( & V_15 -> V_124 , & V_121 ) ;
F_33 ( & V_15 -> V_123 , V_21 ) ;
F_126 (rq, next, &rq_list, queuelist) {
if ( ! ( V_2 -> V_35 & V_125 ) )
continue;
V_2 -> V_35 &= ~ V_125 ;
F_127 ( & V_2 -> V_41 ) ;
F_128 ( V_2 , true , false , false , true ) ;
}
while ( ! F_129 ( & V_121 ) ) {
V_2 = F_130 ( V_121 . V_122 , struct V_1 , V_41 ) ;
F_127 ( & V_2 -> V_41 ) ;
F_128 ( V_2 , false , false , false , true ) ;
}
F_17 ( V_15 , false ) ;
}
void F_121 ( struct V_1 * V_2 , bool V_126 ,
bool V_117 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_21 ;
F_119 ( V_2 -> V_35 & V_125 ) ;
F_31 ( & V_15 -> V_123 , V_21 ) ;
if ( V_126 ) {
V_2 -> V_35 |= V_125 ;
F_131 ( & V_2 -> V_41 , & V_15 -> V_124 ) ;
} else {
F_132 ( & V_2 -> V_41 , & V_15 -> V_124 ) ;
}
F_33 ( & V_15 -> V_123 , V_21 ) ;
if ( V_117 )
F_133 ( V_15 ) ;
}
void F_133 ( struct V_14 * V_15 )
{
F_134 ( & V_15 -> V_120 , 0 ) ;
}
void F_135 ( struct V_14 * V_15 ,
unsigned long V_127 )
{
F_136 ( V_128 , & V_15 -> V_120 ,
F_137 ( V_127 ) ) ;
}
struct V_1 * F_138 ( struct V_33 * V_28 , unsigned int V_31 )
{
if ( V_31 < V_28 -> V_129 ) {
F_139 ( V_28 -> V_40 [ V_31 ] ) ;
return V_28 -> V_40 [ V_31 ] ;
}
return NULL ;
}
void F_140 ( struct V_1 * V_130 , bool V_131 )
{
const struct V_132 * V_71 = V_130 -> V_15 -> V_133 ;
enum V_134 V_82 = V_135 ;
if ( ! F_94 ( V_101 , & V_130 -> V_102 ) )
return;
if ( V_71 -> V_20 )
V_82 = V_71 -> V_20 ( V_130 , V_131 ) ;
switch ( V_82 ) {
case V_136 :
F_90 ( V_130 ) ;
break;
case V_135 :
F_110 ( V_130 ) ;
F_141 ( V_130 ) ;
break;
case V_137 :
break;
default:
F_142 ( V_138 L_1 , V_82 ) ;
break;
}
}
static void F_143 ( struct V_7 * V_8 ,
struct V_1 * V_2 , void * V_139 , bool V_131 )
{
struct V_140 * V_30 = V_139 ;
if ( ! F_94 ( V_101 , & V_2 -> V_102 ) )
return;
if ( F_144 ( V_51 , V_2 -> V_141 ) ) {
if ( ! F_102 ( V_2 ) )
F_140 ( V_2 , V_131 ) ;
} else if ( ! V_30 -> V_142 || F_145 ( V_30 -> V_122 , V_2 -> V_141 ) ) {
V_30 -> V_122 = V_2 -> V_141 ;
V_30 -> V_142 = 1 ;
}
}
static void F_146 ( struct V_118 * V_119 )
{
struct V_14 * V_15 =
F_123 ( V_119 , struct V_14 , V_143 ) ;
struct V_140 V_30 = {
. V_122 = 0 ,
. V_142 = 0 ,
} ;
int V_24 ;
if ( ! F_147 ( & V_15 -> V_18 ) )
return;
F_148 ( V_15 , F_143 , & V_30 ) ;
if ( V_30 . V_142 ) {
V_30 . V_122 = F_149 ( F_150 ( V_30 . V_122 ) ) ;
F_151 ( & V_15 -> V_20 , V_30 . V_122 ) ;
} else {
struct V_7 * V_8 ;
F_35 (q, hctx, i) {
if ( F_41 ( V_8 ) )
F_152 ( V_8 ) ;
}
}
F_65 ( V_15 ) ;
}
static bool F_153 ( struct V_144 * V_145 , unsigned int V_146 , void * V_30 )
{
struct V_147 * V_148 = V_30 ;
struct V_7 * V_8 = V_148 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_149 [ V_146 ] ;
F_13 ( V_145 , V_146 ) ;
F_154 ( & V_12 -> V_150 ) ;
F_155 ( & V_12 -> V_121 , V_148 -> V_151 ) ;
F_156 ( & V_12 -> V_150 ) ;
return true ;
}
void F_157 ( struct V_7 * V_8 , struct V_152 * V_151 )
{
struct V_147 V_30 = {
. V_8 = V_8 ,
. V_151 = V_151 ,
} ;
F_158 ( & V_8 -> V_9 , F_153 , & V_30 ) ;
}
static inline unsigned int F_159 ( unsigned int V_80 )
{
if ( ! V_80 )
return 0 ;
return F_160 ( V_153 - 1 , F_4 ( V_80 ) + 1 ) ;
}
bool F_161 ( struct V_1 * V_2 , struct V_7 * * V_8 ,
bool V_154 )
{
struct V_29 V_30 = {
. V_15 = V_2 -> V_15 ,
. V_8 = F_61 ( V_2 -> V_15 , V_2 -> V_42 -> V_45 ) ,
. V_21 = V_154 ? 0 : V_70 ,
} ;
F_162 ( V_154 ) ;
if ( V_2 -> V_31 != - 1 )
goto V_155;
if ( F_163 ( V_30 . V_8 -> V_104 , V_2 -> V_37 ) )
V_30 . V_21 |= V_156 ;
V_2 -> V_31 = F_63 ( & V_30 ) ;
if ( V_2 -> V_31 >= 0 ) {
if ( F_47 ( V_30 . V_8 ) ) {
V_2 -> V_35 |= V_38 ;
F_48 ( & V_30 . V_8 -> V_39 ) ;
}
V_30 . V_8 -> V_28 -> V_40 [ V_2 -> V_31 ] = V_2 ;
}
V_155:
if ( V_8 )
* V_8 = V_30 . V_8 ;
return V_2 -> V_31 != - 1 ;
}
static void F_164 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
F_80 ( V_8 , V_8 -> V_28 , V_2 -> V_42 , V_2 -> V_31 ) ;
V_2 -> V_31 = - 1 ;
if ( V_2 -> V_35 & V_38 ) {
V_2 -> V_35 &= ~ V_38 ;
F_77 ( & V_8 -> V_39 ) ;
}
}
static void F_165 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_31 == - 1 || V_2 -> V_37 == - 1 )
return;
F_164 ( V_8 , V_2 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
if ( V_2 -> V_31 == - 1 || V_2 -> V_37 == - 1 )
return;
V_8 = F_61 ( V_2 -> V_15 , V_2 -> V_42 -> V_45 ) ;
F_164 ( V_8 , V_2 ) ;
}
static bool F_167 ( struct V_152 * V_151 )
{
struct V_1 * V_2 , * V_157 , * V_158 = NULL ;
F_168 (rq, tmp, list, queuelist) {
if ( V_2 == V_158 )
break;
if ( V_2 -> V_31 != - 1 ) {
F_169 ( & V_2 -> V_41 , V_151 ) ;
if ( ! V_158 )
V_158 = V_2 ;
}
}
return V_158 != NULL ;
}
static int F_170 ( T_2 * V_154 , unsigned V_159 , int V_21 ,
void * V_160 )
{
struct V_7 * V_8 ;
V_8 = F_123 ( V_154 , struct V_7 , V_161 ) ;
F_171 ( & V_154 -> V_162 ) ;
F_172 ( V_163 , & V_8 -> V_164 ) ;
F_173 ( V_8 , true ) ;
return 1 ;
}
static bool F_174 ( struct V_7 * V_8 )
{
struct V_165 * V_166 ;
if ( F_94 ( V_163 , & V_8 -> V_164 ) ||
F_175 ( V_163 , & V_8 -> V_164 ) )
return false ;
F_176 ( & V_8 -> V_161 , F_170 ) ;
V_166 = F_177 ( & V_8 -> V_28 -> V_167 , V_8 ) ;
F_178 ( & V_166 -> V_154 , & V_8 -> V_161 ) ;
return true ;
}
bool F_179 ( struct V_14 * V_15 , struct V_152 * V_151 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_168 , V_80 ;
if ( F_129 ( V_151 ) )
return false ;
V_168 = V_80 = 0 ;
do {
struct V_169 V_170 ;
T_1 V_82 ;
V_2 = F_180 ( V_151 , struct V_1 , V_41 ) ;
if ( ! F_161 ( V_2 , & V_8 , false ) ) {
if ( ! V_80 && F_167 ( V_151 ) )
continue;
if ( ! F_174 ( V_8 ) )
break;
if ( ! F_161 ( V_2 , & V_8 , false ) )
break;
}
F_127 ( & V_2 -> V_41 ) ;
V_170 . V_2 = V_2 ;
if ( F_129 ( V_151 ) )
V_170 . V_171 = true ;
else {
struct V_1 * V_172 ;
V_172 = F_180 ( V_151 , struct V_1 , V_41 ) ;
V_170 . V_171 = ! F_161 ( V_172 , NULL , false ) ;
}
V_82 = V_15 -> V_133 -> V_173 ( V_8 , & V_170 ) ;
if ( V_82 == V_174 ) {
F_165 ( V_8 , V_2 ) ;
F_131 ( & V_2 -> V_41 , V_151 ) ;
F_113 ( V_2 ) ;
break;
}
if ( F_84 ( V_82 != V_175 ) ) {
V_168 ++ ;
F_86 ( V_2 , V_176 ) ;
continue;
}
V_80 ++ ;
} while ( ! F_129 ( V_151 ) );
V_8 -> V_177 [ F_159 ( V_80 ) ] ++ ;
if ( ! F_129 ( V_151 ) ) {
V_2 = F_180 ( V_151 , struct V_1 , V_41 ) ;
F_166 ( V_2 ) ;
F_154 ( & V_8 -> V_150 ) ;
F_125 ( V_151 , & V_8 -> V_10 ) ;
F_156 ( & V_8 -> V_150 ) ;
if ( ! F_181 ( V_8 ) &&
! F_94 ( V_163 , & V_8 -> V_164 ) )
F_173 ( V_8 , true ) ;
}
return ( V_80 + V_168 ) != 0 ;
}
static void F_182 ( struct V_7 * V_8 )
{
int V_178 ;
F_183 ( ! F_184 ( F_185 () , V_8 -> V_94 ) &&
F_97 ( V_8 -> V_179 ) ) ;
if ( ! ( V_8 -> V_21 & V_26 ) ) {
F_186 () ;
F_187 ( V_8 ) ;
F_188 () ;
} else {
F_189 () ;
V_178 = F_190 ( V_8 -> V_27 ) ;
F_187 ( V_8 ) ;
F_191 ( V_8 -> V_27 , V_178 ) ;
}
}
static int F_192 ( struct V_7 * V_8 )
{
if ( V_8 -> V_180 -> V_90 == 1 )
return V_128 ;
if ( -- V_8 -> V_181 <= 0 ) {
int V_179 ;
V_179 = F_193 ( V_8 -> V_179 , V_8 -> V_94 ) ;
if ( V_179 >= V_182 )
V_179 = F_72 ( V_8 -> V_94 ) ;
V_8 -> V_179 = V_179 ;
V_8 -> V_181 = V_183 ;
}
return V_8 -> V_179 ;
}
static void F_194 ( struct V_7 * V_8 , bool V_184 ,
unsigned long V_127 )
{
if ( F_27 ( ! F_41 ( V_8 ) ) )
return;
if ( F_84 ( F_195 ( V_8 ) ) )
return;
if ( ! V_184 && ! ( V_8 -> V_21 & V_26 ) ) {
int V_45 = F_95 () ;
if ( F_184 ( V_45 , V_8 -> V_94 ) ) {
F_182 ( V_8 ) ;
F_99 () ;
return;
}
F_99 () ;
}
F_196 ( F_192 ( V_8 ) ,
& V_8 -> V_185 ,
F_137 ( V_127 ) ) ;
}
void F_197 ( struct V_7 * V_8 , unsigned long V_127 )
{
F_194 ( V_8 , true , V_127 ) ;
}
void F_173 ( struct V_7 * V_8 , bool V_184 )
{
F_194 ( V_8 , V_184 , 0 ) ;
}
void F_17 ( struct V_14 * V_15 , bool V_184 )
{
struct V_7 * V_8 ;
int V_24 ;
F_35 (q, hctx, i) {
if ( ! F_5 ( V_8 ) ||
F_195 ( V_8 ) )
continue;
F_173 ( V_8 , V_184 ) ;
}
}
bool F_198 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
int V_24 ;
F_35 (q, hctx, i)
if ( F_195 ( V_8 ) )
return true ;
return false ;
}
void F_199 ( struct V_7 * V_8 )
{
F_200 ( & V_8 -> V_185 ) ;
F_112 ( V_186 , & V_8 -> V_164 ) ;
}
void F_201 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
int V_24 ;
F_35 (q, hctx, i)
F_199 ( V_8 ) ;
}
void F_202 ( struct V_7 * V_8 )
{
F_79 ( V_186 , & V_8 -> V_164 ) ;
F_173 ( V_8 , false ) ;
}
void F_203 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
int V_24 ;
F_35 (q, hctx, i)
F_202 ( V_8 ) ;
}
void F_204 ( struct V_7 * V_8 , bool V_184 )
{
if ( ! F_195 ( V_8 ) )
return;
F_79 ( V_186 , & V_8 -> V_164 ) ;
F_173 ( V_8 , V_184 ) ;
}
void F_205 ( struct V_14 * V_15 , bool V_184 )
{
struct V_7 * V_8 ;
int V_24 ;
F_35 (q, hctx, i)
F_204 ( V_8 , V_184 ) ;
}
static void F_206 ( struct V_118 * V_119 )
{
struct V_7 * V_8 ;
V_8 = F_123 ( V_119 , struct V_7 , V_185 . V_119 ) ;
if ( F_94 ( V_186 , & V_8 -> V_164 ) ) {
if ( ! F_94 ( V_187 , & V_8 -> V_164 ) )
return;
F_79 ( V_187 , & V_8 -> V_164 ) ;
F_79 ( V_186 , & V_8 -> V_164 ) ;
}
F_182 ( V_8 ) ;
}
void F_207 ( struct V_7 * V_8 , unsigned long V_127 )
{
if ( F_27 ( ! F_41 ( V_8 ) ) )
return;
F_199 ( V_8 ) ;
F_112 ( V_187 , & V_8 -> V_164 ) ;
F_136 ( F_192 ( V_8 ) ,
& V_8 -> V_185 ,
F_137 ( V_127 ) ) ;
}
static inline void F_208 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
bool V_126 )
{
struct V_11 * V_12 = V_2 -> V_42 ;
F_209 ( & V_12 -> V_150 ) ;
F_210 ( V_8 -> V_180 , V_2 ) ;
if ( V_126 )
F_131 ( & V_2 -> V_41 , & V_12 -> V_121 ) ;
else
F_132 ( & V_2 -> V_41 , & V_12 -> V_121 ) ;
}
void F_211 ( struct V_7 * V_8 , struct V_1 * V_2 ,
bool V_126 )
{
struct V_11 * V_12 = V_2 -> V_42 ;
F_209 ( & V_12 -> V_150 ) ;
F_208 ( V_8 , V_2 , V_126 ) ;
F_9 ( V_8 , V_12 ) ;
}
void F_212 ( struct V_7 * V_8 , struct V_11 * V_12 ,
struct V_152 * V_151 )
{
F_154 ( & V_12 -> V_150 ) ;
while ( ! F_129 ( V_151 ) ) {
struct V_1 * V_2 ;
V_2 = F_180 ( V_151 , struct V_1 , V_41 ) ;
F_119 ( V_2 -> V_42 != V_12 ) ;
F_127 ( & V_2 -> V_41 ) ;
F_208 ( V_8 , V_2 , false ) ;
}
F_9 ( V_8 , V_12 ) ;
F_156 ( & V_12 -> V_150 ) ;
}
static int F_213 ( void * V_139 , struct V_152 * V_188 , struct V_152 * V_189 )
{
struct V_1 * V_190 = F_123 ( V_188 , struct V_1 , V_41 ) ;
struct V_1 * V_191 = F_123 ( V_189 , struct V_1 , V_41 ) ;
return ! ( V_190 -> V_42 < V_191 -> V_42 ||
( V_190 -> V_42 == V_191 -> V_42 &&
F_214 ( V_190 ) < F_214 ( V_191 ) ) ) ;
}
void F_215 ( struct V_192 * V_193 , bool V_194 )
{
struct V_11 * V_195 ;
struct V_14 * V_196 ;
struct V_1 * V_2 ;
F_124 ( V_151 ) ;
F_124 ( V_197 ) ;
unsigned int V_198 ;
F_125 ( & V_193 -> V_199 , & V_151 ) ;
F_216 ( NULL , & V_151 , F_213 ) ;
V_196 = NULL ;
V_195 = NULL ;
V_198 = 0 ;
while ( ! F_129 ( & V_151 ) ) {
V_2 = F_217 ( V_151 . V_122 ) ;
F_127 ( & V_2 -> V_41 ) ;
F_119 ( ! V_2 -> V_15 ) ;
if ( V_2 -> V_42 != V_195 ) {
if ( V_195 ) {
F_218 ( V_196 , V_198 , V_194 ) ;
F_219 ( V_196 , V_195 ,
& V_197 ,
V_194 ) ;
}
V_195 = V_2 -> V_42 ;
V_196 = V_2 -> V_15 ;
V_198 = 0 ;
}
V_198 ++ ;
F_132 ( & V_2 -> V_41 , & V_197 ) ;
}
if ( V_195 ) {
F_218 ( V_196 , V_198 , V_194 ) ;
F_219 ( V_196 , V_195 , & V_197 ,
V_194 ) ;
}
}
static void F_220 ( struct V_1 * V_2 , struct V_64 * V_64 )
{
F_221 ( V_2 , V_64 ) ;
F_222 ( V_2 , true ) ;
}
static inline bool F_223 ( struct V_7 * V_8 )
{
return ( V_8 -> V_21 & V_200 ) &&
! F_224 ( V_8 -> V_180 ) ;
}
static inline void F_225 ( struct V_7 * V_8 ,
struct V_11 * V_12 ,
struct V_1 * V_2 )
{
F_154 ( & V_12 -> V_150 ) ;
F_211 ( V_8 , V_2 , false ) ;
F_156 ( & V_12 -> V_150 ) ;
}
static T_3 F_226 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( V_2 -> V_31 != - 1 )
return F_227 ( V_2 -> V_31 , V_8 -> V_201 , false ) ;
return F_227 ( V_2 -> V_37 , V_8 -> V_201 , true ) ;
}
static void F_228 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
T_3 * V_202 , bool V_203 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_169 V_170 = {
. V_2 = V_2 ,
. V_171 = true ,
} ;
T_3 V_204 ;
T_1 V_82 ;
bool V_205 = true ;
if ( F_195 ( V_8 ) || F_229 ( V_15 ) ) {
V_205 = false ;
goto V_206;
}
if ( V_15 -> V_67 )
goto V_206;
if ( ! F_161 ( V_2 , NULL , false ) )
goto V_206;
V_204 = F_226 ( V_8 , V_2 ) ;
V_82 = V_15 -> V_133 -> V_173 ( V_8 , & V_170 ) ;
switch ( V_82 ) {
case V_175 :
* V_202 = V_204 ;
return;
case V_174 :
F_113 ( V_2 ) ;
goto V_206;
default:
* V_202 = V_207 ;
F_86 ( V_2 , V_82 ) ;
return;
}
V_206:
F_128 ( V_2 , false , V_205 , false , V_203 ) ;
}
static void F_230 ( struct V_7 * V_8 ,
struct V_1 * V_2 , T_3 * V_202 )
{
if ( ! ( V_8 -> V_21 & V_26 ) ) {
F_186 () ;
F_228 ( V_8 , V_2 , V_202 , false ) ;
F_188 () ;
} else {
unsigned int V_178 ;
F_189 () ;
V_178 = F_190 ( V_8 -> V_27 ) ;
F_228 ( V_8 , V_2 , V_202 , true ) ;
F_191 ( V_8 -> V_27 , V_178 ) ;
}
}
static T_3 F_231 ( struct V_14 * V_15 , struct V_64 * V_64 )
{
const int V_208 = F_56 ( V_64 -> V_209 ) ;
const int V_210 = F_62 ( V_64 -> V_209 ) ;
struct V_29 V_30 = { . V_21 = 0 } ;
struct V_1 * V_2 ;
unsigned int V_211 = 0 ;
struct V_192 * V_193 ;
struct V_1 * V_212 = NULL ;
T_3 V_202 ;
unsigned int V_213 ;
F_232 ( V_15 , & V_64 ) ;
F_233 ( V_15 , & V_64 ) ;
if ( ! F_234 ( V_64 ) )
return V_207 ;
if ( ! V_210 && ! F_224 ( V_15 ) &&
F_235 ( V_15 , V_64 , & V_211 , & V_212 ) )
return V_207 ;
if ( F_236 ( V_15 , V_64 ) )
return V_207 ;
V_213 = F_237 ( V_15 -> V_99 , V_64 , NULL ) ;
F_238 ( V_15 , V_64 , V_64 -> V_209 ) ;
V_2 = F_57 ( V_15 , V_64 , V_64 -> V_209 , & V_30 ) ;
if ( F_84 ( ! V_2 ) ) {
F_239 ( V_15 -> V_99 , V_213 ) ;
if ( V_64 -> V_209 & V_69 )
F_240 ( V_64 ) ;
return V_207 ;
}
F_241 ( & V_2 -> V_100 , V_213 ) ;
V_202 = F_226 ( V_30 . V_8 , V_2 ) ;
V_193 = V_214 -> V_193 ;
if ( F_84 ( V_210 ) ) {
F_64 ( V_30 . V_12 ) ;
F_220 ( V_2 , V_64 ) ;
if ( V_15 -> V_67 ) {
F_128 ( V_2 , false , true , true ,
true ) ;
} else {
F_242 ( V_2 ) ;
F_173 ( V_30 . V_8 , true ) ;
}
} else if ( V_193 && V_15 -> V_90 == 1 ) {
struct V_1 * V_171 = NULL ;
F_64 ( V_30 . V_12 ) ;
F_220 ( V_2 , V_64 ) ;
if ( F_129 ( & V_193 -> V_199 ) )
V_211 = 0 ;
else if ( F_224 ( V_15 ) )
V_211 = F_243 ( V_15 ) ;
if ( ! V_211 )
F_244 ( V_15 ) ;
else
V_171 = F_217 ( V_193 -> V_199 . V_215 ) ;
if ( V_211 >= V_216 || ( V_171 &&
F_3 ( V_171 ) >= V_217 ) ) {
F_245 ( V_193 , false ) ;
F_244 ( V_15 ) ;
}
F_132 ( & V_2 -> V_41 , & V_193 -> V_199 ) ;
} else if ( V_193 && ! F_224 ( V_15 ) ) {
F_220 ( V_2 , V_64 ) ;
if ( F_129 ( & V_193 -> V_199 ) )
V_212 = NULL ;
if ( V_212 )
F_127 ( & V_212 -> V_41 ) ;
F_132 ( & V_2 -> V_41 , & V_193 -> V_199 ) ;
F_64 ( V_30 . V_12 ) ;
if ( V_212 ) {
V_30 . V_8 = F_61 ( V_15 ,
V_212 -> V_42 -> V_45 ) ;
F_230 ( V_30 . V_8 , V_212 ,
& V_202 ) ;
}
} else if ( V_15 -> V_90 > 1 && V_208 ) {
F_64 ( V_30 . V_12 ) ;
F_220 ( V_2 , V_64 ) ;
F_230 ( V_30 . V_8 , V_2 , & V_202 ) ;
} else if ( V_15 -> V_67 ) {
F_64 ( V_30 . V_12 ) ;
F_220 ( V_2 , V_64 ) ;
F_128 ( V_2 , false , true , true , true ) ;
} else {
F_64 ( V_30 . V_12 ) ;
F_220 ( V_2 , V_64 ) ;
F_225 ( V_30 . V_8 , V_30 . V_12 , V_2 ) ;
F_173 ( V_30 . V_8 , true ) ;
}
return V_202 ;
}
void F_246 ( struct V_218 * V_219 , struct V_33 * V_28 ,
unsigned int V_88 )
{
struct V_220 * V_220 ;
if ( V_28 -> V_40 && V_219 -> V_71 -> V_221 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < V_28 -> V_129 ; V_24 ++ ) {
struct V_1 * V_2 = V_28 -> V_34 [ V_24 ] ;
if ( ! V_2 )
continue;
V_219 -> V_71 -> V_221 ( V_219 , V_2 , V_88 ) ;
V_28 -> V_34 [ V_24 ] = NULL ;
}
}
while ( ! F_129 ( & V_28 -> V_222 ) ) {
V_220 = F_180 ( & V_28 -> V_222 , struct V_220 , V_223 ) ;
F_127 ( & V_220 -> V_223 ) ;
F_247 ( F_248 ( V_220 ) ) ;
F_249 ( V_220 , V_220 -> V_224 ) ;
}
}
void F_250 ( struct V_33 * V_28 )
{
F_251 ( V_28 -> V_40 ) ;
V_28 -> V_40 = NULL ;
F_251 ( V_28 -> V_34 ) ;
V_28 -> V_34 = NULL ;
F_252 ( V_28 ) ;
}
struct V_33 * F_253 ( struct V_218 * V_219 ,
unsigned int V_88 ,
unsigned int V_129 ,
unsigned int V_225 )
{
struct V_33 * V_28 ;
int V_226 ;
V_226 = F_254 ( V_219 -> V_227 , V_88 ) ;
if ( V_226 == V_228 )
V_226 = V_219 -> V_229 ;
V_28 = F_255 ( V_129 , V_225 , V_226 ,
F_256 ( V_219 -> V_21 ) ) ;
if ( ! V_28 )
return NULL ;
V_28 -> V_40 = F_257 ( V_129 * sizeof( struct V_1 * ) ,
V_230 | V_231 | V_232 ,
V_226 ) ;
if ( ! V_28 -> V_40 ) {
F_252 ( V_28 ) ;
return NULL ;
}
V_28 -> V_34 = F_257 ( V_129 * sizeof( struct V_1 * ) ,
V_230 | V_231 | V_232 ,
V_226 ) ;
if ( ! V_28 -> V_34 ) {
F_251 ( V_28 -> V_40 ) ;
F_252 ( V_28 ) ;
return NULL ;
}
return V_28 ;
}
static T_4 F_258 ( unsigned int V_233 )
{
return ( T_4 ) V_234 << V_233 ;
}
int F_259 ( struct V_218 * V_219 , struct V_33 * V_28 ,
unsigned int V_88 , unsigned int V_198 )
{
unsigned int V_24 , V_235 , V_236 , V_237 = 4 ;
T_4 V_238 , V_239 ;
int V_226 ;
V_226 = F_254 ( V_219 -> V_227 , V_88 ) ;
if ( V_226 == V_228 )
V_226 = V_219 -> V_229 ;
F_49 ( & V_28 -> V_222 ) ;
V_238 = F_260 ( sizeof( struct V_1 ) + V_219 -> V_240 ,
F_261 () ) ;
V_239 = V_238 * V_198 ;
for ( V_24 = 0 ; V_24 < V_198 ; ) {
int V_241 = V_237 ;
struct V_220 * V_220 ;
int V_242 ;
void * V_243 ;
while ( V_241 && V_239 < F_258 ( V_241 - 1 ) )
V_241 -- ;
do {
V_220 = F_262 ( V_226 ,
V_230 | V_231 | V_232 | V_244 ,
V_241 ) ;
if ( V_220 )
break;
if ( ! V_241 -- )
break;
if ( F_258 ( V_241 ) < V_238 )
break;
} while ( 1 );
if ( ! V_220 )
goto V_245;
V_220 -> V_224 = V_241 ;
F_132 ( & V_220 -> V_223 , & V_28 -> V_222 ) ;
V_243 = F_248 ( V_220 ) ;
F_263 ( V_243 , F_258 ( V_241 ) , 1 , V_230 ) ;
V_236 = F_258 ( V_241 ) / V_238 ;
V_242 = F_160 ( V_236 , V_198 - V_24 ) ;
V_239 -= V_242 * V_238 ;
for ( V_235 = 0 ; V_235 < V_242 ; V_235 ++ ) {
struct V_1 * V_2 = V_243 ;
V_28 -> V_34 [ V_24 ] = V_2 ;
if ( V_219 -> V_71 -> V_246 ) {
if ( V_219 -> V_71 -> V_246 ( V_219 , V_2 , V_88 ,
V_226 ) ) {
V_28 -> V_34 [ V_24 ] = NULL ;
goto V_245;
}
}
V_243 += V_238 ;
V_24 ++ ;
}
}
return 0 ;
V_245:
F_246 ( V_219 , V_28 , V_88 ) ;
return - V_247 ;
}
static int F_264 ( unsigned int V_45 , struct V_248 * V_226 )
{
struct V_7 * V_8 ;
struct V_11 * V_12 ;
F_124 ( V_157 ) ;
V_8 = F_265 ( V_226 , struct V_7 , V_249 ) ;
V_12 = F_73 ( V_8 -> V_180 , V_45 ) ;
F_154 ( & V_12 -> V_150 ) ;
if ( ! F_129 ( & V_12 -> V_121 ) ) {
F_125 ( & V_12 -> V_121 , & V_157 ) ;
F_12 ( V_8 , V_12 ) ;
}
F_156 ( & V_12 -> V_150 ) ;
if ( F_129 ( & V_157 ) )
return 0 ;
F_154 ( & V_8 -> V_150 ) ;
F_155 ( & V_157 , & V_8 -> V_10 ) ;
F_156 ( & V_8 -> V_150 ) ;
F_173 ( V_8 , true ) ;
return 0 ;
}
static void F_266 ( struct V_7 * V_8 )
{
F_267 ( V_250 ,
& V_8 -> V_249 ) ;
}
static void F_268 ( struct V_14 * V_15 ,
struct V_218 * V_219 ,
struct V_7 * V_8 , unsigned int V_88 )
{
F_269 ( V_8 ) ;
F_152 ( V_8 ) ;
if ( V_219 -> V_71 -> V_221 )
V_219 -> V_71 -> V_221 ( V_219 , V_8 -> V_251 -> V_252 , V_88 ) ;
F_270 ( V_15 , V_8 , V_88 ) ;
if ( V_219 -> V_71 -> V_253 )
V_219 -> V_71 -> V_253 ( V_8 , V_88 ) ;
if ( V_8 -> V_21 & V_26 )
F_271 ( V_8 -> V_27 ) ;
F_266 ( V_8 ) ;
F_272 ( V_8 -> V_251 ) ;
F_273 ( & V_8 -> V_9 ) ;
}
static void F_274 ( struct V_14 * V_15 ,
struct V_218 * V_219 , int V_254 )
{
struct V_7 * V_8 ;
unsigned int V_24 ;
F_35 (q, hctx, i) {
if ( V_24 == V_254 )
break;
F_268 ( V_15 , V_219 , V_8 , V_24 ) ;
}
}
static int F_275 ( struct V_14 * V_15 ,
struct V_218 * V_219 ,
struct V_7 * V_8 , unsigned V_88 )
{
int V_226 ;
V_226 = V_8 -> V_229 ;
if ( V_226 == V_228 )
V_226 = V_8 -> V_229 = V_219 -> V_229 ;
F_276 ( & V_8 -> V_185 , F_206 ) ;
F_277 ( & V_8 -> V_150 ) ;
F_49 ( & V_8 -> V_10 ) ;
V_8 -> V_180 = V_15 ;
V_8 -> V_21 = V_219 -> V_21 & ~ V_255 ;
F_278 ( V_250 , & V_8 -> V_249 ) ;
V_8 -> V_28 = V_219 -> V_28 [ V_88 ] ;
V_8 -> V_149 = F_279 ( V_182 * sizeof( void * ) ,
V_256 , V_226 ) ;
if ( ! V_8 -> V_149 )
goto V_257;
if ( F_280 ( & V_8 -> V_9 , V_182 , F_4 ( 8 ) , V_256 ,
V_226 ) )
goto V_258;
V_8 -> V_259 = 0 ;
if ( V_219 -> V_71 -> V_260 &&
V_219 -> V_71 -> V_260 ( V_8 , V_219 -> V_261 , V_88 ) )
goto V_262;
if ( F_281 ( V_15 , V_8 , V_88 ) )
goto V_253;
V_8 -> V_251 = F_282 ( V_15 , V_8 -> V_229 , V_219 -> V_240 ) ;
if ( ! V_8 -> V_251 )
goto V_263;
if ( V_219 -> V_71 -> V_246 &&
V_219 -> V_71 -> V_246 ( V_219 , V_8 -> V_251 -> V_252 , V_88 ,
V_226 ) )
goto V_264;
if ( V_8 -> V_21 & V_26 )
F_283 ( V_8 -> V_27 ) ;
F_284 ( V_15 , V_8 ) ;
return 0 ;
V_264:
F_251 ( V_8 -> V_251 ) ;
V_263:
F_270 ( V_15 , V_8 , V_88 ) ;
V_253:
if ( V_219 -> V_71 -> V_253 )
V_219 -> V_71 -> V_253 ( V_8 , V_88 ) ;
V_262:
F_273 ( & V_8 -> V_9 ) ;
V_258:
F_251 ( V_8 -> V_149 ) ;
V_257:
F_266 ( V_8 ) ;
return - 1 ;
}
static void F_285 ( struct V_14 * V_15 ,
unsigned int V_90 )
{
unsigned int V_24 ;
F_286 (i) {
struct V_11 * V_265 = F_287 ( V_15 -> V_266 , V_24 ) ;
struct V_7 * V_8 ;
V_265 -> V_45 = V_24 ;
F_277 ( & V_265 -> V_150 ) ;
F_49 ( & V_265 -> V_121 ) ;
V_265 -> V_180 = V_15 ;
if ( ! F_288 ( V_24 ) )
continue;
V_8 = F_61 ( V_15 , V_24 ) ;
if ( V_90 > 1 && V_8 -> V_229 == V_228 )
V_8 -> V_229 = F_289 ( F_290 ( V_24 ) ) ;
}
}
static bool F_291 ( struct V_218 * V_219 , int V_88 )
{
int V_82 = 0 ;
V_219 -> V_28 [ V_88 ] = F_253 ( V_219 , V_88 ,
V_219 -> V_267 , V_219 -> V_225 ) ;
if ( ! V_219 -> V_28 [ V_88 ] )
return false ;
V_82 = F_259 ( V_219 , V_219 -> V_28 [ V_88 ] , V_88 ,
V_219 -> V_267 ) ;
if ( ! V_82 )
return true ;
F_250 ( V_219 -> V_28 [ V_88 ] ) ;
V_219 -> V_28 [ V_88 ] = NULL ;
return false ;
}
static void F_292 ( struct V_218 * V_219 ,
unsigned int V_88 )
{
if ( V_219 -> V_28 [ V_88 ] ) {
F_246 ( V_219 , V_219 -> V_28 [ V_88 ] , V_88 ) ;
F_250 ( V_219 -> V_28 [ V_88 ] ) ;
V_219 -> V_28 [ V_88 ] = NULL ;
}
}
static void F_293 ( struct V_14 * V_15 )
{
unsigned int V_24 , V_88 ;
struct V_7 * V_8 ;
struct V_11 * V_12 ;
struct V_218 * V_219 = V_15 -> V_268 ;
F_294 ( & V_15 -> V_269 ) ;
F_35 (q, hctx, i) {
F_295 ( V_8 -> V_94 ) ;
V_8 -> V_259 = 0 ;
}
F_296 (i) {
V_88 = V_15 -> V_227 [ V_24 ] ;
if ( ! V_219 -> V_28 [ V_88 ] &&
! F_291 ( V_219 , V_88 ) ) {
V_15 -> V_227 [ V_24 ] = 0 ;
}
V_12 = F_287 ( V_15 -> V_266 , V_24 ) ;
V_8 = F_61 ( V_15 , V_24 ) ;
F_297 ( V_24 , V_8 -> V_94 ) ;
V_12 -> V_13 = V_8 -> V_259 ;
V_8 -> V_149 [ V_8 -> V_259 ++ ] = V_12 ;
}
F_298 ( & V_15 -> V_269 ) ;
F_35 (q, hctx, i) {
if ( ! V_8 -> V_259 ) {
if ( V_24 && V_219 -> V_28 [ V_24 ] )
F_292 ( V_219 , V_24 ) ;
V_8 -> V_28 = NULL ;
continue;
}
V_8 -> V_28 = V_219 -> V_28 [ V_24 ] ;
F_183 ( ! V_8 -> V_28 ) ;
F_299 ( & V_8 -> V_9 , V_8 -> V_259 ) ;
V_8 -> V_179 = F_72 ( V_8 -> V_94 ) ;
V_8 -> V_181 = V_183 ;
}
}
static void F_300 ( struct V_14 * V_15 , bool V_106 )
{
struct V_7 * V_8 ;
int V_24 ;
F_35 (q, hctx, i) {
if ( V_106 ) {
if ( F_94 ( V_270 , & V_8 -> V_164 ) )
F_48 ( & V_15 -> V_271 ) ;
V_8 -> V_21 |= V_255 ;
} else {
if ( F_94 ( V_270 , & V_8 -> V_164 ) )
F_77 ( & V_15 -> V_271 ) ;
V_8 -> V_21 &= ~ V_255 ;
}
}
}
static void F_301 ( struct V_218 * V_219 ,
bool V_106 )
{
struct V_14 * V_15 ;
F_209 ( & V_219 -> V_272 ) ;
F_302 (q, &set->tag_list, tag_set_list) {
F_24 ( V_15 ) ;
F_300 ( V_15 , V_106 ) ;
F_25 ( V_15 ) ;
}
}
static void F_303 ( struct V_14 * V_15 )
{
struct V_218 * V_219 = V_15 -> V_268 ;
F_294 ( & V_219 -> V_272 ) ;
F_304 ( & V_15 -> V_273 ) ;
F_49 ( & V_15 -> V_273 ) ;
if ( F_305 ( & V_219 -> V_274 ) ) {
V_219 -> V_21 &= ~ V_255 ;
F_301 ( V_219 , false ) ;
}
F_298 ( & V_219 -> V_272 ) ;
F_37 () ;
}
static void F_306 ( struct V_218 * V_219 ,
struct V_14 * V_15 )
{
V_15 -> V_268 = V_219 ;
F_294 ( & V_219 -> V_272 ) ;
if ( ! F_129 ( & V_219 -> V_274 ) && ! ( V_219 -> V_21 & V_255 ) ) {
V_219 -> V_21 |= V_255 ;
F_301 ( V_219 , true ) ;
}
if ( V_219 -> V_21 & V_255 )
F_300 ( V_15 , true ) ;
F_307 ( & V_15 -> V_273 , & V_219 -> V_274 ) ;
F_298 ( & V_219 -> V_272 ) ;
}
void F_308 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
unsigned int V_24 ;
F_35 (q, hctx, i) {
if ( ! V_8 )
continue;
F_309 ( & V_8 -> V_275 ) ;
}
V_15 -> V_227 = NULL ;
F_251 ( V_15 -> V_92 ) ;
F_310 ( V_15 ) ;
F_311 ( V_15 -> V_266 ) ;
}
struct V_14 * F_312 ( struct V_218 * V_219 )
{
struct V_14 * V_276 , * V_15 ;
V_276 = F_313 ( V_256 , V_219 -> V_229 ) ;
if ( ! V_276 )
return F_70 ( - V_247 ) ;
V_15 = F_314 ( V_219 , V_276 ) ;
if ( F_315 ( V_15 ) )
F_316 ( V_276 ) ;
return V_15 ;
}
static int F_317 ( struct V_218 * V_268 )
{
int V_277 = sizeof( struct V_7 ) ;
F_318 ( F_319 ( F_320 ( struct V_7 , V_27 ) ,
F_321 ( struct V_7 ) ) !=
sizeof( struct V_7 ) ) ;
if ( V_268 -> V_21 & V_26 )
V_277 += sizeof( struct V_278 ) ;
return V_277 ;
}
static void F_322 ( struct V_218 * V_219 ,
struct V_14 * V_15 )
{
int V_24 , V_235 ;
struct V_7 * * V_279 = V_15 -> V_92 ;
F_323 ( V_15 ) ;
for ( V_24 = 0 ; V_24 < V_219 -> V_90 ; V_24 ++ ) {
int V_226 ;
if ( V_279 [ V_24 ] )
continue;
V_226 = F_254 ( V_15 -> V_227 , V_24 ) ;
V_279 [ V_24 ] = F_257 ( F_317 ( V_219 ) ,
V_256 , V_226 ) ;
if ( ! V_279 [ V_24 ] )
break;
if ( ! F_324 ( & V_279 [ V_24 ] -> V_94 , V_256 ,
V_226 ) ) {
F_251 ( V_279 [ V_24 ] ) ;
V_279 [ V_24 ] = NULL ;
break;
}
F_325 ( & V_279 [ V_24 ] -> V_39 , 0 ) ;
V_279 [ V_24 ] -> V_229 = V_226 ;
V_279 [ V_24 ] -> V_201 = V_24 ;
if ( F_275 ( V_15 , V_219 , V_279 [ V_24 ] , V_24 ) ) {
F_326 ( V_279 [ V_24 ] -> V_94 ) ;
F_251 ( V_279 [ V_24 ] ) ;
V_279 [ V_24 ] = NULL ;
break;
}
F_327 ( V_279 [ V_24 ] ) ;
}
for ( V_235 = V_24 ; V_235 < V_15 -> V_90 ; V_235 ++ ) {
struct V_7 * V_8 = V_279 [ V_235 ] ;
if ( V_8 ) {
if ( V_8 -> V_28 )
F_292 ( V_219 , V_235 ) ;
F_268 ( V_15 , V_219 , V_8 , V_235 ) ;
F_309 ( & V_8 -> V_275 ) ;
V_279 [ V_235 ] = NULL ;
}
}
V_15 -> V_90 = V_24 ;
F_328 ( V_15 ) ;
}
struct V_14 * F_314 ( struct V_218 * V_219 ,
struct V_14 * V_15 )
{
V_15 -> V_133 = V_219 -> V_71 ;
V_15 -> V_280 = F_329 ( V_281 ,
F_1 ,
V_6 , V_15 ) ;
if ( ! V_15 -> V_280 )
goto V_282;
V_15 -> V_266 = F_330 ( struct V_11 ) ;
if ( ! V_15 -> V_266 )
goto V_282;
F_331 ( V_15 ) ;
V_15 -> V_92 = F_257 ( V_182 * sizeof( * ( V_15 -> V_92 ) ) ,
V_256 , V_219 -> V_229 ) ;
if ( ! V_15 -> V_92 )
goto V_283;
V_15 -> V_227 = V_219 -> V_227 ;
F_322 ( V_219 , V_15 ) ;
if ( ! V_15 -> V_90 )
goto V_284;
F_332 ( & V_15 -> V_143 , F_146 ) ;
F_333 ( V_15 , V_219 -> V_20 ? V_219 -> V_20 : 30 * V_285 ) ;
V_15 -> V_286 = V_182 ;
V_15 -> V_109 |= V_287 ;
if ( ! ( V_219 -> V_21 & V_288 ) )
V_15 -> V_109 |= 1 << V_289 ;
V_15 -> V_290 = V_291 ;
F_276 ( & V_15 -> V_120 , F_122 ) ;
F_49 ( & V_15 -> V_124 ) ;
F_277 ( & V_15 -> V_123 ) ;
F_334 ( V_15 , F_231 ) ;
V_15 -> V_292 = V_219 -> V_267 ;
V_15 -> V_293 = - 1 ;
if ( V_219 -> V_71 -> V_294 )
F_335 ( V_15 , V_219 -> V_71 -> V_294 ) ;
F_285 ( V_15 , V_219 -> V_90 ) ;
F_306 ( V_219 , V_15 ) ;
F_293 ( V_15 ) ;
if ( ! ( V_219 -> V_21 & V_295 ) ) {
int V_82 ;
V_82 = F_336 ( V_15 ) ;
if ( V_82 )
return F_70 ( V_82 ) ;
}
return V_15 ;
V_284:
F_251 ( V_15 -> V_92 ) ;
V_283:
F_311 ( V_15 -> V_266 ) ;
V_282:
V_15 -> V_133 = NULL ;
return F_70 ( - V_247 ) ;
}
void F_337 ( struct V_14 * V_15 )
{
struct V_218 * V_219 = V_15 -> V_268 ;
F_303 ( V_15 ) ;
F_274 ( V_15 , V_219 , V_219 -> V_90 ) ;
}
static void F_338 ( struct V_14 * V_15 )
{
F_27 ( ! F_339 ( & V_15 -> V_17 ) ) ;
F_340 ( V_15 ) ;
F_323 ( V_15 ) ;
F_293 ( V_15 ) ;
F_328 ( V_15 ) ;
F_341 ( V_15 ) ;
}
static int F_342 ( struct V_218 * V_219 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_219 -> V_90 ; V_24 ++ )
if ( ! F_291 ( V_219 , V_24 ) )
goto V_296;
return 0 ;
V_296:
while ( -- V_24 >= 0 )
F_250 ( V_219 -> V_28 [ V_24 ] ) ;
return - V_247 ;
}
static int F_343 ( struct V_218 * V_219 )
{
unsigned int V_198 ;
int V_297 ;
V_198 = V_219 -> V_267 ;
do {
V_297 = F_342 ( V_219 ) ;
if ( ! V_297 )
break;
V_219 -> V_267 >>= 1 ;
if ( V_219 -> V_267 < V_219 -> V_225 + V_298 ) {
V_297 = - V_247 ;
break;
}
} while ( V_219 -> V_267 );
if ( ! V_219 -> V_267 || V_297 ) {
F_344 ( L_2 ) ;
return - V_247 ;
}
if ( V_198 != V_219 -> V_267 )
F_345 ( L_3 ,
V_198 , V_219 -> V_267 ) ;
return 0 ;
}
static int F_346 ( struct V_218 * V_219 )
{
if ( V_219 -> V_71 -> V_299 )
return V_219 -> V_71 -> V_299 ( V_219 ) ;
else
return F_347 ( V_219 ) ;
}
int F_348 ( struct V_218 * V_219 )
{
int V_82 ;
F_318 ( V_300 > 1 << V_301 ) ;
if ( ! V_219 -> V_90 )
return - V_89 ;
if ( ! V_219 -> V_267 )
return - V_89 ;
if ( V_219 -> V_267 < V_219 -> V_225 + V_298 )
return - V_89 ;
if ( ! V_219 -> V_71 -> V_173 )
return - V_89 ;
if ( V_219 -> V_267 > V_300 ) {
F_345 ( L_4 ,
V_300 ) ;
V_219 -> V_267 = V_300 ;
}
if ( F_349 () ) {
V_219 -> V_90 = 1 ;
V_219 -> V_267 = F_160 ( 64U , V_219 -> V_267 ) ;
}
if ( V_219 -> V_90 > V_182 )
V_219 -> V_90 = V_182 ;
V_219 -> V_28 = F_257 ( V_182 * sizeof( struct V_33 * ) ,
V_256 , V_219 -> V_229 ) ;
if ( ! V_219 -> V_28 )
return - V_247 ;
V_82 = - V_247 ;
V_219 -> V_227 = F_257 ( sizeof( * V_219 -> V_227 ) * V_182 ,
V_256 , V_219 -> V_229 ) ;
if ( ! V_219 -> V_227 )
goto V_302;
V_82 = F_346 ( V_219 ) ;
if ( V_82 )
goto V_303;
V_82 = F_343 ( V_219 ) ;
if ( V_82 )
goto V_303;
F_350 ( & V_219 -> V_272 ) ;
F_49 ( & V_219 -> V_274 ) ;
return 0 ;
V_303:
F_251 ( V_219 -> V_227 ) ;
V_219 -> V_227 = NULL ;
V_302:
F_251 ( V_219 -> V_28 ) ;
V_219 -> V_28 = NULL ;
return V_82 ;
}
void F_351 ( struct V_218 * V_219 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_182 ; V_24 ++ )
F_292 ( V_219 , V_24 ) ;
F_251 ( V_219 -> V_227 ) ;
V_219 -> V_227 = NULL ;
F_251 ( V_219 -> V_28 ) ;
V_219 -> V_28 = NULL ;
}
int F_352 ( struct V_14 * V_15 , unsigned int V_304 )
{
struct V_218 * V_219 = V_15 -> V_268 ;
struct V_7 * V_8 ;
int V_24 , V_82 ;
if ( ! V_219 )
return - V_89 ;
F_24 ( V_15 ) ;
V_82 = 0 ;
F_35 (q, hctx, i) {
if ( ! V_8 -> V_28 )
continue;
if ( ! V_8 -> V_104 ) {
V_82 = F_353 ( V_8 , & V_8 -> V_28 ,
F_160 ( V_304 , V_219 -> V_267 ) ,
false ) ;
} else {
V_82 = F_353 ( V_8 , & V_8 -> V_104 ,
V_304 , true ) ;
}
if ( V_82 )
break;
}
if ( ! V_82 )
V_15 -> V_292 = V_304 ;
F_25 ( V_15 ) ;
return V_82 ;
}
static void F_354 ( struct V_218 * V_219 ,
int V_90 )
{
struct V_14 * V_15 ;
F_209 ( & V_219 -> V_272 ) ;
if ( V_90 > V_182 )
V_90 = V_182 ;
if ( V_90 < 1 || V_90 == V_219 -> V_90 )
return;
F_302 (q, &set->tag_list, tag_set_list)
F_24 ( V_15 ) ;
V_219 -> V_90 = V_90 ;
F_346 ( V_219 ) ;
F_302 (q, &set->tag_list, tag_set_list) {
F_322 ( V_219 , V_15 ) ;
F_338 ( V_15 ) ;
}
F_302 (q, &set->tag_list, tag_set_list)
F_25 ( V_15 ) ;
}
void F_355 ( struct V_218 * V_219 , int V_90 )
{
F_294 ( & V_219 -> V_272 ) ;
F_354 ( V_219 , V_90 ) ;
F_298 ( & V_219 -> V_272 ) ;
}
static bool F_356 ( struct V_14 * V_15 )
{
if ( F_94 ( V_305 , & V_15 -> V_109 ) ||
F_357 ( V_305 , & V_15 -> V_109 ) )
return true ;
F_358 ( V_15 , V_15 -> V_280 ) ;
return false ;
}
static void F_92 ( struct V_14 * V_15 )
{
if ( ! F_94 ( V_305 , & V_15 -> V_109 ) ||
F_359 ( V_15 -> V_280 ) )
return;
F_360 ( V_15 -> V_280 , 100 ) ;
}
static void V_281 ( struct V_306 * V_307 )
{
struct V_14 * V_15 = V_307 -> V_30 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_307 -> V_308 [ V_5 ] . V_309 )
V_15 -> V_310 [ V_5 ] = V_307 -> V_308 [ V_5 ] ;
}
}
static unsigned long F_361 ( struct V_14 * V_15 ,
struct V_7 * V_8 ,
struct V_1 * V_2 )
{
unsigned long V_82 = 0 ;
int V_5 ;
if ( ! F_356 ( V_15 ) )
return 0 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_82 ;
if ( V_15 -> V_310 [ V_5 ] . V_309 )
V_82 = ( V_15 -> V_310 [ V_5 ] . V_311 + 1 ) / 2 ;
return V_82 ;
}
static bool F_362 ( struct V_14 * V_15 ,
struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_312 V_313 ;
enum V_314 V_159 ;
unsigned int V_315 ;
T_5 V_316 ;
if ( F_94 ( V_103 , & V_2 -> V_102 ) )
return false ;
if ( V_15 -> V_293 == - 1 )
return false ;
else if ( V_15 -> V_293 > 0 )
V_315 = V_15 -> V_293 ;
else
V_315 = F_361 ( V_15 , V_8 , V_2 ) ;
if ( ! V_315 )
return false ;
F_112 ( V_103 , & V_2 -> V_102 ) ;
V_316 = V_315 ;
V_159 = V_317 ;
F_363 ( & V_313 . V_318 , V_319 , V_159 ) ;
F_364 ( & V_313 . V_318 , V_316 ) ;
F_365 ( & V_313 , V_214 ) ;
do {
if ( F_94 ( V_115 , & V_2 -> V_102 ) )
break;
F_366 ( V_320 ) ;
F_367 ( & V_313 . V_318 , V_159 ) ;
if ( V_313 . V_321 )
F_368 () ;
F_369 ( & V_313 . V_318 ) ;
V_159 = V_322 ;
} while ( V_313 . V_321 && ! F_370 ( V_214 ) );
F_371 ( V_323 ) ;
F_372 ( & V_313 . V_318 ) ;
return true ;
}
static bool F_373 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_14 * V_15 = V_8 -> V_180 ;
long V_164 ;
if ( F_362 ( V_15 , V_8 , V_2 ) )
return true ;
V_8 -> V_324 ++ ;
V_164 = V_214 -> V_164 ;
while ( ! F_374 () ) {
int V_82 ;
V_8 -> V_325 ++ ;
V_82 = V_15 -> V_133 -> V_326 ( V_8 , V_2 -> V_31 ) ;
if ( V_82 > 0 ) {
V_8 -> V_327 ++ ;
F_366 ( V_323 ) ;
return true ;
}
if ( F_375 ( V_164 , V_214 ) )
F_366 ( V_323 ) ;
if ( V_214 -> V_164 == V_323 )
return true ;
if ( V_82 < 0 )
break;
F_376 () ;
}
return false ;
}
bool F_377 ( struct V_14 * V_15 , T_3 V_202 )
{
struct V_7 * V_8 ;
struct V_192 * V_193 ;
struct V_1 * V_2 ;
if ( ! V_15 -> V_133 || ! V_15 -> V_133 -> V_326 || ! F_378 ( V_202 ) ||
! F_94 ( V_328 , & V_15 -> V_109 ) )
return false ;
V_193 = V_214 -> V_193 ;
if ( V_193 )
F_245 ( V_193 , false ) ;
V_8 = V_15 -> V_92 [ F_379 ( V_202 ) ] ;
if ( ! F_380 ( V_202 ) )
V_2 = F_138 ( V_8 -> V_28 , F_381 ( V_202 ) ) ;
else {
V_2 = F_138 ( V_8 -> V_104 , F_381 ( V_202 ) ) ;
if ( ! V_2 )
return false ;
}
return F_373 ( V_8 , V_2 ) ;
}
static int T_6 F_382 ( void )
{
F_383 ( V_250 , L_5 , NULL ,
F_264 ) ;
return 0 ;
}
