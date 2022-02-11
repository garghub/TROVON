static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = F_3 ( V_9 -> V_12 + V_13 ) ;
* V_5 = V_10 >> V_14 ;
* V_5 &= V_15 ;
return V_16 ;
case V_17 :
* V_5 = F_4 ( V_9 -> V_18 ) / 1000 ;
* V_6 = 10 ;
return V_19 ;
}
return - V_20 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int V_5 , int V_6 , long V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 ;
switch ( V_7 ) {
case V_11 :
if ( V_5 < 0 || V_5 > V_15 )
return - V_20 ;
V_10 = V_21 ;
V_10 |= V_5 << V_14 ;
F_6 ( & V_9 -> V_22 ) ;
F_7 ( V_10 , V_9 -> V_12 + V_13 ) ;
F_7 ( V_23 , V_9 -> V_12 + V_24 ) ;
F_8 ( & V_9 -> V_22 ) ;
return 0 ;
}
return - V_20 ;
}
static int F_9 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_27 * V_28 ;
int V_29 ;
V_2 = F_10 ( & V_26 -> V_30 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_31 ;
F_11 ( V_26 , V_2 ) ;
V_9 = F_2 ( V_2 ) ;
F_12 ( & V_9 -> V_22 ) ;
V_28 = F_13 ( V_26 , V_32 , 0 ) ;
V_9 -> V_12 = F_14 ( & V_26 -> V_30 , V_28 ) ;
if ( F_15 ( V_9 -> V_12 ) )
return F_16 ( V_9 -> V_12 ) ;
V_9 -> V_33 = F_17 ( & V_26 -> V_30 , NULL ) ;
if ( F_15 ( V_9 -> V_33 ) ) {
F_18 ( & V_26 -> V_30 , L_1 ) ;
return F_16 ( V_9 -> V_33 ) ;
}
V_9 -> V_18 = F_19 ( & V_26 -> V_30 , L_2 ) ;
if ( F_15 ( V_9 -> V_18 ) ) {
F_18 ( & V_26 -> V_30 , L_3 ) ;
return F_16 ( V_9 -> V_18 ) ;
}
V_2 -> V_34 = F_20 ( & V_26 -> V_30 ) ;
V_2 -> V_30 . V_35 = & V_26 -> V_30 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = F_21 ( V_41 ) ;
V_29 = F_22 ( V_9 -> V_18 ) ;
if ( V_29 ) {
F_18 ( & V_26 -> V_30 , L_4 ) ;
return V_29 ;
}
V_29 = F_23 ( V_9 -> V_33 ) ;
if ( V_29 ) {
F_18 ( & V_26 -> V_30 , L_5 ) ;
goto V_43;
}
F_7 ( 0 , V_9 -> V_12 + V_24 ) ;
F_7 ( 0 , V_9 -> V_12 + V_13 ) ;
V_29 = F_24 ( V_2 ) ;
if ( V_29 ) {
F_18 ( & V_26 -> V_30 , L_6 ) ;
goto V_44;
}
return 0 ;
V_44:
F_25 ( V_9 -> V_33 ) ;
V_43:
F_26 ( V_9 -> V_18 ) ;
return V_29 ;
}
static int F_27 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_28 ( V_26 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_29 ( V_2 ) ;
F_7 ( 0 , V_9 -> V_12 + V_24 ) ;
F_25 ( V_9 -> V_33 ) ;
F_26 ( V_9 -> V_18 ) ;
return 0 ;
}
