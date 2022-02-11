static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( & V_8 -> V_9 ) ;
if ( V_4 != V_10 )
V_7 |= V_6 -> V_11 ;
else
V_7 &= ~ V_6 -> V_11 ;
F_4 ( V_7 , & V_8 -> V_9 ) ;
}
static enum V_3 F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( & V_8 -> V_9 ) ;
return ( V_7 & V_6 -> V_11 ) ? V_12 : V_10 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_17 ;
V_16 = F_7 ( V_14 , V_18 , 0 ) ;
if ( ! V_16 )
return - V_19 ;
V_8 = F_8 ( V_16 -> V_20 , F_9 ( V_16 ) ) ;
F_4 ( 0xff , & V_8 -> V_9 ) ;
for ( V_17 = 0 ; V_17 < F_10 ( V_21 ) ; V_17 ++ ) {
struct V_5 * V_6 ;
V_6 = F_11 ( sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
break;
V_6 -> V_2 . V_23 = V_21 [ V_17 ] . V_23 ;
V_6 -> V_2 . V_24 = F_1 ;
V_6 -> V_2 . V_25 = F_5 ;
V_6 -> V_2 . V_26 = V_21 [ V_17 ] . V_27 ;
V_6 -> V_11 = F_12 ( V_17 ) ;
if ( F_13 ( NULL , & V_6 -> V_2 ) < 0 ) {
F_14 ( V_6 ) ;
break;
}
}
return 0 ;
}
static int F_15 ( struct V_28 * V_29 )
{
V_30 = F_3 ( & V_8 -> V_9 ) ;
F_4 ( 0xff , & V_8 -> V_9 ) ;
return 0 ;
}
static int F_16 ( struct V_28 * V_29 )
{
F_4 ( ~ V_30 , & V_8 -> V_9 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
if ( F_18 ()
|| F_19 ()
|| F_20 ()
|| F_21 ()
)
return F_22 ( & V_31 ) ;
return 0 ;
}
