static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
V_4 -> V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_4 -> V_8 = F_2 ( V_4 -> V_6 + V_9 ) ;
F_3 ( 0x1 , V_4 -> V_6 + V_10 ) ;
return V_11 ;
}
static T_1 F_4 ( int V_1 , void * V_12 )
{
struct V_3 * V_4 = V_12 ;
struct V_13 * V_14 = F_5 ( V_4 ) ;
T_2 V_15 = V_4 -> V_5 & 0xFF ;
T_3 V_16 = 0 ;
struct V_17 * V_18 = NULL ;
F_6 ( V_14 , L_1 ,
V_19 , V_20 , V_4 -> V_5 & 0xFF , V_4 -> V_8 & 0xF ) ;
V_16 = ( V_4 -> V_5 & 0xFF00 ) >> 8 ;
if ( V_16 >= V_21 ) {
F_7 ( V_14 , L_2 ,
V_18 -> V_22 , V_20 , V_16 ) ;
V_18 -> V_23 = true ;
goto V_24;
}
V_18 = V_4 -> V_25 [ V_16 ] ;
if ( ! V_18 )
goto V_24;
switch ( V_15 ) {
case V_26 :
F_6 ( V_14 , L_3 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = false ;
break;
case V_27 :
F_6 ( V_14 , L_4 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = false ;
break;
case V_28 :
F_6 ( V_14 , L_5 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = false ;
break;
case V_29 :
F_7 ( V_14 , L_6 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = true ;
break;
case V_30 :
F_7 ( V_14 , L_7 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = true ;
break;
case V_31 :
F_7 ( V_14 , L_8 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = true ;
break;
case V_32 :
F_7 ( V_14 , L_9 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = true ;
break;
case V_33 :
F_7 ( V_14 , L_10 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = true ;
break;
case V_34 :
F_7 ( V_14 , L_11 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = true ;
break;
default:
F_7 ( V_14 , L_12 ,
V_18 -> V_22 , V_20 ) ;
V_18 -> V_23 = true ;
break;
}
V_24:
F_8 ( & V_4 -> V_35 ) ;
return V_36 ;
}
static T_1 F_9 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
V_4 -> V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_4 -> V_8 = F_2 ( V_4 -> V_6 + V_9 ) ;
V_4 -> V_37 = F_2 ( V_4 -> V_6 + V_38 ) ;
V_4 -> V_39 = F_2 ( V_4 -> V_6 + V_40 ) ;
V_4 -> V_41 = F_2 ( V_4 -> V_6 +
V_42 ) ;
F_3 ( 0x1 , V_4 -> V_6 + V_10 ) ;
return V_11 ;
}
static T_1 F_10 ( int V_1 , void * V_12 )
{
struct V_3 * V_4 = V_12 ;
struct V_13 * V_14 = F_5 ( V_4 ) ;
T_3 V_16 = 0 ;
struct V_17 * V_18 ;
F_6 ( V_14 , L_13 ,
V_19 , V_4 -> V_5 & 0xFF , V_4 -> V_8 & 0xF ) ;
V_16 = ( V_4 -> V_5 & 0xFF00 ) >> 8 ;
if ( V_16 >= V_21 ) {
F_7 ( V_14 , L_14 , V_19 ,
V_16 ) ;
goto V_24;
}
V_18 = V_4 -> V_25 [ V_16 ] ;
if ( ! V_18 )
goto V_24;
if ( V_4 -> V_37 ) {
F_7 ( V_14 , L_15 ,
V_18 -> V_22 , V_4 -> V_37 ) ;
V_18 -> V_23 = true ;
}
if ( V_4 -> V_37 ) {
F_7 ( V_14 , L_16 ,
V_18 -> V_22 , V_4 -> V_39 ) ;
V_18 -> V_23 = true ;
}
if ( V_4 -> V_41 ) {
F_7 ( V_14 , L_17 ,
V_18 -> V_22 , V_4 -> V_41 ) ;
V_18 -> V_23 = true ;
}
V_24:
F_8 ( & V_4 -> V_35 ) ;
return V_36 ;
}
static unsigned long int F_11 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_5 ( V_4 ) ;
unsigned long int V_43 ;
if ( F_12 ( V_14 ) < 0 ) {
F_7 ( V_14 , L_18 , V_19 ) ;
F_13 ( & V_4 -> V_44 ) ;
return - V_45 ;
}
V_43 = F_2 ( V_4 -> V_6 + V_46 ) &
V_47 ;
F_14 ( V_14 ) ;
switch ( V_43 ) {
case V_48 :
F_6 ( V_14 , L_19 ,
V_19 , V_43 ) ;
break;
default:
F_7 ( V_14 , L_20 ,
V_19 , V_43 ) ;
V_43 = V_49 ;
break;
}
return V_43 ;
}
int F_15 ( struct V_50 * V_51 , struct V_3 * V_4 )
{
struct V_13 * V_14 = & V_51 -> V_14 ;
struct V_52 * V_6 ;
struct V_52 * V_53 ;
int V_54 ;
F_16 ( ! V_4 ) ;
V_6 = F_17 ( V_51 , V_55 , 0 ) ;
V_4 -> V_6 = F_18 ( V_14 , V_6 ) ;
if ( F_19 ( V_4 -> V_6 ) ) {
F_7 ( V_14 , L_21 , V_19 ) ;
return F_20 ( V_4 -> V_6 ) ;
}
V_53 = F_17 ( V_51 , V_55 , 1 ) ;
if ( F_19 ( V_53 ) ) {
F_7 ( V_14 , L_22 , V_19 ) ;
return F_20 ( V_53 ) ;
}
V_4 -> V_56 = V_53 -> V_57 ;
V_4 -> V_58 = F_21 ( V_53 ) ;
F_22 ( V_14 , L_23 ,
V_19 , V_4 -> V_56 , V_4 -> V_58 ) ;
V_4 -> V_59 = F_23 ( V_14 , L_24 ) ;
if ( F_24 ( V_4 -> V_59 ) ) {
F_7 ( V_14 , L_25 , V_19 ) ;
return F_20 ( V_4 -> V_59 ) ;
}
V_54 = F_25 ( V_4 -> V_59 ) ;
if ( V_54 < 0 ) {
F_7 ( V_14 , L_26 , V_19 ) ;
V_4 -> V_59 = F_26 ( - V_60 ) ;
return V_54 ;
}
V_54 = F_27 ( V_51 , 0 ) ;
if ( V_54 < 0 ) {
F_7 ( V_14 , L_27 , V_19 ) ;
goto V_61;
}
V_4 -> V_62 = V_54 ;
V_54 = F_28 ( V_14 , V_4 -> V_62 , F_1 ,
F_4 ,
V_63 ,
L_28 , V_4 ) ;
if ( V_54 ) {
F_7 ( V_14 , L_29 ,
V_19 , V_4 -> V_62 ) ;
goto V_61;
}
F_29 ( V_4 -> V_62 ) ;
V_54 = F_27 ( V_51 , 1 ) ;
if ( V_54 < 0 ) {
F_7 ( V_14 , L_30 , V_19 ) ;
goto V_61;
}
V_4 -> V_64 = V_54 ;
V_54 = F_28 ( V_14 , V_4 -> V_64 , F_9 ,
F_10 ,
V_63 ,
L_31 , V_4 ) ;
if ( V_54 ) {
F_7 ( V_14 , L_32 ,
V_19 , V_4 -> V_64 ) ;
goto V_61;
}
F_29 ( V_4 -> V_64 ) ;
F_30 ( & V_4 -> V_44 ) ;
F_31 ( & V_4 -> V_35 ) ;
F_32 ( V_14 , V_65 ) ;
F_33 ( V_14 ) ;
F_34 ( V_14 ) ;
F_35 ( V_14 ) ;
V_54 = F_12 ( V_14 ) ;
if ( V_54 < 0 ) {
F_7 ( V_14 , L_33 , V_19 ) ;
goto V_61;
}
V_4 -> V_66 = F_11 ( V_4 ) ;
if ( V_4 -> V_66 == V_49 ) {
V_54 = - V_60 ;
goto V_67;
}
F_22 ( V_14 , L_34 , V_19 ,
V_4 -> V_66 ) ;
return 0 ;
V_67:
F_36 ( V_14 ) ;
V_61:
if ( V_4 -> V_59 )
F_37 ( V_4 -> V_59 ) ;
return V_54 ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_5 ( V_4 ) ;
F_29 ( V_4 -> V_62 ) ;
F_29 ( V_4 -> V_64 ) ;
F_14 ( V_14 ) ;
F_39 ( V_14 ) ;
}
int F_40 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_41 ( V_14 ) ;
F_42 ( V_4 -> V_59 ) ;
return 0 ;
}
int F_43 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_41 ( V_14 ) ;
if ( F_44 ( V_4 -> V_59 ) ) {
F_7 ( V_4 -> V_14 , L_35 ,
V_19 ) ;
return - V_60 ;
}
if ( F_45 ( V_4 -> V_59 , V_68 ) ) {
F_7 ( V_14 , L_36 ,
V_19 ) ;
return - V_60 ;
}
return 0 ;
}
int F_46 ( struct V_17 * V_18 , enum V_69 V_70 ,
struct V_71 * V_72 )
{
struct V_3 * V_4 = F_47 ( V_18 ) ;
struct V_13 * V_14 = F_5 ( V_4 ) ;
T_3 V_73 = V_18 -> V_74 ;
int V_54 ;
T_2 V_75 = 0 ;
F_48 ( & V_4 -> V_44 ) ;
F_49 ( V_4 -> V_62 ) ;
F_49 ( V_4 -> V_64 ) ;
if ( F_12 ( V_14 ) < 0 ) {
F_7 ( V_14 , L_18 , V_18 -> V_22 ) ;
V_54 = - V_45 ;
goto V_24;
}
V_75 = F_2 ( V_4 -> V_6 + V_76 ) ;
switch ( V_70 ) {
case V_77 :
V_75 |= V_78 ;
break;
default:
F_6 ( V_14 , L_37 , V_18 -> V_22 , V_70 ) ;
V_54 = - V_45 ;
goto V_24;
}
F_3 ( V_75 , V_4 -> V_6 + V_76 ) ;
F_6 ( V_14 , L_38 , V_18 -> V_22 ,
V_20 ) ;
F_3 ( V_79 , V_4 -> V_6 + V_80 ) ;
F_3 ( V_81 , V_4 -> V_6 + V_82 ) ;
F_3 ( V_83 , V_4 -> V_6 + V_84 ) ;
F_6 ( V_14 , L_39 ,
V_18 -> V_22 , V_20 , V_70 + ( V_73 << 8 ) , & V_72 -> V_85 ) ;
F_3 ( V_70 + ( V_73 << 8 ) , V_4 -> V_6 + V_86 ) ;
F_3 ( V_72 -> V_85 , V_4 -> V_6 + V_86 ) ;
if ( ! F_50 ( & V_4 -> V_35 ,
F_51 ( 2000 ) ) ) {
F_7 ( V_14 , L_40 , V_18 -> V_22 ,
V_20 ) ;
V_54 = - V_45 ;
goto V_24;
}
V_54 = V_18 -> V_23 ? - V_45 : 0 ;
V_24:
F_29 ( V_4 -> V_62 ) ;
F_29 ( V_4 -> V_64 ) ;
switch ( V_70 ) {
case V_77 :
V_75 &= ~ V_78 ;
F_3 ( V_75 , V_4 -> V_6 + V_76 ) ;
break;
default:
F_6 ( V_14 , L_37 , V_18 -> V_22 , V_70 ) ;
}
F_14 ( V_14 ) ;
F_13 ( & V_4 -> V_44 ) ;
return V_54 ;
}
