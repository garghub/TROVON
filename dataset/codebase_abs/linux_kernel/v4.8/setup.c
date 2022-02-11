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
static void T_1 F_8 ( void )
{
int V_6 ;
const int V_20 = 2 * sizeof( unsigned long ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
F_9 ( V_21 L_4 ,
V_20 , ( unsigned long long ) V_4 . V_10 [ V_6 ] . V_2 ,
V_20 , ( unsigned long long ) V_4 . V_10 [ V_6 ] . V_12 ) ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_19 :
F_9 ( V_22 L_5 ) ;
break;
case V_23 :
F_9 ( V_22 L_6 ) ;
break;
case V_24 :
F_9 ( V_22 L_7 ) ;
break;
case V_25 :
F_9 ( V_22 L_8 ) ;
break;
default:
F_9 ( V_22 L_9 , V_4 . V_10 [ V_6 ] . type ) ;
break;
}
}
}
static int T_1 F_10 ( char * V_26 )
{
unsigned long V_1 = F_11 ( V_26 , & V_26 ) ;
#ifdef F_12
if ( V_1 < V_27 )
V_1 = ( int ) V_1 ;
#endif
V_28 = V_1 ;
V_29 += V_1 ;
return 0 ;
}
static int T_1 F_13 ( char * V_26 )
{
V_29 += F_11 ( V_26 , & V_26 ) ;
return 0 ;
}
static unsigned long T_1 F_14 ( void )
{
unsigned long V_30 ;
if ( ! V_28 || V_29 <= V_28 )
goto V_31;
if ( V_28 & ~ V_32 ) {
F_5 ( L_10 ) ;
goto V_31;
}
if ( V_28 < V_33 ) {
F_5 ( L_11 ) ;
goto V_31;
}
V_30 = F_15 ( V_29 ) ;
V_29 = ( unsigned long ) F_16 ( V_30 ) ;
V_28 = ( unsigned long ) F_16 ( F_15 ( V_28 ) ) ;
V_34 = V_35 ;
return F_17 ( V_30 ) ;
V_31:
V_28 = 0 ;
V_29 = 0 ;
return 0 ;
}
static void T_1 F_18 ( void )
{
#if F_19 ( V_36 )
T_3 V_37 ;
if ( ! memcmp ( ( void * ) V_28 , L_12 , 6 ) )
return;
if ( F_20 ( ( unsigned char * ) V_28 , 8 , NULL ) )
return;
V_37 = F_21 ( ( T_3 * ) V_28 ) ;
if ( ! memcmp ( & V_37 , L_12 , 6 ) ||
F_20 ( ( unsigned char * ) ( & V_37 ) , 8 , NULL ) ) {
unsigned long V_6 ;
F_22 ( L_13 ) ;
for ( V_6 = V_28 ; V_6 < F_23 ( V_29 , 8 ) ; V_6 += 8 )
F_24 ( ( T_3 * ) V_6 ) ;
}
#endif
}
static void T_1 F_25 ( void )
{
unsigned long V_2 = V_29 - V_28 ;
if ( V_2 == 0 ) {
F_9 ( V_21 L_14 ) ;
goto V_31;
}
if ( F_15 ( V_29 ) > F_26 ( V_38 ) ) {
F_9 ( V_39 L_15 ) ;
goto V_31;
}
F_18 () ;
F_27 ( F_15 ( V_28 ) , V_2 , V_40 ) ;
V_41 = 1 ;
F_22 ( L_16 ,
V_28 , V_2 ) ;
return;
V_31:
F_9 ( V_22 L_17 ) ;
V_28 = 0 ;
V_29 = 0 ;
}
static unsigned long T_1 F_14 ( void )
{
return 0 ;
}
static void T_1 F_28 ( void )
{
F_14 () ;
F_25 () ;
}
static void T_1 F_28 ( void )
{
unsigned long V_42 ;
unsigned long V_43 = ~ 0UL ;
unsigned long V_44 ;
int V_6 ;
F_14 () ;
V_42 = ( unsigned long ) F_17 ( F_29 ( & V_45 ) ) ;
V_46 = ~ 0UL ;
V_38 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_30 ;
if ( V_4 . V_10 [ V_6 ] . type != V_19 )
continue;
V_1 = F_17 ( V_4 . V_10 [ V_6 ] . V_12 ) ;
V_30 = F_30 ( V_4 . V_10 [ V_6 ] . V_12
+ V_4 . V_10 [ V_6 ] . V_2 ) ;
if ( V_30 > V_38 )
V_38 = V_30 ;
if ( V_1 < V_46 )
V_46 = V_1 ;
if ( V_30 <= V_42 )
continue;
#ifdef F_31
if ( V_29 && V_30 <= ( unsigned long ) F_17 ( F_15 ( V_29 ) ) )
continue;
#endif
if ( V_1 >= V_43 )
continue;
V_43 = F_3 ( V_42 , V_1 ) ;
}
if ( V_46 >= V_38 )
F_32 ( L_18 ) ;
if ( V_46 > V_47 ) {
F_22 ( L_19 ,
( V_46 - V_47 ) * sizeof( struct V_48 ) ,
V_46 - V_47 ) ;
} else if ( V_46 < V_47 ) {
F_22 ( L_20 ,
V_47 - V_46 ) ;
}
V_46 = V_47 ;
V_49 = V_38 ;
if ( V_38 > F_30 ( V_50 ) ) {
#ifdef F_33
V_51 = F_30 ( V_50 ) ;
V_52 = V_38 ;
#endif
V_38 = F_30 ( V_50 ) ;
}
#ifdef F_31
if ( V_29 )
V_43 = F_3 ( V_43 , ( unsigned long ) F_17 ( F_15 ( V_29 ) ) ) ;
#endif
V_44 = F_34 ( F_35 ( 0 ) , V_43 ,
V_46 , V_38 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_30 ;
V_1 = F_17 ( V_4 . V_10 [ V_6 ] . V_12 ) ;
V_30 = F_30 ( V_4 . V_10 [ V_6 ] . V_12
+ V_4 . V_10 [ V_6 ] . V_2 ) ;
if ( V_1 <= V_46 )
V_1 = V_46 ;
if ( V_1 >= V_30 )
continue;
#ifndef F_33
if ( V_30 > V_38 )
V_30 = V_38 ;
if ( V_30 <= V_1 )
continue;
#endif
F_36 ( F_26 ( V_1 ) , F_26 ( V_30 - V_1 ) , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_30 , V_2 ;
V_1 = F_17 ( V_4 . V_10 [ V_6 ] . V_12 ) ;
V_30 = F_30 ( V_4 . V_10 [ V_6 ] . V_12
+ V_4 . V_10 [ V_6 ] . V_2 ) ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_19 :
break;
case V_23 :
F_37 ( 0 , V_1 , V_30 ) ;
continue;
default:
continue;
}
if ( V_1 >= V_38 )
continue;
if ( V_1 < V_42 )
V_1 = V_42 ;
if ( V_30 > V_38 )
V_30 = V_38 ;
if ( V_30 <= V_1 )
continue;
V_2 = V_30 - V_1 ;
F_38 ( F_26 ( V_1 ) , V_2 << V_53 ) ;
F_37 ( 0 , V_1 , V_30 ) ;
}
F_27 ( F_26 ( V_43 ) , V_44 , V_40 ) ;
#ifdef F_39
if ( F_29 ( V_54 ) > F_29 ( V_55 ) ) {
unsigned long V_56 ;
extern void V_57 ( const char * V_58 ) ;
V_56 = F_29 ( V_54 ) - F_29 ( V_55 ) ;
F_38 ( F_29 ( V_55 ) , V_56 ) ;
#if F_19 ( V_59 ) && F_19 ( V_60 )
V_57 ( V_21 ) ;
#endif
}
#endif
F_25 () ;
}
static int T_1 F_40 ( char * V_26 )
{
T_2 V_1 , V_2 ;
if ( V_61 == 0 ) {
V_4 . V_5 = 0 ;
V_61 = 1 ;
}
V_1 = 0 ;
V_2 = F_11 ( V_26 , & V_26 ) ;
if ( * V_26 == '@' )
V_1 = F_11 ( V_26 + 1 , & V_26 ) ;
F_1 ( V_1 , V_2 , V_19 ) ;
return 0 ;
}
static int T_1 F_41 ( char * V_26 )
{
int V_6 ;
V_62 = F_11 ( V_26 , & V_26 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 = V_4 . V_10 [ V_6 ] . V_12 ;
unsigned long V_30 = ( V_4 . V_10 [ V_6 ] . V_12 +
V_4 . V_10 [ V_6 ] . V_2 ) ;
if ( V_62 >= V_1 && V_62 < V_30 ) {
V_63 = V_30 - V_62 ;
break;
}
}
return 0 ;
}
static void T_1 F_42 ( T_2 V_64 , T_2 V_30 , int type )
{
T_2 V_2 ;
int V_6 ;
V_2 = V_30 - V_64 ;
if ( ! V_2 )
return;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
if ( V_64 >= V_4 . V_10 [ V_6 ] . V_12 &&
V_64 < ( V_4 . V_10 [ V_6 ] . V_12 +
V_4 . V_10 [ V_6 ] . V_2 ) )
return;
}
F_1 ( V_64 , V_2 , type ) ;
}
static inline unsigned long long F_43 ( void )
{
unsigned long long V_65 ;
V_65 = V_49 - V_46 ;
return V_65 << V_53 ;
}
static void T_1 F_44 ( void )
{
unsigned long long V_66 ;
unsigned long long V_67 , V_68 ;
int V_69 ;
V_66 = F_43 () ;
V_69 = F_45 ( V_70 , V_66 ,
& V_67 , & V_68 ) ;
if ( V_69 != 0 || V_67 <= 0 )
return;
V_71 . V_1 = V_68 ;
V_71 . V_30 = V_68 + V_67 - 1 ;
}
static void T_1 F_46 ( struct V_72 * V_73 )
{
int V_69 ;
V_69 = F_47 ( V_73 , & V_71 ) ;
if ( ! V_69 )
F_22 ( L_21 ,
( unsigned long ) ( ( V_71 . V_30 -
V_71 . V_1 + 1 ) >> 20 ) ,
( unsigned long ) ( V_71 . V_1 >> 20 ) ) ;
}
static void T_1 F_44 ( void )
{
}
static void T_1 F_46 ( struct V_72 * V_73 )
{
}
static void T_1 F_48 ( char * * V_74 )
{
struct V_75 * V_76 ;
extern void V_77 ( void ) ;
V_77 () ;
F_42 ( F_30 ( F_29 ( & V_54 ) ) << V_53 ,
F_17 ( F_29 ( & V_78 ) ) << V_53 ,
V_19 ) ;
F_42 ( F_17 ( F_29 ( & V_79 ) ) << V_53 ,
F_30 ( F_29 ( & V_80 ) ) << V_53 ,
V_23 ) ;
F_22 ( L_22 ) ;
F_8 () ;
#if F_19 ( V_81 ) && F_19 ( V_82 )
F_49 ( V_70 , V_83 , V_84 ) ;
#else
if ( ( V_85 && V_86 [ 0 ] ) ||
( V_87 && ! V_70 [ 0 ] ) )
F_49 ( V_70 , V_86 , V_84 ) ;
if ( V_88 && V_86 [ 0 ] ) {
if ( V_70 [ 0 ] )
F_50 ( V_70 , L_23 , V_84 ) ;
F_50 ( V_70 , V_86 , V_84 ) ;
}
#if F_19 ( V_81 )
if ( V_83 [ 0 ] ) {
if ( V_70 [ 0 ] )
F_50 ( V_70 , L_23 , V_84 ) ;
F_50 ( V_70 , V_83 , V_84 ) ;
}
if ( V_89 && V_86 [ 0 ] ) {
if ( V_70 [ 0 ] )
F_50 ( V_70 , L_23 , V_84 ) ;
F_50 ( V_70 , V_86 , V_84 ) ;
}
#endif
#endif
F_49 ( V_90 , V_70 , V_84 ) ;
* V_74 = V_90 ;
F_51 () ;
if ( V_61 ) {
F_22 ( L_24 ) ;
F_8 () ;
}
F_28 () ;
#ifdef F_52
if ( V_62 && V_63 ) {
F_9 ( V_21 L_25 ,
V_62 , V_63 ) ;
F_27 ( V_62 , V_63 ,
V_40 ) ;
}
#endif
F_44 () ;
#ifdef F_53
if ( V_71 . V_1 != V_71 . V_30 )
F_27 ( V_71 . V_1 ,
V_71 . V_30 - V_71 . V_1 + 1 ,
V_40 ) ;
#endif
F_54 () ;
F_55 () ;
F_56 () ;
F_57 ( F_26 ( V_38 ) ) ;
F_58 (reserved, reg)
if ( V_76 -> V_2 != 0 )
F_27 ( V_76 -> V_91 , V_76 -> V_2 , V_40 ) ;
F_59 ( F_29 ( & V_92 ) ,
F_29 ( & V_93 ) ) ;
}
static void T_1 F_60 ( void )
{
int V_6 ;
if ( V_94 != V_95 )
return;
V_96 . V_1 = F_29 ( & V_54 ) ;
V_96 . V_30 = F_29 ( & V_97 ) - 1 ;
V_98 . V_1 = F_29 ( & V_97 ) ;
V_98 . V_30 = F_29 ( & V_78 ) - 1 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_72 * V_73 ;
unsigned long V_1 , V_30 ;
V_1 = V_4 . V_10 [ V_6 ] . V_12 ;
V_30 = V_4 . V_10 [ V_6 ] . V_12 + V_4 . V_10 [ V_6 ] . V_2 - 1 ;
if ( V_1 >= V_50 )
continue;
if ( V_30 >= V_50 )
V_30 = V_50 - 1 ;
V_73 = F_61 ( sizeof( struct V_72 ) ) ;
V_73 -> V_1 = V_1 ;
V_73 -> V_30 = V_30 ;
V_73 -> V_99 = V_100 | V_101 ;
switch ( V_4 . V_10 [ V_6 ] . type ) {
case V_19 :
case V_23 :
case V_24 :
V_73 -> V_102 = L_26 ;
V_73 -> V_99 |= V_103 ;
break;
case V_25 :
default:
V_73 -> V_102 = L_27 ;
}
F_47 ( & V_104 , V_73 ) ;
F_47 ( V_73 , & V_96 ) ;
F_47 ( V_73 , & V_98 ) ;
F_46 ( V_73 ) ;
}
}
static void T_1 F_62 ( void )
{
int V_6 , V_105 = F_63 () ;
if ( V_105 > V_106 )
V_105 = V_106 ;
for ( V_6 = 0 ; V_6 < V_105 ; V_6 ++ )
F_64 ( V_6 , true ) ;
for (; V_6 < V_107 ; V_6 ++ )
F_64 ( V_6 , false ) ;
V_106 = V_105 ;
}
static inline void F_62 ( void ) {}
void T_1 F_65 ( char * * V_74 )
{
F_66 () ;
F_67 () ;
F_68 () ;
F_69 () ;
#ifdef F_70
F_71 () ;
#endif
F_72 () ;
F_73 () ;
#if F_19 ( V_108 )
#if F_19 ( V_109 )
V_110 = & V_111 ;
#elif F_19 ( V_112 )
V_110 = & V_113 ;
#endif
#endif
F_48 ( V_74 ) ;
F_60 () ;
F_74 () ;
F_62 () ;
F_75 () ;
F_76 () ;
}
static int T_1 F_77 ( void )
{
struct V_114 * V_115 ;
V_115 = F_78 ( L_28 , NULL ) ;
if ( ! V_115 )
return - V_116 ;
V_117 = V_115 ;
return 0 ;
}
