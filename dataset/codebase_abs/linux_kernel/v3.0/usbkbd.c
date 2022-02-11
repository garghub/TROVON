static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 ;
switch ( V_1 -> V_6 ) {
case 0 :
break;
case - V_7 :
case - V_8 :
case - V_9 :
return;
default:
goto V_10;
}
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
F_2 ( V_3 -> V_11 , V_12 [ V_5 + 224 ] , ( V_3 -> V_13 [ 0 ] >> V_5 ) & 1 ) ;
for ( V_5 = 2 ; V_5 < 8 ; V_5 ++ ) {
if ( V_3 -> V_14 [ V_5 ] > 3 && F_3 ( V_3 -> V_13 + 2 , V_3 -> V_14 [ V_5 ] , 6 ) == V_3 -> V_13 + 8 ) {
if ( V_12 [ V_3 -> V_14 [ V_5 ] ] )
F_2 ( V_3 -> V_11 , V_12 [ V_3 -> V_14 [ V_5 ] ] , 0 ) ;
else
F_4 ( V_1 -> V_11 ,
L_1 ,
V_3 -> V_14 [ V_5 ] ) ;
}
if ( V_3 -> V_13 [ V_5 ] > 3 && F_3 ( V_3 -> V_14 + 2 , V_3 -> V_13 [ V_5 ] , 6 ) == V_3 -> V_14 + 8 ) {
if ( V_12 [ V_3 -> V_13 [ V_5 ] ] )
F_2 ( V_3 -> V_11 , V_12 [ V_3 -> V_13 [ V_5 ] ] , 1 ) ;
else
F_4 ( V_1 -> V_11 ,
L_1 ,
V_3 -> V_13 [ V_5 ] ) ;
}
}
F_5 ( V_3 -> V_11 ) ;
memcpy ( V_3 -> V_14 , V_3 -> V_13 , 8 ) ;
V_10:
V_5 = F_6 ( V_1 , V_15 ) ;
if ( V_5 )
F_7 ( V_1 -> V_11 , L_2 ,
V_3 -> V_16 -> V_17 -> V_18 ,
V_3 -> V_16 -> V_19 , V_5 ) ;
}
static int F_8 ( struct V_20 * V_11 , unsigned int type ,
unsigned int V_21 , int V_22 )
{
struct V_2 * V_3 = F_9 ( V_11 ) ;
if ( type != V_23 )
return - 1 ;
V_3 -> V_24 = ( ! ! F_10 ( V_25 , V_11 -> V_26 ) << 3 ) | ( ! ! F_10 ( V_27 , V_11 -> V_26 ) << 3 ) |
( ! ! F_10 ( V_28 , V_11 -> V_26 ) << 2 ) | ( ! ! F_10 ( V_29 , V_11 -> V_26 ) << 1 ) |
( ! ! F_10 ( V_30 , V_11 -> V_26 ) ) ;
if ( V_3 -> V_26 -> V_6 == - V_31 )
return 0 ;
if ( * ( V_3 -> V_32 ) == V_3 -> V_24 )
return 0 ;
* ( V_3 -> V_32 ) = V_3 -> V_24 ;
V_3 -> V_26 -> V_11 = V_3 -> V_16 ;
if ( F_6 ( V_3 -> V_26 , V_15 ) )
F_11 ( L_3 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
if ( V_1 -> V_6 )
F_13 ( V_1 -> V_11 , L_4 ,
V_1 -> V_6 ) ;
if ( * ( V_3 -> V_32 ) == V_3 -> V_24 )
return;
* ( V_3 -> V_32 ) = V_3 -> V_24 ;
V_3 -> V_26 -> V_11 = V_3 -> V_16 ;
if ( F_6 ( V_3 -> V_26 , V_15 ) )
F_7 ( V_1 -> V_11 , L_3 ) ;
}
static int F_14 ( struct V_20 * V_11 )
{
struct V_2 * V_3 = F_9 ( V_11 ) ;
V_3 -> V_33 -> V_11 = V_3 -> V_16 ;
if ( F_6 ( V_3 -> V_33 , V_34 ) )
return - V_35 ;
return 0 ;
}
static void F_15 ( struct V_20 * V_11 )
{
struct V_2 * V_3 = F_9 ( V_11 ) ;
F_16 ( V_3 -> V_33 ) ;
}
static int F_17 ( struct V_36 * V_11 , struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_33 = F_18 ( 0 , V_34 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_26 = F_18 ( 0 , V_34 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_13 = F_19 ( V_11 , 8 , V_15 , & V_3 -> V_37 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_38 = F_20 ( sizeof( struct V_39 ) , V_34 ) ) )
return - 1 ;
if ( ! ( V_3 -> V_32 = F_19 ( V_11 , 1 , V_15 , & V_3 -> V_40 ) ) )
return - 1 ;
return 0 ;
}
static void F_21 ( struct V_36 * V_11 , struct V_2 * V_3 )
{
F_22 ( V_3 -> V_33 ) ;
F_22 ( V_3 -> V_26 ) ;
F_23 ( V_11 , 8 , V_3 -> V_13 , V_3 -> V_37 ) ;
F_24 ( V_3 -> V_38 ) ;
F_23 ( V_11 , 1 , V_3 -> V_32 , V_3 -> V_40 ) ;
}
static int F_25 ( struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
struct V_36 * V_11 = F_26 ( V_42 ) ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_2 * V_3 ;
struct V_20 * V_20 ;
int V_5 , V_49 , V_50 ;
int error = - V_51 ;
V_46 = V_42 -> V_52 ;
if ( V_46 -> V_53 . V_54 != 1 )
return - V_55 ;
V_48 = & V_46 -> V_48 [ 0 ] . V_53 ;
if ( ! F_27 ( V_48 ) )
return - V_55 ;
V_49 = F_28 ( V_11 , V_48 -> V_56 ) ;
V_50 = F_29 ( V_11 , V_49 , F_30 ( V_49 ) ) ;
V_3 = F_31 ( sizeof( struct V_2 ) , V_34 ) ;
V_20 = F_32 () ;
if ( ! V_3 || ! V_20 )
goto V_57;
if ( F_17 ( V_11 , V_3 ) )
goto V_58;
V_3 -> V_16 = V_11 ;
V_3 -> V_11 = V_20 ;
if ( V_11 -> V_59 )
F_33 ( V_3 -> V_60 , V_11 -> V_59 , sizeof( V_3 -> V_60 ) ) ;
if ( V_11 -> V_61 ) {
if ( V_11 -> V_59 )
F_34 ( V_3 -> V_60 , L_5 , sizeof( V_3 -> V_60 ) ) ;
F_34 ( V_3 -> V_60 , V_11 -> V_61 , sizeof( V_3 -> V_60 ) ) ;
}
if ( ! strlen ( V_3 -> V_60 ) )
snprintf ( V_3 -> V_60 , sizeof( V_3 -> V_60 ) ,
L_6 ,
F_35 ( V_11 -> V_62 . V_63 ) ,
F_35 ( V_11 -> V_62 . V_64 ) ) ;
F_36 ( V_11 , V_3 -> V_65 , sizeof( V_3 -> V_65 ) ) ;
F_34 ( V_3 -> V_65 , L_7 , sizeof( V_3 -> V_65 ) ) ;
V_20 -> V_60 = V_3 -> V_60 ;
V_20 -> V_65 = V_3 -> V_65 ;
F_37 ( V_11 , & V_20 -> V_44 ) ;
V_20 -> V_11 . V_66 = & V_42 -> V_11 ;
F_38 ( V_20 , V_3 ) ;
V_20 -> V_67 [ 0 ] = F_39 ( V_68 ) | F_39 ( V_23 ) |
F_39 ( V_69 ) ;
V_20 -> V_70 [ 0 ] = F_39 ( V_30 ) | F_39 ( V_29 ) |
F_39 ( V_28 ) | F_39 ( V_27 ) |
F_39 ( V_25 ) ;
for ( V_5 = 0 ; V_5 < 255 ; V_5 ++ )
F_40 ( V_12 [ V_5 ] , V_20 -> V_71 ) ;
F_41 ( 0 , V_20 -> V_71 ) ;
V_20 -> V_72 = F_8 ;
V_20 -> V_73 = F_14 ;
V_20 -> V_74 = F_15 ;
F_42 ( V_3 -> V_33 , V_11 , V_49 ,
V_3 -> V_13 , ( V_50 > 8 ? 8 : V_50 ) ,
F_1 , V_3 , V_48 -> V_75 ) ;
V_3 -> V_33 -> V_76 = V_3 -> V_37 ;
V_3 -> V_33 -> V_77 |= V_78 ;
V_3 -> V_38 -> V_79 = V_80 | V_81 ;
V_3 -> V_38 -> V_82 = 0x09 ;
V_3 -> V_38 -> V_83 = F_43 ( 0x200 ) ;
V_3 -> V_38 -> V_84 = F_43 ( V_46 -> V_53 . V_85 ) ;
V_3 -> V_38 -> V_86 = F_43 ( 1 ) ;
F_44 ( V_3 -> V_26 , V_11 , F_45 ( V_11 , 0 ) ,
( void * ) V_3 -> V_38 , V_3 -> V_32 , 1 ,
F_12 , V_3 ) ;
V_3 -> V_26 -> V_76 = V_3 -> V_40 ;
V_3 -> V_26 -> V_77 |= V_78 ;
error = F_46 ( V_3 -> V_11 ) ;
if ( error )
goto V_58;
F_47 ( V_42 , V_3 ) ;
F_48 ( & V_11 -> V_11 , 1 ) ;
return 0 ;
V_58:
F_21 ( V_11 , V_3 ) ;
V_57:
F_49 ( V_20 ) ;
F_24 ( V_3 ) ;
return error ;
}
static void F_50 ( struct V_41 * V_87 )
{
struct V_2 * V_3 = F_51 ( V_87 ) ;
F_47 ( V_87 , NULL ) ;
if ( V_3 ) {
F_16 ( V_3 -> V_33 ) ;
F_52 ( V_3 -> V_11 ) ;
F_21 ( F_26 ( V_87 ) , V_3 ) ;
F_24 ( V_3 ) ;
}
}
static int T_1 F_53 ( void )
{
int V_88 = F_54 ( & V_89 ) ;
if ( V_88 == 0 )
F_55 (KERN_INFO KBUILD_MODNAME L_8 DRIVER_VERSION L_9
DRIVER_DESC L_10 ) ;
return V_88 ;
}
static void T_2 F_56 ( void )
{
F_57 ( & V_89 ) ;
}
