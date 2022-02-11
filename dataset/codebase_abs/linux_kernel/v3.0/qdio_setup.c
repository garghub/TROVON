static inline int F_1 ( void )
{
#ifdef F_2
return V_1 . V_2 ;
#endif
return 0 ;
}
static void F_3 ( struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned char * V_6 ,
unsigned long * V_7 ,
unsigned long * V_8 )
{
struct V_9 * V_10 ;
int V_11 , V_12 ;
if ( ! V_4 )
return;
V_4 -> V_13 . V_14 = V_5 ;
if ( V_6 )
memcpy ( V_4 -> V_13 . V_15 , V_6 ,
V_16 ) ;
if ( ! V_7 )
goto V_17;
F_4 (irq_ptr, q, i) {
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ )
V_10 -> V_18 -> V_19 [ V_12 ] . V_20 =
V_7 [ V_11 * V_16 + V_12 ] ;
}
V_17:
if ( ! V_8 )
return;
F_5 (irq_ptr, q, i) {
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ )
V_10 -> V_18 -> V_19 [ V_12 ] . V_20 =
V_8 [ V_11 * V_16 + V_12 ] ;
}
}
static int F_6 ( struct V_9 * * V_21 , int V_22 )
{
struct V_9 * V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_22 ; V_11 ++ ) {
V_10 = F_7 ( V_23 , V_24 ) ;
if ( ! V_10 )
return - V_25 ;
V_10 -> V_18 = (struct V_18 * ) F_8 ( V_24 ) ;
if ( ! V_10 -> V_18 ) {
F_9 ( V_23 , V_10 ) ;
return - V_25 ;
}
V_21 [ V_11 ] = V_10 ;
}
return 0 ;
}
int F_10 ( struct V_3 * V_4 , int V_26 , int V_27 )
{
int V_28 ;
V_28 = F_6 ( V_4 -> V_29 , V_26 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_6 ( V_4 -> V_30 , V_27 ) ;
return V_28 ;
}
static void F_11 ( struct V_9 * V_10 , struct V_3 * V_4 ,
T_1 * V_31 , int V_11 )
{
struct V_18 * V_18 = V_10 -> V_18 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
memset ( V_18 , 0 , V_32 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_33 = 1 << ( 31 - V_11 ) ;
V_10 -> V_34 = V_11 ;
V_10 -> V_31 = V_31 ;
}
static void F_12 ( struct V_9 * V_10 , struct V_3 * V_4 ,
void * * V_35 , int V_11 )
{
struct V_9 * V_36 ;
int V_12 ;
F_13 ( & V_10 , sizeof( void * ) ) ;
V_10 -> V_37 = (struct V_37 * ) ( ( char * ) V_10 -> V_18 + V_32 / 2 ) ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ ) {
V_10 -> V_38 [ V_12 ] = * V_35 ++ ;
F_14 ( ( unsigned long ) V_10 -> V_38 [ V_12 ] & 0xff ) ;
}
if ( V_11 > 0 ) {
V_36 = ( V_10 -> V_39 ) ? V_4 -> V_29 [ V_11 - 1 ]
: V_4 -> V_30 [ V_11 - 1 ] ;
V_36 -> V_18 -> V_40 = ( unsigned long ) V_10 -> V_18 ;
}
V_10 -> V_18 -> V_41 = ( unsigned long ) V_10 -> V_37 ;
V_10 -> V_18 -> V_42 = ( unsigned long ) & V_10 -> V_43 . V_44 [ 0 ] ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ )
V_10 -> V_37 -> V_45 [ V_12 ] . V_38 = ( unsigned long ) V_10 -> V_38 [ V_12 ] ;
}
static void F_15 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
struct V_9 * V_10 ;
void * * V_48 = V_47 -> V_49 ;
void * * V_50 = V_47 -> V_51 ;
int V_11 ;
F_4 (irq_ptr, q, i) {
F_16 ( L_1 , V_11 ) ;
F_11 ( V_10 , V_4 , V_47 -> V_52 , V_11 ) ;
V_10 -> V_39 = 1 ;
V_10 -> V_53 . V_54 . V_55 = V_47 -> V_55 ;
F_12 ( V_10 , V_4 , V_48 , V_11 ) ;
V_48 += V_16 ;
if ( F_17 ( V_4 ) )
F_18 ( & V_10 -> V_56 , V_57 ,
( unsigned long ) V_10 ) ;
else
F_18 ( & V_10 -> V_56 , V_58 ,
( unsigned long ) V_10 ) ;
}
F_5 (irq_ptr, q, i) {
F_16 ( L_2 , V_11 ) ;
F_11 ( V_10 , V_4 , V_47 -> V_59 , V_11 ) ;
V_10 -> V_39 = 0 ;
V_10 -> V_53 . V_60 . V_61 = V_47 -> V_61 ;
F_12 ( V_10 , V_4 , V_50 , V_11 ) ;
V_50 += V_16 ;
F_18 ( & V_10 -> V_56 , V_62 ,
( unsigned long ) V_10 ) ;
F_19 ( & V_10 -> V_53 . V_60 . V_63 , ( void (*) ( unsigned long ) )
& V_64 , ( unsigned long ) V_10 ) ;
}
}
static void F_20 ( struct V_3 * V_4 , unsigned char V_65 )
{
if ( V_65 & V_66 )
V_4 -> V_67 . V_68 = 1 ;
if ( V_65 & V_69 )
V_4 -> V_67 . V_17 = 1 ;
if ( V_65 & V_70 )
V_4 -> V_67 . V_71 = 1 ;
if ( ! ( V_65 & V_72 ) )
V_4 -> V_67 . V_73 = 1 ;
if ( ! ( V_65 & V_74 ) )
V_4 -> V_67 . V_75 = 1 ;
}
static void F_21 ( struct V_3 * V_4 ,
unsigned char V_65 , unsigned long V_76 )
{
if ( ! ( V_4 -> V_13 . V_77 & V_78 ) )
goto V_79;
if ( ! ( V_65 & V_80 ) ||
( ! ( V_65 & V_81 ) ) )
goto V_79;
V_4 -> V_82 = V_76 ;
F_16 ( L_3 ) ;
F_16 ( L_4 , V_4 -> V_82 ) ;
return;
V_79:
V_4 -> V_82 = 0 ;
V_4 -> V_13 . V_77 &= ~ V_78 ;
F_16 ( L_5 ) ;
}
int F_22 ( struct V_3 * V_4 ,
struct V_83 * V_84 ,
struct V_85 * V_86 )
{
struct V_87 * V_88 ;
int V_28 ;
F_16 ( L_6 , V_84 -> V_89 ) ;
if ( V_4 != NULL )
V_88 = (struct V_87 * ) V_4 -> V_90 ;
else
V_88 = (struct V_87 * ) F_8 ( V_24 ) ;
memset ( V_88 , 0 , V_32 ) ;
V_88 -> V_91 = (struct V_92 ) {
. V_93 = 0x0010 ,
. V_94 = 0x0024 ,
} ;
V_88 -> V_95 = V_84 -> V_89 ;
V_88 -> V_96 = V_84 -> V_89 ;
V_88 -> V_97 = V_84 -> V_97 ;
if ( F_23 ( V_88 ) )
return - V_98 ;
V_28 = F_24 ( V_88 -> V_99 . V_94 ) ;
if ( V_28 )
return V_28 ;
if ( ! ( V_88 -> V_100 . V_101 & V_102 ) ||
! ( V_88 -> V_100 . V_101 & V_103 ) ||
( V_88 -> V_100 . V_104 != V_84 -> V_89 ) )
return - V_105 ;
if ( V_4 != NULL )
memcpy ( & V_4 -> V_106 , & V_88 -> V_100 ,
sizeof( struct V_85 ) ) ;
else {
memcpy ( V_86 , & V_88 -> V_100 ,
sizeof( struct V_85 ) ) ;
F_25 ( ( unsigned long ) V_88 ) ;
}
return 0 ;
}
void F_26 ( struct V_3 * V_4 )
{
unsigned char V_65 ;
int V_28 ;
V_28 = F_22 ( V_4 , & V_4 -> V_84 , NULL ) ;
if ( V_28 ) {
F_27 ( L_7 , V_4 -> V_84 . V_89 ) ;
F_27 ( L_8 , V_28 ) ;
V_65 = V_66 | V_69 |
V_70 ;
} else
V_65 = V_4 -> V_106 . V_107 ;
F_21 ( V_4 , V_65 , V_4 -> V_106 . V_82 ) ;
F_20 ( V_4 , V_65 ) ;
F_16 ( L_9 , V_65 ) ;
}
void F_28 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_108 ; V_11 ++ ) {
V_10 = V_4 -> V_29 [ V_11 ] ;
if ( V_10 ) {
F_25 ( ( unsigned long ) V_10 -> V_18 ) ;
F_9 ( V_23 , V_10 ) ;
}
}
for ( V_11 = 0 ; V_11 < V_108 ; V_11 ++ ) {
V_10 = V_4 -> V_30 [ V_11 ] ;
if ( V_10 ) {
F_25 ( ( unsigned long ) V_10 -> V_18 ) ;
F_9 ( V_23 , V_10 ) ;
}
}
F_25 ( ( unsigned long ) V_4 -> V_109 ) ;
F_25 ( V_4 -> V_90 ) ;
F_25 ( ( unsigned long ) V_4 ) ;
}
static void F_29 ( struct V_3 * V_4 ,
struct V_9 * * V_21 ,
int V_11 , int V_34 )
{
V_4 -> V_109 -> V_110 [ V_11 + V_34 ] . V_111 =
( unsigned long ) V_21 [ V_11 ] -> V_18 ;
V_4 -> V_109 -> V_110 [ V_11 + V_34 ] . V_41 =
( unsigned long ) V_21 [ V_11 ] -> V_37 ;
V_4 -> V_109 -> V_110 [ V_11 + V_34 ] . V_42 =
( unsigned long ) & V_21 [ V_11 ] -> V_43 . V_44 [ 0 ] ;
V_4 -> V_109 -> V_110 [ V_11 + V_34 ] . V_112 = V_113 >> 4 ;
V_4 -> V_109 -> V_110 [ V_11 + V_34 ] . V_114 = V_113 >> 4 ;
V_4 -> V_109 -> V_110 [ V_11 + V_34 ] . V_115 = V_113 >> 4 ;
V_4 -> V_109 -> V_110 [ V_11 + V_34 ] . V_116 = V_113 >> 4 ;
}
static void F_30 ( struct V_3 * V_4 ,
struct V_46 * V_47 )
{
int V_11 ;
V_4 -> V_109 -> V_117 = V_47 -> V_118 ;
V_4 -> V_109 -> V_119 = V_47 -> V_120 ;
V_4 -> V_109 -> V_121 = V_47 -> V_122 ;
V_4 -> V_109 -> V_123 = sizeof( struct V_124 ) / 4 ;
V_4 -> V_109 -> V_125 = sizeof( struct V_124 ) / 4 ;
V_4 -> V_109 -> V_126 = ( unsigned long ) & V_4 -> V_13 ;
V_4 -> V_109 -> V_127 = V_113 >> 4 ;
for ( V_11 = 0 ; V_11 < V_47 -> V_120 ; V_11 ++ )
F_29 ( V_4 , V_4 -> V_29 , V_11 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_47 -> V_122 ; V_11 ++ )
F_29 ( V_4 , V_4 -> V_30 , V_11 ,
V_47 -> V_120 ) ;
}
static void F_31 ( struct V_3 * V_4 ,
struct V_46 * V_128 )
{
if ( F_1 () )
V_4 -> V_13 . V_77 |= V_78 ;
V_4 -> V_13 . V_77 |= V_128 -> V_129 ;
V_4 -> V_13 . V_117 = V_128 -> V_118 ;
if ( V_128 -> V_120 )
V_4 -> V_13 . V_130 =
( unsigned long ) ( V_4 -> V_29 [ 0 ] -> V_18 ) ;
if ( V_128 -> V_122 )
V_4 -> V_13 . V_131 =
( unsigned long ) ( V_4 -> V_30 [ 0 ] -> V_18 ) ;
memcpy ( V_4 -> V_13 . V_132 , V_128 -> V_133 , 8 ) ;
}
int F_32 ( struct V_46 * V_128 )
{
struct V_134 * V_134 ;
struct V_3 * V_4 = V_128 -> V_135 -> V_136 -> V_137 ;
int V_28 ;
memset ( & V_4 -> V_13 , 0 , sizeof( V_4 -> V_13 ) ) ;
memset ( & V_4 -> V_67 , 0 , sizeof( V_4 -> V_67 ) ) ;
memset ( & V_4 -> V_138 , 0 , sizeof( V_4 -> V_138 ) ) ;
memset ( & V_4 -> V_106 , 0 , sizeof( V_4 -> V_106 ) ) ;
memset ( & V_4 -> V_139 , 0 , sizeof( V_4 -> V_139 ) ) ;
V_4 -> V_140 = V_4 -> V_141 = NULL ;
V_4 -> V_82 = V_4 -> V_142 = V_4 -> V_143 = 0 ;
memset ( V_4 -> V_109 , 0 , sizeof( struct V_109 ) ) ;
V_4 -> V_144 = V_128 -> V_144 ;
V_4 -> V_26 = V_128 -> V_120 ;
V_4 -> V_27 = V_128 -> V_122 ;
V_4 -> V_84 = F_33 ( V_128 -> V_135 ) ;
V_4 -> V_135 = V_128 -> V_135 ;
F_15 ( V_4 , V_128 ) ;
F_31 ( V_4 , V_128 ) ;
F_34 ( V_4 ) ;
F_3 ( V_4 , V_128 -> V_5 ,
V_128 -> V_6 ,
V_128 -> V_7 ,
V_128 -> V_8 ) ;
F_30 ( V_4 , V_128 ) ;
V_134 = F_35 ( V_128 -> V_135 , V_145 ) ;
if ( ! V_134 ) {
F_27 ( L_10 , V_4 -> V_84 . V_89 ) ;
V_28 = - V_105 ;
goto V_146;
}
V_4 -> V_147 = * V_134 ;
V_134 = F_35 ( V_128 -> V_135 , V_148 ) ;
if ( ! V_134 ) {
F_27 ( L_11 , V_4 -> V_84 . V_89 ) ;
V_28 = - V_105 ;
goto V_146;
}
V_4 -> V_149 = * V_134 ;
V_4 -> V_150 = V_128 -> V_135 -> V_31 ;
V_128 -> V_135 -> V_31 = V_151 ;
return 0 ;
V_146:
F_28 ( V_4 ) ;
return V_28 ;
}
void F_36 ( struct V_3 * V_4 ,
struct V_152 * V_135 )
{
char V_153 [ 80 ] ;
snprintf ( V_153 , 80 , L_12
L_13 ,
F_37 ( & V_135 -> V_154 ) ,
( V_4 -> V_13 . V_117 == V_155 ) ? L_14 :
( ( V_4 -> V_13 . V_117 == V_156 ) ? L_15 : L_16 ) ,
V_4 -> V_84 . V_89 ,
F_17 ( V_4 ) ,
( V_4 -> V_82 ) ? 1 : 0 ,
( V_4 -> V_13 . V_157 & V_158 ) ? 1 : 0 ,
V_1 . V_159 ,
( V_4 -> V_67 . V_68 ) ? L_17 : L_18 ,
( V_4 -> V_67 . V_17 ) ? L_19 : L_18 ,
( V_4 -> V_67 . V_71 ) ? L_20 : L_18 ,
( V_4 -> V_67 . V_73 ) ? L_21 : L_18 ,
( V_4 -> V_67 . V_75 ) ? L_22 : L_18 ) ;
F_38 ( V_160 L_23 , V_153 ) ;
}
int T_2 F_39 ( void )
{
V_23 = F_40 ( L_24 , sizeof( struct V_9 ) ,
256 , 0 , NULL ) ;
if ( ! V_23 )
return - V_25 ;
F_16 ( L_25 ,
( V_1 . V_161 ) ? 1 : 0 ) ;
F_16 ( L_26 , ( F_1 () ) ? 1 : 0 ) ;
return 0 ;
}
void F_41 ( void )
{
F_42 ( V_23 ) ;
}
