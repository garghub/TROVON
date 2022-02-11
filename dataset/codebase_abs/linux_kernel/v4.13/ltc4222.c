static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 ;
T_1 V_6 [ 2 ] ;
int V_7 ;
V_7 = F_3 ( V_4 , V_3 , V_6 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 = ( ( V_6 [ 0 ] << 8 ) + V_6 [ 1 ] ) >> 6 ;
switch ( V_3 ) {
case V_8 :
case V_9 :
V_5 = F_4 ( V_5 * 5 , 4 ) ;
break;
case V_10 :
case V_11 :
V_5 = F_4 ( V_5 * 125 , 4 ) ;
break;
case V_12 :
case V_13 :
V_5 = F_4 ( V_5 * 125 , 2 ) ;
break;
default:
return - V_14 ;
}
return V_5 ;
}
static T_2 F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_6 )
{
struct V_17 * V_18 = F_6 ( V_16 ) ;
int V_19 ;
V_19 = F_1 ( V_2 , V_18 -> V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
return snprintf ( V_6 , V_21 , L_1 , V_19 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 , char * V_6 )
{
struct V_22 * V_18 = F_8 ( V_16 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned int V_23 ;
int V_7 ;
V_7 = F_9 ( V_4 , V_18 -> V_24 , & V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 &= V_18 -> V_20 ;
if ( V_23 )
F_10 ( V_4 , V_18 -> V_24 , V_18 -> V_20 , 0 ) ;
return snprintf ( V_6 , V_21 , L_1 , ! ! V_23 ) ;
}
static int F_11 ( struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_2 = & V_26 -> V_2 ;
struct V_1 * V_29 ;
struct V_4 * V_4 ;
V_4 = F_12 ( V_26 , & V_30 ) ;
if ( F_13 ( V_4 ) ) {
F_14 ( V_2 , L_2 ) ;
return F_15 ( V_4 ) ;
}
F_16 ( V_4 , V_31 , 0x00 ) ;
F_16 ( V_4 , V_32 , 0x00 ) ;
V_29 = F_17 ( V_2 , V_26 -> V_33 ,
V_4 ,
V_34 ) ;
return F_18 ( V_29 ) ;
}
