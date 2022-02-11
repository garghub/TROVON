static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_4 , V_5 ) ;
if ( ! V_2 -> V_3 )
return - V_6 ;
V_2 -> V_7 = F_3 ( V_2 ,
V_2 -> V_3 , V_4 ) ;
if ( F_4 ( V_2 -> V_7 ) ) {
F_5 ( V_2 -> V_3 ) ;
F_6 ( & V_2 -> V_8 -> V_9 , L_1 ,
V_10 , __LINE__ , - V_6 ) ;
return - V_6 ;
}
V_2 -> V_11 -> V_12 ( V_2 , V_13 , V_2 -> V_7 ) ;
V_2 -> V_11 -> V_12 ( V_2 , V_14 , V_2 -> V_7 >> 32 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_2 -> V_7 , V_4 ) ;
F_5 ( V_2 -> V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_15 ) {
case V_16 :
V_2 -> V_11 = & V_17 ;
V_2 -> V_18 = & V_19 ;
V_2 -> V_20 = & V_21 ;
break;
default:
break;
}
}
static enum V_22 F_10 ( struct V_23 * V_8 )
{
enum V_22 V_15 ;
switch ( V_8 -> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_15 = V_16 ;
break;
default:
V_15 = V_40 ;
break;
}
return V_15 ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_23 * V_8 )
{
V_2 -> V_8 = V_8 ;
V_2 -> V_15 = F_10 ( V_8 ) ;
V_2 -> V_41 = V_8 -> V_42 ;
F_9 ( V_2 ) ;
F_12 ( & V_2 -> V_43 ) ;
V_2 -> V_44 . V_45 = 0 ;
F_13 ( & V_2 -> V_46 ) ;
}
static int F_14 ( struct V_23 * V_8 ,
const struct V_47 * V_48 )
{
int V_49 ;
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 ) {
V_49 = - V_6 ;
F_6 ( & V_8 -> V_9 , L_2 , V_49 ) ;
goto V_50;
}
V_2 -> V_51 = F_15 ( & V_52 , 0 , V_53 , V_5 ) ;
if ( V_2 -> V_51 < 0 ) {
V_49 = V_2 -> V_51 ;
F_6 ( & V_8 -> V_9 , L_3 , V_49 ) ;
goto V_54;
}
F_11 ( V_2 , V_8 ) ;
V_49 = F_16 ( V_8 ) ;
if ( V_49 ) {
F_6 ( & V_8 -> V_9 , L_4 ) ;
goto V_55;
}
F_17 ( V_8 ) ;
V_49 = F_18 ( V_8 , V_56 ) ;
if ( V_49 ) {
F_6 ( & V_8 -> V_9 , L_5 ) ;
goto V_57;
}
V_49 = F_19 ( V_8 , F_20 ( 64 ) ) ;
if ( V_49 ) {
F_6 ( & V_8 -> V_9 , L_6 ) ;
goto V_58;
}
V_2 -> V_59 . V_60 = F_21 ( V_8 , V_2 -> V_11 -> V_61 ) ;
V_2 -> V_59 . V_62 = F_22 ( V_8 , V_2 -> V_11 -> V_61 ) ;
V_2 -> V_59 . V_63 = F_23 ( V_8 , V_2 -> V_11 -> V_61 ) ;
if ( ! V_2 -> V_59 . V_63 ) {
F_6 ( & V_8 -> V_9 , L_7 ) ;
V_49 = - V_64 ;
goto V_58;
}
V_2 -> V_65 . V_60 = F_21 ( V_8 , V_2 -> V_11 -> V_66 ) ;
V_2 -> V_65 . V_62 = F_22 ( V_8 , V_2 -> V_11 -> V_66 ) ;
V_2 -> V_65 . V_63 = F_24 ( V_2 -> V_65 . V_60 , V_2 -> V_65 . V_62 ) ;
if ( ! V_2 -> V_65 . V_63 ) {
F_6 ( & V_8 -> V_9 , L_8 ) ;
V_49 = - V_64 ;
goto V_67;
}
V_2 -> V_18 -> V_68 ( V_2 ) ;
V_49 = F_25 ( V_2 , V_8 ) ;
if ( V_49 ) {
F_6 ( & V_8 -> V_9 , L_9 , V_49 ) ;
goto V_69;
}
V_49 = F_26 ( V_2 ) ;
if ( V_49 ) {
F_6 ( & V_8 -> V_9 , L_10 , V_49 ) ;
goto V_70;
}
F_27 ( V_8 , V_2 ) ;
V_49 = F_1 ( V_2 ) ;
if ( V_49 ) {
F_6 ( & V_8 -> V_9 , L_11 , V_49 ) ;
goto V_71;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
V_2 -> V_72 . V_73 = V_74 ;
snprintf ( V_2 -> V_75 , sizeof( V_2 -> V_75 ) , L_12 , V_2 -> V_51 ) ;
V_2 -> V_72 . V_75 = V_2 -> V_75 ;
V_2 -> V_72 . V_76 = & V_77 ;
V_2 -> V_72 . V_78 = & V_2 -> V_8 -> V_9 ;
V_49 = F_30 ( & V_2 -> V_72 ) ;
if ( V_49 ) {
F_6 ( & V_8 -> V_9 , L_13 ,
V_2 -> V_51 , V_49 ) ;
goto V_79;
}
V_2 -> V_80 = F_31 ( & V_2 -> V_8 -> V_9 , & V_81 ) ;
if ( F_32 ( V_2 -> V_80 ) ) {
V_49 = F_33 ( V_2 -> V_80 ) ;
F_6 ( & V_8 -> V_9 , L_14 , V_49 ) ;
goto V_82;
}
return 0 ;
V_82:
F_34 ( & V_2 -> V_72 ) ;
V_79:
F_35 ( V_2 ) ;
F_7 ( V_2 ) ;
V_71:
F_36 ( V_2 ) ;
V_70:
F_37 ( V_2 , V_8 ) ;
V_69:
F_38 ( V_2 -> V_65 . V_63 ) ;
V_67:
F_38 ( V_2 -> V_59 . V_63 ) ;
V_58:
F_39 ( V_8 ) ;
V_57:
F_40 ( V_8 ) ;
V_55:
F_41 ( & V_52 , V_2 -> V_51 ) ;
V_54:
F_5 ( V_2 ) ;
V_50:
F_6 ( & V_8 -> V_9 , L_15 , V_49 ) ;
return V_49 ;
}
static void F_42 ( struct V_23 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_8 ) ;
if ( ! V_2 )
return;
F_44 ( V_2 -> V_80 ) ;
F_34 ( & V_2 -> V_72 ) ;
F_35 ( V_2 ) ;
F_7 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 , V_8 ) ;
F_38 ( V_2 -> V_65 . V_63 ) ;
F_38 ( V_2 -> V_59 . V_63 ) ;
F_39 ( V_8 ) ;
F_40 ( V_8 ) ;
F_41 ( & V_52 , V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
}
static int T_1 F_45 ( void )
{
int V_83 ;
V_83 = F_46 ( & V_84 , 0 ,
V_53 , V_56 ) ;
if ( V_83 ) {
F_47 ( L_16 , V_83 ) ;
goto error;
}
F_48 () ;
F_49 ( & V_52 ) ;
V_83 = F_50 ( & V_85 ) ;
if ( V_83 ) {
F_47 ( L_17 , V_83 ) ;
goto V_86;
}
return V_83 ;
V_86:
F_51 ( & V_52 ) ;
F_52 () ;
F_53 ( V_84 , V_53 ) ;
error:
return V_83 ;
}
static void T_2 F_54 ( void )
{
F_55 ( & V_85 ) ;
F_51 ( & V_52 ) ;
F_52 () ;
F_53 ( V_84 , V_53 ) ;
}
