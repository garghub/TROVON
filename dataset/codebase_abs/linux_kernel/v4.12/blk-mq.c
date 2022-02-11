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
struct V_7 * V_8 ;
unsigned int V_21 ;
bool V_22 = false ;
F_31 ( V_15 , true ) ;
F_32 (q, hctx, i) {
if ( V_8 -> V_23 & V_24 )
F_33 ( & V_8 -> V_25 ) ;
else
V_22 = true ;
}
if ( V_22 )
F_34 () ;
}
void F_35 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
unsigned int V_21 ;
F_32 (q, hctx, i)
if ( F_36 ( V_8 ) )
F_37 ( V_8 -> V_26 , true ) ;
F_29 ( & V_15 -> V_19 ) ;
}
bool F_38 ( struct V_7 * V_8 )
{
return F_39 ( V_8 -> V_26 ) ;
}
void F_40 ( struct V_14 * V_15 , struct V_11 * V_12 ,
struct V_1 * V_2 , unsigned int V_27 )
{
F_41 ( & V_2 -> V_28 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_29 = V_12 ;
V_2 -> V_30 = V_27 ;
if ( F_42 ( V_15 ) )
V_2 -> V_31 |= V_32 ;
V_2 -> V_33 = - 1 ;
F_43 ( & V_2 -> V_34 ) ;
F_44 ( & V_2 -> V_35 ) ;
V_2 -> V_36 = NULL ;
V_2 -> V_37 = NULL ;
V_2 -> V_38 = V_39 ;
#ifdef F_45
V_2 -> V_40 = NULL ;
F_46 ( V_2 ) ;
V_2 -> V_41 = 0 ;
#endif
V_2 -> V_42 = 0 ;
#if F_47 ( V_43 )
V_2 -> V_44 = 0 ;
#endif
V_2 -> V_45 = NULL ;
V_2 -> V_46 = 0 ;
F_41 ( & V_2 -> V_47 ) ;
V_2 -> V_20 = 0 ;
V_2 -> V_48 = NULL ;
V_2 -> V_49 = NULL ;
V_2 -> V_50 = NULL ;
V_12 -> V_51 [ F_48 ( V_27 ) ] ++ ;
}
struct V_1 * F_49 ( struct V_52 * V_53 ,
unsigned int V_27 )
{
struct V_1 * V_2 ;
unsigned int V_54 ;
V_54 = F_50 ( V_53 ) ;
if ( V_54 != V_55 ) {
struct V_56 * V_26 = F_51 ( V_53 ) ;
V_2 = V_26 -> V_57 [ V_54 ] ;
if ( V_53 -> V_23 & V_58 ) {
V_2 -> V_54 = - 1 ;
V_2 -> V_59 = V_54 ;
} else {
if ( F_52 ( V_53 -> V_8 ) ) {
V_2 -> V_31 = V_60 ;
F_53 ( & V_53 -> V_8 -> V_61 ) ;
}
V_2 -> V_54 = V_54 ;
V_2 -> V_59 = - 1 ;
V_53 -> V_8 -> V_26 -> V_62 [ V_2 -> V_54 ] = V_2 ;
}
F_40 ( V_53 -> V_15 , V_53 -> V_12 , V_2 , V_27 ) ;
return V_2 ;
}
return NULL ;
}
struct V_1 * F_54 ( struct V_14 * V_15 , int V_63 ,
unsigned int V_23 )
{
struct V_52 V_64 = { . V_23 = V_23 } ;
struct V_1 * V_2 ;
int V_65 ;
V_65 = F_55 ( V_15 , V_23 & V_66 ) ;
if ( V_65 )
return F_56 ( V_65 ) ;
V_2 = F_57 ( V_15 , NULL , V_63 , & V_64 ) ;
F_58 ( V_64 . V_12 ) ;
F_59 ( V_15 ) ;
if ( ! V_2 )
return F_56 ( - V_67 ) ;
V_2 -> V_68 = 0 ;
V_2 -> V_69 = ( V_70 ) - 1 ;
V_2 -> V_71 = V_2 -> V_72 = NULL ;
return V_2 ;
}
struct V_1 * F_60 ( struct V_14 * V_15 , int V_63 ,
unsigned int V_23 , unsigned int V_73 )
{
struct V_52 V_64 = { . V_23 = V_23 } ;
struct V_1 * V_2 ;
unsigned int V_33 ;
int V_65 ;
if ( F_27 ( ! ( V_23 & V_66 ) ) )
return F_56 ( - V_74 ) ;
if ( V_73 >= V_15 -> V_75 )
return F_56 ( - V_76 ) ;
V_65 = F_55 ( V_15 , true ) ;
if ( V_65 )
return F_56 ( V_65 ) ;
V_64 . V_8 = V_15 -> V_77 [ V_73 ] ;
if ( ! F_36 ( V_64 . V_8 ) ) {
F_59 ( V_15 ) ;
return F_56 ( - V_78 ) ;
}
V_33 = F_61 ( V_64 . V_8 -> V_79 ) ;
V_64 . V_12 = F_62 ( V_15 , V_33 ) ;
V_2 = F_57 ( V_15 , NULL , V_63 , & V_64 ) ;
F_59 ( V_15 ) ;
if ( ! V_2 )
return F_56 ( - V_67 ) ;
return V_2 ;
}
void F_63 ( struct V_7 * V_8 , struct V_11 * V_12 ,
struct V_1 * V_2 )
{
const int V_80 = V_2 -> V_59 ;
struct V_14 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_31 & V_60 )
F_64 ( & V_8 -> V_61 ) ;
F_65 ( V_15 -> V_81 , & V_2 -> V_82 ) ;
V_2 -> V_31 = 0 ;
F_66 ( V_83 , & V_2 -> V_84 ) ;
F_66 ( V_85 , & V_2 -> V_84 ) ;
if ( V_2 -> V_54 != - 1 )
F_67 ( V_8 , V_8 -> V_26 , V_12 , V_2 -> V_54 ) ;
if ( V_80 != - 1 )
F_67 ( V_8 , V_8 -> V_86 , V_12 , V_80 ) ;
F_68 ( V_8 ) ;
F_59 ( V_15 ) ;
}
static void F_69 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_29 ;
V_12 -> V_87 [ F_70 ( V_2 ) ] ++ ;
F_63 ( V_8 , V_12 , V_2 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
F_69 ( F_72 ( V_2 -> V_15 , V_2 -> V_29 -> V_33 ) , V_2 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
F_74 ( V_2 ) ;
}
inline void F_75 ( struct V_1 * V_2 , int error )
{
F_76 ( V_2 ) ;
if ( V_2 -> V_48 ) {
F_65 ( V_2 -> V_15 -> V_81 , & V_2 -> V_82 ) ;
V_2 -> V_48 ( V_2 , error ) ;
} else {
if ( F_77 ( F_78 ( V_2 ) ) )
F_73 ( V_2 -> V_50 ) ;
F_73 ( V_2 ) ;
}
}
void F_79 ( struct V_1 * V_2 , int error )
{
if ( F_80 ( V_2 , error , F_3 ( V_2 ) ) )
F_81 () ;
F_75 ( V_2 , error ) ;
}
static void F_82 ( void * V_53 )
{
struct V_1 * V_2 = V_53 ;
V_2 -> V_15 -> V_88 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_29 ;
bool V_89 = false ;
int V_33 ;
if ( V_2 -> V_59 != - 1 )
F_84 ( V_2 ) ;
if ( V_2 -> V_31 & V_90 ) {
F_85 ( V_2 -> V_15 ) ;
F_86 ( V_2 ) ;
}
if ( ! F_87 ( V_91 , & V_2 -> V_15 -> V_92 ) ) {
V_2 -> V_15 -> V_88 ( V_2 ) ;
return;
}
V_33 = F_88 () ;
if ( ! F_87 ( V_93 , & V_2 -> V_15 -> V_92 ) )
V_89 = F_89 ( V_33 , V_12 -> V_33 ) ;
if ( V_33 != V_12 -> V_33 && ! V_89 && F_90 ( V_12 -> V_33 ) ) {
V_2 -> V_94 . V_95 = F_82 ;
V_2 -> V_94 . V_96 = V_2 ;
V_2 -> V_94 . V_23 = 0 ;
F_91 ( V_12 -> V_33 , & V_2 -> V_94 ) ;
} else {
V_2 -> V_15 -> V_88 ( V_2 ) ;
}
F_92 () ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( F_77 ( F_94 ( V_15 ) ) )
return;
if ( ! F_95 ( V_2 ) )
F_83 ( V_2 ) ;
}
int F_96 ( struct V_1 * V_2 )
{
return F_87 ( V_83 , & V_2 -> V_84 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_98 ( V_2 ) ;
F_99 ( V_15 , V_2 ) ;
if ( F_87 ( V_97 , & V_15 -> V_92 ) ) {
F_100 ( & V_2 -> V_82 , F_101 ( V_2 ) ) ;
V_2 -> V_31 |= V_90 ;
F_102 ( V_15 -> V_81 , & V_2 -> V_82 ) ;
}
F_103 ( V_2 ) ;
F_104 () ;
if ( ! F_87 ( V_83 , & V_2 -> V_84 ) )
F_105 ( V_83 , & V_2 -> V_84 ) ;
if ( F_87 ( V_98 , & V_2 -> V_84 ) )
F_66 ( V_98 , & V_2 -> V_84 ) ;
if ( V_15 -> V_99 && F_3 ( V_2 ) ) {
V_2 -> V_42 ++ ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
F_107 ( V_15 , V_2 ) ;
F_108 ( V_15 -> V_81 , & V_2 -> V_82 ) ;
F_109 ( V_2 ) ;
if ( F_110 ( V_83 , & V_2 -> V_84 ) ) {
if ( V_15 -> V_99 && F_3 ( V_2 ) )
V_2 -> V_42 -- ;
}
}
void F_111 ( struct V_1 * V_2 , bool V_100 )
{
F_106 ( V_2 ) ;
F_112 ( F_113 ( V_2 ) ) ;
F_114 ( V_2 , true , V_100 ) ;
}
static void F_115 ( struct V_101 * V_102 )
{
struct V_14 * V_15 =
F_116 ( V_102 , struct V_14 , V_103 . V_102 ) ;
F_117 ( V_104 ) ;
struct V_1 * V_2 , * V_105 ;
unsigned long V_23 ;
F_118 ( & V_15 -> V_106 , V_23 ) ;
F_119 ( & V_15 -> V_107 , & V_104 ) ;
F_120 ( & V_15 -> V_106 , V_23 ) ;
F_121 (rq, next, &rq_list, queuelist) {
if ( ! ( V_2 -> V_31 & V_108 ) )
continue;
V_2 -> V_31 &= ~ V_108 ;
F_122 ( & V_2 -> V_28 ) ;
F_123 ( V_2 , true , false , false , true ) ;
}
while ( ! F_124 ( & V_104 ) ) {
V_2 = F_125 ( V_104 . V_105 , struct V_1 , V_28 ) ;
F_122 ( & V_2 -> V_28 ) ;
F_123 ( V_2 , false , false , false , true ) ;
}
F_17 ( V_15 , false ) ;
}
void F_114 ( struct V_1 * V_2 , bool V_109 ,
bool V_100 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned long V_23 ;
F_112 ( V_2 -> V_31 & V_108 ) ;
F_118 ( & V_15 -> V_106 , V_23 ) ;
if ( V_109 ) {
V_2 -> V_31 |= V_108 ;
F_126 ( & V_2 -> V_28 , & V_15 -> V_107 ) ;
} else {
F_127 ( & V_2 -> V_28 , & V_15 -> V_107 ) ;
}
F_120 ( & V_15 -> V_106 , V_23 ) ;
if ( V_100 )
F_128 ( V_15 ) ;
}
void F_128 ( struct V_14 * V_15 )
{
F_129 ( & V_15 -> V_103 , 0 ) ;
}
void F_130 ( struct V_14 * V_15 ,
unsigned long V_110 )
{
F_129 ( & V_15 -> V_103 ,
F_131 ( V_110 ) ) ;
}
struct V_1 * F_132 ( struct V_56 * V_26 , unsigned int V_54 )
{
if ( V_54 < V_26 -> V_111 ) {
F_133 ( V_26 -> V_62 [ V_54 ] ) ;
return V_26 -> V_62 [ V_54 ] ;
}
return NULL ;
}
void F_134 ( struct V_1 * V_112 , bool V_113 )
{
const struct V_114 * V_115 = V_112 -> V_15 -> V_116 ;
enum V_117 V_65 = V_118 ;
if ( ! F_87 ( V_83 , & V_112 -> V_84 ) )
return;
if ( V_115 -> V_20 )
V_65 = V_115 -> V_20 ( V_112 , V_113 ) ;
switch ( V_65 ) {
case V_119 :
F_83 ( V_112 ) ;
break;
case V_118 :
F_103 ( V_112 ) ;
F_135 ( V_112 ) ;
break;
case V_120 :
break;
default:
F_136 ( V_121 L_1 , V_65 ) ;
break;
}
}
static void F_137 ( struct V_7 * V_8 ,
struct V_1 * V_2 , void * V_122 , bool V_113 )
{
struct V_123 * V_53 = V_122 ;
if ( ! F_87 ( V_83 , & V_2 -> V_84 ) )
return;
if ( F_138 ( V_39 , V_2 -> V_124 ) ) {
if ( ! F_95 ( V_2 ) )
F_134 ( V_2 , V_113 ) ;
} else if ( ! V_53 -> V_125 || F_139 ( V_53 -> V_105 , V_2 -> V_124 ) ) {
V_53 -> V_105 = V_2 -> V_124 ;
V_53 -> V_125 = 1 ;
}
}
static void F_140 ( struct V_101 * V_102 )
{
struct V_14 * V_15 =
F_116 ( V_102 , struct V_14 , V_126 ) ;
struct V_123 V_53 = {
. V_105 = 0 ,
. V_125 = 0 ,
} ;
int V_21 ;
if ( ! F_141 ( & V_15 -> V_18 ) )
return;
F_142 ( V_15 , F_137 , & V_53 ) ;
if ( V_53 . V_125 ) {
V_53 . V_105 = F_143 ( F_144 ( V_53 . V_105 ) ) ;
F_145 ( & V_15 -> V_20 , V_53 . V_105 ) ;
} else {
struct V_7 * V_8 ;
F_32 (q, hctx, i) {
if ( F_36 ( V_8 ) )
F_146 ( V_8 ) ;
}
}
F_59 ( V_15 ) ;
}
static bool F_147 ( struct V_14 * V_15 ,
struct V_11 * V_12 , struct V_71 * V_71 )
{
struct V_1 * V_2 ;
int V_127 = 8 ;
F_148 (rq, &ctx->rq_list, queuelist) {
bool V_128 = false ;
if ( ! V_127 -- )
break;
if ( ! F_149 ( V_2 , V_71 ) )
continue;
switch ( F_150 ( V_2 , V_71 ) ) {
case V_129 :
if ( F_151 ( V_15 , V_2 , V_71 ) )
V_128 = F_152 ( V_15 , V_2 , V_71 ) ;
break;
case V_130 :
if ( F_151 ( V_15 , V_2 , V_71 ) )
V_128 = F_153 ( V_15 , V_2 , V_71 ) ;
break;
case V_131 :
V_128 = F_154 ( V_15 , V_2 , V_71 ) ;
break;
default:
continue;
}
if ( V_128 )
V_12 -> V_132 ++ ;
return V_128 ;
}
return false ;
}
static bool F_155 ( struct V_133 * V_134 , unsigned int V_135 , void * V_53 )
{
struct V_136 * V_137 = V_53 ;
struct V_7 * V_8 = V_137 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_138 [ V_135 ] ;
F_13 ( V_134 , V_135 ) ;
F_156 ( & V_12 -> V_139 ) ;
F_157 ( & V_12 -> V_104 , V_137 -> V_140 ) ;
F_158 ( & V_12 -> V_139 ) ;
return true ;
}
void F_159 ( struct V_7 * V_8 , struct V_141 * V_140 )
{
struct V_136 V_53 = {
. V_8 = V_8 ,
. V_140 = V_140 ,
} ;
F_160 ( & V_8 -> V_9 , F_155 , & V_53 ) ;
}
static inline unsigned int F_161 ( unsigned int V_142 )
{
if ( ! V_142 )
return 0 ;
return F_162 ( V_143 - 1 , F_4 ( V_142 ) + 1 ) ;
}
bool F_163 ( struct V_1 * V_2 , struct V_7 * * V_8 ,
bool V_144 )
{
struct V_52 V_53 = {
. V_15 = V_2 -> V_15 ,
. V_8 = F_72 ( V_2 -> V_15 , V_2 -> V_29 -> V_33 ) ,
. V_23 = V_144 ? 0 : V_66 ,
} ;
F_164 ( V_144 ) ;
if ( V_2 -> V_54 != - 1 )
goto V_145;
if ( F_165 ( V_53 . V_8 -> V_86 , V_2 -> V_59 ) )
V_53 . V_23 |= V_146 ;
V_2 -> V_54 = F_50 ( & V_53 ) ;
if ( V_2 -> V_54 >= 0 ) {
if ( F_52 ( V_53 . V_8 ) ) {
V_2 -> V_31 |= V_60 ;
F_53 ( & V_53 . V_8 -> V_61 ) ;
}
V_53 . V_8 -> V_26 -> V_62 [ V_2 -> V_54 ] = V_2 ;
}
V_145:
if ( V_8 )
* V_8 = V_53 . V_8 ;
return V_2 -> V_54 != - 1 ;
}
static void F_166 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
F_67 ( V_8 , V_8 -> V_26 , V_2 -> V_29 , V_2 -> V_54 ) ;
V_2 -> V_54 = - 1 ;
if ( V_2 -> V_31 & V_60 ) {
V_2 -> V_31 &= ~ V_60 ;
F_64 ( & V_8 -> V_61 ) ;
}
}
static void F_167 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_54 == - 1 || V_2 -> V_59 == - 1 )
return;
F_166 ( V_8 , V_2 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
if ( V_2 -> V_54 == - 1 || V_2 -> V_59 == - 1 )
return;
V_8 = F_72 ( V_2 -> V_15 , V_2 -> V_29 -> V_33 ) ;
F_166 ( V_8 , V_2 ) ;
}
static bool F_169 ( struct V_141 * V_140 )
{
struct V_1 * V_2 , * V_147 , * V_148 = NULL ;
F_170 (rq, tmp, list, queuelist) {
if ( V_2 == V_148 )
break;
if ( V_2 -> V_54 != - 1 ) {
F_171 ( & V_2 -> V_28 , V_140 ) ;
if ( ! V_148 )
V_148 = V_2 ;
}
}
return V_148 != NULL ;
}
static int F_172 ( T_1 * V_144 , unsigned V_149 , int V_23 ,
void * V_150 )
{
struct V_7 * V_8 ;
V_8 = F_116 ( V_144 , struct V_7 , V_151 ) ;
F_173 ( & V_144 -> V_152 ) ;
F_174 ( V_153 , & V_8 -> V_154 ) ;
F_175 ( V_8 , true ) ;
return 1 ;
}
static bool F_176 ( struct V_7 * V_8 )
{
struct V_155 * V_156 ;
if ( F_87 ( V_153 , & V_8 -> V_154 ) ||
F_177 ( V_153 , & V_8 -> V_154 ) )
return false ;
F_178 ( & V_8 -> V_151 , F_172 ) ;
V_156 = F_179 ( & V_8 -> V_26 -> V_157 , V_8 ) ;
F_180 ( & V_156 -> V_144 , & V_8 -> V_151 ) ;
return true ;
}
bool F_181 ( struct V_14 * V_15 , struct V_141 * V_140 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_158 , V_142 , V_65 = V_159 ;
if ( F_124 ( V_140 ) )
return false ;
V_158 = V_142 = 0 ;
do {
struct V_160 V_161 ;
V_2 = F_182 ( V_140 , struct V_1 , V_28 ) ;
if ( ! F_163 ( V_2 , & V_8 , false ) ) {
if ( ! V_142 && F_169 ( V_140 ) )
continue;
if ( ! F_176 ( V_8 ) )
break;
if ( ! F_163 ( V_2 , & V_8 , false ) )
break;
}
F_122 ( & V_2 -> V_28 ) ;
V_161 . V_2 = V_2 ;
if ( F_124 ( V_140 ) )
V_161 . V_162 = true ;
else {
struct V_1 * V_163 ;
V_163 = F_182 ( V_140 , struct V_1 , V_28 ) ;
V_161 . V_162 = ! F_163 ( V_163 , NULL , false ) ;
}
V_65 = V_15 -> V_116 -> V_164 ( V_8 , & V_161 ) ;
switch ( V_65 ) {
case V_159 :
V_142 ++ ;
break;
case V_165 :
F_167 ( V_8 , V_2 ) ;
F_126 ( & V_2 -> V_28 , V_140 ) ;
F_106 ( V_2 ) ;
break;
default:
F_183 ( L_2 , V_65 ) ;
case V_166 :
V_158 ++ ;
F_79 ( V_2 , - V_76 ) ;
break;
}
if ( V_65 == V_165 )
break;
} while ( ! F_124 ( V_140 ) );
V_8 -> V_167 [ F_161 ( V_142 ) ] ++ ;
if ( ! F_124 ( V_140 ) ) {
V_2 = F_182 ( V_140 , struct V_1 , V_28 ) ;
F_168 ( V_2 ) ;
F_156 ( & V_8 -> V_139 ) ;
F_119 ( V_140 , & V_8 -> V_10 ) ;
F_158 ( & V_8 -> V_139 ) ;
if ( ! F_184 ( V_8 ) &&
! F_87 ( V_153 , & V_8 -> V_154 ) )
F_175 ( V_8 , true ) ;
}
return ( V_142 + V_158 ) != 0 ;
}
static void F_185 ( struct V_7 * V_8 )
{
int V_168 ;
F_186 ( ! F_187 ( F_188 () , V_8 -> V_79 ) &&
F_90 ( V_8 -> V_169 ) ) ;
if ( ! ( V_8 -> V_23 & V_24 ) ) {
F_189 () ;
F_190 ( V_8 ) ;
F_191 () ;
} else {
F_192 () ;
V_168 = F_193 ( & V_8 -> V_25 ) ;
F_190 ( V_8 ) ;
F_194 ( & V_8 -> V_25 , V_168 ) ;
}
}
static int F_195 ( struct V_7 * V_8 )
{
if ( V_8 -> V_170 -> V_75 == 1 )
return V_171 ;
if ( -- V_8 -> V_172 <= 0 ) {
int V_169 ;
V_169 = F_196 ( V_8 -> V_169 , V_8 -> V_79 ) ;
if ( V_169 >= V_173 )
V_169 = F_61 ( V_8 -> V_79 ) ;
V_8 -> V_169 = V_169 ;
V_8 -> V_172 = V_174 ;
}
return V_8 -> V_169 ;
}
static void F_197 ( struct V_7 * V_8 , bool V_175 ,
unsigned long V_110 )
{
if ( F_77 ( F_198 ( V_8 ) ||
! F_36 ( V_8 ) ) )
return;
if ( ! V_175 && ! ( V_8 -> V_23 & V_24 ) ) {
int V_33 = F_88 () ;
if ( F_187 ( V_33 , V_8 -> V_79 ) ) {
F_185 ( V_8 ) ;
F_92 () ;
return;
}
F_92 () ;
}
F_199 ( F_195 ( V_8 ) ,
& V_8 -> V_176 ,
F_131 ( V_110 ) ) ;
}
void F_200 ( struct V_7 * V_8 , unsigned long V_110 )
{
F_197 ( V_8 , true , V_110 ) ;
}
void F_175 ( struct V_7 * V_8 , bool V_175 )
{
F_197 ( V_8 , V_175 , 0 ) ;
}
void F_17 ( struct V_14 * V_15 , bool V_175 )
{
struct V_7 * V_8 ;
int V_21 ;
F_32 (q, hctx, i) {
if ( ! F_5 ( V_8 ) ||
F_198 ( V_8 ) )
continue;
F_175 ( V_8 , V_175 ) ;
}
}
bool F_201 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
int V_21 ;
F_32 (q, hctx, i)
if ( F_198 ( V_8 ) )
return true ;
return false ;
}
static void F_202 ( struct V_7 * V_8 , bool V_177 )
{
if ( V_177 )
F_203 ( & V_8 -> V_176 ) ;
else
F_204 ( & V_8 -> V_176 ) ;
F_105 ( V_178 , & V_8 -> V_154 ) ;
}
void F_205 ( struct V_7 * V_8 )
{
F_202 ( V_8 , false ) ;
}
static void F_31 ( struct V_14 * V_15 , bool V_177 )
{
struct V_7 * V_8 ;
int V_21 ;
F_32 (q, hctx, i)
F_202 ( V_8 , V_177 ) ;
}
void F_206 ( struct V_14 * V_15 )
{
F_31 ( V_15 , false ) ;
}
void F_207 ( struct V_7 * V_8 )
{
F_66 ( V_178 , & V_8 -> V_154 ) ;
F_175 ( V_8 , false ) ;
}
void F_208 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
int V_21 ;
F_32 (q, hctx, i)
F_207 ( V_8 ) ;
}
void F_209 ( struct V_7 * V_8 , bool V_175 )
{
if ( ! F_198 ( V_8 ) )
return;
F_66 ( V_178 , & V_8 -> V_154 ) ;
F_175 ( V_8 , V_175 ) ;
}
void F_210 ( struct V_14 * V_15 , bool V_175 )
{
struct V_7 * V_8 ;
int V_21 ;
F_32 (q, hctx, i)
F_209 ( V_8 , V_175 ) ;
}
static void F_211 ( struct V_101 * V_102 )
{
struct V_7 * V_8 ;
V_8 = F_116 ( V_102 , struct V_7 , V_176 . V_102 ) ;
if ( F_87 ( V_178 , & V_8 -> V_154 ) ) {
if ( ! F_87 ( V_179 , & V_8 -> V_154 ) )
return;
F_66 ( V_179 , & V_8 -> V_154 ) ;
F_66 ( V_178 , & V_8 -> V_154 ) ;
}
F_185 ( V_8 ) ;
}
void F_212 ( struct V_7 * V_8 , unsigned long V_110 )
{
if ( F_77 ( ! F_36 ( V_8 ) ) )
return;
F_205 ( V_8 ) ;
F_105 ( V_179 , & V_8 -> V_154 ) ;
F_213 ( F_195 ( V_8 ) ,
& V_8 -> V_176 ,
F_131 ( V_110 ) ) ;
}
static inline void F_214 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
bool V_109 )
{
struct V_11 * V_12 = V_2 -> V_29 ;
F_215 ( V_8 -> V_170 , V_2 ) ;
if ( V_109 )
F_126 ( & V_2 -> V_28 , & V_12 -> V_104 ) ;
else
F_127 ( & V_2 -> V_28 , & V_12 -> V_104 ) ;
}
void F_216 ( struct V_7 * V_8 , struct V_1 * V_2 ,
bool V_109 )
{
struct V_11 * V_12 = V_2 -> V_29 ;
F_214 ( V_8 , V_2 , V_109 ) ;
F_9 ( V_8 , V_12 ) ;
}
void F_217 ( struct V_7 * V_8 , struct V_11 * V_12 ,
struct V_141 * V_140 )
{
F_156 ( & V_12 -> V_139 ) ;
while ( ! F_124 ( V_140 ) ) {
struct V_1 * V_2 ;
V_2 = F_182 ( V_140 , struct V_1 , V_28 ) ;
F_112 ( V_2 -> V_29 != V_12 ) ;
F_122 ( & V_2 -> V_28 ) ;
F_214 ( V_8 , V_2 , false ) ;
}
F_9 ( V_8 , V_12 ) ;
F_158 ( & V_12 -> V_139 ) ;
}
static int F_218 ( void * V_122 , struct V_141 * V_180 , struct V_141 * V_181 )
{
struct V_1 * V_182 = F_116 ( V_180 , struct V_1 , V_28 ) ;
struct V_1 * V_183 = F_116 ( V_181 , struct V_1 , V_28 ) ;
return ! ( V_182 -> V_29 < V_183 -> V_29 ||
( V_182 -> V_29 == V_183 -> V_29 &&
F_219 ( V_182 ) < F_219 ( V_183 ) ) ) ;
}
void F_220 ( struct V_184 * V_185 , bool V_186 )
{
struct V_11 * V_187 ;
struct V_14 * V_188 ;
struct V_1 * V_2 ;
F_117 ( V_140 ) ;
F_117 ( V_189 ) ;
unsigned int V_190 ;
F_119 ( & V_185 -> V_191 , & V_140 ) ;
F_221 ( NULL , & V_140 , F_218 ) ;
V_188 = NULL ;
V_187 = NULL ;
V_190 = 0 ;
while ( ! F_124 ( & V_140 ) ) {
V_2 = F_222 ( V_140 . V_105 ) ;
F_122 ( & V_2 -> V_28 ) ;
F_112 ( ! V_2 -> V_15 ) ;
if ( V_2 -> V_29 != V_187 ) {
if ( V_187 ) {
F_223 ( V_188 , V_190 , V_186 ) ;
F_224 ( V_188 , V_187 ,
& V_189 ,
V_186 ) ;
}
V_187 = V_2 -> V_29 ;
V_188 = V_2 -> V_15 ;
V_190 = 0 ;
}
V_190 ++ ;
F_127 ( & V_2 -> V_28 , & V_189 ) ;
}
if ( V_187 ) {
F_223 ( V_188 , V_190 , V_186 ) ;
F_224 ( V_188 , V_187 , & V_189 ,
V_186 ) ;
}
}
static void F_225 ( struct V_1 * V_2 , struct V_71 * V_71 )
{
F_226 ( V_2 , V_71 ) ;
F_227 ( V_2 , true ) ;
}
static inline bool F_228 ( struct V_7 * V_8 )
{
return ( V_8 -> V_23 & V_192 ) &&
! F_229 ( V_8 -> V_170 ) ;
}
static inline bool F_230 ( struct V_7 * V_8 ,
struct V_11 * V_12 ,
struct V_1 * V_2 , struct V_71 * V_71 )
{
if ( ! F_228 ( V_8 ) || ! F_231 ( V_71 ) ) {
F_225 ( V_2 , V_71 ) ;
F_156 ( & V_12 -> V_139 ) ;
V_193:
F_216 ( V_8 , V_2 , false ) ;
F_158 ( & V_12 -> V_139 ) ;
return false ;
} else {
struct V_14 * V_15 = V_8 -> V_170 ;
F_156 ( & V_12 -> V_139 ) ;
if ( ! F_147 ( V_15 , V_12 , V_71 ) ) {
F_225 ( V_2 , V_71 ) ;
goto V_193;
}
F_158 ( & V_12 -> V_139 ) ;
F_63 ( V_8 , V_12 , V_2 ) ;
return true ;
}
}
static T_2 F_232 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( V_2 -> V_54 != - 1 )
return F_233 ( V_2 -> V_54 , V_8 -> V_194 , false ) ;
return F_233 ( V_2 -> V_59 , V_8 -> V_194 , true ) ;
}
static void F_234 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
T_2 * V_195 , bool V_196 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_160 V_161 = {
. V_2 = V_2 ,
. V_162 = true ,
} ;
T_2 V_197 ;
int V_65 ;
bool V_198 = true ;
if ( F_198 ( V_8 ) ) {
V_198 = false ;
goto V_199;
}
if ( V_15 -> V_200 )
goto V_199;
if ( ! F_163 ( V_2 , NULL , false ) )
goto V_199;
V_197 = F_232 ( V_8 , V_2 ) ;
V_65 = V_15 -> V_116 -> V_164 ( V_8 , & V_161 ) ;
if ( V_65 == V_159 ) {
* V_195 = V_197 ;
return;
}
if ( V_65 == V_166 ) {
* V_195 = V_201 ;
F_79 ( V_2 , - V_76 ) ;
return;
}
F_106 ( V_2 ) ;
V_199:
F_123 ( V_2 , false , V_198 , false , V_196 ) ;
}
static void F_235 ( struct V_7 * V_8 ,
struct V_1 * V_2 , T_2 * V_195 )
{
if ( ! ( V_8 -> V_23 & V_24 ) ) {
F_189 () ;
F_234 ( V_8 , V_2 , V_195 , false ) ;
F_191 () ;
} else {
unsigned int V_168 ;
F_192 () ;
V_168 = F_193 ( & V_8 -> V_25 ) ;
F_234 ( V_8 , V_2 , V_195 , true ) ;
F_194 ( & V_8 -> V_25 , V_168 ) ;
}
}
static T_2 F_236 ( struct V_14 * V_15 , struct V_71 * V_71 )
{
const int V_202 = F_48 ( V_71 -> V_203 ) ;
const int V_204 = F_237 ( V_71 -> V_203 ) ;
struct V_52 V_53 = { . V_23 = 0 } ;
struct V_1 * V_2 ;
unsigned int V_205 = 0 ;
struct V_184 * V_185 ;
struct V_1 * V_206 = NULL ;
T_2 V_195 ;
unsigned int V_207 ;
F_238 ( V_15 , & V_71 ) ;
F_239 ( V_15 , & V_71 , V_15 -> V_208 ) ;
if ( F_240 ( V_71 ) && F_241 ( V_71 ) ) {
F_242 ( V_71 ) ;
return V_201 ;
}
if ( ! V_204 && ! F_229 ( V_15 ) &&
F_243 ( V_15 , V_71 , & V_205 , & V_206 ) )
return V_201 ;
if ( F_244 ( V_15 , V_71 ) )
return V_201 ;
V_207 = F_245 ( V_15 -> V_81 , V_71 , NULL ) ;
F_246 ( V_15 , V_71 , V_71 -> V_203 ) ;
V_2 = F_57 ( V_15 , V_71 , V_71 -> V_203 , & V_53 ) ;
if ( F_77 ( ! V_2 ) ) {
F_247 ( V_15 -> V_81 , V_207 ) ;
return V_201 ;
}
F_248 ( & V_2 -> V_82 , V_207 ) ;
V_195 = F_232 ( V_53 . V_8 , V_2 ) ;
V_185 = V_209 -> V_185 ;
if ( F_77 ( V_204 ) ) {
F_58 ( V_53 . V_12 ) ;
F_225 ( V_2 , V_71 ) ;
if ( V_15 -> V_200 ) {
F_123 ( V_2 , false , true , true ,
true ) ;
} else {
F_249 ( V_2 ) ;
F_175 ( V_53 . V_8 , true ) ;
}
} else if ( V_185 && V_15 -> V_75 == 1 ) {
struct V_1 * V_162 = NULL ;
F_58 ( V_53 . V_12 ) ;
F_225 ( V_2 , V_71 ) ;
if ( F_124 ( & V_185 -> V_191 ) )
V_205 = 0 ;
else if ( F_229 ( V_15 ) )
V_205 = F_250 ( V_15 ) ;
if ( ! V_205 )
F_251 ( V_15 ) ;
else
V_162 = F_222 ( V_185 -> V_191 . V_210 ) ;
if ( V_205 >= V_211 || ( V_162 &&
F_3 ( V_162 ) >= V_212 ) ) {
F_252 ( V_185 , false ) ;
F_251 ( V_15 ) ;
}
F_127 ( & V_2 -> V_28 , & V_185 -> V_191 ) ;
} else if ( V_185 && ! F_229 ( V_15 ) ) {
F_225 ( V_2 , V_71 ) ;
if ( F_124 ( & V_185 -> V_191 ) )
V_206 = NULL ;
if ( V_206 )
F_122 ( & V_206 -> V_28 ) ;
F_127 ( & V_2 -> V_28 , & V_185 -> V_191 ) ;
F_58 ( V_53 . V_12 ) ;
if ( V_206 ) {
V_53 . V_8 = F_72 ( V_15 ,
V_206 -> V_29 -> V_33 ) ;
F_235 ( V_53 . V_8 , V_206 ,
& V_195 ) ;
}
} else if ( V_15 -> V_75 > 1 && V_202 ) {
F_58 ( V_53 . V_12 ) ;
F_225 ( V_2 , V_71 ) ;
F_235 ( V_53 . V_8 , V_2 , & V_195 ) ;
} else if ( V_15 -> V_200 ) {
F_58 ( V_53 . V_12 ) ;
F_225 ( V_2 , V_71 ) ;
F_123 ( V_2 , false , true , true , true ) ;
} else if ( ! F_230 ( V_53 . V_8 , V_53 . V_12 , V_2 , V_71 ) ) {
F_58 ( V_53 . V_12 ) ;
F_175 ( V_53 . V_8 , true ) ;
} else
F_58 ( V_53 . V_12 ) ;
return V_195 ;
}
void F_253 ( struct V_213 * V_214 , struct V_56 * V_26 ,
unsigned int V_73 )
{
struct V_215 * V_215 ;
if ( V_26 -> V_62 && V_214 -> V_115 -> V_216 ) {
int V_21 ;
for ( V_21 = 0 ; V_21 < V_26 -> V_111 ; V_21 ++ ) {
struct V_1 * V_2 = V_26 -> V_57 [ V_21 ] ;
if ( ! V_2 )
continue;
V_214 -> V_115 -> V_216 ( V_214 , V_2 , V_73 ) ;
V_26 -> V_57 [ V_21 ] = NULL ;
}
}
while ( ! F_124 ( & V_26 -> V_217 ) ) {
V_215 = F_182 ( & V_26 -> V_217 , struct V_215 , V_218 ) ;
F_122 ( & V_215 -> V_218 ) ;
F_254 ( F_255 ( V_215 ) ) ;
F_256 ( V_215 , V_215 -> V_219 ) ;
}
}
void F_257 ( struct V_56 * V_26 )
{
F_258 ( V_26 -> V_62 ) ;
V_26 -> V_62 = NULL ;
F_258 ( V_26 -> V_57 ) ;
V_26 -> V_57 = NULL ;
F_259 ( V_26 ) ;
}
struct V_56 * F_260 ( struct V_213 * V_214 ,
unsigned int V_73 ,
unsigned int V_111 ,
unsigned int V_220 )
{
struct V_56 * V_26 ;
int V_221 ;
V_221 = F_261 ( V_214 -> V_222 , V_73 ) ;
if ( V_221 == V_223 )
V_221 = V_214 -> V_224 ;
V_26 = F_262 ( V_111 , V_220 , V_221 ,
F_263 ( V_214 -> V_23 ) ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_62 = F_264 ( V_111 * sizeof( struct V_1 * ) ,
V_225 | V_226 | V_227 ,
V_221 ) ;
if ( ! V_26 -> V_62 ) {
F_259 ( V_26 ) ;
return NULL ;
}
V_26 -> V_57 = F_264 ( V_111 * sizeof( struct V_1 * ) ,
V_225 | V_226 | V_227 ,
V_221 ) ;
if ( ! V_26 -> V_57 ) {
F_258 ( V_26 -> V_62 ) ;
F_259 ( V_26 ) ;
return NULL ;
}
return V_26 ;
}
static T_3 F_265 ( unsigned int V_228 )
{
return ( T_3 ) V_229 << V_228 ;
}
int F_266 ( struct V_213 * V_214 , struct V_56 * V_26 ,
unsigned int V_73 , unsigned int V_190 )
{
unsigned int V_21 , V_230 , V_231 , V_232 = 4 ;
T_3 V_233 , V_234 ;
int V_221 ;
V_221 = F_261 ( V_214 -> V_222 , V_73 ) ;
if ( V_221 == V_223 )
V_221 = V_214 -> V_224 ;
F_41 ( & V_26 -> V_217 ) ;
V_233 = F_267 ( sizeof( struct V_1 ) + V_214 -> V_235 ,
F_268 () ) ;
V_234 = V_233 * V_190 ;
for ( V_21 = 0 ; V_21 < V_190 ; ) {
int V_236 = V_232 ;
struct V_215 * V_215 ;
int V_237 ;
void * V_238 ;
while ( V_236 && V_234 < F_265 ( V_236 - 1 ) )
V_236 -- ;
do {
V_215 = F_269 ( V_221 ,
V_225 | V_226 | V_227 | V_239 ,
V_236 ) ;
if ( V_215 )
break;
if ( ! V_236 -- )
break;
if ( F_265 ( V_236 ) < V_233 )
break;
} while ( 1 );
if ( ! V_215 )
goto V_240;
V_215 -> V_219 = V_236 ;
F_127 ( & V_215 -> V_218 , & V_26 -> V_217 ) ;
V_238 = F_255 ( V_215 ) ;
F_270 ( V_238 , F_265 ( V_236 ) , 1 , V_225 ) ;
V_231 = F_265 ( V_236 ) / V_233 ;
V_237 = F_162 ( V_231 , V_190 - V_21 ) ;
V_234 -= V_237 * V_233 ;
for ( V_230 = 0 ; V_230 < V_237 ; V_230 ++ ) {
struct V_1 * V_2 = V_238 ;
V_26 -> V_57 [ V_21 ] = V_2 ;
if ( V_214 -> V_115 -> V_241 ) {
if ( V_214 -> V_115 -> V_241 ( V_214 , V_2 , V_73 ,
V_221 ) ) {
V_26 -> V_57 [ V_21 ] = NULL ;
goto V_240;
}
}
V_238 += V_233 ;
V_21 ++ ;
}
}
return 0 ;
V_240:
F_253 ( V_214 , V_26 , V_73 ) ;
return - V_242 ;
}
static int F_271 ( unsigned int V_33 , struct V_243 * V_221 )
{
struct V_7 * V_8 ;
struct V_11 * V_12 ;
F_117 ( V_147 ) ;
V_8 = F_272 ( V_221 , struct V_7 , V_244 ) ;
V_12 = F_62 ( V_8 -> V_170 , V_33 ) ;
F_156 ( & V_12 -> V_139 ) ;
if ( ! F_124 ( & V_12 -> V_104 ) ) {
F_119 ( & V_12 -> V_104 , & V_147 ) ;
F_12 ( V_8 , V_12 ) ;
}
F_158 ( & V_12 -> V_139 ) ;
if ( F_124 ( & V_147 ) )
return 0 ;
F_156 ( & V_8 -> V_139 ) ;
F_157 ( & V_147 , & V_8 -> V_10 ) ;
F_158 ( & V_8 -> V_139 ) ;
F_175 ( V_8 , true ) ;
return 0 ;
}
static void F_273 ( struct V_7 * V_8 )
{
F_274 ( V_245 ,
& V_8 -> V_244 ) ;
}
static void F_275 ( struct V_14 * V_15 ,
struct V_213 * V_214 ,
struct V_7 * V_8 , unsigned int V_73 )
{
F_276 ( V_8 ) ;
F_146 ( V_8 ) ;
if ( V_214 -> V_115 -> V_216 )
V_214 -> V_115 -> V_216 ( V_214 , V_8 -> V_246 -> V_247 , V_73 ) ;
F_277 ( V_15 , V_8 , V_73 ) ;
if ( V_214 -> V_115 -> V_248 )
V_214 -> V_115 -> V_248 ( V_8 , V_73 ) ;
if ( V_8 -> V_23 & V_24 )
F_278 ( & V_8 -> V_25 ) ;
F_273 ( V_8 ) ;
F_279 ( V_8 -> V_246 ) ;
F_280 ( & V_8 -> V_9 ) ;
}
static void F_281 ( struct V_14 * V_15 ,
struct V_213 * V_214 , int V_249 )
{
struct V_7 * V_8 ;
unsigned int V_21 ;
F_32 (q, hctx, i) {
if ( V_21 == V_249 )
break;
F_275 ( V_15 , V_214 , V_8 , V_21 ) ;
}
}
static int F_282 ( struct V_14 * V_15 ,
struct V_213 * V_214 ,
struct V_7 * V_8 , unsigned V_73 )
{
int V_221 ;
V_221 = V_8 -> V_224 ;
if ( V_221 == V_223 )
V_221 = V_8 -> V_224 = V_214 -> V_224 ;
F_283 ( & V_8 -> V_176 , F_211 ) ;
F_284 ( & V_8 -> V_139 ) ;
F_41 ( & V_8 -> V_10 ) ;
V_8 -> V_170 = V_15 ;
V_8 -> V_194 = V_73 ;
V_8 -> V_23 = V_214 -> V_23 & ~ V_250 ;
F_285 ( V_245 , & V_8 -> V_244 ) ;
V_8 -> V_26 = V_214 -> V_26 [ V_73 ] ;
V_8 -> V_138 = F_286 ( V_173 * sizeof( void * ) ,
V_251 , V_221 ) ;
if ( ! V_8 -> V_138 )
goto V_252;
if ( F_287 ( & V_8 -> V_9 , V_173 , F_4 ( 8 ) , V_251 ,
V_221 ) )
goto V_253;
V_8 -> V_254 = 0 ;
if ( V_214 -> V_115 -> V_255 &&
V_214 -> V_115 -> V_255 ( V_8 , V_214 -> V_256 , V_73 ) )
goto V_257;
if ( F_288 ( V_15 , V_8 , V_73 ) )
goto V_248;
V_8 -> V_246 = F_289 ( V_15 , V_8 -> V_224 , V_214 -> V_235 ) ;
if ( ! V_8 -> V_246 )
goto V_258;
if ( V_214 -> V_115 -> V_241 &&
V_214 -> V_115 -> V_241 ( V_214 , V_8 -> V_246 -> V_247 , V_73 ,
V_221 ) )
goto V_259;
if ( V_8 -> V_23 & V_24 )
F_290 ( & V_8 -> V_25 ) ;
F_291 ( V_15 , V_8 ) ;
return 0 ;
V_259:
F_258 ( V_8 -> V_246 ) ;
V_258:
F_277 ( V_15 , V_8 , V_73 ) ;
V_248:
if ( V_214 -> V_115 -> V_248 )
V_214 -> V_115 -> V_248 ( V_8 , V_73 ) ;
V_257:
F_280 ( & V_8 -> V_9 ) ;
V_253:
F_258 ( V_8 -> V_138 ) ;
V_252:
F_273 ( V_8 ) ;
return - 1 ;
}
static void F_292 ( struct V_14 * V_15 ,
unsigned int V_75 )
{
unsigned int V_21 ;
F_293 (i) {
struct V_11 * V_260 = F_294 ( V_15 -> V_261 , V_21 ) ;
struct V_7 * V_8 ;
V_260 -> V_33 = V_21 ;
F_284 ( & V_260 -> V_139 ) ;
F_41 ( & V_260 -> V_104 ) ;
V_260 -> V_170 = V_15 ;
if ( ! F_90 ( V_21 ) )
continue;
V_8 = F_72 ( V_15 , V_21 ) ;
if ( V_75 > 1 && V_8 -> V_224 == V_223 )
V_8 -> V_224 = F_295 ( F_296 ( V_21 ) ) ;
}
}
static bool F_297 ( struct V_213 * V_214 , int V_73 )
{
int V_65 = 0 ;
V_214 -> V_26 [ V_73 ] = F_260 ( V_214 , V_73 ,
V_214 -> V_262 , V_214 -> V_220 ) ;
if ( ! V_214 -> V_26 [ V_73 ] )
return false ;
V_65 = F_266 ( V_214 , V_214 -> V_26 [ V_73 ] , V_73 ,
V_214 -> V_262 ) ;
if ( ! V_65 )
return true ;
F_257 ( V_214 -> V_26 [ V_73 ] ) ;
V_214 -> V_26 [ V_73 ] = NULL ;
return false ;
}
static void F_298 ( struct V_213 * V_214 ,
unsigned int V_73 )
{
if ( V_214 -> V_26 [ V_73 ] ) {
F_253 ( V_214 , V_214 -> V_26 [ V_73 ] , V_73 ) ;
F_257 ( V_214 -> V_26 [ V_73 ] ) ;
V_214 -> V_26 [ V_73 ] = NULL ;
}
}
static void F_299 ( struct V_14 * V_15 ,
const struct V_79 * V_263 )
{
unsigned int V_21 , V_73 ;
struct V_7 * V_8 ;
struct V_11 * V_12 ;
struct V_213 * V_214 = V_15 -> V_264 ;
F_300 ( & V_15 -> V_265 ) ;
F_32 (q, hctx, i) {
F_301 ( V_8 -> V_79 ) ;
V_8 -> V_254 = 0 ;
}
F_293 (i) {
if ( ! F_187 ( V_21 , V_263 ) )
continue;
V_73 = V_15 -> V_222 [ V_21 ] ;
if ( ! V_214 -> V_26 [ V_73 ] &&
! F_297 ( V_214 , V_73 ) ) {
V_15 -> V_222 [ V_21 ] = 0 ;
}
V_12 = F_294 ( V_15 -> V_261 , V_21 ) ;
V_8 = F_72 ( V_15 , V_21 ) ;
F_302 ( V_21 , V_8 -> V_79 ) ;
V_12 -> V_13 = V_8 -> V_254 ;
V_8 -> V_138 [ V_8 -> V_254 ++ ] = V_12 ;
}
F_303 ( & V_15 -> V_265 ) ;
F_32 (q, hctx, i) {
if ( ! V_8 -> V_254 ) {
if ( V_21 && V_214 -> V_26 [ V_21 ] )
F_298 ( V_214 , V_21 ) ;
V_8 -> V_26 = NULL ;
continue;
}
V_8 -> V_26 = V_214 -> V_26 [ V_21 ] ;
F_186 ( ! V_8 -> V_26 ) ;
F_304 ( & V_8 -> V_9 , V_8 -> V_254 ) ;
V_8 -> V_169 = F_61 ( V_8 -> V_79 ) ;
V_8 -> V_172 = V_174 ;
}
}
static void F_305 ( struct V_14 * V_15 , bool V_89 )
{
struct V_7 * V_8 ;
int V_21 ;
F_32 (q, hctx, i) {
if ( V_89 ) {
if ( F_87 ( V_266 , & V_8 -> V_154 ) )
F_53 ( & V_15 -> V_267 ) ;
V_8 -> V_23 |= V_250 ;
} else {
if ( F_87 ( V_266 , & V_8 -> V_154 ) )
F_64 ( & V_15 -> V_267 ) ;
V_8 -> V_23 &= ~ V_250 ;
}
}
}
static void F_306 ( struct V_213 * V_214 ,
bool V_89 )
{
struct V_14 * V_15 ;
F_307 ( & V_214 -> V_268 ) ;
F_308 (q, &set->tag_list, tag_set_list) {
F_24 ( V_15 ) ;
F_305 ( V_15 , V_89 ) ;
F_25 ( V_15 ) ;
}
}
static void F_309 ( struct V_14 * V_15 )
{
struct V_213 * V_214 = V_15 -> V_264 ;
F_300 ( & V_214 -> V_268 ) ;
F_310 ( & V_15 -> V_269 ) ;
F_41 ( & V_15 -> V_269 ) ;
if ( F_311 ( & V_214 -> V_270 ) ) {
V_214 -> V_23 &= ~ V_250 ;
F_306 ( V_214 , false ) ;
}
F_303 ( & V_214 -> V_268 ) ;
F_34 () ;
}
static void F_312 ( struct V_213 * V_214 ,
struct V_14 * V_15 )
{
V_15 -> V_264 = V_214 ;
F_300 ( & V_214 -> V_268 ) ;
if ( ! F_124 ( & V_214 -> V_270 ) && ! ( V_214 -> V_23 & V_250 ) ) {
V_214 -> V_23 |= V_250 ;
F_306 ( V_214 , true ) ;
}
if ( V_214 -> V_23 & V_250 )
F_305 ( V_15 , true ) ;
F_313 ( & V_15 -> V_269 , & V_214 -> V_270 ) ;
F_303 ( & V_214 -> V_268 ) ;
}
void F_314 ( struct V_14 * V_15 )
{
struct V_7 * V_8 ;
unsigned int V_21 ;
F_32 (q, hctx, i) {
if ( ! V_8 )
continue;
F_315 ( & V_8 -> V_271 ) ;
}
V_15 -> V_222 = NULL ;
F_258 ( V_15 -> V_77 ) ;
F_316 ( V_15 ) ;
F_317 ( V_15 -> V_261 ) ;
}
struct V_14 * F_318 ( struct V_213 * V_214 )
{
struct V_14 * V_272 , * V_15 ;
V_272 = F_319 ( V_251 , V_214 -> V_224 ) ;
if ( ! V_272 )
return F_56 ( - V_242 ) ;
V_15 = F_320 ( V_214 , V_272 ) ;
if ( F_321 ( V_15 ) )
F_322 ( V_272 ) ;
return V_15 ;
}
static void F_323 ( struct V_213 * V_214 ,
struct V_14 * V_15 )
{
int V_21 , V_230 ;
struct V_7 * * V_273 = V_15 -> V_77 ;
F_324 ( V_15 ) ;
for ( V_21 = 0 ; V_21 < V_214 -> V_75 ; V_21 ++ ) {
int V_221 ;
if ( V_273 [ V_21 ] )
continue;
V_221 = F_261 ( V_15 -> V_222 , V_21 ) ;
V_273 [ V_21 ] = F_264 ( sizeof( struct V_7 ) ,
V_251 , V_221 ) ;
if ( ! V_273 [ V_21 ] )
break;
if ( ! F_325 ( & V_273 [ V_21 ] -> V_79 , V_251 ,
V_221 ) ) {
F_258 ( V_273 [ V_21 ] ) ;
V_273 [ V_21 ] = NULL ;
break;
}
F_326 ( & V_273 [ V_21 ] -> V_61 , 0 ) ;
V_273 [ V_21 ] -> V_224 = V_221 ;
V_273 [ V_21 ] -> V_194 = V_21 ;
if ( F_282 ( V_15 , V_214 , V_273 [ V_21 ] , V_21 ) ) {
F_327 ( V_273 [ V_21 ] -> V_79 ) ;
F_258 ( V_273 [ V_21 ] ) ;
V_273 [ V_21 ] = NULL ;
break;
}
F_328 ( V_273 [ V_21 ] ) ;
}
for ( V_230 = V_21 ; V_230 < V_15 -> V_75 ; V_230 ++ ) {
struct V_7 * V_8 = V_273 [ V_230 ] ;
if ( V_8 ) {
if ( V_8 -> V_26 )
F_298 ( V_214 , V_230 ) ;
F_275 ( V_15 , V_214 , V_8 , V_230 ) ;
F_315 ( & V_8 -> V_271 ) ;
V_273 [ V_230 ] = NULL ;
}
}
V_15 -> V_75 = V_21 ;
F_329 ( V_15 ) ;
}
struct V_14 * F_320 ( struct V_213 * V_214 ,
struct V_14 * V_15 )
{
V_15 -> V_116 = V_214 -> V_115 ;
V_15 -> V_274 = F_330 ( V_275 ,
F_1 ,
V_6 , V_15 ) ;
if ( ! V_15 -> V_274 )
goto V_276;
V_15 -> V_261 = F_331 ( struct V_11 ) ;
if ( ! V_15 -> V_261 )
goto V_276;
F_332 ( V_15 ) ;
V_15 -> V_77 = F_264 ( V_173 * sizeof( * ( V_15 -> V_77 ) ) ,
V_251 , V_214 -> V_224 ) ;
if ( ! V_15 -> V_77 )
goto V_277;
V_15 -> V_222 = V_214 -> V_222 ;
F_323 ( V_214 , V_15 ) ;
if ( ! V_15 -> V_75 )
goto V_278;
F_333 ( & V_15 -> V_126 , F_140 ) ;
F_334 ( V_15 , V_214 -> V_20 ? V_214 -> V_20 : 30 * V_279 ) ;
V_15 -> V_280 = V_173 ;
V_15 -> V_92 |= V_281 ;
if ( ! ( V_214 -> V_23 & V_282 ) )
V_15 -> V_92 |= 1 << V_283 ;
V_15 -> V_284 = V_285 ;
F_283 ( & V_15 -> V_103 , F_115 ) ;
F_41 ( & V_15 -> V_107 ) ;
F_284 ( & V_15 -> V_106 ) ;
F_335 ( V_15 , F_236 ) ;
V_15 -> V_286 = V_214 -> V_262 ;
V_15 -> V_287 = - 1 ;
if ( V_214 -> V_115 -> V_288 )
F_336 ( V_15 , V_214 -> V_115 -> V_288 ) ;
F_292 ( V_15 , V_214 -> V_75 ) ;
F_337 () ;
F_300 ( & V_289 ) ;
F_127 ( & V_15 -> V_290 , & V_291 ) ;
F_312 ( V_214 , V_15 ) ;
F_299 ( V_15 , V_292 ) ;
F_303 ( & V_289 ) ;
F_338 () ;
if ( ! ( V_214 -> V_23 & V_293 ) ) {
int V_65 ;
V_65 = F_339 ( V_15 ) ;
if ( V_65 )
return F_56 ( V_65 ) ;
}
return V_15 ;
V_278:
F_258 ( V_15 -> V_77 ) ;
V_277:
F_317 ( V_15 -> V_261 ) ;
V_276:
V_15 -> V_116 = NULL ;
return F_56 ( - V_242 ) ;
}
void F_340 ( struct V_14 * V_15 )
{
struct V_213 * V_214 = V_15 -> V_264 ;
F_300 ( & V_289 ) ;
F_122 ( & V_15 -> V_290 ) ;
F_303 ( & V_289 ) ;
F_309 ( V_15 ) ;
F_281 ( V_15 , V_214 , V_214 -> V_75 ) ;
}
static void F_341 ( struct V_14 * V_15 ,
const struct V_79 * V_263 )
{
F_27 ( ! F_342 ( & V_15 -> V_17 ) ) ;
F_343 ( V_15 ) ;
F_324 ( V_15 ) ;
F_299 ( V_15 , V_263 ) ;
F_329 ( V_15 ) ;
F_344 ( V_15 ) ;
}
static void F_345 ( void )
{
struct V_14 * V_15 ;
F_300 ( & V_289 ) ;
F_308 (q, &all_q_list, all_q_node)
F_14 ( V_15 ) ;
F_308 (q, &all_q_list, all_q_node)
F_18 ( V_15 ) ;
F_308 (q, &all_q_list, all_q_node)
F_341 ( V_15 , & V_294 ) ;
F_308 (q, &all_q_list, all_q_node)
F_25 ( V_15 ) ;
F_303 ( & V_289 ) ;
}
static int F_346 ( unsigned int V_33 )
{
F_347 ( & V_294 , V_292 ) ;
F_345 () ;
return 0 ;
}
static int F_348 ( unsigned int V_33 )
{
F_347 ( & V_294 , V_292 ) ;
F_302 ( V_33 , & V_294 ) ;
F_345 () ;
return 0 ;
}
static int F_349 ( struct V_213 * V_214 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_214 -> V_75 ; V_21 ++ )
if ( ! F_297 ( V_214 , V_21 ) )
goto V_295;
return 0 ;
V_295:
while ( -- V_21 >= 0 )
F_257 ( V_214 -> V_26 [ V_21 ] ) ;
return - V_242 ;
}
static int F_350 ( struct V_213 * V_214 )
{
unsigned int V_190 ;
int V_296 ;
V_190 = V_214 -> V_262 ;
do {
V_296 = F_349 ( V_214 ) ;
if ( ! V_296 )
break;
V_214 -> V_262 >>= 1 ;
if ( V_214 -> V_262 < V_214 -> V_220 + V_297 ) {
V_296 = - V_242 ;
break;
}
} while ( V_214 -> V_262 );
if ( ! V_214 -> V_262 || V_296 ) {
F_183 ( L_3 ) ;
return - V_242 ;
}
if ( V_190 != V_214 -> V_262 )
F_351 ( L_4 ,
V_190 , V_214 -> V_262 ) ;
return 0 ;
}
static int F_352 ( struct V_213 * V_214 )
{
if ( V_214 -> V_115 -> V_298 )
return V_214 -> V_115 -> V_298 ( V_214 ) ;
else
return F_353 ( V_214 ) ;
}
int F_354 ( struct V_213 * V_214 )
{
int V_65 ;
F_355 ( V_299 > 1 << V_300 ) ;
if ( ! V_214 -> V_75 )
return - V_74 ;
if ( ! V_214 -> V_262 )
return - V_74 ;
if ( V_214 -> V_262 < V_214 -> V_220 + V_297 )
return - V_74 ;
if ( ! V_214 -> V_115 -> V_164 )
return - V_74 ;
if ( V_214 -> V_262 > V_299 ) {
F_351 ( L_5 ,
V_299 ) ;
V_214 -> V_262 = V_299 ;
}
if ( F_356 () ) {
V_214 -> V_75 = 1 ;
V_214 -> V_262 = F_162 ( 64U , V_214 -> V_262 ) ;
}
if ( V_214 -> V_75 > V_173 )
V_214 -> V_75 = V_173 ;
V_214 -> V_26 = F_264 ( V_173 * sizeof( struct V_56 * ) ,
V_251 , V_214 -> V_224 ) ;
if ( ! V_214 -> V_26 )
return - V_242 ;
V_65 = - V_242 ;
V_214 -> V_222 = F_264 ( sizeof( * V_214 -> V_222 ) * V_173 ,
V_251 , V_214 -> V_224 ) ;
if ( ! V_214 -> V_222 )
goto V_301;
V_65 = F_352 ( V_214 ) ;
if ( V_65 )
goto V_302;
V_65 = F_350 ( V_214 ) ;
if ( V_65 )
goto V_302;
F_357 ( & V_214 -> V_268 ) ;
F_41 ( & V_214 -> V_270 ) ;
return 0 ;
V_302:
F_258 ( V_214 -> V_222 ) ;
V_214 -> V_222 = NULL ;
V_301:
F_258 ( V_214 -> V_26 ) ;
V_214 -> V_26 = NULL ;
return V_65 ;
}
void F_358 ( struct V_213 * V_214 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_173 ; V_21 ++ )
F_298 ( V_214 , V_21 ) ;
F_258 ( V_214 -> V_222 ) ;
V_214 -> V_222 = NULL ;
F_258 ( V_214 -> V_26 ) ;
V_214 -> V_26 = NULL ;
}
int F_359 ( struct V_14 * V_15 , unsigned int V_303 )
{
struct V_213 * V_214 = V_15 -> V_264 ;
struct V_7 * V_8 ;
int V_21 , V_65 ;
if ( ! V_214 )
return - V_74 ;
F_24 ( V_15 ) ;
V_65 = 0 ;
F_32 (q, hctx, i) {
if ( ! V_8 -> V_26 )
continue;
if ( ! V_8 -> V_86 ) {
V_65 = F_360 ( V_8 , & V_8 -> V_26 ,
F_162 ( V_303 , V_214 -> V_262 ) ,
false ) ;
} else {
V_65 = F_360 ( V_8 , & V_8 -> V_86 ,
V_303 , true ) ;
}
if ( V_65 )
break;
}
if ( ! V_65 )
V_15 -> V_286 = V_303 ;
F_25 ( V_15 ) ;
return V_65 ;
}
static void F_361 ( struct V_213 * V_214 ,
int V_75 )
{
struct V_14 * V_15 ;
F_307 ( & V_214 -> V_268 ) ;
if ( V_75 > V_173 )
V_75 = V_173 ;
if ( V_75 < 1 || V_75 == V_214 -> V_75 )
return;
F_308 (q, &set->tag_list, tag_set_list)
F_24 ( V_15 ) ;
V_214 -> V_75 = V_75 ;
F_352 ( V_214 ) ;
F_308 (q, &set->tag_list, tag_set_list) {
F_323 ( V_214 , V_15 ) ;
F_341 ( V_15 , V_292 ) ;
}
F_308 (q, &set->tag_list, tag_set_list)
F_25 ( V_15 ) ;
}
void F_362 ( struct V_213 * V_214 , int V_75 )
{
F_300 ( & V_214 -> V_268 ) ;
F_361 ( V_214 , V_75 ) ;
F_303 ( & V_214 -> V_268 ) ;
}
static bool F_363 ( struct V_14 * V_15 )
{
if ( F_87 ( V_304 , & V_15 -> V_92 ) ||
F_364 ( V_304 , & V_15 -> V_92 ) )
return true ;
F_365 ( V_15 , V_15 -> V_274 ) ;
return false ;
}
static void F_85 ( struct V_14 * V_15 )
{
if ( ! F_87 ( V_304 , & V_15 -> V_92 ) ||
F_366 ( V_15 -> V_274 ) )
return;
F_367 ( V_15 -> V_274 , 100 ) ;
}
static void V_275 ( struct V_305 * V_306 )
{
struct V_14 * V_15 = V_306 -> V_53 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_306 -> V_307 [ V_5 ] . V_308 )
V_15 -> V_309 [ V_5 ] = V_306 -> V_307 [ V_5 ] ;
}
}
static unsigned long F_368 ( struct V_14 * V_15 ,
struct V_7 * V_8 ,
struct V_1 * V_2 )
{
unsigned long V_65 = 0 ;
int V_5 ;
if ( ! F_363 ( V_15 ) )
return 0 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_65 ;
if ( V_15 -> V_309 [ V_5 ] . V_308 )
V_65 = ( V_15 -> V_309 [ V_5 ] . V_310 + 1 ) / 2 ;
return V_65 ;
}
static bool F_369 ( struct V_14 * V_15 ,
struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_311 V_312 ;
enum V_313 V_149 ;
unsigned int V_314 ;
T_4 V_315 ;
if ( F_87 ( V_85 , & V_2 -> V_84 ) )
return false ;
if ( V_15 -> V_287 == - 1 )
return false ;
else if ( V_15 -> V_287 > 0 )
V_314 = V_15 -> V_287 ;
else
V_314 = F_368 ( V_15 , V_8 , V_2 ) ;
if ( ! V_314 )
return false ;
F_105 ( V_85 , & V_2 -> V_84 ) ;
V_315 = V_314 ;
V_149 = V_316 ;
F_370 ( & V_312 . V_317 , V_318 , V_149 ) ;
F_371 ( & V_312 . V_317 , V_315 ) ;
F_372 ( & V_312 , V_209 ) ;
do {
if ( F_87 ( V_98 , & V_2 -> V_84 ) )
break;
F_373 ( V_319 ) ;
F_374 ( & V_312 . V_317 , V_149 ) ;
if ( V_312 . V_320 )
F_375 () ;
F_376 ( & V_312 . V_317 ) ;
V_149 = V_321 ;
} while ( V_312 . V_320 && ! F_377 ( V_209 ) );
F_378 ( V_322 ) ;
F_379 ( & V_312 . V_317 ) ;
return true ;
}
static bool F_380 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_14 * V_15 = V_8 -> V_170 ;
long V_154 ;
if ( F_369 ( V_15 , V_8 , V_2 ) )
return true ;
V_8 -> V_323 ++ ;
V_154 = V_209 -> V_154 ;
while ( ! F_381 () ) {
int V_65 ;
V_8 -> V_324 ++ ;
V_65 = V_15 -> V_116 -> V_325 ( V_8 , V_2 -> V_54 ) ;
if ( V_65 > 0 ) {
V_8 -> V_326 ++ ;
F_373 ( V_322 ) ;
return true ;
}
if ( F_382 ( V_154 , V_209 ) )
F_373 ( V_322 ) ;
if ( V_209 -> V_154 == V_322 )
return true ;
if ( V_65 < 0 )
break;
F_383 () ;
}
return false ;
}
bool F_384 ( struct V_14 * V_15 , T_2 V_195 )
{
struct V_7 * V_8 ;
struct V_184 * V_185 ;
struct V_1 * V_2 ;
if ( ! V_15 -> V_116 || ! V_15 -> V_116 -> V_325 || ! F_385 ( V_195 ) ||
! F_87 ( V_327 , & V_15 -> V_92 ) )
return false ;
V_185 = V_209 -> V_185 ;
if ( V_185 )
F_252 ( V_185 , false ) ;
V_8 = V_15 -> V_77 [ F_386 ( V_195 ) ] ;
if ( ! F_387 ( V_195 ) )
V_2 = F_132 ( V_8 -> V_26 , F_388 ( V_195 ) ) ;
else {
V_2 = F_132 ( V_8 -> V_86 , F_388 ( V_195 ) ) ;
if ( ! V_2 )
return false ;
}
return F_380 ( V_8 , V_2 ) ;
}
void F_389 ( void )
{
F_300 ( & V_289 ) ;
}
void F_390 ( void )
{
F_303 ( & V_289 ) ;
}
static int T_5 F_391 ( void )
{
F_392 ( V_245 , L_6 , NULL ,
F_271 ) ;
F_393 ( V_328 , L_7 ,
F_348 ,
F_346 ) ;
return 0 ;
}
