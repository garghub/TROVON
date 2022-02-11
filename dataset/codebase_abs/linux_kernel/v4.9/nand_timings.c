const struct V_1 * F_1 ( int V_2 )
{
if ( V_2 < 0 || V_2 >= F_2 ( V_3 ) )
return F_3 ( - V_4 ) ;
return & V_3 [ V_2 ] . V_5 . V_6 ;
}
int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
enum V_11 type ,
int V_12 )
{
if ( type != V_13 )
return - V_4 ;
if ( V_12 < 0 || V_12 >= F_2 ( V_3 ) )
return - V_4 ;
* V_10 = V_3 [ V_12 ] ;
return 0 ;
}
const struct V_9 * F_5 ( void )
{
return & V_3 [ 0 ] ;
}
