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
for ( V_45 = 0 ; V_45 < F_8 ( V_48 ) ; V_45 ++ ) {
if ( V_48 [ V_45 ] . V_44 == V_44 )
break;
}
if ( V_45 == F_8 ( V_48 ) ) {
F_4 ( V_7 -> V_26 , L_3 ) ;
return - V_27 ;
}
V_47 = V_49 ;
V_12 = V_48 [ V_45 ] . V_50 ;
V_46 = V_9 -> V_34 ? V_51 : V_48 [ V_45 ] . V_52 ;
F_5 ( V_9 -> V_28 , V_53 ,
F_9 ( V_41 ) | V_47 ,
F_10 ( V_41 , V_46 ) | V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_40 , int V_54 )
{
struct V_6 * V_7 = V_40 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
F_5 ( V_9 -> V_28 , V_55 ,
V_56 , V_54 ? V_56 : 0 ) ;
return 0 ;
}
static bool F_12 ( struct V_57 * V_26 , unsigned int V_58 )
{
switch ( V_58 ) {
case V_59 :
return true ;
default:
return false ;
}
}
static bool F_13 ( struct V_57 * V_26 , unsigned int V_58 )
{
switch ( V_58 ) {
case V_60 :
case V_59 :
return false ;
default:
return true ;
}
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_61 * V_62 = & V_7 -> V_62 ;
switch ( V_9 -> V_63 -> V_64 ) {
case 3 :
F_15 ( V_7 , V_65 ,
F_8 ( V_65 ) ) ;
F_16 ( V_62 , V_66 ,
F_8 ( V_66 ) ) ;
F_17 ( V_62 , V_67 ,
F_8 ( V_67 ) ) ;
break;
default:
break;
}
F_18 ( V_9 -> V_28 , V_55 , V_56 ) ;
return 0 ;
}
int F_19 ( struct V_57 * V_26 , struct V_28 * V_28 )
{
const struct V_68 * V_69 = F_20 ( V_70 , V_26 ) ;
struct V_8 * V_9 ;
int V_71 , V_12 , V_45 ;
V_9 = F_21 ( V_26 , sizeof( * V_9 ) , V_72 ) ;
if ( V_9 == NULL )
return - V_73 ;
F_22 ( V_26 , V_9 ) ;
if ( V_69 )
V_9 -> V_63 = V_69 -> V_74 ;
if ( ! V_9 -> V_63 ) {
F_4 ( V_26 , L_4 ) ;
return - V_27 ;
}
V_9 -> V_75 = F_23 ( V_26 , L_5 ) ;
if ( F_24 ( V_9 -> V_75 ) ) {
F_4 ( V_26 , L_6 ,
F_25 ( V_9 -> V_75 ) ) ;
return - V_27 ;
}
V_9 -> V_10 = F_26 ( V_9 -> V_75 ) ;
for ( V_45 = 0 ; V_45 < F_8 ( V_9 -> V_76 ) ; V_45 ++ )
V_9 -> V_76 [ V_45 ] . V_77 = V_78 [ V_45 ] ;
V_71 = F_27 ( V_26 ,
F_8 ( V_9 -> V_76 ) , V_9 -> V_76 ) ;
if ( V_71 ) {
F_4 ( V_26 , L_7 , V_71 ) ;
return V_71 ;
}
V_71 = F_28 ( F_8 ( V_9 -> V_76 ) ,
V_9 -> V_76 ) ;
if ( V_71 ) {
F_4 ( V_26 , L_8 , V_71 ) ;
return V_71 ;
}
F_29 ( 5 ) ;
V_9 -> V_28 = V_28 ;
if ( F_24 ( V_9 -> V_28 ) ) {
V_71 = F_25 ( V_9 -> V_28 ) ;
F_4 ( V_26 , L_9 , V_71 ) ;
goto V_79;
}
F_30 ( V_9 -> V_28 , true ) ;
V_71 = F_31 ( V_9 -> V_28 , V_60 , & V_12 ) ;
if ( V_71 < 0 ) {
F_4 ( V_26 , L_10 , V_71 ) ;
goto V_79;
}
if ( ( ( V_12 & V_80 ) >> 4 ) != 0x00 ) {
F_4 ( V_26 , L_11 ,
( V_12 & V_80 ) >> 4 ) ;
V_71 = - V_27 ;
goto V_79;
}
F_32 ( V_26 , L_12 ,
V_12 & V_81 ) ;
F_30 ( V_9 -> V_28 , false ) ;
V_82 . V_83 = V_9 -> V_63 -> V_83 ;
V_82 . V_84 . V_85 = V_9 -> V_63 -> V_64 * 2 ;
V_71 = F_33 ( V_26 , & V_86 , & V_82 , 1 ) ;
if ( V_71 ) {
F_4 ( V_26 , L_13 , V_71 ) ;
goto V_79;
}
F_34 ( V_9 -> V_28 , true ) ;
V_79:
F_35 ( F_8 ( V_9 -> V_76 ) ,
V_9 -> V_76 ) ;
return V_71 ;
}
static int F_36 ( struct V_57 * V_26 )
{
struct V_8 * V_9 = F_37 ( V_26 ) ;
int V_71 ;
V_71 = F_38 ( V_9 -> V_75 ) ;
if ( V_71 ) {
F_4 ( V_26 , L_14 , V_71 ) ;
return V_71 ;
}
V_71 = F_28 ( F_8 ( V_9 -> V_76 ) ,
V_9 -> V_76 ) ;
if ( V_71 ) {
F_4 ( V_26 , L_8 , V_71 ) ;
goto V_87;
}
F_29 ( 5 ) ;
F_34 ( V_9 -> V_28 , false ) ;
V_71 = F_39 ( V_9 -> V_28 ) ;
if ( V_71 ) {
F_4 ( V_26 , L_15 , V_71 ) ;
goto V_88;
}
return 0 ;
V_88:
F_35 ( F_8 ( V_9 -> V_76 ) ,
V_9 -> V_76 ) ;
V_87:
F_40 ( V_9 -> V_75 ) ;
return V_71 ;
}
static int F_41 ( struct V_57 * V_26 )
{
struct V_8 * V_9 = F_37 ( V_26 ) ;
F_34 ( V_9 -> V_28 , true ) ;
F_35 ( F_8 ( V_9 -> V_76 ) ,
V_9 -> V_76 ) ;
F_40 ( V_9 -> V_75 ) ;
return 0 ;
}
