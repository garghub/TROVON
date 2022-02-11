static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
unsigned int V_8 = V_9 ;
T_1 V_10 , V_11 , V_12 , V_13 ;
switch ( V_5 -> V_14 ) {
case V_15 :
case V_16 :
V_10 = 750 ;
V_11 = 1875 ;
V_12 = 1500 ;
V_13 = 75 ;
break;
case V_17 :
V_8 = V_18 ;
case V_19 :
case V_20 :
case V_21 :
V_10 = 1800 ;
V_11 = 4050 ;
V_12 = 3000 ;
V_13 = 150 ;
break;
default:
F_3 ( & V_2 -> V_6 ,
L_1 ) ;
return - V_22 ;
}
if ( V_3 == 0 )
V_3 = V_12 ;
if ( V_3 < V_10 ) {
V_3 = V_10 ;
F_4 ( & V_2 -> V_6 , L_2 ,
V_10 ) ;
}
if ( V_3 > V_11 ) {
V_3 = V_11 ;
F_4 ( & V_2 -> V_6 , L_3 ,
V_11 ) ;
}
V_3 = ( V_3 - V_10 ) / V_13 ;
return F_5 ( V_5 -> V_23 , V_8 ,
V_24 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_25 * V_26 , * V_27 ;
int V_28 ;
T_1 V_3 = 0 ;
V_26 = F_7 ( V_2 -> V_6 . V_7 -> V_29 ) ;
if ( ! V_26 )
return 0 ;
V_27 = F_8 ( V_26 , L_4 ) ;
if ( ! V_27 ) {
F_4 ( & V_2 -> V_6 , L_5 ) ;
} else {
F_9 ( V_27 , L_6 , & V_3 ) ;
V_28 = F_1 ( V_2 , V_3 ) ;
if ( V_28 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 , V_28 ) ;
return V_28 ;
}
F_10 ( V_27 ) ;
}
return 0 ;
}
static int F_11 ( struct V_30 * V_31 , int V_32 , T_1 V_33 )
{
struct V_4 * V_5 = F_12 ( V_31 ) ;
unsigned int V_8 = V_34 ;
unsigned int V_35 ;
switch ( V_5 -> V_14 ) {
case V_15 :
case V_16 :
if ( ( V_32 != V_36 ) && ( V_32 != V_37 ) )
return - V_22 ;
V_35 = V_38 ;
if ( V_32 == V_37 )
V_35 = V_39 ;
V_33 <<= F_13 ( V_35 ) - 1 ;
break;
case V_17 :
V_8 = V_40 ;
case V_19 :
case V_20 :
case V_21 :
if ( V_32 < V_41 || V_32 > V_42 )
return - V_22 ;
V_35 = F_14 ( V_32 - V_41 ) ;
V_33 <<= V_32 - V_41 ;
break;
default:
F_15 ( 1 ) ;
return - V_22 ;
}
return F_5 ( V_31 -> V_23 , V_8 , V_35 , V_33 ) ;
}
static bool F_16 ( struct V_4 * V_5 , int V_32 )
{
T_1 V_8 = 0 ;
if ( V_5 -> V_14 != V_17 )
return false ;
F_17 ( V_5 -> V_23 , V_40 , & V_8 ) ;
switch ( V_32 ) {
case V_43 :
return ( ( ( V_8 & F_18 ( 7 , 6 ) ) == F_19 ( 6 ) ) ||
( ( V_8 & F_18 ( 7 , 6 ) ) == F_19 ( 7 ) ) ) ;
case V_44 :
return ( ( V_8 & F_18 ( 7 , 6 ) ) == F_19 ( 7 ) ) ;
case V_45 :
return ! ! ( V_8 & F_19 ( 5 ) ) ;
}
return false ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
const struct V_46 * V_27 ;
struct V_47 V_48 = {
. V_6 = V_2 -> V_6 . V_7 ,
. V_23 = V_5 -> V_23 ,
. V_49 = V_5 ,
} ;
int V_28 , V_50 , V_51 ;
T_1 V_33 ;
const char * V_52 = V_53 [ V_41 ] . V_54 ;
const char * V_55 = V_53 [ V_42 ] . V_54 ;
bool V_56 = false ;
switch ( V_5 -> V_14 ) {
case V_15 :
case V_16 :
V_27 = V_57 ;
V_51 = V_58 ;
break;
case V_19 :
case V_20 :
V_27 = V_53 ;
V_51 = V_59 ;
V_56 = F_21 ( V_2 -> V_6 . V_7 -> V_29 ,
L_8 ) ;
break;
case V_17 :
V_27 = V_60 ;
V_51 = V_61 ;
break;
case V_21 :
V_27 = V_62 ;
V_51 = V_63 ;
break;
default:
F_3 ( & V_2 -> V_6 , L_9 ,
V_5 -> V_14 ) ;
return - V_22 ;
}
F_6 ( V_2 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
const struct V_46 * V_64 = & V_27 [ V_50 ] ;
struct V_46 * V_65 ;
if ( F_16 ( V_5 , V_50 ) )
continue;
if ( ( V_27 == V_53 && V_50 == V_66 ) ||
( V_27 == V_62 && V_50 == V_67 ) ) {
V_65 = F_22 ( & V_2 -> V_6 , sizeof( * V_64 ) ,
V_68 ) ;
* V_65 = V_27 [ V_50 ] ;
V_65 -> V_69 = V_52 ;
V_64 = V_65 ;
}
if ( ( V_27 == V_53 && V_50 == V_70 ) ||
( V_27 == V_62 && V_50 == V_71 ) ) {
V_65 = F_22 ( & V_2 -> V_6 , sizeof( * V_64 ) ,
V_68 ) ;
* V_65 = V_27 [ V_50 ] ;
V_65 -> V_69 = V_55 ;
V_64 = V_65 ;
}
V_31 = F_23 ( & V_2 -> V_6 , V_64 , & V_48 ) ;
if ( F_24 ( V_31 ) ) {
F_3 ( & V_2 -> V_6 , L_10 ,
V_27 [ V_50 ] . V_54 ) ;
return F_25 ( V_31 ) ;
}
V_28 = F_9 ( V_31 -> V_6 . V_29 ,
L_11 ,
& V_33 ) ;
if ( ! V_28 ) {
if ( F_11 ( V_31 , V_50 , V_33 ) )
F_3 ( & V_2 -> V_6 , L_12 ,
V_31 -> V_64 -> V_54 ) ;
}
if ( ( V_27 == V_53 && V_50 == V_41 ) ||
( V_27 == V_62 && V_50 == V_72 ) )
F_26 ( V_31 -> V_6 . V_29 ,
L_13 ,
& V_52 ) ;
if ( ( V_27 == V_53 && V_50 == V_42 ) ||
( V_27 == V_62 && V_50 == V_73 ) )
F_26 ( V_31 -> V_6 . V_29 ,
L_13 ,
& V_55 ) ;
}
if ( V_56 ) {
F_5 ( V_5 -> V_23 , V_74 ,
V_75 , 0 ) ;
V_31 = F_23 ( & V_2 -> V_6 ,
& V_76 ,
& V_48 ) ;
if ( F_24 ( V_31 ) ) {
F_3 ( & V_2 -> V_6 , L_14 ) ;
return F_25 ( V_31 ) ;
}
}
return 0 ;
}
