static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 * V_5 )
{
if ( V_2 -> V_6 [ 0 ] - 'A' + 0xA != V_4 -> args [ 2 ] )
return - V_7 ;
return F_2 ( V_2 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
const struct V_12 * V_13 ;
const struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
void T_2 * V_20 ;
int V_21 ;
int V_22 ;
V_19 = F_4 ( V_9 , V_23 , 0 ) ;
V_20 = F_5 ( V_11 , V_19 ) ;
if ( ! V_20 )
return - V_24 ;
V_15 = F_6 ( V_25 , V_11 -> V_26 ) ;
if ( ! V_15 )
return - V_7 ;
V_13 = V_15 -> V_27 ;
V_17 = F_7 ( V_11 , sizeof( * V_17 ) * V_13 -> V_28 , V_29 ) ;
if ( ! V_17 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < V_13 -> V_28 ; V_22 ++ ) {
struct V_16 * V_30 = & V_17 [ V_22 ] ;
const struct V_31 * V_32 = & V_13 -> V_33 [ V_22 ] ;
V_21 = F_8 ( V_30 , V_11 , 4 ,
V_20 + V_32 -> V_34 ,
V_20 + V_32 -> V_35 ,
NULL ,
V_20 + V_32 -> V_36 ,
NULL ,
V_37 ) ;
if ( V_21 )
return V_21 ;
V_30 -> V_2 . V_38 = V_32 -> V_38 ;
V_30 -> V_2 . V_6 = V_32 -> V_6 ;
V_30 -> V_2 . V_26 = V_11 -> V_26 ;
V_30 -> V_2 . V_39 = 3 ;
V_30 -> V_2 . V_40 = F_1 ;
V_21 = F_9 ( & V_30 -> V_2 ) ;
if ( V_21 )
F_10 ( V_11 , L_1 ,
V_30 -> V_2 . V_6 ) ;
}
return 0 ;
}
static int T_3 F_11 ( void )
{
return F_12 ( & V_41 ) ;
}
