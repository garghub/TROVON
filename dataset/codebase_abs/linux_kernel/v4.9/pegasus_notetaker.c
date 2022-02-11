static int F_1 ( struct V_1 * V_1 , T_1 * V_2 , int V_3 )
{
const int V_4 = V_3 + 2 ;
int V_5 ;
int error ;
T_1 * V_6 ;
V_6 = F_2 ( V_4 , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_6 [ 0 ] = V_9 ;
V_6 [ 1 ] = V_3 ;
memcpy ( V_6 + 2 , V_2 , V_3 ) ;
V_5 = F_3 ( V_1 -> V_10 ,
F_4 ( V_1 -> V_10 , 0 ) ,
V_11 ,
V_12 | V_13 ,
0 , 0 , V_6 , V_4 ,
V_14 ) ;
F_5 ( V_6 ) ;
if ( F_6 ( V_5 != V_4 ) ) {
error = V_5 < 0 ? V_5 : - V_15 ;
F_7 ( & V_1 -> V_10 -> V_16 , L_1 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , T_1 V_17 , T_1 V_18 )
{
T_1 V_19 [] = { V_20 , V_21 , V_18 , V_17 } ;
return F_1 ( V_1 , V_19 , sizeof( V_19 ) ) ;
}
static void F_9 ( struct V_1 * V_1 )
{
unsigned char * V_2 = V_1 -> V_2 ;
struct V_22 * V_16 = V_1 -> V_16 ;
T_2 V_23 , V_24 ;
switch ( V_2 [ 0 ] ) {
case V_25 :
if ( V_2 [ 1 ] == V_26 )
F_10 ( & V_1 -> V_27 ) ;
break;
case V_28 :
F_11 ( & V_16 -> V_16 , L_2 ) ;
case V_29 :
case V_30 :
V_23 = F_12 ( ( V_31 * ) & V_2 [ 2 ] ) ;
V_24 = F_12 ( ( V_31 * ) & V_2 [ 4 ] ) ;
if ( V_23 == 0 && V_24 == 0 )
break;
F_13 ( V_16 , V_32 , V_2 [ 1 ] & V_33 ) ;
F_13 ( V_16 , V_34 , V_2 [ 1 ] & V_35 ) ;
F_13 ( V_16 , V_36 , 1 ) ;
F_14 ( V_16 , V_37 , ( V_38 ) V_23 ) ;
F_14 ( V_16 , V_39 , V_24 ) ;
F_15 ( V_16 ) ;
break;
default:
F_11 ( & V_1 -> V_10 -> V_16 ,
L_3 ) ;
}
}
static void F_16 ( struct V_40 * V_40 )
{
struct V_1 * V_1 = V_40 -> V_41 ;
struct V_42 * V_16 = V_1 -> V_10 ;
int V_43 ;
switch ( V_40 -> V_44 ) {
case 0 :
F_9 ( V_1 ) ;
F_17 ( V_1 -> V_10 ) ;
break;
case - V_45 :
case - V_46 :
case - V_47 :
F_7 ( & V_16 -> V_16 , L_4 ,
V_48 , V_40 -> V_44 ) ;
return;
default:
F_7 ( & V_16 -> V_16 , L_5 ,
V_48 , V_40 -> V_44 ) ;
break;
}
V_43 = F_18 ( V_40 , V_49 ) ;
if ( V_43 )
F_7 ( & V_16 -> V_16 , L_6 ,
V_48 , V_43 ) ;
}
static void F_19 ( struct V_50 * V_51 )
{
struct V_1 * V_1 = F_20 ( V_51 , struct V_1 , V_27 ) ;
int error ;
error = F_8 ( V_1 , V_52 , V_53 ) ;
if ( error )
F_7 ( & V_1 -> V_10 -> V_16 , L_7 ,
error ) ;
}
static int F_21 ( struct V_22 * V_16 )
{
struct V_1 * V_1 = F_22 ( V_16 ) ;
int error ;
error = F_23 ( V_1 -> V_54 ) ;
if ( error )
return error ;
V_1 -> V_55 -> V_16 = V_1 -> V_10 ;
if ( F_18 ( V_1 -> V_55 , V_7 ) ) {
error = - V_15 ;
goto V_56;
}
error = F_8 ( V_1 , V_52 , V_53 ) ;
if ( error )
goto V_57;
return 0 ;
V_57:
F_24 ( V_1 -> V_55 ) ;
F_25 ( & V_1 -> V_27 ) ;
V_56:
F_26 ( V_1 -> V_54 ) ;
return error ;
}
static void F_27 ( struct V_22 * V_16 )
{
struct V_1 * V_1 = F_22 ( V_16 ) ;
F_24 ( V_1 -> V_55 ) ;
F_25 ( & V_1 -> V_27 ) ;
F_26 ( V_1 -> V_54 ) ;
}
static int F_28 ( struct V_58 * V_54 ,
const struct V_59 * V_60 )
{
struct V_42 * V_16 = F_29 ( V_54 ) ;
struct V_61 * V_62 ;
struct V_1 * V_1 ;
struct V_22 * V_22 ;
int error ;
int V_63 ;
if ( V_54 -> V_64 -> V_65 . V_66 >= 1 )
return - V_67 ;
if ( V_54 -> V_68 [ 0 ] . V_65 . V_69 < 1 ) {
F_7 ( & V_54 -> V_16 , L_8 ) ;
return - V_70 ;
}
V_62 = & V_54 -> V_64 -> V_62 [ 0 ] . V_65 ;
V_1 = F_30 ( sizeof( * V_1 ) , V_7 ) ;
V_22 = F_31 () ;
if ( ! V_1 || ! V_22 ) {
error = - V_8 ;
goto V_71;
}
V_1 -> V_10 = V_16 ;
V_1 -> V_16 = V_22 ;
V_1 -> V_54 = V_54 ;
V_63 = F_32 ( V_16 , V_62 -> V_72 ) ;
V_1 -> V_73 = F_33 ( V_16 , V_63 , F_34 ( V_63 ) ) ;
V_1 -> V_2 = F_35 ( V_16 , V_1 -> V_73 , V_7 ,
& V_1 -> V_74 ) ;
if ( ! V_1 -> V_2 ) {
error = - V_8 ;
goto V_71;
}
V_1 -> V_55 = F_36 ( 0 , V_7 ) ;
if ( ! V_1 -> V_55 ) {
error = - V_8 ;
goto V_75;
}
F_37 ( V_1 -> V_55 , V_16 , V_63 ,
V_1 -> V_2 , V_1 -> V_73 ,
F_16 , V_1 , V_62 -> V_76 ) ;
V_1 -> V_55 -> V_77 = V_1 -> V_74 ;
V_1 -> V_55 -> V_78 |= V_79 ;
if ( V_16 -> V_80 )
F_38 ( V_1 -> V_81 , V_16 -> V_80 ,
sizeof( V_1 -> V_81 ) ) ;
if ( V_16 -> V_82 ) {
if ( V_16 -> V_80 )
F_39 ( V_1 -> V_81 , L_9 , sizeof( V_1 -> V_81 ) ) ;
F_39 ( V_1 -> V_81 , V_16 -> V_82 , sizeof( V_1 -> V_81 ) ) ;
}
if ( ! strlen ( V_1 -> V_81 ) )
snprintf ( V_1 -> V_81 , sizeof( V_1 -> V_81 ) ,
L_10 ,
F_40 ( V_16 -> V_83 . V_84 ) ,
F_40 ( V_16 -> V_83 . V_85 ) ) ;
F_41 ( V_16 , V_1 -> V_86 , sizeof( V_1 -> V_86 ) ) ;
F_39 ( V_1 -> V_86 , L_11 , sizeof( V_1 -> V_86 ) ) ;
F_42 ( & V_1 -> V_27 , F_19 ) ;
F_43 ( V_54 , V_1 ) ;
V_22 -> V_81 = V_1 -> V_81 ;
V_22 -> V_86 = V_1 -> V_86 ;
F_44 ( V_16 , & V_22 -> V_60 ) ;
V_22 -> V_16 . V_87 = & V_54 -> V_16 ;
F_45 ( V_22 , V_1 ) ;
V_22 -> V_88 = F_21 ;
V_22 -> V_89 = F_27 ;
F_46 ( V_90 , V_22 -> V_91 ) ;
F_46 ( V_92 , V_22 -> V_91 ) ;
F_46 ( V_37 , V_22 -> V_93 ) ;
F_46 ( V_39 , V_22 -> V_93 ) ;
F_46 ( V_32 , V_22 -> V_94 ) ;
F_46 ( V_34 , V_22 -> V_94 ) ;
F_46 ( V_36 , V_22 -> V_94 ) ;
F_46 ( V_95 , V_22 -> V_96 ) ;
F_46 ( V_97 , V_22 -> V_96 ) ;
F_47 ( V_22 , V_37 , - 1500 , 1500 , 8 , 0 ) ;
F_47 ( V_22 , V_39 , 1600 , 3000 , 8 , 0 ) ;
error = F_48 ( V_1 -> V_16 ) ;
if ( error )
goto V_98;
return 0 ;
V_98:
F_49 ( V_1 -> V_55 ) ;
V_75:
F_50 ( V_16 , V_1 -> V_73 ,
V_1 -> V_2 , V_1 -> V_74 ) ;
V_71:
F_51 ( V_22 ) ;
F_5 ( V_1 ) ;
F_43 ( V_54 , NULL ) ;
return error ;
}
static void F_52 ( struct V_58 * V_54 )
{
struct V_1 * V_1 = F_53 ( V_54 ) ;
F_54 ( V_1 -> V_16 ) ;
F_49 ( V_1 -> V_55 ) ;
F_50 ( F_29 ( V_54 ) ,
V_1 -> V_73 , V_1 -> V_2 ,
V_1 -> V_74 ) ;
F_5 ( V_1 ) ;
F_43 ( V_54 , NULL ) ;
}
static int F_55 ( struct V_58 * V_54 , T_3 V_99 )
{
struct V_1 * V_1 = F_53 ( V_54 ) ;
F_56 ( & V_1 -> V_16 -> V_100 ) ;
F_24 ( V_1 -> V_55 ) ;
F_25 ( & V_1 -> V_27 ) ;
F_57 ( & V_1 -> V_16 -> V_100 ) ;
return 0 ;
}
static int F_58 ( struct V_58 * V_54 )
{
struct V_1 * V_1 = F_53 ( V_54 ) ;
int V_43 = 0 ;
F_56 ( & V_1 -> V_16 -> V_100 ) ;
if ( V_1 -> V_16 -> V_101 && F_18 ( V_1 -> V_55 , V_102 ) < 0 )
V_43 = - V_15 ;
F_57 ( & V_1 -> V_16 -> V_100 ) ;
return V_43 ;
}
static int F_59 ( struct V_58 * V_54 )
{
struct V_1 * V_1 = F_53 ( V_54 ) ;
int V_43 = 0 ;
F_56 ( & V_1 -> V_16 -> V_100 ) ;
if ( V_1 -> V_16 -> V_101 ) {
V_43 = F_8 ( V_1 , V_52 ,
V_53 ) ;
if ( ! V_43 && F_18 ( V_1 -> V_55 , V_102 ) < 0 )
V_43 = - V_15 ;
}
F_57 ( & V_1 -> V_16 -> V_100 ) ;
return V_43 ;
}
