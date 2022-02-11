static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
return V_5 ;
}
static inline struct V_6 * F_3 (
struct V_3 * V_7 )
{
return F_4 ( V_7 ) ;
}
static int F_5 ( struct V_3 * V_7 ,
enum V_8 V_9 , union V_10 * V_11 )
{
struct V_6 * V_6 = F_3 ( V_7 ) ;
switch ( V_9 ) {
case V_12 :
if ( ! V_6 -> V_13 ) {
V_11 -> V_14 = V_15 ;
break;
}
if ( F_6 ( V_6 -> V_13 ) )
V_11 -> V_14 = V_16 ;
else
V_11 -> V_14 = V_17 ;
break;
case V_18 :
V_11 -> V_14 = F_6 ( V_6 -> V_19 ) ;
break;
case V_20 :
if ( ! V_6 -> V_21 ) {
V_11 -> V_14 = V_22 ;
break;
}
if ( ! F_6 ( V_6 -> V_21 ) ) {
V_11 -> V_14 = V_23 ;
break;
}
if ( ! V_6 -> V_13 ) {
V_11 -> V_14 = V_24 ;
break;
}
V_11 -> V_14 = F_6 ( V_6 -> V_13 ) ?
V_25 :
V_26 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_7 ( struct V_28 * V_29 )
{
struct V_30 V_31 = {} ;
struct V_6 * V_6 ;
struct V_32 * V_33 ;
int V_34 ;
V_6 = F_8 ( & V_29 -> V_35 , sizeof( * V_6 ) ,
V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_6 -> V_19 = F_9 ( & V_29 -> V_35 ,
L_1 , V_38 ) ;
if ( F_10 ( V_6 -> V_19 ) ) {
V_34 = F_11 ( V_6 -> V_19 ) ;
F_12 ( & V_29 -> V_35 , L_2 , V_34 ) ;
return V_34 ;
}
V_6 -> V_21 = F_13 ( & V_29 -> V_35 ,
L_3 , V_38 ) ;
if ( F_10 ( V_6 -> V_21 ) ) {
V_34 = F_11 ( V_6 -> V_21 ) ;
F_12 ( & V_29 -> V_35 , L_4 , V_34 ) ;
return V_34 ;
}
V_6 -> V_13 = F_13 ( & V_29 -> V_35 ,
L_5 , V_38 ) ;
if ( F_10 ( V_6 -> V_13 ) ) {
V_34 = F_11 ( V_6 -> V_13 ) ;
F_12 ( & V_29 -> V_35 , L_6 , V_34 ) ;
return V_34 ;
}
V_33 = & V_6 -> V_33 ;
V_33 -> V_39 = V_29 -> V_35 . V_40 -> V_39 ;
V_33 -> type = V_41 ;
V_33 -> V_42 = V_43 ;
V_33 -> V_44 = F_14 ( V_43 ) ;
V_33 -> V_45 = F_5 ;
V_31 . V_40 = V_29 -> V_35 . V_40 ;
V_31 . V_46 = V_6 ;
V_6 -> V_4 = F_15 ( & V_29 -> V_35 ,
V_33 , & V_31 ) ;
if ( F_10 ( V_6 -> V_4 ) ) {
V_34 = F_11 ( V_6 -> V_4 ) ;
F_12 ( & V_29 -> V_35 , L_7 ,
V_34 ) ;
return V_34 ;
}
if ( V_6 -> V_19 ) {
V_34 = F_16 ( V_6 -> V_19 ) ;
if ( V_34 >= 0 )
V_34 = F_17 ( & V_29 -> V_35 , V_34 ,
F_1 ,
V_47 | V_48 ,
F_18 ( & V_29 -> V_35 ) , V_6 -> V_4 ) ;
if ( V_34 < 0 )
F_19 ( & V_29 -> V_35 , L_8 ) ;
}
if ( V_6 -> V_21 ) {
V_34 = F_16 ( V_6 -> V_21 ) ;
if ( V_34 >= 0 )
V_34 = F_17 ( & V_29 -> V_35 , V_34 ,
F_1 ,
V_47 | V_48 ,
F_18 ( & V_29 -> V_35 ) , V_6 -> V_4 ) ;
if ( V_34 < 0 )
F_19 ( & V_29 -> V_35 , L_9 ) ;
}
if ( V_6 -> V_13 ) {
V_34 = F_16 ( V_6 -> V_13 ) ;
if ( V_34 >= 0 )
V_34 = F_17 ( & V_29 -> V_35 , V_34 ,
F_1 ,
V_47 | V_48 ,
F_18 ( & V_29 -> V_35 ) , V_6 -> V_4 ) ;
if ( V_34 < 0 )
F_19 ( & V_29 -> V_35 , L_10 ) ;
}
F_20 ( V_29 , V_6 ) ;
return 0 ;
}
