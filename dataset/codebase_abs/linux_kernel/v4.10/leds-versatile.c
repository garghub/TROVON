static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
T_1 V_7 = F_3 ( V_6 -> V_8 ) ;
if ( V_4 != V_9 )
V_7 |= V_6 -> V_10 ;
else
V_7 &= ~ V_6 -> V_10 ;
F_4 ( V_7 , V_6 -> V_8 ) ;
}
static enum V_3 F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
T_1 V_7 = F_3 ( V_6 -> V_8 ) ;
return ( V_7 & V_6 -> V_10 ) ? V_11 : V_9 ;
}
static int F_6 ( struct V_12 * V_13 )
{
int V_14 ;
struct V_15 * V_16 ;
void T_2 * V_8 ;
V_16 = F_7 ( V_13 , V_17 , 0 ) ;
V_8 = F_8 ( & V_13 -> V_13 , V_16 ) ;
if ( F_9 ( V_8 ) )
return F_10 ( V_8 ) ;
F_4 ( 0 , V_8 ) ;
for ( V_14 = 0 ; V_14 < F_11 ( V_18 ) ; V_14 ++ ) {
struct V_5 * V_6 ;
V_6 = F_12 ( sizeof( * V_6 ) , V_19 ) ;
if ( ! V_6 )
break;
V_6 -> V_8 = V_8 ;
V_6 -> V_2 . V_20 = V_18 [ V_14 ] . V_20 ;
V_6 -> V_2 . V_21 = F_1 ;
V_6 -> V_2 . V_22 = F_5 ;
V_6 -> V_2 . V_23 = V_18 [ V_14 ] . V_24 ;
V_6 -> V_10 = F_13 ( V_14 ) ;
if ( F_14 ( NULL , & V_6 -> V_2 ) < 0 ) {
F_15 ( V_6 ) ;
break;
}
}
return 0 ;
}
