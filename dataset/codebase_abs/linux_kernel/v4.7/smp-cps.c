static int T_1 F_1 ( char * V_1 )
{
V_2 = true ;
return 0 ;
}
static unsigned F_2 ( unsigned V_3 )
{
unsigned V_4 ;
if ( V_2 )
return 1 ;
if ( ( ! F_3 ( V_5 ) || ! V_6 )
&& ( ! F_3 ( V_7 ) || ! V_8 ) )
return 1 ;
F_4 ( V_3 , 0 ) ;
V_4 = F_5 () & V_9 ;
F_6 () ;
return ( V_4 >> V_10 ) + 1 ;
}
static void T_1 F_7 ( void )
{
unsigned int V_11 , V_12 , V_13 ;
unsigned long V_14 ;
int V_15 , V_16 ;
V_11 = F_8 () ;
F_9 ( L_1 , V_17 ? L_2 : L_3 ) ;
for ( V_15 = V_12 = 0 ; V_15 < V_11 ; V_15 ++ ) {
V_13 = F_2 ( V_15 ) ;
F_10 ( L_4 , V_15 ? ',' : '{' , V_13 ) ;
if ( ! V_15 )
V_18 = V_13 ;
for ( V_16 = 0 ; V_16 < F_11 ( int , V_13 , V_19 - V_12 ) ; V_16 ++ ) {
V_20 [ V_12 + V_16 ] . V_3 = V_15 ;
#if F_12 ( V_5 ) || F_12 ( V_7 )
V_20 [ V_12 + V_16 ] . V_21 = V_16 ;
#endif
}
V_12 += V_13 ;
}
F_10 ( L_5 , V_12 ) ;
for ( V_16 = 0 ; V_16 < F_11 ( unsigned , V_12 , V_19 ) ; V_16 ++ ) {
F_13 ( V_16 , true ) ;
F_14 ( V_16 , true ) ;
V_22 [ V_16 ] = V_16 ;
V_23 [ V_16 ] = V_16 ;
}
F_15 ( V_24 , 0x5 ) ;
F_16 ( V_25 , 0 , 1 ) ;
F_17 () ;
F_18 ( 0xff ) ;
if ( F_19 () >= V_26 ) {
V_14 = F_20 ( ( unsigned long ) V_27 ) ;
F_21 ( V_14 ) ;
}
#ifdef F_22
if ( V_28 )
F_23 ( 0 , & V_29 ) ;
#endif
}
static void T_1 F_24 ( unsigned int V_30 )
{
unsigned V_11 , V_13 , V_15 , V_31 ;
bool V_32 ;
T_2 * V_33 ;
F_25 () ;
V_31 = F_26 () & V_24 ;
switch ( V_31 ) {
case 0x4 :
case 0x5 :
V_32 = false ;
break;
default:
V_32 = true ;
}
V_11 = F_8 () ;
if ( V_32 && V_11 > 1 ) {
F_27 ( L_6 ,
V_31 ) ;
F_28 (c) {
if ( V_20 [ V_15 ] . V_3 )
F_14 ( V_15 , false ) ;
}
}
V_33 = ( T_2 * ) & V_27 ;
F_29 ( & V_33 , 16 , 0 , V_31 ) ;
F_30 ( ( unsigned long ) & V_27 ,
( unsigned long ) V_33 ) ;
F_31 ( ( unsigned long ) & V_27 ,
( void * ) V_33 - ( void * ) & V_27 ) ;
F_32 () ;
V_34 = F_33 ( V_11 , sizeof( * V_34 ) ,
V_35 ) ;
if ( ! V_34 ) {
F_34 ( L_7 , V_11 ) ;
goto V_36;
}
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
V_13 = F_2 ( V_15 ) ;
V_34 [ V_15 ] . V_37 = F_33 ( V_13 ,
sizeof( * V_34 [ V_15 ] . V_37 ) ,
V_35 ) ;
if ( ! V_34 [ V_15 ] . V_37 ) {
F_34 ( L_8 ,
V_13 ) ;
goto V_36;
}
}
F_35 ( & V_34 [ V_38 . V_3 ] . V_39 ,
1 << F_36 ( & V_38 ) ) ;
return;
V_36:
if ( V_34 ) {
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ )
F_37 ( V_34 [ V_15 ] . V_37 ) ;
F_37 ( V_34 ) ;
V_34 = NULL ;
}
F_38 (c) {
if ( V_15 == 0 )
continue;
F_14 ( V_15 , false ) ;
}
}
static void F_39 ( unsigned V_3 )
{
T_2 V_40 , V_41 , V_42 ;
unsigned V_43 ;
F_4 ( V_3 , 0 ) ;
F_40 ( F_20 ( ( unsigned long ) V_27 ) ) ;
F_41 ( 0 ) ;
F_42 ( V_44 ) ;
V_40 = F_43 () ;
V_40 |= 1 << ( V_45 + V_3 ) ;
F_44 ( V_40 ) ;
if ( F_45 () ) {
F_46 ( V_3 ) ;
if ( F_19 () >= V_26 ) {
F_47 ( 0x1 ) ;
F_48 () ;
}
F_49 ( V_46 ) ;
V_43 = 100 ;
while ( true ) {
V_41 = F_50 () ;
V_42 = V_41 & V_47 ;
if ( V_42 == V_48 )
break;
if ( V_43 ) {
V_43 -- ;
F_51 ( 10 ) ;
continue;
}
F_27 ( L_9 ,
V_3 , V_41 ) ;
F_51 ( 1000 ) ;
}
F_52 () ;
} else {
F_53 ( 0 ) ;
}
F_6 () ;
F_16 ( V_25 , V_3 , 1 ) ;
}
static void F_54 ( void * V_49 )
{
unsigned V_3 = V_38 . V_3 ;
struct V_50 * V_51 = & V_34 [ V_3 ] ;
F_55 ( V_51 , F_36 ( & V_38 ) ) ;
}
static void F_56 ( int V_52 , struct V_53 * V_54 )
{
unsigned V_3 = V_20 [ V_52 ] . V_3 ;
unsigned V_21 = F_36 ( & V_20 [ V_52 ] ) ;
struct V_50 * V_51 = & V_34 [ V_3 ] ;
struct V_55 * V_56 = & V_51 -> V_37 [ V_21 ] ;
unsigned long V_14 ;
unsigned int V_57 ;
int V_58 ;
V_56 -> V_59 = ( unsigned long ) & V_60 ;
V_56 -> V_61 = F_57 ( V_54 ) ;
V_56 -> V_62 = ( unsigned long ) F_58 ( V_54 ) ;
F_59 ( 1 << F_36 ( & V_20 [ V_52 ] ) , & V_51 -> V_39 ) ;
F_60 () ;
if ( ! F_61 ( V_3 , V_25 ) ) {
F_39 ( V_3 ) ;
goto V_63;
}
if ( V_8 ) {
F_4 ( V_3 , V_21 ) ;
V_14 = F_20 ( ( unsigned long ) V_27 ) ;
F_40 ( V_14 ) ;
F_6 () ;
}
if ( V_3 != V_38 . V_3 ) {
for ( V_57 = 0 ; V_57 < V_19 ; V_57 ++ ) {
if ( V_20 [ V_57 ] . V_3 != V_3 )
continue;
if ( F_62 ( V_57 ) )
break;
}
F_63 ( V_57 >= V_19 ) ;
V_58 = F_64 ( V_57 , F_54 ,
NULL , 1 ) ;
if ( V_58 )
F_65 ( L_10 ) ;
goto V_63;
}
F_63 ( ! V_6 && ! V_8 ) ;
F_55 ( V_51 , V_21 ) ;
V_63:
F_66 () ;
}
static void F_67 ( void )
{
if ( V_6 )
F_68 () ;
if ( F_19 () >= V_26 ) {
unsigned V_64 = F_69 () ;
F_63 ( V_64 != F_70 ( F_71 () ) ) ;
}
if ( V_65 )
F_72 ( V_66 ) ;
else
F_73 ( V_66 , V_67 | V_68 |
V_69 | V_70 |
V_71 | V_72 ) ;
}
static void F_74 ( void )
{
F_75 ( F_76 () + ( 8 * V_73 / V_74 ) ) ;
#ifdef F_22
if ( V_28 )
F_23 ( F_71 () , & V_29 ) ;
#endif
F_77 () ;
}
static int F_78 ( void )
{
unsigned V_52 = F_71 () ;
struct V_50 * V_51 ;
if ( ! V_52 )
return - V_75 ;
if ( ! F_79 ( V_76 ) )
return - V_77 ;
V_51 = & V_34 [ V_38 . V_3 ] ;
F_80 ( 1 << F_36 ( & V_38 ) , & V_51 -> V_39 ) ;
F_81 () ;
F_82 ( V_52 , false ) ;
F_83 ( V_52 , & V_78 ) ;
return 0 ;
}
void F_84 ( void )
{
unsigned V_52 , V_3 ;
F_85 () ;
F_86 () ;
V_52 = F_71 () ;
V_79 = V_80 ;
if ( V_6 ) {
V_3 = V_20 [ V_52 ] . V_3 ;
F_87 (cpu_death_sibling) {
if ( V_20 [ V_81 ] . V_3 != V_3 )
continue;
V_79 = V_82 ;
break;
}
}
F_88 ( & V_83 ) ;
if ( V_79 == V_82 ) {
F_89 ( V_84 ) ;
F_90 () ;
} else {
F_91 ( V_76 ) ;
}
F_65 ( L_11 , V_52 ) ;
}
static void F_92 ( void * V_85 )
{
unsigned V_52 = ( unsigned long ) V_85 ;
unsigned V_21 = F_36 ( & V_20 [ V_52 ] ) ;
unsigned V_86 ;
unsigned long V_87 ;
do {
F_93 ( V_87 ) ;
F_94 ( V_21 ) ;
V_86 = F_95 () ;
F_96 ( V_87 ) ;
} while ( ! ( V_86 & V_84 ) );
}
static void F_97 ( unsigned int V_52 )
{
unsigned V_3 = V_20 [ V_52 ] . V_3 ;
unsigned V_41 ;
int V_58 ;
if ( ! F_98 ( & V_83 ,
F_99 ( 5000 ) ) ) {
F_34 ( L_12 , V_52 ) ;
return;
}
if ( V_79 == V_80 ) {
do {
F_46 ( V_3 ) ;
V_41 = F_50 () ;
V_41 &= V_47 ;
F_52 () ;
} while ( V_41 != V_88 &&
V_41 != V_89 &&
V_41 != V_90 );
F_100 ( V_25 , V_3 , 1 ) ;
} else if ( V_6 ) {
V_58 = F_64 ( V_81 ,
F_92 ,
( void * ) ( unsigned long ) V_52 , 1 ) ;
if ( V_58 )
F_65 ( L_13 ) ;
}
}
bool F_101 ( void )
{
extern struct V_91 * V_92 ;
return V_92 == & V_93 ;
}
int F_102 ( void )
{
if ( ! F_103 () ) {
F_27 ( L_14 ) ;
return - V_94 ;
}
if ( ! ( F_104 () & V_95 ) ) {
F_27 ( L_15 ) ;
return - V_94 ;
}
F_105 ( & V_93 ) ;
return 0 ;
}
