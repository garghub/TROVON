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
static void F_7 ( const struct V_1 * V_2 , bool V_8 )
{
T_2 V_7 ;
V_7 = F_8 ( V_2 -> V_9 ) ;
if ( V_8 )
V_7 |= F_9 ( V_2 -> V_10 ) ;
else
V_7 &= ~ F_9 ( V_2 -> V_10 ) ;
F_10 ( V_7 , V_2 -> V_9 ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
int V_13 ;
void T_3 * V_14 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
const struct V_17 * V_18 ;
const struct V_19 * V_20 ;
struct V_21 * V_21 ;
struct V_22 * V_23 , * V_24 ;
int V_25 ;
struct V_26 * V_26 ;
if ( V_12 -> V_16 . V_27 ) {
V_18 = F_12 ( V_28 , & V_12 -> V_16 ) ;
if ( ! V_18 ) {
F_13 ( & V_12 -> V_16 , L_1 ) ;
V_13 = - V_29 ;
goto exit;
}
V_20 = V_18 -> V_30 ;
} else {
V_20 = F_14 ( V_12 ) ;
}
V_21 = F_15 ( & V_12 -> V_16 ) ;
if ( F_16 ( V_21 ) )
F_17 ( & V_12 -> V_16 ,
L_2 ) ;
V_26 = F_18 ( & V_12 -> V_16 , NULL ) ;
if ( F_16 ( V_26 ) ) {
F_13 ( & V_12 -> V_16 , L_3 ) ;
V_13 = - V_31 ;
goto exit;
}
V_23 = F_19 ( V_12 , V_32 , 0 ) ;
V_25 = F_20 ( V_12 , 0 ) ;
if ( ! V_23 || V_25 <= 0 ) {
V_13 = - V_31 ;
goto V_33;
}
if ( ! F_21 ( V_23 -> V_34 , F_22 ( V_23 ) ,
V_35 ) ) {
F_13 ( & V_12 -> V_16 , L_4 ) ;
V_13 = - V_31 ;
goto V_33;
}
V_14 = F_23 ( V_23 -> V_34 , F_22 ( V_23 ) ) ;
if ( ! V_14 ) {
F_13 ( & V_12 -> V_16 , L_5 ) ;
V_13 = - V_36 ;
goto V_37;
}
V_16 = F_24 () ;
if ( ! V_16 ) {
V_13 = - V_36 ;
goto V_38;
}
V_2 = F_25 ( V_16 ) ;
switch ( V_20 -> V_39 ) {
case V_40 :
V_2 -> V_6 = V_41 ;
switch ( V_23 -> V_42 & V_43 ) {
case V_44 :
V_2 -> V_45 = F_5 ;
V_2 -> V_46 = F_6 ;
break;
case V_47 :
default:
V_2 -> V_45 = F_1 ;
V_2 -> V_46 = F_3 ;
break;
}
break;
case V_48 :
V_2 -> V_6 = V_49 ;
V_2 -> V_50 . V_51 |= V_52 ;
V_2 -> V_45 = F_1 ;
V_2 -> V_46 = F_3 ;
if ( V_12 -> V_16 . V_27 )
V_2 -> V_10 = F_26 ( V_12 -> V_16 . V_27 , L_6 ) ;
else
V_2 -> V_10 = V_12 -> V_20 ;
V_24 = F_19 ( V_12 , V_32 , 1 ) ;
V_2 -> V_9 = F_27 ( & V_12 -> V_16 , V_24 ) ;
if ( ! V_2 -> V_9 || V_2 -> V_10 < 0 )
F_28 ( & V_12 -> V_16 , L_7 ) ;
else
V_2 -> V_53 = F_7 ;
break;
default:
V_13 = - V_29 ;
goto V_54;
}
V_16 -> V_25 = V_25 ;
V_2 -> V_5 = V_14 ;
V_2 -> V_55 = & V_12 -> V_16 ;
V_2 -> V_50 . clock . V_56 = F_29 ( V_26 ) ;
V_2 -> V_2 = V_26 ;
V_2 -> type = V_20 -> V_39 ;
F_30 ( V_12 , V_16 ) ;
F_31 ( V_16 , & V_12 -> V_16 ) ;
V_13 = F_32 ( V_16 ) ;
if ( V_13 ) {
F_13 ( & V_12 -> V_16 , L_8 ,
V_35 , V_13 ) ;
goto V_54;
}
F_28 ( & V_12 -> V_16 , L_9 ,
V_35 , V_2 -> V_5 , V_16 -> V_25 ) ;
return 0 ;
V_54:
F_30 ( V_12 , NULL ) ;
F_33 ( V_16 ) ;
V_38:
F_34 ( V_14 ) ;
V_37:
F_35 ( V_23 -> V_34 , F_22 ( V_23 ) ) ;
V_33:
F_36 ( V_26 ) ;
exit:
F_13 ( & V_12 -> V_16 , L_10 ) ;
return V_13 ;
}
static int F_37 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = F_38 ( V_12 ) ;
struct V_1 * V_2 = F_25 ( V_16 ) ;
struct V_22 * V_23 ;
F_39 ( V_16 ) ;
F_30 ( V_12 , NULL ) ;
F_33 ( V_16 ) ;
F_34 ( V_2 -> V_5 ) ;
V_23 = F_19 ( V_12 , V_32 , 0 ) ;
F_35 ( V_23 -> V_34 , F_22 ( V_23 ) ) ;
F_36 ( V_2 -> V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_11 * V_12 , T_4 V_57 )
{
int V_13 ;
struct V_15 * V_58 = F_38 ( V_12 ) ;
struct V_1 * V_2 = F_25 ( V_58 ) ;
if ( V_2 -> type != V_48 ) {
F_17 ( & V_12 -> V_16 , L_11 ) ;
return 0 ;
}
if ( F_41 ( V_58 ) ) {
F_42 ( V_58 ) ;
F_43 ( V_58 ) ;
}
V_13 = F_44 ( V_58 ) ;
if ( V_13 ) {
F_45 ( V_58 , L_12 ) ;
return V_13 ;
}
V_2 -> V_50 . V_57 = V_59 ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 )
{
int V_13 ;
struct V_15 * V_58 = F_38 ( V_12 ) ;
struct V_1 * V_2 = F_25 ( V_58 ) ;
if ( V_2 -> type != V_48 ) {
F_17 ( & V_12 -> V_16 , L_11 ) ;
return 0 ;
}
V_13 = F_47 ( V_58 ) ;
if ( V_13 ) {
F_45 ( V_58 , L_13 ) ;
return V_13 ;
}
V_2 -> V_50 . V_57 = V_60 ;
if ( F_41 ( V_58 ) ) {
F_48 ( V_58 ) ;
F_49 ( V_58 ) ;
}
return 0 ;
}
