static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
return F_2 ( V_3 -> V_5 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , F_4 () ) ;
}
static void F_5 ( struct V_1 * V_6 )
{
F_6 () ;
}
static bool F_7 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ )
if ( V_8 -> V_11 [ V_9 ] )
return true ;
return false ;
}
static void F_8 ( struct V_7 * V_8 ,
struct V_1 * V_6 )
{
if ( ! F_9 ( V_6 -> V_12 , V_8 -> V_11 ) )
F_10 ( V_6 -> V_12 , V_8 -> V_11 ) ;
}
static struct V_13 * F_11 ( struct V_7 * V_8 , T_1 V_14 ,
bool V_15 )
{
struct V_13 * V_16 ;
unsigned int V_17 ;
V_17 = F_12 ( V_8 -> V_18 , V_14 , V_15 ) ;
if ( V_17 != V_19 ) {
V_16 = V_8 -> V_20 [ V_17 ] ;
V_16 -> V_17 = V_17 ;
return V_16 ;
}
return NULL ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_21 ;
F_14 ( & V_3 -> V_22 , 1 , 1000000 ) ;
F_15 () ;
if ( ! F_16 ( V_3 ) || ! F_17 ( V_3 ) )
return 0 ;
F_14 ( & V_3 -> V_22 , - 1 , 1000000 ) ;
F_18 ( V_3 -> V_23 ) ;
V_21 = F_19 ( V_3 -> V_24 ,
! F_16 ( V_3 ) , * V_3 -> V_23 ) ;
if ( ! V_21 )
F_14 ( & V_3 -> V_22 , 1 , 1000000 ) ;
F_20 ( V_3 -> V_23 ) ;
return V_21 ;
}
static void F_21 ( struct V_2 * V_3 )
{
F_14 ( & V_3 -> V_22 , - 1 , 1000000 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
bool V_25 ;
F_18 ( V_3 -> V_23 ) ;
V_25 = ! V_3 -> V_26 ++ ;
F_23 ( V_27 , V_3 ) ;
F_20 ( V_3 -> V_23 ) ;
if ( ! V_25 )
return;
while ( true ) {
T_2 V_28 ;
F_18 ( V_3 -> V_23 ) ;
V_28 = F_24 ( & V_3 -> V_22 ) ;
F_20 ( V_3 -> V_23 ) ;
if ( V_28 == 0 )
break;
F_25 ( V_3 , false ) ;
F_26 ( 10 ) ;
}
}
static void F_27 ( struct V_2 * V_3 )
{
bool V_29 = false ;
F_18 ( V_3 -> V_23 ) ;
if ( ! -- V_3 -> V_26 ) {
F_28 ( V_27 , V_3 ) ;
V_29 = true ;
}
F_29 ( V_3 -> V_26 < 0 ) ;
F_20 ( V_3 -> V_23 ) ;
if ( V_29 )
F_30 ( & V_3 -> V_24 ) ;
}
bool F_31 ( struct V_7 * V_8 )
{
return F_32 ( V_8 -> V_18 ) ;
}
static void F_33 ( struct V_2 * V_3 , struct V_1 * V_6 ,
struct V_13 * V_16 , unsigned int V_30 )
{
if ( F_34 ( V_3 ) )
V_30 |= V_31 ;
V_16 -> V_32 = V_6 ;
V_16 -> V_33 = V_30 ;
V_6 -> V_34 [ F_35 ( V_30 ) ] ++ ;
}
static struct V_13 * F_36 ( struct V_7 * V_8 ,
T_1 V_14 , bool V_15 )
{
return F_11 ( V_8 , V_14 , V_15 ) ;
}
static struct V_13 * F_37 ( struct V_2 * V_3 ,
int V_35 , T_1 V_14 ,
bool V_15 )
{
struct V_13 * V_16 ;
do {
struct V_1 * V_6 = F_3 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
V_16 = F_36 ( V_8 , V_14 & ~ V_38 , V_15 ) ;
if ( V_16 ) {
F_33 ( V_3 , V_6 , V_16 , V_35 ) ;
break;
}
F_5 ( V_6 ) ;
if ( ! ( V_14 & V_38 ) )
break;
F_38 ( V_8 ) ;
F_39 ( V_8 -> V_18 ) ;
} while ( 1 );
return V_16 ;
}
struct V_13 * F_40 ( struct V_2 * V_3 , int V_35 ,
T_1 V_14 , bool V_15 )
{
struct V_13 * V_16 ;
if ( F_13 ( V_3 ) )
return NULL ;
V_16 = F_37 ( V_3 , V_35 , V_14 , V_15 ) ;
if ( V_16 )
F_5 ( V_16 -> V_32 ) ;
return V_16 ;
}
struct V_13 * F_41 ( struct V_2 * V_3 , int V_35 ,
T_1 V_14 )
{
struct V_13 * V_16 ;
if ( F_13 ( V_3 ) )
return NULL ;
V_16 = F_37 ( V_3 , V_35 , V_14 , true ) ;
if ( V_16 )
F_5 ( V_16 -> V_32 ) ;
return V_16 ;
}
static void F_42 ( struct V_7 * V_8 , struct V_13 * V_16 )
{
F_43 ( V_8 -> V_39 , V_16 ) ;
if ( V_8 -> V_40 )
V_16 -> V_41 = F_44 ( V_16 ) ;
}
static void F_45 ( struct V_7 * V_8 ,
struct V_1 * V_6 , struct V_13 * V_16 )
{
const int V_17 = V_16 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_42 ( V_8 , V_16 ) ;
F_46 ( V_8 -> V_18 , V_17 ) ;
F_21 ( V_3 ) ;
}
void F_47 ( struct V_13 * V_16 )
{
struct V_1 * V_6 = V_16 -> V_32 ;
struct V_7 * V_8 ;
struct V_2 * V_3 = V_16 -> V_3 ;
V_6 -> V_42 [ F_48 ( V_16 ) ] ++ ;
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
F_45 ( V_8 , V_6 , V_16 ) ;
}
static void F_49 ( struct V_13 * V_16 , struct V_43 * V_43 , int error )
{
if ( error )
F_50 ( V_44 , & V_43 -> V_45 ) ;
else if ( ! F_9 ( V_44 , & V_43 -> V_45 ) )
error = - V_46 ;
if ( F_51 ( V_16 -> V_33 & V_47 ) )
F_10 ( V_48 , & V_43 -> V_45 ) ;
if ( ! ( V_16 -> V_33 & V_49 ) )
F_52 ( V_43 , error ) ;
}
void F_53 ( struct V_13 * V_16 , int error )
{
struct V_43 * V_43 = V_16 -> V_43 ;
unsigned int V_50 = 0 ;
F_54 ( V_16 -> V_3 , V_16 ) ;
while ( V_43 ) {
struct V_43 * V_51 = V_43 -> V_52 ;
V_43 -> V_52 = NULL ;
V_50 += V_43 -> V_53 ;
F_49 ( V_16 , V_43 , error ) ;
V_43 = V_51 ;
}
F_55 ( V_16 , V_50 ) ;
F_56 ( V_16 ) ;
if ( V_16 -> V_54 )
V_16 -> V_54 ( V_16 , error ) ;
else
F_47 ( V_16 ) ;
}
void F_57 ( struct V_13 * V_16 , int error )
{
if ( ! F_58 ( V_16 ) )
F_53 ( V_16 , error ) ;
}
static void F_59 ( void * V_55 )
{
struct V_56 * V_57 = & F_60 ( V_58 , F_61 () ) ;
struct V_59 * V_60 , * V_51 ;
struct V_13 * V_16 ;
V_60 = F_62 ( V_57 ) ;
while ( V_60 ) {
V_51 = V_60 -> V_51 ;
V_16 = F_63 ( V_60 , struct V_13 , V_61 ) ;
F_57 ( V_16 , V_16 -> V_62 ) ;
V_60 = V_51 ;
}
}
static int F_64 ( struct V_1 * V_6 , const int V_4 ,
struct V_13 * V_16 , const int error )
{
struct V_63 * V_55 = & V_16 -> V_64 ;
V_16 -> V_62 = error ;
V_16 -> V_61 . V_51 = NULL ;
if ( F_65 ( & V_16 -> V_61 , & F_60 ( V_58 , V_6 -> V_4 ) ) ) {
V_55 -> V_65 = F_59 ;
V_55 -> V_66 = 0 ;
F_66 ( V_6 -> V_4 , V_55 , 0 ) ;
}
return true ;
}
static int F_64 ( struct V_1 * V_6 , const int V_4 ,
struct V_13 * V_16 , const int error )
{
return false ;
}
void F_67 ( struct V_13 * V_16 , int error )
{
struct V_1 * V_6 = V_16 -> V_32 ;
int V_4 ;
if ( ! V_6 -> V_67 )
return F_57 ( V_16 , error ) ;
V_4 = F_4 () ;
if ( V_4 == V_6 -> V_4 || ! F_68 ( V_6 -> V_4 ) ||
! F_64 ( V_6 , V_4 , V_16 , error ) )
F_57 ( V_16 , error ) ;
F_6 () ;
}
static void F_69 ( struct V_13 * V_16 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
F_70 ( V_3 , V_16 ) ;
V_16 -> V_68 = V_69 + V_3 -> V_70 ;
F_10 ( V_71 , & V_16 -> V_72 ) ;
}
static void F_71 ( struct V_13 * V_16 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
F_72 ( V_3 , V_16 ) ;
F_50 ( V_71 , & V_16 -> V_72 ) ;
}
static void F_73 ( void * V_73 , unsigned long * V_74 )
{
struct V_75 * V_55 = V_73 ;
struct V_7 * V_8 = V_55 -> V_8 ;
unsigned int V_17 ;
V_17 = 0 ;
do {
struct V_13 * V_16 ;
V_17 = F_74 ( V_74 , V_8 -> V_76 , V_17 ) ;
if ( V_17 >= V_8 -> V_76 )
break;
V_16 = V_8 -> V_20 [ V_17 ++ ] ;
if ( ! F_9 ( V_71 , & V_16 -> V_72 ) )
continue;
F_75 ( V_16 , V_55 -> V_51 , V_55 -> V_77 ) ;
} while ( 1 );
}
static void F_76 ( struct V_7 * V_8 ,
unsigned long * V_51 ,
unsigned int * V_77 )
{
struct V_75 V_55 = {
. V_8 = V_8 ,
. V_51 = V_51 ,
. V_77 = V_77 ,
} ;
F_77 ( V_8 -> V_18 , F_73 , & V_55 ) ;
}
static void F_78 ( unsigned long V_55 )
{
struct V_2 * V_3 = (struct V_2 * ) V_55 ;
struct V_7 * V_8 ;
unsigned long V_51 = 0 ;
int V_9 , V_77 = 0 ;
F_79 (q, hctx, i)
F_76 ( V_8 , & V_51 , & V_77 ) ;
if ( V_77 )
F_80 ( & V_3 -> V_78 , F_81 ( V_51 ) ) ;
}
static bool F_82 ( struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_43 * V_43 )
{
struct V_13 * V_16 ;
int V_79 = 8 ;
F_83 (rq, &ctx->rq_list, queuelist) {
int V_80 ;
if ( ! V_79 -- )
break;
if ( ! F_84 ( V_16 , V_43 ) )
continue;
V_80 = F_85 ( V_16 , V_43 ) ;
if ( V_80 == V_81 ) {
if ( F_86 ( V_3 , V_16 , V_43 ) ) {
V_6 -> V_82 ++ ;
return true ;
}
break;
} else if ( V_80 == V_83 ) {
if ( F_87 ( V_3 , V_16 , V_43 ) ) {
V_6 -> V_82 ++ ;
return true ;
}
break;
}
}
return false ;
}
void F_88 ( struct V_13 * V_16 )
{
F_89 ( V_16 , NULL ) ;
}
static void F_38 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_39 ;
struct V_1 * V_6 ;
struct V_13 * V_16 ;
F_90 ( V_84 ) ;
int V_85 , V_86 ;
if ( F_51 ( F_9 ( V_87 , & V_8 -> V_66 ) ) )
return;
V_8 -> V_88 ++ ;
F_91 (bit, hctx->ctx_map, hctx->nr_ctx) {
F_50 ( V_85 , V_8 -> V_11 ) ;
V_6 = V_8 -> V_89 [ V_85 ] ;
F_92 ( V_85 != V_6 -> V_12 ) ;
F_93 ( & V_6 -> V_90 ) ;
F_94 ( & V_6 -> V_84 , & V_84 ) ;
F_95 ( & V_6 -> V_90 ) ;
}
if ( ! F_96 ( & V_8 -> V_91 ) ) {
F_93 ( & V_8 -> V_90 ) ;
if ( ! F_97 ( & V_8 -> V_91 ) )
F_98 ( & V_8 -> V_91 , & V_84 ) ;
F_95 ( & V_8 -> V_90 ) ;
}
V_86 = 0 ;
while ( ! F_97 ( & V_84 ) ) {
int V_21 ;
V_16 = F_99 ( & V_84 , struct V_13 , V_92 ) ;
F_100 ( & V_16 -> V_92 ) ;
F_69 ( V_16 ) ;
if ( F_97 ( & V_84 ) )
V_16 -> V_33 |= V_93 ;
V_21 = V_3 -> V_36 -> V_94 ( V_8 , V_16 ) ;
switch ( V_21 ) {
case V_95 :
V_86 ++ ;
continue;
case V_96 :
F_101 ( & V_16 -> V_92 , & V_84 ) ;
F_71 ( V_16 ) ;
break;
default:
F_102 ( L_1 , V_21 ) ;
V_16 -> V_62 = - V_46 ;
case V_97 :
F_67 ( V_16 , V_16 -> V_62 ) ;
break;
}
if ( V_21 == V_96 )
break;
}
if ( ! V_86 )
V_8 -> V_98 [ 0 ] ++ ;
else if ( V_86 < ( 1 << ( V_99 - 1 ) ) )
V_8 -> V_98 [ F_103 ( V_86 ) + 1 ] ++ ;
if ( ! F_97 ( & V_84 ) ) {
F_93 ( & V_8 -> V_90 ) ;
F_104 ( & V_84 , & V_8 -> V_91 ) ;
F_95 ( & V_8 -> V_90 ) ;
}
}
void F_105 ( struct V_7 * V_8 , bool V_100 )
{
if ( F_51 ( F_9 ( V_87 , & V_8 -> V_66 ) ) )
return;
if ( ! V_100 )
F_38 ( V_8 ) ;
else {
struct V_2 * V_3 = V_8 -> V_39 ;
F_106 ( V_3 , & V_8 -> V_101 , 0 ) ;
}
}
void F_25 ( struct V_2 * V_3 , bool V_100 )
{
struct V_7 * V_8 ;
int V_9 ;
F_79 (q, hctx, i) {
if ( ( ! F_7 ( V_8 ) &&
F_96 ( & V_8 -> V_91 ) ) ||
F_9 ( V_87 , & V_8 -> V_66 ) )
continue;
F_105 ( V_8 , V_100 ) ;
}
}
void F_107 ( struct V_7 * V_8 )
{
F_108 ( & V_8 -> V_101 ) ;
F_10 ( V_87 , & V_8 -> V_102 ) ;
}
void F_109 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_9 ;
F_79 (q, hctx, i)
F_107 ( V_8 ) ;
}
void F_110 ( struct V_7 * V_8 )
{
F_50 ( V_87 , & V_8 -> V_102 ) ;
F_38 ( V_8 ) ;
}
void F_111 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_9 ;
F_79 (q, hctx, i) {
if ( ! F_9 ( V_87 , & V_8 -> V_102 ) )
continue;
F_50 ( V_87 , & V_8 -> V_102 ) ;
F_105 ( V_8 , true ) ;
}
}
static void F_112 ( struct V_103 * V_104 )
{
struct V_7 * V_8 ;
V_8 = F_113 ( V_104 , struct V_7 , V_101 . V_104 ) ;
F_38 ( V_8 ) ;
}
static void F_114 ( struct V_7 * V_8 ,
struct V_13 * V_16 )
{
struct V_1 * V_6 = V_16 -> V_32 ;
F_115 ( V_8 -> V_39 , V_16 ) ;
F_116 ( & V_16 -> V_92 , & V_6 -> V_84 ) ;
F_8 ( V_8 , V_6 ) ;
F_88 ( V_16 ) ;
}
void F_117 ( struct V_2 * V_3 , struct V_13 * V_16 ,
bool V_105 )
{
struct V_7 * V_8 ;
struct V_1 * V_6 , * V_106 ;
V_6 = V_16 -> V_32 ;
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
if ( V_16 -> V_33 & ( V_107 | V_108 ) ) {
F_118 ( V_16 ) ;
} else {
V_106 = F_3 ( V_3 ) ;
if ( ! F_68 ( V_6 -> V_4 ) ) {
V_6 = V_106 ;
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
V_16 -> V_32 = V_6 ;
}
F_93 ( & V_6 -> V_90 ) ;
F_114 ( V_8 , V_16 ) ;
F_95 ( & V_6 -> V_90 ) ;
F_5 ( V_106 ) ;
}
if ( V_105 )
F_38 ( V_8 ) ;
}
void F_119 ( struct V_13 * V_16 , bool V_105 , bool V_100 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_7 * V_8 ;
struct V_1 * V_6 , * V_106 ;
V_106 = F_3 ( V_3 ) ;
V_6 = V_16 -> V_32 ;
if ( ! F_68 ( V_6 -> V_4 ) ) {
V_6 = V_106 ;
V_16 -> V_32 = V_6 ;
}
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
F_93 ( & V_6 -> V_90 ) ;
F_114 ( V_8 , V_16 ) ;
F_95 ( & V_6 -> V_90 ) ;
F_5 ( V_106 ) ;
if ( V_105 )
F_105 ( V_8 , V_100 ) ;
}
static void F_120 ( struct V_2 * V_3 ,
struct V_1 * V_6 ,
struct V_109 * V_57 ,
int V_110 ,
bool V_111 )
{
struct V_7 * V_8 ;
struct V_1 * V_106 ;
F_121 ( V_3 , V_110 , ! V_111 ) ;
V_106 = F_3 ( V_3 ) ;
if ( ! F_68 ( V_6 -> V_4 ) )
V_6 = V_106 ;
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
F_93 ( & V_6 -> V_90 ) ;
while ( ! F_97 ( V_57 ) ) {
struct V_13 * V_16 ;
V_16 = F_99 ( V_57 , struct V_13 , V_92 ) ;
F_100 ( & V_16 -> V_92 ) ;
V_16 -> V_32 = V_6 ;
F_114 ( V_8 , V_16 ) ;
}
F_95 ( & V_6 -> V_90 ) ;
F_5 ( V_106 ) ;
F_105 ( V_8 , V_111 ) ;
}
static int F_122 ( void * V_112 , struct V_109 * V_113 , struct V_109 * V_114 )
{
struct V_13 * V_115 = F_113 ( V_113 , struct V_13 , V_92 ) ;
struct V_13 * V_116 = F_113 ( V_114 , struct V_13 , V_92 ) ;
return ! ( V_115 -> V_32 < V_116 -> V_32 ||
( V_115 -> V_32 == V_116 -> V_32 &&
F_123 ( V_115 ) < F_123 ( V_116 ) ) ) ;
}
void F_124 ( struct V_117 * V_118 , bool V_111 )
{
struct V_1 * V_119 ;
struct V_2 * V_120 ;
struct V_13 * V_16 ;
F_90 ( V_57 ) ;
F_90 ( V_121 ) ;
unsigned int V_110 ;
F_98 ( & V_118 -> V_122 , & V_57 ) ;
F_125 ( NULL , & V_57 , F_122 ) ;
V_120 = NULL ;
V_119 = NULL ;
V_110 = 0 ;
while ( ! F_97 ( & V_57 ) ) {
V_16 = F_126 ( V_57 . V_51 ) ;
F_100 ( & V_16 -> V_92 ) ;
F_92 ( ! V_16 -> V_3 ) ;
if ( V_16 -> V_32 != V_119 ) {
if ( V_119 ) {
F_120 ( V_120 , V_119 ,
& V_121 , V_110 ,
V_111 ) ;
}
V_119 = V_16 -> V_32 ;
V_120 = V_16 -> V_3 ;
V_110 = 0 ;
}
V_110 ++ ;
F_116 ( & V_16 -> V_92 , & V_121 ) ;
}
if ( V_119 ) {
F_120 ( V_120 , V_119 , & V_121 , V_110 ,
V_111 ) ;
}
}
static void F_127 ( struct V_13 * V_16 , struct V_43 * V_43 )
{
F_128 ( V_16 , V_43 ) ;
F_129 ( V_16 , 1 ) ;
}
static void F_130 ( struct V_2 * V_3 , struct V_43 * V_43 )
{
struct V_7 * V_8 ;
struct V_1 * V_6 ;
const int V_123 = F_35 ( V_43 -> V_124 ) ;
const int V_125 = V_43 -> V_124 & ( V_107 | V_108 ) ;
int V_35 = F_131 ( V_43 ) ;
struct V_13 * V_16 ;
unsigned int V_126 , V_127 = 0 ;
V_126 = ! V_125 && ( ( V_3 -> V_128 == 1 ) || ! V_123 ) ;
F_132 ( V_3 , & V_43 ) ;
if ( V_126 && F_133 ( V_3 , V_43 , & V_127 ) )
return;
if ( F_13 ( V_3 ) ) {
F_52 ( V_43 , - V_46 ) ;
return;
}
V_6 = F_3 ( V_3 ) ;
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
F_134 ( V_3 , V_43 , V_35 ) ;
V_16 = F_36 ( V_8 , V_129 , false ) ;
if ( F_135 ( V_16 ) )
F_33 ( V_3 , V_6 , V_16 , V_35 ) ;
else {
F_5 ( V_6 ) ;
F_136 ( V_3 , V_43 , V_35 ) ;
V_16 = F_37 ( V_3 , V_35 , V_38 | V_129 ,
false ) ;
V_6 = V_16 -> V_32 ;
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_6 -> V_4 ) ;
}
V_8 -> V_86 ++ ;
if ( F_51 ( V_125 ) ) {
F_127 ( V_16 , V_43 ) ;
F_5 ( V_6 ) ;
F_118 ( V_16 ) ;
goto V_105;
}
if ( V_126 ) {
struct V_117 * V_118 = V_130 -> V_118 ;
if ( V_118 ) {
F_127 ( V_16 , V_43 ) ;
if ( F_97 ( & V_118 -> V_122 ) )
F_137 ( V_3 ) ;
else if ( V_127 >= V_131 ) {
F_138 ( V_118 , false ) ;
F_137 ( V_3 ) ;
}
F_116 ( & V_16 -> V_92 , & V_118 -> V_122 ) ;
F_5 ( V_6 ) ;
return;
}
}
F_93 ( & V_6 -> V_90 ) ;
if ( ( V_8 -> V_66 & V_132 ) &&
F_82 ( V_3 , V_6 , V_43 ) )
F_45 ( V_8 , V_6 , V_16 ) ;
else {
F_127 ( V_16 , V_43 ) ;
F_114 ( V_8 , V_16 ) ;
}
F_95 ( & V_6 -> V_90 ) ;
F_5 ( V_6 ) ;
V_105:
F_105 ( V_8 , ! V_123 || V_125 ) ;
}
struct V_7 * F_139 ( struct V_2 * V_3 , const int V_4 )
{
return V_3 -> V_133 [ V_3 -> V_134 [ V_4 ] ] ;
}
struct V_7 * F_140 ( struct V_135 * V_136 ,
unsigned int V_137 )
{
return F_141 ( sizeof( struct V_7 ) ,
V_138 | V_139 , V_136 -> V_140 ) ;
}
void F_142 ( struct V_7 * V_8 ,
unsigned int V_137 )
{
F_143 ( V_8 ) ;
}
static void F_144 ( void * V_55 , unsigned long V_141 ,
unsigned int V_4 )
{
struct V_7 * V_8 = V_55 ;
struct V_1 * V_6 ;
F_90 ( V_142 ) ;
if ( V_141 != V_143 && V_141 != V_144 )
return;
V_6 = F_1 ( V_8 -> V_39 , V_4 ) ;
F_93 ( & V_6 -> V_90 ) ;
if ( ! F_97 ( & V_6 -> V_84 ) ) {
F_98 ( & V_6 -> V_84 , & V_142 ) ;
F_50 ( V_6 -> V_12 , V_8 -> V_11 ) ;
}
F_95 ( & V_6 -> V_90 ) ;
if ( F_97 ( & V_142 ) )
return;
V_6 = F_3 ( V_8 -> V_39 ) ;
F_93 ( & V_6 -> V_90 ) ;
while ( ! F_97 ( & V_142 ) ) {
struct V_13 * V_16 ;
V_16 = F_99 ( & V_142 , struct V_13 , V_92 ) ;
V_16 -> V_32 = V_6 ;
F_145 ( & V_16 -> V_92 , & V_6 -> V_84 ) ;
}
F_8 ( V_8 , V_6 ) ;
F_95 ( & V_6 -> V_90 ) ;
F_5 ( V_6 ) ;
}
static void F_146 ( struct V_7 * V_8 ,
void (* F_147)( void * , struct V_7 * ,
struct V_13 * , unsigned int ) ,
void * V_55 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_76 ; V_9 ++ ) {
struct V_13 * V_16 = V_8 -> V_20 [ V_9 ] ;
F_147 ( V_55 , V_8 , V_16 , V_9 ) ;
}
}
void F_148 ( struct V_2 * V_3 ,
void (* F_147)( void * , struct V_7 * ,
struct V_13 * , unsigned int ) ,
void * V_55 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
F_79 (q, hctx, i)
F_146 ( V_8 , F_147 , V_55 ) ;
}
static void F_149 ( struct V_7 * V_8 )
{
struct V_145 * V_145 ;
while ( ! F_97 ( & V_8 -> V_146 ) ) {
V_145 = F_99 ( & V_8 -> V_146 , struct V_145 , V_57 ) ;
F_100 ( & V_145 -> V_57 ) ;
F_150 ( V_145 , V_145 -> V_147 ) ;
}
F_143 ( V_8 -> V_20 ) ;
if ( V_8 -> V_18 )
F_151 ( V_8 -> V_18 ) ;
}
static T_3 F_152 ( unsigned int V_148 )
{
T_3 V_21 = V_149 ;
while ( V_148 -- )
V_21 *= 2 ;
return V_21 ;
}
static int F_153 ( struct V_7 * V_8 ,
unsigned int V_150 , int V_151 )
{
unsigned int V_9 , V_152 , V_153 , V_154 = 4 ;
T_3 V_155 , V_156 ;
F_154 ( & V_8 -> V_146 ) ;
V_8 -> V_20 = F_141 ( V_8 -> V_76 * sizeof( struct V_13 * ) ,
V_138 , V_151 ) ;
if ( ! V_8 -> V_20 )
return - V_157 ;
V_155 = F_155 ( sizeof( struct V_13 ) + V_8 -> V_40 ,
F_156 () ) ;
V_156 = V_155 * V_8 -> V_76 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_76 ; ) {
int V_158 = V_154 ;
struct V_145 * V_145 ;
int V_159 ;
void * V_160 ;
while ( V_156 < F_152 ( V_158 - 1 ) && V_158 )
V_158 -- ;
do {
V_145 = F_157 ( V_151 , V_138 , V_158 ) ;
if ( V_145 )
break;
if ( ! V_158 -- )
break;
if ( F_152 ( V_158 ) < V_155 )
break;
} while ( 1 );
if ( ! V_145 )
break;
V_145 -> V_147 = V_158 ;
F_116 ( & V_145 -> V_57 , & V_8 -> V_146 ) ;
V_160 = F_158 ( V_145 ) ;
V_153 = F_152 ( V_158 ) / V_155 ;
V_159 = F_159 ( V_153 , V_8 -> V_76 - V_9 ) ;
V_156 -= V_159 * V_155 ;
for ( V_152 = 0 ; V_152 < V_159 ; V_152 ++ ) {
V_8 -> V_20 [ V_9 ] = V_160 ;
F_42 ( V_8 , V_8 -> V_20 [ V_9 ] ) ;
V_160 += V_155 ;
V_9 ++ ;
}
}
if ( V_9 < ( V_150 + V_161 ) )
goto V_162;
else if ( V_9 != V_8 -> V_76 ) {
V_8 -> V_76 = V_9 ;
F_160 ( L_2 ,
V_163 , V_9 ) ;
}
V_8 -> V_18 = F_161 ( V_8 -> V_76 , V_150 , V_151 ) ;
if ( ! V_8 -> V_18 ) {
V_162:
F_149 ( V_8 ) ;
return - V_157 ;
}
return 0 ;
}
static int F_162 ( struct V_2 * V_3 ,
struct V_135 * V_136 , void * V_164 )
{
struct V_7 * V_8 ;
unsigned int V_9 , V_152 ;
F_79 (q, hctx, i) {
unsigned int V_165 ;
int V_151 ;
V_151 = V_8 -> V_140 ;
if ( V_151 == V_166 )
V_151 = V_8 -> V_140 = V_136 -> V_140 ;
F_163 ( & V_8 -> V_101 , F_112 ) ;
F_164 ( & V_8 -> V_90 ) ;
F_154 ( & V_8 -> V_91 ) ;
V_8 -> V_39 = V_3 ;
V_8 -> V_167 = V_9 ;
V_8 -> V_66 = V_136 -> V_66 ;
V_8 -> V_76 = V_136 -> V_76 ;
V_8 -> V_40 = V_136 -> V_40 ;
F_165 ( & V_8 -> V_168 ,
F_144 , V_8 ) ;
F_166 ( & V_8 -> V_168 ) ;
if ( F_153 ( V_8 , V_136 -> V_150 , V_151 ) )
break;
V_8 -> V_89 = F_141 ( V_169 * sizeof( void * ) ,
V_138 , V_151 ) ;
if ( ! V_8 -> V_89 )
break;
V_165 = F_167 ( V_169 , V_170 ) / V_170 ;
V_8 -> V_11 = F_168 ( V_165 * sizeof( unsigned long ) ,
V_138 , V_151 ) ;
if ( ! V_8 -> V_11 )
break;
V_8 -> V_10 = V_165 ;
V_8 -> V_171 = 0 ;
if ( V_136 -> V_172 -> V_173 &&
V_136 -> V_172 -> V_173 ( V_8 , V_164 , V_9 ) )
break;
}
if ( V_9 == V_3 -> V_128 )
return 0 ;
F_79 (q, hctx, j) {
if ( V_9 == V_152 )
break;
if ( V_136 -> V_172 -> V_174 )
V_136 -> V_172 -> V_174 ( V_8 , V_152 ) ;
F_169 ( & V_8 -> V_168 ) ;
F_149 ( V_8 ) ;
F_143 ( V_8 -> V_89 ) ;
}
return 1 ;
}
static void F_170 ( struct V_2 * V_3 ,
unsigned int V_128 )
{
unsigned int V_9 ;
F_171 (i) {
struct V_1 * V_175 = F_2 ( V_3 -> V_5 , V_9 ) ;
struct V_7 * V_8 ;
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_4 = V_9 ;
F_164 ( & V_175 -> V_90 ) ;
F_154 ( & V_175 -> V_84 ) ;
V_175 -> V_39 = V_3 ;
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_9 ) ;
V_8 -> V_171 ++ ;
if ( ! F_68 ( V_9 ) )
continue;
if ( V_128 > 1 && V_8 -> V_140 == V_166 )
V_8 -> V_140 = F_172 ( V_9 ) ;
}
}
static void F_173 ( struct V_2 * V_3 )
{
unsigned int V_9 ;
struct V_7 * V_8 ;
struct V_1 * V_6 ;
F_79 (q, hctx, i) {
V_8 -> V_171 = 0 ;
}
F_174 (q, ctx, i) {
V_8 = V_3 -> V_36 -> V_37 ( V_3 , V_9 ) ;
V_6 -> V_12 = V_8 -> V_171 ;
V_8 -> V_89 [ V_8 -> V_171 ++ ] = V_6 ;
}
}
struct V_2 * F_175 ( struct V_135 * V_136 ,
void * V_164 )
{
struct V_7 * * V_176 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_9 ;
if ( ! V_136 -> V_128 ||
! V_136 -> V_172 -> V_94 || ! V_136 -> V_172 -> V_37 ||
! V_136 -> V_172 -> V_177 || ! V_136 -> V_172 -> V_178 )
return F_176 ( - V_179 ) ;
if ( ! V_136 -> V_76 )
V_136 -> V_76 = V_180 ;
else if ( V_136 -> V_76 > V_180 ) {
F_102 ( L_3 , V_136 -> V_76 ) ;
V_136 -> V_76 = V_180 ;
}
V_136 -> V_76 ++ ;
V_136 -> V_150 ++ ;
if ( V_136 -> V_76 < ( V_136 -> V_150 + V_161 ) )
return F_176 ( - V_179 ) ;
V_6 = F_177 ( struct V_1 ) ;
if ( ! V_6 )
return F_176 ( - V_157 ) ;
V_176 = F_141 ( V_136 -> V_128 * sizeof( * V_176 ) , V_138 ,
V_136 -> V_140 ) ;
if ( ! V_176 )
goto V_181;
for ( V_9 = 0 ; V_9 < V_136 -> V_128 ; V_9 ++ ) {
V_176 [ V_9 ] = V_136 -> V_172 -> V_177 ( V_136 , V_9 ) ;
if ( ! V_176 [ V_9 ] )
goto V_182;
V_176 [ V_9 ] -> V_140 = V_166 ;
V_176 [ V_9 ] -> V_167 = V_9 ;
}
V_3 = F_178 ( V_138 , V_136 -> V_140 ) ;
if ( ! V_3 )
goto V_182;
V_3 -> V_134 = F_179 ( V_136 ) ;
if ( ! V_3 -> V_134 )
goto V_183;
F_180 ( & V_3 -> V_78 , F_78 , ( unsigned long ) V_3 ) ;
F_181 ( V_3 , 30000 ) ;
V_3 -> V_184 = V_169 ;
V_3 -> V_128 = V_136 -> V_128 ;
V_3 -> V_5 = V_6 ;
V_3 -> V_133 = V_176 ;
V_3 -> V_36 = V_136 -> V_172 ;
V_3 -> V_185 |= V_186 ;
F_182 ( V_3 , F_130 ) ;
F_183 ( V_3 , V_136 -> V_172 -> V_78 ) ;
if ( V_136 -> V_78 )
F_181 ( V_3 , V_136 -> V_78 ) ;
F_184 ( V_3 ) ;
F_170 ( V_3 , V_136 -> V_128 ) ;
if ( F_162 ( V_3 , V_136 , V_164 ) )
goto V_187;
F_173 ( V_3 ) ;
F_185 ( & V_188 ) ;
F_116 ( & V_3 -> V_189 , & V_190 ) ;
F_186 ( & V_188 ) ;
return V_3 ;
V_187:
F_143 ( V_3 -> V_134 ) ;
V_183:
F_187 ( V_3 ) ;
V_182:
for ( V_9 = 0 ; V_9 < V_136 -> V_128 ; V_9 ++ ) {
if ( ! V_176 [ V_9 ] )
break;
V_136 -> V_172 -> V_178 ( V_176 [ V_9 ] , V_9 ) ;
}
F_143 ( V_176 ) ;
V_181:
F_188 ( V_6 ) ;
return F_176 ( - V_157 ) ;
}
void F_189 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_9 ;
F_79 (q, hctx, i) {
F_190 ( & V_8 -> V_101 ) ;
F_143 ( V_8 -> V_11 ) ;
F_143 ( V_8 -> V_89 ) ;
F_149 ( V_8 ) ;
F_169 ( & V_8 -> V_168 ) ;
if ( V_3 -> V_36 -> V_174 )
V_3 -> V_36 -> V_174 ( V_8 , V_9 ) ;
V_3 -> V_36 -> V_178 ( V_8 , V_9 ) ;
}
F_188 ( V_3 -> V_5 ) ;
F_143 ( V_3 -> V_133 ) ;
F_143 ( V_3 -> V_134 ) ;
V_3 -> V_5 = NULL ;
V_3 -> V_133 = NULL ;
V_3 -> V_134 = NULL ;
F_185 ( & V_188 ) ;
F_100 ( & V_3 -> V_189 ) ;
F_186 ( & V_188 ) ;
}
static void F_191 ( struct V_2 * V_3 )
{
F_22 ( V_3 ) ;
F_192 ( V_3 -> V_134 , V_3 -> V_128 ) ;
F_173 ( V_3 ) ;
F_27 ( V_3 ) ;
}
static int F_193 ( struct V_191 * V_192 ,
unsigned long V_141 , void * V_193 )
{
struct V_2 * V_3 ;
if ( V_141 != V_143 && V_141 != V_144 &&
V_141 != V_194 && V_141 != V_195 )
return V_196 ;
F_185 ( & V_188 ) ;
F_194 (q, &all_q_list, all_q_node)
F_191 ( V_3 ) ;
F_186 ( & V_188 ) ;
return V_196 ;
}
static int T_4 F_195 ( void )
{
unsigned int V_9 ;
F_171 (i)
F_196 ( & F_60 ( V_58 , V_9 ) ) ;
F_197 () ;
F_198 ( F_193 , - 10 ) ;
return 0 ;
}
