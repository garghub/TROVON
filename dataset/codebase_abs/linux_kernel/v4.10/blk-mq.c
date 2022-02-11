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
bool V_14 = false ;
F_23 ( V_8 ) ;
F_24 (q, hctx, i) {
if ( V_2 -> V_15 & V_16 )
F_25 ( & V_2 -> V_17 ) ;
else
V_14 = true ;
}
if ( V_14 )
F_26 () ;
}
void F_27 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_24 (q, hctx, i)
if ( F_28 ( V_2 ) )
F_29 ( V_2 -> V_18 , true ) ;
F_21 ( & V_8 -> V_12 ) ;
}
bool F_30 ( struct V_1 * V_2 )
{
return F_31 ( V_2 -> V_18 ) ;
}
static void F_32 ( struct V_7 * V_8 , struct V_4 * V_5 ,
struct V_19 * V_20 , unsigned int V_21 )
{
F_33 ( & V_20 -> V_22 ) ;
V_20 -> V_8 = V_8 ;
V_20 -> V_23 = V_5 ;
V_20 -> V_24 = V_21 ;
if ( F_34 ( V_8 ) )
V_20 -> V_25 |= V_26 ;
V_20 -> V_27 = - 1 ;
F_35 ( & V_20 -> V_28 ) ;
F_36 ( & V_20 -> V_29 ) ;
V_20 -> V_30 = NULL ;
V_20 -> V_31 = NULL ;
V_20 -> V_32 = V_33 ;
#ifdef F_37
V_20 -> V_34 = NULL ;
F_38 ( V_20 ) ;
V_20 -> V_35 = 0 ;
#endif
V_20 -> V_36 = 0 ;
#if F_39 ( V_37 )
V_20 -> V_38 = 0 ;
#endif
V_20 -> V_39 = NULL ;
V_20 -> V_40 = 0 ;
V_20 -> V_41 = V_20 -> V_42 ;
V_20 -> V_43 = 0 ;
V_20 -> V_44 = 0 ;
V_20 -> V_45 = 0 ;
V_20 -> V_46 = NULL ;
F_33 ( & V_20 -> V_47 ) ;
V_20 -> V_48 = 0 ;
V_20 -> V_49 = NULL ;
V_20 -> V_50 = NULL ;
V_20 -> V_51 = NULL ;
V_5 -> V_52 [ F_40 ( V_21 ) ] ++ ;
}
static struct V_19 *
F_41 ( struct V_53 * V_54 , unsigned int V_21 )
{
struct V_19 * V_20 ;
unsigned int V_55 ;
V_55 = F_42 ( V_54 ) ;
if ( V_55 != V_56 ) {
V_20 = V_54 -> V_2 -> V_18 -> V_57 [ V_55 ] ;
if ( F_43 ( V_54 -> V_2 ) ) {
V_20 -> V_25 = V_58 ;
F_44 ( & V_54 -> V_2 -> V_59 ) ;
}
V_20 -> V_55 = V_55 ;
F_32 ( V_54 -> V_8 , V_54 -> V_5 , V_20 , V_21 ) ;
return V_20 ;
}
return NULL ;
}
struct V_19 * F_45 ( struct V_7 * V_8 , int V_60 ,
unsigned int V_15 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
struct V_53 V_61 ;
int V_62 ;
V_62 = F_46 ( V_8 , V_15 & V_63 ) ;
if ( V_62 )
return F_47 ( V_62 ) ;
V_5 = F_48 ( V_8 ) ;
V_2 = F_49 ( V_8 , V_5 -> V_27 ) ;
F_50 ( & V_61 , V_8 , V_15 , V_5 , V_2 ) ;
V_20 = F_41 ( & V_61 , V_60 ) ;
F_51 ( V_5 ) ;
if ( ! V_20 ) {
F_52 ( V_8 ) ;
return F_47 ( - V_64 ) ;
}
V_20 -> V_65 = 0 ;
V_20 -> V_66 = ( V_67 ) - 1 ;
V_20 -> V_68 = V_20 -> V_69 = NULL ;
return V_20 ;
}
struct V_19 * F_53 ( struct V_7 * V_8 , int V_60 ,
unsigned int V_15 , unsigned int V_70 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_19 * V_20 ;
struct V_53 V_61 ;
int V_62 ;
if ( F_19 ( ! ( V_15 & V_63 ) ) )
return F_47 ( - V_71 ) ;
if ( V_70 >= V_8 -> V_72 )
return F_47 ( - V_73 ) ;
V_62 = F_46 ( V_8 , true ) ;
if ( V_62 )
return F_47 ( V_62 ) ;
V_2 = V_8 -> V_74 [ V_70 ] ;
if ( ! F_28 ( V_2 ) ) {
V_62 = - V_75 ;
goto V_76;
}
V_5 = F_54 ( V_8 , F_55 ( V_2 -> V_77 ) ) ;
F_50 ( & V_61 , V_8 , V_15 , V_5 , V_2 ) ;
V_20 = F_41 ( & V_61 , V_60 ) ;
if ( ! V_20 ) {
V_62 = - V_64 ;
goto V_76;
}
return V_20 ;
V_76:
F_52 ( V_8 ) ;
return F_47 ( V_62 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_4 * V_5 , struct V_19 * V_20 )
{
const int V_55 = V_20 -> V_55 ;
struct V_7 * V_8 = V_20 -> V_8 ;
if ( V_20 -> V_25 & V_58 )
F_57 ( & V_2 -> V_59 ) ;
F_58 ( V_8 -> V_78 , & V_20 -> V_79 ) ;
V_20 -> V_25 = 0 ;
F_59 ( V_80 , & V_20 -> V_81 ) ;
F_59 ( V_82 , & V_20 -> V_81 ) ;
F_60 ( V_2 , V_5 , V_55 ) ;
F_52 ( V_8 ) ;
}
void F_61 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_4 * V_5 = V_20 -> V_23 ;
V_5 -> V_83 [ F_62 ( V_20 ) ] ++ ;
F_56 ( V_2 , V_5 , V_20 ) ;
}
void F_63 ( struct V_19 * V_20 )
{
F_61 ( F_49 ( V_20 -> V_8 , V_20 -> V_23 -> V_27 ) , V_20 ) ;
}
inline void F_64 ( struct V_19 * V_20 , int error )
{
F_65 ( V_20 ) ;
if ( V_20 -> V_49 ) {
F_58 ( V_20 -> V_8 -> V_78 , & V_20 -> V_79 ) ;
V_20 -> V_49 ( V_20 , error ) ;
} else {
if ( F_66 ( F_67 ( V_20 ) ) )
F_63 ( V_20 -> V_51 ) ;
F_63 ( V_20 ) ;
}
}
void F_68 ( struct V_19 * V_20 , int error )
{
if ( F_69 ( V_20 , error , F_70 ( V_20 ) ) )
F_71 () ;
F_64 ( V_20 , error ) ;
}
static void F_72 ( void * V_54 )
{
struct V_19 * V_20 = V_54 ;
V_20 -> V_8 -> V_84 ( V_20 ) ;
}
static void F_73 ( struct V_19 * V_20 )
{
struct V_4 * V_5 = V_20 -> V_23 ;
bool V_85 = false ;
int V_27 ;
if ( ! F_74 ( V_86 , & V_20 -> V_8 -> V_87 ) ) {
V_20 -> V_8 -> V_84 ( V_20 ) ;
return;
}
V_27 = F_75 () ;
if ( ! F_74 ( V_88 , & V_20 -> V_8 -> V_87 ) )
V_85 = F_76 ( V_27 , V_5 -> V_27 ) ;
if ( V_27 != V_5 -> V_27 && ! V_85 && F_77 ( V_5 -> V_27 ) ) {
V_20 -> V_89 . V_90 = F_72 ;
V_20 -> V_89 . V_91 = V_20 ;
V_20 -> V_89 . V_15 = 0 ;
F_78 ( V_5 -> V_27 , & V_20 -> V_89 ) ;
} else {
V_20 -> V_8 -> V_84 ( V_20 ) ;
}
F_79 () ;
}
static void F_80 ( struct V_19 * V_20 )
{
if ( V_20 -> V_25 & V_92 ) {
struct V_4 * V_5 ;
V_5 = F_54 ( V_20 -> V_8 , F_81 () ) ;
F_82 ( & V_5 -> V_93 [ F_83 ( V_20 ) ] , V_20 ) ;
}
}
static void F_84 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_8 ;
F_80 ( V_20 ) ;
if ( ! V_8 -> V_84 )
F_68 ( V_20 , V_20 -> V_40 ) ;
else
F_73 ( V_20 ) ;
}
void F_85 ( struct V_19 * V_20 , int error )
{
struct V_7 * V_8 = V_20 -> V_8 ;
if ( F_66 ( F_86 ( V_8 ) ) )
return;
if ( ! F_87 ( V_20 ) ) {
V_20 -> V_40 = error ;
F_84 ( V_20 ) ;
}
}
int F_88 ( struct V_19 * V_20 )
{
return F_74 ( V_80 , & V_20 -> V_81 ) ;
}
void F_89 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_8 ;
F_90 ( V_8 , V_20 ) ;
V_20 -> V_45 = F_70 ( V_20 ) ;
if ( F_66 ( F_67 ( V_20 ) ) )
V_20 -> V_51 -> V_45 = F_70 ( V_20 -> V_51 ) ;
if ( F_74 ( V_94 , & V_8 -> V_87 ) ) {
F_91 ( & V_20 -> V_79 ) ;
V_20 -> V_25 |= V_92 ;
F_92 ( V_8 -> V_78 , & V_20 -> V_79 ) ;
}
F_93 ( V_20 ) ;
F_94 () ;
if ( ! F_74 ( V_80 , & V_20 -> V_81 ) )
F_95 ( V_80 , & V_20 -> V_81 ) ;
if ( F_74 ( V_95 , & V_20 -> V_81 ) )
F_59 ( V_95 , & V_20 -> V_81 ) ;
if ( V_8 -> V_96 && F_70 ( V_20 ) ) {
V_20 -> V_36 ++ ;
}
}
static void F_96 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_8 ;
F_97 ( V_8 , V_20 ) ;
F_98 ( V_8 -> V_78 , & V_20 -> V_79 ) ;
if ( F_99 ( V_80 , & V_20 -> V_81 ) ) {
if ( V_8 -> V_96 && F_70 ( V_20 ) )
V_20 -> V_36 -- ;
}
}
void F_100 ( struct V_19 * V_20 , bool V_97 )
{
F_96 ( V_20 ) ;
F_101 ( F_102 ( V_20 ) ) ;
F_103 ( V_20 , true , V_97 ) ;
}
static void F_104 ( struct V_98 * V_99 )
{
struct V_7 * V_8 =
F_105 ( V_99 , struct V_7 , V_100 . V_99 ) ;
F_106 ( V_101 ) ;
struct V_19 * V_20 , * V_102 ;
unsigned long V_15 ;
F_107 ( & V_8 -> V_103 , V_15 ) ;
F_108 ( & V_8 -> V_104 , & V_101 ) ;
F_109 ( & V_8 -> V_103 , V_15 ) ;
F_110 (rq, next, &rq_list, queuelist) {
if ( ! ( V_20 -> V_25 & V_105 ) )
continue;
V_20 -> V_25 &= ~ V_105 ;
F_111 ( & V_20 -> V_22 ) ;
F_112 ( V_20 , true , false , false ) ;
}
while ( ! F_113 ( & V_101 ) ) {
V_20 = F_114 ( V_101 . V_102 , struct V_19 , V_22 ) ;
F_111 ( & V_20 -> V_22 ) ;
F_112 ( V_20 , false , false , false ) ;
}
F_11 ( V_8 , false ) ;
}
void F_103 ( struct V_19 * V_20 , bool V_106 ,
bool V_97 )
{
struct V_7 * V_8 = V_20 -> V_8 ;
unsigned long V_15 ;
F_101 ( V_20 -> V_25 & V_105 ) ;
F_107 ( & V_8 -> V_103 , V_15 ) ;
if ( V_106 ) {
V_20 -> V_25 |= V_105 ;
F_115 ( & V_20 -> V_22 , & V_8 -> V_104 ) ;
} else {
F_116 ( & V_20 -> V_22 , & V_8 -> V_104 ) ;
}
F_109 ( & V_8 -> V_103 , V_15 ) ;
if ( V_97 )
F_117 ( V_8 ) ;
}
void F_117 ( struct V_7 * V_8 )
{
F_118 ( & V_8 -> V_100 , 0 ) ;
}
void F_119 ( struct V_7 * V_8 ,
unsigned long V_107 )
{
F_118 ( & V_8 -> V_100 ,
F_120 ( V_107 ) ) ;
}
void F_121 ( struct V_7 * V_8 )
{
unsigned long V_15 ;
F_106 ( V_101 ) ;
F_107 ( & V_8 -> V_103 , V_15 ) ;
F_108 ( & V_8 -> V_104 , & V_101 ) ;
F_109 ( & V_8 -> V_103 , V_15 ) ;
while ( ! F_113 ( & V_101 ) ) {
struct V_19 * V_20 ;
V_20 = F_122 ( & V_101 , struct V_19 , V_22 ) ;
F_111 ( & V_20 -> V_22 ) ;
V_20 -> V_40 = - V_73 ;
F_68 ( V_20 , V_20 -> V_40 ) ;
}
}
struct V_19 * F_123 ( struct V_108 * V_18 , unsigned int V_55 )
{
if ( V_55 < V_18 -> V_109 ) {
F_124 ( V_18 -> V_57 [ V_55 ] ) ;
return V_18 -> V_57 [ V_55 ] ;
}
return NULL ;
}
void F_125 ( struct V_19 * V_110 , bool V_111 )
{
struct V_112 * V_113 = V_110 -> V_8 -> V_114 ;
enum V_115 V_62 = V_116 ;
if ( ! F_74 ( V_80 , & V_110 -> V_81 ) )
return;
if ( V_113 -> V_48 )
V_62 = V_113 -> V_48 ( V_110 , V_111 ) ;
switch ( V_62 ) {
case V_117 :
F_84 ( V_110 ) ;
break;
case V_116 :
F_93 ( V_110 ) ;
F_126 ( V_110 ) ;
break;
case V_118 :
break;
default:
F_127 ( V_119 L_1 , V_62 ) ;
break;
}
}
static void F_128 ( struct V_1 * V_2 ,
struct V_19 * V_20 , void * V_120 , bool V_111 )
{
struct V_121 * V_54 = V_120 ;
if ( ! F_74 ( V_80 , & V_20 -> V_81 ) ) {
if ( F_66 ( F_129 ( V_20 -> V_8 ) ) ) {
V_20 -> V_40 = - V_73 ;
F_68 ( V_20 , V_20 -> V_40 ) ;
}
return;
}
if ( F_130 ( V_33 , V_20 -> V_122 ) ) {
if ( ! F_87 ( V_20 ) )
F_125 ( V_20 , V_111 ) ;
} else if ( ! V_54 -> V_123 || F_131 ( V_54 -> V_102 , V_20 -> V_122 ) ) {
V_54 -> V_102 = V_20 -> V_122 ;
V_54 -> V_123 = 1 ;
}
}
static void F_132 ( struct V_98 * V_99 )
{
struct V_7 * V_8 =
F_105 ( V_99 , struct V_7 , V_124 ) ;
struct V_121 V_54 = {
. V_102 = 0 ,
. V_123 = 0 ,
} ;
int V_13 ;
if ( ! F_133 ( & V_8 -> V_11 ) )
return;
F_134 ( V_8 , F_128 , & V_54 ) ;
if ( V_54 . V_123 ) {
V_54 . V_102 = F_135 ( F_136 ( V_54 . V_102 ) ) ;
F_137 ( & V_8 -> V_48 , V_54 . V_102 ) ;
} else {
struct V_1 * V_2 ;
F_24 (q, hctx, i) {
if ( F_28 ( V_2 ) )
F_138 ( V_2 ) ;
}
}
F_52 ( V_8 ) ;
}
static bool F_139 ( struct V_7 * V_8 ,
struct V_4 * V_5 , struct V_68 * V_68 )
{
struct V_19 * V_20 ;
int V_125 = 8 ;
F_140 (rq, &ctx->rq_list, queuelist) {
int V_126 ;
if ( ! V_125 -- )
break;
if ( ! F_141 ( V_20 , V_68 ) )
continue;
V_126 = F_142 ( V_20 , V_68 ) ;
if ( V_126 == V_127 ) {
if ( F_143 ( V_8 , V_20 , V_68 ) ) {
V_5 -> V_128 ++ ;
return true ;
}
break;
} else if ( V_126 == V_129 ) {
if ( F_144 ( V_8 , V_20 , V_68 ) ) {
V_5 -> V_128 ++ ;
return true ;
}
break;
}
}
return false ;
}
static bool F_145 ( struct V_130 * V_131 , unsigned int V_132 , void * V_54 )
{
struct V_133 * V_134 = V_54 ;
struct V_1 * V_2 = V_134 -> V_2 ;
struct V_4 * V_5 = V_2 -> V_135 [ V_132 ] ;
F_7 ( V_131 , V_132 ) ;
F_146 ( & V_5 -> V_136 ) ;
F_147 ( & V_5 -> V_101 , V_134 -> V_137 ) ;
F_148 ( & V_5 -> V_136 ) ;
return true ;
}
static void F_149 ( struct V_1 * V_2 , struct V_138 * V_137 )
{
struct V_133 V_54 = {
. V_2 = V_2 ,
. V_137 = V_137 ,
} ;
F_150 ( & V_2 -> V_3 , F_145 , & V_54 ) ;
}
static inline unsigned int F_151 ( unsigned int V_139 )
{
if ( ! V_139 )
return 0 ;
return F_152 ( V_140 - 1 , F_153 ( V_139 ) + 1 ) ;
}
bool F_154 ( struct V_1 * V_2 , struct V_138 * V_137 )
{
struct V_7 * V_8 = V_2 -> V_141 ;
struct V_19 * V_20 ;
F_106 ( V_142 ) ;
struct V_138 * V_143 ;
int V_139 , V_62 = V_144 ;
V_143 = NULL ;
V_139 = 0 ;
while ( ! F_113 ( V_137 ) ) {
struct V_145 V_146 ;
V_20 = F_122 ( V_137 , struct V_19 , V_22 ) ;
F_111 ( & V_20 -> V_22 ) ;
V_146 . V_20 = V_20 ;
V_146 . V_137 = V_143 ;
V_146 . V_147 = F_113 ( V_137 ) ;
V_62 = V_8 -> V_114 -> V_148 ( V_2 , & V_146 ) ;
switch ( V_62 ) {
case V_144 :
V_139 ++ ;
break;
case V_149 :
F_115 ( & V_20 -> V_22 , V_137 ) ;
F_96 ( V_20 ) ;
break;
default:
F_155 ( L_2 , V_62 ) ;
case V_150 :
V_20 -> V_40 = - V_73 ;
F_68 ( V_20 , V_20 -> V_40 ) ;
break;
}
if ( V_62 == V_149 )
break;
if ( ! V_143 && V_137 -> V_102 != V_137 -> V_151 )
V_143 = & V_142 ;
}
V_2 -> V_152 [ F_151 ( V_139 ) ] ++ ;
if ( ! F_113 ( V_137 ) ) {
F_146 ( & V_2 -> V_136 ) ;
F_156 ( V_137 , & V_2 -> V_153 ) ;
F_148 ( & V_2 -> V_136 ) ;
F_157 ( V_2 , true ) ;
}
return V_62 != V_149 ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_106 ( V_101 ) ;
if ( F_66 ( F_159 ( V_2 ) ) )
return;
V_2 -> V_154 ++ ;
F_149 ( V_2 , & V_101 ) ;
if ( ! F_160 ( & V_2 -> V_153 ) ) {
F_146 ( & V_2 -> V_136 ) ;
if ( ! F_113 ( & V_2 -> V_153 ) )
F_108 ( & V_2 -> V_153 , & V_101 ) ;
F_148 ( & V_2 -> V_136 ) ;
}
F_154 ( V_2 , & V_101 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
int V_155 ;
F_162 ( ! F_163 ( F_81 () , V_2 -> V_77 ) &&
F_77 ( V_2 -> V_156 ) ) ;
if ( ! ( V_2 -> V_15 & V_16 ) ) {
F_164 () ;
F_158 ( V_2 ) ;
F_165 () ;
} else {
V_155 = F_166 ( & V_2 -> V_17 ) ;
F_158 ( V_2 ) ;
F_167 ( & V_2 -> V_17 , V_155 ) ;
}
}
static int F_168 ( struct V_1 * V_2 )
{
if ( V_2 -> V_141 -> V_72 == 1 )
return V_157 ;
if ( -- V_2 -> V_158 <= 0 ) {
int V_156 ;
V_156 = F_169 ( V_2 -> V_156 , V_2 -> V_77 ) ;
if ( V_156 >= V_159 )
V_156 = F_55 ( V_2 -> V_77 ) ;
V_2 -> V_156 = V_156 ;
V_2 -> V_158 = V_160 ;
}
return V_2 -> V_156 ;
}
void F_157 ( struct V_1 * V_2 , bool V_161 )
{
if ( F_66 ( F_159 ( V_2 ) ||
! F_28 ( V_2 ) ) )
return;
if ( ! V_161 && ! ( V_2 -> V_15 & V_16 ) ) {
int V_27 = F_75 () ;
if ( F_163 ( V_27 , V_2 -> V_77 ) ) {
F_161 ( V_2 ) ;
F_79 () ;
return;
}
F_79 () ;
}
F_170 ( F_168 ( V_2 ) , & V_2 -> V_162 ) ;
}
void F_11 ( struct V_7 * V_8 , bool V_161 )
{
struct V_1 * V_2 ;
int V_13 ;
F_24 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_160 ( & V_2 -> V_153 ) ) ||
F_159 ( V_2 ) )
continue;
F_157 ( V_2 , V_161 ) ;
}
}
bool F_171 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_13 ;
F_24 (q, hctx, i)
if ( F_159 ( V_2 ) )
return true ;
return false ;
}
void F_172 ( struct V_1 * V_2 )
{
F_173 ( & V_2 -> V_162 ) ;
F_174 ( & V_2 -> V_163 ) ;
F_95 ( V_164 , & V_2 -> V_165 ) ;
}
void F_23 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_13 ;
F_24 (q, hctx, i)
F_172 ( V_2 ) ;
}
void F_175 ( struct V_1 * V_2 )
{
F_59 ( V_164 , & V_2 -> V_165 ) ;
F_157 ( V_2 , false ) ;
}
void F_176 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
int V_13 ;
F_24 (q, hctx, i)
F_175 ( V_2 ) ;
}
void F_177 ( struct V_1 * V_2 , bool V_161 )
{
if ( ! F_159 ( V_2 ) )
return;
F_59 ( V_164 , & V_2 -> V_165 ) ;
F_157 ( V_2 , V_161 ) ;
}
void F_178 ( struct V_7 * V_8 , bool V_161 )
{
struct V_1 * V_2 ;
int V_13 ;
F_24 (q, hctx, i)
F_177 ( V_2 , V_161 ) ;
}
static void F_179 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
V_2 = F_105 ( V_99 , struct V_1 , V_162 ) ;
F_161 ( V_2 ) ;
}
static void F_180 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
V_2 = F_105 ( V_99 , struct V_1 , V_163 . V_99 ) ;
if ( F_99 ( V_164 , & V_2 -> V_165 ) )
F_161 ( V_2 ) ;
}
void F_181 ( struct V_1 * V_2 , unsigned long V_107 )
{
if ( F_66 ( ! F_28 ( V_2 ) ) )
return;
F_182 ( F_168 ( V_2 ) ,
& V_2 -> V_163 , F_120 ( V_107 ) ) ;
}
static inline void F_183 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
bool V_106 )
{
struct V_4 * V_5 = V_20 -> V_23 ;
F_184 ( V_2 -> V_141 , V_20 ) ;
if ( V_106 )
F_115 ( & V_20 -> V_22 , & V_5 -> V_101 ) ;
else
F_116 ( & V_20 -> V_22 , & V_5 -> V_101 ) ;
}
static void F_185 ( struct V_1 * V_2 ,
struct V_19 * V_20 , bool V_106 )
{
struct V_4 * V_5 = V_20 -> V_23 ;
F_183 ( V_2 , V_20 , V_106 ) ;
F_3 ( V_2 , V_5 ) ;
}
void F_112 ( struct V_19 * V_20 , bool V_106 , bool V_166 ,
bool V_161 )
{
struct V_4 * V_5 = V_20 -> V_23 ;
struct V_7 * V_8 = V_20 -> V_8 ;
struct V_1 * V_2 = F_49 ( V_8 , V_5 -> V_27 ) ;
F_146 ( & V_5 -> V_136 ) ;
F_185 ( V_2 , V_20 , V_106 ) ;
F_148 ( & V_5 -> V_136 ) ;
if ( V_166 )
F_157 ( V_2 , V_161 ) ;
}
static void F_186 ( struct V_7 * V_8 ,
struct V_4 * V_5 ,
struct V_138 * V_137 ,
int V_167 ,
bool V_168 )
{
struct V_1 * V_2 = F_49 ( V_8 , V_5 -> V_27 ) ;
F_187 ( V_8 , V_167 , ! V_168 ) ;
F_146 ( & V_5 -> V_136 ) ;
while ( ! F_113 ( V_137 ) ) {
struct V_19 * V_20 ;
V_20 = F_122 ( V_137 , struct V_19 , V_22 ) ;
F_101 ( V_20 -> V_23 != V_5 ) ;
F_111 ( & V_20 -> V_22 ) ;
F_183 ( V_2 , V_20 , false ) ;
}
F_3 ( V_2 , V_5 ) ;
F_148 ( & V_5 -> V_136 ) ;
F_157 ( V_2 , V_168 ) ;
}
static int F_188 ( void * V_120 , struct V_138 * V_169 , struct V_138 * V_170 )
{
struct V_19 * V_171 = F_105 ( V_169 , struct V_19 , V_22 ) ;
struct V_19 * V_172 = F_105 ( V_170 , struct V_19 , V_22 ) ;
return ! ( V_171 -> V_23 < V_172 -> V_23 ||
( V_171 -> V_23 == V_172 -> V_23 &&
F_189 ( V_171 ) < F_189 ( V_172 ) ) ) ;
}
void F_190 ( struct V_173 * V_174 , bool V_168 )
{
struct V_4 * V_175 ;
struct V_7 * V_176 ;
struct V_19 * V_20 ;
F_106 ( V_137 ) ;
F_106 ( V_177 ) ;
unsigned int V_167 ;
F_108 ( & V_174 -> V_178 , & V_137 ) ;
F_191 ( NULL , & V_137 , F_188 ) ;
V_176 = NULL ;
V_175 = NULL ;
V_167 = 0 ;
while ( ! F_113 ( & V_137 ) ) {
V_20 = F_192 ( V_137 . V_102 ) ;
F_111 ( & V_20 -> V_22 ) ;
F_101 ( ! V_20 -> V_8 ) ;
if ( V_20 -> V_23 != V_175 ) {
if ( V_175 ) {
F_186 ( V_176 , V_175 ,
& V_177 , V_167 ,
V_168 ) ;
}
V_175 = V_20 -> V_23 ;
V_176 = V_20 -> V_8 ;
V_167 = 0 ;
}
V_167 ++ ;
F_116 ( & V_20 -> V_22 , & V_177 ) ;
}
if ( V_175 ) {
F_186 ( V_176 , V_175 , & V_177 , V_167 ,
V_168 ) ;
}
}
static void F_193 ( struct V_19 * V_20 , struct V_68 * V_68 )
{
F_194 ( V_20 , V_68 ) ;
F_195 ( V_20 , true ) ;
}
static inline bool F_196 ( struct V_1 * V_2 )
{
return ( V_2 -> V_15 & V_179 ) &&
! F_197 ( V_2 -> V_141 ) ;
}
static inline bool F_198 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
struct V_19 * V_20 , struct V_68 * V_68 )
{
if ( ! F_196 ( V_2 ) || ! F_199 ( V_68 ) ) {
F_193 ( V_20 , V_68 ) ;
F_146 ( & V_5 -> V_136 ) ;
V_180:
F_185 ( V_2 , V_20 , false ) ;
F_148 ( & V_5 -> V_136 ) ;
return false ;
} else {
struct V_7 * V_8 = V_2 -> V_141 ;
F_146 ( & V_5 -> V_136 ) ;
if ( ! F_139 ( V_8 , V_5 , V_68 ) ) {
F_193 ( V_20 , V_68 ) ;
goto V_180;
}
F_148 ( & V_5 -> V_136 ) ;
F_56 ( V_2 , V_5 , V_20 ) ;
return true ;
}
}
static struct V_19 * F_200 ( struct V_7 * V_8 ,
struct V_68 * V_68 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_19 * V_20 ;
F_201 ( V_8 ) ;
V_5 = F_48 ( V_8 ) ;
V_2 = F_49 ( V_8 , V_5 -> V_27 ) ;
F_202 ( V_8 , V_68 , V_68 -> V_181 ) ;
F_50 ( V_54 , V_8 , 0 , V_5 , V_2 ) ;
V_20 = F_41 ( V_54 , V_68 -> V_181 ) ;
V_54 -> V_2 -> V_139 ++ ;
return V_20 ;
}
static void F_203 ( struct V_19 * V_20 , T_1 * V_182 )
{
int V_62 ;
struct V_7 * V_8 = V_20 -> V_8 ;
struct V_1 * V_2 = F_49 ( V_8 , V_20 -> V_23 -> V_27 ) ;
struct V_145 V_146 = {
. V_20 = V_20 ,
. V_137 = NULL ,
. V_147 = 1
} ;
T_1 V_183 = F_204 ( V_20 -> V_55 , V_2 -> V_184 ) ;
if ( F_159 ( V_2 ) )
goto V_185;
V_62 = V_8 -> V_114 -> V_148 ( V_2 , & V_146 ) ;
if ( V_62 == V_144 ) {
* V_182 = V_183 ;
return;
}
F_96 ( V_20 ) ;
if ( V_62 == V_150 ) {
* V_182 = V_186 ;
V_20 -> V_40 = - V_73 ;
F_68 ( V_20 , V_20 -> V_40 ) ;
return;
}
V_185:
F_112 ( V_20 , false , true , true ) ;
}
static T_1 F_205 ( struct V_7 * V_8 , struct V_68 * V_68 )
{
const int V_187 = F_40 ( V_68 -> V_181 ) ;
const int V_188 = V_68 -> V_181 & ( V_189 | V_190 ) ;
struct V_53 V_54 ;
struct V_19 * V_20 ;
unsigned int V_191 = 0 , V_155 ;
struct V_173 * V_174 ;
struct V_19 * V_192 = NULL ;
T_1 V_182 ;
unsigned int V_193 ;
F_206 ( V_8 , & V_68 ) ;
if ( F_207 ( V_68 ) && F_208 ( V_68 ) ) {
F_209 ( V_68 ) ;
return V_186 ;
}
F_210 ( V_8 , & V_68 , V_8 -> V_194 ) ;
if ( ! V_188 && ! F_197 ( V_8 ) &&
F_211 ( V_8 , V_68 , & V_191 , & V_192 ) )
return V_186 ;
V_193 = F_212 ( V_8 -> V_78 , V_68 , NULL ) ;
V_20 = F_200 ( V_8 , V_68 , & V_54 ) ;
if ( F_66 ( ! V_20 ) ) {
F_213 ( V_8 -> V_78 , V_193 ) ;
return V_186 ;
}
F_214 ( & V_20 -> V_79 , V_193 ) ;
V_182 = F_204 ( V_20 -> V_55 , V_54 . V_2 -> V_184 ) ;
if ( F_66 ( V_188 ) ) {
F_193 ( V_20 , V_68 ) ;
F_215 ( V_20 ) ;
goto V_166;
}
V_174 = V_195 -> V_174 ;
if ( ( ( V_174 && ! F_197 ( V_8 ) ) || V_187 ) &&
! ( V_54 . V_2 -> V_15 & V_196 ) ) {
struct V_19 * V_197 = NULL ;
F_193 ( V_20 , V_68 ) ;
if ( V_174 ) {
if ( V_192 && ! F_113 ( & V_174 -> V_178 ) ) {
V_197 = V_192 ;
F_111 ( & V_197 -> V_22 ) ;
}
F_116 ( & V_20 -> V_22 , & V_174 -> V_178 ) ;
} else
V_197 = V_20 ;
F_51 ( V_54 . V_5 ) ;
if ( ! V_197 )
goto V_198;
if ( ! ( V_54 . V_2 -> V_15 & V_16 ) ) {
F_164 () ;
F_203 ( V_197 , & V_182 ) ;
F_165 () ;
} else {
V_155 = F_166 ( & V_54 . V_2 -> V_17 ) ;
F_203 ( V_197 , & V_182 ) ;
F_167 ( & V_54 . V_2 -> V_17 , V_155 ) ;
}
goto V_198;
}
if ( ! F_198 ( V_54 . V_2 , V_54 . V_5 , V_20 , V_68 ) ) {
V_166:
F_157 ( V_54 . V_2 , ! V_187 || V_188 ) ;
}
F_51 ( V_54 . V_5 ) ;
V_198:
return V_182 ;
}
static T_1 F_216 ( struct V_7 * V_8 , struct V_68 * V_68 )
{
const int V_187 = F_40 ( V_68 -> V_181 ) ;
const int V_188 = V_68 -> V_181 & ( V_189 | V_190 ) ;
struct V_173 * V_174 ;
unsigned int V_191 = 0 ;
struct V_53 V_54 ;
struct V_19 * V_20 ;
T_1 V_182 ;
unsigned int V_193 ;
F_206 ( V_8 , & V_68 ) ;
if ( F_207 ( V_68 ) && F_208 ( V_68 ) ) {
F_209 ( V_68 ) ;
return V_186 ;
}
F_210 ( V_8 , & V_68 , V_8 -> V_194 ) ;
if ( ! V_188 && ! F_197 ( V_8 ) ) {
if ( F_211 ( V_8 , V_68 , & V_191 , NULL ) )
return V_186 ;
} else
V_191 = F_217 ( V_8 ) ;
V_193 = F_212 ( V_8 -> V_78 , V_68 , NULL ) ;
V_20 = F_200 ( V_8 , V_68 , & V_54 ) ;
if ( F_66 ( ! V_20 ) ) {
F_213 ( V_8 -> V_78 , V_193 ) ;
return V_186 ;
}
F_214 ( & V_20 -> V_79 , V_193 ) ;
V_182 = F_204 ( V_20 -> V_55 , V_54 . V_2 -> V_184 ) ;
if ( F_66 ( V_188 ) ) {
F_193 ( V_20 , V_68 ) ;
F_215 ( V_20 ) ;
goto V_166;
}
V_174 = V_195 -> V_174 ;
if ( V_174 ) {
struct V_19 * V_147 = NULL ;
F_193 ( V_20 , V_68 ) ;
if ( F_113 ( & V_174 -> V_178 ) )
V_191 = 0 ;
if ( ! V_191 )
F_218 ( V_8 ) ;
else
V_147 = F_192 ( V_174 -> V_178 . V_151 ) ;
F_51 ( V_54 . V_5 ) ;
if ( V_191 >= V_199 || ( V_147 &&
F_70 ( V_147 ) >= V_200 ) ) {
F_219 ( V_174 , false ) ;
F_218 ( V_8 ) ;
}
F_116 ( & V_20 -> V_22 , & V_174 -> V_178 ) ;
return V_182 ;
}
if ( ! F_198 ( V_54 . V_2 , V_54 . V_5 , V_20 , V_68 ) ) {
V_166:
F_157 ( V_54 . V_2 , ! V_187 || V_188 ) ;
}
F_51 ( V_54 . V_5 ) ;
return V_182 ;
}
static void F_220 ( struct V_201 * V_202 ,
struct V_108 * V_18 , unsigned int V_70 )
{
struct V_203 * V_203 ;
if ( V_18 -> V_57 && V_202 -> V_113 -> V_204 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_18 -> V_109 ; V_13 ++ ) {
if ( ! V_18 -> V_57 [ V_13 ] )
continue;
V_202 -> V_113 -> V_204 ( V_202 -> V_205 , V_18 -> V_57 [ V_13 ] ,
V_70 , V_13 ) ;
V_18 -> V_57 [ V_13 ] = NULL ;
}
}
while ( ! F_113 ( & V_18 -> V_206 ) ) {
V_203 = F_122 ( & V_18 -> V_206 , struct V_203 , V_207 ) ;
F_111 ( & V_203 -> V_207 ) ;
F_221 ( F_222 ( V_203 ) ) ;
F_223 ( V_203 , V_203 -> V_208 ) ;
}
F_224 ( V_18 -> V_57 ) ;
F_225 ( V_18 ) ;
}
static T_2 F_226 ( unsigned int V_209 )
{
return ( T_2 ) V_210 << V_209 ;
}
static struct V_108 * F_227 ( struct V_201 * V_202 ,
unsigned int V_70 )
{
struct V_108 * V_18 ;
unsigned int V_13 , V_211 , V_212 , V_213 = 4 ;
T_2 V_214 , V_215 ;
V_18 = F_228 ( V_202 -> V_216 , V_202 -> V_217 ,
V_202 -> V_218 ,
F_229 ( V_202 -> V_15 ) ) ;
if ( ! V_18 )
return NULL ;
F_33 ( & V_18 -> V_206 ) ;
V_18 -> V_57 = F_230 ( V_202 -> V_216 * sizeof( struct V_19 * ) ,
V_219 | V_220 | V_221 ,
V_202 -> V_218 ) ;
if ( ! V_18 -> V_57 ) {
F_225 ( V_18 ) ;
return NULL ;
}
V_214 = F_231 ( sizeof( struct V_19 ) + V_202 -> V_222 ,
F_232 () ) ;
V_215 = V_214 * V_202 -> V_216 ;
for ( V_13 = 0 ; V_13 < V_202 -> V_216 ; ) {
int V_223 = V_213 ;
struct V_203 * V_203 ;
int V_224 ;
void * V_225 ;
while ( V_223 && V_215 < F_226 ( V_223 - 1 ) )
V_223 -- ;
do {
V_203 = F_233 ( V_202 -> V_218 ,
V_219 | V_220 | V_221 | V_226 ,
V_223 ) ;
if ( V_203 )
break;
if ( ! V_223 -- )
break;
if ( F_226 ( V_223 ) < V_214 )
break;
} while ( 1 );
if ( ! V_203 )
goto V_227;
V_203 -> V_208 = V_223 ;
F_116 ( & V_203 -> V_207 , & V_18 -> V_206 ) ;
V_225 = F_222 ( V_203 ) ;
F_234 ( V_225 , F_226 ( V_223 ) , 1 , V_219 ) ;
V_212 = F_226 ( V_223 ) / V_214 ;
V_224 = F_152 ( V_212 , V_202 -> V_216 - V_13 ) ;
V_215 -= V_224 * V_214 ;
for ( V_211 = 0 ; V_211 < V_224 ; V_211 ++ ) {
V_18 -> V_57 [ V_13 ] = V_225 ;
if ( V_202 -> V_113 -> V_228 ) {
if ( V_202 -> V_113 -> V_228 ( V_202 -> V_205 ,
V_18 -> V_57 [ V_13 ] , V_70 , V_13 ,
V_202 -> V_218 ) ) {
V_18 -> V_57 [ V_13 ] = NULL ;
goto V_227;
}
}
V_225 += V_214 ;
V_13 ++ ;
}
}
return V_18 ;
V_227:
F_220 ( V_202 , V_18 , V_70 ) ;
return NULL ;
}
static int F_235 ( unsigned int V_27 , struct V_229 * V_230 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
F_106 ( V_231 ) ;
V_2 = F_236 ( V_230 , struct V_1 , V_232 ) ;
V_5 = F_54 ( V_2 -> V_141 , V_27 ) ;
F_146 ( & V_5 -> V_136 ) ;
if ( ! F_113 ( & V_5 -> V_101 ) ) {
F_108 ( & V_5 -> V_101 , & V_231 ) ;
F_6 ( V_2 , V_5 ) ;
}
F_148 ( & V_5 -> V_136 ) ;
if ( F_113 ( & V_231 ) )
return 0 ;
F_146 ( & V_2 -> V_136 ) ;
F_147 ( & V_231 , & V_2 -> V_153 ) ;
F_148 ( & V_2 -> V_136 ) ;
F_157 ( V_2 , true ) ;
return 0 ;
}
static void F_237 ( struct V_1 * V_2 )
{
F_238 ( V_233 ,
& V_2 -> V_232 ) ;
}
static void F_239 ( struct V_7 * V_8 ,
struct V_201 * V_202 ,
struct V_1 * V_2 , unsigned int V_70 )
{
unsigned V_234 = V_202 -> V_216 ;
F_138 ( V_2 ) ;
if ( V_202 -> V_113 -> V_204 )
V_202 -> V_113 -> V_204 ( V_202 -> V_205 ,
V_2 -> V_235 -> V_236 , V_70 ,
V_234 + V_70 ) ;
if ( V_202 -> V_113 -> V_237 )
V_202 -> V_113 -> V_237 ( V_2 , V_70 ) ;
if ( V_2 -> V_15 & V_16 )
F_240 ( & V_2 -> V_17 ) ;
F_237 ( V_2 ) ;
F_241 ( V_2 -> V_235 ) ;
F_242 ( & V_2 -> V_3 ) ;
}
static void F_243 ( struct V_7 * V_8 ,
struct V_201 * V_202 , int V_238 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_24 (q, hctx, i) {
if ( V_13 == V_238 )
break;
F_239 ( V_8 , V_202 , V_2 , V_13 ) ;
}
}
static void F_244 ( struct V_7 * V_8 ,
struct V_201 * V_202 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_24 (q, hctx, i)
F_245 ( V_2 -> V_77 ) ;
}
static int F_246 ( struct V_7 * V_8 ,
struct V_201 * V_202 ,
struct V_1 * V_2 , unsigned V_70 )
{
int V_230 ;
unsigned V_234 = V_202 -> V_216 ;
V_230 = V_2 -> V_218 ;
if ( V_230 == V_239 )
V_230 = V_2 -> V_218 = V_202 -> V_218 ;
F_247 ( & V_2 -> V_162 , F_179 ) ;
F_248 ( & V_2 -> V_163 , F_180 ) ;
F_249 ( & V_2 -> V_136 ) ;
F_33 ( & V_2 -> V_153 ) ;
V_2 -> V_141 = V_8 ;
V_2 -> V_184 = V_70 ;
V_2 -> V_15 = V_202 -> V_15 & ~ V_240 ;
F_250 ( V_233 , & V_2 -> V_232 ) ;
V_2 -> V_18 = V_202 -> V_18 [ V_70 ] ;
V_2 -> V_135 = F_251 ( V_159 * sizeof( void * ) ,
V_241 , V_230 ) ;
if ( ! V_2 -> V_135 )
goto V_242;
if ( F_252 ( & V_2 -> V_3 , V_159 , F_153 ( 8 ) , V_241 ,
V_230 ) )
goto V_243;
V_2 -> V_244 = 0 ;
if ( V_202 -> V_113 -> V_245 &&
V_202 -> V_113 -> V_245 ( V_2 , V_202 -> V_205 , V_70 ) )
goto V_246;
V_2 -> V_235 = F_253 ( V_8 , V_2 -> V_218 , V_202 -> V_222 ) ;
if ( ! V_2 -> V_235 )
goto V_237;
if ( V_202 -> V_113 -> V_228 &&
V_202 -> V_113 -> V_228 ( V_202 -> V_205 ,
V_2 -> V_235 -> V_236 , V_70 ,
V_234 + V_70 , V_230 ) )
goto V_247;
if ( V_2 -> V_15 & V_16 )
F_254 ( & V_2 -> V_17 ) ;
return 0 ;
V_247:
F_224 ( V_2 -> V_235 ) ;
V_237:
if ( V_202 -> V_113 -> V_237 )
V_202 -> V_113 -> V_237 ( V_2 , V_70 ) ;
V_246:
F_242 ( & V_2 -> V_3 ) ;
V_243:
F_224 ( V_2 -> V_135 ) ;
V_242:
F_237 ( V_2 ) ;
return - 1 ;
}
static void F_255 ( struct V_7 * V_8 ,
unsigned int V_72 )
{
unsigned int V_13 ;
F_256 (i) {
struct V_4 * V_248 = F_257 ( V_8 -> V_249 , V_13 ) ;
struct V_1 * V_2 ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_27 = V_13 ;
F_249 ( & V_248 -> V_136 ) ;
F_33 ( & V_248 -> V_101 ) ;
V_248 -> V_141 = V_8 ;
F_258 ( & V_248 -> V_93 [ V_250 ] ) ;
F_258 ( & V_248 -> V_93 [ V_251 ] ) ;
if ( ! F_77 ( V_13 ) )
continue;
V_2 = F_49 ( V_8 , V_13 ) ;
if ( V_72 > 1 && V_2 -> V_218 == V_239 )
V_2 -> V_218 = F_259 ( F_260 ( V_13 ) ) ;
}
}
static void F_261 ( struct V_7 * V_8 ,
const struct V_77 * V_252 )
{
unsigned int V_13 , V_70 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_201 * V_202 = V_8 -> V_253 ;
F_262 ( & V_8 -> V_254 ) ;
F_24 (q, hctx, i) {
F_263 ( V_2 -> V_77 ) ;
V_2 -> V_244 = 0 ;
}
F_256 (i) {
if ( ! F_163 ( V_13 , V_252 ) )
continue;
V_70 = V_8 -> V_255 [ V_13 ] ;
if ( ! V_202 -> V_18 [ V_70 ] ) {
V_202 -> V_18 [ V_70 ] = F_227 ( V_202 , V_70 ) ;
if ( ! V_202 -> V_18 [ V_70 ] )
V_8 -> V_255 [ V_13 ] = 0 ;
}
V_5 = F_257 ( V_8 -> V_249 , V_13 ) ;
V_2 = F_49 ( V_8 , V_13 ) ;
F_264 ( V_13 , V_2 -> V_77 ) ;
V_5 -> V_6 = V_2 -> V_244 ;
V_2 -> V_135 [ V_2 -> V_244 ++ ] = V_5 ;
}
F_265 ( & V_8 -> V_254 ) ;
F_24 (q, hctx, i) {
if ( ! V_2 -> V_244 ) {
if ( V_13 && V_202 -> V_18 [ V_13 ] ) {
F_220 ( V_202 , V_202 -> V_18 [ V_13 ] , V_13 ) ;
V_202 -> V_18 [ V_13 ] = NULL ;
}
V_2 -> V_18 = NULL ;
continue;
}
V_2 -> V_18 = V_202 -> V_18 [ V_13 ] ;
F_162 ( ! V_2 -> V_18 ) ;
F_266 ( & V_2 -> V_3 , V_2 -> V_244 ) ;
V_2 -> V_156 = F_55 ( V_2 -> V_77 ) ;
V_2 -> V_158 = V_160 ;
}
}
static void F_267 ( struct V_7 * V_8 , bool V_85 )
{
struct V_1 * V_2 ;
int V_13 ;
F_24 (q, hctx, i) {
if ( V_85 )
V_2 -> V_15 |= V_240 ;
else
V_2 -> V_15 &= ~ V_240 ;
}
}
static void F_268 ( struct V_201 * V_202 , bool V_85 )
{
struct V_7 * V_8 ;
F_269 (q, &set->tag_list, tag_set_list) {
F_16 ( V_8 ) ;
F_267 ( V_8 , V_85 ) ;
F_17 ( V_8 ) ;
}
}
static void F_270 ( struct V_7 * V_8 )
{
struct V_201 * V_202 = V_8 -> V_253 ;
F_262 ( & V_202 -> V_256 ) ;
F_111 ( & V_8 -> V_257 ) ;
if ( F_271 ( & V_202 -> V_258 ) ) {
V_202 -> V_15 &= ~ V_240 ;
F_268 ( V_202 , false ) ;
}
F_265 ( & V_202 -> V_256 ) ;
}
static void F_272 ( struct V_201 * V_202 ,
struct V_7 * V_8 )
{
V_8 -> V_253 = V_202 ;
F_262 ( & V_202 -> V_256 ) ;
if ( ! F_113 ( & V_202 -> V_258 ) && ! ( V_202 -> V_15 & V_240 ) ) {
V_202 -> V_15 |= V_240 ;
F_268 ( V_202 , true ) ;
}
if ( V_202 -> V_15 & V_240 )
F_267 ( V_8 , true ) ;
F_116 ( & V_8 -> V_257 , & V_202 -> V_258 ) ;
F_265 ( & V_202 -> V_256 ) ;
}
void F_273 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
unsigned int V_13 ;
F_24 (q, hctx, i) {
if ( ! V_2 )
continue;
F_224 ( V_2 -> V_135 ) ;
F_224 ( V_2 ) ;
}
V_8 -> V_255 = NULL ;
F_224 ( V_8 -> V_74 ) ;
F_274 ( V_8 -> V_249 ) ;
}
struct V_7 * F_275 ( struct V_201 * V_202 )
{
struct V_7 * V_259 , * V_8 ;
V_259 = F_276 ( V_241 , V_202 -> V_218 ) ;
if ( ! V_259 )
return F_47 ( - V_260 ) ;
V_8 = F_277 ( V_202 , V_259 ) ;
if ( F_278 ( V_8 ) )
F_279 ( V_259 ) ;
return V_8 ;
}
static void F_280 ( struct V_201 * V_202 ,
struct V_7 * V_8 )
{
int V_13 , V_211 ;
struct V_1 * * V_261 = V_8 -> V_74 ;
F_281 ( V_8 ) ;
for ( V_13 = 0 ; V_13 < V_202 -> V_72 ; V_13 ++ ) {
int V_230 ;
if ( V_261 [ V_13 ] )
continue;
V_230 = F_282 ( V_8 -> V_255 , V_13 ) ;
V_261 [ V_13 ] = F_230 ( sizeof( struct V_1 ) ,
V_241 , V_230 ) ;
if ( ! V_261 [ V_13 ] )
break;
if ( ! F_283 ( & V_261 [ V_13 ] -> V_77 , V_241 ,
V_230 ) ) {
F_224 ( V_261 [ V_13 ] ) ;
V_261 [ V_13 ] = NULL ;
break;
}
F_284 ( & V_261 [ V_13 ] -> V_59 , 0 ) ;
V_261 [ V_13 ] -> V_218 = V_230 ;
V_261 [ V_13 ] -> V_184 = V_13 ;
if ( F_246 ( V_8 , V_202 , V_261 [ V_13 ] , V_13 ) ) {
F_245 ( V_261 [ V_13 ] -> V_77 ) ;
F_224 ( V_261 [ V_13 ] ) ;
V_261 [ V_13 ] = NULL ;
break;
}
F_285 ( V_261 [ V_13 ] ) ;
}
for ( V_211 = V_13 ; V_211 < V_8 -> V_72 ; V_211 ++ ) {
struct V_1 * V_2 = V_261 [ V_211 ] ;
if ( V_2 ) {
if ( V_2 -> V_18 ) {
F_220 ( V_202 , V_2 -> V_18 , V_211 ) ;
V_202 -> V_18 [ V_211 ] = NULL ;
}
F_239 ( V_8 , V_202 , V_2 , V_211 ) ;
F_245 ( V_2 -> V_77 ) ;
F_286 ( & V_2 -> V_262 ) ;
F_224 ( V_2 -> V_135 ) ;
F_224 ( V_2 ) ;
V_261 [ V_211 ] = NULL ;
}
}
V_8 -> V_72 = V_13 ;
F_287 ( V_8 ) ;
}
struct V_7 * F_277 ( struct V_201 * V_202 ,
struct V_7 * V_8 )
{
V_8 -> V_114 = V_202 -> V_113 ;
V_8 -> V_249 = F_288 ( struct V_4 ) ;
if ( ! V_8 -> V_249 )
goto V_263;
V_8 -> V_74 = F_230 ( V_159 * sizeof( * ( V_8 -> V_74 ) ) ,
V_241 , V_202 -> V_218 ) ;
if ( ! V_8 -> V_74 )
goto V_264;
V_8 -> V_255 = V_202 -> V_255 ;
F_280 ( V_202 , V_8 ) ;
if ( ! V_8 -> V_72 )
goto V_265;
F_247 ( & V_8 -> V_124 , F_132 ) ;
F_289 ( V_8 , V_202 -> V_48 ? V_202 -> V_48 : 30 * V_266 ) ;
V_8 -> V_267 = V_159 ;
V_8 -> V_87 |= V_268 ;
if ( ! ( V_202 -> V_15 & V_269 ) )
V_8 -> V_87 |= 1 << V_270 ;
V_8 -> V_271 = V_272 ;
F_248 ( & V_8 -> V_100 , F_104 ) ;
F_33 ( & V_8 -> V_104 ) ;
F_249 ( & V_8 -> V_103 ) ;
if ( V_8 -> V_72 > 1 )
F_290 ( V_8 , F_205 ) ;
else
F_290 ( V_8 , F_216 ) ;
V_8 -> V_273 = V_202 -> V_216 ;
V_8 -> V_274 = - 1 ;
if ( V_202 -> V_113 -> V_275 )
F_291 ( V_8 , V_202 -> V_113 -> V_275 ) ;
F_255 ( V_8 , V_202 -> V_72 ) ;
F_292 () ;
F_262 ( & V_276 ) ;
F_116 ( & V_8 -> V_277 , & V_278 ) ;
F_272 ( V_202 , V_8 ) ;
F_261 ( V_8 , V_279 ) ;
F_265 ( & V_276 ) ;
F_293 () ;
return V_8 ;
V_265:
F_224 ( V_8 -> V_74 ) ;
V_264:
F_274 ( V_8 -> V_249 ) ;
V_263:
V_8 -> V_114 = NULL ;
return F_47 ( - V_260 ) ;
}
void F_294 ( struct V_7 * V_8 )
{
struct V_201 * V_202 = V_8 -> V_253 ;
F_262 ( & V_276 ) ;
F_111 ( & V_8 -> V_277 ) ;
F_265 ( & V_276 ) ;
F_295 ( V_8 ) ;
F_270 ( V_8 ) ;
F_243 ( V_8 , V_202 , V_202 -> V_72 ) ;
F_244 ( V_8 , V_202 ) ;
}
static void F_296 ( struct V_7 * V_8 ,
const struct V_77 * V_252 )
{
F_19 ( ! F_297 ( & V_8 -> V_10 ) ) ;
F_281 ( V_8 ) ;
F_261 ( V_8 , V_252 ) ;
F_287 ( V_8 ) ;
}
static void F_298 ( void )
{
struct V_7 * V_8 ;
F_262 ( & V_276 ) ;
F_269 (q, &all_q_list, all_q_node)
F_8 ( V_8 ) ;
F_269 (q, &all_q_list, all_q_node)
F_12 ( V_8 ) ;
F_269 (q, &all_q_list, all_q_node)
F_296 ( V_8 , & V_280 ) ;
F_269 (q, &all_q_list, all_q_node)
F_17 ( V_8 ) ;
F_265 ( & V_276 ) ;
}
static int F_299 ( unsigned int V_27 )
{
F_300 ( & V_280 , V_279 ) ;
F_298 () ;
return 0 ;
}
static int F_301 ( unsigned int V_27 )
{
F_300 ( & V_280 , V_279 ) ;
F_264 ( V_27 , & V_280 ) ;
F_298 () ;
return 0 ;
}
static int F_302 ( struct V_201 * V_202 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_202 -> V_72 ; V_13 ++ ) {
V_202 -> V_18 [ V_13 ] = F_227 ( V_202 , V_13 ) ;
if ( ! V_202 -> V_18 [ V_13 ] )
goto V_281;
}
return 0 ;
V_281:
while ( -- V_13 >= 0 )
F_220 ( V_202 , V_202 -> V_18 [ V_13 ] , V_13 ) ;
return - V_260 ;
}
static int F_303 ( struct V_201 * V_202 )
{
unsigned int V_167 ;
int V_282 ;
V_167 = V_202 -> V_216 ;
do {
V_282 = F_302 ( V_202 ) ;
if ( ! V_282 )
break;
V_202 -> V_216 >>= 1 ;
if ( V_202 -> V_216 < V_202 -> V_217 + V_283 ) {
V_282 = - V_260 ;
break;
}
} while ( V_202 -> V_216 );
if ( ! V_202 -> V_216 || V_282 ) {
F_155 ( L_3 ) ;
return - V_260 ;
}
if ( V_167 != V_202 -> V_216 )
F_304 ( L_4 ,
V_167 , V_202 -> V_216 ) ;
return 0 ;
}
int F_305 ( struct V_201 * V_202 )
{
int V_62 ;
F_306 ( V_284 > 1 << V_285 ) ;
if ( ! V_202 -> V_72 )
return - V_71 ;
if ( ! V_202 -> V_216 )
return - V_71 ;
if ( V_202 -> V_216 < V_202 -> V_217 + V_283 )
return - V_71 ;
if ( ! V_202 -> V_113 -> V_148 )
return - V_71 ;
if ( V_202 -> V_216 > V_284 ) {
F_304 ( L_5 ,
V_284 ) ;
V_202 -> V_216 = V_284 ;
}
if ( F_307 () ) {
V_202 -> V_72 = 1 ;
V_202 -> V_216 = F_152 ( 64U , V_202 -> V_216 ) ;
}
if ( V_202 -> V_72 > V_159 )
V_202 -> V_72 = V_159 ;
V_202 -> V_18 = F_230 ( V_159 * sizeof( struct V_108 * ) ,
V_241 , V_202 -> V_218 ) ;
if ( ! V_202 -> V_18 )
return - V_260 ;
V_62 = - V_260 ;
V_202 -> V_255 = F_230 ( sizeof( * V_202 -> V_255 ) * V_159 ,
V_241 , V_202 -> V_218 ) ;
if ( ! V_202 -> V_255 )
goto V_286;
if ( V_202 -> V_113 -> V_287 )
V_62 = V_202 -> V_113 -> V_287 ( V_202 ) ;
else
V_62 = F_308 ( V_202 ) ;
if ( V_62 )
goto V_288;
V_62 = F_303 ( V_202 ) ;
if ( V_62 )
goto V_288;
F_309 ( & V_202 -> V_256 ) ;
F_33 ( & V_202 -> V_258 ) ;
return 0 ;
V_288:
F_224 ( V_202 -> V_255 ) ;
V_202 -> V_255 = NULL ;
V_286:
F_224 ( V_202 -> V_18 ) ;
V_202 -> V_18 = NULL ;
return V_62 ;
}
void F_310 ( struct V_201 * V_202 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_159 ; V_13 ++ ) {
if ( V_202 -> V_18 [ V_13 ] )
F_220 ( V_202 , V_202 -> V_18 [ V_13 ] , V_13 ) ;
}
F_224 ( V_202 -> V_255 ) ;
V_202 -> V_255 = NULL ;
F_224 ( V_202 -> V_18 ) ;
V_202 -> V_18 = NULL ;
}
int F_311 ( struct V_7 * V_8 , unsigned int V_289 )
{
struct V_201 * V_202 = V_8 -> V_253 ;
struct V_1 * V_2 ;
int V_13 , V_62 ;
if ( ! V_202 || V_289 > V_202 -> V_216 )
return - V_71 ;
V_62 = 0 ;
F_24 (q, hctx, i) {
if ( ! V_2 -> V_18 )
continue;
V_62 = F_312 ( V_2 -> V_18 , V_289 ) ;
if ( V_62 )
break;
}
if ( ! V_62 )
V_8 -> V_273 = V_289 ;
return V_62 ;
}
void F_313 ( struct V_201 * V_202 , int V_72 )
{
struct V_7 * V_8 ;
if ( V_72 > V_159 )
V_72 = V_159 ;
if ( V_72 < 1 || V_72 == V_202 -> V_72 )
return;
F_269 (q, &set->tag_list, tag_set_list)
F_16 ( V_8 ) ;
V_202 -> V_72 = V_72 ;
F_269 (q, &set->tag_list, tag_set_list) {
F_280 ( V_202 , V_8 ) ;
if ( V_8 -> V_72 > 1 )
F_290 ( V_8 , F_205 ) ;
else
F_290 ( V_8 , F_216 ) ;
F_296 ( V_8 , V_279 ) ;
}
F_269 (q, &set->tag_list, tag_set_list)
F_17 ( V_8 ) ;
}
static unsigned long F_314 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_290 V_93 [ 2 ] ;
unsigned long V_62 = 0 ;
if ( ! F_315 ( V_8 ) )
return 0 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
F_316 ( V_2 , V_93 ) ;
if ( F_317 ( V_20 ) == V_291 && V_93 [ V_250 ] . V_292 )
V_62 = ( V_93 [ V_250 ] . V_293 + 1 ) / 2 ;
else if ( F_317 ( V_20 ) == V_294 && V_93 [ V_251 ] . V_292 )
V_62 = ( V_93 [ V_251 ] . V_293 + 1 ) / 2 ;
return V_62 ;
}
static bool F_318 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_295 V_296 ;
enum V_297 V_298 ;
unsigned int V_299 ;
T_3 V_300 ;
if ( F_74 ( V_82 , & V_20 -> V_81 ) )
return false ;
if ( V_8 -> V_274 == - 1 )
return false ;
else if ( V_8 -> V_274 > 0 )
V_299 = V_8 -> V_274 ;
else
V_299 = F_314 ( V_8 , V_2 , V_20 ) ;
if ( ! V_299 )
return false ;
F_95 ( V_82 , & V_20 -> V_81 ) ;
V_300 = V_299 ;
V_298 = V_301 ;
F_319 ( & V_296 . V_302 , V_303 , V_298 ) ;
F_320 ( & V_296 . V_302 , V_300 ) ;
F_321 ( & V_296 , V_195 ) ;
do {
if ( F_74 ( V_95 , & V_20 -> V_81 ) )
break;
F_322 ( V_304 ) ;
F_323 ( & V_296 . V_302 , V_298 ) ;
if ( V_296 . V_305 )
F_324 () ;
F_325 ( & V_296 . V_302 ) ;
V_298 = V_306 ;
} while ( V_296 . V_305 && ! F_326 ( V_195 ) );
F_327 ( V_307 ) ;
F_328 ( & V_296 . V_302 ) ;
return true ;
}
static bool F_329 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_7 * V_8 = V_2 -> V_141 ;
long V_165 ;
if ( F_318 ( V_8 , V_2 , V_20 ) )
return true ;
V_2 -> V_308 ++ ;
V_165 = V_195 -> V_165 ;
while ( ! F_330 () ) {
int V_62 ;
V_2 -> V_309 ++ ;
V_62 = V_8 -> V_114 -> V_310 ( V_2 , V_20 -> V_55 ) ;
if ( V_62 > 0 ) {
V_2 -> V_311 ++ ;
F_322 ( V_307 ) ;
return true ;
}
if ( F_331 ( V_165 , V_195 ) )
F_322 ( V_307 ) ;
if ( V_195 -> V_165 == V_307 )
return true ;
if ( V_62 < 0 )
break;
F_332 () ;
}
return false ;
}
bool F_333 ( struct V_7 * V_8 , T_1 V_182 )
{
struct V_1 * V_2 ;
struct V_173 * V_174 ;
struct V_19 * V_20 ;
if ( ! V_8 -> V_114 || ! V_8 -> V_114 -> V_310 || ! F_334 ( V_182 ) ||
! F_74 ( V_312 , & V_8 -> V_87 ) )
return false ;
V_174 = V_195 -> V_174 ;
if ( V_174 )
F_219 ( V_174 , false ) ;
V_2 = V_8 -> V_74 [ F_335 ( V_182 ) ] ;
V_20 = F_123 ( V_2 -> V_18 , F_336 ( V_182 ) ) ;
return F_329 ( V_2 , V_20 ) ;
}
void F_337 ( void )
{
F_262 ( & V_276 ) ;
}
void F_338 ( void )
{
F_265 ( & V_276 ) ;
}
static int T_4 F_339 ( void )
{
F_340 ( V_233 , L_6 , NULL ,
F_235 ) ;
F_341 ( V_313 , L_7 ,
F_301 ,
F_299 ) ;
return 0 ;
}
