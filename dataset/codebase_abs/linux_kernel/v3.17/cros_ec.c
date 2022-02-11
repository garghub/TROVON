int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 ;
int V_6 , V_7 ;
F_2 ( V_4 -> V_8 > V_9 ) ;
V_5 = V_2 -> V_10 ;
V_5 [ 0 ] = V_11 + V_4 -> V_12 ;
V_5 [ 1 ] = V_4 -> V_13 ;
V_5 [ 2 ] = V_4 -> V_8 ;
V_6 = V_5 [ 0 ] + V_5 [ 1 ] + V_5 [ 2 ] ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ )
V_6 += V_5 [ V_14 + V_7 ] = V_4 -> V_15 [ V_7 ] ;
V_5 [ V_14 + V_4 -> V_8 ] = ( T_1 ) ( V_6 & 0xff ) ;
return V_16 + V_4 -> V_8 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
switch ( V_4 -> V_17 ) {
case V_18 :
return 0 ;
case V_19 :
F_4 ( V_2 -> V_20 , L_1 ,
V_4 -> V_13 ) ;
return - V_21 ;
default:
F_4 ( V_2 -> V_20 , L_2 ,
V_4 -> V_13 , V_4 -> V_17 ) ;
return 0 ;
}
}
int F_5 ( struct V_1 * V_2 )
{
struct V_22 * V_20 = V_2 -> V_20 ;
int V_23 = 0 ;
if ( V_2 -> V_24 ) {
V_2 -> V_25 = F_6 ( V_20 , V_2 -> V_24 , V_26 ) ;
if ( ! V_2 -> V_25 )
return - V_27 ;
}
if ( V_2 -> V_28 ) {
V_2 -> V_10 = F_6 ( V_20 , V_2 -> V_28 , V_26 ) ;
if ( ! V_2 -> V_10 )
return - V_27 ;
}
V_23 = F_7 ( V_20 , 0 , V_29 ,
F_8 ( V_29 ) ,
NULL , V_2 -> V_30 , NULL ) ;
if ( V_23 ) {
F_9 ( V_20 , L_3 ) ;
return V_23 ;
}
F_10 ( V_20 , L_4 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_20 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_22 * V_20 = V_2 -> V_20 ;
if ( F_14 ( V_20 ) )
V_2 -> V_31 = ! F_15 ( V_2 -> V_30 ) ;
F_16 ( V_2 -> V_30 ) ;
V_2 -> V_32 = V_2 -> V_31 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_30 ) ;
if ( V_2 -> V_31 ) {
F_19 ( V_2 -> V_30 ) ;
V_2 -> V_31 = 0 ;
}
return 0 ;
}
