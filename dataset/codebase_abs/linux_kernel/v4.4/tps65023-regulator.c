static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
if ( V_5 < V_6 || V_5 > V_7 )
return - V_8 ;
if ( V_5 != V_4 -> V_9 -> V_10 )
return 0 ;
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = F_3 ( V_2 ) ;
if ( V_5 != V_4 -> V_9 -> V_10 )
return - V_8 ;
return F_6 ( V_2 , V_11 ) ;
}
static int F_7 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 = F_8 ( & V_13 -> V_2 ) ;
struct V_18 V_19 = { } ;
struct V_3 * V_4 ;
int V_20 ;
int error ;
V_4 = F_9 ( & V_13 -> V_2 , sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_4 -> V_9 = (struct V_23 * ) V_15 -> V_9 ;
V_4 -> V_24 = F_10 ( V_13 , & V_25 ) ;
if ( F_11 ( V_4 -> V_24 ) ) {
error = F_12 ( V_4 -> V_24 ) ;
F_13 ( & V_13 -> V_2 , L_1 ,
error ) ;
return error ;
}
V_19 . V_2 = & V_13 -> V_2 ;
V_19 . V_9 = V_4 ;
V_19 . V_24 = V_4 -> V_24 ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ ) {
if ( V_17 )
V_19 . V_17 = & V_17 [ V_20 ] ;
V_4 -> V_27 [ V_20 ] = F_14 ( & V_13 -> V_2 ,
& V_4 -> V_9 -> V_28 [ V_20 ] , & V_19 ) ;
if ( F_11 ( V_4 -> V_27 [ V_20 ] ) ) {
F_13 ( & V_13 -> V_2 , L_2 ,
V_15 -> V_29 ) ;
return F_12 ( V_4 -> V_27 [ V_20 ] ) ;
}
}
F_15 ( V_13 , V_4 ) ;
F_16 ( V_4 -> V_24 , V_30 ,
V_31 ,
V_31 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_32 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_32 ) ;
}
