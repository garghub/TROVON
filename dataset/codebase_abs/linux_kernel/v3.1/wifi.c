bool F_1 ( T_1 V_1 )
{
if ( ! F_2 ( V_1 ) && ! F_3 ( V_1 ) )
return true ;
if ( ! F_4 ( V_1 ) && ! F_5 ( V_1 ) )
return true ;
if ( F_5 ( V_1 ) ) {
if ( ! F_6 ( V_1 ) )
return true ;
} else {
if ( ! F_7 ( V_1 ) && ! F_8 ( V_1 ) )
return true ;
}
return false ;
}
T_2 F_9 ( T_1 V_2 )
{
T_2 V_3 ;
if ( F_10 ( V_2 ) == V_4 ) {
return F_11 ( V_2 ) ;
} else {
if ( F_10 ( V_2 ) == V_5 ) {
V_3 = F_12 ( F_11 ( V_2 ) ) ;
} else {
V_3 = F_13 ( F_11 ( V_2 ) ) ;
}
}
return V_3 ;
}
int F_14 ( T_3 V_6 , T_3 V_7 )
{
int V_8 = - 1 ;
T_3 V_9 ;
int V_10 ;
if ( V_7 == 0 ) {
if ( V_6 >= 2400 && V_6 <= 2500 )
V_7 = V_11 ;
else if ( V_6 >= 5000 && V_6 <= 6000 )
V_7 = V_12 ;
}
if ( V_6 == 2484 && V_7 == V_11 )
return 14 ;
V_9 = V_7 / 2 ;
if ( ( V_6 < V_9 ) || ( V_6 > V_9 + 1000 ) )
return - 1 ;
V_10 = V_6 - V_9 ;
V_8 = V_10 / 5 ;
if ( V_10 != ( V_8 * 5 ) )
return - 1 ;
if ( V_7 == V_11 && ( V_8 < 1 || V_8 > 13 ) )
return - 1 ;
return V_8 ;
}
