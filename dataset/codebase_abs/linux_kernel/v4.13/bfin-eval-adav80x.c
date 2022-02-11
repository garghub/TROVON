static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , V_11 , V_12 ,
27000000 , F_3 ( V_4 ) * 256 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_4 ( V_9 , V_13 ,
F_3 ( V_4 ) * 256 , V_14 ) ;
return V_10 ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
F_4 ( V_9 , V_15 , 0 ,
V_16 ) ;
F_4 ( V_9 , V_17 , 0 ,
V_16 ) ;
F_4 ( V_9 , V_18 , 0 ,
V_16 ) ;
F_4 ( V_9 , V_19 , 2700000 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_24 ;
const char * V_25 ;
switch ( F_7 ( V_21 ) -> V_26 ) {
case V_27 :
V_25 = L_1 ;
break;
case V_28 :
V_25 = L_2 ;
break;
default:
return - V_29 ;
}
V_30 [ 0 ] . V_25 = V_25 ;
V_23 -> V_31 = & V_21 -> V_31 ;
return F_8 ( & V_21 -> V_31 , & V_24 ) ;
}
