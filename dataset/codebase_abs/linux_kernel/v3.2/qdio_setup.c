struct V_1 * F_1 ()
{
struct V_1 * V_2 ;
V_2 = F_2 ( V_3 , V_4 ) ;
return V_2 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_3 , V_2 ) ;
}
static inline int F_5 ( void )
{
#ifdef F_6
return V_5 . V_6 ;
#endif
return 0 ;
}
static void F_7 ( struct V_7 * V_8 ,
unsigned int V_9 ,
unsigned char * V_10 ,
unsigned long * V_11 ,
unsigned long * V_12 )
{
struct V_13 * V_14 ;
int V_15 , V_16 ;
if ( ! V_8 )
return;
V_8 -> V_17 . V_18 = V_9 ;
if ( V_10 )
memcpy ( V_8 -> V_17 . V_19 , V_10 ,
V_20 ) ;
if ( ! V_11 )
goto V_21;
F_8 (irq_ptr, q, i) {
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ )
V_14 -> V_22 -> V_23 [ V_16 ] . V_24 =
V_11 [ V_15 * V_20 + V_16 ] ;
}
V_21:
if ( ! V_12 )
return;
F_9 (irq_ptr, q, i) {
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ )
V_14 -> V_22 -> V_23 [ V_16 ] . V_24 =
V_12 [ V_15 * V_20 + V_16 ] ;
}
}
static int F_10 ( struct V_13 * * V_25 , int V_26 )
{
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
V_14 = F_11 ( V_27 , V_28 ) ;
if ( ! V_14 )
return - V_29 ;
V_14 -> V_22 = (struct V_22 * ) F_12 ( V_28 ) ;
if ( ! V_14 -> V_22 ) {
F_4 ( V_27 , V_14 ) ;
return - V_29 ;
}
V_25 [ V_15 ] = V_14 ;
}
return 0 ;
}
int F_13 ( struct V_7 * V_8 , int V_30 , int V_31 )
{
int V_32 ;
V_32 = F_10 ( V_8 -> V_33 , V_30 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_10 ( V_8 -> V_34 , V_31 ) ;
return V_32 ;
}
static void F_14 ( struct V_13 * V_14 , struct V_7 * V_8 ,
T_1 * V_35 , int V_15 )
{
struct V_22 * V_22 = V_14 -> V_22 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
memset ( V_22 , 0 , V_36 ) ;
V_14 -> V_22 = V_22 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_37 = 1 << ( 31 - V_15 ) ;
V_14 -> V_38 = V_15 ;
V_14 -> V_35 = V_35 ;
}
static void F_15 ( struct V_13 * V_14 , struct V_7 * V_8 ,
void * * V_39 , int V_15 )
{
struct V_13 * V_40 ;
int V_16 ;
F_16 ( & V_14 , sizeof( void * ) ) ;
V_14 -> V_41 = (struct V_41 * ) ( ( char * ) V_14 -> V_22 + V_36 / 2 ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_14 -> V_42 [ V_16 ] = * V_39 ++ ;
F_17 ( ( unsigned long ) V_14 -> V_42 [ V_16 ] & 0xff ) ;
}
if ( V_15 > 0 ) {
V_40 = ( V_14 -> V_43 ) ? V_8 -> V_33 [ V_15 - 1 ]
: V_8 -> V_34 [ V_15 - 1 ] ;
V_40 -> V_22 -> V_44 = ( unsigned long ) V_14 -> V_22 ;
}
V_14 -> V_22 -> V_45 = ( unsigned long ) V_14 -> V_41 ;
V_14 -> V_22 -> V_46 = ( unsigned long ) & V_14 -> V_47 . V_48 [ 0 ] ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ )
V_14 -> V_41 -> V_49 [ V_16 ] . V_42 = ( unsigned long ) V_14 -> V_42 [ V_16 ] ;
}
static void F_18 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
struct V_13 * V_14 ;
void * * V_52 = V_51 -> V_53 ;
void * * V_54 = V_51 -> V_55 ;
struct V_56 * V_57 =
V_51 -> V_57 ;
int V_15 ;
F_8 (irq_ptr, q, i) {
F_19 ( L_1 , V_15 ) ;
F_14 ( V_14 , V_8 , V_51 -> V_58 , V_15 ) ;
V_14 -> V_43 = 1 ;
V_14 -> V_59 . V_60 . V_61 = V_51 -> V_61 [ V_15 ] ;
F_15 ( V_14 , V_8 , V_52 , V_15 ) ;
V_52 += V_20 ;
if ( F_20 ( V_8 ) ) {
F_21 ( & V_14 -> V_62 , V_63 ,
( unsigned long ) V_14 ) ;
} else {
F_21 ( & V_14 -> V_62 , V_64 ,
( unsigned long ) V_14 ) ;
}
}
F_9 (irq_ptr, q, i) {
F_19 ( L_2 , V_15 ) ;
F_14 ( V_14 , V_8 , V_51 -> V_65 , V_15 ) ;
V_14 -> V_59 . V_66 . V_67 = V_57 ;
V_57 += V_20 ;
V_14 -> V_43 = 0 ;
V_14 -> V_59 . V_66 . V_68 = V_51 -> V_68 ;
F_15 ( V_14 , V_8 , V_54 , V_15 ) ;
V_54 += V_20 ;
F_21 ( & V_14 -> V_62 , V_69 ,
( unsigned long ) V_14 ) ;
F_22 ( & V_14 -> V_59 . V_66 . V_70 , ( void (*) ( unsigned long ) )
& V_71 , ( unsigned long ) V_14 ) ;
}
}
static void F_23 ( struct V_7 * V_8 , unsigned char V_72 )
{
if ( V_72 & V_73 )
V_8 -> V_74 . V_75 = 1 ;
if ( V_72 & V_76 )
V_8 -> V_74 . V_21 = 1 ;
if ( V_72 & V_77 )
V_8 -> V_74 . V_78 = 1 ;
if ( ! ( V_72 & V_79 ) )
V_8 -> V_74 . V_80 = 1 ;
if ( ! ( V_72 & V_81 ) )
V_8 -> V_74 . V_82 = 1 ;
}
static void F_24 ( struct V_7 * V_8 ,
unsigned char V_72 , unsigned long V_83 )
{
if ( ! ( V_8 -> V_17 . V_84 & V_85 ) )
goto V_86;
if ( ! ( V_72 & V_87 ) ||
( ! ( V_72 & V_88 ) ) )
goto V_86;
V_8 -> V_89 = V_83 ;
F_19 ( L_3 ) ;
F_19 ( L_4 , V_8 -> V_89 ) ;
return;
V_86:
V_8 -> V_89 = 0 ;
V_8 -> V_17 . V_84 &= ~ V_85 ;
F_19 ( L_5 ) ;
}
int F_25 ( struct V_7 * V_8 ,
struct V_90 * V_91 ,
struct V_92 * V_93 )
{
struct V_94 * V_95 ;
int V_32 ;
F_19 ( L_6 , V_91 -> V_96 ) ;
if ( V_8 != NULL )
V_95 = (struct V_94 * ) V_8 -> V_97 ;
else
V_95 = (struct V_94 * ) F_12 ( V_28 ) ;
memset ( V_95 , 0 , V_36 ) ;
V_95 -> V_98 = (struct V_99 ) {
. V_100 = 0x0010 ,
. V_101 = 0x0024 ,
} ;
V_95 -> V_102 = V_91 -> V_96 ;
V_95 -> V_103 = V_91 -> V_96 ;
V_95 -> V_104 = V_91 -> V_104 ;
if ( F_26 ( V_95 ) )
return - V_105 ;
V_32 = F_27 ( V_95 -> V_106 . V_101 ) ;
if ( V_32 )
return V_32 ;
if ( ! ( V_95 -> V_107 . V_108 & V_109 ) ||
! ( V_95 -> V_107 . V_108 & V_110 ) ||
( V_95 -> V_107 . V_111 != V_91 -> V_96 ) )
return - V_112 ;
if ( V_8 != NULL )
memcpy ( & V_8 -> V_113 , & V_95 -> V_107 ,
sizeof( struct V_92 ) ) ;
else {
memcpy ( V_93 , & V_95 -> V_107 ,
sizeof( struct V_92 ) ) ;
F_28 ( ( unsigned long ) V_95 ) ;
}
return 0 ;
}
void F_29 ( struct V_7 * V_8 )
{
unsigned char V_72 ;
int V_32 ;
V_32 = F_25 ( V_8 , & V_8 -> V_91 , NULL ) ;
if ( V_32 ) {
F_30 ( L_7 , V_8 -> V_91 . V_96 ) ;
F_30 ( L_8 , V_32 ) ;
V_72 = V_73 | V_76 |
V_77 ;
} else
V_72 = V_8 -> V_113 . V_114 ;
F_24 ( V_8 , V_72 , V_8 -> V_113 . V_89 ) ;
F_23 ( V_8 , V_72 ) ;
F_19 ( L_9 , V_72 ) ;
}
void F_31 ( struct V_7 * V_8 )
{
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_115 ; V_15 ++ ) {
V_14 = V_8 -> V_33 [ V_15 ] ;
if ( V_14 ) {
F_28 ( ( unsigned long ) V_14 -> V_22 ) ;
F_4 ( V_27 , V_14 ) ;
}
}
for ( V_15 = 0 ; V_15 < V_115 ; V_15 ++ ) {
V_14 = V_8 -> V_34 [ V_15 ] ;
if ( V_14 ) {
if ( V_14 -> V_59 . V_66 . V_116 ) {
int V_117 ;
for ( V_117 = 0 ; V_117 < V_20 ; ++ V_117 ) {
struct V_1 * V_2 = V_14 -> V_59 . V_66 . V_118 [ V_117 ] ;
if ( V_2 ) {
F_3 ( V_2 ) ;
V_14 -> V_59 . V_66 . V_118 [ V_117 ] = NULL ;
}
}
F_32 ( & V_14 -> V_59 . V_66 ) ;
}
F_28 ( ( unsigned long ) V_14 -> V_22 ) ;
F_4 ( V_27 , V_14 ) ;
}
}
F_28 ( ( unsigned long ) V_8 -> V_119 ) ;
F_28 ( V_8 -> V_97 ) ;
F_28 ( ( unsigned long ) V_8 ) ;
}
static void F_33 ( struct V_7 * V_8 ,
struct V_13 * * V_25 ,
int V_15 , int V_38 )
{
V_8 -> V_119 -> V_120 [ V_15 + V_38 ] . V_121 =
( unsigned long ) V_25 [ V_15 ] -> V_22 ;
V_8 -> V_119 -> V_120 [ V_15 + V_38 ] . V_45 =
( unsigned long ) V_25 [ V_15 ] -> V_41 ;
V_8 -> V_119 -> V_120 [ V_15 + V_38 ] . V_46 =
( unsigned long ) & V_25 [ V_15 ] -> V_47 . V_48 [ 0 ] ;
V_8 -> V_119 -> V_120 [ V_15 + V_38 ] . V_122 = V_123 >> 4 ;
V_8 -> V_119 -> V_120 [ V_15 + V_38 ] . V_124 = V_123 >> 4 ;
V_8 -> V_119 -> V_120 [ V_15 + V_38 ] . V_125 = V_123 >> 4 ;
V_8 -> V_119 -> V_120 [ V_15 + V_38 ] . V_126 = V_123 >> 4 ;
}
static void F_34 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
int V_15 ;
V_8 -> V_119 -> V_127 = V_51 -> V_128 ;
V_8 -> V_119 -> V_129 = V_51 -> V_130 ;
V_8 -> V_119 -> V_131 = V_51 -> V_132 ;
V_8 -> V_119 -> V_133 = V_51 -> V_134 ;
V_8 -> V_119 -> V_135 = sizeof( struct V_136 ) / 4 ;
V_8 -> V_119 -> V_137 = sizeof( struct V_136 ) / 4 ;
V_8 -> V_119 -> V_138 = ( unsigned long ) & V_8 -> V_17 ;
V_8 -> V_119 -> V_139 = V_123 >> 4 ;
for ( V_15 = 0 ; V_15 < V_51 -> V_132 ; V_15 ++ )
F_33 ( V_8 , V_8 -> V_33 , V_15 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_51 -> V_134 ; V_15 ++ )
F_33 ( V_8 , V_8 -> V_34 , V_15 ,
V_51 -> V_132 ) ;
}
static void F_35 ( struct V_7 * V_8 ,
struct V_50 * V_140 )
{
if ( F_5 () )
V_8 -> V_17 . V_84 |= V_85 ;
V_8 -> V_17 . V_84 |= V_140 -> V_141 ;
V_8 -> V_17 . V_127 = V_140 -> V_128 ;
if ( V_140 -> V_132 )
V_8 -> V_17 . V_142 =
( unsigned long ) ( V_8 -> V_33 [ 0 ] -> V_22 ) ;
if ( V_140 -> V_134 )
V_8 -> V_17 . V_143 =
( unsigned long ) ( V_8 -> V_34 [ 0 ] -> V_22 ) ;
memcpy ( V_8 -> V_17 . V_144 , V_140 -> V_145 , 8 ) ;
}
int F_36 ( struct V_50 * V_140 )
{
struct V_146 * V_146 ;
struct V_7 * V_8 = V_140 -> V_147 -> V_148 -> V_149 ;
int V_32 ;
memset ( & V_8 -> V_17 , 0 , sizeof( V_8 -> V_17 ) ) ;
memset ( & V_8 -> V_74 , 0 , sizeof( V_8 -> V_74 ) ) ;
memset ( & V_8 -> V_150 , 0 , sizeof( V_8 -> V_150 ) ) ;
memset ( & V_8 -> V_113 , 0 , sizeof( V_8 -> V_113 ) ) ;
memset ( & V_8 -> V_151 , 0 , sizeof( V_8 -> V_151 ) ) ;
V_8 -> V_152 = V_8 -> V_153 = NULL ;
V_8 -> V_89 = V_8 -> V_154 = V_8 -> V_155 = 0 ;
memset ( V_8 -> V_119 , 0 , sizeof( struct V_119 ) ) ;
V_8 -> V_156 = V_140 -> V_156 ;
V_8 -> V_30 = V_140 -> V_132 ;
V_8 -> V_31 = V_140 -> V_134 ;
V_8 -> V_91 = F_37 ( V_140 -> V_147 ) ;
V_8 -> V_147 = V_140 -> V_147 ;
F_18 ( V_8 , V_140 ) ;
F_35 ( V_8 , V_140 ) ;
F_38 ( V_8 ) ;
F_7 ( V_8 , V_140 -> V_9 ,
V_140 -> V_10 ,
V_140 -> V_11 ,
V_140 -> V_12 ) ;
F_34 ( V_8 , V_140 ) ;
V_146 = F_39 ( V_140 -> V_147 , V_157 ) ;
if ( ! V_146 ) {
F_30 ( L_10 , V_8 -> V_91 . V_96 ) ;
V_32 = - V_112 ;
goto V_158;
}
V_8 -> V_159 = * V_146 ;
V_146 = F_39 ( V_140 -> V_147 , V_160 ) ;
if ( ! V_146 ) {
F_30 ( L_11 , V_8 -> V_91 . V_96 ) ;
V_32 = - V_112 ;
goto V_158;
}
V_8 -> V_161 = * V_146 ;
V_8 -> V_162 = V_140 -> V_147 -> V_35 ;
V_140 -> V_147 -> V_35 = V_163 ;
return 0 ;
V_158:
F_31 ( V_8 ) ;
return V_32 ;
}
void F_40 ( struct V_7 * V_8 ,
struct V_164 * V_147 )
{
char V_165 [ 80 ] ;
snprintf ( V_165 , 80 , L_12
L_13 ,
F_41 ( & V_147 -> V_166 ) ,
( V_8 -> V_17 . V_127 == V_167 ) ? L_14 :
( ( V_8 -> V_17 . V_127 == V_168 ) ? L_15 : L_16 ) ,
V_8 -> V_91 . V_96 ,
F_20 ( V_8 ) ,
( V_8 -> V_89 ) ? 1 : 0 ,
( V_8 -> V_17 . V_129 & V_169 ) ? 1 : 0 ,
V_5 . V_170 ,
( V_8 -> V_74 . V_75 ) ? L_17 : L_18 ,
( V_8 -> V_74 . V_21 ) ? L_19 : L_18 ,
( V_8 -> V_74 . V_78 ) ? L_20 : L_18 ,
( V_8 -> V_74 . V_80 ) ? L_21 : L_18 ,
( V_8 -> V_74 . V_82 ) ? L_22 : L_18 ) ;
F_42 ( V_171 L_23 , V_165 ) ;
}
int F_43 ( struct V_172 * V_173 )
{
V_173 -> V_118 = F_44 ( sizeof( struct V_1 * ) * V_20 ,
V_4 ) ;
if ( ! V_173 -> V_118 ) {
V_173 -> V_116 = 0 ;
return - V_29 ;
}
V_173 -> V_116 = 1 ;
return 0 ;
}
void F_32 ( struct V_172 * V_14 )
{
F_45 ( V_14 -> V_118 ) ;
V_14 -> V_118 = NULL ;
V_14 -> V_116 = 0 ;
}
int T_2 F_46 ( void )
{
int V_32 ;
V_27 = F_47 ( L_24 , sizeof( struct V_13 ) ,
256 , 0 , NULL ) ;
if ( ! V_27 )
return - V_29 ;
V_3 = F_47 ( L_25 ,
sizeof( struct V_1 ) ,
sizeof( struct V_1 ) ,
0 ,
NULL ) ;
if ( ! V_3 ) {
V_32 = - V_29 ;
goto V_174;
}
F_19 ( L_26 ,
( V_5 . V_175 ) ? 1 : 0 ) ;
F_19 ( L_27 , ( F_5 () ) ? 1 : 0 ) ;
V_32 = 0 ;
V_66:
return V_32 ;
V_174:
F_48 ( V_27 ) ;
goto V_66;
}
void F_49 ( void )
{
F_48 ( V_3 ) ;
F_48 ( V_27 ) ;
}
