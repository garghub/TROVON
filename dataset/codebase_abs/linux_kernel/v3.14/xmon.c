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
V_24 = F_22 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = V_24 -> V_32 + V_27 ;
F_23 ( & V_24 -> V_33 ) ;
}
F_24 () ;
#ifdef F_20
V_29 = F_11 () ;
if ( F_25 ( V_29 , & V_14 ) ) {
F_10 () ;
F_26 ( V_16 ) ;
printf ( L_2
L_3 ,
V_29 , V_16 -> V_34 , F_27 ( F_28 ( V_16 ) ) ) ;
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
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 || F_17 ( V_16 ) )
V_21 = 0 ;
if ( ! V_21 ) {
F_10 () ;
F_26 ( V_16 ) ;
if ( V_24 ) {
printf ( L_6 ,
V_29 , F_30 ( V_24 ) ) ;
F_31 ( V_16 -> V_31 , L_7 , L_8 ) ;
}
if ( F_17 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_14 () ;
}
F_32 ( V_29 , & V_14 ) ;
V_38:
V_30 = 1 ;
while ( V_30 && ! V_37 ) {
if ( V_36 == 0 ) {
if ( V_21 )
goto V_45;
V_30 = F_33 ( 0 , & V_36 ) ;
}
F_34 () ;
}
if ( ! V_30 && ! V_37 ) {
int V_46 = F_35 () ;
V_40 = V_29 ;
F_36 () ;
if ( V_46 > 1 ) {
F_37 () ;
for ( V_12 = 100000000 ; V_12 != 0 ; -- V_12 ) {
if ( F_38 ( & V_14 ) >= V_46 )
break;
F_34 () ;
}
}
F_39 () ;
F_5 () ;
if ( V_24 || F_28 ( V_16 ) == 0xd00 )
F_40 ( V_16 -> V_31 , 1 , 0 ) ;
printf ( L_11 ) ;
F_36 () ;
V_37 = 1 ;
F_34 () ;
}
V_41:
while ( V_36 ) {
if ( V_30 ) {
if ( V_29 == V_40 ) {
if ( ! F_33 ( 0 , & V_39 ) ) {
V_30 = 0 ;
continue;
}
while ( V_29 == V_40 )
F_34 () ;
}
F_34 () ;
} else {
V_22 = F_41 ( V_16 ) ;
if ( V_22 != 0 ) {
F_42 () ;
V_37 = 0 ;
F_43 () ;
V_36 = 0 ;
break;
}
V_30 = 1 ;
}
}
V_45:
F_44 ( V_29 , & V_14 ) ;
V_35 [ V_29 ] = NULL ;
#else
if ( V_36 ) {
printf ( L_12 ,
V_16 -> V_34 , F_27 ( F_28 ( V_16 ) ) ) ;
longjmp ( V_35 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_25 ) == 0 ) {
V_35 [ 0 ] = V_25 ;
V_36 = 1 ;
F_26 ( V_16 ) ;
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 ) {
printf ( L_13 , F_30 ( V_24 ) ) ;
F_31 ( V_16 -> V_31 , L_7 , L_8 ) ;
}
if ( F_17 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_39 () ;
F_5 () ;
if ( V_24 || F_28 ( V_16 ) == 0xd00 )
F_40 ( V_16 -> V_31 , 1 , 0 ) ;
printf ( L_11 ) ;
}
V_22 = F_41 ( V_16 ) ;
F_42 () ;
V_36 = 0 ;
#endif
#ifdef F_45
if ( V_16 -> V_19 & V_47 ) {
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = ( unsigned long ) & V_24 -> V_48 [ 0 ] ;
F_46 ( & V_24 -> V_33 ) ;
}
}
#else
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) ) {
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( V_24 != NULL ) {
int V_49 = F_47 ( V_16 , V_24 -> V_48 [ 0 ] ) ;
if ( V_49 == 0 ) {
V_16 -> V_31 = ( unsigned long ) & V_24 -> V_48 [ 0 ] ;
F_46 ( & V_24 -> V_33 ) ;
} else if ( V_49 < 0 ) {
printf ( L_14 ,
( F_48 ( V_24 -> V_48 [ 0 ] ) ? L_15 : L_16 ) ) ;
}
}
}
#endif
F_49 () ;
F_50 ( V_28 ) ;
return V_22 != 'X' && V_22 != V_50 ;
}
int F_51 ( struct V_15 * V_51 )
{
struct V_15 V_16 ;
if ( V_51 == NULL ) {
F_52 ( & V_16 ) ;
V_51 = & V_16 ;
}
return F_19 ( V_51 , 0 ) ;
}
T_1 F_53 ( int V_52 , void * V_53 )
{
unsigned long V_28 ;
F_21 ( V_28 ) ;
printf ( L_17 ) ;
F_51 ( F_54 () ) ;
F_50 ( V_28 ) ;
return V_54 ;
}
static int F_55 ( struct V_15 * V_16 )
{
struct V_23 * V_24 ;
unsigned long V_27 ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
V_24 = F_22 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL && V_27 == 4 ) {
V_16 -> V_31 = V_24 -> V_32 + 4 ;
F_23 ( & V_24 -> V_33 ) ;
return 1 ;
}
V_24 = F_29 ( V_16 -> V_31 ) ;
if ( ! V_24 )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_56 ( struct V_15 * V_16 )
{
if ( F_57 ( V_16 ) )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_58 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
if ( V_55 . V_56 == 0 )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_59 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) != ( V_42 | V_44 ) )
return 0 ;
if ( V_57 == NULL )
return 0 ;
F_19 ( V_16 , 0 ) ;
return 1 ;
}
static int F_60 ( struct V_15 * V_16 )
{
#ifdef F_20
if ( V_36 && ! F_25 ( F_11 () , & V_14 ) )
F_19 ( V_16 , 1 ) ;
#endif
return 0 ;
}
static int F_61 ( struct V_15 * V_16 )
{
struct V_23 * V_24 ;
unsigned long V_27 ;
if ( V_36 && V_58 )
F_62 ( V_16 ) ;
if ( ( V_16 -> V_19 & ( V_42 | V_43 | V_44 ) ) == ( V_42 | V_44 ) ) {
V_24 = F_22 ( V_16 -> V_31 , & V_27 ) ;
if ( V_24 != NULL ) {
V_16 -> V_31 = V_24 -> V_32 + V_27 ;
F_23 ( & V_24 -> V_33 ) ;
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
static struct V_23 * F_22 ( unsigned long V_31 , unsigned long * V_63 )
{
unsigned long V_64 ;
V_64 = V_31 - ( unsigned long ) V_61 ;
if ( V_64 >= sizeof( V_61 ) )
return NULL ;
V_64 %= sizeof( struct V_23 ) ;
if ( V_64 != F_63 ( struct V_23 , V_48 [ 0 ] )
&& V_64 != F_63 ( struct V_23 , V_48 [ 1 ] ) )
return NULL ;
* V_63 = V_64 - F_63 ( struct V_23 , V_48 [ 0 ] ) ;
return (struct V_23 * ) ( V_31 - V_64 ) ;
}
static struct V_23 * F_64 ( unsigned long V_65 )
{
struct V_23 * V_24 ;
V_65 &= ~ 3UL ;
V_24 = F_29 ( V_65 ) ;
if ( V_24 )
return V_24 ;
for ( V_24 = V_61 ; V_24 < & V_61 [ V_62 ] ; ++ V_24 ) {
if ( ! V_24 -> V_56 && F_65 ( & V_24 -> V_33 ) == 0 ) {
V_24 -> V_32 = V_65 ;
V_24 -> V_48 [ 1 ] = V_66 ;
F_2 ( & V_24 -> V_48 [ 1 ] ) ;
return V_24 ;
}
}
printf ( L_18 ) ;
return NULL ;
}
static void F_42 ( void )
{
int V_60 ;
struct V_23 * V_24 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 ) {
if ( ( V_24 -> V_56 & ( V_67 | V_68 ) ) == 0 )
continue;
if ( F_66 ( V_24 -> V_32 , & V_24 -> V_48 [ 0 ] , 4 ) != 4 ) {
printf ( L_19
L_20 , V_24 -> V_32 ) ;
V_24 -> V_56 = 0 ;
continue;
}
if ( F_67 ( V_24 -> V_48 [ 0 ] ) || F_48 ( V_24 -> V_48 [ 0 ] ) ) {
printf ( L_21
L_22 , V_24 -> V_32 ) ;
V_24 -> V_56 = 0 ;
continue;
}
F_2 ( & V_24 -> V_48 [ 0 ] ) ;
if ( V_24 -> V_56 & V_68 )
continue;
if ( F_68 ( V_24 -> V_32 , & V_66 , 4 ) != 4 ) {
printf ( L_23
L_20 , V_24 -> V_32 ) ;
V_24 -> V_56 &= ~ V_67 ;
continue;
}
F_2 ( ( void * ) V_24 -> V_32 ) ;
}
}
static void F_49 ( void )
{
struct V_69 V_70 ;
if ( V_55 . V_56 ) {
V_70 . V_32 = V_55 . V_32 ;
V_70 . type = ( V_55 . V_56 & V_71 ) | V_72 ;
V_70 . V_73 = 8 ;
F_69 ( & V_70 ) ;
}
if ( V_57 && F_70 ( V_74 ) )
F_71 ( V_75 , V_57 -> V_32
| ( V_57 -> V_56 & ( V_68 | V_76 ) ) ) ;
}
static void F_39 ( void )
{
int V_60 ;
struct V_23 * V_24 ;
unsigned V_48 ;
V_24 = V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; ++ V_60 , ++ V_24 ) {
if ( ( V_24 -> V_56 & ( V_67 | V_68 ) ) != V_67 )
continue;
if ( F_66 ( V_24 -> V_32 , & V_48 , 4 ) == 4
&& V_48 == V_66
&& F_68 ( V_24 -> V_32 , & V_24 -> V_48 , 4 ) != 4 )
printf ( L_24 ,
V_24 -> V_32 ) ;
else
F_2 ( ( void * ) V_24 -> V_32 ) ;
}
}
static void F_24 ( void )
{
F_72 () ;
if ( F_70 ( V_74 ) )
F_71 ( V_75 , 0 ) ;
}
static int
F_41 ( struct V_15 * V_51 )
{
int V_22 = 0 ;
V_77 = NULL ;
V_78 = V_51 ;
if ( ! V_79 ) {
V_79 = 1 ;
F_73 ( V_51 -> V_80 [ 1 ] , V_51 -> V_81 , V_51 -> V_31 ) ;
}
for(; ; ) {
#ifdef F_20
printf ( L_25 , F_11 () ) ;
#endif
printf ( L_26 ) ;
F_74 () ;
V_82 = 0 ;
V_22 = F_75 () ;
if( V_22 == '\n' ) {
if ( V_77 == NULL )
continue;
F_76 ( V_77 ) ;
V_77 = NULL ;
V_22 = F_77 () ;
}
switch ( V_22 ) {
case 'm' :
V_22 = F_77 () ;
switch ( V_22 ) {
case 'm' :
case 's' :
case 'd' :
F_78 ( V_22 ) ;
break;
case 'l' :
F_79 () ;
break;
case 'z' :
F_80 () ;
break;
case 'i' :
F_81 ( 0 ) ;
break;
default:
V_82 = V_22 ;
F_82 () ;
}
break;
case 'd' :
F_83 () ;
break;
case 'l' :
F_84 () ;
break;
case 'r' :
F_85 ( V_51 ) ;
break;
case 'e' :
F_26 ( V_51 ) ;
break;
case 'S' :
F_86 () ;
break;
case 't' :
F_87 ( V_51 ) ;
break;
case 'f' :
F_88 () ;
break;
case 's' :
if ( F_89 () == 0 )
break;
if ( F_90 ( V_51 ) )
return V_22 ;
break;
case 'x' :
case 'X' :
return V_22 ;
case V_50 :
printf ( L_27 ) ;
F_91 ( 2000 ) ;
return V_22 ;
case '?' :
F_92 ( V_83 ) ;
break;
case 'b' :
F_93 () ;
break;
case 'C' :
F_94 () ;
break;
case 'c' :
if ( F_95 () )
return 0 ;
break;
case 'z' :
F_96 () ;
break;
case 'p' :
F_97 () ;
break;
#ifdef F_98
case 'u' :
F_99 () ;
break;
#elif F_18 ( V_17 )
case 'u' :
F_100 () ;
break;
#elif F_18 ( V_18 )
case 'u' :
F_101 () ;
break;
#endif
default:
printf ( L_28 ) ;
do {
if ( ' ' < V_22 && V_22 <= '~' )
putchar ( V_22 ) ;
else
printf ( L_29 , V_22 ) ;
V_22 = F_77 () ;
} while ( V_22 != '\n' );
printf ( L_30 ) ;
break;
}
}
}
static int F_90 ( struct V_15 * V_16 )
{
V_16 -> V_19 |= V_47 ;
F_71 ( V_84 , F_102 ( V_84 ) | V_85 | V_86 ) ;
return 1 ;
}
static int F_90 ( struct V_15 * V_16 )
{
unsigned int V_48 ;
int V_49 ;
if ( ( V_16 -> V_19 & ( V_44 | V_43 | V_42 ) ) == ( V_44 | V_42 ) ) {
if ( F_66 ( V_16 -> V_31 , & V_48 , 4 ) == 4 ) {
V_49 = F_47 ( V_16 , V_48 ) ;
if ( V_49 < 0 ) {
printf ( L_14 ,
( F_48 ( V_48 ) ? L_15 : L_16 ) ) ;
return 0 ;
}
if ( V_49 > 0 ) {
V_16 -> V_34 = 0xd00 | ( V_16 -> V_34 & 1 ) ;
printf ( L_31 ) ;
F_31 ( V_16 -> V_31 , L_7 , L_32 ) ;
F_40 ( V_16 -> V_31 , 1 , 0 ) ;
return 0 ;
}
}
}
V_16 -> V_19 |= V_87 ;
return 1 ;
}
static void F_96 ( void )
{
int V_22 ;
V_22 = F_77 () ;
if ( V_22 == 'r' )
V_88 . V_89 ( NULL ) ;
else if ( V_22 == 'h' )
V_88 . V_90 () ;
else if ( V_22 == 'p' )
V_88 . V_91 () ;
}
static int F_95 ( void )
{
#ifdef F_20
unsigned long V_29 , V_92 , V_93 ;
int V_12 ;
if ( ! F_103 ( & V_29 ) ) {
printf ( L_33 ) ;
V_93 = V_92 = V_94 ;
F_104 (cpu) {
if ( F_25 ( V_29 , & V_14 ) ) {
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
if ( ! F_25 ( V_29 , & V_14 ) ) {
printf ( L_36 , V_29 ) ;
return 0 ;
}
V_39 = 0 ;
F_36 () ;
V_40 = V_29 ;
V_12 = 10000000 ;
while ( ! V_39 ) {
if ( -- V_12 == 0 ) {
if ( F_33 ( 0 , & V_39 ) )
break;
F_36 () ;
V_40 = F_11 () ;
printf ( L_37 , V_29 ) ;
return 0 ;
}
F_34 () ;
}
return 1 ;
#else
return 0 ;
#endif
}
static void
F_94 ( void )
{
unsigned int V_60 ;
unsigned short V_95 ;
unsigned char V_96 ;
if ( ! F_103 ( & V_97 ) )
return;
if ( ! F_103 ( & V_98 ) )
return;
V_95 = 0xffff ;
for ( V_60 = 0 ; V_60 < V_98 ; ++ V_60 ) {
if ( F_66 ( V_97 + V_60 , & V_96 , 1 ) == 0 ) {
printf ( L_38 , V_97 + V_60 ) ;
break;
}
V_95 = F_105 ( V_95 , V_96 ) ;
}
printf ( L_39 , V_95 ) ;
}
static long F_106 ( unsigned long V_99 )
{
unsigned int V_48 ;
V_99 &= ~ 3 ;
if ( ! F_107 ( V_99 ) ) {
printf ( L_40 ) ;
return 0 ;
}
if ( ! F_66 ( V_99 , & V_48 , sizeof( V_48 ) ) ) {
printf ( L_41 , V_99 ) ;
return 0 ;
}
if ( F_67 ( V_48 ) || F_48 ( V_48 ) ) {
printf ( L_42
L_43 ) ;
return 0 ;
}
return 1 ;
}
static void
F_93 ( void )
{
int V_22 ;
unsigned long V_65 ;
int V_100 , V_60 ;
struct V_23 * V_24 ;
const char V_101 [] = L_44
L_45 ;
V_22 = F_77 () ;
switch ( V_22 ) {
#ifndef F_108
case 'd' :
V_100 = 7 ;
V_22 = F_77 () ;
if ( V_22 == 'r' )
V_100 = 5 ;
else if ( V_22 == 'w' )
V_100 = 6 ;
else
V_82 = V_22 ;
V_55 . V_32 = 0 ;
V_55 . V_56 = 0 ;
if ( F_103 ( & V_55 . V_32 ) ) {
if ( ! F_107 ( V_55 . V_32 ) ) {
printf ( V_101 ) ;
break;
}
V_55 . V_32 &= ~ V_71 ;
V_55 . V_56 = V_100 | V_102 ;
}
break;
case 'i' :
if ( ! F_70 ( V_74 ) ) {
printf ( L_46
L_47 ) ;
break;
}
if ( V_57 ) {
V_57 -> V_56 &= ~ ( V_68 | V_76 ) ;
V_57 = NULL ;
}
if ( ! F_103 ( & V_65 ) )
break;
if ( ! F_106 ( V_65 ) )
break;
V_24 = F_64 ( V_65 ) ;
if ( V_24 != NULL ) {
V_24 -> V_56 |= V_68 | V_76 ;
V_57 = V_24 ;
}
break;
#endif
case 'c' :
if ( ! F_103 ( & V_65 ) ) {
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
V_82 = V_22 ;
V_22 = F_75 () ;
if ( V_22 == '?' ) {
printf ( V_103 ) ;
break;
}
V_82 = V_22 ;
if ( ! F_103 ( & V_65 ) ) {
printf ( L_51 ) ;
if ( V_55 . V_56 ) {
printf ( L_52 V_104 L_53 , V_55 . V_32 ) ;
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
if ( ! F_106 ( V_65 ) )
break;
V_24 = F_64 ( V_65 ) ;
if ( V_24 != NULL )
V_24 -> V_56 |= V_67 ;
break;
}
}
static
const char * F_27 ( unsigned long V_105 )
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
static void F_109 ( unsigned long V_59 , unsigned long * V_107 ,
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
V_110 = F_110 ( V_59 , & V_109 , & V_27 , NULL , V_112 ) ;
if ( V_110 != NULL ) {
* V_107 = V_59 - V_27 ;
* V_108 = V_59 - V_27 + V_109 ;
}
F_1 () ;
}
V_58 = 0 ;
}
static void F_73 ( unsigned long V_113 , unsigned long V_114 ,
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
if ( ! F_66 ( V_113 + V_120 , & V_116 , sizeof( unsigned long ) )
|| ! F_66 ( V_113 , & V_117 , sizeof( unsigned long ) ) ) {
printf ( L_86 , V_113 ) ;
break;
}
if ( ( V_59 | V_114 ) != 0 ) {
unsigned long V_121 , V_122 ;
unsigned long V_123 ;
int V_124 = 1 ;
F_109 ( V_59 , & V_121 , & V_122 ) ;
V_123 = 0 ;
if ( V_117 > V_113 )
F_66 ( V_117 + V_120 , & V_123 ,
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
F_31 ( V_114 , L_7 , L_32 ) ;
}
if ( V_124 ) {
printf ( L_88 V_104 L_89 , V_113 ) ;
F_31 ( V_116 , L_7 , L_90 ) ;
}
V_59 = V_114 = 0 ;
} else {
printf ( L_88 V_104 L_89 , V_113 ) ;
F_31 ( V_116 , L_7 , L_32 ) ;
}
if ( F_66 ( V_113 + V_125 , & V_118 , sizeof( unsigned long ) )
&& V_118 == V_126 ) {
if ( F_66 ( V_113 + V_127 , & V_16 , sizeof( V_16 ) )
!= sizeof( V_16 ) ) {
printf ( L_91 ,
V_113 + V_127 ) ;
break;
}
printf ( L_92 , V_16 . V_34 ,
F_27 ( F_28 ( & V_16 ) ) ) ;
V_59 = V_16 . V_31 ;
V_114 = V_16 . V_81 ;
F_31 ( V_59 , L_7 , L_32 ) ;
}
if ( V_117 == 0 )
break;
V_113 = V_117 ;
}
}
static void F_87 ( struct V_15 * V_51 )
{
unsigned long V_113 ;
if ( F_103 ( & V_113 ) )
F_73 ( V_113 , 0 , 0 ) ;
else
F_73 ( V_51 -> V_80 [ 1 ] , V_51 -> V_81 , V_51 -> V_31 ) ;
F_111 () ;
}
static void F_112 ( struct V_15 * V_16 )
{
#ifdef F_113
const struct V_128 * V_129 ;
unsigned long V_99 ;
if ( V_16 -> V_19 & V_43 )
return;
V_99 = V_16 -> V_31 ;
if ( V_99 < V_119 )
return;
V_129 = F_114 ( V_16 -> V_31 ) ;
if ( V_129 == NULL )
return;
if ( F_115 ( V_129 ) )
return;
#ifdef F_116
printf ( L_93 ,
V_129 -> V_130 , V_129 -> line ) ;
#else
printf ( L_94 , ( void * ) V_129 -> V_131 ) ;
#endif
#endif
}
static void F_26 ( struct V_15 * V_132 )
{
unsigned long V_34 ;
#ifdef F_20
printf ( L_95 , F_11 () ) ;
#endif
V_34 = F_28 ( V_132 ) ;
printf ( L_96 , V_132 -> V_34 , F_27 ( V_34 ) , V_132 ) ;
printf ( L_97 ) ;
F_31 ( V_132 -> V_31 , L_98 , L_32 ) ;
printf ( L_99 , V_132 -> V_81 ) ;
F_31 ( V_132 -> V_81 , L_98 , L_32 ) ;
printf ( L_100 , V_132 -> V_80 [ 1 ] ) ;
printf ( L_101 , V_132 -> V_19 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 || V_34 == 0x200 ) {
printf ( L_102 , V_132 -> V_133 ) ;
if ( V_34 != 0x380 )
printf ( L_103 , V_132 -> V_134 ) ;
}
printf ( L_104 , V_135 ) ;
#ifdef F_117
printf ( L_105 ,
V_136 , V_136 -> V_137 , V_136 -> V_138 ) ;
#endif
if ( V_135 ) {
printf ( L_106 ,
V_135 -> V_139 , V_135 -> V_140 ) ;
}
if ( V_34 == 0x700 )
F_112 ( V_132 ) ;
}
static void F_85 ( struct V_15 * V_132 )
{
int V_141 , V_34 ;
unsigned long V_142 ;
struct V_15 V_16 ;
if ( F_103 ( & V_142 ) ) {
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_16 = * (struct V_15 * ) V_142 ;
F_1 () ;
F_118 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_107 V_104 L_32 ,
V_142 ) ;
return;
}
V_58 = 0 ;
V_132 = & V_16 ;
}
#ifdef F_117
if ( F_119 ( V_132 ) ) {
for ( V_141 = 0 ; V_141 < 16 ; ++ V_141 )
printf ( L_108 V_104 L_109 V_104 L_32 ,
V_141 , V_132 -> V_80 [ V_141 ] , V_141 + 16 , V_132 -> V_80 [ V_141 + 16 ] ) ;
} else {
for ( V_141 = 0 ; V_141 < 7 ; ++ V_141 )
printf ( L_108 V_104 L_109 V_104 L_32 ,
V_141 , V_132 -> V_80 [ V_141 ] , V_141 + 7 , V_132 -> V_80 [ V_141 + 7 ] ) ;
}
#else
for ( V_141 = 0 ; V_141 < 32 ; ++ V_141 ) {
printf ( L_110 , V_141 , V_132 -> V_80 [ V_141 ] ,
( V_141 & 3 ) == 3 ? L_32 : L_111 ) ;
if ( V_141 == 12 && ! F_119 ( V_132 ) ) {
printf ( L_32 ) ;
break;
}
}
#endif
printf ( L_112 ) ;
F_31 ( V_132 -> V_31 , L_7 , L_32 ) ;
if ( F_28 ( V_132 ) != 0xc00 && F_70 ( V_143 ) ) {
printf ( L_113 ) ;
F_31 ( V_132 -> V_144 , L_7 , L_32 ) ;
}
printf ( L_114 ) ;
F_31 ( V_132 -> V_81 , L_7 , L_32 ) ;
printf ( L_115 V_104 L_116 , V_132 -> V_19 , V_132 -> V_145 ) ;
printf ( L_117 V_104 L_118 V_104 L_119 ,
V_132 -> V_146 , V_132 -> V_147 , V_132 -> V_34 ) ;
V_34 = F_28 ( V_132 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 )
printf ( L_120 V_104 L_121 , V_132 -> V_133 , V_132 -> V_134 ) ;
}
static void F_88 ( void )
{
int V_22 ;
unsigned long V_148 ;
V_22 = F_77 () ;
if ( V_22 != 'i' )
V_82 = V_22 ;
F_103 ( ( void * ) & V_97 ) ;
if ( V_82 != '\n' )
V_82 = 0 ;
V_148 = 1 ;
F_103 ( & V_148 ) ;
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
F_118 ( 200 ) ;
}
V_58 = 0 ;
}
static unsigned long
F_120 ( int V_141 )
{
unsigned int V_150 [ 2 ] ;
unsigned long ( * V_151 ) ( void ) ;
unsigned long V_106 = - 1UL ;
#ifdef F_117
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
F_118 ( 200 ) ;
V_141 = V_109 ;
}
return V_106 ;
}
static void
F_121 ( int V_141 , unsigned long V_153 )
{
unsigned int V_150 [ 2 ] ;
unsigned long ( * V_151 ) ( unsigned long ) ;
#ifdef F_117
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
F_118 ( 200 ) ;
V_141 = V_109 ;
}
}
static void F_86 ( void )
{
int V_22 ;
unsigned long V_153 ;
V_22 = F_75 () ;
if ( V_22 == '\n' ) {
unsigned long V_113 , V_154 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_122 V_104 L_123 V_104 L_32 ,
F_122 () , F_102 ( V_155 ) ) ;
printf ( L_124 V_104 L_125 V_104 L_32 ,
F_102 ( V_156 ) , F_102 ( V_157 ) ) ;
printf ( L_126 V_104 L_127 V_104 L_32 ,
F_102 ( V_158 ) , F_102 ( V_159 ) ) ;
printf ( L_128 V_104 L_129 V_104 L_32 , V_113 , F_102 ( V_160 ) ) ;
printf ( L_130 V_104 L_131 V_104 L_32 , V_154 , F_102 ( V_161 ) ) ;
return;
}
F_103 ( & V_162 ) ;
switch ( V_22 ) {
case 'w' :
V_153 = F_120 ( V_162 ) ;
F_103 ( & V_153 ) ;
F_121 ( V_162 , V_153 ) ;
case 'r' :
printf ( L_132 , V_162 , F_120 ( V_162 ) ) ;
break;
}
F_111 () ;
}
static int
F_66 ( unsigned long V_97 , void * V_163 , int V_109 )
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
F_118 ( 200 ) ;
V_141 = V_109 ;
}
V_58 = 0 ;
return V_141 ;
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
F_118 ( 200 ) ;
V_141 = V_109 ;
} else {
printf ( L_133 , V_97 + V_141 ) ;
}
V_58 = 0 ;
return V_141 ;
}
static int F_62 ( struct V_15 * V_16 )
{
V_168 = F_28 ( V_16 ) ;
switch ( F_28 ( V_16 ) ) {
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
F_123 ( unsigned char * V_153 , int V_109 )
{
int V_170 ;
switch ( V_109 ) {
case 2 :
F_124 ( V_153 [ 0 ] , V_153 [ 1 ] , V_170 ) ;
break;
case 4 :
F_124 ( V_153 [ 0 ] , V_153 [ 3 ] , V_170 ) ;
F_124 ( V_153 [ 1 ] , V_153 [ 2 ] , V_170 ) ;
break;
case 8 :
F_124 ( V_153 [ 0 ] , V_153 [ 7 ] , V_170 ) ;
F_124 ( V_153 [ 1 ] , V_153 [ 6 ] , V_170 ) ;
F_124 ( V_153 [ 2 ] , V_153 [ 5 ] , V_170 ) ;
F_124 ( V_153 [ 3 ] , V_153 [ 4 ] , V_170 ) ;
break;
}
}
static void
F_82 ( void )
{
int V_22 , V_171 , V_60 , V_172 ;
unsigned long V_141 ;
unsigned char V_153 [ 16 ] ;
F_103 ( ( void * ) & V_97 ) ;
V_22 = F_75 () ;
if ( V_22 == '?' ) {
printf ( V_173 ) ;
return;
} else {
V_82 = V_22 ;
}
V_77 = L_134 ;
while ( ( V_22 = F_75 () ) != '\n' ) {
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
V_141 = F_66 ( V_97 , V_153 , V_109 ) ;
printf ( V_104 L_135 , V_97 , V_174 ? 'r' : ' ' ) ;
if ( ! V_175 ) {
if ( V_174 )
F_123 ( V_153 , V_109 ) ;
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
if( F_103 ( & V_141 ) ) {
for ( V_60 = 0 ; V_60 < V_109 ; ++ V_60 )
V_153 [ V_60 ] = V_141 >> ( V_60 * 8 ) ;
if ( ! V_174 )
F_123 ( V_153 , V_109 ) ;
F_68 ( V_97 , V_153 , V_109 ) ;
V_171 = V_109 ;
}
V_22 = F_75 () ;
if ( V_22 == '\n' )
break;
V_171 = 0 ;
switch ( V_22 ) {
case '\'' :
for(; ; ) {
V_141 = F_77 () ;
if( V_141 == '\\' )
V_141 = F_125 () ;
else if( V_141 == '\'' )
break;
for ( V_60 = 0 ; V_60 < V_109 ; ++ V_60 )
V_153 [ V_60 ] = V_141 >> ( V_60 * 8 ) ;
if ( ! V_174 )
F_123 ( V_153 , V_109 ) ;
F_68 ( V_97 , V_153 , V_109 ) ;
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
F_111 () ;
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
F_103 ( ( void * ) & V_97 ) ;
break;
case 'n' :
V_175 = 1 ;
break;
case 'r' :
V_174 = ! V_174 ;
break;
case '<' :
V_141 = V_109 ;
F_103 ( & V_141 ) ;
V_97 -= V_141 ;
break;
case '>' :
V_141 = V_109 ;
F_103 ( & V_141 ) ;
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
F_125 ( void )
{
int V_178 ;
V_178 = F_77 () ;
switch( V_178 ) {
case 'n' : V_178 = '\n' ; break;
case 'r' : V_178 = '\r' ; break;
case 'b' : V_178 = '\b' ; break;
case 't' : V_178 = '\t' ; break;
}
return V_178 ;
}
static void F_126 ( unsigned long V_97 , long V_179 )
{
long V_141 , V_180 , V_181 , V_182 ;
unsigned char V_183 [ 16 ] ;
for ( V_141 = V_179 ; V_141 > 0 ; ) {
V_181 = V_141 < 16 ? V_141 : 16 ;
V_182 = F_66 ( V_97 , V_183 , V_181 ) ;
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
static void F_127 ( int V_29 )
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
printf ( L_140 , 16 , L_141 , F_128 ( V_29 ) ? L_142 : L_143 ) ;
printf ( L_140 , 16 , L_144 , F_129 ( V_29 ) ? L_142 : L_143 ) ;
printf ( L_140 , 16 , L_145 , F_130 ( V_29 ) ? L_142 : L_143 ) ;
#define F_131 ( V_185 , V_110 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 16, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_131 ( V_1 , V_186 , L_146 ) ;
F_131 ( V_1 , V_187 , L_146 ) ;
F_131 ( V_1 , V_188 , L_147 ) ;
F_131 ( V_1 , V_189 , L_147 ) ;
F_131 ( V_1 , V_190 , L_147 ) ;
#ifdef F_132
F_131 ( V_1 , V_191 , L_147 ) ;
F_131 ( V_1 , V_192 , L_147 ) ;
#endif
F_131 ( V_1 , V_193 , L_148 ) ;
#ifdef F_133
F_131 ( V_1 , V_194 , L_148 ) ;
F_131 ( V_1 , V_195 , L_146 ) ;
#endif
F_131 ( V_1 , V_196 , L_147 ) ;
F_131 ( V_1 , V_197 , L_146 ) ;
F_131 ( V_1 , V_198 , L_146 ) ;
F_131 ( V_1 , V_199 , L_146 ) ;
F_131 ( V_1 , V_200 , L_148 ) ;
F_131 ( V_1 , V_201 , L_147 ) ;
F_131 ( V_1 , V_202 , L_147 ) ;
F_131 ( V_1 , V_203 , L_147 ) ;
F_131 ( V_1 , V_204 , L_146 ) ;
F_131 ( V_1 , V_137 , L_146 ) ;
F_131 ( V_1 , V_138 , L_146 ) ;
F_131 ( V_1 , V_205 , L_146 ) ;
F_131 ( V_1 , V_206 , L_146 ) ;
F_131 ( V_1 , V_207 , L_146 ) ;
#undef F_131
V_58 = 0 ;
F_1 () ;
}
static void F_134 ( void )
{
int V_29 ;
if ( F_135 () == 0 ) {
printf ( L_149 ) ;
return;
}
F_104 (cpu)
F_127 ( V_29 ) ;
}
static void F_136 ( void )
{
unsigned long V_208 ;
int V_178 ;
V_178 = F_77 () ;
if ( V_178 == 'a' ) {
F_134 () ;
return;
}
V_82 = V_178 ;
if ( F_103 ( & V_208 ) )
F_127 ( V_208 ) ;
else
F_127 ( V_40 ) ;
}
static void
F_83 ( void )
{
int V_178 ;
V_178 = F_77 () ;
#ifdef F_117
if ( V_178 == 'p' ) {
F_136 () ;
return;
}
#endif
if ( ( isxdigit ( V_178 ) && V_178 != 'f' && V_178 != 'd' ) || V_178 == '\n' )
V_82 = V_178 ;
F_103 ( ( void * ) & V_97 ) ;
if ( V_82 != '\n' )
V_82 = 0 ;
if ( V_178 == 'i' ) {
F_103 ( & V_209 ) ;
if ( V_209 == 0 )
V_209 = 16 ;
else if ( V_209 > V_210 )
V_209 = V_210 ;
V_97 += F_40 ( V_97 , V_209 , 1 ) ;
V_77 = L_150 ;
} else if ( V_178 == 'l' ) {
F_137 () ;
} else if ( V_178 == 'r' ) {
F_103 ( & V_179 ) ;
if ( V_179 == 0 )
V_179 = 64 ;
F_126 ( V_97 , V_179 ) ;
V_97 += V_179 ;
V_77 = L_151 ;
} else {
F_103 ( & V_179 ) ;
if ( V_179 == 0 )
V_179 = 64 ;
else if ( V_179 > V_210 )
V_179 = V_210 ;
F_138 ( V_97 , V_179 ) ;
V_97 += V_179 ;
V_77 = L_152 ;
}
}
static void
F_138 ( unsigned long V_97 , long V_179 )
{
long V_141 , V_180 , V_178 , V_181 , V_182 ;
unsigned char V_183 [ 16 ] ;
for ( V_141 = V_179 ; V_141 > 0 ; ) {
printf ( V_104 , V_97 ) ;
putchar ( ' ' ) ;
V_181 = V_141 < 16 ? V_141 : 16 ;
V_182 = F_66 ( V_97 , V_183 , V_181 ) ;
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
F_139 ( unsigned long V_211 , long V_212 , int V_213 ,
T_3 V_214 )
{
int V_182 , V_215 ;
unsigned long V_216 ;
unsigned long V_217 , V_218 = 0 ;
unsigned char V_153 [ 4 ] ;
V_215 = 0 ;
for ( V_216 = V_211 ; V_212 > 0 ; -- V_212 , V_211 += 4 ) {
V_182 = F_66 ( V_211 , V_153 , 4 ) ;
if ( V_182 == 0 ) {
if ( V_213 ) {
const char * V_219 = V_176 [ V_169 ] ;
printf ( V_104 L_155 , V_211 , V_219 , V_219 , V_219 , V_219 ) ;
}
break;
}
V_217 = F_140 ( V_153 ) ;
if ( V_211 > V_216 && V_217 == V_218 ) {
if ( ! V_215 ) {
printf ( L_156 ) ;
V_215 = 1 ;
}
continue;
}
V_215 = 0 ;
V_218 = V_217 ;
if ( V_213 )
printf ( V_104 L_157 , V_211 , V_217 ) ;
printf ( L_158 ) ;
V_214 ( V_217 , V_211 ) ;
printf ( L_32 ) ;
}
return V_211 - V_216 ;
}
static int
F_40 ( unsigned long V_211 , long V_212 , int V_213 )
{
return F_139 ( V_211 , V_212 , V_213 , V_220 ) ;
}
void
F_141 ( unsigned long V_99 )
{
F_31 ( V_99 , L_159 , L_84 ) ;
}
void
F_137 ( void )
{
struct V_221 V_222 = { . V_223 = 1 } ;
unsigned char V_163 [ 128 ] ;
T_4 V_73 ;
if ( setjmp ( V_111 ) != 0 ) {
printf ( L_160 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
F_142 ( & V_222 ) ;
while ( F_143 ( & V_222 , false , V_163 , sizeof( V_163 ) , & V_73 ) ) {
V_163 [ V_73 ] = '\0' ;
printf ( L_137 , V_163 ) ;
}
F_1 () ;
F_118 ( 200 ) ;
V_58 = 0 ;
}
static void
F_78 ( int V_22 )
{
F_103 ( ( void * ) & V_224 ) ;
if( V_82 != '\n' )
V_82 = 0 ;
F_103 ( ( void * ) ( V_22 == 's' ? & V_225 : & V_226 ) ) ;
if( V_82 != '\n' )
V_82 = 0 ;
F_103 ( ( void * ) & V_227 ) ;
switch( V_22 ) {
case 'm' :
memmove ( ( void * ) V_224 , ( void * ) V_226 , V_227 ) ;
break;
case 's' :
memset ( ( void * ) V_224 , V_225 , V_227 ) ;
break;
case 'd' :
if( V_82 != '\n' )
V_82 = 0 ;
F_103 ( ( void * ) & V_228 ) ;
F_144 ( ( unsigned char * ) V_224 , ( unsigned char * ) V_226 , V_227 , V_228 ) ;
break;
}
}
static void
F_144 ( unsigned char * V_229 , unsigned char * V_230 , unsigned V_231 , unsigned V_232 )
{
unsigned V_141 , V_233 ;
V_233 = 0 ;
for( V_141 = V_231 ; V_141 > 0 ; -- V_141 )
if( * V_229 ++ != * V_230 ++ )
if( ++ V_233 <= V_232 )
printf ( L_161 , V_229 - 1 ,
V_229 [ - 1 ] , V_230 - 1 , V_230 [ - 1 ] ) ;
if( V_233 > V_232 )
printf ( L_162 , V_233 ) ;
}
static void
F_79 ( void )
{
unsigned V_65 , V_141 ;
unsigned char V_153 [ 4 ] ;
V_77 = L_163 ;
F_103 ( ( void * ) & V_224 ) ;
if ( V_82 != '\n' ) {
V_82 = 0 ;
F_103 ( ( void * ) & V_234 ) ;
if ( V_82 != '\n' ) {
V_82 = 0 ;
F_103 ( ( void * ) & V_225 ) ;
V_235 = ~ 0 ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_103 ( ( void * ) & V_235 ) ;
}
}
V_141 = 0 ;
for ( V_65 = V_224 ; V_65 < V_234 ; V_65 += 4 ) {
if ( F_66 ( V_65 , V_153 , 4 ) == 4
&& ( ( F_140 ( V_153 ) ^ V_225 ) & V_235 ) == 0 ) {
printf ( L_164 , V_65 , F_140 ( V_153 ) ) ;
if ( ++ V_141 >= 10 )
break;
}
}
}
static void
F_80 ( void )
{
unsigned char V_96 ;
unsigned V_65 ;
int V_236 , V_237 ;
F_103 ( & V_224 ) ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_103 ( & V_238 ) ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_103 ( & V_239 ) ;
V_237 = 0 ;
for ( V_65 = V_224 ; V_65 < V_239 ; V_65 += V_238 ) {
V_236 = F_66 ( V_65 , & V_96 , 1 ) ;
if ( V_236 && ! V_237 ) {
printf ( L_165 , V_65 ) ;
} else if ( ! V_236 && V_237 )
printf ( L_166 , V_65 - V_238 ) ;
V_237 = V_236 ;
if ( V_65 + V_238 < V_65 )
break;
}
if ( V_237 )
printf ( L_166 , V_65 - V_238 ) ;
}
static void F_97 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_106 ;
int V_60 ;
typedef unsigned long (* T_5)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_5 V_240 ;
if ( ! F_103 ( & V_97 ) )
return;
if ( V_82 != '\n' )
V_82 = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 )
args [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 ) {
if ( ! F_103 ( & args [ V_60 ] ) || V_82 == '\n' )
break;
V_82 = 0 ;
}
V_240 = ( T_5 ) V_97 ;
V_106 = 0 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_106 = V_240 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_1 () ;
printf ( L_167 , V_106 ) ;
} else {
printf ( L_168 , V_168 ) ;
}
V_58 = 0 ;
}
int
F_75 ( void )
{
int V_178 ;
if( V_82 != 0 ) {
V_178 = V_82 ;
V_82 = 0 ;
} else
V_178 = F_77 () ;
while( V_178 == ' ' || V_178 == '\t' )
V_178 = F_77 () ;
return V_178 ;
}
int
F_103 ( unsigned long * V_241 )
{
int V_178 , V_53 ;
unsigned long V_96 ;
V_178 = F_75 () ;
if ( V_178 == '%' ) {
char V_242 [ 8 ] ;
int V_60 ;
for ( V_60 = 0 ; V_60 < sizeof( V_242 ) - 1 ; ++ V_60 ) {
V_178 = F_77 () ;
if ( ! isalnum ( V_178 ) ) {
V_82 = V_178 ;
break;
}
V_242 [ V_60 ] = V_178 ;
}
V_242 [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < V_243 ; ++ V_60 ) {
if ( strcmp ( V_244 [ V_60 ] , V_242 ) == 0 ) {
if ( V_78 == NULL ) {
printf ( L_169 ) ;
return 0 ;
}
* V_241 = ( ( unsigned long * ) V_78 ) [ V_60 ] ;
return 1 ;
}
}
printf ( L_170 , V_242 ) ;
return 0 ;
}
if ( V_178 == '0' ) {
V_178 = F_77 () ;
if ( V_178 == 'x' ) {
V_178 = F_77 () ;
} else {
V_53 = F_145 ( V_178 ) ;
if ( V_53 == V_50 ) {
V_82 = V_178 ;
* V_241 = 0 ;
return 1 ;
}
}
} else if ( V_178 == '$' ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 63 ; V_60 ++ ) {
V_178 = F_77 () ;
if ( isspace ( V_178 ) ) {
V_82 = V_178 ;
break;
}
V_112 [ V_60 ] = V_178 ;
}
V_112 [ V_60 ++ ] = 0 ;
* V_241 = 0 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
* V_241 = F_146 ( V_112 ) ;
F_1 () ;
}
V_58 = 0 ;
if ( ! ( * V_241 ) ) {
printf ( L_171 , V_112 ) ;
return 0 ;
}
return 1 ;
}
V_53 = F_145 ( V_178 ) ;
if ( V_53 == V_50 ) {
V_82 = V_178 ;
return 0 ;
}
V_96 = 0 ;
do {
V_96 = ( V_96 << 4 ) + V_53 ;
V_178 = F_77 () ;
V_53 = F_145 ( V_178 ) ;
} while ( V_53 != V_50 );
V_82 = V_178 ;
* V_241 = V_96 ;
return 1 ;
}
static void
F_111 ( void )
{
int V_178 ;
V_178 = V_82 ;
V_82 = 0 ;
while( V_178 != '\n' )
V_178 = F_77 () ;
}
static int F_145 ( int V_178 )
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
F_147 ( char * V_245 , int V_109 )
{
int V_178 ;
V_178 = F_75 () ;
do {
if( V_109 > 1 ) {
* V_245 ++ = V_178 ;
-- V_109 ;
}
V_178 = F_77 () ;
} while( V_178 != ' ' && V_178 != '\t' && V_178 != '\n' );
V_82 = V_178 ;
* V_245 = 0 ;
}
static void
F_74 ( void )
{
V_246 = NULL ;
}
static int
F_77 ( void )
{
if ( V_246 == NULL || * V_246 == 0 ) {
if ( F_148 ( line , sizeof( line ) ) == NULL ) {
V_246 = NULL ;
return V_50 ;
}
V_246 = line ;
}
return * V_246 ++ ;
}
static void
F_76 ( char * V_247 )
{
V_246 = V_247 ;
}
static void
F_84 ( void )
{
int type = F_77 () ;
unsigned long V_99 ;
static char V_248 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_103 ( & V_99 ) )
F_31 ( V_99 , L_98 , L_32 ) ;
V_82 = 0 ;
break;
case 's' :
F_147 ( V_248 , 64 ) ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_99 = F_146 ( V_248 ) ;
if ( V_99 )
printf ( L_172 , V_248 , V_99 ) ;
else
printf ( L_173 , V_248 ) ;
F_1 () ;
}
V_58 = 0 ;
V_82 = 0 ;
break;
}
}
static void F_31 ( unsigned long V_32 , const char * V_249 ,
const char * V_250 )
{
char * V_251 ;
const char * V_110 = NULL ;
unsigned long V_27 , V_109 ;
printf ( V_104 , V_32 ) ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_110 = F_110 ( V_32 , & V_109 , & V_27 , & V_251 ,
V_112 ) ;
F_1 () ;
F_118 ( 200 ) ;
}
V_58 = 0 ;
if ( V_110 ) {
printf ( L_174 , V_249 , V_110 , V_27 , V_109 ) ;
if ( V_251 )
printf ( L_175 , V_251 ) ;
}
printf ( L_137 , V_250 ) ;
}
static void F_149 ( void )
{
int V_60 ;
unsigned long V_252 , V_253 , V_254 ;
unsigned long V_255 ;
printf ( L_176 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_256 ; V_60 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
V_254 = ( V_252 & V_257 ) ;
if ( V_254 | V_252 | V_253 ) {
printf ( L_177 , V_60 , V_252 , V_253 ) ;
if ( V_254 ) {
V_255 = V_253 & V_258 ;
if ( V_253 & V_259 ) {
printf ( L_178 ,
F_150 ( V_252 ) ,
( V_253 & ~ V_260 ) >> V_261 ,
V_255 ) ;
} else {
printf ( L_179 ,
F_151 ( V_252 ) ,
( V_253 & ~ V_260 ) >> V_262 ,
V_255 ) ;
}
} else
printf ( L_32 ) ;
}
}
}
static void F_152 ( void )
{
int V_60 ;
unsigned long * V_248 = ( unsigned long * ) V_136 -> V_192 ;
printf ( L_180 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_263 / 16 ; V_60 ++ ) {
unsigned long V_65 , V_264 ;
V_65 = * V_248 ++ ;
V_264 = * V_248 ++ ;
if ( V_65 || V_264 ) {
printf ( L_181 , V_60 , V_65 ) ;
printf ( L_182 , V_264 ) ;
}
}
}
void F_99 ( void )
{
if ( F_153 ( V_265 ) )
F_149 () ;
else
F_152 () ;
}
void F_99 ( void )
{
int V_60 ;
printf ( L_183 ) ;
for ( V_60 = 0 ; V_60 < 16 ; ++ V_60 )
printf ( L_184 , F_154 ( V_60 ) ) ;
printf ( L_32 ) ;
}
static void F_100 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_266 ; V_60 ++ ) {
unsigned long V_267 , V_268 , V_269 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_185 , V_60 , V_267 , V_268 , V_269 ) ;
if ( V_267 & V_270 ) {
printf ( L_186 ,
V_267 & V_271 ,
V_268 & V_272 ,
V_268 & V_273 ,
( V_269 & V_274 ) ? 'W' : 'w' ,
( V_269 & V_275 ) ? 'I' : 'i' ,
( V_269 & V_276 ) ? 'M' : 'm' ,
( V_269 & V_277 ) ? 'G' : 'g' ,
( V_269 & V_278 ) ? 'E' : 'e' ) ;
}
printf ( L_32 ) ;
}
}
static void F_101 ( void )
{
V_166 V_279 , V_280 , V_281 ;
V_167 V_282 ;
int V_60 , V_283 , V_284 , V_285 , V_286 , V_287 , V_288 = 0 ;
int V_289 ;
static const char * V_290 [] = {
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
L_216 ,
L_217 ,
L_218 ,
} ;
V_279 = F_102 ( V_291 ) ;
V_289 = ( V_279 & 3 ) + 1 ;
V_284 = ( ( V_279 >> 2 ) & 3 ) + 1 ;
V_285 = ( ( V_279 >> 6 ) & 0x1f ) + 1 ;
V_286 = ( V_279 >> 24 ) & 0xf ;
V_287 = ( V_279 >> 16 ) & 0x7f ;
if ( ( V_289 > 1 ) && ( V_279 & 0x10000 ) )
V_288 = 1 ;
printf ( L_219 ,
V_289 , V_284 , V_285 , V_286 , V_287 ) ;
V_280 = ( 1ul << V_285 ) - 1 ;
V_281 = ( 1ul << V_286 ) - 1 ;
V_282 = ( 1ull << V_287 ) - 1 ;
for ( V_283 = 0 ; V_283 < V_284 ; V_283 ++ ) {
V_166 V_292 ;
int V_293 , V_294 , V_295 = 1 ;
printf ( L_220 , V_283 ) ;
switch( V_283 ) {
case 0 :
V_292 = F_102 ( V_296 ) ;
break;
case 1 :
V_292 = F_102 ( V_297 ) ;
break;
case 2 :
V_292 = F_102 ( V_298 ) ;
break;
case 3 :
V_292 = F_102 ( V_299 ) ;
break;
default:
printf ( L_221 ) ;
continue;
}
V_293 = V_292 & 0xfff ;
V_294 = ( V_292 >> 24 ) & 0xff ;
for ( V_60 = 0 ; V_60 < V_293 ; V_60 ++ ) {
V_166 V_300 = F_155 ( V_283 ) ;
V_166 V_301 = F_156 ( V_302 ) ;
V_167 V_303 = 0 ;
V_167 V_304 ;
int V_305 = V_60 , V_306 = V_60 ;
if ( V_294 != 0 ) {
V_306 = V_60 / V_294 ;
V_305 = V_60 % V_294 ;
V_303 = V_306 * 0x1000 ;
}
V_300 |= F_157 ( V_305 ) ;
F_71 ( V_307 , V_300 ) ;
F_71 ( V_308 , V_301 ) ;
F_71 ( V_309 , V_303 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_301 = F_102 ( V_308 ) ;
V_303 = F_102 ( V_309 ) ;
V_304 = F_102 ( V_310 ) ;
if ( V_294 && ( V_60 % V_294 ) == 0 )
V_295 = 1 ;
if ( ! ( V_301 & V_311 ) )
continue;
if ( V_294 == 0 )
printf ( L_222 , V_60 ) ;
else if ( V_295 )
printf ( L_223 , V_306 , 'A' + V_305 ) ;
else
printf ( L_224 , 'A' + V_305 ) ;
V_295 = 0 ;
printf ( L_225 ,
V_303 & ~ 0x3ffull ,
( V_301 >> 16 ) & 0x3fff ,
V_290 [ ( V_301 >> 7 ) & 0x1f ] ,
V_301 & V_312 ? 'I' : ' ' ,
V_301 & V_313 ? 'P' : ' ' ,
V_301 & V_314 ? '1' : '0' ) ;
printf ( L_226 ,
V_303 & V_315 ? 'a' : ' ' ,
V_303 & V_316 ? 'v' : ' ' ,
V_303 & V_317 ? 'w' : ' ' ,
V_303 & V_318 ? 'i' : ' ' ,
V_303 & V_319 ? 'm' : ' ' ,
V_303 & V_320 ? 'g' : ' ' ,
V_303 & V_321 ? 'e' : ' ' ) ;
printf ( L_227 , V_304 & V_282 & ~ 0x7ffull ) ;
if ( V_301 & V_312 )
printf ( L_228 ,
V_290 [ ( V_304 >> 1 ) & 0x1f ] ) ;
else
printf ( L_229 ,
V_304 & V_322 ? 'x' : ' ' ,
V_304 & V_323 ? 'w' : ' ' ,
V_304 & V_324 ? 'r' : ' ' ,
V_304 & V_325 ? 'x' : ' ' ,
V_304 & V_326 ? 'w' : ' ' ,
V_304 & V_327 ? 'r' : ' ' ) ;
}
}
}
static void F_158 ( int V_328 )
{
if ( V_328 ) {
V_329 = F_51 ;
V_330 = F_60 ;
V_331 = F_55 ;
V_332 = F_56 ;
V_333 = F_59 ;
V_334 = F_58 ;
V_335 = F_61 ;
} else {
V_329 = NULL ;
V_330 = NULL ;
V_331 = NULL ;
V_332 = NULL ;
V_333 = NULL ;
V_334 = NULL ;
V_335 = NULL ;
}
}
static void F_159 ( int V_336 )
{
F_158 ( 1 ) ;
F_160 ( F_54 () ) ;
}
static int T_6 F_161 ( void )
{
F_162 ( 'x' , & V_337 ) ;
return 0 ;
}
static int T_6 F_163 ( char * V_1 )
{
if ( ! V_1 || strncmp ( V_1 , L_230 , 5 ) == 0 ) {
F_158 ( 1 ) ;
V_338 = 1 ;
} else if ( strncmp ( V_1 , L_231 , 2 ) == 0 )
F_158 ( 1 ) ;
else if ( strncmp ( V_1 , L_232 , 3 ) == 0 )
V_339 = 1 ;
else if ( strncmp ( V_1 , L_233 , 4 ) == 0 )
V_79 = 1 ;
else
return 1 ;
return 0 ;
}
void T_6 F_164 ( void )
{
#ifdef F_165
if ( ! V_339 )
F_158 ( 1 ) ;
#endif
if ( V_338 )
F_160 ( NULL ) ;
}
void F_166 ( struct V_340 * V_341 )
{
struct V_342 * V_342 ;
F_167 (spu, list, full_list) {
if ( V_342 -> V_343 >= V_344 ) {
F_168 ( 1 ) ;
continue;
}
V_345 [ V_342 -> V_343 ] . V_342 = V_342 ;
V_345 [ V_342 -> V_343 ] . V_346 = 0 ;
V_345 [ V_342 -> V_343 ] . V_347 = ( unsigned long )
V_345 [ V_342 -> V_343 ] . V_342 -> V_348 ;
}
}
static void F_169 ( void )
{
struct V_342 * V_342 ;
int V_60 ;
V_167 V_248 ;
for ( V_60 = 0 ; V_60 < V_344 ; V_60 ++ ) {
if ( ! V_345 [ V_60 ] . V_342 )
continue;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_342 = V_345 [ V_60 ] . V_342 ;
V_345 [ V_60 ] . V_349 =
F_170 ( & V_342 -> V_350 -> V_351 ) ;
V_248 = F_171 ( V_342 ) ;
V_345 [ V_60 ] . V_352 = V_248 ;
V_248 &= ~ V_353 ;
F_172 ( V_342 , V_248 ) ;
F_1 () ;
F_118 ( 200 ) ;
V_345 [ V_60 ] . V_346 = 1 ;
printf ( L_234 , V_60 ,
V_345 [ V_60 ] . V_349 ?
L_235 : L_236 ) ;
} else {
V_58 = 0 ;
printf ( L_237 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_173 ( void )
{
struct V_342 * V_342 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_344 ; V_60 ++ ) {
if ( ! V_345 [ V_60 ] . V_342 )
continue;
if ( ! V_345 [ V_60 ] . V_346 ) {
printf ( L_238
L_239 , V_60 ) ;
continue;
}
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_342 = V_345 [ V_60 ] . V_342 ;
F_172 ( V_342 , V_345 [ V_60 ] . V_352 ) ;
F_174 ( & V_342 -> V_350 -> V_351 ,
V_345 [ V_60 ] . V_349 ) ;
F_1 () ;
F_118 ( 200 ) ;
printf ( L_240 , V_60 ) ;
} else {
V_58 = 0 ;
printf ( L_241 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_175 ( struct V_342 * V_342 )
{
printf ( L_242 , V_342 ) ;
F_176 ( V_342 , L_243 , V_343 ) ;
F_176 ( V_342 , L_137 , V_110 ) ;
F_176 ( V_342 , L_244 , V_354 ) ;
F_176 ( V_342 , L_245 , V_348 ) ;
F_176 ( V_342 , L_244 , V_355 ) ;
F_176 ( V_342 , L_243 , V_356 ) ;
F_176 ( V_342 , L_244 , V_28 ) ;
F_176 ( V_342 , L_246 , V_357 ) ;
F_176 ( V_342 , L_244 , V_358 ) ;
F_176 ( V_342 , L_244 , V_359 ) ;
F_176 ( V_342 , L_244 , V_360 ) ;
F_176 ( V_342 , L_244 , V_361 [ 0 ] ) ;
F_176 ( V_342 , L_244 , V_361 [ 1 ] ) ;
F_176 ( V_342 , L_244 , V_361 [ 2 ] ) ;
F_176 ( V_342 , L_243 , V_362 ) ;
F_176 ( V_342 , L_246 , V_139 ) ;
F_176 ( V_342 , L_245 , V_363 ) ;
F_176 ( V_342 , L_245 , V_364 ) ;
F_176 ( V_342 , L_245 , V_365 ) ;
F_176 ( V_342 , L_245 , V_366 ) ;
F_176 ( V_342 , L_244 , V_367 ) ;
F_176 ( V_342 , L_245 , V_350 ) ;
F_177 ( L_243 , V_350 -> V_351 ,
F_170 ( & V_342 -> V_350 -> V_351 ) ) ;
F_177 ( L_243 , V_350 -> V_368 ,
F_170 ( & V_342 -> V_350 -> V_368 ) ) ;
F_177 ( L_243 , V_350 -> V_369 ,
F_170 ( & V_342 -> V_350 -> V_369 ) ) ;
F_176 ( V_342 , L_245 , V_370 ) ;
F_176 ( V_342 , L_245 , V_371 ) ;
}
int
F_178 ( unsigned long V_211 , long V_212 , int V_213 )
{
return F_139 ( V_211 , V_212 , V_213 , V_372 ) ;
}
static void F_179 ( unsigned long V_208 , int V_373 )
{
unsigned long V_27 , V_99 , V_374 ;
if ( setjmp ( V_111 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_374 = ( unsigned long ) V_345 [ V_208 ] . V_342 -> V_348 ;
F_1 () ;
F_118 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_247 , V_208 ) ;
return;
}
V_58 = 0 ;
if ( F_103 ( & V_27 ) )
V_99 = V_374 + V_27 ;
else
V_99 = V_345 [ V_208 ] . V_347 ;
if ( V_99 >= V_374 + V_375 ) {
printf ( L_248 ) ;
return;
}
switch ( V_373 ) {
case 'i' :
V_99 += F_178 ( V_99 , 16 , 1 ) ;
V_77 = L_249 ;
break;
default:
F_138 ( V_99 , 64 ) ;
V_99 += 64 ;
V_77 = L_250 ;
break;
}
V_345 [ V_208 ] . V_347 = V_99 ;
}
static int F_89 ( void )
{
static unsigned long V_208 = 0 ;
int V_22 , V_373 = 0 ;
V_22 = F_77 () ;
switch ( V_22 ) {
case 's' :
F_169 () ;
break;
case 'r' :
F_173 () ;
break;
case 'd' :
V_373 = F_77 () ;
if ( isxdigit ( V_373 ) || V_373 == '\n' )
V_82 = V_373 ;
case 'f' :
F_103 ( & V_208 ) ;
if ( V_208 >= V_344 || ! V_345 [ V_208 ] . V_342 ) {
printf ( L_251 ) ;
return 0 ;
}
switch ( V_22 ) {
case 'f' :
F_175 ( V_345 [ V_208 ] . V_342 ) ;
break;
default:
F_179 ( V_208 , V_373 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_89 ( void )
{
return - 1 ;
}
