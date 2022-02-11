struct V_1 *
F_1 ( struct V_2 * V_3 , enum V_4 type , int V_5 )
{
struct V_1 * V_6 ;
F_2 (ior, &disp->ior, head) {
if ( V_6 -> type == type && ( V_5 < 0 || V_6 -> V_5 == V_5 ) )
return V_6 ;
}
return NULL ;
}
void
F_3 ( struct V_1 * * V_7 )
{
struct V_1 * V_6 = * V_7 ;
if ( V_6 ) {
F_4 ( V_6 , L_1 ) ;
F_5 ( & V_6 -> V_8 ) ;
F_6 ( * V_7 ) ;
* V_7 = NULL ;
}
}
int
F_7 ( const struct V_9 * V_10 , struct V_2 * V_3 ,
enum V_4 type , int V_5 )
{
struct V_1 * V_6 ;
if ( ! ( V_6 = F_8 ( sizeof( * V_6 ) , V_11 ) ) )
return - V_12 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_3 = V_3 ;
V_6 -> type = type ;
V_6 -> V_5 = V_5 ;
snprintf ( V_6 -> V_13 , sizeof( V_6 -> V_13 ) , L_2 ,
V_14 [ V_6 -> type ] , V_6 -> V_5 ) ;
F_9 ( & V_6 -> V_8 , & V_3 -> V_6 ) ;
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
