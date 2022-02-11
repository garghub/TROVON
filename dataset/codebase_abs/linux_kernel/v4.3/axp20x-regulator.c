static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_1 V_8 , V_9 , V_10 , V_11 ;
switch ( V_5 -> V_12 ) {
case V_13 :
case V_14 :
V_8 = 750 ;
V_9 = 1875 ;
V_10 = 1500 ;
V_11 = 75 ;
break;
case V_15 :
V_8 = 1800 ;
V_9 = 4050 ;
V_10 = 3000 ;
V_11 = 150 ;
break;
default:
F_3 ( & V_2 -> V_6 ,
L_1 ) ;
return - V_16 ;
}
if ( V_3 == 0 )
V_3 = V_10 ;
if ( V_3 < V_8 ) {
V_3 = V_8 ;
F_4 ( & V_2 -> V_6 , L_2 ,
V_8 ) ;
}
if ( V_3 > V_9 ) {
V_3 = V_9 ;
F_4 ( & V_2 -> V_6 , L_3 ,
V_9 ) ;
}
V_3 = ( V_3 - V_8 ) / V_11 ;
return F_5 ( V_5 -> V_17 , V_18 ,
V_19 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_20 * V_21 , * V_22 ;
int V_23 ;
T_1 V_3 = 0 ;
V_21 = F_7 ( V_2 -> V_6 . V_7 -> V_24 ) ;
if ( ! V_21 )
return 0 ;
V_22 = F_8 ( V_21 , L_4 ) ;
if ( ! V_22 ) {
F_4 ( & V_2 -> V_6 , L_5 ) ;
} else {
F_9 ( V_22 , L_6 , & V_3 ) ;
V_23 = F_1 ( V_2 , V_3 ) ;
if ( V_23 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 , V_23 ) ;
return V_23 ;
}
F_10 ( V_22 ) ;
}
return 0 ;
}
static int F_11 ( struct V_25 * V_26 , int V_27 , T_1 V_28 )
{
struct V_4 * V_5 = F_12 ( V_26 ) ;
unsigned int V_29 ;
switch ( V_5 -> V_12 ) {
case V_13 :
case V_14 :
if ( ( V_27 != V_30 ) && ( V_27 != V_31 ) )
return - V_16 ;
V_29 = V_32 ;
if ( V_27 == V_31 )
V_29 = V_33 ;
V_28 <<= F_13 ( V_29 ) - 1 ;
break;
case V_15 :
if ( V_27 < V_34 || V_27 > V_35 )
return - V_16 ;
V_29 = F_14 ( V_27 - V_34 ) ;
V_28 <<= V_27 - V_34 ;
break;
default:
F_15 ( 1 ) ;
return - V_16 ;
}
return F_5 ( V_26 -> V_17 , V_36 , V_29 , V_28 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
const struct V_37 * V_22 ;
struct V_38 V_39 = {
. V_6 = V_2 -> V_6 . V_7 ,
. V_17 = V_5 -> V_17 ,
. V_40 = V_5 ,
} ;
int V_23 , V_41 , V_42 ;
T_1 V_28 ;
switch ( V_5 -> V_12 ) {
case V_13 :
case V_14 :
V_22 = V_43 ;
V_42 = V_44 ;
break;
case V_15 :
V_22 = V_45 ;
V_42 = V_46 ;
break;
default:
F_3 ( & V_2 -> V_6 , L_8 ,
V_5 -> V_12 ) ;
return - V_16 ;
}
F_6 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_26 = F_17 ( & V_2 -> V_6 , & V_22 [ V_41 ] ,
& V_39 ) ;
if ( F_18 ( V_26 ) ) {
F_3 ( & V_2 -> V_6 , L_9 ,
V_22 [ V_41 ] . V_47 ) ;
return F_19 ( V_26 ) ;
}
V_23 = F_9 ( V_26 -> V_6 . V_24 ,
L_10 ,
& V_28 ) ;
if ( ! V_23 ) {
if ( F_11 ( V_26 , V_41 , V_28 ) )
F_3 ( & V_2 -> V_6 , L_11 ,
V_26 -> V_48 -> V_47 ) ;
}
}
return 0 ;
}
