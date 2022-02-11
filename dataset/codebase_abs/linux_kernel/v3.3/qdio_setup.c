struct V_1 * F_1 ( void )
{
return F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_1 * V_4 )
{
F_4 ( V_2 , V_4 ) ;
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
V_14 -> V_59 . V_60 . V_61 = V_51 -> V_62 ?
V_51 -> V_62 [ V_15 ] : NULL ;
F_15 ( V_14 , V_8 , V_52 , V_15 ) ;
V_52 += V_20 ;
if ( F_20 ( V_8 ) ) {
F_21 ( & V_14 -> V_63 , V_64 ,
( unsigned long ) V_14 ) ;
} else {
F_21 ( & V_14 -> V_63 , V_65 ,
( unsigned long ) V_14 ) ;
}
}
F_9 (irq_ptr, q, i) {
F_19 ( L_2 , V_15 ) ;
F_14 ( V_14 , V_8 , V_51 -> V_66 , V_15 ) ;
V_14 -> V_59 . V_67 . V_68 = V_57 ;
V_57 += V_20 ;
V_14 -> V_43 = 0 ;
V_14 -> V_59 . V_67 . V_69 = V_51 -> V_69 ;
F_15 ( V_14 , V_8 , V_54 , V_15 ) ;
V_54 += V_20 ;
F_21 ( & V_14 -> V_63 , V_70 ,
( unsigned long ) V_14 ) ;
F_22 ( & V_14 -> V_59 . V_67 . V_71 , ( void (*) ( unsigned long ) )
& V_72 , ( unsigned long ) V_14 ) ;
}
}
static void F_23 ( struct V_7 * V_8 , unsigned char V_73 )
{
if ( V_73 & V_74 )
V_8 -> V_75 . V_76 = 1 ;
if ( V_73 & V_77 )
V_8 -> V_75 . V_21 = 1 ;
if ( V_73 & V_78 )
V_8 -> V_75 . V_79 = 1 ;
if ( ! ( V_73 & V_80 ) )
V_8 -> V_75 . V_81 = 1 ;
if ( ! ( V_73 & V_82 ) )
V_8 -> V_75 . V_83 = 1 ;
}
static void F_24 ( struct V_7 * V_8 ,
unsigned char V_73 , unsigned long V_84 )
{
if ( ! ( V_8 -> V_17 . V_85 & V_86 ) )
goto V_87;
if ( ! ( V_73 & V_88 ) ||
( ! ( V_73 & V_89 ) ) )
goto V_87;
V_8 -> V_90 = V_84 ;
F_19 ( L_3 ) ;
F_19 ( L_4 , V_8 -> V_90 ) ;
return;
V_87:
V_8 -> V_90 = 0 ;
V_8 -> V_17 . V_85 &= ~ V_86 ;
F_19 ( L_5 ) ;
}
int F_25 ( struct V_7 * V_8 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 ;
int V_32 ;
F_19 ( L_6 , V_92 -> V_97 ) ;
if ( V_8 != NULL )
V_96 = (struct V_95 * ) V_8 -> V_98 ;
else
V_96 = (struct V_95 * ) F_12 ( V_28 ) ;
memset ( V_96 , 0 , V_36 ) ;
V_96 -> V_99 = (struct V_100 ) {
. V_101 = 0x0010 ,
. V_102 = 0x0024 ,
} ;
V_96 -> V_103 = V_92 -> V_97 ;
V_96 -> V_104 = V_92 -> V_97 ;
V_96 -> V_105 = V_92 -> V_105 ;
if ( F_26 ( V_96 ) )
return - V_106 ;
V_32 = F_27 ( V_96 -> V_107 . V_102 ) ;
if ( V_32 )
return V_32 ;
if ( ! ( V_96 -> V_108 . V_109 & V_110 ) ||
! ( V_96 -> V_108 . V_109 & V_111 ) ||
( V_96 -> V_108 . V_112 != V_92 -> V_97 ) )
return - V_113 ;
if ( V_8 != NULL )
memcpy ( & V_8 -> V_114 , & V_96 -> V_108 ,
sizeof( struct V_93 ) ) ;
else {
memcpy ( V_94 , & V_96 -> V_108 ,
sizeof( struct V_93 ) ) ;
F_28 ( ( unsigned long ) V_96 ) ;
}
return 0 ;
}
void F_29 ( struct V_7 * V_8 )
{
unsigned char V_73 ;
int V_32 ;
V_32 = F_25 ( V_8 , & V_8 -> V_92 , NULL ) ;
if ( V_32 ) {
F_30 ( L_7 , V_8 -> V_92 . V_97 ) ;
F_30 ( L_8 , V_32 ) ;
V_73 = V_74 | V_77 |
V_78 ;
} else
V_73 = V_8 -> V_114 . V_115 ;
F_24 ( V_8 , V_73 , V_8 -> V_114 . V_90 ) ;
F_23 ( V_8 , V_73 ) ;
F_19 ( L_9 , V_73 ) ;
}
void F_31 ( struct V_7 * V_8 )
{
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_116 ; V_15 ++ ) {
V_14 = V_8 -> V_33 [ V_15 ] ;
if ( V_14 ) {
F_28 ( ( unsigned long ) V_14 -> V_22 ) ;
F_4 ( V_27 , V_14 ) ;
}
}
for ( V_15 = 0 ; V_15 < V_116 ; V_15 ++ ) {
V_14 = V_8 -> V_34 [ V_15 ] ;
if ( V_14 ) {
if ( V_14 -> V_59 . V_67 . V_117 ) {
int V_118 ;
for ( V_118 = 0 ; V_118 < V_20 ; ++ V_118 ) {
struct V_1 * V_4 = V_14 -> V_59 . V_67 . V_119 [ V_118 ] ;
if ( V_4 ) {
F_3 ( V_4 ) ;
V_14 -> V_59 . V_67 . V_119 [ V_118 ] = NULL ;
}
}
F_32 ( & V_14 -> V_59 . V_67 ) ;
}
F_28 ( ( unsigned long ) V_14 -> V_22 ) ;
F_4 ( V_27 , V_14 ) ;
}
}
F_28 ( ( unsigned long ) V_8 -> V_120 ) ;
F_28 ( V_8 -> V_98 ) ;
F_28 ( ( unsigned long ) V_8 ) ;
}
static void F_33 ( struct V_7 * V_8 ,
struct V_13 * * V_25 ,
int V_15 , int V_38 )
{
V_8 -> V_120 -> V_121 [ V_15 + V_38 ] . V_122 =
( unsigned long ) V_25 [ V_15 ] -> V_22 ;
V_8 -> V_120 -> V_121 [ V_15 + V_38 ] . V_45 =
( unsigned long ) V_25 [ V_15 ] -> V_41 ;
V_8 -> V_120 -> V_121 [ V_15 + V_38 ] . V_46 =
( unsigned long ) & V_25 [ V_15 ] -> V_47 . V_48 [ 0 ] ;
V_8 -> V_120 -> V_121 [ V_15 + V_38 ] . V_123 = V_124 >> 4 ;
V_8 -> V_120 -> V_121 [ V_15 + V_38 ] . V_125 = V_124 >> 4 ;
V_8 -> V_120 -> V_121 [ V_15 + V_38 ] . V_126 = V_124 >> 4 ;
V_8 -> V_120 -> V_121 [ V_15 + V_38 ] . V_127 = V_124 >> 4 ;
}
static void F_34 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
int V_15 ;
V_8 -> V_120 -> V_128 = V_51 -> V_129 ;
V_8 -> V_120 -> V_130 = V_51 -> V_131 ;
V_8 -> V_120 -> V_132 = V_51 -> V_133 ;
V_8 -> V_120 -> V_134 = V_51 -> V_135 ;
V_8 -> V_120 -> V_136 = sizeof( struct V_137 ) / 4 ;
V_8 -> V_120 -> V_138 = sizeof( struct V_137 ) / 4 ;
V_8 -> V_120 -> V_139 = ( unsigned long ) & V_8 -> V_17 ;
V_8 -> V_120 -> V_140 = V_124 >> 4 ;
for ( V_15 = 0 ; V_15 < V_51 -> V_133 ; V_15 ++ )
F_33 ( V_8 , V_8 -> V_33 , V_15 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_51 -> V_135 ; V_15 ++ )
F_33 ( V_8 , V_8 -> V_34 , V_15 ,
V_51 -> V_133 ) ;
}
static void F_35 ( struct V_7 * V_8 ,
struct V_50 * V_141 )
{
if ( F_5 () )
V_8 -> V_17 . V_85 |= V_86 ;
V_8 -> V_17 . V_85 |= V_141 -> V_142 ;
V_8 -> V_17 . V_128 = V_141 -> V_129 ;
if ( V_141 -> V_133 )
V_8 -> V_17 . V_143 =
( unsigned long ) ( V_8 -> V_33 [ 0 ] -> V_22 ) ;
if ( V_141 -> V_135 )
V_8 -> V_17 . V_144 =
( unsigned long ) ( V_8 -> V_34 [ 0 ] -> V_22 ) ;
memcpy ( V_8 -> V_17 . V_145 , V_141 -> V_146 , 8 ) ;
}
int F_36 ( struct V_50 * V_141 )
{
struct V_147 * V_147 ;
struct V_7 * V_8 = V_141 -> V_148 -> V_149 -> V_150 ;
int V_32 ;
memset ( & V_8 -> V_17 , 0 , sizeof( V_8 -> V_17 ) ) ;
memset ( & V_8 -> V_75 , 0 , sizeof( V_8 -> V_75 ) ) ;
memset ( & V_8 -> V_151 , 0 , sizeof( V_8 -> V_151 ) ) ;
memset ( & V_8 -> V_114 , 0 , sizeof( V_8 -> V_114 ) ) ;
memset ( & V_8 -> V_152 , 0 , sizeof( V_8 -> V_152 ) ) ;
V_8 -> V_153 = V_8 -> V_154 = NULL ;
V_8 -> V_90 = V_8 -> V_155 = V_8 -> V_156 = 0 ;
memset ( V_8 -> V_120 , 0 , sizeof( struct V_120 ) ) ;
V_8 -> V_157 = V_141 -> V_157 ;
V_8 -> V_30 = V_141 -> V_133 ;
V_8 -> V_31 = V_141 -> V_135 ;
V_8 -> V_92 = F_37 ( V_141 -> V_148 ) ;
V_8 -> V_148 = V_141 -> V_148 ;
F_18 ( V_8 , V_141 ) ;
F_35 ( V_8 , V_141 ) ;
F_38 ( V_8 ) ;
F_7 ( V_8 , V_141 -> V_9 ,
V_141 -> V_10 ,
V_141 -> V_11 ,
V_141 -> V_12 ) ;
F_34 ( V_8 , V_141 ) ;
V_147 = F_39 ( V_141 -> V_148 , V_158 ) ;
if ( ! V_147 ) {
F_30 ( L_10 , V_8 -> V_92 . V_97 ) ;
V_32 = - V_113 ;
goto V_159;
}
V_8 -> V_160 = * V_147 ;
V_147 = F_39 ( V_141 -> V_148 , V_161 ) ;
if ( ! V_147 ) {
F_30 ( L_11 , V_8 -> V_92 . V_97 ) ;
V_32 = - V_113 ;
goto V_159;
}
V_8 -> V_162 = * V_147 ;
V_8 -> V_163 = V_141 -> V_148 -> V_35 ;
V_141 -> V_148 -> V_35 = V_164 ;
return 0 ;
V_159:
F_31 ( V_8 ) ;
return V_32 ;
}
void F_40 ( struct V_7 * V_8 ,
struct V_165 * V_148 )
{
char V_166 [ 80 ] ;
snprintf ( V_166 , 80 , L_12
L_13 ,
F_41 ( & V_148 -> V_167 ) ,
( V_8 -> V_17 . V_128 == V_168 ) ? L_14 :
( ( V_8 -> V_17 . V_128 == V_169 ) ? L_15 : L_16 ) ,
V_8 -> V_92 . V_97 ,
F_20 ( V_8 ) ,
( V_8 -> V_90 ) ? 1 : 0 ,
( V_8 -> V_17 . V_130 & V_170 ) ? 1 : 0 ,
V_5 . V_171 ,
( V_8 -> V_75 . V_76 ) ? L_17 : L_18 ,
( V_8 -> V_75 . V_21 ) ? L_19 : L_18 ,
( V_8 -> V_75 . V_79 ) ? L_20 : L_18 ,
( V_8 -> V_75 . V_81 ) ? L_21 : L_18 ,
( V_8 -> V_75 . V_83 ) ? L_22 : L_18 ) ;
F_42 ( V_172 L_23 , V_166 ) ;
}
int F_43 ( struct V_173 * V_174 )
{
V_174 -> V_119 = F_44 ( sizeof( struct V_1 * ) * V_20 ,
V_3 ) ;
if ( ! V_174 -> V_119 ) {
V_174 -> V_117 = 0 ;
return - V_29 ;
}
V_174 -> V_117 = 1 ;
return 0 ;
}
void F_32 ( struct V_173 * V_14 )
{
F_45 ( V_14 -> V_119 ) ;
V_14 -> V_119 = NULL ;
V_14 -> V_117 = 0 ;
}
int T_2 F_46 ( void )
{
int V_32 ;
V_27 = F_47 ( L_24 , sizeof( struct V_13 ) ,
256 , 0 , NULL ) ;
if ( ! V_27 )
return - V_29 ;
V_2 = F_47 ( L_25 ,
sizeof( struct V_1 ) ,
sizeof( struct V_1 ) ,
0 ,
NULL ) ;
if ( ! V_2 ) {
V_32 = - V_29 ;
goto V_175;
}
F_19 ( L_26 ,
( V_5 . V_176 ) ? 1 : 0 ) ;
F_19 ( L_27 , ( F_5 () ) ? 1 : 0 ) ;
V_32 = 0 ;
V_67:
return V_32 ;
V_175:
F_48 ( V_27 ) ;
goto V_67;
}
void F_49 ( void )
{
F_48 ( V_2 ) ;
F_48 ( V_27 ) ;
}
