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
static int F_9 ( struct V_14 * V_15 )
{
while ( true ) {
int V_16 ;
if ( F_10 ( & V_15 -> V_17 ) )
return 0 ;
V_16 = F_11 ( V_15 -> V_18 ,
! V_15 -> V_19 || F_12 ( V_15 ) ) ;
if ( F_12 ( V_15 ) )
return - V_20 ;
if ( V_16 )
return V_16 ;
}
}
static void F_13 ( struct V_14 * V_15 )
{
F_14 ( & V_15 -> V_17 ) ;
}
static void F_15 ( struct V_21 * V_22 )
{
struct V_14 * V_15 =
F_16 ( V_22 , struct V_14 , V_17 ) ;
F_17 ( & V_15 -> V_18 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
bool V_23 ;
F_19 ( V_15 -> V_24 ) ;
V_23 = ! V_15 -> V_19 ++ ;
F_20 ( V_15 -> V_24 ) ;
if ( V_23 ) {
F_21 ( & V_15 -> V_17 ) ;
F_22 ( V_15 , false ) ;
}
}
static void F_23 ( struct V_14 * V_15 )
{
F_24 ( V_15 -> V_18 , F_25 ( & V_15 -> V_17 ) ) ;
}
void F_26 ( struct V_14 * V_15 )
{
F_18 ( V_15 ) ;
F_23 ( V_15 ) ;
}
static void F_27 ( struct V_14 * V_15 )
{
bool V_25 ;
F_19 ( V_15 -> V_24 ) ;
V_25 = ! -- V_15 -> V_19 ;
F_28 ( V_15 -> V_19 < 0 ) ;
F_20 ( V_15 -> V_24 ) ;
if ( V_25 ) {
F_29 ( & V_15 -> V_17 ) ;
F_17 ( & V_15 -> V_18 ) ;
}
}
bool F_30 ( struct V_1 * V_2 )
{
return F_31 ( V_2 -> V_26 ) ;
}
static void F_32 ( struct V_14 * V_15 , struct V_9 * V_10 ,
struct V_27 * V_28 , unsigned int V_29 )
{
if ( F_33 ( V_15 ) )
V_29 |= V_30 ;
F_34 ( & V_28 -> V_31 ) ;
V_28 -> V_15 = V_15 ;
V_28 -> V_32 = V_10 ;
V_28 -> V_33 |= V_29 ;
V_28 -> V_34 = - 1 ;
F_35 ( & V_28 -> V_35 ) ;
F_36 ( & V_28 -> V_36 ) ;
V_28 -> V_37 = NULL ;
V_28 -> V_38 = NULL ;
V_28 -> V_39 = V_40 ;
#ifdef F_37
V_28 -> V_41 = NULL ;
F_38 ( V_28 ) ;
V_28 -> V_42 = 0 ;
#endif
V_28 -> V_43 = 0 ;
#if F_39 ( V_44 )
V_28 -> V_45 = 0 ;
#endif
V_28 -> V_46 = NULL ;
V_28 -> V_47 = 0 ;
V_28 -> V_48 = V_28 -> V_49 ;
V_28 -> V_50 = 0 ;
V_28 -> V_51 = 0 ;
V_28 -> V_52 = 0 ;
V_28 -> V_53 = NULL ;
F_34 ( & V_28 -> V_54 ) ;
V_28 -> V_55 = 0 ;
V_28 -> V_56 = NULL ;
V_28 -> V_57 = NULL ;
V_28 -> V_58 = NULL ;
V_10 -> V_59 [ F_40 ( V_29 ) ] ++ ;
}
static struct V_27 *
F_41 ( struct V_60 * V_61 , int V_62 )
{
struct V_27 * V_28 ;
unsigned int V_63 ;
V_63 = F_42 ( V_61 ) ;
if ( V_63 != V_64 ) {
V_28 = V_61 -> V_2 -> V_26 -> V_65 [ V_63 ] ;
if ( F_43 ( V_61 -> V_2 ) ) {
V_28 -> V_33 = V_66 ;
F_44 ( & V_61 -> V_2 -> V_67 ) ;
}
V_28 -> V_63 = V_63 ;
F_32 ( V_61 -> V_15 , V_61 -> V_10 , V_28 , V_62 ) ;
return V_28 ;
}
return NULL ;
}
struct V_27 * F_45 ( struct V_14 * V_15 , int V_62 , T_1 V_68 ,
bool V_69 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_60 V_70 ;
int V_16 ;
V_16 = F_9 ( V_15 ) ;
if ( V_16 )
return F_46 ( V_16 ) ;
V_10 = F_47 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_48 ( & V_70 , V_15 , V_68 & ~ V_73 ,
V_69 , V_10 , V_2 ) ;
V_28 = F_41 ( & V_70 , V_62 ) ;
if ( ! V_28 && ( V_68 & V_73 ) ) {
F_49 ( V_2 ) ;
F_50 ( V_10 ) ;
V_10 = F_47 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_48 ( & V_70 , V_15 , V_68 , V_69 , V_10 ,
V_2 ) ;
V_28 = F_41 ( & V_70 , V_62 ) ;
V_10 = V_70 . V_10 ;
}
F_50 ( V_10 ) ;
if ( ! V_28 )
return F_46 ( - V_74 ) ;
return V_28 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_27 * V_28 )
{
const int V_63 = V_28 -> V_63 ;
struct V_14 * V_15 = V_28 -> V_15 ;
if ( V_28 -> V_33 & V_66 )
F_52 ( & V_2 -> V_67 ) ;
V_28 -> V_33 = 0 ;
F_8 ( V_75 , & V_28 -> V_76 ) ;
F_53 ( V_2 , V_63 , & V_10 -> V_77 ) ;
F_13 ( V_15 ) ;
}
void F_54 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
struct V_1 * V_2 ;
struct V_14 * V_15 = V_28 -> V_15 ;
V_10 -> V_78 [ F_55 ( V_28 ) ] ++ ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_51 ( V_2 , V_10 , V_28 ) ;
}
inline void F_56 ( struct V_27 * V_28 , int error )
{
F_57 ( V_28 ) ;
if ( V_28 -> V_56 ) {
V_28 -> V_56 ( V_28 , error ) ;
} else {
if ( F_58 ( F_59 ( V_28 ) ) )
F_54 ( V_28 -> V_58 ) ;
F_54 ( V_28 ) ;
}
}
void F_60 ( struct V_27 * V_28 , int error )
{
if ( F_61 ( V_28 , error , F_62 ( V_28 ) ) )
F_63 () ;
F_56 ( V_28 , error ) ;
}
static void F_64 ( void * V_61 )
{
struct V_27 * V_28 = V_61 ;
V_28 -> V_15 -> V_79 ( V_28 ) ;
}
static void F_65 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
bool V_80 = false ;
int V_34 ;
if ( ! F_4 ( V_81 , & V_28 -> V_15 -> V_82 ) ) {
V_28 -> V_15 -> V_79 ( V_28 ) ;
return;
}
V_34 = F_66 () ;
if ( ! F_4 ( V_83 , & V_28 -> V_15 -> V_82 ) )
V_80 = F_67 ( V_34 , V_10 -> V_34 ) ;
if ( V_34 != V_10 -> V_34 && ! V_80 && F_68 ( V_10 -> V_34 ) ) {
V_28 -> V_84 . V_85 = F_64 ;
V_28 -> V_84 . V_86 = V_28 ;
V_28 -> V_84 . V_87 = 0 ;
F_69 ( V_10 -> V_34 , & V_28 -> V_84 ) ;
} else {
V_28 -> V_15 -> V_79 ( V_28 ) ;
}
F_70 () ;
}
void F_71 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( ! V_15 -> V_79 )
F_60 ( V_28 , V_28 -> V_47 ) ;
else
F_65 ( V_28 ) ;
}
void F_72 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( F_58 ( F_73 ( V_15 ) ) )
return;
if ( ! F_74 ( V_28 ) )
F_71 ( V_28 ) ;
}
void F_75 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_76 ( V_15 , V_28 ) ;
V_28 -> V_52 = F_62 ( V_28 ) ;
if ( F_58 ( F_59 ( V_28 ) ) )
V_28 -> V_58 -> V_52 = F_62 ( V_28 -> V_58 ) ;
F_77 ( V_28 ) ;
F_78 () ;
if ( ! F_4 ( V_75 , & V_28 -> V_76 ) )
F_6 ( V_75 , & V_28 -> V_76 ) ;
if ( F_4 ( V_88 , & V_28 -> V_76 ) )
F_8 ( V_88 , & V_28 -> V_76 ) ;
if ( V_15 -> V_89 && F_62 ( V_28 ) ) {
V_28 -> V_43 ++ ;
}
}
static void F_79 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_80 ( V_15 , V_28 ) ;
if ( F_81 ( V_75 , & V_28 -> V_76 ) ) {
if ( V_15 -> V_89 && F_62 ( V_28 ) )
V_28 -> V_43 -- ;
}
}
void F_82 ( struct V_27 * V_28 )
{
F_79 ( V_28 ) ;
F_83 ( F_84 ( V_28 ) ) ;
F_85 ( V_28 , true ) ;
}
static void F_86 ( struct V_90 * V_91 )
{
struct V_14 * V_15 =
F_16 ( V_91 , struct V_14 , V_92 ) ;
F_87 ( V_93 ) ;
struct V_27 * V_28 , * V_94 ;
unsigned long V_87 ;
F_88 ( & V_15 -> V_95 , V_87 ) ;
F_89 ( & V_15 -> V_96 , & V_93 ) ;
F_90 ( & V_15 -> V_95 , V_87 ) ;
F_91 (rq, next, &rq_list, queuelist) {
if ( ! ( V_28 -> V_33 & V_97 ) )
continue;
V_28 -> V_33 &= ~ V_97 ;
F_92 ( & V_28 -> V_31 ) ;
F_93 ( V_28 , true , false , false ) ;
}
while ( ! F_94 ( & V_93 ) ) {
V_28 = F_95 ( V_93 . V_94 , struct V_27 , V_31 ) ;
F_92 ( & V_28 -> V_31 ) ;
F_93 ( V_28 , false , false , false ) ;
}
F_96 ( V_15 ) ;
}
void F_85 ( struct V_27 * V_28 , bool V_98 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
unsigned long V_87 ;
F_83 ( V_28 -> V_33 & V_97 ) ;
F_88 ( & V_15 -> V_95 , V_87 ) ;
if ( V_98 ) {
V_28 -> V_33 |= V_97 ;
F_97 ( & V_28 -> V_31 , & V_15 -> V_96 ) ;
} else {
F_98 ( & V_28 -> V_31 , & V_15 -> V_96 ) ;
}
F_90 ( & V_15 -> V_95 , V_87 ) ;
}
void F_99 ( struct V_14 * V_15 )
{
F_100 ( & V_15 -> V_92 ) ;
}
static inline bool F_101 ( struct V_27 * V_28 ,
struct V_99 * V_100 , unsigned int V_63 )
{
return ( ( V_28 -> V_33 & V_101 ) &&
V_100 -> V_102 -> V_63 == V_63 ) ;
}
struct V_27 * F_102 ( struct V_103 * V_26 , unsigned int V_63 )
{
struct V_27 * V_28 = V_26 -> V_65 [ V_63 ] ;
struct V_99 * V_100 = F_103 ( V_28 -> V_15 , V_28 -> V_32 ) ;
if ( ! F_101 ( V_28 , V_100 , V_63 ) )
return V_28 ;
return V_100 -> V_102 ;
}
void F_104 ( struct V_27 * V_104 , bool V_69 )
{
struct V_105 * V_106 = V_104 -> V_15 -> V_71 ;
enum V_107 V_16 = V_108 ;
if ( ! F_4 ( V_75 , & V_104 -> V_76 ) )
return;
if ( V_106 -> V_55 )
V_16 = V_106 -> V_55 ( V_104 , V_69 ) ;
switch ( V_16 ) {
case V_109 :
F_71 ( V_104 ) ;
break;
case V_108 :
F_77 ( V_104 ) ;
F_105 ( V_104 ) ;
break;
case V_110 :
break;
default:
F_106 ( V_111 L_1 , V_16 ) ;
break;
}
}
static void F_107 ( struct V_1 * V_2 ,
struct V_27 * V_28 , void * V_112 , bool V_69 )
{
struct V_113 * V_61 = V_112 ;
if ( ! F_4 ( V_75 , & V_28 -> V_76 ) )
return;
if ( F_108 ( V_40 , V_28 -> V_114 ) ) {
if ( ! F_74 ( V_28 ) )
F_104 ( V_28 , V_69 ) ;
} else if ( ! V_61 -> V_115 || F_109 ( V_61 -> V_94 , V_28 -> V_114 ) ) {
V_61 -> V_94 = V_28 -> V_114 ;
V_61 -> V_115 = 1 ;
}
}
static void F_110 ( unsigned long V_112 )
{
struct V_14 * V_15 = (struct V_14 * ) V_112 ;
struct V_113 V_61 = {
. V_94 = 0 ,
. V_115 = 0 ,
} ;
struct V_1 * V_2 ;
int V_3 ;
F_111 (q, hctx, i) {
if ( ! V_2 -> V_116 || ! V_2 -> V_26 )
continue;
F_112 ( V_2 , F_107 , & V_61 ) ;
}
if ( V_61 . V_115 ) {
V_61 . V_94 = F_113 ( F_114 ( V_61 . V_94 ) ) ;
F_115 ( & V_15 -> V_55 , V_61 . V_94 ) ;
} else {
F_111 (q, hctx, i)
F_116 ( V_2 ) ;
}
}
static bool F_117 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_117 * V_117 )
{
struct V_27 * V_28 ;
int V_118 = 8 ;
F_118 (rq, &ctx->rq_list, queuelist) {
int V_119 ;
if ( ! V_118 -- )
break;
if ( ! F_119 ( V_28 , V_117 ) )
continue;
V_119 = F_120 ( V_28 , V_117 ) ;
if ( V_119 == V_120 ) {
if ( F_121 ( V_15 , V_28 , V_117 ) ) {
V_10 -> V_121 ++ ;
return true ;
}
break;
} else if ( V_119 == V_122 ) {
if ( F_122 ( V_15 , V_28 , V_117 ) ) {
V_10 -> V_121 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_123 ( struct V_1 * V_2 , struct V_123 * V_124 )
{
struct V_9 * V_10 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_8 * V_13 = & V_2 -> V_4 . V_6 [ V_3 ] ;
unsigned int V_125 , V_126 ;
if ( ! V_13 -> V_7 )
continue;
V_126 = 0 ;
V_125 = V_3 * V_2 -> V_4 . V_12 ;
do {
V_126 = F_124 ( & V_13 -> V_7 , V_13 -> V_127 , V_126 ) ;
if ( V_126 >= V_13 -> V_127 )
break;
V_10 = V_2 -> V_128 [ V_126 + V_125 ] ;
F_8 ( V_126 , & V_13 -> V_7 ) ;
F_125 ( & V_10 -> V_129 ) ;
F_126 ( & V_10 -> V_93 , V_124 ) ;
F_127 ( & V_10 -> V_129 ) ;
V_126 ++ ;
} while ( 1 );
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_130 ;
struct V_27 * V_28 ;
F_87 ( V_93 ) ;
int V_131 ;
F_128 ( ! F_129 ( F_130 () , V_2 -> V_132 ) ) ;
if ( F_58 ( F_4 ( V_133 , & V_2 -> V_134 ) ) )
return;
V_2 -> V_135 ++ ;
F_123 ( V_2 , & V_93 ) ;
if ( ! F_131 ( & V_2 -> V_136 ) ) {
F_125 ( & V_2 -> V_129 ) ;
if ( ! F_94 ( & V_2 -> V_136 ) )
F_89 ( & V_2 -> V_136 , & V_93 ) ;
F_127 ( & V_2 -> V_129 ) ;
}
V_131 = 0 ;
while ( ! F_94 ( & V_93 ) ) {
int V_16 ;
V_28 = F_132 ( & V_93 , struct V_27 , V_31 ) ;
F_92 ( & V_28 -> V_31 ) ;
V_16 = V_15 -> V_71 -> V_137 ( V_2 , V_28 , F_94 ( & V_93 ) ) ;
switch ( V_16 ) {
case V_138 :
V_131 ++ ;
continue;
case V_139 :
F_97 ( & V_28 -> V_31 , & V_93 ) ;
F_79 ( V_28 ) ;
break;
default:
F_133 ( L_2 , V_16 ) ;
case V_140 :
V_28 -> V_47 = - V_141 ;
F_60 ( V_28 , V_28 -> V_47 ) ;
break;
}
if ( V_16 == V_139 )
break;
}
if ( ! V_131 )
V_2 -> V_142 [ 0 ] ++ ;
else if ( V_131 < ( 1 << ( V_143 - 1 ) ) )
V_2 -> V_142 [ F_134 ( V_131 ) + 1 ] ++ ;
if ( ! F_94 ( & V_93 ) ) {
F_125 ( & V_2 -> V_129 ) ;
F_135 ( & V_93 , & V_2 -> V_136 ) ;
F_127 ( & V_2 -> V_129 ) ;
}
}
static int F_136 ( struct V_1 * V_2 )
{
int V_34 = V_2 -> V_144 ;
if ( -- V_2 -> V_145 <= 0 ) {
int V_144 ;
V_144 = F_137 ( V_2 -> V_144 , V_2 -> V_132 ) ;
if ( V_144 >= V_146 )
V_144 = F_138 ( V_2 -> V_132 ) ;
V_2 -> V_144 = V_144 ;
V_2 -> V_145 = V_147 ;
}
return V_34 ;
}
void F_139 ( struct V_1 * V_2 , bool V_148 )
{
if ( F_58 ( F_4 ( V_133 , & V_2 -> V_134 ) ) )
return;
if ( ! V_148 && F_129 ( F_140 () , V_2 -> V_132 ) )
F_49 ( V_2 ) ;
else if ( V_2 -> V_130 -> V_149 == 1 )
F_141 ( & V_2 -> V_150 , 0 ) ;
else {
unsigned int V_34 ;
V_34 = F_136 ( V_2 ) ;
F_142 ( V_34 , & V_2 -> V_150 , 0 ) ;
}
}
void F_22 ( struct V_14 * V_15 , bool V_148 )
{
struct V_1 * V_2 ;
int V_3 ;
F_111 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_131 ( & V_2 -> V_136 ) ) ||
F_4 ( V_133 , & V_2 -> V_134 ) )
continue;
F_143 () ;
F_139 ( V_2 , V_148 ) ;
F_144 () ;
}
}
void F_145 ( struct V_1 * V_2 )
{
F_146 ( & V_2 -> V_150 ) ;
F_146 ( & V_2 -> V_151 ) ;
F_6 ( V_133 , & V_2 -> V_134 ) ;
}
void F_147 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_111 (q, hctx, i)
F_145 ( V_2 ) ;
}
void F_148 ( struct V_1 * V_2 )
{
F_8 ( V_133 , & V_2 -> V_134 ) ;
F_143 () ;
F_139 ( V_2 , false ) ;
F_144 () ;
}
void F_96 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_111 (q, hctx, i)
F_148 ( V_2 ) ;
}
void F_149 ( struct V_14 * V_15 , bool V_148 )
{
struct V_1 * V_2 ;
int V_3 ;
F_111 (q, hctx, i) {
if ( ! F_4 ( V_133 , & V_2 -> V_134 ) )
continue;
F_8 ( V_133 , & V_2 -> V_134 ) ;
F_143 () ;
F_139 ( V_2 , V_148 ) ;
F_144 () ;
}
}
static void F_150 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_91 , struct V_1 , V_150 . V_91 ) ;
F_49 ( V_2 ) ;
}
static void F_151 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_91 , struct V_1 , V_151 . V_91 ) ;
if ( F_81 ( V_133 , & V_2 -> V_134 ) )
F_49 ( V_2 ) ;
}
void F_152 ( struct V_1 * V_2 , unsigned long V_152 )
{
unsigned long V_153 = F_153 ( V_152 ) ;
if ( V_2 -> V_130 -> V_149 == 1 )
F_141 ( & V_2 -> V_151 , V_153 ) ;
else {
unsigned int V_34 ;
V_34 = F_136 ( V_2 ) ;
F_142 ( V_34 , & V_2 -> V_151 , V_153 ) ;
}
}
static void F_154 ( struct V_1 * V_2 ,
struct V_27 * V_28 , bool V_98 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
F_155 ( V_2 -> V_130 , V_28 ) ;
if ( V_98 )
F_97 ( & V_28 -> V_31 , & V_10 -> V_93 ) ;
else
F_98 ( & V_28 -> V_31 , & V_10 -> V_93 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_93 ( struct V_27 * V_28 , bool V_98 , bool V_154 ,
bool V_148 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_28 -> V_32 , * V_155 ;
V_155 = F_47 ( V_15 ) ;
if ( ! F_68 ( V_10 -> V_34 ) )
V_28 -> V_32 = V_10 = V_155 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_125 ( & V_10 -> V_129 ) ;
F_154 ( V_2 , V_28 , V_98 ) ;
F_127 ( & V_10 -> V_129 ) ;
if ( V_154 )
F_139 ( V_2 , V_148 ) ;
F_50 ( V_155 ) ;
}
static void F_156 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_123 * V_124 ,
int V_127 ,
bool V_156 )
{
struct V_1 * V_2 ;
struct V_9 * V_155 ;
F_157 ( V_15 , V_127 , ! V_156 ) ;
V_155 = F_47 ( V_15 ) ;
if ( ! F_68 ( V_10 -> V_34 ) )
V_10 = V_155 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_125 ( & V_10 -> V_129 ) ;
while ( ! F_94 ( V_124 ) ) {
struct V_27 * V_28 ;
V_28 = F_132 ( V_124 , struct V_27 , V_31 ) ;
F_92 ( & V_28 -> V_31 ) ;
V_28 -> V_32 = V_10 ;
F_154 ( V_2 , V_28 , false ) ;
}
F_127 ( & V_10 -> V_129 ) ;
F_139 ( V_2 , V_156 ) ;
F_50 ( V_155 ) ;
}
static int F_158 ( void * V_112 , struct V_123 * V_157 , struct V_123 * V_158 )
{
struct V_27 * V_159 = F_16 ( V_157 , struct V_27 , V_31 ) ;
struct V_27 * V_160 = F_16 ( V_158 , struct V_27 , V_31 ) ;
return ! ( V_159 -> V_32 < V_160 -> V_32 ||
( V_159 -> V_32 == V_160 -> V_32 &&
F_159 ( V_159 ) < F_159 ( V_160 ) ) ) ;
}
void F_160 ( struct V_161 * V_162 , bool V_156 )
{
struct V_9 * V_163 ;
struct V_14 * V_164 ;
struct V_27 * V_28 ;
F_87 ( V_124 ) ;
F_87 ( V_165 ) ;
unsigned int V_127 ;
F_89 ( & V_162 -> V_166 , & V_124 ) ;
F_161 ( NULL , & V_124 , F_158 ) ;
V_164 = NULL ;
V_163 = NULL ;
V_127 = 0 ;
while ( ! F_94 ( & V_124 ) ) {
V_28 = F_162 ( V_124 . V_94 ) ;
F_92 ( & V_28 -> V_31 ) ;
F_83 ( ! V_28 -> V_15 ) ;
if ( V_28 -> V_32 != V_163 ) {
if ( V_163 ) {
F_156 ( V_164 , V_163 ,
& V_165 , V_127 ,
V_156 ) ;
}
V_163 = V_28 -> V_32 ;
V_164 = V_28 -> V_15 ;
V_127 = 0 ;
}
V_127 ++ ;
F_98 ( & V_28 -> V_31 , & V_165 ) ;
}
if ( V_163 ) {
F_156 ( V_164 , V_163 , & V_165 , V_127 ,
V_156 ) ;
}
}
static void F_163 ( struct V_27 * V_28 , struct V_117 * V_117 )
{
F_164 ( V_28 , V_117 ) ;
if ( F_165 ( V_28 ) )
F_166 ( V_28 , 1 ) ;
}
static inline bool F_167 ( struct V_1 * V_2 )
{
return ( V_2 -> V_87 & V_167 ) &&
! F_168 ( V_2 -> V_130 ) ;
}
static inline bool F_169 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_27 * V_28 , struct V_117 * V_117 )
{
if ( ! F_167 ( V_2 ) ) {
F_163 ( V_28 , V_117 ) ;
F_125 ( & V_10 -> V_129 ) ;
V_168:
F_154 ( V_2 , V_28 , false ) ;
F_127 ( & V_10 -> V_129 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_130 ;
F_125 ( & V_10 -> V_129 ) ;
if ( ! F_117 ( V_15 , V_10 , V_117 ) ) {
F_163 ( V_28 , V_117 ) ;
goto V_168;
}
F_127 ( & V_10 -> V_129 ) ;
F_51 ( V_2 , V_10 , V_28 ) ;
return true ;
}
}
static struct V_27 * F_170 ( struct V_14 * V_15 ,
struct V_117 * V_117 ,
struct V_169 * V_61 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
int V_62 = F_171 ( V_117 ) ;
struct V_60 V_70 ;
if ( F_58 ( F_9 ( V_15 ) ) ) {
F_172 ( V_117 , - V_141 ) ;
return NULL ;
}
V_10 = F_47 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
if ( F_40 ( V_117 -> V_170 ) )
V_62 |= V_171 ;
F_173 ( V_15 , V_117 , V_62 ) ;
F_48 ( & V_70 , V_15 , V_172 , false , V_10 ,
V_2 ) ;
V_28 = F_41 ( & V_70 , V_62 ) ;
if ( F_58 ( ! V_28 ) ) {
F_49 ( V_2 ) ;
F_50 ( V_10 ) ;
F_174 ( V_15 , V_117 , V_62 ) ;
V_10 = F_47 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_48 ( & V_70 , V_15 ,
V_73 | V_172 , false , V_10 , V_2 ) ;
V_28 = F_41 ( & V_70 , V_62 ) ;
V_10 = V_70 . V_10 ;
V_2 = V_70 . V_2 ;
}
V_2 -> V_131 ++ ;
V_61 -> V_2 = V_2 ;
V_61 -> V_10 = V_10 ;
return V_28 ;
}
static void F_175 ( struct V_14 * V_15 , struct V_117 * V_117 )
{
const int V_173 = F_40 ( V_117 -> V_170 ) ;
const int V_174 = V_117 -> V_170 & ( V_175 | V_176 ) ;
struct V_169 V_61 ;
struct V_27 * V_28 ;
F_176 ( V_15 , & V_117 ) ;
if ( F_177 ( V_117 ) && F_178 ( V_117 ) ) {
F_172 ( V_117 , - V_141 ) ;
return;
}
V_28 = F_170 ( V_15 , V_117 , & V_61 ) ;
if ( F_58 ( ! V_28 ) )
return;
if ( F_58 ( V_174 ) ) {
F_163 ( V_28 , V_117 ) ;
F_179 ( V_28 ) ;
goto V_154;
}
if ( V_173 ) {
int V_16 ;
F_163 ( V_28 , V_117 ) ;
V_16 = V_15 -> V_71 -> V_137 ( V_61 . V_2 , V_28 , true ) ;
if ( V_16 == V_138 )
goto V_177;
else {
F_79 ( V_28 ) ;
if ( V_16 == V_140 ) {
V_28 -> V_47 = - V_141 ;
F_60 ( V_28 , V_28 -> V_47 ) ;
goto V_177;
}
}
}
if ( ! F_169 ( V_61 . V_2 , V_61 . V_10 , V_28 , V_117 ) ) {
V_154:
F_139 ( V_61 . V_2 , ! V_173 || V_174 ) ;
}
V_177:
F_50 ( V_61 . V_10 ) ;
}
static void F_180 ( struct V_14 * V_15 , struct V_117 * V_117 )
{
const int V_173 = F_40 ( V_117 -> V_170 ) ;
const int V_174 = V_117 -> V_170 & ( V_175 | V_176 ) ;
unsigned int V_178 , V_179 = 0 ;
struct V_169 V_61 ;
struct V_27 * V_28 ;
V_178 = ! V_174 && ! V_173 ;
F_176 ( V_15 , & V_117 ) ;
if ( F_177 ( V_117 ) && F_178 ( V_117 ) ) {
F_172 ( V_117 , - V_141 ) ;
return;
}
if ( V_178 && ! F_168 ( V_15 ) &&
F_181 ( V_15 , V_117 , & V_179 ) )
return;
V_28 = F_170 ( V_15 , V_117 , & V_61 ) ;
if ( F_58 ( ! V_28 ) )
return;
if ( F_58 ( V_174 ) ) {
F_163 ( V_28 , V_117 ) ;
F_179 ( V_28 ) ;
goto V_154;
}
if ( V_178 ) {
struct V_161 * V_162 = V_180 -> V_162 ;
if ( V_162 ) {
F_163 ( V_28 , V_117 ) ;
if ( F_94 ( & V_162 -> V_166 ) )
F_182 ( V_15 ) ;
else if ( V_179 >= V_181 ) {
F_183 ( V_162 , false ) ;
F_182 ( V_15 ) ;
}
F_98 ( & V_28 -> V_31 , & V_162 -> V_166 ) ;
F_50 ( V_61 . V_10 ) ;
return;
}
}
if ( ! F_169 ( V_61 . V_2 , V_61 . V_10 , V_28 , V_117 ) ) {
V_154:
F_139 ( V_61 . V_2 , ! V_173 || V_174 ) ;
}
F_50 ( V_61 . V_10 ) ;
}
struct V_1 * F_184 ( struct V_14 * V_15 , const int V_34 )
{
return V_15 -> V_182 [ V_15 -> V_183 [ V_34 ] ] ;
}
static void F_185 ( struct V_184 * V_185 ,
struct V_103 * V_26 , unsigned int V_186 )
{
struct V_187 * V_187 ;
if ( V_26 -> V_65 && V_185 -> V_106 -> V_188 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_189 ; V_3 ++ ) {
if ( ! V_26 -> V_65 [ V_3 ] )
continue;
V_185 -> V_106 -> V_188 ( V_185 -> V_190 , V_26 -> V_65 [ V_3 ] ,
V_186 , V_3 ) ;
V_26 -> V_65 [ V_3 ] = NULL ;
}
}
while ( ! F_94 ( & V_26 -> V_191 ) ) {
V_187 = F_132 ( & V_26 -> V_191 , struct V_187 , V_192 ) ;
F_92 ( & V_187 -> V_192 ) ;
F_186 ( V_187 , V_187 -> V_193 ) ;
}
F_187 ( V_26 -> V_65 ) ;
F_188 ( V_26 ) ;
}
static T_2 F_189 ( unsigned int V_194 )
{
return ( T_2 ) V_195 << V_194 ;
}
static struct V_103 * F_190 ( struct V_184 * V_185 ,
unsigned int V_186 )
{
struct V_103 * V_26 ;
unsigned int V_3 , V_196 , V_197 , V_198 = 4 ;
T_2 V_199 , V_200 ;
V_26 = F_191 ( V_185 -> V_201 , V_185 -> V_202 ,
V_185 -> V_203 ) ;
if ( ! V_26 )
return NULL ;
F_34 ( & V_26 -> V_191 ) ;
V_26 -> V_65 = F_192 ( V_185 -> V_201 * sizeof( struct V_27 * ) ,
V_204 | V_205 | V_206 ,
V_185 -> V_203 ) ;
if ( ! V_26 -> V_65 ) {
F_188 ( V_26 ) ;
return NULL ;
}
V_199 = F_193 ( sizeof( struct V_27 ) + V_185 -> V_207 ,
F_194 () ) ;
V_200 = V_199 * V_185 -> V_201 ;
for ( V_3 = 0 ; V_3 < V_185 -> V_201 ; ) {
int V_208 = V_198 ;
struct V_187 * V_187 ;
int V_209 ;
void * V_210 ;
while ( V_200 < F_189 ( V_208 - 1 ) && V_208 )
V_208 -- ;
do {
V_187 = F_195 ( V_185 -> V_203 ,
V_204 | V_205 | V_206 ,
V_208 ) ;
if ( V_187 )
break;
if ( ! V_208 -- )
break;
if ( F_189 ( V_208 ) < V_199 )
break;
} while ( 1 );
if ( ! V_187 )
goto V_211;
V_187 -> V_193 = V_208 ;
F_98 ( & V_187 -> V_192 , & V_26 -> V_191 ) ;
V_210 = F_196 ( V_187 ) ;
V_197 = F_189 ( V_208 ) / V_199 ;
V_209 = F_197 ( V_197 , V_185 -> V_201 - V_3 ) ;
V_200 -= V_209 * V_199 ;
for ( V_196 = 0 ; V_196 < V_209 ; V_196 ++ ) {
V_26 -> V_65 [ V_3 ] = V_210 ;
V_26 -> V_65 [ V_3 ] -> V_76 = 0 ;
V_26 -> V_65 [ V_3 ] -> V_33 = 0 ;
if ( V_185 -> V_106 -> V_212 ) {
if ( V_185 -> V_106 -> V_212 ( V_185 -> V_190 ,
V_26 -> V_65 [ V_3 ] , V_186 , V_3 ,
V_185 -> V_203 ) ) {
V_26 -> V_65 [ V_3 ] = NULL ;
goto V_211;
}
}
V_210 += V_199 ;
V_3 ++ ;
}
}
return V_26 ;
V_211:
F_185 ( V_185 , V_26 , V_186 ) ;
return NULL ;
}
static void F_198 ( struct V_213 * V_214 )
{
F_187 ( V_214 -> V_6 ) ;
}
static int F_199 ( struct V_213 * V_214 , int V_215 )
{
unsigned int V_216 = 8 , V_217 , V_218 , V_3 ;
V_214 -> V_12 = V_216 ;
V_218 = F_200 ( V_146 , V_216 ) / V_216 ;
V_214 -> V_6 = F_192 ( V_218 * sizeof( struct V_8 ) ,
V_204 , V_215 ) ;
if ( ! V_214 -> V_6 )
return - V_219 ;
V_214 -> V_5 = V_218 ;
V_217 = V_146 ;
for ( V_3 = 0 ; V_3 < V_218 ; V_3 ++ ) {
V_214 -> V_6 [ V_3 ] . V_127 = F_197 ( V_217 , V_214 -> V_12 ) ;
V_217 -= V_214 -> V_6 [ V_3 ] . V_127 ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_130 ;
struct V_9 * V_10 ;
F_87 ( V_220 ) ;
V_10 = F_202 ( V_15 , V_34 ) ;
F_125 ( & V_10 -> V_129 ) ;
if ( ! F_94 ( & V_10 -> V_93 ) ) {
F_89 ( & V_10 -> V_93 , & V_220 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_127 ( & V_10 -> V_129 ) ;
if ( F_94 ( & V_220 ) )
return V_221 ;
V_10 = F_47 ( V_15 ) ;
F_125 ( & V_10 -> V_129 ) ;
while ( ! F_94 ( & V_220 ) ) {
struct V_27 * V_28 ;
V_28 = F_132 ( & V_220 , struct V_27 , V_31 ) ;
V_28 -> V_32 = V_10 ;
F_203 ( & V_28 -> V_31 , & V_10 -> V_93 ) ;
}
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_3 ( V_2 , V_10 ) ;
F_127 ( & V_10 -> V_129 ) ;
F_139 ( V_2 , true ) ;
F_50 ( V_10 ) ;
return V_221 ;
}
static int F_204 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_130 ;
struct V_184 * V_185 = V_15 -> V_222 ;
if ( V_185 -> V_26 [ V_2 -> V_223 ] )
return V_221 ;
V_185 -> V_26 [ V_2 -> V_223 ] = F_190 ( V_185 , V_2 -> V_223 ) ;
if ( ! V_185 -> V_26 [ V_2 -> V_223 ] )
return V_224 ;
V_2 -> V_26 = V_185 -> V_26 [ V_2 -> V_223 ] ;
return V_221 ;
}
static int F_205 ( void * V_61 , unsigned long V_225 ,
unsigned int V_34 )
{
struct V_1 * V_2 = V_61 ;
if ( V_225 == V_226 || V_225 == V_227 )
return F_201 ( V_2 , V_34 ) ;
else if ( V_225 == V_228 || V_225 == V_229 )
return F_204 ( V_2 , V_34 ) ;
return V_221 ;
}
static void F_206 ( struct V_14 * V_15 ,
struct V_184 * V_185 ,
struct V_1 * V_2 , unsigned int V_186 )
{
unsigned V_230 = V_185 -> V_201 ;
F_116 ( V_2 ) ;
if ( V_185 -> V_106 -> V_188 )
V_185 -> V_106 -> V_188 ( V_185 -> V_190 ,
V_2 -> V_100 -> V_102 , V_186 ,
V_230 + V_186 ) ;
if ( V_185 -> V_106 -> V_231 )
V_185 -> V_106 -> V_231 ( V_2 , V_186 ) ;
F_207 ( & V_2 -> V_232 ) ;
F_208 ( V_2 -> V_100 ) ;
F_187 ( V_2 -> V_128 ) ;
F_198 ( & V_2 -> V_4 ) ;
}
static void F_209 ( struct V_14 * V_15 ,
struct V_184 * V_185 , int V_233 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_111 (q, hctx, i) {
if ( V_3 == V_233 )
break;
F_206 ( V_15 , V_185 , V_2 , V_3 ) ;
}
}
static void F_210 ( struct V_14 * V_15 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_111 (q, hctx, i) {
F_211 ( V_2 -> V_132 ) ;
F_187 ( V_2 ) ;
}
}
static int F_212 ( struct V_14 * V_15 ,
struct V_184 * V_185 ,
struct V_1 * V_2 , unsigned V_186 )
{
int V_215 ;
unsigned V_230 = V_185 -> V_201 ;
V_215 = V_2 -> V_203 ;
if ( V_215 == V_234 )
V_215 = V_2 -> V_203 = V_185 -> V_203 ;
F_213 ( & V_2 -> V_150 , F_150 ) ;
F_213 ( & V_2 -> V_151 , F_151 ) ;
F_214 ( & V_2 -> V_129 ) ;
F_34 ( & V_2 -> V_136 ) ;
V_2 -> V_130 = V_15 ;
V_2 -> V_223 = V_186 ;
V_2 -> V_87 = V_185 -> V_87 ;
V_2 -> V_207 = V_185 -> V_207 ;
F_215 ( & V_2 -> V_232 ,
F_205 , V_2 ) ;
F_216 ( & V_2 -> V_232 ) ;
V_2 -> V_26 = V_185 -> V_26 [ V_186 ] ;
V_2 -> V_128 = F_217 ( V_146 * sizeof( void * ) ,
V_204 , V_215 ) ;
if ( ! V_2 -> V_128 )
goto V_235;
if ( F_199 ( & V_2 -> V_4 , V_215 ) )
goto V_236;
V_2 -> V_116 = 0 ;
if ( V_185 -> V_106 -> V_237 &&
V_185 -> V_106 -> V_237 ( V_2 , V_185 -> V_190 , V_186 ) )
goto V_238;
V_2 -> V_100 = F_218 ( V_15 , V_2 -> V_203 , V_185 -> V_207 ) ;
if ( ! V_2 -> V_100 )
goto V_231;
if ( V_185 -> V_106 -> V_212 &&
V_185 -> V_106 -> V_212 ( V_185 -> V_190 ,
V_2 -> V_100 -> V_102 , V_186 ,
V_230 + V_186 , V_215 ) )
goto V_239;
return 0 ;
V_239:
F_187 ( V_2 -> V_100 ) ;
V_231:
if ( V_185 -> V_106 -> V_231 )
V_185 -> V_106 -> V_231 ( V_2 , V_186 ) ;
V_238:
F_198 ( & V_2 -> V_4 ) ;
V_236:
F_187 ( V_2 -> V_128 ) ;
V_235:
F_207 ( & V_2 -> V_232 ) ;
return - 1 ;
}
static int F_219 ( struct V_14 * V_15 ,
struct V_184 * V_185 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_111 (q, hctx, i) {
if ( F_212 ( V_15 , V_185 , V_2 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_149 )
return 0 ;
F_209 ( V_15 , V_185 , V_3 ) ;
return 1 ;
}
static void F_220 ( struct V_14 * V_15 ,
unsigned int V_149 )
{
unsigned int V_3 ;
F_221 (i) {
struct V_9 * V_240 = F_222 ( V_15 -> V_241 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_240 , 0 , sizeof( * V_240 ) ) ;
V_240 -> V_34 = V_3 ;
F_214 ( & V_240 -> V_129 ) ;
F_34 ( & V_240 -> V_93 ) ;
V_240 -> V_130 = V_15 ;
if ( ! F_68 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_223 ( V_3 , V_2 -> V_132 ) ;
V_2 -> V_116 ++ ;
if ( V_149 > 1 && V_2 -> V_203 == V_234 )
V_2 -> V_203 = F_224 ( V_3 ) ;
}
}
static void F_225 ( struct V_14 * V_15 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_111 (q, hctx, i) {
F_226 ( V_2 -> V_132 ) ;
V_2 -> V_116 = 0 ;
}
F_227 (q, ctx, i) {
if ( ! F_68 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_223 ( V_3 , V_2 -> V_132 ) ;
V_10 -> V_11 = V_2 -> V_116 ;
V_2 -> V_128 [ V_2 -> V_116 ++ ] = V_10 ;
}
F_111 (q, hctx, i) {
if ( ! V_2 -> V_116 ) {
struct V_184 * V_185 = V_15 -> V_222 ;
if ( V_185 -> V_26 [ V_3 ] ) {
F_185 ( V_185 , V_185 -> V_26 [ V_3 ] , V_3 ) ;
V_185 -> V_26 [ V_3 ] = NULL ;
V_2 -> V_26 = NULL ;
}
continue;
}
V_2 -> V_144 = F_138 ( V_2 -> V_132 ) ;
V_2 -> V_145 = V_147 ;
}
}
static void F_228 ( struct V_184 * V_185 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
bool V_80 ;
int V_3 ;
if ( V_185 -> V_242 . V_94 == V_185 -> V_242 . V_243 )
V_80 = false ;
else
V_80 = true ;
F_229 (q, &set->tag_list, tag_set_list) {
F_26 ( V_15 ) ;
F_111 (q, hctx, i) {
if ( V_80 )
V_2 -> V_87 |= V_244 ;
else
V_2 -> V_87 &= ~ V_244 ;
}
F_27 ( V_15 ) ;
}
}
static void F_230 ( struct V_14 * V_15 )
{
struct V_184 * V_185 = V_15 -> V_222 ;
F_231 ( & V_185 -> V_245 ) ;
F_92 ( & V_15 -> V_246 ) ;
F_228 ( V_185 ) ;
F_232 ( & V_185 -> V_245 ) ;
}
static void F_233 ( struct V_184 * V_185 ,
struct V_14 * V_15 )
{
V_15 -> V_222 = V_185 ;
F_231 ( & V_185 -> V_245 ) ;
F_98 ( & V_15 -> V_246 , & V_185 -> V_242 ) ;
F_228 ( V_185 ) ;
F_232 ( & V_185 -> V_245 ) ;
}
struct V_14 * F_234 ( struct V_184 * V_185 )
{
struct V_1 * * V_247 ;
struct V_9 T_3 * V_10 ;
struct V_14 * V_15 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_235 ( struct V_9 ) ;
if ( ! V_10 )
return F_46 ( - V_219 ) ;
if ( F_236 () ) {
V_185 -> V_149 = 1 ;
V_185 -> V_201 = F_197 ( 64U , V_185 -> V_201 ) ;
}
V_247 = F_217 ( V_185 -> V_149 * sizeof( * V_247 ) , V_204 ,
V_185 -> V_203 ) ;
if ( ! V_247 )
goto V_248;
V_6 = F_237 ( V_185 ) ;
if ( ! V_6 )
goto V_249;
for ( V_3 = 0 ; V_3 < V_185 -> V_149 ; V_3 ++ ) {
int V_215 = F_238 ( V_6 , V_3 ) ;
V_247 [ V_3 ] = F_192 ( sizeof( struct V_1 ) ,
V_204 , V_215 ) ;
if ( ! V_247 [ V_3 ] )
goto V_250;
if ( ! F_239 ( & V_247 [ V_3 ] -> V_132 , V_204 ,
V_215 ) )
goto V_250;
F_240 ( & V_247 [ V_3 ] -> V_67 , 0 ) ;
V_247 [ V_3 ] -> V_203 = V_215 ;
V_247 [ V_3 ] -> V_223 = V_3 ;
}
V_15 = F_241 ( V_204 , V_185 -> V_203 ) ;
if ( ! V_15 )
goto V_250;
if ( F_242 ( & V_15 -> V_17 , F_15 ,
V_251 , V_204 ) )
goto V_249;
F_243 ( & V_15 -> V_55 , F_110 , ( unsigned long ) V_15 ) ;
F_244 ( V_15 , 30000 ) ;
V_15 -> V_252 = V_146 ;
V_15 -> V_149 = V_185 -> V_149 ;
V_15 -> V_183 = V_6 ;
V_15 -> V_241 = V_10 ;
V_15 -> V_182 = V_247 ;
V_15 -> V_71 = V_185 -> V_106 ;
V_15 -> V_82 |= V_253 ;
if ( ! ( V_185 -> V_87 & V_254 ) )
V_15 -> V_82 |= 1 << V_255 ;
V_15 -> V_256 = V_257 ;
F_245 ( & V_15 -> V_92 , F_86 ) ;
F_34 ( & V_15 -> V_96 ) ;
F_214 ( & V_15 -> V_95 ) ;
if ( V_15 -> V_149 > 1 )
F_246 ( V_15 , F_175 ) ;
else
F_246 ( V_15 , F_180 ) ;
if ( V_185 -> V_55 )
F_244 ( V_15 , V_185 -> V_55 ) ;
V_15 -> V_258 = V_185 -> V_201 ;
if ( V_185 -> V_106 -> V_259 )
F_247 ( V_15 , V_185 -> V_106 -> V_259 ) ;
F_220 ( V_15 , V_185 -> V_149 ) ;
if ( F_219 ( V_15 , V_185 ) )
goto V_260;
F_231 ( & V_261 ) ;
F_98 ( & V_15 -> V_262 , & V_263 ) ;
F_232 ( & V_261 ) ;
F_233 ( V_185 , V_15 ) ;
F_225 ( V_15 ) ;
return V_15 ;
V_260:
F_248 ( V_15 ) ;
V_250:
F_187 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_185 -> V_149 ; V_3 ++ ) {
if ( ! V_247 [ V_3 ] )
break;
F_211 ( V_247 [ V_3 ] -> V_132 ) ;
F_187 ( V_247 [ V_3 ] ) ;
}
V_249:
F_187 ( V_247 ) ;
V_248:
F_249 ( V_10 ) ;
return F_46 ( - V_219 ) ;
}
void F_250 ( struct V_14 * V_15 )
{
struct V_184 * V_185 = V_15 -> V_222 ;
F_230 ( V_15 ) ;
F_209 ( V_15 , V_185 , V_185 -> V_149 ) ;
F_210 ( V_15 , V_185 ) ;
F_251 ( & V_15 -> V_17 ) ;
F_249 ( V_15 -> V_241 ) ;
F_187 ( V_15 -> V_182 ) ;
F_187 ( V_15 -> V_183 ) ;
V_15 -> V_241 = NULL ;
V_15 -> V_182 = NULL ;
V_15 -> V_183 = NULL ;
F_231 ( & V_261 ) ;
F_92 ( & V_15 -> V_262 ) ;
F_232 ( & V_261 ) ;
}
static void F_252 ( struct V_14 * V_15 )
{
F_28 ( ! V_15 -> V_19 ) ;
F_253 ( V_15 ) ;
F_254 ( V_15 -> V_183 , V_15 -> V_149 ) ;
F_225 ( V_15 ) ;
F_255 ( V_15 ) ;
}
static int F_256 ( struct V_264 * V_265 ,
unsigned long V_225 , void * V_266 )
{
struct V_14 * V_15 ;
if ( V_225 != V_226 && V_225 != V_227 &&
V_225 != V_228 && V_225 != V_229 )
return V_221 ;
F_231 ( & V_261 ) ;
F_229 (q, &all_q_list, all_q_node)
F_18 ( V_15 ) ;
F_229 (q, &all_q_list, all_q_node)
F_23 ( V_15 ) ;
F_229 (q, &all_q_list, all_q_node)
F_252 ( V_15 ) ;
F_229 (q, &all_q_list, all_q_node)
F_27 ( V_15 ) ;
F_232 ( & V_261 ) ;
return V_221 ;
}
static int F_257 ( struct V_184 * V_185 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_185 -> V_149 ; V_3 ++ ) {
V_185 -> V_26 [ V_3 ] = F_190 ( V_185 , V_3 ) ;
if ( ! V_185 -> V_26 [ V_3 ] )
goto V_267;
}
return 0 ;
V_267:
while ( -- V_3 >= 0 )
F_185 ( V_185 , V_185 -> V_26 [ V_3 ] , V_3 ) ;
return - V_219 ;
}
static int F_258 ( struct V_184 * V_185 )
{
unsigned int V_127 ;
int V_268 ;
V_127 = V_185 -> V_201 ;
do {
V_268 = F_257 ( V_185 ) ;
if ( ! V_268 )
break;
V_185 -> V_201 >>= 1 ;
if ( V_185 -> V_201 < V_185 -> V_202 + V_269 ) {
V_268 = - V_219 ;
break;
}
} while ( V_185 -> V_201 );
if ( ! V_185 -> V_201 || V_268 ) {
F_133 ( L_3 ) ;
return - V_219 ;
}
if ( V_127 != V_185 -> V_201 )
F_259 ( L_4 ,
V_127 , V_185 -> V_201 ) ;
return 0 ;
}
int F_260 ( struct V_184 * V_185 )
{
if ( ! V_185 -> V_149 )
return - V_270 ;
if ( ! V_185 -> V_201 )
return - V_270 ;
if ( V_185 -> V_201 < V_185 -> V_202 + V_269 )
return - V_270 ;
if ( ! V_185 -> V_149 || ! V_185 -> V_106 -> V_137 || ! V_185 -> V_106 -> V_72 )
return - V_270 ;
if ( V_185 -> V_201 > V_271 ) {
F_259 ( L_5 ,
V_271 ) ;
V_185 -> V_201 = V_271 ;
}
V_185 -> V_26 = F_217 ( V_185 -> V_149 *
sizeof( struct V_103 * ) ,
V_204 , V_185 -> V_203 ) ;
if ( ! V_185 -> V_26 )
return - V_219 ;
if ( F_258 ( V_185 ) )
goto V_272;
F_261 ( & V_185 -> V_245 ) ;
F_34 ( & V_185 -> V_242 ) ;
return 0 ;
V_272:
F_187 ( V_185 -> V_26 ) ;
V_185 -> V_26 = NULL ;
return - V_219 ;
}
void F_262 ( struct V_184 * V_185 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_185 -> V_149 ; V_3 ++ ) {
if ( V_185 -> V_26 [ V_3 ] )
F_185 ( V_185 , V_185 -> V_26 [ V_3 ] , V_3 ) ;
}
F_187 ( V_185 -> V_26 ) ;
V_185 -> V_26 = NULL ;
}
int F_263 ( struct V_14 * V_15 , unsigned int V_273 )
{
struct V_184 * V_185 = V_15 -> V_222 ;
struct V_1 * V_2 ;
int V_3 , V_16 ;
if ( ! V_185 || V_273 > V_185 -> V_201 )
return - V_270 ;
V_16 = 0 ;
F_111 (q, hctx, i) {
V_16 = F_264 ( V_2 -> V_26 , V_273 ) ;
if ( V_16 )
break;
}
if ( ! V_16 )
V_15 -> V_258 = V_273 ;
return V_16 ;
}
void F_265 ( void )
{
F_231 ( & V_261 ) ;
}
void F_266 ( void )
{
F_232 ( & V_261 ) ;
}
static int T_4 F_267 ( void )
{
F_268 () ;
F_269 ( F_256 , 0 ) ;
return 0 ;
}
