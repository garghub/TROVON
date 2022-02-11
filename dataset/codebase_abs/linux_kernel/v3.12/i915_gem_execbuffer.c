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
struct V_43 * V_44 )
{
T_1 V_45 = F_27 ( V_44 -> V_46 ) ;
char * V_47 ;
int V_48 = - V_29 ;
V_48 = F_28 ( V_24 , 1 ) ;
if ( V_48 )
return V_48 ;
V_47 = F_29 ( F_30 ( V_24 ,
V_44 -> V_46 >> V_49 ) ) ;
* ( T_1 * ) ( V_47 + V_45 ) = V_44 -> V_50 ;
F_31 ( V_47 ) ;
return 0 ;
}
static int
F_32 ( struct V_8 * V_24 ,
struct V_43 * V_44 )
{
struct V_51 * V_52 = V_24 -> V_30 . V_52 ;
struct V_53 * V_54 = V_52 -> V_55 ;
T_1 T_2 * V_56 ;
void T_2 * V_57 ;
int V_48 = - V_29 ;
V_48 = F_33 ( V_24 , true ) ;
if ( V_48 )
return V_48 ;
V_48 = F_34 ( V_24 ) ;
if ( V_48 )
return V_48 ;
V_44 -> V_46 += F_35 ( V_24 ) ;
V_57 = F_36 ( V_54 -> V_58 . V_59 ,
V_44 -> V_46 & V_60 ) ;
V_56 = ( T_1 T_2 * )
( V_57 + F_27 ( V_44 -> V_46 ) ) ;
F_37 ( V_44 -> V_50 , V_56 ) ;
F_38 ( V_57 ) ;
return 0 ;
}
static int
F_39 ( struct V_8 * V_24 ,
struct V_1 * V_3 ,
struct V_43 * V_44 ,
struct V_61 * V_62 )
{
struct V_51 * V_52 = V_24 -> V_30 . V_52 ;
struct V_63 * V_64 ;
struct V_8 * V_65 ;
T_1 V_66 ;
int V_48 = - V_29 ;
V_64 = & F_17 ( V_3 , V_44 -> V_67 ) -> V_30 ;
if ( F_40 ( V_64 == NULL ) )
return - V_27 ;
V_65 = F_9 ( V_64 ) ;
V_66 = F_35 ( V_65 ) ;
if ( F_40 ( F_41 ( V_52 ) &&
V_44 -> V_38 == V_68 &&
! V_65 -> V_69 ) ) {
F_42 ( V_65 ,
V_65 -> V_41 ) ;
}
if ( F_40 ( V_44 -> V_38 & ( V_44 -> V_38 - 1 ) ) ) {
F_12 ( L_3
L_4
L_5 ,
V_24 , V_44 -> V_67 ,
( int ) V_44 -> V_46 ,
V_44 -> V_70 ,
V_44 -> V_38 ) ;
return V_48 ;
}
if ( F_40 ( ( V_44 -> V_38 | V_44 -> V_70 )
& ~ V_71 ) ) {
F_12 ( L_6
L_4
L_5 ,
V_24 , V_44 -> V_67 ,
( int ) V_44 -> V_46 ,
V_44 -> V_70 ,
V_44 -> V_38 ) ;
return V_48 ;
}
V_64 -> V_72 |= V_44 -> V_70 ;
V_64 -> V_73 |= V_44 -> V_38 ;
if ( V_66 == V_44 -> V_74 )
return 0 ;
if ( F_40 ( V_44 -> V_46 > V_24 -> V_30 . V_6 - 4 ) ) {
F_12 ( L_7
L_8 ,
V_24 , V_44 -> V_67 ,
( int ) V_44 -> V_46 ,
( int ) V_24 -> V_30 . V_6 ) ;
return V_48 ;
}
if ( F_40 ( V_44 -> V_46 & 3 ) ) {
F_12 ( L_9
L_10 ,
V_24 , V_44 -> V_67 ,
( int ) V_44 -> V_46 ) ;
return V_48 ;
}
if ( V_24 -> V_75 && F_43 () )
return - V_76 ;
V_44 -> V_50 += V_66 ;
if ( F_25 ( V_24 ) )
V_48 = F_26 ( V_24 , V_44 ) ;
else
V_48 = F_32 ( V_24 , V_44 ) ;
if ( V_48 )
return V_48 ;
V_44 -> V_74 = V_66 ;
return 0 ;
}
static int
F_44 ( struct V_8 * V_24 ,
struct V_1 * V_3 ,
struct V_61 * V_62 )
{
#define F_45 ( T_3 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_43 V_77 [ F_45 ( 512 ) ] ;
struct V_43 T_4 * V_78 ;
struct V_18 * V_79 = V_24 -> V_31 ;
int V_80 , V_48 ;
V_78 = F_46 ( V_79 -> V_81 ) ;
V_80 = V_79 -> V_82 ;
while ( V_80 ) {
struct V_43 * V_83 = V_77 ;
int V_12 = V_80 ;
if ( V_12 > F_47 ( V_77 ) )
V_12 = F_47 ( V_77 ) ;
V_80 -= V_12 ;
if ( F_48 ( V_83 , V_78 , V_12 * sizeof( V_83 [ 0 ] ) ) )
return - V_76 ;
do {
T_5 V_46 = V_83 -> V_74 ;
V_48 = F_39 ( V_24 , V_3 , V_83 ,
V_62 ) ;
if ( V_48 )
return V_48 ;
if ( V_83 -> V_74 != V_46 &&
F_49 ( & V_78 -> V_74 ,
& V_83 -> V_74 ,
sizeof( V_83 -> V_74 ) ) ) {
return - V_76 ;
}
V_78 ++ ;
V_83 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_45
}
static int
F_50 ( struct V_8 * V_24 ,
struct V_1 * V_3 ,
struct V_43 * V_84 ,
struct V_61 * V_62 )
{
const struct V_18 * V_79 = V_24 -> V_31 ;
int V_22 , V_48 ;
for ( V_22 = 0 ; V_22 < V_79 -> V_82 ; V_22 ++ ) {
V_48 = F_39 ( V_24 , V_3 , & V_84 [ V_22 ] ,
V_62 ) ;
if ( V_48 )
return V_48 ;
}
return 0 ;
}
static int
F_51 ( struct V_1 * V_3 ,
struct V_61 * V_62 )
{
struct V_8 * V_24 ;
int V_48 = 0 ;
F_52 () ;
F_53 (obj, &eb->objects, exec_list) {
V_48 = F_44 ( V_24 , V_3 , V_62 ) ;
if ( V_48 )
break;
}
F_54 () ;
return V_48 ;
}
static int
F_55 ( struct V_8 * V_24 )
{
struct V_18 * V_79 = V_24 -> V_31 ;
return V_79 -> V_82 && ! F_25 ( V_24 ) ;
}
static int
F_56 ( struct V_8 * V_24 ,
struct V_85 * V_86 ,
struct V_61 * V_62 ,
bool * V_87 )
{
struct V_53 * V_54 = V_24 -> V_30 . V_52 -> V_55 ;
struct V_18 * V_79 = V_24 -> V_31 ;
bool V_88 = F_57 ( V_86 -> V_52 ) -> V_89 < 4 ;
bool V_90 , V_91 ;
int V_48 ;
V_90 =
V_88 &&
V_79 -> V_4 & V_92 &&
V_24 -> V_93 != V_94 ;
V_91 = V_90 || F_55 ( V_24 ) ;
V_48 = F_58 ( V_24 , V_62 , V_79 -> V_95 , V_91 ,
false ) ;
if ( V_48 )
return V_48 ;
V_79 -> V_4 |= V_96 ;
if ( V_88 ) {
if ( V_79 -> V_4 & V_92 ) {
V_48 = F_59 ( V_24 ) ;
if ( V_48 )
return V_48 ;
if ( F_60 ( V_24 ) )
V_79 -> V_4 |= V_97 ;
V_24 -> V_98 = true ;
}
}
if ( V_54 -> V_99 . V_100 && ! V_24 -> V_101 ) {
F_61 ( V_54 -> V_99 . V_100 ,
V_24 , V_24 -> V_41 ) ;
V_24 -> V_101 = 1 ;
}
if ( V_79 -> V_46 != F_62 ( V_24 , V_62 ) ) {
V_79 -> V_46 = F_62 ( V_24 , V_62 ) ;
* V_87 = true ;
}
if ( V_79 -> V_4 & V_102 ) {
V_24 -> V_30 . V_72 = V_103 ;
V_24 -> V_30 . V_73 = V_103 ;
}
if ( V_79 -> V_4 & V_104 &&
! V_24 -> V_69 )
F_42 ( V_24 , V_24 -> V_41 ) ;
return 0 ;
}
static void
F_63 ( struct V_8 * V_24 )
{
struct V_18 * V_79 ;
if ( ! F_64 ( V_24 ) )
return;
V_79 = V_24 -> V_31 ;
if ( V_79 -> V_4 & V_97 )
F_65 ( V_24 ) ;
if ( V_79 -> V_4 & V_96 )
F_66 ( V_24 ) ;
V_79 -> V_4 &= ~ ( V_97 | V_96 ) ;
}
static int
F_67 ( struct V_85 * V_86 ,
struct V_105 * V_16 ,
struct V_61 * V_62 ,
bool * V_106 )
{
struct V_8 * V_24 ;
struct V_105 V_107 ;
bool V_88 = F_57 ( V_86 -> V_52 ) -> V_89 < 4 ;
int V_108 ;
F_5 ( & V_107 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_79 ;
bool V_90 , V_91 ;
V_24 = F_21 ( V_16 ,
struct V_8 ,
V_28 ) ;
V_79 = V_24 -> V_31 ;
V_90 =
V_88 &&
V_79 -> V_4 & V_92 &&
V_24 -> V_93 != V_94 ;
V_91 = V_90 || F_55 ( V_24 ) ;
if ( V_91 )
F_68 ( & V_24 -> V_28 , & V_107 ) ;
else
F_69 ( & V_24 -> V_28 , & V_107 ) ;
V_24 -> V_30 . V_72 = V_71 & ~ V_109 ;
V_24 -> V_30 . V_73 = 0 ;
V_24 -> V_98 = false ;
}
F_70 ( & V_107 , V_16 ) ;
V_108 = 0 ;
do {
int V_48 = 0 ;
F_53 (obj, objects, exec_list) {
struct V_18 * V_79 = V_24 -> V_31 ;
bool V_90 , V_91 ;
T_6 V_110 ;
if ( ! F_71 ( V_24 , V_62 ) )
continue;
V_110 = F_62 ( V_24 , V_62 ) ;
V_90 =
V_88 &&
V_79 -> V_4 & V_92 &&
V_24 -> V_93 != V_94 ;
V_91 = V_90 || F_55 ( V_24 ) ;
F_72 ( ( V_91 || V_90 ) &&
! F_73 ( V_62 ) ) ;
if ( ( V_79 -> V_95 &&
V_110 & ( V_79 -> V_95 - 1 ) ) ||
( V_91 && ! V_24 -> V_40 ) )
V_48 = F_74 ( F_75 ( V_24 , V_62 ) ) ;
else
V_48 = F_56 ( V_24 , V_86 , V_62 , V_106 ) ;
if ( V_48 )
goto V_111;
}
F_53 (obj, objects, exec_list) {
if ( F_71 ( V_24 , V_62 ) )
continue;
V_48 = F_56 ( V_24 , V_86 , V_62 , V_106 ) ;
if ( V_48 )
goto V_111;
}
V_111:
F_53 (obj, objects, exec_list)
F_63 ( V_24 ) ;
if ( V_48 != - V_112 || V_108 ++ )
return V_48 ;
V_48 = F_76 ( V_86 -> V_52 ) ;
if ( V_48 )
return V_48 ;
} while ( 1 );
}
static int
F_77 ( struct V_51 * V_52 ,
struct V_2 * args ,
struct V_20 * V_21 ,
struct V_85 * V_86 ,
struct V_1 * V_3 ,
struct V_18 * V_19 ,
struct V_61 * V_62 )
{
struct V_43 * V_44 ;
struct V_8 * V_24 ;
bool V_106 ;
int * V_113 ;
int V_22 , V_114 , V_48 ;
int V_12 = args -> V_7 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_24 = F_21 ( & V_3 -> V_16 ,
struct V_8 ,
V_28 ) ;
F_22 ( & V_24 -> V_28 ) ;
F_23 ( & V_24 -> V_30 ) ;
}
F_78 ( & V_52 -> V_115 ) ;
V_114 = 0 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ )
V_114 += V_19 [ V_22 ] . V_82 ;
V_113 = F_79 ( V_12 , sizeof( * V_113 ) ) ;
V_44 = F_79 ( V_114 , sizeof( * V_44 ) ) ;
if ( V_44 == NULL || V_113 == NULL ) {
F_80 ( V_44 ) ;
F_80 ( V_113 ) ;
F_81 ( & V_52 -> V_115 ) ;
return - V_116 ;
}
V_114 = 0 ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
struct V_43 T_4 * V_78 ;
T_5 V_117 = ( T_5 ) - 1 ;
int V_118 ;
V_78 = F_46 ( V_19 [ V_22 ] . V_81 ) ;
if ( F_82 ( V_44 + V_114 , V_78 ,
V_19 [ V_22 ] . V_82 * sizeof( * V_44 ) ) ) {
V_48 = - V_76 ;
F_81 ( & V_52 -> V_115 ) ;
goto V_111;
}
for ( V_118 = 0 ; V_118 < V_19 [ V_22 ] . V_82 ; V_118 ++ ) {
if ( F_83 ( & V_78 [ V_118 ] . V_74 ,
& V_117 ,
sizeof( V_117 ) ) ) {
V_48 = - V_76 ;
F_81 ( & V_52 -> V_115 ) ;
goto V_111;
}
}
V_113 [ V_22 ] = V_114 ;
V_114 += V_19 [ V_22 ] . V_82 ;
}
V_48 = F_84 ( V_52 ) ;
if ( V_48 ) {
F_81 ( & V_52 -> V_115 ) ;
goto V_111;
}
F_6 ( V_3 ) ;
V_48 = F_7 ( V_3 , V_19 , args , V_21 ) ;
if ( V_48 )
goto V_111;
V_106 = ( args -> V_4 & V_119 ) == 0 ;
V_48 = F_67 ( V_86 , & V_3 -> V_16 , V_62 , & V_106 ) ;
if ( V_48 )
goto V_111;
F_53 (obj, &eb->objects, exec_list) {
int V_46 = V_24 -> V_31 - V_19 ;
V_48 = F_50 ( V_24 , V_3 ,
V_44 + V_113 [ V_46 ] ,
V_62 ) ;
if ( V_48 )
goto V_111;
}
V_111:
F_80 ( V_44 ) ;
F_80 ( V_113 ) ;
return V_48 ;
}
static int
F_85 ( struct V_85 * V_86 ,
struct V_105 * V_16 )
{
struct V_8 * V_24 ;
T_1 V_120 = 0 ;
bool V_121 = false ;
int V_48 ;
F_53 (obj, objects, exec_list) {
V_48 = F_86 ( V_24 , V_86 ) ;
if ( V_48 )
return V_48 ;
if ( V_24 -> V_30 . V_38 & V_39 )
V_121 |= F_87 ( V_24 , false ) ;
V_120 |= V_24 -> V_30 . V_38 ;
}
if ( V_121 )
F_88 ( V_86 -> V_52 ) ;
if ( V_120 & V_122 )
F_89 () ;
return F_90 ( V_86 ) ;
}
static bool
F_91 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_123 )
return false ;
return ( ( V_19 -> V_124 | V_19 -> V_125 ) & 0x7 ) == 0 ;
}
static int
F_92 ( struct V_18 * V_19 ,
int V_12 )
{
int V_22 ;
int V_126 = 0 ;
int V_127 = V_128 / sizeof( struct V_43 ) ;
for ( V_22 = 0 ; V_22 < V_12 ; V_22 ++ ) {
char T_4 * V_129 = F_46 ( V_19 [ V_22 ] . V_81 ) ;
int V_130 ;
if ( V_19 [ V_22 ] . V_4 & V_131 )
return - V_29 ;
if ( V_19 [ V_22 ] . V_82 > V_127 - V_126 )
return - V_29 ;
V_126 += V_19 [ V_22 ] . V_82 ;
V_130 = V_19 [ V_22 ] . V_82 *
sizeof( struct V_43 ) ;
if ( ! F_93 ( V_132 , V_129 , V_130 ) )
return - V_76 ;
if ( F_94 ( ! V_133 ) ) {
if ( F_95 ( V_129 , V_130 ) )
return - V_76 ;
}
}
return 0 ;
}
static void
F_96 ( struct V_105 * V_16 ,
struct V_61 * V_62 ,
struct V_85 * V_86 )
{
struct V_8 * V_24 ;
F_53 (obj, objects, exec_list) {
T_6 V_134 = V_24 -> V_30 . V_70 ;
T_6 V_135 = V_24 -> V_30 . V_38 ;
V_24 -> V_30 . V_38 = V_24 -> V_30 . V_73 ;
if ( V_24 -> V_30 . V_38 == 0 )
V_24 -> V_30 . V_72 |= V_24 -> V_30 . V_70 ;
V_24 -> V_30 . V_70 = V_24 -> V_30 . V_72 ;
V_24 -> V_136 = V_24 -> V_98 ;
F_69 ( & F_75 ( V_24 , V_62 ) -> V_137 , & V_62 -> V_138 ) ;
F_97 ( V_24 , V_86 ) ;
if ( V_24 -> V_30 . V_38 ) {
V_24 -> V_139 = 1 ;
V_24 -> V_140 = F_98 ( V_86 ) ;
if ( V_24 -> V_141 )
F_99 ( V_24 , V_86 ) ;
}
F_100 ( V_24 , V_134 , V_135 ) ;
}
}
static void
F_101 ( struct V_51 * V_52 ,
struct V_20 * V_21 ,
struct V_85 * V_86 ,
struct V_8 * V_24 )
{
V_86 -> V_142 = true ;
( void ) F_102 ( V_86 , V_21 , V_24 , NULL ) ;
}
static int
F_103 ( struct V_51 * V_52 ,
struct V_85 * V_86 )
{
T_7 * V_54 = V_52 -> V_55 ;
int V_48 , V_22 ;
if ( ! F_104 ( V_52 ) || V_86 != & V_54 -> V_86 [ V_143 ] )
return 0 ;
V_48 = F_105 ( V_86 , 4 * 3 ) ;
if ( V_48 )
return V_48 ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
F_106 ( V_86 , F_107 ( 1 ) ) ;
F_106 ( V_86 , F_108 ( V_22 ) ) ;
F_106 ( V_86 , 0 ) ;
}
F_109 ( V_86 ) ;
return 0 ;
}
static int
F_110 ( struct V_51 * V_52 , void * V_144 ,
struct V_20 * V_21 ,
struct V_2 * args ,
struct V_18 * V_19 ,
struct V_61 * V_62 )
{
T_7 * V_54 = V_52 -> V_55 ;
struct V_1 * V_3 ;
struct V_8 * V_145 ;
struct V_146 * V_147 = NULL ;
struct V_85 * V_86 ;
T_6 V_148 = F_111 ( * args ) ;
T_6 V_149 , V_150 ;
T_6 V_151 , V_4 ;
int V_48 , V_152 , V_22 ;
bool V_106 ;
if ( ! F_91 ( args ) )
return - V_29 ;
V_48 = F_92 ( V_19 , args -> V_7 ) ;
if ( V_48 )
return V_48 ;
V_4 = 0 ;
if ( args -> V_4 & V_153 ) {
if ( ! V_21 -> V_154 || ! F_112 ( V_155 ) )
return - V_156 ;
V_4 |= V_157 ;
}
if ( args -> V_4 & V_158 )
V_4 |= V_159 ;
switch ( args -> V_4 & V_160 ) {
case V_161 :
case V_162 :
V_86 = & V_54 -> V_86 [ V_143 ] ;
break;
case V_163 :
V_86 = & V_54 -> V_86 [ V_164 ] ;
if ( V_148 != V_165 ) {
F_12 ( L_11 ,
V_86 -> V_166 ) ;
return - V_156 ;
}
break;
case V_167 :
V_86 = & V_54 -> V_86 [ V_168 ] ;
if ( V_148 != V_165 ) {
F_12 ( L_11 ,
V_86 -> V_166 ) ;
return - V_156 ;
}
break;
case V_169 :
V_86 = & V_54 -> V_86 [ V_170 ] ;
if ( V_148 != V_165 ) {
F_12 ( L_11 ,
V_86 -> V_166 ) ;
return - V_156 ;
}
break;
default:
F_12 ( L_12 ,
( int ) ( args -> V_4 & V_160 ) ) ;
return - V_29 ;
}
if ( ! F_113 ( V_86 ) ) {
F_12 ( L_13 ,
( int ) ( args -> V_4 & V_160 ) ) ;
return - V_29 ;
}
V_152 = args -> V_4 & V_171 ;
V_151 = V_171 ;
switch ( V_152 ) {
case V_172 :
case V_173 :
case V_174 :
if ( V_86 == & V_54 -> V_86 [ V_143 ] &&
V_152 != V_54 -> V_175 ) {
if ( F_57 ( V_52 ) -> V_89 < 4 )
return - V_29 ;
if ( F_57 ( V_52 ) -> V_89 > 5 &&
V_152 == V_174 )
return - V_29 ;
if ( F_57 ( V_52 ) -> V_89 >= 6 )
V_151 &= ~ V_174 ;
}
break;
default:
F_12 ( L_14 , V_152 ) ;
return - V_29 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_15 , args -> V_7 ) ;
return - V_29 ;
}
if ( args -> V_176 != 0 ) {
if ( V_86 != & V_54 -> V_86 [ V_143 ] ) {
F_12 ( L_16 ) ;
return - V_29 ;
}
if ( F_57 ( V_52 ) -> V_89 >= 5 ) {
F_12 ( L_17 ) ;
return - V_29 ;
}
if ( args -> V_176 > V_177 / sizeof( * V_147 ) ) {
F_12 ( L_18 ,
args -> V_176 ) ;
return - V_29 ;
}
V_147 = F_2 ( args -> V_176 * sizeof( * V_147 ) ,
V_178 ) ;
if ( V_147 == NULL ) {
V_48 = - V_116 ;
goto V_179;
}
if ( F_82 ( V_147 ,
F_46 ( args -> V_180 ) ,
sizeof( * V_147 ) * args -> V_176 ) ) {
V_48 = - V_76 ;
goto V_179;
}
}
V_48 = F_84 ( V_52 ) ;
if ( V_48 )
goto V_179;
if ( V_54 -> V_181 . V_182 ) {
F_78 ( & V_52 -> V_115 ) ;
V_48 = - V_183 ;
goto V_179;
}
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_78 ( & V_52 -> V_115 ) ;
V_48 = - V_116 ;
goto V_179;
}
V_48 = F_7 ( V_3 , V_19 , args , V_21 ) ;
if ( V_48 )
goto V_111;
V_145 = F_114 ( V_3 -> V_16 . V_184 ,
struct V_8 ,
V_28 ) ;
V_106 = ( args -> V_4 & V_119 ) == 0 ;
V_48 = F_67 ( V_86 , & V_3 -> V_16 , V_62 , & V_106 ) ;
if ( V_48 )
goto V_111;
if ( V_106 )
V_48 = F_51 ( V_3 , V_62 ) ;
if ( V_48 ) {
if ( V_48 == - V_76 ) {
V_48 = F_77 ( V_52 , args , V_21 , V_86 ,
V_3 , V_19 , V_62 ) ;
F_115 ( ! F_116 ( & V_52 -> V_115 ) ) ;
}
if ( V_48 )
goto V_111;
}
if ( V_145 -> V_30 . V_73 ) {
F_12 ( L_19 ) ;
V_48 = - V_29 ;
goto V_111;
}
V_145 -> V_30 . V_72 |= V_109 ;
if ( V_4 & V_157 && ! V_145 -> V_69 )
F_42 ( V_145 , V_145 -> V_41 ) ;
V_48 = F_85 ( V_86 , & V_3 -> V_16 ) ;
if ( V_48 )
goto V_111;
V_48 = F_117 ( V_86 , V_21 , V_148 ) ;
if ( V_48 )
goto V_111;
if ( V_86 == & V_54 -> V_86 [ V_143 ] &&
V_152 != V_54 -> V_175 ) {
V_48 = F_105 ( V_86 , 4 ) ;
if ( V_48 )
goto V_111;
F_106 ( V_86 , V_185 ) ;
F_106 ( V_86 , F_107 ( 1 ) ) ;
F_106 ( V_86 , V_186 ) ;
F_106 ( V_86 , V_151 << 16 | V_152 ) ;
F_109 ( V_86 ) ;
V_54 -> V_175 = V_152 ;
}
if ( args -> V_4 & V_187 ) {
V_48 = F_103 ( V_52 , V_86 ) ;
if ( V_48 )
goto V_111;
}
V_149 = F_62 ( V_145 , V_62 ) +
args -> V_124 ;
V_150 = args -> V_125 ;
if ( V_147 ) {
for ( V_22 = 0 ; V_22 < args -> V_176 ; V_22 ++ ) {
V_48 = F_118 ( V_52 , & V_147 [ V_22 ] ,
args -> V_188 , args -> V_189 ) ;
if ( V_48 )
goto V_111;
V_48 = V_86 -> V_190 ( V_86 ,
V_149 , V_150 ,
V_4 ) ;
if ( V_48 )
goto V_111;
}
} else {
V_48 = V_86 -> V_190 ( V_86 ,
V_149 , V_150 ,
V_4 ) ;
if ( V_48 )
goto V_111;
}
F_119 ( V_86 , F_98 ( V_86 ) , V_4 ) ;
F_96 ( & V_3 -> V_16 , V_62 , V_86 ) ;
F_101 ( V_52 , V_21 , V_86 , V_145 ) ;
V_111:
F_20 ( V_3 ) ;
F_78 ( & V_52 -> V_115 ) ;
V_179:
F_24 ( V_147 ) ;
return V_48 ;
}
int
F_120 ( struct V_51 * V_52 , void * V_144 ,
struct V_20 * V_21 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_191 * args = V_144 ;
struct V_2 V_192 ;
struct V_193 * V_28 = NULL ;
struct V_18 * V_194 = NULL ;
int V_48 , V_22 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_15 , args -> V_7 ) ;
return - V_29 ;
}
V_28 = F_79 ( sizeof( * V_28 ) , args -> V_7 ) ;
V_194 = F_79 ( sizeof( * V_194 ) , args -> V_7 ) ;
if ( V_28 == NULL || V_194 == NULL ) {
F_12 ( L_20 ,
args -> V_7 ) ;
F_80 ( V_28 ) ;
F_80 ( V_194 ) ;
return - V_116 ;
}
V_48 = F_82 ( V_28 ,
F_46 ( args -> V_195 ) ,
sizeof( * V_28 ) * args -> V_7 ) ;
if ( V_48 != 0 ) {
F_12 ( L_21 ,
args -> V_7 , V_48 ) ;
F_80 ( V_28 ) ;
F_80 ( V_194 ) ;
return - V_76 ;
}
for ( V_22 = 0 ; V_22 < args -> V_7 ; V_22 ++ ) {
V_194 [ V_22 ] . V_26 = V_28 [ V_22 ] . V_26 ;
V_194 [ V_22 ] . V_82 = V_28 [ V_22 ] . V_82 ;
V_194 [ V_22 ] . V_81 = V_28 [ V_22 ] . V_81 ;
V_194 [ V_22 ] . V_95 = V_28 [ V_22 ] . V_95 ;
V_194 [ V_22 ] . V_46 = V_28 [ V_22 ] . V_46 ;
if ( F_57 ( V_52 ) -> V_89 < 4 )
V_194 [ V_22 ] . V_4 = V_92 ;
else
V_194 [ V_22 ] . V_4 = 0 ;
}
V_192 . V_195 = args -> V_195 ;
V_192 . V_7 = args -> V_7 ;
V_192 . V_124 = args -> V_124 ;
V_192 . V_125 = args -> V_125 ;
V_192 . V_188 = args -> V_188 ;
V_192 . V_189 = args -> V_189 ;
V_192 . V_176 = args -> V_176 ;
V_192 . V_180 = args -> V_180 ;
V_192 . V_4 = V_162 ;
F_121 ( V_192 , 0 ) ;
V_48 = F_110 ( V_52 , V_144 , V_21 , & V_192 , V_194 ,
& V_54 -> V_58 . V_30 ) ;
if ( ! V_48 ) {
for ( V_22 = 0 ; V_22 < args -> V_7 ; V_22 ++ )
V_28 [ V_22 ] . V_46 = V_194 [ V_22 ] . V_46 ;
V_48 = F_83 ( F_46 ( args -> V_195 ) ,
V_28 ,
sizeof( * V_28 ) * args -> V_7 ) ;
if ( V_48 ) {
V_48 = - V_76 ;
F_12 ( L_22
L_23 ,
args -> V_7 , V_48 ) ;
}
}
F_80 ( V_28 ) ;
F_80 ( V_194 ) ;
return V_48 ;
}
int
F_122 ( struct V_51 * V_52 , void * V_144 ,
struct V_20 * V_21 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_2 * args = V_144 ;
struct V_18 * V_194 = NULL ;
int V_48 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_177 / sizeof( * V_194 ) ) {
F_12 ( L_24 , args -> V_7 ) ;
return - V_29 ;
}
V_194 = F_2 ( sizeof( * V_194 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_194 == NULL )
V_194 = F_79 ( sizeof( * V_194 ) ,
args -> V_7 ) ;
if ( V_194 == NULL ) {
F_12 ( L_20 ,
args -> V_7 ) ;
return - V_116 ;
}
V_48 = F_82 ( V_194 ,
F_46 ( args -> V_195 ) ,
sizeof( * V_194 ) * args -> V_7 ) ;
if ( V_48 != 0 ) {
F_12 ( L_21 ,
args -> V_7 , V_48 ) ;
F_80 ( V_194 ) ;
return - V_76 ;
}
V_48 = F_110 ( V_52 , V_144 , V_21 , args , V_194 ,
& V_54 -> V_58 . V_30 ) ;
if ( ! V_48 ) {
V_48 = F_83 ( F_46 ( args -> V_195 ) ,
V_194 ,
sizeof( * V_194 ) * args -> V_7 ) ;
if ( V_48 ) {
V_48 = - V_76 ;
F_12 ( L_22
L_23 ,
args -> V_7 , V_48 ) ;
}
}
F_80 ( V_194 ) ;
return V_48 ;
}
