static void T_1 F_1 ( const struct V_1 * V_2 )
{
while ( V_2 -> V_3 != V_4 ) {
int V_5 = 0 ;
const unsigned long * V_6 = V_2 -> V_6 ;
switch ( V_2 -> V_3 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
break;
case V_11 :
if ( V_12 < V_13 ) {
V_14 [ V_12 ] . V_15 = V_6 [ 0 ] ;
V_14 [ V_12 ] . V_16 = V_6 [ 1 ] ;
V_12 ++ ;
} else
F_2 ( L_1 ) ;
break;
case V_17 :
V_18 . V_15 = V_6 [ 0 ] ;
V_18 . V_16 = V_6 [ 1 ] ;
break;
case V_19 :
F_3 ( V_20 , ( const char * ) V_6 ,
sizeof( V_20 ) ) ;
break;
default:
if ( V_21 )
V_5 = F_4 ( V_2 ) ;
else if ( V_22 )
V_5 = F_5 ( V_2 ) ;
else if ( V_23 )
V_5 = F_6 ( V_2 ) ;
else if ( V_24 )
V_5 = F_7 ( V_2 ) ;
else if ( V_25 )
V_5 = F_8 ( V_2 ) ;
else if ( V_26 )
V_5 = F_9 ( V_2 ) ;
else if ( V_27 )
V_5 = F_10 ( V_2 ) ;
else if ( V_28 )
V_5 = F_11 ( V_2 ) ;
else if ( V_29 )
V_5 = F_12 ( V_2 ) ;
else
V_5 = 1 ;
}
if ( V_5 )
F_2 ( L_2 ,
V_2 -> V_3 ) ;
V_2 = (struct V_1 * ) ( ( unsigned long ) V_2 +
V_2 -> V_16 ) ;
}
V_30 = V_12 ;
#ifdef F_13
if ( V_12 > 1 ) {
F_2 ( L_3 ,
( V_12 - 1 ) ) ;
V_12 = 1 ;
}
#endif
}
void T_1 F_14 ( char * * V_31 )
{
#ifndef F_15
int V_32 ;
#endif
if ( ! V_33 )
F_1 ( ( const struct V_1 * ) V_34 ) ;
if ( V_35 )
V_36 = 4 ;
else if ( V_37 )
V_36 = 6 ;
#ifndef F_16
if ( V_38 & ( V_39 | V_40 | V_41 | V_42 | V_43 ) ) {
volatile int V_44 = 0 ;
asm volatile ("frestore %0" : : "m" (zero));
}
#endif
if ( V_37 ) {
T_2 V_45 ;
asm (".chip 68060; movec %%pcr,%0; .chip 68k"
: "=d" (pcr));
if ( ( ( V_45 >> 8 ) & 0xff ) <= 5 ) {
F_2 ( L_4 ) ;
asm (".chip 68060; movec %0,%%pcr; .chip 68k"
: : "d" (pcr | 0x20));
}
}
V_46 . V_47 = V_48 ;
V_46 . V_49 = ( unsigned long ) V_50 ;
V_46 . V_51 = ( unsigned long ) V_52 ;
V_46 . V_53 = ( unsigned long ) V_34 ;
#if F_17 ( V_54 )
strncpy ( V_20 , V_55 , V_56 ) ;
V_20 [ V_56 - 1 ] = 0 ;
#endif
* V_31 = V_20 ;
memcpy ( V_57 , * V_31 , V_56 ) ;
F_18 () ;
#ifdef F_19
V_58 = & V_59 ;
#endif
switch ( V_60 ) {
#ifdef F_20
case V_61 :
F_21 () ;
break;
#endif
#ifdef F_22
case V_62 :
F_23 () ;
break;
#endif
#ifdef F_24
case V_63 :
F_25 () ;
break;
#endif
#ifdef F_15
case V_64 :
F_26 () ;
break;
#endif
#ifdef F_27
case V_65 :
F_28 () ;
break;
#endif
#ifdef F_29
case V_66 :
F_30 () ;
break;
#endif
#ifdef F_31
case V_67 :
F_32 () ;
break;
#endif
#ifdef F_33
case V_68 :
F_34 () ;
break;
#endif
#ifdef F_35
case V_69 :
F_36 () ;
break;
#endif
#ifdef F_37
case V_70 :
F_38 () ;
break;
#endif
#ifdef F_39
case V_71 :
F_40 () ;
break;
#endif
#ifdef F_41
case V_72 :
F_42 ( NULL , 0 ) ;
break;
#endif
default:
F_43 ( L_5 ) ;
}
#ifdef F_44
F_45 () ;
#endif
F_46 () ;
#ifndef F_15
for ( V_32 = 1 ; V_32 < V_12 ; V_32 ++ )
F_47 ( F_48 ( V_32 ) , V_14 [ V_32 ] . V_15 ,
V_14 [ V_32 ] . V_16 ) ;
#ifdef F_49
if ( V_18 . V_16 ) {
F_50 ( F_51 ( F_52 ( V_18 . V_15 ) ) ,
V_18 . V_15 , V_18 . V_16 ,
V_73 ) ;
V_74 = ( unsigned long ) F_52 ( V_18 . V_15 ) ;
V_75 = V_74 + V_18 . V_16 ;
F_2 ( L_6 , V_74 , V_75 ) ;
}
#endif
#ifdef F_22
if ( V_22 )
F_53 ( ( void * ) V_76 ) ;
#endif
#ifdef F_39
if ( V_77 ) {
F_54 () ;
}
#endif
#endif
#if F_17 ( V_78 ) && F_17 ( V_79 )
if ( V_24 ) {
V_80 = V_81 ;
V_82 = 0 ;
}
#ifdef F_55
if ( V_21 && F_56 ( V_83 ) ) {
V_80 = V_84 ;
V_82 = 1 ;
}
#endif
#ifdef F_57
if ( V_22 ) {
V_80 = V_85 ;
V_82 = 0 ;
}
#endif
#endif
}
static int F_58 ( struct V_86 * V_87 , void * V_88 )
{
const char * V_89 , * V_90 , * V_91 ;
unsigned long V_92 , V_93 ;
#define F_59 (8)
#define F_60 (8)
#define F_61 (3)
#define F_62 (1)
#define F_63 (2)
if ( V_94 ) {
V_89 = L_7 ;
V_93 = F_59 ;
} else if ( V_95 ) {
V_89 = L_8 ;
V_93 = F_60 ;
} else if ( V_35 ) {
V_89 = L_9 ;
V_93 = F_61 ;
} else if ( V_37 ) {
V_89 = L_10 ;
V_93 = F_62 ;
} else if ( V_33 ) {
V_89 = L_11 ;
V_93 = F_63 ;
} else {
V_89 = L_12 ;
V_93 = 0 ;
}
#ifdef F_16
V_91 = L_13 ;
#else
if ( V_38 & V_39 )
V_91 = L_14 ;
else if ( V_38 & V_40 )
V_91 = L_15 ;
else if ( V_38 & V_41 )
V_91 = L_9 ;
else if ( V_38 & V_42 )
V_91 = L_10 ;
else if ( V_38 & V_96 )
V_91 = L_16 ;
else if ( V_38 & V_43 )
V_91 = L_11 ;
else
V_91 = L_17 ;
#endif
if ( V_97 & V_98 )
V_90 = L_18 ;
else if ( V_97 & V_99 )
V_90 = L_8 ;
else if ( V_97 & V_100 )
V_90 = L_9 ;
else if ( V_97 & V_101 )
V_90 = L_10 ;
else if ( V_97 & V_102 )
V_90 = L_19 ;
else if ( V_97 & V_103 )
V_90 = L_20 ;
else if ( V_97 & V_104 )
V_90 = L_11 ;
else
V_90 = L_21 ;
V_92 = V_105 * V_106 * V_93 ;
F_64 ( V_87 , L_22
L_23
L_24
L_25
L_26
L_27 ,
V_89 , V_90 , V_91 ,
V_92 / 1000000 , ( V_92 / 100000 ) % 10 ,
V_105 / ( 500000 / V_106 ) , ( V_105 / ( 5000 / V_106 ) ) % 100 ,
V_105 ) ;
return 0 ;
}
static void * F_65 ( struct V_86 * V_87 , T_3 * V_107 )
{
return * V_107 < 1 ? ( void * ) 1 : NULL ;
}
static void * F_66 ( struct V_86 * V_87 , void * V_88 , T_3 * V_107 )
{
++ * V_107 ;
return NULL ;
}
static void F_67 ( struct V_86 * V_87 , void * V_88 )
{
}
static int F_68 ( struct V_86 * V_87 , void * V_88 )
{
char V_108 [ 80 ] ;
unsigned long V_109 ;
int V_32 ;
if ( V_110 )
V_110 ( V_108 ) ;
else
strcpy ( V_108 , L_28 ) ;
F_64 ( V_87 , L_29 , V_108 ) ;
for ( V_109 = 0 , V_32 = 0 ; V_32 < V_12 ; V_32 ++ )
V_109 += V_14 [ V_32 ] . V_16 ;
F_64 ( V_87 , L_30 , V_109 >> 10 ) ;
if ( V_111 )
V_111 ( V_87 ) ;
return 0 ;
}
static int F_69 ( struct V_112 * V_112 , struct V_113 * V_113 )
{
return F_70 ( V_113 , F_68 , NULL ) ;
}
static int T_1 F_71 ( void )
{
F_72 ( L_31 , 0 , NULL , & V_114 ) ;
return 0 ;
}
void F_73 ( void )
{
#ifndef F_74
if ( V_38 == 0 ) {
F_2 ( V_115 L_32
L_33 ) ;
F_2 ( V_115 L_34
L_35 ) ;
F_43 ( L_36 ) ;
}
#endif
}
static int T_1 F_75 ( char * V_116 ) {
extern int V_117 ;
V_117 = 1 ;
return 1 ;
}
