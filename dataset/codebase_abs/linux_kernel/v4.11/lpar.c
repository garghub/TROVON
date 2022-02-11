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
static int F_64 ( void * V_108 )
{
struct V_109 * V_110 = V_108 ;
V_110 -> V_111 = F_65 ( 0 , V_110 -> V_70 ) ;
if ( V_110 -> V_111 != V_42 )
return - V_112 ;
V_53 = V_110 -> V_70 ;
V_113 = 1UL << V_53 ;
V_71 = ( V_113 >> 7 ) - 1 ;
return 0 ;
}
static int F_66 ( unsigned long V_70 )
{
struct V_109 V_110 = {
. V_70 = V_70 ,
. V_111 = V_114 ,
} ;
unsigned int V_115 , V_116 = 0 ;
int V_60 ;
T_3 V_117 , V_118 , V_119 ;
F_67 () ;
if ( ! F_12 ( V_120 ) )
return - V_121 ;
F_63 ( V_106 L_20 ,
V_70 ) ;
V_117 = F_68 () ;
V_60 = F_69 ( 0 , V_70 ) ;
while ( F_70 ( V_60 ) ) {
V_115 = F_71 ( V_60 ) ;
V_116 += V_115 ;
if ( V_116 > V_122 ) {
V_60 = F_69 ( 0 , 0 ) ;
if ( V_60 != V_42 )
F_63 ( V_123
L_21 ,
V_60 ) ;
return - V_124 ;
}
F_72 ( V_115 ) ;
V_60 = F_69 ( 0 , V_70 ) ;
} ;
switch ( V_60 ) {
case V_42 :
break;
case V_125 :
return - V_126 ;
case V_51 :
return - V_127 ;
default:
F_63 ( V_123
L_22 ,
V_60 ) ;
return - V_112 ;
}
V_118 = F_68 () ;
V_60 = F_73 ( F_64 , & V_110 , NULL ) ;
V_119 = F_68 () ;
if ( V_60 != 0 ) {
switch ( V_110 . V_111 ) {
case V_41 :
F_63 ( V_123
L_23 ) ;
return - V_128 ;
default:
F_63 ( V_123
L_24 ,
V_110 . V_111 ) ;
return - V_112 ;
} ;
}
F_63 ( V_106
L_25 ,
V_70 , ( long long ) F_74 ( V_118 , V_117 ) ,
( long long ) F_74 ( V_119 , V_118 ) ) ;
return 0 ;
}
static int F_75 ( unsigned long V_129 ,
unsigned long V_130 , unsigned long V_131 )
{
long V_60 ;
unsigned long V_32 = V_132 ;
if ( F_11 () )
V_32 |= V_133 | V_134 ;
for (; ; ) {
V_60 = F_30 ( V_135 , V_32 , V_129 ,
V_130 , V_131 ) ;
if ( ! F_70 ( V_60 ) )
break;
F_76 ( F_71 ( V_60 ) ) ;
}
if ( V_60 != V_42 ) {
F_9 ( L_26 , V_60 ) ;
F_77 () ;
}
return V_60 ;
}
void T_2 F_78 ( void )
{
V_136 . V_137 = F_46 ;
V_136 . V_138 = F_35 ;
V_136 . V_139 = F_43 ;
V_136 . V_140 = F_16 ;
V_136 . V_141 = F_22 ;
V_136 . V_142 = F_56 ;
V_136 . V_143 = F_57 ;
V_136 . V_144 = F_31 ;
V_136 . V_145 = F_52 ;
if ( F_12 ( V_120 ) )
V_136 . V_146 = F_66 ;
}
void F_79 ( void )
{
F_80 ( L_27 ) ;
V_147 = F_75 ;
}
static int T_2 F_81 ( char * V_105 )
{
char * V_148 ;
V_148 = F_82 ( V_105 ) ;
if ( strcasecmp ( V_148 , L_28 ) == 0 || strcasecmp ( V_148 , L_18 ) == 0 ) {
F_63 ( V_106 L_29 ) ;
V_149 = 0 ;
return 1 ;
}
V_149 = 1 ;
F_63 ( V_106 L_30 ) ;
if ( strcasecmp ( V_148 , L_31 ) == 0 || strcasecmp ( V_148 , L_32 ) == 0 )
return 1 ;
return 0 ;
}
static void F_83 ( struct V_150 * V_150 , int V_151 ,
unsigned long V_110 )
{
int V_45 , V_58 ;
unsigned long V_152 , V_3 ;
V_152 = F_84 () ;
V_3 = F_7 ( ( unsigned long ) F_85 ( V_150 ) ) ;
for ( V_45 = 0 ; V_45 < ( 1 << V_151 ) ; V_45 ++ , V_3 += V_153 ) {
for ( V_58 = 0 ; V_58 < V_153 ; V_58 += V_152 )
F_30 ( V_154 , V_110 , V_3 + V_58 , 0 ) ;
}
}
void F_86 ( struct V_150 * V_150 , int V_151 )
{
if ( F_11 () )
return;
if ( ! V_149 || ! F_12 ( V_155 ) )
return;
F_83 ( V_150 , V_151 , V_156 ) ;
}
int F_87 ( void )
{
F_88 ( & V_157 ) ;
return 0 ;
}
void F_89 ( void )
{
F_90 ( & V_157 ) ;
}
int F_87 ( void )
{
V_158 ++ ;
return 0 ;
}
void F_89 ( void )
{
V_158 -- ;
}
void F_91 ( unsigned long V_159 , unsigned long * args )
{
unsigned long V_32 ;
unsigned int * V_160 ;
if ( V_159 == V_161 )
return;
F_92 ( V_32 ) ;
V_160 = F_58 ( & V_162 ) ;
if ( * V_160 )
goto V_163;
( * V_160 ) ++ ;
F_93 () ;
F_94 ( V_159 , args ) ;
( * V_160 ) -- ;
V_163:
F_95 ( V_32 ) ;
}
void F_96 ( long V_159 , unsigned long V_164 ,
unsigned long * V_165 )
{
unsigned long V_32 ;
unsigned int * V_160 ;
if ( V_159 == V_161 )
return;
F_92 ( V_32 ) ;
V_160 = F_58 ( & V_162 ) ;
if ( * V_160 )
goto V_163;
( * V_160 ) ++ ;
F_97 ( V_159 , V_164 , V_165 ) ;
F_98 () ;
( * V_160 ) -- ;
V_163:
F_95 ( V_32 ) ;
}
int F_99 ( struct V_166 * V_167 )
{
int V_60 ;
unsigned long V_165 [ V_77 ] ;
V_60 = F_50 ( V_168 , V_165 ) ;
V_167 -> V_169 = V_165 [ 0 ] ;
V_167 -> V_170 = V_165 [ 1 ] ;
V_167 -> V_171 = ( V_165 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_167 -> V_172 = V_165 [ 2 ] & 0xffff ;
V_167 -> V_173 = ( V_165 [ 3 ] >> 7 * 8 ) & 0xff ;
V_167 -> V_174 = ( V_165 [ 3 ] >> 6 * 8 ) & 0xff ;
V_167 -> V_175 = V_165 [ 3 ] & 0xffffffffffffUL ;
V_167 -> V_176 = V_165 [ 4 ] ;
V_167 -> V_177 = V_165 [ 5 ] ;
V_167 -> V_178 = V_165 [ 6 ] ;
return V_60 ;
}
int F_100 ( struct V_179 * V_180 )
{
int V_60 ;
unsigned long V_165 [ V_77 ] = { 0 } ;
V_60 = F_50 ( V_181 , V_165 ) ;
V_180 -> V_182 = V_165 [ 0 ] ;
V_180 -> V_183 = V_165 [ 1 ] ;
V_180 -> V_184 = V_165 [ 2 ] ;
V_180 -> V_185 = V_165 [ 3 ] ;
return V_60 ;
}
