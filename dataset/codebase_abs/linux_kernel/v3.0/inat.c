T_1 F_1 ( T_2 V_1 )
{
return V_2 [ V_1 ] ;
}
T_1 F_2 ( T_2 V_1 , T_2 V_3 ,
T_1 V_4 )
{
const T_1 * V_5 ;
T_1 V_6 ;
int V_7 , V_8 = 0 ;
V_7 = F_3 ( V_4 ) ;
if ( V_3 ) {
V_6 = F_1 ( V_3 ) ;
V_8 = F_4 ( V_6 ) ;
}
V_5 = V_9 [ V_7 ] [ 0 ] ;
if ( ! V_5 )
return 0 ;
if ( F_5 ( V_5 [ V_1 ] ) && V_8 ) {
V_5 = V_9 [ V_7 ] [ V_8 ] ;
if ( ! V_5 )
return 0 ;
}
return V_5 [ V_1 ] ;
}
T_1 F_6 ( T_2 V_10 , T_2 V_3 ,
T_1 V_11 )
{
const T_1 * V_5 ;
T_1 V_6 ;
int V_7 , V_8 = 0 ;
V_7 = F_7 ( V_11 ) ;
if ( V_3 ) {
V_6 = F_1 ( V_3 ) ;
V_8 = F_4 ( V_6 ) ;
}
V_5 = V_12 [ V_7 ] [ 0 ] ;
if ( ! V_5 )
return F_8 ( V_11 ) ;
if ( F_5 ( V_5 [ F_9 ( V_10 ) ] ) && V_8 ) {
V_5 = V_12 [ V_7 ] [ V_8 ] ;
if ( ! V_5 )
return F_8 ( V_11 ) ;
}
return V_5 [ F_9 ( V_10 ) ] |
F_8 ( V_11 ) ;
}
T_1 F_10 ( T_2 V_1 , T_2 V_13 ,
T_2 V_14 )
{
const T_1 * V_5 ;
if ( V_13 > V_15 || V_14 > V_16 )
return 0 ;
V_5 = V_17 [ V_13 ] [ V_14 ] ;
if ( ! V_5 )
return 0 ;
return V_5 [ V_1 ] ;
}
