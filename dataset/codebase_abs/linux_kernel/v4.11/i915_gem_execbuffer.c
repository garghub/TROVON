static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * args )
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
V_5 -> V_3 = V_3 ;
F_5 ( & V_5 -> V_18 ) ;
return V_5 ;
}
static void
F_6 ( struct V_1 * V_5 )
{
if ( V_5 -> V_17 >= 0 )
memset ( V_5 -> V_19 , 0 , ( V_5 -> V_17 + 1 ) * sizeof( struct V_16 ) ) ;
}
static struct V_10 *
F_7 ( struct V_1 * V_5 )
{
struct V_10 * V_20 = F_8 ( V_5 -> V_18 . V_21 , F_9 ( * V_20 ) , V_22 ) ;
if ( ( V_20 -> V_23 -> V_6 & V_24 ) == 0 )
V_20 -> V_23 -> V_6 |= V_25 ;
return V_20 ;
}
static int
F_10 ( struct V_1 * V_5 ,
struct V_26 * V_27 ,
const struct V_4 * args ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_34 V_35 ;
int V_36 , V_37 ;
F_5 ( & V_35 ) ;
F_11 ( & V_31 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_33 = F_12 ( F_13 ( & V_31 -> V_39 , V_27 [ V_36 ] . V_40 ) ) ;
if ( V_33 == NULL ) {
F_14 ( & V_31 -> V_38 ) ;
F_15 ( L_1 ,
V_27 [ V_36 ] . V_40 , V_36 ) ;
V_37 = - V_41 ;
goto V_42;
}
if ( ! F_16 ( & V_33 -> V_43 ) ) {
F_14 ( & V_31 -> V_38 ) ;
F_15 ( L_2 ,
V_33 , V_27 [ V_36 ] . V_40 , V_36 ) ;
V_37 = - V_44 ;
goto V_42;
}
F_17 ( V_33 ) ;
F_18 ( & V_33 -> V_43 , & V_35 ) ;
}
F_14 ( & V_31 -> V_38 ) ;
V_36 = 0 ;
while ( ! F_16 ( & V_35 ) ) {
struct V_10 * V_20 ;
V_33 = F_19 ( & V_35 ,
struct V_32 ,
V_43 ) ;
V_20 = F_20 ( V_33 , V_29 , NULL ) ;
if ( F_21 ( F_22 ( V_20 ) ) ) {
F_15 ( L_3 ) ;
V_37 = F_23 ( V_20 ) ;
goto V_42;
}
F_18 ( & V_20 -> V_22 , & V_5 -> V_18 ) ;
F_24 ( & V_33 -> V_43 ) ;
V_20 -> V_23 = & V_27 [ V_36 ] ;
if ( V_5 -> V_17 < 0 ) {
V_5 -> V_45 [ V_36 ] = V_20 ;
} else {
T_1 V_40 = args -> V_6 & V_7 ? V_36 : V_27 [ V_36 ] . V_40 ;
V_20 -> V_46 = V_40 ;
F_25 ( & V_20 -> V_47 ,
& V_5 -> V_19 [ V_40 & V_5 -> V_17 ] ) ;
}
++ V_36 ;
}
return 0 ;
V_42:
while ( ! F_16 ( & V_35 ) ) {
V_33 = F_19 ( & V_35 ,
struct V_32 ,
V_43 ) ;
F_24 ( & V_33 -> V_43 ) ;
F_26 ( V_33 ) ;
}
return V_37 ;
}
static struct V_10 * F_27 ( struct V_1 * V_5 , unsigned long V_40 )
{
if ( V_5 -> V_17 < 0 ) {
if ( V_40 >= - V_5 -> V_17 )
return NULL ;
return V_5 -> V_45 [ V_40 ] ;
} else {
struct V_16 * V_48 ;
struct V_10 * V_20 ;
V_48 = & V_5 -> V_19 [ V_40 & V_5 -> V_17 ] ;
F_28 (vma, head, exec_node) {
if ( V_20 -> V_46 == V_40 )
return V_20 ;
}
return NULL ;
}
}
static void
F_29 ( struct V_10 * V_20 )
{
struct V_26 * V_49 ;
if ( ! F_30 ( & V_20 -> V_50 ) )
return;
V_49 = V_20 -> V_23 ;
if ( V_49 -> V_6 & V_51 )
F_31 ( V_20 ) ;
if ( V_49 -> V_6 & V_52 )
F_32 ( V_20 ) ;
V_49 -> V_6 &= ~ ( V_51 | V_52 ) ;
}
static void F_33 ( struct V_1 * V_5 )
{
while ( ! F_16 ( & V_5 -> V_18 ) ) {
struct V_10 * V_20 ;
V_20 = F_19 ( & V_5 -> V_18 ,
struct V_10 ,
V_22 ) ;
F_24 ( & V_20 -> V_22 ) ;
F_29 ( V_20 ) ;
V_20 -> V_23 = NULL ;
F_34 ( V_20 ) ;
}
F_35 ( V_5 ) ;
}
static inline int F_36 ( struct V_32 * V_33 )
{
if ( ! F_37 ( V_33 ) )
return false ;
if ( V_53 )
return V_53 > 0 ;
return ( F_38 ( F_39 ( V_33 -> V_54 . V_55 ) ) ||
V_33 -> V_54 . V_56 == V_57 ||
V_33 -> V_58 != V_59 ) ;
}
static inline T_2 F_40 ( T_2 V_60 )
{
return F_41 ( V_60 , V_61 ) ;
}
static inline T_2 F_42 ( T_2 V_60 )
{
return V_60 & ( ( 1ULL << ( V_61 + 1 ) ) - 1 ) ;
}
static inline T_2
F_43 ( const struct V_62 * V_63 ,
T_2 V_64 )
{
return F_40 ( ( int ) V_63 -> V_65 + V_64 ) ;
}
static void F_44 ( struct V_66 * V_67 ,
struct V_2 * V_3 )
{
V_67 -> V_68 = - 1 ;
V_67 -> V_69 = 0 ;
V_67 -> V_3 = V_3 ;
V_67 -> V_70 = F_45 ( V_3 ) ;
V_67 -> V_50 . V_71 = false ;
}
static inline void * F_46 ( unsigned long V_72 )
{
return ( void * ) ( V_73 ) ( V_72 & V_74 ) ;
}
static inline unsigned int F_47 ( unsigned long V_72 )
{
return V_72 & ~ V_74 ;
}
static void F_48 ( struct V_66 * V_67 )
{
void * V_69 ;
if ( ! V_67 -> V_69 )
return;
V_69 = F_46 ( V_67 -> V_69 ) ;
if ( V_67 -> V_69 & V_75 ) {
if ( V_67 -> V_69 & V_76 )
F_49 () ;
F_50 ( V_69 ) ;
F_51 ( (struct V_32 * ) V_67 -> V_50 . V_77 ) ;
} else {
F_52 () ;
F_53 ( ( void V_78 * ) V_69 ) ;
if ( V_67 -> V_50 . V_71 ) {
struct V_79 * V_80 = & V_67 -> V_3 -> V_80 ;
V_80 -> V_54 . V_81 ( & V_80 -> V_54 ,
V_67 -> V_50 . V_82 ,
V_67 -> V_50 . V_8 ) ;
F_54 ( & V_67 -> V_50 ) ;
} else {
F_55 ( (struct V_10 * ) V_67 -> V_50 . V_77 ) ;
}
}
}
static void * F_56 ( struct V_32 * V_33 ,
struct V_66 * V_67 ,
int V_68 )
{
void * V_69 ;
if ( V_67 -> V_69 ) {
F_50 ( F_46 ( V_67 -> V_69 ) ) ;
} else {
unsigned int V_83 ;
int V_37 ;
V_37 = F_57 ( V_33 , & V_83 ) ;
if ( V_37 )
return F_58 ( V_37 ) ;
F_59 ( V_75 & V_84 ) ;
F_59 ( ( V_75 | V_84 ) & V_74 ) ;
V_67 -> V_69 = V_83 | V_75 ;
V_67 -> V_50 . V_77 = ( void * ) V_33 ;
if ( V_83 )
F_49 () ;
}
V_69 = F_60 ( F_61 ( V_33 , V_68 ) ) ;
V_67 -> V_69 = F_47 ( V_67 -> V_69 ) | ( unsigned long ) V_69 ;
V_67 -> V_68 = V_68 ;
return V_69 ;
}
static void * F_62 ( struct V_32 * V_33 ,
struct V_66 * V_67 ,
int V_68 )
{
struct V_79 * V_80 = & V_67 -> V_3 -> V_80 ;
unsigned long V_85 ;
void * V_69 ;
if ( V_67 -> V_69 ) {
F_53 ( ( void V_86 V_78 * ) F_46 ( V_67 -> V_69 ) ) ;
} else {
struct V_10 * V_20 ;
int V_37 ;
if ( F_36 ( V_33 ) )
return NULL ;
V_37 = F_63 ( V_33 , true ) ;
if ( V_37 )
return F_58 ( V_37 ) ;
V_20 = F_64 ( V_33 , NULL , 0 , 0 ,
V_87 | V_88 ) ;
if ( F_22 ( V_20 ) ) {
memset ( & V_67 -> V_50 , 0 , sizeof( V_67 -> V_50 ) ) ;
V_37 = F_65
( & V_80 -> V_54 . V_77 , & V_67 -> V_50 ,
V_15 , 0 , V_89 ,
0 , V_80 -> V_90 ,
V_91 ) ;
if ( V_37 )
return NULL ;
} else {
V_37 = F_66 ( V_20 ) ;
if ( V_37 ) {
F_55 ( V_20 ) ;
return F_58 ( V_37 ) ;
}
V_67 -> V_50 . V_82 = V_20 -> V_50 . V_82 ;
V_67 -> V_50 . V_77 = ( void * ) V_20 ;
}
}
V_85 = V_67 -> V_50 . V_82 ;
if ( V_67 -> V_50 . V_71 ) {
F_52 () ;
V_80 -> V_54 . V_92 ( & V_80 -> V_54 ,
F_67 ( V_33 , V_68 ) ,
V_85 , V_59 , 0 ) ;
} else {
V_85 += V_68 << V_93 ;
}
V_69 = ( void V_86 * ) F_68 ( & V_67 -> V_3 -> V_80 . V_94 , V_85 ) ;
V_67 -> V_68 = V_68 ;
V_67 -> V_69 = ( unsigned long ) V_69 ;
return V_69 ;
}
static void * F_69 ( struct V_32 * V_33 ,
struct V_66 * V_67 ,
int V_68 )
{
void * V_69 ;
if ( V_67 -> V_68 == V_68 ) {
V_69 = F_46 ( V_67 -> V_69 ) ;
} else {
V_69 = NULL ;
if ( ( V_67 -> V_69 & V_75 ) == 0 )
V_69 = F_62 ( V_33 , V_67 , V_68 ) ;
if ( ! V_69 )
V_69 = F_56 ( V_33 , V_67 , V_68 ) ;
}
return V_69 ;
}
static void F_70 ( T_3 * V_95 , T_3 V_96 , unsigned int V_83 )
{
if ( F_21 ( V_83 & ( V_97 | V_76 ) ) ) {
if ( V_83 & V_97 ) {
F_71 ( V_95 ) ;
F_49 () ;
}
* V_95 = V_96 ;
if ( V_83 & V_76 )
F_71 ( V_95 ) ;
} else
* V_95 = V_96 ;
}
static int
F_72 ( struct V_32 * V_33 ,
const struct V_62 * V_63 ,
struct V_66 * V_67 ,
T_4 V_64 )
{
T_4 V_85 = V_63 -> V_85 ;
bool V_98 = V_67 -> V_70 ;
void * V_69 ;
V_64 = F_43 ( V_63 , V_64 ) ;
V_99:
V_69 = F_69 ( V_33 , V_67 , V_85 >> V_93 ) ;
if ( F_22 ( V_69 ) )
return F_23 ( V_69 ) ;
F_70 ( V_69 + F_73 ( V_85 ) ,
F_74 ( V_64 ) ,
V_67 -> V_69 ) ;
if ( V_98 ) {
V_85 += sizeof( T_3 ) ;
V_64 >>= 32 ;
V_98 = false ;
goto V_99;
}
return 0 ;
}
static int
F_75 ( struct V_32 * V_33 ,
struct V_1 * V_5 ,
struct V_62 * V_63 ,
struct V_66 * V_67 )
{
struct V_2 * V_100 = F_39 ( V_33 -> V_54 . V_55 ) ;
struct V_101 * V_102 ;
struct V_32 * V_103 ;
struct V_10 * V_104 ;
T_2 V_64 ;
int V_37 ;
V_104 = F_27 ( V_5 , V_63 -> V_105 ) ;
if ( F_21 ( V_104 == NULL ) )
return - V_41 ;
V_103 = V_104 -> V_33 ;
V_102 = & V_104 -> V_33 -> V_54 ;
V_64 = F_40 ( V_104 -> V_50 . V_82 ) ;
if ( F_21 ( F_76 ( V_100 ) &&
V_63 -> V_56 == V_106 ) ) {
V_37 = F_77 ( V_104 , V_103 -> V_58 ,
V_107 ) ;
if ( F_78 ( V_37 , L_4 ) )
return V_37 ;
}
if ( F_21 ( V_63 -> V_56 & ( V_63 -> V_56 - 1 ) ) ) {
F_15 ( L_5
L_6
L_7 ,
V_33 , V_63 -> V_105 ,
( int ) V_63 -> V_85 ,
V_63 -> V_108 ,
V_63 -> V_56 ) ;
return - V_44 ;
}
if ( F_21 ( ( V_63 -> V_56 | V_63 -> V_108 )
& ~ V_109 ) ) {
F_15 ( L_8
L_6
L_7 ,
V_33 , V_63 -> V_105 ,
( int ) V_63 -> V_85 ,
V_63 -> V_108 ,
V_63 -> V_56 ) ;
return - V_44 ;
}
V_102 -> V_110 |= V_63 -> V_108 ;
V_102 -> V_111 |= V_63 -> V_56 ;
if ( V_64 == V_63 -> V_112 )
return 0 ;
if ( F_21 ( V_63 -> V_85 >
V_33 -> V_54 . V_8 - ( V_67 -> V_70 ? 8 : 4 ) ) ) {
F_15 ( L_9
L_10 ,
V_33 , V_63 -> V_105 ,
( int ) V_63 -> V_85 ,
( int ) V_33 -> V_54 . V_8 ) ;
return - V_44 ;
}
if ( F_21 ( V_63 -> V_85 & 3 ) ) {
F_15 ( L_11
L_12 ,
V_33 , V_63 -> V_105 ,
( int ) V_63 -> V_85 ) ;
return - V_44 ;
}
V_37 = F_72 ( V_33 , V_63 , V_67 , V_64 ) ;
if ( V_37 )
return V_37 ;
V_63 -> V_112 = V_64 ;
return 0 ;
}
static int
F_79 ( struct V_10 * V_20 ,
struct V_1 * V_5 )
{
#define F_80 ( T_5 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_62 V_113 [ F_80 ( 512 ) ] ;
struct V_62 T_6 * V_114 ;
struct V_26 * V_49 = V_20 -> V_23 ;
struct V_66 V_67 ;
int V_115 , V_37 = 0 ;
V_114 = F_81 ( V_49 -> V_116 ) ;
F_44 ( & V_67 , V_5 -> V_3 ) ;
V_115 = V_49 -> V_117 ;
while ( V_115 ) {
struct V_62 * V_118 = V_113 ;
unsigned long V_119 ;
unsigned int V_14 ;
V_14 = F_82 (unsigned int, remain, ARRAY_SIZE(stack_reloc)) ;
V_115 -= V_14 ;
F_83 () ;
V_119 = F_84 ( V_118 , V_114 , V_14 * sizeof( V_118 [ 0 ] ) ) ;
F_85 () ;
if ( F_21 ( V_119 ) ) {
V_37 = - V_120 ;
goto V_121;
}
do {
T_4 V_85 = V_118 -> V_112 ;
V_37 = F_75 ( V_20 -> V_33 , V_5 , V_118 , & V_67 ) ;
if ( V_37 )
goto V_121;
if ( V_118 -> V_112 != V_85 ) {
F_83 () ;
V_119 = F_86 ( V_118 -> V_112 ,
& V_114 -> V_112 ) ;
F_85 () ;
if ( F_21 ( V_119 ) ) {
V_37 = - V_120 ;
goto V_121;
}
}
V_114 ++ ;
V_118 ++ ;
} while ( -- V_14 );
}
V_121:
F_48 ( & V_67 ) ;
return V_37 ;
#undef F_80
}
static int
F_87 ( struct V_10 * V_20 ,
struct V_1 * V_5 ,
struct V_62 * V_122 )
{
const struct V_26 * V_49 = V_20 -> V_23 ;
struct V_66 V_67 ;
int V_36 , V_37 = 0 ;
F_44 ( & V_67 , V_5 -> V_3 ) ;
for ( V_36 = 0 ; V_36 < V_49 -> V_117 ; V_36 ++ ) {
V_37 = F_75 ( V_20 -> V_33 , V_5 , & V_122 [ V_36 ] , & V_67 ) ;
if ( V_37 )
break;
}
F_48 ( & V_67 ) ;
return V_37 ;
}
static int
F_88 ( struct V_1 * V_5 )
{
struct V_10 * V_20 ;
int V_37 = 0 ;
F_89 (vma, &eb->vmas, exec_list) {
V_37 = F_79 ( V_20 , V_5 ) ;
if ( V_37 )
break;
}
return V_37 ;
}
static bool F_90 ( unsigned int V_6 )
{
return ( V_6 & ( V_123 | V_124 ) ) ==
V_124 ;
}
static int
F_91 ( struct V_10 * V_20 ,
struct V_125 * V_126 ,
bool * V_127 )
{
struct V_32 * V_33 = V_20 -> V_33 ;
struct V_26 * V_49 = V_20 -> V_23 ;
T_2 V_6 ;
int V_37 ;
V_6 = V_128 ;
if ( V_49 -> V_6 & V_129 )
V_6 |= V_107 ;
if ( ! F_30 ( & V_20 -> V_50 ) ) {
if ( ( V_49 -> V_6 & V_130 ) == 0 )
V_6 |= V_131 ;
if ( V_49 -> V_6 & V_124 )
V_6 |= V_107 | V_87 ;
if ( V_49 -> V_6 & V_25 )
V_6 |= V_132 | V_133 ;
if ( V_49 -> V_6 & V_24 )
V_6 |= V_49 -> V_85 | V_134 ;
if ( ( V_6 & V_87 ) == 0 )
V_6 |= V_135 ;
}
V_37 = F_92 ( V_20 ,
V_49 -> V_136 ,
V_49 -> V_137 ,
V_6 ) ;
if ( ( V_37 == - V_138 || V_37 == - V_139 ) &&
F_90 ( V_49 -> V_6 ) )
V_37 = F_92 ( V_20 ,
V_49 -> V_136 ,
V_49 -> V_137 ,
V_6 & ~ V_87 ) ;
if ( V_37 )
return V_37 ;
V_49 -> V_6 |= V_52 ;
if ( V_49 -> V_6 & V_123 ) {
V_37 = F_93 ( V_20 ) ;
if ( V_37 )
return V_37 ;
if ( F_94 ( V_20 ) )
V_49 -> V_6 |= V_51 ;
}
if ( V_49 -> V_85 != V_20 -> V_50 . V_82 ) {
V_49 -> V_85 = V_20 -> V_50 . V_82 ;
* V_127 = true ;
}
if ( V_49 -> V_6 & V_140 ) {
V_33 -> V_54 . V_110 = V_141 ;
V_33 -> V_54 . V_111 = V_141 ;
}
return 0 ;
}
static bool
F_95 ( struct V_10 * V_20 )
{
struct V_26 * V_49 = V_20 -> V_23 ;
if ( V_49 -> V_117 == 0 )
return false ;
if ( ! F_96 ( V_20 ) )
return false ;
if ( F_38 ( F_39 ( V_20 -> V_33 -> V_54 . V_55 ) ) )
return false ;
if ( V_20 -> V_33 -> V_54 . V_56 == V_57 )
return false ;
return true ;
}
static bool
F_97 ( struct V_10 * V_20 )
{
struct V_26 * V_49 = V_20 -> V_23 ;
F_98 ( V_49 -> V_6 & V_124 &&
! F_96 ( V_20 ) ) ;
if ( V_49 -> V_137 && ! F_99 ( V_20 -> V_50 . V_82 , V_49 -> V_137 ) )
return true ;
if ( V_20 -> V_50 . V_8 < V_49 -> V_136 )
return true ;
if ( V_49 -> V_6 & V_24 &&
V_20 -> V_50 . V_82 != V_49 -> V_85 )
return true ;
if ( V_49 -> V_6 & V_25 &&
V_20 -> V_50 . V_82 < V_132 )
return true ;
if ( V_49 -> V_6 & V_124 &&
! F_100 ( V_20 ) )
return ! F_90 ( V_49 -> V_6 ) ;
if ( ( V_49 -> V_6 & V_130 ) == 0 &&
( V_20 -> V_50 . V_82 + V_20 -> V_50 . V_8 - 1 ) >> 32 )
return true ;
return false ;
}
static int
F_101 ( struct V_125 * V_126 ,
struct V_34 * V_18 ,
struct V_142 * V_143 ,
bool * V_144 )
{
struct V_32 * V_33 ;
struct V_10 * V_20 ;
struct V_28 * V_29 ;
struct V_34 V_145 ;
struct V_34 V_146 ;
bool V_147 = F_102 ( V_126 -> V_3 ) < 4 ;
bool V_148 = F_103 ( V_126 -> V_3 ) -> V_149 ;
int V_150 ;
V_29 = F_19 ( V_18 , struct V_10 , V_22 ) -> V_29 ;
F_5 ( & V_145 ) ;
F_5 ( & V_146 ) ;
while ( ! F_16 ( V_18 ) ) {
struct V_26 * V_49 ;
bool V_151 , V_152 ;
V_20 = F_19 ( V_18 , struct V_10 , V_22 ) ;
V_33 = V_20 -> V_33 ;
V_49 = V_20 -> V_23 ;
if ( V_143 -> V_6 & V_153 )
V_49 -> V_6 |= V_25 ;
if ( ! V_147 )
V_49 -> V_6 &= ~ V_123 ;
V_151 =
( V_49 -> V_6 & V_123 ||
V_148 ) &&
F_104 ( V_33 ) ;
V_152 = V_151 || F_95 ( V_20 ) ;
if ( V_49 -> V_6 & V_24 )
F_105 ( & V_20 -> V_22 , & V_146 ) ;
else if ( V_152 ) {
V_49 -> V_6 |= V_124 ;
F_106 ( & V_20 -> V_22 , & V_145 ) ;
} else
F_105 ( & V_20 -> V_22 , & V_145 ) ;
V_33 -> V_54 . V_110 = V_109 & ~ V_154 ;
V_33 -> V_54 . V_111 = 0 ;
}
F_107 ( & V_145 , V_18 ) ;
F_107 ( & V_146 , V_18 ) ;
V_150 = 0 ;
do {
int V_37 = 0 ;
F_89 (vma, vmas, exec_list) {
if ( ! F_30 ( & V_20 -> V_50 ) )
continue;
if ( F_97 ( V_20 ) )
V_37 = F_108 ( V_20 ) ;
else
V_37 = F_91 ( V_20 ,
V_126 ,
V_144 ) ;
if ( V_37 )
goto V_42;
}
F_89 (vma, vmas, exec_list) {
if ( F_30 ( & V_20 -> V_50 ) )
continue;
V_37 = F_91 ( V_20 , V_126 ,
V_144 ) ;
if ( V_37 )
goto V_42;
}
V_42:
if ( V_37 != - V_138 || V_150 ++ )
return V_37 ;
F_89 (vma, vmas, exec_list)
F_29 ( V_20 ) ;
V_37 = F_109 ( V_29 , true ) ;
if ( V_37 )
return V_37 ;
} while ( 1 );
}
static int
F_110 ( struct V_155 * V_55 ,
struct V_4 * args ,
struct V_30 * V_31 ,
struct V_125 * V_126 ,
struct V_1 * V_5 ,
struct V_26 * V_27 ,
struct V_142 * V_143 )
{
struct V_62 * V_63 ;
struct V_28 * V_29 ;
struct V_10 * V_20 ;
bool V_144 ;
int * V_156 ;
int V_36 , V_157 , V_37 ;
unsigned V_14 = args -> V_9 ;
V_29 = F_19 ( & V_5 -> V_18 , struct V_10 , V_22 ) -> V_29 ;
while ( ! F_16 ( & V_5 -> V_18 ) ) {
V_20 = F_19 ( & V_5 -> V_18 , struct V_10 , V_22 ) ;
F_24 ( & V_20 -> V_22 ) ;
F_29 ( V_20 ) ;
F_34 ( V_20 ) ;
}
F_111 ( & V_55 -> V_158 ) ;
V_157 = 0 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ )
V_157 += V_27 [ V_36 ] . V_117 ;
V_156 = F_112 ( V_14 , sizeof( * V_156 ) ) ;
V_63 = F_112 ( V_157 , sizeof( * V_63 ) ) ;
if ( V_63 == NULL || V_156 == NULL ) {
F_113 ( V_63 ) ;
F_113 ( V_156 ) ;
F_114 ( & V_55 -> V_158 ) ;
return - V_159 ;
}
V_157 = 0 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
struct V_62 T_6 * V_114 ;
T_4 V_160 = ( T_4 ) - 1 ;
int V_161 ;
V_114 = F_81 ( V_27 [ V_36 ] . V_116 ) ;
if ( F_115 ( V_63 + V_157 , V_114 ,
V_27 [ V_36 ] . V_117 * sizeof( * V_63 ) ) ) {
V_37 = - V_120 ;
F_114 ( & V_55 -> V_158 ) ;
goto V_42;
}
for ( V_161 = 0 ; V_161 < V_27 [ V_36 ] . V_117 ; V_161 ++ ) {
if ( F_116 ( & V_114 [ V_161 ] . V_112 ,
& V_160 ,
sizeof( V_160 ) ) ) {
V_37 = - V_120 ;
F_114 ( & V_55 -> V_158 ) ;
goto V_42;
}
}
V_156 [ V_36 ] = V_157 ;
V_157 += V_27 [ V_36 ] . V_117 ;
}
V_37 = F_117 ( V_55 ) ;
if ( V_37 ) {
F_114 ( & V_55 -> V_158 ) ;
goto V_42;
}
F_6 ( V_5 ) ;
V_37 = F_10 ( V_5 , V_27 , args , V_29 , V_31 ) ;
if ( V_37 )
goto V_42;
V_144 = ( args -> V_6 & V_162 ) == 0 ;
V_37 = F_101 ( V_126 , & V_5 -> V_18 , V_143 ,
& V_144 ) ;
if ( V_37 )
goto V_42;
F_89 (vma, &eb->vmas, exec_list) {
int V_85 = V_20 -> V_23 - V_27 ;
V_37 = F_87 ( V_20 , V_5 ,
V_63 + V_156 [ V_85 ] ) ;
if ( V_37 )
goto V_42;
}
V_42:
F_113 ( V_63 ) ;
F_113 ( V_156 ) ;
return V_37 ;
}
static int
F_118 ( struct V_163 * V_164 ,
struct V_34 * V_18 )
{
struct V_10 * V_20 ;
int V_37 ;
F_89 (vma, vmas, exec_list) {
struct V_32 * V_33 = V_20 -> V_33 ;
V_37 = F_119
( V_164 , V_33 , V_33 -> V_54 . V_111 ) ;
if ( V_37 )
return V_37 ;
if ( V_33 -> V_54 . V_56 & V_57 )
F_120 ( V_33 , false ) ;
}
F_121 ( V_164 -> V_126 -> V_3 ) ;
return V_164 -> V_126 -> V_165 ( V_164 , V_166 ) ;
}
static bool
F_122 ( struct V_4 * V_27 )
{
if ( V_27 -> V_6 & V_167 )
return false ;
if ( V_27 -> V_168 || V_27 -> V_169 )
return false ;
if ( V_27 -> V_170 == 0xffffffff ) {
F_15 ( L_13 ) ;
V_27 -> V_170 = 0 ;
}
if ( V_27 -> V_171 || V_27 -> V_170 )
return false ;
if ( ( V_27 -> V_172 | V_27 -> V_173 ) & 0x7 )
return false ;
return true ;
}
static int
F_123 ( struct V_155 * V_55 ,
struct V_26 * V_27 ,
int V_14 )
{
unsigned V_174 = 0 ;
unsigned V_175 = V_176 / sizeof( struct V_62 ) ;
unsigned V_177 ;
int V_36 ;
F_59 ( V_178 & ~ V_179 ) ;
V_177 = V_179 ;
if ( F_124 ( V_55 ) )
V_177 |= V_129 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
char T_6 * V_180 = F_81 ( V_27 [ V_36 ] . V_116 ) ;
int V_181 ;
if ( V_27 [ V_36 ] . V_6 & V_177 )
return - V_44 ;
if ( V_27 [ V_36 ] . V_6 & V_24 ) {
if ( V_27 [ V_36 ] . V_85 !=
F_40 ( V_27 [ V_36 ] . V_85 & V_74 ) )
return - V_44 ;
}
V_27 [ V_36 ] . V_85 = F_42 ( V_27 [ V_36 ] . V_85 ) ;
if ( V_27 [ V_36 ] . V_137 && ! F_125 ( V_27 [ V_36 ] . V_137 ) )
return - V_44 ;
if ( V_27 [ V_36 ] . V_6 & V_182 ) {
if ( F_73 ( V_27 [ V_36 ] . V_136 ) )
return - V_44 ;
} else {
V_27 [ V_36 ] . V_136 = 0 ;
}
if ( V_27 [ V_36 ] . V_117 > V_175 - V_174 )
return - V_44 ;
V_174 += V_27 [ V_36 ] . V_117 ;
V_181 = V_27 [ V_36 ] . V_117 *
sizeof( struct V_62 ) ;
if ( ! F_126 ( V_183 , V_180 , V_181 ) )
return - V_120 ;
if ( F_127 ( ! V_3 . V_184 ) ) {
if ( F_128 ( V_180 , V_181 ) )
return - V_120 ;
}
}
return 0 ;
}
static struct V_142 *
F_129 ( struct V_155 * V_55 , struct V_30 * V_31 ,
struct V_125 * V_126 , const T_3 V_185 )
{
struct V_142 * V_143 ;
V_143 = F_130 ( V_31 -> V_186 , V_185 ) ;
if ( F_22 ( V_143 ) )
return V_143 ;
if ( F_131 ( V_143 ) ) {
F_15 ( L_14 , V_185 ) ;
return F_58 ( - V_187 ) ;
}
return V_143 ;
}
static bool F_132 ( struct V_32 * V_33 )
{
return ! ( V_33 -> V_58 == V_59 ||
V_33 -> V_58 == V_188 ) ;
}
void F_133 ( struct V_10 * V_20 ,
struct V_163 * V_164 ,
unsigned int V_6 )
{
struct V_32 * V_33 = V_20 -> V_33 ;
const unsigned int V_189 = V_164 -> V_126 -> V_190 ;
F_134 ( & V_164 -> V_3 -> V_191 . V_158 ) ;
F_135 ( ! F_30 ( & V_20 -> V_50 ) ) ;
if ( ! F_136 ( V_20 ) )
V_33 -> V_192 ++ ;
F_137 ( V_20 , V_189 ) ;
F_138 ( & V_20 -> V_193 [ V_189 ] , V_164 ) ;
F_105 ( & V_20 -> V_194 , & V_20 -> V_29 -> V_195 ) ;
if ( V_6 & V_140 ) {
if ( F_139 ( V_33 , V_196 ) )
F_138 ( & V_33 -> V_197 , V_164 ) ;
V_33 -> V_54 . V_56 &= ~ V_109 ;
if ( ! V_33 -> V_198 && F_132 ( V_33 ) )
V_33 -> V_198 = true ;
}
if ( V_6 & V_123 )
F_138 ( & V_20 -> V_199 , V_164 ) ;
}
static void F_140 ( struct V_32 * V_33 ,
struct V_163 * V_164 ,
unsigned int V_6 )
{
struct V_200 * V_201 = V_33 -> V_201 ;
F_141 ( & V_201 -> V_202 , NULL ) ;
if ( V_6 & V_140 )
F_142 ( V_201 , & V_164 -> V_203 ) ;
else if ( F_143 ( V_201 ) == 0 )
F_144 ( V_201 , & V_164 -> V_203 ) ;
F_145 ( & V_201 -> V_202 ) ;
}
static void
F_146 ( struct V_34 * V_18 ,
struct V_163 * V_164 )
{
struct V_10 * V_20 ;
F_89 (vma, vmas, exec_list) {
struct V_32 * V_33 = V_20 -> V_33 ;
T_3 V_204 = V_33 -> V_54 . V_108 ;
T_3 V_205 = V_33 -> V_54 . V_56 ;
V_33 -> V_54 . V_56 = V_33 -> V_54 . V_111 ;
if ( V_33 -> V_54 . V_56 )
V_20 -> V_23 -> V_6 |= V_140 ;
else
V_33 -> V_54 . V_110 |= V_33 -> V_54 . V_108 ;
V_33 -> V_54 . V_108 = V_33 -> V_54 . V_110 ;
F_133 ( V_20 , V_164 , V_20 -> V_23 -> V_6 ) ;
F_140 ( V_33 , V_164 , V_20 -> V_23 -> V_6 ) ;
F_147 ( V_33 , V_204 , V_205 ) ;
}
}
static int
F_148 ( struct V_163 * V_164 )
{
struct V_206 * V_207 = V_164 -> V_207 ;
int V_37 , V_36 ;
if ( ! F_149 ( V_164 -> V_3 ) || V_164 -> V_126 -> V_190 != V_208 ) {
F_15 ( L_15 ) ;
return - V_44 ;
}
V_37 = F_150 ( V_164 , 4 * 3 ) ;
if ( V_37 )
return V_37 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
F_151 ( V_207 , F_152 ( 1 ) ) ;
F_153 ( V_207 , F_154 ( V_36 ) ) ;
F_151 ( V_207 , 0 ) ;
}
F_155 ( V_207 ) ;
return 0 ;
}
static struct V_10 *
F_156 ( struct V_125 * V_126 ,
struct V_26 * V_209 ,
struct V_32 * V_210 ,
struct V_1 * V_5 ,
T_3 V_172 ,
T_3 V_173 ,
bool V_211 )
{
struct V_32 * V_212 ;
struct V_10 * V_20 ;
int V_37 ;
V_212 = F_157 ( & V_126 -> V_213 ,
F_158 ( V_173 ) ) ;
if ( F_22 ( V_212 ) )
return F_159 ( V_212 ) ;
V_37 = F_160 ( V_126 ,
V_210 ,
V_212 ,
V_172 ,
V_173 ,
V_211 ) ;
if ( V_37 ) {
if ( V_37 == - V_214 )
V_20 = NULL ;
else
V_20 = F_58 ( V_37 ) ;
goto V_121;
}
V_20 = F_64 ( V_212 , NULL , 0 , 0 , 0 ) ;
if ( F_22 ( V_20 ) )
goto V_121;
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
V_20 -> V_23 = V_209 ;
V_20 -> V_23 -> V_6 = V_52 ;
F_17 ( V_212 ) ;
F_18 ( & V_20 -> V_22 , & V_5 -> V_18 ) ;
V_121:
F_161 ( V_212 ) ;
return V_20 ;
}
static int
F_162 ( struct V_215 * V_216 ,
struct V_4 * args ,
struct V_34 * V_18 )
{
T_4 V_217 , V_218 ;
int V_37 ;
V_37 = F_118 ( V_216 -> V_219 , V_18 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_163 ( V_216 -> V_219 ) ;
if ( V_37 )
return V_37 ;
if ( args -> V_6 & V_220 ) {
F_15 ( L_16 ) ;
return - V_44 ;
}
if ( args -> V_6 & V_221 ) {
V_37 = F_148 ( V_216 -> V_219 ) ;
if ( V_37 )
return V_37 ;
}
V_218 = args -> V_173 ;
V_217 = V_216 -> V_222 -> V_50 . V_82 +
V_216 -> V_223 ;
if ( V_218 == 0 )
V_218 = V_216 -> V_222 -> V_8 - V_216 -> V_223 ;
V_37 = V_216 -> V_126 -> V_224 ( V_216 -> V_219 ,
V_217 , V_218 ,
V_216 -> V_225 ) ;
if ( V_37 )
return V_37 ;
F_164 ( V_216 -> V_219 , V_216 -> V_225 ) ;
F_146 ( V_18 , V_216 -> V_219 ) ;
return 0 ;
}
static unsigned int
F_165 ( struct V_2 * V_100 ,
struct V_30 * V_31 )
{
struct V_226 * V_227 = V_31 -> V_186 ;
if ( ( int ) V_227 -> V_228 < 0 )
V_227 -> V_228 = F_166 ( 1 ,
& V_100 -> V_77 . V_229 ) ;
return V_227 -> V_228 ;
}
static struct V_125 *
F_167 ( struct V_2 * V_100 ,
struct V_30 * V_31 ,
struct V_4 * args )
{
unsigned int V_230 = args -> V_6 & V_231 ;
struct V_125 * V_126 ;
if ( V_230 > V_232 ) {
F_15 ( L_17 , V_230 ) ;
return NULL ;
}
if ( ( V_230 != V_233 ) &&
( ( args -> V_6 & V_234 ) != 0 ) ) {
F_15 ( L_18
L_19 , ( int ) ( args -> V_6 ) ) ;
return NULL ;
}
if ( V_230 == V_233 && F_168 ( V_100 ) ) {
unsigned int V_235 = args -> V_6 & V_234 ;
if ( V_235 == V_236 ) {
V_235 = F_165 ( V_100 , V_31 ) ;
} else if ( V_235 >= V_237 &&
V_235 <= V_238 ) {
V_235 >>= V_239 ;
V_235 -- ;
} else {
F_15 ( L_20 ,
V_235 ) ;
return NULL ;
}
V_126 = V_100 -> V_126 [ F_169 ( V_235 ) ] ;
} else {
V_126 = V_100 -> V_126 [ V_240 [ V_230 ] ] ;
}
if ( ! V_126 ) {
F_15 ( L_21 , V_230 ) ;
return NULL ;
}
return V_126 ;
}
static int
F_170 ( struct V_155 * V_55 , void * V_241 ,
struct V_30 * V_31 ,
struct V_4 * args ,
struct V_26 * V_27 )
{
struct V_2 * V_100 = F_39 ( V_55 ) ;
struct V_79 * V_80 = & V_100 -> V_80 ;
struct V_1 * V_5 ;
struct V_26 V_209 ;
struct V_125 * V_126 ;
struct V_142 * V_143 ;
struct V_28 * V_29 ;
struct V_215 V_242 ;
struct V_215 * V_216 = & V_242 ;
const T_3 V_185 = F_171 ( * args ) ;
T_3 V_225 ;
int V_37 ;
bool V_144 ;
if ( ! F_122 ( args ) )
return - V_44 ;
V_37 = F_123 ( V_55 , V_27 , args -> V_9 ) ;
if ( V_37 )
return V_37 ;
V_225 = 0 ;
if ( args -> V_6 & V_243 ) {
if ( ! F_172 ( V_31 ) || ! F_173 ( V_244 ) )
return - V_245 ;
V_225 |= V_246 ;
}
if ( args -> V_6 & V_247 )
V_225 |= V_248 ;
V_126 = F_167 ( V_100 , V_31 , args ) ;
if ( ! V_126 )
return - V_44 ;
if ( args -> V_9 < 1 ) {
F_15 ( L_22 , args -> V_9 ) ;
return - V_44 ;
}
if ( args -> V_6 & V_249 ) {
if ( ! F_174 ( V_100 ) ) {
F_15 ( L_23 ) ;
return - V_44 ;
}
if ( V_126 -> V_190 != V_208 ) {
F_15 ( L_24 ,
V_126 -> V_250 ) ;
return - V_44 ;
}
V_225 |= V_251 ;
}
F_175 ( V_100 ) ;
V_37 = F_117 ( V_55 ) ;
if ( V_37 )
goto V_252;
V_143 = F_129 ( V_55 , V_31 , V_126 , V_185 ) ;
if ( F_22 ( V_143 ) ) {
F_111 ( & V_55 -> V_158 ) ;
V_37 = F_23 ( V_143 ) ;
goto V_252;
}
F_176 ( V_143 ) ;
if ( V_143 -> V_253 )
V_29 = & V_143 -> V_253 -> V_54 ;
else
V_29 = & V_80 -> V_54 ;
memset ( & V_242 , 0x00 , sizeof( V_242 ) ) ;
V_5 = F_1 ( V_100 , args ) ;
if ( V_5 == NULL ) {
F_177 ( V_143 ) ;
F_111 ( & V_55 -> V_158 ) ;
V_37 = - V_159 ;
goto V_252;
}
V_37 = F_10 ( V_5 , V_27 , args , V_29 , V_31 ) ;
if ( V_37 )
goto V_42;
V_216 -> V_222 = F_7 ( V_5 ) ;
V_144 = ( args -> V_6 & V_162 ) == 0 ;
V_37 = F_101 ( V_126 , & V_5 -> V_18 , V_143 ,
& V_144 ) ;
if ( V_37 )
goto V_42;
if ( V_144 )
V_37 = F_88 ( V_5 ) ;
if ( V_37 ) {
if ( V_37 == - V_120 ) {
V_37 = F_110 ( V_55 , args , V_31 ,
V_126 ,
V_5 , V_27 , V_143 ) ;
F_178 ( ! F_179 ( & V_55 -> V_158 ) ) ;
}
if ( V_37 )
goto V_42;
}
if ( V_216 -> V_222 -> V_33 -> V_54 . V_111 ) {
F_15 ( L_25 ) ;
V_37 = - V_44 ;
goto V_42;
}
if ( args -> V_172 > V_216 -> V_222 -> V_8 ||
args -> V_173 > V_216 -> V_222 -> V_8 - args -> V_172 ) {
F_15 ( L_26 ) ;
V_37 = - V_44 ;
goto V_42;
}
V_216 -> V_223 = args -> V_172 ;
if ( V_126 -> V_254 && args -> V_173 ) {
struct V_10 * V_20 ;
V_20 = F_156 ( V_126 , & V_209 ,
V_216 -> V_222 -> V_33 ,
V_5 ,
args -> V_172 ,
args -> V_173 ,
F_172 ( V_31 ) ) ;
if ( F_22 ( V_20 ) ) {
V_37 = F_23 ( V_20 ) ;
goto V_42;
}
if ( V_20 ) {
V_225 |= V_246 ;
V_216 -> V_223 = 0 ;
V_216 -> V_222 = V_20 ;
}
}
V_216 -> V_222 -> V_33 -> V_54 . V_110 |= V_154 ;
if ( V_225 & V_246 ) {
struct V_32 * V_33 = V_216 -> V_222 -> V_33 ;
struct V_10 * V_20 ;
V_20 = F_64 ( V_33 , NULL , 0 , 0 , 0 ) ;
if ( F_22 ( V_20 ) ) {
V_37 = F_23 ( V_20 ) ;
goto V_42;
}
V_216 -> V_222 = V_20 ;
}
V_216 -> V_219 = F_180 ( V_126 , V_143 ) ;
if ( F_22 ( V_216 -> V_219 ) ) {
V_37 = F_23 ( V_216 -> V_219 ) ;
goto V_255;
}
V_216 -> V_219 -> V_222 = V_216 -> V_222 ;
V_37 = F_181 ( V_216 -> V_219 , V_31 ) ;
if ( V_37 )
goto V_256;
V_216 -> V_55 = V_55 ;
V_216 -> V_31 = V_31 ;
V_216 -> V_126 = V_126 ;
V_216 -> V_225 = V_225 ;
V_216 -> V_143 = V_143 ;
V_37 = F_162 ( V_216 , args , & V_5 -> V_18 ) ;
V_256:
F_182 ( V_216 -> V_219 , V_37 == 0 ) ;
V_255:
if ( V_225 & V_246 )
F_55 ( V_216 -> V_222 ) ;
V_42:
F_177 ( V_143 ) ;
F_33 ( V_5 ) ;
F_111 ( & V_55 -> V_158 ) ;
V_252:
F_183 ( V_100 ) ;
return V_37 ;
}
int
F_184 ( struct V_155 * V_55 , void * V_241 ,
struct V_30 * V_31 )
{
struct V_257 * args = V_241 ;
struct V_4 V_258 ;
struct V_259 * V_22 = NULL ;
struct V_26 * V_260 = NULL ;
int V_37 , V_36 ;
if ( args -> V_9 < 1 ) {
F_15 ( L_22 , args -> V_9 ) ;
return - V_44 ;
}
V_22 = F_112 ( sizeof( * V_22 ) , args -> V_9 ) ;
V_260 = F_112 ( sizeof( * V_260 ) , args -> V_9 ) ;
if ( V_22 == NULL || V_260 == NULL ) {
F_15 ( L_27 ,
args -> V_9 ) ;
F_113 ( V_22 ) ;
F_113 ( V_260 ) ;
return - V_159 ;
}
V_37 = F_115 ( V_22 ,
F_81 ( args -> V_261 ) ,
sizeof( * V_22 ) * args -> V_9 ) ;
if ( V_37 != 0 ) {
F_15 ( L_28 ,
args -> V_9 , V_37 ) ;
F_113 ( V_22 ) ;
F_113 ( V_260 ) ;
return - V_120 ;
}
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_260 [ V_36 ] . V_40 = V_22 [ V_36 ] . V_40 ;
V_260 [ V_36 ] . V_117 = V_22 [ V_36 ] . V_117 ;
V_260 [ V_36 ] . V_116 = V_22 [ V_36 ] . V_116 ;
V_260 [ V_36 ] . V_137 = V_22 [ V_36 ] . V_137 ;
V_260 [ V_36 ] . V_85 = V_22 [ V_36 ] . V_85 ;
if ( F_102 ( F_39 ( V_55 ) ) < 4 )
V_260 [ V_36 ] . V_6 = V_123 ;
else
V_260 [ V_36 ] . V_6 = 0 ;
}
V_258 . V_261 = args -> V_261 ;
V_258 . V_9 = args -> V_9 ;
V_258 . V_172 = args -> V_172 ;
V_258 . V_173 = args -> V_173 ;
V_258 . V_171 = args -> V_171 ;
V_258 . V_170 = args -> V_170 ;
V_258 . V_168 = args -> V_168 ;
V_258 . V_169 = args -> V_169 ;
V_258 . V_6 = V_262 ;
F_185 ( V_258 , 0 ) ;
V_37 = F_170 ( V_55 , V_241 , V_31 , & V_258 , V_260 ) ;
if ( ! V_37 ) {
struct V_259 T_6 * V_263 =
F_81 ( args -> V_261 ) ;
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_260 [ V_36 ] . V_85 =
F_40 ( V_260 [ V_36 ] . V_85 ) ;
V_37 = F_116 ( & V_263 [ V_36 ] . V_85 ,
& V_260 [ V_36 ] . V_85 ,
sizeof( V_263 [ V_36 ] . V_85 ) ) ;
if ( V_37 ) {
V_37 = - V_120 ;
F_15 ( L_29
L_30 ,
args -> V_9 , V_37 ) ;
break;
}
}
}
F_113 ( V_22 ) ;
F_113 ( V_260 ) ;
return V_37 ;
}
int
F_186 ( struct V_155 * V_55 , void * V_241 ,
struct V_30 * V_31 )
{
struct V_4 * args = V_241 ;
struct V_26 * V_260 = NULL ;
int V_37 ;
if ( args -> V_9 < 1 ||
args -> V_9 > V_176 / sizeof( * V_260 ) ) {
F_15 ( L_31 , args -> V_9 ) ;
return - V_44 ;
}
if ( args -> V_264 != 0 ) {
F_15 ( L_32 ) ;
return - V_44 ;
}
V_260 = F_187 ( args -> V_9 ,
sizeof( * V_260 ) ,
V_11 ) ;
if ( V_260 == NULL ) {
F_15 ( L_27 ,
args -> V_9 ) ;
return - V_159 ;
}
V_37 = F_115 ( V_260 ,
F_81 ( args -> V_261 ) ,
sizeof( * V_260 ) * args -> V_9 ) ;
if ( V_37 != 0 ) {
F_15 ( L_28 ,
args -> V_9 , V_37 ) ;
F_113 ( V_260 ) ;
return - V_120 ;
}
V_37 = F_170 ( V_55 , V_241 , V_31 , args , V_260 ) ;
if ( ! V_37 ) {
struct V_26 T_6 * V_263 =
F_81 ( args -> V_261 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_260 [ V_36 ] . V_85 =
F_40 ( V_260 [ V_36 ] . V_85 ) ;
V_37 = F_116 ( & V_263 [ V_36 ] . V_85 ,
& V_260 [ V_36 ] . V_85 ,
sizeof( V_263 [ V_36 ] . V_85 ) ) ;
if ( V_37 ) {
V_37 = - V_120 ;
F_15 ( L_29
L_33 ,
args -> V_9 ) ;
break;
}
}
}
F_113 ( V_260 ) ;
return V_37 ;
}
