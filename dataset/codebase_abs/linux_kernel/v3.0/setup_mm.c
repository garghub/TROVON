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
int V_32 ;
F_1 ( ( const struct V_1 * ) V_33 ) ;
if ( V_34 )
V_35 = 4 ;
else if ( V_36 )
V_35 = 6 ;
#ifndef F_15
if ( V_37 & ( V_38 | V_39 | V_40 | V_41 ) ) {
volatile int V_42 = 0 ;
asm volatile ("frestore %0" : : "m" (zero));
}
#endif
if ( V_36 ) {
T_2 V_43 ;
asm (".chip 68060; movec %%pcr,%0; .chip 68k"
: "=d" (pcr));
if ( ( ( V_43 >> 8 ) & 0xff ) <= 5 ) {
F_2 ( L_4 ) ;
asm (".chip 68060; movec %0,%%pcr; .chip 68k"
: : "d" (pcr | 0x20));
}
}
V_44 . V_45 = V_46 ;
V_44 . V_47 = ( unsigned long ) V_48 ;
V_44 . V_49 = ( unsigned long ) V_50 ;
V_44 . V_51 = ( unsigned long ) V_33 ;
* V_31 = V_20 ;
memcpy ( V_52 , * V_31 , V_53 ) ;
F_16 () ;
#ifdef F_17
V_54 = & V_55 ;
#endif
switch ( V_56 ) {
#ifdef F_18
case V_57 :
F_19 () ;
break;
#endif
#ifdef F_20
case V_58 :
F_21 () ;
break;
#endif
#ifdef F_22
case V_59 :
F_23 () ;
break;
#endif
#ifdef F_24
case V_60 :
F_25 () ;
break;
#endif
#ifdef F_26
case V_61 :
F_27 () ;
break;
#endif
#ifdef F_28
case V_62 :
F_29 () ;
break;
#endif
#ifdef F_30
case V_63 :
F_31 () ;
break;
#endif
#ifdef F_32
case V_64 :
F_33 () ;
break;
#endif
#ifdef F_34
case V_65 :
F_35 () ;
break;
#endif
#ifdef F_36
case V_66 :
F_37 () ;
break;
#endif
#ifdef F_38
case V_67 :
F_39 () ;
break;
#endif
default:
F_40 ( L_5 ) ;
}
#ifdef F_41
F_42 () ;
#endif
F_43 () ;
#ifndef F_24
for ( V_32 = 1 ; V_32 < V_12 ; V_32 ++ )
F_44 ( F_45 ( V_32 ) , V_14 [ V_32 ] . V_15 ,
V_14 [ V_32 ] . V_16 ) ;
#ifdef F_46
if ( V_18 . V_16 ) {
F_47 ( F_48 ( F_49 ( V_18 . V_15 ) ) ,
V_18 . V_15 , V_18 . V_16 ,
V_68 ) ;
V_69 = ( unsigned long ) F_49 ( V_18 . V_15 ) ;
V_70 = V_69 + V_18 . V_16 ;
F_2 ( L_6 , V_69 , V_70 ) ;
}
#endif
#ifdef F_20
if ( V_22 )
F_50 ( ( void * ) V_71 ) ;
#endif
#ifdef F_38
if ( V_72 ) {
F_51 () ;
}
#endif
#endif
#if F_52 ( V_73 ) && F_52 ( V_74 )
if ( V_24 ) {
V_75 = V_76 ;
V_77 = 0 ;
}
#ifdef F_53
if ( V_21 && F_54 ( V_78 ) ) {
V_75 = V_79 ;
V_77 = 1 ;
}
#endif
#endif
}
static int F_55 ( struct V_80 * V_81 , void * V_82 )
{
const char * V_83 , * V_84 , * V_85 ;
unsigned long V_86 , V_87 ;
#define F_56 (8)
#define F_57 (8)
#define F_58 (3)
#define F_59 (1)
if ( V_88 ) {
V_83 = L_7 ;
V_87 = F_56 ;
} else if ( V_89 ) {
V_83 = L_8 ;
V_87 = F_57 ;
} else if ( V_34 ) {
V_83 = L_9 ;
V_87 = F_58 ;
} else if ( V_36 ) {
V_83 = L_10 ;
V_87 = F_59 ;
} else {
V_83 = L_11 ;
V_87 = 0 ;
}
#ifdef F_15
V_85 = L_12 ;
#else
if ( V_37 & V_38 )
V_85 = L_13 ;
else if ( V_37 & V_39 )
V_85 = L_14 ;
else if ( V_37 & V_40 )
V_85 = L_9 ;
else if ( V_37 & V_41 )
V_85 = L_10 ;
else if ( V_37 & V_90 )
V_85 = L_15 ;
else
V_85 = L_16 ;
#endif
if ( V_91 & V_92 )
V_84 = L_17 ;
else if ( V_91 & V_93 )
V_84 = L_8 ;
else if ( V_91 & V_94 )
V_84 = L_9 ;
else if ( V_91 & V_95 )
V_84 = L_10 ;
else if ( V_91 & V_96 )
V_84 = L_18 ;
else if ( V_91 & V_97 )
V_84 = L_19 ;
else
V_84 = L_20 ;
V_86 = V_98 * V_99 * V_87 ;
F_60 ( V_81 , L_21
L_22
L_23
L_24
L_25
L_26 ,
V_83 , V_84 , V_85 ,
V_86 / 1000000 , ( V_86 / 100000 ) % 10 ,
V_98 / ( 500000 / V_99 ) , ( V_98 / ( 5000 / V_99 ) ) % 100 ,
V_98 ) ;
return 0 ;
}
static void * F_61 ( struct V_80 * V_81 , T_3 * V_100 )
{
return * V_100 < 1 ? ( void * ) 1 : NULL ;
}
static void * F_62 ( struct V_80 * V_81 , void * V_82 , T_3 * V_100 )
{
++ * V_100 ;
return NULL ;
}
static void F_63 ( struct V_80 * V_81 , void * V_82 )
{
}
static int F_64 ( struct V_80 * V_81 , void * V_82 )
{
char V_101 [ 80 ] ;
unsigned long V_102 ;
int V_32 ;
if ( V_103 )
V_103 ( V_101 ) ;
else
strcpy ( V_101 , L_27 ) ;
F_60 ( V_81 , L_28 , V_101 ) ;
for ( V_102 = 0 , V_32 = 0 ; V_32 < V_12 ; V_32 ++ )
V_102 += V_14 [ V_32 ] . V_16 ;
F_60 ( V_81 , L_29 , V_102 >> 10 ) ;
if ( V_104 )
V_104 ( V_81 ) ;
return 0 ;
}
static int F_65 ( struct V_105 * V_105 , struct V_106 * V_106 )
{
return F_66 ( V_106 , F_64 , NULL ) ;
}
static int T_1 F_67 ( void )
{
F_68 ( L_30 , 0 , NULL , & V_107 ) ;
return 0 ;
}
void F_69 ( void )
{
#ifndef F_70
if ( V_37 == 0 ) {
F_2 ( V_108 L_31
L_32 ) ;
F_2 ( V_108 L_33
L_34 ) ;
F_40 ( L_35 ) ;
}
#endif
}
static int T_1 F_71 ( char * V_109 ) {
extern int V_110 ;
V_110 = 1 ;
return 1 ;
}
