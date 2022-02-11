static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_5 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 * 2 ) ;
}
static void F_6 ( const struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 * 2 ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 * 4 ) ;
}
static void F_8 ( const struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 * 4 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_8 ;
void T_2 * V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_12 * V_13 , * V_14 ;
struct V_15 * V_16 ;
V_16 = F_10 ( & V_7 -> V_11 ) ;
if ( ! V_16 ) {
F_11 ( & V_7 -> V_11 , L_1 ) ;
V_8 = - V_17 ;
goto exit;
}
V_13 = F_12 ( V_7 , V_18 , 0 ) ;
V_14 = F_12 ( V_7 , V_19 , 0 ) ;
if ( ! V_13 || ! V_14 ) {
V_8 = - V_17 ;
goto exit;
}
if ( ! F_13 ( V_13 -> V_20 , F_14 ( V_13 ) ,
V_21 ) ) {
V_8 = - V_22 ;
goto exit;
}
V_9 = F_15 ( V_13 -> V_20 , F_14 ( V_13 ) ) ;
if ( ! V_9 ) {
V_8 = - V_23 ;
goto V_24;
}
V_11 = F_16 ( 0 ) ;
if ( ! V_11 ) {
V_8 = - V_23 ;
goto V_25;
}
V_2 = F_17 ( V_11 ) ;
V_11 -> V_26 = V_14 -> V_20 ;
V_2 -> V_27 = V_14 -> V_28 & V_29 ;
if ( V_14 -> V_28 & V_30 )
V_2 -> V_27 |= V_31 ;
V_2 -> V_4 = V_9 ;
V_2 -> V_32 . clock . V_33 = V_16 -> V_34 / 2 ;
V_2 -> V_35 = V_16 -> V_35 ;
V_2 -> V_36 = V_16 -> V_36 ;
switch ( V_13 -> V_28 & V_37 ) {
case V_38 :
V_2 -> V_39 = F_7 ;
V_2 -> V_40 = F_8 ;
break;
case V_41 :
V_2 -> V_39 = F_5 ;
V_2 -> V_40 = F_6 ;
break;
case V_42 :
default:
V_2 -> V_39 = F_1 ;
V_2 -> V_40 = F_3 ;
break;
}
F_18 ( V_7 , V_11 ) ;
F_19 ( V_11 , & V_7 -> V_11 ) ;
V_8 = F_20 ( V_11 ) ;
if ( V_8 ) {
F_11 ( & V_7 -> V_11 , L_2 ,
V_21 , V_8 ) ;
goto V_43;
}
F_21 ( & V_7 -> V_11 , L_3 ,
V_21 , V_2 -> V_4 , V_11 -> V_26 ) ;
return 0 ;
V_43:
F_22 ( V_11 ) ;
V_25:
F_23 ( V_9 ) ;
V_24:
F_24 ( V_13 -> V_20 , F_14 ( V_13 ) ) ;
exit:
return V_8 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_26 ( V_7 ) ;
struct V_1 * V_2 = F_17 ( V_11 ) ;
struct V_12 * V_44 ;
F_27 ( V_11 ) ;
if ( V_2 -> V_4 )
F_23 ( V_2 -> V_4 ) ;
V_44 = F_12 ( V_7 , V_18 , 0 ) ;
F_24 ( V_44 -> V_20 , F_14 ( V_44 ) ) ;
F_22 ( V_11 ) ;
return 0 ;
}
