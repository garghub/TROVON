static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
int V_6 = F_4 ( V_2 , V_5 ) ;
return F_5 ( V_6 , V_4 -> V_7 -> V_8 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_7 ( V_10 -> V_12 . V_13 ) ;
struct V_14 * V_15 = F_8 ( V_11 -> V_12 ) ;
struct V_16 V_17 = { } ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_18 ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
int V_21 ;
int V_22 ;
if ( ! V_15 ) {
F_9 ( & V_10 -> V_12 , L_1 ) ;
return - V_23 ;
}
V_18 = F_10 ( & V_10 -> V_12 , V_24 *
sizeof( struct V_3 ) , V_25 ) ;
if ( ! V_18 )
return - V_26 ;
for ( V_22 = 0 ; V_22 < V_24 ; ++ V_22 ) {
V_4 = & V_18 [ V_22 ] ;
V_20 = & V_27 [ V_22 ] ;
V_4 -> V_7 = V_20 ;
if ( V_20 -> V_28 == V_29 )
goto V_30;
V_21 = F_11 ( V_11 -> V_12 ,
V_20 -> V_28 ,
V_15 -> V_31 [ V_22 ] ,
V_15 -> V_32 [ V_22 ] ) ;
if ( V_21 < 0 )
F_12 ( & V_10 -> V_12 ,
L_2 , V_22 ) ;
V_30:
V_17 . V_12 = & V_10 -> V_12 ;
V_17 . V_33 = V_15 -> V_34 [ V_22 ] ;
V_17 . V_35 = V_4 ;
V_17 . V_36 = V_11 -> V_36 ;
V_2 = F_13 ( & V_10 -> V_12 , & V_20 -> V_37 , & V_17 ) ;
if ( F_14 ( V_2 ) ) {
F_9 ( & V_10 -> V_12 , L_3 ,
V_20 -> V_37 . V_38 ) ;
return F_15 ( V_2 ) ;
}
V_4 -> V_2 = V_2 ;
}
F_16 ( V_10 , V_18 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_39 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_39 ) ;
}
