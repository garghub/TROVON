static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_3 -> V_8 ;
int V_9 , V_10 ;
switch ( V_1 -> V_10 ) {
case 0 :
break;
case - V_11 :
case - V_12 :
case - V_13 :
F_2 ( L_1 , V_14 , V_1 -> V_10 ) ;
return;
default:
F_2 ( L_2 , V_14 , V_1 -> V_10 ) ;
goto V_15;
}
V_9 = ( V_5 [ 0 ] & 0x04 ) >> 2 ;
F_3 ( V_7 , V_16 , V_9 ) ;
if ( V_9 ) {
int V_17 = V_5 [ 1 ] | ( V_5 [ 2 ] << 8 ) ;
int V_18 = V_5 [ 3 ] | ( V_5 [ 4 ] << 8 ) ;
int V_19 = V_5 [ 5 ] | ( V_5 [ 6 ] << 8 ) ;
int V_20 = V_5 [ 0 ] & 0x01 ;
int V_21 = ( V_5 [ 0 ] & 0x10 ) >> 4 ;
int V_22 = ( V_5 [ 0 ] & 0x20 ) >> 5 ;
F_4 ( V_7 , V_23 , V_17 ) ;
F_4 ( V_7 , V_24 , V_18 ) ;
F_4 ( V_7 , V_25 , V_19 ) ;
F_3 ( V_7 , V_26 , V_20 ) ;
F_3 ( V_7 , V_27 , V_21 ) ;
F_3 ( V_7 , V_28 , V_22 ) ;
}
F_5 ( V_7 ) ;
V_15:
V_10 = F_6 ( V_1 , V_29 ) ;
if ( V_10 )
F_7 ( L_3 ,
V_3 -> V_30 -> V_31 -> V_32 , V_3 -> V_30 -> V_33 , V_10 ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_9 ( V_7 ) ;
V_3 -> V_34 -> V_7 = V_3 -> V_30 ;
if ( F_6 ( V_3 -> V_34 , V_35 ) )
return - V_36 ;
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_9 ( V_7 ) ;
F_11 ( V_3 -> V_34 ) ;
}
static int F_12 ( struct V_37 * V_38 , const struct V_39 * V_40 )
{
struct V_41 * V_7 = F_13 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_44 ;
struct V_45 * V_46 ;
struct V_2 * V_3 ;
struct V_6 * V_6 ;
int V_47 , V_48 ;
int F_7 ;
if ( V_43 -> V_49 . V_50 != 1 )
return - V_51 ;
V_46 = & V_43 -> V_46 [ 0 ] . V_49 ;
if ( ! F_14 ( V_46 ) )
return - V_51 ;
V_47 = F_15 ( V_7 , V_46 -> V_52 ) ;
V_48 = F_16 ( V_7 , V_47 , F_17 ( V_47 ) ) ;
V_3 = F_18 ( sizeof( struct V_2 ) , V_35 ) ;
V_6 = F_19 () ;
if ( ! V_3 || ! V_6 ) {
F_7 = - V_53 ;
goto V_54;
}
V_3 -> V_5 = F_20 ( V_7 , 8 , V_35 , & V_3 -> V_55 ) ;
if ( ! V_3 -> V_5 ) {
F_7 = - V_53 ;
goto V_54;
}
V_3 -> V_34 = F_21 ( 0 , V_35 ) ;
if ( ! V_3 -> V_34 ) {
F_7 = - V_53 ;
goto V_56;
}
V_3 -> V_30 = V_7 ;
V_3 -> V_8 = V_6 ;
if ( V_7 -> V_57 )
F_22 ( V_3 -> V_58 , V_7 -> V_57 , sizeof( V_3 -> V_58 ) ) ;
if ( V_7 -> V_59 ) {
if ( V_7 -> V_57 )
F_23 ( V_3 -> V_58 , L_4 , sizeof( V_3 -> V_58 ) ) ;
F_23 ( V_3 -> V_58 , V_7 -> V_59 , sizeof( V_3 -> V_58 ) ) ;
}
F_24 ( V_7 , V_3 -> V_60 , sizeof( V_3 -> V_60 ) ) ;
F_23 ( V_3 -> V_60 , L_5 , sizeof( V_3 -> V_60 ) ) ;
V_6 -> V_58 = V_3 -> V_58 ;
V_6 -> V_60 = V_3 -> V_60 ;
F_25 ( V_7 , & V_6 -> V_40 ) ;
V_6 -> V_7 . V_61 = & V_38 -> V_7 ;
F_26 ( V_6 , V_3 ) ;
V_6 -> V_62 = F_8 ;
V_6 -> V_63 = F_10 ;
V_6 -> V_64 [ 0 ] = F_27 ( V_65 ) | F_27 ( V_66 ) ;
V_6 -> V_67 [ F_28 ( V_68 ) ] = F_27 ( V_16 ) |
F_27 ( V_26 ) | F_27 ( V_27 ) |
F_27 ( V_28 ) ;
switch ( V_40 -> V_69 ) {
case 0 :
F_29 ( V_6 , V_23 , 0 , 5000 , 4 , 0 ) ;
F_29 ( V_6 , V_24 , 0 , 3750 , 4 , 0 ) ;
F_29 ( V_6 , V_25 , 0 , 512 , 0 , 0 ) ;
if ( ! strlen ( V_3 -> V_58 ) )
snprintf ( V_3 -> V_58 , sizeof( V_3 -> V_58 ) ,
L_6 ,
F_30 ( V_7 -> V_70 . V_71 ) ,
F_30 ( V_7 -> V_70 . V_72 ) ) ;
break;
case 1 :
F_29 ( V_6 , V_23 , 0 , 53000 , 4 , 0 ) ;
F_29 ( V_6 , V_24 , 0 , 2250 , 4 , 0 ) ;
F_29 ( V_6 , V_25 , 0 , 1024 , 0 , 0 ) ;
if ( ! strlen ( V_3 -> V_58 ) )
snprintf ( V_3 -> V_58 , sizeof( V_3 -> V_58 ) ,
L_7 ,
F_30 ( V_7 -> V_70 . V_71 ) ,
F_30 ( V_7 -> V_70 . V_72 ) ) ;
break;
}
F_31 ( V_3 -> V_34 , V_7 , V_47 ,
V_3 -> V_5 , V_48 > 8 ? 8 : V_48 ,
F_1 , V_3 , V_46 -> V_73 ) ;
V_3 -> V_34 -> V_74 = V_3 -> V_55 ;
V_3 -> V_34 -> V_75 |= V_76 ;
F_7 = F_32 ( V_3 -> V_8 ) ;
if ( F_7 )
goto V_77;
F_33 ( V_38 , V_3 ) ;
return 0 ;
V_77: F_34 ( V_3 -> V_34 ) ;
V_56: F_35 ( V_7 , 8 , V_3 -> V_5 , V_3 -> V_55 ) ;
V_54: F_36 ( V_6 ) ;
F_37 ( V_3 ) ;
return F_7 ;
}
static void F_38 ( struct V_37 * V_38 )
{
struct V_2 * V_3 = F_39 ( V_38 ) ;
F_33 ( V_38 , NULL ) ;
F_40 ( V_3 -> V_8 ) ;
F_34 ( V_3 -> V_34 ) ;
F_35 ( V_3 -> V_30 , 8 , V_3 -> V_5 , V_3 -> V_55 ) ;
F_37 ( V_3 ) ;
}
static int T_1 F_41 ( void )
{
int V_78 = F_42 ( & V_79 ) ;
if ( V_78 == 0 )
F_43 (KERN_INFO KBUILD_MODNAME L_8 DRIVER_VERSION L_9
DRIVER_DESC L_10 ) ;
return V_78 ;
}
static void T_2 F_44 ( void )
{
F_45 ( & V_79 ) ;
}
