static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 , V_5 ;
V_5 = F_2 ( V_2 -> V_6 -> V_7 ) ;
V_4 = F_2 ( V_2 -> V_6 -> V_8 ) ;
return F_3 ( V_2 -> V_9 -> V_10 , V_4 , V_5 , V_3 ) ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
F_6 ( V_2 -> V_9 -> V_13 , L_1 , V_2 -> V_6 -> V_14 ) ;
return F_1 ( V_2 , true ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
F_6 ( V_2 -> V_9 -> V_13 , L_2 , V_2 -> V_6 -> V_14 ) ;
return F_1 ( V_2 , false ) ;
}
static int F_8 ( struct V_15 * V_9 , int V_16 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_9 -> V_13 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
V_2 -> V_6 = & V_9 -> V_6 -> V_19 [ V_16 ] ;
V_2 -> V_9 = V_9 ;
V_2 -> V_20 . V_14 = V_2 -> V_6 -> V_14 ;
V_2 -> V_20 . V_21 = F_4 ;
V_2 -> V_20 . V_22 = F_7 ;
V_2 -> V_20 . V_23 = V_2 -> V_6 -> V_24 ;
F_10 ( & V_2 -> V_20 , NULL , false ) ;
V_9 -> V_25 . V_19 [ V_16 ] = & V_2 -> V_20 ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 )
{
const struct V_28 * V_29 ;
const struct V_30 * V_31 ;
struct V_15 * V_9 ;
int V_32 , V_33 ;
if ( ! V_27 -> V_13 . V_34 ) {
F_12 ( & V_27 -> V_13 , L_3 ) ;
return - V_35 ;
}
V_29 = F_13 ( V_27 -> V_13 . V_36 -> V_37 , & V_27 -> V_13 ) ;
if ( ! V_29 || ! V_29 -> V_38 ) {
F_12 ( & V_27 -> V_13 , L_4 ) ;
return - V_39 ;
}
V_31 = V_29 -> V_38 ;
V_9 = F_9 ( & V_27 -> V_13 , sizeof( * V_9 ) +
V_31 -> V_40 * sizeof( V_9 -> V_19 [ 0 ] ) ,
V_17 ) ;
if ( ! V_9 )
return - V_18 ;
V_9 -> V_10 = F_14 ( V_27 -> V_13 . V_34 , 0 , L_5 ) ;
if ( F_15 ( V_9 -> V_10 ) ) {
F_12 ( & V_27 -> V_13 , L_6 ) ;
return F_16 ( V_9 -> V_10 ) ;
}
V_9 -> V_13 = & V_27 -> V_13 ;
V_9 -> V_6 = V_31 ;
V_9 -> V_25 . V_19 = V_9 -> V_19 ;
V_9 -> V_25 . V_40 = V_31 -> V_40 ;
for ( V_32 = 0 ; V_32 < V_31 -> V_40 ; V_32 ++ ) {
V_33 = F_8 ( V_9 , V_32 ) ;
if ( V_33 )
return V_33 ;
}
V_33 = F_17 ( V_27 -> V_13 . V_34 , & V_9 -> V_25 ) ;
if ( V_33 ) {
F_12 ( & V_27 -> V_13 , L_7 , V_33 ) ;
return V_33 ;
}
return 0 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_41 ) ;
}
