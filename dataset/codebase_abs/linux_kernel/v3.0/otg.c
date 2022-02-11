struct V_1 * F_1 ( void )
{
if ( V_2 )
F_2 ( V_2 -> V_3 ) ;
return V_2 ;
}
void F_3 ( struct V_1 * V_4 )
{
if ( V_4 )
F_4 ( V_4 -> V_3 ) ;
}
int F_5 ( struct V_1 * V_4 )
{
if ( V_2 && V_4 )
return - V_5 ;
V_2 = V_4 ;
return 0 ;
}
const char * F_6 ( enum V_6 V_7 )
{
switch ( V_7 ) {
case V_8 :
return L_1 ;
case V_9 :
return L_2 ;
case V_10 :
return L_3 ;
case V_11 :
return L_4 ;
case V_12 :
return L_5 ;
case V_13 :
return L_6 ;
case V_14 :
return L_7 ;
case V_15 :
return L_8 ;
case V_16 :
return L_9 ;
case V_17 :
return L_10 ;
case V_18 :
return L_11 ;
case V_19 :
return L_12 ;
case V_20 :
return L_13 ;
default:
return L_14 ;
}
}
