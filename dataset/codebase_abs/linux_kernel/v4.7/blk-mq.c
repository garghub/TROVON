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
struct V_21 * F_42 ( struct V_14 * V_15 , int V_56 ,
unsigned int V_62 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_54 V_63 ;
int V_64 ;
V_64 = F_43 ( V_15 , V_62 & V_65 ) ;
if ( V_64 )
return F_44 ( V_64 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_46 ( & V_63 , V_15 , V_62 , V_10 , V_2 ) ;
V_22 = F_38 ( & V_63 , V_56 ) ;
if ( ! V_22 && ! ( V_62 & V_65 ) ) {
F_47 ( V_2 ) ;
F_48 ( V_10 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_46 ( & V_63 , V_15 , V_62 , V_10 , V_2 ) ;
V_22 = F_38 ( & V_63 , V_56 ) ;
V_10 = V_63 . V_10 ;
}
F_48 ( V_10 ) ;
if ( ! V_22 ) {
F_49 ( V_15 ) ;
return F_44 ( - V_68 ) ;
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
F_8 ( V_69 , & V_22 -> V_70 ) ;
F_52 ( V_2 , V_57 , & V_10 -> V_71 ) ;
F_49 ( V_15 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_26 ;
V_10 -> V_72 [ F_54 ( V_22 ) ] ++ ;
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
V_22 -> V_15 -> V_73 ( V_22 ) ;
}
static void F_65 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_26 ;
bool V_74 = false ;
int V_28 ;
if ( ! F_4 ( V_75 , & V_22 -> V_15 -> V_76 ) ) {
V_22 -> V_15 -> V_73 ( V_22 ) ;
return;
}
V_28 = F_66 () ;
if ( ! F_4 ( V_77 , & V_22 -> V_15 -> V_76 ) )
V_74 = F_67 ( V_28 , V_10 -> V_28 ) ;
if ( V_28 != V_10 -> V_28 && ! V_74 && F_68 ( V_10 -> V_28 ) ) {
V_22 -> V_78 . V_79 = F_64 ;
V_22 -> V_78 . V_80 = V_22 ;
V_22 -> V_78 . V_62 = 0 ;
F_69 ( V_10 -> V_28 , & V_22 -> V_78 ) ;
} else {
V_22 -> V_15 -> V_73 ( V_22 ) ;
}
F_70 () ;
}
static void F_71 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
if ( ! V_15 -> V_73 )
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
return F_4 ( V_69 , & V_22 -> V_70 ) ;
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
if ( ! F_4 ( V_69 , & V_22 -> V_70 ) )
F_6 ( V_69 , & V_22 -> V_70 ) ;
if ( F_4 ( V_81 , & V_22 -> V_70 ) )
F_8 ( V_81 , & V_22 -> V_70 ) ;
if ( V_15 -> V_82 && F_62 ( V_22 ) ) {
V_22 -> V_37 ++ ;
}
}
static void F_80 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
F_81 ( V_15 , V_22 ) ;
if ( F_82 ( V_69 , & V_22 -> V_70 ) ) {
if ( V_15 -> V_82 && F_62 ( V_22 ) )
V_22 -> V_37 -- ;
}
}
void F_83 ( struct V_21 * V_22 )
{
F_80 ( V_22 ) ;
F_84 ( F_85 ( V_22 ) ) ;
F_86 ( V_22 , true ) ;
}
static void F_87 ( struct V_83 * V_84 )
{
struct V_14 * V_15 =
F_88 ( V_84 , struct V_14 , V_85 ) ;
F_89 ( V_86 ) ;
struct V_21 * V_22 , * V_87 ;
unsigned long V_62 ;
F_90 ( & V_15 -> V_88 , V_62 ) ;
F_91 ( & V_15 -> V_89 , & V_86 ) ;
F_92 ( & V_15 -> V_88 , V_62 ) ;
F_93 (rq, next, &rq_list, queuelist) {
if ( ! ( V_22 -> V_27 & V_90 ) )
continue;
V_22 -> V_27 &= ~ V_90 ;
F_94 ( & V_22 -> V_25 ) ;
F_95 ( V_22 , true , false , false ) ;
}
while ( ! F_96 ( & V_86 ) ) {
V_22 = F_97 ( V_86 . V_87 , struct V_21 , V_25 ) ;
F_94 ( & V_22 -> V_25 ) ;
F_95 ( V_22 , false , false , false ) ;
}
F_98 ( V_15 ) ;
}
void F_86 ( struct V_21 * V_22 , bool V_91 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
unsigned long V_62 ;
F_84 ( V_22 -> V_27 & V_90 ) ;
F_90 ( & V_15 -> V_88 , V_62 ) ;
if ( V_91 ) {
V_22 -> V_27 |= V_90 ;
F_99 ( & V_22 -> V_25 , & V_15 -> V_89 ) ;
} else {
F_100 ( & V_22 -> V_25 , & V_15 -> V_89 ) ;
}
F_92 ( & V_15 -> V_88 , V_62 ) ;
}
void F_101 ( struct V_14 * V_15 )
{
F_102 ( & V_15 -> V_85 ) ;
}
void F_103 ( struct V_14 * V_15 )
{
F_104 ( & V_15 -> V_85 ) ;
}
void F_105 ( struct V_14 * V_15 )
{
unsigned long V_62 ;
F_89 ( V_86 ) ;
F_90 ( & V_15 -> V_88 , V_62 ) ;
F_91 ( & V_15 -> V_89 , & V_86 ) ;
F_92 ( & V_15 -> V_88 , V_62 ) ;
while ( ! F_96 ( & V_86 ) ) {
struct V_21 * V_22 ;
V_22 = F_106 ( & V_86 , struct V_21 , V_25 ) ;
F_94 ( & V_22 -> V_25 ) ;
V_22 -> V_41 = - V_92 ;
F_60 ( V_22 , V_22 -> V_41 ) ;
}
}
struct V_21 * F_107 ( struct V_93 * V_20 , unsigned int V_57 )
{
if ( V_57 < V_20 -> V_94 )
return V_20 -> V_59 [ V_57 ] ;
return NULL ;
}
void F_108 ( struct V_21 * V_95 , bool V_96 )
{
struct V_97 * V_98 = V_95 -> V_15 -> V_66 ;
enum V_99 V_64 = V_100 ;
if ( ! F_4 ( V_69 , & V_95 -> V_70 ) )
return;
if ( V_98 -> V_49 )
V_64 = V_98 -> V_49 ( V_95 , V_96 ) ;
switch ( V_64 ) {
case V_101 :
F_71 ( V_95 ) ;
break;
case V_100 :
F_78 ( V_95 ) ;
F_109 ( V_95 ) ;
break;
case V_102 :
break;
default:
F_110 ( V_103 L_1 , V_64 ) ;
break;
}
}
static void F_111 ( struct V_1 * V_2 ,
struct V_21 * V_22 , void * V_104 , bool V_96 )
{
struct V_105 * V_55 = V_104 ;
if ( ! F_4 ( V_69 , & V_22 -> V_70 ) ) {
if ( F_58 ( F_112 ( V_22 -> V_15 ) ) ) {
V_22 -> V_41 = - V_92 ;
F_60 ( V_22 , V_22 -> V_41 ) ;
}
return;
}
if ( F_113 ( V_34 , V_22 -> V_106 ) ) {
if ( ! F_74 ( V_22 ) )
F_108 ( V_22 , V_96 ) ;
} else if ( ! V_55 -> V_107 || F_114 ( V_55 -> V_87 , V_22 -> V_106 ) ) {
V_55 -> V_87 = V_22 -> V_106 ;
V_55 -> V_107 = 1 ;
}
}
static void F_115 ( struct V_83 * V_84 )
{
struct V_14 * V_15 =
F_88 ( V_84 , struct V_14 , V_108 ) ;
struct V_105 V_55 = {
. V_87 = 0 ,
. V_107 = 0 ,
} ;
int V_3 ;
if ( F_43 ( V_15 , true ) )
return;
F_116 ( V_15 , F_111 , & V_55 ) ;
if ( V_55 . V_107 ) {
V_55 . V_87 = F_117 ( F_118 ( V_55 . V_87 ) ) ;
F_119 ( & V_15 -> V_49 , V_55 . V_87 ) ;
} else {
struct V_1 * V_2 ;
F_24 (q, hctx, i) {
if ( F_25 ( V_2 ) )
F_120 ( V_2 ) ;
}
}
F_49 ( V_15 ) ;
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
F_130 ( & V_10 -> V_86 , V_116 ) ;
F_131 ( & V_10 -> V_121 ) ;
V_118 ++ ;
} while ( 1 );
}
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_122 ;
struct V_21 * V_22 ;
F_89 ( V_86 ) ;
F_89 ( V_123 ) ;
struct V_115 * V_124 ;
int V_125 ;
F_132 ( ! F_133 ( F_134 () , V_2 -> V_126 ) ) ;
if ( F_58 ( F_4 ( V_127 , & V_2 -> V_128 ) ) )
return;
V_2 -> V_129 ++ ;
F_127 ( V_2 , & V_86 ) ;
if ( ! F_135 ( & V_2 -> V_130 ) ) {
F_129 ( & V_2 -> V_121 ) ;
if ( ! F_96 ( & V_2 -> V_130 ) )
F_91 ( & V_2 -> V_130 , & V_86 ) ;
F_131 ( & V_2 -> V_121 ) ;
}
V_124 = NULL ;
V_125 = 0 ;
while ( ! F_96 ( & V_86 ) ) {
struct V_131 V_132 ;
int V_64 ;
V_22 = F_106 ( & V_86 , struct V_21 , V_25 ) ;
F_94 ( & V_22 -> V_25 ) ;
V_132 . V_22 = V_22 ;
V_132 . V_116 = V_124 ;
V_132 . V_133 = F_96 ( & V_86 ) ;
V_64 = V_15 -> V_66 -> V_134 ( V_2 , & V_132 ) ;
switch ( V_64 ) {
case V_135 :
V_125 ++ ;
continue;
case V_136 :
F_99 ( & V_22 -> V_25 , & V_86 ) ;
F_80 ( V_22 ) ;
break;
default:
F_136 ( L_2 , V_64 ) ;
case V_137 :
V_22 -> V_41 = - V_92 ;
F_60 ( V_22 , V_22 -> V_41 ) ;
break;
}
if ( V_64 == V_136 )
break;
if ( ! V_124 && V_86 . V_87 != V_86 . V_138 )
V_124 = & V_123 ;
}
if ( ! V_125 )
V_2 -> V_139 [ 0 ] ++ ;
else if ( V_125 < ( 1 << ( V_140 - 1 ) ) )
V_2 -> V_139 [ F_137 ( V_125 ) + 1 ] ++ ;
if ( ! F_96 ( & V_86 ) ) {
F_129 ( & V_2 -> V_121 ) ;
F_138 ( & V_86 , & V_2 -> V_130 ) ;
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
static void F_149 ( struct V_83 * V_84 )
{
struct V_1 * V_2 ;
V_2 = F_88 ( V_84 , struct V_1 , V_148 . V_84 ) ;
F_47 ( V_2 ) ;
}
static void F_150 ( struct V_83 * V_84 )
{
struct V_1 * V_2 ;
V_2 = F_88 ( V_84 , struct V_1 , V_149 . V_84 ) ;
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
bool V_91 )
{
F_154 ( V_2 -> V_122 , V_22 ) ;
if ( V_91 )
F_99 ( & V_22 -> V_25 , & V_10 -> V_86 ) ;
else
F_100 ( & V_22 -> V_25 , & V_10 -> V_86 ) ;
}
static void F_155 ( struct V_1 * V_2 ,
struct V_21 * V_22 , bool V_91 )
{
struct V_9 * V_10 = V_22 -> V_26 ;
F_153 ( V_2 , V_10 , V_22 , V_91 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_95 ( struct V_21 * V_22 , bool V_91 , bool V_151 ,
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
F_155 ( V_2 , V_22 , V_91 ) ;
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
V_22 = F_162 ( V_116 . V_87 ) ;
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
F_165 ( V_22 , 1 ) ;
}
static inline bool F_166 ( struct V_1 * V_2 )
{
return ( V_2 -> V_62 & V_164 ) &&
! F_167 ( V_2 -> V_122 ) ;
}
static inline bool F_168 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_21 * V_22 , struct V_109 * V_109 )
{
if ( ! F_166 ( V_2 ) || ! F_169 ( V_109 ) ) {
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
static struct V_21 * F_170 ( struct V_14 * V_15 ,
struct V_109 * V_109 ,
struct V_166 * V_55 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_21 * V_22 ;
int V_56 = F_171 ( V_109 ) ;
struct V_54 V_63 ;
F_172 ( V_15 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
if ( F_37 ( V_109 -> V_167 ) )
V_56 |= V_168 ;
F_173 ( V_15 , V_109 , V_56 ) ;
F_46 ( & V_63 , V_15 , V_65 , V_10 , V_2 ) ;
V_22 = F_38 ( & V_63 , V_56 ) ;
if ( F_58 ( ! V_22 ) ) {
F_47 ( V_2 ) ;
F_48 ( V_10 ) ;
F_174 ( V_15 , V_109 , V_56 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_46 ( & V_63 , V_15 , 0 , V_10 , V_2 ) ;
V_22 = F_38 ( & V_63 , V_56 ) ;
V_10 = V_63 . V_10 ;
V_2 = V_63 . V_2 ;
}
V_2 -> V_125 ++ ;
V_55 -> V_2 = V_2 ;
V_55 -> V_10 = V_10 ;
return V_22 ;
}
static int F_175 ( struct V_21 * V_22 , T_1 * V_169 )
{
int V_64 ;
struct V_14 * V_15 = V_22 -> V_15 ;
struct V_1 * V_2 = V_15 -> V_66 -> V_67 ( V_15 ,
V_22 -> V_26 -> V_28 ) ;
struct V_131 V_132 = {
. V_22 = V_22 ,
. V_116 = NULL ,
. V_133 = 1
} ;
T_1 V_170 = F_176 ( V_22 -> V_57 , V_2 -> V_171 ) ;
V_64 = V_15 -> V_66 -> V_134 ( V_2 , & V_132 ) ;
if ( V_64 == V_135 ) {
* V_169 = V_170 ;
return 0 ;
}
F_80 ( V_22 ) ;
if ( V_64 == V_137 ) {
* V_169 = V_172 ;
V_22 -> V_41 = - V_92 ;
F_60 ( V_22 , V_22 -> V_41 ) ;
return 0 ;
}
return - 1 ;
}
static T_1 F_177 ( struct V_14 * V_15 , struct V_109 * V_109 )
{
const int V_173 = F_37 ( V_109 -> V_167 ) ;
const int V_174 = V_109 -> V_167 & ( V_175 | V_176 ) ;
struct V_166 V_55 ;
struct V_21 * V_22 ;
unsigned int V_177 = 0 ;
struct V_158 * V_159 ;
struct V_21 * V_178 = NULL ;
T_1 V_169 ;
F_178 ( V_15 , & V_109 ) ;
if ( F_179 ( V_109 ) && F_180 ( V_109 ) ) {
F_181 ( V_109 ) ;
return V_172 ;
}
F_182 ( V_15 , & V_109 , V_15 -> V_179 ) ;
if ( ! V_174 && ! F_167 ( V_15 ) &&
F_183 ( V_15 , V_109 , & V_177 , & V_178 ) )
return V_172 ;
V_22 = F_170 ( V_15 , V_109 , & V_55 ) ;
if ( F_58 ( ! V_22 ) )
return V_172 ;
V_169 = F_176 ( V_22 -> V_57 , V_55 . V_2 -> V_171 ) ;
if ( F_58 ( V_174 ) ) {
F_163 ( V_22 , V_109 ) ;
F_184 ( V_22 ) ;
goto V_151;
}
V_159 = V_180 -> V_159 ;
if ( ( ( V_159 && ! F_167 ( V_15 ) ) || V_173 ) &&
! ( V_55 . V_2 -> V_62 & V_181 ) ) {
struct V_21 * V_182 = NULL ;
F_163 ( V_22 , V_109 ) ;
if ( V_159 ) {
if ( V_178 && ! F_96 ( & V_159 -> V_163 ) ) {
V_182 = V_178 ;
F_94 ( & V_182 -> V_25 ) ;
}
F_100 ( & V_22 -> V_25 , & V_159 -> V_163 ) ;
} else
V_182 = V_22 ;
F_48 ( V_55 . V_10 ) ;
if ( ! V_182 )
goto V_183;
if ( ! F_175 ( V_182 , & V_169 ) )
goto V_183;
F_95 ( V_182 , false , true , true ) ;
goto V_183;
}
if ( ! F_168 ( V_55 . V_2 , V_55 . V_10 , V_22 , V_109 ) ) {
V_151:
F_139 ( V_55 . V_2 , ! V_173 || V_174 ) ;
}
F_48 ( V_55 . V_10 ) ;
V_183:
return V_169 ;
}
static T_1 F_185 ( struct V_14 * V_15 , struct V_109 * V_109 )
{
const int V_173 = F_37 ( V_109 -> V_167 ) ;
const int V_174 = V_109 -> V_167 & ( V_175 | V_176 ) ;
struct V_158 * V_159 ;
unsigned int V_177 = 0 ;
struct V_166 V_55 ;
struct V_21 * V_22 ;
T_1 V_169 ;
F_178 ( V_15 , & V_109 ) ;
if ( F_179 ( V_109 ) && F_180 ( V_109 ) ) {
F_181 ( V_109 ) ;
return V_172 ;
}
F_182 ( V_15 , & V_109 , V_15 -> V_179 ) ;
if ( ! V_174 && ! F_167 ( V_15 ) ) {
if ( F_183 ( V_15 , V_109 , & V_177 , NULL ) )
return V_172 ;
} else
V_177 = F_186 ( V_15 ) ;
V_22 = F_170 ( V_15 , V_109 , & V_55 ) ;
if ( F_58 ( ! V_22 ) )
return V_172 ;
V_169 = F_176 ( V_22 -> V_57 , V_55 . V_2 -> V_171 ) ;
if ( F_58 ( V_174 ) ) {
F_163 ( V_22 , V_109 ) ;
F_184 ( V_22 ) ;
goto V_151;
}
V_159 = V_180 -> V_159 ;
if ( V_159 ) {
F_163 ( V_22 , V_109 ) ;
if ( ! V_177 )
F_187 ( V_15 ) ;
F_48 ( V_55 . V_10 ) ;
if ( V_177 >= V_184 ) {
F_188 ( V_159 , false ) ;
F_187 ( V_15 ) ;
}
F_100 ( & V_22 -> V_25 , & V_159 -> V_163 ) ;
return V_169 ;
}
if ( ! F_168 ( V_55 . V_2 , V_55 . V_10 , V_22 , V_109 ) ) {
V_151:
F_139 ( V_55 . V_2 , ! V_173 || V_174 ) ;
}
F_48 ( V_55 . V_10 ) ;
return V_169 ;
}
struct V_1 * F_189 ( struct V_14 * V_15 , const int V_28 )
{
return V_15 -> V_185 [ V_15 -> V_186 [ V_28 ] ] ;
}
static void F_190 ( struct V_187 * V_188 ,
struct V_93 * V_20 , unsigned int V_189 )
{
struct V_190 * V_190 ;
if ( V_20 -> V_59 && V_188 -> V_98 -> V_191 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_20 -> V_94 ; V_3 ++ ) {
if ( ! V_20 -> V_59 [ V_3 ] )
continue;
V_188 -> V_98 -> V_191 ( V_188 -> V_192 , V_20 -> V_59 [ V_3 ] ,
V_189 , V_3 ) ;
V_20 -> V_59 [ V_3 ] = NULL ;
}
}
while ( ! F_96 ( & V_20 -> V_193 ) ) {
V_190 = F_106 ( & V_20 -> V_193 , struct V_190 , V_194 ) ;
F_94 ( & V_190 -> V_194 ) ;
F_191 ( F_192 ( V_190 ) ) ;
F_193 ( V_190 , V_190 -> V_195 ) ;
}
F_194 ( V_20 -> V_59 ) ;
F_195 ( V_20 ) ;
}
static T_2 F_196 ( unsigned int V_196 )
{
return ( T_2 ) V_197 << V_196 ;
}
static struct V_93 * F_197 ( struct V_187 * V_188 ,
unsigned int V_189 )
{
struct V_93 * V_20 ;
unsigned int V_3 , V_198 , V_199 , V_200 = 4 ;
T_2 V_201 , V_202 ;
V_20 = F_198 ( V_188 -> V_203 , V_188 -> V_204 ,
V_188 -> V_205 ,
F_199 ( V_188 -> V_62 ) ) ;
if ( ! V_20 )
return NULL ;
F_31 ( & V_20 -> V_193 ) ;
V_20 -> V_59 = F_200 ( V_188 -> V_203 * sizeof( struct V_21 * ) ,
V_206 | V_207 | V_208 ,
V_188 -> V_205 ) ;
if ( ! V_20 -> V_59 ) {
F_195 ( V_20 ) ;
return NULL ;
}
V_201 = F_201 ( sizeof( struct V_21 ) + V_188 -> V_209 ,
F_202 () ) ;
V_202 = V_201 * V_188 -> V_203 ;
for ( V_3 = 0 ; V_3 < V_188 -> V_203 ; ) {
int V_210 = V_200 ;
struct V_190 * V_190 ;
int V_211 ;
void * V_212 ;
while ( V_210 && V_202 < F_196 ( V_210 - 1 ) )
V_210 -- ;
do {
V_190 = F_203 ( V_188 -> V_205 ,
V_206 | V_207 | V_208 | V_213 ,
V_210 ) ;
if ( V_190 )
break;
if ( ! V_210 -- )
break;
if ( F_196 ( V_210 ) < V_201 )
break;
} while ( 1 );
if ( ! V_190 )
goto V_214;
V_190 -> V_195 = V_210 ;
F_100 ( & V_190 -> V_194 , & V_20 -> V_193 ) ;
V_212 = F_192 ( V_190 ) ;
F_204 ( V_212 , F_196 ( V_210 ) , 1 , V_206 ) ;
V_199 = F_196 ( V_210 ) / V_201 ;
V_211 = F_205 ( V_199 , V_188 -> V_203 - V_3 ) ;
V_202 -= V_211 * V_201 ;
for ( V_198 = 0 ; V_198 < V_211 ; V_198 ++ ) {
V_20 -> V_59 [ V_3 ] = V_212 ;
if ( V_188 -> V_98 -> V_215 ) {
if ( V_188 -> V_98 -> V_215 ( V_188 -> V_192 ,
V_20 -> V_59 [ V_3 ] , V_189 , V_3 ,
V_188 -> V_205 ) ) {
V_20 -> V_59 [ V_3 ] = NULL ;
goto V_214;
}
}
V_212 += V_201 ;
V_3 ++ ;
}
}
return V_20 ;
V_214:
F_190 ( V_188 , V_20 , V_189 ) ;
return NULL ;
}
static void F_206 ( struct V_216 * V_217 )
{
F_194 ( V_217 -> V_6 ) ;
}
static int F_207 ( struct V_216 * V_217 , int V_218 )
{
unsigned int V_219 = 8 , V_220 , V_221 , V_3 ;
V_217 -> V_12 = V_219 ;
V_221 = F_208 ( V_145 , V_219 ) / V_219 ;
V_217 -> V_6 = F_200 ( V_221 * sizeof( struct V_8 ) ,
V_206 , V_218 ) ;
if ( ! V_217 -> V_6 )
return - V_222 ;
V_220 = V_145 ;
for ( V_3 = 0 ; V_3 < V_221 ; V_3 ++ ) {
V_217 -> V_6 [ V_3 ] . V_119 = F_205 ( V_220 , V_217 -> V_12 ) ;
V_220 -= V_217 -> V_6 [ V_3 ] . V_119 ;
}
return 0 ;
}
static int F_209 ( struct V_1 * V_2 , int V_28 )
{
struct V_14 * V_15 = V_2 -> V_122 ;
struct V_9 * V_10 ;
F_89 ( V_223 ) ;
V_10 = F_210 ( V_15 , V_28 ) ;
F_129 ( & V_10 -> V_121 ) ;
if ( ! F_96 ( & V_10 -> V_86 ) ) {
F_91 ( & V_10 -> V_86 , & V_223 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_131 ( & V_10 -> V_121 ) ;
if ( F_96 ( & V_223 ) )
return V_224 ;
V_10 = F_45 ( V_15 ) ;
F_129 ( & V_10 -> V_121 ) ;
while ( ! F_96 ( & V_223 ) ) {
struct V_21 * V_22 ;
V_22 = F_106 ( & V_223 , struct V_21 , V_25 ) ;
V_22 -> V_26 = V_10 ;
F_211 ( & V_22 -> V_25 , & V_10 -> V_86 ) ;
}
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_10 -> V_28 ) ;
F_3 ( V_2 , V_10 ) ;
F_131 ( & V_10 -> V_121 ) ;
F_139 ( V_2 , true ) ;
F_48 ( V_10 ) ;
return V_224 ;
}
static int F_212 ( void * V_55 , unsigned long V_225 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_55 ;
if ( V_225 == V_226 || V_225 == V_227 )
return F_209 ( V_2 , V_28 ) ;
return V_224 ;
}
static void F_213 ( struct V_14 * V_15 ,
struct V_187 * V_188 ,
struct V_1 * V_2 , unsigned int V_189 )
{
unsigned V_228 = V_188 -> V_203 ;
F_120 ( V_2 ) ;
if ( V_188 -> V_98 -> V_191 )
V_188 -> V_98 -> V_191 ( V_188 -> V_192 ,
V_2 -> V_229 -> V_230 , V_189 ,
V_228 + V_189 ) ;
if ( V_188 -> V_98 -> V_231 )
V_188 -> V_98 -> V_231 ( V_2 , V_189 ) ;
F_214 ( & V_2 -> V_232 ) ;
F_215 ( V_2 -> V_229 ) ;
F_206 ( & V_2 -> V_4 ) ;
}
static void F_216 ( struct V_14 * V_15 ,
struct V_187 * V_188 , int V_233 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i) {
if ( V_3 == V_233 )
break;
F_213 ( V_15 , V_188 , V_2 , V_3 ) ;
}
}
static void F_217 ( struct V_14 * V_15 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i)
F_218 ( V_2 -> V_126 ) ;
}
static int F_219 ( struct V_14 * V_15 ,
struct V_187 * V_188 ,
struct V_1 * V_2 , unsigned V_189 )
{
int V_218 ;
unsigned V_228 = V_188 -> V_203 ;
V_218 = V_2 -> V_205 ;
if ( V_218 == V_234 )
V_218 = V_2 -> V_205 = V_188 -> V_205 ;
F_220 ( & V_2 -> V_148 , F_149 ) ;
F_220 ( & V_2 -> V_149 , F_150 ) ;
F_221 ( & V_2 -> V_121 ) ;
F_31 ( & V_2 -> V_130 ) ;
V_2 -> V_122 = V_15 ;
V_2 -> V_171 = V_189 ;
V_2 -> V_62 = V_188 -> V_62 & ~ V_235 ;
F_222 ( & V_2 -> V_232 ,
F_212 , V_2 ) ;
F_223 ( & V_2 -> V_232 ) ;
V_2 -> V_20 = V_188 -> V_20 [ V_189 ] ;
V_2 -> V_120 = F_224 ( V_145 * sizeof( void * ) ,
V_206 , V_218 ) ;
if ( ! V_2 -> V_120 )
goto V_236;
if ( F_207 ( & V_2 -> V_4 , V_218 ) )
goto V_237;
V_2 -> V_238 = 0 ;
if ( V_188 -> V_98 -> V_239 &&
V_188 -> V_98 -> V_239 ( V_2 , V_188 -> V_192 , V_189 ) )
goto V_240;
V_2 -> V_229 = F_225 ( V_15 , V_2 -> V_205 , V_188 -> V_209 ) ;
if ( ! V_2 -> V_229 )
goto V_231;
if ( V_188 -> V_98 -> V_215 &&
V_188 -> V_98 -> V_215 ( V_188 -> V_192 ,
V_2 -> V_229 -> V_230 , V_189 ,
V_228 + V_189 , V_218 ) )
goto V_241;
return 0 ;
V_241:
F_194 ( V_2 -> V_229 ) ;
V_231:
if ( V_188 -> V_98 -> V_231 )
V_188 -> V_98 -> V_231 ( V_2 , V_189 ) ;
V_240:
F_206 ( & V_2 -> V_4 ) ;
V_237:
F_194 ( V_2 -> V_120 ) ;
V_236:
F_214 ( & V_2 -> V_232 ) ;
return - 1 ;
}
static void F_226 ( struct V_14 * V_15 ,
unsigned int V_141 )
{
unsigned int V_3 ;
F_227 (i) {
struct V_9 * V_242 = F_228 ( V_15 -> V_243 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_242 , 0 , sizeof( * V_242 ) ) ;
V_242 -> V_28 = V_3 ;
F_221 ( & V_242 -> V_121 ) ;
F_31 ( & V_242 -> V_86 ) ;
V_242 -> V_122 = V_15 ;
if ( ! F_68 ( V_3 ) )
continue;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_3 ) ;
if ( V_141 > 1 && V_2 -> V_205 == V_234 )
V_2 -> V_205 = F_229 ( F_230 ( V_3 ) ) ;
}
}
static void F_231 ( struct V_14 * V_15 ,
const struct V_126 * V_244 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_187 * V_188 = V_15 -> V_245 ;
F_232 ( & V_15 -> V_246 ) ;
F_24 (q, hctx, i) {
F_233 ( V_2 -> V_126 ) ;
V_2 -> V_238 = 0 ;
}
F_227 (i) {
if ( ! F_133 ( V_3 , V_244 ) )
continue;
V_10 = F_228 ( V_15 -> V_243 , V_3 ) ;
V_2 = V_15 -> V_66 -> V_67 ( V_15 , V_3 ) ;
F_234 ( V_3 , V_2 -> V_126 ) ;
V_10 -> V_11 = V_2 -> V_238 ;
V_2 -> V_120 [ V_2 -> V_238 ++ ] = V_10 ;
}
F_235 ( & V_15 -> V_246 ) ;
F_24 (q, hctx, i) {
struct V_216 * V_6 = & V_2 -> V_4 ;
if ( ! V_2 -> V_238 ) {
if ( V_188 -> V_20 [ V_3 ] ) {
F_190 ( V_188 , V_188 -> V_20 [ V_3 ] , V_3 ) ;
V_188 -> V_20 [ V_3 ] = NULL ;
}
V_2 -> V_20 = NULL ;
continue;
}
if ( ! V_188 -> V_20 [ V_3 ] )
V_188 -> V_20 [ V_3 ] = F_197 ( V_188 , V_3 ) ;
V_2 -> V_20 = V_188 -> V_20 [ V_3 ] ;
F_132 ( ! V_2 -> V_20 ) ;
F_236 ( V_2 -> V_20 -> V_126 , V_2 -> V_126 ) ;
V_6 -> V_5 = F_237 ( V_2 -> V_238 , V_6 -> V_12 ) ;
V_2 -> V_144 = F_142 ( V_2 -> V_126 ) ;
V_2 -> V_143 = V_146 ;
}
}
static void F_238 ( struct V_14 * V_15 , bool V_74 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i) {
if ( V_74 )
V_2 -> V_62 |= V_235 ;
else
V_2 -> V_62 &= ~ V_235 ;
}
}
static void F_239 ( struct V_187 * V_188 , bool V_74 )
{
struct V_14 * V_15 ;
F_240 (q, &set->tag_list, tag_set_list) {
F_17 ( V_15 ) ;
F_238 ( V_15 , V_74 ) ;
F_18 ( V_15 ) ;
}
}
static void F_241 ( struct V_14 * V_15 )
{
struct V_187 * V_188 = V_15 -> V_245 ;
F_232 ( & V_188 -> V_247 ) ;
F_94 ( & V_15 -> V_248 ) ;
if ( F_242 ( & V_188 -> V_249 ) ) {
V_188 -> V_62 &= ~ V_235 ;
F_239 ( V_188 , false ) ;
}
F_235 ( & V_188 -> V_247 ) ;
}
static void F_243 ( struct V_187 * V_188 ,
struct V_14 * V_15 )
{
V_15 -> V_245 = V_188 ;
F_232 ( & V_188 -> V_247 ) ;
if ( ! F_96 ( & V_188 -> V_249 ) && ! ( V_188 -> V_62 & V_235 ) ) {
V_188 -> V_62 |= V_235 ;
F_239 ( V_188 , true ) ;
}
if ( V_188 -> V_62 & V_235 )
F_238 ( V_15 , true ) ;
F_100 ( & V_15 -> V_248 , & V_188 -> V_249 ) ;
F_235 ( & V_188 -> V_247 ) ;
}
void F_244 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i) {
if ( ! V_2 )
continue;
F_194 ( V_2 -> V_120 ) ;
F_194 ( V_2 ) ;
}
F_194 ( V_15 -> V_186 ) ;
V_15 -> V_186 = NULL ;
F_194 ( V_15 -> V_185 ) ;
F_245 ( V_15 -> V_243 ) ;
}
struct V_14 * F_246 ( struct V_187 * V_188 )
{
struct V_14 * V_250 , * V_15 ;
V_250 = F_247 ( V_206 , V_188 -> V_205 ) ;
if ( ! V_250 )
return F_44 ( - V_222 ) ;
V_15 = F_248 ( V_188 , V_250 ) ;
if ( F_249 ( V_15 ) )
F_250 ( V_250 ) ;
return V_15 ;
}
static void F_251 ( struct V_187 * V_188 ,
struct V_14 * V_15 )
{
int V_3 , V_198 ;
struct V_1 * * V_251 = V_15 -> V_185 ;
F_252 ( V_15 ) ;
for ( V_3 = 0 ; V_3 < V_188 -> V_141 ; V_3 ++ ) {
int V_218 ;
if ( V_251 [ V_3 ] )
continue;
V_218 = F_253 ( V_15 -> V_186 , V_3 ) ;
V_251 [ V_3 ] = F_200 ( sizeof( struct V_1 ) ,
V_206 , V_218 ) ;
if ( ! V_251 [ V_3 ] )
break;
if ( ! F_254 ( & V_251 [ V_3 ] -> V_126 , V_206 ,
V_218 ) ) {
F_194 ( V_251 [ V_3 ] ) ;
V_251 [ V_3 ] = NULL ;
break;
}
F_255 ( & V_251 [ V_3 ] -> V_61 , 0 ) ;
V_251 [ V_3 ] -> V_205 = V_218 ;
V_251 [ V_3 ] -> V_171 = V_3 ;
if ( F_219 ( V_15 , V_188 , V_251 [ V_3 ] , V_3 ) ) {
F_218 ( V_251 [ V_3 ] -> V_126 ) ;
F_194 ( V_251 [ V_3 ] ) ;
V_251 [ V_3 ] = NULL ;
break;
}
F_256 ( V_251 [ V_3 ] ) ;
}
for ( V_198 = V_3 ; V_198 < V_15 -> V_141 ; V_198 ++ ) {
struct V_1 * V_2 = V_251 [ V_198 ] ;
if ( V_2 ) {
if ( V_2 -> V_20 ) {
F_190 ( V_188 , V_2 -> V_20 , V_198 ) ;
V_188 -> V_20 [ V_198 ] = NULL ;
}
F_213 ( V_15 , V_188 , V_2 , V_198 ) ;
F_218 ( V_2 -> V_126 ) ;
F_257 ( & V_2 -> V_252 ) ;
F_194 ( V_2 -> V_120 ) ;
F_194 ( V_2 ) ;
V_251 [ V_198 ] = NULL ;
}
}
V_15 -> V_141 = V_3 ;
F_258 ( V_15 ) ;
}
struct V_14 * F_248 ( struct V_187 * V_188 ,
struct V_14 * V_15 )
{
V_15 -> V_66 = V_188 -> V_98 ;
V_15 -> V_243 = F_259 ( struct V_9 ) ;
if ( ! V_15 -> V_243 )
goto V_253;
V_15 -> V_185 = F_200 ( V_145 * sizeof( * ( V_15 -> V_185 ) ) ,
V_206 , V_188 -> V_205 ) ;
if ( ! V_15 -> V_185 )
goto V_254;
V_15 -> V_186 = F_260 ( V_188 ) ;
if ( ! V_15 -> V_186 )
goto V_255;
F_251 ( V_188 , V_15 ) ;
if ( ! V_15 -> V_141 )
goto V_256;
F_261 ( & V_15 -> V_108 , F_115 ) ;
F_262 ( V_15 , V_188 -> V_49 ? V_188 -> V_49 : 30 * V_257 ) ;
V_15 -> V_258 = V_145 ;
V_15 -> V_76 |= V_259 ;
if ( ! ( V_188 -> V_62 & V_260 ) )
V_15 -> V_76 |= 1 << V_261 ;
V_15 -> V_262 = V_263 ;
F_261 ( & V_15 -> V_85 , F_87 ) ;
F_31 ( & V_15 -> V_89 ) ;
F_221 ( & V_15 -> V_88 ) ;
if ( V_15 -> V_141 > 1 )
F_263 ( V_15 , F_177 ) ;
else
F_263 ( V_15 , F_185 ) ;
V_15 -> V_264 = V_188 -> V_203 ;
if ( V_188 -> V_98 -> V_265 )
F_264 ( V_15 , V_188 -> V_98 -> V_265 ) ;
F_226 ( V_15 , V_188 -> V_141 ) ;
F_265 () ;
F_232 ( & V_266 ) ;
F_100 ( & V_15 -> V_267 , & V_268 ) ;
F_243 ( V_188 , V_15 ) ;
F_231 ( V_15 , V_269 ) ;
F_235 ( & V_266 ) ;
F_266 () ;
return V_15 ;
V_256:
F_194 ( V_15 -> V_186 ) ;
V_255:
F_194 ( V_15 -> V_185 ) ;
V_254:
F_245 ( V_15 -> V_243 ) ;
V_253:
V_15 -> V_66 = NULL ;
return F_44 ( - V_222 ) ;
}
void F_267 ( struct V_14 * V_15 )
{
struct V_187 * V_188 = V_15 -> V_245 ;
F_232 ( & V_266 ) ;
F_94 ( & V_15 -> V_267 ) ;
F_235 ( & V_266 ) ;
F_241 ( V_15 ) ;
F_216 ( V_15 , V_188 , V_188 -> V_141 ) ;
F_217 ( V_15 , V_188 ) ;
}
static void F_268 ( struct V_14 * V_15 ,
const struct V_126 * V_244 )
{
F_20 ( ! F_269 ( & V_15 -> V_17 ) ) ;
F_252 ( V_15 ) ;
F_270 ( V_15 -> V_186 , V_15 -> V_141 , V_244 ) ;
F_231 ( V_15 , V_244 ) ;
F_258 ( V_15 ) ;
}
static int F_271 ( struct V_270 * V_271 ,
unsigned long V_225 , void * V_272 )
{
struct V_14 * V_15 ;
int V_28 = ( unsigned long ) V_272 ;
static struct V_126 V_273 ;
switch ( V_225 & ~ V_274 ) {
case V_226 :
case V_275 :
F_236 ( & V_273 , V_269 ) ;
break;
case V_276 :
F_236 ( & V_273 , V_269 ) ;
F_234 ( V_28 , & V_273 ) ;
break;
default:
return V_224 ;
}
F_232 ( & V_266 ) ;
F_240 (q, &all_q_list, all_q_node)
F_9 ( V_15 ) ;
F_240 (q, &all_q_list, all_q_node) {
F_13 ( V_15 ) ;
F_272 ( & V_15 -> V_49 ) ;
}
F_240 (q, &all_q_list, all_q_node)
F_268 ( V_15 , & V_273 ) ;
F_240 (q, &all_q_list, all_q_node)
F_18 ( V_15 ) ;
F_235 ( & V_266 ) ;
return V_224 ;
}
static int F_273 ( struct V_187 * V_188 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_188 -> V_141 ; V_3 ++ ) {
V_188 -> V_20 [ V_3 ] = F_197 ( V_188 , V_3 ) ;
if ( ! V_188 -> V_20 [ V_3 ] )
goto V_277;
}
return 0 ;
V_277:
while ( -- V_3 >= 0 )
F_190 ( V_188 , V_188 -> V_20 [ V_3 ] , V_3 ) ;
return - V_222 ;
}
static int F_274 ( struct V_187 * V_188 )
{
unsigned int V_119 ;
int V_278 ;
V_119 = V_188 -> V_203 ;
do {
V_278 = F_273 ( V_188 ) ;
if ( ! V_278 )
break;
V_188 -> V_203 >>= 1 ;
if ( V_188 -> V_203 < V_188 -> V_204 + V_279 ) {
V_278 = - V_222 ;
break;
}
} while ( V_188 -> V_203 );
if ( ! V_188 -> V_203 || V_278 ) {
F_136 ( L_3 ) ;
return - V_222 ;
}
if ( V_119 != V_188 -> V_203 )
F_275 ( L_4 ,
V_119 , V_188 -> V_203 ) ;
return 0 ;
}
struct V_126 * F_276 ( struct V_93 * V_20 )
{
return V_20 -> V_126 ;
}
int F_277 ( struct V_187 * V_188 )
{
F_278 ( V_280 > 1 << V_281 ) ;
if ( ! V_188 -> V_141 )
return - V_282 ;
if ( ! V_188 -> V_203 )
return - V_282 ;
if ( V_188 -> V_203 < V_188 -> V_204 + V_279 )
return - V_282 ;
if ( ! V_188 -> V_98 -> V_134 || ! V_188 -> V_98 -> V_67 )
return - V_282 ;
if ( V_188 -> V_203 > V_280 ) {
F_275 ( L_5 ,
V_280 ) ;
V_188 -> V_203 = V_280 ;
}
if ( F_279 () ) {
V_188 -> V_141 = 1 ;
V_188 -> V_203 = F_205 ( 64U , V_188 -> V_203 ) ;
}
if ( V_188 -> V_141 > V_145 )
V_188 -> V_141 = V_145 ;
V_188 -> V_20 = F_200 ( V_145 * sizeof( struct V_93 * ) ,
V_206 , V_188 -> V_205 ) ;
if ( ! V_188 -> V_20 )
return - V_222 ;
if ( F_274 ( V_188 ) )
goto V_283;
F_280 ( & V_188 -> V_247 ) ;
F_31 ( & V_188 -> V_249 ) ;
return 0 ;
V_283:
F_194 ( V_188 -> V_20 ) ;
V_188 -> V_20 = NULL ;
return - V_222 ;
}
void F_281 ( struct V_187 * V_188 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_145 ; V_3 ++ ) {
if ( V_188 -> V_20 [ V_3 ] )
F_190 ( V_188 , V_188 -> V_20 [ V_3 ] , V_3 ) ;
}
F_194 ( V_188 -> V_20 ) ;
V_188 -> V_20 = NULL ;
}
int F_282 ( struct V_14 * V_15 , unsigned int V_284 )
{
struct V_187 * V_188 = V_15 -> V_245 ;
struct V_1 * V_2 ;
int V_3 , V_64 ;
if ( ! V_188 || V_284 > V_188 -> V_203 )
return - V_282 ;
V_64 = 0 ;
F_24 (q, hctx, i) {
if ( ! V_2 -> V_20 )
continue;
V_64 = F_283 ( V_2 -> V_20 , V_284 ) ;
if ( V_64 )
break;
}
if ( ! V_64 )
V_15 -> V_264 = V_284 ;
return V_64 ;
}
void F_284 ( struct V_187 * V_188 , int V_141 )
{
struct V_14 * V_15 ;
if ( V_141 > V_145 )
V_141 = V_145 ;
if ( V_141 < 1 || V_141 == V_188 -> V_141 )
return;
F_240 (q, &set->tag_list, tag_set_list)
F_17 ( V_15 ) ;
V_188 -> V_141 = V_141 ;
F_240 (q, &set->tag_list, tag_set_list) {
F_251 ( V_188 , V_15 ) ;
if ( V_15 -> V_141 > 1 )
F_263 ( V_15 , F_177 ) ;
else
F_263 ( V_15 , F_185 ) ;
F_268 ( V_15 , V_269 ) ;
}
F_240 (q, &set->tag_list, tag_set_list)
F_18 ( V_15 ) ;
}
void F_285 ( void )
{
F_232 ( & V_266 ) ;
}
void F_286 ( void )
{
F_235 ( & V_266 ) ;
}
static int T_3 F_287 ( void )
{
F_288 () ;
F_289 ( F_271 , 0 ) ;
return 0 ;
}
