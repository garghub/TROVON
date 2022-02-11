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
if ( V_9 -> V_15 != V_16 )
return - V_17 ;
V_5 = F_4 ( V_2 , V_3 ,
V_26 ) ;
break;
case V_27 :
V_5 = F_4 ( V_2 , V_3 ,
V_28 ) ;
break;
case V_29 :
if ( V_9 -> V_15 != V_16 )
return - V_17 ;
V_5 = 0 ;
break;
case V_30 :
case V_31 :
case V_32 :
V_5 = 0 ;
break;
default:
V_5 = - V_33 ;
break;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_34 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
switch ( V_4 ) {
case V_29 :
V_5 = F_6 ( V_2 , V_3 ,
V_24 , 0 ) ;
if ( V_5 )
break;
V_5 = F_6 ( V_2 , V_3 ,
V_22 , 0 ) ;
break;
case V_30 :
V_5 = F_6 ( V_2 , V_3 ,
V_11 , 0x7fff ) ;
if ( V_5 )
break;
V_5 = F_6 ( V_2 , V_3 ,
V_13 , 0 ) ;
break;
case V_31 :
V_5 = F_6 ( V_2 , V_3 ,
V_20 , 0 ) ;
if ( ! V_5 && V_9 -> V_15 == V_16 )
V_5 = F_6 ( V_2 , V_3 ,
V_18 , 0 ) ;
break;
case V_32 :
V_5 = F_6 ( V_2 , V_3 ,
V_28 ,
0x8000 ) ;
if ( ! V_5 && V_9 -> V_15 == V_16 )
V_5 = F_6 ( V_2 , V_3 ,
V_26 , 0 ) ;
break;
default:
V_5 = - V_33 ;
break;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 = 0 ;
int V_35 ;
if ( V_3 >= 0 ) {
V_5 = F_8 ( V_2 , V_3 ) ;
if ( V_5 < 0 )
return V_5 ;
}
switch ( V_4 ) {
case V_36 :
V_35 = F_4 ( V_2 , 0 ,
V_37 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 & V_38 )
V_5 |= V_39 ;
if ( V_35 & V_40 )
V_5 |= V_41 ;
break;
case V_42 :
V_35 = F_4 ( V_2 , 0 ,
V_37 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_35 & V_43 )
V_5 |= V_44 ;
if ( V_35 & V_45 )
V_5 |= V_46 ;
break;
default:
V_5 = - V_33 ;
break;
}
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_47 * V_15 )
{
struct V_8 * V_9 ;
V_9 = F_10 ( & V_2 -> V_48 , sizeof( struct V_8 ) ,
V_49 ) ;
if ( ! V_9 )
return - V_50 ;
V_9 -> V_15 = V_15 -> V_51 ;
V_9 -> V_7 = V_52 [ V_15 -> V_51 ] ;
return F_11 ( V_2 , V_15 , & V_9 -> V_7 ) ;
}
