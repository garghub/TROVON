static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
return false ;
default:
return true ;
}
}
static void F_3 ( struct V_20 * V_21 )
{
F_4 ( V_21 -> V_22 ,
V_23 ,
V_24 ,
V_24 ) ;
F_4 ( V_21 -> V_22 ,
V_25 ,
V_26 ,
V_26 ) ;
if ( ! V_21 -> V_27 ) {
F_4 ( V_21 -> V_22 ,
V_23 ,
V_28 ,
V_21 -> V_29 ) ;
F_4 ( V_21 -> V_22 ,
V_25 ,
V_30 ,
V_21 -> V_31 ) ;
} else {
F_4 ( V_21 -> V_22 ,
V_32 ,
V_33 ,
V_33 ) ;
F_4 ( V_21 -> V_22 ,
V_34 ,
V_35 ,
V_21 -> V_29 ) ;
}
}
static int F_5 ( struct V_36 * V_37 ,
unsigned int V_38 )
{
struct V_39 * V_40 = V_37 -> V_40 ;
struct V_20 * V_21 = F_6 ( V_40 ) ;
unsigned int V_41 = 0 ;
F_7 ( V_40 -> V_2 , L_1 , V_42 , V_38 ) ;
switch ( V_38 & V_43 ) {
case V_44 :
F_3 ( V_21 ) ;
break;
default:
F_8 ( V_40 -> V_2 , L_2 ) ;
return - V_45 ;
}
switch ( V_38 & V_46 ) {
case V_47 :
break;
case V_48 :
V_41 = V_49 ;
break;
case V_50 :
V_41 = V_51 ;
break;
case V_52 :
V_41 = V_51 | V_49 ;
break;
default:
F_8 ( V_40 -> V_2 , L_3 ) ;
return - V_45 ;
}
F_9 ( V_21 -> V_22 ,
V_32 , V_53 ) ;
F_4 ( V_21 -> V_22 , V_32 ,
V_51 , V_41 ) ;
return 0 ;
}
static int F_10 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_36 * V_58 )
{
int V_59 = - V_45 ;
int V_60 = F_11 ( V_57 ) , V_61 ;
struct V_39 * V_40 = V_58 -> V_40 ;
struct V_20 * V_21 = F_6 ( V_40 ) ;
int V_62 ;
switch ( F_12 ( V_57 ) ) {
case V_63 :
F_4 ( V_21 -> V_22 ,
V_32 ,
V_64 ,
V_65 ) ;
V_21 -> V_66 = 16 ;
break;
case V_67 :
F_4 ( V_21 -> V_22 ,
V_32 ,
V_64 ,
V_68 ) ;
V_21 -> V_66 = 24 ;
break;
case V_69 :
F_4 ( V_21 -> V_22 ,
V_32 ,
V_64 ,
V_70 ) ;
V_21 -> V_66 = 32 ;
break;
default:
F_7 ( V_40 -> V_2 , L_4 ,
F_12 ( V_57 ) ) ;
return - V_45 ;
}
V_62 = F_13 ( V_57 ) * V_21 -> V_66 ;
switch ( V_62 ) {
case 32 :
F_4 ( V_21 -> V_22 ,
V_71 ,
V_72 ,
V_73 ) ;
break;
case 48 :
F_4 ( V_21 -> V_22 ,
V_71 ,
V_72 ,
V_74 ) ;
break;
case 64 :
F_4 ( V_21 -> V_22 ,
V_71 ,
V_72 ,
V_75 ) ;
break;
default:
return - V_45 ;
}
for ( V_61 = 0 ; V_61 < F_14 ( V_76 ) ; V_61 ++ ) {
if ( V_76 [ V_61 ] . V_60 >= V_60 ) {
V_59 = V_76 [ V_61 ] . V_77 ;
break;
}
}
if ( V_59 < 0 )
return - V_45 ;
F_4 ( V_21 -> V_22 ,
V_71 ,
V_78 , V_59 << V_79 ) ;
return 0 ;
}
static int F_15 ( struct V_39 * V_40 )
{
struct V_20 * V_21 = F_6 ( V_40 ) ;
V_21 -> V_40 = V_40 ;
V_40 -> V_80 = V_21 -> V_22 ;
F_9 ( V_21 -> V_22 , V_81 , 0xF0 ) ;
return 0 ;
}
static int F_16 ( struct V_82 * V_83 ,
const struct V_84 * V_85 )
{
int V_86 , V_3 ;
T_1 V_87 ;
struct V_20 * V_21 ;
V_21 = F_17 ( & V_83 -> V_2 ,
sizeof( * V_21 ) , V_88 ) ;
if ( ! V_21 )
return - V_89 ;
F_18 ( V_83 , V_21 ) ;
V_21 -> V_22 = F_19 ( V_83 , & V_90 ) ;
if ( F_20 ( V_21 -> V_22 ) ) {
V_86 = F_21 ( V_21 -> V_22 ) ;
F_8 ( & V_83 -> V_2 ,
L_5 , V_86 ) ;
goto V_91;
}
if ( F_22 ( V_83 -> V_2 . V_92 , L_6 ) )
V_21 -> V_27 = true ;
if ( ! F_23 ( V_83 -> V_2 . V_92 , L_7 , & V_87 ) ) {
if ( V_87 > V_93 ) {
F_8 ( & V_83 -> V_2 , L_8 ) ;
return - V_45 ;
}
V_21 -> V_29 = V_87 ;
}
if ( ! F_23 ( V_83 -> V_2 . V_92 , L_9 , & V_87 ) ) {
if ( V_87 > V_94 ) {
F_8 ( & V_83 -> V_2 , L_10 ) ;
return - V_45 ;
}
V_21 -> V_31 = V_87 ;
}
V_86 = F_24 ( V_21 -> V_22 ,
V_15 , & V_3 ) ;
if ( V_86 < 0 ) {
F_8 ( & V_83 -> V_2 , L_11 , V_3 ) ;
return V_86 ;
}
V_86 = F_25 ( & V_83 -> V_2 , & V_95 ,
V_96 , F_14 ( V_96 ) ) ;
if ( V_86 < 0 )
F_8 ( & V_83 -> V_2 ,
L_12 , V_86 ) ;
F_26 ( & V_83 -> V_2 , L_13 , V_3 ) ;
V_91:
return V_86 ;
}
static int F_27 ( struct V_82 * V_97 )
{
F_28 ( & V_97 -> V_2 ) ;
return 0 ;
}
