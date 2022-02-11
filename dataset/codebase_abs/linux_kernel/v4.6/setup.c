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
unsigned long V_2 = V_28 - V_27 ;
if ( V_2 == 0 ) {
F_9 ( V_20 L_12 ) ;
goto V_30;
}
if ( F_15 ( V_28 ) > F_19 ( V_35 ) ) {
F_9 ( V_36 L_13 ) ;
goto V_30;
}
F_20 ( F_15 ( V_27 ) , V_2 , V_37 ) ;
V_38 = 1 ;
F_21 ( L_14 ,
V_27 , V_2 ) ;
return;
V_30:
F_9 ( V_21 L_15 ) ;
V_27 = 0 ;
V_28 = 0 ;
}
static unsigned long T_1 F_14 ( void )
{
return 0 ;
}
static void T_1 F_22 ( void )
{
F_14 () ;
F_18 () ;
}
static void T_1 F_22 ( void )
{
unsigned long V_39 ;
unsigned long V_40 = ~ 0UL ;
unsigned long V_41 ;
int V_6 ;
F_14 () ;
V_39 = ( unsigned long ) F_17 ( F_23 ( & V_42 ) ) ;
V_43 = ~ 0UL ;
V_35 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_29 ;
if ( V_4 . V_9 [ V_6 ] . type != V_18 )
continue;
V_1 = F_17 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_29 = F_24 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_29 > V_35 )
V_35 = V_29 ;
if ( V_1 < V_43 )
V_43 = V_1 ;
if ( V_29 <= V_39 )
continue;
#ifdef F_25
if ( V_28 && V_29 <= ( unsigned long ) F_17 ( F_15 ( V_28 ) ) )
continue;
#endif
if ( V_1 >= V_40 )
continue;
V_40 = F_3 ( V_39 , V_1 ) ;
}
if ( V_43 >= V_35 )
F_26 ( L_16 ) ;
if ( V_43 > V_44 ) {
F_21 ( L_17 ,
( V_43 - V_44 ) * sizeof( struct V_45 ) ,
V_43 - V_44 ) ;
} else if ( V_43 < V_44 ) {
F_21 ( L_18 ,
V_44 - V_43 ) ;
}
V_43 = V_44 ;
V_46 = V_35 ;
if ( V_35 > F_24 ( V_47 ) ) {
#ifdef F_27
V_48 = F_24 ( V_47 ) ;
V_49 = V_35 ;
#endif
V_35 = F_24 ( V_47 ) ;
}
#ifdef F_25
if ( V_28 )
V_40 = F_3 ( V_40 , ( unsigned long ) F_17 ( F_15 ( V_28 ) ) ) ;
#endif
V_41 = F_28 ( F_29 ( 0 ) , V_40 ,
V_43 , V_35 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_29 ;
V_1 = F_17 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_29 = F_24 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_1 <= V_43 )
V_1 = V_43 ;
if ( V_1 >= V_29 )
continue;
#ifndef F_27
if ( V_29 > V_35 )
V_29 = V_35 ;
if ( V_29 <= V_1 )
continue;
#endif
F_30 ( F_19 ( V_1 ) , F_19 ( V_29 - V_1 ) , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_29 , V_2 ;
V_1 = F_17 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_29 = F_24 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_18 :
break;
case V_22 :
F_31 ( 0 , V_1 , V_29 ) ;
continue;
default:
continue;
}
if ( V_1 >= V_35 )
continue;
if ( V_1 < V_39 )
V_1 = V_39 ;
if ( V_29 > V_35 )
V_29 = V_35 ;
if ( V_29 <= V_1 )
continue;
V_2 = V_29 - V_1 ;
F_32 ( F_19 ( V_1 ) , V_2 << V_50 ) ;
F_31 ( 0 , V_1 , V_29 ) ;
}
F_20 ( F_19 ( V_40 ) , V_41 , V_37 ) ;
F_18 () ;
}
static int T_1 F_33 ( char * V_25 )
{
T_2 V_1 , V_2 ;
if ( V_51 == 0 ) {
V_4 . V_5 = 0 ;
V_51 = 1 ;
}
V_1 = 0 ;
V_2 = F_11 ( V_25 , & V_25 ) ;
if ( * V_25 == '@' )
V_1 = F_11 ( V_25 + 1 , & V_25 ) ;
F_1 ( V_1 , V_2 , V_18 ) ;
return 0 ;
}
static int T_1 F_34 ( char * V_25 )
{
int V_6 ;
V_52 = F_11 ( V_25 , & V_25 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 = V_4 . V_9 [ V_6 ] . V_11 ;
unsigned long V_29 = ( V_4 . V_9 [ V_6 ] . V_11 +
V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_52 >= V_1 && V_52 < V_29 ) {
V_53 = V_29 - V_52 ;
break;
}
}
return 0 ;
}
static void T_1 F_35 ( T_2 V_54 , T_2 V_29 , int type )
{
T_2 V_2 ;
int V_6 ;
V_2 = V_29 - V_54 ;
if ( ! V_2 )
return;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
if ( V_54 >= V_4 . V_9 [ V_6 ] . V_11 &&
V_54 < ( V_4 . V_9 [ V_6 ] . V_11 +
V_4 . V_9 [ V_6 ] . V_2 ) )
return;
}
F_1 ( V_54 , V_2 , type ) ;
}
static inline unsigned long long F_36 ( void )
{
unsigned long long V_55 ;
V_55 = V_46 - V_43 ;
return V_55 << V_50 ;
}
static void T_1 F_37 ( void )
{
unsigned long long V_56 ;
unsigned long long V_57 , V_58 ;
int V_59 ;
V_56 = F_36 () ;
V_59 = F_38 ( V_60 , V_56 ,
& V_57 , & V_58 ) ;
if ( V_59 != 0 || V_57 <= 0 )
return;
V_61 . V_1 = V_58 ;
V_61 . V_29 = V_58 + V_57 - 1 ;
}
static void T_1 F_39 ( struct V_62 * V_63 )
{
int V_59 ;
V_59 = F_40 ( V_63 , & V_61 ) ;
if ( ! V_59 )
F_21 ( L_19 ,
( unsigned long ) ( ( V_61 . V_29 -
V_61 . V_1 + 1 ) >> 20 ) ,
( unsigned long ) ( V_61 . V_1 >> 20 ) ) ;
}
static void T_1 F_37 ( void )
{
}
static void T_1 F_39 ( struct V_62 * V_63 )
{
}
static void T_1 F_41 ( char * * V_64 )
{
struct V_65 * V_66 ;
extern void V_67 ( void ) ;
V_67 () ;
F_35 ( F_24 ( F_23 ( & V_68 ) ) << V_50 ,
F_17 ( F_23 ( & V_69 ) ) << V_50 ,
V_18 ) ;
F_35 ( F_17 ( F_23 ( & V_70 ) ) << V_50 ,
F_24 ( F_23 ( & V_71 ) ) << V_50 ,
V_22 ) ;
F_21 ( L_20 ) ;
F_8 () ;
#if F_42 ( V_72 ) && F_42 ( V_73 )
F_43 ( V_60 , V_74 , V_75 ) ;
#else
if ( ( V_76 && V_77 [ 0 ] ) ||
( V_78 && ! V_60 [ 0 ] ) )
F_43 ( V_60 , V_77 , V_75 ) ;
if ( V_79 && V_77 [ 0 ] ) {
F_44 ( V_60 , L_21 , V_75 ) ;
F_44 ( V_60 , V_77 , V_75 ) ;
}
#if F_42 ( V_72 )
if ( V_74 [ 0 ] ) {
F_44 ( V_60 , L_21 , V_75 ) ;
F_44 ( V_60 , V_74 , V_75 ) ;
}
#endif
#endif
F_43 ( V_80 , V_60 , V_75 ) ;
* V_64 = V_80 ;
F_45 () ;
if ( V_51 ) {
F_21 ( L_22 ) ;
F_8 () ;
}
F_22 () ;
#ifdef F_46
if ( V_52 && V_53 ) {
F_9 ( V_20 L_23 ,
V_52 , V_53 ) ;
F_20 ( V_52 , V_53 ,
V_37 ) ;
}
#endif
F_37 () ;
#ifdef F_47
if ( V_61 . V_1 != V_61 . V_29 )
F_20 ( V_61 . V_1 ,
V_61 . V_29 - V_61 . V_1 + 1 ,
V_37 ) ;
#endif
F_48 () ;
F_49 () ;
F_50 () ;
F_51 () ;
F_52 ( F_19 ( V_35 ) ) ;
F_53 (reserved, reg)
if ( V_66 -> V_2 != 0 )
F_20 ( V_66 -> V_81 , V_66 -> V_2 , V_37 ) ;
}
static void T_1 F_54 ( void )
{
int V_6 ;
if ( V_82 != V_83 )
return;
V_84 . V_1 = F_23 ( & V_68 ) ;
V_84 . V_29 = F_23 ( & V_85 ) - 1 ;
V_86 . V_1 = F_23 ( & V_85 ) ;
V_86 . V_29 = F_23 ( & V_69 ) - 1 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_62 * V_63 ;
unsigned long V_1 , V_29 ;
V_1 = V_4 . V_9 [ V_6 ] . V_11 ;
V_29 = V_4 . V_9 [ V_6 ] . V_11 + V_4 . V_9 [ V_6 ] . V_2 - 1 ;
if ( V_1 >= V_47 )
continue;
if ( V_29 >= V_47 )
V_29 = V_47 - 1 ;
V_63 = F_55 ( sizeof( struct V_62 ) ) ;
V_63 -> V_1 = V_1 ;
V_63 -> V_29 = V_29 ;
V_63 -> V_87 = V_88 | V_89 ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_18 :
case V_22 :
case V_23 :
V_63 -> V_90 = L_24 ;
V_63 -> V_87 |= V_91 ;
break;
case V_24 :
default:
V_63 -> V_90 = L_25 ;
}
F_40 ( & V_92 , V_63 ) ;
F_40 ( V_63 , & V_84 ) ;
F_40 ( V_63 , & V_86 ) ;
F_39 ( V_63 ) ;
}
}
static void T_1 F_56 ( void )
{
int V_6 , V_93 = F_57 () ;
if ( V_93 > V_94 )
V_93 = V_94 ;
for ( V_6 = 0 ; V_6 < V_93 ; V_6 ++ )
F_58 ( V_6 , true ) ;
for (; V_6 < V_95 ; V_6 ++ )
F_58 ( V_6 , false ) ;
V_94 = V_93 ;
}
static inline void F_56 ( void ) {}
void T_1 F_59 ( char * * V_64 )
{
F_60 () ;
F_61 () ;
F_62 () ;
F_63 () ;
#ifdef F_64
F_65 () ;
#endif
F_66 () ;
F_67 () ;
#if F_42 ( V_96 )
#if F_42 ( V_97 )
V_98 = & V_99 ;
#elif F_42 ( V_100 )
V_98 = & V_101 ;
#endif
#endif
F_41 ( V_64 ) ;
F_54 () ;
F_68 () ;
F_56 () ;
F_69 () ;
}
static int T_1 F_70 ( void )
{
struct V_102 * V_103 ;
V_103 = F_71 ( L_26 , NULL ) ;
if ( ! V_103 )
return - V_104 ;
V_105 = V_103 ;
return 0 ;
}
