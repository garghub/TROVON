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
int V_16 ;
F_10 ( & V_15 -> V_17 , 1 , 1000000 ) ;
F_11 () ;
if ( ! F_12 ( V_15 ) &&
( ! F_13 ( V_15 ) || ! F_14 ( V_15 ) ) )
return 0 ;
F_10 ( & V_15 -> V_17 , - 1 , 1000000 ) ;
F_15 ( V_15 -> V_18 ) ;
V_16 = F_16 ( V_15 -> V_19 ,
! F_13 ( V_15 ) || F_12 ( V_15 ) ,
* V_15 -> V_18 ) ;
if ( ! V_16 && ! F_12 ( V_15 ) )
F_10 ( & V_15 -> V_17 , 1 , 1000000 ) ;
else if ( F_12 ( V_15 ) )
V_16 = - V_20 ;
F_17 ( V_15 -> V_18 ) ;
return V_16 ;
}
static void F_18 ( struct V_14 * V_15 )
{
F_10 ( & V_15 -> V_17 , - 1 , 1000000 ) ;
}
void F_19 ( struct V_14 * V_15 )
{
while ( true ) {
T_1 V_21 ;
F_15 ( V_15 -> V_18 ) ;
V_21 = F_20 ( & V_15 -> V_17 ) ;
F_17 ( V_15 -> V_18 ) ;
if ( V_21 == 0 )
break;
F_21 ( V_15 ) ;
F_22 ( 10 ) ;
}
}
static void F_23 ( struct V_14 * V_15 )
{
bool V_22 ;
F_15 ( V_15 -> V_18 ) ;
V_22 = ! V_15 -> V_23 ++ ;
F_24 ( V_24 , V_15 ) ;
F_17 ( V_15 -> V_18 ) ;
if ( V_22 )
F_19 ( V_15 ) ;
}
static void F_25 ( struct V_14 * V_15 )
{
bool V_25 = false ;
F_15 ( V_15 -> V_18 ) ;
if ( ! -- V_15 -> V_23 ) {
F_26 ( V_24 , V_15 ) ;
V_25 = true ;
}
F_27 ( V_15 -> V_23 < 0 ) ;
F_17 ( V_15 -> V_18 ) ;
if ( V_25 )
F_28 ( & V_15 -> V_19 ) ;
}
bool F_29 ( struct V_1 * V_2 )
{
return F_30 ( V_2 -> V_26 ) ;
}
static void F_31 ( struct V_14 * V_15 , struct V_9 * V_10 ,
struct V_27 * V_28 , unsigned int V_29 )
{
if ( F_32 ( V_15 ) )
V_29 |= V_30 ;
F_33 ( & V_28 -> V_31 ) ;
V_28 -> V_15 = V_15 ;
V_28 -> V_32 = V_10 ;
V_28 -> V_33 |= V_29 ;
V_28 -> V_34 = - 1 ;
F_34 ( & V_28 -> V_35 ) ;
F_35 ( & V_28 -> V_36 ) ;
V_28 -> V_37 = NULL ;
V_28 -> V_38 = NULL ;
V_28 -> V_39 = V_40 ;
#ifdef F_36
V_28 -> V_41 = NULL ;
F_37 ( V_28 ) ;
V_28 -> V_42 = 0 ;
#endif
V_28 -> V_43 = 0 ;
#if F_38 ( V_44 )
V_28 -> V_45 = 0 ;
#endif
V_28 -> V_46 = NULL ;
V_28 -> V_47 = 0 ;
V_28 -> V_48 = 0 ;
V_28 -> V_49 = 0 ;
V_28 -> V_50 = 0 ;
V_28 -> V_51 = NULL ;
F_33 ( & V_28 -> V_52 ) ;
V_28 -> V_53 = 0 ;
V_28 -> V_54 = NULL ;
V_28 -> V_55 = NULL ;
V_28 -> V_56 = NULL ;
V_10 -> V_57 [ F_39 ( V_29 ) ] ++ ;
}
static struct V_27 *
F_40 ( struct V_58 * V_59 , int V_60 )
{
struct V_27 * V_28 ;
unsigned int V_61 ;
V_61 = F_41 ( V_59 ) ;
if ( V_61 != V_62 ) {
V_28 = V_59 -> V_2 -> V_26 -> V_63 [ V_61 ] ;
V_28 -> V_33 = 0 ;
if ( F_42 ( V_59 -> V_2 ) ) {
V_28 -> V_33 = V_64 ;
F_43 ( & V_59 -> V_2 -> V_65 ) ;
}
V_28 -> V_61 = V_61 ;
F_31 ( V_59 -> V_15 , V_59 -> V_10 , V_28 , V_60 ) ;
return V_28 ;
}
return NULL ;
}
struct V_27 * F_44 ( struct V_14 * V_15 , int V_60 , T_2 V_66 ,
bool V_67 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
struct V_58 V_68 ;
if ( F_9 ( V_15 ) )
return NULL ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
F_46 ( & V_68 , V_15 , V_66 & ~ V_71 ,
V_67 , V_10 , V_2 ) ;
V_28 = F_40 ( & V_68 , V_60 ) ;
if ( ! V_28 && ( V_66 & V_71 ) ) {
F_47 ( V_2 ) ;
F_48 ( V_10 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
F_46 ( & V_68 , V_15 , V_66 , V_67 , V_10 ,
V_2 ) ;
V_28 = F_40 ( & V_68 , V_60 ) ;
V_10 = V_68 . V_10 ;
}
F_48 ( V_10 ) ;
return V_28 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_27 * V_28 )
{
const int V_61 = V_28 -> V_61 ;
struct V_14 * V_15 = V_28 -> V_15 ;
if ( V_28 -> V_33 & V_64 )
F_50 ( & V_2 -> V_65 ) ;
F_8 ( V_72 , & V_28 -> V_73 ) ;
F_51 ( V_2 , V_61 , & V_10 -> V_74 ) ;
F_18 ( V_15 ) ;
}
void F_52 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
struct V_1 * V_2 ;
struct V_14 * V_15 = V_28 -> V_15 ;
V_10 -> V_75 [ F_53 ( V_28 ) ] ++ ;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
F_49 ( V_2 , V_10 , V_28 ) ;
}
void F_54 ( struct V_27 * V_76 ,
struct V_27 * V_77 )
{
struct V_1 * V_2 =
V_77 -> V_15 -> V_69 -> V_70 ( V_77 -> V_15 , V_77 -> V_32 -> V_34 ) ;
V_76 -> V_32 = V_77 -> V_32 ;
V_76 -> V_61 = V_77 -> V_61 ;
memcpy ( F_55 ( V_76 ) , F_55 ( V_77 ) ,
V_2 -> V_78 ) ;
}
inline void F_56 ( struct V_27 * V_28 , int error )
{
F_57 ( V_28 ) ;
if ( V_28 -> V_54 ) {
V_28 -> V_54 ( V_28 , error ) ;
} else {
if ( F_58 ( F_59 ( V_28 ) ) )
F_52 ( V_28 -> V_56 ) ;
F_52 ( V_28 ) ;
}
}
void F_60 ( struct V_27 * V_28 , int error )
{
if ( F_61 ( V_28 , error , F_62 ( V_28 ) ) )
F_63 () ;
F_56 ( V_28 , error ) ;
}
static void F_64 ( void * V_59 )
{
struct V_27 * V_28 = V_59 ;
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
static void F_75 ( struct V_27 * V_28 , bool V_88 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_76 ( V_15 , V_28 ) ;
V_28 -> V_50 = F_62 ( V_28 ) ;
if ( F_58 ( F_59 ( V_28 ) ) )
V_28 -> V_56 -> V_50 = F_62 ( V_28 -> V_56 ) ;
F_77 ( V_28 ) ;
if ( ! F_4 ( V_72 , & V_28 -> V_73 ) )
F_6 ( V_72 , & V_28 -> V_73 ) ;
if ( F_4 ( V_89 , & V_28 -> V_73 ) )
F_8 ( V_89 , & V_28 -> V_73 ) ;
if ( V_15 -> V_90 && F_62 ( V_28 ) ) {
V_28 -> V_43 ++ ;
}
if ( V_88 )
V_28 -> V_33 |= V_91 ;
}
static void F_78 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
F_79 ( V_15 , V_28 ) ;
F_8 ( V_72 , & V_28 -> V_73 ) ;
V_28 -> V_33 &= ~ V_91 ;
if ( V_15 -> V_90 && F_62 ( V_28 ) )
V_28 -> V_43 -- ;
}
void F_80 ( struct V_27 * V_28 )
{
F_78 ( V_28 ) ;
F_81 ( V_28 ) ;
F_82 ( F_83 ( V_28 ) ) ;
F_84 ( V_28 , true ) ;
}
static void F_85 ( struct V_92 * V_93 )
{
struct V_14 * V_15 =
F_86 ( V_93 , struct V_14 , V_94 ) ;
F_87 ( V_95 ) ;
struct V_27 * V_28 , * V_96 ;
unsigned long V_87 ;
F_88 ( & V_15 -> V_97 , V_87 ) ;
F_89 ( & V_15 -> V_98 , & V_95 ) ;
F_90 ( & V_15 -> V_97 , V_87 ) ;
F_91 (rq, next, &rq_list, queuelist) {
if ( ! ( V_28 -> V_33 & V_99 ) )
continue;
V_28 -> V_33 &= ~ V_99 ;
F_92 ( & V_28 -> V_31 ) ;
F_93 ( V_28 , true , false , false ) ;
}
while ( ! F_94 ( & V_95 ) ) {
V_28 = F_95 ( V_95 . V_96 , struct V_27 , V_31 ) ;
F_92 ( & V_28 -> V_31 ) ;
F_93 ( V_28 , false , false , false ) ;
}
F_96 ( V_15 , false ) ;
}
void F_84 ( struct V_27 * V_28 , bool V_100 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
unsigned long V_87 ;
F_82 ( V_28 -> V_33 & V_99 ) ;
F_88 ( & V_15 -> V_97 , V_87 ) ;
if ( V_100 ) {
V_28 -> V_33 |= V_99 ;
F_97 ( & V_28 -> V_31 , & V_15 -> V_98 ) ;
} else {
F_98 ( & V_28 -> V_31 , & V_15 -> V_98 ) ;
}
F_90 ( & V_15 -> V_97 , V_87 ) ;
}
void F_99 ( struct V_14 * V_15 )
{
F_100 ( & V_15 -> V_94 ) ;
}
static inline bool F_101 ( struct V_27 * V_28 , unsigned int V_61 )
{
return ( ( V_28 -> V_33 & V_101 ) &&
V_28 -> V_15 -> V_76 -> V_61 == V_61 ) ;
}
struct V_27 * F_102 ( struct V_102 * V_26 , unsigned int V_61 )
{
struct V_27 * V_28 = V_26 -> V_63 [ V_61 ] ;
if ( ! F_101 ( V_28 , V_61 ) )
return V_28 ;
return V_28 -> V_15 -> V_76 ;
}
static void F_103 ( void * V_103 , unsigned long * V_104 )
{
struct V_105 * V_59 = V_103 ;
struct V_1 * V_2 = V_59 -> V_2 ;
unsigned int V_61 ;
V_61 = 0 ;
do {
struct V_27 * V_28 ;
V_61 = F_104 ( V_104 , V_2 -> V_26 -> V_106 , V_61 ) ;
if ( V_61 >= V_2 -> V_26 -> V_106 )
break;
V_28 = F_102 ( V_2 -> V_26 , V_61 ++ ) ;
if ( V_28 -> V_15 != V_2 -> V_107 )
continue;
if ( ! F_4 ( V_72 , & V_28 -> V_73 ) )
continue;
F_105 ( V_28 , V_59 -> V_96 , V_59 -> V_108 ) ;
} while ( 1 );
}
static void F_106 ( struct V_1 * V_2 ,
unsigned long * V_96 ,
unsigned int * V_108 )
{
struct V_105 V_59 = {
. V_2 = V_2 ,
. V_96 = V_96 ,
. V_108 = V_108 ,
} ;
F_107 ( V_2 -> V_26 , F_103 , & V_59 ) ;
}
static enum V_109 F_108 ( struct V_27 * V_28 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
if ( ! F_4 ( V_72 , & V_28 -> V_73 ) )
return V_110 ;
if ( ! V_15 -> V_69 -> V_53 )
return V_111 ;
return V_15 -> V_69 -> V_53 ( V_28 ) ;
}
static void F_109 ( unsigned long V_59 )
{
struct V_14 * V_15 = (struct V_14 * ) V_59 ;
struct V_1 * V_2 ;
unsigned long V_96 = 0 ;
int V_3 , V_108 = 0 ;
F_110 (q, hctx, i) {
if ( ! V_2 -> V_112 || ! V_2 -> V_26 )
continue;
F_106 ( V_2 , & V_96 , & V_108 ) ;
}
if ( V_108 ) {
V_96 = F_111 ( F_112 ( V_96 ) ) ;
F_113 ( & V_15 -> V_53 , V_96 ) ;
} else {
F_110 (q, hctx, i)
F_114 ( V_2 ) ;
}
}
static bool F_115 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_113 * V_113 )
{
struct V_27 * V_28 ;
int V_114 = 8 ;
F_116 (rq, &ctx->rq_list, queuelist) {
int V_115 ;
if ( ! V_114 -- )
break;
if ( ! F_117 ( V_28 , V_113 ) )
continue;
V_115 = F_118 ( V_28 , V_113 ) ;
if ( V_115 == V_116 ) {
if ( F_119 ( V_15 , V_28 , V_113 ) ) {
V_10 -> V_117 ++ ;
return true ;
}
break;
} else if ( V_115 == V_118 ) {
if ( F_120 ( V_15 , V_28 , V_113 ) ) {
V_10 -> V_117 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_121 ( struct V_1 * V_2 , struct V_119 * V_120 )
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
V_122 = F_122 ( & V_13 -> V_7 , V_13 -> V_123 , V_122 ) ;
if ( V_122 >= V_13 -> V_123 )
break;
V_10 = V_2 -> V_124 [ V_122 + V_121 ] ;
F_8 ( V_122 , & V_13 -> V_7 ) ;
F_123 ( & V_10 -> V_125 ) ;
F_124 ( & V_10 -> V_95 , V_120 ) ;
F_125 ( & V_10 -> V_125 ) ;
V_122 ++ ;
} while ( 1 );
}
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_107 ;
struct V_27 * V_28 ;
F_87 ( V_95 ) ;
int V_126 ;
F_126 ( ! F_127 ( F_128 () , V_2 -> V_127 ) ) ;
if ( F_58 ( F_4 ( V_128 , & V_2 -> V_129 ) ) )
return;
V_2 -> V_130 ++ ;
F_121 ( V_2 , & V_95 ) ;
if ( ! F_129 ( & V_2 -> V_131 ) ) {
F_123 ( & V_2 -> V_125 ) ;
if ( ! F_94 ( & V_2 -> V_131 ) )
F_89 ( & V_2 -> V_131 , & V_95 ) ;
F_125 ( & V_2 -> V_125 ) ;
}
V_126 = 0 ;
while ( ! F_94 ( & V_95 ) ) {
int V_16 ;
V_28 = F_130 ( & V_95 , struct V_27 , V_31 ) ;
F_92 ( & V_28 -> V_31 ) ;
F_75 ( V_28 , F_94 ( & V_95 ) ) ;
V_16 = V_15 -> V_69 -> V_132 ( V_2 , V_28 ) ;
switch ( V_16 ) {
case V_133 :
V_126 ++ ;
continue;
case V_134 :
F_97 ( & V_28 -> V_31 , & V_95 ) ;
F_78 ( V_28 ) ;
break;
default:
F_131 ( L_1 , V_16 ) ;
case V_135 :
V_28 -> V_47 = - V_136 ;
F_60 ( V_28 , V_28 -> V_47 ) ;
break;
}
if ( V_16 == V_134 )
break;
}
if ( ! V_126 )
V_2 -> V_137 [ 0 ] ++ ;
else if ( V_126 < ( 1 << ( V_138 - 1 ) ) )
V_2 -> V_137 [ F_132 ( V_126 ) + 1 ] ++ ;
if ( ! F_94 ( & V_95 ) ) {
F_123 ( & V_2 -> V_125 ) ;
F_133 ( & V_95 , & V_2 -> V_131 ) ;
F_125 ( & V_2 -> V_125 ) ;
}
}
static int F_134 ( struct V_1 * V_2 )
{
int V_34 = V_2 -> V_139 ;
if ( -- V_2 -> V_140 <= 0 ) {
int V_139 ;
V_139 = F_135 ( V_2 -> V_139 , V_2 -> V_127 ) ;
if ( V_139 >= V_141 )
V_139 = F_136 ( V_2 -> V_127 ) ;
V_2 -> V_139 = V_139 ;
V_2 -> V_140 = V_142 ;
}
return V_34 ;
}
void F_137 ( struct V_1 * V_2 , bool V_143 )
{
if ( F_58 ( F_4 ( V_128 , & V_2 -> V_129 ) ) )
return;
if ( ! V_143 && F_127 ( F_138 () , V_2 -> V_127 ) )
F_47 ( V_2 ) ;
else if ( V_2 -> V_107 -> V_144 == 1 )
F_139 ( & V_2 -> V_145 , 0 ) ;
else {
unsigned int V_34 ;
V_34 = F_134 ( V_2 ) ;
F_140 ( V_34 , & V_2 -> V_145 , 0 ) ;
}
}
void F_96 ( struct V_14 * V_15 , bool V_143 )
{
struct V_1 * V_2 ;
int V_3 ;
F_110 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_129 ( & V_2 -> V_131 ) ) ||
F_4 ( V_128 , & V_2 -> V_129 ) )
continue;
F_141 () ;
F_137 ( V_2 , V_143 ) ;
F_142 () ;
}
}
void F_143 ( struct V_1 * V_2 )
{
F_144 ( & V_2 -> V_145 ) ;
F_144 ( & V_2 -> V_146 ) ;
F_6 ( V_128 , & V_2 -> V_129 ) ;
}
void F_145 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_110 (q, hctx, i)
F_143 ( V_2 ) ;
}
void F_146 ( struct V_1 * V_2 )
{
F_8 ( V_128 , & V_2 -> V_129 ) ;
F_141 () ;
F_137 ( V_2 , false ) ;
F_142 () ;
}
void F_21 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_110 (q, hctx, i)
F_146 ( V_2 ) ;
}
void F_147 ( struct V_14 * V_15 , bool V_143 )
{
struct V_1 * V_2 ;
int V_3 ;
F_110 (q, hctx, i) {
if ( ! F_4 ( V_128 , & V_2 -> V_129 ) )
continue;
F_8 ( V_128 , & V_2 -> V_129 ) ;
F_141 () ;
F_137 ( V_2 , V_143 ) ;
F_142 () ;
}
}
static void F_148 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
V_2 = F_86 ( V_93 , struct V_1 , V_145 . V_93 ) ;
F_47 ( V_2 ) ;
}
static void F_149 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
V_2 = F_86 ( V_93 , struct V_1 , V_146 . V_93 ) ;
if ( F_150 ( V_128 , & V_2 -> V_129 ) )
F_47 ( V_2 ) ;
}
void F_151 ( struct V_1 * V_2 , unsigned long V_147 )
{
unsigned long V_148 = F_152 ( V_147 ) ;
if ( V_2 -> V_107 -> V_144 == 1 )
F_139 ( & V_2 -> V_146 , V_148 ) ;
else {
unsigned int V_34 ;
V_34 = F_134 ( V_2 ) ;
F_140 ( V_34 , & V_2 -> V_146 , V_148 ) ;
}
}
static void F_153 ( struct V_1 * V_2 ,
struct V_27 * V_28 , bool V_100 )
{
struct V_9 * V_10 = V_28 -> V_32 ;
F_154 ( V_2 -> V_107 , V_28 ) ;
if ( V_100 )
F_97 ( & V_28 -> V_31 , & V_10 -> V_95 ) ;
else
F_98 ( & V_28 -> V_31 , & V_10 -> V_95 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_93 ( struct V_27 * V_28 , bool V_100 , bool V_149 ,
bool V_143 )
{
struct V_14 * V_15 = V_28 -> V_15 ;
struct V_1 * V_2 ;
struct V_9 * V_10 = V_28 -> V_32 , * V_150 ;
V_150 = F_45 ( V_15 ) ;
if ( ! F_68 ( V_10 -> V_34 ) )
V_28 -> V_32 = V_10 = V_150 ;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
if ( V_28 -> V_33 & ( V_151 | V_152 ) &&
! ( V_28 -> V_33 & ( V_101 ) ) ) {
F_155 ( V_28 ) ;
} else {
F_123 ( & V_10 -> V_125 ) ;
F_153 ( V_2 , V_28 , V_100 ) ;
F_125 ( & V_10 -> V_125 ) ;
}
if ( V_149 )
F_137 ( V_2 , V_143 ) ;
F_48 ( V_150 ) ;
}
static void F_156 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_119 * V_120 ,
int V_123 ,
bool V_153 )
{
struct V_1 * V_2 ;
struct V_9 * V_150 ;
F_157 ( V_15 , V_123 , ! V_153 ) ;
V_150 = F_45 ( V_15 ) ;
if ( ! F_68 ( V_10 -> V_34 ) )
V_10 = V_150 ;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
F_123 ( & V_10 -> V_125 ) ;
while ( ! F_94 ( V_120 ) ) {
struct V_27 * V_28 ;
V_28 = F_130 ( V_120 , struct V_27 , V_31 ) ;
F_92 ( & V_28 -> V_31 ) ;
V_28 -> V_32 = V_10 ;
F_153 ( V_2 , V_28 , false ) ;
}
F_125 ( & V_10 -> V_125 ) ;
F_137 ( V_2 , V_153 ) ;
F_48 ( V_150 ) ;
}
static int F_158 ( void * V_154 , struct V_119 * V_155 , struct V_119 * V_156 )
{
struct V_27 * V_157 = F_86 ( V_155 , struct V_27 , V_31 ) ;
struct V_27 * V_158 = F_86 ( V_156 , struct V_27 , V_31 ) ;
return ! ( V_157 -> V_32 < V_158 -> V_32 ||
( V_157 -> V_32 == V_158 -> V_32 &&
F_159 ( V_157 ) < F_159 ( V_158 ) ) ) ;
}
void F_160 ( struct V_159 * V_160 , bool V_153 )
{
struct V_9 * V_161 ;
struct V_14 * V_162 ;
struct V_27 * V_28 ;
F_87 ( V_120 ) ;
F_87 ( V_163 ) ;
unsigned int V_123 ;
F_89 ( & V_160 -> V_164 , & V_120 ) ;
F_161 ( NULL , & V_120 , F_158 ) ;
V_162 = NULL ;
V_161 = NULL ;
V_123 = 0 ;
while ( ! F_94 ( & V_120 ) ) {
V_28 = F_162 ( V_120 . V_96 ) ;
F_92 ( & V_28 -> V_31 ) ;
F_82 ( ! V_28 -> V_15 ) ;
if ( V_28 -> V_32 != V_161 ) {
if ( V_161 ) {
F_156 ( V_162 , V_161 ,
& V_163 , V_123 ,
V_153 ) ;
}
V_161 = V_28 -> V_32 ;
V_162 = V_28 -> V_15 ;
V_123 = 0 ;
}
V_123 ++ ;
F_98 ( & V_28 -> V_31 , & V_163 ) ;
}
if ( V_161 ) {
F_156 ( V_162 , V_161 , & V_163 , V_123 ,
V_153 ) ;
}
}
static void F_163 ( struct V_27 * V_28 , struct V_113 * V_113 )
{
F_164 ( V_28 , V_113 ) ;
if ( F_165 ( V_28 ) )
F_166 ( V_28 , 1 ) ;
}
static inline bool F_167 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_27 * V_28 , struct V_113 * V_113 )
{
struct V_14 * V_15 = V_2 -> V_107 ;
if ( ! ( V_2 -> V_87 & V_165 ) ) {
F_163 ( V_28 , V_113 ) ;
F_123 ( & V_10 -> V_125 ) ;
V_166:
F_153 ( V_2 , V_28 , false ) ;
F_125 ( & V_10 -> V_125 ) ;
return false ;
} else {
F_123 ( & V_10 -> V_125 ) ;
if ( ! F_115 ( V_15 , V_10 , V_113 ) ) {
F_163 ( V_28 , V_113 ) ;
goto V_166;
}
F_125 ( & V_10 -> V_125 ) ;
F_49 ( V_2 , V_10 , V_28 ) ;
return true ;
}
}
static struct V_27 * F_168 ( struct V_14 * V_15 ,
struct V_113 * V_113 ,
struct V_167 * V_59 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_27 * V_28 ;
int V_60 = F_169 ( V_113 ) ;
struct V_58 V_68 ;
if ( F_58 ( F_9 ( V_15 ) ) ) {
F_170 ( V_113 , - V_136 ) ;
return NULL ;
}
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
if ( F_39 ( V_113 -> V_168 ) )
V_60 |= V_169 ;
F_171 ( V_15 , V_113 , V_60 ) ;
F_46 ( & V_68 , V_15 , V_170 , false , V_10 ,
V_2 ) ;
V_28 = F_40 ( & V_68 , V_60 ) ;
if ( F_58 ( ! V_28 ) ) {
F_47 ( V_2 ) ;
F_48 ( V_10 ) ;
F_172 ( V_15 , V_113 , V_60 ) ;
V_10 = F_45 ( V_15 ) ;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
F_46 ( & V_68 , V_15 ,
V_71 | V_170 , false , V_10 , V_2 ) ;
V_28 = F_40 ( & V_68 , V_60 ) ;
V_10 = V_68 . V_10 ;
V_2 = V_68 . V_2 ;
}
V_2 -> V_126 ++ ;
V_59 -> V_2 = V_2 ;
V_59 -> V_10 = V_10 ;
return V_28 ;
}
static void F_173 ( struct V_14 * V_15 , struct V_113 * V_113 )
{
const int V_171 = F_39 ( V_113 -> V_168 ) ;
const int V_172 = V_113 -> V_168 & ( V_151 | V_152 ) ;
struct V_167 V_59 ;
struct V_27 * V_28 ;
F_174 ( V_15 , & V_113 ) ;
if ( F_175 ( V_113 ) && F_176 ( V_113 ) ) {
F_170 ( V_113 , - V_136 ) ;
return;
}
V_28 = F_168 ( V_15 , V_113 , & V_59 ) ;
if ( F_58 ( ! V_28 ) )
return;
if ( F_58 ( V_172 ) ) {
F_163 ( V_28 , V_113 ) ;
F_155 ( V_28 ) ;
goto V_149;
}
if ( V_171 ) {
int V_16 ;
F_163 ( V_28 , V_113 ) ;
F_75 ( V_28 , true ) ;
V_16 = V_15 -> V_69 -> V_132 ( V_59 . V_2 , V_28 ) ;
if ( V_16 == V_133 )
goto V_173;
else {
F_78 ( V_28 ) ;
if ( V_16 == V_135 ) {
V_28 -> V_47 = - V_136 ;
F_60 ( V_28 , V_28 -> V_47 ) ;
goto V_173;
}
}
}
if ( ! F_167 ( V_59 . V_2 , V_59 . V_10 , V_28 , V_113 ) ) {
V_149:
F_137 ( V_59 . V_2 , ! V_171 || V_172 ) ;
}
V_173:
F_48 ( V_59 . V_10 ) ;
}
static void F_177 ( struct V_14 * V_15 , struct V_113 * V_113 )
{
const int V_171 = F_39 ( V_113 -> V_168 ) ;
const int V_172 = V_113 -> V_168 & ( V_151 | V_152 ) ;
unsigned int V_174 , V_175 = 0 ;
struct V_167 V_59 ;
struct V_27 * V_28 ;
V_174 = ! V_172 && ! V_171 ;
F_174 ( V_15 , & V_113 ) ;
if ( F_175 ( V_113 ) && F_176 ( V_113 ) ) {
F_170 ( V_113 , - V_136 ) ;
return;
}
if ( V_174 && ! F_178 ( V_15 ) &&
F_179 ( V_15 , V_113 , & V_175 ) )
return;
V_28 = F_168 ( V_15 , V_113 , & V_59 ) ;
if ( F_58 ( ! V_28 ) )
return;
if ( F_58 ( V_172 ) ) {
F_163 ( V_28 , V_113 ) ;
F_155 ( V_28 ) ;
goto V_149;
}
if ( V_174 ) {
struct V_159 * V_160 = V_176 -> V_160 ;
if ( V_160 ) {
F_163 ( V_28 , V_113 ) ;
if ( F_94 ( & V_160 -> V_164 ) )
F_180 ( V_15 ) ;
else if ( V_175 >= V_177 ) {
F_181 ( V_160 , false ) ;
F_180 ( V_15 ) ;
}
F_98 ( & V_28 -> V_31 , & V_160 -> V_164 ) ;
F_48 ( V_59 . V_10 ) ;
return;
}
}
if ( ! F_167 ( V_59 . V_2 , V_59 . V_10 , V_28 , V_113 ) ) {
V_149:
F_137 ( V_59 . V_2 , ! V_171 || V_172 ) ;
}
F_48 ( V_59 . V_10 ) ;
}
struct V_1 * F_182 ( struct V_14 * V_15 , const int V_34 )
{
return V_15 -> V_178 [ V_15 -> V_179 [ V_34 ] ] ;
}
static void F_183 ( struct V_180 * V_181 ,
struct V_102 * V_26 , unsigned int V_182 )
{
struct V_183 * V_183 ;
if ( V_26 -> V_63 && V_181 -> V_184 -> V_185 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_106 ; V_3 ++ ) {
if ( ! V_26 -> V_63 [ V_3 ] )
continue;
V_181 -> V_184 -> V_185 ( V_181 -> V_186 , V_26 -> V_63 [ V_3 ] ,
V_182 , V_3 ) ;
}
}
while ( ! F_94 ( & V_26 -> V_187 ) ) {
V_183 = F_130 ( & V_26 -> V_187 , struct V_183 , V_188 ) ;
F_92 ( & V_183 -> V_188 ) ;
F_184 ( V_183 , V_183 -> V_189 ) ;
}
F_185 ( V_26 -> V_63 ) ;
F_186 ( V_26 ) ;
}
static T_3 F_187 ( unsigned int V_190 )
{
return ( T_3 ) V_191 << V_190 ;
}
static struct V_102 * F_188 ( struct V_180 * V_181 ,
unsigned int V_182 )
{
struct V_102 * V_26 ;
unsigned int V_3 , V_192 , V_193 , V_194 = 4 ;
T_3 V_195 , V_196 ;
V_26 = F_189 ( V_181 -> V_197 , V_181 -> V_198 ,
V_181 -> V_199 ) ;
if ( ! V_26 )
return NULL ;
F_33 ( & V_26 -> V_187 ) ;
V_26 -> V_63 = F_190 ( V_181 -> V_197 * sizeof( struct V_27 * ) ,
V_200 , V_181 -> V_199 ) ;
if ( ! V_26 -> V_63 ) {
F_186 ( V_26 ) ;
return NULL ;
}
V_195 = F_191 ( sizeof( struct V_27 ) + V_181 -> V_78 ,
F_192 () ) ;
V_196 = V_195 * V_181 -> V_197 ;
for ( V_3 = 0 ; V_3 < V_181 -> V_197 ; ) {
int V_201 = V_194 ;
struct V_183 * V_183 ;
int V_202 ;
void * V_203 ;
while ( V_196 < F_187 ( V_201 - 1 ) && V_201 )
V_201 -- ;
do {
V_183 = F_193 ( V_181 -> V_199 , V_200 ,
V_201 ) ;
if ( V_183 )
break;
if ( ! V_201 -- )
break;
if ( F_187 ( V_201 ) < V_195 )
break;
} while ( 1 );
if ( ! V_183 )
goto V_204;
V_183 -> V_189 = V_201 ;
F_98 ( & V_183 -> V_188 , & V_26 -> V_187 ) ;
V_203 = F_194 ( V_183 ) ;
V_193 = F_187 ( V_201 ) / V_195 ;
V_202 = F_195 ( V_193 , V_181 -> V_197 - V_3 ) ;
V_196 -= V_202 * V_195 ;
for ( V_192 = 0 ; V_192 < V_202 ; V_192 ++ ) {
V_26 -> V_63 [ V_3 ] = V_203 ;
if ( V_181 -> V_184 -> V_205 ) {
if ( V_181 -> V_184 -> V_205 ( V_181 -> V_186 ,
V_26 -> V_63 [ V_3 ] , V_182 , V_3 ,
V_181 -> V_199 ) )
goto V_204;
}
V_203 += V_195 ;
V_3 ++ ;
}
}
return V_26 ;
V_204:
F_196 ( L_2 , V_206 ) ;
F_183 ( V_181 , V_26 , V_182 ) ;
return NULL ;
}
static void F_197 ( struct V_207 * V_208 )
{
F_185 ( V_208 -> V_6 ) ;
}
static int F_198 ( struct V_207 * V_208 , int V_209 )
{
unsigned int V_210 = 8 , V_211 , V_212 , V_3 ;
V_208 -> V_12 = V_210 ;
V_212 = F_199 ( V_141 , V_210 ) / V_210 ;
V_208 -> V_6 = F_200 ( V_212 * sizeof( struct V_8 ) ,
V_200 , V_209 ) ;
if ( ! V_208 -> V_6 )
return - V_213 ;
V_208 -> V_5 = V_212 ;
V_211 = V_141 ;
for ( V_3 = 0 ; V_3 < V_212 ; V_3 ++ ) {
V_208 -> V_6 [ V_3 ] . V_123 = F_195 ( V_211 , V_208 -> V_12 ) ;
V_211 -= V_208 -> V_6 [ V_3 ] . V_123 ;
}
return 0 ;
}
static int F_201 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_107 ;
struct V_9 * V_10 ;
F_87 ( V_214 ) ;
V_10 = F_202 ( V_15 , V_34 ) ;
F_123 ( & V_10 -> V_125 ) ;
if ( ! F_94 ( & V_10 -> V_95 ) ) {
F_89 ( & V_10 -> V_95 , & V_214 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_125 ( & V_10 -> V_125 ) ;
if ( F_94 ( & V_214 ) )
return V_215 ;
V_10 = F_45 ( V_15 ) ;
F_123 ( & V_10 -> V_125 ) ;
while ( ! F_94 ( & V_214 ) ) {
struct V_27 * V_28 ;
V_28 = F_130 ( & V_214 , struct V_27 , V_31 ) ;
V_28 -> V_32 = V_10 ;
F_203 ( & V_28 -> V_31 , & V_10 -> V_95 ) ;
}
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_10 -> V_34 ) ;
F_3 ( V_2 , V_10 ) ;
F_125 ( & V_10 -> V_125 ) ;
F_137 ( V_2 , true ) ;
F_48 ( V_10 ) ;
return V_215 ;
}
static int F_204 ( struct V_1 * V_2 , int V_34 )
{
struct V_14 * V_15 = V_2 -> V_107 ;
struct V_180 * V_181 = V_15 -> V_216 ;
if ( V_181 -> V_26 [ V_2 -> V_217 ] )
return V_215 ;
V_181 -> V_26 [ V_2 -> V_217 ] = F_188 ( V_181 , V_2 -> V_217 ) ;
if ( ! V_181 -> V_26 [ V_2 -> V_217 ] )
return V_218 ;
V_2 -> V_26 = V_181 -> V_26 [ V_2 -> V_217 ] ;
return V_215 ;
}
static int F_205 ( void * V_59 , unsigned long V_219 ,
unsigned int V_34 )
{
struct V_1 * V_2 = V_59 ;
if ( V_219 == V_220 || V_219 == V_221 )
return F_201 ( V_2 , V_34 ) ;
else if ( V_219 == V_222 || V_219 == V_223 )
return F_204 ( V_2 , V_34 ) ;
return V_215 ;
}
static void F_206 ( struct V_14 * V_15 ,
struct V_180 * V_181 , int V_224 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_110 (q, hctx, i) {
if ( V_3 == V_224 )
break;
F_114 ( V_2 ) ;
if ( V_181 -> V_184 -> V_225 )
V_181 -> V_184 -> V_225 ( V_2 , V_3 ) ;
F_207 ( & V_2 -> V_226 ) ;
F_185 ( V_2 -> V_124 ) ;
F_197 ( & V_2 -> V_4 ) ;
}
}
static void F_208 ( struct V_14 * V_15 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_110 (q, hctx, i) {
F_209 ( V_2 -> V_127 ) ;
F_185 ( V_2 ) ;
}
}
static int F_210 ( struct V_14 * V_15 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_110 (q, hctx, i) {
int V_209 ;
V_209 = V_2 -> V_199 ;
if ( V_209 == V_227 )
V_209 = V_2 -> V_199 = V_181 -> V_199 ;
F_211 ( & V_2 -> V_145 , F_148 ) ;
F_211 ( & V_2 -> V_146 , F_149 ) ;
F_212 ( & V_2 -> V_125 ) ;
F_33 ( & V_2 -> V_131 ) ;
V_2 -> V_107 = V_15 ;
V_2 -> V_217 = V_3 ;
V_2 -> V_87 = V_181 -> V_87 ;
V_2 -> V_78 = V_181 -> V_78 ;
F_213 ( & V_2 -> V_226 ,
F_205 , V_2 ) ;
F_214 ( & V_2 -> V_226 ) ;
V_2 -> V_26 = V_181 -> V_26 [ V_3 ] ;
V_2 -> V_124 = F_190 ( V_141 * sizeof( void * ) ,
V_200 , V_209 ) ;
if ( ! V_2 -> V_124 )
break;
if ( F_198 ( & V_2 -> V_4 , V_209 ) )
break;
V_2 -> V_112 = 0 ;
if ( V_181 -> V_184 -> V_228 &&
V_181 -> V_184 -> V_228 ( V_2 , V_181 -> V_186 , V_3 ) )
break;
}
if ( V_3 == V_15 -> V_144 )
return 0 ;
F_206 ( V_15 , V_181 , V_3 ) ;
return 1 ;
}
static void F_215 ( struct V_14 * V_15 ,
unsigned int V_144 )
{
unsigned int V_3 ;
F_216 (i) {
struct V_9 * V_229 = F_217 ( V_15 -> V_230 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
V_229 -> V_34 = V_3 ;
F_212 ( & V_229 -> V_125 ) ;
F_33 ( & V_229 -> V_95 ) ;
V_229 -> V_107 = V_15 ;
if ( ! F_68 ( V_3 ) )
continue;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_3 ) ;
F_218 ( V_3 , V_2 -> V_127 ) ;
V_2 -> V_112 ++ ;
if ( V_144 > 1 && V_2 -> V_199 == V_227 )
V_2 -> V_199 = F_219 ( V_3 ) ;
}
}
static void F_220 ( struct V_14 * V_15 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
F_110 (q, hctx, i) {
F_221 ( V_2 -> V_127 ) ;
V_2 -> V_112 = 0 ;
}
F_222 (q, ctx, i) {
if ( ! F_68 ( V_3 ) )
continue;
V_2 = V_15 -> V_69 -> V_70 ( V_15 , V_3 ) ;
F_218 ( V_3 , V_2 -> V_127 ) ;
V_10 -> V_11 = V_2 -> V_112 ;
V_2 -> V_124 [ V_2 -> V_112 ++ ] = V_10 ;
}
F_110 (q, hctx, i) {
if ( ! V_2 -> V_112 ) {
struct V_180 * V_181 = V_15 -> V_216 ;
if ( V_181 -> V_26 [ V_3 ] ) {
F_183 ( V_181 , V_181 -> V_26 [ V_3 ] , V_3 ) ;
V_181 -> V_26 [ V_3 ] = NULL ;
V_2 -> V_26 = NULL ;
}
continue;
}
V_2 -> V_139 = F_136 ( V_2 -> V_127 ) ;
V_2 -> V_140 = V_142 ;
}
}
static void F_223 ( struct V_180 * V_181 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
bool V_80 ;
int V_3 ;
if ( V_181 -> V_231 . V_96 == V_181 -> V_231 . V_232 )
V_80 = false ;
else
V_80 = true ;
F_224 (q, &set->tag_list, tag_set_list) {
F_23 ( V_15 ) ;
F_110 (q, hctx, i) {
if ( V_80 )
V_2 -> V_87 |= V_233 ;
else
V_2 -> V_87 &= ~ V_233 ;
}
F_25 ( V_15 ) ;
}
}
static void F_225 ( struct V_14 * V_15 )
{
struct V_180 * V_181 = V_15 -> V_216 ;
F_23 ( V_15 ) ;
F_226 ( & V_181 -> V_234 ) ;
F_92 ( & V_15 -> V_235 ) ;
F_223 ( V_181 ) ;
F_227 ( & V_181 -> V_234 ) ;
F_25 ( V_15 ) ;
}
static void F_228 ( struct V_180 * V_181 ,
struct V_14 * V_15 )
{
V_15 -> V_216 = V_181 ;
F_226 ( & V_181 -> V_234 ) ;
F_98 ( & V_15 -> V_235 , & V_181 -> V_231 ) ;
F_223 ( V_181 ) ;
F_227 ( & V_181 -> V_234 ) ;
}
struct V_14 * F_229 ( struct V_180 * V_181 )
{
struct V_1 * * V_236 ;
struct V_9 T_4 * V_10 ;
struct V_14 * V_15 ;
unsigned int * V_6 ;
int V_3 ;
V_10 = F_230 ( struct V_9 ) ;
if ( ! V_10 )
return F_231 ( - V_213 ) ;
V_236 = F_190 ( V_181 -> V_144 * sizeof( * V_236 ) , V_200 ,
V_181 -> V_199 ) ;
if ( ! V_236 )
goto V_237;
V_6 = F_232 ( V_181 ) ;
if ( ! V_6 )
goto V_238;
for ( V_3 = 0 ; V_3 < V_181 -> V_144 ; V_3 ++ ) {
int V_209 = F_233 ( V_6 , V_3 ) ;
V_236 [ V_3 ] = F_200 ( sizeof( struct V_1 ) ,
V_200 , V_209 ) ;
if ( ! V_236 [ V_3 ] )
goto V_239;
if ( ! F_234 ( & V_236 [ V_3 ] -> V_127 , V_200 ) )
goto V_239;
F_235 ( & V_236 [ V_3 ] -> V_65 , 0 ) ;
V_236 [ V_3 ] -> V_199 = V_209 ;
V_236 [ V_3 ] -> V_217 = V_3 ;
}
V_15 = F_236 ( V_200 , V_181 -> V_199 ) ;
if ( ! V_15 )
goto V_239;
if ( F_237 ( & V_15 -> V_17 , 0 ) )
goto V_238;
F_238 ( & V_15 -> V_53 , F_109 , ( unsigned long ) V_15 ) ;
F_239 ( V_15 , 30000 ) ;
V_15 -> V_240 = V_141 ;
V_15 -> V_144 = V_181 -> V_144 ;
V_15 -> V_179 = V_6 ;
V_15 -> V_230 = V_10 ;
V_15 -> V_178 = V_236 ;
V_15 -> V_69 = V_181 -> V_184 ;
V_15 -> V_82 |= V_241 ;
if ( ! ( V_181 -> V_87 & V_242 ) )
V_15 -> V_82 |= 1 << V_243 ;
V_15 -> V_244 = V_245 ;
F_240 ( & V_15 -> V_94 , F_85 ) ;
F_33 ( & V_15 -> V_98 ) ;
F_212 ( & V_15 -> V_97 ) ;
if ( V_15 -> V_144 > 1 )
F_241 ( V_15 , F_173 ) ;
else
F_241 ( V_15 , F_177 ) ;
F_242 ( V_15 , F_108 ) ;
if ( V_181 -> V_53 )
F_239 ( V_15 , V_181 -> V_53 ) ;
V_15 -> V_246 = V_181 -> V_197 ;
if ( V_181 -> V_184 -> V_247 )
F_243 ( V_15 , V_181 -> V_184 -> V_247 ) ;
F_244 ( V_15 ) ;
F_215 ( V_15 , V_181 -> V_144 ) ;
V_15 -> V_76 = F_245 ( F_191 ( sizeof( struct V_27 ) +
V_181 -> V_78 , F_192 () ) ,
V_200 ) ;
if ( ! V_15 -> V_76 )
goto V_248;
if ( F_210 ( V_15 , V_181 ) )
goto V_249;
F_226 ( & V_250 ) ;
F_98 ( & V_15 -> V_251 , & V_252 ) ;
F_227 ( & V_250 ) ;
F_228 ( V_181 , V_15 ) ;
F_220 ( V_15 ) ;
return V_15 ;
V_249:
F_185 ( V_15 -> V_76 ) ;
V_248:
F_246 ( V_15 ) ;
V_239:
F_185 ( V_6 ) ;
for ( V_3 = 0 ; V_3 < V_181 -> V_144 ; V_3 ++ ) {
if ( ! V_236 [ V_3 ] )
break;
F_209 ( V_236 [ V_3 ] -> V_127 ) ;
F_185 ( V_236 [ V_3 ] ) ;
}
V_238:
F_185 ( V_236 ) ;
V_237:
F_247 ( V_10 ) ;
return F_231 ( - V_213 ) ;
}
void F_248 ( struct V_14 * V_15 )
{
struct V_180 * V_181 = V_15 -> V_216 ;
F_225 ( V_15 ) ;
F_206 ( V_15 , V_181 , V_181 -> V_144 ) ;
F_208 ( V_15 , V_181 ) ;
F_249 ( & V_15 -> V_17 ) ;
F_247 ( V_15 -> V_230 ) ;
F_185 ( V_15 -> V_178 ) ;
F_185 ( V_15 -> V_179 ) ;
V_15 -> V_230 = NULL ;
V_15 -> V_178 = NULL ;
V_15 -> V_179 = NULL ;
F_226 ( & V_250 ) ;
F_92 ( & V_15 -> V_251 ) ;
F_227 ( & V_250 ) ;
}
static void F_250 ( struct V_14 * V_15 )
{
F_23 ( V_15 ) ;
F_251 ( V_15 ) ;
F_252 ( V_15 -> V_179 , V_15 -> V_144 ) ;
F_220 ( V_15 ) ;
F_253 ( V_15 ) ;
F_25 ( V_15 ) ;
}
static int F_254 ( struct V_253 * V_254 ,
unsigned long V_219 , void * V_255 )
{
struct V_14 * V_15 ;
if ( V_219 != V_220 && V_219 != V_221 &&
V_219 != V_222 && V_219 != V_223 )
return V_215 ;
F_226 ( & V_250 ) ;
F_224 (q, &all_q_list, all_q_node)
F_250 ( V_15 ) ;
F_227 ( & V_250 ) ;
return V_215 ;
}
int F_255 ( struct V_180 * V_181 )
{
int V_3 ;
if ( ! V_181 -> V_144 )
return - V_256 ;
if ( ! V_181 -> V_197 )
return - V_256 ;
if ( V_181 -> V_197 < V_181 -> V_198 + V_257 )
return - V_256 ;
if ( ! V_181 -> V_144 || ! V_181 -> V_184 -> V_132 || ! V_181 -> V_184 -> V_70 )
return - V_256 ;
if ( V_181 -> V_197 > V_258 ) {
F_256 ( L_3 ,
V_258 ) ;
V_181 -> V_197 = V_258 ;
}
V_181 -> V_26 = F_190 ( V_181 -> V_144 *
sizeof( struct V_102 * ) ,
V_200 , V_181 -> V_199 ) ;
if ( ! V_181 -> V_26 )
goto V_259;
for ( V_3 = 0 ; V_3 < V_181 -> V_144 ; V_3 ++ ) {
V_181 -> V_26 [ V_3 ] = F_188 ( V_181 , V_3 ) ;
if ( ! V_181 -> V_26 [ V_3 ] )
goto V_260;
}
F_257 ( & V_181 -> V_234 ) ;
F_33 ( & V_181 -> V_231 ) ;
return 0 ;
V_260:
while ( -- V_3 >= 0 )
F_183 ( V_181 , V_181 -> V_26 [ V_3 ] , V_3 ) ;
V_259:
return - V_213 ;
}
void F_258 ( struct V_180 * V_181 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_181 -> V_144 ; V_3 ++ ) {
if ( V_181 -> V_26 [ V_3 ] )
F_183 ( V_181 , V_181 -> V_26 [ V_3 ] , V_3 ) ;
}
F_185 ( V_181 -> V_26 ) ;
}
int F_259 ( struct V_14 * V_15 , unsigned int V_261 )
{
struct V_180 * V_181 = V_15 -> V_216 ;
struct V_1 * V_2 ;
int V_3 , V_16 ;
if ( ! V_181 || V_261 > V_181 -> V_197 )
return - V_256 ;
V_16 = 0 ;
F_110 (q, hctx, i) {
V_16 = F_260 ( V_2 -> V_26 , V_261 ) ;
if ( V_16 )
break;
}
if ( ! V_16 )
V_15 -> V_246 = V_261 ;
return V_16 ;
}
void F_261 ( void )
{
F_226 ( & V_250 ) ;
}
void F_262 ( void )
{
F_227 ( & V_250 ) ;
}
static int T_5 F_263 ( void )
{
F_264 () ;
F_265 ( F_254 , - 10 ) ;
return 0 ;
}
