void T_1 F_1 ( T_2 V_1 , T_2 V_2 , long type )
{
int V_3 = V_4 . V_5 ;
int V_6 ;
if ( V_1 + V_2 - 1 == ( T_2 ) V_7 )
-- V_2 ;
if ( V_1 + V_2 < V_1 ) {
F_2 ( L_1 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_8 * V_9 = V_4 . V_10 + V_6 ;
unsigned long V_11 ;
if ( V_9 -> type != type )
continue;
if ( V_1 + V_2 < V_9 -> V_12 )
continue;
if ( V_9 -> V_12 + V_9 -> V_2 < V_1 )
continue;
V_11 = F_3 ( V_9 -> V_12 + V_9 -> V_2 , V_1 + V_2 ) ;
V_9 -> V_12 = F_4 ( V_9 -> V_12 , V_1 ) ;
V_9 -> V_2 = V_11 - V_9 -> V_12 ;
return;
}
if ( V_4 . V_5 == V_13 ) {
F_5 ( L_2 ) ;
return;
}
V_4 . V_10 [ V_3 ] . V_12 = V_1 ;
V_4 . V_10 [ V_3 ] . V_2 = V_2 ;
V_4 . V_10 [ V_3 ] . type = type ;
V_4 . V_5 ++ ;
}
void T_1 F_6 ( T_2 V_1 , T_2 V_14 , T_2 V_15 )
{
void * V_16 = & V_17 ;
T_2 V_2 ;
for ( V_2 = V_14 ; V_2 < V_15 ; V_2 <<= 1 ) {
if ( ! memcmp ( V_16 , V_16 + V_2 , sizeof( V_17 ) ) )
break;
}
F_7 ( L_3 ,
( ( unsigned long long ) V_2 ) / V_18 ,
( unsigned long long ) V_1 ,
( ( unsigned long long ) V_14 ) / V_18 ,
( ( unsigned long long ) V_15 ) / V_18 ) ;
F_1 ( V_1 , V_2 , V_19 ) ;
}
bool T_1 F_8 ( T_2 V_1 , T_2 V_2 )
{
int V_6 ;
bool V_20 = false , free = true ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
T_2 V_21 , V_22 ;
V_21 = V_4 . V_10 [ V_6 ] . V_12 ;
V_22 = V_4 . V_10 [ V_6 ] . V_12 + V_4 . V_10 [ V_6 ] . V_2 ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_19 :
if ( V_1 >= V_21 && V_1 + V_2 <= V_22 )
V_20 = true ;
break;
case V_23 :
if ( ( V_1 >= V_21 && V_1 < V_22 ) ||
( V_1 < V_21 && V_1 + V_2 >= V_21 ) )
free = false ;
break;
default:
continue;
}
}
return V_20 && free ;
}
static void T_1 F_9 ( void )
{
int V_6 ;
const int V_24 = 2 * sizeof( unsigned long ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
F_10 ( V_25 L_4 ,
V_24 , ( unsigned long long ) V_4 . V_10 [ V_6 ] . V_2 ,
V_24 , ( unsigned long long ) V_4 . V_10 [ V_6 ] . V_12 ) ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_19 :
F_10 ( V_26 L_5 ) ;
break;
case V_27 :
F_10 ( V_26 L_6 ) ;
break;
case V_28 :
F_10 ( V_26 L_7 ) ;
break;
case V_23 :
F_10 ( V_26 L_8 ) ;
break;
default:
F_10 ( V_26 L_9 , V_4 . V_10 [ V_6 ] . type ) ;
break;
}
}
}
static int T_1 F_11 ( char * V_29 )
{
unsigned long V_1 = F_12 ( V_29 , & V_29 ) ;
#ifdef F_13
if ( V_1 < V_30 )
V_1 = ( int ) V_1 ;
#endif
V_31 = V_1 ;
V_32 += V_1 ;
return 0 ;
}
static int T_1 F_14 ( char * V_29 )
{
V_32 += F_12 ( V_29 , & V_29 ) ;
return 0 ;
}
static unsigned long T_1 F_15 ( void )
{
unsigned long V_33 ;
if ( ! V_31 || V_32 <= V_31 )
goto V_34;
if ( V_31 & ~ V_35 ) {
F_5 ( L_10 ) ;
goto V_34;
}
if ( V_31 < V_36 ) {
F_5 ( L_11 ) ;
goto V_34;
}
V_33 = F_16 ( V_32 ) ;
V_32 = ( unsigned long ) F_17 ( V_33 ) ;
V_31 = ( unsigned long ) F_17 ( F_16 ( V_31 ) ) ;
V_37 = V_38 ;
return F_18 ( V_33 ) ;
V_34:
V_31 = 0 ;
V_32 = 0 ;
return 0 ;
}
static void T_1 F_19 ( void )
{
#if F_20 ( V_39 )
T_3 V_40 ;
if ( ! memcmp ( ( void * ) V_31 , L_12 , 6 ) )
return;
if ( F_21 ( ( unsigned char * ) V_31 , 8 , NULL ) )
return;
V_40 = F_22 ( ( T_3 * ) V_31 ) ;
if ( ! memcmp ( & V_40 , L_12 , 6 ) ||
F_21 ( ( unsigned char * ) ( & V_40 ) , 8 , NULL ) ) {
unsigned long V_6 ;
F_23 ( L_13 ) ;
for ( V_6 = V_31 ; V_6 < F_24 ( V_32 , 8 ) ; V_6 += 8 )
F_25 ( ( T_3 * ) V_6 ) ;
}
#endif
}
static void T_1 F_26 ( void )
{
unsigned long V_2 = V_32 - V_31 ;
if ( V_2 == 0 ) {
F_10 ( V_25 L_14 ) ;
goto V_34;
}
if ( F_16 ( V_32 ) > F_27 ( V_41 ) ) {
F_10 ( V_42 L_15 ) ;
goto V_34;
}
F_19 () ;
F_28 ( F_16 ( V_31 ) , V_2 , V_43 ) ;
V_44 = 1 ;
F_23 ( L_16 ,
V_31 , V_2 ) ;
return;
V_34:
F_10 ( V_26 L_17 ) ;
V_31 = 0 ;
V_32 = 0 ;
}
static unsigned long T_1 F_15 ( void )
{
return 0 ;
}
static void T_1 F_29 ( void )
{
F_15 () ;
F_26 () ;
}
static unsigned long T_1 F_30 ( unsigned long V_45 )
{
unsigned long V_46 = F_31 ( V_45 , 8 ) ;
return F_24 ( V_46 , sizeof( long ) ) ;
}
static void T_1 F_29 ( void )
{
unsigned long V_47 ;
unsigned long V_48 = ~ 0UL ;
unsigned long V_49 ;
bool V_50 = false ;
int V_6 ;
F_15 () ;
V_47 = ( unsigned long ) F_18 ( F_32 ( & V_51 ) ) ;
V_52 = ~ 0UL ;
V_41 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_33 ;
if ( V_4 . V_10 [ V_6 ] . type != V_19 )
continue;
V_1 = F_18 ( V_4 . V_10 [ V_6 ] . V_12 ) ;
V_33 = F_33 ( V_4 . V_10 [ V_6 ] . V_12
+ V_4 . V_10 [ V_6 ] . V_2 ) ;
#ifndef F_34
if ( V_1 >= F_33 ( V_53 ) )
continue;
if ( V_33 > F_33 ( V_53 ) )
V_33 = F_33 ( V_53 ) ;
#endif
if ( V_33 > V_41 )
V_41 = V_33 ;
if ( V_1 < V_52 )
V_52 = V_1 ;
if ( V_33 <= V_47 )
continue;
#ifdef F_35
if ( V_32 && V_33 <= ( unsigned long ) F_18 ( F_16 ( V_32 ) ) )
continue;
#endif
if ( V_1 >= V_48 )
continue;
V_48 = F_3 ( V_47 , V_1 ) ;
}
if ( V_52 >= V_41 )
F_36 ( L_18 ) ;
if ( V_52 > V_54 ) {
F_23 ( L_19 ,
( V_52 - V_54 ) * sizeof( struct V_55 ) ,
V_52 - V_54 ) ;
} else if ( V_52 < V_54 ) {
F_23 ( L_20 ,
V_54 - V_52 ) ;
}
V_52 = V_54 ;
V_56 = V_41 ;
if ( V_41 > F_33 ( V_53 ) ) {
#ifdef F_34
V_57 = F_33 ( V_53 ) ;
V_58 = V_41 ;
#endif
V_41 = F_33 ( V_53 ) ;
}
#ifdef F_35
if ( V_32 )
V_48 = F_3 ( V_48 , ( unsigned long ) F_18 ( F_16 ( V_32 ) ) ) ;
#endif
V_49 = F_30 ( V_41 - V_52 ) ;
V_50 = F_8 ( F_27 ( V_48 ) ,
V_49 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 && ! V_50 ; V_6 ++ ) {
unsigned long V_59 ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_23 :
V_59 = F_37 ( V_4 . V_10 [ V_6 ] . V_12 +
V_4 . V_10 [ V_6 ] . V_2 ) ;
if ( F_38 ( V_59 ) < V_48 )
break;
V_50 = F_8 ( V_59 ,
V_49 ) ;
if ( V_50 )
V_48 = F_38 ( V_59 ) ;
break;
default:
break;
}
}
if ( ! V_50 )
F_36 ( L_21 ) ;
if ( V_49 != F_39 ( F_40 ( 0 ) , V_48 ,
V_52 , V_41 ) )
F_36 ( L_22 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_33 ;
V_1 = F_18 ( V_4 . V_10 [ V_6 ] . V_12 ) ;
V_33 = F_33 ( V_4 . V_10 [ V_6 ] . V_12
+ V_4 . V_10 [ V_6 ] . V_2 ) ;
if ( V_1 <= V_52 )
V_1 = V_52 ;
if ( V_1 >= V_33 )
continue;
#ifndef F_34
if ( V_33 > V_41 )
V_33 = V_41 ;
if ( V_33 <= V_1 )
continue;
#endif
F_41 ( F_27 ( V_1 ) , F_27 ( V_33 - V_1 ) , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_33 , V_2 ;
V_1 = F_18 ( V_4 . V_10 [ V_6 ] . V_12 ) ;
V_33 = F_33 ( V_4 . V_10 [ V_6 ] . V_12
+ V_4 . V_10 [ V_6 ] . V_2 ) ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_19 :
break;
case V_27 :
F_42 ( 0 , V_1 , V_33 ) ;
continue;
default:
if ( V_1 > V_52 && V_33 < V_41 )
F_28 ( V_4 . V_10 [ V_6 ] . V_12 ,
V_4 . V_10 [ V_6 ] . V_2 ,
V_43 ) ;
continue;
}
if ( V_1 >= V_41 )
continue;
if ( V_1 < V_47 )
V_1 = V_47 ;
if ( V_33 > V_41 )
V_33 = V_41 ;
if ( V_33 <= V_1 )
continue;
V_2 = V_33 - V_1 ;
F_43 ( F_27 ( V_1 ) , V_2 << V_60 ) ;
F_42 ( 0 , V_1 , V_33 ) ;
}
F_28 ( F_27 ( V_48 ) , V_49 , V_43 ) ;
#ifdef F_44
if ( F_32 ( V_61 ) > F_32 ( V_62 ) ) {
unsigned long V_63 ;
extern void V_64 ( const char * V_65 ) ;
V_63 = F_32 ( V_61 ) - F_32 ( V_62 ) ;
F_43 ( F_32 ( V_62 ) , V_63 ) ;
#if F_20 ( V_66 ) && F_20 ( V_67 )
V_64 ( V_25 ) ;
#endif
}
#endif
F_26 () ;
}
static int T_1 F_45 ( char * V_29 )
{
T_2 V_1 , V_2 ;
if ( V_68 == 0 ) {
V_4 . V_5 = 0 ;
V_68 = 1 ;
}
V_1 = 0 ;
V_2 = F_12 ( V_29 , & V_29 ) ;
if ( * V_29 == '@' )
V_1 = F_12 ( V_29 + 1 , & V_29 ) ;
F_1 ( V_1 , V_2 , V_19 ) ;
if ( V_1 && V_1 > V_69 )
F_1 ( V_69 , V_1 - V_69 ,
V_23 ) ;
return 0 ;
}
static int T_1 F_46 ( char * V_29 )
{
char * V_70 ;
T_3 V_71 , V_72 ;
if ( ! V_29 )
return - V_73 ;
if ( ! strncmp ( V_29 , L_23 , 8 ) ) {
F_5 ( L_24 ) ;
return 0 ;
}
V_70 = V_29 ;
V_72 = F_12 ( V_29 , & V_29 ) ;
if ( V_29 == V_70 )
return - V_73 ;
if ( * V_29 == '@' ) {
V_71 = F_12 ( V_29 + 1 , & V_29 ) ;
F_1 ( V_71 , V_72 , V_19 ) ;
} else if ( * V_29 == '#' ) {
F_5 ( L_25 ) ;
return - V_73 ;
} else if ( * V_29 == '$' ) {
V_71 = F_12 ( V_29 + 1 , & V_29 ) ;
F_1 ( V_71 , V_72 , V_23 ) ;
} else {
F_5 ( L_26 ) ;
return - V_73 ;
}
if ( * V_29 == '\0' ) {
V_68 = 1 ;
return 0 ;
} else
return - V_73 ;
}
static int T_1 F_47 ( char * V_29 )
{
int V_6 ;
V_74 = F_12 ( V_29 , & V_29 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 = V_4 . V_10 [ V_6 ] . V_12 ;
unsigned long V_33 = ( V_4 . V_10 [ V_6 ] . V_12 +
V_4 . V_10 [ V_6 ] . V_2 ) ;
if ( V_74 >= V_1 && V_74 < V_33 ) {
V_75 = V_33 - V_74 ;
break;
}
}
return 0 ;
}
static void T_1 F_48 ( T_2 V_76 , T_2 V_33 , int type )
{
T_2 V_2 ;
int V_6 ;
V_2 = V_33 - V_76 ;
if ( ! V_2 )
return;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
if ( V_76 >= V_4 . V_10 [ V_6 ] . V_12 &&
V_76 < ( V_4 . V_10 [ V_6 ] . V_12 +
V_4 . V_10 [ V_6 ] . V_2 ) )
return;
}
F_1 ( V_76 , V_2 , type ) ;
}
static inline unsigned long long F_49 ( void )
{
unsigned long long V_77 ;
V_77 = V_56 - V_52 ;
return V_77 << V_60 ;
}
static void T_1 F_50 ( void )
{
unsigned long long V_78 ;
unsigned long long V_79 , V_80 ;
int V_81 ;
V_78 = F_49 () ;
V_81 = F_51 ( V_82 , V_78 ,
& V_79 , & V_80 ) ;
if ( V_81 != 0 || V_79 <= 0 )
return;
if ( ! F_8 ( V_80 , V_79 ) ) {
F_2 ( L_27 ) ;
return;
}
V_83 . V_1 = V_80 ;
V_83 . V_33 = V_80 + V_79 - 1 ;
}
static void T_1 F_52 ( struct V_84 * V_85 )
{
int V_81 ;
if ( V_83 . V_1 == V_83 . V_33 )
return;
V_81 = F_53 ( V_85 , & V_83 ) ;
if ( ! V_81 )
F_23 ( L_28 ,
( unsigned long ) ( ( V_83 . V_33 -
V_83 . V_1 + 1 ) >> 20 ) ,
( unsigned long ) ( V_83 . V_1 >> 20 ) ) ;
}
static void T_1 F_50 ( void )
{
}
static void T_1 F_52 ( struct V_84 * V_85 )
{
}
static void T_1 F_54 ( char * * V_86 )
{
struct V_87 * V_88 ;
extern void V_89 ( void ) ;
V_89 () ;
F_48 ( F_33 ( F_32 ( & V_61 ) ) << V_60 ,
F_18 ( F_32 ( & V_90 ) ) << V_60 ,
V_19 ) ;
F_48 ( F_18 ( F_32 ( & V_91 ) ) << V_60 ,
F_33 ( F_32 ( & V_92 ) ) << V_60 ,
V_27 ) ;
F_23 ( L_29 ) ;
F_9 () ;
#if F_20 ( V_93 ) && F_20 ( V_94 )
F_55 ( V_82 , V_95 , V_96 ) ;
#else
if ( ( V_97 && V_98 [ 0 ] ) ||
( V_99 && ! V_82 [ 0 ] ) )
F_55 ( V_82 , V_98 , V_96 ) ;
if ( V_100 && V_98 [ 0 ] ) {
if ( V_82 [ 0 ] )
F_56 ( V_82 , L_30 , V_96 ) ;
F_56 ( V_82 , V_98 , V_96 ) ;
}
#if F_20 ( V_93 )
if ( V_95 [ 0 ] ) {
if ( V_82 [ 0 ] )
F_56 ( V_82 , L_30 , V_96 ) ;
F_56 ( V_82 , V_95 , V_96 ) ;
}
if ( V_101 && V_98 [ 0 ] ) {
if ( V_82 [ 0 ] )
F_56 ( V_82 , L_30 , V_96 ) ;
F_56 ( V_82 , V_98 , V_96 ) ;
}
#endif
#endif
F_55 ( V_102 , V_82 , V_96 ) ;
* V_86 = V_102 ;
F_57 () ;
if ( V_68 ) {
F_23 ( L_31 ) ;
F_9 () ;
}
F_58 () ;
F_59 () ;
F_29 () ;
#ifdef F_60
if ( V_74 && V_75 ) {
F_10 ( V_25 L_32 ,
V_74 , V_75 ) ;
F_28 ( V_74 , V_75 ,
V_43 ) ;
}
#endif
F_50 () ;
#ifdef F_61
if ( V_83 . V_1 != V_83 . V_33 )
F_28 ( V_83 . V_1 ,
V_83 . V_33 - V_83 . V_1 + 1 ,
V_43 ) ;
#endif
F_62 () ;
F_63 () ;
F_64 () ;
F_65 ( F_27 ( V_41 ) ) ;
F_66 (reserved, reg)
if ( V_88 -> V_2 != 0 )
F_28 ( V_88 -> V_103 , V_88 -> V_2 , V_43 ) ;
F_67 ( F_32 ( & V_104 ) ,
F_32 ( & V_105 ) ) ;
}
static void T_1 F_68 ( void )
{
int V_6 ;
if ( V_106 != V_107 )
return;
V_108 . V_1 = F_32 ( & V_61 ) ;
V_108 . V_33 = F_32 ( & V_109 ) - 1 ;
V_110 . V_1 = F_32 ( & V_109 ) ;
V_110 . V_33 = F_32 ( & V_90 ) - 1 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_84 * V_85 ;
unsigned long V_1 , V_33 ;
V_1 = V_4 . V_10 [ V_6 ] . V_12 ;
V_33 = V_4 . V_10 [ V_6 ] . V_12 + V_4 . V_10 [ V_6 ] . V_2 - 1 ;
if ( V_1 >= V_53 )
continue;
if ( V_33 >= V_53 )
V_33 = V_53 - 1 ;
V_85 = F_69 ( sizeof( struct V_84 ) ) ;
V_85 -> V_1 = V_1 ;
V_85 -> V_33 = V_33 ;
V_85 -> V_111 = V_112 | V_113 ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_19 :
case V_27 :
case V_28 :
V_85 -> V_114 = L_33 ;
V_85 -> V_111 |= V_115 ;
break;
case V_23 :
default:
V_85 -> V_114 = L_34 ;
}
F_53 ( & V_116 , V_85 ) ;
F_53 ( V_85 , & V_108 ) ;
F_53 ( V_85 , & V_110 ) ;
F_52 ( V_85 ) ;
}
}
static void T_1 F_70 ( void )
{
int V_6 , V_117 = F_71 () ;
if ( V_117 > V_118 )
V_117 = V_118 ;
for ( V_6 = 0 ; V_6 < V_117 ; V_6 ++ )
F_72 ( V_6 , true ) ;
for (; V_6 < V_119 ; V_6 ++ )
F_72 ( V_6 , false ) ;
V_118 = V_117 ;
}
static inline void F_70 ( void ) {}
void T_1 F_73 ( char * * V_86 )
{
F_74 () ;
F_75 () ;
F_76 () ;
F_77 () ;
#ifdef F_78
F_79 () ;
#endif
F_80 () ;
F_81 () ;
#if F_20 ( V_120 )
#if F_20 ( V_121 )
V_122 = & V_123 ;
#elif F_20 ( V_124 )
V_122 = & V_125 ;
#endif
#endif
F_54 ( V_86 ) ;
F_68 () ;
F_82 () ;
F_70 () ;
F_83 () ;
F_84 () ;
}
static int T_1 F_85 ( void )
{
struct V_126 * V_127 ;
V_127 = F_86 ( L_35 , NULL ) ;
if ( ! V_127 )
return - V_128 ;
V_129 = V_127 ;
return 0 ;
}
