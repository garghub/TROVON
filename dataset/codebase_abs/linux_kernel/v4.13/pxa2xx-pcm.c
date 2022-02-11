static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_6 -> V_10 , V_2 ) ;
if ( ! V_9 )
return 0 ;
return F_3 ( V_2 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 -> V_11 ;
struct V_13 * V_14 = V_6 -> V_14 ;
int V_15 ;
V_15 = F_7 ( V_12 -> V_16 , F_8 ( 32 ) ) ;
if ( V_15 )
return V_15 ;
if ( V_14 -> V_17 [ V_18 ] . V_2 ) {
V_15 = F_9 ( V_14 ,
V_18 ) ;
if ( V_15 )
goto V_19;
}
if ( V_14 -> V_17 [ V_20 ] . V_2 ) {
V_15 = F_9 ( V_14 ,
V_20 ) ;
if ( V_15 )
goto V_19;
}
V_19:
return V_15 ;
}
static int F_10 ( struct V_21 * V_22 )
{
return F_11 ( & V_22 -> V_16 , & V_23 ) ;
}
