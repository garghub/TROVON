static T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_1 V_3 = 0 ;
T_1 V_4 ;
V_4 = F_2 ( V_5 , V_6 ) ;
V_2 = V_7 ;
while ( V_2 -> V_8 >= 0 && V_2 -> V_9 >= 0 ) {
if ( V_4 & ( 1 << V_2 -> V_8 ) )
V_3 |= 1 << V_2 -> V_9 ;
V_2 ++ ;
}
return V_3 ;
}
static int F_3 ( T_2 V_10 )
{
T_2 V_11 ;
switch ( V_10 ) {
case V_12 :
V_11 = V_13 ;
break;
case V_14 :
V_11 = V_15 ;
break;
case V_16 :
V_11 = V_17 ;
break;
default:
return - V_18 ;
}
return V_11 ;
}
void F_4 ( void )
{
F_5 ( V_19 , V_5 ,
V_20 ) ;
F_2 ( V_5 , V_20 ) ;
}
int F_6 ( struct V_21 * V_22 )
{
F_5 ( V_23 ,
V_22 -> V_24 . V_25 -> V_26 ,
V_27 ) ;
return 0 ;
}
int F_7 ( struct V_21 * V_22 )
{
F_8 ( V_23 ,
V_22 -> V_24 . V_25 -> V_26 ,
V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_28 * V_24 , T_2 V_11 )
{
T_2 V_29 ;
switch ( V_11 ) {
case V_13 :
V_29 = V_12 ;
break;
case V_15 :
V_29 = V_14 ;
break;
case V_17 :
V_29 = V_16 ;
break;
default:
return - V_18 ;
}
F_10 ( V_30 ,
( V_29 << V_31 ) ,
V_24 -> V_26 , V_27 ) ;
return 0 ;
}
static int F_11 ( struct V_28 * V_24 )
{
T_2 V_10 ;
V_10 = F_12 ( V_24 -> V_26 ,
V_27 ,
V_30 ) ;
return F_3 ( V_10 ) ;
}
static int F_13 ( struct V_28 * V_24 )
{
T_2 V_10 ;
V_10 = F_12 ( V_24 -> V_26 ,
V_32 ,
V_33 ) ;
return F_3 ( V_10 ) ;
}
int T_3 F_14 ( void )
{
return F_15 ( & V_34 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_34 ) ;
}
