void F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
unsigned long V_3 ;
long V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_3 ( V_1 != F_4 () ) ;
if ( F_5 ( V_9 ) )
F_6 ( V_1 ) . V_10 = 1 ;
if ( F_5 ( V_11 ) )
F_6 ( V_1 ) . V_12 = 1 ;
V_3 = F_7 ( & F_6 ( V_1 ) ) ;
V_4 = F_8 ( V_2 , V_3 ) ;
if ( V_4 ) {
F_9 ( L_1
L_2 , V_1 , V_2 , V_3 , V_4 ) ;
return;
}
V_3 = F_7 ( V_13 [ V_1 ] . V_14 ) ;
if ( F_10 ( V_15 ) ) {
V_4 = F_11 ( V_2 , V_3 ) ;
if ( V_4 )
F_9 ( L_3
L_4 ,
V_1 , V_2 , V_3 , V_4 ) ;
}
V_6 = & V_13 [ V_1 ] ;
V_8 = V_6 -> V_16 ;
if ( V_8 ) {
V_6 -> V_17 = 0 ;
V_6 -> V_18 = V_8 ;
F_6 ( V_1 ) . V_19 = 0 ;
V_8 -> V_20 = F_12 ( V_21 ) ;
V_4 = F_13 ( V_2 , F_7 ( V_8 ) ) ;
if ( V_4 )
F_9 ( L_5
L_6 , F_4 () ,
V_2 , V_4 ) ;
F_6 ( V_1 ) . V_22 = 2 ;
}
}
static long F_14 ( unsigned long V_23 ,
unsigned long V_24 , unsigned long V_25 ,
unsigned long V_26 , unsigned long V_27 ,
int V_28 , int V_29 , int V_30 )
{
unsigned long V_31 ;
unsigned long V_32 ;
unsigned long V_33 ;
unsigned long V_34 , V_35 ;
if ( ! ( V_27 & V_36 ) )
F_15 ( L_7
L_8 ,
V_23 , V_24 , V_25 , V_26 , V_27 , V_28 ) ;
V_34 = F_16 ( V_24 , V_28 , V_29 , V_30 ) | V_27 | V_37 ;
V_35 = F_17 ( V_25 , V_28 , V_29 ) | V_26 ;
if ( ! ( V_27 & V_36 ) )
F_15 ( L_9 , V_34 , V_35 ) ;
V_32 = 0 ;
if ( ( V_26 & V_38 ) && ! ( V_26 & V_39 ) )
V_35 &= ~ V_40 ;
if ( F_10 ( V_41 ) && ! ( V_35 & V_42 ) )
V_32 |= V_43 ;
V_31 = F_18 ( V_32 , V_23 , V_34 , V_35 , & V_33 ) ;
if ( F_19 ( V_31 == V_44 ) ) {
if ( ! ( V_27 & V_36 ) )
F_15 ( L_10 ) ;
return - 1 ;
}
if ( F_19 ( V_31 != V_45 ) ) {
if ( ! ( V_27 & V_36 ) )
F_15 ( L_11 , V_31 ) ;
return - 2 ;
}
if ( ! ( V_27 & V_36 ) )
F_15 ( L_12 , V_33 & 7 ) ;
return ( V_33 & 7 ) | ( ! ! ( V_27 & V_46 ) << 3 ) ;
}
static long F_20 ( unsigned long V_23 )
{
unsigned long V_47 ;
unsigned long V_31 ;
int V_48 ;
unsigned long V_49 , V_50 ;
V_47 = F_21 () & 0x7 ;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
V_31 = F_22 ( V_52 , V_23 + V_47 ,
( 0x1UL << 4 ) , & V_49 , & V_50 ) ;
if ( V_31 == V_45 )
return V_48 ;
F_23 ( V_31 != V_53 && V_31 != V_54 ) ;
V_47 ++ ;
V_47 &= 0x7 ;
}
return - 1 ;
}
static void F_24 ( void )
{
unsigned long V_55 = 1UL << V_56 ;
unsigned long V_57 = V_55 >> 4 ;
struct {
unsigned long V_58 ;
unsigned long V_59 ;
} V_60 [ 4 ] ;
long V_31 ;
unsigned long V_48 , V_61 ;
for ( V_48 = 0 ; V_48 < V_57 ; V_48 += 4 ) {
V_31 = F_25 ( 0 , V_48 , ( void * ) V_60 ) ;
if ( V_31 != V_45 )
continue;
for ( V_61 = 0 ; V_61 < 4 ; V_61 ++ ) {
if ( ( V_60 [ V_61 ] . V_58 & V_62 ) ==
V_62 )
continue;
if ( V_60 [ V_61 ] . V_58 & V_37 )
F_26 ( 0 , V_48 + V_61 , 0 ,
& ( V_60 [ V_61 ] . V_58 ) , & ( V_60 [ V_61 ] . V_59 ) ) ;
}
}
#ifdef F_27
if ( F_10 ( V_63 ) && ! F_28 () ) {
long V_64 ;
V_64 = F_29 () ;
if ( V_64 && ! F_30 () )
F_31 ( L_13 ) ;
}
#endif
}
static long F_32 ( unsigned long V_33 ,
unsigned long V_65 ,
unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , unsigned long V_66 )
{
unsigned long V_31 ;
unsigned long V_32 = ( V_65 & 7 ) | V_67 ;
unsigned long V_68 ;
V_68 = F_33 ( V_24 , V_28 , V_30 ) ;
F_15 ( L_14 ,
V_68 , V_33 , V_32 , V_28 ) ;
V_31 = F_34 ( V_32 , V_33 , V_68 ) ;
if ( V_31 == V_53 ) {
F_15 ( L_15 ) ;
return - 1 ;
}
F_15 ( L_16 ) ;
F_23 ( V_31 != V_45 ) ;
return 0 ;
}
static unsigned long F_35 ( unsigned long V_33 )
{
unsigned long V_69 ;
unsigned long V_31 ;
unsigned long V_70 ;
unsigned long V_32 ;
V_32 = 0 ;
V_31 = F_36 ( V_32 , V_33 , & V_69 , & V_70 ) ;
F_23 ( V_31 != V_45 ) ;
return V_69 ;
}
static long F_37 ( unsigned long V_24 , int V_28 , int V_30 )
{
unsigned long V_71 ;
unsigned long V_48 ;
long V_33 ;
unsigned long V_68 , V_34 ;
V_71 = F_38 ( V_24 , V_72 [ V_28 ] . V_73 , V_30 ) ;
V_68 = F_33 ( V_24 , V_28 , V_30 ) ;
V_33 = ( V_71 & V_74 ) * V_51 ;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
V_34 = F_35 ( V_33 ) ;
if ( F_39 ( V_34 , V_68 ) && ( V_34 & V_37 ) )
return V_33 ;
++ V_33 ;
}
return - 1 ;
}
static void F_40 ( unsigned long V_65 ,
unsigned long V_75 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_31 , V_33 , V_76 , V_32 ;
V_76 = F_41 ( V_75 , V_30 ) ;
V_24 = F_42 ( V_75 , V_76 , V_30 ) ;
V_33 = F_37 ( V_24 , V_28 , V_30 ) ;
F_23 ( V_33 == - 1 ) ;
V_32 = V_65 & 7 ;
V_31 = F_34 ( V_32 , V_33 , 0 ) ;
F_23 ( V_31 != V_45 ) ;
}
static void F_43 ( unsigned long V_33 , unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , int V_77 )
{
unsigned long V_68 ;
unsigned long V_31 ;
unsigned long V_49 , V_50 ;
F_15 ( L_17 ,
V_33 , V_24 , V_28 , V_77 ) ;
V_68 = F_33 ( V_24 , V_28 , V_30 ) ;
V_31 = F_22 ( V_67 , V_33 , V_68 , & V_49 , & V_50 ) ;
if ( V_31 == V_53 )
return;
F_23 ( V_31 != V_45 ) ;
}
static void F_44 ( unsigned long * V_33 ,
unsigned long * V_24 , int V_78 ,
int V_28 , int V_30 )
{
unsigned long V_79 [ 8 ] ;
int V_48 = 0 , V_80 = 0 , V_64 ;
unsigned long V_32 = 0 ;
int V_81 = ! F_45 ( V_82 ) ;
if ( V_81 )
F_46 ( & V_83 , V_32 ) ;
for ( V_48 = 0 ; V_48 < V_78 ; V_48 ++ ) {
if ( ! F_10 ( V_84 ) ) {
F_43 ( V_33 [ V_48 ] , V_24 [ V_48 ] , V_28 , 0 ,
V_30 , 0 ) ;
} else {
V_79 [ V_80 ] = V_85 | V_86 | V_33 [ V_48 ] ;
V_79 [ V_80 + 1 ] = F_33 ( V_24 [ V_48 ] , V_28 , V_30 ) ;
V_80 += 2 ;
if ( V_80 == 8 ) {
V_64 = F_47 ( V_87 , V_79 ,
V_79 [ 0 ] , V_79 [ 1 ] , V_79 [ 2 ] ,
V_79 [ 3 ] , V_79 [ 4 ] , V_79 [ 5 ] ,
V_79 [ 6 ] , V_79 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
V_80 = 0 ;
}
}
}
if ( V_80 ) {
V_79 [ V_80 ] = V_88 ;
V_64 = F_47 ( V_87 , V_79 , V_79 [ 0 ] , V_79 [ 1 ] ,
V_79 [ 2 ] , V_79 [ 3 ] , V_79 [ 4 ] , V_79 [ 5 ] ,
V_79 [ 6 ] , V_79 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
}
if ( V_81 )
F_48 ( & V_83 , V_32 ) ;
}
static void F_49 ( unsigned long V_76 ,
unsigned long V_3 ,
unsigned char * V_89 ,
int V_28 , int V_30 , int V_77 )
{
int V_48 , V_90 = 0 ;
unsigned long V_91 = V_3 ;
unsigned int V_92 , V_93 ;
unsigned long V_94 [ V_95 ] ;
unsigned long V_96 [ V_95 ] ;
unsigned long V_73 , V_97 , V_24 = 0 , V_71 , V_33 ;
V_73 = V_72 [ V_28 ] . V_73 ;
V_92 = 1U << ( V_98 - V_73 ) ;
for ( V_48 = 0 ; V_48 < V_92 ; V_48 ++ ) {
V_93 = F_50 ( V_89 , V_48 ) ;
if ( ! V_93 )
continue;
V_97 = F_51 ( V_89 , V_48 ) ;
V_3 = V_91 + ( V_48 * ( 1ul << V_73 ) ) ;
V_24 = F_42 ( V_3 , V_76 , V_30 ) ;
V_71 = F_38 ( V_24 , V_73 , V_30 ) ;
if ( V_97 & V_99 )
V_71 = ~ V_71 ;
V_33 = ( V_71 & V_74 ) * V_51 ;
V_33 += V_97 & V_100 ;
V_96 [ V_90 ] = V_33 ;
V_94 [ V_90 ] = V_24 ;
if ( V_90 == V_95 - 1 ) {
F_44 ( V_96 ,
V_94 ,
V_95 ,
V_28 , V_30 ) ;
V_90 = 0 ;
} else
V_90 ++ ;
}
if ( V_90 )
F_44 ( V_96 , V_94 ,
V_90 , V_28 , V_30 ) ;
}
static void F_52 ( unsigned long V_75 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_33 , V_76 ;
V_76 = F_41 ( V_75 , V_30 ) ;
V_24 = F_42 ( V_75 , V_76 , V_30 ) ;
V_33 = F_37 ( V_24 , V_28 , V_30 ) ;
F_23 ( V_33 == - 1 ) ;
F_43 ( V_33 , V_24 , V_28 , 0 , V_30 , 0 ) ;
}
static void F_53 ( unsigned long V_101 , int V_77 )
{
unsigned long V_24 ;
unsigned long V_48 , V_80 , V_64 ;
unsigned long V_32 = 0 ;
struct V_102 * V_103 = F_54 ( & V_102 ) ;
int V_81 = ! F_45 ( V_82 ) ;
unsigned long V_79 [ 9 ] ;
unsigned long V_71 , V_90 , V_73 , V_97 , V_33 ;
T_1 V_104 ;
int V_28 , V_30 ;
if ( V_81 )
F_46 ( & V_83 , V_32 ) ;
V_28 = V_103 -> V_28 ;
V_30 = V_103 -> V_30 ;
V_80 = 0 ;
for ( V_48 = 0 ; V_48 < V_101 ; V_48 ++ ) {
V_24 = V_103 -> V_24 [ V_48 ] ;
V_104 = V_103 -> V_104 [ V_48 ] ;
F_55 (pte, psize, vpn, index, shift) {
V_71 = F_38 ( V_24 , V_73 , V_30 ) ;
V_97 = F_56 ( V_104 , V_90 ) ;
if ( V_97 & V_99 )
V_71 = ~ V_71 ;
V_33 = ( V_71 & V_74 ) * V_51 ;
V_33 += V_97 & V_100 ;
if ( ! F_10 ( V_84 ) ) {
F_43 ( V_33 , V_24 , V_28 ,
0 , V_30 , V_77 ) ;
} else {
V_79 [ V_80 ] = V_85 | V_86 | V_33 ;
V_79 [ V_80 + 1 ] = F_33 ( V_24 , V_28 ,
V_30 ) ;
V_80 += 2 ;
if ( V_80 == 8 ) {
V_64 = F_47 ( V_87 , V_79 ,
V_79 [ 0 ] , V_79 [ 1 ] , V_79 [ 2 ] ,
V_79 [ 3 ] , V_79 [ 4 ] , V_79 [ 5 ] ,
V_79 [ 6 ] , V_79 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
V_80 = 0 ;
}
}
} F_57 () ;
}
if ( V_80 ) {
V_79 [ V_80 ] = V_88 ;
V_64 = F_47 ( V_87 , V_79 , V_79 [ 0 ] , V_79 [ 1 ] ,
V_79 [ 2 ] , V_79 [ 3 ] , V_79 [ 4 ] , V_79 [ 5 ] ,
V_79 [ 6 ] , V_79 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
}
if ( V_81 )
F_48 ( & V_83 , V_32 ) ;
}
static int T_2 F_58 ( char * V_105 )
{
if ( strcmp ( V_105 , L_18 ) == 0 &&
F_10 ( V_84 ) ) {
F_59 ( V_106 L_19 ) ;
V_107 &= ~ V_84 ;
}
return 1 ;
}
void T_2 F_60 ( void )
{
V_108 . V_109 = F_43 ;
V_108 . V_110 = F_32 ;
V_108 . V_111 = F_40 ;
V_108 . V_112 = F_14 ;
V_108 . V_113 = F_20 ;
V_108 . V_114 = F_52 ;
V_108 . V_115 = F_53 ;
V_108 . V_116 = F_24 ;
V_108 . V_117 = F_49 ;
}
static int T_2 F_61 ( char * V_105 )
{
char * V_118 ;
V_118 = F_62 ( V_105 ) ;
if ( strcasecmp ( V_118 , L_20 ) == 0 || strcasecmp ( V_118 , L_18 ) == 0 ) {
F_59 ( V_106 L_21 ) ;
V_119 = 0 ;
return 1 ;
}
V_119 = 1 ;
F_59 ( V_106 L_22 ) ;
if ( strcasecmp ( V_118 , L_23 ) == 0 || strcasecmp ( V_118 , L_24 ) == 0 )
return 1 ;
return 0 ;
}
static void F_63 ( struct V_120 * V_120 , int V_121 ,
unsigned long V_122 )
{
int V_48 , V_61 ;
unsigned long V_123 , V_3 ;
V_123 = F_64 () ;
V_3 = F_7 ( ( unsigned long ) F_65 ( V_120 ) ) ;
for ( V_48 = 0 ; V_48 < ( 1 << V_121 ) ; V_48 ++ , V_3 += V_124 ) {
for ( V_61 = 0 ; V_61 < V_124 ; V_61 += V_123 )
F_66 ( V_125 , V_122 , V_3 + V_61 , 0 ) ;
}
}
void F_67 ( struct V_120 * V_120 , int V_121 )
{
if ( ! V_119 || ! F_10 ( V_126 ) )
return;
F_63 ( V_120 , V_121 , V_127 ) ;
}
void F_68 ( void )
{
F_69 ( & V_128 ) ;
}
void F_70 ( void )
{
F_71 ( & V_128 ) ;
}
void F_68 ( void )
{
V_129 ++ ;
}
void F_70 ( void )
{
V_129 -- ;
}
void F_72 ( unsigned long V_130 , unsigned long * args )
{
unsigned long V_32 ;
unsigned int * V_131 ;
if ( V_130 == V_132 )
return;
F_73 ( V_32 ) ;
V_131 = F_54 ( & V_133 ) ;
if ( * V_131 )
goto V_134;
( * V_131 ) ++ ;
F_74 () ;
F_75 ( V_130 , args ) ;
( * V_131 ) -- ;
V_134:
F_76 ( V_32 ) ;
}
void F_77 ( long V_130 , unsigned long V_135 ,
unsigned long * V_136 )
{
unsigned long V_32 ;
unsigned int * V_131 ;
if ( V_130 == V_132 )
return;
F_73 ( V_32 ) ;
V_131 = F_54 ( & V_133 ) ;
if ( * V_131 )
goto V_134;
( * V_131 ) ++ ;
F_78 ( V_130 , V_135 , V_136 ) ;
F_79 () ;
( * V_131 ) -- ;
V_134:
F_76 ( V_32 ) ;
}
int F_80 ( struct V_137 * V_138 )
{
int V_64 ;
unsigned long V_136 [ V_139 ] ;
V_64 = F_47 ( V_140 , V_136 ) ;
V_138 -> V_141 = V_136 [ 0 ] ;
V_138 -> V_142 = V_136 [ 1 ] ;
V_138 -> V_143 = ( V_136 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_138 -> V_144 = V_136 [ 2 ] & 0xffff ;
V_138 -> V_145 = ( V_136 [ 3 ] >> 7 * 8 ) & 0xff ;
V_138 -> V_146 = ( V_136 [ 3 ] >> 6 * 8 ) & 0xff ;
V_138 -> V_147 = V_136 [ 3 ] & 0xffffffffffffUL ;
V_138 -> V_148 = V_136 [ 4 ] ;
V_138 -> V_149 = V_136 [ 5 ] ;
V_138 -> V_150 = V_136 [ 6 ] ;
return V_64 ;
}
int F_81 ( struct V_151 * V_152 )
{
int V_64 ;
unsigned long V_136 [ V_139 ] = { 0 } ;
V_64 = F_47 ( V_153 , V_136 ) ;
V_152 -> V_154 = V_136 [ 0 ] ;
V_152 -> V_155 = V_136 [ 1 ] ;
V_152 -> V_156 = V_136 [ 2 ] ;
V_152 -> V_157 = V_136 [ 3 ] ;
return V_64 ;
}
