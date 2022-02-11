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
static int F_14 ( struct V_39 * V_40 , void * V_41 )
{
int V_42 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_42 = V_6 -> V_43 [ 1 ] ;
F_4 () ;
F_15 ( V_40 , L_1 , V_42 ) ;
F_15 ( V_40 , L_2 ,
V_42 & F_16 ( 0 ) ) ;
F_15 ( V_40 , L_3 ,
( V_42 & F_16 ( 1 ) ) >> 1 ) ;
F_15 ( V_40 , L_4 ,
( V_42 & F_16 ( 2 ) ) >> 2 ) ;
F_15 ( V_40 , L_5 ,
( V_42 & F_16 ( 3 ) ) >> 3 ) ;
F_15 ( V_40 , L_6 ,
( V_42 & F_16 ( 4 ) ) >> 4 ) ;
F_15 ( V_40 , L_7 ,
( V_42 & F_16 ( 5 ) ) >> 5 ) ;
F_15 ( V_40 , L_8 ,
( V_42 & F_16 ( 8 ) ) >> 8 ) ;
F_15 ( V_40 , L_9 ,
( V_42 & F_16 ( 9 ) ) >> 9 ) ;
F_15 ( V_40 , L_10 ,
( V_42 & F_16 ( 10 ) ) >> 10 ) ;
F_15 ( V_40 , L_11 ,
( V_42 & F_16 ( 16 ) ) >> 16 ) ;
F_15 ( V_40 , L_12 ,
( V_42 & F_16 ( 17 ) ) >> 17 ) ;
F_15 ( V_40 , L_13 ,
( V_42 & F_16 ( 18 ) ) >> 18 ) ;
F_15 ( V_40 , L_14 ,
( V_42 & F_16 ( 19 ) ) >> 19 ) ;
F_15 ( V_40 , L_15 , V_44 ) ;
F_15 ( V_40 , L_16 ,
V_44 & F_16 ( 0 ) ) ;
F_15 ( V_40 , L_17 ,
( V_44 & F_16 ( 1 ) ) >> 1 ) ;
F_15 ( V_40 , L_18 ,
( V_44 & F_16 ( 2 ) ) >> 2 ) ;
F_15 ( V_40 , L_19 ,
( V_44 & F_16 ( 7 ) ) >> 7 ) ;
F_15 ( V_40 , L_20 ,
( V_44 & F_16 ( 8 ) ) >> 8 ) ;
F_15 ( V_40 , L_21 ,
( V_44 & F_16 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_17 ( struct V_45 * V_45 , struct V_46 * V_46 )
{
return F_18 ( V_46 , F_14 , V_45 -> V_47 ) ;
}
static int F_19 ( struct V_48 * V_49 )
{
int V_50 = 0 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = F_10 ( V_52 ) ;
V_6 -> V_51 [ 1 ] = V_49 -> V_53 . V_54 ;
if ( V_6 -> V_51 [ 0 ] == - 1 ) {
V_50 = - V_55 ;
goto V_56;
}
if ( F_20 () > 0 )
F_11 ( V_6 , 1 , 2 ) ;
else
F_11 ( V_6 , 1 , 1 ) ;
V_56:
F_4 () ;
return 0 ;
}
static int F_21 ( struct V_48 * V_49 )
{
int V_50 = 0 ;
F_2 () ;
V_6 -> V_51 [ 0 ] = F_10 ( V_52 ) ;
if ( V_6 -> V_51 [ 0 ] == - 1 ) {
V_50 = - V_55 ;
goto V_56;
}
if ( F_20 () > 0 )
F_11 ( V_6 , 0 , 2 ) ;
else
F_11 ( V_6 , 0 , 1 ) ;
V_50 = V_6 -> V_43 [ 1 ] ;
V_56:
F_4 () ;
return V_50 ;
}
static void F_22 ( void )
{
int V_32 = 0x97 ;
char V_41 = 1 ;
F_23 ( & V_41 , V_32 | 1 << 12 ) ;
}
static void F_24 ( void )
{
int V_32 = 0x97 ;
char V_41 = 2 ;
F_23 ( & V_41 , V_32 | 1 << 12 ) ;
}
static void F_25 ( struct V_57 * V_58 ,
enum V_59 V_60 )
{
if ( V_60 > 0 )
F_22 () ;
else
F_24 () ;
}
static int F_26 ( struct V_61 * V_62 )
{
return F_27 ( V_62 , & V_63 ) ;
}
static void F_28 ( void )
{
F_29 ( & V_63 ) ;
}
static int T_1 F_30 ( void )
{
int V_64 = 0 ;
int V_50 ;
if ( ! F_31 ( V_65 ) )
return - V_55 ;
V_3 = NULL ;
F_31 ( V_66 ) ;
F_32 ( F_9 , NULL ) ;
if ( ! V_21 ) {
F_33 ( L_22 ) ;
return - V_55 ;
}
V_50 = F_34 ( & V_67 ) ;
if ( V_50 )
goto V_68;
V_69 = F_35 ( L_23 , - 1 ) ;
if ( ! V_69 ) {
V_50 = - V_70 ;
goto V_71;
}
V_50 = F_36 ( V_69 ) ;
if ( V_50 )
goto V_72;
V_73 = F_37 ( V_23 | V_74 ) ;
if ( ! V_73 )
goto V_75;
V_6 = F_38 ( V_73 ) ;
if ( V_3 && V_3 -> V_63 )
F_26 ( & V_69 -> V_62 ) ;
V_76 = F_39 ( L_24 , NULL ) ;
#ifdef F_40
if ( F_41 () )
return 0 ;
#endif
F_2 () ;
V_6 -> V_51 [ 0 ] = F_10 ( V_52 ) ;
if ( V_6 -> V_51 [ 0 ] != - 1 ) {
F_11 ( V_6 , 0 , 2 ) ;
V_64 = V_6 -> V_43 [ 3 ] ;
}
F_4 () ;
if ( V_64 ) {
struct V_77 V_53 ;
memset ( & V_53 , 0 , sizeof( struct V_77 ) ) ;
V_53 . type = V_78 ;
V_53 . V_79 = V_64 ;
V_80 = F_42 ( L_25 ,
& V_69 -> V_62 ,
NULL ,
& V_81 ,
& V_53 ) ;
if ( F_43 ( V_80 ) ) {
V_50 = F_44 ( V_80 ) ;
V_80 = NULL ;
goto V_82;
}
V_80 -> V_53 . V_54 =
F_21 ( V_80 ) ;
F_45 ( V_80 ) ;
}
return 0 ;
V_82:
F_46 ( ( unsigned long ) V_73 ) ;
V_75:
F_47 ( V_69 ) ;
V_72:
F_48 ( V_69 ) ;
V_71:
F_49 ( & V_67 ) ;
V_68:
F_50 ( V_21 ) ;
return V_50 ;
}
static void T_2 F_51 ( void )
{
F_52 ( V_76 ) ;
if ( V_3 && V_3 -> V_63 )
F_28 () ;
F_53 ( V_80 ) ;
if ( V_69 ) {
F_54 ( V_69 ) ;
F_49 ( & V_67 ) ;
}
F_50 ( V_21 ) ;
F_46 ( ( unsigned long ) V_6 ) ;
}
