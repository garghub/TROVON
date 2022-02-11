static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
signed char * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_7 ;
int V_8 ;
switch ( V_1 -> V_8 ) {
case 0 :
break;
case - V_9 :
case - V_10 :
case - V_11 :
return;
default:
goto V_12;
}
F_2 ( V_7 , V_13 , V_5 [ 0 ] & 0x01 ) ;
F_2 ( V_7 , V_14 , V_5 [ 0 ] & 0x02 ) ;
F_2 ( V_7 , V_15 , V_5 [ 0 ] & 0x04 ) ;
F_2 ( V_7 , V_16 , V_5 [ 0 ] & 0x08 ) ;
F_2 ( V_7 , V_17 , V_5 [ 0 ] & 0x10 ) ;
F_3 ( V_7 , V_18 , V_5 [ 1 ] ) ;
F_3 ( V_7 , V_19 , V_5 [ 2 ] ) ;
F_3 ( V_7 , V_20 , V_5 [ 3 ] ) ;
F_4 ( V_7 ) ;
V_12:
V_8 = F_5 ( V_1 , V_21 ) ;
if ( V_8 )
F_6 ( L_1 ,
V_3 -> V_22 -> V_23 -> V_24 ,
V_3 -> V_22 -> V_25 , V_8 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
V_3 -> V_26 -> V_7 = V_3 -> V_22 ;
if ( F_5 ( V_3 -> V_26 , V_27 ) )
return - V_28 ;
return 0 ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_8 ( V_7 ) ;
F_10 ( V_3 -> V_26 ) ;
}
static int F_11 ( struct V_29 * V_30 , const struct V_31 * V_32 )
{
struct V_33 * V_7 = F_12 ( V_30 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_2 * V_3 ;
struct V_6 * V_6 ;
int V_38 , V_39 ;
int error = - V_40 ;
V_35 = V_30 -> V_41 ;
if ( V_35 -> V_42 . V_43 != 1 )
return - V_44 ;
V_37 = & V_35 -> V_37 [ 0 ] . V_42 ;
if ( ! F_13 ( V_37 ) )
return - V_44 ;
V_38 = F_14 ( V_7 , V_37 -> V_45 ) ;
V_39 = F_15 ( V_7 , V_38 , F_16 ( V_38 ) ) ;
V_3 = F_17 ( sizeof( struct V_2 ) , V_27 ) ;
V_6 = F_18 () ;
if ( ! V_3 || ! V_6 )
goto V_46;
V_3 -> V_5 = F_19 ( V_7 , 8 , V_21 , & V_3 -> V_47 ) ;
if ( ! V_3 -> V_5 )
goto V_46;
V_3 -> V_26 = F_20 ( 0 , V_27 ) ;
if ( ! V_3 -> V_26 )
goto V_48;
V_3 -> V_22 = V_7 ;
V_3 -> V_7 = V_6 ;
if ( V_7 -> V_49 )
F_21 ( V_3 -> V_50 , V_7 -> V_49 , sizeof( V_3 -> V_50 ) ) ;
if ( V_7 -> V_51 ) {
if ( V_7 -> V_49 )
F_22 ( V_3 -> V_50 , L_2 , sizeof( V_3 -> V_50 ) ) ;
F_22 ( V_3 -> V_50 , V_7 -> V_51 , sizeof( V_3 -> V_50 ) ) ;
}
if ( ! strlen ( V_3 -> V_50 ) )
snprintf ( V_3 -> V_50 , sizeof( V_3 -> V_50 ) ,
L_3 ,
F_23 ( V_7 -> V_52 . V_53 ) ,
F_23 ( V_7 -> V_52 . V_54 ) ) ;
F_24 ( V_7 , V_3 -> V_55 , sizeof( V_3 -> V_55 ) ) ;
F_22 ( V_3 -> V_55 , L_4 , sizeof( V_3 -> V_55 ) ) ;
V_6 -> V_50 = V_3 -> V_50 ;
V_6 -> V_55 = V_3 -> V_55 ;
F_25 ( V_7 , & V_6 -> V_32 ) ;
V_6 -> V_7 . V_56 = & V_30 -> V_7 ;
V_6 -> V_57 [ 0 ] = F_26 ( V_58 ) | F_26 ( V_59 ) ;
V_6 -> V_60 [ F_27 ( V_61 ) ] = F_26 ( V_13 ) |
F_26 ( V_14 ) | F_26 ( V_15 ) ;
V_6 -> V_62 [ 0 ] = F_26 ( V_18 ) | F_26 ( V_19 ) ;
V_6 -> V_60 [ F_27 ( V_61 ) ] |= F_26 ( V_16 ) |
F_26 ( V_17 ) ;
V_6 -> V_62 [ 0 ] |= F_26 ( V_20 ) ;
F_28 ( V_6 , V_3 ) ;
V_6 -> V_63 = F_7 ;
V_6 -> V_64 = F_9 ;
F_29 ( V_3 -> V_26 , V_7 , V_38 , V_3 -> V_5 ,
( V_39 > 8 ? 8 : V_39 ) ,
F_1 , V_3 , V_37 -> V_65 ) ;
V_3 -> V_26 -> V_66 = V_3 -> V_47 ;
V_3 -> V_26 -> V_67 |= V_68 ;
error = F_30 ( V_3 -> V_7 ) ;
if ( error )
goto V_69;
F_31 ( V_30 , V_3 ) ;
return 0 ;
V_69:
F_32 ( V_3 -> V_26 ) ;
V_48:
F_33 ( V_7 , 8 , V_3 -> V_5 , V_3 -> V_47 ) ;
V_46:
F_34 ( V_6 ) ;
F_35 ( V_3 ) ;
return error ;
}
static void F_36 ( struct V_29 * V_30 )
{
struct V_2 * V_3 = F_37 ( V_30 ) ;
F_31 ( V_30 , NULL ) ;
if ( V_3 ) {
F_10 ( V_3 -> V_26 ) ;
F_38 ( V_3 -> V_7 ) ;
F_32 ( V_3 -> V_26 ) ;
F_33 ( F_12 ( V_30 ) , 8 , V_3 -> V_5 , V_3 -> V_47 ) ;
F_35 ( V_3 ) ;
}
}
static int T_1 F_39 ( void )
{
int V_70 = F_40 ( & V_71 ) ;
if ( V_70 == 0 )
F_41 (KERN_INFO KBUILD_MODNAME L_5 DRIVER_VERSION L_6
DRIVER_DESC L_7 ) ;
return V_70 ;
}
static void T_2 F_42 ( void )
{
F_43 ( & V_71 ) ;
}
