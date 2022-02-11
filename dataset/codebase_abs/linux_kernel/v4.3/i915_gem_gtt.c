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
static T_4 F_12 ( const T_3 V_29 ,
const enum V_14 V_30 )
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
static int F_21 ( struct V_1 * V_2 ,
struct V_54 * V_55 , T_6 V_48 )
{
struct V_56 * V_56 = & V_2 -> V_8 -> V_2 ;
V_55 -> V_57 = F_22 ( V_48 ) ;
if ( ! V_55 -> V_57 )
return - V_58 ;
V_55 -> V_59 = F_23 ( V_56 ,
V_55 -> V_57 , 0 , 4096 , V_60 ) ;
if ( F_24 ( V_56 , V_55 -> V_59 ) ) {
F_25 ( V_55 -> V_57 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
return F_21 ( V_2 , V_55 , V_62 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
if ( F_28 ( ! V_55 -> V_57 ) )
return;
F_29 ( & V_2 -> V_8 -> V_2 , V_55 -> V_59 , 4096 , V_60 ) ;
F_25 ( V_55 -> V_57 ) ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
}
static void * F_30 ( struct V_54 * V_55 )
{
return F_31 ( V_55 -> V_57 ) ;
}
static void F_32 ( struct V_1 * V_2 , void * V_63 )
{
if ( F_7 ( V_2 ) || F_33 ( V_2 ) )
F_34 ( V_63 , V_64 ) ;
F_35 ( V_63 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_54 * V_55 ,
const T_7 V_65 )
{
int V_66 ;
T_7 * const V_63 = F_30 ( V_55 ) ;
for ( V_66 = 0 ; V_66 < 512 ; V_66 ++ )
V_63 [ V_66 ] = V_65 ;
F_32 ( V_2 , V_63 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_54 * V_55 ,
const T_8 V_67 )
{
T_7 V_68 = V_67 ;
V_68 = V_68 << 32 | V_67 ;
F_36 ( V_2 , V_55 , V_68 ) ;
}
static struct V_69 * F_38 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
int V_71 ;
V_70 = F_39 ( sizeof( * V_70 ) , V_62 ) ;
if ( V_70 == NULL )
return F_40 ( - V_58 ) ;
V_71 = F_21 ( V_2 , F_41 ( V_70 ) , V_72 | V_73 ) ;
if ( V_71 ) {
F_42 ( V_70 ) ;
return F_40 ( V_71 ) ;
}
F_43 ( F_44 ( V_70 ) , 1 ) ;
return V_70 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
F_46 ( F_44 ( V_70 ) , 1 ) ;
F_47 ( V_2 , V_70 ) ;
F_42 ( V_70 ) ;
}
static struct V_74 * F_48 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
const T_9 V_76 = F_2 ( V_2 ) -> V_6 >= 8 ?
V_77 : V_78 ;
int V_71 = - V_58 ;
V_75 = F_39 ( sizeof( * V_75 ) , V_62 ) ;
if ( ! V_75 )
return F_40 ( - V_58 ) ;
V_75 -> V_79 = F_49 ( F_50 ( V_76 ) , sizeof( * V_75 -> V_79 ) ,
V_62 ) ;
if ( ! V_75 -> V_79 )
goto V_80;
V_71 = F_51 ( V_2 , V_75 ) ;
if ( V_71 )
goto V_81;
return V_75 ;
V_81:
F_42 ( V_75 -> V_79 ) ;
V_80:
F_42 ( V_75 ) ;
return F_40 ( V_71 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
F_47 ( V_2 , V_75 ) ;
F_42 ( V_75 -> V_79 ) ;
F_42 ( V_75 ) ;
}
static void F_53 ( struct V_82 * V_21 ,
struct V_74 * V_75 )
{
T_2 V_83 ;
V_83 = F_11 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true ) ;
F_55 ( V_21 -> V_2 , V_75 , V_83 ) ;
}
static void F_56 ( struct V_82 * V_21 ,
struct V_74 * V_75 )
{
T_5 V_83 ;
F_28 ( F_54 ( V_21 -> V_84 ) == 0 ) ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true , 0 ) ;
F_57 ( V_21 -> V_2 , V_75 , V_83 ) ;
}
static struct V_86 * F_58 ( struct V_1 * V_2 )
{
struct V_86 * V_87 ;
int V_71 = - V_58 ;
V_87 = F_39 ( sizeof( * V_87 ) , V_62 ) ;
if ( ! V_87 )
return F_40 ( - V_58 ) ;
V_87 -> V_88 = F_49 ( F_50 ( V_89 ) ,
sizeof( * V_87 -> V_88 ) , V_62 ) ;
if ( ! V_87 -> V_88 )
goto V_80;
V_71 = F_51 ( V_2 , V_87 ) ;
if ( V_71 )
goto V_81;
return V_87 ;
V_81:
F_42 ( V_87 -> V_88 ) ;
V_80:
F_42 ( V_87 ) ;
return F_40 ( V_71 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
if ( F_44 ( V_87 ) ) {
F_47 ( V_2 , V_87 ) ;
F_42 ( V_87 -> V_88 ) ;
F_42 ( V_87 ) ;
}
}
static void F_60 ( struct V_82 * V_21 ,
struct V_86 * V_87 )
{
T_4 V_90 ;
V_90 = F_12 ( F_54 ( V_21 -> V_91 ) , V_44 ) ;
F_55 ( V_21 -> V_2 , V_87 , V_90 ) ;
}
static int F_61 ( struct V_92 * V_93 ,
unsigned V_94 ,
T_3 V_29 )
{
struct V_95 * V_96 = V_93 -> V_96 ;
int V_71 ;
F_62 ( V_94 >= 4 ) ;
V_71 = F_63 ( V_93 , 6 ) ;
if ( V_71 )
return V_71 ;
F_64 ( V_96 , F_65 ( 1 ) ) ;
F_64 ( V_96 , F_66 ( V_96 , V_94 ) ) ;
F_64 ( V_96 , F_67 ( V_29 ) ) ;
F_64 ( V_96 , F_65 ( 1 ) ) ;
F_64 ( V_96 , F_68 ( V_96 , V_94 ) ) ;
F_64 ( V_96 , F_69 ( V_29 ) ) ;
F_70 ( V_96 ) ;
return 0 ;
}
static int F_71 ( struct V_97 * V_98 ,
struct V_92 * V_93 )
{
int V_66 , V_71 ;
for ( V_66 = V_99 - 1 ; V_66 >= 0 ; V_66 -- ) {
const T_3 V_100 = F_72 ( V_98 , V_66 ) ;
V_71 = F_61 ( V_93 , V_66 , V_100 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
static void F_73 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_101 ,
bool V_102 )
{
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
T_2 * V_103 , V_83 ;
unsigned V_104 = V_25 >> V_105 & V_106 ;
unsigned V_40 = V_25 >> V_107 & V_108 ;
unsigned V_32 = V_25 >> V_109 & V_110 ;
unsigned V_111 = V_101 >> V_112 ;
unsigned V_113 , V_66 ;
V_83 = F_11 ( F_54 ( V_98 -> V_27 . V_84 ) ,
V_44 , V_102 ) ;
while ( V_111 ) {
struct V_86 * V_87 ;
struct V_74 * V_75 ;
if ( F_28 ( ! V_98 -> V_114 . V_115 [ V_104 ] ) )
break;
V_87 = V_98 -> V_114 . V_115 [ V_104 ] ;
if ( F_28 ( ! V_87 -> V_116 [ V_40 ] ) )
break;
V_75 = V_87 -> V_116 [ V_40 ] ;
if ( F_28 ( ! F_44 ( V_75 ) ) )
break;
V_113 = V_32 + V_111 ;
if ( V_113 > V_77 )
V_113 = V_77 ;
V_103 = F_75 ( V_75 ) ;
for ( V_66 = V_32 ; V_66 < V_113 ; V_66 ++ ) {
V_103 [ V_66 ] = V_83 ;
V_111 -- ;
}
F_76 ( V_98 , V_75 ) ;
V_32 = 0 ;
if ( ++ V_40 == V_89 ) {
V_104 ++ ;
V_40 = 0 ;
}
}
}
static void F_77 ( struct V_82 * V_21 ,
struct V_117 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_16 )
{
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
T_2 * V_103 ;
unsigned V_104 = V_25 >> V_105 & V_106 ;
unsigned V_40 = V_25 >> V_107 & V_108 ;
unsigned V_32 = V_25 >> V_109 & V_110 ;
struct V_118 V_119 ;
V_103 = NULL ;
F_78 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_28 ( V_104 >= V_99 ) )
break;
if ( V_103 == NULL ) {
struct V_86 * V_87 = V_98 -> V_114 . V_115 [ V_104 ] ;
struct V_74 * V_75 = V_87 -> V_116 [ V_40 ] ;
V_103 = F_75 ( V_75 ) ;
}
V_103 [ V_32 ] =
F_11 ( F_79 ( & V_119 ) ,
V_15 , true ) ;
if ( ++ V_32 == V_77 ) {
F_76 ( V_98 , V_103 ) ;
V_103 = NULL ;
if ( ++ V_40 == V_89 ) {
V_104 ++ ;
V_40 = 0 ;
}
V_32 = 0 ;
}
}
if ( V_103 )
F_76 ( V_98 , V_103 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
int V_66 ;
if ( ! F_44 ( V_87 ) )
return;
F_81 (i, pd->used_pdes, I915_PDES) {
if ( F_28 ( ! V_87 -> V_116 [ V_66 ] ) )
continue;
F_52 ( V_2 , V_87 -> V_116 [ V_66 ] ) ;
V_87 -> V_116 [ V_66 ] = NULL ;
}
}
static int F_82 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
V_21 -> V_84 = F_38 ( V_2 ) ;
if ( F_83 ( V_21 -> V_84 ) )
return F_84 ( V_21 -> V_84 ) ;
V_21 -> V_91 = F_48 ( V_2 ) ;
if ( F_83 ( V_21 -> V_91 ) ) {
F_45 ( V_2 , V_21 -> V_84 ) ;
return F_84 ( V_21 -> V_91 ) ;
}
V_21 -> V_120 = F_58 ( V_2 ) ;
if ( F_83 ( V_21 -> V_120 ) ) {
F_52 ( V_2 , V_21 -> V_91 ) ;
F_45 ( V_2 , V_21 -> V_84 ) ;
return F_84 ( V_21 -> V_120 ) ;
}
F_53 ( V_21 , V_21 -> V_91 ) ;
F_60 ( V_21 , V_21 -> V_120 ) ;
return 0 ;
}
static void F_85 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
F_59 ( V_2 , V_21 -> V_120 ) ;
F_52 ( V_2 , V_21 -> V_91 ) ;
F_45 ( V_2 , V_21 -> V_84 ) ;
}
static void F_86 ( struct V_82 * V_21 )
{
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
int V_66 ;
F_81 (i, ppgtt->pdp.used_pdpes, GEN8_LEGACY_PDPES) {
if ( F_28 ( ! V_98 -> V_114 . V_115 [ V_66 ] ) )
continue;
F_80 ( V_98 -> V_27 . V_2 ,
V_98 -> V_114 . V_115 [ V_66 ] ) ;
F_59 ( V_98 -> V_27 . V_2 , V_98 -> V_114 . V_115 [ V_66 ] ) ;
}
F_85 ( V_21 ) ;
}
static int F_87 ( struct V_97 * V_98 ,
struct V_86 * V_87 ,
T_7 V_25 ,
T_7 V_101 ,
unsigned long * V_121 )
{
struct V_1 * V_2 = V_98 -> V_27 . V_2 ;
struct V_74 * V_75 ;
T_7 V_122 ;
T_8 V_40 ;
F_88 (pt, pd, start, length, temp, pde) {
if ( V_75 ) {
F_28 ( V_75 == V_98 -> V_27 . V_91 ) ;
continue;
}
V_75 = F_48 ( V_2 ) ;
if ( F_83 ( V_75 ) )
goto V_123;
F_53 ( & V_98 -> V_27 , V_75 ) ;
V_87 -> V_116 [ V_40 ] = V_75 ;
F_89 ( V_40 , V_121 ) ;
}
return 0 ;
V_123:
F_81 (pde, new_pts, I915_PDES)
F_52 ( V_2 , V_87 -> V_116 [ V_40 ] ) ;
return - V_58 ;
}
static int F_90 ( struct V_97 * V_98 ,
struct V_124 * V_114 ,
T_7 V_25 ,
T_7 V_101 ,
unsigned long * V_125 )
{
struct V_1 * V_2 = V_98 -> V_27 . V_2 ;
struct V_86 * V_87 ;
T_7 V_122 ;
T_8 V_104 ;
F_28 ( ! F_91 ( V_125 , V_99 ) ) ;
F_92 (pd, pdp, start, length, temp, pdpe) {
if ( V_87 )
continue;
V_87 = F_58 ( V_2 ) ;
if ( F_83 ( V_87 ) )
goto V_123;
F_60 ( & V_98 -> V_27 , V_87 ) ;
V_114 -> V_115 [ V_104 ] = V_87 ;
F_89 ( V_104 , V_125 ) ;
}
return 0 ;
V_123:
F_81 (pdpe, new_pds, GEN8_LEGACY_PDPES)
F_59 ( V_2 , V_114 -> V_115 [ V_104 ] ) ;
return - V_58 ;
}
static void
F_93 ( unsigned long * V_125 , unsigned long * * V_121 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_99 ; V_66 ++ )
F_42 ( V_121 [ V_66 ] ) ;
F_42 ( V_121 ) ;
F_42 ( V_125 ) ;
}
static
int T_10 F_94 ( unsigned long * * V_125 ,
unsigned long * * * V_121 )
{
int V_66 ;
unsigned long * V_126 ;
unsigned long * * V_127 ;
V_126 = F_49 ( F_50 ( V_99 ) , sizeof( unsigned long ) , V_62 ) ;
if ( ! V_126 )
return - V_58 ;
V_127 = F_49 ( V_99 , sizeof( unsigned long * ) , V_62 ) ;
if ( ! V_127 ) {
F_42 ( V_126 ) ;
return - V_58 ;
}
for ( V_66 = 0 ; V_66 < V_99 ; V_66 ++ ) {
V_127 [ V_66 ] = F_49 ( F_50 ( V_89 ) ,
sizeof( unsigned long ) , V_62 ) ;
if ( ! V_127 [ V_66 ] )
goto V_128;
}
* V_125 = V_126 ;
* V_121 = V_127 ;
return 0 ;
V_128:
F_93 ( V_126 , V_127 ) ;
return - V_58 ;
}
static void F_95 ( struct V_97 * V_98 )
{
V_98 -> V_129 = F_2 ( V_98 -> V_27 . V_2 ) -> V_130 ;
}
static int F_96 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_101 )
{
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
unsigned long * V_131 , * * V_132 ;
struct V_86 * V_87 ;
const T_7 V_133 = V_25 ;
const T_7 V_134 = V_101 ;
T_7 V_122 ;
T_8 V_104 ;
int V_71 ;
if ( F_28 ( V_25 + V_101 < V_25 ) )
return - V_135 ;
if ( F_28 ( V_25 + V_101 > V_98 -> V_27 . V_136 ) )
return - V_135 ;
V_71 = F_94 ( & V_131 , & V_132 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_90 ( V_98 , & V_98 -> V_114 , V_25 , V_101 ,
V_131 ) ;
if ( V_71 ) {
F_93 ( V_131 , V_132 ) ;
return V_71 ;
}
F_92 (pd, &ppgtt->pdp, start, length, temp, pdpe) {
V_71 = F_87 ( V_98 , V_87 , V_25 , V_101 ,
V_132 [ V_104 ] ) ;
if ( V_71 )
goto V_128;
}
V_25 = V_133 ;
V_101 = V_134 ;
F_92 (pd, &ppgtt->pdp, start, length, temp, pdpe) {
T_4 * const V_115 = F_75 ( V_87 ) ;
struct V_74 * V_75 ;
T_7 V_137 = F_97 ( V_25 , V_101 ) ;
T_7 V_138 = V_25 ;
T_8 V_40 ;
F_28 ( ! V_87 ) ;
F_88 (pt, pd, pd_start, pd_len, temp, pde) {
F_28 ( ! V_75 ) ;
F_28 ( ! V_137 ) ;
F_28 ( ! F_98 ( V_138 , V_137 ) ) ;
F_99 ( V_75 -> V_79 ,
F_100 ( V_138 ) ,
F_98 ( V_138 , V_137 ) ) ;
F_89 ( V_40 , V_87 -> V_88 ) ;
V_115 [ V_40 ] = F_12 ( F_54 ( V_75 ) ,
V_44 ) ;
}
F_76 ( V_98 , V_115 ) ;
F_89 ( V_104 , V_98 -> V_114 . V_139 ) ;
}
F_93 ( V_131 , V_132 ) ;
F_95 ( V_98 ) ;
return 0 ;
V_128:
while ( V_104 -- ) {
F_81 (temp, new_page_tables[pdpe], I915_PDES)
F_52 ( V_21 -> V_2 , V_98 -> V_114 . V_115 [ V_104 ] -> V_116 [ V_122 ] ) ;
}
F_81 (pdpe, new_page_dirs, GEN8_LEGACY_PDPES)
F_59 ( V_21 -> V_2 , V_98 -> V_114 . V_115 [ V_104 ] ) ;
F_93 ( V_131 , V_132 ) ;
F_95 ( V_98 ) ;
return V_71 ;
}
static int F_101 ( struct V_97 * V_98 )
{
int V_71 ;
V_71 = F_82 ( & V_98 -> V_27 ) ;
if ( V_71 )
return V_71 ;
V_98 -> V_27 . V_25 = 0 ;
V_98 -> V_27 . V_136 = 1ULL << 32 ;
if ( F_102 ( V_140 ) )
V_98 -> V_27 . V_136 = F_103 ( V_98 -> V_27 . V_2 ) -> V_141 . V_27 . V_136 ;
V_98 -> V_27 . V_142 = F_86 ;
V_98 -> V_27 . V_143 = F_96 ;
V_98 -> V_27 . V_22 = F_77 ;
V_98 -> V_27 . V_26 = F_73 ;
V_98 -> V_27 . V_144 = F_10 ;
V_98 -> V_27 . V_145 = F_9 ;
V_98 -> V_146 = F_71 ;
return 0 ;
}
static void F_104 ( struct V_97 * V_98 , struct V_147 * V_148 )
{
struct V_82 * V_21 = & V_98 -> V_27 ;
struct V_74 * V_16 ;
T_5 V_83 ;
T_8 V_149 ;
T_8 V_32 , V_40 , V_122 ;
T_8 V_25 = V_98 -> V_27 . V_25 , V_101 = V_98 -> V_27 . V_136 ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true , 0 ) ;
F_105 (unused, &ppgtt->pd, start, length, temp, pde) {
T_1 V_150 ;
T_5 * V_103 ;
const T_3 V_151 = F_54 ( V_98 -> V_87 . V_116 [ V_40 ] ) ;
V_149 = F_106 ( V_98 -> V_152 + V_40 ) ;
V_150 = ( F_107 ( V_151 ) | V_153 ) ;
if ( V_149 != V_150 )
F_108 ( V_148 , L_3 ,
V_40 ,
V_149 ,
V_150 ) ;
F_108 ( V_148 , L_4 , V_149 ) ;
V_103 = F_75 ( V_98 -> V_87 . V_116 [ V_40 ] ) ;
for ( V_32 = 0 ; V_32 < V_78 ; V_32 += 4 ) {
unsigned long V_154 =
( V_40 * V_64 * V_78 ) +
( V_32 * V_64 ) ;
int V_66 ;
bool V_155 = false ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ )
if ( V_103 [ V_32 + V_66 ] != V_83 )
V_155 = true ;
if ( ! V_155 )
continue;
F_108 ( V_148 , L_5 , V_154 , V_40 , V_32 ) ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ ) {
if ( V_103 [ V_32 + V_66 ] != V_83 )
F_108 ( V_148 , L_6 , V_103 [ V_32 + V_66 ] ) ;
else
F_109 ( V_148 , L_7 ) ;
}
F_109 ( V_148 , L_8 ) ;
}
F_76 ( V_98 , V_103 ) ;
}
}
static void F_110 ( struct V_86 * V_87 ,
const int V_40 , struct V_74 * V_75 )
{
struct V_97 * V_98 =
F_74 ( V_87 , struct V_97 , V_87 ) ;
T_1 V_149 ;
V_149 = F_107 ( F_54 ( V_75 ) ) ;
V_149 |= V_153 ;
F_111 ( V_149 , V_98 -> V_152 + V_40 ) ;
}
static void F_112 ( struct V_156 * V_157 ,
struct V_86 * V_87 ,
T_8 V_25 , T_8 V_101 )
{
struct V_74 * V_75 ;
T_8 V_40 , V_122 ;
F_105 (pt, pd, start, length, temp, pde)
F_110 ( V_87 , V_40 , V_75 ) ;
F_106 ( V_157 -> V_141 . V_158 ) ;
}
static T_8 F_113 ( struct V_97 * V_98 )
{
F_62 ( V_98 -> V_87 . V_27 . V_159 & 0x3f ) ;
return ( V_98 -> V_87 . V_27 . V_159 / 64 ) << 16 ;
}
static int F_114 ( struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_95 * V_96 = V_93 -> V_96 ;
int V_71 ;
V_71 = V_96 -> V_160 ( V_93 , V_161 , V_161 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_63 ( V_93 , 6 ) ;
if ( V_71 )
return V_71 ;
F_64 ( V_96 , F_65 ( 2 ) ) ;
F_64 ( V_96 , F_115 ( V_96 ) ) ;
F_64 ( V_96 , V_162 ) ;
F_64 ( V_96 , F_116 ( V_96 ) ) ;
F_64 ( V_96 , F_113 ( V_98 ) ) ;
F_64 ( V_96 , V_163 ) ;
F_70 ( V_96 ) ;
return 0 ;
}
static int F_117 ( struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_95 * V_96 = V_93 -> V_96 ;
struct V_156 * V_157 = F_103 ( V_98 -> V_27 . V_2 ) ;
F_118 ( F_115 ( V_96 ) , V_162 ) ;
F_118 ( F_116 ( V_96 ) , F_113 ( V_98 ) ) ;
return 0 ;
}
static int F_119 ( struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_95 * V_96 = V_93 -> V_96 ;
int V_71 ;
V_71 = V_96 -> V_160 ( V_93 , V_161 , V_161 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_63 ( V_93 , 6 ) ;
if ( V_71 )
return V_71 ;
F_64 ( V_96 , F_65 ( 2 ) ) ;
F_64 ( V_96 , F_115 ( V_96 ) ) ;
F_64 ( V_96 , V_162 ) ;
F_64 ( V_96 , F_116 ( V_96 ) ) ;
F_64 ( V_96 , F_113 ( V_98 ) ) ;
F_64 ( V_96 , V_163 ) ;
F_70 ( V_96 ) ;
if ( V_96 -> V_164 != V_165 ) {
V_71 = V_96 -> V_160 ( V_93 , V_161 , V_161 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
static int F_120 ( struct V_97 * V_98 ,
struct V_92 * V_93 )
{
struct V_95 * V_96 = V_93 -> V_96 ;
struct V_1 * V_2 = V_98 -> V_27 . V_2 ;
struct V_156 * V_157 = V_2 -> V_166 ;
F_118 ( F_115 ( V_96 ) , V_162 ) ;
F_118 ( F_116 ( V_96 ) , F_113 ( V_98 ) ) ;
F_121 ( F_115 ( V_96 ) ) ;
return 0 ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_95 * V_96 ;
int V_167 ;
F_123 (ring, dev_priv, j) {
F_118 ( F_124 ( V_96 ) ,
F_125 ( V_168 ) ) ;
}
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_95 * V_96 ;
T_8 V_169 , V_170 ;
int V_66 ;
V_170 = F_127 ( V_171 ) ;
F_118 ( V_171 , V_170 | V_172 ) ;
V_169 = F_127 ( V_173 ) ;
if ( F_128 ( V_2 ) ) {
V_169 |= V_174 ;
} else {
V_169 |= V_175 ;
V_169 &= ~ V_176 ;
}
F_118 ( V_173 , V_169 ) ;
F_123 (ring, dev_priv, i) {
F_118 ( F_124 ( V_96 ) ,
F_125 ( V_168 ) ) ;
}
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
T_8 V_169 , V_177 , V_170 ;
V_170 = F_127 ( V_171 ) ;
F_118 ( V_171 , V_170 | V_178 |
V_172 ) ;
V_177 = F_127 ( V_179 ) ;
F_118 ( V_179 , V_177 | V_180 ) ;
V_169 = F_127 ( V_173 ) ;
F_118 ( V_173 , V_169 | V_181 | V_182 ) ;
F_118 ( V_183 , F_125 ( V_168 ) ) ;
}
static void F_130 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_101 ,
bool V_102 )
{
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
T_5 * V_103 , V_83 ;
unsigned V_184 = V_25 >> V_112 ;
unsigned V_111 = V_101 >> V_112 ;
unsigned V_185 = V_184 / V_78 ;
unsigned V_186 = V_184 % V_78 ;
unsigned V_113 , V_66 ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true , 0 ) ;
while ( V_111 ) {
V_113 = V_186 + V_111 ;
if ( V_113 > V_78 )
V_113 = V_78 ;
V_103 = F_75 ( V_98 -> V_87 . V_116 [ V_185 ] ) ;
for ( V_66 = V_186 ; V_66 < V_113 ; V_66 ++ )
V_103 [ V_66 ] = V_83 ;
F_76 ( V_98 , V_103 ) ;
V_111 -= V_113 - V_186 ;
V_186 = 0 ;
V_185 ++ ;
}
}
static void F_131 ( struct V_82 * V_21 ,
struct V_117 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_48 )
{
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
T_5 * V_103 ;
unsigned V_184 = V_25 >> V_112 ;
unsigned V_185 = V_184 / V_78 ;
unsigned V_187 = V_184 % V_78 ;
struct V_118 V_119 ;
V_103 = NULL ;
F_78 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_103 == NULL )
V_103 = F_75 ( V_98 -> V_87 . V_116 [ V_185 ] ) ;
V_103 [ V_187 ] =
V_21 -> V_85 ( F_79 ( & V_119 ) ,
V_15 , true , V_48 ) ;
if ( ++ V_187 == V_78 ) {
F_76 ( V_98 , V_103 ) ;
V_103 = NULL ;
V_185 ++ ;
V_187 = 0 ;
}
}
if ( V_103 )
F_76 ( V_98 , V_103 ) ;
}
static int F_132 ( struct V_82 * V_21 ,
T_7 V_188 , T_7 V_189 )
{
F_133 ( V_132 , V_89 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
struct V_74 * V_75 ;
T_8 V_25 , V_101 , V_190 , V_191 ;
T_8 V_40 , V_122 ;
int V_71 ;
if ( F_28 ( V_188 + V_189 > V_98 -> V_27 . V_136 ) )
return - V_135 ;
V_25 = V_190 = V_188 ;
V_101 = V_191 = V_189 ;
F_134 ( V_132 , V_89 ) ;
F_105 (pt, &ppgtt->pd, start, length, temp, pde) {
if ( V_75 != V_21 -> V_91 ) {
F_28 ( F_91 ( V_75 -> V_79 , V_78 ) ) ;
continue;
}
F_28 ( ! F_91 ( V_75 -> V_79 , V_78 ) ) ;
V_75 = F_48 ( V_2 ) ;
if ( F_83 ( V_75 ) ) {
V_71 = F_84 ( V_75 ) ;
goto V_123;
}
F_56 ( V_21 , V_75 ) ;
V_98 -> V_87 . V_116 [ V_40 ] = V_75 ;
F_89 ( V_40 , V_132 ) ;
F_135 ( V_21 , V_40 , V_25 , V_192 ) ;
}
V_25 = V_190 ;
V_101 = V_191 ;
F_105 (pt, &ppgtt->pd, start, length, temp, pde) {
F_133 ( V_193 , V_78 ) ;
F_134 ( V_193 , V_78 ) ;
F_99 ( V_193 , F_136 ( V_25 ) ,
F_137 ( V_25 , V_101 ) ) ;
if ( F_138 ( V_40 , V_132 ) )
F_110 ( & V_98 -> V_87 , V_40 , V_75 ) ;
F_139 ( V_21 , V_40 , V_75 ,
F_136 ( V_25 ) ,
F_137 ( V_25 , V_101 ) ,
V_78 ) ;
F_140 ( V_75 -> V_79 , V_193 , V_75 -> V_79 ,
V_78 ) ;
}
F_28 ( ! F_91 ( V_132 , V_89 ) ) ;
F_106 ( V_157 -> V_141 . V_158 ) ;
F_95 ( V_98 ) ;
return 0 ;
V_123:
F_81 (pde, new_page_tables, I915_PDES) {
struct V_74 * V_75 = V_98 -> V_87 . V_116 [ V_40 ] ;
V_98 -> V_87 . V_116 [ V_40 ] = V_21 -> V_91 ;
F_52 ( V_21 -> V_2 , V_75 ) ;
}
F_95 ( V_98 ) ;
return V_71 ;
}
static int F_141 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
V_21 -> V_84 = F_38 ( V_2 ) ;
if ( F_83 ( V_21 -> V_84 ) )
return F_84 ( V_21 -> V_84 ) ;
V_21 -> V_91 = F_48 ( V_2 ) ;
if ( F_83 ( V_21 -> V_91 ) ) {
F_45 ( V_2 , V_21 -> V_84 ) ;
return F_84 ( V_21 -> V_91 ) ;
}
F_56 ( V_21 , V_21 -> V_91 ) ;
return 0 ;
}
static void F_142 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
F_52 ( V_2 , V_21 -> V_91 ) ;
F_45 ( V_2 , V_21 -> V_84 ) ;
}
static void F_143 ( struct V_82 * V_21 )
{
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 , V_27 ) ;
struct V_74 * V_75 ;
T_8 V_40 ;
F_144 ( & V_98 -> V_24 ) ;
F_145 (pt, ppgtt, pde) {
if ( V_75 != V_21 -> V_91 )
F_52 ( V_98 -> V_27 . V_2 , V_75 ) ;
}
F_142 ( V_21 ) ;
}
static int F_146 ( struct V_97 * V_98 )
{
struct V_82 * V_21 = & V_98 -> V_27 ;
struct V_1 * V_2 = V_98 -> V_27 . V_2 ;
struct V_156 * V_157 = V_2 -> V_166 ;
bool V_194 = false ;
int V_71 ;
F_62 ( ! F_147 ( & V_157 -> V_141 . V_27 . V_195 ) ) ;
V_71 = F_141 ( V_21 ) ;
if ( V_71 )
return V_71 ;
V_196:
V_71 = F_148 ( & V_157 -> V_141 . V_27 . V_195 ,
& V_98 -> V_24 , V_197 ,
V_198 , 0 ,
0 , V_157 -> V_141 . V_27 . V_136 ,
V_199 ) ;
if ( V_71 == - V_200 && ! V_194 ) {
V_71 = F_149 ( V_2 , & V_157 -> V_141 . V_27 ,
V_197 , V_198 ,
V_35 ,
0 , V_157 -> V_141 . V_27 . V_136 ,
0 ) ;
if ( V_71 )
goto V_128;
V_194 = true ;
goto V_196;
}
if ( V_71 )
goto V_128;
if ( V_98 -> V_24 . V_25 < V_157 -> V_141 . V_201 )
F_150 ( L_9 ) ;
return 0 ;
V_128:
F_142 ( V_21 ) ;
return V_71 ;
}
static int F_151 ( struct V_97 * V_98 )
{
return F_146 ( V_98 ) ;
}
static void F_152 ( struct V_97 * V_98 ,
T_7 V_25 , T_7 V_101 )
{
struct V_74 * V_16 ;
T_8 V_40 , V_122 ;
F_105 (unused, &ppgtt->pd, start, length, temp, pde)
V_98 -> V_87 . V_116 [ V_40 ] = V_98 -> V_27 . V_91 ;
}
static int F_153 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = V_98 -> V_27 . V_2 ;
struct V_156 * V_157 = V_2 -> V_166 ;
int V_71 ;
V_98 -> V_27 . V_85 = V_157 -> V_141 . V_27 . V_85 ;
if ( F_154 ( V_2 ) ) {
V_98 -> V_146 = F_120 ;
} else if ( F_128 ( V_2 ) ) {
V_98 -> V_146 = F_114 ;
} else if ( F_155 ( V_2 ) ) {
V_98 -> V_146 = F_119 ;
} else
F_156 () ;
if ( F_3 ( V_2 ) )
V_98 -> V_146 = F_117 ;
V_71 = F_151 ( V_98 ) ;
if ( V_71 )
return V_71 ;
V_98 -> V_27 . V_143 = F_132 ;
V_98 -> V_27 . V_26 = F_130 ;
V_98 -> V_27 . V_22 = F_131 ;
V_98 -> V_27 . V_144 = F_10 ;
V_98 -> V_27 . V_145 = F_9 ;
V_98 -> V_27 . V_142 = F_143 ;
V_98 -> V_27 . V_25 = 0 ;
V_98 -> V_27 . V_136 = V_89 * V_78 * V_64 ;
V_98 -> V_202 = F_104 ;
V_98 -> V_87 . V_27 . V_159 =
V_98 -> V_24 . V_25 / V_64 * sizeof( T_5 ) ;
V_98 -> V_152 = ( T_5 V_203 * ) V_157 -> V_141 . V_158 +
V_98 -> V_87 . V_27 . V_159 / sizeof( T_5 ) ;
F_152 ( V_98 , 0 , V_98 -> V_27 . V_136 ) ;
F_112 ( V_157 , & V_98 -> V_87 , 0 , V_98 -> V_27 . V_136 ) ;
F_8 ( L_10 ,
V_98 -> V_24 . V_28 >> 20 ,
V_98 -> V_24 . V_25 / V_64 ) ;
F_150 ( L_11 ,
V_98 -> V_87 . V_27 . V_159 << 10 ) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
V_98 -> V_27 . V_2 = V_2 ;
if ( F_2 ( V_2 ) -> V_6 < 8 )
return F_153 ( V_98 ) ;
else
return F_101 ( V_98 ) ;
}
int F_158 ( struct V_1 * V_2 , struct V_97 * V_98 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
int V_71 = 0 ;
V_71 = F_157 ( V_2 , V_98 ) ;
if ( V_71 == 0 ) {
F_159 ( & V_98 -> V_204 ) ;
F_160 ( & V_98 -> V_27 . V_195 , V_98 -> V_27 . V_25 ,
V_98 -> V_27 . V_136 ) ;
F_161 ( V_157 , & V_98 -> V_27 ) ;
}
return V_71 ;
}
int F_162 ( struct V_1 * V_2 )
{
if ( V_10 . V_11 )
return 0 ;
if ( ! F_163 ( V_2 ) )
return 0 ;
if ( F_154 ( V_2 ) )
F_129 ( V_2 ) ;
else if ( F_155 ( V_2 ) )
F_126 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_6 >= 8 )
F_122 ( V_2 ) ;
else
F_15 ( F_2 ( V_2 ) -> V_6 ) ;
return 0 ;
}
int F_164 ( struct V_92 * V_93 )
{
struct V_156 * V_157 = V_93 -> V_96 -> V_2 -> V_166 ;
struct V_97 * V_98 = V_157 -> V_195 . V_205 ;
if ( V_10 . V_11 )
return 0 ;
if ( ! V_98 )
return 0 ;
return V_98 -> V_146 ( V_98 , V_93 ) ;
}
struct V_97 *
F_165 ( struct V_1 * V_2 , struct V_206 * V_207 )
{
struct V_97 * V_98 ;
int V_71 ;
V_98 = F_39 ( sizeof( * V_98 ) , V_62 ) ;
if ( ! V_98 )
return F_40 ( - V_58 ) ;
V_71 = F_158 ( V_2 , V_98 ) ;
if ( V_71 ) {
F_42 ( V_98 ) ;
return F_40 ( V_71 ) ;
}
V_98 -> V_208 = V_207 ;
F_166 ( & V_98 -> V_27 ) ;
return V_98 ;
}
void F_167 ( struct V_209 * V_209 )
{
struct V_97 * V_98 =
F_74 ( V_209 , struct V_97 , V_204 ) ;
F_168 ( & V_98 -> V_27 ) ;
F_28 ( ! F_169 ( & V_98 -> V_27 . V_210 ) ) ;
F_28 ( ! F_169 ( & V_98 -> V_27 . V_211 ) ) ;
F_170 ( & V_98 -> V_27 . V_212 ) ;
F_171 ( & V_98 -> V_27 . V_195 ) ;
V_98 -> V_27 . V_142 ( & V_98 -> V_27 ) ;
F_42 ( V_98 ) ;
}
static bool F_172 ( struct V_1 * V_2 )
{
#ifdef F_4
if ( F_173 ( V_2 ) && F_174 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_175 ( struct V_156 * V_157 )
{
bool V_71 = V_157 -> V_195 . V_213 ;
if ( F_176 ( V_157 -> V_141 . V_214 ) ) {
V_157 -> V_195 . V_213 = false ;
if ( F_177 ( V_157 -> V_2 ) ) {
F_178 ( L_12 ) ;
F_179 ( 10 ) ;
}
}
return V_71 ;
}
static void F_180 ( struct V_156 * V_157 , bool V_213 )
{
if ( F_176 ( V_157 -> V_141 . V_214 ) )
V_157 -> V_195 . V_213 = V_213 ;
}
void F_181 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_95 * V_96 ;
int V_66 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_123 (ring, dev_priv, i) {
T_1 V_215 ;
V_215 = F_127 ( F_182 ( V_96 ) ) ;
if ( V_215 & V_216 ) {
F_8 ( L_13
L_14
L_15
L_16
L_17 ,
V_215 & V_217 ,
V_215 & V_218 ? L_18 : L_19 ,
F_183 ( V_215 ) ,
F_184 ( V_215 ) ) ;
F_118 ( F_182 ( V_96 ) ,
V_215 & ~ V_216 ) ;
}
}
F_121 ( F_182 ( & V_157 -> V_96 [ V_165 ] ) ) ;
}
static void F_185 ( struct V_156 * V_157 )
{
if ( F_2 ( V_157 -> V_2 ) -> V_6 < 6 ) {
F_186 () ;
} else {
F_118 ( V_219 , V_220 ) ;
F_121 ( V_219 ) ;
}
}
void F_187 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_181 ( V_2 ) ;
V_157 -> V_141 . V_27 . V_26 ( & V_157 -> V_141 . V_27 ,
V_157 -> V_141 . V_27 . V_25 ,
V_157 -> V_141 . V_27 . V_136 ,
true ) ;
F_185 ( V_157 ) ;
}
int F_188 ( struct V_221 * V_18 )
{
if ( ! F_189 ( & V_18 -> V_27 . V_2 -> V_8 -> V_2 ,
V_18 -> V_23 -> V_222 , V_18 -> V_23 -> V_223 ,
V_60 ) )
return - V_200 ;
return 0 ;
}
static void F_190 ( void V_203 * V_29 , T_2 V_32 )
{
#ifdef F_191
F_191 ( V_32 , V_29 ) ;
#else
F_192 ( ( T_1 ) V_32 , V_29 ) ;
F_192 ( V_32 >> 32 , V_29 + 4 ) ;
#endif
}
static void F_193 ( struct V_82 * V_21 ,
struct V_117 * V_224 ,
T_7 V_25 ,
enum V_14 V_30 , T_1 V_16 )
{
struct V_156 * V_157 = V_21 -> V_2 -> V_166 ;
unsigned V_184 = V_25 >> V_112 ;
T_2 V_203 * V_225 =
( T_2 V_203 * ) V_157 -> V_141 . V_158 + V_184 ;
int V_66 = 0 ;
struct V_118 V_119 ;
T_3 V_29 = 0 ;
F_78 (st->sgl, &sg_iter, st->nents, 0 ) {
V_29 = F_194 ( V_119 . V_226 ) +
( V_119 . V_227 << V_112 ) ;
F_190 ( & V_225 [ V_66 ] ,
F_11 ( V_29 , V_30 , true ) ) ;
V_66 ++ ;
}
if ( V_66 != 0 )
F_28 ( F_195 ( & V_225 [ V_66 - 1 ] )
!= F_11 ( V_29 , V_30 , true ) ) ;
F_118 ( V_219 , V_220 ) ;
F_121 ( V_219 ) ;
}
static void F_196 ( struct V_82 * V_21 ,
struct V_117 * V_224 ,
T_7 V_25 ,
enum V_14 V_30 , T_1 V_48 )
{
struct V_156 * V_157 = V_21 -> V_2 -> V_166 ;
unsigned V_184 = V_25 >> V_112 ;
T_5 V_203 * V_225 =
( T_5 V_203 * ) V_157 -> V_141 . V_158 + V_184 ;
int V_66 = 0 ;
struct V_118 V_119 ;
T_3 V_29 = 0 ;
F_78 (st->sgl, &sg_iter, st->nents, 0 ) {
V_29 = F_79 ( & V_119 ) ;
F_192 ( V_21 -> V_85 ( V_29 , V_30 , true , V_48 ) , & V_225 [ V_66 ] ) ;
V_66 ++ ;
}
if ( V_66 != 0 ) {
unsigned long V_141 = F_106 ( & V_225 [ V_66 - 1 ] ) ;
F_28 ( V_141 != V_21 -> V_85 ( V_29 , V_30 , true , V_48 ) ) ;
}
F_118 ( V_219 , V_220 ) ;
F_121 ( V_219 ) ;
}
static void F_197 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_101 ,
bool V_102 )
{
struct V_156 * V_157 = V_21 -> V_2 -> V_166 ;
unsigned V_184 = V_25 >> V_112 ;
unsigned V_111 = V_101 >> V_112 ;
T_2 V_83 , V_203 * V_228 =
( T_2 V_203 * ) V_157 -> V_141 . V_158 + V_184 ;
const int V_229 = F_198 ( V_157 -> V_141 ) - V_184 ;
int V_66 ;
if ( F_199 ( V_111 > V_229 ,
L_20 ,
V_184 , V_111 , V_229 ) )
V_111 = V_229 ;
V_83 = F_11 ( F_54 ( V_21 -> V_84 ) ,
V_44 ,
V_102 ) ;
for ( V_66 = 0 ; V_66 < V_111 ; V_66 ++ )
F_190 ( & V_228 [ V_66 ] , V_83 ) ;
F_106 ( V_228 ) ;
}
static void F_200 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_101 ,
bool V_102 )
{
struct V_156 * V_157 = V_21 -> V_2 -> V_166 ;
unsigned V_184 = V_25 >> V_112 ;
unsigned V_111 = V_101 >> V_112 ;
T_5 V_83 , V_203 * V_228 =
( T_5 V_203 * ) V_157 -> V_141 . V_158 + V_184 ;
const int V_229 = F_198 ( V_157 -> V_141 ) - V_184 ;
int V_66 ;
if ( F_199 ( V_111 > V_229 ,
L_20 ,
V_184 , V_111 , V_229 ) )
V_111 = V_229 ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , V_102 , 0 ) ;
for ( V_66 = 0 ; V_66 < V_111 ; V_66 ++ )
F_192 ( V_83 , & V_228 [ V_66 ] ) ;
F_106 ( V_228 ) ;
}
static void F_201 ( struct V_82 * V_21 ,
struct V_117 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_16 )
{
unsigned int V_48 = ( V_15 == V_35 ) ?
V_230 : V_231 ;
F_202 ( V_23 , V_25 >> V_112 , V_48 ) ;
}
static void F_203 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_101 ,
bool V_16 )
{
unsigned V_184 = V_25 >> V_112 ;
unsigned V_111 = V_101 >> V_112 ;
F_204 ( V_184 , V_111 ) ;
}
static int F_205 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
T_1 V_48 )
{
struct V_1 * V_2 = V_13 -> V_21 -> V_2 ;
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_221 * V_18 = V_13 -> V_18 ;
struct V_117 * V_23 = V_18 -> V_23 ;
T_1 V_17 = 0 ;
int V_71 ;
V_71 = F_206 ( V_13 ) ;
if ( V_71 )
return V_71 ;
V_23 = V_13 -> V_232 . V_23 ;
if ( V_18 -> V_19 )
V_17 |= V_20 ;
if ( ! V_157 -> V_195 . V_205 || V_48 & V_233 ) {
V_13 -> V_21 -> V_22 ( V_13 -> V_21 , V_23 ,
V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
V_13 -> V_234 |= V_233 ;
}
if ( V_157 -> V_195 . V_205 && V_48 & V_235 ) {
struct V_97 * V_236 = V_157 -> V_195 . V_205 ;
V_236 -> V_27 . V_22 ( & V_236 -> V_27 , V_23 ,
V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
}
return 0 ;
}
static void F_207 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_21 -> V_2 ;
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_221 * V_18 = V_13 -> V_18 ;
const T_7 V_28 = F_208 ( T_7 ,
V_18 -> V_27 . V_28 ,
V_13 -> V_24 . V_28 ) ;
if ( V_13 -> V_234 & V_233 ) {
V_13 -> V_21 -> V_26 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_28 ,
true ) ;
}
if ( V_157 -> V_195 . V_205 && V_13 -> V_234 & V_235 ) {
struct V_97 * V_236 = V_157 -> V_195 . V_205 ;
V_236 -> V_27 . V_26 ( & V_236 -> V_27 ,
V_13 -> V_24 . V_25 ,
V_28 ,
true ) ;
}
}
void F_209 ( struct V_221 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_27 . V_2 ;
struct V_156 * V_157 = V_2 -> V_166 ;
bool V_213 ;
V_213 = F_175 ( V_157 ) ;
F_210 ( & V_2 -> V_8 -> V_2 , V_18 -> V_23 -> V_222 , V_18 -> V_23 -> V_223 ,
V_60 ) ;
F_180 ( V_157 , V_213 ) ;
}
static void F_211 ( struct V_237 * V_24 ,
unsigned long V_238 ,
T_11 * V_25 ,
T_11 * V_239 )
{
if ( V_24 -> V_238 != V_238 )
* V_25 += 4096 ;
if ( ! F_169 ( & V_24 -> V_240 ) ) {
V_24 = F_212 ( V_24 -> V_240 . V_241 ,
struct V_237 ,
V_240 ) ;
if ( V_24 -> V_242 && V_24 -> V_238 != V_238 )
* V_239 -= 4096 ;
}
}
static int F_213 ( struct V_1 * V_2 ,
unsigned long V_25 ,
unsigned long V_201 ,
unsigned long V_239 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_82 * V_243 = & V_157 -> V_141 . V_27 ;
struct V_237 * V_94 ;
struct V_221 * V_18 ;
unsigned long V_244 , V_245 ;
int V_71 ;
F_62 ( V_201 > V_239 ) ;
F_160 ( & V_243 -> V_195 , V_25 , V_239 - V_25 - V_64 ) ;
V_157 -> V_141 . V_27 . V_25 = V_25 ;
V_157 -> V_141 . V_27 . V_136 = V_239 - V_25 ;
if ( F_3 ( V_2 ) ) {
V_71 = F_214 ( V_2 ) ;
if ( V_71 )
return V_71 ;
}
if ( ! F_215 ( V_2 ) )
V_157 -> V_141 . V_27 . V_195 . V_246 = F_211 ;
F_216 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_12 * V_13 = F_217 ( V_18 , V_243 ) ;
F_218 ( L_21 ,
F_219 ( V_18 ) , V_18 -> V_27 . V_28 ) ;
F_28 ( F_220 ( V_18 ) ) ;
V_71 = F_221 ( & V_243 -> V_195 , & V_13 -> V_24 ) ;
if ( V_71 ) {
F_218 ( L_22 , V_71 ) ;
return V_71 ;
}
V_13 -> V_234 |= V_233 ;
}
F_222 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_218 ( L_23 ,
V_244 , V_245 ) ;
V_243 -> V_26 ( V_243 , V_244 ,
V_245 - V_244 , true ) ;
}
V_243 -> V_26 ( V_243 , V_239 - V_64 , V_64 , true ) ;
if ( F_163 ( V_2 ) && ! F_223 ( V_2 ) ) {
struct V_97 * V_98 ;
V_98 = F_39 ( sizeof( * V_98 ) , V_62 ) ;
if ( ! V_98 )
return - V_58 ;
V_71 = F_157 ( V_2 , V_98 ) ;
if ( V_71 ) {
V_98 -> V_27 . V_142 ( & V_98 -> V_27 ) ;
F_42 ( V_98 ) ;
return V_71 ;
}
if ( V_98 -> V_27 . V_143 )
V_71 = V_98 -> V_27 . V_143 ( & V_98 -> V_27 , 0 ,
V_98 -> V_27 . V_136 ) ;
if ( V_71 ) {
V_98 -> V_27 . V_142 ( & V_98 -> V_27 ) ;
F_42 ( V_98 ) ;
return V_71 ;
}
V_98 -> V_27 . V_26 ( & V_98 -> V_27 ,
V_98 -> V_27 . V_25 ,
V_98 -> V_27 . V_136 ,
true ) ;
V_157 -> V_195 . V_205 = V_98 ;
}
return 0 ;
}
void F_224 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
T_11 V_247 , V_248 ;
V_247 = V_157 -> V_141 . V_27 . V_136 ;
V_248 = V_157 -> V_141 . V_201 ;
F_213 ( V_2 , 0 , V_248 , V_247 ) ;
}
void F_225 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_82 * V_21 = & V_157 -> V_141 . V_27 ;
if ( V_157 -> V_195 . V_205 ) {
struct V_97 * V_98 = V_157 -> V_195 . V_205 ;
V_98 -> V_27 . V_142 ( & V_98 -> V_27 ) ;
}
if ( F_147 ( & V_21 -> V_195 ) ) {
if ( F_3 ( V_2 ) )
F_226 () ;
F_171 ( & V_21 -> V_195 ) ;
F_170 ( & V_21 -> V_212 ) ;
}
V_21 -> V_142 ( V_21 ) ;
}
static unsigned int F_227 ( T_12 V_249 )
{
V_249 >>= V_250 ;
V_249 &= V_251 ;
return V_249 << 20 ;
}
static unsigned int F_228 ( T_12 V_252 )
{
V_252 >>= V_253 ;
V_252 &= V_254 ;
if ( V_252 )
V_252 = 1 << V_252 ;
#ifdef V_140
if ( V_252 > 4 )
V_252 = 4 ;
#endif
return V_252 << 20 ;
}
static unsigned int F_229 ( T_12 V_255 )
{
V_255 >>= V_250 ;
V_255 &= V_251 ;
if ( V_255 )
return 1 << ( 20 + V_255 ) ;
return 0 ;
}
static T_9 F_230 ( T_12 V_249 )
{
V_249 >>= V_256 ;
V_249 &= V_257 ;
return V_249 << 25 ;
}
static T_9 F_231 ( T_12 V_252 )
{
V_252 >>= V_258 ;
V_252 &= V_259 ;
return V_252 << 25 ;
}
static T_9 F_232 ( T_12 V_255 )
{
V_255 >>= V_256 ;
V_255 &= V_257 ;
if ( V_255 < 0x11 )
return V_255 << 25 ;
else if ( V_255 < 0x17 )
return ( V_255 - 0x11 + 2 ) << 22 ;
else
return ( V_255 - 0x17 + 9 ) << 22 ;
}
static T_9 F_233 ( T_12 V_260 )
{
V_260 >>= V_258 ;
V_260 &= V_259 ;
if ( V_260 < 0xf0 )
return V_260 << 25 ;
else
return ( V_260 - 0xf0 + 1 ) << 22 ;
}
static int F_234 ( struct V_1 * V_2 ,
T_9 V_247 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_69 * V_84 ;
T_13 V_261 ;
V_261 = F_235 ( V_2 -> V_8 , 0 ) +
( F_236 ( V_2 -> V_8 , 0 ) / 2 ) ;
if ( F_33 ( V_2 ) )
V_157 -> V_141 . V_158 = F_237 ( V_261 , V_247 ) ;
else
V_157 -> V_141 . V_158 = F_238 ( V_261 , V_247 ) ;
if ( ! V_157 -> V_141 . V_158 ) {
F_178 ( L_24 ) ;
return - V_58 ;
}
V_84 = F_38 ( V_2 ) ;
if ( F_83 ( V_84 ) ) {
F_178 ( L_25 ) ;
F_239 ( V_157 -> V_141 . V_158 ) ;
return F_84 ( V_84 ) ;
}
V_157 -> V_141 . V_27 . V_84 = V_84 ;
return 0 ;
}
static void F_240 ( struct V_156 * V_157 )
{
T_7 V_262 ;
V_262 = F_241 ( 0 , V_263 | V_264 ) |
F_241 ( 1 , V_265 | V_266 ) |
F_241 ( 2 , V_267 | V_266 ) |
F_241 ( 3 , V_268 ) |
F_241 ( 4 , V_263 | V_266 | F_242 ( 0 ) ) |
F_241 ( 5 , V_263 | V_266 | F_242 ( 1 ) ) |
F_241 ( 6 , V_263 | V_266 | F_242 ( 2 ) ) |
F_241 ( 7 , V_263 | V_266 | F_242 ( 3 ) ) ;
if ( ! F_163 ( V_157 -> V_2 ) )
V_262 = F_241 ( 0 , V_268 ) ;
F_118 ( V_269 , V_262 ) ;
F_118 ( V_269 + 4 , V_262 >> 32 ) ;
}
static void F_243 ( struct V_156 * V_157 )
{
T_7 V_262 ;
V_262 = F_241 ( 0 , V_270 ) |
F_241 ( 1 , 0 ) |
F_241 ( 2 , 0 ) |
F_241 ( 3 , 0 ) |
F_241 ( 4 , V_270 ) |
F_241 ( 5 , V_270 ) |
F_241 ( 6 , V_270 ) |
F_241 ( 7 , V_270 ) ;
F_118 ( V_269 , V_262 ) ;
F_118 ( V_269 + 4 , V_262 >> 32 ) ;
}
static int F_244 ( struct V_1 * V_2 ,
T_11 * V_271 ,
T_9 * V_272 ,
T_13 * V_273 ,
T_11 * V_201 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
T_11 V_247 ;
T_12 V_249 ;
int V_71 ;
* V_273 = F_235 ( V_2 -> V_8 , 2 ) ;
* V_201 = F_236 ( V_2 -> V_8 , 2 ) ;
if ( ! F_245 ( V_2 -> V_8 , F_246 ( 39 ) ) )
F_247 ( V_2 -> V_8 , F_246 ( 39 ) ) ;
F_248 ( V_2 -> V_8 , V_274 , & V_249 ) ;
if ( F_2 ( V_2 ) -> V_6 >= 9 ) {
* V_272 = F_233 ( V_249 ) ;
V_247 = F_228 ( V_249 ) ;
} else if ( F_7 ( V_2 ) ) {
* V_272 = F_232 ( V_249 ) ;
V_247 = F_229 ( V_249 ) ;
} else {
* V_272 = F_231 ( V_249 ) ;
V_247 = F_228 ( V_249 ) ;
}
* V_271 = ( V_247 / sizeof( T_2 ) ) << V_112 ;
if ( F_7 ( V_2 ) || F_33 ( V_2 ) )
F_243 ( V_157 ) ;
else
F_240 ( V_157 ) ;
V_71 = F_234 ( V_2 , V_247 ) ;
V_157 -> V_141 . V_27 . V_26 = F_197 ;
V_157 -> V_141 . V_27 . V_22 = F_193 ;
V_157 -> V_141 . V_27 . V_145 = F_205 ;
V_157 -> V_141 . V_27 . V_144 = F_207 ;
return V_71 ;
}
static int F_249 ( struct V_1 * V_2 ,
T_11 * V_271 ,
T_9 * V_272 ,
T_13 * V_273 ,
T_11 * V_201 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
unsigned int V_247 ;
T_12 V_249 ;
int V_71 ;
* V_273 = F_235 ( V_2 -> V_8 , 2 ) ;
* V_201 = F_236 ( V_2 -> V_8 , 2 ) ;
if ( ( * V_201 < ( 64 << 20 ) || ( * V_201 > ( 512 << 20 ) ) ) ) {
F_178 ( L_26 ,
V_157 -> V_141 . V_201 ) ;
return - V_275 ;
}
if ( ! F_245 ( V_2 -> V_8 , F_246 ( 40 ) ) )
F_247 ( V_2 -> V_8 , F_246 ( 40 ) ) ;
F_248 ( V_2 -> V_8 , V_274 , & V_249 ) ;
* V_272 = F_230 ( V_249 ) ;
V_247 = F_227 ( V_249 ) ;
* V_271 = ( V_247 / sizeof( T_5 ) ) << V_112 ;
V_71 = F_234 ( V_2 , V_247 ) ;
V_157 -> V_141 . V_27 . V_26 = F_200 ;
V_157 -> V_141 . V_27 . V_22 = F_196 ;
V_157 -> V_141 . V_27 . V_145 = F_205 ;
V_157 -> V_141 . V_27 . V_144 = F_207 ;
return V_71 ;
}
static void F_250 ( struct V_82 * V_21 )
{
struct V_276 * V_141 = F_74 ( V_21 , struct V_276 , V_27 ) ;
F_239 ( V_141 -> V_158 ) ;
F_45 ( V_21 -> V_2 , V_21 -> V_84 ) ;
}
static int F_251 ( struct V_1 * V_2 ,
T_11 * V_271 ,
T_9 * V_272 ,
T_13 * V_273 ,
T_11 * V_201 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
int V_71 ;
V_71 = F_252 ( V_157 -> V_277 , V_157 -> V_2 -> V_8 , NULL ) ;
if ( ! V_71 ) {
F_178 ( L_27 ) ;
return - V_278 ;
}
F_253 ( V_271 , V_272 , V_273 , V_201 ) ;
V_157 -> V_141 . V_214 = F_172 ( V_157 -> V_2 ) ;
V_157 -> V_141 . V_27 . V_22 = F_201 ;
V_157 -> V_141 . V_27 . V_26 = F_203 ;
V_157 -> V_141 . V_27 . V_145 = F_205 ;
V_157 -> V_141 . V_27 . V_144 = F_207 ;
if ( F_176 ( V_157 -> V_141 . V_214 ) )
F_5 ( L_28 ) ;
return 0 ;
}
static void F_254 ( struct V_82 * V_21 )
{
F_255 () ;
}
int F_256 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_276 * V_141 = & V_157 -> V_141 ;
int V_71 ;
if ( F_2 ( V_2 ) -> V_6 <= 5 ) {
V_141 -> V_279 = F_251 ;
V_141 -> V_27 . V_142 = F_254 ;
} else if ( F_2 ( V_2 ) -> V_6 < 8 ) {
V_141 -> V_279 = F_249 ;
V_141 -> V_27 . V_142 = F_250 ;
if ( F_128 ( V_2 ) && V_157 -> V_280 )
V_141 -> V_27 . V_85 = F_20 ;
else if ( F_128 ( V_2 ) )
V_141 -> V_27 . V_85 = F_18 ;
else if ( F_6 ( V_2 ) )
V_141 -> V_27 . V_85 = F_17 ;
else if ( F_2 ( V_2 ) -> V_6 >= 7 )
V_141 -> V_27 . V_85 = F_16 ;
else
V_141 -> V_27 . V_85 = F_13 ;
} else {
V_157 -> V_141 . V_279 = F_244 ;
V_157 -> V_141 . V_27 . V_142 = F_250 ;
}
V_141 -> V_27 . V_2 = V_2 ;
V_71 = V_141 -> V_279 ( V_2 , & V_141 -> V_27 . V_136 , & V_141 -> V_281 ,
& V_141 -> V_273 , & V_141 -> V_201 ) ;
if ( V_71 )
return V_71 ;
F_5 ( L_29 ,
V_141 -> V_27 . V_136 >> 20 ) ;
F_8 ( L_30 , V_141 -> V_201 >> 20 ) ;
F_8 ( L_31 , V_141 -> V_281 >> 20 ) ;
#ifdef F_4
if ( V_7 )
F_5 ( L_32 ) ;
#endif
V_10 . V_3 = F_1 ( V_2 , V_10 . V_3 ) ;
F_8 ( L_33 , V_10 . V_3 ) ;
return 0 ;
}
void F_257 ( struct V_1 * V_2 )
{
struct V_156 * V_157 = V_2 -> V_166 ;
struct V_221 * V_18 ;
struct V_82 * V_21 ;
struct V_12 * V_13 ;
bool V_160 ;
F_181 ( V_2 ) ;
V_157 -> V_141 . V_27 . V_26 ( & V_157 -> V_141 . V_27 ,
V_157 -> V_141 . V_27 . V_25 ,
V_157 -> V_141 . V_27 . V_136 ,
true ) ;
V_21 = & V_157 -> V_141 . V_27 ;
F_216 (obj, &dev_priv->mm.bound_list, global_list) {
V_160 = false ;
F_216 (vma, &obj->vma_list, vma_link) {
if ( V_13 -> V_21 != V_21 )
continue;
F_28 ( F_258 ( V_13 , V_18 -> V_15 ,
V_282 ) ) ;
V_160 = true ;
}
if ( V_160 )
F_259 ( V_18 , V_18 -> V_283 ) ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 ) {
if ( F_7 ( V_2 ) || F_33 ( V_2 ) )
F_243 ( V_157 ) ;
else
F_240 ( V_157 ) ;
return;
}
if ( F_163 ( V_2 ) ) {
F_216 (vm, &dev_priv->vm_list, global_link) {
struct V_97 * V_98 =
F_74 ( V_21 , struct V_97 ,
V_27 ) ;
if ( F_260 ( V_21 ) )
V_98 = V_157 -> V_195 . V_205 ;
F_112 ( V_157 , & V_98 -> V_87 ,
0 , V_98 -> V_27 . V_136 ) ;
}
}
F_185 ( V_157 ) ;
}
static struct V_12 *
F_261 ( struct V_221 * V_18 ,
struct V_82 * V_21 ,
const struct V_284 * V_232 )
{
struct V_12 * V_13 ;
if ( F_28 ( F_260 ( V_21 ) != ! ! V_232 ) )
return F_40 ( - V_61 ) ;
V_13 = F_262 ( F_103 ( V_18 -> V_27 . V_2 ) -> V_285 , V_62 ) ;
if ( V_13 == NULL )
return F_40 ( - V_58 ) ;
F_263 ( & V_13 -> V_286 ) ;
F_263 ( & V_13 -> V_287 ) ;
F_263 ( & V_13 -> V_288 ) ;
V_13 -> V_21 = V_21 ;
V_13 -> V_18 = V_18 ;
if ( F_260 ( V_21 ) )
V_13 -> V_232 = * V_232 ;
F_264 ( & V_13 -> V_286 , & V_18 -> V_289 ) ;
if ( ! F_260 ( V_21 ) )
F_265 ( F_266 ( V_21 ) ) ;
return V_13 ;
}
struct V_12 *
F_267 ( struct V_221 * V_18 ,
struct V_82 * V_21 )
{
struct V_12 * V_13 ;
V_13 = F_217 ( V_18 , V_21 ) ;
if ( ! V_13 )
V_13 = F_261 ( V_18 , V_21 ,
F_260 ( V_21 ) ? & V_290 : NULL ) ;
return V_13 ;
}
struct V_12 *
F_268 ( struct V_221 * V_18 ,
const struct V_284 * V_291 )
{
struct V_82 * V_292 = F_269 ( V_18 ) ;
struct V_12 * V_13 ;
if ( F_28 ( ! V_291 ) )
return F_40 ( - V_61 ) ;
V_13 = F_270 ( V_18 , V_291 ) ;
if ( F_83 ( V_13 ) )
return V_13 ;
if ( ! V_13 )
V_13 = F_261 ( V_18 , V_292 , V_291 ) ;
return V_13 ;
}
static void
F_271 ( T_3 * V_293 , unsigned int V_294 , unsigned int V_295 ,
struct V_117 * V_224 )
{
unsigned int V_296 , V_297 ;
unsigned int V_298 ;
struct V_299 * V_226 = V_224 -> V_222 ;
V_224 -> V_223 = 0 ;
for ( V_296 = 0 ; V_296 < V_294 ; V_296 ++ ) {
V_298 = V_294 * ( V_295 - 1 ) + V_296 ;
for ( V_297 = 0 ; V_297 < V_295 ; V_297 ++ ) {
V_224 -> V_223 ++ ;
F_272 ( V_226 , NULL , V_64 , 0 ) ;
F_194 ( V_226 ) = V_293 [ V_298 ] ;
F_273 ( V_226 ) = V_64 ;
V_226 = F_274 ( V_226 ) ;
V_298 -= V_294 ;
}
}
}
static struct V_117 *
F_275 ( struct V_284 * V_232 ,
struct V_221 * V_18 )
{
struct V_300 * V_301 = & V_232 -> V_302 ;
unsigned int V_303 = V_301 -> V_28 >> V_112 ;
struct V_118 V_119 ;
unsigned long V_66 ;
T_3 * V_304 ;
struct V_117 * V_224 ;
int V_71 = - V_58 ;
V_304 = F_276 ( V_18 -> V_27 . V_28 / V_64 ,
sizeof( T_3 ) ) ;
if ( ! V_304 )
return F_40 ( V_71 ) ;
V_224 = F_277 ( sizeof( * V_224 ) , V_62 ) ;
if ( ! V_224 )
goto V_305;
V_71 = F_278 ( V_224 , V_303 , V_62 ) ;
if ( V_71 )
goto V_306;
V_66 = 0 ;
F_78 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_304 [ V_66 ] = F_79 ( & V_119 ) ;
V_66 ++ ;
}
F_271 ( V_304 ,
V_301 -> V_307 , V_301 -> V_308 ,
V_224 ) ;
F_218 (
L_34 ,
V_18 -> V_27 . V_28 , V_301 -> V_309 , V_301 -> V_295 ,
V_301 -> V_310 , V_301 -> V_307 ,
V_301 -> V_308 , V_303 ) ;
F_279 ( V_304 ) ;
return V_224 ;
V_306:
F_42 ( V_224 ) ;
V_305:
F_279 ( V_304 ) ;
F_218 (
L_35 ,
V_18 -> V_27 . V_28 , V_71 , V_301 -> V_309 , V_301 -> V_295 ,
V_301 -> V_310 , V_301 -> V_307 ,
V_301 -> V_308 , V_303 ) ;
return F_40 ( V_71 ) ;
}
static struct V_117 *
F_280 ( const struct V_284 * V_291 ,
struct V_221 * V_18 )
{
struct V_117 * V_224 ;
struct V_299 * V_226 ;
struct V_118 V_311 ;
int V_71 = - V_58 ;
V_224 = F_277 ( sizeof( * V_224 ) , V_62 ) ;
if ( ! V_224 )
goto V_305;
V_71 = F_278 ( V_224 , V_291 -> V_312 . V_313 . V_28 , V_62 ) ;
if ( V_71 )
goto V_306;
V_226 = V_224 -> V_222 ;
V_224 -> V_223 = 0 ;
F_78 (obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if ( V_224 -> V_223 >= V_291 -> V_312 . V_313 . V_28 )
break;
F_272 ( V_226 , NULL , V_64 , 0 ) ;
F_194 ( V_226 ) = F_79 ( & V_311 ) ;
F_273 ( V_226 ) = V_64 ;
V_226 = F_274 ( V_226 ) ;
V_224 -> V_223 ++ ;
}
return V_224 ;
V_306:
F_42 ( V_224 ) ;
V_305:
return F_40 ( V_71 ) ;
}
static int
F_206 ( struct V_12 * V_13 )
{
int V_71 = 0 ;
if ( V_13 -> V_232 . V_23 )
return 0 ;
if ( V_13 -> V_232 . type == V_314 )
V_13 -> V_232 . V_23 = V_13 -> V_18 -> V_23 ;
else if ( V_13 -> V_232 . type == V_315 )
V_13 -> V_232 . V_23 =
F_275 ( & V_13 -> V_232 , V_13 -> V_18 ) ;
else if ( V_13 -> V_232 . type == V_316 )
V_13 -> V_232 . V_23 =
F_280 ( & V_13 -> V_232 , V_13 -> V_18 ) ;
else
F_281 ( 1 , L_36 ,
V_13 -> V_232 . type ) ;
if ( ! V_13 -> V_232 . V_23 ) {
F_178 ( L_37 ,
V_13 -> V_232 . type ) ;
V_71 = - V_61 ;
} else if ( F_83 ( V_13 -> V_232 . V_23 ) ) {
V_71 = F_84 ( V_13 -> V_232 . V_23 ) ;
V_13 -> V_232 . V_23 = NULL ;
F_178 ( L_38 ,
V_13 -> V_232 . type , V_71 ) ;
}
return V_71 ;
}
int F_258 ( struct V_12 * V_13 , enum V_14 V_15 ,
T_1 V_48 )
{
int V_71 ;
T_1 V_317 ;
if ( F_28 ( V_48 == 0 ) )
return - V_61 ;
V_317 = 0 ;
if ( V_48 & V_318 )
V_317 |= V_233 ;
if ( V_48 & V_319 )
V_317 |= V_235 ;
if ( V_48 & V_282 )
V_317 |= V_13 -> V_234 ;
else
V_317 &= ~ V_13 -> V_234 ;
if ( V_317 == 0 )
return 0 ;
if ( V_13 -> V_234 == 0 && V_13 -> V_21 -> V_143 ) {
F_282 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_24 . V_28 ,
F_283 ( V_13 -> V_21 ) ) ;
V_13 -> V_320 ++ ;
V_71 = V_13 -> V_21 -> V_143 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_24 . V_28 ) ;
V_13 -> V_320 -- ;
if ( V_71 )
return V_71 ;
}
V_71 = V_13 -> V_21 -> V_145 ( V_13 , V_15 , V_317 ) ;
if ( V_71 )
return V_71 ;
V_13 -> V_234 |= V_317 ;
return 0 ;
}
T_9
F_284 ( struct V_221 * V_18 ,
const struct V_284 * V_291 )
{
if ( V_291 -> type == V_314 ) {
return V_18 -> V_27 . V_28 ;
} else if ( V_291 -> type == V_315 ) {
return V_291 -> V_302 . V_28 ;
} else if ( V_291 -> type == V_316 ) {
return V_291 -> V_312 . V_313 . V_28 << V_112 ;
} else {
F_281 ( 1 , L_36 , V_291 -> type ) ;
return V_18 -> V_27 . V_28 ;
}
}
