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
F_89 ( 0 , NULL ) ;
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
if ( ! F_115 ( V_117 ) ) {
if ( V_117 != 0 )
printf ( L_87 , V_117 ) ;
break;
}
if ( ! F_73 ( V_117 + V_123 , & V_120 , sizeof( unsigned long ) )
|| ! F_73 ( V_117 , & V_121 , sizeof( unsigned long ) ) ) {
printf ( L_88 , V_117 ) ;
break;
}
if ( ( V_66 | V_118 ) != 0 ) {
unsigned long V_124 , V_125 ;
unsigned long V_126 ;
int V_127 = 1 ;
F_117 ( V_66 , & V_124 , & V_125 ) ;
V_126 = 0 ;
if ( V_121 > V_117 )
F_73 ( V_121 + V_123 , & V_126 ,
sizeof( unsigned long ) ) ;
if ( V_118 == V_120 ) {
if ( ! F_115 ( V_118 )
|| ( V_124 <= V_118 && V_118 < V_125 ) )
V_127 = 0 ;
} else if ( V_118 == V_126 ) {
V_127 = 0 ;
} else if ( F_115 ( V_118 )
&& ! ( V_124 <= V_118 && V_118 < V_125 ) ) {
printf ( L_89 ) ;
F_37 ( V_118 , L_8 , L_34 ) ;
}
if ( V_127 ) {
printf ( L_90 V_105 L_91 , V_117 ) ;
F_37 ( V_120 , L_8 , L_92 ) ;
}
V_66 = V_118 = 0 ;
} else {
printf ( L_90 V_105 L_91 , V_117 ) ;
F_37 ( V_120 , L_8 , L_34 ) ;
}
if ( F_73 ( V_117 + V_128 , & V_122 , sizeof( unsigned long ) )
&& V_122 == V_129 ) {
if ( F_73 ( V_117 + V_130 , & V_21 , sizeof( V_21 ) )
!= sizeof( V_21 ) ) {
printf ( L_93 ,
V_117 + V_130 ) ;
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
const struct V_131 * V_132 ;
unsigned long V_6 ;
if ( V_21 -> V_24 & V_50 )
return;
V_6 = V_21 -> V_36 ;
if ( ! F_115 ( V_6 ) )
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
unsigned long V_41 ;
#ifdef F_25
printf ( L_97 , F_16 () ) ;
#endif
V_41 = F_34 ( V_135 ) ;
printf ( L_98 , V_135 -> V_41 , F_33 ( V_41 ) , V_135 ) ;
printf ( L_99 ) ;
F_37 ( V_135 -> V_36 , L_100 , L_34 ) ;
printf ( L_101 , V_135 -> V_86 ) ;
F_37 ( V_135 -> V_86 , L_100 , L_34 ) ;
printf ( L_102 , V_135 -> V_85 [ 1 ] ) ;
printf ( L_103 , V_135 -> V_24 ) ;
if ( V_41 == 0x300 || V_41 == 0x380 || V_41 == 0x600 || V_41 == 0x200 ) {
printf ( L_104 , V_135 -> V_136 ) ;
if ( V_41 != 0x380 )
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
if ( V_41 == 0x700 )
F_120 ( V_135 ) ;
printf ( V_144 ) ;
}
static void F_93 ( struct V_20 * V_135 )
{
int V_145 , V_41 ;
unsigned long V_146 ;
struct V_20 V_21 ;
if ( F_79 ( & V_146 ) ) {
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_21 = * (struct V_20 * ) V_146 ;
F_3 () ;
F_126 ( 200 ) ;
} else {
V_65 = 0 ;
printf ( L_109 V_105 L_34 ,
V_146 ) ;
return;
}
V_65 = 0 ;
V_135 = & V_21 ;
}
#ifdef F_125
if ( F_127 ( V_135 ) ) {
for ( V_145 = 0 ; V_145 < 16 ; ++ V_145 )
printf ( L_110 V_105 L_111 V_105 L_34 ,
V_145 , V_135 -> V_85 [ V_145 ] , V_145 + 16 , V_135 -> V_85 [ V_145 + 16 ] ) ;
} else {
for ( V_145 = 0 ; V_145 < 7 ; ++ V_145 )
printf ( L_110 V_105 L_111 V_105 L_34 ,
V_145 , V_135 -> V_85 [ V_145 ] , V_145 + 7 , V_135 -> V_85 [ V_145 + 7 ] ) ;
}
#else
for ( V_145 = 0 ; V_145 < 32 ; ++ V_145 ) {
printf ( L_112 , V_145 , V_135 -> V_85 [ V_145 ] ,
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
F_37 ( V_135 -> V_86 , L_8 , L_34 ) ;
printf ( L_117 V_105 L_118 , V_135 -> V_24 , V_135 -> V_149 ) ;
printf ( L_119 V_105 L_120 V_105 L_121 ,
V_135 -> V_150 , V_135 -> V_151 , V_135 -> V_41 ) ;
V_41 = F_34 ( V_135 ) ;
if ( V_41 == 0x300 || V_41 == 0x380 || V_41 == 0x600 )
printf ( L_122 V_105 L_123 , V_135 -> V_136 , V_135 -> V_137 ) ;
}
static void F_96 ( void )
{
int V_27 ;
unsigned long V_152 ;
V_27 = F_85 () ;
if ( V_27 != 'i' )
V_87 = V_27 ;
F_79 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
V_152 = 1 ;
F_79 ( & V_152 ) ;
V_152 = ( V_152 + V_153 - 1 ) / V_153 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
if ( V_27 != 'i' ) {
for (; V_152 > 0 ; -- V_152 , V_103 += V_153 )
F_5 ( ( void * ) V_103 ) ;
} else {
for (; V_152 > 0 ; -- V_152 , V_103 += V_153 )
F_6 ( ( void * ) V_103 ) ;
}
F_3 () ;
F_126 ( 200 ) ;
}
V_65 = 0 ;
}
static int
F_128 ( int V_145 , unsigned long * V_154 )
{
unsigned long V_111 = - 1UL ;
int V_155 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_39 = 1 ;
F_3 () ;
V_111 = F_129 ( V_145 , * V_154 ) ;
F_3 () ;
* V_154 = V_111 ;
V_155 = 1 ;
}
V_39 = 0 ;
return V_155 ;
}
static void
F_130 ( int V_145 , unsigned long V_156 )
{
if ( setjmp ( V_40 ) == 0 ) {
V_39 = 1 ;
F_3 () ;
F_131 ( V_145 , V_156 ) ;
F_3 () ;
} else {
printf ( L_124 , V_145 , V_145 ) ;
}
V_39 = 0 ;
}
static void F_132 ( void )
{
#ifdef F_125
if ( ! F_8 ( V_157 ) )
return;
printf ( L_125 ,
F_111 ( V_158 ) , F_111 ( V_159 ) , F_111 ( V_160 ) ) ;
printf ( L_126 ,
F_111 ( V_161 ) , F_111 ( V_162 ) , F_111 ( V_163 ) ) ;
if ( ! ( F_133 () & V_164 ) )
return;
printf ( L_127 ,
F_111 ( V_165 ) , F_111 ( V_166 ) , F_111 ( V_167 ) ) ;
printf ( L_128 ,
F_111 ( V_168 ) , F_111 ( V_169 ) , F_111 ( V_170 ) ) ;
printf ( L_129 ,
F_111 ( V_171 ) , F_111 ( V_172 ) , F_111 ( V_173 ) ) ;
printf ( L_130 ,
F_111 ( V_174 ) , F_111 ( V_175 ) ) ;
printf ( L_131 ,
F_111 ( V_176 ) , F_111 ( V_177 ) ) ;
#endif
}
static void F_134 ( void )
{
#ifdef F_125
unsigned long V_24 ;
if ( ! F_8 ( V_3 ) )
return;
printf ( L_132 ,
F_111 ( V_178 ) , F_111 ( V_179 ) , F_111 ( V_180 ) ) ;
printf ( L_133 ,
F_111 ( V_181 ) , F_111 ( V_182 ) , F_111 ( V_183 ) ) ;
V_24 = F_133 () ;
if ( V_24 & V_184 ) {
printf ( L_134 ,
F_111 ( V_185 ) , F_111 ( V_186 ) ,
F_111 ( V_187 ) ) ;
}
printf ( L_135 ,
F_111 ( V_188 ) , F_111 ( V_189 ) , F_111 ( V_190 ) ) ;
printf ( L_136 ,
F_111 ( V_191 ) , F_111 ( V_192 ) ,
F_111 ( V_193 ) , F_111 ( V_194 ) ) ;
printf ( L_137 ,
F_111 ( V_195 ) , F_111 ( V_196 ) , F_111 ( V_197 ) ) ;
printf ( L_138 ,
F_111 ( V_198 ) , F_111 ( V_199 ) , F_111 ( V_200 ) ) ;
printf ( L_139 ,
F_111 ( V_201 ) , F_111 ( V_202 ) , F_111 ( V_203 ) ) ;
if ( ! ( V_24 & V_164 ) )
return;
printf ( L_140 ,
F_111 ( V_204 ) , F_111 ( V_205 ) , F_111 ( V_206 ) ) ;
printf ( L_141 ,
F_111 ( V_207 ) , F_111 ( V_208 ) , F_111 ( V_5 ) ) ;
#endif
}
static void F_135 ( int V_209 , bool V_210 )
{
unsigned long V_156 ;
V_156 = 0xdeadbeef ;
if ( ! F_128 ( V_209 , & V_156 ) ) {
printf ( L_142 , V_209 , V_209 ) ;
return;
}
if ( V_156 == 0xdeadbeef ) {
V_156 = 0x0badcafe ;
if ( ! F_128 ( V_209 , & V_156 ) ) {
printf ( L_142 , V_209 , V_209 ) ;
return;
}
if ( V_156 == 0x0badcafe ) {
if ( V_210 )
printf ( L_143 , V_209 , V_209 ) ;
return;
}
}
printf ( L_144 , V_209 , V_209 , V_156 ) ;
}
static void F_94 ( void )
{
static unsigned long V_211 ;
int V_27 ;
int V_209 ;
V_27 = F_83 () ;
switch ( V_27 ) {
case '\n' : {
unsigned long V_117 , V_212 ;
asm("mr %0,1" : "=r" (sp) :);
asm("mr %0,2" : "=r" (toc) :);
printf ( L_145 V_105 L_146 V_105 L_34 ,
F_133 () , F_111 ( V_213 ) ) ;
printf ( L_147 V_105 L_148 V_105 L_34 ,
F_111 ( V_214 ) , F_111 ( V_215 ) ) ;
printf ( L_149 V_105 L_150 V_105 L_34 ,
F_111 ( V_216 ) , F_111 ( V_217 ) ) ;
printf ( L_151 V_105 L_152 V_105 L_34 , V_117 , F_111 ( V_218 ) ) ;
printf ( L_153 V_105 L_154 V_105 L_34 , V_212 , F_111 ( V_219 ) ) ;
F_132 () ;
F_134 () ;
return;
}
case 'w' : {
unsigned long V_156 ;
F_79 ( & V_211 ) ;
V_156 = 0 ;
F_128 ( V_211 , & V_156 ) ;
F_79 ( & V_156 ) ;
F_130 ( V_211 , V_156 ) ;
F_135 ( V_211 , true ) ;
break;
}
case 'r' :
F_79 ( & V_211 ) ;
F_135 ( V_211 , true ) ;
break;
case 'a' :
for ( V_209 = 1 ; V_209 < 1024 ; ++ V_209 )
F_135 ( V_209 , false ) ;
break;
}
F_119 () ;
}
static int
F_73 ( unsigned long V_103 , void * V_220 , int V_114 )
{
volatile int V_145 ;
char * V_2 , * V_221 ;
V_145 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_2 = ( char * ) V_103 ;
V_221 = ( char * ) V_220 ;
switch ( V_114 ) {
case 2 :
* ( V_222 * ) V_221 = * ( V_222 * ) V_2 ;
break;
case 4 :
* ( V_223 * ) V_221 = * ( V_223 * ) V_2 ;
break;
case 8 :
* ( V_224 * ) V_221 = * ( V_224 * ) V_2 ;
break;
default:
for( ; V_145 < V_114 ; ++ V_145 ) {
* V_221 ++ = * V_2 ++ ;
F_3 () ;
}
}
F_3 () ;
F_126 ( 200 ) ;
V_145 = V_114 ;
}
V_65 = 0 ;
return V_145 ;
}
static int
F_75 ( unsigned long V_103 , void * V_220 , int V_114 )
{
volatile int V_145 ;
char * V_2 , * V_221 ;
V_145 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_2 = ( char * ) V_103 ;
V_221 = ( char * ) V_220 ;
switch ( V_114 ) {
case 2 :
* ( V_222 * ) V_2 = * ( V_222 * ) V_221 ;
break;
case 4 :
* ( V_223 * ) V_2 = * ( V_223 * ) V_221 ;
break;
case 8 :
* ( V_224 * ) V_2 = * ( V_224 * ) V_221 ;
break;
default:
for ( ; V_145 < V_114 ; ++ V_145 ) {
* V_2 ++ = * V_221 ++ ;
F_3 () ;
}
}
F_3 () ;
F_126 ( 200 ) ;
V_145 = V_114 ;
} else {
printf ( L_155 V_105 L_34 , V_103 + V_145 ) ;
}
V_65 = 0 ;
return V_145 ;
}
static int F_69 ( struct V_20 * V_21 )
{
V_225 = F_34 ( V_21 ) ;
switch ( F_34 ( V_21 ) ) {
case 0x200 :
V_226 = 0 ;
break;
case 0x300 :
case 0x380 :
V_226 = 1 ;
break;
default:
V_226 = 2 ;
}
longjmp ( V_40 , 1 ) ;
return 0 ;
}
static void
F_136 ( unsigned char * V_156 , int V_114 )
{
int V_227 ;
switch ( V_114 ) {
case 2 :
F_137 ( V_156 [ 0 ] , V_156 [ 1 ] , V_227 ) ;
break;
case 4 :
F_137 ( V_156 [ 0 ] , V_156 [ 3 ] , V_227 ) ;
F_137 ( V_156 [ 1 ] , V_156 [ 2 ] , V_227 ) ;
break;
case 8 :
F_137 ( V_156 [ 0 ] , V_156 [ 7 ] , V_227 ) ;
F_137 ( V_156 [ 1 ] , V_156 [ 6 ] , V_227 ) ;
F_137 ( V_156 [ 2 ] , V_156 [ 5 ] , V_227 ) ;
F_137 ( V_156 [ 3 ] , V_156 [ 4 ] , V_227 ) ;
break;
}
}
static void
F_90 ( void )
{
int V_27 , V_228 , V_67 , V_229 ;
unsigned long V_145 ;
unsigned char V_156 [ 16 ] ;
F_79 ( ( void * ) & V_103 ) ;
V_27 = F_83 () ;
if ( V_27 == '?' ) {
printf ( V_230 ) ;
return;
} else {
V_87 = V_27 ;
}
V_82 = L_156 ;
while ( ( V_27 = F_83 () ) != '\n' ) {
switch( V_27 ) {
case 'b' : V_114 = 1 ; break;
case 'w' : V_114 = 2 ; break;
case 'l' : V_114 = 4 ; break;
case 'd' : V_114 = 8 ; break;
case 'r' : V_231 = ! V_231 ; break;
case 'n' : V_232 = 1 ; break;
case '.' : V_232 = 0 ; break;
}
}
if( V_114 <= 0 )
V_114 = 1 ;
else if( V_114 > 8 )
V_114 = 8 ;
for(; ; ) {
if ( ! V_232 )
V_145 = F_73 ( V_103 , V_156 , V_114 ) ;
printf ( V_105 L_157 , V_103 , V_231 ? 'r' : ' ' ) ;
if ( ! V_232 ) {
if ( V_231 )
F_136 ( V_156 , V_114 ) ;
putchar ( ' ' ) ;
for ( V_67 = 0 ; V_67 < V_145 ; ++ V_67 )
printf ( L_158 , V_156 [ V_67 ] ) ;
for (; V_67 < V_114 ; ++ V_67 )
printf ( L_159 , V_233 [ V_226 ] ) ;
}
putchar ( ' ' ) ;
V_228 = V_114 ;
V_229 = 0 ;
for(; ; ) {
if( F_79 ( & V_145 ) ) {
for ( V_67 = 0 ; V_67 < V_114 ; ++ V_67 )
V_156 [ V_67 ] = V_145 >> ( V_67 * 8 ) ;
if ( ! V_231 )
F_136 ( V_156 , V_114 ) ;
F_75 ( V_103 , V_156 , V_114 ) ;
V_228 = V_114 ;
}
V_27 = F_83 () ;
if ( V_27 == '\n' )
break;
V_228 = 0 ;
switch ( V_27 ) {
case '\'' :
for(; ; ) {
V_145 = F_85 () ;
if( V_145 == '\\' )
V_145 = F_138 () ;
else if( V_145 == '\'' )
break;
for ( V_67 = 0 ; V_67 < V_114 ; ++ V_67 )
V_156 [ V_67 ] = V_145 >> ( V_67 * 8 ) ;
if ( ! V_231 )
F_136 ( V_156 , V_114 ) ;
F_75 ( V_103 , V_156 , V_114 ) ;
V_103 += V_114 ;
}
V_103 -= V_114 ;
V_228 = V_114 ;
break;
case ',' :
V_103 += V_114 ;
break;
case '.' :
V_232 = 0 ;
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
if ( V_229 > 0 )
V_103 -= 1 << V_229 ;
else
V_229 = 0 ;
V_229 += 4 ;
V_103 += 1 << V_229 ;
break;
case '\\' :
if ( V_229 < 0 )
V_103 += 1 << - V_229 ;
else
V_229 = 0 ;
V_229 -= 4 ;
V_103 -= 1 << - V_229 ;
break;
case 'm' :
F_79 ( ( void * ) & V_103 ) ;
break;
case 'n' :
V_232 = 1 ;
break;
case 'r' :
V_231 = ! V_231 ;
break;
case '<' :
V_145 = V_114 ;
F_79 ( & V_145 ) ;
V_103 -= V_145 ;
break;
case '>' :
V_145 = V_114 ;
F_79 ( & V_145 ) ;
V_103 += V_145 ;
break;
case '?' :
printf ( V_234 ) ;
break;
}
}
V_103 += V_228 ;
}
}
static int
F_138 ( void )
{
int V_235 ;
V_235 = F_85 () ;
switch( V_235 ) {
case 'n' : V_235 = '\n' ; break;
case 'r' : V_235 = '\r' ; break;
case 'b' : V_235 = '\b' ; break;
case 't' : V_235 = '\t' ; break;
}
return V_235 ;
}
static void F_139 ( unsigned long V_103 , long V_236 )
{
long V_145 , V_237 , V_238 , V_239 ;
unsigned char V_240 [ 16 ] ;
for ( V_145 = V_236 ; V_145 > 0 ; ) {
V_238 = V_145 < 16 ? V_145 : 16 ;
V_239 = F_73 ( V_103 , V_240 , V_238 ) ;
V_103 += V_239 ;
for ( V_237 = 0 ; V_237 < V_238 ; ++ V_237 ) {
if ( V_237 < V_239 )
printf ( L_158 , V_240 [ V_237 ] ) ;
else
printf ( L_159 , V_233 [ V_226 ] ) ;
}
V_145 -= V_238 ;
if ( V_239 < V_238 )
break;
}
printf ( L_34 ) ;
}
static void F_140 ( int V_34 )
{
struct V_241 * V_2 ;
#ifdef F_141
int V_67 = 0 ;
#endif
if ( setjmp ( V_40 ) != 0 ) {
printf ( L_160 , V_34 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
V_2 = & V_242 [ V_34 ] ;
printf ( L_161 , V_34 , V_2 ) ;
printf ( L_162 , 20 , L_163 , F_142 ( V_34 ) ? L_164 : L_165 ) ;
printf ( L_162 , 20 , L_166 , F_143 ( V_34 ) ? L_164 : L_165 ) ;
printf ( L_162 , 20 , L_167 , F_144 ( V_34 ) ? L_164 : L_165 ) ;
#define F_145 ( V_242 , V_115 , T_2 ) \
printf(" %-*s = %#-*"format"\t(0x%lx)\n", 20, #name, 18, paca->name, \
offsetof(struct paca_struct, name));
F_145 ( V_2 , V_243 , L_168 ) ;
F_145 ( V_2 , V_244 , L_168 ) ;
F_145 ( V_2 , V_245 , L_169 ) ;
F_145 ( V_2 , V_246 , L_169 ) ;
F_145 ( V_2 , V_247 , L_169 ) ;
F_145 ( V_2 , V_248 , L_170 ) ;
#ifdef F_146
F_145 ( V_2 , V_249 , L_170 ) ;
F_145 ( V_2 , V_250 , L_168 ) ;
F_145 ( V_2 , V_251 , L_168 ) ;
#endif
F_145 ( V_2 , V_252 , L_169 ) ;
F_145 ( V_2 , V_253 , L_168 ) ;
F_145 ( V_2 , V_254 , L_168 ) ;
F_145 ( V_2 , V_255 , L_168 ) ;
#ifdef F_141
for ( V_67 = 0 ; V_67 < V_256 ; V_67 ++ ) {
V_224 V_257 , V_258 ;
if ( ! V_2 -> V_259 )
continue;
V_257 = F_147 ( V_2 -> V_259 -> V_260 [ V_67 ] . V_257 ) ;
V_258 = F_147 ( V_2 -> V_259 -> V_260 [ V_67 ] . V_258 ) ;
if ( V_257 || V_258 ) {
printf ( L_171 ,
V_67 , V_257 , V_258 ) ;
}
}
F_145 ( V_2 , V_261 , L_168 ) ;
F_145 ( V_2 , V_262 , L_168 ) ;
for ( V_67 = 0 ; V_67 < V_263 ; V_67 ++ )
printf ( L_172 , V_67 , V_2 -> V_264 [ V_67 ] ) ;
#endif
F_145 ( V_2 , V_265 , L_173 ) ;
#ifdef V_23
F_145 ( V_2 , V_266 , L_170 ) ;
F_145 ( V_2 , V_267 , L_170 ) ;
F_145 ( V_2 , V_268 , L_170 ) ;
F_145 ( V_2 , V_269 , L_170 ) ;
F_145 ( V_2 , V_270 , L_170 ) ;
F_145 ( V_2 , V_271 , L_170 ) ;
#endif
F_145 ( V_2 , V_272 , L_170 ) ;
F_145 ( V_2 , V_273 , L_169 ) ;
F_145 ( V_2 , V_274 , L_169 ) ;
F_145 ( V_2 , V_275 , L_169 ) ;
F_145 ( V_2 , V_276 , L_168 ) ;
F_145 ( V_2 , V_140 , L_168 ) ;
F_145 ( V_2 , V_141 , L_168 ) ;
F_145 ( V_2 , V_277 , L_168 ) ;
F_145 ( V_2 , V_278 , L_168 ) ;
F_145 ( V_2 , V_279 , L_168 ) ;
F_145 ( V_2 , V_280 , L_173 ) ;
#ifdef F_148
F_145 ( V_2 , V_281 , L_173 ) ;
#endif
#ifdef F_149
F_145 ( V_2 , V_282 , L_170 ) ;
F_145 ( V_2 , V_283 , L_168 ) ;
F_145 ( V_2 , V_284 , L_168 ) ;
F_145 ( V_2 , V_285 , L_168 ) ;
#endif
F_145 ( V_2 , V_286 . V_287 , L_173 ) ;
F_145 ( V_2 , V_286 . V_288 , L_173 ) ;
F_145 ( V_2 , V_286 . V_289 , L_173 ) ;
F_145 ( V_2 , V_286 . V_290 , L_173 ) ;
F_145 ( V_2 , V_286 . V_291 , L_173 ) ;
F_145 ( V_2 , V_286 . V_292 , L_173 ) ;
F_145 ( V_2 , V_286 . V_293 , L_173 ) ;
F_145 ( V_2 , V_286 . V_294 , L_173 ) ;
#undef F_145
V_65 = 0 ;
F_3 () ;
}
static void F_150 ( void )
{
int V_34 ;
if ( F_151 () == 0 ) {
printf ( L_174 ) ;
return;
}
F_112 (cpu)
F_140 ( V_34 ) ;
}
static void F_152 ( void )
{
unsigned long V_295 ;
int V_235 ;
V_235 = F_85 () ;
if ( V_235 == 'a' ) {
F_150 () ;
return;
}
V_87 = V_235 ;
if ( F_79 ( & V_295 ) )
F_140 ( V_295 ) ;
else
F_140 ( V_47 ) ;
}
static void F_153 ( unsigned long V_6 , long V_296 , int V_114 )
{
unsigned char V_240 [ 16 ] ;
int V_67 , V_297 ;
V_224 V_156 ;
V_296 = F_154 ( V_296 , 16 ) ;
for ( V_67 = 0 ; V_67 < V_296 ; V_67 += 16 , V_6 += 16 ) {
printf ( V_105 , V_6 ) ;
if ( F_73 ( V_6 , V_240 , 16 ) != 16 ) {
printf ( L_175 V_105 L_34 , 16 , V_6 ) ;
return;
}
for ( V_297 = 0 ; V_297 < 16 ; V_297 += V_114 ) {
putchar ( ' ' ) ;
switch ( V_114 ) {
case 1 : V_156 = V_240 [ V_297 ] ; break;
case 2 : V_156 = * ( V_222 * ) & V_240 [ V_297 ] ; break;
case 4 : V_156 = * ( V_223 * ) & V_240 [ V_297 ] ; break;
case 8 : V_156 = * ( V_224 * ) & V_240 [ V_297 ] ; break;
default: V_156 = 0 ;
}
printf ( L_176 , V_114 * 2 , V_156 ) ;
}
printf ( L_34 ) ;
}
}
static void
F_91 ( void )
{
static char V_298 [] = { L_177 } ;
int V_235 ;
V_235 = F_85 () ;
#ifdef F_125
if ( V_235 == 'p' ) {
F_155 () ;
F_152 () ;
F_156 () ;
return;
}
#endif
if ( V_235 == '\n' )
V_87 = V_235 ;
F_79 ( ( void * ) & V_103 ) ;
if ( V_87 != '\n' )
V_87 = 0 ;
if ( V_235 == 'i' ) {
F_79 ( & V_299 ) ;
if ( V_299 == 0 )
V_299 = 16 ;
else if ( V_299 > V_300 )
V_299 = V_300 ;
V_103 += F_46 ( V_103 , V_299 , 1 ) ;
V_82 = L_178 ;
} else if ( V_235 == 'l' ) {
F_157 () ;
} else if ( V_235 == 'o' ) {
F_2 () ;
} else if ( V_235 == 't' ) {
F_158 ( V_301 ) ;
F_159 () ;
} else if ( V_235 == 'r' ) {
F_79 ( & V_236 ) ;
if ( V_236 == 0 )
V_236 = 64 ;
F_139 ( V_103 , V_236 ) ;
V_103 += V_236 ;
V_82 = L_179 ;
} else {
F_79 ( & V_236 ) ;
if ( V_236 == 0 )
V_236 = 64 ;
else if ( V_236 > V_300 )
V_236 = V_300 ;
switch ( V_235 ) {
case '8' :
case '4' :
case '2' :
case '1' :
V_236 = F_154 ( V_236 , 16 ) ;
F_153 ( V_103 , V_236 , V_235 - '0' ) ;
V_298 [ 1 ] = V_235 ;
V_82 = V_298 ;
break;
default:
F_160 ( V_103 , V_236 ) ;
V_82 = L_180 ;
}
V_103 += V_236 ;
}
}
static void
F_160 ( unsigned long V_103 , long V_236 )
{
long V_145 , V_237 , V_235 , V_238 , V_239 ;
unsigned char V_240 [ 16 ] ;
for ( V_145 = V_236 ; V_145 > 0 ; ) {
printf ( V_105 , V_103 ) ;
putchar ( ' ' ) ;
V_238 = V_145 < 16 ? V_145 : 16 ;
V_239 = F_73 ( V_103 , V_240 , V_238 ) ;
V_103 += V_239 ;
for ( V_237 = 0 ; V_237 < V_238 ; ++ V_237 ) {
if ( ( V_237 & ( sizeof( long ) - 1 ) ) == 0 && V_237 > 0 )
putchar ( ' ' ) ;
if ( V_237 < V_239 )
printf ( L_158 , V_240 [ V_237 ] ) ;
else
printf ( L_159 , V_233 [ V_226 ] ) ;
}
for (; V_237 < 16 ; ++ V_237 ) {
if ( ( V_237 & ( sizeof( long ) - 1 ) ) == 0 )
putchar ( ' ' ) ;
printf ( L_62 ) ;
}
printf ( L_181 ) ;
for ( V_237 = 0 ; V_237 < V_238 ; ++ V_237 ) {
if ( V_237 < V_239 ) {
V_235 = V_240 [ V_237 ] ;
putchar ( ' ' <= V_235 && V_235 <= '~' ? V_235 : '.' ) ;
} else
putchar ( ' ' ) ;
}
V_145 -= V_238 ;
for (; V_237 < 16 ; ++ V_237 )
putchar ( ' ' ) ;
printf ( L_182 ) ;
if ( V_239 < V_238 )
break;
}
}
static int
F_161 ( unsigned long V_302 , long V_296 , int V_303 ,
T_3 V_304 )
{
int V_239 , V_305 ;
unsigned long V_306 ;
unsigned long V_307 , V_308 = 0 ;
unsigned char V_156 [ 4 ] ;
V_305 = 0 ;
for ( V_306 = V_302 ; V_296 > 0 ; -- V_296 , V_302 += 4 ) {
V_239 = F_73 ( V_302 , V_156 , 4 ) ;
if ( V_239 == 0 ) {
if ( V_303 ) {
const char * V_309 = V_233 [ V_226 ] ;
printf ( V_105 L_183 , V_302 , V_309 , V_309 , V_309 , V_309 ) ;
}
break;
}
V_307 = F_162 ( V_156 ) ;
if ( V_302 > V_306 && V_307 == V_308 ) {
if ( ! V_305 ) {
printf ( L_184 ) ;
V_305 = 1 ;
}
continue;
}
V_305 = 0 ;
V_308 = V_307 ;
if ( V_303 )
printf ( V_105 L_185 , V_302 , V_307 ) ;
printf ( L_186 ) ;
V_304 ( V_307 , V_302 ) ;
printf ( L_34 ) ;
}
return V_302 - V_306 ;
}
static int
F_46 ( unsigned long V_302 , long V_296 , int V_303 )
{
return F_161 ( V_302 , V_296 , V_303 , V_310 ) ;
}
void
F_163 ( unsigned long V_6 )
{
F_37 ( V_6 , L_187 , L_86 ) ;
}
void
F_157 ( void )
{
struct V_311 V_312 = { . V_313 = 1 } ;
unsigned char V_220 [ 128 ] ;
T_4 V_80 ;
if ( setjmp ( V_40 ) != 0 ) {
printf ( L_188 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
F_164 ( & V_312 ) ;
F_155 () ;
while ( F_165 ( & V_312 , false , V_220 , sizeof( V_220 ) , & V_80 ) ) {
V_220 [ V_80 ] = '\0' ;
printf ( L_159 , V_220 ) ;
}
F_156 () ;
F_3 () ;
F_126 ( 200 ) ;
V_65 = 0 ;
}
static void F_2 ( void )
{
unsigned char V_220 [ 128 ] ;
T_5 V_314 ;
T_6 V_315 = 0 ;
if ( ! F_166 ( V_316 ) ) {
printf ( L_1 ) ;
return;
}
if ( setjmp ( V_40 ) != 0 ) {
printf ( L_189 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
F_155 () ;
while ( ( V_314 = F_167 ( V_220 , V_315 , sizeof( V_220 ) - 1 ) ) ) {
if ( V_314 < 0 ) {
printf ( L_190 , V_314 ) ;
break;
}
V_220 [ V_314 ] = '\0' ;
printf ( L_159 , V_220 ) ;
V_315 += V_314 ;
}
F_156 () ;
F_3 () ;
F_126 ( 200 ) ;
V_65 = 0 ;
}
static void
F_86 ( int V_27 )
{
F_79 ( ( void * ) & V_317 ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_79 ( ( void * ) ( V_27 == 's' ? & V_318 : & V_319 ) ) ;
if( V_87 != '\n' )
V_87 = 0 ;
F_79 ( ( void * ) & V_320 ) ;
switch( V_27 ) {
case 'm' :
memmove ( ( void * ) V_317 , ( void * ) V_319 , V_320 ) ;
break;
case 's' :
memset ( ( void * ) V_317 , V_318 , V_320 ) ;
break;
case 'd' :
if( V_87 != '\n' )
V_87 = 0 ;
F_79 ( ( void * ) & V_321 ) ;
F_168 ( ( unsigned char * ) V_317 , ( unsigned char * ) V_319 , V_320 , V_321 ) ;
break;
}
}
static void
F_168 ( unsigned char * V_322 , unsigned char * V_323 , unsigned V_324 , unsigned V_325 )
{
unsigned V_145 , V_326 ;
V_326 = 0 ;
for( V_145 = V_324 ; V_145 > 0 ; -- V_145 )
if( * V_322 ++ != * V_323 ++ )
if( ++ V_326 <= V_325 )
printf ( L_191 , V_322 - 1 ,
V_322 [ - 1 ] , V_323 - 1 , V_323 [ - 1 ] ) ;
if( V_326 > V_325 )
printf ( L_192 , V_326 ) ;
}
static void
F_87 ( void )
{
unsigned V_72 , V_145 ;
unsigned char V_156 [ 4 ] ;
V_82 = L_193 ;
F_79 ( ( void * ) & V_317 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_79 ( ( void * ) & V_327 ) ;
if ( V_87 != '\n' ) {
V_87 = 0 ;
F_79 ( ( void * ) & V_318 ) ;
V_328 = ~ 0 ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_79 ( ( void * ) & V_328 ) ;
}
}
V_145 = 0 ;
for ( V_72 = V_317 ; V_72 < V_327 ; V_72 += 4 ) {
if ( F_73 ( V_72 , V_156 , 4 ) == 4
&& ( ( F_162 ( V_156 ) ^ V_318 ) & V_328 ) == 0 ) {
printf ( L_194 , V_72 , F_162 ( V_156 ) ) ;
if ( ++ V_145 >= 10 )
break;
}
}
}
static void
F_88 ( void )
{
unsigned char V_102 ;
unsigned V_72 ;
int V_155 , V_329 ;
F_79 ( & V_317 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_79 ( & V_330 ) ;
if ( V_87 != '\n' ) V_87 = 0 ;
F_79 ( & V_331 ) ;
V_329 = 0 ;
for ( V_72 = V_317 ; V_72 < V_331 ; V_72 += V_330 ) {
V_155 = F_73 ( V_72 , & V_102 , 1 ) ;
if ( V_155 && ! V_329 ) {
printf ( L_195 , V_72 ) ;
} else if ( ! V_155 && V_329 )
printf ( L_196 , V_72 - V_330 ) ;
V_329 = V_155 ;
if ( V_72 + V_330 < V_72 )
break;
}
if ( V_329 )
printf ( L_196 , V_72 - V_330 ) ;
}
static void F_169 ( struct V_332 * V_333 )
{
char V_334 ;
V_334 = ( V_333 -> V_334 == 0 ) ? 'R' :
( V_333 -> V_334 < 0 ) ? 'U' :
( V_333 -> V_334 & V_335 ) ? 'D' :
( V_333 -> V_334 & V_336 ) ? 'T' :
( V_333 -> V_334 & V_337 ) ? 'C' :
( V_333 -> V_338 & V_339 ) ? 'Z' :
( V_333 -> V_338 & V_340 ) ? 'E' :
( V_333 -> V_334 & V_341 ) ? 'S' : '?' ;
printf ( L_197 , V_333 ,
V_333 -> V_342 . V_343 ,
V_333 -> V_142 , V_333 -> V_344 -> V_142 ,
V_334 , F_170 ( V_333 ) -> V_34 ,
V_333 -> V_143 ) ;
}
static void F_106 ( void )
{
unsigned long V_345 ;
struct V_332 * V_333 = NULL ;
printf ( L_198 ) ;
if ( F_79 ( & V_345 ) )
V_333 = (struct V_332 * ) V_345 ;
if ( setjmp ( V_40 ) != 0 ) {
V_65 = 0 ;
printf ( L_199 , V_333 ) ;
return;
}
V_65 = 1 ;
F_3 () ;
if ( V_333 )
F_169 ( V_333 ) ;
else
F_171 (tsk)
F_169 ( V_333 ) ;
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
T_7 V_346 ;
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
V_346 = ( T_7 ) V_103 ;
V_111 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_111 = V_346 ( args [ 0 ] , args [ 1 ] , args [ 2 ] , args [ 3 ] ,
args [ 4 ] , args [ 5 ] , args [ 6 ] , args [ 7 ] ) ;
F_3 () ;
printf ( L_200 , V_111 ) ;
} else {
printf ( L_201 , V_225 ) ;
}
V_65 = 0 ;
}
int
F_83 ( void )
{
int V_235 ;
if( V_87 != 0 ) {
V_235 = V_87 ;
V_87 = 0 ;
} else
V_235 = F_85 () ;
while( V_235 == ' ' || V_235 == '\t' )
V_235 = F_85 () ;
return V_235 ;
}
int
F_79 ( unsigned long * V_154 )
{
int V_235 , V_60 ;
unsigned long V_102 ;
V_235 = F_83 () ;
if ( V_235 == '%' ) {
char V_347 [ 8 ] ;
int V_67 ;
for ( V_67 = 0 ; V_67 < sizeof( V_347 ) - 1 ; ++ V_67 ) {
V_235 = F_85 () ;
if ( ! isalnum ( V_235 ) ) {
V_87 = V_235 ;
break;
}
V_347 [ V_67 ] = V_235 ;
}
V_347 [ V_67 ] = 0 ;
for ( V_67 = 0 ; V_67 < V_348 ; ++ V_67 ) {
if ( strcmp ( V_349 [ V_67 ] , V_347 ) == 0 ) {
if ( V_83 == NULL ) {
printf ( L_202 ) ;
return 0 ;
}
* V_154 = ( ( unsigned long * ) V_83 ) [ V_67 ] ;
return 1 ;
}
}
printf ( L_203 , V_347 ) ;
return 0 ;
}
if ( V_235 == '0' ) {
V_235 = F_85 () ;
if ( V_235 == 'x' ) {
V_235 = F_85 () ;
} else {
V_60 = F_172 ( V_235 ) ;
if ( V_60 == V_57 ) {
V_87 = V_235 ;
* V_154 = 0 ;
return 1 ;
}
}
} else if ( V_235 == '$' ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < 63 ; V_67 ++ ) {
V_235 = F_85 () ;
if ( isspace ( V_235 ) || V_235 == '\0' ) {
V_87 = V_235 ;
break;
}
V_116 [ V_67 ] = V_235 ;
}
V_116 [ V_67 ++ ] = 0 ;
* V_154 = 0 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
* V_154 = F_173 ( V_116 ) ;
F_3 () ;
}
V_65 = 0 ;
if ( ! ( * V_154 ) ) {
printf ( L_204 , V_116 ) ;
return 0 ;
}
return 1 ;
}
V_60 = F_172 ( V_235 ) ;
if ( V_60 == V_57 ) {
V_87 = V_235 ;
return 0 ;
}
V_102 = 0 ;
do {
V_102 = ( V_102 << 4 ) + V_60 ;
V_235 = F_85 () ;
V_60 = F_172 ( V_235 ) ;
} while ( V_60 != V_57 );
V_87 = V_235 ;
* V_154 = V_102 ;
return 1 ;
}
static void
F_119 ( void )
{
int V_235 ;
V_235 = V_87 ;
V_87 = 0 ;
while( V_235 != '\n' )
V_235 = F_85 () ;
}
static int F_172 ( int V_235 )
{
if( '0' <= V_235 && V_235 <= '9' )
return V_235 - '0' ;
if( 'A' <= V_235 && V_235 <= 'F' )
return V_235 - ( 'A' - 10 ) ;
if( 'a' <= V_235 && V_235 <= 'f' )
return V_235 - ( 'a' - 10 ) ;
return V_57 ;
}
void
F_174 ( char * V_350 , int V_114 )
{
int V_235 ;
V_235 = F_83 () ;
do {
if( V_114 > 1 ) {
* V_350 ++ = V_235 ;
-- V_114 ;
}
V_235 = F_85 () ;
} while( V_235 != ' ' && V_235 != '\t' && V_235 != '\n' );
V_87 = V_235 ;
* V_350 = 0 ;
}
static void
F_82 ( void )
{
V_351 = NULL ;
}
static int
F_85 ( void )
{
if ( V_351 == NULL || * V_351 == 0 ) {
if ( F_175 ( line , sizeof( line ) ) == NULL ) {
V_351 = NULL ;
return V_57 ;
}
V_351 = line ;
}
return * V_351 ++ ;
}
static void
F_84 ( char * V_352 )
{
V_351 = V_352 ;
}
static void
F_92 ( void )
{
int type = F_85 () ;
unsigned long V_6 ;
static char V_353 [ 64 ] ;
switch ( type ) {
case 'a' :
if ( F_79 ( & V_6 ) )
F_37 ( V_6 , L_100 , L_34 ) ;
V_87 = 0 ;
break;
case 's' :
F_174 ( V_353 , 64 ) ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_6 = F_173 ( V_353 ) ;
if ( V_6 )
printf ( L_205 , V_353 , V_6 ) ;
else
printf ( L_206 , V_353 ) ;
F_3 () ;
}
V_65 = 0 ;
V_87 = 0 ;
break;
}
}
static void F_37 ( unsigned long V_37 , const char * V_354 ,
const char * V_355 )
{
char * V_356 ;
const char * V_115 = NULL ;
unsigned long V_32 , V_114 ;
printf ( V_105 , V_37 ) ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_115 = F_118 ( V_37 , & V_114 , & V_32 , & V_356 ,
V_116 ) ;
F_3 () ;
F_126 ( 200 ) ;
}
V_65 = 0 ;
if ( V_115 ) {
printf ( L_207 , V_354 , V_115 , V_32 , V_114 ) ;
if ( V_356 )
printf ( L_208 , V_356 ) ;
}
printf ( L_159 , V_355 ) ;
}
void F_108 ( void )
{
int V_67 ;
unsigned long V_257 , V_258 ;
unsigned long V_357 ;
printf ( L_209 , F_16 () ) ;
for ( V_67 = 0 ; V_67 < V_358 ; V_67 ++ ) {
asm volatile("slbmfee %0,%1" : "=r" (esid) : "r" (i));
asm volatile("slbmfev %0,%1" : "=r" (vsid) : "r" (i));
if ( V_257 || V_258 ) {
printf ( L_210 , V_67 , V_257 , V_258 ) ;
if ( V_257 & V_359 ) {
V_357 = V_258 & V_360 ;
if ( V_258 & V_361 ) {
printf ( L_211 ,
F_176 ( V_257 ) ,
( V_258 & ~ V_362 ) >> V_363 ,
V_357 ) ;
} else {
printf ( L_212 ,
F_177 ( V_257 ) ,
( V_258 & ~ V_362 ) >> V_364 ,
V_357 ) ;
}
} else
printf ( L_34 ) ;
}
}
}
void F_108 ( void )
{
int V_67 ;
printf ( L_213 ) ;
for ( V_67 = 0 ; V_67 < 16 ; ++ V_67 )
printf ( L_214 , F_178 ( V_67 ) ) ;
printf ( L_34 ) ;
}
static void F_109 ( void )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_365 ; V_67 ++ ) {
unsigned long V_366 , V_367 , V_368 ;
asm volatile("tlbre %0,%1,0" : "=r" (w0) : "r" (i));
asm volatile("tlbre %0,%1,1" : "=r" (w1) : "r" (i));
asm volatile("tlbre %0,%1,2" : "=r" (w2) : "r" (i));
printf ( L_215 , V_67 , V_366 , V_367 , V_368 ) ;
if ( V_366 & V_369 ) {
printf ( L_216 ,
V_366 & V_370 ,
V_367 & V_371 ,
V_367 & V_372 ,
( V_368 & V_373 ) ? 'W' : 'w' ,
( V_368 & V_374 ) ? 'I' : 'i' ,
( V_368 & V_375 ) ? 'M' : 'm' ,
( V_368 & V_376 ) ? 'G' : 'g' ,
( V_368 & V_377 ) ? 'E' : 'e' ) ;
}
printf ( L_34 ) ;
}
}
static void F_110 ( void )
{
V_223 V_378 , V_379 , V_380 ;
V_224 V_381 ;
int V_67 , V_382 , V_383 , V_384 , V_385 , V_386 , V_387 = 0 ;
int V_388 ;
static const char * V_389 [] = {
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
} ;
V_378 = F_111 ( V_390 ) ;
V_388 = ( V_378 & 3 ) + 1 ;
V_383 = ( ( V_378 >> 2 ) & 3 ) + 1 ;
V_384 = ( ( V_378 >> 6 ) & 0x1f ) + 1 ;
V_385 = ( V_378 >> 24 ) & 0xf ;
V_386 = ( V_378 >> 16 ) & 0x7f ;
if ( ( V_388 > 1 ) && ( V_378 & 0x10000 ) )
V_387 = 1 ;
printf ( L_249 ,
V_388 , V_383 , V_384 , V_385 , V_386 ) ;
V_379 = ( 1ul << V_384 ) - 1 ;
V_380 = ( 1ul << V_385 ) - 1 ;
V_381 = ( 1ull << V_386 ) - 1 ;
for ( V_382 = 0 ; V_382 < V_383 ; V_382 ++ ) {
V_223 V_391 ;
int V_392 , V_393 , V_394 = 1 ;
printf ( L_250 , V_382 ) ;
switch( V_382 ) {
case 0 :
V_391 = F_111 ( V_395 ) ;
break;
case 1 :
V_391 = F_111 ( V_396 ) ;
break;
case 2 :
V_391 = F_111 ( V_397 ) ;
break;
case 3 :
V_391 = F_111 ( V_398 ) ;
break;
default:
printf ( L_251 ) ;
continue;
}
V_392 = V_391 & 0xfff ;
V_393 = ( V_391 >> 24 ) & 0xff ;
for ( V_67 = 0 ; V_67 < V_392 ; V_67 ++ ) {
V_223 V_399 = F_179 ( V_382 ) ;
V_223 V_400 = F_180 ( V_401 ) ;
V_224 V_402 = 0 ;
V_224 V_403 ;
int V_404 = V_67 , V_405 = V_67 ;
if ( V_393 != 0 ) {
V_405 = V_67 / V_393 ;
V_404 = V_67 % V_393 ;
V_402 = V_405 * 0x1000 ;
}
V_399 |= F_181 ( V_404 ) ;
F_9 ( V_406 , V_399 ) ;
F_9 ( V_407 , V_400 ) ;
F_9 ( V_408 , V_402 ) ;
asm volatile("tlbre 0,0,0" : : : "memory");
V_400 = F_111 ( V_407 ) ;
V_402 = F_111 ( V_408 ) ;
V_403 = F_111 ( V_409 ) ;
if ( V_393 && ( V_67 % V_393 ) == 0 )
V_394 = 1 ;
if ( ! ( V_400 & V_410 ) )
continue;
if ( V_393 == 0 )
printf ( L_252 , V_67 ) ;
else if ( V_394 )
printf ( L_253 , V_405 , 'A' + V_404 ) ;
else
printf ( L_254 , 'A' + V_404 ) ;
V_394 = 0 ;
printf ( L_255 ,
V_402 & ~ 0x3ffull ,
( V_400 >> 16 ) & 0x3fff ,
V_389 [ ( V_400 >> 7 ) & 0x1f ] ,
V_400 & V_411 ? 'I' : ' ' ,
V_400 & V_412 ? 'P' : ' ' ,
V_400 & V_413 ? '1' : '0' ) ;
printf ( L_256 ,
V_402 & V_414 ? 'a' : ' ' ,
V_402 & V_415 ? 'v' : ' ' ,
V_402 & V_416 ? 'w' : ' ' ,
V_402 & V_417 ? 'i' : ' ' ,
V_402 & V_418 ? 'm' : ' ' ,
V_402 & V_419 ? 'g' : ' ' ,
V_402 & V_420 ? 'e' : ' ' ) ;
printf ( L_257 , V_403 & V_381 & ~ 0x7ffull ) ;
if ( V_400 & V_411 )
printf ( L_258 ,
V_389 [ ( V_403 >> 1 ) & 0x1f ] ) ;
else
printf ( L_259 ,
V_403 & V_421 ? 'x' : ' ' ,
V_403 & V_422 ? 'w' : ' ' ,
V_403 & V_423 ? 'r' : ' ' ,
V_403 & V_424 ? 'x' : ' ' ,
V_403 & V_425 ? 'w' : ' ' ,
V_403 & V_426 ? 'r' : ' ' ) ;
}
}
}
static void F_182 ( int V_427 )
{
if ( V_427 ) {
V_428 = F_58 ;
V_429 = F_67 ;
V_430 = F_62 ;
V_431 = F_63 ;
V_432 = F_66 ;
V_433 = F_65 ;
V_434 = F_68 ;
} else {
V_428 = NULL ;
V_429 = NULL ;
V_430 = NULL ;
V_431 = NULL ;
V_432 = NULL ;
V_433 = NULL ;
V_434 = NULL ;
}
}
static void F_183 ( int V_435 )
{
F_182 ( 1 ) ;
F_184 ( F_61 () ) ;
}
static int T_8 F_185 ( void )
{
F_186 ( 'x' , & V_436 ) ;
return 0 ;
}
static int T_8 F_187 ( char * V_2 )
{
if ( ! V_2 || strncmp ( V_2 , L_260 , 5 ) == 0 ) {
F_182 ( 1 ) ;
V_437 = 1 ;
} else if ( strncmp ( V_2 , L_261 , 2 ) == 0 )
F_182 ( 1 ) ;
else if ( strncmp ( V_2 , L_262 , 3 ) == 0 )
V_438 = 1 ;
else if ( strncmp ( V_2 , L_263 , 4 ) == 0 )
V_84 = 1 ;
else
return 1 ;
return 0 ;
}
void T_8 F_188 ( void )
{
#ifdef F_189
if ( ! V_438 )
F_182 ( 1 ) ;
#endif
if ( V_437 )
F_184 ( NULL ) ;
}
void F_190 ( struct V_439 * V_440 )
{
struct V_441 * V_441 ;
F_191 (spu, list, full_list) {
if ( V_441 -> V_442 >= V_443 ) {
F_192 ( 1 ) ;
continue;
}
V_444 [ V_441 -> V_442 ] . V_441 = V_441 ;
V_444 [ V_441 -> V_442 ] . V_445 = 0 ;
V_444 [ V_441 -> V_442 ] . V_446 = ( unsigned long )
V_444 [ V_441 -> V_442 ] . V_441 -> V_447 ;
}
}
static void F_193 ( void )
{
struct V_441 * V_441 ;
int V_67 ;
V_224 V_353 ;
for ( V_67 = 0 ; V_67 < V_443 ; V_67 ++ ) {
if ( ! V_444 [ V_67 ] . V_441 )
continue;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_441 = V_444 [ V_67 ] . V_441 ;
V_444 [ V_67 ] . V_448 =
F_194 ( & V_441 -> V_449 -> V_450 ) ;
V_353 = F_195 ( V_441 ) ;
V_444 [ V_67 ] . V_451 = V_353 ;
V_353 &= ~ V_452 ;
F_196 ( V_441 , V_353 ) ;
F_3 () ;
F_126 ( 200 ) ;
V_444 [ V_67 ] . V_445 = 1 ;
printf ( L_264 , V_67 ,
V_444 [ V_67 ] . V_448 ?
L_265 : L_266 ) ;
} else {
V_65 = 0 ;
printf ( L_267 , V_67 ) ;
}
V_65 = 0 ;
}
}
static void F_197 ( void )
{
struct V_441 * V_441 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_443 ; V_67 ++ ) {
if ( ! V_444 [ V_67 ] . V_441 )
continue;
if ( ! V_444 [ V_67 ] . V_445 ) {
printf ( L_268
L_269 , V_67 ) ;
continue;
}
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_441 = V_444 [ V_67 ] . V_441 ;
F_196 ( V_441 , V_444 [ V_67 ] . V_451 ) ;
F_198 ( & V_441 -> V_449 -> V_450 ,
V_444 [ V_67 ] . V_448 ) ;
F_3 () ;
F_126 ( 200 ) ;
printf ( L_270 , V_67 ) ;
} else {
V_65 = 0 ;
printf ( L_271 , V_67 ) ;
}
V_65 = 0 ;
}
}
static void F_199 ( struct V_441 * V_441 )
{
printf ( L_272 , V_441 ) ;
F_200 ( V_441 , L_273 , V_442 ) ;
F_200 ( V_441 , L_159 , V_115 ) ;
F_200 ( V_441 , L_274 , V_453 ) ;
F_200 ( V_441 , L_275 , V_447 ) ;
F_200 ( V_441 , L_274 , V_454 ) ;
F_200 ( V_441 , L_273 , V_455 ) ;
F_200 ( V_441 , L_274 , V_33 ) ;
F_200 ( V_441 , L_276 , V_456 ) ;
F_200 ( V_441 , L_274 , V_457 ) ;
F_200 ( V_441 , L_274 , V_458 ) ;
F_200 ( V_441 , L_274 , V_459 ) ;
F_200 ( V_441 , L_274 , V_460 [ 0 ] ) ;
F_200 ( V_441 , L_274 , V_460 [ 1 ] ) ;
F_200 ( V_441 , L_274 , V_460 [ 2 ] ) ;
F_200 ( V_441 , L_273 , V_461 ) ;
F_200 ( V_441 , L_276 , V_142 ) ;
F_200 ( V_441 , L_275 , V_462 ) ;
F_200 ( V_441 , L_275 , V_463 ) ;
F_200 ( V_441 , L_275 , V_464 ) ;
F_200 ( V_441 , L_275 , V_465 ) ;
F_200 ( V_441 , L_274 , V_466 ) ;
F_200 ( V_441 , L_275 , V_449 ) ;
F_201 ( L_273 , V_449 -> V_450 ,
F_194 ( & V_441 -> V_449 -> V_450 ) ) ;
F_201 ( L_273 , V_449 -> V_467 ,
F_194 ( & V_441 -> V_449 -> V_467 ) ) ;
F_201 ( L_273 , V_449 -> V_468 ,
F_194 ( & V_441 -> V_449 -> V_468 ) ) ;
F_200 ( V_441 , L_275 , V_469 ) ;
F_200 ( V_441 , L_275 , V_470 ) ;
}
int
F_202 ( unsigned long V_302 , long V_296 , int V_303 )
{
return F_161 ( V_302 , V_296 , V_303 , V_471 ) ;
}
static void F_203 ( unsigned long V_295 , int V_472 )
{
unsigned long V_32 , V_6 , V_473 ;
if ( setjmp ( V_40 ) == 0 ) {
V_65 = 1 ;
F_3 () ;
V_473 = ( unsigned long ) V_444 [ V_295 ] . V_441 -> V_447 ;
F_3 () ;
F_126 ( 200 ) ;
} else {
V_65 = 0 ;
printf ( L_277 , V_295 ) ;
return;
}
V_65 = 0 ;
if ( F_79 ( & V_32 ) )
V_6 = V_473 + V_32 ;
else
V_6 = V_444 [ V_295 ] . V_446 ;
if ( V_6 >= V_473 + V_474 ) {
printf ( L_278 ) ;
return;
}
switch ( V_472 ) {
case 'i' :
V_6 += F_202 ( V_6 , 16 , 1 ) ;
V_82 = L_279 ;
break;
default:
F_160 ( V_6 , 64 ) ;
V_6 += 64 ;
V_82 = L_280 ;
break;
}
V_444 [ V_295 ] . V_446 = V_6 ;
}
static int F_97 ( void )
{
static unsigned long V_295 = 0 ;
int V_27 , V_472 = 0 ;
V_27 = F_85 () ;
switch ( V_27 ) {
case 's' :
F_193 () ;
break;
case 'r' :
F_197 () ;
break;
case 'd' :
V_472 = F_85 () ;
if ( isxdigit ( V_472 ) || V_472 == '\n' )
V_87 = V_472 ;
case 'f' :
F_79 ( & V_295 ) ;
if ( V_295 >= V_443 || ! V_444 [ V_295 ] . V_441 ) {
printf ( L_281 ) ;
return 0 ;
}
switch ( V_27 ) {
case 'f' :
F_199 ( V_444 [ V_295 ] . V_441 ) ;
break;
default:
F_203 ( V_295 , V_472 ) ;
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
