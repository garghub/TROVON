static void T_1 F_1 ( const struct V_1 * V_2 )
{
T_2 V_3 ;
F_2 ( V_2 ) ;
while ( ( V_3 = F_3 ( V_2 -> V_3 ) ) != V_4 ) {
int V_5 = 0 ;
const void * V_6 = V_2 -> V_6 ;
T_2 V_7 = F_3 ( V_2 -> V_7 ) ;
switch ( V_3 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
break;
case V_12 :
if ( V_13 < V_14 ) {
const struct V_15 * V_16 = V_6 ;
V_17 [ V_13 ] . V_18 =
F_4 ( V_16 -> V_18 ) ;
V_17 [ V_13 ] . V_7 =
F_4 ( V_16 -> V_7 ) ;
V_13 ++ ;
} else
F_5 ( L_1 ,
V_19 ) ;
break;
case V_20 :
{
const struct V_15 * V_16 = V_6 ;
V_21 . V_18 = F_4 ( V_16 -> V_18 ) ;
V_21 . V_7 = F_4 ( V_16 -> V_7 ) ;
}
break;
case V_22 :
F_6 ( V_23 , V_6 ,
sizeof( V_23 ) ) ;
break;
default:
if ( V_24 )
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
else if ( V_30 )
V_5 = F_13 ( V_2 ) ;
else if ( V_31 )
V_5 = F_14 ( V_2 ) ;
else if ( V_32 )
V_5 = F_15 ( V_2 ) ;
else
V_5 = 1 ;
}
if ( V_5 )
F_5 ( L_2 , V_19 ,
V_3 ) ;
V_2 = (struct V_1 * ) ( ( unsigned long ) V_2 + V_7 ) ;
}
V_33 = V_13 ;
#ifdef F_16
if ( V_13 > 1 ) {
F_5 ( L_3 ,
V_19 , ( V_13 - 1 ) ) ;
V_13 = 1 ;
}
#endif
}
void T_1 F_17 ( char * * V_34 )
{
#ifndef F_18
int V_35 ;
#endif
if ( ! V_36 )
F_1 ( ( const struct V_1 * ) V_37 ) ;
if ( V_38 )
V_39 = 4 ;
else if ( V_40 )
V_39 = 6 ;
#if F_19 ( V_41 ) && ! F_19 ( V_42 )
if ( V_43 & ( V_44 | V_45 | V_46 | V_47 | V_48 ) ) {
volatile int V_49 = 0 ;
asm volatile ("frestore %0" : : "m" (zero));
}
#endif
if ( V_40 ) {
T_3 V_50 ;
asm (".chip 68060; movec %%pcr,%0; .chip 68k"
: "=d" (pcr));
if ( ( ( V_50 >> 8 ) & 0xff ) <= 5 ) {
F_5 ( L_4 ) ;
asm (".chip 68060; movec %0,%%pcr; .chip 68k"
: : "d" (pcr | 0x20));
}
}
V_51 . V_52 = V_53 ;
V_51 . V_54 = ( unsigned long ) V_55 ;
V_51 . V_56 = ( unsigned long ) V_57 ;
V_51 . V_58 = ( unsigned long ) V_37 ;
#if F_19 ( V_59 )
strncpy ( V_23 , V_60 , V_61 ) ;
V_23 [ V_61 - 1 ] = 0 ;
#endif
F_20 ( & V_23 [ 0 ] , V_61 ) ;
* V_34 = V_23 ;
memcpy ( V_62 , * V_34 , V_61 ) ;
F_21 () ;
#ifdef F_22
V_63 = & V_64 ;
#endif
switch ( V_65 ) {
#ifdef F_23
case V_66 :
F_24 () ;
break;
#endif
#ifdef F_25
case V_67 :
F_26 () ;
break;
#endif
#ifdef F_27
case V_68 :
F_28 () ;
break;
#endif
#ifdef F_18
case V_69 :
F_29 () ;
break;
#endif
#ifdef F_30
case V_70 :
F_31 () ;
break;
#endif
#ifdef F_32
case V_71 :
F_33 () ;
break;
#endif
#ifdef F_34
case V_72 :
F_35 () ;
break;
#endif
#ifdef F_36
case V_73 :
F_37 () ;
break;
#endif
#ifdef F_38
case V_74 :
F_39 () ;
break;
#endif
#ifdef F_40
case V_75 :
F_41 () ;
break;
#endif
#ifdef F_42
case V_76 :
F_43 () ;
break;
#endif
#ifdef F_44
case V_77 :
case V_78 :
F_45 ( NULL , 0 ) ;
break;
#endif
default:
F_46 ( L_5 ) ;
}
F_47 () ;
#ifdef F_48
F_49 () ;
#endif
#ifndef F_18
for ( V_35 = 1 ; V_35 < V_13 ; V_35 ++ )
F_50 ( F_51 ( V_35 ) , V_17 [ V_35 ] . V_18 ,
V_17 [ V_35 ] . V_7 ) ;
#ifdef F_52
if ( V_21 . V_7 ) {
F_53 ( F_54 ( F_55 ( V_21 . V_18 ) ) ,
V_21 . V_18 , V_21 . V_7 ,
V_79 ) ;
V_80 = ( unsigned long ) F_55 ( V_21 . V_18 ) ;
V_81 = V_80 + V_21 . V_7 ;
F_56 ( L_6 , V_80 , V_81 ) ;
}
#endif
#ifdef F_25
if ( V_25 )
F_57 ( ( void * ) V_82 ) ;
#endif
#ifdef F_42
if ( V_83 ) {
F_58 () ;
}
#endif
#endif
#if F_19 ( V_84 ) && F_19 ( V_85 )
if ( V_27 ) {
V_86 = V_87 ;
V_88 = 0 ;
}
#ifdef F_59
if ( V_24 && F_60 ( V_89 ) ) {
V_86 = V_90 ;
V_88 = 1 ;
}
#endif
#ifdef F_61
if ( V_25 ) {
V_86 = V_91 ;
V_88 = 0 ;
}
#endif
#endif
}
static int F_62 ( struct V_92 * V_16 , void * V_93 )
{
const char * V_94 , * V_95 , * V_96 ;
unsigned long V_97 , V_98 ;
#define F_63 (8)
#define F_64 (8)
#define F_65 (3)
#define F_66 (1)
#define F_67 (2)
if ( V_99 ) {
V_94 = L_7 ;
V_98 = F_63 ;
} else if ( V_100 ) {
V_94 = L_8 ;
V_98 = F_64 ;
} else if ( V_38 ) {
V_94 = L_9 ;
V_98 = F_65 ;
} else if ( V_40 ) {
V_94 = L_10 ;
V_98 = F_66 ;
} else if ( V_36 ) {
V_94 = L_11 ;
V_98 = F_67 ;
} else {
V_94 = L_12 ;
V_98 = 0 ;
}
#ifdef V_42
V_96 = L_13 ;
#else
if ( V_43 & V_44 )
V_96 = L_14 ;
else if ( V_43 & V_45 )
V_96 = L_15 ;
else if ( V_43 & V_46 )
V_96 = L_9 ;
else if ( V_43 & V_47 )
V_96 = L_10 ;
else if ( V_43 & V_101 )
V_96 = L_16 ;
else if ( V_43 & V_48 )
V_96 = L_11 ;
else
V_96 = L_17 ;
#endif
if ( V_102 & V_103 )
V_95 = L_18 ;
else if ( V_102 & V_104 )
V_95 = L_8 ;
else if ( V_102 & V_105 )
V_95 = L_9 ;
else if ( V_102 & V_106 )
V_95 = L_10 ;
else if ( V_102 & V_107 )
V_95 = L_19 ;
else if ( V_102 & V_108 )
V_95 = L_20 ;
else if ( V_102 & V_109 )
V_95 = L_11 ;
else
V_95 = L_21 ;
V_97 = V_110 * V_111 * V_98 ;
F_68 ( V_16 , L_22
L_23
L_24
L_25
L_26
L_27 ,
V_94 , V_95 , V_96 ,
V_97 / 1000000 , ( V_97 / 100000 ) % 10 ,
V_110 / ( 500000 / V_111 ) , ( V_110 / ( 5000 / V_111 ) ) % 100 ,
V_110 ) ;
return 0 ;
}
static void * F_69 ( struct V_92 * V_16 , T_4 * V_112 )
{
return * V_112 < 1 ? ( void * ) 1 : NULL ;
}
static void * F_70 ( struct V_92 * V_16 , void * V_93 , T_4 * V_112 )
{
++ * V_112 ;
return NULL ;
}
static void F_71 ( struct V_92 * V_16 , void * V_93 )
{
}
static int F_72 ( struct V_92 * V_16 , void * V_93 )
{
char V_113 [ 80 ] ;
unsigned long V_114 ;
int V_35 ;
if ( V_115 )
V_115 ( V_113 ) ;
else
strcpy ( V_113 , L_28 ) ;
F_68 ( V_16 , L_29 , V_113 ) ;
for ( V_114 = 0 , V_35 = 0 ; V_35 < V_13 ; V_35 ++ )
V_114 += V_17 [ V_35 ] . V_7 ;
F_68 ( V_16 , L_30 , V_114 >> 10 ) ;
if ( V_116 )
V_116 ( V_16 ) ;
return 0 ;
}
static int F_73 ( struct V_117 * V_117 , struct V_118 * V_118 )
{
return F_74 ( V_118 , F_72 , NULL ) ;
}
static int T_1 F_75 ( void )
{
F_76 ( L_31 , 0 , NULL , & V_119 ) ;
return 0 ;
}
void F_77 ( void )
{
#if F_19 ( V_41 ) && ! F_19 ( V_120 )
if ( V_43 == 0 ) {
F_78 ( L_32
L_33 ) ;
F_78 ( L_34
L_35 ) ;
F_46 ( L_36 ) ;
}
#endif
}
static int T_1 F_79 ( char * V_121 ) {
extern int V_122 ;
V_122 = 1 ;
return 1 ;
}
