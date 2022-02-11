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
const struct V_16 * V_17 ;
struct V_18 * V_18 ;
struct V_19 * V_20 ;
int V_21 ;
struct V_22 * V_22 ;
if ( V_9 -> V_13 . V_23 ) {
V_15 = F_8 ( V_24 , & V_9 -> V_13 ) ;
if ( ! V_15 ) {
F_9 ( & V_9 -> V_13 , L_1 ) ;
V_10 = - V_25 ;
goto exit;
}
V_17 = V_15 -> V_26 ;
} else {
V_17 = F_10 ( V_9 ) ;
}
V_18 = F_11 ( & V_9 -> V_13 ) ;
if ( F_12 ( V_18 ) )
F_13 ( & V_9 -> V_13 ,
L_2 ) ;
V_22 = F_14 ( & V_9 -> V_13 , NULL ) ;
if ( F_12 ( V_22 ) ) {
F_9 ( & V_9 -> V_13 , L_3 ) ;
V_10 = - V_27 ;
goto exit;
}
V_20 = F_15 ( V_9 , V_28 , 0 ) ;
V_21 = F_16 ( V_9 , 0 ) ;
if ( ! V_20 || V_21 <= 0 ) {
V_10 = - V_27 ;
goto V_29;
}
if ( ! F_17 ( V_20 -> V_30 , F_18 ( V_20 ) ,
V_31 ) ) {
F_9 ( & V_9 -> V_13 , L_4 ) ;
V_10 = - V_27 ;
goto V_29;
}
V_11 = F_19 ( V_20 -> V_30 , F_18 ( V_20 ) ) ;
if ( ! V_11 ) {
F_9 ( & V_9 -> V_13 , L_5 ) ;
V_10 = - V_32 ;
goto V_33;
}
V_13 = F_20 () ;
if ( ! V_13 ) {
V_10 = - V_32 ;
goto V_34;
}
V_2 = F_21 ( V_13 ) ;
switch ( V_17 -> V_35 ) {
case V_36 :
V_2 -> V_6 = V_37 ;
switch ( V_20 -> V_38 & V_39 ) {
case V_40 :
V_2 -> V_41 = F_5 ;
V_2 -> V_42 = F_6 ;
break;
case V_43 :
default:
V_2 -> V_41 = F_1 ;
V_2 -> V_42 = F_3 ;
break;
}
break;
case V_44 :
V_2 -> V_6 = V_45 ;
V_2 -> V_46 . V_47 |= V_48 ;
V_2 -> V_41 = F_1 ;
V_2 -> V_42 = F_3 ;
break;
default:
V_10 = - V_25 ;
goto V_49;
}
V_13 -> V_21 = V_21 ;
V_2 -> V_5 = V_11 ;
V_2 -> V_50 = & V_9 -> V_13 ;
V_2 -> V_46 . clock . V_51 = F_22 ( V_22 ) ;
V_2 -> V_2 = V_22 ;
V_2 -> type = V_17 -> V_35 ;
F_23 ( V_9 , V_13 ) ;
F_24 ( V_13 , & V_9 -> V_13 ) ;
V_10 = F_25 ( V_13 ) ;
if ( V_10 ) {
F_9 ( & V_9 -> V_13 , L_6 ,
V_31 , V_10 ) ;
goto V_49;
}
F_26 ( & V_9 -> V_13 , L_7 ,
V_31 , V_2 -> V_5 , V_13 -> V_21 ) ;
return 0 ;
V_49:
F_23 ( V_9 , NULL ) ;
F_27 ( V_13 ) ;
V_34:
F_28 ( V_11 ) ;
V_33:
F_29 ( V_20 -> V_30 , F_18 ( V_20 ) ) ;
V_29:
F_30 ( V_22 ) ;
exit:
F_9 ( & V_9 -> V_13 , L_8 ) ;
return V_10 ;
}
static int T_4 F_31 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_32 ( V_9 ) ;
struct V_1 * V_2 = F_21 ( V_13 ) ;
struct V_19 * V_20 ;
F_33 ( V_13 ) ;
F_23 ( V_9 , NULL ) ;
F_27 ( V_13 ) ;
F_28 ( V_2 -> V_5 ) ;
V_20 = F_15 ( V_9 , V_28 , 0 ) ;
F_29 ( V_20 -> V_30 , F_18 ( V_20 ) ) ;
F_30 ( V_2 -> V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_8 * V_9 , T_5 V_52 )
{
int V_10 ;
struct V_12 * V_53 = F_32 ( V_9 ) ;
struct V_1 * V_2 = F_21 ( V_53 ) ;
if ( V_2 -> type != V_44 ) {
F_13 ( & V_9 -> V_13 , L_9 ) ;
return 0 ;
}
if ( F_35 ( V_53 ) ) {
F_36 ( V_53 ) ;
F_37 ( V_53 ) ;
}
V_10 = F_38 ( V_53 ) ;
if ( V_10 ) {
F_39 ( V_53 , L_10 ) ;
return V_10 ;
}
V_2 -> V_46 . V_52 = V_54 ;
return 0 ;
}
static int F_40 ( struct V_8 * V_9 )
{
int V_10 ;
struct V_12 * V_53 = F_32 ( V_9 ) ;
struct V_1 * V_2 = F_21 ( V_53 ) ;
if ( V_2 -> type != V_44 ) {
F_13 ( & V_9 -> V_13 , L_9 ) ;
return 0 ;
}
V_10 = F_41 ( V_53 ) ;
if ( V_10 ) {
F_39 ( V_53 , L_11 ) ;
return V_10 ;
}
V_2 -> V_46 . V_52 = V_55 ;
if ( F_35 ( V_53 ) ) {
F_42 ( V_53 ) ;
F_43 ( V_53 ) ;
}
return 0 ;
}
