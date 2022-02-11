static int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return F_2 ( V_4 -> V_5 == V_6 , V_4 -> V_7 == 0 ) &&
F_3 ( & V_4 -> V_8 ) >= V_4 -> V_7 &&
V_4 -> V_7 >= V_4 -> V_9 &&
V_4 -> V_7 >= 0 &&
V_4 -> V_9 >= 0 &&
V_4 -> V_10 >= 0 ;
}
static int F_4 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_11 ;
V_11 = F_3 ( & V_4 -> V_8 ) > 0 &&
F_1 ( V_2 , V_4 ) ;
if ( ! V_11 && V_2 != NULL )
F_5 ( V_12 , V_2 , V_4 , L_1 ) ;
return V_11 ;
}
static enum V_13 F_6 ( const struct V_3 * V_4 )
{
return F_7 ( V_4 -> V_14 . V_15 ) -> V_16 ;
}
static struct V_17 * F_8 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_18 * V_19 ;
enum V_13 V_20 ;
V_19 = F_9 ( V_2 ) ;
V_20 = F_6 ( V_4 ) ;
F_10 ( V_20 < F_11 ( V_19 -> V_21 ) ) ;
return & V_19 -> V_21 [ V_20 ] ;
}
static void F_12 ( int V_22 , const struct V_1 * V_2 ,
const char * V_23 , const struct V_3 * V_4 ,
const char * V_24 , const int line )
{
struct F_7 * V_25 = F_7 ( V_4 -> V_14 . V_15 ) ;
F_13 ( V_22 , L_2
L_3 ,
V_23 , V_4 , F_3 ( & V_4 -> V_8 ) ,
V_4 -> V_26 , V_4 -> V_10 ,
V_4 -> V_5 , V_4 -> V_27 , V_4 -> V_7 ,
V_4 -> V_9 , V_4 -> V_28 ,
V_2 , V_25 -> V_16 , F_14 ( V_2 ) ,
V_24 , line ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_16 ( V_4 , & V_29 , L_4 ) ;
}
static void F_17 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_30 )
{
F_8 ( V_2 , V_4 ) -> V_31 ++ ;
F_18 ( & V_4 -> V_32 ) ;
}
static void F_19 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_8 ( V_2 , V_4 ) -> V_31 -- ;
F_20 ( & V_4 -> V_32 , 0 , V_33 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{}
static void F_17 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_30 )
{}
static void F_19 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{}
void F_21 ( struct V_3 * V_4 , struct V_34 * V_35 ,
struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
V_40 ;
V_35 -> V_41 = V_4 ;
F_22 ( & V_35 -> V_42 , & V_4 -> V_43 ) ;
V_35 -> V_44 = V_37 ;
V_35 -> V_45 = V_39 ;
EXIT ;
}
int F_23 ( enum V_46 V_47 , enum V_46 V_48 )
{
F_24 ( V_48 == V_49 || V_48 == V_50 ||
V_48 == V_51 || V_48 == V_52 ) ;
F_24 ( V_47 == V_49 || V_47 == V_50 ||
V_47 == V_51 || V_47 == V_52 ) ;
F_25 ( V_51 < V_49 ) ;
F_25 ( V_49 < V_50 ) ;
F_25 ( V_50 < V_52 ) ;
if ( V_47 != V_52 )
return V_48 <= V_47 ;
else
return V_48 == V_47 ;
}
int F_26 ( const struct V_53 * V_47 ,
const struct V_53 * V_48 )
{
return
V_47 -> V_54 <= V_48 -> V_54 &&
V_47 -> V_55 >= V_48 -> V_55 &&
F_23 ( V_47 -> V_56 , V_48 -> V_56 ) &&
( V_47 -> V_56 != V_52 || V_47 -> V_57 == V_48 -> V_57 ) ;
}
int F_27 ( const struct V_53 * V_47 ,
const struct V_53 * V_48 )
{
return
F_28 ( V_47 -> V_15 , V_48 -> V_15 ) &&
F_26 ( V_47 , V_48 ) ;
}
static void F_29 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_14 . V_15 ;
F_24 ( ! F_30 ( V_4 ) ) ;
V_40 ;
F_31 ( V_58 , V_2 , L_5 , V_4 ) ;
F_32 () ;
while ( ! F_33 ( & V_4 -> V_43 ) ) {
struct V_34 * V_35 ;
V_35 = F_34 ( V_4 -> V_43 . V_59 ,
struct V_34 , V_42 ) ;
F_35 ( V_4 -> V_43 . V_59 ) ;
V_35 -> V_45 -> V_60 ( V_2 , V_35 ) ;
}
F_36 ( V_37 , V_61 ) ;
F_37 ( V_37 , V_4 -> V_5 ) ;
F_38 ( & V_37 -> V_62 , V_4 -> V_63 , L_6 , V_4 ) ;
F_39 ( V_2 , V_37 ) ;
F_40 ( & V_4 -> V_64 ) ;
F_40 ( & V_4 -> V_65 ) ;
F_41 ( & V_4 -> V_66 ) ;
F_42 ( V_4 , V_67 ) ;
EXIT ;
}
void F_43 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 * V_37 ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
V_37 = V_4 -> V_14 . V_15 ;
F_24 ( V_37 != NULL ) ;
F_13 ( V_68 , L_7 ,
F_3 ( & V_4 -> V_8 ) , V_4 , V_33 ) ;
if ( F_44 ( & V_4 -> V_8 ) ) {
if ( V_4 -> V_5 == V_6 ) {
F_10 ( F_33 ( & V_4 -> V_69 ) ) ;
F_29 ( V_2 , V_4 ) ;
}
F_36 ( V_37 , V_70 ) ;
}
EXIT ;
}
void F_45 ( struct V_3 * V_4 )
{
F_24 ( F_4 ( NULL , V_4 ) ) ;
F_13 ( V_68 , L_8 ,
F_3 ( & V_4 -> V_8 ) , V_4 , V_33 ) ;
F_46 ( & V_4 -> V_8 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
F_13 ( V_68 , L_9 ,
F_3 ( & V_4 -> V_8 ) , V_4 , V_33 ) ;
if ( F_48 ( & V_4 -> V_8 ) == 1 )
F_49 ( V_4 -> V_14 . V_15 , V_70 ) ;
}
static void F_50 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_51 ( V_2 , V_4 ) ;
F_52 ( V_2 , V_4 ) ;
F_53 ( V_2 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
}
static struct V_3 * F_55 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_71 * V_72 ,
const struct V_53 * V_73 )
{
struct V_3 * V_4 ;
struct V_74 * V_75 ;
V_40 ;
F_56 ( V_4 , V_67 , V_76 ) ;
if ( V_4 != NULL ) {
F_57 ( & V_4 -> V_8 , 1 ) ;
V_4 -> V_14 = * V_73 ;
V_4 -> V_5 = V_77 ;
F_58 ( V_37 ) ;
V_4 -> V_63 = F_59 ( & V_37 -> V_62 ,
L_6 , V_4 ) ;
F_60 ( & V_4 -> V_43 ) ;
F_60 ( & V_4 -> V_69 ) ;
F_60 ( & V_4 -> V_78 ) ;
F_61 ( & V_4 -> V_64 ) ;
F_61 ( & V_4 -> V_65 ) ;
F_62 ( & V_4 -> V_66 ) ;
F_63 ( & V_4 -> V_66 , & V_79 ) ;
F_64 ( & V_4 -> V_80 ) ;
V_75 = V_37 -> V_62 . V_81 ;
F_65 ( V_37 , V_77 ) ;
F_49 ( V_37 , V_61 ) ;
F_49 ( V_37 , V_82 ) ;
F_15 ( V_4 ) ;
F_66 (obj, &head->loh_layers,
co_lu.lo_linkage) {
int V_83 ;
V_83 = V_37 -> V_84 -> V_85 ( V_2 , V_37 , V_4 , V_72 ) ;
if ( V_83 != 0 ) {
F_50 ( V_2 , V_4 ) ;
V_4 = F_67 ( V_83 ) ;
break;
}
}
} else
V_4 = F_67 ( - V_86 ) ;
RETURN ( V_4 ) ;
}
enum V_87 F_68 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_87 V_88 = V_4 -> V_5 ;
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_88 != V_89 ) ;
F_69 ( V_88 >= V_90 && V_88 <= V_91 ,
L_10 , V_88 ) ;
F_70 ( V_2 , V_4 , V_89 ) ;
V_4 -> V_92 = V_93 ;
F_71 ( V_2 , V_4 , L_11 , V_93 ) ;
return V_88 ;
}
void F_72 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_87 V_88 )
{
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_4 -> V_5 == V_89 ) ;
F_10 ( V_88 != V_89 ) ;
F_10 ( V_4 -> V_92 == V_93 ) ;
V_4 -> V_92 = NULL ;
F_70 ( V_2 , V_4 , V_88 ) ;
F_73 ( V_2 , V_4 , L_11 , V_93 ) ;
}
int F_74 ( struct V_3 * V_4 )
{
F_10 ( F_30 ( V_4 ) ) ;
return V_4 -> V_5 == V_89 &&
V_4 -> V_92 != V_93 ;
}
static int F_75 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_53 * V_48 ,
const struct V_71 * V_72 )
{
const struct V_34 * V_35 ;
F_24 ( F_1 ( V_2 , V_4 ) ) ;
V_40 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_45 -> V_94 != NULL &&
! V_35 -> V_45 -> V_94 ( V_2 , V_35 , V_48 , V_72 ) )
RETURN ( 0 ) ;
}
RETURN ( 1 ) ;
}
static struct V_3 * F_76 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_71 * V_72 ,
const struct V_53 * V_48 )
{
struct V_3 * V_4 ;
struct F_7 * V_75 ;
V_40 ;
V_75 = F_7 ( V_37 ) ;
F_24 ( F_77 ( & V_75 -> V_95 ) ) ;
F_49 ( V_37 , V_96 ) ;
F_66 (lock, &head->coh_locks, cll_linkage) {
int V_97 ;
V_97 = F_26 ( & V_4 -> V_14 , V_48 ) &&
V_4 -> V_5 < V_6 &&
V_4 -> V_27 == 0 &&
! ( V_4 -> V_28 & V_98 ) &&
F_75 ( V_2 , V_4 , V_48 , V_72 ) ;
F_13 ( V_58 , L_12 V_99 L_13 V_99 L_14 ,
F_78 ( & V_4 -> V_14 ) , V_4 -> V_5 , F_78 ( V_48 ) ,
V_97 ) ;
if ( V_97 ) {
F_47 ( V_4 ) ;
F_49 ( V_37 , V_100 ) ;
RETURN ( V_4 ) ;
}
}
RETURN ( NULL ) ;
}
static struct V_3 * F_79 ( const struct V_1 * V_2 ,
const struct V_71 * V_72 ,
const struct V_53 * V_48 )
{
struct F_7 * V_75 ;
struct V_36 * V_37 ;
struct V_3 * V_4 ;
V_40 ;
V_37 = V_48 -> V_15 ;
V_75 = F_7 ( V_37 ) ;
F_80 ( & V_75 -> V_95 ) ;
V_4 = F_76 ( V_2 , V_37 , V_72 , V_48 ) ;
F_81 ( & V_75 -> V_95 ) ;
if ( V_4 == NULL ) {
V_4 = F_55 ( V_2 , V_37 , V_72 , V_48 ) ;
if ( ! F_82 ( V_4 ) ) {
struct V_3 * V_101 ;
F_80 ( & V_75 -> V_95 ) ;
V_101 = F_76 ( V_2 , V_37 , V_72 , V_48 ) ;
if ( V_101 == NULL ) {
F_22 ( & V_4 -> V_69 ,
& V_75 -> V_102 ) ;
F_81 ( & V_75 -> V_95 ) ;
F_49 ( V_37 , V_70 ) ;
} else {
F_81 ( & V_75 -> V_95 ) ;
F_50 ( V_2 , V_4 ) ;
V_4 = V_101 ;
}
}
}
RETURN ( V_4 ) ;
}
struct V_3 * F_83 ( const struct V_1 * V_2 , const struct V_71 * V_72 ,
const struct V_53 * V_48 ,
const char * V_103 , const void * V_104 )
{
struct F_7 * V_75 ;
struct V_36 * V_37 ;
struct V_3 * V_4 ;
V_37 = V_48 -> V_15 ;
V_75 = F_7 ( V_37 ) ;
do {
F_80 ( & V_75 -> V_95 ) ;
V_4 = F_76 ( V_2 , V_37 , V_72 , V_48 ) ;
F_81 ( & V_75 -> V_95 ) ;
if ( V_4 == NULL )
return NULL ;
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 == V_89 )
F_84 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 == V_6 ) {
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
V_4 = NULL ;
}
} while ( V_4 == NULL );
F_71 ( V_2 , V_4 , V_103 , V_104 ) ;
F_85 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 == V_91 )
F_86 ( V_2 , V_4 , 1 ) ;
if ( V_4 -> V_5 == V_105 ) {
F_54 ( V_2 , V_4 ) ;
F_17 ( V_2 , V_4 , 0 ) ;
F_43 ( V_2 , V_4 ) ;
} else {
F_87 ( V_2 , V_4 ) ;
F_73 ( V_2 , V_4 , V_103 , V_104 ) ;
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
const struct V_34 * F_88 ( const struct V_3 * V_4 ,
const struct V_106 * V_107 )
{
const struct V_34 * V_35 ;
F_24 ( F_1 ( NULL , V_4 ) ) ;
V_40 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_62 . V_108 -> V_109 == V_107 )
RETURN ( V_35 ) ;
}
RETURN ( NULL ) ;
}
static void F_89 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_110 ;
V_110 = F_8 ( V_2 , V_4 ) ;
V_4 -> V_10 ++ ;
V_110 -> V_111 ++ ;
F_90 ( & V_110 -> V_112 , L_15 , V_4 ) ;
F_31 ( V_68 , V_2 , L_16 , V_4 ) ;
}
void F_51 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
if ( V_4 -> V_26 == V_93 ) {
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( V_4 -> V_10 > 0 ) ;
} else {
struct F_7 * V_113 ;
struct V_18 * V_19 ;
int V_114 ;
F_24 ( V_4 -> V_26 != V_93 ) ;
V_113 = F_7 ( V_4 -> V_14 . V_15 ) ;
V_19 = F_9 ( V_2 ) ;
for ( V_114 = 0 ; V_114 < V_113 -> V_16 ; ++ V_114 )
F_10 ( V_19 -> V_21 [ V_114 ] . V_111 == 0 ) ;
F_91 ( & V_4 -> V_66 , V_113 -> V_16 ) ;
V_4 -> V_26 = V_93 ;
F_24 ( V_4 -> V_10 == 0 ) ;
}
F_89 ( V_2 , V_4 ) ;
}
int F_92 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
F_24 ( F_1 ( V_2 , V_4 ) ) ;
V_40 ;
V_11 = 0 ;
if ( V_4 -> V_26 == V_93 ) {
F_24 ( V_4 -> V_10 > 0 ) ;
F_89 ( V_2 , V_4 ) ;
} else if ( F_93 ( & V_4 -> V_66 ) ) {
F_24 ( V_4 -> V_10 == 0 ) ;
V_4 -> V_26 = V_93 ;
F_89 ( V_2 , V_4 ) ;
} else
V_11 = - V_115 ;
RETURN ( V_11 ) ;
}
void F_54 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_110 ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( V_4 -> V_26 == V_93 ) ;
F_24 ( V_4 -> V_10 > 0 ) ;
V_110 = F_8 ( V_2 , V_4 ) ;
F_24 ( V_110 -> V_111 > 0 ) ;
F_31 ( V_68 , V_2 , L_17 , V_4 ) ;
F_94 ( & V_110 -> V_112 , L_15 , V_4 ) ;
V_110 -> V_111 -- ;
if ( -- V_4 -> V_10 == 0 ) {
V_4 -> V_26 = NULL ;
F_95 ( & V_4 -> V_66 ) ;
}
}
int F_30 ( struct V_3 * V_4 )
{
return V_4 -> V_26 == V_93 ;
}
int F_14 ( const struct V_1 * V_2 )
{
struct V_18 * V_19 ;
int V_114 ;
int V_116 ;
V_19 = F_9 ( V_2 ) ;
for ( V_114 = 0 , V_116 = 0 ; V_114 < F_11 ( V_19 -> V_21 ) ; ++ V_114 )
V_116 += V_19 -> V_21 [ V_114 ] . V_111 ;
return V_116 ;
}
static void F_96 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
if ( ! ( V_4 -> V_28 & V_98 ) ) {
const struct V_34 * V_35 ;
V_4 -> V_28 |= V_98 ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_45 -> V_117 != NULL )
V_35 -> V_45 -> V_117 ( V_2 , V_35 ) ;
}
}
EXIT ;
}
static void F_98 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct F_7 * V_75 ;
const struct V_34 * V_35 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
if ( V_4 -> V_5 < V_6 ) {
F_10 ( V_4 -> V_5 != V_89 ) ;
F_70 ( V_2 , V_4 , V_6 ) ;
V_75 = F_7 ( V_4 -> V_14 . V_15 ) ;
F_80 ( & V_75 -> V_95 ) ;
F_35 ( & V_4 -> V_69 ) ;
F_81 ( & V_75 -> V_95 ) ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_45 -> V_118 != NULL )
V_35 -> V_45 -> V_118 ( V_2 , V_35 ) ;
}
}
EXIT ;
}
static void F_99 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
int V_119 )
{
struct V_17 * V_110 ;
enum V_13 V_20 ;
V_4 -> V_7 += V_119 ;
V_20 = F_6 ( V_4 ) ;
if ( V_20 == V_120 ) {
V_110 = & F_9 ( V_2 ) -> V_21 [ V_120 ] ;
V_110 -> V_121 += V_119 ;
F_10 ( V_110 -> V_121 >= 0 ) ;
}
}
static void F_100 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
int V_119 )
{
struct V_17 * V_110 ;
enum V_13 V_20 ;
V_4 -> V_9 += V_119 ;
V_20 = F_6 ( V_4 ) ;
if ( V_20 == V_120 ) {
V_110 = & F_9 ( V_2 ) -> V_21 [ V_120 ] ;
V_110 -> V_122 += V_119 ;
F_10 ( V_110 -> V_122 >= 0 ) ;
}
}
void F_101 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
V_40 ;
F_31 ( V_58 , V_2 , L_18 , V_4 ) ;
F_94 ( & V_4 -> V_65 , V_103 , V_104 ) ;
F_99 ( V_2 , V_4 , - 1 ) ;
if ( V_4 -> V_7 == 0 ) {
F_102 ( V_4 -> V_5 != V_105 , V_2 , V_4 ) ;
if ( V_4 -> V_14 . V_56 == V_51 ||
V_4 -> V_14 . V_56 == V_52 ||
V_4 -> V_5 != V_91 )
V_4 -> V_28 |= V_123 | V_124 ;
if ( V_4 -> V_28 & V_123 ) {
V_4 -> V_28 &= ~ V_123 ;
F_96 ( V_2 , V_4 ) ;
}
if ( V_4 -> V_28 & V_124 ) {
V_4 -> V_28 &= ~ V_124 ;
F_98 ( V_2 , V_4 ) ;
}
}
EXIT ;
}
int F_84 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_125 ;
T_3 V_126 ;
int V_11 ;
V_40 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_10 == 1 ) ;
F_10 ( V_4 -> V_5 != V_6 ) ;
F_31 ( V_58 , V_2 , L_19 , V_4 ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 == 0 ) {
V_126 = F_103 ( V_127 ) ;
F_104 ( & V_125 ) ;
F_105 ( & V_4 -> V_80 , & V_125 ) ;
F_106 ( V_128 ) ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
V_11 = - V_129 ;
if ( F_107 ( ! F_108 ( V_130 ) ) ) {
F_109 ( & V_125 , V_128 ) ;
if ( ! F_110 () )
V_11 = 0 ;
}
F_51 ( V_2 , V_4 ) ;
F_106 ( V_131 ) ;
F_111 ( & V_4 -> V_80 , & V_125 ) ;
F_112 ( V_126 ) ;
}
RETURN ( V_11 ) ;
}
static void F_113 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_87 V_88 )
{
const struct V_34 * V_35 ;
V_40 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_66 (slice, &lock->cll_layers, cls_linkage)
if ( V_35 -> V_45 -> V_132 != NULL )
V_35 -> V_45 -> V_132 ( V_2 , V_35 , V_88 ) ;
F_114 ( & V_4 -> V_80 ) ;
EXIT ;
}
void F_115 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
V_40 ;
F_31 ( V_58 , V_2 , L_20 , V_4 ) ;
F_113 ( V_2 , V_4 , V_4 -> V_5 ) ;
EXIT ;
}
void F_70 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_87 V_88 )
{
V_40 ;
F_10 ( V_4 -> V_5 <= V_88 ||
( V_4 -> V_5 == V_91 &&
( V_88 == V_105 ||
V_88 == V_77 ||
V_88 == V_89 ) ) ||
V_4 -> V_5 == V_89 ) ;
if ( V_4 -> V_5 != V_88 ) {
F_37 ( V_4 -> V_14 . V_15 , V_4 -> V_5 ) ;
F_65 ( V_4 -> V_14 . V_15 , V_88 ) ;
F_113 ( V_2 , V_4 , V_88 ) ;
V_4 -> V_5 = V_88 ;
}
EXIT ;
}
static int F_116 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
int V_11 ;
do {
V_11 = 0 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_5 == V_89 ) ;
V_11 = - V_133 ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_45 -> V_134 != NULL ) {
V_11 = V_35 -> V_45 -> V_134 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_133 ) ;
} while ( V_11 == V_135 );
return V_11 ;
}
int F_86 ( const struct V_1 * V_2 , struct V_3 * V_4 , int V_136 )
{
const struct V_34 * V_35 ;
int V_11 ;
enum V_87 V_88 ;
V_40 ;
F_31 ( V_58 , V_2 , L_21 , V_4 ) ;
F_10 ( V_4 -> V_5 == V_91 ) ;
if ( V_4 -> V_27 )
RETURN ( V_4 -> V_27 ) ;
V_11 = - V_133 ;
V_88 = F_68 ( V_2 , V_4 ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_45 -> V_137 != NULL ) {
V_11 = V_35 -> V_45 -> V_137 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_133 ) ;
F_69 ( V_4 -> V_5 == V_89 , L_22 ,
V_4 -> V_5 ) ;
if ( V_11 == 0 ) {
V_88 = V_105 ;
} else {
if ( V_11 == - V_138 ) {
V_88 = V_77 ;
V_11 = V_135 ;
}
if ( V_136 ) {
int V_139 ;
V_139 = F_116 ( V_2 , V_4 ) ;
if ( V_139 < 0 && V_11 > 0 )
V_11 = V_139 ;
}
}
F_72 ( V_2 , V_4 , V_88 ) ;
RETURN ( V_11 ) ;
}
static int F_117 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_71 * V_72 , T_1 V_140 )
{
int V_11 ;
const struct V_34 * V_35 ;
V_40 ;
V_11 = - V_133 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_45 -> V_141 != NULL ) {
V_11 = V_35 -> V_45 -> V_141 ( V_2 ,
V_35 , V_72 , V_140 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_133 ) ;
RETURN ( V_11 ) ;
}
int F_118 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_71 * V_72 , T_1 V_140 )
{
int V_11 ;
V_40 ;
F_31 ( V_58 , V_2 , L_23 , V_4 ) ;
do {
F_24 ( F_30 ( V_4 ) ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 != 0 )
break;
switch ( V_4 -> V_5 ) {
case V_77 :
F_70 ( V_2 , V_4 , V_142 ) ;
case V_142 :
V_11 = F_117 ( V_2 , V_4 , V_72 , V_140 ) ;
if ( V_11 == 0 && V_4 -> V_5 == V_142 )
F_70 ( V_2 , V_4 , V_90 ) ;
break;
case V_89 :
F_10 ( F_74 ( V_4 ) ) ;
V_11 = V_143 ;
break;
case V_91 :
V_11 = F_86 ( V_2 , V_4 , 0 ) ;
break;
case V_90 :
case V_105 :
V_11 = 0 ;
break;
default:
case V_6 :
F_119 () ;
}
} while ( V_11 == V_135 );
RETURN ( V_11 ) ;
}
int F_120 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_144 )
{
struct V_3 * V_145 ;
int V_139 = 0 ;
V_40 ;
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_4 -> V_5 == V_142 ) ;
F_10 ( V_4 -> V_146 != NULL ) ;
V_145 = V_4 -> V_146 ;
V_4 -> V_146 = NULL ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
F_51 ( V_2 , V_145 ) ;
F_31 ( V_58 , V_2 , L_24 , V_145 ) ;
F_52 ( V_2 , V_145 ) ;
F_53 ( V_2 , V_145 ) ;
while ( V_145 -> V_5 != V_6 ) {
V_139 = F_84 ( V_2 , V_145 ) ;
if ( V_139 != 0 )
break;
}
F_54 ( V_2 , V_145 ) ;
F_94 ( & V_145 -> V_64 , L_25 , V_4 ) ;
F_43 ( V_2 , V_145 ) ;
if ( V_144 )
F_51 ( V_2 , V_4 ) ;
F_10 ( V_139 <= 0 ) ;
RETURN ( V_139 ) ;
}
static int F_121 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_71 * V_72 , T_1 V_30 )
{
int V_11 ;
V_40 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
F_85 ( V_2 , V_4 ) ;
do {
V_11 = F_118 ( V_2 , V_4 , V_72 , V_30 ) ;
if ( V_11 == V_143 ) {
if ( V_4 -> V_146 != NULL )
V_11 = F_120 ( V_2 , V_4 , 1 ) ;
else
V_11 = F_84 ( V_2 , V_4 ) ;
if ( V_11 == 0 )
continue;
}
break;
} while ( 1 );
if ( V_11 != 0 )
F_87 ( V_2 , V_4 ) ;
F_10 ( F_2 ( V_11 == 0 && ! ( V_30 & V_147 ) ,
V_4 -> V_5 == V_90 ||
V_4 -> V_5 == V_105 ) ) ;
RETURN ( V_11 ) ;
}
int F_122 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_71 * V_72 , T_1 V_30 )
{
int V_11 ;
V_40 ;
F_17 ( V_2 , V_4 , V_30 ) ;
F_51 ( V_2 , V_4 ) ;
V_11 = F_121 ( V_2 , V_4 , V_72 , V_30 ) ;
F_54 ( V_2 , V_4 ) ;
if ( V_11 != 0 )
F_19 ( V_2 , V_4 ) ;
F_10 ( F_2 ( V_11 == 0 , V_4 -> V_5 == V_90 ||
V_4 -> V_5 == V_105 ) ) ;
RETURN ( V_11 ) ;
}
int F_87 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
enum V_87 V_88 = V_77 ;
V_40 ;
F_31 ( V_58 , V_2 , L_26 , V_4 ) ;
if ( V_4 -> V_9 > 1 ) {
F_123 ( V_2 , V_4 ) ;
RETURN ( 0 ) ;
}
if ( ! ( V_4 -> V_5 == V_105 || V_4 -> V_5 == V_90 ) ) {
F_123 ( V_2 , V_4 ) ;
RETURN ( 0 ) ;
}
V_88 = F_68 ( V_2 , V_4 ) ;
V_11 = F_116 ( V_2 , V_4 ) ;
F_10 ( V_4 -> V_5 == V_89 ) ;
F_10 ( V_11 != V_143 ) ;
F_123 ( V_2 , V_4 ) ;
if ( V_11 == 0 || V_11 == - V_138 ) {
if ( V_88 == V_105 && V_11 == 0 )
V_88 = V_91 ;
else
V_88 = V_77 ;
F_72 ( V_2 , V_4 , V_88 ) ;
V_11 = 0 ;
} else {
F_124 ( L_27 , V_11 ) ;
V_88 = V_77 ;
F_72 ( V_2 , V_4 , V_88 ) ;
}
RETURN ( V_11 ? : V_4 -> V_27 ) ;
}
static void F_125 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
V_40 ;
V_11 = F_87 ( V_2 , V_4 ) ;
if ( V_11 )
F_5 ( V_12 , V_2 , V_4 , L_28 , V_11 ) ;
EXIT ;
}
void F_126 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
V_40 ;
F_51 ( V_2 , V_4 ) ;
F_125 ( V_2 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_19 ( V_2 , V_4 ) ;
EXIT ;
}
int F_127 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
int V_11 ;
V_40 ;
F_31 ( V_58 , V_2 , L_29 , V_4 ) ;
do {
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_69 ( V_4 -> V_5 == V_142 ||
V_4 -> V_5 == V_90 ||
V_4 -> V_5 == V_105 ||
V_4 -> V_5 == V_89 ,
L_30 , V_4 -> V_5 ) ;
F_10 ( V_4 -> V_9 > 0 ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 != 0 )
break;
if ( F_74 ( V_4 ) ) {
V_11 = V_143 ;
break;
}
if ( V_4 -> V_5 == V_105 )
break;
V_11 = - V_133 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_45 -> V_148 != NULL ) {
V_11 = V_35 -> V_45 -> V_148 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_133 ) ;
if ( V_11 == 0 ) {
F_10 ( V_4 -> V_5 != V_89 ) ;
F_70 ( V_2 , V_4 , V_105 ) ;
}
} while ( V_11 == V_135 );
RETURN ( V_11 ) ;
}
int F_128 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
V_40 ;
F_51 ( V_2 , V_4 ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_69 ( V_4 -> V_5 == V_90 || V_4 -> V_5 == V_105 ,
L_31 , V_4 -> V_5 ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
do {
V_11 = F_127 ( V_2 , V_4 ) ;
if ( V_11 == V_143 ) {
V_11 = F_84 ( V_2 , V_4 ) ;
if ( V_11 == 0 )
continue;
}
break;
} while ( 1 );
if ( V_11 < 0 ) {
F_87 ( V_2 , V_4 ) ;
F_19 ( V_2 , V_4 ) ;
}
F_31 ( V_58 , V_2 , L_32 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_2 ( V_11 == 0 , V_4 -> V_5 == V_105 ) ) ;
RETURN ( V_11 ) ;
}
unsigned long F_129 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
unsigned long V_149 ;
unsigned long V_150 ;
V_40 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_149 = 0 ;
F_97 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_45 -> V_151 != NULL ) {
V_150 = V_35 -> V_45 -> V_151 ( V_2 , V_35 ) ;
V_149 += V_150 ;
if ( V_149 < V_150 )
V_149 = ~ 0UL ;
}
}
RETURN ( V_149 ) ;
}
int F_130 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_53 * V_152 )
{
const struct V_34 * V_35 ;
struct V_36 * V_37 = V_4 -> V_14 . V_15 ;
struct F_7 * V_113 = F_7 ( V_37 ) ;
int V_11 ;
V_40 ;
F_31 ( V_58 , V_2 , L_33 , V_4 ) ;
F_10 ( V_37 == V_152 -> V_15 ) ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_97 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_45 -> V_153 != NULL ) {
V_11 = V_35 -> V_45 -> V_153 ( V_2 , V_35 , V_152 ) ;
if ( V_11 != 0 )
RETURN ( V_11 ) ;
}
}
F_5 ( V_58 , V_2 , V_4 , L_34 V_99 L_35 V_154 L_36 ,
F_78 ( V_152 ) , F_131 ( F_132 ( & V_152 -> V_15 -> V_62 ) ) ) ;
F_80 ( & V_113 -> V_95 ) ;
V_4 -> V_14 = * V_152 ;
F_81 ( & V_113 -> V_95 ) ;
RETURN ( 0 ) ;
}
void F_133 ( const struct V_1 * V_2 ,
struct V_155 * V_156 ,
struct V_3 * V_157 , int V_158 )
{
F_24 ( F_30 ( V_157 ) ) ;
F_24 ( F_4 ( V_2 , V_157 ) ) ;
F_60 ( & V_156 -> V_159 ) ;
V_156 -> V_160 = V_157 ;
V_156 -> V_161 = V_158 ;
V_156 -> V_162 = 0 ;
}
int F_134 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_155 * V_156 )
{
const struct V_34 * V_35 ;
int V_11 ;
V_40 ;
F_24 ( F_30 ( V_156 -> V_160 ) ) ;
F_24 ( F_4 ( V_2 , V_156 -> V_160 ) ) ;
V_11 = F_135 ( V_2 , V_4 , V_156 ) ;
if ( V_11 == 0 ) {
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_45 -> V_163 != NULL ) {
V_11 = V_35 -> V_45 -> V_163 ( V_2 , V_35 ,
V_156 ) ;
if ( V_11 != 0 )
break;
}
}
}
if ( V_11 != 0 )
F_136 ( V_2 , V_156 ) ;
RETURN ( V_11 ) ;
}
int F_135 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_155 * V_156 )
{
int V_11 = 0 ;
V_40 ;
F_31 ( V_58 , V_2 , L_37 , V_4 ) ;
if ( ! F_92 ( V_2 , V_4 ) ) {
if ( F_33 ( & V_4 -> V_78 ) ) {
F_47 ( V_4 ) ;
F_90 ( & V_4 -> V_64 , L_38 , V_156 ) ;
F_137 ( & V_4 -> V_78 , & V_156 -> V_159 ) ;
V_156 -> V_162 ++ ;
} else
F_54 ( V_2 , V_4 ) ;
V_11 = 0 ;
} else {
F_136 ( V_2 , V_156 ) ;
if ( V_156 -> V_161 ) {
F_47 ( V_4 ) ;
F_90 ( & V_4 -> V_64 , L_39 , V_156 ) ;
F_54 ( V_2 , V_156 -> V_160 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
F_51 ( V_2 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_51 ( V_2 , V_156 -> V_160 ) ;
F_94 ( & V_4 -> V_64 , L_39 , V_156 ) ;
F_43 ( V_2 , V_4 ) ;
}
V_11 = V_135 ;
}
RETURN ( V_11 ) ;
}
void F_136 ( const struct V_1 * V_2 ,
struct V_155 * V_156 )
{
struct V_3 * V_164 ;
struct V_3 * V_165 ;
F_31 ( V_58 , V_2 , L_40 , V_156 -> V_160 ) ;
F_138 (scan, temp, &closure->clc_list,
cll_inclosure) {
F_35 ( & V_164 -> V_78 ) ;
F_54 ( V_2 , V_164 ) ;
F_94 ( & V_164 -> V_64 , L_38 , V_156 ) ;
F_43 ( V_2 , V_164 ) ;
V_156 -> V_162 -- ;
}
F_10 ( V_156 -> V_162 == 0 ) ;
}
void F_139 ( struct V_155 * V_156 )
{
F_10 ( V_156 -> V_162 == 0 ) ;
F_10 ( F_33 ( & V_156 -> V_159 ) ) ;
}
void F_53 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( F_2 ( F_6 ( V_4 ) == V_120 ,
F_14 ( V_2 ) == 1 ) ) ;
V_40 ;
F_31 ( V_58 , V_2 , L_41 , V_4 ) ;
if ( V_4 -> V_7 == 0 )
F_98 ( V_2 , V_4 ) ;
else
V_4 -> V_28 |= V_124 ;
EXIT ;
}
void F_140 ( const struct V_1 * V_2 , struct V_3 * V_4 , int error )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
if ( V_4 -> V_27 == 0 && error != 0 ) {
F_31 ( V_58 , V_2 , L_42 , V_4 ) ;
V_4 -> V_27 = error ;
F_115 ( V_2 , V_4 ) ;
F_52 ( V_2 , V_4 ) ;
F_53 ( V_2 , V_4 ) ;
}
EXIT ;
}
void F_52 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
F_31 ( V_58 , V_2 , L_43 , V_4 ) ;
if ( V_4 -> V_7 == 0 )
F_96 ( V_2 , V_4 ) ;
else
V_4 -> V_28 |= V_123 ;
EXIT ;
}
struct V_3 * F_141 ( const struct V_1 * V_2 ,
struct V_36 * V_37 , T_4 V_166 ,
struct V_3 * V_167 ,
int V_168 , int V_169 )
{
struct F_7 * V_75 ;
struct V_3 * V_164 ;
struct V_3 * V_4 ;
struct V_53 * V_48 ;
V_40 ;
V_75 = F_7 ( V_37 ) ;
V_48 = & F_9 ( V_2 ) -> V_170 ;
V_4 = NULL ;
V_48 -> V_56 = V_49 ;
V_48 -> V_54 = V_48 -> V_55 = V_166 ;
V_48 -> V_171 = 0 ;
F_80 ( & V_75 -> V_95 ) ;
F_66 (scan, &head->coh_locks, cll_linkage) {
if ( V_164 != V_167 &&
( V_164 -> V_14 . V_56 == V_52 ||
F_26 ( & V_164 -> V_14 , V_48 ) ) &&
V_164 -> V_5 >= V_105 &&
V_164 -> V_5 < V_6 &&
( V_169 || ! ( V_164 -> V_28 & V_98 ) ) &&
( V_168 || ! ( V_164 -> V_28 & V_123 ) ) ) {
F_47 ( V_164 ) ;
V_4 = V_164 ;
break;
}
}
F_81 ( & V_75 -> V_95 ) ;
RETURN ( V_4 ) ;
}
static T_4 F_142 ( struct V_172 * V_173 , struct V_3 * V_4 )
{
struct V_106 * V_107 ;
const struct V_174 * V_35 ;
V_107 = V_4 -> V_14 . V_15 -> V_62 . V_108 -> V_109 ;
V_35 = F_143 ( V_173 , V_107 ) ;
F_10 ( V_35 != NULL ) ;
return V_35 -> V_175 -> V_176 ;
}
static int F_144 ( const struct V_1 * V_2 , struct V_71 * V_72 ,
struct V_172 * V_173 , void * V_177 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_3 * V_4 = V_177 ;
T_4 V_166 = F_142 ( V_173 , V_4 ) ;
if ( V_166 >= V_19 -> V_178 ) {
struct V_3 * V_179 ;
V_179 = F_141 ( V_2 , V_4 -> V_14 . V_15 , V_166 ,
V_4 , 1 , 0 ) ;
if ( V_179 != NULL ) {
V_19 -> V_178 = V_179 -> V_14 . V_55 + 1 ;
if ( V_179 -> V_14 . V_55 == V_180 )
V_19 -> V_178 = V_180 ;
F_43 ( V_2 , V_179 ) ;
} else if ( F_145 ( V_2 , V_72 , V_173 ) == 0 ) {
F_146 ( V_2 , V_72 , V_173 ) ;
F_147 ( V_2 , V_72 , V_173 ) ;
F_148 ( V_2 , V_72 , V_173 ) ;
} else {
F_10 ( V_173 -> V_181 == V_182 ) ;
}
}
V_19 -> V_183 = V_166 + 1 ;
return V_184 ;
}
static int F_149 ( const struct V_1 * V_2 , struct V_71 * V_72 ,
struct V_172 * V_173 , void * V_177 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_3 * V_4 = V_177 ;
F_10 ( V_4 -> V_14 . V_56 >= V_50 ) ;
F_150 ( F_2 ( V_173 -> V_185 == V_186 ,
! F_151 ( F_152 ( V_2 , V_173 ) ) ) ) ;
F_150 ( F_2 ( V_173 -> V_185 == V_186 ,
! F_153 ( F_152 ( V_2 , V_173 ) ) ) ) ;
V_19 -> V_183 = F_142 ( V_173 , V_4 ) + 1 ;
if ( F_145 ( V_2 , V_72 , V_173 ) == 0 ) {
F_146 ( V_2 , V_72 , V_173 ) ;
F_147 ( V_2 , V_72 , V_173 ) ;
F_148 ( V_2 , V_72 , V_173 ) ;
} else {
F_10 ( V_173 -> V_181 == V_182 ) ;
}
return V_184 ;
}
int F_154 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_71 * V_72 = & V_19 -> V_187 ;
struct V_53 * V_73 = & V_4 -> V_14 ;
T_5 V_188 ;
int V_189 ;
int V_11 ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
V_72 -> V_190 = F_155 ( V_73 -> V_15 ) ;
V_72 -> V_191 = 1 ;
V_11 = F_156 ( V_2 , V_72 , V_192 , V_72 -> V_190 ) ;
if ( V_11 != 0 )
GOTO ( V_193 , V_11 ) ;
V_188 = V_73 -> V_56 == V_49 ? F_144 : F_149 ;
V_19 -> V_178 = V_19 -> V_183 = V_73 -> V_54 ;
do {
V_189 = F_157 ( V_2 , V_73 -> V_15 , V_72 ,
V_19 -> V_183 , V_73 -> V_55 ,
V_188 , ( void * ) V_4 ) ;
if ( V_19 -> V_183 > V_73 -> V_55 )
break;
if ( V_189 == V_194 )
F_158 () ;
} while ( V_189 != V_184 );
V_193:
F_159 ( V_2 , V_72 ) ;
RETURN ( V_11 ) ;
}
void F_160 ( const struct V_1 * V_2 , struct V_36 * V_37 , int V_195 )
{
struct F_7 * V_75 ;
struct V_3 * V_4 ;
V_40 ;
V_75 = F_7 ( V_37 ) ;
F_10 ( F_2 ( ! V_195 ,
V_75 -> V_196 . V_197 == NULL && V_75 -> V_198 == 0 ) ) ;
F_80 ( & V_75 -> V_95 ) ;
while ( ! F_33 ( & V_75 -> V_102 ) ) {
V_4 = F_161 ( V_75 -> V_102 . V_59 ,
struct V_3 , V_69 ) ;
F_47 ( V_4 ) ;
F_81 ( & V_75 -> V_95 ) ;
F_90 ( & V_4 -> V_64 , L_44 , V_93 ) ;
V_199:
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 < V_6 ) {
F_10 ( V_4 -> V_9 <= 1 ) ;
if ( F_162 ( V_4 -> V_9 == 1 ) ) {
struct V_200 V_201 = { 0 } ;
F_54 ( V_2 , V_4 ) ;
F_163 ( V_4 -> V_80 ,
V_4 -> V_9 == 0 ,
& V_201 ) ;
goto V_199;
}
if ( V_195 )
F_52 ( V_2 , V_4 ) ;
F_53 ( V_2 , V_4 ) ;
}
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_64 , L_44 , V_93 ) ;
F_43 ( V_2 , V_4 ) ;
F_80 ( & V_75 -> V_95 ) ;
}
F_81 ( & V_75 -> V_95 ) ;
EXIT ;
}
static struct V_3 * F_164 ( const struct V_1 * V_2 ,
const struct V_71 * V_72 ,
const struct V_53 * V_48 ,
const char * V_103 , const void * V_104 )
{
struct V_3 * V_4 ;
V_40 ;
while ( 1 ) {
V_4 = F_79 ( V_2 , V_72 , V_48 ) ;
if ( F_82 ( V_4 ) )
break;
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 < V_6 &&
! ( V_4 -> V_28 & V_98 ) ) {
F_99 ( V_2 , V_4 , + 1 ) ;
F_90 ( & V_4 -> V_65 , V_103 , V_104 ) ;
F_90 ( & V_4 -> V_64 , V_103 , V_104 ) ;
break;
}
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
}
RETURN ( V_4 ) ;
}
struct V_3 * F_165 ( const struct V_1 * V_2 , const struct V_71 * V_72 ,
const struct V_53 * V_48 ,
const char * V_103 , const void * V_104 )
{
struct V_3 * V_4 ;
V_40 ;
V_4 = F_164 ( V_2 , V_72 , V_48 , V_103 , V_104 ) ;
if ( ! F_82 ( V_4 ) )
F_54 ( V_2 , V_4 ) ;
RETURN ( V_4 ) ;
}
struct V_3 * F_166 ( const struct V_1 * V_2 , struct V_71 * V_72 ,
const struct V_53 * V_48 ,
const char * V_103 , const void * V_104 )
{
struct V_3 * V_4 ;
int V_139 ;
T_1 V_30 = V_48 -> V_171 ;
V_40 ;
do {
V_4 = F_164 ( V_2 , V_72 , V_48 , V_103 , V_104 ) ;
if ( F_82 ( V_4 ) )
break;
V_139 = F_121 ( V_2 , V_4 , V_72 , V_30 ) ;
if ( V_139 == 0 ) {
if ( F_75 ( V_2 , V_4 , V_48 , V_72 ) ) {
if ( ! ( V_30 & V_147 ) ) {
F_54 ( V_2 , V_4 ) ;
F_17 ( V_2 , V_4 ,
V_30 ) ;
break;
}
V_139 = 1 ;
}
F_125 ( V_2 , V_4 ) ;
}
F_31 ( V_58 , V_2 ,
V_139 <= 0 ? L_45 : L_46 , V_4 ) ;
F_101 ( V_2 , V_4 , V_103 , V_104 ) ;
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_64 , V_103 , V_104 ) ;
F_43 ( V_2 , V_4 ) ;
if ( V_139 > 0 ) {
F_10 ( V_30 & V_147 ) ;
V_4 = NULL ;
} else if ( V_139 != 0 ) {
V_4 = F_67 ( V_139 ) ;
}
} while ( V_139 == 0 );
RETURN ( V_4 ) ;
}
void F_71 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_5 != V_6 ) ;
V_40 ;
F_99 ( V_2 , V_4 , + 1 ) ;
F_45 ( V_4 ) ;
F_90 ( & V_4 -> V_65 , V_103 , V_104 ) ;
F_90 ( & V_4 -> V_64 , V_103 , V_104 ) ;
EXIT ;
}
void F_73 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
F_101 ( V_2 , V_4 , V_103 , V_104 ) ;
F_94 ( & V_4 -> V_64 , V_103 , V_104 ) ;
F_43 ( V_2 , V_4 ) ;
EXIT ;
}
void F_167 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
F_31 ( V_58 , V_2 , L_47 , V_4 ) ;
F_51 ( V_2 , V_4 ) ;
F_101 ( V_2 , V_4 , V_103 , V_104 ) ;
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_64 , V_103 , V_104 ) ;
F_43 ( V_2 , V_4 ) ;
EXIT ;
}
void F_85 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_40 ;
F_100 ( V_2 , V_4 , + 1 ) ;
EXIT ;
}
void F_123 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_9 > 0 ) ;
V_40 ;
F_100 ( V_2 , V_4 , - 1 ) ;
if ( V_4 -> V_9 == 0 )
F_114 ( & V_4 -> V_80 ) ;
EXIT ;
}
const char * F_168 ( const enum V_46 V_202 )
{
static const char * V_203 [] = {
[ V_51 ] = L_48 ,
[ V_49 ] = L_49 ,
[ V_50 ] = L_50 ,
[ V_52 ] = L_51
} ;
if ( 0 <= V_202 && V_202 < F_11 ( V_203 ) )
return V_203 [ V_202 ] ;
else
return L_52 ;
}
void F_169 ( const struct V_1 * V_2 , void * V_204 ,
T_6 V_205 ,
const struct V_53 * V_73 )
{
const struct V_206 * V_207 ;
V_207 = F_132 ( & V_73 -> V_15 -> V_62 ) ;
(* V_205)( V_2 , V_204 , V_99 L_35 V_154 , F_78 ( V_73 ) , F_131 ( V_207 ) ) ;
}
void F_170 ( const struct V_1 * V_2 , void * V_204 ,
T_6 V_205 , const struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
(* V_205)( V_2 , V_204 , L_53 ,
V_4 , F_3 ( & V_4 -> V_8 ) ,
V_4 -> V_5 , V_4 -> V_27 , V_4 -> V_7 ,
V_4 -> V_9 , V_4 -> V_28 ) ;
F_169 ( V_2 , V_204 , V_205 , & V_4 -> V_14 ) ;
(* V_205)( V_2 , V_204 , L_54 ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
(* V_205)( V_2 , V_204 , L_55 ,
V_35 -> V_44 -> V_62 . V_108 -> V_109 -> V_208 ,
V_35 ) ;
if ( V_35 -> V_45 -> V_209 != NULL )
V_35 -> V_45 -> V_209 ( V_2 , V_204 , V_205 , V_35 ) ;
(* V_205)( V_2 , V_204 , L_36 ) ;
}
(* V_205)( V_2 , V_204 , L_56 , V_4 ) ;
}
int F_171 ( void )
{
return F_172 ( V_210 ) ;
}
void F_173 ( void )
{
F_174 ( V_210 ) ;
}
