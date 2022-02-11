void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 -> V_3 ;
F_2 ( V_3 ) ;
if ( V_2 -> V_5 == 3 ) {
F_2 ( V_3 + 1 ) ;
F_2 ( V_3 + 2 ) ;
}
}
void F_3 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 -> V_3 ;
F_4 ( V_3 ) ;
if ( V_2 -> V_5 == 3 ) {
F_4 ( V_3 + 1 ) ;
F_4 ( V_3 + 2 ) ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_4 = V_2 -> V_4 ;
int V_7 ;
int V_8 = V_4 -> V_9 ;
F_6 ( V_2 , L_1 , V_10 ) ;
V_4 -> V_9 = 0 ;
F_7 ( V_4 ) ;
switch ( V_11 ) {
case 3 :
case 1 :
F_6 ( V_2 , L_2 , V_11 ) ;
break;
case 0 :
F_6 ( V_2 , L_3 ) ;
break;
default:
F_8 ( V_2 , L_4 , V_11 ) ;
V_11 = 1 ;
}
if ( V_11 == 3 && F_9 ( V_4 , 3 , 3 ) < 0 ) {
F_8 ( V_2 , L_5 ) ;
V_11 = 1 ;
}
if ( V_11 == 1 && F_10 ( V_4 ) ) {
F_8 ( V_2 , L_6 ) ;
V_11 = 0 ;
}
V_2 -> V_5 = V_11 ;
if ( ( V_2 -> V_5 == 0 ) && V_8 ) {
F_8 ( V_2 , L_7 ) ;
V_7 = - V_12 ;
goto V_13;
}
V_7 = F_11 ( V_2 , V_4 -> V_3 ) ;
if ( V_7 )
goto V_13;
F_12 ( & V_2 -> V_14 ) ;
V_7 = F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_14 ) ;
if ( V_15 )
V_7 = 0 ;
if ( V_7 )
goto V_16;
return 0 ;
V_16:
F_15 ( V_2 , V_4 -> V_3 ) ;
F_16 ( V_4 ) ;
V_13:
F_17 ( V_4 ) ;
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_4 = V_2 -> V_4 ;
F_6 ( V_2 , L_1 , V_10 ) ;
F_17 ( V_4 ) ;
F_15 ( V_2 , V_4 -> V_3 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_4 , const struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 = & V_4 -> V_20 ;
void T_1 * V_21 ;
struct V_22 * V_23 = (struct V_22 * ) V_18 -> V_24 ;
int V_7 ;
F_20 ( & V_4 -> V_20 , V_25
L_8 , V_23 -> V_26 ,
( int ) V_4 -> V_27 , ( int ) V_4 -> V_19 , ( int ) V_4 -> V_28 ) ;
if ( F_21 ( V_4 , 0 ) != V_29 ) {
F_22 ( & V_4 -> V_20 , L_9 V_25 L_10
L_11 ,
( V_30 ) F_21 ( V_4 , 0 ) , V_29 ) ;
return - V_12 ;
}
V_7 = F_23 ( V_4 ) ;
if ( V_7 ) {
F_22 ( & V_4 -> V_20 ,
L_12 ) ;
V_4 -> V_9 = 1 ;
V_7 = F_23 ( V_4 ) ;
}
if ( V_7 )
return - V_12 ;
V_7 = F_24 ( V_4 , 0 , V_25 ) ;
if ( V_7 ) {
F_22 ( & V_4 -> V_20 , L_13 ) ;
goto V_31;
}
V_21 = F_25 ( V_4 , 0 ) ;
if ( ! V_21 ) {
F_22 ( & V_4 -> V_20 , L_14 ) ;
V_7 = - V_12 ;
goto V_32;
}
F_20 ( & V_4 -> V_20 , L_15 , & V_4 -> V_33 [ 0 ] , V_21 ) ;
V_2 = F_26 ( V_20 , V_21 ) ;
if ( F_27 ( V_2 ) ) {
V_7 = ( int ) F_28 ( V_2 ) ;
F_22 ( V_20 , L_16 , V_7 ) ;
goto V_34;
}
F_29 ( V_4 , V_2 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_23 = V_23 ;
F_30 ( V_2 ) ;
V_2 -> V_35 =
F_31 ( & V_4 -> V_20 , & V_2 -> V_36 ) ;
V_7 = F_5 ( V_2 ) ;
if ( V_7 ) {
F_8 ( V_2 , L_17 ) ;
goto V_37;
}
V_7 = F_32 ( V_2 ) ;
if ( V_7 ) {
F_8 ( V_2 , L_18 , V_7 ) ;
goto V_38;
}
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
return 0 ;
V_38:
F_18 ( V_2 ) ;
V_37:
if ( V_2 -> V_36 . V_39 )
V_2 -> V_36 . V_39 ( V_2 -> V_35 ) ;
F_35 ( V_2 ) ;
V_34:
F_36 ( V_4 , V_21 ) ;
V_32:
F_37 ( V_4 , 0 ) ;
V_31:
F_38 ( V_4 ) ;
return V_7 ;
}
static void F_39 ( struct V_6 * V_4 )
{
struct V_1 * V_2 = F_40 ( V_4 ) ;
void T_1 * V_21 = V_2 -> V_21 ;
F_6 ( V_2 , L_1 , V_10 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_18 ( V_2 ) ;
if ( V_2 -> V_36 . V_39 )
V_2 -> V_36 . V_39 ( V_2 -> V_35 ) ;
F_35 ( V_2 ) ;
F_36 ( V_4 , V_21 ) ;
F_37 ( V_4 , 0 ) ;
F_38 ( V_4 ) ;
}
