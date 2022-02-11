static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
if ( V_2 == 0 && V_1 == 0 )
return 0 ;
if ( V_2 == 0 )
return V_3 ;
return F_2 ( V_1 , V_2 ) ;
}
static int F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 = V_6 / 1000 ;
T_1 V_10 = V_8 -> V_11 / 1000 ;
T_1 V_12 , V_13 , V_14 ;
V_13 = V_8 -> V_15 ;
V_14 = V_8 -> V_16 ;
if ( V_9 == 0 ) {
if ( V_8 -> V_17 == V_18 )
return V_19 ;
return 0 ;
}
if ( V_9 >= V_10 )
return ( V_8 -> V_17 == V_18 ) ?
0 : V_19 ;
if ( V_8 -> V_17 == V_18 && V_13 == 0 )
V_12 = F_1 ( V_14 * ( V_10 - V_9 ) , V_9 ) ;
else if ( V_8 -> V_17 == V_20 && V_14 == 0 )
V_12 = F_1 ( V_13 * V_9 , V_10 - V_9 ) ;
else if ( V_8 -> V_17 == V_18 )
V_12 = F_1 ( V_14 * V_13 * ( V_10 - V_9 ) ,
V_13 * V_9 - V_14 * ( V_10 - V_9 ) ) ;
else
V_12 = F_1 ( V_14 * V_13 * V_9 , V_14 * ( V_10 - V_9 ) - V_13 * V_9 ) ;
if ( V_12 > V_19 )
V_12 = V_19 ;
return V_12 ;
}
static void F_4 ( struct V_4 * V_5 , unsigned int V_21 ,
int * V_22 , int * V_23 )
{
int V_24 , V_25 , V_26 ;
if ( V_21 >= V_5 -> V_27 [ 0 ] . V_21 ) {
* V_22 = 0 ;
* V_23 = 0 ;
return;
}
if ( V_21 <= V_5 -> V_27 [ V_5 -> V_28 - 1 ] . V_21 ) {
* V_22 = V_5 -> V_28 - 1 ;
* V_23 = V_5 -> V_28 - 1 ;
return;
}
V_24 = 0 ;
V_25 = V_5 -> V_28 ;
while ( V_24 < V_25 ) {
V_26 = V_24 + ( V_25 - V_24 ) / 2 ;
if ( V_21 >= V_5 -> V_27 [ V_26 ] . V_21 ) {
V_25 = V_26 ;
} else {
V_24 = V_26 + 1 ;
if ( V_21 >= V_5 -> V_27 [ V_24 ] . V_21 )
V_25 = V_24 ;
}
}
* V_22 = V_25 ;
if ( V_21 == V_5 -> V_27 [ V_25 ] . V_21 )
* V_23 = V_25 ;
else
* V_23 = V_25 - 1 ;
}
static int F_5 ( struct V_4 * V_5 , unsigned int V_21 )
{
int V_29 , V_30 ;
int V_31 ;
F_4 ( V_5 , V_21 , & V_29 , & V_30 ) ;
if ( V_29 == V_30 ) {
V_31 = V_5 -> V_27 [ V_29 ] . V_32 * 1000 ;
} else {
V_31 = V_5 -> V_27 [ V_29 ] . V_32 * 1000 +
( ( V_5 -> V_27 [ V_30 ] . V_32 - V_5 -> V_27 [ V_29 ] . V_32 ) *
1000 * ( ( int ) V_21 - ( int ) V_5 -> V_27 [ V_29 ] . V_21 ) ) /
( ( int ) V_5 -> V_27 [ V_30 ] . V_21 - ( int ) V_5 -> V_27 [ V_29 ] . V_21 ) ;
}
return V_31 ;
}
static int F_6 ( struct V_4 * V_5 )
{
int V_33 ;
if ( V_5 -> V_8 -> V_34 )
return V_5 -> V_8 -> V_34 () ;
if ( V_5 -> V_8 -> V_33 ) {
V_33 = V_5 -> V_8 -> V_33 () ;
if ( V_33 < 0 )
return V_33 ;
return F_3 ( V_5 , V_33 ) ;
}
return - V_35 ;
}
static T_2 F_7 ( struct V_36 * V_37 ,
struct V_38 * V_39 , char * V_40 )
{
struct V_4 * V_5 = F_8 ( V_37 ) ;
return sprintf ( V_40 , L_1 , V_5 -> V_41 ) ;
}
static T_2 F_9 ( struct V_36 * V_37 ,
struct V_38 * V_39 , char * V_40 )
{
return sprintf ( V_40 , L_2 ) ;
}
static T_2 F_10 ( struct V_36 * V_37 ,
struct V_38 * V_39 , char * V_40 )
{
struct V_4 * V_5 = F_8 ( V_37 ) ;
int V_21 ;
V_21 = F_6 ( V_5 ) ;
if ( V_21 < 0 )
return V_21 ;
return sprintf ( V_40 , L_3 , F_5 ( V_5 , V_21 ) ) ;
}
static int T_3 F_11 ( struct V_42 * V_43 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 = V_43 -> V_37 . V_44 ;
int V_45 = 0 ;
if ( ! V_8 ) {
F_12 ( & V_43 -> V_37 , L_4 ) ;
return - V_46 ;
}
if ( ! V_8 -> V_33 && ! V_8 -> V_34 ) {
F_12 ( & V_43 -> V_37 ,
L_5 ) ;
return - V_35 ;
}
if ( V_8 -> V_33 && V_8 -> V_34 ) {
F_13 ( & V_43 -> V_37 ,
L_6 ) ;
V_8 -> V_33 = NULL ;
}
if ( V_8 -> V_33 && ( V_8 -> V_11 == 0 ||
( V_8 -> V_15 == 0 && V_8 -> V_17 ==
V_20 ) ||
( V_8 -> V_16 == 0 && V_8 -> V_17 ==
V_18 ) ||
( V_8 -> V_17 != V_18 &&
V_8 -> V_17 != V_20 ) ) ) {
F_12 ( & V_43 -> V_37 ,
L_7 ) ;
return - V_35 ;
}
V_5 = F_14 ( & V_43 -> V_37 , sizeof( struct V_4 ) , V_47 ) ;
if ( ! V_5 )
return - V_48 ;
V_5 -> V_37 = & V_43 -> V_37 ;
V_5 -> V_8 = V_8 ;
F_15 ( V_5 -> V_41 , V_43 -> V_49 -> V_41 , sizeof( V_5 -> V_41 ) ) ;
switch ( V_43 -> V_49 -> V_50 ) {
case V_51 :
V_5 -> V_27 = V_52 ;
V_5 -> V_28 = F_16 ( V_52 ) ;
break;
case V_53 :
V_5 -> V_27 = V_54 ;
V_5 -> V_28 = F_16 ( V_54 ) ;
break;
default:
F_12 ( & V_43 -> V_37 , L_8 ,
V_43 -> V_49 -> V_50 ,
V_43 -> V_49 -> V_41 ) ;
return - V_35 ;
}
F_17 ( V_43 , V_5 ) ;
V_45 = F_18 ( & V_5 -> V_37 -> V_55 , & V_56 ) ;
if ( V_45 ) {
F_12 ( V_5 -> V_37 , L_9 ) ;
return V_45 ;
}
V_5 -> V_57 = F_19 ( V_5 -> V_37 ) ;
if ( F_20 ( V_5 -> V_57 ) ) {
F_12 ( V_5 -> V_37 , L_10 ) ;
V_45 = F_21 ( V_5 -> V_57 ) ;
goto V_58;
}
F_22 ( & V_43 -> V_37 , L_11 ,
V_43 -> V_41 , V_43 -> V_59 , V_43 -> V_49 -> V_41 ,
V_43 -> V_49 -> V_50 ) ;
return 0 ;
V_58:
F_23 ( & V_5 -> V_37 -> V_55 , & V_56 ) ;
return V_45 ;
}
static int T_4 F_24 ( struct V_42 * V_43 )
{
struct V_4 * V_5 = F_25 ( V_43 ) ;
F_26 ( V_5 -> V_57 ) ;
F_23 ( & V_5 -> V_37 -> V_55 , & V_56 ) ;
F_17 ( V_43 , NULL ) ;
return 0 ;
}
