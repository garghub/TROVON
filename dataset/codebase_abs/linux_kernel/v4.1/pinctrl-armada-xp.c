static int F_1 ( unsigned V_1 , unsigned long * V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static int F_3 ( unsigned V_1 , unsigned long V_2 )
{
return F_4 ( V_3 , V_1 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 =
F_6 ( V_5 ) ;
int V_9 , V_10 ;
V_10 = F_7 ( V_8 -> V_11 , V_12 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
V_13 [ V_9 ] = F_8 ( V_3 + V_9 * 4 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_7 * V_8 =
F_6 ( V_5 ) ;
int V_9 , V_10 ;
V_10 = F_7 ( V_8 -> V_11 , V_12 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_10 ( V_13 [ V_9 ] , V_3 + V_9 * 4 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = & V_14 ;
const struct V_15 * V_16 =
F_12 ( V_17 , & V_5 -> V_18 ) ;
struct V_19 * V_20 ;
int V_10 ;
if ( ! V_16 )
return - V_21 ;
V_20 = F_13 ( V_5 , V_22 , 0 ) ;
V_3 = F_14 ( & V_5 -> V_18 , V_20 ) ;
if ( F_15 ( V_3 ) )
return F_16 ( V_3 ) ;
V_8 -> V_23 = ( unsigned ) V_16 -> V_24 & 0xff ;
switch ( V_8 -> V_23 ) {
case V_25 :
V_8 -> V_26 = V_27 ;
V_8 -> V_28 = F_17 ( V_27 ) ;
V_8 -> V_29 = V_30 ;
V_8 -> V_11 = V_27 [ 0 ] . V_31 ;
V_8 -> V_32 = V_33 ;
V_8 -> V_34 = F_17 ( V_33 ) ;
break;
case V_35 :
V_8 -> V_26 = V_36 ;
V_8 -> V_28 = F_17 ( V_36 ) ;
V_8 -> V_29 = V_30 ;
V_8 -> V_11 = V_36 [ 0 ] . V_31 ;
V_8 -> V_32 = V_37 ;
V_8 -> V_34 = F_17 ( V_37 ) ;
break;
case V_38 :
V_8 -> V_26 = V_39 ;
V_8 -> V_28 = F_17 ( V_39 ) ;
V_8 -> V_29 = V_30 ;
V_8 -> V_11 = V_39 [ 0 ] . V_31 ;
V_8 -> V_32 = V_40 ;
V_8 -> V_34 = F_17 ( V_40 ) ;
break;
}
V_10 = F_7 ( V_8 -> V_11 , V_12 ) ;
V_13 = F_18 ( & V_5 -> V_18 , V_10 * sizeof( V_41 ) ,
V_42 ) ;
if ( ! V_13 )
return - V_43 ;
V_5 -> V_18 . V_44 = V_8 ;
return F_19 ( V_5 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
return F_21 ( V_5 ) ;
}
