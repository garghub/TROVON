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
if ( ( V_32 || V_34 ) && V_11 > 1 ) {
F_27 ( L_6 ,
V_32 ? L_7 : L_8 ,
( V_32 && V_34 ) ? L_9 : L_8 ,
V_34 ? L_10 : L_8 ) ;
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
V_35 = F_33 ( V_11 , sizeof( * V_35 ) ,
V_36 ) ;
if ( ! V_35 ) {
F_34 ( L_11 , V_11 ) ;
goto V_37;
}
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ ) {
V_13 = F_2 ( V_15 ) ;
V_35 [ V_15 ] . V_38 = F_33 ( V_13 ,
sizeof( * V_35 [ V_15 ] . V_38 ) ,
V_36 ) ;
if ( ! V_35 [ V_15 ] . V_38 ) {
F_34 ( L_12 ,
V_13 ) ;
goto V_37;
}
}
F_35 ( & V_35 [ V_39 . V_3 ] . V_40 ,
1 << F_36 ( & V_39 ) ) ;
return;
V_37:
if ( V_35 ) {
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ )
F_37 ( V_35 [ V_15 ] . V_38 ) ;
F_37 ( V_35 ) ;
V_35 = NULL ;
}
F_38 (c) {
if ( V_15 == 0 )
continue;
F_14 ( V_15 , false ) ;
}
}
static void F_39 ( unsigned int V_3 , unsigned int V_21 )
{
T_2 V_41 , V_42 , V_43 ;
unsigned V_44 ;
F_4 ( V_3 , 0 ) ;
F_40 ( F_20 ( ( unsigned long ) V_27 ) ) ;
F_41 ( 0 ) ;
F_42 ( V_45 ) ;
V_41 = F_43 () ;
V_41 |= 1 << ( V_46 + V_3 ) ;
F_44 ( V_41 ) ;
if ( F_45 () ) {
F_46 ( V_3 ) ;
if ( F_19 () >= V_26 ) {
F_47 ( 0xf ) ;
F_48 ( 1 << V_21 ) ;
F_49 () ;
}
F_50 ( V_47 ) ;
V_44 = 100 ;
while ( true ) {
V_42 = F_51 () ;
V_43 = V_42 & V_48 ;
if ( V_43 == V_49 )
break;
if ( V_44 ) {
V_44 -- ;
F_52 ( 10 ) ;
continue;
}
F_27 ( L_13 ,
V_3 , V_42 ) ;
F_52 ( 1000 ) ;
}
F_53 () ;
} else {
F_54 ( 0 ) ;
}
F_6 () ;
F_16 ( V_25 , V_3 , 1 ) ;
}
static void F_55 ( void * V_50 )
{
unsigned V_3 = V_39 . V_3 ;
struct V_51 * V_52 = & V_35 [ V_3 ] ;
F_56 ( V_52 , F_36 ( & V_39 ) ) ;
}
static void F_57 ( int V_53 , struct V_54 * V_55 )
{
unsigned V_3 = V_20 [ V_53 ] . V_3 ;
unsigned V_21 = F_36 ( & V_20 [ V_53 ] ) ;
struct V_51 * V_52 = & V_35 [ V_3 ] ;
struct V_56 * V_57 = & V_52 -> V_38 [ V_21 ] ;
unsigned long V_14 ;
unsigned int V_58 ;
int V_59 ;
V_57 -> V_60 = ( unsigned long ) & V_61 ;
V_57 -> V_62 = F_58 ( V_55 ) ;
V_57 -> V_63 = ( unsigned long ) F_59 ( V_55 ) ;
F_60 ( 1 << F_36 ( & V_20 [ V_53 ] ) , & V_52 -> V_40 ) ;
F_61 () ;
if ( ! F_62 ( V_3 , V_25 ) ) {
F_39 ( V_3 , V_21 ) ;
goto V_64;
}
if ( V_8 ) {
F_4 ( V_3 , V_21 ) ;
V_14 = F_20 ( ( unsigned long ) V_27 ) ;
F_40 ( V_14 ) ;
F_6 () ;
}
if ( V_3 != V_39 . V_3 ) {
for ( V_58 = 0 ; V_58 < V_19 ; V_58 ++ ) {
if ( V_20 [ V_58 ] . V_3 != V_3 )
continue;
if ( F_63 ( V_58 ) )
break;
}
if ( V_58 >= V_19 ) {
F_64 ( L_14 ,
V_3 , V_53 ) ;
goto V_64;
}
V_59 = F_65 ( V_58 , F_55 ,
NULL , 1 ) ;
if ( V_59 )
F_66 ( L_15 ) ;
goto V_64;
}
F_67 ( ! V_6 && ! V_8 ) ;
F_56 ( V_52 , V_21 ) ;
V_64:
F_68 () ;
}
static void F_69 ( void )
{
if ( V_6 )
F_70 () ;
if ( F_19 () >= V_26 ) {
unsigned V_65 = F_71 () ;
F_67 ( V_65 != F_72 ( F_73 () ) ) ;
}
if ( V_66 )
F_74 ( V_67 ) ;
else
F_75 ( V_67 , V_68 | V_69 |
V_70 | V_71 |
V_72 | V_73 ) ;
}
static void F_76 ( void )
{
F_77 ( F_78 () + ( 8 * V_74 / V_75 ) ) ;
#ifdef F_22
if ( V_28 )
F_23 ( F_73 () , & V_29 ) ;
#endif
F_79 () ;
}
static int F_80 ( void )
{
unsigned V_53 = F_73 () ;
struct V_51 * V_52 ;
if ( ! V_53 )
return - V_76 ;
if ( ! F_81 ( V_77 ) )
return - V_78 ;
V_52 = & V_35 [ V_39 . V_3 ] ;
F_82 ( 1 << F_36 ( & V_39 ) , & V_52 -> V_40 ) ;
F_83 () ;
F_84 ( V_53 , false ) ;
F_85 () ;
return 0 ;
}
void F_86 ( void )
{
unsigned int V_53 , V_3 , V_21 ;
F_87 () ;
F_88 () ;
V_53 = F_73 () ;
V_3 = V_20 [ V_53 ] . V_3 ;
V_79 = V_80 ;
F_89 ( L_16 , V_53 ) ;
if ( V_6 || V_8 ) {
F_90 (cpu_death_sibling) {
if ( V_20 [ V_81 ] . V_3 != V_3 )
continue;
V_79 = V_82 ;
break;
}
}
( void ) F_91 () ;
if ( V_79 == V_82 ) {
V_21 = F_36 ( & V_20 [ V_53 ] ) ;
F_89 ( L_17 , V_3 , V_21 ) ;
if ( V_6 ) {
F_92 ( V_83 ) ;
F_93 () ;
} else if ( V_8 ) {
F_94 ( 1 << V_21 ) ;
F_49 () ;
}
} else {
F_89 ( L_18 , V_3 ) ;
F_95 ( V_77 ) ;
}
F_66 ( L_19 , V_53 ) ;
}
static void F_96 ( void * V_84 )
{
unsigned V_53 = ( unsigned long ) V_84 ;
unsigned V_21 = F_36 ( & V_20 [ V_53 ] ) ;
unsigned V_85 ;
unsigned long V_86 ;
do {
F_97 ( V_86 ) ;
F_98 ( V_21 ) ;
V_85 = F_99 () ;
F_100 ( V_86 ) ;
} while ( ! ( V_85 & V_83 ) );
}
static void F_101 ( unsigned int V_53 )
{
unsigned V_3 = V_20 [ V_53 ] . V_3 ;
unsigned int V_21 = F_36 ( & V_20 [ V_53 ] ) ;
T_3 V_87 ;
unsigned V_42 ;
int V_59 ;
if ( ! F_102 ( V_53 , 5 ) ) {
F_34 ( L_20 , V_53 ) ;
return;
}
if ( V_79 == V_80 ) {
V_87 = F_103 ( F_104 () , 2000 ) ;
do {
F_4 ( V_3 , 0 ) ;
F_46 ( V_3 ) ;
V_42 = F_51 () ;
V_42 &= V_48 ;
F_53 () ;
F_6 () ;
if ( V_42 == V_88 ||
V_42 == V_89 ||
V_42 == V_90 )
break;
if ( F_105 ( F_106 ( F_104 () , V_87 ) ,
L_21 ,
V_53 , V_42 >> V_91 ) )
break;
} while ( 1 );
F_107 ( V_25 , V_3 , 1 ) ;
} else if ( V_6 ) {
V_59 = F_65 ( V_81 ,
F_96 ,
( void * ) ( unsigned long ) V_53 , 1 ) ;
if ( V_59 )
F_66 ( L_22 ) ;
} else if ( V_8 ) {
do {
F_4 ( V_3 , V_21 ) ;
V_42 = F_108 () ;
F_6 () ;
} while ( V_42 & ( 1 << V_21 ) );
}
}
bool F_109 ( void )
{
extern struct V_92 * V_93 ;
return V_93 == & V_94 ;
}
int F_110 ( void )
{
if ( ! F_111 () ) {
F_27 ( L_23 ) ;
return - V_95 ;
}
if ( ! ( F_112 () & V_96 ) ) {
F_27 ( L_24 ) ;
return - V_95 ;
}
F_113 ( & V_94 ) ;
return 0 ;
}
