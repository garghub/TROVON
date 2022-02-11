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
static void T_1 F_6 ( void )
{
int V_6 ;
const int V_13 = 2 * sizeof( unsigned long ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
F_7 ( V_14 L_3 ,
V_13 , ( unsigned long long ) V_4 . V_9 [ V_6 ] . V_2 ,
V_13 , ( unsigned long long ) V_4 . V_9 [ V_6 ] . V_11 ) ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_15 :
F_7 ( V_16 L_4 ) ;
break;
case V_17 :
F_7 ( V_16 L_5 ) ;
break;
case V_18 :
F_7 ( V_16 L_6 ) ;
break;
case V_19 :
F_7 ( V_16 L_7 ) ;
break;
default:
F_7 ( V_16 L_8 , V_4 . V_9 [ V_6 ] . type ) ;
break;
}
}
}
static int T_1 F_8 ( char * V_20 )
{
unsigned long V_1 = F_9 ( V_20 , & V_20 ) ;
#ifdef F_10
if ( V_1 < V_21 )
V_1 = ( int ) V_1 ;
#endif
V_22 = V_1 ;
V_23 += V_1 ;
return 0 ;
}
static int T_1 F_11 ( char * V_20 )
{
V_23 += F_9 ( V_20 , & V_20 ) ;
return 0 ;
}
static unsigned long T_1 F_12 ( void )
{
unsigned long V_24 ;
if ( ! V_22 || V_23 <= V_22 )
goto V_25;
if ( V_22 & ~ V_26 ) {
F_5 ( L_9 ) ;
goto V_25;
}
if ( V_22 < V_27 ) {
F_5 ( L_10 ) ;
goto V_25;
}
V_24 = F_13 ( V_23 ) ;
V_23 = ( unsigned long ) F_14 ( V_24 ) ;
V_22 = ( unsigned long ) F_14 ( F_13 ( V_22 ) ) ;
V_28 = V_29 ;
return F_15 ( V_24 ) ;
V_25:
V_22 = 0 ;
V_23 = 0 ;
return 0 ;
}
static void T_1 F_16 ( void )
{
unsigned long V_2 = V_23 - V_22 ;
if ( V_2 == 0 ) {
F_7 ( V_14 L_11 ) ;
goto V_25;
}
if ( F_13 ( V_23 ) > F_17 ( V_30 ) ) {
F_7 ( V_31 L_12 ) ;
goto V_25;
}
F_18 ( F_13 ( V_22 ) , V_2 , V_32 ) ;
V_33 = 1 ;
F_19 ( L_13 ,
V_22 , V_2 ) ;
return;
V_25:
F_7 ( V_16 L_14 ) ;
V_22 = 0 ;
V_23 = 0 ;
}
static unsigned long T_1 F_12 ( void )
{
return 0 ;
}
static void T_1 F_20 ( void )
{
F_12 () ;
F_16 () ;
}
static void T_1 F_20 ( void )
{
unsigned long V_34 ;
unsigned long V_35 = ~ 0UL ;
unsigned long V_36 ;
int V_6 ;
V_34 = F_3 ( F_12 () ,
( unsigned long ) F_15 ( F_21 ( & V_37 ) ) ) ;
V_38 = ~ 0UL ;
V_30 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_24 ;
if ( V_4 . V_9 [ V_6 ] . type != V_15 )
continue;
V_1 = F_15 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_24 = F_22 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_24 > V_30 )
V_30 = V_24 ;
if ( V_1 < V_38 )
V_38 = V_1 ;
if ( V_24 <= V_34 )
continue;
if ( V_1 >= V_35 )
continue;
V_35 = F_3 ( V_34 , V_1 ) ;
}
if ( V_38 >= V_30 )
F_23 ( L_15 ) ;
if ( V_38 > V_39 ) {
F_19 ( L_16 ,
( V_38 - V_39 ) * sizeof( struct V_40 ) ,
V_38 - V_39 ) ;
} else if ( V_38 < V_39 ) {
F_19 ( L_17 ,
V_39 - V_38 ) ;
}
V_38 = V_39 ;
V_41 = V_30 ;
if ( V_30 > F_22 ( V_42 ) ) {
#ifdef F_24
V_43 = F_22 ( V_42 ) ;
V_44 = V_30 ;
#endif
V_30 = F_22 ( V_42 ) ;
}
V_36 = F_25 ( F_26 ( 0 ) , V_35 ,
V_38 , V_30 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_24 ;
V_1 = F_15 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_24 = F_22 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_1 <= V_38 )
V_1 = V_38 ;
if ( V_1 >= V_24 )
continue;
#ifndef F_24
if ( V_24 > V_30 )
V_24 = V_30 ;
if ( V_24 <= V_1 )
continue;
#endif
F_27 ( F_17 ( V_1 ) , F_17 ( V_24 - V_1 ) , 0 ) ;
}
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 , V_24 , V_2 ;
V_1 = F_15 ( V_4 . V_9 [ V_6 ] . V_11 ) ;
V_24 = F_22 ( V_4 . V_9 [ V_6 ] . V_11
+ V_4 . V_9 [ V_6 ] . V_2 ) ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_15 :
break;
case V_17 :
F_28 ( 0 , V_1 , V_24 ) ;
continue;
default:
continue;
}
if ( V_1 >= V_30 )
continue;
if ( V_1 < V_34 )
V_1 = V_34 ;
if ( V_24 > V_30 )
V_24 = V_30 ;
if ( V_24 <= V_1 )
continue;
V_2 = V_24 - V_1 ;
F_29 ( F_17 ( V_1 ) , V_2 << V_45 ) ;
F_28 ( 0 , V_1 , V_24 ) ;
}
F_18 ( F_17 ( V_35 ) , V_36 , V_32 ) ;
F_16 () ;
}
static int T_1 F_30 ( char * V_20 )
{
unsigned long V_1 , V_2 ;
if ( V_46 == 0 ) {
V_4 . V_5 = 0 ;
V_46 = 1 ;
}
V_1 = 0 ;
V_2 = F_9 ( V_20 , & V_20 ) ;
if ( * V_20 == '@' )
V_1 = F_9 ( V_20 + 1 , & V_20 ) ;
F_1 ( V_1 , V_2 , V_15 ) ;
return 0 ;
}
static int T_1 F_31 ( char * V_20 )
{
int V_6 ;
V_47 = F_9 ( V_20 , & V_20 ) ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
unsigned long V_1 = V_4 . V_9 [ V_6 ] . V_11 ;
unsigned long V_24 = ( V_4 . V_9 [ V_6 ] . V_11 +
V_4 . V_9 [ V_6 ] . V_2 ) ;
if ( V_47 >= V_1 && V_47 < V_24 ) {
V_48 = V_24 - V_47 ;
break;
}
}
return 0 ;
}
static void T_1 F_32 ( T_2 V_49 , T_2 V_24 , int type )
{
T_2 V_2 ;
int V_6 ;
V_2 = V_24 - V_49 ;
if ( ! V_2 )
return;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
if ( V_49 >= V_4 . V_9 [ V_6 ] . V_11 &&
V_49 < ( V_4 . V_9 [ V_6 ] . V_11 +
V_4 . V_9 [ V_6 ] . V_2 ) )
return;
}
F_1 ( V_49 , V_2 , type ) ;
}
static void T_1 F_33 ( char * * V_50 )
{
extern void V_51 ( void ) ;
V_51 () ;
F_32 ( F_22 ( F_21 ( & V_52 ) ) << V_45 ,
F_15 ( F_21 ( & V_53 ) ) << V_45 ,
V_15 ) ;
F_32 ( F_15 ( F_21 ( & V_54 ) ) << V_45 ,
F_22 ( F_21 ( & V_55 ) ) << V_45 ,
V_17 ) ;
F_19 ( L_18 ) ;
F_6 () ;
#ifdef F_34
#ifdef F_35
F_36 ( V_56 , V_57 , V_58 ) ;
#else
if ( V_57 [ 0 ] ) {
F_37 ( V_59 , L_19 , V_58 ) ;
F_37 ( V_59 , V_57 , V_58 ) ;
}
F_36 ( V_56 , V_59 , V_58 ) ;
#endif
#else
F_36 ( V_56 , V_59 , V_58 ) ;
#endif
F_36 ( V_60 , V_56 , V_58 ) ;
* V_50 = V_60 ;
F_38 () ;
if ( V_46 ) {
F_19 ( L_20 ) ;
F_6 () ;
}
F_20 () ;
#ifdef F_39
if ( V_47 && V_48 ) {
F_7 ( V_14 L_21 ,
V_47 , V_48 ) ;
F_18 ( V_47 , V_48 ,
V_32 ) ;
}
#endif
#ifdef F_40
if ( V_61 . V_1 != V_61 . V_24 )
F_18 ( V_61 . V_1 ,
V_61 . V_24 - V_61 . V_1 + 1 ,
V_32 ) ;
#endif
F_41 () ;
F_42 () ;
F_43 () ;
F_44 () ;
}
static inline unsigned long long F_45 ( void )
{
unsigned long long V_62 ;
V_62 = V_41 - V_38 ;
return V_62 << V_45 ;
}
static void T_1 F_46 ( void )
{
unsigned long long V_63 ;
unsigned long long V_64 , V_65 ;
int V_66 ;
V_63 = F_45 () ;
V_66 = F_47 ( V_56 , V_63 ,
& V_64 , & V_65 ) ;
if ( V_66 != 0 || V_64 <= 0 )
return;
V_61 . V_1 = V_65 ;
V_61 . V_24 = V_65 + V_64 - 1 ;
}
static void T_1 F_48 ( struct V_67 * V_68 )
{
int V_66 ;
V_66 = F_49 ( V_68 , & V_61 ) ;
if ( ! V_66 )
F_19 ( L_22 ,
( unsigned long ) ( ( V_61 . V_24 -
V_61 . V_1 + 1 ) >> 20 ) ,
( unsigned long ) ( V_61 . V_1 >> 20 ) ) ;
}
static void T_1 F_46 ( void )
{
}
static void T_1 F_48 ( struct V_67 * V_68 )
{
}
static void T_1 F_50 ( void )
{
int V_6 ;
if ( V_69 != V_70 )
return;
V_71 . V_1 = F_21 ( & V_52 ) ;
V_71 . V_24 = F_21 ( & V_72 ) - 1 ;
V_73 . V_1 = F_21 ( & V_72 ) ;
V_73 . V_24 = F_21 ( & V_53 ) - 1 ;
F_46 () ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_67 * V_68 ;
unsigned long V_1 , V_24 ;
V_1 = V_4 . V_9 [ V_6 ] . V_11 ;
V_24 = V_4 . V_9 [ V_6 ] . V_11 + V_4 . V_9 [ V_6 ] . V_2 - 1 ;
if ( V_1 >= V_42 )
continue;
if ( V_24 >= V_42 )
V_24 = V_42 - 1 ;
V_68 = F_51 ( sizeof( struct V_67 ) ) ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_15 :
case V_17 :
case V_18 :
V_68 -> V_74 = L_23 ;
break;
case V_19 :
default:
V_68 -> V_74 = L_24 ;
}
V_68 -> V_1 = V_1 ;
V_68 -> V_24 = V_24 ;
V_68 -> V_75 = V_76 | V_77 ;
F_49 ( & V_78 , V_68 ) ;
F_49 ( V_68 , & V_71 ) ;
F_49 ( V_68 , & V_73 ) ;
F_48 ( V_68 ) ;
}
}
void T_1 F_52 ( char * * V_50 )
{
F_53 () ;
F_54 () ;
#ifdef F_55
F_56 () ;
#endif
F_57 () ;
F_58 () ;
#if F_59 ( V_79 )
#if F_59 ( V_80 )
V_81 = & V_82 ;
#elif F_59 ( V_83 )
V_81 = & V_84 ;
#endif
#endif
F_33 ( V_50 ) ;
F_50 () ;
F_60 () ;
F_61 () ;
}
static int T_1 F_62 ( void )
{
struct V_85 * V_86 ;
V_86 = F_63 ( L_25 , NULL ) ;
if ( ! V_86 )
return - V_87 ;
V_88 = V_86 ;
return 0 ;
}
