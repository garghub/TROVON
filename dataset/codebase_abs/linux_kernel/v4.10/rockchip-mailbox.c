static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 -> V_7 ) ;
struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = V_5 -> V_11 ;
if ( ! V_9 )
return - V_12 ;
if ( V_9 -> V_13 > V_5 -> V_14 ) {
F_3 ( V_5 -> V_6 . V_7 , L_1 ,
V_5 -> V_14 ) ;
return - V_12 ;
}
F_4 ( V_5 -> V_6 . V_7 , L_2 ,
V_11 -> V_15 , V_9 -> V_16 ) ;
V_5 -> V_11 [ V_11 -> V_15 ] . V_9 = V_9 ;
F_5 ( V_9 -> V_16 , V_5 -> V_17 + F_6 ( V_11 -> V_15 ) ) ;
F_5 ( V_9 -> V_13 , V_5 -> V_17 +
F_7 ( V_11 -> V_15 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 -> V_7 ) ;
F_5 ( ( 1 << V_5 -> V_6 . V_18 ) - 1 ,
V_5 -> V_17 + V_19 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 -> V_7 ) ;
struct V_10 * V_11 = V_5 -> V_11 ;
F_5 ( 0 , V_5 -> V_17 + V_19 ) ;
V_5 -> V_11 [ V_11 -> V_15 ] . V_9 = NULL ;
}
static T_1 F_10 ( int V_20 , void * V_21 )
{
int V_15 ;
struct V_4 * V_5 = (struct V_4 * ) V_21 ;
T_2 V_22 = F_11 ( V_5 -> V_17 + V_23 ) ;
for ( V_15 = 0 ; V_15 < V_5 -> V_6 . V_18 ; V_15 ++ ) {
if ( ( V_22 & ( 1 << V_15 ) ) && ( V_20 == V_5 -> V_11 [ V_15 ] . V_20 ) ) {
F_5 ( 1 << V_15 ,
V_5 -> V_17 + V_23 ) ;
return V_24 ;
}
}
return V_25 ;
}
static T_1 F_12 ( int V_20 , void * V_21 )
{
int V_15 ;
struct V_8 * V_9 = NULL ;
struct V_4 * V_5 = (struct V_4 * ) V_21 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_6 . V_18 ; V_15 ++ ) {
if ( V_20 != V_5 -> V_11 [ V_15 ] . V_20 )
continue;
V_9 = V_5 -> V_11 [ V_15 ] . V_9 ;
if ( ! V_9 ) {
F_3 ( V_5 -> V_6 . V_7 ,
L_3 , V_15 ) ;
break;
}
F_13 ( & V_5 -> V_6 . V_11 [ V_15 ] , V_9 ) ;
V_5 -> V_11 [ V_15 ] . V_9 = NULL ;
F_4 ( V_5 -> V_6 . V_7 , L_4 ,
V_15 , V_9 -> V_16 ) ;
break;
}
return V_26 ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
const struct V_29 * V_30 ;
const struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 , V_20 , V_36 ;
if ( ! V_28 -> V_7 . V_37 )
return - V_38 ;
V_30 = F_15 ( V_39 , V_28 -> V_7 . V_37 ) ;
V_32 = ( const struct V_31 * ) V_30 -> V_3 ;
V_5 = F_16 ( & V_28 -> V_7 , sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 )
return - V_41 ;
V_5 -> V_11 = F_17 ( & V_28 -> V_7 , V_32 -> V_18 ,
sizeof( * V_5 -> V_11 ) , V_40 ) ;
if ( ! V_5 -> V_11 )
return - V_41 ;
V_5 -> V_6 . V_11 = F_17 ( & V_28 -> V_7 , V_32 -> V_18 ,
sizeof( * V_5 -> V_6 . V_11 ) , V_40 ) ;
if ( ! V_5 -> V_6 . V_11 )
return - V_41 ;
F_18 ( V_28 , V_5 ) ;
V_5 -> V_6 . V_7 = & V_28 -> V_7 ;
V_5 -> V_6 . V_18 = V_32 -> V_18 ;
V_5 -> V_6 . V_42 = & V_43 ;
V_5 -> V_6 . V_44 = true ;
V_34 = F_19 ( V_28 , V_45 , 0 ) ;
if ( ! V_34 )
return - V_38 ;
V_5 -> V_17 = F_20 ( & V_28 -> V_7 , V_34 ) ;
if ( F_21 ( V_5 -> V_17 ) )
return F_22 ( V_5 -> V_17 ) ;
V_5 -> V_14 = ( V_46 ) F_23 ( V_34 ) / ( V_32 -> V_18 * 2 ) ;
V_5 -> V_47 = F_24 ( & V_28 -> V_7 , L_5 ) ;
if ( F_21 ( V_5 -> V_47 ) ) {
V_35 = F_22 ( V_5 -> V_47 ) ;
F_3 ( & V_28 -> V_7 , L_6 ,
V_35 ) ;
return V_35 ;
}
V_35 = F_25 ( V_5 -> V_47 ) ;
if ( V_35 ) {
F_3 ( & V_28 -> V_7 , L_7 , V_35 ) ;
return V_35 ;
}
for ( V_36 = 0 ; V_36 < V_5 -> V_6 . V_18 ; V_36 ++ ) {
V_20 = F_26 ( V_28 , V_36 ) ;
if ( V_20 < 0 )
return V_20 ;
V_35 = F_27 ( & V_28 -> V_7 , V_20 ,
F_10 ,
F_12 , V_48 ,
F_28 ( & V_28 -> V_7 ) , V_5 ) ;
if ( V_35 < 0 )
return V_35 ;
V_5 -> V_11 [ V_36 ] . V_15 = V_36 ;
V_5 -> V_11 [ V_36 ] . V_20 = V_20 ;
V_5 -> V_11 [ V_36 ] . V_5 = V_5 ;
V_5 -> V_11 [ V_36 ] . V_9 = NULL ;
}
V_35 = F_29 ( & V_5 -> V_6 ) ;
if ( V_35 < 0 )
F_3 ( & V_28 -> V_7 , L_8 , V_35 ) ;
return V_35 ;
}
static int F_30 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = F_31 ( V_28 ) ;
if ( ! V_5 )
return - V_12 ;
F_32 ( & V_5 -> V_6 ) ;
return 0 ;
}
