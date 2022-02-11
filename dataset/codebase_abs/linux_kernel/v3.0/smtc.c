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
F_11 ( V_41 ) ;
F_12 ( V_23 ) ;
F_13 () ;
F_26 ( ( F_27 ()
& ~ ( V_43 | V_44 | V_45 ) )
| V_46 ) ;
F_28 ( ( sizeof( struct V_47 ) * V_42 ) << 16 ) ;
F_14 ( V_40 ) ;
memcpy ( & V_27 [ V_42 ] , & V_27 [ 0 ] , sizeof( struct V_48 ) ) ;
if ( V_27 [ 0 ] . V_49 == V_50 ||
V_27 [ 0 ] . V_49 == V_51 )
V_27 [ V_42 ] . V_52 &= ~ V_53 ;
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
if ( V_60 [ V_40 ] == 0 )
continue;
if ( V_40 != 0 )
F_6 ( L_10 ) ;
F_6 ( L_11 , V_40 ) ;
for ( V_10 = 0 ; V_10 < V_60 [ V_40 ] ; V_10 ++ ) {
if ( V_41 != 0 ) {
F_25 ( V_40 , V_41 , V_42 ) ;
V_42 ++ ;
}
F_6 ( L_12 , V_41 ) ;
V_41 ++ ;
}
if ( V_40 != 0 ) {
F_38 ( F_39 () |
V_77 ) ;
F_40 ( 0 ) ;
F_41 ( ( F_42 ()
& ~ ( V_78 | V_79 | V_80 | V_81 ) )
| ( V_82 | V_83 | V_84
| V_85 ) ) ;
F_43 ( F_44 () ) ;
F_45 ( 0 ) ;
F_46 ( F_47 () ) ;
F_48 ( F_49 () + V_86 ) ;
F_19 () ;
}
F_50 ( F_51 () | V_87 ) ;
F_38 ( F_39 () | V_88 ) ;
}
while ( V_41 < ( ( ( V_63 & V_34 ) >> V_35 ) + 1 ) ) {
F_22 ( V_41 , false ) ;
F_52 ( V_41 , false ) ;
V_41 ++ ;
}
F_15 ( F_16 () & ~ V_24 ) ;
F_6 ( L_13 ) ;
#ifdef F_23
for ( V_41 = 0 ; V_41 < V_58 ; V_41 ++ ) {
if ( V_27 [ V_41 ] . V_52 & V_53 )
F_53 ( V_41 , V_39 ) ;
}
#endif
F_54 ( V_59 ) ;
V_64 = V_36 * V_89 ;
if ( V_3 > 0 )
V_64 = V_3 ;
V_66 = F_55 ( V_64 * sizeof( struct V_65 ) , V_90 ) ;
if ( V_66 == NULL )
F_56 ( L_14 ) ;
else
F_6 ( L_15 , V_64 ) ;
for ( V_10 = 0 ; V_10 < V_64 ; V_10 ++ ) {
F_57 ( & V_67 , V_66 ) ;
V_66 ++ ;
}
F_58 ( V_91 ) ;
F_59 ( V_92 ) ;
F_60 ( V_62 ) ;
F_61 () ;
}
void T_2 F_62 ( int V_42 , struct V_93 * V_94 )
{
extern T_3 V_95 [ V_36 ] ;
unsigned long V_62 ;
int V_96 ;
F_63 () ;
if ( V_27 [ V_42 ] . V_54 != V_27 [ F_64 () ] . V_54 ) {
F_32 () ;
}
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_65 ( ( unsigned long ) & V_97 ) ;
V_95 [ V_42 ] = F_66 ( V_94 ) ;
F_67 ( F_66 ( V_94 ) ) ;
F_68 ( ( unsigned long ) F_69 ( V_94 ) ) ;
V_30 |= V_98 ;
F_12 ( 0 ) ;
if ( V_27 [ V_42 ] . V_54 != V_27 [ F_64 () ] . V_54 ) {
F_59 ( V_92 ) ;
}
F_70 () ;
}
void F_71 ( void )
{
F_72 () ;
}
void F_73 ( void )
{
int V_42 = F_64 () ;
if ( V_42 > 0 && ( V_27 [ V_42 ] . V_54 != V_27 [ V_42 - 1 ] . V_54 ) )
F_74 ( F_49 () + V_99 / V_100 ) ;
F_6 ( L_16 ,
V_27 [ F_64 () ] . V_55 , F_64 () ) ;
}
void F_75 ( void )
{
}
int F_76 ( unsigned int V_101 , struct V_102 * V_103 ,
unsigned long V_104 )
{
#ifdef F_37
unsigned int V_40 = V_29 . V_54 ;
V_105 [ V_40 ] [ V_101 - V_106 ] = 1 ;
#endif
V_107 [ V_101 ] = V_104 ;
return F_77 ( V_101 , V_103 ) ;
}
void F_78 ( unsigned int V_101 , T_4 V_108 )
{
}
void F_79 ( struct V_109 * V_110 )
{
unsigned int V_101 = V_110 -> V_101 ;
int V_111 ;
V_111 = F_80 ( V_110 -> V_108 ) ;
if ( V_111 >= V_36 )
F_81 ( V_101 ) ;
else
F_82 ( V_111 , V_112 , V_101 ) ;
}
static void F_83 ( void )
{
int V_10 ;
struct V_65 * V_113 ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
F_84 ( L_17 ,
V_10 , ( unsigned ) V_69 [ V_10 ] . V_70 , ( unsigned ) V_69 [ V_10 ] . V_71 ,
V_69 [ V_10 ] . V_72 ) ;
V_113 = V_69 [ V_10 ] . V_70 ;
while ( V_113 != V_69 [ V_10 ] . V_71 ) {
F_85 ( L_18 , V_113 -> type , V_113 -> V_114 ,
( int ) V_113 -> V_115 ) ;
#ifdef F_86
F_85 ( L_19 , V_113 -> V_116 , V_113 -> V_117 ) ;
#else
F_85 ( L_13 ) ;
#endif
V_113 = V_113 -> V_118 ;
}
}
}
static inline int F_87 ( T_5 * V_119 )
{
unsigned long V_120 ;
unsigned long V_113 ;
__asm__ __volatile__(
"1: ll %0, %2 \n"
" addu %1, %0, 1 \n"
" sc %1, %2 \n"
" beqz %1, 1b \n"
__WEAK_LLSC_MB
: "=&r" (result), "=&r" (temp), "=m" (v->counter)
: "m" (v->counter)
: "memory");
return V_120 ;
}
void F_82 ( int V_42 , int type , unsigned int V_121 )
{
int V_122 ;
struct V_65 * V_66 ;
unsigned long V_62 ;
int V_96 ;
unsigned long V_123 ;
extern void V_124 ( void ) , V_125 ( void ) ;
int V_126 = ( type == V_127 &&
V_121 == V_128 ) ;
if ( V_42 == F_64 () ) {
F_6 ( L_20 ) ;
return;
}
if ( V_126 && V_69 [ V_42 ] . V_73 != 0 )
return;
V_66 = F_88 ( & V_67 ) ;
if ( V_66 == NULL ) {
F_89 ( 1 ) ;
F_90 ( F_32 () ) ;
F_56 ( L_21 ) ;
}
V_66 -> type = type ;
V_66 -> V_115 = ( void * ) V_121 ;
V_66 -> V_114 = V_42 ;
if ( V_27 [ V_42 ] . V_54 != V_27 [ F_64 () ] . V_54 ) {
V_69 [ V_42 ] . V_73 |= V_126 ;
F_57 ( & V_69 [ V_42 ] , V_66 ) ;
F_91 () ;
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_40 ( F_92 () | V_129 ) ;
F_93 () ;
} else {
F_91 () ;
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_12 ( V_23 ) ;
F_13 () ;
V_122 = F_27 () ;
if ( ( V_122 & V_45 ) != 0 ) {
if ( V_130 == V_124 ) {
V_123 = F_94 () ;
if ( V_123 >= ( unsigned long ) V_124
&& V_123 < ( unsigned long ) V_125 ) {
F_65 ( V_125 ) ;
V_122 &= ~ V_45 ;
F_26 ( V_122 ) ;
goto V_131;
}
}
F_12 ( 0 ) ;
F_93 () ;
V_69 [ V_42 ] . V_73 |= V_126 ;
F_57 ( & V_69 [ V_42 ] , V_66 ) ;
} else {
V_131:
F_95 ( V_42 , V_66 ) ;
F_12 ( 0 ) ;
F_93 () ;
}
}
}
static void F_95 ( int V_42 , struct V_65 * V_66 )
{
struct V_132 * V_133 ;
unsigned long V_122 ;
unsigned long V_123 ;
extern T_3 V_95 [ V_36 ] ;
extern void V_134 ( void ) ;
V_122 = F_27 () ;
V_123 = F_94 () ;
if ( ( V_123 & 0x80000000 )
&& ( ( * ( unsigned int * ) V_123 & 0xfe00003f ) == 0x42000020 ) ) {
V_123 += 4 ;
}
if ( V_122 & V_135 ) {
V_133 = ( (struct V_132 * ) F_96 () ) - 1 ;
} else {
V_133 = ( (struct V_132 * ) V_95 [ V_42 ] ) - 1 ;
}
V_133 -> V_136 = ( long ) V_123 ;
V_133 -> V_137 = V_122 ;
V_133 -> V_138 [ 4 ] = ( unsigned long ) V_66 ;
V_133 -> V_138 [ 5 ] = ( unsigned long ) & V_139 ;
V_122 |= V_45 ;
V_122 &= ~ V_43 ;
F_26 ( V_122 ) ;
F_19 () ;
F_65 ( V_134 ) ;
}
static void F_97 ( void )
{
F_98 () ;
}
static void F_99 ( void )
{
F_100 () ;
}
static void T_6 F_101 ( void )
{
unsigned int V_42 = F_64 () ;
struct V_140 * V_141 ;
int V_101 = V_106 + 1 ;
F_102 () ;
F_103 ( V_101 , F_104 ( V_101 ) ) ;
V_141 = & F_105 ( V_142 , V_42 ) ;
V_141 -> V_143 ( V_141 ) ;
F_106 () ;
}
void V_139 ( struct V_65 * V_66 )
{
void * V_144 = V_66 -> V_115 ;
int V_145 = V_66 -> type ;
F_57 ( & V_67 , V_66 ) ;
switch ( V_145 ) {
case V_146 :
F_101 () ;
break;
case V_127 :
switch ( ( int ) V_144 ) {
case V_128 :
F_97 () ;
break;
case V_147 :
F_99 () ;
break;
default:
F_6 ( L_22 , V_144 ) ;
break;
}
break;
#ifdef F_107
case V_112 :
F_81 ( ( int ) V_144 ) ;
break;
#endif
default:
F_6 ( L_23 , V_145 ) ;
break;
}
}
void F_108 ( void )
{
int V_42 = F_64 () ;
while ( V_69 [ V_42 ] . V_70 != NULL ) {
struct V_47 * V_148 = & V_69 [ V_42 ] ;
struct V_65 * V_66 ;
unsigned long V_62 ;
F_31 ( V_62 ) ;
F_109 ( & V_148 -> V_68 ) ;
V_66 = F_110 ( V_148 ) ;
F_111 ( & V_148 -> V_68 ) ;
if ( V_66 != NULL ) {
if ( V_66 -> type == V_127 &&
( int ) V_66 -> V_115 == V_128 )
V_69 [ V_42 ] . V_73 = 0 ;
V_139 ( V_66 ) ;
}
F_112 ( V_62 ) ;
}
}
static T_7 F_113 ( int V_101 , void * V_149 )
{
int V_150 = V_27 [ F_64 () ] . V_54 ;
int V_151 = V_27 [ F_64 () ] . V_55 ;
int V_42 ;
struct V_65 * V_66 ;
unsigned long V_122 ;
int V_152 ;
unsigned long V_62 ;
unsigned int V_96 ;
unsigned int V_153 ;
F_31 ( V_62 ) ;
V_153 = F_32 () ;
F_114 ( 0x100 << V_154 ) ;
F_115 ( 0x100 << V_154 ) ;
F_116 () ;
F_59 ( V_153 ) ;
F_60 ( V_62 ) ;
F_117 (cpu) {
if ( V_27 [ V_42 ] . V_54 != V_150 )
continue;
V_66 = F_88 ( & V_69 [ V_42 ] ) ;
if ( V_66 != NULL ) {
if ( V_27 [ V_42 ] . V_55 != V_151 ) {
V_152 = 0 ;
F_63 () ;
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_12 ( V_23 ) ;
F_13 () ;
V_122 = F_27 () ;
if ( ( V_122 & V_45 ) == 0 ) {
F_95 ( V_42 , V_66 ) ;
V_152 = 1 ;
}
F_12 ( 0 ) ;
F_70 () ;
if ( ! V_152 ) {
F_118 ( & V_69 [ V_42 ] , V_66 ) ;
}
} else {
F_31 ( V_62 ) ;
if ( V_66 -> type == V_127 &&
( int ) V_66 -> V_115 == V_128 )
V_69 [ V_42 ] . V_73 = 0 ;
V_139 ( V_66 ) ;
F_60 ( V_62 ) ;
}
}
}
return V_155 ;
}
static void F_119 ( void )
{
F_120 ( V_156 ) ;
}
static void F_54 ( unsigned int V_59 )
{
if ( V_59 < 1 )
return;
if ( ! V_157 )
F_56 ( L_24 ) ;
F_121 ( V_154 , F_119 ) ;
F_76 ( V_156 , & V_158 , ( 0x100 << V_154 ) ) ;
F_122 ( V_156 , V_159 ) ;
}
void F_123 ( void )
{
unsigned int V_42 = F_64 () ;
while ( V_69 [ V_42 ] . V_70 != NULL ) {
struct V_47 * V_148 = & V_69 [ V_42 ] ;
struct V_65 * V_66 ;
unsigned long V_62 ;
F_31 ( V_62 ) ;
F_109 ( & V_148 -> V_68 ) ;
V_66 = F_110 ( V_148 ) ;
F_111 ( & V_148 -> V_68 ) ;
F_112 ( V_62 ) ;
if ( V_66 ) {
F_124 ( V_66 ) ;
V_160 [ V_42 ] . V_161 ++ ;
}
}
}
void F_125 ( void )
{
#ifdef F_37
int V_162 ;
int V_62 ;
int V_96 ;
int V_163 ;
int V_40 ;
int V_41 ;
int V_164 ;
char * V_165 ;
char V_166 [ 768 ] ;
if ( F_126 ( & V_167 ) == 0 ) {
if ( F_127 ( 1 , & V_167 ) == 1 ) {
int V_13 ;
V_13 = F_10 () ;
V_164 = ( ( V_13 & V_34 ) >> V_35 ) + 1 ;
if ( V_164 > V_36 )
V_164 = V_36 ;
for ( V_41 = 0 ; V_41 < V_164 ; V_41 ++ ) {
V_168 [ V_41 ] = 0 ;
V_169 [ V_41 ] = 0 ;
}
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ )
for ( V_162 = 0 ; V_162 < 8 ; V_162 ++ )
V_170 [ V_40 ] [ V_162 ] = 0 ;
F_6 ( L_25 , V_164 ) ;
F_128 ( & V_167 , 1000 ) ;
} else {
while ( F_126 ( & V_167 ) < 1000 )
;
}
}
if ( F_129 () & 0x400 ) {
F_130 ( F_129 () & ~ 0x400 ) ;
F_19 () ;
F_6 ( L_26 ) ;
}
#define F_131 2000
F_31 ( V_62 ) ;
V_96 = F_33 () ;
V_165 = & V_166 [ 0 ] ;
V_162 = F_132 () ;
V_40 = V_29 . V_54 ;
for ( V_163 = 0 ; V_163 < 8 ; V_163 ++ ) {
if ( V_105 [ V_40 ] [ V_163 ] ) {
if ( ! ( V_162 & ( 0x100 << V_163 ) ) )
V_170 [ V_40 ] [ V_163 ] ++ ;
else
V_170 [ V_40 ] [ V_163 ] = 0 ;
if ( V_170 [ V_40 ] [ V_163 ] > F_131 ) {
F_115 ( 0x100 << V_163 ) ;
F_19 () ;
V_170 [ V_40 ] [ V_163 ] = 0 ;
V_165 += sprintf ( V_165 ,
L_27 , V_163 ,
V_40 ) ;
}
}
}
F_58 ( V_96 ) ;
F_60 ( V_62 ) ;
if ( V_165 != & V_166 [ 0 ] )
F_6 ( L_28 , F_64 () , V_166 ) ;
#endif
F_123 () ;
}
void F_133 ( void )
{
int V_10 ;
F_6 ( L_29 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
F_6 ( L_30 , V_10 , V_160 [ V_10 ] . V_171 ) ;
}
F_6 ( L_31 ) ;
for ( V_10 = 0 ; V_10 < V_36 ; V_10 ++ ) {
F_6 ( L_30 , V_10 , V_160 [ V_10 ] . V_161 ) ;
}
F_83 () ;
F_6 ( L_32 ,
F_126 ( & V_172 ) ) ;
}
void F_134 ( struct V_173 * V_174 , unsigned long V_42 )
{
unsigned long V_62 , V_96 , V_175 , V_176 , V_177 ;
int V_178 , V_10 ;
F_31 ( V_62 ) ;
if ( V_30 & V_31 ) {
V_96 = F_32 () ;
V_178 = 0 ;
} else {
V_96 = F_33 () ;
V_178 = V_27 [ V_42 ] . V_54 ;
}
V_177 = F_135 ( V_42 ) ;
do {
if ( ! ( ( V_177 += V_179 ) & V_180 ) ) {
if ( V_181 )
F_136 () ;
F_117 (i) {
if ( ( V_10 != F_64 () ) &&
( ( V_30 & V_31 ) ||
( V_27 [ V_10 ] . V_54 == V_27 [ V_42 ] . V_54 ) ) ) {
F_11 ( V_27 [ V_10 ] . V_55 ) ;
V_176 = F_137 () & V_23 ;
if ( ! V_176 ) {
F_12 ( V_23 ) ;
F_13 () ;
}
V_175 = F_27 () ;
V_17 [ V_178 ] [ ( V_175 & V_180 ) ] |= ( V_182 ) ( 0x1 << V_10 ) ;
if ( ! V_176 )
F_12 ( 0 ) ;
}
}
if ( ! V_177 )
V_177 = V_183 ;
F_20 () ;
}
} while ( V_17 [ V_178 ] [ ( V_177 & V_180 ) ] );
F_117 (i) {
if ( ( V_30 & V_31 ) ||
( V_27 [ V_10 ] . V_54 == V_27 [ V_42 ] . V_54 ) )
F_138 ( V_10 , V_174 ) = F_135 ( V_10 ) = V_177 ;
}
if ( V_30 & V_31 )
F_59 ( V_96 ) ;
else
F_58 ( V_96 ) ;
F_60 ( V_62 ) ;
}
void F_139 ( unsigned long V_177 )
{
int V_184 ;
unsigned long V_185 ;
V_184 = F_140 () ;
while ( V_184 < V_29 . V_28 ) {
F_141 ( V_184 ) ;
F_19 () ;
F_142 () ;
F_19 () ;
V_185 = F_143 () ;
if ( ( V_185 & V_180 ) == V_177 ) {
F_144 ( V_186 + ( V_184 << ( V_187 + 1 ) ) ) ;
F_145 ( 0 ) ;
F_146 ( 0 ) ;
F_147 () ;
F_148 () ;
}
V_184 ++ ;
}
F_141 ( V_188 ) ;
F_149 () ;
}
void F_150 ( void )
{
int V_42 ;
F_117 (cpu) {
if ( V_42 != F_64 () ) {
F_11 ( V_27 [ V_42 ] . V_55 ) ;
V_189 [ V_42 ] = F_137 () ;
F_12 ( V_23 ) ;
}
}
F_13 () ;
}
void F_151 ( void )
{
int V_42 ;
F_13 () ;
F_117 (cpu) {
if ( V_42 != F_64 () ) {
F_11 ( V_27 [ V_42 ] . V_55 ) ;
F_12 ( V_189 [ V_42 ] ) ;
}
}
F_13 () ;
}
