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
struct V_20 * V_21 = V_8 -> V_11 . V_22 ;
struct V_23 V_24 = { } ;
struct V_3 * V_4 ;
int V_25 , V_26 , V_9 = - V_27 ;
V_4 = F_10 ( & V_8 -> V_11 , sizeof( struct V_3 ) +
sizeof( struct V_1 * ) * ( V_28 + 1 ) ,
V_29 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_8 = V_8 ;
if ( ! V_21 -> V_30 )
return - V_31 ;
V_4 -> V_32 = V_33 / 1000 * V_21 -> V_30 / 1000 ;
V_4 -> V_34 = V_35 / 1000 * V_21 -> V_30 / 1000 ;
V_4 -> V_5 = 24 ;
V_4 -> V_13 = 0 ;
V_2 = V_4 -> V_2 ;
for ( V_25 = 0 ; V_25 < V_21 -> V_36 && V_25 <= V_28 ; V_25 ++ ) {
V_26 = V_21 -> V_37 [ V_25 ] . V_26 ;
if ( ! V_21 -> V_37 [ V_25 ] . V_22 )
continue;
if ( V_26 < V_38 || V_26 > V_28 ) {
F_11 ( & V_8 -> V_11 , L_3 , V_26 ) ;
goto V_39;
}
if ( V_26 == V_38 ) {
V_40 [ V_26 ] . V_32 = V_4 -> V_32 ;
V_40 [ V_26 ] . V_41 =
( V_4 -> V_34 - V_4 -> V_32 ) /
V_42 ;
}
V_24 . V_11 = & V_8 -> V_11 ;
V_24 . V_43 = V_21 -> V_37 [ V_25 ] . V_22 ;
V_24 . V_44 = V_4 ;
V_2 [ V_25 ] = F_12 ( & V_40 [ V_26 ] , & V_24 ) ;
if ( F_13 ( V_2 [ V_25 ] ) ) {
V_9 = F_14 ( V_2 [ V_25 ] ) ;
F_11 ( & V_8 -> V_11 , L_4 ,
V_40 [ V_26 ] . V_45 ) ;
goto V_39;
}
}
F_15 ( V_8 , V_4 ) ;
F_16 ( & V_8 -> V_11 , L_5 ) ;
return 0 ;
V_39:
while ( -- V_25 >= 0 )
F_17 ( V_2 [ V_25 ] ) ;
return V_9 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_19 ( V_8 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 <= V_28 ; V_25 ++ )
if ( V_4 -> V_2 [ V_25 ] )
F_17 ( V_4 -> V_2 [ V_25 ] ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_46 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_46 ) ;
}
