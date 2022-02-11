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
( unsigned long ) V_24 ) ;
F_24 ( ( unsigned long ) & V_25 ,
( void * ) V_24 - ( void * ) & V_25 ) ;
F_25 () ;
V_27 = F_26 ( V_8 , sizeof( * V_27 ) ,
V_28 ) ;
if ( ! V_27 ) {
F_27 ( L_5 , V_8 ) ;
goto V_29;
}
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ ) {
V_10 = F_1 ( V_11 ) ;
V_27 [ V_11 ] . V_30 = F_26 ( V_10 ,
sizeof( * V_27 [ V_11 ] . V_30 ) ,
V_28 ) ;
if ( ! V_27 [ V_11 ] . V_30 ) {
F_27 ( L_6 ,
V_10 ) ;
goto V_29;
}
}
F_28 ( & V_27 [ V_31 . V_1 ] . V_32 ,
1 << F_29 ( & V_31 ) ) ;
return;
V_29:
if ( V_27 ) {
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ )
F_30 ( V_27 [ V_11 ] . V_30 ) ;
F_30 ( V_27 ) ;
V_27 = NULL ;
}
F_31 (c) {
if ( V_11 == 0 )
continue;
F_11 ( V_11 , false ) ;
}
}
static void F_32 ( unsigned V_1 )
{
T_2 V_33 ;
F_3 ( V_1 << V_5 ) ;
F_33 ( F_34 ( ( unsigned long ) V_25 ) ) ;
F_35 ( 0 ) ;
V_33 = F_36 () ;
V_33 |= 1 << ( V_34 + V_1 ) ;
F_37 ( V_33 ) ;
if ( F_38 () ) {
F_39 ( V_1 ) ;
F_40 ( V_35 ) ;
F_41 () ;
} else {
F_42 ( 0 ) ;
}
F_13 ( V_20 , V_1 , 1 ) ;
}
static void F_43 ( void * V_36 )
{
F_44 () ;
}
static void F_45 ( int V_37 , struct V_38 * V_39 )
{
unsigned V_1 = V_15 [ V_37 ] . V_1 ;
unsigned V_16 = F_29 ( & V_15 [ V_37 ] ) ;
struct V_40 * V_41 = & V_27 [ V_1 ] ;
struct V_42 * V_43 = & V_41 -> V_30 [ V_16 ] ;
unsigned int V_44 ;
int V_45 ;
V_43 -> V_46 = ( unsigned long ) & V_47 ;
V_43 -> V_48 = F_46 ( V_39 ) ;
V_43 -> V_49 = ( unsigned long ) F_47 ( V_39 ) ;
F_48 ( 1 << F_29 ( & V_15 [ V_37 ] ) , & V_41 -> V_32 ) ;
F_49 () ;
if ( ! F_50 ( V_1 , V_20 ) ) {
F_32 ( V_1 ) ;
goto V_50;
}
if ( V_1 != V_31 . V_1 ) {
for ( V_44 = 0 ; V_44 < V_14 ; V_44 ++ ) {
if ( V_15 [ V_44 ] . V_1 != V_1 )
continue;
if ( F_51 ( V_44 ) )
break;
}
F_52 ( V_44 >= V_14 ) ;
V_45 = F_53 ( V_44 , F_43 ,
NULL , 1 ) ;
if ( V_45 )
F_54 ( L_7 ) ;
goto V_50;
}
F_52 ( ! V_4 ) ;
F_44 () ;
V_50:
F_55 () ;
}
static void F_56 ( void )
{
if ( V_4 )
F_57 () ;
F_58 ( V_51 , V_52 | V_53 | V_54 |
V_55 | V_56 | V_57 ) ;
}
static void F_59 ( void )
{
F_60 ( F_61 () + ( 8 * V_58 / V_59 ) ) ;
#ifdef F_62
if ( V_60 )
F_63 ( F_64 () , V_61 ) ;
#endif
F_65 () ;
}
static int F_66 ( void )
{
unsigned V_37 = F_64 () ;
struct V_40 * V_41 ;
if ( ! V_37 )
return - V_62 ;
if ( ! F_67 ( V_63 ) )
return - V_64 ;
V_41 = & V_27 [ V_31 . V_1 ] ;
F_68 ( 1 << F_29 ( & V_31 ) , & V_41 -> V_32 ) ;
F_69 () ;
F_70 ( V_37 , false ) ;
F_71 ( V_37 , V_65 ) ;
return 0 ;
}
void F_72 ( void )
{
unsigned V_37 , V_1 ;
F_73 () ;
F_74 () ;
V_37 = F_64 () ;
V_66 = V_67 ;
if ( V_4 ) {
V_1 = V_15 [ V_37 ] . V_1 ;
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
F_54 ( L_8 , V_37 ) ;
}
static void F_80 ( void * V_72 )
{
unsigned V_37 = ( unsigned ) V_72 ;
unsigned V_16 = F_29 ( & V_15 [ V_37 ] ) ;
unsigned V_73 ;
unsigned long V_74 ;
do {
F_81 ( V_74 ) ;
F_82 ( V_16 ) ;
V_73 = F_83 () ;
F_84 ( V_74 ) ;
} while ( ! ( V_73 & V_71 ) );
}
static void F_85 ( unsigned int V_37 )
{
unsigned V_1 = V_15 [ V_37 ] . V_1 ;
unsigned V_75 ;
int V_45 ;
if ( ! F_86 ( & V_70 ,
F_87 ( 5000 ) ) ) {
F_27 ( L_9 , V_37 ) ;
return;
}
if ( V_66 == V_67 ) {
do {
F_39 ( V_1 ) ;
V_75 = F_88 () ;
V_75 &= V_76 ;
F_41 () ;
} while ( V_75 != V_77 &&
V_75 != V_78 &&
V_75 != V_79 );
F_89 ( V_20 , V_1 , 1 ) ;
} else if ( V_4 ) {
V_45 = F_53 ( V_68 ,
F_80 ,
( void * ) V_37 , 1 ) ;
if ( V_45 )
F_54 ( L_10 ) ;
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
F_19 ( L_11 ) ;
return - V_83 ;
}
if ( ! ( F_93 () & V_84 ) ) {
F_19 ( L_12 ) ;
return - V_83 ;
}
F_94 ( & V_82 ) ;
return 0 ;
}
