void T_1 F_1 ( T_2 V_1 , T_2 V_2 , long type )
{
int V_3 = V_4 . V_5 ;
struct V_6 * V_7 = V_4 . V_8 + V_3 - 1 ;
if ( V_1 + V_2 < V_1 ) {
F_2 ( L_1 ) ;
return;
}
if ( V_3 && V_7 -> V_9 + V_7 -> V_2 == V_1 && V_7 -> type == type ) {
V_7 -> V_2 += V_2 ;
return;
}
if ( V_3 == V_10 ) {
F_3 ( L_2 ) ;
return;
}
V_4 . V_8 [ V_3 ] . V_9 = V_1 ;
V_4 . V_8 [ V_3 ] . V_2 = V_2 ;
V_4 . V_8 [ V_3 ] . type = type ;
V_4 . V_5 ++ ;
}
static void T_1 F_4 ( void )
{
int V_11 ;
const int V_12 = 2 * sizeof( unsigned long ) ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
F_5 ( V_13 L_3 ,
V_12 , ( unsigned long long ) V_4 . V_8 [ V_11 ] . V_2 ,
V_12 , ( unsigned long long ) V_4 . V_8 [ V_11 ] . V_9 ) ;
switch ( V_4 . V_8 [ V_11 ] . type ) {
case V_14 :
F_5 ( V_15 L_4 ) ;
break;
case V_16 :
F_5 ( V_15 L_5 ) ;
break;
case V_17 :
F_5 ( V_15 L_6 ) ;
break;
case V_18 :
F_5 ( V_15 L_7 ) ;
break;
default:
F_5 ( V_15 L_8 , V_4 . V_8 [ V_11 ] . type ) ;
break;
}
}
}
static int T_1 F_6 ( char * V_19 )
{
unsigned long V_1 = F_7 ( V_19 , & V_19 ) ;
#ifdef F_8
if ( V_1 < V_20 )
V_1 = ( int ) V_1 ;
#endif
V_21 = V_1 ;
V_22 += V_1 ;
return 0 ;
}
static int T_1 F_9 ( char * V_19 )
{
V_22 += F_7 ( V_19 , & V_19 ) ;
return 0 ;
}
static unsigned long T_1 F_10 ( void )
{
unsigned long V_23 ;
if ( ! V_21 || V_22 <= V_21 )
goto V_24;
if ( V_21 & ~ V_25 ) {
F_3 ( L_9 ) ;
goto V_24;
}
if ( V_21 < V_26 ) {
F_3 ( L_10 ) ;
goto V_24;
}
V_23 = F_11 ( V_22 ) ;
V_22 = ( unsigned long ) F_12 ( V_23 ) ;
V_21 = ( unsigned long ) F_12 ( F_11 ( V_21 ) ) ;
V_27 = V_28 ;
return F_13 ( V_23 ) ;
V_24:
V_21 = 0 ;
V_22 = 0 ;
return 0 ;
}
static void T_1 F_14 ( void )
{
unsigned long V_2 = V_22 - V_21 ;
if ( V_2 == 0 ) {
F_5 ( V_13 L_11 ) ;
goto V_24;
}
if ( F_11 ( V_22 ) > F_15 ( V_29 ) ) {
F_5 ( V_30 L_12 ) ;
goto V_24;
}
F_16 ( F_11 ( V_21 ) , V_2 , V_31 ) ;
V_32 = 1 ;
F_17 ( L_13 ,
V_21 , V_2 ) ;
return;
V_24:
F_5 ( V_15 L_14 ) ;
V_21 = 0 ;
V_22 = 0 ;
}
static unsigned long T_1 F_10 ( void )
{
return 0 ;
}
static void T_1 F_18 ( void )
{
F_10 () ;
F_14 () ;
}
static void T_1 F_18 ( void )
{
unsigned long V_33 ;
unsigned long V_34 = ~ 0UL ;
unsigned long V_35 ;
int V_11 ;
V_33 = F_19 ( F_10 () ,
( unsigned long ) F_13 ( F_20 ( & V_36 ) ) ) ;
V_37 = ~ 0UL ;
V_29 = 0 ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
unsigned long V_1 , V_23 ;
if ( V_4 . V_8 [ V_11 ] . type != V_14 )
continue;
V_1 = F_13 ( V_4 . V_8 [ V_11 ] . V_9 ) ;
V_23 = F_21 ( V_4 . V_8 [ V_11 ] . V_9
+ V_4 . V_8 [ V_11 ] . V_2 ) ;
if ( V_23 > V_29 )
V_29 = V_23 ;
if ( V_1 < V_37 )
V_37 = V_1 ;
if ( V_23 <= V_33 )
continue;
if ( V_1 >= V_34 )
continue;
V_34 = F_19 ( V_33 , V_1 ) ;
}
if ( V_37 >= V_29 )
F_22 ( L_15 ) ;
if ( V_37 > V_38 ) {
F_17 ( L_16 ,
( V_37 - V_38 ) * sizeof( struct V_39 ) ,
V_37 - V_38 ) ;
} else if ( V_37 < V_38 ) {
F_17 ( L_17 ,
V_38 - V_37 ) ;
}
V_37 = V_38 ;
V_40 = V_29 ;
if ( V_29 > F_21 ( V_41 ) ) {
#ifdef F_23
V_42 = F_21 ( V_41 ) ;
V_43 = V_29 ;
#endif
V_29 = F_21 ( V_41 ) ;
}
V_35 = F_24 ( F_25 ( 0 ) , V_34 ,
V_37 , V_29 ) ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
unsigned long V_1 , V_23 ;
V_1 = F_13 ( V_4 . V_8 [ V_11 ] . V_9 ) ;
V_23 = F_21 ( V_4 . V_8 [ V_11 ] . V_9
+ V_4 . V_8 [ V_11 ] . V_2 ) ;
if ( V_1 <= V_37 )
V_1 = V_37 ;
if ( V_1 >= V_23 )
continue;
#ifndef F_23
if ( V_23 > V_29 )
V_23 = V_29 ;
if ( V_23 <= V_1 )
continue;
#endif
F_26 ( F_15 ( V_1 ) , F_15 ( V_23 - V_1 ) , 0 ) ;
}
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
unsigned long V_1 , V_23 , V_2 ;
V_1 = F_13 ( V_4 . V_8 [ V_11 ] . V_9 ) ;
V_23 = F_21 ( V_4 . V_8 [ V_11 ] . V_9
+ V_4 . V_8 [ V_11 ] . V_2 ) ;
switch ( V_4 . V_8 [ V_11 ] . type ) {
case V_14 :
break;
case V_16 :
F_27 ( 0 , V_1 , V_23 ) ;
continue;
default:
continue;
}
if ( V_1 >= V_29 )
continue;
if ( V_1 < V_33 )
V_1 = V_33 ;
if ( V_23 > V_29 )
V_23 = V_29 ;
if ( V_23 <= V_1 )
continue;
V_2 = V_23 - V_1 ;
F_28 ( F_15 ( V_1 ) , V_2 << V_44 ) ;
F_27 ( 0 , V_1 , V_23 ) ;
}
F_16 ( F_15 ( V_34 ) , V_35 , V_31 ) ;
F_14 () ;
}
static int T_1 F_29 ( char * V_19 )
{
unsigned long V_1 , V_2 ;
if ( V_45 == 0 ) {
V_4 . V_5 = 0 ;
V_45 = 1 ;
}
V_1 = 0 ;
V_2 = F_7 ( V_19 , & V_19 ) ;
if ( * V_19 == '@' )
V_1 = F_7 ( V_19 + 1 , & V_19 ) ;
F_1 ( V_1 , V_2 , V_14 ) ;
return 0 ;
}
static void T_1 F_30 ( char * * V_46 )
{
T_2 V_47 , V_48 , V_49 ;
extern void V_50 ( void ) ;
V_50 () ;
V_47 = F_13 ( F_20 ( & V_51 ) ) << V_44 ;
V_48 = F_21 ( F_20 ( & V_52 ) ) << V_44 ;
V_49 = V_48 - V_47 ;
if ( V_49 ) {
int V_11 , V_53 ;
V_53 = 0 ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
if ( V_47 >= V_4 . V_8 [ V_11 ] . V_9 &&
V_47 < ( V_4 . V_8 [ V_11 ] . V_9 +
V_4 . V_8 [ V_11 ] . V_2 ) ) {
V_53 = 1 ;
break;
}
}
if ( ! V_53 )
F_1 ( V_47 , V_49 ,
V_16 ) ;
}
F_17 ( L_18 ) ;
F_4 () ;
#ifdef F_31
#ifdef F_32
F_33 ( V_54 , V_55 , V_56 ) ;
#else
if ( V_55 [ 0 ] ) {
F_34 ( V_57 , L_19 , V_56 ) ;
F_34 ( V_57 , V_55 , V_56 ) ;
}
F_33 ( V_54 , V_57 , V_56 ) ;
#endif
#else
F_33 ( V_54 , V_57 , V_56 ) ;
#endif
F_33 ( V_58 , V_54 , V_56 ) ;
* V_46 = V_58 ;
F_35 () ;
if ( V_45 ) {
F_17 ( L_20 ) ;
F_4 () ;
}
F_18 () ;
F_36 () ;
F_37 () ;
F_38 () ;
F_39 () ;
}
static void T_1 F_40 ( void )
{
int V_11 ;
if ( V_59 != V_60 )
return;
V_61 . V_1 = F_20 ( & V_62 ) ;
V_61 . V_23 = F_20 ( & V_63 ) - 1 ;
V_64 . V_1 = F_20 ( & V_63 ) ;
V_64 . V_23 = F_20 ( & V_65 ) - 1 ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
struct V_66 * V_67 ;
unsigned long V_1 , V_23 ;
V_1 = V_4 . V_8 [ V_11 ] . V_9 ;
V_23 = V_4 . V_8 [ V_11 ] . V_9 + V_4 . V_8 [ V_11 ] . V_2 - 1 ;
if ( V_1 >= V_41 )
continue;
if ( V_23 >= V_41 )
V_23 = V_41 - 1 ;
V_67 = F_41 ( sizeof( struct V_66 ) ) ;
switch ( V_4 . V_8 [ V_11 ] . type ) {
case V_14 :
case V_16 :
case V_17 :
V_67 -> V_68 = L_21 ;
break;
case V_18 :
default:
V_67 -> V_68 = L_22 ;
}
V_67 -> V_1 = V_1 ;
V_67 -> V_23 = V_23 ;
V_67 -> V_69 = V_70 | V_71 ;
F_42 ( & V_72 , V_67 ) ;
F_42 ( V_67 , & V_61 ) ;
F_42 ( V_67 , & V_64 ) ;
}
}
void T_1 F_43 ( char * * V_46 )
{
F_44 () ;
F_45 () ;
#ifdef F_46
F_47 () ;
#endif
F_48 () ;
F_49 () ;
#if F_50 ( V_73 )
#if F_50 ( V_74 )
V_75 = & V_76 ;
#elif F_50 ( V_77 )
V_75 = & V_78 ;
#endif
#endif
F_30 ( V_46 ) ;
F_40 () ;
F_51 () ;
}
static int T_1 F_52 ( void )
{
struct V_79 * V_80 ;
V_80 = F_53 ( L_23 , NULL ) ;
if ( ! V_80 )
return - V_81 ;
V_82 = V_80 ;
return 0 ;
}
