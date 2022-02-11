struct V_1 * F_1 ( void )
{
return F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_1 * V_4 )
{
F_4 ( V_2 , V_4 ) ;
}
void F_5 ( struct V_5 * * V_6 , unsigned int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += V_9 )
F_6 ( ( unsigned long ) V_6 [ V_8 ] ) ;
}
int F_7 ( struct V_5 * * V_6 , unsigned int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 += V_9 ) {
V_6 [ V_8 ] = ( void * ) F_8 ( V_10 ) ;
if ( ! V_6 [ V_8 ] ) {
F_5 ( V_6 , V_7 ) ;
return - V_11 ;
}
}
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
if ( V_8 % V_9 )
V_6 [ V_8 ] = V_6 [ V_8 - 1 ] + 1 ;
return 0 ;
}
void F_9 ( struct V_5 * * V_6 , unsigned int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
memset ( V_6 [ V_8 ] , 0 , sizeof( struct V_5 ) ) ;
}
static inline int F_10 ( void )
{
return V_12 . V_13 ;
}
static void F_11 ( struct V_14 * V_15 ,
unsigned int V_16 ,
unsigned char * V_17 ,
unsigned long * V_18 ,
unsigned long * V_19 )
{
struct V_20 * V_21 ;
int V_22 , V_23 ;
if ( ! V_15 )
return;
V_15 -> V_24 . V_25 = V_16 ;
if ( V_17 )
memcpy ( V_15 -> V_24 . V_26 , V_17 ,
V_27 ) ;
if ( ! V_18 )
goto V_28;
F_12 (irq_ptr, q, i) {
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ )
V_21 -> V_29 -> V_30 [ V_23 ] . V_31 =
V_18 [ V_22 * V_27 + V_23 ] ;
}
V_28:
if ( ! V_19 )
return;
F_13 (irq_ptr, q, i) {
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ )
V_21 -> V_29 -> V_30 [ V_23 ] . V_31 =
V_19 [ V_22 * V_27 + V_23 ] ;
}
}
static int F_14 ( struct V_20 * * V_32 , int V_33 )
{
struct V_20 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_33 ; V_22 ++ ) {
V_21 = F_15 ( V_34 , V_10 ) ;
if ( ! V_21 )
return - V_11 ;
V_21 -> V_29 = (struct V_29 * ) F_16 ( V_10 ) ;
if ( ! V_21 -> V_29 ) {
F_4 ( V_34 , V_21 ) ;
return - V_11 ;
}
V_32 [ V_22 ] = V_21 ;
}
return 0 ;
}
int F_17 ( struct V_14 * V_15 , int V_35 , int V_36 )
{
int V_37 ;
V_37 = F_14 ( V_15 -> V_38 , V_35 ) ;
if ( V_37 )
return V_37 ;
V_37 = F_14 ( V_15 -> V_39 , V_36 ) ;
return V_37 ;
}
static void F_18 ( struct V_20 * V_21 , struct V_14 * V_15 ,
T_1 * V_40 , int V_22 )
{
struct V_29 * V_29 = V_21 -> V_29 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
memset ( V_29 , 0 , V_41 ) ;
V_21 -> V_29 = V_29 ;
V_21 -> V_15 = V_15 ;
V_21 -> V_42 = 1 << ( 31 - V_22 ) ;
V_21 -> V_43 = V_22 ;
V_21 -> V_40 = V_40 ;
}
static void F_19 ( struct V_20 * V_21 , struct V_14 * V_15 ,
void * * V_44 , int V_22 )
{
struct V_20 * V_45 ;
int V_23 ;
F_20 ( & V_21 , sizeof( void * ) ) ;
V_21 -> V_46 = (struct V_46 * ) ( ( char * ) V_21 -> V_29 + V_41 / 2 ) ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ )
V_21 -> V_47 [ V_23 ] = * V_44 ++ ;
if ( V_22 > 0 ) {
V_45 = ( V_21 -> V_48 ) ? V_15 -> V_38 [ V_22 - 1 ]
: V_15 -> V_39 [ V_22 - 1 ] ;
V_45 -> V_29 -> V_49 = ( unsigned long ) V_21 -> V_29 ;
}
V_21 -> V_29 -> V_50 = ( unsigned long ) V_21 -> V_46 ;
V_21 -> V_29 -> V_51 = ( unsigned long ) & V_21 -> V_52 . V_53 [ 0 ] ;
for ( V_23 = 0 ; V_23 < V_27 ; V_23 ++ )
V_21 -> V_46 -> V_54 [ V_23 ] . V_47 = ( unsigned long ) V_21 -> V_47 [ V_23 ] ;
}
static void F_21 ( struct V_14 * V_15 ,
struct V_55 * V_56 )
{
struct V_20 * V_21 ;
void * * V_57 = V_56 -> V_58 ;
void * * V_59 = V_56 -> V_60 ;
struct V_61 * V_62 =
V_56 -> V_62 ;
int V_22 ;
F_12 (irq_ptr, q, i) {
F_22 ( L_1 , V_22 ) ;
F_18 ( V_21 , V_15 , V_56 -> V_63 , V_22 ) ;
V_21 -> V_48 = 1 ;
V_21 -> V_64 . V_65 . V_66 = V_56 -> V_67 ?
V_56 -> V_67 [ V_22 ] : NULL ;
F_19 ( V_21 , V_15 , V_57 , V_22 ) ;
V_57 += V_27 ;
if ( F_23 ( V_15 ) ) {
F_24 ( & V_21 -> V_68 , V_69 ,
( unsigned long ) V_21 ) ;
} else {
F_24 ( & V_21 -> V_68 , V_70 ,
( unsigned long ) V_21 ) ;
}
}
F_13 (irq_ptr, q, i) {
F_22 ( L_2 , V_22 ) ;
F_18 ( V_21 , V_15 , V_56 -> V_71 , V_22 ) ;
V_21 -> V_64 . V_72 . V_73 = V_62 ;
V_62 += V_27 ;
V_21 -> V_48 = 0 ;
V_21 -> V_64 . V_72 . V_74 = V_56 -> V_74 ;
F_19 ( V_21 , V_15 , V_59 , V_22 ) ;
V_59 += V_27 ;
F_24 ( & V_21 -> V_68 , V_75 ,
( unsigned long ) V_21 ) ;
F_25 ( & V_21 -> V_64 . V_72 . V_76 , ( void (*) ( unsigned long ) )
& V_77 , ( unsigned long ) V_21 ) ;
}
}
static void F_26 ( struct V_14 * V_15 , unsigned char V_78 )
{
if ( V_78 & V_79 )
V_15 -> V_80 . V_81 = 1 ;
if ( V_78 & V_82 )
V_15 -> V_80 . V_28 = 1 ;
if ( V_78 & V_83 )
V_15 -> V_80 . V_84 = 1 ;
if ( ! ( V_78 & V_85 ) )
V_15 -> V_80 . V_86 = 1 ;
if ( ! ( V_78 & V_87 ) )
V_15 -> V_80 . V_88 = 1 ;
}
static void F_27 ( struct V_14 * V_15 ,
unsigned char V_78 , unsigned long V_89 )
{
if ( ! ( V_15 -> V_24 . V_90 & V_91 ) )
goto V_92;
if ( ! ( V_78 & V_93 ) ||
( ! ( V_78 & V_94 ) ) )
goto V_92;
V_15 -> V_95 = V_89 ;
F_22 ( L_3 ) ;
F_22 ( L_4 , V_15 -> V_95 ) ;
return;
V_92:
V_15 -> V_95 = 0 ;
V_15 -> V_24 . V_90 &= ~ V_91 ;
F_22 ( L_5 ) ;
}
int F_28 ( struct V_14 * V_15 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 ;
int V_37 ;
F_22 ( L_6 , V_97 -> V_102 ) ;
if ( ! V_15 ) {
V_101 = (struct V_100 * ) F_16 ( V_10 ) ;
if ( ! V_101 )
return - V_11 ;
} else {
V_101 = (struct V_100 * ) V_15 -> V_103 ;
}
V_37 = F_29 ( * V_97 , V_101 ) ;
if ( V_37 )
goto V_72;
if ( ! ( V_101 -> V_104 . V_105 & V_106 ) ||
! ( V_101 -> V_104 . V_105 & V_107 ) ||
( V_101 -> V_104 . V_108 != V_97 -> V_102 ) )
V_37 = - V_109 ;
if ( ! V_37 )
memcpy ( V_99 , & V_101 -> V_104 , sizeof( * V_99 ) ) ;
V_72:
if ( ! V_15 )
F_6 ( ( unsigned long ) V_101 ) ;
return V_37 ;
}
void F_30 ( struct V_14 * V_15 )
{
unsigned char V_78 ;
int V_37 ;
V_37 = F_28 ( V_15 , & V_15 -> V_97 , & V_15 -> V_110 ) ;
if ( V_37 ) {
F_31 ( L_7 , V_15 -> V_97 . V_102 ) ;
F_31 ( L_8 , V_37 ) ;
V_78 = V_79 | V_82 |
V_83 ;
} else
V_78 = V_15 -> V_110 . V_111 ;
F_27 ( V_15 , V_78 , V_15 -> V_110 . V_95 ) ;
F_26 ( V_15 , V_78 ) ;
F_22 ( L_9 , V_78 , V_15 -> V_110 . V_112 ) ;
F_22 ( L_10 , V_15 -> V_110 . V_113 , V_15 -> V_24 . V_114 ) ;
}
void F_32 ( struct V_14 * V_15 )
{
struct V_20 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_115 ; V_22 ++ ) {
V_21 = V_15 -> V_38 [ V_22 ] ;
if ( V_21 ) {
F_6 ( ( unsigned long ) V_21 -> V_29 ) ;
F_4 ( V_34 , V_21 ) ;
}
}
for ( V_22 = 0 ; V_22 < V_115 ; V_22 ++ ) {
V_21 = V_15 -> V_39 [ V_22 ] ;
if ( V_21 ) {
if ( V_21 -> V_64 . V_72 . V_116 ) {
int V_117 ;
for ( V_117 = 0 ; V_117 < V_27 ; ++ V_117 ) {
struct V_1 * V_4 = V_21 -> V_64 . V_72 . V_118 [ V_117 ] ;
if ( V_4 ) {
F_3 ( V_4 ) ;
V_21 -> V_64 . V_72 . V_118 [ V_117 ] = NULL ;
}
}
F_33 ( & V_21 -> V_64 . V_72 ) ;
}
F_6 ( ( unsigned long ) V_21 -> V_29 ) ;
F_4 ( V_34 , V_21 ) ;
}
}
F_6 ( ( unsigned long ) V_15 -> V_119 ) ;
F_6 ( V_15 -> V_103 ) ;
F_6 ( ( unsigned long ) V_15 ) ;
}
static void F_34 ( struct V_14 * V_15 ,
struct V_20 * * V_32 ,
int V_22 , int V_43 )
{
V_15 -> V_119 -> V_120 [ V_22 + V_43 ] . V_121 =
( unsigned long ) V_32 [ V_22 ] -> V_29 ;
V_15 -> V_119 -> V_120 [ V_22 + V_43 ] . V_50 =
( unsigned long ) V_32 [ V_22 ] -> V_46 ;
V_15 -> V_119 -> V_120 [ V_22 + V_43 ] . V_51 =
( unsigned long ) & V_32 [ V_22 ] -> V_52 . V_53 [ 0 ] ;
V_15 -> V_119 -> V_120 [ V_22 + V_43 ] . V_122 = V_123 >> 4 ;
V_15 -> V_119 -> V_120 [ V_22 + V_43 ] . V_124 = V_123 >> 4 ;
V_15 -> V_119 -> V_120 [ V_22 + V_43 ] . V_125 = V_123 >> 4 ;
V_15 -> V_119 -> V_120 [ V_22 + V_43 ] . V_126 = V_123 >> 4 ;
}
static void F_35 ( struct V_14 * V_15 ,
struct V_55 * V_56 )
{
int V_22 ;
V_15 -> V_119 -> V_127 = V_56 -> V_128 ;
V_15 -> V_119 -> V_114 = V_56 -> V_129 ;
V_15 -> V_119 -> V_130 = V_56 -> V_131 ;
V_15 -> V_119 -> V_132 = V_56 -> V_133 ;
V_15 -> V_119 -> V_134 = sizeof( struct V_135 ) / 4 ;
V_15 -> V_119 -> V_136 = sizeof( struct V_135 ) / 4 ;
V_15 -> V_119 -> V_137 = ( unsigned long ) & V_15 -> V_24 ;
V_15 -> V_119 -> V_138 = V_123 >> 4 ;
for ( V_22 = 0 ; V_22 < V_56 -> V_131 ; V_22 ++ )
F_34 ( V_15 , V_15 -> V_38 , V_22 , 0 ) ;
for ( V_22 = 0 ; V_22 < V_56 -> V_133 ; V_22 ++ )
F_34 ( V_15 , V_15 -> V_39 , V_22 ,
V_56 -> V_131 ) ;
}
static void F_36 ( struct V_14 * V_15 ,
struct V_55 * V_139 )
{
if ( F_10 () )
V_15 -> V_24 . V_90 |= V_91 ;
V_15 -> V_24 . V_90 |= V_139 -> V_140 ;
V_15 -> V_24 . V_127 = V_139 -> V_128 ;
if ( V_139 -> V_131 )
V_15 -> V_24 . V_141 =
( unsigned long ) ( V_15 -> V_38 [ 0 ] -> V_29 ) ;
if ( V_139 -> V_133 )
V_15 -> V_24 . V_142 =
( unsigned long ) ( V_15 -> V_39 [ 0 ] -> V_29 ) ;
memcpy ( V_15 -> V_24 . V_143 , V_139 -> V_144 , 8 ) ;
}
int F_37 ( struct V_55 * V_139 )
{
struct V_145 * V_145 ;
struct V_14 * V_15 = V_139 -> V_146 -> V_147 -> V_148 ;
int V_37 ;
memset ( & V_15 -> V_24 , 0 , sizeof( V_15 -> V_24 ) ) ;
memset ( & V_15 -> V_80 , 0 , sizeof( V_15 -> V_80 ) ) ;
memset ( & V_15 -> V_149 , 0 , sizeof( V_15 -> V_149 ) ) ;
memset ( & V_15 -> V_110 , 0 , sizeof( V_15 -> V_110 ) ) ;
memset ( & V_15 -> V_150 , 0 , sizeof( V_15 -> V_150 ) ) ;
V_15 -> V_151 = V_15 -> V_152 = NULL ;
V_15 -> V_95 = V_15 -> V_153 = V_15 -> V_154 = 0 ;
memset ( V_15 -> V_119 , 0 , sizeof( struct V_119 ) ) ;
V_15 -> V_155 = V_139 -> V_155 ;
V_15 -> V_35 = V_139 -> V_131 ;
V_15 -> V_36 = V_139 -> V_133 ;
V_15 -> V_146 = V_139 -> V_146 ;
F_38 ( V_15 -> V_146 , & V_15 -> V_97 ) ;
F_21 ( V_15 , V_139 ) ;
F_36 ( V_15 , V_139 ) ;
F_39 ( V_15 ) ;
F_11 ( V_15 , V_139 -> V_16 ,
V_139 -> V_17 ,
V_139 -> V_18 ,
V_139 -> V_19 ) ;
F_35 ( V_15 , V_139 ) ;
V_145 = F_40 ( V_139 -> V_146 , V_156 ) ;
if ( ! V_145 ) {
F_31 ( L_11 , V_15 -> V_97 . V_102 ) ;
V_37 = - V_109 ;
goto V_157;
}
V_15 -> V_158 = * V_145 ;
V_145 = F_40 ( V_139 -> V_146 , V_159 ) ;
if ( ! V_145 ) {
F_31 ( L_12 , V_15 -> V_97 . V_102 ) ;
V_37 = - V_109 ;
goto V_157;
}
V_15 -> V_160 = * V_145 ;
V_15 -> V_161 = V_139 -> V_146 -> V_40 ;
V_139 -> V_146 -> V_40 = V_162 ;
return 0 ;
V_157:
F_32 ( V_15 ) ;
return V_37 ;
}
void F_41 ( struct V_14 * V_15 ,
struct V_163 * V_146 )
{
char V_164 [ 80 ] ;
snprintf ( V_164 , 80 , L_13
L_14 ,
F_42 ( & V_146 -> V_165 ) ,
( V_15 -> V_24 . V_127 == V_166 ) ? L_15 :
( ( V_15 -> V_24 . V_127 == V_167 ) ? L_16 : L_17 ) ,
V_15 -> V_97 . V_102 ,
F_23 ( V_15 ) ,
( V_15 -> V_95 ) ? 1 : 0 ,
( V_15 -> V_24 . V_114 & V_168 ) ? 1 : 0 ,
V_12 . V_169 ,
( V_15 -> V_80 . V_81 ) ? L_18 : L_19 ,
( V_15 -> V_80 . V_28 ) ? L_20 : L_19 ,
( V_15 -> V_80 . V_84 ) ? L_21 : L_19 ,
( V_15 -> V_80 . V_86 ) ? L_22 : L_19 ,
( V_15 -> V_80 . V_88 ) ? L_23 : L_19 ) ;
F_43 ( V_170 L_24 , V_164 ) ;
}
int F_44 ( struct V_171 * V_172 )
{
V_172 -> V_118 = F_45 ( sizeof( struct V_1 * ) * V_27 ,
V_3 ) ;
if ( ! V_172 -> V_118 ) {
V_172 -> V_116 = 0 ;
return - V_11 ;
}
V_172 -> V_116 = 1 ;
return 0 ;
}
void F_33 ( struct V_171 * V_21 )
{
F_46 ( V_21 -> V_118 ) ;
V_21 -> V_118 = NULL ;
V_21 -> V_116 = 0 ;
}
int T_2 F_47 ( void )
{
int V_37 ;
V_34 = F_48 ( L_25 , sizeof( struct V_20 ) ,
256 , 0 , NULL ) ;
if ( ! V_34 )
return - V_11 ;
V_2 = F_48 ( L_26 ,
sizeof( struct V_1 ) ,
sizeof( struct V_1 ) ,
0 ,
NULL ) ;
if ( ! V_2 ) {
V_37 = - V_11 ;
goto V_173;
}
F_22 ( L_27 ,
( V_12 . V_174 ) ? 1 : 0 ) ;
F_22 ( L_28 , ( F_10 () ) ? 1 : 0 ) ;
V_37 = 0 ;
V_72:
return V_37 ;
V_173:
F_49 ( V_34 ) ;
goto V_72;
}
void F_50 ( void )
{
F_49 ( V_2 ) ;
F_49 ( V_34 ) ;
}
