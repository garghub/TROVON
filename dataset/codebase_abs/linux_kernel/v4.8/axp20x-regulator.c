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
case V_17 :
V_8 = 1800 ;
V_9 = 4050 ;
V_10 = 3000 ;
V_11 = 150 ;
break;
default:
F_3 ( & V_2 -> V_6 ,
L_1 ) ;
return - V_18 ;
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
return F_5 ( V_5 -> V_19 , V_20 ,
V_21 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_24 ;
int V_25 ;
T_1 V_3 = 0 ;
V_23 = F_7 ( V_2 -> V_6 . V_7 -> V_26 ) ;
if ( ! V_23 )
return 0 ;
V_24 = F_8 ( V_23 , L_4 ) ;
if ( ! V_24 ) {
F_4 ( & V_2 -> V_6 , L_5 ) ;
} else {
F_9 ( V_24 , L_6 , & V_3 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 , V_25 ) ;
return V_25 ;
}
F_10 ( V_24 ) ;
}
return 0 ;
}
static int F_11 ( struct V_27 * V_28 , int V_29 , T_1 V_30 )
{
struct V_4 * V_5 = F_12 ( V_28 ) ;
unsigned int V_31 ;
switch ( V_5 -> V_12 ) {
case V_13 :
case V_14 :
if ( ( V_29 != V_32 ) && ( V_29 != V_33 ) )
return - V_18 ;
V_31 = V_34 ;
if ( V_29 == V_33 )
V_31 = V_35 ;
V_30 <<= F_13 ( V_31 ) - 1 ;
break;
case V_15 :
case V_16 :
case V_17 :
if ( V_29 < V_36 || V_29 > V_37 )
return - V_18 ;
V_31 = F_14 ( V_29 - V_36 ) ;
V_30 <<= V_29 - V_36 ;
break;
default:
F_15 ( 1 ) ;
return - V_18 ;
}
return F_5 ( V_28 -> V_19 , V_38 , V_31 , V_30 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
const struct V_39 * V_24 ;
struct V_40 V_41 = {
. V_6 = V_2 -> V_6 . V_7 ,
. V_19 = V_5 -> V_19 ,
. V_42 = V_5 ,
} ;
int V_25 , V_43 , V_44 ;
T_1 V_30 ;
const char * V_45 = V_46 [ V_36 ] . V_47 ;
const char * V_48 = V_46 [ V_37 ] . V_47 ;
bool V_49 = false ;
switch ( V_5 -> V_12 ) {
case V_13 :
case V_14 :
V_24 = V_50 ;
V_44 = V_51 ;
break;
case V_15 :
case V_16 :
V_24 = V_46 ;
V_44 = V_52 ;
V_49 = F_17 ( V_2 -> V_6 . V_7 -> V_26 ,
L_8 ) ;
break;
case V_17 :
V_24 = V_53 ;
V_44 = V_54 ;
break;
default:
F_3 ( & V_2 -> V_6 , L_9 ,
V_5 -> V_12 ) ;
return - V_18 ;
}
F_6 ( V_2 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
const struct V_39 * V_55 = & V_24 [ V_43 ] ;
struct V_39 * V_56 ;
if ( ( V_24 == V_46 && V_43 == V_57 ) ||
( V_24 == V_53 && V_43 == V_58 ) ) {
V_56 = F_18 ( & V_2 -> V_6 , sizeof( * V_55 ) ,
V_59 ) ;
* V_56 = V_24 [ V_43 ] ;
V_56 -> V_60 = V_45 ;
V_55 = V_56 ;
}
if ( ( V_24 == V_46 && V_43 == V_61 ) ||
( V_24 == V_53 && V_43 == V_62 ) ) {
V_56 = F_18 ( & V_2 -> V_6 , sizeof( * V_55 ) ,
V_59 ) ;
* V_56 = V_24 [ V_43 ] ;
V_56 -> V_60 = V_48 ;
V_55 = V_56 ;
}
V_28 = F_19 ( & V_2 -> V_6 , V_55 , & V_41 ) ;
if ( F_20 ( V_28 ) ) {
F_3 ( & V_2 -> V_6 , L_10 ,
V_24 [ V_43 ] . V_47 ) ;
return F_21 ( V_28 ) ;
}
V_25 = F_9 ( V_28 -> V_6 . V_26 ,
L_11 ,
& V_30 ) ;
if ( ! V_25 ) {
if ( F_11 ( V_28 , V_43 , V_30 ) )
F_3 ( & V_2 -> V_6 , L_12 ,
V_28 -> V_55 -> V_47 ) ;
}
if ( ( V_24 == V_46 && V_43 == V_36 ) ||
( V_24 == V_53 && V_43 == V_63 ) )
F_22 ( V_28 -> V_6 . V_26 ,
L_13 ,
& V_45 ) ;
if ( ( V_24 == V_46 && V_43 == V_37 ) ||
( V_24 == V_53 && V_43 == V_64 ) )
F_22 ( V_28 -> V_6 . V_26 ,
L_13 ,
& V_48 ) ;
}
if ( V_49 ) {
F_5 ( V_5 -> V_19 , V_65 ,
V_66 , 0 ) ;
V_28 = F_19 ( & V_2 -> V_6 ,
& V_67 ,
& V_41 ) ;
if ( F_20 ( V_28 ) ) {
F_3 ( & V_2 -> V_6 , L_14 ) ;
return F_21 ( V_28 ) ;
}
}
return 0 ;
}
