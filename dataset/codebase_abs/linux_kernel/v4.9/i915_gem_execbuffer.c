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
return ( F_38 ( V_33 -> V_54 . V_55 ) ||
V_33 -> V_54 . V_56 == V_57 ||
V_33 -> V_58 != V_59 ) ;
}
static inline T_2 F_39 ( T_2 V_60 )
{
return F_40 ( V_60 , V_61 ) ;
}
static inline T_2 F_41 ( T_2 V_60 )
{
return V_60 & ( ( 1ULL << ( V_61 + 1 ) ) - 1 ) ;
}
static inline T_2
F_42 ( const struct V_62 * V_63 ,
T_2 V_64 )
{
return F_39 ( ( int ) V_63 -> V_65 + V_64 ) ;
}
static void F_43 ( struct V_66 * V_67 ,
struct V_2 * V_3 )
{
V_67 -> V_68 = - 1 ;
V_67 -> V_69 = 0 ;
V_67 -> V_3 = V_3 ;
V_67 -> V_70 = F_44 ( V_67 -> V_3 ) >= 8 ;
V_67 -> V_50 . V_71 = false ;
}
static inline void * F_45 ( unsigned long V_72 )
{
return ( void * ) ( V_73 ) ( V_72 & V_74 ) ;
}
static inline unsigned int F_46 ( unsigned long V_72 )
{
return V_72 & ~ V_74 ;
}
static void F_47 ( struct V_66 * V_67 )
{
void * V_69 ;
if ( ! V_67 -> V_69 )
return;
V_69 = F_45 ( V_67 -> V_69 ) ;
if ( V_67 -> V_69 & V_75 ) {
if ( V_67 -> V_69 & V_76 )
F_48 () ;
F_49 ( V_69 ) ;
F_50 ( (struct V_32 * ) V_67 -> V_50 . V_77 ) ;
} else {
F_51 () ;
F_52 ( ( void V_78 * ) V_69 ) ;
if ( V_67 -> V_50 . V_71 ) {
struct V_79 * V_80 = & V_67 -> V_3 -> V_80 ;
V_80 -> V_54 . V_81 ( & V_80 -> V_54 ,
V_67 -> V_50 . V_82 ,
V_67 -> V_50 . V_8 ,
true ) ;
F_53 ( & V_67 -> V_50 ) ;
} else {
F_54 ( (struct V_10 * ) V_67 -> V_50 . V_77 ) ;
}
}
}
static void * F_55 ( struct V_32 * V_33 ,
struct V_66 * V_67 ,
int V_68 )
{
void * V_69 ;
if ( V_67 -> V_69 ) {
F_49 ( F_45 ( V_67 -> V_69 ) ) ;
} else {
unsigned int V_83 ;
int V_37 ;
V_37 = F_56 ( V_33 , & V_83 ) ;
if ( V_37 )
return F_57 ( V_37 ) ;
F_58 ( V_75 & V_84 ) ;
F_58 ( ( V_75 | V_84 ) & V_74 ) ;
V_67 -> V_69 = V_83 | V_75 ;
V_67 -> V_50 . V_77 = ( void * ) V_33 ;
if ( V_83 )
F_48 () ;
}
V_69 = F_59 ( F_60 ( V_33 , V_68 ) ) ;
V_67 -> V_69 = F_46 ( V_67 -> V_69 ) | ( unsigned long ) V_69 ;
V_67 -> V_68 = V_68 ;
return V_69 ;
}
static void * F_61 ( struct V_32 * V_33 ,
struct V_66 * V_67 ,
int V_68 )
{
struct V_79 * V_80 = & V_67 -> V_3 -> V_80 ;
unsigned long V_85 ;
void * V_69 ;
if ( V_67 -> V_50 . V_71 ) {
F_51 () ;
V_80 -> V_54 . V_86 ( & V_80 -> V_54 ,
F_62 ( V_33 , V_68 ) ,
V_67 -> V_50 . V_82 , V_59 , 0 ) ;
V_67 -> V_68 = V_68 ;
return F_45 ( V_67 -> V_69 ) ;
}
if ( V_67 -> V_69 ) {
F_52 ( F_45 ( V_67 -> V_69 ) ) ;
} else {
struct V_10 * V_20 ;
int V_37 ;
if ( F_36 ( V_33 ) )
return NULL ;
V_37 = F_63 ( V_33 , true ) ;
if ( V_37 )
return F_57 ( V_37 ) ;
V_20 = F_64 ( V_33 , NULL , 0 , 0 ,
V_87 | V_88 ) ;
if ( F_22 ( V_20 ) ) {
memset ( & V_67 -> V_50 , 0 , sizeof( V_67 -> V_50 ) ) ;
V_37 = F_65
( & V_80 -> V_54 . V_77 , & V_67 -> V_50 ,
4096 , 0 , 0 ,
0 , V_80 -> V_89 ,
V_90 ,
V_91 ) ;
if ( V_37 )
return NULL ;
} else {
V_37 = F_66 ( V_20 ) ;
if ( V_37 ) {
F_54 ( V_20 ) ;
return F_57 ( V_37 ) ;
}
V_67 -> V_50 . V_82 = V_20 -> V_50 . V_82 ;
V_67 -> V_50 . V_77 = ( void * ) V_20 ;
}
}
V_85 = V_67 -> V_50 . V_82 ;
if ( V_67 -> V_50 . V_71 ) {
V_80 -> V_54 . V_86 ( & V_80 -> V_54 ,
F_62 ( V_33 , V_68 ) ,
V_85 , V_59 , 0 ) ;
} else {
V_85 += V_68 << V_92 ;
}
V_69 = F_67 ( & V_67 -> V_3 -> V_80 . V_93 , V_85 ) ;
V_67 -> V_68 = V_68 ;
V_67 -> V_69 = ( unsigned long ) V_69 ;
return V_69 ;
}
static void * F_68 ( struct V_32 * V_33 ,
struct V_66 * V_67 ,
int V_68 )
{
void * V_69 ;
if ( V_67 -> V_68 == V_68 ) {
V_69 = F_45 ( V_67 -> V_69 ) ;
} else {
V_69 = NULL ;
if ( ( V_67 -> V_69 & V_75 ) == 0 )
V_69 = F_61 ( V_33 , V_67 , V_68 ) ;
if ( ! V_69 )
V_69 = F_55 ( V_33 , V_67 , V_68 ) ;
}
return V_69 ;
}
static void F_69 ( T_3 * V_94 , T_3 V_95 , unsigned int V_83 )
{
if ( F_21 ( V_83 & ( V_96 | V_76 ) ) ) {
if ( V_83 & V_96 ) {
F_70 ( V_94 ) ;
F_48 () ;
}
* V_94 = V_95 ;
if ( V_83 & V_76 )
F_70 ( V_94 ) ;
} else
* V_94 = V_95 ;
}
static int
F_71 ( struct V_32 * V_33 ,
const struct V_62 * V_63 ,
struct V_66 * V_67 ,
T_4 V_64 )
{
T_4 V_85 = V_63 -> V_85 ;
bool V_97 = V_67 -> V_70 ;
void * V_69 ;
V_64 = F_42 ( V_63 , V_64 ) ;
V_98:
V_69 = F_68 ( V_33 , V_67 , V_85 >> V_92 ) ;
if ( F_22 ( V_69 ) )
return F_23 ( V_69 ) ;
F_69 ( V_69 + F_72 ( V_85 ) ,
F_73 ( V_64 ) ,
V_67 -> V_69 ) ;
if ( V_97 ) {
V_85 += sizeof( T_3 ) ;
V_64 >>= 32 ;
V_97 = false ;
goto V_98;
}
return 0 ;
}
static bool F_74 ( struct V_32 * V_33 )
{
unsigned long V_99 = F_75 ( V_33 ) ;
int V_100 ;
F_76 (active, idx) {
if ( ! F_77 ( & V_33 -> V_101 [ V_100 ] ,
& V_33 -> V_54 . V_55 -> V_102 ) )
return false ;
}
return true ;
}
static int
F_78 ( struct V_32 * V_33 ,
struct V_1 * V_5 ,
struct V_62 * V_63 ,
struct V_66 * V_67 )
{
struct V_103 * V_55 = V_33 -> V_54 . V_55 ;
struct V_104 * V_105 ;
struct V_32 * V_106 ;
struct V_10 * V_107 ;
T_2 V_64 ;
int V_37 ;
V_107 = F_27 ( V_5 , V_63 -> V_108 ) ;
if ( F_21 ( V_107 == NULL ) )
return - V_41 ;
V_106 = V_107 -> V_33 ;
V_105 = & V_107 -> V_33 -> V_54 ;
V_64 = F_39 ( V_107 -> V_50 . V_82 ) ;
if ( F_21 ( F_79 ( V_55 ) &&
V_63 -> V_56 == V_109 ) ) {
V_37 = F_80 ( V_107 , V_106 -> V_58 ,
V_110 ) ;
if ( F_81 ( V_37 , L_4 ) )
return V_37 ;
}
if ( F_21 ( V_63 -> V_56 & ( V_63 -> V_56 - 1 ) ) ) {
F_15 ( L_5
L_6
L_7 ,
V_33 , V_63 -> V_108 ,
( int ) V_63 -> V_85 ,
V_63 -> V_111 ,
V_63 -> V_56 ) ;
return - V_44 ;
}
if ( F_21 ( ( V_63 -> V_56 | V_63 -> V_111 )
& ~ V_112 ) ) {
F_15 ( L_8
L_6
L_7 ,
V_33 , V_63 -> V_108 ,
( int ) V_63 -> V_85 ,
V_63 -> V_111 ,
V_63 -> V_56 ) ;
return - V_44 ;
}
V_105 -> V_113 |= V_63 -> V_111 ;
V_105 -> V_114 |= V_63 -> V_56 ;
if ( V_64 == V_63 -> V_115 )
return 0 ;
if ( F_21 ( V_63 -> V_85 >
V_33 -> V_54 . V_8 - ( V_67 -> V_70 ? 8 : 4 ) ) ) {
F_15 ( L_9
L_10 ,
V_33 , V_63 -> V_108 ,
( int ) V_63 -> V_85 ,
( int ) V_33 -> V_54 . V_8 ) ;
return - V_44 ;
}
if ( F_21 ( V_63 -> V_85 & 3 ) ) {
F_15 ( L_11
L_12 ,
V_33 , V_63 -> V_108 ,
( int ) V_63 -> V_85 ) ;
return - V_44 ;
}
if ( F_82 () && ! F_74 ( V_33 ) )
return - V_116 ;
V_37 = F_71 ( V_33 , V_63 , V_67 , V_64 ) ;
if ( V_37 )
return V_37 ;
V_63 -> V_115 = V_64 ;
return 0 ;
}
static int
F_83 ( struct V_10 * V_20 ,
struct V_1 * V_5 )
{
#define F_84 ( T_5 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_62 V_117 [ F_84 ( 512 ) ] ;
struct V_62 T_6 * V_118 ;
struct V_26 * V_49 = V_20 -> V_23 ;
struct V_66 V_67 ;
int V_119 , V_37 = 0 ;
V_118 = F_85 ( V_49 -> V_120 ) ;
F_43 ( & V_67 , V_5 -> V_3 ) ;
V_119 = V_49 -> V_121 ;
while ( V_119 ) {
struct V_62 * V_122 = V_117 ;
int V_14 = V_119 ;
if ( V_14 > F_86 ( V_117 ) )
V_14 = F_86 ( V_117 ) ;
V_119 -= V_14 ;
if ( F_87 ( V_122 , V_118 , V_14 * sizeof( V_122 [ 0 ] ) ) ) {
V_37 = - V_116 ;
goto V_123;
}
do {
T_4 V_85 = V_122 -> V_115 ;
V_37 = F_78 ( V_20 -> V_33 , V_5 , V_122 , & V_67 ) ;
if ( V_37 )
goto V_123;
if ( V_122 -> V_115 != V_85 &&
F_88 ( V_122 -> V_115 ,
& V_118 -> V_115 ) ) {
V_37 = - V_116 ;
goto V_123;
}
V_118 ++ ;
V_122 ++ ;
} while ( -- V_14 );
}
V_123:
F_47 ( & V_67 ) ;
return V_37 ;
#undef F_84
}
static int
F_89 ( struct V_10 * V_20 ,
struct V_1 * V_5 ,
struct V_62 * V_124 )
{
const struct V_26 * V_49 = V_20 -> V_23 ;
struct V_66 V_67 ;
int V_36 , V_37 = 0 ;
F_43 ( & V_67 , V_5 -> V_3 ) ;
for ( V_36 = 0 ; V_36 < V_49 -> V_121 ; V_36 ++ ) {
V_37 = F_78 ( V_20 -> V_33 , V_5 , & V_124 [ V_36 ] , & V_67 ) ;
if ( V_37 )
break;
}
F_47 ( & V_67 ) ;
return V_37 ;
}
static int
F_90 ( struct V_1 * V_5 )
{
struct V_10 * V_20 ;
int V_37 = 0 ;
F_91 () ;
F_92 (vma, &eb->vmas, exec_list) {
V_37 = F_83 ( V_20 , V_5 ) ;
if ( V_37 )
break;
}
F_93 () ;
return V_37 ;
}
static bool F_94 ( unsigned int V_6 )
{
return ( V_6 & ( V_125 | V_126 ) ) ==
V_126 ;
}
static int
F_95 ( struct V_10 * V_20 ,
struct V_127 * V_128 ,
bool * V_129 )
{
struct V_32 * V_33 = V_20 -> V_33 ;
struct V_26 * V_49 = V_20 -> V_23 ;
T_2 V_6 ;
int V_37 ;
V_6 = V_130 ;
if ( V_49 -> V_6 & V_131 )
V_6 |= V_110 ;
if ( ! F_30 ( & V_20 -> V_50 ) ) {
if ( ( V_49 -> V_6 & V_132 ) == 0 )
V_6 |= V_133 ;
if ( V_49 -> V_6 & V_126 )
V_6 |= V_110 | V_87 ;
if ( V_49 -> V_6 & V_25 )
V_6 |= V_134 | V_135 ;
if ( V_49 -> V_6 & V_24 )
V_6 |= V_49 -> V_85 | V_136 ;
if ( ( V_6 & V_87 ) == 0 )
V_6 |= V_137 ;
}
V_37 = F_96 ( V_20 ,
V_49 -> V_138 ,
V_49 -> V_139 ,
V_6 ) ;
if ( ( V_37 == - V_140 || V_37 == - V_141 ) &&
F_94 ( V_49 -> V_6 ) )
V_37 = F_96 ( V_20 ,
V_49 -> V_138 ,
V_49 -> V_139 ,
V_6 & ~ V_87 ) ;
if ( V_37 )
return V_37 ;
V_49 -> V_6 |= V_52 ;
if ( V_49 -> V_6 & V_125 ) {
V_37 = F_97 ( V_20 ) ;
if ( V_37 )
return V_37 ;
if ( F_98 ( V_20 ) )
V_49 -> V_6 |= V_51 ;
}
if ( V_49 -> V_85 != V_20 -> V_50 . V_82 ) {
V_49 -> V_85 = V_20 -> V_50 . V_82 ;
* V_129 = true ;
}
if ( V_49 -> V_6 & V_142 ) {
V_33 -> V_54 . V_113 = V_143 ;
V_33 -> V_54 . V_114 = V_143 ;
}
return 0 ;
}
static bool
F_99 ( struct V_10 * V_20 )
{
struct V_26 * V_49 = V_20 -> V_23 ;
if ( V_49 -> V_121 == 0 )
return false ;
if ( ! F_100 ( V_20 ) )
return false ;
if ( F_38 ( V_20 -> V_33 -> V_54 . V_55 ) )
return false ;
if ( V_20 -> V_33 -> V_54 . V_56 == V_57 )
return false ;
return true ;
}
static bool
F_101 ( struct V_10 * V_20 )
{
struct V_26 * V_49 = V_20 -> V_23 ;
F_102 ( V_49 -> V_6 & V_126 &&
! F_100 ( V_20 ) ) ;
if ( V_49 -> V_139 &&
V_20 -> V_50 . V_82 & ( V_49 -> V_139 - 1 ) )
return true ;
if ( V_20 -> V_50 . V_8 < V_49 -> V_138 )
return true ;
if ( V_49 -> V_6 & V_24 &&
V_20 -> V_50 . V_82 != V_49 -> V_85 )
return true ;
if ( V_49 -> V_6 & V_25 &&
V_20 -> V_50 . V_82 < V_134 )
return true ;
if ( V_49 -> V_6 & V_126 &&
! F_103 ( V_20 ) )
return ! F_94 ( V_49 -> V_6 ) ;
if ( ( V_49 -> V_6 & V_132 ) == 0 &&
( V_20 -> V_50 . V_82 + V_20 -> V_50 . V_8 - 1 ) >> 32 )
return true ;
return false ;
}
static int
F_104 ( struct V_127 * V_128 ,
struct V_34 * V_18 ,
struct V_144 * V_145 ,
bool * V_146 )
{
struct V_32 * V_33 ;
struct V_10 * V_20 ;
struct V_28 * V_29 ;
struct V_34 V_147 ;
struct V_34 V_148 ;
bool V_149 = F_44 ( V_128 -> V_3 ) < 4 ;
int V_150 ;
V_29 = F_19 ( V_18 , struct V_10 , V_22 ) -> V_29 ;
F_5 ( & V_147 ) ;
F_5 ( & V_148 ) ;
while ( ! F_16 ( V_18 ) ) {
struct V_26 * V_49 ;
bool V_151 , V_152 ;
V_20 = F_19 ( V_18 , struct V_10 , V_22 ) ;
V_33 = V_20 -> V_33 ;
V_49 = V_20 -> V_23 ;
if ( V_145 -> V_6 & V_153 )
V_49 -> V_6 |= V_25 ;
if ( ! V_149 )
V_49 -> V_6 &= ~ V_125 ;
V_151 =
V_49 -> V_6 & V_125 &&
F_105 ( V_33 ) ;
V_152 = V_151 || F_99 ( V_20 ) ;
if ( V_49 -> V_6 & V_24 )
F_106 ( & V_20 -> V_22 , & V_148 ) ;
else if ( V_152 ) {
V_49 -> V_6 |= V_126 ;
F_107 ( & V_20 -> V_22 , & V_147 ) ;
} else
F_106 ( & V_20 -> V_22 , & V_147 ) ;
V_33 -> V_54 . V_113 = V_112 & ~ V_154 ;
V_33 -> V_54 . V_114 = 0 ;
}
F_108 ( & V_147 , V_18 ) ;
F_108 ( & V_148 , V_18 ) ;
V_150 = 0 ;
do {
int V_37 = 0 ;
F_92 (vma, vmas, exec_list) {
if ( ! F_30 ( & V_20 -> V_50 ) )
continue;
if ( F_101 ( V_20 ) )
V_37 = F_109 ( V_20 ) ;
else
V_37 = F_95 ( V_20 ,
V_128 ,
V_146 ) ;
if ( V_37 )
goto V_42;
}
F_92 (vma, vmas, exec_list) {
if ( F_30 ( & V_20 -> V_50 ) )
continue;
V_37 = F_95 ( V_20 , V_128 ,
V_146 ) ;
if ( V_37 )
goto V_42;
}
V_42:
if ( V_37 != - V_140 || V_150 ++ )
return V_37 ;
F_92 (vma, vmas, exec_list)
F_29 ( V_20 ) ;
V_37 = F_110 ( V_29 , true ) ;
if ( V_37 )
return V_37 ;
} while ( 1 );
}
static int
F_111 ( struct V_103 * V_55 ,
struct V_4 * args ,
struct V_30 * V_31 ,
struct V_127 * V_128 ,
struct V_1 * V_5 ,
struct V_26 * V_27 ,
struct V_144 * V_145 )
{
struct V_62 * V_63 ;
struct V_28 * V_29 ;
struct V_10 * V_20 ;
bool V_146 ;
int * V_155 ;
int V_36 , V_156 , V_37 ;
unsigned V_14 = args -> V_9 ;
V_29 = F_19 ( & V_5 -> V_18 , struct V_10 , V_22 ) -> V_29 ;
while ( ! F_16 ( & V_5 -> V_18 ) ) {
V_20 = F_19 ( & V_5 -> V_18 , struct V_10 , V_22 ) ;
F_24 ( & V_20 -> V_22 ) ;
F_29 ( V_20 ) ;
F_34 ( V_20 ) ;
}
F_112 ( & V_55 -> V_102 ) ;
V_156 = 0 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ )
V_156 += V_27 [ V_36 ] . V_121 ;
V_155 = F_113 ( V_14 , sizeof( * V_155 ) ) ;
V_63 = F_113 ( V_156 , sizeof( * V_63 ) ) ;
if ( V_63 == NULL || V_155 == NULL ) {
F_114 ( V_63 ) ;
F_114 ( V_155 ) ;
F_115 ( & V_55 -> V_102 ) ;
return - V_157 ;
}
V_156 = 0 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
struct V_62 T_6 * V_118 ;
T_4 V_158 = ( T_4 ) - 1 ;
int V_159 ;
V_118 = F_85 ( V_27 [ V_36 ] . V_120 ) ;
if ( F_116 ( V_63 + V_156 , V_118 ,
V_27 [ V_36 ] . V_121 * sizeof( * V_63 ) ) ) {
V_37 = - V_116 ;
F_115 ( & V_55 -> V_102 ) ;
goto V_42;
}
for ( V_159 = 0 ; V_159 < V_27 [ V_36 ] . V_121 ; V_159 ++ ) {
if ( F_117 ( & V_118 [ V_159 ] . V_115 ,
& V_158 ,
sizeof( V_158 ) ) ) {
V_37 = - V_116 ;
F_115 ( & V_55 -> V_102 ) ;
goto V_42;
}
}
V_155 [ V_36 ] = V_156 ;
V_156 += V_27 [ V_36 ] . V_121 ;
}
V_37 = F_118 ( V_55 ) ;
if ( V_37 ) {
F_115 ( & V_55 -> V_102 ) ;
goto V_42;
}
F_6 ( V_5 ) ;
V_37 = F_10 ( V_5 , V_27 , args , V_29 , V_31 ) ;
if ( V_37 )
goto V_42;
V_146 = ( args -> V_6 & V_160 ) == 0 ;
V_37 = F_104 ( V_128 , & V_5 -> V_18 , V_145 ,
& V_146 ) ;
if ( V_37 )
goto V_42;
F_92 (vma, &eb->vmas, exec_list) {
int V_85 = V_20 -> V_23 - V_27 ;
V_37 = F_89 ( V_20 , V_5 ,
V_63 + V_155 [ V_85 ] ) ;
if ( V_37 )
goto V_42;
}
V_42:
F_114 ( V_63 ) ;
F_114 ( V_155 ) ;
return V_37 ;
}
static unsigned int F_119 ( struct V_161 * V_162 )
{
unsigned int V_163 ;
V_163 = ~ F_120 ( V_162 -> V_128 ) & V_164 ;
V_163 <<= V_165 ;
return V_163 ;
}
static int
F_121 ( struct V_161 * V_162 ,
struct V_34 * V_18 )
{
const unsigned int V_166 = F_119 ( V_162 ) ;
struct V_10 * V_20 ;
int V_37 ;
F_92 (vma, vmas, exec_list) {
struct V_32 * V_33 = V_20 -> V_33 ;
struct V_167 * V_168 ;
if ( V_33 -> V_6 & V_166 ) {
V_37 = F_122
( V_162 , V_33 , V_33 -> V_54 . V_114 ) ;
if ( V_37 )
return V_37 ;
}
V_168 = F_123 ( V_33 ) ;
if ( V_168 ) {
V_37 = F_124
( & V_162 -> V_169 , V_168 , & V_170 ,
V_33 -> V_54 . V_114 , 10 * V_171 ,
V_172 | V_12 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( V_33 -> V_54 . V_56 & V_57 )
F_125 ( V_33 , false ) ;
}
F_126 ( V_162 -> V_128 -> V_3 ) ;
return V_162 -> V_128 -> V_173 ( V_162 , V_174 ) ;
}
static bool
F_127 ( struct V_4 * V_27 )
{
if ( V_27 -> V_6 & V_175 )
return false ;
if ( V_27 -> V_176 || V_27 -> V_177 )
return false ;
if ( V_27 -> V_178 == 0xffffffff ) {
F_15 ( L_13 ) ;
V_27 -> V_178 = 0 ;
}
if ( V_27 -> V_179 || V_27 -> V_178 )
return false ;
if ( ( V_27 -> V_180 | V_27 -> V_181 ) & 0x7 )
return false ;
return true ;
}
static int
F_128 ( struct V_103 * V_55 ,
struct V_26 * V_27 ,
int V_14 )
{
unsigned V_182 = 0 ;
unsigned V_183 = V_184 / sizeof( struct V_62 ) ;
unsigned V_185 ;
int V_36 ;
F_58 ( V_186 & ~ V_187 ) ;
V_185 = V_187 ;
if ( F_129 ( V_55 ) )
V_185 |= V_131 ;
for ( V_36 = 0 ; V_36 < V_14 ; V_36 ++ ) {
char T_6 * V_188 = F_85 ( V_27 [ V_36 ] . V_120 ) ;
int V_189 ;
if ( V_27 [ V_36 ] . V_6 & V_185 )
return - V_44 ;
if ( V_27 [ V_36 ] . V_6 & V_24 ) {
if ( V_27 [ V_36 ] . V_85 !=
F_39 ( V_27 [ V_36 ] . V_85 & V_74 ) )
return - V_44 ;
V_27 [ V_36 ] . V_85 = F_41 ( V_27 [ V_36 ] . V_85 ) ;
}
if ( V_27 [ V_36 ] . V_139 && ! F_130 ( V_27 [ V_36 ] . V_139 ) )
return - V_44 ;
if ( V_27 [ V_36 ] . V_6 & V_190 ) {
if ( F_72 ( V_27 [ V_36 ] . V_138 ) )
return - V_44 ;
} else {
V_27 [ V_36 ] . V_138 = 0 ;
}
if ( V_27 [ V_36 ] . V_121 > V_183 - V_182 )
return - V_44 ;
V_182 += V_27 [ V_36 ] . V_121 ;
V_189 = V_27 [ V_36 ] . V_121 *
sizeof( struct V_62 ) ;
if ( ! F_131 ( V_191 , V_188 , V_189 ) )
return - V_116 ;
if ( F_132 ( ! V_3 . V_192 ) ) {
if ( F_133 ( V_188 , V_189 ) )
return - V_116 ;
}
}
return 0 ;
}
static struct V_144 *
F_134 ( struct V_103 * V_55 , struct V_30 * V_31 ,
struct V_127 * V_128 , const T_3 V_193 )
{
struct V_144 * V_145 ;
struct V_194 * V_195 ;
V_145 = F_135 ( V_31 -> V_196 , V_193 ) ;
if ( F_22 ( V_145 ) )
return V_145 ;
V_195 = & V_145 -> V_197 ;
if ( V_195 -> V_198 ) {
F_15 ( L_14 , V_193 ) ;
return F_57 ( - V_199 ) ;
}
return V_145 ;
}
static bool F_136 ( struct V_32 * V_33 )
{
return ! ( V_33 -> V_58 == V_59 ||
V_33 -> V_58 == V_200 ) ;
}
void F_137 ( struct V_10 * V_20 ,
struct V_161 * V_162 ,
unsigned int V_6 )
{
struct V_32 * V_33 = V_20 -> V_33 ;
const unsigned int V_100 = V_162 -> V_128 -> V_201 ;
F_138 ( ! F_30 ( & V_20 -> V_50 ) ) ;
V_33 -> V_202 = 1 ;
if ( ! F_139 ( V_33 ) )
F_17 ( V_33 ) ;
F_140 ( V_33 , V_100 ) ;
F_141 ( & V_33 -> V_101 [ V_100 ] , V_162 ) ;
if ( V_6 & V_142 ) {
F_141 ( & V_33 -> V_203 , V_162 ) ;
F_142 ( V_33 , V_204 ) ;
V_33 -> V_54 . V_56 &= ~ V_112 ;
if ( ! V_33 -> V_205 && F_136 ( V_33 ) )
V_33 -> V_205 = true ;
}
if ( V_6 & V_125 )
F_141 ( & V_20 -> V_206 , V_162 ) ;
F_143 ( V_20 , V_100 ) ;
F_141 ( & V_20 -> V_101 [ V_100 ] , V_162 ) ;
F_106 ( & V_20 -> V_207 , & V_20 -> V_29 -> V_208 ) ;
}
static void F_144 ( struct V_32 * V_33 ,
struct V_161 * V_162 ,
unsigned int V_6 )
{
struct V_167 * V_168 ;
V_168 = F_123 ( V_33 ) ;
if ( ! V_168 )
return;
F_145 ( & V_168 -> V_209 , NULL ) ;
if ( V_6 & V_142 )
F_146 ( V_168 , & V_162 -> V_210 ) ;
else if ( F_147 ( V_168 ) == 0 )
F_148 ( V_168 , & V_162 -> V_210 ) ;
F_149 ( & V_168 -> V_209 ) ;
}
static void
F_150 ( struct V_34 * V_18 ,
struct V_161 * V_162 )
{
struct V_10 * V_20 ;
F_92 (vma, vmas, exec_list) {
struct V_32 * V_33 = V_20 -> V_33 ;
T_3 V_211 = V_33 -> V_54 . V_111 ;
T_3 V_212 = V_33 -> V_54 . V_56 ;
V_33 -> V_54 . V_56 = V_33 -> V_54 . V_114 ;
if ( V_33 -> V_54 . V_56 )
V_20 -> V_23 -> V_6 |= V_142 ;
else
V_33 -> V_54 . V_113 |= V_33 -> V_54 . V_111 ;
V_33 -> V_54 . V_111 = V_33 -> V_54 . V_113 ;
F_137 ( V_20 , V_162 , V_20 -> V_23 -> V_6 ) ;
F_144 ( V_33 , V_162 , V_20 -> V_23 -> V_6 ) ;
F_151 ( V_33 , V_211 , V_212 ) ;
}
}
static int
F_152 ( struct V_161 * V_162 )
{
struct V_213 * V_214 = V_162 -> V_214 ;
int V_37 , V_36 ;
if ( ! F_153 ( V_162 -> V_3 ) || V_162 -> V_128 -> V_201 != V_215 ) {
F_15 ( L_15 ) ;
return - V_44 ;
}
V_37 = F_154 ( V_162 , 4 * 3 ) ;
if ( V_37 )
return V_37 ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
F_155 ( V_214 , F_156 ( 1 ) ) ;
F_157 ( V_214 , F_158 ( V_36 ) ) ;
F_155 ( V_214 , 0 ) ;
}
F_159 ( V_214 ) ;
return 0 ;
}
static struct V_10 *
F_160 ( struct V_127 * V_128 ,
struct V_26 * V_216 ,
struct V_32 * V_217 ,
struct V_1 * V_5 ,
T_3 V_180 ,
T_3 V_181 ,
bool V_218 )
{
struct V_32 * V_219 ;
struct V_10 * V_20 ;
int V_37 ;
V_219 = F_161 ( & V_128 -> V_220 ,
F_162 ( V_181 ) ) ;
if ( F_22 ( V_219 ) )
return F_163 ( V_219 ) ;
V_37 = F_164 ( V_128 ,
V_217 ,
V_219 ,
V_180 ,
V_181 ,
V_218 ) ;
if ( V_37 ) {
if ( V_37 == - V_221 )
V_20 = NULL ;
else
V_20 = F_57 ( V_37 ) ;
goto V_123;
}
V_20 = F_64 ( V_219 , NULL , 0 , 0 , 0 ) ;
if ( F_22 ( V_20 ) )
goto V_123;
memset ( V_216 , 0 , sizeof( * V_216 ) ) ;
V_20 -> V_23 = V_216 ;
V_20 -> V_23 -> V_6 = V_52 ;
F_17 ( V_219 ) ;
F_18 ( & V_20 -> V_22 , & V_5 -> V_18 ) ;
V_123:
F_165 ( V_219 ) ;
return V_20 ;
}
static int
F_166 ( struct V_222 * V_223 ,
struct V_4 * args ,
struct V_34 * V_18 )
{
struct V_2 * V_224 = V_223 -> V_225 -> V_3 ;
T_4 V_226 , V_227 ;
int V_228 ;
T_3 V_229 ;
int V_37 ;
V_37 = F_121 ( V_223 -> V_225 , V_18 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_167 ( V_223 -> V_225 ) ;
if ( V_37 )
return V_37 ;
V_228 = args -> V_6 & V_230 ;
V_229 = V_230 ;
switch ( V_228 ) {
case V_231 :
case V_232 :
case V_233 :
if ( V_228 != 0 && V_223 -> V_128 -> V_201 != V_215 ) {
F_15 ( L_16 ) ;
return - V_44 ;
}
if ( V_228 != V_224 -> V_234 ) {
if ( F_168 ( V_224 ) -> V_235 < 4 ) {
F_15 ( L_17 ) ;
return - V_44 ;
}
if ( F_168 ( V_224 ) -> V_235 > 5 &&
V_228 == V_233 ) {
F_15 ( L_18 ) ;
return - V_44 ;
}
if ( F_168 ( V_224 ) -> V_235 >= 6 )
V_229 &= ~ V_233 ;
}
break;
default:
F_15 ( L_19 , V_228 ) ;
return - V_44 ;
}
if ( V_223 -> V_128 -> V_201 == V_215 &&
V_228 != V_224 -> V_234 ) {
struct V_213 * V_214 = V_223 -> V_225 -> V_214 ;
V_37 = F_154 ( V_223 -> V_225 , 4 ) ;
if ( V_37 )
return V_37 ;
F_155 ( V_214 , V_236 ) ;
F_155 ( V_214 , F_156 ( 1 ) ) ;
F_157 ( V_214 , V_237 ) ;
F_155 ( V_214 , V_229 << 16 | V_228 ) ;
F_159 ( V_214 ) ;
V_224 -> V_234 = V_228 ;
}
if ( args -> V_6 & V_238 ) {
V_37 = F_152 ( V_223 -> V_225 ) ;
if ( V_37 )
return V_37 ;
}
V_227 = args -> V_181 ;
V_226 = V_223 -> V_239 -> V_50 . V_82 +
V_223 -> V_240 ;
if ( V_227 == 0 )
V_227 = V_223 -> V_239 -> V_8 - V_223 -> V_240 ;
V_37 = V_223 -> V_128 -> V_241 ( V_223 -> V_225 ,
V_226 , V_227 ,
V_223 -> V_242 ) ;
if ( V_37 )
return V_37 ;
F_169 ( V_223 -> V_225 , V_223 -> V_242 ) ;
F_150 ( V_18 , V_223 -> V_225 ) ;
return 0 ;
}
static unsigned int
F_170 ( struct V_2 * V_224 ,
struct V_30 * V_31 )
{
struct V_243 * V_244 = V_31 -> V_196 ;
if ( ( int ) V_244 -> V_245 < 0 )
V_244 -> V_245 = F_171 ( 1 ,
& V_224 -> V_77 . V_246 ) ;
return V_244 -> V_245 ;
}
static struct V_127 *
F_172 ( struct V_2 * V_224 ,
struct V_30 * V_31 ,
struct V_4 * args )
{
unsigned int V_247 = args -> V_6 & V_248 ;
struct V_127 * V_128 ;
if ( V_247 > V_249 ) {
F_15 ( L_20 , V_247 ) ;
return NULL ;
}
if ( ( V_247 != V_250 ) &&
( ( args -> V_6 & V_251 ) != 0 ) ) {
F_15 ( L_21
L_22 , ( int ) ( args -> V_6 ) ) ;
return NULL ;
}
if ( V_247 == V_250 && F_173 ( V_224 ) ) {
unsigned int V_252 = args -> V_6 & V_251 ;
if ( V_252 == V_253 ) {
V_252 = F_170 ( V_224 , V_31 ) ;
} else if ( V_252 >= V_254 &&
V_252 <= V_255 ) {
V_252 >>= V_256 ;
V_252 -- ;
} else {
F_15 ( L_23 ,
V_252 ) ;
return NULL ;
}
V_128 = & V_224 -> V_128 [ F_174 ( V_252 ) ] ;
} else {
V_128 = & V_224 -> V_128 [ V_257 [ V_247 ] ] ;
}
if ( ! F_175 ( V_128 ) ) {
F_15 ( L_24 , V_247 ) ;
return NULL ;
}
return V_128 ;
}
static int
F_176 ( struct V_103 * V_55 , void * V_258 ,
struct V_30 * V_31 ,
struct V_4 * args ,
struct V_26 * V_27 )
{
struct V_2 * V_224 = F_177 ( V_55 ) ;
struct V_79 * V_80 = & V_224 -> V_80 ;
struct V_1 * V_5 ;
struct V_26 V_216 ;
struct V_127 * V_128 ;
struct V_144 * V_145 ;
struct V_28 * V_29 ;
struct V_222 V_259 ;
struct V_222 * V_223 = & V_259 ;
const T_3 V_193 = F_178 ( * args ) ;
T_3 V_242 ;
int V_37 ;
bool V_146 ;
if ( ! F_127 ( args ) )
return - V_44 ;
V_37 = F_128 ( V_55 , V_27 , args -> V_9 ) ;
if ( V_37 )
return V_37 ;
V_242 = 0 ;
if ( args -> V_6 & V_260 ) {
if ( ! F_179 ( V_31 ) || ! F_180 ( V_261 ) )
return - V_262 ;
V_242 |= V_263 ;
}
if ( args -> V_6 & V_264 )
V_242 |= V_265 ;
V_128 = F_172 ( V_224 , V_31 , args ) ;
if ( ! V_128 )
return - V_44 ;
if ( args -> V_9 < 1 ) {
F_15 ( L_25 , args -> V_9 ) ;
return - V_44 ;
}
if ( args -> V_6 & V_266 ) {
if ( ! F_181 ( V_55 ) ) {
F_15 ( L_26 ) ;
return - V_44 ;
}
if ( V_128 -> V_201 != V_215 ) {
F_15 ( L_27 ,
V_128 -> V_267 ) ;
return - V_44 ;
}
V_242 |= V_268 ;
}
F_182 ( V_224 ) ;
V_37 = F_118 ( V_55 ) ;
if ( V_37 )
goto V_269;
V_145 = F_134 ( V_55 , V_31 , V_128 , V_193 ) ;
if ( F_22 ( V_145 ) ) {
F_112 ( & V_55 -> V_102 ) ;
V_37 = F_23 ( V_145 ) ;
goto V_269;
}
F_183 ( V_145 ) ;
if ( V_145 -> V_270 )
V_29 = & V_145 -> V_270 -> V_54 ;
else
V_29 = & V_80 -> V_54 ;
memset ( & V_259 , 0x00 , sizeof( V_259 ) ) ;
V_5 = F_1 ( V_224 , args ) ;
if ( V_5 == NULL ) {
F_184 ( V_145 ) ;
F_112 ( & V_55 -> V_102 ) ;
V_37 = - V_157 ;
goto V_269;
}
V_37 = F_10 ( V_5 , V_27 , args , V_29 , V_31 ) ;
if ( V_37 )
goto V_42;
V_223 -> V_239 = F_7 ( V_5 ) ;
V_146 = ( args -> V_6 & V_160 ) == 0 ;
V_37 = F_104 ( V_128 , & V_5 -> V_18 , V_145 ,
& V_146 ) ;
if ( V_37 )
goto V_42;
if ( V_146 )
V_37 = F_90 ( V_5 ) ;
if ( V_37 ) {
if ( V_37 == - V_116 ) {
V_37 = F_111 ( V_55 , args , V_31 ,
V_128 ,
V_5 , V_27 , V_145 ) ;
F_185 ( ! F_186 ( & V_55 -> V_102 ) ) ;
}
if ( V_37 )
goto V_42;
}
if ( V_223 -> V_239 -> V_33 -> V_54 . V_114 ) {
F_15 ( L_28 ) ;
V_37 = - V_44 ;
goto V_42;
}
if ( args -> V_180 > V_223 -> V_239 -> V_8 ||
args -> V_181 > V_223 -> V_239 -> V_8 - args -> V_180 ) {
F_15 ( L_29 ) ;
V_37 = - V_44 ;
goto V_42;
}
V_223 -> V_240 = args -> V_180 ;
if ( F_187 ( V_128 ) && args -> V_181 ) {
struct V_10 * V_20 ;
V_20 = F_160 ( V_128 , & V_216 ,
V_223 -> V_239 -> V_33 ,
V_5 ,
args -> V_180 ,
args -> V_181 ,
F_179 ( V_31 ) ) ;
if ( F_22 ( V_20 ) ) {
V_37 = F_23 ( V_20 ) ;
goto V_42;
}
if ( V_20 ) {
V_242 |= V_263 ;
V_223 -> V_240 = 0 ;
V_223 -> V_239 = V_20 ;
}
}
V_223 -> V_239 -> V_33 -> V_54 . V_113 |= V_154 ;
if ( V_242 & V_263 ) {
struct V_32 * V_33 = V_223 -> V_239 -> V_33 ;
struct V_10 * V_20 ;
V_20 = F_64 ( V_33 , NULL , 0 , 0 , 0 ) ;
if ( F_22 ( V_20 ) ) {
V_37 = F_23 ( V_20 ) ;
goto V_42;
}
V_223 -> V_239 = V_20 ;
}
V_223 -> V_225 = F_188 ( V_128 , V_145 ) ;
if ( F_22 ( V_223 -> V_225 ) ) {
V_37 = F_23 ( V_223 -> V_225 ) ;
goto V_271;
}
V_223 -> V_225 -> V_239 = V_223 -> V_239 ;
V_37 = F_189 ( V_223 -> V_225 , V_31 ) ;
if ( V_37 )
goto V_272;
V_223 -> V_55 = V_55 ;
V_223 -> V_31 = V_31 ;
V_223 -> V_128 = V_128 ;
V_223 -> V_242 = V_242 ;
V_223 -> V_145 = V_145 ;
V_37 = F_166 ( V_223 , args , & V_5 -> V_18 ) ;
V_272:
F_190 ( V_223 -> V_225 , V_37 == 0 ) ;
V_271:
if ( V_242 & V_263 )
F_54 ( V_223 -> V_239 ) ;
V_42:
F_184 ( V_145 ) ;
F_33 ( V_5 ) ;
F_112 ( & V_55 -> V_102 ) ;
V_269:
F_191 ( V_224 ) ;
return V_37 ;
}
int
F_192 ( struct V_103 * V_55 , void * V_258 ,
struct V_30 * V_31 )
{
struct V_273 * args = V_258 ;
struct V_4 V_274 ;
struct V_275 * V_22 = NULL ;
struct V_26 * V_276 = NULL ;
int V_37 , V_36 ;
if ( args -> V_9 < 1 ) {
F_15 ( L_25 , args -> V_9 ) ;
return - V_44 ;
}
V_22 = F_113 ( sizeof( * V_22 ) , args -> V_9 ) ;
V_276 = F_113 ( sizeof( * V_276 ) , args -> V_9 ) ;
if ( V_22 == NULL || V_276 == NULL ) {
F_15 ( L_30 ,
args -> V_9 ) ;
F_114 ( V_22 ) ;
F_114 ( V_276 ) ;
return - V_157 ;
}
V_37 = F_116 ( V_22 ,
F_85 ( args -> V_277 ) ,
sizeof( * V_22 ) * args -> V_9 ) ;
if ( V_37 != 0 ) {
F_15 ( L_31 ,
args -> V_9 , V_37 ) ;
F_114 ( V_22 ) ;
F_114 ( V_276 ) ;
return - V_116 ;
}
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_276 [ V_36 ] . V_40 = V_22 [ V_36 ] . V_40 ;
V_276 [ V_36 ] . V_121 = V_22 [ V_36 ] . V_121 ;
V_276 [ V_36 ] . V_120 = V_22 [ V_36 ] . V_120 ;
V_276 [ V_36 ] . V_139 = V_22 [ V_36 ] . V_139 ;
V_276 [ V_36 ] . V_85 = V_22 [ V_36 ] . V_85 ;
if ( F_168 ( V_55 ) -> V_235 < 4 )
V_276 [ V_36 ] . V_6 = V_125 ;
else
V_276 [ V_36 ] . V_6 = 0 ;
}
V_274 . V_277 = args -> V_277 ;
V_274 . V_9 = args -> V_9 ;
V_274 . V_180 = args -> V_180 ;
V_274 . V_181 = args -> V_181 ;
V_274 . V_179 = args -> V_179 ;
V_274 . V_178 = args -> V_178 ;
V_274 . V_176 = args -> V_176 ;
V_274 . V_177 = args -> V_177 ;
V_274 . V_6 = V_278 ;
F_193 ( V_274 , 0 ) ;
V_37 = F_176 ( V_55 , V_258 , V_31 , & V_274 , V_276 ) ;
if ( ! V_37 ) {
struct V_275 T_6 * V_279 =
F_85 ( args -> V_277 ) ;
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_276 [ V_36 ] . V_85 =
F_39 ( V_276 [ V_36 ] . V_85 ) ;
V_37 = F_117 ( & V_279 [ V_36 ] . V_85 ,
& V_276 [ V_36 ] . V_85 ,
sizeof( V_279 [ V_36 ] . V_85 ) ) ;
if ( V_37 ) {
V_37 = - V_116 ;
F_15 ( L_32
L_33 ,
args -> V_9 , V_37 ) ;
break;
}
}
}
F_114 ( V_22 ) ;
F_114 ( V_276 ) ;
return V_37 ;
}
int
F_194 ( struct V_103 * V_55 , void * V_258 ,
struct V_30 * V_31 )
{
struct V_4 * args = V_258 ;
struct V_26 * V_276 = NULL ;
int V_37 ;
if ( args -> V_9 < 1 ||
args -> V_9 > V_184 / sizeof( * V_276 ) ) {
F_15 ( L_34 , args -> V_9 ) ;
return - V_44 ;
}
if ( args -> V_280 != 0 ) {
F_15 ( L_35 ) ;
return - V_44 ;
}
V_276 = F_195 ( args -> V_9 ,
sizeof( * V_276 ) ,
V_11 ) ;
if ( V_276 == NULL ) {
F_15 ( L_30 ,
args -> V_9 ) ;
return - V_157 ;
}
V_37 = F_116 ( V_276 ,
F_85 ( args -> V_277 ) ,
sizeof( * V_276 ) * args -> V_9 ) ;
if ( V_37 != 0 ) {
F_15 ( L_31 ,
args -> V_9 , V_37 ) ;
F_114 ( V_276 ) ;
return - V_116 ;
}
V_37 = F_176 ( V_55 , V_258 , V_31 , args , V_276 ) ;
if ( ! V_37 ) {
struct V_26 T_6 * V_279 =
F_85 ( args -> V_277 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < args -> V_9 ; V_36 ++ ) {
V_276 [ V_36 ] . V_85 =
F_39 ( V_276 [ V_36 ] . V_85 ) ;
V_37 = F_117 ( & V_279 [ V_36 ] . V_85 ,
& V_276 [ V_36 ] . V_85 ,
sizeof( V_279 [ V_36 ] . V_85 ) ) ;
if ( V_37 ) {
V_37 = - V_116 ;
F_15 ( L_32
L_36 ,
args -> V_9 ) ;
break;
}
}
}
F_114 ( V_276 ) ;
return V_37 ;
}
