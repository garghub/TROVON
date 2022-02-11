static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 = F_3 ( V_7 ) ;
switch ( V_4 ) {
case V_10 :
V_5 = F_4 ( V_2 , V_3 ,
V_11 ) ;
break;
case V_12 :
V_5 = F_4 ( V_2 , V_3 ,
V_13 ) ;
break;
case V_14 :
if ( V_9 -> V_15 != V_16 )
return - V_17 ;
V_5 = F_4 ( V_2 , V_3 ,
V_18 ) ;
break;
case V_19 :
V_5 = F_4 ( V_2 , V_3 ,
V_20 ) ;
break;
case V_21 :
if ( V_9 -> V_15 != V_16 )
return - V_17 ;
V_5 = F_4 ( V_2 , V_3 ,
V_22 ) ;
break;
case V_23 :
if ( V_9 -> V_15 != V_16 )
return - V_17 ;
V_5 = F_4 ( V_2 , V_3 ,
V_24 ) ;
break;
case V_25 :
if ( V_9 -> V_15 != V_16 && V_9 -> V_15 != V_26 &&
V_9 -> V_15 != V_27 )
return - V_17 ;
V_5 = F_4 ( V_2 , V_3 ,
V_28 ) ;
break;
case V_29 :
V_5 = F_4 ( V_2 , V_3 ,
V_30 ) ;
break;
case V_31 :
if ( V_9 -> V_15 != V_16 )
return - V_17 ;
V_5 = 0 ;
break;
case V_32 :
case V_33 :
case V_34 :
V_5 = 0 ;
break;
default:
V_5 = - V_35 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_36 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
switch ( V_4 ) {
case V_31 :
V_5 = F_6 ( V_2 , V_3 ,
V_24 , 0 ) ;
if ( V_5 )
break;
V_5 = F_6 ( V_2 , V_3 ,
V_22 , 0 ) ;
break;
case V_32 :
V_5 = F_6 ( V_2 , V_3 ,
V_11 , 0x7fff ) ;
if ( V_5 )
break;
V_5 = F_6 ( V_2 , V_3 ,
V_13 , 0 ) ;
break;
case V_33 :
V_5 = F_6 ( V_2 , V_3 ,
V_20 , 0 ) ;
if ( ! V_5 && V_9 -> V_15 == V_16 )
V_5 = F_6 ( V_2 , V_3 ,
V_18 , 0 ) ;
break;
case V_34 :
V_5 = F_6 ( V_2 , V_3 ,
V_30 ,
0x8000 ) ;
if ( ! V_5 && V_9 -> V_15 == V_16 )
V_5 = F_6 ( V_2 , V_3 ,
V_28 , 0 ) ;
break;
default:
V_5 = - V_35 ;
break;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
int V_37 ;
if ( V_3 >= 0 ) {
V_5 = F_8 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
}
switch ( V_4 ) {
case V_38 :
V_37 = F_4 ( V_2 , 0 ,
V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_37 & V_40 )
V_5 |= V_41 ;
if ( V_37 & V_42 )
V_5 |= V_43 ;
break;
case V_44 :
V_37 = F_4 ( V_2 , 0 ,
V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_37 & V_45 )
V_5 |= V_46 ;
if ( V_37 & V_47 )
V_5 |= V_48 ;
break;
default:
V_5 = - V_35 ;
break;
}
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_49 * V_15 )
{
struct V_8 * V_9 ;
V_9 = F_10 ( & V_2 -> V_50 , sizeof( struct V_8 ) ,
V_51 ) ;
if ( ! V_9 )
return - V_52 ;
V_9 -> V_15 = V_15 -> V_53 ;
V_9 -> V_7 = V_54 [ V_15 -> V_53 ] ;
return F_11 ( V_2 , V_15 , & V_9 -> V_7 ) ;
}
