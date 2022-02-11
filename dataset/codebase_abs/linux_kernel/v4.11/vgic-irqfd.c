static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 ,
int V_5 , bool V_6 )
{
unsigned int V_7 = V_2 -> V_8 . V_9 + V_10 ;
if ( ! F_2 ( V_3 , V_7 ) )
return - V_11 ;
return F_3 ( V_3 , 0 , V_7 , V_5 ) ;
}
int F_4 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
int V_14 = - V_11 ;
switch ( V_13 -> type ) {
case V_15 :
V_2 -> V_16 = F_1 ;
V_2 -> V_8 . V_8 = V_13 -> V_17 . V_8 . V_8 ;
V_2 -> V_8 . V_9 = V_13 -> V_17 . V_8 . V_9 ;
if ( ( V_2 -> V_8 . V_9 >= V_18 ) ||
( V_2 -> V_8 . V_8 >= V_19 ) )
goto V_20;
break;
case V_21 :
V_2 -> V_16 = V_22 ;
V_2 -> V_23 . V_24 = V_13 -> V_17 . V_23 . V_24 ;
V_2 -> V_23 . V_25 = V_13 -> V_17 . V_23 . V_25 ;
V_2 -> V_23 . V_26 = V_13 -> V_17 . V_23 . V_26 ;
V_2 -> V_23 . V_27 = V_13 -> V_27 ;
V_2 -> V_23 . V_28 = V_13 -> V_17 . V_23 . V_28 ;
break;
default:
goto V_20;
}
V_14 = 0 ;
V_20:
return V_14 ;
}
int V_22 ( struct V_1 * V_2 ,
struct V_3 * V_3 , int V_4 ,
int V_5 , bool V_6 )
{
struct V_29 V_23 ;
V_23 . V_24 = V_2 -> V_23 . V_24 ;
V_23 . V_25 = V_2 -> V_23 . V_25 ;
V_23 . V_26 = V_2 -> V_23 . V_26 ;
V_23 . V_27 = V_2 -> V_23 . V_27 ;
V_23 . V_28 = V_2 -> V_23 . V_28 ;
if ( ! F_5 ( V_3 ) )
return - V_30 ;
if ( ! V_5 )
return - 1 ;
return F_6 ( V_3 , & V_23 ) ;
}
int F_7 ( struct V_3 * V_3 )
{
struct V_12 * V_31 ;
struct V_32 * V_33 = & V_3 -> V_34 . V_35 ;
T_1 V_36 = V_33 -> V_37 ;
int V_38 , V_39 ;
V_31 = F_8 ( V_36 , sizeof( struct V_1 ) ,
V_40 ) ;
if ( ! V_31 )
return - V_41 ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
V_31 [ V_38 ] . V_42 = V_38 ;
V_31 [ V_38 ] . type = V_15 ;
V_31 [ V_38 ] . V_17 . V_8 . V_8 = 0 ;
V_31 [ V_38 ] . V_17 . V_8 . V_9 = V_38 ;
}
V_39 = F_9 ( V_3 , V_31 , V_36 , 0 ) ;
F_10 ( V_31 ) ;
return V_39 ;
}
