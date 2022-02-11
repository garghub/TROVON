static int
F_1 ( void )
{
return 0 ;
}
static void
F_2 ( void )
{
}
static void
F_3 ( void )
{
int V_1 ;
int V_2 ;
if ( F_4 () ) {
V_3 =
( V_4 ) F_5 ( ( V_4 * ) F_6 ( V_5 ) ) ;
V_6 =
( V_4 ) F_5 ( ( V_4 * ) F_6 ( V_7 ) ) ;
V_8 =
( V_4 ) F_5 ( ( V_4 * ) F_6 ( V_9 ) ) ;
V_10 =
( V_4 ) F_5 ( ( V_4 * ) F_6 ( V_11 ) ) ;
F_7 (node) {
V_2 = F_8 ( V_1 ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_5 ) ,
- 1UL ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_7 ) ,
- 1UL ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_9 ) ,
- 1UL ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_11 ) ,
- 1UL ) ;
}
} else {
V_12 =
( V_4 ) F_5 ( ( V_4 * ) F_6 ( V_13 ) ) ;
F_7 (node) {
V_2 = F_8 ( V_1 ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_13 ) ,
- 1UL ) ;
}
}
}
static void
F_11 ( void )
{
int V_1 ;
int V_2 ;
if ( F_4 () ) {
F_7 (node) {
V_2 = F_8 ( V_1 ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_5 ) ,
V_3 ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_7 ) ,
V_6 ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_9 ) ,
V_8 ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_11 ) ,
V_10 ) ;
}
} else {
F_7 (node) {
V_2 = F_8 ( V_1 ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 , V_13 ) ,
V_12 ) ;
}
}
}
static V_4
F_12 ( struct V_14 * V_14 )
{
return F_13 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_16 ) ;
}
static enum V_17
F_15 ( struct V_14 * V_14 , V_4 V_18 , int V_2 , int V_19 ,
int V_20 )
{
int V_21 = 0 ;
unsigned long V_22 ;
F_16 ( V_22 ) ;
F_17 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_23 , V_18 ) ;
F_18 ( V_2 , V_19 , V_20 , 0 ) ;
V_21 = F_19 ( ( V_4 * ) F_10 ( F_20 ( & V_14 -> V_15 ) ,
V_24 ) ) ;
F_21 ( V_22 ) ;
return ( V_21 == 0 ) ? V_25 : V_26 ;
}
static struct V_14 *
F_22 ( int V_27 )
{
struct V_14 * V_14 = V_28 -> V_29 + V_27 ;
( void ) F_12 ( V_14 ) ;
return V_14 ;
}
static T_1
F_23 ( int V_30 , void * V_31 )
{
unsigned long V_22 ;
F_24 ( & V_32 , V_22 ) ;
V_33 ++ ;
F_25 ( & V_32 , V_22 ) ;
F_26 ( & V_34 ) ;
return V_35 ;
}
static void
F_27 ( unsigned long V_36 , int V_37 ,
int V_38 , int V_39 )
{
struct V_14 * V_40 = (struct V_14 * ) F_28 ( V_36 +
( V_41 *
sizeof( struct V_14 ) ) ) ;
( void ) F_15 ( & V_40 [ F_29 ( V_37 / 2 ) ] ,
F_30 ( V_37 / 2 ) , V_38 ,
V_39 , V_42 ) ;
}
static void
F_31 ( int V_37 )
{
unsigned long V_22 ;
struct V_14 * V_40 = (struct V_14 * ) F_28 ( V_28 -> V_36 +
( V_41 *
sizeof( struct V_14 ) ) ) ;
F_17 ( F_14 ( ( V_4 ) & V_40 [ F_29 ( V_37 / 2 ) ] . V_15 ) ,
V_23 , F_30 ( V_37 / 2 ) ) ;
F_24 ( & V_32 , V_22 ) ;
V_33 ++ ;
F_25 ( & V_32 , V_22 ) ;
F_26 ( & V_34 ) ;
}
static void
F_32 ( struct V_43 * V_44 )
{
union V_45 V_46 ;
unsigned long V_22 ;
V_46 . V_47 = F_12 ( V_44 -> V_48 . V_49 .
V_50 ) ;
if ( V_46 . V_47 == 0 )
return;
F_24 ( & V_44 -> V_51 , V_22 ) ;
V_44 -> V_46 . V_47 |= V_46 . V_47 ;
F_25 ( & V_44 -> V_51 , V_22 ) ;
F_33 ( V_52 , L_1
L_2 , F_34 ( V_44 ) , V_46 . V_47 ) ;
F_35 ( V_44 ) ;
}
static T_1
F_36 ( int V_30 , void * V_31 )
{
short V_53 = ( short ) ( V_4 ) V_31 ;
struct V_43 * V_44 = & V_54 [ V_53 ] ;
F_37 ( V_53 < 0 || V_53 >= V_55 ) ;
if ( F_38 ( V_44 ) ) {
F_32 ( V_44 ) ;
F_39 ( V_44 ) ;
}
return V_35 ;
}
static void
F_40 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
if ( F_38 ( V_44 ) ) {
F_32 ( V_44 ) ;
V_57 -> V_58 . V_59 = V_60 +
V_61 ;
F_41 ( & V_57 -> V_58 ) ;
F_39 ( V_44 ) ;
}
}
static void
F_42 ( struct V_62 * V_63 , T_2 V_64 ,
char * V_65 , unsigned long * V_22 )
{
struct V_43 * V_44 = & V_54 [ V_63 -> V_53 ] ;
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
union V_45 V_46 = { 0 } ;
enum V_17 V_21 ;
if ( F_43 ( V_44 -> V_66 != V_67 ) ) {
V_46 . V_68 [ V_63 -> V_69 ] = V_64 ;
V_21 = F_15 ( V_57 -> V_70 ,
V_46 . V_47 ,
V_57 -> V_71 ,
V_57 -> V_72 ,
V_73 ) ;
F_33 ( V_52 , L_3 ,
V_65 , V_63 -> V_53 , V_63 -> V_69 , V_21 ) ;
if ( F_44 ( V_21 != V_25 ) ) {
if ( V_22 != NULL )
F_25 ( & V_63 -> V_74 , * V_22 ) ;
F_45 ( V_44 , V_21 ) ;
if ( V_22 != NULL )
F_24 ( & V_63 -> V_74 , * V_22 ) ;
}
}
}
static void
F_46 ( struct V_62 * V_63 , T_2 V_64 ,
char * V_65 )
{
struct V_43 * V_44 = & V_54 [ V_63 -> V_53 ] ;
union V_45 V_46 = { 0 } ;
V_46 . V_68 [ V_63 -> V_69 ] = V_64 ;
F_17 ( F_14 ( ( V_4 ) & V_44 -> V_48 . V_49 . V_50 ->
V_15 ) , V_23 , V_46 . V_47 ) ;
F_33 ( V_52 , L_4 ,
V_65 , V_63 -> V_53 , V_63 -> V_69 ) ;
}
static void
F_47 ( struct V_62 * V_63 ,
unsigned long * V_22 )
{
struct V_75 * args = V_63 -> V_48 . V_49 . V_76 ;
args -> V_77 = V_63 -> V_77 ;
F_48 ( V_63 , V_78 , V_22 ) ;
}
static void
F_49 ( struct V_62 * V_63 , unsigned long * V_22 )
{
F_48 ( V_63 , V_79 , V_22 ) ;
}
static void
F_50 ( struct V_62 * V_63 , unsigned long * V_22 )
{
struct V_75 * args = V_63 -> V_48 . V_49 . V_76 ;
args -> V_80 = V_63 -> V_80 ;
args -> V_81 = V_63 -> V_81 ;
F_48 ( V_63 , V_82 , V_22 ) ;
}
static void
F_51 ( struct V_62 * V_63 , unsigned long * V_22 )
{
struct V_75 * args = V_63 -> V_48 . V_49 . V_76 ;
args -> V_83 = V_63 -> V_83 ;
args -> V_81 = V_63 -> V_81 ;
args -> V_84 = F_52 ( V_63 -> V_48 . V_49 . V_85 ) ;
F_48 ( V_63 , V_86 , V_22 ) ;
}
static void
F_53 ( struct V_62 * V_63 ,
unsigned long * V_22 )
{
F_48 ( V_63 , V_87 , V_22 ) ;
}
static void
F_54 ( struct V_62 * V_63 )
{
F_48 ( V_63 , V_88 , NULL ) ;
}
static void
F_55 ( struct V_62 * V_63 )
{
F_56 ( V_63 , V_88 ) ;
}
static enum V_17
F_57 ( struct V_62 * V_63 ,
unsigned long V_89 )
{
V_63 -> V_48 . V_49 . V_90 = V_89 ;
return V_25 ;
}
static void
F_58 ( struct V_43 * V_44 )
{
unsigned long V_22 ;
struct V_14 * V_14 = (struct V_14 * ) F_28 ( V_44 -> V_48 . V_49 . V_91 +
( V_92 *
sizeof( struct V_14 ) ) ) ;
F_16 ( V_22 ) ;
F_17 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_23 ,
F_59 ( V_93 ) ) ;
( void ) F_19 ( ( V_4 * ) F_10 ( F_20 ( & V_14 ->
V_15 ) ,
V_24 ) ) ;
F_21 ( V_22 ) ;
}
static void
F_60 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
unsigned long V_22 ;
struct V_14 * V_14 = (struct V_14 * ) F_28 ( V_57 -> V_91 +
( V_92 *
sizeof( struct V_14 ) ) ) ;
F_16 ( V_22 ) ;
F_17 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_94 ,
~ F_59 ( V_93 ) ) ;
( void ) F_19 ( ( V_4 * ) F_10 ( F_20 ( & V_14 ->
V_15 ) ,
V_24 ) ) ;
F_21 ( V_22 ) ;
F_27 ( V_57 -> V_91 ,
F_8 ( 0 ) ,
V_57 -> V_95 ,
V_57 -> V_96 ) ;
}
static void
F_61 ( short V_53 )
{
struct V_14 * V_14 = V_28 -> V_29 +
V_92 ;
F_17 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_94 ,
~ F_59 ( V_53 ) ) ;
}
static int
F_62 ( short V_53 )
{
struct V_14 * V_14 = V_28 -> V_29 +
V_92 ;
return ( F_13 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_97 ) &
F_59 ( V_53 ) ) != 0 ;
}
static int
F_63 ( void )
{
struct V_14 * V_14 = V_28 -> V_29 +
V_92 ;
return F_13 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_97 ) != 0 ;
}
static enum V_17
F_64 ( struct V_14 * V_29 )
{
enum V_17 V_21 = V_25 ;
if ( ! F_65 () )
V_21 = F_66 ( F_67 ( ( V_4 ) V_29 ) , V_98 ) ;
return V_21 ;
}
static void
F_68 ( void )
{
int V_1 ;
int V_2 ;
if ( ! F_65 () )
return;
F_7 (node) {
V_2 = F_8 ( V_1 ) ;
V_99 [ V_1 ] =
( V_4 ) F_5 ( ( V_4 * ) F_10 ( V_2 ,
V_100 ) ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 ,
V_100 ) ,
- 1UL ) ;
F_9 ( ( V_4 * ) F_10 ( V_2 ,
V_101 ) ,
- 1UL ) ;
}
}
static enum V_17
F_69 ( void * V_102 , V_4 * V_103 , unsigned long * V_104 ,
T_3 * V_105 )
{
T_4 V_106 ;
enum V_17 V_21 ;
V_106 = F_70 ( ( V_4 ) V_102 , V_103 ,
( V_4 * ) V_104 , ( V_4 * ) V_105 ) ;
if ( V_106 == V_107 )
V_21 = V_25 ;
else if ( V_106 == V_108 )
V_21 = V_109 ;
else
V_21 = V_110 ;
return V_21 ;
}
static int
F_71 ( struct V_111 * V_112 )
{
struct V_14 * V_29 ;
int V_113 ;
int V_21 ;
V_28 = F_72 ( V_112 ) ;
V_112 -> V_48 . V_49 . V_114 = F_52 ( V_28 ) ;
V_115 = (struct V_115 * ) ( ( T_2 * ) F_72 ( V_112 ) +
V_116 ) ;
V_29 = V_28 -> V_29 ;
if ( V_29 == NULL ) {
V_29 = (struct V_14 * ) F_14 ( F_73 ( 0 , 1 ) ) ;
if ( V_29 == NULL ) {
F_74 ( V_117 , L_5 ) ;
return - V_118 ;
}
V_21 = F_64 ( V_29 ) ;
if ( V_21 != V_25 ) {
F_74 ( V_117 , L_6 ) ;
F_75 ( V_119 |
F_76 ( ( V_4 ) V_29 ) , 1 ) ;
return - V_120 ;
}
}
memset ( V_28 , 0 , sizeof( struct V_28 ) ) ;
V_28 -> V_121 = V_122 ;
V_28 -> V_95 = F_77 ( 0 ) ;
V_28 -> V_96 = F_78 ( 0 ) ;
V_28 -> V_123 = F_52 ( V_115 ) ;
V_28 -> V_36 = F_67 ( ( V_4 ) V_29 ) ;
V_28 -> V_29 = V_29 ;
memset ( ( V_4 * ) V_115 , 0 , sizeof( struct V_115 ) *
V_55 ) ;
for ( V_113 = 0 ; V_113 < V_124 ; V_113 ++ )
( void ) F_22 ( V_41 + V_113 ) ;
( void ) F_22 ( V_92 ) ;
( void ) F_22 ( V_125 ) ;
return 0 ;
}
static int
F_79 ( short V_53 , void * V_126 )
{
return F_80 ( V_53 , V_126 ) ;
}
static void
F_81 ( short V_53 )
{
F_37 ( V_28 == NULL ) ;
F_82 ( V_53 , V_28 -> V_126 ) ;
}
static void
F_83 ( short V_53 )
{
F_37 ( V_28 == NULL ) ;
F_84 ( V_53 , V_28 -> V_126 ) ;
}
static void
F_85 ( void )
{
F_37 ( V_28 == NULL ) ;
F_86 ( V_28 -> V_126 , V_127 ) ;
}
static void
F_87 ( void )
{
V_28 -> V_128 ++ ;
}
static void
F_88 ( void )
{
F_87 () ;
V_28 -> V_129 = 1 ;
}
static void
F_89 ( void )
{
F_87 () ;
V_28 -> V_129 = 0 ;
}
static void
F_90 ( void )
{
F_37 ( V_28 == NULL ) ;
F_86 ( V_28 -> V_126 , V_55 ) ;
F_89 () ;
}
static void
F_91 ( void )
{
F_88 () ;
}
static enum V_17
F_92 ( struct V_43 * V_44 )
{
struct V_28 * V_130 ;
enum V_17 V_21 ;
V_130 = (struct V_28 * ) V_131 ;
V_21 = F_93 ( F_52 ( V_130 ) ,
V_44 -> V_48 . V_49 . V_132 ,
V_116 ) ;
if ( V_21 != V_25 )
return V_21 ;
F_33 ( V_117 , L_7
L_8 , F_34 ( V_44 ) ,
V_130 -> V_128 , V_44 -> V_133 ,
V_130 -> V_129 ,
V_130 -> V_126 [ 0 ] ) ;
if ( ( V_130 -> V_128 == V_44 -> V_133 &&
! V_130 -> V_129 ) ||
! F_79 ( V_93 ,
V_130 -> V_126 ) ) {
V_21 = V_134 ;
} else {
V_44 -> V_133 = V_130 -> V_128 ;
}
return V_21 ;
}
static enum V_17
F_94 ( unsigned long V_132 ,
struct V_28 * V_130 )
{
enum V_17 V_21 ;
if ( V_132 == 0 )
return V_135 ;
V_21 = F_93 ( F_52 ( V_130 ) , V_132 ,
V_116 ) ;
if ( V_21 != V_25 )
return V_21 ;
if ( F_95 ( V_130 -> V_121 ) !=
F_95 ( V_122 ) ) {
return V_136 ;
}
return V_25 ;
}
static void
F_96 ( struct V_111 * V_137 ,
unsigned long V_138 , int V_2 )
{
F_31 ( V_2 ) ;
}
static void
F_97 ( struct V_43 * V_44 )
{
F_31 ( V_44 -> V_48 . V_49 . V_95 ) ;
}
static void
F_98 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
unsigned long V_22 ;
struct V_14 * V_14 = (struct V_14 * ) F_28 ( V_57 -> V_91 +
( V_125 *
sizeof( struct V_14 ) ) ) ;
F_16 ( V_22 ) ;
F_17 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_23 ,
F_59 ( V_93 ) ) ;
( void ) F_19 ( ( V_4 * ) F_10 ( F_20 ( & V_14 ->
V_15 ) ,
V_24 ) ) ;
F_21 ( V_22 ) ;
F_27 ( V_57 -> V_91 ,
F_8 ( 0 ) ,
V_57 -> V_95 ,
V_57 -> V_96 ) ;
}
static void
F_99 ( struct V_43 * V_44 )
{
unsigned long V_22 ;
struct V_14 * V_14 = (struct V_14 * ) F_28 ( V_44 -> V_48 . V_49 . V_91 +
( V_125 *
sizeof( struct V_14 ) ) ) ;
F_16 ( V_22 ) ;
F_17 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_94 ,
~ F_59 ( V_93 ) ) ;
( void ) F_19 ( ( V_4 * ) F_10 ( F_20 ( & V_14 ->
V_15 ) ,
V_24 ) ) ;
F_21 ( V_22 ) ;
}
static int
F_100 ( short V_53 )
{
struct V_14 * V_14 = V_28 -> V_29 +
V_125 ;
return ( F_13 ( F_14 ( ( V_4 ) & V_14 -> V_15 ) , V_97 ) &
F_59 ( V_53 ) ) != 0 ;
}
static void
F_101 ( struct V_43 * V_44 , T_2 V_139 ,
unsigned long * V_140 ,
unsigned long V_138 ,
unsigned long V_132 ,
struct V_28 * V_130 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
V_44 -> V_139 = V_139 ;
F_33 ( V_117 , L_9 ,
V_44 -> V_139 ) ;
V_44 -> V_140 = * V_140 ;
F_33 ( V_117 , L_10 ,
V_44 -> V_140 ) ;
V_44 -> V_138 = V_138 ;
F_33 ( V_117 , L_11 , V_44 -> V_138 ) ;
V_57 -> V_132 = V_132 ;
F_33 ( V_117 , L_12 ,
V_57 -> V_132 ) ;
V_44 -> V_133 = V_130 -> V_128 - 1 ;
F_33 ( V_117 , L_13 ,
V_44 -> V_133 ) ;
V_57 -> V_141 = V_130 -> V_123 ;
F_33 ( V_117 , L_14 ,
V_57 -> V_141 ) ;
V_57 -> V_95 = V_130 -> V_95 ;
F_33 ( V_117 , L_15 ,
V_57 -> V_95 ) ;
V_57 -> V_96 =
V_130 -> V_96 ;
F_33 ( V_117 , L_16 ,
V_57 -> V_96 ) ;
V_57 -> V_91 = V_130 -> V_36 ;
F_33 ( V_117 , L_17 ,
V_57 -> V_91 ) ;
V_57 -> V_142 = V_130 -> V_121 ;
F_33 ( V_117 , L_18 ,
V_57 -> V_142 ) ;
}
static void
F_102 ( int V_2 )
{
struct V_111 * V_137 ;
struct V_28 * V_130 ;
unsigned long V_138 ;
unsigned long V_132 ;
int V_139 ;
int V_143 = 0 ;
unsigned long V_140 = 0 ;
short V_53 ;
struct V_43 * V_44 ;
struct V_56 * V_57 ;
enum V_17 V_21 ;
V_137 = (struct V_111 * ) V_131 ;
V_21 = F_103 ( V_2 , NULL , V_137 , & V_138 ) ;
if ( V_21 != V_25 ) {
F_104 ( V_117 , L_19
L_20 , V_2 , V_21 ) ;
return;
}
V_132 = V_137 -> V_48 . V_49 . V_114 ;
V_139 = V_137 -> V_121 ;
V_140 = V_137 -> V_144 ;
V_53 = V_137 -> V_145 ;
V_44 = & V_54 [ V_53 ] ;
V_57 = & V_44 -> V_48 . V_49 ;
V_130 = (struct V_28 * ) V_131 ;
V_21 = F_94 ( V_132 , V_130 ) ;
if ( V_21 != V_25 ) {
F_104 ( V_117 , L_21
L_20 , V_2 , V_21 ) ;
F_45 ( V_44 , V_21 ) ;
return;
}
V_44 -> V_146 ++ ;
F_33 ( V_117 , L_22
L_23 , ( int ) V_2 , ( int ) V_53 ,
V_44 -> V_146 ,
V_130 -> V_128 , V_130 -> V_126 [ 0 ] ) ;
if ( F_105 ( V_44 ) &&
V_44 -> V_66 == V_147 ) {
F_101 ( V_44 , V_139 ,
& V_140 ,
V_138 , V_132 ,
V_130 ) ;
if ( F_100 ( V_53 ) ) {
return;
}
F_106 ( V_44 ) ;
return;
}
F_37 ( V_44 -> V_139 == 0 ) ;
F_37 ( V_57 -> V_142 == 0 ) ;
if ( V_140 != V_44 -> V_140 ) {
F_37 ( F_62 ( V_53 ) ) ;
F_37 ( F_100 ( V_53 ) ) ;
F_101 ( V_44 , V_139 ,
& V_140 ,
V_138 , V_132 ,
V_130 ) ;
V_143 = 1 ;
}
if ( V_44 -> V_148 > 0 && ! F_105 ( V_44 ) ) {
return;
}
if ( V_143 )
F_45 ( V_44 , V_149 ) ;
else if ( F_100 ( V_53 ) )
F_45 ( V_44 , V_150 ) ;
}
int
F_107 ( void )
{
int V_151 ;
int V_152 ;
unsigned long V_153 ;
V_4 V_2 ;
int V_154 = 0 ;
struct V_14 * V_155 ;
V_155 = V_28 -> V_29 + V_41 ;
for ( V_151 = 0 ; V_151 < V_124 ; V_151 ++ ) {
if ( V_156 )
break;
V_153 = F_12 ( & V_155 [ V_151 ] ) ;
V_152 = F_108 ( & V_153 , V_157 ) ;
if ( V_152 >= V_157 ) {
continue;
}
F_33 ( V_117 , L_24 , V_151 ,
V_153 ) ;
V_158 [ V_151 ] |= V_153 ;
do {
V_154 ++ ;
V_2 = ( V_151 * V_157 + V_152 ) * 2 ;
F_33 ( V_117 , L_25 , V_2 ) ;
F_102 ( V_2 ) ;
V_152 = F_109 ( & V_153 , V_157 ,
V_152 + 1 ) ;
} while ( V_152 < V_157 );
}
return V_154 ;
}
static void
F_110 ( void )
{
unsigned long V_22 ;
int V_159 ;
int V_154 ;
F_24 ( & V_32 , V_22 ) ;
V_159 = V_33 ;
V_33 = 0 ;
F_25 ( & V_32 , V_22 ) ;
V_154 = F_107 () ;
if ( V_154 < V_159 ) {
( void ) F_107 () ;
}
}
static enum V_17
F_111 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
struct V_160 * V_161 ;
enum V_17 V_162 ;
int V_21 ;
int V_163 ;
int V_164 ;
struct V_165 * V_166 ;
short V_53 = F_34 ( V_44 ) ;
V_57 -> V_167 =
F_112 ( V_168 , V_169 ,
& V_57 -> V_170 ) ;
if ( V_57 -> V_167 == NULL ) {
F_74 ( V_52 , L_26
L_27 ) ;
return V_171 ;
}
V_57 -> V_172 =
F_112 ( V_168 , V_169 ,
& V_57 -> V_173 ) ;
if ( V_57 -> V_172 == NULL ) {
F_74 ( V_52 , L_28
L_27 ) ;
V_162 = V_171 ;
goto V_174;
}
V_57 -> V_175 = 0 ;
V_57 -> V_76 =
F_112 ( V_176 ,
V_169 , & V_57 ->
V_177 ) ;
if ( V_57 -> V_76 == NULL ) {
F_74 ( V_52 , L_29 ) ;
V_162 = V_171 ;
goto V_178;
}
V_57 -> V_179 = 0 ;
V_57 -> V_50 = F_22 ( V_53 ) ;
V_57 -> V_71 = 0 ;
V_57 -> V_72 = 0 ;
V_57 -> V_70 = NULL ;
sprintf ( V_57 -> V_180 , L_30 , V_53 ) ;
V_21 = F_113 ( V_73 , F_36 ,
V_181 , V_57 -> V_180 ,
( void * ) ( V_4 ) V_53 ) ;
if ( V_21 != 0 ) {
F_74 ( V_52 , L_31
L_32 , - V_21 ) ;
V_162 = V_182 ;
goto V_183;
}
V_166 = & V_57 -> V_58 ;
F_114 ( V_166 ) ;
V_166 -> V_184 =
( void (*) ( unsigned long ) ) F_40 ;
V_166 -> V_185 = ( unsigned long ) V_44 ;
V_166 -> V_59 = V_60 + V_61 ;
F_41 ( V_166 ) ;
for ( V_164 = 0 ; V_164 < V_44 -> V_186 ; V_164 ++ ) {
V_161 = & V_44 -> V_187 [ V_164 ] . V_48 . V_49 ;
V_161 -> V_188 = & V_57 -> V_167 [ V_164 ] ;
V_161 -> V_76 =
& V_57 -> V_76 [ V_164 ] ;
F_115 ( & V_161 -> V_189 ) ;
}
V_115 [ V_53 ] . V_190 = F_52 ( V_57 -> V_167 ) ;
V_115 [ V_53 ] . V_191 =
F_52 ( V_57 -> V_76 ) ;
V_115 [ V_53 ] . V_192 =
F_52 ( V_57 -> V_50 ) ;
V_163 = F_116 () ;
V_115 [ V_53 ] . V_71 = F_77 ( V_163 ) ;
V_115 [ V_53 ] . V_72 =
F_78 ( V_163 ) ;
V_115 [ V_53 ] . V_186 = V_44 -> V_186 ;
V_115 [ V_53 ] . V_193 = V_194 ;
return V_25 ;
V_183:
F_117 ( V_57 -> V_177 ) ;
V_57 -> V_76 = NULL ;
V_178:
F_117 ( V_57 -> V_173 ) ;
V_57 -> V_172 = NULL ;
V_174:
F_117 ( V_57 -> V_170 ) ;
V_57 -> V_167 = NULL ;
return V_162 ;
}
static void
F_118 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
short V_53 = F_34 ( V_44 ) ;
V_115 [ V_53 ] . V_193 = 0 ;
F_119 ( & V_57 -> V_58 ) ;
F_120 ( V_73 , ( void * ) ( V_4 ) V_53 ) ;
F_117 ( V_57 -> V_177 ) ;
V_57 -> V_76 = NULL ;
F_117 ( V_57 -> V_173 ) ;
V_57 -> V_172 = NULL ;
F_117 ( V_57 -> V_170 ) ;
V_57 -> V_167 = NULL ;
V_57 -> V_50 = NULL ;
}
static enum V_17
F_121 ( struct V_43 * V_44 , void * V_195 ,
const unsigned long V_196 , T_3 V_197 )
{
enum V_17 V_21 ;
F_37 ( V_196 != F_122 ( V_196 ) ) ;
F_37 ( ( unsigned long ) V_195 != F_122 ( ( unsigned long ) V_195 ) ) ;
F_37 ( V_197 != F_122 ( V_197 ) ) ;
if ( V_44 -> V_66 == V_67 )
return V_44 -> V_77 ;
V_21 = F_93 ( F_52 ( V_195 ) , V_196 , V_197 ) ;
if ( V_21 != V_25 ) {
F_33 ( V_52 , L_33
L_34 , F_34 ( V_44 ) , V_21 ) ;
}
return V_21 ;
}
static enum V_17
F_123 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
T_2 V_198 [ V_199 * 2 ] ;
struct V_115 * V_200 =
(struct V_115 * ) F_122 ( ( V_4 ) V_198 ) ;
struct V_115 * V_201 ;
unsigned long V_202 ;
unsigned long V_203 ;
short V_53 = F_34 ( V_44 ) ;
enum V_17 V_21 ;
F_37 ( V_57 -> V_141 !=
F_122 ( V_57 -> V_141 ) ) ;
F_37 ( sizeof( struct V_115 ) != V_199 / 2 ) ;
V_203 = V_57 -> V_141 +
V_93 * sizeof( struct V_115 ) ;
V_202 = ( V_203 & ~ ( V_199 - 1 ) ) ;
V_201 = (struct V_115 * ) ( ( V_4 ) V_200
+ ( V_203 &
( V_199 - 1 ) ) ) ;
V_21 = F_121 ( V_44 , V_200 ,
V_202 ,
V_199 ) ;
if ( V_21 != V_25 ) {
F_33 ( V_52 , L_35
L_36 , V_53 , V_21 ) ;
return V_21 ;
}
if ( V_201 -> V_193 != V_194 &&
V_201 -> V_193 != V_204 ) {
if ( V_201 -> V_193 != 0 ) {
F_33 ( V_52 , L_37
L_38 ,
V_53 , V_93 , V_201 -> V_193 ) ;
return V_205 ;
}
return V_206 ;
}
if ( V_115 [ V_53 ] . V_193 == V_194 ) {
if ( V_201 -> V_190 == 0 ||
V_201 -> V_191 == 0 ||
V_201 -> V_192 == 0 ) {
F_74 ( V_52 , L_37
L_39 , V_53 ,
V_93 ) ;
return V_207 ;
}
V_57 -> V_175 = V_201 -> V_190 ;
V_57 -> V_179 =
V_201 -> V_191 ;
V_57 -> V_70 =
(struct V_14 * ) F_28 ( V_201 -> V_192 ) ;
V_57 -> V_71 = V_201 -> V_71 ;
V_57 -> V_72 =
V_201 -> V_72 ;
if ( V_44 -> V_186 > V_201 -> V_186 )
V_44 -> V_186 = V_201 -> V_186 ;
V_115 [ V_53 ] . V_193 = V_204 ;
}
if ( V_201 -> V_193 == V_194 )
return V_206 ;
return V_25 ;
}
static enum V_17
F_124 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
enum V_17 V_21 ;
if ( F_125 ( V_57 -> V_91 ,
V_98 , 1 ) < 0 ) {
F_104 ( V_117 , L_40
L_41 , F_34 ( V_44 ) ) ;
V_21 = V_208 ;
F_45 ( V_44 , V_21 ) ;
return V_21 ;
}
F_27 ( V_57 -> V_91 ,
F_8 ( 0 ) ,
V_57 -> V_95 ,
V_57 -> V_96 ) ;
while ( ( V_21 = F_123 ( V_44 ) ) != V_25 ) {
if ( V_21 != V_206 ) {
F_45 ( V_44 , V_21 ) ;
return V_21 ;
}
F_33 ( V_117 , L_42
L_43 , F_34 ( V_44 ) ) ;
( void ) F_126 ( 250 ) ;
if ( V_44 -> V_66 == V_67 )
return V_44 -> V_77 ;
}
return V_25 ;
}
static V_4
F_127 ( struct V_43 * V_44 )
{
struct V_56 * V_57 = & V_44 -> V_48 . V_49 ;
unsigned long V_22 ;
union V_45 V_46 ;
enum V_17 V_21 ;
F_24 ( & V_44 -> V_51 , V_22 ) ;
V_46 = V_44 -> V_46 ;
if ( V_46 . V_47 != 0 )
V_44 -> V_46 . V_47 = 0 ;
F_25 ( & V_44 -> V_51 , V_22 ) ;
if ( F_128 ( & V_46 ) ) {
V_21 = F_121 ( V_44 , V_44 ->
V_209 ,
V_57 ->
V_179 ,
V_176 ) ;
if ( V_21 != V_25 ) {
F_45 ( V_44 , V_21 ) ;
F_33 ( V_52 , L_44
L_36 , F_34 ( V_44 ) ,
V_21 ) ;
V_46 . V_47 = 0 ;
}
}
if ( F_129 ( & V_46 ) ) {
V_21 = F_121 ( V_44 , V_57 -> V_172 ,
V_57 -> V_175 ,
V_168 ) ;
if ( V_21 != V_25 ) {
F_45 ( V_44 , V_21 ) ;
F_33 ( V_52 , L_45
L_46 , F_34 ( V_44 ) , V_21 ) ;
V_46 . V_47 = 0 ;
}
}
return V_46 . V_47 ;
}
static enum V_17
F_130 ( struct V_62 * V_63 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
unsigned long V_22 ;
int V_210 ;
T_3 V_211 ;
for ( V_210 = V_63 -> V_81 ; V_210 > 0 ; V_210 -- ) {
V_211 = V_210 * V_63 -> V_80 ;
V_161 -> V_85 =
F_112 ( V_211 , V_169 ,
& V_161 -> V_212 ) ;
if ( V_161 -> V_85 == NULL )
continue;
V_211 = V_210 * sizeof( struct V_213 ) ;
V_161 -> V_214 = F_131 ( V_211 , V_169 ) ;
if ( V_161 -> V_214 == NULL ) {
F_117 ( V_161 -> V_212 ) ;
V_161 -> V_85 = NULL ;
continue;
}
F_24 ( & V_63 -> V_74 , V_22 ) ;
if ( V_210 < V_63 -> V_81 ) {
F_33 ( V_52 , L_47
L_48 , V_210 ,
V_63 -> V_81 , V_63 -> V_53 , V_63 -> V_69 ) ;
V_63 -> V_81 = V_210 ;
}
F_25 ( & V_63 -> V_74 , V_22 ) ;
return V_25 ;
}
F_33 ( V_52 , L_49
L_50 , V_63 -> V_53 , V_63 -> V_69 ) ;
return V_171 ;
}
static enum V_17
F_132 ( struct V_62 * V_63 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
unsigned long V_22 ;
int V_210 ;
T_3 V_211 ;
F_37 ( V_63 -> V_83 <= 0 ) ;
for ( V_210 = V_63 -> V_83 ; V_210 > 0 ; V_210 -- ) {
V_211 = V_210 * V_63 -> V_80 ;
V_161 -> V_215 =
F_112 ( V_211 , V_169 , & V_161 ->
V_216 ) ;
if ( V_161 -> V_215 == NULL )
continue;
F_24 ( & V_63 -> V_74 , V_22 ) ;
if ( V_210 < V_63 -> V_83 ) {
F_33 ( V_52 , L_51
L_48 , V_210 ,
V_63 -> V_83 , V_63 -> V_53 , V_63 -> V_69 ) ;
V_63 -> V_83 = V_210 ;
}
F_25 ( & V_63 -> V_74 , V_22 ) ;
return V_25 ;
}
F_33 ( V_52 , L_52
L_48 , V_63 -> V_53 , V_63 -> V_69 ) ;
return V_171 ;
}
static enum V_17
F_133 ( struct V_62 * V_63 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
enum V_17 V_21 ;
F_37 ( V_63 -> V_68 & V_217 ) ;
V_21 = F_130 ( V_63 ) ;
if ( V_21 == V_25 ) {
V_21 = F_132 ( V_63 ) ;
if ( V_21 != V_25 ) {
F_117 ( V_161 -> V_212 ) ;
V_161 -> V_85 = NULL ;
F_117 ( V_161 -> V_214 ) ;
V_161 -> V_214 = NULL ;
}
}
return V_21 ;
}
static void
F_134 ( struct V_62 * V_63 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
F_37 ( ! F_135 ( & V_63 -> V_74 ) ) ;
V_161 -> V_90 = 0 ;
V_161 -> V_188 -> V_218 = 0 ;
V_161 -> V_188 -> V_219 = 0 ;
V_161 -> V_220 . V_218 = 0 ;
V_161 -> V_220 . V_219 = 0 ;
V_161 -> V_221 . V_218 = 0 ;
V_161 -> V_221 . V_219 = 0 ;
V_161 -> V_222 . V_218 = 0 ;
V_161 -> V_222 . V_219 = 0 ;
V_161 -> V_223 = 0 ;
if ( V_63 -> V_68 & V_217 ) {
F_33 ( V_52 , L_53 ,
V_63 -> V_68 , V_63 -> V_53 , V_63 -> V_69 ) ;
F_117 ( V_161 -> V_212 ) ;
V_161 -> V_85 = NULL ;
F_117 ( V_161 -> V_216 ) ;
V_161 -> V_215 = NULL ;
F_117 ( V_161 -> V_214 ) ;
V_161 -> V_214 = NULL ;
}
}
static void
F_136 ( struct V_62 * V_63 , enum V_17 V_77 , T_4 V_219 )
{
struct V_213 * V_224 ;
T_2 V_225 ;
T_4 V_218 = V_63 -> V_48 . V_49 . V_222 . V_218 - 1 ;
while ( ++ V_218 < V_219 && V_226 ( & V_63 -> V_227 ) > 0 ) {
V_224 = & V_63 -> V_48 . V_49 . V_214 [ V_218 % V_63 -> V_81 ] ;
V_225 = V_224 -> type ;
if ( V_225 == 0 ||
F_137 ( & V_224 -> type , V_225 , 0 ) != V_225 ) {
continue;
}
F_37 ( V_225 != V_228 ) ;
F_138 ( & V_63 -> V_227 ) ;
if ( V_224 -> V_229 != NULL ) {
F_33 ( V_52 , L_54
L_55 ,
( void * ) V_224 , V_218 , V_63 -> V_53 , V_63 -> V_69 ) ;
V_224 -> V_229 ( V_77 , V_63 -> V_53 , V_63 -> V_69 ,
V_224 -> V_230 ) ;
F_33 ( V_52 , L_56
L_57 ,
( void * ) V_224 , V_218 , V_63 -> V_53 , V_63 -> V_69 ) ;
}
}
}
static void
F_139 ( struct V_62 * V_63 )
{
F_136 ( V_63 , V_63 -> V_77 , V_63 -> V_48 . V_49 . V_221 . V_219 ) ;
}
static inline void
F_140 ( struct V_62 * V_63 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
struct V_231 * V_232 ;
T_4 V_218 ;
V_218 = V_161 -> V_222 . V_218 ;
do {
V_232 = (struct V_231 * ) ( ( V_4 ) V_161 -> V_85 +
( V_218 % V_63 -> V_81 ) *
V_63 -> V_80 ) ;
F_37 ( ! ( V_232 -> V_68 & V_233 ) ) ;
V_232 -> V_68 = 0 ;
} while ( ++ V_218 < V_161 -> V_220 . V_218 );
}
static inline void
F_141 ( struct V_62 * V_63 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
struct V_231 * V_232 ;
T_4 V_219 , V_83 = V_63 -> V_83 ;
if ( V_161 -> V_220 . V_219 < V_83 )
return;
V_219 = F_142 ( V_161 -> V_222 . V_219 , V_83 ) ;
do {
V_232 = (struct V_231 * ) ( ( V_4 ) V_161 -> V_215 +
( V_219 % V_83 ) *
V_63 -> V_80 ) ;
F_37 ( ! ( V_232 -> V_68 & V_233 ) ) ;
F_37 ( ! ( V_232 -> V_68 & V_234 ) ) ;
F_37 ( V_232 -> V_69 != V_219 - V_83 ) ;
V_232 -> V_68 = 0 ;
} while ( ++ V_219 < V_161 -> V_220 . V_219 );
}
static int
F_143 ( struct V_62 * V_63 )
{
return V_63 -> V_48 . V_49 . V_222 . V_219 - V_63 -> V_48 . V_49 . V_221 . V_218 ;
}
static void
F_144 ( struct V_43 * V_44 , int V_164 )
{
struct V_62 * V_63 = & V_44 -> V_187 [ V_164 ] ;
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
int V_235 ;
V_161 -> V_220 = V_44 -> V_48 . V_49 . V_172 [ V_164 ] ;
F_145 ( V_63 ) ;
if ( V_161 -> V_222 . V_218 == V_161 -> V_220 . V_218 &&
V_161 -> V_222 . V_219 == V_161 -> V_220 . V_219 ) {
F_146 ( V_63 ) ;
return;
}
if ( ! ( V_63 -> V_68 & V_236 ) ) {
F_146 ( V_63 ) ;
return;
}
if ( V_161 -> V_222 . V_218 != V_161 -> V_220 . V_218 ) {
if ( V_226 ( & V_63 -> V_227 ) > 0 ) {
F_136 ( V_63 , V_237 ,
V_161 -> V_220 . V_218 ) ;
}
F_140 ( V_63 ) ;
V_161 -> V_222 . V_218 = V_161 -> V_220 . V_218 ;
F_33 ( V_52 , L_58
L_59 , V_161 -> V_222 . V_218 , V_63 -> V_53 ,
V_63 -> V_69 ) ;
if ( V_226 ( & V_63 -> V_238 ) > 0 )
F_147 ( & V_63 -> V_239 ) ;
}
if ( V_161 -> V_222 . V_219 != V_161 -> V_220 . V_219 ) {
F_141 ( V_63 ) ;
F_148 () ;
V_161 -> V_222 . V_219 = V_161 -> V_220 . V_219 ;
F_33 ( V_52 , L_60
L_59 , V_161 -> V_222 . V_219 , V_63 -> V_53 ,
V_63 -> V_69 ) ;
V_235 = F_143 ( V_63 ) ;
if ( V_235 > 0 ) {
F_33 ( V_52 , L_61
L_62 ,
V_235 , V_63 -> V_53 , V_63 -> V_69 ) ;
if ( V_63 -> V_68 & V_240 )
F_149 ( V_63 , V_235 ) ;
}
}
F_146 ( V_63 ) ;
}
static struct V_231 *
F_150 ( struct V_62 * V_63 , T_4 V_218 )
{
struct V_43 * V_44 = & V_54 [ V_63 -> V_53 ] ;
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
unsigned long V_241 ;
struct V_231 * V_232 ;
T_5 V_242 ;
T_5 V_243 ;
V_4 V_244 ;
enum V_17 V_21 ;
if ( F_151 ( & V_161 -> V_189 ) != 0 ) {
return NULL ;
}
while ( V_218 >= V_161 -> V_223 ) {
V_242 = V_161 -> V_223 % V_63 -> V_83 ;
F_37 ( V_161 -> V_223 >= V_161 -> V_222 . V_219 ) ;
V_243 = V_161 -> V_222 . V_219 - V_161 -> V_223 ;
if ( V_242 + V_243 > V_63 -> V_83 ) {
V_243 = V_63 -> V_83 - V_242 ;
}
V_244 = V_242 * V_63 -> V_80 ;
V_232 = (struct V_231 * ) ( ( V_4 ) V_161 -> V_215 +
V_244 ) ;
V_241 = V_161 -> V_90 + V_244 ;
V_21 = F_121 ( V_44 , V_232 , V_241 ,
V_243 * V_63 -> V_80 ) ;
if ( V_21 != V_25 ) {
F_33 ( V_52 , L_63
L_64
L_65 , V_243 , V_161 -> V_223 ,
V_63 -> V_53 , V_63 -> V_69 , V_21 ) ;
F_45 ( V_44 , V_21 ) ;
F_152 ( & V_161 -> V_189 ) ;
return NULL ;
}
V_161 -> V_223 += V_243 ;
}
F_152 ( & V_161 -> V_189 ) ;
V_244 = ( V_218 % V_63 -> V_83 ) * V_63 -> V_80 ;
V_232 = (struct V_231 * ) ( ( V_4 ) V_161 -> V_215 + V_244 ) ;
return V_232 ;
}
static void *
F_153 ( struct V_62 * V_63 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
struct V_231 * V_232 ;
void * V_245 = NULL ;
T_4 V_218 ;
do {
if ( V_63 -> V_68 & V_246 )
break;
V_218 = V_161 -> V_221 . V_218 ;
F_154 () ;
if ( V_218 == V_161 -> V_222 . V_219 )
break;
if ( F_137 ( & V_161 -> V_221 . V_218 , V_218 , V_218 + 1 ) == V_218 ) {
F_33 ( V_52 , L_66
L_48 , V_218 + 1 ,
V_63 -> V_53 , V_63 -> V_69 ) ;
V_232 = F_150 ( V_63 , V_218 ) ;
if ( V_232 != NULL ) {
F_37 ( V_232 -> V_69 != V_218 ) ;
F_37 ( V_232 -> V_68 & V_234 ) ;
F_37 ( ! ( V_232 -> V_68 & V_233 ) ) ;
V_245 = & V_232 -> V_245 ;
}
break;
}
} while ( 1 );
return V_245 ;
}
static void
F_155 ( struct V_62 * V_63 , T_4 V_247 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
struct V_231 * V_232 ;
T_4 V_219 = V_247 + 1 ;
int V_248 = 0 ;
while ( 1 ) {
while ( 1 ) {
if ( V_219 == V_161 -> V_221 . V_219 )
break;
V_232 = (struct V_231 * ) ( ( V_4 ) V_161 ->
V_85 + ( V_219 %
V_63 -> V_81 ) *
V_63 -> V_80 ) ;
if ( ! ( V_232 -> V_68 & V_233 ) )
break;
V_219 ++ ;
}
if ( V_219 == V_247 ) {
break;
}
if ( F_156 ( & V_161 -> V_188 -> V_219 , V_247 , V_219 ) !=
V_247 ) {
F_37 ( V_161 -> V_188 -> V_219 < V_247 ) ;
break;
}
F_33 ( V_52 , L_67
L_59 , V_219 , V_63 -> V_53 , V_63 -> V_69 ) ;
V_248 = 1 ;
V_247 = V_219 ;
}
if ( V_248 )
F_54 ( V_63 ) ;
}
static enum V_17
F_157 ( struct V_62 * V_63 , T_5 V_68 ,
struct V_231 * * V_249 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
struct V_231 * V_232 ;
enum V_17 V_21 ;
T_4 V_219 ;
V_21 = V_250 ;
while ( 1 ) {
V_219 = V_161 -> V_221 . V_219 ;
F_154 () ;
if ( V_219 - V_161 -> V_222 . V_218 < V_63 -> V_81 ) {
if ( F_137 ( & V_161 -> V_221 . V_219 , V_219 , V_219 + 1 ) ==
V_219 ) {
break;
}
continue;
}
if ( V_21 == V_250 )
F_55 ( V_63 ) ;
if ( V_68 & V_251 )
return V_252 ;
V_21 = F_158 ( V_63 ) ;
if ( V_21 != V_253 && V_21 != V_250 )
return V_21 ;
}
V_232 = (struct V_231 * ) ( ( V_4 ) V_161 -> V_85 +
( V_219 % V_63 -> V_81 ) *
V_63 -> V_80 ) ;
F_37 ( V_232 -> V_68 != 0 ) ;
V_232 -> V_69 = V_219 ;
F_33 ( V_52 , L_68
L_69 , V_219 + 1 ,
( void * ) V_232 , V_232 -> V_69 , V_63 -> V_53 , V_63 -> V_69 ) ;
* V_249 = V_232 ;
return V_25 ;
}
static enum V_17
F_159 ( struct V_62 * V_63 , T_5 V_68 , void * V_245 ,
T_6 V_254 , T_2 V_225 , T_7 V_229 ,
void * V_230 )
{
enum V_17 V_21 = V_25 ;
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
struct V_231 * V_232 = V_232 ;
struct V_213 * V_224 = V_224 ;
T_4 V_255 ;
T_4 V_219 ;
F_37 ( V_225 == V_228 && V_229 == NULL ) ;
if ( F_160 ( V_254 ) > V_63 -> V_80 )
return V_256 ;
F_145 ( V_63 ) ;
if ( V_63 -> V_68 & V_246 ) {
V_21 = V_63 -> V_77 ;
goto V_174;
}
if ( ! ( V_63 -> V_68 & V_236 ) ) {
V_21 = V_257 ;
goto V_174;
}
V_21 = F_157 ( V_63 , V_68 , & V_232 ) ;
if ( V_21 != V_25 )
goto V_174;
V_255 = V_232 -> V_69 ;
if ( V_225 != 0 ) {
V_232 -> V_68 |= V_258 ;
F_161 ( & V_63 -> V_227 ) ;
V_224 = & V_161 -> V_214 [ V_255 % V_63 -> V_81 ] ;
V_224 -> V_229 = V_229 ;
V_224 -> V_230 = V_230 ;
V_224 -> type = V_225 ;
if ( V_63 -> V_68 & V_246 ) {
if ( F_137 ( & V_224 -> type , V_225 , 0 ) ==
V_225 ) {
F_138 ( & V_63 -> V_227 ) ;
V_21 = V_63 -> V_77 ;
}
goto V_174;
}
}
memcpy ( & V_232 -> V_245 , V_245 , V_254 ) ;
V_232 -> V_68 |= V_233 ;
F_162 () ;
V_219 = V_161 -> V_188 -> V_219 ;
if ( V_219 == V_255 )
F_155 ( V_63 , V_219 ) ;
V_174:
F_146 ( V_63 ) ;
return V_21 ;
}
static void
F_163 ( struct V_62 * V_63 , T_4 V_259 , T_2 V_260 )
{
struct V_160 * V_161 = & V_63 -> V_48 . V_49 ;
struct V_231 * V_232 ;
T_4 V_218 = V_259 + 1 ;
int V_248 = 0 ;
while ( 1 ) {
while ( 1 ) {
if ( V_218 == V_161 -> V_221 . V_218 )
break;
V_232 = (struct V_231 * ) ( ( V_4 ) V_161 ->
V_215 + ( V_218 %
V_63 -> V_83 ) *
V_63 -> V_80 ) ;
if ( ! ( V_232 -> V_68 & V_234 ) )
break;
V_260 |= V_232 -> V_68 ;
V_218 ++ ;
}
if ( V_218 == V_259 ) {
break;
}
if ( F_156 ( & V_161 -> V_188 -> V_218 , V_259 , V_218 ) !=
V_259 ) {
F_37 ( V_161 -> V_188 -> V_218 <= V_259 ) ;
break;
}
F_33 ( V_52 , L_70
L_59 , V_218 , V_63 -> V_53 , V_63 -> V_69 ) ;
V_248 = ( V_260 & V_258 ) ;
V_259 = V_218 ;
}
if ( V_248 )
F_54 ( V_63 ) ;
}
static void
F_164 ( struct V_62 * V_63 , void * V_245 )
{
struct V_231 * V_232 ;
T_4 V_255 ;
T_4 V_218 ;
V_232 = F_165 ( V_245 , struct V_231 , V_245 ) ;
V_255 = V_232 -> V_69 ;
F_33 ( V_52 , L_71 ,
( void * ) V_232 , V_255 , V_63 -> V_53 , V_63 -> V_69 ) ;
F_37 ( ( ( ( V_4 ) V_232 - ( V_4 ) V_63 -> V_48 . V_49 . V_215 ) / V_63 -> V_80 ) !=
V_255 % V_63 -> V_83 ) ;
F_37 ( ! ( V_232 -> V_68 & V_233 ) ) ;
F_37 ( V_232 -> V_68 & V_234 ) ;
V_232 -> V_68 |= V_234 ;
F_162 () ;
V_218 = V_63 -> V_48 . V_49 . V_188 -> V_218 ;
if ( V_218 == V_255 )
F_163 ( V_63 , V_218 , V_232 -> V_68 ) ;
}
int
F_166 ( void )
{
int V_21 ;
T_3 V_261 ;
V_262 = V_263 ;
if ( F_167 ( struct V_231 , V_245 ) > V_264 ) {
F_74 ( V_117 , L_72
L_73 , V_264 ) ;
return - V_265 ;
}
V_261 = F_142 ( V_116 ,
V_266 + V_267 ) ;
V_131 = F_168 ( V_261 ,
V_169 ,
& V_268 ) ;
if ( V_131 == NULL ) {
F_74 ( V_117 , L_74 ) ;
return - V_118 ;
}
F_3 () ;
F_68 () ;
V_21 = F_113 ( V_42 , F_23 , 0 ,
L_75 , NULL ) ;
if ( V_21 != 0 ) {
F_74 ( V_117 , L_76
L_32 , - V_21 ) ;
F_11 () ;
F_117 ( V_268 ) ;
}
return V_21 ;
}
void
F_169 ( void )
{
F_120 ( V_42 , NULL ) ;
F_11 () ;
F_117 ( V_268 ) ;
}
