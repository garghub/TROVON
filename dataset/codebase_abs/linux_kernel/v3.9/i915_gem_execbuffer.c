static struct V_1 *
F_1 ( struct V_2 * args )
{
struct V_1 * V_3 = NULL ;
if ( args -> V_4 & V_5 ) {
int V_6 = args -> V_7 ;
V_6 *= sizeof( struct V_8 * ) ;
V_6 += sizeof( struct V_1 ) ;
V_3 = F_2 ( V_6 , V_9 | V_10 | V_11 ) ;
}
if ( V_3 == NULL ) {
int V_6 = args -> V_7 ;
int V_12 = V_13 / sizeof( struct V_14 ) / 2 ;
F_3 ( V_13 / sizeof( struct V_14 ) ) ;
while ( V_12 > 2 * V_6 )
V_12 >>= 1 ;
V_3 = F_4 ( V_12 * sizeof( struct V_14 ) +
sizeof( struct V_1 ) ,
V_9 ) ;
if ( V_3 == NULL )
return V_3 ;
V_3 -> V_15 = V_12 - 1 ;
} else
V_3 -> V_15 = - args -> V_7 ;
F_5 ( & V_3 -> V_16 ) ;
return V_3 ;
}
static void
F_6 ( struct V_1 * V_3 )
{
if ( V_3 -> V_15 >= 0 )
memset ( V_3 -> V_17 , 0 , ( V_3 -> V_15 + 1 ) * sizeof( struct V_14 ) ) ;
}
static int
F_7 ( struct V_1 * V_3 ,
struct V_18 * V_19 ,
const struct V_2 * args ,
struct V_20 * V_21 )
{
int V_22 ;
F_8 ( & V_21 -> V_23 ) ;
for ( V_22 = 0 ; V_22 < args -> V_7 ; V_22 ++ ) {
struct V_8 * V_24 ;
V_24 = F_9 ( F_10 ( & V_21 -> V_25 , V_19 [ V_22 ] . V_26 ) ) ;
if ( V_24 == NULL ) {
F_11 ( & V_21 -> V_23 ) ;
F_12 ( L_1 ,
V_19 [ V_22 ] . V_26 , V_22 ) ;
return - V_27 ;
}
if ( ! F_13 ( & V_24 -> V_28 ) ) {
F_11 ( & V_21 -> V_23 ) ;
F_12 ( L_2 ,
V_24 , V_19 [ V_22 ] . V_26 , V_22 ) ;
return - V_29 ;
}
F_14 ( & V_24 -> V_30 ) ;
F_15 ( & V_24 -> V_28 , & V_3 -> V_16 ) ;
V_24 -> V_31 = & V_19 [ V_22 ] ;
if ( V_3 -> V_15 < 0 ) {
V_3 -> V_32 [ V_22 ] = V_24 ;
} else {
T_1 V_26 = args -> V_4 & V_5 ? V_22 : V_19 [ V_22 ] . V_26 ;
V_24 -> V_33 = V_26 ;
F_16 ( & V_24 -> V_34 ,
& V_3 -> V_17 [ V_26 & V_3 -> V_15 ] ) ;
}
}
F_11 ( & V_21 -> V_23 ) ;
return 0 ;
}
static struct V_8 *
F_17 ( struct V_1 * V_3 , unsigned long V_26 )
{
if ( V_3 -> V_15 < 0 ) {
if ( V_26 >= - V_3 -> V_15 )
return NULL ;
return V_3 -> V_32 [ V_26 ] ;
} else {
struct V_14 * V_35 ;
struct V_36 * V_37 ;
V_35 = & V_3 -> V_17 [ V_26 & V_3 -> V_15 ] ;
F_18 (node, head) {
struct V_8 * V_24 ;
V_24 = F_19 ( V_37 , struct V_8 , V_34 ) ;
if ( V_24 -> V_33 == V_26 )
return V_24 ;
}
return NULL ;
}
}
static void
F_20 ( struct V_1 * V_3 )
{
while ( ! F_13 ( & V_3 -> V_16 ) ) {
struct V_8 * V_24 ;
V_24 = F_21 ( & V_3 -> V_16 ,
struct V_8 ,
V_28 ) ;
F_22 ( & V_24 -> V_28 ) ;
F_23 ( & V_24 -> V_30 ) ;
}
F_24 ( V_3 ) ;
}
static inline int F_25 ( struct V_8 * V_24 )
{
return ( V_24 -> V_30 . V_38 == V_39 ||
! V_24 -> V_40 ||
V_24 -> V_41 != V_42 ) ;
}
static int
F_26 ( struct V_8 * V_24 ,
struct V_1 * V_3 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = V_24 -> V_30 . V_46 ;
struct V_47 * V_48 ;
struct V_8 * V_49 ;
T_1 V_50 ;
int V_51 = - V_29 ;
V_48 = & F_17 ( V_3 , V_44 -> V_52 ) -> V_30 ;
if ( F_27 ( V_48 == NULL ) )
return - V_27 ;
V_49 = F_9 ( V_48 ) ;
V_50 = V_49 -> V_53 ;
if ( F_27 ( F_28 ( V_46 ) &&
V_44 -> V_38 == V_54 &&
! V_49 -> V_55 ) ) {
F_29 ( V_49 ,
V_49 -> V_41 ) ;
}
if ( F_27 ( V_44 -> V_38 & ( V_44 -> V_38 - 1 ) ) ) {
F_12 ( L_3
L_4
L_5 ,
V_24 , V_44 -> V_52 ,
( int ) V_44 -> V_56 ,
V_44 -> V_57 ,
V_44 -> V_38 ) ;
return V_51 ;
}
if ( F_27 ( ( V_44 -> V_38 | V_44 -> V_57 )
& ~ V_58 ) ) {
F_12 ( L_6
L_4
L_5 ,
V_24 , V_44 -> V_52 ,
( int ) V_44 -> V_56 ,
V_44 -> V_57 ,
V_44 -> V_38 ) ;
return V_51 ;
}
V_48 -> V_59 |= V_44 -> V_57 ;
V_48 -> V_60 |= V_44 -> V_38 ;
if ( V_50 == V_44 -> V_61 )
return 0 ;
if ( F_27 ( V_44 -> V_56 > V_24 -> V_30 . V_6 - 4 ) ) {
F_12 ( L_7
L_8 ,
V_24 , V_44 -> V_52 ,
( int ) V_44 -> V_56 ,
( int ) V_24 -> V_30 . V_6 ) ;
return V_51 ;
}
if ( F_27 ( V_44 -> V_56 & 3 ) ) {
F_12 ( L_9
L_10 ,
V_24 , V_44 -> V_52 ,
( int ) V_44 -> V_56 ) ;
return V_51 ;
}
if ( V_24 -> V_62 && F_30 () )
return - V_63 ;
V_44 -> V_64 += V_50 ;
if ( F_25 ( V_24 ) ) {
T_1 V_65 = V_44 -> V_56 & ~ V_66 ;
char * V_67 ;
V_51 = F_31 ( V_24 , 1 ) ;
if ( V_51 )
return V_51 ;
V_67 = F_32 ( F_33 ( V_24 ,
V_44 -> V_56 >> V_68 ) ) ;
* ( T_1 * ) ( V_67 + V_65 ) = V_44 -> V_64 ;
F_34 ( V_67 ) ;
} else {
struct V_69 * V_70 = V_46 -> V_71 ;
T_1 T_2 * V_72 ;
void T_2 * V_73 ;
V_51 = F_35 ( V_24 , true ) ;
if ( V_51 )
return V_51 ;
V_51 = F_36 ( V_24 ) ;
if ( V_51 )
return V_51 ;
V_44 -> V_56 += V_24 -> V_53 ;
V_73 = F_37 ( V_70 -> V_74 . V_75 ,
V_44 -> V_56 & V_66 ) ;
V_72 = ( T_1 T_2 * )
( V_73 + ( V_44 -> V_56 & ~ V_66 ) ) ;
F_38 ( V_44 -> V_64 , V_72 ) ;
F_39 ( V_73 ) ;
}
V_44 -> V_61 = V_50 ;
return 0 ;
}
static int
F_40 ( struct V_8 * V_24 ,
struct V_1 * V_3 )
{
#define F_41 ( T_3 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_43 V_76 [ F_41 ( 512 ) ] ;
struct V_43 T_4 * V_77 ;
struct V_18 * V_78 = V_24 -> V_31 ;
int V_79 , V_51 ;
V_77 = ( void T_4 * ) ( V_80 ) V_78 -> V_81 ;
V_79 = V_78 -> V_82 ;
while ( V_79 ) {
struct V_43 * V_83 = V_76 ;
int V_12 = V_79 ;
if ( V_12 > F_42 ( V_76 ) )
V_12 = F_42 ( V_76 ) ;
V_79 -= V_12 ;
if ( F_43 ( V_83 , V_77 , V_12 * sizeof( V_83 [ 0 ] ) ) )
return - V_63 ;
do {
T_5 V_56 = V_83 -> V_61 ;
V_51 = F_26 ( V_24 , V_3 , V_83 ) ;
if ( V_51 )
return V_51 ;
if ( V_83 -> V_61 != V_56 &&
F_44 ( & V_77 -> V_61 ,
& V_83 -> V_61 ,
sizeof( V_83 -> V_61 ) ) ) {
return - V_63 ;
}
V_77 ++ ;
V_83 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_41
}
static int
F_45 ( struct V_8 * V_24 ,
struct V_1 * V_3 ,
struct V_43 * V_84 )
{
const struct V_18 * V_78 = V_24 -> V_31 ;
int V_22 , V_51 ;
for ( V_22 = 0 ; V_22 < V_78 -> V_82 ; V_22 ++ ) {
V_51 = F_26 ( V_24 , V_3 , & V_84 [ V_22 ] ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int
F_46 ( struct V_45 * V_46 ,
struct V_1 * V_3 )
{
struct V_8 * V_24 ;
int V_51 = 0 ;
F_47 () ;
F_48 (obj, &eb->objects, exec_list) {
V_51 = F_40 ( V_24 , V_3 ) ;
if ( V_51 )
break;
}
F_49 () ;
return V_51 ;
}
static int
F_50 ( struct V_8 * V_24 )
{
struct V_18 * V_78 = V_24 -> V_31 ;
return V_78 -> V_82 && ! F_25 ( V_24 ) ;
}
static int
F_51 ( struct V_8 * V_24 ,
struct V_85 * V_86 ,
bool * V_87 )
{
struct V_69 * V_70 = V_24 -> V_30 . V_46 -> V_71 ;
struct V_18 * V_78 = V_24 -> V_31 ;
bool V_88 = F_52 ( V_86 -> V_46 ) -> V_89 < 4 ;
bool V_90 , V_91 ;
int V_51 ;
V_90 =
V_88 &&
V_78 -> V_4 & V_92 &&
V_24 -> V_93 != V_94 ;
V_91 = V_90 || F_50 ( V_24 ) ;
V_51 = F_53 ( V_24 , V_78 -> V_95 , V_91 , false ) ;
if ( V_51 )
return V_51 ;
V_78 -> V_4 |= V_96 ;
if ( V_88 ) {
if ( V_78 -> V_4 & V_92 ) {
V_51 = F_54 ( V_24 ) ;
if ( V_51 )
return V_51 ;
if ( F_55 ( V_24 ) )
V_78 -> V_4 |= V_97 ;
V_24 -> V_98 = true ;
}
}
if ( V_70 -> V_99 . V_100 && ! V_24 -> V_101 ) {
F_56 ( V_70 -> V_99 . V_100 ,
V_24 , V_24 -> V_41 ) ;
V_24 -> V_101 = 1 ;
}
if ( V_78 -> V_56 != V_24 -> V_53 ) {
V_78 -> V_56 = V_24 -> V_53 ;
* V_87 = true ;
}
if ( V_78 -> V_4 & V_102 ) {
V_24 -> V_30 . V_59 = V_103 ;
V_24 -> V_30 . V_60 = V_103 ;
}
if ( V_78 -> V_4 & V_104 &&
! V_24 -> V_55 )
F_29 ( V_24 , V_24 -> V_41 ) ;
return 0 ;
}
static void
F_57 ( struct V_8 * V_24 )
{
struct V_18 * V_78 ;
if ( ! V_24 -> V_105 )
return;
V_78 = V_24 -> V_31 ;
if ( V_78 -> V_4 & V_97 )
F_58 ( V_24 ) ;
if ( V_78 -> V_4 & V_96 )
F_59 ( V_24 ) ;
V_78 -> V_4 &= ~ ( V_97 | V_96 ) ;
}
static int
F_60 ( struct V_85 * V_86 ,
struct V_20 * V_21 ,
struct V_106 * V_16 ,
bool * V_107 )
{
struct V_8 * V_24 ;
struct V_106 V_108 ;
bool V_88 = F_52 ( V_86 -> V_46 ) -> V_89 < 4 ;
int V_109 ;
F_5 ( & V_108 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_78 ;
bool V_90 , V_91 ;
V_24 = F_21 ( V_16 ,
struct V_8 ,
V_28 ) ;
V_78 = V_24 -> V_31 ;
V_90 =
V_88 &&
V_78 -> V_4 & V_92 &&
V_24 -> V_93 != V_94 ;
V_91 = V_90 || F_50 ( V_24 ) ;
if ( V_91 )
F_61 ( & V_24 -> V_28 , & V_108 ) ;
else
F_62 ( & V_24 -> V_28 , & V_108 ) ;
V_24 -> V_30 . V_59 = V_58 & ~ V_110 ;
V_24 -> V_30 . V_60 = 0 ;
V_24 -> V_98 = false ;
}
F_63 ( & V_108 , V_16 ) ;
V_109 = 0 ;
do {
int V_51 = 0 ;
F_48 (obj, objects, exec_list) {
struct V_18 * V_78 = V_24 -> V_31 ;
bool V_90 , V_91 ;
if ( ! V_24 -> V_105 )
continue;
V_90 =
V_88 &&
V_78 -> V_4 & V_92 &&
V_24 -> V_93 != V_94 ;
V_91 = V_90 || F_50 ( V_24 ) ;
if ( ( V_78 -> V_95 && V_24 -> V_53 & ( V_78 -> V_95 - 1 ) ) ||
( V_91 && ! V_24 -> V_40 ) )
V_51 = F_64 ( V_24 ) ;
else
V_51 = F_51 ( V_24 , V_86 , V_107 ) ;
if ( V_51 )
goto V_111;
}
F_48 (obj, objects, exec_list) {
if ( V_24 -> V_105 )
continue;
V_51 = F_51 ( V_24 , V_86 , V_107 ) ;
if ( V_51 )
goto V_111;
}
V_111:
F_48 (obj, objects, exec_list)
F_57 ( V_24 ) ;
if ( V_51 != - V_112 || V_109 ++ )
return V_51 ;
V_51 = F_65 ( V_86 -> V_46 ) ;
if ( V_51 )
return V_51 ;
} while ( 1 );
}
static int
F_66 ( struct V_45 * V_46 ,
struct V_2 * args ,
struct V_20 * V_21 ,
struct V_85 * V_86 ,
struct V_1 * V_3 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 ;
struct V_8 * V_24 ;
bool V_107 ;
int * V_113 ;
int V_22 , V_114 , V_51 ;
int V_12 = args -> V_7 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_24 = F_21 ( & V_3 -> V_16 ,
struct V_8 ,
V_28 ) ;
F_22 ( & V_24 -> V_28 ) ;
F_23 ( & V_24 -> V_30 ) ;
}
F_67 ( & V_46 -> V_115 ) ;
V_114 = 0 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
V_114 += V_19 [ V_22 ] . V_82 ;
V_113 = F_68 ( V_12 , sizeof( * V_113 ) ) ;
V_44 = F_68 ( V_114 , sizeof( * V_44 ) ) ;
if ( V_44 == NULL || V_113 == NULL ) {
F_69 ( V_44 ) ;
F_69 ( V_113 ) ;
F_70 ( & V_46 -> V_115 ) ;
return - V_116 ;
}
V_114 = 0 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
struct V_43 T_4 * V_77 ;
T_5 V_117 = ( T_5 ) - 1 ;
int V_118 ;
V_77 = ( void T_4 * ) ( V_80 ) V_19 [ V_22 ] . V_81 ;
if ( F_71 ( V_44 + V_114 , V_77 ,
V_19 [ V_22 ] . V_82 * sizeof( * V_44 ) ) ) {
V_51 = - V_63 ;
F_70 ( & V_46 -> V_115 ) ;
goto V_111;
}
for ( V_118 = 0 ; V_118 < V_19 [ V_22 ] . V_82 ; V_118 ++ ) {
if ( F_72 ( & V_77 [ V_118 ] . V_61 ,
& V_117 ,
sizeof( V_117 ) ) ) {
V_51 = - V_63 ;
F_70 ( & V_46 -> V_115 ) ;
goto V_111;
}
}
V_113 [ V_22 ] = V_114 ;
V_114 += V_19 [ V_22 ] . V_82 ;
}
V_51 = F_73 ( V_46 ) ;
if ( V_51 ) {
F_70 ( & V_46 -> V_115 ) ;
goto V_111;
}
F_6 ( V_3 ) ;
V_51 = F_7 ( V_3 , V_19 , args , V_21 ) ;
if ( V_51 )
goto V_111;
V_107 = ( args -> V_4 & V_119 ) == 0 ;
V_51 = F_60 ( V_86 , V_21 , & V_3 -> V_16 , & V_107 ) ;
if ( V_51 )
goto V_111;
F_48 (obj, &eb->objects, exec_list) {
int V_56 = V_24 -> V_31 - V_19 ;
V_51 = F_45 ( V_24 , V_3 ,
V_44 + V_113 [ V_56 ] ) ;
if ( V_51 )
goto V_111;
}
V_111:
F_69 ( V_44 ) ;
F_69 ( V_113 ) ;
return V_51 ;
}
static int
F_74 ( struct V_85 * V_86 ,
struct V_106 * V_16 )
{
struct V_8 * V_24 ;
T_1 V_120 = 0 ;
int V_51 ;
F_48 (obj, objects, exec_list) {
V_51 = F_75 ( V_24 , V_86 ) ;
if ( V_51 )
return V_51 ;
if ( V_24 -> V_30 . V_38 & V_39 )
F_76 ( V_24 ) ;
V_120 |= V_24 -> V_30 . V_38 ;
}
if ( V_120 & V_39 )
F_77 ( V_86 -> V_46 ) ;
if ( V_120 & V_121 )
F_78 () ;
return F_79 ( V_86 ) ;
}
static bool
F_80 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_122 )
return false ;
return ( ( V_19 -> V_123 | V_19 -> V_124 ) & 0x7 ) == 0 ;
}
static int
F_81 ( struct V_18 * V_19 ,
int V_12 )
{
int V_22 ;
int V_125 = 0 ;
int V_126 = V_127 / sizeof( struct V_43 ) ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
char T_4 * V_128 = ( char T_4 * ) ( V_80 ) V_19 [ V_22 ] . V_81 ;
int V_129 ;
if ( V_19 [ V_22 ] . V_4 & V_130 )
return - V_29 ;
if ( V_19 [ V_22 ] . V_82 > V_126 - V_125 )
return - V_29 ;
V_125 += V_19 [ V_22 ] . V_82 ;
V_129 = V_19 [ V_22 ] . V_82 *
sizeof( struct V_43 ) ;
if ( ! F_82 ( V_131 , V_128 , V_129 ) )
return - V_63 ;
if ( F_83 ( V_128 , V_129 ) )
return - V_63 ;
}
return 0 ;
}
static void
F_84 ( struct V_106 * V_16 ,
struct V_85 * V_86 )
{
struct V_8 * V_24 ;
F_48 (obj, objects, exec_list) {
T_6 V_132 = V_24 -> V_30 . V_57 ;
T_6 V_133 = V_24 -> V_30 . V_38 ;
V_24 -> V_30 . V_38 = V_24 -> V_30 . V_60 ;
if ( V_24 -> V_30 . V_38 == 0 )
V_24 -> V_30 . V_59 |= V_24 -> V_30 . V_57 ;
V_24 -> V_30 . V_57 = V_24 -> V_30 . V_59 ;
V_24 -> V_134 = V_24 -> V_98 ;
F_85 ( V_24 , V_86 ) ;
if ( V_24 -> V_30 . V_38 ) {
V_24 -> V_135 = 1 ;
V_24 -> V_136 = F_86 ( V_86 ) ;
if ( V_24 -> V_137 )
F_87 ( V_24 ) ;
}
F_88 ( V_24 , V_132 , V_133 ) ;
}
}
static void
F_89 ( struct V_45 * V_46 ,
struct V_20 * V_21 ,
struct V_85 * V_86 )
{
V_86 -> V_138 = true ;
( void ) F_90 ( V_86 , V_21 , NULL ) ;
}
static int
F_91 ( struct V_45 * V_46 ,
struct V_85 * V_86 )
{
T_7 * V_70 = V_46 -> V_71 ;
int V_51 , V_22 ;
if ( ! F_92 ( V_46 ) || V_86 != & V_70 -> V_86 [ V_139 ] )
return 0 ;
V_51 = F_93 ( V_86 , 4 * 3 ) ;
if ( V_51 )
return V_51 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
F_94 ( V_86 , F_95 ( 1 ) ) ;
F_94 ( V_86 , F_96 ( V_22 ) ) ;
F_94 ( V_86 , 0 ) ;
}
F_97 ( V_86 ) ;
return 0 ;
}
static int
F_98 ( struct V_45 * V_46 , void * V_140 ,
struct V_20 * V_21 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
T_7 * V_70 = V_46 -> V_71 ;
struct V_1 * V_3 ;
struct V_8 * V_141 ;
struct V_142 * V_143 = NULL ;
struct V_85 * V_86 ;
T_6 V_144 = F_99 ( * args ) ;
T_6 V_145 , V_146 ;
T_6 V_147 , V_4 ;
int V_51 , V_148 , V_22 ;
bool V_107 ;
if ( ! F_80 ( args ) )
return - V_29 ;
V_51 = F_81 ( V_19 , args -> V_7 ) ;
if ( V_51 )
return V_51 ;
V_4 = 0 ;
if ( args -> V_4 & V_149 ) {
if ( ! V_21 -> V_150 || ! F_100 ( V_151 ) )
return - V_152 ;
V_4 |= V_153 ;
}
if ( args -> V_4 & V_154 )
V_4 |= V_155 ;
switch ( args -> V_4 & V_156 ) {
case V_157 :
case V_158 :
V_86 = & V_70 -> V_86 [ V_139 ] ;
break;
case V_159 :
V_86 = & V_70 -> V_86 [ V_160 ] ;
if ( V_144 != 0 ) {
F_12 ( L_11 ,
V_86 -> V_161 ) ;
return - V_152 ;
}
break;
case V_162 :
V_86 = & V_70 -> V_86 [ V_163 ] ;
if ( V_144 != 0 ) {
F_12 ( L_11 ,
V_86 -> V_161 ) ;
return - V_152 ;
}
break;
default:
F_12 ( L_12 ,
( int ) ( args -> V_4 & V_156 ) ) ;
return - V_29 ;
}
if ( ! F_101 ( V_86 ) ) {
F_12 ( L_13 ,
( int ) ( args -> V_4 & V_156 ) ) ;
return - V_29 ;
}
V_148 = args -> V_4 & V_164 ;
V_147 = V_164 ;
switch ( V_148 ) {
case V_165 :
case V_166 :
case V_167 :
if ( V_86 == & V_70 -> V_86 [ V_139 ] &&
V_148 != V_70 -> V_168 ) {
if ( F_52 ( V_46 ) -> V_89 < 4 )
return - V_29 ;
if ( F_52 ( V_46 ) -> V_89 > 5 &&
V_148 == V_167 )
return - V_29 ;
if ( F_52 ( V_46 ) -> V_89 >= 6 )
V_147 &= ~ V_167 ;
}
break;
default:
F_12 ( L_14 , V_148 ) ;
return - V_29 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_15 , args -> V_7 ) ;
return - V_29 ;
}
if ( args -> V_169 != 0 ) {
if ( V_86 != & V_70 -> V_86 [ V_139 ] ) {
F_12 ( L_16 ) ;
return - V_29 ;
}
if ( F_52 ( V_46 ) -> V_89 >= 5 ) {
F_12 ( L_17 ) ;
return - V_29 ;
}
if ( args -> V_169 > V_170 / sizeof( * V_143 ) ) {
F_12 ( L_18 ,
args -> V_169 ) ;
return - V_29 ;
}
V_143 = F_2 ( args -> V_169 * sizeof( * V_143 ) ,
V_171 ) ;
if ( V_143 == NULL ) {
V_51 = - V_116 ;
goto V_172;
}
if ( F_71 ( V_143 ,
(struct V_142 T_4 * ) ( V_80 )
args -> V_173 ,
sizeof( * V_143 ) * args -> V_169 ) ) {
V_51 = - V_63 ;
goto V_172;
}
}
V_51 = F_73 ( V_46 ) ;
if ( V_51 )
goto V_172;
if ( V_70 -> V_99 . V_174 ) {
F_67 ( & V_46 -> V_115 ) ;
V_51 = - V_175 ;
goto V_172;
}
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_67 ( & V_46 -> V_115 ) ;
V_51 = - V_116 ;
goto V_172;
}
V_51 = F_7 ( V_3 , V_19 , args , V_21 ) ;
if ( V_51 )
goto V_111;
V_141 = F_102 ( V_3 -> V_16 . V_176 ,
struct V_8 ,
V_28 ) ;
V_107 = ( args -> V_4 & V_119 ) == 0 ;
V_51 = F_60 ( V_86 , V_21 , & V_3 -> V_16 , & V_107 ) ;
if ( V_51 )
goto V_111;
if ( V_107 )
V_51 = F_46 ( V_46 , V_3 ) ;
if ( V_51 ) {
if ( V_51 == - V_63 ) {
V_51 = F_66 ( V_46 , args , V_21 , V_86 ,
V_3 , V_19 ) ;
F_103 ( ! F_104 ( & V_46 -> V_115 ) ) ;
}
if ( V_51 )
goto V_111;
}
if ( V_141 -> V_30 . V_60 ) {
F_12 ( L_19 ) ;
V_51 = - V_29 ;
goto V_111;
}
V_141 -> V_30 . V_59 |= V_110 ;
if ( V_4 & V_153 && ! V_141 -> V_55 )
F_29 ( V_141 , V_141 -> V_41 ) ;
V_51 = F_74 ( V_86 , & V_3 -> V_16 ) ;
if ( V_51 )
goto V_111;
V_51 = F_105 ( V_86 , V_21 , V_144 ) ;
if ( V_51 )
goto V_111;
if ( V_86 == & V_70 -> V_86 [ V_139 ] &&
V_148 != V_70 -> V_168 ) {
V_51 = F_93 ( V_86 , 4 ) ;
if ( V_51 )
goto V_111;
F_94 ( V_86 , V_177 ) ;
F_94 ( V_86 , F_95 ( 1 ) ) ;
F_94 ( V_86 , V_178 ) ;
F_94 ( V_86 , V_147 << 16 | V_148 ) ;
F_97 ( V_86 ) ;
V_70 -> V_168 = V_148 ;
}
if ( args -> V_4 & V_179 ) {
V_51 = F_91 ( V_46 , V_86 ) ;
if ( V_51 )
goto V_111;
}
V_145 = V_141 -> V_53 + args -> V_123 ;
V_146 = args -> V_124 ;
if ( V_143 ) {
for ( V_22 = 0 ; V_22 < args -> V_169 ; V_22 ++ ) {
V_51 = F_106 ( V_46 , & V_143 [ V_22 ] ,
args -> V_180 , args -> V_181 ) ;
if ( V_51 )
goto V_111;
V_51 = V_86 -> V_182 ( V_86 ,
V_145 , V_146 ,
V_4 ) ;
if ( V_51 )
goto V_111;
}
} else {
V_51 = V_86 -> V_182 ( V_86 ,
V_145 , V_146 ,
V_4 ) ;
if ( V_51 )
goto V_111;
}
F_107 ( V_86 , F_86 ( V_86 ) , V_4 ) ;
F_84 ( & V_3 -> V_16 , V_86 ) ;
F_89 ( V_46 , V_21 , V_86 ) ;
V_111:
F_20 ( V_3 ) ;
F_67 ( & V_46 -> V_115 ) ;
V_172:
F_24 ( V_143 ) ;
return V_51 ;
}
int
F_108 ( struct V_45 * V_46 , void * V_140 ,
struct V_20 * V_21 )
{
struct V_183 * args = V_140 ;
struct V_2 V_184 ;
struct V_185 * V_28 = NULL ;
struct V_18 * V_186 = NULL ;
int V_51 , V_22 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_15 , args -> V_7 ) ;
return - V_29 ;
}
V_28 = F_68 ( sizeof( * V_28 ) , args -> V_7 ) ;
V_186 = F_68 ( sizeof( * V_186 ) , args -> V_7 ) ;
if ( V_28 == NULL || V_186 == NULL ) {
F_12 ( L_20 ,
args -> V_7 ) ;
F_69 ( V_28 ) ;
F_69 ( V_186 ) ;
return - V_116 ;
}
V_51 = F_71 ( V_28 ,
( void T_4 * ) ( V_80 ) args -> V_187 ,
sizeof( * V_28 ) * args -> V_7 ) ;
if ( V_51 != 0 ) {
F_12 ( L_21 ,
args -> V_7 , V_51 ) ;
F_69 ( V_28 ) ;
F_69 ( V_186 ) ;
return - V_63 ;
}
for ( V_22 = 0 ; V_22 < args -> V_7 ; V_22 ++ ) {
V_186 [ V_22 ] . V_26 = V_28 [ V_22 ] . V_26 ;
V_186 [ V_22 ] . V_82 = V_28 [ V_22 ] . V_82 ;
V_186 [ V_22 ] . V_81 = V_28 [ V_22 ] . V_81 ;
V_186 [ V_22 ] . V_95 = V_28 [ V_22 ] . V_95 ;
V_186 [ V_22 ] . V_56 = V_28 [ V_22 ] . V_56 ;
if ( F_52 ( V_46 ) -> V_89 < 4 )
V_186 [ V_22 ] . V_4 = V_92 ;
else
V_186 [ V_22 ] . V_4 = 0 ;
}
V_184 . V_187 = args -> V_187 ;
V_184 . V_7 = args -> V_7 ;
V_184 . V_123 = args -> V_123 ;
V_184 . V_124 = args -> V_124 ;
V_184 . V_180 = args -> V_180 ;
V_184 . V_181 = args -> V_181 ;
V_184 . V_169 = args -> V_169 ;
V_184 . V_173 = args -> V_173 ;
V_184 . V_4 = V_158 ;
F_109 ( V_184 , 0 ) ;
V_51 = F_98 ( V_46 , V_140 , V_21 , & V_184 , V_186 ) ;
if ( ! V_51 ) {
for ( V_22 = 0 ; V_22 < args -> V_7 ; V_22 ++ )
V_28 [ V_22 ] . V_56 = V_186 [ V_22 ] . V_56 ;
V_51 = F_72 ( ( void T_4 * ) ( V_80 ) args -> V_187 ,
V_28 ,
sizeof( * V_28 ) * args -> V_7 ) ;
if ( V_51 ) {
V_51 = - V_63 ;
F_12 ( L_22
L_23 ,
args -> V_7 , V_51 ) ;
}
}
F_69 ( V_28 ) ;
F_69 ( V_186 ) ;
return V_51 ;
}
int
F_110 ( struct V_45 * V_46 , void * V_140 ,
struct V_20 * V_21 )
{
struct V_2 * args = V_140 ;
struct V_18 * V_186 = NULL ;
int V_51 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_170 / sizeof( * V_186 ) ) {
F_12 ( L_24 , args -> V_7 ) ;
return - V_29 ;
}
V_186 = F_2 ( sizeof( * V_186 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_186 == NULL )
V_186 = F_68 ( sizeof( * V_186 ) ,
args -> V_7 ) ;
if ( V_186 == NULL ) {
F_12 ( L_20 ,
args -> V_7 ) ;
return - V_116 ;
}
V_51 = F_71 ( V_186 ,
(struct V_188 T_4 * )
( V_80 ) args -> V_187 ,
sizeof( * V_186 ) * args -> V_7 ) ;
if ( V_51 != 0 ) {
F_12 ( L_21 ,
args -> V_7 , V_51 ) ;
F_69 ( V_186 ) ;
return - V_63 ;
}
V_51 = F_98 ( V_46 , V_140 , V_21 , args , V_186 ) ;
if ( ! V_51 ) {
V_51 = F_72 ( ( void T_4 * ) ( V_80 ) args -> V_187 ,
V_186 ,
sizeof( * V_186 ) * args -> V_7 ) ;
if ( V_51 ) {
V_51 = - V_63 ;
F_12 ( L_22
L_23 ,
args -> V_7 , V_51 ) ;
}
}
F_69 ( V_186 ) ;
return V_51 ;
}
