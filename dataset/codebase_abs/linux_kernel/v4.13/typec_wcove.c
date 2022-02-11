static int F_1 ( struct V_1 * V_2 ,
enum F_1 V_3 , int V_4 )
{
union V_5 * V_6 ;
union V_5 V_7 ;
union V_5 V_8 = F_2 ( 1 , & V_7 ) ;
V_7 . type = V_9 ;
V_7 . integer . V_10 = V_4 ;
V_6 = F_3 ( F_4 ( V_2 -> V_11 ) , & V_12 , 1 , V_3 ,
& V_8 ) ;
if ( ! V_6 ) {
F_5 ( V_2 -> V_11 , L_1 , V_13 ) ;
return - V_14 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
static T_1 F_7 ( int V_15 , void * V_16 )
{
enum V_17 V_18 = V_19 ;
struct V_20 V_21 ;
struct V_1 * V_2 = V_16 ;
unsigned int V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
int V_28 ;
F_8 ( & V_2 -> V_29 ) ;
V_28 = F_9 ( V_2 -> V_30 , V_31 , & V_24 ) ;
if ( V_28 )
goto V_32;
V_28 = F_9 ( V_2 -> V_30 , V_33 , & V_25 ) ;
if ( V_28 )
goto V_32;
V_28 = F_9 ( V_2 -> V_30 , V_34 , & V_26 ) ;
if ( V_28 )
goto V_32;
V_28 = F_9 ( V_2 -> V_30 , V_35 , & V_27 ) ;
if ( V_28 )
goto V_32;
V_28 = F_9 ( V_2 -> V_30 , V_36 , & V_22 ) ;
if ( V_28 )
goto V_32;
V_28 = F_9 ( V_2 -> V_30 , V_37 , & V_23 ) ;
if ( V_28 )
goto V_32;
if ( V_24 ) {
if ( V_24 & V_38 )
F_5 ( V_2 -> V_11 , L_2 ) ;
if ( V_24 & V_39 )
F_5 ( V_2 -> V_11 , L_3 ) ;
V_28 = F_10 ( V_2 -> V_30 , V_31 , V_24 ) ;
if ( V_28 )
goto V_32;
}
if ( V_25 ) {
V_28 = F_10 ( V_2 -> V_30 , V_33 , V_25 ) ;
if ( V_28 )
goto V_32;
if ( V_25 & ~ V_40 ) {
F_11 ( V_2 -> V_11 , L_4 ) ;
goto V_32;
}
}
if ( V_26 & V_41 )
goto V_42;
if ( F_12 ( V_26 ) == V_43 ) {
if ( V_2 -> V_21 ) {
F_13 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
F_1 ( V_2 , V_44 ,
V_45 ) ;
F_1 ( V_2 , V_46 , V_47 ) ;
F_14 ( V_2 -> V_48 , V_49 ) ;
F_15 ( V_2 -> V_48 , V_19 ) ;
F_16 ( V_2 -> V_48 , V_50 ) ;
goto V_42;
}
if ( V_2 -> V_21 )
goto V_42;
switch ( F_17 ( V_26 ) ) {
case V_51 :
F_1 ( V_2 , V_44 ,
V_45 ) ;
break;
case V_52 :
F_1 ( V_2 , V_44 ,
V_53 ) ;
default:
break;
}
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
switch ( F_12 ( V_26 ) ) {
case V_54 :
F_16 ( V_2 -> V_48 , V_50 ) ;
break;
case V_55 :
F_16 ( V_2 -> V_48 , V_56 ) ;
break;
case V_57 :
F_16 ( V_2 -> V_48 , V_58 ) ;
break;
case V_59 :
V_18 = V_60 ;
break;
case V_61 :
V_21 . V_62 = V_63 ;
break;
case V_64 :
V_21 . V_62 = V_65 ;
break;
default:
F_11 ( V_2 -> V_11 , L_5 , V_13 ) ;
goto V_32;
}
if ( V_18 == V_19 ) {
F_1 ( V_2 , V_46 , V_66 ) ;
F_14 ( V_2 -> V_48 , V_49 ) ;
F_15 ( V_2 -> V_48 , V_19 ) ;
} else {
F_1 ( V_2 , V_46 , V_47 ) ;
F_15 ( V_2 -> V_48 , V_60 ) ;
F_14 ( V_2 -> V_48 , V_67 ) ;
}
V_2 -> V_21 = F_18 ( V_2 -> V_48 , & V_21 ) ;
if ( ! V_2 -> V_21 )
F_5 ( V_2 -> V_11 , L_6 ) ;
V_42:
if ( ( V_22 & V_68 ) ||
( V_23 & V_68 ) )
F_1 ( V_2 , V_69 , true ) ;
else
F_1 ( V_2 , V_69 , false ) ;
F_1 ( V_2 , V_70 ,
! ! ( V_27 & V_71 ) ) ;
V_32:
F_10 ( V_2 -> V_30 , V_72 , F_19 ( 5 ) ) ;
F_20 ( & V_2 -> V_29 ) ;
return V_73 ;
}
static int F_21 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = F_22 ( V_75 -> V_11 . V_78 ) ;
struct V_1 * V_2 ;
unsigned int V_79 ;
int V_28 ;
V_2 = F_23 ( & V_75 -> V_11 , sizeof( * V_2 ) , V_80 ) ;
if ( ! V_2 )
return - V_81 ;
F_24 ( & V_2 -> V_29 ) ;
V_2 -> V_11 = & V_75 -> V_11 ;
V_2 -> V_30 = V_77 -> V_30 ;
V_28 = F_25 ( V_77 -> V_82 ,
F_26 ( V_75 , 0 ) ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_27 ( & V_75 -> V_11 , V_28 , NULL ,
F_7 , V_83 ,
L_7 , V_2 ) ;
if ( V_28 )
return V_28 ;
if ( ! F_28 ( F_4 ( & V_75 -> V_11 ) , & V_12 , 0 , 0x1f ) ) {
F_5 ( & V_75 -> V_11 , L_8 ) ;
return - V_84 ;
}
V_2 -> V_85 . type = V_86 ;
V_2 -> V_85 . V_87 = V_88 ;
V_2 -> V_85 . V_89 = V_90 ;
F_9 ( V_2 -> V_30 , V_91 , & V_79 ) ;
F_10 ( V_2 -> V_30 , V_91 , V_79 | V_92 ) ;
F_9 ( V_2 -> V_30 , V_93 , & V_79 ) ;
F_10 ( V_2 -> V_30 , V_93 , F_29 ( V_79 ) ) ;
V_2 -> V_48 = F_30 ( & V_75 -> V_11 , & V_2 -> V_85 ) ;
if ( ! V_2 -> V_48 )
return - V_84 ;
F_9 ( V_2 -> V_30 , V_94 , & V_79 ) ;
F_10 ( V_2 -> V_30 , V_94 , V_79 & ~ V_95 ) ;
F_9 ( V_2 -> V_30 , V_96 , & V_79 ) ;
F_10 ( V_2 -> V_30 , V_96 , V_79 & ~ V_97 ) ;
F_31 ( V_75 , V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_33 ( V_75 ) ;
unsigned int V_79 ;
F_9 ( V_2 -> V_30 , V_94 , & V_79 ) ;
F_10 ( V_2 -> V_30 , V_94 , V_79 | V_95 ) ;
F_9 ( V_2 -> V_30 , V_96 , & V_79 ) ;
F_10 ( V_2 -> V_30 , V_96 , V_79 | V_97 ) ;
F_13 ( V_2 -> V_21 ) ;
F_34 ( V_2 -> V_48 ) ;
return 0 ;
}
