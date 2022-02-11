static
void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + F_3 ( V_5 ) ) ;
F_4 ( V_2 -> V_6 , V_7 ) ;
switch ( V_3 ) {
case V_8 :
V_2 -> V_9 = L_1 ;
V_2 -> V_10 = V_11 ;
break;
case V_12 :
V_2 -> V_9 = L_2 ;
V_2 -> V_10 = V_13 ;
break;
case V_14 :
V_2 -> V_9 = L_3 ;
V_2 -> V_10 = V_15 ;
break;
case V_16 :
V_2 -> V_9 = L_4 ;
V_2 -> V_10 = V_17 ;
break;
default:
F_5 ( V_2 , L_5 , V_3 ) ;
V_2 -> V_9 = L_6 ;
V_2 -> V_10 = V_18 ;
}
F_6 ( V_2 , L_7 , V_2 -> V_9 ) ;
if ( V_2 -> V_10 >= V_13 )
F_7 ( V_19 , V_2 -> V_6 ) ;
if ( V_2 -> V_10 >= V_17 )
F_7 ( V_20 ,
V_2 -> V_6 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
int V_21 = V_2 -> V_22 -> V_21 ;
F_9 ( V_21 ) ;
if ( V_2 -> V_23 == 3 ) {
F_9 ( V_21 + 1 ) ;
F_9 ( V_21 + 2 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
int V_21 = V_2 -> V_22 -> V_21 ;
F_11 ( V_21 ) ;
if ( V_2 -> V_23 == 3 ) {
F_11 ( V_21 + 1 ) ;
F_11 ( V_21 + 2 ) ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_24 * V_22 = V_2 -> V_22 ;
int V_25 ;
int V_26 = V_22 -> V_27 ;
F_13 ( V_2 , L_8 , V_28 ) ;
V_22 -> V_27 = 0 ;
F_14 ( V_22 ) ;
switch ( V_29 ) {
case 3 :
case 1 :
F_13 ( V_2 , L_9 , V_29 ) ;
break;
case 0 :
F_13 ( V_2 , L_10 ) ;
break;
default:
F_5 ( V_2 , L_11 , V_29 ) ;
V_29 = 1 ;
}
if ( V_29 == 3 && F_15 ( V_22 , 3 , 3 ) < 0 ) {
F_5 ( V_2 , L_12 ) ;
V_29 = 1 ;
}
if ( V_29 == 1 && F_16 ( V_22 ) ) {
F_5 ( V_2 , L_13 ) ;
V_29 = 0 ;
}
V_2 -> V_23 = V_29 ;
if ( ( V_2 -> V_23 == 0 ) && V_26 ) {
F_5 ( V_2 , L_14 ) ;
V_25 = - V_30 ;
goto V_31;
}
V_25 = F_17 ( V_2 , V_22 -> V_21 ) ;
if ( V_25 )
goto V_31;
F_18 ( & V_2 -> V_32 ) ;
V_25 = F_19 ( V_2 ) ;
F_20 ( & V_2 -> V_32 ) ;
if ( V_33 )
V_25 = 0 ;
if ( V_25 )
goto V_34;
return 0 ;
V_34:
F_21 ( V_2 , V_22 -> V_21 ) ;
F_22 ( V_22 ) ;
V_31:
F_23 ( V_22 ) ;
return V_25 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_24 * V_22 = V_2 -> V_22 ;
F_13 ( V_2 , L_8 , V_28 ) ;
F_23 ( V_22 ) ;
F_21 ( V_2 , V_22 -> V_21 ) ;
F_22 ( V_22 ) ;
return 0 ;
}
static int F_25 ( struct V_24 * V_22 , const struct V_35 * V_36 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 = & V_22 -> V_38 ;
void T_2 * V_4 ;
int V_25 ;
F_26 ( & V_22 -> V_38 , V_39
L_15 ,
( int ) V_22 -> V_40 , ( int ) V_22 -> V_37 , ( int ) V_22 -> V_41 ) ;
if ( F_27 ( V_22 , 0 ) != V_42 ) {
F_28 ( & V_22 -> V_38 , L_16 V_39 L_17
L_18 ,
( V_43 ) F_27 ( V_22 , 0 ) , V_42 ) ;
return - V_30 ;
}
V_25 = F_29 ( V_22 ) ;
if ( V_25 ) {
F_28 ( & V_22 -> V_38 ,
L_19 ) ;
V_22 -> V_27 = 1 ;
V_25 = F_29 ( V_22 ) ;
}
if ( V_25 )
return - V_30 ;
V_25 = F_30 ( V_22 , 0 , V_39 ) ;
if ( V_25 ) {
F_28 ( & V_22 -> V_38 , L_20 ) ;
goto V_44;
}
V_4 = F_31 ( V_22 , 0 ) ;
if ( ! V_4 ) {
F_28 ( & V_22 -> V_38 , L_21 ) ;
V_25 = - V_30 ;
goto V_45;
}
F_26 ( & V_22 -> V_38 , L_22 , & V_22 -> V_46 [ 0 ] , V_4 ) ;
V_2 = F_32 ( V_38 , V_4 ) ;
if ( F_33 ( V_2 ) ) {
V_25 = ( int ) F_34 ( V_2 ) ;
F_28 ( V_38 , L_23 , V_25 ) ;
goto V_47;
}
F_35 ( V_22 , V_2 ) ;
V_2 -> V_22 = V_22 ;
F_1 ( V_2 ) ;
F_36 ( V_2 ) ;
V_2 -> V_48 =
F_37 ( & V_22 -> V_38 , & V_2 -> V_49 ) ;
V_25 = F_12 ( V_2 ) ;
if ( V_25 ) {
F_5 ( V_2 , L_24 ) ;
goto V_50;
}
V_25 = F_38 ( V_2 ) ;
if ( V_25 ) {
F_5 ( V_2 , L_25 , V_25 ) ;
goto V_51;
}
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
V_51:
F_24 ( V_2 ) ;
V_50:
if ( V_2 -> V_49 . V_52 )
V_2 -> V_49 . V_52 ( V_2 -> V_48 ) ;
F_41 ( V_2 ) ;
V_47:
F_42 ( V_22 , V_4 ) ;
V_45:
F_43 ( V_22 , 0 ) ;
V_44:
F_44 ( V_22 ) ;
return V_25 ;
}
static void F_45 ( struct V_24 * V_22 )
{
struct V_1 * V_2 = F_46 ( V_22 ) ;
void T_2 * V_4 = V_2 -> V_4 ;
F_13 ( V_2 , L_8 , V_28 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( V_2 -> V_49 . V_52 )
V_2 -> V_49 . V_52 ( V_2 -> V_48 ) ;
F_41 ( V_2 ) ;
F_42 ( V_22 , V_4 ) ;
F_43 ( V_22 , 0 ) ;
F_44 ( V_22 ) ;
}
