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
struct V_16 * V_17 ;
struct V_18 V_19 = { } ;
struct V_3 * V_4 = NULL ;
struct V_3 * V_20 ;
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_23 ;
int V_24 ;
if ( ! V_15 ) {
F_9 ( & V_10 -> V_12 , L_1 ) ;
return - V_25 ;
}
V_20 = F_10 ( & V_10 -> V_12 , V_26 *
sizeof( struct V_3 ) , V_27 ) ;
if ( ! V_20 ) {
F_9 ( & V_10 -> V_12 , L_2 ) ;
return - V_28 ;
}
for ( V_24 = 0 ; V_24 < V_26 ; ++ V_24 ) {
V_17 = V_15 -> V_29 [ V_24 ] ;
if ( ! V_17 )
continue;
V_4 = & V_20 [ V_24 ] ;
V_22 = & V_30 [ V_24 ] ;
V_4 -> V_7 = V_22 ;
if ( V_22 -> V_31 == V_32 )
goto V_33;
V_23 = F_11 ( V_11 -> V_12 ,
V_22 -> V_31 ,
V_15 -> V_34 [ V_24 ] ,
V_15 -> V_35 [ V_24 ] ) ;
if ( V_23 < 0 )
F_12 ( & V_10 -> V_12 ,
L_3 , V_24 ) ;
V_33:
V_19 . V_12 = & V_10 -> V_12 ;
V_19 . V_36 = V_17 ;
V_19 . V_37 = V_4 ;
V_19 . V_38 = V_11 -> V_38 ;
V_2 = F_13 ( & V_10 -> V_12 , & V_22 -> V_39 , & V_19 ) ;
if ( F_14 ( V_2 ) ) {
F_9 ( & V_10 -> V_12 , L_4 ,
V_22 -> V_39 . V_40 ) ;
return F_15 ( V_2 ) ;
}
V_4 -> V_2 = V_2 ;
}
F_16 ( V_10 , V_20 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_41 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_41 ) ;
}
