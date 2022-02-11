static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
enum V_5 V_6 ;
if ( V_3 )
V_6 = V_7 ;
else
V_6 = V_8 ;
V_4 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_6 ) ;
if ( V_4 )
return V_4 ;
return ! ( V_6 == V_2 -> V_9 -> V_12 ( V_2 -> V_11 ) ) ;
}
static int F_2 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
return F_1 ( V_2 , true ) ;
}
static int F_4 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
return F_1 ( V_2 , false ) ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_15 -> V_17 ;
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_21 ;
struct V_22 * V_23 ;
struct V_13 * * V_24 ;
struct V_25 * V_25 ;
int V_4 , V_26 , V_27 ;
V_25 = F_6 () ;
if ( ! V_25 )
return - V_28 ;
if ( ! V_19 ) {
F_7 ( V_17 , L_1 ) ;
return - V_29 ;
}
if ( ! V_25 -> V_10 ||
! V_25 -> V_12 ) {
F_7 ( V_17 , L_2 ) ;
return - V_29 ;
}
V_4 = F_8 ( V_19 , L_3 , & V_26 ) ;
if ( V_4 ) {
F_7 ( V_17 , L_4 ) ;
return - V_30 ;
}
V_21 = F_9 ( V_17 , V_26 , sizeof( * V_21 ) , V_31 ) ;
if ( ! V_21 )
return - V_32 ;
V_23 = F_10 ( V_17 , sizeof( * V_23 ) , V_31 ) ;
if ( ! V_23 )
return - V_32 ;
V_24 = F_9 ( V_17 , V_26 , sizeof( * V_24 ) , V_31 ) ;
if ( ! V_24 )
return - V_32 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ , V_21 ++ ) {
V_24 [ V_27 ] = & V_21 -> V_33 ;
V_21 -> V_11 = V_27 ;
V_21 -> V_9 = V_25 ;
sprintf ( V_21 -> V_34 , L_5 , V_19 -> V_34 , V_27 ) ;
V_21 -> V_33 . V_34 = V_21 -> V_34 ;
V_21 -> V_33 . V_35 = F_4 ;
V_21 -> V_33 . V_3 = F_2 ;
F_11 ( & V_21 -> V_33 , NULL , true ) ;
}
V_23 -> V_24 = V_24 ;
V_23 -> V_26 = V_26 ;
F_12 ( V_19 , V_23 ) ;
return 0 ;
}
