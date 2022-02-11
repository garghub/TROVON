static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , V_7 ) ;
if ( V_6 >= 0 ) {
int V_8 = V_6 & 0xfff0 ;
if ( V_8 == V_9 )
return L_1 ;
if ( V_8 == V_10 )
return L_2 ;
if ( V_6 == V_11 )
return L_3 ;
if ( V_8 == V_12 )
return L_4 ;
if ( V_8 == V_13 )
return L_5 ;
}
return NULL ;
}
static int F_5 ( struct V_14 * V_15 )
{
T_1 V_16 = F_6 ( V_15 ) ;
int V_6 ;
T_1 V_17 ;
V_6 = F_7 ( V_15 ) ;
if ( V_6 )
return V_6 ;
F_8 ( V_18 , V_19 ,
V_20 | V_21 ) ;
F_8 ( V_18 , V_22 , 0x8100 ) ;
V_17 = V_16 << V_23 |
V_16 << V_24 |
V_25 ;
F_8 ( V_18 , V_26 , V_17 ) ;
if ( V_15 -> V_27 -> V_28 -> V_29 > 1 )
F_8 ( V_18 , V_30 ,
V_31 |
( V_15 -> V_32 & 0x1f ) ) ;
else
F_8 ( V_18 , V_30 ,
V_33 |
( V_15 -> V_32 & 0x1f ) ) ;
F_8 ( V_34 , V_35 ,
V_36 |
7 << V_37 |
V_38 |
7 << V_39 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_40 * V_41 = F_10 ( V_15 ) ;
int V_6 ;
V_6 = F_11 ( V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
F_12 ( V_15 ) ;
switch ( V_41 -> V_42 ) {
case V_9 :
case V_13 :
V_41 -> V_43 = 10 ;
break;
case V_10 :
V_41 -> V_43 = 11 ;
break;
case V_12 :
case V_11 :
V_41 -> V_43 = 8 ;
break;
default:
return - V_44 ;
}
V_6 = F_13 ( V_15 , false ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_14 ( V_15 ) ;
}
static int F_15 ( struct V_14 * V_15 , int V_45 )
{
struct V_40 * V_41 = F_10 ( V_15 ) ;
if ( V_45 >= 0 && V_45 < V_41 -> V_43 )
return V_45 ;
return - V_46 ;
}
static int
F_16 ( struct V_14 * V_15 , int V_45 , int V_47 )
{
int V_48 = F_15 ( V_15 , V_45 ) ;
if ( V_48 < 0 )
return V_48 ;
return F_17 ( V_15 , V_48 , V_47 ) ;
}
static int
F_18 ( struct V_14 * V_15 ,
int V_45 , int V_47 , T_2 V_49 )
{
int V_48 = F_15 ( V_15 , V_45 ) ;
if ( V_48 < 0 )
return V_48 ;
return F_19 ( V_15 , V_48 , V_47 , V_49 ) ;
}
