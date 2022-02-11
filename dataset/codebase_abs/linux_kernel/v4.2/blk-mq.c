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
void F_78 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = V_29 -> V_15 ;
if ( F_64 ( F_79 ( V_15 ) ) )
return;
if ( ! F_80 ( V_29 ) )
F_77 ( V_29 ) ;
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
static inline bool F_112 ( struct V_28 * V_29 ,
struct V_99 * V_100 , unsigned int V_64 )
{
return ( ( V_29 -> V_34 & V_101 ) &&
V_100 -> V_102 -> V_64 == V_64 ) ;
}
struct V_28 * F_113 ( struct V_103 * V_27 , unsigned int V_64 )
{
struct V_28 * V_29 = V_27 -> V_66 [ V_64 ] ;
struct V_99 * V_100 = F_114 ( V_29 -> V_15 , V_29 -> V_33 ) ;
if ( ! F_112 ( V_29 , V_100 , V_64 ) )
return V_29 ;
return V_100 -> V_102 ;
}
void F_115 ( struct V_28 * V_104 , bool V_69 )
{
struct V_105 * V_106 = V_104 -> V_15 -> V_71 ;
enum V_107 V_17 = V_108 ;
if ( ! F_4 ( V_74 , & V_104 -> V_75 ) )
return;
if ( V_106 -> V_56 )
V_17 = V_106 -> V_56 ( V_104 , V_69 ) ;
switch ( V_17 ) {
case V_109 :
F_77 ( V_104 ) ;
break;
case V_108 :
F_84 ( V_104 ) ;
F_116 ( V_104 ) ;
break;
case V_110 :
break;
default:
F_117 ( V_111 L_1 , V_17 ) ;
break;
}
}
static void F_118 ( struct V_1 * V_2 ,
struct V_28 * V_29 , void * V_112 , bool V_69 )
{
struct V_113 * V_62 = V_112 ;
if ( ! F_4 ( V_74 , & V_29 -> V_75 ) ) {
if ( F_64 ( F_13 ( V_29 -> V_15 ) ) ) {
V_29 -> V_48 = - V_98 ;
F_78 ( V_29 ) ;
}
return;
}
if ( V_29 -> V_34 & V_114 )
return;
if ( F_119 ( V_41 , V_29 -> V_115 ) ) {
if ( ! F_80 ( V_29 ) )
F_115 ( V_29 , V_69 ) ;
} else if ( ! V_62 -> V_116 || F_120 ( V_62 -> V_93 , V_29 -> V_115 ) ) {
V_62 -> V_93 = V_29 -> V_115 ;
V_62 -> V_116 = 1 ;
}
}
static void F_121 ( unsigned long V_112 )
{
struct V_14 * V_15 = (struct V_14 * ) V_112 ;
struct V_113 V_62 = {
. V_93 = 0 ,
. V_116 = 0 ,
} ;
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i) {
if ( ! F_33 ( V_2 ) )
continue;
F_122 ( V_2 , F_118 , & V_62 ) ;
}
if ( V_62 . V_116 ) {
V_62 . V_93 = F_123 ( F_124 ( V_62 . V_93 ) ) ;
F_125 ( & V_15 -> V_56 , V_62 . V_93 ) ;
} else {
F_32 (q, hctx, i) {
if ( F_33 ( V_2 ) )
F_126 ( V_2 ) ;
}
}
}
static bool F_127 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_117 * V_117 )
{
struct V_28 * V_29 ;
int V_118 = 8 ;
F_128 (rq, &ctx->rq_list, queuelist) {
int V_119 ;
if ( ! V_118 -- )
break;
if ( ! F_129 ( V_29 , V_117 ) )
continue;
V_119 = F_130 ( V_29 , V_117 ) ;
if ( V_119 == V_120 ) {
if ( F_131 ( V_15 , V_29 , V_117 ) ) {
V_10 -> V_121 ++ ;
return true ;
}
break;
} else if ( V_119 == V_122 ) {
if ( F_132 ( V_15 , V_29 , V_117 ) ) {
V_10 -> V_121 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_133 ( struct V_1 * V_2 , struct V_123 * V_124 )
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
V_126 = F_134 ( & V_13 -> V_7 , V_13 -> V_127 , V_126 ) ;
if ( V_126 >= V_13 -> V_127 )
break;
V_10 = V_2 -> V_128 [ V_126 + V_125 ] ;
F_8 ( V_126 , & V_13 -> V_7 ) ;
F_135 ( & V_10 -> V_129 ) ;
F_136 ( & V_10 -> V_92 , V_124 ) ;
F_137 ( & V_10 -> V_129 ) ;
V_126 ++ ;
} while ( 1 );
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_130 ;
struct V_28 * V_29 ;
F_94 ( V_92 ) ;
F_94 ( V_131 ) ;
struct V_123 * V_132 ;
int V_133 ;
F_138 ( ! F_139 ( F_140 () , V_2 -> V_134 ) ) ;
if ( F_64 ( F_4 ( V_135 , & V_2 -> V_136 ) ) )
return;
V_2 -> V_137 ++ ;
F_133 ( V_2 , & V_92 ) ;
if ( ! F_141 ( & V_2 -> V_138 ) ) {
F_135 ( & V_2 -> V_129 ) ;
if ( ! F_101 ( & V_2 -> V_138 ) )
F_96 ( & V_2 -> V_138 , & V_92 ) ;
F_137 ( & V_2 -> V_129 ) ;
}
V_132 = NULL ;
V_133 = 0 ;
while ( ! F_101 ( & V_92 ) ) {
struct V_139 V_140 ;
int V_17 ;
V_29 = F_111 ( & V_92 , struct V_28 , V_32 ) ;
F_99 ( & V_29 -> V_32 ) ;
V_140 . V_29 = V_29 ;
V_140 . V_124 = V_132 ;
V_140 . V_141 = F_101 ( & V_92 ) ;
V_17 = V_15 -> V_71 -> V_142 ( V_2 , & V_140 ) ;
switch ( V_17 ) {
case V_143 :
V_133 ++ ;
continue;
case V_144 :
F_104 ( & V_29 -> V_32 , & V_92 ) ;
F_86 ( V_29 ) ;
break;
default:
F_142 ( L_2 , V_17 ) ;
case V_145 :
V_29 -> V_48 = - V_98 ;
F_66 ( V_29 , V_29 -> V_48 ) ;
break;
}
if ( V_17 == V_144 )
break;
if ( ! V_132 && V_92 . V_93 != V_92 . V_146 )
V_132 = & V_131 ;
}
if ( ! V_133 )
V_2 -> V_147 [ 0 ] ++ ;
else if ( V_133 < ( 1 << ( V_148 - 1 ) ) )
V_2 -> V_147 [ F_143 ( V_133 ) + 1 ] ++ ;
if ( ! F_101 ( & V_92 ) ) {
F_135 ( & V_2 -> V_129 ) ;
F_144 ( & V_92 , & V_2 -> V_138 ) ;
F_137 ( & V_2 -> V_129 ) ;
F_145 ( V_2 , true ) ;
}
}
static int F_146 ( struct V_1 * V_2 )
{
if ( V_2 -> V_130 -> V_149 == 1 )
return V_150 ;
if ( -- V_2 -> V_151 <= 0 ) {
int V_35 = V_2 -> V_152 , V_152 ;
V_152 = F_147 ( V_2 -> V_152 , V_2 -> V_134 ) ;
if ( V_152 >= V_153 )
V_152 = F_148 ( V_2 -> V_134 ) ;
V_2 -> V_152 = V_152 ;
V_2 -> V_151 = V_154 ;
return V_35 ;
}
return V_2 -> V_152 ;
}
void F_145 ( struct V_1 * V_2 , bool V_155 )
{
if ( F_64 ( F_4 ( V_135 , & V_2 -> V_136 ) ||
! F_33 ( V_2 ) ) )
return;
if ( ! V_155 ) {
int V_35 = F_72 () ;
if ( F_139 ( V_35 , V_2 -> V_134 ) ) {
F_54 ( V_2 ) ;
F_76 () ;
return;
}
F_76 () ;
}
F_149 ( F_146 ( V_2 ) ,
& V_2 -> V_156 , 0 ) ;
}
void F_22 ( struct V_14 * V_15 , bool V_155 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_141 ( & V_2 -> V_138 ) ) ||
F_4 ( V_135 , & V_2 -> V_136 ) )
continue;
F_145 ( V_2 , V_155 ) ;
}
}
void F_150 ( struct V_1 * V_2 )
{
F_151 ( & V_2 -> V_156 ) ;
F_151 ( & V_2 -> V_157 ) ;
F_6 ( V_135 , & V_2 -> V_136 ) ;
}
void F_152 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i)
F_150 ( V_2 ) ;
}
void F_153 ( struct V_1 * V_2 )
{
F_8 ( V_135 , & V_2 -> V_136 ) ;
F_145 ( V_2 , false ) ;
}
void F_103 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i)
F_153 ( V_2 ) ;
}
void F_154 ( struct V_14 * V_15 , bool V_155 )
{
struct V_1 * V_2 ;
int V_3 ;
F_32 (q, hctx, i) {
if ( ! F_4 ( V_135 , & V_2 -> V_136 ) )
continue;
F_8 ( V_135 , & V_2 -> V_136 ) ;
F_145 ( V_2 , V_155 ) ;
}
}
static void F_155 ( struct V_89 * V_90 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_90 , struct V_1 , V_156 . V_90 ) ;
F_54 ( V_2 ) ;
}
static void F_156 ( struct V_89 * V_90 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_90 , struct V_1 , V_157 . V_90 ) ;
if ( F_88 ( V_135 , & V_2 -> V_136 ) )
F_54 ( V_2 ) ;
}
void F_157 ( struct V_1 * V_2 , unsigned long V_158 )
{
if ( F_64 ( ! F_33 ( V_2 ) ) )
return;
F_149 ( F_146 ( V_2 ) ,
& V_2 -> V_157 , F_158 ( V_158 ) ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_28 * V_29 , bool V_97 )
{
struct V_9 * V_10 = V_29 -> V_33 ;
F_160 ( V_2 -> V_130 , V_29 ) ;
if ( V_97 )
F_104 ( & V_29 -> V_32 , & V_10 -> V_92 ) ;
else
F_105 ( & V_29 -> V_32 , & V_10 -> V_92 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_100 ( struct V_28 * V_29 , bool V_97 , bool V_159 ,
bool V_155 )
{
struct V_14 * V_15 = V_29 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_29 -> V_33 , * V_160 ;
V_160 = F_52 ( V_15 ) ;
if ( ! F_74 ( V_10 -> V_35 ) )
V_29 -> V_33 = V_10 = V_160 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_135 ( & V_10 -> V_129 ) ;
F_159 ( V_2 , V_29 , V_97 ) ;
F_137 ( & V_10 -> V_129 ) ;
if ( V_159 )
F_145 ( V_2 , V_155 ) ;
F_55 ( V_160 ) ;
}
static void F_161 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_123 * V_124 ,
int V_127 ,
bool V_161 )
{
struct V_1 * V_2 ;
struct V_9 * V_160 ;
F_162 ( V_15 , V_127 , ! V_161 ) ;
V_160 = F_52 ( V_15 ) ;
if ( ! F_74 ( V_10 -> V_35 ) )
V_10 = V_160 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_135 ( & V_10 -> V_129 ) ;
while ( ! F_101 ( V_124 ) ) {
struct V_28 * V_29 ;
V_29 = F_111 ( V_124 , struct V_28 , V_32 ) ;
F_99 ( & V_29 -> V_32 ) ;
V_29 -> V_33 = V_10 ;
F_159 ( V_2 , V_29 , false ) ;
}
F_137 ( & V_10 -> V_129 ) ;
F_145 ( V_2 , V_161 ) ;
F_55 ( V_160 ) ;
}
static int F_163 ( void * V_112 , struct V_123 * V_162 , struct V_123 * V_163 )
{
struct V_28 * V_164 = F_17 ( V_162 , struct V_28 , V_32 ) ;
struct V_28 * V_165 = F_17 ( V_163 , struct V_28 , V_32 ) ;
return ! ( V_164 -> V_33 < V_165 -> V_33 ||
( V_164 -> V_33 == V_165 -> V_33 &&
F_164 ( V_164 ) < F_164 ( V_165 ) ) ) ;
}
void F_165 ( struct V_166 * V_167 , bool V_161 )
{
struct V_9 * V_168 ;
struct V_14 * V_169 ;
struct V_28 * V_29 ;
F_94 ( V_124 ) ;
F_94 ( V_170 ) ;
unsigned int V_127 ;
F_96 ( & V_167 -> V_171 , & V_124 ) ;
F_166 ( NULL , & V_124 , F_163 ) ;
V_169 = NULL ;
V_168 = NULL ;
V_127 = 0 ;
while ( ! F_101 ( & V_124 ) ) {
V_29 = F_167 ( V_124 . V_93 ) ;
F_99 ( & V_29 -> V_32 ) ;
F_90 ( ! V_29 -> V_15 ) ;
if ( V_29 -> V_33 != V_168 ) {
if ( V_168 ) {
F_161 ( V_169 , V_168 ,
& V_170 , V_127 ,
V_161 ) ;
}
V_168 = V_29 -> V_33 ;
V_169 = V_29 -> V_15 ;
V_127 = 0 ;
}
V_127 ++ ;
F_105 ( & V_29 -> V_32 , & V_170 ) ;
}
if ( V_168 ) {
F_161 ( V_169 , V_168 , & V_170 , V_127 ,
V_161 ) ;
}
}
static void F_168 ( struct V_28 * V_29 , struct V_117 * V_117 )
{
F_169 ( V_29 , V_117 ) ;
if ( F_170 ( V_29 ) )
F_171 ( V_29 , 1 ) ;
}
static inline bool F_172 ( struct V_1 * V_2 )
{
return ( V_2 -> V_86 & V_172 ) &&
! F_173 ( V_2 -> V_130 ) ;
}
static inline bool F_174 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_28 * V_29 , struct V_117 * V_117 )
{
if ( ! F_172 ( V_2 ) ) {
F_168 ( V_29 , V_117 ) ;
F_135 ( & V_10 -> V_129 ) ;
V_173:
F_159 ( V_2 , V_29 , false ) ;
F_137 ( & V_10 -> V_129 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_130 ;
F_135 ( & V_10 -> V_129 ) ;
if ( ! F_127 ( V_15 , V_10 , V_117 ) ) {
F_168 ( V_29 , V_117 ) ;
goto V_173;
}
F_137 ( & V_10 -> V_129 ) ;
F_56 ( V_2 , V_10 , V_29 ) ;
return true ;
}
}
static struct V_28 * F_175 ( struct V_14 * V_15 ,
struct V_117 * V_117 ,
struct V_174 * V_62 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_28 * V_29 ;
int V_63 = F_176 ( V_117 ) ;
struct V_61 V_70 ;
if ( F_64 ( F_9 ( V_15 , V_175 ) ) ) {
F_177 ( V_117 , - V_98 ) ;
return NULL ;
}
V_10 = F_52 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
if ( F_45 ( V_117 -> V_176 ) )
V_63 |= V_177 ;
F_178 ( V_15 , V_117 , V_63 ) ;
F_53 ( & V_70 , V_15 , V_178 , false , V_10 ,
V_2 ) ;
V_29 = F_46 ( & V_70 , V_63 ) ;
if ( F_64 ( ! V_29 ) ) {
F_54 ( V_2 ) ;
F_55 ( V_10 ) ;
F_179 ( V_15 , V_117 , V_63 ) ;
V_10 = F_52 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_53 ( & V_70 , V_15 ,
V_19 | V_178 , false , V_10 , V_2 ) ;
V_29 = F_46 ( & V_70 , V_63 ) ;
V_10 = V_70 . V_10 ;
V_2 = V_70 . V_2 ;
}
V_2 -> V_133 ++ ;
V_62 -> V_2 = V_2 ;
V_62 -> V_10 = V_10 ;
return V_29 ;
}
static int F_180 ( struct V_28 * V_29 )
{
int V_17 ;
struct V_14 * V_15 = V_29 -> V_15 ;
struct V_1 * V_2 = V_15 -> V_71 -> V_72 ( V_15 ,
V_29 -> V_33 -> V_35 ) ;
struct V_139 V_140 = {
. V_29 = V_29 ,
. V_124 = NULL ,
. V_141 = 1
} ;
V_17 = V_15 -> V_71 -> V_142 ( V_2 , & V_140 ) ;
if ( V_17 == V_143 )
return 0 ;
else {
F_86 ( V_29 ) ;
if ( V_17 == V_145 ) {
V_29 -> V_48 = - V_98 ;
F_66 ( V_29 , V_29 -> V_48 ) ;
return 0 ;
}
return - 1 ;
}
}
static void F_181 ( struct V_14 * V_15 , struct V_117 * V_117 )
{
const int V_179 = F_45 ( V_117 -> V_176 ) ;
const int V_180 = V_117 -> V_176 & ( V_181 | V_182 ) ;
struct V_174 V_62 ;
struct V_28 * V_29 ;
unsigned int V_183 = 0 ;
struct V_166 * V_167 ;
struct V_28 * V_184 = NULL ;
F_182 ( V_15 , & V_117 ) ;
if ( F_183 ( V_117 ) && F_184 ( V_117 ) ) {
F_177 ( V_117 , - V_98 ) ;
return;
}
if ( ! V_180 && ! F_173 ( V_15 ) &&
F_185 ( V_15 , V_117 , & V_183 , & V_184 ) )
return;
V_29 = F_175 ( V_15 , V_117 , & V_62 ) ;
if ( F_64 ( ! V_29 ) )
return;
if ( F_64 ( V_180 ) ) {
F_168 ( V_29 , V_117 ) ;
F_186 ( V_29 ) ;
goto V_159;
}
V_167 = V_185 -> V_167 ;
if ( ( ( V_167 && ! F_173 ( V_15 ) ) || V_179 ) &&
! ( V_62 . V_2 -> V_86 & V_186 ) ) {
struct V_28 * V_187 = NULL ;
F_168 ( V_29 , V_117 ) ;
if ( V_167 ) {
if ( V_184 && ! F_101 ( & V_167 -> V_171 ) ) {
V_187 = V_184 ;
F_99 ( & V_187 -> V_32 ) ;
}
F_105 ( & V_29 -> V_32 , & V_167 -> V_171 ) ;
} else
V_187 = V_29 ;
F_55 ( V_62 . V_10 ) ;
if ( ! V_187 )
return;
if ( ! F_180 ( V_187 ) )
return;
F_100 ( V_187 , false , true , true ) ;
return;
}
if ( ! F_174 ( V_62 . V_2 , V_62 . V_10 , V_29 , V_117 ) ) {
V_159:
F_145 ( V_62 . V_2 , ! V_179 || V_180 ) ;
}
F_55 ( V_62 . V_10 ) ;
}
static void F_187 ( struct V_14 * V_15 , struct V_117 * V_117 )
{
const int V_179 = F_45 ( V_117 -> V_176 ) ;
const int V_180 = V_117 -> V_176 & ( V_181 | V_182 ) ;
struct V_166 * V_167 ;
unsigned int V_183 = 0 ;
struct V_174 V_62 ;
struct V_28 * V_29 ;
F_182 ( V_15 , & V_117 ) ;
if ( F_183 ( V_117 ) && F_184 ( V_117 ) ) {
F_177 ( V_117 , - V_98 ) ;
return;
}
if ( ! V_180 && ! F_173 ( V_15 ) &&
F_185 ( V_15 , V_117 , & V_183 , NULL ) )
return;
V_29 = F_175 ( V_15 , V_117 , & V_62 ) ;
if ( F_64 ( ! V_29 ) )
return;
if ( F_64 ( V_180 ) ) {
F_168 ( V_29 , V_117 ) ;
F_186 ( V_29 ) ;
goto V_159;
}
V_167 = V_185 -> V_167 ;
if ( V_167 ) {
F_168 ( V_29 , V_117 ) ;
if ( F_101 ( & V_167 -> V_171 ) )
F_188 ( V_15 ) ;
else if ( V_183 >= V_188 ) {
F_189 ( V_167 , false ) ;
F_188 ( V_15 ) ;
}
F_105 ( & V_29 -> V_32 , & V_167 -> V_171 ) ;
F_55 ( V_62 . V_10 ) ;
return;
}
if ( ! F_174 ( V_62 . V_2 , V_62 . V_10 , V_29 , V_117 ) ) {
V_159:
F_145 ( V_62 . V_2 , ! V_179 || V_180 ) ;
}
F_55 ( V_62 . V_10 ) ;
}
struct V_1 * F_190 ( struct V_14 * V_15 , const int V_35 )
{
return V_15 -> V_189 [ V_15 -> V_190 [ V_35 ] ] ;
}
static void F_191 ( struct V_191 * V_192 ,
struct V_103 * V_27 , unsigned int V_193 )
{
struct V_194 * V_194 ;
if ( V_27 -> V_66 && V_192 -> V_106 -> V_195 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_196 ; V_3 ++ ) {
if ( ! V_27 -> V_66 [ V_3 ] )
continue;
V_192 -> V_106 -> V_195 ( V_192 -> V_197 , V_27 -> V_66 [ V_3 ] ,
V_193 , V_3 ) ;
V_27 -> V_66 [ V_3 ] = NULL ;
}
}
while ( ! F_101 ( & V_27 -> V_198 ) ) {
V_194 = F_111 ( & V_27 -> V_198 , struct V_194 , V_199 ) ;
F_99 ( & V_194 -> V_199 ) ;
F_192 ( V_194 , V_194 -> V_200 ) ;
}
F_193 ( V_27 -> V_66 ) ;
F_194 ( V_27 ) ;
}
static T_2 F_195 ( unsigned int V_201 )
{
return ( T_2 ) V_202 << V_201 ;
}
static struct V_103 * F_196 ( struct V_191 * V_192 ,
unsigned int V_193 )
{
struct V_103 * V_27 ;
unsigned int V_3 , V_203 , V_204 , V_205 = 4 ;
T_2 V_206 , V_207 ;
V_27 = F_197 ( V_192 -> V_208 , V_192 -> V_209 ,
V_192 -> V_210 ,
F_198 ( V_192 -> V_86 ) ) ;
if ( ! V_27 )
return NULL ;
F_39 ( & V_27 -> V_198 ) ;
V_27 -> V_66 = F_199 ( V_192 -> V_208 * sizeof( struct V_28 * ) ,
V_175 | V_211 | V_212 ,
V_192 -> V_210 ) ;
if ( ! V_27 -> V_66 ) {
F_194 ( V_27 ) ;
return NULL ;
}
V_206 = F_200 ( sizeof( struct V_28 ) + V_192 -> V_213 ,
F_201 () ) ;
V_207 = V_206 * V_192 -> V_208 ;
for ( V_3 = 0 ; V_3 < V_192 -> V_208 ; ) {
int V_214 = V_205 ;
struct V_194 * V_194 ;
int V_215 ;
void * V_216 ;
while ( V_207 < F_195 ( V_214 - 1 ) && V_214 )
V_214 -- ;
do {
V_194 = F_202 ( V_192 -> V_210 ,
V_175 | V_211 | V_212 | V_217 ,
V_214 ) ;
if ( V_194 )
break;
if ( ! V_214 -- )
break;
if ( F_195 ( V_214 ) < V_206 )
break;
} while ( 1 );
if ( ! V_194 )
goto V_218;
V_194 -> V_200 = V_214 ;
F_105 ( & V_194 -> V_199 , & V_27 -> V_198 ) ;
V_216 = F_203 ( V_194 ) ;
V_204 = F_195 ( V_214 ) / V_206 ;
V_215 = F_204 ( V_204 , V_192 -> V_208 - V_3 ) ;
V_207 -= V_215 * V_206 ;
for ( V_203 = 0 ; V_203 < V_215 ; V_203 ++ ) {
V_27 -> V_66 [ V_3 ] = V_216 ;
if ( V_192 -> V_106 -> V_219 ) {
if ( V_192 -> V_106 -> V_219 ( V_192 -> V_197 ,
V_27 -> V_66 [ V_3 ] , V_193 , V_3 ,
V_192 -> V_210 ) ) {
V_27 -> V_66 [ V_3 ] = NULL ;
goto V_218;
}
}
V_216 += V_206 ;
V_3 ++ ;
}
}
return V_27 ;
V_218:
F_191 ( V_192 , V_27 , V_193 ) ;
return NULL ;
}
static void F_205 ( struct V_220 * V_221 )
{
F_193 ( V_221 -> V_6 ) ;
}
static int F_206 ( struct V_220 * V_221 , int V_222 )
{
unsigned int V_223 = 8 , V_224 , V_225 , V_3 ;
V_221 -> V_12 = V_223 ;
V_225 = F_207 ( V_153 , V_223 ) / V_223 ;
V_221 -> V_6 = F_199 ( V_225 * sizeof( struct V_8 ) ,
V_175 , V_222 ) ;
if ( ! V_221 -> V_6 )
return - V_226 ;
V_224 = V_153 ;
for ( V_3 = 0 ; V_3 < V_225 ; V_3 ++ ) {
V_221 -> V_6 [ V_3 ] . V_127 = F_204 ( V_224 , V_221 -> V_12 ) ;
V_224 -= V_221 -> V_6 [ V_3 ] . V_127 ;
}
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , int V_35 )
{
struct V_14 * V_15 = V_2 -> V_130 ;
struct V_9 * V_10 ;
F_94 ( V_227 ) ;
V_10 = F_209 ( V_15 , V_35 ) ;
F_135 ( & V_10 -> V_129 ) ;
if ( ! F_101 ( & V_10 -> V_92 ) ) {
F_96 ( & V_10 -> V_92 , & V_227 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_137 ( & V_10 -> V_129 ) ;
if ( F_101 ( & V_227 ) )
return V_228 ;
V_10 = F_52 ( V_15 ) ;
F_135 ( & V_10 -> V_129 ) ;
while ( ! F_101 ( & V_227 ) ) {
struct V_28 * V_29 ;
V_29 = F_111 ( & V_227 , struct V_28 , V_32 ) ;
V_29 -> V_33 = V_10 ;
F_210 ( & V_29 -> V_32 , & V_10 -> V_92 ) ;
}
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_35 ) ;
F_3 ( V_2 , V_10 ) ;
F_137 ( & V_10 -> V_129 ) ;
F_145 ( V_2 , true ) ;
F_55 ( V_10 ) ;
return V_228 ;
}
static int F_211 ( void * V_62 , unsigned long V_229 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_62 ;
if ( V_229 == V_230 || V_229 == V_231 )
return F_208 ( V_2 , V_35 ) ;
return V_228 ;
}
static void F_212 ( struct V_14 * V_15 ,
struct V_191 * V_192 ,
struct V_1 * V_2 , unsigned int V_193 )
{
unsigned V_232 = V_192 -> V_208 ;
F_126 ( V_2 ) ;
if ( V_192 -> V_106 -> V_195 )
V_192 -> V_106 -> V_195 ( V_192 -> V_197 ,
V_2 -> V_100 -> V_102 , V_193 ,
V_232 + V_193 ) ;
if ( V_192 -> V_106 -> V_233 )
V_192 -> V_106 -> V_233 ( V_2 , V_193 ) ;
F_213 ( & V_2 -> V_234 ) ;
F_214 ( V_2 -> V_100 ) ;
F_205 ( & V_2 -> V_4 ) ;
}
static void F_215 ( struct V_14 * V_15 ,
struct V_191 * V_192 , int V_235 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i) {
if ( V_3 == V_235 )
break;
F_212 ( V_15 , V_192 , V_2 , V_3 ) ;
}
}
static void F_216 ( struct V_14 * V_15 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i)
F_217 ( V_2 -> V_134 ) ;
}
static int F_218 ( struct V_14 * V_15 ,
struct V_191 * V_192 ,
struct V_1 * V_2 , unsigned V_193 )
{
int V_222 ;
unsigned V_232 = V_192 -> V_208 ;
V_222 = V_2 -> V_210 ;
if ( V_222 == V_236 )
V_222 = V_2 -> V_210 = V_192 -> V_210 ;
F_219 ( & V_2 -> V_156 , F_155 ) ;
F_219 ( & V_2 -> V_157 , F_156 ) ;
F_220 ( & V_2 -> V_129 ) ;
F_39 ( & V_2 -> V_138 ) ;
V_2 -> V_130 = V_15 ;
V_2 -> V_237 = V_193 ;
V_2 -> V_86 = V_192 -> V_86 ;
F_221 ( & V_2 -> V_234 ,
F_211 , V_2 ) ;
F_222 ( & V_2 -> V_234 ) ;
V_2 -> V_27 = V_192 -> V_27 [ V_193 ] ;
V_2 -> V_128 = F_223 ( V_153 * sizeof( void * ) ,
V_175 , V_222 ) ;
if ( ! V_2 -> V_128 )
goto V_238;
if ( F_206 ( & V_2 -> V_4 , V_222 ) )
goto V_239;
V_2 -> V_240 = 0 ;
if ( V_192 -> V_106 -> V_241 &&
V_192 -> V_106 -> V_241 ( V_2 , V_192 -> V_197 , V_193 ) )
goto V_242;
V_2 -> V_100 = F_224 ( V_15 , V_2 -> V_210 , V_192 -> V_213 ) ;
if ( ! V_2 -> V_100 )
goto V_233;
if ( V_192 -> V_106 -> V_219 &&
V_192 -> V_106 -> V_219 ( V_192 -> V_197 ,
V_2 -> V_100 -> V_102 , V_193 ,
V_232 + V_193 , V_222 ) )
goto V_243;
return 0 ;
V_243:
F_193 ( V_2 -> V_100 ) ;
V_233:
if ( V_192 -> V_106 -> V_233 )
V_192 -> V_106 -> V_233 ( V_2 , V_193 ) ;
V_242:
F_205 ( & V_2 -> V_4 ) ;
V_239:
F_193 ( V_2 -> V_128 ) ;
V_238:
F_213 ( & V_2 -> V_234 ) ;
return - 1 ;
}
static int F_225 ( struct V_14 * V_15 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i) {
if ( F_218 ( V_15 , V_192 , V_2 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_149 )
return 0 ;
F_215 ( V_15 , V_192 , V_3 ) ;
return 1 ;
}
static void F_226 ( struct V_14 * V_15 ,
unsigned int V_149 )
{
unsigned int V_3 ;
F_227 (i) {
struct V_9 * V_244 = F_228 ( V_15 -> V_245 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
V_244 -> V_35 = V_3 ;
F_220 ( & V_244 -> V_129 ) ;
F_39 ( & V_244 -> V_92 ) ;
V_244 -> V_130 = V_15 ;
if ( ! F_74 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
if ( V_149 > 1 && V_2 -> V_210 == V_236 )
V_2 -> V_210 = F_229 ( V_3 ) ;
}
}
static void F_230 ( struct V_14 * V_15 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_191 * V_192 = V_15 -> V_246 ;
F_32 (q, hctx, i) {
F_231 ( V_2 -> V_134 ) ;
V_2 -> V_240 = 0 ;
}
F_232 (q, ctx, i) {
if ( ! F_74 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_233 ( V_3 , V_2 -> V_134 ) ;
F_233 ( V_3 , V_2 -> V_27 -> V_134 ) ;
V_10 -> V_11 = V_2 -> V_240 ;
V_2 -> V_128 [ V_2 -> V_240 ++ ] = V_10 ;
}
F_32 (q, hctx, i) {
struct V_220 * V_6 = & V_2 -> V_4 ;
if ( ! V_2 -> V_240 ) {
if ( V_192 -> V_27 [ V_3 ] ) {
F_191 ( V_192 , V_192 -> V_27 [ V_3 ] , V_3 ) ;
V_192 -> V_27 [ V_3 ] = NULL ;
}
V_2 -> V_27 = NULL ;
continue;
}
if ( ! V_192 -> V_27 [ V_3 ] )
V_192 -> V_27 [ V_3 ] = F_196 ( V_192 , V_3 ) ;
V_2 -> V_27 = V_192 -> V_27 [ V_3 ] ;
F_138 ( ! V_2 -> V_27 ) ;
V_6 -> V_5 = F_234 ( V_2 -> V_240 , V_6 -> V_12 ) ;
V_2 -> V_152 = F_148 ( V_2 -> V_134 ) ;
V_2 -> V_151 = V_154 ;
}
}
static void F_235 ( struct V_191 * V_192 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
bool V_79 ;
int V_3 ;
if ( V_192 -> V_247 . V_93 == V_192 -> V_247 . V_146 )
V_79 = false ;
else
V_79 = true ;
F_236 (q, &set->tag_list, tag_set_list) {
F_26 ( V_15 ) ;
F_32 (q, hctx, i) {
if ( V_79 )
V_2 -> V_86 |= V_248 ;
else
V_2 -> V_86 &= ~ V_248 ;
}
F_27 ( V_15 ) ;
}
}
static void F_237 ( struct V_14 * V_15 )
{
struct V_191 * V_192 = V_15 -> V_246 ;
F_238 ( & V_192 -> V_249 ) ;
F_99 ( & V_15 -> V_250 ) ;
F_235 ( V_192 ) ;
F_239 ( & V_192 -> V_249 ) ;
}
static void F_240 ( struct V_191 * V_192 ,
struct V_14 * V_15 )
{
V_15 -> V_246 = V_192 ;
F_238 ( & V_192 -> V_249 ) ;
F_105 ( & V_15 -> V_250 , & V_192 -> V_247 ) ;
F_235 ( V_192 ) ;
F_239 ( & V_192 -> V_249 ) ;
}
void F_241 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_32 (q, hctx, i) {
if ( ! V_2 )
continue;
F_193 ( V_2 -> V_128 ) ;
F_193 ( V_2 ) ;
}
F_193 ( V_15 -> V_189 ) ;
F_242 ( V_15 -> V_245 ) ;
}
struct V_14 * F_243 ( struct V_191 * V_192 )
{
struct V_14 * V_251 , * V_15 ;
V_251 = F_244 ( V_175 , V_192 -> V_210 ) ;
if ( ! V_251 )
return F_51 ( - V_226 ) ;
V_15 = F_245 ( V_192 , V_251 ) ;
if ( F_246 ( V_15 ) )
F_247 ( V_251 ) ;
return V_15 ;
}
struct V_14 * F_245 ( struct V_191 * V_192 ,
struct V_14 * V_15 )
{
struct V_1 * * V_252 ;
struct V_9 T_3 * V_10 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_248 ( struct V_9 ) ;
if ( ! V_10 )
return F_51 ( - V_226 ) ;
V_252 = F_223 ( V_192 -> V_149 * sizeof( * V_252 ) , V_175 ,
V_192 -> V_210 ) ;
if ( ! V_252 )
goto V_253;
V_6 = F_249 ( V_192 ) ;
if ( ! V_6 )
goto V_254;
for ( V_3 = 0 ; V_3 < V_192 -> V_149 ; V_3 ++ ) {
int V_222 = F_250 ( V_6 , V_3 ) ;
V_252 [ V_3 ] = F_199 ( sizeof( struct V_1 ) ,
V_175 , V_222 ) ;
if ( ! V_252 [ V_3 ] )
goto V_255;
if ( ! F_251 ( & V_252 [ V_3 ] -> V_134 , V_175 ,
V_222 ) )
goto V_255;
F_252 ( & V_252 [ V_3 ] -> V_68 , 0 ) ;
V_252 [ V_3 ] -> V_210 = V_222 ;
V_252 [ V_3 ] -> V_237 = V_3 ;
}
if ( F_253 ( & V_15 -> V_18 , F_16 ,
V_256 , V_175 ) )
goto V_255;
F_254 ( & V_15 -> V_56 , F_121 , ( unsigned long ) V_15 ) ;
F_255 ( V_15 , V_192 -> V_56 ? V_192 -> V_56 : 30 * V_257 ) ;
V_15 -> V_258 = V_153 ;
V_15 -> V_149 = V_192 -> V_149 ;
V_15 -> V_190 = V_6 ;
V_15 -> V_245 = V_10 ;
V_15 -> V_189 = V_252 ;
V_15 -> V_71 = V_192 -> V_106 ;
V_15 -> V_81 |= V_259 ;
if ( ! ( V_192 -> V_86 & V_260 ) )
V_15 -> V_81 |= 1 << V_261 ;
V_15 -> V_262 = V_263 ;
F_256 ( & V_15 -> V_91 , F_93 ) ;
F_39 ( & V_15 -> V_95 ) ;
F_220 ( & V_15 -> V_94 ) ;
if ( V_15 -> V_149 > 1 )
F_257 ( V_15 , F_181 ) ;
else
F_257 ( V_15 , F_187 ) ;
V_15 -> V_264 = V_192 -> V_208 ;
if ( V_192 -> V_106 -> V_265 )
F_258 ( V_15 , V_192 -> V_106 -> V_265 ) ;
F_226 ( V_15 , V_192 -> V_149 ) ;
if ( F_225 ( V_15 , V_192 ) )
goto V_255;
F_238 ( & V_266 ) ;
F_105 ( & V_15 -> V_267 , & V_268 ) ;
F_239 ( & V_266 ) ;
F_240 ( V_192 , V_15 ) ;
F_230 ( V_15 ) ;
return V_15 ;
V_255:
F_193 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_192 -> V_149 ; V_3 ++ ) {
if ( ! V_252 [ V_3 ] )
break;
F_217 ( V_252 [ V_3 ] -> V_134 ) ;
F_193 ( V_252 [ V_3 ] ) ;
}
V_254:
F_193 ( V_252 ) ;
V_253:
F_242 ( V_10 ) ;
return F_51 ( - V_226 ) ;
}
void F_259 ( struct V_14 * V_15 )
{
struct V_191 * V_192 = V_15 -> V_246 ;
F_237 ( V_15 ) ;
F_215 ( V_15 , V_192 , V_192 -> V_149 ) ;
F_216 ( V_15 , V_192 ) ;
F_260 ( & V_15 -> V_18 ) ;
F_193 ( V_15 -> V_190 ) ;
V_15 -> V_190 = NULL ;
F_238 ( & V_266 ) ;
F_99 ( & V_15 -> V_267 ) ;
F_239 ( & V_266 ) ;
}
static void F_261 ( struct V_14 * V_15 )
{
F_29 ( ! F_12 ( & V_15 -> V_22 ) ) ;
F_262 ( V_15 ) ;
F_263 ( V_15 -> V_190 , V_15 -> V_149 ) ;
F_230 ( V_15 ) ;
F_264 ( V_15 ) ;
}
static int F_265 ( struct V_269 * V_270 ,
unsigned long V_229 , void * V_271 )
{
struct V_14 * V_15 ;
if ( V_229 != V_230 && V_229 != V_231 &&
V_229 != V_272 && V_229 != V_273 )
return V_228 ;
F_238 ( & V_266 ) ;
F_236 (q, &all_q_list, all_q_node)
F_19 ( V_15 ) ;
F_236 (q, &all_q_list, all_q_node) {
F_23 ( V_15 ) ;
F_266 ( & V_15 -> V_56 ) ;
}
F_236 (q, &all_q_list, all_q_node)
F_261 ( V_15 ) ;
F_236 (q, &all_q_list, all_q_node)
F_27 ( V_15 ) ;
F_239 ( & V_266 ) ;
return V_228 ;
}
static int F_267 ( struct V_191 * V_192 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_192 -> V_149 ; V_3 ++ ) {
V_192 -> V_27 [ V_3 ] = F_196 ( V_192 , V_3 ) ;
if ( ! V_192 -> V_27 [ V_3 ] )
goto V_274;
}
return 0 ;
V_274:
while ( -- V_3 >= 0 )
F_191 ( V_192 , V_192 -> V_27 [ V_3 ] , V_3 ) ;
return - V_226 ;
}
static int F_268 ( struct V_191 * V_192 )
{
unsigned int V_127 ;
int V_275 ;
V_127 = V_192 -> V_208 ;
do {
V_275 = F_267 ( V_192 ) ;
if ( ! V_275 )
break;
V_192 -> V_208 >>= 1 ;
if ( V_192 -> V_208 < V_192 -> V_209 + V_276 ) {
V_275 = - V_226 ;
break;
}
} while ( V_192 -> V_208 );
if ( ! V_192 -> V_208 || V_275 ) {
F_142 ( L_3 ) ;
return - V_226 ;
}
if ( V_127 != V_192 -> V_208 )
F_269 ( L_4 ,
V_127 , V_192 -> V_208 ) ;
return 0 ;
}
struct V_134 * F_270 ( struct V_103 * V_27 )
{
return V_27 -> V_134 ;
}
int F_271 ( struct V_191 * V_192 )
{
F_272 ( V_277 > 1 << V_278 ) ;
if ( ! V_192 -> V_149 )
return - V_279 ;
if ( ! V_192 -> V_208 )
return - V_279 ;
if ( V_192 -> V_208 < V_192 -> V_209 + V_276 )
return - V_279 ;
if ( ! V_192 -> V_106 -> V_142 || ! V_192 -> V_106 -> V_72 )
return - V_279 ;
if ( V_192 -> V_208 > V_277 ) {
F_269 ( L_5 ,
V_277 ) ;
V_192 -> V_208 = V_277 ;
}
if ( F_273 () ) {
V_192 -> V_149 = 1 ;
V_192 -> V_208 = F_204 ( 64U , V_192 -> V_208 ) ;
}
V_192 -> V_27 = F_223 ( V_192 -> V_149 *
sizeof( struct V_103 * ) ,
V_175 , V_192 -> V_210 ) ;
if ( ! V_192 -> V_27 )
return - V_226 ;
if ( F_268 ( V_192 ) )
goto V_280;
F_274 ( & V_192 -> V_249 ) ;
F_39 ( & V_192 -> V_247 ) ;
return 0 ;
V_280:
F_193 ( V_192 -> V_27 ) ;
V_192 -> V_27 = NULL ;
return - V_226 ;
}
void F_275 ( struct V_191 * V_192 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_192 -> V_149 ; V_3 ++ ) {
if ( V_192 -> V_27 [ V_3 ] ) {
F_191 ( V_192 , V_192 -> V_27 [ V_3 ] , V_3 ) ;
F_217 ( V_192 -> V_27 [ V_3 ] -> V_134 ) ;
}
}
F_193 ( V_192 -> V_27 ) ;
V_192 -> V_27 = NULL ;
}
int F_276 ( struct V_14 * V_15 , unsigned int V_281 )
{
struct V_191 * V_192 = V_15 -> V_246 ;
struct V_1 * V_2 ;
int V_3 , V_17 ;
if ( ! V_192 || V_281 > V_192 -> V_208 )
return - V_279 ;
V_17 = 0 ;
F_32 (q, hctx, i) {
V_17 = F_277 ( V_2 -> V_27 , V_281 ) ;
if ( V_17 )
break;
}
if ( ! V_17 )
V_15 -> V_264 = V_281 ;
return V_17 ;
}
void F_278 ( void )
{
F_238 ( & V_266 ) ;
}
void F_279 ( void )
{
F_239 ( & V_266 ) ;
}
static int T_4 F_280 ( void )
{
F_281 () ;
F_282 ( F_265 , 0 ) ;
return 0 ;
}
