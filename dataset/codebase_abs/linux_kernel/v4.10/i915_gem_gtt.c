int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
bool V_4 ;
bool V_5 ;
bool V_6 ;
V_4 = F_2 ( V_2 ) >= 6 ;
V_5 = F_2 ( V_2 ) >= 7 ;
V_6 =
F_3 ( V_2 ) || F_2 ( V_2 ) >= 9 ;
if ( F_4 ( V_2 ) ) {
V_5 = false ;
V_6 = false ;
}
if ( ! V_4 )
return 0 ;
if ( V_3 == 0 && F_2 ( V_2 ) < 9 )
return 0 ;
if ( V_3 == 1 )
return 1 ;
if ( V_3 == 2 && V_5 )
return 2 ;
if ( V_3 == 3 && V_6 )
return 3 ;
#ifdef F_5
if ( F_6 ( V_2 ) && V_7 ) {
F_7 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_8 ( V_2 ) && V_2 -> V_8 . V_9 -> V_10 < 0xb ) {
F_9 ( L_2 ) ;
return 0 ;
}
if ( F_2 ( V_2 ) >= 8 && V_11 . V_12 && V_5 )
return V_6 ? 3 : 2 ;
else
return V_4 ? 1 : 0 ;
}
static int F_10 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_17 )
{
T_1 V_18 = 0 ;
V_14 -> V_19 = V_14 -> V_20 -> V_21 . V_19 ;
if ( V_14 -> V_20 -> V_22 )
V_18 |= V_23 ;
V_14 -> V_24 -> V_25 ( V_14 -> V_24 , V_14 -> V_19 , V_14 -> V_26 . V_27 ,
V_16 , V_18 ) ;
return 0 ;
}
static void F_11 ( struct V_13 * V_14 )
{
V_14 -> V_24 -> V_28 ( V_14 -> V_24 ,
V_14 -> V_26 . V_27 ,
V_14 -> V_29 ) ;
}
static T_2 F_12 ( T_3 V_30 ,
enum V_15 V_31 )
{
T_2 V_32 = V_33 | V_34 ;
V_32 |= V_30 ;
switch ( V_31 ) {
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
static T_4 F_13 ( const T_3 V_30 ,
const enum V_15 V_31 )
{
T_4 V_40 = V_33 | V_34 ;
V_40 |= V_30 ;
if ( V_31 != V_35 )
V_40 |= V_41 ;
else
V_40 |= V_36 ;
return V_40 ;
}
static T_5 F_14 ( T_3 V_30 ,
enum V_15 V_31 ,
T_1 V_17 )
{
T_5 V_32 = V_42 ;
V_32 |= F_15 ( V_30 ) ;
switch ( V_31 ) {
case V_43 :
case V_44 :
V_32 |= V_45 ;
break;
case V_35 :
V_32 |= V_46 ;
break;
default:
F_16 ( V_31 ) ;
}
return V_32 ;
}
static T_5 F_17 ( T_3 V_30 ,
enum V_15 V_31 ,
T_1 V_17 )
{
T_5 V_32 = V_42 ;
V_32 |= F_15 ( V_30 ) ;
switch ( V_31 ) {
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
F_16 ( V_31 ) ;
}
return V_32 ;
}
static T_5 F_18 ( T_3 V_30 ,
enum V_15 V_31 ,
T_1 V_48 )
{
T_5 V_32 = V_42 ;
V_32 |= F_15 ( V_30 ) ;
if ( ! ( V_48 & V_23 ) )
V_32 |= V_49 ;
if ( V_31 != V_35 )
V_32 |= V_50 ;
return V_32 ;
}
static T_5 F_19 ( T_3 V_30 ,
enum V_15 V_31 ,
T_1 V_17 )
{
T_5 V_32 = V_42 ;
V_32 |= F_20 ( V_30 ) ;
if ( V_31 != V_35 )
V_32 |= V_51 ;
return V_32 ;
}
static T_5 F_21 ( T_3 V_30 ,
enum V_15 V_31 ,
T_1 V_17 )
{
T_5 V_32 = V_42 ;
V_32 |= F_20 ( V_30 ) ;
switch ( V_31 ) {
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
static int F_22 ( struct V_1 * V_2 ,
struct V_54 * V_55 , T_6 V_48 )
{
struct V_56 * V_57 = & V_2 -> V_8 . V_9 -> V_58 ;
V_55 -> V_59 = F_23 ( V_48 ) ;
if ( ! V_55 -> V_59 )
return - V_60 ;
V_55 -> V_61 = F_24 ( V_57 ,
V_55 -> V_59 , 0 , 4096 , V_62 ) ;
if ( F_25 ( V_57 , V_55 -> V_61 ) ) {
F_26 ( V_55 -> V_59 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
return F_22 ( V_2 , V_55 , V_64 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_65 * V_9 = V_2 -> V_8 . V_9 ;
if ( F_29 ( ! V_55 -> V_59 ) )
return;
F_30 ( & V_9 -> V_58 , V_55 -> V_61 , 4096 , V_62 ) ;
F_26 ( V_55 -> V_59 ) ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
}
static void * F_31 ( struct V_54 * V_55 )
{
return F_32 ( V_55 -> V_59 ) ;
}
static void F_33 ( struct V_1 * V_2 , void * V_66 )
{
if ( F_34 ( V_2 ) || F_35 ( V_2 ) )
F_36 ( V_66 , V_67 ) ;
F_37 ( V_66 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_54 * V_55 , const T_7 V_68 )
{
int V_69 ;
T_7 * const V_66 = F_31 ( V_55 ) ;
for ( V_69 = 0 ; V_69 < 512 ; V_69 ++ )
V_66 [ V_69 ] = V_68 ;
F_33 ( V_2 , V_66 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_54 * V_55 , const T_8 V_70 )
{
T_7 V_71 = V_70 ;
V_71 = V_71 << 32 | V_70 ;
F_38 ( V_2 , V_55 , V_71 ) ;
}
static int
F_40 ( struct V_1 * V_2 ,
struct V_54 * V_72 ,
T_6 V_73 )
{
return F_22 ( V_2 , V_72 , V_73 | V_74 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_54 * V_72 )
{
F_28 ( V_2 , V_72 ) ;
}
static struct V_75 * F_42 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
const T_9 V_77 = F_2 ( V_2 ) >= 8 ? V_78 : V_79 ;
int V_80 = - V_60 ;
V_76 = F_43 ( sizeof( * V_76 ) , V_81 ) ;
if ( ! V_76 )
return F_44 ( - V_60 ) ;
V_76 -> V_82 = F_45 ( F_46 ( V_77 ) , sizeof( * V_76 -> V_82 ) ,
V_81 ) ;
if ( ! V_76 -> V_82 )
goto V_83;
V_80 = F_47 ( V_2 , V_76 ) ;
if ( V_80 )
goto V_84;
return V_76 ;
V_84:
F_48 ( V_76 -> V_82 ) ;
V_83:
F_48 ( V_76 ) ;
return F_44 ( V_80 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
F_50 ( V_2 , V_76 ) ;
F_48 ( V_76 -> V_82 ) ;
F_48 ( V_76 ) ;
}
static void F_51 ( struct V_85 * V_24 ,
struct V_75 * V_76 )
{
T_2 V_86 ;
V_86 = F_12 ( V_24 -> V_87 . V_61 ,
V_44 ) ;
F_52 ( F_53 ( V_24 -> V_58 ) , V_76 , V_86 ) ;
}
static void F_54 ( struct V_85 * V_24 ,
struct V_75 * V_76 )
{
T_5 V_86 ;
F_29 ( V_24 -> V_87 . V_61 == 0 ) ;
V_86 = V_24 -> V_88 ( V_24 -> V_87 . V_61 ,
V_44 , 0 ) ;
F_55 ( F_53 ( V_24 -> V_58 ) , V_76 , V_86 ) ;
}
static struct V_89 * F_56 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
int V_80 = - V_60 ;
V_90 = F_43 ( sizeof( * V_90 ) , V_81 ) ;
if ( ! V_90 )
return F_44 ( - V_60 ) ;
V_90 -> V_91 = F_45 ( F_46 ( V_92 ) ,
sizeof( * V_90 -> V_91 ) , V_81 ) ;
if ( ! V_90 -> V_91 )
goto V_83;
V_80 = F_47 ( V_2 , V_90 ) ;
if ( V_80 )
goto V_84;
return V_90 ;
V_84:
F_48 ( V_90 -> V_91 ) ;
V_83:
F_48 ( V_90 ) ;
return F_44 ( V_80 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
if ( F_58 ( V_90 ) ) {
F_50 ( V_2 , V_90 ) ;
F_48 ( V_90 -> V_91 ) ;
F_48 ( V_90 ) ;
}
}
static void F_59 ( struct V_85 * V_24 ,
struct V_89 * V_90 )
{
T_4 V_93 ;
V_93 = F_13 ( F_60 ( V_24 -> V_94 ) , V_44 ) ;
F_52 ( F_53 ( V_24 -> V_58 ) , V_90 , V_93 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
T_9 V_97 = F_62 ( V_2 ) ;
V_96 -> V_98 = F_45 ( F_46 ( V_97 ) ,
sizeof( unsigned long ) ,
V_81 ) ;
if ( ! V_96 -> V_98 )
return - V_60 ;
V_96 -> V_99 = F_45 ( V_97 , sizeof( * V_96 -> V_99 ) ,
V_81 ) ;
if ( ! V_96 -> V_99 ) {
F_48 ( V_96 -> V_98 ) ;
V_96 -> V_98 = NULL ;
return - V_60 ;
}
return 0 ;
}
static void F_63 ( struct V_95 * V_96 )
{
F_48 ( V_96 -> V_98 ) ;
F_48 ( V_96 -> V_99 ) ;
V_96 -> V_99 = NULL ;
}
static struct
V_95 * F_64 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
int V_80 = - V_60 ;
F_29 ( ! F_65 ( V_2 ) ) ;
V_96 = F_43 ( sizeof( * V_96 ) , V_81 ) ;
if ( ! V_96 )
return F_44 ( - V_60 ) ;
V_80 = F_61 ( V_2 , V_96 ) ;
if ( V_80 )
goto V_83;
V_80 = F_47 ( V_2 , V_96 ) ;
if ( V_80 )
goto V_84;
return V_96 ;
V_84:
F_63 ( V_96 ) ;
V_83:
F_48 ( V_96 ) ;
return F_44 ( V_80 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
F_63 ( V_96 ) ;
if ( F_65 ( V_2 ) ) {
F_50 ( V_2 , V_96 ) ;
F_48 ( V_96 ) ;
}
}
static void F_67 ( struct V_85 * V_24 ,
struct V_95 * V_96 )
{
T_10 V_100 ;
V_100 = F_68 ( F_60 ( V_24 -> V_101 ) , V_44 ) ;
F_52 ( F_53 ( V_24 -> V_58 ) , V_96 , V_100 ) ;
}
static void F_69 ( struct V_85 * V_24 ,
struct V_102 * V_103 )
{
T_11 V_104 ;
V_104 = F_70 ( F_60 ( V_24 -> V_105 ) ,
V_44 ) ;
F_52 ( F_53 ( V_24 -> V_58 ) , V_103 , V_104 ) ;
}
static void
F_71 ( struct V_106 * V_107 ,
struct V_95 * V_96 ,
struct V_89 * V_90 ,
int V_108 )
{
T_10 * V_109 ;
if ( ! F_65 ( F_53 ( V_107 -> V_110 . V_58 ) ) )
return;
V_109 = F_72 ( V_96 ) ;
V_109 [ V_108 ] = F_68 ( F_60 ( V_90 ) , V_44 ) ;
F_73 ( V_107 , V_109 ) ;
}
static void
F_74 ( struct V_106 * V_107 ,
struct V_102 * V_103 ,
struct V_95 * V_96 ,
int V_108 )
{
T_11 * V_111 = F_72 ( V_103 ) ;
F_29 ( ! F_65 ( F_53 ( V_107 -> V_110 . V_58 ) ) ) ;
V_111 [ V_108 ] = F_70 ( F_60 ( V_96 ) , V_44 ) ;
F_73 ( V_107 , V_111 ) ;
}
static int F_75 ( struct V_112 * V_113 ,
unsigned V_114 ,
T_3 V_30 )
{
struct V_115 * V_116 = V_113 -> V_116 ;
struct V_117 * V_118 = V_113 -> V_118 ;
int V_80 ;
F_76 ( V_114 >= 4 ) ;
V_80 = F_77 ( V_113 , 6 ) ;
if ( V_80 )
return V_80 ;
F_78 ( V_116 , F_79 ( 1 ) ) ;
F_80 ( V_116 , F_81 ( V_118 , V_114 ) ) ;
F_78 ( V_116 , F_82 ( V_30 ) ) ;
F_78 ( V_116 , F_79 ( 1 ) ) ;
F_80 ( V_116 , F_83 ( V_118 , V_114 ) ) ;
F_78 ( V_116 , F_84 ( V_30 ) ) ;
F_85 ( V_116 ) ;
return 0 ;
}
static int F_86 ( struct V_106 * V_107 ,
struct V_112 * V_113 )
{
int V_69 , V_80 ;
for ( V_69 = V_119 - 1 ; V_69 >= 0 ; V_69 -- ) {
const T_3 V_120 = F_87 ( V_107 , V_69 ) ;
V_80 = F_75 ( V_113 , V_69 , V_120 ) ;
if ( V_80 )
return V_80 ;
}
return 0 ;
}
static int F_88 ( struct V_106 * V_107 ,
struct V_112 * V_113 )
{
return F_75 ( V_113 , 0 , F_60 ( & V_107 -> V_103 ) ) ;
}
static void F_89 ( struct V_106 * V_107 )
{
V_107 -> V_121 = F_90 ( F_53 ( V_107 -> V_110 . V_58 ) ) -> V_122 ;
}
static bool F_91 ( struct V_85 * V_24 ,
struct V_75 * V_76 ,
T_7 V_27 ,
T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
unsigned int V_124 = F_93 ( V_27 , V_123 ) ;
unsigned int V_32 = F_94 ( V_27 ) ;
unsigned int V_125 = V_32 + V_124 ;
T_2 * V_126 ;
T_2 V_86 = F_12 ( V_24 -> V_87 . V_61 ,
V_44 ) ;
if ( F_29 ( ! F_58 ( V_76 ) ) )
return false ;
F_95 ( V_125 > V_78 ) ;
F_96 ( V_76 -> V_82 , V_32 , V_124 ) ;
if ( F_97 ( V_76 -> V_82 , V_78 ) ) {
F_49 ( F_53 ( V_24 -> V_58 ) , V_76 ) ;
return true ;
}
V_126 = F_72 ( V_76 ) ;
while ( V_32 < V_125 )
V_126 [ V_32 ++ ] = V_86 ;
F_73 ( V_107 , V_126 ) ;
return false ;
}
static bool F_98 ( struct V_85 * V_24 ,
struct V_89 * V_90 ,
T_7 V_27 ,
T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
struct V_75 * V_76 ;
T_7 V_40 ;
T_4 * V_127 ;
T_4 V_93 = F_13 ( F_60 ( V_24 -> V_94 ) ,
V_44 ) ;
F_99 (pt, pd, start, length, pde) {
if ( F_29 ( ! V_90 -> V_128 [ V_40 ] ) )
break;
if ( F_91 ( V_24 , V_76 , V_27 , V_123 ) ) {
F_100 ( V_40 , V_90 -> V_91 ) ;
V_127 = F_72 ( V_90 ) ;
V_127 [ V_40 ] = V_93 ;
F_73 ( V_107 , V_127 ) ;
}
}
if ( F_97 ( V_90 -> V_91 , V_92 ) ) {
F_57 ( F_53 ( V_24 -> V_58 ) , V_90 ) ;
return true ;
}
return false ;
}
static bool F_101 ( struct V_85 * V_24 ,
struct V_95 * V_96 ,
T_7 V_27 ,
T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_89 * V_90 ;
T_7 V_129 ;
T_10 * V_130 ;
T_10 V_100 =
F_68 ( F_60 ( V_24 -> V_101 ) , V_44 ) ;
F_102 (pd, pdp, start, length, pdpe) {
if ( F_29 ( ! V_96 -> V_99 [ V_129 ] ) )
break;
if ( F_98 ( V_24 , V_90 , V_27 , V_123 ) ) {
F_100 ( V_129 , V_96 -> V_98 ) ;
if ( F_65 ( V_2 ) ) {
V_130 = F_72 ( V_96 ) ;
V_130 [ V_129 ] = V_100 ;
F_73 ( V_107 , V_130 ) ;
}
}
}
F_89 ( V_107 ) ;
if ( F_65 ( V_2 ) &&
F_97 ( V_96 -> V_98 , F_62 ( V_2 ) ) ) {
F_66 ( V_2 , V_96 ) ;
return true ;
}
return false ;
}
static void F_103 ( struct V_85 * V_24 ,
struct V_102 * V_103 ,
T_7 V_27 ,
T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
struct V_95 * V_96 ;
T_7 V_131 ;
T_11 * V_132 ;
T_11 V_104 =
F_70 ( F_60 ( V_24 -> V_105 ) , V_44 ) ;
F_95 ( ! F_65 ( F_53 ( V_24 -> V_58 ) ) ) ;
F_104 (pdp, pml4, start, length, pml4e) {
if ( F_29 ( ! V_103 -> V_133 [ V_131 ] ) )
break;
if ( F_101 ( V_24 , V_96 , V_27 , V_123 ) ) {
F_100 ( V_131 , V_103 -> V_134 ) ;
V_132 = F_72 ( V_103 ) ;
V_132 [ V_131 ] = V_104 ;
F_73 ( V_107 , V_132 ) ;
}
}
}
static void F_105 ( struct V_85 * V_24 ,
T_7 V_27 , T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
if ( F_65 ( F_53 ( V_24 -> V_58 ) ) )
F_103 ( V_24 , & V_107 -> V_103 , V_27 , V_123 ) ;
else
F_101 ( V_24 , & V_107 -> V_96 , V_27 , V_123 ) ;
}
static void
F_106 ( struct V_85 * V_24 ,
struct V_95 * V_96 ,
struct V_135 * V_136 ,
T_7 V_27 ,
enum V_15 V_16 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
T_2 * V_126 ;
unsigned V_129 = F_107 ( V_27 ) ;
unsigned V_40 = F_108 ( V_27 ) ;
unsigned V_32 = F_94 ( V_27 ) ;
V_126 = NULL ;
while ( F_109 ( V_136 ) ) {
if ( V_126 == NULL ) {
struct V_89 * V_90 = V_96 -> V_99 [ V_129 ] ;
struct V_75 * V_76 = V_90 -> V_128 [ V_40 ] ;
V_126 = F_72 ( V_76 ) ;
}
V_126 [ V_32 ] =
F_12 ( F_110 ( V_136 ) ,
V_16 ) ;
if ( ++ V_32 == V_78 ) {
F_73 ( V_107 , V_126 ) ;
V_126 = NULL ;
if ( ++ V_40 == V_92 ) {
if ( ++ V_129 == F_62 ( F_53 ( V_24 -> V_58 ) ) )
break;
V_40 = 0 ;
}
V_32 = 0 ;
}
}
if ( V_126 )
F_73 ( V_107 , V_126 ) ;
}
static void F_111 ( struct V_85 * V_24 ,
struct V_137 * V_19 ,
T_7 V_27 ,
enum V_15 V_16 ,
T_1 V_17 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
struct V_135 V_136 ;
F_112 ( & V_136 , V_19 -> V_138 , F_113 ( V_19 -> V_138 ) , 0 ) ;
if ( ! F_65 ( F_53 ( V_24 -> V_58 ) ) ) {
F_106 ( V_24 , & V_107 -> V_96 , & V_136 , V_27 ,
V_16 ) ;
} else {
struct V_95 * V_96 ;
T_7 V_131 ;
T_7 V_123 = ( T_7 ) V_19 -> V_139 << V_140 ;
F_104 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_106 ( V_24 , V_96 , & V_136 ,
V_27 , V_16 ) ;
}
}
}
static void F_114 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
int V_69 ;
if ( ! F_58 ( V_90 ) )
return;
F_115 (i, pd->used_pdes, I915_PDES) {
if ( F_29 ( ! V_90 -> V_128 [ V_69 ] ) )
continue;
F_49 ( V_2 , V_90 -> V_128 [ V_69 ] ) ;
V_90 -> V_128 [ V_69 ] = NULL ;
}
}
static int F_116 ( struct V_85 * V_24 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
int V_80 ;
V_80 = F_40 ( V_2 , & V_24 -> V_87 , V_64 ) ;
if ( V_80 )
return V_80 ;
V_24 -> V_94 = F_42 ( V_2 ) ;
if ( F_117 ( V_24 -> V_94 ) ) {
V_80 = F_118 ( V_24 -> V_94 ) ;
goto V_141;
}
V_24 -> V_101 = F_56 ( V_2 ) ;
if ( F_117 ( V_24 -> V_101 ) ) {
V_80 = F_118 ( V_24 -> V_101 ) ;
goto F_49;
}
if ( F_65 ( V_2 ) ) {
V_24 -> V_105 = F_64 ( V_2 ) ;
if ( F_117 ( V_24 -> V_105 ) ) {
V_80 = F_118 ( V_24 -> V_105 ) ;
goto F_57;
}
}
F_51 ( V_24 , V_24 -> V_94 ) ;
F_59 ( V_24 , V_24 -> V_101 ) ;
if ( F_65 ( V_2 ) )
F_67 ( V_24 , V_24 -> V_105 ) ;
return 0 ;
F_57:
F_57 ( V_2 , V_24 -> V_101 ) ;
F_49:
F_49 ( V_2 , V_24 -> V_94 ) ;
V_141:
F_41 ( V_2 , & V_24 -> V_87 ) ;
return V_80 ;
}
static int F_119 ( struct V_106 * V_107 , bool V_142 )
{
enum V_143 V_144 ;
struct V_1 * V_2 = F_53 ( V_107 -> V_110 . V_58 ) ;
int V_69 ;
if ( F_65 ( V_2 ) ) {
T_12 V_61 = F_60 ( & V_107 -> V_103 ) ;
F_120 ( F_121 ( V_96 [ 0 ] . V_145 ) , F_84 ( V_61 ) ) ;
F_120 ( F_121 ( V_96 [ 0 ] . V_146 ) , F_82 ( V_61 ) ) ;
V_144 = ( V_142 ? V_147 :
V_148 ) ;
} else {
for ( V_69 = 0 ; V_69 < V_119 ; V_69 ++ ) {
T_12 V_61 = F_87 ( V_107 , V_69 ) ;
F_120 ( F_121 ( V_96 [ V_69 ] . V_145 ) , F_84 ( V_61 ) ) ;
F_120 ( F_121 ( V_96 [ V_69 ] . V_146 ) , F_82 ( V_61 ) ) ;
}
V_144 = ( V_142 ? V_149 :
V_150 ) ;
}
F_120 ( F_121 ( V_151 ) , V_144 ) ;
return 0 ;
}
static void F_122 ( struct V_85 * V_24 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
if ( F_65 ( V_2 ) )
F_66 ( V_2 , V_24 -> V_105 ) ;
F_57 ( V_2 , V_24 -> V_101 ) ;
F_49 ( V_2 , V_24 -> V_94 ) ;
F_41 ( V_2 , & V_24 -> V_87 ) ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
int V_69 ;
F_115 (i, pdp->used_pdpes, I915_PDPES_PER_PDP(dev_priv)) {
if ( F_29 ( ! V_96 -> V_99 [ V_69 ] ) )
continue;
F_114 ( V_2 , V_96 -> V_99 [ V_69 ] ) ;
F_57 ( V_2 , V_96 -> V_99 [ V_69 ] ) ;
}
F_66 ( V_2 , V_96 ) ;
}
static void F_124 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_53 ( V_107 -> V_110 . V_58 ) ;
int V_69 ;
F_115 (i, ppgtt->pml4.used_pml4es, GEN8_PML4ES_PER_PML4) {
if ( F_29 ( ! V_107 -> V_103 . V_133 [ V_69 ] ) )
continue;
F_123 ( V_2 , V_107 -> V_103 . V_133 [ V_69 ] ) ;
}
F_50 ( V_2 , & V_107 -> V_103 ) ;
}
static void F_125 ( struct V_85 * V_24 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_106 * V_107 = F_92 ( V_24 ) ;
if ( F_4 ( V_2 ) )
F_119 ( V_107 , false ) ;
if ( ! F_65 ( V_2 ) )
F_123 ( V_2 , & V_107 -> V_96 ) ;
else
F_124 ( V_107 ) ;
F_122 ( V_24 ) ;
}
static int F_126 ( struct V_85 * V_24 ,
struct V_89 * V_90 ,
T_7 V_27 ,
T_7 V_123 ,
unsigned long * V_152 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_75 * V_76 ;
T_8 V_40 ;
F_99 (pt, pd, start, length, pde) {
if ( F_127 ( V_40 , V_90 -> V_91 ) ) {
F_29 ( V_76 == V_24 -> V_94 ) ;
continue;
}
V_76 = F_42 ( V_2 ) ;
if ( F_117 ( V_76 ) )
goto V_153;
F_51 ( V_24 , V_76 ) ;
V_90 -> V_128 [ V_40 ] = V_76 ;
F_128 ( V_40 , V_152 ) ;
F_129 ( V_24 , V_40 , V_27 , V_154 ) ;
}
return 0 ;
V_153:
F_115 (pde, new_pts, I915_PDES)
F_49 ( V_2 , V_90 -> V_128 [ V_40 ] ) ;
return - V_60 ;
}
static int
F_130 ( struct V_85 * V_24 ,
struct V_95 * V_96 ,
T_7 V_27 ,
T_7 V_123 ,
unsigned long * V_155 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_89 * V_90 ;
T_8 V_129 ;
T_8 V_97 = F_62 ( V_2 ) ;
F_29 ( ! F_97 ( V_155 , V_97 ) ) ;
F_102 (pd, pdp, start, length, pdpe) {
if ( F_127 ( V_129 , V_96 -> V_98 ) )
continue;
V_90 = F_56 ( V_2 ) ;
if ( F_117 ( V_90 ) )
goto V_153;
F_59 ( V_24 , V_90 ) ;
V_96 -> V_99 [ V_129 ] = V_90 ;
F_128 ( V_129 , V_155 ) ;
F_131 ( V_24 , V_129 , V_27 , V_156 ) ;
}
return 0 ;
V_153:
F_115 (pdpe, new_pds, pdpes)
F_57 ( V_2 , V_96 -> V_99 [ V_129 ] ) ;
return - V_60 ;
}
static int
F_132 ( struct V_85 * V_24 ,
struct V_102 * V_103 ,
T_7 V_27 ,
T_7 V_123 ,
unsigned long * V_157 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_95 * V_96 ;
T_8 V_131 ;
F_29 ( ! F_97 ( V_157 , V_158 ) ) ;
F_104 (pdp, pml4, start, length, pml4e) {
if ( ! F_127 ( V_131 , V_103 -> V_134 ) ) {
V_96 = F_64 ( V_2 ) ;
if ( F_117 ( V_96 ) )
goto V_153;
F_67 ( V_24 , V_96 ) ;
V_103 -> V_133 [ V_131 ] = V_96 ;
F_128 ( V_131 , V_157 ) ;
F_133 ( V_24 ,
V_131 ,
V_27 ,
V_159 ) ;
}
}
return 0 ;
V_153:
F_115 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_66 ( V_2 , V_103 -> V_133 [ V_131 ] ) ;
return - V_60 ;
}
static void
F_134 ( unsigned long * V_155 , unsigned long * V_152 )
{
F_48 ( V_152 ) ;
F_48 ( V_155 ) ;
}
static
int T_13 F_135 ( unsigned long * * V_155 ,
unsigned long * * V_152 ,
T_8 V_97 )
{
unsigned long * V_160 ;
unsigned long * V_161 ;
V_160 = F_45 ( F_46 ( V_97 ) , sizeof( unsigned long ) , V_162 ) ;
if ( ! V_160 )
return - V_60 ;
V_161 = F_45 ( V_97 , F_46 ( V_92 ) * sizeof( unsigned long ) ,
V_162 ) ;
if ( ! V_161 )
goto V_163;
* V_155 = V_160 ;
* V_152 = V_161 ;
return 0 ;
V_163:
F_134 ( V_160 , V_161 ) ;
return - V_60 ;
}
static int F_136 ( struct V_85 * V_24 ,
struct V_95 * V_96 ,
T_7 V_27 ,
T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
unsigned long * V_164 , * V_165 ;
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_89 * V_90 ;
const T_7 V_166 = V_27 ;
const T_7 V_167 = V_123 ;
T_8 V_129 ;
T_8 V_97 = F_62 ( V_2 ) ;
int V_80 ;
if ( F_29 ( V_27 + V_123 < V_27 ) )
return - V_168 ;
if ( F_29 ( V_27 + V_123 > V_24 -> V_169 ) )
return - V_168 ;
V_80 = F_135 ( & V_164 , & V_165 , V_97 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_130 ( V_24 , V_96 , V_27 , V_123 ,
V_164 ) ;
if ( V_80 ) {
F_134 ( V_164 , V_165 ) ;
return V_80 ;
}
F_102 (pd, pdp, start, length, pdpe) {
V_80 = F_126 ( V_24 , V_90 , V_27 , V_123 ,
V_165 + V_129 * F_46 ( V_92 ) ) ;
if ( V_80 )
goto V_163;
}
V_27 = V_166 ;
V_123 = V_167 ;
F_102 (pd, pdp, start, length, pdpe) {
T_4 * const V_99 = F_72 ( V_90 ) ;
struct V_75 * V_76 ;
T_7 V_170 = V_123 ;
T_7 V_171 = V_27 ;
T_8 V_40 ;
F_29 ( ! V_90 ) ;
F_99 (pt, pd, pd_start, pd_len, pde) {
F_29 ( ! V_76 ) ;
F_29 ( ! V_170 ) ;
F_29 ( ! F_93 ( V_171 , V_170 ) ) ;
F_137 ( V_76 -> V_82 ,
F_94 ( V_171 ) ,
F_93 ( V_171 , V_170 ) ) ;
F_128 ( V_40 , V_90 -> V_91 ) ;
V_99 [ V_40 ] = F_13 ( F_60 ( V_76 ) ,
V_44 ) ;
F_138 ( & V_107 -> V_110 , V_40 , V_76 ,
F_94 ( V_27 ) ,
F_93 ( V_27 , V_123 ) ,
V_78 ) ;
}
F_73 ( V_107 , V_99 ) ;
F_128 ( V_129 , V_96 -> V_98 ) ;
F_71 ( V_107 , V_96 , V_90 , V_129 ) ;
}
F_134 ( V_164 , V_165 ) ;
F_89 ( V_107 ) ;
return 0 ;
V_163:
while ( V_129 -- ) {
unsigned long V_172 ;
F_115 (temp, new_page_tables + pdpe *
BITS_TO_LONGS(I915_PDES), I915_PDES)
F_49 ( V_2 ,
V_96 -> V_99 [ V_129 ] -> V_128 [ V_172 ] ) ;
}
F_115 (pdpe, new_page_dirs, pdpes)
F_57 ( V_2 , V_96 -> V_99 [ V_129 ] ) ;
F_134 ( V_164 , V_165 ) ;
F_89 ( V_107 ) ;
return V_80 ;
}
static int F_139 ( struct V_85 * V_24 ,
struct V_102 * V_103 ,
T_7 V_27 ,
T_7 V_123 )
{
F_140 ( V_157 , V_158 ) ;
struct V_106 * V_107 = F_92 ( V_24 ) ;
struct V_95 * V_96 ;
T_7 V_131 ;
int V_80 = 0 ;
F_141 ( V_157 , V_158 ) ;
V_80 = F_132 ( V_24 , V_103 , V_27 , V_123 ,
V_157 ) ;
if ( V_80 )
return V_80 ;
F_142 ( F_143 ( V_157 , V_158 ) > 2 ,
L_3
L_4 ) ;
F_104 (pdp, pml4, start, length, pml4e) {
F_29 ( ! V_96 ) ;
V_80 = F_136 ( V_24 , V_96 , V_27 , V_123 ) ;
if ( V_80 )
goto V_163;
F_74 ( V_107 , V_103 , V_96 , V_131 ) ;
}
F_144 ( V_103 -> V_134 , V_157 , V_103 -> V_134 ,
V_158 ) ;
return 0 ;
V_163:
F_115 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_123 ( F_53 ( V_24 -> V_58 ) , V_103 -> V_133 [ V_131 ] ) ;
return V_80 ;
}
static int F_145 ( struct V_85 * V_24 ,
T_7 V_27 , T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
if ( F_65 ( F_53 ( V_24 -> V_58 ) ) )
return F_139 ( V_24 , & V_107 -> V_103 , V_27 , V_123 ) ;
else
return F_136 ( V_24 , & V_107 -> V_96 , V_27 , V_123 ) ;
}
static void F_146 ( struct V_95 * V_96 ,
T_7 V_27 , T_7 V_123 ,
T_2 V_86 ,
struct V_173 * V_174 )
{
struct V_89 * V_90 ;
T_8 V_129 ;
F_102 (pd, pdp, start, length, pdpe) {
struct V_75 * V_76 ;
T_7 V_170 = V_123 ;
T_7 V_171 = V_27 ;
T_8 V_40 ;
if ( ! F_127 ( V_129 , V_96 -> V_98 ) )
continue;
F_147 ( V_174 , L_5 , V_129 ) ;
F_99 (pt, pd, pd_start, pd_len, pde) {
T_8 V_32 ;
T_2 * V_126 ;
if ( ! F_127 ( V_40 , V_90 -> V_91 ) )
continue;
V_126 = F_72 ( V_76 ) ;
for ( V_32 = 0 ; V_32 < V_78 ; V_32 += 4 ) {
T_7 V_175 =
( V_129 << V_156 ) |
( V_40 << V_154 ) |
( V_32 << V_176 ) ;
int V_69 ;
bool V_177 = false ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ )
if ( V_126 [ V_32 + V_69 ] != V_86 )
V_177 = true ;
if ( ! V_177 )
continue;
F_147 ( V_174 , L_6 , V_175 , V_129 , V_40 , V_32 ) ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
if ( V_126 [ V_32 + V_69 ] != V_86 )
F_147 ( V_174 , L_7 , V_126 [ V_32 + V_69 ] ) ;
else
F_148 ( V_174 , L_8 ) ;
}
F_148 ( V_174 , L_9 ) ;
}
F_37 ( V_126 ) ;
}
}
}
static void F_149 ( struct V_106 * V_107 , struct V_173 * V_174 )
{
struct V_85 * V_24 = & V_107 -> V_110 ;
T_7 V_27 = V_107 -> V_110 . V_27 ;
T_7 V_123 = V_107 -> V_110 . V_169 ;
T_2 V_86 = F_12 ( V_24 -> V_87 . V_61 ,
V_44 ) ;
if ( ! F_65 ( F_53 ( V_24 -> V_58 ) ) ) {
F_146 ( & V_107 -> V_96 , V_27 , V_123 , V_86 , V_174 ) ;
} else {
T_7 V_131 ;
struct V_102 * V_103 = & V_107 -> V_103 ;
struct V_95 * V_96 ;
F_104 (pdp, pml4, start, length, pml4e) {
if ( ! F_127 ( V_131 , V_103 -> V_134 ) )
continue;
F_147 ( V_174 , L_10 , V_131 ) ;
F_146 ( V_96 , V_27 , V_123 , V_86 , V_174 ) ;
}
}
}
static int F_150 ( struct V_106 * V_107 )
{
unsigned long * V_164 , * V_165 ;
T_8 V_97 = F_62 ( F_53 ( V_107 -> V_110 . V_58 ) ) ;
int V_80 ;
V_80 = F_135 ( & V_164 , & V_165 , V_97 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_130 ( & V_107 -> V_110 , & V_107 -> V_96 ,
0 , 1ULL << 32 ,
V_164 ) ;
if ( ! V_80 )
* V_107 -> V_96 . V_98 = * V_164 ;
F_134 ( V_164 , V_165 ) ;
return V_80 ;
}
static int F_151 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_53 ( V_107 -> V_110 . V_58 ) ;
int V_80 ;
V_80 = F_116 ( & V_107 -> V_110 ) ;
if ( V_80 )
return V_80 ;
V_107 -> V_110 . V_27 = 0 ;
V_107 -> V_110 . V_178 = F_125 ;
V_107 -> V_110 . V_179 = F_145 ;
V_107 -> V_110 . V_25 = F_111 ;
V_107 -> V_110 . V_28 = F_105 ;
V_107 -> V_110 . V_180 = F_11 ;
V_107 -> V_110 . V_181 = F_10 ;
V_107 -> V_182 = F_149 ;
if ( F_65 ( V_2 ) ) {
V_80 = F_47 ( V_2 , & V_107 -> V_103 ) ;
if ( V_80 )
goto V_183;
F_69 ( & V_107 -> V_110 , & V_107 -> V_103 ) ;
V_107 -> V_110 . V_169 = 1ULL << 48 ;
V_107 -> V_184 = F_88 ;
} else {
V_80 = F_61 ( V_2 , & V_107 -> V_96 ) ;
if ( V_80 )
goto V_183;
V_107 -> V_110 . V_169 = 1ULL << 32 ;
V_107 -> V_184 = F_86 ;
F_133 ( & V_107 -> V_110 ,
0 , 0 ,
V_159 ) ;
if ( F_4 ( V_2 ) ) {
V_80 = F_150 ( V_107 ) ;
if ( V_80 )
goto V_183;
}
}
if ( F_4 ( V_2 ) )
F_119 ( V_107 , true ) ;
return 0 ;
V_183:
F_122 ( & V_107 -> V_110 ) ;
return V_80 ;
}
static void F_152 ( struct V_106 * V_107 , struct V_173 * V_174 )
{
struct V_85 * V_24 = & V_107 -> V_110 ;
struct V_75 * V_17 ;
T_5 V_86 ;
T_8 V_185 ;
T_8 V_32 , V_40 ;
T_8 V_27 = V_107 -> V_110 . V_27 , V_123 = V_107 -> V_110 . V_169 ;
V_86 = V_24 -> V_88 ( V_24 -> V_87 . V_61 ,
V_44 , 0 ) ;
F_153 (unused, &ppgtt->pd, start, length, pde) {
T_1 V_186 ;
T_5 * V_126 ;
const T_3 V_187 = F_60 ( V_107 -> V_90 . V_128 [ V_40 ] ) ;
V_185 = F_154 ( V_107 -> V_188 + V_40 ) ;
V_186 = ( F_155 ( V_187 ) | V_189 ) ;
if ( V_185 != V_186 )
F_147 ( V_174 , L_11 ,
V_40 ,
V_185 ,
V_186 ) ;
F_147 ( V_174 , L_12 , V_185 ) ;
V_126 = F_72 ( V_107 -> V_90 . V_128 [ V_40 ] ) ;
for ( V_32 = 0 ; V_32 < V_79 ; V_32 += 4 ) {
unsigned long V_175 =
( V_40 * V_67 * V_79 ) +
( V_32 * V_67 ) ;
int V_69 ;
bool V_177 = false ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ )
if ( V_126 [ V_32 + V_69 ] != V_86 )
V_177 = true ;
if ( ! V_177 )
continue;
F_147 ( V_174 , L_13 , V_175 , V_40 , V_32 ) ;
for ( V_69 = 0 ; V_69 < 4 ; V_69 ++ ) {
if ( V_126 [ V_32 + V_69 ] != V_86 )
F_147 ( V_174 , L_14 , V_126 [ V_32 + V_69 ] ) ;
else
F_148 ( V_174 , L_8 ) ;
}
F_148 ( V_174 , L_9 ) ;
}
F_73 ( V_107 , V_126 ) ;
}
}
static void F_156 ( struct V_89 * V_90 ,
const int V_40 , struct V_75 * V_76 )
{
struct V_106 * V_107 =
F_157 ( V_90 , struct V_106 , V_90 ) ;
T_1 V_185 ;
V_185 = F_155 ( F_60 ( V_76 ) ) ;
V_185 |= V_189 ;
F_158 ( V_185 , V_107 -> V_188 + V_40 ) ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_89 * V_90 ,
T_8 V_27 , T_8 V_123 )
{
struct V_190 * V_191 = & V_2 -> V_191 ;
struct V_75 * V_76 ;
T_8 V_40 ;
F_153 (pt, pd, start, length, pde)
F_156 ( V_90 , V_40 , V_76 ) ;
F_154 ( V_191 -> V_192 ) ;
}
static T_8 F_160 ( struct V_106 * V_107 )
{
F_76 ( V_107 -> V_90 . V_110 . V_193 & 0x3f ) ;
return ( V_107 -> V_90 . V_110 . V_193 / 64 ) << 16 ;
}
static int F_161 ( struct V_106 * V_107 ,
struct V_112 * V_113 )
{
struct V_115 * V_116 = V_113 -> V_116 ;
struct V_117 * V_118 = V_113 -> V_118 ;
int V_80 ;
V_80 = V_118 -> V_194 ( V_113 , V_195 | V_196 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_77 ( V_113 , 6 ) ;
if ( V_80 )
return V_80 ;
F_78 ( V_116 , F_79 ( 2 ) ) ;
F_80 ( V_116 , F_162 ( V_118 ) ) ;
F_78 ( V_116 , V_197 ) ;
F_80 ( V_116 , F_163 ( V_118 ) ) ;
F_78 ( V_116 , F_160 ( V_107 ) ) ;
F_78 ( V_116 , V_198 ) ;
F_85 ( V_116 ) ;
return 0 ;
}
static int F_164 ( struct V_106 * V_107 ,
struct V_112 * V_113 )
{
struct V_115 * V_116 = V_113 -> V_116 ;
struct V_117 * V_118 = V_113 -> V_118 ;
int V_80 ;
V_80 = V_118 -> V_194 ( V_113 , V_195 | V_196 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_77 ( V_113 , 6 ) ;
if ( V_80 )
return V_80 ;
F_78 ( V_116 , F_79 ( 2 ) ) ;
F_80 ( V_116 , F_162 ( V_118 ) ) ;
F_78 ( V_116 , V_197 ) ;
F_80 ( V_116 , F_163 ( V_118 ) ) ;
F_78 ( V_116 , F_160 ( V_107 ) ) ;
F_78 ( V_116 , V_198 ) ;
F_85 ( V_116 ) ;
if ( V_118 -> V_199 != V_200 ) {
V_80 = V_118 -> V_194 ( V_113 , V_195 | V_196 ) ;
if ( V_80 )
return V_80 ;
}
return 0 ;
}
static int F_165 ( struct V_106 * V_107 ,
struct V_112 * V_113 )
{
struct V_117 * V_118 = V_113 -> V_118 ;
struct V_1 * V_2 = V_113 -> V_11 ;
F_120 ( F_162 ( V_118 ) , V_197 ) ;
F_120 ( F_163 ( V_118 ) , F_160 ( V_107 ) ) ;
return 0 ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
enum V_201 V_199 ;
F_167 (engine, dev_priv, id) {
T_1 V_202 = F_65 ( V_2 ) ?
V_203 : 0 ;
F_120 ( F_168 ( V_118 ) ,
F_169 ( V_204 | V_202 ) ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
T_8 V_205 , V_206 ;
enum V_201 V_199 ;
V_206 = F_171 ( V_207 ) ;
F_120 ( V_207 , V_206 | V_208 ) ;
V_205 = F_171 ( V_209 ) ;
if ( F_172 ( V_2 ) ) {
V_205 |= V_210 ;
} else {
V_205 |= V_211 ;
V_205 &= ~ V_212 ;
}
F_120 ( V_209 , V_205 ) ;
F_167 (engine, dev_priv, id) {
F_120 ( F_168 ( V_118 ) ,
F_169 ( V_204 ) ) ;
}
}
static void F_173 ( struct V_1 * V_2 )
{
T_8 V_205 , V_213 , V_206 ;
V_206 = F_171 ( V_207 ) ;
F_120 ( V_207 , V_206 | V_214 |
V_208 ) ;
V_213 = F_171 ( V_215 ) ;
F_120 ( V_215 , V_213 | V_216 ) ;
V_205 = F_171 ( V_209 ) ;
F_120 ( V_209 , V_205 | V_217 | V_218 ) ;
F_120 ( V_219 , F_169 ( V_204 ) ) ;
}
static void F_174 ( struct V_85 * V_24 ,
T_7 V_27 ,
T_7 V_123 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
T_5 * V_126 , V_86 ;
unsigned V_220 = V_27 >> V_140 ;
unsigned V_124 = V_123 >> V_140 ;
unsigned V_221 = V_220 / V_79 ;
unsigned V_222 = V_220 % V_79 ;
unsigned V_223 , V_69 ;
V_86 = V_24 -> V_88 ( V_24 -> V_87 . V_61 ,
V_44 , 0 ) ;
while ( V_124 ) {
V_223 = V_222 + V_124 ;
if ( V_223 > V_79 )
V_223 = V_79 ;
V_126 = F_72 ( V_107 -> V_90 . V_128 [ V_221 ] ) ;
for ( V_69 = V_222 ; V_69 < V_223 ; V_69 ++ )
V_126 [ V_69 ] = V_86 ;
F_73 ( V_107 , V_126 ) ;
V_124 -= V_223 - V_222 ;
V_222 = 0 ;
V_221 ++ ;
}
}
static void F_175 ( struct V_85 * V_24 ,
struct V_137 * V_19 ,
T_7 V_27 ,
enum V_15 V_16 , T_1 V_48 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
unsigned V_220 = V_27 >> V_140 ;
unsigned V_221 = V_220 / V_79 ;
unsigned V_224 = V_220 % V_79 ;
T_5 * V_126 = NULL ;
struct V_225 V_225 ;
T_3 V_30 ;
F_176 (addr, sgt_iter, pages) {
if ( V_126 == NULL )
V_126 = F_72 ( V_107 -> V_90 . V_128 [ V_221 ] ) ;
V_126 [ V_224 ] =
V_24 -> V_88 ( V_30 , V_16 , V_48 ) ;
if ( ++ V_224 == V_79 ) {
F_73 ( V_107 , V_126 ) ;
V_126 = NULL ;
V_221 ++ ;
V_224 = 0 ;
}
}
if ( V_126 )
F_73 ( V_107 , V_126 ) ;
}
static int F_177 ( struct V_85 * V_24 ,
T_7 V_226 , T_7 V_227 )
{
F_140 ( V_165 , V_92 ) ;
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_190 * V_191 = & V_2 -> V_191 ;
struct V_106 * V_107 = F_92 ( V_24 ) ;
struct V_75 * V_76 ;
T_8 V_27 , V_123 , V_228 , V_229 ;
T_8 V_40 ;
int V_80 ;
if ( F_29 ( V_226 + V_227 > V_107 -> V_110 . V_169 ) )
return - V_168 ;
V_27 = V_228 = V_226 ;
V_123 = V_229 = V_227 ;
F_141 ( V_165 , V_92 ) ;
F_153 (pt, &ppgtt->pd, start, length, pde) {
if ( V_76 != V_24 -> V_94 ) {
F_29 ( F_97 ( V_76 -> V_82 , V_79 ) ) ;
continue;
}
F_29 ( ! F_97 ( V_76 -> V_82 , V_79 ) ) ;
V_76 = F_42 ( V_2 ) ;
if ( F_117 ( V_76 ) ) {
V_80 = F_118 ( V_76 ) ;
goto V_153;
}
F_54 ( V_24 , V_76 ) ;
V_107 -> V_90 . V_128 [ V_40 ] = V_76 ;
F_128 ( V_40 , V_165 ) ;
F_129 ( V_24 , V_40 , V_27 , V_230 ) ;
}
V_27 = V_228 ;
V_123 = V_229 ;
F_153 (pt, &ppgtt->pd, start, length, pde) {
F_140 ( V_231 , V_79 ) ;
F_141 ( V_231 , V_79 ) ;
F_137 ( V_231 , F_178 ( V_27 ) ,
F_179 ( V_27 , V_123 ) ) ;
if ( F_180 ( V_40 , V_165 ) )
F_156 ( & V_107 -> V_90 , V_40 , V_76 ) ;
F_138 ( V_24 , V_40 , V_76 ,
F_178 ( V_27 ) ,
F_179 ( V_27 , V_123 ) ,
V_79 ) ;
F_144 ( V_76 -> V_82 , V_231 , V_76 -> V_82 ,
V_79 ) ;
}
F_29 ( ! F_97 ( V_165 , V_92 ) ) ;
F_154 ( V_191 -> V_192 ) ;
F_89 ( V_107 ) ;
return 0 ;
V_153:
F_115 (pde, new_page_tables, I915_PDES) {
struct V_75 * V_76 = V_107 -> V_90 . V_128 [ V_40 ] ;
V_107 -> V_90 . V_128 [ V_40 ] = V_24 -> V_94 ;
F_49 ( V_2 , V_76 ) ;
}
F_89 ( V_107 ) ;
return V_80 ;
}
static int F_181 ( struct V_85 * V_24 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
int V_80 ;
V_80 = F_40 ( V_2 , & V_24 -> V_87 , V_64 ) ;
if ( V_80 )
return V_80 ;
V_24 -> V_94 = F_42 ( V_2 ) ;
if ( F_117 ( V_24 -> V_94 ) ) {
F_41 ( V_2 , & V_24 -> V_87 ) ;
return F_118 ( V_24 -> V_94 ) ;
}
F_54 ( V_24 , V_24 -> V_94 ) ;
return 0 ;
}
static void F_182 ( struct V_85 * V_24 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
F_49 ( V_2 , V_24 -> V_94 ) ;
F_41 ( V_2 , & V_24 -> V_87 ) ;
}
static void F_183 ( struct V_85 * V_24 )
{
struct V_106 * V_107 = F_92 ( V_24 ) ;
struct V_89 * V_90 = & V_107 -> V_90 ;
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_75 * V_76 ;
T_8 V_40 ;
F_184 ( & V_107 -> V_26 ) ;
F_185 (pt, pd, pde)
if ( V_76 != V_24 -> V_94 )
F_49 ( V_2 , V_76 ) ;
F_182 ( V_24 ) ;
}
static int F_186 ( struct V_106 * V_107 )
{
struct V_85 * V_24 = & V_107 -> V_110 ;
struct V_1 * V_2 = F_53 ( V_107 -> V_110 . V_58 ) ;
struct V_190 * V_191 = & V_2 -> V_191 ;
bool V_232 = false ;
int V_80 ;
F_76 ( ! F_187 ( & V_191 -> V_110 . V_21 ) ) ;
V_80 = F_181 ( V_24 ) ;
if ( V_80 )
return V_80 ;
V_233:
V_80 = F_188 ( & V_191 -> V_110 . V_21 ,
& V_107 -> V_26 , V_234 ,
V_235 , 0 ,
0 , V_191 -> V_110 . V_169 ,
V_236 ) ;
if ( V_80 == - V_237 && ! V_232 ) {
V_80 = F_189 ( & V_191 -> V_110 ,
V_234 , V_235 ,
V_35 ,
0 , V_191 -> V_110 . V_169 ,
0 ) ;
if ( V_80 )
goto V_163;
V_232 = true ;
goto V_233;
}
if ( V_80 )
goto V_163;
if ( V_107 -> V_26 . V_27 < V_191 -> V_238 )
F_190 ( L_15 ) ;
return 0 ;
V_163:
F_182 ( V_24 ) ;
return V_80 ;
}
static int F_191 ( struct V_106 * V_107 )
{
return F_186 ( V_107 ) ;
}
static void F_192 ( struct V_106 * V_107 ,
T_7 V_27 , T_7 V_123 )
{
struct V_75 * V_17 ;
T_8 V_40 ;
F_153 (unused, &ppgtt->pd, start, length, pde)
V_107 -> V_90 . V_128 [ V_40 ] = V_107 -> V_110 . V_94 ;
}
static int F_193 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_53 ( V_107 -> V_110 . V_58 ) ;
struct V_190 * V_191 = & V_2 -> V_191 ;
int V_80 ;
V_107 -> V_110 . V_88 = V_191 -> V_110 . V_88 ;
if ( F_4 ( V_2 ) || F_6 ( V_2 ) )
V_107 -> V_184 = F_165 ;
else if ( F_172 ( V_2 ) )
V_107 -> V_184 = F_161 ;
else if ( F_194 ( V_2 ) )
V_107 -> V_184 = F_164 ;
else
F_195 () ;
V_80 = F_191 ( V_107 ) ;
if ( V_80 )
return V_80 ;
V_107 -> V_110 . V_179 = F_177 ;
V_107 -> V_110 . V_28 = F_174 ;
V_107 -> V_110 . V_25 = F_175 ;
V_107 -> V_110 . V_180 = F_11 ;
V_107 -> V_110 . V_181 = F_10 ;
V_107 -> V_110 . V_178 = F_183 ;
V_107 -> V_110 . V_27 = 0 ;
V_107 -> V_110 . V_169 = V_92 * V_79 * V_67 ;
V_107 -> V_182 = F_152 ;
V_107 -> V_90 . V_110 . V_193 =
V_107 -> V_26 . V_27 / V_67 * sizeof( T_5 ) ;
V_107 -> V_188 = ( T_5 V_239 * ) V_191 -> V_192 +
V_107 -> V_90 . V_110 . V_193 / sizeof( T_5 ) ;
F_192 ( V_107 , 0 , V_107 -> V_110 . V_169 ) ;
F_159 ( V_2 , & V_107 -> V_90 , 0 , V_107 -> V_110 . V_169 ) ;
F_9 ( L_16 ,
V_107 -> V_26 . V_29 >> 20 ,
V_107 -> V_26 . V_27 / V_67 ) ;
F_190 ( L_17 ,
V_107 -> V_90 . V_110 . V_193 << 10 ) ;
return 0 ;
}
static int F_196 ( struct V_106 * V_107 ,
struct V_1 * V_2 )
{
V_107 -> V_110 . V_58 = & V_2 -> V_8 ;
if ( F_90 ( V_2 ) -> V_240 < 8 )
return F_193 ( V_107 ) ;
else
return F_151 ( V_107 ) ;
}
static void F_197 ( struct V_85 * V_24 ,
struct V_1 * V_2 ,
const char * V_241 )
{
F_198 ( V_2 , & V_24 -> V_242 , V_241 ) ;
F_199 ( & V_24 -> V_21 , V_24 -> V_27 , V_24 -> V_169 ) ;
F_200 ( & V_24 -> V_243 ) ;
F_200 ( & V_24 -> V_244 ) ;
F_200 ( & V_24 -> V_245 ) ;
F_201 ( & V_24 -> V_246 , & V_2 -> V_247 ) ;
}
static void F_202 ( struct V_85 * V_24 )
{
F_203 ( & V_24 -> V_242 ) ;
F_204 ( & V_24 -> V_21 ) ;
F_205 ( & V_24 -> V_246 ) ;
}
static void F_206 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) )
F_120 ( V_248 , V_249 ) ;
else if ( F_34 ( V_2 ) )
F_120 ( V_248 , V_250 ) ;
else if ( F_207 ( V_2 ) )
F_120 ( V_248 , V_251 ) ;
else if ( F_35 ( V_2 ) )
F_120 ( V_248 , V_252 ) ;
}
static int F_208 ( struct V_106 * V_107 ,
struct V_1 * V_2 ,
struct V_253 * V_254 ,
const char * V_241 )
{
int V_80 ;
V_80 = F_196 ( V_107 , V_2 ) ;
if ( V_80 == 0 ) {
F_209 ( & V_107 -> V_255 ) ;
F_197 ( & V_107 -> V_110 , V_2 , V_241 ) ;
V_107 -> V_110 . V_256 = V_254 ;
}
return V_80 ;
}
int F_210 ( struct V_1 * V_2 )
{
F_206 ( V_2 ) ;
if ( V_11 . V_12 )
return 0 ;
if ( ! F_211 ( V_2 ) )
return 0 ;
if ( F_6 ( V_2 ) )
F_173 ( V_2 ) ;
else if ( F_194 ( V_2 ) )
F_170 ( V_2 ) ;
else if ( F_2 ( V_2 ) >= 8 )
F_166 ( V_2 ) ;
else
F_16 ( F_2 ( V_2 ) ) ;
return 0 ;
}
struct V_106 *
F_212 ( struct V_1 * V_2 ,
struct V_253 * V_257 ,
const char * V_241 )
{
struct V_106 * V_107 ;
int V_80 ;
V_107 = F_43 ( sizeof( * V_107 ) , V_81 ) ;
if ( ! V_107 )
return F_44 ( - V_60 ) ;
V_80 = F_208 ( V_107 , V_2 , V_257 , V_241 ) ;
if ( V_80 ) {
F_48 ( V_107 ) ;
return F_44 ( V_80 ) ;
}
F_213 ( & V_107 -> V_110 ) ;
return V_107 ;
}
void F_214 ( struct V_258 * V_258 )
{
struct V_106 * V_107 =
F_157 ( V_258 , struct V_106 , V_255 ) ;
F_215 ( & V_107 -> V_110 ) ;
F_29 ( ! F_216 ( & V_107 -> V_110 . V_243 ) ) ;
F_29 ( ! F_216 ( & V_107 -> V_110 . V_244 ) ) ;
F_29 ( ! F_216 ( & V_107 -> V_110 . V_245 ) ) ;
F_202 ( & V_107 -> V_110 ) ;
V_107 -> V_110 . V_178 ( & V_107 -> V_110 ) ;
F_48 ( V_107 ) ;
}
static bool F_217 ( struct V_1 * V_2 )
{
#ifdef F_5
if ( F_218 ( V_2 ) && F_219 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
void F_220 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
enum V_201 V_199 ;
if ( F_90 ( V_2 ) -> V_240 < 6 )
return;
F_167 (engine, dev_priv, id) {
T_1 V_259 ;
V_259 = F_171 ( F_221 ( V_118 ) ) ;
if ( V_259 & V_260 ) {
F_9 ( L_18
L_19
L_20
L_21
L_22 ,
V_259 & V_261 ,
V_259 & V_262 ? L_23 : L_24 ,
F_222 ( V_259 ) ,
F_223 ( V_259 ) ) ;
F_120 ( F_221 ( V_118 ) ,
V_259 & ~ V_260 ) ;
}
}
if ( V_2 -> V_118 [ V_200 ] )
F_224 ( F_221 ( V_2 -> V_118 [ V_200 ] ) ) ;
}
static void F_225 ( struct V_1 * V_2 )
{
if ( F_90 ( V_2 ) -> V_240 < 6 ) {
F_226 () ;
} else {
F_120 ( V_263 , V_264 ) ;
F_224 ( V_263 ) ;
}
}
void F_227 ( struct V_1 * V_2 )
{
struct V_190 * V_191 = & V_2 -> V_191 ;
if ( F_2 ( V_2 ) < 6 )
return;
F_220 ( V_2 ) ;
V_191 -> V_110 . V_28 ( & V_191 -> V_110 , V_191 -> V_110 . V_27 , V_191 -> V_110 . V_169 ) ;
F_225 ( V_2 ) ;
}
int F_228 ( struct V_265 * V_20 ,
struct V_137 * V_19 )
{
if ( F_229 ( & V_20 -> V_110 . V_58 -> V_9 -> V_58 ,
V_19 -> V_138 , V_19 -> V_266 ,
V_62 ) )
return 0 ;
return - V_237 ;
}
static void F_230 ( void V_239 * V_30 , T_2 V_32 )
{
F_231 ( V_32 , V_30 ) ;
}
static void F_232 ( struct V_85 * V_24 ,
T_3 V_30 ,
T_7 V_267 ,
enum V_15 V_31 ,
T_1 V_17 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
T_2 V_239 * V_32 =
( T_2 V_239 * ) V_2 -> V_191 . V_192 +
( V_267 >> V_140 ) ;
F_230 ( V_32 , F_12 ( V_30 , V_31 ) ) ;
F_120 ( V_263 , V_264 ) ;
F_224 ( V_263 ) ;
}
static void F_233 ( struct V_85 * V_24 ,
struct V_137 * V_268 ,
T_7 V_27 ,
enum V_15 V_31 , T_1 V_17 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_190 * V_191 = F_234 ( V_24 ) ;
struct V_225 V_225 ;
T_2 V_239 * V_269 ;
T_2 V_270 ;
T_3 V_30 ;
int V_69 = 0 ;
V_269 = ( T_2 V_239 * ) V_191 -> V_192 + ( V_27 >> V_140 ) ;
F_176 (addr, sgt_iter, st) {
V_270 = F_12 ( V_30 , V_31 ) ;
F_230 ( & V_269 [ V_69 ++ ] , V_270 ) ;
}
if ( V_69 != 0 )
F_29 ( F_235 ( & V_269 [ V_69 - 1 ] ) != V_270 ) ;
F_120 ( V_263 , V_264 ) ;
F_224 ( V_263 ) ;
}
static int F_236 ( void * V_271 )
{
struct V_25 * V_272 = V_271 ;
F_233 ( V_272 -> V_24 , V_272 -> V_268 ,
V_272 -> V_27 , V_272 -> V_31 , V_272 -> V_48 ) ;
return 0 ;
}
static void F_237 ( struct V_85 * V_24 ,
struct V_137 * V_268 ,
T_7 V_27 ,
enum V_15 V_31 ,
T_1 V_48 )
{
struct V_25 V_272 = { V_24 , V_268 , V_27 , V_31 , V_48 } ;
F_238 ( F_236 , & V_272 , NULL ) ;
}
static void F_239 ( struct V_85 * V_24 ,
T_3 V_30 ,
T_7 V_267 ,
enum V_15 V_31 ,
T_1 V_48 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
T_5 V_239 * V_32 =
( T_5 V_239 * ) V_2 -> V_191 . V_192 +
( V_267 >> V_140 ) ;
F_240 ( V_24 -> V_88 ( V_30 , V_31 , V_48 ) , V_32 ) ;
F_120 ( V_263 , V_264 ) ;
F_224 ( V_263 ) ;
}
static void F_241 ( struct V_85 * V_24 ,
struct V_137 * V_268 ,
T_7 V_27 ,
enum V_15 V_31 , T_1 V_48 )
{
struct V_1 * V_2 = F_53 ( V_24 -> V_58 ) ;
struct V_190 * V_191 = F_234 ( V_24 ) ;
struct V_225 V_225 ;
T_5 V_239 * V_269 ;
T_5 V_270 ;
T_3 V_30 ;
int V_69 = 0 ;
V_269 = ( T_5 V_239 * ) V_191 -> V_192 + ( V_27 >> V_140 ) ;
F_176 (addr, sgt_iter, st) {
V_270 = V_24 -> V_88 ( V_30 , V_31 , V_48 ) ;
F_240 ( V_270 , & V_269 [ V_69 ++ ] ) ;
}
if ( V_69 != 0 )
F_29 ( F_154 ( & V_269 [ V_69 - 1 ] ) != V_270 ) ;
F_120 ( V_263 , V_264 ) ;
F_224 ( V_263 ) ;
}
static void F_242 ( struct V_85 * V_24 ,
T_7 V_27 , T_7 V_123 )
{
}
static void F_243 ( struct V_85 * V_24 ,
T_7 V_27 , T_7 V_123 )
{
struct V_190 * V_191 = F_234 ( V_24 ) ;
unsigned V_220 = V_27 >> V_140 ;
unsigned V_124 = V_123 >> V_140 ;
T_2 V_86 , V_239 * V_273 =
( T_2 V_239 * ) V_191 -> V_192 + V_220 ;
const int V_274 = F_244 ( V_191 ) - V_220 ;
int V_69 ;
if ( F_142 ( V_124 > V_274 ,
L_25 ,
V_220 , V_124 , V_274 ) )
V_124 = V_274 ;
V_86 = F_12 ( V_24 -> V_87 . V_61 ,
V_44 ) ;
for ( V_69 = 0 ; V_69 < V_124 ; V_69 ++ )
F_230 ( & V_273 [ V_69 ] , V_86 ) ;
F_154 ( V_273 ) ;
}
static void F_245 ( struct V_85 * V_24 ,
T_7 V_27 ,
T_7 V_123 )
{
struct V_190 * V_191 = F_234 ( V_24 ) ;
unsigned V_220 = V_27 >> V_140 ;
unsigned V_124 = V_123 >> V_140 ;
T_5 V_86 , V_239 * V_273 =
( T_5 V_239 * ) V_191 -> V_192 + V_220 ;
const int V_274 = F_244 ( V_191 ) - V_220 ;
int V_69 ;
if ( F_142 ( V_124 > V_274 ,
L_25 ,
V_220 , V_124 , V_274 ) )
V_124 = V_274 ;
V_86 = V_24 -> V_88 ( V_24 -> V_87 . V_61 ,
V_44 , 0 ) ;
for ( V_69 = 0 ; V_69 < V_124 ; V_69 ++ )
F_240 ( V_86 , & V_273 [ V_69 ] ) ;
F_154 ( V_273 ) ;
}
static void F_246 ( struct V_85 * V_24 ,
T_3 V_30 ,
T_7 V_267 ,
enum V_15 V_16 ,
T_1 V_17 )
{
unsigned int V_48 = ( V_16 == V_35 ) ?
V_275 : V_276 ;
F_247 ( V_30 , V_267 >> V_140 , V_48 ) ;
}
static void F_248 ( struct V_85 * V_24 ,
struct V_137 * V_19 ,
T_7 V_27 ,
enum V_15 V_16 , T_1 V_17 )
{
unsigned int V_48 = ( V_16 == V_35 ) ?
V_275 : V_276 ;
F_249 ( V_19 , V_27 >> V_140 , V_48 ) ;
}
static void F_250 ( struct V_85 * V_24 ,
T_7 V_27 ,
T_7 V_123 )
{
F_251 ( V_27 >> V_140 , V_123 >> V_140 ) ;
}
static int F_252 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_48 )
{
struct V_1 * V_11 = F_53 ( V_14 -> V_24 -> V_58 ) ;
struct V_265 * V_20 = V_14 -> V_20 ;
T_1 V_18 = 0 ;
int V_80 ;
V_80 = F_253 ( V_14 ) ;
if ( V_80 )
return V_80 ;
if ( V_20 -> V_22 )
V_18 |= V_23 ;
F_254 ( V_11 ) ;
V_14 -> V_24 -> V_25 ( V_14 -> V_24 , V_14 -> V_19 , V_14 -> V_26 . V_27 ,
V_16 , V_18 ) ;
F_255 ( V_11 ) ;
V_14 -> V_48 |= V_277 | V_278 ;
return 0 ;
}
static int F_256 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_48 )
{
struct V_1 * V_11 = F_53 ( V_14 -> V_24 -> V_58 ) ;
T_1 V_18 ;
int V_80 ;
V_80 = F_253 ( V_14 ) ;
if ( V_80 )
return V_80 ;
V_18 = 0 ;
if ( V_14 -> V_20 -> V_22 )
V_18 |= V_23 ;
if ( V_48 & V_277 ) {
F_254 ( V_11 ) ;
V_14 -> V_24 -> V_25 ( V_14 -> V_24 ,
V_14 -> V_19 , V_14 -> V_26 . V_27 ,
V_16 , V_18 ) ;
F_255 ( V_11 ) ;
}
if ( V_48 & V_278 ) {
struct V_106 * V_279 = V_11 -> V_21 . V_280 ;
V_279 -> V_110 . V_25 ( & V_279 -> V_110 ,
V_14 -> V_19 , V_14 -> V_26 . V_27 ,
V_16 , V_18 ) ;
}
return 0 ;
}
static void F_257 ( struct V_13 * V_14 )
{
struct V_1 * V_11 = F_53 ( V_14 -> V_24 -> V_58 ) ;
struct V_106 * V_279 = V_11 -> V_21 . V_280 ;
const T_12 V_29 = F_258 ( V_14 -> V_29 , V_14 -> V_26 . V_29 ) ;
if ( V_14 -> V_48 & V_277 ) {
F_254 ( V_11 ) ;
V_14 -> V_24 -> V_28 ( V_14 -> V_24 ,
V_14 -> V_26 . V_27 , V_29 ) ;
F_255 ( V_11 ) ;
}
if ( V_14 -> V_48 & V_278 && V_279 )
V_279 -> V_110 . V_28 ( & V_279 -> V_110 ,
V_14 -> V_26 . V_27 , V_29 ) ;
}
void F_259 ( struct V_265 * V_20 ,
struct V_137 * V_19 )
{
struct V_1 * V_2 = F_53 ( V_20 -> V_110 . V_58 ) ;
struct V_56 * V_57 = & V_2 -> V_8 . V_9 -> V_58 ;
struct V_190 * V_191 = & V_2 -> V_191 ;
if ( F_260 ( V_191 -> V_281 ) ) {
if ( F_261 ( V_2 , V_282 ) ) {
F_262 ( L_26 ) ;
F_263 ( 10 ) ;
}
}
F_264 ( V_57 , V_19 -> V_138 , V_19 -> V_266 , V_62 ) ;
}
static void F_265 ( struct V_283 * V_26 ,
unsigned long V_284 ,
T_12 * V_27 ,
T_12 * V_285 )
{
if ( V_26 -> V_284 != V_284 )
* V_27 += 4096 ;
V_26 = F_266 ( & V_26 -> V_286 ,
struct V_283 ,
V_286 ) ;
if ( V_26 && V_26 -> V_287 && V_26 -> V_284 != V_284 )
* V_285 -= 4096 ;
}
int F_267 ( struct V_1 * V_2 )
{
struct V_190 * V_191 = & V_2 -> V_191 ;
unsigned long V_288 , V_289 ;
struct V_106 * V_107 ;
struct V_283 * V_114 ;
int V_80 ;
V_80 = F_268 ( V_2 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_188 ( & V_191 -> V_110 . V_21 ,
& V_191 -> V_290 ,
4096 , 0 , - 1 ,
0 , V_191 -> V_238 ,
0 , 0 ) ;
if ( V_80 )
return V_80 ;
F_269 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_270 ( L_27 ,
V_288 , V_289 ) ;
V_191 -> V_110 . V_28 ( & V_191 -> V_110 , V_288 ,
V_289 - V_288 ) ;
}
V_191 -> V_110 . V_28 ( & V_191 -> V_110 ,
V_191 -> V_110 . V_169 - V_67 , V_67 ) ;
if ( F_211 ( V_2 ) && ! F_271 ( V_2 ) ) {
V_107 = F_43 ( sizeof( * V_107 ) , V_81 ) ;
if ( ! V_107 ) {
V_80 = - V_60 ;
goto V_291;
}
V_80 = F_196 ( V_107 , V_2 ) ;
if ( V_80 )
goto V_292;
if ( V_107 -> V_110 . V_179 ) {
V_80 = V_107 -> V_110 . V_179 ( & V_107 -> V_110 , 0 ,
V_107 -> V_110 . V_169 ) ;
if ( V_80 )
goto V_293;
}
V_107 -> V_110 . V_28 ( & V_107 -> V_110 ,
V_107 -> V_110 . V_27 ,
V_107 -> V_110 . V_169 ) ;
V_2 -> V_21 . V_280 = V_107 ;
F_29 ( V_191 -> V_110 . V_181 != F_252 ) ;
V_191 -> V_110 . V_181 = F_256 ;
}
return 0 ;
V_293:
V_107 -> V_110 . V_178 ( & V_107 -> V_110 ) ;
V_292:
F_48 ( V_107 ) ;
V_291:
F_184 ( & V_191 -> V_290 ) ;
return V_80 ;
}
void F_272 ( struct V_1 * V_2 )
{
struct V_190 * V_191 = & V_2 -> V_191 ;
if ( V_2 -> V_21 . V_280 ) {
struct V_106 * V_107 = V_2 -> V_21 . V_280 ;
V_107 -> V_110 . V_178 ( & V_107 -> V_110 ) ;
F_48 ( V_107 ) ;
}
F_273 ( & V_2 -> V_8 ) ;
if ( F_274 ( & V_191 -> V_290 ) )
F_184 ( & V_191 -> V_290 ) ;
if ( F_187 ( & V_191 -> V_110 . V_21 ) ) {
F_275 ( V_2 ) ;
F_276 ( & V_2 -> V_8 . V_294 ) ;
F_202 ( & V_191 -> V_110 ) ;
F_277 ( & V_2 -> V_8 . V_294 ) ;
}
V_191 -> V_110 . V_178 ( & V_191 -> V_110 ) ;
F_278 ( V_191 -> V_295 ) ;
F_279 ( & V_191 -> V_296 ) ;
}
static unsigned int F_280 ( T_14 V_297 )
{
V_297 >>= V_298 ;
V_297 &= V_299 ;
return V_297 << 20 ;
}
static unsigned int F_281 ( T_14 V_300 )
{
V_300 >>= V_301 ;
V_300 &= V_302 ;
if ( V_300 )
V_300 = 1 << V_300 ;
#ifdef F_282
if ( V_300 > 4 )
V_300 = 4 ;
#endif
return V_300 << 20 ;
}
static unsigned int F_283 ( T_14 V_303 )
{
V_303 >>= V_298 ;
V_303 &= V_299 ;
if ( V_303 )
return 1 << ( 20 + V_303 ) ;
return 0 ;
}
static T_9 F_284 ( T_14 V_297 )
{
V_297 >>= V_304 ;
V_297 &= V_305 ;
return V_297 << 25 ;
}
static T_9 F_285 ( T_14 V_300 )
{
V_300 >>= V_306 ;
V_300 &= V_307 ;
return V_300 << 25 ;
}
static T_9 F_286 ( T_14 V_303 )
{
V_303 >>= V_304 ;
V_303 &= V_305 ;
if ( V_303 < 0x11 )
return V_303 << 25 ;
else if ( V_303 < 0x17 )
return ( V_303 - 0x11 + 2 ) << 22 ;
else
return ( V_303 - 0x17 + 9 ) << 22 ;
}
static T_9 F_287 ( T_14 V_308 )
{
V_308 >>= V_306 ;
V_308 &= V_307 ;
if ( V_308 < 0xf0 )
return V_308 << 25 ;
else
return ( V_308 - 0xf0 + 1 ) << 22 ;
}
static int F_288 ( struct V_190 * V_191 , T_12 V_29 )
{
struct V_1 * V_2 = F_53 ( V_191 -> V_110 . V_58 ) ;
struct V_65 * V_9 = V_191 -> V_110 . V_58 -> V_9 ;
T_15 V_309 ;
int V_80 ;
V_309 = F_289 ( V_9 , 0 ) + F_290 ( V_9 , 0 ) / 2 ;
if ( F_35 ( V_2 ) )
V_191 -> V_192 = F_291 ( V_309 , V_29 ) ;
else
V_191 -> V_192 = F_292 ( V_309 , V_29 ) ;
if ( ! V_191 -> V_192 ) {
F_262 ( L_28 ) ;
return - V_60 ;
}
V_80 = F_40 ( V_2 , & V_191 -> V_110 . V_87 , V_310 ) ;
if ( V_80 ) {
F_262 ( L_29 ) ;
F_293 ( V_191 -> V_192 ) ;
return V_80 ;
}
return 0 ;
}
static void F_294 ( struct V_1 * V_2 )
{
T_7 V_311 ;
V_311 = F_295 ( 0 , V_312 | V_313 ) |
F_295 ( 1 , V_314 | V_315 ) |
F_295 ( 2 , V_316 | V_315 ) |
F_295 ( 3 , V_317 ) |
F_295 ( 4 , V_312 | V_315 | F_296 ( 0 ) ) |
F_295 ( 5 , V_312 | V_315 | F_296 ( 1 ) ) |
F_295 ( 6 , V_312 | V_315 | F_296 ( 2 ) ) |
F_295 ( 7 , V_312 | V_315 | F_296 ( 3 ) ) ;
if ( ! F_211 ( V_2 ) )
V_311 = F_295 ( 0 , V_317 ) ;
F_120 ( V_318 , V_311 ) ;
F_120 ( V_319 , V_311 >> 32 ) ;
}
static void F_297 ( struct V_1 * V_2 )
{
T_7 V_311 ;
V_311 = F_295 ( 0 , V_320 ) |
F_295 ( 1 , 0 ) |
F_295 ( 2 , 0 ) |
F_295 ( 3 , 0 ) |
F_295 ( 4 , V_320 ) |
F_295 ( 5 , V_320 ) |
F_295 ( 6 , V_320 ) |
F_295 ( 7 , V_320 ) ;
F_120 ( V_318 , V_311 ) ;
F_120 ( V_319 , V_311 >> 32 ) ;
}
static void F_298 ( struct V_85 * V_24 )
{
struct V_190 * V_191 = F_234 ( V_24 ) ;
F_293 ( V_191 -> V_192 ) ;
F_41 ( F_53 ( V_24 -> V_58 ) , & V_24 -> V_87 ) ;
}
static int F_299 ( struct V_190 * V_191 )
{
struct V_1 * V_2 = F_53 ( V_191 -> V_110 . V_58 ) ;
struct V_65 * V_9 = V_2 -> V_8 . V_9 ;
unsigned int V_29 ;
T_14 V_297 ;
V_191 -> V_321 = F_289 ( V_9 , 2 ) ;
V_191 -> V_238 = F_290 ( V_9 , 2 ) ;
if ( ! F_300 ( V_9 , F_301 ( 39 ) ) )
F_302 ( V_9 , F_301 ( 39 ) ) ;
F_303 ( V_9 , V_322 , & V_297 ) ;
if ( F_2 ( V_2 ) >= 9 ) {
V_191 -> V_323 = F_287 ( V_297 ) ;
V_29 = F_281 ( V_297 ) ;
} else if ( F_34 ( V_2 ) ) {
V_191 -> V_323 = F_286 ( V_297 ) ;
V_29 = F_283 ( V_297 ) ;
} else {
V_191 -> V_323 = F_285 ( V_297 ) ;
V_29 = F_281 ( V_297 ) ;
}
V_191 -> V_110 . V_169 = ( V_29 / sizeof( T_2 ) ) << V_140 ;
if ( F_34 ( V_2 ) || F_35 ( V_2 ) )
F_297 ( V_2 ) ;
else
F_294 ( V_2 ) ;
V_191 -> V_110 . V_178 = F_298 ;
V_191 -> V_110 . V_181 = F_252 ;
V_191 -> V_110 . V_180 = F_257 ;
V_191 -> V_110 . V_324 = F_232 ;
V_191 -> V_110 . V_28 = F_242 ;
if ( ! F_271 ( V_2 ) || F_304 ( V_2 ) )
V_191 -> V_110 . V_28 = F_243 ;
V_191 -> V_110 . V_25 = F_233 ;
if ( F_34 ( V_2 ) )
V_191 -> V_110 . V_25 = F_237 ;
return F_288 ( V_191 , V_29 ) ;
}
static int F_305 ( struct V_190 * V_191 )
{
struct V_1 * V_2 = F_53 ( V_191 -> V_110 . V_58 ) ;
struct V_65 * V_9 = V_2 -> V_8 . V_9 ;
unsigned int V_29 ;
T_14 V_297 ;
V_191 -> V_321 = F_289 ( V_9 , 2 ) ;
V_191 -> V_238 = F_290 ( V_9 , 2 ) ;
if ( V_191 -> V_238 < ( 64 << 20 ) || V_191 -> V_238 > ( 512 << 20 ) ) {
F_262 ( L_30 , V_191 -> V_238 ) ;
return - V_325 ;
}
if ( ! F_300 ( V_9 , F_301 ( 40 ) ) )
F_302 ( V_9 , F_301 ( 40 ) ) ;
F_303 ( V_9 , V_322 , & V_297 ) ;
V_191 -> V_323 = F_284 ( V_297 ) ;
V_29 = F_280 ( V_297 ) ;
V_191 -> V_110 . V_169 = ( V_29 / sizeof( T_5 ) ) << V_140 ;
V_191 -> V_110 . V_28 = F_245 ;
V_191 -> V_110 . V_324 = F_239 ;
V_191 -> V_110 . V_25 = F_241 ;
V_191 -> V_110 . V_181 = F_252 ;
V_191 -> V_110 . V_180 = F_257 ;
V_191 -> V_110 . V_178 = F_298 ;
if ( F_306 ( V_2 ) )
V_191 -> V_110 . V_88 = F_21 ;
else if ( F_172 ( V_2 ) )
V_191 -> V_110 . V_88 = F_19 ;
else if ( F_8 ( V_2 ) )
V_191 -> V_110 . V_88 = F_18 ;
else if ( F_2 ( V_2 ) >= 7 )
V_191 -> V_110 . V_88 = F_17 ;
else
V_191 -> V_110 . V_88 = F_14 ;
return F_288 ( V_191 , V_29 ) ;
}
static void F_307 ( struct V_85 * V_24 )
{
F_308 () ;
}
static int F_309 ( struct V_190 * V_191 )
{
struct V_1 * V_2 = F_53 ( V_191 -> V_110 . V_58 ) ;
int V_80 ;
V_80 = F_310 ( V_2 -> V_326 , V_2 -> V_8 . V_9 , NULL ) ;
if ( ! V_80 ) {
F_262 ( L_31 ) ;
return - V_327 ;
}
F_311 ( & V_191 -> V_110 . V_169 , & V_191 -> V_323 ,
& V_191 -> V_321 , & V_191 -> V_238 ) ;
V_191 -> V_281 = F_217 ( V_2 ) ;
V_191 -> V_110 . V_324 = F_246 ;
V_191 -> V_110 . V_25 = F_248 ;
V_191 -> V_110 . V_28 = F_250 ;
V_191 -> V_110 . V_181 = F_252 ;
V_191 -> V_110 . V_180 = F_257 ;
V_191 -> V_110 . V_178 = F_307 ;
if ( F_260 ( V_191 -> V_281 ) )
F_7 ( L_32 ) ;
return 0 ;
}
int F_312 ( struct V_1 * V_2 )
{
struct V_190 * V_191 = & V_2 -> V_191 ;
int V_80 ;
V_191 -> V_110 . V_58 = & V_2 -> V_8 ;
if ( F_2 ( V_2 ) <= 5 )
V_80 = F_309 ( V_191 ) ;
else if ( F_2 ( V_2 ) < 8 )
V_80 = F_305 ( V_191 ) ;
else
V_80 = F_299 ( V_191 ) ;
if ( V_80 )
return V_80 ;
if ( ( V_191 -> V_110 . V_169 - 1 ) >> 32 ) {
F_262 ( L_33
L_34 ,
V_191 -> V_110 . V_169 >> 20 ) ;
V_191 -> V_110 . V_169 = 1ULL << 32 ;
V_191 -> V_238 = F_258 ( V_191 -> V_238 , V_191 -> V_110 . V_169 ) ;
}
if ( V_191 -> V_238 > V_191 -> V_110 . V_169 ) {
F_262 ( L_35
L_36 ,
V_191 -> V_238 , V_191 -> V_110 . V_169 ) ;
V_191 -> V_238 = V_191 -> V_110 . V_169 ;
}
F_7 ( L_37 ,
V_191 -> V_110 . V_169 >> 20 ) ;
F_9 ( L_38 , V_191 -> V_238 >> 20 ) ;
F_9 ( L_39 , V_191 -> V_323 >> 20 ) ;
#ifdef F_5
if ( V_7 )
F_7 ( L_40 ) ;
#endif
return 0 ;
}
int F_313 ( struct V_1 * V_2 )
{
struct V_190 * V_191 = & V_2 -> V_191 ;
int V_80 ;
F_200 ( & V_2 -> V_247 ) ;
F_276 ( & V_2 -> V_8 . V_294 ) ;
V_191 -> V_110 . V_169 -= V_67 ;
F_197 ( & V_191 -> V_110 , V_2 , L_41 ) ;
V_191 -> V_110 . V_169 += V_67 ;
if ( ! F_314 ( V_2 ) )
V_191 -> V_110 . V_21 . V_328 = F_265 ;
F_277 ( & V_2 -> V_8 . V_294 ) ;
if ( ! F_315 ( & V_2 -> V_191 . V_296 ,
V_2 -> V_191 . V_321 ,
V_2 -> V_191 . V_238 ) ) {
V_80 = - V_327 ;
goto V_329;
}
V_191 -> V_295 = F_316 ( V_191 -> V_321 , V_191 -> V_238 ) ;
V_80 = F_317 ( V_2 ) ;
if ( V_80 )
goto V_329;
return 0 ;
V_329:
V_191 -> V_110 . V_178 ( & V_191 -> V_110 ) ;
return V_80 ;
}
int F_318 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) < 6 && ! F_319 () )
return - V_327 ;
return 0 ;
}
void F_320 ( struct V_1 * V_2 )
{
struct V_190 * V_191 = & V_2 -> V_191 ;
struct V_265 * V_20 , * V_330 ;
F_220 ( V_2 ) ;
V_191 -> V_110 . V_28 ( & V_191 -> V_110 , V_191 -> V_110 . V_27 , V_191 -> V_110 . V_169 ) ;
V_191 -> V_110 . V_331 = true ;
F_321 (obj, on,
&dev_priv->mm.bound_list, global_link) {
bool V_332 = false ;
struct V_13 * V_14 ;
F_322 (vma, &obj->vma_list, obj_link) {
if ( V_14 -> V_24 != & V_191 -> V_110 )
continue;
if ( ! F_323 ( V_14 ) )
continue;
F_29 ( F_324 ( V_14 , V_20 -> V_16 ,
V_333 ) ) ;
V_332 = true ;
}
if ( V_332 )
F_29 ( F_325 ( V_20 , false ) ) ;
}
V_191 -> V_110 . V_331 = false ;
if ( F_2 ( V_2 ) >= 8 ) {
if ( F_34 ( V_2 ) || F_35 ( V_2 ) )
F_297 ( V_2 ) ;
else
F_294 ( V_2 ) ;
return;
}
if ( F_211 ( V_2 ) ) {
struct V_85 * V_24 ;
F_322 (vm, &dev_priv->vm_list, global_link) {
struct V_106 * V_107 ;
if ( F_326 ( V_24 ) )
V_107 = V_2 -> V_21 . V_280 ;
else
V_107 = F_92 ( V_24 ) ;
F_159 ( V_2 , & V_107 -> V_90 ,
0 , V_107 -> V_110 . V_169 ) ;
}
}
F_225 ( V_2 ) ;
}
struct V_13 *
F_327 ( struct V_265 * V_20 ,
struct V_85 * V_24 ,
const struct V_334 * V_335 )
{
struct V_336 * V_337 ;
V_337 = V_20 -> V_338 . V_336 ;
while ( V_337 ) {
struct V_13 * V_14 = F_328 ( V_337 , struct V_13 , V_339 ) ;
long V_340 ;
V_340 = F_329 ( V_14 , V_24 , V_335 ) ;
if ( V_340 == 0 )
return V_14 ;
if ( V_340 < 0 )
V_337 = V_337 -> V_341 ;
else
V_337 = V_337 -> V_342 ;
}
return NULL ;
}
struct V_13 *
F_330 ( struct V_265 * V_20 ,
struct V_85 * V_24 ,
const struct V_334 * V_335 )
{
struct V_13 * V_14 ;
F_331 ( & V_20 -> V_110 . V_58 -> V_294 ) ;
F_95 ( V_335 && ! F_326 ( V_24 ) ) ;
V_14 = F_327 ( V_20 , V_24 , V_335 ) ;
if ( ! V_14 ) {
V_14 = F_332 ( V_20 , V_24 , V_335 ) ;
F_95 ( V_14 != F_327 ( V_20 , V_24 , V_335 ) ) ;
}
F_95 ( F_333 ( V_14 ) ) ;
return V_14 ;
}
static struct V_343 *
F_334 ( const T_3 * V_344 , unsigned int V_267 ,
unsigned int V_345 , unsigned int V_346 ,
unsigned int V_347 ,
struct V_137 * V_268 , struct V_343 * V_348 )
{
unsigned int V_349 , V_350 ;
unsigned int V_351 ;
for ( V_349 = 0 ; V_349 < V_345 ; V_349 ++ ) {
V_351 = V_347 * ( V_346 - 1 ) + V_349 ;
for ( V_350 = 0 ; V_350 < V_346 ; V_350 ++ ) {
V_268 -> V_266 ++ ;
F_335 ( V_348 , NULL , V_67 , 0 ) ;
F_336 ( V_348 ) = V_344 [ V_267 + V_351 ] ;
F_337 ( V_348 ) = V_67 ;
V_348 = F_338 ( V_348 ) ;
V_351 -= V_347 ;
}
}
return V_348 ;
}
static struct V_137 *
F_339 ( const struct V_352 * V_353 ,
struct V_265 * V_20 )
{
const T_9 V_354 = V_20 -> V_110 . V_29 / V_67 ;
unsigned int V_29 = F_340 ( V_353 ) ;
struct V_225 V_225 ;
T_3 V_355 ;
unsigned long V_69 ;
T_3 * V_356 ;
struct V_137 * V_268 ;
struct V_343 * V_348 ;
int V_80 = - V_60 ;
V_356 = F_341 ( V_354 ,
sizeof( T_3 ) ,
V_162 ) ;
if ( ! V_356 )
return F_44 ( V_80 ) ;
V_268 = F_342 ( sizeof( * V_268 ) , V_81 ) ;
if ( ! V_268 )
goto V_357;
V_80 = F_343 ( V_268 , V_29 , V_81 ) ;
if ( V_80 )
goto V_358;
V_69 = 0 ;
F_176 (dma_addr, sgt_iter, obj->mm.pages)
V_356 [ V_69 ++ ] = V_355 ;
F_95 ( V_69 != V_354 ) ;
V_268 -> V_266 = 0 ;
V_348 = V_268 -> V_138 ;
for ( V_69 = 0 ; V_69 < F_344 ( V_353 -> V_359 ) ; V_69 ++ ) {
V_348 = F_334 ( V_356 , V_353 -> V_359 [ V_69 ] . V_267 ,
V_353 -> V_359 [ V_69 ] . V_345 , V_353 -> V_359 [ V_69 ] . V_346 ,
V_353 -> V_359 [ V_69 ] . V_347 , V_268 , V_348 ) ;
}
F_270 ( L_42 ,
V_20 -> V_110 . V_29 , V_353 -> V_359 [ 0 ] . V_345 , V_353 -> V_359 [ 0 ] . V_346 , V_29 ) ;
F_345 ( V_356 ) ;
return V_268 ;
V_358:
F_48 ( V_268 ) ;
V_357:
F_345 ( V_356 ) ;
F_270 ( L_43 ,
V_20 -> V_110 . V_29 , V_353 -> V_359 [ 0 ] . V_345 , V_353 -> V_359 [ 0 ] . V_346 , V_29 ) ;
return F_44 ( V_80 ) ;
}
static struct V_137 *
F_346 ( const struct V_334 * V_335 ,
struct V_265 * V_20 )
{
struct V_137 * V_268 ;
struct V_343 * V_348 , * V_360 ;
unsigned int V_77 = V_335 -> V_361 . V_362 . V_29 ;
unsigned int V_267 ;
int V_80 = - V_60 ;
V_268 = F_342 ( sizeof( * V_268 ) , V_81 ) ;
if ( ! V_268 )
goto V_357;
V_80 = F_343 ( V_268 , V_77 , V_81 ) ;
if ( V_80 )
goto V_358;
V_360 = F_347 ( V_20 ,
V_335 -> V_361 . V_362 . V_267 ,
& V_267 ) ;
F_95 ( ! V_360 ) ;
V_348 = V_268 -> V_138 ;
V_268 -> V_266 = 0 ;
do {
unsigned int V_363 ;
V_363 = F_258 ( V_360 -> V_123 - ( V_267 << V_140 ) ,
V_77 << V_140 ) ;
F_335 ( V_348 , NULL , V_363 , 0 ) ;
F_336 ( V_348 ) =
F_336 ( V_360 ) + ( V_267 << V_140 ) ;
F_337 ( V_348 ) = V_363 ;
V_268 -> V_266 ++ ;
V_77 -= V_363 >> V_140 ;
if ( V_77 == 0 ) {
F_348 ( V_348 ) ;
return V_268 ;
}
V_348 = F_349 ( V_348 ) ;
V_360 = F_349 ( V_360 ) ;
V_267 = 0 ;
} while ( 1 );
V_358:
F_48 ( V_268 ) ;
V_357:
return F_44 ( V_80 ) ;
}
static int
F_253 ( struct V_13 * V_14 )
{
int V_80 = 0 ;
F_95 ( ! F_350 ( V_14 -> V_20 ) ) ;
if ( V_14 -> V_19 )
return 0 ;
if ( V_14 -> V_364 . type == V_365 )
V_14 -> V_19 = V_14 -> V_20 -> V_21 . V_19 ;
else if ( V_14 -> V_364 . type == V_366 )
V_14 -> V_19 =
F_339 ( & V_14 -> V_364 . V_361 . V_367 , V_14 -> V_20 ) ;
else if ( V_14 -> V_364 . type == V_368 )
V_14 -> V_19 = F_346 ( & V_14 -> V_364 , V_14 -> V_20 ) ;
else
F_351 ( 1 , L_44 ,
V_14 -> V_364 . type ) ;
if ( ! V_14 -> V_19 ) {
F_262 ( L_45 ,
V_14 -> V_364 . type ) ;
V_80 = - V_63 ;
} else if ( F_117 ( V_14 -> V_19 ) ) {
V_80 = F_118 ( V_14 -> V_19 ) ;
V_14 -> V_19 = NULL ;
F_262 ( L_46 ,
V_14 -> V_364 . type , V_80 ) ;
}
return V_80 ;
}
