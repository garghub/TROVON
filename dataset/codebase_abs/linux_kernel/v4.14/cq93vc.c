static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 ;
if ( V_3 )
V_6 = V_7 ;
else
V_6 = 0 ;
F_2 ( V_5 , V_8 , V_7 ,
V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_9 ,
int V_10 , unsigned int V_11 , int V_12 )
{
switch ( V_11 ) {
case 22579200 :
case 27000000 :
case 33868800 :
return 0 ;
}
return - V_13 ;
}
static int F_4 ( struct V_4 * V_5 ,
enum V_14 V_15 )
{
switch ( V_15 ) {
case V_16 :
F_5 ( V_5 , V_17 ,
V_18 ) ;
break;
case V_19 :
break;
case V_20 :
F_5 ( V_5 , V_17 ,
V_21 ) ;
break;
case V_22 :
F_5 ( V_5 , V_17 ,
V_21 ) ;
break;
}
return 0 ;
}
static struct V_23 * F_6 ( struct V_24 * V_25 )
{
struct V_26 * V_26 = V_25 -> V_27 ;
return V_26 -> V_23 ;
}
static int F_7 ( struct V_28 * V_29 )
{
return F_8 ( & V_29 -> V_25 ,
& V_30 , & V_31 , 1 ) ;
}
static int F_9 ( struct V_28 * V_29 )
{
F_10 ( & V_29 -> V_25 ) ;
return 0 ;
}
