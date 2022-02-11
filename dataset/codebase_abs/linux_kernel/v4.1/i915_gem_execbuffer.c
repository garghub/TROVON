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
V_25 -> V_57 != V_58 ) ;
}
static int
F_33 ( struct V_24 * V_25 ,
struct V_59 * V_60 ,
T_2 V_61 )
{
struct V_62 * V_54 = V_25 -> V_37 . V_54 ;
T_1 V_63 = F_34 ( V_60 -> V_64 ) ;
T_2 V_65 = V_60 -> V_65 + V_61 ;
char * V_66 ;
int V_29 ;
V_29 = F_35 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_66 = F_36 ( F_37 ( V_25 ,
V_60 -> V_64 >> V_67 ) ) ;
* ( T_1 * ) ( V_66 + V_63 ) = F_38 ( V_65 ) ;
if ( F_39 ( V_54 ) -> V_68 >= 8 ) {
V_63 = F_34 ( V_63 + sizeof( T_1 ) ) ;
if ( V_63 == 0 ) {
F_40 ( V_66 ) ;
V_66 = F_36 ( F_37 ( V_25 ,
( V_60 -> V_64 + sizeof( T_1 ) ) >> V_67 ) ) ;
}
* ( T_1 * ) ( V_66 + V_63 ) = F_41 ( V_65 ) ;
}
F_40 ( V_66 ) ;
return 0 ;
}
static int
F_42 ( struct V_24 * V_25 ,
struct V_59 * V_60 ,
T_2 V_61 )
{
struct V_62 * V_54 = V_25 -> V_37 . V_54 ;
struct V_69 * V_70 = V_54 -> V_71 ;
T_2 V_65 = V_60 -> V_65 + V_61 ;
T_2 V_64 ;
void T_3 * V_72 ;
int V_29 ;
V_29 = F_43 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_29 = F_44 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_64 = F_45 ( V_25 ) ;
V_64 += V_60 -> V_64 ;
V_72 = F_46 ( V_70 -> V_73 . V_74 ,
V_64 & V_75 ) ;
F_47 ( F_38 ( V_65 ) , V_72 + F_34 ( V_64 ) ) ;
if ( F_39 ( V_54 ) -> V_68 >= 8 ) {
V_64 += sizeof( T_1 ) ;
if ( F_34 ( V_64 ) == 0 ) {
F_48 ( V_72 ) ;
V_72 =
F_46 ( V_70 -> V_73 . V_74 ,
V_64 ) ;
}
F_47 ( F_41 ( V_65 ) ,
V_72 + F_34 ( V_64 ) ) ;
}
F_48 ( V_72 ) ;
return 0 ;
}
static void
F_49 ( void * V_76 , T_1 V_77 )
{
F_50 ( V_76 , sizeof( T_1 ) ) ;
* ( T_1 * ) V_76 = V_77 ;
F_50 ( V_76 , sizeof( T_1 ) ) ;
}
static int
F_51 ( struct V_24 * V_25 ,
struct V_59 * V_60 ,
T_2 V_61 )
{
struct V_62 * V_54 = V_25 -> V_37 . V_54 ;
T_1 V_63 = F_34 ( V_60 -> V_64 ) ;
T_2 V_65 = ( int ) V_60 -> V_65 + V_61 ;
char * V_66 ;
int V_29 ;
V_29 = F_43 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_66 = F_36 ( F_37 ( V_25 ,
V_60 -> V_64 >> V_67 ) ) ;
F_49 ( V_66 + V_63 , F_38 ( V_65 ) ) ;
if ( F_39 ( V_54 ) -> V_68 >= 8 ) {
V_63 = F_34 ( V_63 + sizeof( T_1 ) ) ;
if ( V_63 == 0 ) {
F_40 ( V_66 ) ;
V_66 = F_36 ( F_37 ( V_25 ,
( V_60 -> V_64 + sizeof( T_1 ) ) >> V_67 ) ) ;
}
F_49 ( V_66 + V_63 , F_41 ( V_65 ) ) ;
}
F_40 ( V_66 ) ;
return 0 ;
}
static int
F_52 ( struct V_24 * V_25 ,
struct V_1 * V_3 ,
struct V_59 * V_60 )
{
struct V_62 * V_54 = V_25 -> V_37 . V_54 ;
struct V_78 * V_79 ;
struct V_24 * V_80 ;
struct V_8 * V_81 ;
T_2 V_61 ;
int V_29 ;
V_81 = F_23 ( V_3 , V_60 -> V_82 ) ;
if ( F_53 ( V_81 == NULL ) )
return - V_33 ;
V_80 = V_81 -> V_25 ;
V_79 = & V_81 -> V_25 -> V_37 ;
V_61 = V_81 -> V_46 . V_83 ;
if ( F_53 ( F_54 ( V_54 ) &&
V_60 -> V_55 == V_84 &&
! ( V_81 -> V_85 & V_86 ) ) ) {
V_29 = F_55 ( V_81 , V_80 -> V_57 ,
V_86 ) ;
if ( F_56 ( V_29 , L_4 ) )
return V_29 ;
}
if ( F_53 ( V_60 -> V_55 & ( V_60 -> V_55 - 1 ) ) ) {
F_12 ( L_5
L_6
L_7 ,
V_25 , V_60 -> V_82 ,
( int ) V_60 -> V_64 ,
V_60 -> V_87 ,
V_60 -> V_55 ) ;
return - V_36 ;
}
if ( F_53 ( ( V_60 -> V_55 | V_60 -> V_87 )
& ~ V_88 ) ) {
F_12 ( L_8
L_6
L_7 ,
V_25 , V_60 -> V_82 ,
( int ) V_60 -> V_64 ,
V_60 -> V_87 ,
V_60 -> V_55 ) ;
return - V_36 ;
}
V_79 -> V_89 |= V_60 -> V_87 ;
V_79 -> V_90 |= V_60 -> V_55 ;
if ( V_61 == V_60 -> V_91 )
return 0 ;
if ( F_53 ( V_60 -> V_64 >
V_25 -> V_37 . V_6 - ( F_39 ( V_54 ) -> V_68 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_9
L_10 ,
V_25 , V_60 -> V_82 ,
( int ) V_60 -> V_64 ,
( int ) V_25 -> V_37 . V_6 ) ;
return - V_36 ;
}
if ( F_53 ( V_60 -> V_64 & 3 ) ) {
F_12 ( L_11
L_12 ,
V_25 , V_60 -> V_82 ,
( int ) V_60 -> V_64 ) ;
return - V_36 ;
}
if ( V_25 -> V_92 && F_57 () )
return - V_93 ;
if ( F_31 ( V_25 ) )
V_29 = F_33 ( V_25 , V_60 , V_61 ) ;
else if ( V_25 -> V_94 )
V_29 = F_42 ( V_25 , V_60 , V_61 ) ;
else if ( V_95 )
V_29 = F_51 ( V_25 , V_60 , V_61 ) ;
else {
F_56 ( 1 , L_13 ) ;
V_29 = - V_96 ;
}
if ( V_29 )
return V_29 ;
V_60 -> V_91 = V_61 ;
return 0 ;
}
static int
F_58 ( struct V_8 * V_38 ,
struct V_1 * V_3 )
{
#define F_59 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_59 V_97 [ F_59 ( 512 ) ] ;
struct V_59 T_5 * V_98 ;
struct V_18 * V_47 = V_38 -> V_40 ;
int V_99 , V_29 ;
V_98 = F_60 ( V_47 -> V_100 ) ;
V_99 = V_47 -> V_101 ;
while ( V_99 ) {
struct V_59 * V_102 = V_97 ;
int V_12 = V_99 ;
if ( V_12 > F_61 ( V_97 ) )
V_12 = F_61 ( V_97 ) ;
V_99 -= V_12 ;
if ( F_62 ( V_102 , V_98 , V_12 * sizeof( V_102 [ 0 ] ) ) )
return - V_93 ;
do {
T_6 V_64 = V_102 -> V_91 ;
V_29 = F_52 ( V_38 -> V_25 , V_3 , V_102 ) ;
if ( V_29 )
return V_29 ;
if ( V_102 -> V_91 != V_64 &&
F_63 ( & V_98 -> V_91 ,
& V_102 -> V_91 ,
sizeof( V_102 -> V_91 ) ) ) {
return - V_93 ;
}
V_98 ++ ;
V_102 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_59
}
static int
F_64 ( struct V_8 * V_38 ,
struct V_1 * V_3 ,
struct V_59 * V_103 )
{
const struct V_18 * V_47 = V_38 -> V_40 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_47 -> V_101 ; V_28 ++ ) {
V_29 = F_52 ( V_38 -> V_25 , V_3 , & V_103 [ V_28 ] ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static int
F_65 ( struct V_1 * V_3 )
{
struct V_8 * V_38 ;
int V_29 = 0 ;
F_66 () ;
F_67 (vma, &eb->vmas, exec_list) {
V_29 = F_58 ( V_38 , V_3 ) ;
if ( V_29 )
break;
}
F_68 () ;
return V_29 ;
}
static bool F_69 ( unsigned int V_4 )
{
return ( V_4 & ( V_104 | V_105 ) ) ==
V_105 ;
}
static int
F_70 ( struct V_8 * V_38 ,
struct V_106 * V_107 ,
bool * V_108 )
{
struct V_24 * V_25 = V_38 -> V_25 ;
struct V_18 * V_47 = V_38 -> V_40 ;
T_2 V_4 ;
int V_29 ;
V_4 = 0 ;
if ( ! F_27 ( & V_38 -> V_46 ) ) {
if ( V_47 -> V_4 & V_105 )
V_4 |= V_109 | V_110 ;
if ( V_47 -> V_4 & V_111 )
V_4 |= V_109 ;
if ( V_47 -> V_4 & V_112 )
V_4 |= V_113 | V_114 ;
}
V_29 = F_71 ( V_25 , V_38 -> V_21 , V_47 -> V_115 , V_4 ) ;
if ( ( V_29 == - V_116 || V_29 == - V_117 ) &&
F_69 ( V_47 -> V_4 ) )
V_29 = F_71 ( V_25 , V_38 -> V_21 ,
V_47 -> V_115 ,
V_4 & ~ ( V_109 | V_110 ) ) ;
if ( V_29 )
return V_29 ;
V_47 -> V_4 |= V_49 ;
if ( V_47 -> V_4 & V_104 ) {
V_29 = F_72 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_73 ( V_25 ) )
V_47 -> V_4 |= V_48 ;
}
if ( V_47 -> V_64 != V_38 -> V_46 . V_83 ) {
V_47 -> V_64 = V_38 -> V_46 . V_83 ;
* V_108 = true ;
}
if ( V_47 -> V_4 & V_118 ) {
V_25 -> V_37 . V_89 = V_119 ;
V_25 -> V_37 . V_90 = V_119 ;
}
return 0 ;
}
static bool
F_74 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
if ( V_47 -> V_101 == 0 )
return false ;
if ( ! F_75 ( V_38 -> V_21 ) )
return false ;
if ( F_32 ( V_38 -> V_25 -> V_37 . V_54 ) )
return false ;
if ( V_38 -> V_25 -> V_37 . V_55 == V_56 )
return false ;
return true ;
}
static bool
F_76 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
F_77 ( V_47 -> V_4 & V_105 &&
! F_75 ( V_38 -> V_21 ) ) ;
if ( V_47 -> V_115 &&
V_38 -> V_46 . V_83 & ( V_47 -> V_115 - 1 ) )
return true ;
if ( V_47 -> V_4 & V_112 &&
V_38 -> V_46 . V_83 < V_113 )
return true ;
if ( V_47 -> V_4 & V_105 && ! V_25 -> V_94 )
return ! F_69 ( V_47 -> V_4 ) ;
return false ;
}
static int
F_78 ( struct V_106 * V_107 ,
struct V_26 * V_16 ,
bool * V_120 )
{
struct V_24 * V_25 ;
struct V_8 * V_38 ;
struct V_20 * V_21 ;
struct V_26 V_121 ;
bool V_122 = F_39 ( V_107 -> V_54 ) -> V_68 < 4 ;
int V_123 ;
F_79 ( V_107 ) ;
V_21 = F_16 ( V_16 , struct V_8 , V_39 ) -> V_21 ;
F_5 ( & V_121 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_47 ;
bool V_124 , V_125 ;
V_38 = F_16 ( V_16 , struct V_8 , V_39 ) ;
V_25 = V_38 -> V_25 ;
V_47 = V_38 -> V_40 ;
if ( ! V_122 )
V_47 -> V_4 &= ~ V_104 ;
V_124 =
V_47 -> V_4 & V_104 &&
V_25 -> V_126 != V_127 ;
V_125 = V_124 || F_74 ( V_38 ) ;
if ( V_125 ) {
V_47 -> V_4 |= V_105 ;
F_80 ( & V_38 -> V_39 , & V_121 ) ;
} else
F_81 ( & V_38 -> V_39 , & V_121 ) ;
V_25 -> V_37 . V_89 = V_88 & ~ V_128 ;
V_25 -> V_37 . V_90 = 0 ;
}
F_82 ( & V_121 , V_16 ) ;
V_123 = 0 ;
do {
int V_29 = 0 ;
F_67 (vma, vmas, exec_list) {
if ( ! F_27 ( & V_38 -> V_46 ) )
continue;
if ( F_76 ( V_38 ) )
V_29 = F_83 ( V_38 ) ;
else
V_29 = F_70 ( V_38 , V_107 , V_120 ) ;
if ( V_29 )
goto V_34;
}
F_67 (vma, vmas, exec_list) {
if ( F_27 ( & V_38 -> V_46 ) )
continue;
V_29 = F_70 ( V_38 , V_107 , V_120 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_116 || V_123 ++ )
return V_29 ;
F_67 (vma, vmas, exec_list)
F_26 ( V_38 ) ;
V_29 = F_84 ( V_21 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_85 ( struct V_62 * V_54 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_106 * V_107 ,
struct V_1 * V_3 ,
struct V_18 * V_19 )
{
struct V_59 * V_60 ;
struct V_20 * V_21 ;
struct V_8 * V_38 ;
bool V_120 ;
int * V_129 ;
int V_28 , V_130 , V_29 ;
unsigned V_12 = args -> V_7 ;
V_21 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) -> V_21 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_38 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_86 ( & V_54 -> V_131 ) ;
V_130 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
V_130 += V_19 [ V_28 ] . V_101 ;
V_129 = F_87 ( V_12 , sizeof( * V_129 ) ) ;
V_60 = F_87 ( V_130 , sizeof( * V_60 ) ) ;
if ( V_60 == NULL || V_129 == NULL ) {
F_88 ( V_60 ) ;
F_88 ( V_129 ) ;
F_89 ( & V_54 -> V_131 ) ;
return - V_132 ;
}
V_130 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
struct V_59 T_5 * V_98 ;
T_6 V_133 = ( T_6 ) - 1 ;
int V_134 ;
V_98 = F_60 ( V_19 [ V_28 ] . V_100 ) ;
if ( F_90 ( V_60 + V_130 , V_98 ,
V_19 [ V_28 ] . V_101 * sizeof( * V_60 ) ) ) {
V_29 = - V_93 ;
F_89 ( & V_54 -> V_131 ) ;
goto V_34;
}
for ( V_134 = 0 ; V_134 < V_19 [ V_28 ] . V_101 ; V_134 ++ ) {
if ( F_91 ( & V_98 [ V_134 ] . V_91 ,
& V_133 ,
sizeof( V_133 ) ) ) {
V_29 = - V_93 ;
F_89 ( & V_54 -> V_131 ) ;
goto V_34;
}
}
V_129 [ V_28 ] = V_130 ;
V_130 += V_19 [ V_28 ] . V_101 ;
}
V_29 = F_92 ( V_54 ) ;
if ( V_29 ) {
F_89 ( & V_54 -> V_131 ) ;
goto V_34;
}
F_6 ( V_3 ) ;
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_120 = ( args -> V_4 & V_135 ) == 0 ;
V_29 = F_78 ( V_107 , & V_3 -> V_16 , & V_120 ) ;
if ( V_29 )
goto V_34;
F_67 (vma, &eb->vmas, exec_list) {
int V_64 = V_38 -> V_40 - V_19 ;
V_29 = F_64 ( V_38 , V_3 ,
V_60 + V_129 [ V_64 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_88 ( V_60 ) ;
F_88 ( V_129 ) ;
return V_29 ;
}
static int
F_93 ( struct V_106 * V_107 ,
struct V_26 * V_16 )
{
struct V_8 * V_38 ;
T_1 V_136 = 0 ;
bool V_137 = false ;
int V_29 ;
F_67 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
V_29 = F_94 ( V_25 , V_107 ) ;
if ( V_29 )
return V_29 ;
if ( V_25 -> V_37 . V_55 & V_56 )
V_137 |= F_95 ( V_25 , false ) ;
V_136 |= V_25 -> V_37 . V_55 ;
}
if ( V_137 )
F_96 ( V_107 -> V_54 ) ;
if ( V_136 & V_138 )
F_97 () ;
return F_98 ( V_107 ) ;
}
static bool
F_99 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_139 )
return false ;
return ( ( V_19 -> V_140 | V_19 -> V_141 ) & 0x7 ) == 0 ;
}
static int
F_100 ( struct V_62 * V_54 ,
struct V_18 * V_19 ,
int V_12 )
{
unsigned V_142 = 0 ;
unsigned V_143 = V_144 / sizeof( struct V_59 ) ;
unsigned V_145 ;
int V_28 ;
V_145 = V_146 ;
if ( F_101 ( V_54 ) )
V_145 |= V_111 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
char T_5 * V_147 = F_60 ( V_19 [ V_28 ] . V_100 ) ;
int V_148 ;
if ( V_19 [ V_28 ] . V_4 & V_145 )
return - V_36 ;
if ( V_19 [ V_28 ] . V_101 > V_143 - V_142 )
return - V_36 ;
V_142 += V_19 [ V_28 ] . V_101 ;
V_148 = V_19 [ V_28 ] . V_101 *
sizeof( struct V_59 ) ;
if ( ! F_102 ( V_149 , V_147 , V_148 ) )
return - V_93 ;
if ( F_103 ( ! V_150 . V_151 ) ) {
if ( F_104 ( V_147 , V_148 ) )
return - V_93 ;
}
}
return 0 ;
}
static struct V_152 *
F_105 ( struct V_62 * V_54 , struct V_22 * V_23 ,
struct V_106 * V_107 , const T_7 V_153 )
{
struct V_152 * V_154 = NULL ;
struct V_155 * V_156 ;
if ( V_107 -> V_157 != V_158 && V_153 != V_159 )
return F_106 ( - V_36 ) ;
V_154 = F_107 ( V_23 -> V_160 , V_153 ) ;
if ( F_18 ( V_154 ) )
return V_154 ;
V_156 = & V_154 -> V_161 ;
if ( V_156 -> V_162 ) {
F_12 ( L_14 , V_153 ) ;
return F_106 ( - V_163 ) ;
}
if ( V_150 . V_164 && ! V_154 -> V_165 [ V_107 -> V_157 ] . V_166 ) {
int V_29 = F_108 ( V_154 , V_107 ) ;
if ( V_29 ) {
F_12 ( L_15 , V_153 , V_29 ) ;
return F_106 ( V_29 ) ;
}
}
return V_154 ;
}
void
F_109 ( struct V_26 * V_16 ,
struct V_106 * V_107 )
{
struct V_167 * V_168 = F_110 ( V_107 ) ;
struct V_8 * V_38 ;
F_67 (vma, vmas, exec_list) {
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
T_7 V_169 = V_25 -> V_37 . V_87 ;
T_7 V_170 = V_25 -> V_37 . V_55 ;
V_25 -> V_37 . V_55 = V_25 -> V_37 . V_90 ;
if ( V_25 -> V_37 . V_55 == 0 )
V_25 -> V_37 . V_89 |= V_25 -> V_37 . V_87 ;
V_25 -> V_37 . V_87 = V_25 -> V_37 . V_89 ;
F_111 ( V_38 , V_107 ) ;
if ( V_25 -> V_37 . V_55 ) {
V_25 -> V_171 = 1 ;
F_112 ( & V_25 -> V_172 , V_168 ) ;
F_113 ( V_25 , V_107 , V_173 ) ;
V_25 -> V_37 . V_55 &= ~ V_88 ;
}
if ( V_47 -> V_4 & V_104 ) {
F_112 ( & V_25 -> V_174 , V_168 ) ;
if ( V_47 -> V_4 & V_48 ) {
struct V_69 * V_70 = F_114 ( V_107 -> V_54 ) ;
F_81 ( & V_70 -> V_175 [ V_25 -> V_176 ] . V_177 ,
& V_70 -> V_178 . V_179 ) ;
}
}
F_115 ( V_25 , V_169 , V_170 ) ;
}
}
void
F_116 ( struct V_62 * V_54 ,
struct V_22 * V_23 ,
struct V_106 * V_107 ,
struct V_24 * V_25 )
{
V_107 -> V_180 = true ;
( void ) F_117 ( V_107 , V_23 , V_25 ) ;
}
static int
F_118 ( struct V_62 * V_54 ,
struct V_106 * V_107 )
{
struct V_69 * V_70 = V_54 -> V_71 ;
int V_29 , V_28 ;
if ( ! F_119 ( V_54 ) || V_107 != & V_70 -> V_107 [ V_158 ] ) {
F_12 ( L_16 ) ;
return - V_36 ;
}
V_29 = F_120 ( V_107 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_121 ( V_107 , F_122 ( 1 ) ) ;
F_121 ( V_107 , F_123 ( V_28 ) ) ;
F_121 ( V_107 , 0 ) ;
}
F_124 ( V_107 ) ;
return 0 ;
}
static int
F_125 ( struct V_106 * V_107 ,
struct V_181 * V_182 ,
int V_183 , int V_184 )
{
int V_29 ;
if ( V_182 -> V_185 <= V_182 -> y1 || V_182 -> V_186 <= V_182 -> V_187 ||
V_182 -> V_185 <= 0 || V_182 -> V_186 <= 0 ) {
F_126 ( L_17 ,
V_182 -> V_187 , V_182 -> y1 , V_182 -> V_186 , V_182 -> V_185 ) ;
return - V_36 ;
}
if ( F_39 ( V_107 -> V_54 ) -> V_68 >= 4 ) {
V_29 = F_120 ( V_107 , 4 ) ;
if ( V_29 )
return V_29 ;
F_121 ( V_107 , V_188 ) ;
F_121 ( V_107 , ( V_182 -> V_187 & 0xffff ) | V_182 -> y1 << 16 ) ;
F_121 ( V_107 , ( ( V_182 -> V_186 - 1 ) & 0xffff ) | ( V_182 -> V_185 - 1 ) << 16 ) ;
F_121 ( V_107 , V_184 ) ;
} else {
V_29 = F_120 ( V_107 , 6 ) ;
if ( V_29 )
return V_29 ;
F_121 ( V_107 , V_189 ) ;
F_121 ( V_107 , V_183 ) ;
F_121 ( V_107 , ( V_182 -> V_187 & 0xffff ) | V_182 -> y1 << 16 ) ;
F_121 ( V_107 , ( ( V_182 -> V_186 - 1 ) & 0xffff ) | ( V_182 -> V_185 - 1 ) << 16 ) ;
F_121 ( V_107 , V_184 ) ;
F_121 ( V_107 , 0 ) ;
}
F_124 ( V_107 ) ;
return 0 ;
}
static struct V_24 *
F_127 ( struct V_106 * V_107 ,
struct V_18 * V_190 ,
struct V_1 * V_3 ,
struct V_24 * V_191 ,
T_7 V_140 ,
T_7 V_141 ,
bool V_192 )
{
struct V_69 * V_70 = F_114 ( V_191 -> V_37 . V_54 ) ;
struct V_24 * V_193 ;
struct V_8 * V_38 ;
int V_29 ;
V_193 = F_128 ( & V_70 -> V_178 . V_194 ,
F_129 ( V_141 ) ) ;
if ( F_18 ( V_193 ) )
return V_193 ;
V_29 = F_130 ( V_107 ,
V_191 ,
V_193 ,
V_140 ,
V_141 ,
V_192 ) ;
if ( V_29 )
goto V_34;
V_29 = F_131 ( V_193 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
memset ( V_190 , 0 , sizeof( * V_190 ) ) ;
V_38 = F_132 ( V_193 ) ;
V_38 -> V_40 = V_190 ;
V_38 -> V_40 -> V_4 = V_51 | V_49 ;
F_14 ( & V_193 -> V_37 ) ;
F_15 ( & V_38 -> V_39 , & V_3 -> V_16 ) ;
V_193 -> V_37 . V_89 = V_128 ;
return V_193 ;
V_34:
if ( V_29 == - V_195 )
return V_191 ;
else
return F_106 ( V_29 ) ;
}
int
F_133 ( struct V_62 * V_54 , struct V_22 * V_23 ,
struct V_106 * V_107 ,
struct V_152 * V_154 ,
struct V_2 * args ,
struct V_26 * V_16 ,
struct V_24 * V_191 ,
T_6 V_196 , T_7 V_197 )
{
struct V_181 * V_198 = NULL ;
struct V_69 * V_70 = V_54 -> V_71 ;
T_6 V_199 ;
int V_200 ;
T_7 V_201 ;
int V_28 , V_29 = 0 ;
if ( args -> V_202 != 0 ) {
if ( V_107 != & V_70 -> V_107 [ V_158 ] ) {
F_12 ( L_18 ) ;
return - V_36 ;
}
if ( F_39 ( V_54 ) -> V_68 >= 5 ) {
F_12 ( L_19 ) ;
return - V_36 ;
}
if ( args -> V_202 > V_144 / sizeof( * V_198 ) ) {
F_12 ( L_20 ,
args -> V_202 ) ;
return - V_36 ;
}
V_198 = F_134 ( args -> V_202 ,
sizeof( * V_198 ) ,
V_203 ) ;
if ( V_198 == NULL ) {
V_29 = - V_132 ;
goto error;
}
if ( F_90 ( V_198 ,
F_60 ( args -> V_204 ) ,
sizeof( * V_198 ) * args -> V_202 ) ) {
V_29 = - V_93 ;
goto error;
}
} else {
if ( args -> V_184 == 0xffffffff ) {
F_12 ( L_21 ) ;
args -> V_184 = 0 ;
}
if ( args -> V_183 || args -> V_184 || args -> V_204 ) {
F_12 ( L_22 ) ;
return - V_36 ;
}
}
V_29 = F_93 ( V_107 , V_16 ) ;
if ( V_29 )
goto error;
V_29 = F_135 ( V_107 , V_154 ) ;
if ( V_29 )
goto error;
if ( V_154 -> V_205 )
F_136 ( V_154 -> V_205 -> V_206 & ( 1 << V_107 -> V_157 ) ,
L_23 , V_107 -> V_207 ) ;
else if ( V_70 -> V_178 . V_208 )
F_136 ( V_70 -> V_178 . V_208 -> V_206 &
( 1 << V_107 -> V_157 ) , L_23 , V_107 -> V_207 ) ;
V_200 = args -> V_4 & V_209 ;
V_201 = V_209 ;
switch ( V_200 ) {
case V_210 :
case V_211 :
case V_212 :
if ( V_200 != 0 && V_107 != & V_70 -> V_107 [ V_158 ] ) {
F_12 ( L_24 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_200 != V_70 -> V_213 ) {
if ( F_39 ( V_54 ) -> V_68 < 4 ) {
F_12 ( L_25 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_54 ) -> V_68 > 5 &&
V_200 == V_212 ) {
F_12 ( L_26 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_54 ) -> V_68 >= 6 )
V_201 &= ~ V_212 ;
}
break;
default:
F_12 ( L_27 , V_200 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_107 == & V_70 -> V_107 [ V_158 ] &&
V_200 != V_70 -> V_213 ) {
V_29 = F_120 ( V_107 , 4 ) ;
if ( V_29 )
goto error;
F_121 ( V_107 , V_214 ) ;
F_121 ( V_107 , F_122 ( 1 ) ) ;
F_121 ( V_107 , V_215 ) ;
F_121 ( V_107 , V_201 << 16 | V_200 ) ;
F_124 ( V_107 ) ;
V_70 -> V_213 = V_200 ;
}
if ( args -> V_4 & V_216 ) {
V_29 = F_118 ( V_54 , V_107 ) ;
if ( V_29 )
goto error;
}
V_199 = args -> V_141 ;
if ( V_198 ) {
for ( V_28 = 0 ; V_28 < args -> V_202 ; V_28 ++ ) {
V_29 = F_125 ( V_107 , & V_198 [ V_28 ] ,
args -> V_183 , args -> V_184 ) ;
if ( V_29 )
goto error;
V_29 = V_107 -> V_217 ( V_107 ,
V_196 , V_199 ,
V_197 ) ;
if ( V_29 )
goto error;
}
} else {
V_29 = V_107 -> V_217 ( V_107 ,
V_196 , V_199 ,
V_197 ) ;
if ( V_29 )
return V_29 ;
}
F_137 ( F_110 ( V_107 ) , V_197 ) ;
F_109 ( V_16 , V_107 ) ;
F_116 ( V_54 , V_23 , V_107 , V_191 ) ;
error:
F_30 ( V_198 ) ;
return V_29 ;
}
static int F_138 ( struct V_62 * V_54 ,
struct V_22 * V_23 )
{
struct V_69 * V_70 = V_54 -> V_71 ;
struct V_218 * V_219 = V_23 -> V_160 ;
if ( V_219 -> V_220 )
return V_219 -> V_220 -> V_157 ;
else {
int V_221 ;
F_89 ( & V_54 -> V_131 ) ;
if ( V_70 -> V_178 . V_222 == 0 ) {
V_221 = V_223 ;
V_70 -> V_178 . V_222 = 1 ;
} else {
V_221 = V_224 ;
V_70 -> V_178 . V_222 = 0 ;
}
V_219 -> V_220 = & V_70 -> V_107 [ V_221 ] ;
F_86 ( & V_54 -> V_131 ) ;
return V_221 ;
}
}
static struct V_24 *
F_139 ( struct V_1 * V_3 )
{
struct V_8 * V_38 = F_140 ( V_3 -> V_16 . V_225 , F_141 ( * V_38 ) , V_39 ) ;
V_38 -> V_40 -> V_4 |= V_112 ;
return V_38 -> V_25 ;
}
static int
F_142 ( struct V_62 * V_54 , void * V_226 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_69 * V_70 = V_54 -> V_71 ;
struct V_1 * V_3 ;
struct V_24 * V_191 ;
struct V_18 V_190 ;
struct V_106 * V_107 ;
struct V_152 * V_154 ;
struct V_20 * V_21 ;
const T_7 V_153 = F_143 ( * args ) ;
T_6 V_196 = args -> V_140 ;
T_7 V_197 ;
int V_29 ;
bool V_120 ;
if ( ! F_99 ( args ) )
return - V_36 ;
V_29 = F_100 ( V_54 , V_19 , args -> V_7 ) ;
if ( V_29 )
return V_29 ;
V_197 = 0 ;
if ( args -> V_4 & V_227 ) {
if ( ! V_23 -> V_192 || ! F_144 ( V_228 ) )
return - V_229 ;
V_197 |= V_230 ;
}
if ( args -> V_4 & V_231 )
V_197 |= V_232 ;
if ( ( args -> V_4 & V_233 ) > V_234 ) {
F_12 ( L_28 ,
( int ) ( args -> V_4 & V_233 ) ) ;
return - V_36 ;
}
if ( ( ( args -> V_4 & V_233 ) != V_235 ) &&
( ( args -> V_4 & V_236 ) != 0 ) ) {
F_12 ( L_29
L_30 , ( int ) ( args -> V_4 ) ) ;
return - V_36 ;
}
if ( ( args -> V_4 & V_233 ) == V_237 )
V_107 = & V_70 -> V_107 [ V_158 ] ;
else if ( ( args -> V_4 & V_233 ) == V_235 ) {
if ( F_145 ( V_54 ) ) {
int V_221 ;
switch ( args -> V_4 & V_236 ) {
case V_238 :
V_221 = F_138 ( V_54 , V_23 ) ;
V_107 = & V_70 -> V_107 [ V_221 ] ;
break;
case V_239 :
V_107 = & V_70 -> V_107 [ V_223 ] ;
break;
case V_240 :
V_107 = & V_70 -> V_107 [ V_224 ] ;
break;
default:
F_12 ( L_31 ,
( int ) ( args -> V_4 & V_236 ) ) ;
return - V_36 ;
}
} else
V_107 = & V_70 -> V_107 [ V_223 ] ;
} else
V_107 = & V_70 -> V_107 [ ( args -> V_4 & V_233 ) - 1 ] ;
if ( ! F_146 ( V_107 ) ) {
F_12 ( L_32 ,
( int ) ( args -> V_4 & V_233 ) ) ;
return - V_36 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_33 , args -> V_7 ) ;
return - V_36 ;
}
F_147 ( V_70 ) ;
V_29 = F_92 ( V_54 ) ;
if ( V_29 )
goto V_241;
V_154 = F_105 ( V_54 , V_23 , V_107 , V_153 ) ;
if ( F_18 ( V_154 ) ) {
F_86 ( & V_54 -> V_131 ) ;
V_29 = F_19 ( V_154 ) ;
goto V_241;
}
F_148 ( V_154 ) ;
if ( V_154 -> V_205 )
V_21 = & V_154 -> V_205 -> V_37 ;
else
V_21 = & V_70 -> V_73 . V_37 ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_149 ( V_154 ) ;
F_86 ( & V_54 -> V_131 ) ;
V_29 = - V_132 ;
goto V_241;
}
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_191 = F_139 ( V_3 ) ;
V_120 = ( args -> V_4 & V_135 ) == 0 ;
V_29 = F_78 ( V_107 , & V_3 -> V_16 , & V_120 ) ;
if ( V_29 )
goto V_34;
if ( V_120 )
V_29 = F_65 ( V_3 ) ;
if ( V_29 ) {
if ( V_29 == - V_93 ) {
V_29 = F_85 ( V_54 , args , V_23 , V_107 ,
V_3 , V_19 ) ;
F_150 ( ! F_151 ( & V_54 -> V_131 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_191 -> V_37 . V_90 ) {
F_12 ( L_34 ) ;
V_29 = - V_36 ;
goto V_34;
}
if ( F_152 ( V_107 ) && args -> V_141 ) {
V_191 = F_127 ( V_107 ,
& V_190 ,
V_3 ,
V_191 ,
args -> V_140 ,
args -> V_141 ,
V_23 -> V_192 ) ;
if ( F_18 ( V_191 ) ) {
V_29 = F_19 ( V_191 ) ;
goto V_34;
}
if ( F_101 ( V_54 ) )
V_197 |= V_230 ;
V_196 = 0 ;
}
V_191 -> V_37 . V_89 |= V_128 ;
if ( V_197 & V_230 ) {
V_29 = F_131 ( V_191 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
V_196 += F_45 ( V_191 ) ;
} else
V_196 += F_153 ( V_191 , V_21 ) ;
V_29 = V_70 -> V_242 . V_243 ( V_54 , V_23 , V_107 , V_154 , args ,
& V_3 -> V_16 , V_191 , V_196 ,
V_197 ) ;
if ( V_197 & V_230 )
F_154 ( V_191 ) ;
V_34:
F_149 ( V_154 ) ;
F_29 ( V_3 ) ;
F_86 ( & V_54 -> V_131 ) ;
V_241:
F_155 ( V_70 ) ;
return V_29 ;
}
int
F_156 ( struct V_62 * V_54 , void * V_226 ,
struct V_22 * V_23 )
{
struct V_244 * args = V_226 ;
struct V_2 V_245 ;
struct V_246 * V_39 = NULL ;
struct V_18 * V_247 = NULL ;
int V_29 , V_28 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_33 , args -> V_7 ) ;
return - V_36 ;
}
V_39 = F_87 ( sizeof( * V_39 ) , args -> V_7 ) ;
V_247 = F_87 ( sizeof( * V_247 ) , args -> V_7 ) ;
if ( V_39 == NULL || V_247 == NULL ) {
F_12 ( L_35 ,
args -> V_7 ) ;
F_88 ( V_39 ) ;
F_88 ( V_247 ) ;
return - V_132 ;
}
V_29 = F_90 ( V_39 ,
F_60 ( args -> V_248 ) ,
sizeof( * V_39 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_36 ,
args -> V_7 , V_29 ) ;
F_88 ( V_39 ) ;
F_88 ( V_247 ) ;
return - V_93 ;
}
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_247 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_247 [ V_28 ] . V_101 = V_39 [ V_28 ] . V_101 ;
V_247 [ V_28 ] . V_100 = V_39 [ V_28 ] . V_100 ;
V_247 [ V_28 ] . V_115 = V_39 [ V_28 ] . V_115 ;
V_247 [ V_28 ] . V_64 = V_39 [ V_28 ] . V_64 ;
if ( F_39 ( V_54 ) -> V_68 < 4 )
V_247 [ V_28 ] . V_4 = V_104 ;
else
V_247 [ V_28 ] . V_4 = 0 ;
}
V_245 . V_248 = args -> V_248 ;
V_245 . V_7 = args -> V_7 ;
V_245 . V_140 = args -> V_140 ;
V_245 . V_141 = args -> V_141 ;
V_245 . V_183 = args -> V_183 ;
V_245 . V_184 = args -> V_184 ;
V_245 . V_202 = args -> V_202 ;
V_245 . V_204 = args -> V_204 ;
V_245 . V_4 = V_249 ;
F_157 ( V_245 , 0 ) ;
V_29 = F_142 ( V_54 , V_226 , V_23 , & V_245 , V_247 ) ;
if ( ! V_29 ) {
struct V_246 T_5 * V_250 =
F_60 ( args -> V_248 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_91 ( & V_250 [ V_28 ] . V_64 ,
& V_247 [ V_28 ] . V_64 ,
sizeof( V_250 [ V_28 ] . V_64 ) ) ;
if ( V_29 ) {
V_29 = - V_93 ;
F_12 ( L_37
L_38 ,
args -> V_7 , V_29 ) ;
break;
}
}
}
F_88 ( V_39 ) ;
F_88 ( V_247 ) ;
return V_29 ;
}
int
F_158 ( struct V_62 * V_54 , void * V_226 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_226 ;
struct V_18 * V_247 = NULL ;
int V_29 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_144 / sizeof( * V_247 ) ) {
F_12 ( L_39 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_251 != 0 ) {
F_12 ( L_40 ) ;
return - V_36 ;
}
V_247 = F_2 ( sizeof( * V_247 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_247 == NULL )
V_247 = F_87 ( sizeof( * V_247 ) ,
args -> V_7 ) ;
if ( V_247 == NULL ) {
F_12 ( L_35 ,
args -> V_7 ) ;
return - V_132 ;
}
V_29 = F_90 ( V_247 ,
F_60 ( args -> V_248 ) ,
sizeof( * V_247 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_36 ,
args -> V_7 , V_29 ) ;
F_88 ( V_247 ) ;
return - V_93 ;
}
V_29 = F_142 ( V_54 , V_226 , V_23 , args , V_247 ) ;
if ( ! V_29 ) {
struct V_18 T_5 * V_250 =
F_60 ( args -> V_248 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_91 ( & V_250 [ V_28 ] . V_64 ,
& V_247 [ V_28 ] . V_64 ,
sizeof( V_250 [ V_28 ] . V_64 ) ) ;
if ( V_29 ) {
V_29 = - V_93 ;
F_12 ( L_37
L_41 ,
args -> V_7 ) ;
break;
}
}
}
F_88 ( V_247 ) ;
return V_29 ;
}
