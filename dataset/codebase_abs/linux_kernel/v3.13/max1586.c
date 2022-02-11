static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 ;
T_1 V_10 ;
F_4 ( & V_8 -> V_11 , L_1 ,
F_5 ( V_2 , V_6 ) / 1000 ) ;
V_10 = V_12 | ( T_1 ) V_6 ;
V_9 = F_6 ( V_8 , V_10 ) ;
if ( V_9 )
return V_9 ;
V_4 -> V_5 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_14 ;
int V_9 ;
F_4 ( & V_8 -> V_11 , L_2 ,
V_2 -> V_15 -> V_16 [ V_6 ] / 1000 ) ;
V_14 = V_17 | ( T_1 ) V_6 ;
V_9 = F_6 ( V_8 , V_14 ) ;
if ( V_9 )
return V_9 ;
V_4 -> V_13 = V_6 ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 ,
const struct V_18 * V_19 )
{
struct V_1 * * V_2 ;
struct V_20 * V_21 = F_10 ( & V_8 -> V_11 ) ;
struct V_22 V_23 = { } ;
struct V_3 * V_4 ;
int V_24 , V_25 ;
V_4 = F_11 ( & V_8 -> V_11 , sizeof( struct V_3 ) +
sizeof( struct V_1 * ) * ( V_26 + 1 ) ,
V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_4 -> V_8 = V_8 ;
if ( ! V_21 -> V_29 )
return - V_30 ;
V_4 -> V_31 = V_32 / 1000 * V_21 -> V_29 / 1000 ;
V_4 -> V_33 = V_34 / 1000 * V_21 -> V_29 / 1000 ;
V_4 -> V_5 = 24 ;
V_4 -> V_13 = 0 ;
V_2 = V_4 -> V_2 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_35 && V_24 <= V_26 ; V_24 ++ ) {
V_25 = V_21 -> V_36 [ V_24 ] . V_25 ;
if ( ! V_21 -> V_36 [ V_24 ] . V_37 )
continue;
if ( V_25 < V_38 || V_25 > V_26 ) {
F_12 ( & V_8 -> V_11 , L_3 , V_25 ) ;
return - V_30 ;
}
if ( V_25 == V_38 ) {
V_39 [ V_25 ] . V_31 = V_4 -> V_31 ;
V_39 [ V_25 ] . V_40 =
( V_4 -> V_33 - V_4 -> V_31 ) /
V_41 ;
}
V_23 . V_11 = & V_8 -> V_11 ;
V_23 . V_42 = V_21 -> V_36 [ V_24 ] . V_37 ;
V_23 . V_43 = V_4 ;
V_2 [ V_24 ] = F_13 ( & V_8 -> V_11 ,
& V_39 [ V_25 ] , & V_23 ) ;
if ( F_14 ( V_2 [ V_24 ] ) ) {
F_12 ( & V_8 -> V_11 , L_4 ,
V_39 [ V_25 ] . V_44 ) ;
return F_15 ( V_2 [ V_24 ] ) ;
}
}
F_16 ( V_8 , V_4 ) ;
F_17 ( & V_8 -> V_11 , L_5 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_45 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_45 ) ;
}
