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
V_4 -> V_31 = V_11 ;
V_4 -> V_12 = & V_10 -> V_12 ;
if ( V_22 -> V_32 == V_33 )
goto V_34;
V_23 = F_11 ( V_11 -> V_12 ,
V_22 -> V_32 ,
V_15 -> V_35 [ V_24 ] ,
V_15 -> V_36 [ V_24 ] ) ;
if ( V_23 < 0 )
F_12 ( & V_10 -> V_12 ,
L_3 , V_24 ) ;
V_34:
V_19 . V_12 = & V_10 -> V_12 ;
V_19 . V_37 = V_17 ;
V_19 . V_38 = V_4 ;
V_19 . V_39 = V_11 -> V_39 ;
V_2 = F_13 ( & V_22 -> V_40 , & V_19 ) ;
if ( F_14 ( V_2 ) ) {
F_9 ( & V_10 -> V_12 , L_4 ,
V_22 -> V_40 . V_41 ) ;
V_23 = F_15 ( V_2 ) ;
goto V_42;
}
V_4 -> V_2 = V_2 ;
}
F_16 ( V_10 , V_20 ) ;
return 0 ;
V_42:
while ( -- V_24 >= 0 )
F_17 ( V_20 [ V_24 ] . V_2 ) ;
return V_23 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_3 * V_20 = F_19 ( V_10 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_26 ; ++ V_24 )
F_17 ( V_20 [ V_24 ] . V_2 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_43 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_43 ) ;
}
