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
V_25 -> V_54 != V_55 ) ;
}
static inline T_2 F_33 ( T_2 V_56 )
{
return F_34 ( V_56 , V_57 ) ;
}
static inline T_2 F_35 ( T_2 V_56 )
{
return V_56 & ( ( 1ULL << ( V_57 + 1 ) ) - 1 ) ;
}
static inline T_2
F_36 ( struct V_58 * V_59 ,
T_2 V_60 )
{
return F_33 ( ( int ) V_59 -> V_61 + V_60 ) ;
}
static int
F_37 ( struct V_24 * V_25 ,
struct V_58 * V_59 ,
T_2 V_60 )
{
struct V_62 * V_51 = V_25 -> V_37 . V_51 ;
T_1 V_63 = F_38 ( V_59 -> V_64 ) ;
T_2 V_61 = F_36 ( V_59 , V_60 ) ;
char * V_65 ;
int V_29 ;
V_29 = F_39 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_65 = F_40 ( F_41 ( V_25 ,
V_59 -> V_64 >> V_66 ) ) ;
* ( T_1 * ) ( V_65 + V_63 ) = F_42 ( V_61 ) ;
if ( F_43 ( V_51 ) -> V_67 >= 8 ) {
V_63 = F_38 ( V_63 + sizeof( T_1 ) ) ;
if ( V_63 == 0 ) {
F_44 ( V_65 ) ;
V_65 = F_40 ( F_41 ( V_25 ,
( V_59 -> V_64 + sizeof( T_1 ) ) >> V_66 ) ) ;
}
* ( T_1 * ) ( V_65 + V_63 ) = F_45 ( V_61 ) ;
}
F_44 ( V_65 ) ;
return 0 ;
}
static int
F_46 ( struct V_24 * V_25 ,
struct V_58 * V_59 ,
T_2 V_60 )
{
struct V_62 * V_51 = V_25 -> V_37 . V_51 ;
struct V_68 * V_69 = V_51 -> V_70 ;
T_2 V_61 = F_36 ( V_59 , V_60 ) ;
T_2 V_64 ;
void T_3 * V_71 ;
int V_29 ;
V_29 = F_47 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_29 = F_48 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_64 = F_49 ( V_25 ) ;
V_64 += V_59 -> V_64 ;
V_71 = F_50 ( V_69 -> V_72 . V_73 ,
V_64 & V_74 ) ;
F_51 ( F_42 ( V_61 ) , V_71 + F_38 ( V_64 ) ) ;
if ( F_43 ( V_51 ) -> V_67 >= 8 ) {
V_64 += sizeof( T_1 ) ;
if ( F_38 ( V_64 ) == 0 ) {
F_52 ( V_71 ) ;
V_71 =
F_50 ( V_69 -> V_72 . V_73 ,
V_64 ) ;
}
F_51 ( F_45 ( V_61 ) ,
V_71 + F_38 ( V_64 ) ) ;
}
F_52 ( V_71 ) ;
return 0 ;
}
static void
F_53 ( void * V_75 , T_1 V_76 )
{
F_54 ( V_75 , sizeof( T_1 ) ) ;
* ( T_1 * ) V_75 = V_76 ;
F_54 ( V_75 , sizeof( T_1 ) ) ;
}
static int
F_55 ( struct V_24 * V_25 ,
struct V_58 * V_59 ,
T_2 V_60 )
{
struct V_62 * V_51 = V_25 -> V_37 . V_51 ;
T_1 V_63 = F_38 ( V_59 -> V_64 ) ;
T_2 V_61 = F_36 ( V_59 , V_60 ) ;
char * V_65 ;
int V_29 ;
V_29 = F_47 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_65 = F_40 ( F_41 ( V_25 ,
V_59 -> V_64 >> V_66 ) ) ;
F_53 ( V_65 + V_63 , F_42 ( V_61 ) ) ;
if ( F_43 ( V_51 ) -> V_67 >= 8 ) {
V_63 = F_38 ( V_63 + sizeof( T_1 ) ) ;
if ( V_63 == 0 ) {
F_44 ( V_65 ) ;
V_65 = F_40 ( F_41 ( V_25 ,
( V_59 -> V_64 + sizeof( T_1 ) ) >> V_66 ) ) ;
}
F_53 ( V_65 + V_63 , F_45 ( V_61 ) ) ;
}
F_44 ( V_65 ) ;
return 0 ;
}
static int
F_56 ( struct V_24 * V_25 ,
struct V_1 * V_3 ,
struct V_58 * V_59 )
{
struct V_62 * V_51 = V_25 -> V_37 . V_51 ;
struct V_77 * V_78 ;
struct V_24 * V_79 ;
struct V_8 * V_80 ;
T_2 V_60 ;
int V_29 ;
V_80 = F_23 ( V_3 , V_59 -> V_81 ) ;
if ( F_57 ( V_80 == NULL ) )
return - V_33 ;
V_79 = V_80 -> V_25 ;
V_78 = & V_80 -> V_25 -> V_37 ;
V_60 = F_33 ( V_80 -> V_46 . V_82 ) ;
if ( F_57 ( F_58 ( V_51 ) &&
V_59 -> V_52 == V_83 ) ) {
V_29 = F_59 ( V_80 , V_79 -> V_54 ,
V_84 ) ;
if ( F_60 ( V_29 , L_4 ) )
return V_29 ;
}
if ( F_57 ( V_59 -> V_52 & ( V_59 -> V_52 - 1 ) ) ) {
F_12 ( L_5
L_6
L_7 ,
V_25 , V_59 -> V_81 ,
( int ) V_59 -> V_64 ,
V_59 -> V_85 ,
V_59 -> V_52 ) ;
return - V_36 ;
}
if ( F_57 ( ( V_59 -> V_52 | V_59 -> V_85 )
& ~ V_86 ) ) {
F_12 ( L_8
L_6
L_7 ,
V_25 , V_59 -> V_81 ,
( int ) V_59 -> V_64 ,
V_59 -> V_85 ,
V_59 -> V_52 ) ;
return - V_36 ;
}
V_78 -> V_87 |= V_59 -> V_85 ;
V_78 -> V_88 |= V_59 -> V_52 ;
if ( V_60 == V_59 -> V_89 )
return 0 ;
if ( F_57 ( V_59 -> V_64 >
V_25 -> V_37 . V_6 - ( F_43 ( V_51 ) -> V_67 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_9
L_10 ,
V_25 , V_59 -> V_81 ,
( int ) V_59 -> V_64 ,
( int ) V_25 -> V_37 . V_6 ) ;
return - V_36 ;
}
if ( F_57 ( V_59 -> V_64 & 3 ) ) {
F_12 ( L_11
L_12 ,
V_25 , V_59 -> V_81 ,
( int ) V_59 -> V_64 ) ;
return - V_36 ;
}
if ( V_25 -> V_90 && F_61 () )
return - V_91 ;
if ( F_31 ( V_25 ) )
V_29 = F_37 ( V_25 , V_59 , V_60 ) ;
else if ( V_25 -> V_92 )
V_29 = F_46 ( V_25 , V_59 , V_60 ) ;
else if ( V_93 )
V_29 = F_55 ( V_25 , V_59 , V_60 ) ;
else {
F_60 ( 1 , L_13 ) ;
V_29 = - V_94 ;
}
if ( V_29 )
return V_29 ;
V_59 -> V_89 = V_60 ;
return 0 ;
}
static int
F_62 ( struct V_8 * V_38 ,
struct V_1 * V_3 )
{
#define F_63 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_58 V_95 [ F_63 ( 512 ) ] ;
struct V_58 T_5 * V_96 ;
struct V_18 * V_47 = V_38 -> V_40 ;
int V_97 , V_29 ;
V_96 = F_64 ( V_47 -> V_98 ) ;
V_97 = V_47 -> V_99 ;
while ( V_97 ) {
struct V_58 * V_100 = V_95 ;
int V_12 = V_97 ;
if ( V_12 > F_65 ( V_95 ) )
V_12 = F_65 ( V_95 ) ;
V_97 -= V_12 ;
if ( F_66 ( V_100 , V_96 , V_12 * sizeof( V_100 [ 0 ] ) ) )
return - V_91 ;
do {
T_6 V_64 = V_100 -> V_89 ;
V_29 = F_56 ( V_38 -> V_25 , V_3 , V_100 ) ;
if ( V_29 )
return V_29 ;
if ( V_100 -> V_89 != V_64 &&
F_67 ( & V_96 -> V_89 ,
& V_100 -> V_89 ,
sizeof( V_100 -> V_89 ) ) ) {
return - V_91 ;
}
V_96 ++ ;
V_100 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_63
}
static int
F_68 ( struct V_8 * V_38 ,
struct V_1 * V_3 ,
struct V_58 * V_101 )
{
const struct V_18 * V_47 = V_38 -> V_40 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_47 -> V_99 ; V_28 ++ ) {
V_29 = F_56 ( V_38 -> V_25 , V_3 , & V_101 [ V_28 ] ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_69 ( struct V_1 * V_3 )
{
struct V_8 * V_38 ;
int V_29 = 0 ;
F_70 () ;
F_71 (vma, &eb->vmas, exec_list) {
V_29 = F_62 ( V_38 , V_3 ) ;
if ( V_29 )
break;
}
F_72 () ;
return V_29 ;
}
static bool F_73 ( unsigned int V_4 )
{
return ( V_4 & ( V_102 | V_103 ) ) ==
V_103 ;
}
static int
F_74 ( struct V_8 * V_38 ,
struct V_104 * V_105 ,
bool * V_106 )
{
struct V_24 * V_25 = V_38 -> V_25 ;
struct V_18 * V_47 = V_38 -> V_40 ;
T_2 V_4 ;
int V_29 ;
V_4 = V_107 ;
if ( V_47 -> V_4 & V_108 )
V_4 |= V_84 ;
if ( ! F_27 ( & V_38 -> V_46 ) ) {
if ( ( V_47 -> V_4 & V_109 ) == 0 )
V_4 |= V_110 ;
if ( V_47 -> V_4 & V_103 )
V_4 |= V_84 | V_111 ;
if ( V_47 -> V_4 & V_112 )
V_4 |= V_113 | V_114 ;
if ( V_47 -> V_4 & V_115 )
V_4 |= V_47 -> V_64 | V_116 ;
if ( ( V_4 & V_111 ) == 0 )
V_4 |= V_117 ;
}
V_29 = F_75 ( V_25 , V_38 -> V_21 , V_47 -> V_118 , V_4 ) ;
if ( ( V_29 == - V_119 || V_29 == - V_120 ) &&
F_73 ( V_47 -> V_4 ) )
V_29 = F_75 ( V_25 , V_38 -> V_21 ,
V_47 -> V_118 ,
V_4 & ~ V_111 ) ;
if ( V_29 )
return V_29 ;
V_47 -> V_4 |= V_49 ;
if ( V_47 -> V_4 & V_102 ) {
V_29 = F_76 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_77 ( V_25 ) )
V_47 -> V_4 |= V_48 ;
}
if ( V_47 -> V_64 != V_38 -> V_46 . V_82 ) {
V_47 -> V_64 = V_38 -> V_46 . V_82 ;
* V_106 = true ;
}
if ( V_47 -> V_4 & V_121 ) {
V_25 -> V_37 . V_87 = V_122 ;
V_25 -> V_37 . V_88 = V_122 ;
}
return 0 ;
}
static bool
F_78 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
if ( V_47 -> V_99 == 0 )
return false ;
if ( ! F_79 ( V_38 -> V_21 ) )
return false ;
if ( F_32 ( V_38 -> V_25 -> V_37 . V_51 ) )
return false ;
if ( V_38 -> V_25 -> V_37 . V_52 == V_53 )
return false ;
return true ;
}
static bool
F_80 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
F_81 ( V_47 -> V_4 & V_103 &&
! F_79 ( V_38 -> V_21 ) ) ;
if ( V_47 -> V_118 &&
V_38 -> V_46 . V_82 & ( V_47 -> V_118 - 1 ) )
return true ;
if ( V_47 -> V_4 & V_115 &&
V_38 -> V_46 . V_82 != V_47 -> V_64 )
return true ;
if ( V_47 -> V_4 & V_112 &&
V_38 -> V_46 . V_82 < V_113 )
return true ;
if ( V_47 -> V_4 & V_103 && ! V_25 -> V_92 )
return ! F_73 ( V_47 -> V_4 ) ;
if ( ( V_47 -> V_4 & V_109 ) == 0 &&
( V_38 -> V_46 . V_82 + V_38 -> V_46 . V_6 - 1 ) >> 32 )
return true ;
return false ;
}
static int
F_82 ( struct V_104 * V_105 ,
struct V_26 * V_16 ,
struct V_123 * V_124 ,
bool * V_125 )
{
struct V_24 * V_25 ;
struct V_8 * V_38 ;
struct V_20 * V_21 ;
struct V_26 V_126 ;
struct V_26 V_127 ;
bool V_128 = F_43 ( V_105 -> V_51 ) -> V_67 < 4 ;
int V_129 ;
F_83 ( V_105 ) ;
V_21 = F_16 ( V_16 , struct V_8 , V_39 ) -> V_21 ;
F_5 ( & V_126 ) ;
F_5 ( & V_127 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_47 ;
bool V_130 , V_131 ;
V_38 = F_16 ( V_16 , struct V_8 , V_39 ) ;
V_25 = V_38 -> V_25 ;
V_47 = V_38 -> V_40 ;
if ( V_124 -> V_4 & V_132 )
V_47 -> V_4 |= V_112 ;
if ( ! V_128 )
V_47 -> V_4 &= ~ V_102 ;
V_130 =
V_47 -> V_4 & V_102 &&
V_25 -> V_133 != V_134 ;
V_131 = V_130 || F_78 ( V_38 ) ;
if ( V_47 -> V_4 & V_115 )
F_84 ( & V_38 -> V_39 , & V_127 ) ;
else if ( V_131 ) {
V_47 -> V_4 |= V_103 ;
F_85 ( & V_38 -> V_39 , & V_126 ) ;
} else
F_84 ( & V_38 -> V_39 , & V_126 ) ;
V_25 -> V_37 . V_87 = V_86 & ~ V_135 ;
V_25 -> V_37 . V_88 = 0 ;
}
F_86 ( & V_126 , V_16 ) ;
F_86 ( & V_127 , V_16 ) ;
V_129 = 0 ;
do {
int V_29 = 0 ;
F_71 (vma, vmas, exec_list) {
if ( ! F_27 ( & V_38 -> V_46 ) )
continue;
if ( F_80 ( V_38 ) )
V_29 = F_87 ( V_38 ) ;
else
V_29 = F_74 ( V_38 , V_105 , V_125 ) ;
if ( V_29 )
goto V_34;
}
F_71 (vma, vmas, exec_list) {
if ( F_27 ( & V_38 -> V_46 ) )
continue;
V_29 = F_74 ( V_38 , V_105 , V_125 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_119 || V_129 ++ )
return V_29 ;
F_71 (vma, vmas, exec_list)
F_26 ( V_38 ) ;
V_29 = F_88 ( V_21 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_89 ( struct V_62 * V_51 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_104 * V_105 ,
struct V_1 * V_3 ,
struct V_18 * V_19 ,
struct V_123 * V_124 )
{
struct V_58 * V_59 ;
struct V_20 * V_21 ;
struct V_8 * V_38 ;
bool V_125 ;
int * V_136 ;
int V_28 , V_137 , V_29 ;
unsigned V_12 = args -> V_7 ;
V_21 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) -> V_21 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_38 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_90 ( & V_51 -> V_138 ) ;
V_137 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
V_137 += V_19 [ V_28 ] . V_99 ;
V_136 = F_91 ( V_12 , sizeof( * V_136 ) ) ;
V_59 = F_91 ( V_137 , sizeof( * V_59 ) ) ;
if ( V_59 == NULL || V_136 == NULL ) {
F_92 ( V_59 ) ;
F_92 ( V_136 ) ;
F_93 ( & V_51 -> V_138 ) ;
return - V_139 ;
}
V_137 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
struct V_58 T_5 * V_96 ;
T_6 V_140 = ( T_6 ) - 1 ;
int V_141 ;
V_96 = F_64 ( V_19 [ V_28 ] . V_98 ) ;
if ( F_94 ( V_59 + V_137 , V_96 ,
V_19 [ V_28 ] . V_99 * sizeof( * V_59 ) ) ) {
V_29 = - V_91 ;
F_93 ( & V_51 -> V_138 ) ;
goto V_34;
}
for ( V_141 = 0 ; V_141 < V_19 [ V_28 ] . V_99 ; V_141 ++ ) {
if ( F_95 ( & V_96 [ V_141 ] . V_89 ,
& V_140 ,
sizeof( V_140 ) ) ) {
V_29 = - V_91 ;
F_93 ( & V_51 -> V_138 ) ;
goto V_34;
}
}
V_136 [ V_28 ] = V_137 ;
V_137 += V_19 [ V_28 ] . V_99 ;
}
V_29 = F_96 ( V_51 ) ;
if ( V_29 ) {
F_93 ( & V_51 -> V_138 ) ;
goto V_34;
}
F_6 ( V_3 ) ;
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_125 = ( args -> V_4 & V_142 ) == 0 ;
V_29 = F_82 ( V_105 , & V_3 -> V_16 , V_124 , & V_125 ) ;
if ( V_29 )
goto V_34;
F_71 (vma, &eb->vmas, exec_list) {
int V_64 = V_38 -> V_40 - V_19 ;
V_29 = F_68 ( V_38 , V_3 ,
V_59 + V_136 [ V_64 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_92 ( V_59 ) ;
F_92 ( V_136 ) ;
return V_29 ;
}
static int
F_97 ( struct V_143 * V_144 ,
struct V_26 * V_16 )
{
const unsigned V_145 = ~ F_98 ( V_144 -> V_105 ) ;
struct V_8 * V_38 ;
T_1 V_146 = 0 ;
bool V_147 = false ;
int V_29 ;
F_71 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
if ( V_25 -> V_90 & V_145 ) {
V_29 = F_99 ( V_25 , V_144 -> V_105 , & V_144 ) ;
if ( V_29 )
return V_29 ;
}
if ( V_25 -> V_37 . V_52 & V_53 )
V_147 |= F_100 ( V_25 , false ) ;
V_146 |= V_25 -> V_37 . V_52 ;
}
if ( V_147 )
F_101 ( V_144 -> V_105 -> V_51 ) ;
if ( V_146 & V_148 )
F_102 () ;
return F_103 ( V_144 ) ;
}
static bool
F_104 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_149 )
return false ;
if ( V_19 -> V_150 || V_19 -> V_151 )
return false ;
if ( V_19 -> V_152 == 0xffffffff ) {
F_12 ( L_14 ) ;
V_19 -> V_152 = 0 ;
}
if ( V_19 -> V_153 || V_19 -> V_152 )
return false ;
if ( ( V_19 -> V_154 | V_19 -> V_155 ) & 0x7 )
return false ;
return true ;
}
static int
F_105 ( struct V_62 * V_51 ,
struct V_18 * V_19 ,
int V_12 )
{
unsigned V_156 = 0 ;
unsigned V_157 = V_158 / sizeof( struct V_58 ) ;
unsigned V_159 ;
int V_28 ;
V_159 = V_160 ;
if ( F_106 ( V_51 ) )
V_159 |= V_108 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
char T_5 * V_161 = F_64 ( V_19 [ V_28 ] . V_98 ) ;
int V_162 ;
if ( V_19 [ V_28 ] . V_4 & V_159 )
return - V_36 ;
if ( V_19 [ V_28 ] . V_4 & V_115 ) {
if ( V_19 [ V_28 ] . V_64 !=
F_33 ( V_19 [ V_28 ] . V_64 & V_74 ) )
return - V_36 ;
V_19 [ V_28 ] . V_64 = F_35 ( V_19 [ V_28 ] . V_64 ) ;
}
if ( V_19 [ V_28 ] . V_118 && ! F_107 ( V_19 [ V_28 ] . V_118 ) )
return - V_36 ;
if ( V_19 [ V_28 ] . V_99 > V_157 - V_156 )
return - V_36 ;
V_156 += V_19 [ V_28 ] . V_99 ;
V_162 = V_19 [ V_28 ] . V_99 *
sizeof( struct V_58 ) ;
if ( ! F_108 ( V_163 , V_161 , V_162 ) )
return - V_91 ;
if ( F_109 ( ! V_164 . V_165 ) ) {
if ( F_110 ( V_161 , V_162 ) )
return - V_91 ;
}
}
return 0 ;
}
static struct V_123 *
F_111 ( struct V_62 * V_51 , struct V_22 * V_23 ,
struct V_104 * V_105 , const T_7 V_166 )
{
struct V_123 * V_124 = NULL ;
struct V_167 * V_168 ;
if ( V_105 -> V_169 != V_170 && V_166 != V_171 )
return F_112 ( - V_36 ) ;
V_124 = F_113 ( V_23 -> V_172 , V_166 ) ;
if ( F_18 ( V_124 ) )
return V_124 ;
V_168 = & V_124 -> V_173 ;
if ( V_168 -> V_174 ) {
F_12 ( L_15 , V_166 ) ;
return F_112 ( - V_175 ) ;
}
if ( V_164 . V_176 && ! V_124 -> V_177 [ V_105 -> V_169 ] . V_178 ) {
int V_29 = F_114 ( V_124 , V_105 ) ;
if ( V_29 ) {
F_12 ( L_16 , V_166 , V_29 ) ;
return F_112 ( V_29 ) ;
}
}
return V_124 ;
}
void
F_115 ( struct V_26 * V_16 ,
struct V_143 * V_144 )
{
struct V_104 * V_105 = F_116 ( V_144 ) ;
struct V_8 * V_38 ;
F_71 (vma, vmas, exec_list) {
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
T_7 V_179 = V_25 -> V_37 . V_85 ;
T_7 V_180 = V_25 -> V_37 . V_52 ;
V_25 -> V_181 = 1 ;
V_25 -> V_37 . V_52 = V_25 -> V_37 . V_88 ;
if ( V_25 -> V_37 . V_52 == 0 )
V_25 -> V_37 . V_87 |= V_25 -> V_37 . V_85 ;
V_25 -> V_37 . V_85 = V_25 -> V_37 . V_87 ;
F_117 ( V_38 , V_144 ) ;
if ( V_25 -> V_37 . V_52 ) {
F_118 ( & V_25 -> V_182 , V_144 ) ;
F_119 ( V_25 , V_183 ) ;
V_25 -> V_37 . V_52 &= ~ V_86 ;
}
if ( V_47 -> V_4 & V_102 ) {
F_118 ( & V_25 -> V_184 , V_144 ) ;
if ( V_47 -> V_4 & V_48 ) {
struct V_68 * V_69 = F_120 ( V_105 -> V_51 ) ;
F_84 ( & V_69 -> V_185 [ V_25 -> V_186 ] . V_187 ,
& V_69 -> V_188 . V_189 ) ;
}
}
F_121 ( V_25 , V_179 , V_180 ) ;
}
}
void
F_122 ( struct V_190 * V_191 )
{
V_191 -> V_105 -> V_192 = true ;
F_123 ( V_191 -> V_193 , V_191 -> V_194 , true ) ;
}
static int
F_124 ( struct V_62 * V_51 ,
struct V_143 * V_144 )
{
struct V_104 * V_105 = V_144 -> V_105 ;
struct V_68 * V_69 = V_51 -> V_70 ;
int V_29 , V_28 ;
if ( ! F_125 ( V_51 ) || V_105 != & V_69 -> V_105 [ V_170 ] ) {
F_12 ( L_17 ) ;
return - V_36 ;
}
V_29 = F_126 ( V_144 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_127 ( V_105 , F_128 ( 1 ) ) ;
F_129 ( V_105 , F_130 ( V_28 ) ) ;
F_127 ( V_105 , 0 ) ;
}
F_131 ( V_105 ) ;
return 0 ;
}
static struct V_24 *
F_132 ( struct V_104 * V_105 ,
struct V_18 * V_195 ,
struct V_1 * V_3 ,
struct V_24 * V_194 ,
T_7 V_154 ,
T_7 V_155 ,
bool V_196 )
{
struct V_24 * V_197 ;
struct V_8 * V_38 ;
int V_29 ;
V_197 = F_133 ( & V_105 -> V_198 ,
F_134 ( V_155 ) ) ;
if ( F_18 ( V_197 ) )
return V_197 ;
V_29 = F_135 ( V_105 ,
V_194 ,
V_197 ,
V_154 ,
V_155 ,
V_196 ) ;
if ( V_29 )
goto V_34;
V_29 = F_136 ( V_197 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
F_137 ( V_197 ) ;
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
V_38 = F_138 ( V_197 ) ;
V_38 -> V_40 = V_195 ;
V_38 -> V_40 -> V_4 = V_49 ;
F_14 ( & V_197 -> V_37 ) ;
F_15 ( & V_38 -> V_39 , & V_3 -> V_16 ) ;
V_197 -> V_37 . V_87 = V_135 ;
return V_197 ;
V_34:
F_137 ( V_197 ) ;
if ( V_29 == - V_199 )
return V_194 ;
else
return F_112 ( V_29 ) ;
}
int
F_139 ( struct V_190 * V_191 ,
struct V_2 * args ,
struct V_26 * V_16 )
{
struct V_62 * V_51 = V_191 -> V_51 ;
struct V_104 * V_105 = V_191 -> V_105 ;
struct V_68 * V_69 = V_51 -> V_70 ;
T_6 V_200 , V_201 ;
int V_202 ;
T_7 V_203 ;
int V_29 ;
V_29 = F_97 ( V_191 -> V_193 , V_16 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_140 ( V_191 -> V_193 ) ;
if ( V_29 )
return V_29 ;
F_141 ( V_191 -> V_124 -> V_204 && V_191 -> V_124 -> V_204 -> V_205 & ( 1 << V_105 -> V_169 ) ,
L_18 , V_105 -> V_206 ) ;
V_202 = args -> V_4 & V_207 ;
V_203 = V_207 ;
switch ( V_202 ) {
case V_208 :
case V_209 :
case V_210 :
if ( V_202 != 0 && V_105 != & V_69 -> V_105 [ V_170 ] ) {
F_12 ( L_19 ) ;
return - V_36 ;
}
if ( V_202 != V_69 -> V_211 ) {
if ( F_43 ( V_51 ) -> V_67 < 4 ) {
F_12 ( L_20 ) ;
return - V_36 ;
}
if ( F_43 ( V_51 ) -> V_67 > 5 &&
V_202 == V_210 ) {
F_12 ( L_21 ) ;
return - V_36 ;
}
if ( F_43 ( V_51 ) -> V_67 >= 6 )
V_203 &= ~ V_210 ;
}
break;
default:
F_12 ( L_22 , V_202 ) ;
return - V_36 ;
}
if ( V_105 == & V_69 -> V_105 [ V_170 ] &&
V_202 != V_69 -> V_211 ) {
V_29 = F_126 ( V_191 -> V_193 , 4 ) ;
if ( V_29 )
return V_29 ;
F_127 ( V_105 , V_212 ) ;
F_127 ( V_105 , F_128 ( 1 ) ) ;
F_129 ( V_105 , V_213 ) ;
F_127 ( V_105 , V_203 << 16 | V_202 ) ;
F_131 ( V_105 ) ;
V_69 -> V_211 = V_202 ;
}
if ( args -> V_4 & V_214 ) {
V_29 = F_124 ( V_51 , V_191 -> V_193 ) ;
if ( V_29 )
return V_29 ;
}
V_201 = args -> V_155 ;
V_200 = V_191 -> V_215 +
V_191 -> V_216 ;
V_29 = V_105 -> V_217 ( V_191 -> V_193 ,
V_200 , V_201 ,
V_191 -> V_218 ) ;
if ( V_29 )
return V_29 ;
F_142 ( V_191 -> V_193 , V_191 -> V_218 ) ;
F_115 ( V_16 , V_191 -> V_193 ) ;
F_122 ( V_191 ) ;
return 0 ;
}
static int F_143 ( struct V_62 * V_51 ,
struct V_22 * V_23 )
{
struct V_68 * V_69 = V_51 -> V_70 ;
struct V_219 * V_220 = V_23 -> V_172 ;
if ( V_220 -> V_221 )
return V_220 -> V_221 -> V_169 ;
else {
int V_222 ;
F_93 ( & V_51 -> V_138 ) ;
if ( V_69 -> V_188 . V_223 == 0 ) {
V_222 = V_224 ;
V_69 -> V_188 . V_223 = 1 ;
} else {
V_222 = V_225 ;
V_69 -> V_188 . V_223 = 0 ;
}
V_220 -> V_221 = & V_69 -> V_105 [ V_222 ] ;
F_90 ( & V_51 -> V_138 ) ;
return V_222 ;
}
}
static struct V_24 *
F_144 ( struct V_1 * V_3 )
{
struct V_8 * V_38 = F_145 ( V_3 -> V_16 . V_226 , F_146 ( * V_38 ) , V_39 ) ;
if ( ( V_38 -> V_40 -> V_4 & V_115 ) == 0 )
V_38 -> V_40 -> V_4 |= V_112 ;
return V_38 -> V_25 ;
}
static int
F_147 ( struct V_62 * V_51 , void * V_227 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_68 * V_69 = V_51 -> V_70 ;
struct V_1 * V_3 ;
struct V_24 * V_194 ;
struct V_18 V_195 ;
struct V_104 * V_105 ;
struct V_123 * V_124 ;
struct V_20 * V_21 ;
struct V_190 V_228 ;
struct V_190 * V_191 = & V_228 ;
const T_7 V_166 = F_148 ( * args ) ;
T_7 V_218 ;
int V_29 ;
bool V_125 ;
if ( ! F_104 ( args ) )
return - V_36 ;
V_29 = F_105 ( V_51 , V_19 , args -> V_7 ) ;
if ( V_29 )
return V_29 ;
V_218 = 0 ;
if ( args -> V_4 & V_229 ) {
if ( ! V_23 -> V_196 || ! F_149 ( V_230 ) )
return - V_231 ;
V_218 |= V_232 ;
}
if ( args -> V_4 & V_233 )
V_218 |= V_234 ;
if ( ( args -> V_4 & V_235 ) > V_236 ) {
F_12 ( L_23 ,
( int ) ( args -> V_4 & V_235 ) ) ;
return - V_36 ;
}
if ( ( ( args -> V_4 & V_235 ) != V_237 ) &&
( ( args -> V_4 & V_238 ) != 0 ) ) {
F_12 ( L_24
L_25 , ( int ) ( args -> V_4 ) ) ;
return - V_36 ;
}
if ( ( args -> V_4 & V_235 ) == V_239 )
V_105 = & V_69 -> V_105 [ V_170 ] ;
else if ( ( args -> V_4 & V_235 ) == V_237 ) {
if ( F_150 ( V_51 ) ) {
int V_222 ;
switch ( args -> V_4 & V_238 ) {
case V_240 :
V_222 = F_143 ( V_51 , V_23 ) ;
V_105 = & V_69 -> V_105 [ V_222 ] ;
break;
case V_241 :
V_105 = & V_69 -> V_105 [ V_224 ] ;
break;
case V_242 :
V_105 = & V_69 -> V_105 [ V_225 ] ;
break;
default:
F_12 ( L_26 ,
( int ) ( args -> V_4 & V_238 ) ) ;
return - V_36 ;
}
} else
V_105 = & V_69 -> V_105 [ V_224 ] ;
} else
V_105 = & V_69 -> V_105 [ ( args -> V_4 & V_235 ) - 1 ] ;
if ( ! F_151 ( V_105 ) ) {
F_12 ( L_27 ,
( int ) ( args -> V_4 & V_235 ) ) ;
return - V_36 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_28 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_4 & V_243 ) {
if ( ! F_152 ( V_51 ) ) {
F_12 ( L_29 ) ;
return - V_36 ;
}
if ( V_105 -> V_169 != V_170 ) {
F_12 ( L_30 ,
V_105 -> V_206 ) ;
return - V_36 ;
}
V_218 |= V_244 ;
}
F_153 ( V_69 ) ;
V_29 = F_96 ( V_51 ) ;
if ( V_29 )
goto V_245;
V_124 = F_111 ( V_51 , V_23 , V_105 , V_166 ) ;
if ( F_18 ( V_124 ) ) {
F_90 ( & V_51 -> V_138 ) ;
V_29 = F_19 ( V_124 ) ;
goto V_245;
}
F_154 ( V_124 ) ;
if ( V_124 -> V_204 )
V_21 = & V_124 -> V_204 -> V_37 ;
else
V_21 = & V_69 -> V_72 . V_37 ;
memset ( & V_228 , 0x00 , sizeof( V_228 ) ) ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_155 ( V_124 ) ;
F_90 ( & V_51 -> V_138 ) ;
V_29 = - V_139 ;
goto V_245;
}
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_194 = F_144 ( V_3 ) ;
V_125 = ( args -> V_4 & V_142 ) == 0 ;
V_29 = F_82 ( V_105 , & V_3 -> V_16 , V_124 , & V_125 ) ;
if ( V_29 )
goto V_34;
if ( V_125 )
V_29 = F_69 ( V_3 ) ;
if ( V_29 ) {
if ( V_29 == - V_91 ) {
V_29 = F_89 ( V_51 , args , V_23 , V_105 ,
V_3 , V_19 , V_124 ) ;
F_156 ( ! F_157 ( & V_51 -> V_138 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_194 -> V_37 . V_88 ) {
F_12 ( L_31 ) ;
V_29 = - V_36 ;
goto V_34;
}
V_191 -> V_216 = args -> V_154 ;
if ( F_158 ( V_105 ) && args -> V_155 ) {
struct V_24 * V_246 ;
V_246 = F_132 ( V_105 ,
& V_195 ,
V_3 ,
V_194 ,
args -> V_154 ,
args -> V_155 ,
V_23 -> V_196 ) ;
if ( F_18 ( V_246 ) ) {
V_29 = F_19 ( V_246 ) ;
goto V_34;
}
if ( V_246 != V_194 ) {
V_218 |= V_232 ;
V_191 -> V_216 = 0 ;
V_194 = V_246 ;
}
}
V_194 -> V_37 . V_87 |= V_135 ;
if ( V_218 & V_232 ) {
V_29 = F_136 ( V_194 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
V_191 -> V_215 = F_49 ( V_194 ) ;
} else
V_191 -> V_215 = F_159 ( V_194 , V_21 ) ;
V_29 = F_160 ( V_105 , V_124 , & V_191 -> V_193 ) ;
if ( V_29 )
goto V_247;
V_29 = F_161 ( V_191 -> V_193 , V_23 ) ;
if ( V_29 )
goto V_247;
V_191 -> V_51 = V_51 ;
V_191 -> V_23 = V_23 ;
V_191 -> V_105 = V_105 ;
V_191 -> V_218 = V_218 ;
V_191 -> V_194 = V_194 ;
V_191 -> V_124 = V_124 ;
V_29 = V_69 -> V_248 . V_249 ( V_191 , args , & V_3 -> V_16 ) ;
V_247:
if ( V_218 & V_232 )
F_162 ( V_194 ) ;
V_34:
F_155 ( V_124 ) ;
F_29 ( V_3 ) ;
if ( V_29 && V_191 -> V_193 )
F_163 ( V_191 -> V_193 ) ;
F_90 ( & V_51 -> V_138 ) ;
V_245:
F_164 ( V_69 ) ;
return V_29 ;
}
int
F_165 ( struct V_62 * V_51 , void * V_227 ,
struct V_22 * V_23 )
{
struct V_250 * args = V_227 ;
struct V_2 V_251 ;
struct V_252 * V_39 = NULL ;
struct V_18 * V_253 = NULL ;
int V_29 , V_28 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_28 , args -> V_7 ) ;
return - V_36 ;
}
V_39 = F_91 ( sizeof( * V_39 ) , args -> V_7 ) ;
V_253 = F_91 ( sizeof( * V_253 ) , args -> V_7 ) ;
if ( V_39 == NULL || V_253 == NULL ) {
F_12 ( L_32 ,
args -> V_7 ) ;
F_92 ( V_39 ) ;
F_92 ( V_253 ) ;
return - V_139 ;
}
V_29 = F_94 ( V_39 ,
F_64 ( args -> V_254 ) ,
sizeof( * V_39 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_33 ,
args -> V_7 , V_29 ) ;
F_92 ( V_39 ) ;
F_92 ( V_253 ) ;
return - V_91 ;
}
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_253 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_253 [ V_28 ] . V_99 = V_39 [ V_28 ] . V_99 ;
V_253 [ V_28 ] . V_98 = V_39 [ V_28 ] . V_98 ;
V_253 [ V_28 ] . V_118 = V_39 [ V_28 ] . V_118 ;
V_253 [ V_28 ] . V_64 = V_39 [ V_28 ] . V_64 ;
if ( F_43 ( V_51 ) -> V_67 < 4 )
V_253 [ V_28 ] . V_4 = V_102 ;
else
V_253 [ V_28 ] . V_4 = 0 ;
}
V_251 . V_254 = args -> V_254 ;
V_251 . V_7 = args -> V_7 ;
V_251 . V_154 = args -> V_154 ;
V_251 . V_155 = args -> V_155 ;
V_251 . V_153 = args -> V_153 ;
V_251 . V_152 = args -> V_152 ;
V_251 . V_150 = args -> V_150 ;
V_251 . V_151 = args -> V_151 ;
V_251 . V_4 = V_255 ;
F_166 ( V_251 , 0 ) ;
V_29 = F_147 ( V_51 , V_227 , V_23 , & V_251 , V_253 ) ;
if ( ! V_29 ) {
struct V_252 T_5 * V_256 =
F_64 ( args -> V_254 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_253 [ V_28 ] . V_64 =
F_33 ( V_253 [ V_28 ] . V_64 ) ;
V_29 = F_95 ( & V_256 [ V_28 ] . V_64 ,
& V_253 [ V_28 ] . V_64 ,
sizeof( V_256 [ V_28 ] . V_64 ) ) ;
if ( V_29 ) {
V_29 = - V_91 ;
F_12 ( L_34
L_35 ,
args -> V_7 , V_29 ) ;
break;
}
}
}
F_92 ( V_39 ) ;
F_92 ( V_253 ) ;
return V_29 ;
}
int
F_167 ( struct V_62 * V_51 , void * V_227 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_227 ;
struct V_18 * V_253 = NULL ;
int V_29 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_158 / sizeof( * V_253 ) ) {
F_12 ( L_36 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_257 != 0 ) {
F_12 ( L_37 ) ;
return - V_36 ;
}
V_253 = F_2 ( sizeof( * V_253 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_253 == NULL )
V_253 = F_91 ( sizeof( * V_253 ) ,
args -> V_7 ) ;
if ( V_253 == NULL ) {
F_12 ( L_32 ,
args -> V_7 ) ;
return - V_139 ;
}
V_29 = F_94 ( V_253 ,
F_64 ( args -> V_254 ) ,
sizeof( * V_253 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_33 ,
args -> V_7 , V_29 ) ;
F_92 ( V_253 ) ;
return - V_91 ;
}
V_29 = F_147 ( V_51 , V_227 , V_23 , args , V_253 ) ;
if ( ! V_29 ) {
struct V_18 T_5 * V_256 =
F_64 ( args -> V_254 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_253 [ V_28 ] . V_64 =
F_33 ( V_253 [ V_28 ] . V_64 ) ;
V_29 = F_95 ( & V_256 [ V_28 ] . V_64 ,
& V_253 [ V_28 ] . V_64 ,
sizeof( V_256 [ V_28 ] . V_64 ) ) ;
if ( V_29 ) {
V_29 = - V_91 ;
F_12 ( L_34
L_38 ,
args -> V_7 ) ;
break;
}
}
}
F_92 ( V_253 ) ;
return V_29 ;
}
