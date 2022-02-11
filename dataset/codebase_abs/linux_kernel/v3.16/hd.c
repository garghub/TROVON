unsigned long F_1 ( void )
{
unsigned long V_1 , V_2 ;
int V_3 ;
F_2 ( & V_4 , V_2 ) ;
V_1 = V_5 * 11932 ;
F_3 ( 0 , 0x43 ) ;
V_3 = F_4 ( 0x40 ) ;
V_3 |= F_5 ( 0x40 ) << 8 ;
F_6 ( & V_4 , V_2 ) ;
return ( V_1 - V_3 ) ;
}
static void T_1 F_7 ( char * V_6 , int * V_7 )
{
int V_8 = 0 ;
if ( V_7 [ 0 ] != 3 )
return;
if ( V_9 [ 0 ] . V_10 != 0 )
V_8 = 1 ;
V_9 [ V_8 ] . V_10 = V_7 [ 2 ] ;
V_9 [ V_8 ] . V_11 = V_7 [ 3 ] ;
V_9 [ V_8 ] . V_12 = V_7 [ 1 ] ;
V_9 [ V_8 ] . V_13 = 0 ;
V_9 [ V_8 ] . V_14 = V_7 [ 1 ] ;
V_9 [ V_8 ] . V_15 = ( V_7 [ 2 ] > 8 ? 8 : 0 ) ;
V_16 = V_8 + 1 ;
}
static bool F_8 ( int V_17 , unsigned int V_18 )
{
if ( F_9 ( V_19 , V_17 , V_18 ) )
return true ;
V_19 = NULL ;
return false ;
}
static bool F_10 ( int V_17 )
{
return F_8 ( V_17 , F_11 ( V_19 ) ) ;
}
static void F_12 ( const char * V_20 , unsigned int V_21 )
{
char * V_22 = L_1 ;
if ( V_19 )
V_22 = V_19 -> V_23 -> V_24 ;
#ifdef F_13
F_14 ( L_2 , V_22 , V_20 , V_21 & 0xff ) ;
if ( V_21 & V_25 ) F_14 ( L_3 ) ;
if ( V_21 & V_26 ) F_14 ( L_4 ) ;
if ( V_21 & V_27 ) F_14 ( L_5 ) ;
if ( V_21 & V_28 ) F_14 ( L_6 ) ;
if ( V_21 & V_29 ) F_14 ( L_7 ) ;
if ( V_21 & V_30 ) F_14 ( L_8 ) ;
if ( V_21 & V_31 ) F_14 ( L_9 ) ;
if ( V_21 & V_32 ) F_14 ( L_10 ) ;
F_14 ( L_11 ) ;
if ( ( V_21 & V_32 ) == 0 ) {
V_33 = 0 ;
} else {
V_33 = F_5 ( V_34 ) ;
F_14 ( L_12 , V_22 , V_20 , V_33 & 0xff ) ;
if ( V_33 & V_35 ) F_14 ( L_13 ) ;
if ( V_33 & V_36 ) F_14 ( L_14 ) ;
if ( V_33 & V_37 ) F_14 ( L_15 ) ;
if ( V_33 & V_38 ) F_14 ( L_16 ) ;
if ( V_33 & V_39 ) F_14 ( L_17 ) ;
if ( V_33 & V_40 ) F_14 ( L_18 ) ;
F_14 ( L_19 ) ;
if ( V_33 & ( V_35 | V_36 | V_37 | V_40 ) ) {
F_14 ( L_20 , ( F_5 ( V_41 ) << 8 ) + F_5 ( V_42 ) ,
F_5 ( V_43 ) & 0xf , F_5 ( V_44 ) ) ;
if ( V_19 )
F_14 ( L_21 , F_15 ( V_19 ) ) ;
}
F_14 ( L_22 ) ;
}
#else
F_14 ( L_23 , V_22 , V_20 , V_21 & 0xff ) ;
if ( ( V_21 & V_32 ) == 0 ) {
V_33 = 0 ;
} else {
V_33 = F_5 ( V_34 ) ;
F_14 ( L_24 , V_22 , V_20 , V_33 & 0xff ) ;
}
#endif
}
static void F_16 ( void )
{
int V_3 = F_4 ( V_45 ) ;
if ( ! F_17 ( V_3 ) ) {
F_12 ( L_25 , V_3 ) ;
F_18 () ;
}
}
static int F_19 ( void )
{
int V_46 = 100000 ;
unsigned char V_47 ;
do {
V_47 = F_4 ( V_45 ) ;
} while ( ( V_47 & V_25 ) && -- V_46 );
return V_47 ;
}
static int F_20 ( void )
{
unsigned char V_47 = F_4 ( V_45 ) ;
if ( V_47 & V_25 )
return 1 ;
if ( V_47 & V_27 )
return 0 ;
if ( ! ( V_47 & V_26 ) )
return 0 ;
if ( ! ( V_47 & V_28 ) )
return 0 ;
return 1 ;
}
static int F_21 ( unsigned int V_48 , unsigned int V_10 )
{
int V_49 = 100 ;
do {
if ( F_19 () & V_25 )
return 0 ;
F_3 ( 0xA0 | ( V_48 << 4 ) | V_10 , V_43 ) ;
if ( F_20 () )
return 1 ;
} while ( -- V_49 );
return 0 ;
}
static void F_22 ( struct V_50 * V_51 ,
unsigned int V_52 ,
unsigned int V_11 ,
unsigned int V_10 ,
unsigned int V_12 ,
unsigned int V_53 ,
void (* F_23)( void ) )
{
unsigned short V_54 ;
#if ( V_55 > 0 )
while ( F_1 () - V_56 < V_55 )
;
#endif
if ( V_57 )
return;
if ( ! F_21 ( V_51 -> V_58 , V_10 ) ) {
V_57 = 1 ;
return;
}
F_24 ( F_23 ) ;
F_3 ( V_51 -> V_15 , V_59 ) ;
V_54 = V_60 ;
F_3 ( V_51 -> V_13 >> 2 , ++ V_54 ) ;
F_3 ( V_52 , ++ V_54 ) ;
F_3 ( V_11 , ++ V_54 ) ;
F_3 ( V_12 , ++ V_54 ) ;
F_3 ( V_12 >> 8 , ++ V_54 ) ;
F_3 ( 0xA0 | ( V_51 -> V_58 << 4 ) | V_10 , ++ V_54 ) ;
F_3 ( V_53 , ++ V_54 ) ;
}
static int F_25 ( void )
{
unsigned int V_3 ;
unsigned char V_61 ;
for ( V_3 = 0 ; V_3 < 500000 ; V_3 ++ ) {
V_61 = F_4 ( V_45 ) ;
if ( ( V_61 & ( V_25 | V_26 | V_28 ) ) == V_62 )
return 0 ;
}
F_12 ( L_26 , V_61 ) ;
return 1 ;
}
static void F_26 ( void )
{
int V_3 ;
F_3 ( 4 , V_59 ) ;
for ( V_3 = 0 ; V_3 < 1000 ; V_3 ++ ) F_27 () ;
F_3 ( V_9 [ 0 ] . V_15 & 0x0f , V_59 ) ;
for ( V_3 = 0 ; V_3 < 1000 ; V_3 ++ ) F_27 () ;
if ( F_25 () )
F_14 ( L_27 ) ;
else if ( ( V_33 = F_5 ( V_34 ) ) != 1 )
F_14 ( L_28 , V_33 ) ;
}
static void F_28 ( void )
{
static int V_3 ;
V_63:
if ( V_57 ) {
V_57 = 0 ;
V_3 = - 1 ;
F_26 () ;
} else {
F_16 () ;
if ( V_57 )
goto V_63;
}
if ( ++ V_3 < V_16 ) {
struct V_50 * V_51 = & V_9 [ V_3 ] ;
V_51 -> V_64 = V_51 -> V_65 = 1 ;
F_22 ( V_51 , V_51 -> V_11 , V_51 -> V_11 , V_51 -> V_10 - 1 ,
V_51 -> V_12 , V_66 , & F_28 ) ;
if ( V_57 )
goto V_63;
} else
F_29 () ;
}
static void F_30 ( void )
{
unsigned int V_21 = F_4 ( V_45 ) ;
if ( V_21 & ( V_25 | V_29 | V_30 | V_32 ) ) {
F_12 ( L_29 , V_21 ) ;
V_67 ;
}
}
static void F_18 ( void )
{
struct V_68 * V_69 = V_19 ;
if ( V_69 != NULL ) {
struct V_50 * V_51 = V_69 -> V_23 -> V_70 ;
if ( ++ V_69 -> V_71 >= V_72 || ( V_33 & V_35 ) ) {
F_10 ( - V_73 ) ;
V_51 -> V_64 = V_51 -> V_65 = 1 ;
} else if ( V_69 -> V_71 % V_74 == 0 )
V_57 = 1 ;
else if ( ( V_33 & V_39 ) || V_69 -> V_71 % V_75 == 0 )
V_51 -> V_64 = V_51 -> V_65 = 1 ;
}
}
static inline int F_31 ( void )
{
int V_46 ;
int V_21 ;
for ( V_46 = 0 ; V_46 < 100000 ; V_46 ++ ) {
V_21 = F_4 ( V_45 ) ;
if ( V_21 & V_29 )
return 0 ;
}
F_12 ( L_30 , V_21 ) ;
return - 1 ;
}
static void F_32 ( void )
{
struct V_68 * V_69 ;
int V_3 , V_46 = 100000 ;
do {
V_3 = ( unsigned ) F_4 ( V_45 ) ;
if ( V_3 & V_25 )
continue;
if ( ! F_17 ( V_3 ) )
break;
if ( V_3 & V_29 )
goto V_76;
} while ( -- V_46 > 0 );
F_12 ( L_31 , V_3 ) ;
F_18 () ;
F_29 () ;
return;
V_76:
V_69 = V_19 ;
F_33 ( V_60 , F_34 ( V_69 -> V_77 ) , 256 ) ;
#ifdef F_35
F_14 ( L_32 ,
V_69 -> V_23 -> V_24 , F_15 ( V_69 ) + 1 ,
F_36 ( V_69 ) - 1 , F_34 ( V_69 -> V_77 ) + 512 ) ;
#endif
if ( F_8 ( 0 , 512 ) ) {
F_24 ( & F_32 ) ;
return;
}
( void ) F_4 ( V_45 ) ;
#if ( V_55 > 0 )
V_56 = F_1 () ;
#endif
F_29 () ;
}
static void F_37 ( void )
{
struct V_68 * V_69 = V_19 ;
int V_3 ;
int V_46 = 100000 ;
do {
V_3 = ( unsigned ) F_4 ( V_45 ) ;
if ( V_3 & V_25 )
continue;
if ( ! F_17 ( V_3 ) )
break;
if ( ( F_36 ( V_69 ) <= 1 ) || ( V_3 & V_29 ) )
goto V_78;
} while ( -- V_46 > 0 );
F_12 ( L_33 , V_3 ) ;
F_18 () ;
F_29 () ;
return;
V_78:
if ( F_8 ( 0 , 512 ) ) {
F_24 ( & F_37 ) ;
F_38 ( V_60 , F_34 ( V_69 -> V_77 ) , 256 ) ;
return;
}
#if ( V_55 > 0 )
V_56 = F_1 () ;
#endif
F_29 () ;
}
static void F_39 ( void )
{
F_16 () ;
#if ( V_55 > 0 )
V_56 = F_1 () ;
#endif
F_29 () ;
}
static void F_40 ( unsigned long V_79 )
{
char * V_22 ;
V_80 = NULL ;
if ( ! V_19 )
return;
F_41 ( V_81 -> V_82 ) ;
V_57 = 1 ;
V_22 = V_19 -> V_23 -> V_24 ;
F_14 ( L_34 , V_22 ) ;
if ( ++ V_19 -> V_71 >= V_72 ) {
#ifdef F_35
F_14 ( L_35 , V_22 ) ;
#endif
F_10 ( - V_73 ) ;
}
F_29 () ;
F_42 ( V_81 -> V_82 ) ;
}
static int F_43 ( struct V_50 * V_51 , struct V_68 * V_69 )
{
if ( V_51 -> V_65 ) {
V_51 -> V_65 = 0 ;
F_22 ( V_51 , V_51 -> V_11 , 0 , 0 , 0 , V_83 , & F_39 ) ;
return V_57 ;
}
if ( V_51 -> V_10 > 16 ) {
F_14 ( L_36 , V_69 -> V_23 -> V_24 ) ;
F_10 ( - V_73 ) ;
}
V_51 -> V_64 = 0 ;
return 1 ;
}
static void F_29 ( void )
{
unsigned int V_84 , V_52 , V_85 , V_86 , V_10 , V_12 ;
struct V_50 * V_51 ;
struct V_68 * V_69 ;
if ( V_80 )
return;
V_63:
F_44 ( & V_87 ) ;
if ( ! V_19 ) {
V_19 = F_45 ( V_81 ) ;
if ( ! V_19 ) {
V_80 = NULL ;
return;
}
}
V_69 = V_19 ;
if ( V_57 ) {
F_28 () ;
return;
}
V_51 = V_69 -> V_23 -> V_70 ;
V_84 = F_15 ( V_69 ) ;
V_52 = F_36 ( V_69 ) ;
if ( V_84 >= F_46 ( V_69 -> V_23 ) ||
( ( V_84 + V_52 ) > F_46 ( V_69 -> V_23 ) ) ) {
F_14 ( L_37 ,
V_69 -> V_23 -> V_24 , V_84 , V_52 ) ;
F_10 ( - V_73 ) ;
goto V_63;
}
if ( V_51 -> V_64 ) {
if ( F_43 ( V_51 , V_69 ) )
goto V_63;
return;
}
V_85 = V_84 % V_51 -> V_11 + 1 ;
V_86 = V_84 / V_51 -> V_11 ;
V_10 = V_86 % V_51 -> V_10 ;
V_12 = V_86 / V_51 -> V_10 ;
#ifdef F_35
F_14 ( L_38 ,
V_69 -> V_23 -> V_24 ,
F_47 ( V_69 ) == V_88 ? L_39 : L_40 ,
V_12 , V_10 , V_85 , V_52 , F_34 ( V_69 -> V_77 ) ) ;
#endif
if ( V_69 -> V_89 == V_90 ) {
switch ( F_48 ( V_69 ) ) {
case V_88 :
F_22 ( V_51 , V_52 , V_85 , V_10 , V_12 , V_91 ,
& F_32 ) ;
if ( V_57 )
goto V_63;
break;
case V_92 :
F_22 ( V_51 , V_52 , V_85 , V_10 , V_12 , V_93 ,
& F_37 ) ;
if ( V_57 )
goto V_63;
if ( F_31 () ) {
F_18 () ;
goto V_63;
}
F_38 ( V_60 , F_34 ( V_69 -> V_77 ) , 256 ) ;
break;
default:
F_14 ( L_41 ) ;
F_10 ( - V_73 ) ;
break;
}
}
}
static void F_49 ( struct V_94 * V_95 )
{
F_29 () ;
}
static int F_50 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_50 * V_51 = V_97 -> V_100 -> V_70 ;
V_99 -> V_101 = V_51 -> V_10 ;
V_99 -> V_102 = V_51 -> V_11 ;
V_99 -> V_103 = V_51 -> V_12 ;
return 0 ;
}
static T_2 F_51 ( int V_104 , void * V_105 )
{
void (* F_52)( void ) = V_80 ;
F_53 ( V_81 -> V_82 ) ;
V_80 = NULL ;
F_44 ( & V_87 ) ;
if ( ! F_52 )
F_52 = F_30 ;
F_52 () ;
F_54 ( V_81 -> V_82 ) ;
return V_106 ;
}
static int T_1 F_55 ( void )
{
int V_48 ;
if ( F_56 ( V_107 , L_42 ) )
return - 1 ;
V_81 = F_57 ( F_49 , & V_108 ) ;
if ( ! V_81 ) {
F_58 ( V_107 , L_42 ) ;
return - V_109 ;
}
F_59 ( V_81 , 255 ) ;
F_60 ( & V_87 ) ;
V_87 . V_110 = F_40 ;
F_61 ( V_81 , 512 ) ;
if ( ! V_16 ) {
F_14 ( L_43
L_44 ) ;
goto V_111;
}
for ( V_48 = 0 ; V_48 < V_16 ; V_48 ++ ) {
struct V_112 * V_51 = F_62 ( 64 ) ;
struct V_50 * V_113 = & V_9 [ V_48 ] ;
if ( ! V_51 )
goto V_114;
V_51 -> V_115 = V_107 ;
V_51 -> V_116 = V_48 << 6 ;
V_51 -> V_117 = & V_118 ;
sprintf ( V_51 -> V_24 , L_45 , 'a' + V_48 ) ;
V_51 -> V_70 = V_113 ;
F_63 ( V_51 , V_113 -> V_10 * V_113 -> V_11 * V_113 -> V_12 ) ;
V_51 -> V_119 = V_81 ;
V_113 -> V_58 = V_48 ;
V_120 [ V_48 ] = V_51 ;
F_14 ( L_46 ,
V_51 -> V_24 , ( unsigned long ) F_46 ( V_51 ) / 2048 ,
V_113 -> V_12 , V_113 -> V_10 , V_113 -> V_11 ) ;
}
if ( F_64 ( V_121 , F_51 , V_122 , L_42 , NULL ) ) {
F_14 ( L_47 ,
V_121 ) ;
goto V_123;
}
if ( ! F_65 ( V_60 , 8 , L_42 ) ) {
F_14 ( V_124 L_48 , V_60 ) ;
goto V_125;
}
if ( ! F_65 ( V_59 , 1 , L_49 ) ) {
F_14 ( V_124 L_48 , V_59 ) ;
goto V_126;
}
for ( V_48 = 0 ; V_48 < V_16 ; V_48 ++ )
F_66 ( V_120 [ V_48 ] ) ;
return 0 ;
V_126:
F_67 ( V_60 , 8 ) ;
V_125:
F_68 ( V_121 , NULL ) ;
V_123:
for ( V_48 = 0 ; V_48 < V_16 ; V_48 ++ )
F_69 ( V_120 [ V_48 ] ) ;
V_16 = 0 ;
V_111:
F_44 ( & V_87 ) ;
F_58 ( V_107 , L_42 ) ;
F_70 ( V_81 ) ;
return - 1 ;
V_114:
while ( V_48 -- )
F_69 ( V_120 [ V_48 ] ) ;
goto V_111;
}
static int T_1 F_71 ( char * line )
{
int V_7 [ 6 ] ;
( void ) F_72 ( line , F_73 ( V_7 ) , V_7 ) ;
F_7 ( NULL , V_7 ) ;
return 1 ;
}
