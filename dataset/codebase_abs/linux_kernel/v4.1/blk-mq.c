static bool F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ )
if ( V_2 -> V_4 . V_6 [ V_3 ] . V_7 )
return true ;
return false ;
}
static inline struct V_8 * F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
return & V_2 -> V_4 . V_6 [ V_10 -> V_11 / V_2 -> V_4 . V_12 ] ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_8 * V_13 = F_2 ( V_2 , V_10 ) ;
if ( ! F_4 ( F_5 ( V_2 , V_10 ) , & V_13 -> V_7 ) )
F_6 ( F_5 ( V_2 , V_10 ) , & V_13 -> V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_8 * V_13 = F_2 ( V_2 , V_10 ) ;
F_8 ( F_5 ( V_2 , V_10 ) , & V_13 -> V_7 ) ;
}
static int F_9 ( struct V_14 * V_15 , T_1 V_16 )
{
while ( true ) {
int V_17 ;
if ( F_10 ( & V_15 -> V_18 ) )
return 0 ;
if ( ! ( V_16 & V_19 ) )
return - V_20 ;
V_17 = F_11 ( V_15 -> V_21 ,
! V_15 -> V_22 || F_12 ( V_15 ) ) ;
if ( F_12 ( V_15 ) )
return - V_23 ;
if ( V_17 )
return V_17 ;
}
}
static void F_13 ( struct V_14 * V_15 )
{
F_14 ( & V_15 -> V_18 ) ;
}
static void F_15 ( struct V_24 * V_25 )
{
struct V_14 * V_15 =
F_16 ( V_25 , struct V_14 , V_18 ) ;
F_17 ( & V_15 -> V_21 ) ;
}
void F_18 ( struct V_14 * V_15 )
{
bool V_26 ;
F_19 ( V_15 -> V_27 ) ;
V_26 = ! V_15 -> V_22 ++ ;
F_20 ( V_15 -> V_27 ) ;
if ( V_26 ) {
F_21 ( & V_15 -> V_18 ) ;
F_22 ( V_15 , false ) ;
}
}
static void F_23 ( struct V_14 * V_15 )
{
F_24 ( V_15 -> V_21 , F_25 ( & V_15 -> V_18 ) ) ;
}
void F_26 ( struct V_14 * V_15 )
{
F_18 ( V_15 ) ;
F_23 ( V_15 ) ;
}
void F_27 ( struct V_14 * V_15 )
{
bool V_28 ;
F_19 ( V_15 -> V_27 ) ;
V_28 = ! -- V_15 -> V_22 ;
F_28 ( V_15 -> V_22 < 0 ) ;
F_20 ( V_15 -> V_27 ) ;
if ( V_28 ) {
F_29 ( & V_15 -> V_18 ) ;
F_17 ( & V_15 -> V_21 ) ;
}
}
void F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i)
if ( F_32 ( V_2 ) )
F_33 ( V_2 -> V_29 , true ) ;
F_17 ( & V_15 -> V_21 ) ;
}
bool F_34 ( struct V_1 * V_2 )
{
return F_35 ( V_2 -> V_29 ) ;
}
static void F_36 ( struct V_14 * V_15 , struct V_9 * V_10 ,
struct V_30 * V_31 , unsigned int V_32 )
{
if ( F_37 ( V_15 ) )
V_32 |= V_33 ;
F_38 ( & V_31 -> V_34 ) ;
V_31 -> V_15 = V_15 ;
V_31 -> V_35 = V_10 ;
V_31 -> V_36 |= V_32 ;
V_31 -> V_37 = - 1 ;
F_39 ( & V_31 -> V_38 ) ;
F_40 ( & V_31 -> V_39 ) ;
V_31 -> V_40 = NULL ;
V_31 -> V_41 = NULL ;
V_31 -> V_42 = V_43 ;
#ifdef F_41
V_31 -> V_44 = NULL ;
F_42 ( V_31 ) ;
V_31 -> V_45 = 0 ;
#endif
V_31 -> V_46 = 0 ;
#if F_43 ( V_47 )
V_31 -> V_48 = 0 ;
#endif
V_31 -> V_49 = NULL ;
V_31 -> V_50 = 0 ;
V_31 -> V_51 = V_31 -> V_52 ;
V_31 -> V_53 = 0 ;
V_31 -> V_54 = 0 ;
V_31 -> V_55 = 0 ;
V_31 -> V_56 = NULL ;
F_38 ( & V_31 -> V_57 ) ;
V_31 -> V_58 = 0 ;
V_31 -> V_59 = NULL ;
V_31 -> V_60 = NULL ;
V_31 -> V_61 = NULL ;
V_10 -> V_62 [ F_44 ( V_32 ) ] ++ ;
}
static struct V_30 *
F_45 ( struct V_63 * V_64 , int V_65 )
{
struct V_30 * V_31 ;
unsigned int V_66 ;
V_66 = F_46 ( V_64 ) ;
if ( V_66 != V_67 ) {
V_31 = V_64 -> V_2 -> V_29 -> V_68 [ V_66 ] ;
if ( F_47 ( V_64 -> V_2 ) ) {
V_31 -> V_36 = V_69 ;
F_48 ( & V_64 -> V_2 -> V_70 ) ;
}
V_31 -> V_66 = V_66 ;
F_36 ( V_64 -> V_15 , V_64 -> V_10 , V_31 , V_65 ) ;
return V_31 ;
}
return NULL ;
}
struct V_30 * F_49 ( struct V_14 * V_15 , int V_65 , T_1 V_16 ,
bool V_71 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_63 V_72 ;
int V_17 ;
V_17 = F_9 ( V_15 , V_16 ) ;
if ( V_17 )
return F_50 ( V_17 ) ;
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_10 -> V_37 ) ;
F_52 ( & V_72 , V_15 , V_16 & ~ V_19 ,
V_71 , V_10 , V_2 ) ;
V_31 = F_45 ( & V_72 , V_65 ) ;
if ( ! V_31 && ( V_16 & V_19 ) ) {
F_53 ( V_2 ) ;
F_54 ( V_10 ) ;
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_10 -> V_37 ) ;
F_52 ( & V_72 , V_15 , V_16 , V_71 , V_10 ,
V_2 ) ;
V_31 = F_45 ( & V_72 , V_65 ) ;
V_10 = V_72 . V_10 ;
}
F_54 ( V_10 ) ;
if ( ! V_31 ) {
F_13 ( V_15 ) ;
return F_50 ( - V_75 ) ;
}
return V_31 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_30 * V_31 )
{
const int V_66 = V_31 -> V_66 ;
struct V_14 * V_15 = V_31 -> V_15 ;
if ( V_31 -> V_36 & V_69 )
F_56 ( & V_2 -> V_70 ) ;
V_31 -> V_36 = 0 ;
F_8 ( V_76 , & V_31 -> V_77 ) ;
F_57 ( V_2 , V_66 , & V_10 -> V_78 ) ;
F_13 ( V_15 ) ;
}
void F_58 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_35 ;
V_10 -> V_79 [ F_59 ( V_31 ) ] ++ ;
F_55 ( V_2 , V_10 , V_31 ) ;
}
void F_60 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = V_31 -> V_15 ;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_31 -> V_35 -> V_37 ) ;
F_58 ( V_2 , V_31 ) ;
}
inline void F_61 ( struct V_30 * V_31 , int error )
{
F_62 ( V_31 ) ;
if ( V_31 -> V_59 ) {
V_31 -> V_59 ( V_31 , error ) ;
} else {
if ( F_63 ( F_64 ( V_31 ) ) )
F_60 ( V_31 -> V_61 ) ;
F_60 ( V_31 ) ;
}
}
void F_65 ( struct V_30 * V_31 , int error )
{
if ( F_66 ( V_31 , error , F_67 ( V_31 ) ) )
F_68 () ;
F_61 ( V_31 , error ) ;
}
static void F_69 ( void * V_64 )
{
struct V_30 * V_31 = V_64 ;
V_31 -> V_15 -> V_80 ( V_31 ) ;
}
static void F_70 ( struct V_30 * V_31 )
{
struct V_9 * V_10 = V_31 -> V_35 ;
bool V_81 = false ;
int V_37 ;
if ( ! F_4 ( V_82 , & V_31 -> V_15 -> V_83 ) ) {
V_31 -> V_15 -> V_80 ( V_31 ) ;
return;
}
V_37 = F_71 () ;
if ( ! F_4 ( V_84 , & V_31 -> V_15 -> V_83 ) )
V_81 = F_72 ( V_37 , V_10 -> V_37 ) ;
if ( V_37 != V_10 -> V_37 && ! V_81 && F_73 ( V_10 -> V_37 ) ) {
V_31 -> V_85 . V_86 = F_69 ;
V_31 -> V_85 . V_87 = V_31 ;
V_31 -> V_85 . V_88 = 0 ;
F_74 ( V_10 -> V_37 , & V_31 -> V_85 ) ;
} else {
V_31 -> V_15 -> V_80 ( V_31 ) ;
}
F_75 () ;
}
void F_76 ( struct V_30 * V_31 )
{
struct V_14 * V_15 = V_31 -> V_15 ;
if ( ! V_15 -> V_80 )
F_65 ( V_31 , V_31 -> V_50 ) ;
else
F_70 ( V_31 ) ;
}
void F_77 ( struct V_30 * V_31 )
{
struct V_14 * V_15 = V_31 -> V_15 ;
if ( F_63 ( F_78 ( V_15 ) ) )
return;
if ( ! F_79 ( V_31 ) )
F_76 ( V_31 ) ;
}
int F_80 ( struct V_30 * V_31 )
{
return F_4 ( V_76 , & V_31 -> V_77 ) ;
}
void F_81 ( struct V_30 * V_31 )
{
struct V_14 * V_15 = V_31 -> V_15 ;
F_82 ( V_15 , V_31 ) ;
V_31 -> V_55 = F_67 ( V_31 ) ;
if ( F_63 ( F_64 ( V_31 ) ) )
V_31 -> V_61 -> V_55 = F_67 ( V_31 -> V_61 ) ;
F_83 ( V_31 ) ;
F_84 () ;
if ( ! F_4 ( V_76 , & V_31 -> V_77 ) )
F_6 ( V_76 , & V_31 -> V_77 ) ;
if ( F_4 ( V_89 , & V_31 -> V_77 ) )
F_8 ( V_89 , & V_31 -> V_77 ) ;
if ( V_15 -> V_90 && F_67 ( V_31 ) ) {
V_31 -> V_46 ++ ;
}
}
static void F_85 ( struct V_30 * V_31 )
{
struct V_14 * V_15 = V_31 -> V_15 ;
F_86 ( V_15 , V_31 ) ;
if ( F_87 ( V_76 , & V_31 -> V_77 ) ) {
if ( V_15 -> V_90 && F_67 ( V_31 ) )
V_31 -> V_46 -- ;
}
}
void F_88 ( struct V_30 * V_31 )
{
F_85 ( V_31 ) ;
F_89 ( F_90 ( V_31 ) ) ;
F_91 ( V_31 , true ) ;
}
static void F_92 ( struct V_91 * V_92 )
{
struct V_14 * V_15 =
F_16 ( V_92 , struct V_14 , V_93 ) ;
F_93 ( V_94 ) ;
struct V_30 * V_31 , * V_95 ;
unsigned long V_88 ;
F_94 ( & V_15 -> V_96 , V_88 ) ;
F_95 ( & V_15 -> V_97 , & V_94 ) ;
F_96 ( & V_15 -> V_96 , V_88 ) ;
F_97 (rq, next, &rq_list, queuelist) {
if ( ! ( V_31 -> V_36 & V_98 ) )
continue;
V_31 -> V_36 &= ~ V_98 ;
F_98 ( & V_31 -> V_34 ) ;
F_99 ( V_31 , true , false , false ) ;
}
while ( ! F_100 ( & V_94 ) ) {
V_31 = F_101 ( V_94 . V_95 , struct V_30 , V_34 ) ;
F_98 ( & V_31 -> V_34 ) ;
F_99 ( V_31 , false , false , false ) ;
}
F_102 ( V_15 ) ;
}
void F_91 ( struct V_30 * V_31 , bool V_99 )
{
struct V_14 * V_15 = V_31 -> V_15 ;
unsigned long V_88 ;
F_89 ( V_31 -> V_36 & V_98 ) ;
F_94 ( & V_15 -> V_96 , V_88 ) ;
if ( V_99 ) {
V_31 -> V_36 |= V_98 ;
F_103 ( & V_31 -> V_34 , & V_15 -> V_97 ) ;
} else {
F_104 ( & V_31 -> V_34 , & V_15 -> V_97 ) ;
}
F_96 ( & V_15 -> V_96 , V_88 ) ;
}
void F_105 ( struct V_14 * V_15 )
{
F_106 ( & V_15 -> V_93 ) ;
}
void F_107 ( struct V_14 * V_15 )
{
F_108 ( & V_15 -> V_93 ) ;
}
void F_109 ( struct V_14 * V_15 )
{
unsigned long V_88 ;
F_93 ( V_94 ) ;
F_94 ( & V_15 -> V_96 , V_88 ) ;
F_95 ( & V_15 -> V_97 , & V_94 ) ;
F_96 ( & V_15 -> V_96 , V_88 ) ;
while ( ! F_100 ( & V_94 ) ) {
struct V_30 * V_31 ;
V_31 = F_110 ( & V_94 , struct V_30 , V_34 ) ;
F_98 ( & V_31 -> V_34 ) ;
V_31 -> V_50 = - V_100 ;
F_65 ( V_31 , V_31 -> V_50 ) ;
}
}
static inline bool F_111 ( struct V_30 * V_31 ,
struct V_101 * V_102 , unsigned int V_66 )
{
return ( ( V_31 -> V_36 & V_103 ) &&
V_102 -> V_104 -> V_66 == V_66 ) ;
}
struct V_30 * F_112 ( struct V_105 * V_29 , unsigned int V_66 )
{
struct V_30 * V_31 = V_29 -> V_68 [ V_66 ] ;
struct V_101 * V_102 = F_113 ( V_31 -> V_15 , V_31 -> V_35 ) ;
if ( ! F_111 ( V_31 , V_102 , V_66 ) )
return V_31 ;
return V_102 -> V_104 ;
}
void F_114 ( struct V_30 * V_106 , bool V_71 )
{
struct V_107 * V_108 = V_106 -> V_15 -> V_73 ;
enum V_109 V_17 = V_110 ;
if ( ! F_4 ( V_76 , & V_106 -> V_77 ) )
return;
if ( V_108 -> V_58 )
V_17 = V_108 -> V_58 ( V_106 , V_71 ) ;
switch ( V_17 ) {
case V_111 :
F_76 ( V_106 ) ;
break;
case V_110 :
F_83 ( V_106 ) ;
F_115 ( V_106 ) ;
break;
case V_112 :
break;
default:
F_116 ( V_113 L_1 , V_17 ) ;
break;
}
}
static void F_117 ( struct V_1 * V_2 ,
struct V_30 * V_31 , void * V_114 , bool V_71 )
{
struct V_115 * V_64 = V_114 ;
if ( ! F_4 ( V_76 , & V_31 -> V_77 ) ) {
if ( F_63 ( F_12 ( V_31 -> V_15 ) ) ) {
V_31 -> V_50 = - V_100 ;
F_77 ( V_31 ) ;
}
return;
}
if ( V_31 -> V_36 & V_116 )
return;
if ( F_118 ( V_43 , V_31 -> V_117 ) ) {
if ( ! F_79 ( V_31 ) )
F_114 ( V_31 , V_71 ) ;
} else if ( ! V_64 -> V_118 || F_119 ( V_64 -> V_95 , V_31 -> V_117 ) ) {
V_64 -> V_95 = V_31 -> V_117 ;
V_64 -> V_118 = 1 ;
}
}
static void F_120 ( unsigned long V_114 )
{
struct V_14 * V_15 = (struct V_14 * ) V_114 ;
struct V_115 V_64 = {
. V_95 = 0 ,
. V_118 = 0 ,
} ;
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i) {
if ( ! F_32 ( V_2 ) )
continue;
F_121 ( V_2 , F_117 , & V_64 ) ;
}
if ( V_64 . V_118 ) {
V_64 . V_95 = F_122 ( F_123 ( V_64 . V_95 ) ) ;
F_124 ( & V_15 -> V_58 , V_64 . V_95 ) ;
} else {
F_31 (q, hctx, i) {
if ( F_32 ( V_2 ) )
F_125 ( V_2 ) ;
}
}
}
static bool F_126 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_119 * V_119 )
{
struct V_30 * V_31 ;
int V_120 = 8 ;
F_127 (rq, &ctx->rq_list, queuelist) {
int V_121 ;
if ( ! V_120 -- )
break;
if ( ! F_128 ( V_31 , V_119 ) )
continue;
V_121 = F_129 ( V_31 , V_119 ) ;
if ( V_121 == V_122 ) {
if ( F_130 ( V_15 , V_31 , V_119 ) ) {
V_10 -> V_123 ++ ;
return true ;
}
break;
} else if ( V_121 == V_124 ) {
if ( F_131 ( V_15 , V_31 , V_119 ) ) {
V_10 -> V_123 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_132 ( struct V_1 * V_2 , struct V_125 * V_126 )
{
struct V_9 * V_10 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_8 * V_13 = & V_2 -> V_4 . V_6 [ V_3 ] ;
unsigned int V_127 , V_128 ;
if ( ! V_13 -> V_7 )
continue;
V_128 = 0 ;
V_127 = V_3 * V_2 -> V_4 . V_12 ;
do {
V_128 = F_133 ( & V_13 -> V_7 , V_13 -> V_129 , V_128 ) ;
if ( V_128 >= V_13 -> V_129 )
break;
V_10 = V_2 -> V_130 [ V_128 + V_127 ] ;
F_8 ( V_128 , & V_13 -> V_7 ) ;
F_134 ( & V_10 -> V_131 ) ;
F_135 ( & V_10 -> V_94 , V_126 ) ;
F_136 ( & V_10 -> V_131 ) ;
V_128 ++ ;
} while ( 1 );
}
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_132 ;
struct V_30 * V_31 ;
F_93 ( V_94 ) ;
F_93 ( V_133 ) ;
struct V_125 * V_134 ;
int V_135 ;
F_137 ( ! F_138 ( F_139 () , V_2 -> V_136 ) ) ;
if ( F_63 ( F_4 ( V_137 , & V_2 -> V_138 ) ) )
return;
V_2 -> V_139 ++ ;
F_132 ( V_2 , & V_94 ) ;
if ( ! F_140 ( & V_2 -> V_140 ) ) {
F_134 ( & V_2 -> V_131 ) ;
if ( ! F_100 ( & V_2 -> V_140 ) )
F_95 ( & V_2 -> V_140 , & V_94 ) ;
F_136 ( & V_2 -> V_131 ) ;
}
V_134 = NULL ;
V_135 = 0 ;
while ( ! F_100 ( & V_94 ) ) {
struct V_141 V_142 ;
int V_17 ;
V_31 = F_110 ( & V_94 , struct V_30 , V_34 ) ;
F_98 ( & V_31 -> V_34 ) ;
V_142 . V_31 = V_31 ;
V_142 . V_126 = V_134 ;
V_142 . V_143 = F_100 ( & V_94 ) ;
V_17 = V_15 -> V_73 -> V_144 ( V_2 , & V_142 ) ;
switch ( V_17 ) {
case V_145 :
V_135 ++ ;
continue;
case V_146 :
F_103 ( & V_31 -> V_34 , & V_94 ) ;
F_85 ( V_31 ) ;
break;
default:
F_141 ( L_2 , V_17 ) ;
case V_147 :
V_31 -> V_50 = - V_100 ;
F_65 ( V_31 , V_31 -> V_50 ) ;
break;
}
if ( V_17 == V_146 )
break;
if ( ! V_134 && V_94 . V_95 != V_94 . V_148 )
V_134 = & V_133 ;
}
if ( ! V_135 )
V_2 -> V_149 [ 0 ] ++ ;
else if ( V_135 < ( 1 << ( V_150 - 1 ) ) )
V_2 -> V_149 [ F_142 ( V_135 ) + 1 ] ++ ;
if ( ! F_100 ( & V_94 ) ) {
F_134 ( & V_2 -> V_131 ) ;
F_143 ( & V_94 , & V_2 -> V_140 ) ;
F_136 ( & V_2 -> V_131 ) ;
F_144 ( V_2 , true ) ;
}
}
static int F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_132 -> V_151 == 1 )
return V_152 ;
if ( -- V_2 -> V_153 <= 0 ) {
int V_37 = V_2 -> V_154 , V_154 ;
V_154 = F_146 ( V_2 -> V_154 , V_2 -> V_136 ) ;
if ( V_154 >= V_155 )
V_154 = F_147 ( V_2 -> V_136 ) ;
V_2 -> V_154 = V_154 ;
V_2 -> V_153 = V_156 ;
return V_37 ;
}
return V_2 -> V_154 ;
}
void F_144 ( struct V_1 * V_2 , bool V_157 )
{
if ( F_63 ( F_4 ( V_137 , & V_2 -> V_138 ) ||
! F_32 ( V_2 ) ) )
return;
if ( ! V_157 ) {
int V_37 = F_71 () ;
if ( F_138 ( V_37 , V_2 -> V_136 ) ) {
F_53 ( V_2 ) ;
F_75 () ;
return;
}
F_75 () ;
}
F_148 ( F_145 ( V_2 ) ,
& V_2 -> V_158 , 0 ) ;
}
void F_22 ( struct V_14 * V_15 , bool V_157 )
{
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_140 ( & V_2 -> V_140 ) ) ||
F_4 ( V_137 , & V_2 -> V_138 ) )
continue;
F_144 ( V_2 , V_157 ) ;
}
}
void F_149 ( struct V_1 * V_2 )
{
F_150 ( & V_2 -> V_158 ) ;
F_150 ( & V_2 -> V_159 ) ;
F_6 ( V_137 , & V_2 -> V_138 ) ;
}
void F_151 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i)
F_149 ( V_2 ) ;
}
void F_152 ( struct V_1 * V_2 )
{
F_8 ( V_137 , & V_2 -> V_138 ) ;
F_144 ( V_2 , false ) ;
}
void F_102 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i)
F_152 ( V_2 ) ;
}
void F_153 ( struct V_14 * V_15 , bool V_157 )
{
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i) {
if ( ! F_4 ( V_137 , & V_2 -> V_138 ) )
continue;
F_8 ( V_137 , & V_2 -> V_138 ) ;
F_144 ( V_2 , V_157 ) ;
}
}
static void F_154 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_92 , struct V_1 , V_158 . V_92 ) ;
F_53 ( V_2 ) ;
}
static void F_155 ( struct V_91 * V_92 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_92 , struct V_1 , V_159 . V_92 ) ;
if ( F_87 ( V_137 , & V_2 -> V_138 ) )
F_53 ( V_2 ) ;
}
void F_156 ( struct V_1 * V_2 , unsigned long V_160 )
{
if ( F_63 ( ! F_32 ( V_2 ) ) )
return;
F_148 ( F_145 ( V_2 ) ,
& V_2 -> V_159 , F_157 ( V_160 ) ) ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_30 * V_31 , bool V_99 )
{
struct V_9 * V_10 = V_31 -> V_35 ;
F_159 ( V_2 -> V_132 , V_31 ) ;
if ( V_99 )
F_103 ( & V_31 -> V_34 , & V_10 -> V_94 ) ;
else
F_104 ( & V_31 -> V_34 , & V_10 -> V_94 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_99 ( struct V_30 * V_31 , bool V_99 , bool V_161 ,
bool V_157 )
{
struct V_14 * V_15 = V_31 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_31 -> V_35 , * V_162 ;
V_162 = F_51 ( V_15 ) ;
if ( ! F_73 ( V_10 -> V_37 ) )
V_31 -> V_35 = V_10 = V_162 ;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_10 -> V_37 ) ;
F_134 ( & V_10 -> V_131 ) ;
F_158 ( V_2 , V_31 , V_99 ) ;
F_136 ( & V_10 -> V_131 ) ;
if ( V_161 )
F_144 ( V_2 , V_157 ) ;
F_54 ( V_162 ) ;
}
static void F_160 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_125 * V_126 ,
int V_129 ,
bool V_163 )
{
struct V_1 * V_2 ;
struct V_9 * V_162 ;
F_161 ( V_15 , V_129 , ! V_163 ) ;
V_162 = F_51 ( V_15 ) ;
if ( ! F_73 ( V_10 -> V_37 ) )
V_10 = V_162 ;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_10 -> V_37 ) ;
F_134 ( & V_10 -> V_131 ) ;
while ( ! F_100 ( V_126 ) ) {
struct V_30 * V_31 ;
V_31 = F_110 ( V_126 , struct V_30 , V_34 ) ;
F_98 ( & V_31 -> V_34 ) ;
V_31 -> V_35 = V_10 ;
F_158 ( V_2 , V_31 , false ) ;
}
F_136 ( & V_10 -> V_131 ) ;
F_144 ( V_2 , V_163 ) ;
F_54 ( V_162 ) ;
}
static int F_162 ( void * V_114 , struct V_125 * V_164 , struct V_125 * V_165 )
{
struct V_30 * V_166 = F_16 ( V_164 , struct V_30 , V_34 ) ;
struct V_30 * V_167 = F_16 ( V_165 , struct V_30 , V_34 ) ;
return ! ( V_166 -> V_35 < V_167 -> V_35 ||
( V_166 -> V_35 == V_167 -> V_35 &&
F_163 ( V_166 ) < F_163 ( V_167 ) ) ) ;
}
void F_164 ( struct V_168 * V_169 , bool V_163 )
{
struct V_9 * V_170 ;
struct V_14 * V_171 ;
struct V_30 * V_31 ;
F_93 ( V_126 ) ;
F_93 ( V_172 ) ;
unsigned int V_129 ;
F_95 ( & V_169 -> V_173 , & V_126 ) ;
F_165 ( NULL , & V_126 , F_162 ) ;
V_171 = NULL ;
V_170 = NULL ;
V_129 = 0 ;
while ( ! F_100 ( & V_126 ) ) {
V_31 = F_166 ( V_126 . V_95 ) ;
F_98 ( & V_31 -> V_34 ) ;
F_89 ( ! V_31 -> V_15 ) ;
if ( V_31 -> V_35 != V_170 ) {
if ( V_170 ) {
F_160 ( V_171 , V_170 ,
& V_172 , V_129 ,
V_163 ) ;
}
V_170 = V_31 -> V_35 ;
V_171 = V_31 -> V_15 ;
V_129 = 0 ;
}
V_129 ++ ;
F_104 ( & V_31 -> V_34 , & V_172 ) ;
}
if ( V_170 ) {
F_160 ( V_171 , V_170 , & V_172 , V_129 ,
V_163 ) ;
}
}
static void F_167 ( struct V_30 * V_31 , struct V_119 * V_119 )
{
F_168 ( V_31 , V_119 ) ;
if ( F_169 ( V_31 ) )
F_170 ( V_31 , 1 ) ;
}
static inline bool F_171 ( struct V_1 * V_2 )
{
return ( V_2 -> V_88 & V_174 ) &&
! F_172 ( V_2 -> V_132 ) ;
}
static inline bool F_173 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_30 * V_31 , struct V_119 * V_119 )
{
if ( ! F_171 ( V_2 ) ) {
F_167 ( V_31 , V_119 ) ;
F_134 ( & V_10 -> V_131 ) ;
V_175:
F_158 ( V_2 , V_31 , false ) ;
F_136 ( & V_10 -> V_131 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_132 ;
F_134 ( & V_10 -> V_131 ) ;
if ( ! F_126 ( V_15 , V_10 , V_119 ) ) {
F_167 ( V_31 , V_119 ) ;
goto V_175;
}
F_136 ( & V_10 -> V_131 ) ;
F_55 ( V_2 , V_10 , V_31 ) ;
return true ;
}
}
static struct V_30 * F_174 ( struct V_14 * V_15 ,
struct V_119 * V_119 ,
struct V_176 * V_64 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_30 * V_31 ;
int V_65 = F_175 ( V_119 ) ;
struct V_63 V_72 ;
if ( F_63 ( F_9 ( V_15 , V_177 ) ) ) {
F_176 ( V_119 , - V_100 ) ;
return NULL ;
}
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_10 -> V_37 ) ;
if ( F_44 ( V_119 -> V_178 ) )
V_65 |= V_179 ;
F_177 ( V_15 , V_119 , V_65 ) ;
F_52 ( & V_72 , V_15 , V_180 , false , V_10 ,
V_2 ) ;
V_31 = F_45 ( & V_72 , V_65 ) ;
if ( F_63 ( ! V_31 ) ) {
F_53 ( V_2 ) ;
F_54 ( V_10 ) ;
F_178 ( V_15 , V_119 , V_65 ) ;
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_10 -> V_37 ) ;
F_52 ( & V_72 , V_15 ,
V_19 | V_180 , false , V_10 , V_2 ) ;
V_31 = F_45 ( & V_72 , V_65 ) ;
V_10 = V_72 . V_10 ;
V_2 = V_72 . V_2 ;
}
V_2 -> V_135 ++ ;
V_64 -> V_2 = V_2 ;
V_64 -> V_10 = V_10 ;
return V_31 ;
}
static void F_179 ( struct V_14 * V_15 , struct V_119 * V_119 )
{
const int V_181 = F_44 ( V_119 -> V_178 ) ;
const int V_182 = V_119 -> V_178 & ( V_183 | V_184 ) ;
struct V_176 V_64 ;
struct V_30 * V_31 ;
F_180 ( V_15 , & V_119 ) ;
if ( F_181 ( V_119 ) && F_182 ( V_119 ) ) {
F_176 ( V_119 , - V_100 ) ;
return;
}
V_31 = F_174 ( V_15 , V_119 , & V_64 ) ;
if ( F_63 ( ! V_31 ) )
return;
if ( F_63 ( V_182 ) ) {
F_167 ( V_31 , V_119 ) ;
F_183 ( V_31 ) ;
goto V_161;
}
if ( V_181 && ! ( V_64 . V_2 -> V_88 & V_185 ) ) {
struct V_141 V_142 = {
. V_31 = V_31 ,
. V_126 = NULL ,
. V_143 = 1
} ;
int V_17 ;
F_167 ( V_31 , V_119 ) ;
V_17 = V_15 -> V_73 -> V_144 ( V_64 . V_2 , & V_142 ) ;
if ( V_17 == V_145 )
goto V_186;
else {
F_85 ( V_31 ) ;
if ( V_17 == V_147 ) {
V_31 -> V_50 = - V_100 ;
F_65 ( V_31 , V_31 -> V_50 ) ;
goto V_186;
}
}
}
if ( ! F_173 ( V_64 . V_2 , V_64 . V_10 , V_31 , V_119 ) ) {
V_161:
F_144 ( V_64 . V_2 , ! V_181 || V_182 ) ;
}
V_186:
F_54 ( V_64 . V_10 ) ;
}
static void F_184 ( struct V_14 * V_15 , struct V_119 * V_119 )
{
const int V_181 = F_44 ( V_119 -> V_178 ) ;
const int V_182 = V_119 -> V_178 & ( V_183 | V_184 ) ;
unsigned int V_187 , V_188 = 0 ;
struct V_176 V_64 ;
struct V_30 * V_31 ;
V_187 = ! V_182 && ! V_181 ;
F_180 ( V_15 , & V_119 ) ;
if ( F_181 ( V_119 ) && F_182 ( V_119 ) ) {
F_176 ( V_119 , - V_100 ) ;
return;
}
if ( V_187 && ! F_172 ( V_15 ) &&
F_185 ( V_15 , V_119 , & V_188 ) )
return;
V_31 = F_174 ( V_15 , V_119 , & V_64 ) ;
if ( F_63 ( ! V_31 ) )
return;
if ( F_63 ( V_182 ) ) {
F_167 ( V_31 , V_119 ) ;
F_183 ( V_31 ) ;
goto V_161;
}
if ( V_187 ) {
struct V_168 * V_169 = V_189 -> V_169 ;
if ( V_169 ) {
F_167 ( V_31 , V_119 ) ;
if ( F_100 ( & V_169 -> V_173 ) )
F_186 ( V_15 ) ;
else if ( V_188 >= V_190 ) {
F_187 ( V_169 , false ) ;
F_186 ( V_15 ) ;
}
F_104 ( & V_31 -> V_34 , & V_169 -> V_173 ) ;
F_54 ( V_64 . V_10 ) ;
return;
}
}
if ( ! F_173 ( V_64 . V_2 , V_64 . V_10 , V_31 , V_119 ) ) {
V_161:
F_144 ( V_64 . V_2 , ! V_181 || V_182 ) ;
}
F_54 ( V_64 . V_10 ) ;
}
struct V_1 * F_188 ( struct V_14 * V_15 , const int V_37 )
{
return V_15 -> V_191 [ V_15 -> V_192 [ V_37 ] ] ;
}
static void F_189 ( struct V_193 * V_194 ,
struct V_105 * V_29 , unsigned int V_195 )
{
struct V_196 * V_196 ;
if ( V_29 -> V_68 && V_194 -> V_108 -> V_197 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_198 ; V_3 ++ ) {
if ( ! V_29 -> V_68 [ V_3 ] )
continue;
V_194 -> V_108 -> V_197 ( V_194 -> V_199 , V_29 -> V_68 [ V_3 ] ,
V_195 , V_3 ) ;
V_29 -> V_68 [ V_3 ] = NULL ;
}
}
while ( ! F_100 ( & V_29 -> V_200 ) ) {
V_196 = F_110 ( & V_29 -> V_200 , struct V_196 , V_201 ) ;
F_98 ( & V_196 -> V_201 ) ;
F_190 ( V_196 , V_196 -> V_202 ) ;
}
F_191 ( V_29 -> V_68 ) ;
F_192 ( V_29 ) ;
}
static T_2 F_193 ( unsigned int V_203 )
{
return ( T_2 ) V_204 << V_203 ;
}
static struct V_105 * F_194 ( struct V_193 * V_194 ,
unsigned int V_195 )
{
struct V_105 * V_29 ;
unsigned int V_3 , V_205 , V_206 , V_207 = 4 ;
T_2 V_208 , V_209 ;
V_29 = F_195 ( V_194 -> V_210 , V_194 -> V_211 ,
V_194 -> V_212 ,
F_196 ( V_194 -> V_88 ) ) ;
if ( ! V_29 )
return NULL ;
F_38 ( & V_29 -> V_200 ) ;
V_29 -> V_68 = F_197 ( V_194 -> V_210 * sizeof( struct V_30 * ) ,
V_177 | V_213 | V_214 ,
V_194 -> V_212 ) ;
if ( ! V_29 -> V_68 ) {
F_192 ( V_29 ) ;
return NULL ;
}
V_208 = F_198 ( sizeof( struct V_30 ) + V_194 -> V_215 ,
F_199 () ) ;
V_209 = V_208 * V_194 -> V_210 ;
for ( V_3 = 0 ; V_3 < V_194 -> V_210 ; ) {
int V_216 = V_207 ;
struct V_196 * V_196 ;
int V_217 ;
void * V_218 ;
while ( V_209 < F_193 ( V_216 - 1 ) && V_216 )
V_216 -- ;
do {
V_196 = F_200 ( V_194 -> V_212 ,
V_177 | V_213 | V_214 | V_219 ,
V_216 ) ;
if ( V_196 )
break;
if ( ! V_216 -- )
break;
if ( F_193 ( V_216 ) < V_208 )
break;
} while ( 1 );
if ( ! V_196 )
goto V_220;
V_196 -> V_202 = V_216 ;
F_104 ( & V_196 -> V_201 , & V_29 -> V_200 ) ;
V_218 = F_201 ( V_196 ) ;
V_206 = F_193 ( V_216 ) / V_208 ;
V_217 = F_202 ( V_206 , V_194 -> V_210 - V_3 ) ;
V_209 -= V_217 * V_208 ;
for ( V_205 = 0 ; V_205 < V_217 ; V_205 ++ ) {
V_29 -> V_68 [ V_3 ] = V_218 ;
if ( V_194 -> V_108 -> V_221 ) {
if ( V_194 -> V_108 -> V_221 ( V_194 -> V_199 ,
V_29 -> V_68 [ V_3 ] , V_195 , V_3 ,
V_194 -> V_212 ) ) {
V_29 -> V_68 [ V_3 ] = NULL ;
goto V_220;
}
}
V_218 += V_208 ;
V_3 ++ ;
}
}
return V_29 ;
V_220:
F_189 ( V_194 , V_29 , V_195 ) ;
return NULL ;
}
static void F_203 ( struct V_222 * V_223 )
{
F_191 ( V_223 -> V_6 ) ;
}
static int F_204 ( struct V_222 * V_223 , int V_224 )
{
unsigned int V_225 = 8 , V_226 , V_227 , V_3 ;
V_223 -> V_12 = V_225 ;
V_227 = F_205 ( V_155 , V_225 ) / V_225 ;
V_223 -> V_6 = F_197 ( V_227 * sizeof( struct V_8 ) ,
V_177 , V_224 ) ;
if ( ! V_223 -> V_6 )
return - V_228 ;
V_226 = V_155 ;
for ( V_3 = 0 ; V_3 < V_227 ; V_3 ++ ) {
V_223 -> V_6 [ V_3 ] . V_129 = F_202 ( V_226 , V_223 -> V_12 ) ;
V_226 -= V_223 -> V_6 [ V_3 ] . V_129 ;
}
return 0 ;
}
static int F_206 ( struct V_1 * V_2 , int V_37 )
{
struct V_14 * V_15 = V_2 -> V_132 ;
struct V_9 * V_10 ;
F_93 ( V_229 ) ;
V_10 = F_207 ( V_15 , V_37 ) ;
F_134 ( & V_10 -> V_131 ) ;
if ( ! F_100 ( & V_10 -> V_94 ) ) {
F_95 ( & V_10 -> V_94 , & V_229 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_136 ( & V_10 -> V_131 ) ;
if ( F_100 ( & V_229 ) )
return V_230 ;
V_10 = F_51 ( V_15 ) ;
F_134 ( & V_10 -> V_131 ) ;
while ( ! F_100 ( & V_229 ) ) {
struct V_30 * V_31 ;
V_31 = F_110 ( & V_229 , struct V_30 , V_34 ) ;
V_31 -> V_35 = V_10 ;
F_208 ( & V_31 -> V_34 , & V_10 -> V_94 ) ;
}
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_10 -> V_37 ) ;
F_3 ( V_2 , V_10 ) ;
F_136 ( & V_10 -> V_131 ) ;
F_144 ( V_2 , true ) ;
F_54 ( V_10 ) ;
return V_230 ;
}
static int F_209 ( void * V_64 , unsigned long V_231 ,
unsigned int V_37 )
{
struct V_1 * V_2 = V_64 ;
if ( V_231 == V_232 || V_231 == V_233 )
return F_206 ( V_2 , V_37 ) ;
return V_230 ;
}
static void F_210 ( struct V_14 * V_15 ,
struct V_193 * V_194 ,
struct V_1 * V_2 , unsigned int V_195 )
{
unsigned V_234 = V_194 -> V_210 ;
F_125 ( V_2 ) ;
if ( V_194 -> V_108 -> V_197 )
V_194 -> V_108 -> V_197 ( V_194 -> V_199 ,
V_2 -> V_102 -> V_104 , V_195 ,
V_234 + V_195 ) ;
if ( V_194 -> V_108 -> V_235 )
V_194 -> V_108 -> V_235 ( V_2 , V_195 ) ;
F_211 ( & V_2 -> V_236 ) ;
F_212 ( V_2 -> V_102 ) ;
F_203 ( & V_2 -> V_4 ) ;
}
static void F_213 ( struct V_14 * V_15 ,
struct V_193 * V_194 , int V_237 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i) {
if ( V_3 == V_237 )
break;
F_210 ( V_15 , V_194 , V_2 , V_3 ) ;
}
}
static void F_214 ( struct V_14 * V_15 ,
struct V_193 * V_194 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i)
F_215 ( V_2 -> V_136 ) ;
}
static int F_216 ( struct V_14 * V_15 ,
struct V_193 * V_194 ,
struct V_1 * V_2 , unsigned V_195 )
{
int V_224 ;
unsigned V_234 = V_194 -> V_210 ;
V_224 = V_2 -> V_212 ;
if ( V_224 == V_238 )
V_224 = V_2 -> V_212 = V_194 -> V_212 ;
F_217 ( & V_2 -> V_158 , F_154 ) ;
F_217 ( & V_2 -> V_159 , F_155 ) ;
F_218 ( & V_2 -> V_131 ) ;
F_38 ( & V_2 -> V_140 ) ;
V_2 -> V_132 = V_15 ;
V_2 -> V_239 = V_195 ;
V_2 -> V_88 = V_194 -> V_88 ;
F_219 ( & V_2 -> V_236 ,
F_209 , V_2 ) ;
F_220 ( & V_2 -> V_236 ) ;
V_2 -> V_29 = V_194 -> V_29 [ V_195 ] ;
V_2 -> V_130 = F_221 ( V_155 * sizeof( void * ) ,
V_177 , V_224 ) ;
if ( ! V_2 -> V_130 )
goto V_240;
if ( F_204 ( & V_2 -> V_4 , V_224 ) )
goto V_241;
V_2 -> V_242 = 0 ;
if ( V_194 -> V_108 -> V_243 &&
V_194 -> V_108 -> V_243 ( V_2 , V_194 -> V_199 , V_195 ) )
goto V_244;
V_2 -> V_102 = F_222 ( V_15 , V_2 -> V_212 , V_194 -> V_215 ) ;
if ( ! V_2 -> V_102 )
goto V_235;
if ( V_194 -> V_108 -> V_221 &&
V_194 -> V_108 -> V_221 ( V_194 -> V_199 ,
V_2 -> V_102 -> V_104 , V_195 ,
V_234 + V_195 , V_224 ) )
goto V_245;
return 0 ;
V_245:
F_191 ( V_2 -> V_102 ) ;
V_235:
if ( V_194 -> V_108 -> V_235 )
V_194 -> V_108 -> V_235 ( V_2 , V_195 ) ;
V_244:
F_203 ( & V_2 -> V_4 ) ;
V_241:
F_191 ( V_2 -> V_130 ) ;
V_240:
F_211 ( & V_2 -> V_236 ) ;
return - 1 ;
}
static int F_223 ( struct V_14 * V_15 ,
struct V_193 * V_194 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i) {
if ( F_216 ( V_15 , V_194 , V_2 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_151 )
return 0 ;
F_213 ( V_15 , V_194 , V_3 ) ;
return 1 ;
}
static void F_224 ( struct V_14 * V_15 ,
unsigned int V_151 )
{
unsigned int V_3 ;
F_225 (i) {
struct V_9 * V_246 = F_226 ( V_15 -> V_247 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_37 = V_3 ;
F_218 ( & V_246 -> V_131 ) ;
F_38 ( & V_246 -> V_94 ) ;
V_246 -> V_132 = V_15 ;
if ( ! F_73 ( V_3 ) )
continue;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_3 ) ;
if ( V_151 > 1 && V_2 -> V_212 == V_238 )
V_2 -> V_212 = F_227 ( V_3 ) ;
}
}
static void F_228 ( struct V_14 * V_15 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_193 * V_194 = V_15 -> V_248 ;
F_31 (q, hctx, i) {
F_229 ( V_2 -> V_136 ) ;
V_2 -> V_242 = 0 ;
}
F_230 (q, ctx, i) {
if ( ! F_73 ( V_3 ) )
continue;
V_2 = V_15 -> V_73 -> V_74 ( V_15 , V_3 ) ;
F_231 ( V_3 , V_2 -> V_136 ) ;
V_10 -> V_11 = V_2 -> V_242 ;
V_2 -> V_130 [ V_2 -> V_242 ++ ] = V_10 ;
}
F_31 (q, hctx, i) {
struct V_222 * V_6 = & V_2 -> V_4 ;
if ( ! V_2 -> V_242 ) {
if ( V_194 -> V_29 [ V_3 ] ) {
F_189 ( V_194 , V_194 -> V_29 [ V_3 ] , V_3 ) ;
V_194 -> V_29 [ V_3 ] = NULL ;
}
V_2 -> V_29 = NULL ;
continue;
}
if ( ! V_194 -> V_29 [ V_3 ] )
V_194 -> V_29 [ V_3 ] = F_194 ( V_194 , V_3 ) ;
V_2 -> V_29 = V_194 -> V_29 [ V_3 ] ;
F_137 ( ! V_2 -> V_29 ) ;
V_6 -> V_5 = F_232 ( V_2 -> V_242 , V_6 -> V_12 ) ;
V_2 -> V_154 = F_147 ( V_2 -> V_136 ) ;
V_2 -> V_153 = V_156 ;
}
}
static void F_233 ( struct V_193 * V_194 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
bool V_81 ;
int V_3 ;
if ( V_194 -> V_249 . V_95 == V_194 -> V_249 . V_148 )
V_81 = false ;
else
V_81 = true ;
F_234 (q, &set->tag_list, tag_set_list) {
F_26 ( V_15 ) ;
F_31 (q, hctx, i) {
if ( V_81 )
V_2 -> V_88 |= V_250 ;
else
V_2 -> V_88 &= ~ V_250 ;
}
F_27 ( V_15 ) ;
}
}
static void F_235 ( struct V_14 * V_15 )
{
struct V_193 * V_194 = V_15 -> V_248 ;
F_236 ( & V_194 -> V_251 ) ;
F_98 ( & V_15 -> V_252 ) ;
F_233 ( V_194 ) ;
F_237 ( & V_194 -> V_251 ) ;
}
static void F_238 ( struct V_193 * V_194 ,
struct V_14 * V_15 )
{
V_15 -> V_248 = V_194 ;
F_236 ( & V_194 -> V_251 ) ;
F_104 ( & V_15 -> V_252 , & V_194 -> V_249 ) ;
F_233 ( V_194 ) ;
F_237 ( & V_194 -> V_251 ) ;
}
void F_239 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i) {
if ( ! V_2 )
continue;
F_191 ( V_2 -> V_130 ) ;
F_191 ( V_2 ) ;
}
F_191 ( V_15 -> V_191 ) ;
F_240 ( V_15 -> V_247 ) ;
}
struct V_14 * F_241 ( struct V_193 * V_194 )
{
struct V_14 * V_253 , * V_15 ;
V_253 = F_242 ( V_177 , V_194 -> V_212 ) ;
if ( ! V_253 )
return F_50 ( - V_228 ) ;
V_15 = F_243 ( V_194 , V_253 ) ;
if ( F_244 ( V_15 ) )
F_245 ( V_253 ) ;
return V_15 ;
}
struct V_14 * F_243 ( struct V_193 * V_194 ,
struct V_14 * V_15 )
{
struct V_1 * * V_254 ;
struct V_9 T_3 * V_10 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_246 ( struct V_9 ) ;
if ( ! V_10 )
return F_50 ( - V_228 ) ;
V_254 = F_221 ( V_194 -> V_151 * sizeof( * V_254 ) , V_177 ,
V_194 -> V_212 ) ;
if ( ! V_254 )
goto V_255;
V_6 = F_247 ( V_194 ) ;
if ( ! V_6 )
goto V_256;
for ( V_3 = 0 ; V_3 < V_194 -> V_151 ; V_3 ++ ) {
int V_224 = F_248 ( V_6 , V_3 ) ;
V_254 [ V_3 ] = F_197 ( sizeof( struct V_1 ) ,
V_177 , V_224 ) ;
if ( ! V_254 [ V_3 ] )
goto V_257;
if ( ! F_249 ( & V_254 [ V_3 ] -> V_136 , V_177 ,
V_224 ) )
goto V_257;
F_250 ( & V_254 [ V_3 ] -> V_70 , 0 ) ;
V_254 [ V_3 ] -> V_212 = V_224 ;
V_254 [ V_3 ] -> V_239 = V_3 ;
}
if ( F_251 ( & V_15 -> V_18 , F_15 ,
V_258 , V_177 ) )
goto V_257;
F_252 ( & V_15 -> V_58 , F_120 , ( unsigned long ) V_15 ) ;
F_253 ( V_15 , V_194 -> V_58 ? V_194 -> V_58 : 30000 ) ;
V_15 -> V_259 = V_155 ;
V_15 -> V_151 = V_194 -> V_151 ;
V_15 -> V_192 = V_6 ;
V_15 -> V_247 = V_10 ;
V_15 -> V_191 = V_254 ;
V_15 -> V_73 = V_194 -> V_108 ;
V_15 -> V_83 |= V_260 ;
if ( ! ( V_194 -> V_88 & V_261 ) )
V_15 -> V_83 |= 1 << V_262 ;
V_15 -> V_263 = V_264 ;
F_254 ( & V_15 -> V_93 , F_92 ) ;
F_38 ( & V_15 -> V_97 ) ;
F_218 ( & V_15 -> V_96 ) ;
if ( V_15 -> V_151 > 1 )
F_255 ( V_15 , F_179 ) ;
else
F_255 ( V_15 , F_184 ) ;
V_15 -> V_265 = V_194 -> V_210 ;
if ( V_194 -> V_108 -> V_266 )
F_256 ( V_15 , V_194 -> V_108 -> V_266 ) ;
F_224 ( V_15 , V_194 -> V_151 ) ;
if ( F_223 ( V_15 , V_194 ) )
goto V_257;
F_236 ( & V_267 ) ;
F_104 ( & V_15 -> V_268 , & V_269 ) ;
F_237 ( & V_267 ) ;
F_238 ( V_194 , V_15 ) ;
F_228 ( V_15 ) ;
return V_15 ;
V_257:
F_191 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_194 -> V_151 ; V_3 ++ ) {
if ( ! V_254 [ V_3 ] )
break;
F_215 ( V_254 [ V_3 ] -> V_136 ) ;
F_191 ( V_254 [ V_3 ] ) ;
}
V_256:
F_191 ( V_254 ) ;
V_255:
F_240 ( V_10 ) ;
return F_50 ( - V_228 ) ;
}
void F_257 ( struct V_14 * V_15 )
{
struct V_193 * V_194 = V_15 -> V_248 ;
F_235 ( V_15 ) ;
F_213 ( V_15 , V_194 , V_194 -> V_151 ) ;
F_214 ( V_15 , V_194 ) ;
F_258 ( & V_15 -> V_18 ) ;
F_191 ( V_15 -> V_192 ) ;
V_15 -> V_192 = NULL ;
F_236 ( & V_267 ) ;
F_98 ( & V_15 -> V_268 ) ;
F_237 ( & V_267 ) ;
}
static void F_259 ( struct V_14 * V_15 )
{
F_28 ( ! V_15 -> V_22 ) ;
F_260 ( V_15 ) ;
F_261 ( V_15 -> V_192 , V_15 -> V_151 ) ;
F_228 ( V_15 ) ;
F_262 ( V_15 ) ;
}
static int F_263 ( struct V_270 * V_271 ,
unsigned long V_231 , void * V_272 )
{
struct V_14 * V_15 ;
if ( V_231 != V_232 && V_231 != V_233 &&
V_231 != V_273 && V_231 != V_274 )
return V_230 ;
F_236 ( & V_267 ) ;
F_234 (q, &all_q_list, all_q_node)
F_18 ( V_15 ) ;
F_234 (q, &all_q_list, all_q_node) {
F_23 ( V_15 ) ;
F_264 ( & V_15 -> V_58 ) ;
}
F_234 (q, &all_q_list, all_q_node)
F_259 ( V_15 ) ;
F_234 (q, &all_q_list, all_q_node)
F_27 ( V_15 ) ;
F_237 ( & V_267 ) ;
return V_230 ;
}
static int F_265 ( struct V_193 * V_194 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_194 -> V_151 ; V_3 ++ ) {
V_194 -> V_29 [ V_3 ] = F_194 ( V_194 , V_3 ) ;
if ( ! V_194 -> V_29 [ V_3 ] )
goto V_275;
}
return 0 ;
V_275:
while ( -- V_3 >= 0 )
F_189 ( V_194 , V_194 -> V_29 [ V_3 ] , V_3 ) ;
return - V_228 ;
}
static int F_266 ( struct V_193 * V_194 )
{
unsigned int V_129 ;
int V_276 ;
V_129 = V_194 -> V_210 ;
do {
V_276 = F_265 ( V_194 ) ;
if ( ! V_276 )
break;
V_194 -> V_210 >>= 1 ;
if ( V_194 -> V_210 < V_194 -> V_211 + V_277 ) {
V_276 = - V_228 ;
break;
}
} while ( V_194 -> V_210 );
if ( ! V_194 -> V_210 || V_276 ) {
F_141 ( L_3 ) ;
return - V_228 ;
}
if ( V_129 != V_194 -> V_210 )
F_267 ( L_4 ,
V_129 , V_194 -> V_210 ) ;
return 0 ;
}
int F_268 ( struct V_193 * V_194 )
{
F_269 ( V_278 > 1 << V_279 ) ;
if ( ! V_194 -> V_151 )
return - V_280 ;
if ( ! V_194 -> V_210 )
return - V_280 ;
if ( V_194 -> V_210 < V_194 -> V_211 + V_277 )
return - V_280 ;
if ( ! V_194 -> V_108 -> V_144 || ! V_194 -> V_108 -> V_74 )
return - V_280 ;
if ( V_194 -> V_210 > V_278 ) {
F_267 ( L_5 ,
V_278 ) ;
V_194 -> V_210 = V_278 ;
}
if ( F_270 () ) {
V_194 -> V_151 = 1 ;
V_194 -> V_210 = F_202 ( 64U , V_194 -> V_210 ) ;
}
V_194 -> V_29 = F_221 ( V_194 -> V_151 *
sizeof( struct V_105 * ) ,
V_177 , V_194 -> V_212 ) ;
if ( ! V_194 -> V_29 )
return - V_228 ;
if ( F_266 ( V_194 ) )
goto V_281;
F_271 ( & V_194 -> V_251 ) ;
F_38 ( & V_194 -> V_249 ) ;
return 0 ;
V_281:
F_191 ( V_194 -> V_29 ) ;
V_194 -> V_29 = NULL ;
return - V_228 ;
}
void F_272 ( struct V_193 * V_194 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_194 -> V_151 ; V_3 ++ ) {
if ( V_194 -> V_29 [ V_3 ] )
F_189 ( V_194 , V_194 -> V_29 [ V_3 ] , V_3 ) ;
}
F_191 ( V_194 -> V_29 ) ;
V_194 -> V_29 = NULL ;
}
int F_273 ( struct V_14 * V_15 , unsigned int V_282 )
{
struct V_193 * V_194 = V_15 -> V_248 ;
struct V_1 * V_2 ;
int V_3 , V_17 ;
if ( ! V_194 || V_282 > V_194 -> V_210 )
return - V_280 ;
V_17 = 0 ;
F_31 (q, hctx, i) {
V_17 = F_274 ( V_2 -> V_29 , V_282 ) ;
if ( V_17 )
break;
}
if ( ! V_17 )
V_15 -> V_265 = V_282 ;
return V_17 ;
}
void F_275 ( void )
{
F_236 ( & V_267 ) ;
}
void F_276 ( void )
{
F_237 ( & V_267 ) ;
}
static int T_4 F_277 ( void )
{
F_278 () ;
F_279 ( F_263 , 0 ) ;
return 0 ;
}
