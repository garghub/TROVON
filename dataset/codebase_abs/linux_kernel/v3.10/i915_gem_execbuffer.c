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
V_77 = F_42 ( V_78 -> V_80 ) ;
V_79 = V_78 -> V_81 ;
while ( V_79 ) {
struct V_43 * V_82 = V_76 ;
int V_12 = V_79 ;
if ( V_12 > F_43 ( V_76 ) )
V_12 = F_43 ( V_76 ) ;
V_79 -= V_12 ;
if ( F_44 ( V_82 , V_77 , V_12 * sizeof( V_82 [ 0 ] ) ) )
return - V_63 ;
do {
T_5 V_56 = V_82 -> V_61 ;
V_51 = F_26 ( V_24 , V_3 , V_82 ) ;
if ( V_51 )
return V_51 ;
if ( V_82 -> V_61 != V_56 &&
F_45 ( & V_77 -> V_61 ,
& V_82 -> V_61 ,
sizeof( V_82 -> V_61 ) ) ) {
return - V_63 ;
}
V_77 ++ ;
V_82 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_41
}
static int
F_46 ( struct V_8 * V_24 ,
struct V_1 * V_3 ,
struct V_43 * V_83 )
{
const struct V_18 * V_78 = V_24 -> V_31 ;
int V_22 , V_51 ;
for ( V_22 = 0 ; V_22 < V_78 -> V_81 ; V_22 ++ ) {
V_51 = F_26 ( V_24 , V_3 , & V_83 [ V_22 ] ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int
F_47 ( struct V_1 * V_3 )
{
struct V_8 * V_24 ;
int V_51 = 0 ;
F_48 () ;
F_49 (obj, &eb->objects, exec_list) {
V_51 = F_40 ( V_24 , V_3 ) ;
if ( V_51 )
break;
}
F_50 () ;
return V_51 ;
}
static int
F_51 ( struct V_8 * V_24 )
{
struct V_18 * V_78 = V_24 -> V_31 ;
return V_78 -> V_81 && ! F_25 ( V_24 ) ;
}
static int
F_52 ( struct V_8 * V_24 ,
struct V_84 * V_85 ,
bool * V_86 )
{
struct V_69 * V_70 = V_24 -> V_30 . V_46 -> V_71 ;
struct V_18 * V_78 = V_24 -> V_31 ;
bool V_87 = F_53 ( V_85 -> V_46 ) -> V_88 < 4 ;
bool V_89 , V_90 ;
int V_51 ;
V_89 =
V_87 &&
V_78 -> V_4 & V_91 &&
V_24 -> V_92 != V_93 ;
V_90 = V_89 || F_51 ( V_24 ) ;
V_51 = F_54 ( V_24 , V_78 -> V_94 , V_90 , false ) ;
if ( V_51 )
return V_51 ;
V_78 -> V_4 |= V_95 ;
if ( V_87 ) {
if ( V_78 -> V_4 & V_91 ) {
V_51 = F_55 ( V_24 ) ;
if ( V_51 )
return V_51 ;
if ( F_56 ( V_24 ) )
V_78 -> V_4 |= V_96 ;
V_24 -> V_97 = true ;
}
}
if ( V_70 -> V_98 . V_99 && ! V_24 -> V_100 ) {
F_57 ( V_70 -> V_98 . V_99 ,
V_24 , V_24 -> V_41 ) ;
V_24 -> V_100 = 1 ;
}
if ( V_78 -> V_56 != V_24 -> V_53 ) {
V_78 -> V_56 = V_24 -> V_53 ;
* V_86 = true ;
}
if ( V_78 -> V_4 & V_101 ) {
V_24 -> V_30 . V_59 = V_102 ;
V_24 -> V_30 . V_60 = V_102 ;
}
if ( V_78 -> V_4 & V_103 &&
! V_24 -> V_55 )
F_29 ( V_24 , V_24 -> V_41 ) ;
return 0 ;
}
static void
F_58 ( struct V_8 * V_24 )
{
struct V_18 * V_78 ;
if ( ! V_24 -> V_104 )
return;
V_78 = V_24 -> V_31 ;
if ( V_78 -> V_4 & V_96 )
F_59 ( V_24 ) ;
if ( V_78 -> V_4 & V_95 )
F_60 ( V_24 ) ;
V_78 -> V_4 &= ~ ( V_96 | V_95 ) ;
}
static int
F_61 ( struct V_84 * V_85 ,
struct V_105 * V_16 ,
bool * V_106 )
{
struct V_8 * V_24 ;
struct V_105 V_107 ;
bool V_87 = F_53 ( V_85 -> V_46 ) -> V_88 < 4 ;
int V_108 ;
F_5 ( & V_107 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_78 ;
bool V_89 , V_90 ;
V_24 = F_21 ( V_16 ,
struct V_8 ,
V_28 ) ;
V_78 = V_24 -> V_31 ;
V_89 =
V_87 &&
V_78 -> V_4 & V_91 &&
V_24 -> V_92 != V_93 ;
V_90 = V_89 || F_51 ( V_24 ) ;
if ( V_90 )
F_62 ( & V_24 -> V_28 , & V_107 ) ;
else
F_63 ( & V_24 -> V_28 , & V_107 ) ;
V_24 -> V_30 . V_59 = V_58 & ~ V_109 ;
V_24 -> V_30 . V_60 = 0 ;
V_24 -> V_97 = false ;
}
F_64 ( & V_107 , V_16 ) ;
V_108 = 0 ;
do {
int V_51 = 0 ;
F_49 (obj, objects, exec_list) {
struct V_18 * V_78 = V_24 -> V_31 ;
bool V_89 , V_90 ;
if ( ! V_24 -> V_104 )
continue;
V_89 =
V_87 &&
V_78 -> V_4 & V_91 &&
V_24 -> V_92 != V_93 ;
V_90 = V_89 || F_51 ( V_24 ) ;
if ( ( V_78 -> V_94 && V_24 -> V_53 & ( V_78 -> V_94 - 1 ) ) ||
( V_90 && ! V_24 -> V_40 ) )
V_51 = F_65 ( V_24 ) ;
else
V_51 = F_52 ( V_24 , V_85 , V_106 ) ;
if ( V_51 )
goto V_110;
}
F_49 (obj, objects, exec_list) {
if ( V_24 -> V_104 )
continue;
V_51 = F_52 ( V_24 , V_85 , V_106 ) ;
if ( V_51 )
goto V_110;
}
V_110:
F_49 (obj, objects, exec_list)
F_58 ( V_24 ) ;
if ( V_51 != - V_111 || V_108 ++ )
return V_51 ;
V_51 = F_66 ( V_85 -> V_46 ) ;
if ( V_51 )
return V_51 ;
} while ( 1 );
}
static int
F_67 ( struct V_45 * V_46 ,
struct V_2 * args ,
struct V_20 * V_21 ,
struct V_84 * V_85 ,
struct V_1 * V_3 ,
struct V_18 * V_19 )
{
struct V_43 * V_44 ;
struct V_8 * V_24 ;
bool V_106 ;
int * V_112 ;
int V_22 , V_113 , V_51 ;
int V_12 = args -> V_7 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_24 = F_21 ( & V_3 -> V_16 ,
struct V_8 ,
V_28 ) ;
F_22 ( & V_24 -> V_28 ) ;
F_23 ( & V_24 -> V_30 ) ;
}
F_68 ( & V_46 -> V_114 ) ;
V_113 = 0 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
V_113 += V_19 [ V_22 ] . V_81 ;
V_112 = F_69 ( V_12 , sizeof( * V_112 ) ) ;
V_44 = F_69 ( V_113 , sizeof( * V_44 ) ) ;
if ( V_44 == NULL || V_112 == NULL ) {
F_70 ( V_44 ) ;
F_70 ( V_112 ) ;
F_71 ( & V_46 -> V_114 ) ;
return - V_115 ;
}
V_113 = 0 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
struct V_43 T_4 * V_77 ;
T_5 V_116 = ( T_5 ) - 1 ;
int V_117 ;
V_77 = F_42 ( V_19 [ V_22 ] . V_80 ) ;
if ( F_72 ( V_44 + V_113 , V_77 ,
V_19 [ V_22 ] . V_81 * sizeof( * V_44 ) ) ) {
V_51 = - V_63 ;
F_71 ( & V_46 -> V_114 ) ;
goto V_110;
}
for ( V_117 = 0 ; V_117 < V_19 [ V_22 ] . V_81 ; V_117 ++ ) {
if ( F_73 ( & V_77 [ V_117 ] . V_61 ,
& V_116 ,
sizeof( V_116 ) ) ) {
V_51 = - V_63 ;
F_71 ( & V_46 -> V_114 ) ;
goto V_110;
}
}
V_112 [ V_22 ] = V_113 ;
V_113 += V_19 [ V_22 ] . V_81 ;
}
V_51 = F_74 ( V_46 ) ;
if ( V_51 ) {
F_71 ( & V_46 -> V_114 ) ;
goto V_110;
}
F_6 ( V_3 ) ;
V_51 = F_7 ( V_3 , V_19 , args , V_21 ) ;
if ( V_51 )
goto V_110;
V_106 = ( args -> V_4 & V_118 ) == 0 ;
V_51 = F_61 ( V_85 , & V_3 -> V_16 , & V_106 ) ;
if ( V_51 )
goto V_110;
F_49 (obj, &eb->objects, exec_list) {
int V_56 = V_24 -> V_31 - V_19 ;
V_51 = F_46 ( V_24 , V_3 ,
V_44 + V_112 [ V_56 ] ) ;
if ( V_51 )
goto V_110;
}
V_110:
F_70 ( V_44 ) ;
F_70 ( V_112 ) ;
return V_51 ;
}
static int
F_75 ( struct V_84 * V_85 ,
struct V_105 * V_16 )
{
struct V_8 * V_24 ;
T_1 V_119 = 0 ;
int V_51 ;
F_49 (obj, objects, exec_list) {
V_51 = F_76 ( V_24 , V_85 ) ;
if ( V_51 )
return V_51 ;
if ( V_24 -> V_30 . V_38 & V_39 )
F_77 ( V_24 ) ;
V_119 |= V_24 -> V_30 . V_38 ;
}
if ( V_119 & V_39 )
F_78 ( V_85 -> V_46 ) ;
if ( V_119 & V_120 )
F_79 () ;
return F_80 ( V_85 ) ;
}
static bool
F_81 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_121 )
return false ;
return ( ( V_19 -> V_122 | V_19 -> V_123 ) & 0x7 ) == 0 ;
}
static int
F_82 ( struct V_18 * V_19 ,
int V_12 )
{
int V_22 ;
int V_124 = 0 ;
int V_125 = V_126 / sizeof( struct V_43 ) ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
char T_4 * V_127 = F_42 ( V_19 [ V_22 ] . V_80 ) ;
int V_128 ;
if ( V_19 [ V_22 ] . V_4 & V_129 )
return - V_29 ;
if ( V_19 [ V_22 ] . V_81 > V_125 - V_124 )
return - V_29 ;
V_124 += V_19 [ V_22 ] . V_81 ;
V_128 = V_19 [ V_22 ] . V_81 *
sizeof( struct V_43 ) ;
if ( ! F_83 ( V_130 , V_127 , V_128 ) )
return - V_63 ;
if ( F_84 ( V_127 , V_128 ) )
return - V_63 ;
}
return 0 ;
}
static void
F_85 ( struct V_105 * V_16 ,
struct V_84 * V_85 )
{
struct V_8 * V_24 ;
F_49 (obj, objects, exec_list) {
T_6 V_131 = V_24 -> V_30 . V_57 ;
T_6 V_132 = V_24 -> V_30 . V_38 ;
V_24 -> V_30 . V_38 = V_24 -> V_30 . V_60 ;
if ( V_24 -> V_30 . V_38 == 0 )
V_24 -> V_30 . V_59 |= V_24 -> V_30 . V_57 ;
V_24 -> V_30 . V_57 = V_24 -> V_30 . V_59 ;
V_24 -> V_133 = V_24 -> V_97 ;
F_86 ( V_24 , V_85 ) ;
if ( V_24 -> V_30 . V_38 ) {
V_24 -> V_134 = 1 ;
V_24 -> V_135 = F_87 ( V_85 ) ;
if ( V_24 -> V_136 )
F_88 ( V_24 ) ;
}
F_89 ( V_24 , V_131 , V_132 ) ;
}
}
static void
F_90 ( struct V_45 * V_46 ,
struct V_20 * V_21 ,
struct V_84 * V_85 )
{
V_85 -> V_137 = true ;
( void ) F_91 ( V_85 , V_21 , NULL ) ;
}
static int
F_92 ( struct V_45 * V_46 ,
struct V_84 * V_85 )
{
T_7 * V_70 = V_46 -> V_71 ;
int V_51 , V_22 ;
if ( ! F_93 ( V_46 ) || V_85 != & V_70 -> V_85 [ V_138 ] )
return 0 ;
V_51 = F_94 ( V_85 , 4 * 3 ) ;
if ( V_51 )
return V_51 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
F_95 ( V_85 , F_96 ( 1 ) ) ;
F_95 ( V_85 , F_97 ( V_22 ) ) ;
F_95 ( V_85 , 0 ) ;
}
F_98 ( V_85 ) ;
return 0 ;
}
static int
F_99 ( struct V_45 * V_46 , void * V_139 ,
struct V_20 * V_21 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
T_7 * V_70 = V_46 -> V_71 ;
struct V_1 * V_3 ;
struct V_8 * V_140 ;
struct V_141 * V_142 = NULL ;
struct V_84 * V_85 ;
T_6 V_143 = F_100 ( * args ) ;
T_6 V_144 , V_145 ;
T_6 V_146 , V_4 ;
int V_51 , V_147 , V_22 ;
bool V_106 ;
if ( ! F_81 ( args ) )
return - V_29 ;
V_51 = F_82 ( V_19 , args -> V_7 ) ;
if ( V_51 )
return V_51 ;
V_4 = 0 ;
if ( args -> V_4 & V_148 ) {
if ( ! V_21 -> V_149 || ! F_101 ( V_150 ) )
return - V_151 ;
V_4 |= V_152 ;
}
if ( args -> V_4 & V_153 )
V_4 |= V_154 ;
switch ( args -> V_4 & V_155 ) {
case V_156 :
case V_157 :
V_85 = & V_70 -> V_85 [ V_138 ] ;
break;
case V_158 :
V_85 = & V_70 -> V_85 [ V_159 ] ;
if ( V_143 != 0 ) {
F_12 ( L_11 ,
V_85 -> V_160 ) ;
return - V_151 ;
}
break;
case V_161 :
V_85 = & V_70 -> V_85 [ V_162 ] ;
if ( V_143 != 0 ) {
F_12 ( L_11 ,
V_85 -> V_160 ) ;
return - V_151 ;
}
break;
default:
F_12 ( L_12 ,
( int ) ( args -> V_4 & V_155 ) ) ;
return - V_29 ;
}
if ( ! F_102 ( V_85 ) ) {
F_12 ( L_13 ,
( int ) ( args -> V_4 & V_155 ) ) ;
return - V_29 ;
}
V_147 = args -> V_4 & V_163 ;
V_146 = V_163 ;
switch ( V_147 ) {
case V_164 :
case V_165 :
case V_166 :
if ( V_85 == & V_70 -> V_85 [ V_138 ] &&
V_147 != V_70 -> V_167 ) {
if ( F_53 ( V_46 ) -> V_88 < 4 )
return - V_29 ;
if ( F_53 ( V_46 ) -> V_88 > 5 &&
V_147 == V_166 )
return - V_29 ;
if ( F_53 ( V_46 ) -> V_88 >= 6 )
V_146 &= ~ V_166 ;
}
break;
default:
F_12 ( L_14 , V_147 ) ;
return - V_29 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_15 , args -> V_7 ) ;
return - V_29 ;
}
if ( args -> V_168 != 0 ) {
if ( V_85 != & V_70 -> V_85 [ V_138 ] ) {
F_12 ( L_16 ) ;
return - V_29 ;
}
if ( F_53 ( V_46 ) -> V_88 >= 5 ) {
F_12 ( L_17 ) ;
return - V_29 ;
}
if ( args -> V_168 > V_169 / sizeof( * V_142 ) ) {
F_12 ( L_18 ,
args -> V_168 ) ;
return - V_29 ;
}
V_142 = F_2 ( args -> V_168 * sizeof( * V_142 ) ,
V_170 ) ;
if ( V_142 == NULL ) {
V_51 = - V_115 ;
goto V_171;
}
if ( F_72 ( V_142 ,
F_42 ( args -> V_172 ) ,
sizeof( * V_142 ) * args -> V_168 ) ) {
V_51 = - V_63 ;
goto V_171;
}
}
V_51 = F_74 ( V_46 ) ;
if ( V_51 )
goto V_171;
if ( V_70 -> V_98 . V_173 ) {
F_68 ( & V_46 -> V_114 ) ;
V_51 = - V_174 ;
goto V_171;
}
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_68 ( & V_46 -> V_114 ) ;
V_51 = - V_115 ;
goto V_171;
}
V_51 = F_7 ( V_3 , V_19 , args , V_21 ) ;
if ( V_51 )
goto V_110;
V_140 = F_103 ( V_3 -> V_16 . V_175 ,
struct V_8 ,
V_28 ) ;
V_106 = ( args -> V_4 & V_118 ) == 0 ;
V_51 = F_61 ( V_85 , & V_3 -> V_16 , & V_106 ) ;
if ( V_51 )
goto V_110;
if ( V_106 )
V_51 = F_47 ( V_3 ) ;
if ( V_51 ) {
if ( V_51 == - V_63 ) {
V_51 = F_67 ( V_46 , args , V_21 , V_85 ,
V_3 , V_19 ) ;
F_104 ( ! F_105 ( & V_46 -> V_114 ) ) ;
}
if ( V_51 )
goto V_110;
}
if ( V_140 -> V_30 . V_60 ) {
F_12 ( L_19 ) ;
V_51 = - V_29 ;
goto V_110;
}
V_140 -> V_30 . V_59 |= V_109 ;
if ( V_4 & V_152 && ! V_140 -> V_55 )
F_29 ( V_140 , V_140 -> V_41 ) ;
V_51 = F_75 ( V_85 , & V_3 -> V_16 ) ;
if ( V_51 )
goto V_110;
V_51 = F_106 ( V_85 , V_21 , V_143 ) ;
if ( V_51 )
goto V_110;
if ( V_85 == & V_70 -> V_85 [ V_138 ] &&
V_147 != V_70 -> V_167 ) {
V_51 = F_94 ( V_85 , 4 ) ;
if ( V_51 )
goto V_110;
F_95 ( V_85 , V_176 ) ;
F_95 ( V_85 , F_96 ( 1 ) ) ;
F_95 ( V_85 , V_177 ) ;
F_95 ( V_85 , V_146 << 16 | V_147 ) ;
F_98 ( V_85 ) ;
V_70 -> V_167 = V_147 ;
}
if ( args -> V_4 & V_178 ) {
V_51 = F_92 ( V_46 , V_85 ) ;
if ( V_51 )
goto V_110;
}
V_144 = V_140 -> V_53 + args -> V_122 ;
V_145 = args -> V_123 ;
if ( V_142 ) {
for ( V_22 = 0 ; V_22 < args -> V_168 ; V_22 ++ ) {
V_51 = F_107 ( V_46 , & V_142 [ V_22 ] ,
args -> V_179 , args -> V_180 ) ;
if ( V_51 )
goto V_110;
V_51 = V_85 -> V_181 ( V_85 ,
V_144 , V_145 ,
V_4 ) ;
if ( V_51 )
goto V_110;
}
} else {
V_51 = V_85 -> V_181 ( V_85 ,
V_144 , V_145 ,
V_4 ) ;
if ( V_51 )
goto V_110;
}
F_108 ( V_85 , F_87 ( V_85 ) , V_4 ) ;
F_85 ( & V_3 -> V_16 , V_85 ) ;
F_90 ( V_46 , V_21 , V_85 ) ;
V_110:
F_20 ( V_3 ) ;
F_68 ( & V_46 -> V_114 ) ;
V_171:
F_24 ( V_142 ) ;
return V_51 ;
}
int
F_109 ( struct V_45 * V_46 , void * V_139 ,
struct V_20 * V_21 )
{
struct V_182 * args = V_139 ;
struct V_2 V_183 ;
struct V_184 * V_28 = NULL ;
struct V_18 * V_185 = NULL ;
int V_51 , V_22 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_15 , args -> V_7 ) ;
return - V_29 ;
}
V_28 = F_69 ( sizeof( * V_28 ) , args -> V_7 ) ;
V_185 = F_69 ( sizeof( * V_185 ) , args -> V_7 ) ;
if ( V_28 == NULL || V_185 == NULL ) {
F_12 ( L_20 ,
args -> V_7 ) ;
F_70 ( V_28 ) ;
F_70 ( V_185 ) ;
return - V_115 ;
}
V_51 = F_72 ( V_28 ,
F_42 ( args -> V_186 ) ,
sizeof( * V_28 ) * args -> V_7 ) ;
if ( V_51 != 0 ) {
F_12 ( L_21 ,
args -> V_7 , V_51 ) ;
F_70 ( V_28 ) ;
F_70 ( V_185 ) ;
return - V_63 ;
}
for ( V_22 = 0 ; V_22 < args -> V_7 ; V_22 ++ ) {
V_185 [ V_22 ] . V_26 = V_28 [ V_22 ] . V_26 ;
V_185 [ V_22 ] . V_81 = V_28 [ V_22 ] . V_81 ;
V_185 [ V_22 ] . V_80 = V_28 [ V_22 ] . V_80 ;
V_185 [ V_22 ] . V_94 = V_28 [ V_22 ] . V_94 ;
V_185 [ V_22 ] . V_56 = V_28 [ V_22 ] . V_56 ;
if ( F_53 ( V_46 ) -> V_88 < 4 )
V_185 [ V_22 ] . V_4 = V_91 ;
else
V_185 [ V_22 ] . V_4 = 0 ;
}
V_183 . V_186 = args -> V_186 ;
V_183 . V_7 = args -> V_7 ;
V_183 . V_122 = args -> V_122 ;
V_183 . V_123 = args -> V_123 ;
V_183 . V_179 = args -> V_179 ;
V_183 . V_180 = args -> V_180 ;
V_183 . V_168 = args -> V_168 ;
V_183 . V_172 = args -> V_172 ;
V_183 . V_4 = V_157 ;
F_110 ( V_183 , 0 ) ;
V_51 = F_99 ( V_46 , V_139 , V_21 , & V_183 , V_185 ) ;
if ( ! V_51 ) {
for ( V_22 = 0 ; V_22 < args -> V_7 ; V_22 ++ )
V_28 [ V_22 ] . V_56 = V_185 [ V_22 ] . V_56 ;
V_51 = F_73 ( F_42 ( args -> V_186 ) ,
V_28 ,
sizeof( * V_28 ) * args -> V_7 ) ;
if ( V_51 ) {
V_51 = - V_63 ;
F_12 ( L_22
L_23 ,
args -> V_7 , V_51 ) ;
}
}
F_70 ( V_28 ) ;
F_70 ( V_185 ) ;
return V_51 ;
}
int
F_111 ( struct V_45 * V_46 , void * V_139 ,
struct V_20 * V_21 )
{
struct V_2 * args = V_139 ;
struct V_18 * V_185 = NULL ;
int V_51 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_169 / sizeof( * V_185 ) ) {
F_12 ( L_24 , args -> V_7 ) ;
return - V_29 ;
}
V_185 = F_2 ( sizeof( * V_185 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_185 == NULL )
V_185 = F_69 ( sizeof( * V_185 ) ,
args -> V_7 ) ;
if ( V_185 == NULL ) {
F_12 ( L_20 ,
args -> V_7 ) ;
return - V_115 ;
}
V_51 = F_72 ( V_185 ,
F_42 ( args -> V_186 ) ,
sizeof( * V_185 ) * args -> V_7 ) ;
if ( V_51 != 0 ) {
F_12 ( L_21 ,
args -> V_7 , V_51 ) ;
F_70 ( V_185 ) ;
return - V_63 ;
}
V_51 = F_99 ( V_46 , V_139 , V_21 , args , V_185 ) ;
if ( ! V_51 ) {
V_51 = F_73 ( F_42 ( args -> V_186 ) ,
V_185 ,
sizeof( * V_185 ) * args -> V_7 ) ;
if ( V_51 ) {
V_51 = - V_63 ;
F_12 ( L_22
L_23 ,
args -> V_7 , V_51 ) ;
}
}
F_70 ( V_185 ) ;
return V_51 ;
}
