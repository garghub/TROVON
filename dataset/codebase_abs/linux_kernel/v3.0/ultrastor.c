static inline int F_1 ( unsigned long * V_1 )
{
int V_2 ;
if ( * V_1 == 0 )
F_2 ( L_1 ) ;
asm volatile (
"xorl %0,%0\n\t"
"0: bsfw %1,%w0\n\t"
"btr %0,%1\n\t"
"jnc 0b"
: "=&r" (rv), "+m" (*field) :);
return V_2 ;
}
static inline unsigned char F_3 ( unsigned char V_3 ,
volatile unsigned char * V_4 )
{
__asm__ ("xchgb %0,%1" : "=q" (reg), "=m" (*mem) : "0" (reg));
return V_3 ;
}
static void F_4 ( struct V_5 * V_6 ,
int V_7 )
{
static char V_8 [ 80 ] = L_2 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
{
V_8 [ 20 + V_9 * 2 ] = ' ' ;
if ( ! ( V_6 -> V_11 & ( 1 << V_9 ) ) )
V_8 [ 21 + V_9 * 2 ] = '0' + V_6 -> V_12 [ V_9 ] . V_13 ;
else
V_8 [ 21 + V_9 * 2 ] = '-' ;
}
V_8 [ 20 + V_10 * 2 ] = '\n' ;
V_8 [ 21 + V_10 * 2 ] = 0 ;
F_5 ( V_8 , V_7 , & V_6 -> V_12 [ V_7 ] , V_6 -> V_11 ) ;
}
static int F_6 ( struct V_14 * V_15 )
{
T_1 V_9 ;
unsigned char V_16 , V_17 = 0 ;
struct V_18 {
unsigned char V_19 : 3 ;
unsigned char V_20 : 1 ;
unsigned char V_21 : 2 ;
unsigned char V_22 : 2 ;
} V_18 ;
struct V_23 {
unsigned char V_24 : 3 ;
unsigned char V_25 : 2 ;
unsigned char V_26 : 1 ;
unsigned char V_27 : 2 ;
} V_23 ;
#if ( V_28 & V_29 )
F_5 ( L_3 ) ;
#endif
if ( V_6 . V_19 )
return FALSE ;
#ifdef F_7
if( ! F_8 ( F_7 , 0xc , L_4 ) ) {
F_5 ( L_5 ) ;
return FALSE ;
} ;
V_6 . V_30 = F_7 ;
#else
for ( V_9 = 0 ; V_9 < F_9 ( V_31 ) ; V_9 ++ ) {
if( ! F_8 ( V_31 [ V_9 ] , 0x0c , L_4 ) ) continue;
V_6 . V_30 = V_31 [ V_9 ] ;
#endif
#if ( V_28 & V_29 )
F_5 ( L_6 , V_6 . V_30 ) ;
#endif
V_16 = F_10 ( F_11 ( V_6 . V_30 ) ) ;
if ( V_16 != V_32 ) {
#if ( V_28 & V_29 )
# ifdef F_7
F_5 ( L_7 , V_16 ) ;
# else
F_5 ( L_8 , V_6 . V_30 ) ;
# endif
#endif
#ifdef F_7
goto V_33;
#else
F_12 ( V_6 . V_30 , 0x0c ) ;
continue;
#endif
}
V_16 = F_10 ( F_11 ( V_6 . V_30 ) + 1 ) ;
if ( ( V_16 & 0xF0 ) != V_34 ) {
#if ( V_28 & V_29 )
# ifdef F_7
F_5 ( L_9 , V_16 ) ;
# else
F_5 ( L_8 , V_6 . V_30 ) ;
# endif
#endif
#ifdef F_7
goto V_33;
#else
F_12 ( V_6 . V_30 , 0x0c ) ;
continue;
#endif
}
V_17 = V_16 ;
#ifndef F_7
break;
}
if ( V_9 == F_9 ( V_31 ) ) {
# if ( V_28 & V_29 )
F_5 ( L_10 ) ;
# endif
return FALSE ;
}
#endif
#if ( V_28 & V_29 )
F_5 ( L_11 ,
V_6 . V_30 ) ;
#endif
F_13 ( V_35 ? 0xc2 : 0x82 , F_14 ( V_6 . V_30 ) ) ;
* ( char * ) & V_18 = F_10 ( F_15 ( V_6 . V_30 + 0 ) ) ;
* ( char * ) & V_23 = F_10 ( F_15 ( V_6 . V_30 + 1 ) ) ;
V_6 . V_19 = V_36 [ V_18 . V_19 ] ;
V_6 . V_37 = V_6 . V_30 ;
V_6 . V_38 = V_6 . V_30 + 0x8 ;
V_6 . V_39 = V_6 . V_30 + 0xC ;
V_6 . V_21 = V_40 [ V_18 . V_21 ] ;
V_6 . V_24 = V_23 . V_24 ;
V_6 . V_41 = V_42 [ V_23 . V_25 ] . V_41 ;
V_6 . V_43 = V_42 [ V_23 . V_25 ] . V_43 ;
V_6 . V_26 = V_23 . V_26 ;
V_6 . V_44 = ( V_17 & 0x0F ) ;
if ( V_6 . V_44 == V_45 )
V_6 . V_22 = 0 ;
else
V_6 . V_22 = V_46 [ V_18 . V_22 ] ;
if ( ! V_6 . V_19 ) {
#if ( V_28 & V_29 )
F_5 ( L_12 ) ;
#endif
goto V_33;
}
if ( V_6 . V_44 != V_45 )
if ( ! V_6 . V_22 || ! ( V_23 . V_27 & 0x2 ) ) {
#if ( V_28 & V_29 )
F_5 ( L_13 ) ;
#endif
goto V_33;
}
#if ( V_28 & V_29 )
F_5 ( L_14
L_15
L_16
L_17
L_18
L_19
L_20 ,
V_6 . V_30 , V_6 . V_19 , V_6 . V_21 ,
V_6 . V_22 , V_6 . V_24 , V_6 . V_44 ) ;
#endif
V_15 -> V_47 = V_6 . V_24 ;
V_15 -> V_48 = ( V_6 . V_44 != V_45 ) ;
#if V_10 > 1
V_6 . V_11 = ~ 0 ;
#endif
if ( F_16 ( V_6 . V_21 , V_49 , 0 , L_21 , & V_6 . V_12 [ 0 ] . V_50 -> V_51 -> V_52 ) ) {
F_5 ( L_22 ,
V_6 . V_21 ) ;
goto V_33;
}
if ( V_6 . V_22 && F_17 ( V_6 . V_22 , L_21 ) ) {
F_5 ( L_23 ,
V_6 . V_22 ) ;
F_18 ( V_6 . V_21 , NULL ) ;
goto V_33;
}
V_15 -> V_53 = V_54 ;
F_5 ( L_24 V_55 L_25 ,
V_54 ) ;
return TRUE ;
V_33:
F_12 ( V_6 . V_30 , 0x0c ) ;
return FALSE ;
}
static int F_19 ( struct V_14 * V_15 )
{
int V_9 ;
struct V_56 * V_57 = NULL ;
#if ( V_28 & V_29 )
F_5 ( L_26 ) ;
#endif
for ( V_9 = 1 ; V_9 < 15 ; V_9 ++ )
{
unsigned char V_18 , V_23 ;
unsigned short V_58 = ( V_9 << 12 ) | V_59 ;
if ( F_10 ( V_58 ) != V_60 &&
F_10 ( V_58 + 1 ) != V_61 &&
F_10 ( V_58 + 2 ) != V_62 )
continue;
V_6 . V_63 = F_10 ( V_58 + 3 ) ;
V_6 . V_64 = V_9 ;
if ( ! ( F_10 ( V_58 + 4 ) & 1 ) )
{
#if ( V_28 & V_29 )
F_5 ( L_27 , V_9 ) ;
#endif
continue;
}
#if ( V_28 & V_29 )
F_5 ( L_28 , V_9 ) ;
#endif
V_18 = F_10 ( V_58 + 5 ) ;
V_6 . V_19 = V_36 [ V_18 & 7 ] ;
switch( V_18 >> 4 )
{
case 1 :
V_6 . V_21 = 15 ;
break;
case 2 :
V_6 . V_21 = 14 ;
break;
case 4 :
V_6 . V_21 = 11 ;
break;
case 8 :
V_6 . V_21 = 10 ;
break;
default:
F_5 ( L_29 ) ;
return FALSE ;
}
V_6 . V_30 = V_58 ;
V_6 . V_37 = V_58 + 12 ;
V_6 . V_38 = V_58 + 0x17 ;
V_6 . V_39 = V_58 + 0x1C ;
V_23 = F_10 ( V_58 + 7 ) ;
V_6 . V_24 = V_23 & 7 ;
V_6 . V_41 = V_42 [ ( V_23 >> 3 ) & 3 ] . V_41 ;
V_6 . V_43 = V_42 [ ( V_23 >> 3 ) & 3 ] . V_43 ;
#if ( V_28 & V_29 )
F_5 ( L_30
L_15
L_16
L_17
L_19 ,
V_6 . V_30 , V_6 . V_19 ,
V_6 . V_21 , V_6 . V_24 ) ;
#endif
V_15 -> V_47 = V_6 . V_24 ;
V_15 -> V_48 = 0 ;
V_15 -> V_53 = V_65 ;
V_57 = F_20 ( V_15 , 0 ) ;
if ( ! V_57 ) {
F_5 ( V_66 L_31 ) ;
F_18 ( V_6 . V_21 , V_49 ) ;
return FALSE ;
}
if ( F_16 ( V_6 . V_21 , V_49 , 0 , L_21 , V_57 ) )
{
F_5 ( L_22 ,
V_6 . V_21 ) ;
return FALSE ;
}
V_57 -> V_67 = V_6 . V_21 ;
V_57 -> V_22 = V_6 . V_22 ;
V_57 -> V_68 = V_6 . V_30 ;
#if V_10 > 1
V_6 . V_11 = ~ 0 ;
#endif
F_13 ( 0 , V_58 + 0x16 ) ;
F_13 ( 0 , V_58 + 0x1B ) ;
F_13 ( V_35 ? 0xc2 : 0x82 , F_14 ( V_58 + 12 ) ) ;
F_13 ( 0x02 , F_21 ( V_58 + 12 ) ) ;
F_5 ( L_32 V_55 L_25 ,
V_15 -> V_53 ) ;
return TRUE ;
}
return FALSE ;
}
static int F_22 ( struct V_14 * V_15 )
{
V_15 -> V_69 = L_4 ;
return F_6 ( V_15 ) || F_19 ( V_15 ) ;
}
static int F_23 ( struct V_56 * V_70 )
{
if ( V_70 -> V_67 )
F_18 ( V_70 -> V_67 , NULL ) ;
if ( V_70 -> V_22 != 0xff )
F_24 ( V_70 -> V_22 ) ;
if ( V_70 -> V_68 && V_70 -> V_71 )
F_12 ( V_70 -> V_68 , V_70 -> V_71 ) ;
F_25 ( V_70 ) ;
return 0 ;
}
static const char * F_26 ( struct V_56 * V_57 )
{
static char V_72 [ 64 ] ;
if ( V_6 . V_64 )
sprintf ( V_72 , L_33 ,
V_6 . V_64 , V_6 . V_21 ) ;
else if ( V_6 . V_44 )
sprintf ( V_72 , L_34 ,
V_6 . V_30 , ( int ) V_6 . V_19 ,
V_6 . V_21 ) ;
else
sprintf ( V_72 , L_35 ,
V_6 . V_30 , ( int ) V_6 . V_19 ,
V_6 . V_21 , V_6 . V_22 ) ;
return V_72 ;
}
static inline void F_27 ( struct V_12 * V_12 , struct V_73 * V_74 )
{
struct V_75 * V_76 ;
long V_77 = 0 ;
int V_9 , V_78 ;
V_78 = F_28 ( V_74 ) ;
F_29 (SCpnt, sg, max, i) {
V_12 -> V_79 [ V_9 ] . V_80 = F_30 ( F_31 ( V_76 ) ) + V_76 -> V_81 ;
V_12 -> V_79 [ V_9 ] . V_82 = V_76 -> V_83 ;
V_77 += V_76 -> V_83 ;
}
V_12 -> V_84 = V_78 ;
V_12 -> V_85 = F_32 ( V_12 -> V_79 ) ;
V_12 -> V_86 = V_77 ;
}
static int F_33 ( struct V_73 * V_74 ,
void (* F_34) ( struct V_73 * ) )
{
struct V_12 * V_87 ;
#if V_10 > 1
int V_88 ;
#endif
unsigned int V_89 ;
if ( ( V_6 . V_11 & ( ( 1U << V_10 ) - 1 ) ) == 0 )
F_2 ( L_36 ) ;
V_88 = F_1 ( & V_6 . V_11 ) ;
if ( F_3 ( 0xff , & V_6 . V_90 [ V_88 ] ) != 0 )
{
V_89 = V_91 << 16 ;
goto V_90;
}
V_87 = & V_6 . V_12 [ V_88 ] ;
* ( unsigned char * ) V_87 = V_92 | ( V_93 << 3 ) ;
V_87 -> V_94 = V_74 -> V_51 -> type != V_95 ;
V_87 -> V_13 = V_74 -> V_51 -> V_96 ;
V_87 -> V_97 = 0 ;
V_87 -> V_98 = V_74 -> V_51 -> V_98 ;
if ( F_28 ( V_74 ) ) {
V_87 -> V_76 = TRUE ;
F_27 ( V_87 , V_74 ) ;
} else {
V_87 -> V_76 = FALSE ;
V_87 -> V_85 = F_32 ( F_35 ( V_74 ) ) ;
V_87 -> V_86 = F_36 ( V_74 ) ;
}
V_87 -> V_99 = 0 ;
V_87 -> V_100 = 0 ;
V_87 -> V_101 = V_102 ;
V_87 -> V_103 = V_74 -> V_104 ;
memcpy ( V_87 -> V_105 , V_74 -> V_106 , V_87 -> V_103 ) ;
V_87 -> V_107 = 0 ;
V_87 -> V_108 = 0 ;
V_87 -> V_109 = F_32 ( & V_74 -> V_110 ) ;
V_87 -> F_34 = F_34 ;
V_87 -> V_50 = V_74 ;
V_74 -> V_111 = ( unsigned char * ) V_87 ;
V_112:
if ( V_6 . V_64 )
while ( F_10 ( V_6 . V_38 - 1 ) != 0 && V_6 . V_90 [ V_88 ] == 0xff )
F_37 () ;
while ( ( F_10 ( F_38 ( V_6 . V_37 ) ) & ( V_6 . V_64 ? 2 : 1 ) ) && V_6 . V_90 [ V_88 ] == 0xff )
F_37 () ;
if ( F_10 ( F_38 ( V_6 . V_37 ) ) & ( V_6 . V_64 ? 2 : 1 ) )
goto V_112;
V_89 = F_3 ( 0 , & V_6 . V_90 [ V_88 ] ) ;
if ( V_89 != 0xff ) {
#if V_28 & ( V_113 | V_114 )
F_5 ( L_37 ) ;
#if V_10 > 1
F_4 ( & V_6 , V_88 ) ;
#endif
#endif
V_89 <<= 16 ;
V_90:
F_39 ( V_88 , & V_6 . V_11 ) ;
#if V_10 > 1
V_74 -> V_115 = V_89 ;
F_34 ( V_74 ) ;
return 0 ;
#else
return V_89 ;
#endif
}
F_40 ( F_32 ( V_87 ) , V_6 . V_38 ) ;
if ( V_6 . V_64 ) {
F_13 ( 1 , V_6 . V_38 - 1 ) ;
F_13 ( 0x2 , F_38 ( V_6 . V_37 ) ) ;
} else {
F_13 ( 0x1 , F_38 ( V_6 . V_37 ) ) ;
}
#if ( V_28 & V_113 )
F_5 ( L_38 ) ;
#endif
return 0 ;
}
int F_41 ( struct V_73 * V_74 )
{
unsigned long V_116 ;
int V_9 ;
struct V_56 * V_52 = V_74 -> V_51 -> V_52 ;
#if ( V_28 & V_117 )
F_5 ( L_39 ) ;
#endif
if( V_6 . V_64 )
return V_118 ;
F_42 ( V_52 -> V_119 , V_116 ) ;
F_13 ( 0xc0 , F_38 ( V_6 . V_37 ) ) ;
if ( V_6 . V_64 )
{
F_13 ( 0 , V_6 . V_38 - 1 ) ;
F_13 ( 0 , V_6 . V_39 - 1 ) ;
}
#if V_10 == 1
if ( V_6 . V_120 && V_6 . V_12 -> F_34 && V_6 . V_12 -> V_50 )
{
V_6 . V_12 -> V_50 -> V_115 = V_121 << 16 ;
V_6 . V_12 -> F_34 ( V_6 . V_12 -> V_50 ) ;
}
V_6 . V_12 -> V_50 = 0 ;
#else
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
{
if ( ! ( V_6 . V_11 & ( 1 << V_9 ) ) &&
V_6 . V_12 [ V_9 ] . F_34 && V_6 . V_12 [ V_9 ] . V_50 )
{
V_6 . V_12 [ V_9 ] . V_50 -> V_115 = V_121 << 16 ;
V_6 . V_12 [ V_9 ] . F_34 ( V_6 . V_12 [ V_9 ] . V_50 ) ;
V_6 . V_12 [ V_9 ] . F_34 = NULL ;
}
V_6 . V_12 [ V_9 ] . V_50 = NULL ;
}
#endif
memset ( ( unsigned char * ) V_6 . V_90 , 0 , sizeof V_6 . V_90 ) ;
#if V_10 == 1
V_6 . V_120 = 0 ;
#else
V_6 . V_11 = ~ 0 ;
#endif
F_43 ( V_52 -> V_119 , V_116 ) ;
return V_122 ;
}
int F_44 ( struct V_123 * V_124 , struct V_125 * V_126 ,
T_2 V_127 , int * V_128 )
{
int V_129 = V_127 ;
unsigned int V_130 = V_6 . V_41 * V_6 . V_43 ;
V_128 [ 0 ] = V_6 . V_41 ;
V_128 [ 1 ] = V_6 . V_43 ;
V_128 [ 2 ] = V_129 / V_130 ;
#if 0
if (dkinfo[2] > 1024)
dkinfo[2] = 1024;
#endif
return 0 ;
}
static void F_45 ( void * V_131 )
{
unsigned int V_89 ;
#if V_10 > 1
unsigned int V_88 ;
#endif
struct V_12 * V_12 ;
void (* F_34) ( struct V_73 * );
struct V_73 * V_132 ;
#if V_10 == 1
V_12 = & V_6 . V_12 [ 0 ] ;
#else
V_12 = (struct V_12 * ) F_46 ( F_47 ( V_6 . V_39 ) ) ;
V_88 = V_12 - V_6 . V_12 ;
if ( V_88 >= V_10 ) {
F_5 ( L_40 , ( unsigned int ) V_12 ) ;
F_41 ( V_131 ) ;
return;
}
#endif
if ( V_6 . V_64 ) {
unsigned char V_133 = F_10 ( V_6 . V_39 - 1 ) ;
#if V_28 & ( V_134 | V_135 | V_114 )
if ( V_133 != 1 && V_133 != 2 )
F_5 ( L_41 , V_133 ,
V_88 , ( unsigned int ) V_12 ) ;
#endif
F_13 ( 2 , F_48 ( V_6 . V_37 ) ) ;
F_13 ( 0 , V_6 . V_39 - 1 ) ;
if ( V_133 == 4 ) {
F_5 ( L_42 ) ;
return;
}
if ( V_133 == 3 ) {
void (* F_34)( struct V_73 * ) = V_12 -> F_34 ;
if ( F_34 ) {
V_12 -> F_34 = NULL ;
V_12 -> V_50 -> V_115 = V_91 << 16 ;
F_34 ( V_12 -> V_50 ) ;
}
return;
}
} else {
F_13 ( 1 , F_48 ( V_6 . V_37 ) ) ;
}
V_132 = V_12 -> V_50 ;
V_12 -> V_50 = NULL ;
if ( ! V_132 )
{
#if V_28 & ( V_114 | V_134 )
F_5 ( L_43 , V_88 , ( unsigned int ) V_12 ) ;
#endif
#if V_10 == 1
V_6 . V_120 = FALSE ;
#else
F_39 ( V_88 , & V_6 . V_11 ) ;
#endif
V_6 . V_90 [ V_88 ] = 0 ;
return;
}
F_34 = V_12 -> F_34 ;
V_12 -> F_34 = NULL ;
switch ( V_12 -> V_107 )
{
case 0 :
V_89 = V_136 << 16 ;
break;
case 0x01 :
case 0x02 :
case 0x03 :
default:
V_89 = V_137 << 16 ;
break;
case 0x84 :
V_89 = V_91 << 16 ;
break;
case 0x91 :
V_89 = V_138 << 16 ;
break;
}
V_132 -> V_115 = V_89 | V_12 -> V_108 ;
V_132 -> V_111 = NULL ;
#if V_10 == 1
V_6 . V_120 = FALSE ;
#else
F_39 ( V_88 , & V_6 . V_11 ) ;
#endif
#if V_28 & ( V_114 | V_134 )
if ( V_6 . V_90 [ V_88 ] )
F_5 ( L_44 ,
V_88 , ( unsigned int ) V_12 , V_6 . V_90 [ V_88 ] ) ;
#endif
V_6 . V_90 [ V_88 ] = 0 ;
if ( F_34 )
F_34 ( V_132 ) ;
else
F_5 ( L_45 ) ;
if ( V_6 . V_64 ? F_10 ( V_6 . V_39 - 1 ) :
( F_10 ( F_48 ( V_6 . V_37 ) ) & 1 ) )
#if ( V_28 & V_139 )
F_5 ( L_46 ) ;
#else
;
#endif
#if ( V_28 & V_134 )
F_5 ( L_47 ) ;
#endif
}
static T_3 V_49 ( int V_67 , void * V_131 )
{
unsigned long V_116 ;
struct V_56 * V_140 = V_131 ;
F_42 ( V_140 -> V_119 , V_116 ) ;
F_45 ( V_131 ) ;
F_43 ( V_140 -> V_119 , V_116 ) ;
return V_141 ;
}
