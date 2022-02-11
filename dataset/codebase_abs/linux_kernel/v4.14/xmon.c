static inline long F_1 ( unsigned long V_1 ) { return 0 ; }
static inline void F_2 ( void )
{
printf ( L_1 ) ;
}
static inline void F_3 ( void )
{
asm volatile("sync; isync");
}
static inline void F_4 ( void * V_2 )
{
asm volatile ("dcbst 0,%0; sync; icbi 0,%0; isync" : : "r" (p));
}
static inline void F_5 ( void * V_2 )
{
asm volatile ("dcbf 0,%0; icbi 0,%0" : : "r" (p));
}
static inline void F_6 ( void * V_2 )
{
asm volatile ("dcbi 0,%0; icbi 0,%0" : : "r" (p));
}
static void F_7 ( unsigned long V_1 )
{
if ( ! F_8 ( V_3 ) )
return;
if ( F_8 ( V_4 ) ) {
F_9 ( V_5 , V_1 ) ;
return;
}
F_1 ( V_1 ) ;
}
static void F_10 ( unsigned long V_6 )
{
V_6 &= ~ V_7 ;
if ( F_8 ( V_4 ) )
V_6 |= V_8 ;
else
V_6 |= V_9 ;
F_7 ( V_6 ) ;
}
static inline void F_11 ( void )
{
#ifdef F_12
static struct V_10 args ;
int V_11 ;
V_11 = F_13 ( L_2 ) ;
if ( V_11 == V_12 )
return;
F_14 ( & args , V_11 , 3 , 1 , NULL , V_13 , 0 , 0 ) ;
#endif
}
static void F_15 ( void )
{
int V_14 = F_16 () + 0x100 ;
int V_15 = 0 , V_16 ;
long V_17 ;
if ( V_18 == V_14 )
return;
for (; ; ) {
V_15 = F_17 ( & V_18 , 0 , V_14 ) ;
if ( V_15 == 0 )
return;
V_17 = 10000 ;
while ( V_18 == V_15 ) {
if ( -- V_17 > 0 ) {
F_18 ( 100 ) ;
continue;
}
V_16 = F_17 ( & V_18 , V_15 , V_14 ) ;
if ( V_16 == V_15 )
return;
break;
}
}
}
static void F_19 ( void )
{
V_18 = 0 ;
}
int F_20 ( void )
{
return ! F_21 ( & V_19 ) ;
}
static bool F_22 ( int V_20 )
{
unsigned long V_17 ;
for ( V_17 = 20000 ; V_17 != 0 ; -- V_17 ) {
if ( F_23 ( & V_19 ) >= V_20 )
return true ;
F_18 ( 100 ) ;
F_24 () ;
}
return false ;
}
static inline int F_25 ( struct V_21 * V_22 )
{
#if F_26 ( V_23 ) || F_26 ( V_24 )
return 0 ;
#else
return ( ( V_22 -> V_25 & V_26 ) == 0 ) ;
#endif
}
static int F_27 ( struct V_21 * V_22 , int V_27 )
{
int V_28 = 0 ;
struct V_29 * V_30 ;
long V_31 [ V_32 ] ;
unsigned long V_33 ;
unsigned long V_34 ;
#ifdef F_28
int V_35 ;
int V_36 ;
#endif
F_29 ( V_34 ) ;
F_30 () ;
V_37 = F_31 () ;
F_32 () ;
V_30 = F_33 ( V_22 -> V_38 , & V_33 ) ;
if ( V_30 != NULL ) {
V_22 -> V_38 = V_30 -> V_39 + V_33 ;
F_34 ( & V_30 -> V_40 ) ;
}
F_35 () ;
#ifdef F_28
V_35 = F_16 () ;
if ( F_36 ( V_35 , & V_19 ) ) {
if ( V_41 )
longjmp ( V_42 , 1 ) ;
F_15 () ;
F_37 ( V_22 ) ;
printf ( L_3
L_4 ,
V_35 , V_22 -> V_43 , F_38 ( F_39 ( V_22 ) ) ) ;
F_19 () ;
longjmp ( V_44 [ V_35 ] , 1 ) ;
}
if ( setjmp ( V_31 ) != 0 ) {
if ( ! V_45 || ! V_46 ) {
F_15 () ;
printf ( L_5
L_6 , V_35 ) ;
F_19 () ;
goto V_47;
}
V_36 = ! ( V_48 && V_35 == V_49 ) ;
goto V_50;
}
V_44 [ V_35 ] = V_31 ;
V_30 = NULL ;
if ( ( V_22 -> V_25 & ( V_51 | V_52 | V_53 ) ) == ( V_51 | V_53 ) )
V_30 = F_40 ( V_22 -> V_38 ) ;
if ( V_30 || F_25 ( V_22 ) )
V_27 = 0 ;
if ( ! V_27 ) {
F_15 () ;
F_37 ( V_22 ) ;
if ( V_30 ) {
printf ( L_7 ,
V_35 , F_41 ( V_30 ) ) ;
F_42 ( V_22 -> V_38 , L_8 , L_9 ) ;
}
if ( F_25 ( V_22 ) )
printf ( L_10
L_11 ) ;
F_19 () ;
}
F_43 ( V_35 , & V_19 ) ;
V_47:
V_36 = 1 ;
while ( V_36 && ! V_46 ) {
if ( V_45 == 0 ) {
if ( V_27 )
goto V_54;
V_36 = F_44 ( 0 , & V_45 ) ;
}
F_24 () ;
}
if ( ! V_36 && ! V_46 ) {
int V_20 = F_45 () ;
V_49 = V_35 ;
F_46 () ;
if ( V_20 > 1 ) {
if ( F_39 ( V_22 ) != 0x100 || ! F_22 ( V_20 ) )
F_47 () ;
F_22 ( V_20 ) ;
}
F_48 () ;
F_11 () ;
if ( V_30 || F_39 ( V_22 ) == 0xd00 )
F_49 ( V_22 -> V_38 , 1 , 0 ) ;
printf ( L_12 ) ;
F_46 () ;
V_46 = 1 ;
F_24 () ;
}
V_50:
while ( V_45 ) {
if ( V_36 ) {
if ( V_35 == V_49 ) {
if ( ! F_44 ( 0 , & V_48 ) ) {
V_36 = 0 ;
continue;
}
while ( V_35 == V_49 )
F_24 () ;
}
F_24 () ;
} else {
V_28 = F_50 ( V_22 ) ;
if ( V_28 != 0 ) {
F_51 () ;
V_46 = 0 ;
F_52 () ;
V_45 = 0 ;
break;
}
V_36 = 1 ;
}
}
V_54:
F_53 ( V_35 , & V_19 ) ;
V_44 [ V_35 ] = NULL ;
#else
if ( V_45 ) {
printf ( L_13 ,
V_22 -> V_43 , F_38 ( F_39 ( V_22 ) ) ) ;
longjmp ( V_44 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_31 ) == 0 ) {
V_44 [ 0 ] = V_31 ;
V_45 = 1 ;
F_37 ( V_22 ) ;
V_30 = F_40 ( V_22 -> V_38 ) ;
if ( V_30 ) {
printf ( L_14 , F_41 ( V_30 ) ) ;
F_42 ( V_22 -> V_38 , L_8 , L_9 ) ;
}
if ( F_25 ( V_22 ) )
printf ( L_10
L_11 ) ;
F_48 () ;
F_11 () ;
if ( V_30 || F_39 ( V_22 ) == 0xd00 )
F_49 ( V_22 -> V_38 , 1 , 0 ) ;
printf ( L_12 ) ;
}
V_28 = F_50 ( V_22 ) ;
F_51 () ;
V_45 = 0 ;
#endif
#ifdef F_54
if ( V_22 -> V_25 & V_55 ) {
V_30 = F_40 ( V_22 -> V_38 ) ;
if ( V_30 != NULL ) {
V_22 -> V_38 = ( unsigned long ) & V_30 -> V_56 [ 0 ] ;
F_55 ( & V_30 -> V_40 ) ;
}
}
#else
if ( ( V_22 -> V_25 & ( V_51 | V_52 | V_53 ) ) == ( V_51 | V_53 ) ) {
V_30 = F_40 ( V_22 -> V_38 ) ;
if ( V_30 != NULL ) {
int V_57 = F_56 ( V_22 , V_30 -> V_56 [ 0 ] ) ;
if ( V_57 == 0 ) {
V_22 -> V_38 = ( unsigned long ) & V_30 -> V_56 [ 0 ] ;
F_55 ( & V_30 -> V_40 ) ;
} else if ( V_57 < 0 ) {
printf ( L_15 ,
( F_57 ( V_30 -> V_56 [ 0 ] ) ? L_16 : L_17 ) ) ;
}
}
}
#endif
F_58 () ;
F_59 () ;
F_60 ( V_34 ) ;
return V_28 != 'X' && V_28 != V_58 ;
}
int F_61 ( struct V_21 * V_59 )
{
struct V_21 V_22 ;
if ( V_59 == NULL ) {
F_62 ( & V_22 ) ;
V_59 = & V_22 ;
}
return F_27 ( V_59 , 0 ) ;
}
T_1 F_63 ( int V_60 , void * V_61 )
{
unsigned long V_34 ;
F_29 ( V_34 ) ;
printf ( L_18 ) ;
F_61 ( F_64 () ) ;
F_60 ( V_34 ) ;
return V_62 ;
}
static int F_65 ( struct V_21 * V_22 )
{
struct V_29 * V_30 ;
unsigned long V_33 ;
if ( ( V_22 -> V_25 & ( V_51 | V_52 | V_53 ) ) != ( V_51 | V_53 ) )
return 0 ;
V_30 = F_33 ( V_22 -> V_38 , & V_33 ) ;
if ( V_30 != NULL && V_33 == 4 ) {
V_22 -> V_38 = V_30 -> V_39 + 4 ;
F_34 ( & V_30 -> V_40 ) ;
return 1 ;
}
V_30 = F_40 ( V_22 -> V_38 ) ;
if ( ! V_30 )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_66 ( struct V_21 * V_22 )
{
if ( F_67 ( V_22 ) )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_68 ( struct V_21 * V_22 )
{
if ( ( V_22 -> V_25 & ( V_51 | V_52 | V_53 ) ) != ( V_51 | V_53 ) )
return 0 ;
if ( V_63 . V_64 == 0 )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_69 ( struct V_21 * V_22 )
{
if ( ( V_22 -> V_25 & ( V_51 | V_52 | V_53 ) ) != ( V_51 | V_53 ) )
return 0 ;
if ( V_65 == NULL )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_70 ( struct V_21 * V_22 )
{
#ifdef F_28
if ( V_45 && ! F_36 ( F_16 () , & V_19 ) )
F_27 ( V_22 , 1 ) ;
#endif
return 0 ;
}
static int F_71 ( struct V_21 * V_22 )
{
struct V_29 * V_30 ;
unsigned long V_33 ;
if ( V_45 && V_66 )
F_72 ( V_22 ) ;
if ( ( V_22 -> V_25 & ( V_51 | V_52 | V_53 ) ) == ( V_51 | V_53 ) ) {
V_30 = F_33 ( V_22 -> V_38 , & V_33 ) ;
if ( V_30 != NULL ) {
V_22 -> V_38 = V_30 -> V_39 + V_33 ;
F_34 ( & V_30 -> V_40 ) ;
}
}
return 0 ;
}
static struct V_29 * F_40 ( unsigned long V_67 )
{
int V_68 ;
struct V_29 * V_30 ;
V_30 = V_69 ;
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 , ++ V_30 )
if ( V_30 -> V_64 && V_67 == V_30 -> V_39 )
return V_30 ;
return NULL ;
}
static struct V_29 * F_33 ( unsigned long V_38 , unsigned long * V_71 )
{
unsigned long V_72 ;
V_72 = V_38 - ( unsigned long ) V_69 ;
if ( V_72 >= sizeof( V_69 ) )
return NULL ;
V_72 %= sizeof( struct V_29 ) ;
if ( V_72 != F_73 ( struct V_29 , V_56 [ 0 ] )
&& V_72 != F_73 ( struct V_29 , V_56 [ 1 ] ) )
return NULL ;
* V_71 = V_72 - F_73 ( struct V_29 , V_56 [ 0 ] ) ;
return (struct V_29 * ) ( V_38 - V_72 ) ;
}
static struct V_29 * F_74 ( unsigned long V_73 )
{
struct V_29 * V_30 ;
V_73 &= ~ 3UL ;
V_30 = F_40 ( V_73 ) ;
if ( V_30 )
return V_30 ;
for ( V_30 = V_69 ; V_30 < & V_69 [ V_70 ] ; ++ V_30 ) {
if ( ! V_30 -> V_64 && F_75 ( & V_30 -> V_40 ) == 0 ) {
V_30 -> V_39 = V_73 ;
V_30 -> V_56 [ 1 ] = V_74 ;
F_4 ( & V_30 -> V_56 [ 1 ] ) ;
return V_30 ;
}
}
printf ( L_19 ) ;
return NULL ;
}
static void F_51 ( void )
{
int V_68 ;
struct V_29 * V_30 ;
V_30 = V_69 ;
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 , ++ V_30 ) {
if ( ( V_30 -> V_64 & ( V_75 | V_76 ) ) == 0 )
continue;
if ( F_76 ( V_30 -> V_39 , & V_30 -> V_56 [ 0 ] , 4 ) != 4 ) {
printf ( L_20
L_21 , V_30 -> V_39 ) ;
V_30 -> V_64 = 0 ;
continue;
}
if ( F_77 ( V_30 -> V_56 [ 0 ] ) || F_57 ( V_30 -> V_56 [ 0 ] ) ) {
printf ( L_22
L_23 , V_30 -> V_39 ) ;
V_30 -> V_64 = 0 ;
continue;
}
F_4 ( & V_30 -> V_56 [ 0 ] ) ;
if ( V_30 -> V_64 & V_76 )
continue;
if ( F_78 ( ( unsigned int * ) V_30 -> V_39 ,
V_74 ) != 0 ) {
printf ( L_24
L_21 , V_30 -> V_39 ) ;
V_30 -> V_64 &= ~ V_75 ;
continue;
}
F_4 ( ( void * ) V_30 -> V_39 ) ;
}
}
static void F_58 ( void )
{
struct V_77 V_78 ;
if ( V_63 . V_64 ) {
V_78 . V_39 = V_63 . V_39 ;
V_78 . type = ( V_63 . V_64 & V_79 ) | V_80 ;
V_78 . V_81 = 8 ;
F_79 ( & V_78 ) ;
}
if ( V_65 )
F_10 ( V_65 -> V_39 ) ;
}
static void F_48 ( void )
{
int V_68 ;
struct V_29 * V_30 ;
unsigned V_56 ;
V_30 = V_69 ;
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 , ++ V_30 ) {
if ( ( V_30 -> V_64 & ( V_75 | V_76 ) ) != V_75 )
continue;
if ( F_76 ( V_30 -> V_39 , & V_56 , 4 ) == 4
&& V_56 == V_74
&& F_78 (
( unsigned int * ) V_30 -> V_39 , V_30 -> V_56 [ 0 ] ) != 0 )
printf ( L_25 ,
V_30 -> V_39 ) ;
else
F_4 ( ( void * ) V_30 -> V_39 ) ;
}
}
static void F_35 ( void )
{
F_80 () ;
F_7 ( 0 ) ;
}
static void F_81 ( void )
{
unsigned long V_82 ;
if ( ! F_82 ( & V_82 ) ) {
printf ( L_26 ) ;
V_82 = 0 ;
}
F_83 ( V_82 ) ;
}
static int
F_50 ( struct V_21 * V_59 )
{
int V_28 = 0 ;
V_83 = NULL ;
V_84 = V_59 ;
F_84 ( V_59 -> V_85 [ 1 ] , V_59 -> V_86 , V_59 -> V_38 ) ;
for(; ; ) {
#ifdef F_28
printf ( L_27 , F_16 () ) ;
#endif
printf ( L_28 ) ;
F_85 () ;
V_87 = 0 ;
V_28 = F_86 () ;
if( V_28 == '\n' ) {
if ( V_83 == NULL )
continue;
F_87 ( V_83 ) ;
V_83 = NULL ;
V_28 = F_88 () ;
}
switch ( V_28 ) {
case 'm' :
V_28 = F_88 () ;
switch ( V_28 ) {
case 'm' :
case 's' :
case 'd' :
F_89 ( V_28 ) ;
break;
case 'l' :
F_90 () ;
break;
case 'z' :
F_91 () ;
break;
case 'i' :
F_92 ( 0 , NULL ) ;
break;
default:
V_87 = V_28 ;
F_93 () ;
}
break;
case 'd' :
F_94 () ;
break;
case 'l' :
F_95 () ;
break;
case 'r' :
F_96 ( V_59 ) ;
break;
case 'e' :
F_37 ( V_59 ) ;
break;
case 'S' :
F_97 () ;
break;
case 't' :
F_98 ( V_59 ) ;
break;
case 'f' :
F_99 () ;
break;
case 's' :
if ( F_100 () == 0 )
break;
if ( F_101 ( V_59 ) )
return V_28 ;
break;
case 'x' :
case 'X' :
if ( V_37 )
F_102 () ;
return V_28 ;
case V_58 :
printf ( L_29 ) ;
F_103 ( 2000 ) ;
return V_28 ;
case '?' :
F_104 ( V_88 ) ;
break;
case '#' :
F_81 () ;
break;
case 'b' :
F_105 () ;
break;
case 'C' :
F_106 () ;
break;
case 'c' :
if ( F_107 () )
return 0 ;
break;
case 'z' :
F_108 () ;
break;
case 'p' :
F_109 () ;
break;
case 'P' :
F_110 () ;
break;
#ifdef F_111
case 'u' :
F_112 () ;
break;
#elif F_26 ( V_89 )
case 'u' :
F_113 () ;
break;
#elif F_26 ( V_24 )
case 'u' :
F_114 () ;
break;
#endif
default:
printf ( L_30 ) ;
do {
if ( ' ' < V_28 && V_28 <= '~' )
putchar ( V_28 ) ;
else
printf ( L_31 , V_28 ) ;
V_28 = F_88 () ;
} while ( V_28 != '\n' );
printf ( L_32 ) ;
break;
}
}
}
static int F_101 ( struct V_21 * V_22 )
{
V_22 -> V_25 |= V_55 ;
F_9 ( V_90 , F_115 ( V_90 ) | V_91 | V_92 ) ;
return 1 ;
}
static int F_101 ( struct V_21 * V_22 )
{
unsigned int V_56 ;
int V_57 ;
if ( ( V_22 -> V_25 & ( V_53 | V_52 | V_51 ) ) == ( V_53 | V_51 ) ) {
if ( F_76 ( V_22 -> V_38 , & V_56 , 4 ) == 4 ) {
V_57 = F_56 ( V_22 , V_56 ) ;
if ( V_57 < 0 ) {
printf ( L_15 ,
( F_57 ( V_56 ) ? L_16 : L_17 ) ) ;
return 0 ;
}
if ( V_57 > 0 ) {
V_22 -> V_43 = 0xd00 | ( V_22 -> V_43 & 1 ) ;
printf ( L_33 ) ;
F_42 ( V_22 -> V_38 , L_8 , L_34 ) ;
F_49 ( V_22 -> V_38 , 1 , 0 ) ;
return 0 ;
}
}
}
V_22 -> V_25 |= V_93 ;
return 1 ;
}
static void F_108 ( void )
{
int V_28 ;
V_28 = F_88 () ;
if ( V_28 == 'r' )
V_94 . V_95 ( NULL ) ;
else if ( V_28 == 'h' )
V_94 . V_96 () ;
else if ( V_28 == 'p' )
if ( V_97 )
V_97 () ;
}
static int F_107 ( void )
{
#ifdef F_28
unsigned long V_35 , V_98 , V_99 ;
int V_17 ;
if ( ! F_82 ( & V_35 ) ) {
printf ( L_35 ) ;
V_99 = V_98 = V_100 ;
F_116 (cpu) {
if ( F_36 ( V_35 , & V_19 ) ) {
if ( V_35 == V_99 + 1 ) {
V_99 = V_35 ;
} else {
if ( V_99 != V_98 )
printf ( L_36 , V_99 ) ;
V_99 = V_98 = V_35 ;
printf ( L_37 , V_35 ) ;
}
}
}
if ( V_99 != V_98 )
printf ( L_36 , V_99 ) ;
printf ( L_34 ) ;
return 0 ;
}
if ( ! F_36 ( V_35 , & V_19 ) ) {
printf ( L_38 , V_35 ) ;
return 0 ;
}
V_48 = 0 ;
F_46 () ;
V_49 = V_35 ;
V_17 = 10000000 ;
while ( ! V_48 ) {
if ( -- V_17 == 0 ) {
if ( F_44 ( 0 , & V_48 ) )
break;
F_46 () ;
V_49 = F_16 () ;
printf ( L_39 , V_35 ) ;
return 0 ;
}
F_24 () ;
}
return 1 ;
#else
return 0 ;
#endif
}
static void
F_106 ( void )
{
unsigned int V_68 ;
unsigned short V_101 ;
unsigned char V_102 ;
if ( ! F_82 ( & V_103 ) )
return;
if ( ! F_82 ( & V_104 ) )
return;
V_101 = 0xffff ;
for ( V_68 = 0 ; V_68 < V_104 ; ++ V_68 ) {
if ( F_76 ( V_103 + V_68 , & V_102 , 1 ) == 0 ) {
printf ( L_40 V_105 L_34 , V_103 + V_68 ) ;
break;
}
V_101 = F_117 ( V_101 , V_102 ) ;
}
printf ( L_41 , V_101 ) ;
}
static long F_118 ( unsigned long V_6 )
{
unsigned int V_56 ;
V_6 &= ~ 3 ;
if ( ! F_119 ( V_6 ) ) {
printf ( L_42 ) ;
return 0 ;
}
if ( ! F_76 ( V_6 , & V_56 , sizeof( V_56 ) ) ) {
printf ( L_43 , V_6 ) ;
return 0 ;
}
if ( F_77 ( V_56 ) || F_57 ( V_56 ) ) {
printf ( L_44
L_45 ) ;
return 0 ;
}
return 1 ;
}
static void
F_105 ( void )
{
int V_28 ;
unsigned long V_73 ;
int V_68 ;
struct V_29 * V_30 ;
V_28 = F_88 () ;
switch ( V_28 ) {
#ifndef F_120
static const char V_106 [] = L_46 ;
int V_107 ;
case 'd' :
V_107 = 7 ;
V_28 = F_88 () ;
if ( V_28 == 'r' )
V_107 = 5 ;
else if ( V_28 == 'w' )
V_107 = 6 ;
else
V_87 = V_28 ;
V_63 . V_39 = 0 ;
V_63 . V_64 = 0 ;
if ( F_82 ( & V_63 . V_39 ) ) {
if ( ! F_119 ( V_63 . V_39 ) ) {
printf ( V_106 ) ;
break;
}
V_63 . V_39 &= ~ V_79 ;
V_63 . V_64 = V_107 | V_108 ;
}
break;
case 'i' :
if ( ! F_8 ( V_3 ) ) {
printf ( L_47
L_48 ) ;
break;
}
if ( V_65 ) {
V_65 -> V_64 &= ~ V_76 ;
V_65 = NULL ;
}
if ( ! F_82 ( & V_73 ) )
break;
if ( ! F_118 ( V_73 ) )
break;
V_30 = F_74 ( V_73 ) ;
if ( V_30 != NULL ) {
V_30 -> V_64 |= V_76 ;
V_65 = V_30 ;
}
break;
#endif
case 'c' :
if ( ! F_82 ( & V_73 ) ) {
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 )
V_69 [ V_68 ] . V_64 = 0 ;
V_65 = NULL ;
V_63 . V_64 = 0 ;
printf ( L_49 ) ;
break;
}
if ( V_73 <= V_70 && V_73 >= 1 ) {
V_30 = & V_69 [ V_73 - 1 ] ;
} else {
V_30 = F_40 ( V_73 ) ;
if ( V_30 == NULL ) {
printf ( L_50 , V_73 ) ;
break;
}
}
printf ( L_51 , F_41 ( V_30 ) ) ;
F_42 ( V_30 -> V_39 , L_8 , L_9 ) ;
V_30 -> V_64 = 0 ;
break;
default:
V_87 = V_28 ;
V_28 = F_86 () ;
if ( V_28 == '?' ) {
printf ( V_109 ) ;
break;
}
V_87 = V_28 ;
if ( ! F_82 ( & V_73 ) ) {
printf ( L_52 ) ;
if ( V_63 . V_64 ) {
printf ( L_53 V_105 L_54 , V_63 . V_39 ) ;
if ( V_63 . V_64 & 1 )
printf ( L_55 ) ;
if ( V_63 . V_64 & 2 )
printf ( L_56 ) ;
printf ( L_57 ) ;
}
for ( V_30 = V_69 ; V_30 < & V_69 [ V_70 ] ; ++ V_30 ) {
if ( ! V_30 -> V_64 )
continue;
printf ( L_58 , F_41 ( V_30 ) ,
( V_30 -> V_64 & V_76 ) ? L_59 : L_60 ) ;
F_42 ( V_30 -> V_39 , L_61 , L_34 ) ;
}
break;
}
if ( ! F_118 ( V_73 ) )
break;
V_30 = F_74 ( V_73 ) ;
if ( V_30 != NULL )
V_30 -> V_64 |= V_75 ;
break;
}
}
static
const char * F_38 ( unsigned long V_110 )
{
char * V_111 ;
switch ( V_110 ) {
case 0x100 : V_111 = L_62 ; break;
case 0x200 : V_111 = L_63 ; break;
case 0x300 : V_111 = L_64 ; break;
case 0x380 :
if ( F_121 () )
V_111 = L_65 ;
else
V_111 = L_66 ;
break;
case 0x400 : V_111 = L_67 ; break;
case 0x480 :
if ( F_121 () )
V_111 = L_68 ;
else
V_111 = L_69 ;
break;
case 0x500 : V_111 = L_70 ; break;
case 0x600 : V_111 = L_71 ; break;
case 0x700 : V_111 = L_72 ; break;
case 0x800 : V_111 = L_73 ; break;
case 0x900 : V_111 = L_74 ; break;
case 0x980 : V_111 = L_75 ; break;
case 0xa00 : V_111 = L_76 ; break;
case 0xc00 : V_111 = L_77 ; break;
case 0xd00 : V_111 = L_78 ; break;
case 0xe40 : V_111 = L_79 ; break;
case 0xe60 : V_111 = L_80 ; break;
case 0xe80 : V_111 = L_81 ; break;
case 0xf00 : V_111 = L_82 ; break;
case 0xf20 : V_111 = L_83 ; break;
case 0x1300 : V_111 = L_84 ; break;
case 0x1500 : V_111 = L_85 ; break;
case 0x1700 : V_111 = L_86 ; break;
default: V_111 = L_87 ;
}
return V_111 ;
}
static void F_122 ( unsigned long V_67 , unsigned long * V_112 ,
unsigned long * V_113 )
{
unsigned long V_114 , V_33 ;
const char * V_115 ;
* V_112 = * V_113 = 0 ;
if ( V_67 == 0 )
return;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_115 = F_123 ( V_67 , & V_114 , & V_33 , NULL , V_116 ) ;
if ( V_115 != NULL ) {
* V_112 = V_67 - V_33 ;
* V_113 = V_67 - V_33 + V_114 ;
}
F_3 () ;
}
V_66 = 0 ;
}
static void F_84 ( unsigned long V_117 , unsigned long V_118 ,
unsigned long V_67 )
{
int V_119 = 64 ;
unsigned long V_120 ;
unsigned long V_121 ;
unsigned long V_122 ;
struct V_21 V_22 ;
while ( V_119 -- ) {
if ( ! F_119 ( V_117 ) ) {
if ( V_117 != 0 )
printf ( L_88 , V_117 ) ;
break;
}
if ( ! F_76 ( V_117 + V_123 , & V_120 , sizeof( unsigned long ) )
|| ! F_76 ( V_117 , & V_121 , sizeof( unsigned long ) ) ) {
printf ( L_89 , V_117 ) ;
break;
}
if ( ( V_67 | V_118 ) != 0 ) {
unsigned long V_124 , V_125 ;
unsigned long V_126 ;
int V_127 = 1 ;
F_122 ( V_67 , & V_124 , & V_125 ) ;
V_126 = 0 ;
if ( V_121 > V_117 )
F_76 ( V_121 + V_123 , & V_126 ,
sizeof( unsigned long ) ) ;
if ( V_118 == V_120 ) {
if ( ! F_119 ( V_118 )
|| ( V_124 <= V_118 && V_118 < V_125 ) )
V_127 = 0 ;
} else if ( V_118 == V_126 ) {
V_127 = 0 ;
} else if ( F_119 ( V_118 )
&& ! ( V_124 <= V_118 && V_118 < V_125 ) ) {
printf ( L_90 ) ;
F_42 ( V_118 , L_8 , L_34 ) ;
}
if ( V_127 ) {
printf ( L_91 V_105 L_92 , V_117 ) ;
F_42 ( V_120 , L_8 , L_93 ) ;
}
V_67 = V_118 = 0 ;
} else {
printf ( L_91 V_105 L_92 , V_117 ) ;
F_42 ( V_120 , L_8 , L_34 ) ;
}
if ( F_76 ( V_117 + V_128 , & V_122 , sizeof( unsigned long ) )
&& V_122 == V_129 ) {
if ( F_76 ( V_117 + V_130 , & V_22 , sizeof( V_22 ) )
!= sizeof( V_22 ) ) {
printf ( L_94 ,
V_117 + V_130 ) ;
break;
}
printf ( L_95 , V_22 . V_43 ,
F_38 ( F_39 ( & V_22 ) ) ) ;
V_67 = V_22 . V_38 ;
V_118 = V_22 . V_86 ;
F_42 ( V_67 , L_8 , L_34 ) ;
}
if ( V_121 == 0 )
break;
V_117 = V_121 ;
}
}
static void F_98 ( struct V_21 * V_59 )
{
unsigned long V_117 ;
if ( F_82 ( & V_117 ) )
F_84 ( V_117 , 0 , 0 ) ;
else
F_84 ( V_59 -> V_85 [ 1 ] , V_59 -> V_86 , V_59 -> V_38 ) ;
F_124 () ;
}
static void F_125 ( struct V_21 * V_22 )
{
#ifdef F_126
const struct V_131 * V_132 ;
unsigned long V_6 ;
if ( V_22 -> V_25 & V_52 )
return;
V_6 = V_22 -> V_38 ;
if ( ! F_119 ( V_6 ) )
return;
V_132 = F_127 ( V_22 -> V_38 ) ;
if ( V_132 == NULL )
return;
if ( F_128 ( V_132 ) )
return;
#ifdef F_129
printf ( L_96 ,
V_132 -> V_133 , V_132 -> line ) ;
#else
printf ( L_97 , ( void * ) V_132 -> V_134 ) ;
#endif
#endif
}
static void F_37 ( struct V_21 * V_135 )
{
unsigned long V_43 ;
#ifdef F_28
printf ( L_98 , F_16 () ) ;
#endif
V_43 = F_39 ( V_135 ) ;
printf ( L_99 , V_135 -> V_43 , F_38 ( V_43 ) , V_135 ) ;
printf ( L_100 ) ;
F_42 ( V_135 -> V_38 , L_101 , L_34 ) ;
printf ( L_102 , V_135 -> V_86 ) ;
F_42 ( V_135 -> V_86 , L_101 , L_34 ) ;
printf ( L_103 , V_135 -> V_85 [ 1 ] ) ;
printf ( L_104 , V_135 -> V_25 ) ;
if ( V_43 == 0x300 || V_43 == 0x380 || V_43 == 0x600 || V_43 == 0x200 ) {
printf ( L_105 , V_135 -> V_136 ) ;
if ( V_43 != 0x380 )
printf ( L_106 , V_135 -> V_137 ) ;
}
printf ( L_107 , V_138 ) ;
#ifdef F_130
printf ( L_108 ,
V_139 , V_139 -> V_140 , V_139 -> V_141 ) ;
#endif
if ( V_138 ) {
printf ( L_109 ,
V_138 -> V_142 , V_138 -> V_143 ) ;
}
if ( V_43 == 0x700 )
F_125 ( V_135 ) ;
printf ( V_144 ) ;
}
static void F_96 ( struct V_21 * V_135 )
{
int V_145 , V_43 ;
unsigned long V_146 ;
struct V_21 V_22 ;
if ( F_82 ( & V_146 ) ) {
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_22 = * (struct V_21 * ) V_146 ;
F_3 () ;
F_131 ( 200 ) ;
} else {
V_66 = 0 ;
printf ( L_110 V_105 L_34 ,
V_146 ) ;
return;
}
V_66 = 0 ;
V_135 = & V_22 ;
}
#ifdef F_130
if ( F_132 ( V_135 ) ) {
for ( V_145 = 0 ; V_145 < 16 ; ++ V_145 )
printf ( L_111 V_105 L_112 V_105 L_34 ,
V_145 , V_135 -> V_85 [ V_145 ] , V_145 + 16 , V_135 -> V_85 [ V_145 + 16 ] ) ;
} else {
for ( V_145 = 0 ; V_145 < 7 ; ++ V_145 )
printf ( L_111 V_105 L_112 V_105 L_34 ,
V_145 , V_135 -> V_85 [ V_145 ] , V_145 + 7 , V_135 -> V_85 [ V_145 + 7 ] ) ;
}
#else
for ( V_145 = 0 ; V_145 < 32 ; ++ V_145 ) {
printf ( L_113 , V_145 , V_135 -> V_85 [ V_145 ] ,
( V_145 & 3 ) == 3 ? L_34 : L_114 ) ;
if ( V_145 == 12 && ! F_132 ( V_135 ) ) {
printf ( L_34 ) ;
break;
}
}
#endif
printf ( L_115 ) ;
F_42 ( V_135 -> V_38 , L_8 , L_34 ) ;
if ( F_39 ( V_135 ) != 0xc00 && F_8 ( V_147 ) ) {
printf ( L_116 ) ;
F_42 ( V_135 -> V_148 , L_8 , L_34 ) ;
}
printf ( L_117 ) ;
F_42 ( V_135 -> V_86 , L_8 , L_34 ) ;
printf ( L_118 V_105 L_119 , V_135 -> V_25 , V_135 -> V_149 ) ;
printf ( L_120 V_105 L_121 V_105 L_122 ,
V_135 -> V_150 , V_135 -> V_151 , V_135 -> V_43 ) ;
V_43 = F_39 ( V_135 ) ;
if ( V_43 == 0x300 || V_43 == 0x380 || V_43 == 0x600 )
printf ( L_123 V_105 L_124 , V_135 -> V_136 , V_135 -> V_137 ) ;
}
static void F_99 ( void )
{
int V_28 ;
unsigned long V_152 ;
V_28 = F_88 () ;
if ( V_28 != 'i' )
V_87 = V_28 ;
F_82 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
V_152 = 1 ;
F_82 ( & V_152 ) ;
V_152 = ( V_152 + V_153 - 1 ) / V_153 ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
if ( V_28 != 'i' ) {
for (; V_152 > 0 ; -- V_152 , V_103 += V_153 )
F_5 ( ( void * ) V_103 ) ;
} else {
for (; V_152 > 0 ; -- V_152 , V_103 += V_153 )
F_6 ( ( void * ) V_103 ) ;
}
F_3 () ;
F_131 ( 200 ) ;
}
V_66 = 0 ;
}
static int
F_133 ( int V_145 , unsigned long * V_154 )
{
unsigned long V_111 = - 1UL ;
int V_155 = 0 ;
if ( setjmp ( V_42 ) == 0 ) {
V_41 = 1 ;
F_3 () ;
V_111 = F_134 ( V_145 , * V_154 ) ;
F_3 () ;
* V_154 = V_111 ;
V_155 = 1 ;
}
V_41 = 0 ;
return V_155 ;
}
static void
F_135 ( int V_145 , unsigned long V_156 )
{
if ( setjmp ( V_42 ) == 0 ) {
V_41 = 1 ;
F_3 () ;
F_136 ( V_145 , V_156 ) ;
F_3 () ;
} else {
printf ( L_125 , V_145 , V_145 ) ;
}
V_41 = 0 ;
}
static void F_137 ( void )
{
#ifdef F_130
if ( ! F_8 ( V_157 ) )
return;
printf ( L_126 ,
F_115 ( V_158 ) , F_115 ( V_159 ) , F_115 ( V_160 ) ) ;
printf ( L_127 ,
F_115 ( V_161 ) , F_115 ( V_162 ) , F_115 ( V_163 ) ) ;
printf ( L_128 ,
F_115 ( V_164 ) , F_115 ( V_165 ) ) ;
if ( ! ( F_138 () & V_166 ) )
return;
printf ( L_129 ,
F_115 ( V_167 ) , F_115 ( V_168 ) , F_115 ( V_169 ) ) ;
printf ( L_130 ,
F_115 ( V_170 ) , F_115 ( V_171 ) , F_115 ( V_172 ) ) ;
printf ( L_131 ,
F_115 ( V_173 ) , F_115 ( V_174 ) , F_115 ( V_175 ) ) ;
printf ( L_132 ,
F_115 ( V_176 ) , F_115 ( V_177 ) , F_115 ( V_178 ) ) ;
printf ( L_133 ,
F_115 ( V_179 ) , F_115 ( V_180 ) ) ;
#endif
}
static void F_139 ( void )
{
#ifdef F_130
unsigned long V_25 ;
if ( ! F_8 ( V_3 ) )
return;
printf ( L_134 ,
F_115 ( V_181 ) , F_115 ( V_182 ) , F_115 ( V_183 ) ) ;
printf ( L_135 ,
F_115 ( V_184 ) , F_115 ( V_185 ) , F_115 ( V_186 ) ) ;
V_25 = F_138 () ;
if ( V_25 & V_187 ) {
printf ( L_136 ,
F_115 ( V_188 ) , F_115 ( V_189 ) ,
F_115 ( V_190 ) ) ;
}
printf ( L_137 ,
F_115 ( V_191 ) , F_115 ( V_192 ) , F_115 ( V_193 ) ) ;
printf ( L_138 ,
F_115 ( V_194 ) , F_115 ( V_195 ) ,
F_115 ( V_196 ) , F_115 ( V_197 ) ) ;
printf ( L_139 ,
F_115 ( V_198 ) , F_115 ( V_199 ) , F_115 ( V_200 ) ) ;
printf ( L_140 ,
F_115 ( V_201 ) , F_115 ( V_202 ) , F_115 ( V_203 ) ) ;
printf ( L_141 ,
F_115 ( V_204 ) , F_115 ( V_205 ) , F_115 ( V_206 ) ) ;
printf ( L_142 , F_115 ( V_207 ) ) ;
if ( ! ( V_25 & V_166 ) )
return;
printf ( L_143 ,
F_115 ( V_208 ) , F_115 ( V_209 ) , F_115 ( V_210 ) ) ;
printf ( L_144 ,
F_115 ( V_211 ) , F_115 ( V_212 ) , F_115 ( V_5 ) ) ;
#endif
}
static void F_140 ( void )
{
#ifdef F_130
bool V_213 = F_138 () & V_166 ;
if ( ! F_8 ( V_214 ) )
return;
printf ( L_145 ,
F_115 ( V_215 ) , F_115 ( V_216 ) ) ;
printf ( L_146 ,
F_115 ( V_217 ) , V_213 ? F_115 ( V_218 )
: F_115 ( V_219 ) ) ;
if ( ! V_213 )
return;
printf ( L_147 ,
F_115 ( V_220 ) ) ;
#endif
}
static void F_141 ( int V_221 , bool V_222 )
{
unsigned long V_156 ;
V_156 = 0xdeadbeef ;
if ( ! F_133 ( V_221 , & V_156 ) ) {
printf ( L_148 , V_221 , V_221 ) ;
return;
}
if ( V_156 == 0xdeadbeef ) {
V_156 = 0x0badcafe ;
if ( ! F_133 ( V_221 , & V_156 ) ) {
printf ( L_148 , V_221 , V_221 ) ;
return;
}
if ( V_156 == 0x0badcafe ) {
if ( V_222 )
printf ( L_149 , V_221 , V_221 ) ;
return;
}
}
printf ( L_150 , V_221 , V_221 , V_156 ) ;
}
static void F_97 ( void )
{
static unsigned long V_223 ;
int V_28 ;
int V_221 ;
V_28 = F_86 () ;
switch ( V_28 ) {
case '\n' : {
unsigned long V_117 , V_224 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_151 V_105 L_152 V_105 L_34 ,
F_138 () , F_115 ( V_225 ) ) ;
printf ( L_153 V_105 L_154 V_105 L_34 ,
F_115 ( V_226 ) , F_115 ( V_227 ) ) ;
printf ( L_155 V_105 L_156 V_105 L_34 ,
F_115 ( V_228 ) , F_115 ( V_229 ) ) ;
printf ( L_157 V_105 L_158 V_105 L_34 , V_117 , F_115 ( V_230 ) ) ;
printf ( L_159 V_105 L_160 V_105 L_34 , V_224 , F_115 ( V_231 ) ) ;
F_137 () ;
F_139 () ;
F_140 () ;
return;
}
case 'w' : {
unsigned long V_156 ;
F_82 ( & V_223 ) ;
V_156 = 0 ;
F_133 ( V_223 , & V_156 ) ;
F_82 ( & V_156 ) ;
F_135 ( V_223 , V_156 ) ;
F_141 ( V_223 , true ) ;
break;
}
case 'r' :
F_82 ( & V_223 ) ;
F_141 ( V_223 , true ) ;
break;
case 'a' :
for ( V_221 = 1 ; V_221 < 1024 ; ++ V_221 )
F_141 ( V_221 , false ) ;
break;
}
F_124 () ;
}
static int
F_76 ( unsigned long V_103 , void * V_232 , int V_114 )
{
volatile int V_145 ;
char * V_2 , * V_233 ;
V_145 = 0 ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_2 = ( char * ) V_103 ;
V_233 = ( char * ) V_232 ;
switch ( V_114 ) {
case 2 :
* ( V_234 * ) V_233 = * ( V_234 * ) V_2 ;
break;
case 4 :
* ( V_235 * ) V_233 = * ( V_235 * ) V_2 ;
break;
case 8 :
* ( V_236 * ) V_233 = * ( V_236 * ) V_2 ;
break;
default:
for( ; V_145 < V_114 ; ++ V_145 ) {
* V_233 ++ = * V_2 ++ ;
F_3 () ;
}
}
F_3 () ;
F_131 ( 200 ) ;
V_145 = V_114 ;
}
V_66 = 0 ;
return V_145 ;
}
static int
F_142 ( unsigned long V_103 , void * V_232 , int V_114 )
{
volatile int V_145 ;
char * V_2 , * V_233 ;
V_145 = 0 ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_2 = ( char * ) V_103 ;
V_233 = ( char * ) V_232 ;
switch ( V_114 ) {
case 2 :
* ( V_234 * ) V_2 = * ( V_234 * ) V_233 ;
break;
case 4 :
* ( V_235 * ) V_2 = * ( V_235 * ) V_233 ;
break;
case 8 :
* ( V_236 * ) V_2 = * ( V_236 * ) V_233 ;
break;
default:
for ( ; V_145 < V_114 ; ++ V_145 ) {
* V_2 ++ = * V_233 ++ ;
F_3 () ;
}
}
F_3 () ;
F_131 ( 200 ) ;
V_145 = V_114 ;
} else {
printf ( L_161 V_105 L_34 , V_103 + V_145 ) ;
}
V_66 = 0 ;
return V_145 ;
}
static int F_72 ( struct V_21 * V_22 )
{
V_237 = F_39 ( V_22 ) ;
switch ( F_39 ( V_22 ) ) {
case 0x200 :
V_238 = 0 ;
break;
case 0x300 :
case 0x380 :
V_238 = 1 ;
break;
default:
V_238 = 2 ;
}
longjmp ( V_42 , 1 ) ;
return 0 ;
}
static void
F_143 ( unsigned char * V_156 , int V_114 )
{
int V_239 ;
switch ( V_114 ) {
case 2 :
F_144 ( V_156 [ 0 ] , V_156 [ 1 ] , V_239 ) ;
break;
case 4 :
F_144 ( V_156 [ 0 ] , V_156 [ 3 ] , V_239 ) ;
F_144 ( V_156 [ 1 ] , V_156 [ 2 ] , V_239 ) ;
break;
case 8 :
F_144 ( V_156 [ 0 ] , V_156 [ 7 ] , V_239 ) ;
F_144 ( V_156 [ 1 ] , V_156 [ 6 ] , V_239 ) ;
F_144 ( V_156 [ 2 ] , V_156 [ 5 ] , V_239 ) ;
F_144 ( V_156 [ 3 ] , V_156 [ 4 ] , V_239 ) ;
break;
}
}
static void
F_93 ( void )
{
int V_28 , V_240 , V_68 , V_241 ;
unsigned long V_145 ;
unsigned char V_156 [ 16 ] ;
F_82 ( ( void * ) & V_103 ) ;
V_28 = F_86 () ;
if ( V_28 == '?' ) {
printf ( V_242 ) ;
return;
} else {
V_87 = V_28 ;
}
V_83 = L_162 ;
while ( ( V_28 = F_86 () ) != '\n' ) {
switch( V_28 ) {
case 'b' : V_114 = 1 ; break;
case 'w' : V_114 = 2 ; break;
case 'l' : V_114 = 4 ; break;
case 'd' : V_114 = 8 ; break;
case 'r' : V_243 = ! V_243 ; break;
case 'n' : V_244 = 1 ; break;
case '.' : V_244 = 0 ; break;
}
}
if( V_114 <= 0 )
V_114 = 1 ;
else if( V_114 > 8 )
V_114 = 8 ;
for(; ; ) {
if ( ! V_244 )
V_145 = F_76 ( V_103 , V_156 , V_114 ) ;
printf ( V_105 L_163 , V_103 , V_243 ? 'r' : ' ' ) ;
if ( ! V_244 ) {
if ( V_243 )
F_143 ( V_156 , V_114 ) ;
putchar ( ' ' ) ;
for ( V_68 = 0 ; V_68 < V_145 ; ++ V_68 )
printf ( L_164 , V_156 [ V_68 ] ) ;
for (; V_68 < V_114 ; ++ V_68 )
printf ( L_165 , V_245 [ V_238 ] ) ;
}
putchar ( ' ' ) ;
V_240 = V_114 ;
V_241 = 0 ;
for(; ; ) {
if( F_82 ( & V_145 ) ) {
for ( V_68 = 0 ; V_68 < V_114 ; ++ V_68 )
V_156 [ V_68 ] = V_145 >> ( V_68 * 8 ) ;
if ( ! V_243 )
F_143 ( V_156 , V_114 ) ;
F_142 ( V_103 , V_156 , V_114 ) ;
V_240 = V_114 ;
}
V_28 = F_86 () ;
if ( V_28 == '\n' )
break;
V_240 = 0 ;
switch ( V_28 ) {
case '\'' :
for(; ; ) {
V_145 = F_88 () ;
if( V_145 == '\\' )
V_145 = F_145 () ;
else if( V_145 == '\'' )
break;
for ( V_68 = 0 ; V_68 < V_114 ; ++ V_68 )
V_156 [ V_68 ] = V_145 >> ( V_68 * 8 ) ;
if ( ! V_243 )
F_143 ( V_156 , V_114 ) ;
F_142 ( V_103 , V_156 , V_114 ) ;
V_103 += V_114 ;
}
V_103 -= V_114 ;
V_240 = V_114 ;
break;
case ',' :
V_103 += V_114 ;
break;
case '.' :
V_244 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_58 :
F_124 () ;
return;
case 'b' :
case 'v' :
V_114 = 1 ;
break;
case 'w' :
V_114 = 2 ;
break;
case 'l' :
V_114 = 4 ;
break;
case 'u' :
V_114 = 8 ;
break;
case '^' :
V_103 -= V_114 ;
break;
case '/' :
if ( V_241 > 0 )
V_103 -= 1 << V_241 ;
else
V_241 = 0 ;
V_241 += 4 ;
V_103 += 1 << V_241 ;
break;
case '\\' :
if ( V_241 < 0 )
V_103 += 1 << - V_241 ;
else
V_241 = 0 ;
V_241 -= 4 ;
V_103 -= 1 << - V_241 ;
break;
case 'm' :
F_82 ( ( void * ) & V_103 ) ;
break;
case 'n' :
V_244 = 1 ;
break;
case 'r' :
V_243 = ! V_243 ;
break;
case '<' :
V_145 = V_114 ;
F_82 ( & V_145 ) ;
V_103 -= V_145 ;
break;
case '>' :
V_145 = V_114 ;
F_82 ( & V_145 ) ;
V_103 += V_145 ;
break;
case '?' :
printf ( V_246 ) ;
break;
}
}
V_103 += V_240 ;
}
}
static int
F_145 ( void )
{
int V_247 ;
V_247 = F_88 () ;
switch( V_247 ) {
case 'n' : V_247 = '\n' ; break;
case 'r' : V_247 = '\r' ; break;
case 'b' : V_247 = '\b' ; break;
case 't' : V_247 = '\t' ; break;
}
return V_247 ;
}
static void F_146 ( unsigned long V_103 , long V_248 )
{
long V_145 , V_249 , V_250 , V_251 ;
unsigned char V_252 [ 16 ] ;
for ( V_145 = V_248 ; V_145 > 0 ; ) {
V_250 = V_145 < 16 ? V_145 : 16 ;
V_251 = F_76 ( V_103 , V_252 , V_250 ) ;
V_103 += V_251 ;
for ( V_249 = 0 ; V_249 < V_250 ; ++ V_249 ) {
if ( V_249 < V_251 )
printf ( L_164 , V_252 [ V_249 ] ) ;
else
printf ( L_165 , V_245 [ V_238 ] ) ;
}
V_145 -= V_250 ;
if ( V_251 < V_250 )
break;
}
printf ( L_34 ) ;
}
static void F_147 ( void )
{
int V_247 ;
V_247 = F_88 () ;
if ( V_247 == 'c' )
F_148 ( V_253 ) ;
else
F_148 ( V_254 ) ;
}
static void F_149 ( int V_35 )
{
struct V_255 * V_2 ;
#ifdef F_150
int V_68 = 0 ;
#endif
if ( setjmp ( V_42 ) != 0 ) {
printf ( L_166 , V_35 ) ;
return;
}
V_66 = 1 ;
F_3 () ;
V_2 = & V_256 [ V_35 ] ;
printf ( L_167 , V_35 , V_2 ) ;
printf ( L_168 , 20 , L_169 , F_151 ( V_35 ) ? L_170 : L_171 ) ;
printf ( L_168 , 20 , L_172 , F_152 ( V_35 ) ? L_170 : L_171 ) ;
printf ( L_168 , 20 , L_173 , F_153 ( V_35 ) ? L_170 : L_171 ) ;
#define F_154 ( V_256 , V_115 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 20, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_154 ( V_2 , V_257 , L_174 ) ;
F_154 ( V_2 , V_258 , L_174 ) ;
F_154 ( V_2 , V_259 , L_175 ) ;
F_154 ( V_2 , V_260 , L_175 ) ;
F_154 ( V_2 , V_261 , L_175 ) ;
F_154 ( V_2 , V_262 , L_176 ) ;
#ifdef F_155
F_154 ( V_2 , V_263 , L_176 ) ;
F_154 ( V_2 , V_264 , L_176 ) ;
F_154 ( V_2 , V_265 , L_174 ) ;
F_154 ( V_2 , V_266 , L_174 ) ;
F_154 ( V_2 , V_267 , L_174 ) ;
#endif
F_154 ( V_2 , V_268 , L_175 ) ;
F_154 ( V_2 , V_269 , L_174 ) ;
F_154 ( V_2 , V_270 , L_174 ) ;
F_154 ( V_2 , V_271 , L_174 ) ;
#ifdef F_150
for ( V_68 = 0 ; V_68 < V_272 ; V_68 ++ ) {
V_236 V_273 , V_274 ;
if ( ! V_2 -> V_275 )
continue;
V_273 = F_156 ( V_2 -> V_275 -> V_276 [ V_68 ] . V_273 ) ;
V_274 = F_156 ( V_2 -> V_275 -> V_276 [ V_68 ] . V_274 ) ;
if ( V_273 || V_274 ) {
printf ( L_177 ,
V_68 , V_273 , V_274 ) ;
}
}
F_154 ( V_2 , V_277 , L_174 ) ;
F_154 ( V_2 , V_278 , L_174 ) ;
for ( V_68 = 0 ; V_68 < V_279 ; V_68 ++ )
printf ( L_178 , V_68 , V_2 -> V_280 [ V_68 ] ) ;
#endif
F_154 ( V_2 , V_281 , L_179 ) ;
#ifdef V_24
F_154 ( V_2 , V_282 , L_176 ) ;
F_154 ( V_2 , V_283 , L_176 ) ;
F_154 ( V_2 , V_284 , L_176 ) ;
F_154 ( V_2 , V_285 , L_176 ) ;
F_154 ( V_2 , V_286 , L_176 ) ;
F_154 ( V_2 , V_287 , L_176 ) ;
#endif
F_154 ( V_2 , V_288 , L_176 ) ;
F_154 ( V_2 , V_289 , L_175 ) ;
F_154 ( V_2 , V_290 , L_175 ) ;
F_154 ( V_2 , V_291 , L_175 ) ;
F_154 ( V_2 , V_292 , L_174 ) ;
F_154 ( V_2 , V_140 , L_174 ) ;
F_154 ( V_2 , V_141 , L_174 ) ;
F_154 ( V_2 , V_293 , L_174 ) ;
F_154 ( V_2 , V_294 , L_174 ) ;
F_154 ( V_2 , V_295 , L_174 ) ;
F_154 ( V_2 , V_296 , L_179 ) ;
#ifdef F_157
F_154 ( V_2 , V_297 , L_179 ) ;
#endif
#ifdef F_158
F_154 ( V_2 , V_298 , L_176 ) ;
F_154 ( V_2 , V_299 , L_174 ) ;
F_154 ( V_2 , V_300 , L_174 ) ;
F_154 ( V_2 , V_301 , L_174 ) ;
#endif
F_154 ( V_2 , V_302 . V_303 , L_179 ) ;
F_154 ( V_2 , V_302 . V_304 , L_179 ) ;
F_154 ( V_2 , V_302 . V_305 , L_179 ) ;
F_154 ( V_2 , V_302 . V_306 , L_179 ) ;
F_154 ( V_2 , V_302 . V_307 , L_179 ) ;
F_154 ( V_2 , V_302 . V_308 , L_179 ) ;
F_154 ( V_2 , V_302 . V_309 , L_179 ) ;
F_154 ( V_2 , V_302 . V_310 , L_179 ) ;
#undef F_154
V_66 = 0 ;
F_3 () ;
}
static void F_159 ( void )
{
int V_35 ;
if ( F_160 () == 0 ) {
printf ( L_180 ) ;
return;
}
F_116 (cpu)
F_149 ( V_35 ) ;
}
static void F_161 ( void )
{
unsigned long V_311 ;
int V_247 ;
V_247 = F_88 () ;
if ( V_247 == 'a' ) {
F_159 () ;
return;
}
V_87 = V_247 ;
if ( F_82 ( & V_311 ) )
F_149 ( V_311 ) ;
else
F_149 ( V_49 ) ;
}
static void F_162 ( int V_35 )
{
unsigned int V_312 = F_163 ( V_35 ) ;
F_164 ( V_313 , V_312 ) ;
F_164 ( V_314 , V_312 ) ;
F_164 ( V_315 , V_312 ) ;
F_164 ( V_316 , V_312 ) ;
F_164 ( V_317 , V_312 ) ;
F_164 ( V_318 , V_312 ) ;
if ( setjmp ( V_42 ) != 0 ) {
V_66 = 0 ;
printf ( L_181 , V_35 ) ;
return;
}
V_66 = 1 ;
F_3 () ;
F_165 ( V_35 ) ;
F_3 () ;
F_131 ( 200 ) ;
V_66 = 0 ;
}
static void F_166 ( void )
{
int V_35 ;
if ( F_160 () == 0 ) {
printf ( L_182 ) ;
return;
}
F_116 (cpu)
F_162 ( V_35 ) ;
}
static void F_167 ( V_235 V_311 )
{
T_3 V_319 ;
T_4 V_154 ;
T_5 V_320 ;
T_6 V_321 ;
V_319 = F_168 ( V_311 , & V_154 , & V_320 , & V_321 ) ;
F_169 ( L_183 ,
V_311 , F_156 ( V_154 ) , V_320 , F_170 ( V_321 ) , V_319 ) ;
}
static void F_171 ( void )
{
unsigned long V_311 ;
int V_247 ;
V_247 = F_88 () ;
if ( V_247 == 'a' ) {
F_166 () ;
return;
} else if ( V_247 == 'i' ) {
if ( F_82 ( & V_311 ) )
F_167 ( V_311 ) ;
return;
}
V_87 = V_247 ;
if ( F_82 ( & V_311 ) )
F_162 ( V_311 ) ;
else
F_162 ( V_49 ) ;
}
static void F_172 ( unsigned long V_6 , long V_322 , int V_114 )
{
unsigned char V_252 [ 16 ] ;
int V_68 , V_323 ;
V_236 V_156 ;
V_322 = F_173 ( V_322 , 16 ) ;
for ( V_68 = 0 ; V_68 < V_322 ; V_68 += 16 , V_6 += 16 ) {
printf ( V_105 , V_6 ) ;
if ( F_76 ( V_6 , V_252 , 16 ) != 16 ) {
printf ( L_184 V_105 L_34 , 16 , V_6 ) ;
return;
}
for ( V_323 = 0 ; V_323 < 16 ; V_323 += V_114 ) {
putchar ( ' ' ) ;
switch ( V_114 ) {
case 1 : V_156 = V_252 [ V_323 ] ; break;
case 2 : V_156 = * ( V_234 * ) & V_252 [ V_323 ] ; break;
case 4 : V_156 = * ( V_235 * ) & V_252 [ V_323 ] ; break;
case 8 : V_156 = * ( V_236 * ) & V_252 [ V_323 ] ; break;
default: V_156 = 0 ;
}
printf ( L_185 , V_114 * 2 , V_156 ) ;
}
printf ( L_34 ) ;
}
}
static void
F_94 ( void )
{
static char V_324 [] = { L_186 } ;
int V_247 ;
V_247 = F_88 () ;
#ifdef F_130
if ( V_247 == 'p' ) {
F_174 () ;
F_161 () ;
F_175 () ;
return;
}
#endif
#ifdef F_158
if ( V_247 == 'x' ) {
F_174 () ;
F_171 () ;
F_175 () ;
return;
}
#endif
if ( V_247 == 't' ) {
F_147 () ;
return;
}
if ( V_247 == '\n' )
V_87 = V_247 ;
F_82 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
if ( V_247 == 'i' ) {
F_82 ( & V_325 ) ;
if ( V_325 == 0 )
V_325 = 16 ;
else if ( V_325 > V_326 )
V_325 = V_326 ;
V_103 += F_49 ( V_103 , V_325 , 1 ) ;
V_83 = L_187 ;
} else if ( V_247 == 'l' ) {
F_176 () ;
} else if ( V_247 == 'o' ) {
F_2 () ;
} else if ( V_247 == 'r' ) {
F_82 ( & V_248 ) ;
if ( V_248 == 0 )
V_248 = 64 ;
F_146 ( V_103 , V_248 ) ;
V_103 += V_248 ;
V_83 = L_188 ;
} else {
F_82 ( & V_248 ) ;
if ( V_248 == 0 )
V_248 = 64 ;
else if ( V_248 > V_326 )
V_248 = V_326 ;
switch ( V_247 ) {
case '8' :
case '4' :
case '2' :
case '1' :
V_248 = F_173 ( V_248 , 16 ) ;
F_172 ( V_103 , V_248 , V_247 - '0' ) ;
V_324 [ 1 ] = V_247 ;
V_83 = V_324 ;
break;
default:
F_177 ( V_103 , V_248 ) ;
V_83 = L_189 ;
}
V_103 += V_248 ;
}
}
static void
F_177 ( unsigned long V_103 , long V_248 )
{
long V_145 , V_249 , V_247 , V_250 , V_251 ;
unsigned char V_252 [ 16 ] ;
for ( V_145 = V_248 ; V_145 > 0 ; ) {
printf ( V_105 , V_103 ) ;
putchar ( ' ' ) ;
V_250 = V_145 < 16 ? V_145 : 16 ;
V_251 = F_76 ( V_103 , V_252 , V_250 ) ;
V_103 += V_251 ;
for ( V_249 = 0 ; V_249 < V_250 ; ++ V_249 ) {
if ( ( V_249 & ( sizeof( long ) - 1 ) ) == 0 && V_249 > 0 )
putchar ( ' ' ) ;
if ( V_249 < V_251 )
printf ( L_164 , V_252 [ V_249 ] ) ;
else
printf ( L_165 , V_245 [ V_238 ] ) ;
}
for (; V_249 < 16 ; ++ V_249 ) {
if ( ( V_249 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_61 ) ;
}
printf ( L_190 ) ;
for ( V_249 = 0 ; V_249 < V_250 ; ++ V_249 ) {
if ( V_249 < V_251 ) {
V_247 = V_252 [ V_249 ] ;
putchar ( ' ' <= V_247 && V_247 <= '~' ? V_247 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_145 -= V_250 ;
for (; V_249 < 16 ; ++ V_249 )
putchar ( ' ' ) ;
printf ( L_191 ) ;
if ( V_251 < V_250 )
break;
}
}
static int
F_178 ( unsigned long V_327 , long V_322 , int V_328 ,
T_7 V_329 )
{
int V_251 , V_330 ;
unsigned long V_331 ;
unsigned long V_332 , V_333 = 0 ;
unsigned char V_156 [ 4 ] ;
V_330 = 0 ;
for ( V_331 = V_327 ; V_322 > 0 ; -- V_322 , V_327 += 4 ) {
V_251 = F_76 ( V_327 , V_156 , 4 ) ;
if ( V_251 == 0 ) {
if ( V_328 ) {
const char * V_334 = V_245 [ V_238 ] ;
printf ( V_105 L_192 , V_327 , V_334 , V_334 , V_334 , V_334 ) ;
}
break;
}
V_332 = F_179 ( V_156 ) ;
if ( V_327 > V_331 && V_332 == V_333 ) {
if ( ! V_330 ) {
printf ( L_193 ) ;
V_330 = 1 ;
}
continue;
}
V_330 = 0 ;
V_333 = V_332 ;
if ( V_328 )
printf ( V_105 L_194 , V_327 , V_332 ) ;
printf ( L_195 ) ;
V_329 ( V_332 , V_327 ) ;
printf ( L_34 ) ;
}
return V_327 - V_331 ;
}
static int
F_49 ( unsigned long V_327 , long V_322 , int V_328 )
{
return F_178 ( V_327 , V_322 , V_328 , V_335 ) ;
}
void
F_180 ( unsigned long V_6 )
{
F_42 ( V_6 , L_196 , L_87 ) ;
}
void
F_176 ( void )
{
struct V_336 V_337 = { . V_338 = 1 } ;
unsigned char V_232 [ 128 ] ;
T_8 V_81 ;
if ( setjmp ( V_42 ) != 0 ) {
printf ( L_197 ) ;
return;
}
V_66 = 1 ;
F_3 () ;
F_181 ( & V_337 ) ;
F_174 () ;
while ( F_182 ( & V_337 , false , V_232 , sizeof( V_232 ) , & V_81 ) ) {
V_232 [ V_81 ] = '\0' ;
printf ( L_165 , V_232 ) ;
}
F_175 () ;
F_3 () ;
F_131 ( 200 ) ;
V_66 = 0 ;
}
static void F_2 ( void )
{
unsigned char V_232 [ 128 ] ;
T_9 V_339 ;
T_10 V_340 = 0 ;
if ( ! F_183 ( V_341 ) ) {
printf ( L_1 ) ;
return;
}
if ( setjmp ( V_42 ) != 0 ) {
printf ( L_198 ) ;
return;
}
V_66 = 1 ;
F_3 () ;
F_174 () ;
while ( ( V_339 = F_184 ( V_232 , V_340 , sizeof( V_232 ) - 1 ) ) ) {
if ( V_339 < 0 ) {
printf ( L_199 , V_339 ) ;
break;
}
V_232 [ V_339 ] = '\0' ;
printf ( L_165 , V_232 ) ;
V_340 += V_339 ;
}
F_175 () ;
F_3 () ;
F_131 ( 200 ) ;
V_66 = 0 ;
}
static void
F_89 ( int V_28 )
{
F_82 ( ( void * ) & V_342 ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_82 ( ( void * ) ( V_28 == 's' ? & V_343 : & V_344 ) ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_82 ( ( void * ) & V_345 ) ;
switch( V_28 ) {
case 'm' :
memmove ( ( void * ) V_342 , ( void * ) V_344 , V_345 ) ;
break;
case 's' :
memset ( ( void * ) V_342 , V_343 , V_345 ) ;
break;
case 'd' :
if( V_87 != '\n' )
V_87 = 0 ;
F_82 ( ( void * ) & V_346 ) ;
F_185 ( ( unsigned char * ) V_342 , ( unsigned char * ) V_344 , V_345 , V_346 ) ;
break;
}
}
static void
F_185 ( unsigned char * V_347 , unsigned char * V_348 , unsigned V_349 , unsigned V_350 )
{
unsigned V_145 , V_351 ;
V_351 = 0 ;
for( V_145 = V_349 ; V_145 > 0 ; -- V_145 )
if( * V_347 ++ != * V_348 ++ )
if( ++ V_351 <= V_350 )
printf ( L_200 , V_347 - 1 ,
V_347 [ - 1 ] , V_348 - 1 , V_348 [ - 1 ] ) ;
if( V_351 > V_350 )
printf ( L_201 , V_351 ) ;
}
static void
F_90 ( void )
{
unsigned V_73 , V_145 ;
unsigned char V_156 [ 4 ] ;
V_83 = L_202 ;
F_82 ( ( void * ) & V_342 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_82 ( ( void * ) & V_352 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_82 ( ( void * ) & V_343 ) ;
V_353 = ~ 0 ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_82 ( ( void * ) & V_353 ) ;
}
}
V_145 = 0 ;
for ( V_73 = V_342 ; V_73 < V_352 ; V_73 += 4 ) {
if ( F_76 ( V_73 , V_156 , 4 ) == 4
&& ( ( F_179 ( V_156 ) ^ V_343 ) & V_353 ) == 0 ) {
printf ( L_203 , V_73 , F_179 ( V_156 ) ) ;
if ( ++ V_145 >= 10 )
break;
}
}
}
static void
F_91 ( void )
{
unsigned char V_102 ;
unsigned V_73 ;
int V_155 , V_354 ;
F_82 ( & V_342 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_82 ( & V_355 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_82 ( & V_356 ) ;
V_354 = 0 ;
for ( V_73 = V_342 ; V_73 < V_356 ; V_73 += V_355 ) {
V_155 = F_76 ( V_73 , & V_102 , 1 ) ;
if ( V_155 && ! V_354 ) {
printf ( L_204 , V_73 ) ;
} else if ( ! V_155 && V_354 )
printf ( L_205 , V_73 - V_355 ) ;
V_354 = V_155 ;
if ( V_73 + V_355 < V_73 )
break;
}
if ( V_354 )
printf ( L_205 , V_73 - V_355 ) ;
}
static void F_186 ( struct V_357 * V_358 )
{
char V_359 ;
V_359 = ( V_358 -> V_359 == 0 ) ? 'R' :
( V_358 -> V_359 < 0 ) ? 'U' :
( V_358 -> V_359 & V_360 ) ? 'D' :
( V_358 -> V_359 & V_361 ) ? 'T' :
( V_358 -> V_359 & V_362 ) ? 'C' :
( V_358 -> V_363 & V_364 ) ? 'Z' :
( V_358 -> V_363 & V_365 ) ? 'E' :
( V_358 -> V_359 & V_366 ) ? 'S' : '?' ;
printf ( L_206 , V_358 ,
V_358 -> V_367 . V_368 ,
V_358 -> V_142 , V_358 -> V_369 -> V_142 ,
V_359 , F_187 ( V_358 ) -> V_35 ,
V_358 -> V_143 ) ;
}
static void F_110 ( void )
{
unsigned long V_370 ;
struct V_357 * V_358 = NULL ;
printf ( L_207 ) ;
if ( F_82 ( & V_370 ) )
V_358 = (struct V_357 * ) V_370 ;
if ( setjmp ( V_42 ) != 0 ) {
V_66 = 0 ;
printf ( L_208 , V_358 ) ;
return;
}
V_66 = 1 ;
F_3 () ;
if ( V_358 )
F_186 ( V_358 ) ;
else
F_188 (tsk)
F_186 ( V_358 ) ;
F_3 () ;
F_131 ( 200 ) ;
V_66 = 0 ;
}
static void F_109 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_111 ;
int V_68 ;
typedef unsigned long (* T_11)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_11 V_371 ;
if ( ! F_82 ( & V_103 ) )
return;
if ( V_87 != '\n' )
V_87 = 0 ;
for ( V_68 = 0 ; V_68 < 8 ; ++ V_68 )
args [ V_68 ] = 0 ;
for ( V_68 = 0 ; V_68 < 8 ; ++ V_68 ) {
if ( ! F_82 ( & args [ V_68 ] ) || V_87 == '\n' )
break;
V_87 = 0 ;
}
V_371 = ( T_11 ) V_103 ;
V_111 = 0 ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_111 = V_371 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_3 () ;
printf ( L_209 , V_111 ) ;
} else {
printf ( L_210 , V_237 ) ;
}
V_66 = 0 ;
}
int
F_86 ( void )
{
int V_247 ;
if( V_87 != 0 ) {
V_247 = V_87 ;
V_87 = 0 ;
} else
V_247 = F_88 () ;
while( V_247 == ' ' || V_247 == '\t' )
V_247 = F_88 () ;
return V_247 ;
}
int
F_82 ( unsigned long * V_154 )
{
int V_247 , V_61 ;
unsigned long V_102 ;
V_247 = F_86 () ;
if ( V_247 == '%' ) {
char V_372 [ 8 ] ;
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_372 ) - 1 ; ++ V_68 ) {
V_247 = F_88 () ;
if ( ! isalnum ( V_247 ) ) {
V_87 = V_247 ;
break;
}
V_372 [ V_68 ] = V_247 ;
}
V_372 [ V_68 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_373 ; ++ V_68 ) {
if ( strcmp ( V_374 [ V_68 ] , V_372 ) == 0 ) {
if ( V_84 == NULL ) {
printf ( L_211 ) ;
return 0 ;
}
* V_154 = ( ( unsigned long * ) V_84 ) [ V_68 ] ;
return 1 ;
}
}
printf ( L_212 , V_372 ) ;
return 0 ;
}
if ( V_247 == '0' ) {
V_247 = F_88 () ;
if ( V_247 == 'x' ) {
V_247 = F_88 () ;
} else {
V_61 = F_189 ( V_247 ) ;
if ( V_61 == V_58 ) {
V_87 = V_247 ;
* V_154 = 0 ;
return 1 ;
}
}
} else if ( V_247 == '$' ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < 63 ; V_68 ++ ) {
V_247 = F_88 () ;
if ( isspace ( V_247 ) || V_247 == '\0' ) {
V_87 = V_247 ;
break;
}
V_116 [ V_68 ] = V_247 ;
}
V_116 [ V_68 ++ ] = 0 ;
* V_154 = 0 ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
* V_154 = F_190 ( V_116 ) ;
F_3 () ;
}
V_66 = 0 ;
if ( ! ( * V_154 ) ) {
printf ( L_213 , V_116 ) ;
return 0 ;
}
return 1 ;
}
V_61 = F_189 ( V_247 ) ;
if ( V_61 == V_58 ) {
V_87 = V_247 ;
return 0 ;
}
V_102 = 0 ;
do {
V_102 = ( V_102 << 4 ) + V_61 ;
V_247 = F_88 () ;
V_61 = F_189 ( V_247 ) ;
} while ( V_61 != V_58 );
V_87 = V_247 ;
* V_154 = V_102 ;
return 1 ;
}
static void
F_124 ( void )
{
int V_247 ;
V_247 = V_87 ;
V_87 = 0 ;
while( V_247 != '\n' )
V_247 = F_88 () ;
}
static int F_189 ( int V_247 )
{
if( '0' <= V_247 && V_247 <= '9' )
return V_247 - '0' ;
if( 'A' <= V_247 && V_247 <= 'F' )
return V_247 - ( 'A' - 10 ) ;
if( 'a' <= V_247 && V_247 <= 'f' )
return V_247 - ( 'a' - 10 ) ;
return V_58 ;
}
void
F_191 ( char * V_375 , int V_114 )
{
int V_247 ;
V_247 = F_86 () ;
do {
if( V_114 > 1 ) {
* V_375 ++ = V_247 ;
-- V_114 ;
}
V_247 = F_88 () ;
} while( V_247 != ' ' && V_247 != '\t' && V_247 != '\n' );
V_87 = V_247 ;
* V_375 = 0 ;
}
static void
F_85 ( void )
{
V_376 = NULL ;
}
static int
F_88 ( void )
{
if ( V_376 == NULL || * V_376 == 0 ) {
if ( F_192 ( line , sizeof( line ) ) == NULL ) {
V_376 = NULL ;
return V_58 ;
}
V_376 = line ;
}
return * V_376 ++ ;
}
static void
F_87 ( char * V_377 )
{
V_376 = V_377 ;
}
static void
F_95 ( void )
{
int type = F_88 () ;
unsigned long V_6 ;
static char V_378 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_82 ( & V_6 ) )
F_42 ( V_6 , L_101 , L_34 ) ;
V_87 = 0 ;
break;
case 's' :
F_191 ( V_378 , 64 ) ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_6 = F_190 ( V_378 ) ;
if ( V_6 )
printf ( L_214 , V_378 , V_6 ) ;
else
printf ( L_215 , V_378 ) ;
F_3 () ;
}
V_66 = 0 ;
V_87 = 0 ;
break;
}
}
static void F_42 ( unsigned long V_39 , const char * V_379 ,
const char * V_380 )
{
char * V_381 ;
const char * V_115 = NULL ;
unsigned long V_33 , V_114 ;
printf ( V_105 , V_39 ) ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_115 = F_123 ( V_39 , & V_114 , & V_33 , & V_381 ,
V_116 ) ;
F_3 () ;
F_131 ( 200 ) ;
}
V_66 = 0 ;
if ( V_115 ) {
printf ( L_216 , V_379 , V_115 , V_33 , V_114 ) ;
if ( V_381 )
printf ( L_217 , V_381 ) ;
}
printf ( L_165 , V_380 ) ;
}
void F_112 ( void )
{
int V_68 ;
unsigned long V_273 , V_274 ;
unsigned long V_382 ;
printf ( L_218 , F_16 () ) ;
for ( V_68 = 0 ; V_68 < V_383 ; V_68 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( ! V_273 && ! V_274 )
continue;
printf ( L_219 , V_68 , V_273 , V_274 ) ;
if ( ! ( V_273 & V_384 ) ) {
printf ( L_34 ) ;
continue;
}
V_382 = V_274 & V_385 ;
if ( V_274 & V_386 ) {
printf ( L_220 ,
F_193 ( V_273 ) ,
( V_274 & ~ V_387 ) >> V_388 ,
V_382 ) ;
} else {
printf ( L_221 ,
F_194 ( V_273 ) ,
( V_274 & ~ V_387 ) >> V_389 ,
V_382 ) ;
}
}
}
void F_112 ( void )
{
int V_68 ;
printf ( L_222 ) ;
for ( V_68 = 0 ; V_68 < 16 ; ++ V_68 )
printf ( L_223 , F_195 ( V_68 ) ) ;
printf ( L_34 ) ;
}
static void F_113 ( void )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_390 ; V_68 ++ ) {
unsigned long V_391 , V_392 , V_393 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_224 , V_68 , V_391 , V_392 , V_393 ) ;
if ( V_391 & V_394 ) {
printf ( L_225 ,
V_391 & V_395 ,
V_392 & V_396 ,
V_392 & V_397 ,
( V_393 & V_398 ) ? 'W' : 'w' ,
( V_393 & V_399 ) ? 'I' : 'i' ,
( V_393 & V_400 ) ? 'M' : 'm' ,
( V_393 & V_401 ) ? 'G' : 'g' ,
( V_393 & V_402 ) ? 'E' : 'e' ) ;
}
printf ( L_34 ) ;
}
}
static void F_114 ( void )
{
V_235 V_403 , V_404 , V_405 ;
V_236 V_406 ;
int V_68 , V_407 , V_408 , V_409 , V_410 , V_411 , V_412 = 0 ;
int V_413 ;
static const char * V_414 [] = {
L_226 ,
L_227 ,
L_228 ,
L_229 ,
L_230 ,
L_231 ,
L_232 ,
L_233 ,
L_234 ,
L_235 ,
L_236 ,
L_237 ,
L_238 ,
L_239 ,
L_240 ,
L_241 ,
L_242 ,
L_243 ,
L_244 ,
L_245 ,
L_246 ,
L_247 ,
L_248 ,
L_249 ,
L_250 ,
L_251 ,
L_252 ,
L_253 ,
L_254 ,
L_255 ,
L_256 ,
L_257 ,
} ;
V_403 = F_115 ( V_415 ) ;
V_413 = ( V_403 & 3 ) + 1 ;
V_408 = ( ( V_403 >> 2 ) & 3 ) + 1 ;
V_409 = ( ( V_403 >> 6 ) & 0x1f ) + 1 ;
V_410 = ( V_403 >> 24 ) & 0xf ;
V_411 = ( V_403 >> 16 ) & 0x7f ;
if ( ( V_413 > 1 ) && ( V_403 & 0x10000 ) )
V_412 = 1 ;
printf ( L_258 ,
V_413 , V_408 , V_409 , V_410 , V_411 ) ;
V_404 = ( 1ul << V_409 ) - 1 ;
V_405 = ( 1ul << V_410 ) - 1 ;
V_406 = ( 1ull << V_411 ) - 1 ;
for ( V_407 = 0 ; V_407 < V_408 ; V_407 ++ ) {
V_235 V_416 ;
int V_417 , V_418 , V_419 = 1 ;
printf ( L_259 , V_407 ) ;
switch( V_407 ) {
case 0 :
V_416 = F_115 ( V_420 ) ;
break;
case 1 :
V_416 = F_115 ( V_421 ) ;
break;
case 2 :
V_416 = F_115 ( V_422 ) ;
break;
case 3 :
V_416 = F_115 ( V_423 ) ;
break;
default:
printf ( L_260 ) ;
continue;
}
V_417 = V_416 & 0xfff ;
V_418 = ( V_416 >> 24 ) & 0xff ;
for ( V_68 = 0 ; V_68 < V_417 ; V_68 ++ ) {
V_235 V_424 = F_196 ( V_407 ) ;
V_235 V_425 = F_197 ( V_426 ) ;
V_236 V_427 = 0 ;
V_236 V_428 ;
int V_429 = V_68 , V_430 = V_68 ;
if ( V_418 != 0 ) {
V_430 = V_68 / V_418 ;
V_429 = V_68 % V_418 ;
V_427 = V_430 * 0x1000 ;
}
V_424 |= F_198 ( V_429 ) ;
F_9 ( V_431 , V_424 ) ;
F_9 ( V_432 , V_425 ) ;
F_9 ( V_433 , V_427 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_425 = F_115 ( V_432 ) ;
V_427 = F_115 ( V_433 ) ;
V_428 = F_115 ( V_434 ) ;
if ( V_418 && ( V_68 % V_418 ) == 0 )
V_419 = 1 ;
if ( ! ( V_425 & V_435 ) )
continue;
if ( V_418 == 0 )
printf ( L_261 , V_68 ) ;
else if ( V_419 )
printf ( L_262 , V_430 , 'A' + V_429 ) ;
else
printf ( L_263 , 'A' + V_429 ) ;
V_419 = 0 ;
printf ( L_264 ,
V_427 & ~ 0x3ffull ,
( V_425 >> 16 ) & 0x3fff ,
V_414 [ ( V_425 >> 7 ) & 0x1f ] ,
V_425 & V_436 ? 'I' : ' ' ,
V_425 & V_437 ? 'P' : ' ' ,
V_425 & V_438 ? '1' : '0' ) ;
printf ( L_265 ,
V_427 & V_439 ? 'a' : ' ' ,
V_427 & V_440 ? 'v' : ' ' ,
V_427 & V_441 ? 'w' : ' ' ,
V_427 & V_442 ? 'i' : ' ' ,
V_427 & V_443 ? 'm' : ' ' ,
V_427 & V_444 ? 'g' : ' ' ,
V_427 & V_445 ? 'e' : ' ' ) ;
printf ( L_266 , V_428 & V_406 & ~ 0x7ffull ) ;
if ( V_425 & V_436 )
printf ( L_267 ,
V_414 [ ( V_428 >> 1 ) & 0x1f ] ) ;
else
printf ( L_268 ,
V_428 & V_446 ? 'x' : ' ' ,
V_428 & V_447 ? 'w' : ' ' ,
V_428 & V_448 ? 'r' : ' ' ,
V_428 & V_449 ? 'x' : ' ' ,
V_428 & V_450 ? 'w' : ' ' ,
V_428 & V_451 ? 'r' : ' ' ) ;
}
}
}
static void F_199 ( int V_452 )
{
if ( V_452 ) {
V_453 = F_61 ;
V_454 = F_70 ;
V_455 = F_65 ;
V_456 = F_66 ;
V_457 = F_69 ;
V_458 = F_68 ;
V_459 = F_71 ;
} else {
V_453 = NULL ;
V_454 = NULL ;
V_455 = NULL ;
V_456 = NULL ;
V_457 = NULL ;
V_458 = NULL ;
V_459 = NULL ;
}
}
static void F_200 ( int V_460 )
{
F_199 ( 1 ) ;
F_201 ( F_64 () ) ;
if ( ! V_461 )
F_199 ( 0 ) ;
}
static int T_12 F_202 ( void )
{
F_203 ( 'x' , & V_462 ) ;
return 0 ;
}
static int F_204 ( void * V_463 , V_236 V_156 )
{
V_461 = ! ! V_156 ;
F_199 ( V_461 ) ;
return 0 ;
}
static int F_205 ( void * V_463 , V_236 * V_156 )
{
* V_156 = V_461 ;
return 0 ;
}
static int T_12 F_206 ( void )
{
F_207 ( L_269 , 0600 , V_464 , NULL ,
& V_465 ) ;
return 0 ;
}
static int T_12 F_208 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_270 , 5 ) == 0 ) {
F_199 ( 1 ) ;
V_466 = 1 ;
V_461 = 1 ;
} else if ( strncmp ( V_2 , L_271 , 2 ) == 0 ) {
F_199 ( 1 ) ;
V_461 = 1 ;
} else if ( strncmp ( V_2 , L_272 , 3 ) == 0 )
V_461 = 0 ;
else
return 1 ;
return 0 ;
}
void T_12 F_209 ( void )
{
if ( V_461 )
F_199 ( 1 ) ;
if ( V_466 )
F_201 ( NULL ) ;
}
void F_210 ( struct V_467 * V_468 )
{
struct V_469 * V_469 ;
F_211 (spu, list, full_list) {
if ( V_469 -> V_470 >= V_471 ) {
F_212 ( 1 ) ;
continue;
}
V_472 [ V_469 -> V_470 ] . V_469 = V_469 ;
V_472 [ V_469 -> V_470 ] . V_473 = 0 ;
V_472 [ V_469 -> V_470 ] . V_474 = ( unsigned long )
V_472 [ V_469 -> V_470 ] . V_469 -> V_475 ;
}
}
static void F_213 ( void )
{
struct V_469 * V_469 ;
int V_68 ;
V_236 V_378 ;
for ( V_68 = 0 ; V_68 < V_471 ; V_68 ++ ) {
if ( ! V_472 [ V_68 ] . V_469 )
continue;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_469 = V_472 [ V_68 ] . V_469 ;
V_472 [ V_68 ] . V_476 =
F_214 ( & V_469 -> V_477 -> V_478 ) ;
V_378 = F_215 ( V_469 ) ;
V_472 [ V_68 ] . V_479 = V_378 ;
V_378 &= ~ V_480 ;
F_216 ( V_469 , V_378 ) ;
F_3 () ;
F_131 ( 200 ) ;
V_472 [ V_68 ] . V_473 = 1 ;
printf ( L_273 , V_68 ,
V_472 [ V_68 ] . V_476 ?
L_274 : L_275 ) ;
} else {
V_66 = 0 ;
printf ( L_276 , V_68 ) ;
}
V_66 = 0 ;
}
}
static void F_217 ( void )
{
struct V_469 * V_469 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_471 ; V_68 ++ ) {
if ( ! V_472 [ V_68 ] . V_469 )
continue;
if ( ! V_472 [ V_68 ] . V_473 ) {
printf ( L_277
L_278 , V_68 ) ;
continue;
}
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_469 = V_472 [ V_68 ] . V_469 ;
F_216 ( V_469 , V_472 [ V_68 ] . V_479 ) ;
F_218 ( & V_469 -> V_477 -> V_478 ,
V_472 [ V_68 ] . V_476 ) ;
F_3 () ;
F_131 ( 200 ) ;
printf ( L_279 , V_68 ) ;
} else {
V_66 = 0 ;
printf ( L_280 , V_68 ) ;
}
V_66 = 0 ;
}
}
static void F_219 ( struct V_469 * V_469 )
{
printf ( L_281 , V_469 ) ;
F_220 ( V_469 , L_282 , V_470 ) ;
F_220 ( V_469 , L_165 , V_115 ) ;
F_220 ( V_469 , L_283 , V_481 ) ;
F_220 ( V_469 , L_284 , V_475 ) ;
F_220 ( V_469 , L_283 , V_482 ) ;
F_220 ( V_469 , L_282 , V_483 ) ;
F_220 ( V_469 , L_283 , V_34 ) ;
F_220 ( V_469 , L_285 , V_484 ) ;
F_220 ( V_469 , L_283 , V_485 ) ;
F_220 ( V_469 , L_283 , V_486 ) ;
F_220 ( V_469 , L_283 , V_487 ) ;
F_220 ( V_469 , L_283 , V_488 [ 0 ] ) ;
F_220 ( V_469 , L_283 , V_488 [ 1 ] ) ;
F_220 ( V_469 , L_283 , V_488 [ 2 ] ) ;
F_220 ( V_469 , L_282 , V_489 ) ;
F_220 ( V_469 , L_285 , V_142 ) ;
F_220 ( V_469 , L_284 , V_490 ) ;
F_220 ( V_469 , L_284 , V_491 ) ;
F_220 ( V_469 , L_284 , V_492 ) ;
F_220 ( V_469 , L_284 , V_493 ) ;
F_220 ( V_469 , L_283 , V_494 ) ;
F_220 ( V_469 , L_284 , V_477 ) ;
F_221 ( L_282 , V_477 -> V_478 ,
F_214 ( & V_469 -> V_477 -> V_478 ) ) ;
F_221 ( L_282 , V_477 -> V_495 ,
F_214 ( & V_469 -> V_477 -> V_495 ) ) ;
F_221 ( L_282 , V_477 -> V_496 ,
F_214 ( & V_469 -> V_477 -> V_496 ) ) ;
F_220 ( V_469 , L_284 , V_497 ) ;
F_220 ( V_469 , L_284 , V_498 ) ;
}
int
F_222 ( unsigned long V_327 , long V_322 , int V_328 )
{
return F_178 ( V_327 , V_322 , V_328 , V_499 ) ;
}
static void F_223 ( unsigned long V_311 , int V_500 )
{
unsigned long V_33 , V_6 , V_501 ;
if ( setjmp ( V_42 ) == 0 ) {
V_66 = 1 ;
F_3 () ;
V_501 = ( unsigned long ) V_472 [ V_311 ] . V_469 -> V_475 ;
F_3 () ;
F_131 ( 200 ) ;
} else {
V_66 = 0 ;
printf ( L_286 , V_311 ) ;
return;
}
V_66 = 0 ;
if ( F_82 ( & V_33 ) )
V_6 = V_501 + V_33 ;
else
V_6 = V_472 [ V_311 ] . V_474 ;
if ( V_6 >= V_501 + V_502 ) {
printf ( L_287 ) ;
return;
}
switch ( V_500 ) {
case 'i' :
V_6 += F_222 ( V_6 , 16 , 1 ) ;
V_83 = L_288 ;
break;
default:
F_177 ( V_6 , 64 ) ;
V_6 += 64 ;
V_83 = L_289 ;
break;
}
V_472 [ V_311 ] . V_474 = V_6 ;
}
static int F_100 ( void )
{
static unsigned long V_311 = 0 ;
int V_28 , V_500 = 0 ;
V_28 = F_88 () ;
switch ( V_28 ) {
case 's' :
F_213 () ;
break;
case 'r' :
F_217 () ;
break;
case 'd' :
V_500 = F_88 () ;
if ( isxdigit ( V_500 ) || V_500 == '\n' )
V_87 = V_500 ;
case 'f' :
F_82 ( & V_311 ) ;
if ( V_311 >= V_471 || ! V_472 [ V_311 ] . V_469 ) {
printf ( L_290 ) ;
return 0 ;
}
switch ( V_28 ) {
case 'f' :
F_219 ( V_472 [ V_311 ] . V_469 ) ;
break;
default:
F_223 ( V_311 , V_500 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_100 ( void )
{
return - 1 ;
}
