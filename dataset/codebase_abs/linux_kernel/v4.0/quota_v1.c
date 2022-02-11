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
if ( ! F_6 ( V_18 -> V_21 ) -> V_22 [ type ] )
return - V_23 ;
memset ( & V_20 , 0 , sizeof( struct V_7 ) ) ;
V_18 -> V_21 -> V_24 -> V_25 ( V_18 -> V_21 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) ,
F_7 ( F_8 ( & V_26 , V_18 -> V_19 ) ) ) ;
F_3 ( & V_18 -> V_27 , & V_20 ) ;
if ( V_18 -> V_27 . V_12 == 0 &&
V_18 -> V_27 . V_13 == 0 &&
V_18 -> V_27 . V_9 == 0 &&
V_18 -> V_27 . V_10 == 0 )
F_9 ( V_28 , & V_18 -> V_29 ) ;
F_10 ( V_30 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_18 )
{
short type = V_18 -> V_19 . type ;
T_2 V_31 ;
struct V_7 V_20 ;
F_4 ( & V_20 , & V_18 -> V_27 ) ;
if ( ( ( type == V_32 ) && F_12 ( V_18 -> V_19 . V_33 , V_34 ) ) ||
( ( type == V_35 ) && F_13 ( V_18 -> V_19 . V_36 , V_37 ) ) ) {
V_20 . V_17 =
F_6 ( V_18 -> V_21 ) -> V_38 [ type ] . V_39 ;
V_20 . V_16 =
F_6 ( V_18 -> V_21 ) -> V_38 [ type ] . V_40 ;
}
V_31 = 0 ;
if ( F_6 ( V_18 -> V_21 ) -> V_22 [ type ] )
V_31 = V_18 -> V_21 -> V_24 -> V_41 ( V_18 -> V_21 , type ,
( char * ) & V_20 , sizeof( struct V_7 ) ,
F_7 ( F_8 ( & V_26 , V_18 -> V_19 ) ) ) ;
if ( V_31 != sizeof( struct V_7 ) ) {
F_14 ( V_18 -> V_21 , L_1 ) ;
if ( V_31 >= 0 )
V_31 = - V_42 ;
goto V_43;
}
V_31 = 0 ;
V_43:
F_10 ( V_44 ) ;
return V_31 ;
}
static int F_15 ( struct V_45 * V_46 , int type )
{
struct V_47 * V_47 = F_6 ( V_46 ) -> V_22 [ type ] ;
T_3 V_4 ;
T_4 V_48 ;
struct V_49 V_50 ;
T_2 V_51 ;
T_5 V_52 ;
static const T_6 V_53 [] = V_54 ;
V_52 = F_16 ( V_47 ) ;
if ( ! V_52 )
return 0 ;
V_4 = V_52 >> V_55 ;
V_48 = V_52 & ( V_56 - 1 ) ;
if ( ( V_4 % sizeof( struct V_7 ) * V_56 + V_48 ) %
sizeof( struct V_7 ) )
return 0 ;
V_51 = V_46 -> V_24 -> V_25 ( V_46 , type , ( char * ) & V_50 ,
sizeof( struct V_49 ) , 0 ) ;
if ( V_51 != sizeof( struct V_49 ) )
return 1 ;
if ( F_17 ( V_50 . V_57 ) != V_53 [ type ] )
return 1 ;
F_18 ( V_58
L_2
L_3 , V_46 -> V_59 ) ;
return 0 ;
}
static int F_19 ( struct V_45 * V_46 , int type )
{
struct V_60 * V_61 = F_6 ( V_46 ) ;
struct V_7 V_20 ;
int V_31 ;
V_31 = V_46 -> V_24 -> V_25 ( V_46 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_31 != sizeof( struct V_7 ) ) {
if ( V_31 >= 0 )
V_31 = - V_42 ;
goto V_43;
}
V_31 = 0 ;
V_61 -> V_38 [ type ] . V_62 = 0xffffffffULL << V_3 ;
V_61 -> V_38 [ type ] . V_63 = 0xffffffff ;
V_61 -> V_38 [ type ] . V_40 =
V_20 . V_16 ? V_20 . V_16 : V_64 ;
V_61 -> V_38 [ type ] . V_39 =
V_20 . V_17 ? V_20 . V_17 : V_65 ;
V_43:
return V_31 ;
}
static int F_20 ( struct V_45 * V_46 , int type )
{
struct V_60 * V_61 = F_6 ( V_46 ) ;
struct V_7 V_20 ;
int V_31 ;
V_61 -> V_38 [ type ] . V_66 &= ~ V_67 ;
V_31 = V_46 -> V_24 -> V_25 ( V_46 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_31 != sizeof( struct V_7 ) ) {
if ( V_31 >= 0 )
V_31 = - V_42 ;
goto V_43;
}
V_20 . V_16 = V_61 -> V_38 [ type ] . V_40 ;
V_20 . V_17 = V_61 -> V_38 [ type ] . V_39 ;
V_31 = V_46 -> V_24 -> V_41 ( V_46 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_31 == sizeof( struct V_7 ) )
V_31 = 0 ;
else if ( V_31 > 0 )
V_31 = - V_42 ;
V_43:
return V_31 ;
}
static int T_7 F_21 ( void )
{
return F_22 ( & V_68 ) ;
}
static void T_8 F_23 ( void )
{
F_24 ( & V_68 ) ;
}
