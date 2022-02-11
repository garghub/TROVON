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
if ( V_9 -> V_32 == true )
F_25 ( & V_12 -> V_28 ) ;
else
F_26 ( V_16 , V_12 -> V_14 ) ;
break;
case V_33 :
F_26 ( V_16 , V_12 -> V_14 ) ;
break;
case V_34 :
F_27 ( V_16 , V_12 -> V_14 ) ;
break;
case V_35 :
V_9 -> V_32 = false ;
case V_36 :
F_28 ( V_16 , V_12 -> V_14 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_29 ( struct V_37 * V_14 , void * V_38 )
{
struct V_11 * V_12 = V_38 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_15 * V_16 = V_9 -> V_16 ;
T_1 V_41 , V_42 ;
V_42 = F_30 ( V_16 , V_12 -> V_14 ,
F_31 ( V_2 ) ) ;
V_12 -> V_26 = V_42 ;
V_41 = F_32 ( V_40 ,
( V_40 -> V_43 -> V_44 %
V_40 -> V_45 ) ) ;
F_3 ( V_6 -> V_23 , L_11 , V_41 , V_42 ) ;
F_33 ( V_2 ) ;
return V_41 ;
}
static T_3 F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_39 * V_40 = V_2 -> V_40 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
F_3 ( V_6 -> V_23 , L_12 , V_12 -> V_26 ) ;
return F_35 ( V_40 , V_12 -> V_26 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = & V_9 -> V_13 [ V_2 -> V_14 ] ;
struct V_15 * V_16 = V_9 -> V_16 ;
F_3 ( V_6 -> V_23 , L_13 ) ;
F_37 ( & V_12 -> V_46 ) ;
V_12 -> V_2 = V_2 ;
F_38 ( V_2 , & V_47 ) ;
V_12 -> V_14 = F_39 ( V_16 , V_2 -> V_14 + 1 ,
F_29 , V_12 ) ;
if ( V_12 -> V_14 == NULL ) {
F_5 ( V_6 -> V_23 , L_14 ) ;
F_40 ( & V_12 -> V_46 ) ;
return - V_48 ;
}
F_40 ( & V_12 -> V_46 ) ;
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
F_37 ( & V_12 -> V_46 ) ;
V_20 = F_43 ( V_16 , V_12 -> V_14 ) ;
if ( V_20 < 0 ) {
F_3 ( V_6 -> V_23 , L_16 ) ;
goto V_49;
}
V_12 -> V_14 = NULL ;
V_49:
F_40 ( & V_12 -> V_46 ) ;
return V_20 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_6 -> V_23 , L_17 ) ;
return F_45 ( V_2 , V_51 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_52 * V_13 = V_6 -> V_13 ;
T_4 V_53 ;
struct V_54 * V_10 = V_6 -> V_10 ;
struct V_55 * V_9 = F_47 ( V_10 -> V_23 ) ;
int V_20 = 0 ;
if ( V_13 -> V_56 [ V_22 ] . V_2 ||
V_13 -> V_56 [ V_57 ] . V_2 ) {
V_53 = V_47 . V_58 ;
V_20 = F_48 ( V_13 ,
V_59 ,
V_9 -> V_60 ,
V_53 , V_53 ) ;
if ( V_20 ) {
F_5 ( V_6 -> V_23 , L_18 ,
V_20 ) ;
return V_20 ;
}
}
return V_20 ;
}
static int F_49 ( struct V_54 * V_10 )
{
struct V_55 * V_61 = F_47 ( V_10 -> V_23 ) ;
struct V_8 * V_62 ;
int V_63 ;
if ( ! V_61 )
return - V_64 ;
V_62 = F_50 ( V_10 -> V_23 , sizeof( * V_62 ) ,
V_65 ) ;
V_62 -> V_16 = V_61 -> V_66 ;
F_51 ( V_10 , V_62 ) ;
for ( V_63 = 0 ; V_63 < V_67 ; V_63 ++ ) {
F_52 ( & V_62 -> V_13 [ V_63 ] . V_46 ) ;
F_53 ( & V_62 -> V_13 [ V_63 ] . V_28 , F_21 ) ;
}
return 0 ;
}
static int F_54 ( struct V_54 * V_10 )
{
return 0 ;
}
static int F_55 ( struct V_68 * V_23 )
{
struct V_55 * V_55 = F_47 ( V_23 ) ;
struct V_8 * V_62 = F_56 ( V_23 ) ;
int V_20 ;
F_3 ( V_23 , L_19 ) ;
V_20 = F_57 ( V_23 , V_55 ) ;
if ( V_20 < 0 ) {
F_5 ( V_23 , L_20 , V_20 ) ;
return V_20 ;
}
V_62 -> V_32 = true ;
return V_20 ;
}
static int F_58 ( struct V_68 * V_23 )
{
struct V_55 * V_55 = F_47 ( V_23 ) ;
int V_20 ;
F_3 ( V_23 , L_21 ) ;
V_20 = F_59 ( V_23 , V_55 ) ;
if ( V_20 )
return V_20 ;
return F_60 ( V_23 , V_55 ) ;
}
static int F_61 ( struct V_69 * V_70 )
{
struct V_55 * V_55 = F_47 ( & V_70 -> V_23 ) ;
int V_20 ;
V_20 = F_62 ( & V_70 -> V_23 , V_55 ) ;
if ( V_20 < 0 )
return - V_64 ;
V_20 = F_63 ( & V_70 -> V_23 , & V_71 ) ;
if ( V_20 < 0 )
goto V_72;
V_20 = F_64 ( & V_70 -> V_23 , & V_73 ,
V_74 , F_65 ( V_74 ) ) ;
if ( V_20 < 0 )
goto V_75;
return 0 ;
V_75:
F_66 ( & V_70 -> V_23 ) ;
V_72:
F_67 ( & V_70 -> V_23 , V_55 ) ;
return V_20 ;
}
static int F_68 ( struct V_69 * V_70 )
{
struct V_55 * V_55 = F_47 ( & V_70 -> V_23 ) ;
F_66 ( & V_70 -> V_23 ) ;
F_69 ( & V_70 -> V_23 ) ;
F_67 ( & V_70 -> V_23 , V_55 ) ;
return 0 ;
}
