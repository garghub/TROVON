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
T_1 V_25 ;
int V_26 ;
if ( ! ( V_21 -> V_27 & V_28 ) ) {
V_26 = V_21 -> V_29 -> V_30 ( V_21 -> V_29 , V_21 -> V_31 . V_32 ,
V_21 -> V_33 ) ;
if ( V_26 )
return V_26 ;
}
V_21 -> V_34 = V_21 -> V_35 -> V_36 . V_34 ;
V_25 = 0 ;
if ( V_21 -> V_35 -> V_37 )
V_25 |= V_38 ;
V_21 -> V_29 -> V_39 ( V_21 -> V_29 , V_21 -> V_34 , V_21 -> V_31 . V_32 ,
V_23 , V_25 ) ;
return 0 ;
}
static void F_16 ( struct V_20 * V_21 )
{
V_21 -> V_29 -> V_40 ( V_21 -> V_29 , V_21 -> V_31 . V_32 , V_21 -> V_33 ) ;
}
static T_2 F_17 ( T_3 V_41 ,
enum V_22 V_42 )
{
T_2 V_43 = V_44 | V_45 ;
V_43 |= V_41 ;
switch ( V_42 ) {
case V_46 :
V_43 |= V_47 ;
break;
case V_48 :
V_43 |= V_49 ;
break;
default:
V_43 |= V_50 ;
break;
}
return V_43 ;
}
static T_4 F_18 ( const T_3 V_41 ,
const enum V_22 V_42 )
{
T_4 V_51 = V_44 | V_45 ;
V_51 |= V_41 ;
if ( V_42 != V_46 )
V_51 |= V_52 ;
else
V_51 |= V_47 ;
return V_51 ;
}
static T_5 F_19 ( T_3 V_41 ,
enum V_22 V_42 ,
T_1 V_24 )
{
T_5 V_43 = V_53 ;
V_43 |= F_20 ( V_41 ) ;
switch ( V_42 ) {
case V_54 :
case V_55 :
V_43 |= V_56 ;
break;
case V_46 :
V_43 |= V_57 ;
break;
default:
F_21 ( V_42 ) ;
}
return V_43 ;
}
static T_5 F_22 ( T_3 V_41 ,
enum V_22 V_42 ,
T_1 V_24 )
{
T_5 V_43 = V_53 ;
V_43 |= F_20 ( V_41 ) ;
switch ( V_42 ) {
case V_54 :
V_43 |= V_58 ;
break;
case V_55 :
V_43 |= V_56 ;
break;
case V_46 :
V_43 |= V_57 ;
break;
default:
F_21 ( V_42 ) ;
}
return V_43 ;
}
static T_5 F_23 ( T_3 V_41 ,
enum V_22 V_42 ,
T_1 V_27 )
{
T_5 V_43 = V_53 ;
V_43 |= F_20 ( V_41 ) ;
if ( ! ( V_27 & V_38 ) )
V_43 |= V_59 ;
if ( V_42 != V_46 )
V_43 |= V_60 ;
return V_43 ;
}
static T_5 F_24 ( T_3 V_41 ,
enum V_22 V_42 ,
T_1 V_24 )
{
T_5 V_43 = V_53 ;
V_43 |= F_25 ( V_41 ) ;
if ( V_42 != V_46 )
V_43 |= V_61 ;
return V_43 ;
}
static T_5 F_26 ( T_3 V_41 ,
enum V_22 V_42 ,
T_1 V_24 )
{
T_5 V_43 = V_53 ;
V_43 |= F_25 ( V_41 ) ;
switch ( V_42 ) {
case V_46 :
break;
case V_48 :
V_43 |= V_62 ;
break;
default:
V_43 |= V_63 ;
break;
}
return V_43 ;
}
static struct V_64 * F_27 ( struct V_65 * V_29 , T_6 V_66 )
{
struct V_64 * V_64 ;
if ( F_28 ( F_29 ( & V_29 -> V_67 , 1 ) ) )
F_30 ( V_29 -> V_7 ) ;
if ( V_29 -> V_68 . V_69 )
return V_29 -> V_68 . V_34 [ -- V_29 -> V_68 . V_69 ] ;
V_64 = F_31 ( V_66 ) ;
if ( ! V_64 )
return NULL ;
if ( V_29 -> V_70 )
F_32 ( & V_64 , 1 ) ;
return V_64 ;
}
static void F_33 ( struct V_65 * V_29 )
{
F_34 ( ! F_35 ( & V_29 -> V_68 ) ) ;
if ( V_29 -> V_70 )
F_36 ( V_29 -> V_68 . V_34 ,
F_35 ( & V_29 -> V_68 ) ) ;
F_37 ( & V_29 -> V_68 ) ;
}
static void F_38 ( struct V_65 * V_29 , struct V_64 * V_64 )
{
if ( ! F_39 ( & V_29 -> V_68 , V_64 ) )
F_33 ( V_29 ) ;
}
static int F_40 ( struct V_65 * V_29 ,
struct V_71 * V_72 ,
T_6 V_66 )
{
V_72 -> V_64 = F_27 ( V_29 , V_66 | V_73 | V_74 ) ;
if ( F_41 ( ! V_72 -> V_64 ) )
return - V_75 ;
V_72 -> V_76 = F_42 ( V_29 -> V_77 , V_72 -> V_64 , 0 , V_78 ,
V_79 ) ;
if ( F_41 ( F_43 ( V_29 -> V_77 , V_72 -> V_76 ) ) ) {
F_38 ( V_29 , V_72 -> V_64 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_44 ( struct V_65 * V_29 ,
struct V_71 * V_72 )
{
return F_40 ( V_29 , V_72 , V_80 ) ;
}
static void F_45 ( struct V_65 * V_29 ,
struct V_71 * V_72 )
{
F_46 ( V_29 -> V_77 , V_72 -> V_76 , V_78 , V_79 ) ;
F_38 ( V_29 , V_72 -> V_64 ) ;
}
static void F_47 ( struct V_65 * V_29 ,
struct V_71 * V_72 ,
const T_7 V_81 )
{
T_7 * const V_82 = F_48 ( V_72 -> V_64 ) ;
int V_83 ;
for ( V_83 = 0 ; V_83 < 512 ; V_83 ++ )
V_82 [ V_83 ] = V_81 ;
F_49 ( V_82 ) ;
}
static void F_50 ( struct V_65 * V_29 ,
struct V_71 * V_72 ,
const T_1 V_84 )
{
F_47 ( V_29 , V_72 , ( T_7 ) V_84 << 32 | V_84 ) ;
}
static int
F_51 ( struct V_65 * V_29 , T_6 V_66 )
{
return F_40 ( V_29 , & V_29 -> V_85 , V_66 | V_86 ) ;
}
static void F_52 ( struct V_65 * V_29 )
{
F_45 ( V_29 , & V_29 -> V_85 ) ;
}
static struct V_87 * F_53 ( struct V_65 * V_29 )
{
struct V_87 * V_88 ;
V_88 = F_54 ( sizeof( * V_88 ) , V_89 | V_73 ) ;
if ( F_41 ( ! V_88 ) )
return F_55 ( - V_75 ) ;
if ( F_41 ( F_56 ( V_29 , V_88 ) ) ) {
F_57 ( V_88 ) ;
return F_55 ( - V_75 ) ;
}
V_88 -> V_90 = 0 ;
return V_88 ;
}
static void F_58 ( struct V_65 * V_29 , struct V_87 * V_88 )
{
F_59 ( V_29 , V_88 ) ;
F_57 ( V_88 ) ;
}
static void F_60 ( struct V_65 * V_29 ,
struct V_87 * V_88 )
{
F_61 ( V_29 , V_88 ,
F_17 ( V_29 -> V_85 . V_76 , V_55 ) ) ;
}
static void F_62 ( struct V_65 * V_29 ,
struct V_87 * V_88 )
{
F_63 ( V_29 , V_88 ,
V_29 -> V_91 ( V_29 -> V_85 . V_76 , V_55 , 0 ) ) ;
}
static struct V_92 * F_64 ( struct V_65 * V_29 )
{
struct V_92 * V_93 ;
V_93 = F_65 ( sizeof( * V_93 ) , V_89 | V_73 ) ;
if ( F_41 ( ! V_93 ) )
return F_55 ( - V_75 ) ;
if ( F_41 ( F_56 ( V_29 , V_93 ) ) ) {
F_57 ( V_93 ) ;
return F_55 ( - V_75 ) ;
}
V_93 -> V_94 = 0 ;
return V_93 ;
}
static void F_66 ( struct V_65 * V_29 ,
struct V_92 * V_93 )
{
F_59 ( V_29 , V_93 ) ;
F_57 ( V_93 ) ;
}
static void F_67 ( struct V_65 * V_29 ,
struct V_92 * V_93 )
{
unsigned int V_83 ;
F_61 ( V_29 , V_93 ,
F_18 ( F_68 ( V_29 -> V_95 ) , V_55 ) ) ;
for ( V_83 = 0 ; V_83 < V_96 ; V_83 ++ )
V_93 -> V_97 [ V_83 ] = V_29 -> V_95 ;
}
static int F_69 ( struct V_65 * V_29 ,
struct V_98 * V_99 )
{
const unsigned int V_100 = F_70 ( V_29 ) ;
unsigned int V_83 ;
V_99 -> V_101 = F_71 ( V_100 , sizeof( * V_99 -> V_101 ) ,
V_89 | V_73 ) ;
if ( F_41 ( ! V_99 -> V_101 ) )
return - V_75 ;
for ( V_83 = 0 ; V_83 < V_100 ; V_83 ++ )
V_99 -> V_101 [ V_83 ] = V_29 -> V_102 ;
return 0 ;
}
static void F_72 ( struct V_98 * V_99 )
{
F_57 ( V_99 -> V_101 ) ;
V_99 -> V_101 = NULL ;
}
static inline bool F_73 ( const struct V_65 * V_29 )
{
return F_74 ( V_29 ) ;
}
static struct V_98 *
F_75 ( struct V_65 * V_29 )
{
struct V_98 * V_99 ;
int V_26 = - V_75 ;
F_76 ( ! F_73 ( V_29 ) ) ;
V_99 = F_65 ( sizeof( * V_99 ) , V_89 ) ;
if ( ! V_99 )
return F_55 ( - V_75 ) ;
V_26 = F_69 ( V_29 , V_99 ) ;
if ( V_26 )
goto V_103;
V_26 = F_56 ( V_29 , V_99 ) ;
if ( V_26 )
goto V_104;
return V_99 ;
V_104:
F_72 ( V_99 ) ;
V_103:
F_57 ( V_99 ) ;
return F_55 ( V_26 ) ;
}
static void F_77 ( struct V_65 * V_29 ,
struct V_98 * V_99 )
{
F_72 ( V_99 ) ;
if ( ! F_73 ( V_29 ) )
return;
F_59 ( V_29 , V_99 ) ;
F_57 ( V_99 ) ;
}
static void F_78 ( struct V_65 * V_29 ,
struct V_98 * V_99 )
{
T_8 V_105 ;
V_105 = F_79 ( F_68 ( V_29 -> V_102 ) , V_55 ) ;
F_61 ( V_29 , V_99 , V_105 ) ;
}
static void F_80 ( struct V_65 * V_29 ,
struct V_106 * V_107 )
{
unsigned int V_83 ;
F_61 ( V_29 , V_107 ,
F_81 ( F_68 ( V_29 -> V_108 ) , V_55 ) ) ;
for ( V_83 = 0 ; V_83 < V_109 ; V_83 ++ )
V_107 -> V_110 [ V_83 ] = V_29 -> V_108 ;
}
static int F_82 ( struct V_111 * V_112 ,
unsigned V_113 ,
T_3 V_41 )
{
struct V_114 * V_115 = V_112 -> V_115 ;
T_1 * V_116 ;
F_83 ( V_113 >= 4 ) ;
V_116 = F_84 ( V_112 , 6 ) ;
if ( F_85 ( V_116 ) )
return F_86 ( V_116 ) ;
* V_116 ++ = F_87 ( 1 ) ;
* V_116 ++ = F_88 ( F_89 ( V_115 , V_113 ) ) ;
* V_116 ++ = F_90 ( V_41 ) ;
* V_116 ++ = F_87 ( 1 ) ;
* V_116 ++ = F_88 ( F_91 ( V_115 , V_113 ) ) ;
* V_116 ++ = F_92 ( V_41 ) ;
F_93 ( V_112 , V_116 ) ;
return 0 ;
}
static int F_94 ( struct V_117 * V_118 ,
struct V_111 * V_112 )
{
int V_83 , V_26 ;
for ( V_83 = V_119 - 1 ; V_83 >= 0 ; V_83 -- ) {
const T_3 V_120 = F_95 ( V_118 , V_83 ) ;
V_26 = F_82 ( V_112 , V_83 , V_120 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
static int F_96 ( struct V_117 * V_118 ,
struct V_111 * V_112 )
{
return F_82 ( V_112 , 0 , F_68 ( & V_118 -> V_107 ) ) ;
}
static void F_97 ( struct V_117 * V_118 )
{
V_118 -> V_121 = F_98 ( V_118 -> V_122 . V_7 ) -> V_123 ;
}
static bool F_99 ( struct V_65 * V_29 ,
struct V_87 * V_88 ,
T_7 V_32 , T_7 V_124 )
{
unsigned int V_125 = F_100 ( V_32 , V_124 ) ;
unsigned int V_43 = F_101 ( V_32 ) ;
unsigned int V_126 = V_43 + V_125 ;
const T_2 V_127 =
F_17 ( V_29 -> V_85 . V_76 , V_55 ) ;
T_2 * V_82 ;
F_34 ( V_125 > V_88 -> V_90 ) ;
V_88 -> V_90 -= V_125 ;
if ( ! V_88 -> V_90 )
return true ;
V_82 = F_102 ( V_88 ) ;
while ( V_43 < V_126 )
V_82 [ V_43 ++ ] = V_127 ;
F_49 ( V_82 ) ;
return false ;
}
static void F_103 ( struct V_65 * V_29 ,
struct V_92 * V_93 ,
struct V_87 * V_88 ,
unsigned int V_51 )
{
T_4 * V_82 ;
V_93 -> V_97 [ V_51 ] = V_88 ;
V_82 = F_102 ( V_93 ) ;
V_82 [ V_51 ] = F_18 ( F_68 ( V_88 ) , V_55 ) ;
F_49 ( V_82 ) ;
}
static bool F_104 ( struct V_65 * V_29 ,
struct V_92 * V_93 ,
T_7 V_32 , T_7 V_124 )
{
struct V_87 * V_88 ;
T_1 V_51 ;
F_105 (pt, pd, start, length, pde) {
F_34 ( V_88 == V_29 -> V_95 ) ;
if ( ! F_99 ( V_29 , V_88 , V_32 , V_124 ) )
continue;
F_103 ( V_29 , V_93 , V_29 -> V_95 , V_51 ) ;
F_34 ( ! V_93 -> V_94 ) ;
V_93 -> V_94 -- ;
F_58 ( V_29 , V_88 ) ;
}
return ! V_93 -> V_94 ;
}
static void F_106 ( struct V_65 * V_29 ,
struct V_98 * V_99 ,
struct V_92 * V_93 ,
unsigned int V_128 )
{
T_8 * V_82 ;
V_99 -> V_101 [ V_128 ] = V_93 ;
if ( ! F_73 ( V_29 ) )
return;
V_82 = F_102 ( V_99 ) ;
V_82 [ V_128 ] = F_79 ( F_68 ( V_93 ) , V_55 ) ;
F_49 ( V_82 ) ;
}
static bool F_107 ( struct V_65 * V_29 ,
struct V_98 * V_99 ,
T_7 V_32 , T_7 V_124 )
{
struct V_92 * V_93 ;
unsigned int V_128 ;
F_108 (pd, pdp, start, length, pdpe) {
F_34 ( V_93 == V_29 -> V_102 ) ;
if ( ! F_104 ( V_29 , V_93 , V_32 , V_124 ) )
continue;
F_106 ( V_29 , V_99 , V_29 -> V_102 , V_128 ) ;
F_34 ( ! V_99 -> V_129 ) ;
V_99 -> V_129 -- ;
F_66 ( V_29 , V_93 ) ;
}
return ! V_99 -> V_129 ;
}
static void F_109 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
F_107 ( V_29 , & F_110 ( V_29 ) -> V_99 , V_32 , V_124 ) ;
}
static void F_111 ( struct V_106 * V_107 ,
struct V_98 * V_99 ,
unsigned int V_130 )
{
T_9 * V_82 ;
V_107 -> V_110 [ V_130 ] = V_99 ;
V_82 = F_102 ( V_107 ) ;
V_82 [ V_130 ] = F_81 ( F_68 ( V_99 ) , V_55 ) ;
F_49 ( V_82 ) ;
}
static void F_112 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
struct V_106 * V_107 = & V_118 -> V_107 ;
struct V_98 * V_99 ;
unsigned int V_130 ;
F_34 ( ! F_73 ( V_29 ) ) ;
F_113 (pdp, pml4, start, length, pml4e) {
F_34 ( V_99 == V_29 -> V_108 ) ;
if ( ! F_107 ( V_29 , V_99 , V_32 , V_124 ) )
continue;
F_111 ( V_107 , V_29 -> V_108 , V_130 ) ;
F_77 ( V_29 , V_99 ) ;
}
}
static T_10 bool
F_114 ( struct V_117 * V_118 ,
struct V_98 * V_99 ,
struct V_131 * V_132 ,
struct V_133 * V_134 ,
enum V_22 V_23 )
{
struct V_92 * V_93 ;
const T_2 V_91 = F_17 ( 0 , V_23 ) ;
T_2 * V_82 ;
bool V_26 ;
F_34 ( V_134 -> V_128 >= F_70 ( & V_118 -> V_122 ) ) ;
V_93 = V_99 -> V_101 [ V_134 -> V_128 ] ;
V_82 = F_102 ( V_93 -> V_97 [ V_134 -> V_51 ] ) ;
do {
V_82 [ V_134 -> V_43 ] = V_91 | V_132 -> V_77 ;
V_132 -> V_77 += V_78 ;
if ( V_132 -> V_77 >= V_132 -> V_135 ) {
V_132 -> V_136 = F_115 ( V_132 -> V_136 ) ;
if ( ! V_132 -> V_136 ) {
V_26 = false ;
break;
}
V_132 -> V_77 = F_116 ( V_132 -> V_136 ) ;
V_132 -> V_135 = V_132 -> V_77 + V_132 -> V_136 -> V_124 ;
}
if ( ++ V_134 -> V_43 == V_137 ) {
V_134 -> V_43 = 0 ;
if ( ++ V_134 -> V_51 == V_96 ) {
V_134 -> V_51 = 0 ;
if ( ++ V_134 -> V_128 == V_109 ) {
V_134 -> V_128 = 0 ;
V_26 = true ;
break;
}
F_34 ( V_134 -> V_128 >= F_70 ( & V_118 -> V_122 ) ) ;
V_93 = V_99 -> V_101 [ V_134 -> V_128 ] ;
}
F_49 ( V_82 ) ;
V_82 = F_102 ( V_93 -> V_97 [ V_134 -> V_51 ] ) ;
}
} while ( 1 );
F_49 ( V_82 ) ;
return V_26 ;
}
static void F_117 ( struct V_65 * V_29 ,
struct V_138 * V_34 ,
T_7 V_32 ,
enum V_22 V_23 ,
T_1 V_24 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
struct V_131 V_132 = {
. V_136 = V_34 -> V_139 ,
. V_77 = F_116 ( V_132 . V_136 ) ,
. V_135 = V_132 . V_77 + V_132 . V_136 -> V_124 ,
} ;
struct V_133 V_134 = V_133 ( V_32 ) ;
F_114 ( V_118 , & V_118 -> V_99 , & V_132 , & V_134 ,
V_23 ) ;
}
static void F_118 ( struct V_65 * V_29 ,
struct V_138 * V_34 ,
T_7 V_32 ,
enum V_22 V_23 ,
T_1 V_24 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
struct V_131 V_132 = {
. V_136 = V_34 -> V_139 ,
. V_77 = F_116 ( V_132 . V_136 ) ,
. V_135 = V_132 . V_77 + V_132 . V_136 -> V_124 ,
} ;
struct V_98 * * V_110 = V_118 -> V_107 . V_110 ;
struct V_133 V_134 = V_133 ( V_32 ) ;
while ( F_114 ( V_118 , V_110 [ V_134 . V_130 ++ ] , & V_132 ,
& V_134 , V_23 ) )
F_34 ( V_134 . V_130 >= V_109 ) ;
}
static void F_119 ( struct V_65 * V_29 ,
struct V_92 * V_93 )
{
int V_83 ;
if ( ! F_120 ( V_93 ) )
return;
for ( V_83 = 0 ; V_83 < V_96 ; V_83 ++ ) {
if ( V_93 -> V_97 [ V_83 ] != V_29 -> V_95 )
F_58 ( V_29 , V_93 -> V_97 [ V_83 ] ) ;
}
}
static int F_121 ( struct V_65 * V_29 )
{
int V_26 ;
V_26 = F_51 ( V_29 , V_80 ) ;
if ( V_26 )
return V_26 ;
V_29 -> V_95 = F_53 ( V_29 ) ;
if ( F_85 ( V_29 -> V_95 ) ) {
V_26 = F_86 ( V_29 -> V_95 ) ;
goto V_140;
}
V_29 -> V_102 = F_64 ( V_29 ) ;
if ( F_85 ( V_29 -> V_102 ) ) {
V_26 = F_86 ( V_29 -> V_102 ) ;
goto F_58;
}
if ( F_73 ( V_29 ) ) {
V_29 -> V_108 = F_75 ( V_29 ) ;
if ( F_85 ( V_29 -> V_108 ) ) {
V_26 = F_86 ( V_29 -> V_108 ) ;
goto F_66;
}
}
F_60 ( V_29 , V_29 -> V_95 ) ;
F_67 ( V_29 , V_29 -> V_102 ) ;
if ( F_73 ( V_29 ) )
F_78 ( V_29 , V_29 -> V_108 ) ;
return 0 ;
F_66:
F_66 ( V_29 , V_29 -> V_102 ) ;
F_58:
F_58 ( V_29 , V_29 -> V_95 ) ;
V_140:
F_52 ( V_29 ) ;
return V_26 ;
}
static int F_122 ( struct V_117 * V_118 , bool V_141 )
{
struct V_65 * V_29 = & V_118 -> V_122 ;
struct V_1 * V_2 = V_29 -> V_7 ;
enum V_142 V_143 ;
int V_83 ;
if ( F_73 ( V_29 ) ) {
const T_7 V_76 = F_68 ( & V_118 -> V_107 ) ;
F_2 ( F_123 ( V_99 [ 0 ] . V_144 ) , F_92 ( V_76 ) ) ;
F_2 ( F_123 ( V_99 [ 0 ] . V_145 ) , F_90 ( V_76 ) ) ;
V_143 = ( V_141 ? V_146 :
V_147 ) ;
} else {
for ( V_83 = 0 ; V_83 < V_119 ; V_83 ++ ) {
const T_7 V_76 = F_95 ( V_118 , V_83 ) ;
F_2 ( F_123 ( V_99 [ V_83 ] . V_144 ) , F_92 ( V_76 ) ) ;
F_2 ( F_123 ( V_99 [ V_83 ] . V_145 ) , F_90 ( V_76 ) ) ;
}
V_143 = ( V_141 ? V_148 :
V_149 ) ;
}
F_2 ( F_123 ( V_150 ) , V_143 ) ;
return 0 ;
}
static void F_124 ( struct V_65 * V_29 )
{
if ( F_73 ( V_29 ) )
F_77 ( V_29 , V_29 -> V_108 ) ;
F_66 ( V_29 , V_29 -> V_102 ) ;
F_58 ( V_29 , V_29 -> V_95 ) ;
F_52 ( V_29 ) ;
}
static void F_125 ( struct V_65 * V_29 ,
struct V_98 * V_99 )
{
const unsigned int V_100 = F_70 ( V_29 ) ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_100 ; V_83 ++ ) {
if ( V_99 -> V_101 [ V_83 ] == V_29 -> V_102 )
continue;
F_119 ( V_29 , V_99 -> V_101 [ V_83 ] ) ;
F_66 ( V_29 , V_99 -> V_101 [ V_83 ] ) ;
}
F_77 ( V_29 , V_99 ) ;
}
static void F_126 ( struct V_117 * V_118 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_109 ; V_83 ++ ) {
if ( V_118 -> V_107 . V_110 [ V_83 ] == V_118 -> V_122 . V_108 )
continue;
F_125 ( & V_118 -> V_122 , V_118 -> V_107 . V_110 [ V_83 ] ) ;
}
F_59 ( & V_118 -> V_122 , & V_118 -> V_107 ) ;
}
static void F_127 ( struct V_65 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_7 ;
struct V_117 * V_118 = F_110 ( V_29 ) ;
if ( F_8 ( V_2 ) )
F_122 ( V_118 , false ) ;
if ( F_73 ( V_29 ) )
F_126 ( V_118 ) ;
else
F_125 ( & V_118 -> V_122 , & V_118 -> V_99 ) ;
F_124 ( V_29 ) ;
}
static int F_128 ( struct V_65 * V_29 ,
struct V_92 * V_93 ,
T_7 V_32 , T_7 V_124 )
{
struct V_87 * V_88 ;
T_7 V_151 = V_32 ;
unsigned int V_51 ;
F_105 (pt, pd, start, length, pde) {
if ( V_88 == V_29 -> V_95 ) {
V_88 = F_53 ( V_29 ) ;
if ( F_85 ( V_88 ) )
goto V_152;
F_60 ( V_29 , V_88 ) ;
F_103 ( V_29 , V_93 , V_88 , V_51 ) ;
V_93 -> V_94 ++ ;
F_34 ( V_93 -> V_94 > V_96 ) ;
}
V_88 -> V_90 += F_100 ( V_32 , V_124 ) ;
}
return 0 ;
V_152:
F_104 ( V_29 , V_93 , V_151 , V_32 - V_151 ) ;
return - V_75 ;
}
static int F_129 ( struct V_65 * V_29 ,
struct V_98 * V_99 ,
T_7 V_32 , T_7 V_124 )
{
struct V_92 * V_93 ;
T_7 V_151 = V_32 ;
unsigned int V_128 ;
int V_26 ;
F_108 (pd, pdp, start, length, pdpe) {
if ( V_93 == V_29 -> V_102 ) {
V_93 = F_64 ( V_29 ) ;
if ( F_85 ( V_93 ) )
goto V_152;
F_67 ( V_29 , V_93 ) ;
F_106 ( V_29 , V_99 , V_93 , V_128 ) ;
V_99 -> V_129 ++ ;
F_34 ( V_99 -> V_129 > F_70 ( V_29 ) ) ;
F_97 ( F_110 ( V_29 ) ) ;
}
V_26 = F_128 ( V_29 , V_93 , V_32 , V_124 ) ;
if ( F_41 ( V_26 ) )
goto V_153;
}
return 0 ;
V_153:
if ( ! V_93 -> V_94 ) {
F_106 ( V_29 , V_99 , V_29 -> V_102 , V_128 ) ;
F_34 ( ! V_99 -> V_129 ) ;
V_99 -> V_129 -- ;
F_66 ( V_29 , V_93 ) ;
}
V_152:
F_107 ( V_29 , V_99 , V_151 , V_32 - V_151 ) ;
return - V_75 ;
}
static int F_130 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
return F_129 ( V_29 ,
& F_110 ( V_29 ) -> V_99 , V_32 , V_124 ) ;
}
static int F_131 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
struct V_106 * V_107 = & V_118 -> V_107 ;
struct V_98 * V_99 ;
T_7 V_151 = V_32 ;
T_1 V_130 ;
int V_26 ;
F_113 (pdp, pml4, start, length, pml4e) {
if ( V_107 -> V_110 [ V_130 ] == V_29 -> V_108 ) {
V_99 = F_75 ( V_29 ) ;
if ( F_85 ( V_99 ) )
goto V_152;
F_78 ( V_29 , V_99 ) ;
F_111 ( V_107 , V_99 , V_130 ) ;
}
V_26 = F_129 ( V_29 , V_99 , V_32 , V_124 ) ;
if ( F_41 ( V_26 ) )
goto V_154;
}
return 0 ;
V_154:
if ( ! V_99 -> V_129 ) {
F_111 ( V_107 , V_29 -> V_108 , V_130 ) ;
F_77 ( V_29 , V_99 ) ;
}
V_152:
F_112 ( V_29 , V_151 , V_32 - V_151 ) ;
return - V_75 ;
}
static void F_132 ( struct V_117 * V_118 ,
struct V_98 * V_99 ,
T_7 V_32 , T_7 V_124 ,
T_2 V_127 ,
struct V_155 * V_156 )
{
struct V_65 * V_29 = & V_118 -> V_122 ;
struct V_92 * V_93 ;
T_1 V_128 ;
F_108 (pd, pdp, start, length, pdpe) {
struct V_87 * V_88 ;
T_7 V_157 = V_124 ;
T_7 V_158 = V_32 ;
T_1 V_51 ;
if ( V_99 -> V_101 [ V_128 ] == V_118 -> V_122 . V_102 )
continue;
F_133 ( V_156 , L_3 , V_128 ) ;
F_105 (pt, pd, pd_start, pd_len, pde) {
T_1 V_43 ;
T_2 * V_159 ;
if ( V_93 -> V_97 [ V_51 ] == V_118 -> V_122 . V_95 )
continue;
V_159 = F_102 ( V_88 ) ;
for ( V_43 = 0 ; V_43 < V_137 ; V_43 += 4 ) {
T_7 V_160 = ( V_128 << V_161 |
V_51 << V_162 |
V_43 << V_163 ) ;
int V_83 ;
bool V_164 = false ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ )
if ( V_159 [ V_43 + V_83 ] != V_127 )
V_164 = true ;
if ( ! V_164 )
continue;
F_133 ( V_156 , L_4 , V_160 , V_128 , V_51 , V_43 ) ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ ) {
if ( V_159 [ V_43 + V_83 ] != V_127 )
F_133 ( V_156 , L_5 , V_159 [ V_43 + V_83 ] ) ;
else
F_134 ( V_156 , L_6 ) ;
}
F_134 ( V_156 , L_7 ) ;
}
F_49 ( V_159 ) ;
}
}
}
static void F_135 ( struct V_117 * V_118 , struct V_155 * V_156 )
{
struct V_65 * V_29 = & V_118 -> V_122 ;
const T_2 V_127 =
F_17 ( V_29 -> V_85 . V_76 , V_55 ) ;
T_7 V_32 = 0 , V_124 = V_118 -> V_122 . V_165 ;
if ( F_73 ( V_29 ) ) {
T_7 V_130 ;
struct V_106 * V_107 = & V_118 -> V_107 ;
struct V_98 * V_99 ;
F_113 (pdp, pml4, start, length, pml4e) {
if ( V_107 -> V_110 [ V_130 ] == V_118 -> V_122 . V_108 )
continue;
F_133 ( V_156 , L_8 , V_130 ) ;
F_132 ( V_118 , V_99 , V_32 , V_124 , V_127 , V_156 ) ;
}
} else {
F_132 ( V_118 , & V_118 -> V_99 , V_32 , V_124 , V_127 , V_156 ) ;
}
}
static int F_136 ( struct V_117 * V_118 )
{
struct V_65 * V_29 = & V_118 -> V_122 ;
struct V_98 * V_99 = & V_118 -> V_99 ;
struct V_92 * V_93 ;
T_7 V_32 = 0 , V_124 = V_118 -> V_122 . V_165 ;
T_7 V_151 = V_32 ;
unsigned int V_128 ;
F_108 (pd, pdp, start, length, pdpe) {
V_93 = F_64 ( V_29 ) ;
if ( F_85 ( V_93 ) )
goto V_152;
F_67 ( V_29 , V_93 ) ;
F_106 ( V_29 , V_99 , V_93 , V_128 ) ;
V_99 -> V_129 ++ ;
}
V_99 -> V_129 ++ ;
return 0 ;
V_152:
V_32 -= V_151 ;
F_108 (pd, pdp, from, start, pdpe) {
F_106 ( V_29 , V_99 , V_29 -> V_102 , V_128 ) ;
F_66 ( V_29 , V_93 ) ;
}
V_99 -> V_129 = 0 ;
return - V_75 ;
}
static int F_137 ( struct V_117 * V_118 )
{
struct V_65 * V_29 = & V_118 -> V_122 ;
struct V_1 * V_2 = V_29 -> V_7 ;
int V_26 ;
V_118 -> V_122 . V_165 = F_138 ( V_2 ) ?
1ULL << 48 :
1ULL << 32 ;
V_26 = F_121 ( & V_118 -> V_122 ) ;
if ( V_26 ) {
V_118 -> V_122 . V_165 = 0 ;
return V_26 ;
}
if ( F_139 ( V_2 ) || F_140 ( V_2 ) )
V_118 -> V_122 . V_70 = true ;
if ( F_73 ( V_29 ) ) {
V_26 = F_56 ( & V_118 -> V_122 , & V_118 -> V_107 ) ;
if ( V_26 )
goto V_166;
F_80 ( & V_118 -> V_122 , & V_118 -> V_107 ) ;
V_118 -> V_167 = F_96 ;
V_118 -> V_122 . V_30 = F_131 ;
V_118 -> V_122 . V_39 = F_118 ;
V_118 -> V_122 . V_40 = F_112 ;
} else {
V_26 = F_69 ( & V_118 -> V_122 , & V_118 -> V_99 ) ;
if ( V_26 )
goto V_166;
if ( F_8 ( V_2 ) ) {
V_26 = F_136 ( V_118 ) ;
if ( V_26 ) {
F_72 ( & V_118 -> V_99 ) ;
goto V_166;
}
}
V_118 -> V_167 = F_94 ;
V_118 -> V_122 . V_30 = F_130 ;
V_118 -> V_122 . V_39 = F_117 ;
V_118 -> V_122 . V_40 = F_109 ;
}
if ( F_8 ( V_2 ) )
F_122 ( V_118 , true ) ;
V_118 -> V_122 . V_168 = F_127 ;
V_118 -> V_122 . V_169 = F_16 ;
V_118 -> V_122 . V_170 = F_15 ;
V_118 -> V_171 = F_135 ;
return 0 ;
V_166:
F_124 ( & V_118 -> V_122 ) ;
return V_26 ;
}
static void F_141 ( struct V_117 * V_118 , struct V_155 * V_156 )
{
struct V_65 * V_29 = & V_118 -> V_122 ;
struct V_87 * V_24 ;
T_5 V_127 ;
T_1 V_172 , V_43 , V_51 ;
T_1 V_32 = 0 , V_124 = V_118 -> V_122 . V_165 ;
V_127 = V_29 -> V_91 ( V_29 -> V_85 . V_76 ,
V_55 , 0 ) ;
F_142 (unused, &ppgtt->pd, start, length, pde) {
T_1 V_173 ;
T_5 * V_159 ;
const T_3 V_174 = F_68 ( V_118 -> V_93 . V_97 [ V_51 ] ) ;
V_172 = F_143 ( V_118 -> V_175 + V_51 ) ;
V_173 = ( F_144 ( V_174 ) | V_176 ) ;
if ( V_172 != V_173 )
F_133 ( V_156 , L_9 ,
V_51 ,
V_172 ,
V_173 ) ;
F_133 ( V_156 , L_10 , V_172 ) ;
V_159 = F_102 ( V_118 -> V_93 . V_97 [ V_51 ] ) ;
for ( V_43 = 0 ; V_43 < V_177 ; V_43 += 4 ) {
unsigned long V_160 =
( V_51 * V_78 * V_177 ) +
( V_43 * V_78 ) ;
int V_83 ;
bool V_164 = false ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ )
if ( V_159 [ V_43 + V_83 ] != V_127 )
V_164 = true ;
if ( ! V_164 )
continue;
F_133 ( V_156 , L_11 , V_160 , V_51 , V_43 ) ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ ) {
if ( V_159 [ V_43 + V_83 ] != V_127 )
F_133 ( V_156 , L_12 , V_159 [ V_43 + V_83 ] ) ;
else
F_134 ( V_156 , L_6 ) ;
}
F_134 ( V_156 , L_7 ) ;
}
F_49 ( V_159 ) ;
}
}
static inline void F_145 ( const struct V_117 * V_118 ,
const unsigned int V_51 ,
const struct V_87 * V_88 )
{
F_146 ( F_144 ( F_68 ( V_88 ) ) | V_176 ,
V_118 -> V_175 + V_51 ) ;
}
static void F_147 ( struct V_117 * V_118 ,
T_1 V_32 , T_1 V_124 )
{
struct V_87 * V_88 ;
unsigned int V_51 ;
F_142 (pt, &ppgtt->pd, start, length, pde)
F_145 ( V_118 , V_51 , V_88 ) ;
F_97 ( V_118 ) ;
F_148 () ;
}
static inline T_1 F_149 ( struct V_117 * V_118 )
{
F_34 ( V_118 -> V_93 . V_122 . V_178 & 0x3f ) ;
return V_118 -> V_93 . V_122 . V_178 << 10 ;
}
static int F_150 ( struct V_117 * V_118 ,
struct V_111 * V_112 )
{
struct V_114 * V_115 = V_112 -> V_115 ;
T_1 * V_116 ;
V_116 = F_84 ( V_112 , 6 ) ;
if ( F_85 ( V_116 ) )
return F_86 ( V_116 ) ;
* V_116 ++ = F_87 ( 2 ) ;
* V_116 ++ = F_88 ( F_151 ( V_115 ) ) ;
* V_116 ++ = V_179 ;
* V_116 ++ = F_88 ( F_152 ( V_115 ) ) ;
* V_116 ++ = F_149 ( V_118 ) ;
* V_116 ++ = V_180 ;
F_93 ( V_112 , V_116 ) ;
return 0 ;
}
static int F_153 ( struct V_117 * V_118 ,
struct V_111 * V_112 )
{
struct V_114 * V_115 = V_112 -> V_115 ;
T_1 * V_116 ;
V_116 = F_84 ( V_112 , 6 ) ;
if ( F_85 ( V_116 ) )
return F_86 ( V_116 ) ;
* V_116 ++ = F_87 ( 2 ) ;
* V_116 ++ = F_88 ( F_151 ( V_115 ) ) ;
* V_116 ++ = V_179 ;
* V_116 ++ = F_88 ( F_152 ( V_115 ) ) ;
* V_116 ++ = F_149 ( V_118 ) ;
* V_116 ++ = V_180 ;
F_93 ( V_112 , V_116 ) ;
return 0 ;
}
static int F_154 ( struct V_117 * V_118 ,
struct V_111 * V_112 )
{
struct V_114 * V_115 = V_112 -> V_115 ;
struct V_1 * V_2 = V_112 -> V_7 ;
F_2 ( F_151 ( V_115 ) , V_179 ) ;
F_2 ( F_152 ( V_115 ) , F_149 ( V_118 ) ) ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_114 * V_115 ;
enum V_181 V_182 ;
F_156 (engine, dev_priv, id) {
T_1 V_183 = F_138 ( V_2 ) ?
V_184 : 0 ;
F_2 ( F_157 ( V_115 ) ,
F_158 ( V_185 | V_183 ) ) ;
}
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_114 * V_115 ;
T_1 V_186 , V_187 ;
enum V_181 V_182 ;
V_187 = F_160 ( V_188 ) ;
F_2 ( V_188 , V_187 | V_189 ) ;
V_186 = F_160 ( V_190 ) ;
if ( F_161 ( V_2 ) ) {
V_186 |= V_191 ;
} else {
V_186 |= V_192 ;
V_186 &= ~ V_193 ;
}
F_2 ( V_190 , V_186 ) ;
F_156 (engine, dev_priv, id) {
F_2 ( F_157 ( V_115 ) ,
F_158 ( V_185 ) ) ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
T_1 V_186 , V_194 , V_187 ;
V_187 = F_160 ( V_188 ) ;
F_2 ( V_188 , V_187 | V_195 |
V_189 ) ;
V_194 = F_160 ( V_196 ) ;
F_2 ( V_196 , V_194 | V_197 ) ;
V_186 = F_160 ( V_190 ) ;
F_2 ( V_190 , V_186 | V_198 | V_199 ) ;
F_2 ( V_200 , F_158 ( V_185 ) ) ;
}
static void F_163 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
unsigned int V_201 = V_32 >> V_202 ;
unsigned int V_51 = V_201 / V_177 ;
unsigned int V_43 = V_201 % V_177 ;
unsigned int V_125 = V_124 >> V_202 ;
T_5 V_127 =
V_29 -> V_91 ( V_29 -> V_85 . V_76 , V_55 , 0 ) ;
while ( V_125 ) {
struct V_87 * V_88 = V_118 -> V_93 . V_97 [ V_51 ++ ] ;
unsigned int V_203 = F_164 ( V_43 + V_125 , V_177 ) ;
T_5 * V_82 ;
V_125 -= V_203 - V_43 ;
V_82 = F_102 ( V_88 ) ;
do {
V_82 [ V_43 ++ ] = V_127 ;
} while ( V_43 < V_203 );
F_49 ( V_82 ) ;
V_43 = 0 ;
}
}
static void F_165 ( struct V_65 * V_29 ,
struct V_138 * V_34 ,
T_7 V_32 ,
enum V_22 V_23 ,
T_1 V_27 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
unsigned V_201 = V_32 >> V_202 ;
unsigned V_204 = V_201 / V_177 ;
unsigned V_205 = V_201 % V_177 ;
const T_1 V_91 = V_29 -> V_91 ( 0 , V_23 , V_27 ) ;
struct V_131 V_132 ;
T_5 * V_82 ;
V_82 = F_102 ( V_118 -> V_93 . V_97 [ V_204 ] ) ;
V_132 . V_136 = V_34 -> V_139 ;
V_132 . V_77 = F_116 ( V_132 . V_136 ) ;
V_132 . V_135 = V_132 . V_77 + V_132 . V_136 -> V_124 ;
do {
V_82 [ V_205 ] = V_91 | F_20 ( V_132 . V_77 ) ;
V_132 . V_77 += V_78 ;
if ( V_132 . V_77 == V_132 . V_135 ) {
V_132 . V_136 = F_115 ( V_132 . V_136 ) ;
if ( ! V_132 . V_136 )
break;
V_132 . V_77 = F_116 ( V_132 . V_136 ) ;
V_132 . V_135 = V_132 . V_77 + V_132 . V_136 -> V_124 ;
}
if ( ++ V_205 == V_177 ) {
F_49 ( V_82 ) ;
V_82 = F_102 ( V_118 -> V_93 . V_97 [ ++ V_204 ] ) ;
V_205 = 0 ;
}
} while ( 1 );
F_49 ( V_82 ) ;
}
static int F_166 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
struct V_87 * V_88 ;
T_7 V_151 = V_32 ;
unsigned int V_51 ;
bool V_206 = false ;
F_142 (pt, &ppgtt->pd, start, length, pde) {
if ( V_88 == V_29 -> V_95 ) {
V_88 = F_53 ( V_29 ) ;
if ( F_85 ( V_88 ) )
goto V_207;
F_62 ( V_29 , V_88 ) ;
V_118 -> V_93 . V_97 [ V_51 ] = V_88 ;
F_145 ( V_118 , V_51 , V_88 ) ;
V_206 = true ;
}
}
if ( V_206 ) {
F_97 ( V_118 ) ;
F_148 () ;
}
return 0 ;
V_207:
F_163 ( V_29 , V_151 , V_32 ) ;
return - V_75 ;
}
static int F_167 ( struct V_65 * V_29 )
{
int V_26 ;
V_26 = F_51 ( V_29 , V_80 ) ;
if ( V_26 )
return V_26 ;
V_29 -> V_95 = F_53 ( V_29 ) ;
if ( F_85 ( V_29 -> V_95 ) ) {
F_52 ( V_29 ) ;
return F_86 ( V_29 -> V_95 ) ;
}
F_62 ( V_29 , V_29 -> V_95 ) ;
return 0 ;
}
static void F_168 ( struct V_65 * V_29 )
{
F_58 ( V_29 , V_29 -> V_95 ) ;
F_52 ( V_29 ) ;
}
static void F_169 ( struct V_65 * V_29 )
{
struct V_117 * V_118 = F_110 ( V_29 ) ;
struct V_92 * V_93 = & V_118 -> V_93 ;
struct V_87 * V_88 ;
T_1 V_51 ;
F_170 ( & V_118 -> V_31 ) ;
F_171 (pt, pd, pde)
if ( V_88 != V_29 -> V_95 )
F_58 ( V_29 , V_88 ) ;
F_168 ( V_29 ) ;
}
static int F_172 ( struct V_117 * V_118 )
{
struct V_65 * V_29 = & V_118 -> V_122 ;
struct V_1 * V_2 = V_118 -> V_122 . V_7 ;
struct V_208 * V_8 = & V_2 -> V_8 ;
int V_26 ;
F_83 ( ! F_173 ( & V_8 -> V_122 . V_36 ) ) ;
V_26 = F_167 ( V_29 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_174 ( & V_8 -> V_122 , & V_118 -> V_31 ,
V_209 , V_210 ,
V_211 ,
0 , V_8 -> V_122 . V_165 ,
V_212 ) ;
if ( V_26 )
goto V_213;
if ( V_118 -> V_31 . V_32 < V_8 -> V_214 )
F_175 ( L_13 ) ;
V_118 -> V_93 . V_122 . V_178 =
V_118 -> V_31 . V_32 / V_78 * sizeof( T_5 ) ;
V_118 -> V_175 = ( T_5 V_215 * ) V_8 -> V_216 +
V_118 -> V_93 . V_122 . V_178 / sizeof( T_5 ) ;
return 0 ;
V_213:
F_168 ( V_29 ) ;
return V_26 ;
}
static int F_176 ( struct V_117 * V_118 )
{
return F_172 ( V_118 ) ;
}
static void F_177 ( struct V_117 * V_118 ,
T_7 V_32 , T_7 V_124 )
{
struct V_87 * V_24 ;
T_1 V_51 ;
F_142 (unused, &ppgtt->pd, start, length, pde)
V_118 -> V_93 . V_97 [ V_51 ] = V_118 -> V_122 . V_95 ;
}
static int F_178 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_122 . V_7 ;
struct V_208 * V_8 = & V_2 -> V_8 ;
int V_26 ;
V_118 -> V_122 . V_91 = V_8 -> V_122 . V_91 ;
if ( F_8 ( V_2 ) || F_11 ( V_2 ) )
V_118 -> V_167 = F_154 ;
else if ( F_161 ( V_2 ) )
V_118 -> V_167 = F_150 ;
else if ( F_179 ( V_2 ) )
V_118 -> V_167 = F_153 ;
else
F_180 () ;
V_26 = F_176 ( V_118 ) ;
if ( V_26 )
return V_26 ;
V_118 -> V_122 . V_165 = V_96 * V_177 * V_78 ;
F_177 ( V_118 , 0 , V_118 -> V_122 . V_165 ) ;
F_147 ( V_118 , 0 , V_118 -> V_122 . V_165 ) ;
V_26 = F_166 ( & V_118 -> V_122 , 0 , V_118 -> V_122 . V_165 ) ;
if ( V_26 ) {
F_169 ( & V_118 -> V_122 ) ;
return V_26 ;
}
V_118 -> V_122 . V_40 = F_163 ;
V_118 -> V_122 . V_39 = F_165 ;
V_118 -> V_122 . V_169 = F_16 ;
V_118 -> V_122 . V_170 = F_15 ;
V_118 -> V_122 . V_168 = F_169 ;
V_118 -> V_171 = F_141 ;
F_14 ( L_14 ,
V_118 -> V_31 . V_33 >> 20 ,
V_118 -> V_31 . V_32 / V_78 ) ;
F_14 ( L_15 ,
V_118 -> V_93 . V_122 . V_178 << 10 ) ;
return 0 ;
}
static int F_181 ( struct V_117 * V_118 ,
struct V_1 * V_2 )
{
V_118 -> V_122 . V_7 = V_2 ;
V_118 -> V_122 . V_77 = & V_2 -> V_16 . V_17 -> V_217 ;
if ( F_98 ( V_2 ) -> V_218 < 8 )
return F_178 ( V_118 ) ;
else
return F_137 ( V_118 ) ;
}
static void F_182 ( struct V_65 * V_29 ,
struct V_1 * V_2 ,
const char * V_219 )
{
F_183 ( V_2 , & V_29 -> V_220 , V_219 ) ;
F_184 ( & V_29 -> V_36 , 0 , V_29 -> V_165 ) ;
V_29 -> V_36 . V_221 . V_222 = V_211 ;
F_185 ( & V_29 -> V_223 ) ;
F_185 ( & V_29 -> V_224 ) ;
F_185 ( & V_29 -> V_225 ) ;
F_186 ( & V_29 -> V_226 , & V_2 -> V_227 ) ;
F_187 ( & V_29 -> V_68 , false ) ;
}
static void F_188 ( struct V_65 * V_29 )
{
if ( F_35 ( & V_29 -> V_68 ) )
F_33 ( V_29 ) ;
F_189 ( & V_29 -> V_220 ) ;
F_190 ( & V_29 -> V_36 ) ;
F_191 ( & V_29 -> V_226 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
if ( F_193 ( V_2 ) )
F_2 ( V_228 , V_229 ) ;
else if ( F_139 ( V_2 ) )
F_2 ( V_228 , V_230 ) ;
else if ( F_194 ( V_2 ) )
F_2 ( V_228 , V_231 ) ;
else if ( F_195 ( V_2 ) )
F_2 ( V_228 , V_232 ) ;
}
int F_196 ( struct V_1 * V_2 )
{
F_192 ( V_2 ) ;
if ( V_7 . V_19 )
return 0 ;
if ( ! F_197 ( V_2 ) )
return 0 ;
if ( F_11 ( V_2 ) )
F_162 ( V_2 ) ;
else if ( F_179 ( V_2 ) )
F_159 ( V_2 ) ;
else if ( F_9 ( V_2 ) >= 8 )
F_155 ( V_2 ) ;
else
F_21 ( F_9 ( V_2 ) ) ;
return 0 ;
}
struct V_117 *
F_198 ( struct V_1 * V_2 ,
struct V_233 * V_234 ,
const char * V_219 )
{
struct V_117 * V_118 ;
int V_26 ;
V_118 = F_65 ( sizeof( * V_118 ) , V_89 ) ;
if ( ! V_118 )
return F_55 ( - V_75 ) ;
V_26 = F_181 ( V_118 , V_2 ) ;
if ( V_26 ) {
F_57 ( V_118 ) ;
return F_55 ( V_26 ) ;
}
F_199 ( & V_118 -> V_235 ) ;
F_182 ( & V_118 -> V_122 , V_2 , V_219 ) ;
V_118 -> V_122 . V_236 = V_234 ;
F_200 ( & V_118 -> V_122 ) ;
return V_118 ;
}
void F_201 ( struct V_65 * V_29 )
{
struct V_237 * V_238 [] = {
& V_29 -> V_223 ,
& V_29 -> V_224 ,
& V_29 -> V_225 ,
NULL ,
} , * * V_239 ;
F_34 ( V_29 -> V_240 ) ;
V_29 -> V_240 = true ;
for ( V_239 = V_238 ; * V_239 ; V_239 ++ ) {
struct V_20 * V_21 , * V_241 ;
F_202 (vma, vn, *phase, vm_link)
if ( ! F_203 ( V_21 ) )
F_204 ( V_21 ) ;
}
}
void F_205 ( struct V_242 * V_242 )
{
struct V_117 * V_118 =
F_206 ( V_242 , struct V_117 , V_235 ) ;
F_207 ( & V_118 -> V_122 ) ;
F_76 ( ! F_208 ( & V_118 -> V_122 . V_223 ) ) ;
F_76 ( ! F_208 ( & V_118 -> V_122 . V_224 ) ) ;
F_76 ( ! F_208 ( & V_118 -> V_122 . V_225 ) ) ;
V_118 -> V_122 . V_168 ( & V_118 -> V_122 ) ;
F_188 ( & V_118 -> V_122 ) ;
F_57 ( V_118 ) ;
}
static bool F_209 ( struct V_1 * V_2 )
{
#ifdef F_10
if ( F_210 ( V_2 ) && F_211 ( V_2 ) && V_15 )
return true ;
#endif
return false ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_114 * V_115 ;
enum V_181 V_182 ;
if ( F_98 ( V_2 ) -> V_218 < 6 )
return;
F_156 (engine, dev_priv, id) {
T_1 V_243 ;
V_243 = F_160 ( F_213 ( V_115 ) ) ;
if ( V_243 & V_244 ) {
F_14 ( L_16
L_17
L_18
L_19
L_20 ,
V_243 & V_245 ,
V_243 & V_246 ? L_21 : L_22 ,
F_214 ( V_243 ) ,
F_215 ( V_243 ) ) ;
F_2 ( F_213 ( V_115 ) ,
V_243 & ~ V_244 ) ;
}
}
if ( V_2 -> V_115 [ V_247 ] )
F_216 ( F_213 ( V_2 -> V_115 [ V_247 ] ) ) ;
}
void F_217 ( struct V_1 * V_2 )
{
struct V_208 * V_8 = & V_2 -> V_8 ;
if ( F_9 ( V_2 ) < 6 )
return;
F_212 ( V_2 ) ;
V_8 -> V_122 . V_40 ( & V_8 -> V_122 , 0 , V_8 -> V_122 . V_165 ) ;
F_6 ( V_2 ) ;
}
int F_218 ( struct V_248 * V_35 ,
struct V_138 * V_34 )
{
do {
if ( F_219 ( & V_35 -> V_122 . V_217 -> V_17 -> V_217 ,
V_34 -> V_139 , V_34 -> V_249 ,
V_79 ) )
return 0 ;
F_34 ( V_35 -> V_36 . V_34 == V_34 ) ;
} while ( F_220 ( F_221 ( V_35 -> V_122 . V_217 ) ,
V_35 -> V_122 . V_33 >> V_202 ,
V_250 |
V_251 |
V_252 ) );
return - V_253 ;
}
static void F_222 ( void V_215 * V_41 , T_2 V_43 )
{
F_223 ( V_43 , V_41 ) ;
}
static void F_224 ( struct V_65 * V_29 ,
T_3 V_41 ,
T_7 V_254 ,
enum V_22 V_42 ,
T_1 V_24 )
{
struct V_208 * V_8 = F_225 ( V_29 ) ;
T_2 V_215 * V_43 =
( T_2 V_215 * ) V_8 -> V_216 + ( V_254 >> V_202 ) ;
F_222 ( V_43 , F_17 ( V_41 , V_42 ) ) ;
V_8 -> V_9 ( V_29 -> V_7 ) ;
}
static void F_226 ( struct V_65 * V_29 ,
struct V_138 * V_255 ,
T_7 V_32 ,
enum V_22 V_42 ,
T_1 V_24 )
{
struct V_208 * V_8 = F_225 ( V_29 ) ;
struct V_256 V_256 ;
T_2 V_215 * V_257 ;
const T_2 V_91 = F_17 ( 0 , V_42 ) ;
T_3 V_41 ;
V_257 = ( T_2 V_215 * ) V_8 -> V_216 ;
V_257 += V_32 >> V_202 ;
F_227 (addr, sgt_iter, st)
F_222 ( V_257 ++ , V_91 | V_41 ) ;
F_148 () ;
V_8 -> V_9 ( V_29 -> V_7 ) ;
}
static void F_228 ( struct V_65 * V_29 ,
T_3 V_41 ,
T_7 V_254 ,
enum V_22 V_42 ,
T_1 V_27 )
{
struct V_208 * V_8 = F_225 ( V_29 ) ;
T_5 V_215 * V_43 =
( T_5 V_215 * ) V_8 -> V_216 + ( V_254 >> V_202 ) ;
F_229 ( V_29 -> V_91 ( V_41 , V_42 , V_27 ) , V_43 ) ;
V_8 -> V_9 ( V_29 -> V_7 ) ;
}
static void F_230 ( struct V_65 * V_29 ,
struct V_138 * V_255 ,
T_7 V_32 ,
enum V_22 V_42 ,
T_1 V_27 )
{
struct V_208 * V_8 = F_225 ( V_29 ) ;
T_5 V_215 * V_258 = ( T_5 V_215 * ) V_8 -> V_216 ;
unsigned int V_83 = V_32 >> V_202 ;
struct V_256 V_132 ;
T_3 V_41 ;
F_227 (addr, iter, st)
F_229 ( V_29 -> V_91 ( V_41 , V_42 , V_27 ) , & V_258 [ V_83 ++ ] ) ;
F_148 () ;
V_8 -> V_9 ( V_29 -> V_7 ) ;
}
static void F_231 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
}
static void F_232 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
struct V_208 * V_8 = F_225 ( V_29 ) ;
unsigned V_201 = V_32 >> V_202 ;
unsigned V_125 = V_124 >> V_202 ;
const T_2 V_127 =
F_17 ( V_29 -> V_85 . V_76 , V_55 ) ;
T_2 V_215 * V_259 =
( T_2 V_215 * ) V_8 -> V_216 + V_201 ;
const int V_260 = F_233 ( V_8 ) - V_201 ;
int V_83 ;
if ( F_234 ( V_125 > V_260 ,
L_23 ,
V_201 , V_125 , V_260 ) )
V_125 = V_260 ;
for ( V_83 = 0 ; V_83 < V_125 ; V_83 ++ )
F_222 ( & V_259 [ V_83 ] , V_127 ) ;
}
static void F_235 ( struct V_65 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_7 ;
F_216 ( V_3 ) ;
}
static int F_236 ( void * V_261 )
{
struct V_262 * V_263 = V_261 ;
F_224 ( V_263 -> V_29 , V_263 -> V_41 , V_263 -> V_254 , V_263 -> V_42 , 0 ) ;
F_235 ( V_263 -> V_29 ) ;
return 0 ;
}
static void F_237 ( struct V_65 * V_29 ,
T_3 V_41 ,
T_7 V_254 ,
enum V_22 V_42 ,
T_1 V_24 )
{
struct V_262 V_263 = { V_29 , V_41 , V_254 , V_42 } ;
F_238 ( F_236 , & V_263 , NULL ) ;
}
static int F_239 ( void * V_261 )
{
struct V_39 * V_263 = V_261 ;
F_226 ( V_263 -> V_29 , V_263 -> V_255 , V_263 -> V_32 , V_263 -> V_42 , 0 ) ;
F_235 ( V_263 -> V_29 ) ;
return 0 ;
}
static void F_240 ( struct V_65 * V_29 ,
struct V_138 * V_255 ,
T_7 V_32 ,
enum V_22 V_42 ,
T_1 V_24 )
{
struct V_39 V_263 = { V_29 , V_255 , V_32 , V_42 } ;
F_238 ( F_239 , & V_263 , NULL ) ;
}
static int F_241 ( void * V_261 )
{
struct V_40 * V_263 = V_261 ;
F_232 ( V_263 -> V_29 , V_263 -> V_32 , V_263 -> V_124 ) ;
F_235 ( V_263 -> V_29 ) ;
return 0 ;
}
static void F_242 ( struct V_65 * V_29 ,
T_7 V_32 ,
T_7 V_124 )
{
struct V_40 V_263 = { V_29 , V_32 , V_124 } ;
F_238 ( F_241 , & V_263 , NULL ) ;
}
static void F_243 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
struct V_208 * V_8 = F_225 ( V_29 ) ;
unsigned V_201 = V_32 >> V_202 ;
unsigned V_125 = V_124 >> V_202 ;
T_5 V_127 , V_215 * V_259 =
( T_5 V_215 * ) V_8 -> V_216 + V_201 ;
const int V_260 = F_233 ( V_8 ) - V_201 ;
int V_83 ;
if ( F_234 ( V_125 > V_260 ,
L_23 ,
V_201 , V_125 , V_260 ) )
V_125 = V_260 ;
V_127 = V_29 -> V_91 ( V_29 -> V_85 . V_76 ,
V_55 , 0 ) ;
for ( V_83 = 0 ; V_83 < V_125 ; V_83 ++ )
F_229 ( V_127 , & V_259 [ V_83 ] ) ;
}
static void F_244 ( struct V_65 * V_29 ,
T_3 V_41 ,
T_7 V_254 ,
enum V_22 V_23 ,
T_1 V_24 )
{
unsigned int V_27 = ( V_23 == V_46 ) ?
V_264 : V_265 ;
F_245 ( V_41 , V_254 >> V_202 , V_27 ) ;
}
static void F_246 ( struct V_65 * V_29 ,
struct V_138 * V_34 ,
T_7 V_32 ,
enum V_22 V_23 ,
T_1 V_24 )
{
unsigned int V_27 = ( V_23 == V_46 ) ?
V_264 : V_265 ;
F_247 ( V_34 , V_32 >> V_202 , V_27 ) ;
}
static void F_248 ( struct V_65 * V_29 ,
T_7 V_32 , T_7 V_124 )
{
F_249 ( V_32 >> V_202 , V_124 >> V_202 ) ;
}
static int F_250 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
T_1 V_27 )
{
struct V_1 * V_7 = V_21 -> V_29 -> V_7 ;
struct V_248 * V_35 = V_21 -> V_35 ;
T_1 V_25 ;
if ( F_41 ( ! V_21 -> V_34 ) ) {
int V_26 = F_251 ( V_21 ) ;
if ( V_26 )
return V_26 ;
}
V_25 = 0 ;
if ( V_35 -> V_37 )
V_25 |= V_38 ;
F_252 ( V_7 ) ;
V_21 -> V_29 -> V_39 ( V_21 -> V_29 , V_21 -> V_34 , V_21 -> V_31 . V_32 ,
V_23 , V_25 ) ;
F_253 ( V_7 ) ;
V_21 -> V_27 |= V_266 | V_28 ;
return 0 ;
}
static void F_254 ( struct V_20 * V_21 )
{
struct V_1 * V_7 = V_21 -> V_29 -> V_7 ;
F_252 ( V_7 ) ;
V_21 -> V_29 -> V_40 ( V_21 -> V_29 , V_21 -> V_31 . V_32 , V_21 -> V_33 ) ;
F_253 ( V_7 ) ;
}
static int F_255 ( struct V_20 * V_21 ,
enum V_22 V_23 ,
T_1 V_27 )
{
struct V_1 * V_7 = V_21 -> V_29 -> V_7 ;
T_1 V_25 ;
int V_26 ;
if ( F_41 ( ! V_21 -> V_34 ) ) {
V_26 = F_251 ( V_21 ) ;
if ( V_26 )
return V_26 ;
}
V_25 = 0 ;
if ( V_21 -> V_35 -> V_37 )
V_25 |= V_38 ;
if ( V_27 & V_28 ) {
struct V_117 * V_267 = V_7 -> V_36 . V_268 ;
if ( ! ( V_21 -> V_27 & V_28 ) &&
V_267 -> V_122 . V_30 ) {
V_26 = V_267 -> V_122 . V_30 ( & V_267 -> V_122 ,
V_21 -> V_31 . V_32 ,
V_21 -> V_33 ) ;
if ( V_26 )
goto V_269;
}
V_267 -> V_122 . V_39 ( & V_267 -> V_122 ,
V_21 -> V_34 , V_21 -> V_31 . V_32 ,
V_23 , V_25 ) ;
}
if ( V_27 & V_266 ) {
F_252 ( V_7 ) ;
V_21 -> V_29 -> V_39 ( V_21 -> V_29 ,
V_21 -> V_34 , V_21 -> V_31 . V_32 ,
V_23 , V_25 ) ;
F_253 ( V_7 ) ;
}
return 0 ;
V_269:
if ( ! ( V_21 -> V_27 & ( V_266 | V_28 ) ) ) {
if ( V_21 -> V_34 != V_21 -> V_35 -> V_36 . V_34 ) {
F_34 ( ! V_21 -> V_34 ) ;
F_256 ( V_21 -> V_34 ) ;
F_57 ( V_21 -> V_34 ) ;
}
V_21 -> V_34 = NULL ;
}
return V_26 ;
}
static void F_257 ( struct V_20 * V_21 )
{
struct V_1 * V_7 = V_21 -> V_29 -> V_7 ;
if ( V_21 -> V_27 & V_266 ) {
F_252 ( V_7 ) ;
V_21 -> V_29 -> V_40 ( V_21 -> V_29 , V_21 -> V_31 . V_32 , V_21 -> V_33 ) ;
F_253 ( V_7 ) ;
}
if ( V_21 -> V_27 & V_28 ) {
struct V_65 * V_29 = & V_7 -> V_36 . V_268 -> V_122 ;
V_29 -> V_40 ( V_29 , V_21 -> V_31 . V_32 , V_21 -> V_33 ) ;
}
}
void F_258 ( struct V_248 * V_35 ,
struct V_138 * V_34 )
{
struct V_1 * V_2 = F_221 ( V_35 -> V_122 . V_217 ) ;
struct V_270 * V_271 = & V_2 -> V_16 . V_17 -> V_217 ;
struct V_208 * V_8 = & V_2 -> V_8 ;
if ( F_41 ( V_8 -> V_272 ) ) {
if ( F_259 ( V_2 , 0 ) ) {
F_260 ( L_24 ) ;
F_261 ( 10 ) ;
}
}
F_262 ( V_271 , V_34 -> V_139 , V_34 -> V_249 , V_79 ) ;
}
static void F_263 ( const struct V_273 * V_31 ,
unsigned long V_222 ,
T_7 * V_32 ,
T_7 * V_203 )
{
if ( V_31 -> V_274 && V_31 -> V_222 != V_222 )
* V_32 += V_275 ;
V_31 = F_264 ( V_31 , V_276 ) ;
if ( V_31 -> V_222 != V_222 )
* V_203 -= V_275 ;
}
int F_265 ( struct V_1 * V_7 )
{
struct V_208 * V_8 = & V_7 -> V_8 ;
struct V_117 * V_118 ;
int V_277 ;
V_118 = F_198 ( V_7 , F_55 ( - V_278 ) , L_25 ) ;
if ( F_85 ( V_118 ) )
return F_86 ( V_118 ) ;
if ( F_76 ( V_118 -> V_122 . V_165 < V_8 -> V_122 . V_165 ) ) {
V_277 = - V_279 ;
goto V_280;
}
if ( V_118 -> V_122 . V_30 ) {
V_277 = V_118 -> V_122 . V_30 ( & V_118 -> V_122 ,
0 , V_8 -> V_122 . V_165 ) ;
if ( V_277 )
goto V_280;
}
V_7 -> V_36 . V_268 = V_118 ;
F_76 ( V_8 -> V_122 . V_170 != F_250 ) ;
V_8 -> V_122 . V_170 = F_255 ;
F_76 ( V_8 -> V_122 . V_169 != F_254 ) ;
V_8 -> V_122 . V_169 = F_257 ;
return 0 ;
V_280:
F_266 ( V_118 ) ;
return V_277 ;
}
void F_267 ( struct V_1 * V_7 )
{
struct V_208 * V_8 = & V_7 -> V_8 ;
struct V_117 * V_118 ;
V_118 = F_268 ( & V_7 -> V_36 . V_268 ) ;
if ( ! V_118 )
return;
F_266 ( V_118 ) ;
V_8 -> V_122 . V_170 = F_250 ;
V_8 -> V_122 . V_169 = F_254 ;
}
int F_269 ( struct V_1 * V_2 )
{
struct V_208 * V_8 = & V_2 -> V_8 ;
unsigned long V_281 , V_282 ;
struct V_273 * V_113 ;
int V_26 ;
V_26 = F_270 ( V_2 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_271 ( & V_8 -> V_122 . V_36 , & V_8 -> V_283 ,
V_78 , 0 , V_211 ,
0 , V_8 -> V_214 ,
V_284 ) ;
if ( V_26 )
return V_26 ;
F_272 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_273 ( L_26 ,
V_281 , V_282 ) ;
V_8 -> V_122 . V_40 ( & V_8 -> V_122 , V_281 ,
V_282 - V_281 ) ;
}
V_8 -> V_122 . V_40 ( & V_8 -> V_122 ,
V_8 -> V_122 . V_165 - V_78 , V_78 ) ;
if ( F_197 ( V_2 ) && ! F_274 ( V_2 ) ) {
V_26 = F_265 ( V_2 ) ;
if ( V_26 )
goto V_277;
}
return 0 ;
V_277:
F_170 ( & V_8 -> V_283 ) ;
return V_26 ;
}
void F_275 ( struct V_1 * V_2 )
{
struct V_208 * V_8 = & V_2 -> V_8 ;
struct V_20 * V_21 , * V_241 ;
V_8 -> V_122 . V_240 = true ;
F_276 ( & V_2 -> V_16 . V_285 ) ;
F_76 ( ! F_208 ( & V_8 -> V_122 . V_223 ) ) ;
F_202 (vma, vn, &ggtt->base.inactive_list, vm_link)
F_76 ( F_277 ( V_21 ) ) ;
F_278 ( & V_2 -> V_16 . V_285 ) ;
F_279 ( & V_2 -> V_16 ) ;
F_276 ( & V_2 -> V_16 . V_285 ) ;
F_267 ( V_2 ) ;
if ( F_280 ( & V_8 -> V_283 ) )
F_170 ( & V_8 -> V_283 ) ;
if ( F_173 ( & V_8 -> V_122 . V_36 ) ) {
F_281 ( V_2 ) ;
F_188 ( & V_8 -> V_122 ) ;
}
V_8 -> V_122 . V_168 ( & V_8 -> V_122 ) ;
F_278 ( & V_2 -> V_16 . V_285 ) ;
F_282 ( V_8 -> V_286 ) ;
F_283 ( & V_8 -> V_287 ) ;
}
static unsigned int F_284 ( T_11 V_288 )
{
V_288 >>= V_289 ;
V_288 &= V_290 ;
return V_288 << 20 ;
}
static unsigned int F_285 ( T_11 V_291 )
{
V_291 >>= V_292 ;
V_291 &= V_293 ;
if ( V_291 )
V_291 = 1 << V_291 ;
#ifdef F_286
if ( V_291 > 4 )
V_291 = 4 ;
#endif
return V_291 << 20 ;
}
static unsigned int F_287 ( T_11 V_294 )
{
V_294 >>= V_289 ;
V_294 &= V_290 ;
if ( V_294 )
return 1 << ( 20 + V_294 ) ;
return 0 ;
}
static T_12 F_288 ( T_11 V_288 )
{
V_288 >>= V_295 ;
V_288 &= V_296 ;
return V_288 << 25 ;
}
static T_12 F_289 ( T_11 V_291 )
{
V_291 >>= V_297 ;
V_291 &= V_298 ;
return V_291 << 25 ;
}
static T_12 F_290 ( T_11 V_294 )
{
V_294 >>= V_295 ;
V_294 &= V_296 ;
if ( V_294 < 0x11 )
return V_294 << 25 ;
else if ( V_294 < 0x17 )
return ( V_294 - 0x11 + 2 ) << 22 ;
else
return ( V_294 - 0x17 + 9 ) << 22 ;
}
static T_12 F_291 ( T_11 V_299 )
{
V_299 >>= V_297 ;
V_299 &= V_298 ;
if ( V_299 < 0xf0 )
return V_299 << 25 ;
else
return ( V_299 - 0xf0 + 1 ) << 22 ;
}
static int F_292 ( struct V_208 * V_8 , T_7 V_33 )
{
struct V_1 * V_2 = V_8 -> V_122 . V_7 ;
struct V_300 * V_17 = V_2 -> V_16 . V_17 ;
T_13 V_301 ;
int V_26 ;
V_301 = F_293 ( V_17 , 0 ) + F_294 ( V_17 , 0 ) / 2 ;
if ( F_195 ( V_2 ) )
V_8 -> V_216 = F_295 ( V_301 , V_33 ) ;
else
V_8 -> V_216 = F_296 ( V_301 , V_33 ) ;
if ( ! V_8 -> V_216 ) {
F_260 ( L_27 ) ;
return - V_75 ;
}
V_26 = F_51 ( & V_8 -> V_122 , V_302 ) ;
if ( V_26 ) {
F_260 ( L_28 ) ;
F_297 ( V_8 -> V_216 ) ;
return V_26 ;
}
return 0 ;
}
static void F_298 ( struct V_1 * V_2 )
{
T_7 V_303 ;
V_303 = F_299 ( 0 , V_304 | V_305 ) |
F_299 ( 1 , V_306 | V_307 ) |
F_299 ( 2 , V_308 | V_307 ) |
F_299 ( 3 , V_309 ) |
F_299 ( 4 , V_304 | V_307 | F_300 ( 0 ) ) |
F_299 ( 5 , V_304 | V_307 | F_300 ( 1 ) ) |
F_299 ( 6 , V_304 | V_307 | F_300 ( 2 ) ) |
F_299 ( 7 , V_304 | V_307 | F_300 ( 3 ) ) ;
if ( ! F_197 ( V_2 ) )
V_303 = F_299 ( 0 , V_309 ) ;
F_2 ( V_310 , V_303 ) ;
F_2 ( V_311 , V_303 >> 32 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
T_7 V_303 ;
V_303 = F_299 ( 0 , V_312 ) |
F_299 ( 1 , 0 ) |
F_299 ( 2 , 0 ) |
F_299 ( 3 , 0 ) |
F_299 ( 4 , V_312 ) |
F_299 ( 5 , V_312 ) |
F_299 ( 6 , V_312 ) |
F_299 ( 7 , V_312 ) ;
F_2 ( V_310 , V_303 ) ;
F_2 ( V_311 , V_303 >> 32 ) ;
}
static void F_302 ( struct V_65 * V_29 )
{
struct V_208 * V_8 = F_225 ( V_29 ) ;
F_297 ( V_8 -> V_216 ) ;
F_52 ( V_29 ) ;
}
static int F_303 ( struct V_208 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_122 . V_7 ;
struct V_300 * V_17 = V_2 -> V_16 . V_17 ;
unsigned int V_33 ;
T_11 V_288 ;
V_8 -> V_313 = F_293 ( V_17 , 2 ) ;
V_8 -> V_214 = F_294 ( V_17 , 2 ) ;
if ( ! F_304 ( V_17 , F_305 ( 39 ) ) )
F_306 ( V_17 , F_305 ( 39 ) ) ;
F_307 ( V_17 , V_314 , & V_288 ) ;
if ( F_9 ( V_2 ) >= 9 ) {
V_8 -> V_315 = F_291 ( V_288 ) ;
V_33 = F_285 ( V_288 ) ;
} else if ( F_139 ( V_2 ) ) {
V_8 -> V_315 = F_290 ( V_288 ) ;
V_33 = F_287 ( V_288 ) ;
} else {
V_8 -> V_315 = F_289 ( V_288 ) ;
V_33 = F_285 ( V_288 ) ;
}
V_8 -> V_122 . V_165 = ( V_33 / sizeof( T_2 ) ) << V_202 ;
if ( F_139 ( V_2 ) || F_195 ( V_2 ) )
F_301 ( V_2 ) ;
else
F_298 ( V_2 ) ;
V_8 -> V_122 . V_168 = F_302 ;
V_8 -> V_122 . V_170 = F_250 ;
V_8 -> V_122 . V_169 = F_254 ;
V_8 -> V_122 . V_262 = F_224 ;
V_8 -> V_122 . V_40 = F_231 ;
if ( ! F_274 ( V_2 ) || F_308 ( V_2 ) )
V_8 -> V_122 . V_40 = F_232 ;
V_8 -> V_122 . V_39 = F_226 ;
if ( F_309 ( V_2 ) ) {
V_8 -> V_122 . V_39 = F_240 ;
V_8 -> V_122 . V_262 = F_237 ;
if ( V_8 -> V_122 . V_40 != F_231 )
V_8 -> V_122 . V_40 = F_242 ;
}
V_8 -> V_9 = F_1 ;
return F_292 ( V_8 , V_33 ) ;
}
static int F_310 ( struct V_208 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_122 . V_7 ;
struct V_300 * V_17 = V_2 -> V_16 . V_17 ;
unsigned int V_33 ;
T_11 V_288 ;
V_8 -> V_313 = F_293 ( V_17 , 2 ) ;
V_8 -> V_214 = F_294 ( V_17 , 2 ) ;
if ( V_8 -> V_214 < ( 64 << 20 ) || V_8 -> V_214 > ( 512 << 20 ) ) {
F_260 ( L_29 , V_8 -> V_214 ) ;
return - V_316 ;
}
if ( ! F_304 ( V_17 , F_305 ( 40 ) ) )
F_306 ( V_17 , F_305 ( 40 ) ) ;
F_307 ( V_17 , V_314 , & V_288 ) ;
V_8 -> V_315 = F_288 ( V_288 ) ;
V_33 = F_284 ( V_288 ) ;
V_8 -> V_122 . V_165 = ( V_33 / sizeof( T_5 ) ) << V_202 ;
V_8 -> V_122 . V_40 = F_243 ;
V_8 -> V_122 . V_262 = F_228 ;
V_8 -> V_122 . V_39 = F_230 ;
V_8 -> V_122 . V_170 = F_250 ;
V_8 -> V_122 . V_169 = F_254 ;
V_8 -> V_122 . V_168 = F_302 ;
V_8 -> V_9 = F_1 ;
if ( F_311 ( V_2 ) )
V_8 -> V_122 . V_91 = F_26 ;
else if ( F_161 ( V_2 ) )
V_8 -> V_122 . V_91 = F_24 ;
else if ( F_13 ( V_2 ) )
V_8 -> V_122 . V_91 = F_23 ;
else if ( F_9 ( V_2 ) >= 7 )
V_8 -> V_122 . V_91 = F_22 ;
else
V_8 -> V_122 . V_91 = F_19 ;
return F_292 ( V_8 , V_33 ) ;
}
static void F_312 ( struct V_65 * V_29 )
{
F_313 () ;
}
static int F_314 ( struct V_208 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_122 . V_7 ;
int V_26 ;
V_26 = F_315 ( V_2 -> V_317 , V_2 -> V_16 . V_17 , NULL ) ;
if ( ! V_26 ) {
F_260 ( L_30 ) ;
return - V_318 ;
}
F_316 ( & V_8 -> V_122 . V_165 ,
& V_8 -> V_315 ,
& V_8 -> V_313 ,
& V_8 -> V_214 ) ;
V_8 -> V_272 = F_209 ( V_2 ) ;
V_8 -> V_122 . V_262 = F_244 ;
V_8 -> V_122 . V_39 = F_246 ;
V_8 -> V_122 . V_40 = F_248 ;
V_8 -> V_122 . V_170 = F_250 ;
V_8 -> V_122 . V_169 = F_254 ;
V_8 -> V_122 . V_168 = F_312 ;
V_8 -> V_9 = F_4 ;
if ( F_41 ( V_8 -> V_272 ) )
F_12 ( L_31 ) ;
return 0 ;
}
int F_317 ( struct V_1 * V_2 )
{
struct V_208 * V_8 = & V_2 -> V_8 ;
int V_26 ;
V_8 -> V_122 . V_7 = V_2 ;
V_8 -> V_122 . V_77 = & V_2 -> V_16 . V_17 -> V_217 ;
if ( F_9 ( V_2 ) <= 5 )
V_26 = F_314 ( V_8 ) ;
else if ( F_9 ( V_2 ) < 8 )
V_26 = F_310 ( V_8 ) ;
else
V_26 = F_303 ( V_8 ) ;
if ( V_26 )
return V_26 ;
if ( F_318 ( V_2 ) && V_7 . V_319 ) {
V_8 -> V_122 . V_165 = F_319 ( T_7 , V_8 -> V_122 . V_165 , V_320 ) ;
V_8 -> V_214 = F_164 ( V_8 -> V_214 , V_8 -> V_122 . V_165 ) ;
}
if ( ( V_8 -> V_122 . V_165 - 1 ) >> 32 ) {
F_260 ( L_32
L_33 ,
V_8 -> V_122 . V_165 >> 20 ) ;
V_8 -> V_122 . V_165 = 1ULL << 32 ;
V_8 -> V_214 = F_164 ( V_8 -> V_214 , V_8 -> V_122 . V_165 ) ;
}
if ( V_8 -> V_214 > V_8 -> V_122 . V_165 ) {
F_260 ( L_34
L_35 ,
V_8 -> V_214 , V_8 -> V_122 . V_165 ) ;
V_8 -> V_214 = V_8 -> V_122 . V_165 ;
}
F_12 ( L_36 ,
V_8 -> V_122 . V_165 >> 20 ) ;
F_14 ( L_37 , V_8 -> V_214 >> 20 ) ;
F_14 ( L_38 , V_8 -> V_315 >> 20 ) ;
#ifdef F_10
if ( V_15 )
F_12 ( L_39 ) ;
#endif
return 0 ;
}
int F_320 ( struct V_1 * V_2 )
{
struct V_208 * V_8 = & V_2 -> V_8 ;
int V_26 ;
F_185 ( & V_2 -> V_227 ) ;
F_276 ( & V_2 -> V_16 . V_285 ) ;
F_182 ( & V_8 -> V_122 , V_2 , L_40 ) ;
if ( ! F_321 ( V_2 ) && ! F_197 ( V_2 ) )
V_8 -> V_122 . V_36 . V_321 = F_263 ;
F_278 ( & V_2 -> V_16 . V_285 ) ;
if ( ! F_322 ( & V_2 -> V_8 . V_287 ,
V_2 -> V_8 . V_313 ,
V_2 -> V_8 . V_214 ) ) {
V_26 = - V_318 ;
goto V_322;
}
V_8 -> V_286 = F_323 ( V_8 -> V_313 , V_8 -> V_214 ) ;
V_26 = F_324 ( V_2 ) ;
if ( V_26 )
goto V_322;
return 0 ;
V_322:
V_8 -> V_122 . V_168 ( & V_8 -> V_122 ) ;
return V_26 ;
}
int F_325 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) < 6 && ! F_326 () )
return - V_318 ;
return 0 ;
}
void F_327 ( struct V_1 * V_7 )
{
V_7 -> V_8 . V_9 = F_3 ;
}
void F_328 ( struct V_1 * V_7 )
{
if ( V_7 -> V_8 . V_9 == F_3 )
V_7 -> V_8 . V_9 = F_1 ;
}
void F_329 ( struct V_1 * V_2 )
{
struct V_208 * V_8 = & V_2 -> V_8 ;
struct V_248 * V_35 , * V_323 ;
F_212 ( V_2 ) ;
V_8 -> V_122 . V_40 ( & V_8 -> V_122 , 0 , V_8 -> V_122 . V_165 ) ;
V_8 -> V_122 . V_240 = true ;
F_202 (obj, on,
&dev_priv->mm.bound_list, global_link) {
bool V_324 = false ;
struct V_20 * V_21 ;
F_330 (vma, &obj->vma_list, obj_link) {
if ( V_21 -> V_29 != & V_8 -> V_122 )
continue;
if ( ! F_277 ( V_21 ) )
continue;
F_76 ( F_331 ( V_21 , V_35 -> V_23 ,
V_325 ) ) ;
V_324 = true ;
}
if ( V_324 )
F_76 ( F_332 ( V_35 , false ) ) ;
}
V_8 -> V_122 . V_240 = false ;
if ( F_9 ( V_2 ) >= 8 ) {
if ( F_139 ( V_2 ) || F_195 ( V_2 ) )
F_301 ( V_2 ) ;
else
F_298 ( V_2 ) ;
return;
}
if ( F_197 ( V_2 ) ) {
struct V_65 * V_29 ;
F_330 (vm, &dev_priv->vm_list, global_link) {
struct V_117 * V_118 ;
if ( F_333 ( V_29 ) )
V_118 = V_2 -> V_36 . V_268 ;
else
V_118 = F_110 ( V_29 ) ;
F_147 ( V_118 , 0 , V_118 -> V_122 . V_165 ) ;
}
}
F_6 ( V_2 ) ;
}
static struct V_326 *
F_334 ( const T_3 * V_327 , unsigned int V_254 ,
unsigned int V_328 , unsigned int V_329 ,
unsigned int V_330 ,
struct V_138 * V_255 , struct V_326 * V_136 )
{
unsigned int V_331 , V_332 ;
unsigned int V_333 ;
for ( V_331 = 0 ; V_331 < V_328 ; V_331 ++ ) {
V_333 = V_330 * ( V_329 - 1 ) + V_331 ;
for ( V_332 = 0 ; V_332 < V_329 ; V_332 ++ ) {
V_255 -> V_249 ++ ;
F_335 ( V_136 , NULL , V_78 , 0 ) ;
F_116 ( V_136 ) = V_327 [ V_254 + V_333 ] ;
F_336 ( V_136 ) = V_78 ;
V_136 = F_337 ( V_136 ) ;
V_333 -= V_330 ;
}
}
return V_136 ;
}
T_14 struct V_138 *
F_338 ( const struct V_334 * V_335 ,
struct V_248 * V_35 )
{
struct V_138 * V_255 ;
struct V_326 * V_136 , * V_132 ;
unsigned int V_336 = V_335 -> V_337 . V_33 ;
unsigned int V_254 ;
int V_26 = - V_75 ;
V_255 = F_54 ( sizeof( * V_255 ) , V_89 ) ;
if ( ! V_255 )
goto V_338;
V_26 = F_339 ( V_255 , V_336 , V_89 ) ;
if ( V_26 )
goto V_339;
V_132 = F_340 ( V_35 , V_335 -> V_337 . V_254 , & V_254 ) ;
F_34 ( ! V_132 ) ;
V_136 = V_255 -> V_139 ;
V_255 -> V_249 = 0 ;
do {
unsigned int V_340 ;
V_340 = F_164 ( V_132 -> V_124 - ( V_254 << V_202 ) ,
V_336 << V_202 ) ;
F_335 ( V_136 , NULL , V_340 , 0 ) ;
F_116 ( V_136 ) =
F_116 ( V_132 ) + ( V_254 << V_202 ) ;
F_336 ( V_136 ) = V_340 ;
V_255 -> V_249 ++ ;
V_336 -= V_340 >> V_202 ;
if ( V_336 == 0 ) {
F_341 ( V_136 ) ;
return V_255 ;
}
V_136 = F_115 ( V_136 ) ;
V_132 = F_115 ( V_132 ) ;
V_254 = 0 ;
} while ( 1 );
V_339:
F_57 ( V_255 ) ;
V_338:
return F_55 ( V_26 ) ;
}
static int
F_251 ( struct V_20 * V_21 )
{
int V_26 ;
F_34 ( ! F_342 ( V_21 -> V_35 ) ) ;
switch ( V_21 -> V_341 . type ) {
case V_342 :
V_21 -> V_34 = V_21 -> V_35 -> V_36 . V_34 ;
return 0 ;
case V_343 :
V_21 -> V_34 =
F_343 ( & V_21 -> V_341 . V_344 , V_21 -> V_35 ) ;
break;
case V_345 :
V_21 -> V_34 = F_338 ( & V_21 -> V_341 , V_21 -> V_35 ) ;
break;
default:
F_344 ( 1 , L_41 ,
V_21 -> V_341 . type ) ;
return - V_346 ;
}
V_26 = 0 ;
if ( F_41 ( F_85 ( V_21 -> V_34 ) ) ) {
V_26 = F_86 ( V_21 -> V_34 ) ;
V_21 -> V_34 = NULL ;
F_260 ( L_42 ,
V_21 -> V_341 . type , V_26 ) ;
}
return V_26 ;
}
int F_345 ( struct V_65 * V_29 ,
struct V_273 * V_31 ,
T_7 V_33 , T_7 V_254 , unsigned long V_222 ,
unsigned int V_27 )
{
int V_277 ;
F_34 ( ! V_33 ) ;
F_34 ( ! F_346 ( V_33 , V_275 ) ) ;
F_34 ( ! F_346 ( V_254 , V_347 ) ) ;
F_34 ( F_347 ( V_254 , V_33 , V_29 -> V_165 ) ) ;
F_34 ( V_29 == & V_29 -> V_7 -> V_36 . V_268 -> V_122 ) ;
F_34 ( F_280 ( V_31 ) ) ;
V_31 -> V_33 = V_33 ;
V_31 -> V_32 = V_254 ;
V_31 -> V_222 = V_222 ;
V_277 = F_348 ( & V_29 -> V_36 , V_31 ) ;
if ( V_277 != - V_253 )
return V_277 ;
V_277 = F_349 ( V_29 , V_31 , V_27 ) ;
if ( V_277 == 0 )
V_277 = F_348 ( & V_29 -> V_36 , V_31 ) ;
return V_277 ;
}
static T_7 F_350 ( T_7 V_32 , T_7 V_203 , T_7 V_340 , T_7 V_348 )
{
T_7 V_349 , V_41 ;
F_34 ( F_347 ( V_32 , V_340 , V_203 ) ) ;
F_34 ( F_351 ( V_32 , V_348 ) > F_352 ( V_203 - V_340 , V_348 ) ) ;
V_349 = F_352 ( V_203 - V_340 , V_348 ) - F_351 ( V_32 , V_348 ) ;
if ( V_349 ) {
if (sizeof( unsigned long ) == sizeof( T_7 ) ) {
V_41 = F_353 () ;
} else {
V_41 = F_354 () ;
if ( V_349 > V_350 ) {
V_41 <<= 32 ;
V_41 |= F_354 () ;
}
}
F_355 ( V_41 , V_349 , & V_41 ) ;
V_32 += V_41 ;
}
return F_351 ( V_32 , V_348 ) ;
}
int F_174 ( struct V_65 * V_29 ,
struct V_273 * V_31 ,
T_7 V_33 , T_7 V_351 , unsigned long V_222 ,
T_7 V_32 , T_7 V_203 , unsigned int V_27 )
{
enum V_352 V_353 ;
T_7 V_254 ;
int V_277 ;
F_356 ( & V_29 -> V_7 -> V_16 . V_285 ) ;
F_34 ( ! V_33 ) ;
F_34 ( ! F_346 ( V_33 , V_275 ) ) ;
F_34 ( V_351 && ! F_357 ( V_351 ) ) ;
F_34 ( V_351 && ! F_346 ( V_351 , V_347 ) ) ;
F_34 ( V_32 >= V_203 ) ;
F_34 ( V_32 > 0 && ! F_346 ( V_32 , V_275 ) ) ;
F_34 ( V_203 < V_354 && ! F_346 ( V_203 , V_275 ) ) ;
F_34 ( V_29 == & V_29 -> V_7 -> V_36 . V_268 -> V_122 ) ;
F_34 ( F_280 ( V_31 ) ) ;
if ( F_41 ( F_347 ( V_32 , V_33 , V_203 ) ) )
return - V_253 ;
if ( F_41 ( F_351 ( V_32 , V_351 ) > F_352 ( V_203 - V_33 , V_351 ) ) )
return - V_253 ;
V_353 = V_355 ;
if ( V_27 & V_212 )
V_353 = V_356 ;
if ( V_27 & V_357 )
V_353 = V_284 ;
F_358 ( V_347 > V_275 ) ;
if ( V_351 <= V_347 )
V_351 = 0 ;
V_277 = F_271 ( & V_29 -> V_36 , V_31 ,
V_33 , V_351 , V_222 ,
V_32 , V_203 , V_353 ) ;
if ( V_277 != - V_253 )
return V_277 ;
V_254 = F_350 ( V_32 , V_203 ,
V_33 , V_351 ? : V_347 ) ;
V_277 = F_345 ( V_29 , V_31 , V_33 , V_254 , V_222 , V_27 ) ;
if ( V_277 != - V_253 )
return V_277 ;
V_277 = F_359 ( V_29 , V_33 , V_351 , V_222 ,
V_32 , V_203 , V_27 ) ;
if ( V_277 )
return V_277 ;
return F_271 ( & V_29 -> V_36 , V_31 ,
V_33 , V_351 , V_222 ,
V_32 , V_203 , V_358 ) ;
}
