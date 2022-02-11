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
static void F_10 ( void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 =
& F_11 ( V_2 ) [ V_16 -> V_20 ( V_16 ) ] ;
void T_1 * V_21 = V_19 -> V_22 ;
T_2 V_23 ;
V_23 = F_12 ( V_21 , V_16 -> V_24 ( 0 ) ) ;
if ( ! ( V_23 & V_25 ) )
goto V_26;
switch ( ( V_23 & V_27 ) >> V_28 ) {
case V_29 :
F_13 ( & F_4 ( V_2 ) ,
L_2 , V_23 ) ;
F_14 ( V_2 ) ;
break;
case V_30 :
F_13 ( & F_4 ( V_2 ) ,
L_3 , V_23 ) ;
V_2 -> V_8 . V_31 =
( V_23 & V_32 ) >>
V_33 ;
V_2 -> V_8 . V_34 =
( V_23 & V_35 ) >>
V_36 ;
F_15 ( & V_2 -> V_8 . V_37 ) ;
break;
default:
goto V_26;
}
V_23 &= ~ F_16 ( 0 ) ;
F_17 ( V_21 , V_16 -> V_24 ( 0 ) , V_23 ) ;
F_18 ( V_2 ) ;
return;
V_26:
F_3 ( & F_4 ( V_2 ) ,
L_4 ,
V_23 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_8 . V_38 ,
( void * ) F_10 , ( unsigned long ) V_2 ) ;
F_21 ( & V_2 -> V_8 . V_39 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_8 . V_38 ) ;
F_24 ( & V_2 -> V_8 . V_38 ) ;
F_25 ( & V_2 -> V_8 . V_39 ) ;
}
static T_3 F_26 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = V_41 ;
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_18 * V_19 =
& F_11 ( V_2 ) [ V_16 -> V_20 ( V_16 ) ] ;
void T_1 * V_21 = V_19 -> V_22 ;
T_2 V_42 ;
V_42 = F_12 ( V_21 , V_43 ) ;
if ( V_42 & V_44 ) {
F_27 ( V_2 ) ;
F_28 ( & V_2 -> V_8 . V_38 ) ;
return V_45 ;
}
if ( V_42 & V_46 ) {
struct V_47 * V_48 = V_2 -> V_49 ;
struct V_50 * V_51 = & V_48 -> V_52 [ 0 ] ;
F_29 ( V_51 -> V_53 , V_51 -> V_54 ,
0 ) ;
F_28 ( & V_51 -> V_55 ) ;
return V_45 ;
}
return V_56 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_7 ( V_2 ) ;
unsigned int V_57 ;
int V_58 ;
snprintf ( V_2 -> V_8 . V_9 , V_10 ,
L_5 , V_13 -> V_59 -> V_60 , F_31 ( V_13 -> V_61 ) ,
F_32 ( V_13 -> V_61 ) ) ;
V_58 = F_33 ( V_13 -> V_40 , F_26 , 0 , V_2 -> V_8 . V_9 ,
( void * ) V_2 ) ;
if ( V_58 ) {
F_3 ( & F_4 ( V_2 ) , L_6 ,
V_2 -> V_8 . V_9 ) ;
return V_58 ;
}
V_57 = V_2 -> V_62 % F_34 () ;
F_35 ( V_13 -> V_40 , F_36 ( V_57 ) ) ;
return V_58 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_47 * V_63 = V_2 -> V_49 ;
F_20 ( & V_63 -> V_52 [ 0 ] . V_55 , V_64 ,
( unsigned long ) V_63 -> V_52 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_47 * V_63 = V_2 -> V_49 ;
F_23 ( & V_63 -> V_52 [ 0 ] . V_55 ) ;
F_24 ( & V_63 -> V_52 [ 0 ] . V_55 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_7 * V_13 = F_7 ( V_2 ) ;
F_35 ( V_13 -> V_40 , NULL ) ;
F_40 ( V_13 -> V_40 , ( void * ) V_2 ) ;
F_38 ( V_2 ) ;
F_22 ( V_2 ) ;
F_6 ( V_2 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
goto V_65;
if ( F_19 ( V_2 ) )
goto V_65;
if ( F_37 ( V_2 ) )
goto V_65;
if ( F_30 ( V_2 ) )
goto V_65;
return 0 ;
V_65:
F_39 ( V_2 ) ;
return - V_66 ;
}
