static T_1 * F_1 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 * V_3 ;
while ( * V_1 ++ != V_4 ) {
V_3 = V_1 + V_5 - 1 ;
if ( V_3 > V_2 )
return NULL ;
V_1 = V_3 ;
}
return V_1 ;
}
static T_1 * F_2 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 * V_3 ;
while ( * V_1 ++ != V_4 ) {
V_3 = V_1 + 1 + F_3 ( V_1 ) * V_6 ;
if ( V_3 > V_2 )
return NULL ;
V_1 = V_3 ;
}
return V_1 ;
}
static T_1 * F_4 ( T_1 * V_1 , T_1 * V_2 )
{
T_1 * V_3 ;
if ( * V_1 ++ != V_4 ) {
V_3 = V_1 + 1 + F_3 ( V_1 ) * V_6 ;
if ( V_3 > V_2 )
return NULL ;
V_1 = V_3 ;
}
return V_1 ;
}
int F_5 ( struct V_7 * V_8 )
{
T_1 * V_1 , * V_2 , * V_9 ;
unsigned int V_10 ;
if ( V_8 -> V_11 <= V_12 )
goto V_13;
V_9 = V_8 -> V_14 [ 0 ] . V_15 ;
if ( * ( V_9 + 1 ) != V_16 )
goto V_17;
switch ( * ( V_9 + 3 ) ) {
case V_18 :
case V_19 :
break;
case V_20 :
goto V_21;
case V_22 :
goto V_21;
default:
goto V_23;
}
V_2 = ( T_1 * ) ( ( unsigned long ) V_9 + V_8 -> V_11 ) ;
V_1 = F_1 ( V_9 + 4 , V_2 ) ;
if ( ! V_1 )
goto V_24;
V_1 = F_2 ( V_1 , V_2 ) ;
if ( ! V_1 )
goto V_24;
V_1 = F_4 ( V_1 , V_2 ) ;
if ( ! V_1 )
goto V_24;
if ( V_1 > V_2 )
goto V_24;
V_8 -> V_14 [ 0 ] . V_15 = V_1 ;
V_10 = ( unsigned long ) V_1 - ( unsigned long ) V_9 ;
V_8 -> V_14 [ 0 ] . V_25 -= V_10 ;
return V_10 ;
V_13:
F_6 ( L_1 , V_8 -> V_11 ) ;
return - V_26 ;
V_17:
F_6 ( L_2 ,
F_3 ( V_9 + 1 ) ) ;
return - V_27 ;
V_21:
F_6 ( L_3 ) ;
return 0 ;
V_23:
F_6 ( L_4 ,
F_3 ( V_9 + 3 ) ) ;
return - V_26 ;
V_24:
F_6 ( L_5 ) ;
return - V_26 ;
}
