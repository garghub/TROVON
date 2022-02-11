static struct V_1 *
F_1 ( struct V_2 * args , struct V_3 * V_4 )
{
struct V_1 * V_5 = NULL ;
if ( args -> V_6 & V_7 ) {
unsigned V_8 = args -> V_9 ;
V_8 *= sizeof( struct V_10 * ) ;
V_8 += sizeof( struct V_1 ) ;
V_5 = F_2 ( V_8 , V_11 | V_12 | V_13 ) ;
}
if ( V_5 == NULL ) {
unsigned V_8 = args -> V_9 ;
unsigned V_14 = V_15 / sizeof( struct V_16 ) / 2 ;
F_3 ( V_15 / sizeof( struct V_16 ) ) ;
while ( V_14 > 2 * V_8 )
V_14 >>= 1 ;
V_5 = F_4 ( V_14 * sizeof( struct V_16 ) +
sizeof( struct V_1 ) ,
V_11 ) ;
if ( V_5 == NULL )
return V_5 ;
V_5 -> V_17 = V_14 - 1 ;
} else
V_5 -> V_17 = - args -> V_9 ;
F_5 ( & V_5 -> V_18 ) ;
return V_5 ;
}
static void
F_6 ( struct V_1 * V_5 )
{
if ( V_5 -> V_17 >= 0 )
memset ( V_5 -> V_19 , 0 , ( V_5 -> V_17 + 1 ) * sizeof( struct V_16 ) ) ;
}
static int
F_7 ( struct V_1 * V_5 ,
struct V_20 * V_21 ,
const struct V_2 * args ,
struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_26 V_27 ;
int V_28 , V_29 ;
F_5 ( & V_27 ) ;
F_8 ( & V_23 -> V_30 ) ;
for ( V_28 = 0 ; V_28 < args -> V_9 ; V_28 ++ ) {
V_25 = F_9 ( F_10 ( & V_23 -> V_31 , V_21 [ V_28 ] . V_32 ) ) ;
if ( V_25 == NULL ) {
F_11 ( & V_23 -> V_30 ) ;
F_12 ( L_1 ,
V_21 [ V_28 ] . V_32 , V_28 ) ;
V_29 = - V_33 ;
goto V_34;
}
if ( ! F_13 ( & V_25 -> V_35 ) ) {
F_11 ( & V_23 -> V_30 ) ;
F_12 ( L_2 ,
V_25 , V_21 [ V_28 ] . V_32 , V_28 ) ;
V_29 = - V_36 ;
goto V_34;
}
F_14 ( & V_25 -> V_37 ) ;
F_15 ( & V_25 -> V_35 , & V_27 ) ;
}
F_11 ( & V_23 -> V_30 ) ;
V_28 = 0 ;
while ( ! F_13 ( & V_27 ) ) {
struct V_10 * V_38 ;
V_25 = F_16 ( & V_27 ,
struct V_24 ,
V_35 ) ;
V_38 = F_17 ( V_25 , V_4 ) ;
if ( F_18 ( V_38 ) ) {
F_12 ( L_3 ) ;
V_29 = F_19 ( V_38 ) ;
goto V_34;
}
F_15 ( & V_38 -> V_39 , & V_5 -> V_18 ) ;
F_20 ( & V_25 -> V_35 ) ;
V_38 -> V_40 = & V_21 [ V_28 ] ;
if ( V_5 -> V_17 < 0 ) {
V_5 -> V_41 [ V_28 ] = V_38 ;
} else {
T_1 V_32 = args -> V_6 & V_7 ? V_28 : V_21 [ V_28 ] . V_32 ;
V_38 -> V_42 = V_32 ;
F_21 ( & V_38 -> V_43 ,
& V_5 -> V_19 [ V_32 & V_5 -> V_17 ] ) ;
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
static struct V_10 * F_23 ( struct V_1 * V_5 , unsigned long V_32 )
{
if ( V_5 -> V_17 < 0 ) {
if ( V_32 >= - V_5 -> V_17 )
return NULL ;
return V_5 -> V_41 [ V_32 ] ;
} else {
struct V_16 * V_44 ;
struct V_45 * V_46 ;
V_44 = & V_5 -> V_19 [ V_32 & V_5 -> V_17 ] ;
F_24 (node, head) {
struct V_10 * V_38 ;
V_38 = F_25 ( V_46 , struct V_10 , V_43 ) ;
if ( V_38 -> V_42 == V_32 )
return V_38 ;
}
return NULL ;
}
}
static void
F_26 ( struct V_10 * V_38 )
{
struct V_20 * V_47 ;
struct V_24 * V_25 = V_38 -> V_25 ;
if ( ! F_27 ( & V_38 -> V_46 ) )
return;
V_47 = V_38 -> V_40 ;
if ( V_47 -> V_6 & V_48 )
F_28 ( V_25 ) ;
if ( V_47 -> V_6 & V_49 )
F_29 ( V_25 ) ;
V_47 -> V_6 &= ~ ( V_48 | V_49 ) ;
}
static void F_30 ( struct V_1 * V_5 )
{
while ( ! F_13 ( & V_5 -> V_18 ) ) {
struct V_10 * V_38 ;
V_38 = F_16 ( & V_5 -> V_18 ,
struct V_10 ,
V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_31 ( V_5 ) ;
}
static inline int F_32 ( struct V_24 * V_25 )
{
return ( F_33 ( V_25 -> V_37 . V_50 ) ||
V_25 -> V_37 . V_51 == V_52 ||
! V_25 -> V_53 ||
V_25 -> V_54 != V_55 ) ;
}
static int
F_34 ( struct V_24 * V_25 ,
struct V_56 * V_57 )
{
struct V_58 * V_50 = V_25 -> V_37 . V_50 ;
T_1 V_59 = F_35 ( V_57 -> V_60 ) ;
char * V_61 ;
int V_29 = - V_36 ;
V_29 = F_36 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_61 = F_37 ( F_38 ( V_25 ,
V_57 -> V_60 >> V_62 ) ) ;
* ( T_1 * ) ( V_61 + V_59 ) = V_57 -> V_63 ;
if ( F_39 ( V_50 ) -> V_64 >= 8 ) {
V_59 = F_35 ( V_59 + sizeof( T_1 ) ) ;
if ( V_59 == 0 ) {
F_40 ( V_61 ) ;
V_61 = F_37 ( F_38 ( V_25 ,
( V_57 -> V_60 + sizeof( T_1 ) ) >> V_62 ) ) ;
}
* ( T_1 * ) ( V_61 + V_59 ) = 0 ;
}
F_40 ( V_61 ) ;
return 0 ;
}
static int
F_41 ( struct V_24 * V_25 ,
struct V_56 * V_57 )
{
struct V_58 * V_50 = V_25 -> V_37 . V_50 ;
struct V_65 * V_66 = V_50 -> V_67 ;
T_1 T_2 * V_68 ;
void T_2 * V_69 ;
int V_29 = - V_36 ;
V_29 = F_42 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_29 = F_43 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_57 -> V_60 += F_44 ( V_25 ) ;
V_69 = F_45 ( V_66 -> V_70 . V_71 ,
V_57 -> V_60 & V_72 ) ;
V_68 = ( T_1 T_2 * )
( V_69 + F_35 ( V_57 -> V_60 ) ) ;
F_46 ( V_57 -> V_63 , V_68 ) ;
if ( F_39 ( V_50 ) -> V_64 >= 8 ) {
V_68 += 1 ;
if ( F_35 ( V_57 -> V_60 + sizeof( T_1 ) ) == 0 ) {
F_47 ( V_69 ) ;
V_69 = F_45 (
V_66 -> V_70 . V_71 ,
V_57 -> V_60 + sizeof( T_1 ) ) ;
V_68 = V_69 ;
}
F_46 ( 0 , V_68 ) ;
}
F_47 ( V_69 ) ;
return 0 ;
}
static int
F_48 ( struct V_24 * V_25 ,
struct V_1 * V_5 ,
struct V_56 * V_57 ,
struct V_3 * V_4 )
{
struct V_58 * V_50 = V_25 -> V_37 . V_50 ;
struct V_73 * V_74 ;
struct V_24 * V_75 ;
struct V_10 * V_76 ;
T_1 V_77 ;
int V_29 = - V_36 ;
V_76 = F_23 ( V_5 , V_57 -> V_78 ) ;
if ( F_49 ( V_76 == NULL ) )
return - V_33 ;
V_75 = V_76 -> V_25 ;
V_74 = & V_76 -> V_25 -> V_37 ;
V_77 = F_44 ( V_75 ) ;
if ( F_49 ( F_50 ( V_50 ) &&
V_57 -> V_51 == V_79 &&
! V_75 -> V_80 ) ) {
F_51 ( V_75 ,
V_75 -> V_54 ) ;
}
if ( F_49 ( V_57 -> V_51 & ( V_57 -> V_51 - 1 ) ) ) {
F_12 ( L_4
L_5
L_6 ,
V_25 , V_57 -> V_78 ,
( int ) V_57 -> V_60 ,
V_57 -> V_81 ,
V_57 -> V_51 ) ;
return V_29 ;
}
if ( F_49 ( ( V_57 -> V_51 | V_57 -> V_81 )
& ~ V_82 ) ) {
F_12 ( L_7
L_5
L_6 ,
V_25 , V_57 -> V_78 ,
( int ) V_57 -> V_60 ,
V_57 -> V_81 ,
V_57 -> V_51 ) ;
return V_29 ;
}
V_74 -> V_83 |= V_57 -> V_81 ;
V_74 -> V_84 |= V_57 -> V_51 ;
if ( V_77 == V_57 -> V_85 )
return 0 ;
if ( F_49 ( V_57 -> V_60 >
V_25 -> V_37 . V_8 - ( F_39 ( V_50 ) -> V_64 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_8
L_9 ,
V_25 , V_57 -> V_78 ,
( int ) V_57 -> V_60 ,
( int ) V_25 -> V_37 . V_8 ) ;
return V_29 ;
}
if ( F_49 ( V_57 -> V_60 & 3 ) ) {
F_12 ( L_10
L_11 ,
V_25 , V_57 -> V_78 ,
( int ) V_57 -> V_60 ) ;
return V_29 ;
}
if ( V_25 -> V_86 && F_52 () )
return - V_87 ;
V_57 -> V_63 += V_77 ;
if ( F_32 ( V_25 ) )
V_29 = F_34 ( V_25 , V_57 ) ;
else
V_29 = F_41 ( V_25 , V_57 ) ;
if ( V_29 )
return V_29 ;
V_57 -> V_85 = V_77 ;
return 0 ;
}
static int
F_53 ( struct V_10 * V_38 ,
struct V_1 * V_5 )
{
#define F_54 ( T_3 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_56 V_88 [ F_54 ( 512 ) ] ;
struct V_56 T_4 * V_89 ;
struct V_20 * V_47 = V_38 -> V_40 ;
int V_90 , V_29 ;
V_89 = F_55 ( V_47 -> V_91 ) ;
V_90 = V_47 -> V_92 ;
while ( V_90 ) {
struct V_56 * V_93 = V_88 ;
int V_14 = V_90 ;
if ( V_14 > F_56 ( V_88 ) )
V_14 = F_56 ( V_88 ) ;
V_90 -= V_14 ;
if ( F_57 ( V_93 , V_89 , V_14 * sizeof( V_93 [ 0 ] ) ) )
return - V_87 ;
do {
T_5 V_60 = V_93 -> V_85 ;
V_29 = F_48 ( V_38 -> V_25 , V_5 , V_93 ,
V_38 -> V_4 ) ;
if ( V_29 )
return V_29 ;
if ( V_93 -> V_85 != V_60 &&
F_58 ( & V_89 -> V_85 ,
& V_93 -> V_85 ,
sizeof( V_93 -> V_85 ) ) ) {
return - V_87 ;
}
V_89 ++ ;
V_93 ++ ;
} while ( -- V_14 );
}
return 0 ;
#undef F_54
}
static int
F_59 ( struct V_10 * V_38 ,
struct V_1 * V_5 ,
struct V_56 * V_94 )
{
const struct V_20 * V_47 = V_38 -> V_40 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_47 -> V_92 ; V_28 ++ ) {
V_29 = F_48 ( V_38 -> V_25 , V_5 , & V_94 [ V_28 ] ,
V_38 -> V_4 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_60 ( struct V_1 * V_5 ,
struct V_3 * V_4 )
{
struct V_10 * V_38 ;
int V_29 = 0 ;
F_61 () ;
F_62 (vma, &eb->vmas, exec_list) {
V_29 = F_53 ( V_38 , V_5 ) ;
if ( V_29 )
break;
}
F_63 () ;
return V_29 ;
}
static int
F_64 ( struct V_10 * V_38 )
{
struct V_20 * V_47 = V_38 -> V_40 ;
return V_47 -> V_92 && ! F_32 ( V_38 -> V_25 ) &&
F_65 ( V_38 -> V_4 ) ;
}
static int
F_66 ( struct V_10 * V_38 ,
struct V_95 * V_96 ,
bool * V_97 )
{
struct V_65 * V_66 = V_96 -> V_50 -> V_67 ;
struct V_20 * V_47 = V_38 -> V_40 ;
bool V_98 = F_39 ( V_96 -> V_50 ) -> V_64 < 4 ;
bool V_99 , V_100 ;
struct V_24 * V_25 = V_38 -> V_25 ;
int V_29 ;
V_99 =
V_98 &&
V_47 -> V_6 & V_101 &&
V_25 -> V_102 != V_103 ;
V_100 = V_99 || F_64 ( V_38 ) ;
V_29 = F_67 ( V_25 , V_38 -> V_4 , V_47 -> V_104 , V_100 ,
false ) ;
if ( V_29 )
return V_29 ;
V_47 -> V_6 |= V_49 ;
if ( V_98 ) {
if ( V_47 -> V_6 & V_101 ) {
V_29 = F_68 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_69 ( V_25 ) )
V_47 -> V_6 |= V_48 ;
V_25 -> V_105 = true ;
}
}
if ( V_66 -> V_106 . V_107 && ! V_25 -> V_108 ) {
F_70 ( V_66 -> V_106 . V_107 ,
V_25 , V_25 -> V_54 ) ;
V_25 -> V_108 = 1 ;
}
if ( V_47 -> V_60 != V_38 -> V_46 . V_109 ) {
V_47 -> V_60 = V_38 -> V_46 . V_109 ;
* V_97 = true ;
}
if ( V_47 -> V_6 & V_110 ) {
V_25 -> V_37 . V_83 = V_111 ;
V_25 -> V_37 . V_84 = V_111 ;
}
if ( V_47 -> V_6 & V_112 &&
! V_25 -> V_80 )
F_51 ( V_25 , V_25 -> V_54 ) ;
return 0 ;
}
static int
F_71 ( struct V_95 * V_96 ,
struct V_26 * V_18 ,
bool * V_113 )
{
struct V_24 * V_25 ;
struct V_10 * V_38 ;
struct V_3 * V_4 ;
struct V_26 V_114 ;
bool V_98 = F_39 ( V_96 -> V_50 ) -> V_64 < 4 ;
int V_115 ;
if ( F_13 ( V_18 ) )
return 0 ;
V_4 = F_16 ( V_18 , struct V_10 , V_39 ) -> V_4 ;
F_5 ( & V_114 ) ;
while ( ! F_13 ( V_18 ) ) {
struct V_20 * V_47 ;
bool V_99 , V_100 ;
V_38 = F_16 ( V_18 , struct V_10 , V_39 ) ;
V_25 = V_38 -> V_25 ;
V_47 = V_38 -> V_40 ;
V_99 =
V_98 &&
V_47 -> V_6 & V_101 &&
V_25 -> V_102 != V_103 ;
V_100 = V_99 || F_64 ( V_38 ) ;
if ( V_100 )
F_72 ( & V_38 -> V_39 , & V_114 ) ;
else
F_73 ( & V_38 -> V_39 , & V_114 ) ;
V_25 -> V_37 . V_83 = V_82 & ~ V_116 ;
V_25 -> V_37 . V_84 = 0 ;
V_25 -> V_105 = false ;
}
F_74 ( & V_114 , V_18 ) ;
V_115 = 0 ;
do {
int V_29 = 0 ;
F_62 (vma, vmas, exec_list) {
struct V_20 * V_47 = V_38 -> V_40 ;
bool V_99 , V_100 ;
V_25 = V_38 -> V_25 ;
if ( ! F_27 ( & V_38 -> V_46 ) )
continue;
V_99 =
V_98 &&
V_47 -> V_6 & V_101 &&
V_25 -> V_102 != V_103 ;
V_100 = V_99 || F_64 ( V_38 ) ;
F_75 ( ( V_100 || V_99 ) &&
! F_65 ( V_38 -> V_4 ) ) ;
if ( ( V_47 -> V_104 &&
V_38 -> V_46 . V_109 & ( V_47 -> V_104 - 1 ) ) ||
( V_100 && ! V_25 -> V_53 ) )
V_29 = F_76 ( V_38 ) ;
else
V_29 = F_66 ( V_38 , V_96 , V_113 ) ;
if ( V_29 )
goto V_34;
}
F_62 (vma, vmas, exec_list) {
if ( F_27 ( & V_38 -> V_46 ) )
continue;
V_29 = F_66 ( V_38 , V_96 , V_113 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_117 || V_115 ++ )
return V_29 ;
F_62 (vma, vmas, exec_list)
F_26 ( V_38 ) ;
V_29 = F_77 ( V_4 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_78 ( struct V_58 * V_50 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_95 * V_96 ,
struct V_1 * V_5 ,
struct V_20 * V_21 )
{
struct V_56 * V_57 ;
struct V_3 * V_4 ;
struct V_10 * V_38 ;
bool V_113 ;
int * V_118 ;
int V_28 , V_119 , V_29 ;
unsigned V_14 = args -> V_9 ;
if ( F_75 ( F_13 ( & V_5 -> V_18 ) ) )
return 0 ;
V_4 = F_16 ( & V_5 -> V_18 , struct V_10 , V_39 ) -> V_4 ;
while ( ! F_13 ( & V_5 -> V_18 ) ) {
V_38 = F_16 ( & V_5 -> V_18 , struct V_10 , V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_79 ( & V_50 -> V_120 ) ;
V_119 = 0 ;
for ( V_28 = 0 ; V_28 < V_14 ; V_28 ++ )
V_119 += V_21 [ V_28 ] . V_92 ;
V_118 = F_80 ( V_14 , sizeof( * V_118 ) ) ;
V_57 = F_80 ( V_119 , sizeof( * V_57 ) ) ;
if ( V_57 == NULL || V_118 == NULL ) {
F_81 ( V_57 ) ;
F_81 ( V_118 ) ;
F_82 ( & V_50 -> V_120 ) ;
return - V_121 ;
}
V_119 = 0 ;
for ( V_28 = 0 ; V_28 < V_14 ; V_28 ++ ) {
struct V_56 T_4 * V_89 ;
T_5 V_122 = ( T_5 ) - 1 ;
int V_123 ;
V_89 = F_55 ( V_21 [ V_28 ] . V_91 ) ;
if ( F_83 ( V_57 + V_119 , V_89 ,
V_21 [ V_28 ] . V_92 * sizeof( * V_57 ) ) ) {
V_29 = - V_87 ;
F_82 ( & V_50 -> V_120 ) ;
goto V_34;
}
for ( V_123 = 0 ; V_123 < V_21 [ V_28 ] . V_92 ; V_123 ++ ) {
if ( F_84 ( & V_89 [ V_123 ] . V_85 ,
& V_122 ,
sizeof( V_122 ) ) ) {
V_29 = - V_87 ;
F_82 ( & V_50 -> V_120 ) ;
goto V_34;
}
}
V_118 [ V_28 ] = V_119 ;
V_119 += V_21 [ V_28 ] . V_92 ;
}
V_29 = F_85 ( V_50 ) ;
if ( V_29 ) {
F_82 ( & V_50 -> V_120 ) ;
goto V_34;
}
F_6 ( V_5 ) ;
V_29 = F_7 ( V_5 , V_21 , args , V_4 , V_23 ) ;
if ( V_29 )
goto V_34;
V_113 = ( args -> V_6 & V_124 ) == 0 ;
V_29 = F_71 ( V_96 , & V_5 -> V_18 , & V_113 ) ;
if ( V_29 )
goto V_34;
F_62 (vma, &eb->vmas, exec_list) {
int V_60 = V_38 -> V_40 - V_21 ;
V_29 = F_59 ( V_38 , V_5 ,
V_57 + V_118 [ V_60 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_81 ( V_57 ) ;
F_81 ( V_118 ) ;
return V_29 ;
}
static int
F_86 ( struct V_95 * V_96 ,
struct V_26 * V_18 )
{
struct V_10 * V_38 ;
T_1 V_125 = 0 ;
bool V_126 = false ;
int V_29 ;
F_62 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
V_29 = F_87 ( V_25 , V_96 ) ;
if ( V_29 )
return V_29 ;
if ( V_25 -> V_37 . V_51 & V_52 )
V_126 |= F_88 ( V_25 , false ) ;
V_125 |= V_25 -> V_37 . V_51 ;
}
if ( V_126 )
F_89 ( V_96 -> V_50 ) ;
if ( V_125 & V_127 )
F_90 () ;
return F_91 ( V_96 ) ;
}
static bool
F_92 ( struct V_2 * V_21 )
{
if ( V_21 -> V_6 & V_128 )
return false ;
return ( ( V_21 -> V_129 | V_21 -> V_130 ) & 0x7 ) == 0 ;
}
static int
F_93 ( struct V_20 * V_21 ,
int V_14 )
{
int V_28 ;
unsigned V_131 = 0 ;
unsigned V_132 = V_133 / sizeof( struct V_56 ) ;
for ( V_28 = 0 ; V_28 < V_14 ; V_28 ++ ) {
char T_4 * V_134 = F_55 ( V_21 [ V_28 ] . V_91 ) ;
int V_135 ;
if ( V_21 [ V_28 ] . V_6 & V_136 )
return - V_36 ;
if ( V_21 [ V_28 ] . V_92 > V_132 - V_131 )
return - V_36 ;
V_131 += V_21 [ V_28 ] . V_92 ;
V_135 = V_21 [ V_28 ] . V_92 *
sizeof( struct V_56 ) ;
if ( ! F_94 ( V_137 , V_134 , V_135 ) )
return - V_87 ;
if ( F_95 ( ! V_138 ) ) {
if ( F_96 ( V_134 , V_135 ) )
return - V_87 ;
}
}
return 0 ;
}
static void
F_97 ( struct V_26 * V_18 ,
struct V_95 * V_96 )
{
struct V_10 * V_38 ;
F_62 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
T_6 V_139 = V_25 -> V_37 . V_81 ;
T_6 V_140 = V_25 -> V_37 . V_51 ;
V_25 -> V_37 . V_51 = V_25 -> V_37 . V_84 ;
if ( V_25 -> V_37 . V_51 == 0 )
V_25 -> V_37 . V_83 |= V_25 -> V_37 . V_81 ;
V_25 -> V_37 . V_81 = V_25 -> V_37 . V_83 ;
V_25 -> V_141 = V_25 -> V_105 ;
F_98 ( V_38 , V_96 ) ;
if ( V_25 -> V_37 . V_51 ) {
V_25 -> V_142 = 1 ;
V_25 -> V_143 = F_99 ( V_96 ) ;
if ( V_25 -> V_144 )
F_100 ( V_25 , V_96 ) ;
}
F_101 ( V_25 , V_139 , V_140 ) ;
}
}
static void
F_102 ( struct V_58 * V_50 ,
struct V_22 * V_23 ,
struct V_95 * V_96 ,
struct V_24 * V_25 )
{
V_96 -> V_145 = true ;
( void ) F_103 ( V_96 , V_23 , V_25 , NULL ) ;
}
static int
F_104 ( struct V_58 * V_50 ,
struct V_95 * V_96 )
{
T_7 * V_66 = V_50 -> V_67 ;
int V_29 , V_28 ;
if ( ! F_105 ( V_50 ) || V_96 != & V_66 -> V_96 [ V_146 ] )
return 0 ;
V_29 = F_106 ( V_96 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_107 ( V_96 , F_108 ( 1 ) ) ;
F_107 ( V_96 , F_109 ( V_28 ) ) ;
F_107 ( V_96 , 0 ) ;
}
F_110 ( V_96 ) ;
return 0 ;
}
static int
F_111 ( struct V_58 * V_50 , void * V_147 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_20 * V_21 ,
struct V_3 * V_4 )
{
T_7 * V_66 = V_50 -> V_67 ;
struct V_1 * V_5 ;
struct V_24 * V_148 ;
struct V_149 * V_150 = NULL ;
struct V_95 * V_96 ;
struct V_151 * V_152 ;
T_6 V_153 = F_112 ( * args ) ;
T_6 V_154 , V_155 ;
T_6 V_156 , V_6 ;
int V_29 , V_157 , V_28 ;
bool V_113 ;
if ( ! F_92 ( args ) )
return - V_36 ;
V_29 = F_93 ( V_21 , args -> V_9 ) ;
if ( V_29 )
return V_29 ;
V_6 = 0 ;
if ( args -> V_6 & V_158 ) {
if ( ! V_23 -> V_159 || ! F_113 ( V_160 ) )
return - V_161 ;
V_6 |= V_162 ;
}
if ( args -> V_6 & V_163 )
V_6 |= V_164 ;
switch ( args -> V_6 & V_165 ) {
case V_166 :
case V_167 :
V_96 = & V_66 -> V_96 [ V_146 ] ;
break;
case V_168 :
V_96 = & V_66 -> V_96 [ V_169 ] ;
if ( V_153 != V_170 ) {
F_12 ( L_12 ,
V_96 -> V_171 ) ;
return - V_161 ;
}
break;
case V_172 :
V_96 = & V_66 -> V_96 [ V_173 ] ;
if ( V_153 != V_170 ) {
F_12 ( L_12 ,
V_96 -> V_171 ) ;
return - V_161 ;
}
break;
case V_174 :
V_96 = & V_66 -> V_96 [ V_175 ] ;
if ( V_153 != V_170 ) {
F_12 ( L_12 ,
V_96 -> V_171 ) ;
return - V_161 ;
}
break;
default:
F_12 ( L_13 ,
( int ) ( args -> V_6 & V_165 ) ) ;
return - V_36 ;
}
if ( ! F_114 ( V_96 ) ) {
F_12 ( L_14 ,
( int ) ( args -> V_6 & V_165 ) ) ;
return - V_36 ;
}
V_157 = args -> V_6 & V_176 ;
V_156 = V_176 ;
switch ( V_157 ) {
case V_177 :
case V_178 :
case V_179 :
if ( V_96 == & V_66 -> V_96 [ V_146 ] &&
V_157 != V_66 -> V_180 ) {
if ( F_39 ( V_50 ) -> V_64 < 4 )
return - V_36 ;
if ( F_39 ( V_50 ) -> V_64 > 5 &&
V_157 == V_179 )
return - V_36 ;
if ( F_39 ( V_50 ) -> V_64 >= 6 )
V_156 &= ~ V_179 ;
}
break;
default:
F_12 ( L_15 , V_157 ) ;
return - V_36 ;
}
if ( args -> V_9 < 1 ) {
F_12 ( L_16 , args -> V_9 ) ;
return - V_36 ;
}
if ( args -> V_181 != 0 ) {
if ( V_96 != & V_66 -> V_96 [ V_146 ] ) {
F_12 ( L_17 ) ;
return - V_36 ;
}
if ( F_39 ( V_50 ) -> V_64 >= 5 ) {
F_12 ( L_18 ) ;
return - V_36 ;
}
if ( args -> V_181 > V_133 / sizeof( * V_150 ) ) {
F_12 ( L_19 ,
args -> V_181 ) ;
return - V_36 ;
}
V_150 = F_115 ( args -> V_181 ,
sizeof( * V_150 ) ,
V_182 ) ;
if ( V_150 == NULL ) {
V_29 = - V_121 ;
goto V_183;
}
if ( F_83 ( V_150 ,
F_55 ( args -> V_184 ) ,
sizeof( * V_150 ) * args -> V_181 ) ) {
V_29 = - V_87 ;
goto V_183;
}
}
V_29 = F_85 ( V_50 ) ;
if ( V_29 )
goto V_183;
if ( V_66 -> V_185 . V_186 ) {
F_79 ( & V_50 -> V_120 ) ;
V_29 = - V_187 ;
goto V_183;
}
V_5 = F_1 ( args , V_4 ) ;
if ( V_5 == NULL ) {
F_79 ( & V_50 -> V_120 ) ;
V_29 = - V_121 ;
goto V_183;
}
V_29 = F_7 ( V_5 , V_21 , args , V_4 , V_23 ) ;
if ( V_29 )
goto V_34;
V_148 = F_116 ( V_5 -> V_18 . V_188 , struct V_10 , V_39 ) -> V_25 ;
V_113 = ( args -> V_6 & V_124 ) == 0 ;
V_29 = F_71 ( V_96 , & V_5 -> V_18 , & V_113 ) ;
if ( V_29 )
goto V_34;
if ( V_113 )
V_29 = F_60 ( V_5 , V_4 ) ;
if ( V_29 ) {
if ( V_29 == - V_87 ) {
V_29 = F_78 ( V_50 , args , V_23 , V_96 ,
V_5 , V_21 ) ;
F_117 ( ! F_118 ( & V_50 -> V_120 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_148 -> V_37 . V_84 ) {
F_12 ( L_20 ) ;
V_29 = - V_36 ;
goto V_34;
}
V_148 -> V_37 . V_83 |= V_116 ;
if ( V_6 & V_162 && ! V_148 -> V_80 )
F_51 ( V_148 , V_148 -> V_54 ) ;
V_29 = F_86 ( V_96 , & V_5 -> V_18 ) ;
if ( V_29 )
goto V_34;
V_152 = F_119 ( V_50 , V_23 , V_153 ) ;
if ( F_18 ( V_152 ) ) {
V_29 = F_19 ( V_152 ) ;
goto V_34;
}
if ( V_152 -> V_189 ) {
V_29 = - V_190 ;
goto V_34;
}
V_29 = F_120 ( V_96 , V_23 , V_153 ) ;
if ( V_29 )
goto V_34;
if ( V_96 == & V_66 -> V_96 [ V_146 ] &&
V_157 != V_66 -> V_180 ) {
V_29 = F_106 ( V_96 , 4 ) ;
if ( V_29 )
goto V_34;
F_107 ( V_96 , V_191 ) ;
F_107 ( V_96 , F_108 ( 1 ) ) ;
F_107 ( V_96 , V_192 ) ;
F_107 ( V_96 , V_156 << 16 | V_157 ) ;
F_110 ( V_96 ) ;
V_66 -> V_180 = V_157 ;
}
if ( args -> V_6 & V_193 ) {
V_29 = F_104 ( V_50 , V_96 ) ;
if ( V_29 )
goto V_34;
}
V_154 = F_121 ( V_148 , V_4 ) +
args -> V_129 ;
V_155 = args -> V_130 ;
if ( V_150 ) {
for ( V_28 = 0 ; V_28 < args -> V_181 ; V_28 ++ ) {
V_29 = F_122 ( V_50 , & V_150 [ V_28 ] ,
args -> V_194 , args -> V_195 ) ;
if ( V_29 )
goto V_34;
V_29 = V_96 -> V_196 ( V_96 ,
V_154 , V_155 ,
V_6 ) ;
if ( V_29 )
goto V_34;
}
} else {
V_29 = V_96 -> V_196 ( V_96 ,
V_154 , V_155 ,
V_6 ) ;
if ( V_29 )
goto V_34;
}
F_123 ( V_96 , F_99 ( V_96 ) , V_6 ) ;
F_97 ( & V_5 -> V_18 , V_96 ) ;
F_102 ( V_50 , V_23 , V_96 , V_148 ) ;
V_34:
F_30 ( V_5 ) ;
F_79 ( & V_50 -> V_120 ) ;
V_183:
F_31 ( V_150 ) ;
return V_29 ;
}
int
F_124 ( struct V_58 * V_50 , void * V_147 ,
struct V_22 * V_23 )
{
struct V_65 * V_66 = V_50 -> V_67 ;
struct V_197 * args = V_147 ;
struct V_2 V_198 ;
struct V_199 * V_39 = NULL ;
struct V_20 * V_200 = NULL ;
int V_29 , V_28 ;
if ( args -> V_9 < 1 ) {
F_12 ( L_16 , args -> V_9 ) ;
return - V_36 ;
}
V_39 = F_80 ( sizeof( * V_39 ) , args -> V_9 ) ;
V_200 = F_80 ( sizeof( * V_200 ) , args -> V_9 ) ;
if ( V_39 == NULL || V_200 == NULL ) {
F_12 ( L_21 ,
args -> V_9 ) ;
F_81 ( V_39 ) ;
F_81 ( V_200 ) ;
return - V_121 ;
}
V_29 = F_83 ( V_39 ,
F_55 ( args -> V_201 ) ,
sizeof( * V_39 ) * args -> V_9 ) ;
if ( V_29 != 0 ) {
F_12 ( L_22 ,
args -> V_9 , V_29 ) ;
F_81 ( V_39 ) ;
F_81 ( V_200 ) ;
return - V_87 ;
}
for ( V_28 = 0 ; V_28 < args -> V_9 ; V_28 ++ ) {
V_200 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_200 [ V_28 ] . V_92 = V_39 [ V_28 ] . V_92 ;
V_200 [ V_28 ] . V_91 = V_39 [ V_28 ] . V_91 ;
V_200 [ V_28 ] . V_104 = V_39 [ V_28 ] . V_104 ;
V_200 [ V_28 ] . V_60 = V_39 [ V_28 ] . V_60 ;
if ( F_39 ( V_50 ) -> V_64 < 4 )
V_200 [ V_28 ] . V_6 = V_101 ;
else
V_200 [ V_28 ] . V_6 = 0 ;
}
V_198 . V_201 = args -> V_201 ;
V_198 . V_9 = args -> V_9 ;
V_198 . V_129 = args -> V_129 ;
V_198 . V_130 = args -> V_130 ;
V_198 . V_194 = args -> V_194 ;
V_198 . V_195 = args -> V_195 ;
V_198 . V_181 = args -> V_181 ;
V_198 . V_184 = args -> V_184 ;
V_198 . V_6 = V_167 ;
F_125 ( V_198 , 0 ) ;
V_29 = F_111 ( V_50 , V_147 , V_23 , & V_198 , V_200 ,
& V_66 -> V_70 . V_37 ) ;
if ( ! V_29 ) {
for ( V_28 = 0 ; V_28 < args -> V_9 ; V_28 ++ )
V_39 [ V_28 ] . V_60 = V_200 [ V_28 ] . V_60 ;
V_29 = F_84 ( F_55 ( args -> V_201 ) ,
V_39 ,
sizeof( * V_39 ) * args -> V_9 ) ;
if ( V_29 ) {
V_29 = - V_87 ;
F_12 ( L_23
L_24 ,
args -> V_9 , V_29 ) ;
}
}
F_81 ( V_39 ) ;
F_81 ( V_200 ) ;
return V_29 ;
}
int
F_126 ( struct V_58 * V_50 , void * V_147 ,
struct V_22 * V_23 )
{
struct V_65 * V_66 = V_50 -> V_67 ;
struct V_2 * args = V_147 ;
struct V_20 * V_200 = NULL ;
int V_29 ;
if ( args -> V_9 < 1 ||
args -> V_9 > V_133 / sizeof( * V_200 ) ) {
F_12 ( L_25 , args -> V_9 ) ;
return - V_36 ;
}
V_200 = F_2 ( sizeof( * V_200 ) * args -> V_9 ,
V_11 | V_12 | V_13 ) ;
if ( V_200 == NULL )
V_200 = F_80 ( sizeof( * V_200 ) ,
args -> V_9 ) ;
if ( V_200 == NULL ) {
F_12 ( L_21 ,
args -> V_9 ) ;
return - V_121 ;
}
V_29 = F_83 ( V_200 ,
F_55 ( args -> V_201 ) ,
sizeof( * V_200 ) * args -> V_9 ) ;
if ( V_29 != 0 ) {
F_12 ( L_22 ,
args -> V_9 , V_29 ) ;
F_81 ( V_200 ) ;
return - V_87 ;
}
V_29 = F_111 ( V_50 , V_147 , V_23 , args , V_200 ,
& V_66 -> V_70 . V_37 ) ;
if ( ! V_29 ) {
V_29 = F_84 ( F_55 ( args -> V_201 ) ,
V_200 ,
sizeof( * V_200 ) * args -> V_9 ) ;
if ( V_29 ) {
V_29 = - V_87 ;
F_12 ( L_23
L_24 ,
args -> V_9 , V_29 ) ;
}
}
F_81 ( V_200 ) ;
return V_29 ;
}
