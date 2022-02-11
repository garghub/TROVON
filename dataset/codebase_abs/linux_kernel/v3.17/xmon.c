static inline void F_1 ( void )
{
asm volatile("sync; isync");
}
static inline void F_2 ( void * V_1 )
{
asm volatile ("dcbst 0,%0; sync; icbi 0,%0; isync" : : "r" (p));
}
static inline void F_3 ( void * V_1 )
{
asm volatile ("dcbf 0,%0; icbi 0,%0" : : "r" (p));
}
static inline void F_4 ( void * V_1 )
{
asm volatile ("dcbi 0,%0; icbi 0,%0" : : "r" (p));
}
static inline void F_5 ( void )
{
#ifdef F_6
static struct V_2 args ;
args . V_3 = F_7 ( L_1 ) ;
if ( args . V_3 == V_4 )
return;
args . V_5 = 3 ;
args . V_6 = 1 ;
args . V_7 = & args . args [ 3 ] ;
args . args [ 0 ] = V_8 ;
args . args [ 1 ] = 0 ;
args . args [ 2 ] = 0 ;
F_8 ( F_9 ( & args ) ) ;
#endif
}
static void F_10 ( void )
{
int V_9 = F_11 () + 0x100 ;
int V_10 = 0 , V_11 ;
long V_12 ;
if ( V_13 == V_9 )
return;
for (; ; ) {
V_10 = F_12 ( & V_13 , 0 , V_9 ) ;
if ( V_10 == 0 )
return;
V_12 = 10000 ;
while ( V_13 == V_10 ) {
if ( -- V_12 > 0 ) {
F_13 ( 100 ) ;
continue;
}
V_11 = F_12 ( & V_13 , V_10 , V_9 ) ;
if ( V_11 == V_10 )
return;
break;
}
}
}
static void F_14 ( void )
{
V_13 = 0 ;
}
int F_15 ( void )
{
return ! F_16 ( & V_14 ) ;
}
static inline int F_17 ( struct V_15 * V_16 )
{
#if F_18 ( V_17 ) || F_18 ( V_18 )
return 0 ;
#else
return ( ( V_16 -> V_19 & V_20 ) == 0 ) ;
#endif
}
static int F_19 ( struct V_15 * V_16 , int V_21 )
{
int V_22 = 0 ;
struct V_23 * V_24 ;
long V_25 [ V_26 ] ;
unsigned long V_27 ;
unsigned long V_28 ;
#ifdef F_20
int V_29 ;
int V_30 ;
unsigned long V_12 ;
#endif
F_21 ( V_28 ) ;
F_22 () ;
V_24 = F_23 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = V_24 -> V_32 + V_27 ;
F_24 ( & V_24 -> V_33 ) ;
}
F_25 () ;
#ifdef F_20
V_29 = F_11 () ;
if ( F_26 ( V_29 , & V_14 ) ) {
F_10 () ;
F_27 ( V_16 ) ;
printf ( L_2
L_3 ,
V_29 , V_16 -> V_34 , F_28 ( F_29 ( V_16 ) ) ) ;
F_14 () ;
longjmp ( V_35 [ V_29 ] , 1 ) ;
}
if ( setjmp ( V_25 ) != 0 ) {
if ( ! V_36 || ! V_37 ) {
F_10 () ;
printf ( L_4
L_5 , V_29 ) ;
F_14 () ;
goto V_38;
}
V_30 = ! ( V_39 && V_29 == V_40 ) ;
goto V_41;
}
V_35 [ V_29 ] = V_25 ;
V_24 = NULL ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) )
V_24 = F_30 ( V_16 -> V_31 ) ;
if ( V_24 || F_17 ( V_16 ) )
V_21 = 0 ;
if ( ! V_21 ) {
F_10 () ;
F_27 ( V_16 ) ;
if ( V_24 ) {
printf ( L_6 ,
V_29 , F_31 ( V_24 ) ) ;
F_32 ( V_16 -> V_31 , L_7 , L_8 ) ;
}
if ( F_17 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_14 () ;
}
F_33 ( V_29 , & V_14 ) ;
V_38:
V_30 = 1 ;
while ( V_30 && ! V_37 ) {
if ( V_36 == 0 ) {
if ( V_21 )
goto V_45;
V_30 = F_34 ( 0 , & V_36 ) ;
}
F_35 () ;
}
if ( ! V_30 && ! V_37 ) {
int V_46 = F_36 () ;
V_40 = V_29 ;
F_37 () ;
if ( V_46 > 1 ) {
F_38 () ;
for ( V_12 = 100000000 ; V_12 != 0 ; -- V_12 ) {
if ( F_39 ( & V_14 ) >= V_46 )
break;
F_35 () ;
}
}
F_40 () ;
F_5 () ;
if ( V_24 || F_29 ( V_16 ) == 0xd00 )
F_41 ( V_16 -> V_31 , 1 , 0 ) ;
printf ( L_11 ) ;
F_37 () ;
V_37 = 1 ;
F_35 () ;
}
V_41:
while ( V_36 ) {
if ( V_30 ) {
if ( V_29 == V_40 ) {
if ( ! F_34 ( 0 , & V_39 ) ) {
V_30 = 0 ;
continue;
}
while ( V_29 == V_40 )
F_35 () ;
}
F_35 () ;
} else {
V_22 = F_42 ( V_16 ) ;
if ( V_22 != 0 ) {
F_43 () ;
V_37 = 0 ;
F_44 () ;
V_36 = 0 ;
break;
}
V_30 = 1 ;
}
}
V_45:
F_45 ( V_29 , & V_14 ) ;
V_35 [ V_29 ] = NULL ;
#else
if ( V_36 ) {
printf ( L_12 ,
V_16 -> V_34 , F_28 ( F_29 ( V_16 ) ) ) ;
longjmp ( V_35 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_25 ) == 0 ) {
V_35 [ 0 ] = V_25 ;
V_36 = 1 ;
F_27 ( V_16 ) ;
V_24 = F_30 ( V_16 -> V_31 ) ;
if ( V_24 ) {
printf ( L_13 , F_31 ( V_24 ) ) ;
F_32 ( V_16 -> V_31 , L_7 , L_8 ) ;
}
if ( F_17 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_40 () ;
F_5 () ;
if ( V_24 || F_29 ( V_16 ) == 0xd00 )
F_41 ( V_16 -> V_31 , 1 , 0 ) ;
printf ( L_11 ) ;
}
V_22 = F_42 ( V_16 ) ;
F_43 () ;
V_36 = 0 ;
#endif
#ifdef F_46
if ( V_16 -> V_19 & V_47 ) {
V_24 = F_30 ( V_16 -> V_31 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = ( unsigned long ) & V_24 -> V_48 [ 0 ] ;
F_47 ( & V_24 -> V_33 ) ;
}
}
#else
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) ) {
V_24 = F_30 ( V_16 -> V_31 ) ;
if ( V_24 != NULL ) {
int V_49 = F_48 ( V_16 , V_24 -> V_48 [ 0 ] ) ;
if ( V_49 == 0 ) {
V_16 -> V_31 = ( unsigned long ) & V_24 -> V_48 [ 0 ] ;
F_47 ( & V_24 -> V_33 ) ;
} else if ( V_49 < 0 ) {
printf ( L_14 ,
( F_49 ( V_24 -> V_48 [ 0 ] ) ? L_15 : L_16 ) ) ;
}
}
}
#endif
F_50 () ;
F_51 () ;
F_52 ( V_28 ) ;
return V_22 != 'X' && V_22 != V_50 ;
}
int F_53 ( struct V_15 * V_51 )
{
struct V_15 V_16 ;
if ( V_51 == NULL ) {
F_54 ( & V_16 ) ;
V_51 = & V_16 ;
}
return F_19 ( V_51 , 0 ) ;
}
T_1 F_55 ( int V_52 , void * V_53 )
{
unsigned long V_28 ;
F_21 ( V_28 ) ;
printf ( L_17 ) ;
F_53 ( F_56 () ) ;
F_52 ( V_28 ) ;
return V_54 ;
}
static int F_57 ( struct V_15 * V_16 )
{
struct V_23 * V_24 ;
unsigned long V_27 ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
V_24 = F_23 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL && V_27 == 4 ) {
V_16 -> V_31 = V_24 -> V_32 + 4 ;
F_24 ( & V_24 -> V_33 ) ;
return 1 ;
}
V_24 = F_30 ( V_16 -> V_31 ) ;
if ( ! V_24 )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_58 ( struct V_15 * V_16 )
{
if ( F_59 ( V_16 ) )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_60 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
if ( V_55 . V_56 == 0 )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_61 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
if ( V_57 == NULL )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_62 ( struct V_15 * V_16 )
{
#ifdef F_20
if ( V_36 && ! F_26 ( F_11 () , & V_14 ) )
F_19 ( V_16 , 1 ) ;
#endif
return 0 ;
}
static int F_63 ( struct V_15 * V_16 )
{
struct V_23 * V_24 ;
unsigned long V_27 ;
if ( V_36 && V_58 )
F_64 ( V_16 ) ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) ) {
V_24 = F_23 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = V_24 -> V_32 + V_27 ;
F_24 ( & V_24 -> V_33 ) ;
}
}
return 0 ;
}
static struct V_23 * F_30 ( unsigned long V_59 )
{
int V_60 ;
struct V_23 * V_24 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 )
if ( V_24 -> V_56 && V_59 == V_24 -> V_32 )
return V_24 ;
return NULL ;
}
static struct V_23 * F_23 ( unsigned long V_31 , unsigned long * V_63 )
{
unsigned long V_64 ;
V_64 = V_31 - ( unsigned long ) V_61 ;
if ( V_64 >= sizeof( V_61 ) )
return NULL ;
V_64 %= sizeof( struct V_23 ) ;
if ( V_64 != F_65 ( struct V_23 , V_48 [ 0 ] )
&& V_64 != F_65 ( struct V_23 , V_48 [ 1 ] ) )
return NULL ;
* V_63 = V_64 - F_65 ( struct V_23 , V_48 [ 0 ] ) ;
return (struct V_23 * ) ( V_31 - V_64 ) ;
}
static struct V_23 * F_66 ( unsigned long V_65 )
{
struct V_23 * V_24 ;
V_65 &= ~ 3UL ;
V_24 = F_30 ( V_65 ) ;
if ( V_24 )
return V_24 ;
for ( V_24 = V_61 ; V_24 < & V_61 [ V_62 ] ; ++ V_24 ) {
if ( ! V_24 -> V_56 && F_67 ( & V_24 -> V_33 ) == 0 ) {
V_24 -> V_32 = V_65 ;
V_24 -> V_48 [ 1 ] = V_66 ;
F_2 ( & V_24 -> V_48 [ 1 ] ) ;
return V_24 ;
}
}
printf ( L_18 ) ;
return NULL ;
}
static void F_43 ( void )
{
int V_60 ;
struct V_23 * V_24 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 ) {
if ( ( V_24 -> V_56 & ( V_67 | V_68 ) ) == 0 )
continue;
if ( F_68 ( V_24 -> V_32 , & V_24 -> V_48 [ 0 ] , 4 ) != 4 ) {
printf ( L_19
L_20 , V_24 -> V_32 ) ;
V_24 -> V_56 = 0 ;
continue;
}
if ( F_69 ( V_24 -> V_48 [ 0 ] ) || F_49 ( V_24 -> V_48 [ 0 ] ) ) {
printf ( L_21
L_22 , V_24 -> V_32 ) ;
V_24 -> V_56 = 0 ;
continue;
}
F_2 ( & V_24 -> V_48 [ 0 ] ) ;
if ( V_24 -> V_56 & V_68 )
continue;
if ( F_70 ( V_24 -> V_32 , & V_66 , 4 ) != 4 ) {
printf ( L_23
L_20 , V_24 -> V_32 ) ;
V_24 -> V_56 &= ~ V_67 ;
continue;
}
F_2 ( ( void * ) V_24 -> V_32 ) ;
}
}
static void F_50 ( void )
{
struct V_69 V_70 ;
if ( V_55 . V_56 ) {
V_70 . V_32 = V_55 . V_32 ;
V_70 . type = ( V_55 . V_56 & V_71 ) | V_72 ;
V_70 . V_73 = 8 ;
F_71 ( & V_70 ) ;
}
if ( V_57 && F_72 ( V_74 ) )
F_73 ( V_75 , V_57 -> V_32
| ( V_57 -> V_56 & ( V_68 | V_76 ) ) ) ;
}
static void F_40 ( void )
{
int V_60 ;
struct V_23 * V_24 ;
unsigned V_48 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 ) {
if ( ( V_24 -> V_56 & ( V_67 | V_68 ) ) != V_67 )
continue;
if ( F_68 ( V_24 -> V_32 , & V_48 , 4 ) == 4
&& V_48 == V_66
&& F_70 ( V_24 -> V_32 , & V_24 -> V_48 , 4 ) != 4 )
printf ( L_24 ,
V_24 -> V_32 ) ;
else
F_2 ( ( void * ) V_24 -> V_32 ) ;
}
}
static void F_25 ( void )
{
F_74 () ;
if ( F_72 ( V_74 ) )
F_73 ( V_75 , 0 ) ;
}
static int
F_42 ( struct V_15 * V_51 )
{
int V_22 = 0 ;
V_77 = NULL ;
V_78 = V_51 ;
if ( ! V_79 ) {
V_79 = 1 ;
F_75 ( V_51 -> V_80 [ 1 ] , V_51 -> V_81 , V_51 -> V_31 ) ;
}
for(; ; ) {
#ifdef F_20
printf ( L_25 , F_11 () ) ;
#endif
printf ( L_26 ) ;
F_76 () ;
V_82 = 0 ;
V_22 = F_77 () ;
if( V_22 == '\n' ) {
if ( V_77 == NULL )
continue;
F_78 ( V_77 ) ;
V_77 = NULL ;
V_22 = F_79 () ;
}
switch ( V_22 ) {
case 'm' :
V_22 = F_79 () ;
switch ( V_22 ) {
case 'm' :
case 's' :
case 'd' :
F_80 ( V_22 ) ;
break;
case 'l' :
F_81 () ;
break;
case 'z' :
F_82 () ;
break;
case 'i' :
F_83 ( 0 ) ;
break;
default:
V_82 = V_22 ;
F_84 () ;
}
break;
case 'd' :
F_85 () ;
break;
case 'l' :
F_86 () ;
break;
case 'r' :
F_87 ( V_51 ) ;
break;
case 'e' :
F_27 ( V_51 ) ;
break;
case 'S' :
F_88 () ;
break;
case 't' :
F_89 ( V_51 ) ;
break;
case 'f' :
F_90 () ;
break;
case 's' :
if ( F_91 () == 0 )
break;
if ( F_92 ( V_51 ) )
return V_22 ;
break;
case 'x' :
case 'X' :
return V_22 ;
case V_50 :
printf ( L_27 ) ;
F_93 ( 2000 ) ;
return V_22 ;
case '?' :
F_94 ( V_83 ) ;
break;
case 'b' :
F_95 () ;
break;
case 'C' :
F_96 () ;
break;
case 'c' :
if ( F_97 () )
return 0 ;
break;
case 'z' :
F_98 () ;
break;
case 'p' :
F_99 () ;
break;
#ifdef F_100
case 'u' :
F_101 () ;
break;
#elif F_18 ( V_17 )
case 'u' :
F_102 () ;
break;
#elif F_18 ( V_18 )
case 'u' :
F_103 () ;
break;
#endif
default:
printf ( L_28 ) ;
do {
if ( ' ' < V_22 && V_22 <= '~' )
putchar ( V_22 ) ;
else
printf ( L_29 , V_22 ) ;
V_22 = F_79 () ;
} while ( V_22 != '\n' );
printf ( L_30 ) ;
break;
}
}
}
static int F_92 ( struct V_15 * V_16 )
{
V_16 -> V_19 |= V_47 ;
F_73 ( V_84 , F_104 ( V_84 ) | V_85 | V_86 ) ;
return 1 ;
}
static int F_92 ( struct V_15 * V_16 )
{
unsigned int V_48 ;
int V_49 ;
if ( ( V_16 -> V_19 & ( V_44 | V_43 | V_42 ) ) == ( V_44 | V_42 ) ) {
if ( F_68 ( V_16 -> V_31 , & V_48 , 4 ) == 4 ) {
V_49 = F_48 ( V_16 , V_48 ) ;
if ( V_49 < 0 ) {
printf ( L_14 ,
( F_49 ( V_48 ) ? L_15 : L_16 ) ) ;
return 0 ;
}
if ( V_49 > 0 ) {
V_16 -> V_34 = 0xd00 | ( V_16 -> V_34 & 1 ) ;
printf ( L_31 ) ;
F_32 ( V_16 -> V_31 , L_7 , L_32 ) ;
F_41 ( V_16 -> V_31 , 1 , 0 ) ;
return 0 ;
}
}
}
V_16 -> V_19 |= V_87 ;
return 1 ;
}
static void F_98 ( void )
{
int V_22 ;
V_22 = F_79 () ;
if ( V_22 == 'r' )
V_88 . V_89 ( NULL ) ;
else if ( V_22 == 'h' )
V_88 . V_90 () ;
else if ( V_22 == 'p' )
V_88 . V_91 () ;
}
static int F_97 ( void )
{
#ifdef F_20
unsigned long V_29 , V_92 , V_93 ;
int V_12 ;
if ( ! F_105 ( & V_29 ) ) {
printf ( L_33 ) ;
V_93 = V_92 = V_94 ;
F_106 (cpu) {
if ( F_26 ( V_29 , & V_14 ) ) {
if ( V_29 == V_93 + 1 ) {
V_93 = V_29 ;
} else {
if ( V_93 != V_92 )
printf ( L_34 , V_93 ) ;
V_93 = V_92 = V_29 ;
printf ( L_35 , V_29 ) ;
}
}
}
if ( V_93 != V_92 )
printf ( L_34 , V_93 ) ;
printf ( L_32 ) ;
return 0 ;
}
if ( ! F_26 ( V_29 , & V_14 ) ) {
printf ( L_36 , V_29 ) ;
return 0 ;
}
V_39 = 0 ;
F_37 () ;
V_40 = V_29 ;
V_12 = 10000000 ;
while ( ! V_39 ) {
if ( -- V_12 == 0 ) {
if ( F_34 ( 0 , & V_39 ) )
break;
F_37 () ;
V_40 = F_11 () ;
printf ( L_37 , V_29 ) ;
return 0 ;
}
F_35 () ;
}
return 1 ;
#else
return 0 ;
#endif
}
static void
F_96 ( void )
{
unsigned int V_60 ;
unsigned short V_95 ;
unsigned char V_96 ;
if ( ! F_105 ( & V_97 ) )
return;
if ( ! F_105 ( & V_98 ) )
return;
V_95 = 0xffff ;
for ( V_60 = 0 ; V_60 < V_98 ; ++ V_60 ) {
if ( F_68 ( V_97 + V_60 , & V_96 , 1 ) == 0 ) {
printf ( L_38 V_99 L_32 , V_97 + V_60 ) ;
break;
}
V_95 = F_107 ( V_95 , V_96 ) ;
}
printf ( L_39 , V_95 ) ;
}
static long F_108 ( unsigned long V_100 )
{
unsigned int V_48 ;
V_100 &= ~ 3 ;
if ( ! F_109 ( V_100 ) ) {
printf ( L_40 ) ;
return 0 ;
}
if ( ! F_68 ( V_100 , & V_48 , sizeof( V_48 ) ) ) {
printf ( L_41 , V_100 ) ;
return 0 ;
}
if ( F_69 ( V_48 ) || F_49 ( V_48 ) ) {
printf ( L_42
L_43 ) ;
return 0 ;
}
return 1 ;
}
static void
F_95 ( void )
{
int V_22 ;
unsigned long V_65 ;
int V_101 , V_60 ;
struct V_23 * V_24 ;
const char V_102 [] = L_44
L_45 ;
V_22 = F_79 () ;
switch ( V_22 ) {
#ifndef F_110
case 'd' :
V_101 = 7 ;
V_22 = F_79 () ;
if ( V_22 == 'r' )
V_101 = 5 ;
else if ( V_22 == 'w' )
V_101 = 6 ;
else
V_82 = V_22 ;
V_55 . V_32 = 0 ;
V_55 . V_56 = 0 ;
if ( F_105 ( & V_55 . V_32 ) ) {
if ( ! F_109 ( V_55 . V_32 ) ) {
printf ( V_102 ) ;
break;
}
V_55 . V_32 &= ~ V_71 ;
V_55 . V_56 = V_101 | V_103 ;
}
break;
case 'i' :
if ( ! F_72 ( V_74 ) ) {
printf ( L_46
L_47 ) ;
break;
}
if ( V_57 ) {
V_57 -> V_56 &= ~ ( V_68 | V_76 ) ;
V_57 = NULL ;
}
if ( ! F_105 ( & V_65 ) )
break;
if ( ! F_108 ( V_65 ) )
break;
V_24 = F_66 ( V_65 ) ;
if ( V_24 != NULL ) {
V_24 -> V_56 |= V_68 | V_76 ;
V_57 = V_24 ;
}
break;
#endif
case 'c' :
if ( ! F_105 ( & V_65 ) ) {
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 )
V_61 [ V_60 ] . V_56 = 0 ;
V_57 = NULL ;
V_55 . V_56 = 0 ;
printf ( L_48 ) ;
break;
}
if ( V_65 <= V_62 && V_65 >= 1 ) {
V_24 = & V_61 [ V_65 - 1 ] ;
} else {
V_24 = F_30 ( V_65 ) ;
if ( V_24 == NULL ) {
printf ( L_49 , V_65 ) ;
break;
}
}
printf ( L_50 , F_31 ( V_24 ) ) ;
F_32 ( V_24 -> V_32 , L_7 , L_8 ) ;
V_24 -> V_56 = 0 ;
break;
default:
V_82 = V_22 ;
V_22 = F_77 () ;
if ( V_22 == '?' ) {
printf ( V_104 ) ;
break;
}
V_82 = V_22 ;
if ( ! F_105 ( & V_65 ) ) {
printf ( L_51 ) ;
if ( V_55 . V_56 ) {
printf ( L_52 V_99 L_53 , V_55 . V_32 ) ;
if ( V_55 . V_56 & 1 )
printf ( L_54 ) ;
if ( V_55 . V_56 & 2 )
printf ( L_55 ) ;
printf ( L_56 ) ;
}
for ( V_24 = V_61 ; V_24 < & V_61 [ V_62 ] ; ++ V_24 ) {
if ( ! V_24 -> V_56 )
continue;
printf ( L_57 , F_31 ( V_24 ) ,
( V_24 -> V_56 & V_68 ) ? L_58 : L_59 ) ;
F_32 ( V_24 -> V_32 , L_60 , L_32 ) ;
}
break;
}
if ( ! F_108 ( V_65 ) )
break;
V_24 = F_66 ( V_65 ) ;
if ( V_24 != NULL )
V_24 -> V_56 |= V_67 ;
break;
}
}
static
const char * F_28 ( unsigned long V_105 )
{
char * V_106 ;
switch ( V_105 ) {
case 0x100 : V_106 = L_61 ; break;
case 0x200 : V_106 = L_62 ; break;
case 0x300 : V_106 = L_63 ; break;
case 0x380 : V_106 = L_64 ; break;
case 0x400 : V_106 = L_65 ; break;
case 0x480 : V_106 = L_66 ; break;
case 0x500 : V_106 = L_67 ; break;
case 0x600 : V_106 = L_68 ; break;
case 0x700 : V_106 = L_69 ; break;
case 0x800 : V_106 = L_70 ; break;
case 0x900 : V_106 = L_71 ; break;
case 0x980 : V_106 = L_72 ; break;
case 0xa00 : V_106 = L_73 ; break;
case 0xc00 : V_106 = L_74 ; break;
case 0xd00 : V_106 = L_75 ; break;
case 0xe40 : V_106 = L_76 ; break;
case 0xe60 : V_106 = L_77 ; break;
case 0xe80 : V_106 = L_78 ; break;
case 0xf00 : V_106 = L_79 ; break;
case 0xf20 : V_106 = L_80 ; break;
case 0x1300 : V_106 = L_81 ; break;
case 0x1500 : V_106 = L_82 ; break;
case 0x1700 : V_106 = L_83 ; break;
default: V_106 = L_84 ;
}
return V_106 ;
}
static void F_111 ( unsigned long V_59 , unsigned long * V_107 ,
unsigned long * V_108 )
{
unsigned long V_109 , V_27 ;
const char * V_110 ;
* V_107 = * V_108 = 0 ;
if ( V_59 == 0 )
return;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_110 = F_112 ( V_59 , & V_109 , & V_27 , NULL , V_112 ) ;
if ( V_110 != NULL ) {
* V_107 = V_59 - V_27 ;
* V_108 = V_59 - V_27 + V_109 ;
}
F_1 () ;
}
V_58 = 0 ;
}
static void F_75 ( unsigned long V_113 , unsigned long V_114 ,
unsigned long V_59 )
{
int V_115 = 64 ;
unsigned long V_116 ;
unsigned long V_117 ;
unsigned long V_118 ;
struct V_15 V_16 ;
while ( V_115 -- ) {
if ( V_113 < V_119 ) {
if ( V_113 != 0 )
printf ( L_85 , V_113 ) ;
break;
}
if ( ! F_68 ( V_113 + V_120 , & V_116 , sizeof( unsigned long ) )
|| ! F_68 ( V_113 , & V_117 , sizeof( unsigned long ) ) ) {
printf ( L_86 , V_113 ) ;
break;
}
if ( ( V_59 | V_114 ) != 0 ) {
unsigned long V_121 , V_122 ;
unsigned long V_123 ;
int V_124 = 1 ;
F_111 ( V_59 , & V_121 , & V_122 ) ;
V_123 = 0 ;
if ( V_117 > V_113 )
F_68 ( V_117 + V_120 , & V_123 ,
sizeof( unsigned long ) ) ;
if ( V_114 == V_116 ) {
if ( V_114 < V_119
|| ( V_121 <= V_114 && V_114 < V_122 ) )
V_124 = 0 ;
} else if ( V_114 == V_123 ) {
V_124 = 0 ;
} else if ( V_114 >= V_119
&& ! ( V_121 <= V_114 && V_114 < V_122 ) ) {
printf ( L_87 ) ;
F_32 ( V_114 , L_7 , L_32 ) ;
}
if ( V_124 ) {
printf ( L_88 V_99 L_89 , V_113 ) ;
F_32 ( V_116 , L_7 , L_90 ) ;
}
V_59 = V_114 = 0 ;
} else {
printf ( L_88 V_99 L_89 , V_113 ) ;
F_32 ( V_116 , L_7 , L_32 ) ;
}
if ( F_68 ( V_113 + V_125 , & V_118 , sizeof( unsigned long ) )
&& V_118 == V_126 ) {
if ( F_68 ( V_113 + V_127 , & V_16 , sizeof( V_16 ) )
!= sizeof( V_16 ) ) {
printf ( L_91 ,
V_113 + V_127 ) ;
break;
}
printf ( L_92 , V_16 . V_34 ,
F_28 ( F_29 ( & V_16 ) ) ) ;
V_59 = V_16 . V_31 ;
V_114 = V_16 . V_81 ;
F_32 ( V_59 , L_7 , L_32 ) ;
}
if ( V_117 == 0 )
break;
V_113 = V_117 ;
}
}
static void F_89 ( struct V_15 * V_51 )
{
unsigned long V_113 ;
if ( F_105 ( & V_113 ) )
F_75 ( V_113 , 0 , 0 ) ;
else
F_75 ( V_51 -> V_80 [ 1 ] , V_51 -> V_81 , V_51 -> V_31 ) ;
F_113 () ;
}
static void F_114 ( struct V_15 * V_16 )
{
#ifdef F_115
const struct V_128 * V_129 ;
unsigned long V_100 ;
if ( V_16 -> V_19 & V_43 )
return;
V_100 = V_16 -> V_31 ;
if ( V_100 < V_119 )
return;
V_129 = F_116 ( V_16 -> V_31 ) ;
if ( V_129 == NULL )
return;
if ( F_117 ( V_129 ) )
return;
#ifdef F_118
printf ( L_93 ,
V_129 -> V_130 , V_129 -> line ) ;
#else
printf ( L_94 , ( void * ) V_129 -> V_131 ) ;
#endif
#endif
}
static void F_27 ( struct V_15 * V_132 )
{
unsigned long V_34 ;
#ifdef F_20
printf ( L_95 , F_11 () ) ;
#endif
V_34 = F_29 ( V_132 ) ;
printf ( L_96 , V_132 -> V_34 , F_28 ( V_34 ) , V_132 ) ;
printf ( L_97 ) ;
F_32 ( V_132 -> V_31 , L_98 , L_32 ) ;
printf ( L_99 , V_132 -> V_81 ) ;
F_32 ( V_132 -> V_81 , L_98 , L_32 ) ;
printf ( L_100 , V_132 -> V_80 [ 1 ] ) ;
printf ( L_101 , V_132 -> V_19 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 || V_34 == 0x200 ) {
printf ( L_102 , V_132 -> V_133 ) ;
if ( V_34 != 0x380 )
printf ( L_103 , V_132 -> V_134 ) ;
}
printf ( L_104 , V_135 ) ;
#ifdef F_119
printf ( L_105 ,
V_136 , V_136 -> V_137 , V_136 -> V_138 ) ;
#endif
if ( V_135 ) {
printf ( L_106 ,
V_135 -> V_139 , V_135 -> V_140 ) ;
}
if ( V_34 == 0x700 )
F_114 ( V_132 ) ;
}
static void F_87 ( struct V_15 * V_132 )
{
int V_141 , V_34 ;
unsigned long V_142 ;
struct V_15 V_16 ;
if ( F_105 ( & V_142 ) ) {
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_16 = * (struct V_15 * ) V_142 ;
F_1 () ;
F_120 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_107 V_99 L_32 ,
V_142 ) ;
return;
}
V_58 = 0 ;
V_132 = & V_16 ;
}
#ifdef F_119
if ( F_121 ( V_132 ) ) {
for ( V_141 = 0 ; V_141 < 16 ; ++ V_141 )
printf ( L_108 V_99 L_109 V_99 L_32 ,
V_141 , V_132 -> V_80 [ V_141 ] , V_141 + 16 , V_132 -> V_80 [ V_141 + 16 ] ) ;
} else {
for ( V_141 = 0 ; V_141 < 7 ; ++ V_141 )
printf ( L_108 V_99 L_109 V_99 L_32 ,
V_141 , V_132 -> V_80 [ V_141 ] , V_141 + 7 , V_132 -> V_80 [ V_141 + 7 ] ) ;
}
#else
for ( V_141 = 0 ; V_141 < 32 ; ++ V_141 ) {
printf ( L_110 , V_141 , V_132 -> V_80 [ V_141 ] ,
( V_141 & 3 ) == 3 ? L_32 : L_111 ) ;
if ( V_141 == 12 && ! F_121 ( V_132 ) ) {
printf ( L_32 ) ;
break;
}
}
#endif
printf ( L_112 ) ;
F_32 ( V_132 -> V_31 , L_7 , L_32 ) ;
if ( F_29 ( V_132 ) != 0xc00 && F_72 ( V_143 ) ) {
printf ( L_113 ) ;
F_32 ( V_132 -> V_144 , L_7 , L_32 ) ;
}
printf ( L_114 ) ;
F_32 ( V_132 -> V_81 , L_7 , L_32 ) ;
printf ( L_115 V_99 L_116 , V_132 -> V_19 , V_132 -> V_145 ) ;
printf ( L_117 V_99 L_118 V_99 L_119 ,
V_132 -> V_146 , V_132 -> V_147 , V_132 -> V_34 ) ;
V_34 = F_29 ( V_132 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 )
printf ( L_120 V_99 L_121 , V_132 -> V_133 , V_132 -> V_134 ) ;
}
static void F_90 ( void )
{
int V_22 ;
unsigned long V_148 ;
V_22 = F_79 () ;
if ( V_22 != 'i' )
V_82 = V_22 ;
F_105 ( ( void * ) & V_97 ) ;
if ( V_82 != '\n' )
V_82 = 0 ;
V_148 = 1 ;
F_105 ( & V_148 ) ;
V_148 = ( V_148 + V_149 - 1 ) / V_149 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
if ( V_22 != 'i' ) {
for (; V_148 > 0 ; -- V_148 , V_97 += V_149 )
F_3 ( ( void * ) V_97 ) ;
} else {
for (; V_148 > 0 ; -- V_148 , V_97 += V_149 )
F_4 ( ( void * ) V_97 ) ;
}
F_1 () ;
F_120 ( 200 ) ;
}
V_58 = 0 ;
}
static unsigned long
F_122 ( int V_141 )
{
unsigned int V_150 [ 2 ] ;
unsigned long ( * V_151 ) ( void ) ;
unsigned long V_106 = - 1UL ;
#ifdef F_119
unsigned long V_152 [ 3 ] ;
V_152 [ 0 ] = ( unsigned long ) V_150 ;
V_152 [ 1 ] = 0 ;
V_152 [ 2 ] = 0 ;
V_151 = ( unsigned long ( * ) ( void ) ) V_152 ;
#else
V_151 = ( unsigned long ( * ) ( void ) ) V_150 ;
#endif
V_150 [ 0 ] = 0x7c6002a6 + ( ( V_141 & 0x1F ) << 16 ) + ( ( V_141 & 0x3e0 ) << 6 ) ;
V_150 [ 1 ] = 0x4e800020 ;
F_2 ( V_150 ) ;
F_2 ( V_150 + 1 ) ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_106 = V_151 () ;
F_1 () ;
F_120 ( 200 ) ;
V_141 = V_109 ;
}
return V_106 ;
}
static void
F_123 ( int V_141 , unsigned long V_153 )
{
unsigned int V_150 [ 2 ] ;
unsigned long ( * V_151 ) ( unsigned long ) ;
#ifdef F_119
unsigned long V_152 [ 3 ] ;
V_152 [ 0 ] = ( unsigned long ) V_150 ;
V_152 [ 1 ] = 0 ;
V_152 [ 2 ] = 0 ;
V_151 = ( unsigned long (*) ( unsigned long ) ) V_152 ;
#else
V_151 = ( unsigned long (*) ( unsigned long ) ) V_150 ;
#endif
V_150 [ 0 ] = 0x7c6003a6 + ( ( V_141 & 0x1F ) << 16 ) + ( ( V_141 & 0x3e0 ) << 6 ) ;
V_150 [ 1 ] = 0x4e800020 ;
F_2 ( V_150 ) ;
F_2 ( V_150 + 1 ) ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_151 ( V_153 ) ;
F_1 () ;
F_120 ( 200 ) ;
V_141 = V_109 ;
}
}
static void F_88 ( void )
{
int V_22 ;
unsigned long V_153 ;
V_22 = F_77 () ;
if ( V_22 == '\n' ) {
unsigned long V_113 , V_154 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_122 V_99 L_123 V_99 L_32 ,
F_124 () , F_104 ( V_155 ) ) ;
printf ( L_124 V_99 L_125 V_99 L_32 ,
F_104 ( V_156 ) , F_104 ( V_157 ) ) ;
printf ( L_126 V_99 L_127 V_99 L_32 ,
F_104 ( V_158 ) , F_104 ( V_159 ) ) ;
printf ( L_128 V_99 L_129 V_99 L_32 , V_113 , F_104 ( V_160 ) ) ;
printf ( L_130 V_99 L_131 V_99 L_32 , V_154 , F_104 ( V_161 ) ) ;
return;
}
F_105 ( & V_162 ) ;
switch ( V_22 ) {
case 'w' :
V_153 = F_122 ( V_162 ) ;
F_105 ( & V_153 ) ;
F_123 ( V_162 , V_153 ) ;
case 'r' :
printf ( L_132 , V_162 , F_122 ( V_162 ) ) ;
break;
}
F_113 () ;
}
static int
F_68 ( unsigned long V_97 , void * V_163 , int V_109 )
{
volatile int V_141 ;
char * V_1 , * V_164 ;
V_141 = 0 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_97 ;
V_164 = ( char * ) V_163 ;
switch ( V_109 ) {
case 2 :
* ( V_165 * ) V_164 = * ( V_165 * ) V_1 ;
break;
case 4 :
* ( V_166 * ) V_164 = * ( V_166 * ) V_1 ;
break;
case 8 :
* ( V_167 * ) V_164 = * ( V_167 * ) V_1 ;
break;
default:
for( ; V_141 < V_109 ; ++ V_141 ) {
* V_164 ++ = * V_1 ++ ;
F_1 () ;
}
}
F_1 () ;
F_120 ( 200 ) ;
V_141 = V_109 ;
}
V_58 = 0 ;
return V_141 ;
}
static int
F_70 ( unsigned long V_97 , void * V_163 , int V_109 )
{
volatile int V_141 ;
char * V_1 , * V_164 ;
V_141 = 0 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_97 ;
V_164 = ( char * ) V_163 ;
switch ( V_109 ) {
case 2 :
* ( V_165 * ) V_1 = * ( V_165 * ) V_164 ;
break;
case 4 :
* ( V_166 * ) V_1 = * ( V_166 * ) V_164 ;
break;
case 8 :
* ( V_167 * ) V_1 = * ( V_167 * ) V_164 ;
break;
default:
for ( ; V_141 < V_109 ; ++ V_141 ) {
* V_1 ++ = * V_164 ++ ;
F_1 () ;
}
}
F_1 () ;
F_120 ( 200 ) ;
V_141 = V_109 ;
} else {
printf ( L_133 V_99 L_32 , V_97 + V_141 ) ;
}
V_58 = 0 ;
return V_141 ;
}
static int F_64 ( struct V_15 * V_16 )
{
V_168 = F_29 ( V_16 ) ;
switch ( F_29 ( V_16 ) ) {
case 0x200 :
V_169 = 0 ;
break;
case 0x300 :
case 0x380 :
V_169 = 1 ;
break;
default:
V_169 = 2 ;
}
longjmp ( V_111 , 1 ) ;
return 0 ;
}
static void
F_125 ( unsigned char * V_153 , int V_109 )
{
int V_170 ;
switch ( V_109 ) {
case 2 :
F_126 ( V_153 [ 0 ] , V_153 [ 1 ] , V_170 ) ;
break;
case 4 :
F_126 ( V_153 [ 0 ] , V_153 [ 3 ] , V_170 ) ;
F_126 ( V_153 [ 1 ] , V_153 [ 2 ] , V_170 ) ;
break;
case 8 :
F_126 ( V_153 [ 0 ] , V_153 [ 7 ] , V_170 ) ;
F_126 ( V_153 [ 1 ] , V_153 [ 6 ] , V_170 ) ;
F_126 ( V_153 [ 2 ] , V_153 [ 5 ] , V_170 ) ;
F_126 ( V_153 [ 3 ] , V_153 [ 4 ] , V_170 ) ;
break;
}
}
static void
F_84 ( void )
{
int V_22 , V_171 , V_60 , V_172 ;
unsigned long V_141 ;
unsigned char V_153 [ 16 ] ;
F_105 ( ( void * ) & V_97 ) ;
V_22 = F_77 () ;
if ( V_22 == '?' ) {
printf ( V_173 ) ;
return;
} else {
V_82 = V_22 ;
}
V_77 = L_134 ;
while ( ( V_22 = F_77 () ) != '\n' ) {
switch( V_22 ) {
case 'b' : V_109 = 1 ; break;
case 'w' : V_109 = 2 ; break;
case 'l' : V_109 = 4 ; break;
case 'd' : V_109 = 8 ; break;
case 'r' : V_174 = ! V_174 ; break;
case 'n' : V_175 = 1 ; break;
case '.' : V_175 = 0 ; break;
}
}
if( V_109 <= 0 )
V_109 = 1 ;
else if( V_109 > 8 )
V_109 = 8 ;
for(; ; ) {
if ( ! V_175 )
V_141 = F_68 ( V_97 , V_153 , V_109 ) ;
printf ( V_99 L_135 , V_97 , V_174 ? 'r' : ' ' ) ;
if ( ! V_175 ) {
if ( V_174 )
F_125 ( V_153 , V_109 ) ;
putchar ( ' ' ) ;
for ( V_60 = 0 ; V_60 < V_141 ; ++ V_60 )
printf ( L_136 , V_153 [ V_60 ] ) ;
for (; V_60 < V_109 ; ++ V_60 )
printf ( L_137 , V_176 [ V_169 ] ) ;
}
putchar ( ' ' ) ;
V_171 = V_109 ;
V_172 = 0 ;
for(; ; ) {
if( F_105 ( & V_141 ) ) {
for ( V_60 = 0 ; V_60 < V_109 ; ++ V_60 )
V_153 [ V_60 ] = V_141 >> ( V_60 * 8 ) ;
if ( ! V_174 )
F_125 ( V_153 , V_109 ) ;
F_70 ( V_97 , V_153 , V_109 ) ;
V_171 = V_109 ;
}
V_22 = F_77 () ;
if ( V_22 == '\n' )
break;
V_171 = 0 ;
switch ( V_22 ) {
case '\'' :
for(; ; ) {
V_141 = F_79 () ;
if( V_141 == '\\' )
V_141 = F_127 () ;
else if( V_141 == '\'' )
break;
for ( V_60 = 0 ; V_60 < V_109 ; ++ V_60 )
V_153 [ V_60 ] = V_141 >> ( V_60 * 8 ) ;
if ( ! V_174 )
F_125 ( V_153 , V_109 ) ;
F_70 ( V_97 , V_153 , V_109 ) ;
V_97 += V_109 ;
}
V_97 -= V_109 ;
V_171 = V_109 ;
break;
case ',' :
V_97 += V_109 ;
break;
case '.' :
V_175 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_50 :
F_113 () ;
return;
case 'b' :
case 'v' :
V_109 = 1 ;
break;
case 'w' :
V_109 = 2 ;
break;
case 'l' :
V_109 = 4 ;
break;
case 'u' :
V_109 = 8 ;
break;
case '^' :
V_97 -= V_109 ;
break;
break;
case '/' :
if ( V_172 > 0 )
V_97 -= 1 << V_172 ;
else
V_172 = 0 ;
V_172 += 4 ;
V_97 += 1 << V_172 ;
break;
case '\\' :
if ( V_172 < 0 )
V_97 += 1 << - V_172 ;
else
V_172 = 0 ;
V_172 -= 4 ;
V_97 -= 1 << - V_172 ;
break;
case 'm' :
F_105 ( ( void * ) & V_97 ) ;
break;
case 'n' :
V_175 = 1 ;
break;
case 'r' :
V_174 = ! V_174 ;
break;
case '<' :
V_141 = V_109 ;
F_105 ( & V_141 ) ;
V_97 -= V_141 ;
break;
case '>' :
V_141 = V_109 ;
F_105 ( & V_141 ) ;
V_97 += V_141 ;
break;
case '?' :
printf ( V_177 ) ;
break;
}
}
V_97 += V_171 ;
}
}
static int
F_127 ( void )
{
int V_178 ;
V_178 = F_79 () ;
switch( V_178 ) {
case 'n' : V_178 = '\n' ; break;
case 'r' : V_178 = '\r' ; break;
case 'b' : V_178 = '\b' ; break;
case 't' : V_178 = '\t' ; break;
}
return V_178 ;
}
static void F_128 ( unsigned long V_97 , long V_179 )
{
long V_141 , V_180 , V_181 , V_182 ;
unsigned char V_183 [ 16 ] ;
for ( V_141 = V_179 ; V_141 > 0 ; ) {
V_181 = V_141 < 16 ? V_141 : 16 ;
V_182 = F_68 ( V_97 , V_183 , V_181 ) ;
V_97 += V_182 ;
for ( V_180 = 0 ; V_180 < V_181 ; ++ V_180 ) {
if ( V_180 < V_182 )
printf ( L_136 , V_183 [ V_180 ] ) ;
else
printf ( L_137 , V_176 [ V_169 ] ) ;
}
V_141 -= V_181 ;
if ( V_182 < V_181 )
break;
}
printf ( L_32 ) ;
}
static void F_129 ( int V_29 )
{
struct V_184 * V_1 ;
if ( setjmp ( V_111 ) != 0 ) {
printf ( L_138 , V_29 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
V_1 = & V_185 [ V_29 ] ;
printf ( L_139 , V_29 , V_1 ) ;
printf ( L_140 , 16 , L_141 , F_130 ( V_29 ) ? L_142 : L_143 ) ;
printf ( L_140 , 16 , L_144 , F_131 ( V_29 ) ? L_142 : L_143 ) ;
printf ( L_140 , 16 , L_145 , F_132 ( V_29 ) ? L_142 : L_143 ) ;
#define F_133 ( V_185 , V_110 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 16, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_133 ( V_1 , V_186 , L_146 ) ;
F_133 ( V_1 , V_187 , L_146 ) ;
F_133 ( V_1 , V_188 , L_147 ) ;
F_133 ( V_1 , V_189 , L_147 ) ;
F_133 ( V_1 , V_190 , L_147 ) ;
F_133 ( V_1 , V_191 , L_148 ) ;
#ifdef F_134
F_133 ( V_1 , V_192 , L_148 ) ;
F_133 ( V_1 , V_193 , L_146 ) ;
#endif
F_133 ( V_1 , V_194 , L_147 ) ;
F_133 ( V_1 , V_195 , L_146 ) ;
F_133 ( V_1 , V_196 , L_146 ) ;
F_133 ( V_1 , V_197 , L_146 ) ;
F_133 ( V_1 , V_198 , L_148 ) ;
F_133 ( V_1 , V_199 , L_147 ) ;
F_133 ( V_1 , V_200 , L_147 ) ;
F_133 ( V_1 , V_201 , L_147 ) ;
F_133 ( V_1 , V_202 , L_146 ) ;
F_133 ( V_1 , V_137 , L_146 ) ;
F_133 ( V_1 , V_138 , L_146 ) ;
F_133 ( V_1 , V_203 , L_146 ) ;
F_133 ( V_1 , V_204 , L_146 ) ;
F_133 ( V_1 , V_205 , L_146 ) ;
#undef F_133
V_58 = 0 ;
F_1 () ;
}
static void F_135 ( void )
{
int V_29 ;
if ( F_136 () == 0 ) {
printf ( L_149 ) ;
return;
}
F_106 (cpu)
F_129 ( V_29 ) ;
}
static void F_137 ( void )
{
unsigned long V_206 ;
int V_178 ;
V_178 = F_79 () ;
if ( V_178 == 'a' ) {
F_135 () ;
return;
}
V_82 = V_178 ;
if ( F_105 ( & V_206 ) )
F_129 ( V_206 ) ;
else
F_129 ( V_40 ) ;
}
static void
F_85 ( void )
{
int V_178 ;
V_178 = F_79 () ;
#ifdef F_119
if ( V_178 == 'p' ) {
F_137 () ;
return;
}
#endif
if ( ( isxdigit ( V_178 ) && V_178 != 'f' && V_178 != 'd' ) || V_178 == '\n' )
V_82 = V_178 ;
F_105 ( ( void * ) & V_97 ) ;
if ( V_82 != '\n' )
V_82 = 0 ;
if ( V_178 == 'i' ) {
F_105 ( & V_207 ) ;
if ( V_207 == 0 )
V_207 = 16 ;
else if ( V_207 > V_208 )
V_207 = V_208 ;
V_97 += F_41 ( V_97 , V_207 , 1 ) ;
V_77 = L_150 ;
} else if ( V_178 == 'l' ) {
F_138 () ;
} else if ( V_178 == 'r' ) {
F_105 ( & V_179 ) ;
if ( V_179 == 0 )
V_179 = 64 ;
F_128 ( V_97 , V_179 ) ;
V_97 += V_179 ;
V_77 = L_151 ;
} else {
F_105 ( & V_179 ) ;
if ( V_179 == 0 )
V_179 = 64 ;
else if ( V_179 > V_208 )
V_179 = V_208 ;
F_139 ( V_97 , V_179 ) ;
V_97 += V_179 ;
V_77 = L_152 ;
}
}
static void
F_139 ( unsigned long V_97 , long V_179 )
{
long V_141 , V_180 , V_178 , V_181 , V_182 ;
unsigned char V_183 [ 16 ] ;
for ( V_141 = V_179 ; V_141 > 0 ; ) {
printf ( V_99 , V_97 ) ;
putchar ( ' ' ) ;
V_181 = V_141 < 16 ? V_141 : 16 ;
V_182 = F_68 ( V_97 , V_183 , V_181 ) ;
V_97 += V_182 ;
for ( V_180 = 0 ; V_180 < V_181 ; ++ V_180 ) {
if ( ( V_180 & ( sizeof( long ) - 1 ) ) == 0 && V_180 > 0 )
putchar ( ' ' ) ;
if ( V_180 < V_182 )
printf ( L_136 , V_183 [ V_180 ] ) ;
else
printf ( L_137 , V_176 [ V_169 ] ) ;
}
for (; V_180 < 16 ; ++ V_180 ) {
if ( ( V_180 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_60 ) ;
}
printf ( L_153 ) ;
for ( V_180 = 0 ; V_180 < V_181 ; ++ V_180 ) {
if ( V_180 < V_182 ) {
V_178 = V_183 [ V_180 ] ;
putchar ( ' ' <= V_178 && V_178 <= '~' ? V_178 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_141 -= V_181 ;
for (; V_180 < 16 ; ++ V_180 )
putchar ( ' ' ) ;
printf ( L_154 ) ;
if ( V_182 < V_181 )
break;
}
}
static int
F_140 ( unsigned long V_209 , long V_210 , int V_211 ,
T_3 V_212 )
{
int V_182 , V_213 ;
unsigned long V_214 ;
unsigned long V_215 , V_216 = 0 ;
unsigned char V_153 [ 4 ] ;
V_213 = 0 ;
for ( V_214 = V_209 ; V_210 > 0 ; -- V_210 , V_209 += 4 ) {
V_182 = F_68 ( V_209 , V_153 , 4 ) ;
if ( V_182 == 0 ) {
if ( V_211 ) {
const char * V_217 = V_176 [ V_169 ] ;
printf ( V_99 L_155 , V_209 , V_217 , V_217 , V_217 , V_217 ) ;
}
break;
}
V_215 = F_141 ( V_153 ) ;
if ( V_209 > V_214 && V_215 == V_216 ) {
if ( ! V_213 ) {
printf ( L_156 ) ;
V_213 = 1 ;
}
continue;
}
V_213 = 0 ;
V_216 = V_215 ;
if ( V_211 )
printf ( V_99 L_157 , V_209 , V_215 ) ;
printf ( L_158 ) ;
V_212 ( V_215 , V_209 ) ;
printf ( L_32 ) ;
}
return V_209 - V_214 ;
}
static int
F_41 ( unsigned long V_209 , long V_210 , int V_211 )
{
return F_140 ( V_209 , V_210 , V_211 , V_218 ) ;
}
void
F_142 ( unsigned long V_100 )
{
F_32 ( V_100 , L_159 , L_84 ) ;
}
void
F_138 ( void )
{
struct V_219 V_220 = { . V_221 = 1 } ;
unsigned char V_163 [ 128 ] ;
T_4 V_73 ;
if ( setjmp ( V_111 ) != 0 ) {
printf ( L_160 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
F_143 ( & V_220 ) ;
while ( F_144 ( & V_220 , false , V_163 , sizeof( V_163 ) , & V_73 ) ) {
V_163 [ V_73 ] = '\0' ;
printf ( L_137 , V_163 ) ;
}
F_1 () ;
F_120 ( 200 ) ;
V_58 = 0 ;
}
static void
F_80 ( int V_22 )
{
F_105 ( ( void * ) & V_222 ) ;
if( V_82 != '\n' )
V_82 = 0 ;
F_105 ( ( void * ) ( V_22 == 's' ? & V_223 : & V_224 ) ) ;
if( V_82 != '\n' )
V_82 = 0 ;
F_105 ( ( void * ) & V_225 ) ;
switch( V_22 ) {
case 'm' :
memmove ( ( void * ) V_222 , ( void * ) V_224 , V_225 ) ;
break;
case 's' :
memset ( ( void * ) V_222 , V_223 , V_225 ) ;
break;
case 'd' :
if( V_82 != '\n' )
V_82 = 0 ;
F_105 ( ( void * ) & V_226 ) ;
F_145 ( ( unsigned char * ) V_222 , ( unsigned char * ) V_224 , V_225 , V_226 ) ;
break;
}
}
static void
F_145 ( unsigned char * V_227 , unsigned char * V_228 , unsigned V_229 , unsigned V_230 )
{
unsigned V_141 , V_231 ;
V_231 = 0 ;
for( V_141 = V_229 ; V_141 > 0 ; -- V_141 )
if( * V_227 ++ != * V_228 ++ )
if( ++ V_231 <= V_230 )
printf ( L_161 , V_227 - 1 ,
V_227 [ - 1 ] , V_228 - 1 , V_228 [ - 1 ] ) ;
if( V_231 > V_230 )
printf ( L_162 , V_231 ) ;
}
static void
F_81 ( void )
{
unsigned V_65 , V_141 ;
unsigned char V_153 [ 4 ] ;
V_77 = L_163 ;
F_105 ( ( void * ) & V_222 ) ;
if ( V_82 != '\n' ) {
V_82 = 0 ;
F_105 ( ( void * ) & V_232 ) ;
if ( V_82 != '\n' ) {
V_82 = 0 ;
F_105 ( ( void * ) & V_223 ) ;
V_233 = ~ 0 ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_105 ( ( void * ) & V_233 ) ;
}
}
V_141 = 0 ;
for ( V_65 = V_222 ; V_65 < V_232 ; V_65 += 4 ) {
if ( F_68 ( V_65 , V_153 , 4 ) == 4
&& ( ( F_141 ( V_153 ) ^ V_223 ) & V_233 ) == 0 ) {
printf ( L_164 , V_65 , F_141 ( V_153 ) ) ;
if ( ++ V_141 >= 10 )
break;
}
}
}
static void
F_82 ( void )
{
unsigned char V_96 ;
unsigned V_65 ;
int V_234 , V_235 ;
F_105 ( & V_222 ) ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_105 ( & V_236 ) ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_105 ( & V_237 ) ;
V_235 = 0 ;
for ( V_65 = V_222 ; V_65 < V_237 ; V_65 += V_236 ) {
V_234 = F_68 ( V_65 , & V_96 , 1 ) ;
if ( V_234 && ! V_235 ) {
printf ( L_165 , V_65 ) ;
} else if ( ! V_234 && V_235 )
printf ( L_166 , V_65 - V_236 ) ;
V_235 = V_234 ;
if ( V_65 + V_236 < V_65 )
break;
}
if ( V_235 )
printf ( L_166 , V_65 - V_236 ) ;
}
static void F_99 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_106 ;
int V_60 ;
typedef unsigned long (* T_5)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_5 V_238 ;
if ( ! F_105 ( & V_97 ) )
return;
if ( V_82 != '\n' )
V_82 = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 )
args [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 ) {
if ( ! F_105 ( & args [ V_60 ] ) || V_82 == '\n' )
break;
V_82 = 0 ;
}
V_238 = ( T_5 ) V_97 ;
V_106 = 0 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_106 = V_238 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_1 () ;
printf ( L_167 , V_106 ) ;
} else {
printf ( L_168 , V_168 ) ;
}
V_58 = 0 ;
}
int
F_77 ( void )
{
int V_178 ;
if( V_82 != 0 ) {
V_178 = V_82 ;
V_82 = 0 ;
} else
V_178 = F_79 () ;
while( V_178 == ' ' || V_178 == '\t' )
V_178 = F_79 () ;
return V_178 ;
}
int
F_105 ( unsigned long * V_239 )
{
int V_178 , V_53 ;
unsigned long V_96 ;
V_178 = F_77 () ;
if ( V_178 == '%' ) {
char V_240 [ 8 ] ;
int V_60 ;
for ( V_60 = 0 ; V_60 < sizeof( V_240 ) - 1 ; ++ V_60 ) {
V_178 = F_79 () ;
if ( ! isalnum ( V_178 ) ) {
V_82 = V_178 ;
break;
}
V_240 [ V_60 ] = V_178 ;
}
V_240 [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < V_241 ; ++ V_60 ) {
if ( strcmp ( V_242 [ V_60 ] , V_240 ) == 0 ) {
if ( V_78 == NULL ) {
printf ( L_169 ) ;
return 0 ;
}
* V_239 = ( ( unsigned long * ) V_78 ) [ V_60 ] ;
return 1 ;
}
}
printf ( L_170 , V_240 ) ;
return 0 ;
}
if ( V_178 == '0' ) {
V_178 = F_79 () ;
if ( V_178 == 'x' ) {
V_178 = F_79 () ;
} else {
V_53 = F_146 ( V_178 ) ;
if ( V_53 == V_50 ) {
V_82 = V_178 ;
* V_239 = 0 ;
return 1 ;
}
}
} else if ( V_178 == '$' ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 63 ; V_60 ++ ) {
V_178 = F_79 () ;
if ( isspace ( V_178 ) ) {
V_82 = V_178 ;
break;
}
V_112 [ V_60 ] = V_178 ;
}
V_112 [ V_60 ++ ] = 0 ;
* V_239 = 0 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
* V_239 = F_147 ( V_112 ) ;
F_1 () ;
}
V_58 = 0 ;
if ( ! ( * V_239 ) ) {
printf ( L_171 , V_112 ) ;
return 0 ;
}
return 1 ;
}
V_53 = F_146 ( V_178 ) ;
if ( V_53 == V_50 ) {
V_82 = V_178 ;
return 0 ;
}
V_96 = 0 ;
do {
V_96 = ( V_96 << 4 ) + V_53 ;
V_178 = F_79 () ;
V_53 = F_146 ( V_178 ) ;
} while ( V_53 != V_50 );
V_82 = V_178 ;
* V_239 = V_96 ;
return 1 ;
}
static void
F_113 ( void )
{
int V_178 ;
V_178 = V_82 ;
V_82 = 0 ;
while( V_178 != '\n' )
V_178 = F_79 () ;
}
static int F_146 ( int V_178 )
{
if( '0' <= V_178 && V_178 <= '9' )
return V_178 - '0' ;
if( 'A' <= V_178 && V_178 <= 'F' )
return V_178 - ( 'A' - 10 ) ;
if( 'a' <= V_178 && V_178 <= 'f' )
return V_178 - ( 'a' - 10 ) ;
return V_50 ;
}
void
F_148 ( char * V_243 , int V_109 )
{
int V_178 ;
V_178 = F_77 () ;
do {
if( V_109 > 1 ) {
* V_243 ++ = V_178 ;
-- V_109 ;
}
V_178 = F_79 () ;
} while( V_178 != ' ' && V_178 != '\t' && V_178 != '\n' );
V_82 = V_178 ;
* V_243 = 0 ;
}
static void
F_76 ( void )
{
V_244 = NULL ;
}
static int
F_79 ( void )
{
if ( V_244 == NULL || * V_244 == 0 ) {
if ( F_149 ( line , sizeof( line ) ) == NULL ) {
V_244 = NULL ;
return V_50 ;
}
V_244 = line ;
}
return * V_244 ++ ;
}
static void
F_78 ( char * V_245 )
{
V_244 = V_245 ;
}
static void
F_86 ( void )
{
int type = F_79 () ;
unsigned long V_100 ;
static char V_246 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_105 ( & V_100 ) )
F_32 ( V_100 , L_98 , L_32 ) ;
V_82 = 0 ;
break;
case 's' :
F_148 ( V_246 , 64 ) ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_100 = F_147 ( V_246 ) ;
if ( V_100 )
printf ( L_172 , V_246 , V_100 ) ;
else
printf ( L_173 , V_246 ) ;
F_1 () ;
}
V_58 = 0 ;
V_82 = 0 ;
break;
}
}
static void F_32 ( unsigned long V_32 , const char * V_247 ,
const char * V_248 )
{
char * V_249 ;
const char * V_110 = NULL ;
unsigned long V_27 , V_109 ;
printf ( V_99 , V_32 ) ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_110 = F_112 ( V_32 , & V_109 , & V_27 , & V_249 ,
V_112 ) ;
F_1 () ;
F_120 ( 200 ) ;
}
V_58 = 0 ;
if ( V_110 ) {
printf ( L_174 , V_247 , V_110 , V_27 , V_109 ) ;
if ( V_249 )
printf ( L_175 , V_249 ) ;
}
printf ( L_137 , V_248 ) ;
}
void F_101 ( void )
{
int V_60 ;
unsigned long V_250 , V_251 , V_252 ;
unsigned long V_253 ;
printf ( L_176 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_254 ; V_60 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
V_252 = ( V_250 & V_255 ) ;
if ( V_252 | V_250 | V_251 ) {
printf ( L_177 , V_60 , V_250 , V_251 ) ;
if ( V_252 ) {
V_253 = V_251 & V_256 ;
if ( V_251 & V_257 ) {
printf ( L_178 ,
F_150 ( V_250 ) ,
( V_251 & ~ V_258 ) >> V_259 ,
V_253 ) ;
} else {
printf ( L_179 ,
F_151 ( V_250 ) ,
( V_251 & ~ V_258 ) >> V_260 ,
V_253 ) ;
}
} else
printf ( L_32 ) ;
}
}
}
void F_101 ( void )
{
int V_60 ;
printf ( L_180 ) ;
for ( V_60 = 0 ; V_60 < 16 ; ++ V_60 )
printf ( L_181 , F_152 ( V_60 ) ) ;
printf ( L_32 ) ;
}
static void F_102 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_261 ; V_60 ++ ) {
unsigned long V_262 , V_263 , V_264 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_182 , V_60 , V_262 , V_263 , V_264 ) ;
if ( V_262 & V_265 ) {
printf ( L_183 ,
V_262 & V_266 ,
V_263 & V_267 ,
V_263 & V_268 ,
( V_264 & V_269 ) ? 'W' : 'w' ,
( V_264 & V_270 ) ? 'I' : 'i' ,
( V_264 & V_271 ) ? 'M' : 'm' ,
( V_264 & V_272 ) ? 'G' : 'g' ,
( V_264 & V_273 ) ? 'E' : 'e' ) ;
}
printf ( L_32 ) ;
}
}
static void F_103 ( void )
{
V_166 V_274 , V_275 , V_276 ;
V_167 V_277 ;
int V_60 , V_278 , V_279 , V_280 , V_281 , V_282 , V_283 = 0 ;
int V_284 ;
static const char * V_285 [] = {
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
V_274 = F_104 ( V_286 ) ;
V_284 = ( V_274 & 3 ) + 1 ;
V_279 = ( ( V_274 >> 2 ) & 3 ) + 1 ;
V_280 = ( ( V_274 >> 6 ) & 0x1f ) + 1 ;
V_281 = ( V_274 >> 24 ) & 0xf ;
V_282 = ( V_274 >> 16 ) & 0x7f ;
if ( ( V_284 > 1 ) && ( V_274 & 0x10000 ) )
V_283 = 1 ;
printf ( L_216 ,
V_284 , V_279 , V_280 , V_281 , V_282 ) ;
V_275 = ( 1ul << V_280 ) - 1 ;
V_276 = ( 1ul << V_281 ) - 1 ;
V_277 = ( 1ull << V_282 ) - 1 ;
for ( V_278 = 0 ; V_278 < V_279 ; V_278 ++ ) {
V_166 V_287 ;
int V_288 , V_289 , V_290 = 1 ;
printf ( L_217 , V_278 ) ;
switch( V_278 ) {
case 0 :
V_287 = F_104 ( V_291 ) ;
break;
case 1 :
V_287 = F_104 ( V_292 ) ;
break;
case 2 :
V_287 = F_104 ( V_293 ) ;
break;
case 3 :
V_287 = F_104 ( V_294 ) ;
break;
default:
printf ( L_218 ) ;
continue;
}
V_288 = V_287 & 0xfff ;
V_289 = ( V_287 >> 24 ) & 0xff ;
for ( V_60 = 0 ; V_60 < V_288 ; V_60 ++ ) {
V_166 V_295 = F_153 ( V_278 ) ;
V_166 V_296 = F_154 ( V_297 ) ;
V_167 V_298 = 0 ;
V_167 V_299 ;
int V_300 = V_60 , V_301 = V_60 ;
if ( V_289 != 0 ) {
V_301 = V_60 / V_289 ;
V_300 = V_60 % V_289 ;
V_298 = V_301 * 0x1000 ;
}
V_295 |= F_155 ( V_300 ) ;
F_73 ( V_302 , V_295 ) ;
F_73 ( V_303 , V_296 ) ;
F_73 ( V_304 , V_298 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_296 = F_104 ( V_303 ) ;
V_298 = F_104 ( V_304 ) ;
V_299 = F_104 ( V_305 ) ;
if ( V_289 && ( V_60 % V_289 ) == 0 )
V_290 = 1 ;
if ( ! ( V_296 & V_306 ) )
continue;
if ( V_289 == 0 )
printf ( L_219 , V_60 ) ;
else if ( V_290 )
printf ( L_220 , V_301 , 'A' + V_300 ) ;
else
printf ( L_221 , 'A' + V_300 ) ;
V_290 = 0 ;
printf ( L_222 ,
V_298 & ~ 0x3ffull ,
( V_296 >> 16 ) & 0x3fff ,
V_285 [ ( V_296 >> 7 ) & 0x1f ] ,
V_296 & V_307 ? 'I' : ' ' ,
V_296 & V_308 ? 'P' : ' ' ,
V_296 & V_309 ? '1' : '0' ) ;
printf ( L_223 ,
V_298 & V_310 ? 'a' : ' ' ,
V_298 & V_311 ? 'v' : ' ' ,
V_298 & V_312 ? 'w' : ' ' ,
V_298 & V_313 ? 'i' : ' ' ,
V_298 & V_314 ? 'm' : ' ' ,
V_298 & V_315 ? 'g' : ' ' ,
V_298 & V_316 ? 'e' : ' ' ) ;
printf ( L_224 , V_299 & V_277 & ~ 0x7ffull ) ;
if ( V_296 & V_307 )
printf ( L_225 ,
V_285 [ ( V_299 >> 1 ) & 0x1f ] ) ;
else
printf ( L_226 ,
V_299 & V_317 ? 'x' : ' ' ,
V_299 & V_318 ? 'w' : ' ' ,
V_299 & V_319 ? 'r' : ' ' ,
V_299 & V_320 ? 'x' : ' ' ,
V_299 & V_321 ? 'w' : ' ' ,
V_299 & V_322 ? 'r' : ' ' ) ;
}
}
}
static void F_156 ( int V_323 )
{
if ( V_323 ) {
V_324 = F_53 ;
V_325 = F_62 ;
V_326 = F_57 ;
V_327 = F_58 ;
V_328 = F_61 ;
V_329 = F_60 ;
V_330 = F_63 ;
} else {
V_324 = NULL ;
V_325 = NULL ;
V_326 = NULL ;
V_327 = NULL ;
V_328 = NULL ;
V_329 = NULL ;
V_330 = NULL ;
}
}
static void F_157 ( int V_331 )
{
F_156 ( 1 ) ;
F_158 ( F_56 () ) ;
}
static int T_6 F_159 ( void )
{
F_160 ( 'x' , & V_332 ) ;
return 0 ;
}
static int T_6 F_161 ( char * V_1 )
{
if ( ! V_1 || strncmp ( V_1 , L_227 , 5 ) == 0 ) {
F_156 ( 1 ) ;
V_333 = 1 ;
} else if ( strncmp ( V_1 , L_228 , 2 ) == 0 )
F_156 ( 1 ) ;
else if ( strncmp ( V_1 , L_229 , 3 ) == 0 )
V_334 = 1 ;
else if ( strncmp ( V_1 , L_230 , 4 ) == 0 )
V_79 = 1 ;
else
return 1 ;
return 0 ;
}
void T_6 F_162 ( void )
{
#ifdef F_163
if ( ! V_334 )
F_156 ( 1 ) ;
#endif
if ( V_333 )
F_158 ( NULL ) ;
}
void F_164 ( struct V_335 * V_336 )
{
struct V_337 * V_337 ;
F_165 (spu, list, full_list) {
if ( V_337 -> V_338 >= V_339 ) {
F_166 ( 1 ) ;
continue;
}
V_340 [ V_337 -> V_338 ] . V_337 = V_337 ;
V_340 [ V_337 -> V_338 ] . V_341 = 0 ;
V_340 [ V_337 -> V_338 ] . V_342 = ( unsigned long )
V_340 [ V_337 -> V_338 ] . V_337 -> V_343 ;
}
}
static void F_167 ( void )
{
struct V_337 * V_337 ;
int V_60 ;
V_167 V_246 ;
for ( V_60 = 0 ; V_60 < V_339 ; V_60 ++ ) {
if ( ! V_340 [ V_60 ] . V_337 )
continue;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_337 = V_340 [ V_60 ] . V_337 ;
V_340 [ V_60 ] . V_344 =
F_168 ( & V_337 -> V_345 -> V_346 ) ;
V_246 = F_169 ( V_337 ) ;
V_340 [ V_60 ] . V_347 = V_246 ;
V_246 &= ~ V_348 ;
F_170 ( V_337 , V_246 ) ;
F_1 () ;
F_120 ( 200 ) ;
V_340 [ V_60 ] . V_341 = 1 ;
printf ( L_231 , V_60 ,
V_340 [ V_60 ] . V_344 ?
L_232 : L_233 ) ;
} else {
V_58 = 0 ;
printf ( L_234 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_171 ( void )
{
struct V_337 * V_337 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_339 ; V_60 ++ ) {
if ( ! V_340 [ V_60 ] . V_337 )
continue;
if ( ! V_340 [ V_60 ] . V_341 ) {
printf ( L_235
L_236 , V_60 ) ;
continue;
}
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_337 = V_340 [ V_60 ] . V_337 ;
F_170 ( V_337 , V_340 [ V_60 ] . V_347 ) ;
F_172 ( & V_337 -> V_345 -> V_346 ,
V_340 [ V_60 ] . V_344 ) ;
F_1 () ;
F_120 ( 200 ) ;
printf ( L_237 , V_60 ) ;
} else {
V_58 = 0 ;
printf ( L_238 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_173 ( struct V_337 * V_337 )
{
printf ( L_239 , V_337 ) ;
F_174 ( V_337 , L_240 , V_338 ) ;
F_174 ( V_337 , L_137 , V_110 ) ;
F_174 ( V_337 , L_241 , V_349 ) ;
F_174 ( V_337 , L_242 , V_343 ) ;
F_174 ( V_337 , L_241 , V_350 ) ;
F_174 ( V_337 , L_240 , V_351 ) ;
F_174 ( V_337 , L_241 , V_28 ) ;
F_174 ( V_337 , L_243 , V_352 ) ;
F_174 ( V_337 , L_241 , V_353 ) ;
F_174 ( V_337 , L_241 , V_354 ) ;
F_174 ( V_337 , L_241 , V_355 ) ;
F_174 ( V_337 , L_241 , V_356 [ 0 ] ) ;
F_174 ( V_337 , L_241 , V_356 [ 1 ] ) ;
F_174 ( V_337 , L_241 , V_356 [ 2 ] ) ;
F_174 ( V_337 , L_240 , V_357 ) ;
F_174 ( V_337 , L_243 , V_139 ) ;
F_174 ( V_337 , L_242 , V_358 ) ;
F_174 ( V_337 , L_242 , V_359 ) ;
F_174 ( V_337 , L_242 , V_360 ) ;
F_174 ( V_337 , L_242 , V_361 ) ;
F_174 ( V_337 , L_241 , V_362 ) ;
F_174 ( V_337 , L_242 , V_345 ) ;
F_175 ( L_240 , V_345 -> V_346 ,
F_168 ( & V_337 -> V_345 -> V_346 ) ) ;
F_175 ( L_240 , V_345 -> V_363 ,
F_168 ( & V_337 -> V_345 -> V_363 ) ) ;
F_175 ( L_240 , V_345 -> V_364 ,
F_168 ( & V_337 -> V_345 -> V_364 ) ) ;
F_174 ( V_337 , L_242 , V_365 ) ;
F_174 ( V_337 , L_242 , V_366 ) ;
}
int
F_176 ( unsigned long V_209 , long V_210 , int V_211 )
{
return F_140 ( V_209 , V_210 , V_211 , V_367 ) ;
}
static void F_177 ( unsigned long V_206 , int V_368 )
{
unsigned long V_27 , V_100 , V_369 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_369 = ( unsigned long ) V_340 [ V_206 ] . V_337 -> V_343 ;
F_1 () ;
F_120 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_244 , V_206 ) ;
return;
}
V_58 = 0 ;
if ( F_105 ( & V_27 ) )
V_100 = V_369 + V_27 ;
else
V_100 = V_340 [ V_206 ] . V_342 ;
if ( V_100 >= V_369 + V_370 ) {
printf ( L_245 ) ;
return;
}
switch ( V_368 ) {
case 'i' :
V_100 += F_176 ( V_100 , 16 , 1 ) ;
V_77 = L_246 ;
break;
default:
F_139 ( V_100 , 64 ) ;
V_100 += 64 ;
V_77 = L_247 ;
break;
}
V_340 [ V_206 ] . V_342 = V_100 ;
}
static int F_91 ( void )
{
static unsigned long V_206 = 0 ;
int V_22 , V_368 = 0 ;
V_22 = F_79 () ;
switch ( V_22 ) {
case 's' :
F_167 () ;
break;
case 'r' :
F_171 () ;
break;
case 'd' :
V_368 = F_79 () ;
if ( isxdigit ( V_368 ) || V_368 == '\n' )
V_82 = V_368 ;
case 'f' :
F_105 ( & V_206 ) ;
if ( V_206 >= V_339 || ! V_340 [ V_206 ] . V_337 ) {
printf ( L_248 ) ;
return 0 ;
}
switch ( V_22 ) {
case 'f' :
F_173 ( V_340 [ V_206 ] . V_337 ) ;
break;
default:
F_177 ( V_206 , V_368 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_91 ( void )
{
return - 1 ;
}
