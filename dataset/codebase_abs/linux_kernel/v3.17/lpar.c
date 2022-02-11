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
if ( F_10 ( V_63 ) ) {
long V_64 ;
V_64 = F_28 () ;
if ( V_64 )
F_29 ( L_13 ) ;
}
#endif
}
static long F_30 ( unsigned long V_33 ,
unsigned long V_65 ,
unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , int V_66 )
{
unsigned long V_31 ;
unsigned long V_32 = ( V_65 & 7 ) | V_67 ;
unsigned long V_68 ;
V_68 = F_31 ( V_24 , V_28 , V_30 ) ;
F_15 ( L_14 ,
V_68 , V_33 , V_32 , V_28 ) ;
V_31 = F_32 ( V_32 , V_33 , V_68 ) ;
if ( V_31 == V_53 ) {
F_15 ( L_15 ) ;
return - 1 ;
}
F_15 ( L_16 ) ;
F_23 ( V_31 != V_45 ) ;
return 0 ;
}
static unsigned long F_33 ( unsigned long V_33 )
{
unsigned long V_69 ;
unsigned long V_31 ;
unsigned long V_70 ;
unsigned long V_32 ;
V_32 = 0 ;
V_31 = F_34 ( V_32 , V_33 , & V_69 , & V_70 ) ;
F_23 ( V_31 != V_45 ) ;
return V_69 ;
}
static long F_35 ( unsigned long V_24 , int V_28 , int V_30 )
{
unsigned long V_71 ;
unsigned long V_48 ;
long V_33 ;
unsigned long V_68 , V_34 ;
V_71 = F_36 ( V_24 , V_72 [ V_28 ] . V_73 , V_30 ) ;
V_68 = F_31 ( V_24 , V_28 , V_30 ) ;
V_33 = ( V_71 & V_74 ) * V_51 ;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
V_34 = F_33 ( V_33 ) ;
if ( F_37 ( V_34 , V_68 ) && ( V_34 & V_37 ) )
return V_33 ;
++ V_33 ;
}
return - 1 ;
}
static void F_38 ( unsigned long V_65 ,
unsigned long V_75 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_31 , V_33 , V_76 , V_32 ;
V_76 = F_39 ( V_75 , V_30 ) ;
V_24 = F_40 ( V_75 , V_76 , V_30 ) ;
V_33 = F_35 ( V_24 , V_28 , V_30 ) ;
F_23 ( V_33 == - 1 ) ;
V_32 = V_65 & 7 ;
V_31 = F_32 ( V_32 , V_33 , 0 ) ;
F_23 ( V_31 != V_45 ) ;
}
static void F_41 ( unsigned long V_33 , unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , int V_66 )
{
unsigned long V_68 ;
unsigned long V_31 ;
unsigned long V_49 , V_50 ;
F_15 ( L_17 ,
V_33 , V_24 , V_28 , V_66 ) ;
V_68 = F_31 ( V_24 , V_28 , V_30 ) ;
V_31 = F_22 ( V_67 , V_33 , V_68 , & V_49 , & V_50 ) ;
if ( V_31 == V_53 )
return;
F_23 ( V_31 != V_45 ) ;
}
static void F_42 ( unsigned long * V_33 ,
unsigned long * V_24 , int V_77 ,
int V_28 , int V_30 )
{
unsigned long V_78 [ 8 ] ;
int V_48 = 0 , V_79 = 0 , V_64 ;
unsigned long V_32 = 0 ;
int V_80 = ! F_43 ( V_81 ) ;
if ( V_80 )
F_44 ( & V_82 , V_32 ) ;
for ( V_48 = 0 ; V_48 < V_77 ; V_48 ++ ) {
if ( ! F_10 ( V_83 ) ) {
F_41 ( V_33 [ V_48 ] , V_24 [ V_48 ] , V_28 , 0 ,
V_30 , 0 ) ;
} else {
V_78 [ V_79 ] = V_84 | V_85 | V_33 [ V_48 ] ;
V_78 [ V_79 + 1 ] = F_31 ( V_24 [ V_48 ] , V_28 , V_30 ) ;
V_79 += 2 ;
if ( V_79 == 8 ) {
V_64 = F_45 ( V_86 , V_78 ,
V_78 [ 0 ] , V_78 [ 1 ] , V_78 [ 2 ] ,
V_78 [ 3 ] , V_78 [ 4 ] , V_78 [ 5 ] ,
V_78 [ 6 ] , V_78 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
V_79 = 0 ;
}
}
}
if ( V_79 ) {
V_78 [ V_79 ] = V_87 ;
V_64 = F_45 ( V_86 , V_78 , V_78 [ 0 ] , V_78 [ 1 ] ,
V_78 [ 2 ] , V_78 [ 3 ] , V_78 [ 4 ] , V_78 [ 5 ] ,
V_78 [ 6 ] , V_78 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
}
if ( V_80 )
F_46 ( & V_82 , V_32 ) ;
}
static void F_47 ( unsigned long V_76 ,
unsigned long V_3 ,
unsigned char * V_88 ,
int V_28 , int V_30 )
{
int V_48 , V_89 = 0 ;
unsigned long V_90 = V_3 ;
unsigned int V_91 , V_92 ;
unsigned long V_93 [ V_94 ] ;
unsigned long V_95 [ V_94 ] ;
unsigned long V_73 , V_96 , V_24 = 0 , V_71 , V_33 ;
V_73 = V_72 [ V_28 ] . V_73 ;
V_91 = 1U << ( V_97 - V_73 ) ;
for ( V_48 = 0 ; V_48 < V_91 ; V_48 ++ ) {
V_92 = F_48 ( V_88 , V_48 ) ;
if ( ! V_92 )
continue;
V_96 = F_49 ( V_88 , V_48 ) ;
V_3 = V_90 + ( V_48 * ( 1ul << V_73 ) ) ;
V_24 = F_40 ( V_3 , V_76 , V_30 ) ;
V_71 = F_36 ( V_24 , V_73 , V_30 ) ;
if ( V_96 & V_98 )
V_71 = ~ V_71 ;
V_33 = ( V_71 & V_74 ) * V_51 ;
V_33 += V_96 & V_99 ;
V_95 [ V_89 ] = V_33 ;
V_93 [ V_89 ] = V_24 ;
if ( V_89 == V_94 - 1 ) {
F_42 ( V_95 ,
V_93 ,
V_94 ,
V_28 , V_30 ) ;
V_89 = 0 ;
} else
V_89 ++ ;
}
if ( V_89 )
F_42 ( V_95 , V_93 ,
V_89 , V_28 , V_30 ) ;
}
static void F_50 ( unsigned long V_75 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_33 , V_76 ;
V_76 = F_39 ( V_75 , V_30 ) ;
V_24 = F_40 ( V_75 , V_76 , V_30 ) ;
V_33 = F_35 ( V_24 , V_28 , V_30 ) ;
F_23 ( V_33 == - 1 ) ;
F_41 ( V_33 , V_24 , V_28 , 0 , V_30 , 0 ) ;
}
static void F_51 ( unsigned long V_100 , int V_66 )
{
unsigned long V_24 ;
unsigned long V_48 , V_79 , V_64 ;
unsigned long V_32 = 0 ;
struct V_101 * V_102 = & F_52 ( V_101 ) ;
int V_80 = ! F_43 ( V_81 ) ;
unsigned long V_78 [ 9 ] ;
unsigned long V_71 , V_89 , V_73 , V_96 , V_33 ;
T_1 V_103 ;
int V_28 , V_30 ;
if ( V_80 )
F_44 ( & V_82 , V_32 ) ;
V_28 = V_102 -> V_28 ;
V_30 = V_102 -> V_30 ;
V_79 = 0 ;
for ( V_48 = 0 ; V_48 < V_100 ; V_48 ++ ) {
V_24 = V_102 -> V_24 [ V_48 ] ;
V_103 = V_102 -> V_103 [ V_48 ] ;
F_53 (pte, psize, vpn, index, shift) {
V_71 = F_36 ( V_24 , V_73 , V_30 ) ;
V_96 = F_54 ( V_103 , V_89 ) ;
if ( V_96 & V_98 )
V_71 = ~ V_71 ;
V_33 = ( V_71 & V_74 ) * V_51 ;
V_33 += V_96 & V_99 ;
if ( ! F_10 ( V_83 ) ) {
F_41 ( V_33 , V_24 , V_28 ,
0 , V_30 , V_66 ) ;
} else {
V_78 [ V_79 ] = V_84 | V_85 | V_33 ;
V_78 [ V_79 + 1 ] = F_31 ( V_24 , V_28 ,
V_30 ) ;
V_79 += 2 ;
if ( V_79 == 8 ) {
V_64 = F_45 ( V_86 , V_78 ,
V_78 [ 0 ] , V_78 [ 1 ] , V_78 [ 2 ] ,
V_78 [ 3 ] , V_78 [ 4 ] , V_78 [ 5 ] ,
V_78 [ 6 ] , V_78 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
V_79 = 0 ;
}
}
} F_55 () ;
}
if ( V_79 ) {
V_78 [ V_79 ] = V_87 ;
V_64 = F_45 ( V_86 , V_78 , V_78 [ 0 ] , V_78 [ 1 ] ,
V_78 [ 2 ] , V_78 [ 3 ] , V_78 [ 4 ] , V_78 [ 5 ] ,
V_78 [ 6 ] , V_78 [ 7 ] ) ;
F_23 ( V_64 != V_45 ) ;
}
if ( V_80 )
F_46 ( & V_82 , V_32 ) ;
}
static int T_2 F_56 ( char * V_104 )
{
if ( strcmp ( V_104 , L_18 ) == 0 &&
F_10 ( V_83 ) ) {
F_57 ( V_105 L_19 ) ;
V_106 &= ~ V_83 ;
}
return 1 ;
}
void T_2 F_58 ( void )
{
V_107 . V_108 = F_41 ;
V_107 . V_109 = F_30 ;
V_107 . V_110 = F_38 ;
V_107 . V_111 = F_14 ;
V_107 . V_112 = F_20 ;
V_107 . V_113 = F_50 ;
V_107 . V_114 = F_51 ;
V_107 . V_115 = F_24 ;
V_107 . V_116 = F_47 ;
}
static int T_2 F_59 ( char * V_104 )
{
char * V_117 ;
V_117 = F_60 ( V_104 ) ;
if ( strcasecmp ( V_117 , L_20 ) == 0 || strcasecmp ( V_117 , L_18 ) == 0 ) {
F_57 ( V_105 L_21 ) ;
V_118 = 0 ;
return 1 ;
}
V_118 = 1 ;
F_57 ( V_105 L_22 ) ;
if ( strcasecmp ( V_117 , L_23 ) == 0 || strcasecmp ( V_117 , L_24 ) == 0 )
return 1 ;
return 0 ;
}
static void F_61 ( struct V_119 * V_119 , int V_120 ,
unsigned long V_121 )
{
int V_48 , V_61 ;
unsigned long V_122 , V_3 ;
V_122 = F_62 () ;
V_3 = F_7 ( ( unsigned long ) F_63 ( V_119 ) ) ;
for ( V_48 = 0 ; V_48 < ( 1 << V_120 ) ; V_48 ++ , V_3 += V_123 ) {
for ( V_61 = 0 ; V_61 < V_123 ; V_61 += V_122 )
F_64 ( V_124 , V_121 , V_3 + V_61 , 0 ) ;
}
}
void F_65 ( struct V_119 * V_119 , int V_120 )
{
if ( ! V_118 || ! F_10 ( V_125 ) )
return;
F_61 ( V_119 , V_120 , V_126 ) ;
}
void F_66 ( void )
{
F_67 ( & V_127 ) ;
}
void F_68 ( void )
{
F_69 ( & V_127 ) ;
}
void F_66 ( void )
{
V_128 ++ ;
}
void F_68 ( void )
{
V_128 -- ;
}
void F_70 ( unsigned long V_129 , unsigned long * args )
{
unsigned long V_32 ;
unsigned int * V_130 ;
if ( V_129 == V_131 )
return;
F_71 ( V_32 ) ;
V_130 = & F_52 ( V_132 ) ;
if ( * V_130 )
goto V_133;
( * V_130 ) ++ ;
F_72 () ;
F_73 ( V_129 , args ) ;
( * V_130 ) -- ;
V_133:
F_74 ( V_32 ) ;
}
void F_75 ( long V_129 , unsigned long V_134 ,
unsigned long * V_135 )
{
unsigned long V_32 ;
unsigned int * V_130 ;
if ( V_129 == V_131 )
return;
F_71 ( V_32 ) ;
V_130 = & F_52 ( V_132 ) ;
if ( * V_130 )
goto V_133;
( * V_130 ) ++ ;
F_76 ( V_129 , V_134 , V_135 ) ;
F_77 () ;
( * V_130 ) -- ;
V_133:
F_74 ( V_32 ) ;
}
int F_78 ( struct V_136 * V_137 )
{
int V_64 ;
unsigned long V_135 [ V_138 ] ;
V_64 = F_45 ( V_139 , V_135 ) ;
V_137 -> V_140 = V_135 [ 0 ] ;
V_137 -> V_141 = V_135 [ 1 ] ;
V_137 -> V_142 = ( V_135 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_137 -> V_143 = V_135 [ 2 ] & 0xffff ;
V_137 -> V_144 = ( V_135 [ 3 ] >> 7 * 8 ) & 0xff ;
V_137 -> V_145 = ( V_135 [ 3 ] >> 6 * 8 ) & 0xff ;
V_137 -> V_146 = V_135 [ 3 ] & 0xffffffffffffUL ;
V_137 -> V_147 = V_135 [ 4 ] ;
V_137 -> V_148 = V_135 [ 5 ] ;
V_137 -> V_149 = V_135 [ 6 ] ;
return V_64 ;
}
int F_79 ( struct V_150 * V_151 )
{
int V_64 ;
unsigned long V_135 [ V_138 ] = { 0 } ;
V_64 = F_45 ( V_152 , V_135 ) ;
V_151 -> V_153 = V_135 [ 0 ] ;
V_151 -> V_154 = V_135 [ 1 ] ;
V_151 -> V_155 = V_135 [ 2 ] ;
V_151 -> V_156 = V_135 [ 3 ] ;
return V_64 ;
}
