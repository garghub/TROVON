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
int V_11 ;
V_11 = F_12 ( L_1 ) ;
if ( V_11 == V_12 )
return;
F_13 ( & args , V_11 , 3 , 1 , NULL , V_13 , 0 , 0 ) ;
#endif
}
static void F_14 ( void )
{
int V_14 = F_15 () + 0x100 ;
int V_15 = 0 , V_16 ;
long V_17 ;
if ( V_18 == V_14 )
return;
for (; ; ) {
V_15 = F_16 ( & V_18 , 0 , V_14 ) ;
if ( V_15 == 0 )
return;
V_17 = 10000 ;
while ( V_18 == V_15 ) {
if ( -- V_17 > 0 ) {
F_17 ( 100 ) ;
continue;
}
V_16 = F_16 ( & V_18 , V_15 , V_14 ) ;
if ( V_16 == V_15 )
return;
break;
}
}
}
static void F_18 ( void )
{
V_18 = 0 ;
}
int F_19 ( void )
{
return ! F_20 ( & V_19 ) ;
}
static inline int F_21 ( struct V_20 * V_21 )
{
#if F_22 ( V_22 ) || F_22 ( V_23 )
return 0 ;
#else
return ( ( V_21 -> V_24 & V_25 ) == 0 ) ;
#endif
}
static int F_23 ( struct V_20 * V_21 , int V_26 )
{
int V_27 = 0 ;
struct V_28 * V_29 ;
long V_30 [ V_31 ] ;
unsigned long V_32 ;
unsigned long V_33 ;
#ifdef F_24
int V_34 ;
int V_35 ;
unsigned long V_17 ;
#endif
F_25 ( V_33 ) ;
F_26 () ;
V_29 = F_27 ( V_21 -> V_36 , & V_32 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = V_29 -> V_37 + V_32 ;
F_28 ( & V_29 -> V_38 ) ;
}
F_29 () ;
#ifdef F_24
V_34 = F_15 () ;
if ( F_30 ( V_34 , & V_19 ) ) {
F_14 () ;
F_31 ( V_21 ) ;
printf ( L_2
L_3 ,
V_34 , V_21 -> V_39 , F_32 ( F_33 ( V_21 ) ) ) ;
F_18 () ;
longjmp ( V_40 [ V_34 ] , 1 ) ;
}
if ( setjmp ( V_30 ) != 0 ) {
if ( ! V_41 || ! V_42 ) {
F_14 () ;
printf ( L_4
L_5 , V_34 ) ;
F_18 () ;
goto V_43;
}
V_35 = ! ( V_44 && V_34 == V_45 ) ;
goto V_46;
}
V_40 [ V_34 ] = V_30 ;
V_29 = NULL ;
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) == ( V_47 | V_49 ) )
V_29 = F_34 ( V_21 -> V_36 ) ;
if ( V_29 || F_21 ( V_21 ) )
V_26 = 0 ;
if ( ! V_26 ) {
F_14 () ;
F_31 ( V_21 ) ;
if ( V_29 ) {
printf ( L_6 ,
V_34 , F_35 ( V_29 ) ) ;
F_36 ( V_21 -> V_36 , L_7 , L_8 ) ;
}
if ( F_21 ( V_21 ) )
printf ( L_9
L_10 ) ;
F_18 () ;
}
F_37 ( V_34 , & V_19 ) ;
V_43:
V_35 = 1 ;
while ( V_35 && ! V_42 ) {
if ( V_41 == 0 ) {
if ( V_26 )
goto V_50;
V_35 = F_38 ( 0 , & V_41 ) ;
}
F_39 () ;
}
if ( ! V_35 && ! V_42 ) {
int V_51 = F_40 () ;
V_45 = V_34 ;
F_41 () ;
if ( V_51 > 1 ) {
F_42 () ;
for ( V_17 = 100000000 ; V_17 != 0 ; -- V_17 ) {
if ( F_43 ( & V_19 ) >= V_51 )
break;
F_39 () ;
}
}
F_44 () ;
F_10 () ;
if ( V_29 || F_33 ( V_21 ) == 0xd00 )
F_45 ( V_21 -> V_36 , 1 , 0 ) ;
printf ( L_11 ) ;
F_41 () ;
V_42 = 1 ;
F_39 () ;
}
V_46:
while ( V_41 ) {
if ( V_35 ) {
if ( V_34 == V_45 ) {
if ( ! F_38 ( 0 , & V_44 ) ) {
V_35 = 0 ;
continue;
}
while ( V_34 == V_45 )
F_39 () ;
}
F_39 () ;
} else {
V_27 = F_46 ( V_21 ) ;
if ( V_27 != 0 ) {
F_47 () ;
V_42 = 0 ;
F_48 () ;
V_41 = 0 ;
break;
}
V_35 = 1 ;
}
}
V_50:
F_49 ( V_34 , & V_19 ) ;
V_40 [ V_34 ] = NULL ;
#else
if ( V_41 ) {
printf ( L_12 ,
V_21 -> V_39 , F_32 ( F_33 ( V_21 ) ) ) ;
longjmp ( V_40 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_30 ) == 0 ) {
V_40 [ 0 ] = V_30 ;
V_41 = 1 ;
F_31 ( V_21 ) ;
V_29 = F_34 ( V_21 -> V_36 ) ;
if ( V_29 ) {
printf ( L_13 , F_35 ( V_29 ) ) ;
F_36 ( V_21 -> V_36 , L_7 , L_8 ) ;
}
if ( F_21 ( V_21 ) )
printf ( L_9
L_10 ) ;
F_44 () ;
F_10 () ;
if ( V_29 || F_33 ( V_21 ) == 0xd00 )
F_45 ( V_21 -> V_36 , 1 , 0 ) ;
printf ( L_11 ) ;
}
V_27 = F_46 ( V_21 ) ;
F_47 () ;
V_41 = 0 ;
#endif
#ifdef F_50
if ( V_21 -> V_24 & V_52 ) {
V_29 = F_34 ( V_21 -> V_36 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = ( unsigned long ) & V_29 -> V_53 [ 0 ] ;
F_51 ( & V_29 -> V_38 ) ;
}
}
#else
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) == ( V_47 | V_49 ) ) {
V_29 = F_34 ( V_21 -> V_36 ) ;
if ( V_29 != NULL ) {
int V_54 = F_52 ( V_21 , V_29 -> V_53 [ 0 ] ) ;
if ( V_54 == 0 ) {
V_21 -> V_36 = ( unsigned long ) & V_29 -> V_53 [ 0 ] ;
F_51 ( & V_29 -> V_38 ) ;
} else if ( V_54 < 0 ) {
printf ( L_14 ,
( F_53 ( V_29 -> V_53 [ 0 ] ) ? L_15 : L_16 ) ) ;
}
}
}
#endif
F_54 () ;
F_55 () ;
F_56 ( V_33 ) ;
return V_27 != 'X' && V_27 != V_55 ;
}
int F_57 ( struct V_20 * V_56 )
{
struct V_20 V_21 ;
if ( V_56 == NULL ) {
F_58 ( & V_21 ) ;
V_56 = & V_21 ;
}
return F_23 ( V_56 , 0 ) ;
}
T_1 F_59 ( int V_57 , void * V_58 )
{
unsigned long V_33 ;
F_25 ( V_33 ) ;
printf ( L_17 ) ;
F_57 ( F_60 () ) ;
F_56 ( V_33 ) ;
return V_59 ;
}
static int F_61 ( struct V_20 * V_21 )
{
struct V_28 * V_29 ;
unsigned long V_32 ;
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) != ( V_47 | V_49 ) )
return 0 ;
V_29 = F_27 ( V_21 -> V_36 , & V_32 ) ;
if ( V_29 != NULL && V_32 == 4 ) {
V_21 -> V_36 = V_29 -> V_37 + 4 ;
F_28 ( & V_29 -> V_38 ) ;
return 1 ;
}
V_29 = F_34 ( V_21 -> V_36 ) ;
if ( ! V_29 )
return 0 ;
F_23 ( V_21 , 0 ) ;
return 1 ;
}
static int F_62 ( struct V_20 * V_21 )
{
if ( F_63 ( V_21 ) )
return 0 ;
F_23 ( V_21 , 0 ) ;
return 1 ;
}
static int F_64 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) != ( V_47 | V_49 ) )
return 0 ;
if ( V_60 . V_61 == 0 )
return 0 ;
F_23 ( V_21 , 0 ) ;
return 1 ;
}
static int F_65 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) != ( V_47 | V_49 ) )
return 0 ;
if ( V_62 == NULL )
return 0 ;
F_23 ( V_21 , 0 ) ;
return 1 ;
}
static int F_66 ( struct V_20 * V_21 )
{
#ifdef F_24
if ( V_41 && ! F_30 ( F_15 () , & V_19 ) )
F_23 ( V_21 , 1 ) ;
#endif
return 0 ;
}
static int F_67 ( struct V_20 * V_21 )
{
struct V_28 * V_29 ;
unsigned long V_32 ;
if ( V_41 && V_63 )
F_68 ( V_21 ) ;
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) == ( V_47 | V_49 ) ) {
V_29 = F_27 ( V_21 -> V_36 , & V_32 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = V_29 -> V_37 + V_32 ;
F_28 ( & V_29 -> V_38 ) ;
}
}
return 0 ;
}
static struct V_28 * F_34 ( unsigned long V_64 )
{
int V_65 ;
struct V_28 * V_29 ;
V_29 = V_66 ;
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 , ++ V_29 )
if ( V_29 -> V_61 && V_64 == V_29 -> V_37 )
return V_29 ;
return NULL ;
}
static struct V_28 * F_27 ( unsigned long V_36 , unsigned long * V_68 )
{
unsigned long V_69 ;
V_69 = V_36 - ( unsigned long ) V_66 ;
if ( V_69 >= sizeof( V_66 ) )
return NULL ;
V_69 %= sizeof( struct V_28 ) ;
if ( V_69 != F_69 ( struct V_28 , V_53 [ 0 ] )
&& V_69 != F_69 ( struct V_28 , V_53 [ 1 ] ) )
return NULL ;
* V_68 = V_69 - F_69 ( struct V_28 , V_53 [ 0 ] ) ;
return (struct V_28 * ) ( V_36 - V_69 ) ;
}
static struct V_28 * F_70 ( unsigned long V_70 )
{
struct V_28 * V_29 ;
V_70 &= ~ 3UL ;
V_29 = F_34 ( V_70 ) ;
if ( V_29 )
return V_29 ;
for ( V_29 = V_66 ; V_29 < & V_66 [ V_67 ] ; ++ V_29 ) {
if ( ! V_29 -> V_61 && F_71 ( & V_29 -> V_38 ) == 0 ) {
V_29 -> V_37 = V_70 ;
V_29 -> V_53 [ 1 ] = V_71 ;
F_3 ( & V_29 -> V_53 [ 1 ] ) ;
return V_29 ;
}
}
printf ( L_18 ) ;
return NULL ;
}
static void F_47 ( void )
{
int V_65 ;
struct V_28 * V_29 ;
V_29 = V_66 ;
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 , ++ V_29 ) {
if ( ( V_29 -> V_61 & ( V_72 | V_73 ) ) == 0 )
continue;
if ( F_72 ( V_29 -> V_37 , & V_29 -> V_53 [ 0 ] , 4 ) != 4 ) {
printf ( L_19
L_20 , V_29 -> V_37 ) ;
V_29 -> V_61 = 0 ;
continue;
}
if ( F_73 ( V_29 -> V_53 [ 0 ] ) || F_53 ( V_29 -> V_53 [ 0 ] ) ) {
printf ( L_21
L_22 , V_29 -> V_37 ) ;
V_29 -> V_61 = 0 ;
continue;
}
F_3 ( & V_29 -> V_53 [ 0 ] ) ;
if ( V_29 -> V_61 & V_73 )
continue;
if ( F_74 ( V_29 -> V_37 , & V_71 , 4 ) != 4 ) {
printf ( L_23
L_20 , V_29 -> V_37 ) ;
V_29 -> V_61 &= ~ V_72 ;
continue;
}
F_3 ( ( void * ) V_29 -> V_37 ) ;
}
}
static void F_54 ( void )
{
struct V_74 V_75 ;
if ( V_60 . V_61 ) {
V_75 . V_37 = V_60 . V_37 ;
V_75 . type = ( V_60 . V_61 & V_76 ) | V_77 ;
V_75 . V_78 = 8 ;
F_75 ( & V_75 ) ;
}
if ( V_62 )
F_9 ( V_62 -> V_37 ) ;
}
static void F_44 ( void )
{
int V_65 ;
struct V_28 * V_29 ;
unsigned V_53 ;
V_29 = V_66 ;
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 , ++ V_29 ) {
if ( ( V_29 -> V_61 & ( V_72 | V_73 ) ) != V_72 )
continue;
if ( F_72 ( V_29 -> V_37 , & V_53 , 4 ) == 4
&& V_53 == V_71
&& F_74 ( V_29 -> V_37 , & V_29 -> V_53 , 4 ) != 4 )
printf ( L_24 ,
V_29 -> V_37 ) ;
else
F_3 ( ( void * ) V_29 -> V_37 ) ;
}
}
static void F_29 ( void )
{
F_76 () ;
F_6 ( 0 ) ;
}
static void F_77 ( void )
{
unsigned long V_79 ;
if ( ! F_78 ( & V_79 ) ) {
printf ( L_25 ) ;
V_79 = 0 ;
}
F_79 ( V_79 ) ;
}
static int
F_46 ( struct V_20 * V_56 )
{
int V_27 = 0 ;
V_80 = NULL ;
V_81 = V_56 ;
if ( ! V_82 ) {
V_82 = 1 ;
F_80 ( V_56 -> V_83 [ 1 ] , V_56 -> V_84 , V_56 -> V_36 ) ;
}
for(; ; ) {
#ifdef F_24
printf ( L_26 , F_15 () ) ;
#endif
printf ( L_27 ) ;
F_81 () ;
V_85 = 0 ;
V_27 = F_82 () ;
if( V_27 == '\n' ) {
if ( V_80 == NULL )
continue;
F_83 ( V_80 ) ;
V_80 = NULL ;
V_27 = F_84 () ;
}
switch ( V_27 ) {
case 'm' :
V_27 = F_84 () ;
switch ( V_27 ) {
case 'm' :
case 's' :
case 'd' :
F_85 ( V_27 ) ;
break;
case 'l' :
F_86 () ;
break;
case 'z' :
F_87 () ;
break;
case 'i' :
F_88 ( 0 ) ;
break;
default:
V_85 = V_27 ;
F_89 () ;
}
break;
case 'd' :
F_90 () ;
break;
case 'l' :
F_91 () ;
break;
case 'r' :
F_92 ( V_56 ) ;
break;
case 'e' :
F_31 ( V_56 ) ;
break;
case 'S' :
F_93 () ;
break;
case 't' :
F_94 ( V_56 ) ;
break;
case 'f' :
F_95 () ;
break;
case 's' :
if ( F_96 () == 0 )
break;
if ( F_97 ( V_56 ) )
return V_27 ;
break;
case 'x' :
case 'X' :
return V_27 ;
case V_55 :
printf ( L_28 ) ;
F_98 ( 2000 ) ;
return V_27 ;
case '?' :
F_99 ( V_86 ) ;
break;
case '#' :
F_77 () ;
break;
case 'b' :
F_100 () ;
break;
case 'C' :
F_101 () ;
break;
case 'c' :
if ( F_102 () )
return 0 ;
break;
case 'z' :
F_103 () ;
break;
case 'p' :
F_104 () ;
break;
#ifdef F_105
case 'u' :
F_106 () ;
break;
#elif F_22 ( V_87 )
case 'u' :
F_107 () ;
break;
#elif F_22 ( V_23 )
case 'u' :
F_108 () ;
break;
#endif
default:
printf ( L_29 ) ;
do {
if ( ' ' < V_27 && V_27 <= '~' )
putchar ( V_27 ) ;
else
printf ( L_30 , V_27 ) ;
V_27 = F_84 () ;
} while ( V_27 != '\n' );
printf ( L_31 ) ;
break;
}
}
}
static int F_97 ( struct V_20 * V_21 )
{
V_21 -> V_24 |= V_52 ;
F_8 ( V_88 , F_109 ( V_88 ) | V_89 | V_90 ) ;
return 1 ;
}
static int F_97 ( struct V_20 * V_21 )
{
unsigned int V_53 ;
int V_54 ;
if ( ( V_21 -> V_24 & ( V_49 | V_48 | V_47 ) ) == ( V_49 | V_47 ) ) {
if ( F_72 ( V_21 -> V_36 , & V_53 , 4 ) == 4 ) {
V_54 = F_52 ( V_21 , V_53 ) ;
if ( V_54 < 0 ) {
printf ( L_14 ,
( F_53 ( V_53 ) ? L_15 : L_16 ) ) ;
return 0 ;
}
if ( V_54 > 0 ) {
V_21 -> V_39 = 0xd00 | ( V_21 -> V_39 & 1 ) ;
printf ( L_32 ) ;
F_36 ( V_21 -> V_36 , L_7 , L_33 ) ;
F_45 ( V_21 -> V_36 , 1 , 0 ) ;
return 0 ;
}
}
}
V_21 -> V_24 |= V_91 ;
return 1 ;
}
static void F_103 ( void )
{
int V_27 ;
V_27 = F_84 () ;
if ( V_27 == 'r' )
V_92 . V_93 ( NULL ) ;
else if ( V_27 == 'h' )
V_92 . V_94 () ;
else if ( V_27 == 'p' )
if ( V_95 )
V_95 () ;
}
static int F_102 ( void )
{
#ifdef F_24
unsigned long V_34 , V_96 , V_97 ;
int V_17 ;
if ( ! F_78 ( & V_34 ) ) {
printf ( L_34 ) ;
V_97 = V_96 = V_98 ;
F_110 (cpu) {
if ( F_30 ( V_34 , & V_19 ) ) {
if ( V_34 == V_97 + 1 ) {
V_97 = V_34 ;
} else {
if ( V_97 != V_96 )
printf ( L_35 , V_97 ) ;
V_97 = V_96 = V_34 ;
printf ( L_36 , V_34 ) ;
}
}
}
if ( V_97 != V_96 )
printf ( L_35 , V_97 ) ;
printf ( L_33 ) ;
return 0 ;
}
if ( ! F_30 ( V_34 , & V_19 ) ) {
printf ( L_37 , V_34 ) ;
return 0 ;
}
V_44 = 0 ;
F_41 () ;
V_45 = V_34 ;
V_17 = 10000000 ;
while ( ! V_44 ) {
if ( -- V_17 == 0 ) {
if ( F_38 ( 0 , & V_44 ) )
break;
F_41 () ;
V_45 = F_15 () ;
printf ( L_38 , V_34 ) ;
return 0 ;
}
F_39 () ;
}
return 1 ;
#else
return 0 ;
#endif
}
static void
F_101 ( void )
{
unsigned int V_65 ;
unsigned short V_99 ;
unsigned char V_100 ;
if ( ! F_78 ( & V_101 ) )
return;
if ( ! F_78 ( & V_102 ) )
return;
V_99 = 0xffff ;
for ( V_65 = 0 ; V_65 < V_102 ; ++ V_65 ) {
if ( F_72 ( V_101 + V_65 , & V_100 , 1 ) == 0 ) {
printf ( L_39 V_103 L_33 , V_101 + V_65 ) ;
break;
}
V_99 = F_111 ( V_99 , V_100 ) ;
}
printf ( L_40 , V_99 ) ;
}
static long F_112 ( unsigned long V_6 )
{
unsigned int V_53 ;
V_6 &= ~ 3 ;
if ( ! F_113 ( V_6 ) ) {
printf ( L_41 ) ;
return 0 ;
}
if ( ! F_72 ( V_6 , & V_53 , sizeof( V_53 ) ) ) {
printf ( L_42 , V_6 ) ;
return 0 ;
}
if ( F_73 ( V_53 ) || F_53 ( V_53 ) ) {
printf ( L_43
L_44 ) ;
return 0 ;
}
return 1 ;
}
static void
F_100 ( void )
{
int V_27 ;
unsigned long V_70 ;
int V_104 , V_65 ;
struct V_28 * V_29 ;
const char V_105 [] = L_45
L_46 ;
V_27 = F_84 () ;
switch ( V_27 ) {
#ifndef F_114
case 'd' :
V_104 = 7 ;
V_27 = F_84 () ;
if ( V_27 == 'r' )
V_104 = 5 ;
else if ( V_27 == 'w' )
V_104 = 6 ;
else
V_85 = V_27 ;
V_60 . V_37 = 0 ;
V_60 . V_61 = 0 ;
if ( F_78 ( & V_60 . V_37 ) ) {
if ( ! F_113 ( V_60 . V_37 ) ) {
printf ( V_105 ) ;
break;
}
V_60 . V_37 &= ~ V_76 ;
V_60 . V_61 = V_104 | V_106 ;
}
break;
case 'i' :
if ( ! F_7 ( V_3 ) ) {
printf ( L_47
L_48 ) ;
break;
}
if ( V_62 ) {
V_62 -> V_61 &= ~ V_73 ;
V_62 = NULL ;
}
if ( ! F_78 ( & V_70 ) )
break;
if ( ! F_112 ( V_70 ) )
break;
V_29 = F_70 ( V_70 ) ;
if ( V_29 != NULL ) {
V_29 -> V_61 |= V_73 ;
V_62 = V_29 ;
}
break;
#endif
case 'c' :
if ( ! F_78 ( & V_70 ) ) {
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 )
V_66 [ V_65 ] . V_61 = 0 ;
V_62 = NULL ;
V_60 . V_61 = 0 ;
printf ( L_49 ) ;
break;
}
if ( V_70 <= V_67 && V_70 >= 1 ) {
V_29 = & V_66 [ V_70 - 1 ] ;
} else {
V_29 = F_34 ( V_70 ) ;
if ( V_29 == NULL ) {
printf ( L_50 , V_70 ) ;
break;
}
}
printf ( L_51 , F_35 ( V_29 ) ) ;
F_36 ( V_29 -> V_37 , L_7 , L_8 ) ;
V_29 -> V_61 = 0 ;
break;
default:
V_85 = V_27 ;
V_27 = F_82 () ;
if ( V_27 == '?' ) {
printf ( V_107 ) ;
break;
}
V_85 = V_27 ;
if ( ! F_78 ( & V_70 ) ) {
printf ( L_52 ) ;
if ( V_60 . V_61 ) {
printf ( L_53 V_103 L_54 , V_60 . V_37 ) ;
if ( V_60 . V_61 & 1 )
printf ( L_55 ) ;
if ( V_60 . V_61 & 2 )
printf ( L_56 ) ;
printf ( L_57 ) ;
}
for ( V_29 = V_66 ; V_29 < & V_66 [ V_67 ] ; ++ V_29 ) {
if ( ! V_29 -> V_61 )
continue;
printf ( L_58 , F_35 ( V_29 ) ,
( V_29 -> V_61 & V_73 ) ? L_59 : L_60 ) ;
F_36 ( V_29 -> V_37 , L_61 , L_33 ) ;
}
break;
}
if ( ! F_112 ( V_70 ) )
break;
V_29 = F_70 ( V_70 ) ;
if ( V_29 != NULL )
V_29 -> V_61 |= V_72 ;
break;
}
}
static
const char * F_32 ( unsigned long V_108 )
{
char * V_109 ;
switch ( V_108 ) {
case 0x100 : V_109 = L_62 ; break;
case 0x200 : V_109 = L_63 ; break;
case 0x300 : V_109 = L_64 ; break;
case 0x380 : V_109 = L_65 ; break;
case 0x400 : V_109 = L_66 ; break;
case 0x480 : V_109 = L_67 ; break;
case 0x500 : V_109 = L_68 ; break;
case 0x600 : V_109 = L_69 ; break;
case 0x700 : V_109 = L_70 ; break;
case 0x800 : V_109 = L_71 ; break;
case 0x900 : V_109 = L_72 ; break;
case 0x980 : V_109 = L_73 ; break;
case 0xa00 : V_109 = L_74 ; break;
case 0xc00 : V_109 = L_75 ; break;
case 0xd00 : V_109 = L_76 ; break;
case 0xe40 : V_109 = L_77 ; break;
case 0xe60 : V_109 = L_78 ; break;
case 0xe80 : V_109 = L_79 ; break;
case 0xf00 : V_109 = L_80 ; break;
case 0xf20 : V_109 = L_81 ; break;
case 0x1300 : V_109 = L_82 ; break;
case 0x1500 : V_109 = L_83 ; break;
case 0x1700 : V_109 = L_84 ; break;
default: V_109 = L_85 ;
}
return V_109 ;
}
static void F_115 ( unsigned long V_64 , unsigned long * V_110 ,
unsigned long * V_111 )
{
unsigned long V_112 , V_32 ;
const char * V_113 ;
* V_110 = * V_111 = 0 ;
if ( V_64 == 0 )
return;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_113 = F_116 ( V_64 , & V_112 , & V_32 , NULL , V_115 ) ;
if ( V_113 != NULL ) {
* V_110 = V_64 - V_32 ;
* V_111 = V_64 - V_32 + V_112 ;
}
F_2 () ;
}
V_63 = 0 ;
}
static void F_80 ( unsigned long V_116 , unsigned long V_117 ,
unsigned long V_64 )
{
int V_118 = 64 ;
unsigned long V_119 ;
unsigned long V_120 ;
unsigned long V_121 ;
struct V_20 V_21 ;
while ( V_118 -- ) {
if ( V_116 < V_122 ) {
if ( V_116 != 0 )
printf ( L_86 , V_116 ) ;
break;
}
if ( ! F_72 ( V_116 + V_123 , & V_119 , sizeof( unsigned long ) )
|| ! F_72 ( V_116 , & V_120 , sizeof( unsigned long ) ) ) {
printf ( L_87 , V_116 ) ;
break;
}
if ( ( V_64 | V_117 ) != 0 ) {
unsigned long V_124 , V_125 ;
unsigned long V_126 ;
int V_127 = 1 ;
F_115 ( V_64 , & V_124 , & V_125 ) ;
V_126 = 0 ;
if ( V_120 > V_116 )
F_72 ( V_120 + V_123 , & V_126 ,
sizeof( unsigned long ) ) ;
if ( V_117 == V_119 ) {
if ( V_117 < V_122
|| ( V_124 <= V_117 && V_117 < V_125 ) )
V_127 = 0 ;
} else if ( V_117 == V_126 ) {
V_127 = 0 ;
} else if ( V_117 >= V_122
&& ! ( V_124 <= V_117 && V_117 < V_125 ) ) {
printf ( L_88 ) ;
F_36 ( V_117 , L_7 , L_33 ) ;
}
if ( V_127 ) {
printf ( L_89 V_103 L_90 , V_116 ) ;
F_36 ( V_119 , L_7 , L_91 ) ;
}
V_64 = V_117 = 0 ;
} else {
printf ( L_89 V_103 L_90 , V_116 ) ;
F_36 ( V_119 , L_7 , L_33 ) ;
}
if ( F_72 ( V_116 + V_128 , & V_121 , sizeof( unsigned long ) )
&& V_121 == V_129 ) {
if ( F_72 ( V_116 + V_130 , & V_21 , sizeof( V_21 ) )
!= sizeof( V_21 ) ) {
printf ( L_92 ,
V_116 + V_130 ) ;
break;
}
printf ( L_93 , V_21 . V_39 ,
F_32 ( F_33 ( & V_21 ) ) ) ;
V_64 = V_21 . V_36 ;
V_117 = V_21 . V_84 ;
F_36 ( V_64 , L_7 , L_33 ) ;
}
if ( V_120 == 0 )
break;
V_116 = V_120 ;
}
}
static void F_94 ( struct V_20 * V_56 )
{
unsigned long V_116 ;
if ( F_78 ( & V_116 ) )
F_80 ( V_116 , 0 , 0 ) ;
else
F_80 ( V_56 -> V_83 [ 1 ] , V_56 -> V_84 , V_56 -> V_36 ) ;
F_117 () ;
}
static void F_118 ( struct V_20 * V_21 )
{
#ifdef F_119
const struct V_131 * V_132 ;
unsigned long V_6 ;
if ( V_21 -> V_24 & V_48 )
return;
V_6 = V_21 -> V_36 ;
if ( V_6 < V_122 )
return;
V_132 = F_120 ( V_21 -> V_36 ) ;
if ( V_132 == NULL )
return;
if ( F_121 ( V_132 ) )
return;
#ifdef F_122
printf ( L_94 ,
V_132 -> V_133 , V_132 -> line ) ;
#else
printf ( L_95 , ( void * ) V_132 -> V_134 ) ;
#endif
#endif
}
static void F_31 ( struct V_20 * V_135 )
{
unsigned long V_39 ;
#ifdef F_24
printf ( L_96 , F_15 () ) ;
#endif
V_39 = F_33 ( V_135 ) ;
printf ( L_97 , V_135 -> V_39 , F_32 ( V_39 ) , V_135 ) ;
printf ( L_98 ) ;
F_36 ( V_135 -> V_36 , L_99 , L_33 ) ;
printf ( L_100 , V_135 -> V_84 ) ;
F_36 ( V_135 -> V_84 , L_99 , L_33 ) ;
printf ( L_101 , V_135 -> V_83 [ 1 ] ) ;
printf ( L_102 , V_135 -> V_24 ) ;
if ( V_39 == 0x300 || V_39 == 0x380 || V_39 == 0x600 || V_39 == 0x200 ) {
printf ( L_103 , V_135 -> V_136 ) ;
if ( V_39 != 0x380 )
printf ( L_104 , V_135 -> V_137 ) ;
}
printf ( L_105 , V_138 ) ;
#ifdef F_123
printf ( L_106 ,
V_139 , V_139 -> V_140 , V_139 -> V_141 ) ;
#endif
if ( V_138 ) {
printf ( L_107 ,
V_138 -> V_142 , V_138 -> V_143 ) ;
}
if ( V_39 == 0x700 )
F_118 ( V_135 ) ;
printf ( V_144 ) ;
}
static void F_92 ( struct V_20 * V_135 )
{
int V_145 , V_39 ;
unsigned long V_146 ;
struct V_20 V_21 ;
if ( F_78 ( & V_146 ) ) {
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_21 = * (struct V_20 * ) V_146 ;
F_2 () ;
F_124 ( 200 ) ;
} else {
V_63 = 0 ;
printf ( L_108 V_103 L_33 ,
V_146 ) ;
return;
}
V_63 = 0 ;
V_135 = & V_21 ;
}
#ifdef F_123
if ( F_125 ( V_135 ) ) {
for ( V_145 = 0 ; V_145 < 16 ; ++ V_145 )
printf ( L_109 V_103 L_110 V_103 L_33 ,
V_145 , V_135 -> V_83 [ V_145 ] , V_145 + 16 , V_135 -> V_83 [ V_145 + 16 ] ) ;
} else {
for ( V_145 = 0 ; V_145 < 7 ; ++ V_145 )
printf ( L_109 V_103 L_110 V_103 L_33 ,
V_145 , V_135 -> V_83 [ V_145 ] , V_145 + 7 , V_135 -> V_83 [ V_145 + 7 ] ) ;
}
#else
for ( V_145 = 0 ; V_145 < 32 ; ++ V_145 ) {
printf ( L_111 , V_145 , V_135 -> V_83 [ V_145 ] ,
( V_145 & 3 ) == 3 ? L_33 : L_112 ) ;
if ( V_145 == 12 && ! F_125 ( V_135 ) ) {
printf ( L_33 ) ;
break;
}
}
#endif
printf ( L_113 ) ;
F_36 ( V_135 -> V_36 , L_7 , L_33 ) ;
if ( F_33 ( V_135 ) != 0xc00 && F_7 ( V_147 ) ) {
printf ( L_114 ) ;
F_36 ( V_135 -> V_148 , L_7 , L_33 ) ;
}
printf ( L_115 ) ;
F_36 ( V_135 -> V_84 , L_7 , L_33 ) ;
printf ( L_116 V_103 L_117 , V_135 -> V_24 , V_135 -> V_149 ) ;
printf ( L_118 V_103 L_119 V_103 L_120 ,
V_135 -> V_150 , V_135 -> V_151 , V_135 -> V_39 ) ;
V_39 = F_33 ( V_135 ) ;
if ( V_39 == 0x300 || V_39 == 0x380 || V_39 == 0x600 )
printf ( L_121 V_103 L_122 , V_135 -> V_136 , V_135 -> V_137 ) ;
}
static void F_95 ( void )
{
int V_27 ;
unsigned long V_152 ;
V_27 = F_84 () ;
if ( V_27 != 'i' )
V_85 = V_27 ;
F_78 ( ( void * ) & V_101 ) ;
if ( V_85 != '\n' )
V_85 = 0 ;
V_152 = 1 ;
F_78 ( & V_152 ) ;
V_152 = ( V_152 + V_153 - 1 ) / V_153 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
if ( V_27 != 'i' ) {
for (; V_152 > 0 ; -- V_152 , V_101 += V_153 )
F_4 ( ( void * ) V_101 ) ;
} else {
for (; V_152 > 0 ; -- V_152 , V_101 += V_153 )
F_5 ( ( void * ) V_101 ) ;
}
F_2 () ;
F_124 ( 200 ) ;
}
V_63 = 0 ;
}
static unsigned long
F_126 ( int V_145 )
{
unsigned int V_154 [ 2 ] ;
unsigned long ( * V_155 ) ( void ) ;
unsigned long V_109 = - 1UL ;
#ifdef F_123
unsigned long V_156 [ 3 ] ;
V_156 [ 0 ] = ( unsigned long ) V_154 ;
V_156 [ 1 ] = 0 ;
V_156 [ 2 ] = 0 ;
V_155 = ( unsigned long ( * ) ( void ) ) V_156 ;
#else
V_155 = ( unsigned long ( * ) ( void ) ) V_154 ;
#endif
V_154 [ 0 ] = 0x7c6002a6 + ( ( V_145 & 0x1F ) << 16 ) + ( ( V_145 & 0x3e0 ) << 6 ) ;
V_154 [ 1 ] = 0x4e800020 ;
F_3 ( V_154 ) ;
F_3 ( V_154 + 1 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_109 = V_155 () ;
F_2 () ;
F_124 ( 200 ) ;
V_145 = V_112 ;
}
return V_109 ;
}
static void
F_127 ( int V_145 , unsigned long V_157 )
{
unsigned int V_154 [ 2 ] ;
unsigned long ( * V_155 ) ( unsigned long ) ;
#ifdef F_123
unsigned long V_156 [ 3 ] ;
V_156 [ 0 ] = ( unsigned long ) V_154 ;
V_156 [ 1 ] = 0 ;
V_156 [ 2 ] = 0 ;
V_155 = ( unsigned long (*) ( unsigned long ) ) V_156 ;
#else
V_155 = ( unsigned long (*) ( unsigned long ) ) V_154 ;
#endif
V_154 [ 0 ] = 0x7c6003a6 + ( ( V_145 & 0x1F ) << 16 ) + ( ( V_145 & 0x3e0 ) << 6 ) ;
V_154 [ 1 ] = 0x4e800020 ;
F_3 ( V_154 ) ;
F_3 ( V_154 + 1 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_155 ( V_157 ) ;
F_2 () ;
F_124 ( 200 ) ;
V_145 = V_112 ;
}
}
static void F_93 ( void )
{
int V_27 ;
unsigned long V_157 ;
V_27 = F_82 () ;
if ( V_27 == '\n' ) {
unsigned long V_116 , V_158 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_123 V_103 L_124 V_103 L_33 ,
F_128 () , F_109 ( V_159 ) ) ;
printf ( L_125 V_103 L_126 V_103 L_33 ,
F_109 ( V_160 ) , F_109 ( V_161 ) ) ;
printf ( L_127 V_103 L_128 V_103 L_33 ,
F_109 ( V_162 ) , F_109 ( V_163 ) ) ;
printf ( L_129 V_103 L_130 V_103 L_33 , V_116 , F_109 ( V_164 ) ) ;
printf ( L_131 V_103 L_132 V_103 L_33 , V_158 , F_109 ( V_165 ) ) ;
return;
}
F_78 ( & V_166 ) ;
switch ( V_27 ) {
case 'w' :
V_157 = F_126 ( V_166 ) ;
F_78 ( & V_157 ) ;
F_127 ( V_166 , V_157 ) ;
case 'r' :
printf ( L_133 , V_166 , F_126 ( V_166 ) ) ;
break;
}
F_117 () ;
}
static int
F_72 ( unsigned long V_101 , void * V_167 , int V_112 )
{
volatile int V_145 ;
char * V_2 , * V_168 ;
V_145 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_2 = ( char * ) V_101 ;
V_168 = ( char * ) V_167 ;
switch ( V_112 ) {
case 2 :
* ( V_169 * ) V_168 = * ( V_169 * ) V_2 ;
break;
case 4 :
* ( V_170 * ) V_168 = * ( V_170 * ) V_2 ;
break;
case 8 :
* ( V_171 * ) V_168 = * ( V_171 * ) V_2 ;
break;
default:
for( ; V_145 < V_112 ; ++ V_145 ) {
* V_168 ++ = * V_2 ++ ;
F_2 () ;
}
}
F_2 () ;
F_124 ( 200 ) ;
V_145 = V_112 ;
}
V_63 = 0 ;
return V_145 ;
}
static int
F_74 ( unsigned long V_101 , void * V_167 , int V_112 )
{
volatile int V_145 ;
char * V_2 , * V_168 ;
V_145 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_2 = ( char * ) V_101 ;
V_168 = ( char * ) V_167 ;
switch ( V_112 ) {
case 2 :
* ( V_169 * ) V_2 = * ( V_169 * ) V_168 ;
break;
case 4 :
* ( V_170 * ) V_2 = * ( V_170 * ) V_168 ;
break;
case 8 :
* ( V_171 * ) V_2 = * ( V_171 * ) V_168 ;
break;
default:
for ( ; V_145 < V_112 ; ++ V_145 ) {
* V_2 ++ = * V_168 ++ ;
F_2 () ;
}
}
F_2 () ;
F_124 ( 200 ) ;
V_145 = V_112 ;
} else {
printf ( L_134 V_103 L_33 , V_101 + V_145 ) ;
}
V_63 = 0 ;
return V_145 ;
}
static int F_68 ( struct V_20 * V_21 )
{
V_172 = F_33 ( V_21 ) ;
switch ( F_33 ( V_21 ) ) {
case 0x200 :
V_173 = 0 ;
break;
case 0x300 :
case 0x380 :
V_173 = 1 ;
break;
default:
V_173 = 2 ;
}
longjmp ( V_114 , 1 ) ;
return 0 ;
}
static void
F_129 ( unsigned char * V_157 , int V_112 )
{
int V_174 ;
switch ( V_112 ) {
case 2 :
F_130 ( V_157 [ 0 ] , V_157 [ 1 ] , V_174 ) ;
break;
case 4 :
F_130 ( V_157 [ 0 ] , V_157 [ 3 ] , V_174 ) ;
F_130 ( V_157 [ 1 ] , V_157 [ 2 ] , V_174 ) ;
break;
case 8 :
F_130 ( V_157 [ 0 ] , V_157 [ 7 ] , V_174 ) ;
F_130 ( V_157 [ 1 ] , V_157 [ 6 ] , V_174 ) ;
F_130 ( V_157 [ 2 ] , V_157 [ 5 ] , V_174 ) ;
F_130 ( V_157 [ 3 ] , V_157 [ 4 ] , V_174 ) ;
break;
}
}
static void
F_89 ( void )
{
int V_27 , V_175 , V_65 , V_176 ;
unsigned long V_145 ;
unsigned char V_157 [ 16 ] ;
F_78 ( ( void * ) & V_101 ) ;
V_27 = F_82 () ;
if ( V_27 == '?' ) {
printf ( V_177 ) ;
return;
} else {
V_85 = V_27 ;
}
V_80 = L_135 ;
while ( ( V_27 = F_82 () ) != '\n' ) {
switch( V_27 ) {
case 'b' : V_112 = 1 ; break;
case 'w' : V_112 = 2 ; break;
case 'l' : V_112 = 4 ; break;
case 'd' : V_112 = 8 ; break;
case 'r' : V_178 = ! V_178 ; break;
case 'n' : V_179 = 1 ; break;
case '.' : V_179 = 0 ; break;
}
}
if( V_112 <= 0 )
V_112 = 1 ;
else if( V_112 > 8 )
V_112 = 8 ;
for(; ; ) {
if ( ! V_179 )
V_145 = F_72 ( V_101 , V_157 , V_112 ) ;
printf ( V_103 L_136 , V_101 , V_178 ? 'r' : ' ' ) ;
if ( ! V_179 ) {
if ( V_178 )
F_129 ( V_157 , V_112 ) ;
putchar ( ' ' ) ;
for ( V_65 = 0 ; V_65 < V_145 ; ++ V_65 )
printf ( L_137 , V_157 [ V_65 ] ) ;
for (; V_65 < V_112 ; ++ V_65 )
printf ( L_138 , V_180 [ V_173 ] ) ;
}
putchar ( ' ' ) ;
V_175 = V_112 ;
V_176 = 0 ;
for(; ; ) {
if( F_78 ( & V_145 ) ) {
for ( V_65 = 0 ; V_65 < V_112 ; ++ V_65 )
V_157 [ V_65 ] = V_145 >> ( V_65 * 8 ) ;
if ( ! V_178 )
F_129 ( V_157 , V_112 ) ;
F_74 ( V_101 , V_157 , V_112 ) ;
V_175 = V_112 ;
}
V_27 = F_82 () ;
if ( V_27 == '\n' )
break;
V_175 = 0 ;
switch ( V_27 ) {
case '\'' :
for(; ; ) {
V_145 = F_84 () ;
if( V_145 == '\\' )
V_145 = F_131 () ;
else if( V_145 == '\'' )
break;
for ( V_65 = 0 ; V_65 < V_112 ; ++ V_65 )
V_157 [ V_65 ] = V_145 >> ( V_65 * 8 ) ;
if ( ! V_178 )
F_129 ( V_157 , V_112 ) ;
F_74 ( V_101 , V_157 , V_112 ) ;
V_101 += V_112 ;
}
V_101 -= V_112 ;
V_175 = V_112 ;
break;
case ',' :
V_101 += V_112 ;
break;
case '.' :
V_179 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_55 :
F_117 () ;
return;
case 'b' :
case 'v' :
V_112 = 1 ;
break;
case 'w' :
V_112 = 2 ;
break;
case 'l' :
V_112 = 4 ;
break;
case 'u' :
V_112 = 8 ;
break;
case '^' :
V_101 -= V_112 ;
break;
case '/' :
if ( V_176 > 0 )
V_101 -= 1 << V_176 ;
else
V_176 = 0 ;
V_176 += 4 ;
V_101 += 1 << V_176 ;
break;
case '\\' :
if ( V_176 < 0 )
V_101 += 1 << - V_176 ;
else
V_176 = 0 ;
V_176 -= 4 ;
V_101 -= 1 << - V_176 ;
break;
case 'm' :
F_78 ( ( void * ) & V_101 ) ;
break;
case 'n' :
V_179 = 1 ;
break;
case 'r' :
V_178 = ! V_178 ;
break;
case '<' :
V_145 = V_112 ;
F_78 ( & V_145 ) ;
V_101 -= V_145 ;
break;
case '>' :
V_145 = V_112 ;
F_78 ( & V_145 ) ;
V_101 += V_145 ;
break;
case '?' :
printf ( V_181 ) ;
break;
}
}
V_101 += V_175 ;
}
}
static int
F_131 ( void )
{
int V_182 ;
V_182 = F_84 () ;
switch( V_182 ) {
case 'n' : V_182 = '\n' ; break;
case 'r' : V_182 = '\r' ; break;
case 'b' : V_182 = '\b' ; break;
case 't' : V_182 = '\t' ; break;
}
return V_182 ;
}
static void F_132 ( unsigned long V_101 , long V_183 )
{
long V_145 , V_184 , V_185 , V_186 ;
unsigned char V_187 [ 16 ] ;
for ( V_145 = V_183 ; V_145 > 0 ; ) {
V_185 = V_145 < 16 ? V_145 : 16 ;
V_186 = F_72 ( V_101 , V_187 , V_185 ) ;
V_101 += V_186 ;
for ( V_184 = 0 ; V_184 < V_185 ; ++ V_184 ) {
if ( V_184 < V_186 )
printf ( L_137 , V_187 [ V_184 ] ) ;
else
printf ( L_138 , V_180 [ V_173 ] ) ;
}
V_145 -= V_185 ;
if ( V_186 < V_185 )
break;
}
printf ( L_33 ) ;
}
static void F_133 ( int V_34 )
{
struct V_188 * V_2 ;
#ifdef F_134
int V_65 = 0 ;
#endif
if ( setjmp ( V_114 ) != 0 ) {
printf ( L_139 , V_34 ) ;
return;
}
V_63 = 1 ;
F_2 () ;
V_2 = & V_189 [ V_34 ] ;
printf ( L_140 , V_34 , V_2 ) ;
printf ( L_141 , 20 , L_142 , F_135 ( V_34 ) ? L_143 : L_144 ) ;
printf ( L_141 , 20 , L_145 , F_136 ( V_34 ) ? L_143 : L_144 ) ;
printf ( L_141 , 20 , L_146 , F_137 ( V_34 ) ? L_143 : L_144 ) ;
#define F_138 ( V_189 , V_113 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 20, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_138 ( V_2 , V_190 , L_147 ) ;
F_138 ( V_2 , V_191 , L_147 ) ;
F_138 ( V_2 , V_192 , L_148 ) ;
F_138 ( V_2 , V_193 , L_148 ) ;
F_138 ( V_2 , V_194 , L_148 ) ;
F_138 ( V_2 , V_195 , L_149 ) ;
#ifdef F_139
F_138 ( V_2 , V_196 , L_149 ) ;
F_138 ( V_2 , V_197 , L_147 ) ;
F_138 ( V_2 , V_198 , L_147 ) ;
#endif
F_138 ( V_2 , V_199 , L_148 ) ;
F_138 ( V_2 , V_200 , L_147 ) ;
F_138 ( V_2 , V_201 , L_147 ) ;
F_138 ( V_2 , V_202 , L_147 ) ;
#ifdef F_134
for ( V_65 = 0 ; V_65 < V_203 ; V_65 ++ ) {
V_171 V_204 , V_205 ;
if ( ! V_2 -> V_206 )
continue;
V_204 = F_140 ( V_2 -> V_206 -> V_207 [ V_65 ] . V_204 ) ;
V_205 = F_140 ( V_2 -> V_206 -> V_207 [ V_65 ] . V_205 ) ;
if ( V_204 || V_205 ) {
printf ( L_150 ,
V_65 , V_204 , V_205 ) ;
}
}
F_138 ( V_2 , V_208 , L_147 ) ;
F_138 ( V_2 , V_209 , L_147 ) ;
for ( V_65 = 0 ; V_65 < V_210 ; V_65 ++ )
printf ( L_151 , V_65 , V_2 -> V_211 [ V_65 ] ) ;
#endif
F_138 ( V_2 , V_212 , L_152 ) ;
#ifdef V_23
F_138 ( V_2 , V_213 , L_149 ) ;
F_138 ( V_2 , V_214 , L_149 ) ;
F_138 ( V_2 , V_215 , L_149 ) ;
F_138 ( V_2 , V_216 , L_149 ) ;
F_138 ( V_2 , V_217 , L_149 ) ;
F_138 ( V_2 , V_218 , L_149 ) ;
#endif
F_138 ( V_2 , V_219 , L_149 ) ;
F_138 ( V_2 , V_220 , L_148 ) ;
F_138 ( V_2 , V_221 , L_148 ) ;
F_138 ( V_2 , V_222 , L_148 ) ;
F_138 ( V_2 , V_223 , L_147 ) ;
F_138 ( V_2 , V_140 , L_147 ) ;
F_138 ( V_2 , V_141 , L_147 ) ;
F_138 ( V_2 , V_224 , L_147 ) ;
F_138 ( V_2 , V_225 , L_147 ) ;
F_138 ( V_2 , V_226 , L_147 ) ;
F_138 ( V_2 , V_227 , L_152 ) ;
#ifdef F_141
F_138 ( V_2 , V_228 , L_152 ) ;
#endif
#ifdef F_142
F_138 ( V_2 , V_229 , L_149 ) ;
F_138 ( V_2 , V_230 , L_147 ) ;
F_138 ( V_2 , V_231 , L_147 ) ;
F_138 ( V_2 , V_232 , L_147 ) ;
#endif
F_138 ( V_2 , V_233 , L_152 ) ;
F_138 ( V_2 , V_234 , L_152 ) ;
F_138 ( V_2 , V_235 , L_152 ) ;
F_138 ( V_2 , V_236 , L_152 ) ;
F_138 ( V_2 , V_237 , L_152 ) ;
F_138 ( V_2 , V_238 , L_152 ) ;
F_138 ( V_2 , V_239 , L_152 ) ;
F_138 ( V_2 , V_240 , L_152 ) ;
#undef F_138
V_63 = 0 ;
F_2 () ;
}
static void F_143 ( void )
{
int V_34 ;
if ( F_144 () == 0 ) {
printf ( L_153 ) ;
return;
}
F_110 (cpu)
F_133 ( V_34 ) ;
}
static void F_145 ( void )
{
unsigned long V_241 ;
int V_182 ;
V_182 = F_84 () ;
if ( V_182 == 'a' ) {
F_143 () ;
return;
}
V_85 = V_182 ;
if ( F_78 ( & V_241 ) )
F_133 ( V_241 ) ;
else
F_133 ( V_45 ) ;
}
static void
F_90 ( void )
{
int V_182 ;
V_182 = F_84 () ;
#ifdef F_123
if ( V_182 == 'p' ) {
F_146 () ;
F_145 () ;
F_147 () ;
return;
}
#endif
if ( ( isxdigit ( V_182 ) && V_182 != 'f' && V_182 != 'd' ) || V_182 == '\n' )
V_85 = V_182 ;
F_78 ( ( void * ) & V_101 ) ;
if ( V_85 != '\n' )
V_85 = 0 ;
if ( V_182 == 'i' ) {
F_78 ( & V_242 ) ;
if ( V_242 == 0 )
V_242 = 16 ;
else if ( V_242 > V_243 )
V_242 = V_243 ;
V_101 += F_45 ( V_101 , V_242 , 1 ) ;
V_80 = L_154 ;
} else if ( V_182 == 'l' ) {
F_148 () ;
} else if ( V_182 == 'r' ) {
F_78 ( & V_183 ) ;
if ( V_183 == 0 )
V_183 = 64 ;
F_132 ( V_101 , V_183 ) ;
V_101 += V_183 ;
V_80 = L_155 ;
} else {
F_78 ( & V_183 ) ;
if ( V_183 == 0 )
V_183 = 64 ;
else if ( V_183 > V_243 )
V_183 = V_243 ;
F_149 ( V_101 , V_183 ) ;
V_101 += V_183 ;
V_80 = L_156 ;
}
}
static void
F_149 ( unsigned long V_101 , long V_183 )
{
long V_145 , V_184 , V_182 , V_185 , V_186 ;
unsigned char V_187 [ 16 ] ;
for ( V_145 = V_183 ; V_145 > 0 ; ) {
printf ( V_103 , V_101 ) ;
putchar ( ' ' ) ;
V_185 = V_145 < 16 ? V_145 : 16 ;
V_186 = F_72 ( V_101 , V_187 , V_185 ) ;
V_101 += V_186 ;
for ( V_184 = 0 ; V_184 < V_185 ; ++ V_184 ) {
if ( ( V_184 & ( sizeof( long ) - 1 ) ) == 0 && V_184 > 0 )
putchar ( ' ' ) ;
if ( V_184 < V_186 )
printf ( L_137 , V_187 [ V_184 ] ) ;
else
printf ( L_138 , V_180 [ V_173 ] ) ;
}
for (; V_184 < 16 ; ++ V_184 ) {
if ( ( V_184 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_61 ) ;
}
printf ( L_157 ) ;
for ( V_184 = 0 ; V_184 < V_185 ; ++ V_184 ) {
if ( V_184 < V_186 ) {
V_182 = V_187 [ V_184 ] ;
putchar ( ' ' <= V_182 && V_182 <= '~' ? V_182 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_145 -= V_185 ;
for (; V_184 < 16 ; ++ V_184 )
putchar ( ' ' ) ;
printf ( L_158 ) ;
if ( V_186 < V_185 )
break;
}
}
static int
F_150 ( unsigned long V_244 , long V_245 , int V_246 ,
T_3 V_247 )
{
int V_186 , V_248 ;
unsigned long V_249 ;
unsigned long V_250 , V_251 = 0 ;
unsigned char V_157 [ 4 ] ;
V_248 = 0 ;
for ( V_249 = V_244 ; V_245 > 0 ; -- V_245 , V_244 += 4 ) {
V_186 = F_72 ( V_244 , V_157 , 4 ) ;
if ( V_186 == 0 ) {
if ( V_246 ) {
const char * V_252 = V_180 [ V_173 ] ;
printf ( V_103 L_159 , V_244 , V_252 , V_252 , V_252 , V_252 ) ;
}
break;
}
V_250 = F_151 ( V_157 ) ;
if ( V_244 > V_249 && V_250 == V_251 ) {
if ( ! V_248 ) {
printf ( L_160 ) ;
V_248 = 1 ;
}
continue;
}
V_248 = 0 ;
V_251 = V_250 ;
if ( V_246 )
printf ( V_103 L_161 , V_244 , V_250 ) ;
printf ( L_162 ) ;
V_247 ( V_250 , V_244 ) ;
printf ( L_33 ) ;
}
return V_244 - V_249 ;
}
static int
F_45 ( unsigned long V_244 , long V_245 , int V_246 )
{
return F_150 ( V_244 , V_245 , V_246 , V_253 ) ;
}
void
F_152 ( unsigned long V_6 )
{
F_36 ( V_6 , L_163 , L_85 ) ;
}
void
F_148 ( void )
{
struct V_254 V_255 = { . V_256 = 1 } ;
unsigned char V_167 [ 128 ] ;
T_4 V_78 ;
if ( setjmp ( V_114 ) != 0 ) {
printf ( L_164 ) ;
return;
}
V_63 = 1 ;
F_2 () ;
F_153 ( & V_255 ) ;
F_146 () ;
while ( F_154 ( & V_255 , false , V_167 , sizeof( V_167 ) , & V_78 ) ) {
V_167 [ V_78 ] = '\0' ;
printf ( L_138 , V_167 ) ;
}
F_147 () ;
F_2 () ;
F_124 ( 200 ) ;
V_63 = 0 ;
}
static void
F_85 ( int V_27 )
{
F_78 ( ( void * ) & V_257 ) ;
if( V_85 != '\n' )
V_85 = 0 ;
F_78 ( ( void * ) ( V_27 == 's' ? & V_258 : & V_259 ) ) ;
if( V_85 != '\n' )
V_85 = 0 ;
F_78 ( ( void * ) & V_260 ) ;
switch( V_27 ) {
case 'm' :
memmove ( ( void * ) V_257 , ( void * ) V_259 , V_260 ) ;
break;
case 's' :
memset ( ( void * ) V_257 , V_258 , V_260 ) ;
break;
case 'd' :
if( V_85 != '\n' )
V_85 = 0 ;
F_78 ( ( void * ) & V_261 ) ;
F_155 ( ( unsigned char * ) V_257 , ( unsigned char * ) V_259 , V_260 , V_261 ) ;
break;
}
}
static void
F_155 ( unsigned char * V_262 , unsigned char * V_263 , unsigned V_264 , unsigned V_265 )
{
unsigned V_145 , V_266 ;
V_266 = 0 ;
for( V_145 = V_264 ; V_145 > 0 ; -- V_145 )
if( * V_262 ++ != * V_263 ++ )
if( ++ V_266 <= V_265 )
printf ( L_165 , V_262 - 1 ,
V_262 [ - 1 ] , V_263 - 1 , V_263 [ - 1 ] ) ;
if( V_266 > V_265 )
printf ( L_166 , V_266 ) ;
}
static void
F_86 ( void )
{
unsigned V_70 , V_145 ;
unsigned char V_157 [ 4 ] ;
V_80 = L_167 ;
F_78 ( ( void * ) & V_257 ) ;
if ( V_85 != '\n' ) {
V_85 = 0 ;
F_78 ( ( void * ) & V_267 ) ;
if ( V_85 != '\n' ) {
V_85 = 0 ;
F_78 ( ( void * ) & V_258 ) ;
V_268 = ~ 0 ;
if ( V_85 != '\n' ) V_85 = 0 ;
F_78 ( ( void * ) & V_268 ) ;
}
}
V_145 = 0 ;
for ( V_70 = V_257 ; V_70 < V_267 ; V_70 += 4 ) {
if ( F_72 ( V_70 , V_157 , 4 ) == 4
&& ( ( F_151 ( V_157 ) ^ V_258 ) & V_268 ) == 0 ) {
printf ( L_168 , V_70 , F_151 ( V_157 ) ) ;
if ( ++ V_145 >= 10 )
break;
}
}
}
static void
F_87 ( void )
{
unsigned char V_100 ;
unsigned V_70 ;
int V_269 , V_270 ;
F_78 ( & V_257 ) ;
if ( V_85 != '\n' ) V_85 = 0 ;
F_78 ( & V_271 ) ;
if ( V_85 != '\n' ) V_85 = 0 ;
F_78 ( & V_272 ) ;
V_270 = 0 ;
for ( V_70 = V_257 ; V_70 < V_272 ; V_70 += V_271 ) {
V_269 = F_72 ( V_70 , & V_100 , 1 ) ;
if ( V_269 && ! V_270 ) {
printf ( L_169 , V_70 ) ;
} else if ( ! V_269 && V_270 )
printf ( L_170 , V_70 - V_271 ) ;
V_270 = V_269 ;
if ( V_70 + V_271 < V_70 )
break;
}
if ( V_270 )
printf ( L_170 , V_70 - V_271 ) ;
}
static void F_104 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_109 ;
int V_65 ;
typedef unsigned long (* T_5)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_5 V_273 ;
if ( ! F_78 ( & V_101 ) )
return;
if ( V_85 != '\n' )
V_85 = 0 ;
for ( V_65 = 0 ; V_65 < 8 ; ++ V_65 )
args [ V_65 ] = 0 ;
for ( V_65 = 0 ; V_65 < 8 ; ++ V_65 ) {
if ( ! F_78 ( & args [ V_65 ] ) || V_85 == '\n' )
break;
V_85 = 0 ;
}
V_273 = ( T_5 ) V_101 ;
V_109 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_109 = V_273 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_2 () ;
printf ( L_171 , V_109 ) ;
} else {
printf ( L_172 , V_172 ) ;
}
V_63 = 0 ;
}
int
F_82 ( void )
{
int V_182 ;
if( V_85 != 0 ) {
V_182 = V_85 ;
V_85 = 0 ;
} else
V_182 = F_84 () ;
while( V_182 == ' ' || V_182 == '\t' )
V_182 = F_84 () ;
return V_182 ;
}
int
F_78 ( unsigned long * V_274 )
{
int V_182 , V_58 ;
unsigned long V_100 ;
V_182 = F_82 () ;
if ( V_182 == '%' ) {
char V_275 [ 8 ] ;
int V_65 ;
for ( V_65 = 0 ; V_65 < sizeof( V_275 ) - 1 ; ++ V_65 ) {
V_182 = F_84 () ;
if ( ! isalnum ( V_182 ) ) {
V_85 = V_182 ;
break;
}
V_275 [ V_65 ] = V_182 ;
}
V_275 [ V_65 ] = 0 ;
for ( V_65 = 0 ; V_65 < V_276 ; ++ V_65 ) {
if ( strcmp ( V_277 [ V_65 ] , V_275 ) == 0 ) {
if ( V_81 == NULL ) {
printf ( L_173 ) ;
return 0 ;
}
* V_274 = ( ( unsigned long * ) V_81 ) [ V_65 ] ;
return 1 ;
}
}
printf ( L_174 , V_275 ) ;
return 0 ;
}
if ( V_182 == '0' ) {
V_182 = F_84 () ;
if ( V_182 == 'x' ) {
V_182 = F_84 () ;
} else {
V_58 = F_156 ( V_182 ) ;
if ( V_58 == V_55 ) {
V_85 = V_182 ;
* V_274 = 0 ;
return 1 ;
}
}
} else if ( V_182 == '$' ) {
int V_65 ;
for ( V_65 = 0 ; V_65 < 63 ; V_65 ++ ) {
V_182 = F_84 () ;
if ( isspace ( V_182 ) || V_182 == '\0' ) {
V_85 = V_182 ;
break;
}
V_115 [ V_65 ] = V_182 ;
}
V_115 [ V_65 ++ ] = 0 ;
* V_274 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
* V_274 = F_157 ( V_115 ) ;
F_2 () ;
}
V_63 = 0 ;
if ( ! ( * V_274 ) ) {
printf ( L_175 , V_115 ) ;
return 0 ;
}
return 1 ;
}
V_58 = F_156 ( V_182 ) ;
if ( V_58 == V_55 ) {
V_85 = V_182 ;
return 0 ;
}
V_100 = 0 ;
do {
V_100 = ( V_100 << 4 ) + V_58 ;
V_182 = F_84 () ;
V_58 = F_156 ( V_182 ) ;
} while ( V_58 != V_55 );
V_85 = V_182 ;
* V_274 = V_100 ;
return 1 ;
}
static void
F_117 ( void )
{
int V_182 ;
V_182 = V_85 ;
V_85 = 0 ;
while( V_182 != '\n' )
V_182 = F_84 () ;
}
static int F_156 ( int V_182 )
{
if( '0' <= V_182 && V_182 <= '9' )
return V_182 - '0' ;
if( 'A' <= V_182 && V_182 <= 'F' )
return V_182 - ( 'A' - 10 ) ;
if( 'a' <= V_182 && V_182 <= 'f' )
return V_182 - ( 'a' - 10 ) ;
return V_55 ;
}
void
F_158 ( char * V_278 , int V_112 )
{
int V_182 ;
V_182 = F_82 () ;
do {
if( V_112 > 1 ) {
* V_278 ++ = V_182 ;
-- V_112 ;
}
V_182 = F_84 () ;
} while( V_182 != ' ' && V_182 != '\t' && V_182 != '\n' );
V_85 = V_182 ;
* V_278 = 0 ;
}
static void
F_81 ( void )
{
V_279 = NULL ;
}
static int
F_84 ( void )
{
if ( V_279 == NULL || * V_279 == 0 ) {
if ( F_159 ( line , sizeof( line ) ) == NULL ) {
V_279 = NULL ;
return V_55 ;
}
V_279 = line ;
}
return * V_279 ++ ;
}
static void
F_83 ( char * V_280 )
{
V_279 = V_280 ;
}
static void
F_91 ( void )
{
int type = F_84 () ;
unsigned long V_6 ;
static char V_281 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_78 ( & V_6 ) )
F_36 ( V_6 , L_99 , L_33 ) ;
V_85 = 0 ;
break;
case 's' :
F_158 ( V_281 , 64 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_6 = F_157 ( V_281 ) ;
if ( V_6 )
printf ( L_176 , V_281 , V_6 ) ;
else
printf ( L_177 , V_281 ) ;
F_2 () ;
}
V_63 = 0 ;
V_85 = 0 ;
break;
}
}
static void F_36 ( unsigned long V_37 , const char * V_282 ,
const char * V_283 )
{
char * V_284 ;
const char * V_113 = NULL ;
unsigned long V_32 , V_112 ;
printf ( V_103 , V_37 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_113 = F_116 ( V_37 , & V_112 , & V_32 , & V_284 ,
V_115 ) ;
F_2 () ;
F_124 ( 200 ) ;
}
V_63 = 0 ;
if ( V_113 ) {
printf ( L_178 , V_282 , V_113 , V_32 , V_112 ) ;
if ( V_284 )
printf ( L_179 , V_284 ) ;
}
printf ( L_138 , V_283 ) ;
}
void F_106 ( void )
{
int V_65 ;
unsigned long V_204 , V_205 ;
unsigned long V_285 ;
printf ( L_180 , F_15 () ) ;
for ( V_65 = 0 ; V_65 < V_286 ; V_65 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( V_204 || V_205 ) {
printf ( L_181 , V_65 , V_204 , V_205 ) ;
if ( V_204 & V_287 ) {
V_285 = V_205 & V_288 ;
if ( V_205 & V_289 ) {
printf ( L_182 ,
F_160 ( V_204 ) ,
( V_205 & ~ V_290 ) >> V_291 ,
V_285 ) ;
} else {
printf ( L_183 ,
F_161 ( V_204 ) ,
( V_205 & ~ V_290 ) >> V_292 ,
V_285 ) ;
}
} else
printf ( L_33 ) ;
}
}
}
void F_106 ( void )
{
int V_65 ;
printf ( L_184 ) ;
for ( V_65 = 0 ; V_65 < 16 ; ++ V_65 )
printf ( L_185 , F_162 ( V_65 ) ) ;
printf ( L_33 ) ;
}
static void F_107 ( void )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_293 ; V_65 ++ ) {
unsigned long V_294 , V_295 , V_296 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_186 , V_65 , V_294 , V_295 , V_296 ) ;
if ( V_294 & V_297 ) {
printf ( L_187 ,
V_294 & V_298 ,
V_295 & V_299 ,
V_295 & V_300 ,
( V_296 & V_301 ) ? 'W' : 'w' ,
( V_296 & V_302 ) ? 'I' : 'i' ,
( V_296 & V_303 ) ? 'M' : 'm' ,
( V_296 & V_304 ) ? 'G' : 'g' ,
( V_296 & V_305 ) ? 'E' : 'e' ) ;
}
printf ( L_33 ) ;
}
}
static void F_108 ( void )
{
V_170 V_306 , V_307 , V_308 ;
V_171 V_309 ;
int V_65 , V_310 , V_311 , V_312 , V_313 , V_314 , V_315 = 0 ;
int V_316 ;
static const char * V_317 [] = {
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
V_306 = F_109 ( V_318 ) ;
V_316 = ( V_306 & 3 ) + 1 ;
V_311 = ( ( V_306 >> 2 ) & 3 ) + 1 ;
V_312 = ( ( V_306 >> 6 ) & 0x1f ) + 1 ;
V_313 = ( V_306 >> 24 ) & 0xf ;
V_314 = ( V_306 >> 16 ) & 0x7f ;
if ( ( V_316 > 1 ) && ( V_306 & 0x10000 ) )
V_315 = 1 ;
printf ( L_220 ,
V_316 , V_311 , V_312 , V_313 , V_314 ) ;
V_307 = ( 1ul << V_312 ) - 1 ;
V_308 = ( 1ul << V_313 ) - 1 ;
V_309 = ( 1ull << V_314 ) - 1 ;
for ( V_310 = 0 ; V_310 < V_311 ; V_310 ++ ) {
V_170 V_319 ;
int V_320 , V_321 , V_322 = 1 ;
printf ( L_221 , V_310 ) ;
switch( V_310 ) {
case 0 :
V_319 = F_109 ( V_323 ) ;
break;
case 1 :
V_319 = F_109 ( V_324 ) ;
break;
case 2 :
V_319 = F_109 ( V_325 ) ;
break;
case 3 :
V_319 = F_109 ( V_326 ) ;
break;
default:
printf ( L_222 ) ;
continue;
}
V_320 = V_319 & 0xfff ;
V_321 = ( V_319 >> 24 ) & 0xff ;
for ( V_65 = 0 ; V_65 < V_320 ; V_65 ++ ) {
V_170 V_327 = F_163 ( V_310 ) ;
V_170 V_328 = F_164 ( V_329 ) ;
V_171 V_330 = 0 ;
V_171 V_331 ;
int V_332 = V_65 , V_333 = V_65 ;
if ( V_321 != 0 ) {
V_333 = V_65 / V_321 ;
V_332 = V_65 % V_321 ;
V_330 = V_333 * 0x1000 ;
}
V_327 |= F_165 ( V_332 ) ;
F_8 ( V_334 , V_327 ) ;
F_8 ( V_335 , V_328 ) ;
F_8 ( V_336 , V_330 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_328 = F_109 ( V_335 ) ;
V_330 = F_109 ( V_336 ) ;
V_331 = F_109 ( V_337 ) ;
if ( V_321 && ( V_65 % V_321 ) == 0 )
V_322 = 1 ;
if ( ! ( V_328 & V_338 ) )
continue;
if ( V_321 == 0 )
printf ( L_223 , V_65 ) ;
else if ( V_322 )
printf ( L_224 , V_333 , 'A' + V_332 ) ;
else
printf ( L_225 , 'A' + V_332 ) ;
V_322 = 0 ;
printf ( L_226 ,
V_330 & ~ 0x3ffull ,
( V_328 >> 16 ) & 0x3fff ,
V_317 [ ( V_328 >> 7 ) & 0x1f ] ,
V_328 & V_339 ? 'I' : ' ' ,
V_328 & V_340 ? 'P' : ' ' ,
V_328 & V_341 ? '1' : '0' ) ;
printf ( L_227 ,
V_330 & V_342 ? 'a' : ' ' ,
V_330 & V_343 ? 'v' : ' ' ,
V_330 & V_344 ? 'w' : ' ' ,
V_330 & V_345 ? 'i' : ' ' ,
V_330 & V_346 ? 'm' : ' ' ,
V_330 & V_347 ? 'g' : ' ' ,
V_330 & V_348 ? 'e' : ' ' ) ;
printf ( L_228 , V_331 & V_309 & ~ 0x7ffull ) ;
if ( V_328 & V_339 )
printf ( L_229 ,
V_317 [ ( V_331 >> 1 ) & 0x1f ] ) ;
else
printf ( L_230 ,
V_331 & V_349 ? 'x' : ' ' ,
V_331 & V_350 ? 'w' : ' ' ,
V_331 & V_351 ? 'r' : ' ' ,
V_331 & V_352 ? 'x' : ' ' ,
V_331 & V_353 ? 'w' : ' ' ,
V_331 & V_354 ? 'r' : ' ' ) ;
}
}
}
static void F_166 ( int V_355 )
{
if ( V_355 ) {
V_356 = F_57 ;
V_357 = F_66 ;
V_358 = F_61 ;
V_359 = F_62 ;
V_360 = F_65 ;
V_361 = F_64 ;
V_362 = F_67 ;
} else {
V_356 = NULL ;
V_357 = NULL ;
V_358 = NULL ;
V_359 = NULL ;
V_360 = NULL ;
V_361 = NULL ;
V_362 = NULL ;
}
}
static void F_167 ( int V_363 )
{
F_166 ( 1 ) ;
F_168 ( F_60 () ) ;
}
static int T_6 F_169 ( void )
{
F_170 ( 'x' , & V_364 ) ;
return 0 ;
}
static int T_6 F_171 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_231 , 5 ) == 0 ) {
F_166 ( 1 ) ;
V_365 = 1 ;
} else if ( strncmp ( V_2 , L_232 , 2 ) == 0 )
F_166 ( 1 ) ;
else if ( strncmp ( V_2 , L_233 , 3 ) == 0 )
V_366 = 1 ;
else if ( strncmp ( V_2 , L_234 , 4 ) == 0 )
V_82 = 1 ;
else
return 1 ;
return 0 ;
}
void T_6 F_172 ( void )
{
#ifdef F_173
if ( ! V_366 )
F_166 ( 1 ) ;
#endif
if ( V_365 )
F_168 ( NULL ) ;
}
void F_174 ( struct V_367 * V_368 )
{
struct V_369 * V_369 ;
F_175 (spu, list, full_list) {
if ( V_369 -> V_370 >= V_371 ) {
F_176 ( 1 ) ;
continue;
}
V_372 [ V_369 -> V_370 ] . V_369 = V_369 ;
V_372 [ V_369 -> V_370 ] . V_373 = 0 ;
V_372 [ V_369 -> V_370 ] . V_374 = ( unsigned long )
V_372 [ V_369 -> V_370 ] . V_369 -> V_375 ;
}
}
static void F_177 ( void )
{
struct V_369 * V_369 ;
int V_65 ;
V_171 V_281 ;
for ( V_65 = 0 ; V_65 < V_371 ; V_65 ++ ) {
if ( ! V_372 [ V_65 ] . V_369 )
continue;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_369 = V_372 [ V_65 ] . V_369 ;
V_372 [ V_65 ] . V_376 =
F_178 ( & V_369 -> V_377 -> V_378 ) ;
V_281 = F_179 ( V_369 ) ;
V_372 [ V_65 ] . V_379 = V_281 ;
V_281 &= ~ V_380 ;
F_180 ( V_369 , V_281 ) ;
F_2 () ;
F_124 ( 200 ) ;
V_372 [ V_65 ] . V_373 = 1 ;
printf ( L_235 , V_65 ,
V_372 [ V_65 ] . V_376 ?
L_236 : L_237 ) ;
} else {
V_63 = 0 ;
printf ( L_238 , V_65 ) ;
}
V_63 = 0 ;
}
}
static void F_181 ( void )
{
struct V_369 * V_369 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_371 ; V_65 ++ ) {
if ( ! V_372 [ V_65 ] . V_369 )
continue;
if ( ! V_372 [ V_65 ] . V_373 ) {
printf ( L_239
L_240 , V_65 ) ;
continue;
}
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_369 = V_372 [ V_65 ] . V_369 ;
F_180 ( V_369 , V_372 [ V_65 ] . V_379 ) ;
F_182 ( & V_369 -> V_377 -> V_378 ,
V_372 [ V_65 ] . V_376 ) ;
F_2 () ;
F_124 ( 200 ) ;
printf ( L_241 , V_65 ) ;
} else {
V_63 = 0 ;
printf ( L_242 , V_65 ) ;
}
V_63 = 0 ;
}
}
static void F_183 ( struct V_369 * V_369 )
{
printf ( L_243 , V_369 ) ;
F_184 ( V_369 , L_244 , V_370 ) ;
F_184 ( V_369 , L_138 , V_113 ) ;
F_184 ( V_369 , L_245 , V_381 ) ;
F_184 ( V_369 , L_246 , V_375 ) ;
F_184 ( V_369 , L_245 , V_382 ) ;
F_184 ( V_369 , L_244 , V_383 ) ;
F_184 ( V_369 , L_245 , V_33 ) ;
F_184 ( V_369 , L_247 , V_384 ) ;
F_184 ( V_369 , L_245 , V_385 ) ;
F_184 ( V_369 , L_245 , V_386 ) ;
F_184 ( V_369 , L_245 , V_387 ) ;
F_184 ( V_369 , L_245 , V_388 [ 0 ] ) ;
F_184 ( V_369 , L_245 , V_388 [ 1 ] ) ;
F_184 ( V_369 , L_245 , V_388 [ 2 ] ) ;
F_184 ( V_369 , L_244 , V_389 ) ;
F_184 ( V_369 , L_247 , V_142 ) ;
F_184 ( V_369 , L_246 , V_390 ) ;
F_184 ( V_369 , L_246 , V_391 ) ;
F_184 ( V_369 , L_246 , V_392 ) ;
F_184 ( V_369 , L_246 , V_393 ) ;
F_184 ( V_369 , L_245 , V_394 ) ;
F_184 ( V_369 , L_246 , V_377 ) ;
F_185 ( L_244 , V_377 -> V_378 ,
F_178 ( & V_369 -> V_377 -> V_378 ) ) ;
F_185 ( L_244 , V_377 -> V_395 ,
F_178 ( & V_369 -> V_377 -> V_395 ) ) ;
F_185 ( L_244 , V_377 -> V_396 ,
F_178 ( & V_369 -> V_377 -> V_396 ) ) ;
F_184 ( V_369 , L_246 , V_397 ) ;
F_184 ( V_369 , L_246 , V_398 ) ;
}
int
F_186 ( unsigned long V_244 , long V_245 , int V_246 )
{
return F_150 ( V_244 , V_245 , V_246 , V_399 ) ;
}
static void F_187 ( unsigned long V_241 , int V_400 )
{
unsigned long V_32 , V_6 , V_401 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_2 () ;
V_401 = ( unsigned long ) V_372 [ V_241 ] . V_369 -> V_375 ;
F_2 () ;
F_124 ( 200 ) ;
} else {
V_63 = 0 ;
printf ( L_248 , V_241 ) ;
return;
}
V_63 = 0 ;
if ( F_78 ( & V_32 ) )
V_6 = V_401 + V_32 ;
else
V_6 = V_372 [ V_241 ] . V_374 ;
if ( V_6 >= V_401 + V_402 ) {
printf ( L_249 ) ;
return;
}
switch ( V_400 ) {
case 'i' :
V_6 += F_186 ( V_6 , 16 , 1 ) ;
V_80 = L_250 ;
break;
default:
F_149 ( V_6 , 64 ) ;
V_6 += 64 ;
V_80 = L_251 ;
break;
}
V_372 [ V_241 ] . V_374 = V_6 ;
}
static int F_96 ( void )
{
static unsigned long V_241 = 0 ;
int V_27 , V_400 = 0 ;
V_27 = F_84 () ;
switch ( V_27 ) {
case 's' :
F_177 () ;
break;
case 'r' :
F_181 () ;
break;
case 'd' :
V_400 = F_84 () ;
if ( isxdigit ( V_400 ) || V_400 == '\n' )
V_85 = V_400 ;
case 'f' :
F_78 ( & V_241 ) ;
if ( V_241 >= V_371 || ! V_372 [ V_241 ] . V_369 ) {
printf ( L_252 ) ;
return 0 ;
}
switch ( V_27 ) {
case 'f' :
F_183 ( V_372 [ V_241 ] . V_369 ) ;
break;
default:
F_187 ( V_241 , V_400 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_96 ( void )
{
return - 1 ;
}
