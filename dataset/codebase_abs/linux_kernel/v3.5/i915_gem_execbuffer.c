static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 = 0 , V_8 = 0 ;
if ( V_2 -> V_9 . V_10 == 0 )
V_2 -> V_9 . V_11 |= V_2 -> V_9 . V_12 ;
if ( V_2 -> V_9 . V_13 &&
( ( ( V_2 -> V_9 . V_13 != V_2 -> V_9 . V_11 ||
V_2 -> V_4 != V_4 ) ) ||
( V_2 -> V_14 && ! V_2 -> V_15 ) ) ) {
V_8 |= V_2 -> V_9 . V_13 ;
V_7 |=
V_2 -> V_9 . V_11 & ~ V_2 -> V_9 . V_13 ;
}
V_7 |= V_2 -> V_9 . V_11 & ~ V_2 -> V_9 . V_12 ;
if ( ( V_8 | V_7 ) & V_16 )
F_2 ( V_2 ) ;
if ( V_2 -> V_9 . V_10 )
V_6 -> V_17 |= F_3 ( & V_2 -> V_18 ) ;
if ( V_8 == 0 && V_2 -> V_9 . V_10 == 0 )
V_2 -> V_9 . V_10 = V_2 -> V_9 . V_13 ;
V_6 -> V_7 |= V_7 ;
V_6 -> V_8 |= V_8 ;
if ( V_8 & V_19 )
V_6 -> V_20 |= F_4 ( V_2 -> V_4 ) ;
if ( V_7 & V_19 )
V_6 -> V_20 |= F_4 ( V_4 ) ;
}
static struct V_21 *
F_5 ( int V_22 )
{
struct V_21 * V_23 ;
int V_24 = V_25 / sizeof( struct V_26 ) / 2 ;
while ( V_24 > V_22 )
V_24 >>= 1 ;
V_23 = F_6 ( V_24 * sizeof( struct V_26 ) +
sizeof( struct V_21 ) ,
V_27 ) ;
if ( V_23 == NULL )
return V_23 ;
V_23 -> V_28 = V_24 - 1 ;
return V_23 ;
}
static void
F_7 ( struct V_21 * V_23 )
{
memset ( V_23 -> V_29 , 0 , ( V_23 -> V_28 + 1 ) * sizeof( struct V_26 ) ) ;
}
static void
F_8 ( struct V_21 * V_23 , struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_30 ,
& V_23 -> V_29 [ V_2 -> V_31 & V_23 -> V_28 ] ) ;
}
static struct V_1 *
F_10 ( struct V_21 * V_23 , unsigned long V_32 )
{
struct V_26 * V_33 ;
struct V_34 * V_35 ;
struct V_1 * V_2 ;
V_33 = & V_23 -> V_29 [ V_32 & V_23 -> V_28 ] ;
F_11 (node, head) {
V_2 = F_12 ( V_35 , struct V_1 , V_30 ) ;
if ( V_2 -> V_31 == V_32 )
return V_2 ;
}
return NULL ;
}
static void
F_13 ( struct V_21 * V_23 )
{
F_14 ( V_23 ) ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
return ( V_2 -> V_9 . V_13 == V_16 ||
V_2 -> V_36 != V_37 ) ;
}
static int
F_16 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = V_2 -> V_9 . V_41 ;
struct V_42 * V_43 ;
struct V_1 * V_44 ;
T_1 V_45 ;
int V_46 = - V_47 ;
V_43 = & F_10 ( V_23 , V_39 -> V_48 ) -> V_9 ;
if ( F_17 ( V_43 == NULL ) )
return - V_49 ;
V_44 = F_18 ( V_43 ) ;
V_45 = V_44 -> V_50 ;
if ( F_17 ( V_45 == 0 ) ) {
F_19 ( L_1 ,
V_39 -> V_48 ) ;
return V_46 ;
}
if ( F_17 ( V_39 -> V_13 & ( V_39 -> V_13 - 1 ) ) ) {
F_19 ( L_2
L_3
L_4 ,
V_2 , V_39 -> V_48 ,
( int ) V_39 -> V_51 ,
V_39 -> V_12 ,
V_39 -> V_13 ) ;
return V_46 ;
}
if ( F_17 ( ( V_39 -> V_13 | V_39 -> V_12 )
& ~ V_19 ) ) {
F_19 ( L_5
L_3
L_4 ,
V_2 , V_39 -> V_48 ,
( int ) V_39 -> V_51 ,
V_39 -> V_12 ,
V_39 -> V_13 ) ;
return V_46 ;
}
if ( F_17 ( V_39 -> V_13 && V_43 -> V_10 &&
V_39 -> V_13 != V_43 -> V_10 ) ) {
F_19 ( L_6
L_3
L_7 ,
V_2 , V_39 -> V_48 ,
( int ) V_39 -> V_51 ,
V_39 -> V_13 ,
V_43 -> V_10 ) ;
return V_46 ;
}
V_43 -> V_11 |= V_39 -> V_12 ;
V_43 -> V_10 |= V_39 -> V_13 ;
if ( V_45 == V_39 -> V_52 )
return 0 ;
if ( F_17 ( V_39 -> V_51 > V_2 -> V_9 . V_22 - 4 ) ) {
F_19 ( L_8
L_9 ,
V_2 , V_39 -> V_48 ,
( int ) V_39 -> V_51 ,
( int ) V_2 -> V_9 . V_22 ) ;
return V_46 ;
}
if ( F_17 ( V_39 -> V_51 & 3 ) ) {
F_19 ( L_10
L_11 ,
V_2 , V_39 -> V_48 ,
( int ) V_39 -> V_51 ) ;
return V_46 ;
}
if ( V_2 -> V_53 && F_20 () )
return - V_54 ;
V_39 -> V_55 += V_45 ;
if ( F_15 ( V_2 ) ) {
T_1 V_56 = V_39 -> V_51 & ~ V_57 ;
char * V_58 ;
V_46 = F_21 ( V_2 , 1 ) ;
if ( V_46 )
return V_46 ;
V_58 = F_22 ( V_2 -> V_59 [ V_39 -> V_51 >> V_60 ] ) ;
* ( T_1 * ) ( V_58 + V_56 ) = V_39 -> V_55 ;
F_23 ( V_58 ) ;
} else {
struct V_61 * V_62 = V_41 -> V_63 ;
T_1 T_2 * V_64 ;
void T_2 * V_65 ;
V_46 = F_24 ( V_2 , true ) ;
if ( V_46 )
return V_46 ;
V_46 = F_25 ( V_2 ) ;
if ( V_46 )
return V_46 ;
V_39 -> V_51 += V_2 -> V_50 ;
V_65 = F_26 ( V_62 -> V_66 . V_67 ,
V_39 -> V_51 & V_57 ) ;
V_64 = ( T_1 T_2 * )
( V_65 + ( V_39 -> V_51 & ~ V_57 ) ) ;
F_27 ( V_39 -> V_55 , V_64 ) ;
F_28 ( V_65 ) ;
}
if ( F_17 ( F_29 ( V_41 ) &&
V_39 -> V_13 == V_68 &&
! V_44 -> V_69 ) ) {
F_30 ( V_44 ,
V_44 -> V_36 ) ;
}
V_39 -> V_52 = V_45 ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_21 * V_23 )
{
#define F_32 ( T_3 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_38 V_70 [ F_32 ( 512 ) ] ;
struct V_38 T_4 * V_71 ;
struct V_72 * V_73 = V_2 -> V_74 ;
int V_75 , V_46 ;
V_71 = ( void T_4 * ) ( V_76 ) V_73 -> V_77 ;
V_75 = V_73 -> V_78 ;
while ( V_75 ) {
struct V_38 * V_79 = V_70 ;
int V_24 = V_75 ;
if ( V_24 > F_33 ( V_70 ) )
V_24 = F_33 ( V_70 ) ;
V_75 -= V_24 ;
if ( F_34 ( V_79 , V_71 , V_24 * sizeof( V_79 [ 0 ] ) ) )
return - V_54 ;
do {
T_5 V_51 = V_79 -> V_52 ;
V_46 = F_16 ( V_2 , V_23 , V_79 ) ;
if ( V_46 )
return V_46 ;
if ( V_79 -> V_52 != V_51 &&
F_35 ( & V_71 -> V_52 ,
& V_79 -> V_52 ,
sizeof( V_79 -> V_52 ) ) ) {
return - V_54 ;
}
V_71 ++ ;
V_79 ++ ;
} while ( -- V_24 );
}
return 0 ;
#undef F_32
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_21 * V_23 ,
struct V_38 * V_80 )
{
const struct V_72 * V_73 = V_2 -> V_74 ;
int V_81 , V_46 ;
for ( V_81 = 0 ; V_81 < V_73 -> V_78 ; V_81 ++ ) {
V_46 = F_16 ( V_2 , V_23 , & V_80 [ V_81 ] ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static int
F_37 ( struct V_40 * V_41 ,
struct V_21 * V_23 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 ;
int V_46 = 0 ;
F_38 () ;
F_39 (obj, objects, exec_list) {
V_46 = F_31 ( V_2 , V_23 ) ;
if ( V_46 )
break;
}
F_40 () ;
return V_46 ;
}
static int
F_41 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = V_2 -> V_74 ;
return V_73 -> V_78 && ! F_15 ( V_2 ) ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_72 * V_73 = V_2 -> V_74 ;
bool V_84 = F_43 ( V_4 -> V_41 ) -> V_85 < 4 ;
bool V_86 , V_87 ;
int V_46 ;
V_86 =
V_84 &&
V_73 -> V_88 & V_89 &&
V_2 -> V_90 != V_91 ;
V_87 = V_86 || F_41 ( V_2 ) ;
V_46 = F_44 ( V_2 , V_73 -> V_92 , V_87 ) ;
if ( V_46 )
return V_46 ;
if ( V_84 ) {
if ( V_73 -> V_88 & V_89 ) {
V_46 = F_45 ( V_2 ) ;
if ( V_46 )
goto V_93;
if ( F_46 ( V_2 ) )
V_73 -> V_88 |= V_94 ;
V_2 -> V_15 = true ;
}
}
V_73 -> V_51 = V_2 -> V_50 ;
return 0 ;
V_93:
F_47 ( V_2 ) ;
return V_46 ;
}
static int
F_48 ( struct V_3 * V_4 ,
struct V_95 * V_96 ,
struct V_82 * V_83 )
{
T_6 * V_62 = V_4 -> V_41 -> V_63 ;
struct V_1 * V_2 ;
int V_46 , V_97 ;
bool V_84 = F_43 ( V_4 -> V_41 ) -> V_85 < 4 ;
struct V_82 V_98 ;
F_49 ( & V_98 ) ;
while ( ! F_50 ( V_83 ) ) {
struct V_72 * V_73 ;
bool V_86 , V_87 ;
V_2 = F_51 ( V_83 ,
struct V_1 ,
V_99 ) ;
V_73 = V_2 -> V_74 ;
V_86 =
V_84 &&
V_73 -> V_88 & V_89 &&
V_2 -> V_90 != V_91 ;
V_87 = V_86 || F_41 ( V_2 ) ;
if ( V_87 )
F_52 ( & V_2 -> V_99 , & V_98 ) ;
else
F_53 ( & V_2 -> V_99 , & V_98 ) ;
V_2 -> V_9 . V_11 = 0 ;
V_2 -> V_9 . V_10 = 0 ;
}
F_54 ( & V_98 , V_83 ) ;
V_97 = 0 ;
do {
V_46 = 0 ;
F_39 (obj, objects, exec_list) {
struct V_72 * V_73 = V_2 -> V_74 ;
bool V_86 , V_87 ;
if ( ! V_2 -> V_100 )
continue;
V_86 =
V_84 &&
V_73 -> V_88 & V_89 &&
V_2 -> V_90 != V_91 ;
V_87 = V_86 || F_41 ( V_2 ) ;
if ( ( V_73 -> V_92 && V_2 -> V_50 & ( V_73 -> V_92 - 1 ) ) ||
( V_87 && ! V_2 -> V_101 ) )
V_46 = F_55 ( V_2 ) ;
else
V_46 = F_42 ( V_2 , V_4 ) ;
if ( V_46 )
goto V_102;
}
F_39 (obj, objects, exec_list) {
if ( V_2 -> V_100 )
continue;
V_46 = F_42 ( V_2 , V_4 ) ;
if ( V_46 ) {
int V_103 ;
V_103 = F_55 ( V_2 ) ;
( void ) V_103 ;
F_56 ( V_2 -> V_100 ) ;
break;
}
}
F_39 (obj, objects, exec_list) {
struct V_72 * V_73 ;
if ( ! V_2 -> V_100 )
continue;
V_73 = V_2 -> V_74 ;
if ( V_73 -> V_88 & V_94 ) {
F_57 ( V_2 ) ;
V_73 -> V_88 &= ~ V_94 ;
}
F_47 ( V_2 ) ;
if ( V_62 -> V_66 . V_104 && ! V_2 -> V_105 ) {
F_58 ( V_62 -> V_66 . V_104 ,
V_2 , V_2 -> V_36 ) ;
V_2 -> V_105 = 1 ;
}
}
if ( V_46 != - V_106 || V_97 > 1 )
return V_46 ;
V_46 = F_59 ( V_4 -> V_41 , V_97 == 0 ) ;
if ( V_46 )
return V_46 ;
V_97 ++ ;
} while ( 1 );
V_102:
F_60 (obj, objects, exec_list) {
struct V_72 * V_73 ;
if ( ! V_2 -> V_100 )
continue;
V_73 = V_2 -> V_74 ;
if ( V_73 -> V_88 & V_94 ) {
F_57 ( V_2 ) ;
V_73 -> V_88 &= ~ V_94 ;
}
F_47 ( V_2 ) ;
}
return V_46 ;
}
static int
F_61 ( struct V_40 * V_41 ,
struct V_95 * V_96 ,
struct V_3 * V_4 ,
struct V_82 * V_83 ,
struct V_21 * V_23 ,
struct V_72 * V_107 ,
int V_24 )
{
struct V_38 * V_39 ;
struct V_1 * V_2 ;
int * V_108 ;
int V_81 , V_109 , V_46 ;
while ( ! F_50 ( V_83 ) ) {
V_2 = F_51 ( V_83 ,
struct V_1 ,
V_99 ) ;
F_62 ( & V_2 -> V_99 ) ;
F_63 ( & V_2 -> V_9 ) ;
}
F_64 ( & V_41 -> V_110 ) ;
V_109 = 0 ;
for ( V_81 = 0 ; V_81 < V_24 ; V_81 ++ )
V_109 += V_107 [ V_81 ] . V_78 ;
V_108 = F_65 ( V_24 , sizeof( * V_108 ) ) ;
V_39 = F_65 ( V_109 , sizeof( * V_39 ) ) ;
if ( V_39 == NULL || V_108 == NULL ) {
F_66 ( V_39 ) ;
F_66 ( V_108 ) ;
F_67 ( & V_41 -> V_110 ) ;
return - V_111 ;
}
V_109 = 0 ;
for ( V_81 = 0 ; V_81 < V_24 ; V_81 ++ ) {
struct V_38 T_4 * V_71 ;
V_71 = ( void T_4 * ) ( V_76 ) V_107 [ V_81 ] . V_77 ;
if ( F_68 ( V_39 + V_109 , V_71 ,
V_107 [ V_81 ] . V_78 * sizeof( * V_39 ) ) ) {
V_46 = - V_54 ;
F_67 ( & V_41 -> V_110 ) ;
goto V_102;
}
V_108 [ V_81 ] = V_109 ;
V_109 += V_107 [ V_81 ] . V_78 ;
}
V_46 = F_69 ( V_41 ) ;
if ( V_46 ) {
F_67 ( & V_41 -> V_110 ) ;
goto V_102;
}
F_7 ( V_23 ) ;
for ( V_81 = 0 ; V_81 < V_24 ; V_81 ++ ) {
V_2 = F_18 ( F_70 ( V_41 , V_96 ,
V_107 [ V_81 ] . V_32 ) ) ;
if ( & V_2 -> V_9 == NULL ) {
F_19 ( L_12 ,
V_107 [ V_81 ] . V_32 , V_81 ) ;
V_46 = - V_49 ;
goto V_102;
}
F_71 ( & V_2 -> V_99 , V_83 ) ;
V_2 -> V_31 = V_107 [ V_81 ] . V_32 ;
V_2 -> V_74 = & V_107 [ V_81 ] ;
F_8 ( V_23 , V_2 ) ;
}
V_46 = F_48 ( V_4 , V_96 , V_83 ) ;
if ( V_46 )
goto V_102;
F_39 (obj, objects, exec_list) {
int V_51 = V_2 -> V_74 - V_107 ;
V_46 = F_36 ( V_2 , V_23 ,
V_39 + V_108 [ V_51 ] ) ;
if ( V_46 )
goto V_102;
}
V_102:
F_66 ( V_39 ) ;
F_66 ( V_108 ) ;
return V_46 ;
}
static int
F_72 ( struct V_40 * V_41 ,
T_1 V_7 ,
T_1 V_8 ,
T_1 V_20 )
{
T_6 * V_62 = V_41 -> V_63 ;
int V_81 , V_46 ;
if ( V_8 & V_16 )
F_73 () ;
if ( V_8 & V_112 )
F_74 () ;
if ( ( V_8 | V_7 ) & V_19 ) {
for ( V_81 = 0 ; V_81 < V_113 ; V_81 ++ )
if ( V_20 & ( 1 << V_81 ) ) {
V_46 = F_75 ( & V_62 -> V_4 [ V_81 ] ,
V_7 ,
V_8 ) ;
if ( V_46 )
return V_46 ;
}
}
return 0 ;
}
static int
F_76 ( struct V_3 * V_4 , T_7 V_17 )
{
T_7 V_114 , V_115 ;
int V_46 ;
for ( V_114 = 0 ; V_17 >> V_114 ; V_114 ++ ) {
if ( ( ( V_17 >> V_114 ) & 1 ) == 0 )
continue;
if ( V_114 )
V_115 = V_116 ;
else
V_115 = V_117 ;
V_46 = F_77 ( V_4 , 2 ) ;
if ( V_46 )
return V_46 ;
F_78 ( V_4 , V_118 | V_115 ) ;
F_78 ( V_4 , V_119 ) ;
F_79 ( V_4 ) ;
}
return 0 ;
}
static int
F_80 ( struct V_3 * V_4 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 ;
struct V_5 V_6 ;
int V_46 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_39 (obj, objects, exec_list)
F_1 ( V_2 , V_4 , & V_6 ) ;
if ( V_6 . V_7 | V_6 . V_8 ) {
V_46 = F_72 ( V_4 -> V_41 ,
V_6 . V_7 ,
V_6 . V_8 ,
V_6 . V_20 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_6 . V_17 ) {
V_46 = F_76 ( V_4 , V_6 . V_17 ) ;
if ( V_46 )
return V_46 ;
}
F_39 (obj, objects, exec_list) {
V_46 = F_81 ( V_2 , V_4 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static bool
F_82 ( struct V_120 * V_107 )
{
return ( ( V_107 -> V_121 | V_107 -> V_122 ) & 0x7 ) == 0 ;
}
static int
F_83 ( struct V_72 * V_107 ,
int V_24 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_24 ; V_81 ++ ) {
char T_4 * V_123 = ( char T_4 * ) ( V_76 ) V_107 [ V_81 ] . V_77 ;
int V_124 ;
if ( V_107 [ V_81 ] . V_78 >
V_125 / sizeof( struct V_38 ) )
return - V_47 ;
V_124 = V_107 [ V_81 ] . V_78 *
sizeof( struct V_38 ) ;
if ( ! F_84 ( V_126 , V_123 , V_124 ) )
return - V_54 ;
if ( ! F_84 ( V_127 , V_123 , V_124 ) )
return - V_54 ;
if ( F_85 ( V_123 , V_124 ) )
return - V_54 ;
}
return 0 ;
}
static void
F_86 ( struct V_82 * V_83 ,
struct V_3 * V_4 ,
T_7 V_128 )
{
struct V_1 * V_2 ;
F_39 (obj, objects, exec_list) {
T_7 V_129 = V_2 -> V_9 . V_12 ;
T_7 V_130 = V_2 -> V_9 . V_13 ;
V_2 -> V_9 . V_12 = V_2 -> V_9 . V_11 ;
V_2 -> V_9 . V_13 = V_2 -> V_9 . V_10 ;
V_2 -> V_14 = V_2 -> V_15 ;
F_87 ( V_2 , V_4 , V_128 ) ;
if ( V_2 -> V_9 . V_13 ) {
V_2 -> V_131 = 1 ;
V_2 -> V_132 = true ;
F_53 ( & V_2 -> V_133 ,
& V_4 -> V_133 ) ;
if ( V_2 -> V_134 )
F_88 ( V_4 -> V_41 , V_2 ) ;
}
F_89 ( V_2 , V_129 , V_130 ) ;
}
F_88 ( V_4 -> V_41 , NULL ) ;
}
static void
F_90 ( struct V_40 * V_41 ,
struct V_95 * V_96 ,
struct V_3 * V_4 )
{
struct V_135 * V_136 ;
T_7 V_137 ;
V_137 = V_138 ;
if ( F_43 ( V_41 ) -> V_85 >= 4 )
V_137 |= V_139 ;
if ( V_4 -> V_140 ( V_4 , V_137 , 0 ) ) {
F_91 ( V_4 ) ;
return;
}
V_136 = F_6 ( sizeof( * V_136 ) , V_27 ) ;
if ( V_136 == NULL || F_92 ( V_4 , V_96 , V_136 ) ) {
F_91 ( V_4 ) ;
F_14 ( V_136 ) ;
}
}
static int
F_93 ( struct V_40 * V_41 ,
struct V_3 * V_4 )
{
T_6 * V_62 = V_41 -> V_63 ;
int V_46 , V_81 ;
if ( ! F_94 ( V_41 ) || V_4 != & V_62 -> V_4 [ V_141 ] )
return 0 ;
V_46 = F_77 ( V_4 , 4 * 3 ) ;
if ( V_46 )
return V_46 ;
for ( V_81 = 0 ; V_81 < 4 ; V_81 ++ ) {
F_78 ( V_4 , F_95 ( 1 ) ) ;
F_78 ( V_4 , F_96 ( V_81 ) ) ;
F_78 ( V_4 , 0 ) ;
}
F_79 ( V_4 ) ;
return 0 ;
}
static int
F_97 ( struct V_40 * V_41 , void * V_142 ,
struct V_95 * V_96 ,
struct V_120 * args ,
struct V_72 * V_107 )
{
T_6 * V_62 = V_41 -> V_63 ;
struct V_82 V_83 ;
struct V_21 * V_23 ;
struct V_1 * V_143 ;
struct V_144 * V_145 = NULL ;
struct V_3 * V_4 ;
T_7 V_146 , V_147 ;
T_7 V_128 ;
T_7 V_148 ;
int V_46 , V_149 , V_81 ;
if ( ! F_82 ( args ) ) {
F_19 ( L_13 ) ;
return - V_47 ;
}
V_46 = F_83 ( V_107 , args -> V_150 ) ;
if ( V_46 )
return V_46 ;
switch ( args -> V_88 & V_151 ) {
case V_152 :
case V_153 :
V_4 = & V_62 -> V_4 [ V_141 ] ;
break;
case V_154 :
V_4 = & V_62 -> V_4 [ V_155 ] ;
break;
case V_156 :
V_4 = & V_62 -> V_4 [ V_157 ] ;
break;
default:
F_19 ( L_14 ,
( int ) ( args -> V_88 & V_151 ) ) ;
return - V_47 ;
}
if ( ! F_98 ( V_4 ) ) {
F_19 ( L_15 ,
( int ) ( args -> V_88 & V_151 ) ) ;
return - V_47 ;
}
V_149 = args -> V_88 & V_158 ;
V_148 = V_158 ;
switch ( V_149 ) {
case V_159 :
case V_160 :
case V_161 :
if ( V_4 == & V_62 -> V_4 [ V_141 ] &&
V_149 != V_62 -> V_162 ) {
if ( F_43 ( V_41 ) -> V_85 < 4 )
return - V_47 ;
if ( F_43 ( V_41 ) -> V_85 > 5 &&
V_149 == V_161 )
return - V_47 ;
if ( F_43 ( V_41 ) -> V_85 >= 6 )
V_148 &= ~ V_161 ;
}
break;
default:
F_19 ( L_16 , V_149 ) ;
return - V_47 ;
}
if ( args -> V_150 < 1 ) {
F_19 ( L_17 , args -> V_150 ) ;
return - V_47 ;
}
if ( args -> V_163 != 0 ) {
if ( V_4 != & V_62 -> V_4 [ V_141 ] ) {
F_19 ( L_18 ) ;
return - V_47 ;
}
if ( F_43 ( V_41 ) -> V_85 >= 5 ) {
F_19 ( L_19 ) ;
return - V_47 ;
}
if ( args -> V_163 > V_164 / sizeof( * V_145 ) ) {
F_19 ( L_20 ,
args -> V_163 ) ;
return - V_47 ;
}
V_145 = F_99 ( args -> V_163 * sizeof( * V_145 ) ,
V_27 ) ;
if ( V_145 == NULL ) {
V_46 = - V_111 ;
goto V_165;
}
if ( F_68 ( V_145 ,
(struct V_144 T_4 * ) ( V_76 )
args -> V_166 ,
sizeof( * V_145 ) * args -> V_163 ) ) {
V_46 = - V_54 ;
goto V_165;
}
}
V_46 = F_69 ( V_41 ) ;
if ( V_46 )
goto V_165;
if ( V_62 -> V_66 . V_167 ) {
F_64 ( & V_41 -> V_110 ) ;
V_46 = - V_168 ;
goto V_165;
}
V_23 = F_5 ( args -> V_150 ) ;
if ( V_23 == NULL ) {
F_64 ( & V_41 -> V_110 ) ;
V_46 = - V_111 ;
goto V_165;
}
F_49 ( & V_83 ) ;
for ( V_81 = 0 ; V_81 < args -> V_150 ; V_81 ++ ) {
struct V_1 * V_2 ;
V_2 = F_18 ( F_70 ( V_41 , V_96 ,
V_107 [ V_81 ] . V_32 ) ) ;
if ( & V_2 -> V_9 == NULL ) {
F_19 ( L_12 ,
V_107 [ V_81 ] . V_32 , V_81 ) ;
V_46 = - V_49 ;
goto V_102;
}
if ( ! F_50 ( & V_2 -> V_99 ) ) {
F_19 ( L_21 ,
V_2 , V_107 [ V_81 ] . V_32 , V_81 ) ;
V_46 = - V_47 ;
goto V_102;
}
F_71 ( & V_2 -> V_99 , & V_83 ) ;
V_2 -> V_31 = V_107 [ V_81 ] . V_32 ;
V_2 -> V_74 = & V_107 [ V_81 ] ;
F_8 ( V_23 , V_2 ) ;
}
V_143 = F_100 ( V_83 . V_169 ,
struct V_1 ,
V_99 ) ;
V_46 = F_48 ( V_4 , V_96 , & V_83 ) ;
if ( V_46 )
goto V_102;
V_46 = F_37 ( V_41 , V_23 , & V_83 ) ;
if ( V_46 ) {
if ( V_46 == - V_54 ) {
V_46 = F_61 ( V_41 , V_96 , V_4 ,
& V_83 , V_23 ,
V_107 ,
args -> V_150 ) ;
F_101 ( ! F_102 ( & V_41 -> V_110 ) ) ;
}
if ( V_46 )
goto V_102;
}
if ( V_143 -> V_9 . V_10 ) {
F_19 ( L_22 ) ;
V_46 = - V_47 ;
goto V_102;
}
V_143 -> V_9 . V_11 |= V_138 ;
V_46 = F_80 ( V_4 , & V_83 ) ;
if ( V_46 )
goto V_102;
V_128 = F_91 ( V_4 ) ;
for ( V_81 = 0 ; V_81 < F_33 ( V_4 -> V_170 ) ; V_81 ++ ) {
if ( V_128 < V_4 -> V_170 [ V_81 ] ) {
V_46 = F_103 ( V_41 ) ;
if ( V_46 )
goto V_102;
F_104 ( V_41 ) ;
F_101 ( V_4 -> V_170 [ V_81 ] ) ;
}
}
if ( V_4 == & V_62 -> V_4 [ V_141 ] &&
V_149 != V_62 -> V_162 ) {
V_46 = F_77 ( V_4 , 4 ) ;
if ( V_46 )
goto V_102;
F_78 ( V_4 , V_119 ) ;
F_78 ( V_4 , F_95 ( 1 ) ) ;
F_78 ( V_4 , V_171 ) ;
F_78 ( V_4 , V_148 << 16 | V_149 ) ;
F_79 ( V_4 ) ;
V_62 -> V_162 = V_149 ;
}
if ( args -> V_88 & V_172 ) {
V_46 = F_93 ( V_41 , V_4 ) ;
if ( V_46 )
goto V_102;
}
F_105 ( V_4 , V_128 ) ;
V_146 = V_143 -> V_50 + args -> V_121 ;
V_147 = args -> V_122 ;
if ( V_145 ) {
for ( V_81 = 0 ; V_81 < args -> V_163 ; V_81 ++ ) {
V_46 = F_106 ( V_41 , & V_145 [ V_81 ] ,
args -> V_173 , args -> V_174 ) ;
if ( V_46 )
goto V_102;
V_46 = V_4 -> V_175 ( V_4 ,
V_146 , V_147 ) ;
if ( V_46 )
goto V_102;
}
} else {
V_46 = V_4 -> V_175 ( V_4 , V_146 , V_147 ) ;
if ( V_46 )
goto V_102;
}
F_86 ( & V_83 , V_4 , V_128 ) ;
F_90 ( V_41 , V_96 , V_4 ) ;
V_102:
F_13 ( V_23 ) ;
while ( ! F_50 ( & V_83 ) ) {
struct V_1 * V_2 ;
V_2 = F_51 ( & V_83 ,
struct V_1 ,
V_99 ) ;
F_62 ( & V_2 -> V_99 ) ;
F_63 ( & V_2 -> V_9 ) ;
}
F_64 ( & V_41 -> V_110 ) ;
V_165:
F_14 ( V_145 ) ;
return V_46 ;
}
int
F_107 ( struct V_40 * V_41 , void * V_142 ,
struct V_95 * V_96 )
{
struct V_176 * args = V_142 ;
struct V_120 V_177 ;
struct V_178 * V_99 = NULL ;
struct V_72 * V_179 = NULL ;
int V_46 , V_81 ;
if ( args -> V_150 < 1 ) {
F_19 ( L_17 , args -> V_150 ) ;
return - V_47 ;
}
V_99 = F_65 ( sizeof( * V_99 ) , args -> V_150 ) ;
V_179 = F_65 ( sizeof( * V_179 ) , args -> V_150 ) ;
if ( V_99 == NULL || V_179 == NULL ) {
F_19 ( L_23 ,
args -> V_150 ) ;
F_66 ( V_99 ) ;
F_66 ( V_179 ) ;
return - V_111 ;
}
V_46 = F_68 ( V_99 ,
(struct V_180 T_4 * )
( V_76 ) args -> V_181 ,
sizeof( * V_99 ) * args -> V_150 ) ;
if ( V_46 != 0 ) {
F_19 ( L_24 ,
args -> V_150 , V_46 ) ;
F_66 ( V_99 ) ;
F_66 ( V_179 ) ;
return - V_54 ;
}
for ( V_81 = 0 ; V_81 < args -> V_150 ; V_81 ++ ) {
V_179 [ V_81 ] . V_32 = V_99 [ V_81 ] . V_32 ;
V_179 [ V_81 ] . V_78 = V_99 [ V_81 ] . V_78 ;
V_179 [ V_81 ] . V_77 = V_99 [ V_81 ] . V_77 ;
V_179 [ V_81 ] . V_92 = V_99 [ V_81 ] . V_92 ;
V_179 [ V_81 ] . V_51 = V_99 [ V_81 ] . V_51 ;
if ( F_43 ( V_41 ) -> V_85 < 4 )
V_179 [ V_81 ] . V_88 = V_89 ;
else
V_179 [ V_81 ] . V_88 = 0 ;
}
V_177 . V_181 = args -> V_181 ;
V_177 . V_150 = args -> V_150 ;
V_177 . V_121 = args -> V_121 ;
V_177 . V_122 = args -> V_122 ;
V_177 . V_173 = args -> V_173 ;
V_177 . V_174 = args -> V_174 ;
V_177 . V_163 = args -> V_163 ;
V_177 . V_166 = args -> V_166 ;
V_177 . V_88 = V_153 ;
V_46 = F_97 ( V_41 , V_142 , V_96 , & V_177 , V_179 ) ;
if ( ! V_46 ) {
for ( V_81 = 0 ; V_81 < args -> V_150 ; V_81 ++ )
V_99 [ V_81 ] . V_51 = V_179 [ V_81 ] . V_51 ;
V_46 = F_108 ( (struct V_180 T_4 * )
( V_76 ) args -> V_181 ,
V_99 ,
sizeof( * V_99 ) * args -> V_150 ) ;
if ( V_46 ) {
V_46 = - V_54 ;
F_19 ( L_25
L_26 ,
args -> V_150 , V_46 ) ;
}
}
F_66 ( V_99 ) ;
F_66 ( V_179 ) ;
return V_46 ;
}
int
F_109 ( struct V_40 * V_41 , void * V_142 ,
struct V_95 * V_96 )
{
struct V_120 * args = V_142 ;
struct V_72 * V_179 = NULL ;
int V_46 ;
if ( args -> V_150 < 1 ||
args -> V_150 > V_164 / sizeof( * V_179 ) ) {
F_19 ( L_27 , args -> V_150 ) ;
return - V_47 ;
}
V_179 = F_99 ( sizeof( * V_179 ) * args -> V_150 ,
V_27 | V_182 | V_183 ) ;
if ( V_179 == NULL )
V_179 = F_65 ( sizeof( * V_179 ) ,
args -> V_150 ) ;
if ( V_179 == NULL ) {
F_19 ( L_23 ,
args -> V_150 ) ;
return - V_111 ;
}
V_46 = F_68 ( V_179 ,
(struct V_180 T_4 * )
( V_76 ) args -> V_181 ,
sizeof( * V_179 ) * args -> V_150 ) ;
if ( V_46 != 0 ) {
F_19 ( L_24 ,
args -> V_150 , V_46 ) ;
F_66 ( V_179 ) ;
return - V_54 ;
}
V_46 = F_97 ( V_41 , V_142 , V_96 , args , V_179 ) ;
if ( ! V_46 ) {
V_46 = F_108 ( (struct V_180 T_4 * )
( V_76 ) args -> V_181 ,
V_179 ,
sizeof( * V_179 ) * args -> V_150 ) ;
if ( V_46 ) {
V_46 = - V_54 ;
F_19 ( L_25
L_26 ,
args -> V_150 , V_46 ) ;
}
}
F_66 ( V_179 ) ;
return V_46 ;
}
