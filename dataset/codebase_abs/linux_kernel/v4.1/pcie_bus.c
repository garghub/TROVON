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
default:
F_5 ( V_2 , L_2 , V_3 ) ;
V_2 -> V_9 = L_3 ;
V_2 -> V_10 = V_12 ;
}
F_6 ( V_2 , L_4 , V_2 -> V_9 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
int V_13 = V_2 -> V_14 -> V_13 ;
F_8 ( V_13 ) ;
if ( V_2 -> V_15 == 3 ) {
F_8 ( V_13 + 1 ) ;
F_8 ( V_13 + 2 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
int V_13 = V_2 -> V_14 -> V_13 ;
F_10 ( V_13 ) ;
if ( V_2 -> V_15 == 3 ) {
F_10 ( V_13 + 1 ) ;
F_10 ( V_13 + 2 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_14 = V_2 -> V_14 ;
int V_17 ;
int V_18 = V_14 -> V_19 ;
F_12 ( V_2 , L_5 , V_20 ) ;
V_14 -> V_19 = 0 ;
F_13 ( V_14 ) ;
switch ( V_21 ) {
case 3 :
case 1 :
F_12 ( V_2 , L_6 , V_21 ) ;
break;
case 0 :
F_12 ( V_2 , L_7 ) ;
break;
default:
F_5 ( V_2 , L_8 , V_21 ) ;
V_21 = 1 ;
}
if ( V_21 == 3 && F_14 ( V_14 , 3 , 3 ) < 0 ) {
F_5 ( V_2 , L_9 ) ;
V_21 = 1 ;
}
if ( V_21 == 1 && F_15 ( V_14 ) ) {
F_5 ( V_2 , L_10 ) ;
V_21 = 0 ;
}
V_2 -> V_15 = V_21 ;
if ( ( V_2 -> V_15 == 0 ) && V_18 ) {
F_5 ( V_2 , L_11 ) ;
V_17 = - V_22 ;
goto V_23;
}
V_17 = F_16 ( V_2 , V_14 -> V_13 ) ;
if ( V_17 )
goto V_23;
F_17 ( & V_2 -> V_24 ) ;
V_17 = F_18 ( V_2 , false ) ;
F_19 ( & V_2 -> V_24 ) ;
if ( V_25 )
V_17 = 0 ;
if ( V_17 )
goto V_26;
return 0 ;
V_26:
F_20 ( V_2 , V_14 -> V_13 ) ;
F_21 ( V_14 ) ;
V_23:
F_22 ( V_14 ) ;
return V_17 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_16 * V_14 = V_2 -> V_14 ;
F_12 ( V_2 , L_5 , V_20 ) ;
F_22 ( V_14 ) ;
F_20 ( V_2 , V_14 -> V_13 ) ;
F_21 ( V_14 ) ;
return 0 ;
}
static int F_24 ( struct V_16 * V_14 , const struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 = & V_14 -> V_30 ;
void T_2 * V_4 ;
int V_17 ;
F_25 ( & V_14 -> V_30 , V_31
L_12 ,
( int ) V_14 -> V_32 , ( int ) V_14 -> V_29 , ( int ) V_14 -> V_33 ) ;
if ( F_26 ( V_14 , 0 ) != V_34 ) {
F_27 ( & V_14 -> V_30 , L_13 V_31 L_14
L_15 ,
( V_35 ) F_26 ( V_14 , 0 ) , V_34 ) ;
return - V_22 ;
}
V_17 = F_28 ( V_14 ) ;
if ( V_17 ) {
F_27 ( & V_14 -> V_30 ,
L_16 ) ;
V_14 -> V_19 = 1 ;
V_17 = F_28 ( V_14 ) ;
}
if ( V_17 )
return - V_22 ;
V_17 = F_29 ( V_14 , 0 , V_31 ) ;
if ( V_17 ) {
F_27 ( & V_14 -> V_30 , L_17 ) ;
goto V_36;
}
V_4 = F_30 ( V_14 , 0 ) ;
if ( ! V_4 ) {
F_27 ( & V_14 -> V_30 , L_18 ) ;
V_17 = - V_22 ;
goto V_37;
}
F_25 ( & V_14 -> V_30 , L_19 , & V_14 -> V_38 [ 0 ] , V_4 ) ;
V_2 = F_31 ( V_30 , V_4 ) ;
if ( F_32 ( V_2 ) ) {
V_17 = ( int ) F_33 ( V_2 ) ;
F_27 ( V_30 , L_20 , V_17 ) ;
goto V_39;
}
F_34 ( V_14 , V_2 ) ;
V_2 -> V_14 = V_14 ;
F_1 ( V_2 ) ;
F_35 ( V_2 ) ;
V_2 -> V_40 =
F_36 ( & V_14 -> V_30 , & V_2 -> V_41 ) ;
V_17 = F_11 ( V_2 ) ;
if ( V_17 ) {
F_5 ( V_2 , L_21 ) ;
goto V_42;
}
V_17 = F_37 ( V_2 ) ;
if ( V_17 ) {
F_5 ( V_2 , L_22 , V_17 ) ;
goto V_43;
}
F_38 ( V_2 ) ;
return 0 ;
V_43:
F_23 ( V_2 ) ;
V_42:
if ( V_2 -> V_41 . V_44 )
V_2 -> V_41 . V_44 ( V_2 -> V_40 ) ;
F_39 ( V_2 ) ;
V_39:
F_40 ( V_14 , V_4 ) ;
V_37:
F_41 ( V_14 , 0 ) ;
V_36:
F_42 ( V_14 ) ;
return V_17 ;
}
static void F_43 ( struct V_16 * V_14 )
{
struct V_1 * V_2 = F_44 ( V_14 ) ;
void T_2 * V_4 = V_2 -> V_4 ;
F_12 ( V_2 , L_5 , V_20 ) ;
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( V_2 -> V_41 . V_44 )
V_2 -> V_41 . V_44 ( V_2 -> V_40 ) ;
F_39 ( V_2 ) ;
F_40 ( V_14 , V_4 ) ;
F_41 ( V_14 , 0 ) ;
F_42 ( V_14 ) ;
}
