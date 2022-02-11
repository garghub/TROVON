static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 (p, &br->port_list, list) {
if ( F_3 ( V_4 , V_6 -> V_4 ) )
return V_6 -> V_7 ;
}
return ++ V_2 -> V_7 ;
}
int F_4 ( struct V_5 * V_6 )
{
struct V_8 V_9 = {
. V_10 = V_6 -> V_4 ,
. V_11 = V_12 ,
} ;
int V_13 ;
F_5 () ;
V_13 = F_6 ( V_6 -> V_4 , & V_9 ) ;
if ( V_13 ) {
if ( V_13 == - V_14 )
return 0 ;
return V_13 ;
}
V_6 -> V_7 = F_1 ( V_6 -> V_2 , V_6 -> V_4 ) ;
return 0 ;
}
void F_7 ( const struct V_5 * V_6 ,
struct V_15 * V_16 )
{
if ( V_16 -> V_7 && ! F_8 ( ! V_6 -> V_7 ) )
F_9 ( V_16 ) -> V_7 = V_6 -> V_7 ;
}
bool F_10 ( const struct V_5 * V_6 ,
const struct V_15 * V_16 )
{
return ! V_16 -> V_7 ||
F_9 ( V_16 ) -> V_7 != V_6 -> V_7 ;
}
