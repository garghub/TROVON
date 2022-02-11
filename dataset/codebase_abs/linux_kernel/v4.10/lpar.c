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
#ifdef F_10
if ( ! F_11 () && F_12 ( V_13 ) ) {
V_3 = F_7 ( V_14 [ V_1 ] . V_15 ) ;
V_4 = F_13 ( V_2 , V_3 ) ;
if ( V_4 )
F_9 ( L_3
L_4 ,
V_1 , V_2 , V_3 , V_4 ) ;
}
#endif
V_6 = & V_14 [ V_1 ] ;
V_8 = V_6 -> V_16 ;
if ( V_8 ) {
V_6 -> V_17 = 0 ;
V_6 -> V_18 = V_8 ;
F_6 ( V_1 ) . V_19 = 0 ;
V_8 -> V_20 = F_14 ( V_21 ) ;
V_4 = F_15 ( V_2 , F_7 ( V_8 ) ) ;
if ( V_4 )
F_9 ( L_5
L_6 , F_4 () ,
V_2 , V_4 ) ;
F_6 ( V_1 ) . V_22 = 2 ;
}
}
static long F_16 ( unsigned long V_23 ,
unsigned long V_24 , unsigned long V_25 ,
unsigned long V_26 , unsigned long V_27 ,
int V_28 , int V_29 , int V_30 )
{
unsigned long V_31 ;
unsigned long V_32 ;
unsigned long V_33 ;
unsigned long V_34 , V_35 ;
if ( ! ( V_27 & V_36 ) )
F_17 ( L_7
L_8 ,
V_23 , V_24 , V_25 , V_26 , V_27 , V_28 ) ;
V_34 = F_18 ( V_24 , V_28 , V_29 , V_30 ) | V_27 | V_37 ;
V_35 = F_19 ( V_25 , V_28 , V_29 ) | V_26 ;
if ( ! ( V_27 & V_36 ) )
F_17 ( L_9 , V_34 , V_35 ) ;
V_32 = 0 ;
if ( F_12 ( V_38 ) && ! ( V_35 & V_39 ) )
V_32 |= V_40 ;
V_31 = F_20 ( V_32 , V_23 , V_34 , V_35 , & V_33 ) ;
if ( F_21 ( V_31 == V_41 ) ) {
if ( ! ( V_27 & V_36 ) )
F_17 ( L_10 ) ;
return - 1 ;
}
if ( F_21 ( V_31 != V_42 ) ) {
if ( ! ( V_27 & V_36 ) )
F_17 ( L_11 , V_31 ) ;
return - 2 ;
}
if ( ! ( V_27 & V_36 ) )
F_17 ( L_12 , V_33 & 7 ) ;
return ( V_33 & 7 ) | ( ! ! ( V_27 & V_43 ) << 3 ) ;
}
static long F_22 ( unsigned long V_23 )
{
unsigned long V_44 ;
unsigned long V_31 ;
int V_45 ;
unsigned long V_46 , V_47 ;
V_44 = F_23 () & 0x7 ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 ++ ) {
V_31 = F_24 ( V_49 , V_23 + V_44 ,
( 0x1UL << 4 ) , & V_46 , & V_47 ) ;
if ( V_31 == V_42 )
return V_45 ;
F_25 ( V_31 != V_50 && V_31 != V_51 ) ;
V_44 ++ ;
V_44 &= 0x7 ;
}
return - 1 ;
}
static void F_26 ( void )
{
unsigned long V_52 = 1UL << V_53 ;
unsigned long V_54 = V_52 >> 4 ;
struct {
unsigned long V_55 ;
unsigned long V_56 ;
} V_57 [ 4 ] ;
long V_31 ;
unsigned long V_45 , V_58 ;
for ( V_45 = 0 ; V_45 < V_54 ; V_45 += 4 ) {
V_31 = F_27 ( 0 , V_45 , ( void * ) V_57 ) ;
if ( V_31 != V_42 )
continue;
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ ) {
if ( ( V_57 [ V_58 ] . V_55 & V_59 ) ==
V_59 )
continue;
if ( V_57 [ V_58 ] . V_55 & V_37 )
F_28 ( 0 , V_45 + V_58 , 0 ,
& ( V_57 [ V_58 ] . V_55 ) , & ( V_57 [ V_58 ] . V_56 ) ) ;
}
}
}
static int F_29 ( void )
{
int V_60 ;
do {
V_60 = F_30 ( V_61 ) ;
} while ( V_60 == V_62 );
return V_60 ;
}
static void F_31 ( void )
{
int V_60 ;
V_60 = F_29 () ;
if ( V_60 != V_42 )
F_26 () ;
#ifdef F_32
if ( F_12 ( V_63 ) && ! F_33 () )
F_34 () ;
#endif
}
static long F_35 ( unsigned long V_33 ,
unsigned long V_64 ,
unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , unsigned long V_65 )
{
unsigned long V_31 ;
unsigned long V_32 = ( V_64 & 7 ) | V_66 ;
unsigned long V_67 ;
V_67 = F_36 ( V_24 , V_28 , V_30 ) ;
F_17 ( L_13 ,
V_67 , V_33 , V_32 , V_28 ) ;
V_31 = F_37 ( V_32 , V_33 , V_67 ) ;
if ( V_31 == V_50 ) {
F_17 ( L_14 ) ;
return - 1 ;
}
F_17 ( L_15 ) ;
F_25 ( V_31 != V_42 ) ;
return 0 ;
}
static long F_38 ( unsigned long V_67 , unsigned long V_23 )
{
long V_31 ;
unsigned long V_45 , V_58 ;
struct {
unsigned long V_55 ;
unsigned long V_56 ;
} V_57 [ 4 ] ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 += 4 , V_23 += 4 ) {
V_31 = F_39 ( 0 , V_23 , ( void * ) V_57 ) ;
if ( V_31 != V_42 )
continue;
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ ) {
if ( F_40 ( V_57 [ V_58 ] . V_55 , V_67 ) &&
( V_57 [ V_58 ] . V_55 & V_37 ) )
return V_45 + V_58 ;
}
}
return - 1 ;
}
static long F_41 ( unsigned long V_24 , int V_28 , int V_30 )
{
long V_33 ;
unsigned long V_68 ;
unsigned long V_67 ;
unsigned long V_23 ;
V_68 = F_42 ( V_24 , V_69 [ V_28 ] . V_70 , V_30 ) ;
V_67 = F_36 ( V_24 , V_28 , V_30 ) ;
V_23 = ( V_68 & V_71 ) * V_48 ;
V_33 = F_38 ( V_67 , V_23 ) ;
if ( V_33 < 0 )
return - 1 ;
return V_23 + V_33 ;
}
static void F_43 ( unsigned long V_64 ,
unsigned long V_72 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_31 , V_33 , V_73 , V_32 ;
V_73 = F_44 ( V_72 , V_30 ) ;
V_24 = F_45 ( V_72 , V_73 , V_30 ) ;
V_33 = F_41 ( V_24 , V_28 , V_30 ) ;
F_25 ( V_33 == - 1 ) ;
V_32 = V_64 & 7 ;
V_31 = F_37 ( V_32 , V_33 , 0 ) ;
F_25 ( V_31 != V_42 ) ;
}
static void F_46 ( unsigned long V_33 , unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , int V_74 )
{
unsigned long V_67 ;
unsigned long V_31 ;
unsigned long V_46 , V_47 ;
F_17 ( L_16 ,
V_33 , V_24 , V_28 , V_74 ) ;
V_67 = F_36 ( V_24 , V_28 , V_30 ) ;
V_31 = F_24 ( V_66 , V_33 , V_67 , & V_46 , & V_47 ) ;
if ( V_31 == V_50 )
return;
F_25 ( V_31 != V_42 ) ;
}
static void F_47 ( unsigned long * V_33 ,
unsigned long * V_24 , int V_75 ,
int V_28 , int V_30 )
{
unsigned long V_76 [ V_77 ] ;
int V_45 = 0 , V_78 = 0 , V_60 ;
unsigned long V_32 = 0 ;
int V_79 = ! F_48 ( V_80 ) ;
if ( V_79 )
F_49 ( & V_81 , V_32 ) ;
for ( V_45 = 0 ; V_45 < V_75 ; V_45 ++ ) {
if ( ! F_12 ( V_82 ) ) {
F_46 ( V_33 [ V_45 ] , V_24 [ V_45 ] , V_28 , 0 ,
V_30 , 0 ) ;
} else {
V_76 [ V_78 ] = V_83 | V_84 | V_33 [ V_45 ] ;
V_76 [ V_78 + 1 ] = F_36 ( V_24 [ V_45 ] , V_28 , V_30 ) ;
V_78 += 2 ;
if ( V_78 == 8 ) {
V_60 = F_50 ( V_85 , V_76 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] ,
V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_25 ( V_60 != V_42 ) ;
V_78 = 0 ;
}
}
}
if ( V_78 ) {
V_76 [ V_78 ] = V_86 ;
V_60 = F_50 ( V_85 , V_76 , V_76 [ 0 ] , V_76 [ 1 ] ,
V_76 [ 2 ] , V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_25 ( V_60 != V_42 ) ;
}
if ( V_79 )
F_51 ( & V_81 , V_32 ) ;
}
static void F_52 ( unsigned long V_73 ,
unsigned long V_3 ,
unsigned char * V_87 ,
int V_28 , int V_30 , int V_74 )
{
int V_45 , V_88 = 0 ;
unsigned long V_89 = V_3 ;
unsigned int V_90 , V_91 ;
unsigned long V_92 [ V_93 ] ;
unsigned long V_94 [ V_93 ] ;
unsigned long V_70 , V_95 , V_24 = 0 , V_68 , V_33 ;
V_70 = V_69 [ V_28 ] . V_70 ;
V_90 = 1U << ( V_96 - V_70 ) ;
for ( V_45 = 0 ; V_45 < V_90 ; V_45 ++ ) {
V_91 = F_53 ( V_87 , V_45 ) ;
if ( ! V_91 )
continue;
V_95 = F_54 ( V_87 , V_45 ) ;
V_3 = V_89 + ( V_45 * ( 1ul << V_70 ) ) ;
V_24 = F_45 ( V_3 , V_73 , V_30 ) ;
V_68 = F_42 ( V_24 , V_70 , V_30 ) ;
if ( V_95 & V_97 )
V_68 = ~ V_68 ;
V_33 = ( V_68 & V_71 ) * V_48 ;
V_33 += V_95 & V_98 ;
V_94 [ V_88 ] = V_33 ;
V_92 [ V_88 ] = V_24 ;
if ( V_88 == V_93 - 1 ) {
F_47 ( V_94 ,
V_92 ,
V_93 ,
V_28 , V_30 ) ;
V_88 = 0 ;
} else
V_88 ++ ;
}
if ( V_88 )
F_47 ( V_94 , V_92 ,
V_88 , V_28 , V_30 ) ;
}
static void F_52 ( unsigned long V_73 ,
unsigned long V_3 ,
unsigned char * V_87 ,
int V_28 , int V_30 , int V_74 )
{
F_55 ( 1 , L_17 , V_99 ) ;
}
static int F_56 ( unsigned long V_72 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_33 , V_73 ;
V_73 = F_44 ( V_72 , V_30 ) ;
V_24 = F_45 ( V_72 , V_73 , V_30 ) ;
V_33 = F_41 ( V_24 , V_28 , V_30 ) ;
if ( V_33 == - 1 )
return - V_100 ;
F_46 ( V_33 , V_24 , V_28 , 0 , V_30 , 0 ) ;
return 0 ;
}
static void F_57 ( unsigned long V_101 , int V_74 )
{
unsigned long V_24 ;
unsigned long V_45 , V_78 , V_60 ;
unsigned long V_32 = 0 ;
struct V_102 * V_103 = F_58 ( & V_102 ) ;
int V_79 = ! F_48 ( V_80 ) ;
unsigned long V_76 [ V_77 ] ;
unsigned long V_68 , V_88 , V_70 , V_95 , V_33 ;
T_1 V_104 ;
int V_28 , V_30 ;
if ( V_79 )
F_49 ( & V_81 , V_32 ) ;
V_28 = V_103 -> V_28 ;
V_30 = V_103 -> V_30 ;
V_78 = 0 ;
for ( V_45 = 0 ; V_45 < V_101 ; V_45 ++ ) {
V_24 = V_103 -> V_24 [ V_45 ] ;
V_104 = V_103 -> V_104 [ V_45 ] ;
F_59 (pte, psize, vpn, index, shift) {
V_68 = F_42 ( V_24 , V_70 , V_30 ) ;
V_95 = F_60 ( V_104 , V_88 ) ;
if ( V_95 & V_97 )
V_68 = ~ V_68 ;
V_33 = ( V_68 & V_71 ) * V_48 ;
V_33 += V_95 & V_98 ;
if ( ! F_12 ( V_82 ) ) {
F_46 ( V_33 , V_24 , V_28 ,
0 , V_30 , V_74 ) ;
} else {
V_76 [ V_78 ] = V_83 | V_84 | V_33 ;
V_76 [ V_78 + 1 ] = F_36 ( V_24 , V_28 ,
V_30 ) ;
V_78 += 2 ;
if ( V_78 == 8 ) {
V_60 = F_50 ( V_85 , V_76 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] ,
V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_25 ( V_60 != V_42 ) ;
V_78 = 0 ;
}
}
} F_61 () ;
}
if ( V_78 ) {
V_76 [ V_78 ] = V_86 ;
V_60 = F_50 ( V_85 , V_76 , V_76 [ 0 ] , V_76 [ 1 ] ,
V_76 [ 2 ] , V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_25 ( V_60 != V_42 ) ;
}
if ( V_79 )
F_51 ( & V_81 , V_32 ) ;
}
static int T_2 F_62 ( char * V_105 )
{
if ( strcmp ( V_105 , L_18 ) == 0 &&
F_12 ( V_82 ) ) {
F_63 ( V_106 L_19 ) ;
V_107 &= ~ V_82 ;
}
return 1 ;
}
void T_2 F_64 ( void )
{
V_108 . V_109 = F_46 ;
V_108 . V_110 = F_35 ;
V_108 . V_111 = F_43 ;
V_108 . V_112 = F_16 ;
V_108 . V_113 = F_22 ;
V_108 . V_114 = F_56 ;
V_108 . V_115 = F_57 ;
V_108 . V_116 = F_31 ;
V_108 . V_117 = F_52 ;
}
static int T_2 F_65 ( char * V_105 )
{
char * V_118 ;
V_118 = F_66 ( V_105 ) ;
if ( strcasecmp ( V_118 , L_20 ) == 0 || strcasecmp ( V_118 , L_18 ) == 0 ) {
F_63 ( V_106 L_21 ) ;
V_119 = 0 ;
return 1 ;
}
V_119 = 1 ;
F_63 ( V_106 L_22 ) ;
if ( strcasecmp ( V_118 , L_23 ) == 0 || strcasecmp ( V_118 , L_24 ) == 0 )
return 1 ;
return 0 ;
}
static void F_67 ( struct V_120 * V_120 , int V_121 ,
unsigned long V_122 )
{
int V_45 , V_58 ;
unsigned long V_123 , V_3 ;
V_123 = F_68 () ;
V_3 = F_7 ( ( unsigned long ) F_69 ( V_120 ) ) ;
for ( V_45 = 0 ; V_45 < ( 1 << V_121 ) ; V_45 ++ , V_3 += V_124 ) {
for ( V_58 = 0 ; V_58 < V_124 ; V_58 += V_123 )
F_30 ( V_125 , V_122 , V_3 + V_58 , 0 ) ;
}
}
void F_70 ( struct V_120 * V_120 , int V_121 )
{
if ( F_11 () )
return;
if ( ! V_119 || ! F_12 ( V_126 ) )
return;
F_67 ( V_120 , V_121 , V_127 ) ;
}
int F_71 ( void )
{
F_72 ( & V_128 ) ;
return 0 ;
}
void F_73 ( void )
{
F_74 ( & V_128 ) ;
}
int F_71 ( void )
{
V_129 ++ ;
return 0 ;
}
void F_73 ( void )
{
V_129 -- ;
}
void F_75 ( unsigned long V_130 , unsigned long * args )
{
unsigned long V_32 ;
unsigned int * V_131 ;
if ( V_130 == V_132 )
return;
F_76 ( V_32 ) ;
V_131 = F_58 ( & V_133 ) ;
if ( * V_131 )
goto V_134;
( * V_131 ) ++ ;
F_77 () ;
F_78 ( V_130 , args ) ;
( * V_131 ) -- ;
V_134:
F_79 ( V_32 ) ;
}
void F_80 ( long V_130 , unsigned long V_135 ,
unsigned long * V_136 )
{
unsigned long V_32 ;
unsigned int * V_131 ;
if ( V_130 == V_132 )
return;
F_76 ( V_32 ) ;
V_131 = F_58 ( & V_133 ) ;
if ( * V_131 )
goto V_134;
( * V_131 ) ++ ;
F_81 ( V_130 , V_135 , V_136 ) ;
F_82 () ;
( * V_131 ) -- ;
V_134:
F_79 ( V_32 ) ;
}
int F_83 ( struct V_137 * V_138 )
{
int V_60 ;
unsigned long V_136 [ V_77 ] ;
V_60 = F_50 ( V_139 , V_136 ) ;
V_138 -> V_140 = V_136 [ 0 ] ;
V_138 -> V_141 = V_136 [ 1 ] ;
V_138 -> V_142 = ( V_136 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_138 -> V_143 = V_136 [ 2 ] & 0xffff ;
V_138 -> V_144 = ( V_136 [ 3 ] >> 7 * 8 ) & 0xff ;
V_138 -> V_145 = ( V_136 [ 3 ] >> 6 * 8 ) & 0xff ;
V_138 -> V_146 = V_136 [ 3 ] & 0xffffffffffffUL ;
V_138 -> V_147 = V_136 [ 4 ] ;
V_138 -> V_148 = V_136 [ 5 ] ;
V_138 -> V_149 = V_136 [ 6 ] ;
return V_60 ;
}
int F_84 ( struct V_150 * V_151 )
{
int V_60 ;
unsigned long V_136 [ V_77 ] = { 0 } ;
V_60 = F_50 ( V_152 , V_136 ) ;
V_151 -> V_153 = V_136 [ 0 ] ;
V_151 -> V_154 = V_136 [ 1 ] ;
V_151 -> V_155 = V_136 [ 2 ] ;
V_151 -> V_156 = V_136 [ 3 ] ;
return V_60 ;
}
