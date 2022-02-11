static int F_1 ( unsigned long V_1 , void T_1 * V_2 ,
unsigned char V_3 )
{
volatile unsigned char V_4 ;
if( ( F_2 ( V_2 + V_5 ) != 0x00 ) ||
( F_2 ( V_2 + V_5 + 1 ) != 0x55 ) ||
( F_2 ( V_2 + V_5 + 2 ) != 0xAA ) ||
( F_2 ( V_2 + V_5 + 3 ) != 0xFF ) )
return 0 ;
if ( ! V_3 )
V_3 = F_2 ( V_2 + V_6 ) ;
if ( ! V_3 || V_3 > V_7 ) {
F_3 ( V_8 L_1 ,
V_3 , V_1 , V_7 ) ;
return 0 ;
}
if ( V_9 [ V_3 - 1 ] . V_10 ) {
F_3 ( V_8 L_2 ,
V_3 , V_1 , V_3 , V_9 [ V_3 - 1 ] . V_11 ) ;
return 0 ;
}
V_3 -- ;
V_9 [ V_3 ] . V_11 = V_1 ;
V_9 [ V_3 ] . V_10 = V_2 ;
F_4 ( & V_9 [ V_3 ] . V_12 ) ;
F_5 ( & V_9 [ V_3 ] . V_13 ) ;
V_4 = F_2 ( V_2 + V_14 ) ;
V_15 ++ ;
return V_3 + 1 ;
}
static void T_2 F_6 ( void )
{
unsigned int V_16 ;
F_7 ( & V_17 ) ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
if ( ! V_9 [ V_16 ] . V_10 )
continue;
if ( V_9 [ V_16 ] . V_18 )
F_8 ( V_9 [ V_16 ] . V_18 , & V_19 ) ;
F_9 ( V_9 [ V_16 ] . V_10 ) ;
}
}
static int T_3 F_10 ( void )
{
int V_16 , V_20 = 0 ;
struct V_21 * V_22 = NULL ;
void T_1 * V_10 ;
int V_3 , V_23 ;
F_3 ( V_24 L_3 ) ;
while ( ( V_22 = F_11 ( V_25 << 16 , V_22 ) ) ) {
if ( ! F_12 ( V_26 , V_22 ) )
continue;
if ( F_13 ( V_22 ) )
return - V_27 ;
V_10 = F_14 ( F_15 ( V_22 , 0 ) , V_28 ) ;
if ( ! V_10 ) {
F_3 ( V_24 L_4
L_5 ,
( unsigned long long ) F_15 ( V_22 , 0 ) ) ;
F_16 ( V_22 ) ;
return - V_27 ;
}
F_3 ( V_24 L_6 ,
V_29 [ V_22 -> V_30 - 1 ] ,
( unsigned long long ) F_15 ( V_22 , 0 ) ,
V_22 -> V_18 ) ;
V_3 = F_1 ( F_15 ( V_22 , 0 ) ,
V_10 , 0 ) ;
if ( ! V_3 ) {
F_3 ( V_24 L_7 ) ;
F_9 ( V_10 ) ;
F_16 ( V_22 ) ;
continue;
}
if ( F_17 ( V_22 -> V_18 , & V_31 , V_32 , L_8 , & V_19 ) ) {
F_3 ( V_24 L_9 , V_22 -> V_18 ) ;
F_9 ( V_10 ) ;
F_16 ( V_22 ) ;
V_9 [ V_3 - 1 ] . V_10 = NULL ;
continue;
}
F_18 ( 0x40 , V_9 [ V_3 - 1 ] . V_10 + V_33 ) ;
V_9 [ V_3 - 1 ] . V_18 = V_22 -> V_18 ;
}
if ( ! V_34 || ! V_18 ) {
if ( V_15 )
goto V_35;
else {
F_3 ( V_24 L_10 ) ;
F_3 ( V_24 L_11 ) ;
return - V_36 ;
}
}
for ( V_16 = 0 ; V_16 < V_37 ; V_16 ++ ) {
V_10 = F_14 ( V_34 + ( V_28 * V_16 ) , V_28 ) ;
if ( ! V_10 ) {
F_3 ( V_24 L_12 , V_16 + 1 ) ;
continue;
}
if ( ! ( V_3 = F_1 ( ( unsigned long ) V_34 + ( V_28 * V_16 ) ,
V_10 , V_16 + 1 ) ) ) {
F_9 ( V_10 ) ;
continue;
}
F_3 ( V_38 L_13 , V_34 + ( V_28 * V_16 ) , V_18 ) ;
if ( ! V_20 ) {
if ( F_17 ( V_18 , & V_31 , V_32 , L_14 , & V_19 ) ) {
F_3 ( V_8 L_15 , V_18 ) ;
F_9 ( V_10 ) ;
V_9 [ V_3 - 1 ] . V_10 = NULL ;
}
else
V_9 [ V_3 - 1 ] . V_18 = V_18 ;
}
else
V_9 [ V_3 - 1 ] . V_18 = 0 ;
V_20 ++ ;
}
if ( ! V_20 )
F_3 ( V_8 L_16
L_17 , V_34 ) ;
V_35:
F_4 ( & V_39 ) ;
V_40 = 0 ;
V_41 = 0 ;
V_42 = 0 ;
if ( V_15 ) {
V_23 = F_19 ( & V_17 ) ;
if ( V_23 ) {
F_3 ( V_8 L_18 ) ;
goto V_43;
}
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
int V_44 ;
char V_45 [ ( V_46 - V_47 ) + 1 ] ;
if ( ! V_9 [ V_16 ] . V_10 )
continue;
for ( V_44 = 0 ; V_44 < V_46 - V_47 ; V_44 ++ )
V_45 [ V_44 ] = F_2 ( V_9 [ V_16 ] . V_10 + V_47 + V_44 ) ;
V_45 [ V_44 ] = 0 ;
F_3 ( V_24 L_19 ,
V_16 + 1 , V_45 ,
( int ) ( F_2 ( V_9 [ V_16 ] . V_10 + V_48 ) >> 4 ) ,
( int ) ( F_2 ( V_9 [ V_16 ] . V_10 + V_48 ) & 0xF ) ) ;
V_44 = ( F_2 ( V_9 [ V_16 ] . V_10 + V_46 ) << 16 ) +
( F_2 ( V_9 [ V_16 ] . V_10 + V_46 + 1 ) << 8 ) +
( F_2 ( V_9 [ V_16 ] . V_10 + V_46 + 2 ) ) ;
if ( V_44 != 0 )
F_3 ( L_20 , V_44 ) ;
else
F_3 ( L_21 ) ;
}
return 0 ;
}
else
return - V_36 ;
V_43:
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
if ( ! V_9 [ V_16 ] . V_10 )
continue;
if ( V_9 [ V_16 ] . V_18 )
F_8 ( V_9 [ V_16 ] . V_18 , & V_19 ) ;
F_9 ( V_9 [ V_16 ] . V_10 ) ;
}
F_16 ( V_22 ) ;
return V_23 ;
}
static T_4 F_20 ( struct V_49 * V_49 , const char T_5 * V_50 , T_6 V_51 , T_7 * V_52 )
{
unsigned int V_53 ;
unsigned int V_54 ;
unsigned char V_55 ;
unsigned long V_56 ;
struct V_57 V_58 ;
struct V_59 V_60 ;
#ifdef F_21
int V_61 ;
#endif
F_22 ( V_62 , V_63 ) ;
if ( V_51 != sizeof( struct V_57 ) + sizeof( struct V_59 ) ) {
static int V_64 = 5 ;
if ( V_64 ) {
F_3 ( V_24 L_22 ,
V_51 , sizeof( struct V_57 ) + sizeof( struct V_59 ) ) ;
V_64 -- ;
}
return - V_65 ;
}
if( F_23 ( & V_58 , V_50 , sizeof( struct V_57 ) ) )
return - V_66 ;
if( F_23 ( & V_60 , & V_50 [ sizeof( struct V_57 ) ] ,
sizeof( struct V_59 ) ) )
return - V_66 ;
V_53 = V_58 . V_67 ;
V_55 = V_58 . V_68 ;
V_54 = V_53 - 1 ;
if( ( V_53 < 1 ) || ( V_53 > V_7 ) || ! V_9 [ V_54 ] . V_10 )
return - V_65 ;
#ifdef F_21
F_3 ( L_23 ,
V_54 + 1 ) ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_57 ) ; ) {
F_3 ( L_24 , V_61 , ( ( unsigned char * ) & V_58 ) [ V_61 ] ) ;
for ( V_61 ++ ; V_61 % 8 && V_61 < sizeof( struct V_57 ) ; V_61 ++ ) {
F_3 ( L_25 , ( ( unsigned char * ) & V_58 ) [ V_61 ] ) ;
}
}
F_3 ( L_26 ) ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_59 ) ; ) {
F_3 ( L_24 , V_61 , ( ( unsigned char * ) & V_60 ) [ V_61 ] ) ;
for ( V_61 ++ ; V_61 % 8 && V_61 < sizeof( struct V_59 ) ; V_61 ++ ) {
F_3 ( L_25 , ( ( unsigned char * ) & V_60 ) [ V_61 ] ) ;
}
}
F_3 ( L_21 ) ;
#endif
F_24 ( & V_9 [ V_54 ] . V_13 , V_56 ) ;
if( F_2 ( V_9 [ V_54 ] . V_10 + V_69 ) > 2 ) {
V_70 = F_2 ( V_9 [ V_54 ] . V_10 + V_48 ) ;
F_25 ( & V_9 [ V_54 ] . V_13 , V_56 ) ;
F_3 ( V_8 L_27 ,
V_54 , ( int ) F_2 ( V_9 [ V_54 ] . V_10 + V_69 ) ) ;
V_42 ++ ;
return - V_27 ;
}
F_26 ( V_71 ) ;
F_27 ( & V_9 [ V_54 ] . V_12 , & V_62 ) ;
while ( F_2 ( V_9 [ V_54 ] . V_10 + V_69 ) != 0 ) {
V_70 = F_2 ( V_9 [ V_54 ] . V_10 + V_48 ) ;
F_25 ( & V_9 [ V_54 ] . V_13 , V_56 ) ;
F_28 () ;
if ( F_29 ( V_63 ) ) {
F_30 ( & V_9 [ V_54 ] . V_12 ,
& V_62 ) ;
return - V_72 ;
}
F_24 ( & V_9 [ V_54 ] . V_13 , V_56 ) ;
F_26 ( V_71 ) ;
}
F_26 ( V_73 ) ;
F_30 ( & V_9 [ V_54 ] . V_12 , & V_62 ) ;
F_18 ( 1 , V_9 [ V_54 ] . V_10 + V_69 ) ;
{
unsigned char * V_74 = ( unsigned char * ) & V_60 ;
void T_1 * V_75 = V_9 [ V_54 ] . V_10 + V_76 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_59 ) ; V_61 ++ )
F_18 ( * ( V_74 ++ ) , V_75 ++ ) ;
}
F_18 ( 0x20 , V_9 [ V_54 ] . V_10 + V_77 ) ;
F_18 ( 0xff , V_9 [ V_54 ] . V_10 + V_78 ) ;
F_18 ( V_55 , V_9 [ V_54 ] . V_10 + V_79 ) ;
F_18 ( V_53 , V_9 [ V_54 ] . V_10 + V_80 ) ;
F_18 ( 2 , V_9 [ V_54 ] . V_10 + V_69 ) ;
F_18 ( 1 , V_9 [ V_54 ] . V_10 + V_33 ) ;
V_70 = F_2 ( V_9 [ V_54 ] . V_10 + V_48 ) ;
F_25 ( & V_9 [ V_54 ] . V_13 , V_56 ) ;
return 0 ;
}
static int F_31 ( int V_54 , char T_5 * V_50 ,
struct V_57 * V_58 , struct V_59 * V_59 )
{
void T_1 * V_74 = V_9 [ V_54 ] . V_10 + V_81 ;
unsigned char * V_75 = ( unsigned char * ) V_59 ;
#ifdef F_21
int V_61 ;
#endif
V_58 -> V_82 = F_2 ( V_9 [ V_54 ] . V_10 + V_83 ) ;
V_58 -> V_84 = F_2 ( V_9 [ V_54 ] . V_10 + V_6 ) ;
{
int V_61 ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_59 ) ; V_61 ++ )
* ( V_75 ++ ) = F_2 ( V_74 ++ ) ;
}
F_18 ( 1 , V_9 [ V_54 ] . V_10 + V_85 ) ;
F_18 ( 1 , V_9 [ V_54 ] . V_10 + V_86 ) ;
F_18 ( V_54 + 1 , V_9 [ V_54 ] . V_10 + V_87 ) ;
F_18 ( F_2 ( V_9 [ V_54 ] . V_10 + V_83 ) ,
V_9 [ V_54 ] . V_10 + V_88 ) ;
F_18 ( 2 , V_9 [ V_54 ] . V_10 + V_85 ) ;
F_18 ( 0 , V_9 [ V_54 ] . V_10 + V_89 ) ;
F_18 ( 2 , V_9 [ V_54 ] . V_10 + V_33 ) ;
V_70 = F_2 ( V_9 [ V_54 ] . V_10 + V_48 ) ;
#ifdef F_21
F_3 ( L_28 , V_53 ) ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_57 ) ; ) {
F_3 ( L_24 , V_61 , ( ( unsigned char * ) V_58 ) [ V_61 ] ) ;
for ( V_61 ++ ; V_61 % 8 && V_61 < sizeof( struct V_57 ) ; V_61 ++ ) {
F_3 ( L_25 , ( ( unsigned char * ) V_58 ) [ V_61 ] ) ;
}
}
F_3 ( L_26 ) ;
for ( V_61 = 0 ; V_61 < sizeof( struct V_59 ) ; ) {
F_3 ( L_24 , V_61 , ( ( unsigned char * ) V_59 ) [ V_61 ] ) ;
for ( V_61 ++ ; V_61 % 8 && V_61 < sizeof( struct V_59 ) ; V_61 ++ ) {
F_3 ( L_25 , ( ( unsigned char * ) V_59 ) [ V_61 ] ) ;
}
}
F_3 ( L_21 ) ;
#endif
return ( sizeof( struct V_57 ) + sizeof( struct V_59 ) ) ;
}
static T_4 F_32 ( struct V_49 * V_90 , char T_5 * V_50 , T_6 V_51 , T_7 * V_91 )
{
unsigned long V_56 ;
unsigned int V_16 ;
unsigned char V_92 ;
int V_23 = 0 ;
F_22 ( V_62 , V_63 ) ;
#ifdef F_21
int V_93 = 0 ;
#endif
if ( V_51 != sizeof( struct V_57 ) + sizeof( struct V_59 ) ) {
F_3 ( V_8 L_29 ,
V_51 , sizeof( struct V_57 ) + sizeof( struct V_59 ) ) ;
return - V_65 ;
}
while( 1 ) {
F_26 ( V_71 ) ;
F_27 ( & V_39 , & V_62 ) ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
if ( ! V_9 [ V_16 ] . V_10 )
continue;
F_24 ( & V_9 [ V_16 ] . V_13 , V_56 ) ;
V_92 = F_2 ( V_9 [ V_16 ] . V_10 + V_89 ) ;
if ( V_92 == 2 ) {
struct V_57 V_58 ;
struct V_59 V_59 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_23 = F_31 ( V_16 , V_50 , & V_58 , & V_59 ) ;
F_25 ( & V_9 [ V_16 ] . V_13 , V_56 ) ;
F_26 ( V_73 ) ;
F_30 ( & V_39 , & V_62 ) ;
if ( F_33 ( V_50 , & V_58 , sizeof( V_58 ) ) )
return - V_66 ;
if ( F_33 ( V_50 + sizeof( V_58 ) , & V_59 , sizeof( V_59 ) ) )
return - V_66 ;
return V_92 ;
}
if ( V_92 > 2 ) {
V_70 = F_2 ( V_9 [ V_16 ] . V_10 + V_48 ) ;
F_25 ( & V_9 [ V_16 ] . V_13 , V_56 ) ;
F_26 ( V_73 ) ;
F_30 ( & V_39 , & V_62 ) ;
F_3 ( V_8 L_30 ,
V_16 , ( int ) F_2 ( V_9 [ V_16 ] . V_10 + V_89 ) ) ;
V_42 ++ ;
return - V_27 ;
}
V_70 = F_2 ( V_9 [ V_16 ] . V_10 + V_48 ) ;
F_25 ( & V_9 [ V_16 ] . V_13 , V_56 ) ;
}
F_28 () ;
F_30 ( & V_39 , & V_62 ) ;
if ( F_29 ( V_63 ) )
return - V_72 ;
#ifdef F_21
if ( V_93 ++ > 2 ) {
F_3 ( V_94 L_31 , V_93 ) ;
}
#endif
}
}
static T_8 V_31 ( int V_95 , void * V_96 )
{
unsigned int V_16 ;
unsigned int V_97 ;
unsigned int V_98 ;
int V_99 = 0 ;
V_98 = 0 ;
do {
V_97 = 0 ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
if ( ! V_9 [ V_16 ] . V_10 )
continue;
F_34 ( & V_9 [ V_16 ] . V_13 ) ;
if( F_2 ( V_9 [ V_16 ] . V_10 + V_14 ) == 0 ) {
F_35 ( & V_9 [ V_16 ] . V_13 ) ;
continue;
}
V_99 = 1 ;
V_97 = 1 ;
F_18 ( 0 , V_9 [ V_16 ] . V_10 + V_14 ) ;
if ( F_2 ( V_9 [ V_16 ] . V_10 + V_89 ) > 2 ) {
F_3 ( V_8 L_32 ,
V_16 + 1 , ( int ) F_2 ( V_9 [ V_16 ] . V_10 + V_89 ) ) ;
V_42 ++ ;
}
if( ( F_2 ( V_9 [ V_16 ] . V_10 + V_69 ) > 2 ) &&
( F_2 ( V_9 [ V_16 ] . V_10 + V_69 ) != 6 ) ) {
F_3 ( V_8 L_33 ,
V_16 + 1 , ( int ) F_2 ( V_9 [ V_16 ] . V_10 + V_69 ) ) ;
V_42 ++ ;
}
if ( F_2 ( V_9 [ V_16 ] . V_10 + V_89 ) == 2 ) {
if ( F_36 ( & V_39 ) ) {
F_37 ( & V_39 ) ;
}
}
if ( F_2 ( V_9 [ V_16 ] . V_10 + V_69 ) == 0 ) {
if ( F_36 ( & V_9 [ V_16 ] . V_12 ) ) {
F_37 ( & V_9 [ V_16 ] . V_12 ) ;
}
}
V_70 = F_2 ( V_9 [ V_16 ] . V_10 + V_48 ) ;
if( F_2 ( V_9 [ V_16 ] . V_10 + V_14 ) ) {
F_35 ( & V_9 [ V_16 ] . V_13 ) ;
V_16 -- ;
} else {
F_35 ( & V_9 [ V_16 ] . V_13 ) ;
}
}
if ( V_97 )
V_98 = 0 ;
else
V_98 ++ ;
} while( V_98 < 2 );
return F_38 ( V_99 ) ;
}
static long F_39 ( struct V_49 * V_49 , unsigned int V_100 , unsigned long V_101 )
{
int V_16 ;
unsigned char V_54 ;
void T_1 * V_102 ;
int V_23 = 0 ;
volatile unsigned char V_4 ;
struct V_57 * V_103 ;
void T_5 * V_104 = ( void T_5 * ) V_101 ;
V_103 = F_40 ( V_104 , sizeof( struct V_57 ) ) ;
if ( F_41 ( V_103 ) )
return F_42 ( V_103 ) ;
F_43 ( & V_105 ) ;
V_54 = V_103 -> V_67 - 1 ;
if( V_100 != 6 && ( ( V_54 >= V_7 ) || ! V_9 [ V_54 ] . V_10 ) ) {
static int V_64 = 10 ;
if ( V_64 ) {
F_3 ( V_8 L_34 , ( int ) V_54 + 1 ) ;
V_64 -- ;
}
F_44 ( V_103 ) ;
F_45 ( & V_105 ) ;
return - V_65 ;
}
switch ( V_100 ) {
case 0 :
V_102 = V_9 [ V_54 ] . V_10 ;
for ( V_16 = 0 ; V_16 < sizeof( struct V_57 ) ; V_16 ++ )
( ( unsigned char * ) V_103 ) [ V_16 ] = F_2 ( V_102 ++ ) ;
if ( F_33 ( V_104 , V_103 , sizeof( struct V_57 ) ) )
V_23 = - V_66 ;
break;
case 1 :
V_102 = V_9 [ V_54 ] . V_10 + V_5 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
V_103 -> V_106 [ V_16 ] = F_2 ( V_102 ++ ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
V_103 -> V_107 [ V_16 ] = F_2 ( V_102 ++ ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
V_103 -> V_108 [ V_16 ] = F_2 ( V_102 ++ ) ;
V_102 = V_9 [ V_54 ] . V_10 + V_48 ;
V_103 -> V_109 = F_2 ( V_102 ) ;
V_102 = V_9 [ V_54 ] . V_10 + V_47 ;
for ( V_16 = 0 ; V_16 < 20 ; V_16 ++ )
V_103 -> V_110 [ V_16 ] = F_2 ( V_102 ++ ) ;
* ( int * ) & V_103 -> V_110 [ 20 ] =
( F_2 ( V_9 [ V_54 ] . V_10 + V_46 ) << 16 ) +
( F_2 ( V_9 [ V_54 ] . V_10 + V_46 + 1 ) << 8 ) +
( F_2 ( V_9 [ V_54 ] . V_10 + V_46 + 2 ) ) ;
if ( F_33 ( V_104 , V_103 , sizeof( struct V_57 ) ) )
V_23 = - V_66 ;
break;
case 2 :
V_102 = V_9 [ V_54 ] . V_10 + V_5 ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ )
F_18 ( 0xff , V_102 ++ ) ;
F_18 ( V_103 -> V_111 ,
V_9 [ V_54 ] . V_10 + V_69 ) ;
F_18 ( 1 , V_9 [ V_54 ] . V_10 + V_33 ) ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
if ( V_9 [ V_16 ] . V_10 ) {
V_4 = F_2 ( V_9 [ V_16 ] . V_10 + V_14 ) ;
}
}
break;
case 3 :
V_102 = V_9 [ V_54 ] . V_10 + V_79 ;
F_18 ( V_103 -> V_68 , V_102 ) ;
break;
case 4 :
V_102 = V_9 [ V_54 ] . V_10 + V_83 ;
V_103 -> V_82 = F_2 ( V_102 ++ ) ;
V_103 -> V_84 = F_2 ( V_102 ) ;
if ( F_33 ( V_104 , V_103 , sizeof( struct V_57 ) ) )
V_23 = - V_66 ;
break;
case 5 :
F_18 ( V_103 -> V_67 , V_9 [ V_54 ] . V_10 + V_6 ) ;
F_18 ( V_103 -> V_67 , V_9 [ V_54 ] . V_10 + V_80 ) ;
F_18 ( V_103 -> V_67 , V_9 [ V_54 ] . V_10 + V_87 ) ;
F_18 ( 4 , V_9 [ V_54 ] . V_10 + V_69 ) ;
F_18 ( 1 , V_9 [ V_54 ] . V_10 + V_33 ) ;
break;
case 6 :
F_3 ( V_24 L_35 ) ;
F_3 ( V_24 L_36 , ( int ) V_15 ) ;
F_3 ( V_24 L_37 , ( int ) V_34 ) ;
F_3 ( V_24 L_38 , ( int ) V_18 ) ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
int V_44 ;
char V_45 [ ( V_46 - V_47 ) + 1 ] ;
if ( ! V_9 [ V_16 ] . V_10 )
continue;
for ( V_44 = 0 ; V_44 < V_46 - V_47 ; V_44 ++ )
V_45 [ V_44 ] = F_2 ( V_9 [ V_16 ] . V_10 + V_47 + V_44 ) ;
V_45 [ V_44 ] = 0 ;
F_3 ( V_24 L_39 ,
V_16 + 1 ,
( int ) ( F_2 ( V_9 [ V_54 ] . V_10 + V_48 ) >> 4 ) ,
( int ) ( F_2 ( V_9 [ V_54 ] . V_10 + V_48 ) & 0xF ) ,
V_45 ) ;
V_44 = ( F_2 ( V_9 [ V_16 ] . V_10 + V_46 ) << 16 ) +
( F_2 ( V_9 [ V_16 ] . V_10 + V_46 + 1 ) << 8 ) +
( F_2 ( V_9 [ V_16 ] . V_10 + V_46 + 2 ) ) ;
if ( V_44 != 0 )
F_3 ( L_20 , V_44 ) ;
else
F_3 ( L_21 ) ;
}
if ( V_42 != 0 )
F_3 ( V_24 L_40 , V_42 ) ;
if ( V_41 != 0 )
F_3 ( V_24 L_41 , V_41 ) ;
if ( V_40 != 0 )
F_3 ( V_24 L_42 , V_40 ) ;
if ( F_36 ( & V_39 ) )
F_3 ( V_24 L_43 ) ;
for ( V_16 = 0 ; V_16 < V_7 ; V_16 ++ ) {
if ( V_9 [ V_16 ] . V_10 && F_36 ( & V_9 [ V_16 ] . V_12 ) )
F_3 ( V_24 L_44 , V_16 + 1 ) ;
}
break;
default:
V_23 = - V_112 ;
break;
}
V_70 = F_2 ( V_9 [ V_54 ] . V_10 + V_48 ) ;
F_44 ( V_103 ) ;
F_45 ( & V_105 ) ;
return 0 ;
}
