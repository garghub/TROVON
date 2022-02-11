static unsigned F_1 ( unsigned V_1 )
{
unsigned V_2 ;
if ( ! F_2 ( V_3 ) || ! V_4 )
return 1 ;
F_3 ( V_1 << V_5 ) ;
V_2 = F_4 () & V_6 ;
return ( V_2 >> V_7 ) + 1 ;
}
static void T_1 F_5 ( void )
{
unsigned int V_8 , V_9 , V_10 ;
int V_11 , V_12 ;
V_8 = F_6 () ;
F_7 ( L_1 ) ;
for ( V_11 = V_9 = 0 ; V_11 < V_8 ; V_11 ++ ) {
V_10 = F_1 ( V_11 ) ;
F_8 ( L_2 , V_11 ? ',' : '{' , V_10 ) ;
if ( ! V_11 )
V_13 = V_10 ;
for ( V_12 = 0 ; V_12 < F_9 ( int , V_10 , V_14 - V_9 ) ; V_12 ++ ) {
V_15 [ V_9 + V_12 ] . V_1 = V_11 ;
#ifdef V_3
V_15 [ V_9 + V_12 ] . V_16 = V_12 ;
#endif
}
V_9 += V_10 ;
}
F_8 ( L_3 , V_9 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( unsigned , V_9 , V_14 ) ; V_12 ++ ) {
F_10 ( V_12 , true ) ;
F_11 ( V_12 , true ) ;
V_17 [ V_12 ] = V_12 ;
V_18 [ V_12 ] = V_12 ;
}
F_12 ( V_19 , 0x5 ) ;
F_13 ( V_20 , 0 , 1 ) ;
F_14 () ;
F_15 ( 0xff ) ;
}
static void T_1 F_16 ( unsigned int V_21 )
{
unsigned V_8 , V_10 , V_11 , V_22 ;
bool V_23 ;
T_2 * V_24 ;
F_17 () ;
V_22 = F_18 () & V_19 ;
switch ( V_22 ) {
case 0x4 :
case 0x5 :
V_23 = false ;
break;
default:
V_23 = true ;
}
V_8 = F_6 () ;
if ( V_23 && V_8 > 1 ) {
F_19 ( L_4 ,
V_22 ) ;
F_20 (c) {
if ( V_15 [ V_11 ] . V_1 )
F_11 ( V_11 , false ) ;
}
}
V_24 = ( T_2 * ) & V_25 ;
F_21 ( & V_24 , 3 , ( long ) V_26 ) ;
F_22 ( & V_24 , 16 , 0 , V_22 ) ;
F_23 ( ( unsigned long ) & V_25 ,
( void * ) V_24 - ( void * ) & V_25 ) ;
V_27 = F_24 ( V_8 , sizeof( * V_27 ) ,
V_28 ) ;
if ( ! V_27 ) {
F_25 ( L_5 , V_8 ) ;
goto V_29;
}
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ ) {
V_10 = F_1 ( V_11 ) ;
V_27 [ V_11 ] . V_30 = F_24 ( V_10 ,
sizeof( * V_27 [ V_11 ] . V_30 ) ,
V_28 ) ;
if ( ! V_27 [ V_11 ] . V_30 ) {
F_25 ( L_6 ,
V_10 ) ;
goto V_29;
}
}
F_26 ( & V_27 [ V_31 . V_1 ] . V_32 ,
1 << F_27 ( & V_31 ) ) ;
return;
V_29:
if ( V_27 ) {
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ )
F_28 ( V_27 [ V_11 ] . V_30 ) ;
F_28 ( V_27 ) ;
V_27 = NULL ;
}
F_29 (c) {
if ( V_11 == 0 )
continue;
F_11 ( V_11 , false ) ;
}
}
static void F_30 ( unsigned V_1 )
{
T_2 V_33 ;
F_3 ( V_1 << V_5 ) ;
F_31 ( F_32 ( ( unsigned long ) V_25 ) ) ;
F_33 ( 0 ) ;
V_33 = F_34 () ;
V_33 |= 1 << ( V_34 + V_1 ) ;
F_35 ( V_33 ) ;
if ( F_36 () ) {
F_37 ( V_1 ) ;
F_38 ( V_35 ) ;
F_39 () ;
} else {
F_40 ( 0 ) ;
}
F_13 ( V_20 , V_1 , 1 ) ;
}
static void F_41 ( void * V_36 )
{
F_42 () ;
}
static void F_43 ( int V_37 , struct V_38 * V_39 )
{
unsigned V_1 = V_15 [ V_37 ] . V_1 ;
unsigned V_16 = F_27 ( & V_15 [ V_37 ] ) ;
struct V_40 * V_41 = & V_27 [ V_1 ] ;
struct V_42 * V_43 = & V_41 -> V_30 [ V_16 ] ;
unsigned int V_44 ;
int V_45 ;
V_43 -> V_46 = ( unsigned long ) & V_47 ;
V_43 -> V_48 = F_44 ( V_39 ) ;
V_43 -> V_49 = ( unsigned long ) F_45 ( V_39 ) ;
F_46 ( 1 << F_27 ( & V_15 [ V_37 ] ) , & V_41 -> V_32 ) ;
F_47 () ;
if ( ! F_48 ( V_1 , V_20 ) ) {
F_30 ( V_1 ) ;
goto V_50;
}
if ( V_1 != V_31 . V_1 ) {
for ( V_44 = 0 ; V_44 < V_14 ; V_44 ++ ) {
if ( V_15 [ V_44 ] . V_1 != V_1 )
continue;
if ( F_49 ( V_44 ) )
break;
}
F_50 ( V_44 >= V_14 ) ;
V_45 = F_51 ( V_44 , F_41 ,
NULL , 1 ) ;
if ( V_45 )
F_52 ( L_7 ) ;
goto V_50;
}
F_50 ( ! V_4 ) ;
F_42 () ;
V_50:
F_53 () ;
}
static void F_54 ( void )
{
if ( V_4 )
F_55 () ;
F_56 ( V_51 , V_52 | V_53 |
V_54 | V_55 ) ;
}
static void F_57 ( void )
{
F_58 ( F_59 () + ( 8 * V_56 / V_57 ) ) ;
#ifdef F_60
if ( V_58 )
F_61 ( F_62 () , V_59 ) ;
#endif
F_63 () ;
}
static int F_64 ( void )
{
unsigned V_37 = F_62 () ;
struct V_40 * V_41 ;
if ( ! V_37 )
return - V_60 ;
if ( ! F_65 ( V_61 ) )
return - V_62 ;
V_41 = & V_27 [ V_31 . V_1 ] ;
F_66 ( 1 << F_27 ( & V_31 ) , & V_41 -> V_32 ) ;
F_67 () ;
F_68 ( V_37 , false ) ;
F_69 ( V_37 , V_63 ) ;
return 0 ;
}
void F_70 ( void )
{
unsigned V_37 , V_1 ;
F_71 () ;
F_72 () ;
V_37 = F_62 () ;
V_64 = V_65 ;
if ( V_4 ) {
V_1 = V_15 [ V_37 ] . V_1 ;
F_73 (cpu_death_sibling) {
if ( V_15 [ V_66 ] . V_1 != V_1 )
continue;
V_64 = V_67 ;
break;
}
}
F_74 ( & V_68 ) ;
if ( V_64 == V_67 ) {
F_75 ( V_69 ) ;
F_76 () ;
} else {
F_77 ( V_61 ) ;
}
F_52 ( L_8 , V_37 ) ;
}
static void F_78 ( void * V_70 )
{
unsigned V_37 = ( unsigned ) V_70 ;
unsigned V_16 = V_15 [ V_37 ] . V_16 ;
unsigned V_71 ;
unsigned long V_72 ;
do {
F_79 ( V_72 ) ;
F_80 ( V_16 ) ;
V_71 = F_81 () ;
F_82 ( V_72 ) ;
} while ( ! ( V_71 & V_69 ) );
}
static void F_83 ( unsigned int V_37 )
{
unsigned V_1 = V_15 [ V_37 ] . V_1 ;
unsigned V_73 ;
int V_45 ;
if ( ! F_84 ( & V_68 ,
F_85 ( 5000 ) ) ) {
F_25 ( L_9 , V_37 ) ;
return;
}
if ( V_64 == V_65 ) {
do {
F_37 ( V_1 ) ;
V_73 = F_86 () ;
V_73 &= V_74 ;
F_39 () ;
} while ( V_73 != V_75 &&
V_73 != V_76 &&
V_73 != V_77 );
F_87 ( V_20 , V_1 , 1 ) ;
} else if ( V_4 ) {
V_45 = F_51 ( V_66 ,
F_78 ,
( void * ) V_37 , 1 ) ;
if ( V_45 )
F_52 ( L_10 ) ;
}
}
bool F_88 ( void )
{
extern struct V_78 * V_79 ;
return V_79 == & V_80 ;
}
int F_89 ( void )
{
if ( ! F_90 () ) {
F_19 ( L_11 ) ;
return - V_81 ;
}
if ( ! ( F_91 () & V_82 ) ) {
F_19 ( L_12 ) ;
return - V_81 ;
}
F_92 ( & V_80 ) ;
return 0 ;
}
