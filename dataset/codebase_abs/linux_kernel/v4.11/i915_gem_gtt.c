static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_2 ( V_5 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 () ;
}
static inline void F_6 ( struct V_1 * V_7 )
{
V_7 -> V_8 . V_9 ( V_7 ) ;
}
int F_7 ( struct V_1 * V_2 ,
int V_10 )
{
bool V_11 ;
bool V_12 ;
bool V_13 ;
V_11 = V_2 -> V_14 . V_11 ;
V_12 = V_2 -> V_14 . V_12 ;
V_13 = V_2 -> V_14 . V_13 ;
if ( F_8 ( V_2 ) ) {
V_12 = false ;
V_13 = false ;
}
if ( ! V_11 )
return 0 ;
if ( V_10 == 0 && F_9 ( V_2 ) < 9 )
return 0 ;
if ( V_10 == 1 )
return 1 ;
if ( V_10 == 2 && V_12 )
return 2 ;
if ( V_10 == 3 && V_13 )
return 3 ;
#ifdef F_10
if ( F_11 ( V_2 ) && V_15 ) {
F_12 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_13 ( V_2 ) && V_2 -> V_16 . V_17 -> V_18 < 0xb ) {
F_14 ( L_2 ) ;
return 0 ;
}
if ( F_9 ( V_2 ) >= 8 && V_7 . V_19 && V_12 )
return V_13 ? 3 : 2 ;
else
return V_11 ? 1 : 0 ;
}
static int F_15 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
T_1 V_24 )
{
T_1 V_25 = 0 ;
V_21 -> V_26 = V_21 -> V_27 -> V_28 . V_26 ;
if ( V_21 -> V_27 -> V_29 )
V_25 |= V_30 ;
V_21 -> V_31 -> V_32 ( V_21 -> V_31 , V_21 -> V_26 , V_21 -> V_33 . V_34 ,
V_23 , V_25 ) ;
return 0 ;
}
static void F_16 ( struct V_20 * V_21 )
{
V_21 -> V_31 -> V_35 ( V_21 -> V_31 ,
V_21 -> V_33 . V_34 ,
V_21 -> V_36 ) ;
}
static T_2 F_17 ( T_3 V_37 ,
enum V_22 V_38 )
{
T_2 V_39 = V_40 | V_41 ;
V_39 |= V_37 ;
switch ( V_38 ) {
case V_42 :
V_39 |= V_43 ;
break;
case V_44 :
V_39 |= V_45 ;
break;
default:
V_39 |= V_46 ;
break;
}
return V_39 ;
}
static T_4 F_18 ( const T_3 V_37 ,
const enum V_22 V_38 )
{
T_4 V_47 = V_40 | V_41 ;
V_47 |= V_37 ;
if ( V_38 != V_42 )
V_47 |= V_48 ;
else
V_47 |= V_43 ;
return V_47 ;
}
static T_5 F_19 ( T_3 V_37 ,
enum V_22 V_38 ,
T_1 V_24 )
{
T_5 V_39 = V_49 ;
V_39 |= F_20 ( V_37 ) ;
switch ( V_38 ) {
case V_50 :
case V_51 :
V_39 |= V_52 ;
break;
case V_42 :
V_39 |= V_53 ;
break;
default:
F_21 ( V_38 ) ;
}
return V_39 ;
}
static T_5 F_22 ( T_3 V_37 ,
enum V_22 V_38 ,
T_1 V_24 )
{
T_5 V_39 = V_49 ;
V_39 |= F_20 ( V_37 ) ;
switch ( V_38 ) {
case V_50 :
V_39 |= V_54 ;
break;
case V_51 :
V_39 |= V_52 ;
break;
case V_42 :
V_39 |= V_53 ;
break;
default:
F_21 ( V_38 ) ;
}
return V_39 ;
}
static T_5 F_23 ( T_3 V_37 ,
enum V_22 V_38 ,
T_1 V_55 )
{
T_5 V_39 = V_49 ;
V_39 |= F_20 ( V_37 ) ;
if ( ! ( V_55 & V_30 ) )
V_39 |= V_56 ;
if ( V_38 != V_42 )
V_39 |= V_57 ;
return V_39 ;
}
static T_5 F_24 ( T_3 V_37 ,
enum V_22 V_38 ,
T_1 V_24 )
{
T_5 V_39 = V_49 ;
V_39 |= F_25 ( V_37 ) ;
if ( V_38 != V_42 )
V_39 |= V_58 ;
return V_39 ;
}
static T_5 F_26 ( T_3 V_37 ,
enum V_22 V_38 ,
T_1 V_24 )
{
T_5 V_39 = V_49 ;
V_39 |= F_25 ( V_37 ) ;
switch ( V_38 ) {
case V_42 :
break;
case V_44 :
V_39 |= V_59 ;
break;
default:
V_39 |= V_60 ;
break;
}
return V_39 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_61 * V_62 , T_6 V_55 )
{
struct V_63 * V_64 = & V_2 -> V_16 . V_17 -> V_65 ;
V_62 -> V_66 = F_28 ( V_55 ) ;
if ( ! V_62 -> V_66 )
return - V_67 ;
V_62 -> V_68 = F_29 ( V_64 ,
V_62 -> V_66 , 0 , V_69 , V_70 ) ;
if ( F_30 ( V_64 , V_62 -> V_68 ) ) {
F_31 ( V_62 -> V_66 ) ;
return - V_71 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
return F_27 ( V_2 , V_62 , V_72 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_73 * V_17 = V_2 -> V_16 . V_17 ;
if ( F_34 ( ! V_62 -> V_66 ) )
return;
F_35 ( & V_17 -> V_65 , V_62 -> V_68 , V_69 , V_70 ) ;
F_31 ( V_62 -> V_66 ) ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
}
static void * F_36 ( struct V_61 * V_62 )
{
return F_37 ( V_62 -> V_66 ) ;
}
static void F_38 ( struct V_1 * V_2 , void * V_74 )
{
if ( F_39 ( V_2 ) || F_40 ( V_2 ) )
F_41 ( V_74 , V_69 ) ;
F_42 ( V_74 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_61 * V_62 , const T_7 V_75 )
{
int V_76 ;
T_7 * const V_74 = F_36 ( V_62 ) ;
for ( V_76 = 0 ; V_76 < 512 ; V_76 ++ )
V_74 [ V_76 ] = V_75 ;
F_38 ( V_2 , V_74 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_61 * V_62 , const T_8 V_77 )
{
T_7 V_78 = V_77 ;
V_78 = V_78 << 32 | V_77 ;
F_43 ( V_2 , V_62 , V_78 ) ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_61 * V_79 ,
T_6 V_80 )
{
return F_27 ( V_2 , V_79 , V_80 | V_81 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_61 * V_79 )
{
F_33 ( V_2 , V_79 ) ;
}
static struct V_82 * F_47 ( struct V_1 * V_2 )
{
struct V_82 * V_83 ;
const T_9 V_84 = F_9 ( V_2 ) >= 8 ? V_85 : V_86 ;
int V_87 = - V_67 ;
V_83 = F_48 ( sizeof( * V_83 ) , V_88 ) ;
if ( ! V_83 )
return F_49 ( - V_67 ) ;
V_83 -> V_89 = F_50 ( F_51 ( V_84 ) , sizeof( * V_83 -> V_89 ) ,
V_88 ) ;
if ( ! V_83 -> V_89 )
goto V_90;
V_87 = F_52 ( V_2 , V_83 ) ;
if ( V_87 )
goto V_91;
return V_83 ;
V_91:
F_53 ( V_83 -> V_89 ) ;
V_90:
F_53 ( V_83 ) ;
return F_49 ( V_87 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
F_55 ( V_2 , V_83 ) ;
F_53 ( V_83 -> V_89 ) ;
F_53 ( V_83 ) ;
}
static void F_56 ( struct V_92 * V_31 ,
struct V_82 * V_83 )
{
T_2 V_93 ;
V_93 = F_17 ( V_31 -> V_94 . V_68 ,
V_51 ) ;
F_57 ( V_31 -> V_7 , V_83 , V_93 ) ;
}
static void F_58 ( struct V_92 * V_31 ,
struct V_82 * V_83 )
{
T_5 V_93 ;
F_34 ( V_31 -> V_94 . V_68 == 0 ) ;
V_93 = V_31 -> V_95 ( V_31 -> V_94 . V_68 ,
V_51 , 0 ) ;
F_59 ( V_31 -> V_7 , V_83 , V_93 ) ;
}
static struct V_96 * F_60 ( struct V_1 * V_2 )
{
struct V_96 * V_97 ;
int V_87 = - V_67 ;
V_97 = F_48 ( sizeof( * V_97 ) , V_88 ) ;
if ( ! V_97 )
return F_49 ( - V_67 ) ;
V_97 -> V_98 = F_50 ( F_51 ( V_99 ) ,
sizeof( * V_97 -> V_98 ) , V_88 ) ;
if ( ! V_97 -> V_98 )
goto V_90;
V_87 = F_52 ( V_2 , V_97 ) ;
if ( V_87 )
goto V_91;
return V_97 ;
V_91:
F_53 ( V_97 -> V_98 ) ;
V_90:
F_53 ( V_97 ) ;
return F_49 ( V_87 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
if ( F_62 ( V_97 ) ) {
F_55 ( V_2 , V_97 ) ;
F_53 ( V_97 -> V_98 ) ;
F_53 ( V_97 ) ;
}
}
static void F_63 ( struct V_92 * V_31 ,
struct V_96 * V_97 )
{
T_4 V_100 ;
V_100 = F_18 ( F_64 ( V_31 -> V_101 ) , V_51 ) ;
F_57 ( V_31 -> V_7 , V_97 , V_100 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
T_9 V_104 = F_66 ( V_2 ) ;
V_103 -> V_105 = F_50 ( F_51 ( V_104 ) ,
sizeof( unsigned long ) ,
V_88 ) ;
if ( ! V_103 -> V_105 )
return - V_67 ;
V_103 -> V_106 = F_50 ( V_104 , sizeof( * V_103 -> V_106 ) ,
V_88 ) ;
if ( ! V_103 -> V_106 ) {
F_53 ( V_103 -> V_105 ) ;
V_103 -> V_105 = NULL ;
return - V_67 ;
}
return 0 ;
}
static void F_67 ( struct V_102 * V_103 )
{
F_53 ( V_103 -> V_105 ) ;
F_53 ( V_103 -> V_106 ) ;
V_103 -> V_106 = NULL ;
}
static struct
V_102 * F_68 ( struct V_1 * V_2 )
{
struct V_102 * V_103 ;
int V_87 = - V_67 ;
F_34 ( ! F_69 ( V_2 ) ) ;
V_103 = F_48 ( sizeof( * V_103 ) , V_88 ) ;
if ( ! V_103 )
return F_49 ( - V_67 ) ;
V_87 = F_65 ( V_2 , V_103 ) ;
if ( V_87 )
goto V_90;
V_87 = F_52 ( V_2 , V_103 ) ;
if ( V_87 )
goto V_91;
return V_103 ;
V_91:
F_67 ( V_103 ) ;
V_90:
F_53 ( V_103 ) ;
return F_49 ( V_87 ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
F_67 ( V_103 ) ;
if ( F_69 ( V_2 ) ) {
F_55 ( V_2 , V_103 ) ;
F_53 ( V_103 ) ;
}
}
static void F_71 ( struct V_92 * V_31 ,
struct V_102 * V_103 )
{
T_10 V_107 ;
V_107 = F_72 ( F_64 ( V_31 -> V_108 ) , V_51 ) ;
F_57 ( V_31 -> V_7 , V_103 , V_107 ) ;
}
static void F_73 ( struct V_92 * V_31 ,
struct V_109 * V_110 )
{
T_11 V_111 ;
V_111 = F_74 ( F_64 ( V_31 -> V_112 ) ,
V_51 ) ;
F_57 ( V_31 -> V_7 , V_110 , V_111 ) ;
}
static void
F_75 ( struct V_113 * V_114 ,
struct V_102 * V_103 ,
struct V_96 * V_97 ,
int V_115 )
{
T_10 * V_116 ;
if ( ! F_69 ( F_76 ( V_114 -> V_117 . V_65 ) ) )
return;
V_116 = F_77 ( V_103 ) ;
V_116 [ V_115 ] = F_72 ( F_64 ( V_97 ) , V_51 ) ;
F_78 ( V_114 , V_116 ) ;
}
static void
F_79 ( struct V_113 * V_114 ,
struct V_109 * V_110 ,
struct V_102 * V_103 ,
int V_115 )
{
T_11 * V_118 = F_77 ( V_110 ) ;
F_34 ( ! F_69 ( F_76 ( V_114 -> V_117 . V_65 ) ) ) ;
V_118 [ V_115 ] = F_74 ( F_64 ( V_103 ) , V_51 ) ;
F_78 ( V_114 , V_118 ) ;
}
static int F_80 ( struct V_119 * V_120 ,
unsigned V_121 ,
T_3 V_37 )
{
struct V_122 * V_123 = V_120 -> V_123 ;
struct V_124 * V_125 = V_120 -> V_125 ;
int V_87 ;
F_81 ( V_121 >= 4 ) ;
V_87 = F_82 ( V_120 , 6 ) ;
if ( V_87 )
return V_87 ;
F_83 ( V_123 , F_84 ( 1 ) ) ;
F_85 ( V_123 , F_86 ( V_125 , V_121 ) ) ;
F_83 ( V_123 , F_87 ( V_37 ) ) ;
F_83 ( V_123 , F_84 ( 1 ) ) ;
F_85 ( V_123 , F_88 ( V_125 , V_121 ) ) ;
F_83 ( V_123 , F_89 ( V_37 ) ) ;
F_90 ( V_123 ) ;
return 0 ;
}
static int F_91 ( struct V_113 * V_114 ,
struct V_119 * V_120 )
{
int V_76 , V_87 ;
for ( V_76 = V_126 - 1 ; V_76 >= 0 ; V_76 -- ) {
const T_3 V_127 = F_92 ( V_114 , V_76 ) ;
V_87 = F_80 ( V_120 , V_76 , V_127 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_93 ( struct V_113 * V_114 ,
struct V_119 * V_120 )
{
return F_80 ( V_120 , 0 , F_64 ( & V_114 -> V_110 ) ) ;
}
static void F_94 ( struct V_113 * V_114 )
{
V_114 -> V_128 = F_95 ( V_114 -> V_117 . V_7 ) -> V_129 ;
}
static bool F_96 ( struct V_92 * V_31 ,
struct V_82 * V_83 ,
T_7 V_34 ,
T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
unsigned int V_131 = F_98 ( V_34 , V_130 ) ;
unsigned int V_39 = F_99 ( V_34 ) ;
unsigned int V_132 = V_39 + V_131 ;
T_2 * V_133 ;
T_2 V_93 = F_17 ( V_31 -> V_94 . V_68 ,
V_51 ) ;
if ( F_34 ( ! F_62 ( V_83 ) ) )
return false ;
F_100 ( V_132 > V_85 ) ;
F_101 ( V_83 -> V_89 , V_39 , V_131 ) ;
if ( F_102 ( V_31 -> V_7 ) ) {
if ( F_103 ( V_83 -> V_89 , V_85 ) )
return true ;
}
V_133 = F_77 ( V_83 ) ;
while ( V_39 < V_132 )
V_133 [ V_39 ++ ] = V_93 ;
F_78 ( V_114 , V_133 ) ;
return false ;
}
static bool F_104 ( struct V_92 * V_31 ,
struct V_96 * V_97 ,
T_7 V_34 ,
T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
struct V_82 * V_83 ;
T_7 V_47 ;
T_4 * V_134 ;
T_4 V_100 = F_18 ( F_64 ( V_31 -> V_101 ) ,
V_51 ) ;
F_105 (pt, pd, start, length, pde) {
if ( F_34 ( ! V_97 -> V_135 [ V_47 ] ) )
break;
if ( F_96 ( V_31 , V_83 , V_34 , V_130 ) ) {
F_106 ( V_47 , V_97 -> V_98 ) ;
V_134 = F_77 ( V_97 ) ;
V_134 [ V_47 ] = V_100 ;
F_78 ( V_114 , V_134 ) ;
F_54 ( V_31 -> V_7 , V_83 ) ;
}
}
if ( F_103 ( V_97 -> V_98 , V_99 ) )
return true ;
return false ;
}
static bool F_107 ( struct V_92 * V_31 ,
struct V_102 * V_103 ,
T_7 V_34 ,
T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
struct V_96 * V_97 ;
T_7 V_136 ;
F_108 (pd, pdp, start, length, pdpe) {
if ( F_34 ( ! V_103 -> V_106 [ V_136 ] ) )
break;
if ( F_104 ( V_31 , V_97 , V_34 , V_130 ) ) {
F_106 ( V_136 , V_103 -> V_105 ) ;
F_75 ( V_114 , V_103 , V_31 -> V_108 , V_136 ) ;
F_61 ( V_31 -> V_7 , V_97 ) ;
}
}
F_94 ( V_114 ) ;
if ( F_103 ( V_103 -> V_105 , F_66 ( V_2 ) ) )
return true ;
return false ;
}
static void F_109 ( struct V_92 * V_31 ,
struct V_109 * V_110 ,
T_7 V_34 ,
T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
struct V_102 * V_103 ;
T_7 V_137 ;
F_100 ( ! F_69 ( V_31 -> V_7 ) ) ;
F_110 (pdp, pml4, start, length, pml4e) {
if ( F_34 ( ! V_110 -> V_138 [ V_137 ] ) )
break;
if ( F_107 ( V_31 , V_103 , V_34 , V_130 ) ) {
F_106 ( V_137 , V_110 -> V_139 ) ;
F_79 ( V_114 , V_110 , V_31 -> V_112 , V_137 ) ;
F_70 ( V_31 -> V_7 , V_103 ) ;
}
}
}
static void F_111 ( struct V_92 * V_31 ,
T_7 V_34 , T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
if ( F_69 ( V_31 -> V_7 ) )
F_109 ( V_31 , & V_114 -> V_110 , V_34 , V_130 ) ;
else
F_107 ( V_31 , & V_114 -> V_103 , V_34 , V_130 ) ;
}
static void
F_112 ( struct V_92 * V_31 ,
struct V_102 * V_103 ,
struct V_140 * V_141 ,
T_7 V_34 ,
enum V_22 V_23 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
T_2 * V_133 ;
unsigned V_136 = F_113 ( V_34 ) ;
unsigned V_47 = F_114 ( V_34 ) ;
unsigned V_39 = F_99 ( V_34 ) ;
V_133 = NULL ;
while ( F_115 ( V_141 ) ) {
if ( V_133 == NULL ) {
struct V_96 * V_97 = V_103 -> V_106 [ V_136 ] ;
struct V_82 * V_83 = V_97 -> V_135 [ V_47 ] ;
V_133 = F_77 ( V_83 ) ;
}
V_133 [ V_39 ] =
F_17 ( F_116 ( V_141 ) ,
V_23 ) ;
if ( ++ V_39 == V_85 ) {
F_78 ( V_114 , V_133 ) ;
V_133 = NULL ;
if ( ++ V_47 == V_99 ) {
if ( ++ V_136 == F_66 ( V_31 -> V_7 ) )
break;
V_47 = 0 ;
}
V_39 = 0 ;
}
}
if ( V_133 )
F_78 ( V_114 , V_133 ) ;
}
static void F_117 ( struct V_92 * V_31 ,
struct V_142 * V_26 ,
T_7 V_34 ,
enum V_22 V_23 ,
T_1 V_24 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
struct V_140 V_141 ;
F_118 ( & V_141 , V_26 -> V_143 , F_119 ( V_26 -> V_143 ) , 0 ) ;
if ( ! F_69 ( V_31 -> V_7 ) ) {
F_112 ( V_31 , & V_114 -> V_103 , & V_141 , V_34 ,
V_23 ) ;
} else {
struct V_102 * V_103 ;
T_7 V_137 ;
T_7 V_130 = ( T_7 ) V_26 -> V_144 << V_145 ;
F_110 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_112 ( V_31 , V_103 , & V_141 ,
V_34 , V_23 ) ;
}
}
}
static void F_120 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
int V_76 ;
if ( ! F_62 ( V_97 ) )
return;
F_121 (i, pd->used_pdes, I915_PDES) {
if ( F_34 ( ! V_97 -> V_135 [ V_76 ] ) )
continue;
F_54 ( V_2 , V_97 -> V_135 [ V_76 ] ) ;
V_97 -> V_135 [ V_76 ] = NULL ;
}
}
static int F_122 ( struct V_92 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
int V_87 ;
V_87 = F_45 ( V_2 , & V_31 -> V_94 , V_72 ) ;
if ( V_87 )
return V_87 ;
V_31 -> V_101 = F_47 ( V_2 ) ;
if ( F_123 ( V_31 -> V_101 ) ) {
V_87 = F_124 ( V_31 -> V_101 ) ;
goto V_146;
}
V_31 -> V_108 = F_60 ( V_2 ) ;
if ( F_123 ( V_31 -> V_108 ) ) {
V_87 = F_124 ( V_31 -> V_108 ) ;
goto F_54;
}
if ( F_69 ( V_2 ) ) {
V_31 -> V_112 = F_68 ( V_2 ) ;
if ( F_123 ( V_31 -> V_112 ) ) {
V_87 = F_124 ( V_31 -> V_112 ) ;
goto F_61;
}
}
F_56 ( V_31 , V_31 -> V_101 ) ;
F_63 ( V_31 , V_31 -> V_108 ) ;
if ( F_69 ( V_2 ) )
F_71 ( V_31 , V_31 -> V_112 ) ;
return 0 ;
F_61:
F_61 ( V_2 , V_31 -> V_108 ) ;
F_54:
F_54 ( V_2 , V_31 -> V_101 ) ;
V_146:
F_46 ( V_2 , & V_31 -> V_94 ) ;
return V_87 ;
}
static int F_125 ( struct V_113 * V_114 , bool V_147 )
{
enum V_148 V_149 ;
struct V_1 * V_2 = V_114 -> V_117 . V_7 ;
int V_76 ;
if ( F_69 ( V_2 ) ) {
T_12 V_68 = F_64 ( & V_114 -> V_110 ) ;
F_2 ( F_126 ( V_103 [ 0 ] . V_150 ) , F_89 ( V_68 ) ) ;
F_2 ( F_126 ( V_103 [ 0 ] . V_151 ) , F_87 ( V_68 ) ) ;
V_149 = ( V_147 ? V_152 :
V_153 ) ;
} else {
for ( V_76 = 0 ; V_76 < V_126 ; V_76 ++ ) {
T_12 V_68 = F_92 ( V_114 , V_76 ) ;
F_2 ( F_126 ( V_103 [ V_76 ] . V_150 ) , F_89 ( V_68 ) ) ;
F_2 ( F_126 ( V_103 [ V_76 ] . V_151 ) , F_87 ( V_68 ) ) ;
}
V_149 = ( V_147 ? V_154 :
V_155 ) ;
}
F_2 ( F_126 ( V_156 ) , V_149 ) ;
return 0 ;
}
static void F_127 ( struct V_92 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
if ( F_69 ( V_2 ) )
F_70 ( V_2 , V_31 -> V_112 ) ;
F_61 ( V_2 , V_31 -> V_108 ) ;
F_54 ( V_2 , V_31 -> V_101 ) ;
F_46 ( V_2 , & V_31 -> V_94 ) ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
int V_76 ;
F_121 (i, pdp->used_pdpes, I915_PDPES_PER_PDP(dev_priv)) {
if ( F_34 ( ! V_103 -> V_106 [ V_76 ] ) )
continue;
F_120 ( V_2 , V_103 -> V_106 [ V_76 ] ) ;
F_61 ( V_2 , V_103 -> V_106 [ V_76 ] ) ;
}
F_70 ( V_2 , V_103 ) ;
}
static void F_129 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_117 . V_7 ;
int V_76 ;
F_121 (i, ppgtt->pml4.used_pml4es, GEN8_PML4ES_PER_PML4) {
if ( F_34 ( ! V_114 -> V_110 . V_138 [ V_76 ] ) )
continue;
F_128 ( V_2 , V_114 -> V_110 . V_138 [ V_76 ] ) ;
}
F_55 ( V_2 , & V_114 -> V_110 ) ;
}
static void F_130 ( struct V_92 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
struct V_113 * V_114 = F_97 ( V_31 ) ;
if ( F_8 ( V_2 ) )
F_125 ( V_114 , false ) ;
if ( ! F_69 ( V_2 ) )
F_128 ( V_2 , & V_114 -> V_103 ) ;
else
F_129 ( V_114 ) ;
F_127 ( V_31 ) ;
}
static int F_131 ( struct V_92 * V_31 ,
struct V_96 * V_97 ,
T_7 V_34 ,
T_7 V_130 ,
unsigned long * V_157 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
struct V_82 * V_83 ;
T_8 V_47 ;
F_105 (pt, pd, start, length, pde) {
if ( F_132 ( V_47 , V_97 -> V_98 ) ) {
F_34 ( V_83 == V_31 -> V_101 ) ;
continue;
}
V_83 = F_47 ( V_2 ) ;
if ( F_123 ( V_83 ) )
goto V_158;
F_56 ( V_31 , V_83 ) ;
V_97 -> V_135 [ V_47 ] = V_83 ;
F_133 ( V_47 , V_157 ) ;
F_134 ( V_31 , V_47 , V_34 , V_159 ) ;
}
return 0 ;
V_158:
F_121 (pde, new_pts, I915_PDES)
F_54 ( V_2 , V_97 -> V_135 [ V_47 ] ) ;
return - V_67 ;
}
static int
F_135 ( struct V_92 * V_31 ,
struct V_102 * V_103 ,
T_7 V_34 ,
T_7 V_130 ,
unsigned long * V_160 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
struct V_96 * V_97 ;
T_8 V_136 ;
T_8 V_104 = F_66 ( V_2 ) ;
F_34 ( ! F_103 ( V_160 , V_104 ) ) ;
F_108 (pd, pdp, start, length, pdpe) {
if ( F_132 ( V_136 , V_103 -> V_105 ) )
continue;
V_97 = F_60 ( V_2 ) ;
if ( F_123 ( V_97 ) )
goto V_158;
F_63 ( V_31 , V_97 ) ;
V_103 -> V_106 [ V_136 ] = V_97 ;
F_133 ( V_136 , V_160 ) ;
F_136 ( V_31 , V_136 , V_34 , V_161 ) ;
}
return 0 ;
V_158:
F_121 (pdpe, new_pds, pdpes)
F_61 ( V_2 , V_103 -> V_106 [ V_136 ] ) ;
return - V_67 ;
}
static int
F_137 ( struct V_92 * V_31 ,
struct V_109 * V_110 ,
T_7 V_34 ,
T_7 V_130 ,
unsigned long * V_162 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
struct V_102 * V_103 ;
T_8 V_137 ;
F_34 ( ! F_103 ( V_162 , V_163 ) ) ;
F_110 (pdp, pml4, start, length, pml4e) {
if ( ! F_132 ( V_137 , V_110 -> V_139 ) ) {
V_103 = F_68 ( V_2 ) ;
if ( F_123 ( V_103 ) )
goto V_158;
F_71 ( V_31 , V_103 ) ;
V_110 -> V_138 [ V_137 ] = V_103 ;
F_133 ( V_137 , V_162 ) ;
F_138 ( V_31 ,
V_137 ,
V_34 ,
V_164 ) ;
}
}
return 0 ;
V_158:
F_121 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_70 ( V_2 , V_110 -> V_138 [ V_137 ] ) ;
return - V_67 ;
}
static void
F_139 ( unsigned long * V_160 , unsigned long * V_157 )
{
F_53 ( V_157 ) ;
F_53 ( V_160 ) ;
}
static
int T_13 F_140 ( unsigned long * * V_160 ,
unsigned long * * V_157 ,
T_8 V_104 )
{
unsigned long * V_165 ;
unsigned long * V_166 ;
V_165 = F_50 ( F_51 ( V_104 ) , sizeof( unsigned long ) , V_167 ) ;
if ( ! V_165 )
return - V_67 ;
V_166 = F_50 ( V_104 , F_51 ( V_99 ) * sizeof( unsigned long ) ,
V_167 ) ;
if ( ! V_166 )
goto V_168;
* V_160 = V_165 ;
* V_157 = V_166 ;
return 0 ;
V_168:
F_139 ( V_165 , V_166 ) ;
return - V_67 ;
}
static int F_141 ( struct V_92 * V_31 ,
struct V_102 * V_103 ,
T_7 V_34 ,
T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
unsigned long * V_169 , * V_170 ;
struct V_1 * V_2 = V_31 -> V_7 ;
struct V_96 * V_97 ;
const T_7 V_171 = V_34 ;
const T_7 V_172 = V_130 ;
T_8 V_136 ;
T_8 V_104 = F_66 ( V_2 ) ;
int V_87 ;
V_87 = F_140 ( & V_169 , & V_170 , V_104 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_135 ( V_31 , V_103 , V_34 , V_130 ,
V_169 ) ;
if ( V_87 ) {
F_139 ( V_169 , V_170 ) ;
return V_87 ;
}
F_108 (pd, pdp, start, length, pdpe) {
V_87 = F_131 ( V_31 , V_97 , V_34 , V_130 ,
V_170 + V_136 * F_51 ( V_99 ) ) ;
if ( V_87 )
goto V_168;
}
V_34 = V_171 ;
V_130 = V_172 ;
F_108 (pd, pdp, start, length, pdpe) {
T_4 * const V_106 = F_77 ( V_97 ) ;
struct V_82 * V_83 ;
T_7 V_173 = V_130 ;
T_7 V_174 = V_34 ;
T_8 V_47 ;
F_34 ( ! V_97 ) ;
F_105 (pt, pd, pd_start, pd_len, pde) {
F_34 ( ! V_83 ) ;
F_34 ( ! V_173 ) ;
F_34 ( ! F_98 ( V_174 , V_173 ) ) ;
F_142 ( V_83 -> V_89 ,
F_99 ( V_174 ) ,
F_98 ( V_174 , V_173 ) ) ;
F_133 ( V_47 , V_97 -> V_98 ) ;
V_106 [ V_47 ] = F_18 ( F_64 ( V_83 ) ,
V_51 ) ;
F_143 ( & V_114 -> V_117 , V_47 , V_83 ,
F_99 ( V_34 ) ,
F_98 ( V_34 , V_130 ) ,
V_85 ) ;
}
F_78 ( V_114 , V_106 ) ;
F_133 ( V_136 , V_103 -> V_105 ) ;
F_75 ( V_114 , V_103 , V_97 , V_136 ) ;
}
F_139 ( V_169 , V_170 ) ;
F_94 ( V_114 ) ;
return 0 ;
V_168:
while ( V_136 -- ) {
unsigned long V_175 ;
F_121 (temp, new_page_tables + pdpe *
BITS_TO_LONGS(I915_PDES), I915_PDES)
F_54 ( V_2 ,
V_103 -> V_106 [ V_136 ] -> V_135 [ V_175 ] ) ;
}
F_121 (pdpe, new_page_dirs, pdpes)
F_61 ( V_2 , V_103 -> V_106 [ V_136 ] ) ;
F_139 ( V_169 , V_170 ) ;
F_94 ( V_114 ) ;
return V_87 ;
}
static int F_144 ( struct V_92 * V_31 ,
struct V_109 * V_110 ,
T_7 V_34 ,
T_7 V_130 )
{
F_145 ( V_162 , V_163 ) ;
struct V_113 * V_114 = F_97 ( V_31 ) ;
struct V_102 * V_103 ;
T_7 V_137 ;
int V_87 = 0 ;
F_146 ( V_162 , V_163 ) ;
V_87 = F_137 ( V_31 , V_110 , V_34 , V_130 ,
V_162 ) ;
if ( V_87 )
return V_87 ;
F_147 ( F_148 ( V_162 , V_163 ) > 2 ,
L_3
L_4 ) ;
F_110 (pdp, pml4, start, length, pml4e) {
F_34 ( ! V_103 ) ;
V_87 = F_141 ( V_31 , V_103 , V_34 , V_130 ) ;
if ( V_87 )
goto V_168;
F_79 ( V_114 , V_110 , V_103 , V_137 ) ;
}
F_149 ( V_110 -> V_139 , V_162 , V_110 -> V_139 ,
V_163 ) ;
return 0 ;
V_168:
F_121 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_128 ( V_31 -> V_7 , V_110 -> V_138 [ V_137 ] ) ;
return V_87 ;
}
static int F_150 ( struct V_92 * V_31 ,
T_7 V_34 , T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
if ( F_69 ( V_31 -> V_7 ) )
return F_144 ( V_31 , & V_114 -> V_110 , V_34 , V_130 ) ;
else
return F_141 ( V_31 , & V_114 -> V_103 , V_34 , V_130 ) ;
}
static void F_151 ( struct V_102 * V_103 ,
T_7 V_34 , T_7 V_130 ,
T_2 V_93 ,
struct V_176 * V_177 )
{
struct V_96 * V_97 ;
T_8 V_136 ;
F_108 (pd, pdp, start, length, pdpe) {
struct V_82 * V_83 ;
T_7 V_173 = V_130 ;
T_7 V_174 = V_34 ;
T_8 V_47 ;
if ( ! F_132 ( V_136 , V_103 -> V_105 ) )
continue;
F_152 ( V_177 , L_5 , V_136 ) ;
F_105 (pt, pd, pd_start, pd_len, pde) {
T_8 V_39 ;
T_2 * V_133 ;
if ( ! F_132 ( V_47 , V_97 -> V_98 ) )
continue;
V_133 = F_77 ( V_83 ) ;
for ( V_39 = 0 ; V_39 < V_85 ; V_39 += 4 ) {
T_7 V_178 =
( V_136 << V_161 ) |
( V_47 << V_159 ) |
( V_39 << V_179 ) ;
int V_76 ;
bool V_180 = false ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ )
if ( V_133 [ V_39 + V_76 ] != V_93 )
V_180 = true ;
if ( ! V_180 )
continue;
F_152 ( V_177 , L_6 , V_178 , V_136 , V_47 , V_39 ) ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
if ( V_133 [ V_39 + V_76 ] != V_93 )
F_152 ( V_177 , L_7 , V_133 [ V_39 + V_76 ] ) ;
else
F_153 ( V_177 , L_8 ) ;
}
F_153 ( V_177 , L_9 ) ;
}
F_42 ( V_133 ) ;
}
}
}
static void F_154 ( struct V_113 * V_114 , struct V_176 * V_177 )
{
struct V_92 * V_31 = & V_114 -> V_117 ;
T_7 V_34 = V_114 -> V_117 . V_34 ;
T_7 V_130 = V_114 -> V_117 . V_181 ;
T_2 V_93 = F_17 ( V_31 -> V_94 . V_68 ,
V_51 ) ;
if ( ! F_69 ( V_31 -> V_7 ) ) {
F_151 ( & V_114 -> V_103 , V_34 , V_130 , V_93 , V_177 ) ;
} else {
T_7 V_137 ;
struct V_109 * V_110 = & V_114 -> V_110 ;
struct V_102 * V_103 ;
F_110 (pdp, pml4, start, length, pml4e) {
if ( ! F_132 ( V_137 , V_110 -> V_139 ) )
continue;
F_152 ( V_177 , L_10 , V_137 ) ;
F_151 ( V_103 , V_34 , V_130 , V_93 , V_177 ) ;
}
}
}
static int F_155 ( struct V_113 * V_114 )
{
unsigned long * V_169 , * V_170 ;
T_8 V_104 = F_66 ( F_76 ( V_114 -> V_117 . V_65 ) ) ;
int V_87 ;
V_87 = F_140 ( & V_169 , & V_170 , V_104 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_135 ( & V_114 -> V_117 , & V_114 -> V_103 ,
0 , 1ULL << 32 ,
V_169 ) ;
if ( ! V_87 )
* V_114 -> V_103 . V_105 = * V_169 ;
F_139 ( V_169 , V_170 ) ;
return V_87 ;
}
static int F_156 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_117 . V_7 ;
int V_87 ;
V_87 = F_122 ( & V_114 -> V_117 ) ;
if ( V_87 )
return V_87 ;
V_114 -> V_117 . V_34 = 0 ;
V_114 -> V_117 . V_182 = F_130 ;
V_114 -> V_117 . V_183 = F_150 ;
V_114 -> V_117 . V_32 = F_117 ;
V_114 -> V_117 . V_35 = F_111 ;
V_114 -> V_117 . V_184 = F_16 ;
V_114 -> V_117 . V_185 = F_15 ;
V_114 -> V_186 = F_154 ;
if ( F_69 ( V_2 ) ) {
V_87 = F_52 ( V_2 , & V_114 -> V_110 ) ;
if ( V_87 )
goto V_187;
F_73 ( & V_114 -> V_117 , & V_114 -> V_110 ) ;
V_114 -> V_117 . V_181 = 1ULL << 48 ;
V_114 -> V_188 = F_93 ;
} else {
V_87 = F_65 ( V_2 , & V_114 -> V_103 ) ;
if ( V_87 )
goto V_187;
V_114 -> V_117 . V_181 = 1ULL << 32 ;
V_114 -> V_188 = F_91 ;
F_138 ( & V_114 -> V_117 ,
0 , 0 ,
V_164 ) ;
if ( F_8 ( V_2 ) ) {
V_87 = F_155 ( V_114 ) ;
if ( V_87 )
goto V_187;
}
}
if ( F_8 ( V_2 ) )
F_125 ( V_114 , true ) ;
return 0 ;
V_187:
F_127 ( & V_114 -> V_117 ) ;
return V_87 ;
}
static void F_157 ( struct V_113 * V_114 , struct V_176 * V_177 )
{
struct V_92 * V_31 = & V_114 -> V_117 ;
struct V_82 * V_24 ;
T_5 V_93 ;
T_8 V_189 ;
T_8 V_39 , V_47 ;
T_8 V_34 = V_114 -> V_117 . V_34 , V_130 = V_114 -> V_117 . V_181 ;
V_93 = V_31 -> V_95 ( V_31 -> V_94 . V_68 ,
V_51 , 0 ) ;
F_158 (unused, &ppgtt->pd, start, length, pde) {
T_1 V_190 ;
T_5 * V_133 ;
const T_3 V_191 = F_64 ( V_114 -> V_97 . V_135 [ V_47 ] ) ;
V_189 = F_159 ( V_114 -> V_192 + V_47 ) ;
V_190 = ( F_160 ( V_191 ) | V_193 ) ;
if ( V_189 != V_190 )
F_152 ( V_177 , L_11 ,
V_47 ,
V_189 ,
V_190 ) ;
F_152 ( V_177 , L_12 , V_189 ) ;
V_133 = F_77 ( V_114 -> V_97 . V_135 [ V_47 ] ) ;
for ( V_39 = 0 ; V_39 < V_86 ; V_39 += 4 ) {
unsigned long V_178 =
( V_47 * V_69 * V_86 ) +
( V_39 * V_69 ) ;
int V_76 ;
bool V_180 = false ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ )
if ( V_133 [ V_39 + V_76 ] != V_93 )
V_180 = true ;
if ( ! V_180 )
continue;
F_152 ( V_177 , L_13 , V_178 , V_47 , V_39 ) ;
for ( V_76 = 0 ; V_76 < 4 ; V_76 ++ ) {
if ( V_133 [ V_39 + V_76 ] != V_93 )
F_152 ( V_177 , L_14 , V_133 [ V_39 + V_76 ] ) ;
else
F_153 ( V_177 , L_8 ) ;
}
F_153 ( V_177 , L_9 ) ;
}
F_78 ( V_114 , V_133 ) ;
}
}
static void F_161 ( struct V_96 * V_97 ,
const int V_47 , struct V_82 * V_83 )
{
struct V_113 * V_114 =
F_162 ( V_97 , struct V_113 , V_97 ) ;
T_1 V_189 ;
V_189 = F_160 ( F_64 ( V_83 ) ) ;
V_189 |= V_193 ;
F_163 ( V_189 , V_114 -> V_192 + V_47 ) ;
}
static void F_164 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
T_8 V_34 , T_8 V_130 )
{
struct V_194 * V_8 = & V_2 -> V_8 ;
struct V_82 * V_83 ;
T_8 V_47 ;
F_158 (pt, pd, start, length, pde)
F_161 ( V_97 , V_47 , V_83 ) ;
F_159 ( V_8 -> V_195 ) ;
}
static T_8 F_165 ( struct V_113 * V_114 )
{
F_81 ( V_114 -> V_97 . V_117 . V_196 & 0x3f ) ;
return ( V_114 -> V_97 . V_117 . V_196 / 64 ) << 16 ;
}
static int F_166 ( struct V_113 * V_114 ,
struct V_119 * V_120 )
{
struct V_122 * V_123 = V_120 -> V_123 ;
struct V_124 * V_125 = V_120 -> V_125 ;
int V_87 ;
V_87 = V_125 -> V_197 ( V_120 , V_198 | V_199 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_82 ( V_120 , 6 ) ;
if ( V_87 )
return V_87 ;
F_83 ( V_123 , F_84 ( 2 ) ) ;
F_85 ( V_123 , F_167 ( V_125 ) ) ;
F_83 ( V_123 , V_200 ) ;
F_85 ( V_123 , F_168 ( V_125 ) ) ;
F_83 ( V_123 , F_165 ( V_114 ) ) ;
F_83 ( V_123 , V_201 ) ;
F_90 ( V_123 ) ;
return 0 ;
}
static int F_169 ( struct V_113 * V_114 ,
struct V_119 * V_120 )
{
struct V_122 * V_123 = V_120 -> V_123 ;
struct V_124 * V_125 = V_120 -> V_125 ;
int V_87 ;
V_87 = V_125 -> V_197 ( V_120 , V_198 | V_199 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_82 ( V_120 , 6 ) ;
if ( V_87 )
return V_87 ;
F_83 ( V_123 , F_84 ( 2 ) ) ;
F_85 ( V_123 , F_167 ( V_125 ) ) ;
F_83 ( V_123 , V_200 ) ;
F_85 ( V_123 , F_168 ( V_125 ) ) ;
F_83 ( V_123 , F_165 ( V_114 ) ) ;
F_83 ( V_123 , V_201 ) ;
F_90 ( V_123 ) ;
if ( V_125 -> V_202 != V_203 ) {
V_87 = V_125 -> V_197 ( V_120 , V_198 | V_199 ) ;
if ( V_87 )
return V_87 ;
}
return 0 ;
}
static int F_170 ( struct V_113 * V_114 ,
struct V_119 * V_120 )
{
struct V_124 * V_125 = V_120 -> V_125 ;
struct V_1 * V_2 = V_120 -> V_7 ;
F_2 ( F_167 ( V_125 ) , V_200 ) ;
F_2 ( F_168 ( V_125 ) , F_165 ( V_114 ) ) ;
return 0 ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_124 * V_125 ;
enum V_204 V_202 ;
F_172 (engine, dev_priv, id) {
T_1 V_205 = F_69 ( V_2 ) ?
V_206 : 0 ;
F_2 ( F_173 ( V_125 ) ,
F_174 ( V_207 | V_205 ) ) ;
}
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_124 * V_125 ;
T_8 V_208 , V_209 ;
enum V_204 V_202 ;
V_209 = F_176 ( V_210 ) ;
F_2 ( V_210 , V_209 | V_211 ) ;
V_208 = F_176 ( V_212 ) ;
if ( F_177 ( V_2 ) ) {
V_208 |= V_213 ;
} else {
V_208 |= V_214 ;
V_208 &= ~ V_215 ;
}
F_2 ( V_212 , V_208 ) ;
F_172 (engine, dev_priv, id) {
F_2 ( F_173 ( V_125 ) ,
F_174 ( V_207 ) ) ;
}
}
static void F_178 ( struct V_1 * V_2 )
{
T_8 V_208 , V_216 , V_209 ;
V_209 = F_176 ( V_210 ) ;
F_2 ( V_210 , V_209 | V_217 |
V_211 ) ;
V_216 = F_176 ( V_218 ) ;
F_2 ( V_218 , V_216 | V_219 ) ;
V_208 = F_176 ( V_212 ) ;
F_2 ( V_212 , V_208 | V_220 | V_221 ) ;
F_2 ( V_222 , F_174 ( V_207 ) ) ;
}
static void F_179 ( struct V_92 * V_31 ,
T_7 V_34 ,
T_7 V_130 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
T_5 * V_133 , V_93 ;
unsigned V_223 = V_34 >> V_145 ;
unsigned V_131 = V_130 >> V_145 ;
unsigned V_224 = V_223 / V_86 ;
unsigned V_225 = V_223 % V_86 ;
unsigned V_226 , V_76 ;
V_93 = V_31 -> V_95 ( V_31 -> V_94 . V_68 ,
V_51 , 0 ) ;
while ( V_131 ) {
V_226 = V_225 + V_131 ;
if ( V_226 > V_86 )
V_226 = V_86 ;
V_133 = F_77 ( V_114 -> V_97 . V_135 [ V_224 ] ) ;
for ( V_76 = V_225 ; V_76 < V_226 ; V_76 ++ )
V_133 [ V_76 ] = V_93 ;
F_78 ( V_114 , V_133 ) ;
V_131 -= V_226 - V_225 ;
V_225 = 0 ;
V_224 ++ ;
}
}
static void F_180 ( struct V_92 * V_31 ,
struct V_142 * V_26 ,
T_7 V_34 ,
enum V_22 V_23 , T_1 V_55 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
unsigned V_223 = V_34 >> V_145 ;
unsigned V_224 = V_223 / V_86 ;
unsigned V_227 = V_223 % V_86 ;
T_5 * V_133 = NULL ;
struct V_228 V_228 ;
T_3 V_37 ;
F_181 (addr, sgt_iter, pages) {
if ( V_133 == NULL )
V_133 = F_77 ( V_114 -> V_97 . V_135 [ V_224 ] ) ;
V_133 [ V_227 ] =
V_31 -> V_95 ( V_37 , V_23 , V_55 ) ;
if ( ++ V_227 == V_86 ) {
F_78 ( V_114 , V_133 ) ;
V_133 = NULL ;
V_224 ++ ;
V_227 = 0 ;
}
}
if ( V_133 )
F_78 ( V_114 , V_133 ) ;
}
static int F_182 ( struct V_92 * V_31 ,
T_7 V_229 , T_7 V_230 )
{
F_145 ( V_170 , V_99 ) ;
struct V_1 * V_2 = V_31 -> V_7 ;
struct V_194 * V_8 = & V_2 -> V_8 ;
struct V_113 * V_114 = F_97 ( V_31 ) ;
struct V_82 * V_83 ;
T_8 V_34 , V_130 , V_231 , V_232 ;
T_8 V_47 ;
int V_87 ;
V_34 = V_231 = V_229 ;
V_130 = V_232 = V_230 ;
F_146 ( V_170 , V_99 ) ;
F_158 (pt, &ppgtt->pd, start, length, pde) {
if ( V_83 != V_31 -> V_101 ) {
F_34 ( F_103 ( V_83 -> V_89 , V_86 ) ) ;
continue;
}
F_34 ( ! F_103 ( V_83 -> V_89 , V_86 ) ) ;
V_83 = F_47 ( V_2 ) ;
if ( F_123 ( V_83 ) ) {
V_87 = F_124 ( V_83 ) ;
goto V_158;
}
F_58 ( V_31 , V_83 ) ;
V_114 -> V_97 . V_135 [ V_47 ] = V_83 ;
F_133 ( V_47 , V_170 ) ;
F_134 ( V_31 , V_47 , V_34 , V_233 ) ;
}
V_34 = V_231 ;
V_130 = V_232 ;
F_158 (pt, &ppgtt->pd, start, length, pde) {
F_145 ( V_234 , V_86 ) ;
F_146 ( V_234 , V_86 ) ;
F_142 ( V_234 , F_183 ( V_34 ) ,
F_184 ( V_34 , V_130 ) ) ;
if ( F_185 ( V_47 , V_170 ) )
F_161 ( & V_114 -> V_97 , V_47 , V_83 ) ;
F_143 ( V_31 , V_47 , V_83 ,
F_183 ( V_34 ) ,
F_184 ( V_34 , V_130 ) ,
V_86 ) ;
F_149 ( V_83 -> V_89 , V_234 , V_83 -> V_89 ,
V_86 ) ;
}
F_34 ( ! F_103 ( V_170 , V_99 ) ) ;
F_159 ( V_8 -> V_195 ) ;
F_94 ( V_114 ) ;
return 0 ;
V_158:
F_121 (pde, new_page_tables, I915_PDES) {
struct V_82 * V_83 = V_114 -> V_97 . V_135 [ V_47 ] ;
V_114 -> V_97 . V_135 [ V_47 ] = V_31 -> V_101 ;
F_54 ( V_2 , V_83 ) ;
}
F_94 ( V_114 ) ;
return V_87 ;
}
static int F_186 ( struct V_92 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
int V_87 ;
V_87 = F_45 ( V_2 , & V_31 -> V_94 , V_72 ) ;
if ( V_87 )
return V_87 ;
V_31 -> V_101 = F_47 ( V_2 ) ;
if ( F_123 ( V_31 -> V_101 ) ) {
F_46 ( V_2 , & V_31 -> V_94 ) ;
return F_124 ( V_31 -> V_101 ) ;
}
F_58 ( V_31 , V_31 -> V_101 ) ;
return 0 ;
}
static void F_187 ( struct V_92 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_7 ;
F_54 ( V_2 , V_31 -> V_101 ) ;
F_46 ( V_2 , & V_31 -> V_94 ) ;
}
static void F_188 ( struct V_92 * V_31 )
{
struct V_113 * V_114 = F_97 ( V_31 ) ;
struct V_96 * V_97 = & V_114 -> V_97 ;
struct V_1 * V_2 = V_31 -> V_7 ;
struct V_82 * V_83 ;
T_8 V_47 ;
F_189 ( & V_114 -> V_33 ) ;
F_190 (pt, pd, pde)
if ( V_83 != V_31 -> V_101 )
F_54 ( V_2 , V_83 ) ;
F_187 ( V_31 ) ;
}
static int F_191 ( struct V_113 * V_114 )
{
struct V_92 * V_31 = & V_114 -> V_117 ;
struct V_1 * V_2 = V_114 -> V_117 . V_7 ;
struct V_194 * V_8 = & V_2 -> V_8 ;
int V_87 ;
F_81 ( ! F_192 ( & V_8 -> V_117 . V_28 ) ) ;
V_87 = F_186 ( V_31 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_193 ( & V_8 -> V_117 , & V_114 -> V_33 ,
V_235 , V_236 ,
V_237 ,
0 , V_8 -> V_117 . V_181 ,
V_238 ) ;
if ( V_87 )
goto V_168;
if ( V_114 -> V_33 . V_34 < V_8 -> V_239 )
F_194 ( L_15 ) ;
return 0 ;
V_168:
F_187 ( V_31 ) ;
return V_87 ;
}
static int F_195 ( struct V_113 * V_114 )
{
return F_191 ( V_114 ) ;
}
static void F_196 ( struct V_113 * V_114 ,
T_7 V_34 , T_7 V_130 )
{
struct V_82 * V_24 ;
T_8 V_47 ;
F_158 (unused, &ppgtt->pd, start, length, pde)
V_114 -> V_97 . V_135 [ V_47 ] = V_114 -> V_117 . V_101 ;
}
static int F_197 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_117 . V_7 ;
struct V_194 * V_8 = & V_2 -> V_8 ;
int V_87 ;
V_114 -> V_117 . V_95 = V_8 -> V_117 . V_95 ;
if ( F_8 ( V_2 ) || F_11 ( V_2 ) )
V_114 -> V_188 = F_170 ;
else if ( F_177 ( V_2 ) )
V_114 -> V_188 = F_166 ;
else if ( F_198 ( V_2 ) )
V_114 -> V_188 = F_169 ;
else
F_199 () ;
V_87 = F_195 ( V_114 ) ;
if ( V_87 )
return V_87 ;
V_114 -> V_117 . V_183 = F_182 ;
V_114 -> V_117 . V_35 = F_179 ;
V_114 -> V_117 . V_32 = F_180 ;
V_114 -> V_117 . V_184 = F_16 ;
V_114 -> V_117 . V_185 = F_15 ;
V_114 -> V_117 . V_182 = F_188 ;
V_114 -> V_117 . V_34 = 0 ;
V_114 -> V_117 . V_181 = V_99 * V_86 * V_69 ;
V_114 -> V_186 = F_157 ;
V_114 -> V_97 . V_117 . V_196 =
V_114 -> V_33 . V_34 / V_69 * sizeof( T_5 ) ;
V_114 -> V_192 = ( T_5 V_240 * ) V_8 -> V_195 +
V_114 -> V_97 . V_117 . V_196 / sizeof( T_5 ) ;
F_196 ( V_114 , 0 , V_114 -> V_117 . V_181 ) ;
F_164 ( V_2 , & V_114 -> V_97 , 0 , V_114 -> V_117 . V_181 ) ;
F_14 ( L_16 ,
V_114 -> V_33 . V_36 >> 20 ,
V_114 -> V_33 . V_34 / V_69 ) ;
F_194 ( L_17 ,
V_114 -> V_97 . V_117 . V_196 << 10 ) ;
return 0 ;
}
static int F_200 ( struct V_113 * V_114 ,
struct V_1 * V_2 )
{
V_114 -> V_117 . V_7 = V_2 ;
if ( F_95 ( V_2 ) -> V_241 < 8 )
return F_197 ( V_114 ) ;
else
return F_156 ( V_114 ) ;
}
static void F_201 ( struct V_92 * V_31 ,
struct V_1 * V_2 ,
const char * V_242 )
{
F_202 ( V_2 , & V_31 -> V_243 , V_242 ) ;
F_203 ( & V_31 -> V_28 , V_31 -> V_34 , V_31 -> V_181 ) ;
F_204 ( & V_31 -> V_244 ) ;
F_204 ( & V_31 -> V_245 ) ;
F_204 ( & V_31 -> V_246 ) ;
F_205 ( & V_31 -> V_247 , & V_2 -> V_248 ) ;
}
static void F_206 ( struct V_92 * V_31 )
{
F_207 ( & V_31 -> V_243 ) ;
F_208 ( & V_31 -> V_28 ) ;
F_209 ( & V_31 -> V_247 ) ;
}
static void F_210 ( struct V_1 * V_2 )
{
if ( F_211 ( V_2 ) )
F_2 ( V_249 , V_250 ) ;
else if ( F_39 ( V_2 ) )
F_2 ( V_249 , V_251 ) ;
else if ( F_212 ( V_2 ) )
F_2 ( V_249 , V_252 ) ;
else if ( F_213 ( V_2 ) )
F_2 ( V_249 , V_253 ) ;
}
static int F_214 ( struct V_113 * V_114 ,
struct V_1 * V_2 ,
struct V_254 * V_255 ,
const char * V_242 )
{
int V_87 ;
V_87 = F_200 ( V_114 , V_2 ) ;
if ( V_87 == 0 ) {
F_215 ( & V_114 -> V_256 ) ;
F_201 ( & V_114 -> V_117 , V_2 , V_242 ) ;
V_114 -> V_117 . V_257 = V_255 ;
}
return V_87 ;
}
int F_216 ( struct V_1 * V_2 )
{
F_210 ( V_2 ) ;
if ( V_7 . V_19 )
return 0 ;
if ( ! F_217 ( V_2 ) )
return 0 ;
if ( F_11 ( V_2 ) )
F_178 ( V_2 ) ;
else if ( F_198 ( V_2 ) )
F_175 ( V_2 ) ;
else if ( F_9 ( V_2 ) >= 8 )
F_171 ( V_2 ) ;
else
F_21 ( F_9 ( V_2 ) ) ;
return 0 ;
}
struct V_113 *
F_218 ( struct V_1 * V_2 ,
struct V_254 * V_258 ,
const char * V_242 )
{
struct V_113 * V_114 ;
int V_87 ;
V_114 = F_48 ( sizeof( * V_114 ) , V_88 ) ;
if ( ! V_114 )
return F_49 ( - V_67 ) ;
V_87 = F_214 ( V_114 , V_2 , V_258 , V_242 ) ;
if ( V_87 ) {
F_53 ( V_114 ) ;
return F_49 ( V_87 ) ;
}
F_219 ( & V_114 -> V_117 ) ;
return V_114 ;
}
void F_220 ( struct V_92 * V_31 )
{
struct V_259 * V_260 [] = {
& V_31 -> V_244 ,
& V_31 -> V_245 ,
& V_31 -> V_246 ,
NULL ,
} , * * V_261 ;
F_100 ( V_31 -> V_262 ) ;
V_31 -> V_262 = true ;
for ( V_261 = V_260 ; * V_261 ; V_261 ++ ) {
struct V_20 * V_21 , * V_263 ;
F_221 (vma, vn, *phase, vm_link)
if ( ! F_222 ( V_21 ) )
F_223 ( V_21 ) ;
}
}
void F_224 ( struct V_264 * V_264 )
{
struct V_113 * V_114 =
F_162 ( V_264 , struct V_113 , V_256 ) ;
F_225 ( & V_114 -> V_117 ) ;
F_34 ( ! F_226 ( & V_114 -> V_117 . V_244 ) ) ;
F_34 ( ! F_226 ( & V_114 -> V_117 . V_245 ) ) ;
F_34 ( ! F_226 ( & V_114 -> V_117 . V_246 ) ) ;
F_206 ( & V_114 -> V_117 ) ;
V_114 -> V_117 . V_182 ( & V_114 -> V_117 ) ;
F_53 ( V_114 ) ;
}
static bool F_227 ( struct V_1 * V_2 )
{
#ifdef F_10
if ( F_228 ( V_2 ) && F_229 ( V_2 ) && V_15 )
return true ;
#endif
return false ;
}
void F_230 ( struct V_1 * V_2 )
{
struct V_124 * V_125 ;
enum V_204 V_202 ;
if ( F_95 ( V_2 ) -> V_241 < 6 )
return;
F_172 (engine, dev_priv, id) {
T_1 V_265 ;
V_265 = F_176 ( F_231 ( V_125 ) ) ;
if ( V_265 & V_266 ) {
F_14 ( L_18
L_19
L_20
L_21
L_22 ,
V_265 & V_267 ,
V_265 & V_268 ? L_23 : L_24 ,
F_232 ( V_265 ) ,
F_233 ( V_265 ) ) ;
F_2 ( F_231 ( V_125 ) ,
V_265 & ~ V_266 ) ;
}
}
if ( V_2 -> V_125 [ V_203 ] )
F_234 ( F_231 ( V_2 -> V_125 [ V_203 ] ) ) ;
}
void F_235 ( struct V_1 * V_2 )
{
struct V_194 * V_8 = & V_2 -> V_8 ;
if ( F_9 ( V_2 ) < 6 )
return;
F_230 ( V_2 ) ;
V_8 -> V_117 . V_35 ( & V_8 -> V_117 , V_8 -> V_117 . V_34 , V_8 -> V_117 . V_181 ) ;
F_6 ( V_2 ) ;
}
int F_236 ( struct V_269 * V_27 ,
struct V_142 * V_26 )
{
do {
if ( F_237 ( & V_27 -> V_117 . V_65 -> V_17 -> V_65 ,
V_26 -> V_143 , V_26 -> V_270 ,
V_70 ) )
return 0 ;
F_100 ( V_27 -> V_28 . V_26 == V_26 ) ;
} while ( F_238 ( F_76 ( V_27 -> V_117 . V_65 ) ,
V_27 -> V_117 . V_36 >> V_145 ,
V_271 |
V_272 |
V_273 ) );
return - V_274 ;
}
static void F_239 ( void V_240 * V_37 , T_2 V_39 )
{
F_240 ( V_39 , V_37 ) ;
}
static void F_241 ( struct V_92 * V_31 ,
T_3 V_37 ,
T_7 V_275 ,
enum V_22 V_38 ,
T_1 V_24 )
{
struct V_194 * V_8 = F_242 ( V_31 ) ;
T_2 V_240 * V_39 =
( T_2 V_240 * ) V_8 -> V_195 + ( V_275 >> V_145 ) ;
F_239 ( V_39 , F_17 ( V_37 , V_38 ) ) ;
V_8 -> V_9 ( V_31 -> V_7 ) ;
}
static void F_243 ( struct V_92 * V_31 ,
struct V_142 * V_276 ,
T_7 V_34 ,
enum V_22 V_38 , T_1 V_24 )
{
struct V_194 * V_8 = F_242 ( V_31 ) ;
struct V_228 V_228 ;
T_2 V_240 * V_277 ;
T_2 V_278 ;
T_3 V_37 ;
int V_76 = 0 ;
V_277 = ( T_2 V_240 * ) V_8 -> V_195 + ( V_34 >> V_145 ) ;
F_181 (addr, sgt_iter, st) {
V_278 = F_17 ( V_37 , V_38 ) ;
F_239 ( & V_277 [ V_76 ++ ] , V_278 ) ;
}
if ( V_76 != 0 )
F_34 ( F_244 ( & V_277 [ V_76 - 1 ] ) != V_278 ) ;
V_8 -> V_9 ( V_31 -> V_7 ) ;
}
static int F_245 ( void * V_279 )
{
struct V_32 * V_280 = V_279 ;
F_243 ( V_280 -> V_31 , V_280 -> V_276 ,
V_280 -> V_34 , V_280 -> V_38 , V_280 -> V_55 ) ;
return 0 ;
}
static void F_246 ( struct V_92 * V_31 ,
struct V_142 * V_276 ,
T_7 V_34 ,
enum V_22 V_38 ,
T_1 V_55 )
{
struct V_32 V_280 = { V_31 , V_276 , V_34 , V_38 , V_55 } ;
F_247 ( F_245 , & V_280 , NULL ) ;
}
static void F_248 ( struct V_92 * V_31 ,
T_3 V_37 ,
T_7 V_275 ,
enum V_22 V_38 ,
T_1 V_55 )
{
struct V_194 * V_8 = F_242 ( V_31 ) ;
T_5 V_240 * V_39 =
( T_5 V_240 * ) V_8 -> V_195 + ( V_275 >> V_145 ) ;
F_249 ( V_31 -> V_95 ( V_37 , V_38 , V_55 ) , V_39 ) ;
V_8 -> V_9 ( V_31 -> V_7 ) ;
}
static void F_250 ( struct V_92 * V_31 ,
struct V_142 * V_276 ,
T_7 V_34 ,
enum V_22 V_38 , T_1 V_55 )
{
struct V_194 * V_8 = F_242 ( V_31 ) ;
struct V_228 V_228 ;
T_5 V_240 * V_277 ;
T_5 V_278 ;
T_3 V_37 ;
int V_76 = 0 ;
V_277 = ( T_5 V_240 * ) V_8 -> V_195 + ( V_34 >> V_145 ) ;
F_181 (addr, sgt_iter, st) {
V_278 = V_31 -> V_95 ( V_37 , V_38 , V_55 ) ;
F_249 ( V_278 , & V_277 [ V_76 ++ ] ) ;
}
if ( V_76 != 0 )
F_34 ( F_159 ( & V_277 [ V_76 - 1 ] ) != V_278 ) ;
V_8 -> V_9 ( V_31 -> V_7 ) ;
}
static void F_251 ( struct V_92 * V_31 ,
T_7 V_34 , T_7 V_130 )
{
}
static void F_252 ( struct V_92 * V_31 ,
T_7 V_34 , T_7 V_130 )
{
struct V_194 * V_8 = F_242 ( V_31 ) ;
unsigned V_223 = V_34 >> V_145 ;
unsigned V_131 = V_130 >> V_145 ;
T_2 V_93 , V_240 * V_281 =
( T_2 V_240 * ) V_8 -> V_195 + V_223 ;
const int V_282 = F_253 ( V_8 ) - V_223 ;
int V_76 ;
if ( F_147 ( V_131 > V_282 ,
L_25 ,
V_223 , V_131 , V_282 ) )
V_131 = V_282 ;
V_93 = F_17 ( V_31 -> V_94 . V_68 ,
V_51 ) ;
for ( V_76 = 0 ; V_76 < V_131 ; V_76 ++ )
F_239 ( & V_281 [ V_76 ] , V_93 ) ;
F_159 ( V_281 ) ;
}
static void F_254 ( struct V_92 * V_31 ,
T_7 V_34 ,
T_7 V_130 )
{
struct V_194 * V_8 = F_242 ( V_31 ) ;
unsigned V_223 = V_34 >> V_145 ;
unsigned V_131 = V_130 >> V_145 ;
T_5 V_93 , V_240 * V_281 =
( T_5 V_240 * ) V_8 -> V_195 + V_223 ;
const int V_282 = F_253 ( V_8 ) - V_223 ;
int V_76 ;
if ( F_147 ( V_131 > V_282 ,
L_25 ,
V_223 , V_131 , V_282 ) )
V_131 = V_282 ;
V_93 = V_31 -> V_95 ( V_31 -> V_94 . V_68 ,
V_51 , 0 ) ;
for ( V_76 = 0 ; V_76 < V_131 ; V_76 ++ )
F_249 ( V_93 , & V_281 [ V_76 ] ) ;
F_159 ( V_281 ) ;
}
static void F_255 ( struct V_92 * V_31 ,
T_3 V_37 ,
T_7 V_275 ,
enum V_22 V_23 ,
T_1 V_24 )
{
unsigned int V_55 = ( V_23 == V_42 ) ?
V_283 : V_284 ;
F_256 ( V_37 , V_275 >> V_145 , V_55 ) ;
}
static void F_257 ( struct V_92 * V_31 ,
struct V_142 * V_26 ,
T_7 V_34 ,
enum V_22 V_23 , T_1 V_24 )
{
unsigned int V_55 = ( V_23 == V_42 ) ?
V_283 : V_284 ;
F_258 ( V_26 , V_34 >> V_145 , V_55 ) ;
}
static void F_259 ( struct V_92 * V_31 ,
T_7 V_34 ,
T_7 V_130 )
{
F_260 ( V_34 >> V_145 , V_130 >> V_145 ) ;
}
static int F_261 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
T_1 V_55 )
{
struct V_1 * V_7 = V_21 -> V_31 -> V_7 ;
struct V_269 * V_27 = V_21 -> V_27 ;
T_1 V_25 = 0 ;
int V_87 ;
V_87 = F_262 ( V_21 ) ;
if ( V_87 )
return V_87 ;
if ( V_27 -> V_29 )
V_25 |= V_30 ;
F_263 ( V_7 ) ;
V_21 -> V_31 -> V_32 ( V_21 -> V_31 , V_21 -> V_26 , V_21 -> V_33 . V_34 ,
V_23 , V_25 ) ;
F_264 ( V_7 ) ;
V_21 -> V_55 |= V_285 | V_286 ;
return 0 ;
}
static int F_265 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
T_1 V_55 )
{
struct V_1 * V_7 = V_21 -> V_31 -> V_7 ;
T_1 V_25 ;
int V_87 ;
V_87 = F_262 ( V_21 ) ;
if ( V_87 )
return V_87 ;
V_25 = 0 ;
if ( V_21 -> V_27 -> V_29 )
V_25 |= V_30 ;
if ( V_55 & V_285 ) {
F_263 ( V_7 ) ;
V_21 -> V_31 -> V_32 ( V_21 -> V_31 ,
V_21 -> V_26 , V_21 -> V_33 . V_34 ,
V_23 , V_25 ) ;
F_264 ( V_7 ) ;
}
if ( V_55 & V_286 ) {
struct V_113 * V_287 = V_7 -> V_28 . V_288 ;
V_287 -> V_117 . V_32 ( & V_287 -> V_117 ,
V_21 -> V_26 , V_21 -> V_33 . V_34 ,
V_23 , V_25 ) ;
}
return 0 ;
}
static void F_266 ( struct V_20 * V_21 )
{
struct V_1 * V_7 = V_21 -> V_31 -> V_7 ;
struct V_113 * V_287 = V_7 -> V_28 . V_288 ;
const T_12 V_36 = F_267 ( V_21 -> V_36 , V_21 -> V_33 . V_36 ) ;
if ( V_21 -> V_55 & V_285 ) {
F_263 ( V_7 ) ;
V_21 -> V_31 -> V_35 ( V_21 -> V_31 ,
V_21 -> V_33 . V_34 , V_36 ) ;
F_264 ( V_7 ) ;
}
if ( V_21 -> V_55 & V_286 && V_287 )
V_287 -> V_117 . V_35 ( & V_287 -> V_117 ,
V_21 -> V_33 . V_34 , V_36 ) ;
}
void F_268 ( struct V_269 * V_27 ,
struct V_142 * V_26 )
{
struct V_1 * V_2 = F_76 ( V_27 -> V_117 . V_65 ) ;
struct V_63 * V_64 = & V_2 -> V_16 . V_17 -> V_65 ;
struct V_194 * V_8 = & V_2 -> V_8 ;
if ( F_269 ( V_8 -> V_289 ) ) {
if ( F_270 ( V_2 , 0 ) ) {
F_271 ( L_26 ) ;
F_272 ( 10 ) ;
}
}
F_273 ( V_64 , V_26 -> V_143 , V_26 -> V_270 , V_70 ) ;
}
static void F_274 ( const struct V_290 * V_33 ,
unsigned long V_291 ,
T_12 * V_34 ,
T_12 * V_292 )
{
if ( V_33 -> V_291 != V_291 )
* V_34 += V_293 ;
V_33 = F_275 ( V_33 , V_294 ) ;
if ( V_33 -> V_295 && V_33 -> V_291 != V_291 )
* V_292 -= V_293 ;
}
int F_276 ( struct V_1 * V_2 )
{
struct V_194 * V_8 = & V_2 -> V_8 ;
unsigned long V_296 , V_297 ;
struct V_113 * V_114 ;
struct V_290 * V_121 ;
int V_87 ;
V_87 = F_277 ( V_2 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_278 ( & V_8 -> V_117 . V_28 , & V_8 -> V_298 ,
V_69 , 0 , V_237 ,
0 , V_8 -> V_239 ,
V_299 ) ;
if ( V_87 )
return V_87 ;
F_279 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_280 ( L_27 ,
V_296 , V_297 ) ;
V_8 -> V_117 . V_35 ( & V_8 -> V_117 , V_296 ,
V_297 - V_296 ) ;
}
V_8 -> V_117 . V_35 ( & V_8 -> V_117 ,
V_8 -> V_117 . V_181 - V_69 , V_69 ) ;
if ( F_217 ( V_2 ) && ! F_102 ( V_2 ) ) {
V_114 = F_48 ( sizeof( * V_114 ) , V_88 ) ;
if ( ! V_114 ) {
V_87 = - V_67 ;
goto V_300;
}
V_87 = F_200 ( V_114 , V_2 ) ;
if ( V_87 )
goto V_301;
if ( V_114 -> V_117 . V_183 ) {
V_87 = V_114 -> V_117 . V_183 ( & V_114 -> V_117 , 0 ,
V_114 -> V_117 . V_181 ) ;
if ( V_87 )
goto V_302;
}
V_114 -> V_117 . V_35 ( & V_114 -> V_117 ,
V_114 -> V_117 . V_34 ,
V_114 -> V_117 . V_181 ) ;
V_2 -> V_28 . V_288 = V_114 ;
F_34 ( V_8 -> V_117 . V_185 != F_261 ) ;
V_8 -> V_117 . V_185 = F_265 ;
}
return 0 ;
V_302:
V_114 -> V_117 . V_182 ( & V_114 -> V_117 ) ;
V_301:
F_53 ( V_114 ) ;
V_300:
F_189 ( & V_8 -> V_298 ) ;
return V_87 ;
}
void F_281 ( struct V_1 * V_2 )
{
struct V_194 * V_8 = & V_2 -> V_8 ;
if ( V_2 -> V_28 . V_288 ) {
struct V_113 * V_114 = V_2 -> V_28 . V_288 ;
V_114 -> V_117 . V_182 ( & V_114 -> V_117 ) ;
F_53 ( V_114 ) ;
}
F_282 ( & V_2 -> V_16 ) ;
if ( F_283 ( & V_8 -> V_298 ) )
F_189 ( & V_8 -> V_298 ) ;
if ( F_192 ( & V_8 -> V_117 . V_28 ) ) {
F_284 ( V_2 ) ;
F_285 ( & V_2 -> V_16 . V_303 ) ;
F_206 ( & V_8 -> V_117 ) ;
F_286 ( & V_2 -> V_16 . V_303 ) ;
}
V_8 -> V_117 . V_182 ( & V_8 -> V_117 ) ;
F_287 ( V_8 -> V_304 ) ;
F_288 ( & V_8 -> V_305 ) ;
}
static unsigned int F_289 ( T_14 V_306 )
{
V_306 >>= V_307 ;
V_306 &= V_308 ;
return V_306 << 20 ;
}
static unsigned int F_290 ( T_14 V_309 )
{
V_309 >>= V_310 ;
V_309 &= V_311 ;
if ( V_309 )
V_309 = 1 << V_309 ;
#ifdef F_291
if ( V_309 > 4 )
V_309 = 4 ;
#endif
return V_309 << 20 ;
}
static unsigned int F_292 ( T_14 V_312 )
{
V_312 >>= V_307 ;
V_312 &= V_308 ;
if ( V_312 )
return 1 << ( 20 + V_312 ) ;
return 0 ;
}
static T_9 F_293 ( T_14 V_306 )
{
V_306 >>= V_313 ;
V_306 &= V_314 ;
return V_306 << 25 ;
}
static T_9 F_294 ( T_14 V_309 )
{
V_309 >>= V_315 ;
V_309 &= V_316 ;
return V_309 << 25 ;
}
static T_9 F_295 ( T_14 V_312 )
{
V_312 >>= V_313 ;
V_312 &= V_314 ;
if ( V_312 < 0x11 )
return V_312 << 25 ;
else if ( V_312 < 0x17 )
return ( V_312 - 0x11 + 2 ) << 22 ;
else
return ( V_312 - 0x17 + 9 ) << 22 ;
}
static T_9 F_296 ( T_14 V_317 )
{
V_317 >>= V_315 ;
V_317 &= V_316 ;
if ( V_317 < 0xf0 )
return V_317 << 25 ;
else
return ( V_317 - 0xf0 + 1 ) << 22 ;
}
static int F_297 ( struct V_194 * V_8 , T_12 V_36 )
{
struct V_1 * V_2 = V_8 -> V_117 . V_7 ;
struct V_73 * V_17 = V_2 -> V_16 . V_17 ;
T_15 V_318 ;
int V_87 ;
V_318 = F_298 ( V_17 , 0 ) + F_299 ( V_17 , 0 ) / 2 ;
if ( F_40 ( V_2 ) )
V_8 -> V_195 = F_300 ( V_318 , V_36 ) ;
else
V_8 -> V_195 = F_301 ( V_318 , V_36 ) ;
if ( ! V_8 -> V_195 ) {
F_271 ( L_28 ) ;
return - V_67 ;
}
V_87 = F_45 ( V_2 , & V_8 -> V_117 . V_94 , V_319 ) ;
if ( V_87 ) {
F_271 ( L_29 ) ;
F_302 ( V_8 -> V_195 ) ;
return V_87 ;
}
return 0 ;
}
static void F_303 ( struct V_1 * V_2 )
{
T_7 V_320 ;
V_320 = F_304 ( 0 , V_321 | V_322 ) |
F_304 ( 1 , V_323 | V_324 ) |
F_304 ( 2 , V_325 | V_324 ) |
F_304 ( 3 , V_326 ) |
F_304 ( 4 , V_321 | V_324 | F_305 ( 0 ) ) |
F_304 ( 5 , V_321 | V_324 | F_305 ( 1 ) ) |
F_304 ( 6 , V_321 | V_324 | F_305 ( 2 ) ) |
F_304 ( 7 , V_321 | V_324 | F_305 ( 3 ) ) ;
if ( ! F_217 ( V_2 ) )
V_320 = F_304 ( 0 , V_326 ) ;
F_2 ( V_327 , V_320 ) ;
F_2 ( V_328 , V_320 >> 32 ) ;
}
static void F_306 ( struct V_1 * V_2 )
{
T_7 V_320 ;
V_320 = F_304 ( 0 , V_329 ) |
F_304 ( 1 , 0 ) |
F_304 ( 2 , 0 ) |
F_304 ( 3 , 0 ) |
F_304 ( 4 , V_329 ) |
F_304 ( 5 , V_329 ) |
F_304 ( 6 , V_329 ) |
F_304 ( 7 , V_329 ) ;
F_2 ( V_327 , V_320 ) ;
F_2 ( V_328 , V_320 >> 32 ) ;
}
static void F_307 ( struct V_92 * V_31 )
{
struct V_194 * V_8 = F_242 ( V_31 ) ;
F_302 ( V_8 -> V_195 ) ;
F_46 ( V_31 -> V_7 , & V_31 -> V_94 ) ;
}
static int F_308 ( struct V_194 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_117 . V_7 ;
struct V_73 * V_17 = V_2 -> V_16 . V_17 ;
unsigned int V_36 ;
T_14 V_306 ;
V_8 -> V_330 = F_298 ( V_17 , 2 ) ;
V_8 -> V_239 = F_299 ( V_17 , 2 ) ;
if ( ! F_309 ( V_17 , F_310 ( 39 ) ) )
F_311 ( V_17 , F_310 ( 39 ) ) ;
F_312 ( V_17 , V_331 , & V_306 ) ;
if ( F_9 ( V_2 ) >= 9 ) {
V_8 -> V_332 = F_296 ( V_306 ) ;
V_36 = F_290 ( V_306 ) ;
} else if ( F_39 ( V_2 ) ) {
V_8 -> V_332 = F_295 ( V_306 ) ;
V_36 = F_292 ( V_306 ) ;
} else {
V_8 -> V_332 = F_294 ( V_306 ) ;
V_36 = F_290 ( V_306 ) ;
}
V_8 -> V_117 . V_181 = ( V_36 / sizeof( T_2 ) ) << V_145 ;
if ( F_39 ( V_2 ) || F_40 ( V_2 ) )
F_306 ( V_2 ) ;
else
F_303 ( V_2 ) ;
V_8 -> V_117 . V_182 = F_307 ;
V_8 -> V_117 . V_185 = F_261 ;
V_8 -> V_117 . V_184 = F_266 ;
V_8 -> V_117 . V_333 = F_241 ;
V_8 -> V_117 . V_35 = F_251 ;
if ( ! F_102 ( V_2 ) || F_313 ( V_2 ) )
V_8 -> V_117 . V_35 = F_252 ;
V_8 -> V_117 . V_32 = F_243 ;
if ( F_39 ( V_2 ) )
V_8 -> V_117 . V_32 = F_246 ;
V_8 -> V_9 = F_1 ;
return F_297 ( V_8 , V_36 ) ;
}
static int F_314 ( struct V_194 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_117 . V_7 ;
struct V_73 * V_17 = V_2 -> V_16 . V_17 ;
unsigned int V_36 ;
T_14 V_306 ;
V_8 -> V_330 = F_298 ( V_17 , 2 ) ;
V_8 -> V_239 = F_299 ( V_17 , 2 ) ;
if ( V_8 -> V_239 < ( 64 << 20 ) || V_8 -> V_239 > ( 512 << 20 ) ) {
F_271 ( L_30 , V_8 -> V_239 ) ;
return - V_334 ;
}
if ( ! F_309 ( V_17 , F_310 ( 40 ) ) )
F_311 ( V_17 , F_310 ( 40 ) ) ;
F_312 ( V_17 , V_331 , & V_306 ) ;
V_8 -> V_332 = F_293 ( V_306 ) ;
V_36 = F_289 ( V_306 ) ;
V_8 -> V_117 . V_181 = ( V_36 / sizeof( T_5 ) ) << V_145 ;
V_8 -> V_117 . V_35 = F_254 ;
V_8 -> V_117 . V_333 = F_248 ;
V_8 -> V_117 . V_32 = F_250 ;
V_8 -> V_117 . V_185 = F_261 ;
V_8 -> V_117 . V_184 = F_266 ;
V_8 -> V_117 . V_182 = F_307 ;
V_8 -> V_9 = F_1 ;
if ( F_315 ( V_2 ) )
V_8 -> V_117 . V_95 = F_26 ;
else if ( F_177 ( V_2 ) )
V_8 -> V_117 . V_95 = F_24 ;
else if ( F_13 ( V_2 ) )
V_8 -> V_117 . V_95 = F_23 ;
else if ( F_9 ( V_2 ) >= 7 )
V_8 -> V_117 . V_95 = F_22 ;
else
V_8 -> V_117 . V_95 = F_19 ;
return F_297 ( V_8 , V_36 ) ;
}
static void F_316 ( struct V_92 * V_31 )
{
F_317 () ;
}
static int F_318 ( struct V_194 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_117 . V_7 ;
int V_87 ;
V_87 = F_319 ( V_2 -> V_335 , V_2 -> V_16 . V_17 , NULL ) ;
if ( ! V_87 ) {
F_271 ( L_31 ) ;
return - V_336 ;
}
F_320 ( & V_8 -> V_117 . V_181 ,
& V_8 -> V_332 ,
& V_8 -> V_330 ,
& V_8 -> V_239 ) ;
V_8 -> V_289 = F_227 ( V_2 ) ;
V_8 -> V_117 . V_333 = F_255 ;
V_8 -> V_117 . V_32 = F_257 ;
V_8 -> V_117 . V_35 = F_259 ;
V_8 -> V_117 . V_185 = F_261 ;
V_8 -> V_117 . V_184 = F_266 ;
V_8 -> V_117 . V_182 = F_316 ;
V_8 -> V_9 = F_4 ;
if ( F_269 ( V_8 -> V_289 ) )
F_12 ( L_32 ) ;
return 0 ;
}
int F_321 ( struct V_1 * V_2 )
{
struct V_194 * V_8 = & V_2 -> V_8 ;
int V_87 ;
V_8 -> V_117 . V_7 = V_2 ;
if ( F_9 ( V_2 ) <= 5 )
V_87 = F_318 ( V_8 ) ;
else if ( F_9 ( V_2 ) < 8 )
V_87 = F_314 ( V_8 ) ;
else
V_87 = F_308 ( V_8 ) ;
if ( V_87 )
return V_87 ;
if ( F_322 ( V_2 ) && V_7 . V_337 ) {
V_8 -> V_117 . V_181 = F_323 ( T_12 , V_8 -> V_117 . V_181 , V_338 ) ;
V_8 -> V_239 = F_267 ( V_8 -> V_239 , V_8 -> V_117 . V_181 ) ;
}
if ( ( V_8 -> V_117 . V_181 - 1 ) >> 32 ) {
F_271 ( L_33
L_34 ,
V_8 -> V_117 . V_181 >> 20 ) ;
V_8 -> V_117 . V_181 = 1ULL << 32 ;
V_8 -> V_239 = F_267 ( V_8 -> V_239 , V_8 -> V_117 . V_181 ) ;
}
if ( V_8 -> V_239 > V_8 -> V_117 . V_181 ) {
F_271 ( L_35
L_36 ,
V_8 -> V_239 , V_8 -> V_117 . V_181 ) ;
V_8 -> V_239 = V_8 -> V_117 . V_181 ;
}
F_12 ( L_37 ,
V_8 -> V_117 . V_181 >> 20 ) ;
F_14 ( L_38 , V_8 -> V_239 >> 20 ) ;
F_14 ( L_39 , V_8 -> V_332 >> 20 ) ;
#ifdef F_10
if ( V_15 )
F_12 ( L_40 ) ;
#endif
return 0 ;
}
int F_324 ( struct V_1 * V_2 )
{
struct V_194 * V_8 = & V_2 -> V_8 ;
int V_87 ;
F_204 ( & V_2 -> V_248 ) ;
F_285 ( & V_2 -> V_16 . V_303 ) ;
V_8 -> V_117 . V_181 -= V_69 ;
F_201 ( & V_8 -> V_117 , V_2 , L_41 ) ;
V_8 -> V_117 . V_181 += V_69 ;
if ( ! F_325 ( V_2 ) )
V_8 -> V_117 . V_28 . V_339 = F_274 ;
F_286 ( & V_2 -> V_16 . V_303 ) ;
if ( ! F_326 ( & V_2 -> V_8 . V_305 ,
V_2 -> V_8 . V_330 ,
V_2 -> V_8 . V_239 ) ) {
V_87 = - V_336 ;
goto V_340;
}
V_8 -> V_304 = F_327 ( V_8 -> V_330 , V_8 -> V_239 ) ;
V_87 = F_328 ( V_2 ) ;
if ( V_87 )
goto V_340;
return 0 ;
V_340:
V_8 -> V_117 . V_182 ( & V_8 -> V_117 ) ;
return V_87 ;
}
int F_329 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) < 6 && ! F_330 () )
return - V_336 ;
return 0 ;
}
void F_331 ( struct V_1 * V_7 )
{
V_7 -> V_8 . V_9 = F_3 ;
}
void F_332 ( struct V_1 * V_7 )
{
V_7 -> V_8 . V_9 = F_1 ;
}
void F_333 ( struct V_1 * V_2 )
{
struct V_194 * V_8 = & V_2 -> V_8 ;
struct V_269 * V_27 , * V_341 ;
F_230 ( V_2 ) ;
V_8 -> V_117 . V_35 ( & V_8 -> V_117 , V_8 -> V_117 . V_34 , V_8 -> V_117 . V_181 ) ;
V_8 -> V_117 . V_262 = true ;
F_221 (obj, on,
&dev_priv->mm.bound_list, global_link) {
bool V_342 = false ;
struct V_20 * V_21 ;
F_334 (vma, &obj->vma_list, obj_link) {
if ( V_21 -> V_31 != & V_8 -> V_117 )
continue;
if ( ! F_335 ( V_21 ) )
continue;
F_34 ( F_336 ( V_21 , V_27 -> V_23 ,
V_343 ) ) ;
V_342 = true ;
}
if ( V_342 )
F_34 ( F_337 ( V_27 , false ) ) ;
}
V_8 -> V_117 . V_262 = false ;
if ( F_9 ( V_2 ) >= 8 ) {
if ( F_39 ( V_2 ) || F_40 ( V_2 ) )
F_306 ( V_2 ) ;
else
F_303 ( V_2 ) ;
return;
}
if ( F_217 ( V_2 ) ) {
struct V_92 * V_31 ;
F_334 (vm, &dev_priv->vm_list, global_link) {
struct V_113 * V_114 ;
if ( F_338 ( V_31 ) )
V_114 = V_2 -> V_28 . V_288 ;
else
V_114 = F_97 ( V_31 ) ;
F_164 ( V_2 , & V_114 -> V_97 ,
0 , V_114 -> V_117 . V_181 ) ;
}
}
F_6 ( V_2 ) ;
}
static struct V_344 *
F_339 ( const T_3 * V_345 , unsigned int V_275 ,
unsigned int V_346 , unsigned int V_347 ,
unsigned int V_348 ,
struct V_142 * V_276 , struct V_344 * V_349 )
{
unsigned int V_350 , V_351 ;
unsigned int V_352 ;
for ( V_350 = 0 ; V_350 < V_346 ; V_350 ++ ) {
V_352 = V_348 * ( V_347 - 1 ) + V_350 ;
for ( V_351 = 0 ; V_351 < V_347 ; V_351 ++ ) {
V_276 -> V_270 ++ ;
F_340 ( V_349 , NULL , V_69 , 0 ) ;
F_341 ( V_349 ) = V_345 [ V_275 + V_352 ] ;
F_342 ( V_349 ) = V_69 ;
V_349 = F_343 ( V_349 ) ;
V_352 -= V_348 ;
}
}
return V_349 ;
}
static struct V_142 *
F_344 ( const struct V_353 * V_354 ,
struct V_269 * V_27 )
{
const T_9 V_355 = V_27 -> V_117 . V_36 / V_69 ;
unsigned int V_36 = F_345 ( V_354 ) ;
struct V_228 V_228 ;
T_3 V_356 ;
unsigned long V_76 ;
T_3 * V_357 ;
struct V_142 * V_276 ;
struct V_344 * V_349 ;
int V_87 = - V_67 ;
V_357 = F_346 ( V_355 ,
sizeof( T_3 ) ,
V_167 ) ;
if ( ! V_357 )
return F_49 ( V_87 ) ;
V_276 = F_347 ( sizeof( * V_276 ) , V_88 ) ;
if ( ! V_276 )
goto V_358;
V_87 = F_348 ( V_276 , V_36 , V_88 ) ;
if ( V_87 )
goto V_359;
V_76 = 0 ;
F_181 (dma_addr, sgt_iter, obj->mm.pages)
V_357 [ V_76 ++ ] = V_356 ;
F_100 ( V_76 != V_355 ) ;
V_276 -> V_270 = 0 ;
V_349 = V_276 -> V_143 ;
for ( V_76 = 0 ; V_76 < F_349 ( V_354 -> V_360 ) ; V_76 ++ ) {
V_349 = F_339 ( V_357 , V_354 -> V_360 [ V_76 ] . V_275 ,
V_354 -> V_360 [ V_76 ] . V_346 , V_354 -> V_360 [ V_76 ] . V_347 ,
V_354 -> V_360 [ V_76 ] . V_348 , V_276 , V_349 ) ;
}
F_280 ( L_42 ,
V_27 -> V_117 . V_36 , V_354 -> V_360 [ 0 ] . V_346 , V_354 -> V_360 [ 0 ] . V_347 , V_36 ) ;
F_350 ( V_357 ) ;
return V_276 ;
V_359:
F_53 ( V_276 ) ;
V_358:
F_350 ( V_357 ) ;
F_280 ( L_43 ,
V_27 -> V_117 . V_36 , V_354 -> V_360 [ 0 ] . V_346 , V_354 -> V_360 [ 0 ] . V_347 , V_36 ) ;
return F_49 ( V_87 ) ;
}
static struct V_142 *
F_351 ( const struct V_361 * V_362 ,
struct V_269 * V_27 )
{
struct V_142 * V_276 ;
struct V_344 * V_349 , * V_363 ;
unsigned int V_84 = V_362 -> V_364 . V_36 ;
unsigned int V_275 ;
int V_87 = - V_67 ;
V_276 = F_347 ( sizeof( * V_276 ) , V_88 ) ;
if ( ! V_276 )
goto V_358;
V_87 = F_348 ( V_276 , V_84 , V_88 ) ;
if ( V_87 )
goto V_359;
V_363 = F_352 ( V_27 , V_362 -> V_364 . V_275 , & V_275 ) ;
F_100 ( ! V_363 ) ;
V_349 = V_276 -> V_143 ;
V_276 -> V_270 = 0 ;
do {
unsigned int V_365 ;
V_365 = F_267 ( V_363 -> V_130 - ( V_275 << V_145 ) ,
V_84 << V_145 ) ;
F_340 ( V_349 , NULL , V_365 , 0 ) ;
F_341 ( V_349 ) =
F_341 ( V_363 ) + ( V_275 << V_145 ) ;
F_342 ( V_349 ) = V_365 ;
V_276 -> V_270 ++ ;
V_84 -= V_365 >> V_145 ;
if ( V_84 == 0 ) {
F_353 ( V_349 ) ;
return V_276 ;
}
V_349 = F_354 ( V_349 ) ;
V_363 = F_354 ( V_363 ) ;
V_275 = 0 ;
} while ( 1 );
V_359:
F_53 ( V_276 ) ;
V_358:
return F_49 ( V_87 ) ;
}
static int
F_262 ( struct V_20 * V_21 )
{
int V_87 = 0 ;
F_100 ( ! F_355 ( V_21 -> V_27 ) ) ;
if ( V_21 -> V_26 )
return 0 ;
if ( V_21 -> V_366 . type == V_367 )
V_21 -> V_26 = V_21 -> V_27 -> V_28 . V_26 ;
else if ( V_21 -> V_366 . type == V_368 )
V_21 -> V_26 =
F_344 ( & V_21 -> V_366 . V_369 ,
V_21 -> V_27 ) ;
else if ( V_21 -> V_366 . type == V_370 )
V_21 -> V_26 = F_351 ( & V_21 -> V_366 , V_21 -> V_27 ) ;
else
F_356 ( 1 , L_44 ,
V_21 -> V_366 . type ) ;
if ( ! V_21 -> V_26 ) {
F_271 ( L_45 ,
V_21 -> V_366 . type ) ;
V_87 = - V_71 ;
} else if ( F_123 ( V_21 -> V_26 ) ) {
V_87 = F_124 ( V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
F_271 ( L_46 ,
V_21 -> V_366 . type , V_87 ) ;
}
return V_87 ;
}
int F_357 ( struct V_92 * V_31 ,
struct V_290 * V_33 ,
T_12 V_36 , T_12 V_275 , unsigned long V_291 ,
unsigned int V_55 )
{
int V_300 ;
F_100 ( ! V_36 ) ;
F_100 ( ! F_358 ( V_36 , V_293 ) ) ;
F_100 ( ! F_358 ( V_275 , V_371 ) ) ;
F_100 ( F_359 ( V_275 , V_36 , V_31 -> V_181 ) ) ;
F_100 ( V_31 == & V_31 -> V_7 -> V_28 . V_288 -> V_117 ) ;
F_100 ( F_283 ( V_33 ) ) ;
V_33 -> V_36 = V_36 ;
V_33 -> V_34 = V_275 ;
V_33 -> V_291 = V_291 ;
V_300 = F_360 ( & V_31 -> V_28 , V_33 ) ;
if ( V_300 != - V_274 )
return V_300 ;
V_300 = F_361 ( V_31 , V_33 , V_55 ) ;
if ( V_300 == 0 )
V_300 = F_360 ( & V_31 -> V_28 , V_33 ) ;
return V_300 ;
}
static T_12 F_362 ( T_12 V_34 , T_12 V_292 , T_12 V_365 , T_12 V_372 )
{
T_12 V_373 , V_37 ;
F_100 ( F_359 ( V_34 , V_365 , V_292 ) ) ;
F_100 ( F_363 ( V_34 , V_372 ) > F_364 ( V_292 - V_365 , V_372 ) ) ;
V_373 = F_364 ( V_292 - V_365 , V_372 ) - F_363 ( V_34 , V_372 ) ;
if ( V_373 ) {
if (sizeof( unsigned long ) == sizeof( T_12 ) ) {
V_37 = F_365 () ;
} else {
V_37 = F_366 () ;
if ( V_373 > V_374 ) {
V_37 <<= 32 ;
V_37 |= F_366 () ;
}
}
F_367 ( V_37 , V_373 , & V_37 ) ;
V_34 += V_37 ;
}
return F_363 ( V_34 , V_372 ) ;
}
int F_193 ( struct V_92 * V_31 ,
struct V_290 * V_33 ,
T_12 V_36 , T_12 V_375 , unsigned long V_291 ,
T_12 V_34 , T_12 V_292 , unsigned int V_55 )
{
enum V_376 V_377 ;
T_12 V_275 ;
int V_300 ;
F_368 ( & V_31 -> V_7 -> V_16 . V_303 ) ;
F_100 ( ! V_36 ) ;
F_100 ( ! F_358 ( V_36 , V_293 ) ) ;
F_100 ( V_375 && ! F_369 ( V_375 ) ) ;
F_100 ( V_375 && ! F_358 ( V_375 , V_371 ) ) ;
F_100 ( V_34 >= V_292 ) ;
F_100 ( V_34 > 0 && ! F_358 ( V_34 , V_293 ) ) ;
F_100 ( V_292 < V_378 && ! F_358 ( V_292 , V_293 ) ) ;
F_100 ( V_31 == & V_31 -> V_7 -> V_28 . V_288 -> V_117 ) ;
F_100 ( F_283 ( V_33 ) ) ;
if ( F_269 ( F_359 ( V_34 , V_36 , V_292 ) ) )
return - V_274 ;
if ( F_269 ( F_363 ( V_34 , V_375 ) > F_364 ( V_292 - V_36 , V_375 ) ) )
return - V_274 ;
V_377 = V_379 ;
if ( V_55 & V_238 )
V_377 = V_380 ;
if ( V_55 & V_381 )
V_377 = V_299 ;
F_370 ( V_371 > V_293 ) ;
if ( V_375 <= V_371 )
V_375 = 0 ;
V_300 = F_278 ( & V_31 -> V_28 , V_33 ,
V_36 , V_375 , V_291 ,
V_34 , V_292 , V_377 ) ;
if ( V_300 != - V_274 )
return V_300 ;
V_275 = F_362 ( V_34 , V_292 ,
V_36 , V_375 ? : V_371 ) ;
V_300 = F_357 ( V_31 , V_33 , V_36 , V_275 , V_291 , V_55 ) ;
if ( V_300 != - V_274 )
return V_300 ;
V_300 = F_371 ( V_31 , V_36 , V_375 , V_291 ,
V_34 , V_292 , V_55 ) ;
if ( V_300 )
return V_300 ;
return F_278 ( & V_31 -> V_28 , V_33 ,
V_36 , V_375 , V_291 ,
V_34 , V_292 , V_382 ) ;
}
