struct V_1 * F_1 ( void )
{
return & V_2 ;
}
static void F_2 ( struct V_3 * V_4 )
{
F_3 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = NULL ;
}
void F_4 ( struct V_3 * V_4 )
{
if ( V_4 ) {
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
}
}
bool F_5 ( struct V_3 * * V_8 , struct V_9 * V_10 )
{
enum V_11 type = V_12 ;
struct V_3 * V_13 ;
if ( F_6 ( ! V_10 -> V_14 ) )
return false ;
V_13 = F_7 ( V_13 ) ;
if ( ! V_13 ) {
F_8 ( L_1 ) ;
return false ;
}
V_13 -> V_6 = 0 ;
V_13 -> V_7 = V_10 ;
V_13 -> V_5 = F_7 ( V_13 -> V_5 ) ;
if ( ! V_13 -> V_5 ) {
F_8 ( L_2 ) ;
F_3 ( V_13 ) ;
return false ;
}
if ( V_15 == V_16 )
type = V_17 ;
F_9 ( V_13 -> V_5 , V_10 , type ) ;
* V_8 = V_13 ;
return true ;
}
long F_10 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
if ( V_4 -> V_6 != 0 ) {
F_11 ( L_3 ,
V_4 -> V_6 ) ;
return - V_20 ;
}
V_4 -> V_6 = V_19 -> V_6 ;
V_4 -> V_5 -> V_21 = & V_19 -> V_21 ;
V_4 -> V_5 -> V_22 ( V_4 -> V_5 ) ;
return 0 ;
}
long F_12 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
if ( V_4 -> V_6 != V_19 -> V_6 ) {
F_11 ( L_4 ,
V_19 -> V_6 ) ;
return - V_23 ;
}
V_4 -> V_5 -> V_24 ( V_4 -> V_5 ) ;
V_4 -> V_6 = 0 ;
return 0 ;
}
long F_13 ( struct V_3 * V_4 ,
struct V_25 * V_26 )
{
if ( V_4 -> V_6 != V_26 -> V_27 -> V_6 ) {
F_11 ( L_5 ,
V_26 -> V_27 -> V_6 ) ;
return - V_23 ;
}
return ( long ) V_4 -> V_5 -> V_28 ( V_4 -> V_5 , V_26 ) ;
}
long F_14 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
if ( V_4 -> V_6 != V_30 -> V_27 -> V_6 ) {
F_11 ( L_5 ,
V_30 -> V_27 -> V_6 ) ;
return - V_23 ;
}
return ( long ) V_4 -> V_5 -> V_31 ( V_4 -> V_5 ,
V_30 ) ;
}
