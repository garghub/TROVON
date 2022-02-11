static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_8 :
return false ;
default:
return true ;
}
}
static int F_3 ( struct V_9 * V_10 ,
unsigned int V_11 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
unsigned int V_16 = 0 ;
switch ( V_11 & V_17 ) {
case V_18 :
break;
default:
F_5 ( V_13 -> V_2 , L_1 ) ;
return - V_19 ;
}
switch ( V_11 & V_20 ) {
case V_21 :
V_16 |= 0 ;
break;
case V_22 :
V_16 |= V_23 ;
break;
case V_24 :
V_16 |= V_25 ;
break;
default:
F_5 ( V_13 -> V_2 , L_2 ) ;
return - V_19 ;
}
F_6 ( V_15 -> V_26 , V_27 ,
V_28 , V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
struct V_9 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_34 , V_35 , V_36 = F_8 ( V_32 ) ;
int V_37 = F_9 ( V_32 ) ;
switch ( F_10 ( V_32 ) ) {
case V_38 :
F_6 ( V_15 -> V_26 , V_27 ,
V_39 , V_40 ) ;
V_35 = 8 ;
break;
case V_41 :
F_6 ( V_15 -> V_26 , V_27 ,
V_39 , V_40 ) ;
V_35 = 16 ;
break;
case V_42 :
F_6 ( V_15 -> V_26 , V_27 ,
V_39 , V_43 ) ;
V_35 = 24 ;
break;
case V_44 :
F_6 ( V_15 -> V_26 , V_27 ,
V_39 , V_43 ) ;
V_35 = 32 ;
break;
default:
return - V_19 ;
}
V_34 = V_36 * V_35 ;
switch ( V_34 ) {
case 32 :
F_6 ( V_15 -> V_26 ,
V_45 ,
V_46 , V_47 ) ;
break;
case 48 :
F_6 ( V_15 -> V_26 ,
V_45 ,
V_46 , V_48 ) ;
break;
case 64 :
F_6 ( V_15 -> V_26 ,
V_45 ,
V_46 , V_49 ) ;
break;
default:
return - V_19 ;
}
switch ( V_37 ) {
case 32000 :
F_6 ( V_15 -> V_26 ,
V_50 ,
V_51 , V_52 ) ;
break;
case 44100 :
F_6 ( V_15 -> V_26 ,
V_50 ,
V_51 , V_53 ) ;
break;
case 48000 :
F_6 ( V_15 -> V_26 ,
V_50 ,
V_51 , V_54 ) ;
break;
case 88200 :
F_6 ( V_15 -> V_26 ,
V_50 ,
V_51 , V_55 ) ;
break;
case 96000 :
F_6 ( V_15 -> V_26 ,
V_50 ,
V_51 , V_56 ) ;
break;
default:
return - V_19 ;
}
F_6 ( V_15 -> V_26 , V_57 ,
V_58 , V_59 ) ;
F_6 ( V_15 -> V_26 , V_60 ,
V_61 , V_61 ) ;
return 0 ;
}
static int F_11 ( struct V_62 * V_63 ,
const struct V_64 * V_65 )
{
struct V_14 * V_15 ;
int V_66 , V_3 ;
V_15 = F_12 ( & V_63 -> V_2 ,
sizeof( * V_15 ) , V_67 ) ;
if ( ! V_15 )
return - V_68 ;
F_13 ( V_63 , V_15 ) ;
V_15 -> V_26 = F_14 ( V_63 , & V_69 ) ;
if ( F_15 ( V_15 -> V_26 ) ) {
V_66 = F_16 ( V_15 -> V_26 ) ;
F_5 ( & V_63 -> V_2 ,
L_3 , V_66 ) ;
return V_66 ;
}
V_66 = F_17 ( V_15 -> V_26 , V_7 , & V_3 ) ;
if ( V_66 < 0 ) {
F_18 ( & V_63 -> V_2 , L_4 , V_66 ) ;
return V_66 ;
}
F_18 ( & V_63 -> V_2 , L_5 , V_3 ) ;
V_66 = F_19 ( & V_63 -> V_2 , & V_70 ,
V_71 , F_20 ( V_71 ) ) ;
if ( V_66 < 0 ) {
F_5 ( & V_63 -> V_2 , L_6 , V_66 ) ;
return V_66 ;
}
return V_66 ;
}
static int F_21 ( struct V_62 * V_72 )
{
F_22 ( & V_72 -> V_2 ) ;
return 0 ;
}
