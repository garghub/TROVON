static struct V_1 *
F_1 ( int V_2 )
{
struct V_1 * V_3 ;
int V_4 = V_5 / sizeof( struct V_6 ) / 2 ;
F_2 ( ! F_3 ( V_5 / sizeof( struct V_6 ) ) ) ;
while ( V_4 > V_2 )
V_4 >>= 1 ;
V_3 = F_4 ( V_4 * sizeof( struct V_6 ) +
sizeof( struct V_1 ) ,
V_7 ) ;
if ( V_3 == NULL )
return V_3 ;
V_3 -> V_8 = V_4 - 1 ;
return V_3 ;
}
static void
F_5 ( struct V_1 * V_3 )
{
memset ( V_3 -> V_9 , 0 , ( V_3 -> V_8 + 1 ) * sizeof( struct V_6 ) ) ;
}
static void
F_6 ( struct V_1 * V_3 , struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_12 ,
& V_3 -> V_9 [ V_11 -> V_13 & V_3 -> V_8 ] ) ;
}
static struct V_10 *
F_8 ( struct V_1 * V_3 , unsigned long V_14 )
{
struct V_6 * V_15 ;
struct V_16 * V_17 ;
struct V_10 * V_11 ;
V_15 = & V_3 -> V_9 [ V_14 & V_3 -> V_8 ] ;
F_9 (node, head) {
V_11 = F_10 ( V_17 , struct V_10 , V_12 ) ;
if ( V_11 -> V_13 == V_14 )
return V_11 ;
}
return NULL ;
}
static void
F_11 ( struct V_1 * V_3 )
{
F_12 ( V_3 ) ;
}
static inline int F_13 ( struct V_10 * V_11 )
{
return ( V_11 -> V_18 . V_19 == V_20 ||
! V_11 -> V_21 ||
V_11 -> V_22 != V_23 ) ;
}
static int
F_14 ( struct V_10 * V_11 ,
struct V_1 * V_3 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_11 -> V_18 . V_27 ;
struct V_28 * V_29 ;
struct V_10 * V_30 ;
T_1 V_31 ;
int V_32 = - V_33 ;
V_29 = & F_8 ( V_3 , V_25 -> V_34 ) -> V_18 ;
if ( F_15 ( V_29 == NULL ) )
return - V_35 ;
V_30 = F_16 ( V_29 ) ;
V_31 = V_30 -> V_36 ;
if ( F_15 ( F_17 ( V_27 ) &&
V_25 -> V_19 == V_37 &&
! V_30 -> V_38 ) ) {
F_18 ( V_30 ,
V_30 -> V_22 ) ;
}
if ( F_15 ( V_31 == 0 ) ) {
F_19 ( L_1 ,
V_25 -> V_34 ) ;
return V_32 ;
}
if ( F_15 ( V_25 -> V_19 & ( V_25 -> V_19 - 1 ) ) ) {
F_19 ( L_2
L_3
L_4 ,
V_11 , V_25 -> V_34 ,
( int ) V_25 -> V_39 ,
V_25 -> V_40 ,
V_25 -> V_19 ) ;
return V_32 ;
}
if ( F_15 ( ( V_25 -> V_19 | V_25 -> V_40 )
& ~ V_41 ) ) {
F_19 ( L_5
L_3
L_4 ,
V_11 , V_25 -> V_34 ,
( int ) V_25 -> V_39 ,
V_25 -> V_40 ,
V_25 -> V_19 ) ;
return V_32 ;
}
if ( F_15 ( V_25 -> V_19 && V_29 -> V_42 &&
V_25 -> V_19 != V_29 -> V_42 ) ) {
F_19 ( L_6
L_3
L_7 ,
V_11 , V_25 -> V_34 ,
( int ) V_25 -> V_39 ,
V_25 -> V_19 ,
V_29 -> V_42 ) ;
return V_32 ;
}
V_29 -> V_43 |= V_25 -> V_40 ;
V_29 -> V_42 |= V_25 -> V_19 ;
if ( V_31 == V_25 -> V_44 )
return 0 ;
if ( F_15 ( V_25 -> V_39 > V_11 -> V_18 . V_2 - 4 ) ) {
F_19 ( L_8
L_9 ,
V_11 , V_25 -> V_34 ,
( int ) V_25 -> V_39 ,
( int ) V_11 -> V_18 . V_2 ) ;
return V_32 ;
}
if ( F_15 ( V_25 -> V_39 & 3 ) ) {
F_19 ( L_10
L_11 ,
V_11 , V_25 -> V_34 ,
( int ) V_25 -> V_39 ) ;
return V_32 ;
}
if ( V_11 -> V_45 && F_20 () )
return - V_46 ;
V_25 -> V_47 += V_31 ;
if ( F_13 ( V_11 ) ) {
T_1 V_48 = V_25 -> V_39 & ~ V_49 ;
char * V_50 ;
V_32 = F_21 ( V_11 , 1 ) ;
if ( V_32 )
return V_32 ;
V_50 = F_22 ( F_23 ( V_11 ,
V_25 -> V_39 >> V_51 ) ) ;
* ( T_1 * ) ( V_50 + V_48 ) = V_25 -> V_47 ;
F_24 ( V_50 ) ;
} else {
struct V_52 * V_53 = V_27 -> V_54 ;
T_1 T_2 * V_55 ;
void T_2 * V_56 ;
V_32 = F_25 ( V_11 , true ) ;
if ( V_32 )
return V_32 ;
V_32 = F_26 ( V_11 ) ;
if ( V_32 )
return V_32 ;
V_25 -> V_39 += V_11 -> V_36 ;
V_56 = F_27 ( V_53 -> V_57 . V_58 ,
V_25 -> V_39 & V_49 ) ;
V_55 = ( T_1 T_2 * )
( V_56 + ( V_25 -> V_39 & ~ V_49 ) ) ;
F_28 ( V_25 -> V_47 , V_55 ) ;
F_29 ( V_56 ) ;
}
V_25 -> V_44 = V_31 ;
return 0 ;
}
static int
F_30 ( struct V_10 * V_11 ,
struct V_1 * V_3 )
{
#define F_31 ( T_3 ) ((x) / sizeof(struct drm_i915_gem_relocation_entry))
struct V_24 V_59 [ F_31 ( 512 ) ] ;
struct V_24 T_4 * V_60 ;
struct V_61 * V_62 = V_11 -> V_63 ;
int V_64 , V_32 ;
V_60 = ( void T_4 * ) ( V_65 ) V_62 -> V_66 ;
V_64 = V_62 -> V_67 ;
while ( V_64 ) {
struct V_24 * V_68 = V_59 ;
int V_4 = V_64 ;
if ( V_4 > F_32 ( V_59 ) )
V_4 = F_32 ( V_59 ) ;
V_64 -= V_4 ;
if ( F_33 ( V_68 , V_60 , V_4 * sizeof( V_68 [ 0 ] ) ) )
return - V_46 ;
do {
T_5 V_39 = V_68 -> V_44 ;
V_32 = F_14 ( V_11 , V_3 , V_68 ) ;
if ( V_32 )
return V_32 ;
if ( V_68 -> V_44 != V_39 &&
F_34 ( & V_60 -> V_44 ,
& V_68 -> V_44 ,
sizeof( V_68 -> V_44 ) ) ) {
return - V_46 ;
}
V_60 ++ ;
V_68 ++ ;
} while ( -- V_4 );
}
return 0 ;
#undef F_31
}
static int
F_35 ( struct V_10 * V_11 ,
struct V_1 * V_3 ,
struct V_24 * V_69 )
{
const struct V_61 * V_62 = V_11 -> V_63 ;
int V_70 , V_32 ;
for ( V_70 = 0 ; V_70 < V_62 -> V_67 ; V_70 ++ ) {
V_32 = F_14 ( V_11 , V_3 , & V_69 [ V_70 ] ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int
F_36 ( struct V_26 * V_27 ,
struct V_1 * V_3 ,
struct V_71 * V_72 )
{
struct V_10 * V_11 ;
int V_32 = 0 ;
F_37 () ;
F_38 (obj, objects, exec_list) {
V_32 = F_30 ( V_11 , V_3 ) ;
if ( V_32 )
break;
}
F_39 () ;
return V_32 ;
}
static int
F_40 ( struct V_10 * V_11 )
{
struct V_61 * V_62 = V_11 -> V_63 ;
return V_62 -> V_67 && ! F_13 ( V_11 ) ;
}
static int
F_41 ( struct V_10 * V_11 ,
struct V_73 * V_74 )
{
struct V_52 * V_53 = V_11 -> V_18 . V_27 -> V_54 ;
struct V_61 * V_62 = V_11 -> V_63 ;
bool V_75 = F_42 ( V_74 -> V_27 ) -> V_76 < 4 ;
bool V_77 , V_78 ;
int V_32 ;
V_77 =
V_75 &&
V_62 -> V_79 & V_80 &&
V_11 -> V_81 != V_82 ;
V_78 = V_77 || F_40 ( V_11 ) ;
V_32 = F_43 ( V_11 , V_62 -> V_83 , V_78 , false ) ;
if ( V_32 )
return V_32 ;
V_62 -> V_79 |= V_84 ;
if ( V_75 ) {
if ( V_62 -> V_79 & V_80 ) {
V_32 = F_44 ( V_11 ) ;
if ( V_32 )
return V_32 ;
if ( F_45 ( V_11 ) )
V_62 -> V_79 |= V_85 ;
V_11 -> V_86 = true ;
}
}
if ( V_53 -> V_57 . V_87 && ! V_11 -> V_88 ) {
F_46 ( V_53 -> V_57 . V_87 ,
V_11 , V_11 -> V_22 ) ;
V_11 -> V_88 = 1 ;
}
V_62 -> V_39 = V_11 -> V_36 ;
return 0 ;
}
static void
F_47 ( struct V_10 * V_11 )
{
struct V_61 * V_62 ;
if ( ! V_11 -> V_89 )
return;
V_62 = V_11 -> V_63 ;
if ( V_62 -> V_79 & V_85 )
F_48 ( V_11 ) ;
if ( V_62 -> V_79 & V_84 )
F_49 ( V_11 ) ;
V_62 -> V_79 &= ~ ( V_85 | V_84 ) ;
}
static int
F_50 ( struct V_73 * V_74 ,
struct V_90 * V_91 ,
struct V_71 * V_72 )
{
struct V_10 * V_11 ;
struct V_71 V_92 ;
bool V_75 = F_42 ( V_74 -> V_27 ) -> V_76 < 4 ;
int V_93 ;
F_51 ( & V_92 ) ;
while ( ! F_52 ( V_72 ) ) {
struct V_61 * V_62 ;
bool V_77 , V_78 ;
V_11 = F_53 ( V_72 ,
struct V_10 ,
V_94 ) ;
V_62 = V_11 -> V_63 ;
V_77 =
V_75 &&
V_62 -> V_79 & V_80 &&
V_11 -> V_81 != V_82 ;
V_78 = V_77 || F_40 ( V_11 ) ;
if ( V_78 )
F_54 ( & V_11 -> V_94 , & V_92 ) ;
else
F_55 ( & V_11 -> V_94 , & V_92 ) ;
V_11 -> V_18 . V_43 = 0 ;
V_11 -> V_18 . V_42 = 0 ;
V_11 -> V_86 = false ;
}
F_56 ( & V_92 , V_72 ) ;
V_93 = 0 ;
do {
int V_32 = 0 ;
F_38 (obj, objects, exec_list) {
struct V_61 * V_62 = V_11 -> V_63 ;
bool V_77 , V_78 ;
if ( ! V_11 -> V_89 )
continue;
V_77 =
V_75 &&
V_62 -> V_79 & V_80 &&
V_11 -> V_81 != V_82 ;
V_78 = V_77 || F_40 ( V_11 ) ;
if ( ( V_62 -> V_83 && V_11 -> V_36 & ( V_62 -> V_83 - 1 ) ) ||
( V_78 && ! V_11 -> V_21 ) )
V_32 = F_57 ( V_11 ) ;
else
V_32 = F_41 ( V_11 , V_74 ) ;
if ( V_32 )
goto V_95;
}
F_38 (obj, objects, exec_list) {
if ( V_11 -> V_89 )
continue;
V_32 = F_41 ( V_11 , V_74 ) ;
if ( V_32 )
goto V_95;
}
V_95:
F_38 (obj, objects, exec_list)
F_47 ( V_11 ) ;
if ( V_32 != - V_96 || V_93 ++ )
return V_32 ;
V_32 = F_58 ( V_74 -> V_27 ) ;
if ( V_32 )
return V_32 ;
} while ( 1 );
}
static int
F_59 ( struct V_26 * V_27 ,
struct V_90 * V_91 ,
struct V_73 * V_74 ,
struct V_71 * V_72 ,
struct V_1 * V_3 ,
struct V_61 * V_97 ,
int V_4 )
{
struct V_24 * V_25 ;
struct V_10 * V_11 ;
int * V_98 ;
int V_70 , V_99 , V_32 ;
while ( ! F_52 ( V_72 ) ) {
V_11 = F_53 ( V_72 ,
struct V_10 ,
V_94 ) ;
F_60 ( & V_11 -> V_94 ) ;
F_61 ( & V_11 -> V_18 ) ;
}
F_62 ( & V_27 -> V_100 ) ;
V_99 = 0 ;
for ( V_70 = 0 ; V_70 < V_4 ; V_70 ++ )
V_99 += V_97 [ V_70 ] . V_67 ;
V_98 = F_63 ( V_4 , sizeof( * V_98 ) ) ;
V_25 = F_63 ( V_99 , sizeof( * V_25 ) ) ;
if ( V_25 == NULL || V_98 == NULL ) {
F_64 ( V_25 ) ;
F_64 ( V_98 ) ;
F_65 ( & V_27 -> V_100 ) ;
return - V_101 ;
}
V_99 = 0 ;
for ( V_70 = 0 ; V_70 < V_4 ; V_70 ++ ) {
struct V_24 T_4 * V_60 ;
V_60 = ( void T_4 * ) ( V_65 ) V_97 [ V_70 ] . V_66 ;
if ( F_66 ( V_25 + V_99 , V_60 ,
V_97 [ V_70 ] . V_67 * sizeof( * V_25 ) ) ) {
V_32 = - V_46 ;
F_65 ( & V_27 -> V_100 ) ;
goto V_95;
}
V_98 [ V_70 ] = V_99 ;
V_99 += V_97 [ V_70 ] . V_67 ;
}
V_32 = F_67 ( V_27 ) ;
if ( V_32 ) {
F_65 ( & V_27 -> V_100 ) ;
goto V_95;
}
F_5 ( V_3 ) ;
for ( V_70 = 0 ; V_70 < V_4 ; V_70 ++ ) {
V_11 = F_16 ( F_68 ( V_27 , V_91 ,
V_97 [ V_70 ] . V_14 ) ) ;
if ( & V_11 -> V_18 == NULL ) {
F_19 ( L_12 ,
V_97 [ V_70 ] . V_14 , V_70 ) ;
V_32 = - V_35 ;
goto V_95;
}
F_69 ( & V_11 -> V_94 , V_72 ) ;
V_11 -> V_13 = V_97 [ V_70 ] . V_14 ;
V_11 -> V_63 = & V_97 [ V_70 ] ;
F_6 ( V_3 , V_11 ) ;
}
V_32 = F_50 ( V_74 , V_91 , V_72 ) ;
if ( V_32 )
goto V_95;
F_38 (obj, objects, exec_list) {
int V_39 = V_11 -> V_63 - V_97 ;
V_32 = F_35 ( V_11 , V_3 ,
V_25 + V_98 [ V_39 ] ) ;
if ( V_32 )
goto V_95;
}
V_95:
F_64 ( V_25 ) ;
F_64 ( V_98 ) ;
return V_32 ;
}
static int
F_70 ( struct V_73 * V_74 , T_6 V_102 )
{
T_6 V_103 , V_104 ;
int V_32 ;
for ( V_103 = 0 ; V_102 >> V_103 ; V_103 ++ ) {
if ( ( ( V_102 >> V_103 ) & 1 ) == 0 )
continue;
if ( V_103 )
V_104 = V_105 ;
else
V_104 = V_106 ;
V_32 = F_71 ( V_74 , 2 ) ;
if ( V_32 )
return V_32 ;
F_72 ( V_74 , V_107 | V_104 ) ;
F_72 ( V_74 , V_108 ) ;
F_73 ( V_74 ) ;
}
return 0 ;
}
static int
F_74 ( struct V_73 * V_74 ,
struct V_71 * V_72 )
{
struct V_10 * V_11 ;
T_1 V_109 = 0 ;
T_1 V_102 = 0 ;
int V_32 ;
F_38 (obj, objects, exec_list) {
V_32 = F_75 ( V_11 , V_74 ) ;
if ( V_32 )
return V_32 ;
if ( V_11 -> V_18 . V_19 & V_20 )
F_76 ( V_11 ) ;
if ( V_11 -> V_18 . V_42 )
V_102 |= F_77 ( & V_11 -> V_110 ) ;
V_109 |= V_11 -> V_18 . V_19 ;
}
if ( V_102 ) {
V_32 = F_70 ( V_74 , V_102 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_109 & V_20 )
F_78 () ;
if ( V_109 & V_111 )
F_79 () ;
return F_80 ( V_74 ) ;
}
static bool
F_81 ( struct V_112 * V_97 )
{
return ( ( V_97 -> V_113 | V_97 -> V_114 ) & 0x7 ) == 0 ;
}
static int
F_82 ( struct V_61 * V_97 ,
int V_4 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_4 ; V_70 ++ ) {
char T_4 * V_115 = ( char T_4 * ) ( V_65 ) V_97 [ V_70 ] . V_66 ;
int V_116 ;
if ( V_97 [ V_70 ] . V_67 >
V_117 / sizeof( struct V_24 ) )
return - V_33 ;
V_116 = V_97 [ V_70 ] . V_67 *
sizeof( struct V_24 ) ;
if ( ! F_83 ( V_118 , V_115 , V_116 ) )
return - V_46 ;
if ( ! F_83 ( V_119 , V_115 , V_116 ) )
return - V_46 ;
if ( F_84 ( V_115 , V_116 ) )
return - V_46 ;
}
return 0 ;
}
static void
F_85 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
T_6 V_120 )
{
struct V_10 * V_11 ;
F_38 (obj, objects, exec_list) {
T_6 V_121 = V_11 -> V_18 . V_40 ;
T_6 V_122 = V_11 -> V_18 . V_19 ;
V_11 -> V_18 . V_40 = V_11 -> V_18 . V_43 ;
V_11 -> V_18 . V_19 = V_11 -> V_18 . V_42 ;
V_11 -> V_123 = V_11 -> V_86 ;
F_86 ( V_11 , V_74 , V_120 ) ;
if ( V_11 -> V_18 . V_19 ) {
V_11 -> V_124 = 1 ;
V_11 -> V_125 = V_120 ;
if ( V_11 -> V_126 )
F_87 ( V_11 ) ;
}
F_88 ( V_11 , V_121 , V_122 ) ;
}
}
static void
F_89 ( struct V_26 * V_27 ,
struct V_90 * V_91 ,
struct V_73 * V_74 )
{
V_74 -> V_127 = true ;
( void ) F_90 ( V_74 , V_91 , NULL ) ;
}
static int
F_91 ( struct V_26 * V_27 ,
struct V_73 * V_74 )
{
T_7 * V_53 = V_27 -> V_54 ;
int V_32 , V_70 ;
if ( ! F_92 ( V_27 ) || V_74 != & V_53 -> V_74 [ V_128 ] )
return 0 ;
V_32 = F_71 ( V_74 , 4 * 3 ) ;
if ( V_32 )
return V_32 ;
for ( V_70 = 0 ; V_70 < 4 ; V_70 ++ ) {
F_72 ( V_74 , F_93 ( 1 ) ) ;
F_72 ( V_74 , F_94 ( V_70 ) ) ;
F_72 ( V_74 , 0 ) ;
}
F_73 ( V_74 ) ;
return 0 ;
}
static int
F_95 ( struct V_26 * V_27 , void * V_129 ,
struct V_90 * V_91 ,
struct V_112 * args ,
struct V_61 * V_97 )
{
T_7 * V_53 = V_27 -> V_54 ;
struct V_71 V_72 ;
struct V_1 * V_3 ;
struct V_10 * V_130 ;
struct V_131 * V_132 = NULL ;
struct V_73 * V_74 ;
T_6 V_133 = F_96 ( * args ) ;
T_6 V_134 , V_135 ;
T_6 V_120 ;
T_6 V_136 ;
int V_32 , V_137 , V_70 ;
if ( ! F_81 ( args ) ) {
F_19 ( L_13 ) ;
return - V_33 ;
}
V_32 = F_82 ( V_97 , args -> V_138 ) ;
if ( V_32 )
return V_32 ;
switch ( args -> V_79 & V_139 ) {
case V_140 :
case V_141 :
V_74 = & V_53 -> V_74 [ V_128 ] ;
break;
case V_142 :
V_74 = & V_53 -> V_74 [ V_143 ] ;
if ( V_133 != 0 ) {
F_19 ( L_14 ,
V_74 -> V_144 ) ;
return - V_145 ;
}
break;
case V_146 :
V_74 = & V_53 -> V_74 [ V_147 ] ;
if ( V_133 != 0 ) {
F_19 ( L_14 ,
V_74 -> V_144 ) ;
return - V_145 ;
}
break;
default:
F_19 ( L_15 ,
( int ) ( args -> V_79 & V_139 ) ) ;
return - V_33 ;
}
if ( ! F_97 ( V_74 ) ) {
F_19 ( L_16 ,
( int ) ( args -> V_79 & V_139 ) ) ;
return - V_33 ;
}
V_137 = args -> V_79 & V_148 ;
V_136 = V_148 ;
switch ( V_137 ) {
case V_149 :
case V_150 :
case V_151 :
if ( V_74 == & V_53 -> V_74 [ V_128 ] &&
V_137 != V_53 -> V_152 ) {
if ( F_42 ( V_27 ) -> V_76 < 4 )
return - V_33 ;
if ( F_42 ( V_27 ) -> V_76 > 5 &&
V_137 == V_151 )
return - V_33 ;
if ( F_42 ( V_27 ) -> V_76 >= 6 )
V_136 &= ~ V_151 ;
}
break;
default:
F_19 ( L_17 , V_137 ) ;
return - V_33 ;
}
if ( args -> V_138 < 1 ) {
F_19 ( L_18 , args -> V_138 ) ;
return - V_33 ;
}
if ( args -> V_153 != 0 ) {
if ( V_74 != & V_53 -> V_74 [ V_128 ] ) {
F_19 ( L_19 ) ;
return - V_33 ;
}
if ( F_42 ( V_27 ) -> V_76 >= 5 ) {
F_19 ( L_20 ) ;
return - V_33 ;
}
if ( args -> V_153 > V_154 / sizeof( * V_132 ) ) {
F_19 ( L_21 ,
args -> V_153 ) ;
return - V_33 ;
}
V_132 = F_98 ( args -> V_153 * sizeof( * V_132 ) ,
V_7 ) ;
if ( V_132 == NULL ) {
V_32 = - V_101 ;
goto V_155;
}
if ( F_66 ( V_132 ,
(struct V_131 T_4 * ) ( V_65 )
args -> V_156 ,
sizeof( * V_132 ) * args -> V_153 ) ) {
V_32 = - V_46 ;
goto V_155;
}
}
V_32 = F_67 ( V_27 ) ;
if ( V_32 )
goto V_155;
if ( V_53 -> V_57 . V_157 ) {
F_62 ( & V_27 -> V_100 ) ;
V_32 = - V_158 ;
goto V_155;
}
V_3 = F_1 ( args -> V_138 ) ;
if ( V_3 == NULL ) {
F_62 ( & V_27 -> V_100 ) ;
V_32 = - V_101 ;
goto V_155;
}
F_51 ( & V_72 ) ;
for ( V_70 = 0 ; V_70 < args -> V_138 ; V_70 ++ ) {
struct V_10 * V_11 ;
V_11 = F_16 ( F_68 ( V_27 , V_91 ,
V_97 [ V_70 ] . V_14 ) ) ;
if ( & V_11 -> V_18 == NULL ) {
F_19 ( L_12 ,
V_97 [ V_70 ] . V_14 , V_70 ) ;
V_32 = - V_35 ;
goto V_95;
}
if ( ! F_52 ( & V_11 -> V_94 ) ) {
F_19 ( L_22 ,
V_11 , V_97 [ V_70 ] . V_14 , V_70 ) ;
V_32 = - V_33 ;
goto V_95;
}
F_69 ( & V_11 -> V_94 , & V_72 ) ;
V_11 -> V_13 = V_97 [ V_70 ] . V_14 ;
V_11 -> V_63 = & V_97 [ V_70 ] ;
F_6 ( V_3 , V_11 ) ;
}
V_130 = F_99 ( V_72 . V_159 ,
struct V_10 ,
V_94 ) ;
V_32 = F_50 ( V_74 , V_91 , & V_72 ) ;
if ( V_32 )
goto V_95;
V_32 = F_36 ( V_27 , V_3 , & V_72 ) ;
if ( V_32 ) {
if ( V_32 == - V_46 ) {
V_32 = F_59 ( V_27 , V_91 , V_74 ,
& V_72 , V_3 ,
V_97 ,
args -> V_138 ) ;
F_100 ( ! F_101 ( & V_27 -> V_100 ) ) ;
}
if ( V_32 )
goto V_95;
}
if ( V_130 -> V_18 . V_42 ) {
F_19 ( L_23 ) ;
V_32 = - V_33 ;
goto V_95;
}
V_130 -> V_18 . V_43 |= V_160 ;
V_32 = F_74 ( V_74 , & V_72 ) ;
if ( V_32 )
goto V_95;
V_120 = F_102 ( V_74 ) ;
for ( V_70 = 0 ; V_70 < F_32 ( V_74 -> V_161 ) ; V_70 ++ ) {
if ( V_120 < V_74 -> V_161 [ V_70 ] ) {
V_32 = F_103 ( V_27 ) ;
if ( V_32 )
goto V_95;
F_104 ( V_27 ) ;
F_100 ( V_74 -> V_161 [ V_70 ] ) ;
}
}
V_32 = F_105 ( V_74 , V_91 , V_133 ) ;
if ( V_32 )
goto V_95;
if ( V_74 == & V_53 -> V_74 [ V_128 ] &&
V_137 != V_53 -> V_152 ) {
V_32 = F_71 ( V_74 , 4 ) ;
if ( V_32 )
goto V_95;
F_72 ( V_74 , V_108 ) ;
F_72 ( V_74 , F_93 ( 1 ) ) ;
F_72 ( V_74 , V_162 ) ;
F_72 ( V_74 , V_136 << 16 | V_137 ) ;
F_73 ( V_74 ) ;
V_53 -> V_152 = V_137 ;
}
if ( args -> V_79 & V_163 ) {
V_32 = F_91 ( V_27 , V_74 ) ;
if ( V_32 )
goto V_95;
}
F_106 ( V_74 , V_120 ) ;
V_134 = V_130 -> V_36 + args -> V_113 ;
V_135 = args -> V_114 ;
if ( V_132 ) {
for ( V_70 = 0 ; V_70 < args -> V_153 ; V_70 ++ ) {
V_32 = F_107 ( V_27 , & V_132 [ V_70 ] ,
args -> V_164 , args -> V_165 ) ;
if ( V_32 )
goto V_95;
V_32 = V_74 -> V_166 ( V_74 ,
V_134 , V_135 ) ;
if ( V_32 )
goto V_95;
}
} else {
V_32 = V_74 -> V_166 ( V_74 , V_134 , V_135 ) ;
if ( V_32 )
goto V_95;
}
F_85 ( & V_72 , V_74 , V_120 ) ;
F_89 ( V_27 , V_91 , V_74 ) ;
V_95:
F_11 ( V_3 ) ;
while ( ! F_52 ( & V_72 ) ) {
struct V_10 * V_11 ;
V_11 = F_53 ( & V_72 ,
struct V_10 ,
V_94 ) ;
F_60 ( & V_11 -> V_94 ) ;
F_61 ( & V_11 -> V_18 ) ;
}
F_62 ( & V_27 -> V_100 ) ;
V_155:
F_12 ( V_132 ) ;
return V_32 ;
}
int
F_108 ( struct V_26 * V_27 , void * V_129 ,
struct V_90 * V_91 )
{
struct V_167 * args = V_129 ;
struct V_112 V_168 ;
struct V_169 * V_94 = NULL ;
struct V_61 * V_170 = NULL ;
int V_32 , V_70 ;
if ( args -> V_138 < 1 ) {
F_19 ( L_18 , args -> V_138 ) ;
return - V_33 ;
}
V_94 = F_63 ( sizeof( * V_94 ) , args -> V_138 ) ;
V_170 = F_63 ( sizeof( * V_170 ) , args -> V_138 ) ;
if ( V_94 == NULL || V_170 == NULL ) {
F_19 ( L_24 ,
args -> V_138 ) ;
F_64 ( V_94 ) ;
F_64 ( V_170 ) ;
return - V_101 ;
}
V_32 = F_66 ( V_94 ,
( void T_4 * ) ( V_65 ) args -> V_171 ,
sizeof( * V_94 ) * args -> V_138 ) ;
if ( V_32 != 0 ) {
F_19 ( L_25 ,
args -> V_138 , V_32 ) ;
F_64 ( V_94 ) ;
F_64 ( V_170 ) ;
return - V_46 ;
}
for ( V_70 = 0 ; V_70 < args -> V_138 ; V_70 ++ ) {
V_170 [ V_70 ] . V_14 = V_94 [ V_70 ] . V_14 ;
V_170 [ V_70 ] . V_67 = V_94 [ V_70 ] . V_67 ;
V_170 [ V_70 ] . V_66 = V_94 [ V_70 ] . V_66 ;
V_170 [ V_70 ] . V_83 = V_94 [ V_70 ] . V_83 ;
V_170 [ V_70 ] . V_39 = V_94 [ V_70 ] . V_39 ;
if ( F_42 ( V_27 ) -> V_76 < 4 )
V_170 [ V_70 ] . V_79 = V_80 ;
else
V_170 [ V_70 ] . V_79 = 0 ;
}
V_168 . V_171 = args -> V_171 ;
V_168 . V_138 = args -> V_138 ;
V_168 . V_113 = args -> V_113 ;
V_168 . V_114 = args -> V_114 ;
V_168 . V_164 = args -> V_164 ;
V_168 . V_165 = args -> V_165 ;
V_168 . V_153 = args -> V_153 ;
V_168 . V_156 = args -> V_156 ;
V_168 . V_79 = V_141 ;
F_109 ( V_168 , 0 ) ;
V_32 = F_95 ( V_27 , V_129 , V_91 , & V_168 , V_170 ) ;
if ( ! V_32 ) {
for ( V_70 = 0 ; V_70 < args -> V_138 ; V_70 ++ )
V_94 [ V_70 ] . V_39 = V_170 [ V_70 ] . V_39 ;
V_32 = F_110 ( ( void T_4 * ) ( V_65 ) args -> V_171 ,
V_94 ,
sizeof( * V_94 ) * args -> V_138 ) ;
if ( V_32 ) {
V_32 = - V_46 ;
F_19 ( L_26
L_27 ,
args -> V_138 , V_32 ) ;
}
}
F_64 ( V_94 ) ;
F_64 ( V_170 ) ;
return V_32 ;
}
int
F_111 ( struct V_26 * V_27 , void * V_129 ,
struct V_90 * V_91 )
{
struct V_112 * args = V_129 ;
struct V_61 * V_170 = NULL ;
int V_32 ;
if ( args -> V_138 < 1 ||
args -> V_138 > V_154 / sizeof( * V_170 ) ) {
F_19 ( L_28 , args -> V_138 ) ;
return - V_33 ;
}
V_170 = F_98 ( sizeof( * V_170 ) * args -> V_138 ,
V_7 | V_172 | V_173 ) ;
if ( V_170 == NULL )
V_170 = F_63 ( sizeof( * V_170 ) ,
args -> V_138 ) ;
if ( V_170 == NULL ) {
F_19 ( L_24 ,
args -> V_138 ) ;
return - V_101 ;
}
V_32 = F_66 ( V_170 ,
(struct V_174 T_4 * )
( V_65 ) args -> V_171 ,
sizeof( * V_170 ) * args -> V_138 ) ;
if ( V_32 != 0 ) {
F_19 ( L_25 ,
args -> V_138 , V_32 ) ;
F_64 ( V_170 ) ;
return - V_46 ;
}
V_32 = F_95 ( V_27 , V_129 , V_91 , args , V_170 ) ;
if ( ! V_32 ) {
V_32 = F_110 ( ( void T_4 * ) ( V_65 ) args -> V_171 ,
V_170 ,
sizeof( * V_170 ) * args -> V_138 ) ;
if ( V_32 ) {
V_32 = - V_46 ;
F_19 ( L_26
L_27 ,
args -> V_138 , V_32 ) ;
}
}
F_64 ( V_170 ) ;
return V_32 ;
}
