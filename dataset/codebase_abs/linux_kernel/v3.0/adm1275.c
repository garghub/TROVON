static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
int V_6 ;
struct V_7 * V_8 ;
if ( ! F_2 ( V_2 -> V_9 ,
V_10 ) )
return - V_11 ;
V_8 = F_3 ( sizeof( struct V_7 ) , V_12 ) ;
if ( ! V_8 )
return - V_13 ;
V_5 = F_4 ( V_2 , V_14 ) ;
if ( V_5 < 0 ) {
V_6 = V_5 ;
goto V_15;
}
V_8 -> V_16 = 1 ;
V_8 -> V_17 [ V_18 ] = true ;
V_8 -> V_17 [ V_19 ] = true ;
V_8 -> V_17 [ V_20 ] = true ;
V_8 -> V_21 [ V_20 ] = 807 ;
V_8 -> V_22 [ V_20 ] = 20475 ;
V_8 -> V_23 [ V_20 ] = - 1 ;
V_8 -> V_24 [ 0 ] = V_25 | V_26 ;
if ( V_5 & V_27 ) {
V_8 -> V_21 [ V_18 ] = 19199 ;
V_8 -> V_22 [ V_18 ] = 0 ;
V_8 -> V_23 [ V_18 ] = - 2 ;
V_8 -> V_21 [ V_19 ] = 19199 ;
V_8 -> V_22 [ V_19 ] = 0 ;
V_8 -> V_23 [ V_19 ] = - 2 ;
} else {
V_8 -> V_21 [ V_18 ] = 6720 ;
V_8 -> V_22 [ V_18 ] = 0 ;
V_8 -> V_23 [ V_18 ] = - 1 ;
V_8 -> V_21 [ V_19 ] = 6720 ;
V_8 -> V_22 [ V_19 ] = 0 ;
V_8 -> V_23 [ V_19 ] = - 1 ;
}
if ( V_5 & V_28 )
V_8 -> V_24 [ 0 ] |= V_29 | V_30 ;
else
V_8 -> V_24 [ 0 ] |= V_31 | V_32 ;
V_6 = F_5 ( V_2 , V_4 , V_8 ) ;
if ( V_6 )
goto V_15;
return 0 ;
V_15:
F_6 ( V_8 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_8 ( V_2 ) ;
int V_6 ;
V_6 = F_9 ( V_2 ) ;
F_6 ( V_8 ) ;
return V_6 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_33 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_33 ) ;
}
