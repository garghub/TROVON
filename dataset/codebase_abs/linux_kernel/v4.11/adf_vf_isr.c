static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_6 = F_2 ( V_4 -> V_7 ) ;
if ( V_6 ) {
F_3 ( & F_4 ( V_2 ) ,
L_1 ) ;
return V_6 ;
}
V_2 -> V_8 . V_9 = F_5 ( V_10 , V_11 ) ;
if ( ! V_2 -> V_8 . V_9 )
return - V_12 ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_7 ( V_2 ) ;
F_8 ( V_2 -> V_8 . V_9 ) ;
F_9 ( V_13 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 =
F_11 ( V_15 , struct V_16 , V_15 ) ;
struct V_1 * V_2 = V_17 -> V_2 ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_8 ( V_17 ) ;
}
static void F_15 ( void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_19 * V_20 = V_2 -> V_21 ;
struct V_22 * V_23 =
& F_16 ( V_2 ) [ V_20 -> V_24 ( V_20 ) ] ;
void T_1 * V_25 = V_23 -> V_26 ;
T_2 V_27 ;
V_27 = F_17 ( V_25 , V_20 -> V_28 ( 0 ) ) ;
if ( ! ( V_27 & V_29 ) )
goto V_30;
switch ( ( V_27 & V_31 ) >> V_32 ) {
case V_33 : {
struct V_16 * V_17 ;
F_18 ( & F_4 ( V_2 ) ,
L_2 , V_27 ) ;
F_19 ( V_34 , & V_2 -> V_35 ) ;
V_17 = F_5 ( sizeof( * V_17 ) , V_36 ) ;
if ( ! V_17 ) {
F_3 ( & F_4 ( V_2 ) ,
L_3 ,
V_2 -> V_37 ) ;
return;
}
V_17 -> V_2 = V_2 ;
F_20 ( & V_17 -> V_15 , F_10 ) ;
F_21 ( V_38 , & V_17 -> V_15 ) ;
V_27 &= ~ V_39 ;
F_22 ( V_25 , V_20 -> V_28 ( 0 ) , V_27 ) ;
return;
}
case V_40 :
F_18 ( & F_4 ( V_2 ) ,
L_4 , V_27 ) ;
V_2 -> V_8 . V_41 =
( V_27 & V_42 ) >>
V_43 ;
V_2 -> V_8 . V_44 =
( V_27 & V_45 ) >>
V_46 ;
F_23 ( & V_2 -> V_8 . V_47 ) ;
break;
default:
goto V_30;
}
V_27 &= ~ V_39 ;
F_22 ( V_25 , V_20 -> V_28 ( 0 ) , V_27 ) ;
F_14 ( V_2 ) ;
return;
V_30:
F_3 ( & F_4 ( V_2 ) ,
L_5 ,
V_27 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_8 . V_48 ,
( void * ) F_15 , ( unsigned long ) V_2 ) ;
F_26 ( & V_2 -> V_8 . V_49 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_8 . V_48 ) ;
F_29 ( & V_2 -> V_8 . V_48 ) ;
F_30 ( & V_2 -> V_8 . V_49 ) ;
}
static T_3 F_31 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_19 * V_20 = V_2 -> V_21 ;
struct V_22 * V_23 =
& F_16 ( V_2 ) [ V_20 -> V_24 ( V_20 ) ] ;
void T_1 * V_25 = V_23 -> V_26 ;
T_2 V_52 ;
V_52 = F_17 ( V_25 , V_53 ) ;
if ( V_52 & V_54 ) {
F_32 ( V_2 ) ;
F_33 ( & V_2 -> V_8 . V_48 ) ;
return V_55 ;
}
if ( V_52 & V_56 ) {
struct V_57 * V_58 = V_2 -> V_59 ;
struct V_60 * V_61 = & V_58 -> V_62 [ 0 ] ;
F_34 ( V_61 -> V_63 , V_61 -> V_64 ,
0 ) ;
F_33 ( & V_61 -> V_65 ) ;
return V_55 ;
}
return V_66 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_7 ( V_2 ) ;
unsigned int V_67 ;
int V_68 ;
snprintf ( V_2 -> V_8 . V_9 , V_10 ,
L_6 , V_13 -> V_69 -> V_70 , F_36 ( V_13 -> V_71 ) ,
F_37 ( V_13 -> V_71 ) ) ;
V_68 = F_38 ( V_13 -> V_50 , F_31 , 0 , V_2 -> V_8 . V_9 ,
( void * ) V_2 ) ;
if ( V_68 ) {
F_3 ( & F_4 ( V_2 ) , L_7 ,
V_2 -> V_8 . V_9 ) ;
return V_68 ;
}
V_67 = V_2 -> V_37 % F_39 () ;
F_40 ( V_13 -> V_50 , F_41 ( V_67 ) ) ;
return V_68 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_57 * V_72 = V_2 -> V_59 ;
F_25 ( & V_72 -> V_62 [ 0 ] . V_65 , V_73 ,
( unsigned long ) V_72 -> V_62 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_57 * V_72 = V_2 -> V_59 ;
F_28 ( & V_72 -> V_62 [ 0 ] . V_65 ) ;
F_29 ( & V_72 -> V_62 [ 0 ] . V_65 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_7 ( V_2 ) ;
F_40 ( V_13 -> V_50 , NULL ) ;
F_45 ( V_13 -> V_50 , ( void * ) V_2 ) ;
F_43 ( V_2 ) ;
F_27 ( V_2 ) ;
F_6 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
goto V_74;
if ( F_24 ( V_2 ) )
goto V_74;
if ( F_42 ( V_2 ) )
goto V_74;
if ( F_35 ( V_2 ) )
goto V_74;
return 0 ;
V_74:
F_44 ( V_2 ) ;
return - V_75 ;
}
int T_4 F_47 ( void )
{
V_38 = F_48 ( L_8 , V_76 , 0 ) ;
return ! V_38 ? - V_75 : 0 ;
}
void F_49 ( void )
{
if ( V_38 )
F_50 ( V_38 ) ;
V_38 = NULL ;
}
