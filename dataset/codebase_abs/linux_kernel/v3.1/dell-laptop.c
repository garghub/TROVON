static void F_1 ( void )
{
F_2 ( & V_1 ) ;
memset ( V_2 , 0 , sizeof( struct V_3 ) ) ;
}
static void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void T_1 F_5 ( const struct V_4 * V_5 )
{
int V_6 = ( V_5 -> V_7 - 11 ) / sizeof( struct V_8 ) - 1 ;
struct V_9 * V_10 =
F_6 ( V_5 , struct V_9 , V_11 ) ;
if ( V_5 -> V_7 < 17 )
return;
V_12 = V_10 -> V_13 ;
V_14 = V_10 -> V_15 ;
V_16 = F_7 ( V_16 , ( V_17 + V_6 ) *
sizeof( struct V_8 ) ,
V_18 ) ;
if ( ! V_16 )
return;
memcpy ( V_16 + V_17 , V_10 -> V_6 ,
sizeof( struct V_8 ) * V_6 ) ;
V_17 += V_6 ;
}
static void T_1 F_8 ( const struct V_4 * V_5 , void * V_19 )
{
switch ( V_5 -> type ) {
case 0xd4 :
break;
case 0xd5 :
break;
case 0xd6 :
break;
case 0xda :
F_5 ( V_5 ) ;
break;
}
}
static int F_9 ( int V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_17 ; V_21 ++ ) {
if ( V_16 [ V_21 ] . V_22 == V_20 )
return V_16 [ V_21 ] . V_23 ;
}
return - 1 ;
}
static struct V_3 *
F_10 ( struct V_3 * V_2 , int V_24 ,
int V_25 )
{
struct V_26 V_27 ;
V_27 . V_28 = V_29 ;
V_27 . V_30 = V_12 ;
V_27 . V_31 = V_14 ;
V_27 . V_32 = F_11 ( V_2 ) ;
V_27 . V_33 = 0x42534931 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_25 ;
F_12 ( & V_27 ) ;
return V_2 ;
}
static int F_13 ( void * V_34 , bool V_35 )
{
int V_36 = V_35 ? 1 : 0 ;
unsigned long V_37 = ( unsigned long ) V_34 ;
int V_38 = ( unsigned long ) V_34 - 1 ;
int V_39 = 0 ;
F_1 () ;
F_10 ( V_2 , 17 , 11 ) ;
if ( ( V_40 & F_14 ( V_38 ) ) &&
! ( V_2 -> V_41 [ 1 ] & F_14 ( 16 ) ) ) {
V_39 = - V_42 ;
goto V_43;
}
V_2 -> V_44 [ 0 ] = ( 1 | ( V_37 << 8 ) | ( V_36 << 16 ) ) ;
F_10 ( V_2 , 17 , 11 ) ;
V_43:
F_3 () ;
return V_39 ;
}
static void F_15 ( struct V_45 * V_45 , void * V_34 )
{
int V_46 ;
int V_47 = ( unsigned long ) V_34 + 16 ;
int V_38 = ( unsigned long ) V_34 - 1 ;
F_1 () ;
F_10 ( V_2 , 17 , 11 ) ;
V_46 = V_2 -> V_41 [ 1 ] ;
F_3 () ;
F_16 ( V_45 , ! ! ( V_46 & F_14 ( V_47 ) ) ) ;
if ( V_40 & ( F_14 ( V_38 ) ) )
F_17 ( V_45 , ! ( V_46 & F_14 ( 16 ) ) ) ;
}
static int F_18 ( struct V_48 * V_49 , void * V_34 )
{
int V_46 ;
F_1 () ;
F_10 ( V_2 , 17 , 11 ) ;
V_46 = V_2 -> V_41 [ 1 ] ;
F_3 () ;
F_19 ( V_49 , L_1 , V_46 ) ;
F_19 ( V_49 , L_2 ,
V_46 & F_14 ( 0 ) ) ;
F_19 ( V_49 , L_3 ,
( V_46 & F_14 ( 1 ) ) >> 1 ) ;
F_19 ( V_49 , L_4 ,
( V_46 & F_14 ( 2 ) ) >> 2 ) ;
F_19 ( V_49 , L_5 ,
( V_46 & F_14 ( 3 ) ) >> 3 ) ;
F_19 ( V_49 , L_6 ,
( V_46 & F_14 ( 4 ) ) >> 4 ) ;
F_19 ( V_49 , L_7 ,
( V_46 & F_14 ( 5 ) ) >> 5 ) ;
F_19 ( V_49 , L_8 ,
( V_46 & F_14 ( 8 ) ) >> 8 ) ;
F_19 ( V_49 , L_9 ,
( V_46 & F_14 ( 9 ) ) >> 9 ) ;
F_19 ( V_49 , L_10 ,
( V_46 & F_14 ( 10 ) ) >> 10 ) ;
F_19 ( V_49 , L_11 ,
( V_46 & F_14 ( 16 ) ) >> 16 ) ;
F_19 ( V_49 , L_12 ,
( V_46 & F_14 ( 17 ) ) >> 17 ) ;
F_19 ( V_49 , L_13 ,
( V_46 & F_14 ( 18 ) ) >> 18 ) ;
F_19 ( V_49 , L_14 ,
( V_46 & F_14 ( 19 ) ) >> 19 ) ;
F_19 ( V_49 , L_15 , V_40 ) ;
F_19 ( V_49 , L_16 ,
V_40 & F_14 ( 0 ) ) ;
F_19 ( V_49 , L_17 ,
( V_40 & F_14 ( 1 ) ) >> 1 ) ;
F_19 ( V_49 , L_18 ,
( V_40 & F_14 ( 2 ) ) >> 2 ) ;
F_19 ( V_49 , L_19 ,
( V_40 & F_14 ( 7 ) ) >> 7 ) ;
F_19 ( V_49 , L_20 ,
( V_40 & F_14 ( 8 ) ) >> 8 ) ;
F_19 ( V_49 , L_21 ,
( V_40 & F_14 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_20 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return F_21 ( V_51 , F_18 , V_50 -> V_52 ) ;
}
static void F_22 ( struct V_53 * V_54 )
{
if ( V_55 )
F_15 ( V_55 , ( void * ) 1 ) ;
if ( V_56 )
F_15 ( V_56 , ( void * ) 2 ) ;
if ( V_57 )
F_15 ( V_57 , ( void * ) 3 ) ;
}
static int T_1 F_23 ( void )
{
int V_46 ;
int V_39 ;
if ( F_24 ( V_58 ) ) {
F_25 ( L_22 ) ;
return 0 ;
}
F_1 () ;
F_10 ( V_2 , 17 , 11 ) ;
V_46 = V_2 -> V_41 [ 1 ] ;
V_2 -> V_44 [ 0 ] = 0x2 ;
F_10 ( V_2 , 17 , 11 ) ;
V_40 = V_2 -> V_41 [ 1 ] ;
F_3 () ;
if ( ( V_46 & ( 1 << 2 | 1 << 8 ) ) == ( 1 << 2 | 1 << 8 ) ) {
V_55 = F_26 ( L_23 , & V_59 -> V_60 ,
V_61 ,
& V_62 , ( void * ) 1 ) ;
if ( ! V_55 ) {
V_39 = - V_63 ;
goto V_64;
}
V_39 = F_27 ( V_55 ) ;
if ( V_39 )
goto V_64;
}
if ( ( V_46 & ( 1 << 3 | 1 << 9 ) ) == ( 1 << 3 | 1 << 9 ) ) {
V_56 = F_26 ( L_24 ,
& V_59 -> V_60 ,
V_65 ,
& V_62 , ( void * ) 2 ) ;
if ( ! V_56 ) {
V_39 = - V_63 ;
goto V_66;
}
V_39 = F_27 ( V_56 ) ;
if ( V_39 )
goto V_66;
}
if ( ( V_46 & ( 1 << 4 | 1 << 10 ) ) == ( 1 << 4 | 1 << 10 ) ) {
V_57 = F_26 ( L_25 ,
& V_59 -> V_60 ,
V_67 ,
& V_62 , ( void * ) 3 ) ;
if ( ! V_57 ) {
V_39 = - V_63 ;
goto V_68;
}
V_39 = F_27 ( V_57 ) ;
if ( V_39 )
goto V_68;
}
return 0 ;
V_68:
F_28 ( V_57 ) ;
if ( V_56 )
F_29 ( V_56 ) ;
V_66:
F_28 ( V_56 ) ;
if ( V_55 )
F_29 ( V_55 ) ;
V_64:
F_28 ( V_55 ) ;
return V_39 ;
}
static void F_30 ( void )
{
if ( V_55 ) {
F_29 ( V_55 ) ;
F_28 ( V_55 ) ;
}
if ( V_56 ) {
F_29 ( V_56 ) ;
F_28 ( V_56 ) ;
}
if ( V_57 ) {
F_29 ( V_57 ) ;
F_28 ( V_57 ) ;
}
}
static int F_31 ( struct V_69 * V_70 )
{
int V_39 = 0 ;
F_1 () ;
V_2 -> V_44 [ 0 ] = F_9 ( V_71 ) ;
V_2 -> V_44 [ 1 ] = V_70 -> V_72 . V_73 ;
if ( V_2 -> V_44 [ 0 ] == - 1 ) {
V_39 = - V_74 ;
goto V_43;
}
if ( F_32 () > 0 )
F_10 ( V_2 , 1 , 2 ) ;
else
F_10 ( V_2 , 1 , 1 ) ;
V_43:
F_3 () ;
return 0 ;
}
static int F_33 ( struct V_69 * V_70 )
{
int V_39 = 0 ;
F_1 () ;
V_2 -> V_44 [ 0 ] = F_9 ( V_71 ) ;
if ( V_2 -> V_44 [ 0 ] == - 1 ) {
V_39 = - V_74 ;
goto V_43;
}
if ( F_32 () > 0 )
F_10 ( V_2 , 0 , 2 ) ;
else
F_10 ( V_2 , 0 , 1 ) ;
V_39 = V_2 -> V_41 [ 1 ] ;
V_43:
F_3 () ;
return V_39 ;
}
static bool F_34 ( unsigned char V_34 , unsigned char V_75 ,
struct V_76 * V_77 )
{
static bool V_78 ;
if ( V_75 & 0x20 )
return false ;
if ( F_35 ( V_34 == 0xe0 ) ) {
V_78 = true ;
return false ;
} else if ( F_35 ( V_78 ) ) {
switch ( V_34 ) {
case 0x8 :
F_36 ( & V_79 ,
F_37 ( V_80 ) ) ;
break;
}
V_78 = false ;
}
return false ;
}
static int T_1 F_38 ( void )
{
int V_81 = 0 ;
int V_39 ;
if ( ! F_24 ( V_82 ) )
return - V_74 ;
F_39 ( F_8 , NULL ) ;
if ( ! V_16 ) {
F_25 ( L_26 ) ;
return - V_74 ;
}
V_39 = F_40 ( & V_83 ) ;
if ( V_39 )
goto V_84;
V_59 = F_41 ( L_27 , - 1 ) ;
if ( ! V_59 ) {
V_39 = - V_63 ;
goto V_85;
}
V_39 = F_42 ( V_59 ) ;
if ( V_39 )
goto V_86;
V_87 = F_43 ( V_18 | V_88 ) ;
if ( ! V_87 )
goto V_89;
V_2 = F_44 ( V_87 ) ;
V_39 = F_23 () ;
if ( V_39 ) {
F_45 ( L_28 ) ;
goto V_90;
}
V_39 = F_46 ( F_34 ) ;
if ( V_39 ) {
F_45 ( L_29 ) ;
goto V_91;
}
V_92 = F_47 ( L_30 , NULL ) ;
if ( V_92 != NULL )
F_48 ( L_31 , 0444 , V_92 , NULL ,
& V_93 ) ;
#ifdef F_49
if ( F_50 () )
return 0 ;
#endif
F_1 () ;
V_2 -> V_44 [ 0 ] = F_9 ( V_71 ) ;
if ( V_2 -> V_44 [ 0 ] != - 1 ) {
F_10 ( V_2 , 0 , 2 ) ;
V_81 = V_2 -> V_41 [ 3 ] ;
}
F_3 () ;
if ( V_81 ) {
struct V_94 V_72 ;
memset ( & V_72 , 0 , sizeof( struct V_94 ) ) ;
V_72 . type = V_95 ;
V_72 . V_96 = V_81 ;
V_97 = F_51 ( L_32 ,
& V_59 -> V_60 ,
NULL ,
& V_98 ,
& V_72 ) ;
if ( F_52 ( V_97 ) ) {
V_39 = F_53 ( V_97 ) ;
V_97 = NULL ;
goto V_99;
}
V_97 -> V_72 . V_73 =
F_33 ( V_97 ) ;
F_54 ( V_97 ) ;
}
return 0 ;
V_99:
F_55 ( F_34 ) ;
F_56 ( & V_79 ) ;
V_91:
F_30 () ;
V_90:
F_57 ( ( unsigned long ) V_87 ) ;
V_89:
F_58 ( V_59 ) ;
V_86:
F_59 ( V_59 ) ;
V_85:
F_60 ( & V_83 ) ;
V_84:
F_61 ( V_16 ) ;
return V_39 ;
}
static void T_2 F_62 ( void )
{
F_63 ( V_92 ) ;
F_55 ( F_34 ) ;
F_56 ( & V_79 ) ;
F_64 ( V_97 ) ;
F_30 () ;
if ( V_59 ) {
F_65 ( V_59 ) ;
F_60 ( & V_83 ) ;
}
F_61 ( V_16 ) ;
F_57 ( ( unsigned long ) V_2 ) ;
}
