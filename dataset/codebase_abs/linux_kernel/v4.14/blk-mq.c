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
static void F_14 ( struct V_7 * V_8 ,
struct V_1 * V_2 , void * V_14 ,
bool V_15 )
{
struct V_16 * V_17 = V_14 ;
if ( F_15 ( V_18 , & V_2 -> V_19 ) &&
! F_15 ( V_20 , & V_2 -> V_19 ) ) {
if ( V_2 -> V_21 == V_17 -> V_21 )
V_17 -> V_22 [ 0 ] ++ ;
if ( V_17 -> V_21 -> V_23 )
V_17 -> V_22 [ 1 ] ++ ;
}
}
void F_16 ( struct V_24 * V_25 , struct V_26 * V_21 ,
unsigned int V_22 [ 2 ] )
{
struct V_16 V_17 = { . V_21 = V_21 , . V_22 = V_22 , } ;
V_22 [ 0 ] = V_22 [ 1 ] = 0 ;
F_17 ( V_25 , F_14 , & V_17 ) ;
}
void F_18 ( struct V_24 * V_25 )
{
int V_27 ;
V_27 = F_19 ( & V_25 -> V_28 ) ;
if ( V_27 == 1 ) {
F_20 ( & V_25 -> V_29 ) ;
F_21 ( V_25 , false ) ;
}
}
void F_22 ( struct V_24 * V_25 )
{
F_23 ( V_25 -> V_30 , F_24 ( & V_25 -> V_29 ) ) ;
}
int F_25 ( struct V_24 * V_25 ,
unsigned long V_31 )
{
return F_26 ( V_25 -> V_30 ,
F_24 ( & V_25 -> V_29 ) ,
V_31 ) ;
}
void F_27 ( struct V_24 * V_25 )
{
F_18 ( V_25 ) ;
F_22 ( V_25 ) ;
}
void F_28 ( struct V_24 * V_25 )
{
F_27 ( V_25 ) ;
}
void F_29 ( struct V_24 * V_25 )
{
int V_27 ;
V_27 = F_30 ( & V_25 -> V_28 ) ;
F_31 ( V_27 < 0 ) ;
if ( ! V_27 ) {
F_32 ( & V_25 -> V_29 ) ;
F_33 ( & V_25 -> V_30 ) ;
}
}
void F_34 ( struct V_24 * V_25 )
{
unsigned long V_32 ;
F_35 ( V_25 -> V_33 , V_32 ) ;
F_36 ( V_34 , V_25 ) ;
F_37 ( V_25 -> V_33 , V_32 ) ;
}
void F_38 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
unsigned int V_35 ;
bool V_36 = false ;
F_34 ( V_25 ) ;
F_39 (q, hctx, i) {
if ( V_8 -> V_32 & V_37 )
F_40 ( V_8 -> V_38 ) ;
else
V_36 = true ;
}
if ( V_36 )
F_41 () ;
}
void F_42 ( struct V_24 * V_25 )
{
unsigned long V_32 ;
F_35 ( V_25 -> V_33 , V_32 ) ;
F_43 ( V_34 , V_25 ) ;
F_37 ( V_25 -> V_33 , V_32 ) ;
F_21 ( V_25 , true ) ;
}
void F_44 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
unsigned int V_35 ;
F_39 (q, hctx, i)
if ( F_45 ( V_8 ) )
F_46 ( V_8 -> V_39 , true ) ;
F_33 ( & V_25 -> V_30 ) ;
}
bool F_47 ( struct V_7 * V_8 )
{
return F_48 ( V_8 -> V_39 ) ;
}
static struct V_1 * F_49 ( struct V_40 * V_41 ,
unsigned int V_42 , unsigned int V_43 )
{
struct V_44 * V_39 = F_50 ( V_41 ) ;
struct V_1 * V_2 = V_39 -> V_45 [ V_42 ] ;
V_2 -> V_46 = 0 ;
if ( V_41 -> V_32 & V_47 ) {
V_2 -> V_42 = - 1 ;
V_2 -> V_48 = V_42 ;
} else {
if ( F_51 ( V_41 -> V_8 ) ) {
V_2 -> V_46 = V_49 ;
F_52 ( & V_41 -> V_8 -> V_50 ) ;
}
V_2 -> V_42 = V_42 ;
V_2 -> V_48 = - 1 ;
V_41 -> V_8 -> V_39 -> V_51 [ V_2 -> V_42 ] = V_2 ;
}
F_53 ( & V_2 -> V_52 ) ;
V_2 -> V_25 = V_41 -> V_25 ;
V_2 -> V_53 = V_41 -> V_12 ;
V_2 -> V_54 = V_43 ;
if ( F_54 ( V_41 -> V_25 ) )
V_2 -> V_46 |= V_55 ;
V_2 -> V_56 = - 1 ;
F_55 ( & V_2 -> V_57 ) ;
F_56 ( & V_2 -> V_58 ) ;
V_2 -> V_59 = NULL ;
V_2 -> V_21 = NULL ;
V_2 -> V_60 = V_61 ;
#ifdef F_57
V_2 -> V_62 = NULL ;
F_58 ( V_2 ) ;
V_2 -> V_63 = 0 ;
#endif
V_2 -> V_64 = 0 ;
#if F_59 ( V_65 )
V_2 -> V_66 = 0 ;
#endif
V_2 -> V_67 = NULL ;
V_2 -> V_68 = 0 ;
F_53 ( & V_2 -> V_69 ) ;
V_2 -> V_31 = 0 ;
V_2 -> V_70 = NULL ;
V_2 -> V_71 = NULL ;
V_2 -> V_72 = NULL ;
V_41 -> V_12 -> V_73 [ F_60 ( V_43 ) ] ++ ;
return V_2 ;
}
static struct V_1 * F_61 ( struct V_24 * V_25 ,
struct V_74 * V_74 , unsigned int V_43 ,
struct V_40 * V_41 )
{
struct V_75 * V_76 = V_25 -> V_77 ;
struct V_1 * V_2 ;
unsigned int V_42 ;
struct V_11 * V_78 = NULL ;
F_62 ( V_25 ) ;
V_41 -> V_25 = V_25 ;
if ( F_63 ( ! V_41 -> V_12 ) )
V_41 -> V_12 = V_78 = F_64 ( V_25 ) ;
if ( F_63 ( ! V_41 -> V_8 ) )
V_41 -> V_8 = F_65 ( V_25 , V_41 -> V_12 -> V_56 ) ;
if ( V_43 & V_79 )
V_41 -> V_32 |= V_80 ;
if ( V_76 ) {
V_41 -> V_32 |= V_47 ;
if ( ! F_66 ( V_43 ) && V_76 -> type -> V_81 . V_82 . V_83 )
V_76 -> type -> V_81 . V_82 . V_83 ( V_43 , V_41 ) ;
}
V_42 = F_67 ( V_41 ) ;
if ( V_42 == V_84 ) {
if ( V_78 ) {
F_68 ( V_78 ) ;
V_41 -> V_12 = NULL ;
}
F_69 ( V_25 ) ;
return NULL ;
}
V_2 = F_49 ( V_41 , V_42 , V_43 ) ;
if ( ! F_66 ( V_43 ) ) {
V_2 -> V_85 . V_86 = NULL ;
if ( V_76 && V_76 -> type -> V_81 . V_82 . V_87 ) {
if ( V_76 -> type -> V_88 && F_70 ( V_74 ) )
F_71 ( V_2 , V_74 ) ;
V_76 -> type -> V_81 . V_82 . V_87 ( V_2 , V_74 ) ;
V_2 -> V_46 |= V_89 ;
}
}
V_41 -> V_8 -> V_90 ++ ;
return V_2 ;
}
struct V_1 * F_72 ( struct V_24 * V_25 , unsigned int V_43 ,
unsigned int V_32 )
{
struct V_40 V_91 = { . V_32 = V_32 } ;
struct V_1 * V_2 ;
int V_92 ;
V_92 = F_73 ( V_25 , V_32 & V_80 ) ;
if ( V_92 )
return F_74 ( V_92 ) ;
V_2 = F_61 ( V_25 , NULL , V_43 , & V_91 ) ;
F_69 ( V_25 ) ;
if ( ! V_2 )
return F_74 ( - V_93 ) ;
F_68 ( V_91 . V_12 ) ;
V_2 -> V_94 = 0 ;
V_2 -> V_95 = ( V_96 ) - 1 ;
V_2 -> V_74 = V_2 -> V_97 = NULL ;
return V_2 ;
}
struct V_1 * F_75 ( struct V_24 * V_25 ,
unsigned int V_43 , unsigned int V_32 , unsigned int V_98 )
{
struct V_40 V_91 = { . V_32 = V_32 } ;
struct V_1 * V_2 ;
unsigned int V_56 ;
int V_92 ;
if ( F_31 ( ! ( V_32 & V_80 ) ) )
return F_74 ( - V_99 ) ;
if ( V_98 >= V_25 -> V_100 )
return F_74 ( - V_101 ) ;
V_92 = F_73 ( V_25 , true ) ;
if ( V_92 )
return F_74 ( V_92 ) ;
V_91 . V_8 = V_25 -> V_102 [ V_98 ] ;
if ( ! F_45 ( V_91 . V_8 ) ) {
F_69 ( V_25 ) ;
return F_74 ( - V_103 ) ;
}
V_56 = F_76 ( V_91 . V_8 -> V_104 ) ;
V_91 . V_12 = F_77 ( V_25 , V_56 ) ;
V_2 = F_61 ( V_25 , NULL , V_43 , & V_91 ) ;
F_69 ( V_25 ) ;
if ( ! V_2 )
return F_74 ( - V_93 ) ;
return V_2 ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_75 * V_76 = V_25 -> V_77 ;
struct V_11 * V_12 = V_2 -> V_53 ;
struct V_7 * V_8 = F_65 ( V_25 , V_12 -> V_56 ) ;
const int V_105 = V_2 -> V_48 ;
if ( V_2 -> V_46 & V_89 ) {
if ( V_76 && V_76 -> type -> V_81 . V_82 . V_106 )
V_76 -> type -> V_81 . V_82 . V_106 ( V_2 ) ;
if ( V_2 -> V_85 . V_86 ) {
F_79 ( V_2 -> V_85 . V_86 -> V_107 ) ;
V_2 -> V_85 . V_86 = NULL ;
}
}
V_12 -> V_108 [ F_80 ( V_2 ) ] ++ ;
if ( V_2 -> V_46 & V_49 )
F_81 ( & V_8 -> V_50 ) ;
F_82 ( V_25 -> V_109 , & V_2 -> V_110 ) ;
F_83 ( V_18 , & V_2 -> V_19 ) ;
F_83 ( V_111 , & V_2 -> V_19 ) ;
if ( V_2 -> V_42 != - 1 )
F_84 ( V_8 , V_8 -> V_39 , V_12 , V_2 -> V_42 ) ;
if ( V_105 != - 1 )
F_84 ( V_8 , V_8 -> V_112 , V_12 , V_105 ) ;
F_85 ( V_8 ) ;
F_69 ( V_25 ) ;
}
inline void F_86 ( struct V_1 * V_2 , T_1 error )
{
F_87 ( V_2 ) ;
if ( V_2 -> V_70 ) {
F_82 ( V_2 -> V_25 -> V_109 , & V_2 -> V_110 ) ;
V_2 -> V_70 ( V_2 , error ) ;
} else {
if ( F_88 ( F_89 ( V_2 ) ) )
F_78 ( V_2 -> V_72 ) ;
F_78 ( V_2 ) ;
}
}
void F_90 ( struct V_1 * V_2 , T_1 error )
{
if ( F_91 ( V_2 , error , F_3 ( V_2 ) ) )
F_92 () ;
F_86 ( V_2 , error ) ;
}
static void F_93 ( void * V_41 )
{
struct V_1 * V_2 = V_41 ;
V_2 -> V_25 -> V_113 ( V_2 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_53 ;
bool V_114 = false ;
int V_56 ;
if ( V_2 -> V_48 != - 1 )
F_95 ( V_2 ) ;
if ( V_2 -> V_46 & V_115 ) {
F_96 ( V_2 -> V_25 ) ;
F_97 ( V_2 ) ;
}
if ( ! F_15 ( V_116 , & V_2 -> V_25 -> V_117 ) ) {
V_2 -> V_25 -> V_113 ( V_2 ) ;
return;
}
V_56 = F_98 () ;
if ( ! F_15 ( V_118 , & V_2 -> V_25 -> V_117 ) )
V_114 = F_99 ( V_56 , V_12 -> V_56 ) ;
if ( V_56 != V_12 -> V_56 && ! V_114 && F_100 ( V_12 -> V_56 ) ) {
V_2 -> V_119 . V_120 = F_93 ;
V_2 -> V_119 . V_121 = V_2 ;
V_2 -> V_119 . V_32 = 0 ;
F_101 ( V_12 -> V_56 , & V_2 -> V_119 ) ;
} else {
V_2 -> V_25 -> V_113 ( V_2 ) ;
}
F_102 () ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
if ( F_88 ( F_104 ( V_25 ) ) )
return;
if ( ! F_105 ( V_2 ) )
F_94 ( V_2 ) ;
}
int F_106 ( struct V_1 * V_2 )
{
return F_15 ( V_18 , & V_2 -> V_19 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
F_108 ( V_2 ) ;
F_109 ( V_25 , V_2 ) ;
if ( F_15 ( V_122 , & V_25 -> V_117 ) ) {
F_110 ( & V_2 -> V_110 , F_111 ( V_2 ) ) ;
V_2 -> V_46 |= V_115 ;
F_112 ( V_25 -> V_109 , & V_2 -> V_110 ) ;
}
F_113 ( V_2 ) ;
F_114 () ;
if ( ! F_15 ( V_18 , & V_2 -> V_19 ) )
F_115 ( V_18 , & V_2 -> V_19 ) ;
if ( F_15 ( V_20 , & V_2 -> V_19 ) )
F_83 ( V_20 , & V_2 -> V_19 ) ;
if ( V_25 -> V_123 && F_3 ( V_2 ) ) {
V_2 -> V_64 ++ ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
F_117 ( V_25 , V_2 ) ;
F_118 ( V_25 -> V_109 , & V_2 -> V_110 ) ;
F_119 ( V_2 ) ;
if ( F_120 ( V_18 , & V_2 -> V_19 ) ) {
if ( V_25 -> V_123 && F_3 ( V_2 ) )
V_2 -> V_64 -- ;
}
}
void F_121 ( struct V_1 * V_2 , bool V_124 )
{
F_116 ( V_2 ) ;
F_122 ( F_123 ( V_2 ) ) ;
F_124 ( V_2 , true , V_124 ) ;
}
static void F_125 ( struct V_125 * V_126 )
{
struct V_24 * V_25 =
F_126 ( V_126 , struct V_24 , V_127 . V_126 ) ;
F_127 ( V_128 ) ;
struct V_1 * V_2 , * V_129 ;
F_128 ( & V_25 -> V_130 ) ;
F_129 ( & V_25 -> V_131 , & V_128 ) ;
F_130 ( & V_25 -> V_130 ) ;
F_131 (rq, next, &rq_list, queuelist) {
if ( ! ( V_2 -> V_46 & V_132 ) )
continue;
V_2 -> V_46 &= ~ V_132 ;
F_132 ( & V_2 -> V_52 ) ;
F_133 ( V_2 , true , false , false , true ) ;
}
while ( ! F_134 ( & V_128 ) ) {
V_2 = F_135 ( V_128 . V_129 , struct V_1 , V_52 ) ;
F_132 ( & V_2 -> V_52 ) ;
F_133 ( V_2 , false , false , false , true ) ;
}
F_21 ( V_25 , false ) ;
}
void F_124 ( struct V_1 * V_2 , bool V_133 ,
bool V_124 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
unsigned long V_32 ;
F_122 ( V_2 -> V_46 & V_132 ) ;
F_35 ( & V_25 -> V_130 , V_32 ) ;
if ( V_133 ) {
V_2 -> V_46 |= V_132 ;
F_136 ( & V_2 -> V_52 , & V_25 -> V_131 ) ;
} else {
F_137 ( & V_2 -> V_52 , & V_25 -> V_131 ) ;
}
F_37 ( & V_25 -> V_130 , V_32 ) ;
if ( V_124 )
F_138 ( V_25 ) ;
}
void F_138 ( struct V_24 * V_25 )
{
F_139 ( & V_25 -> V_127 , 0 ) ;
}
void F_140 ( struct V_24 * V_25 ,
unsigned long V_134 )
{
F_141 ( V_135 , & V_25 -> V_127 ,
F_142 ( V_134 ) ) ;
}
struct V_1 * F_143 ( struct V_44 * V_39 , unsigned int V_42 )
{
if ( V_42 < V_39 -> V_136 ) {
F_144 ( V_39 -> V_51 [ V_42 ] ) ;
return V_39 -> V_51 [ V_42 ] ;
}
return NULL ;
}
void F_145 ( struct V_1 * V_137 , bool V_15 )
{
const struct V_138 * V_81 = V_137 -> V_25 -> V_139 ;
enum V_140 V_92 = V_141 ;
if ( ! F_15 ( V_18 , & V_137 -> V_19 ) )
return;
if ( V_81 -> V_31 )
V_92 = V_81 -> V_31 ( V_137 , V_15 ) ;
switch ( V_92 ) {
case V_142 :
F_94 ( V_137 ) ;
break;
case V_141 :
F_113 ( V_137 ) ;
F_146 ( V_137 ) ;
break;
case V_143 :
break;
default:
F_147 ( V_144 L_1 , V_92 ) ;
break;
}
}
static void F_148 ( struct V_7 * V_8 ,
struct V_1 * V_2 , void * V_14 , bool V_15 )
{
struct V_145 * V_41 = V_14 ;
if ( ! F_15 ( V_18 , & V_2 -> V_19 ) )
return;
if ( F_149 ( V_61 , V_2 -> V_146 ) ) {
if ( ! F_105 ( V_2 ) )
F_145 ( V_2 , V_15 ) ;
} else if ( ! V_41 -> V_147 || F_150 ( V_41 -> V_129 , V_2 -> V_146 ) ) {
V_41 -> V_129 = V_2 -> V_146 ;
V_41 -> V_147 = 1 ;
}
}
static void F_151 ( struct V_125 * V_126 )
{
struct V_24 * V_25 =
F_126 ( V_126 , struct V_24 , V_148 ) ;
struct V_145 V_41 = {
. V_129 = 0 ,
. V_147 = 0 ,
} ;
int V_35 ;
if ( ! F_152 ( & V_25 -> V_29 ) )
return;
F_17 ( V_25 , F_148 , & V_41 ) ;
if ( V_41 . V_147 ) {
V_41 . V_129 = F_153 ( F_154 ( V_41 . V_129 ) ) ;
F_155 ( & V_25 -> V_31 , V_41 . V_129 ) ;
} else {
struct V_7 * V_8 ;
F_39 (q, hctx, i) {
if ( F_45 ( V_8 ) )
F_156 ( V_8 ) ;
}
}
F_69 ( V_25 ) ;
}
static bool F_157 ( struct V_149 * V_150 , unsigned int V_151 , void * V_41 )
{
struct V_152 * V_153 = V_41 ;
struct V_7 * V_8 = V_153 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_154 [ V_151 ] ;
F_13 ( V_150 , V_151 ) ;
F_158 ( & V_12 -> V_155 ) ;
F_159 ( & V_12 -> V_128 , V_153 -> V_156 ) ;
F_160 ( & V_12 -> V_155 ) ;
return true ;
}
void F_161 ( struct V_7 * V_8 , struct V_157 * V_156 )
{
struct V_152 V_41 = {
. V_8 = V_8 ,
. V_156 = V_156 ,
} ;
F_162 ( & V_8 -> V_9 , F_157 , & V_41 ) ;
}
static inline unsigned int F_163 ( unsigned int V_90 )
{
if ( ! V_90 )
return 0 ;
return F_164 ( V_158 - 1 , F_4 ( V_90 ) + 1 ) ;
}
bool F_165 ( struct V_1 * V_2 , struct V_7 * * V_8 ,
bool V_159 )
{
struct V_40 V_41 = {
. V_25 = V_2 -> V_25 ,
. V_8 = F_65 ( V_2 -> V_25 , V_2 -> V_53 -> V_56 ) ,
. V_32 = V_159 ? 0 : V_80 ,
} ;
F_166 ( V_159 ) ;
if ( V_2 -> V_42 != - 1 )
goto V_160;
if ( F_167 ( V_41 . V_8 -> V_112 , V_2 -> V_48 ) )
V_41 . V_32 |= V_161 ;
V_2 -> V_42 = F_67 ( & V_41 ) ;
if ( V_2 -> V_42 >= 0 ) {
if ( F_51 ( V_41 . V_8 ) ) {
V_2 -> V_46 |= V_49 ;
F_52 ( & V_41 . V_8 -> V_50 ) ;
}
V_41 . V_8 -> V_39 -> V_51 [ V_2 -> V_42 ] = V_2 ;
}
V_160:
if ( V_8 )
* V_8 = V_41 . V_8 ;
return V_2 -> V_42 != - 1 ;
}
static void F_168 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
F_84 ( V_8 , V_8 -> V_39 , V_2 -> V_53 , V_2 -> V_42 ) ;
V_2 -> V_42 = - 1 ;
if ( V_2 -> V_46 & V_49 ) {
V_2 -> V_46 &= ~ V_49 ;
F_81 ( & V_8 -> V_50 ) ;
}
}
static void F_169 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_42 == - 1 || V_2 -> V_48 == - 1 )
return;
F_168 ( V_8 , V_2 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
if ( V_2 -> V_42 == - 1 || V_2 -> V_48 == - 1 )
return;
V_8 = F_65 ( V_2 -> V_25 , V_2 -> V_53 -> V_56 ) ;
F_168 ( V_8 , V_2 ) ;
}
static bool F_171 ( struct V_157 * V_156 )
{
struct V_1 * V_2 , * V_162 , * V_163 = NULL ;
F_172 (rq, tmp, list, queuelist) {
if ( V_2 == V_163 )
break;
if ( V_2 -> V_42 != - 1 ) {
F_173 ( & V_2 -> V_52 , V_156 ) ;
if ( ! V_163 )
V_163 = V_2 ;
}
}
return V_163 != NULL ;
}
static int F_174 ( T_2 * V_159 , unsigned V_164 , int V_32 ,
void * V_165 )
{
struct V_7 * V_8 ;
V_8 = F_126 ( V_159 , struct V_7 , V_166 ) ;
F_175 ( & V_159 -> V_167 ) ;
F_176 ( V_168 , & V_8 -> V_169 ) ;
F_177 ( V_8 , true ) ;
return 1 ;
}
static bool F_178 ( struct V_7 * V_8 )
{
struct V_170 * V_171 ;
if ( F_15 ( V_168 , & V_8 -> V_169 ) ||
F_179 ( V_168 , & V_8 -> V_169 ) )
return false ;
F_180 ( & V_8 -> V_166 , F_174 ) ;
V_171 = F_181 ( & V_8 -> V_39 -> V_172 , V_8 ) ;
F_182 ( & V_171 -> V_159 , & V_8 -> V_166 ) ;
return true ;
}
bool F_183 ( struct V_24 * V_25 , struct V_157 * V_156 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_173 , V_90 ;
if ( F_134 ( V_156 ) )
return false ;
V_173 = V_90 = 0 ;
do {
struct V_174 V_175 ;
T_1 V_92 ;
V_2 = F_184 ( V_156 , struct V_1 , V_52 ) ;
if ( ! F_165 ( V_2 , & V_8 , false ) ) {
if ( ! V_90 && F_171 ( V_156 ) )
continue;
if ( ! F_178 ( V_8 ) )
break;
if ( ! F_165 ( V_2 , & V_8 , false ) )
break;
}
F_132 ( & V_2 -> V_52 ) ;
V_175 . V_2 = V_2 ;
if ( F_134 ( V_156 ) )
V_175 . V_176 = true ;
else {
struct V_1 * V_177 ;
V_177 = F_184 ( V_156 , struct V_1 , V_52 ) ;
V_175 . V_176 = ! F_165 ( V_177 , NULL , false ) ;
}
V_92 = V_25 -> V_139 -> V_178 ( V_8 , & V_175 ) ;
if ( V_92 == V_179 ) {
F_169 ( V_8 , V_2 ) ;
F_136 ( & V_2 -> V_52 , V_156 ) ;
F_116 ( V_2 ) ;
break;
}
if ( F_88 ( V_92 != V_180 ) ) {
V_173 ++ ;
F_90 ( V_2 , V_181 ) ;
continue;
}
V_90 ++ ;
} while ( ! F_134 ( V_156 ) );
V_8 -> V_182 [ F_163 ( V_90 ) ] ++ ;
if ( ! F_134 ( V_156 ) ) {
V_2 = F_184 ( V_156 , struct V_1 , V_52 ) ;
F_170 ( V_2 ) ;
F_158 ( & V_8 -> V_155 ) ;
F_129 ( V_156 , & V_8 -> V_10 ) ;
F_160 ( & V_8 -> V_155 ) ;
if ( ! F_185 ( V_8 ) &&
! F_15 ( V_168 , & V_8 -> V_169 ) )
F_177 ( V_8 , true ) ;
}
return ( V_90 + V_173 ) != 0 ;
}
static void F_186 ( struct V_7 * V_8 )
{
int V_183 ;
F_187 ( ! F_188 ( F_189 () , V_8 -> V_104 ) &&
F_100 ( V_8 -> V_184 ) ) ;
F_31 ( F_190 () ) ;
if ( ! ( V_8 -> V_32 & V_37 ) ) {
F_191 () ;
F_192 ( V_8 ) ;
F_193 () ;
} else {
F_194 () ;
V_183 = F_195 ( V_8 -> V_38 ) ;
F_192 ( V_8 ) ;
F_196 ( V_8 -> V_38 , V_183 ) ;
}
}
static int F_197 ( struct V_7 * V_8 )
{
if ( V_8 -> V_185 -> V_100 == 1 )
return V_135 ;
if ( -- V_8 -> V_186 <= 0 ) {
int V_184 ;
V_184 = F_198 ( V_8 -> V_184 , V_8 -> V_104 ) ;
if ( V_184 >= V_187 )
V_184 = F_76 ( V_8 -> V_104 ) ;
V_8 -> V_184 = V_184 ;
V_8 -> V_186 = V_188 ;
}
return V_8 -> V_184 ;
}
static void F_199 ( struct V_7 * V_8 , bool V_189 ,
unsigned long V_134 )
{
if ( F_31 ( ! F_45 ( V_8 ) ) )
return;
if ( F_88 ( F_200 ( V_8 ) ) )
return;
if ( ! V_189 && ! ( V_8 -> V_32 & V_37 ) ) {
int V_56 = F_98 () ;
if ( F_188 ( V_56 , V_8 -> V_104 ) ) {
F_186 ( V_8 ) ;
F_102 () ;
return;
}
F_102 () ;
}
F_201 ( F_197 ( V_8 ) ,
& V_8 -> V_190 ,
F_142 ( V_134 ) ) ;
}
void F_202 ( struct V_7 * V_8 , unsigned long V_134 )
{
F_199 ( V_8 , true , V_134 ) ;
}
void F_177 ( struct V_7 * V_8 , bool V_189 )
{
F_199 ( V_8 , V_189 , 0 ) ;
}
void F_21 ( struct V_24 * V_25 , bool V_189 )
{
struct V_7 * V_8 ;
int V_35 ;
F_39 (q, hctx, i) {
if ( ! F_5 ( V_8 ) ||
F_200 ( V_8 ) )
continue;
F_177 ( V_8 , V_189 ) ;
}
}
bool F_203 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
int V_35 ;
F_39 (q, hctx, i)
if ( F_200 ( V_8 ) )
return true ;
return false ;
}
void F_204 ( struct V_7 * V_8 )
{
F_205 ( & V_8 -> V_190 ) ;
F_115 ( V_191 , & V_8 -> V_169 ) ;
}
void F_206 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
int V_35 ;
F_39 (q, hctx, i)
F_204 ( V_8 ) ;
}
void F_207 ( struct V_7 * V_8 )
{
F_83 ( V_191 , & V_8 -> V_169 ) ;
F_177 ( V_8 , false ) ;
}
void F_208 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
int V_35 ;
F_39 (q, hctx, i)
F_207 ( V_8 ) ;
}
void F_209 ( struct V_7 * V_8 , bool V_189 )
{
if ( ! F_200 ( V_8 ) )
return;
F_83 ( V_191 , & V_8 -> V_169 ) ;
F_177 ( V_8 , V_189 ) ;
}
void F_210 ( struct V_24 * V_25 , bool V_189 )
{
struct V_7 * V_8 ;
int V_35 ;
F_39 (q, hctx, i)
F_209 ( V_8 , V_189 ) ;
}
static void F_211 ( struct V_125 * V_126 )
{
struct V_7 * V_8 ;
V_8 = F_126 ( V_126 , struct V_7 , V_190 . V_126 ) ;
if ( F_15 ( V_191 , & V_8 -> V_169 ) ) {
if ( ! F_15 ( V_192 , & V_8 -> V_169 ) )
return;
F_83 ( V_192 , & V_8 -> V_169 ) ;
F_83 ( V_191 , & V_8 -> V_169 ) ;
}
F_186 ( V_8 ) ;
}
void F_212 ( struct V_7 * V_8 , unsigned long V_134 )
{
if ( F_31 ( ! F_45 ( V_8 ) ) )
return;
F_204 ( V_8 ) ;
F_115 ( V_192 , & V_8 -> V_169 ) ;
F_141 ( F_197 ( V_8 ) ,
& V_8 -> V_190 ,
F_142 ( V_134 ) ) ;
}
static inline void F_213 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
bool V_133 )
{
struct V_11 * V_12 = V_2 -> V_53 ;
F_214 ( & V_12 -> V_155 ) ;
F_215 ( V_8 -> V_185 , V_2 ) ;
if ( V_133 )
F_136 ( & V_2 -> V_52 , & V_12 -> V_128 ) ;
else
F_137 ( & V_2 -> V_52 , & V_12 -> V_128 ) ;
}
void F_216 ( struct V_7 * V_8 , struct V_1 * V_2 ,
bool V_133 )
{
struct V_11 * V_12 = V_2 -> V_53 ;
F_214 ( & V_12 -> V_155 ) ;
F_213 ( V_8 , V_2 , V_133 ) ;
F_9 ( V_8 , V_12 ) ;
}
void F_217 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_53 ;
struct V_7 * V_8 = F_65 ( V_2 -> V_25 , V_12 -> V_56 ) ;
F_158 ( & V_8 -> V_155 ) ;
F_137 ( & V_2 -> V_52 , & V_8 -> V_10 ) ;
F_160 ( & V_8 -> V_155 ) ;
F_177 ( V_8 , false ) ;
}
void F_218 ( struct V_7 * V_8 , struct V_11 * V_12 ,
struct V_157 * V_156 )
{
F_158 ( & V_12 -> V_155 ) ;
while ( ! F_134 ( V_156 ) ) {
struct V_1 * V_2 ;
V_2 = F_184 ( V_156 , struct V_1 , V_52 ) ;
F_122 ( V_2 -> V_53 != V_12 ) ;
F_132 ( & V_2 -> V_52 ) ;
F_213 ( V_8 , V_2 , false ) ;
}
F_9 ( V_8 , V_12 ) ;
F_160 ( & V_12 -> V_155 ) ;
}
static int F_219 ( void * V_14 , struct V_157 * V_193 , struct V_157 * V_194 )
{
struct V_1 * V_195 = F_126 ( V_193 , struct V_1 , V_52 ) ;
struct V_1 * V_196 = F_126 ( V_194 , struct V_1 , V_52 ) ;
return ! ( V_195 -> V_53 < V_196 -> V_53 ||
( V_195 -> V_53 == V_196 -> V_53 &&
F_220 ( V_195 ) < F_220 ( V_196 ) ) ) ;
}
void F_221 ( struct V_197 * V_198 , bool V_199 )
{
struct V_11 * V_200 ;
struct V_24 * V_201 ;
struct V_1 * V_2 ;
F_127 ( V_156 ) ;
F_127 ( V_202 ) ;
unsigned int V_203 ;
F_129 ( & V_198 -> V_204 , & V_156 ) ;
F_222 ( NULL , & V_156 , F_219 ) ;
V_201 = NULL ;
V_200 = NULL ;
V_203 = 0 ;
while ( ! F_134 ( & V_156 ) ) {
V_2 = F_223 ( V_156 . V_129 ) ;
F_132 ( & V_2 -> V_52 ) ;
F_122 ( ! V_2 -> V_25 ) ;
if ( V_2 -> V_53 != V_200 ) {
if ( V_200 ) {
F_224 ( V_201 , V_203 , V_199 ) ;
F_225 ( V_201 , V_200 ,
& V_202 ,
V_199 ) ;
}
V_200 = V_2 -> V_53 ;
V_201 = V_2 -> V_25 ;
V_203 = 0 ;
}
V_203 ++ ;
F_137 ( & V_2 -> V_52 , & V_202 ) ;
}
if ( V_200 ) {
F_224 ( V_201 , V_203 , V_199 ) ;
F_225 ( V_201 , V_200 , & V_202 ,
V_199 ) ;
}
}
static void F_226 ( struct V_1 * V_2 , struct V_74 * V_74 )
{
F_227 ( V_2 , V_74 ) ;
F_228 ( V_2 , true ) ;
}
static inline bool F_229 ( struct V_7 * V_8 )
{
return ( V_8 -> V_32 & V_205 ) &&
! F_230 ( V_8 -> V_185 ) ;
}
static inline void F_231 ( struct V_7 * V_8 ,
struct V_11 * V_12 ,
struct V_1 * V_2 )
{
F_158 ( & V_12 -> V_155 ) ;
F_216 ( V_8 , V_2 , false ) ;
F_160 ( & V_12 -> V_155 ) ;
}
static T_3 F_232 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( V_2 -> V_42 != - 1 )
return F_233 ( V_2 -> V_42 , V_8 -> V_206 , false ) ;
return F_233 ( V_2 -> V_48 , V_8 -> V_206 , true ) ;
}
static void F_234 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
T_3 * V_207 , bool V_208 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_174 V_175 = {
. V_2 = V_2 ,
. V_176 = true ,
} ;
T_3 V_209 ;
T_1 V_92 ;
bool V_210 = true ;
if ( F_200 ( V_8 ) || F_235 ( V_25 ) ) {
V_210 = false ;
goto V_211;
}
if ( V_25 -> V_77 )
goto V_211;
if ( ! F_165 ( V_2 , NULL , false ) )
goto V_211;
V_209 = F_232 ( V_8 , V_2 ) ;
V_92 = V_25 -> V_139 -> V_178 ( V_8 , & V_175 ) ;
switch ( V_92 ) {
case V_180 :
* V_207 = V_209 ;
return;
case V_179 :
F_116 ( V_2 ) ;
goto V_211;
default:
* V_207 = V_212 ;
F_90 ( V_2 , V_92 ) ;
return;
}
V_211:
F_133 ( V_2 , false , V_210 , false , V_208 ) ;
}
static void F_236 ( struct V_7 * V_8 ,
struct V_1 * V_2 , T_3 * V_207 )
{
if ( ! ( V_8 -> V_32 & V_37 ) ) {
F_191 () ;
F_234 ( V_8 , V_2 , V_207 , false ) ;
F_193 () ;
} else {
unsigned int V_183 ;
F_194 () ;
V_183 = F_195 ( V_8 -> V_38 ) ;
F_234 ( V_8 , V_2 , V_207 , true ) ;
F_196 ( V_8 -> V_38 , V_183 ) ;
}
}
static T_3 F_237 ( struct V_24 * V_25 , struct V_74 * V_74 )
{
const int V_213 = F_60 ( V_74 -> V_214 ) ;
const int V_215 = F_66 ( V_74 -> V_214 ) ;
struct V_40 V_41 = { . V_32 = 0 } ;
struct V_1 * V_2 ;
unsigned int V_216 = 0 ;
struct V_197 * V_198 ;
struct V_1 * V_217 = NULL ;
T_3 V_207 ;
unsigned int V_218 ;
F_238 ( V_25 , & V_74 ) ;
F_239 ( V_25 , & V_74 ) ;
if ( ! F_240 ( V_74 ) )
return V_212 ;
if ( ! V_215 && ! F_230 ( V_25 ) &&
F_241 ( V_25 , V_74 , & V_216 , & V_217 ) )
return V_212 ;
if ( F_242 ( V_25 , V_74 ) )
return V_212 ;
V_218 = F_243 ( V_25 -> V_109 , V_74 , NULL ) ;
F_244 ( V_25 , V_74 , V_74 -> V_214 ) ;
V_2 = F_61 ( V_25 , V_74 , V_74 -> V_214 , & V_41 ) ;
if ( F_88 ( ! V_2 ) ) {
F_245 ( V_25 -> V_109 , V_218 ) ;
if ( V_74 -> V_214 & V_79 )
F_246 ( V_74 ) ;
return V_212 ;
}
F_247 ( & V_2 -> V_110 , V_218 ) ;
V_207 = F_232 ( V_41 . V_8 , V_2 ) ;
V_198 = V_219 -> V_198 ;
if ( F_88 ( V_215 ) ) {
F_68 ( V_41 . V_12 ) ;
F_226 ( V_2 , V_74 ) ;
if ( V_25 -> V_77 ) {
F_133 ( V_2 , false , true , true ,
true ) ;
} else {
F_248 ( V_2 ) ;
F_177 ( V_41 . V_8 , true ) ;
}
} else if ( V_198 && V_25 -> V_100 == 1 ) {
struct V_1 * V_176 = NULL ;
F_68 ( V_41 . V_12 ) ;
F_226 ( V_2 , V_74 ) ;
if ( F_134 ( & V_198 -> V_204 ) )
V_216 = 0 ;
else if ( F_230 ( V_25 ) )
V_216 = F_249 ( V_25 ) ;
if ( ! V_216 )
F_250 ( V_25 ) ;
else
V_176 = F_223 ( V_198 -> V_204 . V_220 ) ;
if ( V_216 >= V_221 || ( V_176 &&
F_3 ( V_176 ) >= V_222 ) ) {
F_251 ( V_198 , false ) ;
F_250 ( V_25 ) ;
}
F_137 ( & V_2 -> V_52 , & V_198 -> V_204 ) ;
} else if ( V_198 && ! F_230 ( V_25 ) ) {
F_226 ( V_2 , V_74 ) ;
if ( F_134 ( & V_198 -> V_204 ) )
V_217 = NULL ;
if ( V_217 )
F_132 ( & V_217 -> V_52 ) ;
F_137 ( & V_2 -> V_52 , & V_198 -> V_204 ) ;
F_68 ( V_41 . V_12 ) ;
if ( V_217 ) {
V_41 . V_8 = F_65 ( V_25 ,
V_217 -> V_53 -> V_56 ) ;
F_236 ( V_41 . V_8 , V_217 ,
& V_207 ) ;
}
} else if ( V_25 -> V_100 > 1 && V_213 ) {
F_68 ( V_41 . V_12 ) ;
F_226 ( V_2 , V_74 ) ;
F_236 ( V_41 . V_8 , V_2 , & V_207 ) ;
} else if ( V_25 -> V_77 ) {
F_68 ( V_41 . V_12 ) ;
F_226 ( V_2 , V_74 ) ;
F_133 ( V_2 , false , true , true , true ) ;
} else {
F_68 ( V_41 . V_12 ) ;
F_226 ( V_2 , V_74 ) ;
F_231 ( V_41 . V_8 , V_41 . V_12 , V_2 ) ;
F_177 ( V_41 . V_8 , true ) ;
}
return V_207 ;
}
void F_252 ( struct V_223 * V_224 , struct V_44 * V_39 ,
unsigned int V_98 )
{
struct V_225 * V_225 ;
if ( V_39 -> V_51 && V_224 -> V_81 -> V_226 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < V_39 -> V_136 ; V_35 ++ ) {
struct V_1 * V_2 = V_39 -> V_45 [ V_35 ] ;
if ( ! V_2 )
continue;
V_224 -> V_81 -> V_226 ( V_224 , V_2 , V_98 ) ;
V_39 -> V_45 [ V_35 ] = NULL ;
}
}
while ( ! F_134 ( & V_39 -> V_227 ) ) {
V_225 = F_184 ( & V_39 -> V_227 , struct V_225 , V_228 ) ;
F_132 ( & V_225 -> V_228 ) ;
F_253 ( F_254 ( V_225 ) ) ;
F_255 ( V_225 , V_225 -> V_229 ) ;
}
}
void F_256 ( struct V_44 * V_39 )
{
F_257 ( V_39 -> V_51 ) ;
V_39 -> V_51 = NULL ;
F_257 ( V_39 -> V_45 ) ;
V_39 -> V_45 = NULL ;
F_258 ( V_39 ) ;
}
struct V_44 * F_259 ( struct V_223 * V_224 ,
unsigned int V_98 ,
unsigned int V_136 ,
unsigned int V_230 )
{
struct V_44 * V_39 ;
int V_231 ;
V_231 = F_260 ( V_224 -> V_232 , V_98 ) ;
if ( V_231 == V_233 )
V_231 = V_224 -> V_234 ;
V_39 = F_261 ( V_136 , V_230 , V_231 ,
F_262 ( V_224 -> V_32 ) ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_51 = F_263 ( V_136 * sizeof( struct V_1 * ) ,
V_235 | V_236 | V_237 ,
V_231 ) ;
if ( ! V_39 -> V_51 ) {
F_258 ( V_39 ) ;
return NULL ;
}
V_39 -> V_45 = F_263 ( V_136 * sizeof( struct V_1 * ) ,
V_235 | V_236 | V_237 ,
V_231 ) ;
if ( ! V_39 -> V_45 ) {
F_257 ( V_39 -> V_51 ) ;
F_258 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
static T_4 F_264 ( unsigned int V_238 )
{
return ( T_4 ) V_239 << V_238 ;
}
int F_265 ( struct V_223 * V_224 , struct V_44 * V_39 ,
unsigned int V_98 , unsigned int V_203 )
{
unsigned int V_35 , V_240 , V_241 , V_242 = 4 ;
T_4 V_243 , V_244 ;
int V_231 ;
V_231 = F_260 ( V_224 -> V_232 , V_98 ) ;
if ( V_231 == V_233 )
V_231 = V_224 -> V_234 ;
F_53 ( & V_39 -> V_227 ) ;
V_243 = F_266 ( sizeof( struct V_1 ) + V_224 -> V_245 ,
F_267 () ) ;
V_244 = V_243 * V_203 ;
for ( V_35 = 0 ; V_35 < V_203 ; ) {
int V_246 = V_242 ;
struct V_225 * V_225 ;
int V_247 ;
void * V_248 ;
while ( V_246 && V_244 < F_264 ( V_246 - 1 ) )
V_246 -- ;
do {
V_225 = F_268 ( V_231 ,
V_235 | V_236 | V_237 | V_249 ,
V_246 ) ;
if ( V_225 )
break;
if ( ! V_246 -- )
break;
if ( F_264 ( V_246 ) < V_243 )
break;
} while ( 1 );
if ( ! V_225 )
goto V_250;
V_225 -> V_229 = V_246 ;
F_137 ( & V_225 -> V_228 , & V_39 -> V_227 ) ;
V_248 = F_254 ( V_225 ) ;
F_269 ( V_248 , F_264 ( V_246 ) , 1 , V_235 ) ;
V_241 = F_264 ( V_246 ) / V_243 ;
V_247 = F_164 ( V_241 , V_203 - V_35 ) ;
V_244 -= V_247 * V_243 ;
for ( V_240 = 0 ; V_240 < V_247 ; V_240 ++ ) {
struct V_1 * V_2 = V_248 ;
V_39 -> V_45 [ V_35 ] = V_2 ;
if ( V_224 -> V_81 -> V_251 ) {
if ( V_224 -> V_81 -> V_251 ( V_224 , V_2 , V_98 ,
V_231 ) ) {
V_39 -> V_45 [ V_35 ] = NULL ;
goto V_250;
}
}
V_248 += V_243 ;
V_35 ++ ;
}
}
return 0 ;
V_250:
F_252 ( V_224 , V_39 , V_98 ) ;
return - V_252 ;
}
static int F_270 ( unsigned int V_56 , struct V_253 * V_231 )
{
struct V_7 * V_8 ;
struct V_11 * V_12 ;
F_127 ( V_162 ) ;
V_8 = F_271 ( V_231 , struct V_7 , V_254 ) ;
V_12 = F_77 ( V_8 -> V_185 , V_56 ) ;
F_158 ( & V_12 -> V_155 ) ;
if ( ! F_134 ( & V_12 -> V_128 ) ) {
F_129 ( & V_12 -> V_128 , & V_162 ) ;
F_12 ( V_8 , V_12 ) ;
}
F_160 ( & V_12 -> V_155 ) ;
if ( F_134 ( & V_162 ) )
return 0 ;
F_158 ( & V_8 -> V_155 ) ;
F_159 ( & V_162 , & V_8 -> V_10 ) ;
F_160 ( & V_8 -> V_155 ) ;
F_177 ( V_8 , true ) ;
return 0 ;
}
static void F_272 ( struct V_7 * V_8 )
{
F_273 ( V_255 ,
& V_8 -> V_254 ) ;
}
static void F_274 ( struct V_24 * V_25 ,
struct V_223 * V_224 ,
struct V_7 * V_8 , unsigned int V_98 )
{
F_275 ( V_8 ) ;
F_156 ( V_8 ) ;
if ( V_224 -> V_81 -> V_226 )
V_224 -> V_81 -> V_226 ( V_224 , V_8 -> V_256 -> V_257 , V_98 ) ;
F_276 ( V_25 , V_8 , V_98 ) ;
if ( V_224 -> V_81 -> V_258 )
V_224 -> V_81 -> V_258 ( V_8 , V_98 ) ;
if ( V_8 -> V_32 & V_37 )
F_277 ( V_8 -> V_38 ) ;
F_272 ( V_8 ) ;
F_278 ( V_8 -> V_256 ) ;
F_279 ( & V_8 -> V_9 ) ;
}
static void F_280 ( struct V_24 * V_25 ,
struct V_223 * V_224 , int V_259 )
{
struct V_7 * V_8 ;
unsigned int V_35 ;
F_39 (q, hctx, i) {
if ( V_35 == V_259 )
break;
F_274 ( V_25 , V_224 , V_8 , V_35 ) ;
}
}
static int F_281 ( struct V_24 * V_25 ,
struct V_223 * V_224 ,
struct V_7 * V_8 , unsigned V_98 )
{
int V_231 ;
V_231 = V_8 -> V_234 ;
if ( V_231 == V_233 )
V_231 = V_8 -> V_234 = V_224 -> V_234 ;
F_282 ( & V_8 -> V_190 , F_211 ) ;
F_283 ( & V_8 -> V_155 ) ;
F_53 ( & V_8 -> V_10 ) ;
V_8 -> V_185 = V_25 ;
V_8 -> V_32 = V_224 -> V_32 & ~ V_260 ;
F_284 ( V_255 , & V_8 -> V_254 ) ;
V_8 -> V_39 = V_224 -> V_39 [ V_98 ] ;
V_8 -> V_154 = F_285 ( V_187 * sizeof( void * ) ,
V_261 , V_231 ) ;
if ( ! V_8 -> V_154 )
goto V_262;
if ( F_286 ( & V_8 -> V_9 , V_187 , F_4 ( 8 ) , V_261 ,
V_231 ) )
goto V_263;
V_8 -> V_264 = 0 ;
if ( V_224 -> V_81 -> V_265 &&
V_224 -> V_81 -> V_265 ( V_8 , V_224 -> V_266 , V_98 ) )
goto V_267;
if ( F_287 ( V_25 , V_8 , V_98 ) )
goto V_258;
V_8 -> V_256 = F_288 ( V_25 , V_8 -> V_234 , V_224 -> V_245 ) ;
if ( ! V_8 -> V_256 )
goto V_268;
if ( V_224 -> V_81 -> V_251 &&
V_224 -> V_81 -> V_251 ( V_224 , V_8 -> V_256 -> V_257 , V_98 ,
V_231 ) )
goto V_269;
if ( V_8 -> V_32 & V_37 )
F_289 ( V_8 -> V_38 ) ;
F_290 ( V_25 , V_8 ) ;
return 0 ;
V_269:
F_257 ( V_8 -> V_256 ) ;
V_268:
F_276 ( V_25 , V_8 , V_98 ) ;
V_258:
if ( V_224 -> V_81 -> V_258 )
V_224 -> V_81 -> V_258 ( V_8 , V_98 ) ;
V_267:
F_279 ( & V_8 -> V_9 ) ;
V_263:
F_257 ( V_8 -> V_154 ) ;
V_262:
F_272 ( V_8 ) ;
return - 1 ;
}
static void F_291 ( struct V_24 * V_25 ,
unsigned int V_100 )
{
unsigned int V_35 ;
F_292 (i) {
struct V_11 * V_270 = F_293 ( V_25 -> V_271 , V_35 ) ;
struct V_7 * V_8 ;
V_270 -> V_56 = V_35 ;
F_283 ( & V_270 -> V_155 ) ;
F_53 ( & V_270 -> V_128 ) ;
V_270 -> V_185 = V_25 ;
if ( ! F_294 ( V_35 ) )
continue;
V_8 = F_65 ( V_25 , V_35 ) ;
if ( V_100 > 1 && V_8 -> V_234 == V_233 )
V_8 -> V_234 = F_295 ( F_296 ( V_35 ) ) ;
}
}
static bool F_297 ( struct V_223 * V_224 , int V_98 )
{
int V_92 = 0 ;
V_224 -> V_39 [ V_98 ] = F_259 ( V_224 , V_98 ,
V_224 -> V_272 , V_224 -> V_230 ) ;
if ( ! V_224 -> V_39 [ V_98 ] )
return false ;
V_92 = F_265 ( V_224 , V_224 -> V_39 [ V_98 ] , V_98 ,
V_224 -> V_272 ) ;
if ( ! V_92 )
return true ;
F_256 ( V_224 -> V_39 [ V_98 ] ) ;
V_224 -> V_39 [ V_98 ] = NULL ;
return false ;
}
static void F_298 ( struct V_223 * V_224 ,
unsigned int V_98 )
{
if ( V_224 -> V_39 [ V_98 ] ) {
F_252 ( V_224 , V_224 -> V_39 [ V_98 ] , V_98 ) ;
F_256 ( V_224 -> V_39 [ V_98 ] ) ;
V_224 -> V_39 [ V_98 ] = NULL ;
}
}
static void F_299 ( struct V_24 * V_25 )
{
unsigned int V_35 , V_98 ;
struct V_7 * V_8 ;
struct V_11 * V_12 ;
struct V_223 * V_224 = V_25 -> V_273 ;
F_300 ( & V_25 -> V_274 ) ;
F_39 (q, hctx, i) {
F_301 ( V_8 -> V_104 ) ;
V_8 -> V_264 = 0 ;
}
F_302 (i) {
V_98 = V_25 -> V_232 [ V_35 ] ;
if ( ! V_224 -> V_39 [ V_98 ] &&
! F_297 ( V_224 , V_98 ) ) {
V_25 -> V_232 [ V_35 ] = 0 ;
}
V_12 = F_293 ( V_25 -> V_271 , V_35 ) ;
V_8 = F_65 ( V_25 , V_35 ) ;
F_303 ( V_35 , V_8 -> V_104 ) ;
V_12 -> V_13 = V_8 -> V_264 ;
V_8 -> V_154 [ V_8 -> V_264 ++ ] = V_12 ;
}
F_304 ( & V_25 -> V_274 ) ;
F_39 (q, hctx, i) {
if ( ! V_8 -> V_264 ) {
if ( V_35 && V_224 -> V_39 [ V_35 ] )
F_298 ( V_224 , V_35 ) ;
V_8 -> V_39 = NULL ;
continue;
}
V_8 -> V_39 = V_224 -> V_39 [ V_35 ] ;
F_187 ( ! V_8 -> V_39 ) ;
F_305 ( & V_8 -> V_9 , V_8 -> V_264 ) ;
V_8 -> V_184 = F_76 ( V_8 -> V_104 ) ;
V_8 -> V_186 = V_188 ;
}
}
static void F_306 ( struct V_24 * V_25 , bool V_114 )
{
struct V_7 * V_8 ;
int V_35 ;
F_39 (q, hctx, i) {
if ( V_114 ) {
if ( F_15 ( V_275 , & V_8 -> V_169 ) )
F_52 ( & V_25 -> V_276 ) ;
V_8 -> V_32 |= V_260 ;
} else {
if ( F_15 ( V_275 , & V_8 -> V_169 ) )
F_81 ( & V_25 -> V_276 ) ;
V_8 -> V_32 &= ~ V_260 ;
}
}
}
static void F_307 ( struct V_223 * V_224 ,
bool V_114 )
{
struct V_24 * V_25 ;
F_214 ( & V_224 -> V_277 ) ;
F_308 (q, &set->tag_list, tag_set_list) {
F_28 ( V_25 ) ;
F_306 ( V_25 , V_114 ) ;
F_29 ( V_25 ) ;
}
}
static void F_309 ( struct V_24 * V_25 )
{
struct V_223 * V_224 = V_25 -> V_273 ;
F_300 ( & V_224 -> V_277 ) ;
F_310 ( & V_25 -> V_278 ) ;
F_53 ( & V_25 -> V_278 ) ;
if ( F_311 ( & V_224 -> V_279 ) ) {
V_224 -> V_32 &= ~ V_260 ;
F_307 ( V_224 , false ) ;
}
F_304 ( & V_224 -> V_277 ) ;
F_41 () ;
}
static void F_312 ( struct V_223 * V_224 ,
struct V_24 * V_25 )
{
V_25 -> V_273 = V_224 ;
F_300 ( & V_224 -> V_277 ) ;
if ( ! F_134 ( & V_224 -> V_279 ) && ! ( V_224 -> V_32 & V_260 ) ) {
V_224 -> V_32 |= V_260 ;
F_307 ( V_224 , true ) ;
}
if ( V_224 -> V_32 & V_260 )
F_306 ( V_25 , true ) ;
F_313 ( & V_25 -> V_278 , & V_224 -> V_279 ) ;
F_304 ( & V_224 -> V_277 ) ;
}
void F_314 ( struct V_24 * V_25 )
{
struct V_7 * V_8 ;
unsigned int V_35 ;
F_39 (q, hctx, i) {
if ( ! V_8 )
continue;
F_315 ( & V_8 -> V_280 ) ;
}
V_25 -> V_232 = NULL ;
F_257 ( V_25 -> V_102 ) ;
F_316 ( V_25 ) ;
F_317 ( V_25 -> V_271 ) ;
}
struct V_24 * F_318 ( struct V_223 * V_224 )
{
struct V_24 * V_281 , * V_25 ;
V_281 = F_319 ( V_261 , V_224 -> V_234 ) ;
if ( ! V_281 )
return F_74 ( - V_252 ) ;
V_25 = F_320 ( V_224 , V_281 ) ;
if ( F_321 ( V_25 ) )
F_322 ( V_281 ) ;
return V_25 ;
}
static int F_323 ( struct V_223 * V_273 )
{
int V_282 = sizeof( struct V_7 ) ;
F_324 ( F_325 ( F_326 ( struct V_7 , V_38 ) ,
F_327 ( struct V_7 ) ) !=
sizeof( struct V_7 ) ) ;
if ( V_273 -> V_32 & V_37 )
V_282 += sizeof( struct V_283 ) ;
return V_282 ;
}
static void F_328 ( struct V_223 * V_224 ,
struct V_24 * V_25 )
{
int V_35 , V_240 ;
struct V_7 * * V_284 = V_25 -> V_102 ;
F_329 ( V_25 ) ;
for ( V_35 = 0 ; V_35 < V_224 -> V_100 ; V_35 ++ ) {
int V_231 ;
if ( V_284 [ V_35 ] )
continue;
V_231 = F_260 ( V_25 -> V_232 , V_35 ) ;
V_284 [ V_35 ] = F_263 ( F_323 ( V_224 ) ,
V_261 , V_231 ) ;
if ( ! V_284 [ V_35 ] )
break;
if ( ! F_330 ( & V_284 [ V_35 ] -> V_104 , V_261 ,
V_231 ) ) {
F_257 ( V_284 [ V_35 ] ) ;
V_284 [ V_35 ] = NULL ;
break;
}
F_331 ( & V_284 [ V_35 ] -> V_50 , 0 ) ;
V_284 [ V_35 ] -> V_234 = V_231 ;
V_284 [ V_35 ] -> V_206 = V_35 ;
if ( F_281 ( V_25 , V_224 , V_284 [ V_35 ] , V_35 ) ) {
F_332 ( V_284 [ V_35 ] -> V_104 ) ;
F_257 ( V_284 [ V_35 ] ) ;
V_284 [ V_35 ] = NULL ;
break;
}
F_333 ( V_284 [ V_35 ] ) ;
}
for ( V_240 = V_35 ; V_240 < V_25 -> V_100 ; V_240 ++ ) {
struct V_7 * V_8 = V_284 [ V_240 ] ;
if ( V_8 ) {
if ( V_8 -> V_39 )
F_298 ( V_224 , V_240 ) ;
F_274 ( V_25 , V_224 , V_8 , V_240 ) ;
F_315 ( & V_8 -> V_280 ) ;
V_284 [ V_240 ] = NULL ;
}
}
V_25 -> V_100 = V_35 ;
F_334 ( V_25 ) ;
}
struct V_24 * F_320 ( struct V_223 * V_224 ,
struct V_24 * V_25 )
{
V_25 -> V_139 = V_224 -> V_81 ;
V_25 -> V_285 = F_335 ( V_286 ,
F_1 ,
V_6 , V_25 ) ;
if ( ! V_25 -> V_285 )
goto V_287;
V_25 -> V_271 = F_336 ( struct V_11 ) ;
if ( ! V_25 -> V_271 )
goto V_287;
F_337 ( V_25 ) ;
V_25 -> V_102 = F_263 ( V_187 * sizeof( * ( V_25 -> V_102 ) ) ,
V_261 , V_224 -> V_234 ) ;
if ( ! V_25 -> V_102 )
goto V_288;
V_25 -> V_232 = V_224 -> V_232 ;
F_328 ( V_224 , V_25 ) ;
if ( ! V_25 -> V_100 )
goto V_289;
F_338 ( & V_25 -> V_148 , F_151 ) ;
F_339 ( V_25 , V_224 -> V_31 ? V_224 -> V_31 : 30 * V_290 ) ;
V_25 -> V_291 = V_187 ;
V_25 -> V_117 |= V_292 ;
if ( ! ( V_224 -> V_32 & V_293 ) )
V_25 -> V_117 |= 1 << V_294 ;
V_25 -> V_295 = V_296 ;
F_282 ( & V_25 -> V_127 , F_125 ) ;
F_53 ( & V_25 -> V_131 ) ;
F_283 ( & V_25 -> V_130 ) ;
F_340 ( V_25 , F_237 ) ;
V_25 -> V_297 = V_224 -> V_272 ;
V_25 -> V_298 = - 1 ;
if ( V_224 -> V_81 -> V_299 )
F_341 ( V_25 , V_224 -> V_81 -> V_299 ) ;
F_291 ( V_25 , V_224 -> V_100 ) ;
F_312 ( V_224 , V_25 ) ;
F_299 ( V_25 ) ;
if ( ! ( V_224 -> V_32 & V_300 ) ) {
int V_92 ;
V_92 = F_342 ( V_25 ) ;
if ( V_92 )
return F_74 ( V_92 ) ;
}
return V_25 ;
V_289:
F_257 ( V_25 -> V_102 ) ;
V_288:
F_317 ( V_25 -> V_271 ) ;
V_287:
V_25 -> V_139 = NULL ;
return F_74 ( - V_252 ) ;
}
void F_343 ( struct V_24 * V_25 )
{
struct V_223 * V_224 = V_25 -> V_273 ;
F_309 ( V_25 ) ;
F_280 ( V_25 , V_224 , V_224 -> V_100 ) ;
}
static void F_344 ( struct V_24 * V_25 )
{
F_31 ( ! F_345 ( & V_25 -> V_28 ) ) ;
F_346 ( V_25 ) ;
F_329 ( V_25 ) ;
F_299 ( V_25 ) ;
F_334 ( V_25 ) ;
F_347 ( V_25 ) ;
}
static int F_348 ( struct V_223 * V_224 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_224 -> V_100 ; V_35 ++ )
if ( ! F_297 ( V_224 , V_35 ) )
goto V_301;
return 0 ;
V_301:
while ( -- V_35 >= 0 )
F_256 ( V_224 -> V_39 [ V_35 ] ) ;
return - V_252 ;
}
static int F_349 ( struct V_223 * V_224 )
{
unsigned int V_203 ;
int V_302 ;
V_203 = V_224 -> V_272 ;
do {
V_302 = F_348 ( V_224 ) ;
if ( ! V_302 )
break;
V_224 -> V_272 >>= 1 ;
if ( V_224 -> V_272 < V_224 -> V_230 + V_303 ) {
V_302 = - V_252 ;
break;
}
} while ( V_224 -> V_272 );
if ( ! V_224 -> V_272 || V_302 ) {
F_350 ( L_2 ) ;
return - V_252 ;
}
if ( V_203 != V_224 -> V_272 )
F_351 ( L_3 ,
V_203 , V_224 -> V_272 ) ;
return 0 ;
}
static int F_352 ( struct V_223 * V_224 )
{
if ( V_224 -> V_81 -> V_304 )
return V_224 -> V_81 -> V_304 ( V_224 ) ;
else
return F_353 ( V_224 ) ;
}
int F_354 ( struct V_223 * V_224 )
{
int V_92 ;
F_324 ( V_305 > 1 << V_306 ) ;
if ( ! V_224 -> V_100 )
return - V_99 ;
if ( ! V_224 -> V_272 )
return - V_99 ;
if ( V_224 -> V_272 < V_224 -> V_230 + V_303 )
return - V_99 ;
if ( ! V_224 -> V_81 -> V_178 )
return - V_99 ;
if ( V_224 -> V_272 > V_305 ) {
F_351 ( L_4 ,
V_305 ) ;
V_224 -> V_272 = V_305 ;
}
if ( F_355 () ) {
V_224 -> V_100 = 1 ;
V_224 -> V_272 = F_164 ( 64U , V_224 -> V_272 ) ;
}
if ( V_224 -> V_100 > V_187 )
V_224 -> V_100 = V_187 ;
V_224 -> V_39 = F_263 ( V_187 * sizeof( struct V_44 * ) ,
V_261 , V_224 -> V_234 ) ;
if ( ! V_224 -> V_39 )
return - V_252 ;
V_92 = - V_252 ;
V_224 -> V_232 = F_263 ( sizeof( * V_224 -> V_232 ) * V_187 ,
V_261 , V_224 -> V_234 ) ;
if ( ! V_224 -> V_232 )
goto V_307;
V_92 = F_352 ( V_224 ) ;
if ( V_92 )
goto V_308;
V_92 = F_349 ( V_224 ) ;
if ( V_92 )
goto V_308;
F_356 ( & V_224 -> V_277 ) ;
F_53 ( & V_224 -> V_279 ) ;
return 0 ;
V_308:
F_257 ( V_224 -> V_232 ) ;
V_224 -> V_232 = NULL ;
V_307:
F_257 ( V_224 -> V_39 ) ;
V_224 -> V_39 = NULL ;
return V_92 ;
}
void F_357 ( struct V_223 * V_224 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_187 ; V_35 ++ )
F_298 ( V_224 , V_35 ) ;
F_257 ( V_224 -> V_232 ) ;
V_224 -> V_232 = NULL ;
F_257 ( V_224 -> V_39 ) ;
V_224 -> V_39 = NULL ;
}
int F_358 ( struct V_24 * V_25 , unsigned int V_309 )
{
struct V_223 * V_224 = V_25 -> V_273 ;
struct V_7 * V_8 ;
int V_35 , V_92 ;
if ( ! V_224 )
return - V_99 ;
F_28 ( V_25 ) ;
V_92 = 0 ;
F_39 (q, hctx, i) {
if ( ! V_8 -> V_39 )
continue;
if ( ! V_8 -> V_112 ) {
V_92 = F_359 ( V_8 , & V_8 -> V_39 ,
F_164 ( V_309 , V_224 -> V_272 ) ,
false ) ;
} else {
V_92 = F_359 ( V_8 , & V_8 -> V_112 ,
V_309 , true ) ;
}
if ( V_92 )
break;
}
if ( ! V_92 )
V_25 -> V_297 = V_309 ;
F_29 ( V_25 ) ;
return V_92 ;
}
static void F_360 ( struct V_223 * V_224 ,
int V_100 )
{
struct V_24 * V_25 ;
F_214 ( & V_224 -> V_277 ) ;
if ( V_100 > V_187 )
V_100 = V_187 ;
if ( V_100 < 1 || V_100 == V_224 -> V_100 )
return;
F_308 (q, &set->tag_list, tag_set_list)
F_28 ( V_25 ) ;
V_224 -> V_100 = V_100 ;
F_352 ( V_224 ) ;
F_308 (q, &set->tag_list, tag_set_list) {
F_328 ( V_224 , V_25 ) ;
F_344 ( V_25 ) ;
}
F_308 (q, &set->tag_list, tag_set_list)
F_29 ( V_25 ) ;
}
void F_361 ( struct V_223 * V_224 , int V_100 )
{
F_300 ( & V_224 -> V_277 ) ;
F_360 ( V_224 , V_100 ) ;
F_304 ( & V_224 -> V_277 ) ;
}
static bool F_362 ( struct V_24 * V_25 )
{
if ( F_15 ( V_310 , & V_25 -> V_117 ) ||
F_363 ( V_310 , & V_25 -> V_117 ) )
return true ;
F_364 ( V_25 , V_25 -> V_285 ) ;
return false ;
}
static void F_96 ( struct V_24 * V_25 )
{
if ( ! F_15 ( V_310 , & V_25 -> V_117 ) ||
F_365 ( V_25 -> V_285 ) )
return;
F_366 ( V_25 -> V_285 , 100 ) ;
}
static void V_286 ( struct V_311 * V_312 )
{
struct V_24 * V_25 = V_312 -> V_41 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_312 -> V_313 [ V_5 ] . V_314 )
V_25 -> V_315 [ V_5 ] = V_312 -> V_313 [ V_5 ] ;
}
}
static unsigned long F_367 ( struct V_24 * V_25 ,
struct V_7 * V_8 ,
struct V_1 * V_2 )
{
unsigned long V_92 = 0 ;
int V_5 ;
if ( ! F_362 ( V_25 ) )
return 0 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_92 ;
if ( V_25 -> V_315 [ V_5 ] . V_314 )
V_92 = ( V_25 -> V_315 [ V_5 ] . V_316 + 1 ) / 2 ;
return V_92 ;
}
static bool F_368 ( struct V_24 * V_25 ,
struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_317 V_318 ;
enum V_319 V_164 ;
unsigned int V_320 ;
T_5 V_321 ;
if ( F_15 ( V_111 , & V_2 -> V_19 ) )
return false ;
if ( V_25 -> V_298 == - 1 )
return false ;
else if ( V_25 -> V_298 > 0 )
V_320 = V_25 -> V_298 ;
else
V_320 = F_367 ( V_25 , V_8 , V_2 ) ;
if ( ! V_320 )
return false ;
F_115 ( V_111 , & V_2 -> V_19 ) ;
V_321 = V_320 ;
V_164 = V_322 ;
F_369 ( & V_318 . V_323 , V_324 , V_164 ) ;
F_370 ( & V_318 . V_323 , V_321 ) ;
F_371 ( & V_318 , V_219 ) ;
do {
if ( F_15 ( V_20 , & V_2 -> V_19 ) )
break;
F_372 ( V_325 ) ;
F_373 ( & V_318 . V_323 , V_164 ) ;
if ( V_318 . V_326 )
F_374 () ;
F_375 ( & V_318 . V_323 ) ;
V_164 = V_327 ;
} while ( V_318 . V_326 && ! F_376 ( V_219 ) );
F_377 ( V_328 ) ;
F_378 ( & V_318 . V_323 ) ;
return true ;
}
static bool F_379 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_24 * V_25 = V_8 -> V_185 ;
long V_169 ;
if ( F_368 ( V_25 , V_8 , V_2 ) )
return true ;
V_8 -> V_329 ++ ;
V_169 = V_219 -> V_169 ;
while ( ! F_380 () ) {
int V_92 ;
V_8 -> V_330 ++ ;
V_92 = V_25 -> V_139 -> V_331 ( V_8 , V_2 -> V_42 ) ;
if ( V_92 > 0 ) {
V_8 -> V_332 ++ ;
F_372 ( V_328 ) ;
return true ;
}
if ( F_381 ( V_169 , V_219 ) )
F_372 ( V_328 ) ;
if ( V_219 -> V_169 == V_328 )
return true ;
if ( V_92 < 0 )
break;
F_382 () ;
}
return false ;
}
bool F_383 ( struct V_24 * V_25 , T_3 V_207 )
{
struct V_7 * V_8 ;
struct V_197 * V_198 ;
struct V_1 * V_2 ;
if ( ! V_25 -> V_139 || ! V_25 -> V_139 -> V_331 || ! F_384 ( V_207 ) ||
! F_15 ( V_333 , & V_25 -> V_117 ) )
return false ;
V_198 = V_219 -> V_198 ;
if ( V_198 )
F_251 ( V_198 , false ) ;
V_8 = V_25 -> V_102 [ F_385 ( V_207 ) ] ;
if ( ! F_386 ( V_207 ) )
V_2 = F_143 ( V_8 -> V_39 , F_387 ( V_207 ) ) ;
else {
V_2 = F_143 ( V_8 -> V_112 , F_387 ( V_207 ) ) ;
if ( ! V_2 )
return false ;
}
return F_379 ( V_8 , V_2 ) ;
}
static int T_6 F_388 ( void )
{
F_389 ( V_255 , L_5 , NULL ,
F_270 ) ;
return 0 ;
}
