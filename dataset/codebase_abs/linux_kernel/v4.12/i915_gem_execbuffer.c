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
F_75 ( struct V_10 * V_20 ,
struct V_1 * V_5 ,
struct V_62 * V_63 ,
struct V_66 * V_67 )
{
struct V_32 * V_33 = V_20 -> V_33 ;
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
V_20 -> V_23 -> V_6 &= ~ V_113 ;
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
struct V_62 V_114 [ F_80 ( 512 ) ] ;
struct V_62 T_6 * V_115 ;
struct V_26 * V_49 = V_20 -> V_23 ;
struct V_66 V_67 ;
int V_116 , V_37 = 0 ;
V_115 = F_81 ( V_49 -> V_117 ) ;
F_44 ( & V_67 , V_5 -> V_3 ) ;
V_116 = V_49 -> V_118 ;
while ( V_116 ) {
struct V_62 * V_119 = V_114 ;
unsigned long V_120 ;
unsigned int V_14 ;
V_14 = F_82 (unsigned int, remain, ARRAY_SIZE(stack_reloc)) ;
V_116 -= V_14 ;
F_83 () ;
V_120 = F_84 ( V_119 , V_115 , V_14 * sizeof( V_119 [ 0 ] ) ) ;
F_85 () ;
if ( F_21 ( V_120 ) ) {
V_37 = - V_121 ;
goto V_122;
}
do {
T_4 V_85 = V_119 -> V_112 ;
V_37 = F_75 ( V_20 , V_5 , V_119 , & V_67 ) ;
if ( V_37 )
goto V_122;
if ( V_119 -> V_112 != V_85 ) {
F_83 () ;
V_120 = F_86 ( V_119 -> V_112 ,
& V_115 -> V_112 ) ;
F_85 () ;
if ( F_21 ( V_120 ) ) {
V_37 = - V_121 ;
goto V_122;
}
}
V_115 ++ ;
V_119 ++ ;
} while ( -- V_14 );
}
V_122:
F_48 ( & V_67 ) ;
return V_37 ;
#undef F_80
}
static int
F_87 ( struct V_10 * V_20 ,
struct V_1 * V_5 ,
struct V_62 * V_123 )
{
const struct V_26 * V_49 = V_20 -> V_23 ;
struct V_66 V_67 ;
int V_36 , V_37 = 0 ;
F_44 ( & V_67 , V_5 -> V_3 ) ;
for ( V_36 = 0 ; V_36 < V_49 -> V_118 ; V_36 ++ ) {
V_37 = F_75 ( V_20 , V_5 , & V_123 [ V_36 ] , & V_67 ) ;
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
return ( V_6 & ( V_124 | V_125 ) ) ==
V_125 ;
}
static int
F_91 ( struct V_10 * V_20 ,
struct V_126 * V_127 ,
bool * V_128 )
{
struct V_32 * V_33 = V_20 -> V_33 ;
struct V_26 * V_49 = V_20 -> V_23 ;
T_2 V_6 ;
int V_37 ;
V_6 = V_129 ;
if ( V_49 -> V_6 & V_130 )
V_6 |= V_107 ;
if ( ! F_30 ( & V_20 -> V_50 ) ) {
if ( ( V_49 -> V_6 & V_131 ) == 0 )
V_6 |= V_132 ;
if ( V_49 -> V_6 & V_125 )
V_6 |= V_107 | V_87 ;
if ( V_49 -> V_6 & V_25 )
V_6 |= V_133 | V_134 ;
if ( V_49 -> V_6 & V_24 )
V_6 |= V_49 -> V_85 | V_135 ;
if ( ( V_6 & V_87 ) == 0 )
V_6 |= V_136 ;
}
V_37 = F_92 ( V_20 ,
V_49 -> V_137 ,
V_49 -> V_138 ,
V_6 ) ;
if ( ( V_37 == - V_139 || V_37 == - V_140 ) &&
F_90 ( V_49 -> V_6 ) )
V_37 = F_92 ( V_20 ,
V_49 -> V_137 ,
V_49 -> V_138 ,
V_6 & ~ V_87 ) ;
if ( V_37 )
return V_37 ;
V_49 -> V_6 |= V_52 ;
if ( V_49 -> V_6 & V_124 ) {
V_37 = F_93 ( V_20 ) ;
if ( V_37 )
return V_37 ;
if ( F_94 ( V_20 ) )
V_49 -> V_6 |= V_51 ;
}
if ( V_49 -> V_85 != V_20 -> V_50 . V_82 ) {
V_49 -> V_85 = V_20 -> V_50 . V_82 ;
* V_128 = true ;
}
if ( V_49 -> V_6 & V_141 ) {
V_33 -> V_54 . V_110 = V_142 ;
V_33 -> V_54 . V_111 = V_142 ;
}
return 0 ;
}
static bool
F_95 ( struct V_10 * V_20 )
{
struct V_26 * V_49 = V_20 -> V_23 ;
if ( V_49 -> V_118 == 0 )
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
F_98 ( V_49 -> V_6 & V_125 &&
! F_96 ( V_20 ) ) ;
if ( V_49 -> V_138 && ! F_99 ( V_20 -> V_50 . V_82 , V_49 -> V_138 ) )
return true ;
if ( V_20 -> V_50 . V_8 < V_49 -> V_137 )
return true ;
if ( V_49 -> V_6 & V_24 &&
V_20 -> V_50 . V_82 != V_49 -> V_85 )
return true ;
if ( V_49 -> V_6 & V_25 &&
V_20 -> V_50 . V_82 < V_133 )
return true ;
if ( V_49 -> V_6 & V_125 &&
! F_100 ( V_20 ) )
return ! F_90 ( V_49 -> V_6 ) ;
if ( ( V_49 -> V_6 & V_131 ) == 0 &&
( V_20 -> V_50 . V_82 + V_20 -> V_50 . V_8 - 1 ) >> 32 )
return true ;
return false ;
}
static int
F_101 ( struct V_126 * V_127 ,
struct V_34 * V_18 ,
struct V_143 * V_144 ,
bool * V_145 )
{
struct V_32 * V_33 ;
struct V_10 * V_20 ;
struct V_28 * V_29 ;
struct V_34 V_146 ;
struct V_34 V_147 ;
bool V_148 = F_102 ( V_127 -> V_3 ) < 4 ;
bool V_149 = F_103 ( V_127 -> V_3 ) -> V_150 ;
int V_151 ;
V_29 = F_19 ( V_18 , struct V_10 , V_22 ) -> V_29 ;
F_5 ( & V_146 ) ;
F_5 ( & V_147 ) ;
while ( ! F_16 ( V_18 ) ) {
struct V_26 * V_49 ;
bool V_152 , V_153 ;
V_20 = F_19 ( V_18 , struct V_10 , V_22 ) ;
V_33 = V_20 -> V_33 ;
V_49 = V_20 -> V_23 ;
if ( V_144 -> V_6 & V_154 )
V_49 -> V_6 |= V_25 ;
if ( ! V_148 )
V_49 -> V_6 &= ~ V_124 ;
V_152 =
( V_49 -> V_6 & V_124 ||
V_149 ) &&
F_104 ( V_33 ) ;
V_153 = V_152 || F_95 ( V_20 ) ;
if ( V_49 -> V_6 & V_24 )
F_105 ( & V_20 -> V_22 , & V_147 ) ;
else if ( V_153 ) {
V_49 -> V_6 |= V_125 ;
F_106 ( & V_20 -> V_22 , & V_146 ) ;
} else
F_105 ( & V_20 -> V_22 , & V_146 ) ;
V_33 -> V_54 . V_110 = V_109 & ~ V_155 ;
V_33 -> V_54 . V_111 = 0 ;
}
F_107 ( & V_146 , V_18 ) ;
F_107 ( & V_147 , V_18 ) ;
V_151 = 0 ;
do {
int V_37 = 0 ;
F_89 (vma, vmas, exec_list) {
if ( ! F_30 ( & V_20 -> V_50 ) )
continue;
if ( F_97 ( V_20 ) )
V_37 = F_108 ( V_20 ) ;
else
V_37 = F_91 ( V_20 ,
V_127 ,
V_145 ) ;
if ( V_37 )
goto V_42;
}
F_89 (vma, vmas, exec_list) {
if ( F_30 ( & V_20 -> V_50 ) )
continue;
V_37 = F_91 ( V_20 , V_127 ,
V_145 ) ;
if ( V_37 )
goto V_42;
}
V_42:
if ( V_37 != - V_139 || V_151 ++ )
return V_37 ;
F_89 (vma, vmas, exec_list)
F_29 ( V_20 ) ;
V_37 = F_109 ( V_29 , true ) ;
if ( V_37 )
return V_37 ;
} while ( 1 );
}
static int
F_110 ( struct V_156 * V_55 ,
struct V_4 * args ,
struct V_30 * V_31 ,
struct V_126 * V_127 ,
struct V_1 * V_5 ,
struct V_26 * V_27 ,
struct V_143 * V_144 )
{
struct V_62 * V_63 ;
struct V_28 * V_29 ;
struct V_10 * V_20 ;
bool V_145 ;
int * V_157 ;
int V_36 , V_158 , V_37 ;
unsigned V_14 = args -> V_9 ;
V_29 = F_19 ( & V_5 -> V_18 , struct V_10 , V_22 ) -> V_29 ;
while ( ! F_16 ( & V_5 -> V_18 ) ) {
V_20 = F_19 ( & V_5 -> V_18 , struct V_10 , V_22 ) ;
F_24 ( & V_20 -> V_22 ) ;
F_29 ( V_20 ) ;
F_34 ( V_20 ) ;
}
F_111 ( & V_55 -> V_159 ) ;
V_158 = 0 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ )
V_158 += V_27 [ V_36 ] . V_118 ;
V_157 = F_112 ( V_14 , sizeof( * V_157 ) ) ;
V_63 = F_112 ( V_158 , sizeof( * V_63 ) ) ;
if ( V_63 == NULL || V_157 == NULL ) {
F_113 ( V_63 ) ;
F_113 ( V_157 ) ;
F_114 ( & V_55 -> V_159 ) ;
return - V_160 ;
}
V_158 = 0 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
struct V_62 T_6 * V_115 ;
T_4 V_161 = ( T_4 ) - 1 ;
int V_162 ;
V_115 = F_81 ( V_27 [ V_36 ] . V_117 ) ;
if ( F_115 ( V_63 + V_158 , V_115 ,
V_27 [ V_36 ] . V_118 * sizeof( * V_63 ) ) ) {
V_37 = - V_121 ;
F_114 ( & V_55 -> V_159 ) ;
goto V_42;
}
for ( V_162 = 0 ; V_162 < V_27 [ V_36 ] . V_118 ; V_162 ++ ) {
if ( F_116 ( & V_115 [ V_162 ] . V_112 ,
& V_161 ,
sizeof( V_161 ) ) ) {
V_37 = - V_121 ;
F_114 ( & V_55 -> V_159 ) ;
goto V_42;
}
}
V_157 [ V_36 ] = V_158 ;
V_158 += V_27 [ V_36 ] . V_118 ;
}
V_37 = F_117 ( V_55 ) ;
if ( V_37 ) {
F_114 ( & V_55 -> V_159 ) ;
goto V_42;
}
F_6 ( V_5 ) ;
V_37 = F_10 ( V_5 , V_27 , args , V_29 , V_31 ) ;
if ( V_37 )
goto V_42;
V_145 = ( args -> V_6 & V_163 ) == 0 ;
V_37 = F_101 ( V_127 , & V_5 -> V_18 , V_144 ,
& V_145 ) ;
if ( V_37 )
goto V_42;
F_89 (vma, &eb->vmas, exec_list) {
int V_85 = V_20 -> V_23 - V_27 ;
V_37 = F_87 ( V_20 , V_5 ,
V_63 + V_157 [ V_85 ] ) ;
if ( V_37 )
goto V_42;
}
V_42:
F_113 ( V_63 ) ;
F_113 ( V_157 ) ;
return V_37 ;
}
static int
F_118 ( struct V_164 * V_165 ,
struct V_34 * V_18 )
{
struct V_10 * V_20 ;
int V_37 ;
F_89 (vma, vmas, exec_list) {
struct V_32 * V_33 = V_20 -> V_33 ;
if ( V_20 -> V_23 -> V_6 & V_113 )
continue;
if ( V_33 -> V_54 . V_56 & V_57 ) {
F_119 ( V_33 , 0 ) ;
V_33 -> V_54 . V_56 = 0 ;
}
V_37 = F_120
( V_165 , V_33 , V_33 -> V_54 . V_111 ) ;
if ( V_37 )
return V_37 ;
}
F_121 ( V_165 -> V_127 -> V_3 ) ;
return V_165 -> V_127 -> V_166 ( V_165 , V_167 ) ;
}
static bool
F_122 ( struct V_4 * V_27 )
{
if ( V_27 -> V_6 & V_168 )
return false ;
if ( V_27 -> V_169 || V_27 -> V_170 )
return false ;
if ( V_27 -> V_171 == 0xffffffff ) {
F_15 ( L_13 ) ;
V_27 -> V_171 = 0 ;
}
if ( V_27 -> V_172 || V_27 -> V_171 )
return false ;
if ( ( V_27 -> V_173 | V_27 -> V_174 ) & 0x7 )
return false ;
return true ;
}
static int
F_123 ( struct V_156 * V_55 ,
struct V_26 * V_27 ,
int V_14 )
{
unsigned V_175 = 0 ;
unsigned V_176 = V_177 / sizeof( struct V_62 ) ;
unsigned V_178 ;
int V_36 ;
F_59 ( V_179 & ~ V_180 ) ;
V_178 = V_180 ;
if ( F_124 ( V_55 ) )
V_178 |= V_130 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
char T_6 * V_181 = F_81 ( V_27 [ V_36 ] . V_117 ) ;
int V_182 ;
if ( V_27 [ V_36 ] . V_6 & V_178 )
return - V_44 ;
if ( V_27 [ V_36 ] . V_6 & V_24 ) {
if ( V_27 [ V_36 ] . V_85 !=
F_40 ( V_27 [ V_36 ] . V_85 & V_74 ) )
return - V_44 ;
}
V_27 [ V_36 ] . V_85 = F_42 ( V_27 [ V_36 ] . V_85 ) ;
if ( V_27 [ V_36 ] . V_138 && ! F_125 ( V_27 [ V_36 ] . V_138 ) )
return - V_44 ;
if ( V_27 [ V_36 ] . V_6 & V_183 ) {
if ( F_73 ( V_27 [ V_36 ] . V_137 ) )
return - V_44 ;
} else {
V_27 [ V_36 ] . V_137 = 0 ;
}
if ( V_27 [ V_36 ] . V_118 > V_176 - V_175 )
return - V_44 ;
V_175 += V_27 [ V_36 ] . V_118 ;
V_182 = V_27 [ V_36 ] . V_118 *
sizeof( struct V_62 ) ;
if ( ! F_126 ( V_184 , V_181 , V_182 ) )
return - V_121 ;
if ( F_127 ( ! V_3 . V_185 ) ) {
if ( F_128 ( V_181 , V_182 ) )
return - V_121 ;
}
}
return 0 ;
}
static struct V_143 *
F_129 ( struct V_156 * V_55 , struct V_30 * V_31 ,
struct V_126 * V_127 , const T_3 V_186 )
{
struct V_143 * V_144 ;
V_144 = F_130 ( V_31 -> V_187 , V_186 ) ;
if ( F_22 ( V_144 ) )
return V_144 ;
if ( F_131 ( V_144 ) ) {
F_15 ( L_14 , V_186 ) ;
return F_58 ( - V_188 ) ;
}
return V_144 ;
}
static bool F_132 ( struct V_32 * V_33 )
{
return ! ( V_33 -> V_58 == V_59 ||
V_33 -> V_58 == V_189 ) ;
}
void F_133 ( struct V_10 * V_20 ,
struct V_164 * V_165 ,
unsigned int V_6 )
{
struct V_32 * V_33 = V_20 -> V_33 ;
const unsigned int V_190 = V_165 -> V_127 -> V_191 ;
F_134 ( & V_165 -> V_3 -> V_192 . V_159 ) ;
F_135 ( ! F_30 ( & V_20 -> V_50 ) ) ;
if ( ! F_136 ( V_20 ) )
V_33 -> V_193 ++ ;
F_137 ( V_20 , V_190 ) ;
F_138 ( & V_20 -> V_194 [ V_190 ] , V_165 ) ;
F_105 ( & V_20 -> V_195 , & V_20 -> V_29 -> V_196 ) ;
if ( V_6 & V_141 ) {
if ( F_139 ( V_33 , V_197 ) )
F_138 ( & V_33 -> V_198 , V_165 ) ;
V_33 -> V_54 . V_56 &= ~ V_109 ;
if ( ! V_33 -> V_199 && F_132 ( V_33 ) )
V_33 -> V_199 = true ;
}
if ( V_6 & V_124 )
F_138 ( & V_20 -> V_200 , V_165 ) ;
}
static void F_140 ( struct V_32 * V_33 ,
struct V_164 * V_165 ,
unsigned int V_6 )
{
struct V_201 * V_202 = V_33 -> V_202 ;
F_141 ( V_202 , NULL ) ;
if ( V_6 & V_141 )
F_142 ( V_202 , & V_165 -> V_203 ) ;
else if ( F_143 ( V_202 ) == 0 )
F_144 ( V_202 , & V_165 -> V_203 ) ;
F_145 ( V_202 ) ;
}
static void
F_146 ( struct V_34 * V_18 ,
struct V_164 * V_165 )
{
struct V_10 * V_20 ;
F_89 (vma, vmas, exec_list) {
struct V_32 * V_33 = V_20 -> V_33 ;
V_33 -> V_54 . V_56 = V_33 -> V_54 . V_111 ;
if ( V_33 -> V_54 . V_56 )
V_20 -> V_23 -> V_6 |= V_141 ;
else
V_33 -> V_54 . V_110 |= V_33 -> V_54 . V_108 ;
V_33 -> V_54 . V_108 = V_33 -> V_54 . V_110 ;
F_133 ( V_20 , V_165 , V_20 -> V_23 -> V_6 ) ;
F_140 ( V_33 , V_165 , V_20 -> V_23 -> V_6 ) ;
}
}
static int
F_147 ( struct V_164 * V_165 )
{
T_3 * V_204 ;
int V_36 ;
if ( ! F_148 ( V_165 -> V_3 ) || V_165 -> V_127 -> V_191 != V_205 ) {
F_15 ( L_15 ) ;
return - V_44 ;
}
V_204 = F_149 ( V_165 , 4 * 3 ) ;
if ( F_22 ( V_204 ) )
return F_23 ( V_204 ) ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
* V_204 ++ = F_150 ( 1 ) ;
* V_204 ++ = F_151 ( F_152 ( V_36 ) ) ;
* V_204 ++ = 0 ;
}
F_153 ( V_165 , V_204 ) ;
return 0 ;
}
static struct V_10 *
F_154 ( struct V_126 * V_127 ,
struct V_26 * V_206 ,
struct V_32 * V_207 ,
struct V_1 * V_5 ,
T_3 V_173 ,
T_3 V_174 ,
bool V_208 )
{
struct V_32 * V_209 ;
struct V_10 * V_20 ;
int V_37 ;
V_209 = F_155 ( & V_127 -> V_210 ,
F_156 ( V_174 ) ) ;
if ( F_22 ( V_209 ) )
return F_157 ( V_209 ) ;
V_37 = F_158 ( V_127 ,
V_207 ,
V_209 ,
V_173 ,
V_174 ,
V_208 ) ;
if ( V_37 ) {
if ( V_37 == - V_211 )
V_20 = NULL ;
else
V_20 = F_58 ( V_37 ) ;
goto V_122;
}
V_20 = F_64 ( V_209 , NULL , 0 , 0 , 0 ) ;
if ( F_22 ( V_20 ) )
goto V_122;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_20 -> V_23 = V_206 ;
V_20 -> V_23 -> V_6 = V_52 ;
F_17 ( V_209 ) ;
F_18 ( & V_20 -> V_22 , & V_5 -> V_18 ) ;
V_122:
F_159 ( V_209 ) ;
return V_20 ;
}
static void
F_160 ( struct V_164 * V_165 ,
struct V_30 * V_31 )
{
V_165 -> V_212 = V_31 -> V_187 ;
F_18 ( & V_165 -> V_213 , & V_165 -> V_212 -> V_77 . V_214 ) ;
}
static int
F_161 ( struct V_215 * V_216 ,
struct V_4 * args ,
struct V_34 * V_18 )
{
T_4 V_217 , V_218 ;
int V_37 ;
V_37 = F_118 ( V_216 -> V_219 , V_18 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_162 ( V_216 -> V_219 ) ;
if ( V_37 )
return V_37 ;
if ( args -> V_6 & V_220 ) {
F_15 ( L_16 ) ;
return - V_44 ;
}
if ( args -> V_6 & V_221 ) {
V_37 = F_147 ( V_216 -> V_219 ) ;
if ( V_37 )
return V_37 ;
}
V_218 = args -> V_174 ;
V_217 = V_216 -> V_222 -> V_50 . V_82 +
V_216 -> V_223 ;
if ( V_218 == 0 )
V_218 = V_216 -> V_222 -> V_8 - V_216 -> V_223 ;
V_37 = V_216 -> V_127 -> V_224 ( V_216 -> V_219 ,
V_217 , V_218 ,
V_216 -> V_225 ) ;
if ( V_37 )
return V_37 ;
F_146 ( V_18 , V_216 -> V_219 ) ;
return 0 ;
}
static unsigned int
F_163 ( struct V_2 * V_100 ,
struct V_30 * V_31 )
{
struct V_226 * V_212 = V_31 -> V_187 ;
if ( ( int ) V_212 -> V_227 < 0 )
V_212 -> V_227 = F_164 ( 1 ,
& V_100 -> V_77 . V_228 ) ;
return V_212 -> V_227 ;
}
static struct V_126 *
F_165 ( struct V_2 * V_100 ,
struct V_30 * V_31 ,
struct V_4 * args )
{
unsigned int V_229 = args -> V_6 & V_230 ;
struct V_126 * V_127 ;
if ( V_229 > V_231 ) {
F_15 ( L_17 , V_229 ) ;
return NULL ;
}
if ( ( V_229 != V_232 ) &&
( ( args -> V_6 & V_233 ) != 0 ) ) {
F_15 ( L_18
L_19 , ( int ) ( args -> V_6 ) ) ;
return NULL ;
}
if ( V_229 == V_232 && F_166 ( V_100 ) ) {
unsigned int V_234 = args -> V_6 & V_233 ;
if ( V_234 == V_235 ) {
V_234 = F_163 ( V_100 , V_31 ) ;
} else if ( V_234 >= V_236 &&
V_234 <= V_237 ) {
V_234 >>= V_238 ;
V_234 -- ;
} else {
F_15 ( L_20 ,
V_234 ) ;
return NULL ;
}
V_127 = V_100 -> V_127 [ F_167 ( V_234 ) ] ;
} else {
V_127 = V_100 -> V_127 [ V_239 [ V_229 ] ] ;
}
if ( ! V_127 ) {
F_15 ( L_21 , V_229 ) ;
return NULL ;
}
return V_127 ;
}
static int
F_168 ( struct V_156 * V_55 , void * V_240 ,
struct V_30 * V_31 ,
struct V_4 * args ,
struct V_26 * V_27 )
{
struct V_2 * V_100 = F_39 ( V_55 ) ;
struct V_79 * V_80 = & V_100 -> V_80 ;
struct V_1 * V_5 ;
struct V_26 V_206 ;
struct V_126 * V_127 ;
struct V_143 * V_144 ;
struct V_28 * V_29 ;
struct V_215 V_241 ;
struct V_215 * V_216 = & V_241 ;
const T_3 V_186 = F_169 ( * args ) ;
T_3 V_225 ;
struct V_242 * V_243 = NULL ;
struct V_244 * V_245 = NULL ;
int V_246 = - 1 ;
int V_37 ;
bool V_145 ;
if ( ! F_122 ( args ) )
return - V_44 ;
V_37 = F_123 ( V_55 , V_27 , args -> V_9 ) ;
if ( V_37 )
return V_37 ;
V_225 = 0 ;
if ( args -> V_6 & V_247 ) {
if ( ! F_170 ( V_31 ) || ! F_171 ( V_248 ) )
return - V_249 ;
V_225 |= V_250 ;
}
if ( args -> V_6 & V_251 )
V_225 |= V_252 ;
V_127 = F_165 ( V_100 , V_31 , args ) ;
if ( ! V_127 )
return - V_44 ;
if ( args -> V_9 < 1 ) {
F_15 ( L_22 , args -> V_9 ) ;
return - V_44 ;
}
if ( args -> V_6 & V_253 ) {
if ( ! F_172 ( V_100 ) ) {
F_15 ( L_23 ) ;
return - V_44 ;
}
if ( V_127 -> V_191 != V_205 ) {
F_15 ( L_24 ,
V_127 -> V_254 ) ;
return - V_44 ;
}
V_225 |= V_255 ;
}
if ( args -> V_6 & V_256 ) {
V_243 = F_173 ( F_74 ( args -> V_257 ) ) ;
if ( ! V_243 )
return - V_44 ;
}
if ( args -> V_6 & V_258 ) {
V_246 = F_174 ( V_259 ) ;
if ( V_246 < 0 ) {
V_37 = V_246 ;
goto V_260;
}
}
F_175 ( V_100 ) ;
V_37 = F_117 ( V_55 ) ;
if ( V_37 )
goto V_261;
V_144 = F_129 ( V_55 , V_31 , V_127 , V_186 ) ;
if ( F_22 ( V_144 ) ) {
F_111 ( & V_55 -> V_159 ) ;
V_37 = F_23 ( V_144 ) ;
goto V_261;
}
F_176 ( V_144 ) ;
if ( V_144 -> V_262 )
V_29 = & V_144 -> V_262 -> V_54 ;
else
V_29 = & V_80 -> V_54 ;
memset ( & V_241 , 0x00 , sizeof( V_241 ) ) ;
V_5 = F_1 ( V_100 , args ) ;
if ( V_5 == NULL ) {
F_177 ( V_144 ) ;
F_111 ( & V_55 -> V_159 ) ;
V_37 = - V_160 ;
goto V_261;
}
V_37 = F_10 ( V_5 , V_27 , args , V_29 , V_31 ) ;
if ( V_37 )
goto V_42;
V_216 -> V_222 = F_7 ( V_5 ) ;
V_145 = ( args -> V_6 & V_163 ) == 0 ;
V_37 = F_101 ( V_127 , & V_5 -> V_18 , V_144 ,
& V_145 ) ;
if ( V_37 )
goto V_42;
if ( V_145 )
V_37 = F_88 ( V_5 ) ;
if ( V_37 ) {
if ( V_37 == - V_121 ) {
V_37 = F_110 ( V_55 , args , V_31 ,
V_127 ,
V_5 , V_27 , V_144 ) ;
F_178 ( ! F_179 ( & V_55 -> V_159 ) ) ;
}
if ( V_37 )
goto V_42;
}
if ( V_216 -> V_222 -> V_33 -> V_54 . V_111 ) {
F_15 ( L_25 ) ;
V_37 = - V_44 ;
goto V_42;
}
if ( args -> V_173 > V_216 -> V_222 -> V_8 ||
args -> V_174 > V_216 -> V_222 -> V_8 - args -> V_173 ) {
F_15 ( L_26 ) ;
V_37 = - V_44 ;
goto V_42;
}
V_216 -> V_223 = args -> V_173 ;
if ( V_127 -> V_263 && args -> V_174 ) {
struct V_10 * V_20 ;
V_20 = F_154 ( V_127 , & V_206 ,
V_216 -> V_222 -> V_33 ,
V_5 ,
args -> V_173 ,
args -> V_174 ,
F_170 ( V_31 ) ) ;
if ( F_22 ( V_20 ) ) {
V_37 = F_23 ( V_20 ) ;
goto V_42;
}
if ( V_20 ) {
V_225 |= V_250 ;
V_216 -> V_223 = 0 ;
V_216 -> V_222 = V_20 ;
}
}
V_216 -> V_222 -> V_33 -> V_54 . V_110 |= V_155 ;
if ( V_225 & V_250 ) {
struct V_32 * V_33 = V_216 -> V_222 -> V_33 ;
struct V_10 * V_20 ;
V_20 = F_64 ( V_33 , NULL , 0 , 0 , 0 ) ;
if ( F_22 ( V_20 ) ) {
V_37 = F_23 ( V_20 ) ;
goto V_42;
}
V_216 -> V_222 = V_20 ;
}
V_216 -> V_219 = F_180 ( V_127 , V_144 ) ;
if ( F_22 ( V_216 -> V_219 ) ) {
V_37 = F_23 ( V_216 -> V_219 ) ;
goto V_264;
}
if ( V_243 ) {
V_37 = F_181 ( V_216 -> V_219 ,
V_243 ) ;
if ( V_37 < 0 )
goto V_265;
}
if ( V_246 != - 1 ) {
V_245 = F_182 ( & V_216 -> V_219 -> V_203 ) ;
if ( ! V_245 ) {
V_37 = - V_160 ;
goto V_265;
}
}
V_216 -> V_219 -> V_222 = V_216 -> V_222 ;
V_216 -> V_55 = V_55 ;
V_216 -> V_31 = V_31 ;
V_216 -> V_127 = V_127 ;
V_216 -> V_225 = V_225 ;
V_216 -> V_144 = V_144 ;
F_183 ( V_216 -> V_219 , V_225 ) ;
V_37 = F_161 ( V_216 , args , & V_5 -> V_18 ) ;
V_265:
F_184 ( V_216 -> V_219 , V_37 == 0 ) ;
F_160 ( V_216 -> V_219 , V_31 ) ;
if ( V_245 ) {
if ( V_37 == 0 ) {
F_185 ( V_246 , V_245 -> V_31 ) ;
args -> V_257 &= F_186 ( 0 , 31 ) ;
args -> V_257 |= ( T_4 ) V_246 << 32 ;
V_246 = - 1 ;
} else {
F_187 ( V_245 -> V_31 ) ;
}
}
V_264:
if ( V_225 & V_250 )
F_55 ( V_216 -> V_222 ) ;
V_42:
F_177 ( V_144 ) ;
F_33 ( V_5 ) ;
F_111 ( & V_55 -> V_159 ) ;
V_261:
F_188 ( V_100 ) ;
if ( V_246 != - 1 )
F_189 ( V_246 ) ;
V_260:
F_190 ( V_243 ) ;
return V_37 ;
}
int
F_191 ( struct V_156 * V_55 , void * V_240 ,
struct V_30 * V_31 )
{
struct V_266 * args = V_240 ;
struct V_4 V_267 ;
struct V_268 * V_22 = NULL ;
struct V_26 * V_269 = NULL ;
int V_37 , V_36 ;
if ( args -> V_9 < 1 ) {
F_15 ( L_22 , args -> V_9 ) ;
return - V_44 ;
}
V_22 = F_112 ( sizeof( * V_22 ) , args -> V_9 ) ;
V_269 = F_112 ( sizeof( * V_269 ) , args -> V_9 ) ;
if ( V_22 == NULL || V_269 == NULL ) {
F_15 ( L_27 ,
args -> V_9 ) ;
F_113 ( V_22 ) ;
F_113 ( V_269 ) ;
return - V_160 ;
}
V_37 = F_115 ( V_22 ,
F_81 ( args -> V_270 ) ,
sizeof( * V_22 ) * args -> V_9 ) ;
if ( V_37 != 0 ) {
F_15 ( L_28 ,
args -> V_9 , V_37 ) ;
F_113 ( V_22 ) ;
F_113 ( V_269 ) ;
return - V_121 ;
}
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_269 [ V_36 ] . V_40 = V_22 [ V_36 ] . V_40 ;
V_269 [ V_36 ] . V_118 = V_22 [ V_36 ] . V_118 ;
V_269 [ V_36 ] . V_117 = V_22 [ V_36 ] . V_117 ;
V_269 [ V_36 ] . V_138 = V_22 [ V_36 ] . V_138 ;
V_269 [ V_36 ] . V_85 = V_22 [ V_36 ] . V_85 ;
if ( F_102 ( F_39 ( V_55 ) ) < 4 )
V_269 [ V_36 ] . V_6 = V_124 ;
else
V_269 [ V_36 ] . V_6 = 0 ;
}
V_267 . V_270 = args -> V_270 ;
V_267 . V_9 = args -> V_9 ;
V_267 . V_173 = args -> V_173 ;
V_267 . V_174 = args -> V_174 ;
V_267 . V_172 = args -> V_172 ;
V_267 . V_171 = args -> V_171 ;
V_267 . V_169 = args -> V_169 ;
V_267 . V_170 = args -> V_170 ;
V_267 . V_6 = V_271 ;
F_192 ( V_267 , 0 ) ;
V_37 = F_168 ( V_55 , V_240 , V_31 , & V_267 , V_269 ) ;
if ( ! V_37 ) {
struct V_268 T_6 * V_272 =
F_81 ( args -> V_270 ) ;
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_269 [ V_36 ] . V_85 =
F_40 ( V_269 [ V_36 ] . V_85 ) ;
V_37 = F_116 ( & V_272 [ V_36 ] . V_85 ,
& V_269 [ V_36 ] . V_85 ,
sizeof( V_272 [ V_36 ] . V_85 ) ) ;
if ( V_37 ) {
V_37 = - V_121 ;
F_15 ( L_29
L_30 ,
args -> V_9 , V_37 ) ;
break;
}
}
}
F_113 ( V_22 ) ;
F_113 ( V_269 ) ;
return V_37 ;
}
int
F_193 ( struct V_156 * V_55 , void * V_240 ,
struct V_30 * V_31 )
{
struct V_4 * args = V_240 ;
struct V_26 * V_269 = NULL ;
int V_37 ;
if ( args -> V_9 < 1 ||
args -> V_9 > V_177 / sizeof( * V_269 ) ) {
F_15 ( L_31 , args -> V_9 ) ;
return - V_44 ;
}
V_269 = F_194 ( args -> V_9 ,
sizeof( * V_269 ) ,
V_11 ) ;
if ( V_269 == NULL ) {
F_15 ( L_27 ,
args -> V_9 ) ;
return - V_160 ;
}
V_37 = F_115 ( V_269 ,
F_81 ( args -> V_270 ) ,
sizeof( * V_269 ) * args -> V_9 ) ;
if ( V_37 != 0 ) {
F_15 ( L_28 ,
args -> V_9 , V_37 ) ;
F_113 ( V_269 ) ;
return - V_121 ;
}
V_37 = F_168 ( V_55 , V_240 , V_31 , args , V_269 ) ;
if ( ! V_37 ) {
struct V_26 T_6 * V_272 =
F_81 ( args -> V_270 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_269 [ V_36 ] . V_85 =
F_40 ( V_269 [ V_36 ] . V_85 ) ;
V_37 = F_116 ( & V_272 [ V_36 ] . V_85 ,
& V_269 [ V_36 ] . V_85 ,
sizeof( V_272 [ V_36 ] . V_85 ) ) ;
if ( V_37 ) {
V_37 = - V_121 ;
F_15 ( L_29
L_32 ,
args -> V_9 ) ;
break;
}
}
}
F_113 ( V_269 ) ;
return V_37 ;
}
