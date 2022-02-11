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
struct V_21 * V_22 , int V_23 ,
unsigned int V_24 )
{
if ( F_30 ( V_15 ) )
V_24 |= V_25 ;
F_31 ( & V_22 -> V_26 ) ;
V_22 -> V_15 = V_15 ;
V_22 -> V_27 = V_10 ;
F_32 ( V_22 , V_23 , V_24 ) ;
V_22 -> V_28 = - 1 ;
F_33 ( & V_22 -> V_29 ) ;
F_34 ( & V_22 -> V_30 ) ;
V_22 -> V_31 = NULL ;
V_22 -> V_32 = NULL ;
V_22 -> V_33 = V_34 ;
#ifdef F_35
V_22 -> V_35 = NULL ;
F_36 ( V_22 ) ;
V_22 -> V_36 = 0 ;
#endif
V_22 -> V_37 = 0 ;
#if F_37 ( V_38 )
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
V_10 -> V_53 [ F_38 ( V_23 , V_24 ) ] ++ ;
}
static struct V_21 *
F_39 ( struct V_54 * V_55 , int V_23 , int V_24 )
{
struct V_21 * V_22 ;
unsigned int V_56 ;
V_56 = F_40 ( V_55 ) ;
if ( V_56 != V_57 ) {
V_22 = V_55 -> V_2 -> V_20 -> V_58 [ V_56 ] ;
if ( F_41 ( V_55 -> V_2 ) ) {
V_22 -> V_59 = V_60 ;
F_42 ( & V_55 -> V_2 -> V_61 ) ;
}
V_22 -> V_56 = V_56 ;
F_29 ( V_55 -> V_15 , V_55 -> V_10 , V_22 , V_23 , V_24 ) ;
return V_22 ;
}
return NULL ;
}
struct V_21 * F_43 ( struct V_14 * V_15 , int V_62 ,
unsigned int V_63 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_54 V_64 ;
int V_65 ;
V_65 = F_44 ( V_15 , V_63 & V_66 ) ;
if ( V_65 )
return F_45 ( V_65 ) ;
V_10 = F_46 ( V_15 ) ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_10 -> V_28 ) ;
F_47 ( & V_64 , V_15 , V_63 , V_10 , V_2 ) ;
V_22 = F_39 ( & V_64 , V_62 , 0 ) ;
if ( ! V_22 && ! ( V_63 & V_66 ) ) {
F_48 ( V_2 ) ;
F_49 ( V_10 ) ;
V_10 = F_46 ( V_15 ) ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_10 -> V_28 ) ;
F_47 ( & V_64 , V_15 , V_63 , V_10 , V_2 ) ;
V_22 = F_39 ( & V_64 , V_62 , 0 ) ;
V_10 = V_64 . V_10 ;
}
F_49 ( V_10 ) ;
if ( ! V_22 ) {
F_50 ( V_15 ) ;
return F_45 ( - V_69 ) ;
}
V_22 -> V_70 = 0 ;
V_22 -> V_71 = ( V_72 ) - 1 ;
V_22 -> V_73 = V_22 -> V_74 = NULL ;
return V_22 ;
}
struct V_21 * F_51 ( struct V_14 * V_15 , int V_62 ,
unsigned int V_63 , unsigned int V_75 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_21 * V_22 ;
struct V_54 V_64 ;
int V_65 ;
if ( F_20 ( ! ( V_63 & V_66 ) ) )
return F_45 ( - V_76 ) ;
if ( V_75 >= V_15 -> V_77 )
return F_45 ( - V_78 ) ;
V_65 = F_44 ( V_15 , true ) ;
if ( V_65 )
return F_45 ( V_65 ) ;
V_2 = V_15 -> V_79 [ V_75 ] ;
if ( ! F_25 ( V_2 ) ) {
V_65 = - V_80 ;
goto V_81;
}
V_10 = F_52 ( V_15 , F_53 ( V_2 -> V_82 ) ) ;
F_47 ( & V_64 , V_15 , V_63 , V_10 , V_2 ) ;
V_22 = F_39 ( & V_64 , V_62 , 0 ) ;
if ( ! V_22 ) {
V_65 = - V_69 ;
goto V_81;
}
return V_22 ;
V_81:
F_50 ( V_15 ) ;
return F_45 ( V_65 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_21 * V_22 )
{
const int V_56 = V_22 -> V_56 ;
struct V_14 * V_15 = V_22 -> V_15 ;
if ( V_22 -> V_59 & V_60 )
F_55 ( & V_2 -> V_61 ) ;
V_22 -> V_59 = 0 ;
F_8 ( V_83 , & V_22 -> V_84 ) ;
F_56 ( V_2 , V_56 , & V_10 -> V_85 ) ;
F_50 ( V_15 ) ;
}
void F_57 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_27 ;
V_10 -> V_86 [ F_58 ( V_22 ) ] ++ ;
F_54 ( V_2 , V_10 , V_22 ) ;
}
void F_59 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = V_22 -> V_15 ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_22 -> V_27 -> V_28 ) ;
F_57 ( V_2 , V_22 ) ;
}
inline void F_60 ( struct V_21 * V_22 , int error )
{
F_61 ( V_22 ) ;
if ( V_22 -> V_50 ) {
V_22 -> V_50 ( V_22 , error ) ;
} else {
if ( F_62 ( F_63 ( V_22 ) ) )
F_59 ( V_22 -> V_52 ) ;
F_59 ( V_22 ) ;
}
}
void F_64 ( struct V_21 * V_22 , int error )
{
if ( F_65 ( V_22 , error , F_66 ( V_22 ) ) )
F_67 () ;
F_60 ( V_22 , error ) ;
}
static void F_68 ( void * V_55 )
{
struct V_21 * V_22 = V_55 ;
V_22 -> V_15 -> V_87 ( V_22 ) ;
}
static void F_69 ( struct V_21 * V_22 )
{
struct V_9 * V_10 = V_22 -> V_27 ;
bool V_88 = false ;
int V_28 ;
if ( ! F_4 ( V_89 , & V_22 -> V_15 -> V_90 ) ) {
V_22 -> V_15 -> V_87 ( V_22 ) ;
return;
}
V_28 = F_70 () ;
if ( ! F_4 ( V_91 , & V_22 -> V_15 -> V_90 ) )
V_88 = F_71 ( V_28 , V_10 -> V_28 ) ;
if ( V_28 != V_10 -> V_28 && ! V_88 && F_72 ( V_10 -> V_28 ) ) {
V_22 -> V_92 . V_93 = F_68 ;
V_22 -> V_92 . V_94 = V_22 ;
V_22 -> V_92 . V_63 = 0 ;
F_73 ( V_10 -> V_28 , & V_22 -> V_92 ) ;
} else {
V_22 -> V_15 -> V_87 ( V_22 ) ;
}
F_74 () ;
}
static void F_75 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
if ( ! V_15 -> V_87 )
F_64 ( V_22 , V_22 -> V_41 ) ;
else
F_69 ( V_22 ) ;
}
void F_76 ( struct V_21 * V_22 , int error )
{
struct V_14 * V_15 = V_22 -> V_15 ;
if ( F_62 ( F_77 ( V_15 ) ) )
return;
if ( ! F_78 ( V_22 ) ) {
V_22 -> V_41 = error ;
F_75 ( V_22 ) ;
}
}
int F_79 ( struct V_21 * V_22 )
{
return F_4 ( V_83 , & V_22 -> V_84 ) ;
}
void F_80 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
F_81 ( V_15 , V_22 ) ;
V_22 -> V_46 = F_66 ( V_22 ) ;
if ( F_62 ( F_63 ( V_22 ) ) )
V_22 -> V_52 -> V_46 = F_66 ( V_22 -> V_52 ) ;
F_82 ( V_22 ) ;
F_83 () ;
if ( ! F_4 ( V_83 , & V_22 -> V_84 ) )
F_6 ( V_83 , & V_22 -> V_84 ) ;
if ( F_4 ( V_95 , & V_22 -> V_84 ) )
F_8 ( V_95 , & V_22 -> V_84 ) ;
if ( V_15 -> V_96 && F_66 ( V_22 ) ) {
V_22 -> V_37 ++ ;
}
}
static void F_84 ( struct V_21 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
F_85 ( V_15 , V_22 ) ;
if ( F_86 ( V_83 , & V_22 -> V_84 ) ) {
if ( V_15 -> V_96 && F_66 ( V_22 ) )
V_22 -> V_37 -- ;
}
}
void F_87 ( struct V_21 * V_22 )
{
F_84 ( V_22 ) ;
F_88 ( F_89 ( V_22 ) ) ;
F_90 ( V_22 , true ) ;
}
static void F_91 ( struct V_97 * V_98 )
{
struct V_14 * V_15 =
F_92 ( V_98 , struct V_14 , V_99 ) ;
F_93 ( V_100 ) ;
struct V_21 * V_22 , * V_101 ;
unsigned long V_63 ;
F_94 ( & V_15 -> V_102 , V_63 ) ;
F_95 ( & V_15 -> V_103 , & V_100 ) ;
F_96 ( & V_15 -> V_102 , V_63 ) ;
F_97 (rq, next, &rq_list, queuelist) {
if ( ! ( V_22 -> V_59 & V_104 ) )
continue;
V_22 -> V_59 &= ~ V_104 ;
F_98 ( & V_22 -> V_26 ) ;
F_99 ( V_22 , true , false , false ) ;
}
while ( ! F_100 ( & V_100 ) ) {
V_22 = F_101 ( V_100 . V_101 , struct V_21 , V_26 ) ;
F_98 ( & V_22 -> V_26 ) ;
F_99 ( V_22 , false , false , false ) ;
}
F_102 ( V_15 ) ;
}
void F_90 ( struct V_21 * V_22 , bool V_105 )
{
struct V_14 * V_15 = V_22 -> V_15 ;
unsigned long V_63 ;
F_88 ( V_22 -> V_59 & V_104 ) ;
F_94 ( & V_15 -> V_102 , V_63 ) ;
if ( V_105 ) {
V_22 -> V_59 |= V_104 ;
F_103 ( & V_22 -> V_26 , & V_15 -> V_103 ) ;
} else {
F_104 ( & V_22 -> V_26 , & V_15 -> V_103 ) ;
}
F_96 ( & V_15 -> V_102 , V_63 ) ;
}
void F_105 ( struct V_14 * V_15 )
{
F_106 ( & V_15 -> V_99 ) ;
}
void F_107 ( struct V_14 * V_15 )
{
F_108 ( & V_15 -> V_99 ) ;
}
void F_109 ( struct V_14 * V_15 )
{
unsigned long V_63 ;
F_93 ( V_100 ) ;
F_94 ( & V_15 -> V_102 , V_63 ) ;
F_95 ( & V_15 -> V_103 , & V_100 ) ;
F_96 ( & V_15 -> V_102 , V_63 ) ;
while ( ! F_100 ( & V_100 ) ) {
struct V_21 * V_22 ;
V_22 = F_110 ( & V_100 , struct V_21 , V_26 ) ;
F_98 ( & V_22 -> V_26 ) ;
V_22 -> V_41 = - V_78 ;
F_64 ( V_22 , V_22 -> V_41 ) ;
}
}
struct V_21 * F_111 ( struct V_106 * V_20 , unsigned int V_56 )
{
if ( V_56 < V_20 -> V_107 )
return V_20 -> V_58 [ V_56 ] ;
return NULL ;
}
void F_112 ( struct V_21 * V_108 , bool V_109 )
{
struct V_110 * V_111 = V_108 -> V_15 -> V_67 ;
enum V_112 V_65 = V_113 ;
if ( ! F_4 ( V_83 , & V_108 -> V_84 ) )
return;
if ( V_111 -> V_49 )
V_65 = V_111 -> V_49 ( V_108 , V_109 ) ;
switch ( V_65 ) {
case V_114 :
F_75 ( V_108 ) ;
break;
case V_113 :
F_82 ( V_108 ) ;
F_113 ( V_108 ) ;
break;
case V_115 :
break;
default:
F_114 ( V_116 L_1 , V_65 ) ;
break;
}
}
static void F_115 ( struct V_1 * V_2 ,
struct V_21 * V_22 , void * V_117 , bool V_109 )
{
struct V_118 * V_55 = V_117 ;
if ( ! F_4 ( V_83 , & V_22 -> V_84 ) ) {
if ( F_62 ( F_116 ( V_22 -> V_15 ) ) ) {
V_22 -> V_41 = - V_78 ;
F_64 ( V_22 , V_22 -> V_41 ) ;
}
return;
}
if ( F_117 ( V_34 , V_22 -> V_119 ) ) {
if ( ! F_78 ( V_22 ) )
F_112 ( V_22 , V_109 ) ;
} else if ( ! V_55 -> V_120 || F_118 ( V_55 -> V_101 , V_22 -> V_119 ) ) {
V_55 -> V_101 = V_22 -> V_119 ;
V_55 -> V_120 = 1 ;
}
}
static void F_119 ( struct V_97 * V_98 )
{
struct V_14 * V_15 =
F_92 ( V_98 , struct V_14 , V_121 ) ;
struct V_118 V_55 = {
. V_101 = 0 ,
. V_120 = 0 ,
} ;
int V_3 ;
if ( ! F_120 ( & V_15 -> V_18 ) )
return;
F_121 ( V_15 , F_115 , & V_55 ) ;
if ( V_55 . V_120 ) {
V_55 . V_101 = F_122 ( F_123 ( V_55 . V_101 ) ) ;
F_124 ( & V_15 -> V_49 , V_55 . V_101 ) ;
} else {
struct V_1 * V_2 ;
F_24 (q, hctx, i) {
if ( F_25 ( V_2 ) )
F_125 ( V_2 ) ;
}
}
F_50 ( V_15 ) ;
}
static bool F_126 ( struct V_14 * V_15 ,
struct V_9 * V_10 , struct V_73 * V_73 )
{
struct V_21 * V_22 ;
int V_122 = 8 ;
F_127 (rq, &ctx->rq_list, queuelist) {
int V_123 ;
if ( ! V_122 -- )
break;
if ( ! F_128 ( V_22 , V_73 ) )
continue;
V_123 = F_129 ( V_22 , V_73 ) ;
if ( V_123 == V_124 ) {
if ( F_130 ( V_15 , V_22 , V_73 ) ) {
V_10 -> V_125 ++ ;
return true ;
}
break;
} else if ( V_123 == V_126 ) {
if ( F_131 ( V_15 , V_22 , V_73 ) ) {
V_10 -> V_125 ++ ;
return true ;
}
break;
}
}
return false ;
}
static void F_132 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
struct V_9 * V_10 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_8 * V_13 = & V_2 -> V_4 . V_6 [ V_3 ] ;
unsigned int V_129 , V_130 ;
if ( ! V_13 -> V_7 )
continue;
V_130 = 0 ;
V_129 = V_3 * V_2 -> V_4 . V_12 ;
do {
V_130 = F_133 ( & V_13 -> V_7 , V_13 -> V_131 , V_130 ) ;
if ( V_130 >= V_13 -> V_131 )
break;
V_10 = V_2 -> V_132 [ V_130 + V_129 ] ;
F_8 ( V_130 , & V_13 -> V_7 ) ;
F_134 ( & V_10 -> V_133 ) ;
F_135 ( & V_10 -> V_100 , V_128 ) ;
F_136 ( & V_10 -> V_133 ) ;
V_130 ++ ;
} while ( 1 );
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_134 ;
struct V_21 * V_22 ;
F_93 ( V_100 ) ;
F_93 ( V_135 ) ;
struct V_127 * V_136 ;
int V_137 ;
if ( F_62 ( F_4 ( V_138 , & V_2 -> V_139 ) ) )
return;
F_137 ( ! F_138 ( F_139 () , V_2 -> V_82 ) &&
F_72 ( V_2 -> V_140 ) ) ;
V_2 -> V_141 ++ ;
F_132 ( V_2 , & V_100 ) ;
if ( ! F_140 ( & V_2 -> V_142 ) ) {
F_134 ( & V_2 -> V_133 ) ;
if ( ! F_100 ( & V_2 -> V_142 ) )
F_95 ( & V_2 -> V_142 , & V_100 ) ;
F_136 ( & V_2 -> V_133 ) ;
}
V_136 = NULL ;
V_137 = 0 ;
while ( ! F_100 ( & V_100 ) ) {
struct V_143 V_144 ;
int V_65 ;
V_22 = F_110 ( & V_100 , struct V_21 , V_26 ) ;
F_98 ( & V_22 -> V_26 ) ;
V_144 . V_22 = V_22 ;
V_144 . V_128 = V_136 ;
V_144 . V_145 = F_100 ( & V_100 ) ;
V_65 = V_15 -> V_67 -> V_146 ( V_2 , & V_144 ) ;
switch ( V_65 ) {
case V_147 :
V_137 ++ ;
break;
case V_148 :
F_103 ( & V_22 -> V_26 , & V_100 ) ;
F_84 ( V_22 ) ;
break;
default:
F_141 ( L_2 , V_65 ) ;
case V_149 :
V_22 -> V_41 = - V_78 ;
F_64 ( V_22 , V_22 -> V_41 ) ;
break;
}
if ( V_65 == V_148 )
break;
if ( ! V_136 && V_100 . V_101 != V_100 . V_150 )
V_136 = & V_135 ;
}
if ( ! V_137 )
V_2 -> V_151 [ 0 ] ++ ;
else if ( V_137 < ( 1 << ( V_152 - 1 ) ) )
V_2 -> V_151 [ F_142 ( V_137 ) + 1 ] ++ ;
if ( ! F_100 ( & V_100 ) ) {
F_134 ( & V_2 -> V_133 ) ;
F_143 ( & V_100 , & V_2 -> V_142 ) ;
F_136 ( & V_2 -> V_133 ) ;
F_144 ( V_2 , true ) ;
}
}
static int F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_134 -> V_77 == 1 )
return V_153 ;
if ( -- V_2 -> V_154 <= 0 ) {
int V_28 = V_2 -> V_140 , V_140 ;
V_140 = F_146 ( V_2 -> V_140 , V_2 -> V_82 ) ;
if ( V_140 >= V_155 )
V_140 = F_53 ( V_2 -> V_82 ) ;
V_2 -> V_140 = V_140 ;
V_2 -> V_154 = V_156 ;
return V_28 ;
}
return V_2 -> V_140 ;
}
void F_144 ( struct V_1 * V_2 , bool V_157 )
{
if ( F_62 ( F_4 ( V_138 , & V_2 -> V_139 ) ||
! F_25 ( V_2 ) ) )
return;
if ( ! V_157 ) {
int V_28 = F_70 () ;
if ( F_138 ( V_28 , V_2 -> V_82 ) ) {
F_48 ( V_2 ) ;
F_74 () ;
return;
}
F_74 () ;
}
F_147 ( F_145 ( V_2 ) ,
& V_2 -> V_158 , 0 ) ;
}
void F_12 ( struct V_14 * V_15 , bool V_157 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i) {
if ( ( ! F_1 ( V_2 ) &&
F_140 ( & V_2 -> V_142 ) ) ||
F_4 ( V_138 , & V_2 -> V_139 ) )
continue;
F_144 ( V_2 , V_157 ) ;
}
}
void F_148 ( struct V_1 * V_2 )
{
F_149 ( & V_2 -> V_158 ) ;
F_149 ( & V_2 -> V_159 ) ;
F_6 ( V_138 , & V_2 -> V_139 ) ;
}
void F_150 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i)
F_148 ( V_2 ) ;
}
void F_151 ( struct V_1 * V_2 )
{
F_8 ( V_138 , & V_2 -> V_139 ) ;
F_144 ( V_2 , false ) ;
}
void F_102 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i)
F_151 ( V_2 ) ;
}
void F_152 ( struct V_14 * V_15 , bool V_157 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i) {
if ( ! F_4 ( V_138 , & V_2 -> V_139 ) )
continue;
F_8 ( V_138 , & V_2 -> V_139 ) ;
F_144 ( V_2 , V_157 ) ;
}
}
static void F_153 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
V_2 = F_92 ( V_98 , struct V_1 , V_158 . V_98 ) ;
F_48 ( V_2 ) ;
}
static void F_154 ( struct V_97 * V_98 )
{
struct V_1 * V_2 ;
V_2 = F_92 ( V_98 , struct V_1 , V_159 . V_98 ) ;
if ( F_86 ( V_138 , & V_2 -> V_139 ) )
F_48 ( V_2 ) ;
}
void F_155 ( struct V_1 * V_2 , unsigned long V_160 )
{
if ( F_62 ( ! F_25 ( V_2 ) ) )
return;
F_147 ( F_145 ( V_2 ) ,
& V_2 -> V_159 , F_156 ( V_160 ) ) ;
}
static inline void F_157 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
bool V_105 )
{
struct V_9 * V_10 = V_22 -> V_27 ;
F_158 ( V_2 -> V_134 , V_22 ) ;
if ( V_105 )
F_103 ( & V_22 -> V_26 , & V_10 -> V_100 ) ;
else
F_104 ( & V_22 -> V_26 , & V_10 -> V_100 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_21 * V_22 , bool V_105 )
{
struct V_9 * V_10 = V_22 -> V_27 ;
F_157 ( V_2 , V_22 , V_105 ) ;
F_3 ( V_2 , V_10 ) ;
}
void F_99 ( struct V_21 * V_22 , bool V_105 , bool V_161 ,
bool V_157 )
{
struct V_9 * V_10 = V_22 -> V_27 ;
struct V_14 * V_15 = V_22 -> V_15 ;
struct V_1 * V_2 ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_10 -> V_28 ) ;
F_134 ( & V_10 -> V_133 ) ;
F_159 ( V_2 , V_22 , V_105 ) ;
F_136 ( & V_10 -> V_133 ) ;
if ( V_161 )
F_144 ( V_2 , V_157 ) ;
}
static void F_160 ( struct V_14 * V_15 ,
struct V_9 * V_10 ,
struct V_127 * V_128 ,
int V_131 ,
bool V_162 )
{
struct V_1 * V_2 ;
F_161 ( V_15 , V_131 , ! V_162 ) ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_10 -> V_28 ) ;
F_134 ( & V_10 -> V_133 ) ;
while ( ! F_100 ( V_128 ) ) {
struct V_21 * V_22 ;
V_22 = F_110 ( V_128 , struct V_21 , V_26 ) ;
F_88 ( V_22 -> V_27 != V_10 ) ;
F_98 ( & V_22 -> V_26 ) ;
F_157 ( V_2 , V_22 , false ) ;
}
F_3 ( V_2 , V_10 ) ;
F_136 ( & V_10 -> V_133 ) ;
F_144 ( V_2 , V_162 ) ;
}
static int F_162 ( void * V_117 , struct V_127 * V_163 , struct V_127 * V_164 )
{
struct V_21 * V_165 = F_92 ( V_163 , struct V_21 , V_26 ) ;
struct V_21 * V_166 = F_92 ( V_164 , struct V_21 , V_26 ) ;
return ! ( V_165 -> V_27 < V_166 -> V_27 ||
( V_165 -> V_27 == V_166 -> V_27 &&
F_163 ( V_165 ) < F_163 ( V_166 ) ) ) ;
}
void F_164 ( struct V_167 * V_168 , bool V_162 )
{
struct V_9 * V_169 ;
struct V_14 * V_170 ;
struct V_21 * V_22 ;
F_93 ( V_128 ) ;
F_93 ( V_171 ) ;
unsigned int V_131 ;
F_95 ( & V_168 -> V_172 , & V_128 ) ;
F_165 ( NULL , & V_128 , F_162 ) ;
V_170 = NULL ;
V_169 = NULL ;
V_131 = 0 ;
while ( ! F_100 ( & V_128 ) ) {
V_22 = F_166 ( V_128 . V_101 ) ;
F_98 ( & V_22 -> V_26 ) ;
F_88 ( ! V_22 -> V_15 ) ;
if ( V_22 -> V_27 != V_169 ) {
if ( V_169 ) {
F_160 ( V_170 , V_169 ,
& V_171 , V_131 ,
V_162 ) ;
}
V_169 = V_22 -> V_27 ;
V_170 = V_22 -> V_15 ;
V_131 = 0 ;
}
V_131 ++ ;
F_104 ( & V_22 -> V_26 , & V_171 ) ;
}
if ( V_169 ) {
F_160 ( V_170 , V_169 , & V_171 , V_131 ,
V_162 ) ;
}
}
static void F_167 ( struct V_21 * V_22 , struct V_73 * V_73 )
{
F_168 ( V_22 , V_73 ) ;
F_169 ( V_22 , 1 ) ;
}
static inline bool F_170 ( struct V_1 * V_2 )
{
return ( V_2 -> V_63 & V_173 ) &&
! F_171 ( V_2 -> V_134 ) ;
}
static inline bool F_172 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_21 * V_22 , struct V_73 * V_73 )
{
if ( ! F_170 ( V_2 ) || ! F_173 ( V_73 ) ) {
F_167 ( V_22 , V_73 ) ;
F_134 ( & V_10 -> V_133 ) ;
V_174:
F_159 ( V_2 , V_22 , false ) ;
F_136 ( & V_10 -> V_133 ) ;
return false ;
} else {
struct V_14 * V_15 = V_2 -> V_134 ;
F_134 ( & V_10 -> V_133 ) ;
if ( ! F_126 ( V_15 , V_10 , V_73 ) ) {
F_167 ( V_22 , V_73 ) ;
goto V_174;
}
F_136 ( & V_10 -> V_133 ) ;
F_54 ( V_2 , V_10 , V_22 ) ;
return true ;
}
}
static struct V_21 * F_174 ( struct V_14 * V_15 ,
struct V_73 * V_73 ,
struct V_175 * V_55 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_21 * V_22 ;
int V_23 = F_175 ( V_73 ) ;
int V_24 = 0 ;
struct V_54 V_64 ;
F_176 ( V_15 ) ;
V_10 = F_46 ( V_15 ) ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_10 -> V_28 ) ;
if ( F_38 ( F_177 ( V_73 ) , V_73 -> V_176 ) )
V_24 |= V_177 ;
F_178 ( V_15 , V_73 , V_23 ) ;
F_47 ( & V_64 , V_15 , V_66 , V_10 , V_2 ) ;
V_22 = F_39 ( & V_64 , V_23 , V_24 ) ;
if ( F_62 ( ! V_22 ) ) {
F_48 ( V_2 ) ;
F_49 ( V_10 ) ;
F_179 ( V_15 , V_73 , V_23 ) ;
V_10 = F_46 ( V_15 ) ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_10 -> V_28 ) ;
F_47 ( & V_64 , V_15 , 0 , V_10 , V_2 ) ;
V_22 = F_39 ( & V_64 , V_23 , V_24 ) ;
V_10 = V_64 . V_10 ;
V_2 = V_64 . V_2 ;
}
V_2 -> V_137 ++ ;
V_55 -> V_2 = V_2 ;
V_55 -> V_10 = V_10 ;
return V_22 ;
}
static int F_180 ( struct V_21 * V_22 , T_1 * V_178 )
{
int V_65 ;
struct V_14 * V_15 = V_22 -> V_15 ;
struct V_1 * V_2 = V_15 -> V_67 -> V_68 ( V_15 ,
V_22 -> V_27 -> V_28 ) ;
struct V_143 V_144 = {
. V_22 = V_22 ,
. V_128 = NULL ,
. V_145 = 1
} ;
T_1 V_179 = F_181 ( V_22 -> V_56 , V_2 -> V_180 ) ;
V_65 = V_15 -> V_67 -> V_146 ( V_2 , & V_144 ) ;
if ( V_65 == V_147 ) {
* V_178 = V_179 ;
return 0 ;
}
F_84 ( V_22 ) ;
if ( V_65 == V_149 ) {
* V_178 = V_181 ;
V_22 -> V_41 = - V_78 ;
F_64 ( V_22 , V_22 -> V_41 ) ;
return 0 ;
}
return - 1 ;
}
static T_1 F_182 ( struct V_14 * V_15 , struct V_73 * V_73 )
{
const int V_182 = F_38 ( F_177 ( V_73 ) , V_73 -> V_176 ) ;
const int V_183 = V_73 -> V_176 & ( V_184 | V_185 ) ;
struct V_175 V_55 ;
struct V_21 * V_22 ;
unsigned int V_186 = 0 ;
struct V_167 * V_168 ;
struct V_21 * V_187 = NULL ;
T_1 V_178 ;
F_183 ( V_15 , & V_73 ) ;
if ( F_184 ( V_73 ) && F_185 ( V_73 ) ) {
F_186 ( V_73 ) ;
return V_181 ;
}
F_187 ( V_15 , & V_73 , V_15 -> V_188 ) ;
if ( ! V_183 && ! F_171 ( V_15 ) &&
F_188 ( V_15 , V_73 , & V_186 , & V_187 ) )
return V_181 ;
V_22 = F_174 ( V_15 , V_73 , & V_55 ) ;
if ( F_62 ( ! V_22 ) )
return V_181 ;
V_178 = F_181 ( V_22 -> V_56 , V_55 . V_2 -> V_180 ) ;
if ( F_62 ( V_183 ) ) {
F_167 ( V_22 , V_73 ) ;
F_189 ( V_22 ) ;
goto V_161;
}
V_168 = V_189 -> V_168 ;
if ( ( ( V_168 && ! F_171 ( V_15 ) ) || V_182 ) &&
! ( V_55 . V_2 -> V_63 & V_190 ) ) {
struct V_21 * V_191 = NULL ;
F_167 ( V_22 , V_73 ) ;
if ( V_168 ) {
if ( V_187 && ! F_100 ( & V_168 -> V_172 ) ) {
V_191 = V_187 ;
F_98 ( & V_191 -> V_26 ) ;
}
F_104 ( & V_22 -> V_26 , & V_168 -> V_172 ) ;
} else
V_191 = V_22 ;
F_49 ( V_55 . V_10 ) ;
if ( ! V_191 )
goto V_192;
if ( ! F_180 ( V_191 , & V_178 ) )
goto V_192;
F_99 ( V_191 , false , true , true ) ;
goto V_192;
}
if ( ! F_172 ( V_55 . V_2 , V_55 . V_10 , V_22 , V_73 ) ) {
V_161:
F_144 ( V_55 . V_2 , ! V_182 || V_183 ) ;
}
F_49 ( V_55 . V_10 ) ;
V_192:
return V_178 ;
}
static T_1 F_190 ( struct V_14 * V_15 , struct V_73 * V_73 )
{
const int V_182 = F_38 ( F_177 ( V_73 ) , V_73 -> V_176 ) ;
const int V_183 = V_73 -> V_176 & ( V_184 | V_185 ) ;
struct V_167 * V_168 ;
unsigned int V_186 = 0 ;
struct V_175 V_55 ;
struct V_21 * V_22 ;
T_1 V_178 ;
F_183 ( V_15 , & V_73 ) ;
if ( F_184 ( V_73 ) && F_185 ( V_73 ) ) {
F_186 ( V_73 ) ;
return V_181 ;
}
F_187 ( V_15 , & V_73 , V_15 -> V_188 ) ;
if ( ! V_183 && ! F_171 ( V_15 ) ) {
if ( F_188 ( V_15 , V_73 , & V_186 , NULL ) )
return V_181 ;
} else
V_186 = F_191 ( V_15 ) ;
V_22 = F_174 ( V_15 , V_73 , & V_55 ) ;
if ( F_62 ( ! V_22 ) )
return V_181 ;
V_178 = F_181 ( V_22 -> V_56 , V_55 . V_2 -> V_180 ) ;
if ( F_62 ( V_183 ) ) {
F_167 ( V_22 , V_73 ) ;
F_189 ( V_22 ) ;
goto V_161;
}
V_168 = V_189 -> V_168 ;
if ( V_168 ) {
F_167 ( V_22 , V_73 ) ;
if ( ! V_186 )
F_192 ( V_15 ) ;
F_49 ( V_55 . V_10 ) ;
if ( V_186 >= V_193 ) {
F_193 ( V_168 , false ) ;
F_192 ( V_15 ) ;
}
F_104 ( & V_22 -> V_26 , & V_168 -> V_172 ) ;
return V_178 ;
}
if ( ! F_172 ( V_55 . V_2 , V_55 . V_10 , V_22 , V_73 ) ) {
V_161:
F_144 ( V_55 . V_2 , ! V_182 || V_183 ) ;
}
F_49 ( V_55 . V_10 ) ;
return V_178 ;
}
struct V_1 * F_194 ( struct V_14 * V_15 , const int V_28 )
{
return V_15 -> V_79 [ V_15 -> V_194 [ V_28 ] ] ;
}
static void F_195 ( struct V_195 * V_196 ,
struct V_106 * V_20 , unsigned int V_75 )
{
struct V_197 * V_197 ;
if ( V_20 -> V_58 && V_196 -> V_111 -> V_198 ) {
int V_3 ;
for ( V_3 = 0 ; V_3 < V_20 -> V_107 ; V_3 ++ ) {
if ( ! V_20 -> V_58 [ V_3 ] )
continue;
V_196 -> V_111 -> V_198 ( V_196 -> V_199 , V_20 -> V_58 [ V_3 ] ,
V_75 , V_3 ) ;
V_20 -> V_58 [ V_3 ] = NULL ;
}
}
while ( ! F_100 ( & V_20 -> V_200 ) ) {
V_197 = F_110 ( & V_20 -> V_200 , struct V_197 , V_201 ) ;
F_98 ( & V_197 -> V_201 ) ;
F_196 ( F_197 ( V_197 ) ) ;
F_198 ( V_197 , V_197 -> V_202 ) ;
}
F_199 ( V_20 -> V_58 ) ;
F_200 ( V_20 ) ;
}
static T_2 F_201 ( unsigned int V_203 )
{
return ( T_2 ) V_204 << V_203 ;
}
static struct V_106 * F_202 ( struct V_195 * V_196 ,
unsigned int V_75 )
{
struct V_106 * V_20 ;
unsigned int V_3 , V_205 , V_206 , V_207 = 4 ;
T_2 V_208 , V_209 ;
V_20 = F_203 ( V_196 -> V_210 , V_196 -> V_211 ,
V_196 -> V_212 ,
F_204 ( V_196 -> V_63 ) ) ;
if ( ! V_20 )
return NULL ;
F_31 ( & V_20 -> V_200 ) ;
V_20 -> V_58 = F_205 ( V_196 -> V_210 * sizeof( struct V_21 * ) ,
V_213 | V_214 | V_215 ,
V_196 -> V_212 ) ;
if ( ! V_20 -> V_58 ) {
F_200 ( V_20 ) ;
return NULL ;
}
V_208 = F_206 ( sizeof( struct V_21 ) + V_196 -> V_216 ,
F_207 () ) ;
V_209 = V_208 * V_196 -> V_210 ;
for ( V_3 = 0 ; V_3 < V_196 -> V_210 ; ) {
int V_217 = V_207 ;
struct V_197 * V_197 ;
int V_218 ;
void * V_219 ;
while ( V_217 && V_209 < F_201 ( V_217 - 1 ) )
V_217 -- ;
do {
V_197 = F_208 ( V_196 -> V_212 ,
V_213 | V_214 | V_215 | V_220 ,
V_217 ) ;
if ( V_197 )
break;
if ( ! V_217 -- )
break;
if ( F_201 ( V_217 ) < V_208 )
break;
} while ( 1 );
if ( ! V_197 )
goto V_221;
V_197 -> V_202 = V_217 ;
F_104 ( & V_197 -> V_201 , & V_20 -> V_200 ) ;
V_219 = F_197 ( V_197 ) ;
F_209 ( V_219 , F_201 ( V_217 ) , 1 , V_213 ) ;
V_206 = F_201 ( V_217 ) / V_208 ;
V_218 = F_210 ( V_206 , V_196 -> V_210 - V_3 ) ;
V_209 -= V_218 * V_208 ;
for ( V_205 = 0 ; V_205 < V_218 ; V_205 ++ ) {
V_20 -> V_58 [ V_3 ] = V_219 ;
if ( V_196 -> V_111 -> V_222 ) {
if ( V_196 -> V_111 -> V_222 ( V_196 -> V_199 ,
V_20 -> V_58 [ V_3 ] , V_75 , V_3 ,
V_196 -> V_212 ) ) {
V_20 -> V_58 [ V_3 ] = NULL ;
goto V_221;
}
}
V_219 += V_208 ;
V_3 ++ ;
}
}
return V_20 ;
V_221:
F_195 ( V_196 , V_20 , V_75 ) ;
return NULL ;
}
static void F_211 ( struct V_223 * V_224 )
{
F_199 ( V_224 -> V_6 ) ;
}
static int F_212 ( struct V_223 * V_224 , int V_225 )
{
unsigned int V_226 = 8 , V_227 , V_228 , V_3 ;
V_224 -> V_12 = V_226 ;
V_228 = F_213 ( V_155 , V_226 ) / V_226 ;
V_224 -> V_6 = F_205 ( V_228 * sizeof( struct V_8 ) ,
V_213 , V_225 ) ;
if ( ! V_224 -> V_6 )
return - V_229 ;
V_227 = V_155 ;
for ( V_3 = 0 ; V_3 < V_228 ; V_3 ++ ) {
V_224 -> V_6 [ V_3 ] . V_131 = F_210 ( V_227 , V_224 -> V_12 ) ;
V_227 -= V_224 -> V_6 [ V_3 ] . V_131 ;
}
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , int V_28 )
{
struct V_9 * V_10 ;
F_93 ( V_230 ) ;
V_10 = F_52 ( V_2 -> V_134 , V_28 ) ;
F_134 ( & V_10 -> V_133 ) ;
if ( ! F_100 ( & V_10 -> V_100 ) ) {
F_95 ( & V_10 -> V_100 , & V_230 ) ;
F_7 ( V_2 , V_10 ) ;
}
F_136 ( & V_10 -> V_133 ) ;
if ( F_100 ( & V_230 ) )
return V_231 ;
F_134 ( & V_2 -> V_133 ) ;
F_135 ( & V_230 , & V_2 -> V_142 ) ;
F_136 ( & V_2 -> V_133 ) ;
F_144 ( V_2 , true ) ;
return V_231 ;
}
static int F_215 ( void * V_55 , unsigned long V_232 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_55 ;
if ( V_232 == V_233 || V_232 == V_234 )
return F_214 ( V_2 , V_28 ) ;
return V_231 ;
}
static void F_216 ( struct V_14 * V_15 ,
struct V_195 * V_196 ,
struct V_1 * V_2 , unsigned int V_75 )
{
unsigned V_235 = V_196 -> V_210 ;
F_125 ( V_2 ) ;
if ( V_196 -> V_111 -> V_198 )
V_196 -> V_111 -> V_198 ( V_196 -> V_199 ,
V_2 -> V_236 -> V_237 , V_75 ,
V_235 + V_75 ) ;
if ( V_196 -> V_111 -> V_238 )
V_196 -> V_111 -> V_238 ( V_2 , V_75 ) ;
F_217 ( & V_2 -> V_239 ) ;
F_218 ( V_2 -> V_236 ) ;
F_211 ( & V_2 -> V_4 ) ;
}
static void F_219 ( struct V_14 * V_15 ,
struct V_195 * V_196 , int V_240 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i) {
if ( V_3 == V_240 )
break;
F_216 ( V_15 , V_196 , V_2 , V_3 ) ;
}
}
static void F_220 ( struct V_14 * V_15 ,
struct V_195 * V_196 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i)
F_221 ( V_2 -> V_82 ) ;
}
static int F_222 ( struct V_14 * V_15 ,
struct V_195 * V_196 ,
struct V_1 * V_2 , unsigned V_75 )
{
int V_225 ;
unsigned V_235 = V_196 -> V_210 ;
V_225 = V_2 -> V_212 ;
if ( V_225 == V_241 )
V_225 = V_2 -> V_212 = V_196 -> V_212 ;
F_223 ( & V_2 -> V_158 , F_153 ) ;
F_223 ( & V_2 -> V_159 , F_154 ) ;
F_224 ( & V_2 -> V_133 ) ;
F_31 ( & V_2 -> V_142 ) ;
V_2 -> V_134 = V_15 ;
V_2 -> V_180 = V_75 ;
V_2 -> V_63 = V_196 -> V_63 & ~ V_242 ;
F_225 ( & V_2 -> V_239 ,
F_215 , V_2 ) ;
F_226 ( & V_2 -> V_239 ) ;
V_2 -> V_20 = V_196 -> V_20 [ V_75 ] ;
V_2 -> V_132 = F_227 ( V_155 * sizeof( void * ) ,
V_213 , V_225 ) ;
if ( ! V_2 -> V_132 )
goto V_243;
if ( F_212 ( & V_2 -> V_4 , V_225 ) )
goto V_244;
V_2 -> V_245 = 0 ;
if ( V_196 -> V_111 -> V_246 &&
V_196 -> V_111 -> V_246 ( V_2 , V_196 -> V_199 , V_75 ) )
goto V_247;
V_2 -> V_236 = F_228 ( V_15 , V_2 -> V_212 , V_196 -> V_216 ) ;
if ( ! V_2 -> V_236 )
goto V_238;
if ( V_196 -> V_111 -> V_222 &&
V_196 -> V_111 -> V_222 ( V_196 -> V_199 ,
V_2 -> V_236 -> V_237 , V_75 ,
V_235 + V_75 , V_225 ) )
goto V_248;
return 0 ;
V_248:
F_199 ( V_2 -> V_236 ) ;
V_238:
if ( V_196 -> V_111 -> V_238 )
V_196 -> V_111 -> V_238 ( V_2 , V_75 ) ;
V_247:
F_211 ( & V_2 -> V_4 ) ;
V_244:
F_199 ( V_2 -> V_132 ) ;
V_243:
F_217 ( & V_2 -> V_239 ) ;
return - 1 ;
}
static void F_229 ( struct V_14 * V_15 ,
unsigned int V_77 )
{
unsigned int V_3 ;
F_230 (i) {
struct V_9 * V_249 = F_231 ( V_15 -> V_250 , V_3 ) ;
struct V_1 * V_2 ;
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
V_249 -> V_28 = V_3 ;
F_224 ( & V_249 -> V_133 ) ;
F_31 ( & V_249 -> V_100 ) ;
V_249 -> V_134 = V_15 ;
if ( ! F_72 ( V_3 ) )
continue;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_3 ) ;
if ( V_77 > 1 && V_2 -> V_212 == V_241 )
V_2 -> V_212 = F_232 ( F_233 ( V_3 ) ) ;
}
}
static void F_234 ( struct V_14 * V_15 ,
const struct V_82 * V_251 )
{
unsigned int V_3 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_195 * V_196 = V_15 -> V_252 ;
F_235 ( & V_15 -> V_253 ) ;
F_24 (q, hctx, i) {
F_236 ( V_2 -> V_82 ) ;
V_2 -> V_245 = 0 ;
}
F_230 (i) {
if ( ! F_138 ( V_3 , V_251 ) )
continue;
V_10 = F_231 ( V_15 -> V_250 , V_3 ) ;
V_2 = V_15 -> V_67 -> V_68 ( V_15 , V_3 ) ;
F_237 ( V_3 , V_2 -> V_82 ) ;
V_10 -> V_11 = V_2 -> V_245 ;
V_2 -> V_132 [ V_2 -> V_245 ++ ] = V_10 ;
}
F_238 ( & V_15 -> V_253 ) ;
F_24 (q, hctx, i) {
struct V_223 * V_6 = & V_2 -> V_4 ;
if ( ! V_2 -> V_245 ) {
if ( V_196 -> V_20 [ V_3 ] ) {
F_195 ( V_196 , V_196 -> V_20 [ V_3 ] , V_3 ) ;
V_196 -> V_20 [ V_3 ] = NULL ;
}
V_2 -> V_20 = NULL ;
continue;
}
if ( ! V_196 -> V_20 [ V_3 ] )
V_196 -> V_20 [ V_3 ] = F_202 ( V_196 , V_3 ) ;
V_2 -> V_20 = V_196 -> V_20 [ V_3 ] ;
F_137 ( ! V_2 -> V_20 ) ;
F_239 ( V_2 -> V_20 -> V_82 , V_2 -> V_82 ) ;
V_6 -> V_5 = F_240 ( V_2 -> V_245 , V_6 -> V_12 ) ;
V_2 -> V_140 = F_53 ( V_2 -> V_82 ) ;
V_2 -> V_154 = V_156 ;
}
}
static void F_241 ( struct V_14 * V_15 , bool V_88 )
{
struct V_1 * V_2 ;
int V_3 ;
F_24 (q, hctx, i) {
if ( V_88 )
V_2 -> V_63 |= V_242 ;
else
V_2 -> V_63 &= ~ V_242 ;
}
}
static void F_242 ( struct V_195 * V_196 , bool V_88 )
{
struct V_14 * V_15 ;
F_243 (q, &set->tag_list, tag_set_list) {
F_17 ( V_15 ) ;
F_241 ( V_15 , V_88 ) ;
F_18 ( V_15 ) ;
}
}
static void F_244 ( struct V_14 * V_15 )
{
struct V_195 * V_196 = V_15 -> V_252 ;
F_235 ( & V_196 -> V_254 ) ;
F_98 ( & V_15 -> V_255 ) ;
if ( F_245 ( & V_196 -> V_256 ) ) {
V_196 -> V_63 &= ~ V_242 ;
F_242 ( V_196 , false ) ;
}
F_238 ( & V_196 -> V_254 ) ;
}
static void F_246 ( struct V_195 * V_196 ,
struct V_14 * V_15 )
{
V_15 -> V_252 = V_196 ;
F_235 ( & V_196 -> V_254 ) ;
if ( ! F_100 ( & V_196 -> V_256 ) && ! ( V_196 -> V_63 & V_242 ) ) {
V_196 -> V_63 |= V_242 ;
F_242 ( V_196 , true ) ;
}
if ( V_196 -> V_63 & V_242 )
F_241 ( V_15 , true ) ;
F_104 ( & V_15 -> V_255 , & V_196 -> V_256 ) ;
F_238 ( & V_196 -> V_254 ) ;
}
void F_247 ( struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_3 ;
F_24 (q, hctx, i) {
if ( ! V_2 )
continue;
F_199 ( V_2 -> V_132 ) ;
F_199 ( V_2 ) ;
}
F_199 ( V_15 -> V_194 ) ;
V_15 -> V_194 = NULL ;
F_199 ( V_15 -> V_79 ) ;
F_248 ( V_15 -> V_250 ) ;
}
struct V_14 * F_249 ( struct V_195 * V_196 )
{
struct V_14 * V_257 , * V_15 ;
V_257 = F_250 ( V_213 , V_196 -> V_212 ) ;
if ( ! V_257 )
return F_45 ( - V_229 ) ;
V_15 = F_251 ( V_196 , V_257 ) ;
if ( F_252 ( V_15 ) )
F_253 ( V_257 ) ;
return V_15 ;
}
static void F_254 ( struct V_195 * V_196 ,
struct V_14 * V_15 )
{
int V_3 , V_205 ;
struct V_1 * * V_258 = V_15 -> V_79 ;
F_255 ( V_15 ) ;
for ( V_3 = 0 ; V_3 < V_196 -> V_77 ; V_3 ++ ) {
int V_225 ;
if ( V_258 [ V_3 ] )
continue;
V_225 = F_256 ( V_15 -> V_194 , V_3 ) ;
V_258 [ V_3 ] = F_205 ( sizeof( struct V_1 ) ,
V_213 , V_225 ) ;
if ( ! V_258 [ V_3 ] )
break;
if ( ! F_257 ( & V_258 [ V_3 ] -> V_82 , V_213 ,
V_225 ) ) {
F_199 ( V_258 [ V_3 ] ) ;
V_258 [ V_3 ] = NULL ;
break;
}
F_258 ( & V_258 [ V_3 ] -> V_61 , 0 ) ;
V_258 [ V_3 ] -> V_212 = V_225 ;
V_258 [ V_3 ] -> V_180 = V_3 ;
if ( F_222 ( V_15 , V_196 , V_258 [ V_3 ] , V_3 ) ) {
F_221 ( V_258 [ V_3 ] -> V_82 ) ;
F_199 ( V_258 [ V_3 ] ) ;
V_258 [ V_3 ] = NULL ;
break;
}
F_259 ( V_258 [ V_3 ] ) ;
}
for ( V_205 = V_3 ; V_205 < V_15 -> V_77 ; V_205 ++ ) {
struct V_1 * V_2 = V_258 [ V_205 ] ;
if ( V_2 ) {
if ( V_2 -> V_20 ) {
F_195 ( V_196 , V_2 -> V_20 , V_205 ) ;
V_196 -> V_20 [ V_205 ] = NULL ;
}
F_216 ( V_15 , V_196 , V_2 , V_205 ) ;
F_221 ( V_2 -> V_82 ) ;
F_260 ( & V_2 -> V_259 ) ;
F_199 ( V_2 -> V_132 ) ;
F_199 ( V_2 ) ;
V_258 [ V_205 ] = NULL ;
}
}
V_15 -> V_77 = V_3 ;
F_261 ( V_15 ) ;
}
struct V_14 * F_251 ( struct V_195 * V_196 ,
struct V_14 * V_15 )
{
V_15 -> V_67 = V_196 -> V_111 ;
V_15 -> V_250 = F_262 ( struct V_9 ) ;
if ( ! V_15 -> V_250 )
goto V_260;
V_15 -> V_79 = F_205 ( V_155 * sizeof( * ( V_15 -> V_79 ) ) ,
V_213 , V_196 -> V_212 ) ;
if ( ! V_15 -> V_79 )
goto V_261;
V_15 -> V_194 = F_263 ( V_196 ) ;
if ( ! V_15 -> V_194 )
goto V_262;
F_254 ( V_196 , V_15 ) ;
if ( ! V_15 -> V_77 )
goto V_263;
F_264 ( & V_15 -> V_121 , F_119 ) ;
F_265 ( V_15 , V_196 -> V_49 ? V_196 -> V_49 : 30 * V_264 ) ;
V_15 -> V_265 = V_155 ;
V_15 -> V_90 |= V_266 ;
if ( ! ( V_196 -> V_63 & V_267 ) )
V_15 -> V_90 |= 1 << V_268 ;
V_15 -> V_269 = V_270 ;
F_264 ( & V_15 -> V_99 , F_91 ) ;
F_31 ( & V_15 -> V_103 ) ;
F_224 ( & V_15 -> V_102 ) ;
if ( V_15 -> V_77 > 1 )
F_266 ( V_15 , F_182 ) ;
else
F_266 ( V_15 , F_190 ) ;
V_15 -> V_271 = V_196 -> V_210 ;
if ( V_196 -> V_111 -> V_272 )
F_267 ( V_15 , V_196 -> V_111 -> V_272 ) ;
F_229 ( V_15 , V_196 -> V_77 ) ;
F_268 () ;
F_235 ( & V_273 ) ;
F_104 ( & V_15 -> V_274 , & V_275 ) ;
F_246 ( V_196 , V_15 ) ;
F_234 ( V_15 , V_276 ) ;
F_238 ( & V_273 ) ;
F_269 () ;
return V_15 ;
V_263:
F_199 ( V_15 -> V_194 ) ;
V_262:
F_199 ( V_15 -> V_79 ) ;
V_261:
F_248 ( V_15 -> V_250 ) ;
V_260:
V_15 -> V_67 = NULL ;
return F_45 ( - V_229 ) ;
}
void F_270 ( struct V_14 * V_15 )
{
struct V_195 * V_196 = V_15 -> V_252 ;
F_235 ( & V_273 ) ;
F_98 ( & V_15 -> V_274 ) ;
F_238 ( & V_273 ) ;
F_244 ( V_15 ) ;
F_219 ( V_15 , V_196 , V_196 -> V_77 ) ;
F_220 ( V_15 , V_196 ) ;
}
static void F_271 ( struct V_14 * V_15 ,
const struct V_82 * V_251 )
{
F_20 ( ! F_272 ( & V_15 -> V_17 ) ) ;
F_255 ( V_15 ) ;
F_273 ( V_15 -> V_194 , V_15 -> V_77 , V_251 ) ;
F_234 ( V_15 , V_251 ) ;
F_261 ( V_15 ) ;
}
static int F_274 ( struct V_277 * V_278 ,
unsigned long V_232 , void * V_279 )
{
struct V_14 * V_15 ;
int V_28 = ( unsigned long ) V_279 ;
static struct V_82 V_280 ;
switch ( V_232 & ~ V_281 ) {
case V_233 :
case V_282 :
F_239 ( & V_280 , V_276 ) ;
break;
case V_283 :
F_239 ( & V_280 , V_276 ) ;
F_237 ( V_28 , & V_280 ) ;
break;
default:
return V_231 ;
}
F_235 ( & V_273 ) ;
F_243 (q, &all_q_list, all_q_node)
F_9 ( V_15 ) ;
F_243 (q, &all_q_list, all_q_node) {
F_13 ( V_15 ) ;
F_275 ( & V_15 -> V_49 ) ;
}
F_243 (q, &all_q_list, all_q_node)
F_271 ( V_15 , & V_280 ) ;
F_243 (q, &all_q_list, all_q_node)
F_18 ( V_15 ) ;
F_238 ( & V_273 ) ;
return V_231 ;
}
static int F_276 ( struct V_195 * V_196 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_196 -> V_77 ; V_3 ++ ) {
V_196 -> V_20 [ V_3 ] = F_202 ( V_196 , V_3 ) ;
if ( ! V_196 -> V_20 [ V_3 ] )
goto V_284;
}
return 0 ;
V_284:
while ( -- V_3 >= 0 )
F_195 ( V_196 , V_196 -> V_20 [ V_3 ] , V_3 ) ;
return - V_229 ;
}
static int F_277 ( struct V_195 * V_196 )
{
unsigned int V_131 ;
int V_285 ;
V_131 = V_196 -> V_210 ;
do {
V_285 = F_276 ( V_196 ) ;
if ( ! V_285 )
break;
V_196 -> V_210 >>= 1 ;
if ( V_196 -> V_210 < V_196 -> V_211 + V_286 ) {
V_285 = - V_229 ;
break;
}
} while ( V_196 -> V_210 );
if ( ! V_196 -> V_210 || V_285 ) {
F_141 ( L_3 ) ;
return - V_229 ;
}
if ( V_131 != V_196 -> V_210 )
F_278 ( L_4 ,
V_131 , V_196 -> V_210 ) ;
return 0 ;
}
struct V_82 * F_279 ( struct V_106 * V_20 )
{
return V_20 -> V_82 ;
}
int F_280 ( struct V_195 * V_196 )
{
F_281 ( V_287 > 1 << V_288 ) ;
if ( ! V_196 -> V_77 )
return - V_76 ;
if ( ! V_196 -> V_210 )
return - V_76 ;
if ( V_196 -> V_210 < V_196 -> V_211 + V_286 )
return - V_76 ;
if ( ! V_196 -> V_111 -> V_146 || ! V_196 -> V_111 -> V_68 )
return - V_76 ;
if ( V_196 -> V_210 > V_287 ) {
F_278 ( L_5 ,
V_287 ) ;
V_196 -> V_210 = V_287 ;
}
if ( F_282 () ) {
V_196 -> V_77 = 1 ;
V_196 -> V_210 = F_210 ( 64U , V_196 -> V_210 ) ;
}
if ( V_196 -> V_77 > V_155 )
V_196 -> V_77 = V_155 ;
V_196 -> V_20 = F_205 ( V_155 * sizeof( struct V_106 * ) ,
V_213 , V_196 -> V_212 ) ;
if ( ! V_196 -> V_20 )
return - V_229 ;
if ( F_277 ( V_196 ) )
goto V_289;
F_283 ( & V_196 -> V_254 ) ;
F_31 ( & V_196 -> V_256 ) ;
return 0 ;
V_289:
F_199 ( V_196 -> V_20 ) ;
V_196 -> V_20 = NULL ;
return - V_229 ;
}
void F_284 ( struct V_195 * V_196 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_155 ; V_3 ++ ) {
if ( V_196 -> V_20 [ V_3 ] )
F_195 ( V_196 , V_196 -> V_20 [ V_3 ] , V_3 ) ;
}
F_199 ( V_196 -> V_20 ) ;
V_196 -> V_20 = NULL ;
}
int F_285 ( struct V_14 * V_15 , unsigned int V_290 )
{
struct V_195 * V_196 = V_15 -> V_252 ;
struct V_1 * V_2 ;
int V_3 , V_65 ;
if ( ! V_196 || V_290 > V_196 -> V_210 )
return - V_76 ;
V_65 = 0 ;
F_24 (q, hctx, i) {
if ( ! V_2 -> V_20 )
continue;
V_65 = F_286 ( V_2 -> V_20 , V_290 ) ;
if ( V_65 )
break;
}
if ( ! V_65 )
V_15 -> V_271 = V_290 ;
return V_65 ;
}
void F_287 ( struct V_195 * V_196 , int V_77 )
{
struct V_14 * V_15 ;
if ( V_77 > V_155 )
V_77 = V_155 ;
if ( V_77 < 1 || V_77 == V_196 -> V_77 )
return;
F_243 (q, &set->tag_list, tag_set_list)
F_17 ( V_15 ) ;
V_196 -> V_77 = V_77 ;
F_243 (q, &set->tag_list, tag_set_list) {
F_254 ( V_196 , V_15 ) ;
if ( V_15 -> V_77 > 1 )
F_266 ( V_15 , F_182 ) ;
else
F_266 ( V_15 , F_190 ) ;
F_271 ( V_15 , V_276 ) ;
}
F_243 (q, &set->tag_list, tag_set_list)
F_18 ( V_15 ) ;
}
void F_288 ( void )
{
F_235 ( & V_273 ) ;
}
void F_289 ( void )
{
F_238 ( & V_273 ) ;
}
static int T_3 F_290 ( void )
{
F_291 () ;
F_292 ( F_274 , 0 ) ;
return 0 ;
}
