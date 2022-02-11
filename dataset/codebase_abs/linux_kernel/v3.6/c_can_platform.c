static T_1 F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static int T_2 F_7 ( struct V_8 * V_9 )
{
int V_10 ;
void T_3 * V_11 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
const struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
struct V_19 * V_19 ;
V_19 = F_8 ( & V_9 -> V_13 , NULL ) ;
if ( F_9 ( V_19 ) ) {
F_10 ( & V_9 -> V_13 , L_1 ) ;
V_10 = - V_20 ;
goto exit;
}
V_17 = F_11 ( V_9 , V_21 , 0 ) ;
V_18 = F_12 ( V_9 , 0 ) ;
if ( ! V_17 || V_18 <= 0 ) {
V_10 = - V_20 ;
goto V_22;
}
if ( ! F_13 ( V_17 -> V_23 , F_14 ( V_17 ) ,
V_24 ) ) {
F_10 ( & V_9 -> V_13 , L_2 ) ;
V_10 = - V_20 ;
goto V_22;
}
V_11 = F_15 ( V_17 -> V_23 , F_14 ( V_17 ) ) ;
if ( ! V_11 ) {
F_10 ( & V_9 -> V_13 , L_3 ) ;
V_10 = - V_25 ;
goto V_26;
}
V_13 = F_16 () ;
if ( ! V_13 ) {
V_10 = - V_25 ;
goto V_27;
}
V_2 = F_17 ( V_13 ) ;
V_15 = F_18 ( V_9 ) ;
switch ( V_15 -> V_28 ) {
case V_29 :
V_2 -> V_6 = V_30 ;
switch ( V_17 -> V_31 & V_32 ) {
case V_33 :
V_2 -> V_34 = F_5 ;
V_2 -> V_35 = F_6 ;
break;
case V_36 :
default:
V_2 -> V_34 = F_1 ;
V_2 -> V_35 = F_3 ;
break;
}
break;
case V_37 :
V_2 -> V_6 = V_38 ;
V_2 -> V_39 . V_40 |= V_41 ;
V_2 -> V_34 = F_1 ;
V_2 -> V_35 = F_3 ;
break;
default:
V_10 = - V_42 ;
goto V_43;
}
V_13 -> V_18 = V_18 ;
V_2 -> V_5 = V_11 ;
V_2 -> V_39 . clock . V_44 = F_19 ( V_19 ) ;
V_2 -> V_2 = V_19 ;
F_20 ( V_9 , V_13 ) ;
F_21 ( V_13 , & V_9 -> V_13 ) ;
V_10 = F_22 ( V_13 ) ;
if ( V_10 ) {
F_10 ( & V_9 -> V_13 , L_4 ,
V_24 , V_10 ) ;
goto V_43;
}
F_23 ( & V_9 -> V_13 , L_5 ,
V_24 , V_2 -> V_5 , V_13 -> V_18 ) ;
return 0 ;
V_43:
F_20 ( V_9 , NULL ) ;
F_24 ( V_13 ) ;
V_27:
F_25 ( V_11 ) ;
V_26:
F_26 ( V_17 -> V_23 , F_14 ( V_17 ) ) ;
V_22:
F_27 ( V_19 ) ;
exit:
F_10 ( & V_9 -> V_13 , L_6 ) ;
return V_10 ;
}
static int T_4 F_28 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_29 ( V_9 ) ;
struct V_1 * V_2 = F_17 ( V_13 ) ;
struct V_16 * V_17 ;
F_30 ( V_13 ) ;
F_20 ( V_9 , NULL ) ;
F_24 ( V_13 ) ;
F_25 ( V_2 -> V_5 ) ;
V_17 = F_11 ( V_9 , V_21 , 0 ) ;
F_26 ( V_17 -> V_23 , F_14 ( V_17 ) ) ;
F_27 ( V_2 -> V_2 ) ;
return 0 ;
}
