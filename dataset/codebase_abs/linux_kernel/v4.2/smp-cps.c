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
#ifdef F_16
if ( V_21 )
F_17 ( 0 , & V_22 ) ;
#endif
}
static void T_1 F_18 ( unsigned int V_23 )
{
unsigned V_8 , V_10 , V_11 , V_24 ;
bool V_25 ;
T_2 * V_26 ;
F_19 () ;
V_24 = F_20 () & V_19 ;
switch ( V_24 ) {
case 0x4 :
case 0x5 :
V_25 = false ;
break;
default:
V_25 = true ;
}
V_8 = F_6 () ;
if ( V_25 && V_8 > 1 ) {
F_21 ( L_4 ,
V_24 ) ;
F_22 (c) {
if ( V_15 [ V_11 ] . V_1 )
F_11 ( V_11 , false ) ;
}
}
V_26 = ( T_2 * ) & V_27 ;
F_23 ( & V_26 , 3 , ( long ) V_28 ) ;
F_24 ( & V_26 , 16 , 0 , V_24 ) ;
F_25 ( ( unsigned long ) & V_27 ,
( unsigned long ) V_26 ) ;
F_26 ( ( unsigned long ) & V_27 ,
( void * ) V_26 - ( void * ) & V_27 ) ;
F_27 () ;
V_29 = F_28 ( V_8 , sizeof( * V_29 ) ,
V_30 ) ;
if ( ! V_29 ) {
F_29 ( L_5 , V_8 ) ;
goto V_31;
}
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ ) {
V_10 = F_1 ( V_11 ) ;
V_29 [ V_11 ] . V_32 = F_28 ( V_10 ,
sizeof( * V_29 [ V_11 ] . V_32 ) ,
V_30 ) ;
if ( ! V_29 [ V_11 ] . V_32 ) {
F_29 ( L_6 ,
V_10 ) ;
goto V_31;
}
}
F_30 ( & V_29 [ V_33 . V_1 ] . V_34 ,
1 << F_31 ( & V_33 ) ) ;
return;
V_31:
if ( V_29 ) {
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ )
F_32 ( V_29 [ V_11 ] . V_32 ) ;
F_32 ( V_29 ) ;
V_29 = NULL ;
}
F_33 (c) {
if ( V_11 == 0 )
continue;
F_11 ( V_11 , false ) ;
}
}
static void F_34 ( unsigned V_1 )
{
T_2 V_35 ;
F_3 ( V_1 << V_5 ) ;
F_35 ( F_36 ( ( unsigned long ) V_27 ) ) ;
F_37 ( 0 ) ;
V_35 = F_38 () ;
V_35 |= 1 << ( V_36 + V_1 ) ;
F_39 ( V_35 ) ;
if ( F_40 () ) {
F_41 ( V_1 ) ;
F_42 ( V_37 ) ;
F_43 () ;
} else {
F_44 ( 0 ) ;
}
F_13 ( V_20 , V_1 , 1 ) ;
}
static void F_45 ( void * V_38 )
{
F_46 () ;
}
static void F_47 ( int V_39 , struct V_40 * V_41 )
{
unsigned V_1 = V_15 [ V_39 ] . V_1 ;
unsigned V_16 = F_31 ( & V_15 [ V_39 ] ) ;
struct V_42 * V_43 = & V_29 [ V_1 ] ;
struct V_44 * V_45 = & V_43 -> V_32 [ V_16 ] ;
unsigned int V_46 ;
int V_47 ;
V_45 -> V_48 = ( unsigned long ) & V_49 ;
V_45 -> V_50 = F_48 ( V_41 ) ;
V_45 -> V_51 = ( unsigned long ) F_49 ( V_41 ) ;
F_50 ( 1 << F_31 ( & V_15 [ V_39 ] ) , & V_43 -> V_34 ) ;
F_51 () ;
if ( ! F_52 ( V_1 , V_20 ) ) {
F_34 ( V_1 ) ;
goto V_52;
}
if ( V_1 != V_33 . V_1 ) {
for ( V_46 = 0 ; V_46 < V_14 ; V_46 ++ ) {
if ( V_15 [ V_46 ] . V_1 != V_1 )
continue;
if ( F_53 ( V_46 ) )
break;
}
F_54 ( V_46 >= V_14 ) ;
V_47 = F_55 ( V_46 , F_45 ,
NULL , 1 ) ;
if ( V_47 )
F_56 ( L_7 ) ;
goto V_52;
}
F_54 ( ! V_4 ) ;
F_46 () ;
V_52:
F_57 () ;
}
static void F_58 ( void )
{
if ( V_4 )
F_59 () ;
F_60 ( V_53 , V_54 | V_55 | V_56 |
V_57 | V_58 | V_59 ) ;
}
static void F_61 ( void )
{
F_62 ( F_63 () + ( 8 * V_60 / V_61 ) ) ;
#ifdef F_16
if ( V_21 )
F_17 ( F_64 () , & V_22 ) ;
#endif
F_65 () ;
}
static int F_66 ( void )
{
unsigned V_39 = F_64 () ;
struct V_42 * V_43 ;
if ( ! V_39 )
return - V_62 ;
if ( ! F_67 ( V_63 ) )
return - V_64 ;
V_43 = & V_29 [ V_33 . V_1 ] ;
F_68 ( 1 << F_31 ( & V_33 ) , & V_43 -> V_34 ) ;
F_69 () ;
F_70 ( V_39 , false ) ;
F_71 ( V_39 , & V_65 ) ;
return 0 ;
}
void F_72 ( void )
{
unsigned V_39 , V_1 ;
F_73 () ;
F_74 () ;
V_39 = F_64 () ;
V_66 = V_67 ;
if ( V_4 ) {
V_1 = V_15 [ V_39 ] . V_1 ;
F_75 (cpu_death_sibling) {
if ( V_15 [ V_68 ] . V_1 != V_1 )
continue;
V_66 = V_69 ;
break;
}
}
F_76 ( & V_70 ) ;
if ( V_66 == V_69 ) {
F_77 ( V_71 ) ;
F_78 () ;
} else {
F_79 ( V_63 ) ;
}
F_56 ( L_8 , V_39 ) ;
}
static void F_80 ( void * V_72 )
{
unsigned V_39 = ( unsigned long ) V_72 ;
unsigned V_16 = F_31 ( & V_15 [ V_39 ] ) ;
unsigned V_73 ;
unsigned long V_74 ;
do {
F_81 ( V_74 ) ;
F_82 ( V_16 ) ;
V_73 = F_83 () ;
F_84 ( V_74 ) ;
} while ( ! ( V_73 & V_71 ) );
}
static void F_85 ( unsigned int V_39 )
{
unsigned V_1 = V_15 [ V_39 ] . V_1 ;
unsigned V_75 ;
int V_47 ;
if ( ! F_86 ( & V_70 ,
F_87 ( 5000 ) ) ) {
F_29 ( L_9 , V_39 ) ;
return;
}
if ( V_66 == V_67 ) {
do {
F_41 ( V_1 ) ;
V_75 = F_88 () ;
V_75 &= V_76 ;
F_43 () ;
} while ( V_75 != V_77 &&
V_75 != V_78 &&
V_75 != V_79 );
F_89 ( V_20 , V_1 , 1 ) ;
} else if ( V_4 ) {
V_47 = F_55 ( V_68 ,
F_80 ,
( void * ) ( unsigned long ) V_39 , 1 ) ;
if ( V_47 )
F_56 ( L_10 ) ;
}
}
bool F_90 ( void )
{
extern struct V_80 * V_81 ;
return V_81 == & V_82 ;
}
int F_91 ( void )
{
if ( ! F_92 () ) {
F_21 ( L_11 ) ;
return - V_83 ;
}
if ( ! ( F_93 () & V_84 ) ) {
F_21 ( L_12 ) ;
return - V_83 ;
}
F_94 ( & V_82 ) ;
return 0 ;
}
