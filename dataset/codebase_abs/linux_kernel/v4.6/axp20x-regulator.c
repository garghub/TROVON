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
case V_16 :
V_8 = 1800 ;
V_9 = 4050 ;
V_10 = 3000 ;
V_11 = 150 ;
break;
default:
F_3 ( & V_2 -> V_6 ,
L_1 ) ;
return - V_17 ;
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
return F_5 ( V_5 -> V_18 , V_19 ,
V_20 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_21 * V_22 , * V_23 ;
int V_24 ;
T_1 V_3 = 0 ;
V_22 = F_7 ( V_2 -> V_6 . V_7 -> V_25 ) ;
if ( ! V_22 )
return 0 ;
V_23 = F_8 ( V_22 , L_4 ) ;
if ( ! V_23 ) {
F_4 ( & V_2 -> V_6 , L_5 ) ;
} else {
F_9 ( V_23 , L_6 , & V_3 ) ;
V_24 = F_1 ( V_2 , V_3 ) ;
if ( V_24 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 , V_24 ) ;
return V_24 ;
}
F_10 ( V_23 ) ;
}
return 0 ;
}
static int F_11 ( struct V_26 * V_27 , int V_28 , T_1 V_29 )
{
struct V_4 * V_5 = F_12 ( V_27 ) ;
unsigned int V_30 ;
switch ( V_5 -> V_12 ) {
case V_13 :
case V_14 :
if ( ( V_28 != V_31 ) && ( V_28 != V_32 ) )
return - V_17 ;
V_30 = V_33 ;
if ( V_28 == V_32 )
V_30 = V_34 ;
V_29 <<= F_13 ( V_30 ) - 1 ;
break;
case V_15 :
case V_16 :
if ( V_28 < V_35 || V_28 > V_36 )
return - V_17 ;
V_30 = F_14 ( V_28 - V_35 ) ;
V_29 <<= V_28 - V_35 ;
break;
default:
F_15 ( 1 ) ;
return - V_17 ;
}
return F_5 ( V_27 -> V_18 , V_37 , V_30 , V_29 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
const struct V_38 * V_23 ;
struct V_39 V_40 = {
. V_6 = V_2 -> V_6 . V_7 ,
. V_18 = V_5 -> V_18 ,
. V_41 = V_5 ,
} ;
int V_24 , V_42 , V_43 ;
T_1 V_29 ;
const char * V_44 = V_45 [ V_35 ] . V_46 ;
const char * V_47 = V_45 [ V_36 ] . V_46 ;
switch ( V_5 -> V_12 ) {
case V_13 :
case V_14 :
V_23 = V_48 ;
V_43 = V_49 ;
break;
case V_15 :
case V_16 :
V_23 = V_45 ;
V_43 = V_50 ;
break;
default:
F_3 ( & V_2 -> V_6 , L_8 ,
V_5 -> V_12 ) ;
return - V_17 ;
}
F_6 ( V_2 ) ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
const struct V_38 * V_51 = & V_23 [ V_42 ] ;
struct V_38 * V_52 ;
if ( V_23 == V_45 ) {
if ( V_42 == V_53 ) {
V_52 = F_17 ( & V_2 -> V_6 ,
sizeof( * V_51 ) ,
V_54 ) ;
* V_52 = V_23 [ V_42 ] ;
V_52 -> V_55 = V_44 ;
V_51 = V_52 ;
} else if ( V_42 == V_56 ) {
V_52 = F_17 ( & V_2 -> V_6 ,
sizeof( * V_51 ) ,
V_54 ) ;
* V_52 = V_23 [ V_42 ] ;
V_52 -> V_55 = V_47 ;
V_51 = V_52 ;
}
}
V_27 = F_18 ( & V_2 -> V_6 , V_51 , & V_40 ) ;
if ( F_19 ( V_27 ) ) {
F_3 ( & V_2 -> V_6 , L_9 ,
V_23 [ V_42 ] . V_46 ) ;
return F_20 ( V_27 ) ;
}
V_24 = F_9 ( V_27 -> V_6 . V_25 ,
L_10 ,
& V_29 ) ;
if ( ! V_24 ) {
if ( F_11 ( V_27 , V_42 , V_29 ) )
F_3 ( & V_2 -> V_6 , L_11 ,
V_27 -> V_51 -> V_46 ) ;
}
if ( V_23 == V_45 ) {
if ( V_42 == V_35 )
F_21 ( V_27 -> V_6 . V_25 ,
L_12 ,
& V_44 ) ;
else if ( V_42 == V_36 )
F_21 ( V_27 -> V_6 . V_25 ,
L_12 ,
& V_47 ) ;
}
}
return 0 ;
}
