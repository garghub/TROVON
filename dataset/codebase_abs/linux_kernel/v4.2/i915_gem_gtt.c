static int F_1 ( struct V_1 * V_2 , int V_3 )
{
bool V_4 ;
bool V_5 ;
V_4 = F_2 ( V_2 ) -> V_6 >= 6 ;
V_5 = F_2 ( V_2 ) -> V_6 >= 7 ;
if ( F_3 ( V_2 ) )
V_5 = false ;
if ( F_2 ( V_2 ) -> V_6 < 9 &&
( V_3 == 0 || ! V_4 ) )
return 0 ;
if ( V_3 == 1 )
return 1 ;
if ( V_3 == 2 && V_5 )
return 2 ;
#ifdef F_4
if ( F_2 ( V_2 ) -> V_6 == 6 && V_7 ) {
F_5 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_6 ( V_2 ) && ! F_7 ( V_2 ) &&
V_2 -> V_8 -> V_9 < 0xb ) {
F_8 ( L_2 ) ;
return 0 ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 && V_10 . V_11 )
return 2 ;
else
return V_4 ? 1 : 0 ;
}
static int F_9 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
T_1 V_16 )
{
T_1 V_17 = 0 ;
if ( V_13 -> V_18 -> V_19 )
V_17 |= V_20 ;
V_13 -> V_21 -> V_22 ( V_13 -> V_21 , V_13 -> V_18 -> V_23 , V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
return 0 ;
}
static void F_10 ( struct V_12 * V_13 )
{
V_13 -> V_21 -> V_26 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_18 -> V_27 . V_28 ,
true ) ;
}
static T_2 F_11 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 )
{
T_2 V_32 = V_31 ? V_33 | V_34 : 0 ;
V_32 |= V_29 ;
switch ( V_30 ) {
case V_35 :
V_32 |= V_36 ;
break;
case V_37 :
V_32 |= V_38 ;
break;
default:
V_32 |= V_39 ;
break;
}
return V_32 ;
}
static T_4 F_12 ( struct V_1 * V_2 ,
T_3 V_29 ,
enum V_14 V_30 )
{
T_4 V_40 = V_33 | V_34 ;
V_40 |= V_29 ;
if ( V_30 != V_35 )
V_40 |= V_41 ;
else
V_40 |= V_36 ;
return V_40 ;
}
static T_5 F_13 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_14 ( V_29 ) ;
switch ( V_30 ) {
case V_43 :
case V_44 :
V_32 |= V_45 ;
break;
case V_35 :
V_32 |= V_46 ;
break;
default:
F_15 ( V_30 ) ;
}
return V_32 ;
}
static T_5 F_16 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_14 ( V_29 ) ;
switch ( V_30 ) {
case V_43 :
V_32 |= V_47 ;
break;
case V_44 :
V_32 |= V_45 ;
break;
case V_35 :
V_32 |= V_46 ;
break;
default:
F_15 ( V_30 ) ;
}
return V_32 ;
}
static T_5 F_17 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_48 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_14 ( V_29 ) ;
if ( ! ( V_48 & V_20 ) )
V_32 |= V_49 ;
if ( V_30 != V_35 )
V_32 |= V_50 ;
return V_32 ;
}
static T_5 F_18 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_19 ( V_29 ) ;
if ( V_30 != V_35 )
V_32 |= V_51 ;
return V_32 ;
}
static T_5 F_20 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_19 ( V_29 ) ;
switch ( V_30 ) {
case V_35 :
break;
case V_37 :
V_32 |= V_52 ;
break;
default:
V_32 |= V_53 ;
break;
}
return V_32 ;
}
static void F_21 ( T_3 V_54 ,
struct V_1 * V_2 )
{
struct V_55 * V_55 = & V_2 -> V_8 -> V_2 ;
F_22 ( V_55 , V_54 , 4096 , V_56 ) ;
}
static int F_23 ( struct V_57 * V_57 ,
struct V_1 * V_2 ,
T_3 * V_54 )
{
struct V_55 * V_55 = & V_2 -> V_8 -> V_2 ;
* V_54 = F_24 ( V_55 , V_57 , 0 , 4096 , V_56 ) ;
if ( F_25 ( V_55 , * V_54 ) )
return - V_58 ;
return 0 ;
}
static void F_26 ( struct V_59 * V_60 ,
struct V_1 * V_2 )
{
if ( F_27 ( ! V_60 -> V_57 ) )
return;
F_28 ( V_60 , V_2 ) ;
F_29 ( V_60 -> V_57 ) ;
F_30 ( V_60 -> V_61 ) ;
F_30 ( V_60 ) ;
}
static void F_31 ( struct V_62 * V_21 ,
struct V_59 * V_60 )
{
T_2 * V_63 , V_64 ;
int V_65 ;
V_63 = F_32 ( V_60 -> V_57 ) ;
V_64 = F_11 ( V_21 -> V_66 . V_29 ,
V_44 , true ) ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ )
V_63 [ V_65 ] = V_64 ;
if ( ! F_33 ( V_21 -> V_2 ) )
F_34 ( V_63 , V_68 ) ;
F_35 ( V_63 ) ;
}
static struct V_59 * F_36 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
const T_6 V_69 = F_2 ( V_2 ) -> V_6 >= 8 ?
V_67 : V_70 ;
int V_71 = - V_58 ;
V_60 = F_37 ( sizeof( * V_60 ) , V_72 ) ;
if ( ! V_60 )
return F_38 ( - V_58 ) ;
V_60 -> V_61 = F_39 ( F_40 ( V_69 ) , sizeof( * V_60 -> V_61 ) ,
V_72 ) ;
if ( ! V_60 -> V_61 )
goto V_73;
V_60 -> V_57 = F_41 ( V_72 ) ;
if ( ! V_60 -> V_57 )
goto V_74;
V_71 = F_42 ( V_60 , V_2 ) ;
if ( V_71 )
goto V_75;
return V_60 ;
V_75:
F_29 ( V_60 -> V_57 ) ;
V_74:
F_30 ( V_60 -> V_61 ) ;
V_73:
F_30 ( V_60 ) ;
return F_38 ( V_71 ) ;
}
static void F_43 ( struct V_76 * V_77 ,
struct V_1 * V_2 )
{
if ( V_77 -> V_57 ) {
F_28 ( V_77 , V_2 ) ;
F_29 ( V_77 -> V_57 ) ;
F_30 ( V_77 -> V_78 ) ;
F_30 ( V_77 ) ;
}
}
static struct V_76 * F_44 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
int V_71 = - V_58 ;
V_77 = F_37 ( sizeof( * V_77 ) , V_72 ) ;
if ( ! V_77 )
return F_38 ( - V_58 ) ;
V_77 -> V_78 = F_39 ( F_40 ( V_79 ) ,
sizeof( * V_77 -> V_78 ) , V_72 ) ;
if ( ! V_77 -> V_78 )
goto V_80;
V_77 -> V_57 = F_41 ( V_72 ) ;
if ( ! V_77 -> V_57 )
goto V_81;
V_71 = F_42 ( V_77 , V_2 ) ;
if ( V_71 )
goto V_82;
return V_77 ;
V_82:
F_29 ( V_77 -> V_57 ) ;
V_81:
F_30 ( V_77 -> V_78 ) ;
V_80:
F_30 ( V_77 ) ;
return F_38 ( V_71 ) ;
}
static int F_45 ( struct V_83 * V_84 ,
unsigned V_85 ,
T_3 V_29 )
{
int V_71 ;
F_46 ( V_85 >= 4 ) ;
V_71 = F_47 ( V_84 , 6 ) ;
if ( V_71 )
return V_71 ;
F_48 ( V_84 , F_49 ( 1 ) ) ;
F_48 ( V_84 , F_50 ( V_84 , V_85 ) ) ;
F_48 ( V_84 , F_51 ( V_29 ) ) ;
F_48 ( V_84 , F_49 ( 1 ) ) ;
F_48 ( V_84 , F_52 ( V_84 , V_85 ) ) ;
F_48 ( V_84 , F_53 ( V_29 ) ) ;
F_54 ( V_84 ) ;
return 0 ;
}
static int F_55 ( struct V_86 * V_87 ,
struct V_83 * V_84 )
{
int V_65 , V_71 ;
for ( V_65 = V_88 - 1 ; V_65 >= 0 ; V_65 -- ) {
struct V_76 * V_77 = V_87 -> V_89 . V_90 [ V_65 ] ;
T_3 V_91 = V_77 ? V_77 -> V_54 : V_87 -> V_92 -> V_54 ;
V_71 = F_45 ( V_84 , V_65 , V_91 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
static void F_56 ( struct V_62 * V_21 ,
T_7 V_25 ,
T_7 V_93 ,
bool V_94 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
T_2 * V_63 , V_64 ;
unsigned V_95 = V_25 >> V_96 & V_97 ;
unsigned V_40 = V_25 >> V_98 & V_99 ;
unsigned V_32 = V_25 >> V_100 & V_101 ;
unsigned V_102 = V_93 >> V_103 ;
unsigned V_104 , V_65 ;
V_64 = F_11 ( V_87 -> V_27 . V_66 . V_29 ,
V_44 , V_94 ) ;
while ( V_102 ) {
struct V_76 * V_77 ;
struct V_59 * V_60 ;
struct V_57 * V_105 ;
if ( F_27 ( ! V_87 -> V_89 . V_90 [ V_95 ] ) )
break;
V_77 = V_87 -> V_89 . V_90 [ V_95 ] ;
if ( F_27 ( ! V_77 -> V_105 [ V_40 ] ) )
break;
V_60 = V_77 -> V_105 [ V_40 ] ;
if ( F_27 ( ! V_60 -> V_57 ) )
break;
V_105 = V_60 -> V_57 ;
V_104 = V_32 + V_102 ;
if ( V_104 > V_67 )
V_104 = V_67 ;
V_63 = F_32 ( V_105 ) ;
for ( V_65 = V_32 ; V_65 < V_104 ; V_65 ++ ) {
V_63 [ V_65 ] = V_64 ;
V_102 -- ;
}
if ( ! F_33 ( V_87 -> V_27 . V_2 ) )
F_34 ( V_63 , V_68 ) ;
F_35 ( V_63 ) ;
V_32 = 0 ;
if ( ++ V_40 == V_79 ) {
V_95 ++ ;
V_40 = 0 ;
}
}
}
static void F_58 ( struct V_62 * V_21 ,
struct V_106 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_16 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
T_2 * V_63 ;
unsigned V_95 = V_25 >> V_96 & V_97 ;
unsigned V_40 = V_25 >> V_98 & V_99 ;
unsigned V_32 = V_25 >> V_100 & V_101 ;
struct V_107 V_108 ;
V_63 = NULL ;
F_59 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_27 ( V_95 >= V_88 ) )
break;
if ( V_63 == NULL ) {
struct V_76 * V_77 = V_87 -> V_89 . V_90 [ V_95 ] ;
struct V_59 * V_60 = V_77 -> V_105 [ V_40 ] ;
struct V_57 * V_105 = V_60 -> V_57 ;
V_63 = F_32 ( V_105 ) ;
}
V_63 [ V_32 ] =
F_11 ( F_60 ( & V_108 ) ,
V_15 , true ) ;
if ( ++ V_32 == V_67 ) {
if ( ! F_33 ( V_87 -> V_27 . V_2 ) )
F_34 ( V_63 , V_68 ) ;
F_35 ( V_63 ) ;
V_63 = NULL ;
if ( ++ V_40 == V_79 ) {
V_95 ++ ;
V_40 = 0 ;
}
V_32 = 0 ;
}
}
if ( V_63 ) {
if ( ! F_33 ( V_87 -> V_27 . V_2 ) )
F_34 ( V_63 , V_68 ) ;
F_35 ( V_63 ) ;
}
}
static void F_61 ( T_4 * const V_40 ,
struct V_59 * V_60 ,
struct V_1 * V_2 )
{
T_4 V_85 =
F_12 ( V_2 , V_60 -> V_54 , V_44 ) ;
* V_40 = V_85 ;
}
static void F_62 ( struct V_62 * V_21 ,
struct V_76 * V_77 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
T_4 * V_90 ;
struct V_59 * V_60 ;
int V_65 ;
V_90 = F_32 ( V_77 -> V_57 ) ;
V_60 = V_87 -> V_109 ;
for ( V_65 = 0 ; V_65 < V_79 ; V_65 ++ )
F_61 ( V_90 + V_65 , V_60 , V_21 -> V_2 ) ;
if ( ! F_33 ( V_21 -> V_2 ) )
F_34 ( V_90 , V_68 ) ;
F_35 ( V_90 ) ;
}
static void F_63 ( struct V_76 * V_77 , struct V_1 * V_2 )
{
int V_65 ;
if ( ! V_77 -> V_57 )
return;
F_64 (i, pd->used_pdes, I915_PDES) {
if ( F_27 ( ! V_77 -> V_105 [ V_65 ] ) )
continue;
F_26 ( V_77 -> V_105 [ V_65 ] , V_2 ) ;
V_77 -> V_105 [ V_65 ] = NULL ;
}
}
static void F_65 ( struct V_62 * V_21 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
int V_65 ;
F_64 (i, ppgtt->pdp.used_pdpes, GEN8_LEGACY_PDPES) {
if ( F_27 ( ! V_87 -> V_89 . V_90 [ V_65 ] ) )
continue;
F_63 ( V_87 -> V_89 . V_90 [ V_65 ] , V_87 -> V_27 . V_2 ) ;
F_43 ( V_87 -> V_89 . V_90 [ V_65 ] , V_87 -> V_27 . V_2 ) ;
}
F_43 ( V_87 -> V_92 , V_87 -> V_27 . V_2 ) ;
F_26 ( V_87 -> V_109 , V_87 -> V_27 . V_2 ) ;
}
static int F_66 ( struct V_86 * V_87 ,
struct V_76 * V_77 ,
T_7 V_25 ,
T_7 V_93 ,
unsigned long * V_110 )
{
struct V_1 * V_2 = V_87 -> V_27 . V_2 ;
struct V_59 * V_60 ;
T_7 V_111 ;
T_8 V_40 ;
F_67 (pt, pd, start, length, temp, pde) {
if ( V_60 ) {
F_27 ( V_60 == V_87 -> V_109 ) ;
continue;
}
V_60 = F_36 ( V_2 ) ;
if ( F_68 ( V_60 ) )
goto V_112;
F_31 ( & V_87 -> V_27 , V_60 ) ;
V_77 -> V_105 [ V_40 ] = V_60 ;
F_69 ( V_40 , V_110 ) ;
}
return 0 ;
V_112:
F_64 (pde, new_pts, I915_PDES)
F_26 ( V_77 -> V_105 [ V_40 ] , V_2 ) ;
return - V_58 ;
}
static int F_70 ( struct V_86 * V_87 ,
struct V_113 * V_89 ,
T_7 V_25 ,
T_7 V_93 ,
unsigned long * V_114 )
{
struct V_1 * V_2 = V_87 -> V_27 . V_2 ;
struct V_76 * V_77 ;
T_7 V_111 ;
T_8 V_95 ;
F_27 ( ! F_71 ( V_114 , V_88 ) ) ;
F_27 ( ( V_25 + V_93 ) > ( 1ULL << 32 ) ) ;
F_72 (pd, pdp, start, length, temp, pdpe) {
if ( V_77 )
continue;
V_77 = F_44 ( V_2 ) ;
if ( F_68 ( V_77 ) )
goto V_112;
F_62 ( & V_87 -> V_27 , V_77 ) ;
V_89 -> V_90 [ V_95 ] = V_77 ;
F_69 ( V_95 , V_114 ) ;
}
return 0 ;
V_112:
F_64 (pdpe, new_pds, GEN8_LEGACY_PDPES)
F_43 ( V_89 -> V_90 [ V_95 ] , V_2 ) ;
return - V_58 ;
}
static void
F_73 ( unsigned long * V_114 , unsigned long * * V_110 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_88 ; V_65 ++ )
F_30 ( V_110 [ V_65 ] ) ;
F_30 ( V_110 ) ;
F_30 ( V_114 ) ;
}
static
int T_9 F_74 ( unsigned long * * V_114 ,
unsigned long * * * V_110 )
{
int V_65 ;
unsigned long * V_115 ;
unsigned long * * V_116 ;
V_115 = F_39 ( F_40 ( V_88 ) , sizeof( unsigned long ) , V_72 ) ;
if ( ! V_115 )
return - V_58 ;
V_116 = F_39 ( V_88 , sizeof( unsigned long * ) , V_72 ) ;
if ( ! V_116 ) {
F_30 ( V_115 ) ;
return - V_58 ;
}
for ( V_65 = 0 ; V_65 < V_88 ; V_65 ++ ) {
V_116 [ V_65 ] = F_39 ( F_40 ( V_79 ) ,
sizeof( unsigned long ) , V_72 ) ;
if ( ! V_116 [ V_65 ] )
goto V_117;
}
* V_114 = V_115 ;
* V_110 = V_116 ;
return 0 ;
V_117:
F_73 ( V_115 , V_116 ) ;
return - V_58 ;
}
static int F_75 ( struct V_62 * V_21 ,
T_7 V_25 ,
T_7 V_93 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
unsigned long * V_118 , * * V_119 ;
struct V_76 * V_77 ;
const T_7 V_120 = V_25 ;
const T_7 V_121 = V_93 ;
T_7 V_111 ;
T_8 V_95 ;
int V_71 ;
if ( F_27 ( V_25 + V_93 < V_25 ) )
return - V_122 ;
V_71 = F_74 ( & V_118 , & V_119 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_70 ( V_87 , & V_87 -> V_89 , V_25 , V_93 ,
V_118 ) ;
if ( V_71 ) {
F_73 ( V_118 , V_119 ) ;
return V_71 ;
}
F_72 (pd, &ppgtt->pdp, start, length, temp, pdpe) {
V_71 = F_66 ( V_87 , V_77 , V_25 , V_93 ,
V_119 [ V_95 ] ) ;
if ( V_71 )
goto V_117;
}
V_25 = V_120 ;
V_93 = V_121 ;
F_72 (pd, &ppgtt->pdp, start, length, temp, pdpe) {
T_4 * const V_90 = F_32 ( V_77 -> V_57 ) ;
struct V_59 * V_60 ;
T_7 V_123 = F_76 ( V_25 , V_93 ) ;
T_7 V_124 = V_25 ;
T_8 V_40 ;
F_27 ( ! V_77 ) ;
F_67 (pt, pd, pd_start, pd_len, temp, pde) {
F_27 ( ! V_60 ) ;
F_27 ( ! V_123 ) ;
F_27 ( ! F_77 ( V_124 , V_123 ) ) ;
F_78 ( V_60 -> V_61 ,
F_79 ( V_124 ) ,
F_77 ( V_124 , V_123 ) ) ;
F_69 ( V_40 , V_77 -> V_78 ) ;
F_61 ( V_90 + V_40 , V_60 , V_21 -> V_2 ) ;
}
if ( ! F_33 ( V_21 -> V_2 ) )
F_34 ( V_90 , V_68 ) ;
F_35 ( V_90 ) ;
F_69 ( V_95 , V_87 -> V_89 . V_125 ) ;
}
F_73 ( V_118 , V_119 ) ;
return 0 ;
V_117:
while ( V_95 -- ) {
F_64 (temp, new_page_tables[pdpe], I915_PDES)
F_26 ( V_87 -> V_89 . V_90 [ V_95 ] -> V_105 [ V_111 ] , V_21 -> V_2 ) ;
}
F_64 (pdpe, new_page_dirs, GEN8_LEGACY_PDPES)
F_43 ( V_87 -> V_89 . V_90 [ V_95 ] , V_21 -> V_2 ) ;
F_73 ( V_118 , V_119 ) ;
return V_71 ;
}
static int F_80 ( struct V_86 * V_87 )
{
V_87 -> V_109 = F_36 ( V_87 -> V_27 . V_2 ) ;
if ( F_68 ( V_87 -> V_109 ) )
return F_81 ( V_87 -> V_109 ) ;
V_87 -> V_92 = F_44 ( V_87 -> V_27 . V_2 ) ;
if ( F_68 ( V_87 -> V_92 ) )
return F_81 ( V_87 -> V_92 ) ;
F_31 ( & V_87 -> V_27 , V_87 -> V_109 ) ;
F_62 ( & V_87 -> V_27 , V_87 -> V_92 ) ;
V_87 -> V_27 . V_25 = 0 ;
V_87 -> V_27 . V_126 = 1ULL << 32 ;
if ( F_82 ( V_127 ) )
V_87 -> V_27 . V_126 = F_83 ( V_87 -> V_27 . V_2 ) -> V_128 . V_27 . V_126 ;
V_87 -> V_27 . V_129 = F_65 ;
V_87 -> V_27 . V_130 = F_75 ;
V_87 -> V_27 . V_22 = F_58 ;
V_87 -> V_27 . V_26 = F_56 ;
V_87 -> V_27 . V_131 = F_10 ;
V_87 -> V_27 . V_132 = F_9 ;
V_87 -> V_133 = F_55 ;
return 0 ;
}
static void F_84 ( struct V_86 * V_87 , struct V_134 * V_135 )
{
struct V_62 * V_21 = & V_87 -> V_27 ;
struct V_59 * V_16 ;
T_5 V_64 ;
T_8 V_136 ;
T_8 V_32 , V_40 , V_111 ;
T_8 V_25 = V_87 -> V_27 . V_25 , V_93 = V_87 -> V_27 . V_126 ;
V_64 = V_21 -> V_137 ( V_21 -> V_66 . V_29 , V_44 , true , 0 ) ;
F_85 (unused, &ppgtt->pd, start, length, temp, pde) {
T_1 V_138 ;
T_5 * V_63 ;
T_3 V_139 = V_87 -> V_77 . V_105 [ V_40 ] -> V_54 ;
V_136 = F_86 ( V_87 -> V_140 + V_40 ) ;
V_138 = ( F_87 ( V_139 ) | V_141 ) ;
if ( V_136 != V_138 )
F_88 ( V_135 , L_3 ,
V_40 ,
V_136 ,
V_138 ) ;
F_88 ( V_135 , L_4 , V_136 ) ;
V_63 = F_32 ( V_87 -> V_77 . V_105 [ V_40 ] -> V_57 ) ;
for ( V_32 = 0 ; V_32 < V_70 ; V_32 += 4 ) {
unsigned long V_142 =
( V_40 * V_68 * V_70 ) +
( V_32 * V_68 ) ;
int V_65 ;
bool V_143 = false ;
for ( V_65 = 0 ; V_65 < 4 ; V_65 ++ )
if ( V_63 [ V_32 + V_65 ] != V_64 )
V_143 = true ;
if ( ! V_143 )
continue;
F_88 ( V_135 , L_5 , V_142 , V_40 , V_32 ) ;
for ( V_65 = 0 ; V_65 < 4 ; V_65 ++ ) {
if ( V_63 [ V_32 + V_65 ] != V_64 )
F_88 ( V_135 , L_6 , V_63 [ V_32 + V_65 ] ) ;
else
F_89 ( V_135 , L_7 ) ;
}
F_89 ( V_135 , L_8 ) ;
}
F_35 ( V_63 ) ;
}
}
static void F_90 ( struct V_76 * V_77 ,
const int V_40 , struct V_59 * V_60 )
{
struct V_86 * V_87 =
F_57 ( V_77 , struct V_86 , V_77 ) ;
T_1 V_136 ;
V_136 = F_87 ( V_60 -> V_54 ) ;
V_136 |= V_141 ;
F_91 ( V_136 , V_87 -> V_140 + V_40 ) ;
}
static void F_92 ( struct V_144 * V_145 ,
struct V_76 * V_77 ,
T_8 V_25 , T_8 V_93 )
{
struct V_59 * V_60 ;
T_8 V_40 , V_111 ;
F_85 (pt, pd, start, length, temp, pde)
F_90 ( V_77 , V_40 , V_60 ) ;
F_86 ( V_145 -> V_128 . V_146 ) ;
}
static T_8 F_93 ( struct V_86 * V_87 )
{
F_46 ( V_87 -> V_77 . V_147 & 0x3f ) ;
return ( V_87 -> V_77 . V_147 / 64 ) << 16 ;
}
static int F_94 ( struct V_86 * V_87 ,
struct V_83 * V_84 )
{
int V_71 ;
V_71 = V_84 -> V_148 ( V_84 , V_149 , V_149 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_47 ( V_84 , 6 ) ;
if ( V_71 )
return V_71 ;
F_48 ( V_84 , F_49 ( 2 ) ) ;
F_48 ( V_84 , F_95 ( V_84 ) ) ;
F_48 ( V_84 , V_150 ) ;
F_48 ( V_84 , F_96 ( V_84 ) ) ;
F_48 ( V_84 , F_93 ( V_87 ) ) ;
F_48 ( V_84 , V_151 ) ;
F_54 ( V_84 ) ;
return 0 ;
}
static int F_97 ( struct V_86 * V_87 ,
struct V_83 * V_84 )
{
struct V_144 * V_145 = F_83 ( V_87 -> V_27 . V_2 ) ;
F_98 ( F_95 ( V_84 ) , V_150 ) ;
F_98 ( F_96 ( V_84 ) , F_93 ( V_87 ) ) ;
return 0 ;
}
static int F_99 ( struct V_86 * V_87 ,
struct V_83 * V_84 )
{
int V_71 ;
V_71 = V_84 -> V_148 ( V_84 , V_149 , V_149 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_47 ( V_84 , 6 ) ;
if ( V_71 )
return V_71 ;
F_48 ( V_84 , F_49 ( 2 ) ) ;
F_48 ( V_84 , F_95 ( V_84 ) ) ;
F_48 ( V_84 , V_150 ) ;
F_48 ( V_84 , F_96 ( V_84 ) ) ;
F_48 ( V_84 , F_93 ( V_87 ) ) ;
F_48 ( V_84 , V_151 ) ;
F_54 ( V_84 ) ;
if ( V_84 -> V_152 != V_153 ) {
V_71 = V_84 -> V_148 ( V_84 , V_149 , V_149 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
static int F_100 ( struct V_86 * V_87 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = V_87 -> V_27 . V_2 ;
struct V_144 * V_145 = V_2 -> V_154 ;
F_98 ( F_95 ( V_84 ) , V_150 ) ;
F_98 ( F_96 ( V_84 ) , F_93 ( V_87 ) ) ;
F_101 ( F_95 ( V_84 ) ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_83 * V_84 ;
int V_155 ;
F_103 (ring, dev_priv, j) {
F_98 ( F_104 ( V_84 ) ,
F_105 ( V_156 ) ) ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_83 * V_84 ;
T_8 V_157 , V_158 ;
int V_65 ;
V_158 = F_107 ( V_159 ) ;
F_98 ( V_159 , V_158 | V_160 ) ;
V_157 = F_107 ( V_161 ) ;
if ( F_108 ( V_2 ) ) {
V_157 |= V_162 ;
} else {
V_157 |= V_163 ;
V_157 &= ~ V_164 ;
}
F_98 ( V_161 , V_157 ) ;
F_103 (ring, dev_priv, i) {
F_98 ( F_104 ( V_84 ) ,
F_105 ( V_156 ) ) ;
}
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
T_8 V_157 , V_165 , V_158 ;
V_158 = F_107 ( V_159 ) ;
F_98 ( V_159 , V_158 | V_166 |
V_160 ) ;
V_165 = F_107 ( V_167 ) ;
F_98 ( V_167 , V_165 | V_168 ) ;
V_157 = F_107 ( V_161 ) ;
F_98 ( V_161 , V_157 | V_169 | V_170 ) ;
F_98 ( V_171 , F_105 ( V_156 ) ) ;
}
static void F_110 ( struct V_62 * V_21 ,
T_7 V_25 ,
T_7 V_93 ,
bool V_94 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
T_5 * V_63 , V_64 ;
unsigned V_172 = V_25 >> V_103 ;
unsigned V_102 = V_93 >> V_103 ;
unsigned V_173 = V_172 / V_70 ;
unsigned V_174 = V_172 % V_70 ;
unsigned V_104 , V_65 ;
V_64 = V_21 -> V_137 ( V_21 -> V_66 . V_29 , V_44 , true , 0 ) ;
while ( V_102 ) {
V_104 = V_174 + V_102 ;
if ( V_104 > V_70 )
V_104 = V_70 ;
V_63 = F_32 ( V_87 -> V_77 . V_105 [ V_173 ] -> V_57 ) ;
for ( V_65 = V_174 ; V_65 < V_104 ; V_65 ++ )
V_63 [ V_65 ] = V_64 ;
F_35 ( V_63 ) ;
V_102 -= V_104 - V_174 ;
V_174 = 0 ;
V_173 ++ ;
}
}
static void F_111 ( struct V_62 * V_21 ,
struct V_106 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_48 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
T_5 * V_63 ;
unsigned V_172 = V_25 >> V_103 ;
unsigned V_173 = V_172 / V_70 ;
unsigned V_175 = V_172 % V_70 ;
struct V_107 V_108 ;
V_63 = NULL ;
F_59 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_63 == NULL )
V_63 = F_32 ( V_87 -> V_77 . V_105 [ V_173 ] -> V_57 ) ;
V_63 [ V_175 ] =
V_21 -> V_137 ( F_60 ( & V_108 ) ,
V_15 , true , V_48 ) ;
if ( ++ V_175 == V_70 ) {
F_35 ( V_63 ) ;
V_63 = NULL ;
V_173 ++ ;
V_175 = 0 ;
}
}
if ( V_63 )
F_35 ( V_63 ) ;
}
static void F_112 ( struct V_86 * V_87 )
{
V_87 -> V_176 = F_2 ( V_87 -> V_27 . V_2 ) -> V_177 ;
}
static void F_113 ( struct V_62 * V_21 ,
struct V_59 * V_60 )
{
T_5 * V_63 , V_64 ;
int V_65 ;
F_27 ( V_21 -> V_66 . V_29 == 0 ) ;
V_64 = V_21 -> V_137 ( V_21 -> V_66 . V_29 ,
V_44 , true , 0 ) ;
V_63 = F_32 ( V_60 -> V_57 ) ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ )
V_63 [ V_65 ] = V_64 ;
F_35 ( V_63 ) ;
}
static int F_114 ( struct V_62 * V_21 ,
T_7 V_25 , T_7 V_93 )
{
F_115 ( V_119 , V_79 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
struct V_59 * V_60 ;
const T_8 V_178 = V_25 , V_179 = V_93 ;
T_8 V_40 , V_111 ;
int V_71 ;
F_27 ( F_51 ( V_25 ) ) ;
F_116 ( V_119 , V_79 ) ;
F_85 (pt, &ppgtt->pd, start, length, temp, pde) {
if ( V_60 != V_87 -> V_109 ) {
F_27 ( F_71 ( V_60 -> V_61 , V_70 ) ) ;
continue;
}
F_27 ( ! F_71 ( V_60 -> V_61 , V_70 ) ) ;
V_60 = F_36 ( V_2 ) ;
if ( F_68 ( V_60 ) ) {
V_71 = F_81 ( V_60 ) ;
goto V_112;
}
F_113 ( V_21 , V_60 ) ;
V_87 -> V_77 . V_105 [ V_40 ] = V_60 ;
F_69 ( V_40 , V_119 ) ;
F_117 ( V_21 , V_40 , V_25 , V_180 ) ;
}
V_25 = V_178 ;
V_93 = V_179 ;
F_85 (pt, &ppgtt->pd, start, length, temp, pde) {
F_115 ( V_181 , V_70 ) ;
F_116 ( V_181 , V_70 ) ;
F_78 ( V_181 , F_118 ( V_25 ) ,
F_119 ( V_25 , V_93 ) ) ;
if ( F_120 ( V_40 , V_119 ) )
F_90 ( & V_87 -> V_77 , V_40 , V_60 ) ;
F_121 ( V_21 , V_40 , V_60 ,
F_118 ( V_25 ) ,
F_119 ( V_25 , V_93 ) ,
V_70 ) ;
F_122 ( V_60 -> V_61 , V_181 , V_60 -> V_61 ,
V_70 ) ;
}
F_27 ( ! F_71 ( V_119 , V_79 ) ) ;
F_86 ( V_145 -> V_128 . V_146 ) ;
F_112 ( V_87 ) ;
return 0 ;
V_112:
F_64 (pde, new_page_tables, I915_PDES) {
struct V_59 * V_60 = V_87 -> V_77 . V_105 [ V_40 ] ;
V_87 -> V_77 . V_105 [ V_40 ] = V_87 -> V_109 ;
F_26 ( V_60 , V_21 -> V_2 ) ;
}
F_112 ( V_87 ) ;
return V_71 ;
}
static void F_123 ( struct V_62 * V_21 )
{
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 , V_27 ) ;
struct V_59 * V_60 ;
T_8 V_40 ;
F_124 ( & V_87 -> V_24 ) ;
F_125 (pt, ppgtt, pde) {
if ( V_60 != V_87 -> V_109 )
F_26 ( V_60 , V_87 -> V_27 . V_2 ) ;
}
F_26 ( V_87 -> V_109 , V_87 -> V_27 . V_2 ) ;
F_43 ( & V_87 -> V_77 , V_87 -> V_27 . V_2 ) ;
}
static int F_126 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_27 . V_2 ;
struct V_144 * V_145 = V_2 -> V_154 ;
bool V_182 = false ;
int V_71 ;
F_46 ( ! F_127 ( & V_145 -> V_128 . V_27 . V_183 ) ) ;
V_87 -> V_109 = F_36 ( V_87 -> V_27 . V_2 ) ;
if ( F_68 ( V_87 -> V_109 ) )
return F_81 ( V_87 -> V_109 ) ;
F_113 ( & V_87 -> V_27 , V_87 -> V_109 ) ;
V_184:
V_71 = F_128 ( & V_145 -> V_128 . V_27 . V_183 ,
& V_87 -> V_24 , V_185 ,
V_186 , 0 ,
0 , V_145 -> V_128 . V_27 . V_126 ,
V_187 ) ;
if ( V_71 == - V_188 && ! V_182 ) {
V_71 = F_129 ( V_2 , & V_145 -> V_128 . V_27 ,
V_185 , V_186 ,
V_35 ,
0 , V_145 -> V_128 . V_27 . V_126 ,
0 ) ;
if ( V_71 )
goto V_117;
V_182 = true ;
goto V_184;
}
if ( V_71 )
goto V_117;
if ( V_87 -> V_24 . V_25 < V_145 -> V_128 . V_189 )
F_130 ( L_9 ) ;
return 0 ;
V_117:
F_26 ( V_87 -> V_109 , V_87 -> V_27 . V_2 ) ;
return V_71 ;
}
static int F_131 ( struct V_86 * V_87 )
{
return F_126 ( V_87 ) ;
}
static void F_132 ( struct V_86 * V_87 ,
T_7 V_25 , T_7 V_93 )
{
struct V_59 * V_16 ;
T_8 V_40 , V_111 ;
F_85 (unused, &ppgtt->pd, start, length, temp, pde)
V_87 -> V_77 . V_105 [ V_40 ] = V_87 -> V_109 ;
}
static int F_133 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_27 . V_2 ;
struct V_144 * V_145 = V_2 -> V_154 ;
int V_71 ;
V_87 -> V_27 . V_137 = V_145 -> V_128 . V_27 . V_137 ;
if ( F_134 ( V_2 ) ) {
V_87 -> V_133 = F_100 ;
} else if ( F_108 ( V_2 ) ) {
V_87 -> V_133 = F_94 ;
} else if ( F_135 ( V_2 ) ) {
V_87 -> V_133 = F_99 ;
} else
F_136 () ;
if ( F_3 ( V_2 ) )
V_87 -> V_133 = F_97 ;
V_71 = F_131 ( V_87 ) ;
if ( V_71 )
return V_71 ;
V_87 -> V_27 . V_130 = F_114 ;
V_87 -> V_27 . V_26 = F_110 ;
V_87 -> V_27 . V_22 = F_111 ;
V_87 -> V_27 . V_131 = F_10 ;
V_87 -> V_27 . V_132 = F_9 ;
V_87 -> V_27 . V_129 = F_123 ;
V_87 -> V_27 . V_25 = 0 ;
V_87 -> V_27 . V_126 = V_79 * V_70 * V_68 ;
V_87 -> V_190 = F_84 ;
V_87 -> V_77 . V_147 =
V_87 -> V_24 . V_25 / V_68 * sizeof( T_5 ) ;
V_87 -> V_140 = ( T_5 V_191 * ) V_145 -> V_128 . V_146 +
V_87 -> V_77 . V_147 / sizeof( T_5 ) ;
F_132 ( V_87 , 0 , V_87 -> V_27 . V_126 ) ;
F_92 ( V_145 , & V_87 -> V_77 , 0 , V_87 -> V_27 . V_126 ) ;
F_8 ( L_10 ,
V_87 -> V_24 . V_28 >> 20 ,
V_87 -> V_24 . V_25 / V_68 ) ;
F_130 ( L_11 ,
V_87 -> V_77 . V_147 << 10 ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
V_87 -> V_27 . V_2 = V_2 ;
V_87 -> V_27 . V_66 = V_145 -> V_128 . V_27 . V_66 ;
if ( F_2 ( V_2 ) -> V_6 < 8 )
return F_133 ( V_87 ) ;
else
return F_80 ( V_87 ) ;
}
int F_138 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
int V_71 = 0 ;
V_71 = F_137 ( V_2 , V_87 ) ;
if ( V_71 == 0 ) {
F_139 ( & V_87 -> V_192 ) ;
F_140 ( & V_87 -> V_27 . V_183 , V_87 -> V_27 . V_25 ,
V_87 -> V_27 . V_126 ) ;
F_141 ( V_145 , & V_87 -> V_27 ) ;
}
return V_71 ;
}
int F_142 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_83 * V_84 ;
struct V_86 * V_87 = V_145 -> V_183 . V_193 ;
int V_65 , V_71 = 0 ;
if ( V_10 . V_11 )
return 0 ;
if ( ! F_143 ( V_2 ) )
return 0 ;
if ( F_134 ( V_2 ) )
F_109 ( V_2 ) ;
else if ( F_135 ( V_2 ) )
F_106 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_6 >= 8 )
F_102 ( V_2 ) ;
else
F_15 ( F_2 ( V_2 ) -> V_6 ) ;
if ( V_87 ) {
F_103 (ring, dev_priv, i) {
V_71 = V_87 -> V_133 ( V_87 , V_84 ) ;
if ( V_71 != 0 )
return V_71 ;
}
}
return V_71 ;
}
struct V_86 *
F_144 ( struct V_1 * V_2 , struct V_194 * V_195 )
{
struct V_86 * V_87 ;
int V_71 ;
V_87 = F_37 ( sizeof( * V_87 ) , V_72 ) ;
if ( ! V_87 )
return F_38 ( - V_58 ) ;
V_71 = F_138 ( V_2 , V_87 ) ;
if ( V_71 ) {
F_30 ( V_87 ) ;
return F_38 ( V_71 ) ;
}
V_87 -> V_196 = V_195 ;
F_145 ( & V_87 -> V_27 ) ;
return V_87 ;
}
void F_146 ( struct V_197 * V_197 )
{
struct V_86 * V_87 =
F_57 ( V_197 , struct V_86 , V_192 ) ;
F_147 ( & V_87 -> V_27 ) ;
F_27 ( ! F_148 ( & V_87 -> V_27 . V_198 ) ) ;
F_27 ( ! F_148 ( & V_87 -> V_27 . V_199 ) ) ;
F_149 ( & V_87 -> V_27 . V_200 ) ;
F_150 ( & V_87 -> V_27 . V_183 ) ;
V_87 -> V_27 . V_129 ( & V_87 -> V_27 ) ;
F_30 ( V_87 ) ;
}
static bool F_151 ( struct V_1 * V_2 )
{
#ifdef F_4
if ( F_152 ( V_2 ) && F_153 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_154 ( struct V_144 * V_145 )
{
bool V_71 = V_145 -> V_183 . V_201 ;
if ( F_155 ( V_145 -> V_128 . V_202 ) ) {
V_145 -> V_183 . V_201 = false ;
if ( F_156 ( V_145 -> V_2 ) ) {
F_157 ( L_12 ) ;
F_158 ( 10 ) ;
}
}
return V_71 ;
}
static void F_159 ( struct V_144 * V_145 , bool V_201 )
{
if ( F_155 ( V_145 -> V_128 . V_202 ) )
V_145 -> V_183 . V_201 = V_201 ;
}
void F_160 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_83 * V_84 ;
int V_65 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_103 (ring, dev_priv, i) {
T_1 V_203 ;
V_203 = F_107 ( F_161 ( V_84 ) ) ;
if ( V_203 & V_204 ) {
F_8 ( L_13
L_14
L_15
L_16
L_17 ,
V_203 & V_205 ,
V_203 & V_206 ? L_18 : L_19 ,
F_162 ( V_203 ) ,
F_163 ( V_203 ) ) ;
F_98 ( F_161 ( V_84 ) ,
V_203 & ~ V_204 ) ;
}
}
F_101 ( F_161 ( & V_145 -> V_84 [ V_153 ] ) ) ;
}
static void F_164 ( struct V_144 * V_145 )
{
if ( F_2 ( V_145 -> V_2 ) -> V_6 < 6 ) {
F_165 () ;
} else {
F_98 ( V_207 , V_208 ) ;
F_101 ( V_207 ) ;
}
}
void F_166 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_160 ( V_2 ) ;
V_145 -> V_128 . V_27 . V_26 ( & V_145 -> V_128 . V_27 ,
V_145 -> V_128 . V_27 . V_25 ,
V_145 -> V_128 . V_27 . V_126 ,
true ) ;
F_164 ( V_145 ) ;
}
int F_167 ( struct V_209 * V_18 )
{
if ( ! F_168 ( & V_18 -> V_27 . V_2 -> V_8 -> V_2 ,
V_18 -> V_23 -> V_210 , V_18 -> V_23 -> V_211 ,
V_56 ) )
return - V_188 ;
return 0 ;
}
static void F_169 ( void V_191 * V_29 , T_2 V_32 )
{
#ifdef F_170
F_170 ( V_32 , V_29 ) ;
#else
F_171 ( ( T_1 ) V_32 , V_29 ) ;
F_171 ( V_32 >> 32 , V_29 + 4 ) ;
#endif
}
static void F_172 ( struct V_62 * V_21 ,
struct V_106 * V_212 ,
T_7 V_25 ,
enum V_14 V_30 , T_1 V_16 )
{
struct V_144 * V_145 = V_21 -> V_2 -> V_154 ;
unsigned V_172 = V_25 >> V_103 ;
T_2 V_191 * V_213 =
( T_2 V_191 * ) V_145 -> V_128 . V_146 + V_172 ;
int V_65 = 0 ;
struct V_107 V_108 ;
T_3 V_29 = 0 ;
F_59 (st->sgl, &sg_iter, st->nents, 0 ) {
V_29 = F_173 ( V_108 . V_214 ) +
( V_108 . V_215 << V_103 ) ;
F_169 ( & V_213 [ V_65 ] ,
F_11 ( V_29 , V_30 , true ) ) ;
V_65 ++ ;
}
if ( V_65 != 0 )
F_27 ( F_174 ( & V_213 [ V_65 - 1 ] )
!= F_11 ( V_29 , V_30 , true ) ) ;
F_98 ( V_207 , V_208 ) ;
F_101 ( V_207 ) ;
}
static void F_175 ( struct V_62 * V_21 ,
struct V_106 * V_212 ,
T_7 V_25 ,
enum V_14 V_30 , T_1 V_48 )
{
struct V_144 * V_145 = V_21 -> V_2 -> V_154 ;
unsigned V_172 = V_25 >> V_103 ;
T_5 V_191 * V_213 =
( T_5 V_191 * ) V_145 -> V_128 . V_146 + V_172 ;
int V_65 = 0 ;
struct V_107 V_108 ;
T_3 V_29 = 0 ;
F_59 (st->sgl, &sg_iter, st->nents, 0 ) {
V_29 = F_60 ( & V_108 ) ;
F_171 ( V_21 -> V_137 ( V_29 , V_30 , true , V_48 ) , & V_213 [ V_65 ] ) ;
V_65 ++ ;
}
if ( V_65 != 0 ) {
unsigned long V_128 = F_86 ( & V_213 [ V_65 - 1 ] ) ;
F_27 ( V_128 != V_21 -> V_137 ( V_29 , V_30 , true , V_48 ) ) ;
}
F_98 ( V_207 , V_208 ) ;
F_101 ( V_207 ) ;
}
static void F_176 ( struct V_62 * V_21 ,
T_7 V_25 ,
T_7 V_93 ,
bool V_94 )
{
struct V_144 * V_145 = V_21 -> V_2 -> V_154 ;
unsigned V_172 = V_25 >> V_103 ;
unsigned V_102 = V_93 >> V_103 ;
T_2 V_64 , V_191 * V_216 =
( T_2 V_191 * ) V_145 -> V_128 . V_146 + V_172 ;
const int V_217 = F_177 ( V_145 -> V_128 ) - V_172 ;
int V_65 ;
if ( F_178 ( V_102 > V_217 ,
L_20 ,
V_172 , V_102 , V_217 ) )
V_102 = V_217 ;
V_64 = F_11 ( V_21 -> V_66 . V_29 ,
V_44 ,
V_94 ) ;
for ( V_65 = 0 ; V_65 < V_102 ; V_65 ++ )
F_169 ( & V_216 [ V_65 ] , V_64 ) ;
F_86 ( V_216 ) ;
}
static void F_179 ( struct V_62 * V_21 ,
T_7 V_25 ,
T_7 V_93 ,
bool V_94 )
{
struct V_144 * V_145 = V_21 -> V_2 -> V_154 ;
unsigned V_172 = V_25 >> V_103 ;
unsigned V_102 = V_93 >> V_103 ;
T_5 V_64 , V_191 * V_216 =
( T_5 V_191 * ) V_145 -> V_128 . V_146 + V_172 ;
const int V_217 = F_177 ( V_145 -> V_128 ) - V_172 ;
int V_65 ;
if ( F_178 ( V_102 > V_217 ,
L_20 ,
V_172 , V_102 , V_217 ) )
V_102 = V_217 ;
V_64 = V_21 -> V_137 ( V_21 -> V_66 . V_29 , V_44 , V_94 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_102 ; V_65 ++ )
F_171 ( V_64 , & V_216 [ V_65 ] ) ;
F_86 ( V_216 ) ;
}
static void F_180 ( struct V_62 * V_21 ,
struct V_106 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_16 )
{
unsigned int V_48 = ( V_15 == V_35 ) ?
V_218 : V_219 ;
F_181 ( V_23 , V_25 >> V_103 , V_48 ) ;
}
static void F_182 ( struct V_62 * V_21 ,
T_7 V_25 ,
T_7 V_93 ,
bool V_16 )
{
unsigned V_172 = V_25 >> V_103 ;
unsigned V_102 = V_93 >> V_103 ;
F_183 ( V_172 , V_102 ) ;
}
static int F_184 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
T_1 V_48 )
{
struct V_1 * V_2 = V_13 -> V_21 -> V_2 ;
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_209 * V_18 = V_13 -> V_18 ;
struct V_106 * V_23 = V_18 -> V_23 ;
T_1 V_17 = 0 ;
int V_71 ;
V_71 = F_185 ( V_13 ) ;
if ( V_71 )
return V_71 ;
V_23 = V_13 -> V_220 . V_23 ;
if ( V_18 -> V_19 )
V_17 |= V_20 ;
if ( ! V_145 -> V_183 . V_193 || V_48 & V_221 ) {
V_13 -> V_21 -> V_22 ( V_13 -> V_21 , V_23 ,
V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
V_13 -> V_222 |= V_221 ;
}
if ( V_145 -> V_183 . V_193 && V_48 & V_223 ) {
struct V_86 * V_224 = V_145 -> V_183 . V_193 ;
V_224 -> V_27 . V_22 ( & V_224 -> V_27 , V_23 ,
V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
}
return 0 ;
}
static void F_186 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_21 -> V_2 ;
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_209 * V_18 = V_13 -> V_18 ;
const T_7 V_28 = F_187 ( T_7 ,
V_18 -> V_27 . V_28 ,
V_13 -> V_24 . V_28 ) ;
if ( V_13 -> V_222 & V_221 ) {
V_13 -> V_21 -> V_26 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_28 ,
true ) ;
}
if ( V_145 -> V_183 . V_193 && V_13 -> V_222 & V_223 ) {
struct V_86 * V_224 = V_145 -> V_183 . V_193 ;
V_224 -> V_27 . V_26 ( & V_224 -> V_27 ,
V_13 -> V_24 . V_25 ,
V_28 ,
true ) ;
}
}
void F_188 ( struct V_209 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_27 . V_2 ;
struct V_144 * V_145 = V_2 -> V_154 ;
bool V_201 ;
V_201 = F_154 ( V_145 ) ;
F_189 ( & V_2 -> V_8 -> V_2 , V_18 -> V_23 -> V_210 , V_18 -> V_23 -> V_211 ,
V_56 ) ;
F_159 ( V_145 , V_201 ) ;
}
static void F_190 ( struct V_225 * V_24 ,
unsigned long V_226 ,
T_10 * V_25 ,
T_10 * V_227 )
{
if ( V_24 -> V_226 != V_226 )
* V_25 += 4096 ;
if ( ! F_148 ( & V_24 -> V_228 ) ) {
V_24 = F_191 ( V_24 -> V_228 . V_229 ,
struct V_225 ,
V_228 ) ;
if ( V_24 -> V_230 && V_24 -> V_226 != V_226 )
* V_227 -= 4096 ;
}
}
static int F_192 ( struct V_1 * V_2 ,
unsigned long V_25 ,
unsigned long V_189 ,
unsigned long V_227 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_62 * V_231 = & V_145 -> V_128 . V_27 ;
struct V_225 * V_85 ;
struct V_209 * V_18 ;
unsigned long V_232 , V_233 ;
int V_71 ;
F_46 ( V_189 > V_227 ) ;
F_140 ( & V_231 -> V_183 , V_25 , V_227 - V_25 - V_68 ) ;
V_145 -> V_128 . V_27 . V_25 = V_25 ;
V_145 -> V_128 . V_27 . V_126 = V_227 - V_25 ;
if ( F_3 ( V_2 ) ) {
V_71 = F_193 ( V_2 ) ;
if ( V_71 )
return V_71 ;
}
if ( ! F_33 ( V_2 ) )
V_145 -> V_128 . V_27 . V_183 . V_234 = F_190 ;
F_194 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_12 * V_13 = F_195 ( V_18 , V_231 ) ;
F_196 ( L_21 ,
F_197 ( V_18 ) , V_18 -> V_27 . V_28 ) ;
F_27 ( F_198 ( V_18 ) ) ;
V_71 = F_199 ( & V_231 -> V_183 , & V_13 -> V_24 ) ;
if ( V_71 ) {
F_196 ( L_22 , V_71 ) ;
return V_71 ;
}
V_13 -> V_222 |= V_221 ;
}
F_200 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_196 ( L_23 ,
V_232 , V_233 ) ;
V_231 -> V_26 ( V_231 , V_232 ,
V_233 - V_232 , true ) ;
}
V_231 -> V_26 ( V_231 , V_227 - V_68 , V_68 , true ) ;
if ( F_143 ( V_2 ) && ! F_201 ( V_2 ) ) {
struct V_86 * V_87 ;
V_87 = F_37 ( sizeof( * V_87 ) , V_72 ) ;
if ( ! V_87 )
return - V_58 ;
V_71 = F_137 ( V_2 , V_87 ) ;
if ( V_71 ) {
V_87 -> V_27 . V_129 ( & V_87 -> V_27 ) ;
F_30 ( V_87 ) ;
return V_71 ;
}
if ( V_87 -> V_27 . V_130 )
V_71 = V_87 -> V_27 . V_130 ( & V_87 -> V_27 , 0 ,
V_87 -> V_27 . V_126 ) ;
if ( V_71 ) {
V_87 -> V_27 . V_129 ( & V_87 -> V_27 ) ;
F_30 ( V_87 ) ;
return V_71 ;
}
V_87 -> V_27 . V_26 ( & V_87 -> V_27 ,
V_87 -> V_27 . V_25 ,
V_87 -> V_27 . V_126 ,
true ) ;
V_145 -> V_183 . V_193 = V_87 ;
}
return 0 ;
}
void F_202 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
unsigned long V_235 , V_236 ;
V_235 = V_145 -> V_128 . V_27 . V_126 ;
V_236 = V_145 -> V_128 . V_189 ;
F_192 ( V_2 , 0 , V_236 , V_235 ) ;
}
void F_203 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_62 * V_21 = & V_145 -> V_128 . V_27 ;
if ( V_145 -> V_183 . V_193 ) {
struct V_86 * V_87 = V_145 -> V_183 . V_193 ;
V_87 -> V_27 . V_129 ( & V_87 -> V_27 ) ;
}
if ( F_127 ( & V_21 -> V_183 ) ) {
if ( F_3 ( V_2 ) )
F_204 () ;
F_150 ( & V_21 -> V_183 ) ;
F_149 ( & V_21 -> V_200 ) ;
}
V_21 -> V_129 ( V_21 ) ;
}
static int F_205 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_57 * V_57 ;
T_3 V_237 ;
V_57 = F_41 ( V_72 | V_238 | V_239 ) ;
if ( V_57 == NULL )
return - V_58 ;
F_206 ( V_57 , 1 ) ;
#ifdef F_4
V_237 = F_207 ( V_2 -> V_8 , V_57 , 0 , V_68 ,
V_56 ) ;
if ( F_208 ( V_2 -> V_8 , V_237 ) )
return - V_240 ;
#else
V_237 = F_209 ( V_57 ) ;
#endif
V_145 -> V_128 . V_27 . V_66 . V_57 = V_57 ;
V_145 -> V_128 . V_27 . V_66 . V_29 = V_237 ;
return 0 ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_57 * V_57 = V_145 -> V_128 . V_27 . V_66 . V_57 ;
F_211 ( V_57 , 1 ) ;
F_212 ( V_2 -> V_8 , V_145 -> V_128 . V_27 . V_66 . V_29 ,
V_68 , V_56 ) ;
F_29 ( V_57 ) ;
}
static unsigned int F_213 ( T_11 V_241 )
{
V_241 >>= V_242 ;
V_241 &= V_243 ;
return V_241 << 20 ;
}
static unsigned int F_214 ( T_11 V_244 )
{
V_244 >>= V_245 ;
V_244 &= V_246 ;
if ( V_244 )
V_244 = 1 << V_244 ;
#ifdef V_127
if ( V_244 > 4 )
V_244 = 4 ;
#endif
return V_244 << 20 ;
}
static unsigned int F_215 ( T_11 V_247 )
{
V_247 >>= V_242 ;
V_247 &= V_243 ;
if ( V_247 )
return 1 << ( 20 + V_247 ) ;
return 0 ;
}
static T_6 F_216 ( T_11 V_241 )
{
V_241 >>= V_248 ;
V_241 &= V_249 ;
return V_241 << 25 ;
}
static T_6 F_217 ( T_11 V_244 )
{
V_244 >>= V_250 ;
V_244 &= V_251 ;
return V_244 << 25 ;
}
static T_6 F_218 ( T_11 V_247 )
{
V_247 >>= V_248 ;
V_247 &= V_249 ;
if ( V_247 < 0x11 )
return V_247 << 25 ;
else if ( V_247 < 0x17 )
return ( V_247 - 0x11 + 2 ) << 22 ;
else
return ( V_247 - 0x17 + 9 ) << 22 ;
}
static T_6 F_219 ( T_11 V_252 )
{
V_252 >>= V_250 ;
V_252 &= V_251 ;
if ( V_252 < 0xf0 )
return V_252 << 25 ;
else
return ( V_252 - 0xf0 + 1 ) << 22 ;
}
static int F_220 ( struct V_1 * V_2 ,
T_6 V_235 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
T_12 V_253 ;
int V_71 ;
V_253 = F_221 ( V_2 -> V_8 , 0 ) +
( F_222 ( V_2 -> V_8 , 0 ) / 2 ) ;
if ( F_223 ( V_2 ) )
V_145 -> V_128 . V_146 = F_224 ( V_253 , V_235 ) ;
else
V_145 -> V_128 . V_146 = F_225 ( V_253 , V_235 ) ;
if ( ! V_145 -> V_128 . V_146 ) {
F_157 ( L_24 ) ;
return - V_58 ;
}
V_71 = F_205 ( V_2 ) ;
if ( V_71 ) {
F_157 ( L_25 ) ;
F_226 ( V_145 -> V_128 . V_146 ) ;
}
return V_71 ;
}
static void F_227 ( struct V_144 * V_145 )
{
T_7 V_254 ;
V_254 = F_228 ( 0 , V_255 | V_256 ) |
F_228 ( 1 , V_257 | V_258 ) |
F_228 ( 2 , V_259 | V_258 ) |
F_228 ( 3 , V_260 ) |
F_228 ( 4 , V_255 | V_258 | F_229 ( 0 ) ) |
F_228 ( 5 , V_255 | V_258 | F_229 ( 1 ) ) |
F_228 ( 6 , V_255 | V_258 | F_229 ( 2 ) ) |
F_228 ( 7 , V_255 | V_258 | F_229 ( 3 ) ) ;
if ( ! F_143 ( V_145 -> V_2 ) )
V_254 = F_228 ( 0 , V_260 ) ;
F_98 ( V_261 , V_254 ) ;
F_98 ( V_261 + 4 , V_254 >> 32 ) ;
}
static void F_230 ( struct V_144 * V_145 )
{
T_7 V_254 ;
V_254 = F_228 ( 0 , V_262 ) |
F_228 ( 1 , 0 ) |
F_228 ( 2 , 0 ) |
F_228 ( 3 , 0 ) |
F_228 ( 4 , V_262 ) |
F_228 ( 5 , V_262 ) |
F_228 ( 6 , V_262 ) |
F_228 ( 7 , V_262 ) ;
F_98 ( V_261 , V_254 ) ;
F_98 ( V_261 + 4 , V_254 >> 32 ) ;
}
static int F_231 ( struct V_1 * V_2 ,
T_6 * V_263 ,
T_6 * V_264 ,
T_12 * V_265 ,
unsigned long * V_189 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
unsigned int V_235 ;
T_11 V_241 ;
int V_71 ;
* V_265 = F_221 ( V_2 -> V_8 , 2 ) ;
* V_189 = F_222 ( V_2 -> V_8 , 2 ) ;
if ( ! F_232 ( V_2 -> V_8 , F_233 ( 39 ) ) )
F_234 ( V_2 -> V_8 , F_233 ( 39 ) ) ;
F_235 ( V_2 -> V_8 , V_266 , & V_241 ) ;
if ( F_2 ( V_2 ) -> V_6 >= 9 ) {
* V_264 = F_219 ( V_241 ) ;
V_235 = F_214 ( V_241 ) ;
} else if ( F_7 ( V_2 ) ) {
* V_264 = F_218 ( V_241 ) ;
V_235 = F_215 ( V_241 ) ;
} else {
* V_264 = F_217 ( V_241 ) ;
V_235 = F_214 ( V_241 ) ;
}
* V_263 = ( V_235 / sizeof( T_2 ) ) << V_103 ;
if ( F_7 ( V_2 ) || F_223 ( V_2 ) )
F_230 ( V_145 ) ;
else
F_227 ( V_145 ) ;
V_71 = F_220 ( V_2 , V_235 ) ;
V_145 -> V_128 . V_27 . V_26 = F_176 ;
V_145 -> V_128 . V_27 . V_22 = F_172 ;
V_145 -> V_128 . V_27 . V_132 = F_184 ;
V_145 -> V_128 . V_27 . V_131 = F_186 ;
return V_71 ;
}
static int F_236 ( struct V_1 * V_2 ,
T_6 * V_263 ,
T_6 * V_264 ,
T_12 * V_265 ,
unsigned long * V_189 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
unsigned int V_235 ;
T_11 V_241 ;
int V_71 ;
* V_265 = F_221 ( V_2 -> V_8 , 2 ) ;
* V_189 = F_222 ( V_2 -> V_8 , 2 ) ;
if ( ( * V_189 < ( 64 << 20 ) || ( * V_189 > ( 512 << 20 ) ) ) ) {
F_157 ( L_26 ,
V_145 -> V_128 . V_189 ) ;
return - V_267 ;
}
if ( ! F_232 ( V_2 -> V_8 , F_233 ( 40 ) ) )
F_234 ( V_2 -> V_8 , F_233 ( 40 ) ) ;
F_235 ( V_2 -> V_8 , V_266 , & V_241 ) ;
* V_264 = F_216 ( V_241 ) ;
V_235 = F_213 ( V_241 ) ;
* V_263 = ( V_235 / sizeof( T_5 ) ) << V_103 ;
V_71 = F_220 ( V_2 , V_235 ) ;
V_145 -> V_128 . V_27 . V_26 = F_179 ;
V_145 -> V_128 . V_27 . V_22 = F_175 ;
V_145 -> V_128 . V_27 . V_132 = F_184 ;
V_145 -> V_128 . V_27 . V_131 = F_186 ;
return V_71 ;
}
static void F_237 ( struct V_62 * V_21 )
{
struct V_268 * V_128 = F_57 ( V_21 , struct V_268 , V_27 ) ;
F_226 ( V_128 -> V_146 ) ;
F_210 ( V_21 -> V_2 ) ;
}
static int F_238 ( struct V_1 * V_2 ,
T_6 * V_263 ,
T_6 * V_264 ,
T_12 * V_265 ,
unsigned long * V_189 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
int V_71 ;
V_71 = F_239 ( V_145 -> V_269 , V_145 -> V_2 -> V_8 , NULL ) ;
if ( ! V_71 ) {
F_157 ( L_27 ) ;
return - V_270 ;
}
F_240 ( V_263 , V_264 , V_265 , V_189 ) ;
V_145 -> V_128 . V_202 = F_151 ( V_145 -> V_2 ) ;
V_145 -> V_128 . V_27 . V_22 = F_180 ;
V_145 -> V_128 . V_27 . V_26 = F_182 ;
V_145 -> V_128 . V_27 . V_132 = F_184 ;
V_145 -> V_128 . V_27 . V_131 = F_186 ;
if ( F_155 ( V_145 -> V_128 . V_202 ) )
F_5 ( L_28 ) ;
return 0 ;
}
static void F_241 ( struct V_62 * V_21 )
{
F_242 () ;
}
int F_243 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_268 * V_128 = & V_145 -> V_128 ;
int V_71 ;
if ( F_2 ( V_2 ) -> V_6 <= 5 ) {
V_128 -> V_271 = F_238 ;
V_128 -> V_27 . V_129 = F_241 ;
} else if ( F_2 ( V_2 ) -> V_6 < 8 ) {
V_128 -> V_271 = F_236 ;
V_128 -> V_27 . V_129 = F_237 ;
if ( F_108 ( V_2 ) && V_145 -> V_272 )
V_128 -> V_27 . V_137 = F_20 ;
else if ( F_108 ( V_2 ) )
V_128 -> V_27 . V_137 = F_18 ;
else if ( F_6 ( V_2 ) )
V_128 -> V_27 . V_137 = F_17 ;
else if ( F_2 ( V_2 ) -> V_6 >= 7 )
V_128 -> V_27 . V_137 = F_16 ;
else
V_128 -> V_27 . V_137 = F_13 ;
} else {
V_145 -> V_128 . V_271 = F_231 ;
V_145 -> V_128 . V_27 . V_129 = F_237 ;
}
V_71 = V_128 -> V_271 ( V_2 , & V_128 -> V_27 . V_126 , & V_128 -> V_273 ,
& V_128 -> V_265 , & V_128 -> V_189 ) ;
if ( V_71 )
return V_71 ;
V_128 -> V_27 . V_2 = V_2 ;
F_5 ( L_29 ,
V_128 -> V_27 . V_126 >> 20 ) ;
F_8 ( L_30 , V_128 -> V_189 >> 20 ) ;
F_8 ( L_31 , V_128 -> V_273 >> 20 ) ;
#ifdef F_4
if ( V_7 )
F_5 ( L_32 ) ;
#endif
V_10 . V_3 = F_1 ( V_2 , V_10 . V_3 ) ;
F_8 ( L_33 , V_10 . V_3 ) ;
return 0 ;
}
void F_244 ( struct V_1 * V_2 )
{
struct V_144 * V_145 = V_2 -> V_154 ;
struct V_209 * V_18 ;
struct V_62 * V_21 ;
struct V_12 * V_13 ;
bool V_148 ;
F_160 ( V_2 ) ;
V_145 -> V_128 . V_27 . V_26 ( & V_145 -> V_128 . V_27 ,
V_145 -> V_128 . V_27 . V_25 ,
V_145 -> V_128 . V_27 . V_126 ,
true ) ;
V_21 = & V_145 -> V_128 . V_27 ;
F_194 (obj, &dev_priv->mm.bound_list, global_list) {
V_148 = false ;
F_194 (vma, &obj->vma_list, vma_link) {
if ( V_13 -> V_21 != V_21 )
continue;
F_27 ( F_245 ( V_13 , V_18 -> V_15 ,
V_274 ) ) ;
V_148 = true ;
}
if ( V_148 )
F_246 ( V_18 , V_18 -> V_275 ) ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 ) {
if ( F_7 ( V_2 ) || F_223 ( V_2 ) )
F_230 ( V_145 ) ;
else
F_227 ( V_145 ) ;
return;
}
if ( F_143 ( V_2 ) ) {
F_194 (vm, &dev_priv->vm_list, global_link) {
struct V_86 * V_87 =
F_57 ( V_21 , struct V_86 ,
V_27 ) ;
if ( F_247 ( V_21 ) )
V_87 = V_145 -> V_183 . V_193 ;
F_92 ( V_145 , & V_87 -> V_77 ,
0 , V_87 -> V_27 . V_126 ) ;
}
}
F_164 ( V_145 ) ;
}
static struct V_12 *
F_248 ( struct V_209 * V_18 ,
struct V_62 * V_21 ,
const struct V_276 * V_220 )
{
struct V_12 * V_13 ;
if ( F_27 ( F_247 ( V_21 ) != ! ! V_220 ) )
return F_38 ( - V_240 ) ;
V_13 = F_249 ( F_83 ( V_18 -> V_27 . V_2 ) -> V_277 , V_72 ) ;
if ( V_13 == NULL )
return F_38 ( - V_58 ) ;
F_250 ( & V_13 -> V_278 ) ;
F_250 ( & V_13 -> V_279 ) ;
F_250 ( & V_13 -> V_280 ) ;
V_13 -> V_21 = V_21 ;
V_13 -> V_18 = V_18 ;
if ( F_247 ( V_21 ) )
V_13 -> V_220 = * V_220 ;
F_251 ( & V_13 -> V_278 , & V_18 -> V_281 ) ;
if ( ! F_247 ( V_21 ) )
F_252 ( F_253 ( V_21 ) ) ;
return V_13 ;
}
struct V_12 *
F_254 ( struct V_209 * V_18 ,
struct V_62 * V_21 )
{
struct V_12 * V_13 ;
V_13 = F_195 ( V_18 , V_21 ) ;
if ( ! V_13 )
V_13 = F_248 ( V_18 , V_21 ,
F_247 ( V_21 ) ? & V_282 : NULL ) ;
return V_13 ;
}
struct V_12 *
F_255 ( struct V_209 * V_18 ,
const struct V_276 * V_283 )
{
struct V_62 * V_284 = F_256 ( V_18 ) ;
struct V_12 * V_13 ;
if ( F_27 ( ! V_283 ) )
return F_38 ( - V_240 ) ;
V_13 = F_257 ( V_18 , V_283 ) ;
if ( F_68 ( V_13 ) )
return V_13 ;
if ( ! V_13 )
V_13 = F_248 ( V_18 , V_284 , V_283 ) ;
return V_13 ;
}
static void
F_258 ( T_3 * V_285 , unsigned int V_286 , unsigned int V_287 ,
struct V_106 * V_212 )
{
unsigned int V_288 , V_289 ;
unsigned int V_290 ;
struct V_291 * V_214 = V_212 -> V_210 ;
V_212 -> V_211 = 0 ;
for ( V_288 = 0 ; V_288 < V_286 ; V_288 ++ ) {
V_290 = V_286 * ( V_287 - 1 ) + V_288 ;
for ( V_289 = 0 ; V_289 < V_287 ; V_289 ++ ) {
V_212 -> V_211 ++ ;
F_259 ( V_214 , NULL , V_68 , 0 ) ;
F_173 ( V_214 ) = V_285 [ V_290 ] ;
F_260 ( V_214 ) = V_68 ;
V_214 = F_261 ( V_214 ) ;
V_290 -= V_286 ;
}
}
}
static struct V_106 *
F_262 ( struct V_276 * V_220 ,
struct V_209 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_27 . V_2 ;
struct V_292 * V_293 = & V_220 -> V_294 ;
unsigned long V_28 , V_23 , V_295 ;
struct V_107 V_108 ;
unsigned long V_65 ;
T_3 * V_296 ;
struct V_106 * V_212 ;
unsigned int V_297 , V_298 ;
unsigned int V_299 , V_300 ;
int V_71 = - V_58 ;
V_23 = V_18 -> V_27 . V_28 / V_68 ;
V_298 = F_263 ( V_2 , V_293 -> V_301 ,
V_293 -> V_302 ) ;
V_297 = V_68 / V_298 ;
V_299 = F_264 ( V_293 -> V_303 , V_297 ) ;
V_300 = F_264 ( V_293 -> V_287 , V_298 ) ;
V_295 = V_299 * V_300 ;
V_28 = V_295 * V_68 ;
V_296 = F_265 ( V_23 , sizeof( T_3 ) ) ;
if ( ! V_296 )
return F_38 ( V_71 ) ;
V_212 = F_266 ( sizeof( * V_212 ) , V_72 ) ;
if ( ! V_212 )
goto V_304;
V_71 = F_267 ( V_212 , V_295 , V_72 ) ;
if ( V_71 )
goto V_305;
V_65 = 0 ;
F_59 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_296 [ V_65 ] = F_60 ( & V_108 ) ;
V_65 ++ ;
}
F_258 ( V_296 , V_299 , V_300 , V_212 ) ;
F_196 (
L_34 ,
V_28 , V_293 -> V_303 , V_293 -> V_287 ,
V_293 -> V_301 , V_299 , V_300 ,
V_295 ) ;
F_268 ( V_296 ) ;
return V_212 ;
V_305:
F_30 ( V_212 ) ;
V_304:
F_268 ( V_296 ) ;
F_196 (
L_35 ,
V_28 , V_71 , V_293 -> V_303 , V_293 -> V_287 ,
V_293 -> V_301 , V_299 , V_300 ,
V_295 ) ;
return F_38 ( V_71 ) ;
}
static struct V_106 *
F_269 ( const struct V_276 * V_283 ,
struct V_209 * V_18 )
{
struct V_106 * V_212 ;
struct V_291 * V_214 ;
struct V_107 V_306 ;
int V_71 = - V_58 ;
V_212 = F_266 ( sizeof( * V_212 ) , V_72 ) ;
if ( ! V_212 )
goto V_304;
V_71 = F_267 ( V_212 , V_283 -> V_307 . V_308 . V_28 , V_72 ) ;
if ( V_71 )
goto V_305;
V_214 = V_212 -> V_210 ;
V_212 -> V_211 = 0 ;
F_59 (obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if ( V_212 -> V_211 >= V_283 -> V_307 . V_308 . V_28 )
break;
F_259 ( V_214 , NULL , V_68 , 0 ) ;
F_173 ( V_214 ) = F_60 ( & V_306 ) ;
F_260 ( V_214 ) = V_68 ;
V_214 = F_261 ( V_214 ) ;
V_212 -> V_211 ++ ;
}
return V_212 ;
V_305:
F_30 ( V_212 ) ;
V_304:
return F_38 ( V_71 ) ;
}
static int
F_185 ( struct V_12 * V_13 )
{
int V_71 = 0 ;
if ( V_13 -> V_220 . V_23 )
return 0 ;
if ( V_13 -> V_220 . type == V_309 )
V_13 -> V_220 . V_23 = V_13 -> V_18 -> V_23 ;
else if ( V_13 -> V_220 . type == V_310 )
V_13 -> V_220 . V_23 =
F_262 ( & V_13 -> V_220 , V_13 -> V_18 ) ;
else if ( V_13 -> V_220 . type == V_311 )
V_13 -> V_220 . V_23 =
F_269 ( & V_13 -> V_220 , V_13 -> V_18 ) ;
else
F_270 ( 1 , L_36 ,
V_13 -> V_220 . type ) ;
if ( ! V_13 -> V_220 . V_23 ) {
F_157 ( L_37 ,
V_13 -> V_220 . type ) ;
V_71 = - V_240 ;
} else if ( F_68 ( V_13 -> V_220 . V_23 ) ) {
V_71 = F_81 ( V_13 -> V_220 . V_23 ) ;
V_13 -> V_220 . V_23 = NULL ;
F_157 ( L_38 ,
V_13 -> V_220 . type , V_71 ) ;
}
return V_71 ;
}
int F_245 ( struct V_12 * V_13 , enum V_14 V_15 ,
T_1 V_48 )
{
int V_71 ;
T_1 V_312 ;
if ( F_27 ( V_48 == 0 ) )
return - V_240 ;
V_312 = 0 ;
if ( V_48 & V_313 )
V_312 |= V_221 ;
if ( V_48 & V_314 )
V_312 |= V_223 ;
if ( V_48 & V_274 )
V_312 |= V_13 -> V_222 ;
else
V_312 &= ~ V_13 -> V_222 ;
if ( V_312 == 0 )
return 0 ;
if ( V_13 -> V_222 == 0 && V_13 -> V_21 -> V_130 ) {
F_271 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_24 . V_28 ,
F_272 ( V_13 -> V_21 ) ) ;
V_71 = V_13 -> V_21 -> V_130 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_24 . V_28 ) ;
if ( V_71 )
return V_71 ;
}
V_71 = V_13 -> V_21 -> V_132 ( V_13 , V_15 , V_312 ) ;
if ( V_71 )
return V_71 ;
V_13 -> V_222 |= V_312 ;
return 0 ;
}
T_6
F_273 ( struct V_209 * V_18 ,
const struct V_276 * V_283 )
{
if ( V_283 -> type == V_309 ||
V_283 -> type == V_310 ) {
return V_18 -> V_27 . V_28 ;
} else if ( V_283 -> type == V_311 ) {
return V_283 -> V_307 . V_308 . V_28 << V_103 ;
} else {
F_270 ( 1 , L_36 , V_283 -> type ) ;
return V_18 -> V_27 . V_28 ;
}
}
