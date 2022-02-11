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
V_35 = F_19 ( V_25 , V_28 , V_29 , V_30 ) | V_26 ;
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
#ifdef F_29
if ( F_12 ( V_60 ) && ! F_30 () )
F_31 () ;
#endif
}
static long F_32 ( unsigned long V_33 ,
unsigned long V_61 ,
unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , unsigned long V_62 )
{
unsigned long V_31 ;
unsigned long V_32 = ( V_61 & 7 ) | V_63 ;
unsigned long V_64 ;
V_64 = F_33 ( V_24 , V_28 , V_30 ) ;
F_17 ( L_13 ,
V_64 , V_33 , V_32 , V_28 ) ;
V_31 = F_34 ( V_32 , V_33 , V_64 ) ;
if ( V_31 == V_50 ) {
F_17 ( L_14 ) ;
return - 1 ;
}
F_17 ( L_15 ) ;
F_25 ( V_31 != V_42 ) ;
return 0 ;
}
static long F_35 ( unsigned long V_64 , unsigned long V_23 )
{
long V_31 ;
unsigned long V_45 , V_58 ;
struct {
unsigned long V_55 ;
unsigned long V_56 ;
} V_57 [ 4 ] ;
for ( V_45 = 0 ; V_45 < V_48 ; V_45 += 4 , V_23 += 4 ) {
V_31 = F_36 ( 0 , V_23 , ( void * ) V_57 ) ;
if ( V_31 != V_42 )
continue;
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ ) {
if ( F_37 ( V_57 [ V_58 ] . V_55 , V_64 ) &&
( V_57 [ V_58 ] . V_55 & V_37 ) )
return V_45 + V_58 ;
}
}
return - 1 ;
}
static long F_38 ( unsigned long V_24 , int V_28 , int V_30 )
{
long V_33 ;
unsigned long V_65 ;
unsigned long V_64 ;
unsigned long V_23 ;
V_65 = F_39 ( V_24 , V_66 [ V_28 ] . V_67 , V_30 ) ;
V_64 = F_33 ( V_24 , V_28 , V_30 ) ;
V_23 = ( V_65 & V_68 ) * V_48 ;
V_33 = F_35 ( V_64 , V_23 ) ;
if ( V_33 < 0 )
return - 1 ;
return V_23 + V_33 ;
}
static void F_40 ( unsigned long V_61 ,
unsigned long V_69 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_31 , V_33 , V_70 , V_32 ;
V_70 = F_41 ( V_69 , V_30 ) ;
V_24 = F_42 ( V_69 , V_70 , V_30 ) ;
V_33 = F_38 ( V_24 , V_28 , V_30 ) ;
F_25 ( V_33 == - 1 ) ;
V_32 = V_61 & 7 ;
V_31 = F_34 ( V_32 , V_33 , 0 ) ;
F_25 ( V_31 != V_42 ) ;
}
static void F_43 ( unsigned long V_33 , unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , int V_71 )
{
unsigned long V_64 ;
unsigned long V_31 ;
unsigned long V_46 , V_47 ;
F_17 ( L_16 ,
V_33 , V_24 , V_28 , V_71 ) ;
V_64 = F_33 ( V_24 , V_28 , V_30 ) ;
V_31 = F_24 ( V_63 , V_33 , V_64 , & V_46 , & V_47 ) ;
if ( V_31 == V_50 )
return;
F_25 ( V_31 != V_42 ) ;
}
static void F_44 ( unsigned long * V_33 ,
unsigned long * V_24 , int V_72 ,
int V_28 , int V_30 )
{
unsigned long V_73 [ V_74 ] ;
int V_45 = 0 , V_75 = 0 , V_76 ;
unsigned long V_32 = 0 ;
int V_77 = ! F_45 ( V_78 ) ;
if ( V_77 )
F_46 ( & V_79 , V_32 ) ;
for ( V_45 = 0 ; V_45 < V_72 ; V_45 ++ ) {
if ( ! F_12 ( V_80 ) ) {
F_43 ( V_33 [ V_45 ] , V_24 [ V_45 ] , V_28 , 0 ,
V_30 , 0 ) ;
} else {
V_73 [ V_75 ] = V_81 | V_82 | V_33 [ V_45 ] ;
V_73 [ V_75 + 1 ] = F_33 ( V_24 [ V_45 ] , V_28 , V_30 ) ;
V_75 += 2 ;
if ( V_75 == 8 ) {
V_76 = F_47 ( V_83 , V_73 ,
V_73 [ 0 ] , V_73 [ 1 ] , V_73 [ 2 ] ,
V_73 [ 3 ] , V_73 [ 4 ] , V_73 [ 5 ] ,
V_73 [ 6 ] , V_73 [ 7 ] ) ;
F_25 ( V_76 != V_42 ) ;
V_75 = 0 ;
}
}
}
if ( V_75 ) {
V_73 [ V_75 ] = V_84 ;
V_76 = F_47 ( V_83 , V_73 , V_73 [ 0 ] , V_73 [ 1 ] ,
V_73 [ 2 ] , V_73 [ 3 ] , V_73 [ 4 ] , V_73 [ 5 ] ,
V_73 [ 6 ] , V_73 [ 7 ] ) ;
F_25 ( V_76 != V_42 ) ;
}
if ( V_77 )
F_48 ( & V_79 , V_32 ) ;
}
static void F_49 ( unsigned long V_70 ,
unsigned long V_3 ,
unsigned char * V_85 ,
int V_28 , int V_30 , int V_71 )
{
int V_45 , V_86 = 0 ;
unsigned long V_87 = V_3 ;
unsigned int V_88 , V_89 ;
unsigned long V_90 [ V_91 ] ;
unsigned long V_92 [ V_91 ] ;
unsigned long V_67 , V_93 , V_24 = 0 , V_65 , V_33 ;
V_67 = V_66 [ V_28 ] . V_67 ;
V_88 = 1U << ( V_94 - V_67 ) ;
for ( V_45 = 0 ; V_45 < V_88 ; V_45 ++ ) {
V_89 = F_50 ( V_85 , V_45 ) ;
if ( ! V_89 )
continue;
V_93 = F_51 ( V_85 , V_45 ) ;
V_3 = V_87 + ( V_45 * ( 1ul << V_67 ) ) ;
V_24 = F_42 ( V_3 , V_70 , V_30 ) ;
V_65 = F_39 ( V_24 , V_67 , V_30 ) ;
if ( V_93 & V_95 )
V_65 = ~ V_65 ;
V_33 = ( V_65 & V_68 ) * V_48 ;
V_33 += V_93 & V_96 ;
V_92 [ V_86 ] = V_33 ;
V_90 [ V_86 ] = V_24 ;
if ( V_86 == V_91 - 1 ) {
F_44 ( V_92 ,
V_90 ,
V_91 ,
V_28 , V_30 ) ;
V_86 = 0 ;
} else
V_86 ++ ;
}
if ( V_86 )
F_44 ( V_92 , V_90 ,
V_86 , V_28 , V_30 ) ;
}
static void F_49 ( unsigned long V_70 ,
unsigned long V_3 ,
unsigned char * V_85 ,
int V_28 , int V_30 , int V_71 )
{
F_52 ( 1 , L_17 , V_97 ) ;
}
static int F_53 ( unsigned long V_69 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_33 , V_70 ;
V_70 = F_41 ( V_69 , V_30 ) ;
V_24 = F_42 ( V_69 , V_70 , V_30 ) ;
V_33 = F_38 ( V_24 , V_28 , V_30 ) ;
if ( V_33 == - 1 )
return - V_98 ;
F_43 ( V_33 , V_24 , V_28 , 0 , V_30 , 0 ) ;
return 0 ;
}
static void F_54 ( unsigned long V_99 , int V_71 )
{
unsigned long V_24 ;
unsigned long V_45 , V_75 , V_76 ;
unsigned long V_32 = 0 ;
struct V_100 * V_101 = F_55 ( & V_100 ) ;
int V_77 = ! F_45 ( V_78 ) ;
unsigned long V_73 [ V_74 ] ;
unsigned long V_65 , V_86 , V_67 , V_93 , V_33 ;
T_1 V_102 ;
int V_28 , V_30 ;
if ( V_77 )
F_46 ( & V_79 , V_32 ) ;
V_28 = V_101 -> V_28 ;
V_30 = V_101 -> V_30 ;
V_75 = 0 ;
for ( V_45 = 0 ; V_45 < V_99 ; V_45 ++ ) {
V_24 = V_101 -> V_24 [ V_45 ] ;
V_102 = V_101 -> V_102 [ V_45 ] ;
F_56 (pte, psize, vpn, index, shift) {
V_65 = F_39 ( V_24 , V_67 , V_30 ) ;
V_93 = F_57 ( V_102 , V_86 ) ;
if ( V_93 & V_95 )
V_65 = ~ V_65 ;
V_33 = ( V_65 & V_68 ) * V_48 ;
V_33 += V_93 & V_96 ;
if ( ! F_12 ( V_80 ) ) {
F_43 ( V_33 , V_24 , V_28 ,
0 , V_30 , V_71 ) ;
} else {
V_73 [ V_75 ] = V_81 | V_82 | V_33 ;
V_73 [ V_75 + 1 ] = F_33 ( V_24 , V_28 ,
V_30 ) ;
V_75 += 2 ;
if ( V_75 == 8 ) {
V_76 = F_47 ( V_83 , V_73 ,
V_73 [ 0 ] , V_73 [ 1 ] , V_73 [ 2 ] ,
V_73 [ 3 ] , V_73 [ 4 ] , V_73 [ 5 ] ,
V_73 [ 6 ] , V_73 [ 7 ] ) ;
F_25 ( V_76 != V_42 ) ;
V_75 = 0 ;
}
}
} F_58 () ;
}
if ( V_75 ) {
V_73 [ V_75 ] = V_84 ;
V_76 = F_47 ( V_83 , V_73 , V_73 [ 0 ] , V_73 [ 1 ] ,
V_73 [ 2 ] , V_73 [ 3 ] , V_73 [ 4 ] , V_73 [ 5 ] ,
V_73 [ 6 ] , V_73 [ 7 ] ) ;
F_25 ( V_76 != V_42 ) ;
}
if ( V_77 )
F_48 ( & V_79 , V_32 ) ;
}
static int T_2 F_59 ( char * V_103 )
{
if ( strcmp ( V_103 , L_18 ) == 0 &&
F_12 ( V_80 ) ) {
F_60 ( V_104 L_19 ) ;
V_105 &= ~ V_80 ;
}
return 1 ;
}
void T_2 F_61 ( void )
{
V_106 . V_107 = F_43 ;
V_106 . V_108 = F_32 ;
V_106 . V_109 = F_40 ;
V_106 . V_110 = F_16 ;
V_106 . V_111 = F_22 ;
V_106 . V_112 = F_53 ;
V_106 . V_113 = F_54 ;
V_106 . V_114 = F_26 ;
V_106 . V_115 = F_49 ;
}
static int T_2 F_62 ( char * V_103 )
{
char * V_116 ;
V_116 = F_63 ( V_103 ) ;
if ( strcasecmp ( V_116 , L_20 ) == 0 || strcasecmp ( V_116 , L_18 ) == 0 ) {
F_60 ( V_104 L_21 ) ;
V_117 = 0 ;
return 1 ;
}
V_117 = 1 ;
F_60 ( V_104 L_22 ) ;
if ( strcasecmp ( V_116 , L_23 ) == 0 || strcasecmp ( V_116 , L_24 ) == 0 )
return 1 ;
return 0 ;
}
static void F_64 ( struct V_118 * V_118 , int V_119 ,
unsigned long V_120 )
{
int V_45 , V_58 ;
unsigned long V_121 , V_3 ;
V_121 = F_65 () ;
V_3 = F_7 ( ( unsigned long ) F_66 ( V_118 ) ) ;
for ( V_45 = 0 ; V_45 < ( 1 << V_119 ) ; V_45 ++ , V_3 += V_122 ) {
for ( V_58 = 0 ; V_58 < V_122 ; V_58 += V_121 )
F_67 ( V_123 , V_120 , V_3 + V_58 , 0 ) ;
}
}
void F_68 ( struct V_118 * V_118 , int V_119 )
{
if ( F_11 () )
return;
if ( ! V_117 || ! F_12 ( V_124 ) )
return;
F_64 ( V_118 , V_119 , V_125 ) ;
}
void F_69 ( void )
{
F_70 ( & V_126 ) ;
}
void F_71 ( void )
{
F_72 ( & V_126 ) ;
}
void F_69 ( void )
{
V_127 ++ ;
}
void F_71 ( void )
{
V_127 -- ;
}
void F_73 ( unsigned long V_128 , unsigned long * args )
{
unsigned long V_32 ;
unsigned int * V_129 ;
if ( V_128 == V_130 )
return;
F_74 ( V_32 ) ;
V_129 = F_55 ( & V_131 ) ;
if ( * V_129 )
goto V_132;
( * V_129 ) ++ ;
F_75 () ;
F_76 ( V_128 , args ) ;
( * V_129 ) -- ;
V_132:
F_77 ( V_32 ) ;
}
void F_78 ( long V_128 , unsigned long V_133 ,
unsigned long * V_134 )
{
unsigned long V_32 ;
unsigned int * V_129 ;
if ( V_128 == V_130 )
return;
F_74 ( V_32 ) ;
V_129 = F_55 ( & V_131 ) ;
if ( * V_129 )
goto V_132;
( * V_129 ) ++ ;
F_79 ( V_128 , V_133 , V_134 ) ;
F_80 () ;
( * V_129 ) -- ;
V_132:
F_77 ( V_32 ) ;
}
int F_81 ( struct V_135 * V_136 )
{
int V_76 ;
unsigned long V_134 [ V_74 ] ;
V_76 = F_47 ( V_137 , V_134 ) ;
V_136 -> V_138 = V_134 [ 0 ] ;
V_136 -> V_139 = V_134 [ 1 ] ;
V_136 -> V_140 = ( V_134 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_136 -> V_141 = V_134 [ 2 ] & 0xffff ;
V_136 -> V_142 = ( V_134 [ 3 ] >> 7 * 8 ) & 0xff ;
V_136 -> V_143 = ( V_134 [ 3 ] >> 6 * 8 ) & 0xff ;
V_136 -> V_144 = V_134 [ 3 ] & 0xffffffffffffUL ;
V_136 -> V_145 = V_134 [ 4 ] ;
V_136 -> V_146 = V_134 [ 5 ] ;
V_136 -> V_147 = V_134 [ 6 ] ;
return V_76 ;
}
int F_82 ( struct V_148 * V_149 )
{
int V_76 ;
unsigned long V_134 [ V_74 ] = { 0 } ;
V_76 = F_47 ( V_150 , V_134 ) ;
V_149 -> V_151 = V_134 [ 0 ] ;
V_149 -> V_152 = V_134 [ 1 ] ;
V_149 -> V_153 = V_134 [ 2 ] ;
V_149 -> V_154 = V_134 [ 3 ] ;
return V_76 ;
}
