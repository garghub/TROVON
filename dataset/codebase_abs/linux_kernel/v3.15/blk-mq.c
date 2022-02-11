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
static struct V_13 * F_11 ( struct V_7 * V_8 ,
T_1 V_14 , bool V_15 )
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
! F_16 ( V_3 ) || F_20 ( V_3 ) ,
* V_3 -> V_23 ) ;
if ( ! V_21 && ! F_20 ( V_3 ) )
F_14 ( & V_3 -> V_22 , 1 , 1000000 ) ;
else if ( F_20 ( V_3 ) )
V_21 = - V_25 ;
F_21 ( V_3 -> V_23 ) ;
return V_21 ;
}
static void F_22 ( struct V_2 * V_3 )
{
F_14 ( & V_3 -> V_22 , - 1 , 1000000 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
while ( true ) {
T_2 V_26 ;
F_18 ( V_3 -> V_23 ) ;
V_26 = F_24 ( & V_3 -> V_22 ) ;
F_21 ( V_3 -> V_23 ) ;
if ( V_26 == 0 )
break;
F_25 ( V_3 , false ) ;
F_26 ( 10 ) ;
}
}
static void F_27 ( struct V_2 * V_3 )
{
bool V_27 ;
F_18 ( V_3 -> V_23 ) ;
V_27 = ! V_3 -> V_28 ++ ;
F_28 ( V_29 , V_3 ) ;
F_21 ( V_3 -> V_23 ) ;
if ( V_27 )
F_23 ( V_3 ) ;
}
void F_29 ( struct V_2 * V_3 )
{
F_23 ( V_3 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
bool V_30 = false ;
F_18 ( V_3 -> V_23 ) ;
if ( ! -- V_3 -> V_28 ) {
F_31 ( V_29 , V_3 ) ;
V_30 = true ;
}
F_32 ( V_3 -> V_28 < 0 ) ;
F_21 ( V_3 -> V_23 ) ;
if ( V_30 )
F_33 ( & V_3 -> V_24 ) ;
}
bool F_34 ( struct V_7 * V_8 )
{
return F_35 ( V_8 -> V_18 ) ;
}
static void F_36 ( struct V_2 * V_3 , struct V_1 * V_6 ,
struct V_13 * V_16 , unsigned int V_31 )
{
if ( F_37 ( V_3 ) )
V_31 |= V_32 ;
V_16 -> V_33 = V_6 ;
V_16 -> V_34 = V_31 ;
V_16 -> V_35 = V_36 ;
F_38 ( V_16 ) ;
V_6 -> V_37 [ F_39 ( V_31 ) ] ++ ;
}
static struct V_13 * F_40 ( struct V_2 * V_3 ,
int V_38 , T_1 V_14 ,
bool V_15 )
{
struct V_13 * V_16 ;
do {
struct V_1 * V_6 = F_3 ( V_3 ) ;
struct V_7 * V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_6 -> V_4 ) ;
V_16 = F_11 ( V_8 , V_14 & ~ V_41 , V_15 ) ;
if ( V_16 ) {
F_36 ( V_3 , V_6 , V_16 , V_38 ) ;
break;
}
F_5 ( V_6 ) ;
if ( ! ( V_14 & V_41 ) )
break;
F_41 ( V_8 ) ;
F_42 ( V_8 -> V_18 ) ;
} while ( 1 );
return V_16 ;
}
struct V_13 * F_43 ( struct V_2 * V_3 , int V_38 , T_1 V_14 )
{
struct V_13 * V_16 ;
if ( F_13 ( V_3 ) )
return NULL ;
V_16 = F_40 ( V_3 , V_38 , V_14 , false ) ;
if ( V_16 )
F_5 ( V_16 -> V_33 ) ;
return V_16 ;
}
struct V_13 * F_44 ( struct V_2 * V_3 , int V_38 ,
T_1 V_14 )
{
struct V_13 * V_16 ;
if ( F_13 ( V_3 ) )
return NULL ;
V_16 = F_40 ( V_3 , V_38 , V_14 , true ) ;
if ( V_16 )
F_5 ( V_16 -> V_33 ) ;
return V_16 ;
}
void F_45 ( struct V_7 * V_8 , struct V_13 * V_16 )
{
F_46 ( V_8 -> V_42 , V_16 ) ;
if ( V_8 -> V_43 )
V_16 -> V_44 = F_47 ( V_16 ) ;
}
static void F_48 ( struct V_7 * V_8 ,
struct V_1 * V_6 , struct V_13 * V_16 )
{
const int V_17 = V_16 -> V_17 ;
struct V_2 * V_3 = V_16 -> V_3 ;
F_45 ( V_8 , V_16 ) ;
F_49 ( V_8 -> V_18 , V_17 ) ;
F_22 ( V_3 ) ;
}
void F_50 ( struct V_13 * V_16 )
{
struct V_1 * V_6 = V_16 -> V_33 ;
struct V_7 * V_8 ;
struct V_2 * V_3 = V_16 -> V_3 ;
V_6 -> V_45 [ F_51 ( V_16 ) ] ++ ;
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_6 -> V_4 ) ;
F_48 ( V_8 , V_6 , V_16 ) ;
}
bool F_52 ( struct V_13 * V_16 , int error , unsigned int V_46 )
{
if ( F_53 ( V_16 , error , F_54 ( V_16 ) ) )
return true ;
F_55 ( V_16 ) ;
if ( V_16 -> V_47 )
V_16 -> V_47 ( V_16 , error ) ;
else
F_50 ( V_16 ) ;
return false ;
}
static void F_56 ( void * V_48 )
{
struct V_13 * V_16 = V_48 ;
V_16 -> V_3 -> V_49 ( V_16 ) ;
}
void F_57 ( struct V_13 * V_16 )
{
struct V_1 * V_6 = V_16 -> V_33 ;
int V_4 ;
if ( ! V_6 -> V_50 ) {
V_16 -> V_3 -> V_49 ( V_16 ) ;
return;
}
V_4 = F_4 () ;
if ( V_4 != V_6 -> V_4 && F_58 ( V_6 -> V_4 ) ) {
V_16 -> V_51 . V_52 = F_56 ;
V_16 -> V_51 . V_53 = V_16 ;
V_16 -> V_51 . V_54 = 0 ;
F_59 ( V_6 -> V_4 , & V_16 -> V_51 ) ;
} else {
V_16 -> V_3 -> V_49 ( V_16 ) ;
}
F_6 () ;
}
void F_60 ( struct V_13 * V_16 )
{
if ( F_61 ( F_62 ( V_16 -> V_3 ) ) )
return;
if ( ! F_63 ( V_16 ) )
F_57 ( V_16 ) ;
}
static void F_64 ( struct V_13 * V_16 , bool V_55 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
F_65 ( V_3 , V_16 ) ;
V_16 -> V_56 = V_36 + V_3 -> V_57 ;
F_10 ( V_58 , & V_16 -> V_59 ) ;
if ( V_3 -> V_60 && F_54 ( V_16 ) ) {
V_16 -> V_61 ++ ;
}
if ( V_55 )
V_16 -> V_34 |= V_62 ;
}
static void F_66 ( struct V_13 * V_16 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
F_67 ( V_3 , V_16 ) ;
F_68 ( V_58 , & V_16 -> V_59 ) ;
V_16 -> V_34 &= ~ V_62 ;
if ( V_3 -> V_60 && F_54 ( V_16 ) )
V_16 -> V_61 -- ;
}
static void F_69 ( void * V_63 , unsigned long * V_64 )
{
struct V_65 * V_48 = V_63 ;
struct V_7 * V_8 = V_48 -> V_8 ;
unsigned int V_17 ;
V_17 = 0 ;
do {
struct V_13 * V_16 ;
V_17 = F_70 ( V_64 , V_8 -> V_66 , V_17 ) ;
if ( V_17 >= V_8 -> V_66 )
break;
V_16 = V_8 -> V_20 [ V_17 ++ ] ;
if ( ! F_9 ( V_58 , & V_16 -> V_59 ) )
continue;
F_71 ( V_16 , V_48 -> V_67 , V_48 -> V_68 ) ;
} while ( 1 );
}
static void F_72 ( struct V_7 * V_8 ,
unsigned long * V_67 ,
unsigned int * V_68 )
{
struct V_65 V_48 = {
. V_8 = V_8 ,
. V_67 = V_67 ,
. V_68 = V_68 ,
} ;
F_73 ( V_8 -> V_18 , F_69 , & V_48 ) ;
}
static void F_74 ( unsigned long V_48 )
{
struct V_2 * V_3 = (struct V_2 * ) V_48 ;
struct V_7 * V_8 ;
unsigned long V_67 = 0 ;
int V_9 , V_68 = 0 ;
F_75 (q, hctx, i)
F_72 ( V_8 , & V_67 , & V_68 ) ;
if ( V_68 )
F_76 ( & V_3 -> V_69 , F_77 ( V_67 ) ) ;
}
static bool F_78 ( struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_70 * V_70 )
{
struct V_13 * V_16 ;
int V_71 = 8 ;
F_79 (rq, &ctx->rq_list, queuelist) {
int V_72 ;
if ( ! V_71 -- )
break;
if ( ! F_80 ( V_16 , V_70 ) )
continue;
V_72 = F_81 ( V_16 , V_70 ) ;
if ( V_72 == V_73 ) {
if ( F_82 ( V_3 , V_16 , V_70 ) ) {
V_6 -> V_74 ++ ;
return true ;
}
break;
} else if ( V_72 == V_75 ) {
if ( F_83 ( V_3 , V_16 , V_70 ) ) {
V_6 -> V_74 ++ ;
return true ;
}
break;
}
}
return false ;
}
void F_84 ( struct V_13 * V_16 )
{
F_85 ( V_16 , NULL ) ;
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_42 ;
struct V_1 * V_6 ;
struct V_13 * V_16 ;
F_86 ( V_76 ) ;
int V_77 , V_78 ;
if ( F_61 ( F_9 ( V_79 , & V_8 -> V_80 ) ) )
return;
V_8 -> V_81 ++ ;
F_87 (bit, hctx->ctx_map, hctx->nr_ctx) {
F_68 ( V_77 , V_8 -> V_11 ) ;
V_6 = V_8 -> V_82 [ V_77 ] ;
F_88 ( V_77 != V_6 -> V_12 ) ;
F_89 ( & V_6 -> V_83 ) ;
F_90 ( & V_6 -> V_76 , & V_76 ) ;
F_91 ( & V_6 -> V_83 ) ;
}
if ( ! F_92 ( & V_8 -> V_84 ) ) {
F_89 ( & V_8 -> V_83 ) ;
if ( ! F_93 ( & V_8 -> V_84 ) )
F_94 ( & V_8 -> V_84 , & V_76 ) ;
F_91 ( & V_8 -> V_83 ) ;
}
V_78 = 0 ;
while ( ! F_93 ( & V_76 ) ) {
int V_21 ;
V_16 = F_95 ( & V_76 , struct V_13 , V_85 ) ;
F_96 ( & V_16 -> V_85 ) ;
F_64 ( V_16 , F_93 ( & V_76 ) ) ;
V_21 = V_3 -> V_39 -> V_86 ( V_8 , V_16 ) ;
switch ( V_21 ) {
case V_87 :
V_78 ++ ;
continue;
case V_88 :
F_97 ( & V_16 -> V_85 , & V_76 ) ;
F_66 ( V_16 ) ;
break;
default:
F_98 ( L_1 , V_21 ) ;
case V_89 :
V_16 -> V_90 = - V_91 ;
F_99 ( V_16 , V_16 -> V_90 ) ;
break;
}
if ( V_21 == V_88 )
break;
}
if ( ! V_78 )
V_8 -> V_92 [ 0 ] ++ ;
else if ( V_78 < ( 1 << ( V_93 - 1 ) ) )
V_8 -> V_92 [ F_100 ( V_78 ) + 1 ] ++ ;
if ( ! F_93 ( & V_76 ) ) {
F_89 ( & V_8 -> V_83 ) ;
F_101 ( & V_76 , & V_8 -> V_84 ) ;
F_91 ( & V_8 -> V_83 ) ;
}
}
void F_102 ( struct V_7 * V_8 , bool V_94 )
{
if ( F_61 ( F_9 ( V_79 , & V_8 -> V_80 ) ) )
return;
if ( ! V_94 )
F_41 ( V_8 ) ;
else {
struct V_2 * V_3 = V_8 -> V_42 ;
F_103 ( V_3 , & V_8 -> V_95 , 0 ) ;
}
}
void F_25 ( struct V_2 * V_3 , bool V_94 )
{
struct V_7 * V_8 ;
int V_9 ;
F_75 (q, hctx, i) {
if ( ( ! F_7 ( V_8 ) &&
F_92 ( & V_8 -> V_84 ) ) ||
F_9 ( V_79 , & V_8 -> V_80 ) )
continue;
F_102 ( V_8 , V_94 ) ;
}
}
void F_104 ( struct V_7 * V_8 )
{
F_105 ( & V_8 -> V_95 ) ;
F_10 ( V_79 , & V_8 -> V_80 ) ;
}
void F_106 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_9 ;
F_75 (q, hctx, i)
F_104 ( V_8 ) ;
}
void F_107 ( struct V_7 * V_8 )
{
F_68 ( V_79 , & V_8 -> V_80 ) ;
F_41 ( V_8 ) ;
}
void F_108 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_9 ;
F_75 (q, hctx, i) {
if ( ! F_9 ( V_79 , & V_8 -> V_80 ) )
continue;
F_68 ( V_79 , & V_8 -> V_80 ) ;
F_102 ( V_8 , true ) ;
}
}
static void F_109 ( struct V_96 * V_97 )
{
struct V_7 * V_8 ;
V_8 = F_110 ( V_97 , struct V_7 , V_95 . V_97 ) ;
F_41 ( V_8 ) ;
}
static void F_111 ( struct V_7 * V_8 ,
struct V_13 * V_16 , bool V_98 )
{
struct V_1 * V_6 = V_16 -> V_33 ;
F_112 ( V_8 -> V_42 , V_16 ) ;
if ( V_98 )
F_97 ( & V_16 -> V_85 , & V_6 -> V_76 ) ;
else
F_113 ( & V_16 -> V_85 , & V_6 -> V_76 ) ;
F_8 ( V_8 , V_6 ) ;
F_84 ( V_16 ) ;
}
void F_114 ( struct V_13 * V_16 , bool V_98 , bool V_99 ,
bool V_94 )
{
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_7 * V_8 ;
struct V_1 * V_6 = V_16 -> V_33 , * V_100 ;
V_100 = F_3 ( V_3 ) ;
if ( ! F_58 ( V_6 -> V_4 ) )
V_16 -> V_33 = V_6 = V_100 ;
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_6 -> V_4 ) ;
if ( V_16 -> V_34 & ( V_101 | V_102 ) &&
! ( V_16 -> V_34 & ( V_103 ) ) ) {
F_115 ( V_16 ) ;
} else {
F_89 ( & V_6 -> V_83 ) ;
F_111 ( V_8 , V_16 , V_98 ) ;
F_91 ( & V_6 -> V_83 ) ;
}
F_5 ( V_100 ) ;
if ( V_99 )
F_102 ( V_8 , V_94 ) ;
}
static void F_116 ( struct V_2 * V_3 ,
struct V_1 * V_6 ,
struct V_104 * V_105 ,
int V_106 ,
bool V_107 )
{
struct V_7 * V_8 ;
struct V_1 * V_100 ;
F_117 ( V_3 , V_106 , ! V_107 ) ;
V_100 = F_3 ( V_3 ) ;
if ( ! F_58 ( V_6 -> V_4 ) )
V_6 = V_100 ;
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_6 -> V_4 ) ;
F_89 ( & V_6 -> V_83 ) ;
while ( ! F_93 ( V_105 ) ) {
struct V_13 * V_16 ;
V_16 = F_95 ( V_105 , struct V_13 , V_85 ) ;
F_96 ( & V_16 -> V_85 ) ;
V_16 -> V_33 = V_6 ;
F_111 ( V_8 , V_16 , false ) ;
}
F_91 ( & V_6 -> V_83 ) ;
F_5 ( V_100 ) ;
F_102 ( V_8 , V_107 ) ;
}
static int F_118 ( void * V_108 , struct V_104 * V_109 , struct V_104 * V_110 )
{
struct V_13 * V_111 = F_110 ( V_109 , struct V_13 , V_85 ) ;
struct V_13 * V_112 = F_110 ( V_110 , struct V_13 , V_85 ) ;
return ! ( V_111 -> V_33 < V_112 -> V_33 ||
( V_111 -> V_33 == V_112 -> V_33 &&
F_119 ( V_111 ) < F_119 ( V_112 ) ) ) ;
}
void F_120 ( struct V_113 * V_114 , bool V_107 )
{
struct V_1 * V_115 ;
struct V_2 * V_116 ;
struct V_13 * V_16 ;
F_86 ( V_105 ) ;
F_86 ( V_117 ) ;
unsigned int V_106 ;
F_94 ( & V_114 -> V_118 , & V_105 ) ;
F_121 ( NULL , & V_105 , F_118 ) ;
V_116 = NULL ;
V_115 = NULL ;
V_106 = 0 ;
while ( ! F_93 ( & V_105 ) ) {
V_16 = F_122 ( V_105 . V_67 ) ;
F_96 ( & V_16 -> V_85 ) ;
F_88 ( ! V_16 -> V_3 ) ;
if ( V_16 -> V_33 != V_115 ) {
if ( V_115 ) {
F_116 ( V_116 , V_115 ,
& V_117 , V_106 ,
V_107 ) ;
}
V_115 = V_16 -> V_33 ;
V_116 = V_16 -> V_3 ;
V_106 = 0 ;
}
V_106 ++ ;
F_113 ( & V_16 -> V_85 , & V_117 ) ;
}
if ( V_115 ) {
F_116 ( V_116 , V_115 , & V_117 , V_106 ,
V_107 ) ;
}
}
static void F_123 ( struct V_13 * V_16 , struct V_70 * V_70 )
{
F_124 ( V_16 , V_70 ) ;
F_125 ( V_16 , 1 ) ;
}
static void F_126 ( struct V_2 * V_3 , struct V_70 * V_70 )
{
struct V_7 * V_8 ;
struct V_1 * V_6 ;
const int V_119 = F_39 ( V_70 -> V_120 ) ;
const int V_121 = V_70 -> V_120 & ( V_101 | V_102 ) ;
int V_38 = F_127 ( V_70 ) ;
struct V_13 * V_16 ;
unsigned int V_122 , V_123 = 0 ;
V_122 = ! V_121 && ( ( V_3 -> V_124 == 1 ) || ! V_119 ) ;
F_128 ( V_3 , & V_70 ) ;
if ( F_129 ( V_70 ) && F_130 ( V_70 ) ) {
F_131 ( V_70 , - V_91 ) ;
return;
}
if ( V_122 && F_132 ( V_3 , V_70 , & V_123 ) )
return;
if ( F_13 ( V_3 ) ) {
F_131 ( V_70 , - V_91 ) ;
return;
}
V_6 = F_3 ( V_3 ) ;
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_6 -> V_4 ) ;
if ( V_119 )
V_38 |= V_125 ;
F_133 ( V_3 , V_70 , V_38 ) ;
V_16 = F_11 ( V_8 , V_126 , false ) ;
if ( F_134 ( V_16 ) )
F_36 ( V_3 , V_6 , V_16 , V_38 ) ;
else {
F_5 ( V_6 ) ;
F_135 ( V_3 , V_70 , V_38 ) ;
V_16 = F_40 ( V_3 , V_38 , V_41 | V_126 ,
false ) ;
V_6 = V_16 -> V_33 ;
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_6 -> V_4 ) ;
}
V_8 -> V_78 ++ ;
if ( F_61 ( V_121 ) ) {
F_123 ( V_16 , V_70 ) ;
F_5 ( V_6 ) ;
F_115 ( V_16 ) ;
goto V_99;
}
if ( V_122 ) {
struct V_113 * V_114 = V_127 -> V_114 ;
if ( V_114 ) {
F_123 ( V_16 , V_70 ) ;
if ( F_93 ( & V_114 -> V_118 ) )
F_136 ( V_3 ) ;
else if ( V_123 >= V_128 ) {
F_137 ( V_114 , false ) ;
F_136 ( V_3 ) ;
}
F_113 ( & V_16 -> V_85 , & V_114 -> V_118 ) ;
F_5 ( V_6 ) ;
return;
}
}
F_89 ( & V_6 -> V_83 ) ;
if ( ( V_8 -> V_54 & V_129 ) &&
F_78 ( V_3 , V_6 , V_70 ) )
F_48 ( V_8 , V_6 , V_16 ) ;
else {
F_123 ( V_16 , V_70 ) ;
F_111 ( V_8 , V_16 , false ) ;
}
F_91 ( & V_6 -> V_83 ) ;
F_5 ( V_6 ) ;
V_99:
F_102 ( V_8 , ! V_119 || V_121 ) ;
}
struct V_7 * F_138 ( struct V_2 * V_3 , const int V_4 )
{
return V_3 -> V_130 [ V_3 -> V_131 [ V_4 ] ] ;
}
struct V_7 * F_139 ( struct V_132 * V_133 ,
unsigned int V_134 )
{
return F_140 ( sizeof( struct V_7 ) ,
V_135 | V_136 , V_133 -> V_137 ) ;
}
void F_141 ( struct V_7 * V_8 ,
unsigned int V_134 )
{
F_142 ( V_8 ) ;
}
static void F_143 ( void * V_48 , unsigned long V_138 ,
unsigned int V_4 )
{
struct V_7 * V_8 = V_48 ;
struct V_2 * V_3 = V_8 -> V_42 ;
struct V_1 * V_6 ;
F_86 ( V_139 ) ;
if ( V_138 != V_140 && V_138 != V_141 )
return;
V_6 = F_1 ( V_3 , V_4 ) ;
F_89 ( & V_6 -> V_83 ) ;
if ( ! F_93 ( & V_6 -> V_76 ) ) {
F_94 ( & V_6 -> V_76 , & V_139 ) ;
F_68 ( V_6 -> V_12 , V_8 -> V_11 ) ;
}
F_91 ( & V_6 -> V_83 ) ;
if ( F_93 ( & V_139 ) )
return;
V_6 = F_3 ( V_3 ) ;
F_89 ( & V_6 -> V_83 ) ;
while ( ! F_93 ( & V_139 ) ) {
struct V_13 * V_16 ;
V_16 = F_95 ( & V_139 , struct V_13 , V_85 ) ;
V_16 -> V_33 = V_6 ;
F_144 ( & V_16 -> V_85 , & V_6 -> V_76 ) ;
}
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_6 -> V_4 ) ;
F_8 ( V_8 , V_6 ) ;
F_91 ( & V_6 -> V_83 ) ;
F_5 ( V_6 ) ;
F_102 ( V_8 , true ) ;
}
static int F_145 ( struct V_7 * V_8 ,
int (* F_146)( void * , struct V_7 * ,
struct V_13 * , unsigned int ) ,
void * V_48 )
{
unsigned int V_9 ;
int V_21 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_66 ; V_9 ++ ) {
struct V_13 * V_16 = V_8 -> V_20 [ V_9 ] ;
V_21 = F_146 ( V_48 , V_8 , V_16 , V_9 ) ;
if ( V_21 )
break;
}
return V_21 ;
}
int F_147 ( struct V_2 * V_3 ,
int (* F_146)( void * , struct V_7 * ,
struct V_13 * , unsigned int ) ,
void * V_48 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
int V_21 = 0 ;
F_75 (q, hctx, i) {
V_21 = F_145 ( V_8 , F_146 , V_48 ) ;
if ( V_21 )
break;
}
return V_21 ;
}
static void F_148 ( struct V_7 * V_8 ,
void (* free)( void * , struct V_7 * ,
struct V_13 * , unsigned int ) ,
void * V_48 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_66 ; V_9 ++ ) {
struct V_13 * V_16 = V_8 -> V_20 [ V_9 ] ;
free ( V_48 , V_8 , V_16 , V_9 ) ;
}
}
void F_149 ( struct V_2 * V_3 ,
void (* free)( void * , struct V_7 * ,
struct V_13 * , unsigned int ) ,
void * V_48 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
F_75 (q, hctx, i)
F_148 ( V_8 , free , V_48 ) ;
}
static void F_150 ( struct V_7 * V_8 )
{
struct V_142 * V_142 ;
while ( ! F_93 ( & V_8 -> V_143 ) ) {
V_142 = F_95 ( & V_8 -> V_143 , struct V_142 , V_144 ) ;
F_96 ( & V_142 -> V_144 ) ;
F_151 ( V_142 , V_142 -> V_145 ) ;
}
F_142 ( V_8 -> V_20 ) ;
if ( V_8 -> V_18 )
F_152 ( V_8 -> V_18 ) ;
}
static T_3 F_153 ( unsigned int V_146 )
{
T_3 V_21 = V_147 ;
while ( V_146 -- )
V_21 *= 2 ;
return V_21 ;
}
static int F_154 ( struct V_7 * V_8 ,
unsigned int V_148 , int V_149 )
{
unsigned int V_9 , V_150 , V_151 , V_152 = 4 ;
T_3 V_153 , V_154 ;
F_155 ( & V_8 -> V_143 ) ;
V_8 -> V_20 = F_140 ( V_8 -> V_66 * sizeof( struct V_13 * ) ,
V_135 , V_149 ) ;
if ( ! V_8 -> V_20 )
return - V_155 ;
V_153 = F_156 ( sizeof( struct V_13 ) + V_8 -> V_43 ,
F_157 () ) ;
V_154 = V_153 * V_8 -> V_66 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_66 ; ) {
int V_156 = V_152 ;
struct V_142 * V_142 ;
int V_157 ;
void * V_158 ;
while ( V_154 < F_153 ( V_156 - 1 ) && V_156 )
V_156 -- ;
do {
V_142 = F_158 ( V_149 , V_135 , V_156 ) ;
if ( V_142 )
break;
if ( ! V_156 -- )
break;
if ( F_153 ( V_156 ) < V_153 )
break;
} while ( 1 );
if ( ! V_142 )
break;
V_142 -> V_145 = V_156 ;
F_113 ( & V_142 -> V_144 , & V_8 -> V_143 ) ;
V_158 = F_159 ( V_142 ) ;
V_151 = F_153 ( V_156 ) / V_153 ;
V_157 = F_160 ( V_151 , V_8 -> V_66 - V_9 ) ;
V_154 -= V_157 * V_153 ;
for ( V_150 = 0 ; V_150 < V_157 ; V_150 ++ ) {
V_8 -> V_20 [ V_9 ] = V_158 ;
F_45 ( V_8 , V_8 -> V_20 [ V_9 ] ) ;
V_158 += V_153 ;
V_9 ++ ;
}
}
if ( V_9 < ( V_148 + V_159 ) )
goto V_160;
else if ( V_9 != V_8 -> V_66 ) {
V_8 -> V_66 = V_9 ;
F_161 ( L_2 ,
V_161 , V_9 ) ;
}
V_8 -> V_18 = F_162 ( V_8 -> V_66 , V_148 , V_149 ) ;
if ( ! V_8 -> V_18 ) {
V_160:
F_150 ( V_8 ) ;
return - V_155 ;
}
return 0 ;
}
static int F_163 ( struct V_2 * V_3 ,
struct V_132 * V_133 , void * V_162 )
{
struct V_7 * V_8 ;
unsigned int V_9 , V_150 ;
F_75 (q, hctx, i) {
unsigned int V_163 ;
int V_149 ;
V_149 = V_8 -> V_137 ;
if ( V_149 == V_164 )
V_149 = V_8 -> V_137 = V_133 -> V_137 ;
F_164 ( & V_8 -> V_95 , F_109 ) ;
F_165 ( & V_8 -> V_83 ) ;
F_155 ( & V_8 -> V_84 ) ;
V_8 -> V_42 = V_3 ;
V_8 -> V_165 = V_9 ;
V_8 -> V_54 = V_133 -> V_54 ;
V_8 -> V_66 = V_133 -> V_66 ;
V_8 -> V_43 = V_133 -> V_43 ;
F_166 ( & V_8 -> V_166 ,
F_143 , V_8 ) ;
F_167 ( & V_8 -> V_166 ) ;
if ( F_154 ( V_8 , V_133 -> V_148 , V_149 ) )
break;
V_8 -> V_82 = F_140 ( V_167 * sizeof( void * ) ,
V_135 , V_149 ) ;
if ( ! V_8 -> V_82 )
break;
V_163 = F_168 ( V_167 , V_168 ) / V_168 ;
V_8 -> V_11 = F_169 ( V_163 * sizeof( unsigned long ) ,
V_135 , V_149 ) ;
if ( ! V_8 -> V_11 )
break;
V_8 -> V_10 = V_163 ;
V_8 -> V_169 = 0 ;
if ( V_133 -> V_170 -> V_171 &&
V_133 -> V_170 -> V_171 ( V_8 , V_162 , V_9 ) )
break;
}
if ( V_9 == V_3 -> V_124 )
return 0 ;
F_75 (q, hctx, j) {
if ( V_9 == V_150 )
break;
if ( V_133 -> V_170 -> V_172 )
V_133 -> V_170 -> V_172 ( V_8 , V_150 ) ;
F_170 ( & V_8 -> V_166 ) ;
F_150 ( V_8 ) ;
F_142 ( V_8 -> V_82 ) ;
}
return 1 ;
}
static void F_171 ( struct V_2 * V_3 ,
unsigned int V_124 )
{
unsigned int V_9 ;
F_172 (i) {
struct V_1 * V_173 = F_2 ( V_3 -> V_5 , V_9 ) ;
struct V_7 * V_8 ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_4 = V_9 ;
F_165 ( & V_173 -> V_83 ) ;
F_155 ( & V_173 -> V_76 ) ;
V_173 -> V_42 = V_3 ;
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_9 ) ;
V_8 -> V_169 ++ ;
if ( ! F_58 ( V_9 ) )
continue;
if ( V_124 > 1 && V_8 -> V_137 == V_164 )
V_8 -> V_137 = F_173 ( V_9 ) ;
}
}
static void F_174 ( struct V_2 * V_3 )
{
unsigned int V_9 ;
struct V_7 * V_8 ;
struct V_1 * V_6 ;
F_75 (q, hctx, i) {
V_8 -> V_169 = 0 ;
}
F_175 (q, ctx, i) {
V_8 = V_3 -> V_39 -> V_40 ( V_3 , V_9 ) ;
V_6 -> V_12 = V_8 -> V_169 ;
V_8 -> V_82 [ V_8 -> V_169 ++ ] = V_6 ;
}
}
struct V_2 * F_176 ( struct V_132 * V_133 ,
void * V_162 )
{
struct V_7 * * V_174 ;
struct V_1 * V_6 ;
struct V_2 * V_3 ;
int V_9 ;
if ( ! V_133 -> V_124 ||
! V_133 -> V_170 -> V_86 || ! V_133 -> V_170 -> V_40 ||
! V_133 -> V_170 -> V_175 || ! V_133 -> V_170 -> V_176 )
return F_177 ( - V_177 ) ;
if ( ! V_133 -> V_66 )
V_133 -> V_66 = V_178 ;
else if ( V_133 -> V_66 > V_178 ) {
F_98 ( L_3 , V_133 -> V_66 ) ;
V_133 -> V_66 = V_178 ;
}
if ( V_133 -> V_66 < ( V_133 -> V_148 + V_159 ) )
return F_177 ( - V_177 ) ;
V_6 = F_178 ( struct V_1 ) ;
if ( ! V_6 )
return F_177 ( - V_155 ) ;
V_174 = F_140 ( V_133 -> V_124 * sizeof( * V_174 ) , V_135 ,
V_133 -> V_137 ) ;
if ( ! V_174 )
goto V_179;
for ( V_9 = 0 ; V_9 < V_133 -> V_124 ; V_9 ++ ) {
V_174 [ V_9 ] = V_133 -> V_170 -> V_175 ( V_133 , V_9 ) ;
if ( ! V_174 [ V_9 ] )
goto V_180;
V_174 [ V_9 ] -> V_137 = V_164 ;
V_174 [ V_9 ] -> V_165 = V_9 ;
}
V_3 = F_179 ( V_135 , V_133 -> V_137 ) ;
if ( ! V_3 )
goto V_180;
V_3 -> V_131 = F_180 ( V_133 ) ;
if ( ! V_3 -> V_131 )
goto V_181;
F_181 ( & V_3 -> V_69 , F_74 , ( unsigned long ) V_3 ) ;
F_182 ( V_3 , 30000 ) ;
V_3 -> V_182 = V_167 ;
V_3 -> V_124 = V_133 -> V_124 ;
V_3 -> V_5 = V_6 ;
V_3 -> V_130 = V_174 ;
V_3 -> V_39 = V_133 -> V_170 ;
V_3 -> V_183 |= V_184 ;
V_3 -> V_185 = V_186 ;
F_183 ( V_3 , F_126 ) ;
F_184 ( V_3 , V_133 -> V_170 -> V_69 ) ;
if ( V_133 -> V_69 )
F_182 ( V_3 , V_133 -> V_69 ) ;
if ( V_133 -> V_170 -> V_187 )
F_185 ( V_3 , V_133 -> V_170 -> V_187 ) ;
F_186 ( V_3 ) ;
F_171 ( V_3 , V_133 -> V_124 ) ;
V_3 -> V_188 = F_187 ( F_156 ( sizeof( struct V_13 ) + V_133 -> V_43 ,
F_157 () ) , V_135 ) ;
if ( ! V_3 -> V_188 )
goto V_189;
if ( F_163 ( V_3 , V_133 , V_162 ) )
goto V_190;
F_174 ( V_3 ) ;
F_188 ( & V_191 ) ;
F_113 ( & V_3 -> V_192 , & V_193 ) ;
F_189 ( & V_191 ) ;
return V_3 ;
V_190:
F_142 ( V_3 -> V_188 ) ;
V_189:
F_142 ( V_3 -> V_131 ) ;
V_181:
F_190 ( V_3 ) ;
V_180:
for ( V_9 = 0 ; V_9 < V_133 -> V_124 ; V_9 ++ ) {
if ( ! V_174 [ V_9 ] )
break;
V_133 -> V_170 -> V_176 ( V_174 [ V_9 ] , V_9 ) ;
}
F_142 ( V_174 ) ;
V_179:
F_191 ( V_6 ) ;
return F_177 ( - V_155 ) ;
}
void F_192 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
int V_9 ;
F_75 (q, hctx, i) {
F_142 ( V_8 -> V_11 ) ;
F_142 ( V_8 -> V_82 ) ;
F_150 ( V_8 ) ;
F_170 ( & V_8 -> V_166 ) ;
if ( V_3 -> V_39 -> V_172 )
V_3 -> V_39 -> V_172 ( V_8 , V_9 ) ;
V_3 -> V_39 -> V_176 ( V_8 , V_9 ) ;
}
F_191 ( V_3 -> V_5 ) ;
F_142 ( V_3 -> V_130 ) ;
F_142 ( V_3 -> V_131 ) ;
V_3 -> V_5 = NULL ;
V_3 -> V_130 = NULL ;
V_3 -> V_131 = NULL ;
F_188 ( & V_191 ) ;
F_96 ( & V_3 -> V_192 ) ;
F_189 ( & V_191 ) ;
}
static void F_193 ( struct V_2 * V_3 )
{
F_27 ( V_3 ) ;
F_194 ( V_3 -> V_131 , V_3 -> V_124 ) ;
F_174 ( V_3 ) ;
F_30 ( V_3 ) ;
}
static int F_195 ( struct V_194 * V_195 ,
unsigned long V_138 , void * V_196 )
{
struct V_2 * V_3 ;
if ( V_138 != V_140 && V_138 != V_141 &&
V_138 != V_197 && V_138 != V_198 )
return V_199 ;
F_188 ( & V_191 ) ;
F_196 (q, &all_q_list, all_q_node)
F_193 ( V_3 ) ;
F_189 ( & V_191 ) ;
return V_199 ;
}
void F_197 ( void )
{
F_188 ( & V_191 ) ;
}
void F_198 ( void )
{
F_189 ( & V_191 ) ;
}
static int T_4 F_199 ( void )
{
F_200 () ;
F_201 ( F_195 , - 10 ) ;
return 0 ;
}
