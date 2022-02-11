static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( V_2 , & V_9 ) ;
V_4 -> V_10 = V_9 . V_11 ;
V_8 = F_3 ( V_4 ,
V_12 ) ;
if ( V_8 < 0 ) {
F_4 ( V_6 -> V_13 , L_1 ,
V_14 , V_8 ) ;
return - V_15 ;
}
F_5 ( V_2 , & V_2 -> V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 =
F_7 ( V_6 -> V_21 ) ;
T_1 V_22 = F_8 ( V_18 ) ;
unsigned int V_23 = F_9 ( V_18 ) ;
unsigned int V_24 ;
int V_25 ;
int V_8 ;
V_25 = F_10 ( V_22 ) ;
if ( V_25 < 0 ) {
F_4 ( V_6 -> V_13 , L_2 ,
V_14 , V_25 ) ;
return V_25 ;
}
V_24 = V_26 |
V_27 |
V_28 ;
switch ( V_25 ) {
case 16 :
switch ( V_23 ) {
case 1 :
case 2 :
V_24 |= V_29 ;
break;
case 4 :
V_24 |= V_30 ;
break;
case 6 :
V_24 |= V_31 ;
break;
case 8 :
V_24 |= V_32 ;
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_25 , V_23 ) ;
return - V_15 ;
}
break;
case 24 :
case 32 :
switch ( V_23 ) {
case 1 :
V_24 |= V_29 ;
break;
case 2 :
V_24 |= V_30 ;
break;
case 4 :
V_24 |= V_32 ;
break;
case 6 :
V_24 |= V_33 ;
break;
case 8 :
V_24 |= V_34 ;
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_25 , V_23 ) ;
return - V_15 ;
}
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_25 , V_23 ) ;
return - V_15 ;
}
V_8 = F_11 ( V_20 -> V_35 ,
F_12 ( V_36 ) , V_24 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 =
F_7 ( V_6 -> V_21 ) ;
int V_8 ;
V_8 = F_11 ( V_20 -> V_35 ,
F_12 ( V_36 ) , 0 ) ;
if ( V_8 )
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 =
F_7 ( V_6 -> V_21 ) ;
int V_8 ;
V_8 = F_11 ( V_20 -> V_35 ,
F_15 ( V_36 ) ,
V_4 -> V_37 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_5 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_11 ( V_20 -> V_35 ,
F_16 ( V_36 ) ,
( F_17 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_6 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_11 ( V_20 -> V_35 ,
F_18 ( V_36 ) ,
( F_19 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_7 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_20 ( V_20 -> V_35 ,
F_12 ( V_36 ) ,
V_38 , V_39 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_40 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 =
F_7 ( V_6 -> V_21 ) ;
int V_8 ;
switch ( V_40 ) {
case V_41 :
case V_42 :
case V_43 :
V_8 = F_11 ( V_20 -> V_35 ,
F_22 ( V_44 ) ,
F_23 ( V_36 ) ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_20 ( V_20 -> V_35 ,
F_24 ( V_44 ) ,
F_23 ( V_36 ) ,
F_23 ( V_36 ) ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_20 ( V_20 -> V_35 ,
F_12 ( V_36 ) ,
V_38 ,
V_39 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
break;
case V_45 :
case V_46 :
case V_47 :
V_8 = F_20 ( V_20 -> V_35 ,
F_12 ( V_36 ) ,
V_38 ,
V_48 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_20 ( V_20 -> V_35 ,
F_24 ( V_44 ) ,
F_23 ( V_36 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
break;
}
return 0 ;
}
static T_2 F_25 (
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 =
F_7 ( V_6 -> V_21 ) ;
unsigned int V_49 , V_50 ;
int V_8 ;
V_8 = F_26 ( V_20 -> V_35 ,
F_15 ( V_36 ) , & V_49 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_10 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_26 ( V_20 -> V_35 ,
F_27 ( V_36 ) , & V_50 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_11 ,
V_14 , V_8 ) ;
return V_8 ;
}
return F_28 ( V_2 -> V_4 , V_50 - V_49 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_30 ( V_2 -> V_53 -> V_54 -> V_13 , V_52 ,
V_4 -> V_55 , V_4 -> V_37 ,
V_4 -> V_10 ) ;
}
static T_3 F_31 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 =
F_7 ( V_6 -> V_21 ) ;
unsigned int V_58 ;
T_3 V_8 = V_59 ;
int V_60 ;
V_60 = F_26 ( V_20 -> V_35 ,
F_32 ( V_44 ) , & V_58 ) ;
if ( V_60 ) {
F_4 ( V_6 -> V_13 , L_12 ,
V_14 , V_60 ) ;
return V_59 ;
}
V_58 &= F_23 ( V_36 ) ;
if ( V_58 & F_33 ( V_36 ) ) {
V_60 = F_11 ( V_20 -> V_35 ,
F_22 ( V_44 ) ,
F_33 ( V_36 ) ) ;
if ( V_60 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_60 ) ;
return V_59 ;
}
F_34 ( V_2 ) ;
V_8 = V_61 ;
}
if ( V_58 & F_35 ( V_36 ) ) {
V_60 = F_11 ( V_20 -> V_35 ,
F_22 ( V_44 ) ,
F_35 ( V_36 ) ) ;
if ( V_60 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_60 ) ;
return V_59 ;
}
F_36 ( V_6 -> V_13 , L_13 , V_14 ) ;
F_37 ( V_2 , V_62 ) ;
V_8 = V_61 ;
}
if ( V_58 & F_38 ( V_36 ) ) {
V_60 = F_11 ( V_20 -> V_35 ,
F_22 ( V_44 ) ,
F_38 ( V_36 ) ) ;
if ( V_60 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_60 ) ;
return V_59 ;
}
F_4 ( V_6 -> V_13 , L_14 , V_14 ) ;
F_37 ( V_2 , V_63 ) ;
V_8 = V_61 ;
}
return V_8 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_64 * V_65 = & V_2 -> V_16 ;
T_4 V_66 = V_9 . V_11 ;
V_65 -> V_13 . type = V_67 ;
V_65 -> V_13 . V_13 = V_6 -> V_13 ;
V_65 -> V_7 = NULL ;
V_65 -> V_68 = F_40 ( V_6 -> V_13 , V_66 , & V_65 -> V_69 ,
V_70 ) ;
if ( ! V_65 -> V_68 ) {
F_4 ( V_6 -> V_13 , L_15 ,
V_14 ) ;
return - V_71 ;
}
V_65 -> V_72 = V_66 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_64 * V_65 = & V_2 -> V_16 ;
if ( V_65 -> V_68 ) {
F_42 ( V_6 -> V_13 , V_65 -> V_72 , V_65 -> V_68 ,
V_65 -> V_69 ) ;
}
V_65 -> V_68 = NULL ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_73 * V_53 = V_6 -> V_53 ;
struct V_1 * V_2 =
V_53 -> V_74 [ V_75 ] . V_2 ;
struct V_19 * V_20 =
F_7 ( V_6 -> V_21 ) ;
int V_8 ;
V_6 -> V_13 -> V_76 = F_44 ( 32 ) ;
V_6 -> V_13 -> V_77 = & V_6 -> V_13 -> V_76 ;
V_8 = F_39 ( V_2 , V_6 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_45 ( V_6 -> V_13 , V_20 -> V_78 ,
F_31 , V_79 ,
L_16 , V_2 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_17 ,
V_14 , V_8 ) ;
goto V_80;
}
V_8 = F_11 ( V_20 -> V_35 ,
F_24 ( V_44 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_11 ( V_20 -> V_35 ,
F_12 ( V_36 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
return 0 ;
V_80:
F_41 ( V_2 , V_6 ) ;
return V_8 ;
}
static void F_46 ( struct V_73 * V_53 )
{
struct V_1 * V_2 =
V_53 -> V_74 [ V_75 ] . V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_41 ( V_2 , V_6 ) ;
}
int F_47 ( struct V_81 * V_82 )
{
struct V_19 * V_20 = F_48 ( V_82 ) ;
V_20 -> V_78 = F_49 ( V_82 , L_16 ) ;
if ( V_20 -> V_78 < 0 ) {
F_4 ( & V_82 -> V_13 , L_18 ,
V_14 , V_20 -> V_78 ) ;
return - V_83 ;
}
return F_50 ( & V_82 -> V_13 ,
& V_84 ) ;
}
