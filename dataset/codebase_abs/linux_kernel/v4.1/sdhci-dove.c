static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( V_3 ) {
case V_5 :
case V_6 :
return 0 ;
default:
V_4 = F_2 ( V_2 -> V_7 + V_3 ) ;
}
return V_4 ;
}
static T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_4 ;
V_4 = F_4 ( V_2 -> V_7 + V_3 ) ;
switch ( V_3 ) {
case V_8 :
V_4 &= ~ V_9 ;
break;
}
return V_4 ;
}
static int F_5 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 ;
int V_4 ;
V_2 = F_6 ( V_11 , & V_14 , 0 ) ;
if ( F_7 ( V_2 ) )
return F_8 ( V_2 ) ;
V_13 = F_9 ( V_2 ) ;
V_13 -> V_15 = F_10 ( & V_11 -> V_16 , NULL ) ;
if ( ! F_7 ( V_13 -> V_15 ) )
F_11 ( V_13 -> V_15 ) ;
V_4 = F_12 ( V_2 -> V_17 ) ;
if ( V_4 )
goto V_18;
V_4 = F_13 ( V_2 ) ;
if ( V_4 )
goto V_18;
return 0 ;
V_18:
F_14 ( V_13 -> V_15 ) ;
F_15 ( V_11 ) ;
return V_4 ;
}
