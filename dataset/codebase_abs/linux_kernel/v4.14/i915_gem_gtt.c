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
V_13 = F_9 ( V_2 ) ;
}
if ( ! V_11 )
return 0 ;
if ( V_10 == 0 && F_10 ( V_2 ) < 9 )
return 0 ;
if ( V_10 == 1 )
return 1 ;
if ( V_10 == 2 && V_12 )
return 2 ;
if ( V_10 == 3 && V_13 )
return 3 ;
if ( F_11 ( V_2 ) && F_12 () ) {
F_13 ( L_1 ) ;
return 0 ;
}
if ( F_14 ( V_2 ) && V_2 -> V_15 . V_16 -> V_17 < 0xb ) {
F_15 ( L_2 ) ;
return 0 ;
}
if ( F_10 ( V_2 ) >= 8 && V_7 . V_18 ) {
if ( V_13 )
return 3 ;
if ( V_12 )
return 2 ;
}
return V_11 ? 1 : 0 ;
}
static int F_16 ( struct V_19 * V_20 ,
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
V_20 -> V_28 -> V_38 ( V_20 -> V_28 , V_20 , V_22 , V_24 ) ;
return 0 ;
}
static void F_17 ( struct V_19 * V_20 )
{
V_20 -> V_28 -> V_39 ( V_20 -> V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
}
static T_2 F_18 ( T_3 V_40 ,
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
static T_4 F_19 ( const T_3 V_40 ,
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
static T_5 F_20 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_21 ( V_40 ) ;
switch ( V_41 ) {
case V_53 :
case V_54 :
V_42 |= V_55 ;
break;
case V_45 :
V_42 |= V_56 ;
break;
default:
F_22 ( V_41 ) ;
}
return V_42 ;
}
static T_5 F_23 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_21 ( V_40 ) ;
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
F_22 ( V_41 ) ;
}
return V_42 ;
}
static T_5 F_24 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_26 )
{
T_5 V_42 = V_52 ;
V_42 |= F_21 ( V_40 ) ;
if ( ! ( V_26 & V_37 ) )
V_42 |= V_58 ;
if ( V_41 != V_45 )
V_42 |= V_59 ;
return V_42 ;
}
static T_5 F_25 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_26 ( V_40 ) ;
if ( V_41 != V_45 )
V_42 |= V_60 ;
return V_42 ;
}
static T_5 F_27 ( T_3 V_40 ,
enum V_21 V_41 ,
T_1 V_23 )
{
T_5 V_42 = V_52 ;
V_42 |= F_26 ( V_40 ) ;
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
static struct V_63 * F_28 ( struct V_64 * V_28 , T_6 V_65 )
{
struct V_63 * V_63 ;
if ( F_29 ( F_30 ( & V_28 -> V_66 , 1 ) ) )
F_31 ( V_28 -> V_7 ) ;
if ( V_28 -> V_67 . V_68 )
return V_28 -> V_67 . V_33 [ -- V_28 -> V_67 . V_68 ] ;
V_63 = F_32 ( V_65 ) ;
if ( ! V_63 )
return NULL ;
if ( V_28 -> V_69 )
F_33 ( & V_63 , 1 ) ;
return V_63 ;
}
static void F_34 ( struct V_64 * V_28 )
{
F_35 ( ! F_36 ( & V_28 -> V_67 ) ) ;
if ( V_28 -> V_69 )
F_37 ( V_28 -> V_67 . V_33 ,
F_36 ( & V_28 -> V_67 ) ) ;
F_38 ( & V_28 -> V_67 ) ;
}
static void F_39 ( struct V_64 * V_28 , struct V_63 * V_63 )
{
if ( ! F_40 ( & V_28 -> V_67 , V_63 ) )
F_34 ( V_28 ) ;
}
static int F_41 ( struct V_64 * V_28 ,
struct V_70 * V_71 ,
T_6 V_65 )
{
V_71 -> V_63 = F_28 ( V_28 , V_65 | V_72 | V_73 ) ;
if ( F_42 ( ! V_71 -> V_63 ) )
return - V_74 ;
V_71 -> V_75 = F_43 ( V_28 -> V_76 , V_71 -> V_63 , 0 , V_77 ,
V_78 ) ;
if ( F_42 ( F_44 ( V_28 -> V_76 , V_71 -> V_75 ) ) ) {
F_39 ( V_28 , V_71 -> V_63 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_45 ( struct V_64 * V_28 ,
struct V_70 * V_71 )
{
return F_41 ( V_28 , V_71 , V_79 ) ;
}
static void F_46 ( struct V_64 * V_28 ,
struct V_70 * V_71 )
{
F_47 ( V_28 -> V_76 , V_71 -> V_75 , V_77 , V_78 ) ;
F_39 ( V_28 , V_71 -> V_63 ) ;
}
static void F_48 ( struct V_64 * V_28 ,
struct V_70 * V_71 ,
const T_7 V_80 )
{
T_7 * const V_81 = F_49 ( V_71 -> V_63 ) ;
int V_82 ;
for ( V_82 = 0 ; V_82 < 512 ; V_82 ++ )
V_81 [ V_82 ] = V_80 ;
F_50 ( V_81 ) ;
}
static void F_51 ( struct V_64 * V_28 ,
struct V_70 * V_71 ,
const T_1 V_83 )
{
F_48 ( V_28 , V_71 , ( T_7 ) V_83 << 32 | V_83 ) ;
}
static int
F_52 ( struct V_64 * V_28 , T_6 V_65 )
{
return F_41 ( V_28 , & V_28 -> V_84 , V_65 | V_85 ) ;
}
static void F_53 ( struct V_64 * V_28 )
{
F_46 ( V_28 , & V_28 -> V_84 ) ;
}
static struct V_86 * F_54 ( struct V_64 * V_28 )
{
struct V_86 * V_87 ;
V_87 = F_55 ( sizeof( * V_87 ) , V_88 | V_72 ) ;
if ( F_42 ( ! V_87 ) )
return F_56 ( - V_74 ) ;
if ( F_42 ( F_57 ( V_28 , V_87 ) ) ) {
F_58 ( V_87 ) ;
return F_56 ( - V_74 ) ;
}
V_87 -> V_89 = 0 ;
return V_87 ;
}
static void F_59 ( struct V_64 * V_28 , struct V_86 * V_87 )
{
F_60 ( V_28 , V_87 ) ;
F_58 ( V_87 ) ;
}
static void F_61 ( struct V_64 * V_28 ,
struct V_86 * V_87 )
{
F_62 ( V_28 , V_87 ,
F_18 ( V_28 -> V_84 . V_75 , V_54 ) ) ;
}
static void F_63 ( struct V_64 * V_28 ,
struct V_86 * V_87 )
{
F_64 ( V_28 , V_87 ,
V_28 -> V_90 ( V_28 -> V_84 . V_75 , V_54 , 0 ) ) ;
}
static struct V_91 * F_65 ( struct V_64 * V_28 )
{
struct V_91 * V_92 ;
V_92 = F_66 ( sizeof( * V_92 ) , V_88 | V_72 ) ;
if ( F_42 ( ! V_92 ) )
return F_56 ( - V_74 ) ;
if ( F_42 ( F_57 ( V_28 , V_92 ) ) ) {
F_58 ( V_92 ) ;
return F_56 ( - V_74 ) ;
}
V_92 -> V_93 = 0 ;
return V_92 ;
}
static void F_67 ( struct V_64 * V_28 ,
struct V_91 * V_92 )
{
F_60 ( V_28 , V_92 ) ;
F_58 ( V_92 ) ;
}
static void F_68 ( struct V_64 * V_28 ,
struct V_91 * V_92 )
{
unsigned int V_82 ;
F_62 ( V_28 , V_92 ,
F_19 ( F_69 ( V_28 -> V_94 ) , V_54 ) ) ;
for ( V_82 = 0 ; V_82 < V_95 ; V_82 ++ )
V_92 -> V_96 [ V_82 ] = V_28 -> V_94 ;
}
static int F_70 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
const unsigned int V_99 = F_71 ( V_28 ) ;
unsigned int V_82 ;
V_98 -> V_100 = F_72 ( V_99 , sizeof( * V_98 -> V_100 ) ,
V_88 | V_72 ) ;
if ( F_42 ( ! V_98 -> V_100 ) )
return - V_74 ;
for ( V_82 = 0 ; V_82 < V_99 ; V_82 ++ )
V_98 -> V_100 [ V_82 ] = V_28 -> V_101 ;
return 0 ;
}
static void F_73 ( struct V_97 * V_98 )
{
F_58 ( V_98 -> V_100 ) ;
V_98 -> V_100 = NULL ;
}
static inline bool F_74 ( const struct V_64 * V_28 )
{
return F_75 ( V_28 ) ;
}
static struct V_97 *
F_76 ( struct V_64 * V_28 )
{
struct V_97 * V_98 ;
int V_25 = - V_74 ;
F_77 ( ! F_74 ( V_28 ) ) ;
V_98 = F_66 ( sizeof( * V_98 ) , V_88 ) ;
if ( ! V_98 )
return F_56 ( - V_74 ) ;
V_25 = F_70 ( V_28 , V_98 ) ;
if ( V_25 )
goto V_102;
V_25 = F_57 ( V_28 , V_98 ) ;
if ( V_25 )
goto V_103;
return V_98 ;
V_103:
F_73 ( V_98 ) ;
V_102:
F_58 ( V_98 ) ;
return F_56 ( V_25 ) ;
}
static void F_78 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
F_73 ( V_98 ) ;
if ( ! F_74 ( V_28 ) )
return;
F_60 ( V_28 , V_98 ) ;
F_58 ( V_98 ) ;
}
static void F_79 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
T_8 V_104 ;
V_104 = F_80 ( F_69 ( V_28 -> V_101 ) , V_54 ) ;
F_62 ( V_28 , V_98 , V_104 ) ;
}
static void F_81 ( struct V_64 * V_28 ,
struct V_105 * V_106 )
{
unsigned int V_82 ;
F_62 ( V_28 , V_106 ,
F_82 ( F_69 ( V_28 -> V_107 ) , V_54 ) ) ;
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ )
V_106 -> V_109 [ V_82 ] = V_28 -> V_107 ;
}
static int F_83 ( struct V_110 * V_111 ,
unsigned V_112 ,
T_3 V_40 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
T_1 * V_115 ;
F_84 ( V_112 >= 4 ) ;
V_115 = F_85 ( V_111 , 6 ) ;
if ( F_86 ( V_115 ) )
return F_87 ( V_115 ) ;
* V_115 ++ = F_88 ( 1 ) ;
* V_115 ++ = F_89 ( F_90 ( V_114 , V_112 ) ) ;
* V_115 ++ = F_91 ( V_40 ) ;
* V_115 ++ = F_88 ( 1 ) ;
* V_115 ++ = F_89 ( F_92 ( V_114 , V_112 ) ) ;
* V_115 ++ = F_93 ( V_40 ) ;
F_94 ( V_111 , V_115 ) ;
return 0 ;
}
static int F_95 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
int V_82 , V_25 ;
for ( V_82 = V_118 - 1 ; V_82 >= 0 ; V_82 -- ) {
const T_3 V_119 = F_96 ( V_117 , V_82 ) ;
V_25 = F_83 ( V_111 , V_82 , V_119 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
static int F_97 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
return F_83 ( V_111 , 0 , F_69 ( & V_117 -> V_106 ) ) ;
}
static void F_98 ( struct V_116 * V_117 )
{
V_117 -> V_120 = F_99 ( V_117 -> V_121 . V_7 ) -> V_122 ;
}
static bool F_100 ( struct V_64 * V_28 ,
struct V_86 * V_87 ,
T_7 V_31 , T_7 V_123 )
{
unsigned int V_124 = F_101 ( V_31 , V_123 ) ;
unsigned int V_42 = F_102 ( V_31 ) ;
unsigned int V_125 = V_42 + V_124 ;
const T_2 V_126 =
F_18 ( V_28 -> V_84 . V_75 , V_54 ) ;
T_2 * V_81 ;
F_35 ( V_124 > V_87 -> V_89 ) ;
V_87 -> V_89 -= V_124 ;
if ( ! V_87 -> V_89 )
return true ;
V_81 = F_103 ( V_87 ) ;
while ( V_42 < V_125 )
V_81 [ V_42 ++ ] = V_126 ;
F_50 ( V_81 ) ;
return false ;
}
static void F_104 ( struct V_64 * V_28 ,
struct V_91 * V_92 ,
struct V_86 * V_87 ,
unsigned int V_50 )
{
T_4 * V_81 ;
V_92 -> V_96 [ V_50 ] = V_87 ;
V_81 = F_103 ( V_92 ) ;
V_81 [ V_50 ] = F_19 ( F_69 ( V_87 ) , V_54 ) ;
F_50 ( V_81 ) ;
}
static bool F_105 ( struct V_64 * V_28 ,
struct V_91 * V_92 ,
T_7 V_31 , T_7 V_123 )
{
struct V_86 * V_87 ;
T_1 V_50 ;
F_106 (pt, pd, start, length, pde) {
F_35 ( V_87 == V_28 -> V_94 ) ;
if ( ! F_100 ( V_28 , V_87 , V_31 , V_123 ) )
continue;
F_104 ( V_28 , V_92 , V_28 -> V_94 , V_50 ) ;
F_35 ( ! V_92 -> V_93 ) ;
V_92 -> V_93 -- ;
F_59 ( V_28 , V_87 ) ;
}
return ! V_92 -> V_93 ;
}
static void F_107 ( struct V_64 * V_28 ,
struct V_97 * V_98 ,
struct V_91 * V_92 ,
unsigned int V_127 )
{
T_8 * V_81 ;
V_98 -> V_100 [ V_127 ] = V_92 ;
if ( ! F_74 ( V_28 ) )
return;
V_81 = F_103 ( V_98 ) ;
V_81 [ V_127 ] = F_80 ( F_69 ( V_92 ) , V_54 ) ;
F_50 ( V_81 ) ;
}
static bool F_108 ( struct V_64 * V_28 ,
struct V_97 * V_98 ,
T_7 V_31 , T_7 V_123 )
{
struct V_91 * V_92 ;
unsigned int V_127 ;
F_109 (pd, pdp, start, length, pdpe) {
F_35 ( V_92 == V_28 -> V_101 ) ;
if ( ! F_105 ( V_28 , V_92 , V_31 , V_123 ) )
continue;
F_107 ( V_28 , V_98 , V_28 -> V_101 , V_127 ) ;
F_35 ( ! V_98 -> V_128 ) ;
V_98 -> V_128 -- ;
F_67 ( V_28 , V_92 ) ;
}
return ! V_98 -> V_128 ;
}
static void F_110 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
F_108 ( V_28 , & F_111 ( V_28 ) -> V_98 , V_31 , V_123 ) ;
}
static void F_112 ( struct V_105 * V_106 ,
struct V_97 * V_98 ,
unsigned int V_129 )
{
T_9 * V_81 ;
V_106 -> V_109 [ V_129 ] = V_98 ;
V_81 = F_103 ( V_106 ) ;
V_81 [ V_129 ] = F_82 ( F_69 ( V_98 ) , V_54 ) ;
F_50 ( V_81 ) ;
}
static void F_113 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
struct V_105 * V_106 = & V_117 -> V_106 ;
struct V_97 * V_98 ;
unsigned int V_129 ;
F_35 ( ! F_74 ( V_28 ) ) ;
F_114 (pdp, pml4, start, length, pml4e) {
F_35 ( V_98 == V_28 -> V_107 ) ;
if ( ! F_108 ( V_28 , V_98 , V_31 , V_123 ) )
continue;
F_112 ( V_106 , V_28 -> V_107 , V_129 ) ;
F_78 ( V_28 , V_98 ) ;
}
}
static T_10 bool
F_115 ( struct V_116 * V_117 ,
struct V_97 * V_98 ,
struct V_130 * V_131 ,
struct V_132 * V_133 ,
enum V_21 V_22 )
{
struct V_91 * V_92 ;
const T_2 V_90 = F_18 ( 0 , V_22 ) ;
T_2 * V_81 ;
bool V_25 ;
F_35 ( V_133 -> V_127 >= F_71 ( & V_117 -> V_121 ) ) ;
V_92 = V_98 -> V_100 [ V_133 -> V_127 ] ;
V_81 = F_103 ( V_92 -> V_96 [ V_133 -> V_50 ] ) ;
do {
V_81 [ V_133 -> V_42 ] = V_90 | V_131 -> V_76 ;
V_131 -> V_76 += V_77 ;
if ( V_131 -> V_76 >= V_131 -> V_134 ) {
V_131 -> V_135 = F_116 ( V_131 -> V_135 ) ;
if ( ! V_131 -> V_135 ) {
V_25 = false ;
break;
}
V_131 -> V_76 = F_117 ( V_131 -> V_135 ) ;
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
F_35 ( V_133 -> V_127 >= F_71 ( & V_117 -> V_121 ) ) ;
V_92 = V_98 -> V_100 [ V_133 -> V_127 ] ;
}
F_50 ( V_81 ) ;
V_81 = F_103 ( V_92 -> V_96 [ V_133 -> V_50 ] ) ;
}
} while ( 1 );
F_50 ( V_81 ) ;
return V_25 ;
}
static void F_118 ( struct V_64 * V_28 ,
struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_23 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
struct V_130 V_131 = V_130 ( V_20 ) ;
struct V_132 V_133 = V_132 ( V_20 -> V_30 . V_31 ) ;
F_115 ( V_117 , & V_117 -> V_98 , & V_131 , & V_133 ,
V_22 ) ;
}
static void F_119 ( struct V_64 * V_28 ,
struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_23 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
struct V_130 V_131 = V_130 ( V_20 ) ;
struct V_97 * * V_109 = V_117 -> V_106 . V_109 ;
struct V_132 V_133 = V_132 ( V_20 -> V_30 . V_31 ) ;
while ( F_115 ( V_117 , V_109 [ V_133 . V_129 ++ ] , & V_131 ,
& V_133 , V_22 ) )
F_35 ( V_133 . V_129 >= V_108 ) ;
}
static void F_120 ( struct V_64 * V_28 ,
struct V_91 * V_92 )
{
int V_82 ;
if ( ! F_121 ( V_92 ) )
return;
for ( V_82 = 0 ; V_82 < V_95 ; V_82 ++ ) {
if ( V_92 -> V_96 [ V_82 ] != V_28 -> V_94 )
F_59 ( V_28 , V_92 -> V_96 [ V_82 ] ) ;
}
}
static int F_122 ( struct V_64 * V_28 )
{
int V_25 ;
V_25 = F_52 ( V_28 , V_79 ) ;
if ( V_25 )
return V_25 ;
V_28 -> V_94 = F_54 ( V_28 ) ;
if ( F_86 ( V_28 -> V_94 ) ) {
V_25 = F_87 ( V_28 -> V_94 ) ;
goto V_137;
}
V_28 -> V_101 = F_65 ( V_28 ) ;
if ( F_86 ( V_28 -> V_101 ) ) {
V_25 = F_87 ( V_28 -> V_101 ) ;
goto F_59;
}
if ( F_74 ( V_28 ) ) {
V_28 -> V_107 = F_76 ( V_28 ) ;
if ( F_86 ( V_28 -> V_107 ) ) {
V_25 = F_87 ( V_28 -> V_107 ) ;
goto F_67;
}
}
F_61 ( V_28 , V_28 -> V_94 ) ;
F_68 ( V_28 , V_28 -> V_101 ) ;
if ( F_74 ( V_28 ) )
F_79 ( V_28 , V_28 -> V_107 ) ;
return 0 ;
F_67:
F_67 ( V_28 , V_28 -> V_101 ) ;
F_59:
F_59 ( V_28 , V_28 -> V_94 ) ;
V_137:
F_53 ( V_28 ) ;
return V_25 ;
}
static int F_123 ( struct V_116 * V_117 , bool V_138 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_1 * V_2 = V_28 -> V_7 ;
enum V_139 V_140 ;
int V_82 ;
if ( F_74 ( V_28 ) ) {
const T_7 V_75 = F_69 ( & V_117 -> V_106 ) ;
F_2 ( F_124 ( V_98 [ 0 ] . V_141 ) , F_93 ( V_75 ) ) ;
F_2 ( F_124 ( V_98 [ 0 ] . V_142 ) , F_91 ( V_75 ) ) ;
V_140 = ( V_138 ? V_143 :
V_144 ) ;
} else {
for ( V_82 = 0 ; V_82 < V_118 ; V_82 ++ ) {
const T_7 V_75 = F_96 ( V_117 , V_82 ) ;
F_2 ( F_124 ( V_98 [ V_82 ] . V_141 ) , F_93 ( V_75 ) ) ;
F_2 ( F_124 ( V_98 [ V_82 ] . V_142 ) , F_91 ( V_75 ) ) ;
}
V_140 = ( V_138 ? V_145 :
V_146 ) ;
}
F_2 ( F_124 ( V_147 ) , V_140 ) ;
return 0 ;
}
static void F_125 ( struct V_64 * V_28 )
{
if ( F_74 ( V_28 ) )
F_78 ( V_28 , V_28 -> V_107 ) ;
F_67 ( V_28 , V_28 -> V_101 ) ;
F_59 ( V_28 , V_28 -> V_94 ) ;
F_53 ( V_28 ) ;
}
static void F_126 ( struct V_64 * V_28 ,
struct V_97 * V_98 )
{
const unsigned int V_99 = F_71 ( V_28 ) ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_99 ; V_82 ++ ) {
if ( V_98 -> V_100 [ V_82 ] == V_28 -> V_101 )
continue;
F_120 ( V_28 , V_98 -> V_100 [ V_82 ] ) ;
F_67 ( V_28 , V_98 -> V_100 [ V_82 ] ) ;
}
F_78 ( V_28 , V_98 ) ;
}
static void F_127 ( struct V_116 * V_117 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ ) {
if ( V_117 -> V_106 . V_109 [ V_82 ] == V_117 -> V_121 . V_107 )
continue;
F_126 ( & V_117 -> V_121 , V_117 -> V_106 . V_109 [ V_82 ] ) ;
}
F_60 ( & V_117 -> V_121 , & V_117 -> V_106 ) ;
}
static void F_128 ( struct V_64 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_7 ;
struct V_116 * V_117 = F_111 ( V_28 ) ;
if ( F_8 ( V_2 ) )
F_123 ( V_117 , false ) ;
if ( F_74 ( V_28 ) )
F_127 ( V_117 ) ;
else
F_126 ( & V_117 -> V_121 , & V_117 -> V_98 ) ;
F_125 ( V_28 ) ;
}
static int F_129 ( struct V_64 * V_28 ,
struct V_91 * V_92 ,
T_7 V_31 , T_7 V_123 )
{
struct V_86 * V_87 ;
T_7 V_148 = V_31 ;
unsigned int V_50 ;
F_106 (pt, pd, start, length, pde) {
if ( V_87 == V_28 -> V_94 ) {
V_87 = F_54 ( V_28 ) ;
if ( F_86 ( V_87 ) )
goto V_149;
F_61 ( V_28 , V_87 ) ;
F_104 ( V_28 , V_92 , V_87 , V_50 ) ;
V_92 -> V_93 ++ ;
F_35 ( V_92 -> V_93 > V_95 ) ;
}
V_87 -> V_89 += F_101 ( V_31 , V_123 ) ;
}
return 0 ;
V_149:
F_105 ( V_28 , V_92 , V_148 , V_31 - V_148 ) ;
return - V_74 ;
}
static int F_130 ( struct V_64 * V_28 ,
struct V_97 * V_98 ,
T_7 V_31 , T_7 V_123 )
{
struct V_91 * V_92 ;
T_7 V_148 = V_31 ;
unsigned int V_127 ;
int V_25 ;
F_109 (pd, pdp, start, length, pdpe) {
if ( V_92 == V_28 -> V_101 ) {
V_92 = F_65 ( V_28 ) ;
if ( F_86 ( V_92 ) )
goto V_149;
F_68 ( V_28 , V_92 ) ;
F_107 ( V_28 , V_98 , V_92 , V_127 ) ;
V_98 -> V_128 ++ ;
F_35 ( V_98 -> V_128 > F_71 ( V_28 ) ) ;
F_98 ( F_111 ( V_28 ) ) ;
}
V_25 = F_129 ( V_28 , V_92 , V_31 , V_123 ) ;
if ( F_42 ( V_25 ) )
goto V_150;
}
return 0 ;
V_150:
if ( ! V_92 -> V_93 ) {
F_107 ( V_28 , V_98 , V_28 -> V_101 , V_127 ) ;
F_35 ( ! V_98 -> V_128 ) ;
V_98 -> V_128 -- ;
F_67 ( V_28 , V_92 ) ;
}
V_149:
F_108 ( V_28 , V_98 , V_148 , V_31 - V_148 ) ;
return - V_74 ;
}
static int F_131 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
return F_130 ( V_28 ,
& F_111 ( V_28 ) -> V_98 , V_31 , V_123 ) ;
}
static int F_132 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
struct V_105 * V_106 = & V_117 -> V_106 ;
struct V_97 * V_98 ;
T_7 V_148 = V_31 ;
T_1 V_129 ;
int V_25 ;
F_114 (pdp, pml4, start, length, pml4e) {
if ( V_106 -> V_109 [ V_129 ] == V_28 -> V_107 ) {
V_98 = F_76 ( V_28 ) ;
if ( F_86 ( V_98 ) )
goto V_149;
F_79 ( V_28 , V_98 ) ;
F_112 ( V_106 , V_98 , V_129 ) ;
}
V_25 = F_130 ( V_28 , V_98 , V_31 , V_123 ) ;
if ( F_42 ( V_25 ) )
goto V_151;
}
return 0 ;
V_151:
if ( ! V_98 -> V_128 ) {
F_112 ( V_106 , V_28 -> V_107 , V_129 ) ;
F_78 ( V_28 , V_98 ) ;
}
V_149:
F_113 ( V_28 , V_148 , V_31 - V_148 ) ;
return - V_74 ;
}
static void F_133 ( struct V_116 * V_117 ,
struct V_97 * V_98 ,
T_7 V_31 , T_7 V_123 ,
T_2 V_126 ,
struct V_152 * V_153 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_91 * V_92 ;
T_1 V_127 ;
F_109 (pd, pdp, start, length, pdpe) {
struct V_86 * V_87 ;
T_7 V_154 = V_123 ;
T_7 V_155 = V_31 ;
T_1 V_50 ;
if ( V_98 -> V_100 [ V_127 ] == V_117 -> V_121 . V_101 )
continue;
F_134 ( V_153 , L_3 , V_127 ) ;
F_106 (pt, pd, pd_start, pd_len, pde) {
T_1 V_42 ;
T_2 * V_156 ;
if ( V_92 -> V_96 [ V_50 ] == V_117 -> V_121 . V_94 )
continue;
V_156 = F_103 ( V_87 ) ;
for ( V_42 = 0 ; V_42 < V_136 ; V_42 += 4 ) {
T_7 V_157 = ( V_127 << V_158 |
V_50 << V_159 |
V_42 << V_160 ) ;
int V_82 ;
bool V_161 = false ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ )
if ( V_156 [ V_42 + V_82 ] != V_126 )
V_161 = true ;
if ( ! V_161 )
continue;
F_134 ( V_153 , L_4 , V_157 , V_127 , V_50 , V_42 ) ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
if ( V_156 [ V_42 + V_82 ] != V_126 )
F_134 ( V_153 , L_5 , V_156 [ V_42 + V_82 ] ) ;
else
F_135 ( V_153 , L_6 ) ;
}
F_135 ( V_153 , L_7 ) ;
}
F_50 ( V_156 ) ;
}
}
}
static void F_136 ( struct V_116 * V_117 , struct V_152 * V_153 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
const T_2 V_126 =
F_18 ( V_28 -> V_84 . V_75 , V_54 ) ;
T_7 V_31 = 0 , V_123 = V_117 -> V_121 . V_162 ;
if ( F_74 ( V_28 ) ) {
T_7 V_129 ;
struct V_105 * V_106 = & V_117 -> V_106 ;
struct V_97 * V_98 ;
F_114 (pdp, pml4, start, length, pml4e) {
if ( V_106 -> V_109 [ V_129 ] == V_117 -> V_121 . V_107 )
continue;
F_134 ( V_153 , L_8 , V_129 ) ;
F_133 ( V_117 , V_98 , V_31 , V_123 , V_126 , V_153 ) ;
}
} else {
F_133 ( V_117 , & V_117 -> V_98 , V_31 , V_123 , V_126 , V_153 ) ;
}
}
static int F_137 ( struct V_116 * V_117 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_97 * V_98 = & V_117 -> V_98 ;
struct V_91 * V_92 ;
T_7 V_31 = 0 , V_123 = V_117 -> V_121 . V_162 ;
T_7 V_148 = V_31 ;
unsigned int V_127 ;
F_109 (pd, pdp, start, length, pdpe) {
V_92 = F_65 ( V_28 ) ;
if ( F_86 ( V_92 ) )
goto V_149;
F_68 ( V_28 , V_92 ) ;
F_107 ( V_28 , V_98 , V_92 , V_127 ) ;
V_98 -> V_128 ++ ;
}
V_98 -> V_128 ++ ;
return 0 ;
V_149:
V_31 -= V_148 ;
F_109 (pd, pdp, from, start, pdpe) {
F_107 ( V_28 , V_98 , V_28 -> V_101 , V_127 ) ;
F_67 ( V_28 , V_92 ) ;
}
V_98 -> V_128 = 0 ;
return - V_74 ;
}
static int F_138 ( struct V_116 * V_117 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_1 * V_2 = V_28 -> V_7 ;
int V_25 ;
V_117 -> V_121 . V_162 = F_139 ( V_2 ) ?
1ULL << 48 :
1ULL << 32 ;
V_25 = F_122 ( & V_117 -> V_121 ) ;
if ( V_25 ) {
V_117 -> V_121 . V_162 = 0 ;
return V_25 ;
}
if ( F_140 ( V_2 ) || F_141 ( V_2 ) )
V_117 -> V_121 . V_69 = true ;
if ( F_74 ( V_28 ) ) {
V_25 = F_57 ( & V_117 -> V_121 , & V_117 -> V_106 ) ;
if ( V_25 )
goto V_163;
F_81 ( & V_117 -> V_121 , & V_117 -> V_106 ) ;
V_117 -> V_164 = F_97 ;
V_117 -> V_121 . V_29 = F_132 ;
V_117 -> V_121 . V_38 = F_119 ;
V_117 -> V_121 . V_39 = F_113 ;
} else {
V_25 = F_70 ( & V_117 -> V_121 , & V_117 -> V_98 ) ;
if ( V_25 )
goto V_163;
if ( F_8 ( V_2 ) ) {
V_25 = F_137 ( V_117 ) ;
if ( V_25 ) {
F_73 ( & V_117 -> V_98 ) ;
goto V_163;
}
}
V_117 -> V_164 = F_95 ;
V_117 -> V_121 . V_29 = F_131 ;
V_117 -> V_121 . V_38 = F_118 ;
V_117 -> V_121 . V_39 = F_110 ;
}
if ( F_8 ( V_2 ) )
F_123 ( V_117 , true ) ;
V_117 -> V_121 . V_165 = F_128 ;
V_117 -> V_121 . V_166 = F_17 ;
V_117 -> V_121 . V_167 = F_16 ;
V_117 -> V_168 = F_136 ;
return 0 ;
V_163:
F_125 ( & V_117 -> V_121 ) ;
return V_25 ;
}
static void F_142 ( struct V_116 * V_117 , struct V_152 * V_153 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_86 * V_23 ;
T_5 V_126 ;
T_1 V_169 , V_42 , V_50 ;
T_1 V_31 = 0 , V_123 = V_117 -> V_121 . V_162 ;
V_126 = V_28 -> V_90 ( V_28 -> V_84 . V_75 ,
V_54 , 0 ) ;
F_143 (unused, &ppgtt->pd, start, length, pde) {
T_1 V_170 ;
T_5 * V_156 ;
const T_3 V_171 = F_69 ( V_117 -> V_92 . V_96 [ V_50 ] ) ;
V_169 = F_144 ( V_117 -> V_172 + V_50 ) ;
V_170 = ( F_145 ( V_171 ) | V_173 ) ;
if ( V_169 != V_170 )
F_134 ( V_153 , L_9 ,
V_50 ,
V_169 ,
V_170 ) ;
F_134 ( V_153 , L_10 , V_169 ) ;
V_156 = F_103 ( V_117 -> V_92 . V_96 [ V_50 ] ) ;
for ( V_42 = 0 ; V_42 < V_174 ; V_42 += 4 ) {
unsigned long V_157 =
( V_50 * V_77 * V_174 ) +
( V_42 * V_77 ) ;
int V_82 ;
bool V_161 = false ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ )
if ( V_156 [ V_42 + V_82 ] != V_126 )
V_161 = true ;
if ( ! V_161 )
continue;
F_134 ( V_153 , L_11 , V_157 , V_50 , V_42 ) ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
if ( V_156 [ V_42 + V_82 ] != V_126 )
F_134 ( V_153 , L_12 , V_156 [ V_42 + V_82 ] ) ;
else
F_135 ( V_153 , L_6 ) ;
}
F_135 ( V_153 , L_7 ) ;
}
F_50 ( V_156 ) ;
}
}
static inline void F_146 ( const struct V_116 * V_117 ,
const unsigned int V_50 ,
const struct V_86 * V_87 )
{
F_147 ( F_145 ( F_69 ( V_87 ) ) | V_173 ,
V_117 -> V_172 + V_50 ) ;
}
static void F_148 ( struct V_116 * V_117 ,
T_1 V_31 , T_1 V_123 )
{
struct V_86 * V_87 ;
unsigned int V_50 ;
F_143 (pt, &ppgtt->pd, start, length, pde)
F_146 ( V_117 , V_50 , V_87 ) ;
F_98 ( V_117 ) ;
F_149 () ;
}
static inline T_1 F_150 ( struct V_116 * V_117 )
{
F_35 ( V_117 -> V_92 . V_121 . V_175 & 0x3f ) ;
return V_117 -> V_92 . V_121 . V_175 << 10 ;
}
static int F_151 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
T_1 * V_115 ;
V_115 = F_85 ( V_111 , 6 ) ;
if ( F_86 ( V_115 ) )
return F_87 ( V_115 ) ;
* V_115 ++ = F_88 ( 2 ) ;
* V_115 ++ = F_89 ( F_152 ( V_114 ) ) ;
* V_115 ++ = V_176 ;
* V_115 ++ = F_89 ( F_153 ( V_114 ) ) ;
* V_115 ++ = F_150 ( V_117 ) ;
* V_115 ++ = V_177 ;
F_94 ( V_111 , V_115 ) ;
return 0 ;
}
static int F_154 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
T_1 * V_115 ;
V_115 = F_85 ( V_111 , 6 ) ;
if ( F_86 ( V_115 ) )
return F_87 ( V_115 ) ;
* V_115 ++ = F_88 ( 2 ) ;
* V_115 ++ = F_89 ( F_152 ( V_114 ) ) ;
* V_115 ++ = V_176 ;
* V_115 ++ = F_89 ( F_153 ( V_114 ) ) ;
* V_115 ++ = F_150 ( V_117 ) ;
* V_115 ++ = V_177 ;
F_94 ( V_111 , V_115 ) ;
return 0 ;
}
static int F_155 ( struct V_116 * V_117 ,
struct V_110 * V_111 )
{
struct V_113 * V_114 = V_111 -> V_114 ;
struct V_1 * V_2 = V_111 -> V_7 ;
F_2 ( F_152 ( V_114 ) , V_176 ) ;
F_2 ( F_153 ( V_114 ) , F_150 ( V_117 ) ) ;
return 0 ;
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
enum V_178 V_179 ;
F_157 (engine, dev_priv, id) {
T_1 V_180 = F_139 ( V_2 ) ?
V_181 : 0 ;
F_2 ( F_158 ( V_114 ) ,
F_159 ( V_182 | V_180 ) ) ;
}
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
T_1 V_183 , V_184 ;
enum V_178 V_179 ;
V_184 = F_161 ( V_185 ) ;
F_2 ( V_185 , V_184 | V_186 ) ;
V_183 = F_161 ( V_187 ) ;
if ( F_162 ( V_2 ) ) {
V_183 |= V_188 ;
} else {
V_183 |= V_189 ;
V_183 &= ~ V_190 ;
}
F_2 ( V_187 , V_183 ) ;
F_157 (engine, dev_priv, id) {
F_2 ( F_158 ( V_114 ) ,
F_159 ( V_182 ) ) ;
}
}
static void F_163 ( struct V_1 * V_2 )
{
T_1 V_183 , V_191 , V_184 ;
V_184 = F_161 ( V_185 ) ;
F_2 ( V_185 , V_184 | V_192 |
V_186 ) ;
V_191 = F_161 ( V_193 ) ;
F_2 ( V_193 , V_191 | V_194 ) ;
V_183 = F_161 ( V_187 ) ;
F_2 ( V_187 , V_183 | V_195 | V_196 ) ;
F_2 ( V_197 , F_159 ( V_182 ) ) ;
}
static void F_164 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
unsigned int V_198 = V_31 >> V_199 ;
unsigned int V_50 = V_198 / V_174 ;
unsigned int V_42 = V_198 % V_174 ;
unsigned int V_124 = V_123 >> V_199 ;
T_5 V_126 =
V_28 -> V_90 ( V_28 -> V_84 . V_75 , V_54 , 0 ) ;
while ( V_124 ) {
struct V_86 * V_87 = V_117 -> V_92 . V_96 [ V_50 ++ ] ;
unsigned int V_200 = F_165 ( V_42 + V_124 , V_174 ) ;
T_5 * V_81 ;
V_124 -= V_200 - V_42 ;
V_81 = F_103 ( V_87 ) ;
do {
V_81 [ V_42 ++ ] = V_126 ;
} while ( V_42 < V_200 );
F_50 ( V_81 ) ;
V_42 = 0 ;
}
}
static void F_166 ( struct V_64 * V_28 ,
struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_26 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
unsigned V_198 = V_20 -> V_30 . V_31 >> V_199 ;
unsigned V_201 = V_198 / V_174 ;
unsigned V_202 = V_198 % V_174 ;
const T_1 V_90 = V_28 -> V_90 ( 0 , V_22 , V_26 ) ;
struct V_130 V_131 = V_130 ( V_20 ) ;
T_5 * V_81 ;
V_81 = F_103 ( V_117 -> V_92 . V_96 [ V_201 ] ) ;
do {
V_81 [ V_202 ] = V_90 | F_21 ( V_131 . V_76 ) ;
V_131 . V_76 += V_77 ;
if ( V_131 . V_76 == V_131 . V_134 ) {
V_131 . V_135 = F_116 ( V_131 . V_135 ) ;
if ( ! V_131 . V_135 )
break;
V_131 . V_76 = F_117 ( V_131 . V_135 ) ;
V_131 . V_134 = V_131 . V_76 + V_131 . V_135 -> V_123 ;
}
if ( ++ V_202 == V_174 ) {
F_50 ( V_81 ) ;
V_81 = F_103 ( V_117 -> V_92 . V_96 [ ++ V_201 ] ) ;
V_202 = 0 ;
}
} while ( 1 );
F_50 ( V_81 ) ;
}
static int F_167 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
struct V_86 * V_87 ;
T_7 V_148 = V_31 ;
unsigned int V_50 ;
bool V_203 = false ;
F_143 (pt, &ppgtt->pd, start, length, pde) {
if ( V_87 == V_28 -> V_94 ) {
V_87 = F_54 ( V_28 ) ;
if ( F_86 ( V_87 ) )
goto V_204;
F_63 ( V_28 , V_87 ) ;
V_117 -> V_92 . V_96 [ V_50 ] = V_87 ;
F_146 ( V_117 , V_50 , V_87 ) ;
V_203 = true ;
}
}
if ( V_203 ) {
F_98 ( V_117 ) ;
F_149 () ;
}
return 0 ;
V_204:
F_164 ( V_28 , V_148 , V_31 ) ;
return - V_74 ;
}
static int F_168 ( struct V_64 * V_28 )
{
int V_25 ;
V_25 = F_52 ( V_28 , V_79 ) ;
if ( V_25 )
return V_25 ;
V_28 -> V_94 = F_54 ( V_28 ) ;
if ( F_86 ( V_28 -> V_94 ) ) {
F_53 ( V_28 ) ;
return F_87 ( V_28 -> V_94 ) ;
}
F_63 ( V_28 , V_28 -> V_94 ) ;
return 0 ;
}
static void F_169 ( struct V_64 * V_28 )
{
F_59 ( V_28 , V_28 -> V_94 ) ;
F_53 ( V_28 ) ;
}
static void F_170 ( struct V_64 * V_28 )
{
struct V_116 * V_117 = F_111 ( V_28 ) ;
struct V_91 * V_92 = & V_117 -> V_92 ;
struct V_86 * V_87 ;
T_1 V_50 ;
F_171 ( & V_117 -> V_30 ) ;
F_172 (pt, pd, pde)
if ( V_87 != V_28 -> V_94 )
F_59 ( V_28 , V_87 ) ;
F_169 ( V_28 ) ;
}
static int F_173 ( struct V_116 * V_117 )
{
struct V_64 * V_28 = & V_117 -> V_121 ;
struct V_1 * V_2 = V_117 -> V_121 . V_7 ;
struct V_205 * V_8 = & V_2 -> V_8 ;
int V_25 ;
F_84 ( ! F_174 ( & V_8 -> V_121 . V_35 ) ) ;
V_25 = F_168 ( V_28 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_175 ( & V_8 -> V_121 , & V_117 -> V_30 ,
V_206 , V_207 ,
V_208 ,
0 , V_8 -> V_121 . V_162 ,
V_209 ) ;
if ( V_25 )
goto V_210;
if ( V_117 -> V_30 . V_31 < V_8 -> V_211 )
F_176 ( L_13 ) ;
V_117 -> V_92 . V_121 . V_175 =
V_117 -> V_30 . V_31 / V_77 * sizeof( T_5 ) ;
V_117 -> V_172 = ( T_5 V_212 * ) V_8 -> V_213 +
V_117 -> V_92 . V_121 . V_175 / sizeof( T_5 ) ;
return 0 ;
V_210:
F_169 ( V_28 ) ;
return V_25 ;
}
static int F_177 ( struct V_116 * V_117 )
{
return F_173 ( V_117 ) ;
}
static void F_178 ( struct V_116 * V_117 ,
T_7 V_31 , T_7 V_123 )
{
struct V_86 * V_23 ;
T_1 V_50 ;
F_143 (unused, &ppgtt->pd, start, length, pde)
V_117 -> V_92 . V_96 [ V_50 ] = V_117 -> V_121 . V_94 ;
}
static int F_179 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_121 . V_7 ;
struct V_205 * V_8 = & V_2 -> V_8 ;
int V_25 ;
V_117 -> V_121 . V_90 = V_8 -> V_121 . V_90 ;
if ( F_8 ( V_2 ) || F_11 ( V_2 ) )
V_117 -> V_164 = F_155 ;
else if ( F_162 ( V_2 ) )
V_117 -> V_164 = F_151 ;
else if ( F_180 ( V_2 ) )
V_117 -> V_164 = F_154 ;
else
F_181 () ;
V_25 = F_177 ( V_117 ) ;
if ( V_25 )
return V_25 ;
V_117 -> V_121 . V_162 = V_95 * V_174 * V_77 ;
F_178 ( V_117 , 0 , V_117 -> V_121 . V_162 ) ;
F_148 ( V_117 , 0 , V_117 -> V_121 . V_162 ) ;
V_25 = F_167 ( & V_117 -> V_121 , 0 , V_117 -> V_121 . V_162 ) ;
if ( V_25 ) {
F_170 ( & V_117 -> V_121 ) ;
return V_25 ;
}
V_117 -> V_121 . V_39 = F_164 ;
V_117 -> V_121 . V_38 = F_166 ;
V_117 -> V_121 . V_166 = F_17 ;
V_117 -> V_121 . V_167 = F_16 ;
V_117 -> V_121 . V_165 = F_170 ;
V_117 -> V_168 = F_142 ;
F_15 ( L_14 ,
V_117 -> V_30 . V_32 >> 20 ,
V_117 -> V_30 . V_31 / V_77 ) ;
F_15 ( L_15 ,
V_117 -> V_92 . V_121 . V_175 << 10 ) ;
return 0 ;
}
static int F_182 ( struct V_116 * V_117 ,
struct V_1 * V_2 )
{
V_117 -> V_121 . V_7 = V_2 ;
V_117 -> V_121 . V_76 = & V_2 -> V_15 . V_16 -> V_214 ;
if ( F_99 ( V_2 ) -> V_215 < 8 )
return F_179 ( V_117 ) ;
else
return F_138 ( V_117 ) ;
}
static void F_183 ( struct V_64 * V_28 ,
struct V_1 * V_2 ,
const char * V_216 )
{
F_184 ( V_2 , & V_28 -> V_217 , V_216 ) ;
F_185 ( & V_28 -> V_35 , 0 , V_28 -> V_162 ) ;
V_28 -> V_35 . V_218 . V_219 = V_208 ;
F_186 ( & V_28 -> V_220 ) ;
F_186 ( & V_28 -> V_221 ) ;
F_186 ( & V_28 -> V_222 ) ;
F_187 ( & V_28 -> V_223 , & V_2 -> V_224 ) ;
F_188 ( & V_28 -> V_67 , false ) ;
}
static void F_189 ( struct V_64 * V_28 )
{
if ( F_36 ( & V_28 -> V_67 ) )
F_34 ( V_28 ) ;
F_190 ( & V_28 -> V_217 ) ;
F_191 ( & V_28 -> V_35 ) ;
F_192 ( & V_28 -> V_223 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
if ( F_194 ( V_2 ) )
F_2 ( V_225 , V_226 ) ;
else if ( F_140 ( V_2 ) )
F_2 ( V_225 , V_227 ) ;
else if ( F_195 ( V_2 ) )
F_2 ( V_225 , V_228 ) ;
else if ( F_196 ( V_2 ) )
F_2 ( V_225 , V_229 ) ;
}
int F_197 ( struct V_1 * V_2 )
{
F_193 ( V_2 ) ;
if ( V_7 . V_18 )
return 0 ;
if ( ! F_198 ( V_2 ) )
return 0 ;
if ( F_11 ( V_2 ) )
F_163 ( V_2 ) ;
else if ( F_180 ( V_2 ) )
F_160 ( V_2 ) ;
else if ( F_10 ( V_2 ) >= 8 )
F_156 ( V_2 ) ;
else
F_22 ( F_10 ( V_2 ) ) ;
return 0 ;
}
struct V_116 *
F_199 ( struct V_1 * V_2 ,
struct V_230 * V_231 ,
const char * V_216 )
{
struct V_116 * V_117 ;
int V_25 ;
V_117 = F_66 ( sizeof( * V_117 ) , V_88 ) ;
if ( ! V_117 )
return F_56 ( - V_74 ) ;
V_25 = F_182 ( V_117 , V_2 ) ;
if ( V_25 ) {
F_58 ( V_117 ) ;
return F_56 ( V_25 ) ;
}
F_200 ( & V_117 -> V_232 ) ;
F_183 ( & V_117 -> V_121 , V_2 , V_216 ) ;
V_117 -> V_121 . V_233 = V_231 ;
F_201 ( & V_117 -> V_121 ) ;
return V_117 ;
}
void F_202 ( struct V_64 * V_28 )
{
struct V_234 * V_235 [] = {
& V_28 -> V_220 ,
& V_28 -> V_221 ,
& V_28 -> V_222 ,
NULL ,
} , * * V_236 ;
F_35 ( V_28 -> V_237 ) ;
V_28 -> V_237 = true ;
for ( V_236 = V_235 ; * V_236 ; V_236 ++ ) {
struct V_19 * V_20 , * V_238 ;
F_203 (vma, vn, *phase, vm_link)
if ( ! F_204 ( V_20 ) )
F_205 ( V_20 ) ;
}
}
void F_206 ( struct V_239 * V_239 )
{
struct V_116 * V_117 =
F_207 ( V_239 , struct V_116 , V_232 ) ;
F_208 ( & V_117 -> V_121 ) ;
F_77 ( ! F_209 ( & V_117 -> V_121 . V_220 ) ) ;
F_77 ( ! F_209 ( & V_117 -> V_121 . V_221 ) ) ;
F_77 ( ! F_209 ( & V_117 -> V_121 . V_222 ) ) ;
V_117 -> V_121 . V_165 ( & V_117 -> V_121 ) ;
F_189 ( & V_117 -> V_121 ) ;
F_58 ( V_117 ) ;
}
static bool F_210 ( struct V_1 * V_2 )
{
return F_211 ( V_2 ) && F_212 ( V_2 ) && F_12 () ;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
enum V_178 V_179 ;
if ( F_99 ( V_2 ) -> V_215 < 6 )
return;
F_157 (engine, dev_priv, id) {
T_1 V_240 ;
V_240 = F_161 ( F_214 ( V_114 ) ) ;
if ( V_240 & V_241 ) {
F_15 ( L_16
L_17
L_18
L_19
L_20 ,
V_240 & V_242 ,
V_240 & V_243 ? L_21 : L_22 ,
F_215 ( V_240 ) ,
F_216 ( V_240 ) ) ;
F_2 ( F_214 ( V_114 ) ,
V_240 & ~ V_241 ) ;
}
}
if ( V_2 -> V_114 [ V_244 ] )
F_217 ( F_214 ( V_2 -> V_114 [ V_244 ] ) ) ;
}
void F_218 ( struct V_1 * V_2 )
{
struct V_205 * V_8 = & V_2 -> V_8 ;
if ( F_10 ( V_2 ) < 6 )
return;
F_213 ( V_2 ) ;
V_8 -> V_121 . V_39 ( & V_8 -> V_121 , 0 , V_8 -> V_121 . V_162 ) ;
F_6 ( V_2 ) ;
}
int F_219 ( struct V_245 * V_34 ,
struct V_246 * V_33 )
{
do {
if ( F_220 ( & V_34 -> V_121 . V_214 -> V_16 -> V_214 ,
V_33 -> V_247 , V_33 -> V_248 ,
V_78 ) )
return 0 ;
F_35 ( V_34 -> V_35 . V_33 == V_33 ) ;
} while ( F_221 ( F_222 ( V_34 -> V_121 . V_214 ) ,
V_34 -> V_121 . V_32 >> V_199 , NULL ,
V_249 |
V_250 |
V_251 ) );
return - V_252 ;
}
static void F_223 ( void V_212 * V_40 , T_2 V_42 )
{
F_224 ( V_42 , V_40 ) ;
}
static void F_225 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_205 * V_8 = F_226 ( V_28 ) ;
T_2 V_212 * V_42 =
( T_2 V_212 * ) V_8 -> V_213 + ( V_253 >> V_199 ) ;
F_223 ( V_42 , F_18 ( V_40 , V_41 ) ) ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_227 ( struct V_64 * V_28 ,
struct V_19 * V_20 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_205 * V_8 = F_226 ( V_28 ) ;
struct V_254 V_254 ;
T_2 V_212 * V_255 ;
const T_2 V_90 = F_18 ( 0 , V_41 ) ;
T_3 V_40 ;
V_255 = ( T_2 V_212 * ) V_8 -> V_213 ;
V_255 += V_20 -> V_30 . V_31 >> V_199 ;
F_228 (addr, sgt_iter, vma->pages)
F_223 ( V_255 ++ , V_90 | V_40 ) ;
F_149 () ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_229 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_41 ,
T_1 V_26 )
{
struct V_205 * V_8 = F_226 ( V_28 ) ;
T_5 V_212 * V_42 =
( T_5 V_212 * ) V_8 -> V_213 + ( V_253 >> V_199 ) ;
F_230 ( V_28 -> V_90 ( V_40 , V_41 , V_26 ) , V_42 ) ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_231 ( struct V_64 * V_28 ,
struct V_19 * V_20 ,
enum V_21 V_41 ,
T_1 V_26 )
{
struct V_205 * V_8 = F_226 ( V_28 ) ;
T_5 V_212 * V_256 = ( T_5 V_212 * ) V_8 -> V_213 ;
unsigned int V_82 = V_20 -> V_30 . V_31 >> V_199 ;
struct V_254 V_131 ;
T_3 V_40 ;
F_228 (addr, iter, vma->pages)
F_230 ( V_28 -> V_90 ( V_40 , V_41 , V_26 ) , & V_256 [ V_82 ++ ] ) ;
F_149 () ;
V_8 -> V_9 ( V_28 -> V_7 ) ;
}
static void F_232 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
}
static void F_233 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_205 * V_8 = F_226 ( V_28 ) ;
unsigned V_198 = V_31 >> V_199 ;
unsigned V_124 = V_123 >> V_199 ;
const T_2 V_126 =
F_18 ( V_28 -> V_84 . V_75 , V_54 ) ;
T_2 V_212 * V_257 =
( T_2 V_212 * ) V_8 -> V_213 + V_198 ;
const int V_258 = F_234 ( V_8 ) - V_198 ;
int V_82 ;
if ( F_235 ( V_124 > V_258 ,
L_23 ,
V_198 , V_124 , V_258 ) )
V_124 = V_258 ;
for ( V_82 = 0 ; V_82 < V_124 ; V_82 ++ )
F_223 ( & V_257 [ V_82 ] , V_126 ) ;
}
static void F_236 ( struct V_64 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_7 ;
F_217 ( V_3 ) ;
}
static int F_237 ( void * V_259 )
{
struct V_260 * V_261 = V_259 ;
F_225 ( V_261 -> V_28 , V_261 -> V_40 , V_261 -> V_253 , V_261 -> V_41 , 0 ) ;
F_236 ( V_261 -> V_28 ) ;
return 0 ;
}
static void F_238 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_260 V_261 = { V_28 , V_40 , V_253 , V_41 } ;
F_239 ( F_237 , & V_261 , NULL ) ;
}
static int F_240 ( void * V_259 )
{
struct V_38 * V_261 = V_259 ;
F_227 ( V_261 -> V_28 , V_261 -> V_20 , V_261 -> V_41 , 0 ) ;
F_236 ( V_261 -> V_28 ) ;
return 0 ;
}
static void F_241 ( struct V_64 * V_28 ,
struct V_19 * V_20 ,
enum V_21 V_41 ,
T_1 V_23 )
{
struct V_38 V_261 = { V_28 , V_20 , V_41 } ;
F_239 ( F_240 , & V_261 , NULL ) ;
}
static int F_242 ( void * V_259 )
{
struct V_39 * V_261 = V_259 ;
F_233 ( V_261 -> V_28 , V_261 -> V_31 , V_261 -> V_123 ) ;
F_236 ( V_261 -> V_28 ) ;
return 0 ;
}
static void F_243 ( struct V_64 * V_28 ,
T_7 V_31 ,
T_7 V_123 )
{
struct V_39 V_261 = { V_28 , V_31 , V_123 } ;
F_239 ( F_242 , & V_261 , NULL ) ;
}
static void F_244 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
struct V_205 * V_8 = F_226 ( V_28 ) ;
unsigned V_198 = V_31 >> V_199 ;
unsigned V_124 = V_123 >> V_199 ;
T_5 V_126 , V_212 * V_257 =
( T_5 V_212 * ) V_8 -> V_213 + V_198 ;
const int V_258 = F_234 ( V_8 ) - V_198 ;
int V_82 ;
if ( F_235 ( V_124 > V_258 ,
L_23 ,
V_198 , V_124 , V_258 ) )
V_124 = V_258 ;
V_126 = V_28 -> V_90 ( V_28 -> V_84 . V_75 ,
V_54 , 0 ) ;
for ( V_82 = 0 ; V_82 < V_124 ; V_82 ++ )
F_230 ( V_126 , & V_257 [ V_82 ] ) ;
}
static void F_245 ( struct V_64 * V_28 ,
T_3 V_40 ,
T_7 V_253 ,
enum V_21 V_22 ,
T_1 V_23 )
{
unsigned int V_26 = ( V_22 == V_45 ) ?
V_262 : V_263 ;
F_246 ( V_40 , V_253 >> V_199 , V_26 ) ;
}
static void F_247 ( struct V_64 * V_28 ,
struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_23 )
{
unsigned int V_26 = ( V_22 == V_45 ) ?
V_262 : V_263 ;
F_248 ( V_20 -> V_33 , V_20 -> V_30 . V_31 >> V_199 ,
V_26 ) ;
}
static void F_249 ( struct V_64 * V_28 ,
T_7 V_31 , T_7 V_123 )
{
F_250 ( V_31 >> V_199 , V_123 >> V_199 ) ;
}
static int F_251 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_26 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
struct V_245 * V_34 = V_20 -> V_34 ;
T_1 V_24 ;
if ( F_42 ( ! V_20 -> V_33 ) ) {
int V_25 = F_252 ( V_20 ) ;
if ( V_25 )
return V_25 ;
}
V_24 = 0 ;
if ( V_34 -> V_36 )
V_24 |= V_37 ;
F_253 ( V_7 ) ;
V_20 -> V_28 -> V_38 ( V_20 -> V_28 , V_20 , V_22 , V_24 ) ;
F_254 ( V_7 ) ;
V_20 -> V_26 |= V_264 | V_27 ;
return 0 ;
}
static void F_255 ( struct V_19 * V_20 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
F_253 ( V_7 ) ;
V_20 -> V_28 -> V_39 ( V_20 -> V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_254 ( V_7 ) ;
}
static int F_256 ( struct V_19 * V_20 ,
enum V_21 V_22 ,
T_1 V_26 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
T_1 V_24 ;
int V_25 ;
if ( F_42 ( ! V_20 -> V_33 ) ) {
V_25 = F_252 ( V_20 ) ;
if ( V_25 )
return V_25 ;
}
V_24 = 0 ;
if ( V_20 -> V_34 -> V_36 )
V_24 |= V_37 ;
if ( V_26 & V_27 ) {
struct V_116 * V_265 = V_7 -> V_35 . V_266 ;
if ( ! ( V_20 -> V_26 & V_27 ) &&
V_265 -> V_121 . V_29 ) {
V_25 = V_265 -> V_121 . V_29 ( & V_265 -> V_121 ,
V_20 -> V_30 . V_31 ,
V_20 -> V_32 ) ;
if ( V_25 )
goto V_267;
}
V_265 -> V_121 . V_38 ( & V_265 -> V_121 , V_20 , V_22 ,
V_24 ) ;
}
if ( V_26 & V_264 ) {
F_253 ( V_7 ) ;
V_20 -> V_28 -> V_38 ( V_20 -> V_28 , V_20 , V_22 , V_24 ) ;
F_254 ( V_7 ) ;
}
return 0 ;
V_267:
if ( ! ( V_20 -> V_26 & ( V_264 | V_27 ) ) ) {
if ( V_20 -> V_33 != V_20 -> V_34 -> V_35 . V_33 ) {
F_35 ( ! V_20 -> V_33 ) ;
F_257 ( V_20 -> V_33 ) ;
F_58 ( V_20 -> V_33 ) ;
}
V_20 -> V_33 = NULL ;
}
return V_25 ;
}
static void F_258 ( struct V_19 * V_20 )
{
struct V_1 * V_7 = V_20 -> V_28 -> V_7 ;
if ( V_20 -> V_26 & V_264 ) {
F_253 ( V_7 ) ;
V_20 -> V_28 -> V_39 ( V_20 -> V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
F_254 ( V_7 ) ;
}
if ( V_20 -> V_26 & V_27 ) {
struct V_64 * V_28 = & V_7 -> V_35 . V_266 -> V_121 ;
V_28 -> V_39 ( V_28 , V_20 -> V_30 . V_31 , V_20 -> V_32 ) ;
}
}
void F_259 ( struct V_245 * V_34 ,
struct V_246 * V_33 )
{
struct V_1 * V_2 = F_222 ( V_34 -> V_121 . V_214 ) ;
struct V_268 * V_269 = & V_2 -> V_15 . V_16 -> V_214 ;
struct V_205 * V_8 = & V_2 -> V_8 ;
if ( F_42 ( V_8 -> V_270 ) ) {
if ( F_260 ( V_2 , 0 ) ) {
F_261 ( L_24 ) ;
F_262 ( 10 ) ;
}
}
F_263 ( V_269 , V_33 -> V_247 , V_33 -> V_248 , V_78 ) ;
}
static void F_264 ( const struct V_271 * V_30 ,
unsigned long V_219 ,
T_7 * V_31 ,
T_7 * V_200 )
{
if ( V_30 -> V_272 && V_30 -> V_219 != V_219 )
* V_31 += V_273 ;
V_30 = F_265 ( V_30 , V_274 ) ;
if ( V_30 -> V_219 != V_219 )
* V_200 -= V_273 ;
}
int F_266 ( struct V_1 * V_7 )
{
struct V_205 * V_8 = & V_7 -> V_8 ;
struct V_116 * V_117 ;
int V_275 ;
V_117 = F_199 ( V_7 , F_56 ( - V_276 ) , L_25 ) ;
if ( F_86 ( V_117 ) )
return F_87 ( V_117 ) ;
if ( F_77 ( V_117 -> V_121 . V_162 < V_8 -> V_121 . V_162 ) ) {
V_275 = - V_277 ;
goto V_278;
}
if ( V_117 -> V_121 . V_29 ) {
V_275 = V_117 -> V_121 . V_29 ( & V_117 -> V_121 ,
0 , V_8 -> V_121 . V_162 ) ;
if ( V_275 )
goto V_278;
}
V_7 -> V_35 . V_266 = V_117 ;
F_77 ( V_8 -> V_121 . V_167 != F_251 ) ;
V_8 -> V_121 . V_167 = F_256 ;
F_77 ( V_8 -> V_121 . V_166 != F_255 ) ;
V_8 -> V_121 . V_166 = F_258 ;
return 0 ;
V_278:
F_267 ( V_117 ) ;
return V_275 ;
}
void F_268 ( struct V_1 * V_7 )
{
struct V_205 * V_8 = & V_7 -> V_8 ;
struct V_116 * V_117 ;
V_117 = F_269 ( & V_7 -> V_35 . V_266 ) ;
if ( ! V_117 )
return;
F_267 ( V_117 ) ;
V_8 -> V_121 . V_167 = F_251 ;
V_8 -> V_121 . V_166 = F_255 ;
}
int F_270 ( struct V_1 * V_2 )
{
struct V_205 * V_8 = & V_2 -> V_8 ;
unsigned long V_279 , V_280 ;
struct V_271 * V_112 ;
int V_25 ;
V_25 = F_271 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_272 ( & V_8 -> V_121 . V_35 , & V_8 -> V_281 ,
V_77 , 0 , V_208 ,
0 , V_8 -> V_211 ,
V_282 ) ;
if ( V_25 )
return V_25 ;
F_273 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_274 ( L_26 ,
V_279 , V_280 ) ;
V_8 -> V_121 . V_39 ( & V_8 -> V_121 , V_279 ,
V_280 - V_279 ) ;
}
V_8 -> V_121 . V_39 ( & V_8 -> V_121 ,
V_8 -> V_121 . V_162 - V_77 , V_77 ) ;
if ( F_198 ( V_2 ) && ! F_275 ( V_2 ) ) {
V_25 = F_266 ( V_2 ) ;
if ( V_25 )
goto V_275;
}
return 0 ;
V_275:
F_171 ( & V_8 -> V_281 ) ;
return V_25 ;
}
void F_276 ( struct V_1 * V_2 )
{
struct V_205 * V_8 = & V_2 -> V_8 ;
struct V_19 * V_20 , * V_238 ;
V_8 -> V_121 . V_237 = true ;
F_277 ( & V_2 -> V_15 . V_283 ) ;
F_77 ( ! F_209 ( & V_8 -> V_121 . V_220 ) ) ;
F_203 (vma, vn, &ggtt->base.inactive_list, vm_link)
F_77 ( F_278 ( V_20 ) ) ;
F_279 ( & V_2 -> V_15 . V_283 ) ;
F_280 ( & V_2 -> V_15 ) ;
F_277 ( & V_2 -> V_15 . V_283 ) ;
F_268 ( V_2 ) ;
if ( F_281 ( & V_8 -> V_281 ) )
F_171 ( & V_8 -> V_281 ) ;
if ( F_174 ( & V_8 -> V_121 . V_35 ) ) {
F_282 ( V_2 ) ;
F_189 ( & V_8 -> V_121 ) ;
}
V_8 -> V_121 . V_165 ( & V_8 -> V_121 ) ;
F_279 ( & V_2 -> V_15 . V_283 ) ;
F_283 ( V_8 -> V_284 ) ;
F_284 ( & V_8 -> V_285 ) ;
}
static unsigned int F_285 ( T_11 V_286 )
{
V_286 >>= V_287 ;
V_286 &= V_288 ;
return V_286 << 20 ;
}
static unsigned int F_286 ( T_11 V_289 )
{
V_289 >>= V_290 ;
V_289 &= V_291 ;
if ( V_289 )
V_289 = 1 << V_289 ;
#ifdef F_287
if ( V_289 > 4 )
V_289 = 4 ;
#endif
return V_289 << 20 ;
}
static unsigned int F_288 ( T_11 V_292 )
{
V_292 >>= V_287 ;
V_292 &= V_288 ;
if ( V_292 )
return 1 << ( 20 + V_292 ) ;
return 0 ;
}
static T_12 F_289 ( T_11 V_286 )
{
V_286 >>= V_293 ;
V_286 &= V_294 ;
return ( T_12 ) V_286 << 25 ;
}
static T_12 F_290 ( T_11 V_289 )
{
V_289 >>= V_295 ;
V_289 &= V_296 ;
return ( T_12 ) V_289 << 25 ;
}
static T_12 F_291 ( T_11 V_292 )
{
V_292 >>= V_293 ;
V_292 &= V_294 ;
if ( V_292 < 0x11 )
return ( T_12 ) V_292 << 25 ;
else if ( V_292 < 0x17 )
return ( T_12 ) ( V_292 - 0x11 + 2 ) << 22 ;
else
return ( T_12 ) ( V_292 - 0x17 + 9 ) << 22 ;
}
static T_12 F_292 ( T_11 V_297 )
{
V_297 >>= V_295 ;
V_297 &= V_296 ;
if ( V_297 < 0xf0 )
return ( T_12 ) V_297 << 25 ;
else
return ( T_12 ) ( V_297 - 0xf0 + 1 ) << 22 ;
}
static int F_293 ( struct V_205 * V_8 , T_7 V_32 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
struct V_298 * V_16 = V_2 -> V_15 . V_16 ;
T_13 V_299 ;
int V_25 ;
V_299 = F_294 ( V_16 , 0 ) + F_295 ( V_16 , 0 ) / 2 ;
if ( F_196 ( V_2 ) )
V_8 -> V_213 = F_296 ( V_299 , V_32 ) ;
else
V_8 -> V_213 = F_297 ( V_299 , V_32 ) ;
if ( ! V_8 -> V_213 ) {
F_261 ( L_27 ) ;
return - V_74 ;
}
V_25 = F_52 ( & V_8 -> V_121 , V_300 ) ;
if ( V_25 ) {
F_261 ( L_28 ) ;
F_298 ( V_8 -> V_213 ) ;
return V_25 ;
}
return 0 ;
}
static void F_299 ( struct V_1 * V_2 )
{
if ( ! F_198 ( V_2 ) ) {
F_2 ( F_300 ( 0 ) , V_301 ) ;
return;
}
F_2 ( F_300 ( 0 ) , V_302 | V_303 ) ;
F_2 ( F_300 ( 1 ) , V_304 | V_305 ) ;
F_2 ( F_300 ( 2 ) , V_306 | V_305 ) ;
F_2 ( F_300 ( 3 ) , V_301 ) ;
F_2 ( F_300 ( 4 ) , V_302 | V_305 | F_301 ( 0 ) ) ;
F_2 ( F_300 ( 5 ) , V_302 | V_305 | F_301 ( 1 ) ) ;
F_2 ( F_300 ( 6 ) , V_302 | V_305 | F_301 ( 2 ) ) ;
F_2 ( F_300 ( 7 ) , V_302 | V_305 | F_301 ( 3 ) ) ;
}
static void F_302 ( struct V_1 * V_2 )
{
T_7 V_307 ;
V_307 = F_303 ( 0 , V_302 | V_303 ) |
F_303 ( 1 , V_304 | V_305 ) |
F_303 ( 2 , V_306 | V_305 ) |
F_303 ( 3 , V_301 ) |
F_303 ( 4 , V_302 | V_305 | F_301 ( 0 ) ) |
F_303 ( 5 , V_302 | V_305 | F_301 ( 1 ) ) |
F_303 ( 6 , V_302 | V_305 | F_301 ( 2 ) ) |
F_303 ( 7 , V_302 | V_305 | F_301 ( 3 ) ) ;
if ( ! F_198 ( V_2 ) )
V_307 = F_303 ( 0 , V_301 ) ;
F_2 ( V_308 , V_307 ) ;
F_2 ( V_309 , V_307 >> 32 ) ;
}
static void F_304 ( struct V_1 * V_2 )
{
T_7 V_307 ;
V_307 = F_303 ( 0 , V_310 ) |
F_303 ( 1 , 0 ) |
F_303 ( 2 , 0 ) |
F_303 ( 3 , 0 ) |
F_303 ( 4 , V_310 ) |
F_303 ( 5 , V_310 ) |
F_303 ( 6 , V_310 ) |
F_303 ( 7 , V_310 ) ;
F_2 ( V_308 , V_307 ) ;
F_2 ( V_309 , V_307 >> 32 ) ;
}
static void F_305 ( struct V_64 * V_28 )
{
struct V_205 * V_8 = F_226 ( V_28 ) ;
F_298 ( V_8 -> V_213 ) ;
F_53 ( V_28 ) ;
}
static int F_306 ( struct V_205 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
struct V_298 * V_16 = V_2 -> V_15 . V_16 ;
unsigned int V_32 ;
T_11 V_286 ;
int V_275 ;
V_8 -> V_311 = F_294 ( V_16 , 2 ) ;
V_8 -> V_211 = F_295 ( V_16 , 2 ) ;
V_275 = F_307 ( V_16 , F_308 ( 39 ) ) ;
if ( ! V_275 )
V_275 = F_309 ( V_16 , F_308 ( 39 ) ) ;
if ( V_275 )
F_261 ( L_29 , V_275 ) ;
F_310 ( V_16 , V_312 , & V_286 ) ;
if ( F_10 ( V_2 ) >= 9 ) {
V_8 -> V_313 = F_292 ( V_286 ) ;
V_32 = F_286 ( V_286 ) ;
} else if ( F_140 ( V_2 ) ) {
V_8 -> V_313 = F_291 ( V_286 ) ;
V_32 = F_288 ( V_286 ) ;
} else {
V_8 -> V_313 = F_290 ( V_286 ) ;
V_32 = F_286 ( V_286 ) ;
}
V_8 -> V_121 . V_162 = ( V_32 / sizeof( T_2 ) ) << V_199 ;
if ( F_10 ( V_2 ) >= 10 )
F_299 ( V_2 ) ;
else if ( F_140 ( V_2 ) || F_196 ( V_2 ) )
F_304 ( V_2 ) ;
else
F_302 ( V_2 ) ;
V_8 -> V_121 . V_165 = F_305 ;
V_8 -> V_121 . V_167 = F_251 ;
V_8 -> V_121 . V_166 = F_255 ;
V_8 -> V_121 . V_260 = F_225 ;
V_8 -> V_121 . V_39 = F_232 ;
if ( ! F_275 ( V_2 ) || F_311 ( V_2 ) )
V_8 -> V_121 . V_39 = F_233 ;
V_8 -> V_121 . V_38 = F_227 ;
if ( F_312 ( V_2 ) ) {
V_8 -> V_121 . V_38 = F_241 ;
V_8 -> V_121 . V_260 = F_238 ;
if ( V_8 -> V_121 . V_39 != F_232 )
V_8 -> V_121 . V_39 = F_243 ;
}
V_8 -> V_9 = F_1 ;
return F_293 ( V_8 , V_32 ) ;
}
static int F_313 ( struct V_205 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
struct V_298 * V_16 = V_2 -> V_15 . V_16 ;
unsigned int V_32 ;
T_11 V_286 ;
int V_275 ;
V_8 -> V_311 = F_294 ( V_16 , 2 ) ;
V_8 -> V_211 = F_295 ( V_16 , 2 ) ;
if ( V_8 -> V_211 < ( 64 << 20 ) || V_8 -> V_211 > ( 512 << 20 ) ) {
F_261 ( L_30 , V_8 -> V_211 ) ;
return - V_314 ;
}
V_275 = F_307 ( V_16 , F_308 ( 40 ) ) ;
if ( ! V_275 )
V_275 = F_309 ( V_16 , F_308 ( 40 ) ) ;
if ( V_275 )
F_261 ( L_29 , V_275 ) ;
F_310 ( V_16 , V_312 , & V_286 ) ;
V_8 -> V_313 = F_289 ( V_286 ) ;
V_32 = F_285 ( V_286 ) ;
V_8 -> V_121 . V_162 = ( V_32 / sizeof( T_5 ) ) << V_199 ;
V_8 -> V_121 . V_39 = F_244 ;
V_8 -> V_121 . V_260 = F_229 ;
V_8 -> V_121 . V_38 = F_231 ;
V_8 -> V_121 . V_167 = F_251 ;
V_8 -> V_121 . V_166 = F_255 ;
V_8 -> V_121 . V_165 = F_305 ;
V_8 -> V_9 = F_1 ;
if ( F_314 ( V_2 ) )
V_8 -> V_121 . V_90 = F_27 ;
else if ( F_162 ( V_2 ) )
V_8 -> V_121 . V_90 = F_25 ;
else if ( F_14 ( V_2 ) )
V_8 -> V_121 . V_90 = F_24 ;
else if ( F_10 ( V_2 ) >= 7 )
V_8 -> V_121 . V_90 = F_23 ;
else
V_8 -> V_121 . V_90 = F_20 ;
return F_293 ( V_8 , V_32 ) ;
}
static void F_315 ( struct V_64 * V_28 )
{
F_316 () ;
}
static int F_317 ( struct V_205 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_121 . V_7 ;
int V_25 ;
V_25 = F_318 ( V_2 -> V_315 , V_2 -> V_15 . V_16 , NULL ) ;
if ( ! V_25 ) {
F_261 ( L_31 ) ;
return - V_316 ;
}
F_319 ( & V_8 -> V_121 . V_162 ,
& V_8 -> V_313 ,
& V_8 -> V_311 ,
& V_8 -> V_211 ) ;
V_8 -> V_270 = F_210 ( V_2 ) ;
V_8 -> V_121 . V_260 = F_245 ;
V_8 -> V_121 . V_38 = F_247 ;
V_8 -> V_121 . V_39 = F_249 ;
V_8 -> V_121 . V_167 = F_251 ;
V_8 -> V_121 . V_166 = F_255 ;
V_8 -> V_121 . V_165 = F_315 ;
V_8 -> V_9 = F_4 ;
if ( F_42 ( V_8 -> V_270 ) )
F_13 ( L_32 ) ;
return 0 ;
}
int F_320 ( struct V_1 * V_2 )
{
struct V_205 * V_8 = & V_2 -> V_8 ;
int V_25 ;
V_8 -> V_121 . V_7 = V_2 ;
V_8 -> V_121 . V_76 = & V_2 -> V_15 . V_16 -> V_214 ;
if ( F_10 ( V_2 ) <= 5 )
V_25 = F_317 ( V_8 ) ;
else if ( F_10 ( V_2 ) < 8 )
V_25 = F_313 ( V_8 ) ;
else
V_25 = F_306 ( V_8 ) ;
if ( V_25 )
return V_25 ;
if ( F_321 ( V_2 ) && V_7 . V_317 ) {
V_8 -> V_121 . V_162 = F_322 ( T_7 , V_8 -> V_121 . V_162 , V_318 ) ;
V_8 -> V_211 = F_165 ( V_8 -> V_211 , V_8 -> V_121 . V_162 ) ;
}
if ( ( V_8 -> V_121 . V_162 - 1 ) >> 32 ) {
F_261 ( L_33
L_34 ,
V_8 -> V_121 . V_162 >> 20 ) ;
V_8 -> V_121 . V_162 = 1ULL << 32 ;
V_8 -> V_211 = F_165 ( V_8 -> V_211 , V_8 -> V_121 . V_162 ) ;
}
if ( V_8 -> V_211 > V_8 -> V_121 . V_162 ) {
F_261 ( L_35
L_36 ,
V_8 -> V_211 , V_8 -> V_121 . V_162 ) ;
V_8 -> V_211 = V_8 -> V_121 . V_162 ;
}
F_13 ( L_37 ,
V_8 -> V_121 . V_162 >> 20 ) ;
F_15 ( L_38 , V_8 -> V_211 >> 20 ) ;
F_15 ( L_39 , V_8 -> V_313 >> 20 ) ;
if ( F_12 () )
F_13 ( L_40 ) ;
return 0 ;
}
int F_323 ( struct V_1 * V_2 )
{
struct V_205 * V_8 = & V_2 -> V_8 ;
int V_25 ;
F_186 ( & V_2 -> V_224 ) ;
F_277 ( & V_2 -> V_15 . V_283 ) ;
F_183 ( & V_8 -> V_121 , V_2 , L_41 ) ;
if ( ! F_324 ( V_2 ) && ! F_198 ( V_2 ) )
V_8 -> V_121 . V_35 . V_319 = F_264 ;
F_279 ( & V_2 -> V_15 . V_283 ) ;
if ( ! F_325 ( & V_2 -> V_8 . V_285 ,
V_2 -> V_8 . V_311 ,
V_2 -> V_8 . V_211 ) ) {
V_25 = - V_316 ;
goto V_320;
}
V_8 -> V_284 = F_326 ( V_8 -> V_311 , V_8 -> V_211 ) ;
V_25 = F_327 ( V_2 ) ;
if ( V_25 )
goto V_320;
return 0 ;
V_320:
V_8 -> V_121 . V_165 ( & V_8 -> V_121 ) ;
return V_25 ;
}
int F_328 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 ) < 6 && ! F_329 () )
return - V_316 ;
return 0 ;
}
void F_330 ( struct V_1 * V_7 )
{
F_35 ( V_7 -> V_8 . V_9 != F_1 ) ;
V_7 -> V_8 . V_9 = F_3 ;
}
void F_331 ( struct V_1 * V_7 )
{
F_35 ( V_7 -> V_8 . V_9 != F_3 ) ;
V_7 -> V_8 . V_9 = F_1 ;
}
void F_332 ( struct V_1 * V_2 )
{
struct V_205 * V_8 = & V_2 -> V_8 ;
struct V_245 * V_34 , * V_321 ;
F_213 ( V_2 ) ;
V_8 -> V_121 . V_39 ( & V_8 -> V_121 , 0 , V_8 -> V_121 . V_162 ) ;
V_8 -> V_121 . V_237 = true ;
F_203 (obj, on,
&dev_priv->mm.bound_list, global_link) {
bool V_322 = false ;
struct V_19 * V_20 ;
F_333 (vma, &obj->vma_list, obj_link) {
if ( V_20 -> V_28 != & V_8 -> V_121 )
continue;
if ( ! F_278 ( V_20 ) )
continue;
F_77 ( F_334 ( V_20 , V_34 -> V_22 ,
V_323 ) ) ;
V_322 = true ;
}
if ( V_322 )
F_77 ( F_335 ( V_34 , false ) ) ;
}
V_8 -> V_121 . V_237 = false ;
if ( F_10 ( V_2 ) >= 8 ) {
if ( F_10 ( V_2 ) >= 10 )
F_299 ( V_2 ) ;
else if ( F_140 ( V_2 ) || F_196 ( V_2 ) )
F_304 ( V_2 ) ;
else
F_302 ( V_2 ) ;
return;
}
if ( F_198 ( V_2 ) ) {
struct V_64 * V_28 ;
F_333 (vm, &dev_priv->vm_list, global_link) {
struct V_116 * V_117 ;
if ( F_336 ( V_28 ) )
V_117 = V_2 -> V_35 . V_266 ;
else
V_117 = F_111 ( V_28 ) ;
F_148 ( V_117 , 0 , V_117 -> V_121 . V_162 ) ;
}
}
F_6 ( V_2 ) ;
}
static struct V_324 *
F_337 ( const T_3 * V_325 , unsigned int V_253 ,
unsigned int V_326 , unsigned int V_327 ,
unsigned int V_328 ,
struct V_246 * V_329 , struct V_324 * V_135 )
{
unsigned int V_330 , V_331 ;
unsigned int V_332 ;
for ( V_330 = 0 ; V_330 < V_326 ; V_330 ++ ) {
V_332 = V_328 * ( V_327 - 1 ) + V_330 ;
for ( V_331 = 0 ; V_331 < V_327 ; V_331 ++ ) {
V_329 -> V_248 ++ ;
F_338 ( V_135 , NULL , V_77 , 0 ) ;
F_117 ( V_135 ) = V_325 [ V_253 + V_332 ] ;
F_339 ( V_135 ) = V_77 ;
V_135 = F_340 ( V_135 ) ;
V_332 -= V_328 ;
}
}
return V_135 ;
}
T_14 struct V_246 *
F_341 ( const struct V_333 * V_334 ,
struct V_245 * V_34 )
{
struct V_246 * V_329 ;
struct V_324 * V_135 , * V_131 ;
unsigned int V_335 = V_334 -> V_336 . V_32 ;
unsigned int V_253 ;
int V_25 = - V_74 ;
V_329 = F_55 ( sizeof( * V_329 ) , V_88 ) ;
if ( ! V_329 )
goto V_337;
V_25 = F_342 ( V_329 , V_335 , V_88 ) ;
if ( V_25 )
goto V_338;
V_131 = F_343 ( V_34 , V_334 -> V_336 . V_253 , & V_253 ) ;
F_35 ( ! V_131 ) ;
V_135 = V_329 -> V_247 ;
V_329 -> V_248 = 0 ;
do {
unsigned int V_339 ;
V_339 = F_165 ( V_131 -> V_123 - ( V_253 << V_199 ) ,
V_335 << V_199 ) ;
F_338 ( V_135 , NULL , V_339 , 0 ) ;
F_117 ( V_135 ) =
F_117 ( V_131 ) + ( V_253 << V_199 ) ;
F_339 ( V_135 ) = V_339 ;
V_329 -> V_248 ++ ;
V_335 -= V_339 >> V_199 ;
if ( V_335 == 0 ) {
F_344 ( V_135 ) ;
return V_329 ;
}
V_135 = F_116 ( V_135 ) ;
V_131 = F_116 ( V_131 ) ;
V_253 = 0 ;
} while ( 1 );
V_338:
F_58 ( V_329 ) ;
V_337:
return F_56 ( V_25 ) ;
}
static int
F_252 ( struct V_19 * V_20 )
{
int V_25 ;
F_35 ( ! F_345 ( V_20 -> V_34 ) ) ;
switch ( V_20 -> V_340 . type ) {
case V_341 :
V_20 -> V_33 = V_20 -> V_34 -> V_35 . V_33 ;
return 0 ;
case V_342 :
V_20 -> V_33 =
F_346 ( & V_20 -> V_340 . V_343 , V_20 -> V_34 ) ;
break;
case V_344 :
V_20 -> V_33 = F_341 ( & V_20 -> V_340 , V_20 -> V_34 ) ;
break;
default:
F_347 ( 1 , L_42 ,
V_20 -> V_340 . type ) ;
return - V_345 ;
}
V_25 = 0 ;
if ( F_42 ( F_86 ( V_20 -> V_33 ) ) ) {
V_25 = F_87 ( V_20 -> V_33 ) ;
V_20 -> V_33 = NULL ;
F_261 ( L_43 ,
V_20 -> V_340 . type , V_25 ) ;
}
return V_25 ;
}
int F_348 ( struct V_64 * V_28 ,
struct V_271 * V_30 ,
T_7 V_32 , T_7 V_253 , unsigned long V_219 ,
unsigned int V_26 )
{
int V_275 ;
F_35 ( ! V_32 ) ;
F_35 ( ! F_349 ( V_32 , V_273 ) ) ;
F_35 ( ! F_349 ( V_253 , V_346 ) ) ;
F_35 ( F_350 ( V_253 , V_32 , V_28 -> V_162 ) ) ;
F_35 ( V_28 == & V_28 -> V_7 -> V_35 . V_266 -> V_121 ) ;
F_35 ( F_281 ( V_30 ) ) ;
V_30 -> V_32 = V_32 ;
V_30 -> V_31 = V_253 ;
V_30 -> V_219 = V_219 ;
V_275 = F_351 ( & V_28 -> V_35 , V_30 ) ;
if ( V_275 != - V_252 )
return V_275 ;
if ( V_26 & V_347 )
return - V_252 ;
V_275 = F_352 ( V_28 , V_30 , V_26 ) ;
if ( V_275 == 0 )
V_275 = F_351 ( & V_28 -> V_35 , V_30 ) ;
return V_275 ;
}
static T_7 F_353 ( T_7 V_31 , T_7 V_200 , T_7 V_339 , T_7 V_348 )
{
T_7 V_349 , V_40 ;
F_35 ( F_350 ( V_31 , V_339 , V_200 ) ) ;
F_35 ( F_354 ( V_31 , V_348 ) > F_355 ( V_200 - V_339 , V_348 ) ) ;
V_349 = F_355 ( V_200 - V_339 , V_348 ) - F_354 ( V_31 , V_348 ) ;
if ( V_349 ) {
if (sizeof( unsigned long ) == sizeof( T_7 ) ) {
V_40 = F_356 () ;
} else {
V_40 = F_357 () ;
if ( V_349 > V_350 ) {
V_40 <<= 32 ;
V_40 |= F_357 () ;
}
}
F_358 ( V_40 , V_349 , & V_40 ) ;
V_31 += V_40 ;
}
return F_354 ( V_31 , V_348 ) ;
}
int F_175 ( struct V_64 * V_28 ,
struct V_271 * V_30 ,
T_7 V_32 , T_7 V_351 , unsigned long V_219 ,
T_7 V_31 , T_7 V_200 , unsigned int V_26 )
{
enum V_352 V_353 ;
T_7 V_253 ;
int V_275 ;
F_359 ( & V_28 -> V_7 -> V_15 . V_283 ) ;
F_35 ( ! V_32 ) ;
F_35 ( ! F_349 ( V_32 , V_273 ) ) ;
F_35 ( V_351 && ! F_360 ( V_351 ) ) ;
F_35 ( V_351 && ! F_349 ( V_351 , V_346 ) ) ;
F_35 ( V_31 >= V_200 ) ;
F_35 ( V_31 > 0 && ! F_349 ( V_31 , V_273 ) ) ;
F_35 ( V_200 < V_354 && ! F_349 ( V_200 , V_273 ) ) ;
F_35 ( V_28 == & V_28 -> V_7 -> V_35 . V_266 -> V_121 ) ;
F_35 ( F_281 ( V_30 ) ) ;
if ( F_42 ( F_350 ( V_31 , V_32 , V_200 ) ) )
return - V_252 ;
if ( F_42 ( F_354 ( V_31 , V_351 ) > F_355 ( V_200 - V_32 , V_351 ) ) )
return - V_252 ;
V_353 = V_355 ;
if ( V_26 & V_209 )
V_353 = V_356 ;
if ( V_26 & V_357 )
V_353 = V_282 ;
F_361 ( V_346 > V_273 ) ;
if ( V_351 <= V_346 )
V_351 = 0 ;
V_275 = F_272 ( & V_28 -> V_35 , V_30 ,
V_32 , V_351 , V_219 ,
V_31 , V_200 , V_353 ) ;
if ( V_275 != - V_252 )
return V_275 ;
if ( V_26 & V_347 )
return - V_252 ;
V_253 = F_353 ( V_31 , V_200 ,
V_32 , V_351 ? : V_346 ) ;
V_275 = F_348 ( V_28 , V_30 , V_32 , V_253 , V_219 , V_26 ) ;
if ( V_275 != - V_252 )
return V_275 ;
V_275 = F_362 ( V_28 , V_32 , V_351 , V_219 ,
V_31 , V_200 , V_26 ) ;
if ( V_275 )
return V_275 ;
return F_272 ( & V_28 -> V_35 , V_30 ,
V_32 , V_351 , V_219 ,
V_31 , V_200 , V_358 ) ;
}
