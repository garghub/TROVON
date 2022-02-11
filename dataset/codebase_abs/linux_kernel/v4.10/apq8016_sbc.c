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
case V_18 :
F_3 ( F_4 ( V_8 -> V_15 ) | V_19 |
V_17 ,
V_8 -> V_15 ) ;
break;
default:
F_5 ( V_6 -> V_20 , L_1 ) ;
V_9 = - V_21 ;
break;
}
return V_9 ;
}
static struct V_7 * F_6 ( struct V_5 * V_6 )
{
struct V_22 * V_20 = V_6 -> V_20 ;
struct V_23 * V_24 ;
struct V_25 * V_26 , * V_27 , * V_28 , * V_29 = V_20 -> V_30 ;
struct V_7 * V_31 ;
int V_32 , V_33 ;
V_32 = F_7 ( V_6 , L_2 ) ;
if ( V_32 ) {
F_5 ( V_20 , L_3 , V_32 ) ;
return F_8 ( V_32 ) ;
}
if ( F_9 ( V_29 , L_4 ) ) {
V_32 = F_10 ( V_6 ,
L_4 ) ;
if ( V_32 )
return F_8 ( V_32 ) ;
}
V_33 = F_11 ( V_29 ) ;
V_31 = F_12 ( V_20 , sizeof( * V_31 ) + sizeof( * V_24 ) * V_33 ,
V_34 ) ;
if ( ! V_31 )
return F_8 ( - V_35 ) ;
V_6 -> V_36 = & V_31 -> V_36 [ 0 ] ;
V_6 -> V_33 = V_33 ;
V_24 = V_31 -> V_36 ;
F_13 (node, np) {
V_28 = F_14 ( V_26 , L_5 ) ;
V_27 = F_14 ( V_26 , L_6 ) ;
if ( ! V_28 || ! V_27 ) {
F_5 ( V_20 , L_7 ) ;
return F_8 ( - V_21 ) ;
}
V_24 -> V_37 = F_15 ( V_28 , L_8 , 0 ) ;
if ( ! V_24 -> V_37 ) {
F_5 ( V_6 -> V_20 , L_9 ) ;
return F_8 ( - V_21 ) ;
}
V_32 = F_16 ( V_28 , & V_24 -> V_38 ) ;
if ( V_32 ) {
F_5 ( V_6 -> V_20 , L_10 ) ;
return F_8 ( V_32 ) ;
}
V_32 = F_17 ( V_20 , V_27 , V_24 ) ;
if ( V_32 < 0 ) {
F_5 ( V_6 -> V_20 , L_11 ) ;
return F_8 ( V_32 ) ;
}
V_24 -> V_39 = V_24 -> V_37 ;
V_32 = F_18 ( V_26 , L_12 , & V_24 -> V_40 ) ;
if ( V_32 ) {
F_5 ( V_6 -> V_20 , L_13 ) ;
return F_8 ( V_32 ) ;
}
V_24 -> V_41 = V_24 -> V_40 ;
V_24 -> V_42 = F_1 ;
V_24 ++ ;
}
return V_31 ;
}
static int F_19 ( struct V_43 * V_44 )
{
struct V_22 * V_20 = & V_44 -> V_20 ;
struct V_5 * V_6 ;
struct V_7 * V_31 ;
struct V_45 * V_46 ;
V_6 = F_12 ( V_20 , sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 )
return - V_35 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_47 = V_48 ;
V_6 -> V_49 = F_20 ( V_48 ) ;
V_31 = F_6 ( V_6 ) ;
if ( F_21 ( V_31 ) ) {
F_5 ( & V_44 -> V_20 , L_14 ,
F_22 ( V_31 ) ) ;
return F_22 ( V_31 ) ;
}
V_46 = F_23 ( V_44 , V_50 , L_15 ) ;
V_31 -> V_15 = F_24 ( V_20 , V_46 ) ;
if ( F_21 ( V_31 -> V_15 ) )
return F_22 ( V_31 -> V_15 ) ;
V_46 = F_23 ( V_44 , V_50 , L_16 ) ;
V_31 -> V_12 = F_24 ( V_20 , V_46 ) ;
if ( F_21 ( V_31 -> V_12 ) )
return F_22 ( V_31 -> V_12 ) ;
F_25 ( V_44 , V_31 ) ;
F_26 ( V_6 , V_31 ) ;
return F_27 ( & V_44 -> V_20 , V_6 ) ;
}
