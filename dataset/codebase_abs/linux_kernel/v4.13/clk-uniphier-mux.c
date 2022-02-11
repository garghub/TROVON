static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_6 , V_5 -> V_7 , V_5 -> V_8 [ V_3 ] ,
V_5 -> V_9 [ V_3 ] ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_10 = F_5 ( V_2 ) ;
int V_11 ;
unsigned int V_12 ;
T_1 V_13 ;
V_11 = F_6 ( V_5 -> V_6 , V_5 -> V_7 , & V_12 ) ;
if ( V_11 )
return V_11 ;
for ( V_13 = 0 ; V_13 < V_10 ; V_13 ++ )
if ( ( V_5 -> V_8 [ V_13 ] & V_12 ) == V_5 -> V_9 [ V_13 ] )
return V_13 ;
return - V_14 ;
}
struct V_1 * F_7 ( struct V_15 * V_16 ,
struct V_6 * V_6 ,
const char * V_17 ,
const struct V_18 * V_19 )
{
struct V_4 * V_5 ;
struct V_20 V_21 ;
int V_11 ;
V_5 = F_8 ( V_16 , sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return F_9 ( - V_23 ) ;
V_21 . V_17 = V_17 ;
V_21 . V_24 = & V_25 ;
V_21 . V_26 = V_27 ;
V_21 . V_28 = V_19 -> V_28 ;
V_21 . V_10 = V_19 -> V_10 ,
V_5 -> V_6 = V_6 ;
V_5 -> V_7 = V_19 -> V_7 ;
V_5 -> V_8 = V_19 -> V_8 ;
V_5 -> V_9 = V_19 -> V_9 ;
V_5 -> V_2 . V_21 = & V_21 ;
V_11 = F_10 ( V_16 , & V_5 -> V_2 ) ;
if ( V_11 )
return F_9 ( V_11 ) ;
return & V_5 -> V_2 ;
}
