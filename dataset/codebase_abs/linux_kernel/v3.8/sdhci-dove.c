static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static T_2 F_3 ( struct V_3 * V_4 , int V_7 )
{
T_2 V_8 ;
switch ( V_7 ) {
case V_9 :
case V_10 :
return 0 ;
default:
V_8 = F_4 ( V_4 -> V_11 + V_7 ) ;
}
return V_8 ;
}
static T_3 F_5 ( struct V_3 * V_4 , int V_7 )
{
struct V_12 * V_13 = F_6 ( V_4 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
T_3 V_8 ;
V_8 = F_7 ( V_4 -> V_11 + V_7 ) ;
switch ( V_7 ) {
case V_16 :
V_8 &= ~ V_17 ;
break;
case V_18 :
if ( F_8 ( V_15 -> V_19 ) ) {
if ( F_9 ( V_15 -> V_19 ) == 0 )
V_8 |= V_20 ;
else
V_8 &= ~ V_20 ;
}
break;
}
return V_8 ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_8 ;
V_15 = F_11 ( & V_22 -> V_23 , sizeof( struct V_14 ) ,
V_24 ) ;
if ( ! V_15 ) {
F_12 ( & V_22 -> V_23 , L_1 ) ;
return - V_25 ;
}
V_15 -> V_26 = F_13 ( & V_22 -> V_23 , NULL ) ;
if ( V_22 -> V_23 . V_27 ) {
V_15 -> V_19 = F_14 ( V_22 -> V_23 . V_27 ,
L_2 , 0 ) ;
} else {
V_15 -> V_19 = - V_28 ;
}
if ( F_8 ( V_15 -> V_19 ) ) {
V_8 = F_15 ( V_15 -> V_19 , L_3 ) ;
if ( V_8 ) {
F_12 ( & V_22 -> V_23 , L_4 ,
V_8 ) ;
return V_8 ;
}
F_16 ( V_15 -> V_19 ) ;
}
V_4 = F_17 ( V_22 , & V_29 ) ;
if ( F_18 ( V_4 ) ) {
V_8 = F_19 ( V_4 ) ;
goto V_30;
}
V_13 = F_6 ( V_4 ) ;
V_13 -> V_15 = V_15 ;
if ( ! F_18 ( V_15 -> V_26 ) )
F_20 ( V_15 -> V_26 ) ;
F_21 ( V_22 ) ;
V_8 = F_22 ( V_4 ) ;
if ( V_8 )
goto V_31;
if ( F_8 ( V_15 -> V_19 ) ) {
V_8 = F_23 ( F_24 ( V_15 -> V_19 ) ,
F_1 ,
V_32 | V_33 ,
F_25 ( V_4 -> V_34 ) , V_4 ) ;
if ( V_8 ) {
F_12 ( & V_22 -> V_23 , L_5 ,
V_8 ) ;
goto V_35;
}
}
return 0 ;
V_35:
F_26 ( V_4 , 0 ) ;
V_31:
if ( ! F_18 ( V_15 -> V_26 ) )
F_27 ( V_15 -> V_26 ) ;
F_28 ( V_22 ) ;
V_30:
if ( F_8 ( V_15 -> V_19 ) )
F_29 ( V_15 -> V_19 ) ;
return V_8 ;
}
static int F_30 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = F_31 ( V_22 ) ;
struct V_12 * V_13 = F_6 ( V_4 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
F_32 ( V_22 ) ;
if ( F_8 ( V_15 -> V_19 ) ) {
F_33 ( F_24 ( V_15 -> V_19 ) , V_4 ) ;
F_29 ( V_15 -> V_19 ) ;
}
if ( ! F_18 ( V_15 -> V_26 ) )
F_27 ( V_15 -> V_26 ) ;
return 0 ;
}
