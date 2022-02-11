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
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ )
V_14 -> V_42 [ V_16 ] = * V_39 ++ ;
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
static void F_17 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
struct V_13 * V_14 ;
void * * V_52 = V_51 -> V_53 ;
void * * V_54 = V_51 -> V_55 ;
struct V_56 * V_57 =
V_51 -> V_57 ;
int V_15 ;
F_8 (irq_ptr, q, i) {
F_18 ( L_1 , V_15 ) ;
F_14 ( V_14 , V_8 , V_51 -> V_58 , V_15 ) ;
V_14 -> V_43 = 1 ;
V_14 -> V_59 . V_60 . V_61 = V_51 -> V_62 ?
V_51 -> V_62 [ V_15 ] : NULL ;
F_15 ( V_14 , V_8 , V_52 , V_15 ) ;
V_52 += V_20 ;
if ( F_19 ( V_8 ) ) {
F_20 ( & V_14 -> V_63 , V_64 ,
( unsigned long ) V_14 ) ;
} else {
F_20 ( & V_14 -> V_63 , V_65 ,
( unsigned long ) V_14 ) ;
}
}
F_9 (irq_ptr, q, i) {
F_18 ( L_2 , V_15 ) ;
F_14 ( V_14 , V_8 , V_51 -> V_66 , V_15 ) ;
V_14 -> V_59 . V_67 . V_68 = V_57 ;
V_57 += V_20 ;
V_14 -> V_43 = 0 ;
V_14 -> V_59 . V_67 . V_69 = V_51 -> V_69 ;
F_15 ( V_14 , V_8 , V_54 , V_15 ) ;
V_54 += V_20 ;
F_20 ( & V_14 -> V_63 , V_70 ,
( unsigned long ) V_14 ) ;
F_21 ( & V_14 -> V_59 . V_67 . V_71 , ( void (*) ( unsigned long ) )
& V_72 , ( unsigned long ) V_14 ) ;
}
}
static void F_22 ( struct V_7 * V_8 , unsigned char V_73 )
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
static void F_23 ( struct V_7 * V_8 ,
unsigned char V_73 , unsigned long V_84 )
{
if ( ! ( V_8 -> V_17 . V_85 & V_86 ) )
goto V_87;
if ( ! ( V_73 & V_88 ) ||
( ! ( V_73 & V_89 ) ) )
goto V_87;
V_8 -> V_90 = V_84 ;
F_18 ( L_3 ) ;
F_18 ( L_4 , V_8 -> V_90 ) ;
return;
V_87:
V_8 -> V_90 = 0 ;
V_8 -> V_17 . V_85 &= ~ V_86 ;
F_18 ( L_5 ) ;
}
int F_24 ( struct V_7 * V_8 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 ;
int V_32 ;
F_18 ( L_6 , V_92 -> V_97 ) ;
if ( ! V_8 ) {
V_96 = (struct V_95 * ) F_12 ( V_28 ) ;
if ( ! V_96 )
return - V_29 ;
} else {
V_96 = (struct V_95 * ) V_8 -> V_98 ;
}
V_32 = F_25 ( * V_92 , V_96 ) ;
if ( V_32 )
goto V_67;
if ( ! ( V_96 -> V_99 . V_100 & V_101 ) ||
! ( V_96 -> V_99 . V_100 & V_102 ) ||
( V_96 -> V_99 . V_103 != V_92 -> V_97 ) )
V_32 = - V_104 ;
if ( ! V_32 )
memcpy ( V_94 , & V_96 -> V_99 , sizeof( * V_94 ) ) ;
V_67:
if ( ! V_8 )
F_26 ( ( unsigned long ) V_96 ) ;
return V_32 ;
}
void F_27 ( struct V_7 * V_8 )
{
unsigned char V_73 ;
int V_32 ;
V_32 = F_24 ( V_8 , & V_8 -> V_92 , & V_8 -> V_105 ) ;
if ( V_32 ) {
F_28 ( L_7 , V_8 -> V_92 . V_97 ) ;
F_28 ( L_8 , V_32 ) ;
V_73 = V_74 | V_77 |
V_78 ;
} else
V_73 = V_8 -> V_105 . V_106 ;
F_23 ( V_8 , V_73 , V_8 -> V_105 . V_90 ) ;
F_22 ( V_8 , V_73 ) ;
F_18 ( L_9 , V_73 , V_8 -> V_105 . V_107 ) ;
F_18 ( L_10 , V_8 -> V_105 . V_108 , V_8 -> V_17 . V_109 ) ;
}
void F_29 ( struct V_7 * V_8 )
{
struct V_13 * V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_110 ; V_15 ++ ) {
V_14 = V_8 -> V_33 [ V_15 ] ;
if ( V_14 ) {
F_26 ( ( unsigned long ) V_14 -> V_22 ) ;
F_4 ( V_27 , V_14 ) ;
}
}
for ( V_15 = 0 ; V_15 < V_110 ; V_15 ++ ) {
V_14 = V_8 -> V_34 [ V_15 ] ;
if ( V_14 ) {
if ( V_14 -> V_59 . V_67 . V_111 ) {
int V_112 ;
for ( V_112 = 0 ; V_112 < V_20 ; ++ V_112 ) {
struct V_1 * V_4 = V_14 -> V_59 . V_67 . V_113 [ V_112 ] ;
if ( V_4 ) {
F_3 ( V_4 ) ;
V_14 -> V_59 . V_67 . V_113 [ V_112 ] = NULL ;
}
}
F_30 ( & V_14 -> V_59 . V_67 ) ;
}
F_26 ( ( unsigned long ) V_14 -> V_22 ) ;
F_4 ( V_27 , V_14 ) ;
}
}
F_26 ( ( unsigned long ) V_8 -> V_114 ) ;
F_26 ( V_8 -> V_98 ) ;
F_26 ( ( unsigned long ) V_8 ) ;
}
static void F_31 ( struct V_7 * V_8 ,
struct V_13 * * V_25 ,
int V_15 , int V_38 )
{
V_8 -> V_114 -> V_115 [ V_15 + V_38 ] . V_116 =
( unsigned long ) V_25 [ V_15 ] -> V_22 ;
V_8 -> V_114 -> V_115 [ V_15 + V_38 ] . V_45 =
( unsigned long ) V_25 [ V_15 ] -> V_41 ;
V_8 -> V_114 -> V_115 [ V_15 + V_38 ] . V_46 =
( unsigned long ) & V_25 [ V_15 ] -> V_47 . V_48 [ 0 ] ;
V_8 -> V_114 -> V_115 [ V_15 + V_38 ] . V_117 = V_118 >> 4 ;
V_8 -> V_114 -> V_115 [ V_15 + V_38 ] . V_119 = V_118 >> 4 ;
V_8 -> V_114 -> V_115 [ V_15 + V_38 ] . V_120 = V_118 >> 4 ;
V_8 -> V_114 -> V_115 [ V_15 + V_38 ] . V_121 = V_118 >> 4 ;
}
static void F_32 ( struct V_7 * V_8 ,
struct V_50 * V_51 )
{
int V_15 ;
V_8 -> V_114 -> V_122 = V_51 -> V_123 ;
V_8 -> V_114 -> V_109 = V_51 -> V_124 ;
V_8 -> V_114 -> V_125 = V_51 -> V_126 ;
V_8 -> V_114 -> V_127 = V_51 -> V_128 ;
V_8 -> V_114 -> V_129 = sizeof( struct V_130 ) / 4 ;
V_8 -> V_114 -> V_131 = sizeof( struct V_130 ) / 4 ;
V_8 -> V_114 -> V_132 = ( unsigned long ) & V_8 -> V_17 ;
V_8 -> V_114 -> V_133 = V_118 >> 4 ;
for ( V_15 = 0 ; V_15 < V_51 -> V_126 ; V_15 ++ )
F_31 ( V_8 , V_8 -> V_33 , V_15 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_51 -> V_128 ; V_15 ++ )
F_31 ( V_8 , V_8 -> V_34 , V_15 ,
V_51 -> V_126 ) ;
}
static void F_33 ( struct V_7 * V_8 ,
struct V_50 * V_134 )
{
if ( F_5 () )
V_8 -> V_17 . V_85 |= V_86 ;
V_8 -> V_17 . V_85 |= V_134 -> V_135 ;
V_8 -> V_17 . V_122 = V_134 -> V_123 ;
if ( V_134 -> V_126 )
V_8 -> V_17 . V_136 =
( unsigned long ) ( V_8 -> V_33 [ 0 ] -> V_22 ) ;
if ( V_134 -> V_128 )
V_8 -> V_17 . V_137 =
( unsigned long ) ( V_8 -> V_34 [ 0 ] -> V_22 ) ;
memcpy ( V_8 -> V_17 . V_138 , V_134 -> V_139 , 8 ) ;
}
int F_34 ( struct V_50 * V_134 )
{
struct V_140 * V_140 ;
struct V_7 * V_8 = V_134 -> V_141 -> V_142 -> V_143 ;
int V_32 ;
memset ( & V_8 -> V_17 , 0 , sizeof( V_8 -> V_17 ) ) ;
memset ( & V_8 -> V_75 , 0 , sizeof( V_8 -> V_75 ) ) ;
memset ( & V_8 -> V_144 , 0 , sizeof( V_8 -> V_144 ) ) ;
memset ( & V_8 -> V_105 , 0 , sizeof( V_8 -> V_105 ) ) ;
memset ( & V_8 -> V_145 , 0 , sizeof( V_8 -> V_145 ) ) ;
V_8 -> V_146 = V_8 -> V_147 = NULL ;
V_8 -> V_90 = V_8 -> V_148 = V_8 -> V_149 = 0 ;
memset ( V_8 -> V_114 , 0 , sizeof( struct V_114 ) ) ;
V_8 -> V_150 = V_134 -> V_150 ;
V_8 -> V_30 = V_134 -> V_126 ;
V_8 -> V_31 = V_134 -> V_128 ;
V_8 -> V_141 = V_134 -> V_141 ;
F_35 ( V_8 -> V_141 , & V_8 -> V_92 ) ;
F_17 ( V_8 , V_134 ) ;
F_33 ( V_8 , V_134 ) ;
F_36 ( V_8 ) ;
F_7 ( V_8 , V_134 -> V_9 ,
V_134 -> V_10 ,
V_134 -> V_11 ,
V_134 -> V_12 ) ;
F_32 ( V_8 , V_134 ) ;
V_140 = F_37 ( V_134 -> V_141 , V_151 ) ;
if ( ! V_140 ) {
F_28 ( L_11 , V_8 -> V_92 . V_97 ) ;
V_32 = - V_104 ;
goto V_152;
}
V_8 -> V_153 = * V_140 ;
V_140 = F_37 ( V_134 -> V_141 , V_154 ) ;
if ( ! V_140 ) {
F_28 ( L_12 , V_8 -> V_92 . V_97 ) ;
V_32 = - V_104 ;
goto V_152;
}
V_8 -> V_155 = * V_140 ;
V_8 -> V_156 = V_134 -> V_141 -> V_35 ;
V_134 -> V_141 -> V_35 = V_157 ;
return 0 ;
V_152:
F_29 ( V_8 ) ;
return V_32 ;
}
void F_38 ( struct V_7 * V_8 ,
struct V_158 * V_141 )
{
char V_159 [ 80 ] ;
snprintf ( V_159 , 80 , L_13
L_14 ,
F_39 ( & V_141 -> V_160 ) ,
( V_8 -> V_17 . V_122 == V_161 ) ? L_15 :
( ( V_8 -> V_17 . V_122 == V_162 ) ? L_16 : L_17 ) ,
V_8 -> V_92 . V_97 ,
F_19 ( V_8 ) ,
( V_8 -> V_90 ) ? 1 : 0 ,
( V_8 -> V_17 . V_109 & V_163 ) ? 1 : 0 ,
V_5 . V_164 ,
( V_8 -> V_75 . V_76 ) ? L_18 : L_19 ,
( V_8 -> V_75 . V_21 ) ? L_20 : L_19 ,
( V_8 -> V_75 . V_79 ) ? L_21 : L_19 ,
( V_8 -> V_75 . V_81 ) ? L_22 : L_19 ,
( V_8 -> V_75 . V_83 ) ? L_23 : L_19 ) ;
F_40 ( V_165 L_24 , V_159 ) ;
}
int F_41 ( struct V_166 * V_167 )
{
V_167 -> V_113 = F_42 ( sizeof( struct V_1 * ) * V_20 ,
V_3 ) ;
if ( ! V_167 -> V_113 ) {
V_167 -> V_111 = 0 ;
return - V_29 ;
}
V_167 -> V_111 = 1 ;
return 0 ;
}
void F_30 ( struct V_166 * V_14 )
{
F_43 ( V_14 -> V_113 ) ;
V_14 -> V_113 = NULL ;
V_14 -> V_111 = 0 ;
}
int T_2 F_44 ( void )
{
int V_32 ;
V_27 = F_45 ( L_25 , sizeof( struct V_13 ) ,
256 , 0 , NULL ) ;
if ( ! V_27 )
return - V_29 ;
V_2 = F_45 ( L_26 ,
sizeof( struct V_1 ) ,
sizeof( struct V_1 ) ,
0 ,
NULL ) ;
if ( ! V_2 ) {
V_32 = - V_29 ;
goto V_168;
}
F_18 ( L_27 ,
( V_5 . V_169 ) ? 1 : 0 ) ;
F_18 ( L_28 , ( F_5 () ) ? 1 : 0 ) ;
V_32 = 0 ;
V_67:
return V_32 ;
V_168:
F_46 ( V_27 ) ;
goto V_67;
}
void F_47 ( void )
{
F_46 ( V_2 ) ;
F_46 ( V_27 ) ;
}
