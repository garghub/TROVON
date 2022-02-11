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
struct V_8 * V_38 ;
V_44 = & V_3 -> V_17 [ V_32 & V_3 -> V_15 ] ;
F_24 (vma, head, exec_node) {
if ( V_38 -> V_42 == V_32 )
return V_38 ;
}
return NULL ;
}
}
static void
F_25 ( struct V_8 * V_38 )
{
struct V_18 * V_45 ;
struct V_24 * V_25 = V_38 -> V_25 ;
if ( ! F_26 ( & V_38 -> V_46 ) )
return;
V_45 = V_38 -> V_40 ;
if ( V_45 -> V_4 & V_47 )
F_27 ( V_25 ) ;
if ( V_45 -> V_4 & V_48 )
V_38 -> V_49 -- ;
V_45 -> V_4 &= ~ ( V_47 | V_48 ) ;
}
static void F_28 ( struct V_1 * V_3 )
{
while ( ! F_13 ( & V_3 -> V_16 ) ) {
struct V_8 * V_38 ;
V_38 = F_16 ( & V_3 -> V_16 ,
struct V_8 ,
V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_25 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_29 ( V_3 ) ;
}
static inline int F_30 ( struct V_24 * V_25 )
{
return ( F_31 ( V_25 -> V_37 . V_50 ) ||
V_25 -> V_37 . V_51 == V_52 ||
V_25 -> V_53 != V_54 ) ;
}
static inline T_2 F_32 ( T_2 V_55 )
{
return F_33 ( V_55 , V_56 ) ;
}
static inline T_2 F_34 ( T_2 V_55 )
{
return V_55 & ( ( 1ULL << ( V_56 + 1 ) ) - 1 ) ;
}
static inline T_2
F_35 ( struct V_57 * V_58 ,
T_2 V_59 )
{
return F_32 ( ( int ) V_58 -> V_60 + V_59 ) ;
}
static int
F_36 ( struct V_24 * V_25 ,
struct V_57 * V_58 ,
T_2 V_59 )
{
struct V_61 * V_50 = V_25 -> V_37 . V_50 ;
T_1 V_62 = F_37 ( V_58 -> V_63 ) ;
T_2 V_60 = F_35 ( V_58 , V_59 ) ;
char * V_64 ;
int V_29 ;
V_29 = F_38 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_64 = F_39 ( F_40 ( V_25 ,
V_58 -> V_63 >> V_65 ) ) ;
* ( T_1 * ) ( V_64 + V_62 ) = F_41 ( V_60 ) ;
if ( F_42 ( V_50 ) -> V_66 >= 8 ) {
V_62 = F_37 ( V_62 + sizeof( T_1 ) ) ;
if ( V_62 == 0 ) {
F_43 ( V_64 ) ;
V_64 = F_39 ( F_40 ( V_25 ,
( V_58 -> V_63 + sizeof( T_1 ) ) >> V_65 ) ) ;
}
* ( T_1 * ) ( V_64 + V_62 ) = F_44 ( V_60 ) ;
}
F_43 ( V_64 ) ;
return 0 ;
}
static int
F_45 ( struct V_24 * V_25 ,
struct V_57 * V_58 ,
T_2 V_59 )
{
struct V_61 * V_50 = V_25 -> V_37 . V_50 ;
struct V_67 * V_68 = F_46 ( V_50 ) ;
struct V_69 * V_70 = & V_68 -> V_70 ;
T_2 V_60 = F_35 ( V_58 , V_59 ) ;
T_2 V_63 ;
void T_3 * V_71 ;
int V_29 ;
V_29 = F_47 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_29 = F_48 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_63 = F_49 ( V_25 ) ;
V_63 += V_58 -> V_63 ;
V_71 = F_50 ( V_70 -> V_72 ,
V_63 & V_73 ) ;
F_51 ( F_41 ( V_60 ) , V_71 + F_37 ( V_63 ) ) ;
if ( F_42 ( V_50 ) -> V_66 >= 8 ) {
V_63 += sizeof( T_1 ) ;
if ( F_37 ( V_63 ) == 0 ) {
F_52 ( V_71 ) ;
V_71 =
F_50 ( V_70 -> V_72 ,
V_63 ) ;
}
F_51 ( F_44 ( V_60 ) ,
V_71 + F_37 ( V_63 ) ) ;
}
F_52 ( V_71 ) ;
return 0 ;
}
static void
F_53 ( void * V_74 , T_1 V_75 )
{
F_54 ( V_74 , sizeof( T_1 ) ) ;
* ( T_1 * ) V_74 = V_75 ;
F_54 ( V_74 , sizeof( T_1 ) ) ;
}
static int
F_55 ( struct V_24 * V_25 ,
struct V_57 * V_58 ,
T_2 V_59 )
{
struct V_61 * V_50 = V_25 -> V_37 . V_50 ;
T_1 V_62 = F_37 ( V_58 -> V_63 ) ;
T_2 V_60 = F_35 ( V_58 , V_59 ) ;
char * V_64 ;
int V_29 ;
V_29 = F_47 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_64 = F_39 ( F_40 ( V_25 ,
V_58 -> V_63 >> V_65 ) ) ;
F_53 ( V_64 + V_62 , F_41 ( V_60 ) ) ;
if ( F_42 ( V_50 ) -> V_66 >= 8 ) {
V_62 = F_37 ( V_62 + sizeof( T_1 ) ) ;
if ( V_62 == 0 ) {
F_43 ( V_64 ) ;
V_64 = F_39 ( F_40 ( V_25 ,
( V_58 -> V_63 + sizeof( T_1 ) ) >> V_65 ) ) ;
}
F_53 ( V_64 + V_62 , F_44 ( V_60 ) ) ;
}
F_43 ( V_64 ) ;
return 0 ;
}
static int
F_56 ( struct V_24 * V_25 ,
struct V_1 * V_3 ,
struct V_57 * V_58 )
{
struct V_61 * V_50 = V_25 -> V_37 . V_50 ;
struct V_76 * V_77 ;
struct V_24 * V_78 ;
struct V_8 * V_79 ;
T_2 V_59 ;
int V_29 ;
V_79 = F_23 ( V_3 , V_58 -> V_80 ) ;
if ( F_57 ( V_79 == NULL ) )
return - V_33 ;
V_78 = V_79 -> V_25 ;
V_77 = & V_79 -> V_25 -> V_37 ;
V_59 = F_32 ( V_79 -> V_46 . V_81 ) ;
if ( F_57 ( F_58 ( V_50 ) &&
V_58 -> V_51 == V_82 ) ) {
V_29 = F_59 ( V_79 , V_78 -> V_53 ,
V_83 ) ;
if ( F_60 ( V_29 , L_4 ) )
return V_29 ;
}
if ( F_57 ( V_58 -> V_51 & ( V_58 -> V_51 - 1 ) ) ) {
F_12 ( L_5
L_6
L_7 ,
V_25 , V_58 -> V_80 ,
( int ) V_58 -> V_63 ,
V_58 -> V_84 ,
V_58 -> V_51 ) ;
return - V_36 ;
}
if ( F_57 ( ( V_58 -> V_51 | V_58 -> V_84 )
& ~ V_85 ) ) {
F_12 ( L_8
L_6
L_7 ,
V_25 , V_58 -> V_80 ,
( int ) V_58 -> V_63 ,
V_58 -> V_84 ,
V_58 -> V_51 ) ;
return - V_36 ;
}
V_77 -> V_86 |= V_58 -> V_84 ;
V_77 -> V_87 |= V_58 -> V_51 ;
if ( V_59 == V_58 -> V_88 )
return 0 ;
if ( F_57 ( V_58 -> V_63 >
V_25 -> V_37 . V_6 - ( F_42 ( V_50 ) -> V_66 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_9
L_10 ,
V_25 , V_58 -> V_80 ,
( int ) V_58 -> V_63 ,
( int ) V_25 -> V_37 . V_6 ) ;
return - V_36 ;
}
if ( F_57 ( V_58 -> V_63 & 3 ) ) {
F_12 ( L_11
L_12 ,
V_25 , V_58 -> V_80 ,
( int ) V_58 -> V_63 ) ;
return - V_36 ;
}
if ( V_25 -> V_89 && F_61 () )
return - V_90 ;
if ( F_30 ( V_25 ) )
V_29 = F_36 ( V_25 , V_58 , V_59 ) ;
else if ( V_25 -> V_91 )
V_29 = F_45 ( V_25 , V_58 , V_59 ) ;
else if ( F_62 ( V_92 ) )
V_29 = F_55 ( V_25 , V_58 , V_59 ) ;
else {
F_60 ( 1 , L_13 ) ;
V_29 = - V_93 ;
}
if ( V_29 )
return V_29 ;
V_58 -> V_88 = V_59 ;
return 0 ;
}
static int
F_63 ( struct V_8 * V_38 ,
struct V_1 * V_3 )
{
#define F_64 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_57 V_94 [ F_64 ( 512 ) ] ;
struct V_57 T_5 * V_95 ;
struct V_18 * V_45 = V_38 -> V_40 ;
int V_96 , V_29 ;
V_95 = F_65 ( V_45 -> V_97 ) ;
V_96 = V_45 -> V_98 ;
while ( V_96 ) {
struct V_57 * V_99 = V_94 ;
int V_12 = V_96 ;
if ( V_12 > F_66 ( V_94 ) )
V_12 = F_66 ( V_94 ) ;
V_96 -= V_12 ;
if ( F_67 ( V_99 , V_95 , V_12 * sizeof( V_99 [ 0 ] ) ) )
return - V_90 ;
do {
T_6 V_63 = V_99 -> V_88 ;
V_29 = F_56 ( V_38 -> V_25 , V_3 , V_99 ) ;
if ( V_29 )
return V_29 ;
if ( V_99 -> V_88 != V_63 &&
F_68 ( V_99 -> V_88 , & V_95 -> V_88 ) ) {
return - V_90 ;
}
V_95 ++ ;
V_99 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_64
}
static int
F_69 ( struct V_8 * V_38 ,
struct V_1 * V_3 ,
struct V_57 * V_100 )
{
const struct V_18 * V_45 = V_38 -> V_40 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_45 -> V_98 ; V_28 ++ ) {
V_29 = F_56 ( V_38 -> V_25 , V_3 , & V_100 [ V_28 ] ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_70 ( struct V_1 * V_3 )
{
struct V_8 * V_38 ;
int V_29 = 0 ;
F_71 () ;
F_72 (vma, &eb->vmas, exec_list) {
V_29 = F_63 ( V_38 , V_3 ) ;
if ( V_29 )
break;
}
F_73 () ;
return V_29 ;
}
static bool F_74 ( unsigned int V_4 )
{
return ( V_4 & ( V_101 | V_102 ) ) ==
V_102 ;
}
static int
F_75 ( struct V_8 * V_38 ,
struct V_103 * V_104 ,
bool * V_105 )
{
struct V_24 * V_25 = V_38 -> V_25 ;
struct V_18 * V_45 = V_38 -> V_40 ;
T_2 V_4 ;
int V_29 ;
V_4 = V_106 ;
if ( V_45 -> V_4 & V_107 )
V_4 |= V_83 ;
if ( ! F_26 ( & V_38 -> V_46 ) ) {
if ( ( V_45 -> V_4 & V_108 ) == 0 )
V_4 |= V_109 ;
if ( V_45 -> V_4 & V_102 )
V_4 |= V_83 | V_110 ;
if ( V_45 -> V_4 & V_111 )
V_4 |= V_112 | V_113 ;
if ( V_45 -> V_4 & V_114 )
V_4 |= V_45 -> V_63 | V_115 ;
if ( ( V_4 & V_110 ) == 0 )
V_4 |= V_116 ;
}
V_29 = F_76 ( V_25 , V_38 -> V_21 , V_45 -> V_117 , V_4 ) ;
if ( ( V_29 == - V_118 || V_29 == - V_119 ) &&
F_74 ( V_45 -> V_4 ) )
V_29 = F_76 ( V_25 , V_38 -> V_21 ,
V_45 -> V_117 ,
V_4 & ~ V_110 ) ;
if ( V_29 )
return V_29 ;
V_45 -> V_4 |= V_48 ;
if ( V_45 -> V_4 & V_101 ) {
V_29 = F_77 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_78 ( V_25 ) )
V_45 -> V_4 |= V_47 ;
}
if ( V_45 -> V_63 != V_38 -> V_46 . V_81 ) {
V_45 -> V_63 = V_38 -> V_46 . V_81 ;
* V_105 = true ;
}
if ( V_45 -> V_4 & V_120 ) {
V_25 -> V_37 . V_86 = V_121 ;
V_25 -> V_37 . V_87 = V_121 ;
}
return 0 ;
}
static bool
F_79 ( struct V_8 * V_38 )
{
struct V_18 * V_45 = V_38 -> V_40 ;
if ( V_45 -> V_98 == 0 )
return false ;
if ( ! V_38 -> V_122 )
return false ;
if ( F_31 ( V_38 -> V_25 -> V_37 . V_50 ) )
return false ;
if ( V_38 -> V_25 -> V_37 . V_51 == V_52 )
return false ;
return true ;
}
static bool
F_80 ( struct V_8 * V_38 )
{
struct V_18 * V_45 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
F_81 ( V_45 -> V_4 & V_102 && ! V_38 -> V_122 ) ;
if ( V_45 -> V_117 &&
V_38 -> V_46 . V_81 & ( V_45 -> V_117 - 1 ) )
return true ;
if ( V_45 -> V_4 & V_114 &&
V_38 -> V_46 . V_81 != V_45 -> V_63 )
return true ;
if ( V_45 -> V_4 & V_111 &&
V_38 -> V_46 . V_81 < V_112 )
return true ;
if ( V_45 -> V_4 & V_102 && ! V_25 -> V_91 )
return ! F_74 ( V_45 -> V_4 ) ;
if ( ( V_45 -> V_4 & V_108 ) == 0 &&
( V_38 -> V_46 . V_81 + V_38 -> V_46 . V_6 - 1 ) >> 32 )
return true ;
return false ;
}
static int
F_82 ( struct V_103 * V_104 ,
struct V_26 * V_16 ,
struct V_123 * V_124 ,
bool * V_125 )
{
struct V_24 * V_25 ;
struct V_8 * V_38 ;
struct V_20 * V_21 ;
struct V_26 V_126 ;
struct V_26 V_127 ;
bool V_128 = F_83 ( V_104 -> V_129 ) < 4 ;
int V_130 ;
F_84 ( V_104 ) ;
V_21 = F_16 ( V_16 , struct V_8 , V_39 ) -> V_21 ;
F_5 ( & V_126 ) ;
F_5 ( & V_127 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_45 ;
bool V_131 , V_132 ;
V_38 = F_16 ( V_16 , struct V_8 , V_39 ) ;
V_25 = V_38 -> V_25 ;
V_45 = V_38 -> V_40 ;
if ( V_124 -> V_4 & V_133 )
V_45 -> V_4 |= V_111 ;
if ( ! V_128 )
V_45 -> V_4 &= ~ V_101 ;
V_131 =
V_45 -> V_4 & V_101 &&
V_25 -> V_134 != V_135 ;
V_132 = V_131 || F_79 ( V_38 ) ;
if ( V_45 -> V_4 & V_114 )
F_85 ( & V_38 -> V_39 , & V_127 ) ;
else if ( V_132 ) {
V_45 -> V_4 |= V_102 ;
F_86 ( & V_38 -> V_39 , & V_126 ) ;
} else
F_85 ( & V_38 -> V_39 , & V_126 ) ;
V_25 -> V_37 . V_86 = V_85 & ~ V_136 ;
V_25 -> V_37 . V_87 = 0 ;
}
F_87 ( & V_126 , V_16 ) ;
F_87 ( & V_127 , V_16 ) ;
V_130 = 0 ;
do {
int V_29 = 0 ;
F_72 (vma, vmas, exec_list) {
if ( ! F_26 ( & V_38 -> V_46 ) )
continue;
if ( F_80 ( V_38 ) )
V_29 = F_88 ( V_38 ) ;
else
V_29 = F_75 ( V_38 ,
V_104 ,
V_125 ) ;
if ( V_29 )
goto V_34;
}
F_72 (vma, vmas, exec_list) {
if ( F_26 ( & V_38 -> V_46 ) )
continue;
V_29 = F_75 ( V_38 , V_104 ,
V_125 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_118 || V_130 ++ )
return V_29 ;
F_72 (vma, vmas, exec_list)
F_25 ( V_38 ) ;
V_29 = F_89 ( V_21 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_90 ( struct V_61 * V_50 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_103 * V_104 ,
struct V_1 * V_3 ,
struct V_18 * V_19 ,
struct V_123 * V_124 )
{
struct V_57 * V_58 ;
struct V_20 * V_21 ;
struct V_8 * V_38 ;
bool V_125 ;
int * V_137 ;
int V_28 , V_138 , V_29 ;
unsigned V_12 = args -> V_7 ;
V_21 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) -> V_21 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_38 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_25 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_91 ( & V_50 -> V_139 ) ;
V_138 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
V_138 += V_19 [ V_28 ] . V_98 ;
V_137 = F_92 ( V_12 , sizeof( * V_137 ) ) ;
V_58 = F_92 ( V_138 , sizeof( * V_58 ) ) ;
if ( V_58 == NULL || V_137 == NULL ) {
F_93 ( V_58 ) ;
F_93 ( V_137 ) ;
F_94 ( & V_50 -> V_139 ) ;
return - V_140 ;
}
V_138 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
struct V_57 T_5 * V_95 ;
T_6 V_141 = ( T_6 ) - 1 ;
int V_142 ;
V_95 = F_65 ( V_19 [ V_28 ] . V_97 ) ;
if ( F_95 ( V_58 + V_138 , V_95 ,
V_19 [ V_28 ] . V_98 * sizeof( * V_58 ) ) ) {
V_29 = - V_90 ;
F_94 ( & V_50 -> V_139 ) ;
goto V_34;
}
for ( V_142 = 0 ; V_142 < V_19 [ V_28 ] . V_98 ; V_142 ++ ) {
if ( F_96 ( & V_95 [ V_142 ] . V_88 ,
& V_141 ,
sizeof( V_141 ) ) ) {
V_29 = - V_90 ;
F_94 ( & V_50 -> V_139 ) ;
goto V_34;
}
}
V_137 [ V_28 ] = V_138 ;
V_138 += V_19 [ V_28 ] . V_98 ;
}
V_29 = F_97 ( V_50 ) ;
if ( V_29 ) {
F_94 ( & V_50 -> V_139 ) ;
goto V_34;
}
F_6 ( V_3 ) ;
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_125 = ( args -> V_4 & V_143 ) == 0 ;
V_29 = F_82 ( V_104 , & V_3 -> V_16 , V_124 ,
& V_125 ) ;
if ( V_29 )
goto V_34;
F_72 (vma, &eb->vmas, exec_list) {
int V_63 = V_38 -> V_40 - V_19 ;
V_29 = F_69 ( V_38 , V_3 ,
V_58 + V_137 [ V_63 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_93 ( V_58 ) ;
F_93 ( V_137 ) ;
return V_29 ;
}
static int
F_98 ( struct V_144 * V_145 ,
struct V_26 * V_16 )
{
const unsigned V_146 = ~ F_99 ( V_145 -> V_104 ) ;
struct V_8 * V_38 ;
int V_29 ;
F_72 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
if ( V_25 -> V_89 & V_146 ) {
V_29 = F_100 ( V_25 , V_145 -> V_104 , & V_145 ) ;
if ( V_29 )
return V_29 ;
}
if ( V_25 -> V_37 . V_51 & V_52 )
F_101 ( V_25 , false ) ;
}
F_102 ( V_145 -> V_104 -> V_129 ) ;
return F_103 ( V_145 ) ;
}
static bool
F_104 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_147 )
return false ;
if ( V_19 -> V_148 || V_19 -> V_149 )
return false ;
if ( V_19 -> V_150 == 0xffffffff ) {
F_12 ( L_14 ) ;
V_19 -> V_150 = 0 ;
}
if ( V_19 -> V_151 || V_19 -> V_150 )
return false ;
if ( ( V_19 -> V_152 | V_19 -> V_153 ) & 0x7 )
return false ;
return true ;
}
static int
F_105 ( struct V_61 * V_50 ,
struct V_18 * V_19 ,
int V_12 )
{
unsigned V_154 = 0 ;
unsigned V_155 = V_156 / sizeof( struct V_57 ) ;
unsigned V_157 ;
int V_28 ;
V_157 = V_158 ;
if ( F_106 ( V_50 ) )
V_157 |= V_107 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
char T_5 * V_159 = F_65 ( V_19 [ V_28 ] . V_97 ) ;
int V_160 ;
if ( V_19 [ V_28 ] . V_4 & V_157 )
return - V_36 ;
if ( V_19 [ V_28 ] . V_4 & V_114 ) {
if ( V_19 [ V_28 ] . V_63 !=
F_32 ( V_19 [ V_28 ] . V_63 & V_73 ) )
return - V_36 ;
V_19 [ V_28 ] . V_63 = F_34 ( V_19 [ V_28 ] . V_63 ) ;
}
if ( V_19 [ V_28 ] . V_117 && ! F_107 ( V_19 [ V_28 ] . V_117 ) )
return - V_36 ;
if ( V_19 [ V_28 ] . V_98 > V_155 - V_154 )
return - V_36 ;
V_154 += V_19 [ V_28 ] . V_98 ;
V_160 = V_19 [ V_28 ] . V_98 *
sizeof( struct V_57 ) ;
if ( ! F_108 ( V_161 , V_159 , V_160 ) )
return - V_90 ;
if ( F_109 ( ! V_129 . V_162 ) ) {
if ( F_110 ( V_159 , V_160 ) )
return - V_90 ;
}
}
return 0 ;
}
static struct V_123 *
F_111 ( struct V_61 * V_50 , struct V_22 * V_23 ,
struct V_103 * V_104 , const T_7 V_163 )
{
struct V_123 * V_124 = NULL ;
struct V_164 * V_165 ;
if ( V_104 -> V_166 != V_167 && V_163 != V_168 )
return F_112 ( - V_36 ) ;
V_124 = F_113 ( V_23 -> V_169 , V_163 ) ;
if ( F_18 ( V_124 ) )
return V_124 ;
V_165 = & V_124 -> V_170 ;
if ( V_165 -> V_171 ) {
F_12 ( L_15 , V_163 ) ;
return F_112 ( - V_172 ) ;
}
return V_124 ;
}
void
F_114 ( struct V_26 * V_16 ,
struct V_144 * V_145 )
{
struct V_103 * V_104 = F_115 ( V_145 ) ;
struct V_8 * V_38 ;
F_72 (vma, vmas, exec_list) {
struct V_18 * V_45 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
T_7 V_173 = V_25 -> V_37 . V_84 ;
T_7 V_174 = V_25 -> V_37 . V_51 ;
V_25 -> V_175 = 1 ;
V_25 -> V_37 . V_51 = V_25 -> V_37 . V_87 ;
if ( V_25 -> V_37 . V_51 == 0 )
V_25 -> V_37 . V_86 |= V_25 -> V_37 . V_84 ;
V_25 -> V_37 . V_84 = V_25 -> V_37 . V_86 ;
F_116 ( V_38 , V_145 ) ;
if ( V_25 -> V_37 . V_51 ) {
F_117 ( & V_25 -> V_176 , V_145 ) ;
F_118 ( V_25 , V_177 ) ;
V_25 -> V_37 . V_51 &= ~ V_85 ;
}
if ( V_45 -> V_4 & V_101 ) {
F_117 ( & V_25 -> V_178 , V_145 ) ;
if ( V_45 -> V_4 & V_47 ) {
struct V_67 * V_68 = V_104 -> V_129 ;
F_85 ( & V_68 -> V_179 [ V_25 -> V_180 ] . V_181 ,
& V_68 -> V_182 . V_183 ) ;
}
}
F_119 ( V_25 , V_173 , V_174 ) ;
}
}
static void
F_120 ( struct V_184 * V_185 )
{
V_185 -> V_104 -> V_186 = true ;
F_121 ( V_185 -> V_187 , V_185 -> V_188 , true ) ;
}
static int
F_122 ( struct V_61 * V_50 ,
struct V_144 * V_145 )
{
struct V_103 * V_104 = V_145 -> V_104 ;
struct V_67 * V_68 = F_46 ( V_50 ) ;
int V_29 , V_28 ;
if ( ! F_123 ( V_50 ) || V_104 != & V_68 -> V_104 [ V_167 ] ) {
F_12 ( L_16 ) ;
return - V_36 ;
}
V_29 = F_124 ( V_145 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_125 ( V_104 , F_126 ( 1 ) ) ;
F_127 ( V_104 , F_128 ( V_28 ) ) ;
F_125 ( V_104 , 0 ) ;
}
F_129 ( V_104 ) ;
return 0 ;
}
static struct V_24 *
F_130 ( struct V_103 * V_104 ,
struct V_18 * V_189 ,
struct V_1 * V_3 ,
struct V_24 * V_188 ,
T_7 V_152 ,
T_7 V_153 ,
bool V_190 )
{
struct V_24 * V_191 ;
struct V_8 * V_38 ;
int V_29 ;
V_191 = F_131 ( & V_104 -> V_192 ,
F_132 ( V_153 ) ) ;
if ( F_18 ( V_191 ) )
return V_191 ;
V_29 = F_133 ( V_104 ,
V_188 ,
V_191 ,
V_152 ,
V_153 ,
V_190 ) ;
if ( V_29 )
goto V_34;
V_29 = F_134 ( V_191 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
F_135 ( V_191 ) ;
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
V_38 = F_136 ( V_191 ) ;
V_38 -> V_40 = V_189 ;
V_38 -> V_40 -> V_4 = V_48 ;
F_14 ( & V_191 -> V_37 ) ;
F_15 ( & V_38 -> V_39 , & V_3 -> V_16 ) ;
V_191 -> V_37 . V_86 = V_136 ;
return V_191 ;
V_34:
F_135 ( V_191 ) ;
if ( V_29 == - V_193 )
return V_188 ;
else
return F_112 ( V_29 ) ;
}
int
F_137 ( struct V_184 * V_185 ,
struct V_2 * args ,
struct V_26 * V_16 )
{
struct V_61 * V_50 = V_185 -> V_50 ;
struct V_103 * V_104 = V_185 -> V_104 ;
struct V_67 * V_68 = F_46 ( V_50 ) ;
T_6 V_194 , V_195 ;
int V_196 ;
T_7 V_197 ;
int V_29 ;
V_29 = F_98 ( V_185 -> V_187 , V_16 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_138 ( V_185 -> V_187 ) ;
if ( V_29 )
return V_29 ;
F_139 ( V_185 -> V_124 -> V_198 && V_185 -> V_124 -> V_198 -> V_199 & ( 1 << V_104 -> V_166 ) ,
L_17 , V_104 -> V_200 ) ;
V_196 = args -> V_4 & V_201 ;
V_197 = V_201 ;
switch ( V_196 ) {
case V_202 :
case V_203 :
case V_204 :
if ( V_196 != 0 && V_104 != & V_68 -> V_104 [ V_167 ] ) {
F_12 ( L_18 ) ;
return - V_36 ;
}
if ( V_196 != V_68 -> V_205 ) {
if ( F_42 ( V_50 ) -> V_66 < 4 ) {
F_12 ( L_19 ) ;
return - V_36 ;
}
if ( F_42 ( V_50 ) -> V_66 > 5 &&
V_196 == V_204 ) {
F_12 ( L_20 ) ;
return - V_36 ;
}
if ( F_42 ( V_50 ) -> V_66 >= 6 )
V_197 &= ~ V_204 ;
}
break;
default:
F_12 ( L_21 , V_196 ) ;
return - V_36 ;
}
if ( V_104 == & V_68 -> V_104 [ V_167 ] &&
V_196 != V_68 -> V_205 ) {
V_29 = F_124 ( V_185 -> V_187 , 4 ) ;
if ( V_29 )
return V_29 ;
F_125 ( V_104 , V_206 ) ;
F_125 ( V_104 , F_126 ( 1 ) ) ;
F_127 ( V_104 , V_207 ) ;
F_125 ( V_104 , V_197 << 16 | V_196 ) ;
F_129 ( V_104 ) ;
V_68 -> V_205 = V_196 ;
}
if ( args -> V_4 & V_208 ) {
V_29 = F_122 ( V_50 , V_185 -> V_187 ) ;
if ( V_29 )
return V_29 ;
}
V_195 = args -> V_153 ;
V_194 = V_185 -> V_209 +
V_185 -> V_210 ;
if ( V_195 == 0 )
V_195 = V_185 -> V_188 -> V_37 . V_6 ;
V_29 = V_104 -> V_211 ( V_185 -> V_187 ,
V_194 , V_195 ,
V_185 -> V_212 ) ;
if ( V_29 )
return V_29 ;
F_140 ( V_185 -> V_187 , V_185 -> V_212 ) ;
F_114 ( V_16 , V_185 -> V_187 ) ;
return 0 ;
}
static unsigned int
F_141 ( struct V_67 * V_68 , struct V_22 * V_23 )
{
struct V_213 * V_214 = V_23 -> V_169 ;
if ( ( int ) V_214 -> V_215 < 0 ) {
F_94 ( & V_68 -> V_216 . V_139 ) ;
V_214 -> V_215 = V_68 -> V_182 . V_217 ;
V_68 -> V_182 . V_217 ^= 1 ;
F_91 ( & V_68 -> V_216 . V_139 ) ;
}
return V_214 -> V_215 ;
}
static struct V_24 *
F_142 ( struct V_1 * V_3 )
{
struct V_8 * V_38 = F_143 ( V_3 -> V_16 . V_218 , F_144 ( * V_38 ) , V_39 ) ;
if ( ( V_38 -> V_40 -> V_4 & V_114 ) == 0 )
V_38 -> V_40 -> V_4 |= V_111 ;
return V_38 -> V_25 ;
}
static int
F_145 ( struct V_67 * V_68 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_103 * * V_219 )
{
unsigned int V_220 = args -> V_4 & V_221 ;
if ( V_220 > V_222 ) {
F_12 ( L_22 , V_220 ) ;
return - V_36 ;
}
if ( ( V_220 != V_223 ) &&
( ( args -> V_4 & V_224 ) != 0 ) ) {
F_12 ( L_23
L_24 , ( int ) ( args -> V_4 ) ) ;
return - V_36 ;
}
if ( V_220 == V_223 && F_146 ( V_68 ) ) {
unsigned int V_225 = args -> V_4 & V_224 ;
if ( V_225 == V_226 ) {
V_225 = F_141 ( V_68 , V_23 ) ;
} else if ( V_225 >= V_227 &&
V_225 <= V_228 ) {
V_225 >>= V_229 ;
V_225 -- ;
} else {
F_12 ( L_25 ,
V_225 ) ;
return - V_36 ;
}
* V_219 = & V_68 -> V_104 [ F_147 ( V_225 ) ] ;
} else {
* V_219 = & V_68 -> V_104 [ V_230 [ V_220 ] ] ;
}
if ( ! F_148 ( * V_219 ) ) {
F_12 ( L_26 , V_220 ) ;
return - V_36 ;
}
return 0 ;
}
static int
F_149 ( struct V_61 * V_50 , void * V_231 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_67 * V_68 = F_46 ( V_50 ) ;
struct V_69 * V_70 = & V_68 -> V_70 ;
struct V_144 * V_145 = NULL ;
struct V_1 * V_3 ;
struct V_24 * V_188 ;
struct V_18 V_189 ;
struct V_103 * V_104 ;
struct V_123 * V_124 ;
struct V_20 * V_21 ;
struct V_184 V_232 ;
struct V_184 * V_185 = & V_232 ;
const T_7 V_163 = F_150 ( * args ) ;
T_7 V_212 ;
int V_29 ;
bool V_125 ;
if ( ! F_104 ( args ) )
return - V_36 ;
V_29 = F_105 ( V_50 , V_19 , args -> V_7 ) ;
if ( V_29 )
return V_29 ;
V_212 = 0 ;
if ( args -> V_4 & V_233 ) {
if ( ! F_151 ( V_23 ) || ! F_152 ( V_234 ) )
return - V_235 ;
V_212 |= V_236 ;
}
if ( args -> V_4 & V_237 )
V_212 |= V_238 ;
V_29 = F_145 ( V_68 , V_23 , args , & V_104 ) ;
if ( V_29 )
return V_29 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_27 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_4 & V_239 ) {
if ( ! F_153 ( V_50 ) ) {
F_12 ( L_28 ) ;
return - V_36 ;
}
if ( V_104 -> V_166 != V_167 ) {
F_12 ( L_29 ,
V_104 -> V_200 ) ;
return - V_36 ;
}
V_212 |= V_240 ;
}
F_154 ( V_68 ) ;
V_29 = F_97 ( V_50 ) ;
if ( V_29 )
goto V_241;
V_124 = F_111 ( V_50 , V_23 , V_104 , V_163 ) ;
if ( F_18 ( V_124 ) ) {
F_91 ( & V_50 -> V_139 ) ;
V_29 = F_19 ( V_124 ) ;
goto V_241;
}
F_155 ( V_124 ) ;
if ( V_124 -> V_198 )
V_21 = & V_124 -> V_198 -> V_37 ;
else
V_21 = & V_70 -> V_37 ;
memset ( & V_232 , 0x00 , sizeof( V_232 ) ) ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_156 ( V_124 ) ;
F_91 ( & V_50 -> V_139 ) ;
V_29 = - V_140 ;
goto V_241;
}
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_188 = F_142 ( V_3 ) ;
V_125 = ( args -> V_4 & V_143 ) == 0 ;
V_29 = F_82 ( V_104 , & V_3 -> V_16 , V_124 ,
& V_125 ) ;
if ( V_29 )
goto V_34;
if ( V_125 )
V_29 = F_70 ( V_3 ) ;
if ( V_29 ) {
if ( V_29 == - V_90 ) {
V_29 = F_90 ( V_50 , args , V_23 ,
V_104 ,
V_3 , V_19 , V_124 ) ;
F_157 ( ! F_158 ( & V_50 -> V_139 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_188 -> V_37 . V_87 ) {
F_12 ( L_30 ) ;
V_29 = - V_36 ;
goto V_34;
}
V_185 -> V_210 = args -> V_152 ;
if ( F_159 ( V_104 ) && args -> V_153 ) {
struct V_24 * V_242 ;
V_242 = F_130 ( V_104 ,
& V_189 ,
V_3 ,
V_188 ,
args -> V_152 ,
args -> V_153 ,
F_151 ( V_23 ) ) ;
if ( F_18 ( V_242 ) ) {
V_29 = F_19 ( V_242 ) ;
goto V_34;
}
if ( V_242 != V_188 ) {
V_212 |= V_236 ;
V_185 -> V_210 = 0 ;
V_188 = V_242 ;
}
}
V_188 -> V_37 . V_86 |= V_136 ;
if ( V_212 & V_236 ) {
V_29 = F_134 ( V_188 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
V_185 -> V_209 = F_49 ( V_188 ) ;
} else
V_185 -> V_209 = F_160 ( V_188 , V_21 ) ;
V_145 = F_161 ( V_104 , V_124 ) ;
if ( F_18 ( V_145 ) ) {
V_29 = F_19 ( V_145 ) ;
goto V_243;
}
V_29 = F_162 ( V_145 , V_23 ) ;
if ( V_29 )
goto V_244;
V_185 -> V_50 = V_50 ;
V_185 -> V_23 = V_23 ;
V_185 -> V_104 = V_104 ;
V_185 -> V_212 = V_212 ;
V_185 -> V_188 = V_188 ;
V_185 -> V_124 = V_124 ;
V_185 -> V_187 = V_145 ;
V_29 = V_68 -> V_245 . V_246 ( V_185 , args , & V_3 -> V_16 ) ;
V_244:
F_120 ( V_185 ) ;
V_243:
if ( V_212 & V_236 )
F_163 ( V_188 ) ;
V_34:
F_156 ( V_124 ) ;
F_28 ( V_3 ) ;
F_91 ( & V_50 -> V_139 ) ;
V_241:
F_164 ( V_68 ) ;
return V_29 ;
}
int
F_165 ( struct V_61 * V_50 , void * V_231 ,
struct V_22 * V_23 )
{
struct V_247 * args = V_231 ;
struct V_2 V_248 ;
struct V_249 * V_39 = NULL ;
struct V_18 * V_250 = NULL ;
int V_29 , V_28 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_27 , args -> V_7 ) ;
return - V_36 ;
}
V_39 = F_92 ( sizeof( * V_39 ) , args -> V_7 ) ;
V_250 = F_92 ( sizeof( * V_250 ) , args -> V_7 ) ;
if ( V_39 == NULL || V_250 == NULL ) {
F_12 ( L_31 ,
args -> V_7 ) ;
F_93 ( V_39 ) ;
F_93 ( V_250 ) ;
return - V_140 ;
}
V_29 = F_95 ( V_39 ,
F_65 ( args -> V_251 ) ,
sizeof( * V_39 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_32 ,
args -> V_7 , V_29 ) ;
F_93 ( V_39 ) ;
F_93 ( V_250 ) ;
return - V_90 ;
}
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_250 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_250 [ V_28 ] . V_98 = V_39 [ V_28 ] . V_98 ;
V_250 [ V_28 ] . V_97 = V_39 [ V_28 ] . V_97 ;
V_250 [ V_28 ] . V_117 = V_39 [ V_28 ] . V_117 ;
V_250 [ V_28 ] . V_63 = V_39 [ V_28 ] . V_63 ;
if ( F_42 ( V_50 ) -> V_66 < 4 )
V_250 [ V_28 ] . V_4 = V_101 ;
else
V_250 [ V_28 ] . V_4 = 0 ;
}
V_248 . V_251 = args -> V_251 ;
V_248 . V_7 = args -> V_7 ;
V_248 . V_152 = args -> V_152 ;
V_248 . V_153 = args -> V_153 ;
V_248 . V_151 = args -> V_151 ;
V_248 . V_150 = args -> V_150 ;
V_248 . V_148 = args -> V_148 ;
V_248 . V_149 = args -> V_149 ;
V_248 . V_4 = V_252 ;
F_166 ( V_248 , 0 ) ;
V_29 = F_149 ( V_50 , V_231 , V_23 , & V_248 , V_250 ) ;
if ( ! V_29 ) {
struct V_249 T_5 * V_253 =
F_65 ( args -> V_251 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_250 [ V_28 ] . V_63 =
F_32 ( V_250 [ V_28 ] . V_63 ) ;
V_29 = F_96 ( & V_253 [ V_28 ] . V_63 ,
& V_250 [ V_28 ] . V_63 ,
sizeof( V_253 [ V_28 ] . V_63 ) ) ;
if ( V_29 ) {
V_29 = - V_90 ;
F_12 ( L_33
L_34 ,
args -> V_7 , V_29 ) ;
break;
}
}
}
F_93 ( V_39 ) ;
F_93 ( V_250 ) ;
return V_29 ;
}
int
F_167 ( struct V_61 * V_50 , void * V_231 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_231 ;
struct V_18 * V_250 = NULL ;
int V_29 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_156 / sizeof( * V_250 ) ) {
F_12 ( L_35 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_254 != 0 ) {
F_12 ( L_36 ) ;
return - V_36 ;
}
V_250 = F_168 ( args -> V_7 ,
sizeof( * V_250 ) ,
V_9 ) ;
if ( V_250 == NULL ) {
F_12 ( L_31 ,
args -> V_7 ) ;
return - V_140 ;
}
V_29 = F_95 ( V_250 ,
F_65 ( args -> V_251 ) ,
sizeof( * V_250 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_32 ,
args -> V_7 , V_29 ) ;
F_93 ( V_250 ) ;
return - V_90 ;
}
V_29 = F_149 ( V_50 , V_231 , V_23 , args , V_250 ) ;
if ( ! V_29 ) {
struct V_18 T_5 * V_253 =
F_65 ( args -> V_251 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_250 [ V_28 ] . V_63 =
F_32 ( V_250 [ V_28 ] . V_63 ) ;
V_29 = F_96 ( & V_253 [ V_28 ] . V_63 ,
& V_250 [ V_28 ] . V_63 ,
sizeof( V_253 [ V_28 ] . V_63 ) ) ;
if ( V_29 ) {
V_29 = - V_90 ;
F_12 ( L_33
L_37 ,
args -> V_7 ) ;
break;
}
}
}
F_93 ( V_250 ) ;
return V_29 ;
}
