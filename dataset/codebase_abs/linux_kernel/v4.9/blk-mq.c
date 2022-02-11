static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
if ( ! F_4 ( & V_2 -> V_3 , V_5 -> V_6 ) )
F_5 ( & V_2 -> V_3 , V_5 -> V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
F_7 ( & V_2 -> V_3 , V_5 -> V_6 ) ;
}
void F_8 ( struct V_7 * V_8 )
{
int V_9 ;
V_9 = F_9 ( & V_8 -> V_10 ) ;
if ( V_9 == 1 ) {
F_10 ( & V_8 -> V_11 ) ;
F_11 ( V_8 , false ) ;
}
}
static void F_12 ( struct V_7 * V_8 )
{
F_13 ( V_8 -> V_12 , F_14 ( & V_8 -> V_11 ) ) ;
}
void F_15 ( struct V_7 * V_8 )
{
F_8 ( V_8 ) ;
F_12 ( V_8 ) ;
}
void F_16 ( struct V_7 * V_8 )
{
F_15 ( V_8 ) ;
}
void F_17 ( struct V_7 * V_8 )
{
int V_9 ;
V_9 = F_18 ( & V_8 -> V_10 ) ;
F_19 ( V_9 < 0 ) ;
if ( ! V_9 ) {
F_20 ( & V_8 -> V_11 ) ;
F_21 ( & V_8 -> V_12 ) ;
}
}
void F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_23 (q, hctx, i)
if ( F_24 ( V_2 ) )
F_25 ( V_2 -> V_14 , true ) ;
F_21 ( & V_8 -> V_12 ) ;
}
bool F_26 ( struct V_1 * V_2 )
{
return F_27 ( V_2 -> V_14 ) ;
}
static void F_28 ( struct V_7 * V_8 , struct V_4 * V_5 ,
struct V_15 * V_16 , int V_17 ,
unsigned int V_18 )
{
if ( F_29 ( V_8 ) )
V_18 |= V_19 ;
F_30 ( & V_16 -> V_20 ) ;
V_16 -> V_8 = V_8 ;
V_16 -> V_21 = V_5 ;
F_31 ( V_16 , V_17 , V_18 ) ;
V_16 -> V_22 = - 1 ;
F_32 ( & V_16 -> V_23 ) ;
F_33 ( & V_16 -> V_24 ) ;
V_16 -> V_25 = NULL ;
V_16 -> V_26 = NULL ;
V_16 -> V_27 = V_28 ;
#ifdef F_34
V_16 -> V_29 = NULL ;
F_35 ( V_16 ) ;
V_16 -> V_30 = 0 ;
#endif
V_16 -> V_31 = 0 ;
#if F_36 ( V_32 )
V_16 -> V_33 = 0 ;
#endif
V_16 -> V_34 = NULL ;
V_16 -> V_35 = 0 ;
V_16 -> V_36 = V_16 -> V_37 ;
V_16 -> V_38 = 0 ;
V_16 -> V_39 = 0 ;
V_16 -> V_40 = 0 ;
V_16 -> V_41 = NULL ;
F_30 ( & V_16 -> V_42 ) ;
V_16 -> V_43 = 0 ;
V_16 -> V_44 = NULL ;
V_16 -> V_45 = NULL ;
V_16 -> V_46 = NULL ;
V_5 -> V_47 [ F_37 ( V_17 , V_18 ) ] ++ ;
}
static struct V_15 *
F_38 ( struct V_48 * V_49 , int V_17 , int V_18 )
{
struct V_15 * V_16 ;
unsigned int V_50 ;
V_50 = F_39 ( V_49 ) ;
if ( V_50 != V_51 ) {
V_16 = V_49 -> V_2 -> V_14 -> V_52 [ V_50 ] ;
if ( F_40 ( V_49 -> V_2 ) ) {
V_16 -> V_53 = V_54 ;
F_41 ( & V_49 -> V_2 -> V_55 ) ;
}
V_16 -> V_50 = V_50 ;
F_28 ( V_49 -> V_8 , V_49 -> V_5 , V_16 , V_17 , V_18 ) ;
return V_16 ;
}
return NULL ;
}
struct V_15 * F_42 ( struct V_7 * V_8 , int V_56 ,
unsigned int V_57 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_48 V_58 ;
int V_59 ;
V_59 = F_43 ( V_8 , V_57 & V_60 ) ;
if ( V_59 )
return F_44 ( V_59 ) ;
V_5 = F_45 ( V_8 ) ;
V_2 = F_46 ( V_8 , V_5 -> V_22 ) ;
F_47 ( & V_58 , V_8 , V_57 , V_5 , V_2 ) ;
V_16 = F_38 ( & V_58 , V_56 , 0 ) ;
F_48 ( V_5 ) ;
if ( ! V_16 ) {
F_49 ( V_8 ) ;
return F_44 ( - V_61 ) ;
}
V_16 -> V_62 = 0 ;
V_16 -> V_63 = ( V_64 ) - 1 ;
V_16 -> V_65 = V_16 -> V_66 = NULL ;
return V_16 ;
}
struct V_15 * F_50 ( struct V_7 * V_8 , int V_56 ,
unsigned int V_57 , unsigned int V_67 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
struct V_48 V_58 ;
int V_59 ;
if ( F_19 ( ! ( V_57 & V_60 ) ) )
return F_44 ( - V_68 ) ;
if ( V_67 >= V_8 -> V_69 )
return F_44 ( - V_70 ) ;
V_59 = F_43 ( V_8 , true ) ;
if ( V_59 )
return F_44 ( V_59 ) ;
V_2 = V_8 -> V_71 [ V_67 ] ;
if ( ! F_24 ( V_2 ) ) {
V_59 = - V_72 ;
goto V_73;
}
V_5 = F_51 ( V_8 , F_52 ( V_2 -> V_74 ) ) ;
F_47 ( & V_58 , V_8 , V_57 , V_5 , V_2 ) ;
V_16 = F_38 ( & V_58 , V_56 , 0 ) ;
if ( ! V_16 ) {
V_59 = - V_61 ;
goto V_73;
}
return V_16 ;
V_73:
F_49 ( V_8 ) ;
return F_44 ( V_59 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_4 * V_5 , struct V_15 * V_16 )
{
const int V_50 = V_16 -> V_50 ;
struct V_7 * V_8 = V_16 -> V_8 ;
if ( V_16 -> V_53 & V_54 )
F_54 ( & V_2 -> V_55 ) ;
V_16 -> V_53 = 0 ;
F_55 ( V_75 , & V_16 -> V_76 ) ;
F_56 ( V_2 , V_5 , V_50 ) ;
F_49 ( V_8 ) ;
}
void F_57 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_21 ;
V_5 -> V_77 [ F_58 ( V_16 ) ] ++ ;
F_53 ( V_2 , V_5 , V_16 ) ;
}
void F_59 ( struct V_15 * V_16 )
{
F_57 ( F_46 ( V_16 -> V_8 , V_16 -> V_21 -> V_22 ) , V_16 ) ;
}
inline void F_60 ( struct V_15 * V_16 , int error )
{
F_61 ( V_16 ) ;
if ( V_16 -> V_44 ) {
V_16 -> V_44 ( V_16 , error ) ;
} else {
if ( F_62 ( F_63 ( V_16 ) ) )
F_59 ( V_16 -> V_46 ) ;
F_59 ( V_16 ) ;
}
}
void F_64 ( struct V_15 * V_16 , int error )
{
if ( F_65 ( V_16 , error , F_66 ( V_16 ) ) )
F_67 () ;
F_60 ( V_16 , error ) ;
}
static void F_68 ( void * V_49 )
{
struct V_15 * V_16 = V_49 ;
V_16 -> V_8 -> V_78 ( V_16 ) ;
}
static void F_69 ( struct V_15 * V_16 )
{
struct V_4 * V_5 = V_16 -> V_21 ;
bool V_79 = false ;
int V_22 ;
if ( ! F_70 ( V_80 , & V_16 -> V_8 -> V_81 ) ) {
V_16 -> V_8 -> V_78 ( V_16 ) ;
return;
}
V_22 = F_71 () ;
if ( ! F_70 ( V_82 , & V_16 -> V_8 -> V_81 ) )
V_79 = F_72 ( V_22 , V_5 -> V_22 ) ;
if ( V_22 != V_5 -> V_22 && ! V_79 && F_73 ( V_5 -> V_22 ) ) {
V_16 -> V_83 . V_84 = F_68 ;
V_16 -> V_83 . V_85 = V_16 ;
V_16 -> V_83 . V_57 = 0 ;
F_74 ( V_5 -> V_22 , & V_16 -> V_83 ) ;
} else {
V_16 -> V_8 -> V_78 ( V_16 ) ;
}
F_75 () ;
}
static void F_76 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = V_16 -> V_8 ;
if ( ! V_8 -> V_78 )
F_64 ( V_16 , V_16 -> V_35 ) ;
else
F_69 ( V_16 ) ;
}
void F_77 ( struct V_15 * V_16 , int error )
{
struct V_7 * V_8 = V_16 -> V_8 ;
if ( F_62 ( F_78 ( V_8 ) ) )
return;
if ( ! F_79 ( V_16 ) ) {
V_16 -> V_35 = error ;
F_76 ( V_16 ) ;
}
}
int F_80 ( struct V_15 * V_16 )
{
return F_70 ( V_75 , & V_16 -> V_76 ) ;
}
void F_81 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = V_16 -> V_8 ;
F_82 ( V_8 , V_16 ) ;
V_16 -> V_40 = F_66 ( V_16 ) ;
if ( F_62 ( F_63 ( V_16 ) ) )
V_16 -> V_46 -> V_40 = F_66 ( V_16 -> V_46 ) ;
F_83 ( V_16 ) ;
F_84 () ;
if ( ! F_70 ( V_75 , & V_16 -> V_76 ) )
F_85 ( V_75 , & V_16 -> V_76 ) ;
if ( F_70 ( V_86 , & V_16 -> V_76 ) )
F_55 ( V_86 , & V_16 -> V_76 ) ;
if ( V_8 -> V_87 && F_66 ( V_16 ) ) {
V_16 -> V_31 ++ ;
}
}
static void F_86 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = V_16 -> V_8 ;
F_87 ( V_8 , V_16 ) ;
if ( F_88 ( V_75 , & V_16 -> V_76 ) ) {
if ( V_8 -> V_87 && F_66 ( V_16 ) )
V_16 -> V_31 -- ;
}
}
void F_89 ( struct V_15 * V_16 )
{
F_86 ( V_16 ) ;
F_90 ( F_91 ( V_16 ) ) ;
F_92 ( V_16 , true ) ;
}
static void F_93 ( struct V_88 * V_89 )
{
struct V_7 * V_8 =
F_94 ( V_89 , struct V_7 , V_90 . V_89 ) ;
F_95 ( V_91 ) ;
struct V_15 * V_16 , * V_92 ;
unsigned long V_57 ;
F_96 ( & V_8 -> V_93 , V_57 ) ;
F_97 ( & V_8 -> V_94 , & V_91 ) ;
F_98 ( & V_8 -> V_93 , V_57 ) ;
F_99 (rq, next, &rq_list, queuelist) {
if ( ! ( V_16 -> V_53 & V_95 ) )
continue;
V_16 -> V_53 &= ~ V_95 ;
F_100 ( & V_16 -> V_20 ) ;
F_101 ( V_16 , true , false , false ) ;
}
while ( ! F_102 ( & V_91 ) ) {
V_16 = F_103 ( V_91 . V_92 , struct V_15 , V_20 ) ;
F_100 ( & V_16 -> V_20 ) ;
F_101 ( V_16 , false , false , false ) ;
}
F_104 ( V_8 ) ;
}
void F_92 ( struct V_15 * V_16 , bool V_96 )
{
struct V_7 * V_8 = V_16 -> V_8 ;
unsigned long V_57 ;
F_90 ( V_16 -> V_53 & V_95 ) ;
F_96 ( & V_8 -> V_93 , V_57 ) ;
if ( V_96 ) {
V_16 -> V_53 |= V_95 ;
F_105 ( & V_16 -> V_20 , & V_8 -> V_94 ) ;
} else {
F_106 ( & V_16 -> V_20 , & V_8 -> V_94 ) ;
}
F_98 ( & V_8 -> V_93 , V_57 ) ;
}
void F_107 ( struct V_7 * V_8 )
{
F_108 ( & V_8 -> V_90 ) ;
}
void F_109 ( struct V_7 * V_8 )
{
F_110 ( & V_8 -> V_90 , 0 ) ;
}
void F_111 ( struct V_7 * V_8 ,
unsigned long V_97 )
{
F_110 ( & V_8 -> V_90 ,
F_112 ( V_97 ) ) ;
}
void F_113 ( struct V_7 * V_8 )
{
unsigned long V_57 ;
F_95 ( V_91 ) ;
F_96 ( & V_8 -> V_93 , V_57 ) ;
F_97 ( & V_8 -> V_94 , & V_91 ) ;
F_98 ( & V_8 -> V_93 , V_57 ) ;
while ( ! F_102 ( & V_91 ) ) {
struct V_15 * V_16 ;
V_16 = F_114 ( & V_91 , struct V_15 , V_20 ) ;
F_100 ( & V_16 -> V_20 ) ;
V_16 -> V_35 = - V_70 ;
F_64 ( V_16 , V_16 -> V_35 ) ;
}
}
struct V_15 * F_115 ( struct V_98 * V_14 , unsigned int V_50 )
{
if ( V_50 < V_14 -> V_99 ) {
F_116 ( V_14 -> V_52 [ V_50 ] ) ;
return V_14 -> V_52 [ V_50 ] ;
}
return NULL ;
}
void F_117 ( struct V_15 * V_100 , bool V_101 )
{
struct V_102 * V_103 = V_100 -> V_8 -> V_104 ;
enum V_105 V_59 = V_106 ;
if ( ! F_70 ( V_75 , & V_100 -> V_76 ) )
return;
if ( V_103 -> V_43 )
V_59 = V_103 -> V_43 ( V_100 , V_101 ) ;
switch ( V_59 ) {
case V_107 :
F_76 ( V_100 ) ;
break;
case V_106 :
F_83 ( V_100 ) ;
F_118 ( V_100 ) ;
break;
case V_108 :
break;
default:
F_119 ( V_109 L_1 , V_59 ) ;
break;
}
}
static void F_120 ( struct V_1 * V_2 ,
struct V_15 * V_16 , void * V_110 , bool V_101 )
{
struct V_111 * V_49 = V_110 ;
if ( ! F_70 ( V_75 , & V_16 -> V_76 ) ) {
if ( F_62 ( F_121 ( V_16 -> V_8 ) ) ) {
V_16 -> V_35 = - V_70 ;
F_64 ( V_16 , V_16 -> V_35 ) ;
}
return;
}
if ( F_122 ( V_28 , V_16 -> V_112 ) ) {
if ( ! F_79 ( V_16 ) )
F_117 ( V_16 , V_101 ) ;
} else if ( ! V_49 -> V_113 || F_123 ( V_49 -> V_92 , V_16 -> V_112 ) ) {
V_49 -> V_92 = V_16 -> V_112 ;
V_49 -> V_113 = 1 ;
}
}
static void F_124 ( struct V_88 * V_89 )
{
struct V_7 * V_8 =
F_94 ( V_89 , struct V_7 , V_114 ) ;
struct V_111 V_49 = {
. V_92 = 0 ,
. V_113 = 0 ,
} ;
int V_13 ;
if ( ! F_125 ( & V_8 -> V_11 ) )
return;
F_126 ( V_8 , F_120 , & V_49 ) ;
if ( V_49 . V_113 ) {
V_49 . V_92 = F_127 ( F_128 ( V_49 . V_92 ) ) ;
F_129 ( & V_8 -> V_43 , V_49 . V_92 ) ;
} else {
struct V_1 * V_2 ;
F_23 (q, hctx, i) {
if ( F_24 ( V_2 ) )
F_130 ( V_2 ) ;
}
}
F_49 ( V_8 ) ;
}
static bool F_131 ( struct V_7 * V_8 ,
struct V_4 * V_5 , struct V_65 * V_65 )
{
struct V_15 * V_16 ;
int V_115 = 8 ;
F_132 (rq, &ctx->rq_list, queuelist) {
int V_116 ;
if ( ! V_115 -- )
break;
if ( ! F_133 ( V_16 , V_65 ) )
continue;
V_116 = F_134 ( V_16 , V_65 ) ;
if ( V_116 == V_117 ) {
if ( F_135 ( V_8 , V_16 , V_65 ) ) {
V_5 -> V_118 ++ ;
return true ;
}
break;
} else if ( V_116 == V_119 ) {
if ( F_136 ( V_8 , V_16 , V_65 ) ) {
V_5 -> V_118 ++ ;
return true ;
}
break;
}
}
return false ;
}
static bool F_137 ( struct V_120 * V_121 , unsigned int V_122 , void * V_49 )
{
struct V_123 * V_124 = V_49 ;
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_125 [ V_122 ] ;
F_7 ( V_121 , V_122 ) ;
F_138 ( & V_5 -> V_126 ) ;
F_139 ( & V_5 -> V_91 , V_124 -> V_127 ) ;
F_140 ( & V_5 -> V_126 ) ;
return true ;
}
static void F_141 ( struct V_1 * V_2 , struct V_128 * V_127 )
{
struct V_123 V_49 = {
. V_2 = V_2 ,
. V_127 = V_127 ,
} ;
F_142 ( & V_2 -> V_3 , F_137 , & V_49 ) ;
}
static inline unsigned int F_143 ( unsigned int V_129 )
{
if ( ! V_129 )
return 0 ;
return F_144 ( V_130 - 1 , F_145 ( V_129 ) + 1 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_131 ;
struct V_15 * V_16 ;
F_95 ( V_91 ) ;
F_95 ( V_132 ) ;
struct V_128 * V_133 ;
int V_129 ;
if ( F_62 ( F_70 ( V_134 , & V_2 -> V_135 ) ) )
return;
F_147 ( ! F_148 ( F_149 () , V_2 -> V_74 ) &&
F_73 ( V_2 -> V_136 ) ) ;
V_2 -> V_137 ++ ;
F_141 ( V_2 , & V_91 ) ;
if ( ! F_150 ( & V_2 -> V_138 ) ) {
F_138 ( & V_2 -> V_126 ) ;
if ( ! F_102 ( & V_2 -> V_138 ) )
F_97 ( & V_2 -> V_138 , & V_91 ) ;
F_140 ( & V_2 -> V_126 ) ;
}
V_133 = NULL ;
V_129 = 0 ;
while ( ! F_102 ( & V_91 ) ) {
struct V_139 V_140 ;
int V_59 ;
V_16 = F_114 ( & V_91 , struct V_15 , V_20 ) ;
F_100 ( & V_16 -> V_20 ) ;
V_140 . V_16 = V_16 ;
V_140 . V_127 = V_133 ;
V_140 . V_141 = F_102 ( & V_91 ) ;
V_59 = V_8 -> V_104 -> V_142 ( V_2 , & V_140 ) ;
switch ( V_59 ) {
case V_143 :
V_129 ++ ;
break;
case V_144 :
F_105 ( & V_16 -> V_20 , & V_91 ) ;
F_86 ( V_16 ) ;
break;
default:
F_151 ( L_2 , V_59 ) ;
case V_145 :
V_16 -> V_35 = - V_70 ;
F_64 ( V_16 , V_16 -> V_35 ) ;
break;
}
if ( V_59 == V_144 )
break;
if ( ! V_133 && V_91 . V_92 != V_91 . V_146 )
V_133 = & V_132 ;
}
V_2 -> V_147 [ F_143 ( V_129 ) ] ++ ;
if ( ! F_102 ( & V_91 ) ) {
F_138 ( & V_2 -> V_126 ) ;
F_152 ( & V_91 , & V_2 -> V_138 ) ;
F_140 ( & V_2 -> V_126 ) ;
F_153 ( V_2 , true ) ;
}
}
static int F_154 ( struct V_1 * V_2 )
{
if ( V_2 -> V_131 -> V_69 == 1 )
return V_148 ;
if ( -- V_2 -> V_149 <= 0 ) {
int V_22 = V_2 -> V_136 , V_136 ;
V_136 = F_155 ( V_2 -> V_136 , V_2 -> V_74 ) ;
if ( V_136 >= V_150 )
V_136 = F_52 ( V_2 -> V_74 ) ;
V_2 -> V_136 = V_136 ;
V_2 -> V_149 = V_151 ;
return V_22 ;
}
return V_2 -> V_136 ;
}
void F_153 ( struct V_1 * V_2 , bool V_152 )
{
if ( F_62 ( F_70 ( V_134 , & V_2 -> V_135 ) ||
! F_24 ( V_2 ) ) )
return;
if ( ! V_152 && ! ( V_2 -> V_57 & V_153 ) ) {
int V_22 = F_71 () ;
if ( F_148 ( V_22 , V_2 -> V_74 ) ) {
F_146 ( V_2 ) ;
F_75 () ;
return;
}
F_75 () ;
}
F_156 ( F_154 ( V_2 ) , & V_2 -> V_154 ) ;
}
void F_11 ( struct V_7 * V_8 , bool V_152 )
{
struct V_1 * V_2 ;
int V_13 ;
F_23 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_150 ( & V_2 -> V_138 ) ) ||
F_70 ( V_134 , & V_2 -> V_135 ) )
continue;
F_153 ( V_2 , V_152 ) ;
}
}
void F_157 ( struct V_1 * V_2 )
{
F_158 ( & V_2 -> V_154 ) ;
F_159 ( & V_2 -> V_155 ) ;
F_85 ( V_134 , & V_2 -> V_135 ) ;
}
void F_160 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_13 ;
F_23 (q, hctx, i)
F_157 ( V_2 ) ;
}
void F_161 ( struct V_1 * V_2 )
{
F_55 ( V_134 , & V_2 -> V_135 ) ;
F_153 ( V_2 , false ) ;
}
void F_104 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_13 ;
F_23 (q, hctx, i)
F_161 ( V_2 ) ;
}
void F_162 ( struct V_7 * V_8 , bool V_152 )
{
struct V_1 * V_2 ;
int V_13 ;
F_23 (q, hctx, i) {
if ( ! F_70 ( V_134 , & V_2 -> V_135 ) )
continue;
F_55 ( V_134 , & V_2 -> V_135 ) ;
F_153 ( V_2 , V_152 ) ;
}
}
static void F_163 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_89 , struct V_1 , V_154 ) ;
F_146 ( V_2 ) ;
}
static void F_164 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( V_89 , struct V_1 , V_155 . V_89 ) ;
if ( F_88 ( V_134 , & V_2 -> V_135 ) )
F_146 ( V_2 ) ;
}
void F_165 ( struct V_1 * V_2 , unsigned long V_97 )
{
if ( F_62 ( ! F_24 ( V_2 ) ) )
return;
F_166 ( F_154 ( V_2 ) ,
& V_2 -> V_155 , F_112 ( V_97 ) ) ;
}
static inline void F_167 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
bool V_96 )
{
struct V_4 * V_5 = V_16 -> V_21 ;
F_168 ( V_2 -> V_131 , V_16 ) ;
if ( V_96 )
F_105 ( & V_16 -> V_20 , & V_5 -> V_91 ) ;
else
F_106 ( & V_16 -> V_20 , & V_5 -> V_91 ) ;
}
static void F_169 ( struct V_1 * V_2 ,
struct V_15 * V_16 , bool V_96 )
{
struct V_4 * V_5 = V_16 -> V_21 ;
F_167 ( V_2 , V_16 , V_96 ) ;
F_3 ( V_2 , V_5 ) ;
}
void F_101 ( struct V_15 * V_16 , bool V_96 , bool V_156 ,
bool V_152 )
{
struct V_4 * V_5 = V_16 -> V_21 ;
struct V_7 * V_8 = V_16 -> V_8 ;
struct V_1 * V_2 = F_46 ( V_8 , V_5 -> V_22 ) ;
F_138 ( & V_5 -> V_126 ) ;
F_169 ( V_2 , V_16 , V_96 ) ;
F_140 ( & V_5 -> V_126 ) ;
if ( V_156 )
F_153 ( V_2 , V_152 ) ;
}
static void F_170 ( struct V_7 * V_8 ,
struct V_4 * V_5 ,
struct V_128 * V_127 ,
int V_157 ,
bool V_158 )
{
struct V_1 * V_2 = F_46 ( V_8 , V_5 -> V_22 ) ;
F_171 ( V_8 , V_157 , ! V_158 ) ;
F_138 ( & V_5 -> V_126 ) ;
while ( ! F_102 ( V_127 ) ) {
struct V_15 * V_16 ;
V_16 = F_114 ( V_127 , struct V_15 , V_20 ) ;
F_90 ( V_16 -> V_21 != V_5 ) ;
F_100 ( & V_16 -> V_20 ) ;
F_167 ( V_2 , V_16 , false ) ;
}
F_3 ( V_2 , V_5 ) ;
F_140 ( & V_5 -> V_126 ) ;
F_153 ( V_2 , V_158 ) ;
}
static int F_172 ( void * V_110 , struct V_128 * V_159 , struct V_128 * V_160 )
{
struct V_15 * V_161 = F_94 ( V_159 , struct V_15 , V_20 ) ;
struct V_15 * V_162 = F_94 ( V_160 , struct V_15 , V_20 ) ;
return ! ( V_161 -> V_21 < V_162 -> V_21 ||
( V_161 -> V_21 == V_162 -> V_21 &&
F_173 ( V_161 ) < F_173 ( V_162 ) ) ) ;
}
void F_174 ( struct V_163 * V_164 , bool V_158 )
{
struct V_4 * V_165 ;
struct V_7 * V_166 ;
struct V_15 * V_16 ;
F_95 ( V_127 ) ;
F_95 ( V_167 ) ;
unsigned int V_157 ;
F_97 ( & V_164 -> V_168 , & V_127 ) ;
F_175 ( NULL , & V_127 , F_172 ) ;
V_166 = NULL ;
V_165 = NULL ;
V_157 = 0 ;
while ( ! F_102 ( & V_127 ) ) {
V_16 = F_176 ( V_127 . V_92 ) ;
F_100 ( & V_16 -> V_20 ) ;
F_90 ( ! V_16 -> V_8 ) ;
if ( V_16 -> V_21 != V_165 ) {
if ( V_165 ) {
F_170 ( V_166 , V_165 ,
& V_167 , V_157 ,
V_158 ) ;
}
V_165 = V_16 -> V_21 ;
V_166 = V_16 -> V_8 ;
V_157 = 0 ;
}
V_157 ++ ;
F_106 ( & V_16 -> V_20 , & V_167 ) ;
}
if ( V_165 ) {
F_170 ( V_166 , V_165 , & V_167 , V_157 ,
V_158 ) ;
}
}
static void F_177 ( struct V_15 * V_16 , struct V_65 * V_65 )
{
F_178 ( V_16 , V_65 ) ;
F_179 ( V_16 , 1 ) ;
}
static inline bool F_180 ( struct V_1 * V_2 )
{
return ( V_2 -> V_57 & V_169 ) &&
! F_181 ( V_2 -> V_131 ) ;
}
static inline bool F_182 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
struct V_15 * V_16 , struct V_65 * V_65 )
{
if ( ! F_180 ( V_2 ) || ! F_183 ( V_65 ) ) {
F_177 ( V_16 , V_65 ) ;
F_138 ( & V_5 -> V_126 ) ;
V_170:
F_169 ( V_2 , V_16 , false ) ;
F_140 ( & V_5 -> V_126 ) ;
return false ;
} else {
struct V_7 * V_8 = V_2 -> V_131 ;
F_138 ( & V_5 -> V_126 ) ;
if ( ! F_131 ( V_8 , V_5 , V_65 ) ) {
F_177 ( V_16 , V_65 ) ;
goto V_170;
}
F_140 ( & V_5 -> V_126 ) ;
F_53 ( V_2 , V_5 , V_16 ) ;
return true ;
}
}
static struct V_15 * F_184 ( struct V_7 * V_8 ,
struct V_65 * V_65 ,
struct V_171 * V_49 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_15 * V_16 ;
int V_17 = F_185 ( V_65 ) ;
int V_18 = 0 ;
struct V_48 V_58 ;
F_186 ( V_8 ) ;
V_5 = F_45 ( V_8 ) ;
V_2 = F_46 ( V_8 , V_5 -> V_22 ) ;
if ( F_37 ( F_187 ( V_65 ) , V_65 -> V_172 ) )
V_18 |= V_173 ;
F_188 ( V_8 , V_65 , V_17 ) ;
F_47 ( & V_58 , V_8 , 0 , V_5 , V_2 ) ;
V_16 = F_38 ( & V_58 , V_17 , V_18 ) ;
V_49 -> V_2 = V_58 . V_2 ;
V_49 -> V_5 = V_58 . V_5 ;
V_49 -> V_2 -> V_129 ++ ;
return V_16 ;
}
static int F_189 ( struct V_15 * V_16 , T_1 * V_174 )
{
int V_59 ;
struct V_7 * V_8 = V_16 -> V_8 ;
struct V_1 * V_2 = F_46 ( V_8 , V_16 -> V_21 -> V_22 ) ;
struct V_139 V_140 = {
. V_16 = V_16 ,
. V_127 = NULL ,
. V_141 = 1
} ;
T_1 V_175 = F_190 ( V_16 -> V_50 , V_2 -> V_176 ) ;
V_59 = V_8 -> V_104 -> V_142 ( V_2 , & V_140 ) ;
if ( V_59 == V_143 ) {
* V_174 = V_175 ;
return 0 ;
}
F_86 ( V_16 ) ;
if ( V_59 == V_145 ) {
* V_174 = V_177 ;
V_16 -> V_35 = - V_70 ;
F_64 ( V_16 , V_16 -> V_35 ) ;
return 0 ;
}
return - 1 ;
}
static T_1 F_191 ( struct V_7 * V_8 , struct V_65 * V_65 )
{
const int V_178 = F_37 ( F_187 ( V_65 ) , V_65 -> V_172 ) ;
const int V_179 = V_65 -> V_172 & ( V_180 | V_181 ) ;
struct V_171 V_49 ;
struct V_15 * V_16 ;
unsigned int V_182 = 0 ;
struct V_163 * V_164 ;
struct V_15 * V_183 = NULL ;
T_1 V_174 ;
F_192 ( V_8 , & V_65 ) ;
if ( F_193 ( V_65 ) && F_194 ( V_65 ) ) {
F_195 ( V_65 ) ;
return V_177 ;
}
F_196 ( V_8 , & V_65 , V_8 -> V_184 ) ;
if ( ! V_179 && ! F_181 ( V_8 ) &&
F_197 ( V_8 , V_65 , & V_182 , & V_183 ) )
return V_177 ;
V_16 = F_184 ( V_8 , V_65 , & V_49 ) ;
if ( F_62 ( ! V_16 ) )
return V_177 ;
V_174 = F_190 ( V_16 -> V_50 , V_49 . V_2 -> V_176 ) ;
if ( F_62 ( V_179 ) ) {
F_177 ( V_16 , V_65 ) ;
F_198 ( V_16 ) ;
goto V_156;
}
V_164 = V_185 -> V_164 ;
if ( ( ( V_164 && ! F_181 ( V_8 ) ) || V_178 ) &&
! ( V_49 . V_2 -> V_57 & V_186 ) ) {
struct V_15 * V_187 = NULL ;
F_177 ( V_16 , V_65 ) ;
if ( V_164 ) {
if ( V_183 && ! F_102 ( & V_164 -> V_168 ) ) {
V_187 = V_183 ;
F_100 ( & V_187 -> V_20 ) ;
}
F_106 ( & V_16 -> V_20 , & V_164 -> V_168 ) ;
} else
V_187 = V_16 ;
F_48 ( V_49 . V_5 ) ;
if ( ! V_187 )
goto V_188;
if ( ! F_189 ( V_187 , & V_174 ) )
goto V_188;
F_101 ( V_187 , false , true , true ) ;
goto V_188;
}
if ( ! F_182 ( V_49 . V_2 , V_49 . V_5 , V_16 , V_65 ) ) {
V_156:
F_153 ( V_49 . V_2 , ! V_178 || V_179 ) ;
}
F_48 ( V_49 . V_5 ) ;
V_188:
return V_174 ;
}
static T_1 F_199 ( struct V_7 * V_8 , struct V_65 * V_65 )
{
const int V_178 = F_37 ( F_187 ( V_65 ) , V_65 -> V_172 ) ;
const int V_179 = V_65 -> V_172 & ( V_180 | V_181 ) ;
struct V_163 * V_164 ;
unsigned int V_182 = 0 ;
struct V_171 V_49 ;
struct V_15 * V_16 ;
T_1 V_174 ;
F_192 ( V_8 , & V_65 ) ;
if ( F_193 ( V_65 ) && F_194 ( V_65 ) ) {
F_195 ( V_65 ) ;
return V_177 ;
}
F_196 ( V_8 , & V_65 , V_8 -> V_184 ) ;
if ( ! V_179 && ! F_181 ( V_8 ) ) {
if ( F_197 ( V_8 , V_65 , & V_182 , NULL ) )
return V_177 ;
} else
V_182 = F_200 ( V_8 ) ;
V_16 = F_184 ( V_8 , V_65 , & V_49 ) ;
if ( F_62 ( ! V_16 ) )
return V_177 ;
V_174 = F_190 ( V_16 -> V_50 , V_49 . V_2 -> V_176 ) ;
if ( F_62 ( V_179 ) ) {
F_177 ( V_16 , V_65 ) ;
F_198 ( V_16 ) ;
goto V_156;
}
V_164 = V_185 -> V_164 ;
if ( V_164 ) {
F_177 ( V_16 , V_65 ) ;
if ( ! V_182 )
F_201 ( V_8 ) ;
F_48 ( V_49 . V_5 ) ;
if ( V_182 >= V_189 ) {
F_202 ( V_164 , false ) ;
F_201 ( V_8 ) ;
}
F_106 ( & V_16 -> V_20 , & V_164 -> V_168 ) ;
return V_174 ;
}
if ( ! F_182 ( V_49 . V_2 , V_49 . V_5 , V_16 , V_65 ) ) {
V_156:
F_153 ( V_49 . V_2 , ! V_178 || V_179 ) ;
}
F_48 ( V_49 . V_5 ) ;
return V_174 ;
}
static void F_203 ( struct V_190 * V_191 ,
struct V_98 * V_14 , unsigned int V_67 )
{
struct V_192 * V_192 ;
if ( V_14 -> V_52 && V_191 -> V_103 -> V_193 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 -> V_99 ; V_13 ++ ) {
if ( ! V_14 -> V_52 [ V_13 ] )
continue;
V_191 -> V_103 -> V_193 ( V_191 -> V_194 , V_14 -> V_52 [ V_13 ] ,
V_67 , V_13 ) ;
V_14 -> V_52 [ V_13 ] = NULL ;
}
}
while ( ! F_102 ( & V_14 -> V_195 ) ) {
V_192 = F_114 ( & V_14 -> V_195 , struct V_192 , V_196 ) ;
F_100 ( & V_192 -> V_196 ) ;
F_204 ( F_205 ( V_192 ) ) ;
F_206 ( V_192 , V_192 -> V_197 ) ;
}
F_207 ( V_14 -> V_52 ) ;
F_208 ( V_14 ) ;
}
static T_2 F_209 ( unsigned int V_198 )
{
return ( T_2 ) V_199 << V_198 ;
}
static struct V_98 * F_210 ( struct V_190 * V_191 ,
unsigned int V_67 )
{
struct V_98 * V_14 ;
unsigned int V_13 , V_200 , V_201 , V_202 = 4 ;
T_2 V_203 , V_204 ;
V_14 = F_211 ( V_191 -> V_205 , V_191 -> V_206 ,
V_191 -> V_207 ,
F_212 ( V_191 -> V_57 ) ) ;
if ( ! V_14 )
return NULL ;
F_30 ( & V_14 -> V_195 ) ;
V_14 -> V_52 = F_213 ( V_191 -> V_205 * sizeof( struct V_15 * ) ,
V_208 | V_209 | V_210 ,
V_191 -> V_207 ) ;
if ( ! V_14 -> V_52 ) {
F_208 ( V_14 ) ;
return NULL ;
}
V_203 = F_214 ( sizeof( struct V_15 ) + V_191 -> V_211 ,
F_215 () ) ;
V_204 = V_203 * V_191 -> V_205 ;
for ( V_13 = 0 ; V_13 < V_191 -> V_205 ; ) {
int V_212 = V_202 ;
struct V_192 * V_192 ;
int V_213 ;
void * V_214 ;
while ( V_212 && V_204 < F_209 ( V_212 - 1 ) )
V_212 -- ;
do {
V_192 = F_216 ( V_191 -> V_207 ,
V_208 | V_209 | V_210 | V_215 ,
V_212 ) ;
if ( V_192 )
break;
if ( ! V_212 -- )
break;
if ( F_209 ( V_212 ) < V_203 )
break;
} while ( 1 );
if ( ! V_192 )
goto V_216;
V_192 -> V_197 = V_212 ;
F_106 ( & V_192 -> V_196 , & V_14 -> V_195 ) ;
V_214 = F_205 ( V_192 ) ;
F_217 ( V_214 , F_209 ( V_212 ) , 1 , V_208 ) ;
V_201 = F_209 ( V_212 ) / V_203 ;
V_213 = F_144 ( V_201 , V_191 -> V_205 - V_13 ) ;
V_204 -= V_213 * V_203 ;
for ( V_200 = 0 ; V_200 < V_213 ; V_200 ++ ) {
V_14 -> V_52 [ V_13 ] = V_214 ;
if ( V_191 -> V_103 -> V_217 ) {
if ( V_191 -> V_103 -> V_217 ( V_191 -> V_194 ,
V_14 -> V_52 [ V_13 ] , V_67 , V_13 ,
V_191 -> V_207 ) ) {
V_14 -> V_52 [ V_13 ] = NULL ;
goto V_216;
}
}
V_214 += V_203 ;
V_13 ++ ;
}
}
return V_14 ;
V_216:
F_203 ( V_191 , V_14 , V_67 ) ;
return NULL ;
}
static int F_218 ( unsigned int V_22 , struct V_218 * V_219 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
F_95 ( V_220 ) ;
V_2 = F_219 ( V_219 , struct V_1 , V_221 ) ;
V_5 = F_51 ( V_2 -> V_131 , V_22 ) ;
F_138 ( & V_5 -> V_126 ) ;
if ( ! F_102 ( & V_5 -> V_91 ) ) {
F_97 ( & V_5 -> V_91 , & V_220 ) ;
F_6 ( V_2 , V_5 ) ;
}
F_140 ( & V_5 -> V_126 ) ;
if ( F_102 ( & V_220 ) )
return 0 ;
F_138 ( & V_2 -> V_126 ) ;
F_139 ( & V_220 , & V_2 -> V_138 ) ;
F_140 ( & V_2 -> V_126 ) ;
F_153 ( V_2 , true ) ;
return 0 ;
}
static void F_220 ( struct V_1 * V_2 )
{
F_221 ( V_222 ,
& V_2 -> V_221 ) ;
}
static void F_222 ( struct V_7 * V_8 ,
struct V_190 * V_191 ,
struct V_1 * V_2 , unsigned int V_67 )
{
unsigned V_223 = V_191 -> V_205 ;
F_130 ( V_2 ) ;
if ( V_191 -> V_103 -> V_193 )
V_191 -> V_103 -> V_193 ( V_191 -> V_194 ,
V_2 -> V_224 -> V_225 , V_67 ,
V_223 + V_67 ) ;
if ( V_191 -> V_103 -> V_226 )
V_191 -> V_103 -> V_226 ( V_2 , V_67 ) ;
F_220 ( V_2 ) ;
F_223 ( V_2 -> V_224 ) ;
F_224 ( & V_2 -> V_3 ) ;
}
static void F_225 ( struct V_7 * V_8 ,
struct V_190 * V_191 , int V_227 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_23 (q, hctx, i) {
if ( V_13 == V_227 )
break;
F_222 ( V_8 , V_191 , V_2 , V_13 ) ;
}
}
static void F_226 ( struct V_7 * V_8 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_23 (q, hctx, i)
F_227 ( V_2 -> V_74 ) ;
}
static int F_228 ( struct V_7 * V_8 ,
struct V_190 * V_191 ,
struct V_1 * V_2 , unsigned V_67 )
{
int V_219 ;
unsigned V_223 = V_191 -> V_205 ;
V_219 = V_2 -> V_207 ;
if ( V_219 == V_228 )
V_219 = V_2 -> V_207 = V_191 -> V_207 ;
F_229 ( & V_2 -> V_154 , F_163 ) ;
F_230 ( & V_2 -> V_155 , F_164 ) ;
F_231 ( & V_2 -> V_126 ) ;
F_30 ( & V_2 -> V_138 ) ;
V_2 -> V_131 = V_8 ;
V_2 -> V_176 = V_67 ;
V_2 -> V_57 = V_191 -> V_57 & ~ V_229 ;
F_232 ( V_222 , & V_2 -> V_221 ) ;
V_2 -> V_14 = V_191 -> V_14 [ V_67 ] ;
V_2 -> V_125 = F_233 ( V_150 * sizeof( void * ) ,
V_208 , V_219 ) ;
if ( ! V_2 -> V_125 )
goto V_230;
if ( F_234 ( & V_2 -> V_3 , V_150 , F_145 ( 8 ) , V_208 ,
V_219 ) )
goto V_231;
V_2 -> V_232 = 0 ;
if ( V_191 -> V_103 -> V_233 &&
V_191 -> V_103 -> V_233 ( V_2 , V_191 -> V_194 , V_67 ) )
goto V_234;
V_2 -> V_224 = F_235 ( V_8 , V_2 -> V_207 , V_191 -> V_211 ) ;
if ( ! V_2 -> V_224 )
goto V_226;
if ( V_191 -> V_103 -> V_217 &&
V_191 -> V_103 -> V_217 ( V_191 -> V_194 ,
V_2 -> V_224 -> V_225 , V_67 ,
V_223 + V_67 , V_219 ) )
goto V_235;
return 0 ;
V_235:
F_207 ( V_2 -> V_224 ) ;
V_226:
if ( V_191 -> V_103 -> V_226 )
V_191 -> V_103 -> V_226 ( V_2 , V_67 ) ;
V_234:
F_224 ( & V_2 -> V_3 ) ;
V_231:
F_207 ( V_2 -> V_125 ) ;
V_230:
F_220 ( V_2 ) ;
return - 1 ;
}
static void F_236 ( struct V_7 * V_8 ,
unsigned int V_69 )
{
unsigned int V_13 ;
F_237 (i) {
struct V_4 * V_236 = F_238 ( V_8 -> V_237 , V_13 ) ;
struct V_1 * V_2 ;
memset ( V_236 , 0 , sizeof( * V_236 ) ) ;
V_236 -> V_22 = V_13 ;
F_231 ( & V_236 -> V_126 ) ;
F_30 ( & V_236 -> V_91 ) ;
V_236 -> V_131 = V_8 ;
if ( ! F_73 ( V_13 ) )
continue;
V_2 = F_46 ( V_8 , V_13 ) ;
if ( V_69 > 1 && V_2 -> V_207 == V_228 )
V_2 -> V_207 = F_239 ( F_240 ( V_13 ) ) ;
}
}
static void F_241 ( struct V_7 * V_8 ,
const struct V_74 * V_238 )
{
unsigned int V_13 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_190 * V_191 = V_8 -> V_239 ;
F_242 ( & V_8 -> V_240 ) ;
F_23 (q, hctx, i) {
F_243 ( V_2 -> V_74 ) ;
V_2 -> V_232 = 0 ;
}
F_237 (i) {
if ( ! F_148 ( V_13 , V_238 ) )
continue;
V_5 = F_238 ( V_8 -> V_237 , V_13 ) ;
V_2 = F_46 ( V_8 , V_13 ) ;
F_244 ( V_13 , V_2 -> V_74 ) ;
V_5 -> V_6 = V_2 -> V_232 ;
V_2 -> V_125 [ V_2 -> V_232 ++ ] = V_5 ;
}
F_245 ( & V_8 -> V_240 ) ;
F_23 (q, hctx, i) {
if ( ! V_2 -> V_232 ) {
if ( V_191 -> V_14 [ V_13 ] ) {
F_203 ( V_191 , V_191 -> V_14 [ V_13 ] , V_13 ) ;
V_191 -> V_14 [ V_13 ] = NULL ;
}
V_2 -> V_14 = NULL ;
continue;
}
if ( ! V_191 -> V_14 [ V_13 ] )
V_191 -> V_14 [ V_13 ] = F_210 ( V_191 , V_13 ) ;
V_2 -> V_14 = V_191 -> V_14 [ V_13 ] ;
F_147 ( ! V_2 -> V_14 ) ;
F_246 ( & V_2 -> V_3 , V_2 -> V_232 ) ;
V_2 -> V_136 = F_52 ( V_2 -> V_74 ) ;
V_2 -> V_149 = V_151 ;
}
}
static void F_247 ( struct V_7 * V_8 , bool V_79 )
{
struct V_1 * V_2 ;
int V_13 ;
F_23 (q, hctx, i) {
if ( V_79 )
V_2 -> V_57 |= V_229 ;
else
V_2 -> V_57 &= ~ V_229 ;
}
}
static void F_248 ( struct V_190 * V_191 , bool V_79 )
{
struct V_7 * V_8 ;
F_249 (q, &set->tag_list, tag_set_list) {
F_16 ( V_8 ) ;
F_247 ( V_8 , V_79 ) ;
F_17 ( V_8 ) ;
}
}
static void F_250 ( struct V_7 * V_8 )
{
struct V_190 * V_191 = V_8 -> V_239 ;
F_242 ( & V_191 -> V_241 ) ;
F_100 ( & V_8 -> V_242 ) ;
if ( F_251 ( & V_191 -> V_243 ) ) {
V_191 -> V_57 &= ~ V_229 ;
F_248 ( V_191 , false ) ;
}
F_245 ( & V_191 -> V_241 ) ;
}
static void F_252 ( struct V_190 * V_191 ,
struct V_7 * V_8 )
{
V_8 -> V_239 = V_191 ;
F_242 ( & V_191 -> V_241 ) ;
if ( ! F_102 ( & V_191 -> V_243 ) && ! ( V_191 -> V_57 & V_229 ) ) {
V_191 -> V_57 |= V_229 ;
F_248 ( V_191 , true ) ;
}
if ( V_191 -> V_57 & V_229 )
F_247 ( V_8 , true ) ;
F_106 ( & V_8 -> V_242 , & V_191 -> V_243 ) ;
F_245 ( & V_191 -> V_241 ) ;
}
void F_253 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_23 (q, hctx, i) {
if ( ! V_2 )
continue;
F_207 ( V_2 -> V_125 ) ;
F_207 ( V_2 ) ;
}
V_8 -> V_244 = NULL ;
F_207 ( V_8 -> V_71 ) ;
F_254 ( V_8 -> V_237 ) ;
}
struct V_7 * F_255 ( struct V_190 * V_191 )
{
struct V_7 * V_245 , * V_8 ;
V_245 = F_256 ( V_208 , V_191 -> V_207 ) ;
if ( ! V_245 )
return F_44 ( - V_246 ) ;
V_8 = F_257 ( V_191 , V_245 ) ;
if ( F_258 ( V_8 ) )
F_259 ( V_245 ) ;
return V_8 ;
}
static void F_260 ( struct V_190 * V_191 ,
struct V_7 * V_8 )
{
int V_13 , V_200 ;
struct V_1 * * V_247 = V_8 -> V_71 ;
F_261 ( V_8 ) ;
for ( V_13 = 0 ; V_13 < V_191 -> V_69 ; V_13 ++ ) {
int V_219 ;
if ( V_247 [ V_13 ] )
continue;
V_219 = F_262 ( V_8 -> V_244 , V_13 ) ;
V_247 [ V_13 ] = F_213 ( sizeof( struct V_1 ) ,
V_208 , V_219 ) ;
if ( ! V_247 [ V_13 ] )
break;
if ( ! F_263 ( & V_247 [ V_13 ] -> V_74 , V_208 ,
V_219 ) ) {
F_207 ( V_247 [ V_13 ] ) ;
V_247 [ V_13 ] = NULL ;
break;
}
F_264 ( & V_247 [ V_13 ] -> V_55 , 0 ) ;
V_247 [ V_13 ] -> V_207 = V_219 ;
V_247 [ V_13 ] -> V_176 = V_13 ;
if ( F_228 ( V_8 , V_191 , V_247 [ V_13 ] , V_13 ) ) {
F_227 ( V_247 [ V_13 ] -> V_74 ) ;
F_207 ( V_247 [ V_13 ] ) ;
V_247 [ V_13 ] = NULL ;
break;
}
F_265 ( V_247 [ V_13 ] ) ;
}
for ( V_200 = V_13 ; V_200 < V_8 -> V_69 ; V_200 ++ ) {
struct V_1 * V_2 = V_247 [ V_200 ] ;
if ( V_2 ) {
if ( V_2 -> V_14 ) {
F_203 ( V_191 , V_2 -> V_14 , V_200 ) ;
V_191 -> V_14 [ V_200 ] = NULL ;
}
F_222 ( V_8 , V_191 , V_2 , V_200 ) ;
F_227 ( V_2 -> V_74 ) ;
F_266 ( & V_2 -> V_248 ) ;
F_207 ( V_2 -> V_125 ) ;
F_207 ( V_2 ) ;
V_247 [ V_200 ] = NULL ;
}
}
V_8 -> V_69 = V_13 ;
F_267 ( V_8 ) ;
}
struct V_7 * F_257 ( struct V_190 * V_191 ,
struct V_7 * V_8 )
{
V_8 -> V_104 = V_191 -> V_103 ;
V_8 -> V_237 = F_268 ( struct V_4 ) ;
if ( ! V_8 -> V_237 )
goto V_249;
V_8 -> V_71 = F_213 ( V_150 * sizeof( * ( V_8 -> V_71 ) ) ,
V_208 , V_191 -> V_207 ) ;
if ( ! V_8 -> V_71 )
goto V_250;
V_8 -> V_244 = V_191 -> V_244 ;
F_260 ( V_191 , V_8 ) ;
if ( ! V_8 -> V_69 )
goto V_251;
F_229 ( & V_8 -> V_114 , F_124 ) ;
F_269 ( V_8 , V_191 -> V_43 ? V_191 -> V_43 : 30 * V_252 ) ;
V_8 -> V_253 = V_150 ;
V_8 -> V_81 |= V_254 ;
if ( ! ( V_191 -> V_57 & V_255 ) )
V_8 -> V_81 |= 1 << V_256 ;
V_8 -> V_257 = V_258 ;
F_230 ( & V_8 -> V_90 , F_93 ) ;
F_30 ( & V_8 -> V_94 ) ;
F_231 ( & V_8 -> V_93 ) ;
if ( V_8 -> V_69 > 1 )
F_270 ( V_8 , F_191 ) ;
else
F_270 ( V_8 , F_199 ) ;
V_8 -> V_259 = V_191 -> V_205 ;
if ( V_191 -> V_103 -> V_260 )
F_271 ( V_8 , V_191 -> V_103 -> V_260 ) ;
F_236 ( V_8 , V_191 -> V_69 ) ;
F_272 () ;
F_242 ( & V_261 ) ;
F_106 ( & V_8 -> V_262 , & V_263 ) ;
F_252 ( V_191 , V_8 ) ;
F_241 ( V_8 , V_264 ) ;
F_245 ( & V_261 ) ;
F_273 () ;
return V_8 ;
V_251:
F_207 ( V_8 -> V_71 ) ;
V_250:
F_254 ( V_8 -> V_237 ) ;
V_249:
V_8 -> V_104 = NULL ;
return F_44 ( - V_246 ) ;
}
void F_274 ( struct V_7 * V_8 )
{
struct V_190 * V_191 = V_8 -> V_239 ;
F_242 ( & V_261 ) ;
F_100 ( & V_8 -> V_262 ) ;
F_245 ( & V_261 ) ;
F_250 ( V_8 ) ;
F_225 ( V_8 , V_191 , V_191 -> V_69 ) ;
F_226 ( V_8 , V_191 ) ;
}
static void F_275 ( struct V_7 * V_8 ,
const struct V_74 * V_238 )
{
F_19 ( ! F_276 ( & V_8 -> V_10 ) ) ;
F_261 ( V_8 ) ;
F_241 ( V_8 , V_238 ) ;
F_267 ( V_8 ) ;
}
static void F_277 ( void )
{
struct V_7 * V_8 ;
F_242 ( & V_261 ) ;
F_249 (q, &all_q_list, all_q_node)
F_8 ( V_8 ) ;
F_249 (q, &all_q_list, all_q_node) {
F_12 ( V_8 ) ;
F_278 ( & V_8 -> V_43 ) ;
}
F_249 (q, &all_q_list, all_q_node)
F_275 ( V_8 , & V_265 ) ;
F_249 (q, &all_q_list, all_q_node)
F_17 ( V_8 ) ;
F_245 ( & V_261 ) ;
}
static int F_279 ( unsigned int V_22 )
{
F_280 ( & V_265 , V_264 ) ;
F_277 () ;
return 0 ;
}
static int F_281 ( unsigned int V_22 )
{
F_280 ( & V_265 , V_264 ) ;
F_244 ( V_22 , & V_265 ) ;
F_277 () ;
return 0 ;
}
static int F_282 ( struct V_190 * V_191 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_191 -> V_69 ; V_13 ++ ) {
V_191 -> V_14 [ V_13 ] = F_210 ( V_191 , V_13 ) ;
if ( ! V_191 -> V_14 [ V_13 ] )
goto V_266;
}
return 0 ;
V_266:
while ( -- V_13 >= 0 )
F_203 ( V_191 , V_191 -> V_14 [ V_13 ] , V_13 ) ;
return - V_246 ;
}
static int F_283 ( struct V_190 * V_191 )
{
unsigned int V_157 ;
int V_267 ;
V_157 = V_191 -> V_205 ;
do {
V_267 = F_282 ( V_191 ) ;
if ( ! V_267 )
break;
V_191 -> V_205 >>= 1 ;
if ( V_191 -> V_205 < V_191 -> V_206 + V_268 ) {
V_267 = - V_246 ;
break;
}
} while ( V_191 -> V_205 );
if ( ! V_191 -> V_205 || V_267 ) {
F_151 ( L_3 ) ;
return - V_246 ;
}
if ( V_157 != V_191 -> V_205 )
F_284 ( L_4 ,
V_157 , V_191 -> V_205 ) ;
return 0 ;
}
int F_285 ( struct V_190 * V_191 )
{
int V_59 ;
F_286 ( V_269 > 1 << V_270 ) ;
if ( ! V_191 -> V_69 )
return - V_68 ;
if ( ! V_191 -> V_205 )
return - V_68 ;
if ( V_191 -> V_205 < V_191 -> V_206 + V_268 )
return - V_68 ;
if ( ! V_191 -> V_103 -> V_142 )
return - V_68 ;
if ( V_191 -> V_205 > V_269 ) {
F_284 ( L_5 ,
V_269 ) ;
V_191 -> V_205 = V_269 ;
}
if ( F_287 () ) {
V_191 -> V_69 = 1 ;
V_191 -> V_205 = F_144 ( 64U , V_191 -> V_205 ) ;
}
if ( V_191 -> V_69 > V_150 )
V_191 -> V_69 = V_150 ;
V_191 -> V_14 = F_213 ( V_150 * sizeof( struct V_98 * ) ,
V_208 , V_191 -> V_207 ) ;
if ( ! V_191 -> V_14 )
return - V_246 ;
V_59 = - V_246 ;
V_191 -> V_244 = F_213 ( sizeof( * V_191 -> V_244 ) * V_150 ,
V_208 , V_191 -> V_207 ) ;
if ( ! V_191 -> V_244 )
goto V_271;
if ( V_191 -> V_103 -> V_272 )
V_59 = V_191 -> V_103 -> V_272 ( V_191 ) ;
else
V_59 = F_288 ( V_191 ) ;
if ( V_59 )
goto V_273;
V_59 = F_283 ( V_191 ) ;
if ( V_59 )
goto V_273;
F_289 ( & V_191 -> V_241 ) ;
F_30 ( & V_191 -> V_243 ) ;
return 0 ;
V_273:
F_207 ( V_191 -> V_244 ) ;
V_191 -> V_244 = NULL ;
V_271:
F_207 ( V_191 -> V_14 ) ;
V_191 -> V_14 = NULL ;
return V_59 ;
}
void F_290 ( struct V_190 * V_191 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_150 ; V_13 ++ ) {
if ( V_191 -> V_14 [ V_13 ] )
F_203 ( V_191 , V_191 -> V_14 [ V_13 ] , V_13 ) ;
}
F_207 ( V_191 -> V_244 ) ;
V_191 -> V_244 = NULL ;
F_207 ( V_191 -> V_14 ) ;
V_191 -> V_14 = NULL ;
}
int F_291 ( struct V_7 * V_8 , unsigned int V_274 )
{
struct V_190 * V_191 = V_8 -> V_239 ;
struct V_1 * V_2 ;
int V_13 , V_59 ;
if ( ! V_191 || V_274 > V_191 -> V_205 )
return - V_68 ;
V_59 = 0 ;
F_23 (q, hctx, i) {
if ( ! V_2 -> V_14 )
continue;
V_59 = F_292 ( V_2 -> V_14 , V_274 ) ;
if ( V_59 )
break;
}
if ( ! V_59 )
V_8 -> V_259 = V_274 ;
return V_59 ;
}
void F_293 ( struct V_190 * V_191 , int V_69 )
{
struct V_7 * V_8 ;
if ( V_69 > V_150 )
V_69 = V_150 ;
if ( V_69 < 1 || V_69 == V_191 -> V_69 )
return;
F_249 (q, &set->tag_list, tag_set_list)
F_16 ( V_8 ) ;
V_191 -> V_69 = V_69 ;
F_249 (q, &set->tag_list, tag_set_list) {
F_260 ( V_191 , V_8 ) ;
if ( V_8 -> V_69 > 1 )
F_270 ( V_8 , F_191 ) ;
else
F_270 ( V_8 , F_199 ) ;
F_275 ( V_8 , V_264 ) ;
}
F_249 (q, &set->tag_list, tag_set_list)
F_17 ( V_8 ) ;
}
void F_294 ( void )
{
F_242 ( & V_261 ) ;
}
void F_295 ( void )
{
F_245 ( & V_261 ) ;
}
static int T_3 F_296 ( void )
{
F_297 ( V_222 , L_6 , NULL ,
F_218 ) ;
F_298 ( V_275 , L_7 ,
F_281 ,
F_279 ) ;
return 0 ;
}
