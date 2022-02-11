static int T_1 F_1 ( const struct V_1 * V_2 )
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
struct V_12 * V_13 ;
struct V_14 * V_15 =
F_7 ( V_9 , struct V_14 , V_16 ) ;
if ( V_9 -> V_11 < 17 )
return;
V_17 = V_15 -> V_18 ;
V_19 = V_15 -> V_20 ;
V_13 = F_8 ( V_21 , ( V_22 + V_10 ) *
sizeof( struct V_12 ) ,
V_23 ) ;
if ( ! V_13 )
return;
V_21 = V_13 ;
memcpy ( V_21 + V_22 , V_15 -> V_10 ,
sizeof( struct V_12 ) * V_10 ) ;
V_22 += V_10 ;
}
static void T_1 F_9 ( const struct V_8 * V_9 , void * V_24 )
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
static int F_10 ( int V_25 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
if ( V_21 [ V_26 ] . V_27 == V_25 )
return V_21 [ V_26 ] . V_28 ;
}
return - 1 ;
}
static struct V_7 *
F_11 ( struct V_7 * V_6 , int V_29 ,
int V_30 )
{
struct V_31 V_32 ;
V_32 . V_33 = V_34 ;
V_32 . V_35 = V_17 ;
V_32 . V_36 = V_19 ;
V_32 . V_37 = F_12 ( V_6 ) ;
V_32 . V_38 = 0x42534931 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_30 = V_30 ;
F_13 ( & V_32 ) ;
return V_6 ;
}
static int F_14 ( void * V_39 , bool V_40 )
{
int V_41 = V_40 ? 1 : 0 ;
unsigned long V_42 = ( unsigned long ) V_39 ;
int V_43 = ( unsigned long ) V_39 - 1 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
if ( ( V_44 & F_15 ( V_43 ) ) &&
! ( V_6 -> V_45 [ 1 ] & F_15 ( 16 ) ) )
V_41 = 1 ;
V_6 -> V_46 [ 0 ] = ( 1 | ( V_42 << 8 ) | ( V_41 << 16 ) ) ;
F_11 ( V_6 , 17 , 11 ) ;
F_4 () ;
return 0 ;
}
static void F_16 ( struct V_47 * V_47 , int V_42 ,
int V_48 )
{
if ( V_48 & F_15 ( 0 ) ) {
int V_49 = F_17 ( V_47 ) ;
V_6 -> V_46 [ 0 ] = ( 1 | ( V_42 << 8 ) | ( V_49 << 16 ) ) ;
F_11 ( V_6 , 17 , 11 ) ;
} else {
F_18 ( V_47 , ! ! ( V_48 & F_15 ( V_42 + 16 ) ) ) ;
}
}
static void F_19 ( struct V_47 * V_47 , int V_42 ,
int V_48 )
{
if ( V_44 & ( F_15 ( V_42 - 1 ) ) )
F_20 ( V_47 , ! ( V_48 & F_15 ( 16 ) ) ) ;
}
static void F_21 ( struct V_47 * V_47 , void * V_39 )
{
int V_48 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_48 = V_6 -> V_45 [ 1 ] ;
F_19 ( V_47 , ( unsigned long ) V_39 , V_48 ) ;
F_4 () ;
}
static int F_22 ( struct V_50 * V_51 , void * V_39 )
{
int V_48 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_48 = V_6 -> V_45 [ 1 ] ;
F_4 () ;
F_23 ( V_51 , L_1 , V_48 ) ;
F_23 ( V_51 , L_2 ,
V_48 & F_15 ( 0 ) ) ;
F_23 ( V_51 , L_3 ,
( V_48 & F_15 ( 1 ) ) >> 1 ) ;
F_23 ( V_51 , L_4 ,
( V_48 & F_15 ( 2 ) ) >> 2 ) ;
F_23 ( V_51 , L_5 ,
( V_48 & F_15 ( 3 ) ) >> 3 ) ;
F_23 ( V_51 , L_6 ,
( V_48 & F_15 ( 4 ) ) >> 4 ) ;
F_23 ( V_51 , L_7 ,
( V_48 & F_15 ( 5 ) ) >> 5 ) ;
F_23 ( V_51 , L_8 ,
( V_48 & F_15 ( 8 ) ) >> 8 ) ;
F_23 ( V_51 , L_9 ,
( V_48 & F_15 ( 9 ) ) >> 9 ) ;
F_23 ( V_51 , L_10 ,
( V_48 & F_15 ( 10 ) ) >> 10 ) ;
F_23 ( V_51 , L_11 ,
( V_48 & F_15 ( 16 ) ) >> 16 ) ;
F_23 ( V_51 , L_12 ,
( V_48 & F_15 ( 17 ) ) >> 17 ) ;
F_23 ( V_51 , L_13 ,
( V_48 & F_15 ( 18 ) ) >> 18 ) ;
F_23 ( V_51 , L_14 ,
( V_48 & F_15 ( 19 ) ) >> 19 ) ;
F_23 ( V_51 , L_15 , V_44 ) ;
F_23 ( V_51 , L_16 ,
V_44 & F_15 ( 0 ) ) ;
F_23 ( V_51 , L_17 ,
( V_44 & F_15 ( 1 ) ) >> 1 ) ;
F_23 ( V_51 , L_18 ,
( V_44 & F_15 ( 2 ) ) >> 2 ) ;
F_23 ( V_51 , L_19 ,
( V_44 & F_15 ( 7 ) ) >> 7 ) ;
F_23 ( V_51 , L_20 ,
( V_44 & F_15 ( 8 ) ) >> 8 ) ;
F_23 ( V_51 , L_21 ,
( V_44 & F_15 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_24 ( struct V_52 * V_52 , struct V_53 * V_53 )
{
return F_25 ( V_53 , F_22 , V_52 -> V_54 ) ;
}
static void F_26 ( struct V_55 * V_56 )
{
int V_48 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_48 = V_6 -> V_45 [ 1 ] ;
if ( V_57 ) {
F_19 ( V_57 , 1 , V_48 ) ;
F_16 ( V_57 , 1 , V_48 ) ;
}
if ( V_58 ) {
F_19 ( V_58 , 2 , V_48 ) ;
F_16 ( V_58 , 2 , V_48 ) ;
}
if ( V_59 ) {
F_19 ( V_59 , 3 , V_48 ) ;
F_16 ( V_59 , 3 , V_48 ) ;
}
F_4 () ;
}
static bool F_27 ( unsigned char V_39 , unsigned char V_60 ,
struct V_61 * V_62 )
{
static bool V_63 ;
if ( V_60 & V_64 )
return false ;
if ( F_28 ( V_39 == 0xe0 ) ) {
V_63 = true ;
return false ;
} else if ( F_28 ( V_63 ) ) {
switch ( V_39 ) {
case 0x8 :
F_29 ( & V_65 ,
F_30 ( V_66 / 4 ) ) ;
break;
}
V_63 = false ;
}
return false ;
}
static int T_1 F_31 ( void )
{
int V_48 , V_67 , V_68 ;
const char * V_69 ;
V_68 = 0 ;
V_69 = F_32 ( V_70 ) ;
if ( V_69 && ( strncmp ( V_69 , L_22 , 8 ) == 0 ||
strncmp ( V_69 , L_23 , 9 ) == 0 ) )
V_68 = 1 ;
if ( ! V_71 && ! V_68 )
return 0 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_48 = V_6 -> V_45 [ 1 ] ;
V_6 -> V_46 [ 0 ] = 0x2 ;
F_11 ( V_6 , 17 , 11 ) ;
V_44 = V_6 -> V_45 [ 1 ] ;
F_4 () ;
if ( ! ( V_48 & F_15 ( 0 ) ) ) {
if ( V_71 ) {
V_44 &= ~ 7 ;
} else {
return 0 ;
}
}
if ( ( V_48 & ( 1 << 2 | 1 << 8 ) ) == ( 1 << 2 | 1 << 8 ) ) {
V_57 = F_33 ( L_24 , & V_72 -> V_73 ,
V_74 ,
& V_75 , ( void * ) 1 ) ;
if ( ! V_57 ) {
V_67 = - V_76 ;
goto V_77;
}
V_67 = F_34 ( V_57 ) ;
if ( V_67 )
goto V_77;
}
if ( ( V_48 & ( 1 << 3 | 1 << 9 ) ) == ( 1 << 3 | 1 << 9 ) ) {
V_58 = F_33 ( L_25 ,
& V_72 -> V_73 ,
V_78 ,
& V_75 , ( void * ) 2 ) ;
if ( ! V_58 ) {
V_67 = - V_76 ;
goto V_79;
}
V_67 = F_34 ( V_58 ) ;
if ( V_67 )
goto V_79;
}
if ( ( V_48 & ( 1 << 4 | 1 << 10 ) ) == ( 1 << 4 | 1 << 10 ) ) {
V_59 = F_33 ( L_26 ,
& V_72 -> V_73 ,
V_80 ,
& V_75 , ( void * ) 3 ) ;
if ( ! V_59 ) {
V_67 = - V_76 ;
goto V_81;
}
V_67 = F_34 ( V_59 ) ;
if ( V_67 )
goto V_81;
}
V_67 = F_35 ( F_27 ) ;
if ( V_67 ) {
F_36 ( L_27 ) ;
goto V_82;
}
return 0 ;
V_82:
if ( V_59 )
F_37 ( V_59 ) ;
V_81:
F_38 ( V_59 ) ;
if ( V_58 )
F_37 ( V_58 ) ;
V_79:
F_38 ( V_58 ) ;
if ( V_57 )
F_37 ( V_57 ) ;
V_77:
F_38 ( V_57 ) ;
return V_67 ;
}
static void F_39 ( void )
{
if ( V_57 ) {
F_37 ( V_57 ) ;
F_38 ( V_57 ) ;
}
if ( V_58 ) {
F_37 ( V_58 ) ;
F_38 ( V_58 ) ;
}
if ( V_59 ) {
F_37 ( V_59 ) ;
F_38 ( V_59 ) ;
}
}
static int F_40 ( struct V_83 * V_84 )
{
int V_67 = 0 ;
F_2 () ;
V_6 -> V_46 [ 0 ] = F_10 ( V_85 ) ;
V_6 -> V_46 [ 1 ] = V_84 -> V_86 . V_87 ;
if ( V_6 -> V_46 [ 0 ] == - 1 ) {
V_67 = - V_88 ;
goto V_89;
}
if ( F_41 () > 0 )
F_11 ( V_6 , 1 , 2 ) ;
else
F_11 ( V_6 , 1 , 1 ) ;
V_89:
F_4 () ;
return V_67 ;
}
static int F_42 ( struct V_83 * V_84 )
{
int V_67 = 0 ;
F_2 () ;
V_6 -> V_46 [ 0 ] = F_10 ( V_85 ) ;
if ( V_6 -> V_46 [ 0 ] == - 1 ) {
V_67 = - V_88 ;
goto V_89;
}
if ( F_41 () > 0 )
F_11 ( V_6 , 0 , 2 ) ;
else
F_11 ( V_6 , 0 , 1 ) ;
V_67 = V_6 -> V_45 [ 1 ] ;
V_89:
F_4 () ;
return V_67 ;
}
static void F_43 ( void )
{
int V_32 = 0x97 ;
char V_39 = 1 ;
F_44 ( & V_39 , V_32 | 1 << 12 ) ;
}
static void F_45 ( void )
{
int V_32 = 0x97 ;
char V_39 = 2 ;
F_44 ( & V_39 , V_32 | 1 << 12 ) ;
}
static void F_46 ( struct V_90 * V_91 ,
enum V_92 V_93 )
{
if ( V_93 > 0 )
F_43 () ;
else
F_45 () ;
}
static int T_1 F_47 ( struct V_94 * V_73 )
{
return F_48 ( V_73 , & V_95 ) ;
}
static void F_49 ( void )
{
F_50 ( & V_95 ) ;
}
static int T_1 F_51 ( void )
{
int V_96 = 0 ;
int V_67 ;
if ( ! F_52 ( V_97 ) )
return - V_88 ;
V_3 = NULL ;
F_52 ( V_98 ) ;
F_53 ( F_9 , NULL ) ;
if ( ! V_21 ) {
F_54 ( L_28 ) ;
return - V_88 ;
}
V_67 = F_55 ( & V_99 ) ;
if ( V_67 )
goto V_100;
V_72 = F_56 ( L_29 , - 1 ) ;
if ( ! V_72 ) {
V_67 = - V_76 ;
goto V_101;
}
V_67 = F_57 ( V_72 ) ;
if ( V_67 )
goto V_102;
V_103 = F_58 ( V_23 | V_104 ) ;
if ( ! V_103 ) {
V_67 = - V_76 ;
goto V_105;
}
V_6 = F_59 ( V_103 ) ;
V_67 = F_31 () ;
if ( V_67 ) {
F_36 ( L_30 ) ;
goto V_106;
}
if ( V_3 && V_3 -> V_95 )
F_47 ( & V_72 -> V_73 ) ;
V_107 = F_60 ( L_31 , NULL ) ;
if ( V_107 != NULL )
F_61 ( L_32 , 0444 , V_107 , NULL ,
& V_108 ) ;
#ifdef F_62
if ( F_63 () )
return 0 ;
#endif
F_2 () ;
V_6 -> V_46 [ 0 ] = F_10 ( V_85 ) ;
if ( V_6 -> V_46 [ 0 ] != - 1 ) {
F_11 ( V_6 , 0 , 2 ) ;
V_96 = V_6 -> V_45 [ 3 ] ;
}
F_4 () ;
if ( V_96 ) {
struct V_109 V_86 ;
memset ( & V_86 , 0 , sizeof( struct V_109 ) ) ;
V_86 . type = V_110 ;
V_86 . V_111 = V_96 ;
V_112 = F_64 ( L_33 ,
& V_72 -> V_73 ,
NULL ,
& V_113 ,
& V_86 ) ;
if ( F_65 ( V_112 ) ) {
V_67 = F_66 ( V_112 ) ;
V_112 = NULL ;
goto V_114;
}
V_112 -> V_86 . V_87 =
F_42 ( V_112 ) ;
F_67 ( V_112 ) ;
}
return 0 ;
V_114:
F_68 ( F_27 ) ;
F_69 ( & V_65 ) ;
F_39 () ;
V_106:
F_70 ( ( unsigned long ) V_103 ) ;
V_105:
F_71 ( V_72 ) ;
V_102:
F_72 ( V_72 ) ;
V_101:
F_73 ( & V_99 ) ;
V_100:
F_74 ( V_21 ) ;
return V_67 ;
}
static void T_2 F_75 ( void )
{
F_76 ( V_107 ) ;
if ( V_3 && V_3 -> V_95 )
F_49 () ;
F_68 ( F_27 ) ;
F_69 ( & V_65 ) ;
F_77 ( V_112 ) ;
F_39 () ;
if ( V_72 ) {
F_78 ( V_72 ) ;
F_73 ( & V_99 ) ;
}
F_74 ( V_21 ) ;
F_70 ( ( unsigned long ) V_6 ) ;
}
