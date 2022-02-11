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
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_22 ;
F_6 ( & V_2 -> V_23 ) ;
V_22 = V_2 -> V_24 ( V_2 , V_4 ) ;
if ( V_4 -> V_17 == V_19 ) {
int V_7 ;
struct V_3 V_25 ;
struct V_26 V_27 ;
V_25 . V_12 = 0 ;
V_25 . V_13 = V_28 ;
V_25 . V_15 = NULL ;
V_25 . V_8 = 0 ;
V_25 . V_29 = ( T_1 * ) & V_27 ;
V_25 . V_30 = sizeof( V_27 ) ;
for ( V_7 = 0 ; V_7 < V_31 ; V_7 ++ ) {
F_7 ( 10000 , 11000 ) ;
V_22 = V_2 -> V_24 ( V_2 , & V_25 ) ;
if ( V_22 < 0 )
break;
V_4 -> V_17 = V_25 . V_17 ;
if ( V_25 . V_17 != V_18 )
break;
if ( ! ( V_27 . V_32 & V_33 ) )
break;
}
}
F_8 ( & V_2 -> V_23 ) ;
return V_22 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_34 * V_20 = V_2 -> V_20 ;
int V_35 = 0 ;
if ( V_2 -> V_36 ) {
V_2 -> V_37 = F_10 ( V_20 , V_2 -> V_36 , V_38 ) ;
if ( ! V_2 -> V_37 )
return - V_39 ;
}
if ( V_2 -> V_40 ) {
V_2 -> V_10 = F_10 ( V_20 , V_2 -> V_40 , V_38 ) ;
if ( ! V_2 -> V_10 )
return - V_39 ;
}
F_11 ( & V_2 -> V_23 ) ;
V_35 = F_12 ( V_20 , 0 , V_41 ,
F_13 ( V_41 ) ,
NULL , V_2 -> V_42 , NULL ) ;
if ( V_35 ) {
F_14 ( V_20 , L_3 ) ;
return V_35 ;
}
F_15 ( V_20 , L_4 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_20 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_34 * V_20 = V_2 -> V_20 ;
if ( F_19 ( V_20 ) )
V_2 -> V_43 = ! F_20 ( V_2 -> V_42 ) ;
F_21 ( V_2 -> V_42 ) ;
V_2 -> V_44 = V_2 -> V_43 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 -> V_42 ) ;
if ( V_2 -> V_43 ) {
F_24 ( V_2 -> V_42 ) ;
V_2 -> V_43 = 0 ;
}
return 0 ;
}
