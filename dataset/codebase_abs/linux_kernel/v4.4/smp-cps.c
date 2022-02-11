static unsigned F_1 ( unsigned V_1 )
{
unsigned V_2 ;
if ( ! F_2 ( V_3 ) || ! V_4 )
return 1 ;
F_3 ( V_1 , 0 ) ;
V_2 = F_4 () & V_5 ;
F_5 () ;
return ( V_2 >> V_6 ) + 1 ;
}
static void T_1 F_6 ( void )
{
unsigned int V_7 , V_8 , V_9 ;
int V_10 , V_11 ;
V_7 = F_7 () ;
F_8 ( L_1 ) ;
for ( V_10 = V_8 = 0 ; V_10 < V_7 ; V_10 ++ ) {
V_9 = F_1 ( V_10 ) ;
F_9 ( L_2 , V_10 ? ',' : '{' , V_9 ) ;
if ( ! V_10 )
V_12 = V_9 ;
for ( V_11 = 0 ; V_11 < F_10 ( int , V_9 , V_13 - V_8 ) ; V_11 ++ ) {
V_14 [ V_8 + V_11 ] . V_1 = V_10 ;
#ifdef V_3
V_14 [ V_8 + V_11 ] . V_15 = V_11 ;
#endif
}
V_8 += V_9 ;
}
F_9 ( L_3 , V_8 ) ;
for ( V_11 = 0 ; V_11 < F_10 ( unsigned , V_8 , V_13 ) ; V_11 ++ ) {
F_11 ( V_11 , true ) ;
F_12 ( V_11 , true ) ;
V_16 [ V_11 ] = V_11 ;
V_17 [ V_11 ] = V_11 ;
}
F_13 ( V_18 , 0x5 ) ;
F_14 ( V_19 , 0 , 1 ) ;
F_15 () ;
F_16 ( 0xff ) ;
#ifdef F_17
if ( V_20 )
F_18 ( 0 , & V_21 ) ;
#endif
}
static void T_1 F_19 ( unsigned int V_22 )
{
unsigned V_7 , V_9 , V_10 , V_23 ;
bool V_24 ;
T_2 * V_25 ;
F_20 () ;
V_23 = F_21 () & V_18 ;
switch ( V_23 ) {
case 0x4 :
case 0x5 :
V_24 = false ;
break;
default:
V_24 = true ;
}
V_7 = F_7 () ;
if ( V_24 && V_7 > 1 ) {
F_22 ( L_4 ,
V_23 ) ;
F_23 (c) {
if ( V_14 [ V_10 ] . V_1 )
F_12 ( V_10 , false ) ;
}
}
V_25 = ( T_2 * ) & V_26 ;
F_24 ( & V_25 , 16 , 0 , V_23 ) ;
F_25 ( ( unsigned long ) & V_26 ,
( unsigned long ) V_25 ) ;
F_26 ( ( unsigned long ) & V_26 ,
( void * ) V_25 - ( void * ) & V_26 ) ;
F_27 () ;
V_27 = F_28 ( V_7 , sizeof( * V_27 ) ,
V_28 ) ;
if ( ! V_27 ) {
F_29 ( L_5 , V_7 ) ;
goto V_29;
}
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
V_9 = F_1 ( V_10 ) ;
V_27 [ V_10 ] . V_30 = F_28 ( V_9 ,
sizeof( * V_27 [ V_10 ] . V_30 ) ,
V_28 ) ;
if ( ! V_27 [ V_10 ] . V_30 ) {
F_29 ( L_6 ,
V_9 ) ;
goto V_29;
}
}
F_30 ( & V_27 [ V_31 . V_1 ] . V_32 ,
1 << F_31 ( & V_31 ) ) ;
return;
V_29:
if ( V_27 ) {
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ )
F_32 ( V_27 [ V_10 ] . V_30 ) ;
F_32 ( V_27 ) ;
V_27 = NULL ;
}
F_33 (c) {
if ( V_10 == 0 )
continue;
F_12 ( V_10 , false ) ;
}
}
static void F_34 ( unsigned V_1 )
{
T_2 V_33 , V_34 , V_35 ;
unsigned V_36 ;
F_3 ( V_1 , 0 ) ;
F_35 ( F_36 ( ( unsigned long ) V_26 ) ) ;
F_37 ( 0 ) ;
V_33 = F_38 () ;
V_33 |= 1 << ( V_37 + V_1 ) ;
F_39 ( V_33 ) ;
if ( F_40 () ) {
F_41 ( V_1 ) ;
F_42 ( V_38 ) ;
V_36 = 100 ;
while ( true ) {
V_34 = F_43 () ;
V_35 = V_34 & V_39 ;
if ( V_35 == V_40 )
break;
if ( V_36 ) {
V_36 -- ;
F_44 ( 10 ) ;
continue;
}
F_22 ( L_7 ,
V_1 , V_34 ) ;
F_44 ( 1000 ) ;
}
F_45 () ;
} else {
F_46 ( 0 ) ;
}
F_5 () ;
F_14 ( V_19 , V_1 , 1 ) ;
}
static void F_47 ( void * V_41 )
{
F_48 () ;
}
static void F_49 ( int V_42 , struct V_43 * V_44 )
{
unsigned V_1 = V_14 [ V_42 ] . V_1 ;
unsigned V_15 = F_31 ( & V_14 [ V_42 ] ) ;
struct V_45 * V_46 = & V_27 [ V_1 ] ;
struct V_47 * V_48 = & V_46 -> V_30 [ V_15 ] ;
unsigned int V_49 ;
int V_50 ;
V_48 -> V_51 = ( unsigned long ) & V_52 ;
V_48 -> V_53 = F_50 ( V_44 ) ;
V_48 -> V_54 = ( unsigned long ) F_51 ( V_44 ) ;
F_52 ( 1 << F_31 ( & V_14 [ V_42 ] ) , & V_46 -> V_32 ) ;
F_53 () ;
if ( ! F_54 ( V_1 , V_19 ) ) {
F_34 ( V_1 ) ;
goto V_55;
}
if ( V_1 != V_31 . V_1 ) {
for ( V_49 = 0 ; V_49 < V_13 ; V_49 ++ ) {
if ( V_14 [ V_49 ] . V_1 != V_1 )
continue;
if ( F_55 ( V_49 ) )
break;
}
F_56 ( V_49 >= V_13 ) ;
V_50 = F_57 ( V_49 , F_47 ,
NULL , 1 ) ;
if ( V_50 )
F_58 ( L_8 ) ;
goto V_55;
}
F_56 ( ! V_4 ) ;
F_48 () ;
V_55:
F_59 () ;
}
static void F_60 ( void )
{
if ( V_4 )
F_61 () ;
F_62 ( V_56 , V_57 | V_58 | V_59 |
V_60 | V_61 | V_62 ) ;
}
static void F_63 ( void )
{
F_64 ( F_65 () + ( 8 * V_63 / V_64 ) ) ;
#ifdef F_17
if ( V_20 )
F_18 ( F_66 () , & V_21 ) ;
#endif
F_67 () ;
}
static int F_68 ( void )
{
unsigned V_42 = F_66 () ;
struct V_45 * V_46 ;
if ( ! V_42 )
return - V_65 ;
if ( ! F_69 ( V_66 ) )
return - V_67 ;
V_46 = & V_27 [ V_31 . V_1 ] ;
F_70 ( 1 << F_31 ( & V_31 ) , & V_46 -> V_32 ) ;
F_71 () ;
F_72 ( V_42 , false ) ;
F_73 ( V_42 , & V_68 ) ;
return 0 ;
}
void F_74 ( void )
{
unsigned V_42 , V_1 ;
F_75 () ;
F_76 () ;
V_42 = F_66 () ;
V_69 = V_70 ;
if ( V_4 ) {
V_1 = V_14 [ V_42 ] . V_1 ;
F_77 (cpu_death_sibling) {
if ( V_14 [ V_71 ] . V_1 != V_1 )
continue;
V_69 = V_72 ;
break;
}
}
F_78 ( & V_73 ) ;
if ( V_69 == V_72 ) {
F_79 ( V_74 ) ;
F_80 () ;
} else {
F_81 ( V_66 ) ;
}
F_58 ( L_9 , V_42 ) ;
}
static void F_82 ( void * V_75 )
{
unsigned V_42 = ( unsigned long ) V_75 ;
unsigned V_15 = F_31 ( & V_14 [ V_42 ] ) ;
unsigned V_76 ;
unsigned long V_77 ;
do {
F_83 ( V_77 ) ;
F_84 ( V_15 ) ;
V_76 = F_85 () ;
F_86 ( V_77 ) ;
} while ( ! ( V_76 & V_74 ) );
}
static void F_87 ( unsigned int V_42 )
{
unsigned V_1 = V_14 [ V_42 ] . V_1 ;
unsigned V_34 ;
int V_50 ;
if ( ! F_88 ( & V_73 ,
F_89 ( 5000 ) ) ) {
F_29 ( L_10 , V_42 ) ;
return;
}
if ( V_69 == V_70 ) {
do {
F_41 ( V_1 ) ;
V_34 = F_43 () ;
V_34 &= V_39 ;
F_45 () ;
} while ( V_34 != V_78 &&
V_34 != V_79 &&
V_34 != V_80 );
F_90 ( V_19 , V_1 , 1 ) ;
} else if ( V_4 ) {
V_50 = F_57 ( V_71 ,
F_82 ,
( void * ) ( unsigned long ) V_42 , 1 ) ;
if ( V_50 )
F_58 ( L_11 ) ;
}
}
bool F_91 ( void )
{
extern struct V_81 * V_82 ;
return V_82 == & V_83 ;
}
int F_92 ( void )
{
if ( ! F_93 () ) {
F_22 ( L_12 ) ;
return - V_84 ;
}
if ( ! ( F_94 () & V_85 ) ) {
F_22 ( L_13 ) ;
return - V_84 ;
}
F_95 ( & V_83 ) ;
return 0 ;
}
