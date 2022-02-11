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
struct V_24 * V_25 ;
struct V_26 V_27 ;
int V_28 , V_29 ;
F_5 ( & V_27 ) ;
F_8 ( & V_23 -> V_30 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_25 = F_9 ( F_10 ( & V_23 -> V_31 , V_19 [ V_28 ] . V_32 ) ) ;
if ( V_25 == NULL ) {
F_11 ( & V_23 -> V_30 ) ;
F_12 ( L_1 ,
V_19 [ V_28 ] . V_32 , V_28 ) ;
V_29 = - V_33 ;
goto V_34;
}
if ( ! F_13 ( & V_25 -> V_35 ) ) {
F_11 ( & V_23 -> V_30 ) ;
F_12 ( L_2 ,
V_25 , V_19 [ V_28 ] . V_32 , V_28 ) ;
V_29 = - V_36 ;
goto V_34;
}
F_14 ( & V_25 -> V_37 ) ;
F_15 ( & V_25 -> V_35 , & V_27 ) ;
}
F_11 ( & V_23 -> V_30 ) ;
V_28 = 0 ;
while ( ! F_13 ( & V_27 ) ) {
struct V_8 * V_38 ;
V_25 = F_16 ( & V_27 ,
struct V_24 ,
V_35 ) ;
V_38 = F_17 ( V_25 , V_21 ) ;
if ( F_18 ( V_38 ) ) {
F_12 ( L_3 ) ;
V_29 = F_19 ( V_38 ) ;
goto V_34;
}
F_15 ( & V_38 -> V_39 , & V_3 -> V_16 ) ;
F_20 ( & V_25 -> V_35 ) ;
V_38 -> V_40 = & V_19 [ V_28 ] ;
if ( V_3 -> V_15 < 0 ) {
V_3 -> V_41 [ V_28 ] = V_38 ;
} else {
T_1 V_32 = args -> V_4 & V_5 ? V_28 : V_19 [ V_28 ] . V_32 ;
V_38 -> V_42 = V_32 ;
F_21 ( & V_38 -> V_43 ,
& V_3 -> V_17 [ V_32 & V_3 -> V_15 ] ) ;
}
++ V_28 ;
}
return 0 ;
V_34:
while ( ! F_13 ( & V_27 ) ) {
V_25 = F_16 ( & V_27 ,
struct V_24 ,
V_35 ) ;
F_20 ( & V_25 -> V_35 ) ;
F_22 ( & V_25 -> V_37 ) ;
}
return V_29 ;
}
static struct V_8 * F_23 ( struct V_1 * V_3 , unsigned long V_32 )
{
if ( V_3 -> V_15 < 0 ) {
if ( V_32 >= - V_3 -> V_15 )
return NULL ;
return V_3 -> V_41 [ V_32 ] ;
} else {
struct V_14 * V_44 ;
struct V_45 * V_46 ;
V_44 = & V_3 -> V_17 [ V_32 & V_3 -> V_15 ] ;
F_24 (node, head) {
struct V_8 * V_38 ;
V_38 = F_25 ( V_46 , struct V_8 , V_43 ) ;
if ( V_38 -> V_42 == V_32 )
return V_38 ;
}
return NULL ;
}
}
static void
F_26 ( struct V_8 * V_38 )
{
struct V_18 * V_47 ;
struct V_24 * V_25 = V_38 -> V_25 ;
if ( ! F_27 ( & V_38 -> V_46 ) )
return;
V_47 = V_38 -> V_40 ;
if ( V_47 -> V_4 & V_48 )
F_28 ( V_25 ) ;
if ( V_47 -> V_4 & V_49 )
V_38 -> V_50 -- ;
if ( V_47 -> V_4 & V_51 )
V_25 -> V_52 = V_53 ;
V_47 -> V_4 &= ~ ( V_48 |
V_49 |
V_51 ) ;
}
static void F_29 ( struct V_1 * V_3 )
{
while ( ! F_13 ( & V_3 -> V_16 ) ) {
struct V_8 * V_38 ;
V_38 = F_16 ( & V_3 -> V_16 ,
struct V_8 ,
V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_30 ( V_3 ) ;
}
static inline int F_31 ( struct V_24 * V_25 )
{
return ( F_32 ( V_25 -> V_37 . V_54 ) ||
V_25 -> V_37 . V_55 == V_56 ||
! V_25 -> V_57 ||
V_25 -> V_58 != V_59 ) ;
}
static int
F_33 ( struct V_24 * V_25 ,
struct V_60 * V_61 ,
T_2 V_62 )
{
struct V_63 * V_54 = V_25 -> V_37 . V_54 ;
T_1 V_64 = F_34 ( V_61 -> V_65 ) ;
T_2 V_66 = V_61 -> V_66 + V_62 ;
char * V_67 ;
int V_29 ;
V_29 = F_35 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_67 = F_36 ( F_37 ( V_25 ,
V_61 -> V_65 >> V_68 ) ) ;
* ( T_1 * ) ( V_67 + V_64 ) = F_38 ( V_66 ) ;
if ( F_39 ( V_54 ) -> V_69 >= 8 ) {
V_64 = F_34 ( V_64 + sizeof( T_1 ) ) ;
if ( V_64 == 0 ) {
F_40 ( V_67 ) ;
V_67 = F_36 ( F_37 ( V_25 ,
( V_61 -> V_65 + sizeof( T_1 ) ) >> V_68 ) ) ;
}
* ( T_1 * ) ( V_67 + V_64 ) = F_41 ( V_66 ) ;
}
F_40 ( V_67 ) ;
return 0 ;
}
static int
F_42 ( struct V_24 * V_25 ,
struct V_60 * V_61 ,
T_2 V_62 )
{
struct V_63 * V_54 = V_25 -> V_37 . V_54 ;
struct V_70 * V_71 = V_54 -> V_72 ;
T_2 V_66 = V_61 -> V_66 + V_62 ;
T_2 V_65 ;
void T_3 * V_73 ;
int V_29 ;
V_29 = F_43 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_29 = F_44 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_65 = F_45 ( V_25 ) ;
V_65 += V_61 -> V_65 ;
V_73 = F_46 ( V_71 -> V_74 . V_75 ,
V_65 & V_76 ) ;
F_47 ( F_38 ( V_66 ) , V_73 + F_34 ( V_65 ) ) ;
if ( F_39 ( V_54 ) -> V_69 >= 8 ) {
V_65 += sizeof( T_1 ) ;
if ( F_34 ( V_65 ) == 0 ) {
F_48 ( V_73 ) ;
V_73 =
F_46 ( V_71 -> V_74 . V_75 ,
V_65 ) ;
}
F_47 ( F_41 ( V_66 ) ,
V_73 + F_34 ( V_65 ) ) ;
}
F_48 ( V_73 ) ;
return 0 ;
}
static int
F_49 ( struct V_24 * V_25 ,
struct V_1 * V_3 ,
struct V_60 * V_61 )
{
struct V_63 * V_54 = V_25 -> V_37 . V_54 ;
struct V_77 * V_78 ;
struct V_24 * V_79 ;
struct V_8 * V_80 ;
T_2 V_62 ;
int V_29 ;
V_80 = F_23 ( V_3 , V_61 -> V_81 ) ;
if ( F_50 ( V_80 == NULL ) )
return - V_33 ;
V_79 = V_80 -> V_25 ;
V_78 = & V_80 -> V_25 -> V_37 ;
V_62 = V_80 -> V_46 . V_82 ;
if ( F_50 ( F_51 ( V_54 ) &&
V_61 -> V_55 == V_83 &&
! ( V_80 -> V_84 & V_85 ) ) ) {
V_29 = F_52 ( V_80 , V_79 -> V_58 ,
V_85 ) ;
if ( F_53 ( V_29 , L_4 ) )
return V_29 ;
}
if ( F_50 ( V_61 -> V_55 & ( V_61 -> V_55 - 1 ) ) ) {
F_12 ( L_5
L_6
L_7 ,
V_25 , V_61 -> V_81 ,
( int ) V_61 -> V_65 ,
V_61 -> V_86 ,
V_61 -> V_55 ) ;
return - V_36 ;
}
if ( F_50 ( ( V_61 -> V_55 | V_61 -> V_86 )
& ~ V_87 ) ) {
F_12 ( L_8
L_6
L_7 ,
V_25 , V_61 -> V_81 ,
( int ) V_61 -> V_65 ,
V_61 -> V_86 ,
V_61 -> V_55 ) ;
return - V_36 ;
}
V_78 -> V_88 |= V_61 -> V_86 ;
V_78 -> V_89 |= V_61 -> V_55 ;
if ( V_62 == V_61 -> V_90 )
return 0 ;
if ( F_50 ( V_61 -> V_65 >
V_25 -> V_37 . V_6 - ( F_39 ( V_54 ) -> V_69 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_9
L_10 ,
V_25 , V_61 -> V_81 ,
( int ) V_61 -> V_65 ,
( int ) V_25 -> V_37 . V_6 ) ;
return - V_36 ;
}
if ( F_50 ( V_61 -> V_65 & 3 ) ) {
F_12 ( L_11
L_12 ,
V_25 , V_61 -> V_81 ,
( int ) V_61 -> V_65 ) ;
return - V_36 ;
}
if ( V_25 -> V_91 && F_54 () )
return - V_92 ;
if ( F_31 ( V_25 ) )
V_29 = F_33 ( V_25 , V_61 , V_62 ) ;
else
V_29 = F_42 ( V_25 , V_61 , V_62 ) ;
if ( V_29 )
return V_29 ;
V_61 -> V_90 = V_62 ;
return 0 ;
}
static int
F_55 ( struct V_8 * V_38 ,
struct V_1 * V_3 )
{
#define F_56 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_60 V_93 [ F_56 ( 512 ) ] ;
struct V_60 T_5 * V_94 ;
struct V_18 * V_47 = V_38 -> V_40 ;
int V_95 , V_29 ;
V_94 = F_57 ( V_47 -> V_96 ) ;
V_95 = V_47 -> V_97 ;
while ( V_95 ) {
struct V_60 * V_98 = V_93 ;
int V_12 = V_95 ;
if ( V_12 > F_58 ( V_93 ) )
V_12 = F_58 ( V_93 ) ;
V_95 -= V_12 ;
if ( F_59 ( V_98 , V_94 , V_12 * sizeof( V_98 [ 0 ] ) ) )
return - V_92 ;
do {
T_6 V_65 = V_98 -> V_90 ;
V_29 = F_49 ( V_38 -> V_25 , V_3 , V_98 ) ;
if ( V_29 )
return V_29 ;
if ( V_98 -> V_90 != V_65 &&
F_60 ( & V_94 -> V_90 ,
& V_98 -> V_90 ,
sizeof( V_98 -> V_90 ) ) ) {
return - V_92 ;
}
V_94 ++ ;
V_98 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_56
}
static int
F_61 ( struct V_8 * V_38 ,
struct V_1 * V_3 ,
struct V_60 * V_99 )
{
const struct V_18 * V_47 = V_38 -> V_40 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_47 -> V_97 ; V_28 ++ ) {
V_29 = F_49 ( V_38 -> V_25 , V_3 , & V_99 [ V_28 ] ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_62 ( struct V_1 * V_3 )
{
struct V_8 * V_38 ;
int V_29 = 0 ;
F_63 () ;
F_64 (vma, &eb->vmas, exec_list) {
V_29 = F_55 ( V_38 , V_3 ) ;
if ( V_29 )
break;
}
F_65 () ;
return V_29 ;
}
static int
F_66 ( struct V_8 * V_38 ,
struct V_100 * V_101 ,
bool * V_102 )
{
struct V_24 * V_25 = V_38 -> V_25 ;
struct V_18 * V_47 = V_38 -> V_40 ;
T_2 V_4 ;
int V_29 ;
V_4 = 0 ;
if ( V_47 -> V_4 & V_103 )
V_4 |= V_104 | V_105 ;
if ( V_47 -> V_4 & V_106 )
V_4 |= V_104 ;
if ( V_47 -> V_4 & V_107 )
V_4 |= V_108 | V_109 ;
V_29 = F_67 ( V_25 , V_38 -> V_21 , V_47 -> V_110 , V_4 ) ;
if ( V_29 )
return V_29 ;
V_47 -> V_4 |= V_49 ;
if ( V_47 -> V_4 & V_111 ) {
V_29 = F_68 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_69 ( V_25 ) )
V_47 -> V_4 |= V_48 ;
}
if ( V_47 -> V_65 != V_38 -> V_46 . V_82 ) {
V_47 -> V_65 = V_38 -> V_46 . V_82 ;
* V_102 = true ;
}
if ( V_47 -> V_4 & V_112 ) {
V_25 -> V_37 . V_88 = V_113 ;
V_25 -> V_37 . V_89 = V_113 ;
}
return 0 ;
}
static bool
F_70 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
if ( V_47 -> V_97 == 0 )
return false ;
if ( ! F_71 ( V_38 -> V_21 ) )
return false ;
if ( F_32 ( V_38 -> V_25 -> V_37 . V_54 ) )
return false ;
if ( V_38 -> V_25 -> V_37 . V_55 == V_56 )
return false ;
return true ;
}
static bool
F_72 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
F_73 ( V_47 -> V_4 & V_103 &&
! F_71 ( V_38 -> V_21 ) ) ;
if ( V_47 -> V_110 &&
V_38 -> V_46 . V_82 & ( V_47 -> V_110 - 1 ) )
return true ;
if ( V_47 -> V_4 & V_103 && ! V_25 -> V_57 )
return true ;
if ( V_47 -> V_4 & V_107 &&
V_38 -> V_46 . V_82 < V_108 )
return true ;
return false ;
}
static int
F_74 ( struct V_100 * V_101 ,
struct V_26 * V_16 ,
bool * V_114 )
{
struct V_24 * V_25 ;
struct V_8 * V_38 ;
struct V_20 * V_21 ;
struct V_26 V_115 ;
bool V_116 = F_39 ( V_101 -> V_54 ) -> V_69 < 4 ;
int V_117 ;
F_75 ( V_101 ) ;
V_21 = F_16 ( V_16 , struct V_8 , V_39 ) -> V_21 ;
F_5 ( & V_115 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_47 ;
bool V_118 , V_119 ;
V_38 = F_16 ( V_16 , struct V_8 , V_39 ) ;
V_25 = V_38 -> V_25 ;
V_47 = V_38 -> V_40 ;
if ( ! V_116 )
V_47 -> V_4 &= ~ V_111 ;
V_118 =
V_47 -> V_4 & V_111 &&
V_25 -> V_120 != V_121 ;
V_119 = V_118 || F_70 ( V_38 ) ;
if ( V_119 ) {
V_47 -> V_4 |= V_103 ;
F_76 ( & V_38 -> V_39 , & V_115 ) ;
} else
F_77 ( & V_38 -> V_39 , & V_115 ) ;
V_25 -> V_37 . V_88 = V_87 & ~ V_122 ;
V_25 -> V_37 . V_89 = 0 ;
}
F_78 ( & V_115 , V_16 ) ;
V_117 = 0 ;
do {
int V_29 = 0 ;
F_64 (vma, vmas, exec_list) {
if ( ! F_27 ( & V_38 -> V_46 ) )
continue;
if ( F_72 ( V_38 ) )
V_29 = F_79 ( V_38 ) ;
else
V_29 = F_66 ( V_38 , V_101 , V_114 ) ;
if ( V_29 )
goto V_34;
}
F_64 (vma, vmas, exec_list) {
if ( F_27 ( & V_38 -> V_46 ) )
continue;
V_29 = F_66 ( V_38 , V_101 , V_114 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_123 || V_117 ++ )
return V_29 ;
F_64 (vma, vmas, exec_list)
F_26 ( V_38 ) ;
V_29 = F_80 ( V_21 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_81 ( struct V_63 * V_54 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_100 * V_101 ,
struct V_1 * V_3 ,
struct V_18 * V_19 )
{
struct V_60 * V_61 ;
struct V_20 * V_21 ;
struct V_8 * V_38 ;
bool V_114 ;
int * V_124 ;
int V_28 , V_125 , V_29 ;
unsigned V_12 = args -> V_7 ;
V_21 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) -> V_21 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_38 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_82 ( & V_54 -> V_126 ) ;
V_125 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
V_125 += V_19 [ V_28 ] . V_97 ;
V_124 = F_83 ( V_12 , sizeof( * V_124 ) ) ;
V_61 = F_83 ( V_125 , sizeof( * V_61 ) ) ;
if ( V_61 == NULL || V_124 == NULL ) {
F_84 ( V_61 ) ;
F_84 ( V_124 ) ;
F_85 ( & V_54 -> V_126 ) ;
return - V_127 ;
}
V_125 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
struct V_60 T_5 * V_94 ;
T_6 V_128 = ( T_6 ) - 1 ;
int V_129 ;
V_94 = F_57 ( V_19 [ V_28 ] . V_96 ) ;
if ( F_86 ( V_61 + V_125 , V_94 ,
V_19 [ V_28 ] . V_97 * sizeof( * V_61 ) ) ) {
V_29 = - V_92 ;
F_85 ( & V_54 -> V_126 ) ;
goto V_34;
}
for ( V_129 = 0 ; V_129 < V_19 [ V_28 ] . V_97 ; V_129 ++ ) {
if ( F_87 ( & V_94 [ V_129 ] . V_90 ,
& V_128 ,
sizeof( V_128 ) ) ) {
V_29 = - V_92 ;
F_85 ( & V_54 -> V_126 ) ;
goto V_34;
}
}
V_124 [ V_28 ] = V_125 ;
V_125 += V_19 [ V_28 ] . V_97 ;
}
V_29 = F_88 ( V_54 ) ;
if ( V_29 ) {
F_85 ( & V_54 -> V_126 ) ;
goto V_34;
}
F_6 ( V_3 ) ;
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_114 = ( args -> V_4 & V_130 ) == 0 ;
V_29 = F_74 ( V_101 , & V_3 -> V_16 , & V_114 ) ;
if ( V_29 )
goto V_34;
F_64 (vma, &eb->vmas, exec_list) {
int V_65 = V_38 -> V_40 - V_19 ;
V_29 = F_61 ( V_38 , V_3 ,
V_61 + V_124 [ V_65 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_84 ( V_61 ) ;
F_84 ( V_124 ) ;
return V_29 ;
}
static int
F_89 ( struct V_100 * V_101 ,
struct V_26 * V_16 )
{
struct V_8 * V_38 ;
T_1 V_131 = 0 ;
bool V_132 = false ;
int V_29 ;
F_64 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
V_29 = F_90 ( V_25 , V_101 ) ;
if ( V_29 )
return V_29 ;
if ( V_25 -> V_37 . V_55 & V_56 )
V_132 |= F_91 ( V_25 , false ) ;
V_131 |= V_25 -> V_37 . V_55 ;
}
if ( V_132 )
F_92 ( V_101 -> V_54 ) ;
if ( V_131 & V_133 )
F_93 () ;
return F_94 ( V_101 ) ;
}
static bool
F_95 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_134 )
return false ;
return ( ( V_19 -> V_135 | V_19 -> V_136 ) & 0x7 ) == 0 ;
}
static int
F_96 ( struct V_63 * V_54 ,
struct V_18 * V_19 ,
int V_12 )
{
unsigned V_137 = 0 ;
unsigned V_138 = V_139 / sizeof( struct V_60 ) ;
unsigned V_140 ;
int V_28 ;
V_140 = V_141 ;
if ( F_97 ( V_54 ) )
V_140 |= V_106 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
char T_5 * V_142 = F_57 ( V_19 [ V_28 ] . V_96 ) ;
int V_143 ;
if ( V_19 [ V_28 ] . V_4 & V_140 )
return - V_36 ;
if ( V_19 [ V_28 ] . V_97 > V_138 - V_137 )
return - V_36 ;
V_137 += V_19 [ V_28 ] . V_97 ;
V_143 = V_19 [ V_28 ] . V_97 *
sizeof( struct V_60 ) ;
if ( ! F_98 ( V_144 , V_142 , V_143 ) )
return - V_92 ;
if ( F_99 ( ! V_145 . V_146 ) ) {
if ( F_100 ( V_142 , V_143 ) )
return - V_92 ;
}
}
return 0 ;
}
static struct V_147 *
F_101 ( struct V_63 * V_54 , struct V_22 * V_23 ,
struct V_100 * V_101 , const T_7 V_148 )
{
struct V_147 * V_149 = NULL ;
struct V_150 * V_151 ;
if ( V_101 -> V_152 != V_153 && V_148 != V_154 )
return F_102 ( - V_36 ) ;
V_149 = F_103 ( V_23 -> V_155 , V_148 ) ;
if ( F_18 ( V_149 ) )
return V_149 ;
V_151 = & V_149 -> V_156 ;
if ( V_151 -> V_157 ) {
F_12 ( L_13 , V_148 ) ;
return F_102 ( - V_158 ) ;
}
if ( V_145 . V_159 && ! V_149 -> V_160 [ V_101 -> V_152 ] . V_161 ) {
int V_29 = F_104 ( V_149 , V_101 ) ;
if ( V_29 ) {
F_12 ( L_14 , V_148 , V_29 ) ;
return F_102 ( V_29 ) ;
}
}
return V_149 ;
}
void
F_105 ( struct V_26 * V_16 ,
struct V_100 * V_101 )
{
struct V_162 * V_163 = F_106 ( V_101 ) ;
struct V_8 * V_38 ;
F_64 (vma, vmas, exec_list) {
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
T_7 V_164 = V_25 -> V_37 . V_86 ;
T_7 V_165 = V_25 -> V_37 . V_55 ;
V_25 -> V_37 . V_55 = V_25 -> V_37 . V_89 ;
if ( V_25 -> V_37 . V_55 == 0 )
V_25 -> V_37 . V_88 |= V_25 -> V_37 . V_86 ;
V_25 -> V_37 . V_86 = V_25 -> V_37 . V_88 ;
F_107 ( V_38 , V_101 ) ;
if ( V_25 -> V_37 . V_55 ) {
V_25 -> V_166 = 1 ;
F_108 ( & V_25 -> V_167 , V_163 ) ;
F_109 ( V_25 , V_101 ) ;
V_25 -> V_37 . V_55 &= ~ V_87 ;
}
if ( V_47 -> V_4 & V_111 ) {
F_108 ( & V_25 -> V_168 , V_163 ) ;
if ( V_47 -> V_4 & V_48 ) {
struct V_70 * V_71 = F_110 ( V_101 -> V_54 ) ;
F_77 ( & V_71 -> V_169 [ V_25 -> V_170 ] . V_171 ,
& V_71 -> V_172 . V_173 ) ;
}
}
F_111 ( V_25 , V_164 , V_165 ) ;
}
}
void
F_112 ( struct V_63 * V_54 ,
struct V_22 * V_23 ,
struct V_100 * V_101 ,
struct V_24 * V_25 )
{
V_101 -> V_174 = true ;
( void ) F_113 ( V_101 , V_23 , V_25 ) ;
}
static int
F_114 ( struct V_63 * V_54 ,
struct V_100 * V_101 )
{
struct V_70 * V_71 = V_54 -> V_72 ;
int V_29 , V_28 ;
if ( ! F_115 ( V_54 ) || V_101 != & V_71 -> V_101 [ V_153 ] ) {
F_12 ( L_15 ) ;
return - V_36 ;
}
V_29 = F_116 ( V_101 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_117 ( V_101 , F_118 ( 1 ) ) ;
F_117 ( V_101 , F_119 ( V_28 ) ) ;
F_117 ( V_101 , 0 ) ;
}
F_120 ( V_101 ) ;
return 0 ;
}
static int
F_121 ( struct V_100 * V_101 ,
struct V_175 * V_176 ,
int V_177 , int V_178 )
{
int V_29 ;
if ( V_176 -> V_179 <= V_176 -> y1 || V_176 -> V_180 <= V_176 -> V_181 ||
V_176 -> V_179 <= 0 || V_176 -> V_180 <= 0 ) {
F_122 ( L_16 ,
V_176 -> V_181 , V_176 -> y1 , V_176 -> V_180 , V_176 -> V_179 ) ;
return - V_36 ;
}
if ( F_39 ( V_101 -> V_54 ) -> V_69 >= 4 ) {
V_29 = F_116 ( V_101 , 4 ) ;
if ( V_29 )
return V_29 ;
F_117 ( V_101 , V_182 ) ;
F_117 ( V_101 , ( V_176 -> V_181 & 0xffff ) | V_176 -> y1 << 16 ) ;
F_117 ( V_101 , ( ( V_176 -> V_180 - 1 ) & 0xffff ) | ( V_176 -> V_179 - 1 ) << 16 ) ;
F_117 ( V_101 , V_178 ) ;
} else {
V_29 = F_116 ( V_101 , 6 ) ;
if ( V_29 )
return V_29 ;
F_117 ( V_101 , V_183 ) ;
F_117 ( V_101 , V_177 ) ;
F_117 ( V_101 , ( V_176 -> V_181 & 0xffff ) | V_176 -> y1 << 16 ) ;
F_117 ( V_101 , ( ( V_176 -> V_180 - 1 ) & 0xffff ) | ( V_176 -> V_179 - 1 ) << 16 ) ;
F_117 ( V_101 , V_178 ) ;
F_117 ( V_101 , 0 ) ;
}
F_120 ( V_101 ) ;
return 0 ;
}
static struct V_24 *
F_123 ( struct V_100 * V_101 ,
struct V_18 * V_184 ,
struct V_1 * V_3 ,
struct V_24 * V_185 ,
T_7 V_135 ,
T_7 V_136 ,
bool V_186 ,
T_7 * V_4 )
{
struct V_70 * V_71 = F_110 ( V_185 -> V_37 . V_54 ) ;
struct V_24 * V_187 ;
bool V_102 = false ;
int V_29 ;
V_187 = F_124 ( & V_71 -> V_172 . V_188 ,
V_185 -> V_37 . V_6 ) ;
if ( F_18 ( V_187 ) )
return V_187 ;
V_29 = F_125 ( V_101 ,
V_185 ,
V_187 ,
V_135 ,
V_136 ,
V_186 ) ;
if ( V_29 ) {
if ( V_29 == - V_189 )
return V_185 ;
} else {
struct V_8 * V_38 ;
memset ( V_184 , 0 , sizeof( * V_184 ) ) ;
V_38 = F_126 ( V_187 ) ;
V_38 -> V_40 = V_184 ;
V_38 -> V_40 -> V_4 = V_51 ;
F_14 ( & V_187 -> V_37 ) ;
F_66 ( V_38 , V_101 , & V_102 ) ;
F_15 ( & V_38 -> V_39 , & V_3 -> V_16 ) ;
V_187 -> V_37 . V_88 =
V_185 -> V_37 . V_88 ;
if ( F_97 ( V_54 ) )
* V_4 |= V_190 ;
}
return V_29 ? F_102 ( V_29 ) : V_187 ;
}
int
F_127 ( struct V_63 * V_54 , struct V_22 * V_23 ,
struct V_100 * V_101 ,
struct V_147 * V_149 ,
struct V_2 * args ,
struct V_26 * V_16 ,
struct V_24 * V_185 ,
T_6 V_191 , T_7 V_4 )
{
struct V_175 * V_192 = NULL ;
struct V_70 * V_71 = V_54 -> V_72 ;
T_6 V_193 ;
int V_194 ;
T_7 V_195 ;
int V_28 , V_29 = 0 ;
if ( args -> V_196 != 0 ) {
if ( V_101 != & V_71 -> V_101 [ V_153 ] ) {
F_12 ( L_17 ) ;
return - V_36 ;
}
if ( F_39 ( V_54 ) -> V_69 >= 5 ) {
F_12 ( L_18 ) ;
return - V_36 ;
}
if ( args -> V_196 > V_139 / sizeof( * V_192 ) ) {
F_12 ( L_19 ,
args -> V_196 ) ;
return - V_36 ;
}
V_192 = F_128 ( args -> V_196 ,
sizeof( * V_192 ) ,
V_197 ) ;
if ( V_192 == NULL ) {
V_29 = - V_127 ;
goto error;
}
if ( F_86 ( V_192 ,
F_57 ( args -> V_198 ) ,
sizeof( * V_192 ) * args -> V_196 ) ) {
V_29 = - V_92 ;
goto error;
}
} else {
if ( args -> V_178 == 0xffffffff ) {
F_12 ( L_20 ) ;
args -> V_178 = 0 ;
}
if ( args -> V_177 || args -> V_178 || args -> V_198 ) {
F_12 ( L_21 ) ;
return - V_36 ;
}
}
V_29 = F_89 ( V_101 , V_16 ) ;
if ( V_29 )
goto error;
V_29 = F_129 ( V_101 , V_149 ) ;
if ( V_29 )
goto error;
V_194 = args -> V_4 & V_199 ;
V_195 = V_199 ;
switch ( V_194 ) {
case V_200 :
case V_201 :
case V_202 :
if ( V_194 != 0 && V_101 != & V_71 -> V_101 [ V_153 ] ) {
F_12 ( L_22 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_194 != V_71 -> V_203 ) {
if ( F_39 ( V_54 ) -> V_69 < 4 ) {
F_12 ( L_23 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_54 ) -> V_69 > 5 &&
V_194 == V_202 ) {
F_12 ( L_24 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_54 ) -> V_69 >= 6 )
V_195 &= ~ V_202 ;
}
break;
default:
F_12 ( L_25 , V_194 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_101 == & V_71 -> V_101 [ V_153 ] &&
V_194 != V_71 -> V_203 ) {
V_29 = F_116 ( V_101 , 4 ) ;
if ( V_29 )
goto error;
F_117 ( V_101 , V_204 ) ;
F_117 ( V_101 , F_118 ( 1 ) ) ;
F_117 ( V_101 , V_205 ) ;
F_117 ( V_101 , V_195 << 16 | V_194 ) ;
F_120 ( V_101 ) ;
V_71 -> V_203 = V_194 ;
}
if ( args -> V_4 & V_206 ) {
V_29 = F_114 ( V_54 , V_101 ) ;
if ( V_29 )
goto error;
}
V_193 = args -> V_136 ;
if ( V_192 ) {
for ( V_28 = 0 ; V_28 < args -> V_196 ; V_28 ++ ) {
V_29 = F_121 ( V_101 , & V_192 [ V_28 ] ,
args -> V_177 , args -> V_178 ) ;
if ( V_29 )
goto error;
V_29 = V_101 -> V_207 ( V_101 ,
V_191 , V_193 ,
V_4 ) ;
if ( V_29 )
goto error;
}
} else {
V_29 = V_101 -> V_207 ( V_101 ,
V_191 , V_193 ,
V_4 ) ;
if ( V_29 )
return V_29 ;
}
F_130 ( F_106 ( V_101 ) , V_4 ) ;
F_105 ( V_16 , V_101 ) ;
F_112 ( V_54 , V_23 , V_101 , V_185 ) ;
error:
F_30 ( V_192 ) ;
return V_29 ;
}
static int F_131 ( struct V_63 * V_54 ,
struct V_22 * V_23 )
{
struct V_70 * V_71 = V_54 -> V_72 ;
struct V_208 * V_209 = V_23 -> V_155 ;
if ( V_209 -> V_210 )
return V_209 -> V_210 -> V_152 ;
else {
int V_211 ;
F_85 ( & V_54 -> V_126 ) ;
if ( V_71 -> V_172 . V_212 == 0 ) {
V_211 = V_213 ;
V_71 -> V_172 . V_212 = 1 ;
} else {
V_211 = V_214 ;
V_71 -> V_172 . V_212 = 0 ;
}
V_209 -> V_210 = & V_71 -> V_101 [ V_211 ] ;
F_82 ( & V_54 -> V_126 ) ;
return V_211 ;
}
}
static struct V_24 *
F_132 ( struct V_1 * V_3 )
{
struct V_8 * V_38 = F_133 ( V_3 -> V_16 . V_215 , F_134 ( * V_38 ) , V_39 ) ;
V_38 -> V_40 -> V_4 |= V_107 ;
return V_38 -> V_25 ;
}
static int
F_135 ( struct V_63 * V_54 , void * V_216 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_70 * V_71 = V_54 -> V_72 ;
struct V_1 * V_3 ;
struct V_24 * V_185 ;
struct V_18 V_184 ;
struct V_100 * V_101 ;
struct V_147 * V_149 ;
struct V_20 * V_21 ;
const T_7 V_148 = F_136 ( * args ) ;
T_6 V_191 = args -> V_135 ;
T_7 V_4 ;
int V_29 ;
bool V_114 ;
if ( ! F_95 ( args ) )
return - V_36 ;
V_29 = F_96 ( V_54 , V_19 , args -> V_7 ) ;
if ( V_29 )
return V_29 ;
V_4 = 0 ;
if ( args -> V_4 & V_217 ) {
if ( ! V_23 -> V_186 || ! F_137 ( V_218 ) )
return - V_219 ;
V_4 |= V_190 ;
}
if ( args -> V_4 & V_220 )
V_4 |= V_221 ;
if ( ( args -> V_4 & V_222 ) > V_223 ) {
F_12 ( L_26 ,
( int ) ( args -> V_4 & V_222 ) ) ;
return - V_36 ;
}
if ( ( ( args -> V_4 & V_222 ) != V_224 ) &&
( ( args -> V_4 & V_225 ) != 0 ) ) {
F_12 ( L_27
L_28 , ( int ) ( args -> V_4 ) ) ;
return - V_36 ;
}
if ( ( args -> V_4 & V_222 ) == V_226 )
V_101 = & V_71 -> V_101 [ V_153 ] ;
else if ( ( args -> V_4 & V_222 ) == V_224 ) {
if ( F_138 ( V_54 ) ) {
int V_211 ;
switch ( args -> V_4 & V_225 ) {
case V_227 :
V_211 = F_131 ( V_54 , V_23 ) ;
V_101 = & V_71 -> V_101 [ V_211 ] ;
break;
case V_228 :
V_101 = & V_71 -> V_101 [ V_213 ] ;
break;
case V_229 :
V_101 = & V_71 -> V_101 [ V_214 ] ;
break;
default:
F_12 ( L_29 ,
( int ) ( args -> V_4 & V_225 ) ) ;
return - V_36 ;
}
} else
V_101 = & V_71 -> V_101 [ V_213 ] ;
} else
V_101 = & V_71 -> V_101 [ ( args -> V_4 & V_222 ) - 1 ] ;
if ( ! F_139 ( V_101 ) ) {
F_12 ( L_30 ,
( int ) ( args -> V_4 & V_222 ) ) ;
return - V_36 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_31 , args -> V_7 ) ;
return - V_36 ;
}
F_140 ( V_71 ) ;
V_29 = F_88 ( V_54 ) ;
if ( V_29 )
goto V_230;
V_149 = F_101 ( V_54 , V_23 , V_101 , V_148 ) ;
if ( F_18 ( V_149 ) ) {
F_82 ( & V_54 -> V_126 ) ;
V_29 = F_19 ( V_149 ) ;
goto V_230;
}
F_141 ( V_149 ) ;
if ( V_149 -> V_231 )
V_21 = & V_149 -> V_231 -> V_37 ;
else
V_21 = & V_71 -> V_74 . V_37 ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_142 ( V_149 ) ;
F_82 ( & V_54 -> V_126 ) ;
V_29 = - V_127 ;
goto V_230;
}
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_185 = F_132 ( V_3 ) ;
V_114 = ( args -> V_4 & V_130 ) == 0 ;
V_29 = F_74 ( V_101 , & V_3 -> V_16 , & V_114 ) ;
if ( V_29 )
goto V_34;
if ( V_114 )
V_29 = F_62 ( V_3 ) ;
if ( V_29 ) {
if ( V_29 == - V_92 ) {
V_29 = F_81 ( V_54 , args , V_23 , V_101 ,
V_3 , V_19 ) ;
F_143 ( ! F_144 ( & V_54 -> V_126 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_185 -> V_37 . V_89 ) {
F_12 ( L_32 ) ;
V_29 = - V_36 ;
goto V_34;
}
if ( F_145 ( V_101 ) && args -> V_136 ) {
V_185 = F_123 ( V_101 ,
& V_184 ,
V_3 ,
V_185 ,
args -> V_135 ,
args -> V_136 ,
V_23 -> V_186 ,
& V_4 ) ;
if ( F_18 ( V_185 ) ) {
V_29 = F_19 ( V_185 ) ;
goto V_34;
}
}
V_185 -> V_37 . V_88 |= V_122 ;
if ( V_4 & V_190 ) {
V_29 = F_146 ( V_185 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
V_191 += F_45 ( V_185 ) ;
} else
V_191 += F_147 ( V_185 , V_21 ) ;
V_29 = V_71 -> V_232 . V_233 ( V_54 , V_23 , V_101 , V_149 , args ,
& V_3 -> V_16 , V_185 , V_191 , V_4 ) ;
if ( V_4 & V_190 )
F_148 ( V_185 ) ;
V_34:
F_142 ( V_149 ) ;
F_29 ( V_3 ) ;
F_82 ( & V_54 -> V_126 ) ;
V_230:
F_149 ( V_71 ) ;
return V_29 ;
}
int
F_150 ( struct V_63 * V_54 , void * V_216 ,
struct V_22 * V_23 )
{
struct V_234 * args = V_216 ;
struct V_2 V_235 ;
struct V_236 * V_39 = NULL ;
struct V_18 * V_237 = NULL ;
int V_29 , V_28 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_31 , args -> V_7 ) ;
return - V_36 ;
}
V_39 = F_83 ( sizeof( * V_39 ) , args -> V_7 ) ;
V_237 = F_83 ( sizeof( * V_237 ) , args -> V_7 ) ;
if ( V_39 == NULL || V_237 == NULL ) {
F_12 ( L_33 ,
args -> V_7 ) ;
F_84 ( V_39 ) ;
F_84 ( V_237 ) ;
return - V_127 ;
}
V_29 = F_86 ( V_39 ,
F_57 ( args -> V_238 ) ,
sizeof( * V_39 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_34 ,
args -> V_7 , V_29 ) ;
F_84 ( V_39 ) ;
F_84 ( V_237 ) ;
return - V_92 ;
}
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_237 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_237 [ V_28 ] . V_97 = V_39 [ V_28 ] . V_97 ;
V_237 [ V_28 ] . V_96 = V_39 [ V_28 ] . V_96 ;
V_237 [ V_28 ] . V_110 = V_39 [ V_28 ] . V_110 ;
V_237 [ V_28 ] . V_65 = V_39 [ V_28 ] . V_65 ;
if ( F_39 ( V_54 ) -> V_69 < 4 )
V_237 [ V_28 ] . V_4 = V_111 ;
else
V_237 [ V_28 ] . V_4 = 0 ;
}
V_235 . V_238 = args -> V_238 ;
V_235 . V_7 = args -> V_7 ;
V_235 . V_135 = args -> V_135 ;
V_235 . V_136 = args -> V_136 ;
V_235 . V_177 = args -> V_177 ;
V_235 . V_178 = args -> V_178 ;
V_235 . V_196 = args -> V_196 ;
V_235 . V_198 = args -> V_198 ;
V_235 . V_4 = V_239 ;
F_151 ( V_235 , 0 ) ;
V_29 = F_135 ( V_54 , V_216 , V_23 , & V_235 , V_237 ) ;
if ( ! V_29 ) {
struct V_236 T_5 * V_240 =
F_57 ( args -> V_238 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_87 ( & V_240 [ V_28 ] . V_65 ,
& V_237 [ V_28 ] . V_65 ,
sizeof( V_240 [ V_28 ] . V_65 ) ) ;
if ( V_29 ) {
V_29 = - V_92 ;
F_12 ( L_35
L_36 ,
args -> V_7 , V_29 ) ;
break;
}
}
}
F_84 ( V_39 ) ;
F_84 ( V_237 ) ;
return V_29 ;
}
int
F_152 ( struct V_63 * V_54 , void * V_216 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_216 ;
struct V_18 * V_237 = NULL ;
int V_29 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_139 / sizeof( * V_237 ) ) {
F_12 ( L_37 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_241 != 0 ) {
F_12 ( L_38 ) ;
return - V_36 ;
}
V_237 = F_2 ( sizeof( * V_237 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_237 == NULL )
V_237 = F_83 ( sizeof( * V_237 ) ,
args -> V_7 ) ;
if ( V_237 == NULL ) {
F_12 ( L_33 ,
args -> V_7 ) ;
return - V_127 ;
}
V_29 = F_86 ( V_237 ,
F_57 ( args -> V_238 ) ,
sizeof( * V_237 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_34 ,
args -> V_7 , V_29 ) ;
F_84 ( V_237 ) ;
return - V_92 ;
}
V_29 = F_135 ( V_54 , V_216 , V_23 , args , V_237 ) ;
if ( ! V_29 ) {
struct V_18 T_5 * V_240 =
F_57 ( args -> V_238 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_87 ( & V_240 [ V_28 ] . V_65 ,
& V_237 [ V_28 ] . V_65 ,
sizeof( V_240 [ V_28 ] . V_65 ) ) ;
if ( V_29 ) {
V_29 = - V_92 ;
F_12 ( L_35
L_39 ,
args -> V_7 ) ;
break;
}
}
}
F_84 ( V_237 ) ;
return V_29 ;
}
