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
static int F_14 ( struct V_38 * V_39 , void * V_40 )
{
int V_41 ;
F_2 () ;
F_11 ( V_6 , 17 , 11 ) ;
V_41 = V_6 -> V_42 [ 1 ] ;
F_4 () ;
F_15 ( V_39 , L_1 , V_41 ) ;
F_15 ( V_39 , L_2 ,
V_41 & F_16 ( 0 ) ) ;
F_15 ( V_39 , L_3 ,
( V_41 & F_16 ( 1 ) ) >> 1 ) ;
F_15 ( V_39 , L_4 ,
( V_41 & F_16 ( 2 ) ) >> 2 ) ;
F_15 ( V_39 , L_5 ,
( V_41 & F_16 ( 3 ) ) >> 3 ) ;
F_15 ( V_39 , L_6 ,
( V_41 & F_16 ( 4 ) ) >> 4 ) ;
F_15 ( V_39 , L_7 ,
( V_41 & F_16 ( 5 ) ) >> 5 ) ;
F_15 ( V_39 , L_8 ,
( V_41 & F_16 ( 8 ) ) >> 8 ) ;
F_15 ( V_39 , L_9 ,
( V_41 & F_16 ( 9 ) ) >> 9 ) ;
F_15 ( V_39 , L_10 ,
( V_41 & F_16 ( 10 ) ) >> 10 ) ;
F_15 ( V_39 , L_11 ,
( V_41 & F_16 ( 16 ) ) >> 16 ) ;
F_15 ( V_39 , L_12 ,
( V_41 & F_16 ( 17 ) ) >> 17 ) ;
F_15 ( V_39 , L_13 ,
( V_41 & F_16 ( 18 ) ) >> 18 ) ;
F_15 ( V_39 , L_14 ,
( V_41 & F_16 ( 19 ) ) >> 19 ) ;
F_15 ( V_39 , L_15 , V_43 ) ;
F_15 ( V_39 , L_16 ,
V_43 & F_16 ( 0 ) ) ;
F_15 ( V_39 , L_17 ,
( V_43 & F_16 ( 1 ) ) >> 1 ) ;
F_15 ( V_39 , L_18 ,
( V_43 & F_16 ( 2 ) ) >> 2 ) ;
F_15 ( V_39 , L_19 ,
( V_43 & F_16 ( 7 ) ) >> 7 ) ;
F_15 ( V_39 , L_20 ,
( V_43 & F_16 ( 8 ) ) >> 8 ) ;
F_15 ( V_39 , L_21 ,
( V_43 & F_16 ( 15 ) ) >> 15 ) ;
return 0 ;
}
static int F_17 ( struct V_44 * V_44 , struct V_45 * V_45 )
{
return F_18 ( V_45 , F_14 , V_44 -> V_46 ) ;
}
static int F_19 ( struct V_47 * V_48 )
{
int V_49 = 0 ;
F_2 () ;
V_6 -> V_50 [ 0 ] = F_10 ( V_51 ) ;
V_6 -> V_50 [ 1 ] = V_48 -> V_52 . V_53 ;
if ( V_6 -> V_50 [ 0 ] == - 1 ) {
V_49 = - V_54 ;
goto V_55;
}
if ( F_20 () > 0 )
F_11 ( V_6 , 1 , 2 ) ;
else
F_11 ( V_6 , 1 , 1 ) ;
V_55:
F_4 () ;
return 0 ;
}
static int F_21 ( struct V_47 * V_48 )
{
int V_49 = 0 ;
F_2 () ;
V_6 -> V_50 [ 0 ] = F_10 ( V_51 ) ;
if ( V_6 -> V_50 [ 0 ] == - 1 ) {
V_49 = - V_54 ;
goto V_55;
}
if ( F_20 () > 0 )
F_11 ( V_6 , 0 , 2 ) ;
else
F_11 ( V_6 , 0 , 1 ) ;
V_49 = V_6 -> V_42 [ 1 ] ;
V_55:
F_4 () ;
return V_49 ;
}
static void F_22 ( void )
{
int V_31 = 0x97 ;
char V_40 = 1 ;
F_23 ( & V_40 , V_31 | 1 << 12 ) ;
}
static void F_24 ( void )
{
int V_31 = 0x97 ;
char V_40 = 2 ;
F_23 ( & V_40 , V_31 | 1 << 12 ) ;
}
static void F_25 ( struct V_56 * V_57 ,
enum V_58 V_59 )
{
if ( V_59 > 0 )
F_22 () ;
else
F_24 () ;
}
static int F_26 ( struct V_60 * V_61 )
{
return F_27 ( V_61 , & V_62 ) ;
}
static void F_28 ( void )
{
F_29 ( & V_62 ) ;
}
static int T_1 F_30 ( void )
{
int V_63 = 0 ;
int V_49 ;
if ( ! F_31 ( V_64 ) )
return - V_54 ;
V_3 = NULL ;
F_31 ( V_65 ) ;
F_32 ( F_9 , NULL ) ;
if ( ! V_20 ) {
F_33 ( L_22 ) ;
return - V_54 ;
}
V_49 = F_34 ( & V_66 ) ;
if ( V_49 )
goto V_67;
V_68 = F_35 ( L_23 , - 1 ) ;
if ( ! V_68 ) {
V_49 = - V_69 ;
goto V_70;
}
V_49 = F_36 ( V_68 ) ;
if ( V_49 )
goto V_71;
V_72 = F_37 ( V_22 | V_73 ) ;
if ( ! V_72 )
goto V_74;
V_6 = F_38 ( V_72 ) ;
if ( V_3 && V_3 -> V_62 )
F_26 ( & V_68 -> V_61 ) ;
V_75 = F_39 ( L_24 , NULL ) ;
#ifdef F_40
if ( F_41 () )
return 0 ;
#endif
F_2 () ;
V_6 -> V_50 [ 0 ] = F_10 ( V_51 ) ;
if ( V_6 -> V_50 [ 0 ] != - 1 ) {
F_11 ( V_6 , 0 , 2 ) ;
V_63 = V_6 -> V_42 [ 3 ] ;
}
F_4 () ;
if ( V_63 ) {
struct V_76 V_52 ;
memset ( & V_52 , 0 , sizeof( struct V_76 ) ) ;
V_52 . type = V_77 ;
V_52 . V_78 = V_63 ;
V_79 = F_42 ( L_25 ,
& V_68 -> V_61 ,
NULL ,
& V_80 ,
& V_52 ) ;
if ( F_43 ( V_79 ) ) {
V_49 = F_44 ( V_79 ) ;
V_79 = NULL ;
goto V_81;
}
V_79 -> V_52 . V_53 =
F_21 ( V_79 ) ;
F_45 ( V_79 ) ;
}
return 0 ;
V_81:
F_46 ( ( unsigned long ) V_72 ) ;
V_74:
F_47 ( V_68 ) ;
V_71:
F_48 ( V_68 ) ;
V_70:
F_49 ( & V_66 ) ;
V_67:
F_50 ( V_20 ) ;
return V_49 ;
}
static void T_2 F_51 ( void )
{
F_52 ( V_75 ) ;
if ( V_3 && V_3 -> V_62 )
F_28 () ;
F_53 ( V_79 ) ;
if ( V_68 ) {
F_54 ( V_68 ) ;
F_49 ( & V_66 ) ;
}
F_50 ( V_20 ) ;
F_46 ( ( unsigned long ) V_6 ) ;
}
