static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 ) ;
V_2 = 1 ;
return 0 ;
}
static int F_3 ( struct V_3 * V_4 , int V_5 , int V_6 )
{
return ( V_5 >= V_4 -> V_7 && V_5 < V_4 -> V_7 + V_4 -> V_8 ) &&
( V_6 >= V_4 -> V_9 && V_6 < V_4 -> V_9 + V_4 -> V_10 ) ;
}
static int F_4 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
int V_5 , V_6 , V_13 , V_14 , V_15 ;
V_14 = F_5 ( F_6 ( V_12 ) , V_16 ) ;
V_15 = F_7 ( F_6 ( V_12 ) , V_16 ) ;
V_4 -> V_7 = F_8 ( V_14 ) ;
V_4 -> V_9 = F_9 ( V_14 ) ;
V_4 -> V_8 = F_8 ( V_15 ) - V_4 -> V_7 + 1 ;
V_4 -> V_10 = F_9 ( V_15 ) - V_4 -> V_9 + 1 ;
F_10 ( & V_4 -> V_11 , V_12 ) ;
V_4 -> V_17 = V_14 ;
if ( V_4 -> V_8 <= 0 || V_4 -> V_10 <= 0 )
return - V_18 ;
for ( V_6 = 0 , V_13 = 0 ; V_6 < V_19 ; ++ V_6 )
for ( V_5 = 0 ; V_5 < V_20 ; ++ V_5 , ++ V_13 )
if ( F_11 ( V_13 , V_12 ) != F_3 ( V_4 , V_5 , V_6 ) )
return - V_18 ;
return 0 ;
}
static int F_12 ( struct V_3 * V_21 , struct V_3 * V_22 )
{
return V_21 -> V_7 + V_21 -> V_8 > V_22 -> V_7 &&
V_22 -> V_7 + V_22 -> V_8 > V_21 -> V_7 &&
V_21 -> V_9 + V_21 -> V_10 > V_22 -> V_9 &&
V_22 -> V_9 + V_22 -> V_10 > V_21 -> V_9 ;
}
static void F_13 ( void )
{
F_14 ( V_23 ) ;
}
static void F_15 ( void )
{
F_16 ( V_23 ) ;
}
static void F_17 ( void * V_24 )
{
struct V_3 * V_4 = V_24 ;
int V_13 = F_18 () ;
int V_5 = V_13 % V_20 ;
int V_6 = V_13 / V_20 ;
int V_25 = 0 ;
if ( V_5 == V_4 -> V_7 )
V_25 |= V_26 ;
if ( V_5 == V_4 -> V_7 + V_4 -> V_8 - 1 )
V_25 |= V_27 ;
if ( V_6 == V_4 -> V_9 )
V_25 |= V_28 ;
if ( V_6 == V_4 -> V_9 + V_4 -> V_10 - 1 )
V_25 |= V_29 ;
F_19 ( V_25 == 0 ) ;
F_20 ( V_30 , V_25 ) ;
F_13 () ;
}
static void F_21 ( struct V_3 * V_4 )
{
int V_5 , V_6 , V_13 , V_31 ;
struct V_11 V_32 ;
F_22 ( & V_32 ) ;
V_13 = V_4 -> V_9 * V_20 + V_4 -> V_7 ;
V_31 = ( V_4 -> V_10 - 1 ) * V_20 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_8 ; ++ V_5 , ++ V_13 ) {
F_23 ( V_13 , & V_32 ) ;
F_23 ( V_13 + V_31 , & V_32 ) ;
}
V_13 -= V_4 -> V_8 ;
V_31 = V_4 -> V_8 - 1 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_10 ; ++ V_6 , V_13 += V_20 ) {
F_23 ( V_13 , & V_32 ) ;
F_23 ( V_13 + V_31 , & V_32 ) ;
}
F_24 ( & V_32 , F_17 , V_4 , 1 ) ;
}
void T_2 F_25 ( struct V_33 * V_34 , int V_35 )
{
struct V_3 * V_36 ;
struct V_37 * V_38 ;
struct V_39 V_24 ;
int V_5 , V_6 ;
int V_13 = F_18 () ;
int V_40 ;
unsigned long V_41 ;
struct V_33 * V_42 = F_26 ( V_34 ) ;
F_27 () ;
V_5 = V_13 % V_20 ;
V_6 = V_13 / V_20 ;
F_28 ( & V_43 , V_41 ) ;
F_29 (rect, &rectangles, list) {
if ( F_3 ( V_36 , V_5 , V_6 ) )
break;
}
F_19 ( & V_36 -> V_44 == & V_45 ) ;
if ( V_36 -> V_46 ) {
F_30 ( L_2
L_3 ,
V_13 , ( long ) F_31 ( V_30 ) ) ;
goto V_47;
}
V_36 -> V_46 = 1 ;
F_32 () ;
F_30 ( L_4 ,
V_13 , ( long ) F_31 ( V_30 ) ) ;
V_24 . V_48 = V_49 ;
V_24 . V_50 = 0 ;
V_24 . V_51 = V_52 ;
V_40 = 0 ;
F_29 (p, &rect->task_head, thread.hardwall_list) {
F_19 ( V_38 -> V_53 . V_54 != V_36 ) ;
if ( ! ( V_38 -> V_41 & V_55 ) ) {
V_40 = 1 ;
F_30 ( L_5 , V_38 -> V_56 ) ;
F_33 ( V_24 . V_48 , & V_24 , V_38 , false ) ;
}
}
if ( ! V_40 )
F_30 ( L_6 ) ;
V_47:
F_34 ( & V_43 , V_41 ) ;
F_15 () ;
F_35 () ;
F_26 ( V_42 ) ;
}
void F_36 ( void )
{
F_20 ( V_57 , 1 ) ;
F_20 ( V_58 , 1 ) ;
F_20 ( V_59 , 1 ) ;
F_20 ( V_60 , 1 ) ;
#if ! F_37 ()
F_20 ( V_61 , 1 ) ;
F_20 ( V_62 , 1 ) ;
#endif
}
void F_38 ( void )
{
F_20 ( V_63 , 1 ) ;
F_20 ( V_64 , 1 ) ;
F_20 ( V_65 , 1 ) ;
F_20 ( V_66 , 1 ) ;
#if ! F_37 ()
F_20 ( V_67 , 1 ) ;
F_20 ( V_68 , 1 ) ;
#endif
}
static struct V_3 * F_39 (
T_3 V_69 , const unsigned char T_4 * V_25 )
{
struct V_3 * V_70 , * V_36 ;
struct V_11 V_12 ;
unsigned long V_41 ;
int V_71 ;
if ( V_69 > V_72 )
return F_40 ( - V_18 ) ;
if ( F_41 ( & V_12 , V_25 , F_42 ( sizeof( struct V_11 ) , V_69 ) ) )
return F_40 ( - V_73 ) ;
if ( V_69 < sizeof( struct V_11 ) ) {
memset ( ( char * ) & V_12 + V_69 , 0 , sizeof( struct V_11 ) - V_69 ) ;
} else if ( V_69 > sizeof( struct V_11 ) ) {
T_3 V_74 ;
for ( V_74 = sizeof( struct V_11 ) ; V_74 < V_69 ; ++ V_74 ) {
char V_75 ;
if ( F_43 ( V_75 , & V_25 [ V_74 ] ) )
return F_40 ( - V_73 ) ;
if ( V_75 )
return F_40 ( - V_18 ) ;
}
}
V_36 = F_44 ( sizeof( struct V_3 ) ,
V_76 | V_77 ) ;
if ( V_36 == NULL )
return F_40 ( - V_78 ) ;
F_45 ( & V_36 -> V_79 ) ;
V_71 = F_4 ( V_36 , & V_12 ) ;
if ( V_71 != 0 ) {
F_46 ( V_36 ) ;
return F_40 ( V_71 ) ;
}
F_28 ( & V_43 , V_41 ) ;
F_29 (iter, &rectangles, list) {
if ( F_12 ( V_70 , V_36 ) ) {
F_34 ( & V_43 , V_41 ) ;
F_46 ( V_36 ) ;
return F_40 ( - V_80 ) ;
}
}
F_47 ( & V_36 -> V_44 , & V_45 ) ;
F_34 ( & V_43 , V_41 ) ;
F_21 ( V_36 ) ;
F_48 ( V_36 ) ;
return V_36 ;
}
static int F_49 ( struct V_3 * V_36 )
{
int V_13 , V_5 , V_6 ;
unsigned long V_41 ;
struct V_37 * V_38 = V_81 ;
struct V_82 * V_83 = & V_38 -> V_53 ;
if ( V_36 == NULL )
return - V_84 ;
if ( V_36 -> V_46 )
return - V_18 ;
if ( F_50 ( & V_38 -> V_85 ) != 1 )
return - V_86 ;
V_13 = F_18 () ;
F_19 ( F_51 ( & V_38 -> V_85 ) != V_13 ) ;
V_5 = F_8 ( V_13 ) ;
V_6 = F_9 ( V_13 ) ;
if ( ! F_3 ( V_36 , V_5 , V_6 ) )
return - V_18 ;
if ( V_83 -> V_54 ) {
F_19 ( V_83 -> V_54 != V_36 ) ;
return 0 ;
}
V_83 -> V_54 = V_36 ;
F_28 ( & V_43 , V_41 ) ;
F_52 ( & V_83 -> V_87 , & V_36 -> V_79 ) ;
F_34 ( & V_43 , V_41 ) ;
F_36 () ;
F_53 ( V_88 L_7 ,
V_38 -> V_56 , V_38 -> V_89 , V_13 ) ;
return 0 ;
}
static void F_54 ( struct V_37 * V_90 )
{
struct V_82 * V_83 = & V_90 -> V_53 ;
if ( F_50 ( & V_90 -> V_85 ) != 1 ) {
F_55 ( L_8
L_9 ,
V_90 -> V_56 , V_90 -> V_89 ,
F_50 ( & V_90 -> V_85 ) ) ;
F_56 () ;
}
F_19 ( V_83 -> V_54 == NULL ) ;
V_83 -> V_54 = NULL ;
F_57 ( & V_83 -> V_87 ) ;
if ( V_90 == V_81 )
F_38 () ;
}
int F_58 ( struct V_37 * V_90 )
{
unsigned long V_41 ;
int V_91 ;
F_28 ( & V_43 , V_41 ) ;
V_91 = ( V_90 -> V_53 . V_54 != NULL ) ;
if ( V_91 )
F_54 ( V_90 ) ;
F_34 ( & V_43 , V_41 ) ;
if ( ! V_91 )
return - V_18 ;
F_53 ( V_88 L_10 ,
V_90 -> V_56 , V_90 -> V_89 , F_18 () ) ;
return 0 ;
}
static void F_59 ( void * V_92 )
{
#if ! F_37 ()
F_20 ( V_93 ,
V_94 |
V_95 |
V_96 ) ;
#endif
}
static void F_60 ( void * V_92 )
{
#if ! F_37 ()
int V_74 ;
int V_97 , V_98 ;
for ( V_74 = 0 ; V_74 < 5 ; V_74 ++ ) {
int V_99 , V_100 ;
F_20 ( V_101 , V_74 ) ;
V_99 = F_31 ( V_102 ) & 0xF ;
for ( V_100 = 0 ; V_100 < V_99 ; V_100 ++ )
( void ) F_31 ( V_103 ) ;
F_19 ( ( F_31 ( V_102 ) & 0xF ) != 0 ) ;
}
V_97 = ( F_31 ( V_104 ) >> 10 ) & 0x3 ;
for ( V_74 = 0 ; V_74 < V_97 ; V_74 ++ )
( void ) F_31 ( V_105 ) ;
while ( F_31 ( V_106 ) & ( 1 << 0 ) )
( void ) F_61 () ;
while ( F_31 ( V_106 ) & ( 1 << 1 ) )
( void ) F_62 () ;
while ( F_31 ( V_106 ) & ( 1 << 2 ) )
( void ) F_63 () ;
while ( F_31 ( V_106 ) & ( 1 << 3 ) )
( void ) F_64 () ;
F_19 ( ( F_31 ( V_106 ) & 0xF ) != 0 ) ;
V_98 = F_31 ( V_107 ) ;
for ( V_74 = 0 ; V_74 < V_98 ; V_74 ++ )
( void ) F_31 ( V_108 ) ;
F_19 ( F_31 ( V_107 ) != 0 ) ;
F_20 ( V_109 , 1 ) ;
for ( V_74 = 0 ; V_74 < 5 ; V_74 ++ ) {
F_20 ( V_101 , V_74 ) ;
F_20 ( V_102 , 0xc3000 ) ;
}
#endif
}
void F_65 ( void )
{
#if ! F_37 ()
unsigned int V_13 = F_18 () ;
unsigned int V_5 = V_13 % V_20 ;
unsigned int V_6 = V_13 / V_20 ;
#endif
if ( V_2 )
return;
#if ! F_37 ()
F_20 ( V_110 , ( V_5 << 18 ) | ( V_6 << 7 ) ) ;
F_20 ( V_111 , 0xf ) ;
F_20 ( V_112 , ( 1 << 0 ) ) ;
F_20 ( V_113 , ( 1 << 1 ) ) ;
F_20 ( V_114 , ( 1 << 2 ) ) ;
F_20 ( V_115 , ( 1 << 3 ) ) ;
#endif
F_20 ( V_116 , 0 ) ;
F_20 ( V_117 , 0 ) ;
#if ! F_37 ()
F_20 ( V_118 , 0 ) ;
F_20 ( V_119 , 0 ) ;
F_20 ( V_101 , 0 ) ;
#endif
#if ! F_37 ()
F_20 ( V_93 , 0 ) ;
#endif
}
static void F_66 ( void * V_92 )
{
F_65 () ;
F_20 ( V_30 , 0 ) ;
F_15 () ;
}
static void F_67 ( struct V_3 * V_4 , struct V_11 * V_120 )
{
int V_5 , V_6 , V_13 ;
F_22 ( V_120 ) ;
V_13 = V_4 -> V_9 * V_20 + V_4 -> V_7 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_10 ; ++ V_6 , V_13 += V_20 - V_4 -> V_8 ) {
for ( V_5 = 0 ; V_5 < V_4 -> V_8 ; ++ V_5 , ++ V_13 )
F_23 ( V_13 , V_120 ) ;
}
}
static void F_68 ( struct V_3 * V_36 )
{
struct V_37 * V_90 ;
unsigned long V_41 ;
struct V_11 V_12 ;
if ( V_36 == NULL )
return;
F_28 ( & V_43 , V_41 ) ;
F_29 (task, &rect->task_head, thread.hardwall_list)
F_54 ( V_90 ) ;
F_34 ( & V_43 , V_41 ) ;
F_53 ( V_88 L_11 ,
V_36 -> V_8 , V_36 -> V_10 , V_36 -> V_7 , V_36 -> V_9 ) ;
F_67 ( V_36 , & V_12 ) ;
F_24 ( & V_12 , F_59 , NULL , 1 ) ;
F_24 ( & V_12 , F_60 , NULL , 1 ) ;
F_24 ( & V_12 , F_66 , NULL , 1 ) ;
F_69 ( V_36 ) ;
F_28 ( & V_43 , V_41 ) ;
F_19 ( ! F_70 ( & V_36 -> V_79 ) ) ;
F_57 ( & V_36 -> V_44 ) ;
F_34 ( & V_43 , V_41 ) ;
F_46 ( V_36 ) ;
}
static int F_71 ( struct V_121 * V_122 , void * V_123 )
{
struct V_3 * V_36 = V_122 -> V_124 ;
char V_125 [ 256 ] ;
int V_71 = F_72 ( V_125 , sizeof( V_125 ) , & V_36 -> V_11 ) ;
V_125 [ V_71 ++ ] = '\n' ;
F_73 ( V_122 , V_125 , V_71 ) ;
return 0 ;
}
static int F_74 ( struct V_126 * V_126 ,
struct V_127 * V_127 )
{
return F_75 ( V_127 , F_71 , F_76 ( V_126 ) -> V_128 ) ;
}
static void F_48 ( struct V_3 * V_36 )
{
char V_125 [ 64 ] ;
snprintf ( V_125 , sizeof( V_125 ) , L_12 , V_36 -> V_17 ) ;
F_77 ( V_125 , 0444 , V_129 ,
& V_130 , V_36 ) ;
}
static void F_69 ( struct V_3 * V_36 )
{
char V_125 [ 64 ] ;
snprintf ( V_125 , sizeof( V_125 ) , L_12 , V_36 -> V_17 ) ;
F_78 ( V_125 , V_129 ) ;
}
int F_79 ( struct V_37 * V_90 , char * V_131 )
{
struct V_3 * V_36 = V_90 -> V_53 . V_54 ;
return V_36 ? sprintf ( V_131 , L_13 , V_36 -> V_17 ) : 0 ;
}
void F_80 ( struct V_132 * V_133 )
{
if ( ! V_2 )
V_129 = F_81 ( L_14 , V_133 ) ;
}
static long F_82 ( struct V_127 * V_127 , unsigned int V_21 , unsigned long V_22 )
{
struct V_3 * V_36 = V_127 -> V_134 ;
if ( F_83 ( V_21 ) != V_135 )
return - V_18 ;
switch ( F_84 ( V_21 ) ) {
case V_136 :
if ( V_2 )
return - V_137 ;
if ( V_36 != NULL )
return - V_138 ;
V_36 = F_39 ( F_85 ( V_21 ) ,
( const unsigned char T_4 * ) V_22 ) ;
if ( F_86 ( V_36 ) )
return F_87 ( V_36 ) ;
V_127 -> V_134 = V_36 ;
return 0 ;
case V_139 :
return F_49 ( V_36 ) ;
case V_140 :
if ( V_81 -> V_53 . V_54 != V_36 )
return - V_18 ;
return F_58 ( V_81 ) ;
case V_141 :
return V_36 ? V_36 -> V_17 : - V_18 ;
default:
return - V_18 ;
}
}
static long F_88 ( struct V_127 * V_127 ,
unsigned int V_21 , unsigned long V_22 )
{
return F_82 ( V_127 , V_21 , ( unsigned long ) F_89 ( V_22 ) ) ;
}
static int F_90 ( struct V_127 * V_127 , T_5 V_142 )
{
struct V_3 * V_36 = V_127 -> V_134 ;
struct V_37 * V_90 , * V_143 ;
unsigned long V_41 ;
if ( V_36 ) {
F_28 ( & V_43 , V_41 ) ;
F_91 (task, tmp, &rect->task_head,
thread.hardwall_list) {
if ( V_90 -> V_144 == V_142 || V_90 -> V_144 == NULL )
F_54 ( V_90 ) ;
}
F_34 ( & V_43 , V_41 ) ;
}
return 0 ;
}
static int F_92 ( struct V_126 * V_126 , struct V_127 * V_127 )
{
F_68 ( V_127 -> V_134 ) ;
return 0 ;
}
static int T_1 F_93 ( void )
{
int V_71 ;
T_6 V_145 ;
V_71 = F_94 ( & V_145 , 0 , 1 , L_14 ) ;
if ( V_71 < 0 )
return V_71 ;
F_95 ( & V_146 , & V_147 ) ;
V_71 = F_96 ( & V_146 , V_145 , 1 ) ;
if ( V_71 < 0 )
return V_71 ;
return 0 ;
}
