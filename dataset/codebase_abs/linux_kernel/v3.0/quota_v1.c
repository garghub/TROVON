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
int type = V_18 -> V_19 ;
struct V_7 V_20 ;
if ( ! F_6 ( V_18 -> V_21 ) -> V_22 [ type ] )
return - V_23 ;
memset ( & V_20 , 0 , sizeof( struct V_7 ) ) ;
V_18 -> V_21 -> V_24 -> V_25 ( V_18 -> V_21 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( V_18 -> V_26 ) ) ;
F_3 ( & V_18 -> V_27 , & V_20 ) ;
if ( V_18 -> V_27 . V_12 == 0 &&
V_18 -> V_27 . V_13 == 0 &&
V_18 -> V_27 . V_9 == 0 &&
V_18 -> V_27 . V_10 == 0 )
F_8 ( V_28 , & V_18 -> V_29 ) ;
F_9 ( V_30 ) ;
return 0 ;
}
static int F_10 ( struct V_18 * V_18 )
{
short type = V_18 -> V_19 ;
T_2 V_31 ;
struct V_7 V_20 ;
F_4 ( & V_20 , & V_18 -> V_27 ) ;
if ( V_18 -> V_26 == 0 ) {
V_20 . V_17 =
F_6 ( V_18 -> V_21 ) -> V_32 [ type ] . V_33 ;
V_20 . V_16 =
F_6 ( V_18 -> V_21 ) -> V_32 [ type ] . V_34 ;
}
V_31 = 0 ;
if ( F_6 ( V_18 -> V_21 ) -> V_22 [ type ] )
V_31 = V_18 -> V_21 -> V_24 -> V_35 ( V_18 -> V_21 , type ,
( char * ) & V_20 , sizeof( struct V_7 ) ,
F_7 ( V_18 -> V_26 ) ) ;
if ( V_31 != sizeof( struct V_7 ) ) {
F_11 ( V_18 -> V_21 , L_1 ) ;
if ( V_31 >= 0 )
V_31 = - V_36 ;
goto V_37;
}
V_31 = 0 ;
V_37:
F_9 ( V_38 ) ;
return V_31 ;
}
static int F_12 ( struct V_39 * V_40 , int type )
{
struct V_41 * V_41 = F_6 ( V_40 ) -> V_22 [ type ] ;
T_3 V_4 ;
T_4 V_42 ;
struct V_43 V_44 ;
T_2 V_45 ;
T_5 V_46 ;
static const T_6 V_47 [] = V_48 ;
V_46 = F_13 ( V_41 ) ;
if ( ! V_46 )
return 0 ;
V_4 = V_46 >> V_49 ;
V_42 = V_46 & ( V_50 - 1 ) ;
if ( ( V_4 % sizeof( struct V_7 ) * V_50 + V_42 ) %
sizeof( struct V_7 ) )
return 0 ;
V_45 = V_40 -> V_24 -> V_25 ( V_40 , type , ( char * ) & V_44 ,
sizeof( struct V_43 ) , 0 ) ;
if ( V_45 != sizeof( struct V_43 ) )
return 1 ;
if ( F_14 ( V_44 . V_51 ) != V_47 [ type ] )
return 1 ;
F_15 ( V_52
L_2
L_3 , V_40 -> V_53 ) ;
return 0 ;
}
static int F_16 ( struct V_39 * V_40 , int type )
{
struct V_54 * V_55 = F_6 ( V_40 ) ;
struct V_7 V_20 ;
int V_31 ;
V_31 = V_40 -> V_24 -> V_25 ( V_40 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_31 != sizeof( struct V_7 ) ) {
if ( V_31 >= 0 )
V_31 = - V_36 ;
goto V_37;
}
V_31 = 0 ;
V_55 -> V_32 [ type ] . V_56 = 0xffffffff ;
V_55 -> V_32 [ type ] . V_57 = 0xffffffff ;
V_55 -> V_32 [ type ] . V_34 =
V_20 . V_16 ? V_20 . V_16 : V_58 ;
V_55 -> V_32 [ type ] . V_33 =
V_20 . V_17 ? V_20 . V_17 : V_59 ;
V_37:
return V_31 ;
}
static int F_17 ( struct V_39 * V_40 , int type )
{
struct V_54 * V_55 = F_6 ( V_40 ) ;
struct V_7 V_20 ;
int V_31 ;
V_55 -> V_32 [ type ] . V_60 &= ~ V_61 ;
V_31 = V_40 -> V_24 -> V_25 ( V_40 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_31 != sizeof( struct V_7 ) ) {
if ( V_31 >= 0 )
V_31 = - V_36 ;
goto V_37;
}
V_20 . V_16 = V_55 -> V_32 [ type ] . V_34 ;
V_20 . V_17 = V_55 -> V_32 [ type ] . V_33 ;
V_31 = V_40 -> V_24 -> V_35 ( V_40 , type , ( char * ) & V_20 ,
sizeof( struct V_7 ) , F_7 ( 0 ) ) ;
if ( V_31 == sizeof( struct V_7 ) )
V_31 = 0 ;
else if ( V_31 > 0 )
V_31 = - V_36 ;
V_37:
return V_31 ;
}
static int T_7 F_18 ( void )
{
return F_19 ( & V_62 ) ;
}
static void T_8 F_20 ( void )
{
F_21 ( & V_62 ) ;
}
