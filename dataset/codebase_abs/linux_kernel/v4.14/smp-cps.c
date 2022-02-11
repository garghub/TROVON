static int T_1 F_1 ( char * V_1 )
{
V_2 = true ;
return 0 ;
}
static unsigned F_2 ( unsigned int V_3 , unsigned V_4 )
{
if ( V_2 )
return 1 ;
return F_3 ( V_3 , V_4 ) ;
}
static void T_1 F_4 ( void )
{
unsigned int V_5 , V_6 , V_7 , V_8 ;
unsigned long V_9 ;
int V_10 , V_11 , V_12 ;
V_7 = 0 ;
V_5 = F_5 () ;
F_6 ( L_1 , V_13 ? L_2 : L_3 ) ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
if ( V_10 > 0 )
F_7 ( L_4 ) ;
F_7 ( L_5 ) ;
V_6 = F_8 ( V_10 ) ;
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
V_8 = F_2 ( V_10 , V_11 ) ;
if ( V_11 > 0 )
F_7 ( L_4 ) ;
F_7 ( L_6 , V_8 ) ;
if ( ! V_10 && ! V_11 )
V_14 = V_8 ;
for ( V_12 = 0 ; V_12 < F_9 ( int , V_8 , V_15 - V_7 ) ; V_12 ++ ) {
F_10 ( & V_16 [ V_7 + V_12 ] , V_10 ) ;
F_11 ( & V_16 [ V_7 + V_12 ] , V_11 ) ;
F_12 ( & V_16 [ V_7 + V_12 ] , V_12 ) ;
}
V_7 += V_8 ;
}
F_7 ( L_7 ) ;
}
F_7 ( L_8 , V_7 ) ;
for ( V_12 = 0 ; V_12 < F_9 ( unsigned , V_7 , V_15 ) ; V_12 ++ ) {
F_13 ( V_12 , F_14 ( & V_16 [ V_12 ] ) == 0 ) ;
F_15 ( V_12 , F_14 ( & V_16 [ V_12 ] ) == 0 ) ;
V_17 [ V_12 ] = V_12 ;
V_18 [ V_12 ] = V_12 ;
}
F_16 ( V_19 , 0x5 ) ;
F_17 ( V_20 , 0 , 1 ) ;
F_18 () ;
F_19 ( 0xff ) ;
if ( F_20 () >= V_21 ) {
V_9 = F_21 ( ( unsigned long ) V_22 ) ;
F_22 ( V_9 ) ;
}
#ifdef F_23
if ( V_23 )
F_24 ( 0 , & V_24 ) ;
#endif
}
static void T_1 F_25 ( unsigned int V_25 )
{
unsigned V_6 , V_8 , V_11 , V_26 ;
bool V_27 , V_28 ;
T_2 * V_29 ;
F_26 () ;
V_26 = F_27 () & V_19 ;
switch ( V_26 ) {
case 0x4 :
case 0x5 :
V_27 = false ;
break;
default:
V_27 = true ;
}
V_28 = false ;
if ( V_27 || V_30 ) {
F_28 (c) {
if ( F_29 ( F_30 () , V_11 ) )
continue;
F_15 ( V_11 , false ) ;
V_28 = true ;
}
}
if ( V_28 )
F_31 ( L_9 ,
V_27 ? L_10 : L_11 ,
( V_27 && V_30 ) ? L_12 : L_11 ,
V_30 ? L_13 : L_11 ) ;
V_29 = ( T_2 * ) & V_22 ;
F_32 ( & V_29 , 16 , 0 , V_26 ) ;
F_33 ( ( unsigned long ) & V_22 ,
( unsigned long ) V_29 ) ;
F_34 ( ( unsigned long ) & V_22 ,
( void * ) V_29 - ( void * ) & V_22 ) ;
F_35 () ;
V_6 = F_8 ( 0 ) ;
V_31 = F_36 ( V_6 , sizeof( * V_31 ) ,
V_32 ) ;
if ( ! V_31 ) {
F_37 ( L_14 , V_6 ) ;
goto V_33;
}
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ ) {
V_8 = F_2 ( 0 , V_11 ) ;
V_31 [ V_11 ] . V_34 = F_36 ( V_8 ,
sizeof( * V_31 [ V_11 ] . V_34 ) ,
V_32 ) ;
if ( ! V_31 [ V_11 ] . V_34 ) {
F_37 ( L_15 ,
V_8 ) ;
goto V_33;
}
}
F_38 ( & V_31 [ F_39 ( & V_35 ) ] . V_36 ,
1 << F_40 ( & V_35 ) ) ;
return;
V_33:
if ( V_31 ) {
for ( V_11 = 0 ; V_11 < V_6 ; V_11 ++ )
F_41 ( V_31 [ V_11 ] . V_34 ) ;
F_41 ( V_31 ) ;
V_31 = NULL ;
}
F_42 (c) {
if ( V_11 == 0 )
continue;
F_15 ( V_11 , false ) ;
}
}
static void F_43 ( unsigned int V_4 , unsigned int V_37 )
{
T_2 V_38 , V_39 ;
unsigned V_40 ;
F_44 ( 0 , V_4 , 0 , V_41 ) ;
F_45 ( F_21 ( ( unsigned long ) V_22 ) ) ;
F_46 ( 0 ) ;
F_47 ( V_42 ) ;
F_48 ( 1 << V_4 ) ;
if ( F_49 () ) {
F_50 ( V_4 ) ;
if ( F_20 () >= V_21 ) {
F_51 ( 0xf ) ;
F_52 ( 1 << V_37 ) ;
F_53 () ;
}
F_54 ( V_43 ) ;
V_40 = 100 ;
while ( true ) {
V_38 = F_55 () ;
V_39 = V_38 & V_44 ;
V_39 >>= F_56 ( V_44 ) ;
if ( V_39 == V_45 )
break;
if ( V_40 ) {
V_40 -- ;
F_57 ( 10 ) ;
continue;
}
F_31 ( L_16 ,
V_4 , V_38 ) ;
F_57 ( 1000 ) ;
}
F_58 () ;
} else {
F_59 ( 0 ) ;
}
F_60 () ;
F_17 ( V_20 , V_4 , 1 ) ;
}
static void F_61 ( void * V_46 )
{
unsigned V_4 = F_39 ( & V_35 ) ;
struct V_47 * V_48 = & V_31 [ V_4 ] ;
F_62 ( V_48 , F_40 ( & V_35 ) ) ;
}
static int F_63 ( int V_49 , struct V_50 * V_51 )
{
unsigned V_4 = F_39 ( & V_16 [ V_49 ] ) ;
unsigned V_37 = F_40 ( & V_16 [ V_49 ] ) ;
struct V_47 * V_48 = & V_31 [ V_4 ] ;
struct V_52 * V_53 = & V_48 -> V_34 [ V_37 ] ;
unsigned long V_9 ;
unsigned int V_54 ;
int V_55 ;
if ( F_14 ( & V_16 [ V_49 ] ) != F_14 ( & V_56 ) )
return - V_57 ;
V_53 -> V_58 = ( unsigned long ) & V_59 ;
V_53 -> V_60 = F_64 ( V_51 ) ;
V_53 -> V_61 = ( unsigned long ) F_65 ( V_51 ) ;
F_66 ( 1 << F_40 ( & V_16 [ V_49 ] ) , & V_48 -> V_36 ) ;
F_67 () ;
if ( ! F_68 ( V_4 , V_20 ) ) {
F_43 ( V_4 , V_37 ) ;
goto V_62;
}
if ( V_63 ) {
F_44 ( 0 , V_4 , V_37 , V_41 ) ;
V_9 = F_21 ( ( unsigned long ) V_22 ) ;
F_45 ( V_9 ) ;
F_60 () ;
}
if ( ! F_29 ( V_49 , F_30 () ) ) {
for ( V_54 = 0 ; V_54 < V_15 ; V_54 ++ ) {
if ( ! F_29 ( V_49 , V_54 ) )
continue;
if ( F_69 ( V_54 ) )
break;
}
if ( V_54 >= V_15 ) {
F_70 ( L_17 ,
V_4 , V_49 ) ;
goto V_62;
}
V_55 = F_71 ( V_54 , F_61 ,
NULL , 1 ) ;
if ( V_55 )
F_72 ( L_18 ) ;
goto V_62;
}
F_73 ( ! V_64 && ! V_63 ) ;
F_62 ( V_48 , V_37 ) ;
V_62:
F_74 () ;
return 0 ;
}
static void F_75 ( void )
{
if ( V_64 )
F_76 () ;
if ( F_20 () >= V_21 ) {
unsigned int V_65 = F_77 () ;
F_73 ( V_65 != F_78 ( F_30 () ) ) ;
}
if ( V_66 )
F_79 ( V_67 ) ;
else
F_80 ( V_67 , V_68 | V_69 |
V_70 | V_71 |
V_72 | V_73 ) ;
}
static void F_81 ( void )
{
F_82 ( F_83 () + ( 8 * V_74 / V_75 ) ) ;
#ifdef F_23
if ( V_23 )
F_24 ( F_30 () , & V_24 ) ;
#endif
F_84 () ;
}
static int F_85 ( void )
{
unsigned V_49 = F_30 () ;
struct V_47 * V_48 ;
if ( ! V_49 )
return - V_76 ;
if ( ! F_86 ( V_77 ) )
return - V_78 ;
V_48 = & V_31 [ F_39 ( & V_35 ) ] ;
F_87 ( 1 << F_40 ( & V_35 ) , & V_48 -> V_36 ) ;
F_88 () ;
F_89 ( V_49 , false ) ;
F_90 () ;
return 0 ;
}
void F_91 ( void )
{
unsigned int V_49 , V_4 , V_37 ;
F_92 () ;
F_93 () ;
V_49 = F_30 () ;
V_4 = F_39 ( & V_16 [ V_49 ] ) ;
V_79 = V_80 ;
F_94 ( L_19 , V_49 ) ;
if ( V_64 || V_63 ) {
V_4 = F_39 ( & V_16 [ V_49 ] ) ;
F_95 (cpu_death_sibling) {
if ( ! F_29 ( V_49 , V_81 ) )
continue;
V_79 = V_82 ;
break;
}
}
( void ) F_96 () ;
if ( V_79 == V_82 ) {
V_37 = F_40 ( & V_16 [ V_49 ] ) ;
F_94 ( L_20 , V_4 , V_37 ) ;
if ( V_64 ) {
F_97 ( V_83 ) ;
F_98 () ;
} else if ( V_63 ) {
F_99 ( 1 << V_37 ) ;
F_53 () ;
}
} else {
F_94 ( L_21 , V_4 ) ;
F_100 ( V_77 ) ;
}
F_72 ( L_22 , V_49 ) ;
}
static void F_101 ( void * V_84 )
{
unsigned V_49 = ( unsigned long ) V_84 ;
unsigned V_37 = F_40 ( & V_16 [ V_49 ] ) ;
unsigned V_85 ;
unsigned long V_86 ;
do {
F_102 ( V_86 ) ;
F_103 ( V_37 ) ;
V_85 = F_104 () ;
F_105 ( V_86 ) ;
} while ( ! ( V_85 & V_83 ) );
}
static void F_106 ( unsigned int V_49 )
{
unsigned V_4 = F_39 ( & V_16 [ V_49 ] ) ;
unsigned int V_37 = F_40 ( & V_16 [ V_49 ] ) ;
T_3 V_87 ;
unsigned V_38 ;
int V_55 ;
if ( ! F_107 ( V_49 , 5 ) ) {
F_37 ( L_23 , V_49 ) ;
return;
}
if ( V_79 == V_80 ) {
V_87 = F_108 ( F_109 () , 2000 ) ;
do {
F_44 ( 0 , V_4 , 0 , V_41 ) ;
F_50 ( V_4 ) ;
V_38 = F_55 () ;
V_38 &= V_44 ;
V_38 >>= F_56 ( V_44 ) ;
F_58 () ;
F_60 () ;
if ( V_38 == V_88 ||
V_38 == V_89 ||
V_38 == V_90 )
break;
if ( F_110 ( F_111 ( F_109 () , V_87 ) ,
L_24 ,
V_49 , V_38 ) )
break;
} while ( 1 );
F_112 ( V_20 , V_4 , 1 ) ;
} else if ( V_64 ) {
V_55 = F_71 ( V_81 ,
F_101 ,
( void * ) ( unsigned long ) V_49 , 1 ) ;
if ( V_55 )
F_72 ( L_25 ) ;
} else if ( V_63 ) {
do {
F_44 ( 0 , V_4 , V_37 , V_41 ) ;
V_38 = F_113 () ;
F_60 () ;
} while ( V_38 & ( 1 << V_37 ) );
}
}
bool F_114 ( void )
{
extern const struct V_91 * V_92 ;
return V_92 == & V_93 ;
}
int F_115 ( void )
{
if ( ! F_116 () ) {
F_31 ( L_26 ) ;
return - V_94 ;
}
if ( ! ( F_117 () & V_95 ) ) {
F_31 ( L_27 ) ;
return - V_94 ;
}
F_118 ( & V_93 ) ;
return 0 ;
}
