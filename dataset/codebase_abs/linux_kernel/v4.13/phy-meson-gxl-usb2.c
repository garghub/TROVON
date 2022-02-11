static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_3 -> V_4 ) {
F_3 ( V_3 -> V_5 , V_6 , V_7 ,
V_7 ) ;
F_4 ( V_8 ) ;
F_3 ( V_3 -> V_5 , V_6 , V_7 ,
0 ) ;
F_4 ( V_8 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , enum V_9 V_10 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
switch ( V_10 ) {
case V_11 :
case V_12 :
F_3 ( V_3 -> V_5 , V_6 , V_13 ,
V_13 ) ;
F_3 ( V_3 -> V_5 , V_6 , V_14 ,
V_14 ) ;
F_3 ( V_3 -> V_5 , V_6 , V_15 , 0 ) ;
break;
case V_16 :
F_3 ( V_3 -> V_5 , V_6 , V_13 ,
0 ) ;
F_3 ( V_3 -> V_5 , V_6 , V_14 ,
0 ) ;
F_3 ( V_3 -> V_5 , V_6 , V_15 ,
V_15 ) ;
break;
default:
return - V_17 ;
}
F_1 ( V_1 ) ;
V_3 -> V_10 = V_10 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
V_3 -> V_4 = 0 ;
F_3 ( V_3 -> V_5 , V_6 , V_7 ,
V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_18 ;
V_3 -> V_4 = 1 ;
F_3 ( V_3 -> V_5 , V_6 , V_7 , 0 ) ;
V_18 = F_5 ( V_1 , V_3 -> V_10 ) ;
if ( V_18 ) {
F_6 ( V_1 ) ;
F_8 ( & V_1 -> V_19 , L_1 ,
V_3 -> V_10 ) ;
return V_18 ;
}
return 0 ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_22 * V_19 = & V_21 -> V_19 ;
struct V_23 * V_23 ;
struct V_24 * V_25 ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
void T_1 * V_26 ;
V_3 = F_10 ( V_19 , sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
F_11 ( V_21 , V_3 ) ;
V_25 = F_12 ( V_21 , V_29 , 0 ) ;
V_26 = F_13 ( V_19 , V_25 ) ;
if ( F_14 ( V_26 ) )
return F_15 ( V_26 ) ;
switch ( F_16 ( V_19 -> V_30 , - 1 ) ) {
case V_31 :
V_3 -> V_10 = V_16 ;
break;
case V_32 :
V_3 -> V_10 = V_12 ;
break;
case V_33 :
default:
V_3 -> V_10 = V_11 ;
break;
}
V_3 -> V_5 = F_17 ( V_19 , V_26 ,
& V_34 ) ;
if ( F_14 ( V_3 -> V_5 ) )
return F_15 ( V_3 -> V_5 ) ;
V_1 = F_18 ( V_19 , NULL , & V_35 ) ;
if ( F_14 ( V_1 ) ) {
F_8 ( V_19 , L_2 ) ;
return F_15 ( V_1 ) ;
}
F_19 ( V_1 , V_3 ) ;
V_23 = F_20 ( V_19 , V_36 ) ;
return F_21 ( V_23 ) ;
}
