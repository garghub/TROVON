int F_1 ( T_1 V_1 , T_1 V_2 , int V_3 )
{
static T_2 V_4 = F_2 ( 0 ) ;
F_3 ( ! ( V_1 & V_5 ) ) ;
if ( ( V_6 & ( V_7 | V_5 ) ) ==
( V_7 | V_5 ) ) {
F_4 ( & V_4 , 0 ) ;
return 0 ;
}
if ( V_6 & V_8 ) {
if ( V_9 < 2 || V_10 ( ) % V_9 > 0 )
return 0 ;
}
if ( V_6 & V_11 ) {
if ( F_5 ( & V_4 ) <= V_9 )
return 0 ;
}
if ( V_3 == V_12 ) {
if ( V_9 != - 1 && V_9 != V_2 )
return 0 ;
}
if ( V_6 & V_13 &&
( ! ( V_6 & V_5 ) || V_9 <= 1 ) ) {
int V_14 = F_5 ( & V_4 ) ;
if ( V_14 >= V_9 ) {
F_6 ( V_15 , & V_6 ) ;
F_4 ( & V_4 , 0 ) ;
if ( V_14 > V_9 )
return 0 ;
}
}
if ( ( V_3 == V_16 ) && ( V_2 & V_5 ) )
F_6 ( V_15 , & V_6 ) ;
if ( F_7 ( V_17 , & V_6 ) ) {
if ( V_6 & V_5 )
return 0 ;
}
switch ( V_3 ) {
case V_18 :
case V_12 :
break;
case V_16 :
V_6 |= V_2 & ~ ( V_7 | V_5 ) ;
break;
case V_19 :
V_6 = V_2 ;
F_4 ( & V_4 , 0 ) ;
break;
default:
F_8 ( 0 , L_1 , V_3 ) ;
break;
}
return 1 ;
}
int F_9 ( T_1 V_1 , T_1 V_2 , int V_20 , int V_3 )
{
int V_21 ;
V_21 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_21 && F_10 ( V_20 > 0 ) ) {
F_11 ( L_2 ,
V_1 , V_20 ) ;
F_12 ( V_22 ) ;
F_13 ( F_14 ( V_20 ) / 1000 ) ;
F_11 ( L_3 , V_1 ) ;
}
return V_21 ;
}
