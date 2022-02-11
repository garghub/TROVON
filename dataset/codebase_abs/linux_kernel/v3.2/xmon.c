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
F_68 ( V_55 . V_32 | ( V_55 . V_56 & 7 ) ) ;
if ( V_57 && F_69 ( V_69 ) )
F_70 ( V_70 , V_57 -> V_32
| ( V_57 -> V_56 & ( V_68 | V_71 ) ) ) ;
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
F_68 ( 0 ) ;
if ( F_69 ( V_69 ) )
F_70 ( V_70 , 0 ) ;
}
static int
F_40 ( struct V_15 * V_51 )
{
int V_22 = 0 ;
V_72 = NULL ;
V_73 = V_51 ;
if ( ! V_74 ) {
V_74 = 1 ;
F_71 ( V_51 -> V_75 [ 1 ] , V_51 -> V_76 , V_51 -> V_31 ) ;
}
for(; ; ) {
#ifdef F_19
printf ( L_25 , F_11 () ) ;
#endif
printf ( L_26 ) ;
F_72 () ;
V_77 = 0 ;
V_22 = F_73 () ;
if( V_22 == '\n' ) {
if ( V_72 == NULL )
continue;
F_74 ( V_72 ) ;
V_72 = NULL ;
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
V_77 = V_22 ;
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
F_90 ( V_78 ) ;
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
#endif
#ifdef V_17
case 'u' :
F_98 () ;
break;
#endif
#ifdef F_99
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
F_70 ( V_79 , F_101 ( V_79 ) | V_80 | V_81 ) ;
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
V_16 -> V_19 |= V_82 ;
return 1 ;
}
static void F_94 ( void )
{
int V_22 ;
V_22 = F_75 () ;
if ( V_22 == 'r' )
V_83 . V_84 ( NULL ) ;
else if ( V_22 == 'h' )
V_83 . V_85 () ;
else if ( V_22 == 'p' )
V_83 . V_86 () ;
}
static int F_93 ( void )
{
#ifdef F_19
unsigned long V_29 ;
int V_12 ;
int V_87 ;
if ( ! F_102 ( & V_29 ) ) {
printf ( L_33 ) ;
V_87 = 0 ;
for ( V_29 = 0 ; V_29 < V_88 ; ++ V_29 ) {
if ( F_24 ( V_29 , & V_14 ) ) {
if ( V_87 == 0 )
printf ( L_34 , V_29 ) ;
++ V_87 ;
} else {
if ( V_87 > 1 )
printf ( L_35 , V_29 - 1 ) ;
V_87 = 0 ;
}
}
if ( V_87 > 1 )
printf ( L_35 , V_88 - 1 ) ;
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
unsigned short V_89 ;
unsigned char V_90 ;
if ( ! F_102 ( & V_91 ) )
return;
if ( ! F_102 ( & V_92 ) )
return;
V_89 = 0xffff ;
for ( V_60 = 0 ; V_60 < V_92 ; ++ V_60 ) {
if ( F_65 ( V_91 + V_60 , & V_90 , 1 ) == 0 ) {
printf ( L_38 , V_91 + V_60 ) ;
break;
}
V_89 = F_103 ( V_89 , V_90 ) ;
}
printf ( L_39 , V_89 ) ;
}
static long F_104 ( unsigned long V_93 )
{
unsigned int V_48 ;
V_93 &= ~ 3 ;
if ( ! F_105 ( V_93 ) ) {
printf ( L_40 ) ;
return 0 ;
}
if ( ! F_65 ( V_93 , & V_48 , sizeof( V_48 ) ) ) {
printf ( L_41 , V_93 ) ;
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
int V_94 , V_60 ;
struct V_23 * V_24 ;
const char V_95 [] = L_44
L_45 ;
V_22 = F_75 () ;
switch ( V_22 ) {
#ifndef F_106
case 'd' :
V_94 = 7 ;
V_22 = F_75 () ;
if ( V_22 == 'r' )
V_94 = 5 ;
else if ( V_22 == 'w' )
V_94 = 6 ;
else
V_77 = V_22 ;
V_55 . V_32 = 0 ;
V_55 . V_56 = 0 ;
if ( F_102 ( & V_55 . V_32 ) ) {
if ( ! F_105 ( V_55 . V_32 ) ) {
printf ( V_95 ) ;
break;
}
V_55 . V_32 &= ~ 7 ;
V_55 . V_56 = V_94 | V_96 ;
}
break;
case 'i' :
if ( ! F_69 ( V_69 ) ) {
printf ( L_46
L_47 ) ;
break;
}
if ( V_57 ) {
V_57 -> V_56 &= ~ ( V_68 | V_71 ) ;
V_57 = NULL ;
}
if ( ! F_102 ( & V_65 ) )
break;
if ( ! F_104 ( V_65 ) )
break;
V_24 = F_63 ( V_65 ) ;
if ( V_24 != NULL ) {
V_24 -> V_56 |= V_68 | V_71 ;
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
V_77 = V_22 ;
V_22 = F_73 () ;
if ( V_22 == '?' ) {
printf ( V_97 ) ;
break;
}
V_77 = V_22 ;
if ( ! F_102 ( & V_65 ) ) {
printf ( L_51 ) ;
if ( V_55 . V_56 ) {
printf ( L_52 V_98 L_53 , V_55 . V_32 ) ;
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
const char * F_26 ( unsigned long V_99 )
{
char * V_100 ;
switch ( V_99 ) {
case 0x100 : V_100 = L_61 ; break;
case 0x200 : V_100 = L_62 ; break;
case 0x300 : V_100 = L_63 ; break;
case 0x380 : V_100 = L_64 ; break;
case 0x400 : V_100 = L_65 ; break;
case 0x480 : V_100 = L_66 ; break;
case 0x500 : V_100 = L_67 ; break;
case 0x600 : V_100 = L_68 ; break;
case 0x700 : V_100 = L_69 ; break;
case 0x800 : V_100 = L_70 ; break;
case 0x900 : V_100 = L_71 ; break;
case 0xc00 : V_100 = L_72 ; break;
case 0xd00 : V_100 = L_73 ; break;
case 0xf00 : V_100 = L_74 ; break;
case 0xf20 : V_100 = L_75 ; break;
case 0x1300 : V_100 = L_76 ; break;
default: V_100 = L_77 ;
}
return V_100 ;
}
static void F_107 ( unsigned long V_59 , unsigned long * V_101 ,
unsigned long * V_102 )
{
unsigned long V_103 , V_27 ;
const char * V_104 ;
* V_101 = * V_102 = 0 ;
if ( V_59 == 0 )
return;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_104 = F_108 ( V_59 , & V_103 , & V_27 , NULL , V_106 ) ;
if ( V_104 != NULL ) {
* V_101 = V_59 - V_27 ;
* V_102 = V_59 - V_27 + V_103 ;
}
F_1 () ;
}
V_58 = 0 ;
}
static void F_71 ( unsigned long V_107 , unsigned long V_108 ,
unsigned long V_59 )
{
unsigned long V_109 ;
unsigned long V_110 ;
unsigned long V_111 ;
int V_87 = 0 ;
struct V_15 V_16 ;
do {
if ( V_107 < V_112 ) {
if ( V_107 != 0 )
printf ( L_78 , V_107 ) ;
break;
}
if ( ! F_65 ( V_107 + V_113 , & V_109 , sizeof( unsigned long ) )
|| ! F_65 ( V_107 , & V_110 , sizeof( unsigned long ) ) ) {
printf ( L_79 , V_107 ) ;
break;
}
if ( ( V_59 | V_108 ) != 0 ) {
unsigned long V_114 , V_115 ;
unsigned long V_116 ;
int V_117 = 1 ;
F_107 ( V_59 , & V_114 , & V_115 ) ;
V_116 = 0 ;
if ( V_110 > V_107 )
F_65 ( V_110 + V_113 , & V_116 ,
sizeof( unsigned long ) ) ;
if ( V_108 == V_109 ) {
if ( V_108 < V_112
|| ( V_114 <= V_108 && V_108 < V_115 ) )
V_117 = 0 ;
} else if ( V_108 == V_116 ) {
V_117 = 0 ;
} else if ( V_108 >= V_112
&& ! ( V_114 <= V_108 && V_108 < V_115 ) ) {
printf ( L_80 ) ;
F_31 ( V_108 , L_7 , L_32 ) ;
}
if ( V_117 ) {
printf ( L_81 V_98 L_82 , V_107 ) ;
F_31 ( V_109 , L_7 , L_83 ) ;
}
V_59 = V_108 = 0 ;
} else {
printf ( L_81 V_98 L_82 , V_107 ) ;
F_31 ( V_109 , L_7 , L_32 ) ;
}
if ( F_65 ( V_107 + V_118 , & V_111 , sizeof( unsigned long ) )
&& V_111 == V_119 ) {
if ( F_65 ( V_107 + V_120 , & V_16 , sizeof( V_16 ) )
!= sizeof( V_16 ) ) {
printf ( L_84 ,
V_107 + V_120 ) ;
break;
}
printf ( L_85 , V_16 . V_34 ,
F_26 ( F_27 ( & V_16 ) ) ) ;
V_59 = V_16 . V_31 ;
V_108 = V_16 . V_76 ;
F_31 ( V_59 , L_7 , L_32 ) ;
}
if ( V_110 == 0 )
break;
V_107 = V_110 ;
} while ( V_87 ++ < V_121 );
}
static void F_85 ( struct V_15 * V_51 )
{
unsigned long V_107 ;
if ( F_102 ( & V_107 ) )
F_71 ( V_107 , 0 , 0 ) ;
else
F_71 ( V_51 -> V_75 [ 1 ] , V_51 -> V_76 , V_51 -> V_31 ) ;
F_109 () ;
}
static void F_110 ( struct V_15 * V_16 )
{
#ifdef F_111
const struct V_122 * V_123 ;
unsigned long V_93 ;
if ( V_16 -> V_19 & V_43 )
return;
V_93 = V_16 -> V_31 ;
if ( V_93 < V_112 )
return;
V_123 = F_112 ( V_16 -> V_31 ) ;
if ( V_123 == NULL )
return;
if ( F_113 ( V_123 ) )
return;
#ifdef F_114
printf ( L_86 ,
V_123 -> V_124 , V_123 -> line ) ;
#else
printf ( L_87 , ( void * ) V_123 -> V_125 ) ;
#endif
#endif
}
static void F_25 ( struct V_15 * V_126 )
{
unsigned long V_34 ;
#ifdef F_19
printf ( L_88 , F_11 () ) ;
#endif
V_34 = F_27 ( V_126 ) ;
printf ( L_89 , V_126 -> V_34 , F_26 ( V_34 ) , V_126 ) ;
printf ( L_90 ) ;
F_31 ( V_126 -> V_31 , L_91 , L_32 ) ;
printf ( L_92 , V_126 -> V_76 ) ;
F_31 ( V_126 -> V_76 , L_91 , L_32 ) ;
printf ( L_93 , V_126 -> V_75 [ 1 ] ) ;
printf ( L_94 , V_126 -> V_19 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 ) {
printf ( L_95 , V_126 -> V_127 ) ;
if ( V_34 != 0x380 )
printf ( L_96 , V_126 -> V_128 ) ;
}
printf ( L_97 , V_129 ) ;
#ifdef F_115
printf ( L_98 , F_116 () ) ;
#endif
if ( V_129 ) {
printf ( L_99 ,
V_129 -> V_130 , V_129 -> V_131 ) ;
}
if ( V_34 == 0x700 )
F_110 ( V_126 ) ;
}
static void F_83 ( struct V_15 * V_126 )
{
int V_132 , V_34 ;
unsigned long V_133 ;
struct V_15 V_16 ;
if ( F_102 ( & V_133 ) ) {
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_16 = * (struct V_15 * ) V_133 ;
F_1 () ;
F_117 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_100 V_98 L_32 ,
V_133 ) ;
return;
}
V_58 = 0 ;
V_126 = & V_16 ;
}
#ifdef F_115
if ( F_118 ( V_126 ) ) {
for ( V_132 = 0 ; V_132 < 16 ; ++ V_132 )
printf ( L_101 V_98 L_102 V_98 L_32 ,
V_132 , V_126 -> V_75 [ V_132 ] , V_132 + 16 , V_126 -> V_75 [ V_132 + 16 ] ) ;
} else {
for ( V_132 = 0 ; V_132 < 7 ; ++ V_132 )
printf ( L_101 V_98 L_102 V_98 L_32 ,
V_132 , V_126 -> V_75 [ V_132 ] , V_132 + 7 , V_126 -> V_75 [ V_132 + 7 ] ) ;
}
#else
for ( V_132 = 0 ; V_132 < 32 ; ++ V_132 ) {
printf ( L_103 , V_132 , V_126 -> V_75 [ V_132 ] ,
( V_132 & 3 ) == 3 ? L_32 : L_104 ) ;
if ( V_132 == 12 && ! F_118 ( V_126 ) ) {
printf ( L_32 ) ;
break;
}
}
#endif
printf ( L_105 ) ;
F_31 ( V_126 -> V_31 , L_7 , L_32 ) ;
if ( F_27 ( V_126 ) != 0xc00 && F_69 ( V_134 ) ) {
printf ( L_106 ) ;
F_31 ( V_126 -> V_135 , L_7 , L_32 ) ;
}
printf ( L_107 ) ;
F_31 ( V_126 -> V_76 , L_7 , L_32 ) ;
printf ( L_108 V_98 L_109 , V_126 -> V_19 , V_126 -> V_136 ) ;
printf ( L_110 V_98 L_111 V_98 L_112 ,
V_126 -> V_137 , V_126 -> V_138 , V_126 -> V_34 ) ;
V_34 = F_27 ( V_126 ) ;
if ( V_34 == 0x300 || V_34 == 0x380 || V_34 == 0x600 )
printf ( L_113 V_98 L_114 , V_126 -> V_127 , V_126 -> V_128 ) ;
}
static void F_86 ( void )
{
int V_22 ;
unsigned long V_139 ;
V_22 = F_75 () ;
if ( V_22 != 'i' )
V_77 = V_22 ;
F_102 ( ( void * ) & V_91 ) ;
if ( V_77 != '\n' )
V_77 = 0 ;
V_139 = 1 ;
F_102 ( & V_139 ) ;
V_139 = ( V_139 + V_140 - 1 ) / V_140 ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
if ( V_22 != 'i' ) {
for (; V_139 > 0 ; -- V_139 , V_91 += V_140 )
F_3 ( ( void * ) V_91 ) ;
} else {
for (; V_139 > 0 ; -- V_139 , V_91 += V_140 )
F_4 ( ( void * ) V_91 ) ;
}
F_1 () ;
F_117 ( 200 ) ;
}
V_58 = 0 ;
}
static unsigned long
F_119 ( int V_132 )
{
unsigned int V_141 [ 2 ] ;
unsigned long ( * V_142 ) ( void ) ;
unsigned long V_100 = - 1UL ;
#ifdef F_115
unsigned long V_143 [ 3 ] ;
V_143 [ 0 ] = ( unsigned long ) V_141 ;
V_143 [ 1 ] = 0 ;
V_143 [ 2 ] = 0 ;
V_142 = ( unsigned long ( * ) ( void ) ) V_143 ;
#else
V_142 = ( unsigned long ( * ) ( void ) ) V_141 ;
#endif
V_141 [ 0 ] = 0x7c6002a6 + ( ( V_132 & 0x1F ) << 16 ) + ( ( V_132 & 0x3e0 ) << 6 ) ;
V_141 [ 1 ] = 0x4e800020 ;
F_2 ( V_141 ) ;
F_2 ( V_141 + 1 ) ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_100 = V_142 () ;
F_1 () ;
F_117 ( 200 ) ;
V_132 = V_103 ;
}
return V_100 ;
}
static void
F_120 ( int V_132 , unsigned long V_144 )
{
unsigned int V_141 [ 2 ] ;
unsigned long ( * V_142 ) ( unsigned long ) ;
#ifdef F_115
unsigned long V_143 [ 3 ] ;
V_143 [ 0 ] = ( unsigned long ) V_141 ;
V_143 [ 1 ] = 0 ;
V_143 [ 2 ] = 0 ;
V_142 = ( unsigned long (*) ( unsigned long ) ) V_143 ;
#else
V_142 = ( unsigned long (*) ( unsigned long ) ) V_141 ;
#endif
V_141 [ 0 ] = 0x7c6003a6 + ( ( V_132 & 0x1F ) << 16 ) + ( ( V_132 & 0x3e0 ) << 6 ) ;
V_141 [ 1 ] = 0x4e800020 ;
F_2 ( V_141 ) ;
F_2 ( V_141 + 1 ) ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_142 ( V_144 ) ;
F_1 () ;
F_117 ( 200 ) ;
V_132 = V_103 ;
}
}
static void F_84 ( void )
{
int V_22 ;
unsigned long V_144 ;
V_22 = F_73 () ;
if ( V_22 == '\n' ) {
unsigned long V_107 , V_145 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_115 V_98 L_116 V_98 L_32 ,
F_121 () , F_101 ( V_146 ) ) ;
printf ( L_117 V_98 L_118 V_98 L_32 ,
F_101 ( V_147 ) , F_101 ( V_148 ) ) ;
printf ( L_119 V_98 L_120 V_98 L_32 ,
F_101 ( V_149 ) , F_101 ( V_150 ) ) ;
printf ( L_121 V_98 L_122 V_98 L_32 , V_107 , F_101 ( V_151 ) ) ;
printf ( L_123 V_98 L_124 V_98 L_32 , V_145 , F_101 ( V_152 ) ) ;
#ifdef F_122
if ( F_123 ( V_153 ) ) {
struct V_154 * V_155 ;
struct V_156 * V_157 ;
printf ( L_125 ) ;
V_155 = F_116 () ;
printf ( L_126 ) ;
V_157 = V_155 -> V_158 ;
printf ( L_127 ,
V_157 -> V_159 , V_157 -> V_160 ) ;
printf ( L_128 ,
V_157 -> V_161 , V_157 -> V_162 ) ;
printf ( L_129 ,
V_157 -> V_163 . V_164 ) ;
}
#endif
return;
}
F_102 ( & V_165 ) ;
switch ( V_22 ) {
case 'w' :
V_144 = F_119 ( V_165 ) ;
F_102 ( & V_144 ) ;
F_120 ( V_165 , V_144 ) ;
case 'r' :
printf ( L_130 , V_165 , F_119 ( V_165 ) ) ;
break;
}
F_109 () ;
}
static int
F_65 ( unsigned long V_91 , void * V_166 , int V_103 )
{
volatile int V_132 ;
char * V_1 , * V_167 ;
V_132 = 0 ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_91 ;
V_167 = ( char * ) V_166 ;
switch ( V_103 ) {
case 2 :
* ( V_168 * ) V_167 = * ( V_168 * ) V_1 ;
break;
case 4 :
* ( V_169 * ) V_167 = * ( V_169 * ) V_1 ;
break;
case 8 :
* ( V_170 * ) V_167 = * ( V_170 * ) V_1 ;
break;
default:
for( ; V_132 < V_103 ; ++ V_132 ) {
* V_167 ++ = * V_1 ++ ;
F_1 () ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_132 = V_103 ;
}
V_58 = 0 ;
return V_132 ;
}
static int
F_67 ( unsigned long V_91 , void * V_166 , int V_103 )
{
volatile int V_132 ;
char * V_1 , * V_167 ;
V_132 = 0 ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_1 = ( char * ) V_91 ;
V_167 = ( char * ) V_166 ;
switch ( V_103 ) {
case 2 :
* ( V_168 * ) V_1 = * ( V_168 * ) V_167 ;
break;
case 4 :
* ( V_169 * ) V_1 = * ( V_169 * ) V_167 ;
break;
case 8 :
* ( V_170 * ) V_1 = * ( V_170 * ) V_167 ;
break;
default:
for ( ; V_132 < V_103 ; ++ V_132 ) {
* V_1 ++ = * V_167 ++ ;
F_1 () ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_132 = V_103 ;
} else {
printf ( L_131 , V_91 + V_132 ) ;
}
V_58 = 0 ;
return V_132 ;
}
static int F_61 ( struct V_15 * V_16 )
{
V_171 = F_27 ( V_16 ) ;
switch ( F_27 ( V_16 ) ) {
case 0x200 :
V_172 = 0 ;
break;
case 0x300 :
case 0x380 :
V_172 = 1 ;
break;
default:
V_172 = 2 ;
}
longjmp ( V_105 , 1 ) ;
return 0 ;
}
static void
F_124 ( unsigned char * V_144 , int V_103 )
{
int V_173 ;
switch ( V_103 ) {
case 2 :
F_125 ( V_144 [ 0 ] , V_144 [ 1 ] , V_173 ) ;
break;
case 4 :
F_125 ( V_144 [ 0 ] , V_144 [ 3 ] , V_173 ) ;
F_125 ( V_144 [ 1 ] , V_144 [ 2 ] , V_173 ) ;
break;
case 8 :
F_125 ( V_144 [ 0 ] , V_144 [ 7 ] , V_173 ) ;
F_125 ( V_144 [ 1 ] , V_144 [ 6 ] , V_173 ) ;
F_125 ( V_144 [ 2 ] , V_144 [ 5 ] , V_173 ) ;
F_125 ( V_144 [ 3 ] , V_144 [ 4 ] , V_173 ) ;
break;
}
}
static void
F_80 ( void )
{
int V_22 , V_174 , V_60 , V_175 ;
unsigned long V_132 ;
unsigned char V_144 [ 16 ] ;
F_102 ( ( void * ) & V_91 ) ;
V_22 = F_73 () ;
if ( V_22 == '?' ) {
printf ( V_176 ) ;
return;
} else {
V_77 = V_22 ;
}
V_72 = L_132 ;
while ( ( V_22 = F_73 () ) != '\n' ) {
switch( V_22 ) {
case 'b' : V_103 = 1 ; break;
case 'w' : V_103 = 2 ; break;
case 'l' : V_103 = 4 ; break;
case 'd' : V_103 = 8 ; break;
case 'r' : V_177 = ! V_177 ; break;
case 'n' : V_178 = 1 ; break;
case '.' : V_178 = 0 ; break;
}
}
if( V_103 <= 0 )
V_103 = 1 ;
else if( V_103 > 8 )
V_103 = 8 ;
for(; ; ) {
if ( ! V_178 )
V_132 = F_65 ( V_91 , V_144 , V_103 ) ;
printf ( V_98 L_133 , V_91 , V_177 ? 'r' : ' ' ) ;
if ( ! V_178 ) {
if ( V_177 )
F_124 ( V_144 , V_103 ) ;
putchar ( ' ' ) ;
for ( V_60 = 0 ; V_60 < V_132 ; ++ V_60 )
printf ( L_134 , V_144 [ V_60 ] ) ;
for (; V_60 < V_103 ; ++ V_60 )
printf ( L_135 , V_179 [ V_172 ] ) ;
}
putchar ( ' ' ) ;
V_174 = V_103 ;
V_175 = 0 ;
for(; ; ) {
if( F_102 ( & V_132 ) ) {
for ( V_60 = 0 ; V_60 < V_103 ; ++ V_60 )
V_144 [ V_60 ] = V_132 >> ( V_60 * 8 ) ;
if ( ! V_177 )
F_124 ( V_144 , V_103 ) ;
F_67 ( V_91 , V_144 , V_103 ) ;
V_174 = V_103 ;
}
V_22 = F_73 () ;
if ( V_22 == '\n' )
break;
V_174 = 0 ;
switch ( V_22 ) {
case '\'' :
for(; ; ) {
V_132 = F_75 () ;
if( V_132 == '\\' )
V_132 = F_126 () ;
else if( V_132 == '\'' )
break;
for ( V_60 = 0 ; V_60 < V_103 ; ++ V_60 )
V_144 [ V_60 ] = V_132 >> ( V_60 * 8 ) ;
if ( ! V_177 )
F_124 ( V_144 , V_103 ) ;
F_67 ( V_91 , V_144 , V_103 ) ;
V_91 += V_103 ;
}
V_91 -= V_103 ;
V_174 = V_103 ;
break;
case ',' :
V_91 += V_103 ;
break;
case '.' :
V_178 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_50 :
F_109 () ;
return;
case 'b' :
case 'v' :
V_103 = 1 ;
break;
case 'w' :
V_103 = 2 ;
break;
case 'l' :
V_103 = 4 ;
break;
case 'u' :
V_103 = 8 ;
break;
case '^' :
V_91 -= V_103 ;
break;
break;
case '/' :
if ( V_175 > 0 )
V_91 -= 1 << V_175 ;
else
V_175 = 0 ;
V_175 += 4 ;
V_91 += 1 << V_175 ;
break;
case '\\' :
if ( V_175 < 0 )
V_91 += 1 << - V_175 ;
else
V_175 = 0 ;
V_175 -= 4 ;
V_91 -= 1 << - V_175 ;
break;
case 'm' :
F_102 ( ( void * ) & V_91 ) ;
break;
case 'n' :
V_178 = 1 ;
break;
case 'r' :
V_177 = ! V_177 ;
break;
case '<' :
V_132 = V_103 ;
F_102 ( & V_132 ) ;
V_91 -= V_132 ;
break;
case '>' :
V_132 = V_103 ;
F_102 ( & V_132 ) ;
V_91 += V_132 ;
break;
case '?' :
printf ( V_180 ) ;
break;
}
}
V_91 += V_174 ;
}
}
static int
F_126 ( void )
{
int V_181 ;
V_181 = F_75 () ;
switch( V_181 ) {
case 'n' : V_181 = '\n' ; break;
case 'r' : V_181 = '\r' ; break;
case 'b' : V_181 = '\b' ; break;
case 't' : V_181 = '\t' ; break;
}
return V_181 ;
}
static void F_127 ( unsigned long V_91 , long V_182 )
{
long V_132 , V_183 , V_184 , V_185 ;
unsigned char V_186 [ 16 ] ;
for ( V_132 = V_182 ; V_132 > 0 ; ) {
V_184 = V_132 < 16 ? V_132 : 16 ;
V_185 = F_65 ( V_91 , V_186 , V_184 ) ;
V_91 += V_185 ;
for ( V_183 = 0 ; V_183 < V_184 ; ++ V_183 ) {
if ( V_183 < V_185 )
printf ( L_134 , V_186 [ V_183 ] ) ;
else
printf ( L_135 , V_179 [ V_172 ] ) ;
}
V_132 -= V_184 ;
if ( V_185 < V_184 )
break;
}
printf ( L_32 ) ;
}
static void
F_81 ( void )
{
int V_181 ;
V_181 = F_75 () ;
if ( ( isxdigit ( V_181 ) && V_181 != 'f' && V_181 != 'd' ) || V_181 == '\n' )
V_77 = V_181 ;
F_102 ( ( void * ) & V_91 ) ;
if ( V_77 != '\n' )
V_77 = 0 ;
if ( V_181 == 'i' ) {
F_102 ( & V_187 ) ;
if ( V_187 == 0 )
V_187 = 16 ;
else if ( V_187 > V_188 )
V_187 = V_188 ;
V_91 += F_39 ( V_91 , V_187 , 1 ) ;
V_72 = L_136 ;
} else if ( V_181 == 'l' ) {
F_128 () ;
} else if ( V_181 == 'r' ) {
F_102 ( & V_182 ) ;
if ( V_182 == 0 )
V_182 = 64 ;
F_127 ( V_91 , V_182 ) ;
V_91 += V_182 ;
V_72 = L_137 ;
} else {
F_102 ( & V_182 ) ;
if ( V_182 == 0 )
V_182 = 64 ;
else if ( V_182 > V_188 )
V_182 = V_188 ;
F_129 ( V_91 , V_182 ) ;
V_91 += V_182 ;
V_72 = L_138 ;
}
}
static void
F_129 ( unsigned long V_91 , long V_182 )
{
long V_132 , V_183 , V_181 , V_184 , V_185 ;
unsigned char V_186 [ 16 ] ;
for ( V_132 = V_182 ; V_132 > 0 ; ) {
printf ( V_98 , V_91 ) ;
putchar ( ' ' ) ;
V_184 = V_132 < 16 ? V_132 : 16 ;
V_185 = F_65 ( V_91 , V_186 , V_184 ) ;
V_91 += V_185 ;
for ( V_183 = 0 ; V_183 < V_184 ; ++ V_183 ) {
if ( ( V_183 & ( sizeof( long ) - 1 ) ) == 0 && V_183 > 0 )
putchar ( ' ' ) ;
if ( V_183 < V_185 )
printf ( L_134 , V_186 [ V_183 ] ) ;
else
printf ( L_135 , V_179 [ V_172 ] ) ;
}
for (; V_183 < 16 ; ++ V_183 ) {
if ( ( V_183 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_60 ) ;
}
printf ( L_139 ) ;
for ( V_183 = 0 ; V_183 < V_184 ; ++ V_183 ) {
if ( V_183 < V_185 ) {
V_181 = V_186 [ V_183 ] ;
putchar ( ' ' <= V_181 && V_181 <= '~' ? V_181 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_132 -= V_184 ;
for (; V_183 < 16 ; ++ V_183 )
putchar ( ' ' ) ;
printf ( L_140 ) ;
if ( V_185 < V_184 )
break;
}
}
static int
F_130 ( unsigned long V_189 , long V_87 , int V_190 ,
T_2 V_191 )
{
int V_185 , V_192 ;
unsigned long V_193 ;
unsigned long V_194 , V_195 = 0 ;
unsigned char V_144 [ 4 ] ;
V_192 = 0 ;
for ( V_193 = V_189 ; V_87 > 0 ; -- V_87 , V_189 += 4 ) {
V_185 = F_65 ( V_189 , V_144 , 4 ) ;
if ( V_185 == 0 ) {
if ( V_190 ) {
const char * V_196 = V_179 [ V_172 ] ;
printf ( V_98 L_141 , V_189 , V_196 , V_196 , V_196 , V_196 ) ;
}
break;
}
V_194 = F_131 ( V_144 ) ;
if ( V_189 > V_193 && V_194 == V_195 ) {
if ( ! V_192 ) {
printf ( L_142 ) ;
V_192 = 1 ;
}
continue;
}
V_192 = 0 ;
V_195 = V_194 ;
if ( V_190 )
printf ( V_98 L_143 , V_189 , V_194 ) ;
printf ( L_144 ) ;
V_191 ( V_194 , V_189 ) ;
printf ( L_32 ) ;
}
return V_189 - V_193 ;
}
static int
F_39 ( unsigned long V_189 , long V_87 , int V_190 )
{
return F_130 ( V_189 , V_87 , V_190 , V_197 ) ;
}
void
F_132 ( unsigned long V_93 )
{
F_31 ( V_93 , L_145 , L_77 ) ;
}
void
F_128 ( void )
{
const unsigned long V_103 = 128 ;
unsigned long V_198 , V_93 ;
unsigned char V_166 [ V_103 + 1 ] ;
V_93 = 0 ;
V_166 [ V_103 ] = '\0' ;
if ( setjmp ( V_105 ) != 0 ) {
printf ( L_146 ) ;
return;
}
V_58 = 1 ;
F_1 () ;
V_93 = F_133 ( L_147 ) ;
if ( ! V_93 )
printf ( L_148 ) ;
else {
V_198 = V_93 + ( 1 << V_199 ) ;
while ( V_93 < V_198 ) {
if ( ! F_65 ( V_93 , V_166 , V_103 ) ) {
printf ( L_149 , V_93 ) ;
break;
}
printf ( L_135 , V_166 ) ;
if ( strlen ( V_166 ) < V_103 )
break;
V_93 += V_103 ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_58 = 0 ;
}
static void
F_76 ( int V_22 )
{
F_102 ( ( void * ) & V_200 ) ;
if( V_77 != '\n' )
V_77 = 0 ;
F_102 ( ( void * ) ( V_22 == 's' ? & V_201 : & V_202 ) ) ;
if( V_77 != '\n' )
V_77 = 0 ;
F_102 ( ( void * ) & V_203 ) ;
switch( V_22 ) {
case 'm' :
memmove ( ( void * ) V_200 , ( void * ) V_202 , V_203 ) ;
break;
case 's' :
memset ( ( void * ) V_200 , V_201 , V_203 ) ;
break;
case 'd' :
if( V_77 != '\n' )
V_77 = 0 ;
F_102 ( ( void * ) & V_204 ) ;
F_134 ( ( unsigned char * ) V_200 , ( unsigned char * ) V_202 , V_203 , V_204 ) ;
break;
}
}
static void
F_134 ( unsigned char * V_205 , unsigned char * V_206 , unsigned V_207 , unsigned V_208 )
{
unsigned V_132 , V_209 ;
V_209 = 0 ;
for( V_132 = V_207 ; V_132 > 0 ; -- V_132 )
if( * V_205 ++ != * V_206 ++ )
if( ++ V_209 <= V_208 )
printf ( L_150 , V_205 - 1 ,
V_205 [ - 1 ] , V_206 - 1 , V_206 [ - 1 ] ) ;
if( V_209 > V_208 )
printf ( L_151 , V_209 ) ;
}
static void
F_77 ( void )
{
unsigned V_65 , V_132 ;
unsigned char V_144 [ 4 ] ;
V_72 = L_152 ;
F_102 ( ( void * ) & V_200 ) ;
if ( V_77 != '\n' ) {
V_77 = 0 ;
F_102 ( ( void * ) & V_210 ) ;
if ( V_77 != '\n' ) {
V_77 = 0 ;
F_102 ( ( void * ) & V_201 ) ;
V_211 = ~ 0 ;
if ( V_77 != '\n' ) V_77 = 0 ;
F_102 ( ( void * ) & V_211 ) ;
}
}
V_132 = 0 ;
for ( V_65 = V_200 ; V_65 < V_210 ; V_65 += 4 ) {
if ( F_65 ( V_65 , V_144 , 4 ) == 4
&& ( ( F_131 ( V_144 ) ^ V_201 ) & V_211 ) == 0 ) {
printf ( L_153 , V_65 , F_131 ( V_144 ) ) ;
if ( ++ V_132 >= 10 )
break;
}
}
}
static void
F_78 ( void )
{
unsigned char V_90 ;
unsigned V_65 ;
int V_212 , V_213 ;
F_102 ( & V_200 ) ;
if ( V_77 != '\n' ) V_77 = 0 ;
F_102 ( & V_214 ) ;
if ( V_77 != '\n' ) V_77 = 0 ;
F_102 ( & V_215 ) ;
V_213 = 0 ;
for ( V_65 = V_200 ; V_65 < V_215 ; V_65 += V_214 ) {
V_212 = F_65 ( V_65 , & V_90 , 1 ) ;
if ( V_212 && ! V_213 ) {
printf ( L_154 , V_65 ) ;
} else if ( ! V_212 && V_213 )
printf ( L_155 , V_65 - V_214 ) ;
V_213 = V_212 ;
if ( V_65 + V_214 < V_65 )
break;
}
if ( V_213 )
printf ( L_155 , V_65 - V_214 ) ;
}
static void F_95 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_100 ;
int V_60 ;
typedef unsigned long (* T_3)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_3 V_216 ;
if ( ! F_102 ( & V_91 ) )
return;
if ( V_77 != '\n' )
V_77 = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 )
args [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < 8 ; ++ V_60 ) {
if ( ! F_102 ( & args [ V_60 ] ) || V_77 == '\n' )
break;
V_77 = 0 ;
}
V_216 = ( T_3 ) V_91 ;
V_100 = 0 ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_100 = V_216 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_1 () ;
printf ( L_156 , V_100 ) ;
} else {
printf ( L_157 , V_171 ) ;
}
V_58 = 0 ;
}
int
F_73 ( void )
{
int V_181 ;
if( V_77 != 0 ) {
V_181 = V_77 ;
V_77 = 0 ;
} else
V_181 = F_75 () ;
while( V_181 == ' ' || V_181 == '\t' )
V_181 = F_75 () ;
return V_181 ;
}
int
F_102 ( unsigned long * V_217 )
{
int V_181 , V_53 ;
unsigned long V_90 ;
V_181 = F_73 () ;
if ( V_181 == '%' ) {
char V_218 [ 8 ] ;
int V_60 ;
for ( V_60 = 0 ; V_60 < sizeof( V_218 ) - 1 ; ++ V_60 ) {
V_181 = F_75 () ;
if ( ! isalnum ( V_181 ) ) {
V_77 = V_181 ;
break;
}
V_218 [ V_60 ] = V_181 ;
}
V_218 [ V_60 ] = 0 ;
for ( V_60 = 0 ; V_60 < V_219 ; ++ V_60 ) {
if ( strcmp ( V_220 [ V_60 ] , V_218 ) == 0 ) {
if ( V_73 == NULL ) {
printf ( L_158 ) ;
return 0 ;
}
* V_217 = ( ( unsigned long * ) V_73 ) [ V_60 ] ;
return 1 ;
}
}
printf ( L_159 , V_218 ) ;
return 0 ;
}
if ( V_181 == '0' ) {
V_181 = F_75 () ;
if ( V_181 == 'x' ) {
V_181 = F_75 () ;
} else {
V_53 = F_135 ( V_181 ) ;
if ( V_53 == V_50 ) {
V_77 = V_181 ;
* V_217 = 0 ;
return 1 ;
}
}
} else if ( V_181 == '$' ) {
int V_60 ;
for ( V_60 = 0 ; V_60 < 63 ; V_60 ++ ) {
V_181 = F_75 () ;
if ( isspace ( V_181 ) ) {
V_77 = V_181 ;
break;
}
V_106 [ V_60 ] = V_181 ;
}
V_106 [ V_60 ++ ] = 0 ;
* V_217 = 0 ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
* V_217 = F_133 ( V_106 ) ;
F_1 () ;
}
V_58 = 0 ;
if ( ! ( * V_217 ) ) {
printf ( L_160 , V_106 ) ;
return 0 ;
}
return 1 ;
}
V_53 = F_135 ( V_181 ) ;
if ( V_53 == V_50 ) {
V_77 = V_181 ;
return 0 ;
}
V_90 = 0 ;
do {
V_90 = ( V_90 << 4 ) + V_53 ;
V_181 = F_75 () ;
V_53 = F_135 ( V_181 ) ;
} while ( V_53 != V_50 );
V_77 = V_181 ;
* V_217 = V_90 ;
return 1 ;
}
static void
F_109 ( void )
{
int V_181 ;
V_181 = V_77 ;
V_77 = 0 ;
while( V_181 != '\n' )
V_181 = F_75 () ;
}
static int F_135 ( int V_181 )
{
if( '0' <= V_181 && V_181 <= '9' )
return V_181 - '0' ;
if( 'A' <= V_181 && V_181 <= 'F' )
return V_181 - ( 'A' - 10 ) ;
if( 'a' <= V_181 && V_181 <= 'f' )
return V_181 - ( 'a' - 10 ) ;
return V_50 ;
}
void
F_136 ( char * V_221 , int V_103 )
{
int V_181 ;
V_181 = F_73 () ;
do {
if( V_103 > 1 ) {
* V_221 ++ = V_181 ;
-- V_103 ;
}
V_181 = F_75 () ;
} while( V_181 != ' ' && V_181 != '\t' && V_181 != '\n' );
V_77 = V_181 ;
* V_221 = 0 ;
}
static void
F_72 ( void )
{
V_222 = NULL ;
}
static int
F_75 ( void )
{
if ( V_222 == NULL || * V_222 == 0 ) {
if ( F_137 ( line , sizeof( line ) ) == NULL ) {
V_222 = NULL ;
return V_50 ;
}
V_222 = line ;
}
return * V_222 ++ ;
}
static void
F_74 ( char * V_223 )
{
V_222 = V_223 ;
}
static void
F_82 ( void )
{
int type = F_75 () ;
unsigned long V_93 ;
static char V_224 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_102 ( & V_93 ) )
F_31 ( V_93 , L_91 , L_32 ) ;
V_77 = 0 ;
break;
case 's' :
F_136 ( V_224 , 64 ) ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_93 = F_133 ( V_224 ) ;
if ( V_93 )
printf ( L_161 , V_224 , V_93 ) ;
else
printf ( L_162 , V_224 ) ;
F_1 () ;
}
V_58 = 0 ;
V_77 = 0 ;
break;
}
}
static void F_31 ( unsigned long V_32 , const char * V_225 ,
const char * V_226 )
{
char * V_227 ;
const char * V_104 = NULL ;
unsigned long V_27 , V_103 ;
printf ( V_98 , V_32 ) ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_104 = F_108 ( V_32 , & V_103 , & V_27 , & V_227 ,
V_106 ) ;
F_1 () ;
F_117 ( 200 ) ;
}
V_58 = 0 ;
if ( V_104 ) {
printf ( L_163 , V_225 , V_104 , V_27 , V_103 ) ;
if ( V_227 )
printf ( L_164 , V_227 ) ;
}
printf ( L_135 , V_226 ) ;
}
static void F_138 ( void )
{
int V_60 ;
unsigned long V_228 , V_229 , V_230 ;
unsigned long V_231 ;
printf ( L_165 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_232 ; V_60 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
V_230 = ( V_228 & V_233 ) ;
if ( V_230 | V_228 | V_229 ) {
printf ( L_166 , V_60 , V_228 , V_229 ) ;
if ( V_230 ) {
V_231 = V_229 & V_234 ;
if ( V_229 & V_235 ) {
printf ( L_167 ,
F_139 ( V_228 ) ,
( V_229 & ~ V_236 ) >> V_237 ,
V_231 ) ;
} else {
printf ( L_168 ,
F_140 ( V_228 ) ,
( V_229 & ~ V_236 ) >> V_238 ,
V_231 ) ;
}
} else
printf ( L_32 ) ;
}
}
}
static void F_141 ( void )
{
int V_60 ;
unsigned long * V_224 = ( unsigned long * ) F_116 () -> V_239 ;
printf ( L_169 , F_11 () ) ;
for ( V_60 = 0 ; V_60 < V_240 / 16 ; V_60 ++ ) {
unsigned long V_65 , V_241 ;
V_65 = * V_224 ++ ;
V_241 = * V_224 ++ ;
if ( V_65 || V_241 ) {
printf ( L_170 , V_60 , V_65 ) ;
printf ( L_171 , V_241 ) ;
}
}
}
void F_97 ( void )
{
if ( F_142 ( V_242 ) )
F_138 () ;
else
F_141 () ;
}
void F_97 ( void )
{
int V_60 ;
printf ( L_172 ) ;
for ( V_60 = 0 ; V_60 < 16 ; ++ V_60 )
printf ( L_34 , F_143 ( V_60 ) ) ;
printf ( L_32 ) ;
}
static void F_98 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_243 ; V_60 ++ ) {
unsigned long V_244 , V_245 , V_246 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_173 , V_60 , V_244 , V_245 , V_246 ) ;
if ( V_244 & V_247 ) {
printf ( L_174 ,
V_244 & V_248 ,
V_245 & V_249 ,
V_245 & V_250 ,
( V_246 & V_251 ) ? 'W' : 'w' ,
( V_246 & V_252 ) ? 'I' : 'i' ,
( V_246 & V_253 ) ? 'M' : 'm' ,
( V_246 & V_254 ) ? 'G' : 'g' ,
( V_246 & V_255 ) ? 'E' : 'e' ) ;
}
printf ( L_32 ) ;
}
}
static void F_100 ( void )
{
V_169 V_256 , V_257 , V_258 ;
V_170 V_259 ;
int V_60 , V_260 , V_261 , V_262 , V_263 , V_264 , V_265 = 0 ;
int V_266 ;
static const char * V_267 [] = {
L_175 ,
L_176 ,
L_177 ,
L_178 ,
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
} ;
V_256 = F_101 ( V_268 ) ;
V_266 = ( V_256 & 3 ) + 1 ;
V_261 = ( ( V_256 >> 2 ) & 3 ) + 1 ;
V_262 = ( ( V_256 >> 6 ) & 0x1f ) + 1 ;
V_263 = ( V_256 >> 24 ) & 0xf ;
V_264 = ( V_256 >> 16 ) & 0x7f ;
if ( ( V_266 > 1 ) && ( V_256 & 0x10000 ) )
V_265 = 1 ;
printf ( L_207 ,
V_266 , V_261 , V_262 , V_263 , V_264 ) ;
V_257 = ( 1ul << V_262 ) - 1 ;
V_258 = ( 1ul << V_263 ) - 1 ;
V_259 = ( 1ull << V_264 ) - 1 ;
for ( V_260 = 0 ; V_260 < V_261 ; V_260 ++ ) {
V_169 V_269 ;
int V_270 , V_271 , V_272 = 1 ;
printf ( L_208 , V_260 ) ;
switch( V_260 ) {
case 0 :
V_269 = F_101 ( V_273 ) ;
break;
case 1 :
V_269 = F_101 ( V_274 ) ;
break;
case 2 :
V_269 = F_101 ( V_275 ) ;
break;
case 3 :
V_269 = F_101 ( V_276 ) ;
break;
default:
printf ( L_209 ) ;
continue;
}
V_270 = V_269 & 0xfff ;
V_271 = ( V_269 >> 24 ) & 0xff ;
for ( V_60 = 0 ; V_60 < V_270 ; V_60 ++ ) {
V_169 V_277 = F_144 ( V_260 ) ;
V_169 V_278 = F_145 ( V_279 ) ;
V_170 V_280 = 0 ;
V_170 V_281 ;
int V_282 = V_60 , V_283 = V_60 ;
if ( V_271 != 0 ) {
V_283 = V_60 / V_271 ;
V_282 = V_60 % V_271 ;
V_280 = V_283 * 0x1000 ;
}
V_277 |= F_146 ( V_282 ) ;
F_70 ( V_284 , V_277 ) ;
F_70 ( V_285 , V_278 ) ;
F_70 ( V_286 , V_280 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_278 = F_101 ( V_285 ) ;
V_280 = F_101 ( V_286 ) ;
V_281 = F_101 ( V_287 ) ;
if ( V_271 && ( V_60 % V_271 ) == 0 )
V_272 = 1 ;
if ( ! ( V_278 & V_288 ) )
continue;
if ( V_271 == 0 )
printf ( L_210 , V_60 ) ;
else if ( V_272 )
printf ( L_211 , V_283 , 'A' + V_282 ) ;
else
printf ( L_212 , 'A' + V_282 ) ;
V_272 = 0 ;
printf ( L_213 ,
V_280 & ~ 0x3ffull ,
( V_278 >> 16 ) & 0x3fff ,
V_267 [ ( V_278 >> 7 ) & 0x1f ] ,
V_278 & V_289 ? 'I' : ' ' ,
V_278 & V_290 ? 'P' : ' ' ,
V_278 & V_291 ? '1' : '0' ) ;
printf ( L_214 ,
V_280 & V_292 ? 'a' : ' ' ,
V_280 & V_293 ? 'v' : ' ' ,
V_280 & V_294 ? 'w' : ' ' ,
V_280 & V_295 ? 'i' : ' ' ,
V_280 & V_296 ? 'm' : ' ' ,
V_280 & V_297 ? 'g' : ' ' ,
V_280 & V_298 ? 'e' : ' ' ) ;
printf ( L_215 , V_281 & V_259 & ~ 0x7ffull ) ;
if ( V_278 & V_289 )
printf ( L_216 ,
V_267 [ ( V_281 >> 1 ) & 0x1f ] ) ;
else
printf ( L_217 ,
V_281 & V_299 ? 'x' : ' ' ,
V_281 & V_300 ? 'w' : ' ' ,
V_281 & V_301 ? 'r' : ' ' ,
V_281 & V_302 ? 'x' : ' ' ,
V_281 & V_303 ? 'w' : ' ' ,
V_281 & V_304 ? 'r' : ' ' ) ;
}
}
}
static void F_147 ( int V_305 )
{
#ifdef F_122
if ( F_123 ( V_153 ) )
return;
#endif
if ( V_305 ) {
V_306 = F_50 ;
V_307 = F_59 ;
V_308 = F_54 ;
V_309 = F_55 ;
V_310 = F_58 ;
V_311 = F_57 ;
V_312 = F_60 ;
} else {
V_306 = NULL ;
V_307 = NULL ;
V_308 = NULL ;
V_309 = NULL ;
V_310 = NULL ;
V_311 = NULL ;
V_312 = NULL ;
}
F_148 () ;
}
static void F_149 ( int V_313 )
{
F_147 ( 1 ) ;
F_150 ( F_53 () ) ;
}
static int T_4 F_151 ( void )
{
#ifdef F_122
if ( F_123 ( V_153 ) )
return 0 ;
#endif
F_152 ( 'x' , & V_314 ) ;
return 0 ;
}
static int T_4 F_153 ( char * V_1 )
{
if ( ! V_1 || strncmp ( V_1 , L_218 , 5 ) == 0 ) {
F_147 ( 1 ) ;
V_315 = 1 ;
} else if ( strncmp ( V_1 , L_219 , 2 ) == 0 )
F_147 ( 1 ) ;
else if ( strncmp ( V_1 , L_220 , 3 ) == 0 )
V_316 = 1 ;
else if ( strncmp ( V_1 , L_221 , 4 ) == 0 )
V_74 = 1 ;
else
return 1 ;
return 0 ;
}
void T_4 F_154 ( void )
{
#ifdef F_155
if ( ! V_316 )
F_147 ( 1 ) ;
#endif
if ( V_315 )
F_150 ( NULL ) ;
}
void F_156 ( struct V_317 * V_318 )
{
struct V_319 * V_319 ;
F_157 (spu, list, full_list) {
if ( V_319 -> V_320 >= V_321 ) {
F_158 ( 1 ) ;
continue;
}
V_322 [ V_319 -> V_320 ] . V_319 = V_319 ;
V_322 [ V_319 -> V_320 ] . V_323 = 0 ;
V_322 [ V_319 -> V_320 ] . V_324 = ( unsigned long )
V_322 [ V_319 -> V_320 ] . V_319 -> V_325 ;
}
}
static void F_159 ( void )
{
struct V_319 * V_319 ;
int V_60 ;
V_170 V_224 ;
for ( V_60 = 0 ; V_60 < V_321 ; V_60 ++ ) {
if ( ! V_322 [ V_60 ] . V_319 )
continue;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_319 = V_322 [ V_60 ] . V_319 ;
V_322 [ V_60 ] . V_326 =
F_160 ( & V_319 -> V_327 -> V_328 ) ;
V_224 = F_161 ( V_319 ) ;
V_322 [ V_60 ] . V_329 = V_224 ;
V_224 &= ~ V_330 ;
F_162 ( V_319 , V_224 ) ;
F_1 () ;
F_117 ( 200 ) ;
V_322 [ V_60 ] . V_323 = 1 ;
printf ( L_222 , V_60 ,
V_322 [ V_60 ] . V_326 ?
L_223 : L_224 ) ;
} else {
V_58 = 0 ;
printf ( L_225 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_163 ( void )
{
struct V_319 * V_319 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_321 ; V_60 ++ ) {
if ( ! V_322 [ V_60 ] . V_319 )
continue;
if ( ! V_322 [ V_60 ] . V_323 ) {
printf ( L_226
L_227 , V_60 ) ;
continue;
}
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_319 = V_322 [ V_60 ] . V_319 ;
F_162 ( V_319 , V_322 [ V_60 ] . V_329 ) ;
F_164 ( & V_319 -> V_327 -> V_328 ,
V_322 [ V_60 ] . V_326 ) ;
F_1 () ;
F_117 ( 200 ) ;
printf ( L_228 , V_60 ) ;
} else {
V_58 = 0 ;
printf ( L_229 , V_60 ) ;
}
V_58 = 0 ;
}
}
static void F_165 ( struct V_319 * V_319 )
{
printf ( L_230 , V_319 ) ;
F_166 ( V_319 , L_231 , V_320 ) ;
F_166 ( V_319 , L_135 , V_104 ) ;
F_166 ( V_319 , L_232 , V_331 ) ;
F_166 ( V_319 , L_233 , V_325 ) ;
F_166 ( V_319 , L_232 , V_332 ) ;
F_166 ( V_319 , L_231 , V_333 ) ;
F_166 ( V_319 , L_232 , V_28 ) ;
F_166 ( V_319 , L_234 , V_334 ) ;
F_166 ( V_319 , L_232 , V_335 ) ;
F_166 ( V_319 , L_232 , V_336 ) ;
F_166 ( V_319 , L_232 , V_337 ) ;
F_166 ( V_319 , L_232 , V_338 [ 0 ] ) ;
F_166 ( V_319 , L_232 , V_338 [ 1 ] ) ;
F_166 ( V_319 , L_232 , V_338 [ 2 ] ) ;
F_166 ( V_319 , L_231 , V_339 ) ;
F_166 ( V_319 , L_234 , V_130 ) ;
F_166 ( V_319 , L_233 , V_340 ) ;
F_166 ( V_319 , L_233 , V_341 ) ;
F_166 ( V_319 , L_233 , V_342 ) ;
F_166 ( V_319 , L_233 , V_343 ) ;
F_166 ( V_319 , L_232 , V_344 ) ;
F_166 ( V_319 , L_233 , V_327 ) ;
F_167 ( L_231 , V_327 -> V_328 ,
F_160 ( & V_319 -> V_327 -> V_328 ) ) ;
F_167 ( L_231 , V_327 -> V_345 ,
F_160 ( & V_319 -> V_327 -> V_345 ) ) ;
F_167 ( L_231 , V_327 -> V_346 ,
F_160 ( & V_319 -> V_327 -> V_346 ) ) ;
F_166 ( V_319 , L_233 , V_347 ) ;
F_166 ( V_319 , L_233 , V_348 ) ;
}
int
F_168 ( unsigned long V_189 , long V_87 , int V_190 )
{
return F_130 ( V_189 , V_87 , V_190 , V_349 ) ;
}
static void F_169 ( unsigned long V_350 , int V_351 )
{
unsigned long V_27 , V_93 , V_352 ;
if ( setjmp ( V_105 ) == 0 ) {
V_58 = 1 ;
F_1 () ;
V_352 = ( unsigned long ) V_322 [ V_350 ] . V_319 -> V_325 ;
F_1 () ;
F_117 ( 200 ) ;
} else {
V_58 = 0 ;
printf ( L_235 , V_350 ) ;
return;
}
V_58 = 0 ;
if ( F_102 ( & V_27 ) )
V_93 = V_352 + V_27 ;
else
V_93 = V_322 [ V_350 ] . V_324 ;
if ( V_93 >= V_352 + V_353 ) {
printf ( L_236 ) ;
return;
}
switch ( V_351 ) {
case 'i' :
V_93 += F_168 ( V_93 , 16 , 1 ) ;
V_72 = L_237 ;
break;
default:
F_129 ( V_93 , 64 ) ;
V_93 += 64 ;
V_72 = L_238 ;
break;
}
V_322 [ V_350 ] . V_324 = V_93 ;
}
static int F_87 ( void )
{
static unsigned long V_350 = 0 ;
int V_22 , V_351 = 0 ;
V_22 = F_75 () ;
switch ( V_22 ) {
case 's' :
F_159 () ;
break;
case 'r' :
F_163 () ;
break;
case 'd' :
V_351 = F_75 () ;
if ( isxdigit ( V_351 ) || V_351 == '\n' )
V_77 = V_351 ;
case 'f' :
F_102 ( & V_350 ) ;
if ( V_350 >= V_321 || ! V_322 [ V_350 ] . V_319 ) {
printf ( L_239 ) ;
return 0 ;
}
switch ( V_22 ) {
case 'f' :
F_165 ( V_322 [ V_350 ] . V_319 ) ;
break;
default:
F_169 ( V_350 , V_351 ) ;
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
