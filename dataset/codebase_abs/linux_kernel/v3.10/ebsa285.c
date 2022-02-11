static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
if ( V_4 != V_7 )
* V_8 |= V_6 -> V_9 ;
else
* V_8 &= ~ V_6 -> V_9 ;
}
static enum V_3 F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
return ( * V_8 & V_6 -> V_9 ) ? V_10 : V_7 ;
}
static int T_1 F_4 ( void )
{
int V_11 ;
if ( F_5 () )
return - V_12 ;
* V_8 |= V_13 | V_14 | V_15 ;
for ( V_11 = 0 ; V_11 < F_6 ( V_16 ) ; V_11 ++ ) {
struct V_5 * V_6 ;
V_6 = F_7 ( sizeof( * V_6 ) , V_17 ) ;
if ( ! V_6 )
break;
V_6 -> V_2 . V_18 = V_16 [ V_11 ] . V_18 ;
V_6 -> V_2 . V_19 = F_1 ;
V_6 -> V_2 . V_20 = F_3 ;
V_6 -> V_2 . V_21 = V_16 [ V_11 ] . V_22 ;
V_6 -> V_9 = F_8 ( V_11 ) ;
if ( F_9 ( NULL , & V_6 -> V_2 ) < 0 ) {
F_10 ( V_6 ) ;
break;
}
}
return 0 ;
}
