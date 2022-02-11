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
if ( V_39 )
longjmp ( V_40 , 1 ) ;
F_15 () ;
F_32 ( V_21 ) ;
printf ( L_3
L_4 ,
V_34 , V_21 -> V_41 , F_33 ( F_34 ( V_21 ) ) ) ;
F_19 () ;
longjmp ( V_42 [ V_34 ] , 1 ) ;
}
if ( setjmp ( V_30 ) != 0 ) {
if ( ! V_43 || ! V_44 ) {
F_15 () ;
printf ( L_5
L_6 , V_34 ) ;
F_19 () ;
goto V_45;
}
V_35 = ! ( V_46 && V_34 == V_47 ) ;
goto V_48;
}
V_42 [ V_34 ] = V_30 ;
V_29 = NULL ;
if ( ( V_21 -> V_24 & ( V_49 | V_50 | V_51 ) ) == ( V_49 | V_51 ) )
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
V_45:
V_35 = 1 ;
while ( V_35 && ! V_44 ) {
if ( V_43 == 0 ) {
if ( V_26 )
goto V_52;
V_35 = F_39 ( 0 , & V_43 ) ;
}
F_40 () ;
}
if ( ! V_35 && ! V_44 ) {
int V_53 = F_41 () ;
V_47 = V_34 ;
F_42 () ;
if ( V_53 > 1 ) {
F_43 () ;
for ( V_17 = 100000000 ; V_17 != 0 ; -- V_17 ) {
if ( F_44 ( & V_19 ) >= V_53 )
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
V_44 = 1 ;
F_40 () ;
}
V_48:
while ( V_43 ) {
if ( V_35 ) {
if ( V_34 == V_47 ) {
if ( ! F_39 ( 0 , & V_46 ) ) {
V_35 = 0 ;
continue;
}
while ( V_34 == V_47 )
F_40 () ;
}
F_40 () ;
} else {
V_27 = F_47 ( V_21 ) ;
if ( V_27 != 0 ) {
F_48 () ;
V_44 = 0 ;
F_49 () ;
V_43 = 0 ;
break;
}
V_35 = 1 ;
}
}
V_52:
F_50 ( V_34 , & V_19 ) ;
V_42 [ V_34 ] = NULL ;
#else
if ( V_43 ) {
printf ( L_13 ,
V_21 -> V_41 , F_33 ( F_34 ( V_21 ) ) ) ;
longjmp ( V_42 [ 0 ] , 1 ) ;
}
if ( setjmp ( V_30 ) == 0 ) {
V_42 [ 0 ] = V_30 ;
V_43 = 1 ;
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
V_43 = 0 ;
#endif
#ifdef F_51
if ( V_21 -> V_24 & V_54 ) {
V_29 = F_35 ( V_21 -> V_36 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = ( unsigned long ) & V_29 -> V_55 [ 0 ] ;
F_52 ( & V_29 -> V_38 ) ;
}
}
#else
if ( ( V_21 -> V_24 & ( V_49 | V_50 | V_51 ) ) == ( V_49 | V_51 ) ) {
V_29 = F_35 ( V_21 -> V_36 ) ;
if ( V_29 != NULL ) {
int V_56 = F_53 ( V_21 , V_29 -> V_55 [ 0 ] ) ;
if ( V_56 == 0 ) {
V_21 -> V_36 = ( unsigned long ) & V_29 -> V_55 [ 0 ] ;
F_52 ( & V_29 -> V_38 ) ;
} else if ( V_56 < 0 ) {
printf ( L_15 ,
( F_54 ( V_29 -> V_55 [ 0 ] ) ? L_16 : L_17 ) ) ;
}
}
}
#endif
F_55 () ;
F_56 () ;
F_57 ( V_33 ) ;
return V_27 != 'X' && V_27 != V_57 ;
}
int F_58 ( struct V_20 * V_58 )
{
struct V_20 V_21 ;
if ( V_58 == NULL ) {
F_59 ( & V_21 ) ;
V_58 = & V_21 ;
}
return F_24 ( V_58 , 0 ) ;
}
T_1 F_60 ( int V_59 , void * V_60 )
{
unsigned long V_33 ;
F_26 ( V_33 ) ;
printf ( L_18 ) ;
F_58 ( F_61 () ) ;
F_57 ( V_33 ) ;
return V_61 ;
}
static int F_62 ( struct V_20 * V_21 )
{
struct V_28 * V_29 ;
unsigned long V_32 ;
if ( ( V_21 -> V_24 & ( V_49 | V_50 | V_51 ) ) != ( V_49 | V_51 ) )
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
if ( ( V_21 -> V_24 & ( V_49 | V_50 | V_51 ) ) != ( V_49 | V_51 ) )
return 0 ;
if ( V_62 . V_63 == 0 )
return 0 ;
F_24 ( V_21 , 0 ) ;
return 1 ;
}
static int F_66 ( struct V_20 * V_21 )
{
if ( ( V_21 -> V_24 & ( V_49 | V_50 | V_51 ) ) != ( V_49 | V_51 ) )
return 0 ;
if ( V_64 == NULL )
return 0 ;
F_24 ( V_21 , 0 ) ;
return 1 ;
}
static int F_67 ( struct V_20 * V_21 )
{
#ifdef F_25
if ( V_43 && ! F_31 ( F_16 () , & V_19 ) )
F_24 ( V_21 , 1 ) ;
#endif
return 0 ;
}
static int F_68 ( struct V_20 * V_21 )
{
struct V_28 * V_29 ;
unsigned long V_32 ;
if ( V_43 && V_65 )
F_69 ( V_21 ) ;
if ( ( V_21 -> V_24 & ( V_49 | V_50 | V_51 ) ) == ( V_49 | V_51 ) ) {
V_29 = F_28 ( V_21 -> V_36 , & V_32 ) ;
if ( V_29 != NULL ) {
V_21 -> V_36 = V_29 -> V_37 + V_32 ;
F_29 ( & V_29 -> V_38 ) ;
}
}
return 0 ;
}
static struct V_28 * F_35 ( unsigned long V_66 )
{
int V_67 ;
struct V_28 * V_29 ;
V_29 = V_68 ;
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 , ++ V_29 )
if ( V_29 -> V_63 && V_66 == V_29 -> V_37 )
return V_29 ;
return NULL ;
}
static struct V_28 * F_28 ( unsigned long V_36 , unsigned long * V_70 )
{
unsigned long V_71 ;
V_71 = V_36 - ( unsigned long ) V_68 ;
if ( V_71 >= sizeof( V_68 ) )
return NULL ;
V_71 %= sizeof( struct V_28 ) ;
if ( V_71 != F_70 ( struct V_28 , V_55 [ 0 ] )
&& V_71 != F_70 ( struct V_28 , V_55 [ 1 ] ) )
return NULL ;
* V_70 = V_71 - F_70 ( struct V_28 , V_55 [ 0 ] ) ;
return (struct V_28 * ) ( V_36 - V_71 ) ;
}
static struct V_28 * F_71 ( unsigned long V_72 )
{
struct V_28 * V_29 ;
V_72 &= ~ 3UL ;
V_29 = F_35 ( V_72 ) ;
if ( V_29 )
return V_29 ;
for ( V_29 = V_68 ; V_29 < & V_68 [ V_69 ] ; ++ V_29 ) {
if ( ! V_29 -> V_63 && F_72 ( & V_29 -> V_38 ) == 0 ) {
V_29 -> V_37 = V_72 ;
V_29 -> V_55 [ 1 ] = V_73 ;
F_4 ( & V_29 -> V_55 [ 1 ] ) ;
return V_29 ;
}
}
printf ( L_19 ) ;
return NULL ;
}
static void F_48 ( void )
{
int V_67 ;
struct V_28 * V_29 ;
V_29 = V_68 ;
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 , ++ V_29 ) {
if ( ( V_29 -> V_63 & ( V_74 | V_75 ) ) == 0 )
continue;
if ( F_73 ( V_29 -> V_37 , & V_29 -> V_55 [ 0 ] , 4 ) != 4 ) {
printf ( L_20
L_21 , V_29 -> V_37 ) ;
V_29 -> V_63 = 0 ;
continue;
}
if ( F_74 ( V_29 -> V_55 [ 0 ] ) || F_54 ( V_29 -> V_55 [ 0 ] ) ) {
printf ( L_22
L_23 , V_29 -> V_37 ) ;
V_29 -> V_63 = 0 ;
continue;
}
F_4 ( & V_29 -> V_55 [ 0 ] ) ;
if ( V_29 -> V_63 & V_75 )
continue;
if ( F_75 ( V_29 -> V_37 , & V_73 , 4 ) != 4 ) {
printf ( L_24
L_21 , V_29 -> V_37 ) ;
V_29 -> V_63 &= ~ V_74 ;
continue;
}
F_4 ( ( void * ) V_29 -> V_37 ) ;
}
}
static void F_55 ( void )
{
struct V_76 V_77 ;
if ( V_62 . V_63 ) {
V_77 . V_37 = V_62 . V_37 ;
V_77 . type = ( V_62 . V_63 & V_78 ) | V_79 ;
V_77 . V_80 = 8 ;
F_76 ( & V_77 ) ;
}
if ( V_64 )
F_10 ( V_64 -> V_37 ) ;
}
static void F_45 ( void )
{
int V_67 ;
struct V_28 * V_29 ;
unsigned V_55 ;
V_29 = V_68 ;
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 , ++ V_29 ) {
if ( ( V_29 -> V_63 & ( V_74 | V_75 ) ) != V_74 )
continue;
if ( F_73 ( V_29 -> V_37 , & V_55 , 4 ) == 4
&& V_55 == V_73
&& F_75 ( V_29 -> V_37 , & V_29 -> V_55 , 4 ) != 4 )
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
unsigned long V_81 ;
if ( ! F_79 ( & V_81 ) ) {
printf ( L_26 ) ;
V_81 = 0 ;
}
F_80 ( V_81 ) ;
}
static int
F_47 ( struct V_20 * V_58 )
{
int V_27 = 0 ;
V_82 = NULL ;
V_83 = V_58 ;
if ( ! V_84 ) {
V_84 = 1 ;
F_81 ( V_58 -> V_85 [ 1 ] , V_58 -> V_86 , V_58 -> V_36 ) ;
}
for(; ; ) {
#ifdef F_25
printf ( L_27 , F_16 () ) ;
#endif
printf ( L_28 ) ;
F_82 () ;
V_87 = 0 ;
V_27 = F_83 () ;
if( V_27 == '\n' ) {
if ( V_82 == NULL )
continue;
F_84 ( V_82 ) ;
V_82 = NULL ;
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
V_87 = V_27 ;
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
F_93 ( V_58 ) ;
break;
case 'e' :
F_32 ( V_58 ) ;
break;
case 'S' :
F_94 () ;
break;
case 't' :
F_95 ( V_58 ) ;
break;
case 'f' :
F_96 () ;
break;
case 's' :
if ( F_97 () == 0 )
break;
if ( F_98 ( V_58 ) )
return V_27 ;
break;
case 'x' :
case 'X' :
return V_27 ;
case V_57 :
printf ( L_29 ) ;
F_99 ( 2000 ) ;
return V_27 ;
case '?' :
F_100 ( V_88 ) ;
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
#elif F_23 ( V_89 )
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
V_21 -> V_24 |= V_54 ;
F_9 ( V_90 , F_111 ( V_90 ) | V_91 | V_92 ) ;
return 1 ;
}
static int F_98 ( struct V_20 * V_21 )
{
unsigned int V_55 ;
int V_56 ;
if ( ( V_21 -> V_24 & ( V_51 | V_50 | V_49 ) ) == ( V_51 | V_49 ) ) {
if ( F_73 ( V_21 -> V_36 , & V_55 , 4 ) == 4 ) {
V_56 = F_53 ( V_21 , V_55 ) ;
if ( V_56 < 0 ) {
printf ( L_15 ,
( F_54 ( V_55 ) ? L_16 : L_17 ) ) ;
return 0 ;
}
if ( V_56 > 0 ) {
V_21 -> V_41 = 0xd00 | ( V_21 -> V_41 & 1 ) ;
printf ( L_33 ) ;
F_37 ( V_21 -> V_36 , L_8 , L_34 ) ;
F_46 ( V_21 -> V_36 , 1 , 0 ) ;
return 0 ;
}
}
}
V_21 -> V_24 |= V_93 ;
return 1 ;
}
static void F_104 ( void )
{
int V_27 ;
V_27 = F_85 () ;
if ( V_27 == 'r' )
V_94 . V_95 ( NULL ) ;
else if ( V_27 == 'h' )
V_94 . V_96 () ;
else if ( V_27 == 'p' )
if ( V_97 )
V_97 () ;
}
static int F_103 ( void )
{
#ifdef F_25
unsigned long V_34 , V_98 , V_99 ;
int V_17 ;
if ( ! F_79 ( & V_34 ) ) {
printf ( L_35 ) ;
V_99 = V_98 = V_100 ;
F_112 (cpu) {
if ( F_31 ( V_34 , & V_19 ) ) {
if ( V_34 == V_99 + 1 ) {
V_99 = V_34 ;
} else {
if ( V_99 != V_98 )
printf ( L_36 , V_99 ) ;
V_99 = V_98 = V_34 ;
printf ( L_37 , V_34 ) ;
}
}
}
if ( V_99 != V_98 )
printf ( L_36 , V_99 ) ;
printf ( L_34 ) ;
return 0 ;
}
if ( ! F_31 ( V_34 , & V_19 ) ) {
printf ( L_38 , V_34 ) ;
return 0 ;
}
V_46 = 0 ;
F_42 () ;
V_47 = V_34 ;
V_17 = 10000000 ;
while ( ! V_46 ) {
if ( -- V_17 == 0 ) {
if ( F_39 ( 0 , & V_46 ) )
break;
F_42 () ;
V_47 = F_16 () ;
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
unsigned int V_67 ;
unsigned short V_101 ;
unsigned char V_102 ;
if ( ! F_79 ( & V_103 ) )
return;
if ( ! F_79 ( & V_104 ) )
return;
V_101 = 0xffff ;
for ( V_67 = 0 ; V_67 < V_104 ; ++ V_67 ) {
if ( F_73 ( V_103 + V_67 , & V_102 , 1 ) == 0 ) {
printf ( L_40 V_105 L_34 , V_103 + V_67 ) ;
break;
}
V_101 = F_113 ( V_101 , V_102 ) ;
}
printf ( L_41 , V_101 ) ;
}
static long F_114 ( unsigned long V_6 )
{
unsigned int V_55 ;
V_6 &= ~ 3 ;
if ( ! F_115 ( V_6 ) ) {
printf ( L_42 ) ;
return 0 ;
}
if ( ! F_73 ( V_6 , & V_55 , sizeof( V_55 ) ) ) {
printf ( L_43 , V_6 ) ;
return 0 ;
}
if ( F_74 ( V_55 ) || F_54 ( V_55 ) ) {
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
unsigned long V_72 ;
int V_106 , V_67 ;
struct V_28 * V_29 ;
const char V_107 [] = L_46
L_47 ;
V_27 = F_85 () ;
switch ( V_27 ) {
#ifndef F_116
case 'd' :
V_106 = 7 ;
V_27 = F_85 () ;
if ( V_27 == 'r' )
V_106 = 5 ;
else if ( V_27 == 'w' )
V_106 = 6 ;
else
V_87 = V_27 ;
V_62 . V_37 = 0 ;
V_62 . V_63 = 0 ;
if ( F_79 ( & V_62 . V_37 ) ) {
if ( ! F_115 ( V_62 . V_37 ) ) {
printf ( V_107 ) ;
break;
}
V_62 . V_37 &= ~ V_78 ;
V_62 . V_63 = V_106 | V_108 ;
}
break;
case 'i' :
if ( ! F_8 ( V_3 ) ) {
printf ( L_48
L_49 ) ;
break;
}
if ( V_64 ) {
V_64 -> V_63 &= ~ V_75 ;
V_64 = NULL ;
}
if ( ! F_79 ( & V_72 ) )
break;
if ( ! F_114 ( V_72 ) )
break;
V_29 = F_71 ( V_72 ) ;
if ( V_29 != NULL ) {
V_29 -> V_63 |= V_75 ;
V_64 = V_29 ;
}
break;
#endif
case 'c' :
if ( ! F_79 ( & V_72 ) ) {
for ( V_67 = 0 ; V_67 < V_69 ; ++ V_67 )
V_68 [ V_67 ] . V_63 = 0 ;
V_64 = NULL ;
V_62 . V_63 = 0 ;
printf ( L_50 ) ;
break;
}
if ( V_72 <= V_69 && V_72 >= 1 ) {
V_29 = & V_68 [ V_72 - 1 ] ;
} else {
V_29 = F_35 ( V_72 ) ;
if ( V_29 == NULL ) {
printf ( L_51 , V_72 ) ;
break;
}
}
printf ( L_52 , F_36 ( V_29 ) ) ;
F_37 ( V_29 -> V_37 , L_8 , L_9 ) ;
V_29 -> V_63 = 0 ;
break;
default:
V_87 = V_27 ;
V_27 = F_83 () ;
if ( V_27 == '?' ) {
printf ( V_109 ) ;
break;
}
V_87 = V_27 ;
if ( ! F_79 ( & V_72 ) ) {
printf ( L_53 ) ;
if ( V_62 . V_63 ) {
printf ( L_54 V_105 L_55 , V_62 . V_37 ) ;
if ( V_62 . V_63 & 1 )
printf ( L_56 ) ;
if ( V_62 . V_63 & 2 )
printf ( L_57 ) ;
printf ( L_58 ) ;
}
for ( V_29 = V_68 ; V_29 < & V_68 [ V_69 ] ; ++ V_29 ) {
if ( ! V_29 -> V_63 )
continue;
printf ( L_59 , F_36 ( V_29 ) ,
( V_29 -> V_63 & V_75 ) ? L_60 : L_61 ) ;
F_37 ( V_29 -> V_37 , L_62 , L_34 ) ;
}
break;
}
if ( ! F_114 ( V_72 ) )
break;
V_29 = F_71 ( V_72 ) ;
if ( V_29 != NULL )
V_29 -> V_63 |= V_74 ;
break;
}
}
static
const char * F_33 ( unsigned long V_110 )
{
char * V_111 ;
switch ( V_110 ) {
case 0x100 : V_111 = L_63 ; break;
case 0x200 : V_111 = L_64 ; break;
case 0x300 : V_111 = L_65 ; break;
case 0x380 : V_111 = L_66 ; break;
case 0x400 : V_111 = L_67 ; break;
case 0x480 : V_111 = L_68 ; break;
case 0x500 : V_111 = L_69 ; break;
case 0x600 : V_111 = L_70 ; break;
case 0x700 : V_111 = L_71 ; break;
case 0x800 : V_111 = L_72 ; break;
case 0x900 : V_111 = L_73 ; break;
case 0x980 : V_111 = L_74 ; break;
case 0xa00 : V_111 = L_75 ; break;
case 0xc00 : V_111 = L_76 ; break;
case 0xd00 : V_111 = L_77 ; break;
case 0xe40 : V_111 = L_78 ; break;
case 0xe60 : V_111 = L_79 ; break;
case 0xe80 : V_111 = L_80 ; break;
case 0xf00 : V_111 = L_81 ; break;
case 0xf20 : V_111 = L_82 ; break;
case 0x1300 : V_111 = L_83 ; break;
case 0x1500 : V_111 = L_84 ; break;
case 0x1700 : V_111 = L_85 ; break;
default: V_111 = L_86 ;
}
return V_111 ;
}
static void F_117 ( unsigned long V_66 , unsigned long * V_112 ,
unsigned long * V_113 )
{
unsigned long V_114 , V_32 ;
const char * V_115 ;
* V_112 = * V_113 = 0 ;
if ( V_66 == 0 )
return;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_115 = F_118 ( V_66 , & V_114 , & V_32 , NULL , V_116 ) ;
if ( V_115 != NULL ) {
* V_112 = V_66 - V_32 ;
* V_113 = V_66 - V_32 + V_114 ;
}
F_3 () ;
}
V_65 = 0 ;
}
static void F_81 ( unsigned long V_117 , unsigned long V_118 ,
unsigned long V_66 )
{
int V_119 = 64 ;
unsigned long V_120 ;
unsigned long V_121 ;
unsigned long V_122 ;
struct V_20 V_21 ;
while ( V_119 -- ) {
if ( V_117 < V_123 ) {
if ( V_117 != 0 )
printf ( L_87 , V_117 ) ;
break;
}
if ( ! F_73 ( V_117 + V_124 , & V_120 , sizeof( unsigned long ) )
|| ! F_73 ( V_117 , & V_121 , sizeof( unsigned long ) ) ) {
printf ( L_88 , V_117 ) ;
break;
}
if ( ( V_66 | V_118 ) != 0 ) {
unsigned long V_125 , V_126 ;
unsigned long V_127 ;
int V_128 = 1 ;
F_117 ( V_66 , & V_125 , & V_126 ) ;
V_127 = 0 ;
if ( V_121 > V_117 )
F_73 ( V_121 + V_124 , & V_127 ,
sizeof( unsigned long ) ) ;
if ( V_118 == V_120 ) {
if ( V_118 < V_123
|| ( V_125 <= V_118 && V_118 < V_126 ) )
V_128 = 0 ;
} else if ( V_118 == V_127 ) {
V_128 = 0 ;
} else if ( V_118 >= V_123
&& ! ( V_125 <= V_118 && V_118 < V_126 ) ) {
printf ( L_89 ) ;
F_37 ( V_118 , L_8 , L_34 ) ;
}
if ( V_128 ) {
printf ( L_90 V_105 L_91 , V_117 ) ;
F_37 ( V_120 , L_8 , L_92 ) ;
}
V_66 = V_118 = 0 ;
} else {
printf ( L_90 V_105 L_91 , V_117 ) ;
F_37 ( V_120 , L_8 , L_34 ) ;
}
if ( F_73 ( V_117 + V_129 , & V_122 , sizeof( unsigned long ) )
&& V_122 == V_130 ) {
if ( F_73 ( V_117 + V_131 , & V_21 , sizeof( V_21 ) )
!= sizeof( V_21 ) ) {
printf ( L_93 ,
V_117 + V_131 ) ;
break;
}
printf ( L_94 , V_21 . V_41 ,
F_33 ( F_34 ( & V_21 ) ) ) ;
V_66 = V_21 . V_36 ;
V_118 = V_21 . V_86 ;
F_37 ( V_66 , L_8 , L_34 ) ;
}
if ( V_121 == 0 )
break;
V_117 = V_121 ;
}
}
static void F_95 ( struct V_20 * V_58 )
{
unsigned long V_117 ;
if ( F_79 ( & V_117 ) )
F_81 ( V_117 , 0 , 0 ) ;
else
F_81 ( V_58 -> V_85 [ 1 ] , V_58 -> V_86 , V_58 -> V_36 ) ;
F_119 () ;
}
static void F_120 ( struct V_20 * V_21 )
{
#ifdef F_121
const struct V_132 * V_133 ;
unsigned long V_6 ;
if ( V_21 -> V_24 & V_50 )
return;
V_6 = V_21 -> V_36 ;
if ( V_6 < V_123 )
return;
V_133 = F_122 ( V_21 -> V_36 ) ;
if ( V_133 == NULL )
return;
if ( F_123 ( V_133 ) )
return;
#ifdef F_124
printf ( L_95 ,
V_133 -> V_134 , V_133 -> line ) ;
#else
printf ( L_96 , ( void * ) V_133 -> V_135 ) ;
#endif
#endif
}
static void F_32 ( struct V_20 * V_136 )
{
unsigned long V_41 ;
#ifdef F_25
printf ( L_97 , F_16 () ) ;
#endif
V_41 = F_34 ( V_136 ) ;
printf ( L_98 , V_136 -> V_41 , F_33 ( V_41 ) , V_136 ) ;
printf ( L_99 ) ;
F_37 ( V_136 -> V_36 , L_100 , L_34 ) ;
printf ( L_101 , V_136 -> V_86 ) ;
F_37 ( V_136 -> V_86 , L_100 , L_34 ) ;
printf ( L_102 , V_136 -> V_85 [ 1 ] ) ;
printf ( L_103 , V_136 -> V_24 ) ;
if ( V_41 == 0x300 || V_41 == 0x380 || V_41 == 0x600 || V_41 == 0x200 ) {
printf ( L_104 , V_136 -> V_137 ) ;
if ( V_41 != 0x380 )
printf ( L_105 , V_136 -> V_138 ) ;
}
printf ( L_106 , V_139 ) ;
#ifdef F_125
printf ( L_107 ,
V_140 , V_140 -> V_141 , V_140 -> V_142 ) ;
#endif
if ( V_139 ) {
printf ( L_108 ,
V_139 -> V_143 , V_139 -> V_144 ) ;
}
if ( V_41 == 0x700 )
F_120 ( V_136 ) ;
printf ( V_145 ) ;
}
static void F_93 ( struct V_20 * V_136 )
{
int V_146 , V_41 ;
unsigned long V_147 ;
struct V_20 V_21 ;
if ( F_79 ( & V_147 ) ) {
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_21 = * (struct V_20 * ) V_147 ;
F_3 () ;
F_126 ( 200 ) ;
} else {
V_65 = 0 ;
printf ( L_109 V_105 L_34 ,
V_147 ) ;
return;
}
V_65 = 0 ;
V_136 = & V_21 ;
}
#ifdef F_125
if ( F_127 ( V_136 ) ) {
for ( V_146 = 0 ; V_146 < 16 ; ++ V_146 )
printf ( L_110 V_105 L_111 V_105 L_34 ,
V_146 , V_136 -> V_85 [ V_146 ] , V_146 + 16 , V_136 -> V_85 [ V_146 + 16 ] ) ;
} else {
for ( V_146 = 0 ; V_146 < 7 ; ++ V_146 )
printf ( L_110 V_105 L_111 V_105 L_34 ,
V_146 , V_136 -> V_85 [ V_146 ] , V_146 + 7 , V_136 -> V_85 [ V_146 + 7 ] ) ;
}
#else
for ( V_146 = 0 ; V_146 < 32 ; ++ V_146 ) {
printf ( L_112 , V_146 , V_136 -> V_85 [ V_146 ] ,
( V_146 & 3 ) == 3 ? L_34 : L_113 ) ;
if ( V_146 == 12 && ! F_127 ( V_136 ) ) {
printf ( L_34 ) ;
break;
}
}
#endif
printf ( L_114 ) ;
F_37 ( V_136 -> V_36 , L_8 , L_34 ) ;
if ( F_34 ( V_136 ) != 0xc00 && F_8 ( V_148 ) ) {
printf ( L_115 ) ;
F_37 ( V_136 -> V_149 , L_8 , L_34 ) ;
}
printf ( L_116 ) ;
F_37 ( V_136 -> V_86 , L_8 , L_34 ) ;
printf ( L_117 V_105 L_118 , V_136 -> V_24 , V_136 -> V_150 ) ;
printf ( L_119 V_105 L_120 V_105 L_121 ,
V_136 -> V_151 , V_136 -> V_152 , V_136 -> V_41 ) ;
V_41 = F_34 ( V_136 ) ;
if ( V_41 == 0x300 || V_41 == 0x380 || V_41 == 0x600 )
printf ( L_122 V_105 L_123 , V_136 -> V_137 , V_136 -> V_138 ) ;
}
static void F_96 ( void )
{
int V_27 ;
unsigned long V_153 ;
V_27 = F_85 () ;
if ( V_27 != 'i' )
V_87 = V_27 ;
F_79 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
V_153 = 1 ;
F_79 ( & V_153 ) ;
V_153 = ( V_153 + V_154 - 1 ) / V_154 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
if ( V_27 != 'i' ) {
for (; V_153 > 0 ; -- V_153 , V_103 += V_154 )
F_5 ( ( void * ) V_103 ) ;
} else {
for (; V_153 > 0 ; -- V_153 , V_103 += V_154 )
F_6 ( ( void * ) V_103 ) ;
}
F_3 () ;
F_126 ( 200 ) ;
}
V_65 = 0 ;
}
static int
F_128 ( int V_146 , unsigned long * V_155 )
{
unsigned long V_111 = - 1UL ;
int V_156 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_39 = 1 ;
F_3 () ;
V_111 = F_129 ( V_146 , * V_155 ) ;
F_3 () ;
* V_155 = V_111 ;
V_156 = 1 ;
}
V_39 = 0 ;
return V_156 ;
}
static void
F_130 ( int V_146 , unsigned long V_157 )
{
if ( setjmp ( V_40 ) == 0 ) {
V_39 = 1 ;
F_3 () ;
F_131 ( V_146 , V_157 ) ;
F_3 () ;
} else {
printf ( L_124 , V_146 , V_146 ) ;
}
V_39 = 0 ;
}
static void F_132 ( int V_158 , bool V_159 )
{
unsigned long V_157 ;
V_157 = 0xdeadbeef ;
if ( ! F_128 ( V_158 , & V_157 ) ) {
printf ( L_125 , V_158 , V_158 ) ;
return;
}
if ( V_157 == 0xdeadbeef ) {
V_157 = 0x0badcafe ;
if ( ! F_128 ( V_158 , & V_157 ) ) {
printf ( L_125 , V_158 , V_158 ) ;
return;
}
if ( V_157 == 0x0badcafe ) {
if ( V_159 )
printf ( L_126 , V_158 , V_158 ) ;
return;
}
}
printf ( L_127 , V_158 , V_158 , V_157 ) ;
}
static void F_94 ( void )
{
int V_27 ;
int V_158 ;
V_27 = F_83 () ;
switch ( V_27 ) {
case '\n' : {
unsigned long V_117 , V_160 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_128 V_105 L_129 V_105 L_34 ,
F_133 () , F_111 ( V_161 ) ) ;
printf ( L_130 V_105 L_131 V_105 L_34 ,
F_111 ( V_162 ) , F_111 ( V_163 ) ) ;
printf ( L_132 V_105 L_133 V_105 L_34 ,
F_111 ( V_164 ) , F_111 ( V_165 ) ) ;
printf ( L_134 V_105 L_135 V_105 L_34 , V_117 , F_111 ( V_166 ) ) ;
printf ( L_136 V_105 L_137 V_105 L_34 , V_160 , F_111 ( V_167 ) ) ;
return;
}
case 'w' : {
unsigned long V_157 ;
F_79 ( & V_168 ) ;
V_157 = 0 ;
F_128 ( V_168 , & V_157 ) ;
F_79 ( & V_157 ) ;
F_130 ( V_168 , V_157 ) ;
F_132 ( V_168 , true ) ;
break;
}
case 'r' :
F_79 ( & V_168 ) ;
F_132 ( V_168 , true ) ;
break;
case 'a' :
for ( V_158 = 1 ; V_158 < 1024 ; ++ V_158 )
F_132 ( V_158 , false ) ;
break;
}
F_119 () ;
}
static int
F_73 ( unsigned long V_103 , void * V_169 , int V_114 )
{
volatile int V_146 ;
char * V_2 , * V_170 ;
V_146 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_2 = ( char * ) V_103 ;
V_170 = ( char * ) V_169 ;
switch ( V_114 ) {
case 2 :
* ( V_171 * ) V_170 = * ( V_171 * ) V_2 ;
break;
case 4 :
* ( V_172 * ) V_170 = * ( V_172 * ) V_2 ;
break;
case 8 :
* ( V_173 * ) V_170 = * ( V_173 * ) V_2 ;
break;
default:
for( ; V_146 < V_114 ; ++ V_146 ) {
* V_170 ++ = * V_2 ++ ;
F_3 () ;
}
}
F_3 () ;
F_126 ( 200 ) ;
V_146 = V_114 ;
}
V_65 = 0 ;
return V_146 ;
}
static int
F_75 ( unsigned long V_103 , void * V_169 , int V_114 )
{
volatile int V_146 ;
char * V_2 , * V_170 ;
V_146 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_2 = ( char * ) V_103 ;
V_170 = ( char * ) V_169 ;
switch ( V_114 ) {
case 2 :
* ( V_171 * ) V_2 = * ( V_171 * ) V_170 ;
break;
case 4 :
* ( V_172 * ) V_2 = * ( V_172 * ) V_170 ;
break;
case 8 :
* ( V_173 * ) V_2 = * ( V_173 * ) V_170 ;
break;
default:
for ( ; V_146 < V_114 ; ++ V_146 ) {
* V_2 ++ = * V_170 ++ ;
F_3 () ;
}
}
F_3 () ;
F_126 ( 200 ) ;
V_146 = V_114 ;
} else {
printf ( L_138 V_105 L_34 , V_103 + V_146 ) ;
}
V_65 = 0 ;
return V_146 ;
}
static int F_69 ( struct V_20 * V_21 )
{
V_174 = F_34 ( V_21 ) ;
switch ( F_34 ( V_21 ) ) {
case 0x200 :
V_175 = 0 ;
break;
case 0x300 :
case 0x380 :
V_175 = 1 ;
break;
default:
V_175 = 2 ;
}
longjmp ( V_40 , 1 ) ;
return 0 ;
}
static void
F_134 ( unsigned char * V_157 , int V_114 )
{
int V_176 ;
switch ( V_114 ) {
case 2 :
F_135 ( V_157 [ 0 ] , V_157 [ 1 ] , V_176 ) ;
break;
case 4 :
F_135 ( V_157 [ 0 ] , V_157 [ 3 ] , V_176 ) ;
F_135 ( V_157 [ 1 ] , V_157 [ 2 ] , V_176 ) ;
break;
case 8 :
F_135 ( V_157 [ 0 ] , V_157 [ 7 ] , V_176 ) ;
F_135 ( V_157 [ 1 ] , V_157 [ 6 ] , V_176 ) ;
F_135 ( V_157 [ 2 ] , V_157 [ 5 ] , V_176 ) ;
F_135 ( V_157 [ 3 ] , V_157 [ 4 ] , V_176 ) ;
break;
}
}
static void
F_90 ( void )
{
int V_27 , V_177 , V_67 , V_178 ;
unsigned long V_146 ;
unsigned char V_157 [ 16 ] ;
F_79 ( ( void * ) & V_103 ) ;
V_27 = F_83 () ;
if ( V_27 == '?' ) {
printf ( V_179 ) ;
return;
} else {
V_87 = V_27 ;
}
V_82 = L_139 ;
while ( ( V_27 = F_83 () ) != '\n' ) {
switch( V_27 ) {
case 'b' : V_114 = 1 ; break;
case 'w' : V_114 = 2 ; break;
case 'l' : V_114 = 4 ; break;
case 'd' : V_114 = 8 ; break;
case 'r' : V_180 = ! V_180 ; break;
case 'n' : V_181 = 1 ; break;
case '.' : V_181 = 0 ; break;
}
}
if( V_114 <= 0 )
V_114 = 1 ;
else if( V_114 > 8 )
V_114 = 8 ;
for(; ; ) {
if ( ! V_181 )
V_146 = F_73 ( V_103 , V_157 , V_114 ) ;
printf ( V_105 L_140 , V_103 , V_180 ? 'r' : ' ' ) ;
if ( ! V_181 ) {
if ( V_180 )
F_134 ( V_157 , V_114 ) ;
putchar ( ' ' ) ;
for ( V_67 = 0 ; V_67 < V_146 ; ++ V_67 )
printf ( L_141 , V_157 [ V_67 ] ) ;
for (; V_67 < V_114 ; ++ V_67 )
printf ( L_142 , V_182 [ V_175 ] ) ;
}
putchar ( ' ' ) ;
V_177 = V_114 ;
V_178 = 0 ;
for(; ; ) {
if( F_79 ( & V_146 ) ) {
for ( V_67 = 0 ; V_67 < V_114 ; ++ V_67 )
V_157 [ V_67 ] = V_146 >> ( V_67 * 8 ) ;
if ( ! V_180 )
F_134 ( V_157 , V_114 ) ;
F_75 ( V_103 , V_157 , V_114 ) ;
V_177 = V_114 ;
}
V_27 = F_83 () ;
if ( V_27 == '\n' )
break;
V_177 = 0 ;
switch ( V_27 ) {
case '\'' :
for(; ; ) {
V_146 = F_85 () ;
if( V_146 == '\\' )
V_146 = F_136 () ;
else if( V_146 == '\'' )
break;
for ( V_67 = 0 ; V_67 < V_114 ; ++ V_67 )
V_157 [ V_67 ] = V_146 >> ( V_67 * 8 ) ;
if ( ! V_180 )
F_134 ( V_157 , V_114 ) ;
F_75 ( V_103 , V_157 , V_114 ) ;
V_103 += V_114 ;
}
V_103 -= V_114 ;
V_177 = V_114 ;
break;
case ',' :
V_103 += V_114 ;
break;
case '.' :
V_181 = 0 ;
break;
case ';' :
break;
case 'x' :
case V_57 :
F_119 () ;
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
if ( V_178 > 0 )
V_103 -= 1 << V_178 ;
else
V_178 = 0 ;
V_178 += 4 ;
V_103 += 1 << V_178 ;
break;
case '\\' :
if ( V_178 < 0 )
V_103 += 1 << - V_178 ;
else
V_178 = 0 ;
V_178 -= 4 ;
V_103 -= 1 << - V_178 ;
break;
case 'm' :
F_79 ( ( void * ) & V_103 ) ;
break;
case 'n' :
V_181 = 1 ;
break;
case 'r' :
V_180 = ! V_180 ;
break;
case '<' :
V_146 = V_114 ;
F_79 ( & V_146 ) ;
V_103 -= V_146 ;
break;
case '>' :
V_146 = V_114 ;
F_79 ( & V_146 ) ;
V_103 += V_146 ;
break;
case '?' :
printf ( V_183 ) ;
break;
}
}
V_103 += V_177 ;
}
}
static int
F_136 ( void )
{
int V_184 ;
V_184 = F_85 () ;
switch( V_184 ) {
case 'n' : V_184 = '\n' ; break;
case 'r' : V_184 = '\r' ; break;
case 'b' : V_184 = '\b' ; break;
case 't' : V_184 = '\t' ; break;
}
return V_184 ;
}
static void F_137 ( unsigned long V_103 , long V_185 )
{
long V_146 , V_186 , V_187 , V_188 ;
unsigned char V_189 [ 16 ] ;
for ( V_146 = V_185 ; V_146 > 0 ; ) {
V_187 = V_146 < 16 ? V_146 : 16 ;
V_188 = F_73 ( V_103 , V_189 , V_187 ) ;
V_103 += V_188 ;
for ( V_186 = 0 ; V_186 < V_187 ; ++ V_186 ) {
if ( V_186 < V_188 )
printf ( L_141 , V_189 [ V_186 ] ) ;
else
printf ( L_142 , V_182 [ V_175 ] ) ;
}
V_146 -= V_187 ;
if ( V_188 < V_187 )
break;
}
printf ( L_34 ) ;
}
static void F_138 ( int V_34 )
{
struct V_190 * V_2 ;
#ifdef F_139
int V_67 = 0 ;
#endif
if ( setjmp ( V_40 ) != 0 ) {
printf ( L_143 , V_34 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
V_2 = & V_191 [ V_34 ] ;
printf ( L_144 , V_34 , V_2 ) ;
printf ( L_145 , 20 , L_146 , F_140 ( V_34 ) ? L_147 : L_148 ) ;
printf ( L_145 , 20 , L_149 , F_141 ( V_34 ) ? L_147 : L_148 ) ;
printf ( L_145 , 20 , L_150 , F_142 ( V_34 ) ? L_147 : L_148 ) ;
#define F_143 ( V_191 , V_115 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 20, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_143 ( V_2 , V_192 , L_151 ) ;
F_143 ( V_2 , V_193 , L_151 ) ;
F_143 ( V_2 , V_194 , L_152 ) ;
F_143 ( V_2 , V_195 , L_152 ) ;
F_143 ( V_2 , V_196 , L_152 ) ;
F_143 ( V_2 , V_197 , L_153 ) ;
#ifdef F_144
F_143 ( V_2 , V_198 , L_153 ) ;
F_143 ( V_2 , V_199 , L_151 ) ;
F_143 ( V_2 , V_200 , L_151 ) ;
#endif
F_143 ( V_2 , V_201 , L_152 ) ;
F_143 ( V_2 , V_202 , L_151 ) ;
F_143 ( V_2 , V_203 , L_151 ) ;
F_143 ( V_2 , V_204 , L_151 ) ;
#ifdef F_139
for ( V_67 = 0 ; V_67 < V_205 ; V_67 ++ ) {
V_173 V_206 , V_207 ;
if ( ! V_2 -> V_208 )
continue;
V_206 = F_145 ( V_2 -> V_208 -> V_209 [ V_67 ] . V_206 ) ;
V_207 = F_145 ( V_2 -> V_208 -> V_209 [ V_67 ] . V_207 ) ;
if ( V_206 || V_207 ) {
printf ( L_154 ,
V_67 , V_206 , V_207 ) ;
}
}
F_143 ( V_2 , V_210 , L_151 ) ;
F_143 ( V_2 , V_211 , L_151 ) ;
for ( V_67 = 0 ; V_67 < V_212 ; V_67 ++ )
printf ( L_155 , V_67 , V_2 -> V_213 [ V_67 ] ) ;
#endif
F_143 ( V_2 , V_214 , L_156 ) ;
#ifdef V_23
F_143 ( V_2 , V_215 , L_153 ) ;
F_143 ( V_2 , V_216 , L_153 ) ;
F_143 ( V_2 , V_217 , L_153 ) ;
F_143 ( V_2 , V_218 , L_153 ) ;
F_143 ( V_2 , V_219 , L_153 ) ;
F_143 ( V_2 , V_220 , L_153 ) ;
#endif
F_143 ( V_2 , V_221 , L_153 ) ;
F_143 ( V_2 , V_222 , L_152 ) ;
F_143 ( V_2 , V_223 , L_152 ) ;
F_143 ( V_2 , V_224 , L_152 ) ;
F_143 ( V_2 , V_225 , L_151 ) ;
F_143 ( V_2 , V_141 , L_151 ) ;
F_143 ( V_2 , V_142 , L_151 ) ;
F_143 ( V_2 , V_226 , L_151 ) ;
F_143 ( V_2 , V_227 , L_151 ) ;
F_143 ( V_2 , V_228 , L_151 ) ;
F_143 ( V_2 , V_229 , L_156 ) ;
#ifdef F_146
F_143 ( V_2 , V_230 , L_156 ) ;
#endif
#ifdef F_147
F_143 ( V_2 , V_231 , L_153 ) ;
F_143 ( V_2 , V_232 , L_151 ) ;
F_143 ( V_2 , V_233 , L_151 ) ;
F_143 ( V_2 , V_234 , L_151 ) ;
#endif
F_143 ( V_2 , V_235 , L_156 ) ;
F_143 ( V_2 , V_236 , L_156 ) ;
F_143 ( V_2 , V_237 , L_156 ) ;
F_143 ( V_2 , V_238 , L_156 ) ;
F_143 ( V_2 , V_239 , L_156 ) ;
F_143 ( V_2 , V_240 , L_156 ) ;
F_143 ( V_2 , V_241 , L_156 ) ;
F_143 ( V_2 , V_242 , L_156 ) ;
#undef F_143
V_65 = 0 ;
F_3 () ;
}
static void F_148 ( void )
{
int V_34 ;
if ( F_149 () == 0 ) {
printf ( L_157 ) ;
return;
}
F_112 (cpu)
F_138 ( V_34 ) ;
}
static void F_150 ( void )
{
unsigned long V_243 ;
int V_184 ;
V_184 = F_85 () ;
if ( V_184 == 'a' ) {
F_148 () ;
return;
}
V_87 = V_184 ;
if ( F_79 ( & V_243 ) )
F_138 ( V_243 ) ;
else
F_138 ( V_47 ) ;
}
static void
F_91 ( void )
{
int V_184 ;
V_184 = F_85 () ;
#ifdef F_125
if ( V_184 == 'p' ) {
F_151 () ;
F_150 () ;
F_152 () ;
return;
}
#endif
if ( ( isxdigit ( V_184 ) && V_184 != 'f' && V_184 != 'd' ) || V_184 == '\n' )
V_87 = V_184 ;
F_79 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
if ( V_184 == 'i' ) {
F_79 ( & V_244 ) ;
if ( V_244 == 0 )
V_244 = 16 ;
else if ( V_244 > V_245 )
V_244 = V_245 ;
V_103 += F_46 ( V_103 , V_244 , 1 ) ;
V_82 = L_158 ;
} else if ( V_184 == 'l' ) {
F_153 () ;
} else if ( V_184 == 'o' ) {
F_2 () ;
} else if ( V_184 == 'r' ) {
F_79 ( & V_185 ) ;
if ( V_185 == 0 )
V_185 = 64 ;
F_137 ( V_103 , V_185 ) ;
V_103 += V_185 ;
V_82 = L_159 ;
} else {
F_79 ( & V_185 ) ;
if ( V_185 == 0 )
V_185 = 64 ;
else if ( V_185 > V_245 )
V_185 = V_245 ;
F_154 ( V_103 , V_185 ) ;
V_103 += V_185 ;
V_82 = L_160 ;
}
}
static void
F_154 ( unsigned long V_103 , long V_185 )
{
long V_146 , V_186 , V_184 , V_187 , V_188 ;
unsigned char V_189 [ 16 ] ;
for ( V_146 = V_185 ; V_146 > 0 ; ) {
printf ( V_105 , V_103 ) ;
putchar ( ' ' ) ;
V_187 = V_146 < 16 ? V_146 : 16 ;
V_188 = F_73 ( V_103 , V_189 , V_187 ) ;
V_103 += V_188 ;
for ( V_186 = 0 ; V_186 < V_187 ; ++ V_186 ) {
if ( ( V_186 & ( sizeof( long ) - 1 ) ) == 0 && V_186 > 0 )
putchar ( ' ' ) ;
if ( V_186 < V_188 )
printf ( L_141 , V_189 [ V_186 ] ) ;
else
printf ( L_142 , V_182 [ V_175 ] ) ;
}
for (; V_186 < 16 ; ++ V_186 ) {
if ( ( V_186 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_62 ) ;
}
printf ( L_161 ) ;
for ( V_186 = 0 ; V_186 < V_187 ; ++ V_186 ) {
if ( V_186 < V_188 ) {
V_184 = V_189 [ V_186 ] ;
putchar ( ' ' <= V_184 && V_184 <= '~' ? V_184 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_146 -= V_187 ;
for (; V_186 < 16 ; ++ V_186 )
putchar ( ' ' ) ;
printf ( L_162 ) ;
if ( V_188 < V_187 )
break;
}
}
static int
F_155 ( unsigned long V_246 , long V_247 , int V_248 ,
T_3 V_249 )
{
int V_188 , V_250 ;
unsigned long V_251 ;
unsigned long V_252 , V_253 = 0 ;
unsigned char V_157 [ 4 ] ;
V_250 = 0 ;
for ( V_251 = V_246 ; V_247 > 0 ; -- V_247 , V_246 += 4 ) {
V_188 = F_73 ( V_246 , V_157 , 4 ) ;
if ( V_188 == 0 ) {
if ( V_248 ) {
const char * V_254 = V_182 [ V_175 ] ;
printf ( V_105 L_163 , V_246 , V_254 , V_254 , V_254 , V_254 ) ;
}
break;
}
V_252 = F_156 ( V_157 ) ;
if ( V_246 > V_251 && V_252 == V_253 ) {
if ( ! V_250 ) {
printf ( L_164 ) ;
V_250 = 1 ;
}
continue;
}
V_250 = 0 ;
V_253 = V_252 ;
if ( V_248 )
printf ( V_105 L_165 , V_246 , V_252 ) ;
printf ( L_166 ) ;
V_249 ( V_252 , V_246 ) ;
printf ( L_34 ) ;
}
return V_246 - V_251 ;
}
static int
F_46 ( unsigned long V_246 , long V_247 , int V_248 )
{
return F_155 ( V_246 , V_247 , V_248 , V_255 ) ;
}
void
F_157 ( unsigned long V_6 )
{
F_37 ( V_6 , L_167 , L_86 ) ;
}
void
F_153 ( void )
{
struct V_256 V_257 = { . V_258 = 1 } ;
unsigned char V_169 [ 128 ] ;
T_4 V_80 ;
if ( setjmp ( V_40 ) != 0 ) {
printf ( L_168 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
F_158 ( & V_257 ) ;
F_151 () ;
while ( F_159 ( & V_257 , false , V_169 , sizeof( V_169 ) , & V_80 ) ) {
V_169 [ V_80 ] = '\0' ;
printf ( L_142 , V_169 ) ;
}
F_152 () ;
F_3 () ;
F_126 ( 200 ) ;
V_65 = 0 ;
}
static void F_2 ( void )
{
unsigned char V_169 [ 128 ] ;
T_5 V_259 ;
T_6 V_260 = 0 ;
if ( ! F_160 ( V_261 ) ) {
printf ( L_1 ) ;
return;
}
if ( setjmp ( V_40 ) != 0 ) {
printf ( L_169 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
F_151 () ;
while ( ( V_259 = F_161 ( V_169 , V_260 , sizeof( V_169 ) - 1 ) ) ) {
if ( V_259 < 0 ) {
printf ( L_170 , V_259 ) ;
break;
}
V_169 [ V_259 ] = '\0' ;
printf ( L_142 , V_169 ) ;
V_260 += V_259 ;
}
F_152 () ;
F_3 () ;
F_126 ( 200 ) ;
V_65 = 0 ;
}
static void
F_86 ( int V_27 )
{
F_79 ( ( void * ) & V_262 ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_79 ( ( void * ) ( V_27 == 's' ? & V_263 : & V_264 ) ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_79 ( ( void * ) & V_265 ) ;
switch( V_27 ) {
case 'm' :
memmove ( ( void * ) V_262 , ( void * ) V_264 , V_265 ) ;
break;
case 's' :
memset ( ( void * ) V_262 , V_263 , V_265 ) ;
break;
case 'd' :
if( V_87 != '\n' )
V_87 = 0 ;
F_79 ( ( void * ) & V_266 ) ;
F_162 ( ( unsigned char * ) V_262 , ( unsigned char * ) V_264 , V_265 , V_266 ) ;
break;
}
}
static void
F_162 ( unsigned char * V_267 , unsigned char * V_268 , unsigned V_269 , unsigned V_270 )
{
unsigned V_146 , V_271 ;
V_271 = 0 ;
for( V_146 = V_269 ; V_146 > 0 ; -- V_146 )
if( * V_267 ++ != * V_268 ++ )
if( ++ V_271 <= V_270 )
printf ( L_171 , V_267 - 1 ,
V_267 [ - 1 ] , V_268 - 1 , V_268 [ - 1 ] ) ;
if( V_271 > V_270 )
printf ( L_172 , V_271 ) ;
}
static void
F_87 ( void )
{
unsigned V_72 , V_146 ;
unsigned char V_157 [ 4 ] ;
V_82 = L_173 ;
F_79 ( ( void * ) & V_262 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_79 ( ( void * ) & V_272 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_79 ( ( void * ) & V_263 ) ;
V_273 = ~ 0 ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_79 ( ( void * ) & V_273 ) ;
}
}
V_146 = 0 ;
for ( V_72 = V_262 ; V_72 < V_272 ; V_72 += 4 ) {
if ( F_73 ( V_72 , V_157 , 4 ) == 4
&& ( ( F_156 ( V_157 ) ^ V_263 ) & V_273 ) == 0 ) {
printf ( L_174 , V_72 , F_156 ( V_157 ) ) ;
if ( ++ V_146 >= 10 )
break;
}
}
}
static void
F_88 ( void )
{
unsigned char V_102 ;
unsigned V_72 ;
int V_156 , V_274 ;
F_79 ( & V_262 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_79 ( & V_275 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_79 ( & V_276 ) ;
V_274 = 0 ;
for ( V_72 = V_262 ; V_72 < V_276 ; V_72 += V_275 ) {
V_156 = F_73 ( V_72 , & V_102 , 1 ) ;
if ( V_156 && ! V_274 ) {
printf ( L_175 , V_72 ) ;
} else if ( ! V_156 && V_274 )
printf ( L_176 , V_72 - V_275 ) ;
V_274 = V_156 ;
if ( V_72 + V_275 < V_72 )
break;
}
if ( V_274 )
printf ( L_176 , V_72 - V_275 ) ;
}
static void F_163 ( struct V_277 * V_278 )
{
char V_279 ;
V_279 = ( V_278 -> V_279 == 0 ) ? 'R' :
( V_278 -> V_279 < 0 ) ? 'U' :
( V_278 -> V_279 & V_280 ) ? 'D' :
( V_278 -> V_279 & V_281 ) ? 'T' :
( V_278 -> V_279 & V_282 ) ? 'C' :
( V_278 -> V_283 & V_284 ) ? 'Z' :
( V_278 -> V_283 & V_285 ) ? 'E' :
( V_278 -> V_279 & V_286 ) ? 'S' : '?' ;
printf ( L_177 , V_278 ,
V_278 -> V_287 . V_288 ,
V_278 -> V_143 , V_278 -> V_289 -> V_143 ,
V_279 , F_164 ( V_278 ) -> V_34 ,
V_278 -> V_144 ) ;
}
static void F_106 ( void )
{
unsigned long V_290 ;
struct V_277 * V_278 = NULL ;
printf ( L_178 ) ;
if ( F_79 ( & V_290 ) )
V_278 = (struct V_277 * ) V_290 ;
if ( setjmp ( V_40 ) != 0 ) {
V_65 = 0 ;
printf ( L_179 , V_278 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
if ( V_278 )
F_163 ( V_278 ) ;
else
F_165 (tsk)
F_163 ( V_278 ) ;
F_3 () ;
F_126 ( 200 ) ;
V_65 = 0 ;
}
static void F_105 ( void )
{
unsigned long args [ 8 ] ;
unsigned long V_111 ;
int V_67 ;
typedef unsigned long (* T_7)( unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long ,
unsigned long , unsigned long , unsigned long );
T_7 V_291 ;
if ( ! F_79 ( & V_103 ) )
return;
if ( V_87 != '\n' )
V_87 = 0 ;
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 )
args [ V_67 ] = 0 ;
for ( V_67 = 0 ; V_67 < 8 ; ++ V_67 ) {
if ( ! F_79 ( & args [ V_67 ] ) || V_87 == '\n' )
break;
V_87 = 0 ;
}
V_291 = ( T_7 ) V_103 ;
V_111 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_111 = V_291 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_3 () ;
printf ( L_180 , V_111 ) ;
} else {
printf ( L_181 , V_174 ) ;
}
V_65 = 0 ;
}
int
F_83 ( void )
{
int V_184 ;
if( V_87 != 0 ) {
V_184 = V_87 ;
V_87 = 0 ;
} else
V_184 = F_85 () ;
while( V_184 == ' ' || V_184 == '\t' )
V_184 = F_85 () ;
return V_184 ;
}
int
F_79 ( unsigned long * V_155 )
{
int V_184 , V_60 ;
unsigned long V_102 ;
V_184 = F_83 () ;
if ( V_184 == '%' ) {
char V_292 [ 8 ] ;
int V_67 ;
for ( V_67 = 0 ; V_67 < sizeof( V_292 ) - 1 ; ++ V_67 ) {
V_184 = F_85 () ;
if ( ! isalnum ( V_184 ) ) {
V_87 = V_184 ;
break;
}
V_292 [ V_67 ] = V_184 ;
}
V_292 [ V_67 ] = 0 ;
for ( V_67 = 0 ; V_67 < V_293 ; ++ V_67 ) {
if ( strcmp ( V_294 [ V_67 ] , V_292 ) == 0 ) {
if ( V_83 == NULL ) {
printf ( L_182 ) ;
return 0 ;
}
* V_155 = ( ( unsigned long * ) V_83 ) [ V_67 ] ;
return 1 ;
}
}
printf ( L_183 , V_292 ) ;
return 0 ;
}
if ( V_184 == '0' ) {
V_184 = F_85 () ;
if ( V_184 == 'x' ) {
V_184 = F_85 () ;
} else {
V_60 = F_166 ( V_184 ) ;
if ( V_60 == V_57 ) {
V_87 = V_184 ;
* V_155 = 0 ;
return 1 ;
}
}
} else if ( V_184 == '$' ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < 63 ; V_67 ++ ) {
V_184 = F_85 () ;
if ( isspace ( V_184 ) || V_184 == '\0' ) {
V_87 = V_184 ;
break;
}
V_116 [ V_67 ] = V_184 ;
}
V_116 [ V_67 ++ ] = 0 ;
* V_155 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
* V_155 = F_167 ( V_116 ) ;
F_3 () ;
}
V_65 = 0 ;
if ( ! ( * V_155 ) ) {
printf ( L_184 , V_116 ) ;
return 0 ;
}
return 1 ;
}
V_60 = F_166 ( V_184 ) ;
if ( V_60 == V_57 ) {
V_87 = V_184 ;
return 0 ;
}
V_102 = 0 ;
do {
V_102 = ( V_102 << 4 ) + V_60 ;
V_184 = F_85 () ;
V_60 = F_166 ( V_184 ) ;
} while ( V_60 != V_57 );
V_87 = V_184 ;
* V_155 = V_102 ;
return 1 ;
}
static void
F_119 ( void )
{
int V_184 ;
V_184 = V_87 ;
V_87 = 0 ;
while( V_184 != '\n' )
V_184 = F_85 () ;
}
static int F_166 ( int V_184 )
{
if( '0' <= V_184 && V_184 <= '9' )
return V_184 - '0' ;
if( 'A' <= V_184 && V_184 <= 'F' )
return V_184 - ( 'A' - 10 ) ;
if( 'a' <= V_184 && V_184 <= 'f' )
return V_184 - ( 'a' - 10 ) ;
return V_57 ;
}
void
F_168 ( char * V_295 , int V_114 )
{
int V_184 ;
V_184 = F_83 () ;
do {
if( V_114 > 1 ) {
* V_295 ++ = V_184 ;
-- V_114 ;
}
V_184 = F_85 () ;
} while( V_184 != ' ' && V_184 != '\t' && V_184 != '\n' );
V_87 = V_184 ;
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
if ( F_169 ( line , sizeof( line ) ) == NULL ) {
V_296 = NULL ;
return V_57 ;
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
V_87 = 0 ;
break;
case 's' :
F_168 ( V_298 , 64 ) ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_6 = F_167 ( V_298 ) ;
if ( V_6 )
printf ( L_185 , V_298 , V_6 ) ;
else
printf ( L_186 , V_298 ) ;
F_3 () ;
}
V_65 = 0 ;
V_87 = 0 ;
break;
}
}
static void F_37 ( unsigned long V_37 , const char * V_299 ,
const char * V_300 )
{
char * V_301 ;
const char * V_115 = NULL ;
unsigned long V_32 , V_114 ;
printf ( V_105 , V_37 ) ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_115 = F_118 ( V_37 , & V_114 , & V_32 , & V_301 ,
V_116 ) ;
F_3 () ;
F_126 ( 200 ) ;
}
V_65 = 0 ;
if ( V_115 ) {
printf ( L_187 , V_299 , V_115 , V_32 , V_114 ) ;
if ( V_301 )
printf ( L_188 , V_301 ) ;
}
printf ( L_142 , V_300 ) ;
}
void F_108 ( void )
{
int V_67 ;
unsigned long V_206 , V_207 ;
unsigned long V_302 ;
printf ( L_189 , F_16 () ) ;
for ( V_67 = 0 ; V_67 < V_303 ; V_67 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( V_206 || V_207 ) {
printf ( L_190 , V_67 , V_206 , V_207 ) ;
if ( V_206 & V_304 ) {
V_302 = V_207 & V_305 ;
if ( V_207 & V_306 ) {
printf ( L_191 ,
F_170 ( V_206 ) ,
( V_207 & ~ V_307 ) >> V_308 ,
V_302 ) ;
} else {
printf ( L_192 ,
F_171 ( V_206 ) ,
( V_207 & ~ V_307 ) >> V_309 ,
V_302 ) ;
}
} else
printf ( L_34 ) ;
}
}
}
void F_108 ( void )
{
int V_67 ;
printf ( L_193 ) ;
for ( V_67 = 0 ; V_67 < 16 ; ++ V_67 )
printf ( L_194 , F_172 ( V_67 ) ) ;
printf ( L_34 ) ;
}
static void F_109 ( void )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_310 ; V_67 ++ ) {
unsigned long V_311 , V_312 , V_313 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_195 , V_67 , V_311 , V_312 , V_313 ) ;
if ( V_311 & V_314 ) {
printf ( L_196 ,
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
V_172 V_323 , V_324 , V_325 ;
V_173 V_326 ;
int V_67 , V_327 , V_328 , V_329 , V_330 , V_331 , V_332 = 0 ;
int V_333 ;
static const char * V_334 [] = {
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
L_226 ,
L_227 ,
L_228 ,
} ;
V_323 = F_111 ( V_335 ) ;
V_333 = ( V_323 & 3 ) + 1 ;
V_328 = ( ( V_323 >> 2 ) & 3 ) + 1 ;
V_329 = ( ( V_323 >> 6 ) & 0x1f ) + 1 ;
V_330 = ( V_323 >> 24 ) & 0xf ;
V_331 = ( V_323 >> 16 ) & 0x7f ;
if ( ( V_333 > 1 ) && ( V_323 & 0x10000 ) )
V_332 = 1 ;
printf ( L_229 ,
V_333 , V_328 , V_329 , V_330 , V_331 ) ;
V_324 = ( 1ul << V_329 ) - 1 ;
V_325 = ( 1ul << V_330 ) - 1 ;
V_326 = ( 1ull << V_331 ) - 1 ;
for ( V_327 = 0 ; V_327 < V_328 ; V_327 ++ ) {
V_172 V_336 ;
int V_337 , V_338 , V_339 = 1 ;
printf ( L_230 , V_327 ) ;
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
printf ( L_231 ) ;
continue;
}
V_337 = V_336 & 0xfff ;
V_338 = ( V_336 >> 24 ) & 0xff ;
for ( V_67 = 0 ; V_67 < V_337 ; V_67 ++ ) {
V_172 V_344 = F_173 ( V_327 ) ;
V_172 V_345 = F_174 ( V_346 ) ;
V_173 V_347 = 0 ;
V_173 V_348 ;
int V_349 = V_67 , V_350 = V_67 ;
if ( V_338 != 0 ) {
V_350 = V_67 / V_338 ;
V_349 = V_67 % V_338 ;
V_347 = V_350 * 0x1000 ;
}
V_344 |= F_175 ( V_349 ) ;
F_9 ( V_351 , V_344 ) ;
F_9 ( V_352 , V_345 ) ;
F_9 ( V_353 , V_347 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_345 = F_111 ( V_352 ) ;
V_347 = F_111 ( V_353 ) ;
V_348 = F_111 ( V_354 ) ;
if ( V_338 && ( V_67 % V_338 ) == 0 )
V_339 = 1 ;
if ( ! ( V_345 & V_355 ) )
continue;
if ( V_338 == 0 )
printf ( L_232 , V_67 ) ;
else if ( V_339 )
printf ( L_233 , V_350 , 'A' + V_349 ) ;
else
printf ( L_234 , 'A' + V_349 ) ;
V_339 = 0 ;
printf ( L_235 ,
V_347 & ~ 0x3ffull ,
( V_345 >> 16 ) & 0x3fff ,
V_334 [ ( V_345 >> 7 ) & 0x1f ] ,
V_345 & V_356 ? 'I' : ' ' ,
V_345 & V_357 ? 'P' : ' ' ,
V_345 & V_358 ? '1' : '0' ) ;
printf ( L_236 ,
V_347 & V_359 ? 'a' : ' ' ,
V_347 & V_360 ? 'v' : ' ' ,
V_347 & V_361 ? 'w' : ' ' ,
V_347 & V_362 ? 'i' : ' ' ,
V_347 & V_363 ? 'm' : ' ' ,
V_347 & V_364 ? 'g' : ' ' ,
V_347 & V_365 ? 'e' : ' ' ) ;
printf ( L_237 , V_348 & V_326 & ~ 0x7ffull ) ;
if ( V_345 & V_356 )
printf ( L_238 ,
V_334 [ ( V_348 >> 1 ) & 0x1f ] ) ;
else
printf ( L_239 ,
V_348 & V_366 ? 'x' : ' ' ,
V_348 & V_367 ? 'w' : ' ' ,
V_348 & V_368 ? 'r' : ' ' ,
V_348 & V_369 ? 'x' : ' ' ,
V_348 & V_370 ? 'w' : ' ' ,
V_348 & V_371 ? 'r' : ' ' ) ;
}
}
}
static void F_176 ( int V_372 )
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
static void F_177 ( int V_380 )
{
F_176 ( 1 ) ;
F_178 ( F_61 () ) ;
}
static int T_8 F_179 ( void )
{
F_180 ( 'x' , & V_381 ) ;
return 0 ;
}
static int T_8 F_181 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_240 , 5 ) == 0 ) {
F_176 ( 1 ) ;
V_382 = 1 ;
} else if ( strncmp ( V_2 , L_241 , 2 ) == 0 )
F_176 ( 1 ) ;
else if ( strncmp ( V_2 , L_242 , 3 ) == 0 )
V_383 = 1 ;
else if ( strncmp ( V_2 , L_243 , 4 ) == 0 )
V_84 = 1 ;
else
return 1 ;
return 0 ;
}
void T_8 F_182 ( void )
{
#ifdef F_183
if ( ! V_383 )
F_176 ( 1 ) ;
#endif
if ( V_382 )
F_178 ( NULL ) ;
}
void F_184 ( struct V_384 * V_385 )
{
struct V_386 * V_386 ;
F_185 (spu, list, full_list) {
if ( V_386 -> V_387 >= V_388 ) {
F_186 ( 1 ) ;
continue;
}
V_389 [ V_386 -> V_387 ] . V_386 = V_386 ;
V_389 [ V_386 -> V_387 ] . V_390 = 0 ;
V_389 [ V_386 -> V_387 ] . V_391 = ( unsigned long )
V_389 [ V_386 -> V_387 ] . V_386 -> V_392 ;
}
}
static void F_187 ( void )
{
struct V_386 * V_386 ;
int V_67 ;
V_173 V_298 ;
for ( V_67 = 0 ; V_67 < V_388 ; V_67 ++ ) {
if ( ! V_389 [ V_67 ] . V_386 )
continue;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_386 = V_389 [ V_67 ] . V_386 ;
V_389 [ V_67 ] . V_393 =
F_188 ( & V_386 -> V_394 -> V_395 ) ;
V_298 = F_189 ( V_386 ) ;
V_389 [ V_67 ] . V_396 = V_298 ;
V_298 &= ~ V_397 ;
F_190 ( V_386 , V_298 ) ;
F_3 () ;
F_126 ( 200 ) ;
V_389 [ V_67 ] . V_390 = 1 ;
printf ( L_244 , V_67 ,
V_389 [ V_67 ] . V_393 ?
L_245 : L_246 ) ;
} else {
V_65 = 0 ;
printf ( L_247 , V_67 ) ;
}
V_65 = 0 ;
}
}
static void F_191 ( void )
{
struct V_386 * V_386 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_388 ; V_67 ++ ) {
if ( ! V_389 [ V_67 ] . V_386 )
continue;
if ( ! V_389 [ V_67 ] . V_390 ) {
printf ( L_248
L_249 , V_67 ) ;
continue;
}
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_386 = V_389 [ V_67 ] . V_386 ;
F_190 ( V_386 , V_389 [ V_67 ] . V_396 ) ;
F_192 ( & V_386 -> V_394 -> V_395 ,
V_389 [ V_67 ] . V_393 ) ;
F_3 () ;
F_126 ( 200 ) ;
printf ( L_250 , V_67 ) ;
} else {
V_65 = 0 ;
printf ( L_251 , V_67 ) ;
}
V_65 = 0 ;
}
}
static void F_193 ( struct V_386 * V_386 )
{
printf ( L_252 , V_386 ) ;
F_194 ( V_386 , L_253 , V_387 ) ;
F_194 ( V_386 , L_142 , V_115 ) ;
F_194 ( V_386 , L_254 , V_398 ) ;
F_194 ( V_386 , L_255 , V_392 ) ;
F_194 ( V_386 , L_254 , V_399 ) ;
F_194 ( V_386 , L_253 , V_400 ) ;
F_194 ( V_386 , L_254 , V_33 ) ;
F_194 ( V_386 , L_256 , V_401 ) ;
F_194 ( V_386 , L_254 , V_402 ) ;
F_194 ( V_386 , L_254 , V_403 ) ;
F_194 ( V_386 , L_254 , V_404 ) ;
F_194 ( V_386 , L_254 , V_405 [ 0 ] ) ;
F_194 ( V_386 , L_254 , V_405 [ 1 ] ) ;
F_194 ( V_386 , L_254 , V_405 [ 2 ] ) ;
F_194 ( V_386 , L_253 , V_406 ) ;
F_194 ( V_386 , L_256 , V_143 ) ;
F_194 ( V_386 , L_255 , V_407 ) ;
F_194 ( V_386 , L_255 , V_408 ) ;
F_194 ( V_386 , L_255 , V_409 ) ;
F_194 ( V_386 , L_255 , V_410 ) ;
F_194 ( V_386 , L_254 , V_411 ) ;
F_194 ( V_386 , L_255 , V_394 ) ;
F_195 ( L_253 , V_394 -> V_395 ,
F_188 ( & V_386 -> V_394 -> V_395 ) ) ;
F_195 ( L_253 , V_394 -> V_412 ,
F_188 ( & V_386 -> V_394 -> V_412 ) ) ;
F_195 ( L_253 , V_394 -> V_413 ,
F_188 ( & V_386 -> V_394 -> V_413 ) ) ;
F_194 ( V_386 , L_255 , V_414 ) ;
F_194 ( V_386 , L_255 , V_415 ) ;
}
int
F_196 ( unsigned long V_246 , long V_247 , int V_248 )
{
return F_155 ( V_246 , V_247 , V_248 , V_416 ) ;
}
static void F_197 ( unsigned long V_243 , int V_417 )
{
unsigned long V_32 , V_6 , V_418 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_418 = ( unsigned long ) V_389 [ V_243 ] . V_386 -> V_392 ;
F_3 () ;
F_126 ( 200 ) ;
} else {
V_65 = 0 ;
printf ( L_257 , V_243 ) ;
return;
}
V_65 = 0 ;
if ( F_79 ( & V_32 ) )
V_6 = V_418 + V_32 ;
else
V_6 = V_389 [ V_243 ] . V_391 ;
if ( V_6 >= V_418 + V_419 ) {
printf ( L_258 ) ;
return;
}
switch ( V_417 ) {
case 'i' :
V_6 += F_196 ( V_6 , 16 , 1 ) ;
V_82 = L_259 ;
break;
default:
F_154 ( V_6 , 64 ) ;
V_6 += 64 ;
V_82 = L_260 ;
break;
}
V_389 [ V_243 ] . V_391 = V_6 ;
}
static int F_97 ( void )
{
static unsigned long V_243 = 0 ;
int V_27 , V_417 = 0 ;
V_27 = F_85 () ;
switch ( V_27 ) {
case 's' :
F_187 () ;
break;
case 'r' :
F_191 () ;
break;
case 'd' :
V_417 = F_85 () ;
if ( isxdigit ( V_417 ) || V_417 == '\n' )
V_87 = V_417 ;
case 'f' :
F_79 ( & V_243 ) ;
if ( V_243 >= V_388 || ! V_389 [ V_243 ] . V_386 ) {
printf ( L_261 ) ;
return 0 ;
}
switch ( V_27 ) {
case 'f' :
F_193 ( V_389 [ V_243 ] . V_386 ) ;
break;
default:
F_197 ( V_243 , V_417 ) ;
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
