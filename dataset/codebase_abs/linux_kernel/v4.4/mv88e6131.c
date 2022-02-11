static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 , V_3 , V_4 ,
F_3 ( V_4 ) ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
T_1 V_7 = F_5 ( V_6 ) ;
int V_8 ;
T_1 V_9 ;
V_8 = F_6 ( V_6 ) ;
if ( V_8 )
return V_8 ;
F_7 ( V_10 , V_11 ,
V_12 | V_13 ) ;
F_7 ( V_10 , V_14 , 0x8100 ) ;
V_9 = V_7 << V_15 |
V_7 << V_16 |
V_17 ;
F_7 ( V_10 , V_18 , V_9 ) ;
if ( V_6 -> V_19 -> V_20 -> V_21 > 1 )
F_7 ( V_10 , V_22 ,
V_23 |
( V_6 -> V_24 & 0x1f ) ) ;
else
F_7 ( V_10 , V_22 ,
V_25 |
( V_6 -> V_24 & 0x1f ) ) ;
F_7 ( V_26 , V_27 ,
V_28 |
7 << V_29 |
V_30 |
7 << V_31 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_32 * V_33 = F_9 ( V_6 ) ;
int V_8 ;
V_8 = F_10 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
F_11 ( V_6 ) ;
switch ( V_33 -> V_34 ) {
case V_35 :
case V_36 :
V_33 -> V_37 = 10 ;
break;
case V_38 :
V_33 -> V_37 = 11 ;
break;
case V_39 :
case V_40 :
V_33 -> V_37 = 8 ;
break;
default:
return - V_41 ;
}
V_8 = F_12 ( V_6 , false ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_4 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_13 ( V_6 ) ;
}
static int F_14 ( struct V_5 * V_6 , int V_42 )
{
struct V_32 * V_33 = F_9 ( V_6 ) ;
if ( V_42 >= 0 && V_42 < V_33 -> V_37 )
return V_42 ;
return - V_43 ;
}
static int
F_15 ( struct V_5 * V_6 , int V_42 , int V_44 )
{
int V_45 = F_14 ( V_6 , V_42 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_16 ( V_6 , V_45 , V_44 ) ;
}
static int
F_17 ( struct V_5 * V_6 ,
int V_42 , int V_44 , T_2 V_46 )
{
int V_45 = F_14 ( V_6 , V_42 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_18 ( V_6 , V_45 , V_44 , V_46 ) ;
}
