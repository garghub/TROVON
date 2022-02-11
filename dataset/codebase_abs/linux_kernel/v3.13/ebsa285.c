static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
if ( V_4 == V_7 )
V_8 |= V_6 -> V_9 ;
else
V_8 &= ~ V_6 -> V_9 ;
* V_10 = V_8 ;
}
static enum V_3 F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
return V_8 & V_6 -> V_9 ? V_7 : V_11 ;
}
static int T_1 F_4 ( void )
{
int V_12 ;
if ( ! F_5 () )
return - V_13 ;
V_8 = V_14 | V_15 | V_16 ;
* V_10 = V_8 ;
for ( V_12 = 0 ; V_12 < F_6 ( V_17 ) ; V_12 ++ ) {
struct V_5 * V_6 ;
V_6 = F_7 ( sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
break;
V_6 -> V_2 . V_19 = V_17 [ V_12 ] . V_19 ;
V_6 -> V_2 . V_20 = F_1 ;
V_6 -> V_2 . V_21 = F_3 ;
V_6 -> V_2 . V_22 = V_17 [ V_12 ] . V_23 ;
V_6 -> V_9 = F_8 ( V_12 ) ;
if ( F_9 ( NULL , & V_6 -> V_2 ) < 0 ) {
F_10 ( V_6 ) ;
break;
}
}
return 0 ;
}
