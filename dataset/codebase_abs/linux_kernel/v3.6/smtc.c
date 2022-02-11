static int T_1 F_1 ( char * V_1 )
{
F_2 ( & V_1 , & V_2 ) ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
F_2 ( & V_1 , & V_3 ) ;
return 1 ;
}
static int T_1 F_4 ( char * V_4 )
{
V_5 = 1 ;
return 1 ;
}
static int T_1 F_5 ( char * V_1 )
{
F_2 ( & V_1 , & V_6 ) ;
switch ( V_6 ) {
case 0x1 :
case 0x3 :
case 0x7 :
case 0xf :
case 0x1f :
case 0x3f :
case 0x7f :
case 0xff :
V_7 = ( unsigned long ) V_6 ;
break;
default:
F_6 ( L_1 , V_6 ) ;
}
return 1 ;
}
static int T_1 F_7 ( char * V_4 )
{
V_8 = 1 ;
return 1 ;
}
static int T_1 F_8 ( char * V_1 )
{
F_2 ( & V_1 , & V_9 ) ;
return 1 ;
}
static void F_9 ( void )
{
int V_10 , V_11 , V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
for ( V_12 = 0 ; V_12 < V_15 ; V_12 ++ ) {
for( V_10 = 0 ; V_10 < V_16 ; V_10 ++ ) {
V_17 [ V_12 ] [ V_10 ] = 0 ;
}
}
V_13 = F_10 () ;
if ( ( V_12 = ( ( V_13 & V_18 )
>> V_19 ) + 1 ) > 1 ) {
if ( ( V_13 & V_20 ) && ! V_5 ) {
if ( ( V_11 = ( ( V_13 & V_21 )
>> V_22 ) ) == 0 ) {
F_11 ( 1 ) ;
F_12 ( V_23 ) ;
F_13 () ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
F_14 ( V_10 ) ;
F_15 (
F_16 () & ~ V_24 ) ;
F_13 () ;
if ( ( ( F_17 () & V_25 ) >> 7 ) == 1 ) {
V_14 = F_18 () ;
V_11 += ( ( V_14 >> 25 ) & 0x3f ) + 1 ;
}
F_15 (
F_16 () | V_24 ) ;
F_13 () ;
}
}
F_15 ( F_16 () | V_26 ) ;
F_19 () ;
if ( V_11 > 64 )
V_11 = 64 ;
V_27 [ 0 ] . V_28 = V_29 . V_28 = V_11 ;
V_30 |= V_31 ;
F_20 () ;
F_6 ( L_2 ,
V_11 , V_12 ) ;
} else {
F_6 ( L_3 ) ;
}
}
}
int T_1 F_21 ( int V_32 )
{
int V_10 , V_33 ;
V_33 = ( ( F_10 () & V_34 ) >> V_35 ) + 1 ;
for ( V_10 = V_32 ; V_10 < V_36 && V_10 < V_33 ; V_10 ++ ) {
F_22 ( V_10 , true ) ;
V_37 [ V_10 ] = V_10 ;
V_38 [ V_10 ] = V_10 ;
}
#ifdef F_23
F_24 ( V_39 ) ;
#endif
F_6 ( L_4 , V_10 - 1 ) ;
return V_10 ;
}
static void F_25 ( int V_40 , int V_41 , int V_42 )
{
static int V_43 [ V_44 ] ;
if ( V_41 == 1 )
{
V_43 [ 0 ] = V_45 [ 0 ] - 1 ;
V_43 [ 1 ] = V_45 [ 1 ] ;
}
F_11 ( V_41 ) ;
F_12 ( V_23 ) ;
F_13 () ;
F_26 ( ( F_27 ()
& ~ ( V_46 | V_47 | V_48 ) )
| V_49 ) ;
F_28 ( ( sizeof( struct V_50 ) * V_42 ) << 16 ) ;
F_14 ( V_40 ) ;
memcpy ( & V_27 [ V_42 ] , & V_27 [ 0 ] , sizeof( struct V_51 ) ) ;
if ( ! V_43 [ V_40 ] )
V_27 [ V_42 ] . V_52 &= ~ V_53 ;
else
V_43 [ V_40 ] -- ;
V_27 [ V_42 ] . V_54 = V_40 ;
V_27 [ V_42 ] . V_55 = V_41 ;
V_27 [ V_42 ] . V_56 = ( F_29 () >> 1 ) & 0xff ;
}
void F_30 ( int V_57 )
{
int V_10 , V_40 , V_41 , V_58 , V_59 , V_60 [ V_36 ] , V_61 , V_42 ;
unsigned long V_62 ;
unsigned long V_63 ;
int V_64 ;
struct V_65 * V_66 ;
F_31 ( V_62 ) ;
F_32 () ;
F_33 () ;
F_34 ( & V_67 . V_68 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
V_69 [ V_10 ] . V_70 = V_69 [ V_10 ] . V_71 = NULL ;
F_34 ( & V_69 [ V_10 ] . V_68 ) ;
V_69 [ V_10 ] . V_72 = 0 ;
V_69 [ V_10 ] . V_73 = 0 ;
}
V_42 = 0 ;
V_27 [ V_42 ] . V_54 = 0 ;
V_27 [ V_42 ] . V_55 = 0 ;
V_27 [ V_42 ] . V_56 = ( F_35 () >> 1 ) & 0xff ;
V_42 ++ ;
F_36 () ;
if ( V_74 > 0 )
F_6 ( L_5 , V_74 ) ;
if ( V_75 > 0 )
F_6 ( L_6 , V_75 ) ;
if ( V_5 ) {
F_6 ( L_7 ) ;
}
if ( V_6 )
F_6 ( L_8 , V_6 ) ;
#ifdef F_37
if ( V_8 )
F_6 ( L_9 ) ;
#endif
F_15 ( F_16 () | V_24 ) ;
V_63 = F_10 () ;
V_59 = ( ( V_63 & V_18 ) >> V_19 ) + 1 ;
if ( V_74 > 0 && V_59 > V_74 )
V_59 = V_74 ;
V_58 = ( ( V_63 & V_34 ) >> V_35 ) + 1 ;
if ( V_58 > V_36 )
V_58 = V_36 ;
if ( V_75 > 0 && V_58 > V_75 )
V_58 = V_75 ;
V_61 = V_58 % V_59 ;
for ( V_10 = 0 ; V_10 < V_59 ; V_10 ++ ) {
V_60 [ V_10 ] = V_58 / V_59 ;
if ( V_61 ) {
if( ( V_61 - V_10 ) > 0 ) V_60 [ V_10 ] ++ ;
}
}
if ( V_2 > V_58 ) V_2 = V_58 ;
if ( V_2 > 0 ) {
int V_76 ;
if ( V_2 < V_60 [ 0 ] ) {
V_61 = V_60 [ 0 ] - V_2 ;
V_76 = V_61 % ( V_59 - 1 ) ;
V_60 [ 0 ] = V_2 ;
for ( V_10 = 1 ; V_10 < V_59 ; V_10 ++ ) {
V_60 [ V_10 ] += V_61 / ( V_59 - 1 ) ;
if( V_76 && ( ( V_76 - ( V_10 - 1 ) > 0 ) ) )
V_60 [ V_10 ] ++ ;
}
} else if ( V_2 > V_60 [ 0 ] ) {
V_61 = V_2 - V_60 [ 0 ] ;
V_76 = V_61 % ( V_59 - 1 ) ;
V_60 [ 0 ] = V_2 ;
for ( V_10 = 1 ; V_10 < V_59 ; V_10 ++ ) {
V_60 [ V_10 ] -= V_61 / ( V_59 - 1 ) ;
if( V_76 && ( ( V_76 - ( V_10 - 1 ) > 0 ) ) )
V_60 [ V_10 ] -- ;
}
}
}
F_9 () ;
for ( V_41 = 0 , V_40 = 0 ; ( V_40 < V_59 ) && ( V_41 < V_58 ) ; V_40 ++ ) {
if ( V_41 == 0 )
{
V_45 [ 0 ] = ( ( F_38 () &
V_77 ) >> V_78 ) ;
if ( V_59 == 2 )
{
F_11 ( 1 ) ;
V_45 [ 1 ] = ( ( F_38 () &
V_77 ) >> V_78 ) ;
F_11 ( 0 ) ;
}
}
if ( V_60 [ V_40 ] == 0 )
continue;
if ( V_40 != 0 )
F_6 ( L_10 ) ;
F_6 ( L_11 , V_40 ) ;
for ( V_10 = 0 ; V_10 < V_60 [ V_40 ] ; V_10 ++ ) {
if ( V_41 != 0 ) {
F_25 ( V_40 , V_41 , V_42 ) ;
if ( V_40 != 0 ) {
F_39 (
F_40 () |
V_79 ) ;
}
V_42 ++ ;
}
F_6 ( L_12 , V_41 ) ;
V_41 ++ ;
}
if ( V_40 != 0 ) {
F_39 ( F_40 () |
V_79 ) ;
F_41 ( 0 ) ;
F_42 ( ( F_43 ()
& ~ ( V_80 | V_81 | V_82 | V_83 ) )
| ( V_84 | V_85 | V_86
| V_87 ) ) ;
F_44 ( F_45 () ) ;
F_46 ( 0 ) ;
F_47 ( F_48 () ) ;
F_49 ( F_50 () + V_88 ) ;
F_19 () ;
}
F_51 ( F_52 () | V_89 ) ;
F_39 ( F_40 () | V_90 ) ;
}
while ( V_41 < ( ( ( V_63 & V_34 ) >> V_35 ) + 1 ) ) {
F_22 ( V_41 , false ) ;
F_53 ( V_41 , false ) ;
V_41 ++ ;
}
F_15 ( F_16 () & ~ V_24 ) ;
F_6 ( L_13 ) ;
#ifdef F_23
for ( V_41 = 0 ; V_41 < V_58 ; V_41 ++ ) {
if ( V_27 [ V_41 ] . V_52 & V_53 )
F_54 ( V_41 , V_39 ) ;
}
#endif
F_55 ( V_59 ) ;
V_64 = V_36 * V_91 ;
if ( V_3 > 0 )
V_64 = V_3 ;
V_66 = F_56 ( V_64 * sizeof( struct V_65 ) , V_92 ) ;
if ( V_66 == NULL )
F_57 ( L_14 ) ;
else
F_6 ( L_15 , V_64 ) ;
for ( V_10 = 0 ; V_10 < V_64 ; V_10 ++ ) {
F_58 ( & V_67 , V_66 ) ;
V_66 ++ ;
}
F_59 ( V_93 ) ;
F_60 ( V_94 ) ;
F_61 ( V_62 ) ;
F_62 () ;
}
void T_2 F_63 ( int V_42 , struct V_95 * V_96 )
{
extern T_3 V_97 [ V_36 ] ;
unsigned long V_62 ;
int V_98 ;
F_64 () ;
if ( V_27 [ V_42 ] . V_54 != V_27 [ F_65 () ] . V_54 ) {
F_32 () ;
}
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_66 ( ( unsigned long ) & V_99 ) ;
V_97 [ V_42 ] = F_67 ( V_96 ) ;
F_68 ( F_67 ( V_96 ) ) ;
F_69 ( ( unsigned long ) F_70 ( V_96 ) ) ;
V_30 |= V_100 ;
F_12 ( 0 ) ;
if ( V_27 [ V_42 ] . V_54 != V_27 [ F_65 () ] . V_54 ) {
F_60 ( V_94 ) ;
}
F_71 () ;
}
void F_72 ( void )
{
}
void F_73 ( void )
{
int V_42 = F_65 () ;
if ( V_42 > 0 && ( V_27 [ V_42 ] . V_54 != V_27 [ V_42 - 1 ] . V_54 ) )
F_74 ( F_50 () + V_101 / V_102 ) ;
F_75 () ;
F_6 ( L_16 ,
V_27 [ F_65 () ] . V_55 , F_65 () ) ;
}
void F_76 ( void )
{
}
int F_77 ( unsigned int V_103 , struct V_104 * V_105 ,
unsigned long V_106 )
{
#ifdef F_37
unsigned int V_40 = V_29 . V_54 ;
V_107 [ V_40 ] [ V_103 - V_108 ] = 1 ;
#endif
V_109 [ V_103 ] = V_106 ;
return F_78 ( V_103 , V_105 ) ;
}
void F_79 ( unsigned int V_103 , T_4 V_110 )
{
}
void F_80 ( struct V_111 * V_112 )
{
unsigned int V_103 = V_112 -> V_103 ;
int V_113 ;
V_113 = F_81 ( V_112 -> V_110 ) ;
if ( V_113 >= V_36 )
F_82 ( V_103 ) ;
else
F_83 ( V_113 , V_114 , V_103 ) ;
}
static void F_84 ( void )
{
int V_10 ;
struct V_65 * V_115 ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
F_85 ( L_17 ,
V_10 , ( unsigned ) V_69 [ V_10 ] . V_70 , ( unsigned ) V_69 [ V_10 ] . V_71 ,
V_69 [ V_10 ] . V_72 ) ;
V_115 = V_69 [ V_10 ] . V_70 ;
while ( V_115 != V_69 [ V_10 ] . V_71 ) {
F_86 ( L_18 , V_115 -> type , V_115 -> V_116 ,
( int ) V_115 -> V_117 ) ;
#ifdef F_87
F_86 ( L_19 , V_115 -> V_118 , V_115 -> V_119 ) ;
#else
F_86 ( L_13 ) ;
#endif
V_115 = V_115 -> V_120 ;
}
}
}
static inline int F_88 ( T_5 * V_121 )
{
unsigned long V_122 ;
unsigned long V_115 ;
__asm__ __volatile__(
"1: ll %0, %2 \n"
" addu %1, %0, 1 \n"
" sc %1, %2 \n"
" beqz %1, 1b \n"
__WEAK_LLSC_MB
: "=&r" (result), "=&r" (temp), "=m" (v->counter)
: "m" (v->counter)
: "memory");
return V_122 ;
}
void F_83 ( int V_42 , int type , unsigned int V_123 )
{
int V_124 ;
struct V_65 * V_66 ;
unsigned long V_62 ;
int V_98 ;
unsigned long V_125 ;
extern void V_126 ( void ) , V_127 ( void ) ;
int V_128 = ( type == V_129 &&
V_123 == V_130 ) ;
if ( V_42 == F_65 () ) {
F_6 ( L_20 ) ;
return;
}
if ( V_128 && V_69 [ V_42 ] . V_73 != 0 )
return;
V_66 = F_89 ( & V_67 ) ;
if ( V_66 == NULL ) {
F_90 ( 1 ) ;
F_91 ( F_32 () ) ;
F_57 ( L_21 ) ;
}
V_66 -> type = type ;
V_66 -> V_117 = ( void * ) V_123 ;
V_66 -> V_116 = V_42 ;
if ( V_27 [ V_42 ] . V_54 != V_27 [ F_65 () ] . V_54 ) {
V_69 [ V_42 ] . V_73 |= V_128 ;
F_58 ( & V_69 [ V_42 ] , V_66 ) ;
F_92 () ;
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_41 ( F_93 () | V_131 ) ;
F_94 () ;
} else {
F_92 () ;
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_12 ( V_23 ) ;
F_13 () ;
V_124 = F_27 () ;
if ( ( V_124 & V_48 ) != 0 ) {
if ( V_132 == V_126 ) {
V_125 = F_95 () ;
if ( V_125 >= ( unsigned long ) V_126
&& V_125 < ( unsigned long ) V_127 ) {
F_66 ( V_127 ) ;
V_124 &= ~ V_48 ;
F_26 ( V_124 ) ;
goto V_133;
}
}
F_12 ( 0 ) ;
F_94 () ;
V_69 [ V_42 ] . V_73 |= V_128 ;
F_58 ( & V_69 [ V_42 ] , V_66 ) ;
} else {
V_133:
F_96 ( V_42 , V_66 ) ;
F_12 ( 0 ) ;
F_94 () ;
}
}
}
static void F_96 ( int V_42 , struct V_65 * V_66 )
{
struct V_134 * V_135 ;
unsigned long V_124 ;
unsigned long V_125 ;
extern T_3 V_97 [ V_36 ] ;
extern void V_136 ( void ) ;
V_124 = F_27 () ;
V_125 = F_95 () ;
if ( ( V_125 & 0x80000000 )
&& ( ( * ( unsigned int * ) V_125 & 0xfe00003f ) == 0x42000020 ) ) {
V_125 += 4 ;
}
if ( V_124 & V_137 ) {
V_135 = ( (struct V_134 * ) F_97 () ) - 1 ;
} else {
V_135 = ( (struct V_134 * ) V_97 [ V_42 ] ) - 1 ;
}
V_135 -> V_138 = ( long ) V_125 ;
V_135 -> V_139 = V_124 ;
V_135 -> V_140 [ 4 ] = ( unsigned long ) V_66 ;
V_135 -> V_140 [ 5 ] = ( unsigned long ) & V_141 ;
V_124 |= V_48 ;
V_124 &= ~ V_46 ;
F_26 ( V_124 ) ;
F_19 () ;
F_66 ( V_136 ) ;
}
static void F_98 ( void )
{
F_99 () ;
}
static void F_100 ( void )
{
F_101 () ;
}
static void T_6 F_102 ( void )
{
unsigned int V_42 = F_65 () ;
struct V_142 * V_143 ;
int V_103 = V_108 + 1 ;
F_103 () ;
F_104 ( V_103 , F_105 ( V_103 ) ) ;
V_143 = & F_106 ( V_144 , V_42 ) ;
V_143 -> V_145 ( V_143 ) ;
F_107 () ;
}
void V_141 ( struct V_65 * V_66 )
{
void * V_146 = V_66 -> V_117 ;
int V_147 = V_66 -> type ;
F_58 ( & V_67 , V_66 ) ;
switch ( V_147 ) {
case V_148 :
F_102 () ;
break;
case V_129 :
switch ( ( int ) V_146 ) {
case V_130 :
F_98 () ;
break;
case V_149 :
F_100 () ;
break;
default:
F_6 ( L_22 , V_146 ) ;
break;
}
break;
#ifdef F_108
case V_114 :
F_82 ( ( int ) V_146 ) ;
break;
#endif
default:
F_6 ( L_23 , V_147 ) ;
break;
}
}
void F_109 ( void )
{
int V_42 = F_65 () ;
while ( V_69 [ V_42 ] . V_70 != NULL ) {
struct V_50 * V_150 = & V_69 [ V_42 ] ;
struct V_65 * V_66 ;
unsigned long V_62 ;
F_31 ( V_62 ) ;
F_110 ( & V_150 -> V_68 ) ;
V_66 = F_111 ( V_150 ) ;
F_112 ( & V_150 -> V_68 ) ;
if ( V_66 != NULL ) {
if ( V_66 -> type == V_129 &&
( int ) V_66 -> V_117 == V_130 )
V_69 [ V_42 ] . V_73 = 0 ;
V_141 ( V_66 ) ;
}
F_113 ( V_62 ) ;
}
}
static T_7 F_114 ( int V_103 , void * V_151 )
{
int V_152 = V_27 [ F_65 () ] . V_54 ;
int V_153 = V_27 [ F_65 () ] . V_55 ;
int V_42 ;
struct V_65 * V_66 ;
unsigned long V_124 ;
int V_154 ;
unsigned long V_62 ;
unsigned int V_98 ;
unsigned int V_155 ;
F_31 ( V_62 ) ;
V_155 = F_32 () ;
F_115 ( 0x100 << V_156 ) ;
F_116 ( 0x100 << V_156 ) ;
F_117 () ;
F_60 ( V_155 ) ;
F_61 ( V_62 ) ;
F_118 (cpu) {
if ( V_27 [ V_42 ] . V_54 != V_152 )
continue;
V_66 = F_89 ( & V_69 [ V_42 ] ) ;
if ( V_66 != NULL ) {
if ( V_27 [ V_42 ] . V_55 != V_153 ) {
V_154 = 0 ;
F_64 () ;
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_12 ( V_23 ) ;
F_13 () ;
V_124 = F_27 () ;
if ( ( V_124 & V_48 ) == 0 ) {
F_96 ( V_42 , V_66 ) ;
V_154 = 1 ;
}
F_12 ( 0 ) ;
F_71 () ;
if ( ! V_154 ) {
F_119 ( & V_69 [ V_42 ] , V_66 ) ;
}
} else {
F_31 ( V_62 ) ;
if ( V_66 -> type == V_129 &&
( int ) V_66 -> V_117 == V_130 )
V_69 [ V_42 ] . V_73 = 0 ;
V_141 ( V_66 ) ;
F_61 ( V_62 ) ;
}
}
}
return V_157 ;
}
static void F_120 ( void )
{
F_121 ( V_158 ) ;
}
static void F_55 ( unsigned int V_59 )
{
if ( V_59 < 1 )
return;
if ( ! V_159 )
F_57 ( L_24 ) ;
F_122 ( V_156 , F_120 ) ;
F_77 ( V_158 , & V_160 , ( 0x100 << V_156 ) ) ;
F_123 ( V_158 , V_161 ) ;
}
void F_124 ( void )
{
unsigned int V_42 = F_65 () ;
while ( V_69 [ V_42 ] . V_70 != NULL ) {
struct V_50 * V_150 = & V_69 [ V_42 ] ;
struct V_65 * V_66 ;
unsigned long V_62 ;
F_31 ( V_62 ) ;
F_110 ( & V_150 -> V_68 ) ;
V_66 = F_111 ( V_150 ) ;
F_112 ( & V_150 -> V_68 ) ;
F_113 ( V_62 ) ;
if ( V_66 ) {
F_125 ( V_66 ) ;
V_162 [ V_42 ] . V_163 ++ ;
}
}
}
void F_126 ( void )
{
#ifdef F_37
int V_164 ;
int V_62 ;
int V_98 ;
int V_165 ;
int V_40 ;
int V_41 ;
int V_166 ;
char * V_167 ;
char V_168 [ 768 ] ;
if ( F_127 ( & V_169 ) == 0 ) {
if ( F_128 ( 1 , & V_169 ) == 1 ) {
int V_13 ;
V_13 = F_10 () ;
V_166 = ( ( V_13 & V_34 ) >> V_35 ) + 1 ;
if ( V_166 > V_36 )
V_166 = V_36 ;
for ( V_41 = 0 ; V_41 < V_166 ; V_41 ++ ) {
V_170 [ V_41 ] = 0 ;
V_171 [ V_41 ] = 0 ;
}
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ )
for ( V_164 = 0 ; V_164 < 8 ; V_164 ++ )
V_172 [ V_40 ] [ V_164 ] = 0 ;
F_6 ( L_25 , V_166 ) ;
F_129 ( & V_169 , 1000 ) ;
} else {
while ( F_127 ( & V_169 ) < 1000 )
;
}
}
if ( F_130 () & 0x400 ) {
F_131 ( F_130 () & ~ 0x400 ) ;
F_19 () ;
F_6 ( L_26 ) ;
}
#define F_132 2000
F_31 ( V_62 ) ;
V_98 = F_33 () ;
V_167 = & V_168 [ 0 ] ;
V_164 = F_133 () ;
V_40 = V_29 . V_54 ;
for ( V_165 = 0 ; V_165 < 8 ; V_165 ++ ) {
if ( V_107 [ V_40 ] [ V_165 ] ) {
if ( ! ( V_164 & ( 0x100 << V_165 ) ) )
V_172 [ V_40 ] [ V_165 ] ++ ;
else
V_172 [ V_40 ] [ V_165 ] = 0 ;
if ( V_172 [ V_40 ] [ V_165 ] > F_132 ) {
F_116 ( 0x100 << V_165 ) ;
F_19 () ;
V_172 [ V_40 ] [ V_165 ] = 0 ;
V_167 += sprintf ( V_167 ,
L_27 , V_165 ,
V_40 ) ;
}
}
}
F_59 ( V_98 ) ;
F_61 ( V_62 ) ;
if ( V_167 != & V_168 [ 0 ] )
F_6 ( L_28 , F_65 () , V_168 ) ;
#endif
F_124 () ;
}
void F_134 ( void )
{
int V_10 ;
F_6 ( L_29 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
F_6 ( L_30 , V_10 , V_162 [ V_10 ] . V_173 ) ;
}
F_6 ( L_31 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
F_6 ( L_30 , V_10 , V_162 [ V_10 ] . V_163 ) ;
}
F_84 () ;
F_6 ( L_32 ,
F_127 ( & V_174 ) ) ;
}
void F_135 ( struct V_175 * V_176 , unsigned long V_42 )
{
unsigned long V_62 , V_98 , V_177 , V_178 , V_179 ;
int V_180 , V_10 ;
F_31 ( V_62 ) ;
if ( V_30 & V_31 ) {
V_98 = F_32 () ;
V_180 = 0 ;
} else {
V_98 = F_33 () ;
V_180 = V_27 [ V_42 ] . V_54 ;
}
V_179 = F_136 ( V_42 ) ;
do {
if ( ! ( ( V_179 += V_181 ) & V_182 ) ) {
if ( V_183 )
F_137 () ;
F_118 (i) {
if ( ( V_10 != F_65 () ) &&
( ( V_30 & V_31 ) ||
( V_27 [ V_10 ] . V_54 == V_27 [ V_42 ] . V_54 ) ) ) {
F_11 ( V_27 [ V_10 ] . V_55 ) ;
V_178 = F_138 () & V_23 ;
if ( ! V_178 ) {
F_12 ( V_23 ) ;
F_13 () ;
}
V_177 = F_27 () ;
V_17 [ V_180 ] [ ( V_177 & V_182 ) ] |= ( V_184 ) ( 0x1 << V_10 ) ;
if ( ! V_178 )
F_12 ( 0 ) ;
}
}
if ( ! V_179 )
V_179 = V_185 ;
F_20 () ;
}
} while ( V_17 [ V_180 ] [ ( V_179 & V_182 ) ] );
F_118 (i) {
if ( ( V_30 & V_31 ) ||
( V_27 [ V_10 ] . V_54 == V_27 [ V_42 ] . V_54 ) )
F_139 ( V_10 , V_176 ) = F_136 ( V_10 ) = V_179 ;
}
if ( V_30 & V_31 )
F_60 ( V_98 ) ;
else
F_59 ( V_98 ) ;
F_61 ( V_62 ) ;
}
void F_140 ( unsigned long V_179 )
{
int V_186 ;
unsigned long V_187 ;
V_186 = F_141 () ;
while ( V_186 < V_29 . V_28 ) {
F_142 ( V_186 ) ;
F_19 () ;
F_143 () ;
F_19 () ;
V_187 = F_144 () ;
if ( ( V_187 & V_182 ) == V_179 ) {
F_145 ( V_188 + ( V_186 << ( V_189 + 1 ) ) ) ;
F_146 ( 0 ) ;
F_147 ( 0 ) ;
F_148 () ;
F_149 () ;
}
V_186 ++ ;
}
F_142 ( V_190 ) ;
F_150 () ;
}
void F_151 ( void )
{
int V_42 ;
F_118 (cpu) {
if ( V_42 != F_65 () ) {
F_11 ( V_27 [ V_42 ] . V_55 ) ;
V_191 [ V_42 ] = F_138 () ;
F_12 ( V_23 ) ;
}
}
F_13 () ;
}
void F_152 ( void )
{
int V_42 ;
F_13 () ;
F_118 (cpu) {
if ( V_42 != F_65 () ) {
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_12 ( V_191 [ V_42 ] ) ;
}
}
F_13 () ;
}
