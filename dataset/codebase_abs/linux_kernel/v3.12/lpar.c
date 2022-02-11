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
V_3 = F_7 ( & V_13 [ V_1 ] ) ;
if ( F_10 ( V_14 ) ) {
V_4 = F_11 ( V_2 , V_3 ) ;
if ( V_4 )
F_9 ( L_3
L_4 ,
V_1 , V_2 , V_3 , V_4 ) ;
}
V_6 = & V_15 [ V_1 ] ;
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
}
static long F_27 ( unsigned long V_33 ,
unsigned long V_63 ,
unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , int V_64 )
{
unsigned long V_31 ;
unsigned long V_32 = ( V_63 & 7 ) | V_65 ;
unsigned long V_66 ;
V_66 = F_28 ( V_24 , V_28 , V_30 ) ;
F_15 ( L_13 ,
V_66 , V_33 , V_32 , V_28 ) ;
V_31 = F_29 ( V_32 , V_33 , V_66 ) ;
if ( V_31 == V_53 ) {
F_15 ( L_14 ) ;
return - 1 ;
}
F_15 ( L_15 ) ;
F_23 ( V_31 != V_45 ) ;
return 0 ;
}
static unsigned long F_30 ( unsigned long V_33 )
{
unsigned long V_67 ;
unsigned long V_31 ;
unsigned long V_68 ;
unsigned long V_32 ;
V_32 = 0 ;
V_31 = F_31 ( V_32 , V_33 , & V_67 , & V_68 ) ;
F_23 ( V_31 != V_45 ) ;
return V_67 ;
}
static long F_32 ( unsigned long V_24 , int V_28 , int V_30 )
{
unsigned long V_69 ;
unsigned long V_48 ;
long V_33 ;
unsigned long V_66 , V_34 ;
V_69 = F_33 ( V_24 , V_70 [ V_28 ] . V_71 , V_30 ) ;
V_66 = F_28 ( V_24 , V_28 , V_30 ) ;
V_33 = ( V_69 & V_72 ) * V_51 ;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
V_34 = F_30 ( V_33 ) ;
if ( F_34 ( V_34 , V_66 ) && ( V_34 & V_37 ) )
return V_33 ;
++ V_33 ;
}
return - 1 ;
}
static void F_35 ( unsigned long V_63 ,
unsigned long V_73 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_31 , V_33 , V_74 , V_32 ;
V_74 = F_36 ( V_73 , V_30 ) ;
V_24 = F_37 ( V_73 , V_74 , V_30 ) ;
V_33 = F_32 ( V_24 , V_28 , V_30 ) ;
F_23 ( V_33 == - 1 ) ;
V_32 = V_63 & 7 ;
V_31 = F_29 ( V_32 , V_33 , 0 ) ;
F_23 ( V_31 != V_45 ) ;
}
static void F_38 ( unsigned long V_33 , unsigned long V_24 ,
int V_28 , int V_29 ,
int V_30 , int V_64 )
{
unsigned long V_66 ;
unsigned long V_31 ;
unsigned long V_49 , V_50 ;
F_15 ( L_16 ,
V_33 , V_24 , V_28 , V_64 ) ;
V_66 = F_28 ( V_24 , V_28 , V_30 ) ;
V_31 = F_22 ( V_65 , V_33 , V_66 , & V_49 , & V_50 ) ;
if ( V_31 == V_53 )
return;
F_23 ( V_31 != V_45 ) ;
}
static void F_39 ( unsigned long * V_33 ,
unsigned long * V_24 , int V_75 ,
int V_28 , int V_30 )
{
unsigned long V_76 [ 8 ] ;
int V_48 = 0 , V_77 = 0 , V_78 ;
unsigned long V_32 = 0 ;
int V_79 = ! F_40 ( V_80 ) ;
if ( V_79 )
F_41 ( & V_81 , V_32 ) ;
for ( V_48 = 0 ; V_48 < V_75 ; V_48 ++ ) {
if ( ! F_10 ( V_82 ) ) {
F_38 ( V_33 [ V_48 ] , V_24 [ V_48 ] , V_28 , 0 ,
V_30 , 0 ) ;
} else {
V_76 [ V_77 ] = V_83 | V_84 | V_33 [ V_48 ] ;
V_76 [ V_77 + 1 ] = F_28 ( V_24 [ V_48 ] , V_28 , V_30 ) ;
V_77 += 2 ;
if ( V_77 == 8 ) {
V_78 = F_42 ( V_85 , V_76 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] ,
V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_23 ( V_78 != V_45 ) ;
V_77 = 0 ;
}
}
}
if ( V_77 ) {
V_76 [ V_77 ] = V_86 ;
V_78 = F_42 ( V_85 , V_76 , V_76 [ 0 ] , V_76 [ 1 ] ,
V_76 [ 2 ] , V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_23 ( V_78 != V_45 ) ;
}
if ( V_79 )
F_43 ( & V_81 , V_32 ) ;
}
static void F_44 ( struct V_87 * V_88 ,
unsigned char * V_89 ,
unsigned long V_3 , int V_28 )
{
int V_30 = 0 , V_48 , V_90 = 0 ;
unsigned long V_91 = V_3 ;
unsigned int V_92 , V_93 ;
unsigned long V_94 [ V_95 ] ;
unsigned long V_96 [ V_95 ] ;
unsigned long V_71 , V_97 , V_24 = 0 , V_74 , V_69 , V_33 ;
V_71 = V_70 [ V_28 ] . V_71 ;
V_92 = 1U << ( V_98 - V_71 ) ;
for ( V_48 = 0 ; V_48 < V_92 ; V_48 ++ ) {
V_93 = F_45 ( V_89 , V_48 ) ;
if ( ! V_93 )
continue;
V_97 = F_46 ( V_89 , V_48 ) ;
V_3 = V_91 + ( V_48 * ( 1ul << V_71 ) ) ;
if ( ! F_47 ( V_3 ) ) {
V_30 = F_48 ( V_3 ) ;
V_74 = F_49 ( V_88 -> V_99 . V_100 , V_3 , V_30 ) ;
F_3 ( V_74 == 0 ) ;
} else {
V_74 = F_36 ( V_3 , V_101 ) ;
V_30 = V_101 ;
}
V_24 = F_37 ( V_3 , V_74 , V_30 ) ;
V_69 = F_33 ( V_24 , V_71 , V_30 ) ;
if ( V_97 & V_102 )
V_69 = ~ V_69 ;
V_33 = ( V_69 & V_72 ) * V_51 ;
V_33 += V_97 & V_103 ;
V_96 [ V_90 ] = V_33 ;
V_94 [ V_90 ] = V_24 ;
if ( V_90 == V_95 - 1 ) {
F_39 ( V_96 ,
V_94 ,
V_95 ,
V_28 , V_30 ) ;
V_90 = 0 ;
} else
V_90 ++ ;
}
if ( V_90 )
F_39 ( V_96 , V_94 ,
V_90 , V_28 , V_30 ) ;
}
static void F_50 ( unsigned long V_73 ,
int V_28 , int V_30 )
{
unsigned long V_24 ;
unsigned long V_33 , V_74 ;
V_74 = F_36 ( V_73 , V_30 ) ;
V_24 = F_37 ( V_73 , V_74 , V_30 ) ;
V_33 = F_32 ( V_24 , V_28 , V_30 ) ;
F_23 ( V_33 == - 1 ) ;
F_38 ( V_33 , V_24 , V_28 , 0 , V_30 , 0 ) ;
}
static void F_51 ( unsigned long V_104 , int V_64 )
{
unsigned long V_24 ;
unsigned long V_48 , V_77 , V_78 ;
unsigned long V_32 = 0 ;
struct V_105 * V_106 = & F_52 ( V_105 ) ;
int V_79 = ! F_40 ( V_80 ) ;
unsigned long V_76 [ 9 ] ;
unsigned long V_69 , V_90 , V_71 , V_97 , V_33 ;
T_1 V_107 ;
int V_28 , V_30 ;
if ( V_79 )
F_41 ( & V_81 , V_32 ) ;
V_28 = V_106 -> V_28 ;
V_30 = V_106 -> V_30 ;
V_77 = 0 ;
for ( V_48 = 0 ; V_48 < V_104 ; V_48 ++ ) {
V_24 = V_106 -> V_24 [ V_48 ] ;
V_107 = V_106 -> V_107 [ V_48 ] ;
F_53 (pte, psize, vpn, index, shift) {
V_69 = F_33 ( V_24 , V_71 , V_30 ) ;
V_97 = F_54 ( V_107 , V_90 ) ;
if ( V_97 & V_102 )
V_69 = ~ V_69 ;
V_33 = ( V_69 & V_72 ) * V_51 ;
V_33 += V_97 & V_103 ;
if ( ! F_10 ( V_82 ) ) {
F_38 ( V_33 , V_24 , V_28 ,
0 , V_30 , V_64 ) ;
} else {
V_76 [ V_77 ] = V_83 | V_84 | V_33 ;
V_76 [ V_77 + 1 ] = F_28 ( V_24 , V_28 ,
V_30 ) ;
V_77 += 2 ;
if ( V_77 == 8 ) {
V_78 = F_42 ( V_85 , V_76 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] ,
V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_23 ( V_78 != V_45 ) ;
V_77 = 0 ;
}
}
} F_55 () ;
}
if ( V_77 ) {
V_76 [ V_77 ] = V_86 ;
V_78 = F_42 ( V_85 , V_76 , V_76 [ 0 ] , V_76 [ 1 ] ,
V_76 [ 2 ] , V_76 [ 3 ] , V_76 [ 4 ] , V_76 [ 5 ] ,
V_76 [ 6 ] , V_76 [ 7 ] ) ;
F_23 ( V_78 != V_45 ) ;
}
if ( V_79 )
F_43 ( & V_81 , V_32 ) ;
}
static int T_2 F_56 ( char * V_108 )
{
if ( strcmp ( V_108 , L_17 ) == 0 &&
F_10 ( V_82 ) ) {
F_57 ( V_109 L_18 ) ;
V_110 &= ~ V_82 ;
}
return 1 ;
}
void T_2 F_58 ( void )
{
V_111 . V_112 = F_38 ;
V_111 . V_113 = F_27 ;
V_111 . V_114 = F_35 ;
V_111 . V_115 = F_14 ;
V_111 . V_116 = F_20 ;
V_111 . V_117 = F_50 ;
V_111 . V_118 = F_51 ;
V_111 . V_119 = F_24 ;
V_111 . V_120 = F_44 ;
}
static int T_2 F_59 ( char * V_108 )
{
char * V_121 ;
V_121 = F_60 ( V_108 ) ;
if ( strcasecmp ( V_121 , L_19 ) == 0 || strcasecmp ( V_121 , L_17 ) == 0 ) {
F_57 ( V_109 L_20 ) ;
V_122 = 0 ;
return 1 ;
}
V_122 = 1 ;
F_57 ( V_109 L_21 ) ;
if ( strcasecmp ( V_121 , L_22 ) == 0 || strcasecmp ( V_121 , L_23 ) == 0 )
return 1 ;
return 0 ;
}
static void F_61 ( struct V_123 * V_123 , int V_124 ,
unsigned long V_125 )
{
int V_48 , V_61 ;
unsigned long V_126 , V_3 ;
V_126 = F_62 () ;
V_3 = F_7 ( ( unsigned long ) F_63 ( V_123 ) ) ;
for ( V_48 = 0 ; V_48 < ( 1 << V_124 ) ; V_48 ++ , V_3 += V_127 ) {
for ( V_61 = 0 ; V_61 < V_127 ; V_61 += V_126 )
F_64 ( V_128 , V_125 , V_3 + V_61 , 0 ) ;
}
}
void F_65 ( struct V_123 * V_123 , int V_124 )
{
if ( ! V_122 || ! F_10 ( V_129 ) )
return;
F_61 ( V_123 , V_124 , V_130 ) ;
}
void F_66 ( void )
{
V_131 ++ ;
}
void F_67 ( void )
{
V_131 -- ;
}
void F_68 ( unsigned long V_132 , unsigned long * args )
{
unsigned long V_32 ;
unsigned int * V_133 ;
if ( V_132 == V_134 )
return;
F_69 ( V_32 ) ;
V_133 = & F_52 ( V_135 ) ;
if ( * V_133 )
goto V_136;
( * V_133 ) ++ ;
F_70 () ;
F_71 ( V_132 , args ) ;
( * V_133 ) -- ;
V_136:
F_72 ( V_32 ) ;
}
void F_73 ( long V_132 , unsigned long V_137 ,
unsigned long * V_138 )
{
unsigned long V_32 ;
unsigned int * V_133 ;
if ( V_132 == V_134 )
return;
F_69 ( V_32 ) ;
V_133 = & F_52 ( V_135 ) ;
if ( * V_133 )
goto V_136;
( * V_133 ) ++ ;
F_74 ( V_132 , V_137 , V_138 ) ;
F_75 () ;
( * V_133 ) -- ;
V_136:
F_72 ( V_32 ) ;
}
int F_76 ( struct V_139 * V_140 )
{
int V_78 ;
unsigned long V_138 [ V_141 ] ;
V_78 = F_42 ( V_142 , V_138 ) ;
V_140 -> V_143 = V_138 [ 0 ] ;
V_140 -> V_144 = V_138 [ 1 ] ;
V_140 -> V_145 = ( V_138 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_140 -> V_146 = V_138 [ 2 ] & 0xffff ;
V_140 -> V_147 = ( V_138 [ 3 ] >> 7 * 8 ) & 0xff ;
V_140 -> V_148 = ( V_138 [ 3 ] >> 6 * 8 ) & 0xff ;
V_140 -> V_149 = V_138 [ 3 ] & 0xffffffffffffUL ;
V_140 -> V_150 = V_138 [ 4 ] ;
V_140 -> V_151 = V_138 [ 5 ] ;
V_140 -> V_152 = V_138 [ 6 ] ;
return V_78 ;
}
int F_77 ( struct V_153 * V_154 )
{
int V_78 ;
unsigned long V_138 [ V_141 ] = { 0 } ;
V_78 = F_42 ( V_155 , V_138 ) ;
V_154 -> V_156 = V_138 [ 0 ] ;
V_154 -> V_157 = V_138 [ 1 ] ;
V_154 -> V_158 = V_138 [ 2 ] ;
V_154 -> V_159 = V_138 [ 3 ] ;
return V_78 ;
}
