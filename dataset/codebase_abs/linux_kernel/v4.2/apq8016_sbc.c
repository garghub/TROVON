static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) ;
int V_9 = 0 ;
switch ( V_4 -> V_10 ) {
case V_11 :
F_3 ( F_4 ( V_8 -> V_12 ) | V_13 ,
V_8 -> V_12 ) ;
break;
case V_14 :
F_3 ( F_4 ( V_8 -> V_15 ) | V_16 |
V_17 ,
V_8 -> V_15 ) ;
break;
default:
F_5 ( V_6 -> V_18 , L_1 ) ;
V_9 = - V_19 ;
break;
}
return V_9 ;
}
static struct V_7 * F_6 ( struct V_5 * V_6 )
{
struct V_20 * V_18 = V_6 -> V_18 ;
struct V_21 * V_22 ;
struct V_23 * V_24 , * V_25 , * V_26 , * V_27 = V_18 -> V_28 ;
struct V_7 * V_29 ;
int V_30 , V_31 ;
V_30 = F_7 ( V_6 , L_2 ) ;
if ( V_30 ) {
F_5 ( V_18 , L_3 , V_30 ) ;
return F_8 ( V_30 ) ;
}
V_31 = F_9 ( V_27 ) ;
V_29 = F_10 ( V_18 , sizeof( * V_29 ) + sizeof( * V_22 ) * V_31 ,
V_32 ) ;
if ( ! V_29 )
return F_8 ( - V_33 ) ;
V_6 -> V_34 = & V_29 -> V_34 [ 0 ] ;
V_6 -> V_31 = V_31 ;
V_22 = V_29 -> V_34 ;
F_11 (node, np) {
V_26 = F_12 ( V_24 , L_4 ) ;
V_25 = F_12 ( V_24 , L_5 ) ;
if ( ! V_26 || ! V_25 ) {
F_5 ( V_18 , L_6 ) ;
return F_8 ( - V_19 ) ;
}
V_22 -> V_35 = F_13 ( V_26 , L_7 , 0 ) ;
if ( ! V_22 -> V_35 ) {
F_5 ( V_6 -> V_18 , L_8 ) ;
return F_8 ( - V_19 ) ;
}
V_22 -> V_36 = F_13 ( V_25 , L_7 , 0 ) ;
if ( ! V_22 -> V_36 ) {
F_5 ( V_6 -> V_18 , L_9 ) ;
return F_8 ( - V_19 ) ;
}
V_30 = F_14 ( V_26 , & V_22 -> V_37 ) ;
if ( V_30 ) {
F_5 ( V_6 -> V_18 , L_10 ) ;
return F_8 ( V_30 ) ;
}
V_30 = F_14 ( V_25 , & V_22 -> V_38 ) ;
if ( V_30 ) {
F_5 ( V_6 -> V_18 , L_11 ) ;
return F_8 ( V_30 ) ;
}
V_22 -> V_39 = V_22 -> V_35 ;
V_22 -> V_40 = true ;
V_30 = F_15 ( V_24 , L_12 , & V_22 -> V_41 ) ;
if ( V_30 ) {
F_5 ( V_6 -> V_18 , L_13 ) ;
return F_8 ( V_30 ) ;
}
V_22 -> V_42 = V_22 -> V_41 ;
V_22 -> V_43 = F_1 ;
V_22 ++ ;
}
return V_29 ;
}
static int F_16 ( struct V_44 * V_45 )
{
struct V_20 * V_18 = & V_45 -> V_18 ;
struct V_5 * V_6 ;
struct V_7 * V_29 ;
struct V_46 * V_47 ;
V_6 = F_10 ( V_18 , sizeof( * V_6 ) , V_32 ) ;
if ( ! V_6 )
return - V_33 ;
V_6 -> V_18 = V_18 ;
V_29 = F_6 ( V_6 ) ;
if ( F_17 ( V_29 ) ) {
F_5 ( & V_45 -> V_18 , L_14 ,
F_18 ( V_29 ) ) ;
return F_18 ( V_29 ) ;
}
V_47 = F_19 ( V_45 , V_48 , L_15 ) ;
V_29 -> V_15 = F_20 ( V_18 , V_47 ) ;
if ( F_17 ( V_29 -> V_15 ) )
return F_18 ( V_29 -> V_15 ) ;
V_47 = F_19 ( V_45 , V_48 , L_16 ) ;
V_29 -> V_12 = F_20 ( V_18 , V_47 ) ;
if ( F_17 ( V_29 -> V_12 ) )
return F_18 ( V_29 -> V_12 ) ;
F_21 ( V_45 , V_29 ) ;
F_22 ( V_6 , V_29 ) ;
return F_23 ( & V_45 -> V_18 , V_6 ) ;
}
