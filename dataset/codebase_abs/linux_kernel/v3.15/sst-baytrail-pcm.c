static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_9 -> V_14 ;
T_1 V_15 , V_16 ;
T_2 V_17 ;
int V_18 , V_19 = ( V_2 -> V_20 == V_21 ) ;
F_4 ( V_6 -> V_22 , L_1 , V_12 ) ;
V_18 = F_5 ( V_14 , V_12 -> V_20 ,
1 , 1 , ! V_19 ) ;
if ( V_18 < 0 ) {
F_6 ( V_6 -> V_22 , L_2 , V_18 ) ;
return V_18 ;
}
V_15 = F_7 ( V_4 ) ;
V_18 = F_8 ( V_14 , V_12 -> V_20 , V_15 ) ;
if ( V_18 < 0 ) {
F_6 ( V_6 -> V_22 , L_3 , V_15 ) ;
return V_18 ;
}
V_16 = F_9 ( F_10 ( V_4 ) ) ;
V_18 = F_11 ( V_14 , V_12 -> V_20 , V_16 ) ;
if ( V_18 < 0 ) {
F_6 ( V_6 -> V_22 , L_4 ,
F_7 ( V_4 ) ) ;
return V_18 ;
}
V_17 = ( T_2 ) ( F_12 ( V_4 ) & 0xF ) ;
V_18 = F_13 ( V_14 , V_12 -> V_20 , V_17 ) ;
if ( V_18 < 0 ) {
F_6 ( V_6 -> V_22 , L_5 ,
F_7 ( V_4 ) ) ;
return V_18 ;
}
F_14 ( V_2 , F_15 ( V_4 ) ) ;
V_18 = F_16 ( V_14 , V_12 -> V_20 ,
V_2 -> V_23 . V_24 ,
F_15 ( V_4 ) ) ;
if ( V_18 < 0 ) {
F_6 ( V_6 -> V_22 , L_6 , V_18 ) ;
return V_18 ;
}
V_18 = F_17 ( V_14 , V_12 -> V_20 ) ;
if ( V_18 < 0 ) {
F_6 ( V_6 -> V_22 , L_7 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 -> V_22 , L_8 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_25 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_9 -> V_14 ;
F_4 ( V_6 -> V_22 , L_9 , V_25 ) ;
switch ( V_25 ) {
case V_26 :
F_21 ( V_14 , V_12 -> V_20 ) ;
break;
case V_27 :
case V_28 :
F_22 ( V_14 , V_12 -> V_20 ) ;
break;
case V_29 :
F_23 ( V_14 , V_12 -> V_20 ) ;
break;
case V_30 :
case V_31 :
F_24 ( V_14 , V_12 -> V_20 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_25 ( struct V_32 * V_20 , void * V_33 )
{
struct V_11 * V_12 = V_33 ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_36 ;
V_36 = F_26 ( V_35 ,
( V_35 -> V_37 -> V_38 %
V_35 -> V_39 ) ) ;
F_4 ( V_6 -> V_22 , L_10 , V_36 ) ;
F_27 ( V_2 ) ;
return V_36 ;
}
static T_3 F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_34 * V_35 = V_2 -> V_35 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_9 -> V_14 ;
T_3 V_40 ;
int V_36 ;
V_36 = F_29 ( V_14 , V_12 -> V_20 ,
F_30 ( V_2 ) ) ;
V_40 = F_31 ( V_35 , V_36 ) ;
F_4 ( V_6 -> V_22 , L_11 ,
F_26 ( V_35 , ( T_1 ) V_40 ) ) ;
return V_40 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_9 -> V_14 ;
F_4 ( V_6 -> V_22 , L_12 ) ;
V_12 = & V_9 -> V_41 [ V_6 -> V_42 -> V_43 ] ;
F_33 ( & V_12 -> V_44 ) ;
F_34 ( V_6 , V_12 ) ;
V_12 -> V_2 = V_2 ;
F_35 ( V_2 , & V_45 ) ;
V_12 -> V_20 = F_36 ( V_14 , V_6 -> V_42 -> V_43 + 1 ,
F_25 , V_12 ) ;
if ( V_12 -> V_20 == NULL ) {
F_6 ( V_6 -> V_22 , L_13 ) ;
F_37 ( & V_12 -> V_44 ) ;
return - V_46 ;
}
F_37 ( & V_12 -> V_44 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 =
F_2 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_3 ( V_6 ) ;
struct V_13 * V_14 = V_9 -> V_14 ;
int V_18 ;
F_4 ( V_6 -> V_22 , L_14 ) ;
F_33 ( & V_12 -> V_44 ) ;
V_18 = F_39 ( V_14 , V_12 -> V_20 ) ;
if ( V_18 < 0 ) {
F_4 ( V_6 -> V_22 , L_15 ) ;
goto V_47;
}
V_12 -> V_20 = NULL ;
V_47:
F_37 ( & V_12 -> V_44 ) ;
return V_18 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_6 -> V_22 , L_16 ) ;
return F_41 ( V_2 , V_49 ) ;
}
static void F_42 ( struct V_50 * V_41 )
{
F_43 ( V_41 ) ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_50 * V_41 = V_6 -> V_41 ;
T_4 V_51 ;
int V_18 = 0 ;
V_18 = F_45 ( V_6 -> V_52 -> V_22 , F_46 ( 32 ) ) ;
if ( V_18 )
return V_18 ;
if ( V_41 -> V_53 [ V_21 ] . V_2 ||
V_41 -> V_53 [ V_54 ] . V_2 ) {
V_51 = V_45 . V_55 ;
V_18 = F_47 ( V_41 ,
V_56 ,
V_6 -> V_52 -> V_22 ,
V_51 , V_51 ) ;
if ( V_18 ) {
F_6 ( V_6 -> V_22 , L_17 ,
V_18 ) ;
return V_18 ;
}
}
return V_18 ;
}
static int F_48 ( struct V_57 * V_10 )
{
struct V_58 * V_59 = F_49 ( V_10 -> V_22 ) ;
struct V_8 * V_60 ;
int V_61 ;
if ( ! V_59 )
return - V_62 ;
V_60 = F_50 ( V_10 -> V_22 , sizeof( * V_60 ) ,
V_63 ) ;
V_60 -> V_14 = V_59 -> V_64 ;
F_51 ( V_10 , V_60 ) ;
for ( V_61 = 0 ; V_61 < F_52 ( V_65 ) ; V_61 ++ )
F_53 ( & V_60 -> V_41 [ V_61 ] . V_44 ) ;
return 0 ;
}
static int F_54 ( struct V_57 * V_10 )
{
return 0 ;
}
static int F_55 ( struct V_66 * V_67 )
{
struct V_58 * V_58 = F_49 ( & V_67 -> V_22 ) ;
int V_18 ;
V_18 = F_56 ( & V_67 -> V_22 , V_58 ) ;
if ( V_18 < 0 )
return - V_62 ;
V_18 = F_57 ( & V_67 -> V_22 , & V_68 ) ;
if ( V_18 < 0 )
goto V_69;
V_18 = F_58 ( & V_67 -> V_22 , & V_70 ,
V_65 , F_52 ( V_65 ) ) ;
if ( V_18 < 0 )
goto V_71;
return 0 ;
V_71:
F_59 ( & V_67 -> V_22 ) ;
V_69:
F_60 ( & V_67 -> V_22 , V_58 ) ;
return V_18 ;
}
static int F_61 ( struct V_66 * V_67 )
{
struct V_58 * V_58 = F_49 ( & V_67 -> V_22 ) ;
F_59 ( & V_67 -> V_22 ) ;
F_62 ( & V_67 -> V_22 ) ;
F_60 ( & V_67 -> V_22 , V_58 ) ;
return 0 ;
}
