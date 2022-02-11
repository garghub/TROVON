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
F_22 ( V_15 , false ) ;
}
F_23 ( V_15 -> V_18 , F_24 ( & V_15 -> V_17 ) ) ;
}
static void F_25 ( struct V_14 * V_15 )
{
bool V_25 ;
F_19 ( V_15 -> V_24 ) ;
V_25 = ! -- V_15 -> V_19 ;
F_26 ( V_15 -> V_19 < 0 ) ;
F_20 ( V_15 -> V_24 ) ;
if ( V_25 ) {
F_27 ( & V_15 -> V_17 ) ;
F_17 ( & V_15 -> V_18 ) ;
}
}
bool F_28 ( struct V_1 * V_2 )
{
return F_29 ( V_2 -> V_26 ) ;
}
static void F_30 ( struct V_14 * V_15 , struct V_9 * V_10 ,
struct V_27 * V_28 , unsigned int V_29 )
{
if ( F_31 ( V_15 ) )
V_29 |= V_30 ;
F_32 ( & V_28 -> V_31 ) ;
V_28 -> V_15 = V_15 ;
V_28 -> V_32 = V_10 ;
V_28 -> V_33 |= V_29 ;
V_28 -> V_34 = - 1 ;
F_33 ( & V_28 -> V_35 ) ;
F_34 ( & V_28 -> V_36 ) ;
V_28 -> V_37 = NULL ;
V_28 -> V_38 = NULL ;
V_28 -> V_39 = V_40 ;
#ifdef F_35
V_28 -> V_41 = NULL ;
F_36 ( V_28 ) ;
V_28 -> V_42 = 0 ;
#endif
V_28 -> V_43 = 0 ;
#if F_37 ( V_44 )
V_28 -> V_45 = 0 ;
#endif
V_28 -> V_46 = NULL ;
V_28 -> V_47 = 0 ;
V_28 -> V_48 = V_28 -> V_49 ;
V_28 -> V_50 = 0 ;
V_28 -> V_51 = 0 ;
V_28 -> V_52 = 0 ;
V_28 -> V_53 = NULL ;
F_32 ( & V_28 -> V_54 ) ;
V_28 -> V_55 = 0 ;
V_28 -> V_56 = NULL ;
V_28 -> V_57 = NULL ;
V_28 -> V_58 = NULL ;
V_10 -> V_59 [ F_38 ( V_29 ) ] ++ ;
}
static struct V_27 *
F_39 ( struct V_60 * V_61 , int V_62 )
{
struct V_27 * V_28 ;
unsigned int V_63 ;
V_63 = F_40 ( V_61 ) ;
if ( V_63 != V_64 ) {
V_28 = V_61 -> V_2 -> V_26 -> V_65 [ V_63 ] ;
if ( F_41 ( V_61 -> V_2 ) ) {
V_28 -> V_33 = V_66 ;
F_42 ( & V_61 -> V_2 -> V_67 ) ;
}
V_28 -> V_63 = V_63 ;
F_30 ( V_61 -> V_15 , V_61 -> V_10 , V_28 , V_62 ) ;
return V_28 ;
}
return NULL ;
}
struct V_27 * F_43 ( struct V_14 * V_15 , int V_62 , T_1 V_68 ,
bool V_69 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_60 V_70 ;
if ( F_9 ( V_15 ) )
return NULL ;
V_10 = F_44 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_45 ( & V_70 , V_15 , V_68 & ~ V_73 ,
V_69 , V_10 , V_2 ) ;
V_28 = F_39 ( & V_70 , V_62 ) ;
if ( ! V_28 && ( V_68 & V_73 ) ) {
F_46 ( V_2 ) ;
F_47 ( V_10 ) ;
V_10 = F_44 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_45 ( & V_70 , V_15 , V_68 , V_69 , V_10 ,
V_2 ) ;
V_28 = F_39 ( & V_70 , V_62 ) ;
V_10 = V_70 . V_10 ;
}
F_47 ( V_10 ) ;
return V_28 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_27 * V_28 )
{
const int V_63 = V_28 -> V_63 ;
struct V_14 * V_15 = V_28 -> V_15 ;
if ( V_28 -> V_33 & V_66 )
F_49 ( & V_2 -> V_67 ) ;
V_28 -> V_33 = 0 ;
F_8 ( V_74 , & V_28 -> V_75 ) ;
F_50 ( V_2 , V_63 , & V_10 -> V_76 ) ;
F_13 ( V_15 ) ;
}
void F_51 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
struct V_1 * V_2 ;
struct V_14 * V_15 = V_28 -> V_15 ;
V_10 -> V_77 [ F_52 ( V_28 ) ] ++ ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_48 ( V_2 , V_10 , V_28 ) ;
}
void F_53 ( struct V_27 * V_78 ,
struct V_27 * V_79 )
{
struct V_1 * V_2 =
V_79 -> V_15 -> V_71 -> V_72 ( V_79 -> V_15 , V_79 -> V_32 -> V_34 ) ;
V_78 -> V_32 = V_79 -> V_32 ;
V_78 -> V_63 = V_79 -> V_63 ;
memcpy ( F_54 ( V_78 ) , F_54 ( V_79 ) ,
V_2 -> V_80 ) ;
}
inline void F_55 ( struct V_27 * V_28 , int error )
{
F_56 ( V_28 ) ;
if ( V_28 -> V_56 ) {
V_28 -> V_56 ( V_28 , error ) ;
} else {
if ( F_57 ( F_58 ( V_28 ) ) )
F_51 ( V_28 -> V_58 ) ;
F_51 ( V_28 ) ;
}
}
void F_59 ( struct V_27 * V_28 , int error )
{
if ( F_60 ( V_28 , error , F_61 ( V_28 ) ) )
F_62 () ;
F_55 ( V_28 , error ) ;
}
static void F_63 ( void * V_61 )
{
struct V_27 * V_28 = V_61 ;
V_28 -> V_15 -> V_81 ( V_28 ) ;
}
static void F_64 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
bool V_82 = false ;
int V_34 ;
if ( ! F_4 ( V_83 , & V_28 -> V_15 -> V_84 ) ) {
V_28 -> V_15 -> V_81 ( V_28 ) ;
return;
}
V_34 = F_65 () ;
if ( ! F_4 ( V_85 , & V_28 -> V_15 -> V_84 ) )
V_82 = F_66 ( V_34 , V_10 -> V_34 ) ;
if ( V_34 != V_10 -> V_34 && ! V_82 && F_67 ( V_10 -> V_34 ) ) {
V_28 -> V_86 . V_87 = F_63 ;
V_28 -> V_86 . V_88 = V_28 ;
V_28 -> V_86 . V_89 = 0 ;
F_68 ( V_10 -> V_34 , & V_28 -> V_86 ) ;
} else {
V_28 -> V_15 -> V_81 ( V_28 ) ;
}
F_69 () ;
}
void F_70 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( ! V_15 -> V_81 )
F_59 ( V_28 , V_28 -> V_47 ) ;
else
F_64 ( V_28 ) ;
}
void F_71 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( F_57 ( F_72 ( V_15 ) ) )
return;
if ( ! F_73 ( V_28 ) )
F_70 ( V_28 ) ;
}
static void F_74 ( struct V_27 * V_28 , bool V_90 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_75 ( V_15 , V_28 ) ;
V_28 -> V_52 = F_61 ( V_28 ) ;
if ( F_57 ( F_58 ( V_28 ) ) )
V_28 -> V_58 -> V_52 = F_61 ( V_28 -> V_58 ) ;
F_76 ( V_28 ) ;
F_77 () ;
if ( ! F_4 ( V_74 , & V_28 -> V_75 ) )
F_6 ( V_74 , & V_28 -> V_75 ) ;
if ( F_4 ( V_91 , & V_28 -> V_75 ) )
F_8 ( V_91 , & V_28 -> V_75 ) ;
if ( V_15 -> V_92 && F_61 ( V_28 ) ) {
V_28 -> V_43 ++ ;
}
if ( V_90 )
V_28 -> V_33 |= V_93 ;
}
static void F_78 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_79 ( V_15 , V_28 ) ;
F_8 ( V_74 , & V_28 -> V_75 ) ;
V_28 -> V_33 &= ~ V_93 ;
if ( V_15 -> V_92 && F_61 ( V_28 ) )
V_28 -> V_43 -- ;
}
void F_80 ( struct V_27 * V_28 )
{
F_78 ( V_28 ) ;
F_81 ( V_28 ) ;
F_82 ( F_83 ( V_28 ) ) ;
F_84 ( V_28 , true ) ;
}
static void F_85 ( struct V_94 * V_95 )
{
struct V_14 * V_15 =
F_16 ( V_95 , struct V_14 , V_96 ) ;
F_86 ( V_97 ) ;
struct V_27 * V_28 , * V_98 ;
unsigned long V_89 ;
F_87 ( & V_15 -> V_99 , V_89 ) ;
F_88 ( & V_15 -> V_100 , & V_97 ) ;
F_89 ( & V_15 -> V_99 , V_89 ) ;
F_90 (rq, next, &rq_list, queuelist) {
if ( ! ( V_28 -> V_33 & V_101 ) )
continue;
V_28 -> V_33 &= ~ V_101 ;
F_91 ( & V_28 -> V_31 ) ;
F_92 ( V_28 , true , false , false ) ;
}
while ( ! F_93 ( & V_97 ) ) {
V_28 = F_94 ( V_97 . V_98 , struct V_27 , V_31 ) ;
F_91 ( & V_28 -> V_31 ) ;
F_92 ( V_28 , false , false , false ) ;
}
F_95 ( V_15 ) ;
}
void F_84 ( struct V_27 * V_28 , bool V_102 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
unsigned long V_89 ;
F_82 ( V_28 -> V_33 & V_101 ) ;
F_87 ( & V_15 -> V_99 , V_89 ) ;
if ( V_102 ) {
V_28 -> V_33 |= V_101 ;
F_96 ( & V_28 -> V_31 , & V_15 -> V_100 ) ;
} else {
F_97 ( & V_28 -> V_31 , & V_15 -> V_100 ) ;
}
F_89 ( & V_15 -> V_99 , V_89 ) ;
}
void F_98 ( struct V_14 * V_15 )
{
F_99 ( & V_15 -> V_96 ) ;
}
static inline bool F_100 ( struct V_27 * V_28 , unsigned int V_63 )
{
return ( ( V_28 -> V_33 & V_103 ) &&
V_28 -> V_15 -> V_78 -> V_63 == V_63 ) ;
}
struct V_27 * F_101 ( struct V_104 * V_26 , unsigned int V_63 )
{
struct V_27 * V_28 = V_26 -> V_65 [ V_63 ] ;
if ( ! F_100 ( V_28 , V_63 ) )
return V_28 ;
return V_28 -> V_15 -> V_78 ;
}
static void F_102 ( void * V_105 , unsigned long * V_106 )
{
struct V_107 * V_61 = V_105 ;
struct V_1 * V_2 = V_61 -> V_2 ;
unsigned int V_63 ;
V_63 = 0 ;
do {
struct V_27 * V_28 ;
V_63 = F_103 ( V_106 , V_2 -> V_26 -> V_108 , V_63 ) ;
if ( V_63 >= V_2 -> V_26 -> V_108 )
break;
V_28 = F_101 ( V_2 -> V_26 , V_63 ++ ) ;
if ( V_28 -> V_15 != V_2 -> V_109 )
continue;
if ( ! F_4 ( V_74 , & V_28 -> V_75 ) )
continue;
F_104 ( V_28 , V_61 -> V_98 , V_61 -> V_110 ) ;
} while ( 1 );
}
static void F_105 ( struct V_1 * V_2 ,
unsigned long * V_98 ,
unsigned int * V_110 )
{
struct V_107 V_61 = {
. V_2 = V_2 ,
. V_98 = V_98 ,
. V_110 = V_110 ,
} ;
F_106 ( V_2 -> V_26 , F_102 , & V_61 ) ;
}
static enum V_111 F_107 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( ! F_4 ( V_74 , & V_28 -> V_75 ) )
return V_112 ;
if ( ! V_15 -> V_71 -> V_55 )
return V_113 ;
return V_15 -> V_71 -> V_55 ( V_28 ) ;
}
static void F_108 ( unsigned long V_61 )
{
struct V_14 * V_15 = (struct V_14 * ) V_61 ;
struct V_1 * V_2 ;
unsigned long V_98 = 0 ;
int V_3 , V_110 = 0 ;
F_109 (q, hctx, i) {
if ( ! V_2 -> V_114 || ! V_2 -> V_26 )
continue;
F_105 ( V_2 , & V_98 , & V_110 ) ;
}
if ( V_110 ) {
V_98 = F_110 ( F_111 ( V_98 ) ) ;
F_112 ( & V_15 -> V_55 , V_98 ) ;
} else {
F_109 (q, hctx, i)
F_113 ( V_2 ) ;
}
}
static bool F_114 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_115 * V_115 )
{
struct V_27 * V_28 ;
int V_116 = 8 ;
F_115 (rq, &ctx->rq_list, queuelist) {
int V_117 ;
if ( ! V_116 -- )
break;
if ( ! F_116 ( V_28 , V_115 ) )
continue;
V_117 = F_117 ( V_28 , V_115 ) ;
if ( V_117 == V_118 ) {
if ( F_118 ( V_15 , V_28 , V_115 ) ) {
V_10 -> V_119 ++ ;
return true ;
}
break;
} else if ( V_117 == V_120 ) {
if ( F_119 ( V_15 , V_28 , V_115 ) ) {
V_10 -> V_119 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_120 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
struct V_9 * V_10 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_8 * V_13 = & V_2 -> V_4 . V_6 [ V_3 ] ;
unsigned int V_123 , V_124 ;
if ( ! V_13 -> V_7 )
continue;
V_124 = 0 ;
V_123 = V_3 * V_2 -> V_4 . V_12 ;
do {
V_124 = F_121 ( & V_13 -> V_7 , V_13 -> V_125 , V_124 ) ;
if ( V_124 >= V_13 -> V_125 )
break;
V_10 = V_2 -> V_126 [ V_124 + V_123 ] ;
F_8 ( V_124 , & V_13 -> V_7 ) ;
F_122 ( & V_10 -> V_127 ) ;
F_123 ( & V_10 -> V_97 , V_122 ) ;
F_124 ( & V_10 -> V_127 ) ;
V_124 ++ ;
} while ( 1 );
}
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_109 ;
struct V_27 * V_28 ;
F_86 ( V_97 ) ;
int V_128 ;
F_125 ( ! F_126 ( F_127 () , V_2 -> V_129 ) ) ;
if ( F_57 ( F_4 ( V_130 , & V_2 -> V_131 ) ) )
return;
V_2 -> V_132 ++ ;
F_120 ( V_2 , & V_97 ) ;
if ( ! F_128 ( & V_2 -> V_133 ) ) {
F_122 ( & V_2 -> V_127 ) ;
if ( ! F_93 ( & V_2 -> V_133 ) )
F_88 ( & V_2 -> V_133 , & V_97 ) ;
F_124 ( & V_2 -> V_127 ) ;
}
V_128 = 0 ;
while ( ! F_93 ( & V_97 ) ) {
int V_16 ;
V_28 = F_129 ( & V_97 , struct V_27 , V_31 ) ;
F_91 ( & V_28 -> V_31 ) ;
F_74 ( V_28 , F_93 ( & V_97 ) ) ;
V_16 = V_15 -> V_71 -> V_134 ( V_2 , V_28 ) ;
switch ( V_16 ) {
case V_135 :
V_128 ++ ;
continue;
case V_136 :
F_96 ( & V_28 -> V_31 , & V_97 ) ;
F_78 ( V_28 ) ;
break;
default:
F_130 ( L_1 , V_16 ) ;
case V_137 :
V_28 -> V_47 = - V_138 ;
F_59 ( V_28 , V_28 -> V_47 ) ;
break;
}
if ( V_16 == V_136 )
break;
}
if ( ! V_128 )
V_2 -> V_139 [ 0 ] ++ ;
else if ( V_128 < ( 1 << ( V_140 - 1 ) ) )
V_2 -> V_139 [ F_131 ( V_128 ) + 1 ] ++ ;
if ( ! F_93 ( & V_97 ) ) {
F_122 ( & V_2 -> V_127 ) ;
F_132 ( & V_97 , & V_2 -> V_133 ) ;
F_124 ( & V_2 -> V_127 ) ;
}
}
static int F_133 ( struct V_1 * V_2 )
{
int V_34 = V_2 -> V_141 ;
if ( -- V_2 -> V_142 <= 0 ) {
int V_141 ;
V_141 = F_134 ( V_2 -> V_141 , V_2 -> V_129 ) ;
if ( V_141 >= V_143 )
V_141 = F_135 ( V_2 -> V_129 ) ;
V_2 -> V_141 = V_141 ;
V_2 -> V_142 = V_144 ;
}
return V_34 ;
}
void F_136 ( struct V_1 * V_2 , bool V_145 )
{
if ( F_57 ( F_4 ( V_130 , & V_2 -> V_131 ) ) )
return;
if ( ! V_145 && F_126 ( F_137 () , V_2 -> V_129 ) )
F_46 ( V_2 ) ;
else if ( V_2 -> V_109 -> V_146 == 1 )
F_138 ( & V_2 -> V_147 , 0 ) ;
else {
unsigned int V_34 ;
V_34 = F_133 ( V_2 ) ;
F_139 ( V_34 , & V_2 -> V_147 , 0 ) ;
}
}
void F_22 ( struct V_14 * V_15 , bool V_145 )
{
struct V_1 * V_2 ;
int V_3 ;
F_109 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_128 ( & V_2 -> V_133 ) ) ||
F_4 ( V_130 , & V_2 -> V_131 ) )
continue;
F_140 () ;
F_136 ( V_2 , V_145 ) ;
F_141 () ;
}
}
void F_142 ( struct V_1 * V_2 )
{
F_143 ( & V_2 -> V_147 ) ;
F_143 ( & V_2 -> V_148 ) ;
F_6 ( V_130 , & V_2 -> V_131 ) ;
}
void F_144 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_109 (q, hctx, i)
F_142 ( V_2 ) ;
}
void F_145 ( struct V_1 * V_2 )
{
F_8 ( V_130 , & V_2 -> V_131 ) ;
F_140 () ;
F_136 ( V_2 , false ) ;
F_141 () ;
}
void F_95 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_109 (q, hctx, i)
F_145 ( V_2 ) ;
}
void F_146 ( struct V_14 * V_15 , bool V_145 )
{
struct V_1 * V_2 ;
int V_3 ;
F_109 (q, hctx, i) {
if ( ! F_4 ( V_130 , & V_2 -> V_131 ) )
continue;
F_8 ( V_130 , & V_2 -> V_131 ) ;
F_140 () ;
F_136 ( V_2 , V_145 ) ;
F_141 () ;
}
}
static void F_147 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_95 , struct V_1 , V_147 . V_95 ) ;
F_46 ( V_2 ) ;
}
static void F_148 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_95 , struct V_1 , V_148 . V_95 ) ;
if ( F_149 ( V_130 , & V_2 -> V_131 ) )
F_46 ( V_2 ) ;
}
void F_150 ( struct V_1 * V_2 , unsigned long V_149 )
{
unsigned long V_150 = F_151 ( V_149 ) ;
if ( V_2 -> V_109 -> V_146 == 1 )
F_138 ( & V_2 -> V_148 , V_150 ) ;
else {
unsigned int V_34 ;
V_34 = F_133 ( V_2 ) ;
F_139 ( V_34 , & V_2 -> V_148 , V_150 ) ;
}
}
static void F_152 ( struct V_1 * V_2 ,
struct V_27 * V_28 , bool V_102 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
F_153 ( V_2 -> V_109 , V_28 ) ;
if ( V_102 )
F_96 ( & V_28 -> V_31 , & V_10 -> V_97 ) ;
else
F_97 ( & V_28 -> V_31 , & V_10 -> V_97 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_92 ( struct V_27 * V_28 , bool V_102 , bool V_151 ,
bool V_145 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_28 -> V_32 , * V_152 ;
V_152 = F_44 ( V_15 ) ;
if ( ! F_67 ( V_10 -> V_34 ) )
V_28 -> V_32 = V_10 = V_152 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_122 ( & V_10 -> V_127 ) ;
F_152 ( V_2 , V_28 , V_102 ) ;
F_124 ( & V_10 -> V_127 ) ;
if ( V_151 )
F_136 ( V_2 , V_145 ) ;
F_47 ( V_152 ) ;
}
static void F_154 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_121 * V_122 ,
int V_125 ,
bool V_153 )
{
struct V_1 * V_2 ;
struct V_9 * V_152 ;
F_155 ( V_15 , V_125 , ! V_153 ) ;
V_152 = F_44 ( V_15 ) ;
if ( ! F_67 ( V_10 -> V_34 ) )
V_10 = V_152 ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_122 ( & V_10 -> V_127 ) ;
while ( ! F_93 ( V_122 ) ) {
struct V_27 * V_28 ;
V_28 = F_129 ( V_122 , struct V_27 , V_31 ) ;
F_91 ( & V_28 -> V_31 ) ;
V_28 -> V_32 = V_10 ;
F_152 ( V_2 , V_28 , false ) ;
}
F_124 ( & V_10 -> V_127 ) ;
F_136 ( V_2 , V_153 ) ;
F_47 ( V_152 ) ;
}
static int F_156 ( void * V_154 , struct V_121 * V_155 , struct V_121 * V_156 )
{
struct V_27 * V_157 = F_16 ( V_155 , struct V_27 , V_31 ) ;
struct V_27 * V_158 = F_16 ( V_156 , struct V_27 , V_31 ) ;
return ! ( V_157 -> V_32 < V_158 -> V_32 ||
( V_157 -> V_32 == V_158 -> V_32 &&
F_157 ( V_157 ) < F_157 ( V_158 ) ) ) ;
}
void F_158 ( struct V_159 * V_160 , bool V_153 )
{
struct V_9 * V_161 ;
struct V_14 * V_162 ;
struct V_27 * V_28 ;
F_86 ( V_122 ) ;
F_86 ( V_163 ) ;
unsigned int V_125 ;
F_88 ( & V_160 -> V_164 , & V_122 ) ;
F_159 ( NULL , & V_122 , F_156 ) ;
V_162 = NULL ;
V_161 = NULL ;
V_125 = 0 ;
while ( ! F_93 ( & V_122 ) ) {
V_28 = F_160 ( V_122 . V_98 ) ;
F_91 ( & V_28 -> V_31 ) ;
F_82 ( ! V_28 -> V_15 ) ;
if ( V_28 -> V_32 != V_161 ) {
if ( V_161 ) {
F_154 ( V_162 , V_161 ,
& V_163 , V_125 ,
V_153 ) ;
}
V_161 = V_28 -> V_32 ;
V_162 = V_28 -> V_15 ;
V_125 = 0 ;
}
V_125 ++ ;
F_97 ( & V_28 -> V_31 , & V_163 ) ;
}
if ( V_161 ) {
F_154 ( V_162 , V_161 , & V_163 , V_125 ,
V_153 ) ;
}
}
static void F_161 ( struct V_27 * V_28 , struct V_115 * V_115 )
{
F_162 ( V_28 , V_115 ) ;
if ( F_163 ( V_28 ) )
F_164 ( V_28 , 1 ) ;
}
static inline bool F_165 ( struct V_1 * V_2 )
{
return ( V_2 -> V_89 & V_165 ) &&
! F_166 ( V_2 -> V_109 ) ;
}
static inline bool F_167 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_27 * V_28 , struct V_115 * V_115 )
{
if ( ! F_165 ( V_2 ) ) {
F_161 ( V_28 , V_115 ) ;
F_122 ( & V_10 -> V_127 ) ;
V_166:
F_152 ( V_2 , V_28 , false ) ;
F_124 ( & V_10 -> V_127 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_109 ;
F_122 ( & V_10 -> V_127 ) ;
if ( ! F_114 ( V_15 , V_10 , V_115 ) ) {
F_161 ( V_28 , V_115 ) ;
goto V_166;
}
F_124 ( & V_10 -> V_127 ) ;
F_48 ( V_2 , V_10 , V_28 ) ;
return true ;
}
}
static struct V_27 * F_168 ( struct V_14 * V_15 ,
struct V_115 * V_115 ,
struct V_167 * V_61 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
int V_62 = F_169 ( V_115 ) ;
struct V_60 V_70 ;
if ( F_57 ( F_9 ( V_15 ) ) ) {
F_170 ( V_115 , - V_138 ) ;
return NULL ;
}
V_10 = F_44 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
if ( F_38 ( V_115 -> V_168 ) )
V_62 |= V_169 ;
F_171 ( V_15 , V_115 , V_62 ) ;
F_45 ( & V_70 , V_15 , V_170 , false , V_10 ,
V_2 ) ;
V_28 = F_39 ( & V_70 , V_62 ) ;
if ( F_57 ( ! V_28 ) ) {
F_46 ( V_2 ) ;
F_47 ( V_10 ) ;
F_172 ( V_15 , V_115 , V_62 ) ;
V_10 = F_44 ( V_15 ) ;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_45 ( & V_70 , V_15 ,
V_73 | V_170 , false , V_10 , V_2 ) ;
V_28 = F_39 ( & V_70 , V_62 ) ;
V_10 = V_70 . V_10 ;
V_2 = V_70 . V_2 ;
}
V_2 -> V_128 ++ ;
V_61 -> V_2 = V_2 ;
V_61 -> V_10 = V_10 ;
return V_28 ;
}
static void F_173 ( struct V_14 * V_15 , struct V_115 * V_115 )
{
const int V_171 = F_38 ( V_115 -> V_168 ) ;
const int V_172 = V_115 -> V_168 & ( V_173 | V_174 ) ;
struct V_167 V_61 ;
struct V_27 * V_28 ;
F_174 ( V_15 , & V_115 ) ;
if ( F_175 ( V_115 ) && F_176 ( V_115 ) ) {
F_170 ( V_115 , - V_138 ) ;
return;
}
V_28 = F_168 ( V_15 , V_115 , & V_61 ) ;
if ( F_57 ( ! V_28 ) )
return;
if ( F_57 ( V_172 ) ) {
F_161 ( V_28 , V_115 ) ;
F_177 ( V_28 ) ;
goto V_151;
}
if ( V_171 ) {
int V_16 ;
F_161 ( V_28 , V_115 ) ;
F_74 ( V_28 , true ) ;
V_16 = V_15 -> V_71 -> V_134 ( V_61 . V_2 , V_28 ) ;
if ( V_16 == V_135 )
goto V_175;
else {
F_78 ( V_28 ) ;
if ( V_16 == V_137 ) {
V_28 -> V_47 = - V_138 ;
F_59 ( V_28 , V_28 -> V_47 ) ;
goto V_175;
}
}
}
if ( ! F_167 ( V_61 . V_2 , V_61 . V_10 , V_28 , V_115 ) ) {
V_151:
F_136 ( V_61 . V_2 , ! V_171 || V_172 ) ;
}
V_175:
F_47 ( V_61 . V_10 ) ;
}
static void F_178 ( struct V_14 * V_15 , struct V_115 * V_115 )
{
const int V_171 = F_38 ( V_115 -> V_168 ) ;
const int V_172 = V_115 -> V_168 & ( V_173 | V_174 ) ;
unsigned int V_176 , V_177 = 0 ;
struct V_167 V_61 ;
struct V_27 * V_28 ;
V_176 = ! V_172 && ! V_171 ;
F_174 ( V_15 , & V_115 ) ;
if ( F_175 ( V_115 ) && F_176 ( V_115 ) ) {
F_170 ( V_115 , - V_138 ) ;
return;
}
if ( V_176 && ! F_166 ( V_15 ) &&
F_179 ( V_15 , V_115 , & V_177 ) )
return;
V_28 = F_168 ( V_15 , V_115 , & V_61 ) ;
if ( F_57 ( ! V_28 ) )
return;
if ( F_57 ( V_172 ) ) {
F_161 ( V_28 , V_115 ) ;
F_177 ( V_28 ) ;
goto V_151;
}
if ( V_176 ) {
struct V_159 * V_160 = V_178 -> V_160 ;
if ( V_160 ) {
F_161 ( V_28 , V_115 ) ;
if ( F_93 ( & V_160 -> V_164 ) )
F_180 ( V_15 ) ;
else if ( V_177 >= V_179 ) {
F_181 ( V_160 , false ) ;
F_180 ( V_15 ) ;
}
F_97 ( & V_28 -> V_31 , & V_160 -> V_164 ) ;
F_47 ( V_61 . V_10 ) ;
return;
}
}
if ( ! F_167 ( V_61 . V_2 , V_61 . V_10 , V_28 , V_115 ) ) {
V_151:
F_136 ( V_61 . V_2 , ! V_171 || V_172 ) ;
}
F_47 ( V_61 . V_10 ) ;
}
struct V_1 * F_182 ( struct V_14 * V_15 , const int V_34 )
{
return V_15 -> V_180 [ V_15 -> V_181 [ V_34 ] ] ;
}
static void F_183 ( struct V_182 * V_183 ,
struct V_104 * V_26 , unsigned int V_184 )
{
struct V_185 * V_185 ;
if ( V_26 -> V_65 && V_183 -> V_186 -> V_187 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_108 ; V_3 ++ ) {
if ( ! V_26 -> V_65 [ V_3 ] )
continue;
V_183 -> V_186 -> V_187 ( V_183 -> V_188 , V_26 -> V_65 [ V_3 ] ,
V_184 , V_3 ) ;
V_26 -> V_65 [ V_3 ] = NULL ;
}
}
while ( ! F_93 ( & V_26 -> V_189 ) ) {
V_185 = F_129 ( & V_26 -> V_189 , struct V_185 , V_190 ) ;
F_91 ( & V_185 -> V_190 ) ;
F_184 ( V_185 , V_185 -> V_191 ) ;
}
F_185 ( V_26 -> V_65 ) ;
F_186 ( V_26 ) ;
}
static T_2 F_187 ( unsigned int V_192 )
{
return ( T_2 ) V_193 << V_192 ;
}
static struct V_104 * F_188 ( struct V_182 * V_183 ,
unsigned int V_184 )
{
struct V_104 * V_26 ;
unsigned int V_3 , V_194 , V_195 , V_196 = 4 ;
T_2 V_197 , V_198 ;
V_26 = F_189 ( V_183 -> V_199 , V_183 -> V_200 ,
V_183 -> V_201 ) ;
if ( ! V_26 )
return NULL ;
F_32 ( & V_26 -> V_189 ) ;
V_26 -> V_65 = F_190 ( V_183 -> V_199 * sizeof( struct V_27 * ) ,
V_202 | V_203 | V_204 ,
V_183 -> V_201 ) ;
if ( ! V_26 -> V_65 ) {
F_186 ( V_26 ) ;
return NULL ;
}
V_197 = F_191 ( sizeof( struct V_27 ) + V_183 -> V_80 ,
F_192 () ) ;
V_198 = V_197 * V_183 -> V_199 ;
for ( V_3 = 0 ; V_3 < V_183 -> V_199 ; ) {
int V_205 = V_196 ;
struct V_185 * V_185 ;
int V_206 ;
void * V_207 ;
while ( V_198 < F_187 ( V_205 - 1 ) && V_205 )
V_205 -- ;
do {
V_185 = F_193 ( V_183 -> V_201 ,
V_202 | V_203 | V_204 ,
V_205 ) ;
if ( V_185 )
break;
if ( ! V_205 -- )
break;
if ( F_187 ( V_205 ) < V_197 )
break;
} while ( 1 );
if ( ! V_185 )
goto V_208;
V_185 -> V_191 = V_205 ;
F_97 ( & V_185 -> V_190 , & V_26 -> V_189 ) ;
V_207 = F_194 ( V_185 ) ;
V_195 = F_187 ( V_205 ) / V_197 ;
V_206 = F_195 ( V_195 , V_183 -> V_199 - V_3 ) ;
V_198 -= V_206 * V_197 ;
for ( V_194 = 0 ; V_194 < V_206 ; V_194 ++ ) {
V_26 -> V_65 [ V_3 ] = V_207 ;
V_26 -> V_65 [ V_3 ] -> V_75 = 0 ;
V_26 -> V_65 [ V_3 ] -> V_33 = 0 ;
if ( V_183 -> V_186 -> V_209 ) {
if ( V_183 -> V_186 -> V_209 ( V_183 -> V_188 ,
V_26 -> V_65 [ V_3 ] , V_184 , V_3 ,
V_183 -> V_201 ) ) {
V_26 -> V_65 [ V_3 ] = NULL ;
goto V_208;
}
}
V_207 += V_197 ;
V_3 ++ ;
}
}
return V_26 ;
V_208:
F_183 ( V_183 , V_26 , V_184 ) ;
return NULL ;
}
static void F_196 ( struct V_210 * V_211 )
{
F_185 ( V_211 -> V_6 ) ;
}
static int F_197 ( struct V_210 * V_211 , int V_212 )
{
unsigned int V_213 = 8 , V_214 , V_215 , V_3 ;
V_211 -> V_12 = V_213 ;
V_215 = F_198 ( V_143 , V_213 ) / V_213 ;
V_211 -> V_6 = F_190 ( V_215 * sizeof( struct V_8 ) ,
V_202 , V_212 ) ;
if ( ! V_211 -> V_6 )
return - V_216 ;
V_211 -> V_5 = V_215 ;
V_214 = V_143 ;
for ( V_3 = 0 ; V_3 < V_215 ; V_3 ++ ) {
V_211 -> V_6 [ V_3 ] . V_125 = F_195 ( V_214 , V_211 -> V_12 ) ;
V_214 -= V_211 -> V_6 [ V_3 ] . V_125 ;
}
return 0 ;
}
static int F_199 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_109 ;
struct V_9 * V_10 ;
F_86 ( V_217 ) ;
V_10 = F_200 ( V_15 , V_34 ) ;
F_122 ( & V_10 -> V_127 ) ;
if ( ! F_93 ( & V_10 -> V_97 ) ) {
F_88 ( & V_10 -> V_97 , & V_217 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_124 ( & V_10 -> V_127 ) ;
if ( F_93 ( & V_217 ) )
return V_218 ;
V_10 = F_44 ( V_15 ) ;
F_122 ( & V_10 -> V_127 ) ;
while ( ! F_93 ( & V_217 ) ) {
struct V_27 * V_28 ;
V_28 = F_129 ( & V_217 , struct V_27 , V_31 ) ;
V_28 -> V_32 = V_10 ;
F_201 ( & V_28 -> V_31 , & V_10 -> V_97 ) ;
}
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_10 -> V_34 ) ;
F_3 ( V_2 , V_10 ) ;
F_124 ( & V_10 -> V_127 ) ;
F_136 ( V_2 , true ) ;
F_47 ( V_10 ) ;
return V_218 ;
}
static int F_202 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_109 ;
struct V_182 * V_183 = V_15 -> V_219 ;
if ( V_183 -> V_26 [ V_2 -> V_220 ] )
return V_218 ;
V_183 -> V_26 [ V_2 -> V_220 ] = F_188 ( V_183 , V_2 -> V_220 ) ;
if ( ! V_183 -> V_26 [ V_2 -> V_220 ] )
return V_221 ;
V_2 -> V_26 = V_183 -> V_26 [ V_2 -> V_220 ] ;
return V_218 ;
}
static int F_203 ( void * V_61 , unsigned long V_222 ,
unsigned int V_34 )
{
struct V_1 * V_2 = V_61 ;
if ( V_222 == V_223 || V_222 == V_224 )
return F_199 ( V_2 , V_34 ) ;
else if ( V_222 == V_225 || V_222 == V_226 )
return F_202 ( V_2 , V_34 ) ;
return V_218 ;
}
static void F_204 ( struct V_14 * V_15 ,
struct V_182 * V_183 , int V_227 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_109 (q, hctx, i) {
if ( V_3 == V_227 )
break;
F_113 ( V_2 ) ;
if ( V_183 -> V_186 -> V_228 )
V_183 -> V_186 -> V_228 ( V_2 , V_3 ) ;
F_205 ( & V_2 -> V_229 ) ;
F_185 ( V_2 -> V_126 ) ;
F_196 ( & V_2 -> V_4 ) ;
}
}
static void F_206 ( struct V_14 * V_15 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_109 (q, hctx, i) {
F_207 ( V_2 -> V_129 ) ;
F_185 ( V_2 ) ;
}
}
static int F_208 ( struct V_14 * V_15 ,
struct V_182 * V_183 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_109 (q, hctx, i) {
int V_212 ;
V_212 = V_2 -> V_201 ;
if ( V_212 == V_230 )
V_212 = V_2 -> V_201 = V_183 -> V_201 ;
F_209 ( & V_2 -> V_147 , F_147 ) ;
F_209 ( & V_2 -> V_148 , F_148 ) ;
F_210 ( & V_2 -> V_127 ) ;
F_32 ( & V_2 -> V_133 ) ;
V_2 -> V_109 = V_15 ;
V_2 -> V_220 = V_3 ;
V_2 -> V_89 = V_183 -> V_89 ;
V_2 -> V_80 = V_183 -> V_80 ;
F_211 ( & V_2 -> V_229 ,
F_203 , V_2 ) ;
F_212 ( & V_2 -> V_229 ) ;
V_2 -> V_26 = V_183 -> V_26 [ V_3 ] ;
V_2 -> V_126 = F_213 ( V_143 * sizeof( void * ) ,
V_202 , V_212 ) ;
if ( ! V_2 -> V_126 )
break;
if ( F_197 ( & V_2 -> V_4 , V_212 ) )
break;
V_2 -> V_114 = 0 ;
if ( V_183 -> V_186 -> V_231 &&
V_183 -> V_186 -> V_231 ( V_2 , V_183 -> V_188 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_146 )
return 0 ;
F_204 ( V_15 , V_183 , V_3 ) ;
return 1 ;
}
static void F_214 ( struct V_14 * V_15 ,
unsigned int V_146 )
{
unsigned int V_3 ;
F_215 (i) {
struct V_9 * V_232 = F_216 ( V_15 -> V_233 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
V_232 -> V_34 = V_3 ;
F_210 ( & V_232 -> V_127 ) ;
F_32 ( & V_232 -> V_97 ) ;
V_232 -> V_109 = V_15 ;
if ( ! F_67 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_217 ( V_3 , V_2 -> V_129 ) ;
V_2 -> V_114 ++ ;
if ( V_146 > 1 && V_2 -> V_201 == V_230 )
V_2 -> V_201 = F_218 ( V_3 ) ;
}
}
static void F_219 ( struct V_14 * V_15 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_109 (q, hctx, i) {
F_220 ( V_2 -> V_129 ) ;
V_2 -> V_114 = 0 ;
}
F_221 (q, ctx, i) {
if ( ! F_67 ( V_3 ) )
continue;
V_2 = V_15 -> V_71 -> V_72 ( V_15 , V_3 ) ;
F_217 ( V_3 , V_2 -> V_129 ) ;
V_10 -> V_11 = V_2 -> V_114 ;
V_2 -> V_126 [ V_2 -> V_114 ++ ] = V_10 ;
}
F_109 (q, hctx, i) {
if ( ! V_2 -> V_114 ) {
struct V_182 * V_183 = V_15 -> V_219 ;
if ( V_183 -> V_26 [ V_3 ] ) {
F_183 ( V_183 , V_183 -> V_26 [ V_3 ] , V_3 ) ;
V_183 -> V_26 [ V_3 ] = NULL ;
V_2 -> V_26 = NULL ;
}
continue;
}
V_2 -> V_141 = F_135 ( V_2 -> V_129 ) ;
V_2 -> V_142 = V_144 ;
}
}
static void F_222 ( struct V_182 * V_183 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
bool V_82 ;
int V_3 ;
if ( V_183 -> V_234 . V_98 == V_183 -> V_234 . V_235 )
V_82 = false ;
else
V_82 = true ;
F_223 (q, &set->tag_list, tag_set_list) {
F_18 ( V_15 ) ;
F_109 (q, hctx, i) {
if ( V_82 )
V_2 -> V_89 |= V_236 ;
else
V_2 -> V_89 &= ~ V_236 ;
}
F_25 ( V_15 ) ;
}
}
static void F_224 ( struct V_14 * V_15 )
{
struct V_182 * V_183 = V_15 -> V_219 ;
F_225 ( & V_183 -> V_237 ) ;
F_91 ( & V_15 -> V_238 ) ;
F_222 ( V_183 ) ;
F_226 ( & V_183 -> V_237 ) ;
}
static void F_227 ( struct V_182 * V_183 ,
struct V_14 * V_15 )
{
V_15 -> V_219 = V_183 ;
F_225 ( & V_183 -> V_237 ) ;
F_97 ( & V_15 -> V_238 , & V_183 -> V_234 ) ;
F_222 ( V_183 ) ;
F_226 ( & V_183 -> V_237 ) ;
}
struct V_14 * F_228 ( struct V_182 * V_183 )
{
struct V_1 * * V_239 ;
struct V_9 T_3 * V_10 ;
struct V_14 * V_15 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_229 ( struct V_9 ) ;
if ( ! V_10 )
return F_230 ( - V_216 ) ;
V_239 = F_213 ( V_183 -> V_146 * sizeof( * V_239 ) , V_202 ,
V_183 -> V_201 ) ;
if ( ! V_239 )
goto V_240;
V_6 = F_231 ( V_183 ) ;
if ( ! V_6 )
goto V_241;
for ( V_3 = 0 ; V_3 < V_183 -> V_146 ; V_3 ++ ) {
int V_212 = F_232 ( V_6 , V_3 ) ;
V_239 [ V_3 ] = F_190 ( sizeof( struct V_1 ) ,
V_202 , V_212 ) ;
if ( ! V_239 [ V_3 ] )
goto V_242;
if ( ! F_233 ( & V_239 [ V_3 ] -> V_129 , V_202 ) )
goto V_242;
F_234 ( & V_239 [ V_3 ] -> V_67 , 0 ) ;
V_239 [ V_3 ] -> V_201 = V_212 ;
V_239 [ V_3 ] -> V_220 = V_3 ;
}
V_15 = F_235 ( V_202 , V_183 -> V_201 ) ;
if ( ! V_15 )
goto V_242;
if ( F_236 ( & V_15 -> V_17 , F_15 ) )
goto V_241;
F_237 ( & V_15 -> V_55 , F_108 , ( unsigned long ) V_15 ) ;
F_238 ( V_15 , 30000 ) ;
V_15 -> V_243 = V_143 ;
V_15 -> V_146 = V_183 -> V_146 ;
V_15 -> V_181 = V_6 ;
V_15 -> V_233 = V_10 ;
V_15 -> V_180 = V_239 ;
V_15 -> V_71 = V_183 -> V_186 ;
V_15 -> V_84 |= V_244 ;
if ( ! ( V_183 -> V_89 & V_245 ) )
V_15 -> V_84 |= 1 << V_246 ;
V_15 -> V_247 = V_248 ;
F_239 ( & V_15 -> V_96 , F_85 ) ;
F_32 ( & V_15 -> V_100 ) ;
F_210 ( & V_15 -> V_99 ) ;
if ( V_15 -> V_146 > 1 )
F_240 ( V_15 , F_173 ) ;
else
F_240 ( V_15 , F_178 ) ;
F_241 ( V_15 , F_107 ) ;
if ( V_183 -> V_55 )
F_238 ( V_15 , V_183 -> V_55 ) ;
V_15 -> V_249 = V_183 -> V_199 ;
if ( V_183 -> V_186 -> V_250 )
F_242 ( V_15 , V_183 -> V_186 -> V_250 ) ;
F_243 ( V_15 ) ;
F_214 ( V_15 , V_183 -> V_146 ) ;
V_15 -> V_78 = F_244 ( F_191 ( sizeof( struct V_27 ) +
V_183 -> V_80 , F_192 () ) ,
V_202 ) ;
if ( ! V_15 -> V_78 )
goto V_251;
if ( F_208 ( V_15 , V_183 ) )
goto V_252;
F_225 ( & V_253 ) ;
F_97 ( & V_15 -> V_254 , & V_255 ) ;
F_226 ( & V_253 ) ;
F_227 ( V_183 , V_15 ) ;
F_219 ( V_15 ) ;
return V_15 ;
V_252:
F_185 ( V_15 -> V_78 ) ;
V_251:
F_245 ( V_15 ) ;
V_242:
F_185 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_183 -> V_146 ; V_3 ++ ) {
if ( ! V_239 [ V_3 ] )
break;
F_207 ( V_239 [ V_3 ] -> V_129 ) ;
F_185 ( V_239 [ V_3 ] ) ;
}
V_241:
F_185 ( V_239 ) ;
V_240:
F_246 ( V_10 ) ;
return F_230 ( - V_216 ) ;
}
void F_247 ( struct V_14 * V_15 )
{
struct V_182 * V_183 = V_15 -> V_219 ;
F_224 ( V_15 ) ;
F_204 ( V_15 , V_183 , V_183 -> V_146 ) ;
F_206 ( V_15 , V_183 ) ;
F_248 ( & V_15 -> V_17 ) ;
F_246 ( V_15 -> V_233 ) ;
F_185 ( V_15 -> V_180 ) ;
F_185 ( V_15 -> V_181 ) ;
V_15 -> V_233 = NULL ;
V_15 -> V_180 = NULL ;
V_15 -> V_181 = NULL ;
F_225 ( & V_253 ) ;
F_91 ( & V_15 -> V_254 ) ;
F_226 ( & V_253 ) ;
}
static void F_249 ( struct V_14 * V_15 )
{
F_18 ( V_15 ) ;
F_250 ( V_15 ) ;
F_251 ( V_15 -> V_181 , V_15 -> V_146 ) ;
F_219 ( V_15 ) ;
F_252 ( V_15 ) ;
F_25 ( V_15 ) ;
}
static int F_253 ( struct V_256 * V_257 ,
unsigned long V_222 , void * V_258 )
{
struct V_14 * V_15 ;
if ( V_222 != V_223 && V_222 != V_224 &&
V_222 != V_225 && V_222 != V_226 )
return V_218 ;
F_225 ( & V_253 ) ;
F_223 (q, &all_q_list, all_q_node)
F_249 ( V_15 ) ;
F_226 ( & V_253 ) ;
return V_218 ;
}
static int F_254 ( struct V_182 * V_183 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_183 -> V_146 ; V_3 ++ ) {
V_183 -> V_26 [ V_3 ] = F_188 ( V_183 , V_3 ) ;
if ( ! V_183 -> V_26 [ V_3 ] )
goto V_259;
}
return 0 ;
V_259:
while ( -- V_3 >= 0 )
F_183 ( V_183 , V_183 -> V_26 [ V_3 ] , V_3 ) ;
return - V_216 ;
}
static int F_255 ( struct V_182 * V_183 )
{
unsigned int V_125 ;
int V_260 ;
V_125 = V_183 -> V_199 ;
do {
V_260 = F_254 ( V_183 ) ;
if ( ! V_260 )
break;
V_183 -> V_199 >>= 1 ;
if ( V_183 -> V_199 < V_183 -> V_200 + V_261 ) {
V_260 = - V_216 ;
break;
}
} while ( V_183 -> V_199 );
if ( ! V_183 -> V_199 || V_260 ) {
F_130 ( L_2 ) ;
return - V_216 ;
}
if ( V_125 != V_183 -> V_199 )
F_256 ( L_3 ,
V_125 , V_183 -> V_199 ) ;
return 0 ;
}
int F_257 ( struct V_182 * V_183 )
{
if ( ! V_183 -> V_146 )
return - V_262 ;
if ( ! V_183 -> V_199 )
return - V_262 ;
if ( V_183 -> V_199 < V_183 -> V_200 + V_261 )
return - V_262 ;
if ( ! V_183 -> V_146 || ! V_183 -> V_186 -> V_134 || ! V_183 -> V_186 -> V_72 )
return - V_262 ;
if ( V_183 -> V_199 > V_263 ) {
F_256 ( L_4 ,
V_263 ) ;
V_183 -> V_199 = V_263 ;
}
V_183 -> V_26 = F_213 ( V_183 -> V_146 *
sizeof( struct V_104 * ) ,
V_202 , V_183 -> V_201 ) ;
if ( ! V_183 -> V_26 )
return - V_216 ;
if ( F_255 ( V_183 ) )
goto V_264;
F_258 ( & V_183 -> V_237 ) ;
F_32 ( & V_183 -> V_234 ) ;
return 0 ;
V_264:
F_185 ( V_183 -> V_26 ) ;
V_183 -> V_26 = NULL ;
return - V_216 ;
}
void F_259 ( struct V_182 * V_183 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_183 -> V_146 ; V_3 ++ ) {
if ( V_183 -> V_26 [ V_3 ] )
F_183 ( V_183 , V_183 -> V_26 [ V_3 ] , V_3 ) ;
}
F_185 ( V_183 -> V_26 ) ;
V_183 -> V_26 = NULL ;
}
int F_260 ( struct V_14 * V_15 , unsigned int V_265 )
{
struct V_182 * V_183 = V_15 -> V_219 ;
struct V_1 * V_2 ;
int V_3 , V_16 ;
if ( ! V_183 || V_265 > V_183 -> V_199 )
return - V_262 ;
V_16 = 0 ;
F_109 (q, hctx, i) {
V_16 = F_261 ( V_2 -> V_26 , V_265 ) ;
if ( V_16 )
break;
}
if ( ! V_16 )
V_15 -> V_249 = V_265 ;
return V_16 ;
}
void F_262 ( void )
{
F_225 ( & V_253 ) ;
}
void F_263 ( void )
{
F_226 ( & V_253 ) ;
}
static int T_4 F_264 ( void )
{
F_265 () ;
F_266 ( F_253 , 0 ) ;
return 0 ;
}
