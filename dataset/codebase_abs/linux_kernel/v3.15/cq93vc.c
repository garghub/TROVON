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
struct V_4 * V_5 = V_9 -> V_5 ;
struct V_13 * V_13 = V_5 -> V_14 -> V_15 ;
switch ( V_11 ) {
case 22579200 :
case 27000000 :
case 33868800 :
V_13 -> V_16 . V_17 = V_11 ;
return 0 ;
}
return - V_18 ;
}
static int F_4 ( struct V_4 * V_5 ,
enum V_19 V_20 )
{
switch ( V_20 ) {
case V_21 :
F_5 ( V_5 , V_22 ,
V_23 ) ;
break;
case V_24 :
break;
case V_25 :
F_5 ( V_5 , V_22 ,
V_26 ) ;
break;
case V_27 :
F_5 ( V_5 , V_22 ,
V_26 ) ;
break;
}
V_5 -> V_28 . V_29 = V_20 ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 )
{
F_4 ( V_5 , V_25 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
struct V_13 * V_13 = V_5 -> V_14 -> V_15 ;
V_13 -> V_16 . V_5 = V_5 ;
F_8 ( V_5 , V_13 -> V_30 ) ;
F_4 ( V_5 , V_25 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
F_4 ( V_5 , V_27 ) ;
return 0 ;
}
static int F_10 ( struct V_31 * V_32 )
{
return F_11 ( & V_32 -> V_14 ,
& V_33 , & V_34 , 1 ) ;
}
static int F_12 ( struct V_31 * V_32 )
{
F_13 ( & V_32 -> V_14 ) ;
return 0 ;
}
