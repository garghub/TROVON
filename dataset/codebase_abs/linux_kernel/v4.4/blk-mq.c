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
void F_9 ( struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_10 ( & V_15 -> V_17 ) ;
if ( V_16 == 1 ) {
F_11 ( & V_15 -> V_18 ) ;
F_12 ( V_15 , false ) ;
}
}
static void F_13 ( struct V_14 * V_15 )
{
F_14 ( V_15 -> V_19 , F_15 ( & V_15 -> V_18 ) ) ;
}
void F_16 ( struct V_14 * V_15 )
{
F_9 ( V_15 ) ;
F_13 ( V_15 ) ;
}
void F_17 ( struct V_14 * V_15 )
{
F_16 ( V_15 ) ;
}
void F_18 ( struct V_14 * V_15 )
{
int V_16 ;
V_16 = F_19 ( & V_15 -> V_17 ) ;
F_20 ( V_16 < 0 ) ;
if ( ! V_16 ) {
F_21 ( & V_15 -> V_18 ) ;
F_22 ( & V_15 -> V_19 ) ;
}
}
void F_23 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i)
if ( F_25 ( V_2 ) )
F_26 ( V_2 -> V_20 , true ) ;
F_22 ( & V_15 -> V_19 ) ;
}
bool F_27 ( struct V_1 * V_2 )
{
return F_28 ( V_2 -> V_20 ) ;
}
static void F_29 ( struct V_14 * V_15 , struct V_9 * V_10 ,
struct V_21 * V_22 , unsigned int V_23 )
{
if ( F_30 ( V_15 ) )
V_23 |= V_24 ;
F_31 ( & V_22 -> V_25 ) ;
V_22 -> V_15 = V_15 ;
V_22 -> V_26 = V_10 ;
V_22 -> V_27 |= V_23 ;
V_22 -> V_28 = - 1 ;
F_32 ( & V_22 -> V_29 ) ;
F_33 ( & V_22 -> V_30 ) ;
V_22 -> V_31 = NULL ;
V_22 -> V_32 = NULL ;
V_22 -> V_33 = V_34 ;
#ifdef F_34
V_22 -> V_35 = NULL ;
F_35 ( V_22 ) ;
V_22 -> V_36 = 0 ;
#endif
V_22 -> V_37 = 0 ;
#if F_36 ( V_38 )
V_22 -> V_39 = 0 ;
#endif
V_22 -> V_40 = NULL ;
V_22 -> V_41 = 0 ;
V_22 -> V_42 = V_22 -> V_43 ;
V_22 -> V_44 = 0 ;
V_22 -> V_45 = 0 ;
V_22 -> V_46 = 0 ;
V_22 -> V_47 = NULL ;
F_31 ( & V_22 -> V_48 ) ;
V_22 -> V_49 = 0 ;
V_22 -> V_50 = NULL ;
V_22 -> V_51 = NULL ;
V_22 -> V_52 = NULL ;
V_10 -> V_53 [ F_37 ( V_23 ) ] ++ ;
}
static struct V_21 *
F_38 ( struct V_54 * V_55 , int V_56 )
{
struct V_21 * V_22 ;
unsigned int V_57 ;
V_57 = F_39 ( V_55 ) ;
if ( V_57 != V_58 ) {
V_22 = V_55 -> V_2 -> V_20 -> V_59 [ V_57 ] ;
if ( F_40 ( V_55 -> V_2 ) ) {
V_22 -> V_27 = V_60 ;
F_41 ( & V_55 -> V_2 -> V_61 ) ;
}
V_22 -> V_57 = V_57 ;
F_29 ( V_55 -> V_15 , V_55 -> V_10 , V_22 , V_56 ) ;
return V_22 ;
}
return NULL ;
}
struct V_21 * F_42 ( struct V_14 * V_15 , int V_56 , T_1 V_62 ,
bool V_63 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_54 V_64 ;
int V_65 ;
V_65 = F_43 ( V_15 , V_62 ) ;
if ( V_65 )
return F_44 ( V_65 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_46 ( & V_64 , V_15 , V_62 & ~ V_68 ,
V_63 , V_10 , V_2 ) ;
V_22 = F_38 ( & V_64 , V_56 ) ;
if ( ! V_22 && ( V_62 & V_68 ) ) {
F_47 ( V_2 ) ;
F_48 ( V_10 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_46 ( & V_64 , V_15 , V_62 , V_63 , V_10 ,
V_2 ) ;
V_22 = F_38 ( & V_64 , V_56 ) ;
V_10 = V_64 . V_10 ;
}
F_48 ( V_10 ) ;
if ( ! V_22 ) {
F_49 ( V_15 ) ;
return F_44 ( - V_69 ) ;
}
return V_22 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_21 * V_22 )
{
const int V_57 = V_22 -> V_57 ;
struct V_14 * V_15 = V_22 -> V_15 ;
if ( V_22 -> V_27 & V_60 )
F_51 ( & V_2 -> V_61 ) ;
V_22 -> V_27 = 0 ;
F_8 ( V_70 , & V_22 -> V_71 ) ;
F_52 ( V_2 , V_57 , & V_10 -> V_72 ) ;
F_49 ( V_15 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_26 ;
V_10 -> V_73 [ F_54 ( V_22 ) ] ++ ;
F_50 ( V_2 , V_10 , V_22 ) ;
}
void F_55 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = V_22 -> V_15 ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_22 -> V_26 -> V_28 ) ;
F_53 ( V_2 , V_22 ) ;
}
inline void F_56 ( struct V_21 * V_22 , int error )
{
F_57 ( V_22 ) ;
if ( V_22 -> V_50 ) {
V_22 -> V_50 ( V_22 , error ) ;
} else {
if ( F_58 ( F_59 ( V_22 ) ) )
F_55 ( V_22 -> V_52 ) ;
F_55 ( V_22 ) ;
}
}
void F_60 ( struct V_21 * V_22 , int error )
{
if ( F_61 ( V_22 , error , F_62 ( V_22 ) ) )
F_63 () ;
F_56 ( V_22 , error ) ;
}
static void F_64 ( void * V_55 )
{
struct V_21 * V_22 = V_55 ;
V_22 -> V_15 -> V_74 ( V_22 ) ;
}
static void F_65 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_26 ;
bool V_75 = false ;
int V_28 ;
if ( ! F_4 ( V_76 , & V_22 -> V_15 -> V_77 ) ) {
V_22 -> V_15 -> V_74 ( V_22 ) ;
return;
}
V_28 = F_66 () ;
if ( ! F_4 ( V_78 , & V_22 -> V_15 -> V_77 ) )
V_75 = F_67 ( V_28 , V_10 -> V_28 ) ;
if ( V_28 != V_10 -> V_28 && ! V_75 && F_68 ( V_10 -> V_28 ) ) {
V_22 -> V_79 . V_80 = F_64 ;
V_22 -> V_79 . V_81 = V_22 ;
V_22 -> V_79 . V_82 = 0 ;
F_69 ( V_10 -> V_28 , & V_22 -> V_79 ) ;
} else {
V_22 -> V_15 -> V_74 ( V_22 ) ;
}
F_70 () ;
}
static void F_71 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
if ( ! V_15 -> V_74 )
F_60 ( V_22 , V_22 -> V_41 ) ;
else
F_65 ( V_22 ) ;
}
void F_72 ( struct V_21 * V_22 , int error )
{
struct V_14 * V_15 = V_22 -> V_15 ;
if ( F_58 ( F_73 ( V_15 ) ) )
return;
if ( ! F_74 ( V_22 ) ) {
V_22 -> V_41 = error ;
F_71 ( V_22 ) ;
}
}
int F_75 ( struct V_21 * V_22 )
{
return F_4 ( V_70 , & V_22 -> V_71 ) ;
}
void F_76 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
F_77 ( V_15 , V_22 ) ;
V_22 -> V_46 = F_62 ( V_22 ) ;
if ( F_58 ( F_59 ( V_22 ) ) )
V_22 -> V_52 -> V_46 = F_62 ( V_22 -> V_52 ) ;
F_78 ( V_22 ) ;
F_79 () ;
if ( ! F_4 ( V_70 , & V_22 -> V_71 ) )
F_6 ( V_70 , & V_22 -> V_71 ) ;
if ( F_4 ( V_83 , & V_22 -> V_71 ) )
F_8 ( V_83 , & V_22 -> V_71 ) ;
if ( V_15 -> V_84 && F_62 ( V_22 ) ) {
V_22 -> V_37 ++ ;
}
}
static void F_80 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
F_81 ( V_15 , V_22 ) ;
if ( F_82 ( V_70 , & V_22 -> V_71 ) ) {
if ( V_15 -> V_84 && F_62 ( V_22 ) )
V_22 -> V_37 -- ;
}
}
void F_83 ( struct V_21 * V_22 )
{
F_80 ( V_22 ) ;
F_84 ( F_85 ( V_22 ) ) ;
F_86 ( V_22 , true ) ;
}
static void F_87 ( struct V_85 * V_86 )
{
struct V_14 * V_15 =
F_88 ( V_86 , struct V_14 , V_87 ) ;
F_89 ( V_88 ) ;
struct V_21 * V_22 , * V_89 ;
unsigned long V_82 ;
F_90 ( & V_15 -> V_90 , V_82 ) ;
F_91 ( & V_15 -> V_91 , & V_88 ) ;
F_92 ( & V_15 -> V_90 , V_82 ) ;
F_93 (rq, next, &rq_list, queuelist) {
if ( ! ( V_22 -> V_27 & V_92 ) )
continue;
V_22 -> V_27 &= ~ V_92 ;
F_94 ( & V_22 -> V_25 ) ;
F_95 ( V_22 , true , false , false ) ;
}
while ( ! F_96 ( & V_88 ) ) {
V_22 = F_97 ( V_88 . V_89 , struct V_21 , V_25 ) ;
F_94 ( & V_22 -> V_25 ) ;
F_95 ( V_22 , false , false , false ) ;
}
F_98 ( V_15 ) ;
}
void F_86 ( struct V_21 * V_22 , bool V_93 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
unsigned long V_82 ;
F_84 ( V_22 -> V_27 & V_92 ) ;
F_90 ( & V_15 -> V_90 , V_82 ) ;
if ( V_93 ) {
V_22 -> V_27 |= V_92 ;
F_99 ( & V_22 -> V_25 , & V_15 -> V_91 ) ;
} else {
F_100 ( & V_22 -> V_25 , & V_15 -> V_91 ) ;
}
F_92 ( & V_15 -> V_90 , V_82 ) ;
}
void F_101 ( struct V_14 * V_15 )
{
F_102 ( & V_15 -> V_87 ) ;
}
void F_103 ( struct V_14 * V_15 )
{
F_104 ( & V_15 -> V_87 ) ;
}
void F_105 ( struct V_14 * V_15 )
{
unsigned long V_82 ;
F_89 ( V_88 ) ;
F_90 ( & V_15 -> V_90 , V_82 ) ;
F_91 ( & V_15 -> V_91 , & V_88 ) ;
F_92 ( & V_15 -> V_90 , V_82 ) ;
while ( ! F_96 ( & V_88 ) ) {
struct V_21 * V_22 ;
V_22 = F_106 ( & V_88 , struct V_21 , V_25 ) ;
F_94 ( & V_22 -> V_25 ) ;
V_22 -> V_41 = - V_94 ;
F_60 ( V_22 , V_22 -> V_41 ) ;
}
}
struct V_21 * F_107 ( struct V_95 * V_20 , unsigned int V_57 )
{
return V_20 -> V_59 [ V_57 ] ;
}
void F_108 ( struct V_21 * V_96 , bool V_63 )
{
struct V_97 * V_98 = V_96 -> V_15 -> V_66 ;
enum V_99 V_65 = V_100 ;
if ( ! F_4 ( V_70 , & V_96 -> V_71 ) )
return;
if ( V_98 -> V_49 )
V_65 = V_98 -> V_49 ( V_96 , V_63 ) ;
switch ( V_65 ) {
case V_101 :
F_71 ( V_96 ) ;
break;
case V_100 :
F_78 ( V_96 ) ;
F_109 ( V_96 ) ;
break;
case V_102 :
break;
default:
F_110 ( V_103 L_1 , V_65 ) ;
break;
}
}
static void F_111 ( struct V_1 * V_2 ,
struct V_21 * V_22 , void * V_104 , bool V_63 )
{
struct V_105 * V_55 = V_104 ;
if ( ! F_4 ( V_70 , & V_22 -> V_71 ) ) {
if ( F_58 ( F_112 ( V_22 -> V_15 ) ) )
F_72 ( V_22 , - V_94 ) ;
return;
}
if ( V_22 -> V_27 & V_106 )
return;
if ( F_113 ( V_34 , V_22 -> V_107 ) ) {
if ( ! F_74 ( V_22 ) )
F_108 ( V_22 , V_63 ) ;
} else if ( ! V_55 -> V_108 || F_114 ( V_55 -> V_89 , V_22 -> V_107 ) ) {
V_55 -> V_89 = V_22 -> V_107 ;
V_55 -> V_108 = 1 ;
}
}
static void F_115 ( unsigned long V_104 )
{
struct V_14 * V_15 = (struct V_14 * ) V_104 ;
struct V_105 V_55 = {
. V_89 = 0 ,
. V_108 = 0 ,
} ;
int V_3 ;
F_116 ( V_15 , F_111 , & V_55 ) ;
if ( V_55 . V_108 ) {
V_55 . V_89 = F_117 ( F_118 ( V_55 . V_89 ) ) ;
F_119 ( & V_15 -> V_49 , V_55 . V_89 ) ;
} else {
struct V_1 * V_2 ;
F_24 (q, hctx, i) {
if ( F_25 ( V_2 ) )
F_120 ( V_2 ) ;
}
}
}
static bool F_121 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_109 * V_109 )
{
struct V_21 * V_22 ;
int V_110 = 8 ;
F_122 (rq, &ctx->rq_list, queuelist) {
int V_111 ;
if ( ! V_110 -- )
break;
if ( ! F_123 ( V_22 , V_109 ) )
continue;
V_111 = F_124 ( V_22 , V_109 ) ;
if ( V_111 == V_112 ) {
if ( F_125 ( V_15 , V_22 , V_109 ) ) {
V_10 -> V_113 ++ ;
return true ;
}
break;
} else if ( V_111 == V_114 ) {
if ( F_126 ( V_15 , V_22 , V_109 ) ) {
V_10 -> V_113 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_127 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
struct V_9 * V_10 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_8 * V_13 = & V_2 -> V_4 . V_6 [ V_3 ] ;
unsigned int V_117 , V_118 ;
if ( ! V_13 -> V_7 )
continue;
V_118 = 0 ;
V_117 = V_3 * V_2 -> V_4 . V_12 ;
do {
V_118 = F_128 ( & V_13 -> V_7 , V_13 -> V_119 , V_118 ) ;
if ( V_118 >= V_13 -> V_119 )
break;
V_10 = V_2 -> V_120 [ V_118 + V_117 ] ;
F_8 ( V_118 , & V_13 -> V_7 ) ;
F_129 ( & V_10 -> V_121 ) ;
F_130 ( & V_10 -> V_88 , V_116 ) ;
F_131 ( & V_10 -> V_121 ) ;
V_118 ++ ;
} while ( 1 );
}
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_122 ;
struct V_21 * V_22 ;
F_89 ( V_88 ) ;
F_89 ( V_123 ) ;
struct V_115 * V_124 ;
int V_125 ;
F_132 ( ! F_133 ( F_134 () , V_2 -> V_126 ) ) ;
if ( F_58 ( F_4 ( V_127 , & V_2 -> V_128 ) ) )
return;
V_2 -> V_129 ++ ;
F_127 ( V_2 , & V_88 ) ;
if ( ! F_135 ( & V_2 -> V_130 ) ) {
F_129 ( & V_2 -> V_121 ) ;
if ( ! F_96 ( & V_2 -> V_130 ) )
F_91 ( & V_2 -> V_130 , & V_88 ) ;
F_131 ( & V_2 -> V_121 ) ;
}
V_124 = NULL ;
V_125 = 0 ;
while ( ! F_96 ( & V_88 ) ) {
struct V_131 V_132 ;
int V_65 ;
V_22 = F_106 ( & V_88 , struct V_21 , V_25 ) ;
F_94 ( & V_22 -> V_25 ) ;
V_132 . V_22 = V_22 ;
V_132 . V_116 = V_124 ;
V_132 . V_133 = F_96 ( & V_88 ) ;
V_65 = V_15 -> V_66 -> V_134 ( V_2 , & V_132 ) ;
switch ( V_65 ) {
case V_135 :
V_125 ++ ;
continue;
case V_136 :
F_99 ( & V_22 -> V_25 , & V_88 ) ;
F_80 ( V_22 ) ;
break;
default:
F_136 ( L_2 , V_65 ) ;
case V_137 :
V_22 -> V_41 = - V_94 ;
F_60 ( V_22 , V_22 -> V_41 ) ;
break;
}
if ( V_65 == V_136 )
break;
if ( ! V_124 && V_88 . V_89 != V_88 . V_138 )
V_124 = & V_123 ;
}
if ( ! V_125 )
V_2 -> V_139 [ 0 ] ++ ;
else if ( V_125 < ( 1 << ( V_140 - 1 ) ) )
V_2 -> V_139 [ F_137 ( V_125 ) + 1 ] ++ ;
if ( ! F_96 ( & V_88 ) ) {
F_129 ( & V_2 -> V_121 ) ;
F_138 ( & V_88 , & V_2 -> V_130 ) ;
F_131 ( & V_2 -> V_121 ) ;
F_139 ( V_2 , true ) ;
}
}
static int F_140 ( struct V_1 * V_2 )
{
if ( V_2 -> V_122 -> V_141 == 1 )
return V_142 ;
if ( -- V_2 -> V_143 <= 0 ) {
int V_28 = V_2 -> V_144 , V_144 ;
V_144 = F_141 ( V_2 -> V_144 , V_2 -> V_126 ) ;
if ( V_144 >= V_145 )
V_144 = F_142 ( V_2 -> V_126 ) ;
V_2 -> V_144 = V_144 ;
V_2 -> V_143 = V_146 ;
return V_28 ;
}
return V_2 -> V_144 ;
}
void F_139 ( struct V_1 * V_2 , bool V_147 )
{
if ( F_58 ( F_4 ( V_127 , & V_2 -> V_128 ) ||
! F_25 ( V_2 ) ) )
return;
if ( ! V_147 ) {
int V_28 = F_66 () ;
if ( F_133 ( V_28 , V_2 -> V_126 ) ) {
F_47 ( V_2 ) ;
F_70 () ;
return;
}
F_70 () ;
}
F_143 ( F_140 ( V_2 ) ,
& V_2 -> V_148 , 0 ) ;
}
void F_12 ( struct V_14 * V_15 , bool V_147 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_135 ( & V_2 -> V_130 ) ) ||
F_4 ( V_127 , & V_2 -> V_128 ) )
continue;
F_139 ( V_2 , V_147 ) ;
}
}
void F_144 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_148 ) ;
F_145 ( & V_2 -> V_149 ) ;
F_6 ( V_127 , & V_2 -> V_128 ) ;
}
void F_146 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i)
F_144 ( V_2 ) ;
}
void F_147 ( struct V_1 * V_2 )
{
F_8 ( V_127 , & V_2 -> V_128 ) ;
F_139 ( V_2 , false ) ;
}
void F_98 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i)
F_147 ( V_2 ) ;
}
void F_148 ( struct V_14 * V_15 , bool V_147 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i) {
if ( ! F_4 ( V_127 , & V_2 -> V_128 ) )
continue;
F_8 ( V_127 , & V_2 -> V_128 ) ;
F_139 ( V_2 , V_147 ) ;
}
}
static void F_149 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
V_2 = F_88 ( V_86 , struct V_1 , V_148 . V_86 ) ;
F_47 ( V_2 ) ;
}
static void F_150 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
V_2 = F_88 ( V_86 , struct V_1 , V_149 . V_86 ) ;
if ( F_82 ( V_127 , & V_2 -> V_128 ) )
F_47 ( V_2 ) ;
}
void F_151 ( struct V_1 * V_2 , unsigned long V_150 )
{
if ( F_58 ( ! F_25 ( V_2 ) ) )
return;
F_143 ( F_140 ( V_2 ) ,
& V_2 -> V_149 , F_152 ( V_150 ) ) ;
}
static inline void F_153 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_21 * V_22 ,
bool V_93 )
{
F_154 ( V_2 -> V_122 , V_22 ) ;
if ( V_93 )
F_99 ( & V_22 -> V_25 , & V_10 -> V_88 ) ;
else
F_100 ( & V_22 -> V_25 , & V_10 -> V_88 ) ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_21 * V_22 , bool V_93 )
{
struct V_9 * V_10 = V_22 -> V_26 ;
F_153 ( V_2 , V_10 , V_22 , V_93 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_95 ( struct V_21 * V_22 , bool V_93 , bool V_151 ,
bool V_147 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_22 -> V_26 , * V_152 ;
V_152 = F_45 ( V_15 ) ;
if ( ! F_68 ( V_10 -> V_28 ) )
V_22 -> V_26 = V_10 = V_152 ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_129 ( & V_10 -> V_121 ) ;
F_155 ( V_2 , V_22 , V_93 ) ;
F_131 ( & V_10 -> V_121 ) ;
if ( V_151 )
F_139 ( V_2 , V_147 ) ;
F_48 ( V_152 ) ;
}
static void F_156 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_115 * V_116 ,
int V_119 ,
bool V_153 )
{
struct V_1 * V_2 ;
struct V_9 * V_152 ;
F_157 ( V_15 , V_119 , ! V_153 ) ;
V_152 = F_45 ( V_15 ) ;
if ( ! F_68 ( V_10 -> V_28 ) )
V_10 = V_152 ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_129 ( & V_10 -> V_121 ) ;
while ( ! F_96 ( V_116 ) ) {
struct V_21 * V_22 ;
V_22 = F_106 ( V_116 , struct V_21 , V_25 ) ;
F_94 ( & V_22 -> V_25 ) ;
V_22 -> V_26 = V_10 ;
F_153 ( V_2 , V_10 , V_22 , false ) ;
}
F_3 ( V_2 , V_10 ) ;
F_131 ( & V_10 -> V_121 ) ;
F_139 ( V_2 , V_153 ) ;
F_48 ( V_152 ) ;
}
static int F_158 ( void * V_104 , struct V_115 * V_154 , struct V_115 * V_155 )
{
struct V_21 * V_156 = F_88 ( V_154 , struct V_21 , V_25 ) ;
struct V_21 * V_157 = F_88 ( V_155 , struct V_21 , V_25 ) ;
return ! ( V_156 -> V_26 < V_157 -> V_26 ||
( V_156 -> V_26 == V_157 -> V_26 &&
F_159 ( V_156 ) < F_159 ( V_157 ) ) ) ;
}
void F_160 ( struct V_158 * V_159 , bool V_153 )
{
struct V_9 * V_160 ;
struct V_14 * V_161 ;
struct V_21 * V_22 ;
F_89 ( V_116 ) ;
F_89 ( V_162 ) ;
unsigned int V_119 ;
F_91 ( & V_159 -> V_163 , & V_116 ) ;
F_161 ( NULL , & V_116 , F_158 ) ;
V_161 = NULL ;
V_160 = NULL ;
V_119 = 0 ;
while ( ! F_96 ( & V_116 ) ) {
V_22 = F_162 ( V_116 . V_89 ) ;
F_94 ( & V_22 -> V_25 ) ;
F_84 ( ! V_22 -> V_15 ) ;
if ( V_22 -> V_26 != V_160 ) {
if ( V_160 ) {
F_156 ( V_161 , V_160 ,
& V_162 , V_119 ,
V_153 ) ;
}
V_160 = V_22 -> V_26 ;
V_161 = V_22 -> V_15 ;
V_119 = 0 ;
}
V_119 ++ ;
F_100 ( & V_22 -> V_25 , & V_162 ) ;
}
if ( V_160 ) {
F_156 ( V_161 , V_160 , & V_162 , V_119 ,
V_153 ) ;
}
}
static void F_163 ( struct V_21 * V_22 , struct V_109 * V_109 )
{
F_164 ( V_22 , V_109 ) ;
if ( F_165 ( V_22 ) )
F_166 ( V_22 , 1 ) ;
}
static inline bool F_167 ( struct V_1 * V_2 )
{
return ( V_2 -> V_82 & V_164 ) &&
! F_168 ( V_2 -> V_122 ) ;
}
static inline bool F_169 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_21 * V_22 , struct V_109 * V_109 )
{
if ( ! F_167 ( V_2 ) || ! F_170 ( V_109 ) ) {
F_163 ( V_22 , V_109 ) ;
F_129 ( & V_10 -> V_121 ) ;
V_165:
F_155 ( V_2 , V_22 , false ) ;
F_131 ( & V_10 -> V_121 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_122 ;
F_129 ( & V_10 -> V_121 ) ;
if ( ! F_121 ( V_15 , V_10 , V_109 ) ) {
F_163 ( V_22 , V_109 ) ;
goto V_165;
}
F_131 ( & V_10 -> V_121 ) ;
F_50 ( V_2 , V_10 , V_22 ) ;
return true ;
}
}
static struct V_21 * F_171 ( struct V_14 * V_15 ,
struct V_109 * V_109 ,
struct V_166 * V_55 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_21 * V_22 ;
int V_56 = F_172 ( V_109 ) ;
struct V_54 V_64 ;
F_173 ( V_15 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
if ( F_37 ( V_109 -> V_167 ) )
V_56 |= V_168 ;
F_174 ( V_15 , V_109 , V_56 ) ;
F_46 ( & V_64 , V_15 , V_169 , false , V_10 ,
V_2 ) ;
V_22 = F_38 ( & V_64 , V_56 ) ;
if ( F_58 ( ! V_22 ) ) {
F_47 ( V_2 ) ;
F_48 ( V_10 ) ;
F_175 ( V_15 , V_109 , V_56 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_46 ( & V_64 , V_15 ,
V_170 | V_171 , false , V_10 , V_2 ) ;
V_22 = F_38 ( & V_64 , V_56 ) ;
V_10 = V_64 . V_10 ;
V_2 = V_64 . V_2 ;
}
V_2 -> V_125 ++ ;
V_55 -> V_2 = V_2 ;
V_55 -> V_10 = V_10 ;
return V_22 ;
}
static int F_176 ( struct V_21 * V_22 , T_2 * V_172 )
{
int V_65 ;
struct V_14 * V_15 = V_22 -> V_15 ;
struct V_1 * V_2 = V_15 -> V_66 -> V_67 ( V_15 ,
V_22 -> V_26 -> V_28 ) ;
struct V_131 V_132 = {
. V_22 = V_22 ,
. V_116 = NULL ,
. V_133 = 1
} ;
T_2 V_173 = F_177 ( V_22 -> V_57 , V_2 -> V_174 ) ;
V_65 = V_15 -> V_66 -> V_134 ( V_2 , & V_132 ) ;
if ( V_65 == V_135 ) {
* V_172 = V_173 ;
return 0 ;
}
F_80 ( V_22 ) ;
if ( V_65 == V_137 ) {
* V_172 = V_175 ;
V_22 -> V_41 = - V_94 ;
F_60 ( V_22 , V_22 -> V_41 ) ;
return 0 ;
}
return - 1 ;
}
static T_2 F_178 ( struct V_14 * V_15 , struct V_109 * V_109 )
{
const int V_176 = F_37 ( V_109 -> V_167 ) ;
const int V_177 = V_109 -> V_167 & ( V_178 | V_179 ) ;
struct V_166 V_55 ;
struct V_21 * V_22 ;
unsigned int V_180 = 0 ;
struct V_158 * V_159 ;
struct V_21 * V_181 = NULL ;
T_2 V_172 ;
F_179 ( V_15 , & V_109 ) ;
if ( F_180 ( V_109 ) && F_181 ( V_109 ) ) {
F_182 ( V_109 ) ;
return V_175 ;
}
F_183 ( V_15 , & V_109 , V_15 -> V_182 ) ;
if ( ! V_177 && ! F_168 ( V_15 ) ) {
if ( F_184 ( V_15 , V_109 , & V_180 ,
& V_181 ) )
return V_175 ;
} else
V_180 = F_185 ( V_15 ) ;
V_22 = F_171 ( V_15 , V_109 , & V_55 ) ;
if ( F_58 ( ! V_22 ) )
return V_175 ;
V_172 = F_177 ( V_22 -> V_57 , V_55 . V_2 -> V_174 ) ;
if ( F_58 ( V_177 ) ) {
F_163 ( V_22 , V_109 ) ;
F_186 ( V_22 ) ;
goto V_151;
}
V_159 = V_183 -> V_159 ;
if ( ( ( V_159 && ! F_168 ( V_15 ) ) || V_176 ) &&
! ( V_55 . V_2 -> V_82 & V_184 ) ) {
struct V_21 * V_185 = NULL ;
F_163 ( V_22 , V_109 ) ;
if ( V_159 ) {
if ( V_181 && ! F_96 ( & V_159 -> V_163 ) ) {
V_185 = V_181 ;
F_94 ( & V_185 -> V_25 ) ;
}
F_100 ( & V_22 -> V_25 , & V_159 -> V_163 ) ;
} else
V_185 = V_22 ;
F_48 ( V_55 . V_10 ) ;
if ( ! V_185 )
goto V_186;
if ( ! F_176 ( V_185 , & V_172 ) )
goto V_186;
F_95 ( V_185 , false , true , true ) ;
goto V_186;
}
if ( ! F_169 ( V_55 . V_2 , V_55 . V_10 , V_22 , V_109 ) ) {
V_151:
F_139 ( V_55 . V_2 , ! V_176 || V_177 ) ;
}
F_48 ( V_55 . V_10 ) ;
V_186:
return V_172 ;
}
static T_2 F_187 ( struct V_14 * V_15 , struct V_109 * V_109 )
{
const int V_176 = F_37 ( V_109 -> V_167 ) ;
const int V_177 = V_109 -> V_167 & ( V_178 | V_179 ) ;
struct V_158 * V_159 ;
unsigned int V_180 = 0 ;
struct V_166 V_55 ;
struct V_21 * V_22 ;
T_2 V_172 ;
F_179 ( V_15 , & V_109 ) ;
if ( F_180 ( V_109 ) && F_181 ( V_109 ) ) {
F_182 ( V_109 ) ;
return V_175 ;
}
F_183 ( V_15 , & V_109 , V_15 -> V_182 ) ;
if ( ! V_177 && ! F_168 ( V_15 ) &&
F_184 ( V_15 , V_109 , & V_180 , NULL ) )
return V_175 ;
V_22 = F_171 ( V_15 , V_109 , & V_55 ) ;
if ( F_58 ( ! V_22 ) )
return V_175 ;
V_172 = F_177 ( V_22 -> V_57 , V_55 . V_2 -> V_174 ) ;
if ( F_58 ( V_177 ) ) {
F_163 ( V_22 , V_109 ) ;
F_186 ( V_22 ) ;
goto V_151;
}
V_159 = V_183 -> V_159 ;
if ( V_159 ) {
F_163 ( V_22 , V_109 ) ;
if ( ! V_180 )
F_188 ( V_15 ) ;
F_48 ( V_55 . V_10 ) ;
if ( V_180 >= V_187 ) {
F_189 ( V_159 , false ) ;
F_188 ( V_15 ) ;
}
F_100 ( & V_22 -> V_25 , & V_159 -> V_163 ) ;
return V_172 ;
}
if ( ! F_169 ( V_55 . V_2 , V_55 . V_10 , V_22 , V_109 ) ) {
V_151:
F_139 ( V_55 . V_2 , ! V_176 || V_177 ) ;
}
F_48 ( V_55 . V_10 ) ;
return V_172 ;
}
struct V_1 * F_190 ( struct V_14 * V_15 , const int V_28 )
{
return V_15 -> V_188 [ V_15 -> V_189 [ V_28 ] ] ;
}
static void F_191 ( struct V_190 * V_191 ,
struct V_95 * V_20 , unsigned int V_192 )
{
struct V_193 * V_193 ;
if ( V_20 -> V_59 && V_191 -> V_98 -> V_194 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_20 -> V_195 ; V_3 ++ ) {
if ( ! V_20 -> V_59 [ V_3 ] )
continue;
V_191 -> V_98 -> V_194 ( V_191 -> V_196 , V_20 -> V_59 [ V_3 ] ,
V_192 , V_3 ) ;
V_20 -> V_59 [ V_3 ] = NULL ;
}
}
while ( ! F_96 ( & V_20 -> V_197 ) ) {
V_193 = F_106 ( & V_20 -> V_197 , struct V_193 , V_198 ) ;
F_94 ( & V_193 -> V_198 ) ;
F_192 ( F_193 ( V_193 ) ) ;
F_194 ( V_193 , V_193 -> V_199 ) ;
}
F_195 ( V_20 -> V_59 ) ;
F_196 ( V_20 ) ;
}
static T_3 F_197 ( unsigned int V_200 )
{
return ( T_3 ) V_201 << V_200 ;
}
static struct V_95 * F_198 ( struct V_190 * V_191 ,
unsigned int V_192 )
{
struct V_95 * V_20 ;
unsigned int V_3 , V_202 , V_203 , V_204 = 4 ;
T_3 V_205 , V_206 ;
V_20 = F_199 ( V_191 -> V_207 , V_191 -> V_208 ,
V_191 -> V_209 ,
F_200 ( V_191 -> V_82 ) ) ;
if ( ! V_20 )
return NULL ;
F_31 ( & V_20 -> V_197 ) ;
V_20 -> V_59 = F_201 ( V_191 -> V_207 * sizeof( struct V_21 * ) ,
V_210 | V_211 | V_212 ,
V_191 -> V_209 ) ;
if ( ! V_20 -> V_59 ) {
F_196 ( V_20 ) ;
return NULL ;
}
V_205 = F_202 ( sizeof( struct V_21 ) + V_191 -> V_213 ,
F_203 () ) ;
V_206 = V_205 * V_191 -> V_207 ;
for ( V_3 = 0 ; V_3 < V_191 -> V_207 ; ) {
int V_214 = V_204 ;
struct V_193 * V_193 ;
int V_215 ;
void * V_216 ;
while ( V_206 < F_197 ( V_214 - 1 ) && V_214 )
V_214 -- ;
do {
V_193 = F_204 ( V_191 -> V_209 ,
V_210 | V_211 | V_212 | V_217 ,
V_214 ) ;
if ( V_193 )
break;
if ( ! V_214 -- )
break;
if ( F_197 ( V_214 ) < V_205 )
break;
} while ( 1 );
if ( ! V_193 )
goto V_218;
V_193 -> V_199 = V_214 ;
F_100 ( & V_193 -> V_198 , & V_20 -> V_197 ) ;
V_216 = F_193 ( V_193 ) ;
F_205 ( V_216 , F_197 ( V_214 ) , 1 , V_210 ) ;
V_203 = F_197 ( V_214 ) / V_205 ;
V_215 = F_206 ( V_203 , V_191 -> V_207 - V_3 ) ;
V_206 -= V_215 * V_205 ;
for ( V_202 = 0 ; V_202 < V_215 ; V_202 ++ ) {
V_20 -> V_59 [ V_3 ] = V_216 ;
if ( V_191 -> V_98 -> V_219 ) {
if ( V_191 -> V_98 -> V_219 ( V_191 -> V_196 ,
V_20 -> V_59 [ V_3 ] , V_192 , V_3 ,
V_191 -> V_209 ) ) {
V_20 -> V_59 [ V_3 ] = NULL ;
goto V_218;
}
}
V_216 += V_205 ;
V_3 ++ ;
}
}
return V_20 ;
V_218:
F_191 ( V_191 , V_20 , V_192 ) ;
return NULL ;
}
static void F_207 ( struct V_220 * V_221 )
{
F_195 ( V_221 -> V_6 ) ;
}
static int F_208 ( struct V_220 * V_221 , int V_222 )
{
unsigned int V_223 = 8 , V_224 , V_225 , V_3 ;
V_221 -> V_12 = V_223 ;
V_225 = F_209 ( V_145 , V_223 ) / V_223 ;
V_221 -> V_6 = F_201 ( V_225 * sizeof( struct V_8 ) ,
V_210 , V_222 ) ;
if ( ! V_221 -> V_6 )
return - V_226 ;
V_224 = V_145 ;
for ( V_3 = 0 ; V_3 < V_225 ; V_3 ++ ) {
V_221 -> V_6 [ V_3 ] . V_119 = F_206 ( V_224 , V_221 -> V_12 ) ;
V_224 -= V_221 -> V_6 [ V_3 ] . V_119 ;
}
return 0 ;
}
static int F_210 ( struct V_1 * V_2 , int V_28 )
{
struct V_14 * V_15 = V_2 -> V_122 ;
struct V_9 * V_10 ;
F_89 ( V_227 ) ;
V_10 = F_211 ( V_15 , V_28 ) ;
F_129 ( & V_10 -> V_121 ) ;
if ( ! F_96 ( & V_10 -> V_88 ) ) {
F_91 ( & V_10 -> V_88 , & V_227 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_131 ( & V_10 -> V_121 ) ;
if ( F_96 ( & V_227 ) )
return V_228 ;
V_10 = F_45 ( V_15 ) ;
F_129 ( & V_10 -> V_121 ) ;
while ( ! F_96 ( & V_227 ) ) {
struct V_21 * V_22 ;
V_22 = F_106 ( & V_227 , struct V_21 , V_25 ) ;
V_22 -> V_26 = V_10 ;
F_212 ( & V_22 -> V_25 , & V_10 -> V_88 ) ;
}
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_3 ( V_2 , V_10 ) ;
F_131 ( & V_10 -> V_121 ) ;
F_139 ( V_2 , true ) ;
F_48 ( V_10 ) ;
return V_228 ;
}
static int F_213 ( void * V_55 , unsigned long V_229 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_55 ;
if ( V_229 == V_230 || V_229 == V_231 )
return F_210 ( V_2 , V_28 ) ;
return V_228 ;
}
static void F_214 ( struct V_14 * V_15 ,
struct V_190 * V_191 ,
struct V_1 * V_2 , unsigned int V_192 )
{
unsigned V_232 = V_191 -> V_207 ;
F_120 ( V_2 ) ;
if ( V_191 -> V_98 -> V_194 )
V_191 -> V_98 -> V_194 ( V_191 -> V_196 ,
V_2 -> V_233 -> V_234 , V_192 ,
V_232 + V_192 ) ;
if ( V_191 -> V_98 -> V_235 )
V_191 -> V_98 -> V_235 ( V_2 , V_192 ) ;
F_215 ( & V_2 -> V_236 ) ;
F_216 ( V_2 -> V_233 ) ;
F_207 ( & V_2 -> V_4 ) ;
}
static void F_217 ( struct V_14 * V_15 ,
struct V_190 * V_191 , int V_237 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i) {
if ( V_3 == V_237 )
break;
F_214 ( V_15 , V_191 , V_2 , V_3 ) ;
}
}
static void F_218 ( struct V_14 * V_15 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i)
F_219 ( V_2 -> V_126 ) ;
}
static int F_220 ( struct V_14 * V_15 ,
struct V_190 * V_191 ,
struct V_1 * V_2 , unsigned V_192 )
{
int V_222 ;
unsigned V_232 = V_191 -> V_207 ;
V_222 = V_2 -> V_209 ;
if ( V_222 == V_238 )
V_222 = V_2 -> V_209 = V_191 -> V_209 ;
F_221 ( & V_2 -> V_148 , F_149 ) ;
F_221 ( & V_2 -> V_149 , F_150 ) ;
F_222 ( & V_2 -> V_121 ) ;
F_31 ( & V_2 -> V_130 ) ;
V_2 -> V_122 = V_15 ;
V_2 -> V_174 = V_192 ;
V_2 -> V_82 = V_191 -> V_82 & ~ V_239 ;
F_223 ( & V_2 -> V_236 ,
F_213 , V_2 ) ;
F_224 ( & V_2 -> V_236 ) ;
V_2 -> V_20 = V_191 -> V_20 [ V_192 ] ;
V_2 -> V_120 = F_225 ( V_145 * sizeof( void * ) ,
V_210 , V_222 ) ;
if ( ! V_2 -> V_120 )
goto V_240;
if ( F_208 ( & V_2 -> V_4 , V_222 ) )
goto V_241;
V_2 -> V_242 = 0 ;
if ( V_191 -> V_98 -> V_243 &&
V_191 -> V_98 -> V_243 ( V_2 , V_191 -> V_196 , V_192 ) )
goto V_244;
V_2 -> V_233 = F_226 ( V_15 , V_2 -> V_209 , V_191 -> V_213 ) ;
if ( ! V_2 -> V_233 )
goto V_235;
if ( V_191 -> V_98 -> V_219 &&
V_191 -> V_98 -> V_219 ( V_191 -> V_196 ,
V_2 -> V_233 -> V_234 , V_192 ,
V_232 + V_192 , V_222 ) )
goto V_245;
return 0 ;
V_245:
F_195 ( V_2 -> V_233 ) ;
V_235:
if ( V_191 -> V_98 -> V_235 )
V_191 -> V_98 -> V_235 ( V_2 , V_192 ) ;
V_244:
F_207 ( & V_2 -> V_4 ) ;
V_241:
F_195 ( V_2 -> V_120 ) ;
V_240:
F_215 ( & V_2 -> V_236 ) ;
return - 1 ;
}
static int F_227 ( struct V_14 * V_15 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i) {
if ( F_220 ( V_15 , V_191 , V_2 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_141 )
return 0 ;
F_217 ( V_15 , V_191 , V_3 ) ;
return 1 ;
}
static void F_228 ( struct V_14 * V_15 ,
unsigned int V_141 )
{
unsigned int V_3 ;
F_229 (i) {
struct V_9 * V_246 = F_230 ( V_15 -> V_247 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_246 , 0 , sizeof( * V_246 ) ) ;
V_246 -> V_28 = V_3 ;
F_222 ( & V_246 -> V_121 ) ;
F_31 ( & V_246 -> V_88 ) ;
V_246 -> V_122 = V_15 ;
if ( ! F_68 ( V_3 ) )
continue;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_3 ) ;
if ( V_141 > 1 && V_2 -> V_209 == V_238 )
V_2 -> V_209 = F_231 ( V_3 ) ;
}
}
static void F_232 ( struct V_14 * V_15 ,
const struct V_126 * V_248 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_190 * V_191 = V_15 -> V_249 ;
F_233 ( & V_15 -> V_250 ) ;
F_24 (q, hctx, i) {
F_234 ( V_2 -> V_126 ) ;
V_2 -> V_242 = 0 ;
}
F_235 (q, ctx, i) {
if ( ! F_133 ( V_3 , V_248 ) )
continue;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_3 ) ;
F_236 ( V_3 , V_2 -> V_126 ) ;
V_10 -> V_11 = V_2 -> V_242 ;
V_2 -> V_120 [ V_2 -> V_242 ++ ] = V_10 ;
}
F_237 ( & V_15 -> V_250 ) ;
F_24 (q, hctx, i) {
struct V_220 * V_6 = & V_2 -> V_4 ;
if ( ! V_2 -> V_242 ) {
if ( V_191 -> V_20 [ V_3 ] ) {
F_191 ( V_191 , V_191 -> V_20 [ V_3 ] , V_3 ) ;
V_191 -> V_20 [ V_3 ] = NULL ;
}
V_2 -> V_20 = NULL ;
continue;
}
if ( ! V_191 -> V_20 [ V_3 ] )
V_191 -> V_20 [ V_3 ] = F_198 ( V_191 , V_3 ) ;
V_2 -> V_20 = V_191 -> V_20 [ V_3 ] ;
F_132 ( ! V_2 -> V_20 ) ;
V_6 -> V_5 = F_238 ( V_2 -> V_242 , V_6 -> V_12 ) ;
V_2 -> V_144 = F_142 ( V_2 -> V_126 ) ;
V_2 -> V_143 = V_146 ;
}
F_235 (q, ctx, i) {
if ( ! F_133 ( V_3 , V_248 ) )
continue;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_3 ) ;
F_236 ( V_3 , V_2 -> V_20 -> V_126 ) ;
}
}
static void F_239 ( struct V_14 * V_15 , bool V_75 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i) {
if ( V_75 )
V_2 -> V_82 |= V_239 ;
else
V_2 -> V_82 &= ~ V_239 ;
}
}
static void F_240 ( struct V_190 * V_191 , bool V_75 )
{
struct V_14 * V_15 ;
F_241 (q, &set->tag_list, tag_set_list) {
F_17 ( V_15 ) ;
F_239 ( V_15 , V_75 ) ;
F_18 ( V_15 ) ;
}
}
static void F_242 ( struct V_14 * V_15 )
{
struct V_190 * V_191 = V_15 -> V_249 ;
F_233 ( & V_191 -> V_251 ) ;
F_94 ( & V_15 -> V_252 ) ;
if ( F_243 ( & V_191 -> V_253 ) ) {
V_191 -> V_82 &= ~ V_239 ;
F_240 ( V_191 , false ) ;
}
F_237 ( & V_191 -> V_251 ) ;
}
static void F_244 ( struct V_190 * V_191 ,
struct V_14 * V_15 )
{
V_15 -> V_249 = V_191 ;
F_233 ( & V_191 -> V_251 ) ;
if ( ! F_96 ( & V_191 -> V_253 ) && ! ( V_191 -> V_82 & V_239 ) ) {
V_191 -> V_82 |= V_239 ;
F_240 ( V_191 , true ) ;
}
if ( V_191 -> V_82 & V_239 )
F_239 ( V_15 , true ) ;
F_100 ( & V_15 -> V_252 , & V_191 -> V_253 ) ;
F_237 ( & V_191 -> V_251 ) ;
}
void F_245 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i) {
if ( ! V_2 )
continue;
F_195 ( V_2 -> V_120 ) ;
F_195 ( V_2 ) ;
}
F_195 ( V_15 -> V_189 ) ;
V_15 -> V_189 = NULL ;
F_195 ( V_15 -> V_188 ) ;
F_246 ( V_15 -> V_247 ) ;
}
struct V_14 * F_247 ( struct V_190 * V_191 )
{
struct V_14 * V_254 , * V_15 ;
V_254 = F_248 ( V_210 , V_191 -> V_209 ) ;
if ( ! V_254 )
return F_44 ( - V_226 ) ;
V_15 = F_249 ( V_191 , V_254 ) ;
if ( F_250 ( V_15 ) )
F_251 ( V_254 ) ;
return V_15 ;
}
struct V_14 * F_249 ( struct V_190 * V_191 ,
struct V_14 * V_15 )
{
struct V_1 * * V_255 ;
struct V_9 T_4 * V_10 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_252 ( struct V_9 ) ;
if ( ! V_10 )
return F_44 ( - V_226 ) ;
V_255 = F_225 ( V_191 -> V_141 * sizeof( * V_255 ) , V_210 ,
V_191 -> V_209 ) ;
if ( ! V_255 )
goto V_256;
V_6 = F_253 ( V_191 ) ;
if ( ! V_6 )
goto V_257;
for ( V_3 = 0 ; V_3 < V_191 -> V_141 ; V_3 ++ ) {
int V_222 = F_254 ( V_6 , V_3 ) ;
V_255 [ V_3 ] = F_201 ( sizeof( struct V_1 ) ,
V_210 , V_222 ) ;
if ( ! V_255 [ V_3 ] )
goto V_258;
if ( ! F_255 ( & V_255 [ V_3 ] -> V_126 , V_210 ,
V_222 ) )
goto V_258;
F_256 ( & V_255 [ V_3 ] -> V_61 , 0 ) ;
V_255 [ V_3 ] -> V_209 = V_222 ;
V_255 [ V_3 ] -> V_174 = V_3 ;
}
F_257 ( & V_15 -> V_49 , F_115 , ( unsigned long ) V_15 ) ;
F_258 ( V_15 , V_191 -> V_49 ? V_191 -> V_49 : 30 * V_259 ) ;
V_15 -> V_260 = V_145 ;
V_15 -> V_141 = V_191 -> V_141 ;
V_15 -> V_189 = V_6 ;
V_15 -> V_247 = V_10 ;
V_15 -> V_188 = V_255 ;
V_15 -> V_66 = V_191 -> V_98 ;
V_15 -> V_77 |= V_261 ;
if ( ! ( V_191 -> V_82 & V_262 ) )
V_15 -> V_77 |= 1 << V_263 ;
V_15 -> V_264 = V_265 ;
F_259 ( & V_15 -> V_87 , F_87 ) ;
F_31 ( & V_15 -> V_91 ) ;
F_222 ( & V_15 -> V_90 ) ;
if ( V_15 -> V_141 > 1 )
F_260 ( V_15 , F_178 ) ;
else
F_260 ( V_15 , F_187 ) ;
V_15 -> V_266 = V_191 -> V_207 ;
if ( V_191 -> V_98 -> V_267 )
F_261 ( V_15 , V_191 -> V_98 -> V_267 ) ;
F_228 ( V_15 , V_191 -> V_141 ) ;
if ( F_227 ( V_15 , V_191 ) )
goto V_258;
F_262 () ;
F_233 ( & V_268 ) ;
F_100 ( & V_15 -> V_269 , & V_270 ) ;
F_244 ( V_191 , V_15 ) ;
F_232 ( V_15 , V_271 ) ;
F_237 ( & V_268 ) ;
F_263 () ;
return V_15 ;
V_258:
F_195 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_191 -> V_141 ; V_3 ++ ) {
if ( ! V_255 [ V_3 ] )
break;
F_219 ( V_255 [ V_3 ] -> V_126 ) ;
F_195 ( V_255 [ V_3 ] ) ;
}
V_257:
F_195 ( V_255 ) ;
V_256:
F_246 ( V_10 ) ;
return F_44 ( - V_226 ) ;
}
void F_264 ( struct V_14 * V_15 )
{
struct V_190 * V_191 = V_15 -> V_249 ;
F_233 ( & V_268 ) ;
F_94 ( & V_15 -> V_269 ) ;
F_237 ( & V_268 ) ;
F_242 ( V_15 ) ;
F_217 ( V_15 , V_191 , V_191 -> V_141 ) ;
F_218 ( V_15 , V_191 ) ;
}
static void F_265 ( struct V_14 * V_15 ,
const struct V_126 * V_248 )
{
F_20 ( ! F_266 ( & V_15 -> V_17 ) ) ;
F_267 ( V_15 ) ;
F_268 ( V_15 -> V_189 , V_15 -> V_141 , V_248 ) ;
F_232 ( V_15 , V_248 ) ;
F_269 ( V_15 ) ;
}
static int F_270 ( struct V_272 * V_273 ,
unsigned long V_229 , void * V_274 )
{
struct V_14 * V_15 ;
int V_28 = ( unsigned long ) V_274 ;
static struct V_126 V_275 ;
switch ( V_229 & ~ V_276 ) {
case V_230 :
case V_277 :
F_271 ( & V_275 , V_271 ) ;
break;
case V_278 :
F_271 ( & V_275 , V_271 ) ;
F_236 ( V_28 , & V_275 ) ;
break;
default:
return V_228 ;
}
F_233 ( & V_268 ) ;
F_241 (q, &all_q_list, all_q_node)
F_9 ( V_15 ) ;
F_241 (q, &all_q_list, all_q_node) {
F_13 ( V_15 ) ;
F_272 ( & V_15 -> V_49 ) ;
}
F_241 (q, &all_q_list, all_q_node)
F_265 ( V_15 , & V_275 ) ;
F_241 (q, &all_q_list, all_q_node)
F_18 ( V_15 ) ;
F_237 ( & V_268 ) ;
return V_228 ;
}
static int F_273 ( struct V_190 * V_191 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_191 -> V_141 ; V_3 ++ ) {
V_191 -> V_20 [ V_3 ] = F_198 ( V_191 , V_3 ) ;
if ( ! V_191 -> V_20 [ V_3 ] )
goto V_279;
}
return 0 ;
V_279:
while ( -- V_3 >= 0 )
F_191 ( V_191 , V_191 -> V_20 [ V_3 ] , V_3 ) ;
return - V_226 ;
}
static int F_274 ( struct V_190 * V_191 )
{
unsigned int V_119 ;
int V_280 ;
V_119 = V_191 -> V_207 ;
do {
V_280 = F_273 ( V_191 ) ;
if ( ! V_280 )
break;
V_191 -> V_207 >>= 1 ;
if ( V_191 -> V_207 < V_191 -> V_208 + V_281 ) {
V_280 = - V_226 ;
break;
}
} while ( V_191 -> V_207 );
if ( ! V_191 -> V_207 || V_280 ) {
F_136 ( L_3 ) ;
return - V_226 ;
}
if ( V_119 != V_191 -> V_207 )
F_275 ( L_4 ,
V_119 , V_191 -> V_207 ) ;
return 0 ;
}
struct V_126 * F_276 ( struct V_95 * V_20 )
{
return V_20 -> V_126 ;
}
int F_277 ( struct V_190 * V_191 )
{
F_278 ( V_282 > 1 << V_283 ) ;
if ( ! V_191 -> V_141 )
return - V_284 ;
if ( ! V_191 -> V_207 )
return - V_284 ;
if ( V_191 -> V_207 < V_191 -> V_208 + V_281 )
return - V_284 ;
if ( ! V_191 -> V_98 -> V_134 || ! V_191 -> V_98 -> V_67 )
return - V_284 ;
if ( V_191 -> V_207 > V_282 ) {
F_275 ( L_5 ,
V_282 ) ;
V_191 -> V_207 = V_282 ;
}
if ( F_279 () ) {
V_191 -> V_141 = 1 ;
V_191 -> V_207 = F_206 ( 64U , V_191 -> V_207 ) ;
}
V_191 -> V_20 = F_225 ( V_191 -> V_141 *
sizeof( struct V_95 * ) ,
V_210 , V_191 -> V_209 ) ;
if ( ! V_191 -> V_20 )
return - V_226 ;
if ( F_274 ( V_191 ) )
goto V_285;
F_280 ( & V_191 -> V_251 ) ;
F_31 ( & V_191 -> V_253 ) ;
return 0 ;
V_285:
F_195 ( V_191 -> V_20 ) ;
V_191 -> V_20 = NULL ;
return - V_226 ;
}
void F_281 ( struct V_190 * V_191 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_191 -> V_141 ; V_3 ++ ) {
if ( V_191 -> V_20 [ V_3 ] )
F_191 ( V_191 , V_191 -> V_20 [ V_3 ] , V_3 ) ;
}
F_195 ( V_191 -> V_20 ) ;
V_191 -> V_20 = NULL ;
}
int F_282 ( struct V_14 * V_15 , unsigned int V_286 )
{
struct V_190 * V_191 = V_15 -> V_249 ;
struct V_1 * V_2 ;
int V_3 , V_65 ;
if ( ! V_191 || V_286 > V_191 -> V_207 )
return - V_284 ;
V_65 = 0 ;
F_24 (q, hctx, i) {
V_65 = F_283 ( V_2 -> V_20 , V_286 ) ;
if ( V_65 )
break;
}
if ( ! V_65 )
V_15 -> V_266 = V_286 ;
return V_65 ;
}
void F_284 ( void )
{
F_233 ( & V_268 ) ;
}
void F_285 ( void )
{
F_237 ( & V_268 ) ;
}
static int T_5 F_286 ( void )
{
F_287 () ;
F_288 ( F_270 , 0 ) ;
return 0 ;
}
