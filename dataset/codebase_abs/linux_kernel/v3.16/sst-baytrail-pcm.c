static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
struct V_15 * V_16 = V_9 -> V_16 ;
T_1 V_17 , V_18 ;
T_2 V_19 ;
int V_20 , V_21 = ( V_2 -> V_14 == V_22 ) ;
F_3 ( V_6 -> V_23 , L_1 , V_12 ) ;
V_20 = F_4 ( V_16 , V_12 -> V_14 ,
1 , 1 , ! V_21 ) ;
if ( V_20 < 0 ) {
F_5 ( V_6 -> V_23 , L_2 , V_20 ) ;
return V_20 ;
}
V_17 = F_6 ( V_4 ) ;
V_20 = F_7 ( V_16 , V_12 -> V_14 , V_17 ) ;
if ( V_20 < 0 ) {
F_5 ( V_6 -> V_23 , L_3 , V_17 ) ;
return V_20 ;
}
V_18 = F_8 ( F_9 ( V_4 ) ) ;
V_20 = F_10 ( V_16 , V_12 -> V_14 , V_18 ) ;
if ( V_20 < 0 ) {
F_5 ( V_6 -> V_23 , L_4 ,
F_6 ( V_4 ) ) ;
return V_20 ;
}
V_19 = ( T_2 ) ( F_11 ( V_4 ) & 0xF ) ;
V_20 = F_12 ( V_16 , V_12 -> V_14 , V_19 ) ;
if ( V_20 < 0 ) {
F_5 ( V_6 -> V_23 , L_5 ,
F_6 ( V_4 ) ) ;
return V_20 ;
}
F_13 ( V_2 , F_14 ( V_4 ) ) ;
V_20 = F_15 ( V_16 , V_12 -> V_14 ,
V_2 -> V_24 . V_25 ,
F_14 ( V_4 ) ) ;
if ( V_20 < 0 ) {
F_5 ( V_6 -> V_23 , L_6 , V_20 ) ;
return V_20 ;
}
V_20 = F_16 ( V_16 , V_12 -> V_14 ) ;
if ( V_20 < 0 ) {
F_5 ( V_6 -> V_23 , L_7 , V_20 ) ;
return V_20 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_6 -> V_23 , L_8 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
struct V_15 * V_16 = V_9 -> V_16 ;
int V_20 ;
V_20 = F_16 ( V_16 , V_12 -> V_14 ) ;
if ( V_20 < 0 ) {
F_5 ( V_6 -> V_23 , L_7 , V_20 ) ;
return V_20 ;
}
F_20 ( V_16 , V_12 -> V_14 , V_12 -> V_26 ) ;
F_3 ( V_6 -> V_23 , L_9 ,
V_12 -> V_26 ) ;
return 0 ;
}
static void F_21 ( struct V_27 * V_28 )
{
struct V_11 * V_12 =
F_22 ( V_28 , struct V_11 , V_28 ) ;
if ( F_23 ( V_12 -> V_2 ) )
F_19 ( V_12 -> V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
struct V_15 * V_16 = V_9 -> V_16 ;
F_3 ( V_6 -> V_23 , L_10 , V_29 ) ;
switch ( V_29 ) {
case V_30 :
V_12 -> V_26 = 0 ;
F_20 ( V_16 , V_12 -> V_14 , 0 ) ;
break;
case V_31 :
F_25 ( & V_12 -> V_28 ) ;
break;
case V_32 :
F_26 ( V_16 , V_12 -> V_14 ) ;
break;
case V_33 :
F_27 ( V_16 , V_12 -> V_14 ) ;
break;
case V_34 :
case V_35 :
F_28 ( V_16 , V_12 -> V_14 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_29 ( struct V_36 * V_14 , void * V_37 )
{
struct V_11 * V_12 = V_37 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
T_1 V_40 , V_41 ;
V_41 = F_30 ( V_16 , V_12 -> V_14 ,
F_31 ( V_2 ) ) ;
V_12 -> V_26 = V_41 ;
V_40 = F_32 ( V_39 ,
( V_39 -> V_42 -> V_43 %
V_39 -> V_44 ) ) ;
F_3 ( V_6 -> V_23 , L_11 , V_40 , V_41 ) ;
F_33 ( V_2 ) ;
return V_40 ;
}
static T_3 F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
F_3 ( V_6 -> V_23 , L_12 , V_12 -> V_26 ) ;
return F_35 ( V_39 , V_12 -> V_26 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
struct V_15 * V_16 = V_9 -> V_16 ;
F_3 ( V_6 -> V_23 , L_13 ) ;
F_37 ( & V_12 -> V_45 ) ;
V_12 -> V_2 = V_2 ;
F_38 ( V_2 , & V_46 ) ;
V_12 -> V_14 = F_39 ( V_16 , V_2 -> V_14 + 1 ,
F_29 , V_12 ) ;
if ( V_12 -> V_14 == NULL ) {
F_5 ( V_6 -> V_23 , L_14 ) ;
F_40 ( & V_12 -> V_45 ) ;
return - V_47 ;
}
F_40 ( & V_12 -> V_45 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
struct V_15 * V_16 = V_9 -> V_16 ;
int V_20 ;
F_3 ( V_6 -> V_23 , L_15 ) ;
F_42 ( & V_12 -> V_28 ) ;
F_37 ( & V_12 -> V_45 ) ;
V_20 = F_43 ( V_16 , V_12 -> V_14 ) ;
if ( V_20 < 0 ) {
F_3 ( V_6 -> V_23 , L_16 ) ;
goto V_48;
}
V_12 -> V_14 = NULL ;
V_48:
F_40 ( & V_12 -> V_45 ) ;
return V_20 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_6 -> V_23 , L_17 ) ;
return F_45 ( V_2 , V_50 ) ;
}
static void F_46 ( struct V_51 * V_13 )
{
F_47 ( V_13 ) ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_51 * V_13 = V_6 -> V_13 ;
T_4 V_52 ;
struct V_53 * V_10 = V_6 -> V_10 ;
struct V_54 * V_9 = F_49 ( V_10 -> V_23 ) ;
int V_20 = 0 ;
if ( V_13 -> V_55 [ V_22 ] . V_2 ||
V_13 -> V_55 [ V_56 ] . V_2 ) {
V_52 = V_46 . V_57 ;
V_20 = F_50 ( V_13 ,
V_58 ,
V_9 -> V_59 ,
V_52 , V_52 ) ;
if ( V_20 ) {
F_5 ( V_6 -> V_23 , L_18 ,
V_20 ) ;
return V_20 ;
}
}
return V_20 ;
}
static int F_51 ( struct V_53 * V_10 )
{
struct V_54 * V_60 = F_49 ( V_10 -> V_23 ) ;
struct V_8 * V_61 ;
int V_62 ;
if ( ! V_60 )
return - V_63 ;
V_61 = F_52 ( V_10 -> V_23 , sizeof( * V_61 ) ,
V_64 ) ;
V_61 -> V_16 = V_60 -> V_65 ;
F_53 ( V_10 , V_61 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ ) {
F_54 ( & V_61 -> V_13 [ V_62 ] . V_45 ) ;
F_55 ( & V_61 -> V_13 [ V_62 ] . V_28 , F_21 ) ;
}
return 0 ;
}
static int F_56 ( struct V_53 * V_10 )
{
return 0 ;
}
static int F_57 ( struct V_67 * V_23 )
{
struct V_54 * V_54 = F_49 ( V_23 ) ;
int V_20 ;
F_3 ( V_23 , L_19 ) ;
V_20 = F_58 ( V_23 , V_54 ) ;
if ( V_20 < 0 ) {
F_5 ( V_23 , L_20 , V_20 ) ;
return V_20 ;
}
return V_20 ;
}
static int F_59 ( struct V_67 * V_23 )
{
struct V_54 * V_54 = F_49 ( V_23 ) ;
int V_20 ;
F_3 ( V_23 , L_21 ) ;
V_20 = F_60 ( V_23 , V_54 ) ;
if ( V_20 < 0 ) {
F_5 ( V_23 , L_20 , V_20 ) ;
return V_20 ;
}
return V_20 ;
}
static int F_61 ( struct V_67 * V_23 )
{
struct V_54 * V_54 = F_49 ( V_23 ) ;
F_3 ( V_23 , L_22 ) ;
return F_62 ( V_23 , V_54 ) ;
}
static int F_63 ( struct V_67 * V_23 )
{
struct V_54 * V_54 = F_49 ( V_23 ) ;
F_3 ( V_23 , L_23 ) ;
return F_64 ( V_23 , V_54 ) ;
}
static int F_65 ( struct V_68 * V_69 )
{
struct V_54 * V_54 = F_49 ( & V_69 -> V_23 ) ;
int V_20 ;
V_20 = F_66 ( & V_69 -> V_23 , V_54 ) ;
if ( V_20 < 0 )
return - V_63 ;
V_20 = F_67 ( & V_69 -> V_23 , & V_70 ) ;
if ( V_20 < 0 )
goto V_71;
V_20 = F_68 ( & V_69 -> V_23 , & V_72 ,
V_73 , F_69 ( V_73 ) ) ;
if ( V_20 < 0 )
goto V_74;
return 0 ;
V_74:
F_70 ( & V_69 -> V_23 ) ;
V_71:
F_71 ( & V_69 -> V_23 , V_54 ) ;
return V_20 ;
}
static int F_72 ( struct V_68 * V_69 )
{
struct V_54 * V_54 = F_49 ( & V_69 -> V_23 ) ;
F_70 ( & V_69 -> V_23 ) ;
F_73 ( & V_69 -> V_23 ) ;
F_71 ( & V_69 -> V_23 , V_54 ) ;
return 0 ;
}
