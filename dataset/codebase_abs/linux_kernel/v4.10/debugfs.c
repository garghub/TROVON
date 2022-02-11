bool F_1 ( void )
{
return true ;
}
static int F_2 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
* V_2 = V_4 -> V_5 . V_6 ;
return 0 ;
}
static int F_3 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
* V_2 = V_4 -> V_5 . V_7 ;
return 0 ;
}
static int F_4 ( void * V_1 , T_1 * V_2 )
{
* V_2 = V_8 ;
return 0 ;
}
int F_5 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( L_1 , 0444 ,
V_4 -> V_11 ,
V_4 , & V_12 ) ;
if ( ! V_10 )
return - V_13 ;
if ( V_14 ) {
V_10 = F_6 ( L_2 , 0444 ,
V_4 -> V_11 ,
V_4 , & V_15 ) ;
if ( ! V_10 )
return - V_13 ;
V_10 = F_6 ( L_3 , 0444 ,
V_4 -> V_11 ,
V_4 , & V_16 ) ;
if ( ! V_10 )
return - V_13 ;
}
return 0 ;
}
