static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_8 ;
F_3 ( & V_7 -> V_9 , L_1 ,
F_4 ( V_2 , V_3 ) / 1000 ) ;
V_8 = V_10 | ( T_1 ) V_3 ;
return F_5 ( V_7 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_11 ;
F_3 ( & V_7 -> V_9 , L_2 ,
V_2 -> V_12 -> V_13 [ V_3 ] / 1000 ) ;
V_11 = V_14 | ( T_1 ) V_3 ;
return F_5 ( V_7 , V_11 ) ;
}
static int T_2 F_7 ( struct V_6 * V_7 ,
const struct V_15 * V_16 )
{
struct V_1 * * V_2 ;
struct V_17 * V_18 = V_7 -> V_9 . V_19 ;
struct V_20 V_21 = { } ;
struct V_4 * V_5 ;
int V_22 , V_23 , V_24 = - V_25 ;
V_5 = F_8 ( & V_7 -> V_9 , sizeof( struct V_4 ) +
sizeof( struct V_1 * ) * ( V_26 + 1 ) ,
V_27 ) ;
if ( ! V_5 )
return - V_25 ;
V_5 -> V_7 = V_7 ;
if ( ! V_18 -> V_28 )
return - V_29 ;
V_5 -> V_30 = V_31 / 1000 * V_18 -> V_28 / 1000 ;
V_5 -> V_32 = V_33 / 1000 * V_18 -> V_28 / 1000 ;
V_2 = V_5 -> V_2 ;
for ( V_22 = 0 ; V_22 < V_18 -> V_34 && V_22 <= V_26 ; V_22 ++ ) {
V_23 = V_18 -> V_35 [ V_22 ] . V_23 ;
if ( ! V_18 -> V_35 [ V_22 ] . V_19 )
continue;
if ( V_23 < V_36 || V_23 > V_26 ) {
F_9 ( & V_7 -> V_9 , L_3 , V_23 ) ;
goto V_37;
}
if ( V_23 == V_36 ) {
V_38 [ V_23 ] . V_30 = V_5 -> V_30 ;
V_38 [ V_23 ] . V_39 =
( V_5 -> V_32 - V_5 -> V_30 ) /
V_40 ;
}
V_21 . V_9 = & V_7 -> V_9 ;
V_21 . V_41 = V_18 -> V_35 [ V_22 ] . V_19 ;
V_21 . V_42 = V_5 ;
V_2 [ V_22 ] = F_10 ( & V_38 [ V_23 ] , & V_21 ) ;
if ( F_11 ( V_2 [ V_22 ] ) ) {
V_24 = F_12 ( V_2 [ V_22 ] ) ;
F_9 ( & V_7 -> V_9 , L_4 ,
V_38 [ V_23 ] . V_43 ) ;
goto V_37;
}
}
F_13 ( V_7 , V_5 ) ;
F_14 ( & V_7 -> V_9 , L_5 ) ;
return 0 ;
V_37:
while ( -- V_22 >= 0 )
F_15 ( V_2 [ V_22 ] ) ;
return V_24 ;
}
static int T_3 F_16 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = F_17 ( V_7 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 <= V_26 ; V_22 ++ )
if ( V_5 -> V_2 [ V_22 ] )
F_15 ( V_5 -> V_2 [ V_22 ] ) ;
return 0 ;
}
static int T_4 F_18 ( void )
{
return F_19 ( & V_44 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_44 ) ;
}
