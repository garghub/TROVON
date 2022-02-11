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
static int
F_48 ( struct V_23 * V_59 )
{
int V_30 = 0 ;
V_82 = NULL ;
V_83 = V_59 ;
if ( ! V_84 ) {
V_84 = 1 ;
F_79 ( V_59 -> V_85 [ 1 ] , V_59 -> V_86 , V_59 -> V_39 ) ;
}
for(; ; ) {
#ifdef F_26
printf ( L_25 , F_17 () ) ;
#endif
printf ( L_26 ) ;
F_80 () ;
V_87 = 0 ;
V_30 = F_81 () ;
if( V_30 == '\n' ) {
if ( V_82 == NULL )
continue;
F_82 ( V_82 ) ;
V_82 = NULL ;
V_30 = F_83 () ;
}
switch ( V_30 ) {
case 'm' :
V_30 = F_83 () ;
switch ( V_30 ) {
case 'm' :
case 's' :
case 'd' :
F_84 ( V_30 ) ;
break;
case 'l' :
F_85 () ;
break;
case 'z' :
F_86 () ;
break;
case 'i' :
F_87 ( 0 ) ;
break;
default:
V_87 = V_30 ;
F_88 () ;
}
break;
case 'd' :
F_89 () ;
break;
case 'l' :
F_90 () ;
break;
case 'r' :
F_91 ( V_59 ) ;
break;
case 'e' :
F_33 ( V_59 ) ;
break;
case 'S' :
F_92 () ;
break;
case 't' :
F_93 ( V_59 ) ;
break;
case 'f' :
F_94 () ;
break;
case 's' :
if ( F_95 () == 0 )
break;
if ( F_96 ( V_59 ) )
return V_30 ;
break;
case 'x' :
case 'X' :
return V_30 ;
case V_58 :
printf ( L_27 ) ;
F_97 ( 2000 ) ;
return V_30 ;
case '?' :
F_98 ( V_88 ) ;
break;
case 'b' :
F_99 () ;
break;
case 'C' :
F_100 () ;
break;
case 'c' :
if ( F_101 () )
return 0 ;
break;
case 'z' :
F_102 () ;
break;
case 'p' :
F_103 () ;
break;
#ifdef F_104
case 'u' :
F_105 () ;
break;
#elif F_24 ( V_89 )
case 'u' :
F_106 () ;
break;
#elif F_24 ( V_26 )
case 'u' :
F_107 () ;
break;
#endif
default:
printf ( L_28 ) ;
do {
if ( ' ' < V_30 && V_30 <= '~' )
putchar ( V_30 ) ;
else
printf ( L_29 , V_30 ) ;
V_30 = F_83 () ;
} while ( V_30 != '\n' );
printf ( L_30 ) ;
break;
}
}
}
static int F_96 ( struct V_23 * V_24 )
{
V_24 -> V_27 |= V_55 ;
F_8 ( V_90 , F_108 ( V_90 ) | V_91 | V_92 ) ;
return 1 ;
}
static int F_96 ( struct V_23 * V_24 )
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
printf ( L_31 ) ;
F_38 ( V_24 -> V_39 , L_7 , L_32 ) ;
F_47 ( V_24 -> V_39 , 1 , 0 ) ;
return 0 ;
}
}
}
V_24 -> V_27 |= V_93 ;
return 1 ;
}
static void F_102 ( void )
{
int V_30 ;
V_30 = F_83 () ;
if ( V_30 == 'r' )
V_94 . V_95 ( NULL ) ;
else if ( V_30 == 'h' )
V_94 . V_96 () ;
else if ( V_30 == 'p' )
if ( V_97 )
V_97 () ;
}
static int F_101 ( void )
{
#ifdef F_26
unsigned long V_37 , V_98 , V_99 ;
int V_20 ;
if ( ! F_109 ( & V_37 ) ) {
printf ( L_33 ) ;
V_99 = V_98 = V_100 ;
F_110 (cpu) {
if ( F_32 ( V_37 , & V_22 ) ) {
if ( V_37 == V_99 + 1 ) {
V_99 = V_37 ;
} else {
if ( V_99 != V_98 )
printf ( L_34 , V_99 ) ;
V_99 = V_98 = V_37 ;
printf ( L_35 , V_37 ) ;
}
}
}
if ( V_99 != V_98 )
printf ( L_34 , V_99 ) ;
printf ( L_32 ) ;
return 0 ;
}
if ( ! F_32 ( V_37 , & V_22 ) ) {
printf ( L_36 , V_37 ) ;
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
printf ( L_37 , V_37 ) ;
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
F_100 ( void )
{
unsigned int V_68 ;
unsigned short V_101 ;
unsigned char V_102 ;
if ( ! F_109 ( & V_103 ) )
return;
if ( ! F_109 ( & V_104 ) )
return;
V_101 = 0xffff ;
for ( V_68 = 0 ; V_68 < V_104 ; ++ V_68 ) {
if ( F_74 ( V_103 + V_68 , & V_102 , 1 ) == 0 ) {
printf ( L_38 V_105 L_32 , V_103 + V_68 ) ;
break;
}
V_101 = F_111 ( V_101 , V_102 ) ;
}
printf ( L_39 , V_101 ) ;
}
static long F_112 ( unsigned long V_6 )
{
unsigned int V_56 ;
V_6 &= ~ 3 ;
if ( ! F_113 ( V_6 ) ) {
printf ( L_40 ) ;
return 0 ;
}
if ( ! F_74 ( V_6 , & V_56 , sizeof( V_56 ) ) ) {
printf ( L_41 , V_6 ) ;
return 0 ;
}
if ( F_75 ( V_56 ) || F_55 ( V_56 ) ) {
printf ( L_42
L_43 ) ;
return 0 ;
}
return 1 ;
}
static void
F_99 ( void )
{
int V_30 ;
unsigned long V_73 ;
int V_106 , V_68 ;
struct V_31 * V_32 ;
const char V_107 [] = L_44
L_45 ;
V_30 = F_83 () ;
switch ( V_30 ) {
#ifndef F_114
case 'd' :
V_106 = 7 ;
V_30 = F_83 () ;
if ( V_30 == 'r' )
V_106 = 5 ;
else if ( V_30 == 'w' )
V_106 = 6 ;
else
V_87 = V_30 ;
V_63 . V_40 = 0 ;
V_63 . V_64 = 0 ;
if ( F_109 ( & V_63 . V_40 ) ) {
if ( ! F_113 ( V_63 . V_40 ) ) {
printf ( V_107 ) ;
break;
}
V_63 . V_40 &= ~ V_79 ;
V_63 . V_64 = V_106 | V_108 ;
}
break;
case 'i' :
if ( ! F_7 ( V_3 ) ) {
printf ( L_46
L_47 ) ;
break;
}
if ( V_65 ) {
V_65 -> V_64 &= ~ V_76 ;
V_65 = NULL ;
}
if ( ! F_109 ( & V_73 ) )
break;
if ( ! F_112 ( V_73 ) )
break;
V_32 = F_72 ( V_73 ) ;
if ( V_32 != NULL ) {
V_32 -> V_64 |= V_76 ;
V_65 = V_32 ;
}
break;
#endif
case 'c' :
if ( ! F_109 ( & V_73 ) ) {
for ( V_68 = 0 ; V_68 < V_70 ; ++ V_68 )
V_69 [ V_68 ] . V_64 = 0 ;
V_65 = NULL ;
V_63 . V_64 = 0 ;
printf ( L_48 ) ;
break;
}
if ( V_73 <= V_70 && V_73 >= 1 ) {
V_32 = & V_69 [ V_73 - 1 ] ;
} else {
V_32 = F_36 ( V_73 ) ;
if ( V_32 == NULL ) {
printf ( L_49 , V_73 ) ;
break;
}
}
printf ( L_50 , F_37 ( V_32 ) ) ;
F_38 ( V_32 -> V_40 , L_7 , L_8 ) ;
V_32 -> V_64 = 0 ;
break;
default:
V_87 = V_30 ;
V_30 = F_81 () ;
if ( V_30 == '?' ) {
printf ( V_109 ) ;
break;
}
V_87 = V_30 ;
if ( ! F_109 ( & V_73 ) ) {
printf ( L_51 ) ;
if ( V_63 . V_64 ) {
printf ( L_52 V_105 L_53 , V_63 . V_40 ) ;
if ( V_63 . V_64 & 1 )
printf ( L_54 ) ;
if ( V_63 . V_64 & 2 )
printf ( L_55 ) ;
printf ( L_56 ) ;
}
for ( V_32 = V_69 ; V_32 < & V_69 [ V_70 ] ; ++ V_32 ) {
if ( ! V_32 -> V_64 )
continue;
printf ( L_57 , F_37 ( V_32 ) ,
( V_32 -> V_64 & V_76 ) ? L_58 : L_59 ) ;
F_38 ( V_32 -> V_40 , L_60 , L_32 ) ;
}
break;
}
if ( ! F_112 ( V_73 ) )
break;
V_32 = F_72 ( V_73 ) ;
if ( V_32 != NULL )
V_32 -> V_64 |= V_75 ;
break;
}
}
static
const char * F_34 ( unsigned long V_110 )
{
char * V_111 ;
switch ( V_110 ) {
case 0x100 : V_111 = L_61 ; break;
case 0x200 : V_111 = L_62 ; break;
case 0x300 : V_111 = L_63 ; break;
case 0x380 : V_111 = L_64 ; break;
case 0x400 : V_111 = L_65 ; break;
case 0x480 : V_111 = L_66 ; break;
case 0x500 : V_111 = L_67 ; break;
case 0x600 : V_111 = L_68 ; break;
case 0x700 : V_111 = L_69 ; break;
case 0x800 : V_111 = L_70 ; break;
case 0x900 : V_111 = L_71 ; break;
case 0x980 : V_111 = L_72 ; break;
case 0xa00 : V_111 = L_73 ; break;
case 0xc00 : V_111 = L_74 ; break;
case 0xd00 : V_111 = L_75 ; break;
case 0xe40 : V_111 = L_76 ; break;
case 0xe60 : V_111 = L_77 ; break;
case 0xe80 : V_111 = L_78 ; break;
case 0xf00 : V_111 = L_79 ; break;
case 0xf20 : V_111 = L_80 ; break;
case 0x1300 : V_111 = L_81 ; break;
case 0x1500 : V_111 = L_82 ; break;
case 0x1700 : V_111 = L_83 ; break;
default: V_111 = L_84 ;
}
return V_111 ;
}
static void F_115 ( unsigned long V_67 , unsigned long * V_112 ,
unsigned long * V_113 )
{
unsigned long V_114 , V_35 ;
const char * V_115 ;
* V_112 = * V_113 = 0 ;
if ( V_67 == 0 )
return;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_115 = F_116 ( V_67 , & V_114 , & V_35 , NULL , V_117 ) ;
if ( V_115 != NULL ) {
* V_112 = V_67 - V_35 ;
* V_113 = V_67 - V_35 + V_114 ;
}
F_2 () ;
}
V_66 = 0 ;
}
static void F_79 ( unsigned long V_118 , unsigned long V_119 ,
unsigned long V_67 )
{
int V_120 = 64 ;
unsigned long V_121 ;
unsigned long V_122 ;
unsigned long V_123 ;
struct V_23 V_24 ;
while ( V_120 -- ) {
if ( V_118 < V_124 ) {
if ( V_118 != 0 )
printf ( L_85 , V_118 ) ;
break;
}
if ( ! F_74 ( V_118 + V_125 , & V_121 , sizeof( unsigned long ) )
|| ! F_74 ( V_118 , & V_122 , sizeof( unsigned long ) ) ) {
printf ( L_86 , V_118 ) ;
break;
}
if ( ( V_67 | V_119 ) != 0 ) {
unsigned long V_126 , V_127 ;
unsigned long V_128 ;
int V_129 = 1 ;
F_115 ( V_67 , & V_126 , & V_127 ) ;
V_128 = 0 ;
if ( V_122 > V_118 )
F_74 ( V_122 + V_125 , & V_128 ,
sizeof( unsigned long ) ) ;
if ( V_119 == V_121 ) {
if ( V_119 < V_124
|| ( V_126 <= V_119 && V_119 < V_127 ) )
V_129 = 0 ;
} else if ( V_119 == V_128 ) {
V_129 = 0 ;
} else if ( V_119 >= V_124
&& ! ( V_126 <= V_119 && V_119 < V_127 ) ) {
printf ( L_87 ) ;
F_38 ( V_119 , L_7 , L_32 ) ;
}
if ( V_129 ) {
printf ( L_88 V_105 L_89 , V_118 ) ;
F_38 ( V_121 , L_7 , L_90 ) ;
}
V_67 = V_119 = 0 ;
} else {
printf ( L_88 V_105 L_89 , V_118 ) ;
F_38 ( V_121 , L_7 , L_32 ) ;
}
if ( F_74 ( V_118 + V_130 , & V_123 , sizeof( unsigned long ) )
&& V_123 == V_131 ) {
if ( F_74 ( V_118 + V_132 , & V_24 , sizeof( V_24 ) )
!= sizeof( V_24 ) ) {
printf ( L_91 ,
V_118 + V_132 ) ;
break;
}
printf ( L_92 , V_24 . V_42 ,
F_34 ( F_35 ( & V_24 ) ) ) ;
V_67 = V_24 . V_39 ;
V_119 = V_24 . V_86 ;
F_38 ( V_67 , L_7 , L_32 ) ;
}
if ( V_122 == 0 )
break;
V_118 = V_122 ;
}
}
static void F_93 ( struct V_23 * V_59 )
{
unsigned long V_118 ;
if ( F_109 ( & V_118 ) )
F_79 ( V_118 , 0 , 0 ) ;
else
F_79 ( V_59 -> V_85 [ 1 ] , V_59 -> V_86 , V_59 -> V_39 ) ;
F_117 () ;
}
static void F_118 ( struct V_23 * V_24 )
{
#ifdef F_119
const struct V_133 * V_134 ;
unsigned long V_6 ;
if ( V_24 -> V_27 & V_51 )
return;
V_6 = V_24 -> V_39 ;
if ( V_6 < V_124 )
return;
V_134 = F_120 ( V_24 -> V_39 ) ;
if ( V_134 == NULL )
return;
if ( F_121 ( V_134 ) )
return;
#ifdef F_122
printf ( L_93 ,
V_134 -> V_135 , V_134 -> line ) ;
#else
printf ( L_94 , ( void * ) V_134 -> V_136 ) ;
#endif
#endif
}
static void F_33 ( struct V_23 * V_137 )
{
unsigned long V_42 ;
#ifdef F_26
printf ( L_95 , F_17 () ) ;
#endif
V_42 = F_35 ( V_137 ) ;
printf ( L_96 , V_137 -> V_42 , F_34 ( V_42 ) , V_137 ) ;
printf ( L_97 ) ;
F_38 ( V_137 -> V_39 , L_98 , L_32 ) ;
printf ( L_99 , V_137 -> V_86 ) ;
F_38 ( V_137 -> V_86 , L_98 , L_32 ) ;
printf ( L_100 , V_137 -> V_85 [ 1 ] ) ;
printf ( L_101 , V_137 -> V_27 ) ;
if ( V_42 == 0x300 || V_42 == 0x380 || V_42 == 0x600 || V_42 == 0x200 ) {
printf ( L_102 , V_137 -> V_138 ) ;
if ( V_42 != 0x380 )
printf ( L_103 , V_137 -> V_139 ) ;
}
printf ( L_104 , V_140 ) ;
#ifdef F_123
printf ( L_105 ,
V_141 , V_141 -> V_142 , V_141 -> V_143 ) ;
#endif
if ( V_140 ) {
printf ( L_106 ,
V_140 -> V_144 , V_140 -> V_145 ) ;
}
if ( V_42 == 0x700 )
F_118 ( V_137 ) ;
}
static void F_91 ( struct V_23 * V_137 )
{
int V_146 , V_42 ;
unsigned long V_147 ;
struct V_23 V_24 ;
if ( F_109 ( & V_147 ) ) {
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_24 = * (struct V_23 * ) V_147 ;
F_2 () ;
F_124 ( 200 ) ;
} else {
V_66 = 0 ;
printf ( L_107 V_105 L_32 ,
V_147 ) ;
return;
}
V_66 = 0 ;
V_137 = & V_24 ;
}
#ifdef F_123
if ( F_125 ( V_137 ) ) {
for ( V_146 = 0 ; V_146 < 16 ; ++ V_146 )
printf ( L_108 V_105 L_109 V_105 L_32 ,
V_146 , V_137 -> V_85 [ V_146 ] , V_146 + 16 , V_137 -> V_85 [ V_146 + 16 ] ) ;
} else {
for ( V_146 = 0 ; V_146 < 7 ; ++ V_146 )
printf ( L_108 V_105 L_109 V_105 L_32 ,
V_146 , V_137 -> V_85 [ V_146 ] , V_146 + 7 , V_137 -> V_85 [ V_146 + 7 ] ) ;
}
#else
for ( V_146 = 0 ; V_146 < 32 ; ++ V_146 ) {
printf ( L_110 , V_146 , V_137 -> V_85 [ V_146 ] ,
( V_146 & 3 ) == 3 ? L_32 : L_111 ) ;
if ( V_146 == 12 && ! F_125 ( V_137 ) ) {
printf ( L_32 ) ;
break;
}
}
#endif
printf ( L_112 ) ;
F_38 ( V_137 -> V_39 , L_7 , L_32 ) ;
if ( F_35 ( V_137 ) != 0xc00 && F_7 ( V_148 ) ) {
printf ( L_113 ) ;
F_38 ( V_137 -> V_149 , L_7 , L_32 ) ;
}
printf ( L_114 ) ;
F_38 ( V_137 -> V_86 , L_7 , L_32 ) ;
printf ( L_115 V_105 L_116 , V_137 -> V_27 , V_137 -> V_150 ) ;
printf ( L_117 V_105 L_118 V_105 L_119 ,
V_137 -> V_151 , V_137 -> V_152 , V_137 -> V_42 ) ;
V_42 = F_35 ( V_137 ) ;
if ( V_42 == 0x300 || V_42 == 0x380 || V_42 == 0x600 )
printf ( L_120 V_105 L_121 , V_137 -> V_138 , V_137 -> V_139 ) ;
}
static void F_94 ( void )
{
int V_30 ;
unsigned long V_153 ;
V_30 = F_83 () ;
if ( V_30 != 'i' )
V_87 = V_30 ;
F_109 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
V_153 = 1 ;
F_109 ( & V_153 ) ;
V_153 = ( V_153 + V_154 - 1 ) / V_154 ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
if ( V_30 != 'i' ) {
for (; V_153 > 0 ; -- V_153 , V_103 += V_154 )
F_4 ( ( void * ) V_103 ) ;
} else {
for (; V_153 > 0 ; -- V_153 , V_103 += V_154 )
F_5 ( ( void * ) V_103 ) ;
}
F_2 () ;
F_124 ( 200 ) ;
}
V_66 = 0 ;
}
static unsigned long
F_126 ( int V_146 )
{
unsigned int V_155 [ 2 ] ;
unsigned long ( * V_156 ) ( void ) ;
unsigned long V_111 = - 1UL ;
#ifdef F_123
unsigned long V_157 [ 3 ] ;
V_157 [ 0 ] = ( unsigned long ) V_155 ;
V_157 [ 1 ] = 0 ;
V_157 [ 2 ] = 0 ;
V_156 = ( unsigned long ( * ) ( void ) ) V_157 ;
#else
V_156 = ( unsigned long ( * ) ( void ) ) V_155 ;
#endif
V_155 [ 0 ] = 0x7c6002a6 + ( ( V_146 & 0x1F ) << 16 ) + ( ( V_146 & 0x3e0 ) << 6 ) ;
V_155 [ 1 ] = 0x4e800020 ;
F_3 ( V_155 ) ;
F_3 ( V_155 + 1 ) ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_111 = V_156 () ;
F_2 () ;
F_124 ( 200 ) ;
V_146 = V_114 ;
}
return V_111 ;
}
static void
F_127 ( int V_146 , unsigned long V_158 )
{
unsigned int V_155 [ 2 ] ;
unsigned long ( * V_156 ) ( unsigned long ) ;
#ifdef F_123
unsigned long V_157 [ 3 ] ;
V_157 [ 0 ] = ( unsigned long ) V_155 ;
V_157 [ 1 ] = 0 ;
V_157 [ 2 ] = 0 ;
V_156 = ( unsigned long (*) ( unsigned long ) ) V_157 ;
#else
V_156 = ( unsigned long (*) ( unsigned long ) ) V_155 ;
#endif
V_155 [ 0 ] = 0x7c6003a6 + ( ( V_146 & 0x1F ) << 16 ) + ( ( V_146 & 0x3e0 ) << 6 ) ;
V_155 [ 1 ] = 0x4e800020 ;
F_3 ( V_155 ) ;
F_3 ( V_155 + 1 ) ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_156 ( V_158 ) ;
F_2 () ;
F_124 ( 200 ) ;
V_146 = V_114 ;
}
}
static void F_92 ( void )
{
int V_30 ;
unsigned long V_158 ;
V_30 = F_81 () ;
if ( V_30 == '\n' ) {
unsigned long V_118 , V_159 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_122 V_105 L_123 V_105 L_32 ,
F_128 () , F_108 ( V_160 ) ) ;
printf ( L_124 V_105 L_125 V_105 L_32 ,
F_108 ( V_161 ) , F_108 ( V_162 ) ) ;
printf ( L_126 V_105 L_127 V_105 L_32 ,
F_108 ( V_163 ) , F_108 ( V_164 ) ) ;
printf ( L_128 V_105 L_129 V_105 L_32 , V_118 , F_108 ( V_165 ) ) ;
printf ( L_130 V_105 L_131 V_105 L_32 , V_159 , F_108 ( V_166 ) ) ;
return;
}
F_109 ( & V_167 ) ;
switch ( V_30 ) {
case 'w' :
V_158 = F_126 ( V_167 ) ;
F_109 ( & V_158 ) ;
F_127 ( V_167 , V_158 ) ;
case 'r' :
printf ( L_132 , V_167 , F_126 ( V_167 ) ) ;
break;
}
F_117 () ;
}
static int
F_74 ( unsigned long V_103 , void * V_168 , int V_114 )
{
volatile int V_146 ;
char * V_2 , * V_169 ;
V_146 = 0 ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_2 = ( char * ) V_103 ;
V_169 = ( char * ) V_168 ;
switch ( V_114 ) {
case 2 :
* ( V_170 * ) V_169 = * ( V_170 * ) V_2 ;
break;
case 4 :
* ( V_171 * ) V_169 = * ( V_171 * ) V_2 ;
break;
case 8 :
* ( V_172 * ) V_169 = * ( V_172 * ) V_2 ;
break;
default:
for( ; V_146 < V_114 ; ++ V_146 ) {
* V_169 ++ = * V_2 ++ ;
F_2 () ;
}
}
F_2 () ;
F_124 ( 200 ) ;
V_146 = V_114 ;
}
V_66 = 0 ;
return V_146 ;
}
static int
F_76 ( unsigned long V_103 , void * V_168 , int V_114 )
{
volatile int V_146 ;
char * V_2 , * V_169 ;
V_146 = 0 ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_2 = ( char * ) V_103 ;
V_169 = ( char * ) V_168 ;
switch ( V_114 ) {
case 2 :
* ( V_170 * ) V_2 = * ( V_170 * ) V_169 ;
break;
case 4 :
* ( V_171 * ) V_2 = * ( V_171 * ) V_169 ;
break;
case 8 :
* ( V_172 * ) V_2 = * ( V_172 * ) V_169 ;
break;
default:
for ( ; V_146 < V_114 ; ++ V_146 ) {
* V_2 ++ = * V_169 ++ ;
F_2 () ;
}
}
F_2 () ;
F_124 ( 200 ) ;
V_146 = V_114 ;
} else {
printf ( L_133 V_105 L_32 , V_103 + V_146 ) ;
}
V_66 = 0 ;
return V_146 ;
}
static int F_70 ( struct V_23 * V_24 )
{
V_173 = F_35 ( V_24 ) ;
switch ( F_35 ( V_24 ) ) {
case 0x200 :
V_174 = 0 ;
break;
case 0x300 :
case 0x380 :
V_174 = 1 ;
break;
default:
V_174 = 2 ;
}
longjmp ( V_116 , 1 ) ;
return 0 ;
}
static void
F_129 ( unsigned char * V_158 , int V_114 )
{
int V_175 ;
switch ( V_114 ) {
case 2 :
F_130 ( V_158 [ 0 ] , V_158 [ 1 ] , V_175 ) ;
break;
case 4 :
F_130 ( V_158 [ 0 ] , V_158 [ 3 ] , V_175 ) ;
F_130 ( V_158 [ 1 ] , V_158 [ 2 ] , V_175 ) ;
break;
case 8 :
F_130 ( V_158 [ 0 ] , V_158 [ 7 ] , V_175 ) ;
F_130 ( V_158 [ 1 ] , V_158 [ 6 ] , V_175 ) ;
F_130 ( V_158 [ 2 ] , V_158 [ 5 ] , V_175 ) ;
F_130 ( V_158 [ 3 ] , V_158 [ 4 ] , V_175 ) ;
break;
}
}
static void
F_88 ( void )
{
int V_30 , V_176 , V_68 , V_177 ;
unsigned long V_146 ;
unsigned char V_158 [ 16 ] ;
F_109 ( ( void * ) & V_103 ) ;
V_30 = F_81 () ;
if ( V_30 == '?' ) {
printf ( V_178 ) ;
return;
} else {
V_87 = V_30 ;
}
V_82 = L_134 ;
while ( ( V_30 = F_81 () ) != '\n' ) {
switch( V_30 ) {
case 'b' : V_114 = 1 ; break;
case 'w' : V_114 = 2 ; break;
case 'l' : V_114 = 4 ; break;
case 'd' : V_114 = 8 ; break;
case 'r' : V_179 = ! V_179 ; break;
case 'n' : V_180 = 1 ; break;
case '.' : V_180 = 0 ; break;
}
}
if( V_114 <= 0 )
V_114 = 1 ;
else if( V_114 > 8 )
V_114 = 8 ;
for(; ; ) {
if ( ! V_180 )
V_146 = F_74 ( V_103 , V_158 , V_114 ) ;
printf ( V_105 L_135 , V_103 , V_179 ? 'r' : ' ' ) ;
if ( ! V_180 ) {
if ( V_179 )
F_129 ( V_158 , V_114 ) ;
putchar ( ' ' ) ;
for ( V_68 = 0 ; V_68 < V_146 ; ++ V_68 )
printf ( L_136 , V_158 [ V_68 ] ) ;
for (; V_68 < V_114 ; ++ V_68 )
printf ( L_137 , V_181 [ V_174 ] ) ;
}
putchar ( ' ' ) ;
V_176 = V_114 ;
V_177 = 0 ;
for(; ; ) {
if( F_109 ( & V_146 ) ) {
for ( V_68 = 0 ; V_68 < V_114 ; ++ V_68 )
V_158 [ V_68 ] = V_146 >> ( V_68 * 8 ) ;
if ( ! V_179 )
F_129 ( V_158 , V_114 ) ;
F_76 ( V_103 , V_158 , V_114 ) ;
V_176 = V_114 ;
}
V_30 = F_81 () ;
if ( V_30 == '\n' )
break;
V_176 = 0 ;
switch ( V_30 ) {
case '\'' :
for(; ; ) {
V_146 = F_83 () ;
if( V_146 == '\\' )
V_146 = F_131 () ;
else if( V_146 == '\'' )
break;
for ( V_68 = 0 ; V_68 < V_114 ; ++ V_68 )
V_158 [ V_68 ] = V_146 >> ( V_68 * 8 ) ;
if ( ! V_179 )
F_129 ( V_158 , V_114 ) ;
F_76 ( V_103 , V_158 , V_114 ) ;
V_103 += V_114 ;
}
V_103 -= V_114 ;
V_176 = V_114 ;
break;
case ',' :
V_103 += V_114 ;
break;
case '.' :
V_180 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_58 :
F_117 () ;
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
if ( V_177 > 0 )
V_103 -= 1 << V_177 ;
else
V_177 = 0 ;
V_177 += 4 ;
V_103 += 1 << V_177 ;
break;
case '\\' :
if ( V_177 < 0 )
V_103 += 1 << - V_177 ;
else
V_177 = 0 ;
V_177 -= 4 ;
V_103 -= 1 << - V_177 ;
break;
case 'm' :
F_109 ( ( void * ) & V_103 ) ;
break;
case 'n' :
V_180 = 1 ;
break;
case 'r' :
V_179 = ! V_179 ;
break;
case '<' :
V_146 = V_114 ;
F_109 ( & V_146 ) ;
V_103 -= V_146 ;
break;
case '>' :
V_146 = V_114 ;
F_109 ( & V_146 ) ;
V_103 += V_146 ;
break;
case '?' :
printf ( V_182 ) ;
break;
}
}
V_103 += V_176 ;
}
}
static int
F_131 ( void )
{
int V_183 ;
V_183 = F_83 () ;
switch( V_183 ) {
case 'n' : V_183 = '\n' ; break;
case 'r' : V_183 = '\r' ; break;
case 'b' : V_183 = '\b' ; break;
case 't' : V_183 = '\t' ; break;
}
return V_183 ;
}
static void F_132 ( unsigned long V_103 , long V_184 )
{
long V_146 , V_185 , V_186 , V_187 ;
unsigned char V_188 [ 16 ] ;
for ( V_146 = V_184 ; V_146 > 0 ; ) {
V_186 = V_146 < 16 ? V_146 : 16 ;
V_187 = F_74 ( V_103 , V_188 , V_186 ) ;
V_103 += V_187 ;
for ( V_185 = 0 ; V_185 < V_186 ; ++ V_185 ) {
if ( V_185 < V_187 )
printf ( L_136 , V_188 [ V_185 ] ) ;
else
printf ( L_137 , V_181 [ V_174 ] ) ;
}
V_146 -= V_186 ;
if ( V_187 < V_186 )
break;
}
printf ( L_32 ) ;
}
static void F_133 ( int V_37 )
{
struct V_189 * V_2 ;
if ( setjmp ( V_116 ) != 0 ) {
printf ( L_138 , V_37 ) ;
return;
}
V_66 = 1 ;
F_2 () ;
V_2 = & V_190 [ V_37 ] ;
printf ( L_139 , V_37 , V_2 ) ;
printf ( L_140 , 16 , L_141 , F_134 ( V_37 ) ? L_142 : L_143 ) ;
printf ( L_140 , 16 , L_144 , F_135 ( V_37 ) ? L_142 : L_143 ) ;
printf ( L_140 , 16 , L_145 , F_136 ( V_37 ) ? L_142 : L_143 ) ;
#define F_137 ( V_190 , V_115 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 16, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_137 ( V_2 , V_191 , L_146 ) ;
F_137 ( V_2 , V_192 , L_146 ) ;
F_137 ( V_2 , V_193 , L_147 ) ;
F_137 ( V_2 , V_194 , L_147 ) ;
F_137 ( V_2 , V_195 , L_147 ) ;
F_137 ( V_2 , V_196 , L_148 ) ;
#ifdef F_138
F_137 ( V_2 , V_197 , L_148 ) ;
F_137 ( V_2 , V_198 , L_146 ) ;
#endif
F_137 ( V_2 , V_199 , L_147 ) ;
F_137 ( V_2 , V_200 , L_146 ) ;
F_137 ( V_2 , V_201 , L_146 ) ;
F_137 ( V_2 , V_202 , L_146 ) ;
F_137 ( V_2 , V_203 , L_148 ) ;
F_137 ( V_2 , V_204 , L_147 ) ;
F_137 ( V_2 , V_205 , L_147 ) ;
F_137 ( V_2 , V_206 , L_147 ) ;
F_137 ( V_2 , V_207 , L_146 ) ;
F_137 ( V_2 , V_142 , L_146 ) ;
F_137 ( V_2 , V_143 , L_146 ) ;
F_137 ( V_2 , V_208 , L_146 ) ;
F_137 ( V_2 , V_209 , L_146 ) ;
F_137 ( V_2 , V_210 , L_146 ) ;
#undef F_137
V_66 = 0 ;
F_2 () ;
}
static void F_139 ( void )
{
int V_37 ;
if ( F_140 () == 0 ) {
printf ( L_149 ) ;
return;
}
F_110 (cpu)
F_133 ( V_37 ) ;
}
static void F_141 ( void )
{
unsigned long V_211 ;
int V_183 ;
V_183 = F_83 () ;
if ( V_183 == 'a' ) {
F_139 () ;
return;
}
V_87 = V_183 ;
if ( F_109 ( & V_211 ) )
F_133 ( V_211 ) ;
else
F_133 ( V_48 ) ;
}
static void
F_89 ( void )
{
int V_183 ;
V_183 = F_83 () ;
#ifdef F_123
if ( V_183 == 'p' ) {
F_141 () ;
return;
}
#endif
if ( ( isxdigit ( V_183 ) && V_183 != 'f' && V_183 != 'd' ) || V_183 == '\n' )
V_87 = V_183 ;
F_109 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
if ( V_183 == 'i' ) {
F_109 ( & V_212 ) ;
if ( V_212 == 0 )
V_212 = 16 ;
else if ( V_212 > V_213 )
V_212 = V_213 ;
V_103 += F_47 ( V_103 , V_212 , 1 ) ;
V_82 = L_150 ;
} else if ( V_183 == 'l' ) {
F_142 () ;
} else if ( V_183 == 'r' ) {
F_109 ( & V_184 ) ;
if ( V_184 == 0 )
V_184 = 64 ;
F_132 ( V_103 , V_184 ) ;
V_103 += V_184 ;
V_82 = L_151 ;
} else {
F_109 ( & V_184 ) ;
if ( V_184 == 0 )
V_184 = 64 ;
else if ( V_184 > V_213 )
V_184 = V_213 ;
F_143 ( V_103 , V_184 ) ;
V_103 += V_184 ;
V_82 = L_152 ;
}
}
static void
F_143 ( unsigned long V_103 , long V_184 )
{
long V_146 , V_185 , V_183 , V_186 , V_187 ;
unsigned char V_188 [ 16 ] ;
for ( V_146 = V_184 ; V_146 > 0 ; ) {
printf ( V_105 , V_103 ) ;
putchar ( ' ' ) ;
V_186 = V_146 < 16 ? V_146 : 16 ;
V_187 = F_74 ( V_103 , V_188 , V_186 ) ;
V_103 += V_187 ;
for ( V_185 = 0 ; V_185 < V_186 ; ++ V_185 ) {
if ( ( V_185 & ( sizeof( long ) - 1 ) ) == 0 && V_185 > 0 )
putchar ( ' ' ) ;
if ( V_185 < V_187 )
printf ( L_136 , V_188 [ V_185 ] ) ;
else
printf ( L_137 , V_181 [ V_174 ] ) ;
}
for (; V_185 < 16 ; ++ V_185 ) {
if ( ( V_185 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_60 ) ;
}
printf ( L_153 ) ;
for ( V_185 = 0 ; V_185 < V_186 ; ++ V_185 ) {
if ( V_185 < V_187 ) {
V_183 = V_188 [ V_185 ] ;
putchar ( ' ' <= V_183 && V_183 <= '~' ? V_183 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_146 -= V_186 ;
for (; V_185 < 16 ; ++ V_185 )
putchar ( ' ' ) ;
printf ( L_154 ) ;
if ( V_187 < V_186 )
break;
}
}
static int
F_144 ( unsigned long V_214 , long V_215 , int V_216 ,
T_3 V_217 )
{
int V_187 , V_218 ;
unsigned long V_219 ;
unsigned long V_220 , V_221 = 0 ;
unsigned char V_158 [ 4 ] ;
V_218 = 0 ;
for ( V_219 = V_214 ; V_215 > 0 ; -- V_215 , V_214 += 4 ) {
V_187 = F_74 ( V_214 , V_158 , 4 ) ;
if ( V_187 == 0 ) {
if ( V_216 ) {
const char * V_222 = V_181 [ V_174 ] ;
printf ( V_105 L_155 , V_214 , V_222 , V_222 , V_222 , V_222 ) ;
}
break;
}
V_220 = F_145 ( V_158 ) ;
if ( V_214 > V_219 && V_220 == V_221 ) {
if ( ! V_218 ) {
printf ( L_156 ) ;
V_218 = 1 ;
}
continue;
}
V_218 = 0 ;
V_221 = V_220 ;
if ( V_216 )
printf ( V_105 L_157 , V_214 , V_220 ) ;
printf ( L_158 ) ;
V_217 ( V_220 , V_214 ) ;
printf ( L_32 ) ;
}
return V_214 - V_219 ;
}
static int
F_47 ( unsigned long V_214 , long V_215 , int V_216 )
{
return F_144 ( V_214 , V_215 , V_216 , V_223 ) ;
}
void
F_146 ( unsigned long V_6 )
{
F_38 ( V_6 , L_159 , L_84 ) ;
}
void
F_142 ( void )
{
struct V_224 V_225 = { . V_226 = 1 } ;
unsigned char V_168 [ 128 ] ;
T_4 V_81 ;
if ( setjmp ( V_116 ) != 0 ) {
printf ( L_160 ) ;
return;
}
V_66 = 1 ;
F_2 () ;
F_147 ( & V_225 ) ;
while ( F_148 ( & V_225 , false , V_168 , sizeof( V_168 ) , & V_81 ) ) {
V_168 [ V_81 ] = '\0' ;
printf ( L_137 , V_168 ) ;
}
F_2 () ;
F_124 ( 200 ) ;
V_66 = 0 ;
}
static void
F_84 ( int V_30 )
{
F_109 ( ( void * ) & V_227 ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_109 ( ( void * ) ( V_30 == 's' ? & V_228 : & V_229 ) ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_109 ( ( void * ) & V_230 ) ;
switch( V_30 ) {
case 'm' :
memmove ( ( void * ) V_227 , ( void * ) V_229 , V_230 ) ;
break;
case 's' :
memset ( ( void * ) V_227 , V_228 , V_230 ) ;
break;
case 'd' :
if( V_87 != '\n' )
V_87 = 0 ;
F_109 ( ( void * ) & V_231 ) ;
F_149 ( ( unsigned char * ) V_227 , ( unsigned char * ) V_229 , V_230 , V_231 ) ;
break;
}
}
static void
F_149 ( unsigned char * V_232 , unsigned char * V_233 , unsigned V_234 , unsigned V_235 )
{
unsigned V_146 , V_236 ;
V_236 = 0 ;
for( V_146 = V_234 ; V_146 > 0 ; -- V_146 )
if( * V_232 ++ != * V_233 ++ )
if( ++ V_236 <= V_235 )
printf ( L_161 , V_232 - 1 ,
V_232 [ - 1 ] , V_233 - 1 , V_233 [ - 1 ] ) ;
if( V_236 > V_235 )
printf ( L_162 , V_236 ) ;
}
static void
F_85 ( void )
{
unsigned V_73 , V_146 ;
unsigned char V_158 [ 4 ] ;
V_82 = L_163 ;
F_109 ( ( void * ) & V_227 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_109 ( ( void * ) & V_237 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_109 ( ( void * ) & V_228 ) ;
V_238 = ~ 0 ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_109 ( ( void * ) & V_238 ) ;
}
}
V_146 = 0 ;
for ( V_73 = V_227 ; V_73 < V_237 ; V_73 += 4 ) {
if ( F_74 ( V_73 , V_158 , 4 ) == 4
&& ( ( F_145 ( V_158 ) ^ V_228 ) & V_238 ) == 0 ) {
printf ( L_164 , V_73 , F_145 ( V_158 ) ) ;
if ( ++ V_146 >= 10 )
break;
}
}
}
static void
F_86 ( void )
{
unsigned char V_102 ;
unsigned V_73 ;
int V_239 , V_240 ;
F_109 ( & V_227 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_109 ( & V_241 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_109 ( & V_242 ) ;
V_240 = 0 ;
for ( V_73 = V_227 ; V_73 < V_242 ; V_73 += V_241 ) {
V_239 = F_74 ( V_73 , & V_102 , 1 ) ;
if ( V_239 && ! V_240 ) {
printf ( L_165 , V_73 ) ;
} else if ( ! V_239 && V_240 )
printf ( L_166 , V_73 - V_241 ) ;
V_240 = V_239 ;
if ( V_73 + V_241 < V_73 )
break;
}
if ( V_240 )
printf ( L_166 , V_73 - V_241 ) ;
}
static void F_103 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_111 ;
int V_68 ;
typedef unsigned long (* T_5)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_5 V_243 ;
if ( ! F_109 ( & V_103 ) )
return;
if ( V_87 != '\n' )
V_87 = 0 ;
for ( V_68 = 0 ; V_68 < 8 ; ++ V_68 )
args [ V_68 ] = 0 ;
for ( V_68 = 0 ; V_68 < 8 ; ++ V_68 ) {
if ( ! F_109 ( & args [ V_68 ] ) || V_87 == '\n' )
break;
V_87 = 0 ;
}
V_243 = ( T_5 ) V_103 ;
V_111 = 0 ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_111 = V_243 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_2 () ;
printf ( L_167 , V_111 ) ;
} else {
printf ( L_168 , V_173 ) ;
}
V_66 = 0 ;
}
int
F_81 ( void )
{
int V_183 ;
if( V_87 != 0 ) {
V_183 = V_87 ;
V_87 = 0 ;
} else
V_183 = F_83 () ;
while( V_183 == ' ' || V_183 == '\t' )
V_183 = F_83 () ;
return V_183 ;
}
int
F_109 ( unsigned long * V_244 )
{
int V_183 , V_61 ;
unsigned long V_102 ;
V_183 = F_81 () ;
if ( V_183 == '%' ) {
char V_245 [ 8 ] ;
int V_68 ;
for ( V_68 = 0 ; V_68 < sizeof( V_245 ) - 1 ; ++ V_68 ) {
V_183 = F_83 () ;
if ( ! isalnum ( V_183 ) ) {
V_87 = V_183 ;
break;
}
V_245 [ V_68 ] = V_183 ;
}
V_245 [ V_68 ] = 0 ;
for ( V_68 = 0 ; V_68 < V_246 ; ++ V_68 ) {
if ( strcmp ( V_247 [ V_68 ] , V_245 ) == 0 ) {
if ( V_83 == NULL ) {
printf ( L_169 ) ;
return 0 ;
}
* V_244 = ( ( unsigned long * ) V_83 ) [ V_68 ] ;
return 1 ;
}
}
printf ( L_170 , V_245 ) ;
return 0 ;
}
if ( V_183 == '0' ) {
V_183 = F_83 () ;
if ( V_183 == 'x' ) {
V_183 = F_83 () ;
} else {
V_61 = F_150 ( V_183 ) ;
if ( V_61 == V_58 ) {
V_87 = V_183 ;
* V_244 = 0 ;
return 1 ;
}
}
} else if ( V_183 == '$' ) {
int V_68 ;
for ( V_68 = 0 ; V_68 < 63 ; V_68 ++ ) {
V_183 = F_83 () ;
if ( isspace ( V_183 ) || V_183 == '\0' ) {
V_87 = V_183 ;
break;
}
V_117 [ V_68 ] = V_183 ;
}
V_117 [ V_68 ++ ] = 0 ;
* V_244 = 0 ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
* V_244 = F_151 ( V_117 ) ;
F_2 () ;
}
V_66 = 0 ;
if ( ! ( * V_244 ) ) {
printf ( L_171 , V_117 ) ;
return 0 ;
}
return 1 ;
}
V_61 = F_150 ( V_183 ) ;
if ( V_61 == V_58 ) {
V_87 = V_183 ;
return 0 ;
}
V_102 = 0 ;
do {
V_102 = ( V_102 << 4 ) + V_61 ;
V_183 = F_83 () ;
V_61 = F_150 ( V_183 ) ;
} while ( V_61 != V_58 );
V_87 = V_183 ;
* V_244 = V_102 ;
return 1 ;
}
static void
F_117 ( void )
{
int V_183 ;
V_183 = V_87 ;
V_87 = 0 ;
while( V_183 != '\n' )
V_183 = F_83 () ;
}
static int F_150 ( int V_183 )
{
if( '0' <= V_183 && V_183 <= '9' )
return V_183 - '0' ;
if( 'A' <= V_183 && V_183 <= 'F' )
return V_183 - ( 'A' - 10 ) ;
if( 'a' <= V_183 && V_183 <= 'f' )
return V_183 - ( 'a' - 10 ) ;
return V_58 ;
}
void
F_152 ( char * V_248 , int V_114 )
{
int V_183 ;
V_183 = F_81 () ;
do {
if( V_114 > 1 ) {
* V_248 ++ = V_183 ;
-- V_114 ;
}
V_183 = F_83 () ;
} while( V_183 != ' ' && V_183 != '\t' && V_183 != '\n' );
V_87 = V_183 ;
* V_248 = 0 ;
}
static void
F_80 ( void )
{
V_249 = NULL ;
}
static int
F_83 ( void )
{
if ( V_249 == NULL || * V_249 == 0 ) {
if ( F_153 ( line , sizeof( line ) ) == NULL ) {
V_249 = NULL ;
return V_58 ;
}
V_249 = line ;
}
return * V_249 ++ ;
}
static void
F_82 ( char * V_250 )
{
V_249 = V_250 ;
}
static void
F_90 ( void )
{
int type = F_83 () ;
unsigned long V_6 ;
static char V_251 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_109 ( & V_6 ) )
F_38 ( V_6 , L_98 , L_32 ) ;
V_87 = 0 ;
break;
case 's' :
F_152 ( V_251 , 64 ) ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_6 = F_151 ( V_251 ) ;
if ( V_6 )
printf ( L_172 , V_251 , V_6 ) ;
else
printf ( L_173 , V_251 ) ;
F_2 () ;
}
V_66 = 0 ;
V_87 = 0 ;
break;
}
}
static void F_38 ( unsigned long V_40 , const char * V_252 ,
const char * V_253 )
{
char * V_254 ;
const char * V_115 = NULL ;
unsigned long V_35 , V_114 ;
printf ( V_105 , V_40 ) ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_115 = F_116 ( V_40 , & V_114 , & V_35 , & V_254 ,
V_117 ) ;
F_2 () ;
F_124 ( 200 ) ;
}
V_66 = 0 ;
if ( V_115 ) {
printf ( L_174 , V_252 , V_115 , V_35 , V_114 ) ;
if ( V_254 )
printf ( L_175 , V_254 ) ;
}
printf ( L_137 , V_253 ) ;
}
void F_105 ( void )
{
int V_68 ;
unsigned long V_255 , V_256 ;
unsigned long V_257 ;
printf ( L_176 , F_17 () ) ;
for ( V_68 = 0 ; V_68 < V_258 ; V_68 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( V_255 || V_256 ) {
printf ( L_177 , V_68 , V_255 , V_256 ) ;
if ( V_255 & V_259 ) {
V_257 = V_256 & V_260 ;
if ( V_256 & V_261 ) {
printf ( L_178 ,
F_154 ( V_255 ) ,
( V_256 & ~ V_262 ) >> V_263 ,
V_257 ) ;
} else {
printf ( L_179 ,
F_155 ( V_255 ) ,
( V_256 & ~ V_262 ) >> V_264 ,
V_257 ) ;
}
} else
printf ( L_32 ) ;
}
}
}
void F_105 ( void )
{
int V_68 ;
printf ( L_180 ) ;
for ( V_68 = 0 ; V_68 < 16 ; ++ V_68 )
printf ( L_181 , F_156 ( V_68 ) ) ;
printf ( L_32 ) ;
}
static void F_106 ( void )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_265 ; V_68 ++ ) {
unsigned long V_266 , V_267 , V_268 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_182 , V_68 , V_266 , V_267 , V_268 ) ;
if ( V_266 & V_269 ) {
printf ( L_183 ,
V_266 & V_270 ,
V_267 & V_271 ,
V_267 & V_272 ,
( V_268 & V_273 ) ? 'W' : 'w' ,
( V_268 & V_274 ) ? 'I' : 'i' ,
( V_268 & V_275 ) ? 'M' : 'm' ,
( V_268 & V_276 ) ? 'G' : 'g' ,
( V_268 & V_277 ) ? 'E' : 'e' ) ;
}
printf ( L_32 ) ;
}
}
static void F_107 ( void )
{
V_171 V_278 , V_279 , V_280 ;
V_172 V_281 ;
int V_68 , V_282 , V_283 , V_284 , V_285 , V_286 , V_287 = 0 ;
int V_288 ;
static const char * V_289 [] = {
L_184 ,
L_185 ,
L_186 ,
L_187 ,
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
} ;
V_278 = F_108 ( V_290 ) ;
V_288 = ( V_278 & 3 ) + 1 ;
V_283 = ( ( V_278 >> 2 ) & 3 ) + 1 ;
V_284 = ( ( V_278 >> 6 ) & 0x1f ) + 1 ;
V_285 = ( V_278 >> 24 ) & 0xf ;
V_286 = ( V_278 >> 16 ) & 0x7f ;
if ( ( V_288 > 1 ) && ( V_278 & 0x10000 ) )
V_287 = 1 ;
printf ( L_216 ,
V_288 , V_283 , V_284 , V_285 , V_286 ) ;
V_279 = ( 1ul << V_284 ) - 1 ;
V_280 = ( 1ul << V_285 ) - 1 ;
V_281 = ( 1ull << V_286 ) - 1 ;
for ( V_282 = 0 ; V_282 < V_283 ; V_282 ++ ) {
V_171 V_291 ;
int V_292 , V_293 , V_294 = 1 ;
printf ( L_217 , V_282 ) ;
switch( V_282 ) {
case 0 :
V_291 = F_108 ( V_295 ) ;
break;
case 1 :
V_291 = F_108 ( V_296 ) ;
break;
case 2 :
V_291 = F_108 ( V_297 ) ;
break;
case 3 :
V_291 = F_108 ( V_298 ) ;
break;
default:
printf ( L_218 ) ;
continue;
}
V_292 = V_291 & 0xfff ;
V_293 = ( V_291 >> 24 ) & 0xff ;
for ( V_68 = 0 ; V_68 < V_292 ; V_68 ++ ) {
V_171 V_299 = F_157 ( V_282 ) ;
V_171 V_300 = F_158 ( V_301 ) ;
V_172 V_302 = 0 ;
V_172 V_303 ;
int V_304 = V_68 , V_305 = V_68 ;
if ( V_293 != 0 ) {
V_305 = V_68 / V_293 ;
V_304 = V_68 % V_293 ;
V_302 = V_305 * 0x1000 ;
}
V_299 |= F_159 ( V_304 ) ;
F_8 ( V_306 , V_299 ) ;
F_8 ( V_307 , V_300 ) ;
F_8 ( V_308 , V_302 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_300 = F_108 ( V_307 ) ;
V_302 = F_108 ( V_308 ) ;
V_303 = F_108 ( V_309 ) ;
if ( V_293 && ( V_68 % V_293 ) == 0 )
V_294 = 1 ;
if ( ! ( V_300 & V_310 ) )
continue;
if ( V_293 == 0 )
printf ( L_219 , V_68 ) ;
else if ( V_294 )
printf ( L_220 , V_305 , 'A' + V_304 ) ;
else
printf ( L_221 , 'A' + V_304 ) ;
V_294 = 0 ;
printf ( L_222 ,
V_302 & ~ 0x3ffull ,
( V_300 >> 16 ) & 0x3fff ,
V_289 [ ( V_300 >> 7 ) & 0x1f ] ,
V_300 & V_311 ? 'I' : ' ' ,
V_300 & V_312 ? 'P' : ' ' ,
V_300 & V_313 ? '1' : '0' ) ;
printf ( L_223 ,
V_302 & V_314 ? 'a' : ' ' ,
V_302 & V_315 ? 'v' : ' ' ,
V_302 & V_316 ? 'w' : ' ' ,
V_302 & V_317 ? 'i' : ' ' ,
V_302 & V_318 ? 'm' : ' ' ,
V_302 & V_319 ? 'g' : ' ' ,
V_302 & V_320 ? 'e' : ' ' ) ;
printf ( L_224 , V_303 & V_281 & ~ 0x7ffull ) ;
if ( V_300 & V_311 )
printf ( L_225 ,
V_289 [ ( V_303 >> 1 ) & 0x1f ] ) ;
else
printf ( L_226 ,
V_303 & V_321 ? 'x' : ' ' ,
V_303 & V_322 ? 'w' : ' ' ,
V_303 & V_323 ? 'r' : ' ' ,
V_303 & V_324 ? 'x' : ' ' ,
V_303 & V_325 ? 'w' : ' ' ,
V_303 & V_326 ? 'r' : ' ' ) ;
}
}
}
static void F_160 ( int V_327 )
{
if ( V_327 ) {
V_328 = F_59 ;
V_329 = F_68 ;
V_330 = F_63 ;
V_331 = F_64 ;
V_332 = F_67 ;
V_333 = F_66 ;
V_334 = F_69 ;
} else {
V_328 = NULL ;
V_329 = NULL ;
V_330 = NULL ;
V_331 = NULL ;
V_332 = NULL ;
V_333 = NULL ;
V_334 = NULL ;
}
}
static void F_161 ( int V_335 )
{
F_160 ( 1 ) ;
F_162 ( F_62 () ) ;
}
static int T_6 F_163 ( void )
{
F_164 ( 'x' , & V_336 ) ;
return 0 ;
}
static int T_6 F_165 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_227 , 5 ) == 0 ) {
F_160 ( 1 ) ;
V_337 = 1 ;
} else if ( strncmp ( V_2 , L_228 , 2 ) == 0 )
F_160 ( 1 ) ;
else if ( strncmp ( V_2 , L_229 , 3 ) == 0 )
V_338 = 1 ;
else if ( strncmp ( V_2 , L_230 , 4 ) == 0 )
V_84 = 1 ;
else
return 1 ;
return 0 ;
}
void T_6 F_166 ( void )
{
#ifdef F_167
if ( ! V_338 )
F_160 ( 1 ) ;
#endif
if ( V_337 )
F_162 ( NULL ) ;
}
void F_168 ( struct V_339 * V_340 )
{
struct V_341 * V_341 ;
F_169 (spu, list, full_list) {
if ( V_341 -> V_342 >= V_343 ) {
F_170 ( 1 ) ;
continue;
}
V_344 [ V_341 -> V_342 ] . V_341 = V_341 ;
V_344 [ V_341 -> V_342 ] . V_345 = 0 ;
V_344 [ V_341 -> V_342 ] . V_346 = ( unsigned long )
V_344 [ V_341 -> V_342 ] . V_341 -> V_347 ;
}
}
static void F_171 ( void )
{
struct V_341 * V_341 ;
int V_68 ;
V_172 V_251 ;
for ( V_68 = 0 ; V_68 < V_343 ; V_68 ++ ) {
if ( ! V_344 [ V_68 ] . V_341 )
continue;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_341 = V_344 [ V_68 ] . V_341 ;
V_344 [ V_68 ] . V_348 =
F_172 ( & V_341 -> V_349 -> V_350 ) ;
V_251 = F_173 ( V_341 ) ;
V_344 [ V_68 ] . V_351 = V_251 ;
V_251 &= ~ V_352 ;
F_174 ( V_341 , V_251 ) ;
F_2 () ;
F_124 ( 200 ) ;
V_344 [ V_68 ] . V_345 = 1 ;
printf ( L_231 , V_68 ,
V_344 [ V_68 ] . V_348 ?
L_232 : L_233 ) ;
} else {
V_66 = 0 ;
printf ( L_234 , V_68 ) ;
}
V_66 = 0 ;
}
}
static void F_175 ( void )
{
struct V_341 * V_341 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_343 ; V_68 ++ ) {
if ( ! V_344 [ V_68 ] . V_341 )
continue;
if ( ! V_344 [ V_68 ] . V_345 ) {
printf ( L_235
L_236 , V_68 ) ;
continue;
}
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_341 = V_344 [ V_68 ] . V_341 ;
F_174 ( V_341 , V_344 [ V_68 ] . V_351 ) ;
F_176 ( & V_341 -> V_349 -> V_350 ,
V_344 [ V_68 ] . V_348 ) ;
F_2 () ;
F_124 ( 200 ) ;
printf ( L_237 , V_68 ) ;
} else {
V_66 = 0 ;
printf ( L_238 , V_68 ) ;
}
V_66 = 0 ;
}
}
static void F_177 ( struct V_341 * V_341 )
{
printf ( L_239 , V_341 ) ;
F_178 ( V_341 , L_240 , V_342 ) ;
F_178 ( V_341 , L_137 , V_115 ) ;
F_178 ( V_341 , L_241 , V_353 ) ;
F_178 ( V_341 , L_242 , V_347 ) ;
F_178 ( V_341 , L_241 , V_354 ) ;
F_178 ( V_341 , L_240 , V_355 ) ;
F_178 ( V_341 , L_241 , V_36 ) ;
F_178 ( V_341 , L_243 , V_356 ) ;
F_178 ( V_341 , L_241 , V_357 ) ;
F_178 ( V_341 , L_241 , V_358 ) ;
F_178 ( V_341 , L_241 , V_359 ) ;
F_178 ( V_341 , L_241 , V_360 [ 0 ] ) ;
F_178 ( V_341 , L_241 , V_360 [ 1 ] ) ;
F_178 ( V_341 , L_241 , V_360 [ 2 ] ) ;
F_178 ( V_341 , L_240 , V_361 ) ;
F_178 ( V_341 , L_243 , V_144 ) ;
F_178 ( V_341 , L_242 , V_362 ) ;
F_178 ( V_341 , L_242 , V_363 ) ;
F_178 ( V_341 , L_242 , V_364 ) ;
F_178 ( V_341 , L_242 , V_365 ) ;
F_178 ( V_341 , L_241 , V_366 ) ;
F_178 ( V_341 , L_242 , V_349 ) ;
F_179 ( L_240 , V_349 -> V_350 ,
F_172 ( & V_341 -> V_349 -> V_350 ) ) ;
F_179 ( L_240 , V_349 -> V_367 ,
F_172 ( & V_341 -> V_349 -> V_367 ) ) ;
F_179 ( L_240 , V_349 -> V_368 ,
F_172 ( & V_341 -> V_349 -> V_368 ) ) ;
F_178 ( V_341 , L_242 , V_369 ) ;
F_178 ( V_341 , L_242 , V_370 ) ;
}
int
F_180 ( unsigned long V_214 , long V_215 , int V_216 )
{
return F_144 ( V_214 , V_215 , V_216 , V_371 ) ;
}
static void F_181 ( unsigned long V_211 , int V_372 )
{
unsigned long V_35 , V_6 , V_373 ;
if ( setjmp ( V_116 ) == 0 ) {
V_66 = 1 ;
F_2 () ;
V_373 = ( unsigned long ) V_344 [ V_211 ] . V_341 -> V_347 ;
F_2 () ;
F_124 ( 200 ) ;
} else {
V_66 = 0 ;
printf ( L_244 , V_211 ) ;
return;
}
V_66 = 0 ;
if ( F_109 ( & V_35 ) )
V_6 = V_373 + V_35 ;
else
V_6 = V_344 [ V_211 ] . V_346 ;
if ( V_6 >= V_373 + V_374 ) {
printf ( L_245 ) ;
return;
}
switch ( V_372 ) {
case 'i' :
V_6 += F_180 ( V_6 , 16 , 1 ) ;
V_82 = L_246 ;
break;
default:
F_143 ( V_6 , 64 ) ;
V_6 += 64 ;
V_82 = L_247 ;
break;
}
V_344 [ V_211 ] . V_346 = V_6 ;
}
static int F_95 ( void )
{
static unsigned long V_211 = 0 ;
int V_30 , V_372 = 0 ;
V_30 = F_83 () ;
switch ( V_30 ) {
case 's' :
F_171 () ;
break;
case 'r' :
F_175 () ;
break;
case 'd' :
V_372 = F_83 () ;
if ( isxdigit ( V_372 ) || V_372 == '\n' )
V_87 = V_372 ;
case 'f' :
F_109 ( & V_211 ) ;
if ( V_211 >= V_343 || ! V_344 [ V_211 ] . V_341 ) {
printf ( L_248 ) ;
return 0 ;
}
switch ( V_30 ) {
case 'f' :
F_177 ( V_344 [ V_211 ] . V_341 ) ;
break;
default:
F_181 ( V_211 , V_372 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_95 ( void )
{
return - 1 ;
}
