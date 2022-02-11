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
struct V_69 V_70 ;
if ( V_55 . V_56 ) {
V_70 . V_32 = V_55 . V_32 ;
V_70 . type = ( V_55 . V_56 & V_71 ) | V_72 ;
V_70 . V_73 = 8 ;
F_68 ( & V_70 ) ;
}
if ( V_57 && F_69 ( V_74 ) )
F_70 ( V_75 , V_57 -> V_32
| ( V_57 -> V_56 & ( V_68 | V_76 ) ) ) ;
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
F_71 () ;
if ( F_69 ( V_74 ) )
F_70 ( V_75 , 0 ) ;
}
static int
F_40 ( struct V_15 * V_51 )
{
int V_22 = 0 ;
V_77 = NULL ;
V_78 = V_51 ;
if ( ! V_79 ) {
V_79 = 1 ;
F_72 ( V_51 -> V_80 [ 1 ] , V_51 -> V_81 , V_51 -> V_31 ) ;
}
for(; ; ) {
#ifdef F_19
printf ( L_25 , F_11 () ) ;
#endif
printf ( L_26 ) ;
F_73 () ;
V_82 = 0 ;
V_22 = F_74 () ;
if( V_22 == '\n' ) {
if ( V_77 == NULL )
continue;
F_75 ( V_77 ) ;
V_77 = NULL ;
V_22 = F_76 () ;
}
switch ( V_22 ) {
case 'm' :
V_22 = F_76 () ;
switch ( V_22 ) {
case 'm' :
case 's' :
case 'd' :
F_77 ( V_22 ) ;
break;
case 'l' :
F_78 () ;
break;
case 'z' :
F_79 () ;
break;
case 'i' :
F_80 ( 0 ) ;
break;
default:
V_82 = V_22 ;
F_81 () ;
}
break;
case 'd' :
F_82 () ;
break;
case 'l' :
F_83 () ;
break;
case 'r' :
F_84 ( V_51 ) ;
break;
case 'e' :
F_25 ( V_51 ) ;
break;
case 'S' :
F_85 () ;
break;
case 't' :
F_86 ( V_51 ) ;
break;
case 'f' :
F_87 () ;
break;
case 's' :
if ( F_88 () == 0 )
break;
if ( F_89 ( V_51 ) )
return V_22 ;
break;
case 'x' :
case 'X' :
return V_22 ;
case V_50 :
printf ( L_27 ) ;
F_90 ( 2000 ) ;
return V_22 ;
case '?' :
F_91 ( V_83 ) ;
break;
case 'b' :
F_92 () ;
break;
case 'C' :
F_93 () ;
break;
case 'c' :
if ( F_94 () )
return 0 ;
break;
case 'z' :
F_95 () ;
break;
case 'p' :
F_96 () ;
break;
#ifdef F_97
case 'u' :
F_98 () ;
break;
#elif F_17 ( V_17 )
case 'u' :
F_99 () ;
break;
#elif F_17 ( V_18 )
case 'u' :
F_100 () ;
break;
#endif
default:
printf ( L_28 ) ;
do {
if ( ' ' < V_22 && V_22 <= '~' )
putchar ( V_22 ) ;
else
printf ( L_29 , V_22 ) ;
V_22 = F_76 () ;
} while ( V_22 != '\n' );
printf ( L_30 ) ;
break;
}
}
}
static int F_89 ( struct V_15 * V_16 )
{
V_16 -> V_19 |= V_47 ;
F_70 ( V_84 , F_101 ( V_84 ) | V_85 | V_86 ) ;
return 1 ;
}
static int F_89 ( struct V_15 * V_16 )
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
V_16 -> V_19 |= V_87 ;
return 1 ;
}
static void F_95 ( void )
{
int V_22 ;
V_22 = F_76 () ;
if ( V_22 == 'r' )
V_88 . V_89 ( NULL ) ;
else if ( V_22 == 'h' )
V_88 . V_90 () ;
else if ( V_22 == 'p' )
V_88 . V_91 () ;
}
static int F_94 ( void )
{
#ifdef F_19
unsigned long V_29 ;
int V_12 ;
int V_92 ;
if ( ! F_102 ( & V_29 ) ) {
printf ( L_33 ) ;
V_92 = 0 ;
F_103 (cpu) {
if ( F_24 ( V_29 , & V_14 ) ) {
if ( V_92 == 0 )
printf ( L_34 , V_29 ) ;
++ V_92 ;
} else {
if ( V_92 > 1 )
printf ( L_35 , V_29 - 1 ) ;
V_92 = 0 ;
}
}
if ( V_92 > 1 )
printf ( L_35 , V_93 - 1 ) ;
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
F_93 ( void )
{
unsigned int V_60 ;
unsigned short V_94 ;
unsigned char V_95 ;
if ( ! F_102 ( & V_96 ) )
return;
if ( ! F_102 ( & V_97 ) )
return;
V_94 = 0xffff ;
for ( V_60 = 0 ; V_60 < V_97 ; ++ V_60 ) {
if ( F_65 ( V_96 + V_60 , & V_95 , 1 ) == 0 ) {
printf ( L_38 , V_96 + V_60 ) ;
break;
}
V_94 = F_104 ( V_94 , V_95 ) ;
}
printf ( L_39 , V_94 ) ;
}
static long F_105 ( unsigned long V_98 )
{
unsigned int V_48 ;
V_98 &= ~ 3 ;
if ( ! F_106 ( V_98 ) ) {
printf ( L_40 ) ;
return 0 ;
}
if ( ! F_65 ( V_98 , & V_48 , sizeof( V_48 ) ) ) {
printf ( L_41 , V_98 ) ;
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
F_92 ( void )
{
int V_22 ;
unsigned long V_65 ;
int V_99 , V_60 ;
struct V_23 * V_24 ;
const char V_100 [] = L_44
L_45 ;
V_22 = F_76 () ;
switch ( V_22 ) {
#ifndef F_107
case 'd' :
V_99 = 7 ;
V_22 = F_76 () ;
if ( V_22 == 'r' )
V_99 = 5 ;
else if ( V_22 == 'w' )
V_99 = 6 ;
else
V_82 = V_22 ;
V_55 . V_32 = 0 ;
V_55 . V_56 = 0 ;
if ( F_102 ( & V_55 . V_32 ) ) {
if ( ! F_106 ( V_55 . V_32 ) ) {
printf ( V_100 ) ;
break;
}
V_55 . V_32 &= ~ V_71 ;
V_55 . V_56 = V_99 | V_101 ;
}
break;
case 'i' :
if ( ! F_69 ( V_74 ) ) {
printf ( L_46
L_47 ) ;
break;
}
if ( V_57 ) {
V_57 -> V_56 &= ~ ( V_68 | V_76 ) ;
V_57 = NULL ;
}
if ( ! F_102 ( & V_65 ) )
break;
if ( ! F_105 ( V_65 ) )
break;
V_24 = F_63 ( V_65 ) ;
if ( V_24 != NULL ) {
V_24 -> V_56 |= V_68 | V_76 ;
V_57 = V_24 ;
}
break;
#endif
case 'c' :
if ( ! F_102 ( & V_65 ) ) {
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
V_22 = F_74 () ;
if ( V_22 == '?' ) {
printf ( V_102 ) ;
break;
}
V_82 = V_22 ;
if ( ! F_102 ( & V_65 ) ) {
printf ( L_51 ) ;
if ( V_55 . V_56 ) {
printf ( L_52 V_103 L_53 , V_55 . V_32 ) ;
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
if ( ! F_105 ( V_65 ) )
break;
V_24 = F_63 ( V_65 ) ;
if ( V_24 != NULL )
V_24 -> V_56 |= V_67 ;
break;
}
}
static
const char * F_26 ( unsigned long V_104 )
{
char * V_105 ;
switch ( V_104 ) {
case 0x100 : V_105 = L_61 ; break;
case 0x200 : V_105 = L_62 ; break;
case 0x300 : V_105 = L_63 ; break;
case 0x380 : V_105 = L_64 ; break;
case 0x400 : V_105 = L_65 ; break;
case 0x480 : V_105 = L_66 ; break;
case 0x500 : V_105 = L_67 ; break;
case 0x600 : V_105 = L_68 ; break;
case 0x700 : V_105 = L_69 ; break;
case 0x800 : V_105 = L_70 ; break;
case 0x900 : V_105 = L_71 ; break;
case 0xc00 : V_105 = L_72 ; break;
case 0xd00 : V_105 = L_73 ; break;
case 0xf00 : V_105 = L_74 ; break;
case 0xf20 : V_105 = L_75 ; break;
case 0x1300 : V_105 = L_76 ; break;
default: V_105 = L_77 ;
}
return V_105 ;
}
static void F_108 ( unsigned long V_59 , unsigned long * V_106 ,
unsigned long * V_107 )
{
unsigned long V_108 , V_27 ;
const char * V_109 ;
* V_106 = * V_107 = 0 ;
if ( V_59 == 0 )
return;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_109 = F_109 ( V_59 , & V_108 , & V_27 , NULL , V_111 ) ;
if ( V_109 != NULL ) {
* V_106 = V_59 - V_27 ;
* V_107 = V_59 - V_27 + V_108 ;
}
F_1 () ;
}
V_58 = 0 ;
}
static void F_72 ( unsigned long V_112 , unsigned long V_113 ,
unsigned long V_59 )
{
int V_114 = 64 ;
unsigned long V_115 ;
unsigned long V_116 ;
unsigned long V_117 ;
struct V_15 V_16 ;
while ( V_114 -- ) {
if ( V_112 < V_118 ) {
if ( V_112 != 0 )
printf ( L_78 , V_112 ) ;
break;
}
if ( ! F_65 ( V_112 + V_119 , & V_115 , sizeof( unsigned long ) )
|| ! F_65 ( V_112 , & V_116 , sizeof( unsigned long ) ) ) {
printf ( L_79 , V_112 ) ;
break;
}
if ( ( V_59 | V_113 ) != 0 ) {
unsigned long V_120 , V_121 ;
unsigned long V_122 ;
int V_123 = 1 ;
F_108 ( V_59 , & V_120 , & V_121 ) ;
V_122 = 0 ;
if ( V_116 > V_112 )
F_65 ( V_116 + V_119 , & V_122 ,
sizeof( unsigned long ) ) ;
if ( V_113 == V_115 ) {
if ( V_113 < V_118
|| ( V_120 <= V_113 && V_113 < V_121 ) )
V_123 = 0 ;
} else if ( V_113 == V_122 ) {
V_123 = 0 ;
} else if ( V_113 >= V_118
&& ! ( V_120 <= V_113 && V_113 < V_121 ) ) {
printf ( L_80 ) ;
F_31 ( V_113 , L_7 , L_32 ) ;
}
if ( V_123 ) {
printf ( L_81 V_103 L_82 , V_112 ) ;
F_31 ( V_115 , L_7 , L_83 ) ;
}
V_59 = V_113 = 0 ;
} else {
printf ( L_81 V_103 L_82 , V_112 ) ;
F_31 ( V_115 , L_7 , L_32 ) ;
}
if ( F_65 ( V_112 + V_124 , & V_117 , sizeof( unsigned long ) )
&& V_117 == V_125 ) {
if ( F_65 ( V_112 + V_126 , & V_16 , sizeof( V_16 ) )
!= sizeof( V_16 ) ) {
printf ( L_84 ,
V_112 + V_126 ) ;
break;
}
printf ( L_85 , V_16 . V_34 ,
F_26 ( F_27 ( & V_16 ) ) ) ;
V_59 = V_16 . V_31 ;
V_113 = V_16 . V_81 ;
F_31 ( V_59 , L_7 , L_32 ) ;
}
if ( V_116 == 0 )
break;
V_112 = V_116 ;
}
}
static void F_86 ( struct V_15 * V_51 )
{
unsigned long V_112 ;
if ( F_102 ( & V_112 ) )
F_72 ( V_112 , 0 , 0 ) ;
else
F_72 ( V_51 -> V_80 [ 1 ] , V_51 -> V_81 , V_51 -> V_31 ) ;
F_110 () ;
}
static void F_111 ( struct V_15 * V_16 )
{
#ifdef F_112
const struct V_127 * V_128 ;
unsigned long V_98 ;
if ( V_16 -> V_19 & V_43 )
return;
V_98 = V_16 -> V_31 ;
if ( V_98 < V_118 )
return;
V_128 = F_113 ( V_16 -> V_31 ) ;
if ( V_128 == NULL )
return;
if ( F_114 ( V_128 ) )
return;
#ifdef F_115
printf ( L_86 ,
V_128 -> V_129 , V_128 -> line ) ;
#else
printf ( L_87 , ( void * ) V_128 -> V_130 ) ;
#endif
#endif
}
static void F_25 ( struct V_15 * V_131 )
{
unsigned long V_34 ;
#ifdef F_19
printf ( L_88 , F_11 () ) ;
#endif
V_34 = F_27 ( V_131 ) ;
printf ( L_89 , V_131 -> V_34 , F_26 ( V_34 ) , V_131 ) ;
printf ( L_90 ) ;
F_31 ( V_131 -> V_31 , L_91 , L_32 ) ;
printf ( L_92 , V_131 -> V_81 ) ;
F_31 ( V_131 -> V_81 , L_91 , L_32 ) ;
printf ( L_93 , V_131 -> V_80 [ 1 ] ) ;
printf ( L_94 , V_131 -> V_19 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 || V_34 == 0x200 ) {
printf ( L_95 , V_131 -> V_132 ) ;
if ( V_34 != 0x380 )
printf ( L_96 , V_131 -> V_133 ) ;
}
printf ( L_97 , V_134 ) ;
#ifdef F_116
printf ( L_98 ,
V_135 , V_135 -> V_136 , V_135 -> V_137 ) ;
#endif
if ( V_134 ) {
printf ( L_99 ,
V_134 -> V_138 , V_134 -> V_139 ) ;
}
if ( V_34 == 0x700 )
F_111 ( V_131 ) ;
}
static void F_84 ( struct V_15 * V_131 )
{
int V_140 , V_34 ;
unsigned long V_141 ;
struct V_15 V_16 ;
if ( F_102 ( & V_141 ) ) {
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_16 = * (struct V_15 * ) V_141 ;
F_1 () ;
F_117 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_100 V_103 L_32 ,
V_141 ) ;
return;
}
V_58 = 0 ;
V_131 = & V_16 ;
}
#ifdef F_116
if ( F_118 ( V_131 ) ) {
for ( V_140 = 0 ; V_140 < 16 ; ++ V_140 )
printf ( L_101 V_103 L_102 V_103 L_32 ,
V_140 , V_131 -> V_80 [ V_140 ] , V_140 + 16 , V_131 -> V_80 [ V_140 + 16 ] ) ;
} else {
for ( V_140 = 0 ; V_140 < 7 ; ++ V_140 )
printf ( L_101 V_103 L_102 V_103 L_32 ,
V_140 , V_131 -> V_80 [ V_140 ] , V_140 + 7 , V_131 -> V_80 [ V_140 + 7 ] ) ;
}
#else
for ( V_140 = 0 ; V_140 < 32 ; ++ V_140 ) {
printf ( L_103 , V_140 , V_131 -> V_80 [ V_140 ] ,
( V_140 & 3 ) == 3 ? L_32 : L_104 ) ;
if ( V_140 == 12 && ! F_118 ( V_131 ) ) {
printf ( L_32 ) ;
break;
}
}
#endif
printf ( L_105 ) ;
F_31 ( V_131 -> V_31 , L_7 , L_32 ) ;
if ( F_27 ( V_131 ) != 0xc00 && F_69 ( V_142 ) ) {
printf ( L_106 ) ;
F_31 ( V_131 -> V_143 , L_7 , L_32 ) ;
}
printf ( L_107 ) ;
F_31 ( V_131 -> V_81 , L_7 , L_32 ) ;
printf ( L_108 V_103 L_109 , V_131 -> V_19 , V_131 -> V_144 ) ;
printf ( L_110 V_103 L_111 V_103 L_112 ,
V_131 -> V_145 , V_131 -> V_146 , V_131 -> V_34 ) ;
V_34 = F_27 ( V_131 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 )
printf ( L_113 V_103 L_114 , V_131 -> V_132 , V_131 -> V_133 ) ;
}
static void F_87 ( void )
{
int V_22 ;
unsigned long V_147 ;
V_22 = F_76 () ;
if ( V_22 != 'i' )
V_82 = V_22 ;
F_102 ( ( void * ) & V_96 ) ;
if ( V_82 != '\n' )
V_82 = 0 ;
V_147 = 1 ;
F_102 ( & V_147 ) ;
V_147 = ( V_147 + V_148 - 1 ) / V_148 ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
if ( V_22 != 'i' ) {
for (; V_147 > 0 ; -- V_147 , V_96 += V_148 )
F_3 ( ( void * ) V_96 ) ;
} else {
for (; V_147 > 0 ; -- V_147 , V_96 += V_148 )
F_4 ( ( void * ) V_96 ) ;
}
F_1 () ;
F_117 ( 200 ) ;
}
V_58 = 0 ;
}
static unsigned long
F_119 ( int V_140 )
{
unsigned int V_149 [ 2 ] ;
unsigned long ( * V_150 ) ( void ) ;
unsigned long V_105 = - 1UL ;
#ifdef F_116
unsigned long V_151 [ 3 ] ;
V_151 [ 0 ] = ( unsigned long ) V_149 ;
V_151 [ 1 ] = 0 ;
V_151 [ 2 ] = 0 ;
V_150 = ( unsigned long ( * ) ( void ) ) V_151 ;
#else
V_150 = ( unsigned long ( * ) ( void ) ) V_149 ;
#endif
V_149 [ 0 ] = 0x7c6002a6 + ( ( V_140 & 0x1F ) << 16 ) + ( ( V_140 & 0x3e0 ) << 6 ) ;
V_149 [ 1 ] = 0x4e800020 ;
F_2 ( V_149 ) ;
F_2 ( V_149 + 1 ) ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_105 = V_150 () ;
F_1 () ;
F_117 ( 200 ) ;
V_140 = V_108 ;
}
return V_105 ;
}
static void
F_120 ( int V_140 , unsigned long V_152 )
{
unsigned int V_149 [ 2 ] ;
unsigned long ( * V_150 ) ( unsigned long ) ;
#ifdef F_116
unsigned long V_151 [ 3 ] ;
V_151 [ 0 ] = ( unsigned long ) V_149 ;
V_151 [ 1 ] = 0 ;
V_151 [ 2 ] = 0 ;
V_150 = ( unsigned long (*) ( unsigned long ) ) V_151 ;
#else
V_150 = ( unsigned long (*) ( unsigned long ) ) V_149 ;
#endif
V_149 [ 0 ] = 0x7c6003a6 + ( ( V_140 & 0x1F ) << 16 ) + ( ( V_140 & 0x3e0 ) << 6 ) ;
V_149 [ 1 ] = 0x4e800020 ;
F_2 ( V_149 ) ;
F_2 ( V_149 + 1 ) ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_150 ( V_152 ) ;
F_1 () ;
F_117 ( 200 ) ;
V_140 = V_108 ;
}
}
static void F_85 ( void )
{
int V_22 ;
unsigned long V_152 ;
V_22 = F_74 () ;
if ( V_22 == '\n' ) {
unsigned long V_112 , V_153 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_115 V_103 L_116 V_103 L_32 ,
F_121 () , F_101 ( V_154 ) ) ;
printf ( L_117 V_103 L_118 V_103 L_32 ,
F_101 ( V_155 ) , F_101 ( V_156 ) ) ;
printf ( L_119 V_103 L_120 V_103 L_32 ,
F_101 ( V_157 ) , F_101 ( V_158 ) ) ;
printf ( L_121 V_103 L_122 V_103 L_32 , V_112 , F_101 ( V_159 ) ) ;
printf ( L_123 V_103 L_124 V_103 L_32 , V_153 , F_101 ( V_160 ) ) ;
return;
}
F_102 ( & V_161 ) ;
switch ( V_22 ) {
case 'w' :
V_152 = F_119 ( V_161 ) ;
F_102 ( & V_152 ) ;
F_120 ( V_161 , V_152 ) ;
case 'r' :
printf ( L_125 , V_161 , F_119 ( V_161 ) ) ;
break;
}
F_110 () ;
}
static int
F_65 ( unsigned long V_96 , void * V_162 , int V_108 )
{
volatile int V_140 ;
char * V_1 , * V_163 ;
V_140 = 0 ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_96 ;
V_163 = ( char * ) V_162 ;
switch ( V_108 ) {
case 2 :
* ( V_164 * ) V_163 = * ( V_164 * ) V_1 ;
break;
case 4 :
* ( V_165 * ) V_163 = * ( V_165 * ) V_1 ;
break;
case 8 :
* ( V_166 * ) V_163 = * ( V_166 * ) V_1 ;
break;
default:
for( ; V_140 < V_108 ; ++ V_140 ) {
* V_163 ++ = * V_1 ++ ;
F_1 () ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_140 = V_108 ;
}
V_58 = 0 ;
return V_140 ;
}
static int
F_67 ( unsigned long V_96 , void * V_162 , int V_108 )
{
volatile int V_140 ;
char * V_1 , * V_163 ;
V_140 = 0 ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_96 ;
V_163 = ( char * ) V_162 ;
switch ( V_108 ) {
case 2 :
* ( V_164 * ) V_1 = * ( V_164 * ) V_163 ;
break;
case 4 :
* ( V_165 * ) V_1 = * ( V_165 * ) V_163 ;
break;
case 8 :
* ( V_166 * ) V_1 = * ( V_166 * ) V_163 ;
break;
default:
for ( ; V_140 < V_108 ; ++ V_140 ) {
* V_1 ++ = * V_163 ++ ;
F_1 () ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_140 = V_108 ;
} else {
printf ( L_126 , V_96 + V_140 ) ;
}
V_58 = 0 ;
return V_140 ;
}
static int F_61 ( struct V_15 * V_16 )
{
V_167 = F_27 ( V_16 ) ;
switch ( F_27 ( V_16 ) ) {
case 0x200 :
V_168 = 0 ;
break;
case 0x300 :
case 0x380 :
V_168 = 1 ;
break;
default:
V_168 = 2 ;
}
longjmp ( V_110 , 1 ) ;
return 0 ;
}
static void
F_122 ( unsigned char * V_152 , int V_108 )
{
int V_169 ;
switch ( V_108 ) {
case 2 :
F_123 ( V_152 [ 0 ] , V_152 [ 1 ] , V_169 ) ;
break;
case 4 :
F_123 ( V_152 [ 0 ] , V_152 [ 3 ] , V_169 ) ;
F_123 ( V_152 [ 1 ] , V_152 [ 2 ] , V_169 ) ;
break;
case 8 :
F_123 ( V_152 [ 0 ] , V_152 [ 7 ] , V_169 ) ;
F_123 ( V_152 [ 1 ] , V_152 [ 6 ] , V_169 ) ;
F_123 ( V_152 [ 2 ] , V_152 [ 5 ] , V_169 ) ;
F_123 ( V_152 [ 3 ] , V_152 [ 4 ] , V_169 ) ;
break;
}
}
static void
F_81 ( void )
{
int V_22 , V_170 , V_60 , V_171 ;
unsigned long V_140 ;
unsigned char V_152 [ 16 ] ;
F_102 ( ( void * ) & V_96 ) ;
V_22 = F_74 () ;
if ( V_22 == '?' ) {
printf ( V_172 ) ;
return;
} else {
V_82 = V_22 ;
}
V_77 = L_127 ;
while ( ( V_22 = F_74 () ) != '\n' ) {
switch( V_22 ) {
case 'b' : V_108 = 1 ; break;
case 'w' : V_108 = 2 ; break;
case 'l' : V_108 = 4 ; break;
case 'd' : V_108 = 8 ; break;
case 'r' : V_173 = ! V_173 ; break;
case 'n' : V_174 = 1 ; break;
case '.' : V_174 = 0 ; break;
}
}
if( V_108 <= 0 )
V_108 = 1 ;
else if( V_108 > 8 )
V_108 = 8 ;
for(; ; ) {
if ( ! V_174 )
V_140 = F_65 ( V_96 , V_152 , V_108 ) ;
printf ( V_103 L_128 , V_96 , V_173 ? 'r' : ' ' ) ;
if ( ! V_174 ) {
if ( V_173 )
F_122 ( V_152 , V_108 ) ;
putchar ( ' ' ) ;
for ( V_60 = 0 ; V_60 < V_140 ; ++ V_60 )
printf ( L_129 , V_152 [ V_60 ] ) ;
for (; V_60 < V_108 ; ++ V_60 )
printf ( L_130 , V_175 [ V_168 ] ) ;
}
putchar ( ' ' ) ;
V_170 = V_108 ;
V_171 = 0 ;
for(; ; ) {
if( F_102 ( & V_140 ) ) {
for ( V_60 = 0 ; V_60 < V_108 ; ++ V_60 )
V_152 [ V_60 ] = V_140 >> ( V_60 * 8 ) ;
if ( ! V_173 )
F_122 ( V_152 , V_108 ) ;
F_67 ( V_96 , V_152 , V_108 ) ;
V_170 = V_108 ;
}
V_22 = F_74 () ;
if ( V_22 == '\n' )
break;
V_170 = 0 ;
switch ( V_22 ) {
case '\'' :
for(; ; ) {
V_140 = F_76 () ;
if( V_140 == '\\' )
V_140 = F_124 () ;
else if( V_140 == '\'' )
break;
for ( V_60 = 0 ; V_60 < V_108 ; ++ V_60 )
V_152 [ V_60 ] = V_140 >> ( V_60 * 8 ) ;
if ( ! V_173 )
F_122 ( V_152 , V_108 ) ;
F_67 ( V_96 , V_152 , V_108 ) ;
V_96 += V_108 ;
}
V_96 -= V_108 ;
V_170 = V_108 ;
break;
case ',' :
V_96 += V_108 ;
break;
case '.' :
V_174 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_50 :
F_110 () ;
return;
case 'b' :
case 'v' :
V_108 = 1 ;
break;
case 'w' :
V_108 = 2 ;
break;
case 'l' :
V_108 = 4 ;
break;
case 'u' :
V_108 = 8 ;
break;
case '^' :
V_96 -= V_108 ;
break;
break;
case '/' :
if ( V_171 > 0 )
V_96 -= 1 << V_171 ;
else
V_171 = 0 ;
V_171 += 4 ;
V_96 += 1 << V_171 ;
break;
case '\\' :
if ( V_171 < 0 )
V_96 += 1 << - V_171 ;
else
V_171 = 0 ;
V_171 -= 4 ;
V_96 -= 1 << - V_171 ;
break;
case 'm' :
F_102 ( ( void * ) & V_96 ) ;
break;
case 'n' :
V_174 = 1 ;
break;
case 'r' :
V_173 = ! V_173 ;
break;
case '<' :
V_140 = V_108 ;
F_102 ( & V_140 ) ;
V_96 -= V_140 ;
break;
case '>' :
V_140 = V_108 ;
F_102 ( & V_140 ) ;
V_96 += V_140 ;
break;
case '?' :
printf ( V_176 ) ;
break;
}
}
V_96 += V_170 ;
}
}
static int
F_124 ( void )
{
int V_177 ;
V_177 = F_76 () ;
switch( V_177 ) {
case 'n' : V_177 = '\n' ; break;
case 'r' : V_177 = '\r' ; break;
case 'b' : V_177 = '\b' ; break;
case 't' : V_177 = '\t' ; break;
}
return V_177 ;
}
static void F_125 ( unsigned long V_96 , long V_178 )
{
long V_140 , V_179 , V_180 , V_181 ;
unsigned char V_182 [ 16 ] ;
for ( V_140 = V_178 ; V_140 > 0 ; ) {
V_180 = V_140 < 16 ? V_140 : 16 ;
V_181 = F_65 ( V_96 , V_182 , V_180 ) ;
V_96 += V_181 ;
for ( V_179 = 0 ; V_179 < V_180 ; ++ V_179 ) {
if ( V_179 < V_181 )
printf ( L_129 , V_182 [ V_179 ] ) ;
else
printf ( L_130 , V_175 [ V_168 ] ) ;
}
V_140 -= V_180 ;
if ( V_181 < V_180 )
break;
}
printf ( L_32 ) ;
}
static void F_126 ( int V_29 )
{
struct V_183 * V_1 ;
if ( setjmp ( V_110 ) != 0 ) {
printf ( L_131 , V_29 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
V_1 = & V_184 [ V_29 ] ;
printf ( L_132 , V_29 , V_1 ) ;
printf ( L_133 , 16 , L_134 , F_127 ( V_29 ) ? L_135 : L_136 ) ;
printf ( L_133 , 16 , L_137 , F_128 ( V_29 ) ? L_135 : L_136 ) ;
printf ( L_133 , 16 , L_138 , F_129 ( V_29 ) ? L_135 : L_136 ) ;
#define F_130 ( V_184 , V_109 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 16, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_130 ( V_1 , V_185 , L_139 ) ;
F_130 ( V_1 , V_186 , L_139 ) ;
F_130 ( V_1 , V_187 , L_140 ) ;
F_130 ( V_1 , V_188 , L_140 ) ;
F_130 ( V_1 , V_189 , L_140 ) ;
#ifdef F_131
F_130 ( V_1 , V_190 , L_140 ) ;
F_130 ( V_1 , V_191 , L_140 ) ;
#endif
F_130 ( V_1 , V_192 , L_141 ) ;
F_130 ( V_1 , V_193 , L_140 ) ;
F_130 ( V_1 , V_194 , L_139 ) ;
F_130 ( V_1 , V_195 , L_139 ) ;
F_130 ( V_1 , V_196 , L_139 ) ;
F_130 ( V_1 , V_197 , L_141 ) ;
F_130 ( V_1 , V_198 , L_140 ) ;
F_130 ( V_1 , V_199 , L_140 ) ;
F_130 ( V_1 , V_200 , L_140 ) ;
F_130 ( V_1 , V_201 , L_139 ) ;
F_130 ( V_1 , V_136 , L_139 ) ;
F_130 ( V_1 , V_137 , L_139 ) ;
F_130 ( V_1 , V_202 , L_139 ) ;
F_130 ( V_1 , V_203 , L_139 ) ;
F_130 ( V_1 , V_204 , L_139 ) ;
#undef F_130
V_58 = 0 ;
F_1 () ;
}
static void F_132 ( void )
{
int V_29 ;
if ( F_133 () == 0 ) {
printf ( L_142 ) ;
return;
}
F_103 (cpu)
F_126 ( V_29 ) ;
}
static void F_134 ( void )
{
unsigned long V_205 ;
int V_177 ;
V_177 = F_76 () ;
if ( V_177 == 'a' ) {
F_132 () ;
return;
}
V_82 = V_177 ;
if ( F_102 ( & V_205 ) )
F_126 ( V_205 ) ;
else
F_126 ( V_40 ) ;
}
static void
F_82 ( void )
{
int V_177 ;
V_177 = F_76 () ;
#ifdef F_116
if ( V_177 == 'p' ) {
F_134 () ;
return;
}
#endif
if ( ( isxdigit ( V_177 ) && V_177 != 'f' && V_177 != 'd' ) || V_177 == '\n' )
V_82 = V_177 ;
F_102 ( ( void * ) & V_96 ) ;
if ( V_82 != '\n' )
V_82 = 0 ;
if ( V_177 == 'i' ) {
F_102 ( & V_206 ) ;
if ( V_206 == 0 )
V_206 = 16 ;
else if ( V_206 > V_207 )
V_206 = V_207 ;
V_96 += F_39 ( V_96 , V_206 , 1 ) ;
V_77 = L_143 ;
} else if ( V_177 == 'l' ) {
F_135 () ;
} else if ( V_177 == 'r' ) {
F_102 ( & V_178 ) ;
if ( V_178 == 0 )
V_178 = 64 ;
F_125 ( V_96 , V_178 ) ;
V_96 += V_178 ;
V_77 = L_144 ;
} else {
F_102 ( & V_178 ) ;
if ( V_178 == 0 )
V_178 = 64 ;
else if ( V_178 > V_207 )
V_178 = V_207 ;
F_136 ( V_96 , V_178 ) ;
V_96 += V_178 ;
V_77 = L_145 ;
}
}
static void
F_136 ( unsigned long V_96 , long V_178 )
{
long V_140 , V_179 , V_177 , V_180 , V_181 ;
unsigned char V_182 [ 16 ] ;
for ( V_140 = V_178 ; V_140 > 0 ; ) {
printf ( V_103 , V_96 ) ;
putchar ( ' ' ) ;
V_180 = V_140 < 16 ? V_140 : 16 ;
V_181 = F_65 ( V_96 , V_182 , V_180 ) ;
V_96 += V_181 ;
for ( V_179 = 0 ; V_179 < V_180 ; ++ V_179 ) {
if ( ( V_179 & ( sizeof( long ) - 1 ) ) == 0 && V_179 > 0 )
putchar ( ' ' ) ;
if ( V_179 < V_181 )
printf ( L_129 , V_182 [ V_179 ] ) ;
else
printf ( L_130 , V_175 [ V_168 ] ) ;
}
for (; V_179 < 16 ; ++ V_179 ) {
if ( ( V_179 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_60 ) ;
}
printf ( L_146 ) ;
for ( V_179 = 0 ; V_179 < V_180 ; ++ V_179 ) {
if ( V_179 < V_181 ) {
V_177 = V_182 [ V_179 ] ;
putchar ( ' ' <= V_177 && V_177 <= '~' ? V_177 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_140 -= V_180 ;
for (; V_179 < 16 ; ++ V_179 )
putchar ( ' ' ) ;
printf ( L_147 ) ;
if ( V_181 < V_180 )
break;
}
}
static int
F_137 ( unsigned long V_208 , long V_92 , int V_209 ,
T_3 V_210 )
{
int V_181 , V_211 ;
unsigned long V_212 ;
unsigned long V_213 , V_214 = 0 ;
unsigned char V_152 [ 4 ] ;
V_211 = 0 ;
for ( V_212 = V_208 ; V_92 > 0 ; -- V_92 , V_208 += 4 ) {
V_181 = F_65 ( V_208 , V_152 , 4 ) ;
if ( V_181 == 0 ) {
if ( V_209 ) {
const char * V_215 = V_175 [ V_168 ] ;
printf ( V_103 L_148 , V_208 , V_215 , V_215 , V_215 , V_215 ) ;
}
break;
}
V_213 = F_138 ( V_152 ) ;
if ( V_208 > V_212 && V_213 == V_214 ) {
if ( ! V_211 ) {
printf ( L_149 ) ;
V_211 = 1 ;
}
continue;
}
V_211 = 0 ;
V_214 = V_213 ;
if ( V_209 )
printf ( V_103 L_150 , V_208 , V_213 ) ;
printf ( L_151 ) ;
V_210 ( V_213 , V_208 ) ;
printf ( L_32 ) ;
}
return V_208 - V_212 ;
}
static int
F_39 ( unsigned long V_208 , long V_92 , int V_209 )
{
return F_137 ( V_208 , V_92 , V_209 , V_216 ) ;
}
void
F_139 ( unsigned long V_98 )
{
F_31 ( V_98 , L_152 , L_77 ) ;
}
void
F_135 ( void )
{
struct V_217 V_218 = { . V_219 = 1 } ;
unsigned char V_162 [ 128 ] ;
T_4 V_73 ;
if ( setjmp ( V_110 ) != 0 ) {
printf ( L_153 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
F_140 ( & V_218 ) ;
while ( F_141 ( & V_218 , false , V_162 , sizeof( V_162 ) , & V_73 ) ) {
V_162 [ V_73 ] = '\0' ;
printf ( L_130 , V_162 ) ;
}
F_1 () ;
F_117 ( 200 ) ;
V_58 = 0 ;
}
static void
F_77 ( int V_22 )
{
F_102 ( ( void * ) & V_220 ) ;
if( V_82 != '\n' )
V_82 = 0 ;
F_102 ( ( void * ) ( V_22 == 's' ? & V_221 : & V_222 ) ) ;
if( V_82 != '\n' )
V_82 = 0 ;
F_102 ( ( void * ) & V_223 ) ;
switch( V_22 ) {
case 'm' :
memmove ( ( void * ) V_220 , ( void * ) V_222 , V_223 ) ;
break;
case 's' :
memset ( ( void * ) V_220 , V_221 , V_223 ) ;
break;
case 'd' :
if( V_82 != '\n' )
V_82 = 0 ;
F_102 ( ( void * ) & V_224 ) ;
F_142 ( ( unsigned char * ) V_220 , ( unsigned char * ) V_222 , V_223 , V_224 ) ;
break;
}
}
static void
F_142 ( unsigned char * V_225 , unsigned char * V_226 , unsigned V_227 , unsigned V_228 )
{
unsigned V_140 , V_229 ;
V_229 = 0 ;
for( V_140 = V_227 ; V_140 > 0 ; -- V_140 )
if( * V_225 ++ != * V_226 ++ )
if( ++ V_229 <= V_228 )
printf ( L_154 , V_225 - 1 ,
V_225 [ - 1 ] , V_226 - 1 , V_226 [ - 1 ] ) ;
if( V_229 > V_228 )
printf ( L_155 , V_229 ) ;
}
static void
F_78 ( void )
{
unsigned V_65 , V_140 ;
unsigned char V_152 [ 4 ] ;
V_77 = L_156 ;
F_102 ( ( void * ) & V_220 ) ;
if ( V_82 != '\n' ) {
V_82 = 0 ;
F_102 ( ( void * ) & V_230 ) ;
if ( V_82 != '\n' ) {
V_82 = 0 ;
F_102 ( ( void * ) & V_221 ) ;
V_231 = ~ 0 ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_102 ( ( void * ) & V_231 ) ;
}
}
V_140 = 0 ;
for ( V_65 = V_220 ; V_65 < V_230 ; V_65 += 4 ) {
if ( F_65 ( V_65 , V_152 , 4 ) == 4
&& ( ( F_138 ( V_152 ) ^ V_221 ) & V_231 ) == 0 ) {
printf ( L_157 , V_65 , F_138 ( V_152 ) ) ;
if ( ++ V_140 >= 10 )
break;
}
}
}
static void
F_79 ( void )
{
unsigned char V_95 ;
unsigned V_65 ;
int V_232 , V_233 ;
F_102 ( & V_220 ) ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_102 ( & V_234 ) ;
if ( V_82 != '\n' ) V_82 = 0 ;
F_102 ( & V_235 ) ;
V_233 = 0 ;
for ( V_65 = V_220 ; V_65 < V_235 ; V_65 += V_234 ) {
V_232 = F_65 ( V_65 , & V_95 , 1 ) ;
if ( V_232 && ! V_233 ) {
printf ( L_158 , V_65 ) ;
} else if ( ! V_232 && V_233 )
printf ( L_159 , V_65 - V_234 ) ;
V_233 = V_232 ;
if ( V_65 + V_234 < V_65 )
break;
}
if ( V_233 )
printf ( L_159 , V_65 - V_234 ) ;
}
static void F_96 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_105 ;
int V_60 ;
typedef unsigned long (* T_5)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_5 V_236 ;
if ( ! F_102 ( & V_96 ) )
return;
if ( V_82 != '\n' )
V_82 = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 )
args [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 ) {
if ( ! F_102 ( & args [ V_60 ] ) || V_82 == '\n' )
break;
V_82 = 0 ;
}
V_236 = ( T_5 ) V_96 ;
V_105 = 0 ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_105 = V_236 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_1 () ;
printf ( L_160 , V_105 ) ;
} else {
printf ( L_161 , V_167 ) ;
}
V_58 = 0 ;
}
int
F_74 ( void )
{
int V_177 ;
if( V_82 != 0 ) {
V_177 = V_82 ;
V_82 = 0 ;
} else
V_177 = F_76 () ;
while( V_177 == ' ' || V_177 == '\t' )
V_177 = F_76 () ;
return V_177 ;
}
int
F_102 ( unsigned long * V_237 )
{
int V_177 , V_53 ;
unsigned long V_95 ;
V_177 = F_74 () ;
if ( V_177 == '%' ) {
char V_238 [ 8 ] ;
int V_60 ;
for ( V_60 = 0 ; V_60 < sizeof( V_238 ) - 1 ; ++ V_60 ) {
V_177 = F_76 () ;
if ( ! isalnum ( V_177 ) ) {
V_82 = V_177 ;
break;
}
V_238 [ V_60 ] = V_177 ;
}
V_238 [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < V_239 ; ++ V_60 ) {
if ( strcmp ( V_240 [ V_60 ] , V_238 ) == 0 ) {
if ( V_78 == NULL ) {
printf ( L_162 ) ;
return 0 ;
}
* V_237 = ( ( unsigned long * ) V_78 ) [ V_60 ] ;
return 1 ;
}
}
printf ( L_163 , V_238 ) ;
return 0 ;
}
if ( V_177 == '0' ) {
V_177 = F_76 () ;
if ( V_177 == 'x' ) {
V_177 = F_76 () ;
} else {
V_53 = F_143 ( V_177 ) ;
if ( V_53 == V_50 ) {
V_82 = V_177 ;
* V_237 = 0 ;
return 1 ;
}
}
} else if ( V_177 == '$' ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 63 ; V_60 ++ ) {
V_177 = F_76 () ;
if ( isspace ( V_177 ) ) {
V_82 = V_177 ;
break;
}
V_111 [ V_60 ] = V_177 ;
}
V_111 [ V_60 ++ ] = 0 ;
* V_237 = 0 ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
* V_237 = F_144 ( V_111 ) ;
F_1 () ;
}
V_58 = 0 ;
if ( ! ( * V_237 ) ) {
printf ( L_164 , V_111 ) ;
return 0 ;
}
return 1 ;
}
V_53 = F_143 ( V_177 ) ;
if ( V_53 == V_50 ) {
V_82 = V_177 ;
return 0 ;
}
V_95 = 0 ;
do {
V_95 = ( V_95 << 4 ) + V_53 ;
V_177 = F_76 () ;
V_53 = F_143 ( V_177 ) ;
} while ( V_53 != V_50 );
V_82 = V_177 ;
* V_237 = V_95 ;
return 1 ;
}
static void
F_110 ( void )
{
int V_177 ;
V_177 = V_82 ;
V_82 = 0 ;
while( V_177 != '\n' )
V_177 = F_76 () ;
}
static int F_143 ( int V_177 )
{
if( '0' <= V_177 && V_177 <= '9' )
return V_177 - '0' ;
if( 'A' <= V_177 && V_177 <= 'F' )
return V_177 - ( 'A' - 10 ) ;
if( 'a' <= V_177 && V_177 <= 'f' )
return V_177 - ( 'a' - 10 ) ;
return V_50 ;
}
void
F_145 ( char * V_241 , int V_108 )
{
int V_177 ;
V_177 = F_74 () ;
do {
if( V_108 > 1 ) {
* V_241 ++ = V_177 ;
-- V_108 ;
}
V_177 = F_76 () ;
} while( V_177 != ' ' && V_177 != '\t' && V_177 != '\n' );
V_82 = V_177 ;
* V_241 = 0 ;
}
static void
F_73 ( void )
{
V_242 = NULL ;
}
static int
F_76 ( void )
{
if ( V_242 == NULL || * V_242 == 0 ) {
if ( F_146 ( line , sizeof( line ) ) == NULL ) {
V_242 = NULL ;
return V_50 ;
}
V_242 = line ;
}
return * V_242 ++ ;
}
static void
F_75 ( char * V_243 )
{
V_242 = V_243 ;
}
static void
F_83 ( void )
{
int type = F_76 () ;
unsigned long V_98 ;
static char V_244 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_102 ( & V_98 ) )
F_31 ( V_98 , L_91 , L_32 ) ;
V_82 = 0 ;
break;
case 's' :
F_145 ( V_244 , 64 ) ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_98 = F_144 ( V_244 ) ;
if ( V_98 )
printf ( L_165 , V_244 , V_98 ) ;
else
printf ( L_166 , V_244 ) ;
F_1 () ;
}
V_58 = 0 ;
V_82 = 0 ;
break;
}
}
static void F_31 ( unsigned long V_32 , const char * V_245 ,
const char * V_246 )
{
char * V_247 ;
const char * V_109 = NULL ;
unsigned long V_27 , V_108 ;
printf ( V_103 , V_32 ) ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_109 = F_109 ( V_32 , & V_108 , & V_27 , & V_247 ,
V_111 ) ;
F_1 () ;
F_117 ( 200 ) ;
}
V_58 = 0 ;
if ( V_109 ) {
printf ( L_167 , V_245 , V_109 , V_27 , V_108 ) ;
if ( V_247 )
printf ( L_168 , V_247 ) ;
}
printf ( L_130 , V_246 ) ;
}
static void F_147 ( void )
{
int V_60 ;
unsigned long V_248 , V_249 , V_250 ;
unsigned long V_251 ;
printf ( L_169 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_252 ; V_60 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
V_250 = ( V_248 & V_253 ) ;
if ( V_250 | V_248 | V_249 ) {
printf ( L_170 , V_60 , V_248 , V_249 ) ;
if ( V_250 ) {
V_251 = V_249 & V_254 ;
if ( V_249 & V_255 ) {
printf ( L_171 ,
F_148 ( V_248 ) ,
( V_249 & ~ V_256 ) >> V_257 ,
V_251 ) ;
} else {
printf ( L_172 ,
F_149 ( V_248 ) ,
( V_249 & ~ V_256 ) >> V_258 ,
V_251 ) ;
}
} else
printf ( L_32 ) ;
}
}
}
static void F_150 ( void )
{
int V_60 ;
unsigned long * V_244 = ( unsigned long * ) V_135 -> V_191 ;
printf ( L_173 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_259 / 16 ; V_60 ++ ) {
unsigned long V_65 , V_260 ;
V_65 = * V_244 ++ ;
V_260 = * V_244 ++ ;
if ( V_65 || V_260 ) {
printf ( L_174 , V_60 , V_65 ) ;
printf ( L_175 , V_260 ) ;
}
}
}
void F_98 ( void )
{
if ( F_151 ( V_261 ) )
F_147 () ;
else
F_150 () ;
}
void F_98 ( void )
{
int V_60 ;
printf ( L_176 ) ;
for ( V_60 = 0 ; V_60 < 16 ; ++ V_60 )
printf ( L_34 , F_152 ( V_60 ) ) ;
printf ( L_32 ) ;
}
static void F_99 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_262 ; V_60 ++ ) {
unsigned long V_263 , V_264 , V_265 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_177 , V_60 , V_263 , V_264 , V_265 ) ;
if ( V_263 & V_266 ) {
printf ( L_178 ,
V_263 & V_267 ,
V_264 & V_268 ,
V_264 & V_269 ,
( V_265 & V_270 ) ? 'W' : 'w' ,
( V_265 & V_271 ) ? 'I' : 'i' ,
( V_265 & V_272 ) ? 'M' : 'm' ,
( V_265 & V_273 ) ? 'G' : 'g' ,
( V_265 & V_274 ) ? 'E' : 'e' ) ;
}
printf ( L_32 ) ;
}
}
static void F_100 ( void )
{
V_165 V_275 , V_276 , V_277 ;
V_166 V_278 ;
int V_60 , V_279 , V_280 , V_281 , V_282 , V_283 , V_284 = 0 ;
int V_285 ;
static const char * V_286 [] = {
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
V_275 = F_101 ( V_287 ) ;
V_285 = ( V_275 & 3 ) + 1 ;
V_280 = ( ( V_275 >> 2 ) & 3 ) + 1 ;
V_281 = ( ( V_275 >> 6 ) & 0x1f ) + 1 ;
V_282 = ( V_275 >> 24 ) & 0xf ;
V_283 = ( V_275 >> 16 ) & 0x7f ;
if ( ( V_285 > 1 ) && ( V_275 & 0x10000 ) )
V_284 = 1 ;
printf ( L_211 ,
V_285 , V_280 , V_281 , V_282 , V_283 ) ;
V_276 = ( 1ul << V_281 ) - 1 ;
V_277 = ( 1ul << V_282 ) - 1 ;
V_278 = ( 1ull << V_283 ) - 1 ;
for ( V_279 = 0 ; V_279 < V_280 ; V_279 ++ ) {
V_165 V_288 ;
int V_289 , V_290 , V_291 = 1 ;
printf ( L_212 , V_279 ) ;
switch( V_279 ) {
case 0 :
V_288 = F_101 ( V_292 ) ;
break;
case 1 :
V_288 = F_101 ( V_293 ) ;
break;
case 2 :
V_288 = F_101 ( V_294 ) ;
break;
case 3 :
V_288 = F_101 ( V_295 ) ;
break;
default:
printf ( L_213 ) ;
continue;
}
V_289 = V_288 & 0xfff ;
V_290 = ( V_288 >> 24 ) & 0xff ;
for ( V_60 = 0 ; V_60 < V_289 ; V_60 ++ ) {
V_165 V_296 = F_153 ( V_279 ) ;
V_165 V_297 = F_154 ( V_298 ) ;
V_166 V_299 = 0 ;
V_166 V_300 ;
int V_301 = V_60 , V_302 = V_60 ;
if ( V_290 != 0 ) {
V_302 = V_60 / V_290 ;
V_301 = V_60 % V_290 ;
V_299 = V_302 * 0x1000 ;
}
V_296 |= F_155 ( V_301 ) ;
F_70 ( V_303 , V_296 ) ;
F_70 ( V_304 , V_297 ) ;
F_70 ( V_305 , V_299 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_297 = F_101 ( V_304 ) ;
V_299 = F_101 ( V_305 ) ;
V_300 = F_101 ( V_306 ) ;
if ( V_290 && ( V_60 % V_290 ) == 0 )
V_291 = 1 ;
if ( ! ( V_297 & V_307 ) )
continue;
if ( V_290 == 0 )
printf ( L_214 , V_60 ) ;
else if ( V_291 )
printf ( L_215 , V_302 , 'A' + V_301 ) ;
else
printf ( L_216 , 'A' + V_301 ) ;
V_291 = 0 ;
printf ( L_217 ,
V_299 & ~ 0x3ffull ,
( V_297 >> 16 ) & 0x3fff ,
V_286 [ ( V_297 >> 7 ) & 0x1f ] ,
V_297 & V_308 ? 'I' : ' ' ,
V_297 & V_309 ? 'P' : ' ' ,
V_297 & V_310 ? '1' : '0' ) ;
printf ( L_218 ,
V_299 & V_311 ? 'a' : ' ' ,
V_299 & V_312 ? 'v' : ' ' ,
V_299 & V_313 ? 'w' : ' ' ,
V_299 & V_314 ? 'i' : ' ' ,
V_299 & V_315 ? 'm' : ' ' ,
V_299 & V_316 ? 'g' : ' ' ,
V_299 & V_317 ? 'e' : ' ' ) ;
printf ( L_219 , V_300 & V_278 & ~ 0x7ffull ) ;
if ( V_297 & V_308 )
printf ( L_220 ,
V_286 [ ( V_300 >> 1 ) & 0x1f ] ) ;
else
printf ( L_221 ,
V_300 & V_318 ? 'x' : ' ' ,
V_300 & V_319 ? 'w' : ' ' ,
V_300 & V_320 ? 'r' : ' ' ,
V_300 & V_321 ? 'x' : ' ' ,
V_300 & V_322 ? 'w' : ' ' ,
V_300 & V_323 ? 'r' : ' ' ) ;
}
}
}
static void F_156 ( int V_324 )
{
if ( V_324 ) {
V_325 = F_50 ;
V_326 = F_59 ;
V_327 = F_54 ;
V_328 = F_55 ;
V_329 = F_58 ;
V_330 = F_57 ;
V_331 = F_60 ;
} else {
V_325 = NULL ;
V_326 = NULL ;
V_327 = NULL ;
V_328 = NULL ;
V_329 = NULL ;
V_330 = NULL ;
V_331 = NULL ;
}
}
static void F_157 ( int V_332 )
{
F_156 ( 1 ) ;
F_158 ( F_53 () ) ;
}
static int T_6 F_159 ( void )
{
F_160 ( 'x' , & V_333 ) ;
return 0 ;
}
static int T_6 F_161 ( char * V_1 )
{
if ( ! V_1 || strncmp ( V_1 , L_222 , 5 ) == 0 ) {
F_156 ( 1 ) ;
V_334 = 1 ;
} else if ( strncmp ( V_1 , L_223 , 2 ) == 0 )
F_156 ( 1 ) ;
else if ( strncmp ( V_1 , L_224 , 3 ) == 0 )
V_335 = 1 ;
else if ( strncmp ( V_1 , L_225 , 4 ) == 0 )
V_79 = 1 ;
else
return 1 ;
return 0 ;
}
void T_6 F_162 ( void )
{
#ifdef F_163
if ( ! V_335 )
F_156 ( 1 ) ;
#endif
if ( V_334 )
F_158 ( NULL ) ;
}
void F_164 ( struct V_336 * V_337 )
{
struct V_338 * V_338 ;
F_165 (spu, list, full_list) {
if ( V_338 -> V_339 >= V_340 ) {
F_166 ( 1 ) ;
continue;
}
V_341 [ V_338 -> V_339 ] . V_338 = V_338 ;
V_341 [ V_338 -> V_339 ] . V_342 = 0 ;
V_341 [ V_338 -> V_339 ] . V_343 = ( unsigned long )
V_341 [ V_338 -> V_339 ] . V_338 -> V_344 ;
}
}
static void F_167 ( void )
{
struct V_338 * V_338 ;
int V_60 ;
V_166 V_244 ;
for ( V_60 = 0 ; V_60 < V_340 ; V_60 ++ ) {
if ( ! V_341 [ V_60 ] . V_338 )
continue;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_338 = V_341 [ V_60 ] . V_338 ;
V_341 [ V_60 ] . V_345 =
F_168 ( & V_338 -> V_346 -> V_347 ) ;
V_244 = F_169 ( V_338 ) ;
V_341 [ V_60 ] . V_348 = V_244 ;
V_244 &= ~ V_349 ;
F_170 ( V_338 , V_244 ) ;
F_1 () ;
F_117 ( 200 ) ;
V_341 [ V_60 ] . V_342 = 1 ;
printf ( L_226 , V_60 ,
V_341 [ V_60 ] . V_345 ?
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
struct V_338 * V_338 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_340 ; V_60 ++ ) {
if ( ! V_341 [ V_60 ] . V_338 )
continue;
if ( ! V_341 [ V_60 ] . V_342 ) {
printf ( L_230
L_231 , V_60 ) ;
continue;
}
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_338 = V_341 [ V_60 ] . V_338 ;
F_170 ( V_338 , V_341 [ V_60 ] . V_348 ) ;
F_172 ( & V_338 -> V_346 -> V_347 ,
V_341 [ V_60 ] . V_345 ) ;
F_1 () ;
F_117 ( 200 ) ;
printf ( L_232 , V_60 ) ;
} else {
V_58 = 0 ;
printf ( L_233 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_173 ( struct V_338 * V_338 )
{
printf ( L_234 , V_338 ) ;
F_174 ( V_338 , L_235 , V_339 ) ;
F_174 ( V_338 , L_130 , V_109 ) ;
F_174 ( V_338 , L_236 , V_350 ) ;
F_174 ( V_338 , L_237 , V_344 ) ;
F_174 ( V_338 , L_236 , V_351 ) ;
F_174 ( V_338 , L_235 , V_352 ) ;
F_174 ( V_338 , L_236 , V_28 ) ;
F_174 ( V_338 , L_238 , V_353 ) ;
F_174 ( V_338 , L_236 , V_354 ) ;
F_174 ( V_338 , L_236 , V_355 ) ;
F_174 ( V_338 , L_236 , V_356 ) ;
F_174 ( V_338 , L_236 , V_357 [ 0 ] ) ;
F_174 ( V_338 , L_236 , V_357 [ 1 ] ) ;
F_174 ( V_338 , L_236 , V_357 [ 2 ] ) ;
F_174 ( V_338 , L_235 , V_358 ) ;
F_174 ( V_338 , L_238 , V_138 ) ;
F_174 ( V_338 , L_237 , V_359 ) ;
F_174 ( V_338 , L_237 , V_360 ) ;
F_174 ( V_338 , L_237 , V_361 ) ;
F_174 ( V_338 , L_237 , V_362 ) ;
F_174 ( V_338 , L_236 , V_363 ) ;
F_174 ( V_338 , L_237 , V_346 ) ;
F_175 ( L_235 , V_346 -> V_347 ,
F_168 ( & V_338 -> V_346 -> V_347 ) ) ;
F_175 ( L_235 , V_346 -> V_364 ,
F_168 ( & V_338 -> V_346 -> V_364 ) ) ;
F_175 ( L_235 , V_346 -> V_365 ,
F_168 ( & V_338 -> V_346 -> V_365 ) ) ;
F_174 ( V_338 , L_237 , V_366 ) ;
F_174 ( V_338 , L_237 , V_367 ) ;
}
int
F_176 ( unsigned long V_208 , long V_92 , int V_209 )
{
return F_137 ( V_208 , V_92 , V_209 , V_368 ) ;
}
static void F_177 ( unsigned long V_205 , int V_369 )
{
unsigned long V_27 , V_98 , V_370 ;
if ( setjmp ( V_110 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_370 = ( unsigned long ) V_341 [ V_205 ] . V_338 -> V_344 ;
F_1 () ;
F_117 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_239 , V_205 ) ;
return;
}
V_58 = 0 ;
if ( F_102 ( & V_27 ) )
V_98 = V_370 + V_27 ;
else
V_98 = V_341 [ V_205 ] . V_343 ;
if ( V_98 >= V_370 + V_371 ) {
printf ( L_240 ) ;
return;
}
switch ( V_369 ) {
case 'i' :
V_98 += F_176 ( V_98 , 16 , 1 ) ;
V_77 = L_241 ;
break;
default:
F_136 ( V_98 , 64 ) ;
V_98 += 64 ;
V_77 = L_242 ;
break;
}
V_341 [ V_205 ] . V_343 = V_98 ;
}
static int F_88 ( void )
{
static unsigned long V_205 = 0 ;
int V_22 , V_369 = 0 ;
V_22 = F_76 () ;
switch ( V_22 ) {
case 's' :
F_167 () ;
break;
case 'r' :
F_171 () ;
break;
case 'd' :
V_369 = F_76 () ;
if ( isxdigit ( V_369 ) || V_369 == '\n' )
V_82 = V_369 ;
case 'f' :
F_102 ( & V_205 ) ;
if ( V_205 >= V_340 || ! V_341 [ V_205 ] . V_338 ) {
printf ( L_243 ) ;
return 0 ;
}
switch ( V_22 ) {
case 'f' :
F_173 ( V_341 [ V_205 ] . V_338 ) ;
break;
default:
F_177 ( V_205 , V_369 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_88 ( void )
{
return - 1 ;
}
