static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
if ( V_2 == 0 && V_1 == 0 )
return 0 ;
if ( V_2 == 0 )
return V_3 ;
return F_2 ( V_1 , V_2 ) ;
}
static unsigned int F_3 ( struct V_4 * V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_9 = V_6 / 1000 ;
T_1 V_10 = V_8 -> V_11 / 1000 ;
T_1 V_12 , V_13 , V_14 ;
V_13 = V_8 -> V_15 ;
V_14 = V_8 -> V_16 ;
if ( V_9 == 0 ) {
if ( V_8 -> V_17 == V_18 )
return V_3 ;
return 0 ;
}
if ( V_9 >= V_10 )
return ( V_8 -> V_17 == V_18 ) ?
0 : V_3 ;
if ( V_8 -> V_17 == V_18 && V_13 == 0 )
V_12 = F_1 ( V_14 * ( V_10 - V_9 ) , V_9 ) ;
else if ( V_8 -> V_17 == V_19 && V_14 == 0 )
V_12 = F_1 ( V_13 * V_9 , V_10 - V_9 ) ;
else if ( V_8 -> V_17 == V_18 )
V_12 = F_1 ( V_14 * V_13 * ( V_10 - V_9 ) ,
V_13 * V_9 - V_14 * ( V_10 - V_9 ) ) ;
else
V_12 = F_1 ( V_14 * V_13 * V_9 , V_14 * ( V_10 - V_9 ) - V_13 * V_9 ) ;
return ( unsigned int ) V_12 ;
}
static int F_4 ( struct V_4 * V_5 ,
unsigned int V_20 , int * V_21 , int * V_22 )
{
int V_23 , V_24 , V_25 = - 1 ;
V_23 = 0 ;
V_24 = V_5 -> V_26 ;
while ( V_24 > V_23 ) {
V_25 = V_23 + ( V_24 - V_23 ) / 2 ;
if ( V_5 -> V_27 [ V_25 ] . V_20 < V_20 )
V_24 = V_25 ;
else if ( V_5 -> V_27 [ V_25 ] . V_20 > V_20 )
V_23 = V_25 + 1 ;
else
break;
}
if ( V_25 == 0 ) {
if ( V_5 -> V_27 [ V_25 ] . V_20 > V_20 ) {
* V_22 = V_25 ;
* V_21 = V_25 + 1 ;
return 0 ;
} else {
* V_21 = V_25 ;
* V_22 = - 1 ;
return - V_28 ;
}
}
if ( V_25 == ( V_5 -> V_26 - 1 ) ) {
if ( V_5 -> V_27 [ V_25 ] . V_20 <= V_20 ) {
* V_21 = V_25 ;
* V_22 = V_25 - 1 ;
return 0 ;
} else {
* V_21 = - 1 ;
* V_22 = V_25 ;
return - V_28 ;
}
}
if ( V_5 -> V_27 [ V_25 ] . V_20 <= V_20 ) {
* V_21 = V_25 ;
* V_22 = V_25 - 1 ;
} else {
* V_21 = V_25 + 1 ;
* V_22 = V_25 ;
}
return 0 ;
}
static int F_5 ( struct V_4 * V_5 , unsigned int V_20 , int * V_29 )
{
int V_30 , V_31 ;
int V_32 ;
V_32 = F_4 ( V_5 , V_20 , & V_30 , & V_31 ) ;
if ( V_32 ) {
if ( V_30 != - 1 )
* V_29 = V_5 -> V_27 [ V_30 ] . V_33 * 1000 ;
else if ( V_31 != - 1 )
* V_29 = V_5 -> V_27 [ V_31 ] . V_33 * 1000 ;
else
return V_32 ;
} else {
* V_29 = V_5 -> V_27 [ V_30 ] . V_33 * 1000 +
( ( V_5 -> V_27 [ V_31 ] . V_33 - V_5 -> V_27 [ V_30 ] . V_33 ) *
1000 * ( ( int ) V_20 - ( int ) V_5 -> V_27 [ V_30 ] . V_20 ) ) /
( ( int ) V_5 -> V_27 [ V_31 ] . V_20 - ( int ) V_5 -> V_27 [ V_30 ] . V_20 ) ;
}
return 0 ;
}
static int F_6 ( struct V_4 * V_5 , int * V_29 )
{
int V_32 ;
int V_34 , V_35 ;
unsigned int V_20 = 0 ;
if ( V_5 -> V_8 -> V_34 ) {
V_34 = V_5 -> V_8 -> V_34 () ;
if ( V_34 < 0 )
return V_34 ;
V_20 = ( unsigned int ) V_34 ;
}
if ( V_5 -> V_8 -> V_35 ) {
V_35 = V_5 -> V_8 -> V_35 () ;
if ( V_35 < 0 )
return V_35 ;
V_20 = F_3 ( V_5 , ( unsigned int ) V_35 ) ;
}
V_32 = F_5 ( V_5 , V_20 , V_29 ) ;
if ( V_32 ) {
F_7 ( V_5 -> V_36 , L_1 ) ;
return V_32 ;
}
return 0 ;
}
static T_2 F_8 ( struct V_37 * V_36 ,
struct V_38 * V_39 , char * V_40 )
{
struct V_4 * V_5 = F_9 ( V_36 ) ;
return sprintf ( V_40 , L_2 , V_5 -> V_41 ) ;
}
static T_2 F_10 ( struct V_37 * V_36 ,
struct V_38 * V_39 , char * V_40 )
{
return sprintf ( V_40 , L_3 ) ;
}
static T_2 F_11 ( struct V_37 * V_36 ,
struct V_38 * V_39 , char * V_40 )
{
struct V_4 * V_5 = F_9 ( V_36 ) ;
int V_29 , V_32 ;
V_32 = F_6 ( V_5 , & V_29 ) ;
if ( V_32 )
return V_32 ;
return sprintf ( V_40 , L_4 , V_29 ) ;
}
static int T_3 F_12 ( struct V_42 * V_43 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 = V_43 -> V_36 . V_44 ;
int V_32 = 0 ;
if ( ! V_8 ) {
F_13 ( & V_43 -> V_36 , L_5 ) ;
return - V_45 ;
}
if ( ! V_8 -> V_35 && ! V_8 -> V_34 ) {
F_13 ( & V_43 -> V_36 , L_6
L_7 ) ;
return - V_28 ;
}
if ( V_8 -> V_35 && V_8 -> V_34 ) {
F_14 ( & V_43 -> V_36 , L_8
L_9 ) ;
V_8 -> V_35 = NULL ;
}
if ( V_8 -> V_35 && ( V_8 -> V_11 == 0 ||
( V_8 -> V_15 == 0 && V_8 -> V_17 ==
V_19 ) ||
( V_8 -> V_16 == 0 && V_8 -> V_17 ==
V_18 ) ||
( V_8 -> V_17 != V_18 &&
V_8 -> V_17 != V_19 ) ) ) {
F_13 ( & V_43 -> V_36 , L_10
L_11 ) ;
return - V_28 ;
}
V_5 = F_15 ( sizeof( struct V_4 ) , V_46 ) ;
if ( ! V_5 )
return - V_47 ;
V_5 -> V_36 = & V_43 -> V_36 ;
V_5 -> V_8 = V_8 ;
strncpy ( V_5 -> V_41 , V_43 -> V_48 -> V_41 , V_49 ) ;
switch ( V_43 -> V_48 -> V_50 ) {
case V_51 :
V_5 -> V_27 = V_52 ;
V_5 -> V_26 = F_16 ( V_52 ) ;
break;
case V_53 :
V_5 -> V_27 = V_54 ;
V_5 -> V_26 = F_16 ( V_54 ) ;
break;
default:
F_13 ( & V_43 -> V_36 , L_12 ,
V_43 -> V_48 -> V_50 ,
V_43 -> V_48 -> V_41 ) ;
V_32 = - V_28 ;
goto V_55;
}
F_17 ( V_43 , V_5 ) ;
V_32 = F_18 ( & V_5 -> V_36 -> V_56 , & V_57 ) ;
if ( V_32 ) {
F_13 ( V_5 -> V_36 , L_13 ) ;
goto V_55;
}
V_5 -> V_58 = F_19 ( V_5 -> V_36 ) ;
if ( F_20 ( V_5 -> V_58 ) ) {
F_13 ( V_5 -> V_36 , L_14 ) ;
V_32 = - V_28 ;
goto V_59;
}
F_21 ( & V_43 -> V_36 , L_15 ,
V_43 -> V_41 , V_43 -> V_60 , V_43 -> V_48 -> V_41 ,
V_43 -> V_48 -> V_50 ) ;
return 0 ;
V_59:
F_22 ( & V_5 -> V_36 -> V_56 , & V_57 ) ;
V_55:
F_23 ( V_5 ) ;
return V_32 ;
}
static int T_4 F_24 ( struct V_42 * V_43 )
{
struct V_4 * V_5 = F_25 ( V_43 ) ;
F_26 ( V_5 -> V_58 ) ;
F_22 ( & V_5 -> V_36 -> V_56 , & V_57 ) ;
F_17 ( V_43 , NULL ) ;
F_23 ( V_5 ) ;
return 0 ;
}
static int T_5 F_27 ( void )
{
return F_28 ( & V_61 ) ;
}
static void T_6 F_29 ( void )
{
F_30 ( & V_61 ) ;
}
