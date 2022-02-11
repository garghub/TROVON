static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 + V_2 - 1 ) >> V_3 ;
}
static inline T_1 F_2 ( T_1 V_4 )
{
return V_4 << V_3 ;
}
static void F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
V_6 -> V_9 = V_8 -> V_9 ;
V_6 -> V_10 = V_8 -> V_10 ;
V_6 -> V_11 = V_8 -> V_11 ;
V_6 -> V_12 = F_2 ( V_8 -> V_12 ) ;
V_6 -> V_13 = F_2 ( V_8 -> V_13 ) ;
V_6 -> V_14 = F_2 ( V_8 -> V_15 ) ;
V_6 -> V_16 = V_8 -> V_16 ;
V_6 -> V_17 = V_8 -> V_17 ;
}
static void F_4 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
V_8 -> V_9 = V_6 -> V_9 ;
V_8 -> V_10 = V_6 -> V_10 ;
V_8 -> V_11 = V_6 -> V_11 ;
V_8 -> V_12 = F_1 ( V_6 -> V_12 ) ;
V_8 -> V_13 = F_1 ( V_6 -> V_13 ) ;
V_8 -> V_15 = F_1 ( V_6 -> V_14 ) ;
V_8 -> V_16 = V_6 -> V_16 ;
V_8 -> V_17 = V_6 -> V_17 ;
}
static int F_5 ( struct V_18 * V_18 )
{
int type = V_18 -> V_19 . type ;
struct V_7 V_20 ;
struct V_21 * V_22 = F_6 ( V_18 -> V_23 ) ;
if ( ! V_22 -> V_24 [ type ] )
return - V_25 ;
memset ( & V_20 , 0 , sizeof( struct V_7 ) ) ;
V_18 -> V_23 -> V_26 -> V_27 ( V_18 -> V_23 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) ,
F_7 ( F_8 ( & V_28 , V_18 -> V_19 ) ) ) ;
F_3 ( & V_18 -> V_29 , & V_20 ) ;
if ( V_18 -> V_29 . V_12 == 0 &&
V_18 -> V_29 . V_13 == 0 &&
V_18 -> V_29 . V_9 == 0 &&
V_18 -> V_29 . V_10 == 0 )
F_9 ( V_30 , & V_18 -> V_31 ) ;
F_10 ( V_32 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_18 )
{
short type = V_18 -> V_19 . type ;
T_2 V_33 ;
struct V_7 V_20 ;
F_4 ( & V_20 , & V_18 -> V_29 ) ;
if ( ( ( type == V_34 ) && F_12 ( V_18 -> V_19 . V_35 , V_36 ) ) ||
( ( type == V_37 ) && F_13 ( V_18 -> V_19 . V_38 , V_39 ) ) ) {
V_20 . V_17 =
F_6 ( V_18 -> V_23 ) -> V_40 [ type ] . V_41 ;
V_20 . V_16 =
F_6 ( V_18 -> V_23 ) -> V_40 [ type ] . V_42 ;
}
V_33 = 0 ;
if ( F_6 ( V_18 -> V_23 ) -> V_24 [ type ] )
V_33 = V_18 -> V_23 -> V_26 -> V_43 ( V_18 -> V_23 , type ,
( char * ) & V_20 , sizeof( struct V_7 ) ,
F_7 ( F_8 ( & V_28 , V_18 -> V_19 ) ) ) ;
if ( V_33 != sizeof( struct V_7 ) ) {
F_14 ( V_18 -> V_23 , L_1 ) ;
if ( V_33 >= 0 )
V_33 = - V_44 ;
goto V_45;
}
V_33 = 0 ;
V_45:
F_10 ( V_46 ) ;
return V_33 ;
}
static int F_15 ( struct V_47 * V_48 , int type )
{
struct V_49 * V_49 = F_6 ( V_48 ) -> V_24 [ type ] ;
T_3 V_4 ;
T_4 V_50 ;
struct V_51 V_52 ;
T_2 V_53 ;
T_5 V_54 ;
static const T_6 V_55 [] = V_56 ;
V_54 = F_16 ( V_49 ) ;
if ( ! V_54 )
return 0 ;
V_4 = V_54 >> V_57 ;
V_50 = V_54 & ( V_58 - 1 ) ;
if ( ( V_4 % sizeof( struct V_7 ) * V_58 + V_50 ) %
sizeof( struct V_7 ) )
return 0 ;
V_53 = V_48 -> V_26 -> V_27 ( V_48 , type , ( char * ) & V_52 ,
sizeof( struct V_51 ) , 0 ) ;
if ( V_53 != sizeof( struct V_51 ) )
return 1 ;
if ( F_17 ( V_52 . V_59 ) != V_55 [ type ] )
return 1 ;
F_18 ( V_60
L_2
L_3 , V_48 -> V_61 ) ;
return 0 ;
}
static int F_19 ( struct V_47 * V_48 , int type )
{
struct V_21 * V_22 = F_6 ( V_48 ) ;
struct V_7 V_20 ;
int V_33 ;
F_20 ( & V_22 -> V_62 ) ;
V_33 = V_48 -> V_26 -> V_27 ( V_48 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_33 != sizeof( struct V_7 ) ) {
if ( V_33 >= 0 )
V_33 = - V_44 ;
goto V_45;
}
V_33 = 0 ;
V_22 -> V_40 [ type ] . V_63 = 0xffffffffULL << V_3 ;
V_22 -> V_40 [ type ] . V_64 = 0xffffffff ;
V_22 -> V_40 [ type ] . V_42 =
V_20 . V_16 ? V_20 . V_16 : V_65 ;
V_22 -> V_40 [ type ] . V_41 =
V_20 . V_17 ? V_20 . V_17 : V_66 ;
V_45:
F_21 ( & V_22 -> V_62 ) ;
return V_33 ;
}
static int F_22 ( struct V_47 * V_48 , int type )
{
struct V_21 * V_22 = F_6 ( V_48 ) ;
struct V_7 V_20 ;
int V_33 ;
F_23 ( & V_22 -> V_62 ) ;
V_33 = V_48 -> V_26 -> V_27 ( V_48 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_33 != sizeof( struct V_7 ) ) {
if ( V_33 >= 0 )
V_33 = - V_44 ;
goto V_45;
}
F_24 ( & V_67 ) ;
V_22 -> V_40 [ type ] . V_68 &= ~ V_69 ;
V_20 . V_16 = V_22 -> V_40 [ type ] . V_42 ;
V_20 . V_17 = V_22 -> V_40 [ type ] . V_41 ;
F_25 ( & V_67 ) ;
V_33 = V_48 -> V_26 -> V_43 ( V_48 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_33 == sizeof( struct V_7 ) )
V_33 = 0 ;
else if ( V_33 > 0 )
V_33 = - V_44 ;
V_45:
F_26 ( & V_22 -> V_62 ) ;
return V_33 ;
}
static int T_7 F_27 ( void )
{
return F_28 ( & V_70 ) ;
}
static void T_8 F_29 ( void )
{
F_30 ( & V_70 ) ;
}
