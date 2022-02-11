struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 )
return NULL ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 ) ;
F_12 ( V_4 ) ;
return V_4 ;
}
void F_13 ( struct V_1 * V_4 )
{
struct V_7 * V_8 , * V_9 ;
if ( ! V_4 )
return;
F_14 (pos, n, &bus->drivers, chain) {
if ( V_8 -> V_10 )
V_8 -> V_10 ( V_8 ) ;
F_15 ( & V_8 -> V_11 ) ;
F_16 ( V_8 -> V_12 ) ;
F_16 ( V_8 ) ;
}
F_16 ( V_4 ) ;
}
const struct V_13 * F_17 ( struct V_1 * V_4 )
{
struct V_7 * V_8 ;
const struct V_13 * V_14 = NULL ;
if ( ! V_4 )
return NULL ;
F_18 (pos, &bus->drivers, chain) {
if ( V_8 -> V_15 )
V_14 = V_8 -> V_15 ( V_8 ) ;
}
return V_14 ;
}
