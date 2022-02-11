static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
if ( V_4 == V_7 )
V_8 |= V_6 -> V_9 ;
else
V_8 &= ~ V_6 -> V_9 ;
F_3 ( V_8 , V_10 ) ;
}
static enum V_3 F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
return V_8 & V_6 -> V_9 ? V_7 : V_11 ;
}
static int T_1 F_5 ( void )
{
int V_12 ;
if ( ! F_6 () )
return - V_13 ;
V_10 = F_7 ( V_14 , V_15 ) ;
if ( ! V_10 )
return - V_16 ;
V_8 = V_17 | V_18 | V_19 ;
F_3 ( V_8 , V_10 ) ;
for ( V_12 = 0 ; V_12 < F_8 ( V_20 ) ; V_12 ++ ) {
struct V_5 * V_6 ;
V_6 = F_9 ( sizeof( * V_6 ) , V_21 ) ;
if ( ! V_6 )
break;
V_6 -> V_2 . V_22 = V_20 [ V_12 ] . V_22 ;
V_6 -> V_2 . V_23 = F_1 ;
V_6 -> V_2 . V_24 = F_4 ;
V_6 -> V_2 . V_25 = V_20 [ V_12 ] . V_26 ;
V_6 -> V_9 = F_10 ( V_12 ) ;
if ( F_11 ( NULL , & V_6 -> V_2 ) < 0 ) {
F_12 ( V_6 ) ;
break;
}
}
return 0 ;
}
