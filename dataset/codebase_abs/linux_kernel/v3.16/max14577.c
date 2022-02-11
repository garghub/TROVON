static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return true ;
default:
break;
}
return false ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( F_1 ( V_2 , V_3 ) )
return true ;
switch ( V_3 ) {
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 ... V_11 :
case V_12 :
case V_13 :
case V_14 :
return true ;
default:
break;
}
return false ;
}
static void F_3 ( struct V_15 * V_15 )
{
T_1 V_16 , V_17 , V_18 ;
int V_19 ;
V_19 = F_4 ( V_15 -> V_20 , V_21 ,
& V_16 ) ;
if ( V_19 ) {
F_5 ( V_15 -> V_2 ,
L_1 , V_19 ) ;
return;
}
V_17 = ( ( V_16 & V_22 ) >>
V_23 ) ;
V_18 = ( ( V_16 & V_24 ) >>
V_25 ) ;
F_6 ( V_15 -> V_2 , L_2 ,
V_15 -> V_26 , V_18 , V_17 ) ;
}
static int F_7 ( struct V_15 * V_15 )
{
int V_19 ;
T_1 V_27 ;
V_15 -> V_28 = F_8 ( V_15 -> V_29 -> V_30 ,
V_31 ) ;
if ( ! V_15 -> V_28 ) {
F_5 ( V_15 -> V_2 , L_3 ) ;
return - V_32 ;
}
F_9 ( V_15 -> V_28 , V_15 ) ;
V_15 -> V_33 = F_10 ( V_15 -> V_28 ,
& V_34 ) ;
if ( F_11 ( V_15 -> V_33 ) ) {
V_19 = F_12 ( V_15 -> V_33 ) ;
F_5 ( V_15 -> V_2 , L_4 ,
V_19 ) ;
goto V_35;
}
V_19 = F_4 ( V_15 -> V_33 ,
V_36 , & V_27 ) ;
if ( V_19 < 0 ) {
F_5 ( V_15 -> V_2 , L_5 ) ;
goto V_35;
}
V_27 &= ~ ( V_37 ) ;
V_27 &= ~ ( V_38 ) ;
V_19 = F_13 ( V_15 -> V_33 ,
V_36 , V_27 ) ;
if ( V_19 < 0 ) {
F_5 ( V_15 -> V_2 , L_6 ) ;
goto V_35;
}
V_19 = F_14 ( V_15 -> V_33 , V_15 -> V_39 ,
V_40 | V_41 | V_42 ,
0 , & V_43 ,
& V_15 -> V_44 ) ;
if ( V_19 != 0 ) {
F_5 ( V_15 -> V_2 , L_7 ,
V_15 -> V_39 , V_19 ) ;
goto V_35;
}
return 0 ;
V_35:
F_15 ( V_15 -> V_28 ) ;
return V_19 ;
}
static void F_16 ( struct V_15 * V_15 )
{
F_17 ( V_15 -> V_39 , V_15 -> V_44 ) ;
F_15 ( V_15 -> V_28 ) ;
}
static int F_18 ( struct V_45 * V_29 ,
const struct V_46 * V_47 )
{
struct V_15 * V_15 ;
struct V_48 * V_49 = F_19 ( & V_29 -> V_2 ) ;
struct V_50 * V_51 = V_29 -> V_2 . V_52 ;
int V_19 = 0 ;
const struct V_53 * V_54 ;
const struct V_55 * V_56 ;
unsigned int V_57 ;
int V_58 ;
if ( V_51 ) {
V_49 = F_20 ( & V_29 -> V_2 , sizeof( * V_49 ) , V_59 ) ;
if ( ! V_49 )
return - V_60 ;
V_29 -> V_2 . V_61 = V_49 ;
}
if ( ! V_49 ) {
F_5 ( & V_29 -> V_2 , L_8 ) ;
return - V_62 ;
}
V_15 = F_20 ( & V_29 -> V_2 , sizeof( * V_15 ) , V_59 ) ;
if ( ! V_15 )
return - V_60 ;
F_9 ( V_29 , V_15 ) ;
V_15 -> V_2 = & V_29 -> V_2 ;
V_15 -> V_29 = V_29 ;
V_15 -> V_39 = V_29 -> V_39 ;
V_15 -> V_20 = F_10 ( V_29 ,
& V_63 ) ;
if ( F_11 ( V_15 -> V_20 ) ) {
V_19 = F_12 ( V_15 -> V_20 ) ;
F_5 ( V_15 -> V_2 , L_9 ,
V_19 ) ;
return V_19 ;
}
if ( V_51 ) {
const struct V_64 * V_65 ;
V_65 = F_21 ( V_66 , & V_29 -> V_2 ) ;
if ( V_65 )
V_15 -> V_26 =
(enum V_67 ) V_65 -> V_68 ;
} else {
V_15 -> V_26 = V_47 -> V_69 ;
}
F_3 ( V_15 ) ;
switch ( V_15 -> V_26 ) {
case V_70 :
V_54 = & V_71 ;
V_56 = V_72 ;
V_57 = F_22 ( V_72 ) ;
V_58 = V_40 | V_41 | V_42 ;
break;
case V_73 :
default:
V_54 = & V_74 ;
V_56 = V_75 ;
V_57 = F_22 ( V_75 ) ;
V_58 = V_40 | V_41 ;
break;
}
V_19 = F_14 ( V_15 -> V_20 , V_15 -> V_39 ,
V_58 , 0 , V_54 ,
& V_15 -> V_76 ) ;
if ( V_19 != 0 ) {
F_5 ( & V_29 -> V_2 , L_10 ,
V_15 -> V_39 , V_19 ) ;
return V_19 ;
}
if ( V_15 -> V_26 == V_70 ) {
V_19 = F_7 ( V_15 ) ;
if ( V_19 < 0 )
goto V_77;
}
V_19 = F_23 ( V_15 -> V_2 , - 1 , V_56 ,
V_57 , NULL , 0 ,
F_24 ( V_15 -> V_76 ) ) ;
if ( V_19 < 0 )
goto V_78;
F_25 ( V_15 -> V_2 , 1 ) ;
return 0 ;
V_78:
if ( V_15 -> V_26 == V_70 )
F_16 ( V_15 ) ;
V_77:
F_17 ( V_15 -> V_39 , V_15 -> V_76 ) ;
return V_19 ;
}
static int F_26 ( struct V_45 * V_29 )
{
struct V_15 * V_15 = F_27 ( V_29 ) ;
F_28 ( V_15 -> V_2 ) ;
F_17 ( V_15 -> V_39 , V_15 -> V_76 ) ;
if ( V_15 -> V_26 == V_70 )
F_16 ( V_15 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_45 * V_29 = F_30 ( V_2 , struct V_45 , V_2 ) ;
struct V_15 * V_15 = F_27 ( V_29 ) ;
if ( F_31 ( V_2 ) )
F_32 ( V_15 -> V_39 ) ;
F_33 ( V_15 -> V_39 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_45 * V_29 = F_30 ( V_2 , struct V_45 , V_2 ) ;
struct V_15 * V_15 = F_27 ( V_29 ) ;
if ( F_31 ( V_2 ) )
F_35 ( V_15 -> V_39 ) ;
F_36 ( V_15 -> V_39 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
F_38 ( F_22 ( V_79 ) != V_80 ) ;
F_38 ( F_22 ( V_66 ) != V_80 ) ;
return F_39 ( & V_81 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_81 ) ;
}
