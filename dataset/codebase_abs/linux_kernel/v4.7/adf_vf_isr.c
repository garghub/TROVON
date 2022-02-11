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
V_27 &= ~ F_22 ( 0 ) ;
F_23 ( V_25 , V_20 -> V_28 ( 0 ) , V_27 ) ;
return;
}
case V_39 :
F_18 ( & F_4 ( V_2 ) ,
L_4 , V_27 ) ;
V_2 -> V_8 . V_40 =
( V_27 & V_41 ) >>
V_42 ;
V_2 -> V_8 . V_43 =
( V_27 & V_44 ) >>
V_45 ;
F_24 ( & V_2 -> V_8 . V_46 ) ;
break;
default:
goto V_30;
}
V_27 &= ~ F_22 ( 0 ) ;
F_23 ( V_25 , V_20 -> V_28 ( 0 ) , V_27 ) ;
F_14 ( V_2 ) ;
return;
V_30:
F_3 ( & F_4 ( V_2 ) ,
L_5 ,
V_27 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_8 . V_47 ,
( void * ) F_15 , ( unsigned long ) V_2 ) ;
F_27 ( & V_2 -> V_8 . V_48 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_8 . V_47 ) ;
F_30 ( & V_2 -> V_8 . V_47 ) ;
F_31 ( & V_2 -> V_8 . V_48 ) ;
}
static T_3 F_32 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
struct V_19 * V_20 = V_2 -> V_21 ;
struct V_22 * V_23 =
& F_16 ( V_2 ) [ V_20 -> V_24 ( V_20 ) ] ;
void T_1 * V_25 = V_23 -> V_26 ;
T_2 V_51 ;
V_51 = F_17 ( V_25 , V_52 ) ;
if ( V_51 & V_53 ) {
F_33 ( V_2 ) ;
F_34 ( & V_2 -> V_8 . V_47 ) ;
return V_54 ;
}
if ( V_51 & V_55 ) {
struct V_56 * V_57 = V_2 -> V_58 ;
struct V_59 * V_60 = & V_57 -> V_61 [ 0 ] ;
F_35 ( V_60 -> V_62 , V_60 -> V_63 ,
0 ) ;
F_34 ( & V_60 -> V_64 ) ;
return V_54 ;
}
return V_65 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_7 ( V_2 ) ;
unsigned int V_66 ;
int V_67 ;
snprintf ( V_2 -> V_8 . V_9 , V_10 ,
L_6 , V_13 -> V_68 -> V_69 , F_37 ( V_13 -> V_70 ) ,
F_38 ( V_13 -> V_70 ) ) ;
V_67 = F_39 ( V_13 -> V_49 , F_32 , 0 , V_2 -> V_8 . V_9 ,
( void * ) V_2 ) ;
if ( V_67 ) {
F_3 ( & F_4 ( V_2 ) , L_7 ,
V_2 -> V_8 . V_9 ) ;
return V_67 ;
}
V_66 = V_2 -> V_37 % F_40 () ;
F_41 ( V_13 -> V_49 , F_42 ( V_66 ) ) ;
return V_67 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_56 * V_71 = V_2 -> V_58 ;
F_26 ( & V_71 -> V_61 [ 0 ] . V_64 , V_72 ,
( unsigned long ) V_71 -> V_61 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_56 * V_71 = V_2 -> V_58 ;
F_29 ( & V_71 -> V_61 [ 0 ] . V_64 ) ;
F_30 ( & V_71 -> V_61 [ 0 ] . V_64 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_7 ( V_2 ) ;
F_41 ( V_13 -> V_49 , NULL ) ;
F_46 ( V_13 -> V_49 , ( void * ) V_2 ) ;
F_44 ( V_2 ) ;
F_28 ( V_2 ) ;
F_6 ( V_2 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
goto V_73;
if ( F_25 ( V_2 ) )
goto V_73;
if ( F_43 ( V_2 ) )
goto V_73;
if ( F_36 ( V_2 ) )
goto V_73;
return 0 ;
V_73:
F_45 ( V_2 ) ;
return - V_74 ;
}
int T_4 F_48 ( void )
{
V_38 = F_49 ( L_8 ) ;
return ! V_38 ? - V_74 : 0 ;
}
void F_50 ( void )
{
if ( V_38 )
F_51 ( V_38 ) ;
V_38 = NULL ;
}
