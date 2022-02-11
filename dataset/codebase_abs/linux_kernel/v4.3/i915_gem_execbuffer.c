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
static int
F_33 ( struct V_24 * V_25 ,
struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_59 * V_51 = V_25 -> V_37 . V_51 ;
T_1 V_60 = F_34 ( V_57 -> V_61 ) ;
T_2 V_62 = V_57 -> V_62 + V_58 ;
char * V_63 ;
int V_29 ;
V_29 = F_35 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_63 = F_36 ( F_37 ( V_25 ,
V_57 -> V_61 >> V_64 ) ) ;
* ( T_1 * ) ( V_63 + V_60 ) = F_38 ( V_62 ) ;
if ( F_39 ( V_51 ) -> V_65 >= 8 ) {
V_60 = F_34 ( V_60 + sizeof( T_1 ) ) ;
if ( V_60 == 0 ) {
F_40 ( V_63 ) ;
V_63 = F_36 ( F_37 ( V_25 ,
( V_57 -> V_61 + sizeof( T_1 ) ) >> V_64 ) ) ;
}
* ( T_1 * ) ( V_63 + V_60 ) = F_41 ( V_62 ) ;
}
F_40 ( V_63 ) ;
return 0 ;
}
static int
F_42 ( struct V_24 * V_25 ,
struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_59 * V_51 = V_25 -> V_37 . V_51 ;
struct V_66 * V_67 = V_51 -> V_68 ;
T_2 V_62 = V_57 -> V_62 + V_58 ;
T_2 V_61 ;
void T_3 * V_69 ;
int V_29 ;
V_29 = F_43 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_29 = F_44 ( V_25 ) ;
if ( V_29 )
return V_29 ;
V_61 = F_45 ( V_25 ) ;
V_61 += V_57 -> V_61 ;
V_69 = F_46 ( V_67 -> V_70 . V_71 ,
V_61 & V_72 ) ;
F_47 ( F_38 ( V_62 ) , V_69 + F_34 ( V_61 ) ) ;
if ( F_39 ( V_51 ) -> V_65 >= 8 ) {
V_61 += sizeof( T_1 ) ;
if ( F_34 ( V_61 ) == 0 ) {
F_48 ( V_69 ) ;
V_69 =
F_46 ( V_67 -> V_70 . V_71 ,
V_61 ) ;
}
F_47 ( F_41 ( V_62 ) ,
V_69 + F_34 ( V_61 ) ) ;
}
F_48 ( V_69 ) ;
return 0 ;
}
static void
F_49 ( void * V_73 , T_1 V_74 )
{
F_50 ( V_73 , sizeof( T_1 ) ) ;
* ( T_1 * ) V_73 = V_74 ;
F_50 ( V_73 , sizeof( T_1 ) ) ;
}
static int
F_51 ( struct V_24 * V_25 ,
struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_59 * V_51 = V_25 -> V_37 . V_51 ;
T_1 V_60 = F_34 ( V_57 -> V_61 ) ;
T_2 V_62 = ( int ) V_57 -> V_62 + V_58 ;
char * V_63 ;
int V_29 ;
V_29 = F_43 ( V_25 , true ) ;
if ( V_29 )
return V_29 ;
V_63 = F_36 ( F_37 ( V_25 ,
V_57 -> V_61 >> V_64 ) ) ;
F_49 ( V_63 + V_60 , F_38 ( V_62 ) ) ;
if ( F_39 ( V_51 ) -> V_65 >= 8 ) {
V_60 = F_34 ( V_60 + sizeof( T_1 ) ) ;
if ( V_60 == 0 ) {
F_40 ( V_63 ) ;
V_63 = F_36 ( F_37 ( V_25 ,
( V_57 -> V_61 + sizeof( T_1 ) ) >> V_64 ) ) ;
}
F_49 ( V_63 + V_60 , F_41 ( V_62 ) ) ;
}
F_40 ( V_63 ) ;
return 0 ;
}
static int
F_52 ( struct V_24 * V_25 ,
struct V_1 * V_3 ,
struct V_56 * V_57 )
{
struct V_59 * V_51 = V_25 -> V_37 . V_51 ;
struct V_75 * V_76 ;
struct V_24 * V_77 ;
struct V_8 * V_78 ;
T_2 V_58 ;
int V_29 ;
V_78 = F_23 ( V_3 , V_57 -> V_79 ) ;
if ( F_53 ( V_78 == NULL ) )
return - V_33 ;
V_77 = V_78 -> V_25 ;
V_76 = & V_78 -> V_25 -> V_37 ;
V_58 = V_78 -> V_46 . V_80 ;
if ( F_53 ( F_54 ( V_51 ) &&
V_57 -> V_52 == V_81 ) ) {
V_29 = F_55 ( V_78 , V_77 -> V_54 ,
V_82 ) ;
if ( F_56 ( V_29 , L_4 ) )
return V_29 ;
}
if ( F_53 ( V_57 -> V_52 & ( V_57 -> V_52 - 1 ) ) ) {
F_12 ( L_5
L_6
L_7 ,
V_25 , V_57 -> V_79 ,
( int ) V_57 -> V_61 ,
V_57 -> V_83 ,
V_57 -> V_52 ) ;
return - V_36 ;
}
if ( F_53 ( ( V_57 -> V_52 | V_57 -> V_83 )
& ~ V_84 ) ) {
F_12 ( L_8
L_6
L_7 ,
V_25 , V_57 -> V_79 ,
( int ) V_57 -> V_61 ,
V_57 -> V_83 ,
V_57 -> V_52 ) ;
return - V_36 ;
}
V_76 -> V_85 |= V_57 -> V_83 ;
V_76 -> V_86 |= V_57 -> V_52 ;
if ( V_58 == V_57 -> V_87 )
return 0 ;
if ( F_53 ( V_57 -> V_61 >
V_25 -> V_37 . V_6 - ( F_39 ( V_51 ) -> V_65 >= 8 ? 8 : 4 ) ) ) {
F_12 ( L_9
L_10 ,
V_25 , V_57 -> V_79 ,
( int ) V_57 -> V_61 ,
( int ) V_25 -> V_37 . V_6 ) ;
return - V_36 ;
}
if ( F_53 ( V_57 -> V_61 & 3 ) ) {
F_12 ( L_11
L_12 ,
V_25 , V_57 -> V_79 ,
( int ) V_57 -> V_61 ) ;
return - V_36 ;
}
if ( V_25 -> V_88 && F_57 () )
return - V_89 ;
if ( F_31 ( V_25 ) )
V_29 = F_33 ( V_25 , V_57 , V_58 ) ;
else if ( V_25 -> V_90 )
V_29 = F_42 ( V_25 , V_57 , V_58 ) ;
else if ( V_91 )
V_29 = F_51 ( V_25 , V_57 , V_58 ) ;
else {
F_56 ( 1 , L_13 ) ;
V_29 = - V_92 ;
}
if ( V_29 )
return V_29 ;
V_57 -> V_87 = V_58 ;
return 0 ;
}
static int
F_58 ( struct V_8 * V_38 ,
struct V_1 * V_3 )
{
#define F_59 ( T_4 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_56 V_93 [ F_59 ( 512 ) ] ;
struct V_56 T_5 * V_94 ;
struct V_18 * V_47 = V_38 -> V_40 ;
int V_95 , V_29 ;
V_94 = F_60 ( V_47 -> V_96 ) ;
V_95 = V_47 -> V_97 ;
while ( V_95 ) {
struct V_56 * V_98 = V_93 ;
int V_12 = V_95 ;
if ( V_12 > F_61 ( V_93 ) )
V_12 = F_61 ( V_93 ) ;
V_95 -= V_12 ;
if ( F_62 ( V_98 , V_94 , V_12 * sizeof( V_98 [ 0 ] ) ) )
return - V_89 ;
do {
T_6 V_61 = V_98 -> V_87 ;
V_29 = F_52 ( V_38 -> V_25 , V_3 , V_98 ) ;
if ( V_29 )
return V_29 ;
if ( V_98 -> V_87 != V_61 &&
F_63 ( & V_94 -> V_87 ,
& V_98 -> V_87 ,
sizeof( V_98 -> V_87 ) ) ) {
return - V_89 ;
}
V_94 ++ ;
V_98 ++ ;
} while ( -- V_12 );
}
return 0 ;
#undef F_59
}
static int
F_64 ( struct V_8 * V_38 ,
struct V_1 * V_3 ,
struct V_56 * V_99 )
{
const struct V_18 * V_47 = V_38 -> V_40 ;
int V_28 , V_29 ;
for ( V_28 = 0 ; V_28 < V_47 -> V_97 ; V_28 ++ ) {
V_29 = F_52 ( V_38 -> V_25 , V_3 , & V_99 [ V_28 ] ) ;
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
return ( V_4 & ( V_100 | V_101 ) ) ==
V_101 ;
}
static int
F_70 ( struct V_8 * V_38 ,
struct V_102 * V_103 ,
bool * V_104 )
{
struct V_24 * V_25 = V_38 -> V_25 ;
struct V_18 * V_47 = V_38 -> V_40 ;
T_2 V_4 ;
int V_29 ;
V_4 = V_105 ;
if ( V_47 -> V_4 & V_106 )
V_4 |= V_82 ;
if ( ! F_27 ( & V_38 -> V_46 ) ) {
if ( V_47 -> V_4 & V_101 )
V_4 |= V_82 | V_107 ;
if ( V_47 -> V_4 & V_108 )
V_4 |= V_109 | V_110 ;
}
V_29 = F_71 ( V_25 , V_38 -> V_21 , V_47 -> V_111 , V_4 ) ;
if ( ( V_29 == - V_112 || V_29 == - V_113 ) &&
F_69 ( V_47 -> V_4 ) )
V_29 = F_71 ( V_25 , V_38 -> V_21 ,
V_47 -> V_111 ,
V_4 & ~ V_107 ) ;
if ( V_29 )
return V_29 ;
V_47 -> V_4 |= V_49 ;
if ( V_47 -> V_4 & V_100 ) {
V_29 = F_72 ( V_25 ) ;
if ( V_29 )
return V_29 ;
if ( F_73 ( V_25 ) )
V_47 -> V_4 |= V_48 ;
}
if ( V_47 -> V_61 != V_38 -> V_46 . V_80 ) {
V_47 -> V_61 = V_38 -> V_46 . V_80 ;
* V_104 = true ;
}
if ( V_47 -> V_4 & V_114 ) {
V_25 -> V_37 . V_85 = V_115 ;
V_25 -> V_37 . V_86 = V_115 ;
}
return 0 ;
}
static bool
F_74 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
if ( V_47 -> V_97 == 0 )
return false ;
if ( ! F_75 ( V_38 -> V_21 ) )
return false ;
if ( F_32 ( V_38 -> V_25 -> V_37 . V_51 ) )
return false ;
if ( V_38 -> V_25 -> V_37 . V_52 == V_53 )
return false ;
return true ;
}
static bool
F_76 ( struct V_8 * V_38 )
{
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
F_77 ( V_47 -> V_4 & V_101 &&
! F_75 ( V_38 -> V_21 ) ) ;
if ( V_47 -> V_111 &&
V_38 -> V_46 . V_80 & ( V_47 -> V_111 - 1 ) )
return true ;
if ( V_47 -> V_4 & V_108 &&
V_38 -> V_46 . V_80 < V_109 )
return true ;
if ( V_47 -> V_4 & V_101 && ! V_25 -> V_90 )
return ! F_69 ( V_47 -> V_4 ) ;
return false ;
}
static int
F_78 ( struct V_102 * V_103 ,
struct V_26 * V_16 ,
struct V_116 * V_117 ,
bool * V_118 )
{
struct V_24 * V_25 ;
struct V_8 * V_38 ;
struct V_20 * V_21 ;
struct V_26 V_119 ;
bool V_120 = F_39 ( V_103 -> V_51 ) -> V_65 < 4 ;
int V_121 ;
F_79 ( V_103 ) ;
V_21 = F_16 ( V_16 , struct V_8 , V_39 ) -> V_21 ;
F_5 ( & V_119 ) ;
while ( ! F_13 ( V_16 ) ) {
struct V_18 * V_47 ;
bool V_122 , V_123 ;
V_38 = F_16 ( V_16 , struct V_8 , V_39 ) ;
V_25 = V_38 -> V_25 ;
V_47 = V_38 -> V_40 ;
if ( V_117 -> V_4 & V_124 )
V_47 -> V_4 |= V_108 ;
if ( ! V_120 )
V_47 -> V_4 &= ~ V_100 ;
V_122 =
V_47 -> V_4 & V_100 &&
V_25 -> V_125 != V_126 ;
V_123 = V_122 || F_74 ( V_38 ) ;
if ( V_123 ) {
V_47 -> V_4 |= V_101 ;
F_80 ( & V_38 -> V_39 , & V_119 ) ;
} else
F_81 ( & V_38 -> V_39 , & V_119 ) ;
V_25 -> V_37 . V_85 = V_84 & ~ V_127 ;
V_25 -> V_37 . V_86 = 0 ;
}
F_82 ( & V_119 , V_16 ) ;
V_121 = 0 ;
do {
int V_29 = 0 ;
F_67 (vma, vmas, exec_list) {
if ( ! F_27 ( & V_38 -> V_46 ) )
continue;
if ( F_76 ( V_38 ) )
V_29 = F_83 ( V_38 ) ;
else
V_29 = F_70 ( V_38 , V_103 , V_118 ) ;
if ( V_29 )
goto V_34;
}
F_67 (vma, vmas, exec_list) {
if ( F_27 ( & V_38 -> V_46 ) )
continue;
V_29 = F_70 ( V_38 , V_103 , V_118 ) ;
if ( V_29 )
goto V_34;
}
V_34:
if ( V_29 != - V_112 || V_121 ++ )
return V_29 ;
F_67 (vma, vmas, exec_list)
F_26 ( V_38 ) ;
V_29 = F_84 ( V_21 , true ) ;
if ( V_29 )
return V_29 ;
} while ( 1 );
}
static int
F_85 ( struct V_59 * V_51 ,
struct V_2 * args ,
struct V_22 * V_23 ,
struct V_102 * V_103 ,
struct V_1 * V_3 ,
struct V_18 * V_19 ,
struct V_116 * V_117 )
{
struct V_56 * V_57 ;
struct V_20 * V_21 ;
struct V_8 * V_38 ;
bool V_118 ;
int * V_128 ;
int V_28 , V_129 , V_29 ;
unsigned V_12 = args -> V_7 ;
V_21 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) -> V_21 ;
while ( ! F_13 ( & V_3 -> V_16 ) ) {
V_38 = F_16 ( & V_3 -> V_16 , struct V_8 , V_39 ) ;
F_20 ( & V_38 -> V_39 ) ;
F_26 ( V_38 ) ;
F_22 ( & V_38 -> V_25 -> V_37 ) ;
}
F_86 ( & V_51 -> V_130 ) ;
V_129 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
V_129 += V_19 [ V_28 ] . V_97 ;
V_128 = F_87 ( V_12 , sizeof( * V_128 ) ) ;
V_57 = F_87 ( V_129 , sizeof( * V_57 ) ) ;
if ( V_57 == NULL || V_128 == NULL ) {
F_88 ( V_57 ) ;
F_88 ( V_128 ) ;
F_89 ( & V_51 -> V_130 ) ;
return - V_131 ;
}
V_129 = 0 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
struct V_56 T_5 * V_94 ;
T_6 V_132 = ( T_6 ) - 1 ;
int V_133 ;
V_94 = F_60 ( V_19 [ V_28 ] . V_96 ) ;
if ( F_90 ( V_57 + V_129 , V_94 ,
V_19 [ V_28 ] . V_97 * sizeof( * V_57 ) ) ) {
V_29 = - V_89 ;
F_89 ( & V_51 -> V_130 ) ;
goto V_34;
}
for ( V_133 = 0 ; V_133 < V_19 [ V_28 ] . V_97 ; V_133 ++ ) {
if ( F_91 ( & V_94 [ V_133 ] . V_87 ,
& V_132 ,
sizeof( V_132 ) ) ) {
V_29 = - V_89 ;
F_89 ( & V_51 -> V_130 ) ;
goto V_34;
}
}
V_128 [ V_28 ] = V_129 ;
V_129 += V_19 [ V_28 ] . V_97 ;
}
V_29 = F_92 ( V_51 ) ;
if ( V_29 ) {
F_89 ( & V_51 -> V_130 ) ;
goto V_34;
}
F_6 ( V_3 ) ;
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_118 = ( args -> V_4 & V_134 ) == 0 ;
V_29 = F_78 ( V_103 , & V_3 -> V_16 , V_117 , & V_118 ) ;
if ( V_29 )
goto V_34;
F_67 (vma, &eb->vmas, exec_list) {
int V_61 = V_38 -> V_40 - V_19 ;
V_29 = F_64 ( V_38 , V_3 ,
V_57 + V_128 [ V_61 ] ) ;
if ( V_29 )
goto V_34;
}
V_34:
F_88 ( V_57 ) ;
F_88 ( V_128 ) ;
return V_29 ;
}
static int
F_93 ( struct V_135 * V_136 ,
struct V_26 * V_16 )
{
const unsigned V_137 = ~ F_94 ( V_136 -> V_103 ) ;
struct V_8 * V_38 ;
T_1 V_138 = 0 ;
bool V_139 = false ;
int V_29 ;
F_67 (vma, vmas, exec_list) {
struct V_24 * V_25 = V_38 -> V_25 ;
if ( V_25 -> V_88 & V_137 ) {
V_29 = F_95 ( V_25 , V_136 -> V_103 , & V_136 ) ;
if ( V_29 )
return V_29 ;
}
if ( V_25 -> V_37 . V_52 & V_53 )
V_139 |= F_96 ( V_25 , false ) ;
V_138 |= V_25 -> V_37 . V_52 ;
}
if ( V_139 )
F_97 ( V_136 -> V_103 -> V_51 ) ;
if ( V_138 & V_140 )
F_98 () ;
return F_99 ( V_136 ) ;
}
static bool
F_100 ( struct V_2 * V_19 )
{
if ( V_19 -> V_4 & V_141 )
return false ;
return ( ( V_19 -> V_142 | V_19 -> V_143 ) & 0x7 ) == 0 ;
}
static int
F_101 ( struct V_59 * V_51 ,
struct V_18 * V_19 ,
int V_12 )
{
unsigned V_144 = 0 ;
unsigned V_145 = V_146 / sizeof( struct V_56 ) ;
unsigned V_147 ;
int V_28 ;
V_147 = V_148 ;
if ( F_102 ( V_51 ) )
V_147 |= V_106 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ ) {
char T_5 * V_149 = F_60 ( V_19 [ V_28 ] . V_96 ) ;
int V_150 ;
if ( V_19 [ V_28 ] . V_4 & V_147 )
return - V_36 ;
if ( V_19 [ V_28 ] . V_111 && ! F_103 ( V_19 [ V_28 ] . V_111 ) )
return - V_36 ;
if ( V_19 [ V_28 ] . V_97 > V_145 - V_144 )
return - V_36 ;
V_144 += V_19 [ V_28 ] . V_97 ;
V_150 = V_19 [ V_28 ] . V_97 *
sizeof( struct V_56 ) ;
if ( ! F_104 ( V_151 , V_149 , V_150 ) )
return - V_89 ;
if ( F_105 ( ! V_152 . V_153 ) ) {
if ( F_106 ( V_149 , V_150 ) )
return - V_89 ;
}
}
return 0 ;
}
static struct V_116 *
F_107 ( struct V_59 * V_51 , struct V_22 * V_23 ,
struct V_102 * V_103 , const T_7 V_154 )
{
struct V_116 * V_117 = NULL ;
struct V_155 * V_156 ;
if ( V_103 -> V_157 != V_158 && V_154 != V_159 )
return F_108 ( - V_36 ) ;
V_117 = F_109 ( V_23 -> V_160 , V_154 ) ;
if ( F_18 ( V_117 ) )
return V_117 ;
V_156 = & V_117 -> V_161 ;
if ( V_156 -> V_162 ) {
F_12 ( L_14 , V_154 ) ;
return F_108 ( - V_163 ) ;
}
if ( V_152 . V_164 && ! V_117 -> V_165 [ V_103 -> V_157 ] . V_166 ) {
int V_29 = F_110 ( V_117 , V_103 ) ;
if ( V_29 ) {
F_12 ( L_15 , V_154 , V_29 ) ;
return F_108 ( V_29 ) ;
}
}
return V_117 ;
}
void
F_111 ( struct V_26 * V_16 ,
struct V_135 * V_136 )
{
struct V_102 * V_103 = F_112 ( V_136 ) ;
struct V_8 * V_38 ;
F_67 (vma, vmas, exec_list) {
struct V_18 * V_47 = V_38 -> V_40 ;
struct V_24 * V_25 = V_38 -> V_25 ;
T_7 V_167 = V_25 -> V_37 . V_83 ;
T_7 V_168 = V_25 -> V_37 . V_52 ;
V_25 -> V_169 = 1 ;
V_25 -> V_37 . V_52 = V_25 -> V_37 . V_86 ;
if ( V_25 -> V_37 . V_52 == 0 )
V_25 -> V_37 . V_85 |= V_25 -> V_37 . V_83 ;
V_25 -> V_37 . V_83 = V_25 -> V_37 . V_85 ;
F_113 ( V_38 , V_136 ) ;
if ( V_25 -> V_37 . V_52 ) {
F_114 ( & V_25 -> V_170 , V_136 ) ;
F_115 ( V_25 , V_171 ) ;
V_25 -> V_37 . V_52 &= ~ V_84 ;
}
if ( V_47 -> V_4 & V_100 ) {
F_114 ( & V_25 -> V_172 , V_136 ) ;
if ( V_47 -> V_4 & V_48 ) {
struct V_66 * V_67 = F_116 ( V_103 -> V_51 ) ;
F_81 ( & V_67 -> V_173 [ V_25 -> V_174 ] . V_175 ,
& V_67 -> V_176 . V_177 ) ;
}
}
F_117 ( V_25 , V_167 , V_168 ) ;
}
}
void
F_118 ( struct V_178 * V_179 )
{
V_179 -> V_103 -> V_180 = true ;
F_119 ( V_179 -> V_181 , V_179 -> V_182 , true ) ;
}
static int
F_120 ( struct V_59 * V_51 ,
struct V_135 * V_136 )
{
struct V_102 * V_103 = V_136 -> V_103 ;
struct V_66 * V_67 = V_51 -> V_68 ;
int V_29 , V_28 ;
if ( ! F_121 ( V_51 ) || V_103 != & V_67 -> V_103 [ V_158 ] ) {
F_12 ( L_16 ) ;
return - V_36 ;
}
V_29 = F_122 ( V_136 , 4 * 3 ) ;
if ( V_29 )
return V_29 ;
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
F_123 ( V_103 , F_124 ( 1 ) ) ;
F_123 ( V_103 , F_125 ( V_28 ) ) ;
F_123 ( V_103 , 0 ) ;
}
F_126 ( V_103 ) ;
return 0 ;
}
static int
F_127 ( struct V_135 * V_136 ,
struct V_183 * V_184 ,
int V_185 , int V_186 )
{
struct V_102 * V_103 = V_136 -> V_103 ;
int V_29 ;
if ( V_184 -> V_187 <= V_184 -> y1 || V_184 -> V_188 <= V_184 -> V_189 ||
V_184 -> V_187 <= 0 || V_184 -> V_188 <= 0 ) {
F_128 ( L_17 ,
V_184 -> V_189 , V_184 -> y1 , V_184 -> V_188 , V_184 -> V_187 ) ;
return - V_36 ;
}
if ( F_39 ( V_103 -> V_51 ) -> V_65 >= 4 ) {
V_29 = F_122 ( V_136 , 4 ) ;
if ( V_29 )
return V_29 ;
F_123 ( V_103 , V_190 ) ;
F_123 ( V_103 , ( V_184 -> V_189 & 0xffff ) | V_184 -> y1 << 16 ) ;
F_123 ( V_103 , ( ( V_184 -> V_188 - 1 ) & 0xffff ) | ( V_184 -> V_187 - 1 ) << 16 ) ;
F_123 ( V_103 , V_186 ) ;
} else {
V_29 = F_122 ( V_136 , 6 ) ;
if ( V_29 )
return V_29 ;
F_123 ( V_103 , V_191 ) ;
F_123 ( V_103 , V_185 ) ;
F_123 ( V_103 , ( V_184 -> V_189 & 0xffff ) | V_184 -> y1 << 16 ) ;
F_123 ( V_103 , ( ( V_184 -> V_188 - 1 ) & 0xffff ) | ( V_184 -> V_187 - 1 ) << 16 ) ;
F_123 ( V_103 , V_186 ) ;
F_123 ( V_103 , 0 ) ;
}
F_126 ( V_103 ) ;
return 0 ;
}
static struct V_24 *
F_129 ( struct V_102 * V_103 ,
struct V_18 * V_192 ,
struct V_1 * V_3 ,
struct V_24 * V_182 ,
T_7 V_142 ,
T_7 V_143 ,
bool V_193 )
{
struct V_24 * V_194 ;
struct V_8 * V_38 ;
int V_29 ;
V_194 = F_130 ( & V_103 -> V_195 ,
F_131 ( V_143 ) ) ;
if ( F_18 ( V_194 ) )
return V_194 ;
V_29 = F_132 ( V_103 ,
V_182 ,
V_194 ,
V_142 ,
V_143 ,
V_193 ) ;
if ( V_29 )
goto V_34;
V_29 = F_133 ( V_194 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
F_134 ( V_194 ) ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_38 = F_135 ( V_194 ) ;
V_38 -> V_40 = V_192 ;
V_38 -> V_40 -> V_4 = V_49 ;
F_14 ( & V_194 -> V_37 ) ;
F_15 ( & V_38 -> V_39 , & V_3 -> V_16 ) ;
V_194 -> V_37 . V_85 = V_127 ;
return V_194 ;
V_34:
F_134 ( V_194 ) ;
if ( V_29 == - V_196 )
return V_182 ;
else
return F_108 ( V_29 ) ;
}
int
F_136 ( struct V_178 * V_179 ,
struct V_2 * args ,
struct V_26 * V_16 )
{
struct V_183 * V_197 = NULL ;
struct V_59 * V_51 = V_179 -> V_51 ;
struct V_102 * V_103 = V_179 -> V_103 ;
struct V_66 * V_67 = V_51 -> V_68 ;
T_6 V_198 , V_199 ;
int V_200 ;
T_7 V_201 ;
int V_28 , V_29 = 0 ;
if ( args -> V_202 != 0 ) {
if ( V_103 != & V_67 -> V_103 [ V_158 ] ) {
F_12 ( L_18 ) ;
return - V_36 ;
}
if ( F_39 ( V_51 ) -> V_65 >= 5 ) {
F_12 ( L_19 ) ;
return - V_36 ;
}
if ( args -> V_202 > V_146 / sizeof( * V_197 ) ) {
F_12 ( L_20 ,
args -> V_202 ) ;
return - V_36 ;
}
V_197 = F_137 ( args -> V_202 ,
sizeof( * V_197 ) ,
V_203 ) ;
if ( V_197 == NULL ) {
V_29 = - V_131 ;
goto error;
}
if ( F_90 ( V_197 ,
F_60 ( args -> V_204 ) ,
sizeof( * V_197 ) * args -> V_202 ) ) {
V_29 = - V_89 ;
goto error;
}
} else {
if ( args -> V_186 == 0xffffffff ) {
F_12 ( L_21 ) ;
args -> V_186 = 0 ;
}
if ( args -> V_185 || args -> V_186 || args -> V_204 ) {
F_12 ( L_22 ) ;
return - V_36 ;
}
}
V_29 = F_93 ( V_179 -> V_181 , V_16 ) ;
if ( V_29 )
goto error;
V_29 = F_138 ( V_179 -> V_181 ) ;
if ( V_29 )
goto error;
F_139 ( V_179 -> V_117 -> V_205 && V_179 -> V_117 -> V_205 -> V_206 & ( 1 << V_103 -> V_157 ) ,
L_23 , V_103 -> V_207 ) ;
V_200 = args -> V_4 & V_208 ;
V_201 = V_208 ;
switch ( V_200 ) {
case V_209 :
case V_210 :
case V_211 :
if ( V_200 != 0 && V_103 != & V_67 -> V_103 [ V_158 ] ) {
F_12 ( L_24 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_200 != V_67 -> V_212 ) {
if ( F_39 ( V_51 ) -> V_65 < 4 ) {
F_12 ( L_25 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_51 ) -> V_65 > 5 &&
V_200 == V_211 ) {
F_12 ( L_26 ) ;
V_29 = - V_36 ;
goto error;
}
if ( F_39 ( V_51 ) -> V_65 >= 6 )
V_201 &= ~ V_211 ;
}
break;
default:
F_12 ( L_27 , V_200 ) ;
V_29 = - V_36 ;
goto error;
}
if ( V_103 == & V_67 -> V_103 [ V_158 ] &&
V_200 != V_67 -> V_212 ) {
V_29 = F_122 ( V_179 -> V_181 , 4 ) ;
if ( V_29 )
goto error;
F_123 ( V_103 , V_213 ) ;
F_123 ( V_103 , F_124 ( 1 ) ) ;
F_123 ( V_103 , V_214 ) ;
F_123 ( V_103 , V_201 << 16 | V_200 ) ;
F_126 ( V_103 ) ;
V_67 -> V_212 = V_200 ;
}
if ( args -> V_4 & V_215 ) {
V_29 = F_120 ( V_51 , V_179 -> V_181 ) ;
if ( V_29 )
goto error;
}
V_199 = args -> V_143 ;
V_198 = V_179 -> V_216 +
V_179 -> V_217 ;
if ( V_197 ) {
for ( V_28 = 0 ; V_28 < args -> V_202 ; V_28 ++ ) {
V_29 = F_127 ( V_179 -> V_181 , & V_197 [ V_28 ] ,
args -> V_185 , args -> V_186 ) ;
if ( V_29 )
goto error;
V_29 = V_103 -> V_218 ( V_179 -> V_181 ,
V_198 , V_199 ,
V_179 -> V_219 ) ;
if ( V_29 )
goto error;
}
} else {
V_29 = V_103 -> V_218 ( V_179 -> V_181 ,
V_198 , V_199 ,
V_179 -> V_219 ) ;
if ( V_29 )
return V_29 ;
}
F_140 ( V_179 -> V_181 , V_179 -> V_219 ) ;
F_111 ( V_16 , V_179 -> V_181 ) ;
F_118 ( V_179 ) ;
error:
F_30 ( V_197 ) ;
return V_29 ;
}
static int F_141 ( struct V_59 * V_51 ,
struct V_22 * V_23 )
{
struct V_66 * V_67 = V_51 -> V_68 ;
struct V_220 * V_221 = V_23 -> V_160 ;
if ( V_221 -> V_222 )
return V_221 -> V_222 -> V_157 ;
else {
int V_223 ;
F_89 ( & V_51 -> V_130 ) ;
if ( V_67 -> V_176 . V_224 == 0 ) {
V_223 = V_225 ;
V_67 -> V_176 . V_224 = 1 ;
} else {
V_223 = V_226 ;
V_67 -> V_176 . V_224 = 0 ;
}
V_221 -> V_222 = & V_67 -> V_103 [ V_223 ] ;
F_86 ( & V_51 -> V_130 ) ;
return V_223 ;
}
}
static struct V_24 *
F_142 ( struct V_1 * V_3 )
{
struct V_8 * V_38 = F_143 ( V_3 -> V_16 . V_227 , F_144 ( * V_38 ) , V_39 ) ;
V_38 -> V_40 -> V_4 |= V_108 ;
return V_38 -> V_25 ;
}
static int
F_145 ( struct V_59 * V_51 , void * V_228 ,
struct V_22 * V_23 ,
struct V_2 * args ,
struct V_18 * V_19 )
{
struct V_66 * V_67 = V_51 -> V_68 ;
struct V_1 * V_3 ;
struct V_24 * V_182 ;
struct V_18 V_192 ;
struct V_102 * V_103 ;
struct V_116 * V_117 ;
struct V_20 * V_21 ;
struct V_178 V_229 ;
struct V_178 * V_179 = & V_229 ;
const T_7 V_154 = F_146 ( * args ) ;
T_7 V_219 ;
int V_29 ;
bool V_118 ;
if ( ! F_100 ( args ) )
return - V_36 ;
V_29 = F_101 ( V_51 , V_19 , args -> V_7 ) ;
if ( V_29 )
return V_29 ;
V_219 = 0 ;
if ( args -> V_4 & V_230 ) {
if ( ! V_23 -> V_193 || ! F_147 ( V_231 ) )
return - V_232 ;
V_219 |= V_233 ;
}
if ( args -> V_4 & V_234 )
V_219 |= V_235 ;
if ( ( args -> V_4 & V_236 ) > V_237 ) {
F_12 ( L_28 ,
( int ) ( args -> V_4 & V_236 ) ) ;
return - V_36 ;
}
if ( ( ( args -> V_4 & V_236 ) != V_238 ) &&
( ( args -> V_4 & V_239 ) != 0 ) ) {
F_12 ( L_29
L_30 , ( int ) ( args -> V_4 ) ) ;
return - V_36 ;
}
if ( ( args -> V_4 & V_236 ) == V_240 )
V_103 = & V_67 -> V_103 [ V_158 ] ;
else if ( ( args -> V_4 & V_236 ) == V_238 ) {
if ( F_148 ( V_51 ) ) {
int V_223 ;
switch ( args -> V_4 & V_239 ) {
case V_241 :
V_223 = F_141 ( V_51 , V_23 ) ;
V_103 = & V_67 -> V_103 [ V_223 ] ;
break;
case V_242 :
V_103 = & V_67 -> V_103 [ V_225 ] ;
break;
case V_243 :
V_103 = & V_67 -> V_103 [ V_226 ] ;
break;
default:
F_12 ( L_31 ,
( int ) ( args -> V_4 & V_239 ) ) ;
return - V_36 ;
}
} else
V_103 = & V_67 -> V_103 [ V_225 ] ;
} else
V_103 = & V_67 -> V_103 [ ( args -> V_4 & V_236 ) - 1 ] ;
if ( ! F_149 ( V_103 ) ) {
F_12 ( L_32 ,
( int ) ( args -> V_4 & V_236 ) ) ;
return - V_36 ;
}
if ( args -> V_7 < 1 ) {
F_12 ( L_33 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_4 & V_244 ) {
if ( ! F_150 ( V_51 ) ) {
F_12 ( L_34 ) ;
return - V_36 ;
}
if ( V_103 -> V_157 != V_158 ) {
F_12 ( L_35 ,
V_103 -> V_207 ) ;
return - V_36 ;
}
V_219 |= V_245 ;
}
F_151 ( V_67 ) ;
V_29 = F_92 ( V_51 ) ;
if ( V_29 )
goto V_246;
V_117 = F_107 ( V_51 , V_23 , V_103 , V_154 ) ;
if ( F_18 ( V_117 ) ) {
F_86 ( & V_51 -> V_130 ) ;
V_29 = F_19 ( V_117 ) ;
goto V_246;
}
F_152 ( V_117 ) ;
if ( V_117 -> V_205 )
V_21 = & V_117 -> V_205 -> V_37 ;
else
V_21 = & V_67 -> V_70 . V_37 ;
memset ( & V_229 , 0x00 , sizeof( V_229 ) ) ;
V_3 = F_1 ( args ) ;
if ( V_3 == NULL ) {
F_153 ( V_117 ) ;
F_86 ( & V_51 -> V_130 ) ;
V_29 = - V_131 ;
goto V_246;
}
V_29 = F_7 ( V_3 , V_19 , args , V_21 , V_23 ) ;
if ( V_29 )
goto V_34;
V_182 = F_142 ( V_3 ) ;
V_118 = ( args -> V_4 & V_134 ) == 0 ;
V_29 = F_78 ( V_103 , & V_3 -> V_16 , V_117 , & V_118 ) ;
if ( V_29 )
goto V_34;
if ( V_118 )
V_29 = F_65 ( V_3 ) ;
if ( V_29 ) {
if ( V_29 == - V_89 ) {
V_29 = F_85 ( V_51 , args , V_23 , V_103 ,
V_3 , V_19 , V_117 ) ;
F_154 ( ! F_155 ( & V_51 -> V_130 ) ) ;
}
if ( V_29 )
goto V_34;
}
if ( V_182 -> V_37 . V_86 ) {
F_12 ( L_36 ) ;
V_29 = - V_36 ;
goto V_34;
}
V_179 -> V_217 = args -> V_142 ;
if ( F_156 ( V_103 ) && args -> V_143 ) {
struct V_24 * V_247 ;
V_247 = F_129 ( V_103 ,
& V_192 ,
V_3 ,
V_182 ,
args -> V_142 ,
args -> V_143 ,
V_23 -> V_193 ) ;
if ( F_18 ( V_247 ) ) {
V_29 = F_19 ( V_247 ) ;
goto V_34;
}
if ( V_247 != V_182 ) {
V_219 |= V_233 ;
V_179 -> V_217 = 0 ;
V_182 = V_247 ;
}
}
V_182 -> V_37 . V_85 |= V_127 ;
if ( V_219 & V_233 ) {
V_29 = F_133 ( V_182 , 0 , 0 ) ;
if ( V_29 )
goto V_34;
V_179 -> V_216 = F_45 ( V_182 ) ;
} else
V_179 -> V_216 = F_157 ( V_182 , V_21 ) ;
V_29 = F_158 ( V_103 , V_117 , & V_179 -> V_181 ) ;
if ( V_29 )
goto V_248;
V_29 = F_159 ( V_179 -> V_181 , V_23 ) ;
if ( V_29 )
goto V_248;
V_179 -> V_51 = V_51 ;
V_179 -> V_23 = V_23 ;
V_179 -> V_103 = V_103 ;
V_179 -> V_219 = V_219 ;
V_179 -> V_182 = V_182 ;
V_179 -> V_117 = V_117 ;
V_29 = V_67 -> V_249 . V_250 ( V_179 , args , & V_3 -> V_16 ) ;
V_248:
if ( V_219 & V_233 )
F_160 ( V_182 ) ;
V_34:
F_153 ( V_117 ) ;
F_29 ( V_3 ) ;
if ( V_29 && V_179 -> V_181 )
F_161 ( V_179 -> V_181 ) ;
F_86 ( & V_51 -> V_130 ) ;
V_246:
F_162 ( V_67 ) ;
return V_29 ;
}
int
F_163 ( struct V_59 * V_51 , void * V_228 ,
struct V_22 * V_23 )
{
struct V_251 * args = V_228 ;
struct V_2 V_252 ;
struct V_253 * V_39 = NULL ;
struct V_18 * V_254 = NULL ;
int V_29 , V_28 ;
if ( args -> V_7 < 1 ) {
F_12 ( L_33 , args -> V_7 ) ;
return - V_36 ;
}
V_39 = F_87 ( sizeof( * V_39 ) , args -> V_7 ) ;
V_254 = F_87 ( sizeof( * V_254 ) , args -> V_7 ) ;
if ( V_39 == NULL || V_254 == NULL ) {
F_12 ( L_37 ,
args -> V_7 ) ;
F_88 ( V_39 ) ;
F_88 ( V_254 ) ;
return - V_131 ;
}
V_29 = F_90 ( V_39 ,
F_60 ( args -> V_255 ) ,
sizeof( * V_39 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_38 ,
args -> V_7 , V_29 ) ;
F_88 ( V_39 ) ;
F_88 ( V_254 ) ;
return - V_89 ;
}
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_254 [ V_28 ] . V_32 = V_39 [ V_28 ] . V_32 ;
V_254 [ V_28 ] . V_97 = V_39 [ V_28 ] . V_97 ;
V_254 [ V_28 ] . V_96 = V_39 [ V_28 ] . V_96 ;
V_254 [ V_28 ] . V_111 = V_39 [ V_28 ] . V_111 ;
V_254 [ V_28 ] . V_61 = V_39 [ V_28 ] . V_61 ;
if ( F_39 ( V_51 ) -> V_65 < 4 )
V_254 [ V_28 ] . V_4 = V_100 ;
else
V_254 [ V_28 ] . V_4 = 0 ;
}
V_252 . V_255 = args -> V_255 ;
V_252 . V_7 = args -> V_7 ;
V_252 . V_142 = args -> V_142 ;
V_252 . V_143 = args -> V_143 ;
V_252 . V_185 = args -> V_185 ;
V_252 . V_186 = args -> V_186 ;
V_252 . V_202 = args -> V_202 ;
V_252 . V_204 = args -> V_204 ;
V_252 . V_4 = V_256 ;
F_164 ( V_252 , 0 ) ;
V_29 = F_145 ( V_51 , V_228 , V_23 , & V_252 , V_254 ) ;
if ( ! V_29 ) {
struct V_253 T_5 * V_257 =
F_60 ( args -> V_255 ) ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_91 ( & V_257 [ V_28 ] . V_61 ,
& V_254 [ V_28 ] . V_61 ,
sizeof( V_257 [ V_28 ] . V_61 ) ) ;
if ( V_29 ) {
V_29 = - V_89 ;
F_12 ( L_39
L_40 ,
args -> V_7 , V_29 ) ;
break;
}
}
}
F_88 ( V_39 ) ;
F_88 ( V_254 ) ;
return V_29 ;
}
int
F_165 ( struct V_59 * V_51 , void * V_228 ,
struct V_22 * V_23 )
{
struct V_2 * args = V_228 ;
struct V_18 * V_254 = NULL ;
int V_29 ;
if ( args -> V_7 < 1 ||
args -> V_7 > V_146 / sizeof( * V_254 ) ) {
F_12 ( L_41 , args -> V_7 ) ;
return - V_36 ;
}
if ( args -> V_258 != 0 ) {
F_12 ( L_42 ) ;
return - V_36 ;
}
V_254 = F_2 ( sizeof( * V_254 ) * args -> V_7 ,
V_9 | V_10 | V_11 ) ;
if ( V_254 == NULL )
V_254 = F_87 ( sizeof( * V_254 ) ,
args -> V_7 ) ;
if ( V_254 == NULL ) {
F_12 ( L_37 ,
args -> V_7 ) ;
return - V_131 ;
}
V_29 = F_90 ( V_254 ,
F_60 ( args -> V_255 ) ,
sizeof( * V_254 ) * args -> V_7 ) ;
if ( V_29 != 0 ) {
F_12 ( L_38 ,
args -> V_7 , V_29 ) ;
F_88 ( V_254 ) ;
return - V_89 ;
}
V_29 = F_145 ( V_51 , V_228 , V_23 , args , V_254 ) ;
if ( ! V_29 ) {
struct V_18 T_5 * V_257 =
F_60 ( args -> V_255 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < args -> V_7 ; V_28 ++ ) {
V_29 = F_91 ( & V_257 [ V_28 ] . V_61 ,
& V_254 [ V_28 ] . V_61 ,
sizeof( V_257 [ V_28 ] . V_61 ) ) ;
if ( V_29 ) {
V_29 = - V_89 ;
F_12 ( L_39
L_43 ,
args -> V_7 ) ;
break;
}
}
}
F_88 ( V_254 ) ;
return V_29 ;
}
