static int F_1 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_9 -> V_10 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_1 V_12 ;
switch ( V_11 & V_13 ) {
case V_14 :
V_12 = V_15 | V_16 ;
break;
case V_17 :
V_12 = V_18 | V_19 ;
break;
case V_20 :
V_12 = V_21 | V_22 ;
break;
case V_23 :
V_12 = V_24 | V_25 ;
break;
default:
F_4 ( V_7 -> V_26 , L_1 ) ;
return - V_27 ;
}
F_5 ( V_9 -> V_28 , V_29 ,
V_30 |
V_31 , V_12 ) ;
switch ( V_11 & V_32 ) {
case V_33 :
V_9 -> V_34 = true ;
break;
case V_35 :
V_9 -> V_34 = false ;
break;
default:
F_4 ( V_7 -> V_26 , L_2 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_6 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_1 * V_40 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
bool V_41 = V_37 -> V_42 == V_43 ;
T_1 V_44 = V_9 -> V_10 / F_7 ( V_39 ) ;
T_1 V_45 , V_46 , V_12 , V_47 ;
if ( V_41 )
V_9 -> V_48 = F_8 ( V_39 ) ;
for ( V_45 = 0 ; V_45 < F_9 ( V_49 ) ; V_45 ++ ) {
if ( V_49 [ V_45 ] . V_44 == V_44 )
break;
}
if ( V_45 == F_9 ( V_49 ) ) {
F_4 ( V_7 -> V_26 , L_3 ) ;
return - V_27 ;
}
V_47 = V_50 ;
V_12 = V_49 [ V_45 ] . V_51 ;
V_46 = V_9 -> V_34 ? V_52 : V_49 [ V_45 ] . V_53 ;
F_5 ( V_9 -> V_28 , V_54 ,
F_10 ( V_41 ) | V_47 ,
F_11 ( V_41 , V_46 ) | V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_40 , int V_55 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_2 V_56 = V_9 -> V_48 ?
~ ( ( 0x1 << V_9 -> V_48 ) - 1 ) : 0 ;
F_13 ( V_9 -> V_28 , V_57 ,
V_55 ? V_58 : V_56 ) ;
return 0 ;
}
static bool F_14 ( struct V_59 * V_26 , unsigned int V_60 )
{
switch ( V_60 ) {
case V_61 :
return true ;
default:
return false ;
}
}
static bool F_15 ( struct V_59 * V_26 , unsigned int V_60 )
{
switch ( V_60 ) {
case V_62 :
case V_61 :
return false ;
default:
return true ;
}
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_63 * V_64 = F_17 ( V_7 ) ;
switch ( V_9 -> V_65 -> V_66 ) {
case 3 :
F_18 ( V_7 , V_67 ,
F_9 ( V_67 ) ) ;
F_19 ( V_64 , V_68 ,
F_9 ( V_68 ) ) ;
F_20 ( V_64 , V_69 ,
F_9 ( V_69 ) ) ;
break;
default:
break;
}
F_13 ( V_9 -> V_28 , V_57 , V_58 ) ;
return 0 ;
}
int F_21 ( struct V_59 * V_26 , struct V_28 * V_28 )
{
const struct V_70 * V_71 ;
struct V_8 * V_9 ;
int V_72 , V_12 , V_45 ;
if ( F_22 ( V_28 ) ) {
V_72 = F_23 ( V_28 ) ;
F_4 ( V_26 , L_4 , V_72 ) ;
return V_72 ;
}
V_9 = F_24 ( V_26 , sizeof( * V_9 ) , V_73 ) ;
if ( V_9 == NULL )
return - V_74 ;
V_9 -> V_28 = V_28 ;
F_25 ( V_26 , V_9 ) ;
V_71 = F_26 ( V_75 , V_26 ) ;
if ( V_71 )
V_9 -> V_65 = V_71 -> V_76 ;
if ( ! V_9 -> V_65 ) {
F_4 ( V_26 , L_5 ) ;
return - V_27 ;
}
V_9 -> V_77 = F_27 ( V_26 , L_6 ) ;
if ( F_22 ( V_9 -> V_77 ) ) {
F_4 ( V_26 , L_7 ,
F_23 ( V_9 -> V_77 ) ) ;
return - V_27 ;
}
V_9 -> V_10 = F_28 ( V_9 -> V_77 ) ;
for ( V_45 = 0 ; V_45 < F_9 ( V_9 -> V_78 ) ; V_45 ++ )
V_9 -> V_78 [ V_45 ] . V_79 = V_80 [ V_45 ] ;
V_72 = F_29 ( V_26 ,
F_9 ( V_9 -> V_78 ) , V_9 -> V_78 ) ;
if ( V_72 ) {
F_4 ( V_26 , L_8 , V_72 ) ;
return V_72 ;
}
V_72 = F_30 ( F_9 ( V_9 -> V_78 ) ,
V_9 -> V_78 ) ;
if ( V_72 ) {
F_4 ( V_26 , L_9 , V_72 ) ;
return V_72 ;
}
F_31 ( 5 ) ;
V_72 = F_32 ( V_9 -> V_28 , V_62 , & V_12 ) ;
if ( V_72 < 0 ) {
F_4 ( V_26 , L_10 , V_72 ) ;
goto V_81;
}
if ( ( ( V_12 & V_82 ) >> 4 ) != 0x00 ) {
F_4 ( V_26 , L_11 ,
( V_12 & V_82 ) >> 4 ) ;
V_72 = - V_27 ;
goto V_81;
}
F_33 ( V_26 , L_12 ,
V_12 & V_83 ) ;
V_84 . V_85 = V_9 -> V_65 -> V_85 ;
V_84 . V_86 . V_87 = V_9 -> V_65 -> V_66 * 2 ;
V_72 = F_34 ( V_26 , & V_88 , & V_84 , 1 ) ;
if ( V_72 ) {
F_4 ( V_26 , L_13 , V_72 ) ;
goto V_81;
}
F_35 ( V_9 -> V_28 , true ) ;
V_81:
F_36 ( F_9 ( V_9 -> V_78 ) ,
V_9 -> V_78 ) ;
return V_72 ;
}
static int F_37 ( struct V_59 * V_26 )
{
struct V_8 * V_9 = F_38 ( V_26 ) ;
int V_72 ;
V_72 = F_39 ( V_9 -> V_77 ) ;
if ( V_72 ) {
F_4 ( V_26 , L_14 , V_72 ) ;
return V_72 ;
}
V_72 = F_30 ( F_9 ( V_9 -> V_78 ) ,
V_9 -> V_78 ) ;
if ( V_72 ) {
F_4 ( V_26 , L_9 , V_72 ) ;
goto V_89;
}
F_31 ( 5 ) ;
F_35 ( V_9 -> V_28 , false ) ;
V_72 = F_40 ( V_9 -> V_28 ) ;
if ( V_72 ) {
F_4 ( V_26 , L_15 , V_72 ) ;
goto V_90;
}
return 0 ;
V_90:
F_36 ( F_9 ( V_9 -> V_78 ) ,
V_9 -> V_78 ) ;
V_89:
F_41 ( V_9 -> V_77 ) ;
return V_72 ;
}
static int F_42 ( struct V_59 * V_26 )
{
struct V_8 * V_9 = F_38 ( V_26 ) ;
F_35 ( V_9 -> V_28 , true ) ;
F_36 ( F_9 ( V_9 -> V_78 ) ,
V_9 -> V_78 ) ;
F_41 ( V_9 -> V_77 ) ;
return 0 ;
}
