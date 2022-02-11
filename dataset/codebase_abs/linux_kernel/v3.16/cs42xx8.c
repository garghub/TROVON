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
default:
F_4 ( V_7 -> V_23 , L_1 ) ;
return - V_24 ;
}
F_5 ( V_9 -> V_25 , V_26 ,
V_27 |
V_28 , V_12 ) ;
switch ( V_11 & V_29 ) {
case V_30 :
V_9 -> V_31 = true ;
break;
case V_32 :
V_9 -> V_31 = false ;
break;
default:
F_4 ( V_7 -> V_23 , L_2 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_6 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_6 * V_7 = V_37 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
bool V_38 = V_34 -> V_39 == V_40 ;
T_1 V_41 = V_9 -> V_10 / F_7 ( V_36 ) ;
T_1 V_42 , V_43 , V_12 , V_44 ;
for ( V_42 = 0 ; V_42 < F_8 ( V_45 ) ; V_42 ++ ) {
if ( V_45 [ V_42 ] . V_41 == V_41 )
break;
}
if ( V_42 == F_8 ( V_45 ) ) {
F_4 ( V_7 -> V_23 , L_3 ) ;
return - V_24 ;
}
V_44 = V_46 ;
V_12 = V_45 [ V_42 ] . V_47 ;
V_43 = V_9 -> V_31 ? V_48 : V_45 [ V_42 ] . V_49 ;
F_5 ( V_9 -> V_25 , V_50 ,
F_9 ( V_38 ) | V_44 ,
F_10 ( V_38 , V_43 ) | V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_37 , int V_51 )
{
struct V_6 * V_7 = V_37 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
F_5 ( V_9 -> V_25 , V_52 ,
V_53 , V_51 ? V_53 : 0 ) ;
return 0 ;
}
static bool F_12 ( struct V_54 * V_23 , unsigned int V_55 )
{
switch ( V_55 ) {
case V_56 :
return true ;
default:
return false ;
}
}
static bool F_13 ( struct V_54 * V_23 , unsigned int V_55 )
{
switch ( V_55 ) {
case V_57 :
case V_56 :
return false ;
default:
return true ;
}
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_58 * V_59 = & V_7 -> V_59 ;
switch ( V_9 -> V_60 -> V_61 ) {
case 3 :
F_15 ( V_7 , V_62 ,
F_8 ( V_62 ) ) ;
F_16 ( V_59 , V_63 ,
F_8 ( V_63 ) ) ;
F_17 ( V_59 , V_64 ,
F_8 ( V_64 ) ) ;
break;
default:
break;
}
F_18 ( V_9 -> V_25 , V_52 , V_53 ) ;
return 0 ;
}
int F_19 ( struct V_54 * V_23 , struct V_25 * V_25 )
{
const struct V_65 * V_66 = F_20 ( V_67 , V_23 ) ;
struct V_8 * V_9 ;
int V_68 , V_12 , V_42 ;
V_9 = F_21 ( V_23 , sizeof( * V_9 ) , V_69 ) ;
if ( V_9 == NULL )
return - V_70 ;
F_22 ( V_23 , V_9 ) ;
if ( V_66 )
V_9 -> V_60 = V_66 -> V_71 ;
if ( ! V_9 -> V_60 ) {
F_4 ( V_23 , L_4 ) ;
return - V_24 ;
}
V_9 -> V_72 = F_23 ( V_23 , L_5 ) ;
if ( F_24 ( V_9 -> V_72 ) ) {
F_4 ( V_23 , L_6 ,
F_25 ( V_9 -> V_72 ) ) ;
return - V_24 ;
}
V_9 -> V_10 = F_26 ( V_9 -> V_72 ) ;
for ( V_42 = 0 ; V_42 < F_8 ( V_9 -> V_73 ) ; V_42 ++ )
V_9 -> V_73 [ V_42 ] . V_74 = V_75 [ V_42 ] ;
V_68 = F_27 ( V_23 ,
F_8 ( V_9 -> V_73 ) , V_9 -> V_73 ) ;
if ( V_68 ) {
F_4 ( V_23 , L_7 , V_68 ) ;
return V_68 ;
}
V_68 = F_28 ( F_8 ( V_9 -> V_73 ) ,
V_9 -> V_73 ) ;
if ( V_68 ) {
F_4 ( V_23 , L_8 , V_68 ) ;
return V_68 ;
}
F_29 ( 5 ) ;
V_9 -> V_25 = V_25 ;
if ( F_24 ( V_9 -> V_25 ) ) {
V_68 = F_25 ( V_9 -> V_25 ) ;
F_4 ( V_23 , L_9 , V_68 ) ;
goto V_76;
}
F_30 ( V_9 -> V_25 , true ) ;
V_68 = F_31 ( V_9 -> V_25 , V_57 , & V_12 ) ;
if ( V_68 < 0 ) {
F_4 ( V_23 , L_10 , V_68 ) ;
goto V_76;
}
if ( ( ( V_12 & V_77 ) >> 4 ) != 0x00 ) {
F_4 ( V_23 , L_11 ,
( V_12 & V_77 ) >> 4 ) ;
V_68 = - V_24 ;
goto V_76;
}
F_32 ( V_23 , L_12 ,
V_12 & V_78 ) ;
F_30 ( V_9 -> V_25 , false ) ;
V_79 . V_80 = V_9 -> V_60 -> V_80 ;
V_79 . V_81 . V_82 = V_9 -> V_60 -> V_61 * 2 ;
V_68 = F_33 ( V_23 , & V_83 , & V_79 , 1 ) ;
if ( V_68 ) {
F_4 ( V_23 , L_13 , V_68 ) ;
goto V_76;
}
F_34 ( V_9 -> V_25 , true ) ;
V_76:
F_35 ( F_8 ( V_9 -> V_73 ) ,
V_9 -> V_73 ) ;
return V_68 ;
}
static int F_36 ( struct V_54 * V_23 )
{
struct V_8 * V_9 = F_37 ( V_23 ) ;
int V_68 ;
V_68 = F_38 ( V_9 -> V_72 ) ;
if ( V_68 ) {
F_4 ( V_23 , L_14 , V_68 ) ;
return V_68 ;
}
V_68 = F_28 ( F_8 ( V_9 -> V_73 ) ,
V_9 -> V_73 ) ;
if ( V_68 ) {
F_4 ( V_23 , L_8 , V_68 ) ;
goto V_84;
}
F_29 ( 5 ) ;
F_34 ( V_9 -> V_25 , false ) ;
V_68 = F_39 ( V_9 -> V_25 ) ;
if ( V_68 ) {
F_4 ( V_23 , L_15 , V_68 ) ;
goto V_85;
}
return 0 ;
V_85:
F_35 ( F_8 ( V_9 -> V_73 ) ,
V_9 -> V_73 ) ;
V_84:
F_40 ( V_9 -> V_72 ) ;
return V_68 ;
}
static int F_41 ( struct V_54 * V_23 )
{
struct V_8 * V_9 = F_37 ( V_23 ) ;
F_34 ( V_9 -> V_25 , true ) ;
F_35 ( F_8 ( V_9 -> V_73 ) ,
V_9 -> V_73 ) ;
F_40 ( V_9 -> V_72 ) ;
return 0 ;
}
