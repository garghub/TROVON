static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
int V_6 ;
V_6 = F_3 ( V_4 , V_3 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_3 ) {
case V_7 :
V_5 = V_5 * 10 ;
break;
case V_8 :
V_5 = V_5 * 400 ;
break;
case V_9 :
V_5 = V_5 * 300 ;
break;
default:
return - V_10 ;
}
return V_5 ;
}
static T_2 F_4 ( struct V_1 * V_2 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_5 ( V_12 ) ;
int V_16 ;
V_16 = F_1 ( V_2 , V_15 -> V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
return snprintf ( V_13 , V_18 , L_1 , V_16 ) ;
}
static T_2 F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_5 ( V_12 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned int V_19 ;
int V_6 ;
V_6 = F_3 ( V_4 , V_20 , & V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
V_19 &= V_15 -> V_17 ;
if ( V_19 )
F_7 ( V_4 , V_20 , V_15 -> V_17 , 0 ) ;
return snprintf ( V_13 , V_18 , L_1 , ! ! V_19 ) ;
}
static int F_8 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_1 * V_2 = & V_22 -> V_2 ;
struct V_1 * V_25 ;
struct V_4 * V_4 ;
V_4 = F_9 ( V_22 , & V_26 ) ;
if ( F_10 ( V_4 ) ) {
F_11 ( V_2 , L_2 ) ;
return F_12 ( V_4 ) ;
}
F_13 ( V_4 , V_20 , 0x00 ) ;
V_25 = F_14 ( V_2 , V_22 -> V_27 ,
V_4 ,
V_28 ) ;
return F_15 ( V_25 ) ;
}
