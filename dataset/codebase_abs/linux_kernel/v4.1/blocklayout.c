static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( sizeof( struct V_5 ) +
sizeof( struct V_7 ) , V_9 ) ;
if ( ! V_6 )
return - V_10 ;
V_4 -> V_11 = V_6 ;
V_6 -> V_12 = 1 ;
V_8 = & V_6 -> V_13 [ 0 ] ;
V_8 -> type = V_14 ;
V_8 -> V_15 . V_16 = V_17 ;
return V_2 -> V_18 -> V_19 ( V_2 , V_8 -> V_15 . V_20 , & V_8 -> V_15 . V_16 ,
& V_8 -> V_15 . V_21 ) ;
}
static T_1
F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_22 != V_2 -> V_22 -> V_23 )
return V_24 ;
return F_4 ( F_1 ( V_2 , V_4 ) ) ;
}
static T_1
F_5 ( struct V_25 * V_25 , const struct V_26 * V_27 ,
struct V_28 * args )
{
struct V_29 * V_30 = & args -> V_31 ;
struct V_1 * V_2 = V_25 -> V_32 ;
T_2 V_33 = ( 1 << V_25 -> V_34 ) ;
struct V_35 * V_36 ;
struct V_37 V_37 ;
T_2 V_38 = 0 ;
int error ;
if ( args -> V_39 < V_33 ) {
F_6 ( L_1 ) ;
goto V_40;
}
if ( V_30 -> V_21 & ( V_33 - 1 ) ) {
F_6 ( L_2 ) ;
goto V_40;
}
error = - V_10 ;
V_36 = F_2 ( sizeof( * V_36 ) , V_9 ) ;
if ( ! V_36 )
goto V_41;
args -> V_42 = V_36 ;
error = V_2 -> V_18 -> V_43 ( V_25 , V_30 -> V_21 , V_30 -> V_44 ,
& V_37 , V_30 -> V_45 != V_46 ,
& V_38 ) ;
if ( error ) {
if ( error == - V_47 )
goto V_40;
goto V_41;
}
if ( V_37 . V_44 < args -> V_39 ) {
F_6 ( L_3 ) ;
goto V_40;
}
switch ( V_37 . type ) {
case V_48 :
if ( V_30 -> V_45 == V_46 )
V_36 -> V_49 = V_50 ;
else
V_36 -> V_49 = V_51 ;
V_36 -> V_52 = ( V_37 . V_53 << 9 ) ;
break;
case V_54 :
if ( V_30 -> V_45 & V_55 ) {
if ( args -> V_39 == 0 ) {
F_6 ( L_4 ) ;
goto V_40;
}
V_36 -> V_49 = V_56 ;
V_36 -> V_52 = ( V_37 . V_53 << 9 ) ;
break;
}
case V_57 :
if ( V_30 -> V_45 == V_46 ) {
V_36 -> V_49 = V_58 ;
break;
}
case V_59 :
default:
F_7 ( 1 , L_5 , V_37 . type ) ;
goto V_40;
}
error = F_8 ( & V_36 -> V_60 , V_27 , V_38 ) ;
if ( error )
goto V_41;
V_36 -> V_61 = V_37 . V_21 ;
V_36 -> V_62 = V_37 . V_44 ;
V_30 -> V_21 = V_37 . V_21 ;
V_30 -> V_44 = V_37 . V_44 ;
F_6 ( L_6 , V_36 -> V_61 , V_36 -> V_62 , V_36 -> V_49 ) ;
return 0 ;
V_41:
V_30 -> V_44 = 0 ;
return F_4 ( error ) ;
V_40:
V_30 -> V_44 = 0 ;
return V_63 ;
}
static T_1
F_9 ( struct V_25 * V_25 ,
struct V_64 * V_65 )
{
T_3 V_66 = V_65 -> V_67 + 1 ;
struct V_68 V_68 = { . V_69 = 0 } ;
struct V_37 * V_70 ;
int V_71 ;
int error ;
V_71 = F_10 ( V_65 -> V_72 ,
V_65 -> V_73 , & V_70 , 1 << V_25 -> V_34 ) ;
if ( V_71 < 0 )
return F_4 ( V_71 ) ;
if ( V_65 -> V_74 . V_75 == V_76 ||
F_11 ( & V_65 -> V_74 , & V_25 -> V_77 ) < 0 )
V_65 -> V_74 = F_12 ( V_25 -> V_32 ) ;
V_68 . V_69 |= V_78 | V_79 | V_80 ;
V_68 . V_81 = V_68 . V_82 = V_68 . V_83 = V_65 -> V_74 ;
if ( V_66 > F_13 ( V_25 ) ) {
V_68 . V_69 |= V_84 ;
V_68 . V_85 = V_66 ;
}
error = V_25 -> V_32 -> V_18 -> V_86 ( V_25 , V_70 ,
V_71 , & V_68 ) ;
F_14 ( V_70 ) ;
return F_4 ( error ) ;
}
