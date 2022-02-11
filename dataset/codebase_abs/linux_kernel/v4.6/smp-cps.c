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
F_38 ( V_37 ) ;
V_33 = F_39 () ;
V_33 |= 1 << ( V_38 + V_1 ) ;
F_40 ( V_33 ) ;
if ( F_41 () ) {
F_42 ( V_1 ) ;
F_43 ( V_39 ) ;
V_36 = 100 ;
while ( true ) {
V_34 = F_44 () ;
V_35 = V_34 & V_40 ;
if ( V_35 == V_41 )
break;
if ( V_36 ) {
V_36 -- ;
F_45 ( 10 ) ;
continue;
}
F_22 ( L_7 ,
V_1 , V_34 ) ;
F_45 ( 1000 ) ;
}
F_46 () ;
} else {
F_47 ( 0 ) ;
}
F_5 () ;
F_14 ( V_19 , V_1 , 1 ) ;
}
static void F_48 ( void * V_42 )
{
F_49 () ;
}
static void F_50 ( int V_43 , struct V_44 * V_45 )
{
unsigned V_1 = V_14 [ V_43 ] . V_1 ;
unsigned V_15 = F_31 ( & V_14 [ V_43 ] ) ;
struct V_46 * V_47 = & V_27 [ V_1 ] ;
struct V_48 * V_49 = & V_47 -> V_30 [ V_15 ] ;
unsigned int V_50 ;
int V_51 ;
V_49 -> V_52 = ( unsigned long ) & V_53 ;
V_49 -> V_54 = F_51 ( V_45 ) ;
V_49 -> V_55 = ( unsigned long ) F_52 ( V_45 ) ;
F_53 ( 1 << F_31 ( & V_14 [ V_43 ] ) , & V_47 -> V_32 ) ;
F_54 () ;
if ( ! F_55 ( V_1 , V_19 ) ) {
F_34 ( V_1 ) ;
goto V_56;
}
if ( V_1 != V_31 . V_1 ) {
for ( V_50 = 0 ; V_50 < V_13 ; V_50 ++ ) {
if ( V_14 [ V_50 ] . V_1 != V_1 )
continue;
if ( F_56 ( V_50 ) )
break;
}
F_57 ( V_50 >= V_13 ) ;
V_51 = F_58 ( V_50 , F_48 ,
NULL , 1 ) ;
if ( V_51 )
F_59 ( L_8 ) ;
goto V_56;
}
F_57 ( ! V_4 ) ;
F_49 () ;
V_56:
F_60 () ;
}
static void F_61 ( void )
{
if ( V_4 )
F_62 () ;
F_63 ( V_57 , V_58 | V_59 | V_60 |
V_61 | V_62 | V_63 ) ;
}
static void F_64 ( void )
{
F_65 ( F_66 () + ( 8 * V_64 / V_65 ) ) ;
#ifdef F_17
if ( V_20 )
F_18 ( F_67 () , & V_21 ) ;
#endif
F_68 () ;
}
static int F_69 ( void )
{
unsigned V_43 = F_67 () ;
struct V_46 * V_47 ;
if ( ! V_43 )
return - V_66 ;
if ( ! F_70 ( V_67 ) )
return - V_68 ;
V_47 = & V_27 [ V_31 . V_1 ] ;
F_71 ( 1 << F_31 ( & V_31 ) , & V_47 -> V_32 ) ;
F_72 () ;
F_73 ( V_43 , false ) ;
F_74 ( V_43 , & V_69 ) ;
return 0 ;
}
void F_75 ( void )
{
unsigned V_43 , V_1 ;
F_76 () ;
F_77 () ;
V_43 = F_67 () ;
V_70 = V_71 ;
if ( V_4 ) {
V_1 = V_14 [ V_43 ] . V_1 ;
F_78 (cpu_death_sibling) {
if ( V_14 [ V_72 ] . V_1 != V_1 )
continue;
V_70 = V_73 ;
break;
}
}
F_79 ( & V_74 ) ;
if ( V_70 == V_73 ) {
F_80 ( V_75 ) ;
F_81 () ;
} else {
F_82 ( V_67 ) ;
}
F_59 ( L_9 , V_43 ) ;
}
static void F_83 ( void * V_76 )
{
unsigned V_43 = ( unsigned long ) V_76 ;
unsigned V_15 = F_31 ( & V_14 [ V_43 ] ) ;
unsigned V_77 ;
unsigned long V_78 ;
do {
F_84 ( V_78 ) ;
F_85 ( V_15 ) ;
V_77 = F_86 () ;
F_87 ( V_78 ) ;
} while ( ! ( V_77 & V_75 ) );
}
static void F_88 ( unsigned int V_43 )
{
unsigned V_1 = V_14 [ V_43 ] . V_1 ;
unsigned V_34 ;
int V_51 ;
if ( ! F_89 ( & V_74 ,
F_90 ( 5000 ) ) ) {
F_29 ( L_10 , V_43 ) ;
return;
}
if ( V_70 == V_71 ) {
do {
F_42 ( V_1 ) ;
V_34 = F_44 () ;
V_34 &= V_40 ;
F_46 () ;
} while ( V_34 != V_79 &&
V_34 != V_80 &&
V_34 != V_81 );
F_91 ( V_19 , V_1 , 1 ) ;
} else if ( V_4 ) {
V_51 = F_58 ( V_72 ,
F_83 ,
( void * ) ( unsigned long ) V_43 , 1 ) ;
if ( V_51 )
F_59 ( L_11 ) ;
}
}
bool F_92 ( void )
{
extern struct V_82 * V_83 ;
return V_83 == & V_84 ;
}
int F_93 ( void )
{
if ( ! F_94 () ) {
F_22 ( L_12 ) ;
return - V_85 ;
}
if ( ! ( F_95 () & V_86 ) ) {
F_22 ( L_13 ) ;
return - V_85 ;
}
F_96 ( & V_84 ) ;
return 0 ;
}
