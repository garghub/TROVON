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
static void F_39 ( unsigned int V_3 , unsigned int V_21 )
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
F_47 ( 0xf ) ;
F_48 ( 1 << V_21 ) ;
F_49 () ;
}
F_50 ( V_46 ) ;
V_43 = 100 ;
while ( true ) {
V_41 = F_51 () ;
V_42 = V_41 & V_47 ;
if ( V_42 == V_48 )
break;
if ( V_43 ) {
V_43 -- ;
F_52 ( 10 ) ;
continue;
}
F_27 ( L_9 ,
V_3 , V_41 ) ;
F_52 ( 1000 ) ;
}
F_53 () ;
} else {
F_54 ( 0 ) ;
}
F_6 () ;
F_16 ( V_25 , V_3 , 1 ) ;
}
static void F_55 ( void * V_49 )
{
unsigned V_3 = V_38 . V_3 ;
struct V_50 * V_51 = & V_34 [ V_3 ] ;
F_56 ( V_51 , F_36 ( & V_38 ) ) ;
}
static void F_57 ( int V_52 , struct V_53 * V_54 )
{
unsigned V_3 = V_20 [ V_52 ] . V_3 ;
unsigned V_21 = F_36 ( & V_20 [ V_52 ] ) ;
struct V_50 * V_51 = & V_34 [ V_3 ] ;
struct V_55 * V_56 = & V_51 -> V_37 [ V_21 ] ;
unsigned long V_14 ;
unsigned int V_57 ;
int V_58 ;
V_56 -> V_59 = ( unsigned long ) & V_60 ;
V_56 -> V_61 = F_58 ( V_54 ) ;
V_56 -> V_62 = ( unsigned long ) F_59 ( V_54 ) ;
F_60 ( 1 << F_36 ( & V_20 [ V_52 ] ) , & V_51 -> V_39 ) ;
F_61 () ;
if ( ! F_62 ( V_3 , V_25 ) ) {
F_39 ( V_3 , V_21 ) ;
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
if ( F_63 ( V_57 ) )
break;
}
F_64 ( V_57 >= V_19 ) ;
V_58 = F_65 ( V_57 , F_55 ,
NULL , 1 ) ;
if ( V_58 )
F_66 ( L_10 ) ;
goto V_63;
}
F_64 ( ! V_6 && ! V_8 ) ;
F_56 ( V_51 , V_21 ) ;
V_63:
F_67 () ;
}
static void F_68 ( void )
{
if ( V_6 )
F_69 () ;
if ( F_19 () >= V_26 ) {
unsigned V_64 = F_70 () ;
F_64 ( V_64 != F_71 ( F_72 () ) ) ;
}
if ( V_65 )
F_73 ( V_66 ) ;
else
F_74 ( V_66 , V_67 | V_68 |
V_69 | V_70 |
V_71 | V_72 ) ;
}
static void F_75 ( void )
{
F_76 ( F_77 () + ( 8 * V_73 / V_74 ) ) ;
#ifdef F_22
if ( V_28 )
F_23 ( F_72 () , & V_29 ) ;
#endif
F_78 () ;
}
static int F_79 ( void )
{
unsigned V_52 = F_72 () ;
struct V_50 * V_51 ;
if ( ! V_52 )
return - V_75 ;
if ( ! F_80 ( V_76 ) )
return - V_77 ;
V_51 = & V_34 [ V_38 . V_3 ] ;
F_81 ( 1 << F_36 ( & V_38 ) , & V_51 -> V_39 ) ;
F_82 () ;
F_83 ( V_52 , false ) ;
F_84 () ;
F_85 ( V_52 , & V_78 ) ;
return 0 ;
}
void F_86 ( void )
{
unsigned int V_52 , V_3 , V_21 ;
F_87 () ;
F_88 () ;
V_52 = F_72 () ;
V_79 = V_80 ;
F_89 ( L_11 , V_52 ) ;
if ( V_6 || V_8 ) {
V_3 = V_20 [ V_52 ] . V_3 ;
F_90 (cpu_death_sibling) {
if ( V_20 [ V_81 ] . V_3 != V_3 )
continue;
V_79 = V_82 ;
break;
}
}
F_91 ( & V_83 ) ;
if ( V_79 == V_82 ) {
V_21 = F_36 ( & V_20 [ V_52 ] ) ;
F_89 ( L_12 , V_3 , V_21 ) ;
if ( V_6 ) {
F_92 ( V_84 ) ;
F_93 () ;
} else if ( V_8 ) {
F_94 ( 1 << V_21 ) ;
F_49 () ;
}
} else {
F_89 ( L_13 , V_3 ) ;
F_95 ( V_76 ) ;
}
F_66 ( L_14 , V_52 ) ;
}
static void F_96 ( void * V_85 )
{
unsigned V_52 = ( unsigned long ) V_85 ;
unsigned V_21 = F_36 ( & V_20 [ V_52 ] ) ;
unsigned V_86 ;
unsigned long V_87 ;
do {
F_97 ( V_87 ) ;
F_98 ( V_21 ) ;
V_86 = F_99 () ;
F_100 ( V_87 ) ;
} while ( ! ( V_86 & V_84 ) );
}
static void F_101 ( unsigned int V_52 )
{
unsigned V_3 = V_20 [ V_52 ] . V_3 ;
unsigned int V_21 = F_36 ( & V_20 [ V_52 ] ) ;
unsigned V_41 ;
int V_58 ;
if ( ! F_102 ( & V_83 ,
F_103 ( 5000 ) ) ) {
F_34 ( L_15 , V_52 ) ;
return;
}
if ( V_79 == V_80 ) {
do {
F_4 ( V_3 , 0 ) ;
F_46 ( V_3 ) ;
V_41 = F_51 () ;
V_41 &= V_47 ;
F_53 () ;
F_6 () ;
} while ( V_41 != V_88 &&
V_41 != V_89 &&
V_41 != V_90 );
F_104 ( V_25 , V_3 , 1 ) ;
} else if ( V_6 ) {
V_58 = F_65 ( V_81 ,
F_96 ,
( void * ) ( unsigned long ) V_52 , 1 ) ;
if ( V_58 )
F_66 ( L_16 ) ;
} else if ( V_8 ) {
do {
F_4 ( V_3 , V_21 ) ;
V_41 = F_105 () ;
F_6 () ;
} while ( V_41 & ( 1 << V_21 ) );
}
}
bool F_106 ( void )
{
extern struct V_91 * V_92 ;
return V_92 == & V_93 ;
}
int F_107 ( void )
{
if ( ! F_108 () ) {
F_27 ( L_17 ) ;
return - V_94 ;
}
if ( ! ( F_109 () & V_95 ) ) {
F_27 ( L_18 ) ;
return - V_94 ;
}
F_110 ( & V_93 ) ;
return 0 ;
}
