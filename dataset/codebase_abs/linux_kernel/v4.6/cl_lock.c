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
if ( ! V_11 && V_2 )
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
F_24 ( V_37 ) ;
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
V_4 = F_56 ( V_66 , V_75 ) ;
if ( V_4 ) {
F_57 ( & V_4 -> V_8 , 1 ) ;
V_4 -> V_14 = * V_72 ;
V_4 -> V_5 = V_76 ;
F_58 ( V_37 ) ;
F_59 ( & V_37 -> V_61 , & V_4 -> V_62 , L_5 ,
V_4 ) ;
F_60 ( & V_4 -> V_42 ) ;
F_60 ( & V_4 -> V_68 ) ;
F_60 ( & V_4 -> V_77 ) ;
F_61 ( & V_4 -> V_63 ) ;
F_61 ( & V_4 -> V_64 ) ;
F_62 ( & V_4 -> V_65 ) ;
F_63 ( & V_4 -> V_65 , & V_78 ) ;
F_64 ( & V_4 -> V_79 ) ;
V_74 = V_37 -> V_61 . V_80 ;
F_65 ( V_37 , V_76 ) ;
F_49 ( V_37 , V_60 ) ;
F_49 ( V_37 , V_81 ) ;
F_15 ( V_4 ) ;
F_66 (obj, &head->loh_layers, co_lu.lo_linkage) {
int V_82 ;
V_82 = V_37 -> V_83 -> V_84 ( V_2 , V_37 , V_4 , V_71 ) ;
if ( V_82 != 0 ) {
F_50 ( V_2 , V_4 ) ;
V_4 = F_67 ( V_82 ) ;
break;
}
}
} else
V_4 = F_67 ( - V_85 ) ;
return V_4 ;
}
static enum V_86 F_68 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
enum V_86 V_87 = V_4 -> V_5 ;
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_87 != V_88 ) ;
F_69 ( V_87 >= V_89 && V_87 <= V_90 ,
L_9 , V_87 ) ;
F_70 ( V_2 , V_4 , V_88 ) ;
V_4 -> V_91 = V_92 ;
F_71 ( V_2 , V_4 , L_10 , V_92 ) ;
return V_87 ;
}
static void F_72 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_86 V_87 )
{
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_4 -> V_5 == V_88 ) ;
F_10 ( V_87 != V_88 ) ;
F_10 ( V_4 -> V_91 == V_92 ) ;
V_4 -> V_91 = NULL ;
F_70 ( V_2 , V_4 , V_87 ) ;
F_73 ( V_2 , V_4 , L_10 , V_92 ) ;
}
int F_74 ( struct V_3 * V_4 )
{
F_10 ( F_30 ( V_4 ) ) ;
return V_4 -> V_5 == V_88 &&
V_4 -> V_91 != V_92 ;
}
static int F_75 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_52 * V_47 ,
const struct V_70 * V_71 )
{
const struct V_34 * V_35 ;
F_24 ( F_1 ( V_2 , V_4 ) ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_93 &&
! V_35 -> V_44 -> V_93 ( V_2 , V_35 , V_47 , V_71 ) )
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
F_77 ( & V_74 -> V_94 ) ;
F_49 ( V_37 , V_95 ) ;
F_66 (lock, &head->coh_locks, cll_linkage) {
int V_96 ;
V_96 = F_26 ( & V_4 -> V_14 , V_47 ) &&
V_4 -> V_5 < V_6 &&
V_4 -> V_27 == 0 &&
! ( V_4 -> V_28 & V_97 ) &&
F_75 ( V_2 , V_4 , V_47 , V_71 ) ;
F_13 ( V_57 , L_11 V_98 L_12 V_98 L_13 ,
F_78 ( & V_4 -> V_14 ) , V_4 -> V_5 , F_78 ( V_47 ) ,
V_96 ) ;
if ( V_96 ) {
F_47 ( V_4 ) ;
F_49 ( V_37 , V_99 ) ;
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
F_80 ( & V_74 -> V_94 ) ;
V_4 = F_76 ( V_2 , V_37 , V_71 , V_47 ) ;
F_81 ( & V_74 -> V_94 ) ;
if ( ! V_4 ) {
V_4 = F_55 ( V_2 , V_37 , V_71 , V_47 ) ;
if ( ! F_82 ( V_4 ) ) {
struct V_3 * V_100 ;
F_80 ( & V_74 -> V_94 ) ;
V_100 = F_76 ( V_2 , V_37 , V_71 , V_47 ) ;
if ( ! V_100 ) {
F_47 ( V_4 ) ;
F_22 ( & V_4 -> V_68 ,
& V_74 -> V_101 ) ;
F_81 ( & V_74 -> V_94 ) ;
F_49 ( V_37 , V_69 ) ;
} else {
F_81 ( & V_74 -> V_94 ) ;
F_50 ( V_2 , V_4 ) ;
V_4 = V_100 ;
}
}
}
return V_4 ;
}
struct V_3 * F_83 ( const struct V_1 * V_2 , const struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_102 , const void * V_103 )
{
struct F_7 * V_74 ;
struct V_36 * V_37 ;
struct V_3 * V_4 ;
V_37 = V_47 -> V_15 ;
V_74 = F_7 ( V_37 ) ;
do {
F_80 ( & V_74 -> V_94 ) ;
V_4 = F_76 ( V_2 , V_37 , V_71 , V_47 ) ;
F_81 ( & V_74 -> V_94 ) ;
if ( ! V_4 )
return NULL ;
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 == V_88 )
F_84 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 == V_6 ) {
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
V_4 = NULL ;
}
} while ( ! V_4 );
F_71 ( V_2 , V_4 , V_102 , V_103 ) ;
F_85 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 == V_90 )
F_86 ( V_2 , V_4 , 1 ) ;
if ( V_4 -> V_5 == V_104 ) {
F_54 ( V_2 , V_4 ) ;
F_17 ( V_2 , V_4 , 0 ) ;
F_43 ( V_2 , V_4 ) ;
} else {
F_87 ( V_2 , V_4 ) ;
F_73 ( V_2 , V_4 , V_102 , V_103 ) ;
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
const struct V_34 * F_88 ( const struct V_3 * V_4 ,
const struct V_105 * V_106 )
{
const struct V_34 * V_35 ;
F_24 ( F_1 ( NULL , V_4 ) ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_43 -> V_61 . V_107 -> V_108 == V_106 )
return V_35 ;
}
return NULL ;
}
static void F_89 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_109 ;
V_109 = F_8 ( V_2 , V_4 ) ;
V_4 -> V_10 ++ ;
V_109 -> V_110 ++ ;
F_90 ( & V_109 -> V_111 , L_14 , V_4 ) ;
F_31 ( V_67 , V_2 , L_15 , V_4 ) ;
}
void F_51 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
if ( V_4 -> V_26 == V_92 ) {
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( V_4 -> V_10 > 0 ) ;
} else {
struct F_7 * V_112 ;
struct V_18 * V_19 ;
int V_113 ;
F_24 ( V_4 -> V_26 != V_92 ) ;
V_112 = F_7 ( V_4 -> V_14 . V_15 ) ;
V_19 = F_9 ( V_2 ) ;
for ( V_113 = 0 ; V_113 < V_112 -> V_16 ; ++ V_113 )
F_10 ( V_19 -> V_21 [ V_113 ] . V_110 == 0 ) ;
F_91 ( & V_4 -> V_65 , V_112 -> V_16 ) ;
V_4 -> V_26 = V_92 ;
F_24 ( V_4 -> V_10 == 0 ) ;
}
F_89 ( V_2 , V_4 ) ;
}
static int F_92 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
F_24 ( F_1 ( V_2 , V_4 ) ) ;
V_11 = 0 ;
if ( V_4 -> V_26 == V_92 ) {
F_24 ( V_4 -> V_10 > 0 ) ;
F_89 ( V_2 , V_4 ) ;
} else if ( F_93 ( & V_4 -> V_65 ) ) {
F_24 ( V_4 -> V_10 == 0 ) ;
V_4 -> V_26 = V_92 ;
F_89 ( V_2 , V_4 ) ;
} else
V_11 = - V_114 ;
return V_11 ;
}
void F_54 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_109 ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( V_4 -> V_26 == V_92 ) ;
F_24 ( V_4 -> V_10 > 0 ) ;
V_109 = F_8 ( V_2 , V_4 ) ;
F_24 ( V_109 -> V_110 > 0 ) ;
F_31 ( V_67 , V_2 , L_16 , V_4 ) ;
F_94 ( & V_109 -> V_111 , L_14 , V_4 ) ;
V_109 -> V_110 -- ;
if ( -- V_4 -> V_10 == 0 ) {
V_4 -> V_26 = NULL ;
F_95 ( & V_4 -> V_65 ) ;
}
}
int F_30 ( struct V_3 * V_4 )
{
return V_4 -> V_26 == V_92 ;
}
int F_14 ( const struct V_1 * V_2 )
{
struct V_18 * V_19 ;
int V_113 ;
int V_115 ;
V_19 = F_9 ( V_2 ) ;
for ( V_113 = 0 , V_115 = 0 ; V_113 < F_11 ( V_19 -> V_21 ) ; ++ V_113 )
V_115 += V_19 -> V_21 [ V_113 ] . V_110 ;
return V_115 ;
}
static void F_96 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
if ( ! ( V_4 -> V_28 & V_97 ) ) {
const struct V_34 * V_35 ;
V_4 -> V_28 |= V_97 ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_44 -> V_116 )
V_35 -> V_44 -> V_116 ( V_2 , V_35 ) ;
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
bool V_117 ;
F_10 ( V_4 -> V_5 != V_88 ) ;
F_70 ( V_2 , V_4 , V_6 ) ;
V_74 = F_7 ( V_4 -> V_14 . V_15 ) ;
F_80 ( & V_74 -> V_94 ) ;
V_117 = ! F_33 ( & V_4 -> V_68 ) ;
if ( V_117 )
F_35 ( & V_4 -> V_68 ) ;
F_81 ( & V_74 -> V_94 ) ;
if ( V_117 )
F_43 ( V_2 , V_4 ) ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_44 -> V_118 )
V_35 -> V_44 -> V_118 ( V_2 , V_35 ) ;
}
}
}
static void F_99 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
int V_119 )
{
struct V_17 * V_109 ;
enum V_13 V_20 ;
V_4 -> V_7 += V_119 ;
V_20 = F_6 ( V_4 ) ;
if ( V_20 == V_120 ) {
V_109 = & F_9 ( V_2 ) -> V_21 [ V_120 ] ;
V_109 -> V_121 += V_119 ;
F_10 ( V_109 -> V_121 >= 0 ) ;
}
}
static void F_100 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
int V_119 )
{
struct V_17 * V_109 ;
enum V_13 V_20 ;
V_4 -> V_9 += V_119 ;
V_20 = F_6 ( V_4 ) ;
if ( V_20 == V_120 ) {
V_109 = & F_9 ( V_2 ) -> V_21 [ V_120 ] ;
V_109 -> V_122 += V_119 ;
F_10 ( V_109 -> V_122 >= 0 ) ;
}
}
void F_101 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_102 , const void * V_103 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
F_31 ( V_57 , V_2 , L_17 , V_4 ) ;
F_94 ( & V_4 -> V_64 , V_102 , V_103 ) ;
F_99 ( V_2 , V_4 , - 1 ) ;
if ( V_4 -> V_7 == 0 ) {
F_102 ( V_4 -> V_5 != V_104 , V_2 , V_4 ) ;
if ( V_4 -> V_14 . V_55 == V_50 ||
V_4 -> V_14 . V_55 == V_51 ||
V_4 -> V_5 != V_90 )
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
}
int F_84 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_125 ;
T_3 V_126 ;
int V_11 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_10 == 1 ) ;
F_10 ( V_4 -> V_5 != V_6 ) ;
F_31 ( V_57 , V_2 , L_18 , V_4 ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 == 0 ) {
V_126 = F_103 ( V_127 ) ;
F_104 ( & V_125 , V_92 ) ;
F_105 ( & V_4 -> V_79 , & V_125 ) ;
F_106 ( V_128 ) ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
V_11 = - V_129 ;
if ( F_107 ( ! F_108 ( V_130 ) ) ) {
F_109 () ;
if ( ! F_110 () )
V_11 = 0 ;
}
F_51 ( V_2 , V_4 ) ;
F_106 ( V_131 ) ;
F_111 ( & V_4 -> V_79 , & V_125 ) ;
F_112 ( V_126 ) ;
}
return V_11 ;
}
static void F_113 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_86 V_87 )
{
const struct V_34 * V_35 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_66 (slice, &lock->cll_layers, cls_linkage)
if ( V_35 -> V_44 -> V_132 )
V_35 -> V_44 -> V_132 ( V_2 , V_35 , V_87 ) ;
F_114 ( & V_4 -> V_79 ) ;
}
void F_115 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_31 ( V_57 , V_2 , L_19 , V_4 ) ;
F_113 ( V_2 , V_4 , V_4 -> V_5 ) ;
}
void F_70 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_86 V_87 )
{
F_10 ( V_4 -> V_5 <= V_87 ||
( V_4 -> V_5 == V_90 &&
( V_87 == V_104 ||
V_87 == V_76 ||
V_87 == V_88 ) ) ||
V_4 -> V_5 == V_88 ) ;
if ( V_4 -> V_5 != V_87 ) {
F_37 ( V_4 -> V_14 . V_15 , V_4 -> V_5 ) ;
F_65 ( V_4 -> V_14 . V_15 , V_87 ) ;
F_113 ( V_2 , V_4 , V_87 ) ;
V_4 -> V_5 = V_87 ;
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
F_10 ( V_4 -> V_5 == V_88 ) ;
V_11 = - V_133 ;
F_97 (slice, &lock->cll_layers,
cls_linkage) {
if ( V_35 -> V_44 -> V_134 ) {
V_11 = V_35 -> V_44 -> V_134 ( V_2 , V_35 ) ;
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
enum V_86 V_87 ;
F_31 ( V_57 , V_2 , L_20 , V_4 ) ;
F_10 ( V_4 -> V_5 == V_90 ) ;
if ( V_4 -> V_27 )
return V_4 -> V_27 ;
V_11 = - V_133 ;
V_87 = F_68 ( V_2 , V_4 ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_137 ) {
V_11 = V_35 -> V_44 -> V_137 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_133 ) ;
F_69 ( V_4 -> V_5 == V_88 , L_21 ,
V_4 -> V_5 ) ;
if ( V_11 == 0 ) {
V_87 = V_104 ;
} else {
if ( V_11 == - V_138 ) {
V_87 = V_76 ;
V_11 = V_135 ;
}
if ( V_136 ) {
int V_139 ;
V_139 = F_116 ( V_2 , V_4 ) ;
if ( V_139 < 0 && V_11 > 0 )
V_11 = V_139 ;
}
}
F_72 ( V_2 , V_4 , V_87 ) ;
return V_11 ;
}
static int F_117 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_70 * V_71 , T_1 V_140 )
{
int V_11 ;
const struct V_34 * V_35 ;
V_11 = - V_133 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_141 ) {
V_11 = V_35 -> V_44 -> V_141 ( V_2 ,
V_35 , V_71 , V_140 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_133 ) ;
return V_11 ;
}
int F_118 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_70 * V_71 , T_1 V_140 )
{
int V_11 ;
F_31 ( V_57 , V_2 , L_22 , V_4 ) ;
do {
F_24 ( F_30 ( V_4 ) ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 != 0 )
break;
switch ( V_4 -> V_5 ) {
case V_76 :
F_70 ( V_2 , V_4 , V_142 ) ;
case V_142 :
V_11 = F_117 ( V_2 , V_4 , V_71 , V_140 ) ;
if ( V_11 == 0 && V_4 -> V_5 == V_142 )
F_70 ( V_2 , V_4 , V_89 ) ;
break;
case V_88 :
F_10 ( F_74 ( V_4 ) ) ;
V_11 = V_143 ;
break;
case V_90 :
V_11 = F_86 ( V_2 , V_4 , 0 ) ;
break;
case V_89 :
case V_104 :
V_11 = 0 ;
break;
default:
case V_6 :
F_119 () ;
}
} while ( V_11 == V_135 );
return V_11 ;
}
int F_120 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_144 )
{
struct V_3 * V_145 ;
int V_139 = 0 ;
F_10 ( F_30 ( V_4 ) ) ;
F_10 ( V_4 -> V_5 == V_142 ) ;
F_10 ( V_4 -> V_146 ) ;
V_145 = V_4 -> V_146 ;
V_4 -> V_146 = NULL ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
F_51 ( V_2 , V_145 ) ;
F_31 ( V_57 , V_2 , L_23 , V_145 ) ;
F_52 ( V_2 , V_145 ) ;
F_53 ( V_2 , V_145 ) ;
while ( V_145 -> V_5 != V_6 ) {
V_139 = F_84 ( V_2 , V_145 ) ;
if ( V_139 != 0 )
break;
}
F_54 ( V_2 , V_145 ) ;
F_94 ( & V_145 -> V_63 , L_24 , V_4 ) ;
F_43 ( V_2 , V_145 ) ;
if ( V_144 )
F_51 ( V_2 , V_4 ) ;
F_10 ( V_139 <= 0 ) ;
return V_139 ;
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
if ( V_11 == V_143 ) {
if ( V_4 -> V_146 )
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
V_4 -> V_5 == V_89 ||
V_4 -> V_5 == V_104 ) ) ;
return V_11 ;
}
int F_87 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
enum V_86 V_87 = V_76 ;
F_31 ( V_57 , V_2 , L_25 , V_4 ) ;
if ( V_4 -> V_9 > 1 ) {
F_122 ( V_2 , V_4 ) ;
return 0 ;
}
if ( ! ( V_4 -> V_5 == V_104 || V_4 -> V_5 == V_89 ) ) {
F_122 ( V_2 , V_4 ) ;
return 0 ;
}
V_87 = F_68 ( V_2 , V_4 ) ;
V_11 = F_116 ( V_2 , V_4 ) ;
F_10 ( V_4 -> V_5 == V_88 ) ;
F_10 ( V_11 != V_143 ) ;
F_122 ( V_2 , V_4 ) ;
if ( V_11 == 0 || V_11 == - V_138 ) {
if ( V_87 == V_104 && V_11 == 0 )
V_87 = V_90 ;
else
V_87 = V_76 ;
F_72 ( V_2 , V_4 , V_87 ) ;
V_11 = 0 ;
} else {
F_123 ( L_26 , V_11 ) ;
V_87 = V_76 ;
F_72 ( V_2 , V_4 , V_87 ) ;
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
F_69 ( V_4 -> V_5 == V_142 ||
V_4 -> V_5 == V_89 ||
V_4 -> V_5 == V_104 ||
V_4 -> V_5 == V_88 ,
L_29 , V_4 -> V_5 ) ;
F_10 ( V_4 -> V_9 > 0 ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
V_11 = V_4 -> V_27 ;
if ( V_11 != 0 )
break;
if ( F_74 ( V_4 ) ) {
V_11 = V_143 ;
break;
}
if ( V_4 -> V_5 == V_104 )
break;
V_11 = - V_133 ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_148 ) {
V_11 = V_35 -> V_44 -> V_148 ( V_2 , V_35 ) ;
if ( V_11 != 0 )
break;
}
}
F_10 ( V_11 != - V_133 ) ;
if ( V_11 == 0 ) {
F_10 ( V_4 -> V_5 != V_88 ) ;
F_70 ( V_2 , V_4 , V_104 ) ;
}
} while ( V_11 == V_135 );
return V_11 ;
}
int F_127 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_11 ;
F_51 ( V_2 , V_4 ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_69 ( V_4 -> V_5 == V_89 || V_4 -> V_5 == V_104 ,
L_30 , V_4 -> V_5 ) ;
F_10 ( V_4 -> V_7 > 0 ) ;
do {
V_11 = F_126 ( V_2 , V_4 ) ;
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
F_31 ( V_57 , V_2 , L_31 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_10 ( F_2 ( V_11 == 0 , V_4 -> V_5 == V_104 ) ) ;
return V_11 ;
}
unsigned long F_128 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
unsigned long V_149 ;
unsigned long V_150 ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_149 = 0 ;
F_97 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_151 ) {
V_150 = V_35 -> V_44 -> V_151 ( V_2 , V_35 ) ;
V_149 += V_150 ;
if ( V_149 < V_150 )
V_149 = ~ 0UL ;
}
}
return V_149 ;
}
int F_129 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_52 * V_152 )
{
const struct V_34 * V_35 ;
struct V_36 * V_37 = V_4 -> V_14 . V_15 ;
struct F_7 * V_112 = F_7 ( V_37 ) ;
int V_11 ;
F_31 ( V_57 , V_2 , L_32 , V_4 ) ;
F_10 ( V_37 == V_152 -> V_15 ) ;
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_97 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_153 ) {
V_11 = V_35 -> V_44 -> V_153 ( V_2 , V_35 , V_152 ) ;
if ( V_11 != 0 )
return V_11 ;
}
}
F_5 ( V_57 , V_2 , V_4 , L_33 V_98 L_34 V_154 L_35 ,
F_78 ( V_152 ) , F_130 ( F_131 ( & V_152 -> V_15 -> V_61 ) ) ) ;
F_80 ( & V_112 -> V_94 ) ;
V_4 -> V_14 = * V_152 ;
F_81 ( & V_112 -> V_94 ) ;
return 0 ;
}
void F_132 ( const struct V_1 * V_2 ,
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
int F_133 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_155 * V_156 )
{
const struct V_34 * V_35 ;
int V_11 ;
F_24 ( F_30 ( V_156 -> V_160 ) ) ;
F_24 ( F_4 ( V_2 , V_156 -> V_160 ) ) ;
V_11 = F_134 ( V_2 , V_4 , V_156 ) ;
if ( V_11 == 0 ) {
F_66 (slice, &lock->cll_layers, cls_linkage) {
if ( V_35 -> V_44 -> V_163 ) {
V_11 = V_35 -> V_44 -> V_163 ( V_2 , V_35 ,
V_156 ) ;
if ( V_11 != 0 )
break;
}
}
}
if ( V_11 != 0 )
F_135 ( V_2 , V_156 ) ;
return V_11 ;
}
int F_134 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_155 * V_156 )
{
int V_11 = 0 ;
F_31 ( V_57 , V_2 , L_36 , V_4 ) ;
if ( ! F_92 ( V_2 , V_4 ) ) {
if ( F_33 ( & V_4 -> V_77 ) ) {
F_47 ( V_4 ) ;
F_90 ( & V_4 -> V_63 , L_37 , V_156 ) ;
F_136 ( & V_4 -> V_77 , & V_156 -> V_159 ) ;
V_156 -> V_162 ++ ;
} else
F_54 ( V_2 , V_4 ) ;
V_11 = 0 ;
} else {
F_135 ( V_2 , V_156 ) ;
if ( V_156 -> V_161 ) {
F_47 ( V_4 ) ;
F_90 ( & V_4 -> V_63 , L_38 , V_156 ) ;
F_54 ( V_2 , V_156 -> V_160 ) ;
F_10 ( F_14 ( V_2 ) == 0 ) ;
F_51 ( V_2 , V_4 ) ;
F_54 ( V_2 , V_4 ) ;
F_51 ( V_2 , V_156 -> V_160 ) ;
F_94 ( & V_4 -> V_63 , L_38 , V_156 ) ;
F_43 ( V_2 , V_4 ) ;
}
V_11 = V_135 ;
}
return V_11 ;
}
void F_135 ( const struct V_1 * V_2 ,
struct V_155 * V_156 )
{
struct V_3 * V_164 ;
struct V_3 * V_165 ;
F_31 ( V_57 , V_2 , L_39 , V_156 -> V_160 ) ;
F_137 (scan, temp, &closure->clc_list,
cll_inclosure) {
F_35 ( & V_164 -> V_77 ) ;
F_54 ( V_2 , V_164 ) ;
F_94 ( & V_164 -> V_63 , L_37 , V_156 ) ;
F_43 ( V_2 , V_164 ) ;
V_156 -> V_162 -- ;
}
F_10 ( V_156 -> V_162 == 0 ) ;
}
void F_138 ( struct V_155 * V_156 )
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
F_31 ( V_57 , V_2 , L_40 , V_4 ) ;
if ( V_4 -> V_7 == 0 )
F_98 ( V_2 , V_4 ) ;
else
V_4 -> V_28 |= V_124 ;
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
V_4 -> V_28 |= V_123 ;
}
struct V_3 * F_140 ( const struct V_1 * V_2 ,
struct V_36 * V_37 , T_4 V_166 ,
struct V_3 * V_167 ,
int V_168 , int V_169 )
{
struct F_7 * V_74 ;
struct V_3 * V_164 ;
struct V_3 * V_4 ;
struct V_52 * V_47 ;
V_74 = F_7 ( V_37 ) ;
V_47 = & F_9 ( V_2 ) -> V_170 ;
V_4 = NULL ;
V_47 -> V_55 = V_48 ;
V_47 -> V_53 = V_47 -> V_54 = V_166 ;
V_47 -> V_171 = 0 ;
F_80 ( & V_74 -> V_94 ) ;
F_66 (scan, &head->coh_locks, cll_linkage) {
if ( V_164 != V_167 &&
( V_164 -> V_14 . V_55 == V_51 ||
F_26 ( & V_164 -> V_14 , V_47 ) ) &&
V_164 -> V_5 >= V_104 &&
V_164 -> V_5 < V_6 &&
( V_169 || ! ( V_164 -> V_28 & V_97 ) ) &&
( V_168 || ! ( V_164 -> V_28 & V_123 ) ) ) {
F_47 ( V_164 ) ;
V_4 = V_164 ;
break;
}
}
F_81 ( & V_74 -> V_94 ) ;
return V_4 ;
}
static T_4 F_141 ( struct V_172 * V_173 , struct V_3 * V_4 )
{
struct V_105 * V_106 ;
const struct V_174 * V_35 ;
V_106 = V_4 -> V_14 . V_15 -> V_61 . V_107 -> V_108 ;
V_35 = F_142 ( V_173 , V_106 ) ;
return V_35 -> V_175 -> V_176 ;
}
static int F_143 ( const struct V_1 * V_2 , struct V_70 * V_71 ,
struct V_172 * V_173 , void * V_177 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_3 * V_4 = V_177 ;
T_4 V_166 = F_141 ( V_173 , V_4 ) ;
if ( V_166 >= V_19 -> V_178 ) {
struct V_3 * V_179 ;
V_179 = F_140 ( V_2 , V_4 -> V_14 . V_15 , V_166 ,
V_4 , 1 , 0 ) ;
if ( V_179 ) {
V_19 -> V_178 = V_179 -> V_14 . V_54 + 1 ;
if ( V_179 -> V_14 . V_54 == V_180 )
V_19 -> V_178 = V_180 ;
F_43 ( V_2 , V_179 ) ;
} else if ( F_144 ( V_2 , V_71 , V_173 ) == 0 ) {
F_145 ( V_2 , V_71 , V_173 ) ;
F_146 ( V_2 , V_71 , V_173 ) ;
F_147 ( V_2 , V_71 , V_173 ) ;
} else {
F_10 ( V_173 -> V_181 == V_182 ) ;
}
}
V_19 -> V_183 = V_166 + 1 ;
return V_184 ;
}
static int F_148 ( const struct V_1 * V_2 , struct V_70 * V_71 ,
struct V_172 * V_173 , void * V_177 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_3 * V_4 = V_177 ;
F_10 ( V_4 -> V_14 . V_55 >= V_49 ) ;
F_149 ( F_2 ( V_173 -> V_185 == V_186 ,
! F_150 ( F_151 ( V_2 , V_173 ) ) ) ) ;
F_149 ( F_2 ( V_173 -> V_185 == V_186 ,
! F_152 ( F_151 ( V_2 , V_173 ) ) ) ) ;
V_19 -> V_183 = F_141 ( V_173 , V_4 ) + 1 ;
if ( F_144 ( V_2 , V_71 , V_173 ) == 0 ) {
F_145 ( V_2 , V_71 , V_173 ) ;
F_146 ( V_2 , V_71 , V_173 ) ;
F_147 ( V_2 , V_71 , V_173 ) ;
} else {
F_10 ( V_173 -> V_181 == V_182 ) ;
}
return V_184 ;
}
int F_153 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_18 * V_19 = F_9 ( V_2 ) ;
struct V_70 * V_71 = & V_19 -> V_187 ;
struct V_52 * V_72 = & V_4 -> V_14 ;
T_5 V_188 ;
int V_189 ;
int V_11 ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
V_71 -> V_190 = F_154 ( V_72 -> V_15 ) ;
V_71 -> V_191 = 1 ;
V_11 = F_155 ( V_2 , V_71 , V_192 , V_71 -> V_190 ) ;
if ( V_11 != 0 )
goto V_193;
V_188 = V_72 -> V_55 == V_48 ? F_143 : F_148 ;
V_19 -> V_178 = V_19 -> V_183 = V_72 -> V_53 ;
do {
V_189 = F_156 ( V_2 , V_72 -> V_15 , V_71 ,
V_19 -> V_183 , V_72 -> V_54 ,
V_188 , ( void * ) V_4 ) ;
if ( V_19 -> V_183 > V_72 -> V_54 )
break;
if ( V_189 == V_194 )
F_157 () ;
} while ( V_189 != V_184 );
V_193:
F_158 ( V_2 , V_71 ) ;
return V_11 ;
}
void F_159 ( const struct V_1 * V_2 , struct V_36 * V_37 , int V_195 )
{
struct F_7 * V_74 ;
struct V_3 * V_4 ;
V_74 = F_7 ( V_37 ) ;
F_10 ( F_2 ( ! V_195 ,
! V_74 -> V_196 . V_197 && V_74 -> V_198 == 0 ) ) ;
F_80 ( & V_74 -> V_94 ) ;
while ( ! F_33 ( & V_74 -> V_101 ) ) {
V_4 = F_160 ( V_74 -> V_101 . V_58 ,
struct V_3 , V_68 ) ;
F_47 ( V_4 ) ;
F_81 ( & V_74 -> V_94 ) ;
F_90 ( & V_4 -> V_63 , L_43 , V_92 ) ;
V_199:
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 < V_6 ) {
F_10 ( V_4 -> V_9 <= 1 ) ;
if ( F_161 ( V_4 -> V_9 == 1 ) ) {
struct V_200 V_201 = { 0 } ;
F_54 ( V_2 , V_4 ) ;
F_162 ( V_4 -> V_79 ,
V_4 -> V_9 == 0 ,
& V_201 ) ;
goto V_199;
}
if ( V_195 )
F_52 ( V_2 , V_4 ) ;
F_53 ( V_2 , V_4 ) ;
}
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_63 , L_43 , V_92 ) ;
F_43 ( V_2 , V_4 ) ;
F_80 ( & V_74 -> V_94 ) ;
}
F_81 ( & V_74 -> V_94 ) ;
}
static struct V_3 * F_163 ( const struct V_1 * V_2 ,
const struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_102 , const void * V_103 )
{
struct V_3 * V_4 ;
while ( 1 ) {
V_4 = F_79 ( V_2 , V_71 , V_47 ) ;
if ( F_82 ( V_4 ) )
break;
F_51 ( V_2 , V_4 ) ;
if ( V_4 -> V_5 < V_6 &&
! ( V_4 -> V_28 & V_97 ) ) {
F_99 ( V_2 , V_4 , 1 ) ;
F_90 ( & V_4 -> V_64 , V_102 , V_103 ) ;
F_90 ( & V_4 -> V_63 , V_102 , V_103 ) ;
break;
}
F_54 ( V_2 , V_4 ) ;
F_43 ( V_2 , V_4 ) ;
}
return V_4 ;
}
struct V_3 * F_164 ( const struct V_1 * V_2 , const struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_102 , const void * V_103 )
{
struct V_3 * V_4 ;
V_4 = F_163 ( V_2 , V_71 , V_47 , V_102 , V_103 ) ;
if ( ! F_82 ( V_4 ) )
F_54 ( V_2 , V_4 ) ;
return V_4 ;
}
struct V_3 * F_165 ( const struct V_1 * V_2 , struct V_70 * V_71 ,
const struct V_52 * V_47 ,
const char * V_102 , const void * V_103 )
{
struct V_3 * V_4 ;
int V_139 ;
T_1 V_30 = V_47 -> V_171 ;
do {
V_4 = F_163 ( V_2 , V_71 , V_47 , V_102 , V_103 ) ;
if ( F_82 ( V_4 ) )
break;
V_139 = F_121 ( V_2 , V_4 , V_71 , V_30 ) ;
if ( V_139 == 0 ) {
if ( F_75 ( V_2 , V_4 , V_47 , V_71 ) ) {
if ( ! ( V_30 & V_147 ) ) {
F_54 ( V_2 , V_4 ) ;
F_17 ( V_2 , V_4 ,
V_30 ) ;
break;
}
V_139 = 1 ;
}
F_124 ( V_2 , V_4 ) ;
}
F_31 ( V_57 , V_2 ,
V_139 <= 0 ? L_44 : L_45 , V_4 ) ;
F_101 ( V_2 , V_4 , V_102 , V_103 ) ;
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_63 , V_102 , V_103 ) ;
F_43 ( V_2 , V_4 ) ;
if ( V_139 > 0 ) {
F_10 ( V_30 & V_147 ) ;
V_4 = NULL ;
} else if ( V_139 != 0 ) {
V_4 = F_67 ( V_139 ) ;
}
} while ( V_139 == 0 );
return V_4 ;
}
void F_71 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_102 , const void * V_103 )
{
F_24 ( F_30 ( V_4 ) ) ;
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_10 ( V_4 -> V_5 != V_6 ) ;
F_99 ( V_2 , V_4 , 1 ) ;
F_45 ( V_4 ) ;
F_90 ( & V_4 -> V_64 , V_102 , V_103 ) ;
F_90 ( & V_4 -> V_63 , V_102 , V_103 ) ;
}
void F_73 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_102 , const void * V_103 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_101 ( V_2 , V_4 , V_102 , V_103 ) ;
F_94 ( & V_4 -> V_63 , V_102 , V_103 ) ;
F_43 ( V_2 , V_4 ) ;
}
void F_166 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_102 , const void * V_103 )
{
F_24 ( F_4 ( V_2 , V_4 ) ) ;
F_31 ( V_57 , V_2 , L_46 , V_4 ) ;
F_51 ( V_2 , V_4 ) ;
F_101 ( V_2 , V_4 , V_102 , V_103 ) ;
F_54 ( V_2 , V_4 ) ;
F_94 ( & V_4 -> V_63 , V_102 , V_103 ) ;
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
F_114 ( & V_4 -> V_79 ) ;
}
const char * F_167 ( const enum V_45 V_202 )
{
static const char * V_203 [] = {
[ V_50 ] = L_47 ,
[ V_48 ] = L_48 ,
[ V_49 ] = L_49 ,
[ V_51 ] = L_50
} ;
if ( 0 <= V_202 && V_202 < F_11 ( V_203 ) )
return V_203 [ V_202 ] ;
else
return L_51 ;
}
void F_168 ( const struct V_1 * V_2 , void * V_204 ,
T_6 V_205 ,
const struct V_52 * V_72 )
{
const struct V_206 * V_207 ;
V_207 = F_131 ( & V_72 -> V_15 -> V_61 ) ;
(* V_205)( V_2 , V_204 , V_98 L_34 V_154 , F_78 ( V_72 ) , F_130 ( V_207 ) ) ;
}
void F_169 ( const struct V_1 * V_2 , void * V_204 ,
T_6 V_205 , const struct V_3 * V_4 )
{
const struct V_34 * V_35 ;
(* V_205)( V_2 , V_204 , L_52 ,
V_4 , F_3 ( & V_4 -> V_8 ) ,
V_4 -> V_5 , V_4 -> V_27 , V_4 -> V_7 ,
V_4 -> V_9 , V_4 -> V_28 ) ;
F_168 ( V_2 , V_204 , V_205 , & V_4 -> V_14 ) ;
(* V_205)( V_2 , V_204 , L_53 ) ;
F_66 (slice, &lock->cll_layers, cls_linkage) {
(* V_205)( V_2 , V_204 , L_54 ,
V_35 -> V_43 -> V_61 . V_107 -> V_108 -> V_208 ,
V_35 ) ;
if ( V_35 -> V_44 -> V_209 )
V_35 -> V_44 -> V_209 ( V_2 , V_204 , V_205 , V_35 ) ;
(* V_205)( V_2 , V_204 , L_35 ) ;
}
(* V_205)( V_2 , V_204 , L_55 , V_4 ) ;
}
int F_170 ( void )
{
return F_171 ( V_210 ) ;
}
void F_172 ( void )
{
F_173 ( V_210 ) ;
}
