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
if ( V_13 == 0 ) {
V_10 = F_12 ( & V_13 , 0 , V_9 ) ;
if ( V_10 == 0 )
return;
}
V_12 = 10000000 ;
while ( V_13 == V_10 ) {
if ( -- V_12 > 0 )
continue;
V_11 = F_12 ( & V_13 , V_10 , V_9 ) ;
if ( V_11 == V_10 )
return;
break;
}
}
}
static void F_13 ( void )
{
V_13 = 0 ;
}
int F_14 ( void )
{
return ! F_15 ( & V_14 ) ;
}
static inline int F_16 ( struct V_15 * V_16 )
{
#if F_17 ( V_17 ) || F_17 ( V_18 )
return 0 ;
#else
return ( ( V_16 -> V_19 & V_20 ) == 0 ) ;
#endif
}
static int F_18 ( struct V_15 * V_16 , int V_21 )
{
int V_22 = 0 ;
struct V_23 * V_24 ;
long V_25 [ V_26 ] ;
unsigned long V_27 ;
unsigned long V_28 ;
#ifdef F_19
int V_29 ;
int V_30 ;
unsigned long V_12 ;
#endif
F_20 ( V_28 ) ;
V_24 = F_21 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = V_24 -> V_32 + V_27 ;
F_22 ( & V_24 -> V_33 ) ;
}
F_23 () ;
#ifdef F_19
V_29 = F_11 () ;
if ( F_24 ( V_29 , & V_14 ) ) {
F_10 () ;
F_25 ( V_16 ) ;
printf ( L_2
L_3 ,
V_29 , V_16 -> V_34 , F_26 ( F_27 ( V_16 ) ) ) ;
F_13 () ;
longjmp ( V_35 [ V_29 ] , 1 ) ;
}
if ( setjmp ( V_25 ) != 0 ) {
if ( ! V_36 || ! V_37 ) {
F_10 () ;
printf ( L_4
L_5 , V_29 ) ;
F_13 () ;
goto V_38;
}
V_30 = ! ( V_39 && V_29 == V_40 ) ;
goto V_41;
}
V_35 [ V_29 ] = V_25 ;
F_28 ( V_29 , & V_14 ) ;
V_24 = NULL ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) )
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 || F_16 ( V_16 ) )
V_21 = 0 ;
if ( ! V_21 ) {
F_10 () ;
F_25 ( V_16 ) ;
if ( V_24 ) {
printf ( L_6 ,
V_29 , F_30 ( V_24 ) ) ;
F_31 ( V_16 -> V_31 , L_7 , L_8 ) ;
}
if ( F_16 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_13 () ;
}
V_38:
V_30 = 1 ;
while ( V_30 && ! V_37 ) {
if ( V_36 == 0 ) {
if ( V_21 )
goto V_45;
V_30 = F_32 ( 0 , & V_36 ) ;
}
F_33 () ;
}
if ( ! V_30 && ! V_37 ) {
int V_46 = F_34 () ;
V_40 = V_29 ;
F_35 () ;
if ( V_46 > 1 ) {
F_36 () ;
for ( V_12 = 100000000 ; V_12 != 0 ; -- V_12 ) {
if ( F_37 ( & V_14 ) >= V_46 )
break;
F_33 () ;
}
}
F_38 () ;
F_5 () ;
if ( V_24 || F_27 ( V_16 ) == 0xd00 )
F_39 ( V_16 -> V_31 , 1 , 0 ) ;
printf ( L_11 ) ;
F_35 () ;
V_37 = 1 ;
F_33 () ;
}
V_41:
while ( V_36 ) {
if ( V_30 ) {
if ( V_29 == V_40 ) {
if ( ! F_32 ( 0 , & V_39 ) ) {
V_30 = 0 ;
continue;
}
while ( V_29 == V_40 )
F_33 () ;
}
F_33 () ;
} else {
V_22 = F_40 ( V_16 ) ;
if ( V_22 != 0 ) {
F_41 () ;
V_37 = 0 ;
F_42 () ;
V_36 = 0 ;
break;
}
V_30 = 1 ;
}
}
V_45:
F_43 ( V_29 , & V_14 ) ;
V_35 [ V_29 ] = NULL ;
#else
if ( V_36 ) {
printf ( L_12 ,
V_16 -> V_34 , F_26 ( F_27 ( V_16 ) ) ) ;
longjmp ( V_35 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_25 ) == 0 ) {
V_35 [ 0 ] = V_25 ;
V_36 = 1 ;
F_25 ( V_16 ) ;
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 ) {
printf ( L_13 , F_30 ( V_24 ) ) ;
F_31 ( V_16 -> V_31 , L_7 , L_8 ) ;
}
if ( F_16 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_38 () ;
F_5 () ;
if ( V_24 || F_27 ( V_16 ) == 0xd00 )
F_39 ( V_16 -> V_31 , 1 , 0 ) ;
printf ( L_11 ) ;
}
V_22 = F_40 ( V_16 ) ;
F_41 () ;
V_36 = 0 ;
#endif
#ifdef F_44
if ( V_16 -> V_19 & V_47 ) {
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = ( unsigned long ) & V_24 -> V_48 [ 0 ] ;
F_45 ( & V_24 -> V_33 ) ;
}
}
#else
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) ) {
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 != NULL ) {
int V_49 = F_46 ( V_16 , V_24 -> V_48 [ 0 ] ) ;
if ( V_49 == 0 ) {
V_16 -> V_31 = ( unsigned long ) & V_24 -> V_48 [ 0 ] ;
F_45 ( & V_24 -> V_33 ) ;
} else if ( V_49 < 0 ) {
printf ( L_14 ,
( F_47 ( V_24 -> V_48 [ 0 ] ) ? L_15 : L_16 ) ) ;
}
}
}
#endif
F_48 () ;
F_49 ( V_28 ) ;
return V_22 != 'X' && V_22 != V_50 ;
}
int F_50 ( struct V_15 * V_51 )
{
struct V_15 V_16 ;
if ( V_51 == NULL ) {
F_51 ( & V_16 ) ;
V_51 = & V_16 ;
}
return F_18 ( V_51 , 0 ) ;
}
T_1 F_52 ( int V_52 , void * V_53 )
{
unsigned long V_28 ;
F_20 ( V_28 ) ;
printf ( L_17 ) ;
F_50 ( F_53 () ) ;
F_49 ( V_28 ) ;
return V_54 ;
}
static int F_54 ( struct V_15 * V_16 )
{
struct V_23 * V_24 ;
unsigned long V_27 ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
V_24 = F_21 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL && V_27 == 4 ) {
V_16 -> V_31 = V_24 -> V_32 + 4 ;
F_22 ( & V_24 -> V_33 ) ;
return 1 ;
}
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( ! V_24 )
return 0 ;
F_18 ( V_16 , 0 ) ;
return 1 ;
}
static int F_55 ( struct V_15 * V_16 )
{
if ( F_56 ( V_16 ) )
return 0 ;
F_18 ( V_16 , 0 ) ;
return 1 ;
}
static int F_57 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
if ( V_55 . V_56 == 0 )
return 0 ;
F_18 ( V_16 , 0 ) ;
return 1 ;
}
static int F_58 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
if ( V_57 == NULL )
return 0 ;
F_18 ( V_16 , 0 ) ;
return 1 ;
}
static int F_59 ( struct V_15 * V_16 )
{
#ifdef F_19
if ( V_36 && ! F_24 ( F_11 () , & V_14 ) )
F_18 ( V_16 , 1 ) ;
#endif
return 0 ;
}
static int F_60 ( struct V_15 * V_16 )
{
struct V_23 * V_24 ;
unsigned long V_27 ;
if ( V_36 && V_58 )
F_61 ( V_16 ) ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) ) {
V_24 = F_21 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = V_24 -> V_32 + V_27 ;
F_22 ( & V_24 -> V_33 ) ;
}
}
return 0 ;
}
static struct V_23 * F_29 ( unsigned long V_59 )
{
int V_60 ;
struct V_23 * V_24 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 )
if ( V_24 -> V_56 && V_59 == V_24 -> V_32 )
return V_24 ;
return NULL ;
}
static struct V_23 * F_21 ( unsigned long V_31 , unsigned long * V_63 )
{
unsigned long V_64 ;
V_64 = V_31 - ( unsigned long ) V_61 ;
if ( V_64 >= sizeof( V_61 ) )
return NULL ;
V_64 %= sizeof( struct V_23 ) ;
if ( V_64 != F_62 ( struct V_23 , V_48 [ 0 ] )
&& V_64 != F_62 ( struct V_23 , V_48 [ 1 ] ) )
return NULL ;
* V_63 = V_64 - F_62 ( struct V_23 , V_48 [ 0 ] ) ;
return (struct V_23 * ) ( V_31 - V_64 ) ;
}
static struct V_23 * F_63 ( unsigned long V_65 )
{
struct V_23 * V_24 ;
V_65 &= ~ 3UL ;
V_24 = F_29 ( V_65 ) ;
if ( V_24 )
return V_24 ;
for ( V_24 = V_61 ; V_24 < & V_61 [ V_62 ] ; ++ V_24 ) {
if ( ! V_24 -> V_56 && F_64 ( & V_24 -> V_33 ) == 0 ) {
V_24 -> V_32 = V_65 ;
V_24 -> V_48 [ 1 ] = V_66 ;
F_2 ( & V_24 -> V_48 [ 1 ] ) ;
return V_24 ;
}
}
printf ( L_18 ) ;
return NULL ;
}
static void F_41 ( void )
{
int V_60 ;
struct V_23 * V_24 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 ) {
if ( ( V_24 -> V_56 & ( V_67 | V_68 ) ) == 0 )
continue;
if ( F_65 ( V_24 -> V_32 , & V_24 -> V_48 [ 0 ] , 4 ) != 4 ) {
printf ( L_19
L_20 , V_24 -> V_32 ) ;
V_24 -> V_56 = 0 ;
continue;
}
if ( F_66 ( V_24 -> V_48 [ 0 ] ) || F_47 ( V_24 -> V_48 [ 0 ] ) ) {
printf ( L_21
L_22 , V_24 -> V_32 ) ;
V_24 -> V_56 = 0 ;
continue;
}
F_2 ( & V_24 -> V_48 [ 0 ] ) ;
if ( V_24 -> V_56 & V_68 )
continue;
if ( F_67 ( V_24 -> V_32 , & V_66 , 4 ) != 4 ) {
printf ( L_23
L_20 , V_24 -> V_32 ) ;
V_24 -> V_56 &= ~ V_67 ;
continue;
}
F_2 ( ( void * ) V_24 -> V_32 ) ;
}
}
static void F_48 ( void )
{
if ( V_55 . V_56 )
F_68 ( V_55 . V_32 | ( V_55 . V_56 & 7 ) , V_69 ) ;
if ( V_57 && F_69 ( V_70 ) )
F_70 ( V_71 , V_57 -> V_32
| ( V_57 -> V_56 & ( V_68 | V_72 ) ) ) ;
}
static void F_38 ( void )
{
int V_60 ;
struct V_23 * V_24 ;
unsigned V_48 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 ) {
if ( ( V_24 -> V_56 & ( V_67 | V_68 ) ) != V_67 )
continue;
if ( F_65 ( V_24 -> V_32 , & V_48 , 4 ) == 4
&& V_48 == V_66
&& F_67 ( V_24 -> V_32 , & V_24 -> V_48 , 4 ) != 4 )
printf ( L_24 ,
V_24 -> V_32 ) ;
else
F_2 ( ( void * ) V_24 -> V_32 ) ;
}
}
static void F_23 ( void )
{
F_68 ( 0 , 0 ) ;
if ( F_69 ( V_70 ) )
F_70 ( V_71 , 0 ) ;
}
static int
F_40 ( struct V_15 * V_51 )
{
int V_22 = 0 ;
V_73 = NULL ;
V_74 = V_51 ;
if ( ! V_75 ) {
V_75 = 1 ;
F_71 ( V_51 -> V_76 [ 1 ] , V_51 -> V_77 , V_51 -> V_31 ) ;
}
for(; ; ) {
#ifdef F_19
printf ( L_25 , F_11 () ) ;
#endif
printf ( L_26 ) ;
F_72 () ;
V_78 = 0 ;
V_22 = F_73 () ;
if( V_22 == '\n' ) {
if ( V_73 == NULL )
continue;
F_74 ( V_73 ) ;
V_73 = NULL ;
V_22 = F_75 () ;
}
switch ( V_22 ) {
case 'm' :
V_22 = F_75 () ;
switch ( V_22 ) {
case 'm' :
case 's' :
case 'd' :
F_76 ( V_22 ) ;
break;
case 'l' :
F_77 () ;
break;
case 'z' :
F_78 () ;
break;
case 'i' :
F_79 ( 0 ) ;
break;
default:
V_78 = V_22 ;
F_80 () ;
}
break;
case 'd' :
F_81 () ;
break;
case 'l' :
F_82 () ;
break;
case 'r' :
F_83 ( V_51 ) ;
break;
case 'e' :
F_25 ( V_51 ) ;
break;
case 'S' :
F_84 () ;
break;
case 't' :
F_85 ( V_51 ) ;
break;
case 'f' :
F_86 () ;
break;
case 's' :
if ( F_87 () == 0 )
break;
if ( F_88 ( V_51 ) )
return V_22 ;
break;
case 'x' :
case 'X' :
return V_22 ;
case V_50 :
printf ( L_27 ) ;
F_89 ( 2000 ) ;
return V_22 ;
case '?' :
F_90 ( V_79 ) ;
break;
case 'b' :
F_91 () ;
break;
case 'C' :
F_92 () ;
break;
case 'c' :
if ( F_93 () )
return 0 ;
break;
case 'z' :
F_94 () ;
break;
case 'p' :
F_95 () ;
break;
#ifdef F_96
case 'u' :
F_97 () ;
break;
#elif F_17 ( V_17 )
case 'u' :
F_98 () ;
break;
#elif F_17 ( V_18 )
case 'u' :
F_99 () ;
break;
#endif
default:
printf ( L_28 ) ;
do {
if ( ' ' < V_22 && V_22 <= '~' )
putchar ( V_22 ) ;
else
printf ( L_29 , V_22 ) ;
V_22 = F_75 () ;
} while ( V_22 != '\n' );
printf ( L_30 ) ;
break;
}
}
}
static int F_88 ( struct V_15 * V_16 )
{
V_16 -> V_19 |= V_47 ;
F_70 ( V_80 , F_100 ( V_80 ) | V_81 | V_82 ) ;
return 1 ;
}
static int F_88 ( struct V_15 * V_16 )
{
unsigned int V_48 ;
int V_49 ;
if ( ( V_16 -> V_19 & ( V_44 | V_43 | V_42 ) ) == ( V_44 | V_42 ) ) {
if ( F_65 ( V_16 -> V_31 , & V_48 , 4 ) == 4 ) {
V_49 = F_46 ( V_16 , V_48 ) ;
if ( V_49 < 0 ) {
printf ( L_14 ,
( F_47 ( V_48 ) ? L_15 : L_16 ) ) ;
return 0 ;
}
if ( V_49 > 0 ) {
V_16 -> V_34 = 0xd00 | ( V_16 -> V_34 & 1 ) ;
printf ( L_31 ) ;
F_31 ( V_16 -> V_31 , L_7 , L_32 ) ;
F_39 ( V_16 -> V_31 , 1 , 0 ) ;
return 0 ;
}
}
}
V_16 -> V_19 |= V_83 ;
return 1 ;
}
static void F_94 ( void )
{
int V_22 ;
V_22 = F_75 () ;
if ( V_22 == 'r' )
V_84 . V_85 ( NULL ) ;
else if ( V_22 == 'h' )
V_84 . V_86 () ;
else if ( V_22 == 'p' )
V_84 . V_87 () ;
}
static int F_93 ( void )
{
#ifdef F_19
unsigned long V_29 ;
int V_12 ;
int V_88 ;
if ( ! F_101 ( & V_29 ) ) {
printf ( L_33 ) ;
V_88 = 0 ;
F_102 (cpu) {
if ( F_24 ( V_29 , & V_14 ) ) {
if ( V_88 == 0 )
printf ( L_34 , V_29 ) ;
++ V_88 ;
} else {
if ( V_88 > 1 )
printf ( L_35 , V_29 - 1 ) ;
V_88 = 0 ;
}
}
if ( V_88 > 1 )
printf ( L_35 , V_89 - 1 ) ;
printf ( L_32 ) ;
return 0 ;
}
if ( ! F_24 ( V_29 , & V_14 ) ) {
printf ( L_36 , V_29 ) ;
return 0 ;
}
V_39 = 0 ;
F_35 () ;
V_40 = V_29 ;
V_12 = 10000000 ;
while ( ! V_39 ) {
if ( -- V_12 == 0 ) {
if ( F_32 ( 0 , & V_39 ) )
break;
F_35 () ;
V_40 = F_11 () ;
printf ( L_37 , V_29 ) ;
return 0 ;
}
F_33 () ;
}
return 1 ;
#else
return 0 ;
#endif
}
static void
F_92 ( void )
{
unsigned int V_60 ;
unsigned short V_90 ;
unsigned char V_91 ;
if ( ! F_101 ( & V_92 ) )
return;
if ( ! F_101 ( & V_93 ) )
return;
V_90 = 0xffff ;
for ( V_60 = 0 ; V_60 < V_93 ; ++ V_60 ) {
if ( F_65 ( V_92 + V_60 , & V_91 , 1 ) == 0 ) {
printf ( L_38 , V_92 + V_60 ) ;
break;
}
V_90 = F_103 ( V_90 , V_91 ) ;
}
printf ( L_39 , V_90 ) ;
}
static long F_104 ( unsigned long V_94 )
{
unsigned int V_48 ;
V_94 &= ~ 3 ;
if ( ! F_105 ( V_94 ) ) {
printf ( L_40 ) ;
return 0 ;
}
if ( ! F_65 ( V_94 , & V_48 , sizeof( V_48 ) ) ) {
printf ( L_41 , V_94 ) ;
return 0 ;
}
if ( F_66 ( V_48 ) || F_47 ( V_48 ) ) {
printf ( L_42
L_43 ) ;
return 0 ;
}
return 1 ;
}
static void
F_91 ( void )
{
int V_22 ;
unsigned long V_65 ;
int V_95 , V_60 ;
struct V_23 * V_24 ;
const char V_96 [] = L_44
L_45 ;
V_22 = F_75 () ;
switch ( V_22 ) {
#ifndef F_106
case 'd' :
V_95 = 7 ;
V_22 = F_75 () ;
if ( V_22 == 'r' )
V_95 = 5 ;
else if ( V_22 == 'w' )
V_95 = 6 ;
else
V_78 = V_22 ;
V_55 . V_32 = 0 ;
V_55 . V_56 = 0 ;
if ( F_101 ( & V_55 . V_32 ) ) {
if ( ! F_105 ( V_55 . V_32 ) ) {
printf ( V_96 ) ;
break;
}
V_55 . V_32 &= ~ 7 ;
V_55 . V_56 = V_95 | V_97 ;
}
break;
case 'i' :
if ( ! F_69 ( V_70 ) ) {
printf ( L_46
L_47 ) ;
break;
}
if ( V_57 ) {
V_57 -> V_56 &= ~ ( V_68 | V_72 ) ;
V_57 = NULL ;
}
if ( ! F_101 ( & V_65 ) )
break;
if ( ! F_104 ( V_65 ) )
break;
V_24 = F_63 ( V_65 ) ;
if ( V_24 != NULL ) {
V_24 -> V_56 |= V_68 | V_72 ;
V_57 = V_24 ;
}
break;
#endif
case 'c' :
if ( ! F_101 ( & V_65 ) ) {
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
V_24 = F_29 ( V_65 ) ;
if ( V_24 == NULL ) {
printf ( L_49 , V_65 ) ;
break;
}
}
printf ( L_50 , F_30 ( V_24 ) ) ;
F_31 ( V_24 -> V_32 , L_7 , L_8 ) ;
V_24 -> V_56 = 0 ;
break;
default:
V_78 = V_22 ;
V_22 = F_73 () ;
if ( V_22 == '?' ) {
printf ( V_98 ) ;
break;
}
V_78 = V_22 ;
if ( ! F_101 ( & V_65 ) ) {
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
printf ( L_57 , F_30 ( V_24 ) ,
( V_24 -> V_56 & V_68 ) ? L_58 : L_59 ) ;
F_31 ( V_24 -> V_32 , L_60 , L_32 ) ;
}
break;
}
if ( ! F_104 ( V_65 ) )
break;
V_24 = F_63 ( V_65 ) ;
if ( V_24 != NULL )
V_24 -> V_56 |= V_67 ;
break;
}
}
static
const char * F_26 ( unsigned long V_100 )
{
char * V_101 ;
switch ( V_100 ) {
case 0x100 : V_101 = L_61 ; break;
case 0x200 : V_101 = L_62 ; break;
case 0x300 : V_101 = L_63 ; break;
case 0x380 : V_101 = L_64 ; break;
case 0x400 : V_101 = L_65 ; break;
case 0x480 : V_101 = L_66 ; break;
case 0x500 : V_101 = L_67 ; break;
case 0x600 : V_101 = L_68 ; break;
case 0x700 : V_101 = L_69 ; break;
case 0x800 : V_101 = L_70 ; break;
case 0x900 : V_101 = L_71 ; break;
case 0xc00 : V_101 = L_72 ; break;
case 0xd00 : V_101 = L_73 ; break;
case 0xf00 : V_101 = L_74 ; break;
case 0xf20 : V_101 = L_75 ; break;
case 0x1300 : V_101 = L_76 ; break;
default: V_101 = L_77 ;
}
return V_101 ;
}
static void F_107 ( unsigned long V_59 , unsigned long * V_102 ,
unsigned long * V_103 )
{
unsigned long V_104 , V_27 ;
const char * V_105 ;
* V_102 = * V_103 = 0 ;
if ( V_59 == 0 )
return;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_105 = F_108 ( V_59 , & V_104 , & V_27 , NULL , V_107 ) ;
if ( V_105 != NULL ) {
* V_102 = V_59 - V_27 ;
* V_103 = V_59 - V_27 + V_104 ;
}
F_1 () ;
}
V_58 = 0 ;
}
static void F_71 ( unsigned long V_108 , unsigned long V_109 ,
unsigned long V_59 )
{
unsigned long V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
int V_88 = 0 ;
struct V_15 V_16 ;
do {
if ( V_108 < V_113 ) {
if ( V_108 != 0 )
printf ( L_78 , V_108 ) ;
break;
}
if ( ! F_65 ( V_108 + V_114 , & V_110 , sizeof( unsigned long ) )
|| ! F_65 ( V_108 , & V_111 , sizeof( unsigned long ) ) ) {
printf ( L_79 , V_108 ) ;
break;
}
if ( ( V_59 | V_109 ) != 0 ) {
unsigned long V_115 , V_116 ;
unsigned long V_117 ;
int V_118 = 1 ;
F_107 ( V_59 , & V_115 , & V_116 ) ;
V_117 = 0 ;
if ( V_111 > V_108 )
F_65 ( V_111 + V_114 , & V_117 ,
sizeof( unsigned long ) ) ;
if ( V_109 == V_110 ) {
if ( V_109 < V_113
|| ( V_115 <= V_109 && V_109 < V_116 ) )
V_118 = 0 ;
} else if ( V_109 == V_117 ) {
V_118 = 0 ;
} else if ( V_109 >= V_113
&& ! ( V_115 <= V_109 && V_109 < V_116 ) ) {
printf ( L_80 ) ;
F_31 ( V_109 , L_7 , L_32 ) ;
}
if ( V_118 ) {
printf ( L_81 V_99 L_82 , V_108 ) ;
F_31 ( V_110 , L_7 , L_83 ) ;
}
V_59 = V_109 = 0 ;
} else {
printf ( L_81 V_99 L_82 , V_108 ) ;
F_31 ( V_110 , L_7 , L_32 ) ;
}
if ( F_65 ( V_108 + V_119 , & V_112 , sizeof( unsigned long ) )
&& V_112 == V_120 ) {
if ( F_65 ( V_108 + V_121 , & V_16 , sizeof( V_16 ) )
!= sizeof( V_16 ) ) {
printf ( L_84 ,
V_108 + V_121 ) ;
break;
}
printf ( L_85 , V_16 . V_34 ,
F_26 ( F_27 ( & V_16 ) ) ) ;
V_59 = V_16 . V_31 ;
V_109 = V_16 . V_77 ;
F_31 ( V_59 , L_7 , L_32 ) ;
}
if ( V_111 == 0 )
break;
V_108 = V_111 ;
} while ( V_88 ++ < V_122 );
}
static void F_85 ( struct V_15 * V_51 )
{
unsigned long V_108 ;
if ( F_101 ( & V_108 ) )
F_71 ( V_108 , 0 , 0 ) ;
else
F_71 ( V_51 -> V_76 [ 1 ] , V_51 -> V_77 , V_51 -> V_31 ) ;
F_109 () ;
}
static void F_110 ( struct V_15 * V_16 )
{
#ifdef F_111
const struct V_123 * V_124 ;
unsigned long V_94 ;
if ( V_16 -> V_19 & V_43 )
return;
V_94 = V_16 -> V_31 ;
if ( V_94 < V_113 )
return;
V_124 = F_112 ( V_16 -> V_31 ) ;
if ( V_124 == NULL )
return;
if ( F_113 ( V_124 ) )
return;
#ifdef F_114
printf ( L_86 ,
V_124 -> V_125 , V_124 -> line ) ;
#else
printf ( L_87 , ( void * ) V_124 -> V_126 ) ;
#endif
#endif
}
static void F_25 ( struct V_15 * V_127 )
{
unsigned long V_34 ;
#ifdef F_19
printf ( L_88 , F_11 () ) ;
#endif
V_34 = F_27 ( V_127 ) ;
printf ( L_89 , V_127 -> V_34 , F_26 ( V_34 ) , V_127 ) ;
printf ( L_90 ) ;
F_31 ( V_127 -> V_31 , L_91 , L_32 ) ;
printf ( L_92 , V_127 -> V_77 ) ;
F_31 ( V_127 -> V_77 , L_91 , L_32 ) ;
printf ( L_93 , V_127 -> V_76 [ 1 ] ) ;
printf ( L_94 , V_127 -> V_19 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 ) {
printf ( L_95 , V_127 -> V_128 ) ;
if ( V_34 != 0x380 )
printf ( L_96 , V_127 -> V_129 ) ;
}
printf ( L_97 , V_130 ) ;
#ifdef F_115
printf ( L_98 ,
V_131 , V_131 -> V_132 , V_131 -> V_133 ) ;
#endif
if ( V_130 ) {
printf ( L_99 ,
V_130 -> V_134 , V_130 -> V_135 ) ;
}
if ( V_34 == 0x700 )
F_110 ( V_127 ) ;
}
static void F_83 ( struct V_15 * V_127 )
{
int V_136 , V_34 ;
unsigned long V_137 ;
struct V_15 V_16 ;
if ( F_101 ( & V_137 ) ) {
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_16 = * (struct V_15 * ) V_137 ;
F_1 () ;
F_116 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_100 V_99 L_32 ,
V_137 ) ;
return;
}
V_58 = 0 ;
V_127 = & V_16 ;
}
#ifdef F_115
if ( F_117 ( V_127 ) ) {
for ( V_136 = 0 ; V_136 < 16 ; ++ V_136 )
printf ( L_101 V_99 L_102 V_99 L_32 ,
V_136 , V_127 -> V_76 [ V_136 ] , V_136 + 16 , V_127 -> V_76 [ V_136 + 16 ] ) ;
} else {
for ( V_136 = 0 ; V_136 < 7 ; ++ V_136 )
printf ( L_101 V_99 L_102 V_99 L_32 ,
V_136 , V_127 -> V_76 [ V_136 ] , V_136 + 7 , V_127 -> V_76 [ V_136 + 7 ] ) ;
}
#else
for ( V_136 = 0 ; V_136 < 32 ; ++ V_136 ) {
printf ( L_103 , V_136 , V_127 -> V_76 [ V_136 ] ,
( V_136 & 3 ) == 3 ? L_32 : L_104 ) ;
if ( V_136 == 12 && ! F_117 ( V_127 ) ) {
printf ( L_32 ) ;
break;
}
}
#endif
printf ( L_105 ) ;
F_31 ( V_127 -> V_31 , L_7 , L_32 ) ;
if ( F_27 ( V_127 ) != 0xc00 && F_69 ( V_138 ) ) {
printf ( L_106 ) ;
F_31 ( V_127 -> V_139 , L_7 , L_32 ) ;
}
printf ( L_107 ) ;
F_31 ( V_127 -> V_77 , L_7 , L_32 ) ;
printf ( L_108 V_99 L_109 , V_127 -> V_19 , V_127 -> V_140 ) ;
printf ( L_110 V_99 L_111 V_99 L_112 ,
V_127 -> V_141 , V_127 -> V_142 , V_127 -> V_34 ) ;
V_34 = F_27 ( V_127 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 )
printf ( L_113 V_99 L_114 , V_127 -> V_128 , V_127 -> V_129 ) ;
}
static void F_86 ( void )
{
int V_22 ;
unsigned long V_143 ;
V_22 = F_75 () ;
if ( V_22 != 'i' )
V_78 = V_22 ;
F_101 ( ( void * ) & V_92 ) ;
if ( V_78 != '\n' )
V_78 = 0 ;
V_143 = 1 ;
F_101 ( & V_143 ) ;
V_143 = ( V_143 + V_144 - 1 ) / V_144 ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
if ( V_22 != 'i' ) {
for (; V_143 > 0 ; -- V_143 , V_92 += V_144 )
F_3 ( ( void * ) V_92 ) ;
} else {
for (; V_143 > 0 ; -- V_143 , V_92 += V_144 )
F_4 ( ( void * ) V_92 ) ;
}
F_1 () ;
F_116 ( 200 ) ;
}
V_58 = 0 ;
}
static unsigned long
F_118 ( int V_136 )
{
unsigned int V_145 [ 2 ] ;
unsigned long ( * V_146 ) ( void ) ;
unsigned long V_101 = - 1UL ;
#ifdef F_115
unsigned long V_147 [ 3 ] ;
V_147 [ 0 ] = ( unsigned long ) V_145 ;
V_147 [ 1 ] = 0 ;
V_147 [ 2 ] = 0 ;
V_146 = ( unsigned long ( * ) ( void ) ) V_147 ;
#else
V_146 = ( unsigned long ( * ) ( void ) ) V_145 ;
#endif
V_145 [ 0 ] = 0x7c6002a6 + ( ( V_136 & 0x1F ) << 16 ) + ( ( V_136 & 0x3e0 ) << 6 ) ;
V_145 [ 1 ] = 0x4e800020 ;
F_2 ( V_145 ) ;
F_2 ( V_145 + 1 ) ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_101 = V_146 () ;
F_1 () ;
F_116 ( 200 ) ;
V_136 = V_104 ;
}
return V_101 ;
}
static void
F_119 ( int V_136 , unsigned long V_148 )
{
unsigned int V_145 [ 2 ] ;
unsigned long ( * V_146 ) ( unsigned long ) ;
#ifdef F_115
unsigned long V_147 [ 3 ] ;
V_147 [ 0 ] = ( unsigned long ) V_145 ;
V_147 [ 1 ] = 0 ;
V_147 [ 2 ] = 0 ;
V_146 = ( unsigned long (*) ( unsigned long ) ) V_147 ;
#else
V_146 = ( unsigned long (*) ( unsigned long ) ) V_145 ;
#endif
V_145 [ 0 ] = 0x7c6003a6 + ( ( V_136 & 0x1F ) << 16 ) + ( ( V_136 & 0x3e0 ) << 6 ) ;
V_145 [ 1 ] = 0x4e800020 ;
F_2 ( V_145 ) ;
F_2 ( V_145 + 1 ) ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_146 ( V_148 ) ;
F_1 () ;
F_116 ( 200 ) ;
V_136 = V_104 ;
}
}
static void F_84 ( void )
{
int V_22 ;
unsigned long V_148 ;
V_22 = F_73 () ;
if ( V_22 == '\n' ) {
unsigned long V_108 , V_149 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_115 V_99 L_116 V_99 L_32 ,
F_120 () , F_100 ( V_150 ) ) ;
printf ( L_117 V_99 L_118 V_99 L_32 ,
F_100 ( V_151 ) , F_100 ( V_152 ) ) ;
printf ( L_119 V_99 L_120 V_99 L_32 ,
F_100 ( V_153 ) , F_100 ( V_154 ) ) ;
printf ( L_121 V_99 L_122 V_99 L_32 , V_108 , F_100 ( V_155 ) ) ;
printf ( L_123 V_99 L_124 V_99 L_32 , V_149 , F_100 ( V_156 ) ) ;
return;
}
F_101 ( & V_157 ) ;
switch ( V_22 ) {
case 'w' :
V_148 = F_118 ( V_157 ) ;
F_101 ( & V_148 ) ;
F_119 ( V_157 , V_148 ) ;
case 'r' :
printf ( L_125 , V_157 , F_118 ( V_157 ) ) ;
break;
}
F_109 () ;
}
static int
F_65 ( unsigned long V_92 , void * V_158 , int V_104 )
{
volatile int V_136 ;
char * V_1 , * V_159 ;
V_136 = 0 ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_92 ;
V_159 = ( char * ) V_158 ;
switch ( V_104 ) {
case 2 :
* ( V_160 * ) V_159 = * ( V_160 * ) V_1 ;
break;
case 4 :
* ( V_161 * ) V_159 = * ( V_161 * ) V_1 ;
break;
case 8 :
* ( V_162 * ) V_159 = * ( V_162 * ) V_1 ;
break;
default:
for( ; V_136 < V_104 ; ++ V_136 ) {
* V_159 ++ = * V_1 ++ ;
F_1 () ;
}
}
F_1 () ;
F_116 ( 200 ) ;
V_136 = V_104 ;
}
V_58 = 0 ;
return V_136 ;
}
static int
F_67 ( unsigned long V_92 , void * V_158 , int V_104 )
{
volatile int V_136 ;
char * V_1 , * V_159 ;
V_136 = 0 ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_92 ;
V_159 = ( char * ) V_158 ;
switch ( V_104 ) {
case 2 :
* ( V_160 * ) V_1 = * ( V_160 * ) V_159 ;
break;
case 4 :
* ( V_161 * ) V_1 = * ( V_161 * ) V_159 ;
break;
case 8 :
* ( V_162 * ) V_1 = * ( V_162 * ) V_159 ;
break;
default:
for ( ; V_136 < V_104 ; ++ V_136 ) {
* V_1 ++ = * V_159 ++ ;
F_1 () ;
}
}
F_1 () ;
F_116 ( 200 ) ;
V_136 = V_104 ;
} else {
printf ( L_126 , V_92 + V_136 ) ;
}
V_58 = 0 ;
return V_136 ;
}
static int F_61 ( struct V_15 * V_16 )
{
V_163 = F_27 ( V_16 ) ;
switch ( F_27 ( V_16 ) ) {
case 0x200 :
V_164 = 0 ;
break;
case 0x300 :
case 0x380 :
V_164 = 1 ;
break;
default:
V_164 = 2 ;
}
longjmp ( V_106 , 1 ) ;
return 0 ;
}
static void
F_121 ( unsigned char * V_148 , int V_104 )
{
int V_165 ;
switch ( V_104 ) {
case 2 :
F_122 ( V_148 [ 0 ] , V_148 [ 1 ] , V_165 ) ;
break;
case 4 :
F_122 ( V_148 [ 0 ] , V_148 [ 3 ] , V_165 ) ;
F_122 ( V_148 [ 1 ] , V_148 [ 2 ] , V_165 ) ;
break;
case 8 :
F_122 ( V_148 [ 0 ] , V_148 [ 7 ] , V_165 ) ;
F_122 ( V_148 [ 1 ] , V_148 [ 6 ] , V_165 ) ;
F_122 ( V_148 [ 2 ] , V_148 [ 5 ] , V_165 ) ;
F_122 ( V_148 [ 3 ] , V_148 [ 4 ] , V_165 ) ;
break;
}
}
static void
F_80 ( void )
{
int V_22 , V_166 , V_60 , V_167 ;
unsigned long V_136 ;
unsigned char V_148 [ 16 ] ;
F_101 ( ( void * ) & V_92 ) ;
V_22 = F_73 () ;
if ( V_22 == '?' ) {
printf ( V_168 ) ;
return;
} else {
V_78 = V_22 ;
}
V_73 = L_127 ;
while ( ( V_22 = F_73 () ) != '\n' ) {
switch( V_22 ) {
case 'b' : V_104 = 1 ; break;
case 'w' : V_104 = 2 ; break;
case 'l' : V_104 = 4 ; break;
case 'd' : V_104 = 8 ; break;
case 'r' : V_169 = ! V_169 ; break;
case 'n' : V_170 = 1 ; break;
case '.' : V_170 = 0 ; break;
}
}
if( V_104 <= 0 )
V_104 = 1 ;
else if( V_104 > 8 )
V_104 = 8 ;
for(; ; ) {
if ( ! V_170 )
V_136 = F_65 ( V_92 , V_148 , V_104 ) ;
printf ( V_99 L_128 , V_92 , V_169 ? 'r' : ' ' ) ;
if ( ! V_170 ) {
if ( V_169 )
F_121 ( V_148 , V_104 ) ;
putchar ( ' ' ) ;
for ( V_60 = 0 ; V_60 < V_136 ; ++ V_60 )
printf ( L_129 , V_148 [ V_60 ] ) ;
for (; V_60 < V_104 ; ++ V_60 )
printf ( L_130 , V_171 [ V_164 ] ) ;
}
putchar ( ' ' ) ;
V_166 = V_104 ;
V_167 = 0 ;
for(; ; ) {
if( F_101 ( & V_136 ) ) {
for ( V_60 = 0 ; V_60 < V_104 ; ++ V_60 )
V_148 [ V_60 ] = V_136 >> ( V_60 * 8 ) ;
if ( ! V_169 )
F_121 ( V_148 , V_104 ) ;
F_67 ( V_92 , V_148 , V_104 ) ;
V_166 = V_104 ;
}
V_22 = F_73 () ;
if ( V_22 == '\n' )
break;
V_166 = 0 ;
switch ( V_22 ) {
case '\'' :
for(; ; ) {
V_136 = F_75 () ;
if( V_136 == '\\' )
V_136 = F_123 () ;
else if( V_136 == '\'' )
break;
for ( V_60 = 0 ; V_60 < V_104 ; ++ V_60 )
V_148 [ V_60 ] = V_136 >> ( V_60 * 8 ) ;
if ( ! V_169 )
F_121 ( V_148 , V_104 ) ;
F_67 ( V_92 , V_148 , V_104 ) ;
V_92 += V_104 ;
}
V_92 -= V_104 ;
V_166 = V_104 ;
break;
case ',' :
V_92 += V_104 ;
break;
case '.' :
V_170 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_50 :
F_109 () ;
return;
case 'b' :
case 'v' :
V_104 = 1 ;
break;
case 'w' :
V_104 = 2 ;
break;
case 'l' :
V_104 = 4 ;
break;
case 'u' :
V_104 = 8 ;
break;
case '^' :
V_92 -= V_104 ;
break;
break;
case '/' :
if ( V_167 > 0 )
V_92 -= 1 << V_167 ;
else
V_167 = 0 ;
V_167 += 4 ;
V_92 += 1 << V_167 ;
break;
case '\\' :
if ( V_167 < 0 )
V_92 += 1 << - V_167 ;
else
V_167 = 0 ;
V_167 -= 4 ;
V_92 -= 1 << - V_167 ;
break;
case 'm' :
F_101 ( ( void * ) & V_92 ) ;
break;
case 'n' :
V_170 = 1 ;
break;
case 'r' :
V_169 = ! V_169 ;
break;
case '<' :
V_136 = V_104 ;
F_101 ( & V_136 ) ;
V_92 -= V_136 ;
break;
case '>' :
V_136 = V_104 ;
F_101 ( & V_136 ) ;
V_92 += V_136 ;
break;
case '?' :
printf ( V_172 ) ;
break;
}
}
V_92 += V_166 ;
}
}
static int
F_123 ( void )
{
int V_173 ;
V_173 = F_75 () ;
switch( V_173 ) {
case 'n' : V_173 = '\n' ; break;
case 'r' : V_173 = '\r' ; break;
case 'b' : V_173 = '\b' ; break;
case 't' : V_173 = '\t' ; break;
}
return V_173 ;
}
static void F_124 ( unsigned long V_92 , long V_174 )
{
long V_136 , V_175 , V_176 , V_177 ;
unsigned char V_178 [ 16 ] ;
for ( V_136 = V_174 ; V_136 > 0 ; ) {
V_176 = V_136 < 16 ? V_136 : 16 ;
V_177 = F_65 ( V_92 , V_178 , V_176 ) ;
V_92 += V_177 ;
for ( V_175 = 0 ; V_175 < V_176 ; ++ V_175 ) {
if ( V_175 < V_177 )
printf ( L_129 , V_178 [ V_175 ] ) ;
else
printf ( L_130 , V_171 [ V_164 ] ) ;
}
V_136 -= V_176 ;
if ( V_177 < V_176 )
break;
}
printf ( L_32 ) ;
}
static void F_125 ( int V_29 )
{
struct V_179 * V_1 ;
if ( setjmp ( V_106 ) != 0 ) {
printf ( L_131 , V_29 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
V_1 = & V_180 [ V_29 ] ;
printf ( L_132 , V_29 , V_1 ) ;
printf ( L_133 , 16 , L_134 , F_126 ( V_29 ) ? L_135 : L_136 ) ;
printf ( L_133 , 16 , L_137 , F_127 ( V_29 ) ? L_135 : L_136 ) ;
printf ( L_133 , 16 , L_138 , F_128 ( V_29 ) ? L_135 : L_136 ) ;
#define F_129 ( V_180 , V_105 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 16, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_129 ( V_1 , V_181 , L_139 ) ;
F_129 ( V_1 , V_182 , L_139 ) ;
F_129 ( V_1 , V_183 , L_140 ) ;
F_129 ( V_1 , V_184 , L_140 ) ;
F_129 ( V_1 , V_185 , L_140 ) ;
#ifdef F_130
F_129 ( V_1 , V_186 , L_140 ) ;
F_129 ( V_1 , V_187 , L_140 ) ;
#endif
F_129 ( V_1 , V_188 , L_141 ) ;
F_129 ( V_1 , V_189 , L_140 ) ;
F_129 ( V_1 , V_190 , L_139 ) ;
F_129 ( V_1 , V_191 , L_139 ) ;
F_129 ( V_1 , V_192 , L_139 ) ;
F_129 ( V_1 , V_193 , L_141 ) ;
F_129 ( V_1 , V_194 , L_140 ) ;
F_129 ( V_1 , V_195 , L_140 ) ;
F_129 ( V_1 , V_196 , L_140 ) ;
F_129 ( V_1 , V_197 , L_139 ) ;
F_129 ( V_1 , V_132 , L_139 ) ;
F_129 ( V_1 , V_133 , L_139 ) ;
F_129 ( V_1 , V_198 , L_139 ) ;
F_129 ( V_1 , V_199 , L_139 ) ;
F_129 ( V_1 , V_200 , L_139 ) ;
#undef F_129
V_58 = 0 ;
F_1 () ;
}
static void F_131 ( void )
{
int V_29 ;
if ( F_132 () == 0 ) {
printf ( L_142 ) ;
return;
}
F_102 (cpu)
F_125 ( V_29 ) ;
}
static void F_133 ( void )
{
unsigned long V_201 ;
int V_173 ;
V_173 = F_75 () ;
if ( V_173 == 'a' ) {
F_131 () ;
return;
}
V_78 = V_173 ;
if ( F_101 ( & V_201 ) )
F_125 ( V_201 ) ;
else
F_125 ( V_40 ) ;
}
static void
F_81 ( void )
{
int V_173 ;
V_173 = F_75 () ;
#ifdef F_115
if ( V_173 == 'p' ) {
F_133 () ;
return;
}
#endif
if ( ( isxdigit ( V_173 ) && V_173 != 'f' && V_173 != 'd' ) || V_173 == '\n' )
V_78 = V_173 ;
F_101 ( ( void * ) & V_92 ) ;
if ( V_78 != '\n' )
V_78 = 0 ;
if ( V_173 == 'i' ) {
F_101 ( & V_202 ) ;
if ( V_202 == 0 )
V_202 = 16 ;
else if ( V_202 > V_203 )
V_202 = V_203 ;
V_92 += F_39 ( V_92 , V_202 , 1 ) ;
V_73 = L_143 ;
} else if ( V_173 == 'l' ) {
F_134 () ;
} else if ( V_173 == 'r' ) {
F_101 ( & V_174 ) ;
if ( V_174 == 0 )
V_174 = 64 ;
F_124 ( V_92 , V_174 ) ;
V_92 += V_174 ;
V_73 = L_144 ;
} else {
F_101 ( & V_174 ) ;
if ( V_174 == 0 )
V_174 = 64 ;
else if ( V_174 > V_203 )
V_174 = V_203 ;
F_135 ( V_92 , V_174 ) ;
V_92 += V_174 ;
V_73 = L_145 ;
}
}
static void
F_135 ( unsigned long V_92 , long V_174 )
{
long V_136 , V_175 , V_173 , V_176 , V_177 ;
unsigned char V_178 [ 16 ] ;
for ( V_136 = V_174 ; V_136 > 0 ; ) {
printf ( V_99 , V_92 ) ;
putchar ( ' ' ) ;
V_176 = V_136 < 16 ? V_136 : 16 ;
V_177 = F_65 ( V_92 , V_178 , V_176 ) ;
V_92 += V_177 ;
for ( V_175 = 0 ; V_175 < V_176 ; ++ V_175 ) {
if ( ( V_175 & ( sizeof( long ) - 1 ) ) == 0 && V_175 > 0 )
putchar ( ' ' ) ;
if ( V_175 < V_177 )
printf ( L_129 , V_178 [ V_175 ] ) ;
else
printf ( L_130 , V_171 [ V_164 ] ) ;
}
for (; V_175 < 16 ; ++ V_175 ) {
if ( ( V_175 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_60 ) ;
}
printf ( L_146 ) ;
for ( V_175 = 0 ; V_175 < V_176 ; ++ V_175 ) {
if ( V_175 < V_177 ) {
V_173 = V_178 [ V_175 ] ;
putchar ( ' ' <= V_173 && V_173 <= '~' ? V_173 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_136 -= V_176 ;
for (; V_175 < 16 ; ++ V_175 )
putchar ( ' ' ) ;
printf ( L_147 ) ;
if ( V_177 < V_176 )
break;
}
}
static int
F_136 ( unsigned long V_204 , long V_88 , int V_205 ,
T_3 V_206 )
{
int V_177 , V_207 ;
unsigned long V_208 ;
unsigned long V_209 , V_210 = 0 ;
unsigned char V_148 [ 4 ] ;
V_207 = 0 ;
for ( V_208 = V_204 ; V_88 > 0 ; -- V_88 , V_204 += 4 ) {
V_177 = F_65 ( V_204 , V_148 , 4 ) ;
if ( V_177 == 0 ) {
if ( V_205 ) {
const char * V_211 = V_171 [ V_164 ] ;
printf ( V_99 L_148 , V_204 , V_211 , V_211 , V_211 , V_211 ) ;
}
break;
}
V_209 = F_137 ( V_148 ) ;
if ( V_204 > V_208 && V_209 == V_210 ) {
if ( ! V_207 ) {
printf ( L_149 ) ;
V_207 = 1 ;
}
continue;
}
V_207 = 0 ;
V_210 = V_209 ;
if ( V_205 )
printf ( V_99 L_150 , V_204 , V_209 ) ;
printf ( L_151 ) ;
V_206 ( V_209 , V_204 ) ;
printf ( L_32 ) ;
}
return V_204 - V_208 ;
}
static int
F_39 ( unsigned long V_204 , long V_88 , int V_205 )
{
return F_136 ( V_204 , V_88 , V_205 , V_212 ) ;
}
void
F_138 ( unsigned long V_94 )
{
F_31 ( V_94 , L_152 , L_77 ) ;
}
void
F_134 ( void )
{
struct V_213 V_214 = { . V_215 = 1 } ;
unsigned char V_158 [ 128 ] ;
T_4 V_216 ;
if ( setjmp ( V_106 ) != 0 ) {
printf ( L_153 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
F_139 ( & V_214 ) ;
while ( F_140 ( & V_214 , false , V_158 , sizeof( V_158 ) , & V_216 ) ) {
V_158 [ V_216 ] = '\0' ;
printf ( L_130 , V_158 ) ;
}
F_1 () ;
F_116 ( 200 ) ;
V_58 = 0 ;
}
static void
F_76 ( int V_22 )
{
F_101 ( ( void * ) & V_217 ) ;
if( V_78 != '\n' )
V_78 = 0 ;
F_101 ( ( void * ) ( V_22 == 's' ? & V_218 : & V_219 ) ) ;
if( V_78 != '\n' )
V_78 = 0 ;
F_101 ( ( void * ) & V_220 ) ;
switch( V_22 ) {
case 'm' :
memmove ( ( void * ) V_217 , ( void * ) V_219 , V_220 ) ;
break;
case 's' :
memset ( ( void * ) V_217 , V_218 , V_220 ) ;
break;
case 'd' :
if( V_78 != '\n' )
V_78 = 0 ;
F_101 ( ( void * ) & V_221 ) ;
F_141 ( ( unsigned char * ) V_217 , ( unsigned char * ) V_219 , V_220 , V_221 ) ;
break;
}
}
static void
F_141 ( unsigned char * V_222 , unsigned char * V_223 , unsigned V_224 , unsigned V_225 )
{
unsigned V_136 , V_226 ;
V_226 = 0 ;
for( V_136 = V_224 ; V_136 > 0 ; -- V_136 )
if( * V_222 ++ != * V_223 ++ )
if( ++ V_226 <= V_225 )
printf ( L_154 , V_222 - 1 ,
V_222 [ - 1 ] , V_223 - 1 , V_223 [ - 1 ] ) ;
if( V_226 > V_225 )
printf ( L_155 , V_226 ) ;
}
static void
F_77 ( void )
{
unsigned V_65 , V_136 ;
unsigned char V_148 [ 4 ] ;
V_73 = L_156 ;
F_101 ( ( void * ) & V_217 ) ;
if ( V_78 != '\n' ) {
V_78 = 0 ;
F_101 ( ( void * ) & V_227 ) ;
if ( V_78 != '\n' ) {
V_78 = 0 ;
F_101 ( ( void * ) & V_218 ) ;
V_228 = ~ 0 ;
if ( V_78 != '\n' ) V_78 = 0 ;
F_101 ( ( void * ) & V_228 ) ;
}
}
V_136 = 0 ;
for ( V_65 = V_217 ; V_65 < V_227 ; V_65 += 4 ) {
if ( F_65 ( V_65 , V_148 , 4 ) == 4
&& ( ( F_137 ( V_148 ) ^ V_218 ) & V_228 ) == 0 ) {
printf ( L_157 , V_65 , F_137 ( V_148 ) ) ;
if ( ++ V_136 >= 10 )
break;
}
}
}
static void
F_78 ( void )
{
unsigned char V_91 ;
unsigned V_65 ;
int V_229 , V_230 ;
F_101 ( & V_217 ) ;
if ( V_78 != '\n' ) V_78 = 0 ;
F_101 ( & V_231 ) ;
if ( V_78 != '\n' ) V_78 = 0 ;
F_101 ( & V_232 ) ;
V_230 = 0 ;
for ( V_65 = V_217 ; V_65 < V_232 ; V_65 += V_231 ) {
V_229 = F_65 ( V_65 , & V_91 , 1 ) ;
if ( V_229 && ! V_230 ) {
printf ( L_158 , V_65 ) ;
} else if ( ! V_229 && V_230 )
printf ( L_159 , V_65 - V_231 ) ;
V_230 = V_229 ;
if ( V_65 + V_231 < V_65 )
break;
}
if ( V_230 )
printf ( L_159 , V_65 - V_231 ) ;
}
static void F_95 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_101 ;
int V_60 ;
typedef unsigned long (* T_5)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_5 V_233 ;
if ( ! F_101 ( & V_92 ) )
return;
if ( V_78 != '\n' )
V_78 = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 )
args [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 ) {
if ( ! F_101 ( & args [ V_60 ] ) || V_78 == '\n' )
break;
V_78 = 0 ;
}
V_233 = ( T_5 ) V_92 ;
V_101 = 0 ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_101 = V_233 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_1 () ;
printf ( L_160 , V_101 ) ;
} else {
printf ( L_161 , V_163 ) ;
}
V_58 = 0 ;
}
int
F_73 ( void )
{
int V_173 ;
if( V_78 != 0 ) {
V_173 = V_78 ;
V_78 = 0 ;
} else
V_173 = F_75 () ;
while( V_173 == ' ' || V_173 == '\t' )
V_173 = F_75 () ;
return V_173 ;
}
int
F_101 ( unsigned long * V_234 )
{
int V_173 , V_53 ;
unsigned long V_91 ;
V_173 = F_73 () ;
if ( V_173 == '%' ) {
char V_235 [ 8 ] ;
int V_60 ;
for ( V_60 = 0 ; V_60 < sizeof( V_235 ) - 1 ; ++ V_60 ) {
V_173 = F_75 () ;
if ( ! isalnum ( V_173 ) ) {
V_78 = V_173 ;
break;
}
V_235 [ V_60 ] = V_173 ;
}
V_235 [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < V_236 ; ++ V_60 ) {
if ( strcmp ( V_237 [ V_60 ] , V_235 ) == 0 ) {
if ( V_74 == NULL ) {
printf ( L_162 ) ;
return 0 ;
}
* V_234 = ( ( unsigned long * ) V_74 ) [ V_60 ] ;
return 1 ;
}
}
printf ( L_163 , V_235 ) ;
return 0 ;
}
if ( V_173 == '0' ) {
V_173 = F_75 () ;
if ( V_173 == 'x' ) {
V_173 = F_75 () ;
} else {
V_53 = F_142 ( V_173 ) ;
if ( V_53 == V_50 ) {
V_78 = V_173 ;
* V_234 = 0 ;
return 1 ;
}
}
} else if ( V_173 == '$' ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 63 ; V_60 ++ ) {
V_173 = F_75 () ;
if ( isspace ( V_173 ) ) {
V_78 = V_173 ;
break;
}
V_107 [ V_60 ] = V_173 ;
}
V_107 [ V_60 ++ ] = 0 ;
* V_234 = 0 ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
* V_234 = F_143 ( V_107 ) ;
F_1 () ;
}
V_58 = 0 ;
if ( ! ( * V_234 ) ) {
printf ( L_164 , V_107 ) ;
return 0 ;
}
return 1 ;
}
V_53 = F_142 ( V_173 ) ;
if ( V_53 == V_50 ) {
V_78 = V_173 ;
return 0 ;
}
V_91 = 0 ;
do {
V_91 = ( V_91 << 4 ) + V_53 ;
V_173 = F_75 () ;
V_53 = F_142 ( V_173 ) ;
} while ( V_53 != V_50 );
V_78 = V_173 ;
* V_234 = V_91 ;
return 1 ;
}
static void
F_109 ( void )
{
int V_173 ;
V_173 = V_78 ;
V_78 = 0 ;
while( V_173 != '\n' )
V_173 = F_75 () ;
}
static int F_142 ( int V_173 )
{
if( '0' <= V_173 && V_173 <= '9' )
return V_173 - '0' ;
if( 'A' <= V_173 && V_173 <= 'F' )
return V_173 - ( 'A' - 10 ) ;
if( 'a' <= V_173 && V_173 <= 'f' )
return V_173 - ( 'a' - 10 ) ;
return V_50 ;
}
void
F_144 ( char * V_238 , int V_104 )
{
int V_173 ;
V_173 = F_73 () ;
do {
if( V_104 > 1 ) {
* V_238 ++ = V_173 ;
-- V_104 ;
}
V_173 = F_75 () ;
} while( V_173 != ' ' && V_173 != '\t' && V_173 != '\n' );
V_78 = V_173 ;
* V_238 = 0 ;
}
static void
F_72 ( void )
{
V_239 = NULL ;
}
static int
F_75 ( void )
{
if ( V_239 == NULL || * V_239 == 0 ) {
if ( F_145 ( line , sizeof( line ) ) == NULL ) {
V_239 = NULL ;
return V_50 ;
}
V_239 = line ;
}
return * V_239 ++ ;
}
static void
F_74 ( char * V_240 )
{
V_239 = V_240 ;
}
static void
F_82 ( void )
{
int type = F_75 () ;
unsigned long V_94 ;
static char V_241 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_101 ( & V_94 ) )
F_31 ( V_94 , L_91 , L_32 ) ;
V_78 = 0 ;
break;
case 's' :
F_144 ( V_241 , 64 ) ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_94 = F_143 ( V_241 ) ;
if ( V_94 )
printf ( L_165 , V_241 , V_94 ) ;
else
printf ( L_166 , V_241 ) ;
F_1 () ;
}
V_58 = 0 ;
V_78 = 0 ;
break;
}
}
static void F_31 ( unsigned long V_32 , const char * V_242 ,
const char * V_243 )
{
char * V_244 ;
const char * V_105 = NULL ;
unsigned long V_27 , V_104 ;
printf ( V_99 , V_32 ) ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_105 = F_108 ( V_32 , & V_104 , & V_27 , & V_244 ,
V_107 ) ;
F_1 () ;
F_116 ( 200 ) ;
}
V_58 = 0 ;
if ( V_105 ) {
printf ( L_167 , V_242 , V_105 , V_27 , V_104 ) ;
if ( V_244 )
printf ( L_168 , V_244 ) ;
}
printf ( L_130 , V_243 ) ;
}
static void F_146 ( void )
{
int V_60 ;
unsigned long V_245 , V_246 , V_247 ;
unsigned long V_248 ;
printf ( L_169 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_249 ; V_60 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
V_247 = ( V_245 & V_250 ) ;
if ( V_247 | V_245 | V_246 ) {
printf ( L_170 , V_60 , V_245 , V_246 ) ;
if ( V_247 ) {
V_248 = V_246 & V_251 ;
if ( V_246 & V_252 ) {
printf ( L_171 ,
F_147 ( V_245 ) ,
( V_246 & ~ V_253 ) >> V_254 ,
V_248 ) ;
} else {
printf ( L_172 ,
F_148 ( V_245 ) ,
( V_246 & ~ V_253 ) >> V_255 ,
V_248 ) ;
}
} else
printf ( L_32 ) ;
}
}
}
static void F_149 ( void )
{
int V_60 ;
unsigned long * V_241 = ( unsigned long * ) V_131 -> V_187 ;
printf ( L_173 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_256 / 16 ; V_60 ++ ) {
unsigned long V_65 , V_257 ;
V_65 = * V_241 ++ ;
V_257 = * V_241 ++ ;
if ( V_65 || V_257 ) {
printf ( L_174 , V_60 , V_65 ) ;
printf ( L_175 , V_257 ) ;
}
}
}
void F_97 ( void )
{
if ( F_150 ( V_258 ) )
F_146 () ;
else
F_149 () ;
}
void F_97 ( void )
{
int V_60 ;
printf ( L_176 ) ;
for ( V_60 = 0 ; V_60 < 16 ; ++ V_60 )
printf ( L_34 , F_151 ( V_60 ) ) ;
printf ( L_32 ) ;
}
static void F_98 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_259 ; V_60 ++ ) {
unsigned long V_260 , V_261 , V_262 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_177 , V_60 , V_260 , V_261 , V_262 ) ;
if ( V_260 & V_263 ) {
printf ( L_178 ,
V_260 & V_264 ,
V_261 & V_265 ,
V_261 & V_266 ,
( V_262 & V_267 ) ? 'W' : 'w' ,
( V_262 & V_268 ) ? 'I' : 'i' ,
( V_262 & V_269 ) ? 'M' : 'm' ,
( V_262 & V_270 ) ? 'G' : 'g' ,
( V_262 & V_271 ) ? 'E' : 'e' ) ;
}
printf ( L_32 ) ;
}
}
static void F_99 ( void )
{
V_161 V_272 , V_273 , V_274 ;
V_162 V_275 ;
int V_60 , V_276 , V_277 , V_278 , V_279 , V_280 , V_281 = 0 ;
int V_282 ;
static const char * V_283 [] = {
L_179 ,
L_180 ,
L_181 ,
L_182 ,
L_183 ,
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
} ;
V_272 = F_100 ( V_284 ) ;
V_282 = ( V_272 & 3 ) + 1 ;
V_277 = ( ( V_272 >> 2 ) & 3 ) + 1 ;
V_278 = ( ( V_272 >> 6 ) & 0x1f ) + 1 ;
V_279 = ( V_272 >> 24 ) & 0xf ;
V_280 = ( V_272 >> 16 ) & 0x7f ;
if ( ( V_282 > 1 ) && ( V_272 & 0x10000 ) )
V_281 = 1 ;
printf ( L_211 ,
V_282 , V_277 , V_278 , V_279 , V_280 ) ;
V_273 = ( 1ul << V_278 ) - 1 ;
V_274 = ( 1ul << V_279 ) - 1 ;
V_275 = ( 1ull << V_280 ) - 1 ;
for ( V_276 = 0 ; V_276 < V_277 ; V_276 ++ ) {
V_161 V_285 ;
int V_286 , V_287 , V_288 = 1 ;
printf ( L_212 , V_276 ) ;
switch( V_276 ) {
case 0 :
V_285 = F_100 ( V_289 ) ;
break;
case 1 :
V_285 = F_100 ( V_290 ) ;
break;
case 2 :
V_285 = F_100 ( V_291 ) ;
break;
case 3 :
V_285 = F_100 ( V_292 ) ;
break;
default:
printf ( L_213 ) ;
continue;
}
V_286 = V_285 & 0xfff ;
V_287 = ( V_285 >> 24 ) & 0xff ;
for ( V_60 = 0 ; V_60 < V_286 ; V_60 ++ ) {
V_161 V_293 = F_152 ( V_276 ) ;
V_161 V_294 = F_153 ( V_295 ) ;
V_162 V_296 = 0 ;
V_162 V_297 ;
int V_298 = V_60 , V_299 = V_60 ;
if ( V_287 != 0 ) {
V_299 = V_60 / V_287 ;
V_298 = V_60 % V_287 ;
V_296 = V_299 * 0x1000 ;
}
V_293 |= F_154 ( V_298 ) ;
F_70 ( V_300 , V_293 ) ;
F_70 ( V_301 , V_294 ) ;
F_70 ( V_302 , V_296 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_294 = F_100 ( V_301 ) ;
V_296 = F_100 ( V_302 ) ;
V_297 = F_100 ( V_303 ) ;
if ( V_287 && ( V_60 % V_287 ) == 0 )
V_288 = 1 ;
if ( ! ( V_294 & V_304 ) )
continue;
if ( V_287 == 0 )
printf ( L_214 , V_60 ) ;
else if ( V_288 )
printf ( L_215 , V_299 , 'A' + V_298 ) ;
else
printf ( L_216 , 'A' + V_298 ) ;
V_288 = 0 ;
printf ( L_217 ,
V_296 & ~ 0x3ffull ,
( V_294 >> 16 ) & 0x3fff ,
V_283 [ ( V_294 >> 7 ) & 0x1f ] ,
V_294 & V_305 ? 'I' : ' ' ,
V_294 & V_306 ? 'P' : ' ' ,
V_294 & V_307 ? '1' : '0' ) ;
printf ( L_218 ,
V_296 & V_308 ? 'a' : ' ' ,
V_296 & V_309 ? 'v' : ' ' ,
V_296 & V_310 ? 'w' : ' ' ,
V_296 & V_311 ? 'i' : ' ' ,
V_296 & V_312 ? 'm' : ' ' ,
V_296 & V_313 ? 'g' : ' ' ,
V_296 & V_314 ? 'e' : ' ' ) ;
printf ( L_219 , V_297 & V_275 & ~ 0x7ffull ) ;
if ( V_294 & V_305 )
printf ( L_220 ,
V_283 [ ( V_297 >> 1 ) & 0x1f ] ) ;
else
printf ( L_221 ,
V_297 & V_315 ? 'x' : ' ' ,
V_297 & V_316 ? 'w' : ' ' ,
V_297 & V_317 ? 'r' : ' ' ,
V_297 & V_318 ? 'x' : ' ' ,
V_297 & V_319 ? 'w' : ' ' ,
V_297 & V_320 ? 'r' : ' ' ) ;
}
}
}
static void F_155 ( int V_321 )
{
if ( V_321 ) {
V_322 = F_50 ;
V_323 = F_59 ;
V_324 = F_54 ;
V_325 = F_55 ;
V_326 = F_58 ;
V_327 = F_57 ;
V_328 = F_60 ;
} else {
V_322 = NULL ;
V_323 = NULL ;
V_324 = NULL ;
V_325 = NULL ;
V_326 = NULL ;
V_327 = NULL ;
V_328 = NULL ;
}
F_156 () ;
}
static void F_157 ( int V_329 )
{
F_155 ( 1 ) ;
F_158 ( F_53 () ) ;
}
static int T_6 F_159 ( void )
{
F_160 ( 'x' , & V_330 ) ;
return 0 ;
}
static int T_6 F_161 ( char * V_1 )
{
if ( ! V_1 || strncmp ( V_1 , L_222 , 5 ) == 0 ) {
F_155 ( 1 ) ;
V_331 = 1 ;
} else if ( strncmp ( V_1 , L_223 , 2 ) == 0 )
F_155 ( 1 ) ;
else if ( strncmp ( V_1 , L_224 , 3 ) == 0 )
V_332 = 1 ;
else if ( strncmp ( V_1 , L_225 , 4 ) == 0 )
V_75 = 1 ;
else
return 1 ;
return 0 ;
}
void T_6 F_162 ( void )
{
#ifdef F_163
if ( ! V_332 )
F_155 ( 1 ) ;
#endif
if ( V_331 )
F_158 ( NULL ) ;
}
void F_164 ( struct V_333 * V_334 )
{
struct V_335 * V_335 ;
F_165 (spu, list, full_list) {
if ( V_335 -> V_336 >= V_337 ) {
F_166 ( 1 ) ;
continue;
}
V_338 [ V_335 -> V_336 ] . V_335 = V_335 ;
V_338 [ V_335 -> V_336 ] . V_339 = 0 ;
V_338 [ V_335 -> V_336 ] . V_340 = ( unsigned long )
V_338 [ V_335 -> V_336 ] . V_335 -> V_341 ;
}
}
static void F_167 ( void )
{
struct V_335 * V_335 ;
int V_60 ;
V_162 V_241 ;
for ( V_60 = 0 ; V_60 < V_337 ; V_60 ++ ) {
if ( ! V_338 [ V_60 ] . V_335 )
continue;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_335 = V_338 [ V_60 ] . V_335 ;
V_338 [ V_60 ] . V_342 =
F_168 ( & V_335 -> V_343 -> V_344 ) ;
V_241 = F_169 ( V_335 ) ;
V_338 [ V_60 ] . V_345 = V_241 ;
V_241 &= ~ V_346 ;
F_170 ( V_335 , V_241 ) ;
F_1 () ;
F_116 ( 200 ) ;
V_338 [ V_60 ] . V_339 = 1 ;
printf ( L_226 , V_60 ,
V_338 [ V_60 ] . V_342 ?
L_227 : L_228 ) ;
} else {
V_58 = 0 ;
printf ( L_229 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_171 ( void )
{
struct V_335 * V_335 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_337 ; V_60 ++ ) {
if ( ! V_338 [ V_60 ] . V_335 )
continue;
if ( ! V_338 [ V_60 ] . V_339 ) {
printf ( L_230
L_231 , V_60 ) ;
continue;
}
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_335 = V_338 [ V_60 ] . V_335 ;
F_170 ( V_335 , V_338 [ V_60 ] . V_345 ) ;
F_172 ( & V_335 -> V_343 -> V_344 ,
V_338 [ V_60 ] . V_342 ) ;
F_1 () ;
F_116 ( 200 ) ;
printf ( L_232 , V_60 ) ;
} else {
V_58 = 0 ;
printf ( L_233 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_173 ( struct V_335 * V_335 )
{
printf ( L_234 , V_335 ) ;
F_174 ( V_335 , L_235 , V_336 ) ;
F_174 ( V_335 , L_130 , V_105 ) ;
F_174 ( V_335 , L_236 , V_347 ) ;
F_174 ( V_335 , L_237 , V_341 ) ;
F_174 ( V_335 , L_236 , V_348 ) ;
F_174 ( V_335 , L_235 , V_349 ) ;
F_174 ( V_335 , L_236 , V_28 ) ;
F_174 ( V_335 , L_238 , V_350 ) ;
F_174 ( V_335 , L_236 , V_351 ) ;
F_174 ( V_335 , L_236 , V_352 ) ;
F_174 ( V_335 , L_236 , V_353 ) ;
F_174 ( V_335 , L_236 , V_354 [ 0 ] ) ;
F_174 ( V_335 , L_236 , V_354 [ 1 ] ) ;
F_174 ( V_335 , L_236 , V_354 [ 2 ] ) ;
F_174 ( V_335 , L_235 , V_355 ) ;
F_174 ( V_335 , L_238 , V_134 ) ;
F_174 ( V_335 , L_237 , V_356 ) ;
F_174 ( V_335 , L_237 , V_357 ) ;
F_174 ( V_335 , L_237 , V_358 ) ;
F_174 ( V_335 , L_237 , V_359 ) ;
F_174 ( V_335 , L_236 , V_360 ) ;
F_174 ( V_335 , L_237 , V_343 ) ;
F_175 ( L_235 , V_343 -> V_344 ,
F_168 ( & V_335 -> V_343 -> V_344 ) ) ;
F_175 ( L_235 , V_343 -> V_361 ,
F_168 ( & V_335 -> V_343 -> V_361 ) ) ;
F_175 ( L_235 , V_343 -> V_362 ,
F_168 ( & V_335 -> V_343 -> V_362 ) ) ;
F_174 ( V_335 , L_237 , V_363 ) ;
F_174 ( V_335 , L_237 , V_364 ) ;
}
int
F_176 ( unsigned long V_204 , long V_88 , int V_205 )
{
return F_136 ( V_204 , V_88 , V_205 , V_365 ) ;
}
static void F_177 ( unsigned long V_201 , int V_366 )
{
unsigned long V_27 , V_94 , V_367 ;
if ( setjmp ( V_106 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_367 = ( unsigned long ) V_338 [ V_201 ] . V_335 -> V_341 ;
F_1 () ;
F_116 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_239 , V_201 ) ;
return;
}
V_58 = 0 ;
if ( F_101 ( & V_27 ) )
V_94 = V_367 + V_27 ;
else
V_94 = V_338 [ V_201 ] . V_340 ;
if ( V_94 >= V_367 + V_368 ) {
printf ( L_240 ) ;
return;
}
switch ( V_366 ) {
case 'i' :
V_94 += F_176 ( V_94 , 16 , 1 ) ;
V_73 = L_241 ;
break;
default:
F_135 ( V_94 , 64 ) ;
V_94 += 64 ;
V_73 = L_242 ;
break;
}
V_338 [ V_201 ] . V_340 = V_94 ;
}
static int F_87 ( void )
{
static unsigned long V_201 = 0 ;
int V_22 , V_366 = 0 ;
V_22 = F_75 () ;
switch ( V_22 ) {
case 's' :
F_167 () ;
break;
case 'r' :
F_171 () ;
break;
case 'd' :
V_366 = F_75 () ;
if ( isxdigit ( V_366 ) || V_366 == '\n' )
V_78 = V_366 ;
case 'f' :
F_101 ( & V_201 ) ;
if ( V_201 >= V_337 || ! V_338 [ V_201 ] . V_335 ) {
printf ( L_243 ) ;
return 0 ;
}
switch ( V_22 ) {
case 'f' :
F_173 ( V_338 [ V_201 ] . V_335 ) ;
break;
default:
F_177 ( V_201 , V_366 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_87 ( void )
{
return - 1 ;
}
