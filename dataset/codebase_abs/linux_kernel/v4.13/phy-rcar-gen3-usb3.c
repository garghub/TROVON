static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 = V_5 |
V_6 | V_7 ;
if ( V_3 )
V_4 |= V_8 ;
F_2 ( V_4 , V_2 -> V_9 + V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_4 = V_11 ;
switch ( V_2 -> V_12 ) {
case 4980 :
V_4 |= V_13 ;
break;
case 4492 :
V_4 |= V_14 ;
break;
case 4003 :
V_4 |= V_15 ;
break;
default:
F_4 ( & V_2 -> V_16 -> V_17 , L_1 , V_18 ,
V_2 -> V_12 ) ;
return;
}
F_2 ( V_4 , V_2 -> V_9 + V_19 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
if ( V_2 -> V_12 )
F_3 ( V_2 ) ;
F_2 ( V_20 | V_21 ,
V_2 -> V_9 + V_22 ) ;
F_2 ( V_23 , V_2 -> V_9 + V_24 ) ;
F_1 ( V_2 , true ) ;
F_6 ( 10 , 20 ) ;
F_1 ( V_2 , false ) ;
}
static int F_7 ( struct V_16 * V_25 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
F_9 ( & V_2 -> V_16 -> V_17 , L_2 , V_18 ,
V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_12 ) ;
if ( ! V_2 -> V_26 && V_2 -> V_27 )
F_5 ( V_2 ) ;
F_2 ( V_28 , V_2 -> V_9 + V_29 ) ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 )
{
struct V_32 * V_17 = & V_31 -> V_17 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_37 = 0 ;
struct V_38 * V_38 ;
if ( ! V_17 -> V_39 ) {
F_4 ( V_17 , L_3 ) ;
return - V_40 ;
}
V_2 = F_11 ( V_17 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_36 = F_12 ( V_31 , V_43 , 0 ) ;
V_2 -> V_9 = F_13 ( V_17 , V_36 ) ;
if ( F_14 ( V_2 -> V_9 ) )
return F_15 ( V_2 -> V_9 ) ;
V_38 = F_16 ( V_17 , L_4 ) ;
if ( ! F_14 ( V_38 ) && ! F_17 ( V_38 ) ) {
V_2 -> V_26 = ! ! F_18 ( V_38 ) ;
F_19 ( V_38 ) ;
}
V_38 = F_16 ( V_17 , L_5 ) ;
if ( ! F_14 ( V_38 ) && ! F_17 ( V_38 ) ) {
V_2 -> V_27 = ! ! F_18 ( V_38 ) ;
F_19 ( V_38 ) ;
}
if ( ! V_2 -> V_26 && ! V_2 -> V_27 ) {
F_4 ( V_17 , L_6 ) ;
V_37 = - V_40 ;
goto error;
}
F_20 ( V_17 ) ;
V_2 -> V_16 = F_21 ( V_17 , NULL , & V_44 ) ;
if ( F_14 ( V_2 -> V_16 ) ) {
F_4 ( V_17 , L_7 ) ;
V_37 = F_15 ( V_2 -> V_16 ) ;
goto error;
}
F_22 ( V_17 -> V_39 , L_8 , & V_2 -> V_12 ) ;
F_23 ( V_31 , V_2 ) ;
F_24 ( V_2 -> V_16 , V_2 ) ;
V_34 = F_25 ( V_17 , V_45 ) ;
if ( F_14 ( V_34 ) ) {
F_4 ( V_17 , L_9 ) ;
V_37 = F_15 ( V_34 ) ;
goto error;
}
return 0 ;
error:
F_26 ( V_17 ) ;
return V_37 ;
}
static int F_27 ( struct V_30 * V_31 )
{
F_26 ( & V_31 -> V_17 ) ;
return 0 ;
}
