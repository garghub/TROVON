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
if ( F_10 ( V_2 ) && F_11 () ) {
F_12 ( L_1 ) ;
return 0 ;
}
if ( F_13 ( V_2 ) && V_2 -> V_15 . V_16 -> V_17 < 0xb ) {
F_14 ( L_2 ) ;
return 0 ;
}
if ( F_9 ( V_2 ) >= 8 && V_7 . V_18 && V_12 )
return V_13 ? 3 : 2 ;
else
return V_11 ? 1 : 0 ;
}
static int F_15 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_23 )
{
T_1 V_24 ;
int V_25 ;
if ( ! ( V_20 -> V_26 & V_27 ) ) {
V_25 = V_20 -> V_28 -> V_29 ( V_20 -> V_28 , V_20 -> V_30 . V_31 ,
V_20 -> V_32 ) ;
if ( V_25 )
return V_25 ;
}
V_20 -> V_33 = V_20 -> V_34 -> V_35 . V_33 ;
V_24 = 0 ;
if ( V_20 -> V_34 -> V_36 )
V_24 |= V_37 ;
V_20 -> V_28 -> V_38 ( V_20 -> V_28 , V_20 -> V_33 , V_20 -> V_30 . V_31 ,
V_22 , V_24 ) ;
return 0 ;
}
static void F_16 ( struct V_19 * V_20 )
{
V_20 -> V_28 -> V_39 ( V_20 -> V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
}
static T_2 F_17 ( T_3 V_40 ,
enum V_21 V_41 )
{
T_2 V_42 = V_43 | V_44 ;
V_42 |= V_40 ;
switch ( V_41 ) {
case V_45 :
V_42 |= V_46 ;
break;
case V_47 :
V_42 |= V_48 ;
break;
default:
V_42 |= V_49 ;
break;
}
return V_42 ;
}
static T_4 F_18 ( const T_3 V_40 ,
const enum V_21 V_41 )
{
T_4 V_50 = V_43 | V_44 ;
V_50 |= V_40 ;
if ( V_41 != V_45 )
V_50 |= V_51 ;
else
V_50 |= V_46 ;
return V_50 ;
}
static T_5 F_19 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_20 ( V_40 ) ;
switch ( V_41 ) {
case V_53 :
case V_54 :
V_42 |= V_55 ;
break;
case V_45 :
V_42 |= V_56 ;
break;
default:
F_21 ( V_41 ) ;
}
return V_42 ;
}
static T_5 F_22 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_20 ( V_40 ) ;
switch ( V_41 ) {
case V_53 :
V_42 |= V_57 ;
break;
case V_54 :
V_42 |= V_55 ;
break;
case V_45 :
V_42 |= V_56 ;
break;
default:
F_21 ( V_41 ) ;
}
return V_42 ;
}
static T_5 F_23 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_26 )
{
T_5 V_42 = V_52 ;
V_42 |= F_20 ( V_40 ) ;
if ( ! ( V_26 & V_37 ) )
V_42 |= V_58 ;
if ( V_41 != V_45 )
V_42 |= V_59 ;
return V_42 ;
}
static T_5 F_24 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_25 ( V_40 ) ;
if ( V_41 != V_45 )
V_42 |= V_60 ;
return V_42 ;
}
static T_5 F_26 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_25 ( V_40 ) ;
switch ( V_41 ) {
case V_45 :
break;
case V_47 :
V_42 |= V_61 ;
break;
default:
V_42 |= V_62 ;
break;
}
return V_42 ;
}
static struct V_63 * F_27 ( struct V_64 * V_28 , T_6 V_65 )
{
struct V_63 * V_63 ;
if ( F_28 ( F_29 ( & V_28 -> V_66 , 1 ) ) )
F_30 ( V_28 -> V_7 ) ;
if ( V_28 -> V_67 . V_68 )
return V_28 -> V_67 . V_33 [ -- V_28 -> V_67 . V_68 ] ;
V_63 = F_31 ( V_65 ) ;
if ( ! V_63 )
return NULL ;
if ( V_28 -> V_69 )
F_32 ( & V_63 , 1 ) ;
return V_63 ;
}
static void F_33 ( struct V_64 * V_28 )
{
F_34 ( ! F_35 ( & V_28 -> V_67 ) ) ;
if ( V_28 -> V_69 )
F_36 ( V_28 -> V_67 . V_33 ,
F_35 ( & V_28 -> V_67 ) ) ;
F_37 ( & V_28 -> V_67 ) ;
}
static void F_38 ( struct V_64 * V_28 , struct V_63 * V_63 )
{
if ( ! F_39 ( & V_28 -> V_67 , V_63 ) )
F_33 ( V_28 ) ;
}
static int F_40 ( struct V_64 * V_28 ,
struct V_70 * V_71 ,
T_6 V_65 )
{
V_71 -> V_63 = F_27 ( V_28 , V_65 | V_72 | V_73 ) ;
if ( F_41 ( ! V_71 -> V_63 ) )
return - V_74 ;
V_71 -> V_75 = F_42 ( V_28 -> V_76 , V_71 -> V_63 , 0 , V_77 ,
V_78 ) ;
if ( F_41 ( F_43 ( V_28 -> V_76 , V_71 -> V_75 ) ) ) {
F_38 ( V_28 , V_71 -> V_63 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_44 ( struct V_64 * V_28 ,
struct V_70 * V_71 )
{
return F_40 ( V_28 , V_71 , V_79 ) ;
}
static void F_45 ( struct V_64 * V_28 ,
struct V_70 * V_71 )
{
F_46 ( V_28 -> V_76 , V_71 -> V_75 , V_77 , V_78 ) ;
F_38 ( V_28 , V_71 -> V_63 ) ;
}
static void F_47 ( struct V_64 * V_28 ,
struct V_70 * V_71 ,
const T_7 V_80 )
{
T_7 * const V_81 = F_48 ( V_71 -> V_63 ) ;
int V_82 ;
for ( V_82 = 0 ; V_82 < 512 ; V_82 ++ )
V_81 [ V_82 ] = V_80 ;
F_49 ( V_81 ) ;
}
static void F_50 ( struct V_64 * V_28 ,
struct V_70 * V_71 ,
const T_1 V_83 )
{
F_47 ( V_28 , V_71 , ( T_7 ) V_83 << 32 | V_83 ) ;
}
static int
F_51 ( struct V_64 * V_28 , T_6 V_65 )
{
return F_40 ( V_28 , & V_28 -> V_84 , V_65 | V_85 ) ;
}
static void F_52 ( struct V_64 * V_28 )
{
F_45 ( V_28 , & V_28 -> V_84 ) ;
}
static struct V_86 * F_53 ( struct V_64 * V_28 )
{
struct V_86 * V_87 ;
V_87 = F_54 ( sizeof( * V_87 ) , V_88 | V_72 ) ;
if ( F_41 ( ! V_87 ) )
return F_55 ( - V_74 ) ;
if ( F_41 ( F_56 ( V_28 , V_87 ) ) ) {
F_57 ( V_87 ) ;
return F_55 ( - V_74 ) ;
}
V_87 -> V_89 = 0 ;
return V_87 ;
}
static void F_58 ( struct V_64 * V_28 , struct V_86 * V_87 )
{
F_59 ( V_28 , V_87 ) ;
F_57 ( V_87 ) ;
}
static void F_60 ( struct V_64 * V_28 ,
struct V_86 * V_87 )
{
F_61 ( V_28 , V_87 ,
F_17 ( V_28 -> V_84 . V_75 , V_54 ) ) ;
}
static void F_62 ( struct V_64 * V_28 ,
struct V_86 * V_87 )
{
F_63 ( V_28 , V_87 ,
V_28 -> V_90 ( V_28 -> V_84 . V_75 , V_54 , 0 ) ) ;
}
static struct V_91 * F_64 ( struct V_64 * V_28 )
{
struct V_91 * V_92 ;
V_92 = F_65 ( sizeof( * V_92 ) , V_88 | V_72 ) ;
if ( F_41 ( ! V_92 ) )
return F_55 ( - V_74 ) ;
if ( F_41 ( F_56 ( V_28 , V_92 ) ) ) {
F_57 ( V_92 ) ;
return F_55 ( - V_74 ) ;
}
V_92 -> V_93 = 0 ;
return V_92 ;
}
static void F_66 ( struct V_64 * V_28 ,
struct V_91 * V_92 )
{
F_59 ( V_28 , V_92 ) ;
F_57 ( V_92 ) ;
}
static void F_67 ( struct V_64 * V_28 ,
struct V_91 * V_92 )
{
unsigned int V_82 ;
F_61 ( V_28 , V_92 ,
F_18 ( F_68 ( V_28 -> V_94 ) , V_54 ) ) ;
for ( V_82 = 0 ; V_82 < V_95 ; V_82 ++ )
V_92 -> V_96 [ V_82 ] = V_28 -> V_94 ;
}
static int F_69 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
const unsigned int V_99 = F_70 ( V_28 ) ;
unsigned int V_82 ;
V_98 -> V_100 = F_71 ( V_99 , sizeof( * V_98 -> V_100 ) ,
V_88 | V_72 ) ;
if ( F_41 ( ! V_98 -> V_100 ) )
return - V_74 ;
for ( V_82 = 0 ; V_82 < V_99 ; V_82 ++ )
V_98 -> V_100 [ V_82 ] = V_28 -> V_101 ;
return 0 ;
}
static void F_72 ( struct V_97 * V_98 )
{
F_57 ( V_98 -> V_100 ) ;
V_98 -> V_100 = NULL ;
}
static inline bool F_73 ( const struct V_64 * V_28 )
{
return F_74 ( V_28 ) ;
}
static struct V_97 *
F_75 ( struct V_64 * V_28 )
{
struct V_97 * V_98 ;
int V_25 = - V_74 ;
F_76 ( ! F_73 ( V_28 ) ) ;
V_98 = F_65 ( sizeof( * V_98 ) , V_88 ) ;
if ( ! V_98 )
return F_55 ( - V_74 ) ;
V_25 = F_69 ( V_28 , V_98 ) ;
if ( V_25 )
goto V_102;
V_25 = F_56 ( V_28 , V_98 ) ;
if ( V_25 )
goto V_103;
return V_98 ;
V_103:
F_72 ( V_98 ) ;
V_102:
F_57 ( V_98 ) ;
return F_55 ( V_25 ) ;
}
static void F_77 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
F_72 ( V_98 ) ;
if ( ! F_73 ( V_28 ) )
return;
F_59 ( V_28 , V_98 ) ;
F_57 ( V_98 ) ;
}
static void F_78 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
T_8 V_104 ;
V_104 = F_79 ( F_68 ( V_28 -> V_101 ) , V_54 ) ;
F_61 ( V_28 , V_98 , V_104 ) ;
}
static void F_80 ( struct V_64 * V_28 ,
struct V_105 * V_106 )
{
unsigned int V_82 ;
F_61 ( V_28 , V_106 ,
F_81 ( F_68 ( V_28 -> V_107 ) , V_54 ) ) ;
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ )
V_106 -> V_109 [ V_82 ] = V_28 -> V_107 ;
}
static int F_82 ( struct V_110 * V_111 ,
unsigned V_112 ,
T_3 V_40 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
T_1 * V_115 ;
F_83 ( V_112 >= 4 ) ;
V_115 = F_84 ( V_111 , 6 ) ;
if ( F_85 ( V_115 ) )
return F_86 ( V_115 ) ;
* V_115 ++ = F_87 ( 1 ) ;
* V_115 ++ = F_88 ( F_89 ( V_114 , V_112 ) ) ;
* V_115 ++ = F_90 ( V_40 ) ;
* V_115 ++ = F_87 ( 1 ) ;
* V_115 ++ = F_88 ( F_91 ( V_114 , V_112 ) ) ;
* V_115 ++ = F_92 ( V_40 ) ;
F_93 ( V_111 , V_115 ) ;
return 0 ;
}
static int F_94 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
int V_82 , V_25 ;
for ( V_82 = V_118 - 1 ; V_82 >= 0 ; V_82 -- ) {
const T_3 V_119 = F_95 ( V_117 , V_82 ) ;
V_25 = F_82 ( V_111 , V_82 , V_119 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
static int F_96 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
return F_82 ( V_111 , 0 , F_68 ( & V_117 -> V_106 ) ) ;
}
static void F_97 ( struct V_116 * V_117 )
{
V_117 -> V_120 = F_98 ( V_117 -> V_121 . V_7 ) -> V_122 ;
}
static bool F_99 ( struct V_64 * V_28 ,
struct V_86 * V_87 ,
T_7 V_31 , T_7 V_123 )
{
unsigned int V_124 = F_100 ( V_31 , V_123 ) ;
unsigned int V_42 = F_101 ( V_31 ) ;
unsigned int V_125 = V_42 + V_124 ;
const T_2 V_126 =
F_17 ( V_28 -> V_84 . V_75 , V_54 ) ;
T_2 * V_81 ;
F_34 ( V_124 > V_87 -> V_89 ) ;
V_87 -> V_89 -= V_124 ;
if ( ! V_87 -> V_89 )
return true ;
V_81 = F_102 ( V_87 ) ;
while ( V_42 < V_125 )
V_81 [ V_42 ++ ] = V_126 ;
F_49 ( V_81 ) ;
return false ;
}
static void F_103 ( struct V_64 * V_28 ,
struct V_91 * V_92 ,
struct V_86 * V_87 ,
unsigned int V_50 )
{
T_4 * V_81 ;
V_92 -> V_96 [ V_50 ] = V_87 ;
V_81 = F_102 ( V_92 ) ;
V_81 [ V_50 ] = F_18 ( F_68 ( V_87 ) , V_54 ) ;
F_49 ( V_81 ) ;
}
static bool F_104 ( struct V_64 * V_28 ,
struct V_91 * V_92 ,
T_7 V_31 , T_7 V_123 )
{
struct V_86 * V_87 ;
T_1 V_50 ;
F_105 (pt, pd, start, length, pde) {
F_34 ( V_87 == V_28 -> V_94 ) ;
if ( ! F_99 ( V_28 , V_87 , V_31 , V_123 ) )
continue;
F_103 ( V_28 , V_92 , V_28 -> V_94 , V_50 ) ;
F_34 ( ! V_92 -> V_93 ) ;
V_92 -> V_93 -- ;
F_58 ( V_28 , V_87 ) ;
}
return ! V_92 -> V_93 ;
}
static void F_106 ( struct V_64 * V_28 ,
struct V_97 * V_98 ,
struct V_91 * V_92 ,
unsigned int V_127 )
{
T_8 * V_81 ;
V_98 -> V_100 [ V_127 ] = V_92 ;
if ( ! F_73 ( V_28 ) )
return;
V_81 = F_102 ( V_98 ) ;
V_81 [ V_127 ] = F_79 ( F_68 ( V_92 ) , V_54 ) ;
F_49 ( V_81 ) ;
}
static bool F_107 ( struct V_64 * V_28 ,
struct V_97 * V_98 ,
T_7 V_31 , T_7 V_123 )
{
struct V_91 * V_92 ;
unsigned int V_127 ;
F_108 (pd, pdp, start, length, pdpe) {
F_34 ( V_92 == V_28 -> V_101 ) ;
if ( ! F_104 ( V_28 , V_92 , V_31 , V_123 ) )
continue;
F_106 ( V_28 , V_98 , V_28 -> V_101 , V_127 ) ;
F_34 ( ! V_98 -> V_128 ) ;
V_98 -> V_128 -- ;
F_66 ( V_28 , V_92 ) ;
}
return ! V_98 -> V_128 ;
}
static void F_109 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
F_107 ( V_28 , & F_110 ( V_28 ) -> V_98 , V_31 , V_123 ) ;
}
static void F_111 ( struct V_105 * V_106 ,
struct V_97 * V_98 ,
unsigned int V_129 )
{
T_9 * V_81 ;
V_106 -> V_109 [ V_129 ] = V_98 ;
V_81 = F_102 ( V_106 ) ;
V_81 [ V_129 ] = F_81 ( F_68 ( V_98 ) , V_54 ) ;
F_49 ( V_81 ) ;
}
static void F_112 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
struct V_105 * V_106 = & V_117 -> V_106 ;
struct V_97 * V_98 ;
unsigned int V_129 ;
F_34 ( ! F_73 ( V_28 ) ) ;
F_113 (pdp, pml4, start, length, pml4e) {
F_34 ( V_98 == V_28 -> V_107 ) ;
if ( ! F_107 ( V_28 , V_98 , V_31 , V_123 ) )
continue;
F_111 ( V_106 , V_28 -> V_107 , V_129 ) ;
F_77 ( V_28 , V_98 ) ;
}
}
static T_10 bool
F_114 ( struct V_116 * V_117 ,
struct V_97 * V_98 ,
struct V_130 * V_131 ,
struct V_132 * V_133 ,
enum V_21 V_22 )
{
struct V_91 * V_92 ;
const T_2 V_90 = F_17 ( 0 , V_22 ) ;
T_2 * V_81 ;
bool V_25 ;
F_34 ( V_133 -> V_127 >= F_70 ( & V_117 -> V_121 ) ) ;
V_92 = V_98 -> V_100 [ V_133 -> V_127 ] ;
V_81 = F_102 ( V_92 -> V_96 [ V_133 -> V_50 ] ) ;
do {
V_81 [ V_133 -> V_42 ] = V_90 | V_131 -> V_76 ;
V_131 -> V_76 += V_77 ;
if ( V_131 -> V_76 >= V_131 -> V_134 ) {
V_131 -> V_135 = F_115 ( V_131 -> V_135 ) ;
if ( ! V_131 -> V_135 ) {
V_25 = false ;
break;
}
V_131 -> V_76 = F_116 ( V_131 -> V_135 ) ;
V_131 -> V_134 = V_131 -> V_76 + V_131 -> V_135 -> V_123 ;
}
if ( ++ V_133 -> V_42 == V_136 ) {
V_133 -> V_42 = 0 ;
if ( ++ V_133 -> V_50 == V_95 ) {
V_133 -> V_50 = 0 ;
if ( ++ V_133 -> V_127 == V_108 ) {
V_133 -> V_127 = 0 ;
V_25 = true ;
break;
}
F_34 ( V_133 -> V_127 >= F_70 ( & V_117 -> V_121 ) ) ;
V_92 = V_98 -> V_100 [ V_133 -> V_127 ] ;
}
F_49 ( V_81 ) ;
V_81 = F_102 ( V_92 -> V_96 [ V_133 -> V_50 ] ) ;
}
} while ( 1 );
F_49 ( V_81 ) ;
return V_25 ;
}
static void F_117 ( struct V_64 * V_28 ,
struct V_137 * V_33 ,
T_7 V_31 ,
enum V_21 V_22 ,
T_1 V_23 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
struct V_130 V_131 = {
. V_135 = V_33 -> V_138 ,
. V_76 = F_116 ( V_131 . V_135 ) ,
. V_134 = V_131 . V_76 + V_131 . V_135 -> V_123 ,
} ;
struct V_132 V_133 = V_132 ( V_31 ) ;
F_114 ( V_117 , & V_117 -> V_98 , & V_131 , & V_133 ,
V_22 ) ;
}
static void F_118 ( struct V_64 * V_28 ,
struct V_137 * V_33 ,
T_7 V_31 ,
enum V_21 V_22 ,
T_1 V_23 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
struct V_130 V_131 = {
. V_135 = V_33 -> V_138 ,
. V_76 = F_116 ( V_131 . V_135 ) ,
. V_134 = V_131 . V_76 + V_131 . V_135 -> V_123 ,
} ;
struct V_97 * * V_109 = V_117 -> V_106 . V_109 ;
struct V_132 V_133 = V_132 ( V_31 ) ;
while ( F_114 ( V_117 , V_109 [ V_133 . V_129 ++ ] , & V_131 ,
& V_133 , V_22 ) )
F_34 ( V_133 . V_129 >= V_108 ) ;
}
static void F_119 ( struct V_64 * V_28 ,
struct V_91 * V_92 )
{
int V_82 ;
if ( ! F_120 ( V_92 ) )
return;
for ( V_82 = 0 ; V_82 < V_95 ; V_82 ++ ) {
if ( V_92 -> V_96 [ V_82 ] != V_28 -> V_94 )
F_58 ( V_28 , V_92 -> V_96 [ V_82 ] ) ;
}
}
static int F_121 ( struct V_64 * V_28 )
{
int V_25 ;
V_25 = F_51 ( V_28 , V_79 ) ;
if ( V_25 )
return V_25 ;
V_28 -> V_94 = F_53 ( V_28 ) ;
if ( F_85 ( V_28 -> V_94 ) ) {
V_25 = F_86 ( V_28 -> V_94 ) ;
goto V_139;
}
V_28 -> V_101 = F_64 ( V_28 ) ;
if ( F_85 ( V_28 -> V_101 ) ) {
V_25 = F_86 ( V_28 -> V_101 ) ;
goto F_58;
}
if ( F_73 ( V_28 ) ) {
V_28 -> V_107 = F_75 ( V_28 ) ;
if ( F_85 ( V_28 -> V_107 ) ) {
V_25 = F_86 ( V_28 -> V_107 ) ;
goto F_66;
}
}
F_60 ( V_28 , V_28 -> V_94 ) ;
F_67 ( V_28 , V_28 -> V_101 ) ;
if ( F_73 ( V_28 ) )
F_78 ( V_28 , V_28 -> V_107 ) ;
return 0 ;
F_66:
F_66 ( V_28 , V_28 -> V_101 ) ;
F_58:
F_58 ( V_28 , V_28 -> V_94 ) ;
V_139:
F_52 ( V_28 ) ;
return V_25 ;
}
static int F_122 ( struct V_116 * V_117 , bool V_140 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_1 * V_2 = V_28 -> V_7 ;
enum V_141 V_142 ;
int V_82 ;
if ( F_73 ( V_28 ) ) {
const T_7 V_75 = F_68 ( & V_117 -> V_106 ) ;
F_2 ( F_123 ( V_98 [ 0 ] . V_143 ) , F_92 ( V_75 ) ) ;
F_2 ( F_123 ( V_98 [ 0 ] . V_144 ) , F_90 ( V_75 ) ) ;
V_142 = ( V_140 ? V_145 :
V_146 ) ;
} else {
for ( V_82 = 0 ; V_82 < V_118 ; V_82 ++ ) {
const T_7 V_75 = F_95 ( V_117 , V_82 ) ;
F_2 ( F_123 ( V_98 [ V_82 ] . V_143 ) , F_92 ( V_75 ) ) ;
F_2 ( F_123 ( V_98 [ V_82 ] . V_144 ) , F_90 ( V_75 ) ) ;
}
V_142 = ( V_140 ? V_147 :
V_148 ) ;
}
F_2 ( F_123 ( V_149 ) , V_142 ) ;
return 0 ;
}
static void F_124 ( struct V_64 * V_28 )
{
if ( F_73 ( V_28 ) )
F_77 ( V_28 , V_28 -> V_107 ) ;
F_66 ( V_28 , V_28 -> V_101 ) ;
F_58 ( V_28 , V_28 -> V_94 ) ;
F_52 ( V_28 ) ;
}
static void F_125 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
const unsigned int V_99 = F_70 ( V_28 ) ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_99 ; V_82 ++ ) {
if ( V_98 -> V_100 [ V_82 ] == V_28 -> V_101 )
continue;
F_119 ( V_28 , V_98 -> V_100 [ V_82 ] ) ;
F_66 ( V_28 , V_98 -> V_100 [ V_82 ] ) ;
}
F_77 ( V_28 , V_98 ) ;
}
static void F_126 ( struct V_116 * V_117 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ ) {
if ( V_117 -> V_106 . V_109 [ V_82 ] == V_117 -> V_121 . V_107 )
continue;
F_125 ( & V_117 -> V_121 , V_117 -> V_106 . V_109 [ V_82 ] ) ;
}
F_59 ( & V_117 -> V_121 , & V_117 -> V_106 ) ;
}
static void F_127 ( struct V_64 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_7 ;
struct V_116 * V_117 = F_110 ( V_28 ) ;
if ( F_8 ( V_2 ) )
F_122 ( V_117 , false ) ;
if ( F_73 ( V_28 ) )
F_126 ( V_117 ) ;
else
F_125 ( & V_117 -> V_121 , & V_117 -> V_98 ) ;
F_124 ( V_28 ) ;
}
static int F_128 ( struct V_64 * V_28 ,
struct V_91 * V_92 ,
T_7 V_31 , T_7 V_123 )
{
struct V_86 * V_87 ;
T_7 V_150 = V_31 ;
unsigned int V_50 ;
F_105 (pt, pd, start, length, pde) {
if ( V_87 == V_28 -> V_94 ) {
V_87 = F_53 ( V_28 ) ;
if ( F_85 ( V_87 ) )
goto V_151;
F_60 ( V_28 , V_87 ) ;
F_103 ( V_28 , V_92 , V_87 , V_50 ) ;
V_92 -> V_93 ++ ;
F_34 ( V_92 -> V_93 > V_95 ) ;
}
V_87 -> V_89 += F_100 ( V_31 , V_123 ) ;
}
return 0 ;
V_151:
F_104 ( V_28 , V_92 , V_150 , V_31 - V_150 ) ;
return - V_74 ;
}
static int F_129 ( struct V_64 * V_28 ,
struct V_97 * V_98 ,
T_7 V_31 , T_7 V_123 )
{
struct V_91 * V_92 ;
T_7 V_150 = V_31 ;
unsigned int V_127 ;
int V_25 ;
F_108 (pd, pdp, start, length, pdpe) {
if ( V_92 == V_28 -> V_101 ) {
V_92 = F_64 ( V_28 ) ;
if ( F_85 ( V_92 ) )
goto V_151;
F_67 ( V_28 , V_92 ) ;
F_106 ( V_28 , V_98 , V_92 , V_127 ) ;
V_98 -> V_128 ++ ;
F_34 ( V_98 -> V_128 > F_70 ( V_28 ) ) ;
F_97 ( F_110 ( V_28 ) ) ;
}
V_25 = F_128 ( V_28 , V_92 , V_31 , V_123 ) ;
if ( F_41 ( V_25 ) )
goto V_152;
}
return 0 ;
V_152:
if ( ! V_92 -> V_93 ) {
F_106 ( V_28 , V_98 , V_28 -> V_101 , V_127 ) ;
F_34 ( ! V_98 -> V_128 ) ;
V_98 -> V_128 -- ;
F_66 ( V_28 , V_92 ) ;
}
V_151:
F_107 ( V_28 , V_98 , V_150 , V_31 - V_150 ) ;
return - V_74 ;
}
static int F_130 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
return F_129 ( V_28 ,
& F_110 ( V_28 ) -> V_98 , V_31 , V_123 ) ;
}
static int F_131 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
struct V_105 * V_106 = & V_117 -> V_106 ;
struct V_97 * V_98 ;
T_7 V_150 = V_31 ;
T_1 V_129 ;
int V_25 ;
F_113 (pdp, pml4, start, length, pml4e) {
if ( V_106 -> V_109 [ V_129 ] == V_28 -> V_107 ) {
V_98 = F_75 ( V_28 ) ;
if ( F_85 ( V_98 ) )
goto V_151;
F_78 ( V_28 , V_98 ) ;
F_111 ( V_106 , V_98 , V_129 ) ;
}
V_25 = F_129 ( V_28 , V_98 , V_31 , V_123 ) ;
if ( F_41 ( V_25 ) )
goto V_153;
}
return 0 ;
V_153:
if ( ! V_98 -> V_128 ) {
F_111 ( V_106 , V_28 -> V_107 , V_129 ) ;
F_77 ( V_28 , V_98 ) ;
}
V_151:
F_112 ( V_28 , V_150 , V_31 - V_150 ) ;
return - V_74 ;
}
static void F_132 ( struct V_116 * V_117 ,
struct V_97 * V_98 ,
T_7 V_31 , T_7 V_123 ,
T_2 V_126 ,
struct V_154 * V_155 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_91 * V_92 ;
T_1 V_127 ;
F_108 (pd, pdp, start, length, pdpe) {
struct V_86 * V_87 ;
T_7 V_156 = V_123 ;
T_7 V_157 = V_31 ;
T_1 V_50 ;
if ( V_98 -> V_100 [ V_127 ] == V_117 -> V_121 . V_101 )
continue;
F_133 ( V_155 , L_3 , V_127 ) ;
F_105 (pt, pd, pd_start, pd_len, pde) {
T_1 V_42 ;
T_2 * V_158 ;
if ( V_92 -> V_96 [ V_50 ] == V_117 -> V_121 . V_94 )
continue;
V_158 = F_102 ( V_87 ) ;
for ( V_42 = 0 ; V_42 < V_136 ; V_42 += 4 ) {
T_7 V_159 = ( V_127 << V_160 |
V_50 << V_161 |
V_42 << V_162 ) ;
int V_82 ;
bool V_163 = false ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ )
if ( V_158 [ V_42 + V_82 ] != V_126 )
V_163 = true ;
if ( ! V_163 )
continue;
F_133 ( V_155 , L_4 , V_159 , V_127 , V_50 , V_42 ) ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
if ( V_158 [ V_42 + V_82 ] != V_126 )
F_133 ( V_155 , L_5 , V_158 [ V_42 + V_82 ] ) ;
else
F_134 ( V_155 , L_6 ) ;
}
F_134 ( V_155 , L_7 ) ;
}
F_49 ( V_158 ) ;
}
}
}
static void F_135 ( struct V_116 * V_117 , struct V_154 * V_155 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
const T_2 V_126 =
F_17 ( V_28 -> V_84 . V_75 , V_54 ) ;
T_7 V_31 = 0 , V_123 = V_117 -> V_121 . V_164 ;
if ( F_73 ( V_28 ) ) {
T_7 V_129 ;
struct V_105 * V_106 = & V_117 -> V_106 ;
struct V_97 * V_98 ;
F_113 (pdp, pml4, start, length, pml4e) {
if ( V_106 -> V_109 [ V_129 ] == V_117 -> V_121 . V_107 )
continue;
F_133 ( V_155 , L_8 , V_129 ) ;
F_132 ( V_117 , V_98 , V_31 , V_123 , V_126 , V_155 ) ;
}
} else {
F_132 ( V_117 , & V_117 -> V_98 , V_31 , V_123 , V_126 , V_155 ) ;
}
}
static int F_136 ( struct V_116 * V_117 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_97 * V_98 = & V_117 -> V_98 ;
struct V_91 * V_92 ;
T_7 V_31 = 0 , V_123 = V_117 -> V_121 . V_164 ;
T_7 V_150 = V_31 ;
unsigned int V_127 ;
F_108 (pd, pdp, start, length, pdpe) {
V_92 = F_64 ( V_28 ) ;
if ( F_85 ( V_92 ) )
goto V_151;
F_67 ( V_28 , V_92 ) ;
F_106 ( V_28 , V_98 , V_92 , V_127 ) ;
V_98 -> V_128 ++ ;
}
V_98 -> V_128 ++ ;
return 0 ;
V_151:
V_31 -= V_150 ;
F_108 (pd, pdp, from, start, pdpe) {
F_106 ( V_28 , V_98 , V_28 -> V_101 , V_127 ) ;
F_66 ( V_28 , V_92 ) ;
}
V_98 -> V_128 = 0 ;
return - V_74 ;
}
static int F_137 ( struct V_116 * V_117 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_1 * V_2 = V_28 -> V_7 ;
int V_25 ;
V_117 -> V_121 . V_164 = F_138 ( V_2 ) ?
1ULL << 48 :
1ULL << 32 ;
V_25 = F_121 ( & V_117 -> V_121 ) ;
if ( V_25 ) {
V_117 -> V_121 . V_164 = 0 ;
return V_25 ;
}
if ( F_139 ( V_2 ) || F_140 ( V_2 ) )
V_117 -> V_121 . V_69 = true ;
if ( F_73 ( V_28 ) ) {
V_25 = F_56 ( & V_117 -> V_121 , & V_117 -> V_106 ) ;
if ( V_25 )
goto V_165;
F_80 ( & V_117 -> V_121 , & V_117 -> V_106 ) ;
V_117 -> V_166 = F_96 ;
V_117 -> V_121 . V_29 = F_131 ;
V_117 -> V_121 . V_38 = F_118 ;
V_117 -> V_121 . V_39 = F_112 ;
} else {
V_25 = F_69 ( & V_117 -> V_121 , & V_117 -> V_98 ) ;
if ( V_25 )
goto V_165;
if ( F_8 ( V_2 ) ) {
V_25 = F_136 ( V_117 ) ;
if ( V_25 ) {
F_72 ( & V_117 -> V_98 ) ;
goto V_165;
}
}
V_117 -> V_166 = F_94 ;
V_117 -> V_121 . V_29 = F_130 ;
V_117 -> V_121 . V_38 = F_117 ;
V_117 -> V_121 . V_39 = F_109 ;
}
if ( F_8 ( V_2 ) )
F_122 ( V_117 , true ) ;
V_117 -> V_121 . V_167 = F_127 ;
V_117 -> V_121 . V_168 = F_16 ;
V_117 -> V_121 . V_169 = F_15 ;
V_117 -> V_170 = F_135 ;
return 0 ;
V_165:
F_124 ( & V_117 -> V_121 ) ;
return V_25 ;
}
static void F_141 ( struct V_116 * V_117 , struct V_154 * V_155 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_86 * V_23 ;
T_5 V_126 ;
T_1 V_171 , V_42 , V_50 ;
T_1 V_31 = 0 , V_123 = V_117 -> V_121 . V_164 ;
V_126 = V_28 -> V_90 ( V_28 -> V_84 . V_75 ,
V_54 , 0 ) ;
F_142 (unused, &ppgtt->pd, start, length, pde) {
T_1 V_172 ;
T_5 * V_158 ;
const T_3 V_173 = F_68 ( V_117 -> V_92 . V_96 [ V_50 ] ) ;
V_171 = F_143 ( V_117 -> V_174 + V_50 ) ;
V_172 = ( F_144 ( V_173 ) | V_175 ) ;
if ( V_171 != V_172 )
F_133 ( V_155 , L_9 ,
V_50 ,
V_171 ,
V_172 ) ;
F_133 ( V_155 , L_10 , V_171 ) ;
V_158 = F_102 ( V_117 -> V_92 . V_96 [ V_50 ] ) ;
for ( V_42 = 0 ; V_42 < V_176 ; V_42 += 4 ) {
unsigned long V_159 =
( V_50 * V_77 * V_176 ) +
( V_42 * V_77 ) ;
int V_82 ;
bool V_163 = false ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ )
if ( V_158 [ V_42 + V_82 ] != V_126 )
V_163 = true ;
if ( ! V_163 )
continue;
F_133 ( V_155 , L_11 , V_159 , V_50 , V_42 ) ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
if ( V_158 [ V_42 + V_82 ] != V_126 )
F_133 ( V_155 , L_12 , V_158 [ V_42 + V_82 ] ) ;
else
F_134 ( V_155 , L_6 ) ;
}
F_134 ( V_155 , L_7 ) ;
}
F_49 ( V_158 ) ;
}
}
static inline void F_145 ( const struct V_116 * V_117 ,
const unsigned int V_50 ,
const struct V_86 * V_87 )
{
F_146 ( F_144 ( F_68 ( V_87 ) ) | V_175 ,
V_117 -> V_174 + V_50 ) ;
}
static void F_147 ( struct V_116 * V_117 ,
T_1 V_31 , T_1 V_123 )
{
struct V_86 * V_87 ;
unsigned int V_50 ;
F_142 (pt, &ppgtt->pd, start, length, pde)
F_145 ( V_117 , V_50 , V_87 ) ;
F_97 ( V_117 ) ;
F_148 () ;
}
static inline T_1 F_149 ( struct V_116 * V_117 )
{
F_34 ( V_117 -> V_92 . V_121 . V_177 & 0x3f ) ;
return V_117 -> V_92 . V_121 . V_177 << 10 ;
}
static int F_150 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
T_1 * V_115 ;
V_115 = F_84 ( V_111 , 6 ) ;
if ( F_85 ( V_115 ) )
return F_86 ( V_115 ) ;
* V_115 ++ = F_87 ( 2 ) ;
* V_115 ++ = F_88 ( F_151 ( V_114 ) ) ;
* V_115 ++ = V_178 ;
* V_115 ++ = F_88 ( F_152 ( V_114 ) ) ;
* V_115 ++ = F_149 ( V_117 ) ;
* V_115 ++ = V_179 ;
F_93 ( V_111 , V_115 ) ;
return 0 ;
}
static int F_153 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
T_1 * V_115 ;
V_115 = F_84 ( V_111 , 6 ) ;
if ( F_85 ( V_115 ) )
return F_86 ( V_115 ) ;
* V_115 ++ = F_87 ( 2 ) ;
* V_115 ++ = F_88 ( F_151 ( V_114 ) ) ;
* V_115 ++ = V_178 ;
* V_115 ++ = F_88 ( F_152 ( V_114 ) ) ;
* V_115 ++ = F_149 ( V_117 ) ;
* V_115 ++ = V_179 ;
F_93 ( V_111 , V_115 ) ;
return 0 ;
}
static int F_154 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
struct V_1 * V_2 = V_111 -> V_7 ;
F_2 ( F_151 ( V_114 ) , V_178 ) ;
F_2 ( F_152 ( V_114 ) , F_149 ( V_117 ) ) ;
return 0 ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
enum V_180 V_181 ;
F_156 (engine, dev_priv, id) {
T_1 V_182 = F_138 ( V_2 ) ?
V_183 : 0 ;
F_2 ( F_157 ( V_114 ) ,
F_158 ( V_184 | V_182 ) ) ;
}
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
T_1 V_185 , V_186 ;
enum V_180 V_181 ;
V_186 = F_160 ( V_187 ) ;
F_2 ( V_187 , V_186 | V_188 ) ;
V_185 = F_160 ( V_189 ) ;
if ( F_161 ( V_2 ) ) {
V_185 |= V_190 ;
} else {
V_185 |= V_191 ;
V_185 &= ~ V_192 ;
}
F_2 ( V_189 , V_185 ) ;
F_156 (engine, dev_priv, id) {
F_2 ( F_157 ( V_114 ) ,
F_158 ( V_184 ) ) ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
T_1 V_185 , V_193 , V_186 ;
V_186 = F_160 ( V_187 ) ;
F_2 ( V_187 , V_186 | V_194 |
V_188 ) ;
V_193 = F_160 ( V_195 ) ;
F_2 ( V_195 , V_193 | V_196 ) ;
V_185 = F_160 ( V_189 ) ;
F_2 ( V_189 , V_185 | V_197 | V_198 ) ;
F_2 ( V_199 , F_158 ( V_184 ) ) ;
}
static void F_163 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
unsigned int V_200 = V_31 >> V_201 ;
unsigned int V_50 = V_200 / V_176 ;
unsigned int V_42 = V_200 % V_176 ;
unsigned int V_124 = V_123 >> V_201 ;
T_5 V_126 =
V_28 -> V_90 ( V_28 -> V_84 . V_75 , V_54 , 0 ) ;
while ( V_124 ) {
struct V_86 * V_87 = V_117 -> V_92 . V_96 [ V_50 ++ ] ;
unsigned int V_202 = F_164 ( V_42 + V_124 , V_176 ) ;
T_5 * V_81 ;
V_124 -= V_202 - V_42 ;
V_81 = F_102 ( V_87 ) ;
do {
V_81 [ V_42 ++ ] = V_126 ;
} while ( V_42 < V_202 );
F_49 ( V_81 ) ;
V_42 = 0 ;
}
}
static void F_165 ( struct V_64 * V_28 ,
struct V_137 * V_33 ,
T_7 V_31 ,
enum V_21 V_22 ,
T_1 V_26 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
unsigned V_200 = V_31 >> V_201 ;
unsigned V_203 = V_200 / V_176 ;
unsigned V_204 = V_200 % V_176 ;
const T_1 V_90 = V_28 -> V_90 ( 0 , V_22 , V_26 ) ;
struct V_130 V_131 ;
T_5 * V_81 ;
V_81 = F_102 ( V_117 -> V_92 . V_96 [ V_203 ] ) ;
V_131 . V_135 = V_33 -> V_138 ;
V_131 . V_76 = F_116 ( V_131 . V_135 ) ;
V_131 . V_134 = V_131 . V_76 + V_131 . V_135 -> V_123 ;
do {
V_81 [ V_204 ] = V_90 | F_20 ( V_131 . V_76 ) ;
V_131 . V_76 += V_77 ;
if ( V_131 . V_76 == V_131 . V_134 ) {
V_131 . V_135 = F_115 ( V_131 . V_135 ) ;
if ( ! V_131 . V_135 )
break;
V_131 . V_76 = F_116 ( V_131 . V_135 ) ;
V_131 . V_134 = V_131 . V_76 + V_131 . V_135 -> V_123 ;
}
if ( ++ V_204 == V_176 ) {
F_49 ( V_81 ) ;
V_81 = F_102 ( V_117 -> V_92 . V_96 [ ++ V_203 ] ) ;
V_204 = 0 ;
}
} while ( 1 );
F_49 ( V_81 ) ;
}
static int F_166 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
struct V_86 * V_87 ;
T_7 V_150 = V_31 ;
unsigned int V_50 ;
bool V_205 = false ;
F_142 (pt, &ppgtt->pd, start, length, pde) {
if ( V_87 == V_28 -> V_94 ) {
V_87 = F_53 ( V_28 ) ;
if ( F_85 ( V_87 ) )
goto V_206;
F_62 ( V_28 , V_87 ) ;
V_117 -> V_92 . V_96 [ V_50 ] = V_87 ;
F_145 ( V_117 , V_50 , V_87 ) ;
V_205 = true ;
}
}
if ( V_205 ) {
F_97 ( V_117 ) ;
F_148 () ;
}
return 0 ;
V_206:
F_163 ( V_28 , V_150 , V_31 ) ;
return - V_74 ;
}
static int F_167 ( struct V_64 * V_28 )
{
int V_25 ;
V_25 = F_51 ( V_28 , V_79 ) ;
if ( V_25 )
return V_25 ;
V_28 -> V_94 = F_53 ( V_28 ) ;
if ( F_85 ( V_28 -> V_94 ) ) {
F_52 ( V_28 ) ;
return F_86 ( V_28 -> V_94 ) ;
}
F_62 ( V_28 , V_28 -> V_94 ) ;
return 0 ;
}
static void F_168 ( struct V_64 * V_28 )
{
F_58 ( V_28 , V_28 -> V_94 ) ;
F_52 ( V_28 ) ;
}
static void F_169 ( struct V_64 * V_28 )
{
struct V_116 * V_117 = F_110 ( V_28 ) ;
struct V_91 * V_92 = & V_117 -> V_92 ;
struct V_86 * V_87 ;
T_1 V_50 ;
F_170 ( & V_117 -> V_30 ) ;
F_171 (pt, pd, pde)
if ( V_87 != V_28 -> V_94 )
F_58 ( V_28 , V_87 ) ;
F_168 ( V_28 ) ;
}
static int F_172 ( struct V_116 * V_117 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_1 * V_2 = V_117 -> V_121 . V_7 ;
struct V_207 * V_8 = & V_2 -> V_8 ;
int V_25 ;
F_83 ( ! F_173 ( & V_8 -> V_121 . V_35 ) ) ;
V_25 = F_167 ( V_28 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_174 ( & V_8 -> V_121 , & V_117 -> V_30 ,
V_208 , V_209 ,
V_210 ,
0 , V_8 -> V_121 . V_164 ,
V_211 ) ;
if ( V_25 )
goto V_212;
if ( V_117 -> V_30 . V_31 < V_8 -> V_213 )
F_175 ( L_13 ) ;
V_117 -> V_92 . V_121 . V_177 =
V_117 -> V_30 . V_31 / V_77 * sizeof( T_5 ) ;
V_117 -> V_174 = ( T_5 V_214 * ) V_8 -> V_215 +
V_117 -> V_92 . V_121 . V_177 / sizeof( T_5 ) ;
return 0 ;
V_212:
F_168 ( V_28 ) ;
return V_25 ;
}
static int F_176 ( struct V_116 * V_117 )
{
return F_172 ( V_117 ) ;
}
static void F_177 ( struct V_116 * V_117 ,
T_7 V_31 , T_7 V_123 )
{
struct V_86 * V_23 ;
T_1 V_50 ;
F_142 (unused, &ppgtt->pd, start, length, pde)
V_117 -> V_92 . V_96 [ V_50 ] = V_117 -> V_121 . V_94 ;
}
static int F_178 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_121 . V_7 ;
struct V_207 * V_8 = & V_2 -> V_8 ;
int V_25 ;
V_117 -> V_121 . V_90 = V_8 -> V_121 . V_90 ;
if ( F_8 ( V_2 ) || F_10 ( V_2 ) )
V_117 -> V_166 = F_154 ;
else if ( F_161 ( V_2 ) )
V_117 -> V_166 = F_150 ;
else if ( F_179 ( V_2 ) )
V_117 -> V_166 = F_153 ;
else
F_180 () ;
V_25 = F_176 ( V_117 ) ;
if ( V_25 )
return V_25 ;
V_117 -> V_121 . V_164 = V_95 * V_176 * V_77 ;
F_177 ( V_117 , 0 , V_117 -> V_121 . V_164 ) ;
F_147 ( V_117 , 0 , V_117 -> V_121 . V_164 ) ;
V_25 = F_166 ( & V_117 -> V_121 , 0 , V_117 -> V_121 . V_164 ) ;
if ( V_25 ) {
F_169 ( & V_117 -> V_121 ) ;
return V_25 ;
}
V_117 -> V_121 . V_39 = F_163 ;
V_117 -> V_121 . V_38 = F_165 ;
V_117 -> V_121 . V_168 = F_16 ;
V_117 -> V_121 . V_169 = F_15 ;
V_117 -> V_121 . V_167 = F_169 ;
V_117 -> V_170 = F_141 ;
F_14 ( L_14 ,
V_117 -> V_30 . V_32 >> 20 ,
V_117 -> V_30 . V_31 / V_77 ) ;
F_14 ( L_15 ,
V_117 -> V_92 . V_121 . V_177 << 10 ) ;
return 0 ;
}
static int F_181 ( struct V_116 * V_117 ,
struct V_1 * V_2 )
{
V_117 -> V_121 . V_7 = V_2 ;
V_117 -> V_121 . V_76 = & V_2 -> V_15 . V_16 -> V_216 ;
if ( F_98 ( V_2 ) -> V_217 < 8 )
return F_178 ( V_117 ) ;
else
return F_137 ( V_117 ) ;
}
static void F_182 ( struct V_64 * V_28 ,
struct V_1 * V_2 ,
const char * V_218 )
{
F_183 ( V_2 , & V_28 -> V_219 , V_218 ) ;
F_184 ( & V_28 -> V_35 , 0 , V_28 -> V_164 ) ;
V_28 -> V_35 . V_220 . V_221 = V_210 ;
F_185 ( & V_28 -> V_222 ) ;
F_185 ( & V_28 -> V_223 ) ;
F_185 ( & V_28 -> V_224 ) ;
F_186 ( & V_28 -> V_225 , & V_2 -> V_226 ) ;
F_187 ( & V_28 -> V_67 , false ) ;
}
static void F_188 ( struct V_64 * V_28 )
{
if ( F_35 ( & V_28 -> V_67 ) )
F_33 ( V_28 ) ;
F_189 ( & V_28 -> V_219 ) ;
F_190 ( & V_28 -> V_35 ) ;
F_191 ( & V_28 -> V_225 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
if ( F_193 ( V_2 ) )
F_2 ( V_227 , V_228 ) ;
else if ( F_139 ( V_2 ) )
F_2 ( V_227 , V_229 ) ;
else if ( F_194 ( V_2 ) )
F_2 ( V_227 , V_230 ) ;
else if ( F_195 ( V_2 ) )
F_2 ( V_227 , V_231 ) ;
}
int F_196 ( struct V_1 * V_2 )
{
F_192 ( V_2 ) ;
if ( V_7 . V_18 )
return 0 ;
if ( ! F_197 ( V_2 ) )
return 0 ;
if ( F_10 ( V_2 ) )
F_162 ( V_2 ) ;
else if ( F_179 ( V_2 ) )
F_159 ( V_2 ) ;
else if ( F_9 ( V_2 ) >= 8 )
F_155 ( V_2 ) ;
else
F_21 ( F_9 ( V_2 ) ) ;
return 0 ;
}
struct V_116 *
F_198 ( struct V_1 * V_2 ,
struct V_232 * V_233 ,
const char * V_218 )
{
struct V_116 * V_117 ;
int V_25 ;
V_117 = F_65 ( sizeof( * V_117 ) , V_88 ) ;
if ( ! V_117 )
return F_55 ( - V_74 ) ;
V_25 = F_181 ( V_117 , V_2 ) ;
if ( V_25 ) {
F_57 ( V_117 ) ;
return F_55 ( V_25 ) ;
}
F_199 ( & V_117 -> V_234 ) ;
F_182 ( & V_117 -> V_121 , V_2 , V_218 ) ;
V_117 -> V_121 . V_235 = V_233 ;
F_200 ( & V_117 -> V_121 ) ;
return V_117 ;
}
void F_201 ( struct V_64 * V_28 )
{
struct V_236 * V_237 [] = {
& V_28 -> V_222 ,
& V_28 -> V_223 ,
& V_28 -> V_224 ,
NULL ,
} , * * V_238 ;
F_34 ( V_28 -> V_239 ) ;
V_28 -> V_239 = true ;
for ( V_238 = V_237 ; * V_238 ; V_238 ++ ) {
struct V_19 * V_20 , * V_240 ;
F_202 (vma, vn, *phase, vm_link)
if ( ! F_203 ( V_20 ) )
F_204 ( V_20 ) ;
}
}
void F_205 ( struct V_241 * V_241 )
{
struct V_116 * V_117 =
F_206 ( V_241 , struct V_116 , V_234 ) ;
F_207 ( & V_117 -> V_121 ) ;
F_76 ( ! F_208 ( & V_117 -> V_121 . V_222 ) ) ;
F_76 ( ! F_208 ( & V_117 -> V_121 . V_223 ) ) ;
F_76 ( ! F_208 ( & V_117 -> V_121 . V_224 ) ) ;
V_117 -> V_121 . V_167 ( & V_117 -> V_121 ) ;
F_188 ( & V_117 -> V_121 ) ;
F_57 ( V_117 ) ;
}
static bool F_209 ( struct V_1 * V_2 )
{
return F_210 ( V_2 ) && F_211 ( V_2 ) && F_11 () ;
}
void F_212 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
enum V_180 V_181 ;
if ( F_98 ( V_2 ) -> V_217 < 6 )
return;
F_156 (engine, dev_priv, id) {
T_1 V_242 ;
V_242 = F_160 ( F_213 ( V_114 ) ) ;
if ( V_242 & V_243 ) {
F_14 ( L_16
L_17
L_18
L_19
L_20 ,
V_242 & V_244 ,
V_242 & V_245 ? L_21 : L_22 ,
F_214 ( V_242 ) ,
F_215 ( V_242 ) ) ;
F_2 ( F_213 ( V_114 ) ,
V_242 & ~ V_243 ) ;
}
}
if ( V_2 -> V_114 [ V_246 ] )
F_216 ( F_213 ( V_2 -> V_114 [ V_246 ] ) ) ;
}
void F_217 ( struct V_1 * V_2 )
{
struct V_207 * V_8 = & V_2 -> V_8 ;
if ( F_9 ( V_2 ) < 6 )
return;
F_212 ( V_2 ) ;
V_8 -> V_121 . V_39 ( & V_8 -> V_121 , 0 , V_8 -> V_121 . V_164 ) ;
F_6 ( V_2 ) ;
}
int F_218 ( struct V_247 * V_34 ,
struct V_137 * V_33 )
{
do {
if ( F_219 ( & V_34 -> V_121 . V_216 -> V_16 -> V_216 ,
V_33 -> V_138 , V_33 -> V_248 ,
V_78 ) )
return 0 ;
F_34 ( V_34 -> V_35 . V_33 == V_33 ) ;
} while ( F_220 ( F_221 ( V_34 -> V_121 . V_216 ) ,
V_34 -> V_121 . V_32 >> V_201 ,
V_249 |
V_250 |
V_251 ) );
return - V_252 ;
}
static void F_222 ( void V_214 * V_40 , T_2 V_42 )
{
F_223 ( V_42 , V_40 ) ;
}
static void F_224 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_207 * V_8 = F_225 ( V_28 ) ;
T_2 V_214 * V_42 =
( T_2 V_214 * ) V_8 -> V_215 + ( V_253 >> V_201 ) ;
F_222 ( V_42 , F_17 ( V_40 , V_41 ) ) ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_226 ( struct V_64 * V_28 ,
struct V_137 * V_254 ,
T_7 V_31 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_207 * V_8 = F_225 ( V_28 ) ;
struct V_255 V_255 ;
T_2 V_214 * V_256 ;
const T_2 V_90 = F_17 ( 0 , V_41 ) ;
T_3 V_40 ;
V_256 = ( T_2 V_214 * ) V_8 -> V_215 ;
V_256 += V_31 >> V_201 ;
F_227 (addr, sgt_iter, st)
F_222 ( V_256 ++ , V_90 | V_40 ) ;
F_148 () ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_228 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_41 ,
T_1 V_26 )
{
struct V_207 * V_8 = F_225 ( V_28 ) ;
T_5 V_214 * V_42 =
( T_5 V_214 * ) V_8 -> V_215 + ( V_253 >> V_201 ) ;
F_229 ( V_28 -> V_90 ( V_40 , V_41 , V_26 ) , V_42 ) ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_230 ( struct V_64 * V_28 ,
struct V_137 * V_254 ,
T_7 V_31 ,
enum V_21 V_41 ,
T_1 V_26 )
{
struct V_207 * V_8 = F_225 ( V_28 ) ;
T_5 V_214 * V_257 = ( T_5 V_214 * ) V_8 -> V_215 ;
unsigned int V_82 = V_31 >> V_201 ;
struct V_255 V_131 ;
T_3 V_40 ;
F_227 (addr, iter, st)
F_229 ( V_28 -> V_90 ( V_40 , V_41 , V_26 ) , & V_257 [ V_82 ++ ] ) ;
F_148 () ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_231 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
}
static void F_232 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_207 * V_8 = F_225 ( V_28 ) ;
unsigned V_200 = V_31 >> V_201 ;
unsigned V_124 = V_123 >> V_201 ;
const T_2 V_126 =
F_17 ( V_28 -> V_84 . V_75 , V_54 ) ;
T_2 V_214 * V_258 =
( T_2 V_214 * ) V_8 -> V_215 + V_200 ;
const int V_259 = F_233 ( V_8 ) - V_200 ;
int V_82 ;
if ( F_234 ( V_124 > V_259 ,
L_23 ,
V_200 , V_124 , V_259 ) )
V_124 = V_259 ;
for ( V_82 = 0 ; V_82 < V_124 ; V_82 ++ )
F_222 ( & V_258 [ V_82 ] , V_126 ) ;
}
static void F_235 ( struct V_64 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_7 ;
F_216 ( V_3 ) ;
}
static int F_236 ( void * V_260 )
{
struct V_261 * V_262 = V_260 ;
F_224 ( V_262 -> V_28 , V_262 -> V_40 , V_262 -> V_253 , V_262 -> V_41 , 0 ) ;
F_235 ( V_262 -> V_28 ) ;
return 0 ;
}
static void F_237 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_261 V_262 = { V_28 , V_40 , V_253 , V_41 } ;
F_238 ( F_236 , & V_262 , NULL ) ;
}
static int F_239 ( void * V_260 )
{
struct V_38 * V_262 = V_260 ;
F_226 ( V_262 -> V_28 , V_262 -> V_254 , V_262 -> V_31 , V_262 -> V_41 , 0 ) ;
F_235 ( V_262 -> V_28 ) ;
return 0 ;
}
static void F_240 ( struct V_64 * V_28 ,
struct V_137 * V_254 ,
T_7 V_31 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_38 V_262 = { V_28 , V_254 , V_31 , V_41 } ;
F_238 ( F_239 , & V_262 , NULL ) ;
}
static int F_241 ( void * V_260 )
{
struct V_39 * V_262 = V_260 ;
F_232 ( V_262 -> V_28 , V_262 -> V_31 , V_262 -> V_123 ) ;
F_235 ( V_262 -> V_28 ) ;
return 0 ;
}
static void F_242 ( struct V_64 * V_28 ,
T_7 V_31 ,
T_7 V_123 )
{
struct V_39 V_262 = { V_28 , V_31 , V_123 } ;
F_238 ( F_241 , & V_262 , NULL ) ;
}
static void F_243 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_207 * V_8 = F_225 ( V_28 ) ;
unsigned V_200 = V_31 >> V_201 ;
unsigned V_124 = V_123 >> V_201 ;
T_5 V_126 , V_214 * V_258 =
( T_5 V_214 * ) V_8 -> V_215 + V_200 ;
const int V_259 = F_233 ( V_8 ) - V_200 ;
int V_82 ;
if ( F_234 ( V_124 > V_259 ,
L_23 ,
V_200 , V_124 , V_259 ) )
V_124 = V_259 ;
V_126 = V_28 -> V_90 ( V_28 -> V_84 . V_75 ,
V_54 , 0 ) ;
for ( V_82 = 0 ; V_82 < V_124 ; V_82 ++ )
F_229 ( V_126 , & V_258 [ V_82 ] ) ;
}
static void F_244 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_22 ,
T_1 V_23 )
{
unsigned int V_26 = ( V_22 == V_45 ) ?
V_263 : V_264 ;
F_245 ( V_40 , V_253 >> V_201 , V_26 ) ;
}
static void F_246 ( struct V_64 * V_28 ,
struct V_137 * V_33 ,
T_7 V_31 ,
enum V_21 V_22 ,
T_1 V_23 )
{
unsigned int V_26 = ( V_22 == V_45 ) ?
V_263 : V_264 ;
F_247 ( V_33 , V_31 >> V_201 , V_26 ) ;
}
static void F_248 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
F_249 ( V_31 >> V_201 , V_123 >> V_201 ) ;
}
static int F_250 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_26 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
struct V_247 * V_34 = V_20 -> V_34 ;
T_1 V_24 ;
if ( F_41 ( ! V_20 -> V_33 ) ) {
int V_25 = F_251 ( V_20 ) ;
if ( V_25 )
return V_25 ;
}
V_24 = 0 ;
if ( V_34 -> V_36 )
V_24 |= V_37 ;
F_252 ( V_7 ) ;
V_20 -> V_28 -> V_38 ( V_20 -> V_28 , V_20 -> V_33 , V_20 -> V_30 . V_31 ,
V_22 , V_24 ) ;
F_253 ( V_7 ) ;
V_20 -> V_26 |= V_265 | V_27 ;
return 0 ;
}
static void F_254 ( struct V_19 * V_20 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
F_252 ( V_7 ) ;
V_20 -> V_28 -> V_39 ( V_20 -> V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_253 ( V_7 ) ;
}
static int F_255 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_26 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
T_1 V_24 ;
int V_25 ;
if ( F_41 ( ! V_20 -> V_33 ) ) {
V_25 = F_251 ( V_20 ) ;
if ( V_25 )
return V_25 ;
}
V_24 = 0 ;
if ( V_20 -> V_34 -> V_36 )
V_24 |= V_37 ;
if ( V_26 & V_27 ) {
struct V_116 * V_266 = V_7 -> V_35 . V_267 ;
if ( ! ( V_20 -> V_26 & V_27 ) &&
V_266 -> V_121 . V_29 ) {
V_25 = V_266 -> V_121 . V_29 ( & V_266 -> V_121 ,
V_20 -> V_30 . V_31 ,
V_20 -> V_32 ) ;
if ( V_25 )
goto V_268;
}
V_266 -> V_121 . V_38 ( & V_266 -> V_121 ,
V_20 -> V_33 , V_20 -> V_30 . V_31 ,
V_22 , V_24 ) ;
}
if ( V_26 & V_265 ) {
F_252 ( V_7 ) ;
V_20 -> V_28 -> V_38 ( V_20 -> V_28 ,
V_20 -> V_33 , V_20 -> V_30 . V_31 ,
V_22 , V_24 ) ;
F_253 ( V_7 ) ;
}
return 0 ;
V_268:
if ( ! ( V_20 -> V_26 & ( V_265 | V_27 ) ) ) {
if ( V_20 -> V_33 != V_20 -> V_34 -> V_35 . V_33 ) {
F_34 ( ! V_20 -> V_33 ) ;
F_256 ( V_20 -> V_33 ) ;
F_57 ( V_20 -> V_33 ) ;
}
V_20 -> V_33 = NULL ;
}
return V_25 ;
}
static void F_257 ( struct V_19 * V_20 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
if ( V_20 -> V_26 & V_265 ) {
F_252 ( V_7 ) ;
V_20 -> V_28 -> V_39 ( V_20 -> V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_253 ( V_7 ) ;
}
if ( V_20 -> V_26 & V_27 ) {
struct V_64 * V_28 = & V_7 -> V_35 . V_267 -> V_121 ;
V_28 -> V_39 ( V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
}
}
void F_258 ( struct V_247 * V_34 ,
struct V_137 * V_33 )
{
struct V_1 * V_2 = F_221 ( V_34 -> V_121 . V_216 ) ;
struct V_269 * V_270 = & V_2 -> V_15 . V_16 -> V_216 ;
struct V_207 * V_8 = & V_2 -> V_8 ;
if ( F_41 ( V_8 -> V_271 ) ) {
if ( F_259 ( V_2 , 0 ) ) {
F_260 ( L_24 ) ;
F_261 ( 10 ) ;
}
}
F_262 ( V_270 , V_33 -> V_138 , V_33 -> V_248 , V_78 ) ;
}
static void F_263 ( const struct V_272 * V_30 ,
unsigned long V_221 ,
T_7 * V_31 ,
T_7 * V_202 )
{
if ( V_30 -> V_273 && V_30 -> V_221 != V_221 )
* V_31 += V_274 ;
V_30 = F_264 ( V_30 , V_275 ) ;
if ( V_30 -> V_221 != V_221 )
* V_202 -= V_274 ;
}
int F_265 ( struct V_1 * V_7 )
{
struct V_207 * V_8 = & V_7 -> V_8 ;
struct V_116 * V_117 ;
int V_276 ;
V_117 = F_198 ( V_7 , F_55 ( - V_277 ) , L_25 ) ;
if ( F_85 ( V_117 ) )
return F_86 ( V_117 ) ;
if ( F_76 ( V_117 -> V_121 . V_164 < V_8 -> V_121 . V_164 ) ) {
V_276 = - V_278 ;
goto V_279;
}
if ( V_117 -> V_121 . V_29 ) {
V_276 = V_117 -> V_121 . V_29 ( & V_117 -> V_121 ,
0 , V_8 -> V_121 . V_164 ) ;
if ( V_276 )
goto V_279;
}
V_7 -> V_35 . V_267 = V_117 ;
F_76 ( V_8 -> V_121 . V_169 != F_250 ) ;
V_8 -> V_121 . V_169 = F_255 ;
F_76 ( V_8 -> V_121 . V_168 != F_254 ) ;
V_8 -> V_121 . V_168 = F_257 ;
return 0 ;
V_279:
F_266 ( V_117 ) ;
return V_276 ;
}
void F_267 ( struct V_1 * V_7 )
{
struct V_207 * V_8 = & V_7 -> V_8 ;
struct V_116 * V_117 ;
V_117 = F_268 ( & V_7 -> V_35 . V_267 ) ;
if ( ! V_117 )
return;
F_266 ( V_117 ) ;
V_8 -> V_121 . V_169 = F_250 ;
V_8 -> V_121 . V_168 = F_254 ;
}
int F_269 ( struct V_1 * V_2 )
{
struct V_207 * V_8 = & V_2 -> V_8 ;
unsigned long V_280 , V_281 ;
struct V_272 * V_112 ;
int V_25 ;
V_25 = F_270 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_271 ( & V_8 -> V_121 . V_35 , & V_8 -> V_282 ,
V_77 , 0 , V_210 ,
0 , V_8 -> V_213 ,
V_283 ) ;
if ( V_25 )
return V_25 ;
F_272 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_273 ( L_26 ,
V_280 , V_281 ) ;
V_8 -> V_121 . V_39 ( & V_8 -> V_121 , V_280 ,
V_281 - V_280 ) ;
}
V_8 -> V_121 . V_39 ( & V_8 -> V_121 ,
V_8 -> V_121 . V_164 - V_77 , V_77 ) ;
if ( F_197 ( V_2 ) && ! F_274 ( V_2 ) ) {
V_25 = F_265 ( V_2 ) ;
if ( V_25 )
goto V_276;
}
return 0 ;
V_276:
F_170 ( & V_8 -> V_282 ) ;
return V_25 ;
}
void F_275 ( struct V_1 * V_2 )
{
struct V_207 * V_8 = & V_2 -> V_8 ;
struct V_19 * V_20 , * V_240 ;
V_8 -> V_121 . V_239 = true ;
F_276 ( & V_2 -> V_15 . V_284 ) ;
F_76 ( ! F_208 ( & V_8 -> V_121 . V_222 ) ) ;
F_202 (vma, vn, &ggtt->base.inactive_list, vm_link)
F_76 ( F_277 ( V_20 ) ) ;
F_278 ( & V_2 -> V_15 . V_284 ) ;
F_279 ( & V_2 -> V_15 ) ;
F_276 ( & V_2 -> V_15 . V_284 ) ;
F_267 ( V_2 ) ;
if ( F_280 ( & V_8 -> V_282 ) )
F_170 ( & V_8 -> V_282 ) ;
if ( F_173 ( & V_8 -> V_121 . V_35 ) ) {
F_281 ( V_2 ) ;
F_188 ( & V_8 -> V_121 ) ;
}
V_8 -> V_121 . V_167 ( & V_8 -> V_121 ) ;
F_278 ( & V_2 -> V_15 . V_284 ) ;
F_282 ( V_8 -> V_285 ) ;
F_283 ( & V_8 -> V_286 ) ;
}
static unsigned int F_284 ( T_11 V_287 )
{
V_287 >>= V_288 ;
V_287 &= V_289 ;
return V_287 << 20 ;
}
static unsigned int F_285 ( T_11 V_290 )
{
V_290 >>= V_291 ;
V_290 &= V_292 ;
if ( V_290 )
V_290 = 1 << V_290 ;
#ifdef F_286
if ( V_290 > 4 )
V_290 = 4 ;
#endif
return V_290 << 20 ;
}
static unsigned int F_287 ( T_11 V_293 )
{
V_293 >>= V_288 ;
V_293 &= V_289 ;
if ( V_293 )
return 1 << ( 20 + V_293 ) ;
return 0 ;
}
static T_12 F_288 ( T_11 V_287 )
{
V_287 >>= V_294 ;
V_287 &= V_295 ;
return ( T_12 ) V_287 << 25 ;
}
static T_12 F_289 ( T_11 V_290 )
{
V_290 >>= V_296 ;
V_290 &= V_297 ;
return ( T_12 ) V_290 << 25 ;
}
static T_12 F_290 ( T_11 V_293 )
{
V_293 >>= V_294 ;
V_293 &= V_295 ;
if ( V_293 < 0x11 )
return ( T_12 ) V_293 << 25 ;
else if ( V_293 < 0x17 )
return ( T_12 ) ( V_293 - 0x11 + 2 ) << 22 ;
else
return ( T_12 ) ( V_293 - 0x17 + 9 ) << 22 ;
}
static T_12 F_291 ( T_11 V_298 )
{
V_298 >>= V_296 ;
V_298 &= V_297 ;
if ( V_298 < 0xf0 )
return ( T_12 ) V_298 << 25 ;
else
return ( T_12 ) ( V_298 - 0xf0 + 1 ) << 22 ;
}
static int F_292 ( struct V_207 * V_8 , T_7 V_32 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
struct V_299 * V_16 = V_2 -> V_15 . V_16 ;
T_13 V_300 ;
int V_25 ;
V_300 = F_293 ( V_16 , 0 ) + F_294 ( V_16 , 0 ) / 2 ;
if ( F_195 ( V_2 ) )
V_8 -> V_215 = F_295 ( V_300 , V_32 ) ;
else
V_8 -> V_215 = F_296 ( V_300 , V_32 ) ;
if ( ! V_8 -> V_215 ) {
F_260 ( L_27 ) ;
return - V_74 ;
}
V_25 = F_51 ( & V_8 -> V_121 , V_301 ) ;
if ( V_25 ) {
F_260 ( L_28 ) ;
F_297 ( V_8 -> V_215 ) ;
return V_25 ;
}
return 0 ;
}
static void F_298 ( struct V_1 * V_2 )
{
T_7 V_302 ;
V_302 = F_299 ( 0 , V_303 | V_304 ) |
F_299 ( 1 , V_305 | V_306 ) |
F_299 ( 2 , V_307 | V_306 ) |
F_299 ( 3 , V_308 ) |
F_299 ( 4 , V_303 | V_306 | F_300 ( 0 ) ) |
F_299 ( 5 , V_303 | V_306 | F_300 ( 1 ) ) |
F_299 ( 6 , V_303 | V_306 | F_300 ( 2 ) ) |
F_299 ( 7 , V_303 | V_306 | F_300 ( 3 ) ) ;
if ( ! F_197 ( V_2 ) )
V_302 = F_299 ( 0 , V_308 ) ;
F_2 ( V_309 , V_302 ) ;
F_2 ( V_310 , V_302 >> 32 ) ;
}
static void F_301 ( struct V_1 * V_2 )
{
T_7 V_302 ;
V_302 = F_299 ( 0 , V_311 ) |
F_299 ( 1 , 0 ) |
F_299 ( 2 , 0 ) |
F_299 ( 3 , 0 ) |
F_299 ( 4 , V_311 ) |
F_299 ( 5 , V_311 ) |
F_299 ( 6 , V_311 ) |
F_299 ( 7 , V_311 ) ;
F_2 ( V_309 , V_302 ) ;
F_2 ( V_310 , V_302 >> 32 ) ;
}
static void F_302 ( struct V_64 * V_28 )
{
struct V_207 * V_8 = F_225 ( V_28 ) ;
F_297 ( V_8 -> V_215 ) ;
F_52 ( V_28 ) ;
}
static int F_303 ( struct V_207 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
struct V_299 * V_16 = V_2 -> V_15 . V_16 ;
unsigned int V_32 ;
T_11 V_287 ;
int V_276 ;
V_8 -> V_312 = F_293 ( V_16 , 2 ) ;
V_8 -> V_213 = F_294 ( V_16 , 2 ) ;
V_276 = F_304 ( V_16 , F_305 ( 39 ) ) ;
if ( ! V_276 )
V_276 = F_306 ( V_16 , F_305 ( 39 ) ) ;
if ( V_276 )
F_260 ( L_29 , V_276 ) ;
F_307 ( V_16 , V_313 , & V_287 ) ;
if ( F_9 ( V_2 ) >= 9 ) {
V_8 -> V_314 = F_291 ( V_287 ) ;
V_32 = F_285 ( V_287 ) ;
} else if ( F_139 ( V_2 ) ) {
V_8 -> V_314 = F_290 ( V_287 ) ;
V_32 = F_287 ( V_287 ) ;
} else {
V_8 -> V_314 = F_289 ( V_287 ) ;
V_32 = F_285 ( V_287 ) ;
}
V_8 -> V_121 . V_164 = ( V_32 / sizeof( T_2 ) ) << V_201 ;
if ( F_139 ( V_2 ) || F_195 ( V_2 ) )
F_301 ( V_2 ) ;
else
F_298 ( V_2 ) ;
V_8 -> V_121 . V_167 = F_302 ;
V_8 -> V_121 . V_169 = F_250 ;
V_8 -> V_121 . V_168 = F_254 ;
V_8 -> V_121 . V_261 = F_224 ;
V_8 -> V_121 . V_39 = F_231 ;
if ( ! F_274 ( V_2 ) || F_308 ( V_2 ) )
V_8 -> V_121 . V_39 = F_232 ;
V_8 -> V_121 . V_38 = F_226 ;
if ( F_309 ( V_2 ) ) {
V_8 -> V_121 . V_38 = F_240 ;
V_8 -> V_121 . V_261 = F_237 ;
if ( V_8 -> V_121 . V_39 != F_231 )
V_8 -> V_121 . V_39 = F_242 ;
}
V_8 -> V_9 = F_1 ;
return F_292 ( V_8 , V_32 ) ;
}
static int F_310 ( struct V_207 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
struct V_299 * V_16 = V_2 -> V_15 . V_16 ;
unsigned int V_32 ;
T_11 V_287 ;
int V_276 ;
V_8 -> V_312 = F_293 ( V_16 , 2 ) ;
V_8 -> V_213 = F_294 ( V_16 , 2 ) ;
if ( V_8 -> V_213 < ( 64 << 20 ) || V_8 -> V_213 > ( 512 << 20 ) ) {
F_260 ( L_30 , V_8 -> V_213 ) ;
return - V_315 ;
}
V_276 = F_304 ( V_16 , F_305 ( 40 ) ) ;
if ( ! V_276 )
V_276 = F_306 ( V_16 , F_305 ( 40 ) ) ;
if ( V_276 )
F_260 ( L_29 , V_276 ) ;
F_307 ( V_16 , V_313 , & V_287 ) ;
V_8 -> V_314 = F_288 ( V_287 ) ;
V_32 = F_284 ( V_287 ) ;
V_8 -> V_121 . V_164 = ( V_32 / sizeof( T_5 ) ) << V_201 ;
V_8 -> V_121 . V_39 = F_243 ;
V_8 -> V_121 . V_261 = F_228 ;
V_8 -> V_121 . V_38 = F_230 ;
V_8 -> V_121 . V_169 = F_250 ;
V_8 -> V_121 . V_168 = F_254 ;
V_8 -> V_121 . V_167 = F_302 ;
V_8 -> V_9 = F_1 ;
if ( F_311 ( V_2 ) )
V_8 -> V_121 . V_90 = F_26 ;
else if ( F_161 ( V_2 ) )
V_8 -> V_121 . V_90 = F_24 ;
else if ( F_13 ( V_2 ) )
V_8 -> V_121 . V_90 = F_23 ;
else if ( F_9 ( V_2 ) >= 7 )
V_8 -> V_121 . V_90 = F_22 ;
else
V_8 -> V_121 . V_90 = F_19 ;
return F_292 ( V_8 , V_32 ) ;
}
static void F_312 ( struct V_64 * V_28 )
{
F_313 () ;
}
static int F_314 ( struct V_207 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
int V_25 ;
V_25 = F_315 ( V_2 -> V_316 , V_2 -> V_15 . V_16 , NULL ) ;
if ( ! V_25 ) {
F_260 ( L_31 ) ;
return - V_317 ;
}
F_316 ( & V_8 -> V_121 . V_164 ,
& V_8 -> V_314 ,
& V_8 -> V_312 ,
& V_8 -> V_213 ) ;
V_8 -> V_271 = F_209 ( V_2 ) ;
V_8 -> V_121 . V_261 = F_244 ;
V_8 -> V_121 . V_38 = F_246 ;
V_8 -> V_121 . V_39 = F_248 ;
V_8 -> V_121 . V_169 = F_250 ;
V_8 -> V_121 . V_168 = F_254 ;
V_8 -> V_121 . V_167 = F_312 ;
V_8 -> V_9 = F_4 ;
if ( F_41 ( V_8 -> V_271 ) )
F_12 ( L_32 ) ;
return 0 ;
}
int F_317 ( struct V_1 * V_2 )
{
struct V_207 * V_8 = & V_2 -> V_8 ;
int V_25 ;
V_8 -> V_121 . V_7 = V_2 ;
V_8 -> V_121 . V_76 = & V_2 -> V_15 . V_16 -> V_216 ;
if ( F_9 ( V_2 ) <= 5 )
V_25 = F_314 ( V_8 ) ;
else if ( F_9 ( V_2 ) < 8 )
V_25 = F_310 ( V_8 ) ;
else
V_25 = F_303 ( V_8 ) ;
if ( V_25 )
return V_25 ;
if ( F_318 ( V_2 ) && V_7 . V_318 ) {
V_8 -> V_121 . V_164 = F_319 ( T_7 , V_8 -> V_121 . V_164 , V_319 ) ;
V_8 -> V_213 = F_164 ( V_8 -> V_213 , V_8 -> V_121 . V_164 ) ;
}
if ( ( V_8 -> V_121 . V_164 - 1 ) >> 32 ) {
F_260 ( L_33
L_34 ,
V_8 -> V_121 . V_164 >> 20 ) ;
V_8 -> V_121 . V_164 = 1ULL << 32 ;
V_8 -> V_213 = F_164 ( V_8 -> V_213 , V_8 -> V_121 . V_164 ) ;
}
if ( V_8 -> V_213 > V_8 -> V_121 . V_164 ) {
F_260 ( L_35
L_36 ,
V_8 -> V_213 , V_8 -> V_121 . V_164 ) ;
V_8 -> V_213 = V_8 -> V_121 . V_164 ;
}
F_12 ( L_37 ,
V_8 -> V_121 . V_164 >> 20 ) ;
F_14 ( L_38 , V_8 -> V_213 >> 20 ) ;
F_14 ( L_39 , V_8 -> V_314 >> 20 ) ;
if ( F_11 () )
F_12 ( L_40 ) ;
return 0 ;
}
int F_320 ( struct V_1 * V_2 )
{
struct V_207 * V_8 = & V_2 -> V_8 ;
int V_25 ;
F_185 ( & V_2 -> V_226 ) ;
F_276 ( & V_2 -> V_15 . V_284 ) ;
F_182 ( & V_8 -> V_121 , V_2 , L_41 ) ;
if ( ! F_321 ( V_2 ) && ! F_197 ( V_2 ) )
V_8 -> V_121 . V_35 . V_320 = F_263 ;
F_278 ( & V_2 -> V_15 . V_284 ) ;
if ( ! F_322 ( & V_2 -> V_8 . V_286 ,
V_2 -> V_8 . V_312 ,
V_2 -> V_8 . V_213 ) ) {
V_25 = - V_317 ;
goto V_321;
}
V_8 -> V_285 = F_323 ( V_8 -> V_312 , V_8 -> V_213 ) ;
V_25 = F_324 ( V_2 ) ;
if ( V_25 )
goto V_321;
return 0 ;
V_321:
V_8 -> V_121 . V_167 ( & V_8 -> V_121 ) ;
return V_25 ;
}
int F_325 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) < 6 && ! F_326 () )
return - V_317 ;
return 0 ;
}
void F_327 ( struct V_1 * V_7 )
{
F_34 ( V_7 -> V_8 . V_9 != F_1 ) ;
V_7 -> V_8 . V_9 = F_3 ;
}
void F_328 ( struct V_1 * V_7 )
{
F_34 ( V_7 -> V_8 . V_9 != F_3 ) ;
V_7 -> V_8 . V_9 = F_1 ;
}
void F_329 ( struct V_1 * V_2 )
{
struct V_207 * V_8 = & V_2 -> V_8 ;
struct V_247 * V_34 , * V_322 ;
F_212 ( V_2 ) ;
V_8 -> V_121 . V_39 ( & V_8 -> V_121 , 0 , V_8 -> V_121 . V_164 ) ;
V_8 -> V_121 . V_239 = true ;
F_202 (obj, on,
&dev_priv->mm.bound_list, global_link) {
bool V_323 = false ;
struct V_19 * V_20 ;
F_330 (vma, &obj->vma_list, obj_link) {
if ( V_20 -> V_28 != & V_8 -> V_121 )
continue;
if ( ! F_277 ( V_20 ) )
continue;
F_76 ( F_331 ( V_20 , V_34 -> V_22 ,
V_324 ) ) ;
V_323 = true ;
}
if ( V_323 )
F_76 ( F_332 ( V_34 , false ) ) ;
}
V_8 -> V_121 . V_239 = false ;
if ( F_9 ( V_2 ) >= 8 ) {
if ( F_139 ( V_2 ) || F_195 ( V_2 ) )
F_301 ( V_2 ) ;
else
F_298 ( V_2 ) ;
return;
}
if ( F_197 ( V_2 ) ) {
struct V_64 * V_28 ;
F_330 (vm, &dev_priv->vm_list, global_link) {
struct V_116 * V_117 ;
if ( F_333 ( V_28 ) )
V_117 = V_2 -> V_35 . V_267 ;
else
V_117 = F_110 ( V_28 ) ;
F_147 ( V_117 , 0 , V_117 -> V_121 . V_164 ) ;
}
}
F_6 ( V_2 ) ;
}
static struct V_325 *
F_334 ( const T_3 * V_326 , unsigned int V_253 ,
unsigned int V_327 , unsigned int V_328 ,
unsigned int V_329 ,
struct V_137 * V_254 , struct V_325 * V_135 )
{
unsigned int V_330 , V_331 ;
unsigned int V_332 ;
for ( V_330 = 0 ; V_330 < V_327 ; V_330 ++ ) {
V_332 = V_329 * ( V_328 - 1 ) + V_330 ;
for ( V_331 = 0 ; V_331 < V_328 ; V_331 ++ ) {
V_254 -> V_248 ++ ;
F_335 ( V_135 , NULL , V_77 , 0 ) ;
F_116 ( V_135 ) = V_326 [ V_253 + V_332 ] ;
F_336 ( V_135 ) = V_77 ;
V_135 = F_337 ( V_135 ) ;
V_332 -= V_329 ;
}
}
return V_135 ;
}
T_14 struct V_137 *
F_338 ( const struct V_333 * V_334 ,
struct V_247 * V_34 )
{
struct V_137 * V_254 ;
struct V_325 * V_135 , * V_131 ;
unsigned int V_335 = V_334 -> V_336 . V_32 ;
unsigned int V_253 ;
int V_25 = - V_74 ;
V_254 = F_54 ( sizeof( * V_254 ) , V_88 ) ;
if ( ! V_254 )
goto V_337;
V_25 = F_339 ( V_254 , V_335 , V_88 ) ;
if ( V_25 )
goto V_338;
V_131 = F_340 ( V_34 , V_334 -> V_336 . V_253 , & V_253 ) ;
F_34 ( ! V_131 ) ;
V_135 = V_254 -> V_138 ;
V_254 -> V_248 = 0 ;
do {
unsigned int V_339 ;
V_339 = F_164 ( V_131 -> V_123 - ( V_253 << V_201 ) ,
V_335 << V_201 ) ;
F_335 ( V_135 , NULL , V_339 , 0 ) ;
F_116 ( V_135 ) =
F_116 ( V_131 ) + ( V_253 << V_201 ) ;
F_336 ( V_135 ) = V_339 ;
V_254 -> V_248 ++ ;
V_335 -= V_339 >> V_201 ;
if ( V_335 == 0 ) {
F_341 ( V_135 ) ;
return V_254 ;
}
V_135 = F_115 ( V_135 ) ;
V_131 = F_115 ( V_131 ) ;
V_253 = 0 ;
} while ( 1 );
V_338:
F_57 ( V_254 ) ;
V_337:
return F_55 ( V_25 ) ;
}
static int
F_251 ( struct V_19 * V_20 )
{
int V_25 ;
F_34 ( ! F_342 ( V_20 -> V_34 ) ) ;
switch ( V_20 -> V_340 . type ) {
case V_341 :
V_20 -> V_33 = V_20 -> V_34 -> V_35 . V_33 ;
return 0 ;
case V_342 :
V_20 -> V_33 =
F_343 ( & V_20 -> V_340 . V_343 , V_20 -> V_34 ) ;
break;
case V_344 :
V_20 -> V_33 = F_338 ( & V_20 -> V_340 , V_20 -> V_34 ) ;
break;
default:
F_344 ( 1 , L_42 ,
V_20 -> V_340 . type ) ;
return - V_345 ;
}
V_25 = 0 ;
if ( F_41 ( F_85 ( V_20 -> V_33 ) ) ) {
V_25 = F_86 ( V_20 -> V_33 ) ;
V_20 -> V_33 = NULL ;
F_260 ( L_43 ,
V_20 -> V_340 . type , V_25 ) ;
}
return V_25 ;
}
int F_345 ( struct V_64 * V_28 ,
struct V_272 * V_30 ,
T_7 V_32 , T_7 V_253 , unsigned long V_221 ,
unsigned int V_26 )
{
int V_276 ;
F_34 ( ! V_32 ) ;
F_34 ( ! F_346 ( V_32 , V_274 ) ) ;
F_34 ( ! F_346 ( V_253 , V_346 ) ) ;
F_34 ( F_347 ( V_253 , V_32 , V_28 -> V_164 ) ) ;
F_34 ( V_28 == & V_28 -> V_7 -> V_35 . V_267 -> V_121 ) ;
F_34 ( F_280 ( V_30 ) ) ;
V_30 -> V_32 = V_32 ;
V_30 -> V_31 = V_253 ;
V_30 -> V_221 = V_221 ;
V_276 = F_348 ( & V_28 -> V_35 , V_30 ) ;
if ( V_276 != - V_252 )
return V_276 ;
if ( V_26 & V_347 )
return - V_252 ;
V_276 = F_349 ( V_28 , V_30 , V_26 ) ;
if ( V_276 == 0 )
V_276 = F_348 ( & V_28 -> V_35 , V_30 ) ;
return V_276 ;
}
static T_7 F_350 ( T_7 V_31 , T_7 V_202 , T_7 V_339 , T_7 V_348 )
{
T_7 V_349 , V_40 ;
F_34 ( F_347 ( V_31 , V_339 , V_202 ) ) ;
F_34 ( F_351 ( V_31 , V_348 ) > F_352 ( V_202 - V_339 , V_348 ) ) ;
V_349 = F_352 ( V_202 - V_339 , V_348 ) - F_351 ( V_31 , V_348 ) ;
if ( V_349 ) {
if (sizeof( unsigned long ) == sizeof( T_7 ) ) {
V_40 = F_353 () ;
} else {
V_40 = F_354 () ;
if ( V_349 > V_350 ) {
V_40 <<= 32 ;
V_40 |= F_354 () ;
}
}
F_355 ( V_40 , V_349 , & V_40 ) ;
V_31 += V_40 ;
}
return F_351 ( V_31 , V_348 ) ;
}
int F_174 ( struct V_64 * V_28 ,
struct V_272 * V_30 ,
T_7 V_32 , T_7 V_351 , unsigned long V_221 ,
T_7 V_31 , T_7 V_202 , unsigned int V_26 )
{
enum V_352 V_353 ;
T_7 V_253 ;
int V_276 ;
F_356 ( & V_28 -> V_7 -> V_15 . V_284 ) ;
F_34 ( ! V_32 ) ;
F_34 ( ! F_346 ( V_32 , V_274 ) ) ;
F_34 ( V_351 && ! F_357 ( V_351 ) ) ;
F_34 ( V_351 && ! F_346 ( V_351 , V_346 ) ) ;
F_34 ( V_31 >= V_202 ) ;
F_34 ( V_31 > 0 && ! F_346 ( V_31 , V_274 ) ) ;
F_34 ( V_202 < V_354 && ! F_346 ( V_202 , V_274 ) ) ;
F_34 ( V_28 == & V_28 -> V_7 -> V_35 . V_267 -> V_121 ) ;
F_34 ( F_280 ( V_30 ) ) ;
if ( F_41 ( F_347 ( V_31 , V_32 , V_202 ) ) )
return - V_252 ;
if ( F_41 ( F_351 ( V_31 , V_351 ) > F_352 ( V_202 - V_32 , V_351 ) ) )
return - V_252 ;
V_353 = V_355 ;
if ( V_26 & V_211 )
V_353 = V_356 ;
if ( V_26 & V_357 )
V_353 = V_283 ;
F_358 ( V_346 > V_274 ) ;
if ( V_351 <= V_346 )
V_351 = 0 ;
V_276 = F_271 ( & V_28 -> V_35 , V_30 ,
V_32 , V_351 , V_221 ,
V_31 , V_202 , V_353 ) ;
if ( V_276 != - V_252 )
return V_276 ;
if ( V_26 & V_347 )
return - V_252 ;
V_253 = F_350 ( V_31 , V_202 ,
V_32 , V_351 ? : V_346 ) ;
V_276 = F_345 ( V_28 , V_30 , V_32 , V_253 , V_221 , V_26 ) ;
if ( V_276 != - V_252 )
return V_276 ;
V_276 = F_359 ( V_28 , V_32 , V_351 , V_221 ,
V_31 , V_202 , V_26 ) ;
if ( V_276 )
return V_276 ;
return F_271 ( & V_28 -> V_35 , V_30 ,
V_32 , V_351 , V_221 ,
V_31 , V_202 , V_358 ) ;
}
