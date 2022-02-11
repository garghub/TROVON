static struct V_1 *
F_1 ( struct V_2 * args )
{
struct V_1 * V_3 = NULL ;
if ( args -> V_4 & V_5 ) {
unsigned V_6 = args -> V_7 ;
V_6 *= sizeof( struct V_8 * ) ;
V_6 += sizeof( struct V_1 ) ;
V_3 = F_2 ( V_6 , V_9 | V_10 | V_11 ) ;
}
if ( V_3 == NULL ) {
unsigned V_6 = args -> V_7 ;
unsigned V_12 = V_13 / sizeof( struct V_14 ) / 2 ;
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
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_21 -> V_26 -> V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 ;
int V_32 , V_33 ;
F_5 ( & V_31 ) ;
F_8 ( & V_23 -> V_34 ) ;
for ( V_32 = 0 ; V_32 < args -> V_7 ; V_32 ++ ) {
V_29 = F_9 ( F_10 ( & V_23 -> V_35 , V_19 [ V_32 ] . V_36 ) ) ;
if ( V_29 == NULL ) {
F_11 ( & V_23 -> V_34 ) ;
F_12 ( L_1 ,
V_19 [ V_32 ] . V_36 , V_32 ) ;
V_33 = - V_37 ;
goto V_38;
}
if ( ! F_13 ( & V_29 -> V_39 ) ) {
F_11 ( & V_23 -> V_34 ) ;
F_12 ( L_2 ,
V_29 , V_19 [ V_32 ] . V_36 , V_32 ) ;
V_33 = - V_40 ;
goto V_38;
}
F_14 ( & V_29 -> V_41 ) ;
F_15 ( & V_29 -> V_39 , & V_31 ) ;
}
F_11 ( & V_23 -> V_34 ) ;
V_32 = 0 ;
while ( ! F_13 ( & V_31 ) ) {
struct V_8 * V_42 ;
struct V_20 * V_43 = V_21 ;
if ( V_19 [ V_32 ] . V_4 & V_44 &&
F_16 ( V_21 -> V_26 ) ) {
V_33 = - V_40 ;
goto V_38;
}
if ( ( ( args -> V_4 & V_45 ) &&
( V_32 == ( args -> V_7 - 1 ) ) ) )
V_43 = & V_25 -> V_46 . V_41 ;
V_29 = F_17 ( & V_31 ,
struct V_28 ,
V_39 ) ;
V_42 = F_18 ( V_29 , V_43 ) ;
if ( F_19 ( V_42 ) ) {
F_12 ( L_3 ) ;
V_33 = F_20 ( V_42 ) ;
goto V_38;
}
F_15 ( & V_42 -> V_47 , & V_3 -> V_16 ) ;
F_21 ( & V_29 -> V_39 ) ;
V_42 -> V_48 = & V_19 [ V_32 ] ;
if ( V_3 -> V_15 < 0 ) {
V_3 -> V_49 [ V_32 ] = V_42 ;
} else {
T_1 V_36 = args -> V_4 & V_5 ? V_32 : V_19 [ V_32 ] . V_36 ;
V_42 -> V_50 = V_36 ;
F_22 ( & V_42 -> V_51 ,
& V_3 -> V_17 [ V_36 & V_3 -> V_15 ] ) ;
}
++ V_32 ;
}
return 0 ;
V_38:
while ( ! F_13 ( & V_31 ) ) {
V_29 = F_17 ( & V_31 ,
struct V_28 ,
V_39 ) ;
F_21 ( & V_29 -> V_39 ) ;
F_23 ( & V_29 -> V_41 ) ;
}
return V_33 ;
}
static struct V_8 * F_24 ( struct V_1 * V_3 , unsigned long V_36 )
{
if ( V_3 -> V_15 < 0 ) {
if ( V_36 >= - V_3 -> V_15 )
return NULL ;
return V_3 -> V_49 [ V_36 ] ;
} else {
struct V_14 * V_52 ;
struct V_53 * V_54 ;
V_52 = & V_3 -> V_17 [ V_36 & V_3 -> V_15 ] ;
F_25 (node, head) {
struct V_8 * V_42 ;
V_42 = F_26 ( V_54 , struct V_8 , V_51 ) ;
if ( V_42 -> V_50 == V_36 )
return V_42 ;
}
return NULL ;
}
}
static void
F_27 ( struct V_8 * V_42 )
{
struct V_18 * V_55 ;
struct V_28 * V_29 = V_42 -> V_29 ;
if ( ! F_28 ( & V_42 -> V_54 ) )
return;
V_55 = V_42 -> V_48 ;
if ( V_55 -> V_4 & V_56 )
F_29 ( V_29 ) ;
if ( V_55 -> V_4 & V_57 )
V_42 -> V_58 -- ;
V_55 -> V_4 &= ~ ( V_56 | V_57 ) ;
}
static void F_30 ( struct V_1 * V_3 )
{
while ( ! F_13 ( & V_3 -> V_16 ) ) {
struct V_8 * V_42 ;
V_42 = F_17 ( & V_3 -> V_16 ,
struct V_8 ,
V_47 ) ;
F_21 ( & V_42 -> V_47 ) ;
F_27 ( V_42 ) ;
F_23 ( & V_42 -> V_29 -> V_41 ) ;
}
F_31 ( V_3 ) ;
}
static inline int F_32 ( struct V_28 * V_29 )
{
return ( F_33 ( V_29 -> V_41 . V_26 ) ||
V_29 -> V_41 . V_59 == V_60 ||
! V_29 -> V_61 ||
V_29 -> V_62 != V_63 ) ;
}
static int
F_34 ( struct V_28 * V_29 ,
struct V_64 * V_65 ,
T_2 V_66 )
{
struct V_67 * V_26 = V_29 -> V_41 . V_26 ;
T_1 V_68 = F_35 ( V_65 -> V_69 ) ;
T_2 V_70 = V_65 -> V_70 + V_66 ;
char * V_71 ;
int V_33 ;
V_33 = F_36 ( V_29 , true ) ;
if ( V_33 )
return V_33 ;
V_71 = F_37 ( F_38 ( V_29 ,
V_65 -> V_69 >> V_72 ) ) ;
* ( T_1 * ) ( V_71 + V_68 ) = F_39 ( V_70 ) ;
if ( F_40 ( V_26 ) -> V_73 >= 8 ) {
V_68 = F_35 ( V_68 + sizeof( T_1 ) ) ;
if ( V_68 == 0 ) {
F_41 ( V_71 ) ;
V_71 = F_37 ( F_38 ( V_29 ,
( V_65 -> V_69 + sizeof( T_1 ) ) >> V_72 ) ) ;
}
* ( T_1 * ) ( V_71 + V_68 ) = F_42 ( V_70 ) ;
}
F_41 ( V_71 ) ;
return 0 ;
}
static int
F_43 ( struct V_28 * V_29 ,
struct V_64 * V_65 ,
T_2 V_66 )
{
struct V_67 * V_26 = V_29 -> V_41 . V_26 ;
struct V_24 * V_25 = V_26 -> V_27 ;
T_2 V_70 = V_65 -> V_70 + V_66 ;
T_1 T_3 * V_74 ;
void T_3 * V_75 ;
int V_33 ;
V_33 = F_44 ( V_29 , true ) ;
if ( V_33 )
return V_33 ;
V_33 = F_45 ( V_29 ) ;
if ( V_33 )
return V_33 ;
V_65 -> V_69 += F_46 ( V_29 ) ;
V_75 = F_47 ( V_25 -> V_46 . V_76 ,
V_65 -> V_69 & V_77 ) ;
V_74 = ( T_1 T_3 * )
( V_75 + F_35 ( V_65 -> V_69 ) ) ;
F_48 ( F_39 ( V_70 ) , V_74 ) ;
if ( F_40 ( V_26 ) -> V_73 >= 8 ) {
V_74 += 1 ;
if ( F_35 ( V_65 -> V_69 + sizeof( T_1 ) ) == 0 ) {
F_49 ( V_75 ) ;
V_75 = F_47 (
V_25 -> V_46 . V_76 ,
V_65 -> V_69 + sizeof( T_1 ) ) ;
V_74 = V_75 ;
}
F_48 ( F_42 ( V_70 ) , V_74 ) ;
}
F_49 ( V_75 ) ;
return 0 ;
}
static int
F_50 ( struct V_28 * V_29 ,
struct V_1 * V_3 ,
struct V_64 * V_65 )
{
struct V_67 * V_26 = V_29 -> V_41 . V_26 ;
struct V_78 * V_79 ;
struct V_28 * V_80 ;
struct V_8 * V_81 ;
T_2 V_66 ;
int V_33 ;
V_81 = F_24 ( V_3 , V_65 -> V_82 ) ;
if ( F_51 ( V_81 == NULL ) )
return - V_37 ;
V_80 = V_81 -> V_29 ;
V_79 = & V_81 -> V_29 -> V_41 ;
V_66 = V_81 -> V_54 . V_83 ;
if ( F_51 ( F_52 ( V_26 ) &&
V_65 -> V_59 == V_84 &&
! V_80 -> V_85 ) ) {
struct V_8 * V_42 =
F_17 ( & V_80 -> V_86 ,
F_53 ( * V_42 ) , V_87 ) ;
V_42 -> V_88 ( V_42 , V_80 -> V_62 , V_89 ) ;
}
if ( F_51 ( V_65 -> V_59 & ( V_65 -> V_59 - 1 ) ) ) {
F_12 ( L_4
L_5
L_6 ,
V_29 , V_65 -> V_82 ,
( int ) V_65 -> V_69 ,
V_65 -> V_90 ,
V_65 -> V_59 ) ;
return - V_40 ;
}
if ( F_51 ( ( V_65 -> V_59 | V_65 -> V_90 )
& ~ V_91 ) ) {
F_12 ( L_7
L_5
L_6 ,
V_29 , V_65 -> V_82 ,
( int ) V_65 -> V_69 ,
V_65 -> V_90 ,
V_65 -> V_59 ) ;
return - V_40 ;
}
V_79 -> V_92 |= V_65 -> V_90 ;
V_79 -> V_93 |= V_65 -> V_59 ;
if ( V_66 == V_65 -> V_94 )
return 0 ;
if ( F_51 ( V_65 -> V_69 >
V_29 -> V_41 . V_6 - ( F_40 ( V_26 ) -> V_73 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_8
L_9 ,
V_29 , V_65 -> V_82 ,
( int ) V_65 -> V_69 ,
( int ) V_29 -> V_41 . V_6 ) ;
return - V_40 ;
}
if ( F_51 ( V_65 -> V_69 & 3 ) ) {
F_12 ( L_10
L_11 ,
V_29 , V_65 -> V_82 ,
( int ) V_65 -> V_69 ) ;
return - V_40 ;
}
if ( V_29 -> V_95 && F_54 () )
return - V_96 ;
if ( F_32 ( V_29 ) )
V_33 = F_34 ( V_29 , V_65 , V_66 ) ;
else
V_33 = F_43 ( V_29 , V_65 , V_66 ) ;
if ( V_33 )
return V_33 ;
V_65 -> V_94 = V_66 ;
return 0 ;
}
static int
F_55 ( struct V_8 * V_42 ,
struct V_1 * V_3 )
{
#define F_56 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_64 V_97 [ F_56 ( 512 ) ] ;
struct V_64 T_5 * V_98 ;
struct V_18 * V_55 = V_42 -> V_48 ;
int V_99 , V_33 ;
V_98 = F_57 ( V_55 -> V_100 ) ;
V_99 = V_55 -> V_101 ;
while ( V_99 ) {
struct V_64 * V_102 = V_97 ;
int V_12 = V_99 ;
if ( V_12 > F_58 ( V_97 ) )
V_12 = F_58 ( V_97 ) ;
V_99 -= V_12 ;
if ( F_59 ( V_102 , V_98 , V_12 * sizeof( V_102 [ 0 ] ) ) )
return - V_96 ;
do {
T_6 V_69 = V_102 -> V_94 ;
V_33 = F_50 ( V_42 -> V_29 , V_3 , V_102 ) ;
if ( V_33 )
return V_33 ;
if ( V_102 -> V_94 != V_69 &&
F_60 ( & V_98 -> V_94 ,
& V_102 -> V_94 ,
sizeof( V_102 -> V_94 ) ) ) {
return - V_96 ;
}
V_98 ++ ;
V_102 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_56
}
static int
F_61 ( struct V_8 * V_42 ,
struct V_1 * V_3 ,
struct V_64 * V_103 )
{
const struct V_18 * V_55 = V_42 -> V_48 ;
int V_32 , V_33 ;
for ( V_32 = 0 ; V_32 < V_55 -> V_101 ; V_32 ++ ) {
V_33 = F_50 ( V_42 -> V_29 , V_3 , & V_103 [ V_32 ] ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int
F_62 ( struct V_1 * V_3 )
{
struct V_8 * V_42 ;
int V_33 = 0 ;
F_63 () ;
F_64 (vma, &eb->vmas, exec_list) {
V_33 = F_55 ( V_42 , V_3 ) ;
if ( V_33 )
break;
}
F_65 () ;
return V_33 ;
}
static int
F_66 ( struct V_8 * V_42 )
{
struct V_18 * V_55 = V_42 -> V_48 ;
return V_55 -> V_101 && ! F_32 ( V_42 -> V_29 ) &&
F_67 ( V_42 -> V_21 ) ;
}
static int
F_68 ( struct V_8 * V_42 ,
struct V_104 * V_105 ,
bool * V_106 )
{
struct V_28 * V_29 = V_42 -> V_29 ;
struct V_18 * V_55 = V_42 -> V_48 ;
bool V_107 = F_40 ( V_105 -> V_26 ) -> V_73 < 4 ;
bool V_108 ;
T_2 V_4 ;
int V_33 ;
V_4 = 0 ;
V_108 =
V_107 &&
V_55 -> V_4 & V_109 &&
V_29 -> V_110 != V_111 ;
if ( V_108 || F_66 ( V_42 ) )
V_4 |= V_112 ;
if ( V_55 -> V_4 & V_44 )
V_4 |= V_113 ;
if ( V_55 -> V_4 & V_114 )
V_4 |= V_115 | V_116 ;
V_33 = F_69 ( V_29 , V_42 -> V_21 , V_55 -> V_117 , V_4 ) ;
if ( V_33 )
return V_33 ;
V_55 -> V_4 |= V_57 ;
if ( V_107 ) {
if ( V_55 -> V_4 & V_109 ) {
V_33 = F_70 ( V_29 ) ;
if ( V_33 )
return V_33 ;
if ( F_71 ( V_29 ) )
V_55 -> V_4 |= V_56 ;
V_29 -> V_118 = true ;
}
}
if ( V_55 -> V_69 != V_42 -> V_54 . V_83 ) {
V_55 -> V_69 = V_42 -> V_54 . V_83 ;
* V_106 = true ;
}
if ( V_55 -> V_4 & V_119 ) {
V_29 -> V_41 . V_92 = V_120 ;
V_29 -> V_41 . V_93 = V_120 ;
}
return 0 ;
}
static bool
F_72 ( struct V_8 * V_42 , bool V_107 )
{
struct V_18 * V_55 = V_42 -> V_48 ;
struct V_28 * V_29 = V_42 -> V_29 ;
bool V_108 , V_121 ;
V_108 =
V_107 &&
V_55 -> V_4 & V_109 &&
V_29 -> V_110 != V_111 ;
V_121 = V_108 || F_66 ( V_42 ) ;
F_73 ( ( V_121 || V_108 ) &&
! F_67 ( V_42 -> V_21 ) ) ;
if ( V_55 -> V_117 &&
V_42 -> V_54 . V_83 & ( V_55 -> V_117 - 1 ) )
return true ;
if ( V_121 && ! V_29 -> V_61 )
return true ;
if ( V_55 -> V_4 & V_114 &&
V_42 -> V_54 . V_83 < V_115 )
return true ;
return false ;
}
static int
F_74 ( struct V_104 * V_105 ,
struct V_30 * V_16 ,
bool * V_122 )
{
struct V_28 * V_29 ;
struct V_8 * V_42 ;
struct V_20 * V_21 ;
struct V_30 V_123 ;
bool V_107 = F_40 ( V_105 -> V_26 ) -> V_73 < 4 ;
int V_124 ;
if ( F_13 ( V_16 ) )
return 0 ;
F_75 ( V_105 ) ;
V_21 = F_17 ( V_16 , struct V_8 , V_47 ) -> V_21 ;
F_5 ( & V_123 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_55 ;
bool V_108 , V_121 ;
V_42 = F_17 ( V_16 , struct V_8 , V_47 ) ;
V_29 = V_42 -> V_29 ;
V_55 = V_42 -> V_48 ;
V_108 =
V_107 &&
V_55 -> V_4 & V_109 &&
V_29 -> V_110 != V_111 ;
V_121 = V_108 || F_66 ( V_42 ) ;
if ( V_121 )
F_76 ( & V_42 -> V_47 , & V_123 ) ;
else
F_77 ( & V_42 -> V_47 , & V_123 ) ;
V_29 -> V_41 . V_92 = V_91 & ~ V_125 ;
V_29 -> V_41 . V_93 = 0 ;
V_29 -> V_118 = false ;
}
F_78 ( & V_123 , V_16 ) ;
V_124 = 0 ;
do {
int V_33 = 0 ;
F_64 (vma, vmas, exec_list) {
if ( ! F_28 ( & V_42 -> V_54 ) )
continue;
if ( F_72 ( V_42 , V_107 ) )
V_33 = F_79 ( V_42 ) ;
else
V_33 = F_68 ( V_42 , V_105 , V_122 ) ;
if ( V_33 )
goto V_38;
}
F_64 (vma, vmas, exec_list) {
if ( F_28 ( & V_42 -> V_54 ) )
continue;
V_33 = F_68 ( V_42 , V_105 , V_122 ) ;
if ( V_33 )
goto V_38;
}
V_38:
if ( V_33 != - V_126 || V_124 ++ )
return V_33 ;
F_64 (vma, vmas, exec_list)
F_27 ( V_42 ) ;
V_33 = F_80 ( V_21 , true ) ;
if ( V_33 )
return V_33 ;
} while ( 1 );
}
static int
F_81 ( struct V_67 * V_26 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_104 * V_105 ,
struct V_1 * V_3 ,
struct V_18 * V_19 )
{
struct V_64 * V_65 ;
struct V_20 * V_21 ;
struct V_8 * V_42 ;
bool V_122 ;
int * V_127 ;
int V_32 , V_128 , V_33 ;
unsigned V_12 = args -> V_7 ;
if ( F_73 ( F_13 ( & V_3 -> V_16 ) ) )
return 0 ;
V_21 = F_17 ( & V_3 -> V_16 , struct V_8 , V_47 ) -> V_21 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_42 = F_17 ( & V_3 -> V_16 , struct V_8 , V_47 ) ;
F_21 ( & V_42 -> V_47 ) ;
F_27 ( V_42 ) ;
F_23 ( & V_42 -> V_29 -> V_41 ) ;
}
F_82 ( & V_26 -> V_129 ) ;
V_128 = 0 ;
for ( V_32 = 0 ; V_32 < V_12 ; V_32 ++ )
V_128 += V_19 [ V_32 ] . V_101 ;
V_127 = F_83 ( V_12 , sizeof( * V_127 ) ) ;
V_65 = F_83 ( V_128 , sizeof( * V_65 ) ) ;
if ( V_65 == NULL || V_127 == NULL ) {
F_84 ( V_65 ) ;
F_84 ( V_127 ) ;
F_85 ( & V_26 -> V_129 ) ;
return - V_130 ;
}
V_128 = 0 ;
for ( V_32 = 0 ; V_32 < V_12 ; V_32 ++ ) {
struct V_64 T_5 * V_98 ;
T_6 V_131 = ( T_6 ) - 1 ;
int V_132 ;
V_98 = F_57 ( V_19 [ V_32 ] . V_100 ) ;
if ( F_86 ( V_65 + V_128 , V_98 ,
V_19 [ V_32 ] . V_101 * sizeof( * V_65 ) ) ) {
V_33 = - V_96 ;
F_85 ( & V_26 -> V_129 ) ;
goto V_38;
}
for ( V_132 = 0 ; V_132 < V_19 [ V_32 ] . V_101 ; V_132 ++ ) {
if ( F_87 ( & V_98 [ V_132 ] . V_94 ,
& V_131 ,
sizeof( V_131 ) ) ) {
V_33 = - V_96 ;
F_85 ( & V_26 -> V_129 ) ;
goto V_38;
}
}
V_127 [ V_32 ] = V_128 ;
V_128 += V_19 [ V_32 ] . V_101 ;
}
V_33 = F_88 ( V_26 ) ;
if ( V_33 ) {
F_85 ( & V_26 -> V_129 ) ;
goto V_38;
}
F_6 ( V_3 ) ;
V_33 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_33 )
goto V_38;
V_122 = ( args -> V_4 & V_133 ) == 0 ;
V_33 = F_74 ( V_105 , & V_3 -> V_16 , & V_122 ) ;
if ( V_33 )
goto V_38;
F_64 (vma, &eb->vmas, exec_list) {
int V_69 = V_42 -> V_48 - V_19 ;
V_33 = F_61 ( V_42 , V_3 ,
V_65 + V_127 [ V_69 ] ) ;
if ( V_33 )
goto V_38;
}
V_38:
F_84 ( V_65 ) ;
F_84 ( V_127 ) ;
return V_33 ;
}
static int
F_89 ( struct V_104 * V_105 ,
struct V_30 * V_16 )
{
struct V_8 * V_42 ;
T_1 V_134 = 0 ;
bool V_135 = false ;
int V_33 ;
F_64 (vma, vmas, exec_list) {
struct V_28 * V_29 = V_42 -> V_29 ;
V_33 = F_90 ( V_29 , V_105 ) ;
if ( V_33 )
return V_33 ;
if ( V_29 -> V_41 . V_59 & V_60 )
V_135 |= F_91 ( V_29 , false ) ;
V_134 |= V_29 -> V_41 . V_59 ;
}
if ( V_135 )
F_92 ( V_105 -> V_26 ) ;
if ( V_134 & V_136 )
F_93 () ;
return F_94 ( V_105 ) ;
}
static bool
F_95 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_137 )
return false ;
return ( ( V_19 -> V_138 | V_19 -> V_139 ) & 0x7 ) == 0 ;
}
static int
F_96 ( struct V_18 * V_19 ,
int V_12 )
{
int V_32 ;
unsigned V_140 = 0 ;
unsigned V_141 = V_142 / sizeof( struct V_64 ) ;
for ( V_32 = 0 ; V_32 < V_12 ; V_32 ++ ) {
char T_5 * V_143 = F_57 ( V_19 [ V_32 ] . V_100 ) ;
int V_144 ;
if ( V_19 [ V_32 ] . V_4 & V_145 )
return - V_40 ;
if ( V_19 [ V_32 ] . V_101 > V_141 - V_140 )
return - V_40 ;
V_140 += V_19 [ V_32 ] . V_101 ;
V_144 = V_19 [ V_32 ] . V_101 *
sizeof( struct V_64 ) ;
if ( ! F_97 ( V_146 , V_143 , V_144 ) )
return - V_96 ;
if ( F_98 ( ! V_147 . V_148 ) ) {
if ( F_99 ( V_143 , V_144 ) )
return - V_96 ;
}
}
return 0 ;
}
static struct V_149 *
F_100 ( struct V_67 * V_26 , struct V_22 * V_23 ,
struct V_104 * V_105 , const T_7 V_150 )
{
struct V_149 * V_151 = NULL ;
struct V_152 * V_153 ;
if ( V_105 -> V_154 != V_155 && V_150 != V_156 )
return F_101 ( - V_40 ) ;
V_151 = F_102 ( V_23 -> V_157 , V_150 ) ;
if ( F_19 ( V_151 ) )
return V_151 ;
V_153 = & V_151 -> V_158 ;
if ( V_153 -> V_159 ) {
F_12 ( L_12 , V_150 ) ;
return F_101 ( - V_160 ) ;
}
return V_151 ;
}
static void
F_103 ( struct V_30 * V_16 ,
struct V_104 * V_105 )
{
struct V_8 * V_42 ;
F_64 (vma, vmas, exec_list) {
struct V_28 * V_29 = V_42 -> V_29 ;
T_7 V_161 = V_29 -> V_41 . V_90 ;
T_7 V_162 = V_29 -> V_41 . V_59 ;
V_29 -> V_41 . V_59 = V_29 -> V_41 . V_93 ;
if ( V_29 -> V_41 . V_59 == 0 )
V_29 -> V_41 . V_92 |= V_29 -> V_41 . V_90 ;
V_29 -> V_41 . V_90 = V_29 -> V_41 . V_92 ;
V_29 -> V_163 = V_29 -> V_118 ;
F_104 ( V_42 , V_105 ) ;
if ( V_29 -> V_41 . V_59 ) {
V_29 -> V_164 = 1 ;
V_29 -> V_165 = F_105 ( V_105 ) ;
F_106 ( V_29 , V_105 ) ;
V_29 -> V_41 . V_59 &= ~ V_91 ;
}
F_107 ( V_29 , V_161 , V_162 ) ;
}
}
static void
F_108 ( struct V_67 * V_26 ,
struct V_22 * V_23 ,
struct V_104 * V_105 ,
struct V_28 * V_29 )
{
V_105 -> V_166 = true ;
( void ) F_109 ( V_105 , V_23 , V_29 , NULL ) ;
}
static int
F_110 ( struct V_67 * V_26 ,
struct V_104 * V_105 )
{
struct V_24 * V_25 = V_26 -> V_27 ;
int V_33 , V_32 ;
if ( ! F_111 ( V_26 ) || V_105 != & V_25 -> V_105 [ V_155 ] ) {
F_12 ( L_13 ) ;
return - V_40 ;
}
V_33 = F_112 ( V_105 , 4 * 3 ) ;
if ( V_33 )
return V_33 ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
F_113 ( V_105 , F_114 ( 1 ) ) ;
F_113 ( V_105 , F_115 ( V_32 ) ) ;
F_113 ( V_105 , 0 ) ;
}
F_116 ( V_105 ) ;
return 0 ;
}
static int
F_117 ( struct V_67 * V_26 , struct V_22 * V_23 ,
struct V_104 * V_105 ,
struct V_149 * V_151 ,
struct V_2 * args ,
struct V_30 * V_16 ,
struct V_28 * V_167 ,
T_6 V_168 , T_7 V_4 )
{
struct V_169 * V_170 = NULL ;
struct V_24 * V_25 = V_26 -> V_27 ;
T_6 V_171 ;
int V_172 ;
T_7 V_173 ;
int V_32 , V_33 = 0 ;
if ( args -> V_174 != 0 ) {
if ( V_105 != & V_25 -> V_105 [ V_155 ] ) {
F_12 ( L_14 ) ;
return - V_40 ;
}
if ( F_40 ( V_26 ) -> V_73 >= 5 ) {
F_12 ( L_15 ) ;
return - V_40 ;
}
if ( args -> V_174 > V_142 / sizeof( * V_170 ) ) {
F_12 ( L_16 ,
args -> V_174 ) ;
return - V_40 ;
}
V_170 = F_118 ( args -> V_174 ,
sizeof( * V_170 ) ,
V_175 ) ;
if ( V_170 == NULL ) {
V_33 = - V_130 ;
goto error;
}
if ( F_86 ( V_170 ,
F_57 ( args -> V_176 ) ,
sizeof( * V_170 ) * args -> V_174 ) ) {
V_33 = - V_96 ;
goto error;
}
} else {
if ( args -> V_177 == 0xffffffff ) {
F_12 ( L_17 ) ;
args -> V_177 = 0 ;
}
if ( args -> V_178 || args -> V_177 || args -> V_176 ) {
F_12 ( L_18 ) ;
return - V_40 ;
}
}
V_33 = F_89 ( V_105 , V_16 ) ;
if ( V_33 )
goto error;
V_33 = F_119 ( V_105 , V_151 ) ;
if ( V_33 )
goto error;
V_172 = args -> V_4 & V_179 ;
V_173 = V_179 ;
switch ( V_172 ) {
case V_180 :
case V_181 :
case V_182 :
if ( V_172 != 0 && V_105 != & V_25 -> V_105 [ V_155 ] ) {
F_12 ( L_19 ) ;
V_33 = - V_40 ;
goto error;
}
if ( V_172 != V_25 -> V_183 ) {
if ( F_40 ( V_26 ) -> V_73 < 4 ) {
F_12 ( L_20 ) ;
V_33 = - V_40 ;
goto error;
}
if ( F_40 ( V_26 ) -> V_73 > 5 &&
V_172 == V_182 ) {
F_12 ( L_21 ) ;
V_33 = - V_40 ;
goto error;
}
if ( F_40 ( V_26 ) -> V_73 >= 6 )
V_173 &= ~ V_182 ;
}
break;
default:
F_12 ( L_22 , V_172 ) ;
V_33 = - V_40 ;
goto error;
}
if ( V_105 == & V_25 -> V_105 [ V_155 ] &&
V_172 != V_25 -> V_183 ) {
V_33 = F_112 ( V_105 , 4 ) ;
if ( V_33 )
goto error;
F_113 ( V_105 , V_184 ) ;
F_113 ( V_105 , F_114 ( 1 ) ) ;
F_113 ( V_105 , V_185 ) ;
F_113 ( V_105 , V_173 << 16 | V_172 ) ;
F_116 ( V_105 ) ;
V_25 -> V_183 = V_172 ;
}
if ( args -> V_4 & V_186 ) {
V_33 = F_110 ( V_26 , V_105 ) ;
if ( V_33 )
goto error;
}
V_171 = args -> V_139 ;
if ( V_170 ) {
for ( V_32 = 0 ; V_32 < args -> V_174 ; V_32 ++ ) {
V_33 = F_120 ( V_26 , & V_170 [ V_32 ] ,
args -> V_178 , args -> V_177 ) ;
if ( V_33 )
goto error;
V_33 = V_105 -> V_187 ( V_105 ,
V_168 , V_171 ,
V_4 ) ;
if ( V_33 )
goto error;
}
} else {
V_33 = V_105 -> V_187 ( V_105 ,
V_168 , V_171 ,
V_4 ) ;
if ( V_33 )
return V_33 ;
}
F_121 ( V_105 , F_105 ( V_105 ) , V_4 ) ;
F_103 ( V_16 , V_105 ) ;
F_108 ( V_26 , V_23 , V_105 , V_167 ) ;
error:
F_31 ( V_170 ) ;
return V_33 ;
}
static int F_122 ( struct V_67 * V_26 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = V_26 -> V_27 ;
struct V_188 * V_189 = V_23 -> V_157 ;
if ( V_189 -> V_190 )
return V_189 -> V_190 -> V_154 ;
else {
int V_191 ;
F_85 ( & V_26 -> V_129 ) ;
if ( V_25 -> V_192 . V_193 == 0 ) {
V_191 = V_194 ;
V_25 -> V_192 . V_193 = 1 ;
} else {
V_191 = V_195 ;
V_25 -> V_192 . V_193 = 0 ;
}
V_189 -> V_190 = & V_25 -> V_105 [ V_191 ] ;
F_82 ( & V_26 -> V_129 ) ;
return V_191 ;
}
}
static struct V_28 *
F_123 ( struct V_1 * V_3 )
{
struct V_8 * V_42 = F_124 ( V_3 -> V_16 . V_196 , F_53 ( * V_42 ) , V_47 ) ;
V_42 -> V_48 -> V_4 |= V_114 ;
return V_42 -> V_29 ;
}
static int
F_125 ( struct V_67 * V_26 , void * V_197 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_24 * V_25 = V_26 -> V_27 ;
struct V_1 * V_3 ;
struct V_28 * V_167 ;
struct V_104 * V_105 ;
struct V_149 * V_151 ;
struct V_20 * V_21 ;
const T_7 V_150 = F_126 ( * args ) ;
T_6 V_168 = args -> V_138 ;
T_7 V_4 ;
int V_33 ;
bool V_122 ;
if ( ! F_95 ( args ) )
return - V_40 ;
V_33 = F_96 ( V_19 , args -> V_7 ) ;
if ( V_33 )
return V_33 ;
V_4 = 0 ;
if ( args -> V_4 & V_45 ) {
if ( ! V_23 -> V_198 || ! F_127 ( V_199 ) )
return - V_200 ;
V_4 |= V_201 ;
}
if ( args -> V_4 & V_202 )
V_4 |= V_203 ;
if ( ( args -> V_4 & V_204 ) > V_205 ) {
F_12 ( L_23 ,
( int ) ( args -> V_4 & V_204 ) ) ;
return - V_40 ;
}
if ( ( args -> V_4 & V_204 ) == V_206 )
V_105 = & V_25 -> V_105 [ V_155 ] ;
else if ( ( args -> V_4 & V_204 ) == V_207 ) {
if ( F_128 ( V_26 ) ) {
int V_191 ;
V_191 = F_122 ( V_26 , V_23 ) ;
V_105 = & V_25 -> V_105 [ V_191 ] ;
} else
V_105 = & V_25 -> V_105 [ V_194 ] ;
} else
V_105 = & V_25 -> V_105 [ ( args -> V_4 & V_204 ) - 1 ] ;
if ( ! F_129 ( V_105 ) ) {
F_12 ( L_24 ,
( int ) ( args -> V_4 & V_204 ) ) ;
return - V_40 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_25 , args -> V_7 ) ;
return - V_40 ;
}
F_130 ( V_25 ) ;
V_33 = F_88 ( V_26 ) ;
if ( V_33 )
goto V_208;
if ( V_25 -> V_209 . V_210 ) {
F_82 ( & V_26 -> V_129 ) ;
V_33 = - V_211 ;
goto V_208;
}
V_151 = F_100 ( V_26 , V_23 , V_105 , V_150 ) ;
if ( F_19 ( V_151 ) ) {
F_82 ( & V_26 -> V_129 ) ;
V_33 = F_20 ( V_151 ) ;
goto V_208;
}
F_131 ( V_151 ) ;
V_21 = V_151 -> V_21 ;
if ( ! F_16 ( V_26 ) )
V_21 = & V_25 -> V_46 . V_41 ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_132 ( V_151 ) ;
F_82 ( & V_26 -> V_129 ) ;
V_33 = - V_130 ;
goto V_208;
}
V_33 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_33 )
goto V_38;
V_167 = F_123 ( V_3 ) ;
V_122 = ( args -> V_4 & V_133 ) == 0 ;
V_33 = F_74 ( V_105 , & V_3 -> V_16 , & V_122 ) ;
if ( V_33 )
goto V_38;
if ( V_122 )
V_33 = F_62 ( V_3 ) ;
if ( V_33 ) {
if ( V_33 == - V_96 ) {
V_33 = F_81 ( V_26 , args , V_23 , V_105 ,
V_3 , V_19 ) ;
F_133 ( ! F_134 ( & V_26 -> V_129 ) ) ;
}
if ( V_33 )
goto V_38;
}
if ( V_167 -> V_41 . V_93 ) {
F_12 ( L_26 ) ;
V_33 = - V_40 ;
goto V_38;
}
V_167 -> V_41 . V_92 |= V_125 ;
if ( F_135 ( V_105 ) ) {
V_33 = F_136 ( V_105 ,
V_167 ,
args -> V_138 ,
V_23 -> V_198 ) ;
if ( V_33 )
goto V_38;
}
if ( V_4 & V_201 &&
! V_167 -> V_85 ) {
struct V_8 * V_42 = F_137 ( V_167 ) ;
F_133 ( ! V_42 ) ;
V_42 -> V_88 ( V_42 , V_167 -> V_62 , V_89 ) ;
}
if ( V_4 & V_201 )
V_168 += F_46 ( V_167 ) ;
else
V_168 += F_138 ( V_167 , V_21 ) ;
V_33 = F_117 ( V_26 , V_23 , V_105 , V_151 ,
args , & V_3 -> V_16 , V_167 , V_168 , V_4 ) ;
if ( V_33 )
goto V_38;
V_38:
F_132 ( V_151 ) ;
F_30 ( V_3 ) ;
F_82 ( & V_26 -> V_129 ) ;
V_208:
F_139 ( V_25 ) ;
return V_33 ;
}
int
F_140 ( struct V_67 * V_26 , void * V_197 ,
struct V_22 * V_23 )
{
struct V_212 * args = V_197 ;
struct V_2 V_213 ;
struct V_214 * V_47 = NULL ;
struct V_18 * V_215 = NULL ;
int V_33 , V_32 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_25 , args -> V_7 ) ;
return - V_40 ;
}
V_47 = F_83 ( sizeof( * V_47 ) , args -> V_7 ) ;
V_215 = F_83 ( sizeof( * V_215 ) , args -> V_7 ) ;
if ( V_47 == NULL || V_215 == NULL ) {
F_12 ( L_27 ,
args -> V_7 ) ;
F_84 ( V_47 ) ;
F_84 ( V_215 ) ;
return - V_130 ;
}
V_33 = F_86 ( V_47 ,
F_57 ( args -> V_216 ) ,
sizeof( * V_47 ) * args -> V_7 ) ;
if ( V_33 != 0 ) {
F_12 ( L_28 ,
args -> V_7 , V_33 ) ;
F_84 ( V_47 ) ;
F_84 ( V_215 ) ;
return - V_96 ;
}
for ( V_32 = 0 ; V_32 < args -> V_7 ; V_32 ++ ) {
V_215 [ V_32 ] . V_36 = V_47 [ V_32 ] . V_36 ;
V_215 [ V_32 ] . V_101 = V_47 [ V_32 ] . V_101 ;
V_215 [ V_32 ] . V_100 = V_47 [ V_32 ] . V_100 ;
V_215 [ V_32 ] . V_117 = V_47 [ V_32 ] . V_117 ;
V_215 [ V_32 ] . V_69 = V_47 [ V_32 ] . V_69 ;
if ( F_40 ( V_26 ) -> V_73 < 4 )
V_215 [ V_32 ] . V_4 = V_109 ;
else
V_215 [ V_32 ] . V_4 = 0 ;
}
V_213 . V_216 = args -> V_216 ;
V_213 . V_7 = args -> V_7 ;
V_213 . V_138 = args -> V_138 ;
V_213 . V_139 = args -> V_139 ;
V_213 . V_178 = args -> V_178 ;
V_213 . V_177 = args -> V_177 ;
V_213 . V_174 = args -> V_174 ;
V_213 . V_176 = args -> V_176 ;
V_213 . V_4 = V_217 ;
F_141 ( V_213 , 0 ) ;
V_33 = F_125 ( V_26 , V_197 , V_23 , & V_213 , V_215 ) ;
if ( ! V_33 ) {
struct V_214 T_5 * V_218 =
F_57 ( args -> V_216 ) ;
for ( V_32 = 0 ; V_32 < args -> V_7 ; V_32 ++ ) {
V_33 = F_87 ( & V_218 [ V_32 ] . V_69 ,
& V_215 [ V_32 ] . V_69 ,
sizeof( V_218 [ V_32 ] . V_69 ) ) ;
if ( V_33 ) {
V_33 = - V_96 ;
F_12 ( L_29
L_30 ,
args -> V_7 , V_33 ) ;
break;
}
}
}
F_84 ( V_47 ) ;
F_84 ( V_215 ) ;
return V_33 ;
}
int
F_142 ( struct V_67 * V_26 , void * V_197 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_197 ;
struct V_18 * V_215 = NULL ;
int V_33 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_142 / sizeof( * V_215 ) ) {
F_12 ( L_31 , args -> V_7 ) ;
return - V_40 ;
}
if ( args -> V_219 != 0 ) {
F_12 ( L_32 ) ;
return - V_40 ;
}
V_215 = F_2 ( sizeof( * V_215 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_215 == NULL )
V_215 = F_83 ( sizeof( * V_215 ) ,
args -> V_7 ) ;
if ( V_215 == NULL ) {
F_12 ( L_27 ,
args -> V_7 ) ;
return - V_130 ;
}
V_33 = F_86 ( V_215 ,
F_57 ( args -> V_216 ) ,
sizeof( * V_215 ) * args -> V_7 ) ;
if ( V_33 != 0 ) {
F_12 ( L_28 ,
args -> V_7 , V_33 ) ;
F_84 ( V_215 ) ;
return - V_96 ;
}
V_33 = F_125 ( V_26 , V_197 , V_23 , args , V_215 ) ;
if ( ! V_33 ) {
struct V_18 T_5 * V_218 =
F_57 ( args -> V_216 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < args -> V_7 ; V_32 ++ ) {
V_33 = F_87 ( & V_218 [ V_32 ] . V_69 ,
& V_215 [ V_32 ] . V_69 ,
sizeof( V_218 [ V_32 ] . V_69 ) ) ;
if ( V_33 ) {
V_33 = - V_96 ;
F_12 ( L_29
L_33 ,
args -> V_7 ) ;
break;
}
}
}
F_84 ( V_215 ) ;
return V_33 ;
}
