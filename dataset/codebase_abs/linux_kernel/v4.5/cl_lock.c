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
F_13 ( V_22 , L_2 ,
V_23 , V_4 , F_3 ( & V_4 -> V_8 ) ,
V_4 -> V_26 , V_4 -> V_10 ,
V_4 -> V_5 , V_4 -> V_27 , V_4 -> V_7 ,
V_4 -> V_9 , V_4 -> V_28 ,
V_2 , V_25 -> V_16 , F_14 ( V_2 ) ,
V_24 , line ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
F_16 ( V_4 , & V_29 , L_3 ) ;
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
V_35 -> V_40 = V_4 ;
F_22 ( & V_35 -> V_41 , & V_4 -> V_42 ) ;
V_35 -> V_43 = V_37 ;
V_35 -> V_44 = V_39 ;
}
int F_23 ( enum V_45 V_46 , enum V_45 V_47 )
{
F_24 ( V_47 == V_48 || V_47 == V_49 ||
V_47 == V_50 || V_47 == V_51 ) ;
F_24 ( V_46 == V_48 || V_46 == V_49 ||
V_46 == V_50 || V_46 == V_51 ) ;
F_25 ( V_50 < V_48 ) ;
F_25 ( V_48 < V_49 ) ;
F_25 ( V_49 < V_51 ) ;
if ( V_46 != V_51 )
return V_47 <= V_46 ;
else
return V_47 == V_46 ;
}
int F_26 ( const struct V_52 * V_46 ,
const struct V_52 * V_47 )
{
return
V_46 -> V_53 <= V_47 -> V_53 &&
V_46 -> V_54 >= V_47 -> V_54 &&
F_23 ( V_46 -> V_55 , V_47 -> V_55 ) &&
( V_46 -> V_55 != V_51 || V_46 -> V_56 == V_47 -> V_56 ) ;
}
int F_27 ( const struct V_52 * V_46 ,
const struct V_52 * V_47 )
{
return
F_28 ( V_46 -> V_15 , V_47 -> V_15 ) &&
F_26 ( V_46 , V_47 ) ;
}
static void F_29 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_14 . V_15 ;
F_24 ( ! F_30 ( V_4 ) ) ;
F_31 ( V_57 , V_2 , L_4 , V_4 ) ;
F_32 () ;
while ( ! F_33 ( & V_4 -> V_42 ) ) {
struct V_34 * V_35 ;
V_35 = F_34 ( V_4 -> V_42 . V_58 ,
struct V_34 , V_41 ) ;
F_35 ( V_4 -> V_42 . V_58 ) ;
V_35 -> V_44 -> V_59 ( V_2 , V_35 ) ;
}
F_36 ( V_37 , V_60 ) ;
F_37 ( V_37 , V_4 -> V_5 ) ;
F_38 ( & V_37 -> V_61 , & V_4 -> V_62 , L_5 , V_4 ) ;
F_39 ( V_2 , V_37 ) ;
F_40 ( & V_4 -> V_63 ) ;
F_40 ( & V_4 -> V_64 ) ;
F_41 ( & V_4 -> V_65 ) ;
F_42 ( V_66 , V_4 ) ;
}
void F_43 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 * V_37 ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_37 = V_4 -> V_14 . V_15 ;
F_24 ( V_37 != NULL ) ;
F_13 ( V_67 , L_6 ,
F_3 ( & V_4 -> V_8 ) , V_4 , V_33 ) ;
if ( F_44 ( & V_4 -> V_8 ) ) {
if ( V_4 -> V_5 == V_6 ) {
F_10 ( F_33 ( & V_4 -> V_68 ) ) ;
F_29 ( V_2 , V_4 ) ;
}
F_36 ( V_37 , V_69 ) ;
}
}
void F_45 ( struct V_3 * V_4 )
{
F_24 ( F_4 ( NULL , V_4 ) ) ;
F_13 ( V_67 , L_7 ,
F_3 ( & V_4 -> V_8 ) , V_4 , V_33 ) ;
F_46 ( & V_4 -> V_8 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
F_13 ( V_67 , L_8 ,
F_3 ( & V_4 -> V_8 ) , V_4 , V_33 ) ;
if ( F_48 ( & V_4 -> V_8 ) == 1 )
F_49 ( V_4 -> V_14 . V_15 , V_69 ) ;
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
const struct V_70 * V_71 ,
const struct V_52 * V_72 )
{
struct V_3 * V_4 ;
struct V_73 * V_74 ;
V_4 = F_56 ( V_66 , V_75 | V_76 ) ;
if ( V_4 != NULL ) {
F_57 ( & V_4 -> V_8 , 1 ) ;
V_4 -> V_14 = * V_72 ;
V_4 -> V_5 = V_77 ;
F_58 ( V_37 ) ;
F_59 ( & V_37 -> V_61 , & V_4 -> V_62 , L_5 ,
V_4 ) ;
F_60 ( & V_4 -> V_42 ) ;
F_60 ( & V_4 -> V_68 ) ;
F_60 ( & V_4 -> V_78 ) ;
F_61 ( & V_4 -> V_63 ) ;
F_61 ( & V_4 -> V_64 ) ;
F_62 ( & V_4 -> V_65 ) ;
F_63 ( & V_4 -> V_65 , & V_79 ) ;
F_64 ( & V_4 -> V_80 ) ;
V_74 = V_37 -> V_61 . V_81 ;
F_65 ( V_37 , V_77 ) ;
F_49 ( V_37 , V_60 ) ;
F_49 ( V_37 , V_82 ) ;
F_15 ( V_4 ) ;
F_66 (obj, &head->loh_layers,
co_lu.lo_linkage) {
int V_83 ;
V_83 = V_37 -> V_84 -> V_85 ( V_2 , V_37 , V_4 , V_71 ) ;
if ( V_83 != 0 ) {
F_50 ( V_2 , V_4 ) ;
V_4 = F_67 ( V_83 ) ;
break;
}
}
} else
V_4 = F_67 ( - V_86 ) ;
return V_4 ;
}
static enum V_87 F_68 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_87 V_88 = V_4 -> V_5 ;
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_88 != V_89 ) ;
F_69 ( V_88 >= V_90 && V_88 <= V_91 ,
L_9 , V_88 ) ;
F_70 ( V_2 , V_4 , V_89 ) ;
V_4 -> V_92 = V_93 ;
F_71 ( V_2 , V_4 , L_10 , V_93 ) ;
return V_88 ;
}
static void F_72 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_87 V_88 )
{
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_4 -> V_5 == V_89 ) ;
F_10 ( V_88 != V_89 ) ;
F_10 ( V_4 -> V_92 == V_93 ) ;
V_4 -> V_92 = NULL ;
F_70 ( V_2 , V_4 , V_88 ) ;
F_73 ( V_2 , V_4 , L_10 , V_93 ) ;
}
int F_74 ( struct V_3 * V_4 )
{
F_10 ( F_30 ( V_4 ) ) ;
return V_4 -> V_5 == V_89 &&
V_4 -> V_92 != V_93 ;
}
static int F_75 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_52 * V_47 ,
const struct V_70 * V_71 )
{
const struct V_34 * V_35 ;
F_24 ( F_1 ( V_2 , V_4 ) ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_94 != NULL &&
! V_35 -> V_44 -> V_94 ( V_2 , V_35 , V_47 , V_71 ) )
return 0 ;
}
return 1 ;
}
static struct V_3 * F_76 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_70 * V_71 ,
const struct V_52 * V_47 )
{
struct V_3 * V_4 ;
struct F_7 * V_74 ;
V_74 = F_7 ( V_37 ) ;
F_77 ( & V_74 -> V_95 ) ;
F_49 ( V_37 , V_96 ) ;
F_66 (lock, &head->coh_locks, cll_linkage) {
int V_97 ;
V_97 = F_26 ( & V_4 -> V_14 , V_47 ) &&
V_4 -> V_5 < V_6 &&
V_4 -> V_27 == 0 &&
! ( V_4 -> V_28 & V_98 ) &&
F_75 ( V_2 , V_4 , V_47 , V_71 ) ;
F_13 ( V_57 , L_11 V_99 L_12 V_99 L_13 ,
F_78 ( & V_4 -> V_14 ) , V_4 -> V_5 , F_78 ( V_47 ) ,
V_97 ) ;
if ( V_97 ) {
F_47 ( V_4 ) ;
F_49 ( V_37 , V_100 ) ;
return V_4 ;
}
}
return NULL ;
}
static struct V_3 * F_79 ( const struct V_1 * V_2 ,
const struct V_70 * V_71 ,
const struct V_52 * V_47 )
{
struct F_7 * V_74 ;
struct V_36 * V_37 ;
struct V_3 * V_4 ;
V_37 = V_47 -> V_15 ;
V_74 = F_7 ( V_37 ) ;
F_80 ( & V_74 -> V_95 ) ;
V_4 = F_76 ( V_2 , V_37 , V_71 , V_47 ) ;
F_81 ( & V_74 -> V_95 ) ;
if ( V_4 == NULL ) {
V_4 = F_55 ( V_2 , V_37 , V_71 , V_47 ) ;
if ( ! F_82 ( V_4 ) ) {
struct V_3 * V_101 ;
F_80 ( & V_74 -> V_95 ) ;
V_101 = F_76 ( V_2 , V_37 , V_71 , V_47 ) ;
if ( V_101 == NULL ) {
F_47 ( V_4 ) ;
F_22 ( & V_4 -> V_68 ,
& V_74 -> V_102 ) ;
F_81 ( & V_74 -> V_95 ) ;
F_49 ( V_37 , V_69 ) ;
} else {
F_81 ( & V_74 -> V_95 ) ;
F_50 ( V_2 , V_4 ) ;
V_4 = V_101 ;
}
}
}
return V_4 ;
}
struct V_3 * F_83 ( const struct V_1 * V_2 , const struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_103 , const void * V_104 )
{
struct F_7 * V_74 ;
struct V_36 * V_37 ;
struct V_3 * V_4 ;
V_37 = V_47 -> V_15 ;
V_74 = F_7 ( V_37 ) ;
do {
F_80 ( & V_74 -> V_95 ) ;
V_4 = F_76 ( V_2 , V_37 , V_71 , V_47 ) ;
F_81 ( & V_74 -> V_95 ) ;
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
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_43 -> V_61 . V_108 -> V_109 == V_107 )
return V_35 ;
}
return NULL ;
}
static void F_89 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_110 ;
V_110 = F_8 ( V_2 , V_4 ) ;
V_4 -> V_10 ++ ;
V_110 -> V_111 ++ ;
F_90 ( & V_110 -> V_112 , L_14 , V_4 ) ;
F_31 ( V_67 , V_2 , L_15 , V_4 ) ;
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
F_91 ( & V_4 -> V_65 , V_113 -> V_16 ) ;
V_4 -> V_26 = V_93 ;
F_24 ( V_4 -> V_10 == 0 ) ;
}
F_89 ( V_2 , V_4 ) ;
}
static int F_92 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
F_24 ( F_1 ( V_2 , V_4 ) ) ;
V_11 = 0 ;
if ( V_4 -> V_26 == V_93 ) {
F_24 ( V_4 -> V_10 > 0 ) ;
F_89 ( V_2 , V_4 ) ;
} else if ( F_93 ( & V_4 -> V_65 ) ) {
F_24 ( V_4 -> V_10 == 0 ) ;
V_4 -> V_26 = V_93 ;
F_89 ( V_2 , V_4 ) ;
} else
V_11 = - V_115 ;
return V_11 ;
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
F_31 ( V_67 , V_2 , L_16 , V_4 ) ;
F_94 ( & V_110 -> V_112 , L_14 , V_4 ) ;
V_110 -> V_111 -- ;
if ( -- V_4 -> V_10 == 0 ) {
V_4 -> V_26 = NULL ;
F_95 ( & V_4 -> V_65 ) ;
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
if ( ! ( V_4 -> V_28 & V_98 ) ) {
const struct V_34 * V_35 ;
V_4 -> V_28 |= V_98 ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_44 -> V_117 != NULL )
V_35 -> V_44 -> V_117 ( V_2 , V_35 ) ;
}
}
}
static void F_98 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct F_7 * V_74 ;
const struct V_34 * V_35 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
if ( V_4 -> V_5 < V_6 ) {
bool V_118 ;
F_10 ( V_4 -> V_5 != V_89 ) ;
F_70 ( V_2 , V_4 , V_6 ) ;
V_74 = F_7 ( V_4 -> V_14 . V_15 ) ;
F_80 ( & V_74 -> V_95 ) ;
V_118 = ! F_33 ( & V_4 -> V_68 ) ;
if ( V_118 )
F_35 ( & V_4 -> V_68 ) ;
F_81 ( & V_74 -> V_95 ) ;
if ( V_118 )
F_43 ( V_2 , V_4 ) ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_44 -> V_119 != NULL )
V_35 -> V_44 -> V_119 ( V_2 , V_35 ) ;
}
}
}
static void F_99 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
int V_120 )
{
struct V_17 * V_110 ;
enum V_13 V_20 ;
V_4 -> V_7 += V_120 ;
V_20 = F_6 ( V_4 ) ;
if ( V_20 == V_121 ) {
V_110 = & F_9 ( V_2 ) -> V_21 [ V_121 ] ;
V_110 -> V_122 += V_120 ;
F_10 ( V_110 -> V_122 >= 0 ) ;
}
}
static void F_100 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
int V_120 )
{
struct V_17 * V_110 ;
enum V_13 V_20 ;
V_4 -> V_9 += V_120 ;
V_20 = F_6 ( V_4 ) ;
if ( V_20 == V_121 ) {
V_110 = & F_9 ( V_2 ) -> V_21 [ V_121 ] ;
V_110 -> V_123 += V_120 ;
F_10 ( V_110 -> V_123 >= 0 ) ;
}
}
void F_101 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
F_31 ( V_57 , V_2 , L_17 , V_4 ) ;
F_94 ( & V_4 -> V_64 , V_103 , V_104 ) ;
F_99 ( V_2 , V_4 , - 1 ) ;
if ( V_4 -> V_7 == 0 ) {
F_102 ( V_4 -> V_5 != V_105 , V_2 , V_4 ) ;
if ( V_4 -> V_14 . V_55 == V_50 ||
V_4 -> V_14 . V_55 == V_51 ||
V_4 -> V_5 != V_91 )
V_4 -> V_28 |= V_124 | V_125 ;
if ( V_4 -> V_28 & V_124 ) {
V_4 -> V_28 &= ~ V_124 ;
F_96 ( V_2 , V_4 ) ;
}
if ( V_4 -> V_28 & V_125 ) {
V_4 -> V_28 &= ~ V_125 ;
F_98 ( V_2 , V_4 ) ;
}
}
}
int F_84 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_126 ;
T_3 V_127 ;
int V_11 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_10 == 1 ) ;
F_10 ( V_4 -> V_5 != V_6 ) ;
F_31 ( V_57 , V_2 , L_18 , V_4 ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 == 0 ) {
V_127 = F_103 ( V_128 ) ;
F_104 ( & V_126 , V_93 ) ;
F_105 ( & V_4 -> V_80 , & V_126 ) ;
F_106 ( V_129 ) ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
V_11 = - V_130 ;
if ( F_107 ( ! F_108 ( V_131 ) ) ) {
F_109 () ;
if ( ! F_110 () )
V_11 = 0 ;
}
F_51 ( V_2 , V_4 ) ;
F_106 ( V_132 ) ;
F_111 ( & V_4 -> V_80 , & V_126 ) ;
F_112 ( V_127 ) ;
}
return V_11 ;
}
static void F_113 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_87 V_88 )
{
const struct V_34 * V_35 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_66 (slice, &lock->cll_layers, cls_linkage)
if ( V_35 -> V_44 -> V_133 != NULL )
V_35 -> V_44 -> V_133 ( V_2 , V_35 , V_88 ) ;
F_114 ( & V_4 -> V_80 ) ;
}
void F_115 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_31 ( V_57 , V_2 , L_19 , V_4 ) ;
F_113 ( V_2 , V_4 , V_4 -> V_5 ) ;
}
void F_70 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_87 V_88 )
{
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
V_11 = - V_134 ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_44 -> V_135 != NULL ) {
V_11 = V_35 -> V_44 -> V_135 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_134 ) ;
} while ( V_11 == V_136 );
return V_11 ;
}
int F_86 ( const struct V_1 * V_2 , struct V_3 * V_4 , int V_137 )
{
const struct V_34 * V_35 ;
int V_11 ;
enum V_87 V_88 ;
F_31 ( V_57 , V_2 , L_20 , V_4 ) ;
F_10 ( V_4 -> V_5 == V_91 ) ;
if ( V_4 -> V_27 )
return V_4 -> V_27 ;
V_11 = - V_134 ;
V_88 = F_68 ( V_2 , V_4 ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_138 != NULL ) {
V_11 = V_35 -> V_44 -> V_138 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_134 ) ;
F_69 ( V_4 -> V_5 == V_89 , L_21 ,
V_4 -> V_5 ) ;
if ( V_11 == 0 ) {
V_88 = V_105 ;
} else {
if ( V_11 == - V_139 ) {
V_88 = V_77 ;
V_11 = V_136 ;
}
if ( V_137 ) {
int V_140 ;
V_140 = F_116 ( V_2 , V_4 ) ;
if ( V_140 < 0 && V_11 > 0 )
V_11 = V_140 ;
}
}
F_72 ( V_2 , V_4 , V_88 ) ;
return V_11 ;
}
static int F_117 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_71 , T_1 V_141 )
{
int V_11 ;
const struct V_34 * V_35 ;
V_11 = - V_134 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_142 != NULL ) {
V_11 = V_35 -> V_44 -> V_142 ( V_2 ,
V_35 , V_71 , V_141 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_134 ) ;
return V_11 ;
}
int F_118 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_70 * V_71 , T_1 V_141 )
{
int V_11 ;
F_31 ( V_57 , V_2 , L_22 , V_4 ) ;
do {
F_24 ( F_30 ( V_4 ) ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 != 0 )
break;
switch ( V_4 -> V_5 ) {
case V_77 :
F_70 ( V_2 , V_4 , V_143 ) ;
case V_143 :
V_11 = F_117 ( V_2 , V_4 , V_71 , V_141 ) ;
if ( V_11 == 0 && V_4 -> V_5 == V_143 )
F_70 ( V_2 , V_4 , V_90 ) ;
break;
case V_89 :
F_10 ( F_74 ( V_4 ) ) ;
V_11 = V_144 ;
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
} while ( V_11 == V_136 );
return V_11 ;
}
int F_120 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_145 )
{
struct V_3 * V_146 ;
int V_140 = 0 ;
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_4 -> V_5 == V_143 ) ;
F_10 ( V_4 -> V_147 != NULL ) ;
V_146 = V_4 -> V_147 ;
V_4 -> V_147 = NULL ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
F_51 ( V_2 , V_146 ) ;
F_31 ( V_57 , V_2 , L_23 , V_146 ) ;
F_52 ( V_2 , V_146 ) ;
F_53 ( V_2 , V_146 ) ;
while ( V_146 -> V_5 != V_6 ) {
V_140 = F_84 ( V_2 , V_146 ) ;
if ( V_140 != 0 )
break;
}
F_54 ( V_2 , V_146 ) ;
F_94 ( & V_146 -> V_63 , L_24 , V_4 ) ;
F_43 ( V_2 , V_146 ) ;
if ( V_145 )
F_51 ( V_2 , V_4 ) ;
F_10 ( V_140 <= 0 ) ;
return V_140 ;
}
static int F_121 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_70 * V_71 , T_1 V_30 )
{
int V_11 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
F_85 ( V_2 , V_4 ) ;
do {
V_11 = F_118 ( V_2 , V_4 , V_71 , V_30 ) ;
if ( V_11 == V_144 ) {
if ( V_4 -> V_147 != NULL )
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
F_10 ( F_2 ( V_11 == 0 && ! ( V_30 & V_148 ) ,
V_4 -> V_5 == V_90 ||
V_4 -> V_5 == V_105 ) ) ;
return V_11 ;
}
int F_87 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
enum V_87 V_88 = V_77 ;
F_31 ( V_57 , V_2 , L_25 , V_4 ) ;
if ( V_4 -> V_9 > 1 ) {
F_122 ( V_2 , V_4 ) ;
return 0 ;
}
if ( ! ( V_4 -> V_5 == V_105 || V_4 -> V_5 == V_90 ) ) {
F_122 ( V_2 , V_4 ) ;
return 0 ;
}
V_88 = F_68 ( V_2 , V_4 ) ;
V_11 = F_116 ( V_2 , V_4 ) ;
F_10 ( V_4 -> V_5 == V_89 ) ;
F_10 ( V_11 != V_144 ) ;
F_122 ( V_2 , V_4 ) ;
if ( V_11 == 0 || V_11 == - V_139 ) {
if ( V_88 == V_105 && V_11 == 0 )
V_88 = V_91 ;
else
V_88 = V_77 ;
F_72 ( V_2 , V_4 , V_88 ) ;
V_11 = 0 ;
} else {
F_123 ( L_26 , V_11 ) ;
V_88 = V_77 ;
F_72 ( V_2 , V_4 , V_88 ) ;
}
return V_11 ? : V_4 -> V_27 ;
}
static void F_124 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
V_11 = F_87 ( V_2 , V_4 ) ;
if ( V_11 )
F_5 ( V_12 , V_2 , V_4 , L_27 , V_11 ) ;
}
void F_125 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_51 ( V_2 , V_4 ) ;
F_124 ( V_2 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_19 ( V_2 , V_4 ) ;
}
int F_126 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
int V_11 ;
F_31 ( V_57 , V_2 , L_28 , V_4 ) ;
do {
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_69 ( V_4 -> V_5 == V_143 ||
V_4 -> V_5 == V_90 ||
V_4 -> V_5 == V_105 ||
V_4 -> V_5 == V_89 ,
L_29 , V_4 -> V_5 ) ;
F_10 ( V_4 -> V_9 > 0 ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 != 0 )
break;
if ( F_74 ( V_4 ) ) {
V_11 = V_144 ;
break;
}
if ( V_4 -> V_5 == V_105 )
break;
V_11 = - V_134 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_149 != NULL ) {
V_11 = V_35 -> V_44 -> V_149 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_134 ) ;
if ( V_11 == 0 ) {
F_10 ( V_4 -> V_5 != V_89 ) ;
F_70 ( V_2 , V_4 , V_105 ) ;
}
} while ( V_11 == V_136 );
return V_11 ;
}
int F_127 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
F_51 ( V_2 , V_4 ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_69 ( V_4 -> V_5 == V_90 || V_4 -> V_5 == V_105 ,
L_30 , V_4 -> V_5 ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
do {
V_11 = F_126 ( V_2 , V_4 ) ;
if ( V_11 == V_144 ) {
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
F_31 ( V_57 , V_2 , L_31 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_2 ( V_11 == 0 , V_4 -> V_5 == V_105 ) ) ;
return V_11 ;
}
unsigned long F_128 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
unsigned long V_150 ;
unsigned long V_151 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_150 = 0 ;
F_97 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_152 != NULL ) {
V_151 = V_35 -> V_44 -> V_152 ( V_2 , V_35 ) ;
V_150 += V_151 ;
if ( V_150 < V_151 )
V_150 = ~ 0UL ;
}
}
return V_150 ;
}
int F_129 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_52 * V_153 )
{
const struct V_34 * V_35 ;
struct V_36 * V_37 = V_4 -> V_14 . V_15 ;
struct F_7 * V_113 = F_7 ( V_37 ) ;
int V_11 ;
F_31 ( V_57 , V_2 , L_32 , V_4 ) ;
F_10 ( V_37 == V_153 -> V_15 ) ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_97 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_154 != NULL ) {
V_11 = V_35 -> V_44 -> V_154 ( V_2 , V_35 , V_153 ) ;
if ( V_11 != 0 )
return V_11 ;
}
}
F_5 ( V_57 , V_2 , V_4 , L_33 V_99 L_34 V_155 L_35 ,
F_78 ( V_153 ) , F_130 ( F_131 ( & V_153 -> V_15 -> V_61 ) ) ) ;
F_80 ( & V_113 -> V_95 ) ;
V_4 -> V_14 = * V_153 ;
F_81 ( & V_113 -> V_95 ) ;
return 0 ;
}
void F_132 ( const struct V_1 * V_2 ,
struct V_156 * V_157 ,
struct V_3 * V_158 , int V_159 )
{
F_24 ( F_30 ( V_158 ) ) ;
F_24 ( F_4 ( V_2 , V_158 ) ) ;
F_60 ( & V_157 -> V_160 ) ;
V_157 -> V_161 = V_158 ;
V_157 -> V_162 = V_159 ;
V_157 -> V_163 = 0 ;
}
int F_133 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_156 * V_157 )
{
const struct V_34 * V_35 ;
int V_11 ;
F_24 ( F_30 ( V_157 -> V_161 ) ) ;
F_24 ( F_4 ( V_2 , V_157 -> V_161 ) ) ;
V_11 = F_134 ( V_2 , V_4 , V_157 ) ;
if ( V_11 == 0 ) {
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_164 != NULL ) {
V_11 = V_35 -> V_44 -> V_164 ( V_2 , V_35 ,
V_157 ) ;
if ( V_11 != 0 )
break;
}
}
}
if ( V_11 != 0 )
F_135 ( V_2 , V_157 ) ;
return V_11 ;
}
int F_134 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_156 * V_157 )
{
int V_11 = 0 ;
F_31 ( V_57 , V_2 , L_36 , V_4 ) ;
if ( ! F_92 ( V_2 , V_4 ) ) {
if ( F_33 ( & V_4 -> V_78 ) ) {
F_47 ( V_4 ) ;
F_90 ( & V_4 -> V_63 , L_37 , V_157 ) ;
F_136 ( & V_4 -> V_78 , & V_157 -> V_160 ) ;
V_157 -> V_163 ++ ;
} else
F_54 ( V_2 , V_4 ) ;
V_11 = 0 ;
} else {
F_135 ( V_2 , V_157 ) ;
if ( V_157 -> V_162 ) {
F_47 ( V_4 ) ;
F_90 ( & V_4 -> V_63 , L_38 , V_157 ) ;
F_54 ( V_2 , V_157 -> V_161 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
F_51 ( V_2 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_51 ( V_2 , V_157 -> V_161 ) ;
F_94 ( & V_4 -> V_63 , L_38 , V_157 ) ;
F_43 ( V_2 , V_4 ) ;
}
V_11 = V_136 ;
}
return V_11 ;
}
void F_135 ( const struct V_1 * V_2 ,
struct V_156 * V_157 )
{
struct V_3 * V_165 ;
struct V_3 * V_166 ;
F_31 ( V_57 , V_2 , L_39 , V_157 -> V_161 ) ;
F_137 (scan, temp, &closure->clc_list,
cll_inclosure) {
F_35 ( & V_165 -> V_78 ) ;
F_54 ( V_2 , V_165 ) ;
F_94 ( & V_165 -> V_63 , L_37 , V_157 ) ;
F_43 ( V_2 , V_165 ) ;
V_157 -> V_163 -- ;
}
F_10 ( V_157 -> V_163 == 0 ) ;
}
void F_138 ( struct V_156 * V_157 )
{
F_10 ( V_157 -> V_163 == 0 ) ;
F_10 ( F_33 ( & V_157 -> V_160 ) ) ;
}
void F_53 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( F_2 ( F_6 ( V_4 ) == V_121 ,
F_14 ( V_2 ) == 1 ) ) ;
F_31 ( V_57 , V_2 , L_40 , V_4 ) ;
if ( V_4 -> V_7 == 0 )
F_98 ( V_2 , V_4 ) ;
else
V_4 -> V_28 |= V_125 ;
}
void F_139 ( const struct V_1 * V_2 , struct V_3 * V_4 , int error )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
if ( V_4 -> V_27 == 0 && error != 0 ) {
F_31 ( V_57 , V_2 , L_41 , V_4 ) ;
V_4 -> V_27 = error ;
F_115 ( V_2 , V_4 ) ;
F_52 ( V_2 , V_4 ) ;
F_53 ( V_2 , V_4 ) ;
}
}
void F_52 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_31 ( V_57 , V_2 , L_42 , V_4 ) ;
if ( V_4 -> V_7 == 0 )
F_96 ( V_2 , V_4 ) ;
else
V_4 -> V_28 |= V_124 ;
}
struct V_3 * F_140 ( const struct V_1 * V_2 ,
struct V_36 * V_37 , T_4 V_167 ,
struct V_3 * V_168 ,
int V_169 , int V_170 )
{
struct F_7 * V_74 ;
struct V_3 * V_165 ;
struct V_3 * V_4 ;
struct V_52 * V_47 ;
V_74 = F_7 ( V_37 ) ;
V_47 = & F_9 ( V_2 ) -> V_171 ;
V_4 = NULL ;
V_47 -> V_55 = V_48 ;
V_47 -> V_53 = V_47 -> V_54 = V_167 ;
V_47 -> V_172 = 0 ;
F_80 ( & V_74 -> V_95 ) ;
F_66 (scan, &head->coh_locks, cll_linkage) {
if ( V_165 != V_168 &&
( V_165 -> V_14 . V_55 == V_51 ||
F_26 ( & V_165 -> V_14 , V_47 ) ) &&
V_165 -> V_5 >= V_105 &&
V_165 -> V_5 < V_6 &&
( V_170 || ! ( V_165 -> V_28 & V_98 ) ) &&
( V_169 || ! ( V_165 -> V_28 & V_124 ) ) ) {
F_47 ( V_165 ) ;
V_4 = V_165 ;
break;
}
}
F_81 ( & V_74 -> V_95 ) ;
return V_4 ;
}
static T_4 F_141 ( struct V_173 * V_174 , struct V_3 * V_4 )
{
struct V_106 * V_107 ;
const struct V_175 * V_35 ;
V_107 = V_4 -> V_14 . V_15 -> V_61 . V_108 -> V_109 ;
V_35 = F_142 ( V_174 , V_107 ) ;
F_10 ( V_35 != NULL ) ;
return V_35 -> V_176 -> V_177 ;
}
static int F_143 ( const struct V_1 * V_2 , struct V_70 * V_71 ,
struct V_173 * V_174 , void * V_178 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_3 * V_4 = V_178 ;
T_4 V_167 = F_141 ( V_174 , V_4 ) ;
if ( V_167 >= V_19 -> V_179 ) {
struct V_3 * V_180 ;
V_180 = F_140 ( V_2 , V_4 -> V_14 . V_15 , V_167 ,
V_4 , 1 , 0 ) ;
if ( V_180 != NULL ) {
V_19 -> V_179 = V_180 -> V_14 . V_54 + 1 ;
if ( V_180 -> V_14 . V_54 == V_181 )
V_19 -> V_179 = V_181 ;
F_43 ( V_2 , V_180 ) ;
} else if ( F_144 ( V_2 , V_71 , V_174 ) == 0 ) {
F_145 ( V_2 , V_71 , V_174 ) ;
F_146 ( V_2 , V_71 , V_174 ) ;
F_147 ( V_2 , V_71 , V_174 ) ;
} else {
F_10 ( V_174 -> V_182 == V_183 ) ;
}
}
V_19 -> V_184 = V_167 + 1 ;
return V_185 ;
}
static int F_148 ( const struct V_1 * V_2 , struct V_70 * V_71 ,
struct V_173 * V_174 , void * V_178 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_3 * V_4 = V_178 ;
F_10 ( V_4 -> V_14 . V_55 >= V_49 ) ;
F_149 ( F_2 ( V_174 -> V_186 == V_187 ,
! F_150 ( F_151 ( V_2 , V_174 ) ) ) ) ;
F_149 ( F_2 ( V_174 -> V_186 == V_187 ,
! F_152 ( F_151 ( V_2 , V_174 ) ) ) ) ;
V_19 -> V_184 = F_141 ( V_174 , V_4 ) + 1 ;
if ( F_144 ( V_2 , V_71 , V_174 ) == 0 ) {
F_145 ( V_2 , V_71 , V_174 ) ;
F_146 ( V_2 , V_71 , V_174 ) ;
F_147 ( V_2 , V_71 , V_174 ) ;
} else {
F_10 ( V_174 -> V_182 == V_183 ) ;
}
return V_185 ;
}
int F_153 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_70 * V_71 = & V_19 -> V_188 ;
struct V_52 * V_72 = & V_4 -> V_14 ;
T_5 V_189 ;
int V_190 ;
int V_11 ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_71 -> V_191 = F_154 ( V_72 -> V_15 ) ;
V_71 -> V_192 = 1 ;
V_11 = F_155 ( V_2 , V_71 , V_193 , V_71 -> V_191 ) ;
if ( V_11 != 0 )
goto V_194;
V_189 = V_72 -> V_55 == V_48 ? F_143 : F_148 ;
V_19 -> V_179 = V_19 -> V_184 = V_72 -> V_53 ;
do {
V_190 = F_156 ( V_2 , V_72 -> V_15 , V_71 ,
V_19 -> V_184 , V_72 -> V_54 ,
V_189 , ( void * ) V_4 ) ;
if ( V_19 -> V_184 > V_72 -> V_54 )
break;
if ( V_190 == V_195 )
F_157 () ;
} while ( V_190 != V_185 );
V_194:
F_158 ( V_2 , V_71 ) ;
return V_11 ;
}
void F_159 ( const struct V_1 * V_2 , struct V_36 * V_37 , int V_196 )
{
struct F_7 * V_74 ;
struct V_3 * V_4 ;
V_74 = F_7 ( V_37 ) ;
F_10 ( F_2 ( ! V_196 ,
V_74 -> V_197 . V_198 == NULL && V_74 -> V_199 == 0 ) ) ;
F_80 ( & V_74 -> V_95 ) ;
while ( ! F_33 ( & V_74 -> V_102 ) ) {
V_4 = F_160 ( V_74 -> V_102 . V_58 ,
struct V_3 , V_68 ) ;
F_47 ( V_4 ) ;
F_81 ( & V_74 -> V_95 ) ;
F_90 ( & V_4 -> V_63 , L_43 , V_93 ) ;
V_200:
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 < V_6 ) {
F_10 ( V_4 -> V_9 <= 1 ) ;
if ( F_161 ( V_4 -> V_9 == 1 ) ) {
struct V_201 V_202 = { 0 } ;
F_54 ( V_2 , V_4 ) ;
F_162 ( V_4 -> V_80 ,
V_4 -> V_9 == 0 ,
& V_202 ) ;
goto V_200;
}
if ( V_196 )
F_52 ( V_2 , V_4 ) ;
F_53 ( V_2 , V_4 ) ;
}
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_63 , L_43 , V_93 ) ;
F_43 ( V_2 , V_4 ) ;
F_80 ( & V_74 -> V_95 ) ;
}
F_81 ( & V_74 -> V_95 ) ;
}
static struct V_3 * F_163 ( const struct V_1 * V_2 ,
const struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_103 , const void * V_104 )
{
struct V_3 * V_4 ;
while ( 1 ) {
V_4 = F_79 ( V_2 , V_71 , V_47 ) ;
if ( F_82 ( V_4 ) )
break;
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 < V_6 &&
! ( V_4 -> V_28 & V_98 ) ) {
F_99 ( V_2 , V_4 , 1 ) ;
F_90 ( & V_4 -> V_64 , V_103 , V_104 ) ;
F_90 ( & V_4 -> V_63 , V_103 , V_104 ) ;
break;
}
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
}
return V_4 ;
}
struct V_3 * F_164 ( const struct V_1 * V_2 , const struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_103 , const void * V_104 )
{
struct V_3 * V_4 ;
V_4 = F_163 ( V_2 , V_71 , V_47 , V_103 , V_104 ) ;
if ( ! F_82 ( V_4 ) )
F_54 ( V_2 , V_4 ) ;
return V_4 ;
}
struct V_3 * F_165 ( const struct V_1 * V_2 , struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_103 , const void * V_104 )
{
struct V_3 * V_4 ;
int V_140 ;
T_1 V_30 = V_47 -> V_172 ;
do {
V_4 = F_163 ( V_2 , V_71 , V_47 , V_103 , V_104 ) ;
if ( F_82 ( V_4 ) )
break;
V_140 = F_121 ( V_2 , V_4 , V_71 , V_30 ) ;
if ( V_140 == 0 ) {
if ( F_75 ( V_2 , V_4 , V_47 , V_71 ) ) {
if ( ! ( V_30 & V_148 ) ) {
F_54 ( V_2 , V_4 ) ;
F_17 ( V_2 , V_4 ,
V_30 ) ;
break;
}
V_140 = 1 ;
}
F_124 ( V_2 , V_4 ) ;
}
F_31 ( V_57 , V_2 ,
V_140 <= 0 ? L_44 : L_45 , V_4 ) ;
F_101 ( V_2 , V_4 , V_103 , V_104 ) ;
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_63 , V_103 , V_104 ) ;
F_43 ( V_2 , V_4 ) ;
if ( V_140 > 0 ) {
F_10 ( V_30 & V_148 ) ;
V_4 = NULL ;
} else if ( V_140 != 0 ) {
V_4 = F_67 ( V_140 ) ;
}
} while ( V_140 == 0 );
return V_4 ;
}
void F_71 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_5 != V_6 ) ;
F_99 ( V_2 , V_4 , 1 ) ;
F_45 ( V_4 ) ;
F_90 ( & V_4 -> V_64 , V_103 , V_104 ) ;
F_90 ( & V_4 -> V_63 , V_103 , V_104 ) ;
}
void F_73 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_101 ( V_2 , V_4 , V_103 , V_104 ) ;
F_94 ( & V_4 -> V_63 , V_103 , V_104 ) ;
F_43 ( V_2 , V_4 ) ;
}
void F_166 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_103 , const void * V_104 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_31 ( V_57 , V_2 , L_46 , V_4 ) ;
F_51 ( V_2 , V_4 ) ;
F_101 ( V_2 , V_4 , V_103 , V_104 ) ;
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_63 , V_103 , V_104 ) ;
F_43 ( V_2 , V_4 ) ;
}
void F_85 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_100 ( V_2 , V_4 , 1 ) ;
}
void F_122 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_9 > 0 ) ;
F_100 ( V_2 , V_4 , - 1 ) ;
if ( V_4 -> V_9 == 0 )
F_114 ( & V_4 -> V_80 ) ;
}
const char * F_167 ( const enum V_45 V_203 )
{
static const char * V_204 [] = {
[ V_50 ] = L_47 ,
[ V_48 ] = L_48 ,
[ V_49 ] = L_49 ,
[ V_51 ] = L_50
} ;
if ( 0 <= V_203 && V_203 < F_11 ( V_204 ) )
return V_204 [ V_203 ] ;
else
return L_51 ;
}
void F_168 ( const struct V_1 * V_2 , void * V_205 ,
T_6 V_206 ,
const struct V_52 * V_72 )
{
const struct V_207 * V_208 ;
V_208 = F_131 ( & V_72 -> V_15 -> V_61 ) ;
(* V_206)( V_2 , V_205 , V_99 L_34 V_155 , F_78 ( V_72 ) , F_130 ( V_208 ) ) ;
}
void F_169 ( const struct V_1 * V_2 , void * V_205 ,
T_6 V_206 , const struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
(* V_206)( V_2 , V_205 , L_52 ,
V_4 , F_3 ( & V_4 -> V_8 ) ,
V_4 -> V_5 , V_4 -> V_27 , V_4 -> V_7 ,
V_4 -> V_9 , V_4 -> V_28 ) ;
F_168 ( V_2 , V_205 , V_206 , & V_4 -> V_14 ) ;
(* V_206)( V_2 , V_205 , L_53 ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
(* V_206)( V_2 , V_205 , L_54 ,
V_35 -> V_43 -> V_61 . V_108 -> V_109 -> V_209 ,
V_35 ) ;
if ( V_35 -> V_44 -> V_210 != NULL )
V_35 -> V_44 -> V_210 ( V_2 , V_205 , V_206 , V_35 ) ;
(* V_206)( V_2 , V_205 , L_35 ) ;
}
(* V_206)( V_2 , V_205 , L_55 , V_4 ) ;
}
int F_170 ( void )
{
return F_171 ( V_211 ) ;
}
void F_172 ( void )
{
F_173 ( V_211 ) ;
}
