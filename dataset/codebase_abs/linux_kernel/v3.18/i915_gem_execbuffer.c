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
V_47 -> V_4 &= ~ ( V_48 | V_49 ) ;
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
return ( F_32 ( V_25 -> V_37 . V_51 ) ||
V_25 -> V_37 . V_52 == V_53 ||
! V_25 -> V_54 ||
V_25 -> V_55 != V_56 ) ;
}
static int
F_33 ( struct V_24 * V_25 ,
struct V_57 * V_58 ,
T_2 V_59 )
{
struct V_60 * V_51 = V_25 -> V_37 . V_51 ;
T_1 V_61 = F_34 ( V_58 -> V_62 ) ;
T_2 V_63 = V_58 -> V_63 + V_59 ;
char * V_64 ;
int V_29 ;
V_29 = F_35 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_64 = F_36 ( F_37 ( V_25 ,
V_58 -> V_62 >> V_65 ) ) ;
* ( T_1 * ) ( V_64 + V_61 ) = F_38 ( V_63 ) ;
if ( F_39 ( V_51 ) -> V_66 >= 8 ) {
V_61 = F_34 ( V_61 + sizeof( T_1 ) ) ;
if ( V_61 == 0 ) {
F_40 ( V_64 ) ;
V_64 = F_36 ( F_37 ( V_25 ,
( V_58 -> V_62 + sizeof( T_1 ) ) >> V_65 ) ) ;
}
* ( T_1 * ) ( V_64 + V_61 ) = F_41 ( V_63 ) ;
}
F_40 ( V_64 ) ;
return 0 ;
}
static int
F_42 ( struct V_24 * V_25 ,
struct V_57 * V_58 ,
T_2 V_59 )
{
struct V_60 * V_51 = V_25 -> V_37 . V_51 ;
struct V_67 * V_68 = V_51 -> V_69 ;
T_2 V_63 = V_58 -> V_63 + V_59 ;
T_2 V_62 ;
void T_3 * V_70 ;
int V_29 ;
V_29 = F_43 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_29 = F_44 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_62 = F_45 ( V_25 ) ;
V_62 += V_58 -> V_62 ;
V_70 = F_46 ( V_68 -> V_71 . V_72 ,
V_62 & V_73 ) ;
F_47 ( F_38 ( V_63 ) , V_70 + F_34 ( V_62 ) ) ;
if ( F_39 ( V_51 ) -> V_66 >= 8 ) {
V_62 += sizeof( T_1 ) ;
if ( F_34 ( V_62 ) == 0 ) {
F_48 ( V_70 ) ;
V_70 =
F_46 ( V_68 -> V_71 . V_72 ,
V_62 ) ;
}
F_47 ( F_41 ( V_63 ) ,
V_70 + F_34 ( V_62 ) ) ;
}
F_48 ( V_70 ) ;
return 0 ;
}
static int
F_49 ( struct V_24 * V_25 ,
struct V_1 * V_3 ,
struct V_57 * V_58 )
{
struct V_60 * V_51 = V_25 -> V_37 . V_51 ;
struct V_74 * V_75 ;
struct V_24 * V_76 ;
struct V_8 * V_77 ;
T_2 V_59 ;
int V_29 ;
V_77 = F_23 ( V_3 , V_58 -> V_78 ) ;
if ( F_50 ( V_77 == NULL ) )
return - V_33 ;
V_76 = V_77 -> V_25 ;
V_75 = & V_77 -> V_25 -> V_37 ;
V_59 = V_77 -> V_46 . V_79 ;
if ( F_50 ( F_51 ( V_51 ) &&
V_58 -> V_52 == V_80 &&
! V_76 -> V_81 ) ) {
struct V_8 * V_38 =
F_16 ( & V_76 -> V_82 ,
F_52 ( * V_38 ) , V_83 ) ;
V_38 -> V_84 ( V_38 , V_76 -> V_55 , V_85 ) ;
}
if ( F_50 ( V_58 -> V_52 & ( V_58 -> V_52 - 1 ) ) ) {
F_12 ( L_4
L_5
L_6 ,
V_25 , V_58 -> V_78 ,
( int ) V_58 -> V_62 ,
V_58 -> V_86 ,
V_58 -> V_52 ) ;
return - V_36 ;
}
if ( F_50 ( ( V_58 -> V_52 | V_58 -> V_86 )
& ~ V_87 ) ) {
F_12 ( L_7
L_5
L_6 ,
V_25 , V_58 -> V_78 ,
( int ) V_58 -> V_62 ,
V_58 -> V_86 ,
V_58 -> V_52 ) ;
return - V_36 ;
}
V_75 -> V_88 |= V_58 -> V_86 ;
V_75 -> V_89 |= V_58 -> V_52 ;
if ( V_59 == V_58 -> V_90 )
return 0 ;
if ( F_50 ( V_58 -> V_62 >
V_25 -> V_37 . V_6 - ( F_39 ( V_51 ) -> V_66 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_8
L_9 ,
V_25 , V_58 -> V_78 ,
( int ) V_58 -> V_62 ,
( int ) V_25 -> V_37 . V_6 ) ;
return - V_36 ;
}
if ( F_50 ( V_58 -> V_62 & 3 ) ) {
F_12 ( L_10
L_11 ,
V_25 , V_58 -> V_78 ,
( int ) V_58 -> V_62 ) ;
return - V_36 ;
}
if ( V_25 -> V_91 && F_53 () )
return - V_92 ;
if ( F_31 ( V_25 ) )
V_29 = F_33 ( V_25 , V_58 , V_59 ) ;
else
V_29 = F_42 ( V_25 , V_58 , V_59 ) ;
if ( V_29 )
return V_29 ;
V_58 -> V_90 = V_59 ;
return 0 ;
}
static int
F_54 ( struct V_8 * V_38 ,
struct V_1 * V_3 )
{
#define F_55 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_57 V_93 [ F_55 ( 512 ) ] ;
struct V_57 T_5 * V_94 ;
struct V_18 * V_47 = V_38 -> V_40 ;
int V_95 , V_29 ;
V_94 = F_56 ( V_47 -> V_96 ) ;
V_95 = V_47 -> V_97 ;
while ( V_95 ) {
struct V_57 * V_98 = V_93 ;
int V_12 = V_95 ;
if ( V_12 > F_57 ( V_93 ) )
V_12 = F_57 ( V_93 ) ;
V_95 -= V_12 ;
if ( F_58 ( V_98 , V_94 , V_12 * sizeof( V_98 [ 0 ] ) ) )
return - V_92 ;
do {
T_6 V_62 = V_98 -> V_90 ;
V_29 = F_49 ( V_38 -> V_25 , V_3 , V_98 ) ;
if ( V_29 )
return V_29 ;
if ( V_98 -> V_90 != V_62 &&
F_59 ( & V_94 -> V_90 ,
& V_98 -> V_90 ,
sizeof( V_98 -> V_90 ) ) ) {
return - V_92 ;
}
V_94 ++ ;
V_98 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_55
}
static int
F_60 ( struct V_8 * V_38 ,
struct V_1 * V_3 ,
struct V_57 * V_99 )
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
F_61 ( struct V_1 * V_3 )
{
struct V_8 * V_38 ;
int V_29 = 0 ;
F_62 () ;
F_63 (vma, &eb->vmas, exec_list) {
V_29 = F_54 ( V_38 , V_3 ) ;
if ( V_29 )
break;
}
F_64 () ;
return V_29 ;
}
static int
F_65 ( struct V_8 * V_38 ,
struct V_100 * V_101 ,
bool * V_102 )
{
struct V_24 * V_25 = V_38 -> V_25 ;
struct V_18 * V_47 = V_38 -> V_40 ;
T_2 V_4 ;
int V_29 ;
V_4 = 0 ;
if ( V_47 -> V_4 & V_103 )
V_4 |= V_104 ;
if ( V_47 -> V_4 & V_105 )
V_4 |= V_106 ;
if ( V_47 -> V_4 & V_107 )
V_4 |= V_108 | V_109 ;
V_29 = F_66 ( V_25 , V_38 -> V_21 , V_47 -> V_110 , V_4 ) ;
if ( V_29 )
return V_29 ;
V_47 -> V_4 |= V_49 ;
if ( V_47 -> V_4 & V_111 ) {
V_29 = F_67 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_68 ( V_25 ) )
V_47 -> V_4 |= V_48 ;
}
if ( V_47 -> V_62 != V_38 -> V_46 . V_79 ) {
V_47 -> V_62 = V_38 -> V_46 . V_79 ;
* V_102 = true ;
}
if ( V_47 -> V_4 & V_112 ) {
V_25 -> V_37 . V_88 = V_113 ;
V_25 -> V_37 . V_89 = V_113 ;
}
return 0 ;
}
static bool
F_69 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
if ( V_47 -> V_97 == 0 )
return false ;
if ( ! F_70 ( V_38 -> V_21 ) )
return false ;
if ( F_32 ( V_38 -> V_25 -> V_37 . V_51 ) )
return false ;
if ( V_38 -> V_25 -> V_37 . V_52 == V_53 )
return false ;
return true ;
}
static bool
F_71 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
F_72 ( V_47 -> V_4 & V_103 &&
! F_70 ( V_38 -> V_21 ) ) ;
if ( V_47 -> V_110 &&
V_38 -> V_46 . V_79 & ( V_47 -> V_110 - 1 ) )
return true ;
if ( V_47 -> V_4 & V_103 && ! V_25 -> V_54 )
return true ;
if ( V_47 -> V_4 & V_107 &&
V_38 -> V_46 . V_79 < V_108 )
return true ;
return false ;
}
static int
F_73 ( struct V_100 * V_101 ,
struct V_26 * V_16 ,
bool * V_114 )
{
struct V_24 * V_25 ;
struct V_8 * V_38 ;
struct V_20 * V_21 ;
struct V_26 V_115 ;
bool V_116 = F_39 ( V_101 -> V_51 ) -> V_66 < 4 ;
int V_117 ;
F_74 ( V_101 ) ;
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
V_119 = V_118 || F_69 ( V_38 ) ;
if ( V_119 ) {
V_47 -> V_4 |= V_103 ;
F_75 ( & V_38 -> V_39 , & V_115 ) ;
} else
F_76 ( & V_38 -> V_39 , & V_115 ) ;
V_25 -> V_37 . V_88 = V_87 & ~ V_122 ;
V_25 -> V_37 . V_89 = 0 ;
}
F_77 ( & V_115 , V_16 ) ;
V_117 = 0 ;
do {
int V_29 = 0 ;
F_63 (vma, vmas, exec_list) {
if ( ! F_27 ( & V_38 -> V_46 ) )
continue;
if ( F_71 ( V_38 ) )
V_29 = F_78 ( V_38 ) ;
else
V_29 = F_65 ( V_38 , V_101 , V_114 ) ;
if ( V_29 )
goto V_34;
}
F_63 (vma, vmas, exec_list) {
if ( F_27 ( & V_38 -> V_46 ) )
continue;
V_29 = F_65 ( V_38 , V_101 , V_114 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_123 || V_117 ++ )
return V_29 ;
F_63 (vma, vmas, exec_list)
F_26 ( V_38 ) ;
V_29 = F_79 ( V_21 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_80 ( struct V_60 * V_51 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_100 * V_101 ,
struct V_1 * V_3 ,
struct V_18 * V_19 )
{
struct V_57 * V_58 ;
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
F_81 ( & V_51 -> V_126 ) ;
V_125 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
V_125 += V_19 [ V_28 ] . V_97 ;
V_124 = F_82 ( V_12 , sizeof( * V_124 ) ) ;
V_58 = F_82 ( V_125 , sizeof( * V_58 ) ) ;
if ( V_58 == NULL || V_124 == NULL ) {
F_83 ( V_58 ) ;
F_83 ( V_124 ) ;
F_84 ( & V_51 -> V_126 ) ;
return - V_127 ;
}
V_125 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
struct V_57 T_5 * V_94 ;
T_6 V_128 = ( T_6 ) - 1 ;
int V_129 ;
V_94 = F_56 ( V_19 [ V_28 ] . V_96 ) ;
if ( F_85 ( V_58 + V_125 , V_94 ,
V_19 [ V_28 ] . V_97 * sizeof( * V_58 ) ) ) {
V_29 = - V_92 ;
F_84 ( & V_51 -> V_126 ) ;
goto V_34;
}
for ( V_129 = 0 ; V_129 < V_19 [ V_28 ] . V_97 ; V_129 ++ ) {
if ( F_86 ( & V_94 [ V_129 ] . V_90 ,
& V_128 ,
sizeof( V_128 ) ) ) {
V_29 = - V_92 ;
F_84 ( & V_51 -> V_126 ) ;
goto V_34;
}
}
V_124 [ V_28 ] = V_125 ;
V_125 += V_19 [ V_28 ] . V_97 ;
}
V_29 = F_87 ( V_51 ) ;
if ( V_29 ) {
F_84 ( & V_51 -> V_126 ) ;
goto V_34;
}
F_6 ( V_3 ) ;
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_114 = ( args -> V_4 & V_130 ) == 0 ;
V_29 = F_73 ( V_101 , & V_3 -> V_16 , & V_114 ) ;
if ( V_29 )
goto V_34;
F_63 (vma, &eb->vmas, exec_list) {
int V_62 = V_38 -> V_40 - V_19 ;
V_29 = F_60 ( V_38 , V_3 ,
V_58 + V_124 [ V_62 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_83 ( V_58 ) ;
F_83 ( V_124 ) ;
return V_29 ;
}
static int
F_88 ( struct V_100 * V_101 ,
struct V_26 * V_16 )
{
struct V_8 * V_38 ;
T_1 V_131 = 0 ;
bool V_132 = false ;
int V_29 ;
F_63 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
V_29 = F_89 ( V_25 , V_101 ) ;
if ( V_29 )
return V_29 ;
if ( V_25 -> V_37 . V_52 & V_53 )
V_132 |= F_90 ( V_25 , false ) ;
V_131 |= V_25 -> V_37 . V_52 ;
}
if ( V_132 )
F_91 ( V_101 -> V_51 ) ;
if ( V_131 & V_133 )
F_92 () ;
return F_93 ( V_101 ) ;
}
static bool
F_94 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_134 )
return false ;
return ( ( V_19 -> V_135 | V_19 -> V_136 ) & 0x7 ) == 0 ;
}
static int
F_95 ( struct V_60 * V_51 ,
struct V_18 * V_19 ,
int V_12 )
{
unsigned V_137 = 0 ;
unsigned V_138 = V_139 / sizeof( struct V_57 ) ;
unsigned V_140 ;
int V_28 ;
V_140 = V_141 ;
if ( F_96 ( V_51 ) )
V_140 |= V_105 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
char T_5 * V_142 = F_56 ( V_19 [ V_28 ] . V_96 ) ;
int V_143 ;
if ( V_19 [ V_28 ] . V_4 & V_140 )
return - V_36 ;
if ( V_19 [ V_28 ] . V_97 > V_138 - V_137 )
return - V_36 ;
V_137 += V_19 [ V_28 ] . V_97 ;
V_143 = V_19 [ V_28 ] . V_97 *
sizeof( struct V_57 ) ;
if ( ! F_97 ( V_144 , V_142 , V_143 ) )
return - V_92 ;
if ( F_98 ( ! V_145 . V_146 ) ) {
if ( F_99 ( V_142 , V_143 ) )
return - V_92 ;
}
}
return 0 ;
}
static struct V_147 *
F_100 ( struct V_60 * V_51 , struct V_22 * V_23 ,
struct V_100 * V_101 , const T_7 V_148 )
{
struct V_147 * V_149 = NULL ;
struct V_150 * V_151 ;
if ( V_101 -> V_152 != V_153 && V_148 != V_154 )
return F_101 ( - V_36 ) ;
V_149 = F_102 ( V_23 -> V_155 , V_148 ) ;
if ( F_18 ( V_149 ) )
return V_149 ;
V_151 = & V_149 -> V_156 ;
if ( V_151 -> V_157 ) {
F_12 ( L_12 , V_148 ) ;
return F_101 ( - V_158 ) ;
}
if ( V_145 . V_159 && ! V_149 -> V_160 [ V_101 -> V_152 ] . V_161 ) {
int V_29 = F_103 ( V_149 , V_101 ) ;
if ( V_29 ) {
F_12 ( L_13 , V_148 , V_29 ) ;
return F_101 ( V_29 ) ;
}
}
return V_149 ;
}
void
F_104 ( struct V_26 * V_16 ,
struct V_100 * V_101 )
{
T_7 V_162 = F_105 ( V_101 ) ;
struct V_8 * V_38 ;
F_63 (vma, vmas, exec_list) {
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
T_7 V_163 = V_25 -> V_37 . V_86 ;
T_7 V_164 = V_25 -> V_37 . V_52 ;
V_25 -> V_37 . V_52 = V_25 -> V_37 . V_89 ;
if ( V_25 -> V_37 . V_52 == 0 )
V_25 -> V_37 . V_88 |= V_25 -> V_37 . V_86 ;
V_25 -> V_37 . V_86 = V_25 -> V_37 . V_88 ;
F_106 ( V_38 , V_101 ) ;
if ( V_25 -> V_37 . V_52 ) {
V_25 -> V_165 = 1 ;
V_25 -> V_166 = V_162 ;
F_107 ( V_25 , V_101 ) ;
V_25 -> V_37 . V_52 &= ~ V_87 ;
}
if ( V_47 -> V_4 & V_111 ) {
V_25 -> V_167 = V_162 ;
if ( V_47 -> V_4 & V_48 ) {
struct V_67 * V_68 = F_108 ( V_101 -> V_51 ) ;
F_76 ( & V_68 -> V_168 [ V_25 -> V_169 ] . V_170 ,
& V_68 -> V_171 . V_172 ) ;
}
}
F_109 ( V_25 , V_163 , V_164 ) ;
}
}
void
F_110 ( struct V_60 * V_51 ,
struct V_22 * V_23 ,
struct V_100 * V_101 ,
struct V_24 * V_25 )
{
V_101 -> V_173 = true ;
( void ) F_111 ( V_101 , V_23 , V_25 , NULL ) ;
}
static int
F_112 ( struct V_60 * V_51 ,
struct V_100 * V_101 )
{
struct V_67 * V_68 = V_51 -> V_69 ;
int V_29 , V_28 ;
if ( ! F_113 ( V_51 ) || V_101 != & V_68 -> V_101 [ V_153 ] ) {
F_12 ( L_14 ) ;
return - V_36 ;
}
V_29 = F_114 ( V_101 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_115 ( V_101 , F_116 ( 1 ) ) ;
F_115 ( V_101 , F_117 ( V_28 ) ) ;
F_115 ( V_101 , 0 ) ;
}
F_118 ( V_101 ) ;
return 0 ;
}
int
F_119 ( struct V_60 * V_51 , struct V_22 * V_23 ,
struct V_100 * V_101 ,
struct V_147 * V_149 ,
struct V_2 * args ,
struct V_26 * V_16 ,
struct V_24 * V_174 ,
T_6 V_175 , T_7 V_4 )
{
struct V_176 * V_177 = NULL ;
struct V_67 * V_68 = V_51 -> V_69 ;
T_6 V_178 ;
int V_179 ;
T_7 V_180 ;
int V_28 , V_29 = 0 ;
if ( args -> V_181 != 0 ) {
if ( V_101 != & V_68 -> V_101 [ V_153 ] ) {
F_12 ( L_15 ) ;
return - V_36 ;
}
if ( F_39 ( V_51 ) -> V_66 >= 5 ) {
F_12 ( L_16 ) ;
return - V_36 ;
}
if ( args -> V_181 > V_139 / sizeof( * V_177 ) ) {
F_12 ( L_17 ,
args -> V_181 ) ;
return - V_36 ;
}
V_177 = F_120 ( args -> V_181 ,
sizeof( * V_177 ) ,
V_182 ) ;
if ( V_177 == NULL ) {
V_29 = - V_127 ;
goto error;
}
if ( F_85 ( V_177 ,
F_56 ( args -> V_183 ) ,
sizeof( * V_177 ) * args -> V_181 ) ) {
V_29 = - V_92 ;
goto error;
}
} else {
if ( args -> V_184 == 0xffffffff ) {
F_12 ( L_18 ) ;
args -> V_184 = 0 ;
}
if ( args -> V_185 || args -> V_184 || args -> V_183 ) {
F_12 ( L_19 ) ;
return - V_36 ;
}
}
V_29 = F_88 ( V_101 , V_16 ) ;
if ( V_29 )
goto error;
V_29 = F_121 ( V_101 , V_149 ) ;
if ( V_29 )
goto error;
V_179 = args -> V_4 & V_186 ;
V_180 = V_186 ;
switch ( V_179 ) {
case V_187 :
case V_188 :
case V_189 :
if ( V_179 != 0 && V_101 != & V_68 -> V_101 [ V_153 ] ) {
F_12 ( L_20 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_179 != V_68 -> V_190 ) {
if ( F_39 ( V_51 ) -> V_66 < 4 ) {
F_12 ( L_21 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_51 ) -> V_66 > 5 &&
V_179 == V_189 ) {
F_12 ( L_22 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_51 ) -> V_66 >= 6 )
V_180 &= ~ V_189 ;
}
break;
default:
F_12 ( L_23 , V_179 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_101 == & V_68 -> V_101 [ V_153 ] &&
V_179 != V_68 -> V_190 ) {
V_29 = F_114 ( V_101 , 4 ) ;
if ( V_29 )
goto error;
F_115 ( V_101 , V_191 ) ;
F_115 ( V_101 , F_116 ( 1 ) ) ;
F_115 ( V_101 , V_192 ) ;
F_115 ( V_101 , V_180 << 16 | V_179 ) ;
F_118 ( V_101 ) ;
V_68 -> V_190 = V_179 ;
}
if ( args -> V_4 & V_193 ) {
V_29 = F_112 ( V_51 , V_101 ) ;
if ( V_29 )
goto error;
}
V_178 = args -> V_136 ;
if ( V_177 ) {
for ( V_28 = 0 ; V_28 < args -> V_181 ; V_28 ++ ) {
V_29 = F_122 ( V_51 , & V_177 [ V_28 ] ,
args -> V_185 , args -> V_184 ) ;
if ( V_29 )
goto error;
V_29 = V_101 -> V_194 ( V_101 ,
V_175 , V_178 ,
V_4 ) ;
if ( V_29 )
goto error;
}
} else {
V_29 = V_101 -> V_194 ( V_101 ,
V_175 , V_178 ,
V_4 ) ;
if ( V_29 )
return V_29 ;
}
F_123 ( V_101 , F_105 ( V_101 ) , V_4 ) ;
F_104 ( V_16 , V_101 ) ;
F_110 ( V_51 , V_23 , V_101 , V_174 ) ;
error:
F_30 ( V_177 ) ;
return V_29 ;
}
static int F_124 ( struct V_60 * V_51 ,
struct V_22 * V_23 )
{
struct V_67 * V_68 = V_51 -> V_69 ;
struct V_195 * V_196 = V_23 -> V_155 ;
if ( V_196 -> V_197 )
return V_196 -> V_197 -> V_152 ;
else {
int V_198 ;
F_84 ( & V_51 -> V_126 ) ;
if ( V_68 -> V_171 . V_199 == 0 ) {
V_198 = V_200 ;
V_68 -> V_171 . V_199 = 1 ;
} else {
V_198 = V_201 ;
V_68 -> V_171 . V_199 = 0 ;
}
V_196 -> V_197 = & V_68 -> V_101 [ V_198 ] ;
F_81 ( & V_51 -> V_126 ) ;
return V_198 ;
}
}
static struct V_24 *
F_125 ( struct V_1 * V_3 )
{
struct V_8 * V_38 = F_126 ( V_3 -> V_16 . V_202 , F_52 ( * V_38 ) , V_39 ) ;
V_38 -> V_40 -> V_4 |= V_107 ;
return V_38 -> V_25 ;
}
static int
F_127 ( struct V_60 * V_51 , void * V_203 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_67 * V_68 = V_51 -> V_69 ;
struct V_1 * V_3 ;
struct V_24 * V_174 ;
struct V_100 * V_101 ;
struct V_147 * V_149 ;
struct V_20 * V_21 ;
const T_7 V_148 = F_128 ( * args ) ;
T_6 V_175 = args -> V_135 ;
T_7 V_4 ;
int V_29 ;
bool V_114 ;
if ( ! F_94 ( args ) )
return - V_36 ;
V_29 = F_95 ( V_51 , V_19 , args -> V_7 ) ;
if ( V_29 )
return V_29 ;
V_4 = 0 ;
if ( args -> V_4 & V_204 ) {
if ( ! V_23 -> V_205 || ! F_129 ( V_206 ) )
return - V_207 ;
V_4 |= V_208 ;
}
if ( args -> V_4 & V_209 )
V_4 |= V_210 ;
if ( ( args -> V_4 & V_211 ) > V_212 ) {
F_12 ( L_24 ,
( int ) ( args -> V_4 & V_211 ) ) ;
return - V_36 ;
}
if ( ( args -> V_4 & V_211 ) == V_213 )
V_101 = & V_68 -> V_101 [ V_153 ] ;
else if ( ( args -> V_4 & V_211 ) == V_214 ) {
if ( F_130 ( V_51 ) ) {
int V_198 ;
V_198 = F_124 ( V_51 , V_23 ) ;
V_101 = & V_68 -> V_101 [ V_198 ] ;
} else
V_101 = & V_68 -> V_101 [ V_200 ] ;
} else
V_101 = & V_68 -> V_101 [ ( args -> V_4 & V_211 ) - 1 ] ;
if ( ! F_131 ( V_101 ) ) {
F_12 ( L_25 ,
( int ) ( args -> V_4 & V_211 ) ) ;
return - V_36 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_26 , args -> V_7 ) ;
return - V_36 ;
}
F_132 ( V_68 ) ;
V_29 = F_87 ( V_51 ) ;
if ( V_29 )
goto V_215;
if ( V_68 -> V_216 . V_217 ) {
F_81 ( & V_51 -> V_126 ) ;
V_29 = - V_218 ;
goto V_215;
}
V_149 = F_100 ( V_51 , V_23 , V_101 , V_148 ) ;
if ( F_18 ( V_149 ) ) {
F_81 ( & V_51 -> V_126 ) ;
V_29 = F_19 ( V_149 ) ;
goto V_215;
}
F_133 ( V_149 ) ;
if ( V_149 -> V_219 )
V_21 = & V_149 -> V_219 -> V_37 ;
else
V_21 = & V_68 -> V_71 . V_37 ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_134 ( V_149 ) ;
F_81 ( & V_51 -> V_126 ) ;
V_29 = - V_127 ;
goto V_215;
}
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_174 = F_125 ( V_3 ) ;
V_114 = ( args -> V_4 & V_130 ) == 0 ;
V_29 = F_73 ( V_101 , & V_3 -> V_16 , & V_114 ) ;
if ( V_29 )
goto V_34;
if ( V_114 )
V_29 = F_61 ( V_3 ) ;
if ( V_29 ) {
if ( V_29 == - V_92 ) {
V_29 = F_80 ( V_51 , args , V_23 , V_101 ,
V_3 , V_19 ) ;
F_135 ( ! F_136 ( & V_51 -> V_126 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_174 -> V_37 . V_89 ) {
F_12 ( L_27 ) ;
V_29 = - V_36 ;
goto V_34;
}
V_174 -> V_37 . V_88 |= V_122 ;
if ( F_137 ( V_101 ) ) {
V_29 = F_138 ( V_101 ,
V_174 ,
args -> V_135 ,
V_23 -> V_205 ) ;
if ( V_29 )
goto V_34;
}
if ( V_4 & V_208 ) {
V_29 = F_139 ( V_174 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
V_175 += F_45 ( V_174 ) ;
} else
V_175 += F_140 ( V_174 , V_21 ) ;
V_29 = V_68 -> V_220 . V_221 ( V_51 , V_23 , V_101 , V_149 , args ,
& V_3 -> V_16 , V_174 , V_175 , V_4 ) ;
if ( V_4 & V_208 )
F_141 ( V_174 ) ;
V_34:
F_134 ( V_149 ) ;
F_29 ( V_3 ) ;
F_81 ( & V_51 -> V_126 ) ;
V_215:
F_142 ( V_68 ) ;
return V_29 ;
}
int
F_143 ( struct V_60 * V_51 , void * V_203 ,
struct V_22 * V_23 )
{
struct V_222 * args = V_203 ;
struct V_2 V_223 ;
struct V_224 * V_39 = NULL ;
struct V_18 * V_225 = NULL ;
int V_29 , V_28 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_26 , args -> V_7 ) ;
return - V_36 ;
}
V_39 = F_82 ( sizeof( * V_39 ) , args -> V_7 ) ;
V_225 = F_82 ( sizeof( * V_225 ) , args -> V_7 ) ;
if ( V_39 == NULL || V_225 == NULL ) {
F_12 ( L_28 ,
args -> V_7 ) ;
F_83 ( V_39 ) ;
F_83 ( V_225 ) ;
return - V_127 ;
}
V_29 = F_85 ( V_39 ,
F_56 ( args -> V_226 ) ,
sizeof( * V_39 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_29 ,
args -> V_7 , V_29 ) ;
F_83 ( V_39 ) ;
F_83 ( V_225 ) ;
return - V_92 ;
}
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_225 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_225 [ V_28 ] . V_97 = V_39 [ V_28 ] . V_97 ;
V_225 [ V_28 ] . V_96 = V_39 [ V_28 ] . V_96 ;
V_225 [ V_28 ] . V_110 = V_39 [ V_28 ] . V_110 ;
V_225 [ V_28 ] . V_62 = V_39 [ V_28 ] . V_62 ;
if ( F_39 ( V_51 ) -> V_66 < 4 )
V_225 [ V_28 ] . V_4 = V_111 ;
else
V_225 [ V_28 ] . V_4 = 0 ;
}
V_223 . V_226 = args -> V_226 ;
V_223 . V_7 = args -> V_7 ;
V_223 . V_135 = args -> V_135 ;
V_223 . V_136 = args -> V_136 ;
V_223 . V_185 = args -> V_185 ;
V_223 . V_184 = args -> V_184 ;
V_223 . V_181 = args -> V_181 ;
V_223 . V_183 = args -> V_183 ;
V_223 . V_4 = V_227 ;
F_144 ( V_223 , 0 ) ;
V_29 = F_127 ( V_51 , V_203 , V_23 , & V_223 , V_225 ) ;
if ( ! V_29 ) {
struct V_224 T_5 * V_228 =
F_56 ( args -> V_226 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_86 ( & V_228 [ V_28 ] . V_62 ,
& V_225 [ V_28 ] . V_62 ,
sizeof( V_228 [ V_28 ] . V_62 ) ) ;
if ( V_29 ) {
V_29 = - V_92 ;
F_12 ( L_30
L_31 ,
args -> V_7 , V_29 ) ;
break;
}
}
}
F_83 ( V_39 ) ;
F_83 ( V_225 ) ;
return V_29 ;
}
int
F_145 ( struct V_60 * V_51 , void * V_203 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_203 ;
struct V_18 * V_225 = NULL ;
int V_29 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_139 / sizeof( * V_225 ) ) {
F_12 ( L_32 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_229 != 0 ) {
F_12 ( L_33 ) ;
return - V_36 ;
}
V_225 = F_2 ( sizeof( * V_225 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_225 == NULL )
V_225 = F_82 ( sizeof( * V_225 ) ,
args -> V_7 ) ;
if ( V_225 == NULL ) {
F_12 ( L_28 ,
args -> V_7 ) ;
return - V_127 ;
}
V_29 = F_85 ( V_225 ,
F_56 ( args -> V_226 ) ,
sizeof( * V_225 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_29 ,
args -> V_7 , V_29 ) ;
F_83 ( V_225 ) ;
return - V_92 ;
}
V_29 = F_127 ( V_51 , V_203 , V_23 , args , V_225 ) ;
if ( ! V_29 ) {
struct V_18 T_5 * V_228 =
F_56 ( args -> V_226 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_86 ( & V_228 [ V_28 ] . V_62 ,
& V_225 [ V_28 ] . V_62 ,
sizeof( V_228 [ V_28 ] . V_62 ) ) ;
if ( V_29 ) {
V_29 = - V_92 ;
F_12 ( L_30
L_34 ,
args -> V_7 ) ;
break;
}
}
}
F_83 ( V_225 ) ;
return V_29 ;
}
