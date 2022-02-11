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
default:
F_5 ( V_15 L_7 , V_4 . V_8 [ V_11 ] . type ) ;
break;
}
}
}
static int T_1 F_6 ( char * V_18 )
{
unsigned long V_1 = F_7 ( V_18 , & V_18 ) ;
#ifdef F_8
if ( V_1 < V_19 )
V_1 = ( int ) V_1 ;
#endif
V_20 = V_1 ;
V_21 += V_1 ;
return 0 ;
}
static int T_1 F_9 ( char * V_18 )
{
V_21 += F_7 ( V_18 , & V_18 ) ;
return 0 ;
}
static unsigned long T_1 F_10 ( void )
{
unsigned long V_22 ;
if ( ! V_20 || V_21 <= V_20 )
goto V_23;
if ( V_20 & ~ V_24 ) {
F_3 ( L_8 ) ;
goto V_23;
}
if ( V_20 < V_25 ) {
F_3 ( L_9 ) ;
goto V_23;
}
V_22 = F_11 ( V_21 ) ;
V_21 = ( unsigned long ) F_12 ( V_22 ) ;
V_20 = ( unsigned long ) F_12 ( F_11 ( V_20 ) ) ;
V_26 = V_27 ;
return F_13 ( V_22 ) ;
V_23:
V_20 = 0 ;
V_21 = 0 ;
return 0 ;
}
static void T_1 F_14 ( void )
{
unsigned long V_2 = V_21 - V_20 ;
if ( V_2 == 0 ) {
F_5 ( V_13 L_10 ) ;
goto V_23;
}
if ( F_11 ( V_21 ) > F_15 ( V_28 ) ) {
F_5 ( V_29 L_11 ) ;
goto V_23;
}
F_16 ( F_11 ( V_20 ) , V_2 , V_30 ) ;
V_31 = 1 ;
F_17 ( L_12 ,
V_20 , V_2 ) ;
return;
V_23:
F_5 ( V_15 L_13 ) ;
V_20 = 0 ;
V_21 = 0 ;
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
unsigned long V_32 ;
unsigned long V_33 = ~ 0UL ;
unsigned long V_34 ;
int V_11 ;
V_32 = F_19 ( F_10 () ,
( unsigned long ) F_13 ( F_20 ( & V_35 ) ) ) ;
V_36 = ~ 0UL ;
V_28 = 0 ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
unsigned long V_1 , V_22 ;
if ( V_4 . V_8 [ V_11 ] . type != V_14 )
continue;
V_1 = F_13 ( V_4 . V_8 [ V_11 ] . V_9 ) ;
V_22 = F_21 ( V_4 . V_8 [ V_11 ] . V_9
+ V_4 . V_8 [ V_11 ] . V_2 ) ;
if ( V_22 > V_28 )
V_28 = V_22 ;
if ( V_1 < V_36 )
V_36 = V_1 ;
if ( V_22 <= V_32 )
continue;
if ( V_1 >= V_33 )
continue;
V_33 = F_19 ( V_32 , V_1 ) ;
}
if ( V_36 >= V_28 )
F_22 ( L_14 ) ;
if ( V_36 > V_37 ) {
F_17 ( L_15 ,
( V_36 - V_37 ) * sizeof( struct V_38 ) ,
V_36 - V_37 ) ;
} else if ( V_36 < V_37 ) {
F_17 ( L_16 ,
V_37 - V_36 ) ;
}
V_36 = V_37 ;
V_39 = V_28 ;
if ( V_28 > F_21 ( V_40 ) ) {
#ifdef F_23
V_41 = F_21 ( V_40 ) ;
V_42 = V_28 ;
#endif
V_28 = F_21 ( V_40 ) ;
}
V_34 = F_24 ( F_25 ( 0 ) , V_33 ,
V_36 , V_28 ) ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
unsigned long V_1 , V_22 ;
V_1 = F_13 ( V_4 . V_8 [ V_11 ] . V_9 ) ;
V_22 = F_21 ( V_4 . V_8 [ V_11 ] . V_9
+ V_4 . V_8 [ V_11 ] . V_2 ) ;
if ( V_1 <= V_36 )
V_1 = V_36 ;
if ( V_1 >= V_22 )
continue;
#ifndef F_23
if ( V_22 > V_28 )
V_22 = V_28 ;
if ( V_22 <= V_1 )
continue;
#endif
F_26 ( 0 , V_1 , V_22 ) ;
}
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
unsigned long V_1 , V_22 , V_2 ;
if ( V_4 . V_8 [ V_11 ] . type != V_14 )
continue;
V_1 = F_13 ( V_4 . V_8 [ V_11 ] . V_9 ) ;
V_22 = F_21 ( V_4 . V_8 [ V_11 ] . V_9
+ V_4 . V_8 [ V_11 ] . V_2 ) ;
if ( V_1 >= V_28 )
continue;
if ( V_1 < V_32 )
V_1 = V_32 ;
if ( V_22 > V_28 )
V_22 = V_28 ;
if ( V_22 <= V_1 )
continue;
V_2 = V_22 - V_1 ;
F_27 ( F_15 ( V_1 ) , V_2 << V_43 ) ;
F_28 ( 0 , V_1 , V_22 ) ;
}
F_16 ( F_15 ( V_33 ) , V_34 , V_30 ) ;
F_14 () ;
}
static int T_1 F_29 ( char * V_18 )
{
unsigned long V_1 , V_2 ;
if ( V_44 == 0 ) {
V_4 . V_5 = 0 ;
V_44 = 1 ;
}
V_1 = 0 ;
V_2 = F_7 ( V_18 , & V_18 ) ;
if ( * V_18 == '@' )
V_1 = F_7 ( V_18 + 1 , & V_18 ) ;
F_1 ( V_1 , V_2 , V_14 ) ;
return 0 ;
}
static void T_1 F_30 ( char * * V_45 )
{
extern void V_46 ( void ) ;
V_46 () ;
F_17 ( L_17 ) ;
F_4 () ;
#ifdef F_31
#ifdef F_32
F_33 ( V_47 , V_48 , V_49 ) ;
#else
if ( V_48 [ 0 ] ) {
F_34 ( V_50 , L_18 , V_49 ) ;
F_34 ( V_50 , V_48 , V_49 ) ;
}
F_33 ( V_47 , V_50 , V_49 ) ;
#endif
#else
F_33 ( V_47 , V_50 , V_49 ) ;
#endif
F_33 ( V_51 , V_47 , V_49 ) ;
* V_45 = V_51 ;
F_35 () ;
if ( V_44 ) {
F_17 ( L_19 ) ;
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
if ( V_52 != V_53 )
return;
V_54 . V_1 = F_20 ( & V_55 ) ;
V_54 . V_22 = F_20 ( & V_56 ) - 1 ;
V_57 . V_1 = F_20 ( & V_56 ) ;
V_57 . V_22 = F_20 ( & V_58 ) - 1 ;
for ( V_11 = 0 ; V_11 < V_4 . V_5 ; V_11 ++ ) {
struct V_59 * V_60 ;
unsigned long V_1 , V_22 ;
V_1 = V_4 . V_8 [ V_11 ] . V_9 ;
V_22 = V_4 . V_8 [ V_11 ] . V_9 + V_4 . V_8 [ V_11 ] . V_2 - 1 ;
if ( V_1 >= V_40 )
continue;
if ( V_22 >= V_40 )
V_22 = V_40 - 1 ;
V_60 = F_41 ( sizeof( struct V_59 ) ) ;
switch ( V_4 . V_8 [ V_11 ] . type ) {
case V_14 :
case V_16 :
V_60 -> V_61 = L_20 ;
break;
case V_17 :
default:
V_60 -> V_61 = L_21 ;
}
V_60 -> V_1 = V_1 ;
V_60 -> V_22 = V_22 ;
V_60 -> V_62 = V_63 | V_64 ;
F_42 ( & V_65 , V_60 ) ;
F_42 ( V_60 , & V_54 ) ;
F_42 ( V_60 , & V_57 ) ;
}
}
void T_1 F_43 ( char * * V_45 )
{
F_44 () ;
F_45 () ;
#ifdef F_46
F_47 () ;
#endif
F_48 () ;
F_49 () ;
#if F_50 ( V_66 )
#if F_50 ( V_67 )
V_68 = & V_69 ;
#elif F_50 ( V_70 )
V_68 = & V_71 ;
#endif
#endif
F_30 ( V_45 ) ;
F_40 () ;
F_51 () ;
}
static int T_1 F_52 ( void )
{
struct V_72 * V_73 ;
V_73 = F_53 ( L_22 , NULL ) ;
if ( ! V_73 )
return - V_74 ;
V_75 = V_73 ;
return 0 ;
}
