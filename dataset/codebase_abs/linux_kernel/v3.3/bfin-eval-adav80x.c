static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_9 , V_12 |
V_13 | V_14 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_2 ( V_10 , V_12 |
V_13 | V_14 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_10 , V_15 , V_16 ,
27000000 , F_4 ( V_4 ) * 256 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_10 , V_17 ,
F_4 ( V_4 ) * 256 , V_18 ) ;
return V_11 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = V_6 -> V_10 ;
F_5 ( V_10 , V_19 , 0 ,
V_20 ) ;
F_5 ( V_10 , V_21 , 0 ,
V_20 ) ;
F_5 ( V_10 , V_22 , 0 ,
V_20 ) ;
F_5 ( V_10 , V_23 , 2700000 , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_28 ;
const char * V_29 ;
switch ( F_8 ( V_25 ) -> V_30 ) {
case V_31 :
V_29 = L_1 ;
break;
case V_32 :
V_29 = L_2 ;
break;
default:
return - V_33 ;
}
V_34 [ 0 ] . V_29 = V_29 ;
V_27 -> V_35 = & V_25 -> V_35 ;
return F_9 ( & V_28 ) ;
}
static int T_1 F_10 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_11 ( V_25 ) ;
F_12 ( V_27 ) ;
return 0 ;
}
