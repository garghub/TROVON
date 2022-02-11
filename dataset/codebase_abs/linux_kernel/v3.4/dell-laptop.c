static int F_1 ( const struct V_1 * V_2 )
{
V_3 = V_2 -> V_4 ;
return 1 ;
}
static void F_2 ( void )
{
F_3 ( & V_5 ) ;
memset ( V_6 , 0 , sizeof( struct V_7 ) ) ;
}
static void F_4 ( void )
{
F_5 ( & V_5 ) ;
}
static void T_1 F_6 ( const struct V_8 * V_9 )
{
int V_10 = ( V_9 -> V_11 - 11 ) / sizeof( struct V_12 ) - 1 ;
struct V_13 * V_14 =
F_7 ( V_9 , struct V_13 , V_15 ) ;
if ( V_9 -> V_11 < 17 )
return;
V_16 = V_14 -> V_17 ;
V_18 = V_14 -> V_19 ;
V_20 = F_8 ( V_20 , ( V_21 + V_10 ) *
sizeof( struct V_12 ) ,
V_22 ) ;
if ( ! V_20 )
return;
memcpy ( V_20 + V_21 , V_14 -> V_10 ,
sizeof( struct V_12 ) * V_10 ) ;
V_21 += V_10 ;
}
static void T_1 F_9 ( const struct V_8 * V_9 , void * V_23 )
{
switch ( V_9 -> type ) {
case 0xd4 :
case 0xd5 :
case 0xd6 :
break;
case 0xda :
F_6 ( V_9 ) ;
break;
}
}
static int F_10 ( int V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_21 ; V_25 ++ ) {
if ( V_20 [ V_25 ] . V_26 == V_24 )
return V_20 [ V_25 ] . V_27 ;
}
return - 1 ;
}
static struct V_7 *
F_11 ( struct V_7 * V_6 , int V_28 ,
int V_29 )
{
struct V_30 V_31 ;
V_31 . V_32 = V_33 ;
V_31 . V_34 = V_16 ;
V_31 . V_35 = V_18 ;
V_31 . V_36 = F_12 ( V_6 ) ;
V_31 . V_37 = 0x42534931 ;
V_6 -> V_28 = V_28 ;
V_6 -> V_29 = V_29 ;
F_13 ( & V_31 ) ;
return V_6 ;
}
static int F_14 ( void * V_38 , bool V_39 )
{
int V_40 = V_39 ? 1 : 0 ;
unsigned long V_41 = ( unsigned long ) V_38 ;
int V_42 = ( unsigned long ) V_38 - 1 ;
int V_43 = 0 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
if ( ( V_44 & F_15 ( V_42 ) ) &&
! ( V_6 -> V_45 [ 1 ] & F_15 ( 16 ) ) ) {
V_43 = - V_46 ;
goto V_47;
}
V_6 -> V_48 [ 0 ] = ( 1 | ( V_41 << 8 ) | ( V_40 << 16 ) ) ;
F_11 ( V_6 , 17 , 11 ) ;
V_47:
F_4 () ;
return V_43 ;
}
static void F_16 ( struct V_49 * V_49 , void * V_38 )
{
int V_50 ;
int V_51 = ( unsigned long ) V_38 + 16 ;
int V_42 = ( unsigned long ) V_38 - 1 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_50 = V_6 -> V_45 [ 1 ] ;
F_4 () ;
F_17 ( V_49 , ! ! ( V_50 & F_15 ( V_51 ) ) ) ;
if ( V_44 & ( F_15 ( V_42 ) ) )
F_18 ( V_49 , ! ( V_50 & F_15 ( 16 ) ) ) ;
}
static int F_19 ( struct V_52 * V_53 , void * V_38 )
{
int V_50 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_50 = V_6 -> V_45 [ 1 ] ;
F_4 () ;
F_20 ( V_53 , L_1 , V_50 ) ;
F_20 ( V_53 , L_2 ,
V_50 & F_15 ( 0 ) ) ;
F_20 ( V_53 , L_3 ,
( V_50 & F_15 ( 1 ) ) >> 1 ) ;
F_20 ( V_53 , L_4 ,
( V_50 & F_15 ( 2 ) ) >> 2 ) ;
F_20 ( V_53 , L_5 ,
( V_50 & F_15 ( 3 ) ) >> 3 ) ;
F_20 ( V_53 , L_6 ,
( V_50 & F_15 ( 4 ) ) >> 4 ) ;
F_20 ( V_53 , L_7 ,
( V_50 & F_15 ( 5 ) ) >> 5 ) ;
F_20 ( V_53 , L_8 ,
( V_50 & F_15 ( 8 ) ) >> 8 ) ;
F_20 ( V_53 , L_9 ,
( V_50 & F_15 ( 9 ) ) >> 9 ) ;
F_20 ( V_53 , L_10 ,
( V_50 & F_15 ( 10 ) ) >> 10 ) ;
F_20 ( V_53 , L_11 ,
( V_50 & F_15 ( 16 ) ) >> 16 ) ;
F_20 ( V_53 , L_12 ,
( V_50 & F_15 ( 17 ) ) >> 17 ) ;
F_20 ( V_53 , L_13 ,
( V_50 & F_15 ( 18 ) ) >> 18 ) ;
F_20 ( V_53 , L_14 ,
( V_50 & F_15 ( 19 ) ) >> 19 ) ;
F_20 ( V_53 , L_15 , V_44 ) ;
F_20 ( V_53 , L_16 ,
V_44 & F_15 ( 0 ) ) ;
F_20 ( V_53 , L_17 ,
( V_44 & F_15 ( 1 ) ) >> 1 ) ;
F_20 ( V_53 , L_18 ,
( V_44 & F_15 ( 2 ) ) >> 2 ) ;
F_20 ( V_53 , L_19 ,
( V_44 & F_15 ( 7 ) ) >> 7 ) ;
F_20 ( V_53 , L_20 ,
( V_44 & F_15 ( 8 ) ) >> 8 ) ;
F_20 ( V_53 , L_21 ,
( V_44 & F_15 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_21 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_22 ( V_55 , F_19 , V_54 -> V_56 ) ;
}
static void F_23 ( struct V_57 * V_58 )
{
if ( V_59 )
F_16 ( V_59 , ( void * ) 1 ) ;
if ( V_60 )
F_16 ( V_60 , ( void * ) 2 ) ;
if ( V_61 )
F_16 ( V_61 , ( void * ) 3 ) ;
}
static int T_1 F_24 ( void )
{
int V_50 ;
int V_43 ;
if ( F_25 ( V_62 ) ) {
F_26 ( L_22 ) ;
return 0 ;
}
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_50 = V_6 -> V_45 [ 1 ] ;
V_6 -> V_48 [ 0 ] = 0x2 ;
F_11 ( V_6 , 17 , 11 ) ;
V_44 = V_6 -> V_45 [ 1 ] ;
F_4 () ;
if ( ( V_50 & ( 1 << 2 | 1 << 8 ) ) == ( 1 << 2 | 1 << 8 ) ) {
V_59 = F_27 ( L_23 , & V_63 -> V_64 ,
V_65 ,
& V_66 , ( void * ) 1 ) ;
if ( ! V_59 ) {
V_43 = - V_67 ;
goto V_68;
}
V_43 = F_28 ( V_59 ) ;
if ( V_43 )
goto V_68;
}
if ( ( V_50 & ( 1 << 3 | 1 << 9 ) ) == ( 1 << 3 | 1 << 9 ) ) {
V_60 = F_27 ( L_24 ,
& V_63 -> V_64 ,
V_69 ,
& V_66 , ( void * ) 2 ) ;
if ( ! V_60 ) {
V_43 = - V_67 ;
goto V_70;
}
V_43 = F_28 ( V_60 ) ;
if ( V_43 )
goto V_70;
}
if ( ( V_50 & ( 1 << 4 | 1 << 10 ) ) == ( 1 << 4 | 1 << 10 ) ) {
V_61 = F_27 ( L_25 ,
& V_63 -> V_64 ,
V_71 ,
& V_66 , ( void * ) 3 ) ;
if ( ! V_61 ) {
V_43 = - V_67 ;
goto V_72;
}
V_43 = F_28 ( V_61 ) ;
if ( V_43 )
goto V_72;
}
return 0 ;
V_72:
F_29 ( V_61 ) ;
if ( V_60 )
F_30 ( V_60 ) ;
V_70:
F_29 ( V_60 ) ;
if ( V_59 )
F_30 ( V_59 ) ;
V_68:
F_29 ( V_59 ) ;
return V_43 ;
}
static void F_31 ( void )
{
if ( V_59 ) {
F_30 ( V_59 ) ;
F_29 ( V_59 ) ;
}
if ( V_60 ) {
F_30 ( V_60 ) ;
F_29 ( V_60 ) ;
}
if ( V_61 ) {
F_30 ( V_61 ) ;
F_29 ( V_61 ) ;
}
}
static int F_32 ( struct V_73 * V_74 )
{
int V_43 = 0 ;
F_2 () ;
V_6 -> V_48 [ 0 ] = F_10 ( V_75 ) ;
V_6 -> V_48 [ 1 ] = V_74 -> V_76 . V_77 ;
if ( V_6 -> V_48 [ 0 ] == - 1 ) {
V_43 = - V_78 ;
goto V_47;
}
if ( F_33 () > 0 )
F_11 ( V_6 , 1 , 2 ) ;
else
F_11 ( V_6 , 1 , 1 ) ;
V_47:
F_4 () ;
return 0 ;
}
static int F_34 ( struct V_73 * V_74 )
{
int V_43 = 0 ;
F_2 () ;
V_6 -> V_48 [ 0 ] = F_10 ( V_75 ) ;
if ( V_6 -> V_48 [ 0 ] == - 1 ) {
V_43 = - V_78 ;
goto V_47;
}
if ( F_33 () > 0 )
F_11 ( V_6 , 0 , 2 ) ;
else
F_11 ( V_6 , 0 , 1 ) ;
V_43 = V_6 -> V_45 [ 1 ] ;
V_47:
F_4 () ;
return V_43 ;
}
static void F_35 ( void )
{
int V_31 = 0x97 ;
char V_38 = 1 ;
F_36 ( & V_38 , V_31 | 1 << 12 ) ;
}
static void F_37 ( void )
{
int V_31 = 0x97 ;
char V_38 = 2 ;
F_36 ( & V_38 , V_31 | 1 << 12 ) ;
}
static void F_38 ( struct V_79 * V_80 ,
enum V_81 V_82 )
{
if ( V_82 > 0 )
F_35 () ;
else
F_37 () ;
}
static int T_2 F_39 ( struct V_83 * V_64 )
{
return F_40 ( V_64 , & V_84 ) ;
}
static void F_41 ( void )
{
F_42 ( & V_84 ) ;
}
static bool F_43 ( unsigned char V_38 , unsigned char V_85 ,
struct V_86 * V_87 )
{
static bool V_88 ;
if ( V_85 & 0x20 )
return false ;
if ( F_44 ( V_38 == 0xe0 ) ) {
V_88 = true ;
return false ;
} else if ( F_44 ( V_88 ) ) {
switch ( V_38 ) {
case 0x8 :
F_45 ( & V_89 ,
F_46 ( V_90 ) ) ;
break;
}
V_88 = false ;
}
return false ;
}
static int T_1 F_47 ( void )
{
int V_91 = 0 ;
int V_43 ;
if ( ! F_25 ( V_92 ) )
return - V_78 ;
V_3 = NULL ;
F_25 ( V_93 ) ;
F_48 ( F_9 , NULL ) ;
if ( ! V_20 ) {
F_26 ( L_26 ) ;
return - V_78 ;
}
V_43 = F_49 ( & V_94 ) ;
if ( V_43 )
goto V_95;
V_63 = F_50 ( L_27 , - 1 ) ;
if ( ! V_63 ) {
V_43 = - V_67 ;
goto V_96;
}
V_43 = F_51 ( V_63 ) ;
if ( V_43 )
goto V_97;
V_98 = F_52 ( V_22 | V_99 ) ;
if ( ! V_98 )
goto V_100;
V_6 = F_53 ( V_98 ) ;
V_43 = F_24 () ;
if ( V_43 ) {
F_54 ( L_28 ) ;
goto V_101;
}
V_43 = F_55 ( F_43 ) ;
if ( V_43 ) {
F_54 ( L_29 ) ;
goto V_102;
}
if ( V_3 && V_3 -> V_84 )
F_39 ( & V_63 -> V_64 ) ;
V_103 = F_56 ( L_30 , NULL ) ;
if ( V_103 != NULL )
F_57 ( L_31 , 0444 , V_103 , NULL ,
& V_104 ) ;
#ifdef F_58
if ( F_59 () )
return 0 ;
#endif
F_2 () ;
V_6 -> V_48 [ 0 ] = F_10 ( V_75 ) ;
if ( V_6 -> V_48 [ 0 ] != - 1 ) {
F_11 ( V_6 , 0 , 2 ) ;
V_91 = V_6 -> V_45 [ 3 ] ;
}
F_4 () ;
if ( V_91 ) {
struct V_105 V_76 ;
memset ( & V_76 , 0 , sizeof( struct V_105 ) ) ;
V_76 . type = V_106 ;
V_76 . V_107 = V_91 ;
V_108 = F_60 ( L_32 ,
& V_63 -> V_64 ,
NULL ,
& V_109 ,
& V_76 ) ;
if ( F_61 ( V_108 ) ) {
V_43 = F_62 ( V_108 ) ;
V_108 = NULL ;
goto V_110;
}
V_108 -> V_76 . V_77 =
F_34 ( V_108 ) ;
F_63 ( V_108 ) ;
}
return 0 ;
V_110:
F_64 ( F_43 ) ;
F_65 ( & V_89 ) ;
V_102:
F_31 () ;
V_101:
F_66 ( ( unsigned long ) V_98 ) ;
V_100:
F_67 ( V_63 ) ;
V_97:
F_68 ( V_63 ) ;
V_96:
F_69 ( & V_94 ) ;
V_95:
F_70 ( V_20 ) ;
return V_43 ;
}
static void T_3 F_71 ( void )
{
F_72 ( V_103 ) ;
if ( V_3 && V_3 -> V_84 )
F_41 () ;
F_64 ( F_43 ) ;
F_65 ( & V_89 ) ;
F_73 ( V_108 ) ;
F_31 () ;
if ( V_63 ) {
F_74 ( V_63 ) ;
F_69 ( & V_94 ) ;
}
F_70 ( V_20 ) ;
F_66 ( ( unsigned long ) V_6 ) ;
}
