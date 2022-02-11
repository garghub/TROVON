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
! ( V_77 -> V_81 & V_82 ) ) )
V_77 -> V_83 ( V_77 , V_76 -> V_55 ,
V_82 ) ;
if ( F_50 ( V_58 -> V_52 & ( V_58 -> V_52 - 1 ) ) ) {
F_12 ( L_4
L_5
L_6 ,
V_25 , V_58 -> V_78 ,
( int ) V_58 -> V_62 ,
V_58 -> V_84 ,
V_58 -> V_52 ) ;
return - V_36 ;
}
if ( F_50 ( ( V_58 -> V_52 | V_58 -> V_84 )
& ~ V_85 ) ) {
F_12 ( L_7
L_5
L_6 ,
V_25 , V_58 -> V_78 ,
( int ) V_58 -> V_62 ,
V_58 -> V_84 ,
V_58 -> V_52 ) ;
return - V_36 ;
}
V_75 -> V_86 |= V_58 -> V_84 ;
V_75 -> V_87 |= V_58 -> V_52 ;
if ( V_59 == V_58 -> V_88 )
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
if ( V_25 -> V_89 && F_52 () )
return - V_90 ;
if ( F_31 ( V_25 ) )
V_29 = F_33 ( V_25 , V_58 , V_59 ) ;
else
V_29 = F_42 ( V_25 , V_58 , V_59 ) ;
if ( V_29 )
return V_29 ;
V_58 -> V_88 = V_59 ;
return 0 ;
}
static int
F_53 ( struct V_8 * V_38 ,
struct V_1 * V_3 )
{
#define F_54 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_57 V_91 [ F_54 ( 512 ) ] ;
struct V_57 T_5 * V_92 ;
struct V_18 * V_47 = V_38 -> V_40 ;
int V_93 , V_29 ;
V_92 = F_55 ( V_47 -> V_94 ) ;
V_93 = V_47 -> V_95 ;
while ( V_93 ) {
struct V_57 * V_96 = V_91 ;
int V_12 = V_93 ;
if ( V_12 > F_56 ( V_91 ) )
V_12 = F_56 ( V_91 ) ;
V_93 -= V_12 ;
if ( F_57 ( V_96 , V_92 , V_12 * sizeof( V_96 [ 0 ] ) ) )
return - V_90 ;
do {
T_6 V_62 = V_96 -> V_88 ;
V_29 = F_49 ( V_38 -> V_25 , V_3 , V_96 ) ;
if ( V_29 )
return V_29 ;
if ( V_96 -> V_88 != V_62 &&
F_58 ( & V_92 -> V_88 ,
& V_96 -> V_88 ,
sizeof( V_96 -> V_88 ) ) ) {
return - V_90 ;
}
V_92 ++ ;
V_96 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_54
}
static int
F_59 ( struct V_8 * V_38 ,
struct V_1 * V_3 ,
struct V_57 * V_97 )
{
const struct V_18 * V_47 = V_38 -> V_40 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_47 -> V_95 ; V_28 ++ ) {
V_29 = F_49 ( V_38 -> V_25 , V_3 , & V_97 [ V_28 ] ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_60 ( struct V_1 * V_3 )
{
struct V_8 * V_38 ;
int V_29 = 0 ;
F_61 () ;
F_62 (vma, &eb->vmas, exec_list) {
V_29 = F_53 ( V_38 , V_3 ) ;
if ( V_29 )
break;
}
F_63 () ;
return V_29 ;
}
static int
F_64 ( struct V_8 * V_38 ,
struct V_98 * V_99 ,
bool * V_100 )
{
struct V_24 * V_25 = V_38 -> V_25 ;
struct V_18 * V_47 = V_38 -> V_40 ;
T_2 V_4 ;
int V_29 ;
V_4 = 0 ;
if ( V_47 -> V_4 & V_101 )
V_4 |= V_102 | V_103 ;
if ( V_47 -> V_4 & V_104 )
V_4 |= V_102 ;
if ( V_47 -> V_4 & V_105 )
V_4 |= V_106 | V_107 ;
V_29 = F_65 ( V_25 , V_38 -> V_21 , V_47 -> V_108 , V_4 ) ;
if ( V_29 )
return V_29 ;
V_47 -> V_4 |= V_49 ;
if ( V_47 -> V_4 & V_109 ) {
V_29 = F_66 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_67 ( V_25 ) )
V_47 -> V_4 |= V_48 ;
}
if ( V_47 -> V_62 != V_38 -> V_46 . V_79 ) {
V_47 -> V_62 = V_38 -> V_46 . V_79 ;
* V_100 = true ;
}
if ( V_47 -> V_4 & V_110 ) {
V_25 -> V_37 . V_86 = V_111 ;
V_25 -> V_37 . V_87 = V_111 ;
}
return 0 ;
}
static bool
F_68 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
if ( V_47 -> V_95 == 0 )
return false ;
if ( ! F_69 ( V_38 -> V_21 ) )
return false ;
if ( F_32 ( V_38 -> V_25 -> V_37 . V_51 ) )
return false ;
if ( V_38 -> V_25 -> V_37 . V_52 == V_53 )
return false ;
return true ;
}
static bool
F_70 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
F_71 ( V_47 -> V_4 & V_101 &&
! F_69 ( V_38 -> V_21 ) ) ;
if ( V_47 -> V_108 &&
V_38 -> V_46 . V_79 & ( V_47 -> V_108 - 1 ) )
return true ;
if ( V_47 -> V_4 & V_101 && ! V_25 -> V_54 )
return true ;
if ( V_47 -> V_4 & V_105 &&
V_38 -> V_46 . V_79 < V_106 )
return true ;
return false ;
}
static int
F_72 ( struct V_98 * V_99 ,
struct V_26 * V_16 ,
bool * V_112 )
{
struct V_24 * V_25 ;
struct V_8 * V_38 ;
struct V_20 * V_21 ;
struct V_26 V_113 ;
bool V_114 = F_39 ( V_99 -> V_51 ) -> V_66 < 4 ;
int V_115 ;
F_73 ( V_99 ) ;
V_21 = F_16 ( V_16 , struct V_8 , V_39 ) -> V_21 ;
F_5 ( & V_113 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_47 ;
bool V_116 , V_117 ;
V_38 = F_16 ( V_16 , struct V_8 , V_39 ) ;
V_25 = V_38 -> V_25 ;
V_47 = V_38 -> V_40 ;
if ( ! V_114 )
V_47 -> V_4 &= ~ V_109 ;
V_116 =
V_47 -> V_4 & V_109 &&
V_25 -> V_118 != V_119 ;
V_117 = V_116 || F_68 ( V_38 ) ;
if ( V_117 ) {
V_47 -> V_4 |= V_101 ;
F_74 ( & V_38 -> V_39 , & V_113 ) ;
} else
F_75 ( & V_38 -> V_39 , & V_113 ) ;
V_25 -> V_37 . V_86 = V_85 & ~ V_120 ;
V_25 -> V_37 . V_87 = 0 ;
}
F_76 ( & V_113 , V_16 ) ;
V_115 = 0 ;
do {
int V_29 = 0 ;
F_62 (vma, vmas, exec_list) {
if ( ! F_27 ( & V_38 -> V_46 ) )
continue;
if ( F_70 ( V_38 ) )
V_29 = F_77 ( V_38 ) ;
else
V_29 = F_64 ( V_38 , V_99 , V_112 ) ;
if ( V_29 )
goto V_34;
}
F_62 (vma, vmas, exec_list) {
if ( F_27 ( & V_38 -> V_46 ) )
continue;
V_29 = F_64 ( V_38 , V_99 , V_112 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_121 || V_115 ++ )
return V_29 ;
F_62 (vma, vmas, exec_list)
F_26 ( V_38 ) ;
V_29 = F_78 ( V_21 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_79 ( struct V_60 * V_51 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_98 * V_99 ,
struct V_1 * V_3 ,
struct V_18 * V_19 )
{
struct V_57 * V_58 ;
struct V_20 * V_21 ;
struct V_8 * V_38 ;
bool V_112 ;
int * V_122 ;
int V_28 , V_123 , V_29 ;
unsigned V_12 = args -> V_7 ;
V_21 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) -> V_21 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_38 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_80 ( & V_51 -> V_124 ) ;
V_123 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
V_123 += V_19 [ V_28 ] . V_95 ;
V_122 = F_81 ( V_12 , sizeof( * V_122 ) ) ;
V_58 = F_81 ( V_123 , sizeof( * V_58 ) ) ;
if ( V_58 == NULL || V_122 == NULL ) {
F_82 ( V_58 ) ;
F_82 ( V_122 ) ;
F_83 ( & V_51 -> V_124 ) ;
return - V_125 ;
}
V_123 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
struct V_57 T_5 * V_92 ;
T_6 V_126 = ( T_6 ) - 1 ;
int V_127 ;
V_92 = F_55 ( V_19 [ V_28 ] . V_94 ) ;
if ( F_84 ( V_58 + V_123 , V_92 ,
V_19 [ V_28 ] . V_95 * sizeof( * V_58 ) ) ) {
V_29 = - V_90 ;
F_83 ( & V_51 -> V_124 ) ;
goto V_34;
}
for ( V_127 = 0 ; V_127 < V_19 [ V_28 ] . V_95 ; V_127 ++ ) {
if ( F_85 ( & V_92 [ V_127 ] . V_88 ,
& V_126 ,
sizeof( V_126 ) ) ) {
V_29 = - V_90 ;
F_83 ( & V_51 -> V_124 ) ;
goto V_34;
}
}
V_122 [ V_28 ] = V_123 ;
V_123 += V_19 [ V_28 ] . V_95 ;
}
V_29 = F_86 ( V_51 ) ;
if ( V_29 ) {
F_83 ( & V_51 -> V_124 ) ;
goto V_34;
}
F_6 ( V_3 ) ;
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_112 = ( args -> V_4 & V_128 ) == 0 ;
V_29 = F_72 ( V_99 , & V_3 -> V_16 , & V_112 ) ;
if ( V_29 )
goto V_34;
F_62 (vma, &eb->vmas, exec_list) {
int V_62 = V_38 -> V_40 - V_19 ;
V_29 = F_59 ( V_38 , V_3 ,
V_58 + V_122 [ V_62 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_82 ( V_58 ) ;
F_82 ( V_122 ) ;
return V_29 ;
}
static int
F_87 ( struct V_98 * V_99 ,
struct V_26 * V_16 )
{
struct V_8 * V_38 ;
T_1 V_129 = 0 ;
bool V_130 = false ;
int V_29 ;
F_62 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
V_29 = F_88 ( V_25 , V_99 ) ;
if ( V_29 )
return V_29 ;
if ( V_25 -> V_37 . V_52 & V_53 )
V_130 |= F_89 ( V_25 , false ) ;
V_129 |= V_25 -> V_37 . V_52 ;
}
if ( V_130 )
F_90 ( V_99 -> V_51 ) ;
if ( V_129 & V_131 )
F_91 () ;
return F_92 ( V_99 ) ;
}
static bool
F_93 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_132 )
return false ;
return ( ( V_19 -> V_133 | V_19 -> V_134 ) & 0x7 ) == 0 ;
}
static int
F_94 ( struct V_60 * V_51 ,
struct V_18 * V_19 ,
int V_12 )
{
unsigned V_135 = 0 ;
unsigned V_136 = V_137 / sizeof( struct V_57 ) ;
unsigned V_138 ;
int V_28 ;
V_138 = V_139 ;
if ( F_95 ( V_51 ) )
V_138 |= V_104 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
char T_5 * V_140 = F_55 ( V_19 [ V_28 ] . V_94 ) ;
int V_141 ;
if ( V_19 [ V_28 ] . V_4 & V_138 )
return - V_36 ;
if ( V_19 [ V_28 ] . V_95 > V_136 - V_135 )
return - V_36 ;
V_135 += V_19 [ V_28 ] . V_95 ;
V_141 = V_19 [ V_28 ] . V_95 *
sizeof( struct V_57 ) ;
if ( ! F_96 ( V_142 , V_140 , V_141 ) )
return - V_90 ;
if ( F_97 ( ! V_143 . V_144 ) ) {
if ( F_98 ( V_140 , V_141 ) )
return - V_90 ;
}
}
return 0 ;
}
static struct V_145 *
F_99 ( struct V_60 * V_51 , struct V_22 * V_23 ,
struct V_98 * V_99 , const T_7 V_146 )
{
struct V_145 * V_147 = NULL ;
struct V_148 * V_149 ;
if ( V_99 -> V_150 != V_151 && V_146 != V_152 )
return F_100 ( - V_36 ) ;
V_147 = F_101 ( V_23 -> V_153 , V_146 ) ;
if ( F_18 ( V_147 ) )
return V_147 ;
V_149 = & V_147 -> V_154 ;
if ( V_149 -> V_155 ) {
F_12 ( L_12 , V_146 ) ;
return F_100 ( - V_156 ) ;
}
if ( V_143 . V_157 && ! V_147 -> V_158 [ V_99 -> V_150 ] . V_159 ) {
int V_29 = F_102 ( V_147 , V_99 ) ;
if ( V_29 ) {
F_12 ( L_13 , V_146 , V_29 ) ;
return F_100 ( V_29 ) ;
}
}
return V_147 ;
}
void
F_103 ( struct V_26 * V_16 ,
struct V_98 * V_99 )
{
T_7 V_160 = F_104 ( V_99 ) ;
struct V_8 * V_38 ;
F_62 (vma, vmas, exec_list) {
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
T_7 V_161 = V_25 -> V_37 . V_84 ;
T_7 V_162 = V_25 -> V_37 . V_52 ;
V_25 -> V_37 . V_52 = V_25 -> V_37 . V_87 ;
if ( V_25 -> V_37 . V_52 == 0 )
V_25 -> V_37 . V_86 |= V_25 -> V_37 . V_84 ;
V_25 -> V_37 . V_84 = V_25 -> V_37 . V_86 ;
F_105 ( V_38 , V_99 ) ;
if ( V_25 -> V_37 . V_52 ) {
V_25 -> V_163 = 1 ;
V_25 -> V_164 = V_160 ;
F_106 ( V_25 , V_99 ) ;
V_25 -> V_37 . V_52 &= ~ V_85 ;
}
if ( V_47 -> V_4 & V_109 ) {
V_25 -> V_165 = V_160 ;
if ( V_47 -> V_4 & V_48 ) {
struct V_67 * V_68 = F_107 ( V_99 -> V_51 ) ;
F_75 ( & V_68 -> V_166 [ V_25 -> V_167 ] . V_168 ,
& V_68 -> V_169 . V_170 ) ;
}
}
F_108 ( V_25 , V_161 , V_162 ) ;
}
}
void
F_109 ( struct V_60 * V_51 ,
struct V_22 * V_23 ,
struct V_98 * V_99 ,
struct V_24 * V_25 )
{
V_99 -> V_171 = true ;
( void ) F_110 ( V_99 , V_23 , V_25 , NULL ) ;
}
static int
F_111 ( struct V_60 * V_51 ,
struct V_98 * V_99 )
{
struct V_67 * V_68 = V_51 -> V_69 ;
int V_29 , V_28 ;
if ( ! F_112 ( V_51 ) || V_99 != & V_68 -> V_99 [ V_151 ] ) {
F_12 ( L_14 ) ;
return - V_36 ;
}
V_29 = F_113 ( V_99 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_114 ( V_99 , F_115 ( 1 ) ) ;
F_114 ( V_99 , F_116 ( V_28 ) ) ;
F_114 ( V_99 , 0 ) ;
}
F_117 ( V_99 ) ;
return 0 ;
}
static int
F_118 ( struct V_98 * V_99 ,
struct V_172 * V_173 ,
int V_174 , int V_175 )
{
int V_29 ;
if ( V_173 -> V_176 <= V_173 -> y1 || V_173 -> V_177 <= V_173 -> V_178 ||
V_173 -> V_176 <= 0 || V_173 -> V_177 <= 0 ) {
F_119 ( L_15 ,
V_173 -> V_178 , V_173 -> y1 , V_173 -> V_177 , V_173 -> V_176 ) ;
return - V_36 ;
}
if ( F_39 ( V_99 -> V_51 ) -> V_66 >= 4 ) {
V_29 = F_113 ( V_99 , 4 ) ;
if ( V_29 )
return V_29 ;
F_114 ( V_99 , V_179 ) ;
F_114 ( V_99 , ( V_173 -> V_178 & 0xffff ) | V_173 -> y1 << 16 ) ;
F_114 ( V_99 , ( ( V_173 -> V_177 - 1 ) & 0xffff ) | ( V_173 -> V_176 - 1 ) << 16 ) ;
F_114 ( V_99 , V_175 ) ;
} else {
V_29 = F_113 ( V_99 , 6 ) ;
if ( V_29 )
return V_29 ;
F_114 ( V_99 , V_180 ) ;
F_114 ( V_99 , V_174 ) ;
F_114 ( V_99 , ( V_173 -> V_178 & 0xffff ) | V_173 -> y1 << 16 ) ;
F_114 ( V_99 , ( ( V_173 -> V_177 - 1 ) & 0xffff ) | ( V_173 -> V_176 - 1 ) << 16 ) ;
F_114 ( V_99 , V_175 ) ;
F_114 ( V_99 , 0 ) ;
}
F_117 ( V_99 ) ;
return 0 ;
}
int
F_120 ( struct V_60 * V_51 , struct V_22 * V_23 ,
struct V_98 * V_99 ,
struct V_145 * V_147 ,
struct V_2 * args ,
struct V_26 * V_16 ,
struct V_24 * V_181 ,
T_6 V_182 , T_7 V_4 )
{
struct V_172 * V_183 = NULL ;
struct V_67 * V_68 = V_51 -> V_69 ;
T_6 V_184 ;
int V_185 ;
T_7 V_186 ;
int V_28 , V_29 = 0 ;
if ( args -> V_187 != 0 ) {
if ( V_99 != & V_68 -> V_99 [ V_151 ] ) {
F_12 ( L_16 ) ;
return - V_36 ;
}
if ( F_39 ( V_51 ) -> V_66 >= 5 ) {
F_12 ( L_17 ) ;
return - V_36 ;
}
if ( args -> V_187 > V_137 / sizeof( * V_183 ) ) {
F_12 ( L_18 ,
args -> V_187 ) ;
return - V_36 ;
}
V_183 = F_121 ( args -> V_187 ,
sizeof( * V_183 ) ,
V_188 ) ;
if ( V_183 == NULL ) {
V_29 = - V_125 ;
goto error;
}
if ( F_84 ( V_183 ,
F_55 ( args -> V_189 ) ,
sizeof( * V_183 ) * args -> V_187 ) ) {
V_29 = - V_90 ;
goto error;
}
} else {
if ( args -> V_175 == 0xffffffff ) {
F_12 ( L_19 ) ;
args -> V_175 = 0 ;
}
if ( args -> V_174 || args -> V_175 || args -> V_189 ) {
F_12 ( L_20 ) ;
return - V_36 ;
}
}
V_29 = F_87 ( V_99 , V_16 ) ;
if ( V_29 )
goto error;
V_29 = F_122 ( V_99 , V_147 ) ;
if ( V_29 )
goto error;
V_185 = args -> V_4 & V_190 ;
V_186 = V_190 ;
switch ( V_185 ) {
case V_191 :
case V_192 :
case V_193 :
if ( V_185 != 0 && V_99 != & V_68 -> V_99 [ V_151 ] ) {
F_12 ( L_21 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_185 != V_68 -> V_194 ) {
if ( F_39 ( V_51 ) -> V_66 < 4 ) {
F_12 ( L_22 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_51 ) -> V_66 > 5 &&
V_185 == V_193 ) {
F_12 ( L_23 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_51 ) -> V_66 >= 6 )
V_186 &= ~ V_193 ;
}
break;
default:
F_12 ( L_24 , V_185 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_99 == & V_68 -> V_99 [ V_151 ] &&
V_185 != V_68 -> V_194 ) {
V_29 = F_113 ( V_99 , 4 ) ;
if ( V_29 )
goto error;
F_114 ( V_99 , V_195 ) ;
F_114 ( V_99 , F_115 ( 1 ) ) ;
F_114 ( V_99 , V_196 ) ;
F_114 ( V_99 , V_186 << 16 | V_185 ) ;
F_117 ( V_99 ) ;
V_68 -> V_194 = V_185 ;
}
if ( args -> V_4 & V_197 ) {
V_29 = F_111 ( V_51 , V_99 ) ;
if ( V_29 )
goto error;
}
V_184 = args -> V_134 ;
if ( V_183 ) {
for ( V_28 = 0 ; V_28 < args -> V_187 ; V_28 ++ ) {
V_29 = F_118 ( V_99 , & V_183 [ V_28 ] ,
args -> V_174 , args -> V_175 ) ;
if ( V_29 )
goto error;
V_29 = V_99 -> V_198 ( V_99 ,
V_182 , V_184 ,
V_4 ) ;
if ( V_29 )
goto error;
}
} else {
V_29 = V_99 -> V_198 ( V_99 ,
V_182 , V_184 ,
V_4 ) ;
if ( V_29 )
return V_29 ;
}
F_123 ( V_99 , F_104 ( V_99 ) , V_4 ) ;
F_103 ( V_16 , V_99 ) ;
F_109 ( V_51 , V_23 , V_99 , V_181 ) ;
error:
F_30 ( V_183 ) ;
return V_29 ;
}
static int F_124 ( struct V_60 * V_51 ,
struct V_22 * V_23 )
{
struct V_67 * V_68 = V_51 -> V_69 ;
struct V_199 * V_200 = V_23 -> V_153 ;
if ( V_200 -> V_201 )
return V_200 -> V_201 -> V_150 ;
else {
int V_202 ;
F_83 ( & V_51 -> V_124 ) ;
if ( V_68 -> V_169 . V_203 == 0 ) {
V_202 = V_204 ;
V_68 -> V_169 . V_203 = 1 ;
} else {
V_202 = V_205 ;
V_68 -> V_169 . V_203 = 0 ;
}
V_200 -> V_201 = & V_68 -> V_99 [ V_202 ] ;
F_80 ( & V_51 -> V_124 ) ;
return V_202 ;
}
}
static struct V_24 *
F_125 ( struct V_1 * V_3 )
{
struct V_8 * V_38 = F_126 ( V_3 -> V_16 . V_206 , F_127 ( * V_38 ) , V_39 ) ;
V_38 -> V_40 -> V_4 |= V_105 ;
return V_38 -> V_25 ;
}
static int
F_128 ( struct V_60 * V_51 , void * V_207 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_67 * V_68 = V_51 -> V_69 ;
struct V_1 * V_3 ;
struct V_24 * V_181 ;
struct V_98 * V_99 ;
struct V_145 * V_147 ;
struct V_20 * V_21 ;
const T_7 V_146 = F_129 ( * args ) ;
T_6 V_182 = args -> V_133 ;
T_7 V_4 ;
int V_29 ;
bool V_112 ;
if ( ! F_93 ( args ) )
return - V_36 ;
V_29 = F_94 ( V_51 , V_19 , args -> V_7 ) ;
if ( V_29 )
return V_29 ;
V_4 = 0 ;
if ( args -> V_4 & V_208 ) {
if ( ! V_23 -> V_209 || ! F_130 ( V_210 ) )
return - V_211 ;
V_4 |= V_212 ;
}
if ( args -> V_4 & V_213 )
V_4 |= V_214 ;
if ( ( args -> V_4 & V_215 ) > V_216 ) {
F_12 ( L_25 ,
( int ) ( args -> V_4 & V_215 ) ) ;
return - V_36 ;
}
if ( ( args -> V_4 & V_215 ) == V_217 )
V_99 = & V_68 -> V_99 [ V_151 ] ;
else if ( ( args -> V_4 & V_215 ) == V_218 ) {
if ( F_131 ( V_51 ) ) {
int V_202 ;
V_202 = F_124 ( V_51 , V_23 ) ;
V_99 = & V_68 -> V_99 [ V_202 ] ;
} else
V_99 = & V_68 -> V_99 [ V_204 ] ;
} else
V_99 = & V_68 -> V_99 [ ( args -> V_4 & V_215 ) - 1 ] ;
if ( ! F_132 ( V_99 ) ) {
F_12 ( L_26 ,
( int ) ( args -> V_4 & V_215 ) ) ;
return - V_36 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_27 , args -> V_7 ) ;
return - V_36 ;
}
F_133 ( V_68 ) ;
V_29 = F_86 ( V_51 ) ;
if ( V_29 )
goto V_219;
V_147 = F_99 ( V_51 , V_23 , V_99 , V_146 ) ;
if ( F_18 ( V_147 ) ) {
F_80 ( & V_51 -> V_124 ) ;
V_29 = F_19 ( V_147 ) ;
goto V_219;
}
F_134 ( V_147 ) ;
if ( V_147 -> V_220 )
V_21 = & V_147 -> V_220 -> V_37 ;
else
V_21 = & V_68 -> V_71 . V_37 ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_135 ( V_147 ) ;
F_80 ( & V_51 -> V_124 ) ;
V_29 = - V_125 ;
goto V_219;
}
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_181 = F_125 ( V_3 ) ;
V_112 = ( args -> V_4 & V_128 ) == 0 ;
V_29 = F_72 ( V_99 , & V_3 -> V_16 , & V_112 ) ;
if ( V_29 )
goto V_34;
if ( V_112 )
V_29 = F_60 ( V_3 ) ;
if ( V_29 ) {
if ( V_29 == - V_90 ) {
V_29 = F_79 ( V_51 , args , V_23 , V_99 ,
V_3 , V_19 ) ;
F_136 ( ! F_137 ( & V_51 -> V_124 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_181 -> V_37 . V_87 ) {
F_12 ( L_28 ) ;
V_29 = - V_36 ;
goto V_34;
}
V_181 -> V_37 . V_86 |= V_120 ;
if ( F_138 ( V_99 ) ) {
V_29 = F_139 ( V_99 ,
V_181 ,
args -> V_133 ,
V_23 -> V_209 ) ;
if ( V_29 ) {
if ( V_29 != - V_221 )
goto V_34;
} else {
}
}
if ( V_4 & V_212 ) {
V_29 = F_140 ( V_181 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
V_182 += F_45 ( V_181 ) ;
} else
V_182 += F_141 ( V_181 , V_21 ) ;
V_29 = V_68 -> V_222 . V_223 ( V_51 , V_23 , V_99 , V_147 , args ,
& V_3 -> V_16 , V_181 , V_182 , V_4 ) ;
if ( V_4 & V_212 )
F_142 ( V_181 ) ;
V_34:
F_135 ( V_147 ) ;
F_29 ( V_3 ) ;
F_80 ( & V_51 -> V_124 ) ;
V_219:
F_143 ( V_68 ) ;
return V_29 ;
}
int
F_144 ( struct V_60 * V_51 , void * V_207 ,
struct V_22 * V_23 )
{
struct V_224 * args = V_207 ;
struct V_2 V_225 ;
struct V_226 * V_39 = NULL ;
struct V_18 * V_227 = NULL ;
int V_29 , V_28 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_27 , args -> V_7 ) ;
return - V_36 ;
}
V_39 = F_81 ( sizeof( * V_39 ) , args -> V_7 ) ;
V_227 = F_81 ( sizeof( * V_227 ) , args -> V_7 ) ;
if ( V_39 == NULL || V_227 == NULL ) {
F_12 ( L_29 ,
args -> V_7 ) ;
F_82 ( V_39 ) ;
F_82 ( V_227 ) ;
return - V_125 ;
}
V_29 = F_84 ( V_39 ,
F_55 ( args -> V_228 ) ,
sizeof( * V_39 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_30 ,
args -> V_7 , V_29 ) ;
F_82 ( V_39 ) ;
F_82 ( V_227 ) ;
return - V_90 ;
}
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_227 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_227 [ V_28 ] . V_95 = V_39 [ V_28 ] . V_95 ;
V_227 [ V_28 ] . V_94 = V_39 [ V_28 ] . V_94 ;
V_227 [ V_28 ] . V_108 = V_39 [ V_28 ] . V_108 ;
V_227 [ V_28 ] . V_62 = V_39 [ V_28 ] . V_62 ;
if ( F_39 ( V_51 ) -> V_66 < 4 )
V_227 [ V_28 ] . V_4 = V_109 ;
else
V_227 [ V_28 ] . V_4 = 0 ;
}
V_225 . V_228 = args -> V_228 ;
V_225 . V_7 = args -> V_7 ;
V_225 . V_133 = args -> V_133 ;
V_225 . V_134 = args -> V_134 ;
V_225 . V_174 = args -> V_174 ;
V_225 . V_175 = args -> V_175 ;
V_225 . V_187 = args -> V_187 ;
V_225 . V_189 = args -> V_189 ;
V_225 . V_4 = V_229 ;
F_145 ( V_225 , 0 ) ;
V_29 = F_128 ( V_51 , V_207 , V_23 , & V_225 , V_227 ) ;
if ( ! V_29 ) {
struct V_226 T_5 * V_230 =
F_55 ( args -> V_228 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_85 ( & V_230 [ V_28 ] . V_62 ,
& V_227 [ V_28 ] . V_62 ,
sizeof( V_230 [ V_28 ] . V_62 ) ) ;
if ( V_29 ) {
V_29 = - V_90 ;
F_12 ( L_31
L_32 ,
args -> V_7 , V_29 ) ;
break;
}
}
}
F_82 ( V_39 ) ;
F_82 ( V_227 ) ;
return V_29 ;
}
int
F_146 ( struct V_60 * V_51 , void * V_207 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_207 ;
struct V_18 * V_227 = NULL ;
int V_29 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_137 / sizeof( * V_227 ) ) {
F_12 ( L_33 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_231 != 0 ) {
F_12 ( L_34 ) ;
return - V_36 ;
}
V_227 = F_2 ( sizeof( * V_227 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_227 == NULL )
V_227 = F_81 ( sizeof( * V_227 ) ,
args -> V_7 ) ;
if ( V_227 == NULL ) {
F_12 ( L_29 ,
args -> V_7 ) ;
return - V_125 ;
}
V_29 = F_84 ( V_227 ,
F_55 ( args -> V_228 ) ,
sizeof( * V_227 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_30 ,
args -> V_7 , V_29 ) ;
F_82 ( V_227 ) ;
return - V_90 ;
}
V_29 = F_128 ( V_51 , V_207 , V_23 , args , V_227 ) ;
if ( ! V_29 ) {
struct V_18 T_5 * V_230 =
F_55 ( args -> V_228 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_85 ( & V_230 [ V_28 ] . V_62 ,
& V_227 [ V_28 ] . V_62 ,
sizeof( V_230 [ V_28 ] . V_62 ) ) ;
if ( V_29 ) {
V_29 = - V_90 ;
F_12 ( L_31
L_35 ,
args -> V_7 ) ;
break;
}
}
}
F_82 ( V_227 ) ;
return V_29 ;
}
