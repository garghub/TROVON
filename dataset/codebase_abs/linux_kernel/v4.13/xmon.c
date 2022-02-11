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
V_30 = F_31 ( V_22 -> V_37 , & V_33 ) ;
if ( V_30 != NULL ) {
V_22 -> V_37 = V_30 -> V_38 + V_33 ;
F_32 ( & V_30 -> V_39 ) ;
}
F_33 () ;
#ifdef F_28
V_35 = F_16 () ;
if ( F_34 ( V_35 , & V_19 ) ) {
if ( V_40 )
longjmp ( V_41 , 1 ) ;
F_15 () ;
F_35 ( V_22 ) ;
printf ( L_3
L_4 ,
V_35 , V_22 -> V_42 , F_36 ( F_37 ( V_22 ) ) ) ;
F_19 () ;
longjmp ( V_43 [ V_35 ] , 1 ) ;
}
if ( setjmp ( V_31 ) != 0 ) {
if ( ! V_44 || ! V_45 ) {
F_15 () ;
printf ( L_5
L_6 , V_35 ) ;
F_19 () ;
goto V_46;
}
V_36 = ! ( V_47 && V_35 == V_48 ) ;
goto V_49;
}
V_43 [ V_35 ] = V_31 ;
V_30 = NULL ;
if ( ( V_22 -> V_25 & ( V_50 | V_51 | V_52 ) ) == ( V_50 | V_52 ) )
V_30 = F_38 ( V_22 -> V_37 ) ;
if ( V_30 || F_25 ( V_22 ) )
V_27 = 0 ;
if ( ! V_27 ) {
F_15 () ;
F_35 ( V_22 ) ;
if ( V_30 ) {
printf ( L_7 ,
V_35 , F_39 ( V_30 ) ) ;
F_40 ( V_22 -> V_37 , L_8 , L_9 ) ;
}
if ( F_25 ( V_22 ) )
printf ( L_10
L_11 ) ;
F_19 () ;
}
F_41 ( V_35 , & V_19 ) ;
V_46:
V_36 = 1 ;
while ( V_36 && ! V_45 ) {
if ( V_44 == 0 ) {
if ( V_27 )
goto V_53;
V_36 = F_42 ( 0 , & V_44 ) ;
}
F_24 () ;
}
if ( ! V_36 && ! V_45 ) {
int V_20 = F_43 () ;
V_48 = V_35 ;
F_44 () ;
if ( V_20 > 1 ) {
if ( F_37 ( V_22 ) != 0x100 || ! F_22 ( V_20 ) )
F_45 () ;
F_22 ( V_20 ) ;
}
F_46 () ;
F_11 () ;
if ( V_30 || F_37 ( V_22 ) == 0xd00 )
F_47 ( V_22 -> V_37 , 1 , 0 ) ;
printf ( L_12 ) ;
F_44 () ;
V_45 = 1 ;
F_24 () ;
}
V_49:
while ( V_44 ) {
if ( V_36 ) {
if ( V_35 == V_48 ) {
if ( ! F_42 ( 0 , & V_47 ) ) {
V_36 = 0 ;
continue;
}
while ( V_35 == V_48 )
F_24 () ;
}
F_24 () ;
} else {
V_28 = F_48 ( V_22 ) ;
if ( V_28 != 0 ) {
F_49 () ;
V_45 = 0 ;
F_50 () ;
V_44 = 0 ;
break;
}
V_36 = 1 ;
}
}
V_53:
F_51 ( V_35 , & V_19 ) ;
V_43 [ V_35 ] = NULL ;
#else
if ( V_44 ) {
printf ( L_13 ,
V_22 -> V_42 , F_36 ( F_37 ( V_22 ) ) ) ;
longjmp ( V_43 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_31 ) == 0 ) {
V_43 [ 0 ] = V_31 ;
V_44 = 1 ;
F_35 ( V_22 ) ;
V_30 = F_38 ( V_22 -> V_37 ) ;
if ( V_30 ) {
printf ( L_14 , F_39 ( V_30 ) ) ;
F_40 ( V_22 -> V_37 , L_8 , L_9 ) ;
}
if ( F_25 ( V_22 ) )
printf ( L_10
L_11 ) ;
F_46 () ;
F_11 () ;
if ( V_30 || F_37 ( V_22 ) == 0xd00 )
F_47 ( V_22 -> V_37 , 1 , 0 ) ;
printf ( L_12 ) ;
}
V_28 = F_48 ( V_22 ) ;
F_49 () ;
V_44 = 0 ;
#endif
#ifdef F_52
if ( V_22 -> V_25 & V_54 ) {
V_30 = F_38 ( V_22 -> V_37 ) ;
if ( V_30 != NULL ) {
V_22 -> V_37 = ( unsigned long ) & V_30 -> V_55 [ 0 ] ;
F_53 ( & V_30 -> V_39 ) ;
}
}
#else
if ( ( V_22 -> V_25 & ( V_50 | V_51 | V_52 ) ) == ( V_50 | V_52 ) ) {
V_30 = F_38 ( V_22 -> V_37 ) ;
if ( V_30 != NULL ) {
int V_56 = F_54 ( V_22 , V_30 -> V_55 [ 0 ] ) ;
if ( V_56 == 0 ) {
V_22 -> V_37 = ( unsigned long ) & V_30 -> V_55 [ 0 ] ;
F_53 ( & V_30 -> V_39 ) ;
} else if ( V_56 < 0 ) {
printf ( L_15 ,
( F_55 ( V_30 -> V_55 [ 0 ] ) ? L_16 : L_17 ) ) ;
}
}
}
#endif
F_56 () ;
F_57 () ;
F_58 ( V_34 ) ;
return V_28 != 'X' && V_28 != V_57 ;
}
int F_59 ( struct V_21 * V_58 )
{
struct V_21 V_22 ;
if ( V_58 == NULL ) {
F_60 ( & V_22 ) ;
V_58 = & V_22 ;
}
return F_27 ( V_58 , 0 ) ;
}
T_1 F_61 ( int V_59 , void * V_60 )
{
unsigned long V_34 ;
F_29 ( V_34 ) ;
printf ( L_18 ) ;
F_59 ( F_62 () ) ;
F_58 ( V_34 ) ;
return V_61 ;
}
static int F_63 ( struct V_21 * V_22 )
{
struct V_29 * V_30 ;
unsigned long V_33 ;
if ( ( V_22 -> V_25 & ( V_50 | V_51 | V_52 ) ) != ( V_50 | V_52 ) )
return 0 ;
V_30 = F_31 ( V_22 -> V_37 , & V_33 ) ;
if ( V_30 != NULL && V_33 == 4 ) {
V_22 -> V_37 = V_30 -> V_38 + 4 ;
F_32 ( & V_30 -> V_39 ) ;
return 1 ;
}
V_30 = F_38 ( V_22 -> V_37 ) ;
if ( ! V_30 )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_64 ( struct V_21 * V_22 )
{
if ( F_65 ( V_22 ) )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_66 ( struct V_21 * V_22 )
{
if ( ( V_22 -> V_25 & ( V_50 | V_51 | V_52 ) ) != ( V_50 | V_52 ) )
return 0 ;
if ( V_62 . V_63 == 0 )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_67 ( struct V_21 * V_22 )
{
if ( ( V_22 -> V_25 & ( V_50 | V_51 | V_52 ) ) != ( V_50 | V_52 ) )
return 0 ;
if ( V_64 == NULL )
return 0 ;
F_27 ( V_22 , 0 ) ;
return 1 ;
}
static int F_68 ( struct V_21 * V_22 )
{
#ifdef F_28
if ( V_44 && ! F_34 ( F_16 () , & V_19 ) )
F_27 ( V_22 , 1 ) ;
#endif
return 0 ;
}
static int F_69 ( struct V_21 * V_22 )
{
struct V_29 * V_30 ;
unsigned long V_33 ;
if ( V_44 && V_65 )
F_70 ( V_22 ) ;
if ( ( V_22 -> V_25 & ( V_50 | V_51 | V_52 ) ) == ( V_50 | V_52 ) ) {
V_30 = F_31 ( V_22 -> V_37 , & V_33 ) ;
if ( V_30 != NULL ) {
V_22 -> V_37 = V_30 -> V_38 + V_33 ;
F_32 ( & V_30 -> V_39 ) ;
}
}
return 0 ;
}
static struct V_29 * F_38 ( unsigned long V_66 )
{
int V_67 ;
struct V_29 * V_30 ;
V_30 = V_68 ;
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 , ++ V_30 )
if ( V_30 -> V_63 && V_66 == V_30 -> V_38 )
return V_30 ;
return NULL ;
}
static struct V_29 * F_31 ( unsigned long V_37 , unsigned long * V_70 )
{
unsigned long V_71 ;
V_71 = V_37 - ( unsigned long ) V_68 ;
if ( V_71 >= sizeof( V_68 ) )
return NULL ;
V_71 %= sizeof( struct V_29 ) ;
if ( V_71 != F_71 ( struct V_29 , V_55 [ 0 ] )
&& V_71 != F_71 ( struct V_29 , V_55 [ 1 ] ) )
return NULL ;
* V_70 = V_71 - F_71 ( struct V_29 , V_55 [ 0 ] ) ;
return (struct V_29 * ) ( V_37 - V_71 ) ;
}
static struct V_29 * F_72 ( unsigned long V_72 )
{
struct V_29 * V_30 ;
V_72 &= ~ 3UL ;
V_30 = F_38 ( V_72 ) ;
if ( V_30 )
return V_30 ;
for ( V_30 = V_68 ; V_30 < & V_68 [ V_69 ] ; ++ V_30 ) {
if ( ! V_30 -> V_63 && F_73 ( & V_30 -> V_39 ) == 0 ) {
V_30 -> V_38 = V_72 ;
V_30 -> V_55 [ 1 ] = V_73 ;
F_4 ( & V_30 -> V_55 [ 1 ] ) ;
return V_30 ;
}
}
printf ( L_19 ) ;
return NULL ;
}
static void F_49 ( void )
{
int V_67 ;
struct V_29 * V_30 ;
V_30 = V_68 ;
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 , ++ V_30 ) {
if ( ( V_30 -> V_63 & ( V_74 | V_75 ) ) == 0 )
continue;
if ( F_74 ( V_30 -> V_38 , & V_30 -> V_55 [ 0 ] , 4 ) != 4 ) {
printf ( L_20
L_21 , V_30 -> V_38 ) ;
V_30 -> V_63 = 0 ;
continue;
}
if ( F_75 ( V_30 -> V_55 [ 0 ] ) || F_55 ( V_30 -> V_55 [ 0 ] ) ) {
printf ( L_22
L_23 , V_30 -> V_38 ) ;
V_30 -> V_63 = 0 ;
continue;
}
F_4 ( & V_30 -> V_55 [ 0 ] ) ;
if ( V_30 -> V_63 & V_75 )
continue;
if ( F_76 ( ( unsigned int * ) V_30 -> V_38 ,
V_73 ) != 0 ) {
printf ( L_24
L_21 , V_30 -> V_38 ) ;
V_30 -> V_63 &= ~ V_74 ;
continue;
}
F_4 ( ( void * ) V_30 -> V_38 ) ;
}
}
static void F_56 ( void )
{
struct V_76 V_77 ;
if ( V_62 . V_63 ) {
V_77 . V_38 = V_62 . V_38 ;
V_77 . type = ( V_62 . V_63 & V_78 ) | V_79 ;
V_77 . V_80 = 8 ;
F_77 ( & V_77 ) ;
}
if ( V_64 )
F_10 ( V_64 -> V_38 ) ;
}
static void F_46 ( void )
{
int V_67 ;
struct V_29 * V_30 ;
unsigned V_55 ;
V_30 = V_68 ;
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 , ++ V_30 ) {
if ( ( V_30 -> V_63 & ( V_74 | V_75 ) ) != V_74 )
continue;
if ( F_74 ( V_30 -> V_38 , & V_55 , 4 ) == 4
&& V_55 == V_73
&& F_76 (
( unsigned int * ) V_30 -> V_38 , V_30 -> V_55 [ 0 ] ) != 0 )
printf ( L_25 ,
V_30 -> V_38 ) ;
else
F_4 ( ( void * ) V_30 -> V_38 ) ;
}
}
static void F_33 ( void )
{
F_78 () ;
F_7 ( 0 ) ;
}
static void F_79 ( void )
{
unsigned long V_81 ;
if ( ! F_80 ( & V_81 ) ) {
printf ( L_26 ) ;
V_81 = 0 ;
}
F_81 ( V_81 ) ;
}
static int
F_48 ( struct V_21 * V_58 )
{
int V_28 = 0 ;
V_82 = NULL ;
V_83 = V_58 ;
F_82 ( V_58 -> V_84 [ 1 ] , V_58 -> V_85 , V_58 -> V_37 ) ;
for(; ; ) {
#ifdef F_28
printf ( L_27 , F_16 () ) ;
#endif
printf ( L_28 ) ;
F_83 () ;
V_86 = 0 ;
V_28 = F_84 () ;
if( V_28 == '\n' ) {
if ( V_82 == NULL )
continue;
F_85 ( V_82 ) ;
V_82 = NULL ;
V_28 = F_86 () ;
}
switch ( V_28 ) {
case 'm' :
V_28 = F_86 () ;
switch ( V_28 ) {
case 'm' :
case 's' :
case 'd' :
F_87 ( V_28 ) ;
break;
case 'l' :
F_88 () ;
break;
case 'z' :
F_89 () ;
break;
case 'i' :
F_90 ( 0 , NULL ) ;
break;
default:
V_86 = V_28 ;
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
F_94 ( V_58 ) ;
break;
case 'e' :
F_35 ( V_58 ) ;
break;
case 'S' :
F_95 () ;
break;
case 't' :
F_96 ( V_58 ) ;
break;
case 'f' :
F_97 () ;
break;
case 's' :
if ( F_98 () == 0 )
break;
if ( F_99 ( V_58 ) )
return V_28 ;
break;
case 'x' :
case 'X' :
return V_28 ;
case V_57 :
printf ( L_29 ) ;
F_100 ( 2000 ) ;
return V_28 ;
case '?' :
F_101 ( V_87 ) ;
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
case 'P' :
F_107 () ;
break;
#ifdef F_108
case 'u' :
F_109 () ;
break;
#elif F_26 ( V_88 )
case 'u' :
F_110 () ;
break;
#elif F_26 ( V_24 )
case 'u' :
F_111 () ;
break;
#endif
default:
printf ( L_30 ) ;
do {
if ( ' ' < V_28 && V_28 <= '~' )
putchar ( V_28 ) ;
else
printf ( L_31 , V_28 ) ;
V_28 = F_86 () ;
} while ( V_28 != '\n' );
printf ( L_32 ) ;
break;
}
}
}
static int F_99 ( struct V_21 * V_22 )
{
V_22 -> V_25 |= V_54 ;
F_9 ( V_89 , F_112 ( V_89 ) | V_90 | V_91 ) ;
return 1 ;
}
static int F_99 ( struct V_21 * V_22 )
{
unsigned int V_55 ;
int V_56 ;
if ( ( V_22 -> V_25 & ( V_52 | V_51 | V_50 ) ) == ( V_52 | V_50 ) ) {
if ( F_74 ( V_22 -> V_37 , & V_55 , 4 ) == 4 ) {
V_56 = F_54 ( V_22 , V_55 ) ;
if ( V_56 < 0 ) {
printf ( L_15 ,
( F_55 ( V_55 ) ? L_16 : L_17 ) ) ;
return 0 ;
}
if ( V_56 > 0 ) {
V_22 -> V_42 = 0xd00 | ( V_22 -> V_42 & 1 ) ;
printf ( L_33 ) ;
F_40 ( V_22 -> V_37 , L_8 , L_34 ) ;
F_47 ( V_22 -> V_37 , 1 , 0 ) ;
return 0 ;
}
}
}
V_22 -> V_25 |= V_92 ;
return 1 ;
}
static void F_105 ( void )
{
int V_28 ;
V_28 = F_86 () ;
if ( V_28 == 'r' )
V_93 . V_94 ( NULL ) ;
else if ( V_28 == 'h' )
V_93 . V_95 () ;
else if ( V_28 == 'p' )
if ( V_96 )
V_96 () ;
}
static int F_104 ( void )
{
#ifdef F_28
unsigned long V_35 , V_97 , V_98 ;
int V_17 ;
if ( ! F_80 ( & V_35 ) ) {
printf ( L_35 ) ;
V_98 = V_97 = V_99 ;
F_113 (cpu) {
if ( F_34 ( V_35 , & V_19 ) ) {
if ( V_35 == V_98 + 1 ) {
V_98 = V_35 ;
} else {
if ( V_98 != V_97 )
printf ( L_36 , V_98 ) ;
V_98 = V_97 = V_35 ;
printf ( L_37 , V_35 ) ;
}
}
}
if ( V_98 != V_97 )
printf ( L_36 , V_98 ) ;
printf ( L_34 ) ;
return 0 ;
}
if ( ! F_34 ( V_35 , & V_19 ) ) {
printf ( L_38 , V_35 ) ;
return 0 ;
}
V_47 = 0 ;
F_44 () ;
V_48 = V_35 ;
V_17 = 10000000 ;
while ( ! V_47 ) {
if ( -- V_17 == 0 ) {
if ( F_42 ( 0 , & V_47 ) )
break;
F_44 () ;
V_48 = F_16 () ;
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
F_103 ( void )
{
unsigned int V_67 ;
unsigned short V_100 ;
unsigned char V_101 ;
if ( ! F_80 ( & V_102 ) )
return;
if ( ! F_80 ( & V_103 ) )
return;
V_100 = 0xffff ;
for ( V_67 = 0 ; V_67 < V_103 ; ++ V_67 ) {
if ( F_74 ( V_102 + V_67 , & V_101 , 1 ) == 0 ) {
printf ( L_40 V_104 L_34 , V_102 + V_67 ) ;
break;
}
V_100 = F_114 ( V_100 , V_101 ) ;
}
printf ( L_41 , V_100 ) ;
}
static long F_115 ( unsigned long V_6 )
{
unsigned int V_55 ;
V_6 &= ~ 3 ;
if ( ! F_116 ( V_6 ) ) {
printf ( L_42 ) ;
return 0 ;
}
if ( ! F_74 ( V_6 , & V_55 , sizeof( V_55 ) ) ) {
printf ( L_43 , V_6 ) ;
return 0 ;
}
if ( F_75 ( V_55 ) || F_55 ( V_55 ) ) {
printf ( L_44
L_45 ) ;
return 0 ;
}
return 1 ;
}
static void
F_102 ( void )
{
int V_28 ;
unsigned long V_72 ;
int V_67 ;
struct V_29 * V_30 ;
V_28 = F_86 () ;
switch ( V_28 ) {
#ifndef F_117
static const char V_105 [] = L_46 ;
int V_106 ;
case 'd' :
V_106 = 7 ;
V_28 = F_86 () ;
if ( V_28 == 'r' )
V_106 = 5 ;
else if ( V_28 == 'w' )
V_106 = 6 ;
else
V_86 = V_28 ;
V_62 . V_38 = 0 ;
V_62 . V_63 = 0 ;
if ( F_80 ( & V_62 . V_38 ) ) {
if ( ! F_116 ( V_62 . V_38 ) ) {
printf ( V_105 ) ;
break;
}
V_62 . V_38 &= ~ V_78 ;
V_62 . V_63 = V_106 | V_107 ;
}
break;
case 'i' :
if ( ! F_8 ( V_3 ) ) {
printf ( L_47
L_48 ) ;
break;
}
if ( V_64 ) {
V_64 -> V_63 &= ~ V_75 ;
V_64 = NULL ;
}
if ( ! F_80 ( & V_72 ) )
break;
if ( ! F_115 ( V_72 ) )
break;
V_30 = F_72 ( V_72 ) ;
if ( V_30 != NULL ) {
V_30 -> V_63 |= V_75 ;
V_64 = V_30 ;
}
break;
#endif
case 'c' :
if ( ! F_80 ( & V_72 ) ) {
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 )
V_68 [ V_67 ] . V_63 = 0 ;
V_64 = NULL ;
V_62 . V_63 = 0 ;
printf ( L_49 ) ;
break;
}
if ( V_72 <= V_69 && V_72 >= 1 ) {
V_30 = & V_68 [ V_72 - 1 ] ;
} else {
V_30 = F_38 ( V_72 ) ;
if ( V_30 == NULL ) {
printf ( L_50 , V_72 ) ;
break;
}
}
printf ( L_51 , F_39 ( V_30 ) ) ;
F_40 ( V_30 -> V_38 , L_8 , L_9 ) ;
V_30 -> V_63 = 0 ;
break;
default:
V_86 = V_28 ;
V_28 = F_84 () ;
if ( V_28 == '?' ) {
printf ( V_108 ) ;
break;
}
V_86 = V_28 ;
if ( ! F_80 ( & V_72 ) ) {
printf ( L_52 ) ;
if ( V_62 . V_63 ) {
printf ( L_53 V_104 L_54 , V_62 . V_38 ) ;
if ( V_62 . V_63 & 1 )
printf ( L_55 ) ;
if ( V_62 . V_63 & 2 )
printf ( L_56 ) ;
printf ( L_57 ) ;
}
for ( V_30 = V_68 ; V_30 < & V_68 [ V_69 ] ; ++ V_30 ) {
if ( ! V_30 -> V_63 )
continue;
printf ( L_58 , F_39 ( V_30 ) ,
( V_30 -> V_63 & V_75 ) ? L_59 : L_60 ) ;
F_40 ( V_30 -> V_38 , L_61 , L_34 ) ;
}
break;
}
if ( ! F_115 ( V_72 ) )
break;
V_30 = F_72 ( V_72 ) ;
if ( V_30 != NULL )
V_30 -> V_63 |= V_74 ;
break;
}
}
static
const char * F_36 ( unsigned long V_109 )
{
char * V_110 ;
switch ( V_109 ) {
case 0x100 : V_110 = L_62 ; break;
case 0x200 : V_110 = L_63 ; break;
case 0x300 : V_110 = L_64 ; break;
case 0x380 :
if ( F_118 () )
V_110 = L_65 ;
else
V_110 = L_66 ;
break;
case 0x400 : V_110 = L_67 ; break;
case 0x480 :
if ( F_118 () )
V_110 = L_68 ;
else
V_110 = L_69 ;
break;
case 0x500 : V_110 = L_70 ; break;
case 0x600 : V_110 = L_71 ; break;
case 0x700 : V_110 = L_72 ; break;
case 0x800 : V_110 = L_73 ; break;
case 0x900 : V_110 = L_74 ; break;
case 0x980 : V_110 = L_75 ; break;
case 0xa00 : V_110 = L_76 ; break;
case 0xc00 : V_110 = L_77 ; break;
case 0xd00 : V_110 = L_78 ; break;
case 0xe40 : V_110 = L_79 ; break;
case 0xe60 : V_110 = L_80 ; break;
case 0xe80 : V_110 = L_81 ; break;
case 0xf00 : V_110 = L_82 ; break;
case 0xf20 : V_110 = L_83 ; break;
case 0x1300 : V_110 = L_84 ; break;
case 0x1500 : V_110 = L_85 ; break;
case 0x1700 : V_110 = L_86 ; break;
default: V_110 = L_87 ;
}
return V_110 ;
}
static void F_119 ( unsigned long V_66 , unsigned long * V_111 ,
unsigned long * V_112 )
{
unsigned long V_113 , V_33 ;
const char * V_114 ;
* V_111 = * V_112 = 0 ;
if ( V_66 == 0 )
return;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_114 = F_120 ( V_66 , & V_113 , & V_33 , NULL , V_115 ) ;
if ( V_114 != NULL ) {
* V_111 = V_66 - V_33 ;
* V_112 = V_66 - V_33 + V_113 ;
}
F_3 () ;
}
V_65 = 0 ;
}
static void F_82 ( unsigned long V_116 , unsigned long V_117 ,
unsigned long V_66 )
{
int V_118 = 64 ;
unsigned long V_119 ;
unsigned long V_120 ;
unsigned long V_121 ;
struct V_21 V_22 ;
while ( V_118 -- ) {
if ( ! F_116 ( V_116 ) ) {
if ( V_116 != 0 )
printf ( L_88 , V_116 ) ;
break;
}
if ( ! F_74 ( V_116 + V_122 , & V_119 , sizeof( unsigned long ) )
|| ! F_74 ( V_116 , & V_120 , sizeof( unsigned long ) ) ) {
printf ( L_89 , V_116 ) ;
break;
}
if ( ( V_66 | V_117 ) != 0 ) {
unsigned long V_123 , V_124 ;
unsigned long V_125 ;
int V_126 = 1 ;
F_119 ( V_66 , & V_123 , & V_124 ) ;
V_125 = 0 ;
if ( V_120 > V_116 )
F_74 ( V_120 + V_122 , & V_125 ,
sizeof( unsigned long ) ) ;
if ( V_117 == V_119 ) {
if ( ! F_116 ( V_117 )
|| ( V_123 <= V_117 && V_117 < V_124 ) )
V_126 = 0 ;
} else if ( V_117 == V_125 ) {
V_126 = 0 ;
} else if ( F_116 ( V_117 )
&& ! ( V_123 <= V_117 && V_117 < V_124 ) ) {
printf ( L_90 ) ;
F_40 ( V_117 , L_8 , L_34 ) ;
}
if ( V_126 ) {
printf ( L_91 V_104 L_92 , V_116 ) ;
F_40 ( V_119 , L_8 , L_93 ) ;
}
V_66 = V_117 = 0 ;
} else {
printf ( L_91 V_104 L_92 , V_116 ) ;
F_40 ( V_119 , L_8 , L_34 ) ;
}
if ( F_74 ( V_116 + V_127 , & V_121 , sizeof( unsigned long ) )
&& V_121 == V_128 ) {
if ( F_74 ( V_116 + V_129 , & V_22 , sizeof( V_22 ) )
!= sizeof( V_22 ) ) {
printf ( L_94 ,
V_116 + V_129 ) ;
break;
}
printf ( L_95 , V_22 . V_42 ,
F_36 ( F_37 ( & V_22 ) ) ) ;
V_66 = V_22 . V_37 ;
V_117 = V_22 . V_85 ;
F_40 ( V_66 , L_8 , L_34 ) ;
}
if ( V_120 == 0 )
break;
V_116 = V_120 ;
}
}
static void F_96 ( struct V_21 * V_58 )
{
unsigned long V_116 ;
if ( F_80 ( & V_116 ) )
F_82 ( V_116 , 0 , 0 ) ;
else
F_82 ( V_58 -> V_84 [ 1 ] , V_58 -> V_85 , V_58 -> V_37 ) ;
F_121 () ;
}
static void F_122 ( struct V_21 * V_22 )
{
#ifdef F_123
const struct V_130 * V_131 ;
unsigned long V_6 ;
if ( V_22 -> V_25 & V_51 )
return;
V_6 = V_22 -> V_37 ;
if ( ! F_116 ( V_6 ) )
return;
V_131 = F_124 ( V_22 -> V_37 ) ;
if ( V_131 == NULL )
return;
if ( F_125 ( V_131 ) )
return;
#ifdef F_126
printf ( L_96 ,
V_131 -> V_132 , V_131 -> line ) ;
#else
printf ( L_97 , ( void * ) V_131 -> V_133 ) ;
#endif
#endif
}
static void F_35 ( struct V_21 * V_134 )
{
unsigned long V_42 ;
#ifdef F_28
printf ( L_98 , F_16 () ) ;
#endif
V_42 = F_37 ( V_134 ) ;
printf ( L_99 , V_134 -> V_42 , F_36 ( V_42 ) , V_134 ) ;
printf ( L_100 ) ;
F_40 ( V_134 -> V_37 , L_101 , L_34 ) ;
printf ( L_102 , V_134 -> V_85 ) ;
F_40 ( V_134 -> V_85 , L_101 , L_34 ) ;
printf ( L_103 , V_134 -> V_84 [ 1 ] ) ;
printf ( L_104 , V_134 -> V_25 ) ;
if ( V_42 == 0x300 || V_42 == 0x380 || V_42 == 0x600 || V_42 == 0x200 ) {
printf ( L_105 , V_134 -> V_135 ) ;
if ( V_42 != 0x380 )
printf ( L_106 , V_134 -> V_136 ) ;
}
printf ( L_107 , V_137 ) ;
#ifdef F_127
printf ( L_108 ,
V_138 , V_138 -> V_139 , V_138 -> V_140 ) ;
#endif
if ( V_137 ) {
printf ( L_109 ,
V_137 -> V_141 , V_137 -> V_142 ) ;
}
if ( V_42 == 0x700 )
F_122 ( V_134 ) ;
printf ( V_143 ) ;
}
static void F_94 ( struct V_21 * V_134 )
{
int V_144 , V_42 ;
unsigned long V_145 ;
struct V_21 V_22 ;
if ( F_80 ( & V_145 ) ) {
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_22 = * (struct V_21 * ) V_145 ;
F_3 () ;
F_128 ( 200 ) ;
} else {
V_65 = 0 ;
printf ( L_110 V_104 L_34 ,
V_145 ) ;
return;
}
V_65 = 0 ;
V_134 = & V_22 ;
}
#ifdef F_127
if ( F_129 ( V_134 ) ) {
for ( V_144 = 0 ; V_144 < 16 ; ++ V_144 )
printf ( L_111 V_104 L_112 V_104 L_34 ,
V_144 , V_134 -> V_84 [ V_144 ] , V_144 + 16 , V_134 -> V_84 [ V_144 + 16 ] ) ;
} else {
for ( V_144 = 0 ; V_144 < 7 ; ++ V_144 )
printf ( L_111 V_104 L_112 V_104 L_34 ,
V_144 , V_134 -> V_84 [ V_144 ] , V_144 + 7 , V_134 -> V_84 [ V_144 + 7 ] ) ;
}
#else
for ( V_144 = 0 ; V_144 < 32 ; ++ V_144 ) {
printf ( L_113 , V_144 , V_134 -> V_84 [ V_144 ] ,
( V_144 & 3 ) == 3 ? L_34 : L_114 ) ;
if ( V_144 == 12 && ! F_129 ( V_134 ) ) {
printf ( L_34 ) ;
break;
}
}
#endif
printf ( L_115 ) ;
F_40 ( V_134 -> V_37 , L_8 , L_34 ) ;
if ( F_37 ( V_134 ) != 0xc00 && F_8 ( V_146 ) ) {
printf ( L_116 ) ;
F_40 ( V_134 -> V_147 , L_8 , L_34 ) ;
}
printf ( L_117 ) ;
F_40 ( V_134 -> V_85 , L_8 , L_34 ) ;
printf ( L_118 V_104 L_119 , V_134 -> V_25 , V_134 -> V_148 ) ;
printf ( L_120 V_104 L_121 V_104 L_122 ,
V_134 -> V_149 , V_134 -> V_150 , V_134 -> V_42 ) ;
V_42 = F_37 ( V_134 ) ;
if ( V_42 == 0x300 || V_42 == 0x380 || V_42 == 0x600 )
printf ( L_123 V_104 L_124 , V_134 -> V_135 , V_134 -> V_136 ) ;
}
static void F_97 ( void )
{
int V_28 ;
unsigned long V_151 ;
V_28 = F_86 () ;
if ( V_28 != 'i' )
V_86 = V_28 ;
F_80 ( ( void * ) & V_102 ) ;
if ( V_86 != '\n' )
V_86 = 0 ;
V_151 = 1 ;
F_80 ( & V_151 ) ;
V_151 = ( V_151 + V_152 - 1 ) / V_152 ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
if ( V_28 != 'i' ) {
for (; V_151 > 0 ; -- V_151 , V_102 += V_152 )
F_5 ( ( void * ) V_102 ) ;
} else {
for (; V_151 > 0 ; -- V_151 , V_102 += V_152 )
F_6 ( ( void * ) V_102 ) ;
}
F_3 () ;
F_128 ( 200 ) ;
}
V_65 = 0 ;
}
static int
F_130 ( int V_144 , unsigned long * V_153 )
{
unsigned long V_110 = - 1UL ;
int V_154 = 0 ;
if ( setjmp ( V_41 ) == 0 ) {
V_40 = 1 ;
F_3 () ;
V_110 = F_131 ( V_144 , * V_153 ) ;
F_3 () ;
* V_153 = V_110 ;
V_154 = 1 ;
}
V_40 = 0 ;
return V_154 ;
}
static void
F_132 ( int V_144 , unsigned long V_155 )
{
if ( setjmp ( V_41 ) == 0 ) {
V_40 = 1 ;
F_3 () ;
F_133 ( V_144 , V_155 ) ;
F_3 () ;
} else {
printf ( L_125 , V_144 , V_144 ) ;
}
V_40 = 0 ;
}
static void F_134 ( void )
{
#ifdef F_127
if ( ! F_8 ( V_156 ) )
return;
printf ( L_126 ,
F_112 ( V_157 ) , F_112 ( V_158 ) , F_112 ( V_159 ) ) ;
printf ( L_127 ,
F_112 ( V_160 ) , F_112 ( V_161 ) , F_112 ( V_162 ) ) ;
if ( ! ( F_135 () & V_163 ) )
return;
printf ( L_128 ,
F_112 ( V_164 ) , F_112 ( V_165 ) , F_112 ( V_166 ) ) ;
printf ( L_129 ,
F_112 ( V_167 ) , F_112 ( V_168 ) , F_112 ( V_169 ) ) ;
printf ( L_130 ,
F_112 ( V_170 ) , F_112 ( V_171 ) , F_112 ( V_172 ) ) ;
printf ( L_131 ,
F_112 ( V_173 ) , F_112 ( V_174 ) ) ;
printf ( L_132 ,
F_112 ( V_175 ) , F_112 ( V_176 ) ) ;
#endif
}
static void F_136 ( void )
{
#ifdef F_127
unsigned long V_25 ;
if ( ! F_8 ( V_3 ) )
return;
printf ( L_133 ,
F_112 ( V_177 ) , F_112 ( V_178 ) , F_112 ( V_179 ) ) ;
printf ( L_134 ,
F_112 ( V_180 ) , F_112 ( V_181 ) , F_112 ( V_182 ) ) ;
V_25 = F_135 () ;
if ( V_25 & V_183 ) {
printf ( L_135 ,
F_112 ( V_184 ) , F_112 ( V_185 ) ,
F_112 ( V_186 ) ) ;
}
printf ( L_136 ,
F_112 ( V_187 ) , F_112 ( V_188 ) , F_112 ( V_189 ) ) ;
printf ( L_137 ,
F_112 ( V_190 ) , F_112 ( V_191 ) ,
F_112 ( V_192 ) , F_112 ( V_193 ) ) ;
printf ( L_138 ,
F_112 ( V_194 ) , F_112 ( V_195 ) , F_112 ( V_196 ) ) ;
printf ( L_139 ,
F_112 ( V_197 ) , F_112 ( V_198 ) , F_112 ( V_199 ) ) ;
printf ( L_140 ,
F_112 ( V_200 ) , F_112 ( V_201 ) , F_112 ( V_202 ) ) ;
if ( ! ( V_25 & V_163 ) )
return;
printf ( L_141 ,
F_112 ( V_203 ) , F_112 ( V_204 ) , F_112 ( V_205 ) ) ;
printf ( L_142 ,
F_112 ( V_206 ) , F_112 ( V_207 ) , F_112 ( V_5 ) ) ;
#endif
}
static void F_137 ( int V_208 , bool V_209 )
{
unsigned long V_155 ;
V_155 = 0xdeadbeef ;
if ( ! F_130 ( V_208 , & V_155 ) ) {
printf ( L_143 , V_208 , V_208 ) ;
return;
}
if ( V_155 == 0xdeadbeef ) {
V_155 = 0x0badcafe ;
if ( ! F_130 ( V_208 , & V_155 ) ) {
printf ( L_143 , V_208 , V_208 ) ;
return;
}
if ( V_155 == 0x0badcafe ) {
if ( V_209 )
printf ( L_144 , V_208 , V_208 ) ;
return;
}
}
printf ( L_145 , V_208 , V_208 , V_155 ) ;
}
static void F_95 ( void )
{
static unsigned long V_210 ;
int V_28 ;
int V_208 ;
V_28 = F_84 () ;
switch ( V_28 ) {
case '\n' : {
unsigned long V_116 , V_211 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_146 V_104 L_147 V_104 L_34 ,
F_135 () , F_112 ( V_212 ) ) ;
printf ( L_148 V_104 L_149 V_104 L_34 ,
F_112 ( V_213 ) , F_112 ( V_214 ) ) ;
printf ( L_150 V_104 L_151 V_104 L_34 ,
F_112 ( V_215 ) , F_112 ( V_216 ) ) ;
printf ( L_152 V_104 L_153 V_104 L_34 , V_116 , F_112 ( V_217 ) ) ;
printf ( L_154 V_104 L_155 V_104 L_34 , V_211 , F_112 ( V_218 ) ) ;
F_134 () ;
F_136 () ;
return;
}
case 'w' : {
unsigned long V_155 ;
F_80 ( & V_210 ) ;
V_155 = 0 ;
F_130 ( V_210 , & V_155 ) ;
F_80 ( & V_155 ) ;
F_132 ( V_210 , V_155 ) ;
F_137 ( V_210 , true ) ;
break;
}
case 'r' :
F_80 ( & V_210 ) ;
F_137 ( V_210 , true ) ;
break;
case 'a' :
for ( V_208 = 1 ; V_208 < 1024 ; ++ V_208 )
F_137 ( V_208 , false ) ;
break;
}
F_121 () ;
}
static int
F_74 ( unsigned long V_102 , void * V_219 , int V_113 )
{
volatile int V_144 ;
char * V_2 , * V_220 ;
V_144 = 0 ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_2 = ( char * ) V_102 ;
V_220 = ( char * ) V_219 ;
switch ( V_113 ) {
case 2 :
* ( V_221 * ) V_220 = * ( V_221 * ) V_2 ;
break;
case 4 :
* ( V_222 * ) V_220 = * ( V_222 * ) V_2 ;
break;
case 8 :
* ( V_223 * ) V_220 = * ( V_223 * ) V_2 ;
break;
default:
for( ; V_144 < V_113 ; ++ V_144 ) {
* V_220 ++ = * V_2 ++ ;
F_3 () ;
}
}
F_3 () ;
F_128 ( 200 ) ;
V_144 = V_113 ;
}
V_65 = 0 ;
return V_144 ;
}
static int
F_138 ( unsigned long V_102 , void * V_219 , int V_113 )
{
volatile int V_144 ;
char * V_2 , * V_220 ;
V_144 = 0 ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_2 = ( char * ) V_102 ;
V_220 = ( char * ) V_219 ;
switch ( V_113 ) {
case 2 :
* ( V_221 * ) V_2 = * ( V_221 * ) V_220 ;
break;
case 4 :
* ( V_222 * ) V_2 = * ( V_222 * ) V_220 ;
break;
case 8 :
* ( V_223 * ) V_2 = * ( V_223 * ) V_220 ;
break;
default:
for ( ; V_144 < V_113 ; ++ V_144 ) {
* V_2 ++ = * V_220 ++ ;
F_3 () ;
}
}
F_3 () ;
F_128 ( 200 ) ;
V_144 = V_113 ;
} else {
printf ( L_156 V_104 L_34 , V_102 + V_144 ) ;
}
V_65 = 0 ;
return V_144 ;
}
static int F_70 ( struct V_21 * V_22 )
{
V_224 = F_37 ( V_22 ) ;
switch ( F_37 ( V_22 ) ) {
case 0x200 :
V_225 = 0 ;
break;
case 0x300 :
case 0x380 :
V_225 = 1 ;
break;
default:
V_225 = 2 ;
}
longjmp ( V_41 , 1 ) ;
return 0 ;
}
static void
F_139 ( unsigned char * V_155 , int V_113 )
{
int V_226 ;
switch ( V_113 ) {
case 2 :
F_140 ( V_155 [ 0 ] , V_155 [ 1 ] , V_226 ) ;
break;
case 4 :
F_140 ( V_155 [ 0 ] , V_155 [ 3 ] , V_226 ) ;
F_140 ( V_155 [ 1 ] , V_155 [ 2 ] , V_226 ) ;
break;
case 8 :
F_140 ( V_155 [ 0 ] , V_155 [ 7 ] , V_226 ) ;
F_140 ( V_155 [ 1 ] , V_155 [ 6 ] , V_226 ) ;
F_140 ( V_155 [ 2 ] , V_155 [ 5 ] , V_226 ) ;
F_140 ( V_155 [ 3 ] , V_155 [ 4 ] , V_226 ) ;
break;
}
}
static void
F_91 ( void )
{
int V_28 , V_227 , V_67 , V_228 ;
unsigned long V_144 ;
unsigned char V_155 [ 16 ] ;
F_80 ( ( void * ) & V_102 ) ;
V_28 = F_84 () ;
if ( V_28 == '?' ) {
printf ( V_229 ) ;
return;
} else {
V_86 = V_28 ;
}
V_82 = L_157 ;
while ( ( V_28 = F_84 () ) != '\n' ) {
switch( V_28 ) {
case 'b' : V_113 = 1 ; break;
case 'w' : V_113 = 2 ; break;
case 'l' : V_113 = 4 ; break;
case 'd' : V_113 = 8 ; break;
case 'r' : V_230 = ! V_230 ; break;
case 'n' : V_231 = 1 ; break;
case '.' : V_231 = 0 ; break;
}
}
if( V_113 <= 0 )
V_113 = 1 ;
else if( V_113 > 8 )
V_113 = 8 ;
for(; ; ) {
if ( ! V_231 )
V_144 = F_74 ( V_102 , V_155 , V_113 ) ;
printf ( V_104 L_158 , V_102 , V_230 ? 'r' : ' ' ) ;
if ( ! V_231 ) {
if ( V_230 )
F_139 ( V_155 , V_113 ) ;
putchar ( ' ' ) ;
for ( V_67 = 0 ; V_67 < V_144 ; ++ V_67 )
printf ( L_159 , V_155 [ V_67 ] ) ;
for (; V_67 < V_113 ; ++ V_67 )
printf ( L_160 , V_232 [ V_225 ] ) ;
}
putchar ( ' ' ) ;
V_227 = V_113 ;
V_228 = 0 ;
for(; ; ) {
if( F_80 ( & V_144 ) ) {
for ( V_67 = 0 ; V_67 < V_113 ; ++ V_67 )
V_155 [ V_67 ] = V_144 >> ( V_67 * 8 ) ;
if ( ! V_230 )
F_139 ( V_155 , V_113 ) ;
F_138 ( V_102 , V_155 , V_113 ) ;
V_227 = V_113 ;
}
V_28 = F_84 () ;
if ( V_28 == '\n' )
break;
V_227 = 0 ;
switch ( V_28 ) {
case '\'' :
for(; ; ) {
V_144 = F_86 () ;
if( V_144 == '\\' )
V_144 = F_141 () ;
else if( V_144 == '\'' )
break;
for ( V_67 = 0 ; V_67 < V_113 ; ++ V_67 )
V_155 [ V_67 ] = V_144 >> ( V_67 * 8 ) ;
if ( ! V_230 )
F_139 ( V_155 , V_113 ) ;
F_138 ( V_102 , V_155 , V_113 ) ;
V_102 += V_113 ;
}
V_102 -= V_113 ;
V_227 = V_113 ;
break;
case ',' :
V_102 += V_113 ;
break;
case '.' :
V_231 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_57 :
F_121 () ;
return;
case 'b' :
case 'v' :
V_113 = 1 ;
break;
case 'w' :
V_113 = 2 ;
break;
case 'l' :
V_113 = 4 ;
break;
case 'u' :
V_113 = 8 ;
break;
case '^' :
V_102 -= V_113 ;
break;
case '/' :
if ( V_228 > 0 )
V_102 -= 1 << V_228 ;
else
V_228 = 0 ;
V_228 += 4 ;
V_102 += 1 << V_228 ;
break;
case '\\' :
if ( V_228 < 0 )
V_102 += 1 << - V_228 ;
else
V_228 = 0 ;
V_228 -= 4 ;
V_102 -= 1 << - V_228 ;
break;
case 'm' :
F_80 ( ( void * ) & V_102 ) ;
break;
case 'n' :
V_231 = 1 ;
break;
case 'r' :
V_230 = ! V_230 ;
break;
case '<' :
V_144 = V_113 ;
F_80 ( & V_144 ) ;
V_102 -= V_144 ;
break;
case '>' :
V_144 = V_113 ;
F_80 ( & V_144 ) ;
V_102 += V_144 ;
break;
case '?' :
printf ( V_233 ) ;
break;
}
}
V_102 += V_227 ;
}
}
static int
F_141 ( void )
{
int V_234 ;
V_234 = F_86 () ;
switch( V_234 ) {
case 'n' : V_234 = '\n' ; break;
case 'r' : V_234 = '\r' ; break;
case 'b' : V_234 = '\b' ; break;
case 't' : V_234 = '\t' ; break;
}
return V_234 ;
}
static void F_142 ( unsigned long V_102 , long V_235 )
{
long V_144 , V_236 , V_237 , V_238 ;
unsigned char V_239 [ 16 ] ;
for ( V_144 = V_235 ; V_144 > 0 ; ) {
V_237 = V_144 < 16 ? V_144 : 16 ;
V_238 = F_74 ( V_102 , V_239 , V_237 ) ;
V_102 += V_238 ;
for ( V_236 = 0 ; V_236 < V_237 ; ++ V_236 ) {
if ( V_236 < V_238 )
printf ( L_159 , V_239 [ V_236 ] ) ;
else
printf ( L_160 , V_232 [ V_225 ] ) ;
}
V_144 -= V_237 ;
if ( V_238 < V_237 )
break;
}
printf ( L_34 ) ;
}
static void F_143 ( int V_35 )
{
struct V_240 * V_2 ;
#ifdef F_144
int V_67 = 0 ;
#endif
if ( setjmp ( V_41 ) != 0 ) {
printf ( L_161 , V_35 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
V_2 = & V_241 [ V_35 ] ;
printf ( L_162 , V_35 , V_2 ) ;
printf ( L_163 , 20 , L_164 , F_145 ( V_35 ) ? L_165 : L_166 ) ;
printf ( L_163 , 20 , L_167 , F_146 ( V_35 ) ? L_165 : L_166 ) ;
printf ( L_163 , 20 , L_168 , F_147 ( V_35 ) ? L_165 : L_166 ) ;
#define F_148 ( V_241 , V_114 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 20, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_148 ( V_2 , V_242 , L_169 ) ;
F_148 ( V_2 , V_243 , L_169 ) ;
F_148 ( V_2 , V_244 , L_170 ) ;
F_148 ( V_2 , V_245 , L_170 ) ;
F_148 ( V_2 , V_246 , L_170 ) ;
F_148 ( V_2 , V_247 , L_171 ) ;
#ifdef F_149
F_148 ( V_2 , V_248 , L_171 ) ;
F_148 ( V_2 , V_249 , L_171 ) ;
F_148 ( V_2 , V_250 , L_169 ) ;
F_148 ( V_2 , V_251 , L_169 ) ;
F_148 ( V_2 , V_252 , L_169 ) ;
#endif
F_148 ( V_2 , V_253 , L_170 ) ;
F_148 ( V_2 , V_254 , L_169 ) ;
F_148 ( V_2 , V_255 , L_169 ) ;
F_148 ( V_2 , V_256 , L_169 ) ;
#ifdef F_144
for ( V_67 = 0 ; V_67 < V_257 ; V_67 ++ ) {
V_223 V_258 , V_259 ;
if ( ! V_2 -> V_260 )
continue;
V_258 = F_150 ( V_2 -> V_260 -> V_261 [ V_67 ] . V_258 ) ;
V_259 = F_150 ( V_2 -> V_260 -> V_261 [ V_67 ] . V_259 ) ;
if ( V_258 || V_259 ) {
printf ( L_172 ,
V_67 , V_258 , V_259 ) ;
}
}
F_148 ( V_2 , V_262 , L_169 ) ;
F_148 ( V_2 , V_263 , L_169 ) ;
for ( V_67 = 0 ; V_67 < V_264 ; V_67 ++ )
printf ( L_173 , V_67 , V_2 -> V_265 [ V_67 ] ) ;
#endif
F_148 ( V_2 , V_266 , L_174 ) ;
#ifdef V_24
F_148 ( V_2 , V_267 , L_171 ) ;
F_148 ( V_2 , V_268 , L_171 ) ;
F_148 ( V_2 , V_269 , L_171 ) ;
F_148 ( V_2 , V_270 , L_171 ) ;
F_148 ( V_2 , V_271 , L_171 ) ;
F_148 ( V_2 , V_272 , L_171 ) ;
#endif
F_148 ( V_2 , V_273 , L_171 ) ;
F_148 ( V_2 , V_274 , L_170 ) ;
F_148 ( V_2 , V_275 , L_170 ) ;
F_148 ( V_2 , V_276 , L_170 ) ;
F_148 ( V_2 , V_277 , L_169 ) ;
F_148 ( V_2 , V_139 , L_169 ) ;
F_148 ( V_2 , V_140 , L_169 ) ;
F_148 ( V_2 , V_278 , L_169 ) ;
F_148 ( V_2 , V_279 , L_169 ) ;
F_148 ( V_2 , V_280 , L_169 ) ;
F_148 ( V_2 , V_281 , L_174 ) ;
#ifdef F_151
F_148 ( V_2 , V_282 , L_174 ) ;
#endif
#ifdef F_152
F_148 ( V_2 , V_283 , L_171 ) ;
F_148 ( V_2 , V_284 , L_169 ) ;
F_148 ( V_2 , V_285 , L_169 ) ;
F_148 ( V_2 , V_286 , L_169 ) ;
#endif
F_148 ( V_2 , V_287 . V_288 , L_174 ) ;
F_148 ( V_2 , V_287 . V_289 , L_174 ) ;
F_148 ( V_2 , V_287 . V_290 , L_174 ) ;
F_148 ( V_2 , V_287 . V_291 , L_174 ) ;
F_148 ( V_2 , V_287 . V_292 , L_174 ) ;
F_148 ( V_2 , V_287 . V_293 , L_174 ) ;
F_148 ( V_2 , V_287 . V_294 , L_174 ) ;
F_148 ( V_2 , V_287 . V_295 , L_174 ) ;
#undef F_148
V_65 = 0 ;
F_3 () ;
}
static void F_153 ( void )
{
int V_35 ;
if ( F_154 () == 0 ) {
printf ( L_175 ) ;
return;
}
F_113 (cpu)
F_143 ( V_35 ) ;
}
static void F_155 ( void )
{
unsigned long V_296 ;
int V_234 ;
V_234 = F_86 () ;
if ( V_234 == 'a' ) {
F_153 () ;
return;
}
V_86 = V_234 ;
if ( F_80 ( & V_296 ) )
F_143 ( V_296 ) ;
else
F_143 ( V_48 ) ;
}
static void F_156 ( int V_35 )
{
unsigned int V_297 = F_157 ( V_35 ) ;
F_158 ( V_298 , V_297 ) ;
F_158 ( V_299 , V_297 ) ;
F_158 ( V_300 , V_297 ) ;
F_158 ( V_301 , V_297 ) ;
F_158 ( V_302 , V_297 ) ;
F_158 ( V_303 , V_297 ) ;
if ( setjmp ( V_41 ) != 0 ) {
V_65 = 0 ;
printf ( L_176 , V_35 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
F_159 ( V_35 ) ;
F_3 () ;
F_128 ( 200 ) ;
V_65 = 0 ;
}
static void F_160 ( void )
{
int V_35 ;
if ( F_154 () == 0 ) {
printf ( L_177 ) ;
return;
}
F_113 (cpu)
F_156 ( V_35 ) ;
}
static void F_161 ( V_222 V_296 )
{
T_3 V_304 ;
T_4 V_153 ;
T_5 V_305 ;
T_6 V_306 ;
V_304 = F_162 ( V_296 , & V_153 , & V_305 , & V_306 ) ;
F_163 ( L_178 ,
V_296 , F_150 ( V_153 ) , V_305 , F_164 ( V_306 ) , V_304 ) ;
}
static void F_165 ( void )
{
unsigned long V_296 ;
int V_234 ;
V_234 = F_86 () ;
if ( V_234 == 'a' ) {
F_160 () ;
return;
} else if ( V_234 == 'i' ) {
if ( F_80 ( & V_296 ) )
F_161 ( V_296 ) ;
return;
}
V_86 = V_234 ;
if ( F_80 ( & V_296 ) )
F_156 ( V_296 ) ;
else
F_156 ( V_48 ) ;
}
static void F_166 ( unsigned long V_6 , long V_307 , int V_113 )
{
unsigned char V_239 [ 16 ] ;
int V_67 , V_308 ;
V_223 V_155 ;
V_307 = F_167 ( V_307 , 16 ) ;
for ( V_67 = 0 ; V_67 < V_307 ; V_67 += 16 , V_6 += 16 ) {
printf ( V_104 , V_6 ) ;
if ( F_74 ( V_6 , V_239 , 16 ) != 16 ) {
printf ( L_179 V_104 L_34 , 16 , V_6 ) ;
return;
}
for ( V_308 = 0 ; V_308 < 16 ; V_308 += V_113 ) {
putchar ( ' ' ) ;
switch ( V_113 ) {
case 1 : V_155 = V_239 [ V_308 ] ; break;
case 2 : V_155 = * ( V_221 * ) & V_239 [ V_308 ] ; break;
case 4 : V_155 = * ( V_222 * ) & V_239 [ V_308 ] ; break;
case 8 : V_155 = * ( V_223 * ) & V_239 [ V_308 ] ; break;
default: V_155 = 0 ;
}
printf ( L_180 , V_113 * 2 , V_155 ) ;
}
printf ( L_34 ) ;
}
}
static void
F_92 ( void )
{
static char V_309 [] = { L_181 } ;
int V_234 ;
V_234 = F_86 () ;
#ifdef F_127
if ( V_234 == 'p' ) {
F_168 () ;
F_155 () ;
F_169 () ;
return;
}
#endif
#ifdef F_152
if ( V_234 == 'x' ) {
F_168 () ;
F_165 () ;
F_169 () ;
return;
}
#endif
if ( V_234 == '\n' )
V_86 = V_234 ;
F_80 ( ( void * ) & V_102 ) ;
if ( V_86 != '\n' )
V_86 = 0 ;
if ( V_234 == 'i' ) {
F_80 ( & V_310 ) ;
if ( V_310 == 0 )
V_310 = 16 ;
else if ( V_310 > V_311 )
V_310 = V_311 ;
V_102 += F_47 ( V_102 , V_310 , 1 ) ;
V_82 = L_182 ;
} else if ( V_234 == 'l' ) {
F_170 () ;
} else if ( V_234 == 'o' ) {
F_2 () ;
} else if ( V_234 == 't' ) {
F_171 ( V_312 ) ;
F_172 () ;
} else if ( V_234 == 'r' ) {
F_80 ( & V_235 ) ;
if ( V_235 == 0 )
V_235 = 64 ;
F_142 ( V_102 , V_235 ) ;
V_102 += V_235 ;
V_82 = L_183 ;
} else {
F_80 ( & V_235 ) ;
if ( V_235 == 0 )
V_235 = 64 ;
else if ( V_235 > V_311 )
V_235 = V_311 ;
switch ( V_234 ) {
case '8' :
case '4' :
case '2' :
case '1' :
V_235 = F_167 ( V_235 , 16 ) ;
F_166 ( V_102 , V_235 , V_234 - '0' ) ;
V_309 [ 1 ] = V_234 ;
V_82 = V_309 ;
break;
default:
F_173 ( V_102 , V_235 ) ;
V_82 = L_184 ;
}
V_102 += V_235 ;
}
}
static void
F_173 ( unsigned long V_102 , long V_235 )
{
long V_144 , V_236 , V_234 , V_237 , V_238 ;
unsigned char V_239 [ 16 ] ;
for ( V_144 = V_235 ; V_144 > 0 ; ) {
printf ( V_104 , V_102 ) ;
putchar ( ' ' ) ;
V_237 = V_144 < 16 ? V_144 : 16 ;
V_238 = F_74 ( V_102 , V_239 , V_237 ) ;
V_102 += V_238 ;
for ( V_236 = 0 ; V_236 < V_237 ; ++ V_236 ) {
if ( ( V_236 & ( sizeof( long ) - 1 ) ) == 0 && V_236 > 0 )
putchar ( ' ' ) ;
if ( V_236 < V_238 )
printf ( L_159 , V_239 [ V_236 ] ) ;
else
printf ( L_160 , V_232 [ V_225 ] ) ;
}
for (; V_236 < 16 ; ++ V_236 ) {
if ( ( V_236 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_61 ) ;
}
printf ( L_185 ) ;
for ( V_236 = 0 ; V_236 < V_237 ; ++ V_236 ) {
if ( V_236 < V_238 ) {
V_234 = V_239 [ V_236 ] ;
putchar ( ' ' <= V_234 && V_234 <= '~' ? V_234 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_144 -= V_237 ;
for (; V_236 < 16 ; ++ V_236 )
putchar ( ' ' ) ;
printf ( L_186 ) ;
if ( V_238 < V_237 )
break;
}
}
static int
F_174 ( unsigned long V_313 , long V_307 , int V_314 ,
T_7 V_315 )
{
int V_238 , V_316 ;
unsigned long V_317 ;
unsigned long V_318 , V_319 = 0 ;
unsigned char V_155 [ 4 ] ;
V_316 = 0 ;
for ( V_317 = V_313 ; V_307 > 0 ; -- V_307 , V_313 += 4 ) {
V_238 = F_74 ( V_313 , V_155 , 4 ) ;
if ( V_238 == 0 ) {
if ( V_314 ) {
const char * V_320 = V_232 [ V_225 ] ;
printf ( V_104 L_187 , V_313 , V_320 , V_320 , V_320 , V_320 ) ;
}
break;
}
V_318 = F_175 ( V_155 ) ;
if ( V_313 > V_317 && V_318 == V_319 ) {
if ( ! V_316 ) {
printf ( L_188 ) ;
V_316 = 1 ;
}
continue;
}
V_316 = 0 ;
V_319 = V_318 ;
if ( V_314 )
printf ( V_104 L_189 , V_313 , V_318 ) ;
printf ( L_190 ) ;
V_315 ( V_318 , V_313 ) ;
printf ( L_34 ) ;
}
return V_313 - V_317 ;
}
static int
F_47 ( unsigned long V_313 , long V_307 , int V_314 )
{
return F_174 ( V_313 , V_307 , V_314 , V_321 ) ;
}
void
F_176 ( unsigned long V_6 )
{
F_40 ( V_6 , L_191 , L_87 ) ;
}
void
F_170 ( void )
{
struct V_322 V_323 = { . V_324 = 1 } ;
unsigned char V_219 [ 128 ] ;
T_8 V_80 ;
if ( setjmp ( V_41 ) != 0 ) {
printf ( L_192 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
F_177 ( & V_323 ) ;
F_168 () ;
while ( F_178 ( & V_323 , false , V_219 , sizeof( V_219 ) , & V_80 ) ) {
V_219 [ V_80 ] = '\0' ;
printf ( L_160 , V_219 ) ;
}
F_169 () ;
F_3 () ;
F_128 ( 200 ) ;
V_65 = 0 ;
}
static void F_2 ( void )
{
unsigned char V_219 [ 128 ] ;
T_9 V_325 ;
T_10 V_326 = 0 ;
if ( ! F_179 ( V_327 ) ) {
printf ( L_1 ) ;
return;
}
if ( setjmp ( V_41 ) != 0 ) {
printf ( L_193 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
F_168 () ;
while ( ( V_325 = F_180 ( V_219 , V_326 , sizeof( V_219 ) - 1 ) ) ) {
if ( V_325 < 0 ) {
printf ( L_194 , V_325 ) ;
break;
}
V_219 [ V_325 ] = '\0' ;
printf ( L_160 , V_219 ) ;
V_326 += V_325 ;
}
F_169 () ;
F_3 () ;
F_128 ( 200 ) ;
V_65 = 0 ;
}
static void
F_87 ( int V_28 )
{
F_80 ( ( void * ) & V_328 ) ;
if( V_86 != '\n' )
V_86 = 0 ;
F_80 ( ( void * ) ( V_28 == 's' ? & V_329 : & V_330 ) ) ;
if( V_86 != '\n' )
V_86 = 0 ;
F_80 ( ( void * ) & V_331 ) ;
switch( V_28 ) {
case 'm' :
memmove ( ( void * ) V_328 , ( void * ) V_330 , V_331 ) ;
break;
case 's' :
memset ( ( void * ) V_328 , V_329 , V_331 ) ;
break;
case 'd' :
if( V_86 != '\n' )
V_86 = 0 ;
F_80 ( ( void * ) & V_332 ) ;
F_181 ( ( unsigned char * ) V_328 , ( unsigned char * ) V_330 , V_331 , V_332 ) ;
break;
}
}
static void
F_181 ( unsigned char * V_333 , unsigned char * V_334 , unsigned V_335 , unsigned V_336 )
{
unsigned V_144 , V_337 ;
V_337 = 0 ;
for( V_144 = V_335 ; V_144 > 0 ; -- V_144 )
if( * V_333 ++ != * V_334 ++ )
if( ++ V_337 <= V_336 )
printf ( L_195 , V_333 - 1 ,
V_333 [ - 1 ] , V_334 - 1 , V_334 [ - 1 ] ) ;
if( V_337 > V_336 )
printf ( L_196 , V_337 ) ;
}
static void
F_88 ( void )
{
unsigned V_72 , V_144 ;
unsigned char V_155 [ 4 ] ;
V_82 = L_197 ;
F_80 ( ( void * ) & V_328 ) ;
if ( V_86 != '\n' ) {
V_86 = 0 ;
F_80 ( ( void * ) & V_338 ) ;
if ( V_86 != '\n' ) {
V_86 = 0 ;
F_80 ( ( void * ) & V_329 ) ;
V_339 = ~ 0 ;
if ( V_86 != '\n' ) V_86 = 0 ;
F_80 ( ( void * ) & V_339 ) ;
}
}
V_144 = 0 ;
for ( V_72 = V_328 ; V_72 < V_338 ; V_72 += 4 ) {
if ( F_74 ( V_72 , V_155 , 4 ) == 4
&& ( ( F_175 ( V_155 ) ^ V_329 ) & V_339 ) == 0 ) {
printf ( L_198 , V_72 , F_175 ( V_155 ) ) ;
if ( ++ V_144 >= 10 )
break;
}
}
}
static void
F_89 ( void )
{
unsigned char V_101 ;
unsigned V_72 ;
int V_154 , V_340 ;
F_80 ( & V_328 ) ;
if ( V_86 != '\n' ) V_86 = 0 ;
F_80 ( & V_341 ) ;
if ( V_86 != '\n' ) V_86 = 0 ;
F_80 ( & V_342 ) ;
V_340 = 0 ;
for ( V_72 = V_328 ; V_72 < V_342 ; V_72 += V_341 ) {
V_154 = F_74 ( V_72 , & V_101 , 1 ) ;
if ( V_154 && ! V_340 ) {
printf ( L_199 , V_72 ) ;
} else if ( ! V_154 && V_340 )
printf ( L_200 , V_72 - V_341 ) ;
V_340 = V_154 ;
if ( V_72 + V_341 < V_72 )
break;
}
if ( V_340 )
printf ( L_200 , V_72 - V_341 ) ;
}
static void F_182 ( struct V_343 * V_344 )
{
char V_345 ;
V_345 = ( V_344 -> V_345 == 0 ) ? 'R' :
( V_344 -> V_345 < 0 ) ? 'U' :
( V_344 -> V_345 & V_346 ) ? 'D' :
( V_344 -> V_345 & V_347 ) ? 'T' :
( V_344 -> V_345 & V_348 ) ? 'C' :
( V_344 -> V_349 & V_350 ) ? 'Z' :
( V_344 -> V_349 & V_351 ) ? 'E' :
( V_344 -> V_345 & V_352 ) ? 'S' : '?' ;
printf ( L_201 , V_344 ,
V_344 -> V_353 . V_354 ,
V_344 -> V_141 , V_344 -> V_355 -> V_141 ,
V_345 , F_183 ( V_344 ) -> V_35 ,
V_344 -> V_142 ) ;
}
static void F_107 ( void )
{
unsigned long V_356 ;
struct V_343 * V_344 = NULL ;
printf ( L_202 ) ;
if ( F_80 ( & V_356 ) )
V_344 = (struct V_343 * ) V_356 ;
if ( setjmp ( V_41 ) != 0 ) {
V_65 = 0 ;
printf ( L_203 , V_344 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
if ( V_344 )
F_182 ( V_344 ) ;
else
F_184 (tsk)
F_182 ( V_344 ) ;
F_3 () ;
F_128 ( 200 ) ;
V_65 = 0 ;
}
static void F_106 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_110 ;
int V_67 ;
typedef unsigned long (* T_11)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_11 V_357 ;
if ( ! F_80 ( & V_102 ) )
return;
if ( V_86 != '\n' )
V_86 = 0 ;
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 )
args [ V_67 ] = 0 ;
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 ) {
if ( ! F_80 ( & args [ V_67 ] ) || V_86 == '\n' )
break;
V_86 = 0 ;
}
V_357 = ( T_11 ) V_102 ;
V_110 = 0 ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_110 = V_357 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_3 () ;
printf ( L_204 , V_110 ) ;
} else {
printf ( L_205 , V_224 ) ;
}
V_65 = 0 ;
}
int
F_84 ( void )
{
int V_234 ;
if( V_86 != 0 ) {
V_234 = V_86 ;
V_86 = 0 ;
} else
V_234 = F_86 () ;
while( V_234 == ' ' || V_234 == '\t' )
V_234 = F_86 () ;
return V_234 ;
}
int
F_80 ( unsigned long * V_153 )
{
int V_234 , V_60 ;
unsigned long V_101 ;
V_234 = F_84 () ;
if ( V_234 == '%' ) {
char V_358 [ 8 ] ;
int V_67 ;
for ( V_67 = 0 ; V_67 < sizeof( V_358 ) - 1 ; ++ V_67 ) {
V_234 = F_86 () ;
if ( ! isalnum ( V_234 ) ) {
V_86 = V_234 ;
break;
}
V_358 [ V_67 ] = V_234 ;
}
V_358 [ V_67 ] = 0 ;
for ( V_67 = 0 ; V_67 < V_359 ; ++ V_67 ) {
if ( strcmp ( V_360 [ V_67 ] , V_358 ) == 0 ) {
if ( V_83 == NULL ) {
printf ( L_206 ) ;
return 0 ;
}
* V_153 = ( ( unsigned long * ) V_83 ) [ V_67 ] ;
return 1 ;
}
}
printf ( L_207 , V_358 ) ;
return 0 ;
}
if ( V_234 == '0' ) {
V_234 = F_86 () ;
if ( V_234 == 'x' ) {
V_234 = F_86 () ;
} else {
V_60 = F_185 ( V_234 ) ;
if ( V_60 == V_57 ) {
V_86 = V_234 ;
* V_153 = 0 ;
return 1 ;
}
}
} else if ( V_234 == '$' ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < 63 ; V_67 ++ ) {
V_234 = F_86 () ;
if ( isspace ( V_234 ) || V_234 == '\0' ) {
V_86 = V_234 ;
break;
}
V_115 [ V_67 ] = V_234 ;
}
V_115 [ V_67 ++ ] = 0 ;
* V_153 = 0 ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
* V_153 = F_186 ( V_115 ) ;
F_3 () ;
}
V_65 = 0 ;
if ( ! ( * V_153 ) ) {
printf ( L_208 , V_115 ) ;
return 0 ;
}
return 1 ;
}
V_60 = F_185 ( V_234 ) ;
if ( V_60 == V_57 ) {
V_86 = V_234 ;
return 0 ;
}
V_101 = 0 ;
do {
V_101 = ( V_101 << 4 ) + V_60 ;
V_234 = F_86 () ;
V_60 = F_185 ( V_234 ) ;
} while ( V_60 != V_57 );
V_86 = V_234 ;
* V_153 = V_101 ;
return 1 ;
}
static void
F_121 ( void )
{
int V_234 ;
V_234 = V_86 ;
V_86 = 0 ;
while( V_234 != '\n' )
V_234 = F_86 () ;
}
static int F_185 ( int V_234 )
{
if( '0' <= V_234 && V_234 <= '9' )
return V_234 - '0' ;
if( 'A' <= V_234 && V_234 <= 'F' )
return V_234 - ( 'A' - 10 ) ;
if( 'a' <= V_234 && V_234 <= 'f' )
return V_234 - ( 'a' - 10 ) ;
return V_57 ;
}
void
F_187 ( char * V_361 , int V_113 )
{
int V_234 ;
V_234 = F_84 () ;
do {
if( V_113 > 1 ) {
* V_361 ++ = V_234 ;
-- V_113 ;
}
V_234 = F_86 () ;
} while( V_234 != ' ' && V_234 != '\t' && V_234 != '\n' );
V_86 = V_234 ;
* V_361 = 0 ;
}
static void
F_83 ( void )
{
V_362 = NULL ;
}
static int
F_86 ( void )
{
if ( V_362 == NULL || * V_362 == 0 ) {
if ( F_188 ( line , sizeof( line ) ) == NULL ) {
V_362 = NULL ;
return V_57 ;
}
V_362 = line ;
}
return * V_362 ++ ;
}
static void
F_85 ( char * V_363 )
{
V_362 = V_363 ;
}
static void
F_93 ( void )
{
int type = F_86 () ;
unsigned long V_6 ;
static char V_364 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_80 ( & V_6 ) )
F_40 ( V_6 , L_101 , L_34 ) ;
V_86 = 0 ;
break;
case 's' :
F_187 ( V_364 , 64 ) ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_6 = F_186 ( V_364 ) ;
if ( V_6 )
printf ( L_209 , V_364 , V_6 ) ;
else
printf ( L_210 , V_364 ) ;
F_3 () ;
}
V_65 = 0 ;
V_86 = 0 ;
break;
}
}
static void F_40 ( unsigned long V_38 , const char * V_365 ,
const char * V_366 )
{
char * V_367 ;
const char * V_114 = NULL ;
unsigned long V_33 , V_113 ;
printf ( V_104 , V_38 ) ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_114 = F_120 ( V_38 , & V_113 , & V_33 , & V_367 ,
V_115 ) ;
F_3 () ;
F_128 ( 200 ) ;
}
V_65 = 0 ;
if ( V_114 ) {
printf ( L_211 , V_365 , V_114 , V_33 , V_113 ) ;
if ( V_367 )
printf ( L_212 , V_367 ) ;
}
printf ( L_160 , V_366 ) ;
}
void F_109 ( void )
{
int V_67 ;
unsigned long V_258 , V_259 ;
unsigned long V_368 ;
printf ( L_213 , F_16 () ) ;
for ( V_67 = 0 ; V_67 < V_369 ; V_67 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( ! V_258 && ! V_259 )
continue;
printf ( L_214 , V_67 , V_258 , V_259 ) ;
if ( ! ( V_258 & V_370 ) ) {
printf ( L_34 ) ;
continue;
}
V_368 = V_259 & V_371 ;
if ( V_259 & V_372 ) {
printf ( L_215 ,
F_189 ( V_258 ) ,
( V_259 & ~ V_373 ) >> V_374 ,
V_368 ) ;
} else {
printf ( L_216 ,
F_190 ( V_258 ) ,
( V_259 & ~ V_373 ) >> V_375 ,
V_368 ) ;
}
}
}
void F_109 ( void )
{
int V_67 ;
printf ( L_217 ) ;
for ( V_67 = 0 ; V_67 < 16 ; ++ V_67 )
printf ( L_218 , F_191 ( V_67 ) ) ;
printf ( L_34 ) ;
}
static void F_110 ( void )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_376 ; V_67 ++ ) {
unsigned long V_377 , V_378 , V_379 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_219 , V_67 , V_377 , V_378 , V_379 ) ;
if ( V_377 & V_380 ) {
printf ( L_220 ,
V_377 & V_381 ,
V_378 & V_382 ,
V_378 & V_383 ,
( V_379 & V_384 ) ? 'W' : 'w' ,
( V_379 & V_385 ) ? 'I' : 'i' ,
( V_379 & V_386 ) ? 'M' : 'm' ,
( V_379 & V_387 ) ? 'G' : 'g' ,
( V_379 & V_388 ) ? 'E' : 'e' ) ;
}
printf ( L_34 ) ;
}
}
static void F_111 ( void )
{
V_222 V_389 , V_390 , V_391 ;
V_223 V_392 ;
int V_67 , V_393 , V_394 , V_395 , V_396 , V_397 , V_398 = 0 ;
int V_399 ;
static const char * V_400 [] = {
L_221 ,
L_222 ,
L_223 ,
L_224 ,
L_225 ,
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
} ;
V_389 = F_112 ( V_401 ) ;
V_399 = ( V_389 & 3 ) + 1 ;
V_394 = ( ( V_389 >> 2 ) & 3 ) + 1 ;
V_395 = ( ( V_389 >> 6 ) & 0x1f ) + 1 ;
V_396 = ( V_389 >> 24 ) & 0xf ;
V_397 = ( V_389 >> 16 ) & 0x7f ;
if ( ( V_399 > 1 ) && ( V_389 & 0x10000 ) )
V_398 = 1 ;
printf ( L_253 ,
V_399 , V_394 , V_395 , V_396 , V_397 ) ;
V_390 = ( 1ul << V_395 ) - 1 ;
V_391 = ( 1ul << V_396 ) - 1 ;
V_392 = ( 1ull << V_397 ) - 1 ;
for ( V_393 = 0 ; V_393 < V_394 ; V_393 ++ ) {
V_222 V_402 ;
int V_403 , V_404 , V_405 = 1 ;
printf ( L_254 , V_393 ) ;
switch( V_393 ) {
case 0 :
V_402 = F_112 ( V_406 ) ;
break;
case 1 :
V_402 = F_112 ( V_407 ) ;
break;
case 2 :
V_402 = F_112 ( V_408 ) ;
break;
case 3 :
V_402 = F_112 ( V_409 ) ;
break;
default:
printf ( L_255 ) ;
continue;
}
V_403 = V_402 & 0xfff ;
V_404 = ( V_402 >> 24 ) & 0xff ;
for ( V_67 = 0 ; V_67 < V_403 ; V_67 ++ ) {
V_222 V_410 = F_192 ( V_393 ) ;
V_222 V_411 = F_193 ( V_412 ) ;
V_223 V_413 = 0 ;
V_223 V_414 ;
int V_415 = V_67 , V_416 = V_67 ;
if ( V_404 != 0 ) {
V_416 = V_67 / V_404 ;
V_415 = V_67 % V_404 ;
V_413 = V_416 * 0x1000 ;
}
V_410 |= F_194 ( V_415 ) ;
F_9 ( V_417 , V_410 ) ;
F_9 ( V_418 , V_411 ) ;
F_9 ( V_419 , V_413 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_411 = F_112 ( V_418 ) ;
V_413 = F_112 ( V_419 ) ;
V_414 = F_112 ( V_420 ) ;
if ( V_404 && ( V_67 % V_404 ) == 0 )
V_405 = 1 ;
if ( ! ( V_411 & V_421 ) )
continue;
if ( V_404 == 0 )
printf ( L_256 , V_67 ) ;
else if ( V_405 )
printf ( L_257 , V_416 , 'A' + V_415 ) ;
else
printf ( L_258 , 'A' + V_415 ) ;
V_405 = 0 ;
printf ( L_259 ,
V_413 & ~ 0x3ffull ,
( V_411 >> 16 ) & 0x3fff ,
V_400 [ ( V_411 >> 7 ) & 0x1f ] ,
V_411 & V_422 ? 'I' : ' ' ,
V_411 & V_423 ? 'P' : ' ' ,
V_411 & V_424 ? '1' : '0' ) ;
printf ( L_260 ,
V_413 & V_425 ? 'a' : ' ' ,
V_413 & V_426 ? 'v' : ' ' ,
V_413 & V_427 ? 'w' : ' ' ,
V_413 & V_428 ? 'i' : ' ' ,
V_413 & V_429 ? 'm' : ' ' ,
V_413 & V_430 ? 'g' : ' ' ,
V_413 & V_431 ? 'e' : ' ' ) ;
printf ( L_261 , V_414 & V_392 & ~ 0x7ffull ) ;
if ( V_411 & V_422 )
printf ( L_262 ,
V_400 [ ( V_414 >> 1 ) & 0x1f ] ) ;
else
printf ( L_263 ,
V_414 & V_432 ? 'x' : ' ' ,
V_414 & V_433 ? 'w' : ' ' ,
V_414 & V_434 ? 'r' : ' ' ,
V_414 & V_435 ? 'x' : ' ' ,
V_414 & V_436 ? 'w' : ' ' ,
V_414 & V_437 ? 'r' : ' ' ) ;
}
}
}
static void F_195 ( int V_438 )
{
if ( V_438 ) {
V_439 = F_59 ;
V_440 = F_68 ;
V_441 = F_63 ;
V_442 = F_64 ;
V_443 = F_67 ;
V_444 = F_66 ;
V_445 = F_69 ;
} else {
V_439 = NULL ;
V_440 = NULL ;
V_441 = NULL ;
V_442 = NULL ;
V_443 = NULL ;
V_444 = NULL ;
V_445 = NULL ;
}
}
static void F_196 ( int V_446 )
{
F_195 ( 1 ) ;
F_197 ( F_62 () ) ;
if ( ! V_447 )
F_195 ( 0 ) ;
}
static int T_12 F_198 ( void )
{
F_199 ( 'x' , & V_448 ) ;
return 0 ;
}
static int F_200 ( void * V_449 , V_223 V_155 )
{
V_447 = ! ! V_155 ;
F_195 ( V_447 ) ;
return 0 ;
}
static int F_201 ( void * V_449 , V_223 * V_155 )
{
* V_155 = V_447 ;
return 0 ;
}
static int T_12 F_202 ( void )
{
F_203 ( L_264 , 0600 , V_450 , NULL ,
& V_451 ) ;
return 0 ;
}
static int T_12 F_204 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_265 , 5 ) == 0 ) {
F_195 ( 1 ) ;
V_452 = 1 ;
V_447 = 1 ;
} else if ( strncmp ( V_2 , L_266 , 2 ) == 0 ) {
F_195 ( 1 ) ;
V_447 = 1 ;
} else if ( strncmp ( V_2 , L_267 , 3 ) == 0 )
V_447 = 0 ;
else
return 1 ;
return 0 ;
}
void T_12 F_205 ( void )
{
if ( V_447 )
F_195 ( 1 ) ;
if ( V_452 )
F_197 ( NULL ) ;
}
void F_206 ( struct V_453 * V_454 )
{
struct V_455 * V_455 ;
F_207 (spu, list, full_list) {
if ( V_455 -> V_456 >= V_457 ) {
F_208 ( 1 ) ;
continue;
}
V_458 [ V_455 -> V_456 ] . V_455 = V_455 ;
V_458 [ V_455 -> V_456 ] . V_459 = 0 ;
V_458 [ V_455 -> V_456 ] . V_460 = ( unsigned long )
V_458 [ V_455 -> V_456 ] . V_455 -> V_461 ;
}
}
static void F_209 ( void )
{
struct V_455 * V_455 ;
int V_67 ;
V_223 V_364 ;
for ( V_67 = 0 ; V_67 < V_457 ; V_67 ++ ) {
if ( ! V_458 [ V_67 ] . V_455 )
continue;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_455 = V_458 [ V_67 ] . V_455 ;
V_458 [ V_67 ] . V_462 =
F_210 ( & V_455 -> V_463 -> V_464 ) ;
V_364 = F_211 ( V_455 ) ;
V_458 [ V_67 ] . V_465 = V_364 ;
V_364 &= ~ V_466 ;
F_212 ( V_455 , V_364 ) ;
F_3 () ;
F_128 ( 200 ) ;
V_458 [ V_67 ] . V_459 = 1 ;
printf ( L_268 , V_67 ,
V_458 [ V_67 ] . V_462 ?
L_269 : L_270 ) ;
} else {
V_65 = 0 ;
printf ( L_271 , V_67 ) ;
}
V_65 = 0 ;
}
}
static void F_213 ( void )
{
struct V_455 * V_455 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_457 ; V_67 ++ ) {
if ( ! V_458 [ V_67 ] . V_455 )
continue;
if ( ! V_458 [ V_67 ] . V_459 ) {
printf ( L_272
L_273 , V_67 ) ;
continue;
}
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_455 = V_458 [ V_67 ] . V_455 ;
F_212 ( V_455 , V_458 [ V_67 ] . V_465 ) ;
F_214 ( & V_455 -> V_463 -> V_464 ,
V_458 [ V_67 ] . V_462 ) ;
F_3 () ;
F_128 ( 200 ) ;
printf ( L_274 , V_67 ) ;
} else {
V_65 = 0 ;
printf ( L_275 , V_67 ) ;
}
V_65 = 0 ;
}
}
static void F_215 ( struct V_455 * V_455 )
{
printf ( L_276 , V_455 ) ;
F_216 ( V_455 , L_277 , V_456 ) ;
F_216 ( V_455 , L_160 , V_114 ) ;
F_216 ( V_455 , L_278 , V_467 ) ;
F_216 ( V_455 , L_279 , V_461 ) ;
F_216 ( V_455 , L_278 , V_468 ) ;
F_216 ( V_455 , L_277 , V_469 ) ;
F_216 ( V_455 , L_278 , V_34 ) ;
F_216 ( V_455 , L_280 , V_470 ) ;
F_216 ( V_455 , L_278 , V_471 ) ;
F_216 ( V_455 , L_278 , V_472 ) ;
F_216 ( V_455 , L_278 , V_473 ) ;
F_216 ( V_455 , L_278 , V_474 [ 0 ] ) ;
F_216 ( V_455 , L_278 , V_474 [ 1 ] ) ;
F_216 ( V_455 , L_278 , V_474 [ 2 ] ) ;
F_216 ( V_455 , L_277 , V_475 ) ;
F_216 ( V_455 , L_280 , V_141 ) ;
F_216 ( V_455 , L_279 , V_476 ) ;
F_216 ( V_455 , L_279 , V_477 ) ;
F_216 ( V_455 , L_279 , V_478 ) ;
F_216 ( V_455 , L_279 , V_479 ) ;
F_216 ( V_455 , L_278 , V_480 ) ;
F_216 ( V_455 , L_279 , V_463 ) ;
F_217 ( L_277 , V_463 -> V_464 ,
F_210 ( & V_455 -> V_463 -> V_464 ) ) ;
F_217 ( L_277 , V_463 -> V_481 ,
F_210 ( & V_455 -> V_463 -> V_481 ) ) ;
F_217 ( L_277 , V_463 -> V_482 ,
F_210 ( & V_455 -> V_463 -> V_482 ) ) ;
F_216 ( V_455 , L_279 , V_483 ) ;
F_216 ( V_455 , L_279 , V_484 ) ;
}
int
F_218 ( unsigned long V_313 , long V_307 , int V_314 )
{
return F_174 ( V_313 , V_307 , V_314 , V_485 ) ;
}
static void F_219 ( unsigned long V_296 , int V_486 )
{
unsigned long V_33 , V_6 , V_487 ;
if ( setjmp ( V_41 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_487 = ( unsigned long ) V_458 [ V_296 ] . V_455 -> V_461 ;
F_3 () ;
F_128 ( 200 ) ;
} else {
V_65 = 0 ;
printf ( L_281 , V_296 ) ;
return;
}
V_65 = 0 ;
if ( F_80 ( & V_33 ) )
V_6 = V_487 + V_33 ;
else
V_6 = V_458 [ V_296 ] . V_460 ;
if ( V_6 >= V_487 + V_488 ) {
printf ( L_282 ) ;
return;
}
switch ( V_486 ) {
case 'i' :
V_6 += F_218 ( V_6 , 16 , 1 ) ;
V_82 = L_283 ;
break;
default:
F_173 ( V_6 , 64 ) ;
V_6 += 64 ;
V_82 = L_284 ;
break;
}
V_458 [ V_296 ] . V_460 = V_6 ;
}
static int F_98 ( void )
{
static unsigned long V_296 = 0 ;
int V_28 , V_486 = 0 ;
V_28 = F_86 () ;
switch ( V_28 ) {
case 's' :
F_209 () ;
break;
case 'r' :
F_213 () ;
break;
case 'd' :
V_486 = F_86 () ;
if ( isxdigit ( V_486 ) || V_486 == '\n' )
V_86 = V_486 ;
case 'f' :
F_80 ( & V_296 ) ;
if ( V_296 >= V_457 || ! V_458 [ V_296 ] . V_455 ) {
printf ( L_285 ) ;
return 0 ;
}
switch ( V_28 ) {
case 'f' :
F_215 ( V_458 [ V_296 ] . V_455 ) ;
break;
default:
F_219 ( V_296 , V_486 ) ;
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
