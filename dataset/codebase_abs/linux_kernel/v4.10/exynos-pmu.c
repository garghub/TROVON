void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
T_1 F_3 ( T_1 V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
void F_5 ( enum V_4 V_5 )
{
unsigned int V_6 ;
const struct V_7 * V_8 ;
if ( ! V_9 )
return;
V_8 = V_9 -> V_8 ;
if ( V_8 -> V_10 )
V_8 -> V_10 ( V_5 ) ;
if ( V_8 -> V_11 ) {
for ( V_6 = 0 ; ( V_8 -> V_11 [ V_6 ] . V_2 != V_12 ) ; V_6 ++ )
F_1 ( V_8 -> V_11 [ V_6 ] . V_1 [ V_5 ] ,
V_8 -> V_11 [ V_6 ] . V_2 ) ;
}
if ( V_8 -> V_13 )
V_8 -> V_13 ( V_5 ) ;
if ( V_8 -> V_14 ) {
for ( V_6 = 0 ; V_8 -> V_14 [ V_6 ] . V_2 != V_12 ; V_6 ++ )
F_1 ( V_8 -> V_14 [ V_6 ] . V_1 [ V_5 ] ,
V_8 -> V_14 [ V_6 ] . V_2 ) ;
}
}
static int F_6 ( struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
struct V_19 * V_20 = & V_16 -> V_20 ;
struct V_21 * V_22 ;
V_22 = F_7 ( V_16 , V_23 , 0 ) ;
V_3 = F_8 ( V_20 , V_22 ) ;
if ( F_9 ( V_3 ) )
return F_10 ( V_3 ) ;
V_9 = F_11 ( & V_16 -> V_20 ,
sizeof( struct V_24 ) ,
V_25 ) ;
if ( ! V_9 ) {
F_12 ( V_20 , L_1 ) ;
return - V_26 ;
}
V_9 -> V_20 = V_20 ;
V_18 = F_13 ( V_27 , V_20 -> V_28 ) ;
V_9 -> V_8 = V_18 -> V_29 ;
if ( V_9 -> V_8 -> V_30 )
V_9 -> V_8 -> V_30 () ;
F_14 ( V_16 , V_9 ) ;
F_15 ( V_20 , L_2 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_31 ) ;
}
