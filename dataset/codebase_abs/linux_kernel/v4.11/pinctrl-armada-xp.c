static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 =
F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_7 = F_3 ( V_5 -> V_8 , V_9 ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_10 [ V_6 ] = F_4 ( V_5 -> V_11 [ 0 ] . V_12 + V_6 * 4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 =
F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_7 = F_3 ( V_5 -> V_8 , V_9 ) ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
F_6 ( V_10 [ V_6 ] , V_5 -> V_11 [ 0 ] . V_12 + V_6 * 4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_13 ;
const struct V_14 * V_15 =
F_8 ( V_16 , & V_2 -> V_17 ) ;
int V_7 ;
if ( ! V_15 )
return - V_18 ;
V_5 -> V_19 = ( unsigned ) V_15 -> V_20 & 0xff ;
switch ( V_5 -> V_19 ) {
case V_21 :
V_5 -> V_22 = V_23 ;
V_5 -> V_24 = F_9 ( V_23 ) ;
V_5 -> V_25 = V_26 ;
V_5 -> V_8 = V_23 [ 0 ] . V_27 ;
V_5 -> V_28 = V_29 ;
V_5 -> V_30 = F_9 ( V_29 ) ;
break;
case V_31 :
V_5 -> V_22 = V_32 ;
V_5 -> V_24 = F_9 ( V_32 ) ;
V_5 -> V_25 = V_26 ;
V_5 -> V_8 = V_32 [ 0 ] . V_27 ;
V_5 -> V_28 = V_33 ;
V_5 -> V_30 = F_9 ( V_33 ) ;
break;
case V_34 :
V_5 -> V_22 = V_35 ;
V_5 -> V_24 = F_9 ( V_35 ) ;
V_5 -> V_25 = V_26 ;
V_5 -> V_8 = V_35 [ 0 ] . V_27 ;
V_5 -> V_28 = V_36 ;
V_5 -> V_30 = F_9 ( V_36 ) ;
break;
case V_37 :
case V_38 :
case V_39 :
V_5 -> V_22 = V_40 ;
V_5 -> V_24 = F_9 ( V_40 ) ;
V_5 -> V_25 = V_41 ;
V_5 -> V_8 = V_40 [ 0 ] . V_27 ;
V_5 -> V_28 = V_42 ;
V_5 -> V_30 = F_9 ( V_42 ) ;
break;
}
V_7 = F_3 ( V_5 -> V_8 , V_9 ) ;
V_10 = F_10 ( & V_2 -> V_17 , V_7 * sizeof( V_43 ) ,
V_44 ) ;
if ( ! V_10 )
return - V_45 ;
V_2 -> V_17 . V_46 = V_5 ;
return F_11 ( V_2 ) ;
}
