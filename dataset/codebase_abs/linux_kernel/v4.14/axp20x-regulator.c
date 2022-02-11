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
if ( V_5 -> V_14 == V_19 )
V_8 = V_20 ;
case V_21 :
case V_22 :
case V_23 :
V_10 = 1800 ;
V_11 = 4050 ;
V_12 = 3000 ;
V_13 = 150 ;
break;
default:
F_3 ( & V_2 -> V_6 ,
L_1 ) ;
return - V_24 ;
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
return F_5 ( V_5 -> V_25 , V_8 ,
V_26 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_27 * V_28 , * V_29 ;
int V_30 ;
T_1 V_3 = 0 ;
V_28 = F_7 ( V_2 -> V_6 . V_7 -> V_31 ) ;
if ( ! V_28 )
return 0 ;
V_29 = F_8 ( V_28 , L_4 ) ;
if ( ! V_29 ) {
F_4 ( & V_2 -> V_6 , L_5 ) ;
} else {
F_9 ( V_29 , L_6 , & V_3 ) ;
V_30 = F_1 ( V_2 , V_3 ) ;
if ( V_30 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 , V_30 ) ;
return V_30 ;
}
F_10 ( V_29 ) ;
}
return 0 ;
}
static int F_11 ( struct V_32 * V_33 , int V_34 , T_1 V_35 )
{
struct V_4 * V_5 = F_12 ( V_33 ) ;
unsigned int V_8 = V_36 ;
unsigned int V_37 ;
switch ( V_5 -> V_14 ) {
case V_15 :
case V_16 :
if ( ( V_34 != V_38 ) && ( V_34 != V_39 ) )
return - V_24 ;
V_37 = V_40 ;
if ( V_34 == V_39 )
V_37 = V_41 ;
V_35 <<= F_13 ( V_37 ) - 1 ;
break;
case V_19 :
V_8 = V_42 ;
case V_21 :
case V_22 :
case V_23 :
if ( V_34 < V_43 || V_34 > V_44 )
return - V_24 ;
V_37 = F_14 ( V_34 - V_43 ) ;
V_35 <<= V_34 - V_43 ;
break;
case V_17 :
if ( V_34 < V_45 || V_34 > V_46 )
return - V_24 ;
V_37 = F_14 ( V_34 - V_45 ) ;
V_35 <<= V_34 - V_45 ;
break;
default:
F_15 ( 1 ) ;
return - V_24 ;
}
return F_5 ( V_33 -> V_25 , V_8 , V_37 , V_35 ) ;
}
static bool F_16 ( struct V_4 * V_5 , int V_34 )
{
T_1 V_8 = 0 ;
switch ( V_5 -> V_14 ) {
case V_17 :
F_17 ( V_5 -> V_25 , V_47 , & V_8 ) ;
switch ( V_34 ) {
case V_48 :
return ! ! ( V_8 & F_18 ( 6 ) ) ;
case V_46 :
return ! ! ( V_8 & F_18 ( 5 ) ) ;
}
break;
case V_19 :
F_17 ( V_5 -> V_25 , V_42 , & V_8 ) ;
switch ( V_34 ) {
case V_49 :
return ( ( ( V_8 & F_19 ( 7 , 6 ) ) == F_18 ( 6 ) ) ||
( ( V_8 & F_19 ( 7 , 6 ) ) == F_18 ( 7 ) ) ) ;
case V_50 :
return ( ( V_8 & F_19 ( 7 , 6 ) ) == F_18 ( 7 ) ) ;
case V_51 :
return ! ! ( V_8 & F_18 ( 5 ) ) ;
}
break;
default:
return false ;
}
return false ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
const struct V_52 * V_29 ;
struct V_53 V_54 = {
. V_6 = V_2 -> V_6 . V_7 ,
. V_25 = V_5 -> V_25 ,
. V_55 = V_5 ,
} ;
int V_30 , V_56 , V_57 ;
T_1 V_35 ;
const char * V_58 = V_59 [ V_43 ] . V_60 ;
const char * V_61 = V_59 [ V_44 ] . V_60 ;
bool V_62 = false ;
switch ( V_5 -> V_14 ) {
case V_15 :
case V_16 :
V_29 = V_63 ;
V_57 = V_64 ;
break;
case V_21 :
case V_22 :
V_29 = V_59 ;
V_57 = V_65 ;
V_62 = F_21 ( V_2 -> V_6 . V_7 -> V_31 ,
L_8 ) ;
break;
case V_17 :
V_29 = V_66 ;
V_57 = V_67 ;
break;
case V_19 :
V_29 = V_68 ;
V_57 = V_69 ;
break;
case V_23 :
V_29 = V_70 ;
V_57 = V_71 ;
break;
default:
F_3 ( & V_2 -> V_6 , L_9 ,
V_5 -> V_14 ) ;
return - V_24 ;
}
F_6 ( V_2 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
const struct V_52 * V_72 = & V_29 [ V_56 ] ;
struct V_52 * V_73 ;
if ( F_16 ( V_5 , V_56 ) )
continue;
if ( ( V_29 == V_59 && V_56 == V_74 ) ||
( V_29 == V_66 && V_56 == V_75 ) ||
( V_29 == V_70 && V_56 == V_76 ) ) {
V_73 = F_22 ( & V_2 -> V_6 , sizeof( * V_72 ) ,
V_77 ) ;
if ( ! V_73 )
return - V_78 ;
* V_73 = V_29 [ V_56 ] ;
V_73 -> V_79 = V_58 ;
V_72 = V_73 ;
}
if ( ( V_29 == V_59 && V_56 == V_80 ) ||
( V_29 == V_70 && V_56 == V_81 ) ) {
V_73 = F_22 ( & V_2 -> V_6 , sizeof( * V_72 ) ,
V_77 ) ;
if ( ! V_73 )
return - V_78 ;
* V_73 = V_29 [ V_56 ] ;
V_73 -> V_79 = V_61 ;
V_72 = V_73 ;
}
V_33 = F_23 ( & V_2 -> V_6 , V_72 , & V_54 ) ;
if ( F_24 ( V_33 ) ) {
F_3 ( & V_2 -> V_6 , L_10 ,
V_29 [ V_56 ] . V_60 ) ;
return F_25 ( V_33 ) ;
}
V_30 = F_9 ( V_33 -> V_6 . V_31 ,
L_11 ,
& V_35 ) ;
if ( ! V_30 ) {
if ( F_11 ( V_33 , V_56 , V_35 ) )
F_3 ( & V_2 -> V_6 , L_12 ,
V_33 -> V_72 -> V_60 ) ;
}
if ( ( V_29 == V_59 && V_56 == V_43 ) ||
( V_29 == V_70 && V_56 == V_82 ) )
F_26 ( V_33 -> V_6 . V_31 ,
L_13 ,
& V_58 ) ;
if ( ( V_29 == V_59 && V_56 == V_44 ) ||
( V_29 == V_70 && V_56 == V_83 ) )
F_26 ( V_33 -> V_6 . V_31 ,
L_13 ,
& V_61 ) ;
}
if ( V_62 ) {
F_5 ( V_5 -> V_25 , V_84 ,
V_85 , 0 ) ;
V_33 = F_23 ( & V_2 -> V_6 ,
& V_86 ,
& V_54 ) ;
if ( F_24 ( V_33 ) ) {
F_3 ( & V_2 -> V_6 , L_14 ) ;
return F_25 ( V_33 ) ;
}
}
return 0 ;
}
