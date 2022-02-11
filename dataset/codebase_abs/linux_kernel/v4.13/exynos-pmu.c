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
if ( ! V_9 || ! V_9 -> V_8 )
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
struct V_15 * F_6 ( void )
{
struct V_16 * V_17 = F_7 ( NULL ,
V_18 ) ;
if ( V_17 )
return F_8 ( V_17 ) ;
return F_9 ( - V_19 ) ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_24 * V_25 ;
V_25 = F_11 ( V_21 , V_26 , 0 ) ;
V_3 = F_12 ( V_23 , V_25 ) ;
if ( F_13 ( V_3 ) )
return F_14 ( V_3 ) ;
V_9 = F_15 ( & V_21 -> V_23 ,
sizeof( struct V_27 ) ,
V_28 ) ;
if ( ! V_9 )
return - V_29 ;
V_9 -> V_23 = V_23 ;
V_9 -> V_8 = F_16 ( V_23 ) ;
if ( V_9 -> V_8 && V_9 -> V_8 -> V_30 )
V_9 -> V_8 -> V_30 () ;
F_17 ( V_21 , V_9 ) ;
F_18 ( V_23 , L_1 ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_31 ) ;
}
