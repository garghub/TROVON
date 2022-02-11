struct V_1 * F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_4 = F_2 ( sizeof( * V_4 ) ) ;
if ( V_4 ) {
struct V_5 * V_6 ;
V_6 = F_3 ( V_2 , V_3 , sizeof( struct V_7 ) ) ;
if ( ! V_6 ) {
free ( V_4 ) ;
return NULL ;
}
V_4 -> V_6 = V_6 ;
}
return V_4 ;
}
void F_4 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_5 ( V_4 -> V_6 ) ;
free ( V_4 ) ;
}
}
static void F_6 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_6 ) ;
}
void F_8 ( struct V_8 * V_9 )
{
F_6 ( V_9 -> V_4 ) ;
}
int F_9 ( struct V_8 * V_9 , int V_2 , int V_3 )
{
V_9 -> V_4 = F_1 ( V_2 , V_3 ) ;
return V_9 -> V_4 != NULL ? 0 : - V_10 ;
}
void F_10 ( struct V_8 * V_9 )
{
F_4 ( V_9 -> V_4 ) ;
V_9 -> V_4 = NULL ;
}
