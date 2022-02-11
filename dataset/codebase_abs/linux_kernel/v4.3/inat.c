T_1 F_1 ( T_2 V_1 )
{
return V_2 [ V_1 ] ;
}
int F_2 ( T_2 V_3 )
{
T_1 V_4 ;
V_4 = F_1 ( V_3 ) ;
return F_3 ( V_4 ) ;
}
T_1 F_4 ( T_2 V_1 , int V_5 ,
T_1 V_6 )
{
const T_1 * V_7 ;
int V_8 ;
V_8 = F_5 ( V_6 ) ;
V_7 = V_9 [ V_8 ] [ 0 ] ;
if ( ! V_7 )
return 0 ;
if ( F_6 ( V_7 [ V_1 ] ) && V_5 ) {
V_7 = V_9 [ V_8 ] [ V_5 ] ;
if ( ! V_7 )
return 0 ;
}
return V_7 [ V_1 ] ;
}
T_1 F_7 ( T_2 V_10 , int V_5 ,
T_1 V_11 )
{
const T_1 * V_7 ;
int V_8 ;
V_8 = F_8 ( V_11 ) ;
V_7 = V_12 [ V_8 ] [ 0 ] ;
if ( ! V_7 )
return F_9 ( V_11 ) ;
if ( F_6 ( V_7 [ F_10 ( V_10 ) ] ) && V_5 ) {
V_7 = V_12 [ V_8 ] [ V_5 ] ;
if ( ! V_7 )
return F_9 ( V_11 ) ;
}
return V_7 [ F_10 ( V_10 ) ] |
F_9 ( V_11 ) ;
}
T_1 F_11 ( T_2 V_1 , T_2 V_13 ,
T_2 V_14 )
{
const T_1 * V_7 ;
if ( V_13 > V_15 || V_14 > V_16 )
return 0 ;
V_7 = V_17 [ V_13 ] [ 0 ] ;
if ( ! V_7 )
return 0 ;
if ( ! F_12 ( V_7 [ V_1 ] ) && V_14 ) {
V_7 = V_17 [ V_13 ] [ V_14 ] ;
if ( ! V_7 )
return 0 ;
}
return V_7 [ V_1 ] ;
}
