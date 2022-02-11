static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
int V_8 ;
F_3 ( & V_4 -> V_9 ) ;
if ( F_4 ( V_10 , V_4 -> V_11 + V_12 / 10 ) || ! V_4 -> V_13 ) {
F_5 ( & V_6 -> V_3 , L_1 ) ;
for ( V_8 = 0 ; V_8 < F_6 ( V_4 -> V_14 ) ; V_8 ++ ) {
V_7 = F_7 ( V_6 , V_8 ) ;
if ( F_8 ( V_7 < 0 ) )
V_4 -> V_14 [ V_8 ] = 0 ;
else
V_4 -> V_14 [ V_8 ] = V_7 ;
}
V_4 -> V_11 = V_10 ;
V_4 -> V_13 = 1 ;
}
F_9 ( & V_4 -> V_9 ) ;
return V_4 ;
}
static int F_10 ( struct V_2 * V_3 , T_2 V_15 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const T_2 V_16 = V_4 -> V_14 [ V_15 ] ;
T_3 V_17 = 0 ;
switch ( V_15 ) {
case V_18 :
V_17 = V_16 * 151 / 1000 ;
break;
case V_19 :
V_17 = V_16 * 605 / 10 ;
break;
case V_20 :
V_17 = V_16 * 482 * 125 / 1000 ;
break;
default:
F_11 ( 1 ) ;
break;
}
return V_17 ;
}
static unsigned int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const unsigned int V_17 = V_4 -> V_14 [ V_18 ] * 151 ;
const unsigned int V_21 = V_17 / 4 ;
return V_21 ;
}
static T_4 F_13 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_14 ( V_23 ) ;
const int V_17 = F_10 ( V_3 , V_26 -> V_27 ) ;
return snprintf ( V_24 , V_28 , L_2 , V_17 ) ;
}
static T_4 F_15 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
const unsigned int V_21 = F_12 ( V_3 ) ;
return snprintf ( V_24 , V_28 , L_3 , V_21 ) ;
}
static T_4 F_16 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
const unsigned int V_21 = F_12 ( V_3 ) ;
const int V_29 = F_10 ( V_3 , V_20 ) ;
const unsigned int V_30 = abs ( V_29 * V_21 ) ;
return snprintf ( V_24 , V_28 , L_3 , V_30 ) ;
}
static T_4 F_17 ( struct V_2 * V_3 ,
struct V_22 * V_23 ,
char * V_24 )
{
struct V_25 * V_26 = F_14 ( V_23 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
const T_2 V_15 = V_4 -> V_14 [ V_31 ] ;
const T_3 V_32 = V_26 -> V_27 ;
return snprintf ( V_24 , V_28 , L_3 , ! ! ( V_15 & V_32 ) ) ;
}
static int F_18 ( struct V_5 * V_6 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 = V_6 -> V_36 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_37 ;
if ( ! F_19 ( V_36 , V_38 ) )
return - V_39 ;
V_4 = F_20 ( V_3 , sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return - V_41 ;
V_4 -> V_6 = V_6 ;
F_21 ( & V_4 -> V_9 ) ;
F_22 ( V_6 , V_42 , 0x00 ) ;
V_37 = F_23 ( V_3 , V_6 -> V_43 ,
V_4 ,
V_44 ) ;
return F_24 ( V_37 ) ;
}
