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
void F_18 ( struct V_14 * V_15 )
{
bool V_23 ;
F_19 ( V_15 -> V_24 ) ;
V_23 = ! V_15 -> V_19 ++ ;
F_20 ( V_15 -> V_24 ) ;
if ( V_23 ) {
F_21 ( & V_15 -> V_17 ) ;
F_22 ( V_15 ) ;
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
void F_27 ( struct V_14 * V_15 )
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
void F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i)
if ( F_32 ( V_2 ) )
F_33 ( V_2 -> V_26 , true ) ;
F_17 ( & V_15 -> V_18 ) ;
}
bool F_34 ( struct V_1 * V_2 )
{
return F_35 ( V_2 -> V_26 ) ;
}
static void F_36 ( struct V_14 * V_15 , struct V_9 * V_10 ,
struct V_27 * V_28 , unsigned int V_29 )
{
if ( F_37 ( V_15 ) )
V_29 |= V_30 ;
F_38 ( & V_28 -> V_31 ) ;
V_28 -> V_15 = V_15 ;
V_28 -> V_32 = V_10 ;
V_28 -> V_33 |= V_29 ;
V_28 -> V_34 = - 1 ;
F_39 ( & V_28 -> V_35 ) ;
F_40 ( & V_28 -> V_36 ) ;
V_28 -> V_37 = NULL ;
V_28 -> V_38 = NULL ;
V_28 -> V_39 = V_40 ;
#ifdef F_41
V_28 -> V_41 = NULL ;
F_42 ( V_28 ) ;
V_28 -> V_42 = 0 ;
#endif
V_28 -> V_43 = 0 ;
#if F_43 ( V_44 )
V_28 -> V_45 = 0 ;
#endif
V_28 -> V_46 = NULL ;
V_28 -> V_47 = 0 ;
V_28 -> V_48 = V_28 -> V_49 ;
V_28 -> V_50 = 0 ;
V_28 -> V_51 = 0 ;
V_28 -> V_52 = 0 ;
V_28 -> V_53 = NULL ;
F_38 ( & V_28 -> V_54 ) ;
V_28 -> V_55 = 0 ;
V_28 -> V_56 = NULL ;
V_28 -> V_57 = NULL ;
V_28 -> V_58 = NULL ;
V_10 -> V_59 [ F_44 ( V_29 ) ] ++ ;
}
static struct V_27 *
F_45 ( struct V_60 * V_61 , int V_62 )
{
struct V_27 * V_28 ;
unsigned int V_63 ;
V_63 = F_46 ( V_61 ) ;
if ( V_63 != V_64 ) {
V_28 = V_61 -> V_2 -> V_26 -> V_65 [ V_63 ] ;
if ( F_47 ( V_61 -> V_2 ) ) {
V_28 -> V_33 = V_66 ;
F_48 ( & V_61 -> V_2 -> V_67 ) ;
}
V_28 -> V_63 = V_63 ;
F_36 ( V_61 -> V_15 , V_61 -> V_10 , V_28 , V_62 ) ;
return V_28 ;
}
return NULL ;
}
struct V_27 * F_49 ( struct V_14 * V_15 , int V_62 , T_1 V_68 ,
bool V_69 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_60 V_70 ;
int V_16 ;
V_16 = F_9 ( V_15 ) ;
if ( V_16 )
return F_50 ( V_16 ) ;
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_52 ( & V_70 , V_15 , V_68 & ~ V_73 ,
V_69 , V_10 , V_2 ) ;
V_28 = F_45 ( & V_70 , V_62 ) ;
if ( ! V_28 && ( V_68 & V_73 ) ) {
F_53 ( V_2 ) ;
F_54 ( V_10 ) ;
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_52 ( & V_70 , V_15 , V_68 , V_69 , V_10 ,
V_2 ) ;
V_28 = F_45 ( & V_70 , V_62 ) ;
V_10 = V_70 . V_10 ;
}
F_54 ( V_10 ) ;
if ( ! V_28 ) {
F_13 ( V_15 ) ;
return F_50 ( - V_74 ) ;
}
return V_28 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_27 * V_28 )
{
const int V_63 = V_28 -> V_63 ;
struct V_14 * V_15 = V_28 -> V_15 ;
if ( V_28 -> V_33 & V_66 )
F_56 ( & V_2 -> V_67 ) ;
V_28 -> V_33 = 0 ;
F_8 ( V_75 , & V_28 -> V_76 ) ;
F_57 ( V_2 , V_63 , & V_10 -> V_77 ) ;
F_13 ( V_15 ) ;
}
void F_58 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
V_10 -> V_78 [ F_59 ( V_28 ) ] ++ ;
F_55 ( V_2 , V_10 , V_28 ) ;
}
void F_60 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = V_28 -> V_15 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_28 -> V_32 -> V_34 ) ;
F_58 ( V_2 , V_28 ) ;
}
inline void F_61 ( struct V_27 * V_28 , int error )
{
F_62 ( V_28 ) ;
if ( V_28 -> V_56 ) {
V_28 -> V_56 ( V_28 , error ) ;
} else {
if ( F_63 ( F_64 ( V_28 ) ) )
F_60 ( V_28 -> V_58 ) ;
F_60 ( V_28 ) ;
}
}
void F_65 ( struct V_27 * V_28 , int error )
{
if ( F_66 ( V_28 , error , F_67 ( V_28 ) ) )
F_68 () ;
F_61 ( V_28 , error ) ;
}
static void F_69 ( void * V_61 )
{
struct V_27 * V_28 = V_61 ;
V_28 -> V_15 -> V_79 ( V_28 ) ;
}
static void F_70 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
bool V_80 = false ;
int V_34 ;
if ( ! F_4 ( V_81 , & V_28 -> V_15 -> V_82 ) ) {
V_28 -> V_15 -> V_79 ( V_28 ) ;
return;
}
V_34 = F_71 () ;
if ( ! F_4 ( V_83 , & V_28 -> V_15 -> V_82 ) )
V_80 = F_72 ( V_34 , V_10 -> V_34 ) ;
if ( V_34 != V_10 -> V_34 && ! V_80 && F_73 ( V_10 -> V_34 ) ) {
V_28 -> V_84 . V_85 = F_69 ;
V_28 -> V_84 . V_86 = V_28 ;
V_28 -> V_84 . V_87 = 0 ;
F_74 ( V_10 -> V_34 , & V_28 -> V_84 ) ;
} else {
V_28 -> V_15 -> V_79 ( V_28 ) ;
}
F_75 () ;
}
void F_76 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( ! V_15 -> V_79 )
F_65 ( V_28 , V_28 -> V_47 ) ;
else
F_70 ( V_28 ) ;
}
void F_77 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( F_63 ( F_78 ( V_15 ) ) )
return;
if ( ! F_79 ( V_28 ) )
F_76 ( V_28 ) ;
}
int F_80 ( struct V_27 * V_28 )
{
return F_4 ( V_75 , & V_28 -> V_76 ) ;
}
void F_81 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_82 ( V_15 , V_28 ) ;
V_28 -> V_52 = F_67 ( V_28 ) ;
if ( F_63 ( F_64 ( V_28 ) ) )
V_28 -> V_58 -> V_52 = F_67 ( V_28 -> V_58 ) ;
F_83 ( V_28 ) ;
F_84 () ;
if ( ! F_4 ( V_75 , & V_28 -> V_76 ) )
F_6 ( V_75 , & V_28 -> V_76 ) ;
if ( F_4 ( V_88 , & V_28 -> V_76 ) )
F_8 ( V_88 , & V_28 -> V_76 ) ;
if ( V_15 -> V_89 && F_67 ( V_28 ) ) {
V_28 -> V_43 ++ ;
}
}
static void F_85 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_86 ( V_15 , V_28 ) ;
if ( F_87 ( V_75 , & V_28 -> V_76 ) ) {
if ( V_15 -> V_89 && F_67 ( V_28 ) )
V_28 -> V_43 -- ;
}
}
void F_88 ( struct V_27 * V_28 )
{
F_85 ( V_28 ) ;
F_89 ( F_90 ( V_28 ) ) ;
F_91 ( V_28 , true ) ;
}
static void F_92 ( struct V_90 * V_91 )
{
struct V_14 * V_15 =
F_16 ( V_91 , struct V_14 , V_92 ) ;
F_93 ( V_93 ) ;
struct V_27 * V_28 , * V_94 ;
unsigned long V_87 ;
F_94 ( & V_15 -> V_95 , V_87 ) ;
F_95 ( & V_15 -> V_96 , & V_93 ) ;
F_96 ( & V_15 -> V_95 , V_87 ) ;
F_97 (rq, next, &rq_list, queuelist) {
if ( ! ( V_28 -> V_33 & V_97 ) )
continue;
V_28 -> V_33 &= ~ V_97 ;
F_98 ( & V_28 -> V_31 ) ;
F_99 ( V_28 , true , false , false ) ;
}
while ( ! F_100 ( & V_93 ) ) {
V_28 = F_101 ( V_93 . V_94 , struct V_27 , V_31 ) ;
F_98 ( & V_28 -> V_31 ) ;
F_99 ( V_28 , false , false , false ) ;
}
F_102 ( V_15 ) ;
}
void F_91 ( struct V_27 * V_28 , bool V_98 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
unsigned long V_87 ;
F_89 ( V_28 -> V_33 & V_97 ) ;
F_94 ( & V_15 -> V_95 , V_87 ) ;
if ( V_98 ) {
V_28 -> V_33 |= V_97 ;
F_103 ( & V_28 -> V_31 , & V_15 -> V_96 ) ;
} else {
F_104 ( & V_28 -> V_31 , & V_15 -> V_96 ) ;
}
F_96 ( & V_15 -> V_95 , V_87 ) ;
}
void F_105 ( struct V_14 * V_15 )
{
F_106 ( & V_15 -> V_92 ) ;
}
void F_107 ( struct V_14 * V_15 )
{
F_108 ( & V_15 -> V_92 ) ;
}
void F_109 ( struct V_14 * V_15 )
{
unsigned long V_87 ;
F_93 ( V_93 ) ;
F_94 ( & V_15 -> V_95 , V_87 ) ;
F_95 ( & V_15 -> V_96 , & V_93 ) ;
F_96 ( & V_15 -> V_95 , V_87 ) ;
while ( ! F_100 ( & V_93 ) ) {
struct V_27 * V_28 ;
V_28 = F_110 ( & V_93 , struct V_27 , V_31 ) ;
F_98 ( & V_28 -> V_31 ) ;
V_28 -> V_47 = - V_99 ;
F_65 ( V_28 , V_28 -> V_47 ) ;
}
}
static inline bool F_111 ( struct V_27 * V_28 ,
struct V_100 * V_101 , unsigned int V_63 )
{
return ( ( V_28 -> V_33 & V_102 ) &&
V_101 -> V_103 -> V_63 == V_63 ) ;
}
struct V_27 * F_112 ( struct V_104 * V_26 , unsigned int V_63 )
{
struct V_27 * V_28 = V_26 -> V_65 [ V_63 ] ;
struct V_100 * V_101 = F_113 ( V_28 -> V_15 , V_28 -> V_32 ) ;
if ( ! F_111 ( V_28 , V_101 , V_63 ) )
return V_28 ;
return V_101 -> V_103 ;
}
void F_114 ( struct V_27 * V_105 , bool V_69 )
{
struct V_106 * V_107 = V_105 -> V_15 -> V_71 ;
enum V_108 V_16 = V_109 ;
if ( ! F_4 ( V_75 , & V_105 -> V_76 ) )
return;
if ( V_107 -> V_55 )
V_16 = V_107 -> V_55 ( V_105 , V_69 ) ;
switch ( V_16 ) {
case V_110 :
F_76 ( V_105 ) ;
break;
case V_109 :
F_83 ( V_105 ) ;
F_115 ( V_105 ) ;
break;
case V_111 :
break;
default:
F_116 ( V_112 L_1 , V_16 ) ;
break;
}
}
static void F_117 ( struct V_1 * V_2 ,
struct V_27 * V_28 , void * V_113 , bool V_69 )
{
struct V_114 * V_61 = V_113 ;
if ( ! F_4 ( V_75 , & V_28 -> V_76 ) ) {
if ( F_63 ( F_12 ( V_28 -> V_15 ) ) ) {
V_28 -> V_47 = - V_99 ;
F_77 ( V_28 ) ;
}
return;
}
if ( V_28 -> V_33 & V_115 )
return;
if ( F_118 ( V_40 , V_28 -> V_116 ) ) {
if ( ! F_79 ( V_28 ) )
F_114 ( V_28 , V_69 ) ;
} else if ( ! V_61 -> V_117 || F_119 ( V_61 -> V_94 , V_28 -> V_116 ) ) {
V_61 -> V_94 = V_28 -> V_116 ;
V_61 -> V_117 = 1 ;
}
}
static void F_120 ( unsigned long V_113 )
{
struct V_14 * V_15 = (struct V_14 * ) V_113 ;
struct V_114 V_61 = {
. V_94 = 0 ,
. V_117 = 0 ,
} ;
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i) {
if ( ! F_32 ( V_2 ) )
continue;
F_121 ( V_2 , F_117 , & V_61 ) ;
}
if ( V_61 . V_117 ) {
V_61 . V_94 = F_122 ( F_123 ( V_61 . V_94 ) ) ;
F_124 ( & V_15 -> V_55 , V_61 . V_94 ) ;
} else {
F_31 (q, hctx, i)
F_125 ( V_2 ) ;
}
}
static bool F_126 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_118 * V_118 )
{
struct V_27 * V_28 ;
int V_119 = 8 ;
F_127 (rq, &ctx->rq_list, queuelist) {
int V_120 ;
if ( ! V_119 -- )
break;
if ( ! F_128 ( V_28 , V_118 ) )
continue;
V_120 = F_129 ( V_28 , V_118 ) ;
if ( V_120 == V_121 ) {
if ( F_130 ( V_15 , V_28 , V_118 ) ) {
V_10 -> V_122 ++ ;
return true ;
}
break;
} else if ( V_120 == V_123 ) {
if ( F_131 ( V_15 , V_28 , V_118 ) ) {
V_10 -> V_122 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_132 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
struct V_9 * V_10 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_8 * V_13 = & V_2 -> V_4 . V_6 [ V_3 ] ;
unsigned int V_126 , V_127 ;
if ( ! V_13 -> V_7 )
continue;
V_127 = 0 ;
V_126 = V_3 * V_2 -> V_4 . V_12 ;
do {
V_127 = F_133 ( & V_13 -> V_7 , V_13 -> V_128 , V_127 ) ;
if ( V_127 >= V_13 -> V_128 )
break;
V_10 = V_2 -> V_129 [ V_127 + V_126 ] ;
F_8 ( V_127 , & V_13 -> V_7 ) ;
F_134 ( & V_10 -> V_130 ) ;
F_135 ( & V_10 -> V_93 , V_125 ) ;
F_136 ( & V_10 -> V_130 ) ;
V_127 ++ ;
} while ( 1 );
}
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_131 ;
struct V_27 * V_28 ;
F_93 ( V_93 ) ;
F_93 ( V_132 ) ;
struct V_124 * V_133 ;
int V_134 ;
F_137 ( ! F_138 ( F_139 () , V_2 -> V_135 ) ) ;
if ( F_63 ( F_4 ( V_136 , & V_2 -> V_137 ) ) )
return;
V_2 -> V_138 ++ ;
F_132 ( V_2 , & V_93 ) ;
if ( ! F_140 ( & V_2 -> V_139 ) ) {
F_134 ( & V_2 -> V_130 ) ;
if ( ! F_100 ( & V_2 -> V_139 ) )
F_95 ( & V_2 -> V_139 , & V_93 ) ;
F_136 ( & V_2 -> V_130 ) ;
}
V_133 = NULL ;
V_134 = 0 ;
while ( ! F_100 ( & V_93 ) ) {
struct V_140 V_141 ;
int V_16 ;
V_28 = F_110 ( & V_93 , struct V_27 , V_31 ) ;
F_98 ( & V_28 -> V_31 ) ;
V_141 . V_28 = V_28 ;
V_141 . V_125 = V_133 ;
V_141 . V_142 = F_100 ( & V_93 ) ;
V_16 = V_15 -> V_71 -> V_143 ( V_2 , & V_141 ) ;
switch ( V_16 ) {
case V_144 :
V_134 ++ ;
continue;
case V_145 :
F_103 ( & V_28 -> V_31 , & V_93 ) ;
F_85 ( V_28 ) ;
break;
default:
F_141 ( L_2 , V_16 ) ;
case V_146 :
V_28 -> V_47 = - V_99 ;
F_65 ( V_28 , V_28 -> V_47 ) ;
break;
}
if ( V_16 == V_145 )
break;
if ( ! V_133 && V_93 . V_94 != V_93 . V_147 )
V_133 = & V_132 ;
}
if ( ! V_134 )
V_2 -> V_148 [ 0 ] ++ ;
else if ( V_134 < ( 1 << ( V_149 - 1 ) ) )
V_2 -> V_148 [ F_142 ( V_134 ) + 1 ] ++ ;
if ( ! F_100 ( & V_93 ) ) {
F_134 ( & V_2 -> V_130 ) ;
F_143 ( & V_93 , & V_2 -> V_139 ) ;
F_136 ( & V_2 -> V_130 ) ;
}
}
static int F_144 ( struct V_1 * V_2 )
{
if ( V_2 -> V_131 -> V_150 == 1 )
return V_151 ;
if ( -- V_2 -> V_152 <= 0 ) {
int V_34 = V_2 -> V_153 , V_153 ;
V_153 = F_145 ( V_2 -> V_153 , V_2 -> V_135 ) ;
if ( V_153 >= V_154 )
V_153 = F_146 ( V_2 -> V_135 ) ;
V_2 -> V_153 = V_153 ;
V_2 -> V_152 = V_155 ;
return V_34 ;
}
return V_2 -> V_153 ;
}
void F_147 ( struct V_1 * V_2 , bool V_156 )
{
if ( F_63 ( F_4 ( V_136 , & V_2 -> V_137 ) ||
! F_32 ( V_2 ) ) )
return;
if ( ! V_156 ) {
int V_34 = F_71 () ;
if ( F_138 ( V_34 , V_2 -> V_135 ) ) {
F_53 ( V_2 ) ;
F_75 () ;
return;
}
F_75 () ;
}
F_148 ( F_144 ( V_2 ) ,
& V_2 -> V_157 , 0 ) ;
}
static void F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_140 ( & V_2 -> V_139 ) ) ||
F_4 ( V_136 , & V_2 -> V_137 ) )
continue;
F_147 ( V_2 , false ) ;
}
}
void F_149 ( struct V_1 * V_2 )
{
F_150 ( & V_2 -> V_157 ) ;
F_150 ( & V_2 -> V_158 ) ;
F_6 ( V_136 , & V_2 -> V_137 ) ;
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
F_8 ( V_136 , & V_2 -> V_137 ) ;
F_147 ( V_2 , false ) ;
}
void F_102 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i)
F_152 ( V_2 ) ;
}
void F_153 ( struct V_14 * V_15 , bool V_156 )
{
struct V_1 * V_2 ;
int V_3 ;
F_31 (q, hctx, i) {
if ( ! F_4 ( V_136 , & V_2 -> V_137 ) )
continue;
F_8 ( V_136 , & V_2 -> V_137 ) ;
F_147 ( V_2 , V_156 ) ;
}
}
static void F_154 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_91 , struct V_1 , V_157 . V_91 ) ;
F_53 ( V_2 ) ;
}
static void F_155 ( struct V_90 * V_91 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_91 , struct V_1 , V_158 . V_91 ) ;
if ( F_87 ( V_136 , & V_2 -> V_137 ) )
F_53 ( V_2 ) ;
}
void F_156 ( struct V_1 * V_2 , unsigned long V_159 )
{
if ( F_63 ( ! F_32 ( V_2 ) ) )
return;
F_148 ( F_144 ( V_2 ) ,
& V_2 -> V_158 , F_157 ( V_159 ) ) ;
}
static void F_158 ( struct V_1 * V_2 ,
struct V_27 * V_28 , bool V_98 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
F_159 ( V_2 -> V_131 , V_28 ) ;
if ( V_98 )
F_103 ( & V_28 -> V_31 , & V_10 -> V_93 ) ;
else
F_104 ( & V_28 -> V_31 , & V_10 -> V_93 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_99 ( struct V_27 * V_28 , bool V_98 , bool V_160 ,
bool V_156 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_28 -> V_32 , * V_161 ;
V_161 = F_51 ( V_15 ) ;
if ( ! F_73 ( V_10 -> V_34 ) )
V_28 -> V_32 = V_10 = V_161 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_134 ( & V_10 -> V_130 ) ;
F_158 ( V_2 , V_28 , V_98 ) ;
F_136 ( & V_10 -> V_130 ) ;
if ( V_160 )
F_147 ( V_2 , V_156 ) ;
F_54 ( V_161 ) ;
}
static void F_160 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_124 * V_125 ,
int V_128 ,
bool V_162 )
{
struct V_1 * V_2 ;
struct V_9 * V_161 ;
F_161 ( V_15 , V_128 , ! V_162 ) ;
V_161 = F_51 ( V_15 ) ;
if ( ! F_73 ( V_10 -> V_34 ) )
V_10 = V_161 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_134 ( & V_10 -> V_130 ) ;
while ( ! F_100 ( V_125 ) ) {
struct V_27 * V_28 ;
V_28 = F_110 ( V_125 , struct V_27 , V_31 ) ;
F_98 ( & V_28 -> V_31 ) ;
V_28 -> V_32 = V_10 ;
F_158 ( V_2 , V_28 , false ) ;
}
F_136 ( & V_10 -> V_130 ) ;
F_147 ( V_2 , V_162 ) ;
F_54 ( V_161 ) ;
}
static int F_162 ( void * V_113 , struct V_124 * V_163 , struct V_124 * V_164 )
{
struct V_27 * V_165 = F_16 ( V_163 , struct V_27 , V_31 ) ;
struct V_27 * V_166 = F_16 ( V_164 , struct V_27 , V_31 ) ;
return ! ( V_165 -> V_32 < V_166 -> V_32 ||
( V_165 -> V_32 == V_166 -> V_32 &&
F_163 ( V_165 ) < F_163 ( V_166 ) ) ) ;
}
void F_164 ( struct V_167 * V_168 , bool V_162 )
{
struct V_9 * V_169 ;
struct V_14 * V_170 ;
struct V_27 * V_28 ;
F_93 ( V_125 ) ;
F_93 ( V_171 ) ;
unsigned int V_128 ;
F_95 ( & V_168 -> V_172 , & V_125 ) ;
F_165 ( NULL , & V_125 , F_162 ) ;
V_170 = NULL ;
V_169 = NULL ;
V_128 = 0 ;
while ( ! F_100 ( & V_125 ) ) {
V_28 = F_166 ( V_125 . V_94 ) ;
F_98 ( & V_28 -> V_31 ) ;
F_89 ( ! V_28 -> V_15 ) ;
if ( V_28 -> V_32 != V_169 ) {
if ( V_169 ) {
F_160 ( V_170 , V_169 ,
& V_171 , V_128 ,
V_162 ) ;
}
V_169 = V_28 -> V_32 ;
V_170 = V_28 -> V_15 ;
V_128 = 0 ;
}
V_128 ++ ;
F_104 ( & V_28 -> V_31 , & V_171 ) ;
}
if ( V_169 ) {
F_160 ( V_170 , V_169 , & V_171 , V_128 ,
V_162 ) ;
}
}
static void F_167 ( struct V_27 * V_28 , struct V_118 * V_118 )
{
F_168 ( V_28 , V_118 ) ;
if ( F_169 ( V_28 ) )
F_170 ( V_28 , 1 ) ;
}
static inline bool F_171 ( struct V_1 * V_2 )
{
return ( V_2 -> V_87 & V_173 ) &&
! F_172 ( V_2 -> V_131 ) ;
}
static inline bool F_173 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_27 * V_28 , struct V_118 * V_118 )
{
if ( ! F_171 ( V_2 ) ) {
F_167 ( V_28 , V_118 ) ;
F_134 ( & V_10 -> V_130 ) ;
V_174:
F_158 ( V_2 , V_28 , false ) ;
F_136 ( & V_10 -> V_130 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_131 ;
F_134 ( & V_10 -> V_130 ) ;
if ( ! F_126 ( V_15 , V_10 , V_118 ) ) {
F_167 ( V_28 , V_118 ) ;
goto V_174;
}
F_136 ( & V_10 -> V_130 ) ;
F_55 ( V_2 , V_10 , V_28 ) ;
return true ;
}
}
static struct V_27 * F_174 ( struct V_14 * V_15 ,
struct V_118 * V_118 ,
struct V_175 * V_61 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
int V_62 = F_175 ( V_118 ) ;
struct V_60 V_70 ;
if ( F_63 ( F_9 ( V_15 ) ) ) {
F_176 ( V_118 , - V_99 ) ;
return NULL ;
}
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
if ( F_44 ( V_118 -> V_176 ) )
V_62 |= V_177 ;
F_177 ( V_15 , V_118 , V_62 ) ;
F_52 ( & V_70 , V_15 , V_178 , false , V_10 ,
V_2 ) ;
V_28 = F_45 ( & V_70 , V_62 ) ;
if ( F_63 ( ! V_28 ) ) {
F_53 ( V_2 ) ;
F_54 ( V_10 ) ;
F_178 ( V_15 , V_118 , V_62 ) ;
V_10 = F_51 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_52 ( & V_70 , V_15 ,
V_73 | V_178 , false , V_10 , V_2 ) ;
V_28 = F_45 ( & V_70 , V_62 ) ;
V_10 = V_70 . V_10 ;
V_2 = V_70 . V_2 ;
}
V_2 -> V_134 ++ ;
V_61 -> V_2 = V_2 ;
V_61 -> V_10 = V_10 ;
return V_28 ;
}
static void F_179 ( struct V_14 * V_15 , struct V_118 * V_118 )
{
const int V_179 = F_44 ( V_118 -> V_176 ) ;
const int V_180 = V_118 -> V_176 & ( V_181 | V_182 ) ;
struct V_175 V_61 ;
struct V_27 * V_28 ;
F_180 ( V_15 , & V_118 ) ;
if ( F_181 ( V_118 ) && F_182 ( V_118 ) ) {
F_176 ( V_118 , - V_99 ) ;
return;
}
V_28 = F_174 ( V_15 , V_118 , & V_61 ) ;
if ( F_63 ( ! V_28 ) )
return;
if ( F_63 ( V_180 ) ) {
F_167 ( V_28 , V_118 ) ;
F_183 ( V_28 ) ;
goto V_160;
}
if ( V_179 && ! ( V_61 . V_2 -> V_87 & V_183 ) ) {
struct V_140 V_141 = {
. V_28 = V_28 ,
. V_125 = NULL ,
. V_142 = 1
} ;
int V_16 ;
F_167 ( V_28 , V_118 ) ;
V_16 = V_15 -> V_71 -> V_143 ( V_61 . V_2 , & V_141 ) ;
if ( V_16 == V_144 )
goto V_184;
else {
F_85 ( V_28 ) ;
if ( V_16 == V_146 ) {
V_28 -> V_47 = - V_99 ;
F_65 ( V_28 , V_28 -> V_47 ) ;
goto V_184;
}
}
}
if ( ! F_173 ( V_61 . V_2 , V_61 . V_10 , V_28 , V_118 ) ) {
V_160:
F_147 ( V_61 . V_2 , ! V_179 || V_180 ) ;
}
V_184:
F_54 ( V_61 . V_10 ) ;
}
static void F_184 ( struct V_14 * V_15 , struct V_118 * V_118 )
{
const int V_179 = F_44 ( V_118 -> V_176 ) ;
const int V_180 = V_118 -> V_176 & ( V_181 | V_182 ) ;
unsigned int V_185 , V_186 = 0 ;
struct V_175 V_61 ;
struct V_27 * V_28 ;
V_185 = ! V_180 && ! V_179 ;
F_180 ( V_15 , & V_118 ) ;
if ( F_181 ( V_118 ) && F_182 ( V_118 ) ) {
F_176 ( V_118 , - V_99 ) ;
return;
}
if ( V_185 && ! F_172 ( V_15 ) &&
F_185 ( V_15 , V_118 , & V_186 ) )
return;
V_28 = F_174 ( V_15 , V_118 , & V_61 ) ;
if ( F_63 ( ! V_28 ) )
return;
if ( F_63 ( V_180 ) ) {
F_167 ( V_28 , V_118 ) ;
F_183 ( V_28 ) ;
goto V_160;
}
if ( V_185 ) {
struct V_167 * V_168 = V_187 -> V_168 ;
if ( V_168 ) {
F_167 ( V_28 , V_118 ) ;
if ( F_100 ( & V_168 -> V_172 ) )
F_186 ( V_15 ) ;
else if ( V_186 >= V_188 ) {
F_187 ( V_168 , false ) ;
F_186 ( V_15 ) ;
}
F_104 ( & V_28 -> V_31 , & V_168 -> V_172 ) ;
F_54 ( V_61 . V_10 ) ;
return;
}
}
if ( ! F_173 ( V_61 . V_2 , V_61 . V_10 , V_28 , V_118 ) ) {
V_160:
F_147 ( V_61 . V_2 , ! V_179 || V_180 ) ;
}
F_54 ( V_61 . V_10 ) ;
}
struct V_1 * F_188 ( struct V_14 * V_15 , const int V_34 )
{
return V_15 -> V_189 [ V_15 -> V_190 [ V_34 ] ] ;
}
static void F_189 ( struct V_191 * V_192 ,
struct V_104 * V_26 , unsigned int V_193 )
{
struct V_194 * V_194 ;
if ( V_26 -> V_65 && V_192 -> V_107 -> V_195 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_196 ; V_3 ++ ) {
if ( ! V_26 -> V_65 [ V_3 ] )
continue;
V_192 -> V_107 -> V_195 ( V_192 -> V_197 , V_26 -> V_65 [ V_3 ] ,
V_193 , V_3 ) ;
V_26 -> V_65 [ V_3 ] = NULL ;
}
}
while ( ! F_100 ( & V_26 -> V_198 ) ) {
V_194 = F_110 ( & V_26 -> V_198 , struct V_194 , V_199 ) ;
F_98 ( & V_194 -> V_199 ) ;
F_190 ( V_194 , V_194 -> V_200 ) ;
}
F_191 ( V_26 -> V_65 ) ;
F_192 ( V_26 ) ;
}
static T_2 F_193 ( unsigned int V_201 )
{
return ( T_2 ) V_202 << V_201 ;
}
static struct V_104 * F_194 ( struct V_191 * V_192 ,
unsigned int V_193 )
{
struct V_104 * V_26 ;
unsigned int V_3 , V_203 , V_204 , V_205 = 4 ;
T_2 V_206 , V_207 ;
V_26 = F_195 ( V_192 -> V_208 , V_192 -> V_209 ,
V_192 -> V_210 ,
F_196 ( V_192 -> V_87 ) ) ;
if ( ! V_26 )
return NULL ;
F_38 ( & V_26 -> V_198 ) ;
V_26 -> V_65 = F_197 ( V_192 -> V_208 * sizeof( struct V_27 * ) ,
V_211 | V_212 | V_213 ,
V_192 -> V_210 ) ;
if ( ! V_26 -> V_65 ) {
F_192 ( V_26 ) ;
return NULL ;
}
V_206 = F_198 ( sizeof( struct V_27 ) + V_192 -> V_214 ,
F_199 () ) ;
V_207 = V_206 * V_192 -> V_208 ;
for ( V_3 = 0 ; V_3 < V_192 -> V_208 ; ) {
int V_215 = V_205 ;
struct V_194 * V_194 ;
int V_216 ;
void * V_217 ;
while ( V_207 < F_193 ( V_215 - 1 ) && V_215 )
V_215 -- ;
do {
V_194 = F_200 ( V_192 -> V_210 ,
V_211 | V_212 | V_213 | V_218 ,
V_215 ) ;
if ( V_194 )
break;
if ( ! V_215 -- )
break;
if ( F_193 ( V_215 ) < V_206 )
break;
} while ( 1 );
if ( ! V_194 )
goto V_219;
V_194 -> V_200 = V_215 ;
F_104 ( & V_194 -> V_199 , & V_26 -> V_198 ) ;
V_217 = F_201 ( V_194 ) ;
V_204 = F_193 ( V_215 ) / V_206 ;
V_216 = F_202 ( V_204 , V_192 -> V_208 - V_3 ) ;
V_207 -= V_216 * V_206 ;
for ( V_203 = 0 ; V_203 < V_216 ; V_203 ++ ) {
V_26 -> V_65 [ V_3 ] = V_217 ;
if ( V_192 -> V_107 -> V_220 ) {
if ( V_192 -> V_107 -> V_220 ( V_192 -> V_197 ,
V_26 -> V_65 [ V_3 ] , V_193 , V_3 ,
V_192 -> V_210 ) ) {
V_26 -> V_65 [ V_3 ] = NULL ;
goto V_219;
}
}
V_217 += V_206 ;
V_3 ++ ;
}
}
return V_26 ;
V_219:
F_189 ( V_192 , V_26 , V_193 ) ;
return NULL ;
}
static void F_203 ( struct V_221 * V_222 )
{
F_191 ( V_222 -> V_6 ) ;
}
static int F_204 ( struct V_221 * V_222 , int V_223 )
{
unsigned int V_224 = 8 , V_225 , V_226 , V_3 ;
V_222 -> V_12 = V_224 ;
V_226 = F_205 ( V_154 , V_224 ) / V_224 ;
V_222 -> V_6 = F_197 ( V_226 * sizeof( struct V_8 ) ,
V_211 , V_223 ) ;
if ( ! V_222 -> V_6 )
return - V_227 ;
V_222 -> V_5 = V_226 ;
V_225 = V_154 ;
for ( V_3 = 0 ; V_3 < V_226 ; V_3 ++ ) {
V_222 -> V_6 [ V_3 ] . V_128 = F_202 ( V_225 , V_222 -> V_12 ) ;
V_225 -= V_222 -> V_6 [ V_3 ] . V_128 ;
}
return 0 ;
}
static int F_206 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_131 ;
struct V_9 * V_10 ;
F_93 ( V_228 ) ;
V_10 = F_207 ( V_15 , V_34 ) ;
F_134 ( & V_10 -> V_130 ) ;
if ( ! F_100 ( & V_10 -> V_93 ) ) {
F_95 ( & V_10 -> V_93 , & V_228 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_136 ( & V_10 -> V_130 ) ;
if ( F_100 ( & V_228 ) )
return V_229 ;
V_10 = F_51 ( V_15 ) ;
F_134 ( & V_10 -> V_130 ) ;
while ( ! F_100 ( & V_228 ) ) {
struct V_27 * V_28 ;
V_28 = F_110 ( & V_228 , struct V_27 , V_31 ) ;
V_28 -> V_32 = V_10 ;
F_208 ( & V_28 -> V_31 , & V_10 -> V_93 ) ;
}
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_3 ( V_2 , V_10 ) ;
F_136 ( & V_10 -> V_130 ) ;
F_147 ( V_2 , true ) ;
F_54 ( V_10 ) ;
return V_229 ;
}
static int F_209 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_131 ;
struct V_191 * V_192 = V_15 -> V_230 ;
if ( V_192 -> V_26 [ V_2 -> V_231 ] )
return V_229 ;
V_192 -> V_26 [ V_2 -> V_231 ] = F_194 ( V_192 , V_2 -> V_231 ) ;
if ( ! V_192 -> V_26 [ V_2 -> V_231 ] )
return V_232 ;
V_2 -> V_26 = V_192 -> V_26 [ V_2 -> V_231 ] ;
return V_229 ;
}
static int F_210 ( void * V_61 , unsigned long V_233 ,
unsigned int V_34 )
{
struct V_1 * V_2 = V_61 ;
if ( V_233 == V_234 || V_233 == V_235 )
return F_206 ( V_2 , V_34 ) ;
else if ( V_233 == V_236 || V_233 == V_237 )
return F_209 ( V_2 , V_34 ) ;
return V_229 ;
}
static void F_211 ( struct V_14 * V_15 ,
struct V_191 * V_192 ,
struct V_1 * V_2 , unsigned int V_193 )
{
unsigned V_238 = V_192 -> V_208 ;
F_125 ( V_2 ) ;
if ( V_192 -> V_107 -> V_195 )
V_192 -> V_107 -> V_195 ( V_192 -> V_197 ,
V_2 -> V_101 -> V_103 , V_193 ,
V_238 + V_193 ) ;
if ( V_192 -> V_107 -> V_239 )
V_192 -> V_107 -> V_239 ( V_2 , V_193 ) ;
F_212 ( & V_2 -> V_240 ) ;
F_213 ( V_2 -> V_101 ) ;
F_191 ( V_2 -> V_129 ) ;
F_203 ( & V_2 -> V_4 ) ;
}
static void F_214 ( struct V_14 * V_15 ,
struct V_191 * V_192 , int V_241 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i) {
if ( V_3 == V_241 )
break;
F_211 ( V_15 , V_192 , V_2 , V_3 ) ;
}
}
static void F_215 ( struct V_14 * V_15 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i)
F_216 ( V_2 -> V_135 ) ;
}
static int F_217 ( struct V_14 * V_15 ,
struct V_191 * V_192 ,
struct V_1 * V_2 , unsigned V_193 )
{
int V_223 ;
unsigned V_238 = V_192 -> V_208 ;
V_223 = V_2 -> V_210 ;
if ( V_223 == V_242 )
V_223 = V_2 -> V_210 = V_192 -> V_210 ;
F_218 ( & V_2 -> V_157 , F_154 ) ;
F_218 ( & V_2 -> V_158 , F_155 ) ;
F_219 ( & V_2 -> V_130 ) ;
F_38 ( & V_2 -> V_139 ) ;
V_2 -> V_131 = V_15 ;
V_2 -> V_231 = V_193 ;
V_2 -> V_87 = V_192 -> V_87 ;
F_220 ( & V_2 -> V_240 ,
F_210 , V_2 ) ;
F_221 ( & V_2 -> V_240 ) ;
V_2 -> V_26 = V_192 -> V_26 [ V_193 ] ;
V_2 -> V_129 = F_222 ( V_154 * sizeof( void * ) ,
V_211 , V_223 ) ;
if ( ! V_2 -> V_129 )
goto V_243;
if ( F_204 ( & V_2 -> V_4 , V_223 ) )
goto V_244;
V_2 -> V_245 = 0 ;
if ( V_192 -> V_107 -> V_246 &&
V_192 -> V_107 -> V_246 ( V_2 , V_192 -> V_197 , V_193 ) )
goto V_247;
V_2 -> V_101 = F_223 ( V_15 , V_2 -> V_210 , V_192 -> V_214 ) ;
if ( ! V_2 -> V_101 )
goto V_239;
if ( V_192 -> V_107 -> V_220 &&
V_192 -> V_107 -> V_220 ( V_192 -> V_197 ,
V_2 -> V_101 -> V_103 , V_193 ,
V_238 + V_193 , V_223 ) )
goto V_248;
return 0 ;
V_248:
F_191 ( V_2 -> V_101 ) ;
V_239:
if ( V_192 -> V_107 -> V_239 )
V_192 -> V_107 -> V_239 ( V_2 , V_193 ) ;
V_247:
F_203 ( & V_2 -> V_4 ) ;
V_244:
F_191 ( V_2 -> V_129 ) ;
V_243:
F_212 ( & V_2 -> V_240 ) ;
return - 1 ;
}
static int F_224 ( struct V_14 * V_15 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i) {
if ( F_217 ( V_15 , V_192 , V_2 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_150 )
return 0 ;
F_214 ( V_15 , V_192 , V_3 ) ;
return 1 ;
}
static void F_225 ( struct V_14 * V_15 ,
unsigned int V_150 )
{
unsigned int V_3 ;
F_226 (i) {
struct V_9 * V_249 = F_227 ( V_15 -> V_250 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
V_249 -> V_34 = V_3 ;
F_219 ( & V_249 -> V_130 ) ;
F_38 ( & V_249 -> V_93 ) ;
V_249 -> V_131 = V_15 ;
if ( ! F_73 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_228 ( V_3 , V_2 -> V_135 ) ;
V_2 -> V_245 ++ ;
if ( V_150 > 1 && V_2 -> V_210 == V_242 )
V_2 -> V_210 = F_229 ( V_3 ) ;
}
}
static void F_230 ( struct V_14 * V_15 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_31 (q, hctx, i) {
F_231 ( V_2 -> V_135 ) ;
V_2 -> V_245 = 0 ;
}
F_232 (q, ctx, i) {
if ( ! F_73 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_228 ( V_3 , V_2 -> V_135 ) ;
V_10 -> V_11 = V_2 -> V_245 ;
V_2 -> V_129 [ V_2 -> V_245 ++ ] = V_10 ;
}
F_31 (q, hctx, i) {
if ( ! V_2 -> V_245 ) {
struct V_191 * V_192 = V_15 -> V_230 ;
if ( V_192 -> V_26 [ V_3 ] ) {
F_189 ( V_192 , V_192 -> V_26 [ V_3 ] , V_3 ) ;
V_192 -> V_26 [ V_3 ] = NULL ;
V_2 -> V_26 = NULL ;
}
continue;
}
V_2 -> V_153 = F_146 ( V_2 -> V_135 ) ;
V_2 -> V_152 = V_155 ;
}
}
static void F_233 ( struct V_191 * V_192 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
bool V_80 ;
int V_3 ;
if ( V_192 -> V_251 . V_94 == V_192 -> V_251 . V_147 )
V_80 = false ;
else
V_80 = true ;
F_234 (q, &set->tag_list, tag_set_list) {
F_26 ( V_15 ) ;
F_31 (q, hctx, i) {
if ( V_80 )
V_2 -> V_87 |= V_252 ;
else
V_2 -> V_87 &= ~ V_252 ;
}
F_27 ( V_15 ) ;
}
}
static void F_235 ( struct V_14 * V_15 )
{
struct V_191 * V_192 = V_15 -> V_230 ;
F_236 ( & V_192 -> V_253 ) ;
F_98 ( & V_15 -> V_254 ) ;
F_233 ( V_192 ) ;
F_237 ( & V_192 -> V_253 ) ;
}
static void F_238 ( struct V_191 * V_192 ,
struct V_14 * V_15 )
{
V_15 -> V_230 = V_192 ;
F_236 ( & V_192 -> V_253 ) ;
F_104 ( & V_15 -> V_254 , & V_192 -> V_251 ) ;
F_233 ( V_192 ) ;
F_237 ( & V_192 -> V_253 ) ;
}
void F_239 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_31 (q, hctx, i)
F_191 ( V_2 ) ;
F_191 ( V_15 -> V_189 ) ;
F_240 ( V_15 -> V_250 ) ;
}
struct V_14 * F_241 ( struct V_191 * V_192 )
{
struct V_1 * * V_255 ;
struct V_9 T_3 * V_10 ;
struct V_14 * V_15 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_242 ( struct V_9 ) ;
if ( ! V_10 )
return F_50 ( - V_227 ) ;
V_255 = F_222 ( V_192 -> V_150 * sizeof( * V_255 ) , V_211 ,
V_192 -> V_210 ) ;
if ( ! V_255 )
goto V_256;
V_6 = F_243 ( V_192 ) ;
if ( ! V_6 )
goto V_257;
for ( V_3 = 0 ; V_3 < V_192 -> V_150 ; V_3 ++ ) {
int V_223 = F_244 ( V_6 , V_3 ) ;
V_255 [ V_3 ] = F_197 ( sizeof( struct V_1 ) ,
V_211 , V_223 ) ;
if ( ! V_255 [ V_3 ] )
goto V_258;
if ( ! F_245 ( & V_255 [ V_3 ] -> V_135 , V_211 ,
V_223 ) )
goto V_258;
F_246 ( & V_255 [ V_3 ] -> V_67 , 0 ) ;
V_255 [ V_3 ] -> V_210 = V_223 ;
V_255 [ V_3 ] -> V_231 = V_3 ;
}
V_15 = F_247 ( V_211 , V_192 -> V_210 ) ;
if ( ! V_15 )
goto V_258;
if ( F_248 ( & V_15 -> V_17 , F_15 ,
V_259 , V_211 ) )
goto V_260;
F_249 ( & V_15 -> V_55 , F_120 , ( unsigned long ) V_15 ) ;
F_250 ( V_15 , 30000 ) ;
V_15 -> V_261 = V_154 ;
V_15 -> V_150 = V_192 -> V_150 ;
V_15 -> V_190 = V_6 ;
V_15 -> V_250 = V_10 ;
V_15 -> V_189 = V_255 ;
V_15 -> V_71 = V_192 -> V_107 ;
V_15 -> V_82 |= V_262 ;
if ( ! ( V_192 -> V_87 & V_263 ) )
V_15 -> V_82 |= 1 << V_264 ;
V_15 -> V_265 = V_266 ;
F_251 ( & V_15 -> V_92 , F_92 ) ;
F_38 ( & V_15 -> V_96 ) ;
F_219 ( & V_15 -> V_95 ) ;
if ( V_15 -> V_150 > 1 )
F_252 ( V_15 , F_179 ) ;
else
F_252 ( V_15 , F_184 ) ;
if ( V_192 -> V_55 )
F_250 ( V_15 , V_192 -> V_55 ) ;
V_15 -> V_267 = V_192 -> V_208 ;
if ( V_192 -> V_107 -> V_268 )
F_253 ( V_15 , V_192 -> V_107 -> V_268 ) ;
F_225 ( V_15 , V_192 -> V_150 ) ;
if ( F_224 ( V_15 , V_192 ) )
goto V_260;
F_236 ( & V_269 ) ;
F_104 ( & V_15 -> V_270 , & V_271 ) ;
F_237 ( & V_269 ) ;
F_238 ( V_192 , V_15 ) ;
F_230 ( V_15 ) ;
return V_15 ;
V_260:
F_254 ( V_15 ) ;
V_258:
F_191 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_192 -> V_150 ; V_3 ++ ) {
if ( ! V_255 [ V_3 ] )
break;
F_216 ( V_255 [ V_3 ] -> V_135 ) ;
F_191 ( V_255 [ V_3 ] ) ;
}
V_257:
F_191 ( V_255 ) ;
V_256:
F_240 ( V_10 ) ;
return F_50 ( - V_227 ) ;
}
void F_255 ( struct V_14 * V_15 )
{
struct V_191 * V_192 = V_15 -> V_230 ;
F_235 ( V_15 ) ;
F_214 ( V_15 , V_192 , V_192 -> V_150 ) ;
F_215 ( V_15 , V_192 ) ;
F_256 ( & V_15 -> V_17 ) ;
F_191 ( V_15 -> V_190 ) ;
V_15 -> V_190 = NULL ;
F_236 ( & V_269 ) ;
F_98 ( & V_15 -> V_270 ) ;
F_237 ( & V_269 ) ;
}
static void F_257 ( struct V_14 * V_15 )
{
F_28 ( ! V_15 -> V_19 ) ;
F_258 ( V_15 ) ;
F_259 ( V_15 -> V_190 , V_15 -> V_150 ) ;
F_230 ( V_15 ) ;
F_260 ( V_15 ) ;
}
static int F_261 ( struct V_272 * V_273 ,
unsigned long V_233 , void * V_274 )
{
struct V_14 * V_15 ;
if ( V_233 != V_234 && V_233 != V_235 &&
V_233 != V_236 && V_233 != V_237 )
return V_229 ;
F_236 ( & V_269 ) ;
F_234 (q, &all_q_list, all_q_node)
F_18 ( V_15 ) ;
F_234 (q, &all_q_list, all_q_node)
F_23 ( V_15 ) ;
F_234 (q, &all_q_list, all_q_node)
F_257 ( V_15 ) ;
F_234 (q, &all_q_list, all_q_node)
F_27 ( V_15 ) ;
F_237 ( & V_269 ) ;
return V_229 ;
}
static int F_262 ( struct V_191 * V_192 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_192 -> V_150 ; V_3 ++ ) {
V_192 -> V_26 [ V_3 ] = F_194 ( V_192 , V_3 ) ;
if ( ! V_192 -> V_26 [ V_3 ] )
goto V_275;
}
return 0 ;
V_275:
while ( -- V_3 >= 0 )
F_189 ( V_192 , V_192 -> V_26 [ V_3 ] , V_3 ) ;
return - V_227 ;
}
static int F_263 ( struct V_191 * V_192 )
{
unsigned int V_128 ;
int V_276 ;
V_128 = V_192 -> V_208 ;
do {
V_276 = F_262 ( V_192 ) ;
if ( ! V_276 )
break;
V_192 -> V_208 >>= 1 ;
if ( V_192 -> V_208 < V_192 -> V_209 + V_277 ) {
V_276 = - V_227 ;
break;
}
} while ( V_192 -> V_208 );
if ( ! V_192 -> V_208 || V_276 ) {
F_141 ( L_3 ) ;
return - V_227 ;
}
if ( V_128 != V_192 -> V_208 )
F_264 ( L_4 ,
V_128 , V_192 -> V_208 ) ;
return 0 ;
}
int F_265 ( struct V_191 * V_192 )
{
F_266 ( V_278 > 1 << V_279 ) ;
if ( ! V_192 -> V_150 )
return - V_280 ;
if ( ! V_192 -> V_208 )
return - V_280 ;
if ( V_192 -> V_208 < V_192 -> V_209 + V_277 )
return - V_280 ;
if ( ! V_192 -> V_150 || ! V_192 -> V_107 -> V_143 || ! V_192 -> V_107 -> V_72 )
return - V_280 ;
if ( V_192 -> V_208 > V_278 ) {
F_264 ( L_5 ,
V_278 ) ;
V_192 -> V_208 = V_278 ;
}
if ( F_267 () ) {
V_192 -> V_150 = 1 ;
V_192 -> V_208 = F_202 ( 64U , V_192 -> V_208 ) ;
}
V_192 -> V_26 = F_222 ( V_192 -> V_150 *
sizeof( struct V_104 * ) ,
V_211 , V_192 -> V_210 ) ;
if ( ! V_192 -> V_26 )
return - V_227 ;
if ( F_263 ( V_192 ) )
goto V_281;
F_268 ( & V_192 -> V_253 ) ;
F_38 ( & V_192 -> V_251 ) ;
return 0 ;
V_281:
F_191 ( V_192 -> V_26 ) ;
V_192 -> V_26 = NULL ;
return - V_227 ;
}
void F_269 ( struct V_191 * V_192 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_192 -> V_150 ; V_3 ++ ) {
if ( V_192 -> V_26 [ V_3 ] )
F_189 ( V_192 , V_192 -> V_26 [ V_3 ] , V_3 ) ;
}
F_191 ( V_192 -> V_26 ) ;
V_192 -> V_26 = NULL ;
}
int F_270 ( struct V_14 * V_15 , unsigned int V_282 )
{
struct V_191 * V_192 = V_15 -> V_230 ;
struct V_1 * V_2 ;
int V_3 , V_16 ;
if ( ! V_192 || V_282 > V_192 -> V_208 )
return - V_280 ;
V_16 = 0 ;
F_31 (q, hctx, i) {
V_16 = F_271 ( V_2 -> V_26 , V_282 ) ;
if ( V_16 )
break;
}
if ( ! V_16 )
V_15 -> V_267 = V_282 ;
return V_16 ;
}
void F_272 ( void )
{
F_236 ( & V_269 ) ;
}
void F_273 ( void )
{
F_237 ( & V_269 ) ;
}
static int T_4 F_274 ( void )
{
F_275 () ;
F_276 ( F_261 , 0 ) ;
return 0 ;
}
