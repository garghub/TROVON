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
static void T_1 F_31 ( char * * V_47 )
{
T_2 V_48 , V_49 , V_50 ;
extern void V_51 ( void ) ;
V_51 () ;
V_48 = F_15 ( F_21 ( & V_52 ) ) << V_45 ;
V_49 = F_22 ( F_21 ( & V_53 ) ) << V_45 ;
V_50 = V_49 - V_48 ;
if ( V_50 ) {
int V_6 , V_54 ;
V_54 = 0 ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
if ( V_48 >= V_4 . V_9 [ V_6 ] . V_11 &&
V_48 < ( V_4 . V_9 [ V_6 ] . V_11 +
V_4 . V_9 [ V_6 ] . V_2 ) ) {
V_54 = 1 ;
break;
}
}
if ( ! V_54 )
F_1 ( V_48 , V_50 ,
V_17 ) ;
}
F_19 ( L_18 ) ;
F_6 () ;
#ifdef F_32
#ifdef F_33
F_34 ( V_55 , V_56 , V_57 ) ;
#else
if ( V_56 [ 0 ] ) {
F_35 ( V_58 , L_19 , V_57 ) ;
F_35 ( V_58 , V_56 , V_57 ) ;
}
F_34 ( V_55 , V_58 , V_57 ) ;
#endif
#else
F_34 ( V_55 , V_58 , V_57 ) ;
#endif
F_34 ( V_59 , V_55 , V_57 ) ;
* V_47 = V_59 ;
F_36 () ;
if ( V_46 ) {
F_19 ( L_20 ) ;
F_6 () ;
}
F_20 () ;
#ifdef F_37
if ( V_60 . V_1 != V_60 . V_24 )
F_18 ( V_60 . V_1 ,
V_60 . V_24 - V_60 . V_1 + 1 ,
V_32 ) ;
#endif
F_38 () ;
F_39 () ;
F_40 () ;
F_41 () ;
}
static inline unsigned long long F_42 ( void )
{
unsigned long long V_61 ;
V_61 = V_41 - V_38 ;
return V_61 << V_45 ;
}
static void T_1 F_43 ( void )
{
unsigned long long V_62 ;
unsigned long long V_63 , V_64 ;
int V_65 ;
V_62 = F_42 () ;
V_65 = F_44 ( V_55 , V_62 ,
& V_63 , & V_64 ) ;
if ( V_65 != 0 || V_63 <= 0 )
return;
V_60 . V_1 = V_64 ;
V_60 . V_24 = V_64 + V_63 - 1 ;
}
static void T_1 F_45 ( struct V_66 * V_67 )
{
int V_65 ;
V_65 = F_46 ( V_67 , & V_60 ) ;
if ( ! V_65 )
F_19 ( L_21 ,
( unsigned long ) ( ( V_60 . V_24 -
V_60 . V_1 + 1 ) >> 20 ) ,
( unsigned long ) ( V_60 . V_1 >> 20 ) ) ;
}
static void T_1 F_43 ( void )
{
}
static void T_1 F_45 ( struct V_66 * V_67 )
{
}
static void T_1 F_47 ( void )
{
int V_6 ;
if ( V_68 != V_69 )
return;
V_70 . V_1 = F_21 ( & V_71 ) ;
V_70 . V_24 = F_21 ( & V_72 ) - 1 ;
V_73 . V_1 = F_21 ( & V_72 ) ;
V_73 . V_24 = F_21 ( & V_74 ) - 1 ;
F_43 () ;
for ( V_6 = 0 ; V_6 < V_4 . V_5 ; V_6 ++ ) {
struct V_66 * V_67 ;
unsigned long V_1 , V_24 ;
V_1 = V_4 . V_9 [ V_6 ] . V_11 ;
V_24 = V_4 . V_9 [ V_6 ] . V_11 + V_4 . V_9 [ V_6 ] . V_2 - 1 ;
if ( V_1 >= V_42 )
continue;
if ( V_24 >= V_42 )
V_24 = V_42 - 1 ;
V_67 = F_48 ( sizeof( struct V_66 ) ) ;
switch ( V_4 . V_9 [ V_6 ] . type ) {
case V_15 :
case V_17 :
case V_18 :
V_67 -> V_75 = L_22 ;
break;
case V_19 :
default:
V_67 -> V_75 = L_23 ;
}
V_67 -> V_1 = V_1 ;
V_67 -> V_24 = V_24 ;
V_67 -> V_76 = V_77 | V_78 ;
F_46 ( & V_79 , V_67 ) ;
F_46 ( V_67 , & V_70 ) ;
F_46 ( V_67 , & V_73 ) ;
F_45 ( V_67 ) ;
}
}
void T_1 F_49 ( char * * V_47 )
{
F_50 () ;
F_51 () ;
#ifdef F_52
F_53 () ;
#endif
F_54 () ;
F_55 () ;
#if F_56 ( V_80 )
#if F_56 ( V_81 )
V_82 = & V_83 ;
#elif F_56 ( V_84 )
V_82 = & V_85 ;
#endif
#endif
F_31 ( V_47 ) ;
F_47 () ;
F_57 () ;
F_58 () ;
}
static int T_1 F_59 ( void )
{
struct V_86 * V_87 ;
V_87 = F_60 ( L_24 , NULL ) ;
if ( ! V_87 )
return - V_88 ;
V_89 = V_87 ;
return 0 ;
}
