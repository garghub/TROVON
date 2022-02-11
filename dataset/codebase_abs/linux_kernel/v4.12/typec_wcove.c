static int F_1 ( struct V_1 * V_2 ,
enum F_1 V_3 , int V_4 )
{
union V_5 * V_6 ;
union V_5 V_7 ;
union V_5 V_8 = F_2 ( 1 , & V_7 ) ;
V_7 . type = V_9 ;
V_7 . integer . V_10 = V_4 ;
V_6 = F_3 ( F_4 ( V_2 -> V_11 ) , V_12 . V_13 , 1 , V_3 ,
& V_8 ) ;
if ( ! V_6 ) {
F_5 ( V_2 -> V_11 , L_1 , V_14 ) ;
return - V_15 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
static T_1 F_7 ( int V_16 , void * V_17 )
{
enum V_18 V_19 = V_20 ;
struct V_21 V_22 ;
struct V_1 * V_2 = V_17 ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int V_28 ;
int V_29 ;
F_8 ( & V_2 -> V_30 ) ;
V_29 = F_9 ( V_2 -> V_31 , V_32 , & V_25 ) ;
if ( V_29 )
goto V_33;
V_29 = F_9 ( V_2 -> V_31 , V_34 , & V_26 ) ;
if ( V_29 )
goto V_33;
V_29 = F_9 ( V_2 -> V_31 , V_35 , & V_27 ) ;
if ( V_29 )
goto V_33;
V_29 = F_9 ( V_2 -> V_31 , V_36 , & V_28 ) ;
if ( V_29 )
goto V_33;
V_29 = F_9 ( V_2 -> V_31 , V_37 , & V_23 ) ;
if ( V_29 )
goto V_33;
V_29 = F_9 ( V_2 -> V_31 , V_38 , & V_24 ) ;
if ( V_29 )
goto V_33;
if ( V_25 ) {
if ( V_25 & V_39 )
F_5 ( V_2 -> V_11 , L_2 ) ;
if ( V_25 & V_40 )
F_5 ( V_2 -> V_11 , L_3 ) ;
V_29 = F_10 ( V_2 -> V_31 , V_32 , V_25 ) ;
if ( V_29 )
goto V_33;
}
if ( V_26 ) {
V_29 = F_10 ( V_2 -> V_31 , V_34 , V_26 ) ;
if ( V_29 )
goto V_33;
if ( V_26 & ~ V_41 ) {
F_11 ( V_2 -> V_11 , L_4 ) ;
goto V_33;
}
}
if ( V_27 & V_42 )
goto V_43;
if ( F_12 ( V_27 ) == V_44 ) {
if ( V_2 -> V_22 ) {
F_13 ( V_2 -> V_22 ) ;
V_2 -> V_22 = NULL ;
}
F_1 ( V_2 , V_45 ,
V_46 ) ;
F_1 ( V_2 , V_47 , V_48 ) ;
F_14 ( V_2 -> V_49 , V_50 ) ;
F_15 ( V_2 -> V_49 , V_20 ) ;
F_16 ( V_2 -> V_49 , V_51 ) ;
goto V_43;
}
if ( V_2 -> V_22 )
goto V_43;
switch ( F_17 ( V_27 ) ) {
case V_52 :
F_1 ( V_2 , V_45 ,
V_46 ) ;
break;
case V_53 :
F_1 ( V_2 , V_45 ,
V_54 ) ;
default:
break;
}
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
switch ( F_12 ( V_27 ) ) {
case V_55 :
F_16 ( V_2 -> V_49 , V_51 ) ;
break;
case V_56 :
F_16 ( V_2 -> V_49 , V_57 ) ;
break;
case V_58 :
F_16 ( V_2 -> V_49 , V_59 ) ;
break;
case V_60 :
V_19 = V_61 ;
break;
case V_62 :
V_22 . V_63 = V_64 ;
break;
case V_65 :
V_22 . V_63 = V_66 ;
break;
default:
F_11 ( V_2 -> V_11 , L_5 , V_14 ) ;
goto V_33;
}
if ( V_19 == V_20 ) {
F_1 ( V_2 , V_47 , V_67 ) ;
F_14 ( V_2 -> V_49 , V_50 ) ;
F_15 ( V_2 -> V_49 , V_20 ) ;
} else {
F_1 ( V_2 , V_47 , V_48 ) ;
F_15 ( V_2 -> V_49 , V_61 ) ;
F_14 ( V_2 -> V_49 , V_68 ) ;
}
V_2 -> V_22 = F_18 ( V_2 -> V_49 , & V_22 ) ;
if ( ! V_2 -> V_22 )
F_5 ( V_2 -> V_11 , L_6 ) ;
V_43:
if ( ( V_23 & V_69 ) ||
( V_24 & V_69 ) )
F_1 ( V_2 , V_70 , true ) ;
else
F_1 ( V_2 , V_70 , false ) ;
F_1 ( V_2 , V_71 ,
! ! ( V_28 & V_72 ) ) ;
V_33:
F_10 ( V_2 -> V_31 , V_73 , F_19 ( 5 ) ) ;
F_20 ( & V_2 -> V_30 ) ;
return V_74 ;
}
static int F_21 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = F_22 ( V_76 -> V_11 . V_79 ) ;
struct V_1 * V_2 ;
unsigned int V_80 ;
int V_29 ;
V_2 = F_23 ( & V_76 -> V_11 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
F_24 ( & V_2 -> V_30 ) ;
V_2 -> V_11 = & V_76 -> V_11 ;
V_2 -> V_31 = V_78 -> V_31 ;
V_29 = F_25 ( V_78 -> V_83 ,
F_26 ( V_76 , 0 ) ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_27 ( & V_76 -> V_11 , V_29 , NULL ,
F_7 , V_84 ,
L_7 , V_2 ) ;
if ( V_29 )
return V_29 ;
if ( ! F_28 ( F_4 ( & V_76 -> V_11 ) , V_12 . V_13 , 0 , 0x1f ) ) {
F_5 ( & V_76 -> V_11 , L_8 ) ;
return - V_85 ;
}
V_2 -> V_86 . type = V_87 ;
V_2 -> V_86 . V_88 = V_89 ;
V_2 -> V_86 . V_90 = V_91 ;
F_9 ( V_2 -> V_31 , V_92 , & V_80 ) ;
F_10 ( V_2 -> V_31 , V_92 , V_80 | V_93 ) ;
F_9 ( V_2 -> V_31 , V_94 , & V_80 ) ;
F_10 ( V_2 -> V_31 , V_94 , F_29 ( V_80 ) ) ;
V_2 -> V_49 = F_30 ( & V_76 -> V_11 , & V_2 -> V_86 ) ;
if ( ! V_2 -> V_49 )
return - V_85 ;
F_9 ( V_2 -> V_31 , V_95 , & V_80 ) ;
F_10 ( V_2 -> V_31 , V_95 , V_80 & ~ V_96 ) ;
F_9 ( V_2 -> V_31 , V_97 , & V_80 ) ;
F_10 ( V_2 -> V_31 , V_97 , V_80 & ~ V_98 ) ;
F_31 ( V_76 , V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_33 ( V_76 ) ;
unsigned int V_80 ;
F_9 ( V_2 -> V_31 , V_95 , & V_80 ) ;
F_10 ( V_2 -> V_31 , V_95 , V_80 | V_96 ) ;
F_9 ( V_2 -> V_31 , V_97 , & V_80 ) ;
F_10 ( V_2 -> V_31 , V_97 , V_80 | V_98 ) ;
F_13 ( V_2 -> V_22 ) ;
F_34 ( V_2 -> V_49 ) ;
return 0 ;
}
