static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 , V_5 ,
V_6 ,
V_4 << V_7 ) ;
F_2 ( V_2 , V_5 ,
V_8 ,
V_3 << V_9 ) ;
F_2 ( V_2 , V_5 ,
V_10 ,
V_10 ) ;
F_2 ( V_2 , V_5 ,
V_10 , 0 ) ;
}
static void F_3 ( struct V_11 * V_12 )
{
F_2 ( V_12 -> V_1 , V_13 ,
V_14 ,
V_14 ) ;
F_1 ( V_12 -> V_1 , 0 ,
V_15 ) ;
}
static void F_4 ( struct V_11 * V_12 )
{
F_2 ( V_12 -> V_1 , V_16 ,
V_17 ,
V_17 ) ;
F_2 ( V_12 -> V_1 , V_16 ,
V_17 , 0 ) ;
F_1 ( V_12 -> V_1 ,
V_18 ,
V_15 ) ;
F_2 ( V_12 -> V_1 , V_13 ,
V_14 , 0 ) ;
}
static int F_5 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_6 ( V_20 ) ;
F_7 ( V_20 , V_12 -> V_1 ) ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 )
{
struct V_11 * V_12 ;
int V_23 , V_24 ;
struct V_25 * V_26 = & V_22 -> V_26 ;
T_1 V_4 ;
V_12 = F_9 ( V_26 , sizeof( * V_12 ) , V_27 ) ;
if ( ! V_12 )
return - V_28 ;
F_10 ( V_22 , V_12 ) ;
V_12 -> V_1 = F_11 ( V_22 -> V_26 . V_29 ,
L_1 ) ;
if ( F_12 ( V_12 -> V_1 ) )
return F_13 ( V_12 -> V_1 ) ;
V_12 -> V_30 = F_14 ( V_26 , L_2 ) ;
if ( F_12 ( V_12 -> V_30 ) ) {
V_23 = F_13 ( V_12 -> V_30 ) ;
if ( V_23 != - V_31 )
F_15 ( V_26 , L_3 , V_23 ) ;
return V_23 ;
}
V_23 = F_16 ( V_12 -> V_30 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_4 , V_23 ) ;
return V_23 ;
}
V_24 = F_17 ( V_12 -> V_30 ) ;
switch ( V_24 ) {
case 1800000 :
V_4 = 0 ;
break;
case 3300000 :
V_4 = V_32 ;
break;
default:
F_15 ( V_26 , L_5 , V_24 ) ;
V_23 = - V_33 ;
goto V_34;
}
F_2 ( V_12 -> V_1 , V_13 ,
V_32 , V_4 ) ;
F_3 ( V_12 ) ;
F_4 ( V_12 ) ;
F_18 ( V_26 ) ;
F_19 ( V_26 ) ;
F_20 ( V_26 ) ;
V_23 = F_21 ( V_26 , & V_35 ,
V_36 ,
F_22 ( V_36 ) ) ;
if ( V_23 ) {
F_15 ( V_26 , L_6 , V_23 ) ;
goto V_37;
}
return 0 ;
V_37:
F_23 ( & V_22 -> V_26 ) ;
F_3 ( V_12 ) ;
V_34:
F_24 ( V_12 -> V_30 ) ;
return V_23 ;
}
static int F_25 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = F_26 ( & V_22 -> V_26 ) ;
F_27 ( & V_22 -> V_26 ) ;
F_23 ( & V_22 -> V_26 ) ;
F_3 ( V_12 ) ;
F_24 ( V_12 -> V_30 ) ;
return 0 ;
}
static int F_28 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_26 ( V_26 ) ;
int V_23 ;
V_23 = F_16 ( V_12 -> V_30 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_4 , V_23 ) ;
return V_23 ;
}
F_4 ( V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_25 * V_26 )
{
struct V_11 * V_12 = F_26 ( V_26 ) ;
F_3 ( V_12 ) ;
F_24 ( V_12 -> V_30 ) ;
return 0 ;
}
