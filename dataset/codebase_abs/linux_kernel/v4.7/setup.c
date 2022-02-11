void T_1 F_1 ( T_2 V_1 , T_2 V_2 , long type )
{
int V_3 = V_4 . V_5 ;
int V_6 ;
if ( V_1 + V_2 < V_1 ) {
F_2 ( L_1 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_7 * V_8 = V_4 . V_9 + V_6 ;
unsigned long V_10 ;
if ( V_8 -> type != type )
continue;
if ( V_1 + V_2 < V_8 -> V_11 )
continue;
if ( V_8 -> V_11 + V_8 -> V_2 < V_1 )
continue;
V_10 = F_3 ( V_8 -> V_11 + V_8 -> V_2 , V_1 + V_2 ) ;
V_8 -> V_11 = F_4 ( V_8 -> V_11 , V_1 ) ;
V_8 -> V_2 = V_10 - V_8 -> V_11 ;
return;
}
if ( V_4 . V_5 == V_12 ) {
F_5 ( L_2 ) ;
return;
}
V_4 . V_9 [ V_3 ] . V_11 = V_1 ;
V_4 . V_9 [ V_3 ] . V_2 = V_2 ;
V_4 . V_9 [ V_3 ] . type = type ;
V_4 . V_5 ++ ;
}
void T_1 F_6 ( T_2 V_1 , T_2 V_13 , T_2 V_14 )
{
void * V_15 = & V_16 ;
T_2 V_2 ;
for ( V_2 = V_13 ; V_2 < V_14 ; V_2 <<= 1 ) {
if ( ! memcmp ( V_15 , V_15 + V_2 , sizeof( V_16 ) ) )
break;
}
F_7 ( L_3 ,
( ( unsigned long long ) V_2 ) / V_17 ,
( unsigned long long ) V_1 ,
( ( unsigned long long ) V_13 ) / V_17 ,
( ( unsigned long long ) V_14 ) / V_17 ) ;
F_1 ( V_1 , V_2 , V_18 ) ;
}
static void T_1 F_8 ( void )
{
int V_6 ;
const int V_19 = 2 * sizeof( unsigned long ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
F_9 ( V_20 L_4 ,
V_19 , ( unsigned long long ) V_4 . V_9 [ V_6 ] . V_2 ,
V_19 , ( unsigned long long ) V_4 . V_9 [ V_6 ] . V_11 ) ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_18 :
F_9 ( V_21 L_5 ) ;
break;
case V_22 :
F_9 ( V_21 L_6 ) ;
break;
case V_23 :
F_9 ( V_21 L_7 ) ;
break;
case V_24 :
F_9 ( V_21 L_8 ) ;
break;
default:
F_9 ( V_21 L_9 , V_4 . V_9 [ V_6 ] . type ) ;
break;
}
}
}
static int T_1 F_10 ( char * V_25 )
{
unsigned long V_1 = F_11 ( V_25 , & V_25 ) ;
#ifdef F_12
if ( V_1 < V_26 )
V_1 = ( int ) V_1 ;
#endif
V_27 = V_1 ;
V_28 += V_1 ;
return 0 ;
}
static int T_1 F_13 ( char * V_25 )
{
V_28 += F_11 ( V_25 , & V_25 ) ;
return 0 ;
}
static unsigned long T_1 F_14 ( void )
{
unsigned long V_29 ;
if ( ! V_27 || V_28 <= V_27 )
goto V_30;
if ( V_27 & ~ V_31 ) {
F_5 ( L_10 ) ;
goto V_30;
}
if ( V_27 < V_32 ) {
F_5 ( L_11 ) ;
goto V_30;
}
V_29 = F_15 ( V_28 ) ;
V_28 = ( unsigned long ) F_16 ( V_29 ) ;
V_27 = ( unsigned long ) F_16 ( F_15 ( V_27 ) ) ;
V_33 = V_34 ;
return F_17 ( V_29 ) ;
V_30:
V_27 = 0 ;
V_28 = 0 ;
return 0 ;
}
static void T_1 F_18 ( void )
{
#if F_19 ( V_35 )
T_3 V_36 ;
if ( ! memcmp ( ( void * ) V_27 , L_12 , 6 ) )
return;
if ( F_20 ( ( unsigned char * ) V_27 , 8 , NULL ) )
return;
V_36 = F_21 ( ( T_3 * ) V_27 ) ;
if ( ! memcmp ( & V_36 , L_12 , 6 ) ||
F_20 ( ( unsigned char * ) ( & V_36 ) , 8 , NULL ) ) {
unsigned long V_6 ;
F_22 ( L_13 ) ;
for ( V_6 = V_27 ; V_6 < F_23 ( V_28 , 8 ) ; V_6 += 8 )
F_24 ( ( T_3 * ) V_6 ) ;
}
#endif
}
static void T_1 F_25 ( void )
{
unsigned long V_2 = V_28 - V_27 ;
if ( V_2 == 0 ) {
F_9 ( V_20 L_14 ) ;
goto V_30;
}
if ( F_15 ( V_28 ) > F_26 ( V_37 ) ) {
F_9 ( V_38 L_15 ) ;
goto V_30;
}
F_18 () ;
F_27 ( F_15 ( V_27 ) , V_2 , V_39 ) ;
V_40 = 1 ;
F_22 ( L_16 ,
V_27 , V_2 ) ;
return;
V_30:
F_9 ( V_21 L_17 ) ;
V_27 = 0 ;
V_28 = 0 ;
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
unsigned long V_41 ;
unsigned long V_42 = ~ 0UL ;
unsigned long V_43 ;
int V_6 ;
F_14 () ;
V_41 = ( unsigned long ) F_17 ( F_29 ( & V_44 ) ) ;
V_45 = ~ 0UL ;
V_37 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_29 ;
if ( V_4 . V_9 [ V_6 ] . type != V_18 )
continue;
V_1 = F_17 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_29 = F_30 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_29 > V_37 )
V_37 = V_29 ;
if ( V_1 < V_45 )
V_45 = V_1 ;
if ( V_29 <= V_41 )
continue;
#ifdef F_31
if ( V_28 && V_29 <= ( unsigned long ) F_17 ( F_15 ( V_28 ) ) )
continue;
#endif
if ( V_1 >= V_42 )
continue;
V_42 = F_3 ( V_41 , V_1 ) ;
}
if ( V_45 >= V_37 )
F_32 ( L_18 ) ;
if ( V_45 > V_46 ) {
F_22 ( L_19 ,
( V_45 - V_46 ) * sizeof( struct V_47 ) ,
V_45 - V_46 ) ;
} else if ( V_45 < V_46 ) {
F_22 ( L_20 ,
V_46 - V_45 ) ;
}
V_45 = V_46 ;
V_48 = V_37 ;
if ( V_37 > F_30 ( V_49 ) ) {
#ifdef F_33
V_50 = F_30 ( V_49 ) ;
V_51 = V_37 ;
#endif
V_37 = F_30 ( V_49 ) ;
}
#ifdef F_31
if ( V_28 )
V_42 = F_3 ( V_42 , ( unsigned long ) F_17 ( F_15 ( V_28 ) ) ) ;
#endif
V_43 = F_34 ( F_35 ( 0 ) , V_42 ,
V_45 , V_37 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_29 ;
V_1 = F_17 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_29 = F_30 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_1 <= V_45 )
V_1 = V_45 ;
if ( V_1 >= V_29 )
continue;
#ifndef F_33
if ( V_29 > V_37 )
V_29 = V_37 ;
if ( V_29 <= V_1 )
continue;
#endif
F_36 ( F_26 ( V_1 ) , F_26 ( V_29 - V_1 ) , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_29 , V_2 ;
V_1 = F_17 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_29 = F_30 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_18 :
break;
case V_22 :
F_37 ( 0 , V_1 , V_29 ) ;
continue;
default:
continue;
}
if ( V_1 >= V_37 )
continue;
if ( V_1 < V_41 )
V_1 = V_41 ;
if ( V_29 > V_37 )
V_29 = V_37 ;
if ( V_29 <= V_1 )
continue;
V_2 = V_29 - V_1 ;
F_38 ( F_26 ( V_1 ) , V_2 << V_52 ) ;
F_37 ( 0 , V_1 , V_29 ) ;
}
F_27 ( F_26 ( V_42 ) , V_43 , V_39 ) ;
#ifdef F_39
if ( F_29 ( V_53 ) > F_29 ( V_54 ) ) {
unsigned long V_55 ;
extern void V_56 ( const char * V_57 ) ;
V_55 = F_29 ( V_53 ) - F_29 ( V_54 ) ;
F_38 ( F_29 ( V_54 ) , V_55 ) ;
#if F_19 ( V_58 ) && F_19 ( V_59 )
V_56 ( V_20 ) ;
#endif
}
#endif
F_25 () ;
}
static int T_1 F_40 ( char * V_25 )
{
T_2 V_1 , V_2 ;
if ( V_60 == 0 ) {
V_4 . V_5 = 0 ;
V_60 = 1 ;
}
V_1 = 0 ;
V_2 = F_11 ( V_25 , & V_25 ) ;
if ( * V_25 == '@' )
V_1 = F_11 ( V_25 + 1 , & V_25 ) ;
F_1 ( V_1 , V_2 , V_18 ) ;
return 0 ;
}
static int T_1 F_41 ( char * V_25 )
{
int V_6 ;
V_61 = F_11 ( V_25 , & V_25 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 = V_4 . V_9 [ V_6 ] . V_11 ;
unsigned long V_29 = ( V_4 . V_9 [ V_6 ] . V_11 +
V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_61 >= V_1 && V_61 < V_29 ) {
V_62 = V_29 - V_61 ;
break;
}
}
return 0 ;
}
static void T_1 F_42 ( T_2 V_63 , T_2 V_29 , int type )
{
T_2 V_2 ;
int V_6 ;
V_2 = V_29 - V_63 ;
if ( ! V_2 )
return;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
if ( V_63 >= V_4 . V_9 [ V_6 ] . V_11 &&
V_63 < ( V_4 . V_9 [ V_6 ] . V_11 +
V_4 . V_9 [ V_6 ] . V_2 ) )
return;
}
F_1 ( V_63 , V_2 , type ) ;
}
static inline unsigned long long F_43 ( void )
{
unsigned long long V_64 ;
V_64 = V_48 - V_45 ;
return V_64 << V_52 ;
}
static void T_1 F_44 ( void )
{
unsigned long long V_65 ;
unsigned long long V_66 , V_67 ;
int V_68 ;
V_65 = F_43 () ;
V_68 = F_45 ( V_69 , V_65 ,
& V_66 , & V_67 ) ;
if ( V_68 != 0 || V_66 <= 0 )
return;
V_70 . V_1 = V_67 ;
V_70 . V_29 = V_67 + V_66 - 1 ;
}
static void T_1 F_46 ( struct V_71 * V_72 )
{
int V_68 ;
V_68 = F_47 ( V_72 , & V_70 ) ;
if ( ! V_68 )
F_22 ( L_21 ,
( unsigned long ) ( ( V_70 . V_29 -
V_70 . V_1 + 1 ) >> 20 ) ,
( unsigned long ) ( V_70 . V_1 >> 20 ) ) ;
}
static void T_1 F_44 ( void )
{
}
static void T_1 F_46 ( struct V_71 * V_72 )
{
}
static void T_1 F_48 ( char * * V_73 )
{
struct V_74 * V_75 ;
extern void V_76 ( void ) ;
V_76 () ;
F_42 ( F_30 ( F_29 ( & V_53 ) ) << V_52 ,
F_17 ( F_29 ( & V_77 ) ) << V_52 ,
V_18 ) ;
F_42 ( F_17 ( F_29 ( & V_78 ) ) << V_52 ,
F_30 ( F_29 ( & V_79 ) ) << V_52 ,
V_22 ) ;
F_22 ( L_22 ) ;
F_8 () ;
#if F_19 ( V_80 ) && F_19 ( V_81 )
F_49 ( V_69 , V_82 , V_83 ) ;
#else
if ( ( V_84 && V_85 [ 0 ] ) ||
( V_86 && ! V_69 [ 0 ] ) )
F_49 ( V_69 , V_85 , V_83 ) ;
if ( V_87 && V_85 [ 0 ] ) {
if ( V_69 [ 0 ] )
F_50 ( V_69 , L_23 , V_83 ) ;
F_50 ( V_69 , V_85 , V_83 ) ;
}
#if F_19 ( V_80 )
if ( V_82 [ 0 ] ) {
if ( V_69 [ 0 ] )
F_50 ( V_69 , L_23 , V_83 ) ;
F_50 ( V_69 , V_82 , V_83 ) ;
}
if ( V_88 && V_85 [ 0 ] ) {
if ( V_69 [ 0 ] )
F_50 ( V_69 , L_23 , V_83 ) ;
F_50 ( V_69 , V_85 , V_83 ) ;
}
#endif
#endif
F_49 ( V_89 , V_69 , V_83 ) ;
* V_73 = V_89 ;
F_51 () ;
if ( V_60 ) {
F_22 ( L_24 ) ;
F_8 () ;
}
F_28 () ;
#ifdef F_52
if ( V_61 && V_62 ) {
F_9 ( V_20 L_25 ,
V_61 , V_62 ) ;
F_27 ( V_61 , V_62 ,
V_39 ) ;
}
#endif
F_44 () ;
#ifdef F_53
if ( V_70 . V_1 != V_70 . V_29 )
F_27 ( V_70 . V_1 ,
V_70 . V_29 - V_70 . V_1 + 1 ,
V_39 ) ;
#endif
F_54 () ;
F_55 () ;
F_56 () ;
F_57 () ;
F_58 ( F_26 ( V_37 ) ) ;
F_59 (reserved, reg)
if ( V_75 -> V_2 != 0 )
F_27 ( V_75 -> V_90 , V_75 -> V_2 , V_39 ) ;
F_60 ( F_29 ( & V_91 ) ,
F_29 ( & V_92 ) ) ;
}
static void T_1 F_61 ( void )
{
int V_6 ;
if ( V_93 != V_94 )
return;
V_95 . V_1 = F_29 ( & V_53 ) ;
V_95 . V_29 = F_29 ( & V_96 ) - 1 ;
V_97 . V_1 = F_29 ( & V_96 ) ;
V_97 . V_29 = F_29 ( & V_77 ) - 1 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_71 * V_72 ;
unsigned long V_1 , V_29 ;
V_1 = V_4 . V_9 [ V_6 ] . V_11 ;
V_29 = V_4 . V_9 [ V_6 ] . V_11 + V_4 . V_9 [ V_6 ] . V_2 - 1 ;
if ( V_1 >= V_49 )
continue;
if ( V_29 >= V_49 )
V_29 = V_49 - 1 ;
V_72 = F_62 ( sizeof( struct V_71 ) ) ;
V_72 -> V_1 = V_1 ;
V_72 -> V_29 = V_29 ;
V_72 -> V_98 = V_99 | V_100 ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_18 :
case V_22 :
case V_23 :
V_72 -> V_101 = L_26 ;
V_72 -> V_98 |= V_102 ;
break;
case V_24 :
default:
V_72 -> V_101 = L_27 ;
}
F_47 ( & V_103 , V_72 ) ;
F_47 ( V_72 , & V_95 ) ;
F_47 ( V_72 , & V_97 ) ;
F_46 ( V_72 ) ;
}
}
static void T_1 F_63 ( void )
{
int V_6 , V_104 = F_64 () ;
if ( V_104 > V_105 )
V_104 = V_105 ;
for ( V_6 = 0 ; V_6 < V_104 ; V_6 ++ )
F_65 ( V_6 , true ) ;
for (; V_6 < V_106 ; V_6 ++ )
F_65 ( V_6 , false ) ;
V_105 = V_104 ;
}
static inline void F_63 ( void ) {}
void T_1 F_66 ( char * * V_73 )
{
F_67 () ;
F_68 () ;
F_69 () ;
F_70 () ;
#ifdef F_71
F_72 () ;
#endif
F_73 () ;
F_74 () ;
#if F_19 ( V_107 )
#if F_19 ( V_108 )
V_109 = & V_110 ;
#elif F_19 ( V_111 )
V_109 = & V_112 ;
#endif
#endif
F_48 ( V_73 ) ;
F_61 () ;
F_75 () ;
F_63 () ;
F_76 () ;
}
static int T_1 F_77 ( void )
{
struct V_113 * V_114 ;
V_114 = F_78 ( L_28 , NULL ) ;
if ( ! V_114 )
return - V_115 ;
V_116 = V_114 ;
return 0 ;
}
