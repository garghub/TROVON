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
! F_12 ( & V_15 -> V_22 ) ||
F_13 ( V_15 ) ) ;
if ( F_13 ( V_15 ) )
return - V_23 ;
if ( V_17 )
return V_17 ;
}
}
static void F_14 ( struct V_14 * V_15 )
{
F_15 ( & V_15 -> V_18 ) ;
}
static void F_16 ( struct V_24 * V_25 )
{
struct V_14 * V_15 =
F_17 ( V_25 , struct V_14 , V_18 ) ;
F_18 ( & V_15 -> V_21 ) ;
}
void F_19 ( struct V_14 * V_15 )
{
int V_26 ;
V_26 = F_20 ( & V_15 -> V_22 ) ;
if ( V_26 == 1 ) {
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
F_19 ( V_15 ) ;
F_23 ( V_15 ) ;
}
void F_27 ( struct V_14 * V_15 )
{
int V_26 ;
V_26 = F_28 ( & V_15 -> V_22 ) ;
F_29 ( V_26 < 0 ) ;
if ( ! V_26 ) {
F_30 ( & V_15 -> V_18 ) ;
F_18 ( & V_15 -> V_21 ) ;
}
}
void F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i)
if ( F_33 ( V_2 ) )
F_34 ( V_2 -> V_27 , true ) ;
F_18 ( & V_15 -> V_21 ) ;
}
bool F_35 ( struct V_1 * V_2 )
{
return F_36 ( V_2 -> V_27 ) ;
}
static void F_37 ( struct V_14 * V_15 , struct V_9 * V_10 ,
struct V_28 * V_29 , unsigned int V_30 )
{
if ( F_38 ( V_15 ) )
V_30 |= V_31 ;
F_39 ( & V_29 -> V_32 ) ;
V_29 -> V_15 = V_15 ;
V_29 -> V_33 = V_10 ;
V_29 -> V_34 |= V_30 ;
V_29 -> V_35 = - 1 ;
F_40 ( & V_29 -> V_36 ) ;
F_41 ( & V_29 -> V_37 ) ;
V_29 -> V_38 = NULL ;
V_29 -> V_39 = NULL ;
V_29 -> V_40 = V_41 ;
#ifdef F_42
V_29 -> V_42 = NULL ;
F_43 ( V_29 ) ;
V_29 -> V_43 = 0 ;
#endif
V_29 -> V_44 = 0 ;
#if F_44 ( V_45 )
V_29 -> V_46 = 0 ;
#endif
V_29 -> V_47 = NULL ;
V_29 -> V_48 = 0 ;
V_29 -> V_49 = V_29 -> V_50 ;
V_29 -> V_51 = 0 ;
V_29 -> V_52 = 0 ;
V_29 -> V_53 = 0 ;
V_29 -> V_54 = NULL ;
F_39 ( & V_29 -> V_55 ) ;
V_29 -> V_56 = 0 ;
V_29 -> V_57 = NULL ;
V_29 -> V_58 = NULL ;
V_29 -> V_59 = NULL ;
V_10 -> V_60 [ F_45 ( V_30 ) ] ++ ;
}
static struct V_28 *
F_46 ( struct V_61 * V_62 , int V_63 )
{
struct V_28 * V_29 ;
unsigned int V_64 ;
V_64 = F_47 ( V_62 ) ;
if ( V_64 != V_65 ) {
V_29 = V_62 -> V_2 -> V_27 -> V_66 [ V_64 ] ;
if ( F_48 ( V_62 -> V_2 ) ) {
V_29 -> V_34 = V_67 ;
F_49 ( & V_62 -> V_2 -> V_68 ) ;
}
V_29 -> V_64 = V_64 ;
F_37 ( V_62 -> V_15 , V_62 -> V_10 , V_29 , V_63 ) ;
return V_29 ;
}
return NULL ;
}
struct V_28 * F_50 ( struct V_14 * V_15 , int V_63 , T_1 V_16 ,
bool V_69 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_61 V_70 ;
int V_17 ;
V_17 = F_9 ( V_15 , V_16 ) ;
if ( V_17 )
return F_51 ( V_17 ) ;
V_10 = F_52 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_53 ( & V_70 , V_15 , V_16 & ~ V_19 ,
V_69 , V_10 , V_2 ) ;
V_29 = F_46 ( & V_70 , V_63 ) ;
if ( ! V_29 && ( V_16 & V_19 ) ) {
F_54 ( V_2 ) ;
F_55 ( V_10 ) ;
V_10 = F_52 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_53 ( & V_70 , V_15 , V_16 , V_69 , V_10 ,
V_2 ) ;
V_29 = F_46 ( & V_70 , V_63 ) ;
V_10 = V_70 . V_10 ;
}
F_55 ( V_10 ) ;
if ( ! V_29 ) {
F_14 ( V_15 ) ;
return F_51 ( - V_73 ) ;
}
return V_29 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_28 * V_29 )
{
const int V_64 = V_29 -> V_64 ;
struct V_14 * V_15 = V_29 -> V_15 ;
if ( V_29 -> V_34 & V_67 )
F_57 ( & V_2 -> V_68 ) ;
V_29 -> V_34 = 0 ;
F_8 ( V_74 , & V_29 -> V_75 ) ;
F_58 ( V_2 , V_64 , & V_10 -> V_76 ) ;
F_14 ( V_15 ) ;
}
void F_59 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_33 ;
V_10 -> V_77 [ F_60 ( V_29 ) ] ++ ;
F_56 ( V_2 , V_10 , V_29 ) ;
}
void F_61 ( struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = V_29 -> V_15 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_29 -> V_33 -> V_35 ) ;
F_59 ( V_2 , V_29 ) ;
}
inline void F_62 ( struct V_28 * V_29 , int error )
{
F_63 ( V_29 ) ;
if ( V_29 -> V_57 ) {
V_29 -> V_57 ( V_29 , error ) ;
} else {
if ( F_64 ( F_65 ( V_29 ) ) )
F_61 ( V_29 -> V_59 ) ;
F_61 ( V_29 ) ;
}
}
void F_66 ( struct V_28 * V_29 , int error )
{
if ( F_67 ( V_29 , error , F_68 ( V_29 ) ) )
F_69 () ;
F_62 ( V_29 , error ) ;
}
static void F_70 ( void * V_62 )
{
struct V_28 * V_29 = V_62 ;
V_29 -> V_15 -> V_78 ( V_29 ) ;
}
static void F_71 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_33 ;
bool V_79 = false ;
int V_35 ;
if ( ! F_4 ( V_80 , & V_29 -> V_15 -> V_81 ) ) {
V_29 -> V_15 -> V_78 ( V_29 ) ;
return;
}
V_35 = F_72 () ;
if ( ! F_4 ( V_82 , & V_29 -> V_15 -> V_81 ) )
V_79 = F_73 ( V_35 , V_10 -> V_35 ) ;
if ( V_35 != V_10 -> V_35 && ! V_79 && F_74 ( V_10 -> V_35 ) ) {
V_29 -> V_83 . V_84 = F_70 ;
V_29 -> V_83 . V_85 = V_29 ;
V_29 -> V_83 . V_86 = 0 ;
F_75 ( V_10 -> V_35 , & V_29 -> V_83 ) ;
} else {
V_29 -> V_15 -> V_78 ( V_29 ) ;
}
F_76 () ;
}
void F_77 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_15 ;
if ( ! V_15 -> V_78 )
F_66 ( V_29 , V_29 -> V_48 ) ;
else
F_71 ( V_29 ) ;
}
void F_78 ( struct V_28 * V_29 , int error )
{
struct V_14 * V_15 = V_29 -> V_15 ;
if ( F_64 ( F_79 ( V_15 ) ) )
return;
if ( ! F_80 ( V_29 ) ) {
V_29 -> V_48 = error ;
F_77 ( V_29 ) ;
}
}
int F_81 ( struct V_28 * V_29 )
{
return F_4 ( V_74 , & V_29 -> V_75 ) ;
}
void F_82 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_15 ;
F_83 ( V_15 , V_29 ) ;
V_29 -> V_53 = F_68 ( V_29 ) ;
if ( F_64 ( F_65 ( V_29 ) ) )
V_29 -> V_59 -> V_53 = F_68 ( V_29 -> V_59 ) ;
F_84 ( V_29 ) ;
F_85 () ;
if ( ! F_4 ( V_74 , & V_29 -> V_75 ) )
F_6 ( V_74 , & V_29 -> V_75 ) ;
if ( F_4 ( V_87 , & V_29 -> V_75 ) )
F_8 ( V_87 , & V_29 -> V_75 ) ;
if ( V_15 -> V_88 && F_68 ( V_29 ) ) {
V_29 -> V_44 ++ ;
}
}
static void F_86 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_15 ;
F_87 ( V_15 , V_29 ) ;
if ( F_88 ( V_74 , & V_29 -> V_75 ) ) {
if ( V_15 -> V_88 && F_68 ( V_29 ) )
V_29 -> V_44 -- ;
}
}
void F_89 ( struct V_28 * V_29 )
{
F_86 ( V_29 ) ;
F_90 ( F_91 ( V_29 ) ) ;
F_92 ( V_29 , true ) ;
}
static void F_93 ( struct V_89 * V_90 )
{
struct V_14 * V_15 =
F_17 ( V_90 , struct V_14 , V_91 ) ;
F_94 ( V_92 ) ;
struct V_28 * V_29 , * V_93 ;
unsigned long V_86 ;
F_95 ( & V_15 -> V_94 , V_86 ) ;
F_96 ( & V_15 -> V_95 , & V_92 ) ;
F_97 ( & V_15 -> V_94 , V_86 ) ;
F_98 (rq, next, &rq_list, queuelist) {
if ( ! ( V_29 -> V_34 & V_96 ) )
continue;
V_29 -> V_34 &= ~ V_96 ;
F_99 ( & V_29 -> V_32 ) ;
F_100 ( V_29 , true , false , false ) ;
}
while ( ! F_101 ( & V_92 ) ) {
V_29 = F_102 ( V_92 . V_93 , struct V_28 , V_32 ) ;
F_99 ( & V_29 -> V_32 ) ;
F_100 ( V_29 , false , false , false ) ;
}
F_103 ( V_15 ) ;
}
void F_92 ( struct V_28 * V_29 , bool V_97 )
{
struct V_14 * V_15 = V_29 -> V_15 ;
unsigned long V_86 ;
F_90 ( V_29 -> V_34 & V_96 ) ;
F_95 ( & V_15 -> V_94 , V_86 ) ;
if ( V_97 ) {
V_29 -> V_34 |= V_96 ;
F_104 ( & V_29 -> V_32 , & V_15 -> V_95 ) ;
} else {
F_105 ( & V_29 -> V_32 , & V_15 -> V_95 ) ;
}
F_97 ( & V_15 -> V_94 , V_86 ) ;
}
void F_106 ( struct V_14 * V_15 )
{
F_107 ( & V_15 -> V_91 ) ;
}
void F_108 ( struct V_14 * V_15 )
{
F_109 ( & V_15 -> V_91 ) ;
}
void F_110 ( struct V_14 * V_15 )
{
unsigned long V_86 ;
F_94 ( V_92 ) ;
F_95 ( & V_15 -> V_94 , V_86 ) ;
F_96 ( & V_15 -> V_95 , & V_92 ) ;
F_97 ( & V_15 -> V_94 , V_86 ) ;
while ( ! F_101 ( & V_92 ) ) {
struct V_28 * V_29 ;
V_29 = F_111 ( & V_92 , struct V_28 , V_32 ) ;
F_99 ( & V_29 -> V_32 ) ;
V_29 -> V_48 = - V_98 ;
F_66 ( V_29 , V_29 -> V_48 ) ;
}
}
struct V_28 * F_112 ( struct V_99 * V_27 , unsigned int V_64 )
{
return V_27 -> V_66 [ V_64 ] ;
}
void F_113 ( struct V_28 * V_100 , bool V_69 )
{
struct V_101 * V_102 = V_100 -> V_15 -> V_71 ;
enum V_103 V_17 = V_104 ;
if ( ! F_4 ( V_74 , & V_100 -> V_75 ) )
return;
if ( V_102 -> V_56 )
V_17 = V_102 -> V_56 ( V_100 , V_69 ) ;
switch ( V_17 ) {
case V_105 :
F_77 ( V_100 ) ;
break;
case V_104 :
F_84 ( V_100 ) ;
F_114 ( V_100 ) ;
break;
case V_106 :
break;
default:
F_115 ( V_107 L_1 , V_17 ) ;
break;
}
}
static void F_116 ( struct V_1 * V_2 ,
struct V_28 * V_29 , void * V_108 , bool V_69 )
{
struct V_109 * V_62 = V_108 ;
if ( ! F_4 ( V_74 , & V_29 -> V_75 ) ) {
if ( F_64 ( F_13 ( V_29 -> V_15 ) ) )
F_78 ( V_29 , - V_98 ) ;
return;
}
if ( V_29 -> V_34 & V_110 )
return;
if ( F_117 ( V_41 , V_29 -> V_111 ) ) {
if ( ! F_80 ( V_29 ) )
F_113 ( V_29 , V_69 ) ;
} else if ( ! V_62 -> V_112 || F_118 ( V_62 -> V_93 , V_29 -> V_111 ) ) {
V_62 -> V_93 = V_29 -> V_111 ;
V_62 -> V_112 = 1 ;
}
}
static void F_119 ( unsigned long V_108 )
{
struct V_14 * V_15 = (struct V_14 * ) V_108 ;
struct V_109 V_62 = {
. V_93 = 0 ,
. V_112 = 0 ,
} ;
int V_3 ;
F_120 ( V_15 , F_116 , & V_62 ) ;
if ( V_62 . V_112 ) {
V_62 . V_93 = F_121 ( F_122 ( V_62 . V_93 ) ) ;
F_123 ( & V_15 -> V_56 , V_62 . V_93 ) ;
} else {
struct V_1 * V_2 ;
F_32 (q, hctx, i) {
if ( F_33 ( V_2 ) )
F_124 ( V_2 ) ;
}
}
}
static bool F_125 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_113 * V_113 )
{
struct V_28 * V_29 ;
int V_114 = 8 ;
F_126 (rq, &ctx->rq_list, queuelist) {
int V_115 ;
if ( ! V_114 -- )
break;
if ( ! F_127 ( V_29 , V_113 ) )
continue;
V_115 = F_128 ( V_29 , V_113 ) ;
if ( V_115 == V_116 ) {
if ( F_129 ( V_15 , V_29 , V_113 ) ) {
V_10 -> V_117 ++ ;
return true ;
}
break;
} else if ( V_115 == V_118 ) {
if ( F_130 ( V_15 , V_29 , V_113 ) ) {
V_10 -> V_117 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_131 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
struct V_9 * V_10 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_8 * V_13 = & V_2 -> V_4 . V_6 [ V_3 ] ;
unsigned int V_121 , V_122 ;
if ( ! V_13 -> V_7 )
continue;
V_122 = 0 ;
V_121 = V_3 * V_2 -> V_4 . V_12 ;
do {
V_122 = F_132 ( & V_13 -> V_7 , V_13 -> V_123 , V_122 ) ;
if ( V_122 >= V_13 -> V_123 )
break;
V_10 = V_2 -> V_124 [ V_122 + V_121 ] ;
F_8 ( V_122 , & V_13 -> V_7 ) ;
F_133 ( & V_10 -> V_125 ) ;
F_134 ( & V_10 -> V_92 , V_120 ) ;
F_135 ( & V_10 -> V_125 ) ;
V_122 ++ ;
} while ( 1 );
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_126 ;
struct V_28 * V_29 ;
F_94 ( V_92 ) ;
F_94 ( V_127 ) ;
struct V_119 * V_128 ;
int V_129 ;
F_136 ( ! F_137 ( F_138 () , V_2 -> V_130 ) ) ;
if ( F_64 ( F_4 ( V_131 , & V_2 -> V_132 ) ) )
return;
V_2 -> V_133 ++ ;
F_131 ( V_2 , & V_92 ) ;
if ( ! F_139 ( & V_2 -> V_134 ) ) {
F_133 ( & V_2 -> V_125 ) ;
if ( ! F_101 ( & V_2 -> V_134 ) )
F_96 ( & V_2 -> V_134 , & V_92 ) ;
F_135 ( & V_2 -> V_125 ) ;
}
V_128 = NULL ;
V_129 = 0 ;
while ( ! F_101 ( & V_92 ) ) {
struct V_135 V_136 ;
int V_17 ;
V_29 = F_111 ( & V_92 , struct V_28 , V_32 ) ;
F_99 ( & V_29 -> V_32 ) ;
V_136 . V_29 = V_29 ;
V_136 . V_120 = V_128 ;
V_136 . V_137 = F_101 ( & V_92 ) ;
V_17 = V_15 -> V_71 -> V_138 ( V_2 , & V_136 ) ;
switch ( V_17 ) {
case V_139 :
V_129 ++ ;
continue;
case V_140 :
F_104 ( & V_29 -> V_32 , & V_92 ) ;
F_86 ( V_29 ) ;
break;
default:
F_140 ( L_2 , V_17 ) ;
case V_141 :
V_29 -> V_48 = - V_98 ;
F_66 ( V_29 , V_29 -> V_48 ) ;
break;
}
if ( V_17 == V_140 )
break;
if ( ! V_128 && V_92 . V_93 != V_92 . V_142 )
V_128 = & V_127 ;
}
if ( ! V_129 )
V_2 -> V_143 [ 0 ] ++ ;
else if ( V_129 < ( 1 << ( V_144 - 1 ) ) )
V_2 -> V_143 [ F_141 ( V_129 ) + 1 ] ++ ;
if ( ! F_101 ( & V_92 ) ) {
F_133 ( & V_2 -> V_125 ) ;
F_142 ( & V_92 , & V_2 -> V_134 ) ;
F_135 ( & V_2 -> V_125 ) ;
F_143 ( V_2 , true ) ;
}
}
static int F_144 ( struct V_1 * V_2 )
{
if ( V_2 -> V_126 -> V_145 == 1 )
return V_146 ;
if ( -- V_2 -> V_147 <= 0 ) {
int V_35 = V_2 -> V_148 , V_148 ;
V_148 = F_145 ( V_2 -> V_148 , V_2 -> V_130 ) ;
if ( V_148 >= V_149 )
V_148 = F_146 ( V_2 -> V_130 ) ;
V_2 -> V_148 = V_148 ;
V_2 -> V_147 = V_150 ;
return V_35 ;
}
return V_2 -> V_148 ;
}
void F_143 ( struct V_1 * V_2 , bool V_151 )
{
if ( F_64 ( F_4 ( V_131 , & V_2 -> V_132 ) ||
! F_33 ( V_2 ) ) )
return;
if ( ! V_151 ) {
int V_35 = F_72 () ;
if ( F_137 ( V_35 , V_2 -> V_130 ) ) {
F_54 ( V_2 ) ;
F_76 () ;
return;
}
F_76 () ;
}
F_147 ( F_144 ( V_2 ) ,
& V_2 -> V_152 , 0 ) ;
}
void F_22 ( struct V_14 * V_15 , bool V_151 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_139 ( & V_2 -> V_134 ) ) ||
F_4 ( V_131 , & V_2 -> V_132 ) )
continue;
F_143 ( V_2 , V_151 ) ;
}
}
void F_148 ( struct V_1 * V_2 )
{
F_149 ( & V_2 -> V_152 ) ;
F_149 ( & V_2 -> V_153 ) ;
F_6 ( V_131 , & V_2 -> V_132 ) ;
}
void F_150 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i)
F_148 ( V_2 ) ;
}
void F_151 ( struct V_1 * V_2 )
{
F_8 ( V_131 , & V_2 -> V_132 ) ;
F_143 ( V_2 , false ) ;
}
void F_103 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i)
F_151 ( V_2 ) ;
}
void F_152 ( struct V_14 * V_15 , bool V_151 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i) {
if ( ! F_4 ( V_131 , & V_2 -> V_132 ) )
continue;
F_8 ( V_131 , & V_2 -> V_132 ) ;
F_143 ( V_2 , V_151 ) ;
}
}
static void F_153 ( struct V_89 * V_90 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_90 , struct V_1 , V_152 . V_90 ) ;
F_54 ( V_2 ) ;
}
static void F_154 ( struct V_89 * V_90 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_90 , struct V_1 , V_153 . V_90 ) ;
if ( F_88 ( V_131 , & V_2 -> V_132 ) )
F_54 ( V_2 ) ;
}
void F_155 ( struct V_1 * V_2 , unsigned long V_154 )
{
if ( F_64 ( ! F_33 ( V_2 ) ) )
return;
F_147 ( F_144 ( V_2 ) ,
& V_2 -> V_153 , F_156 ( V_154 ) ) ;
}
static void F_157 ( struct V_1 * V_2 ,
struct V_28 * V_29 , bool V_97 )
{
struct V_9 * V_10 = V_29 -> V_33 ;
F_158 ( V_2 -> V_126 , V_29 ) ;
if ( V_97 )
F_104 ( & V_29 -> V_32 , & V_10 -> V_92 ) ;
else
F_105 ( & V_29 -> V_32 , & V_10 -> V_92 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_100 ( struct V_28 * V_29 , bool V_97 , bool V_155 ,
bool V_151 )
{
struct V_14 * V_15 = V_29 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_29 -> V_33 , * V_156 ;
V_156 = F_52 ( V_15 ) ;
if ( ! F_74 ( V_10 -> V_35 ) )
V_29 -> V_33 = V_10 = V_156 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_133 ( & V_10 -> V_125 ) ;
F_157 ( V_2 , V_29 , V_97 ) ;
F_135 ( & V_10 -> V_125 ) ;
if ( V_155 )
F_143 ( V_2 , V_151 ) ;
F_55 ( V_156 ) ;
}
static void F_159 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_119 * V_120 ,
int V_123 ,
bool V_157 )
{
struct V_1 * V_2 ;
struct V_9 * V_156 ;
F_160 ( V_15 , V_123 , ! V_157 ) ;
V_156 = F_52 ( V_15 ) ;
if ( ! F_74 ( V_10 -> V_35 ) )
V_10 = V_156 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_133 ( & V_10 -> V_125 ) ;
while ( ! F_101 ( V_120 ) ) {
struct V_28 * V_29 ;
V_29 = F_111 ( V_120 , struct V_28 , V_32 ) ;
F_99 ( & V_29 -> V_32 ) ;
V_29 -> V_33 = V_10 ;
F_157 ( V_2 , V_29 , false ) ;
}
F_135 ( & V_10 -> V_125 ) ;
F_143 ( V_2 , V_157 ) ;
F_55 ( V_156 ) ;
}
static int F_161 ( void * V_108 , struct V_119 * V_158 , struct V_119 * V_159 )
{
struct V_28 * V_160 = F_17 ( V_158 , struct V_28 , V_32 ) ;
struct V_28 * V_161 = F_17 ( V_159 , struct V_28 , V_32 ) ;
return ! ( V_160 -> V_33 < V_161 -> V_33 ||
( V_160 -> V_33 == V_161 -> V_33 &&
F_162 ( V_160 ) < F_162 ( V_161 ) ) ) ;
}
void F_163 ( struct V_162 * V_163 , bool V_157 )
{
struct V_9 * V_164 ;
struct V_14 * V_165 ;
struct V_28 * V_29 ;
F_94 ( V_120 ) ;
F_94 ( V_166 ) ;
unsigned int V_123 ;
F_96 ( & V_163 -> V_167 , & V_120 ) ;
F_164 ( NULL , & V_120 , F_161 ) ;
V_165 = NULL ;
V_164 = NULL ;
V_123 = 0 ;
while ( ! F_101 ( & V_120 ) ) {
V_29 = F_165 ( V_120 . V_93 ) ;
F_99 ( & V_29 -> V_32 ) ;
F_90 ( ! V_29 -> V_15 ) ;
if ( V_29 -> V_33 != V_164 ) {
if ( V_164 ) {
F_159 ( V_165 , V_164 ,
& V_166 , V_123 ,
V_157 ) ;
}
V_164 = V_29 -> V_33 ;
V_165 = V_29 -> V_15 ;
V_123 = 0 ;
}
V_123 ++ ;
F_105 ( & V_29 -> V_32 , & V_166 ) ;
}
if ( V_164 ) {
F_159 ( V_165 , V_164 , & V_166 , V_123 ,
V_157 ) ;
}
}
static void F_166 ( struct V_28 * V_29 , struct V_113 * V_113 )
{
F_167 ( V_29 , V_113 ) ;
if ( F_168 ( V_29 ) )
F_169 ( V_29 , 1 ) ;
}
static inline bool F_170 ( struct V_1 * V_2 )
{
return ( V_2 -> V_86 & V_168 ) &&
! F_171 ( V_2 -> V_126 ) ;
}
static inline bool F_172 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_28 * V_29 , struct V_113 * V_113 )
{
if ( ! F_170 ( V_2 ) ) {
F_166 ( V_29 , V_113 ) ;
F_133 ( & V_10 -> V_125 ) ;
V_169:
F_157 ( V_2 , V_29 , false ) ;
F_135 ( & V_10 -> V_125 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_126 ;
F_133 ( & V_10 -> V_125 ) ;
if ( ! F_125 ( V_15 , V_10 , V_113 ) ) {
F_166 ( V_29 , V_113 ) ;
goto V_169;
}
F_135 ( & V_10 -> V_125 ) ;
F_56 ( V_2 , V_10 , V_29 ) ;
return true ;
}
}
static struct V_28 * F_173 ( struct V_14 * V_15 ,
struct V_113 * V_113 ,
struct V_170 * V_62 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_28 * V_29 ;
int V_63 = F_174 ( V_113 ) ;
struct V_61 V_70 ;
if ( F_64 ( F_9 ( V_15 , V_171 ) ) ) {
F_175 ( V_113 ) ;
return NULL ;
}
V_10 = F_52 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
if ( F_45 ( V_113 -> V_172 ) )
V_63 |= V_173 ;
F_176 ( V_15 , V_113 , V_63 ) ;
F_53 ( & V_70 , V_15 , V_174 , false , V_10 ,
V_2 ) ;
V_29 = F_46 ( & V_70 , V_63 ) ;
if ( F_64 ( ! V_29 ) ) {
F_54 ( V_2 ) ;
F_55 ( V_10 ) ;
F_177 ( V_15 , V_113 , V_63 ) ;
V_10 = F_52 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_53 ( & V_70 , V_15 ,
V_19 | V_174 , false , V_10 , V_2 ) ;
V_29 = F_46 ( & V_70 , V_63 ) ;
V_10 = V_70 . V_10 ;
V_2 = V_70 . V_2 ;
}
V_2 -> V_129 ++ ;
V_62 -> V_2 = V_2 ;
V_62 -> V_10 = V_10 ;
return V_29 ;
}
static int F_178 ( struct V_28 * V_29 )
{
int V_17 ;
struct V_14 * V_15 = V_29 -> V_15 ;
struct V_1 * V_2 = V_15 -> V_71 -> V_72 ( V_15 ,
V_29 -> V_33 -> V_35 ) ;
struct V_135 V_136 = {
. V_29 = V_29 ,
. V_120 = NULL ,
. V_137 = 1
} ;
V_17 = V_15 -> V_71 -> V_138 ( V_2 , & V_136 ) ;
if ( V_17 == V_139 )
return 0 ;
else {
F_86 ( V_29 ) ;
if ( V_17 == V_141 ) {
V_29 -> V_48 = - V_98 ;
F_66 ( V_29 , V_29 -> V_48 ) ;
return 0 ;
}
return - 1 ;
}
}
static void F_179 ( struct V_14 * V_15 , struct V_113 * V_113 )
{
const int V_175 = F_45 ( V_113 -> V_172 ) ;
const int V_176 = V_113 -> V_172 & ( V_177 | V_178 ) ;
struct V_170 V_62 ;
struct V_28 * V_29 ;
unsigned int V_179 = 0 ;
struct V_162 * V_163 ;
struct V_28 * V_180 = NULL ;
F_180 ( V_15 , & V_113 ) ;
if ( F_181 ( V_113 ) && F_182 ( V_113 ) ) {
F_175 ( V_113 ) ;
return;
}
F_183 ( V_15 , & V_113 , V_15 -> V_181 ) ;
if ( ! V_176 && ! F_171 ( V_15 ) &&
F_184 ( V_15 , V_113 , & V_179 , & V_180 ) )
return;
V_29 = F_173 ( V_15 , V_113 , & V_62 ) ;
if ( F_64 ( ! V_29 ) )
return;
if ( F_64 ( V_176 ) ) {
F_166 ( V_29 , V_113 ) ;
F_185 ( V_29 ) ;
goto V_155;
}
V_163 = V_182 -> V_163 ;
if ( ( ( V_163 && ! F_171 ( V_15 ) ) || V_175 ) &&
! ( V_62 . V_2 -> V_86 & V_183 ) ) {
struct V_28 * V_184 = NULL ;
F_166 ( V_29 , V_113 ) ;
if ( V_163 ) {
if ( V_180 && ! F_101 ( & V_163 -> V_167 ) ) {
V_184 = V_180 ;
F_99 ( & V_184 -> V_32 ) ;
}
F_105 ( & V_29 -> V_32 , & V_163 -> V_167 ) ;
} else
V_184 = V_29 ;
F_55 ( V_62 . V_10 ) ;
if ( ! V_184 )
return;
if ( ! F_178 ( V_184 ) )
return;
F_100 ( V_184 , false , true , true ) ;
return;
}
if ( ! F_172 ( V_62 . V_2 , V_62 . V_10 , V_29 , V_113 ) ) {
V_155:
F_143 ( V_62 . V_2 , ! V_175 || V_176 ) ;
}
F_55 ( V_62 . V_10 ) ;
}
static void F_186 ( struct V_14 * V_15 , struct V_113 * V_113 )
{
const int V_175 = F_45 ( V_113 -> V_172 ) ;
const int V_176 = V_113 -> V_172 & ( V_177 | V_178 ) ;
struct V_162 * V_163 ;
unsigned int V_179 = 0 ;
struct V_170 V_62 ;
struct V_28 * V_29 ;
F_180 ( V_15 , & V_113 ) ;
if ( F_181 ( V_113 ) && F_182 ( V_113 ) ) {
F_175 ( V_113 ) ;
return;
}
F_183 ( V_15 , & V_113 , V_15 -> V_181 ) ;
if ( ! V_176 && ! F_171 ( V_15 ) &&
F_184 ( V_15 , V_113 , & V_179 , NULL ) )
return;
V_29 = F_173 ( V_15 , V_113 , & V_62 ) ;
if ( F_64 ( ! V_29 ) )
return;
if ( F_64 ( V_176 ) ) {
F_166 ( V_29 , V_113 ) ;
F_185 ( V_29 ) ;
goto V_155;
}
V_163 = V_182 -> V_163 ;
if ( V_163 ) {
F_166 ( V_29 , V_113 ) ;
if ( F_101 ( & V_163 -> V_167 ) )
F_187 ( V_15 ) ;
else if ( V_179 >= V_185 ) {
F_188 ( V_163 , false ) ;
F_187 ( V_15 ) ;
}
F_105 ( & V_29 -> V_32 , & V_163 -> V_167 ) ;
F_55 ( V_62 . V_10 ) ;
return;
}
if ( ! F_172 ( V_62 . V_2 , V_62 . V_10 , V_29 , V_113 ) ) {
V_155:
F_143 ( V_62 . V_2 , ! V_175 || V_176 ) ;
}
F_55 ( V_62 . V_10 ) ;
}
struct V_1 * F_189 ( struct V_14 * V_15 , const int V_35 )
{
return V_15 -> V_186 [ V_15 -> V_187 [ V_35 ] ] ;
}
static void F_190 ( struct V_188 * V_189 ,
struct V_99 * V_27 , unsigned int V_190 )
{
struct V_191 * V_191 ;
if ( V_27 -> V_66 && V_189 -> V_102 -> V_192 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_193 ; V_3 ++ ) {
if ( ! V_27 -> V_66 [ V_3 ] )
continue;
V_189 -> V_102 -> V_192 ( V_189 -> V_194 , V_27 -> V_66 [ V_3 ] ,
V_190 , V_3 ) ;
V_27 -> V_66 [ V_3 ] = NULL ;
}
}
while ( ! F_101 ( & V_27 -> V_195 ) ) {
V_191 = F_111 ( & V_27 -> V_195 , struct V_191 , V_196 ) ;
F_99 ( & V_191 -> V_196 ) ;
F_191 ( V_191 , V_191 -> V_197 ) ;
}
F_192 ( V_27 -> V_66 ) ;
F_193 ( V_27 ) ;
}
static T_2 F_194 ( unsigned int V_198 )
{
return ( T_2 ) V_199 << V_198 ;
}
static struct V_99 * F_195 ( struct V_188 * V_189 ,
unsigned int V_190 )
{
struct V_99 * V_27 ;
unsigned int V_3 , V_200 , V_201 , V_202 = 4 ;
T_2 V_203 , V_204 ;
V_27 = F_196 ( V_189 -> V_205 , V_189 -> V_206 ,
V_189 -> V_207 ,
F_197 ( V_189 -> V_86 ) ) ;
if ( ! V_27 )
return NULL ;
F_39 ( & V_27 -> V_195 ) ;
V_27 -> V_66 = F_198 ( V_189 -> V_205 * sizeof( struct V_28 * ) ,
V_171 | V_208 | V_209 ,
V_189 -> V_207 ) ;
if ( ! V_27 -> V_66 ) {
F_193 ( V_27 ) ;
return NULL ;
}
V_203 = F_199 ( sizeof( struct V_28 ) + V_189 -> V_210 ,
F_200 () ) ;
V_204 = V_203 * V_189 -> V_205 ;
for ( V_3 = 0 ; V_3 < V_189 -> V_205 ; ) {
int V_211 = V_202 ;
struct V_191 * V_191 ;
int V_212 ;
void * V_213 ;
while ( V_204 < F_194 ( V_211 - 1 ) && V_211 )
V_211 -- ;
do {
V_191 = F_201 ( V_189 -> V_207 ,
V_171 | V_208 | V_209 | V_214 ,
V_211 ) ;
if ( V_191 )
break;
if ( ! V_211 -- )
break;
if ( F_194 ( V_211 ) < V_203 )
break;
} while ( 1 );
if ( ! V_191 )
goto V_215;
V_191 -> V_197 = V_211 ;
F_105 ( & V_191 -> V_196 , & V_27 -> V_195 ) ;
V_213 = F_202 ( V_191 ) ;
V_201 = F_194 ( V_211 ) / V_203 ;
V_212 = F_203 ( V_201 , V_189 -> V_205 - V_3 ) ;
V_204 -= V_212 * V_203 ;
for ( V_200 = 0 ; V_200 < V_212 ; V_200 ++ ) {
V_27 -> V_66 [ V_3 ] = V_213 ;
if ( V_189 -> V_102 -> V_216 ) {
if ( V_189 -> V_102 -> V_216 ( V_189 -> V_194 ,
V_27 -> V_66 [ V_3 ] , V_190 , V_3 ,
V_189 -> V_207 ) ) {
V_27 -> V_66 [ V_3 ] = NULL ;
goto V_215;
}
}
V_213 += V_203 ;
V_3 ++ ;
}
}
return V_27 ;
V_215:
F_190 ( V_189 , V_27 , V_190 ) ;
return NULL ;
}
static void F_204 ( struct V_217 * V_218 )
{
F_192 ( V_218 -> V_6 ) ;
}
static int F_205 ( struct V_217 * V_218 , int V_219 )
{
unsigned int V_220 = 8 , V_221 , V_222 , V_3 ;
V_218 -> V_12 = V_220 ;
V_222 = F_206 ( V_149 , V_220 ) / V_220 ;
V_218 -> V_6 = F_198 ( V_222 * sizeof( struct V_8 ) ,
V_171 , V_219 ) ;
if ( ! V_218 -> V_6 )
return - V_223 ;
V_221 = V_149 ;
for ( V_3 = 0 ; V_3 < V_222 ; V_3 ++ ) {
V_218 -> V_6 [ V_3 ] . V_123 = F_203 ( V_221 , V_218 -> V_12 ) ;
V_221 -= V_218 -> V_6 [ V_3 ] . V_123 ;
}
return 0 ;
}
static int F_207 ( struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_15 = V_2 -> V_126 ;
struct V_9 * V_10 ;
F_94 ( V_224 ) ;
V_10 = F_208 ( V_15 , V_35 ) ;
F_133 ( & V_10 -> V_125 ) ;
if ( ! F_101 ( & V_10 -> V_92 ) ) {
F_96 ( & V_10 -> V_92 , & V_224 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_135 ( & V_10 -> V_125 ) ;
if ( F_101 ( & V_224 ) )
return V_225 ;
V_10 = F_52 ( V_15 ) ;
F_133 ( & V_10 -> V_125 ) ;
while ( ! F_101 ( & V_224 ) ) {
struct V_28 * V_29 ;
V_29 = F_111 ( & V_224 , struct V_28 , V_32 ) ;
V_29 -> V_33 = V_10 ;
F_209 ( & V_29 -> V_32 , & V_10 -> V_92 ) ;
}
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_3 ( V_2 , V_10 ) ;
F_135 ( & V_10 -> V_125 ) ;
F_143 ( V_2 , true ) ;
F_55 ( V_10 ) ;
return V_225 ;
}
static int F_210 ( void * V_62 , unsigned long V_226 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_62 ;
if ( V_226 == V_227 || V_226 == V_228 )
return F_207 ( V_2 , V_35 ) ;
return V_225 ;
}
static void F_211 ( struct V_14 * V_15 ,
struct V_188 * V_189 ,
struct V_1 * V_2 , unsigned int V_190 )
{
unsigned V_229 = V_189 -> V_205 ;
F_124 ( V_2 ) ;
if ( V_189 -> V_102 -> V_192 )
V_189 -> V_102 -> V_192 ( V_189 -> V_194 ,
V_2 -> V_230 -> V_231 , V_190 ,
V_229 + V_190 ) ;
if ( V_189 -> V_102 -> V_232 )
V_189 -> V_102 -> V_232 ( V_2 , V_190 ) ;
F_212 ( & V_2 -> V_233 ) ;
F_213 ( V_2 -> V_230 ) ;
F_204 ( & V_2 -> V_4 ) ;
}
static void F_214 ( struct V_14 * V_15 ,
struct V_188 * V_189 , int V_234 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i) {
if ( V_3 == V_234 )
break;
F_211 ( V_15 , V_189 , V_2 , V_3 ) ;
}
}
static void F_215 ( struct V_14 * V_15 ,
struct V_188 * V_189 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i)
F_216 ( V_2 -> V_130 ) ;
}
static int F_217 ( struct V_14 * V_15 ,
struct V_188 * V_189 ,
struct V_1 * V_2 , unsigned V_190 )
{
int V_219 ;
unsigned V_229 = V_189 -> V_205 ;
V_219 = V_2 -> V_207 ;
if ( V_219 == V_235 )
V_219 = V_2 -> V_207 = V_189 -> V_207 ;
F_218 ( & V_2 -> V_152 , F_153 ) ;
F_218 ( & V_2 -> V_153 , F_154 ) ;
F_219 ( & V_2 -> V_125 ) ;
F_39 ( & V_2 -> V_134 ) ;
V_2 -> V_126 = V_15 ;
V_2 -> V_236 = V_190 ;
V_2 -> V_86 = V_189 -> V_86 ;
F_220 ( & V_2 -> V_233 ,
F_210 , V_2 ) ;
F_221 ( & V_2 -> V_233 ) ;
V_2 -> V_27 = V_189 -> V_27 [ V_190 ] ;
V_2 -> V_124 = F_222 ( V_149 * sizeof( void * ) ,
V_171 , V_219 ) ;
if ( ! V_2 -> V_124 )
goto V_237;
if ( F_205 ( & V_2 -> V_4 , V_219 ) )
goto V_238;
V_2 -> V_239 = 0 ;
if ( V_189 -> V_102 -> V_240 &&
V_189 -> V_102 -> V_240 ( V_2 , V_189 -> V_194 , V_190 ) )
goto V_241;
V_2 -> V_230 = F_223 ( V_15 , V_2 -> V_207 , V_189 -> V_210 ) ;
if ( ! V_2 -> V_230 )
goto V_232;
if ( V_189 -> V_102 -> V_216 &&
V_189 -> V_102 -> V_216 ( V_189 -> V_194 ,
V_2 -> V_230 -> V_231 , V_190 ,
V_229 + V_190 , V_219 ) )
goto V_242;
return 0 ;
V_242:
F_192 ( V_2 -> V_230 ) ;
V_232:
if ( V_189 -> V_102 -> V_232 )
V_189 -> V_102 -> V_232 ( V_2 , V_190 ) ;
V_241:
F_204 ( & V_2 -> V_4 ) ;
V_238:
F_192 ( V_2 -> V_124 ) ;
V_237:
F_212 ( & V_2 -> V_233 ) ;
return - 1 ;
}
static int F_224 ( struct V_14 * V_15 ,
struct V_188 * V_189 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i) {
if ( F_217 ( V_15 , V_189 , V_2 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_145 )
return 0 ;
F_214 ( V_15 , V_189 , V_3 ) ;
return 1 ;
}
static void F_225 ( struct V_14 * V_15 ,
unsigned int V_145 )
{
unsigned int V_3 ;
F_226 (i) {
struct V_9 * V_243 = F_227 ( V_15 -> V_244 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_243 -> V_35 = V_3 ;
F_219 ( & V_243 -> V_125 ) ;
F_39 ( & V_243 -> V_92 ) ;
V_243 -> V_126 = V_15 ;
if ( ! F_74 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
if ( V_145 > 1 && V_2 -> V_207 == V_235 )
V_2 -> V_207 = F_228 ( V_3 ) ;
}
}
static void F_229 ( struct V_14 * V_15 ,
const struct V_130 * V_245 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_188 * V_189 = V_15 -> V_246 ;
F_230 ( & V_15 -> V_247 ) ;
F_32 (q, hctx, i) {
F_231 ( V_2 -> V_130 ) ;
V_2 -> V_239 = 0 ;
}
F_232 (q, ctx, i) {
if ( ! F_137 ( V_3 , V_245 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_233 ( V_3 , V_2 -> V_130 ) ;
V_10 -> V_11 = V_2 -> V_239 ;
V_2 -> V_124 [ V_2 -> V_239 ++ ] = V_10 ;
}
F_234 ( & V_15 -> V_247 ) ;
F_32 (q, hctx, i) {
struct V_217 * V_6 = & V_2 -> V_4 ;
if ( ! V_2 -> V_239 ) {
if ( V_189 -> V_27 [ V_3 ] ) {
F_190 ( V_189 , V_189 -> V_27 [ V_3 ] , V_3 ) ;
V_189 -> V_27 [ V_3 ] = NULL ;
}
V_2 -> V_27 = NULL ;
continue;
}
if ( ! V_189 -> V_27 [ V_3 ] )
V_189 -> V_27 [ V_3 ] = F_195 ( V_189 , V_3 ) ;
V_2 -> V_27 = V_189 -> V_27 [ V_3 ] ;
F_136 ( ! V_2 -> V_27 ) ;
V_6 -> V_5 = F_235 ( V_2 -> V_239 , V_6 -> V_12 ) ;
V_2 -> V_148 = F_146 ( V_2 -> V_130 ) ;
V_2 -> V_147 = V_150 ;
}
F_232 (q, ctx, i) {
if ( ! F_137 ( V_3 , V_245 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_233 ( V_3 , V_2 -> V_27 -> V_130 ) ;
}
}
static void F_236 ( struct V_188 * V_189 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
bool V_79 ;
int V_3 ;
if ( V_189 -> V_248 . V_93 == V_189 -> V_248 . V_142 )
V_79 = false ;
else
V_79 = true ;
F_237 (q, &set->tag_list, tag_set_list) {
F_26 ( V_15 ) ;
F_32 (q, hctx, i) {
if ( V_79 )
V_2 -> V_86 |= V_249 ;
else
V_2 -> V_86 &= ~ V_249 ;
}
F_27 ( V_15 ) ;
}
}
static void F_238 ( struct V_14 * V_15 )
{
struct V_188 * V_189 = V_15 -> V_246 ;
F_230 ( & V_189 -> V_250 ) ;
F_99 ( & V_15 -> V_251 ) ;
F_236 ( V_189 ) ;
F_234 ( & V_189 -> V_250 ) ;
}
static void F_239 ( struct V_188 * V_189 ,
struct V_14 * V_15 )
{
V_15 -> V_246 = V_189 ;
F_230 ( & V_189 -> V_250 ) ;
F_105 ( & V_15 -> V_251 , & V_189 -> V_248 ) ;
F_236 ( V_189 ) ;
F_234 ( & V_189 -> V_250 ) ;
}
void F_240 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i) {
if ( ! V_2 )
continue;
F_192 ( V_2 -> V_124 ) ;
F_192 ( V_2 ) ;
}
F_192 ( V_15 -> V_187 ) ;
V_15 -> V_187 = NULL ;
F_192 ( V_15 -> V_186 ) ;
F_241 ( V_15 -> V_244 ) ;
}
struct V_14 * F_242 ( struct V_188 * V_189 )
{
struct V_14 * V_252 , * V_15 ;
V_252 = F_243 ( V_171 , V_189 -> V_207 ) ;
if ( ! V_252 )
return F_51 ( - V_223 ) ;
V_15 = F_244 ( V_189 , V_252 ) ;
if ( F_245 ( V_15 ) )
F_246 ( V_252 ) ;
return V_15 ;
}
struct V_14 * F_244 ( struct V_188 * V_189 ,
struct V_14 * V_15 )
{
struct V_1 * * V_253 ;
struct V_9 T_3 * V_10 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_247 ( struct V_9 ) ;
if ( ! V_10 )
return F_51 ( - V_223 ) ;
V_253 = F_222 ( V_189 -> V_145 * sizeof( * V_253 ) , V_171 ,
V_189 -> V_207 ) ;
if ( ! V_253 )
goto V_254;
V_6 = F_248 ( V_189 ) ;
if ( ! V_6 )
goto V_255;
for ( V_3 = 0 ; V_3 < V_189 -> V_145 ; V_3 ++ ) {
int V_219 = F_249 ( V_6 , V_3 ) ;
V_253 [ V_3 ] = F_198 ( sizeof( struct V_1 ) ,
V_171 , V_219 ) ;
if ( ! V_253 [ V_3 ] )
goto V_256;
if ( ! F_250 ( & V_253 [ V_3 ] -> V_130 , V_171 ,
V_219 ) )
goto V_256;
F_251 ( & V_253 [ V_3 ] -> V_68 , 0 ) ;
V_253 [ V_3 ] -> V_207 = V_219 ;
V_253 [ V_3 ] -> V_236 = V_3 ;
}
if ( F_252 ( & V_15 -> V_18 , F_16 ,
V_257 , V_171 ) )
goto V_256;
F_253 ( & V_15 -> V_56 , F_119 , ( unsigned long ) V_15 ) ;
F_254 ( V_15 , V_189 -> V_56 ? V_189 -> V_56 : 30 * V_258 ) ;
V_15 -> V_259 = V_149 ;
V_15 -> V_145 = V_189 -> V_145 ;
V_15 -> V_187 = V_6 ;
V_15 -> V_244 = V_10 ;
V_15 -> V_186 = V_253 ;
V_15 -> V_71 = V_189 -> V_102 ;
V_15 -> V_81 |= V_260 ;
if ( ! ( V_189 -> V_86 & V_261 ) )
V_15 -> V_81 |= 1 << V_262 ;
V_15 -> V_263 = V_264 ;
F_255 ( & V_15 -> V_91 , F_93 ) ;
F_39 ( & V_15 -> V_95 ) ;
F_219 ( & V_15 -> V_94 ) ;
if ( V_15 -> V_145 > 1 )
F_256 ( V_15 , F_179 ) ;
else
F_256 ( V_15 , F_186 ) ;
V_15 -> V_265 = V_189 -> V_205 ;
if ( V_189 -> V_102 -> V_266 )
F_257 ( V_15 , V_189 -> V_102 -> V_266 ) ;
F_225 ( V_15 , V_189 -> V_145 ) ;
if ( F_224 ( V_15 , V_189 ) )
goto V_256;
F_258 () ;
F_230 ( & V_267 ) ;
F_105 ( & V_15 -> V_268 , & V_269 ) ;
F_239 ( V_189 , V_15 ) ;
F_229 ( V_15 , V_270 ) ;
F_234 ( & V_267 ) ;
F_259 () ;
return V_15 ;
V_256:
F_192 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_189 -> V_145 ; V_3 ++ ) {
if ( ! V_253 [ V_3 ] )
break;
F_216 ( V_253 [ V_3 ] -> V_130 ) ;
F_192 ( V_253 [ V_3 ] ) ;
}
V_255:
F_192 ( V_253 ) ;
V_254:
F_241 ( V_10 ) ;
return F_51 ( - V_223 ) ;
}
void F_260 ( struct V_14 * V_15 )
{
struct V_188 * V_189 = V_15 -> V_246 ;
F_230 ( & V_267 ) ;
F_99 ( & V_15 -> V_268 ) ;
F_234 ( & V_267 ) ;
F_238 ( V_15 ) ;
F_214 ( V_15 , V_189 , V_189 -> V_145 ) ;
F_215 ( V_15 , V_189 ) ;
F_261 ( & V_15 -> V_18 ) ;
}
static void F_262 ( struct V_14 * V_15 ,
const struct V_130 * V_245 )
{
F_29 ( ! F_12 ( & V_15 -> V_22 ) ) ;
F_263 ( V_15 ) ;
F_264 ( V_15 -> V_187 , V_15 -> V_145 , V_245 ) ;
F_229 ( V_15 , V_245 ) ;
F_265 ( V_15 ) ;
}
static int F_266 ( struct V_271 * V_272 ,
unsigned long V_226 , void * V_273 )
{
struct V_14 * V_15 ;
int V_35 = ( unsigned long ) V_273 ;
static struct V_130 V_274 ;
switch ( V_226 & ~ V_275 ) {
case V_227 :
case V_276 :
F_267 ( & V_274 , V_270 ) ;
break;
case V_277 :
F_267 ( & V_274 , V_270 ) ;
F_233 ( V_35 , & V_274 ) ;
break;
default:
return V_225 ;
}
F_230 ( & V_267 ) ;
F_237 (q, &all_q_list, all_q_node)
F_19 ( V_15 ) ;
F_237 (q, &all_q_list, all_q_node) {
F_23 ( V_15 ) ;
F_268 ( & V_15 -> V_56 ) ;
}
F_237 (q, &all_q_list, all_q_node)
F_262 ( V_15 , & V_274 ) ;
F_237 (q, &all_q_list, all_q_node)
F_27 ( V_15 ) ;
F_234 ( & V_267 ) ;
return V_225 ;
}
static int F_269 ( struct V_188 * V_189 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_189 -> V_145 ; V_3 ++ ) {
V_189 -> V_27 [ V_3 ] = F_195 ( V_189 , V_3 ) ;
if ( ! V_189 -> V_27 [ V_3 ] )
goto V_278;
}
return 0 ;
V_278:
while ( -- V_3 >= 0 )
F_190 ( V_189 , V_189 -> V_27 [ V_3 ] , V_3 ) ;
return - V_223 ;
}
static int F_270 ( struct V_188 * V_189 )
{
unsigned int V_123 ;
int V_279 ;
V_123 = V_189 -> V_205 ;
do {
V_279 = F_269 ( V_189 ) ;
if ( ! V_279 )
break;
V_189 -> V_205 >>= 1 ;
if ( V_189 -> V_205 < V_189 -> V_206 + V_280 ) {
V_279 = - V_223 ;
break;
}
} while ( V_189 -> V_205 );
if ( ! V_189 -> V_205 || V_279 ) {
F_140 ( L_3 ) ;
return - V_223 ;
}
if ( V_123 != V_189 -> V_205 )
F_271 ( L_4 ,
V_123 , V_189 -> V_205 ) ;
return 0 ;
}
struct V_130 * F_272 ( struct V_99 * V_27 )
{
return V_27 -> V_130 ;
}
int F_273 ( struct V_188 * V_189 )
{
F_274 ( V_281 > 1 << V_282 ) ;
if ( ! V_189 -> V_145 )
return - V_283 ;
if ( ! V_189 -> V_205 )
return - V_283 ;
if ( V_189 -> V_205 < V_189 -> V_206 + V_280 )
return - V_283 ;
if ( ! V_189 -> V_102 -> V_138 || ! V_189 -> V_102 -> V_72 )
return - V_283 ;
if ( V_189 -> V_205 > V_281 ) {
F_271 ( L_5 ,
V_281 ) ;
V_189 -> V_205 = V_281 ;
}
if ( F_275 () ) {
V_189 -> V_145 = 1 ;
V_189 -> V_205 = F_203 ( 64U , V_189 -> V_205 ) ;
}
V_189 -> V_27 = F_222 ( V_189 -> V_145 *
sizeof( struct V_99 * ) ,
V_171 , V_189 -> V_207 ) ;
if ( ! V_189 -> V_27 )
return - V_223 ;
if ( F_270 ( V_189 ) )
goto V_284;
F_276 ( & V_189 -> V_250 ) ;
F_39 ( & V_189 -> V_248 ) ;
return 0 ;
V_284:
F_192 ( V_189 -> V_27 ) ;
V_189 -> V_27 = NULL ;
return - V_223 ;
}
void F_277 ( struct V_188 * V_189 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_189 -> V_145 ; V_3 ++ ) {
if ( V_189 -> V_27 [ V_3 ] )
F_190 ( V_189 , V_189 -> V_27 [ V_3 ] , V_3 ) ;
}
F_192 ( V_189 -> V_27 ) ;
V_189 -> V_27 = NULL ;
}
int F_278 ( struct V_14 * V_15 , unsigned int V_285 )
{
struct V_188 * V_189 = V_15 -> V_246 ;
struct V_1 * V_2 ;
int V_3 , V_17 ;
if ( ! V_189 || V_285 > V_189 -> V_205 )
return - V_283 ;
V_17 = 0 ;
F_32 (q, hctx, i) {
V_17 = F_279 ( V_2 -> V_27 , V_285 ) ;
if ( V_17 )
break;
}
if ( ! V_17 )
V_15 -> V_265 = V_285 ;
return V_17 ;
}
void F_280 ( void )
{
F_230 ( & V_267 ) ;
}
void F_281 ( void )
{
F_234 ( & V_267 ) ;
}
static int T_4 F_282 ( void )
{
F_283 () ;
F_284 ( F_266 , 0 ) ;
return 0 ;
}
