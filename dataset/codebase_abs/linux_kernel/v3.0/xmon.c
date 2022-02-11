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
#ifdef F_17
return 0 ;
#else
return ( ( V_16 -> V_17 & V_18 ) == 0 ) ;
#endif
}
static int F_18 ( struct V_15 * V_16 , int V_19 )
{
int V_20 = 0 ;
struct V_21 * V_22 ;
long V_23 [ V_24 ] ;
unsigned long V_25 ;
unsigned long V_26 ;
#ifdef F_19
int V_27 ;
int V_28 ;
unsigned long V_12 ;
#endif
F_20 ( V_26 ) ;
V_22 = F_21 ( V_16 -> V_29 , & V_25 ) ;
if ( V_22 != NULL ) {
V_16 -> V_29 = V_22 -> V_30 + V_25 ;
F_22 ( & V_22 -> V_31 ) ;
}
F_23 () ;
#ifdef F_19
V_27 = F_11 () ;
if ( F_24 ( V_27 , & V_14 ) ) {
F_10 () ;
F_25 ( V_16 ) ;
printf ( L_2
L_3 ,
V_27 , V_16 -> V_32 , F_26 ( F_27 ( V_16 ) ) ) ;
F_13 () ;
longjmp ( V_33 [ V_27 ] , 1 ) ;
}
if ( setjmp ( V_23 ) != 0 ) {
if ( ! V_34 || ! V_35 ) {
F_10 () ;
printf ( L_4
L_5 , V_27 ) ;
F_13 () ;
goto V_36;
}
V_28 = ! ( V_37 && V_27 == V_38 ) ;
goto V_39;
}
V_33 [ V_27 ] = V_23 ;
F_28 ( V_27 , & V_14 ) ;
V_22 = NULL ;
if ( ( V_16 -> V_17 & ( V_40 | V_41 | V_42 ) ) == ( V_40 | V_42 ) )
V_22 = F_29 ( V_16 -> V_29 ) ;
if ( V_22 || F_16 ( V_16 ) )
V_19 = 0 ;
if ( ! V_19 ) {
F_10 () ;
F_25 ( V_16 ) ;
if ( V_22 ) {
printf ( L_6 ,
V_27 , F_30 ( V_22 ) ) ;
F_31 ( V_16 -> V_29 , L_7 , L_8 ) ;
}
if ( F_16 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_13 () ;
}
V_36:
V_28 = 1 ;
while ( V_28 && ! V_35 ) {
if ( V_34 == 0 ) {
if ( V_19 )
goto V_43;
V_28 = F_32 ( 0 , & V_34 ) ;
}
F_33 () ;
}
if ( ! V_28 && ! V_35 ) {
int V_44 = F_34 () ;
V_38 = V_27 ;
F_35 () ;
if ( V_44 > 1 ) {
F_36 () ;
for ( V_12 = 100000000 ; V_12 != 0 ; -- V_12 ) {
if ( F_37 ( & V_14 ) >= V_44 )
break;
F_33 () ;
}
}
F_38 () ;
F_5 () ;
if ( V_22 || F_27 ( V_16 ) == 0xd00 )
F_39 ( V_16 -> V_29 , 1 , 0 ) ;
printf ( L_11 ) ;
F_35 () ;
V_35 = 1 ;
F_33 () ;
}
V_39:
while ( V_34 ) {
if ( V_28 ) {
if ( V_27 == V_38 ) {
if ( ! F_32 ( 0 , & V_37 ) ) {
V_28 = 0 ;
continue;
}
while ( V_27 == V_38 )
F_33 () ;
}
F_33 () ;
} else {
V_20 = F_40 ( V_16 ) ;
if ( V_20 != 0 ) {
F_41 () ;
V_35 = 0 ;
F_42 () ;
V_34 = 0 ;
break;
}
V_28 = 1 ;
}
}
V_43:
F_43 ( V_27 , & V_14 ) ;
V_33 [ V_27 ] = NULL ;
#else
if ( V_34 ) {
printf ( L_12 ,
V_16 -> V_32 , F_26 ( F_27 ( V_16 ) ) ) ;
longjmp ( V_33 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_23 ) == 0 ) {
V_33 [ 0 ] = V_23 ;
V_34 = 1 ;
F_25 ( V_16 ) ;
V_22 = F_29 ( V_16 -> V_29 ) ;
if ( V_22 ) {
printf ( L_13 , F_30 ( V_22 ) ) ;
F_31 ( V_16 -> V_29 , L_7 , L_8 ) ;
}
if ( F_16 ( V_16 ) )
printf ( L_9
L_10 ) ;
F_38 () ;
F_5 () ;
if ( V_22 || F_27 ( V_16 ) == 0xd00 )
F_39 ( V_16 -> V_29 , 1 , 0 ) ;
printf ( L_11 ) ;
}
V_20 = F_40 ( V_16 ) ;
F_41 () ;
V_34 = 0 ;
#endif
#ifdef F_44
if ( V_16 -> V_17 & V_45 ) {
V_22 = F_29 ( V_16 -> V_29 ) ;
if ( V_22 != NULL ) {
V_16 -> V_29 = ( unsigned long ) & V_22 -> V_46 [ 0 ] ;
F_45 ( & V_22 -> V_31 ) ;
}
}
#else
if ( ( V_16 -> V_17 & ( V_40 | V_41 | V_42 ) ) == ( V_40 | V_42 ) ) {
V_22 = F_29 ( V_16 -> V_29 ) ;
if ( V_22 != NULL ) {
int V_47 = F_46 ( V_16 , V_22 -> V_46 [ 0 ] ) ;
if ( V_47 == 0 ) {
V_16 -> V_29 = ( unsigned long ) & V_22 -> V_46 [ 0 ] ;
F_45 ( & V_22 -> V_31 ) ;
} else if ( V_47 < 0 ) {
printf ( L_14 ,
( F_47 ( V_22 -> V_46 [ 0 ] ) ? L_15 : L_16 ) ) ;
}
}
}
#endif
F_48 () ;
F_49 ( V_26 ) ;
return V_20 != 'X' && V_20 != V_48 ;
}
int F_50 ( struct V_15 * V_49 )
{
struct V_15 V_16 ;
if ( V_49 == NULL ) {
F_51 ( & V_16 ) ;
V_49 = & V_16 ;
}
return F_18 ( V_49 , 0 ) ;
}
T_1 F_52 ( int V_50 , void * V_51 )
{
unsigned long V_26 ;
F_20 ( V_26 ) ;
printf ( L_17 ) ;
F_50 ( F_53 () ) ;
F_49 ( V_26 ) ;
return V_52 ;
}
static int F_54 ( struct V_15 * V_16 )
{
struct V_21 * V_22 ;
unsigned long V_25 ;
if ( ( V_16 -> V_17 & ( V_40 | V_41 | V_42 ) ) != ( V_40 | V_42 ) )
return 0 ;
V_22 = F_21 ( V_16 -> V_29 , & V_25 ) ;
if ( V_22 != NULL && V_25 == 4 ) {
V_16 -> V_29 = V_22 -> V_30 + 4 ;
F_22 ( & V_22 -> V_31 ) ;
return 1 ;
}
V_22 = F_29 ( V_16 -> V_29 ) ;
if ( ! V_22 )
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
if ( ( V_16 -> V_17 & ( V_40 | V_41 | V_42 ) ) != ( V_40 | V_42 ) )
return 0 ;
if ( V_53 . V_54 == 0 )
return 0 ;
F_18 ( V_16 , 0 ) ;
return 1 ;
}
static int F_58 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_17 & ( V_40 | V_41 | V_42 ) ) != ( V_40 | V_42 ) )
return 0 ;
if ( V_55 == NULL )
return 0 ;
F_18 ( V_16 , 0 ) ;
return 1 ;
}
static int F_59 ( struct V_15 * V_16 )
{
#ifdef F_19
if ( V_34 && ! F_24 ( F_11 () , & V_14 ) )
F_18 ( V_16 , 1 ) ;
#endif
return 0 ;
}
static int F_60 ( struct V_15 * V_16 )
{
struct V_21 * V_22 ;
unsigned long V_25 ;
if ( V_34 && V_56 )
F_61 ( V_16 ) ;
if ( ( V_16 -> V_17 & ( V_40 | V_41 | V_42 ) ) == ( V_40 | V_42 ) ) {
V_22 = F_21 ( V_16 -> V_29 , & V_25 ) ;
if ( V_22 != NULL ) {
V_16 -> V_29 = V_22 -> V_30 + V_25 ;
F_22 ( & V_22 -> V_31 ) ;
}
}
return 0 ;
}
static struct V_21 * F_29 ( unsigned long V_57 )
{
int V_58 ;
struct V_21 * V_22 ;
V_22 = V_59 ;
for ( V_58 = 0 ; V_58 < V_60 ; ++ V_58 , ++ V_22 )
if ( V_22 -> V_54 && V_57 == V_22 -> V_30 )
return V_22 ;
return NULL ;
}
static struct V_21 * F_21 ( unsigned long V_29 , unsigned long * V_61 )
{
unsigned long V_62 ;
V_62 = V_29 - ( unsigned long ) V_59 ;
if ( V_62 >= sizeof( V_59 ) )
return NULL ;
V_62 %= sizeof( struct V_21 ) ;
if ( V_62 != F_62 ( struct V_21 , V_46 [ 0 ] )
&& V_62 != F_62 ( struct V_21 , V_46 [ 1 ] ) )
return NULL ;
* V_61 = V_62 - F_62 ( struct V_21 , V_46 [ 0 ] ) ;
return (struct V_21 * ) ( V_29 - V_62 ) ;
}
static struct V_21 * F_63 ( unsigned long V_63 )
{
struct V_21 * V_22 ;
V_63 &= ~ 3UL ;
V_22 = F_29 ( V_63 ) ;
if ( V_22 )
return V_22 ;
for ( V_22 = V_59 ; V_22 < & V_59 [ V_60 ] ; ++ V_22 ) {
if ( ! V_22 -> V_54 && F_64 ( & V_22 -> V_31 ) == 0 ) {
V_22 -> V_30 = V_63 ;
V_22 -> V_46 [ 1 ] = V_64 ;
F_2 ( & V_22 -> V_46 [ 1 ] ) ;
return V_22 ;
}
}
printf ( L_18 ) ;
return NULL ;
}
static void F_41 ( void )
{
int V_58 ;
struct V_21 * V_22 ;
V_22 = V_59 ;
for ( V_58 = 0 ; V_58 < V_60 ; ++ V_58 , ++ V_22 ) {
if ( ( V_22 -> V_54 & ( V_65 | V_66 ) ) == 0 )
continue;
if ( F_65 ( V_22 -> V_30 , & V_22 -> V_46 [ 0 ] , 4 ) != 4 ) {
printf ( L_19
L_20 , V_22 -> V_30 ) ;
V_22 -> V_54 = 0 ;
continue;
}
if ( F_66 ( V_22 -> V_46 [ 0 ] ) || F_47 ( V_22 -> V_46 [ 0 ] ) ) {
printf ( L_21
L_22 , V_22 -> V_30 ) ;
V_22 -> V_54 = 0 ;
continue;
}
F_2 ( & V_22 -> V_46 [ 0 ] ) ;
if ( V_22 -> V_54 & V_66 )
continue;
if ( F_67 ( V_22 -> V_30 , & V_64 , 4 ) != 4 ) {
printf ( L_23
L_20 , V_22 -> V_30 ) ;
V_22 -> V_54 &= ~ V_65 ;
continue;
}
F_2 ( ( void * ) V_22 -> V_30 ) ;
}
}
static void F_48 ( void )
{
if ( V_53 . V_54 )
F_68 ( V_53 . V_30 | ( V_53 . V_54 & 7 ) ) ;
if ( V_55 && F_69 ( V_67 ) )
F_70 ( V_68 , V_55 -> V_30
| ( V_55 -> V_54 & ( V_66 | V_69 ) ) ) ;
}
static void F_38 ( void )
{
int V_58 ;
struct V_21 * V_22 ;
unsigned V_46 ;
V_22 = V_59 ;
for ( V_58 = 0 ; V_58 < V_60 ; ++ V_58 , ++ V_22 ) {
if ( ( V_22 -> V_54 & ( V_65 | V_66 ) ) != V_65 )
continue;
if ( F_65 ( V_22 -> V_30 , & V_46 , 4 ) == 4
&& V_46 == V_64
&& F_67 ( V_22 -> V_30 , & V_22 -> V_46 , 4 ) != 4 )
printf ( L_24 ,
V_22 -> V_30 ) ;
else
F_2 ( ( void * ) V_22 -> V_30 ) ;
}
}
static void F_23 ( void )
{
F_68 ( 0 ) ;
if ( F_69 ( V_67 ) )
F_70 ( V_68 , 0 ) ;
}
static int
F_40 ( struct V_15 * V_49 )
{
int V_20 = 0 ;
V_70 = NULL ;
V_71 = V_49 ;
if ( ! V_72 ) {
V_72 = 1 ;
F_71 ( V_49 -> V_73 [ 1 ] , V_49 -> V_74 , V_49 -> V_29 ) ;
}
for(; ; ) {
#ifdef F_19
printf ( L_25 , F_11 () ) ;
#endif
printf ( L_26 ) ;
F_72 () ;
V_75 = 0 ;
V_20 = F_73 () ;
if( V_20 == '\n' ) {
if ( V_70 == NULL )
continue;
F_74 ( V_70 ) ;
V_70 = NULL ;
V_20 = F_75 () ;
}
switch ( V_20 ) {
case 'm' :
V_20 = F_75 () ;
switch ( V_20 ) {
case 'm' :
case 's' :
case 'd' :
F_76 ( V_20 ) ;
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
V_75 = V_20 ;
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
F_83 ( V_49 ) ;
break;
case 'e' :
F_25 ( V_49 ) ;
break;
case 'S' :
F_84 () ;
break;
case 't' :
F_85 ( V_49 ) ;
break;
case 'f' :
F_86 () ;
break;
case 's' :
if ( F_87 () == 0 )
break;
if ( F_88 ( V_49 ) )
return V_20 ;
break;
case 'x' :
case 'X' :
return V_20 ;
case V_48 :
printf ( L_27 ) ;
F_89 ( 2000 ) ;
return V_20 ;
case '?' :
F_90 ( V_76 ) ;
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
#ifdef F_17
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
if ( ' ' < V_20 && V_20 <= '~' )
putchar ( V_20 ) ;
else
printf ( L_29 , V_20 ) ;
V_20 = F_75 () ;
} while ( V_20 != '\n' );
printf ( L_30 ) ;
break;
}
}
}
static int F_88 ( struct V_15 * V_16 )
{
V_16 -> V_17 |= V_45 ;
F_70 ( V_77 , F_101 ( V_77 ) | V_78 | V_79 ) ;
return 1 ;
}
static int F_88 ( struct V_15 * V_16 )
{
unsigned int V_46 ;
int V_47 ;
if ( ( V_16 -> V_17 & ( V_42 | V_41 | V_40 ) ) == ( V_42 | V_40 ) ) {
if ( F_65 ( V_16 -> V_29 , & V_46 , 4 ) == 4 ) {
V_47 = F_46 ( V_16 , V_46 ) ;
if ( V_47 < 0 ) {
printf ( L_14 ,
( F_47 ( V_46 ) ? L_15 : L_16 ) ) ;
return 0 ;
}
if ( V_47 > 0 ) {
V_16 -> V_32 = 0xd00 | ( V_16 -> V_32 & 1 ) ;
printf ( L_31 ) ;
F_31 ( V_16 -> V_29 , L_7 , L_32 ) ;
F_39 ( V_16 -> V_29 , 1 , 0 ) ;
return 0 ;
}
}
}
V_16 -> V_17 |= V_80 ;
return 1 ;
}
static void F_94 ( void )
{
int V_20 ;
V_20 = F_75 () ;
if ( V_20 == 'r' )
V_81 . V_82 ( NULL ) ;
else if ( V_20 == 'h' )
V_81 . V_83 () ;
else if ( V_20 == 'p' )
V_81 . V_84 () ;
}
static int F_93 ( void )
{
#ifdef F_19
unsigned long V_27 ;
int V_12 ;
int V_85 ;
if ( ! F_102 ( & V_27 ) ) {
printf ( L_33 ) ;
V_85 = 0 ;
for ( V_27 = 0 ; V_27 < V_86 ; ++ V_27 ) {
if ( F_24 ( V_27 , & V_14 ) ) {
if ( V_85 == 0 )
printf ( L_34 , V_27 ) ;
++ V_85 ;
} else {
if ( V_85 > 1 )
printf ( L_35 , V_27 - 1 ) ;
V_85 = 0 ;
}
}
if ( V_85 > 1 )
printf ( L_35 , V_86 - 1 ) ;
printf ( L_32 ) ;
return 0 ;
}
if ( ! F_24 ( V_27 , & V_14 ) ) {
printf ( L_36 , V_27 ) ;
return 0 ;
}
V_37 = 0 ;
F_35 () ;
V_38 = V_27 ;
V_12 = 10000000 ;
while ( ! V_37 ) {
if ( -- V_12 == 0 ) {
if ( F_32 ( 0 , & V_37 ) )
break;
F_35 () ;
V_38 = F_11 () ;
printf ( L_37 , V_27 ) ;
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
unsigned int V_58 ;
unsigned short V_87 ;
unsigned char V_88 ;
if ( ! F_102 ( & V_89 ) )
return;
if ( ! F_102 ( & V_90 ) )
return;
V_87 = 0xffff ;
for ( V_58 = 0 ; V_58 < V_90 ; ++ V_58 ) {
if ( F_65 ( V_89 + V_58 , & V_88 , 1 ) == 0 ) {
printf ( L_38 , V_89 + V_58 ) ;
break;
}
V_87 = F_103 ( V_87 , V_88 ) ;
}
printf ( L_39 , V_87 ) ;
}
static long F_104 ( unsigned long V_91 )
{
unsigned int V_46 ;
V_91 &= ~ 3 ;
if ( ! F_105 ( V_91 ) ) {
printf ( L_40 ) ;
return 0 ;
}
if ( ! F_65 ( V_91 , & V_46 , sizeof( V_46 ) ) ) {
printf ( L_41 , V_91 ) ;
return 0 ;
}
if ( F_66 ( V_46 ) || F_47 ( V_46 ) ) {
printf ( L_42
L_43 ) ;
return 0 ;
}
return 1 ;
}
static void
F_91 ( void )
{
int V_20 ;
unsigned long V_63 ;
int V_92 , V_58 ;
struct V_21 * V_22 ;
const char V_93 [] = L_44
L_45 ;
V_20 = F_75 () ;
switch ( V_20 ) {
#ifndef F_106
case 'd' :
V_92 = 7 ;
V_20 = F_75 () ;
if ( V_20 == 'r' )
V_92 = 5 ;
else if ( V_20 == 'w' )
V_92 = 6 ;
else
V_75 = V_20 ;
V_53 . V_30 = 0 ;
V_53 . V_54 = 0 ;
if ( F_102 ( & V_53 . V_30 ) ) {
if ( ! F_105 ( V_53 . V_30 ) ) {
printf ( V_93 ) ;
break;
}
V_53 . V_30 &= ~ 7 ;
V_53 . V_54 = V_92 | V_94 ;
}
break;
case 'i' :
if ( ! F_69 ( V_67 ) ) {
printf ( L_46
L_47 ) ;
break;
}
if ( V_55 ) {
V_55 -> V_54 &= ~ ( V_66 | V_69 ) ;
V_55 = NULL ;
}
if ( ! F_102 ( & V_63 ) )
break;
if ( ! F_104 ( V_63 ) )
break;
V_22 = F_63 ( V_63 ) ;
if ( V_22 != NULL ) {
V_22 -> V_54 |= V_66 | V_69 ;
V_55 = V_22 ;
}
break;
#endif
case 'c' :
if ( ! F_102 ( & V_63 ) ) {
for ( V_58 = 0 ; V_58 < V_60 ; ++ V_58 )
V_59 [ V_58 ] . V_54 = 0 ;
V_55 = NULL ;
V_53 . V_54 = 0 ;
printf ( L_48 ) ;
break;
}
if ( V_63 <= V_60 && V_63 >= 1 ) {
V_22 = & V_59 [ V_63 - 1 ] ;
} else {
V_22 = F_29 ( V_63 ) ;
if ( V_22 == NULL ) {
printf ( L_49 , V_63 ) ;
break;
}
}
printf ( L_50 , F_30 ( V_22 ) ) ;
F_31 ( V_22 -> V_30 , L_7 , L_8 ) ;
V_22 -> V_54 = 0 ;
break;
default:
V_75 = V_20 ;
V_20 = F_73 () ;
if ( V_20 == '?' ) {
printf ( V_95 ) ;
break;
}
V_75 = V_20 ;
if ( ! F_102 ( & V_63 ) ) {
printf ( L_51 ) ;
if ( V_53 . V_54 ) {
printf ( L_52 V_96 L_53 , V_53 . V_30 ) ;
if ( V_53 . V_54 & 1 )
printf ( L_54 ) ;
if ( V_53 . V_54 & 2 )
printf ( L_55 ) ;
printf ( L_56 ) ;
}
for ( V_22 = V_59 ; V_22 < & V_59 [ V_60 ] ; ++ V_22 ) {
if ( ! V_22 -> V_54 )
continue;
printf ( L_57 , F_30 ( V_22 ) ,
( V_22 -> V_54 & V_66 ) ? L_58 : L_59 ) ;
F_31 ( V_22 -> V_30 , L_60 , L_32 ) ;
}
break;
}
if ( ! F_104 ( V_63 ) )
break;
V_22 = F_63 ( V_63 ) ;
if ( V_22 != NULL )
V_22 -> V_54 |= V_65 ;
break;
}
}
static
const char * F_26 ( unsigned long V_97 )
{
char * V_98 ;
switch ( V_97 ) {
case 0x100 : V_98 = L_61 ; break;
case 0x200 : V_98 = L_62 ; break;
case 0x300 : V_98 = L_63 ; break;
case 0x380 : V_98 = L_64 ; break;
case 0x400 : V_98 = L_65 ; break;
case 0x480 : V_98 = L_66 ; break;
case 0x500 : V_98 = L_67 ; break;
case 0x600 : V_98 = L_68 ; break;
case 0x700 : V_98 = L_69 ; break;
case 0x800 : V_98 = L_70 ; break;
case 0x900 : V_98 = L_71 ; break;
case 0xc00 : V_98 = L_72 ; break;
case 0xd00 : V_98 = L_73 ; break;
case 0xf00 : V_98 = L_74 ; break;
case 0xf20 : V_98 = L_75 ; break;
case 0x1300 : V_98 = L_76 ; break;
default: V_98 = L_77 ;
}
return V_98 ;
}
static void F_107 ( unsigned long V_57 , unsigned long * V_99 ,
unsigned long * V_100 )
{
unsigned long V_101 , V_25 ;
const char * V_102 ;
* V_99 = * V_100 = 0 ;
if ( V_57 == 0 )
return;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_102 = F_108 ( V_57 , & V_101 , & V_25 , NULL , V_104 ) ;
if ( V_102 != NULL ) {
* V_99 = V_57 - V_25 ;
* V_100 = V_57 - V_25 + V_101 ;
}
F_1 () ;
}
V_56 = 0 ;
}
static void F_71 ( unsigned long V_105 , unsigned long V_106 ,
unsigned long V_57 )
{
unsigned long V_107 ;
unsigned long V_108 ;
unsigned long V_109 ;
int V_85 = 0 ;
struct V_15 V_16 ;
do {
if ( V_105 < V_110 ) {
if ( V_105 != 0 )
printf ( L_78 , V_105 ) ;
break;
}
if ( ! F_65 ( V_105 + V_111 , & V_107 , sizeof( unsigned long ) )
|| ! F_65 ( V_105 , & V_108 , sizeof( unsigned long ) ) ) {
printf ( L_79 , V_105 ) ;
break;
}
if ( ( V_57 | V_106 ) != 0 ) {
unsigned long V_112 , V_113 ;
unsigned long V_114 ;
int V_115 = 1 ;
F_107 ( V_57 , & V_112 , & V_113 ) ;
V_114 = 0 ;
if ( V_108 > V_105 )
F_65 ( V_108 + V_111 , & V_114 ,
sizeof( unsigned long ) ) ;
if ( V_106 == V_107 ) {
if ( V_106 < V_110
|| ( V_112 <= V_106 && V_106 < V_113 ) )
V_115 = 0 ;
} else if ( V_106 == V_114 ) {
V_115 = 0 ;
} else if ( V_106 >= V_110
&& ! ( V_112 <= V_106 && V_106 < V_113 ) ) {
printf ( L_80 ) ;
F_31 ( V_106 , L_7 , L_32 ) ;
}
if ( V_115 ) {
printf ( L_81 V_96 L_82 , V_105 ) ;
F_31 ( V_107 , L_7 , L_83 ) ;
}
V_57 = V_106 = 0 ;
} else {
printf ( L_81 V_96 L_82 , V_105 ) ;
F_31 ( V_107 , L_7 , L_32 ) ;
}
if ( F_65 ( V_105 + V_116 , & V_109 , sizeof( unsigned long ) )
&& V_109 == V_117 ) {
if ( F_65 ( V_105 + V_118 , & V_16 , sizeof( V_16 ) )
!= sizeof( V_16 ) ) {
printf ( L_84 ,
V_105 + V_118 ) ;
break;
}
printf ( L_85 , V_16 . V_32 ,
F_26 ( F_27 ( & V_16 ) ) ) ;
V_57 = V_16 . V_29 ;
V_106 = V_16 . V_74 ;
F_31 ( V_57 , L_7 , L_32 ) ;
}
if ( V_108 == 0 )
break;
V_105 = V_108 ;
} while ( V_85 ++ < V_119 );
}
static void F_85 ( struct V_15 * V_49 )
{
unsigned long V_105 ;
if ( F_102 ( & V_105 ) )
F_71 ( V_105 , 0 , 0 ) ;
else
F_71 ( V_49 -> V_73 [ 1 ] , V_49 -> V_74 , V_49 -> V_29 ) ;
F_109 () ;
}
static void F_110 ( struct V_15 * V_16 )
{
#ifdef F_111
const struct V_120 * V_121 ;
unsigned long V_91 ;
if ( V_16 -> V_17 & V_41 )
return;
V_91 = V_16 -> V_29 ;
if ( V_91 < V_110 )
return;
V_121 = F_112 ( V_16 -> V_29 ) ;
if ( V_121 == NULL )
return;
if ( F_113 ( V_121 ) )
return;
#ifdef F_114
printf ( L_86 ,
V_121 -> V_122 , V_121 -> line ) ;
#else
printf ( L_87 , ( void * ) V_121 -> V_123 ) ;
#endif
#endif
}
static void F_25 ( struct V_15 * V_124 )
{
unsigned long V_32 ;
#ifdef F_19
printf ( L_88 , F_11 () ) ;
#endif
V_32 = F_27 ( V_124 ) ;
printf ( L_89 , V_124 -> V_32 , F_26 ( V_32 ) , V_124 ) ;
printf ( L_90 ) ;
F_31 ( V_124 -> V_29 , L_91 , L_32 ) ;
printf ( L_92 , V_124 -> V_74 ) ;
F_31 ( V_124 -> V_74 , L_91 , L_32 ) ;
printf ( L_93 , V_124 -> V_73 [ 1 ] ) ;
printf ( L_94 , V_124 -> V_17 ) ;
if ( V_32 == 0x300 || V_32 == 0x380 || V_32 == 0x600 ) {
printf ( L_95 , V_124 -> V_125 ) ;
if ( V_32 != 0x380 )
printf ( L_96 , V_124 -> V_126 ) ;
}
printf ( L_97 , V_127 ) ;
#ifdef F_115
printf ( L_98 , F_116 () ) ;
#endif
if ( V_127 ) {
printf ( L_99 ,
V_127 -> V_128 , V_127 -> V_129 ) ;
}
if ( V_32 == 0x700 )
F_110 ( V_124 ) ;
}
static void F_83 ( struct V_15 * V_124 )
{
int V_130 , V_32 ;
unsigned long V_131 ;
struct V_15 V_16 ;
if ( F_102 ( & V_131 ) ) {
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_16 = * (struct V_15 * ) V_131 ;
F_1 () ;
F_117 ( 200 ) ;
} else {
V_56 = 0 ;
printf ( L_100 V_96 L_32 ,
V_131 ) ;
return;
}
V_56 = 0 ;
V_124 = & V_16 ;
}
#ifdef F_115
if ( F_118 ( V_124 ) ) {
for ( V_130 = 0 ; V_130 < 16 ; ++ V_130 )
printf ( L_101 V_96 L_102 V_96 L_32 ,
V_130 , V_124 -> V_73 [ V_130 ] , V_130 + 16 , V_124 -> V_73 [ V_130 + 16 ] ) ;
} else {
for ( V_130 = 0 ; V_130 < 7 ; ++ V_130 )
printf ( L_101 V_96 L_102 V_96 L_32 ,
V_130 , V_124 -> V_73 [ V_130 ] , V_130 + 7 , V_124 -> V_73 [ V_130 + 7 ] ) ;
}
#else
for ( V_130 = 0 ; V_130 < 32 ; ++ V_130 ) {
printf ( L_103 , V_130 , V_124 -> V_73 [ V_130 ] ,
( V_130 & 3 ) == 3 ? L_32 : L_104 ) ;
if ( V_130 == 12 && ! F_118 ( V_124 ) ) {
printf ( L_32 ) ;
break;
}
}
#endif
printf ( L_105 ) ;
F_31 ( V_124 -> V_29 , L_7 , L_32 ) ;
if ( F_27 ( V_124 ) != 0xc00 && F_69 ( V_132 ) ) {
printf ( L_106 ) ;
F_31 ( V_124 -> V_133 , L_7 , L_32 ) ;
}
printf ( L_107 ) ;
F_31 ( V_124 -> V_74 , L_7 , L_32 ) ;
printf ( L_108 V_96 L_109 , V_124 -> V_17 , V_124 -> V_134 ) ;
printf ( L_110 V_96 L_111 V_96 L_112 ,
V_124 -> V_135 , V_124 -> V_136 , V_124 -> V_32 ) ;
V_32 = F_27 ( V_124 ) ;
if ( V_32 == 0x300 || V_32 == 0x380 || V_32 == 0x600 )
printf ( L_113 V_96 L_114 , V_124 -> V_125 , V_124 -> V_126 ) ;
}
static void F_86 ( void )
{
int V_20 ;
unsigned long V_137 ;
V_20 = F_75 () ;
if ( V_20 != 'i' )
V_75 = V_20 ;
F_102 ( ( void * ) & V_89 ) ;
if ( V_75 != '\n' )
V_75 = 0 ;
V_137 = 1 ;
F_102 ( & V_137 ) ;
V_137 = ( V_137 + V_138 - 1 ) / V_138 ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
if ( V_20 != 'i' ) {
for (; V_137 > 0 ; -- V_137 , V_89 += V_138 )
F_3 ( ( void * ) V_89 ) ;
} else {
for (; V_137 > 0 ; -- V_137 , V_89 += V_138 )
F_4 ( ( void * ) V_89 ) ;
}
F_1 () ;
F_117 ( 200 ) ;
}
V_56 = 0 ;
}
static unsigned long
F_119 ( int V_130 )
{
unsigned int V_139 [ 2 ] ;
unsigned long ( * V_140 ) ( void ) ;
unsigned long V_98 = - 1UL ;
#ifdef F_115
unsigned long V_141 [ 3 ] ;
V_141 [ 0 ] = ( unsigned long ) V_139 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = 0 ;
V_140 = ( unsigned long ( * ) ( void ) ) V_141 ;
#else
V_140 = ( unsigned long ( * ) ( void ) ) V_139 ;
#endif
V_139 [ 0 ] = 0x7c6002a6 + ( ( V_130 & 0x1F ) << 16 ) + ( ( V_130 & 0x3e0 ) << 6 ) ;
V_139 [ 1 ] = 0x4e800020 ;
F_2 ( V_139 ) ;
F_2 ( V_139 + 1 ) ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_98 = V_140 () ;
F_1 () ;
F_117 ( 200 ) ;
V_130 = V_101 ;
}
return V_98 ;
}
static void
F_120 ( int V_130 , unsigned long V_142 )
{
unsigned int V_139 [ 2 ] ;
unsigned long ( * V_140 ) ( unsigned long ) ;
#ifdef F_115
unsigned long V_141 [ 3 ] ;
V_141 [ 0 ] = ( unsigned long ) V_139 ;
V_141 [ 1 ] = 0 ;
V_141 [ 2 ] = 0 ;
V_140 = ( unsigned long (*) ( unsigned long ) ) V_141 ;
#else
V_140 = ( unsigned long (*) ( unsigned long ) ) V_139 ;
#endif
V_139 [ 0 ] = 0x7c6003a6 + ( ( V_130 & 0x1F ) << 16 ) + ( ( V_130 & 0x3e0 ) << 6 ) ;
V_139 [ 1 ] = 0x4e800020 ;
F_2 ( V_139 ) ;
F_2 ( V_139 + 1 ) ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_140 ( V_142 ) ;
F_1 () ;
F_117 ( 200 ) ;
V_130 = V_101 ;
}
}
static void F_84 ( void )
{
int V_20 ;
unsigned long V_142 ;
V_20 = F_73 () ;
if ( V_20 == '\n' ) {
unsigned long V_105 , V_143 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_115 V_96 L_116 V_96 L_32 ,
F_121 () , F_101 ( V_144 ) ) ;
printf ( L_117 V_96 L_118 V_96 L_32 ,
F_101 ( V_145 ) , F_101 ( V_146 ) ) ;
printf ( L_119 V_96 L_120 V_96 L_32 ,
F_101 ( V_147 ) , F_101 ( V_148 ) ) ;
printf ( L_121 V_96 L_122 V_96 L_32 , V_105 , F_101 ( V_149 ) ) ;
printf ( L_123 V_96 L_124 V_96 L_32 , V_143 , F_101 ( V_150 ) ) ;
#ifdef F_122
if ( F_123 ( V_151 ) ) {
struct V_152 * V_153 ;
struct V_154 * V_155 ;
printf ( L_125 ) ;
V_153 = F_116 () ;
printf ( L_126 ) ;
V_155 = V_153 -> V_156 ;
printf ( L_127 ,
V_155 -> V_157 , V_155 -> V_158 ) ;
printf ( L_128 ,
V_155 -> V_159 , V_155 -> V_160 ) ;
printf ( L_129 ,
V_155 -> V_161 . V_162 ) ;
}
#endif
return;
}
F_102 ( & V_163 ) ;
switch ( V_20 ) {
case 'w' :
V_142 = F_119 ( V_163 ) ;
F_102 ( & V_142 ) ;
F_120 ( V_163 , V_142 ) ;
case 'r' :
printf ( L_130 , V_163 , F_119 ( V_163 ) ) ;
break;
}
F_109 () ;
}
static int
F_65 ( unsigned long V_89 , void * V_164 , int V_101 )
{
volatile int V_130 ;
char * V_1 , * V_165 ;
V_130 = 0 ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_1 = ( char * ) V_89 ;
V_165 = ( char * ) V_164 ;
switch ( V_101 ) {
case 2 :
* ( V_166 * ) V_165 = * ( V_166 * ) V_1 ;
break;
case 4 :
* ( V_167 * ) V_165 = * ( V_167 * ) V_1 ;
break;
case 8 :
* ( V_168 * ) V_165 = * ( V_168 * ) V_1 ;
break;
default:
for( ; V_130 < V_101 ; ++ V_130 ) {
* V_165 ++ = * V_1 ++ ;
F_1 () ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_130 = V_101 ;
}
V_56 = 0 ;
return V_130 ;
}
static int
F_67 ( unsigned long V_89 , void * V_164 , int V_101 )
{
volatile int V_130 ;
char * V_1 , * V_165 ;
V_130 = 0 ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_1 = ( char * ) V_89 ;
V_165 = ( char * ) V_164 ;
switch ( V_101 ) {
case 2 :
* ( V_166 * ) V_1 = * ( V_166 * ) V_165 ;
break;
case 4 :
* ( V_167 * ) V_1 = * ( V_167 * ) V_165 ;
break;
case 8 :
* ( V_168 * ) V_1 = * ( V_168 * ) V_165 ;
break;
default:
for ( ; V_130 < V_101 ; ++ V_130 ) {
* V_1 ++ = * V_165 ++ ;
F_1 () ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_130 = V_101 ;
} else {
printf ( L_131 , V_89 + V_130 ) ;
}
V_56 = 0 ;
return V_130 ;
}
static int F_61 ( struct V_15 * V_16 )
{
V_169 = F_27 ( V_16 ) ;
switch ( F_27 ( V_16 ) ) {
case 0x200 :
V_170 = 0 ;
break;
case 0x300 :
case 0x380 :
V_170 = 1 ;
break;
default:
V_170 = 2 ;
}
longjmp ( V_103 , 1 ) ;
return 0 ;
}
static void
F_124 ( unsigned char * V_142 , int V_101 )
{
int V_171 ;
switch ( V_101 ) {
case 2 :
F_125 ( V_142 [ 0 ] , V_142 [ 1 ] , V_171 ) ;
break;
case 4 :
F_125 ( V_142 [ 0 ] , V_142 [ 3 ] , V_171 ) ;
F_125 ( V_142 [ 1 ] , V_142 [ 2 ] , V_171 ) ;
break;
case 8 :
F_125 ( V_142 [ 0 ] , V_142 [ 7 ] , V_171 ) ;
F_125 ( V_142 [ 1 ] , V_142 [ 6 ] , V_171 ) ;
F_125 ( V_142 [ 2 ] , V_142 [ 5 ] , V_171 ) ;
F_125 ( V_142 [ 3 ] , V_142 [ 4 ] , V_171 ) ;
break;
}
}
static void
F_80 ( void )
{
int V_20 , V_172 , V_58 , V_173 ;
unsigned long V_130 ;
unsigned char V_142 [ 16 ] ;
F_102 ( ( void * ) & V_89 ) ;
V_20 = F_73 () ;
if ( V_20 == '?' ) {
printf ( V_174 ) ;
return;
} else {
V_75 = V_20 ;
}
V_70 = L_132 ;
while ( ( V_20 = F_73 () ) != '\n' ) {
switch( V_20 ) {
case 'b' : V_101 = 1 ; break;
case 'w' : V_101 = 2 ; break;
case 'l' : V_101 = 4 ; break;
case 'd' : V_101 = 8 ; break;
case 'r' : V_175 = ! V_175 ; break;
case 'n' : V_176 = 1 ; break;
case '.' : V_176 = 0 ; break;
}
}
if( V_101 <= 0 )
V_101 = 1 ;
else if( V_101 > 8 )
V_101 = 8 ;
for(; ; ) {
if ( ! V_176 )
V_130 = F_65 ( V_89 , V_142 , V_101 ) ;
printf ( V_96 L_133 , V_89 , V_175 ? 'r' : ' ' ) ;
if ( ! V_176 ) {
if ( V_175 )
F_124 ( V_142 , V_101 ) ;
putchar ( ' ' ) ;
for ( V_58 = 0 ; V_58 < V_130 ; ++ V_58 )
printf ( L_134 , V_142 [ V_58 ] ) ;
for (; V_58 < V_101 ; ++ V_58 )
printf ( L_135 , V_177 [ V_170 ] ) ;
}
putchar ( ' ' ) ;
V_172 = V_101 ;
V_173 = 0 ;
for(; ; ) {
if( F_102 ( & V_130 ) ) {
for ( V_58 = 0 ; V_58 < V_101 ; ++ V_58 )
V_142 [ V_58 ] = V_130 >> ( V_58 * 8 ) ;
if ( ! V_175 )
F_124 ( V_142 , V_101 ) ;
F_67 ( V_89 , V_142 , V_101 ) ;
V_172 = V_101 ;
}
V_20 = F_73 () ;
if ( V_20 == '\n' )
break;
V_172 = 0 ;
switch ( V_20 ) {
case '\'' :
for(; ; ) {
V_130 = F_75 () ;
if( V_130 == '\\' )
V_130 = F_126 () ;
else if( V_130 == '\'' )
break;
for ( V_58 = 0 ; V_58 < V_101 ; ++ V_58 )
V_142 [ V_58 ] = V_130 >> ( V_58 * 8 ) ;
if ( ! V_175 )
F_124 ( V_142 , V_101 ) ;
F_67 ( V_89 , V_142 , V_101 ) ;
V_89 += V_101 ;
}
V_89 -= V_101 ;
V_172 = V_101 ;
break;
case ',' :
V_89 += V_101 ;
break;
case '.' :
V_176 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_48 :
F_109 () ;
return;
case 'b' :
case 'v' :
V_101 = 1 ;
break;
case 'w' :
V_101 = 2 ;
break;
case 'l' :
V_101 = 4 ;
break;
case 'u' :
V_101 = 8 ;
break;
case '^' :
V_89 -= V_101 ;
break;
break;
case '/' :
if ( V_173 > 0 )
V_89 -= 1 << V_173 ;
else
V_173 = 0 ;
V_173 += 4 ;
V_89 += 1 << V_173 ;
break;
case '\\' :
if ( V_173 < 0 )
V_89 += 1 << - V_173 ;
else
V_173 = 0 ;
V_173 -= 4 ;
V_89 -= 1 << - V_173 ;
break;
case 'm' :
F_102 ( ( void * ) & V_89 ) ;
break;
case 'n' :
V_176 = 1 ;
break;
case 'r' :
V_175 = ! V_175 ;
break;
case '<' :
V_130 = V_101 ;
F_102 ( & V_130 ) ;
V_89 -= V_130 ;
break;
case '>' :
V_130 = V_101 ;
F_102 ( & V_130 ) ;
V_89 += V_130 ;
break;
case '?' :
printf ( V_178 ) ;
break;
}
}
V_89 += V_172 ;
}
}
static int
F_126 ( void )
{
int V_179 ;
V_179 = F_75 () ;
switch( V_179 ) {
case 'n' : V_179 = '\n' ; break;
case 'r' : V_179 = '\r' ; break;
case 'b' : V_179 = '\b' ; break;
case 't' : V_179 = '\t' ; break;
}
return V_179 ;
}
static void F_127 ( unsigned long V_89 , long V_180 )
{
long V_130 , V_181 , V_182 , V_183 ;
unsigned char V_184 [ 16 ] ;
for ( V_130 = V_180 ; V_130 > 0 ; ) {
V_182 = V_130 < 16 ? V_130 : 16 ;
V_183 = F_65 ( V_89 , V_184 , V_182 ) ;
V_89 += V_183 ;
for ( V_181 = 0 ; V_181 < V_182 ; ++ V_181 ) {
if ( V_181 < V_183 )
printf ( L_134 , V_184 [ V_181 ] ) ;
else
printf ( L_135 , V_177 [ V_170 ] ) ;
}
V_130 -= V_182 ;
if ( V_183 < V_182 )
break;
}
printf ( L_32 ) ;
}
static void
F_81 ( void )
{
int V_179 ;
V_179 = F_75 () ;
if ( ( isxdigit ( V_179 ) && V_179 != 'f' && V_179 != 'd' ) || V_179 == '\n' )
V_75 = V_179 ;
F_102 ( ( void * ) & V_89 ) ;
if ( V_75 != '\n' )
V_75 = 0 ;
if ( V_179 == 'i' ) {
F_102 ( & V_185 ) ;
if ( V_185 == 0 )
V_185 = 16 ;
else if ( V_185 > V_186 )
V_185 = V_186 ;
V_89 += F_39 ( V_89 , V_185 , 1 ) ;
V_70 = L_136 ;
} else if ( V_179 == 'l' ) {
F_128 () ;
} else if ( V_179 == 'r' ) {
F_102 ( & V_180 ) ;
if ( V_180 == 0 )
V_180 = 64 ;
F_127 ( V_89 , V_180 ) ;
V_89 += V_180 ;
V_70 = L_137 ;
} else {
F_102 ( & V_180 ) ;
if ( V_180 == 0 )
V_180 = 64 ;
else if ( V_180 > V_186 )
V_180 = V_186 ;
F_129 ( V_89 , V_180 ) ;
V_89 += V_180 ;
V_70 = L_138 ;
}
}
static void
F_129 ( unsigned long V_89 , long V_180 )
{
long V_130 , V_181 , V_179 , V_182 , V_183 ;
unsigned char V_184 [ 16 ] ;
for ( V_130 = V_180 ; V_130 > 0 ; ) {
printf ( V_96 , V_89 ) ;
putchar ( ' ' ) ;
V_182 = V_130 < 16 ? V_130 : 16 ;
V_183 = F_65 ( V_89 , V_184 , V_182 ) ;
V_89 += V_183 ;
for ( V_181 = 0 ; V_181 < V_182 ; ++ V_181 ) {
if ( ( V_181 & ( sizeof( long ) - 1 ) ) == 0 && V_181 > 0 )
putchar ( ' ' ) ;
if ( V_181 < V_183 )
printf ( L_134 , V_184 [ V_181 ] ) ;
else
printf ( L_135 , V_177 [ V_170 ] ) ;
}
for (; V_181 < 16 ; ++ V_181 ) {
if ( ( V_181 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_60 ) ;
}
printf ( L_139 ) ;
for ( V_181 = 0 ; V_181 < V_182 ; ++ V_181 ) {
if ( V_181 < V_183 ) {
V_179 = V_184 [ V_181 ] ;
putchar ( ' ' <= V_179 && V_179 <= '~' ? V_179 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_130 -= V_182 ;
for (; V_181 < 16 ; ++ V_181 )
putchar ( ' ' ) ;
printf ( L_140 ) ;
if ( V_183 < V_182 )
break;
}
}
static int
F_130 ( unsigned long V_187 , long V_85 , int V_188 ,
T_2 V_189 )
{
int V_183 , V_190 ;
unsigned long V_191 ;
unsigned long V_192 , V_193 = 0 ;
unsigned char V_142 [ 4 ] ;
V_190 = 0 ;
for ( V_191 = V_187 ; V_85 > 0 ; -- V_85 , V_187 += 4 ) {
V_183 = F_65 ( V_187 , V_142 , 4 ) ;
if ( V_183 == 0 ) {
if ( V_188 ) {
const char * V_194 = V_177 [ V_170 ] ;
printf ( V_96 L_141 , V_187 , V_194 , V_194 , V_194 , V_194 ) ;
}
break;
}
V_192 = F_131 ( V_142 ) ;
if ( V_187 > V_191 && V_192 == V_193 ) {
if ( ! V_190 ) {
printf ( L_142 ) ;
V_190 = 1 ;
}
continue;
}
V_190 = 0 ;
V_193 = V_192 ;
if ( V_188 )
printf ( V_96 L_143 , V_187 , V_192 ) ;
printf ( L_144 ) ;
V_189 ( V_192 , V_187 ) ;
printf ( L_32 ) ;
}
return V_187 - V_191 ;
}
static int
F_39 ( unsigned long V_187 , long V_85 , int V_188 )
{
return F_130 ( V_187 , V_85 , V_188 , V_195 ) ;
}
void
F_132 ( unsigned long V_91 )
{
F_31 ( V_91 , L_145 , L_77 ) ;
}
void
F_128 ( void )
{
const unsigned long V_101 = 128 ;
unsigned long V_196 , V_91 ;
unsigned char V_164 [ V_101 + 1 ] ;
V_91 = 0 ;
V_164 [ V_101 ] = '\0' ;
if ( setjmp ( V_103 ) != 0 ) {
printf ( L_146 ) ;
return;
}
V_56 = 1 ;
F_1 () ;
V_91 = F_133 ( L_147 ) ;
if ( ! V_91 )
printf ( L_148 ) ;
else {
V_196 = V_91 + ( 1 << V_197 ) ;
while ( V_91 < V_196 ) {
if ( ! F_65 ( V_91 , V_164 , V_101 ) ) {
printf ( L_149 , V_91 ) ;
break;
}
printf ( L_135 , V_164 ) ;
if ( strlen ( V_164 ) < V_101 )
break;
V_91 += V_101 ;
}
}
F_1 () ;
F_117 ( 200 ) ;
V_56 = 0 ;
}
static void
F_76 ( int V_20 )
{
F_102 ( ( void * ) & V_198 ) ;
if( V_75 != '\n' )
V_75 = 0 ;
F_102 ( ( void * ) ( V_20 == 's' ? & V_199 : & V_200 ) ) ;
if( V_75 != '\n' )
V_75 = 0 ;
F_102 ( ( void * ) & V_201 ) ;
switch( V_20 ) {
case 'm' :
memmove ( ( void * ) V_198 , ( void * ) V_200 , V_201 ) ;
break;
case 's' :
memset ( ( void * ) V_198 , V_199 , V_201 ) ;
break;
case 'd' :
if( V_75 != '\n' )
V_75 = 0 ;
F_102 ( ( void * ) & V_202 ) ;
F_134 ( ( unsigned char * ) V_198 , ( unsigned char * ) V_200 , V_201 , V_202 ) ;
break;
}
}
static void
F_134 ( unsigned char * V_203 , unsigned char * V_204 , unsigned V_205 , unsigned V_206 )
{
unsigned V_130 , V_207 ;
V_207 = 0 ;
for( V_130 = V_205 ; V_130 > 0 ; -- V_130 )
if( * V_203 ++ != * V_204 ++ )
if( ++ V_207 <= V_206 )
printf ( L_150 , V_203 - 1 ,
V_203 [ - 1 ] , V_204 - 1 , V_204 [ - 1 ] ) ;
if( V_207 > V_206 )
printf ( L_151 , V_207 ) ;
}
static void
F_77 ( void )
{
unsigned V_63 , V_130 ;
unsigned char V_142 [ 4 ] ;
V_70 = L_152 ;
F_102 ( ( void * ) & V_198 ) ;
if ( V_75 != '\n' ) {
V_75 = 0 ;
F_102 ( ( void * ) & V_208 ) ;
if ( V_75 != '\n' ) {
V_75 = 0 ;
F_102 ( ( void * ) & V_199 ) ;
V_209 = ~ 0 ;
if ( V_75 != '\n' ) V_75 = 0 ;
F_102 ( ( void * ) & V_209 ) ;
}
}
V_130 = 0 ;
for ( V_63 = V_198 ; V_63 < V_208 ; V_63 += 4 ) {
if ( F_65 ( V_63 , V_142 , 4 ) == 4
&& ( ( F_131 ( V_142 ) ^ V_199 ) & V_209 ) == 0 ) {
printf ( L_153 , V_63 , F_131 ( V_142 ) ) ;
if ( ++ V_130 >= 10 )
break;
}
}
}
static void
F_78 ( void )
{
unsigned char V_88 ;
unsigned V_63 ;
int V_210 , V_211 ;
F_102 ( & V_198 ) ;
if ( V_75 != '\n' ) V_75 = 0 ;
F_102 ( & V_212 ) ;
if ( V_75 != '\n' ) V_75 = 0 ;
F_102 ( & V_213 ) ;
V_211 = 0 ;
for ( V_63 = V_198 ; V_63 < V_213 ; V_63 += V_212 ) {
V_210 = F_65 ( V_63 , & V_88 , 1 ) ;
if ( V_210 && ! V_211 ) {
printf ( L_154 , V_63 ) ;
} else if ( ! V_210 && V_211 )
printf ( L_155 , V_63 - V_212 ) ;
V_211 = V_210 ;
if ( V_63 + V_212 < V_63 )
break;
}
if ( V_211 )
printf ( L_155 , V_63 - V_212 ) ;
}
static void F_95 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_98 ;
int V_58 ;
typedef unsigned long (* T_3)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_3 V_214 ;
if ( ! F_102 ( & V_89 ) )
return;
if ( V_75 != '\n' )
V_75 = 0 ;
for ( V_58 = 0 ; V_58 < 8 ; ++ V_58 )
args [ V_58 ] = 0 ;
for ( V_58 = 0 ; V_58 < 8 ; ++ V_58 ) {
if ( ! F_102 ( & args [ V_58 ] ) || V_75 == '\n' )
break;
V_75 = 0 ;
}
V_214 = ( T_3 ) V_89 ;
V_98 = 0 ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_98 = V_214 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_1 () ;
printf ( L_156 , V_98 ) ;
} else {
printf ( L_157 , V_169 ) ;
}
V_56 = 0 ;
}
int
F_73 ( void )
{
int V_179 ;
if( V_75 != 0 ) {
V_179 = V_75 ;
V_75 = 0 ;
} else
V_179 = F_75 () ;
while( V_179 == ' ' || V_179 == '\t' )
V_179 = F_75 () ;
return V_179 ;
}
int
F_102 ( unsigned long * V_215 )
{
int V_179 , V_51 ;
unsigned long V_88 ;
V_179 = F_73 () ;
if ( V_179 == '%' ) {
char V_216 [ 8 ] ;
int V_58 ;
for ( V_58 = 0 ; V_58 < sizeof( V_216 ) - 1 ; ++ V_58 ) {
V_179 = F_75 () ;
if ( ! isalnum ( V_179 ) ) {
V_75 = V_179 ;
break;
}
V_216 [ V_58 ] = V_179 ;
}
V_216 [ V_58 ] = 0 ;
for ( V_58 = 0 ; V_58 < V_217 ; ++ V_58 ) {
if ( strcmp ( V_218 [ V_58 ] , V_216 ) == 0 ) {
if ( V_71 == NULL ) {
printf ( L_158 ) ;
return 0 ;
}
* V_215 = ( ( unsigned long * ) V_71 ) [ V_58 ] ;
return 1 ;
}
}
printf ( L_159 , V_216 ) ;
return 0 ;
}
if ( V_179 == '0' ) {
V_179 = F_75 () ;
if ( V_179 == 'x' ) {
V_179 = F_75 () ;
} else {
V_51 = F_135 ( V_179 ) ;
if ( V_51 == V_48 ) {
V_75 = V_179 ;
* V_215 = 0 ;
return 1 ;
}
}
} else if ( V_179 == '$' ) {
int V_58 ;
for ( V_58 = 0 ; V_58 < 63 ; V_58 ++ ) {
V_179 = F_75 () ;
if ( isspace ( V_179 ) ) {
V_75 = V_179 ;
break;
}
V_104 [ V_58 ] = V_179 ;
}
V_104 [ V_58 ++ ] = 0 ;
* V_215 = 0 ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
* V_215 = F_133 ( V_104 ) ;
F_1 () ;
}
V_56 = 0 ;
if ( ! ( * V_215 ) ) {
printf ( L_160 , V_104 ) ;
return 0 ;
}
return 1 ;
}
V_51 = F_135 ( V_179 ) ;
if ( V_51 == V_48 ) {
V_75 = V_179 ;
return 0 ;
}
V_88 = 0 ;
do {
V_88 = ( V_88 << 4 ) + V_51 ;
V_179 = F_75 () ;
V_51 = F_135 ( V_179 ) ;
} while ( V_51 != V_48 );
V_75 = V_179 ;
* V_215 = V_88 ;
return 1 ;
}
static void
F_109 ( void )
{
int V_179 ;
V_179 = V_75 ;
V_75 = 0 ;
while( V_179 != '\n' )
V_179 = F_75 () ;
}
static int F_135 ( int V_179 )
{
if( '0' <= V_179 && V_179 <= '9' )
return V_179 - '0' ;
if( 'A' <= V_179 && V_179 <= 'F' )
return V_179 - ( 'A' - 10 ) ;
if( 'a' <= V_179 && V_179 <= 'f' )
return V_179 - ( 'a' - 10 ) ;
return V_48 ;
}
void
F_136 ( char * V_219 , int V_101 )
{
int V_179 ;
V_179 = F_73 () ;
do {
if( V_101 > 1 ) {
* V_219 ++ = V_179 ;
-- V_101 ;
}
V_179 = F_75 () ;
} while( V_179 != ' ' && V_179 != '\t' && V_179 != '\n' );
V_75 = V_179 ;
* V_219 = 0 ;
}
static void
F_72 ( void )
{
V_220 = NULL ;
}
static int
F_75 ( void )
{
if ( V_220 == NULL || * V_220 == 0 ) {
if ( F_137 ( line , sizeof( line ) ) == NULL ) {
V_220 = NULL ;
return V_48 ;
}
V_220 = line ;
}
return * V_220 ++ ;
}
static void
F_74 ( char * V_221 )
{
V_220 = V_221 ;
}
static void
F_82 ( void )
{
int type = F_75 () ;
unsigned long V_91 ;
static char V_222 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_102 ( & V_91 ) )
F_31 ( V_91 , L_91 , L_32 ) ;
V_75 = 0 ;
break;
case 's' :
F_136 ( V_222 , 64 ) ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_91 = F_133 ( V_222 ) ;
if ( V_91 )
printf ( L_161 , V_222 , V_91 ) ;
else
printf ( L_162 , V_222 ) ;
F_1 () ;
}
V_56 = 0 ;
V_75 = 0 ;
break;
}
}
static void F_31 ( unsigned long V_30 , const char * V_223 ,
const char * V_224 )
{
char * V_225 ;
const char * V_102 = NULL ;
unsigned long V_25 , V_101 ;
printf ( V_96 , V_30 ) ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_102 = F_108 ( V_30 , & V_101 , & V_25 , & V_225 ,
V_104 ) ;
F_1 () ;
F_117 ( 200 ) ;
}
V_56 = 0 ;
if ( V_102 ) {
printf ( L_163 , V_223 , V_102 , V_25 , V_101 ) ;
if ( V_225 )
printf ( L_164 , V_225 ) ;
}
printf ( L_135 , V_224 ) ;
}
static void F_138 ( void )
{
int V_58 ;
unsigned long V_226 , V_227 , V_228 ;
unsigned long V_229 ;
printf ( L_165 , F_11 () ) ;
for ( V_58 = 0 ; V_58 < V_230 ; V_58 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
V_228 = ( V_226 & V_231 ) ;
if ( V_228 | V_226 | V_227 ) {
printf ( L_166 , V_58 , V_226 , V_227 ) ;
if ( V_228 ) {
V_229 = V_227 & V_232 ;
if ( V_227 & V_233 ) {
printf ( L_167 ,
F_139 ( V_226 ) ,
( V_227 & ~ V_234 ) >> V_235 ,
V_229 ) ;
} else {
printf ( L_168 ,
F_140 ( V_226 ) ,
( V_227 & ~ V_234 ) >> V_236 ,
V_229 ) ;
}
} else
printf ( L_32 ) ;
}
}
}
static void F_141 ( void )
{
int V_58 ;
unsigned long * V_222 = ( unsigned long * ) F_116 () -> V_237 ;
printf ( L_169 , F_11 () ) ;
for ( V_58 = 0 ; V_58 < V_238 / 16 ; V_58 ++ ) {
unsigned long V_63 , V_239 ;
V_63 = * V_222 ++ ;
V_239 = * V_222 ++ ;
if ( V_63 || V_239 ) {
printf ( L_170 , V_58 , V_63 ) ;
printf ( L_171 , V_239 ) ;
}
}
}
void F_97 ( void )
{
if ( F_142 ( V_240 ) )
F_138 () ;
else
F_141 () ;
}
void F_97 ( void )
{
int V_58 ;
printf ( L_172 ) ;
for ( V_58 = 0 ; V_58 < 16 ; ++ V_58 )
printf ( L_34 , F_143 ( V_58 ) ) ;
printf ( L_32 ) ;
}
static void F_98 ( void )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_241 ; V_58 ++ ) {
unsigned long V_242 , V_243 , V_244 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_173 , V_58 , V_242 , V_243 , V_244 ) ;
if ( V_242 & V_245 ) {
printf ( L_174 ,
V_242 & V_246 ,
V_243 & V_247 ,
V_243 & V_248 ,
( V_244 & V_249 ) ? 'W' : 'w' ,
( V_244 & V_250 ) ? 'I' : 'i' ,
( V_244 & V_251 ) ? 'M' : 'm' ,
( V_244 & V_252 ) ? 'G' : 'g' ,
( V_244 & V_253 ) ? 'E' : 'e' ) ;
}
printf ( L_32 ) ;
}
}
static void F_100 ( void )
{
V_167 V_254 , V_255 , V_256 ;
V_168 V_257 ;
int V_58 , V_258 , V_259 , V_260 , V_261 , V_262 , V_263 = 0 ;
int V_264 ;
static const char * V_265 [] = {
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
V_254 = F_101 ( V_266 ) ;
V_264 = ( V_254 & 3 ) + 1 ;
V_259 = ( ( V_254 >> 2 ) & 3 ) + 1 ;
V_260 = ( ( V_254 >> 6 ) & 0x1f ) + 1 ;
V_261 = ( V_254 >> 24 ) & 0xf ;
V_262 = ( V_254 >> 16 ) & 0x7f ;
if ( ( V_264 > 1 ) && ( V_254 & 0x10000 ) )
V_263 = 1 ;
printf ( L_207 ,
V_264 , V_259 , V_260 , V_261 , V_262 ) ;
V_255 = ( 1ul << V_260 ) - 1 ;
V_256 = ( 1ul << V_261 ) - 1 ;
V_257 = ( 1ull << V_262 ) - 1 ;
for ( V_258 = 0 ; V_258 < V_259 ; V_258 ++ ) {
V_167 V_267 ;
int V_268 , V_269 , V_270 = 1 ;
printf ( L_208 , V_258 ) ;
switch( V_258 ) {
case 0 :
V_267 = F_101 ( V_271 ) ;
break;
case 1 :
V_267 = F_101 ( V_272 ) ;
break;
case 2 :
V_267 = F_101 ( V_273 ) ;
break;
case 3 :
V_267 = F_101 ( V_274 ) ;
break;
default:
printf ( L_209 ) ;
continue;
}
V_268 = V_267 & 0xfff ;
V_269 = ( V_267 >> 24 ) & 0xff ;
for ( V_58 = 0 ; V_58 < V_268 ; V_58 ++ ) {
V_167 V_275 = F_144 ( V_258 ) ;
V_167 V_276 = F_145 ( V_277 ) ;
V_168 V_278 = 0 ;
V_168 V_279 ;
int V_280 = V_58 , V_281 = V_58 ;
if ( V_269 != 0 ) {
V_281 = V_58 / V_269 ;
V_280 = V_58 % V_269 ;
V_278 = V_281 * 0x1000 ;
}
V_275 |= F_146 ( V_280 ) ;
F_70 ( V_282 , V_275 ) ;
F_70 ( V_283 , V_276 ) ;
F_70 ( V_284 , V_278 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_276 = F_101 ( V_283 ) ;
V_278 = F_101 ( V_284 ) ;
V_279 = F_101 ( V_285 ) ;
if ( V_269 && ( V_58 % V_269 ) == 0 )
V_270 = 1 ;
if ( ! ( V_276 & V_286 ) )
continue;
if ( V_269 == 0 )
printf ( L_210 , V_58 ) ;
else if ( V_270 )
printf ( L_211 , V_281 , 'A' + V_280 ) ;
else
printf ( L_212 , 'A' + V_280 ) ;
V_270 = 0 ;
printf ( L_213 ,
V_278 & ~ 0x3ffull ,
( V_276 >> 16 ) & 0x3fff ,
V_265 [ ( V_276 >> 7 ) & 0x1f ] ,
V_276 & V_287 ? 'I' : ' ' ,
V_276 & V_288 ? 'P' : ' ' ,
V_276 & V_289 ? '1' : '0' ) ;
printf ( L_214 ,
V_278 & V_290 ? 'a' : ' ' ,
V_278 & V_291 ? 'v' : ' ' ,
V_278 & V_292 ? 'w' : ' ' ,
V_278 & V_293 ? 'i' : ' ' ,
V_278 & V_294 ? 'm' : ' ' ,
V_278 & V_295 ? 'g' : ' ' ,
V_278 & V_296 ? 'e' : ' ' ) ;
printf ( L_215 , V_279 & V_257 & ~ 0x7ffull ) ;
if ( V_276 & V_287 )
printf ( L_216 ,
V_265 [ ( V_279 >> 1 ) & 0x1f ] ) ;
else
printf ( L_217 ,
V_279 & V_297 ? 'x' : ' ' ,
V_279 & V_298 ? 'w' : ' ' ,
V_279 & V_299 ? 'r' : ' ' ,
V_279 & V_300 ? 'x' : ' ' ,
V_279 & V_301 ? 'w' : ' ' ,
V_279 & V_302 ? 'r' : ' ' ) ;
}
}
}
static void F_147 ( int V_303 )
{
#ifdef F_122
if ( F_123 ( V_151 ) )
return;
#endif
if ( V_303 ) {
V_304 = F_50 ;
V_305 = F_59 ;
V_306 = F_54 ;
V_307 = F_55 ;
V_308 = F_58 ;
V_309 = F_57 ;
V_310 = F_60 ;
} else {
V_304 = NULL ;
V_305 = NULL ;
V_306 = NULL ;
V_307 = NULL ;
V_308 = NULL ;
V_309 = NULL ;
V_310 = NULL ;
}
F_148 () ;
}
static void F_149 ( int V_311 )
{
F_147 ( 1 ) ;
F_150 ( F_53 () ) ;
}
static int T_4 F_151 ( void )
{
#ifdef F_122
if ( F_123 ( V_151 ) )
return 0 ;
#endif
F_152 ( 'x' , & V_312 ) ;
return 0 ;
}
static int T_4 F_153 ( char * V_1 )
{
if ( ! V_1 || strncmp ( V_1 , L_218 , 5 ) == 0 ) {
F_147 ( 1 ) ;
V_313 = 1 ;
} else if ( strncmp ( V_1 , L_219 , 2 ) == 0 )
F_147 ( 1 ) ;
else if ( strncmp ( V_1 , L_220 , 3 ) == 0 )
V_314 = 1 ;
else if ( strncmp ( V_1 , L_221 , 4 ) == 0 )
V_72 = 1 ;
else
return 1 ;
return 0 ;
}
void T_4 F_154 ( void )
{
#ifdef F_155
if ( ! V_314 )
F_147 ( 1 ) ;
#endif
if ( V_313 )
F_150 ( NULL ) ;
}
void F_156 ( struct V_315 * V_316 )
{
struct V_317 * V_317 ;
F_157 (spu, list, full_list) {
if ( V_317 -> V_318 >= V_319 ) {
F_158 ( 1 ) ;
continue;
}
V_320 [ V_317 -> V_318 ] . V_317 = V_317 ;
V_320 [ V_317 -> V_318 ] . V_321 = 0 ;
V_320 [ V_317 -> V_318 ] . V_322 = ( unsigned long )
V_320 [ V_317 -> V_318 ] . V_317 -> V_323 ;
}
}
static void F_159 ( void )
{
struct V_317 * V_317 ;
int V_58 ;
V_168 V_222 ;
for ( V_58 = 0 ; V_58 < V_319 ; V_58 ++ ) {
if ( ! V_320 [ V_58 ] . V_317 )
continue;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_317 = V_320 [ V_58 ] . V_317 ;
V_320 [ V_58 ] . V_324 =
F_160 ( & V_317 -> V_325 -> V_326 ) ;
V_222 = F_161 ( V_317 ) ;
V_320 [ V_58 ] . V_327 = V_222 ;
V_222 &= ~ V_328 ;
F_162 ( V_317 , V_222 ) ;
F_1 () ;
F_117 ( 200 ) ;
V_320 [ V_58 ] . V_321 = 1 ;
printf ( L_222 , V_58 ,
V_320 [ V_58 ] . V_324 ?
L_223 : L_224 ) ;
} else {
V_56 = 0 ;
printf ( L_225 , V_58 ) ;
}
V_56 = 0 ;
}
}
static void F_163 ( void )
{
struct V_317 * V_317 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_319 ; V_58 ++ ) {
if ( ! V_320 [ V_58 ] . V_317 )
continue;
if ( ! V_320 [ V_58 ] . V_321 ) {
printf ( L_226
L_227 , V_58 ) ;
continue;
}
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_317 = V_320 [ V_58 ] . V_317 ;
F_162 ( V_317 , V_320 [ V_58 ] . V_327 ) ;
F_164 ( & V_317 -> V_325 -> V_326 ,
V_320 [ V_58 ] . V_324 ) ;
F_1 () ;
F_117 ( 200 ) ;
printf ( L_228 , V_58 ) ;
} else {
V_56 = 0 ;
printf ( L_229 , V_58 ) ;
}
V_56 = 0 ;
}
}
static void F_165 ( struct V_317 * V_317 )
{
printf ( L_230 , V_317 ) ;
F_166 ( V_317 , L_231 , V_318 ) ;
F_166 ( V_317 , L_135 , V_102 ) ;
F_166 ( V_317 , L_232 , V_329 ) ;
F_166 ( V_317 , L_233 , V_323 ) ;
F_166 ( V_317 , L_232 , V_330 ) ;
F_166 ( V_317 , L_231 , V_331 ) ;
F_166 ( V_317 , L_232 , V_26 ) ;
F_166 ( V_317 , L_234 , V_332 ) ;
F_166 ( V_317 , L_232 , V_333 ) ;
F_166 ( V_317 , L_232 , V_334 ) ;
F_166 ( V_317 , L_232 , V_335 ) ;
F_166 ( V_317 , L_232 , V_336 [ 0 ] ) ;
F_166 ( V_317 , L_232 , V_336 [ 1 ] ) ;
F_166 ( V_317 , L_232 , V_336 [ 2 ] ) ;
F_166 ( V_317 , L_231 , V_337 ) ;
F_166 ( V_317 , L_234 , V_128 ) ;
F_166 ( V_317 , L_233 , V_338 ) ;
F_166 ( V_317 , L_233 , V_339 ) ;
F_166 ( V_317 , L_233 , V_340 ) ;
F_166 ( V_317 , L_233 , V_341 ) ;
F_166 ( V_317 , L_232 , V_342 ) ;
F_166 ( V_317 , L_233 , V_325 ) ;
F_167 ( L_231 , V_325 -> V_326 ,
F_160 ( & V_317 -> V_325 -> V_326 ) ) ;
F_167 ( L_231 , V_325 -> V_343 ,
F_160 ( & V_317 -> V_325 -> V_343 ) ) ;
F_167 ( L_231 , V_325 -> V_344 ,
F_160 ( & V_317 -> V_325 -> V_344 ) ) ;
F_166 ( V_317 , L_233 , V_345 ) ;
F_166 ( V_317 , L_233 , V_346 ) ;
}
int
F_168 ( unsigned long V_187 , long V_85 , int V_188 )
{
return F_130 ( V_187 , V_85 , V_188 , V_347 ) ;
}
static void F_169 ( unsigned long V_348 , int V_349 )
{
unsigned long V_25 , V_91 , V_350 ;
if ( setjmp ( V_103 ) == 0 ) {
V_56 = 1 ;
F_1 () ;
V_350 = ( unsigned long ) V_320 [ V_348 ] . V_317 -> V_323 ;
F_1 () ;
F_117 ( 200 ) ;
} else {
V_56 = 0 ;
printf ( L_235 , V_348 ) ;
return;
}
V_56 = 0 ;
if ( F_102 ( & V_25 ) )
V_91 = V_350 + V_25 ;
else
V_91 = V_320 [ V_348 ] . V_322 ;
if ( V_91 >= V_350 + V_351 ) {
printf ( L_236 ) ;
return;
}
switch ( V_349 ) {
case 'i' :
V_91 += F_168 ( V_91 , 16 , 1 ) ;
V_70 = L_237 ;
break;
default:
F_129 ( V_91 , 64 ) ;
V_91 += 64 ;
V_70 = L_238 ;
break;
}
V_320 [ V_348 ] . V_322 = V_91 ;
}
static int F_87 ( void )
{
static unsigned long V_348 = 0 ;
int V_20 , V_349 = 0 ;
V_20 = F_75 () ;
switch ( V_20 ) {
case 's' :
F_159 () ;
break;
case 'r' :
F_163 () ;
break;
case 'd' :
V_349 = F_75 () ;
if ( isxdigit ( V_349 ) || V_349 == '\n' )
V_75 = V_349 ;
case 'f' :
F_102 ( & V_348 ) ;
if ( V_348 >= V_319 || ! V_320 [ V_348 ] . V_317 ) {
printf ( L_239 ) ;
return 0 ;
}
switch ( V_20 ) {
case 'f' :
F_165 ( V_320 [ V_348 ] . V_317 ) ;
break;
default:
F_169 ( V_348 , V_349 ) ;
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
