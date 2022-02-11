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
static inline int F_22 ( struct V_20 * V_21 )
{
#if F_23 ( V_22 ) || F_23 ( V_23 )
return 0 ;
#else
return ( ( V_21 -> V_24 & V_25 ) == 0 ) ;
#endif
}
static int F_24 ( struct V_20 * V_21 , int V_26 )
{
int V_27 = 0 ;
struct V_28 * V_29 ;
long V_30 [ V_31 ] ;
unsigned long V_32 ;
unsigned long V_33 ;
#ifdef F_25
int V_34 ;
int V_35 ;
unsigned long V_17 ;
#endif
F_26 ( V_33 ) ;
F_27 () ;
V_29 = F_28 ( V_21 -> V_36 , & V_32 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = V_29 -> V_37 + V_32 ;
F_29 ( & V_29 -> V_38 ) ;
}
F_30 () ;
#ifdef F_25
V_34 = F_16 () ;
if ( F_31 ( V_34 , & V_19 ) ) {
F_15 () ;
F_32 ( V_21 ) ;
printf ( L_3
L_4 ,
V_34 , V_21 -> V_39 , F_33 ( F_34 ( V_21 ) ) ) ;
F_19 () ;
longjmp ( V_40 [ V_34 ] , 1 ) ;
}
if ( setjmp ( V_30 ) != 0 ) {
if ( ! V_41 || ! V_42 ) {
F_15 () ;
printf ( L_5
L_6 , V_34 ) ;
F_19 () ;
goto V_43;
}
V_35 = ! ( V_44 && V_34 == V_45 ) ;
goto V_46;
}
V_40 [ V_34 ] = V_30 ;
V_29 = NULL ;
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) == ( V_47 | V_49 ) )
V_29 = F_35 ( V_21 -> V_36 ) ;
if ( V_29 || F_22 ( V_21 ) )
V_26 = 0 ;
if ( ! V_26 ) {
F_15 () ;
F_32 ( V_21 ) ;
if ( V_29 ) {
printf ( L_7 ,
V_34 , F_36 ( V_29 ) ) ;
F_37 ( V_21 -> V_36 , L_8 , L_9 ) ;
}
if ( F_22 ( V_21 ) )
printf ( L_10
L_11 ) ;
F_19 () ;
}
F_38 ( V_34 , & V_19 ) ;
V_43:
V_35 = 1 ;
while ( V_35 && ! V_42 ) {
if ( V_41 == 0 ) {
if ( V_26 )
goto V_50;
V_35 = F_39 ( 0 , & V_41 ) ;
}
F_40 () ;
}
if ( ! V_35 && ! V_42 ) {
int V_51 = F_41 () ;
V_45 = V_34 ;
F_42 () ;
if ( V_51 > 1 ) {
F_43 () ;
for ( V_17 = 100000000 ; V_17 != 0 ; -- V_17 ) {
if ( F_44 ( & V_19 ) >= V_51 )
break;
F_40 () ;
}
}
F_45 () ;
F_11 () ;
if ( V_29 || F_34 ( V_21 ) == 0xd00 )
F_46 ( V_21 -> V_36 , 1 , 0 ) ;
printf ( L_12 ) ;
F_42 () ;
V_42 = 1 ;
F_40 () ;
}
V_46:
while ( V_41 ) {
if ( V_35 ) {
if ( V_34 == V_45 ) {
if ( ! F_39 ( 0 , & V_44 ) ) {
V_35 = 0 ;
continue;
}
while ( V_34 == V_45 )
F_40 () ;
}
F_40 () ;
} else {
V_27 = F_47 ( V_21 ) ;
if ( V_27 != 0 ) {
F_48 () ;
V_42 = 0 ;
F_49 () ;
V_41 = 0 ;
break;
}
V_35 = 1 ;
}
}
V_50:
F_50 ( V_34 , & V_19 ) ;
V_40 [ V_34 ] = NULL ;
#else
if ( V_41 ) {
printf ( L_13 ,
V_21 -> V_39 , F_33 ( F_34 ( V_21 ) ) ) ;
longjmp ( V_40 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_30 ) == 0 ) {
V_40 [ 0 ] = V_30 ;
V_41 = 1 ;
F_32 ( V_21 ) ;
V_29 = F_35 ( V_21 -> V_36 ) ;
if ( V_29 ) {
printf ( L_14 , F_36 ( V_29 ) ) ;
F_37 ( V_21 -> V_36 , L_8 , L_9 ) ;
}
if ( F_22 ( V_21 ) )
printf ( L_10
L_11 ) ;
F_45 () ;
F_11 () ;
if ( V_29 || F_34 ( V_21 ) == 0xd00 )
F_46 ( V_21 -> V_36 , 1 , 0 ) ;
printf ( L_12 ) ;
}
V_27 = F_47 ( V_21 ) ;
F_48 () ;
V_41 = 0 ;
#endif
#ifdef F_51
if ( V_21 -> V_24 & V_52 ) {
V_29 = F_35 ( V_21 -> V_36 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = ( unsigned long ) & V_29 -> V_53 [ 0 ] ;
F_52 ( & V_29 -> V_38 ) ;
}
}
#else
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) == ( V_47 | V_49 ) ) {
V_29 = F_35 ( V_21 -> V_36 ) ;
if ( V_29 != NULL ) {
int V_54 = F_53 ( V_21 , V_29 -> V_53 [ 0 ] ) ;
if ( V_54 == 0 ) {
V_21 -> V_36 = ( unsigned long ) & V_29 -> V_53 [ 0 ] ;
F_52 ( & V_29 -> V_38 ) ;
} else if ( V_54 < 0 ) {
printf ( L_15 ,
( F_54 ( V_29 -> V_53 [ 0 ] ) ? L_16 : L_17 ) ) ;
}
}
}
#endif
F_55 () ;
F_56 () ;
F_57 ( V_33 ) ;
return V_27 != 'X' && V_27 != V_55 ;
}
int F_58 ( struct V_20 * V_56 )
{
struct V_20 V_21 ;
if ( V_56 == NULL ) {
F_59 ( & V_21 ) ;
V_56 = & V_21 ;
}
return F_24 ( V_56 , 0 ) ;
}
T_1 F_60 ( int V_57 , void * V_58 )
{
unsigned long V_33 ;
F_26 ( V_33 ) ;
printf ( L_18 ) ;
F_58 ( F_61 () ) ;
F_57 ( V_33 ) ;
return V_59 ;
}
static int F_62 ( struct V_20 * V_21 )
{
struct V_28 * V_29 ;
unsigned long V_32 ;
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) != ( V_47 | V_49 ) )
return 0 ;
V_29 = F_28 ( V_21 -> V_36 , & V_32 ) ;
if ( V_29 != NULL && V_32 == 4 ) {
V_21 -> V_36 = V_29 -> V_37 + 4 ;
F_29 ( & V_29 -> V_38 ) ;
return 1 ;
}
V_29 = F_35 ( V_21 -> V_36 ) ;
if ( ! V_29 )
return 0 ;
F_24 ( V_21 , 0 ) ;
return 1 ;
}
static int F_63 ( struct V_20 * V_21 )
{
if ( F_64 ( V_21 ) )
return 0 ;
F_24 ( V_21 , 0 ) ;
return 1 ;
}
static int F_65 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) != ( V_47 | V_49 ) )
return 0 ;
if ( V_60 . V_61 == 0 )
return 0 ;
F_24 ( V_21 , 0 ) ;
return 1 ;
}
static int F_66 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) != ( V_47 | V_49 ) )
return 0 ;
if ( V_62 == NULL )
return 0 ;
F_24 ( V_21 , 0 ) ;
return 1 ;
}
static int F_67 ( struct V_20 * V_21 )
{
#ifdef F_25
if ( V_41 && ! F_31 ( F_16 () , & V_19 ) )
F_24 ( V_21 , 1 ) ;
#endif
return 0 ;
}
static int F_68 ( struct V_20 * V_21 )
{
struct V_28 * V_29 ;
unsigned long V_32 ;
if ( V_41 && V_63 )
F_69 ( V_21 ) ;
if ( ( V_21 -> V_24 & ( V_47 | V_48 | V_49 ) ) == ( V_47 | V_49 ) ) {
V_29 = F_28 ( V_21 -> V_36 , & V_32 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = V_29 -> V_37 + V_32 ;
F_29 ( & V_29 -> V_38 ) ;
}
}
return 0 ;
}
static struct V_28 * F_35 ( unsigned long V_64 )
{
int V_65 ;
struct V_28 * V_29 ;
V_29 = V_66 ;
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 , ++ V_29 )
if ( V_29 -> V_61 && V_64 == V_29 -> V_37 )
return V_29 ;
return NULL ;
}
static struct V_28 * F_28 ( unsigned long V_36 , unsigned long * V_68 )
{
unsigned long V_69 ;
V_69 = V_36 - ( unsigned long ) V_66 ;
if ( V_69 >= sizeof( V_66 ) )
return NULL ;
V_69 %= sizeof( struct V_28 ) ;
if ( V_69 != F_70 ( struct V_28 , V_53 [ 0 ] )
&& V_69 != F_70 ( struct V_28 , V_53 [ 1 ] ) )
return NULL ;
* V_68 = V_69 - F_70 ( struct V_28 , V_53 [ 0 ] ) ;
return (struct V_28 * ) ( V_36 - V_69 ) ;
}
static struct V_28 * F_71 ( unsigned long V_70 )
{
struct V_28 * V_29 ;
V_70 &= ~ 3UL ;
V_29 = F_35 ( V_70 ) ;
if ( V_29 )
return V_29 ;
for ( V_29 = V_66 ; V_29 < & V_66 [ V_67 ] ; ++ V_29 ) {
if ( ! V_29 -> V_61 && F_72 ( & V_29 -> V_38 ) == 0 ) {
V_29 -> V_37 = V_70 ;
V_29 -> V_53 [ 1 ] = V_71 ;
F_4 ( & V_29 -> V_53 [ 1 ] ) ;
return V_29 ;
}
}
printf ( L_19 ) ;
return NULL ;
}
static void F_48 ( void )
{
int V_65 ;
struct V_28 * V_29 ;
V_29 = V_66 ;
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 , ++ V_29 ) {
if ( ( V_29 -> V_61 & ( V_72 | V_73 ) ) == 0 )
continue;
if ( F_73 ( V_29 -> V_37 , & V_29 -> V_53 [ 0 ] , 4 ) != 4 ) {
printf ( L_20
L_21 , V_29 -> V_37 ) ;
V_29 -> V_61 = 0 ;
continue;
}
if ( F_74 ( V_29 -> V_53 [ 0 ] ) || F_54 ( V_29 -> V_53 [ 0 ] ) ) {
printf ( L_22
L_23 , V_29 -> V_37 ) ;
V_29 -> V_61 = 0 ;
continue;
}
F_4 ( & V_29 -> V_53 [ 0 ] ) ;
if ( V_29 -> V_61 & V_73 )
continue;
if ( F_75 ( V_29 -> V_37 , & V_71 , 4 ) != 4 ) {
printf ( L_24
L_21 , V_29 -> V_37 ) ;
V_29 -> V_61 &= ~ V_72 ;
continue;
}
F_4 ( ( void * ) V_29 -> V_37 ) ;
}
}
static void F_55 ( void )
{
struct V_74 V_75 ;
if ( V_60 . V_61 ) {
V_75 . V_37 = V_60 . V_37 ;
V_75 . type = ( V_60 . V_61 & V_76 ) | V_77 ;
V_75 . V_78 = 8 ;
F_76 ( & V_75 ) ;
}
if ( V_62 )
F_10 ( V_62 -> V_37 ) ;
}
static void F_45 ( void )
{
int V_65 ;
struct V_28 * V_29 ;
unsigned V_53 ;
V_29 = V_66 ;
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 , ++ V_29 ) {
if ( ( V_29 -> V_61 & ( V_72 | V_73 ) ) != V_72 )
continue;
if ( F_73 ( V_29 -> V_37 , & V_53 , 4 ) == 4
&& V_53 == V_71
&& F_75 ( V_29 -> V_37 , & V_29 -> V_53 , 4 ) != 4 )
printf ( L_25 ,
V_29 -> V_37 ) ;
else
F_4 ( ( void * ) V_29 -> V_37 ) ;
}
}
static void F_30 ( void )
{
F_77 () ;
F_7 ( 0 ) ;
}
static void F_78 ( void )
{
unsigned long V_79 ;
if ( ! F_79 ( & V_79 ) ) {
printf ( L_26 ) ;
V_79 = 0 ;
}
F_80 ( V_79 ) ;
}
static int
F_47 ( struct V_20 * V_56 )
{
int V_27 = 0 ;
V_80 = NULL ;
V_81 = V_56 ;
if ( ! V_82 ) {
V_82 = 1 ;
F_81 ( V_56 -> V_83 [ 1 ] , V_56 -> V_84 , V_56 -> V_36 ) ;
}
for(; ; ) {
#ifdef F_25
printf ( L_27 , F_16 () ) ;
#endif
printf ( L_28 ) ;
F_82 () ;
V_85 = 0 ;
V_27 = F_83 () ;
if( V_27 == '\n' ) {
if ( V_80 == NULL )
continue;
F_84 ( V_80 ) ;
V_80 = NULL ;
V_27 = F_85 () ;
}
switch ( V_27 ) {
case 'm' :
V_27 = F_85 () ;
switch ( V_27 ) {
case 'm' :
case 's' :
case 'd' :
F_86 ( V_27 ) ;
break;
case 'l' :
F_87 () ;
break;
case 'z' :
F_88 () ;
break;
case 'i' :
F_89 ( 0 ) ;
break;
default:
V_85 = V_27 ;
F_90 () ;
}
break;
case 'd' :
F_91 () ;
break;
case 'l' :
F_92 () ;
break;
case 'r' :
F_93 ( V_56 ) ;
break;
case 'e' :
F_32 ( V_56 ) ;
break;
case 'S' :
F_94 () ;
break;
case 't' :
F_95 ( V_56 ) ;
break;
case 'f' :
F_96 () ;
break;
case 's' :
if ( F_97 () == 0 )
break;
if ( F_98 ( V_56 ) )
return V_27 ;
break;
case 'x' :
case 'X' :
return V_27 ;
case V_55 :
printf ( L_29 ) ;
F_99 ( 2000 ) ;
return V_27 ;
case '?' :
F_100 ( V_86 ) ;
break;
case '#' :
F_78 () ;
break;
case 'b' :
F_101 () ;
break;
case 'C' :
F_102 () ;
break;
case 'c' :
if ( F_103 () )
return 0 ;
break;
case 'z' :
F_104 () ;
break;
case 'p' :
F_105 () ;
break;
case 'P' :
F_106 () ;
break;
#ifdef F_107
case 'u' :
F_108 () ;
break;
#elif F_23 ( V_87 )
case 'u' :
F_109 () ;
break;
#elif F_23 ( V_23 )
case 'u' :
F_110 () ;
break;
#endif
default:
printf ( L_30 ) ;
do {
if ( ' ' < V_27 && V_27 <= '~' )
putchar ( V_27 ) ;
else
printf ( L_31 , V_27 ) ;
V_27 = F_85 () ;
} while ( V_27 != '\n' );
printf ( L_32 ) ;
break;
}
}
}
static int F_98 ( struct V_20 * V_21 )
{
V_21 -> V_24 |= V_52 ;
F_9 ( V_88 , F_111 ( V_88 ) | V_89 | V_90 ) ;
return 1 ;
}
static int F_98 ( struct V_20 * V_21 )
{
unsigned int V_53 ;
int V_54 ;
if ( ( V_21 -> V_24 & ( V_49 | V_48 | V_47 ) ) == ( V_49 | V_47 ) ) {
if ( F_73 ( V_21 -> V_36 , & V_53 , 4 ) == 4 ) {
V_54 = F_53 ( V_21 , V_53 ) ;
if ( V_54 < 0 ) {
printf ( L_15 ,
( F_54 ( V_53 ) ? L_16 : L_17 ) ) ;
return 0 ;
}
if ( V_54 > 0 ) {
V_21 -> V_39 = 0xd00 | ( V_21 -> V_39 & 1 ) ;
printf ( L_33 ) ;
F_37 ( V_21 -> V_36 , L_8 , L_34 ) ;
F_46 ( V_21 -> V_36 , 1 , 0 ) ;
return 0 ;
}
}
}
V_21 -> V_24 |= V_91 ;
return 1 ;
}
static void F_104 ( void )
{
int V_27 ;
V_27 = F_85 () ;
if ( V_27 == 'r' )
V_92 . V_93 ( NULL ) ;
else if ( V_27 == 'h' )
V_92 . V_94 () ;
else if ( V_27 == 'p' )
if ( V_95 )
V_95 () ;
}
static int F_103 ( void )
{
#ifdef F_25
unsigned long V_34 , V_96 , V_97 ;
int V_17 ;
if ( ! F_79 ( & V_34 ) ) {
printf ( L_35 ) ;
V_97 = V_96 = V_98 ;
F_112 (cpu) {
if ( F_31 ( V_34 , & V_19 ) ) {
if ( V_34 == V_97 + 1 ) {
V_97 = V_34 ;
} else {
if ( V_97 != V_96 )
printf ( L_36 , V_97 ) ;
V_97 = V_96 = V_34 ;
printf ( L_37 , V_34 ) ;
}
}
}
if ( V_97 != V_96 )
printf ( L_36 , V_97 ) ;
printf ( L_34 ) ;
return 0 ;
}
if ( ! F_31 ( V_34 , & V_19 ) ) {
printf ( L_38 , V_34 ) ;
return 0 ;
}
V_44 = 0 ;
F_42 () ;
V_45 = V_34 ;
V_17 = 10000000 ;
while ( ! V_44 ) {
if ( -- V_17 == 0 ) {
if ( F_39 ( 0 , & V_44 ) )
break;
F_42 () ;
V_45 = F_16 () ;
printf ( L_39 , V_34 ) ;
return 0 ;
}
F_40 () ;
}
return 1 ;
#else
return 0 ;
#endif
}
static void
F_102 ( void )
{
unsigned int V_65 ;
unsigned short V_99 ;
unsigned char V_100 ;
if ( ! F_79 ( & V_101 ) )
return;
if ( ! F_79 ( & V_102 ) )
return;
V_99 = 0xffff ;
for ( V_65 = 0 ; V_65 < V_102 ; ++ V_65 ) {
if ( F_73 ( V_101 + V_65 , & V_100 , 1 ) == 0 ) {
printf ( L_40 V_103 L_34 , V_101 + V_65 ) ;
break;
}
V_99 = F_113 ( V_99 , V_100 ) ;
}
printf ( L_41 , V_99 ) ;
}
static long F_114 ( unsigned long V_6 )
{
unsigned int V_53 ;
V_6 &= ~ 3 ;
if ( ! F_115 ( V_6 ) ) {
printf ( L_42 ) ;
return 0 ;
}
if ( ! F_73 ( V_6 , & V_53 , sizeof( V_53 ) ) ) {
printf ( L_43 , V_6 ) ;
return 0 ;
}
if ( F_74 ( V_53 ) || F_54 ( V_53 ) ) {
printf ( L_44
L_45 ) ;
return 0 ;
}
return 1 ;
}
static void
F_101 ( void )
{
int V_27 ;
unsigned long V_70 ;
int V_104 , V_65 ;
struct V_28 * V_29 ;
const char V_105 [] = L_46
L_47 ;
V_27 = F_85 () ;
switch ( V_27 ) {
#ifndef F_116
case 'd' :
V_104 = 7 ;
V_27 = F_85 () ;
if ( V_27 == 'r' )
V_104 = 5 ;
else if ( V_27 == 'w' )
V_104 = 6 ;
else
V_85 = V_27 ;
V_60 . V_37 = 0 ;
V_60 . V_61 = 0 ;
if ( F_79 ( & V_60 . V_37 ) ) {
if ( ! F_115 ( V_60 . V_37 ) ) {
printf ( V_105 ) ;
break;
}
V_60 . V_37 &= ~ V_76 ;
V_60 . V_61 = V_104 | V_106 ;
}
break;
case 'i' :
if ( ! F_8 ( V_3 ) ) {
printf ( L_48
L_49 ) ;
break;
}
if ( V_62 ) {
V_62 -> V_61 &= ~ V_73 ;
V_62 = NULL ;
}
if ( ! F_79 ( & V_70 ) )
break;
if ( ! F_114 ( V_70 ) )
break;
V_29 = F_71 ( V_70 ) ;
if ( V_29 != NULL ) {
V_29 -> V_61 |= V_73 ;
V_62 = V_29 ;
}
break;
#endif
case 'c' :
if ( ! F_79 ( & V_70 ) ) {
for ( V_65 = 0 ; V_65 < V_67 ; ++ V_65 )
V_66 [ V_65 ] . V_61 = 0 ;
V_62 = NULL ;
V_60 . V_61 = 0 ;
printf ( L_50 ) ;
break;
}
if ( V_70 <= V_67 && V_70 >= 1 ) {
V_29 = & V_66 [ V_70 - 1 ] ;
} else {
V_29 = F_35 ( V_70 ) ;
if ( V_29 == NULL ) {
printf ( L_51 , V_70 ) ;
break;
}
}
printf ( L_52 , F_36 ( V_29 ) ) ;
F_37 ( V_29 -> V_37 , L_8 , L_9 ) ;
V_29 -> V_61 = 0 ;
break;
default:
V_85 = V_27 ;
V_27 = F_83 () ;
if ( V_27 == '?' ) {
printf ( V_107 ) ;
break;
}
V_85 = V_27 ;
if ( ! F_79 ( & V_70 ) ) {
printf ( L_53 ) ;
if ( V_60 . V_61 ) {
printf ( L_54 V_103 L_55 , V_60 . V_37 ) ;
if ( V_60 . V_61 & 1 )
printf ( L_56 ) ;
if ( V_60 . V_61 & 2 )
printf ( L_57 ) ;
printf ( L_58 ) ;
}
for ( V_29 = V_66 ; V_29 < & V_66 [ V_67 ] ; ++ V_29 ) {
if ( ! V_29 -> V_61 )
continue;
printf ( L_59 , F_36 ( V_29 ) ,
( V_29 -> V_61 & V_73 ) ? L_60 : L_61 ) ;
F_37 ( V_29 -> V_37 , L_62 , L_34 ) ;
}
break;
}
if ( ! F_114 ( V_70 ) )
break;
V_29 = F_71 ( V_70 ) ;
if ( V_29 != NULL )
V_29 -> V_61 |= V_72 ;
break;
}
}
static
const char * F_33 ( unsigned long V_108 )
{
char * V_109 ;
switch ( V_108 ) {
case 0x100 : V_109 = L_63 ; break;
case 0x200 : V_109 = L_64 ; break;
case 0x300 : V_109 = L_65 ; break;
case 0x380 : V_109 = L_66 ; break;
case 0x400 : V_109 = L_67 ; break;
case 0x480 : V_109 = L_68 ; break;
case 0x500 : V_109 = L_69 ; break;
case 0x600 : V_109 = L_70 ; break;
case 0x700 : V_109 = L_71 ; break;
case 0x800 : V_109 = L_72 ; break;
case 0x900 : V_109 = L_73 ; break;
case 0x980 : V_109 = L_74 ; break;
case 0xa00 : V_109 = L_75 ; break;
case 0xc00 : V_109 = L_76 ; break;
case 0xd00 : V_109 = L_77 ; break;
case 0xe40 : V_109 = L_78 ; break;
case 0xe60 : V_109 = L_79 ; break;
case 0xe80 : V_109 = L_80 ; break;
case 0xf00 : V_109 = L_81 ; break;
case 0xf20 : V_109 = L_82 ; break;
case 0x1300 : V_109 = L_83 ; break;
case 0x1500 : V_109 = L_84 ; break;
case 0x1700 : V_109 = L_85 ; break;
default: V_109 = L_86 ;
}
return V_109 ;
}
static void F_117 ( unsigned long V_64 , unsigned long * V_110 ,
unsigned long * V_111 )
{
unsigned long V_112 , V_32 ;
const char * V_113 ;
* V_110 = * V_111 = 0 ;
if ( V_64 == 0 )
return;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_113 = F_118 ( V_64 , & V_112 , & V_32 , NULL , V_115 ) ;
if ( V_113 != NULL ) {
* V_110 = V_64 - V_32 ;
* V_111 = V_64 - V_32 + V_112 ;
}
F_3 () ;
}
V_63 = 0 ;
}
static void F_81 ( unsigned long V_116 , unsigned long V_117 ,
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
printf ( L_87 , V_116 ) ;
break;
}
if ( ! F_73 ( V_116 + V_123 , & V_119 , sizeof( unsigned long ) )
|| ! F_73 ( V_116 , & V_120 , sizeof( unsigned long ) ) ) {
printf ( L_88 , V_116 ) ;
break;
}
if ( ( V_64 | V_117 ) != 0 ) {
unsigned long V_124 , V_125 ;
unsigned long V_126 ;
int V_127 = 1 ;
F_117 ( V_64 , & V_124 , & V_125 ) ;
V_126 = 0 ;
if ( V_120 > V_116 )
F_73 ( V_120 + V_123 , & V_126 ,
sizeof( unsigned long ) ) ;
if ( V_117 == V_119 ) {
if ( V_117 < V_122
|| ( V_124 <= V_117 && V_117 < V_125 ) )
V_127 = 0 ;
} else if ( V_117 == V_126 ) {
V_127 = 0 ;
} else if ( V_117 >= V_122
&& ! ( V_124 <= V_117 && V_117 < V_125 ) ) {
printf ( L_89 ) ;
F_37 ( V_117 , L_8 , L_34 ) ;
}
if ( V_127 ) {
printf ( L_90 V_103 L_91 , V_116 ) ;
F_37 ( V_119 , L_8 , L_92 ) ;
}
V_64 = V_117 = 0 ;
} else {
printf ( L_90 V_103 L_91 , V_116 ) ;
F_37 ( V_119 , L_8 , L_34 ) ;
}
if ( F_73 ( V_116 + V_128 , & V_121 , sizeof( unsigned long ) )
&& V_121 == V_129 ) {
if ( F_73 ( V_116 + V_130 , & V_21 , sizeof( V_21 ) )
!= sizeof( V_21 ) ) {
printf ( L_93 ,
V_116 + V_130 ) ;
break;
}
printf ( L_94 , V_21 . V_39 ,
F_33 ( F_34 ( & V_21 ) ) ) ;
V_64 = V_21 . V_36 ;
V_117 = V_21 . V_84 ;
F_37 ( V_64 , L_8 , L_34 ) ;
}
if ( V_120 == 0 )
break;
V_116 = V_120 ;
}
}
static void F_95 ( struct V_20 * V_56 )
{
unsigned long V_116 ;
if ( F_79 ( & V_116 ) )
F_81 ( V_116 , 0 , 0 ) ;
else
F_81 ( V_56 -> V_83 [ 1 ] , V_56 -> V_84 , V_56 -> V_36 ) ;
F_119 () ;
}
static void F_120 ( struct V_20 * V_21 )
{
#ifdef F_121
const struct V_131 * V_132 ;
unsigned long V_6 ;
if ( V_21 -> V_24 & V_48 )
return;
V_6 = V_21 -> V_36 ;
if ( V_6 < V_122 )
return;
V_132 = F_122 ( V_21 -> V_36 ) ;
if ( V_132 == NULL )
return;
if ( F_123 ( V_132 ) )
return;
#ifdef F_124
printf ( L_95 ,
V_132 -> V_133 , V_132 -> line ) ;
#else
printf ( L_96 , ( void * ) V_132 -> V_134 ) ;
#endif
#endif
}
static void F_32 ( struct V_20 * V_135 )
{
unsigned long V_39 ;
#ifdef F_25
printf ( L_97 , F_16 () ) ;
#endif
V_39 = F_34 ( V_135 ) ;
printf ( L_98 , V_135 -> V_39 , F_33 ( V_39 ) , V_135 ) ;
printf ( L_99 ) ;
F_37 ( V_135 -> V_36 , L_100 , L_34 ) ;
printf ( L_101 , V_135 -> V_84 ) ;
F_37 ( V_135 -> V_84 , L_100 , L_34 ) ;
printf ( L_102 , V_135 -> V_83 [ 1 ] ) ;
printf ( L_103 , V_135 -> V_24 ) ;
if ( V_39 == 0x300 || V_39 == 0x380 || V_39 == 0x600 || V_39 == 0x200 ) {
printf ( L_104 , V_135 -> V_136 ) ;
if ( V_39 != 0x380 )
printf ( L_105 , V_135 -> V_137 ) ;
}
printf ( L_106 , V_138 ) ;
#ifdef F_125
printf ( L_107 ,
V_139 , V_139 -> V_140 , V_139 -> V_141 ) ;
#endif
if ( V_138 ) {
printf ( L_108 ,
V_138 -> V_142 , V_138 -> V_143 ) ;
}
if ( V_39 == 0x700 )
F_120 ( V_135 ) ;
printf ( V_144 ) ;
}
static void F_93 ( struct V_20 * V_135 )
{
int V_145 , V_39 ;
unsigned long V_146 ;
struct V_20 V_21 ;
if ( F_79 ( & V_146 ) ) {
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_21 = * (struct V_20 * ) V_146 ;
F_3 () ;
F_126 ( 200 ) ;
} else {
V_63 = 0 ;
printf ( L_109 V_103 L_34 ,
V_146 ) ;
return;
}
V_63 = 0 ;
V_135 = & V_21 ;
}
#ifdef F_125
if ( F_127 ( V_135 ) ) {
for ( V_145 = 0 ; V_145 < 16 ; ++ V_145 )
printf ( L_110 V_103 L_111 V_103 L_34 ,
V_145 , V_135 -> V_83 [ V_145 ] , V_145 + 16 , V_135 -> V_83 [ V_145 + 16 ] ) ;
} else {
for ( V_145 = 0 ; V_145 < 7 ; ++ V_145 )
printf ( L_110 V_103 L_111 V_103 L_34 ,
V_145 , V_135 -> V_83 [ V_145 ] , V_145 + 7 , V_135 -> V_83 [ V_145 + 7 ] ) ;
}
#else
for ( V_145 = 0 ; V_145 < 32 ; ++ V_145 ) {
printf ( L_112 , V_145 , V_135 -> V_83 [ V_145 ] ,
( V_145 & 3 ) == 3 ? L_34 : L_113 ) ;
if ( V_145 == 12 && ! F_127 ( V_135 ) ) {
printf ( L_34 ) ;
break;
}
}
#endif
printf ( L_114 ) ;
F_37 ( V_135 -> V_36 , L_8 , L_34 ) ;
if ( F_34 ( V_135 ) != 0xc00 && F_8 ( V_147 ) ) {
printf ( L_115 ) ;
F_37 ( V_135 -> V_148 , L_8 , L_34 ) ;
}
printf ( L_116 ) ;
F_37 ( V_135 -> V_84 , L_8 , L_34 ) ;
printf ( L_117 V_103 L_118 , V_135 -> V_24 , V_135 -> V_149 ) ;
printf ( L_119 V_103 L_120 V_103 L_121 ,
V_135 -> V_150 , V_135 -> V_151 , V_135 -> V_39 ) ;
V_39 = F_34 ( V_135 ) ;
if ( V_39 == 0x300 || V_39 == 0x380 || V_39 == 0x600 )
printf ( L_122 V_103 L_123 , V_135 -> V_136 , V_135 -> V_137 ) ;
}
static void F_96 ( void )
{
int V_27 ;
unsigned long V_152 ;
V_27 = F_85 () ;
if ( V_27 != 'i' )
V_85 = V_27 ;
F_79 ( ( void * ) & V_101 ) ;
if ( V_85 != '\n' )
V_85 = 0 ;
V_152 = 1 ;
F_79 ( & V_152 ) ;
V_152 = ( V_152 + V_153 - 1 ) / V_153 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
if ( V_27 != 'i' ) {
for (; V_152 > 0 ; -- V_152 , V_101 += V_153 )
F_5 ( ( void * ) V_101 ) ;
} else {
for (; V_152 > 0 ; -- V_152 , V_101 += V_153 )
F_6 ( ( void * ) V_101 ) ;
}
F_3 () ;
F_126 ( 200 ) ;
}
V_63 = 0 ;
}
static unsigned long
F_128 ( int V_145 )
{
unsigned int V_154 [ 2 ] ;
unsigned long ( * V_155 ) ( void ) ;
unsigned long V_109 = - 1UL ;
#ifdef F_125
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
F_4 ( V_154 ) ;
F_4 ( V_154 + 1 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_109 = V_155 () ;
F_3 () ;
F_126 ( 200 ) ;
V_145 = V_112 ;
}
return V_109 ;
}
static void
F_129 ( int V_145 , unsigned long V_157 )
{
unsigned int V_154 [ 2 ] ;
unsigned long ( * V_155 ) ( unsigned long ) ;
#ifdef F_125
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
F_4 ( V_154 ) ;
F_4 ( V_154 + 1 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_155 ( V_157 ) ;
F_3 () ;
F_126 ( 200 ) ;
V_145 = V_112 ;
}
}
static void F_94 ( void )
{
int V_27 ;
unsigned long V_157 ;
V_27 = F_83 () ;
if ( V_27 == '\n' ) {
unsigned long V_116 , V_158 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_124 V_103 L_125 V_103 L_34 ,
F_130 () , F_111 ( V_159 ) ) ;
printf ( L_126 V_103 L_127 V_103 L_34 ,
F_111 ( V_160 ) , F_111 ( V_161 ) ) ;
printf ( L_128 V_103 L_129 V_103 L_34 ,
F_111 ( V_162 ) , F_111 ( V_163 ) ) ;
printf ( L_130 V_103 L_131 V_103 L_34 , V_116 , F_111 ( V_164 ) ) ;
printf ( L_132 V_103 L_133 V_103 L_34 , V_158 , F_111 ( V_165 ) ) ;
return;
}
F_79 ( & V_166 ) ;
switch ( V_27 ) {
case 'w' :
V_157 = F_128 ( V_166 ) ;
F_79 ( & V_157 ) ;
F_129 ( V_166 , V_157 ) ;
case 'r' :
printf ( L_134 , V_166 , F_128 ( V_166 ) ) ;
break;
}
F_119 () ;
}
static int
F_73 ( unsigned long V_101 , void * V_167 , int V_112 )
{
volatile int V_145 ;
char * V_2 , * V_168 ;
V_145 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
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
F_3 () ;
}
}
F_3 () ;
F_126 ( 200 ) ;
V_145 = V_112 ;
}
V_63 = 0 ;
return V_145 ;
}
static int
F_75 ( unsigned long V_101 , void * V_167 , int V_112 )
{
volatile int V_145 ;
char * V_2 , * V_168 ;
V_145 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
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
F_3 () ;
}
}
F_3 () ;
F_126 ( 200 ) ;
V_145 = V_112 ;
} else {
printf ( L_135 V_103 L_34 , V_101 + V_145 ) ;
}
V_63 = 0 ;
return V_145 ;
}
static int F_69 ( struct V_20 * V_21 )
{
V_172 = F_34 ( V_21 ) ;
switch ( F_34 ( V_21 ) ) {
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
F_131 ( unsigned char * V_157 , int V_112 )
{
int V_174 ;
switch ( V_112 ) {
case 2 :
F_132 ( V_157 [ 0 ] , V_157 [ 1 ] , V_174 ) ;
break;
case 4 :
F_132 ( V_157 [ 0 ] , V_157 [ 3 ] , V_174 ) ;
F_132 ( V_157 [ 1 ] , V_157 [ 2 ] , V_174 ) ;
break;
case 8 :
F_132 ( V_157 [ 0 ] , V_157 [ 7 ] , V_174 ) ;
F_132 ( V_157 [ 1 ] , V_157 [ 6 ] , V_174 ) ;
F_132 ( V_157 [ 2 ] , V_157 [ 5 ] , V_174 ) ;
F_132 ( V_157 [ 3 ] , V_157 [ 4 ] , V_174 ) ;
break;
}
}
static void
F_90 ( void )
{
int V_27 , V_175 , V_65 , V_176 ;
unsigned long V_145 ;
unsigned char V_157 [ 16 ] ;
F_79 ( ( void * ) & V_101 ) ;
V_27 = F_83 () ;
if ( V_27 == '?' ) {
printf ( V_177 ) ;
return;
} else {
V_85 = V_27 ;
}
V_80 = L_136 ;
while ( ( V_27 = F_83 () ) != '\n' ) {
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
V_145 = F_73 ( V_101 , V_157 , V_112 ) ;
printf ( V_103 L_137 , V_101 , V_178 ? 'r' : ' ' ) ;
if ( ! V_179 ) {
if ( V_178 )
F_131 ( V_157 , V_112 ) ;
putchar ( ' ' ) ;
for ( V_65 = 0 ; V_65 < V_145 ; ++ V_65 )
printf ( L_138 , V_157 [ V_65 ] ) ;
for (; V_65 < V_112 ; ++ V_65 )
printf ( L_139 , V_180 [ V_173 ] ) ;
}
putchar ( ' ' ) ;
V_175 = V_112 ;
V_176 = 0 ;
for(; ; ) {
if( F_79 ( & V_145 ) ) {
for ( V_65 = 0 ; V_65 < V_112 ; ++ V_65 )
V_157 [ V_65 ] = V_145 >> ( V_65 * 8 ) ;
if ( ! V_178 )
F_131 ( V_157 , V_112 ) ;
F_75 ( V_101 , V_157 , V_112 ) ;
V_175 = V_112 ;
}
V_27 = F_83 () ;
if ( V_27 == '\n' )
break;
V_175 = 0 ;
switch ( V_27 ) {
case '\'' :
for(; ; ) {
V_145 = F_85 () ;
if( V_145 == '\\' )
V_145 = F_133 () ;
else if( V_145 == '\'' )
break;
for ( V_65 = 0 ; V_65 < V_112 ; ++ V_65 )
V_157 [ V_65 ] = V_145 >> ( V_65 * 8 ) ;
if ( ! V_178 )
F_131 ( V_157 , V_112 ) ;
F_75 ( V_101 , V_157 , V_112 ) ;
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
F_119 () ;
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
F_79 ( ( void * ) & V_101 ) ;
break;
case 'n' :
V_179 = 1 ;
break;
case 'r' :
V_178 = ! V_178 ;
break;
case '<' :
V_145 = V_112 ;
F_79 ( & V_145 ) ;
V_101 -= V_145 ;
break;
case '>' :
V_145 = V_112 ;
F_79 ( & V_145 ) ;
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
F_133 ( void )
{
int V_182 ;
V_182 = F_85 () ;
switch( V_182 ) {
case 'n' : V_182 = '\n' ; break;
case 'r' : V_182 = '\r' ; break;
case 'b' : V_182 = '\b' ; break;
case 't' : V_182 = '\t' ; break;
}
return V_182 ;
}
static void F_134 ( unsigned long V_101 , long V_183 )
{
long V_145 , V_184 , V_185 , V_186 ;
unsigned char V_187 [ 16 ] ;
for ( V_145 = V_183 ; V_145 > 0 ; ) {
V_185 = V_145 < 16 ? V_145 : 16 ;
V_186 = F_73 ( V_101 , V_187 , V_185 ) ;
V_101 += V_186 ;
for ( V_184 = 0 ; V_184 < V_185 ; ++ V_184 ) {
if ( V_184 < V_186 )
printf ( L_138 , V_187 [ V_184 ] ) ;
else
printf ( L_139 , V_180 [ V_173 ] ) ;
}
V_145 -= V_185 ;
if ( V_186 < V_185 )
break;
}
printf ( L_34 ) ;
}
static void F_135 ( int V_34 )
{
struct V_188 * V_2 ;
#ifdef F_136
int V_65 = 0 ;
#endif
if ( setjmp ( V_114 ) != 0 ) {
printf ( L_140 , V_34 ) ;
return;
}
V_63 = 1 ;
F_3 () ;
V_2 = & V_189 [ V_34 ] ;
printf ( L_141 , V_34 , V_2 ) ;
printf ( L_142 , 20 , L_143 , F_137 ( V_34 ) ? L_144 : L_145 ) ;
printf ( L_142 , 20 , L_146 , F_138 ( V_34 ) ? L_144 : L_145 ) ;
printf ( L_142 , 20 , L_147 , F_139 ( V_34 ) ? L_144 : L_145 ) ;
#define F_140 ( V_189 , V_113 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 20, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_140 ( V_2 , V_190 , L_148 ) ;
F_140 ( V_2 , V_191 , L_148 ) ;
F_140 ( V_2 , V_192 , L_149 ) ;
F_140 ( V_2 , V_193 , L_149 ) ;
F_140 ( V_2 , V_194 , L_149 ) ;
F_140 ( V_2 , V_195 , L_150 ) ;
#ifdef F_141
F_140 ( V_2 , V_196 , L_150 ) ;
F_140 ( V_2 , V_197 , L_148 ) ;
F_140 ( V_2 , V_198 , L_148 ) ;
#endif
F_140 ( V_2 , V_199 , L_149 ) ;
F_140 ( V_2 , V_200 , L_148 ) ;
F_140 ( V_2 , V_201 , L_148 ) ;
F_140 ( V_2 , V_202 , L_148 ) ;
#ifdef F_136
for ( V_65 = 0 ; V_65 < V_203 ; V_65 ++ ) {
V_171 V_204 , V_205 ;
if ( ! V_2 -> V_206 )
continue;
V_204 = F_142 ( V_2 -> V_206 -> V_207 [ V_65 ] . V_204 ) ;
V_205 = F_142 ( V_2 -> V_206 -> V_207 [ V_65 ] . V_205 ) ;
if ( V_204 || V_205 ) {
printf ( L_151 ,
V_65 , V_204 , V_205 ) ;
}
}
F_140 ( V_2 , V_208 , L_148 ) ;
F_140 ( V_2 , V_209 , L_148 ) ;
for ( V_65 = 0 ; V_65 < V_210 ; V_65 ++ )
printf ( L_152 , V_65 , V_2 -> V_211 [ V_65 ] ) ;
#endif
F_140 ( V_2 , V_212 , L_153 ) ;
#ifdef V_23
F_140 ( V_2 , V_213 , L_150 ) ;
F_140 ( V_2 , V_214 , L_150 ) ;
F_140 ( V_2 , V_215 , L_150 ) ;
F_140 ( V_2 , V_216 , L_150 ) ;
F_140 ( V_2 , V_217 , L_150 ) ;
F_140 ( V_2 , V_218 , L_150 ) ;
#endif
F_140 ( V_2 , V_219 , L_150 ) ;
F_140 ( V_2 , V_220 , L_149 ) ;
F_140 ( V_2 , V_221 , L_149 ) ;
F_140 ( V_2 , V_222 , L_149 ) ;
F_140 ( V_2 , V_223 , L_148 ) ;
F_140 ( V_2 , V_140 , L_148 ) ;
F_140 ( V_2 , V_141 , L_148 ) ;
F_140 ( V_2 , V_224 , L_148 ) ;
F_140 ( V_2 , V_225 , L_148 ) ;
F_140 ( V_2 , V_226 , L_148 ) ;
F_140 ( V_2 , V_227 , L_153 ) ;
#ifdef F_143
F_140 ( V_2 , V_228 , L_153 ) ;
#endif
#ifdef F_144
F_140 ( V_2 , V_229 , L_150 ) ;
F_140 ( V_2 , V_230 , L_148 ) ;
F_140 ( V_2 , V_231 , L_148 ) ;
F_140 ( V_2 , V_232 , L_148 ) ;
#endif
F_140 ( V_2 , V_233 , L_153 ) ;
F_140 ( V_2 , V_234 , L_153 ) ;
F_140 ( V_2 , V_235 , L_153 ) ;
F_140 ( V_2 , V_236 , L_153 ) ;
F_140 ( V_2 , V_237 , L_153 ) ;
F_140 ( V_2 , V_238 , L_153 ) ;
F_140 ( V_2 , V_239 , L_153 ) ;
F_140 ( V_2 , V_240 , L_153 ) ;
#undef F_140
V_63 = 0 ;
F_3 () ;
}
static void F_145 ( void )
{
int V_34 ;
if ( F_146 () == 0 ) {
printf ( L_154 ) ;
return;
}
F_112 (cpu)
F_135 ( V_34 ) ;
}
static void F_147 ( void )
{
unsigned long V_241 ;
int V_182 ;
V_182 = F_85 () ;
if ( V_182 == 'a' ) {
F_145 () ;
return;
}
V_85 = V_182 ;
if ( F_79 ( & V_241 ) )
F_135 ( V_241 ) ;
else
F_135 ( V_45 ) ;
}
static void
F_91 ( void )
{
int V_182 ;
V_182 = F_85 () ;
#ifdef F_125
if ( V_182 == 'p' ) {
F_148 () ;
F_147 () ;
F_149 () ;
return;
}
#endif
if ( ( isxdigit ( V_182 ) && V_182 != 'f' && V_182 != 'd' ) || V_182 == '\n' )
V_85 = V_182 ;
F_79 ( ( void * ) & V_101 ) ;
if ( V_85 != '\n' )
V_85 = 0 ;
if ( V_182 == 'i' ) {
F_79 ( & V_242 ) ;
if ( V_242 == 0 )
V_242 = 16 ;
else if ( V_242 > V_243 )
V_242 = V_243 ;
V_101 += F_46 ( V_101 , V_242 , 1 ) ;
V_80 = L_155 ;
} else if ( V_182 == 'l' ) {
F_150 () ;
} else if ( V_182 == 'o' ) {
F_2 () ;
} else if ( V_182 == 'r' ) {
F_79 ( & V_183 ) ;
if ( V_183 == 0 )
V_183 = 64 ;
F_134 ( V_101 , V_183 ) ;
V_101 += V_183 ;
V_80 = L_156 ;
} else {
F_79 ( & V_183 ) ;
if ( V_183 == 0 )
V_183 = 64 ;
else if ( V_183 > V_243 )
V_183 = V_243 ;
F_151 ( V_101 , V_183 ) ;
V_101 += V_183 ;
V_80 = L_157 ;
}
}
static void
F_151 ( unsigned long V_101 , long V_183 )
{
long V_145 , V_184 , V_182 , V_185 , V_186 ;
unsigned char V_187 [ 16 ] ;
for ( V_145 = V_183 ; V_145 > 0 ; ) {
printf ( V_103 , V_101 ) ;
putchar ( ' ' ) ;
V_185 = V_145 < 16 ? V_145 : 16 ;
V_186 = F_73 ( V_101 , V_187 , V_185 ) ;
V_101 += V_186 ;
for ( V_184 = 0 ; V_184 < V_185 ; ++ V_184 ) {
if ( ( V_184 & ( sizeof( long ) - 1 ) ) == 0 && V_184 > 0 )
putchar ( ' ' ) ;
if ( V_184 < V_186 )
printf ( L_138 , V_187 [ V_184 ] ) ;
else
printf ( L_139 , V_180 [ V_173 ] ) ;
}
for (; V_184 < 16 ; ++ V_184 ) {
if ( ( V_184 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_62 ) ;
}
printf ( L_158 ) ;
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
printf ( L_159 ) ;
if ( V_186 < V_185 )
break;
}
}
static int
F_152 ( unsigned long V_244 , long V_245 , int V_246 ,
T_3 V_247 )
{
int V_186 , V_248 ;
unsigned long V_249 ;
unsigned long V_250 , V_251 = 0 ;
unsigned char V_157 [ 4 ] ;
V_248 = 0 ;
for ( V_249 = V_244 ; V_245 > 0 ; -- V_245 , V_244 += 4 ) {
V_186 = F_73 ( V_244 , V_157 , 4 ) ;
if ( V_186 == 0 ) {
if ( V_246 ) {
const char * V_252 = V_180 [ V_173 ] ;
printf ( V_103 L_160 , V_244 , V_252 , V_252 , V_252 , V_252 ) ;
}
break;
}
V_250 = F_153 ( V_157 ) ;
if ( V_244 > V_249 && V_250 == V_251 ) {
if ( ! V_248 ) {
printf ( L_161 ) ;
V_248 = 1 ;
}
continue;
}
V_248 = 0 ;
V_251 = V_250 ;
if ( V_246 )
printf ( V_103 L_162 , V_244 , V_250 ) ;
printf ( L_163 ) ;
V_247 ( V_250 , V_244 ) ;
printf ( L_34 ) ;
}
return V_244 - V_249 ;
}
static int
F_46 ( unsigned long V_244 , long V_245 , int V_246 )
{
return F_152 ( V_244 , V_245 , V_246 , V_253 ) ;
}
void
F_154 ( unsigned long V_6 )
{
F_37 ( V_6 , L_164 , L_86 ) ;
}
void
F_150 ( void )
{
struct V_254 V_255 = { . V_256 = 1 } ;
unsigned char V_167 [ 128 ] ;
T_4 V_78 ;
if ( setjmp ( V_114 ) != 0 ) {
printf ( L_165 ) ;
return;
}
V_63 = 1 ;
F_3 () ;
F_155 ( & V_255 ) ;
F_148 () ;
while ( F_156 ( & V_255 , false , V_167 , sizeof( V_167 ) , & V_78 ) ) {
V_167 [ V_78 ] = '\0' ;
printf ( L_139 , V_167 ) ;
}
F_149 () ;
F_3 () ;
F_126 ( 200 ) ;
V_63 = 0 ;
}
static void F_2 ( void )
{
unsigned char V_167 [ 128 ] ;
T_5 V_257 ;
T_6 V_258 = 0 ;
if ( ! F_157 ( V_259 ) ) {
printf ( L_1 ) ;
return;
}
if ( setjmp ( V_114 ) != 0 ) {
printf ( L_166 ) ;
return;
}
V_63 = 1 ;
F_3 () ;
F_148 () ;
while ( ( V_257 = F_158 ( V_167 , V_258 , sizeof( V_167 ) - 1 ) ) ) {
if ( V_257 < 0 ) {
printf ( L_167 , V_257 ) ;
break;
}
V_167 [ V_257 ] = '\0' ;
printf ( L_139 , V_167 ) ;
V_258 += V_257 ;
}
F_149 () ;
F_3 () ;
F_126 ( 200 ) ;
V_63 = 0 ;
}
static void
F_86 ( int V_27 )
{
F_79 ( ( void * ) & V_260 ) ;
if( V_85 != '\n' )
V_85 = 0 ;
F_79 ( ( void * ) ( V_27 == 's' ? & V_261 : & V_262 ) ) ;
if( V_85 != '\n' )
V_85 = 0 ;
F_79 ( ( void * ) & V_263 ) ;
switch( V_27 ) {
case 'm' :
memmove ( ( void * ) V_260 , ( void * ) V_262 , V_263 ) ;
break;
case 's' :
memset ( ( void * ) V_260 , V_261 , V_263 ) ;
break;
case 'd' :
if( V_85 != '\n' )
V_85 = 0 ;
F_79 ( ( void * ) & V_264 ) ;
F_159 ( ( unsigned char * ) V_260 , ( unsigned char * ) V_262 , V_263 , V_264 ) ;
break;
}
}
static void
F_159 ( unsigned char * V_265 , unsigned char * V_266 , unsigned V_267 , unsigned V_268 )
{
unsigned V_145 , V_269 ;
V_269 = 0 ;
for( V_145 = V_267 ; V_145 > 0 ; -- V_145 )
if( * V_265 ++ != * V_266 ++ )
if( ++ V_269 <= V_268 )
printf ( L_168 , V_265 - 1 ,
V_265 [ - 1 ] , V_266 - 1 , V_266 [ - 1 ] ) ;
if( V_269 > V_268 )
printf ( L_169 , V_269 ) ;
}
static void
F_87 ( void )
{
unsigned V_70 , V_145 ;
unsigned char V_157 [ 4 ] ;
V_80 = L_170 ;
F_79 ( ( void * ) & V_260 ) ;
if ( V_85 != '\n' ) {
V_85 = 0 ;
F_79 ( ( void * ) & V_270 ) ;
if ( V_85 != '\n' ) {
V_85 = 0 ;
F_79 ( ( void * ) & V_261 ) ;
V_271 = ~ 0 ;
if ( V_85 != '\n' ) V_85 = 0 ;
F_79 ( ( void * ) & V_271 ) ;
}
}
V_145 = 0 ;
for ( V_70 = V_260 ; V_70 < V_270 ; V_70 += 4 ) {
if ( F_73 ( V_70 , V_157 , 4 ) == 4
&& ( ( F_153 ( V_157 ) ^ V_261 ) & V_271 ) == 0 ) {
printf ( L_171 , V_70 , F_153 ( V_157 ) ) ;
if ( ++ V_145 >= 10 )
break;
}
}
}
static void
F_88 ( void )
{
unsigned char V_100 ;
unsigned V_70 ;
int V_272 , V_273 ;
F_79 ( & V_260 ) ;
if ( V_85 != '\n' ) V_85 = 0 ;
F_79 ( & V_274 ) ;
if ( V_85 != '\n' ) V_85 = 0 ;
F_79 ( & V_275 ) ;
V_273 = 0 ;
for ( V_70 = V_260 ; V_70 < V_275 ; V_70 += V_274 ) {
V_272 = F_73 ( V_70 , & V_100 , 1 ) ;
if ( V_272 && ! V_273 ) {
printf ( L_172 , V_70 ) ;
} else if ( ! V_272 && V_273 )
printf ( L_173 , V_70 - V_274 ) ;
V_273 = V_272 ;
if ( V_70 + V_274 < V_70 )
break;
}
if ( V_273 )
printf ( L_173 , V_70 - V_274 ) ;
}
static void F_160 ( struct V_276 * V_277 )
{
char V_278 ;
V_278 = ( V_277 -> V_278 == 0 ) ? 'R' :
( V_277 -> V_278 < 0 ) ? 'U' :
( V_277 -> V_278 & V_279 ) ? 'D' :
( V_277 -> V_278 & V_280 ) ? 'T' :
( V_277 -> V_278 & V_281 ) ? 'C' :
( V_277 -> V_282 & V_283 ) ? 'Z' :
( V_277 -> V_282 & V_284 ) ? 'E' :
( V_277 -> V_278 & V_285 ) ? 'S' : '?' ;
printf ( L_174 , V_277 ,
V_277 -> V_286 . V_287 ,
V_277 -> V_142 , V_277 -> V_288 -> V_142 ,
V_278 , F_161 ( V_277 ) -> V_34 ,
V_277 -> V_143 ) ;
}
static void F_106 ( void )
{
unsigned long V_289 ;
struct V_276 * V_277 = NULL ;
printf ( L_175 ) ;
if ( F_79 ( & V_289 ) )
V_277 = (struct V_276 * ) V_289 ;
if ( setjmp ( V_114 ) != 0 ) {
V_63 = 0 ;
printf ( L_176 , V_277 ) ;
return;
}
V_63 = 1 ;
F_3 () ;
if ( V_277 )
F_160 ( V_277 ) ;
else
F_162 (tsk)
F_160 ( V_277 ) ;
F_3 () ;
F_126 ( 200 ) ;
V_63 = 0 ;
}
static void F_105 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_109 ;
int V_65 ;
typedef unsigned long (* T_7)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_7 V_290 ;
if ( ! F_79 ( & V_101 ) )
return;
if ( V_85 != '\n' )
V_85 = 0 ;
for ( V_65 = 0 ; V_65 < 8 ; ++ V_65 )
args [ V_65 ] = 0 ;
for ( V_65 = 0 ; V_65 < 8 ; ++ V_65 ) {
if ( ! F_79 ( & args [ V_65 ] ) || V_85 == '\n' )
break;
V_85 = 0 ;
}
V_290 = ( T_7 ) V_101 ;
V_109 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_109 = V_290 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_3 () ;
printf ( L_177 , V_109 ) ;
} else {
printf ( L_178 , V_172 ) ;
}
V_63 = 0 ;
}
int
F_83 ( void )
{
int V_182 ;
if( V_85 != 0 ) {
V_182 = V_85 ;
V_85 = 0 ;
} else
V_182 = F_85 () ;
while( V_182 == ' ' || V_182 == '\t' )
V_182 = F_85 () ;
return V_182 ;
}
int
F_79 ( unsigned long * V_291 )
{
int V_182 , V_58 ;
unsigned long V_100 ;
V_182 = F_83 () ;
if ( V_182 == '%' ) {
char V_292 [ 8 ] ;
int V_65 ;
for ( V_65 = 0 ; V_65 < sizeof( V_292 ) - 1 ; ++ V_65 ) {
V_182 = F_85 () ;
if ( ! isalnum ( V_182 ) ) {
V_85 = V_182 ;
break;
}
V_292 [ V_65 ] = V_182 ;
}
V_292 [ V_65 ] = 0 ;
for ( V_65 = 0 ; V_65 < V_293 ; ++ V_65 ) {
if ( strcmp ( V_294 [ V_65 ] , V_292 ) == 0 ) {
if ( V_81 == NULL ) {
printf ( L_179 ) ;
return 0 ;
}
* V_291 = ( ( unsigned long * ) V_81 ) [ V_65 ] ;
return 1 ;
}
}
printf ( L_180 , V_292 ) ;
return 0 ;
}
if ( V_182 == '0' ) {
V_182 = F_85 () ;
if ( V_182 == 'x' ) {
V_182 = F_85 () ;
} else {
V_58 = F_163 ( V_182 ) ;
if ( V_58 == V_55 ) {
V_85 = V_182 ;
* V_291 = 0 ;
return 1 ;
}
}
} else if ( V_182 == '$' ) {
int V_65 ;
for ( V_65 = 0 ; V_65 < 63 ; V_65 ++ ) {
V_182 = F_85 () ;
if ( isspace ( V_182 ) || V_182 == '\0' ) {
V_85 = V_182 ;
break;
}
V_115 [ V_65 ] = V_182 ;
}
V_115 [ V_65 ++ ] = 0 ;
* V_291 = 0 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
* V_291 = F_164 ( V_115 ) ;
F_3 () ;
}
V_63 = 0 ;
if ( ! ( * V_291 ) ) {
printf ( L_181 , V_115 ) ;
return 0 ;
}
return 1 ;
}
V_58 = F_163 ( V_182 ) ;
if ( V_58 == V_55 ) {
V_85 = V_182 ;
return 0 ;
}
V_100 = 0 ;
do {
V_100 = ( V_100 << 4 ) + V_58 ;
V_182 = F_85 () ;
V_58 = F_163 ( V_182 ) ;
} while ( V_58 != V_55 );
V_85 = V_182 ;
* V_291 = V_100 ;
return 1 ;
}
static void
F_119 ( void )
{
int V_182 ;
V_182 = V_85 ;
V_85 = 0 ;
while( V_182 != '\n' )
V_182 = F_85 () ;
}
static int F_163 ( int V_182 )
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
F_165 ( char * V_295 , int V_112 )
{
int V_182 ;
V_182 = F_83 () ;
do {
if( V_112 > 1 ) {
* V_295 ++ = V_182 ;
-- V_112 ;
}
V_182 = F_85 () ;
} while( V_182 != ' ' && V_182 != '\t' && V_182 != '\n' );
V_85 = V_182 ;
* V_295 = 0 ;
}
static void
F_82 ( void )
{
V_296 = NULL ;
}
static int
F_85 ( void )
{
if ( V_296 == NULL || * V_296 == 0 ) {
if ( F_166 ( line , sizeof( line ) ) == NULL ) {
V_296 = NULL ;
return V_55 ;
}
V_296 = line ;
}
return * V_296 ++ ;
}
static void
F_84 ( char * V_297 )
{
V_296 = V_297 ;
}
static void
F_92 ( void )
{
int type = F_85 () ;
unsigned long V_6 ;
static char V_298 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_79 ( & V_6 ) )
F_37 ( V_6 , L_100 , L_34 ) ;
V_85 = 0 ;
break;
case 's' :
F_165 ( V_298 , 64 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_6 = F_164 ( V_298 ) ;
if ( V_6 )
printf ( L_182 , V_298 , V_6 ) ;
else
printf ( L_183 , V_298 ) ;
F_3 () ;
}
V_63 = 0 ;
V_85 = 0 ;
break;
}
}
static void F_37 ( unsigned long V_37 , const char * V_299 ,
const char * V_300 )
{
char * V_301 ;
const char * V_113 = NULL ;
unsigned long V_32 , V_112 ;
printf ( V_103 , V_37 ) ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_113 = F_118 ( V_37 , & V_112 , & V_32 , & V_301 ,
V_115 ) ;
F_3 () ;
F_126 ( 200 ) ;
}
V_63 = 0 ;
if ( V_113 ) {
printf ( L_184 , V_299 , V_113 , V_32 , V_112 ) ;
if ( V_301 )
printf ( L_185 , V_301 ) ;
}
printf ( L_139 , V_300 ) ;
}
void F_108 ( void )
{
int V_65 ;
unsigned long V_204 , V_205 ;
unsigned long V_302 ;
printf ( L_186 , F_16 () ) ;
for ( V_65 = 0 ; V_65 < V_303 ; V_65 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( V_204 || V_205 ) {
printf ( L_187 , V_65 , V_204 , V_205 ) ;
if ( V_204 & V_304 ) {
V_302 = V_205 & V_305 ;
if ( V_205 & V_306 ) {
printf ( L_188 ,
F_167 ( V_204 ) ,
( V_205 & ~ V_307 ) >> V_308 ,
V_302 ) ;
} else {
printf ( L_189 ,
F_168 ( V_204 ) ,
( V_205 & ~ V_307 ) >> V_309 ,
V_302 ) ;
}
} else
printf ( L_34 ) ;
}
}
}
void F_108 ( void )
{
int V_65 ;
printf ( L_190 ) ;
for ( V_65 = 0 ; V_65 < 16 ; ++ V_65 )
printf ( L_191 , F_169 ( V_65 ) ) ;
printf ( L_34 ) ;
}
static void F_109 ( void )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_310 ; V_65 ++ ) {
unsigned long V_311 , V_312 , V_313 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_192 , V_65 , V_311 , V_312 , V_313 ) ;
if ( V_311 & V_314 ) {
printf ( L_193 ,
V_311 & V_315 ,
V_312 & V_316 ,
V_312 & V_317 ,
( V_313 & V_318 ) ? 'W' : 'w' ,
( V_313 & V_319 ) ? 'I' : 'i' ,
( V_313 & V_320 ) ? 'M' : 'm' ,
( V_313 & V_321 ) ? 'G' : 'g' ,
( V_313 & V_322 ) ? 'E' : 'e' ) ;
}
printf ( L_34 ) ;
}
}
static void F_110 ( void )
{
V_170 V_323 , V_324 , V_325 ;
V_171 V_326 ;
int V_65 , V_327 , V_328 , V_329 , V_330 , V_331 , V_332 = 0 ;
int V_333 ;
static const char * V_334 [] = {
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
L_220 ,
L_221 ,
L_222 ,
L_223 ,
L_224 ,
L_225 ,
} ;
V_323 = F_111 ( V_335 ) ;
V_333 = ( V_323 & 3 ) + 1 ;
V_328 = ( ( V_323 >> 2 ) & 3 ) + 1 ;
V_329 = ( ( V_323 >> 6 ) & 0x1f ) + 1 ;
V_330 = ( V_323 >> 24 ) & 0xf ;
V_331 = ( V_323 >> 16 ) & 0x7f ;
if ( ( V_333 > 1 ) && ( V_323 & 0x10000 ) )
V_332 = 1 ;
printf ( L_226 ,
V_333 , V_328 , V_329 , V_330 , V_331 ) ;
V_324 = ( 1ul << V_329 ) - 1 ;
V_325 = ( 1ul << V_330 ) - 1 ;
V_326 = ( 1ull << V_331 ) - 1 ;
for ( V_327 = 0 ; V_327 < V_328 ; V_327 ++ ) {
V_170 V_336 ;
int V_337 , V_338 , V_339 = 1 ;
printf ( L_227 , V_327 ) ;
switch( V_327 ) {
case 0 :
V_336 = F_111 ( V_340 ) ;
break;
case 1 :
V_336 = F_111 ( V_341 ) ;
break;
case 2 :
V_336 = F_111 ( V_342 ) ;
break;
case 3 :
V_336 = F_111 ( V_343 ) ;
break;
default:
printf ( L_228 ) ;
continue;
}
V_337 = V_336 & 0xfff ;
V_338 = ( V_336 >> 24 ) & 0xff ;
for ( V_65 = 0 ; V_65 < V_337 ; V_65 ++ ) {
V_170 V_344 = F_170 ( V_327 ) ;
V_170 V_345 = F_171 ( V_346 ) ;
V_171 V_347 = 0 ;
V_171 V_348 ;
int V_349 = V_65 , V_350 = V_65 ;
if ( V_338 != 0 ) {
V_350 = V_65 / V_338 ;
V_349 = V_65 % V_338 ;
V_347 = V_350 * 0x1000 ;
}
V_344 |= F_172 ( V_349 ) ;
F_9 ( V_351 , V_344 ) ;
F_9 ( V_352 , V_345 ) ;
F_9 ( V_353 , V_347 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_345 = F_111 ( V_352 ) ;
V_347 = F_111 ( V_353 ) ;
V_348 = F_111 ( V_354 ) ;
if ( V_338 && ( V_65 % V_338 ) == 0 )
V_339 = 1 ;
if ( ! ( V_345 & V_355 ) )
continue;
if ( V_338 == 0 )
printf ( L_229 , V_65 ) ;
else if ( V_339 )
printf ( L_230 , V_350 , 'A' + V_349 ) ;
else
printf ( L_231 , 'A' + V_349 ) ;
V_339 = 0 ;
printf ( L_232 ,
V_347 & ~ 0x3ffull ,
( V_345 >> 16 ) & 0x3fff ,
V_334 [ ( V_345 >> 7 ) & 0x1f ] ,
V_345 & V_356 ? 'I' : ' ' ,
V_345 & V_357 ? 'P' : ' ' ,
V_345 & V_358 ? '1' : '0' ) ;
printf ( L_233 ,
V_347 & V_359 ? 'a' : ' ' ,
V_347 & V_360 ? 'v' : ' ' ,
V_347 & V_361 ? 'w' : ' ' ,
V_347 & V_362 ? 'i' : ' ' ,
V_347 & V_363 ? 'm' : ' ' ,
V_347 & V_364 ? 'g' : ' ' ,
V_347 & V_365 ? 'e' : ' ' ) ;
printf ( L_234 , V_348 & V_326 & ~ 0x7ffull ) ;
if ( V_345 & V_356 )
printf ( L_235 ,
V_334 [ ( V_348 >> 1 ) & 0x1f ] ) ;
else
printf ( L_236 ,
V_348 & V_366 ? 'x' : ' ' ,
V_348 & V_367 ? 'w' : ' ' ,
V_348 & V_368 ? 'r' : ' ' ,
V_348 & V_369 ? 'x' : ' ' ,
V_348 & V_370 ? 'w' : ' ' ,
V_348 & V_371 ? 'r' : ' ' ) ;
}
}
}
static void F_173 ( int V_372 )
{
if ( V_372 ) {
V_373 = F_58 ;
V_374 = F_67 ;
V_375 = F_62 ;
V_376 = F_63 ;
V_377 = F_66 ;
V_378 = F_65 ;
V_379 = F_68 ;
} else {
V_373 = NULL ;
V_374 = NULL ;
V_375 = NULL ;
V_376 = NULL ;
V_377 = NULL ;
V_378 = NULL ;
V_379 = NULL ;
}
}
static void F_174 ( int V_380 )
{
F_173 ( 1 ) ;
F_175 ( F_61 () ) ;
}
static int T_8 F_176 ( void )
{
F_177 ( 'x' , & V_381 ) ;
return 0 ;
}
static int T_8 F_178 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_237 , 5 ) == 0 ) {
F_173 ( 1 ) ;
V_382 = 1 ;
} else if ( strncmp ( V_2 , L_238 , 2 ) == 0 )
F_173 ( 1 ) ;
else if ( strncmp ( V_2 , L_239 , 3 ) == 0 )
V_383 = 1 ;
else if ( strncmp ( V_2 , L_240 , 4 ) == 0 )
V_82 = 1 ;
else
return 1 ;
return 0 ;
}
void T_8 F_179 ( void )
{
#ifdef F_180
if ( ! V_383 )
F_173 ( 1 ) ;
#endif
if ( V_382 )
F_175 ( NULL ) ;
}
void F_181 ( struct V_384 * V_385 )
{
struct V_386 * V_386 ;
F_182 (spu, list, full_list) {
if ( V_386 -> V_387 >= V_388 ) {
F_183 ( 1 ) ;
continue;
}
V_389 [ V_386 -> V_387 ] . V_386 = V_386 ;
V_389 [ V_386 -> V_387 ] . V_390 = 0 ;
V_389 [ V_386 -> V_387 ] . V_391 = ( unsigned long )
V_389 [ V_386 -> V_387 ] . V_386 -> V_392 ;
}
}
static void F_184 ( void )
{
struct V_386 * V_386 ;
int V_65 ;
V_171 V_298 ;
for ( V_65 = 0 ; V_65 < V_388 ; V_65 ++ ) {
if ( ! V_389 [ V_65 ] . V_386 )
continue;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_386 = V_389 [ V_65 ] . V_386 ;
V_389 [ V_65 ] . V_393 =
F_185 ( & V_386 -> V_394 -> V_395 ) ;
V_298 = F_186 ( V_386 ) ;
V_389 [ V_65 ] . V_396 = V_298 ;
V_298 &= ~ V_397 ;
F_187 ( V_386 , V_298 ) ;
F_3 () ;
F_126 ( 200 ) ;
V_389 [ V_65 ] . V_390 = 1 ;
printf ( L_241 , V_65 ,
V_389 [ V_65 ] . V_393 ?
L_242 : L_243 ) ;
} else {
V_63 = 0 ;
printf ( L_244 , V_65 ) ;
}
V_63 = 0 ;
}
}
static void F_188 ( void )
{
struct V_386 * V_386 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_388 ; V_65 ++ ) {
if ( ! V_389 [ V_65 ] . V_386 )
continue;
if ( ! V_389 [ V_65 ] . V_390 ) {
printf ( L_245
L_246 , V_65 ) ;
continue;
}
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_386 = V_389 [ V_65 ] . V_386 ;
F_187 ( V_386 , V_389 [ V_65 ] . V_396 ) ;
F_189 ( & V_386 -> V_394 -> V_395 ,
V_389 [ V_65 ] . V_393 ) ;
F_3 () ;
F_126 ( 200 ) ;
printf ( L_247 , V_65 ) ;
} else {
V_63 = 0 ;
printf ( L_248 , V_65 ) ;
}
V_63 = 0 ;
}
}
static void F_190 ( struct V_386 * V_386 )
{
printf ( L_249 , V_386 ) ;
F_191 ( V_386 , L_250 , V_387 ) ;
F_191 ( V_386 , L_139 , V_113 ) ;
F_191 ( V_386 , L_251 , V_398 ) ;
F_191 ( V_386 , L_252 , V_392 ) ;
F_191 ( V_386 , L_251 , V_399 ) ;
F_191 ( V_386 , L_250 , V_400 ) ;
F_191 ( V_386 , L_251 , V_33 ) ;
F_191 ( V_386 , L_253 , V_401 ) ;
F_191 ( V_386 , L_251 , V_402 ) ;
F_191 ( V_386 , L_251 , V_403 ) ;
F_191 ( V_386 , L_251 , V_404 ) ;
F_191 ( V_386 , L_251 , V_405 [ 0 ] ) ;
F_191 ( V_386 , L_251 , V_405 [ 1 ] ) ;
F_191 ( V_386 , L_251 , V_405 [ 2 ] ) ;
F_191 ( V_386 , L_250 , V_406 ) ;
F_191 ( V_386 , L_253 , V_142 ) ;
F_191 ( V_386 , L_252 , V_407 ) ;
F_191 ( V_386 , L_252 , V_408 ) ;
F_191 ( V_386 , L_252 , V_409 ) ;
F_191 ( V_386 , L_252 , V_410 ) ;
F_191 ( V_386 , L_251 , V_411 ) ;
F_191 ( V_386 , L_252 , V_394 ) ;
F_192 ( L_250 , V_394 -> V_395 ,
F_185 ( & V_386 -> V_394 -> V_395 ) ) ;
F_192 ( L_250 , V_394 -> V_412 ,
F_185 ( & V_386 -> V_394 -> V_412 ) ) ;
F_192 ( L_250 , V_394 -> V_413 ,
F_185 ( & V_386 -> V_394 -> V_413 ) ) ;
F_191 ( V_386 , L_252 , V_414 ) ;
F_191 ( V_386 , L_252 , V_415 ) ;
}
int
F_193 ( unsigned long V_244 , long V_245 , int V_246 )
{
return F_152 ( V_244 , V_245 , V_246 , V_416 ) ;
}
static void F_194 ( unsigned long V_241 , int V_417 )
{
unsigned long V_32 , V_6 , V_418 ;
if ( setjmp ( V_114 ) == 0 ) {
V_63 = 1 ;
F_3 () ;
V_418 = ( unsigned long ) V_389 [ V_241 ] . V_386 -> V_392 ;
F_3 () ;
F_126 ( 200 ) ;
} else {
V_63 = 0 ;
printf ( L_254 , V_241 ) ;
return;
}
V_63 = 0 ;
if ( F_79 ( & V_32 ) )
V_6 = V_418 + V_32 ;
else
V_6 = V_389 [ V_241 ] . V_391 ;
if ( V_6 >= V_418 + V_419 ) {
printf ( L_255 ) ;
return;
}
switch ( V_417 ) {
case 'i' :
V_6 += F_193 ( V_6 , 16 , 1 ) ;
V_80 = L_256 ;
break;
default:
F_151 ( V_6 , 64 ) ;
V_6 += 64 ;
V_80 = L_257 ;
break;
}
V_389 [ V_241 ] . V_391 = V_6 ;
}
static int F_97 ( void )
{
static unsigned long V_241 = 0 ;
int V_27 , V_417 = 0 ;
V_27 = F_85 () ;
switch ( V_27 ) {
case 's' :
F_184 () ;
break;
case 'r' :
F_188 () ;
break;
case 'd' :
V_417 = F_85 () ;
if ( isxdigit ( V_417 ) || V_417 == '\n' )
V_85 = V_417 ;
case 'f' :
F_79 ( & V_241 ) ;
if ( V_241 >= V_388 || ! V_389 [ V_241 ] . V_386 ) {
printf ( L_258 ) ;
return 0 ;
}
switch ( V_27 ) {
case 'f' :
F_190 ( V_389 [ V_241 ] . V_386 ) ;
break;
default:
F_194 ( V_241 , V_417 ) ;
break;
}
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_97 ( void )
{
return - 1 ;
}
