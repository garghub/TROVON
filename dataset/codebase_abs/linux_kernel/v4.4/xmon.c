static inline long F_1 ( unsigned long V_1 ) { return 0 ; }
static inline void F_2 ( void )
{
asm volatile("sync; isync");
}
static inline void F_3 ( void * V_2 )
{
asm volatile ("dcbst 0,%0; sync; icbi 0,%0; isync" : : "r" (p));
}
static inline void F_4 ( void * V_2 )
{
asm volatile ("dcbf 0,%0; icbi 0,%0" : : "r" (p));
}
static inline void F_5 ( void * V_2 )
{
asm volatile ("dcbi 0,%0; icbi 0,%0" : : "r" (p));
}
static void F_6 ( unsigned long V_1 )
{
if ( ! F_7 ( V_3 ) )
return;
if ( F_7 ( V_4 ) ) {
F_8 ( V_5 , V_1 ) ;
return;
}
F_1 ( V_1 ) ;
}
static void F_9 ( unsigned long V_6 )
{
V_6 &= ~ V_7 ;
if ( F_7 ( V_4 ) )
V_6 |= V_8 ;
else
V_6 |= V_9 ;
F_6 ( V_6 ) ;
}
static inline void F_10 ( void )
{
#ifdef F_11
static struct V_10 args ;
args . V_11 = F_12 ( L_1 ) ;
if ( args . V_11 == V_12 )
return;
args . V_11 = F_13 ( args . V_11 ) ;
args . V_13 = F_13 ( 3 ) ;
args . V_14 = F_13 ( 1 ) ;
args . V_15 = & args . args [ 3 ] ;
args . args [ 0 ] = F_13 ( V_16 ) ;
args . args [ 1 ] = 0 ;
args . args [ 2 ] = 0 ;
F_14 ( F_15 ( & args ) ) ;
#endif
}
static void F_16 ( void )
{
int V_17 = F_17 () + 0x100 ;
int V_18 = 0 , V_19 ;
long V_20 ;
if ( V_21 == V_17 )
return;
for (; ; ) {
V_18 = F_18 ( & V_21 , 0 , V_17 ) ;
if ( V_18 == 0 )
return;
V_20 = 10000 ;
while ( V_21 == V_18 ) {
if ( -- V_20 > 0 ) {
F_19 ( 100 ) ;
continue;
}
V_19 = F_18 ( & V_21 , V_18 , V_17 ) ;
if ( V_19 == V_18 )
return;
break;
}
}
}
static void F_20 ( void )
{
V_21 = 0 ;
}
int F_21 ( void )
{
return ! F_22 ( & V_22 ) ;
}
static inline int F_23 ( struct V_23 * V_24 )
{
#if F_24 ( V_25 ) || F_24 ( V_26 )
return 0 ;
#else
return ( ( V_24 -> V_27 & V_28 ) == 0 ) ;
#endif
}
static int F_25 ( struct V_23 * V_24 , int V_29 )
{
int V_30 = 0 ;
struct V_31 * V_32 ;
long V_33 [ V_34 ] ;
unsigned long V_35 ;
unsigned long V_36 ;
#ifdef F_26
int V_37 ;
int V_38 ;
unsigned long V_20 ;
#endif
F_27 ( V_36 ) ;
F_28 () ;
V_32 = F_29 ( V_24 -> V_39 , & V_35 ) ;
if ( V_32 != NULL ) {
V_24 -> V_39 = V_32 -> V_40 + V_35 ;
F_30 ( & V_32 -> V_41 ) ;
}
F_31 () ;
#ifdef F_26
V_37 = F_17 () ;
if ( F_32 ( V_37 , & V_22 ) ) {
F_16 () ;
F_33 ( V_24 ) ;
printf ( L_2
L_3 ,
V_37 , V_24 -> V_42 , F_34 ( F_35 ( V_24 ) ) ) ;
F_20 () ;
longjmp ( V_43 [ V_37 ] , 1 ) ;
}
if ( setjmp ( V_33 ) != 0 ) {
if ( ! V_44 || ! V_45 ) {
F_16 () ;
printf ( L_4
L_5 , V_37 ) ;
F_20 () ;
goto V_46;
}
V_38 = ! ( V_47 && V_37 == V_48 ) ;
goto V_49;
}
V_43 [ V_37 ] = V_33 ;
V_32 = NULL ;
if ( ( V_24 -> V_27 & ( V_50 | V_51 | V_52 ) ) == ( V_50 | V_52 ) )
V_32 = F_36 ( V_24 -> V_39 ) ;
if ( V_32 || F_23 ( V_24 ) )
V_29 = 0 ;
if ( ! V_29 ) {
F_16 () ;
F_33 ( V_24 ) ;
if ( V_32 ) {
printf ( L_6 ,
V_37 , F_37 ( V_32 ) ) ;
F_38 ( V_24 -> V_39 , L_7 , L_8 ) ;
}
if ( F_23 ( V_24 ) )
printf ( L_9
L_10 ) ;
F_20 () ;
}
F_39 ( V_37 , & V_22 ) ;
V_46:
V_38 = 1 ;
while ( V_38 && ! V_45 ) {
if ( V_44 == 0 ) {
if ( V_29 )
goto V_53;
V_38 = F_40 ( 0 , & V_44 ) ;
}
F_41 () ;
}
if ( ! V_38 && ! V_45 ) {
int V_54 = F_42 () ;
V_48 = V_37 ;
F_43 () ;
if ( V_54 > 1 ) {
F_44 () ;
for ( V_20 = 100000000 ; V_20 != 0 ; -- V_20 ) {
if ( F_45 ( & V_22 ) >= V_54 )
break;
F_41 () ;
}
}
F_46 () ;
F_10 () ;
if ( V_32 || F_35 ( V_24 ) == 0xd00 )
F_47 ( V_24 -> V_39 , 1 , 0 ) ;
printf ( L_11 ) ;
F_43 () ;
V_45 = 1 ;
F_41 () ;
}
V_49:
while ( V_44 ) {
if ( V_38 ) {
if ( V_37 == V_48 ) {
if ( ! F_40 ( 0 , & V_47 ) ) {
V_38 = 0 ;
continue;
}
while ( V_37 == V_48 )
F_41 () ;
}
F_41 () ;
} else {
V_30 = F_48 ( V_24 ) ;
if ( V_30 != 0 ) {
F_49 () ;
V_45 = 0 ;
F_50 () ;
V_44 = 0 ;
break;
}
V_38 = 1 ;
}
}
V_53:
F_51 ( V_37 , & V_22 ) ;
V_43 [ V_37 ] = NULL ;
#else
if ( V_44 ) {
printf ( L_12 ,
V_24 -> V_42 , F_34 ( F_35 ( V_24 ) ) ) ;
longjmp ( V_43 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_33 ) == 0 ) {
V_43 [ 0 ] = V_33 ;
V_44 = 1 ;
F_33 ( V_24 ) ;
V_32 = F_36 ( V_24 -> V_39 ) ;
if ( V_32 ) {
printf ( L_13 , F_37 ( V_32 ) ) ;
F_38 ( V_24 -> V_39 , L_7 , L_8 ) ;
}
if ( F_23 ( V_24 ) )
printf ( L_9
L_10 ) ;
F_46 () ;
F_10 () ;
if ( V_32 || F_35 ( V_24 ) == 0xd00 )
F_47 ( V_24 -> V_39 , 1 , 0 ) ;
printf ( L_11 ) ;
}
V_30 = F_48 ( V_24 ) ;
F_49 () ;
V_44 = 0 ;
#endif
#ifdef F_52
if ( V_24 -> V_27 & V_55 ) {
V_32 = F_36 ( V_24 -> V_39 ) ;
if ( V_32 != NULL ) {
V_24 -> V_39 = ( unsigned long ) & V_32 -> V_56 [ 0 ] ;
F_53 ( & V_32 -> V_41 ) ;
}
}
#else
if ( ( V_24 -> V_27 & ( V_50 | V_51 | V_52 ) ) == ( V_50 | V_52 ) ) {
V_32 = F_36 ( V_24 -> V_39 ) ;
if ( V_32 != NULL ) {
int V_57 = F_54 ( V_24 , V_32 -> V_56 [ 0 ] ) ;
if ( V_57 == 0 ) {
V_24 -> V_39 = ( unsigned long ) & V_32 -> V_56 [ 0 ] ;
F_53 ( & V_32 -> V_41 ) ;
} else if ( V_57 < 0 ) {
printf ( L_14 ,
( F_55 ( V_32 -> V_56 [ 0 ] ) ? L_15 : L_16 ) ) ;
}
}
}
#endif
F_56 () ;
F_57 () ;
F_58 ( V_36 ) ;
return V_30 != 'X' && V_30 != V_58 ;
}
int F_59 ( struct V_23 * V_59 )
{
struct V_23 V_24 ;
if ( V_59 == NULL ) {
F_60 ( & V_24 ) ;
V_59 = & V_24 ;
}
return F_25 ( V_59 , 0 ) ;
}
T_1 F_61 ( int V_60 , void * V_61 )
{
unsigned long V_36 ;
F_27 ( V_36 ) ;
printf ( L_17 ) ;
F_59 ( F_62 () ) ;
F_58 ( V_36 ) ;
return V_62 ;
}
static int F_63 ( struct V_23 * V_24 )
{
struct V_31 * V_32 ;
unsigned long V_35 ;
if ( ( V_24 -> V_27 & ( V_50 | V_51 | V_52 ) ) != ( V_50 | V_52 ) )
return 0 ;
V_32 = F_29 ( V_24 -> V_39 , & V_35 ) ;
if ( V_32 != NULL && V_35 == 4 ) {
V_24 -> V_39 = V_32 -> V_40 + 4 ;
F_30 ( & V_32 -> V_41 ) ;
return 1 ;
}
V_32 = F_36 ( V_24 -> V_39 ) ;
if ( ! V_32 )
return 0 ;
F_25 ( V_24 , 0 ) ;
return 1 ;
}
static int F_64 ( struct V_23 * V_24 )
{
if ( F_65 ( V_24 ) )
return 0 ;
F_25 ( V_24 , 0 ) ;
return 1 ;
}
static int F_66 ( struct V_23 * V_24 )
{
if ( ( V_24 -> V_27 & ( V_50 | V_51 | V_52 ) ) != ( V_50 | V_52 ) )
return 0 ;
if ( V_63 . V_64 == 0 )
return 0 ;
F_25 ( V_24 , 0 ) ;
return 1 ;
}
static int F_67 ( struct V_23 * V_24 )
{
if ( ( V_24 -> V_27 & ( V_50 | V_51 | V_52 ) ) != ( V_50 | V_52 ) )
return 0 ;
if ( V_65 == NULL )
return 0 ;
F_25 ( V_24 , 0 ) ;
return 1 ;
}
static int F_68 ( struct V_23 * V_24 )
{
#ifdef F_26
if ( V_44 && ! F_32 ( F_17 () , & V_22 ) )
F_25 ( V_24 , 1 ) ;
#endif
return 0 ;
}
static int F_69 ( struct V_23 * V_24 )
{
struct V_31 * V_32 ;
unsigned long V_35 ;
if ( V_44 && V_66 )
F_70 ( V_24 ) ;
if ( ( V_24 -> V_27 & ( V_50 | V_51 | V_52 ) ) == ( V_50 | V_52 ) ) {
V_32 = F_29 ( V_24 -> V_39 , & V_35 ) ;
if ( V_32 != NULL ) {
V_24 -> V_39 = V_32 -> V_40 + V_35 ;
F_30 ( & V_32 -> V_41 ) ;
}
}
return 0 ;
}
static struct V_31 * F_36 ( unsigned long V_67 )
{
int V_68 ;
struct V_31 * V_32 ;
V_32 = V_69 ;
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 , ++ V_32 )
if ( V_32 -> V_64 && V_67 == V_32 -> V_40 )
return V_32 ;
return NULL ;
}
static struct V_31 * F_29 ( unsigned long V_39 , unsigned long * V_71 )
{
unsigned long V_72 ;
V_72 = V_39 - ( unsigned long ) V_69 ;
if ( V_72 >= sizeof( V_69 ) )
return NULL ;
V_72 %= sizeof( struct V_31 ) ;
if ( V_72 != F_71 ( struct V_31 , V_56 [ 0 ] )
&& V_72 != F_71 ( struct V_31 , V_56 [ 1 ] ) )
return NULL ;
* V_71 = V_72 - F_71 ( struct V_31 , V_56 [ 0 ] ) ;
return (struct V_31 * ) ( V_39 - V_72 ) ;
}
static struct V_31 * F_72 ( unsigned long V_73 )
{
struct V_31 * V_32 ;
V_73 &= ~ 3UL ;
V_32 = F_36 ( V_73 ) ;
if ( V_32 )
return V_32 ;
for ( V_32 = V_69 ; V_32 < & V_69 [ V_70 ] ; ++ V_32 ) {
if ( ! V_32 -> V_64 && F_73 ( & V_32 -> V_41 ) == 0 ) {
V_32 -> V_40 = V_73 ;
V_32 -> V_56 [ 1 ] = V_74 ;
F_3 ( & V_32 -> V_56 [ 1 ] ) ;
return V_32 ;
}
}
printf ( L_18 ) ;
return NULL ;
}
static void F_49 ( void )
{
int V_68 ;
struct V_31 * V_32 ;
V_32 = V_69 ;
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 , ++ V_32 ) {
if ( ( V_32 -> V_64 & ( V_75 | V_76 ) ) == 0 )
continue;
if ( F_74 ( V_32 -> V_40 , & V_32 -> V_56 [ 0 ] , 4 ) != 4 ) {
printf ( L_19
L_20 , V_32 -> V_40 ) ;
V_32 -> V_64 = 0 ;
continue;
}
if ( F_75 ( V_32 -> V_56 [ 0 ] ) || F_55 ( V_32 -> V_56 [ 0 ] ) ) {
printf ( L_21
L_22 , V_32 -> V_40 ) ;
V_32 -> V_64 = 0 ;
continue;
}
F_3 ( & V_32 -> V_56 [ 0 ] ) ;
if ( V_32 -> V_64 & V_76 )
continue;
if ( F_76 ( V_32 -> V_40 , & V_74 , 4 ) != 4 ) {
printf ( L_23
L_20 , V_32 -> V_40 ) ;
V_32 -> V_64 &= ~ V_75 ;
continue;
}
F_3 ( ( void * ) V_32 -> V_40 ) ;
}
}
static void F_56 ( void )
{
struct V_77 V_78 ;
if ( V_63 . V_64 ) {
V_78 . V_40 = V_63 . V_40 ;
V_78 . type = ( V_63 . V_64 & V_79 ) | V_80 ;
V_78 . V_81 = 8 ;
F_77 ( & V_78 ) ;
}
if ( V_65 )
F_9 ( V_65 -> V_40 ) ;
}
static void F_46 ( void )
{
int V_68 ;
struct V_31 * V_32 ;
unsigned V_56 ;
V_32 = V_69 ;
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 , ++ V_32 ) {
if ( ( V_32 -> V_64 & ( V_75 | V_76 ) ) != V_75 )
continue;
if ( F_74 ( V_32 -> V_40 , & V_56 , 4 ) == 4
&& V_56 == V_74
&& F_76 ( V_32 -> V_40 , & V_32 -> V_56 , 4 ) != 4 )
printf ( L_24 ,
V_32 -> V_40 ) ;
else
F_3 ( ( void * ) V_32 -> V_40 ) ;
}
}
static void F_31 ( void )
{
F_78 () ;
F_6 ( 0 ) ;
}
static void F_79 ( void )
{
unsigned long V_82 ;
if ( ! F_80 ( & V_82 ) ) {
printf ( L_25 ) ;
V_82 = 0 ;
}
F_81 ( V_82 ) ;
}
static int
F_48 ( struct V_23 * V_59 )
{
int V_30 = 0 ;
V_83 = NULL ;
V_84 = V_59 ;
if ( ! V_85 ) {
V_85 = 1 ;
F_82 ( V_59 -> V_86 [ 1 ] , V_59 -> V_87 , V_59 -> V_39 ) ;
}
for(; ; ) {
#ifdef F_26
printf ( L_26 , F_17 () ) ;
#endif
printf ( L_27 ) ;
F_83 () ;
V_88 = 0 ;
V_30 = F_84 () ;
if( V_30 == '\n' ) {
if ( V_83 == NULL )
continue;
F_85 ( V_83 ) ;
V_83 = NULL ;
V_30 = F_86 () ;
}
switch ( V_30 ) {
case 'm' :
V_30 = F_86 () ;
switch ( V_30 ) {
case 'm' :
case 's' :
case 'd' :
F_87 ( V_30 ) ;
break;
case 'l' :
F_88 () ;
break;
case 'z' :
F_89 () ;
break;
case 'i' :
F_90 ( 0 ) ;
break;
default:
V_88 = V_30 ;
F_91 () ;
}
break;
case 'd' :
F_92 () ;
break;
case 'l' :
F_93 () ;
break;
case 'r' :
F_94 ( V_59 ) ;
break;
case 'e' :
F_33 ( V_59 ) ;
break;
case 'S' :
F_95 () ;
break;
case 't' :
F_96 ( V_59 ) ;
break;
case 'f' :
F_97 () ;
break;
case 's' :
if ( F_98 () == 0 )
break;
if ( F_99 ( V_59 ) )
return V_30 ;
break;
case 'x' :
case 'X' :
return V_30 ;
case V_58 :
printf ( L_28 ) ;
F_100 ( 2000 ) ;
return V_30 ;
case '?' :
F_101 ( V_89 ) ;
break;
case '#' :
F_79 () ;
break;
case 'b' :
F_102 () ;
break;
case 'C' :
F_103 () ;
break;
case 'c' :
if ( F_104 () )
return 0 ;
break;
case 'z' :
F_105 () ;
break;
case 'p' :
F_106 () ;
break;
#ifdef F_107
case 'u' :
F_108 () ;
break;
#elif F_24 ( V_90 )
case 'u' :
F_109 () ;
break;
#elif F_24 ( V_26 )
case 'u' :
F_110 () ;
break;
#endif
default:
printf ( L_29 ) ;
do {
if ( ' ' < V_30 && V_30 <= '~' )
putchar ( V_30 ) ;
else
printf ( L_30 , V_30 ) ;
V_30 = F_86 () ;
} while ( V_30 != '\n' );
printf ( L_31 ) ;
break;
}
}
}
static int F_99 ( struct V_23 * V_24 )
{
V_24 -> V_27 |= V_55 ;
F_8 ( V_91 , F_111 ( V_91 ) | V_92 | V_93 ) ;
return 1 ;
}
static int F_99 ( struct V_23 * V_24 )
{
unsigned int V_56 ;
int V_57 ;
if ( ( V_24 -> V_27 & ( V_52 | V_51 | V_50 ) ) == ( V_52 | V_50 ) ) {
if ( F_74 ( V_24 -> V_39 , & V_56 , 4 ) == 4 ) {
V_57 = F_54 ( V_24 , V_56 ) ;
if ( V_57 < 0 ) {
printf ( L_14 ,
( F_55 ( V_56 ) ? L_15 : L_16 ) ) ;
return 0 ;
}
if ( V_57 > 0 ) {
V_24 -> V_42 = 0xd00 | ( V_24 -> V_42 & 1 ) ;
printf ( L_32 ) ;
F_38 ( V_24 -> V_39 , L_7 , L_33 ) ;
F_47 ( V_24 -> V_39 , 1 , 0 ) ;
return 0 ;
}
}
}
V_24 -> V_27 |= V_94 ;
return 1 ;
}
static void F_105 ( void )
{
int V_30 ;
V_30 = F_86 () ;
if ( V_30 == 'r' )
V_95 . V_96 ( NULL ) ;
else if ( V_30 == 'h' )
V_95 . V_97 () ;
else if ( V_30 == 'p' )
if ( V_98 )
V_98 () ;
}
static int F_104 ( void )
{
#ifdef F_26
unsigned long V_37 , V_99 , V_100 ;
int V_20 ;
if ( ! F_80 ( & V_37 ) ) {
printf ( L_34 ) ;
V_100 = V_99 = V_101 ;
F_112 (cpu) {
if ( F_32 ( V_37 , & V_22 ) ) {
if ( V_37 == V_100 + 1 ) {
V_100 = V_37 ;
} else {
if ( V_100 != V_99 )
printf ( L_35 , V_100 ) ;
V_100 = V_99 = V_37 ;
printf ( L_36 , V_37 ) ;
}
}
}
if ( V_100 != V_99 )
printf ( L_35 , V_100 ) ;
printf ( L_33 ) ;
return 0 ;
}
if ( ! F_32 ( V_37 , & V_22 ) ) {
printf ( L_37 , V_37 ) ;
return 0 ;
}
V_47 = 0 ;
F_43 () ;
V_48 = V_37 ;
V_20 = 10000000 ;
while ( ! V_47 ) {
if ( -- V_20 == 0 ) {
if ( F_40 ( 0 , & V_47 ) )
break;
F_43 () ;
V_48 = F_17 () ;
printf ( L_38 , V_37 ) ;
return 0 ;
}
F_41 () ;
}
return 1 ;
#else
return 0 ;
#endif
}
static void
F_103 ( void )
{
unsigned int V_68 ;
unsigned short V_102 ;
unsigned char V_103 ;
if ( ! F_80 ( & V_104 ) )
return;
if ( ! F_80 ( & V_105 ) )
return;
V_102 = 0xffff ;
for ( V_68 = 0 ; V_68 < V_105 ; ++ V_68 ) {
if ( F_74 ( V_104 + V_68 , & V_103 , 1 ) == 0 ) {
printf ( L_39 V_106 L_33 , V_104 + V_68 ) ;
break;
}
V_102 = F_113 ( V_102 , V_103 ) ;
}
printf ( L_40 , V_102 ) ;
}
static long F_114 ( unsigned long V_6 )
{
unsigned int V_56 ;
V_6 &= ~ 3 ;
if ( ! F_115 ( V_6 ) ) {
printf ( L_41 ) ;
return 0 ;
}
if ( ! F_74 ( V_6 , & V_56 , sizeof( V_56 ) ) ) {
printf ( L_42 , V_6 ) ;
return 0 ;
}
if ( F_75 ( V_56 ) || F_55 ( V_56 ) ) {
printf ( L_43
L_44 ) ;
return 0 ;
}
return 1 ;
}
static void
F_102 ( void )
{
int V_30 ;
unsigned long V_73 ;
int V_107 , V_68 ;
struct V_31 * V_32 ;
const char V_108 [] = L_45
L_46 ;
V_30 = F_86 () ;
switch ( V_30 ) {
#ifndef F_116
case 'd' :
V_107 = 7 ;
V_30 = F_86 () ;
if ( V_30 == 'r' )
V_107 = 5 ;
else if ( V_30 == 'w' )
V_107 = 6 ;
else
V_88 = V_30 ;
V_63 . V_40 = 0 ;
V_63 . V_64 = 0 ;
if ( F_80 ( & V_63 . V_40 ) ) {
if ( ! F_115 ( V_63 . V_40 ) ) {
printf ( V_108 ) ;
break;
}
V_63 . V_40 &= ~ V_79 ;
V_63 . V_64 = V_107 | V_109 ;
}
break;
case 'i' :
if ( ! F_7 ( V_3 ) ) {
printf ( L_47
L_48 ) ;
break;
}
if ( V_65 ) {
V_65 -> V_64 &= ~ V_76 ;
V_65 = NULL ;
}
if ( ! F_80 ( & V_73 ) )
break;
if ( ! F_114 ( V_73 ) )
break;
V_32 = F_72 ( V_73 ) ;
if ( V_32 != NULL ) {
V_32 -> V_64 |= V_76 ;
V_65 = V_32 ;
}
break;
#endif
case 'c' :
if ( ! F_80 ( & V_73 ) ) {
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 )
V_69 [ V_68 ] . V_64 = 0 ;
V_65 = NULL ;
V_63 . V_64 = 0 ;
printf ( L_49 ) ;
break;
}
if ( V_73 <= V_70 && V_73 >= 1 ) {
V_32 = & V_69 [ V_73 - 1 ] ;
} else {
V_32 = F_36 ( V_73 ) ;
if ( V_32 == NULL ) {
printf ( L_50 , V_73 ) ;
break;
}
}
printf ( L_51 , F_37 ( V_32 ) ) ;
F_38 ( V_32 -> V_40 , L_7 , L_8 ) ;
V_32 -> V_64 = 0 ;
break;
default:
V_88 = V_30 ;
V_30 = F_84 () ;
if ( V_30 == '?' ) {
printf ( V_110 ) ;
break;
}
V_88 = V_30 ;
if ( ! F_80 ( & V_73 ) ) {
printf ( L_52 ) ;
if ( V_63 . V_64 ) {
printf ( L_53 V_106 L_54 , V_63 . V_40 ) ;
if ( V_63 . V_64 & 1 )
printf ( L_55 ) ;
if ( V_63 . V_64 & 2 )
printf ( L_56 ) ;
printf ( L_57 ) ;
}
for ( V_32 = V_69 ; V_32 < & V_69 [ V_70 ] ; ++ V_32 ) {
if ( ! V_32 -> V_64 )
continue;
printf ( L_58 , F_37 ( V_32 ) ,
( V_32 -> V_64 & V_76 ) ? L_59 : L_60 ) ;
F_38 ( V_32 -> V_40 , L_61 , L_33 ) ;
}
break;
}
if ( ! F_114 ( V_73 ) )
break;
V_32 = F_72 ( V_73 ) ;
if ( V_32 != NULL )
V_32 -> V_64 |= V_75 ;
break;
}
}
static
const char * F_34 ( unsigned long V_111 )
{
char * V_112 ;
switch ( V_111 ) {
case 0x100 : V_112 = L_62 ; break;
case 0x200 : V_112 = L_63 ; break;
case 0x300 : V_112 = L_64 ; break;
case 0x380 : V_112 = L_65 ; break;
case 0x400 : V_112 = L_66 ; break;
case 0x480 : V_112 = L_67 ; break;
case 0x500 : V_112 = L_68 ; break;
case 0x600 : V_112 = L_69 ; break;
case 0x700 : V_112 = L_70 ; break;
case 0x800 : V_112 = L_71 ; break;
case 0x900 : V_112 = L_72 ; break;
case 0x980 : V_112 = L_73 ; break;
case 0xa00 : V_112 = L_74 ; break;
case 0xc00 : V_112 = L_75 ; break;
case 0xd00 : V_112 = L_76 ; break;
case 0xe40 : V_112 = L_77 ; break;
case 0xe60 : V_112 = L_78 ; break;
case 0xe80 : V_112 = L_79 ; break;
case 0xf00 : V_112 = L_80 ; break;
case 0xf20 : V_112 = L_81 ; break;
case 0x1300 : V_112 = L_82 ; break;
case 0x1500 : V_112 = L_83 ; break;
case 0x1700 : V_112 = L_84 ; break;
default: V_112 = L_85 ;
}
return V_112 ;
}
static void F_117 ( unsigned long V_67 , unsigned long * V_113 ,
unsigned long * V_114 )
{
unsigned long V_115 , V_35 ;
const char * V_116 ;
* V_113 = * V_114 = 0 ;
if ( V_67 == 0 )
return;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_116 = F_118 ( V_67 , & V_115 , & V_35 , NULL , V_118 ) ;
if ( V_116 != NULL ) {
* V_113 = V_67 - V_35 ;
* V_114 = V_67 - V_35 + V_115 ;
}
F_2 () ;
}
V_66 = 0 ;
}
static void F_82 ( unsigned long V_119 , unsigned long V_120 ,
unsigned long V_67 )
{
int V_121 = 64 ;
unsigned long V_122 ;
unsigned long V_123 ;
unsigned long V_124 ;
struct V_23 V_24 ;
while ( V_121 -- ) {
if ( V_119 < V_125 ) {
if ( V_119 != 0 )
printf ( L_86 , V_119 ) ;
break;
}
if ( ! F_74 ( V_119 + V_126 , & V_122 , sizeof( unsigned long ) )
|| ! F_74 ( V_119 , & V_123 , sizeof( unsigned long ) ) ) {
printf ( L_87 , V_119 ) ;
break;
}
if ( ( V_67 | V_120 ) != 0 ) {
unsigned long V_127 , V_128 ;
unsigned long V_129 ;
int V_130 = 1 ;
F_117 ( V_67 , & V_127 , & V_128 ) ;
V_129 = 0 ;
if ( V_123 > V_119 )
F_74 ( V_123 + V_126 , & V_129 ,
sizeof( unsigned long ) ) ;
if ( V_120 == V_122 ) {
if ( V_120 < V_125
|| ( V_127 <= V_120 && V_120 < V_128 ) )
V_130 = 0 ;
} else if ( V_120 == V_129 ) {
V_130 = 0 ;
} else if ( V_120 >= V_125
&& ! ( V_127 <= V_120 && V_120 < V_128 ) ) {
printf ( L_88 ) ;
F_38 ( V_120 , L_7 , L_33 ) ;
}
if ( V_130 ) {
printf ( L_89 V_106 L_90 , V_119 ) ;
F_38 ( V_122 , L_7 , L_91 ) ;
}
V_67 = V_120 = 0 ;
} else {
printf ( L_89 V_106 L_90 , V_119 ) ;
F_38 ( V_122 , L_7 , L_33 ) ;
}
if ( F_74 ( V_119 + V_131 , & V_124 , sizeof( unsigned long ) )
&& V_124 == V_132 ) {
if ( F_74 ( V_119 + V_133 , & V_24 , sizeof( V_24 ) )
!= sizeof( V_24 ) ) {
printf ( L_92 ,
V_119 + V_133 ) ;
break;
}
printf ( L_93 , V_24 . V_42 ,
F_34 ( F_35 ( & V_24 ) ) ) ;
V_67 = V_24 . V_39 ;
V_120 = V_24 . V_87 ;
F_38 ( V_67 , L_7 , L_33 ) ;
}
if ( V_123 == 0 )
break;
V_119 = V_123 ;
}
}
static void F_96 ( struct V_23 * V_59 )
{
unsigned long V_119 ;
if ( F_80 ( & V_119 ) )
F_82 ( V_119 , 0 , 0 ) ;
else
F_82 ( V_59 -> V_86 [ 1 ] , V_59 -> V_87 , V_59 -> V_39 ) ;
F_119 () ;
}
static void F_120 ( struct V_23 * V_24 )
{
#ifdef F_121
const struct V_134 * V_135 ;
unsigned long V_6 ;
if ( V_24 -> V_27 & V_51 )
return;
V_6 = V_24 -> V_39 ;
if ( V_6 < V_125 )
return;
V_135 = F_122 ( V_24 -> V_39 ) ;
if ( V_135 == NULL )
return;
if ( F_123 ( V_135 ) )
return;
#ifdef F_124
printf ( L_94 ,
V_135 -> V_136 , V_135 -> line ) ;
#else
printf ( L_95 , ( void * ) V_135 -> V_137 ) ;
#endif
#endif
}
static void F_33 ( struct V_23 * V_138 )
{
unsigned long V_42 ;
#ifdef F_26
printf ( L_96 , F_17 () ) ;
#endif
V_42 = F_35 ( V_138 ) ;
printf ( L_97 , V_138 -> V_42 , F_34 ( V_42 ) , V_138 ) ;
printf ( L_98 ) ;
F_38 ( V_138 -> V_39 , L_99 , L_33 ) ;
printf ( L_100 , V_138 -> V_87 ) ;
F_38 ( V_138 -> V_87 , L_99 , L_33 ) ;
printf ( L_101 , V_138 -> V_86 [ 1 ] ) ;
printf ( L_102 , V_138 -> V_27 ) ;
if ( V_42 == 0x300 || V_42 == 0x380 || V_42 == 0x600 || V_42 == 0x200 ) {
printf ( L_103 , V_138 -> V_139 ) ;
if ( V_42 != 0x380 )
printf ( L_104 , V_138 -> V_140 ) ;
}
printf ( L_105 , V_141 ) ;
#ifdef F_125
printf ( L_106 ,
V_142 , V_142 -> V_143 , V_142 -> V_144 ) ;
#endif
if ( V_141 ) {
printf ( L_107 ,
V_141 -> V_145 , V_141 -> V_146 ) ;
}
if ( V_42 == 0x700 )
F_120 ( V_138 ) ;
}
static void F_94 ( struct V_23 * V_138 )
{
int V_147 , V_42 ;
unsigned long V_148 ;
struct V_23 V_24 ;
if ( F_80 ( & V_148 ) ) {
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_24 = * (struct V_23 * ) V_148 ;
F_2 () ;
F_126 ( 200 ) ;
} else {
V_66 = 0 ;
printf ( L_108 V_106 L_33 ,
V_148 ) ;
return;
}
V_66 = 0 ;
V_138 = & V_24 ;
}
#ifdef F_125
if ( F_127 ( V_138 ) ) {
for ( V_147 = 0 ; V_147 < 16 ; ++ V_147 )
printf ( L_109 V_106 L_110 V_106 L_33 ,
V_147 , V_138 -> V_86 [ V_147 ] , V_147 + 16 , V_138 -> V_86 [ V_147 + 16 ] ) ;
} else {
for ( V_147 = 0 ; V_147 < 7 ; ++ V_147 )
printf ( L_109 V_106 L_110 V_106 L_33 ,
V_147 , V_138 -> V_86 [ V_147 ] , V_147 + 7 , V_138 -> V_86 [ V_147 + 7 ] ) ;
}
#else
for ( V_147 = 0 ; V_147 < 32 ; ++ V_147 ) {
printf ( L_111 , V_147 , V_138 -> V_86 [ V_147 ] ,
( V_147 & 3 ) == 3 ? L_33 : L_112 ) ;
if ( V_147 == 12 && ! F_127 ( V_138 ) ) {
printf ( L_33 ) ;
break;
}
}
#endif
printf ( L_113 ) ;
F_38 ( V_138 -> V_39 , L_7 , L_33 ) ;
if ( F_35 ( V_138 ) != 0xc00 && F_7 ( V_149 ) ) {
printf ( L_114 ) ;
F_38 ( V_138 -> V_150 , L_7 , L_33 ) ;
}
printf ( L_115 ) ;
F_38 ( V_138 -> V_87 , L_7 , L_33 ) ;
printf ( L_116 V_106 L_117 , V_138 -> V_27 , V_138 -> V_151 ) ;
printf ( L_118 V_106 L_119 V_106 L_120 ,
V_138 -> V_152 , V_138 -> V_153 , V_138 -> V_42 ) ;
V_42 = F_35 ( V_138 ) ;
if ( V_42 == 0x300 || V_42 == 0x380 || V_42 == 0x600 )
printf ( L_121 V_106 L_122 , V_138 -> V_139 , V_138 -> V_140 ) ;
}
static void F_97 ( void )
{
int V_30 ;
unsigned long V_154 ;
V_30 = F_86 () ;
if ( V_30 != 'i' )
V_88 = V_30 ;
F_80 ( ( void * ) & V_104 ) ;
if ( V_88 != '\n' )
V_88 = 0 ;
V_154 = 1 ;
F_80 ( & V_154 ) ;
V_154 = ( V_154 + V_155 - 1 ) / V_155 ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
if ( V_30 != 'i' ) {
for (; V_154 > 0 ; -- V_154 , V_104 += V_155 )
F_4 ( ( void * ) V_104 ) ;
} else {
for (; V_154 > 0 ; -- V_154 , V_104 += V_155 )
F_5 ( ( void * ) V_104 ) ;
}
F_2 () ;
F_126 ( 200 ) ;
}
V_66 = 0 ;
}
static unsigned long
F_128 ( int V_147 )
{
unsigned int V_156 [ 2 ] ;
unsigned long ( * V_157 ) ( void ) ;
unsigned long V_112 = - 1UL ;
#ifdef F_125
unsigned long V_158 [ 3 ] ;
V_158 [ 0 ] = ( unsigned long ) V_156 ;
V_158 [ 1 ] = 0 ;
V_158 [ 2 ] = 0 ;
V_157 = ( unsigned long ( * ) ( void ) ) V_158 ;
#else
V_157 = ( unsigned long ( * ) ( void ) ) V_156 ;
#endif
V_156 [ 0 ] = 0x7c6002a6 + ( ( V_147 & 0x1F ) << 16 ) + ( ( V_147 & 0x3e0 ) << 6 ) ;
V_156 [ 1 ] = 0x4e800020 ;
F_3 ( V_156 ) ;
F_3 ( V_156 + 1 ) ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_112 = V_157 () ;
F_2 () ;
F_126 ( 200 ) ;
V_147 = V_115 ;
}
return V_112 ;
}
static void
F_129 ( int V_147 , unsigned long V_159 )
{
unsigned int V_156 [ 2 ] ;
unsigned long ( * V_157 ) ( unsigned long ) ;
#ifdef F_125
unsigned long V_158 [ 3 ] ;
V_158 [ 0 ] = ( unsigned long ) V_156 ;
V_158 [ 1 ] = 0 ;
V_158 [ 2 ] = 0 ;
V_157 = ( unsigned long (*) ( unsigned long ) ) V_158 ;
#else
V_157 = ( unsigned long (*) ( unsigned long ) ) V_156 ;
#endif
V_156 [ 0 ] = 0x7c6003a6 + ( ( V_147 & 0x1F ) << 16 ) + ( ( V_147 & 0x3e0 ) << 6 ) ;
V_156 [ 1 ] = 0x4e800020 ;
F_3 ( V_156 ) ;
F_3 ( V_156 + 1 ) ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_157 ( V_159 ) ;
F_2 () ;
F_126 ( 200 ) ;
V_147 = V_115 ;
}
}
static void F_95 ( void )
{
int V_30 ;
unsigned long V_159 ;
V_30 = F_84 () ;
if ( V_30 == '\n' ) {
unsigned long V_119 , V_160 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_123 V_106 L_124 V_106 L_33 ,
F_130 () , F_111 ( V_161 ) ) ;
printf ( L_125 V_106 L_126 V_106 L_33 ,
F_111 ( V_162 ) , F_111 ( V_163 ) ) ;
printf ( L_127 V_106 L_128 V_106 L_33 ,
F_111 ( V_164 ) , F_111 ( V_165 ) ) ;
printf ( L_129 V_106 L_130 V_106 L_33 , V_119 , F_111 ( V_166 ) ) ;
printf ( L_131 V_106 L_132 V_106 L_33 , V_160 , F_111 ( V_167 ) ) ;
return;
}
F_80 ( & V_168 ) ;
switch ( V_30 ) {
case 'w' :
V_159 = F_128 ( V_168 ) ;
F_80 ( & V_159 ) ;
F_129 ( V_168 , V_159 ) ;
case 'r' :
printf ( L_133 , V_168 , F_128 ( V_168 ) ) ;
break;
}
F_119 () ;
}
static int
F_74 ( unsigned long V_104 , void * V_169 , int V_115 )
{
volatile int V_147 ;
char * V_2 , * V_170 ;
V_147 = 0 ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_2 = ( char * ) V_104 ;
V_170 = ( char * ) V_169 ;
switch ( V_115 ) {
case 2 :
* ( V_171 * ) V_170 = * ( V_171 * ) V_2 ;
break;
case 4 :
* ( V_172 * ) V_170 = * ( V_172 * ) V_2 ;
break;
case 8 :
* ( V_173 * ) V_170 = * ( V_173 * ) V_2 ;
break;
default:
for( ; V_147 < V_115 ; ++ V_147 ) {
* V_170 ++ = * V_2 ++ ;
F_2 () ;
}
}
F_2 () ;
F_126 ( 200 ) ;
V_147 = V_115 ;
}
V_66 = 0 ;
return V_147 ;
}
static int
F_76 ( unsigned long V_104 , void * V_169 , int V_115 )
{
volatile int V_147 ;
char * V_2 , * V_170 ;
V_147 = 0 ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_2 = ( char * ) V_104 ;
V_170 = ( char * ) V_169 ;
switch ( V_115 ) {
case 2 :
* ( V_171 * ) V_2 = * ( V_171 * ) V_170 ;
break;
case 4 :
* ( V_172 * ) V_2 = * ( V_172 * ) V_170 ;
break;
case 8 :
* ( V_173 * ) V_2 = * ( V_173 * ) V_170 ;
break;
default:
for ( ; V_147 < V_115 ; ++ V_147 ) {
* V_2 ++ = * V_170 ++ ;
F_2 () ;
}
}
F_2 () ;
F_126 ( 200 ) ;
V_147 = V_115 ;
} else {
printf ( L_134 V_106 L_33 , V_104 + V_147 ) ;
}
V_66 = 0 ;
return V_147 ;
}
static int F_70 ( struct V_23 * V_24 )
{
V_174 = F_35 ( V_24 ) ;
switch ( F_35 ( V_24 ) ) {
case 0x200 :
V_175 = 0 ;
break;
case 0x300 :
case 0x380 :
V_175 = 1 ;
break;
default:
V_175 = 2 ;
}
longjmp ( V_117 , 1 ) ;
return 0 ;
}
static void
F_131 ( unsigned char * V_159 , int V_115 )
{
int V_176 ;
switch ( V_115 ) {
case 2 :
F_132 ( V_159 [ 0 ] , V_159 [ 1 ] , V_176 ) ;
break;
case 4 :
F_132 ( V_159 [ 0 ] , V_159 [ 3 ] , V_176 ) ;
F_132 ( V_159 [ 1 ] , V_159 [ 2 ] , V_176 ) ;
break;
case 8 :
F_132 ( V_159 [ 0 ] , V_159 [ 7 ] , V_176 ) ;
F_132 ( V_159 [ 1 ] , V_159 [ 6 ] , V_176 ) ;
F_132 ( V_159 [ 2 ] , V_159 [ 5 ] , V_176 ) ;
F_132 ( V_159 [ 3 ] , V_159 [ 4 ] , V_176 ) ;
break;
}
}
static void
F_91 ( void )
{
int V_30 , V_177 , V_68 , V_178 ;
unsigned long V_147 ;
unsigned char V_159 [ 16 ] ;
F_80 ( ( void * ) & V_104 ) ;
V_30 = F_84 () ;
if ( V_30 == '?' ) {
printf ( V_179 ) ;
return;
} else {
V_88 = V_30 ;
}
V_83 = L_135 ;
while ( ( V_30 = F_84 () ) != '\n' ) {
switch( V_30 ) {
case 'b' : V_115 = 1 ; break;
case 'w' : V_115 = 2 ; break;
case 'l' : V_115 = 4 ; break;
case 'd' : V_115 = 8 ; break;
case 'r' : V_180 = ! V_180 ; break;
case 'n' : V_181 = 1 ; break;
case '.' : V_181 = 0 ; break;
}
}
if( V_115 <= 0 )
V_115 = 1 ;
else if( V_115 > 8 )
V_115 = 8 ;
for(; ; ) {
if ( ! V_181 )
V_147 = F_74 ( V_104 , V_159 , V_115 ) ;
printf ( V_106 L_136 , V_104 , V_180 ? 'r' : ' ' ) ;
if ( ! V_181 ) {
if ( V_180 )
F_131 ( V_159 , V_115 ) ;
putchar ( ' ' ) ;
for ( V_68 = 0 ; V_68 < V_147 ; ++ V_68 )
printf ( L_137 , V_159 [ V_68 ] ) ;
for (; V_68 < V_115 ; ++ V_68 )
printf ( L_138 , V_182 [ V_175 ] ) ;
}
putchar ( ' ' ) ;
V_177 = V_115 ;
V_178 = 0 ;
for(; ; ) {
if( F_80 ( & V_147 ) ) {
for ( V_68 = 0 ; V_68 < V_115 ; ++ V_68 )
V_159 [ V_68 ] = V_147 >> ( V_68 * 8 ) ;
if ( ! V_180 )
F_131 ( V_159 , V_115 ) ;
F_76 ( V_104 , V_159 , V_115 ) ;
V_177 = V_115 ;
}
V_30 = F_84 () ;
if ( V_30 == '\n' )
break;
V_177 = 0 ;
switch ( V_30 ) {
case '\'' :
for(; ; ) {
V_147 = F_86 () ;
if( V_147 == '\\' )
V_147 = F_133 () ;
else if( V_147 == '\'' )
break;
for ( V_68 = 0 ; V_68 < V_115 ; ++ V_68 )
V_159 [ V_68 ] = V_147 >> ( V_68 * 8 ) ;
if ( ! V_180 )
F_131 ( V_159 , V_115 ) ;
F_76 ( V_104 , V_159 , V_115 ) ;
V_104 += V_115 ;
}
V_104 -= V_115 ;
V_177 = V_115 ;
break;
case ',' :
V_104 += V_115 ;
break;
case '.' :
V_181 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_58 :
F_119 () ;
return;
case 'b' :
case 'v' :
V_115 = 1 ;
break;
case 'w' :
V_115 = 2 ;
break;
case 'l' :
V_115 = 4 ;
break;
case 'u' :
V_115 = 8 ;
break;
case '^' :
V_104 -= V_115 ;
break;
case '/' :
if ( V_178 > 0 )
V_104 -= 1 << V_178 ;
else
V_178 = 0 ;
V_178 += 4 ;
V_104 += 1 << V_178 ;
break;
case '\\' :
if ( V_178 < 0 )
V_104 += 1 << - V_178 ;
else
V_178 = 0 ;
V_178 -= 4 ;
V_104 -= 1 << - V_178 ;
break;
case 'm' :
F_80 ( ( void * ) & V_104 ) ;
break;
case 'n' :
V_181 = 1 ;
break;
case 'r' :
V_180 = ! V_180 ;
break;
case '<' :
V_147 = V_115 ;
F_80 ( & V_147 ) ;
V_104 -= V_147 ;
break;
case '>' :
V_147 = V_115 ;
F_80 ( & V_147 ) ;
V_104 += V_147 ;
break;
case '?' :
printf ( V_183 ) ;
break;
}
}
V_104 += V_177 ;
}
}
static int
F_133 ( void )
{
int V_184 ;
V_184 = F_86 () ;
switch( V_184 ) {
case 'n' : V_184 = '\n' ; break;
case 'r' : V_184 = '\r' ; break;
case 'b' : V_184 = '\b' ; break;
case 't' : V_184 = '\t' ; break;
}
return V_184 ;
}
static void F_134 ( unsigned long V_104 , long V_185 )
{
long V_147 , V_186 , V_187 , V_188 ;
unsigned char V_189 [ 16 ] ;
for ( V_147 = V_185 ; V_147 > 0 ; ) {
V_187 = V_147 < 16 ? V_147 : 16 ;
V_188 = F_74 ( V_104 , V_189 , V_187 ) ;
V_104 += V_188 ;
for ( V_186 = 0 ; V_186 < V_187 ; ++ V_186 ) {
if ( V_186 < V_188 )
printf ( L_137 , V_189 [ V_186 ] ) ;
else
printf ( L_138 , V_182 [ V_175 ] ) ;
}
V_147 -= V_187 ;
if ( V_188 < V_187 )
break;
}
printf ( L_33 ) ;
}
static void F_135 ( int V_37 )
{
struct V_190 * V_2 ;
#ifdef F_136
int V_68 = 0 ;
#endif
if ( setjmp ( V_117 ) != 0 ) {
printf ( L_139 , V_37 ) ;
return;
}
V_66 = 1 ;
F_2 () ;
V_2 = & V_191 [ V_37 ] ;
printf ( L_140 , V_37 , V_2 ) ;
printf ( L_141 , 20 , L_142 , F_137 ( V_37 ) ? L_143 : L_144 ) ;
printf ( L_141 , 20 , L_145 , F_138 ( V_37 ) ? L_143 : L_144 ) ;
printf ( L_141 , 20 , L_146 , F_139 ( V_37 ) ? L_143 : L_144 ) ;
#define F_140 ( V_191 , V_116 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 20, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_140 ( V_2 , V_192 , L_147 ) ;
F_140 ( V_2 , V_193 , L_147 ) ;
F_140 ( V_2 , V_194 , L_148 ) ;
F_140 ( V_2 , V_195 , L_148 ) ;
F_140 ( V_2 , V_196 , L_148 ) ;
F_140 ( V_2 , V_197 , L_149 ) ;
#ifdef F_141
F_140 ( V_2 , V_198 , L_149 ) ;
F_140 ( V_2 , V_199 , L_147 ) ;
F_140 ( V_2 , V_200 , L_147 ) ;
#endif
F_140 ( V_2 , V_201 , L_148 ) ;
F_140 ( V_2 , V_202 , L_147 ) ;
F_140 ( V_2 , V_203 , L_147 ) ;
F_140 ( V_2 , V_204 , L_147 ) ;
#ifdef F_136
for ( V_68 = 0 ; V_68 < V_205 ; V_68 ++ ) {
V_173 V_206 , V_207 ;
if ( ! V_2 -> V_208 )
continue;
V_206 = F_142 ( V_2 -> V_208 -> V_209 [ V_68 ] . V_206 ) ;
V_207 = F_142 ( V_2 -> V_208 -> V_209 [ V_68 ] . V_207 ) ;
if ( V_206 || V_207 ) {
printf ( L_150 ,
V_68 , V_206 , V_207 ) ;
}
}
F_140 ( V_2 , V_210 , L_147 ) ;
F_140 ( V_2 , V_211 , L_147 ) ;
for ( V_68 = 0 ; V_68 < V_212 ; V_68 ++ )
printf ( L_151 , V_68 , V_2 -> V_213 [ V_68 ] ) ;
#endif
F_140 ( V_2 , V_214 , L_152 ) ;
#ifdef V_26
F_140 ( V_2 , V_215 , L_149 ) ;
F_140 ( V_2 , V_216 , L_149 ) ;
F_140 ( V_2 , V_217 , L_149 ) ;
F_140 ( V_2 , V_218 , L_149 ) ;
F_140 ( V_2 , V_219 , L_149 ) ;
F_140 ( V_2 , V_220 , L_149 ) ;
#endif
F_140 ( V_2 , V_221 , L_149 ) ;
F_140 ( V_2 , V_222 , L_148 ) ;
F_140 ( V_2 , V_223 , L_148 ) ;
F_140 ( V_2 , V_224 , L_148 ) ;
F_140 ( V_2 , V_225 , L_147 ) ;
F_140 ( V_2 , V_143 , L_147 ) ;
F_140 ( V_2 , V_144 , L_147 ) ;
F_140 ( V_2 , V_226 , L_147 ) ;
F_140 ( V_2 , V_227 , L_147 ) ;
F_140 ( V_2 , V_228 , L_147 ) ;
F_140 ( V_2 , V_229 , L_152 ) ;
#ifdef F_143
F_140 ( V_2 , V_230 , L_152 ) ;
#endif
#ifdef F_144
F_140 ( V_2 , V_231 , L_149 ) ;
F_140 ( V_2 , V_232 , L_147 ) ;
F_140 ( V_2 , V_233 , L_147 ) ;
F_140 ( V_2 , V_234 , L_147 ) ;
#endif
F_140 ( V_2 , V_235 , L_152 ) ;
F_140 ( V_2 , V_236 , L_152 ) ;
F_140 ( V_2 , V_237 , L_152 ) ;
F_140 ( V_2 , V_238 , L_152 ) ;
F_140 ( V_2 , V_239 , L_152 ) ;
F_140 ( V_2 , V_240 , L_152 ) ;
F_140 ( V_2 , V_241 , L_152 ) ;
F_140 ( V_2 , V_242 , L_152 ) ;
#undef F_140
V_66 = 0 ;
F_2 () ;
}
static void F_145 ( void )
{
int V_37 ;
if ( F_146 () == 0 ) {
printf ( L_153 ) ;
return;
}
F_112 (cpu)
F_135 ( V_37 ) ;
}
static void F_147 ( void )
{
unsigned long V_243 ;
int V_184 ;
V_184 = F_86 () ;
if ( V_184 == 'a' ) {
F_145 () ;
return;
}
V_88 = V_184 ;
if ( F_80 ( & V_243 ) )
F_135 ( V_243 ) ;
else
F_135 ( V_48 ) ;
}
static void
F_92 ( void )
{
int V_184 ;
V_184 = F_86 () ;
#ifdef F_125
if ( V_184 == 'p' ) {
F_148 () ;
F_147 () ;
F_149 () ;
return;
}
#endif
if ( ( isxdigit ( V_184 ) && V_184 != 'f' && V_184 != 'd' ) || V_184 == '\n' )
V_88 = V_184 ;
F_80 ( ( void * ) & V_104 ) ;
if ( V_88 != '\n' )
V_88 = 0 ;
if ( V_184 == 'i' ) {
F_80 ( & V_244 ) ;
if ( V_244 == 0 )
V_244 = 16 ;
else if ( V_244 > V_245 )
V_244 = V_245 ;
V_104 += F_47 ( V_104 , V_244 , 1 ) ;
V_83 = L_154 ;
} else if ( V_184 == 'l' ) {
F_150 () ;
} else if ( V_184 == 'r' ) {
F_80 ( & V_185 ) ;
if ( V_185 == 0 )
V_185 = 64 ;
F_134 ( V_104 , V_185 ) ;
V_104 += V_185 ;
V_83 = L_155 ;
} else {
F_80 ( & V_185 ) ;
if ( V_185 == 0 )
V_185 = 64 ;
else if ( V_185 > V_245 )
V_185 = V_245 ;
F_151 ( V_104 , V_185 ) ;
V_104 += V_185 ;
V_83 = L_156 ;
}
}
static void
F_151 ( unsigned long V_104 , long V_185 )
{
long V_147 , V_186 , V_184 , V_187 , V_188 ;
unsigned char V_189 [ 16 ] ;
for ( V_147 = V_185 ; V_147 > 0 ; ) {
printf ( V_106 , V_104 ) ;
putchar ( ' ' ) ;
V_187 = V_147 < 16 ? V_147 : 16 ;
V_188 = F_74 ( V_104 , V_189 , V_187 ) ;
V_104 += V_188 ;
for ( V_186 = 0 ; V_186 < V_187 ; ++ V_186 ) {
if ( ( V_186 & ( sizeof( long ) - 1 ) ) == 0 && V_186 > 0 )
putchar ( ' ' ) ;
if ( V_186 < V_188 )
printf ( L_137 , V_189 [ V_186 ] ) ;
else
printf ( L_138 , V_182 [ V_175 ] ) ;
}
for (; V_186 < 16 ; ++ V_186 ) {
if ( ( V_186 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_61 ) ;
}
printf ( L_157 ) ;
for ( V_186 = 0 ; V_186 < V_187 ; ++ V_186 ) {
if ( V_186 < V_188 ) {
V_184 = V_189 [ V_186 ] ;
putchar ( ' ' <= V_184 && V_184 <= '~' ? V_184 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_147 -= V_187 ;
for (; V_186 < 16 ; ++ V_186 )
putchar ( ' ' ) ;
printf ( L_158 ) ;
if ( V_188 < V_187 )
break;
}
}
static int
F_152 ( unsigned long V_246 , long V_247 , int V_248 ,
T_3 V_249 )
{
int V_188 , V_250 ;
unsigned long V_251 ;
unsigned long V_252 , V_253 = 0 ;
unsigned char V_159 [ 4 ] ;
V_250 = 0 ;
for ( V_251 = V_246 ; V_247 > 0 ; -- V_247 , V_246 += 4 ) {
V_188 = F_74 ( V_246 , V_159 , 4 ) ;
if ( V_188 == 0 ) {
if ( V_248 ) {
const char * V_254 = V_182 [ V_175 ] ;
printf ( V_106 L_159 , V_246 , V_254 , V_254 , V_254 , V_254 ) ;
}
break;
}
V_252 = F_153 ( V_159 ) ;
if ( V_246 > V_251 && V_252 == V_253 ) {
if ( ! V_250 ) {
printf ( L_160 ) ;
V_250 = 1 ;
}
continue;
}
V_250 = 0 ;
V_253 = V_252 ;
if ( V_248 )
printf ( V_106 L_161 , V_246 , V_252 ) ;
printf ( L_162 ) ;
V_249 ( V_252 , V_246 ) ;
printf ( L_33 ) ;
}
return V_246 - V_251 ;
}
static int
F_47 ( unsigned long V_246 , long V_247 , int V_248 )
{
return F_152 ( V_246 , V_247 , V_248 , V_255 ) ;
}
void
F_154 ( unsigned long V_6 )
{
F_38 ( V_6 , L_163 , L_85 ) ;
}
void
F_150 ( void )
{
struct V_256 V_257 = { . V_258 = 1 } ;
unsigned char V_169 [ 128 ] ;
T_4 V_81 ;
if ( setjmp ( V_117 ) != 0 ) {
printf ( L_164 ) ;
return;
}
V_66 = 1 ;
F_2 () ;
F_155 ( & V_257 ) ;
F_148 () ;
while ( F_156 ( & V_257 , false , V_169 , sizeof( V_169 ) , & V_81 ) ) {
V_169 [ V_81 ] = '\0' ;
printf ( L_138 , V_169 ) ;
}
F_149 () ;
F_2 () ;
F_126 ( 200 ) ;
V_66 = 0 ;
}
static void
F_87 ( int V_30 )
{
F_80 ( ( void * ) & V_259 ) ;
if( V_88 != '\n' )
V_88 = 0 ;
F_80 ( ( void * ) ( V_30 == 's' ? & V_260 : & V_261 ) ) ;
if( V_88 != '\n' )
V_88 = 0 ;
F_80 ( ( void * ) & V_262 ) ;
switch( V_30 ) {
case 'm' :
memmove ( ( void * ) V_259 , ( void * ) V_261 , V_262 ) ;
break;
case 's' :
memset ( ( void * ) V_259 , V_260 , V_262 ) ;
break;
case 'd' :
if( V_88 != '\n' )
V_88 = 0 ;
F_80 ( ( void * ) & V_263 ) ;
F_157 ( ( unsigned char * ) V_259 , ( unsigned char * ) V_261 , V_262 , V_263 ) ;
break;
}
}
static void
F_157 ( unsigned char * V_264 , unsigned char * V_265 , unsigned V_266 , unsigned V_267 )
{
unsigned V_147 , V_268 ;
V_268 = 0 ;
for( V_147 = V_266 ; V_147 > 0 ; -- V_147 )
if( * V_264 ++ != * V_265 ++ )
if( ++ V_268 <= V_267 )
printf ( L_165 , V_264 - 1 ,
V_264 [ - 1 ] , V_265 - 1 , V_265 [ - 1 ] ) ;
if( V_268 > V_267 )
printf ( L_166 , V_268 ) ;
}
static void
F_88 ( void )
{
unsigned V_73 , V_147 ;
unsigned char V_159 [ 4 ] ;
V_83 = L_167 ;
F_80 ( ( void * ) & V_259 ) ;
if ( V_88 != '\n' ) {
V_88 = 0 ;
F_80 ( ( void * ) & V_269 ) ;
if ( V_88 != '\n' ) {
V_88 = 0 ;
F_80 ( ( void * ) & V_260 ) ;
V_270 = ~ 0 ;
if ( V_88 != '\n' ) V_88 = 0 ;
F_80 ( ( void * ) & V_270 ) ;
}
}
V_147 = 0 ;
for ( V_73 = V_259 ; V_73 < V_269 ; V_73 += 4 ) {
if ( F_74 ( V_73 , V_159 , 4 ) == 4
&& ( ( F_153 ( V_159 ) ^ V_260 ) & V_270 ) == 0 ) {
printf ( L_168 , V_73 , F_153 ( V_159 ) ) ;
if ( ++ V_147 >= 10 )
break;
}
}
}
static void
F_89 ( void )
{
unsigned char V_103 ;
unsigned V_73 ;
int V_271 , V_272 ;
F_80 ( & V_259 ) ;
if ( V_88 != '\n' ) V_88 = 0 ;
F_80 ( & V_273 ) ;
if ( V_88 != '\n' ) V_88 = 0 ;
F_80 ( & V_274 ) ;
V_272 = 0 ;
for ( V_73 = V_259 ; V_73 < V_274 ; V_73 += V_273 ) {
V_271 = F_74 ( V_73 , & V_103 , 1 ) ;
if ( V_271 && ! V_272 ) {
printf ( L_169 , V_73 ) ;
} else if ( ! V_271 && V_272 )
printf ( L_170 , V_73 - V_273 ) ;
V_272 = V_271 ;
if ( V_73 + V_273 < V_73 )
break;
}
if ( V_272 )
printf ( L_170 , V_73 - V_273 ) ;
}
static void F_106 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_112 ;
int V_68 ;
typedef unsigned long (* T_5)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_5 V_275 ;
if ( ! F_80 ( & V_104 ) )
return;
if ( V_88 != '\n' )
V_88 = 0 ;
for ( V_68 = 0 ; V_68 < 8 ; ++ V_68 )
args [ V_68 ] = 0 ;
for ( V_68 = 0 ; V_68 < 8 ; ++ V_68 ) {
if ( ! F_80 ( & args [ V_68 ] ) || V_88 == '\n' )
break;
V_88 = 0 ;
}
V_275 = ( T_5 ) V_104 ;
V_112 = 0 ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_112 = V_275 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_2 () ;
printf ( L_171 , V_112 ) ;
} else {
printf ( L_172 , V_174 ) ;
}
V_66 = 0 ;
}
int
F_84 ( void )
{
int V_184 ;
if( V_88 != 0 ) {
V_184 = V_88 ;
V_88 = 0 ;
} else
V_184 = F_86 () ;
while( V_184 == ' ' || V_184 == '\t' )
V_184 = F_86 () ;
return V_184 ;
}
int
F_80 ( unsigned long * V_276 )
{
int V_184 , V_61 ;
unsigned long V_103 ;
V_184 = F_84 () ;
if ( V_184 == '%' ) {
char V_277 [ 8 ] ;
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_277 ) - 1 ; ++ V_68 ) {
V_184 = F_86 () ;
if ( ! isalnum ( V_184 ) ) {
V_88 = V_184 ;
break;
}
V_277 [ V_68 ] = V_184 ;
}
V_277 [ V_68 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_278 ; ++ V_68 ) {
if ( strcmp ( V_279 [ V_68 ] , V_277 ) == 0 ) {
if ( V_84 == NULL ) {
printf ( L_173 ) ;
return 0 ;
}
* V_276 = ( ( unsigned long * ) V_84 ) [ V_68 ] ;
return 1 ;
}
}
printf ( L_174 , V_277 ) ;
return 0 ;
}
if ( V_184 == '0' ) {
V_184 = F_86 () ;
if ( V_184 == 'x' ) {
V_184 = F_86 () ;
} else {
V_61 = F_158 ( V_184 ) ;
if ( V_61 == V_58 ) {
V_88 = V_184 ;
* V_276 = 0 ;
return 1 ;
}
}
} else if ( V_184 == '$' ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < 63 ; V_68 ++ ) {
V_184 = F_86 () ;
if ( isspace ( V_184 ) || V_184 == '\0' ) {
V_88 = V_184 ;
break;
}
V_118 [ V_68 ] = V_184 ;
}
V_118 [ V_68 ++ ] = 0 ;
* V_276 = 0 ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
* V_276 = F_159 ( V_118 ) ;
F_2 () ;
}
V_66 = 0 ;
if ( ! ( * V_276 ) ) {
printf ( L_175 , V_118 ) ;
return 0 ;
}
return 1 ;
}
V_61 = F_158 ( V_184 ) ;
if ( V_61 == V_58 ) {
V_88 = V_184 ;
return 0 ;
}
V_103 = 0 ;
do {
V_103 = ( V_103 << 4 ) + V_61 ;
V_184 = F_86 () ;
V_61 = F_158 ( V_184 ) ;
} while ( V_61 != V_58 );
V_88 = V_184 ;
* V_276 = V_103 ;
return 1 ;
}
static void
F_119 ( void )
{
int V_184 ;
V_184 = V_88 ;
V_88 = 0 ;
while( V_184 != '\n' )
V_184 = F_86 () ;
}
static int F_158 ( int V_184 )
{
if( '0' <= V_184 && V_184 <= '9' )
return V_184 - '0' ;
if( 'A' <= V_184 && V_184 <= 'F' )
return V_184 - ( 'A' - 10 ) ;
if( 'a' <= V_184 && V_184 <= 'f' )
return V_184 - ( 'a' - 10 ) ;
return V_58 ;
}
void
F_160 ( char * V_280 , int V_115 )
{
int V_184 ;
V_184 = F_84 () ;
do {
if( V_115 > 1 ) {
* V_280 ++ = V_184 ;
-- V_115 ;
}
V_184 = F_86 () ;
} while( V_184 != ' ' && V_184 != '\t' && V_184 != '\n' );
V_88 = V_184 ;
* V_280 = 0 ;
}
static void
F_83 ( void )
{
V_281 = NULL ;
}
static int
F_86 ( void )
{
if ( V_281 == NULL || * V_281 == 0 ) {
if ( F_161 ( line , sizeof( line ) ) == NULL ) {
V_281 = NULL ;
return V_58 ;
}
V_281 = line ;
}
return * V_281 ++ ;
}
static void
F_85 ( char * V_282 )
{
V_281 = V_282 ;
}
static void
F_93 ( void )
{
int type = F_86 () ;
unsigned long V_6 ;
static char V_283 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_80 ( & V_6 ) )
F_38 ( V_6 , L_99 , L_33 ) ;
V_88 = 0 ;
break;
case 's' :
F_160 ( V_283 , 64 ) ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_6 = F_159 ( V_283 ) ;
if ( V_6 )
printf ( L_176 , V_283 , V_6 ) ;
else
printf ( L_177 , V_283 ) ;
F_2 () ;
}
V_66 = 0 ;
V_88 = 0 ;
break;
}
}
static void F_38 ( unsigned long V_40 , const char * V_284 ,
const char * V_285 )
{
char * V_286 ;
const char * V_116 = NULL ;
unsigned long V_35 , V_115 ;
printf ( V_106 , V_40 ) ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_116 = F_118 ( V_40 , & V_115 , & V_35 , & V_286 ,
V_118 ) ;
F_2 () ;
F_126 ( 200 ) ;
}
V_66 = 0 ;
if ( V_116 ) {
printf ( L_178 , V_284 , V_116 , V_35 , V_115 ) ;
if ( V_286 )
printf ( L_179 , V_286 ) ;
}
printf ( L_138 , V_285 ) ;
}
void F_108 ( void )
{
int V_68 ;
unsigned long V_206 , V_207 ;
unsigned long V_287 ;
printf ( L_180 , F_17 () ) ;
for ( V_68 = 0 ; V_68 < V_288 ; V_68 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( V_206 || V_207 ) {
printf ( L_181 , V_68 , V_206 , V_207 ) ;
if ( V_206 & V_289 ) {
V_287 = V_207 & V_290 ;
if ( V_207 & V_291 ) {
printf ( L_182 ,
F_162 ( V_206 ) ,
( V_207 & ~ V_292 ) >> V_293 ,
V_287 ) ;
} else {
printf ( L_183 ,
F_163 ( V_206 ) ,
( V_207 & ~ V_292 ) >> V_294 ,
V_287 ) ;
}
} else
printf ( L_33 ) ;
}
}
}
void F_108 ( void )
{
int V_68 ;
printf ( L_184 ) ;
for ( V_68 = 0 ; V_68 < 16 ; ++ V_68 )
printf ( L_185 , F_164 ( V_68 ) ) ;
printf ( L_33 ) ;
}
static void F_109 ( void )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_295 ; V_68 ++ ) {
unsigned long V_296 , V_297 , V_298 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_186 , V_68 , V_296 , V_297 , V_298 ) ;
if ( V_296 & V_299 ) {
printf ( L_187 ,
V_296 & V_300 ,
V_297 & V_301 ,
V_297 & V_302 ,
( V_298 & V_303 ) ? 'W' : 'w' ,
( V_298 & V_304 ) ? 'I' : 'i' ,
( V_298 & V_305 ) ? 'M' : 'm' ,
( V_298 & V_306 ) ? 'G' : 'g' ,
( V_298 & V_307 ) ? 'E' : 'e' ) ;
}
printf ( L_33 ) ;
}
}
static void F_110 ( void )
{
V_172 V_308 , V_309 , V_310 ;
V_173 V_311 ;
int V_68 , V_312 , V_313 , V_314 , V_315 , V_316 , V_317 = 0 ;
int V_318 ;
static const char * V_319 [] = {
L_188 ,
L_189 ,
L_190 ,
L_191 ,
L_192 ,
L_193 ,
L_194 ,
L_195 ,
L_196 ,
L_197 ,
L_198 ,
L_199 ,
L_200 ,
L_201 ,
L_202 ,
L_203 ,
L_204 ,
L_205 ,
L_206 ,
L_207 ,
L_208 ,
L_209 ,
L_210 ,
L_211 ,
L_212 ,
L_213 ,
L_214 ,
L_215 ,
L_216 ,
L_217 ,
L_218 ,
L_219 ,
} ;
V_308 = F_111 ( V_320 ) ;
V_318 = ( V_308 & 3 ) + 1 ;
V_313 = ( ( V_308 >> 2 ) & 3 ) + 1 ;
V_314 = ( ( V_308 >> 6 ) & 0x1f ) + 1 ;
V_315 = ( V_308 >> 24 ) & 0xf ;
V_316 = ( V_308 >> 16 ) & 0x7f ;
if ( ( V_318 > 1 ) && ( V_308 & 0x10000 ) )
V_317 = 1 ;
printf ( L_220 ,
V_318 , V_313 , V_314 , V_315 , V_316 ) ;
V_309 = ( 1ul << V_314 ) - 1 ;
V_310 = ( 1ul << V_315 ) - 1 ;
V_311 = ( 1ull << V_316 ) - 1 ;
for ( V_312 = 0 ; V_312 < V_313 ; V_312 ++ ) {
V_172 V_321 ;
int V_322 , V_323 , V_324 = 1 ;
printf ( L_221 , V_312 ) ;
switch( V_312 ) {
case 0 :
V_321 = F_111 ( V_325 ) ;
break;
case 1 :
V_321 = F_111 ( V_326 ) ;
break;
case 2 :
V_321 = F_111 ( V_327 ) ;
break;
case 3 :
V_321 = F_111 ( V_328 ) ;
break;
default:
printf ( L_222 ) ;
continue;
}
V_322 = V_321 & 0xfff ;
V_323 = ( V_321 >> 24 ) & 0xff ;
for ( V_68 = 0 ; V_68 < V_322 ; V_68 ++ ) {
V_172 V_329 = F_165 ( V_312 ) ;
V_172 V_330 = F_166 ( V_331 ) ;
V_173 V_332 = 0 ;
V_173 V_333 ;
int V_334 = V_68 , V_335 = V_68 ;
if ( V_323 != 0 ) {
V_335 = V_68 / V_323 ;
V_334 = V_68 % V_323 ;
V_332 = V_335 * 0x1000 ;
}
V_329 |= F_167 ( V_334 ) ;
F_8 ( V_336 , V_329 ) ;
F_8 ( V_337 , V_330 ) ;
F_8 ( V_338 , V_332 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_330 = F_111 ( V_337 ) ;
V_332 = F_111 ( V_338 ) ;
V_333 = F_111 ( V_339 ) ;
if ( V_323 && ( V_68 % V_323 ) == 0 )
V_324 = 1 ;
if ( ! ( V_330 & V_340 ) )
continue;
if ( V_323 == 0 )
printf ( L_223 , V_68 ) ;
else if ( V_324 )
printf ( L_224 , V_335 , 'A' + V_334 ) ;
else
printf ( L_225 , 'A' + V_334 ) ;
V_324 = 0 ;
printf ( L_226 ,
V_332 & ~ 0x3ffull ,
( V_330 >> 16 ) & 0x3fff ,
V_319 [ ( V_330 >> 7 ) & 0x1f ] ,
V_330 & V_341 ? 'I' : ' ' ,
V_330 & V_342 ? 'P' : ' ' ,
V_330 & V_343 ? '1' : '0' ) ;
printf ( L_227 ,
V_332 & V_344 ? 'a' : ' ' ,
V_332 & V_345 ? 'v' : ' ' ,
V_332 & V_346 ? 'w' : ' ' ,
V_332 & V_347 ? 'i' : ' ' ,
V_332 & V_348 ? 'm' : ' ' ,
V_332 & V_349 ? 'g' : ' ' ,
V_332 & V_350 ? 'e' : ' ' ) ;
printf ( L_228 , V_333 & V_311 & ~ 0x7ffull ) ;
if ( V_330 & V_341 )
printf ( L_229 ,
V_319 [ ( V_333 >> 1 ) & 0x1f ] ) ;
else
printf ( L_230 ,
V_333 & V_351 ? 'x' : ' ' ,
V_333 & V_352 ? 'w' : ' ' ,
V_333 & V_353 ? 'r' : ' ' ,
V_333 & V_354 ? 'x' : ' ' ,
V_333 & V_355 ? 'w' : ' ' ,
V_333 & V_356 ? 'r' : ' ' ) ;
}
}
}
static void F_168 ( int V_357 )
{
if ( V_357 ) {
V_358 = F_59 ;
V_359 = F_68 ;
V_360 = F_63 ;
V_361 = F_64 ;
V_362 = F_67 ;
V_363 = F_66 ;
V_364 = F_69 ;
} else {
V_358 = NULL ;
V_359 = NULL ;
V_360 = NULL ;
V_361 = NULL ;
V_362 = NULL ;
V_363 = NULL ;
V_364 = NULL ;
}
}
static void F_169 ( int V_365 )
{
F_168 ( 1 ) ;
F_170 ( F_62 () ) ;
}
static int T_6 F_171 ( void )
{
F_172 ( 'x' , & V_366 ) ;
return 0 ;
}
static int T_6 F_173 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_231 , 5 ) == 0 ) {
F_168 ( 1 ) ;
V_367 = 1 ;
} else if ( strncmp ( V_2 , L_232 , 2 ) == 0 )
F_168 ( 1 ) ;
else if ( strncmp ( V_2 , L_233 , 3 ) == 0 )
V_368 = 1 ;
else if ( strncmp ( V_2 , L_234 , 4 ) == 0 )
V_85 = 1 ;
else
return 1 ;
return 0 ;
}
void T_6 F_174 ( void )
{
#ifdef F_175
if ( ! V_368 )
F_168 ( 1 ) ;
#endif
if ( V_367 )
F_170 ( NULL ) ;
}
void F_176 ( struct V_369 * V_370 )
{
struct V_371 * V_371 ;
F_177 (spu, list, full_list) {
if ( V_371 -> V_372 >= V_373 ) {
F_178 ( 1 ) ;
continue;
}
V_374 [ V_371 -> V_372 ] . V_371 = V_371 ;
V_374 [ V_371 -> V_372 ] . V_375 = 0 ;
V_374 [ V_371 -> V_372 ] . V_376 = ( unsigned long )
V_374 [ V_371 -> V_372 ] . V_371 -> V_377 ;
}
}
static void F_179 ( void )
{
struct V_371 * V_371 ;
int V_68 ;
V_173 V_283 ;
for ( V_68 = 0 ; V_68 < V_373 ; V_68 ++ ) {
if ( ! V_374 [ V_68 ] . V_371 )
continue;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_371 = V_374 [ V_68 ] . V_371 ;
V_374 [ V_68 ] . V_378 =
F_180 ( & V_371 -> V_379 -> V_380 ) ;
V_283 = F_181 ( V_371 ) ;
V_374 [ V_68 ] . V_381 = V_283 ;
V_283 &= ~ V_382 ;
F_182 ( V_371 , V_283 ) ;
F_2 () ;
F_126 ( 200 ) ;
V_374 [ V_68 ] . V_375 = 1 ;
printf ( L_235 , V_68 ,
V_374 [ V_68 ] . V_378 ?
L_236 : L_237 ) ;
} else {
V_66 = 0 ;
printf ( L_238 , V_68 ) ;
}
V_66 = 0 ;
}
}
static void F_183 ( void )
{
struct V_371 * V_371 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_373 ; V_68 ++ ) {
if ( ! V_374 [ V_68 ] . V_371 )
continue;
if ( ! V_374 [ V_68 ] . V_375 ) {
printf ( L_239
L_240 , V_68 ) ;
continue;
}
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_371 = V_374 [ V_68 ] . V_371 ;
F_182 ( V_371 , V_374 [ V_68 ] . V_381 ) ;
F_184 ( & V_371 -> V_379 -> V_380 ,
V_374 [ V_68 ] . V_378 ) ;
F_2 () ;
F_126 ( 200 ) ;
printf ( L_241 , V_68 ) ;
} else {
V_66 = 0 ;
printf ( L_242 , V_68 ) ;
}
V_66 = 0 ;
}
}
static void F_185 ( struct V_371 * V_371 )
{
printf ( L_243 , V_371 ) ;
F_186 ( V_371 , L_244 , V_372 ) ;
F_186 ( V_371 , L_138 , V_116 ) ;
F_186 ( V_371 , L_245 , V_383 ) ;
F_186 ( V_371 , L_246 , V_377 ) ;
F_186 ( V_371 , L_245 , V_384 ) ;
F_186 ( V_371 , L_244 , V_385 ) ;
F_186 ( V_371 , L_245 , V_36 ) ;
F_186 ( V_371 , L_247 , V_386 ) ;
F_186 ( V_371 , L_245 , V_387 ) ;
F_186 ( V_371 , L_245 , V_388 ) ;
F_186 ( V_371 , L_245 , V_389 ) ;
F_186 ( V_371 , L_245 , V_390 [ 0 ] ) ;
F_186 ( V_371 , L_245 , V_390 [ 1 ] ) ;
F_186 ( V_371 , L_245 , V_390 [ 2 ] ) ;
F_186 ( V_371 , L_244 , V_391 ) ;
F_186 ( V_371 , L_247 , V_145 ) ;
F_186 ( V_371 , L_246 , V_392 ) ;
F_186 ( V_371 , L_246 , V_393 ) ;
F_186 ( V_371 , L_246 , V_394 ) ;
F_186 ( V_371 , L_246 , V_395 ) ;
F_186 ( V_371 , L_245 , V_396 ) ;
F_186 ( V_371 , L_246 , V_379 ) ;
F_187 ( L_244 , V_379 -> V_380 ,
F_180 ( & V_371 -> V_379 -> V_380 ) ) ;
F_187 ( L_244 , V_379 -> V_397 ,
F_180 ( & V_371 -> V_379 -> V_397 ) ) ;
F_187 ( L_244 , V_379 -> V_398 ,
F_180 ( & V_371 -> V_379 -> V_398 ) ) ;
F_186 ( V_371 , L_246 , V_399 ) ;
F_186 ( V_371 , L_246 , V_400 ) ;
}
int
F_188 ( unsigned long V_246 , long V_247 , int V_248 )
{
return F_152 ( V_246 , V_247 , V_248 , V_401 ) ;
}
static void F_189 ( unsigned long V_243 , int V_402 )
{
unsigned long V_35 , V_6 , V_403 ;
if ( setjmp ( V_117 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_403 = ( unsigned long ) V_374 [ V_243 ] . V_371 -> V_377 ;
F_2 () ;
F_126 ( 200 ) ;
} else {
V_66 = 0 ;
printf ( L_248 , V_243 ) ;
return;
}
V_66 = 0 ;
if ( F_80 ( & V_35 ) )
V_6 = V_403 + V_35 ;
else
V_6 = V_374 [ V_243 ] . V_376 ;
if ( V_6 >= V_403 + V_404 ) {
printf ( L_249 ) ;
return;
}
switch ( V_402 ) {
case 'i' :
V_6 += F_188 ( V_6 , 16 , 1 ) ;
V_83 = L_250 ;
break;
default:
F_151 ( V_6 , 64 ) ;
V_6 += 64 ;
V_83 = L_251 ;
break;
}
V_374 [ V_243 ] . V_376 = V_6 ;
}
static int F_98 ( void )
{
static unsigned long V_243 = 0 ;
int V_30 , V_402 = 0 ;
V_30 = F_86 () ;
switch ( V_30 ) {
case 's' :
F_179 () ;
break;
case 'r' :
F_183 () ;
break;
case 'd' :
V_402 = F_86 () ;
if ( isxdigit ( V_402 ) || V_402 == '\n' )
V_88 = V_402 ;
case 'f' :
F_80 ( & V_243 ) ;
if ( V_243 >= V_373 || ! V_374 [ V_243 ] . V_371 ) {
printf ( L_252 ) ;
return 0 ;
}
switch ( V_30 ) {
case 'f' :
F_185 ( V_374 [ V_243 ] . V_371 ) ;
break;
default:
F_189 ( V_243 , V_402 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_98 ( void )
{
return - 1 ;
}
