void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 )
{
if ( F_2 ( V_3 ) ) {
V_2 -> V_6 = NULL ;
return;
}
V_2 -> V_6 = F_3 ( V_3 ) ;
if ( ! V_2 -> V_6 ) {
F_4 ( L_1 ,
V_3 ) ;
return;
}
V_2 -> V_7 = V_5 ;
V_2 -> V_4 = V_4 ;
F_5 ( V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_8 , & V_2 -> V_6 -> V_9 ) ;
F_7 ( V_2 -> V_6 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 )
return;
F_5 ( V_2 -> V_6 ) ;
F_9 ( & V_2 -> V_8 ) ;
F_7 ( V_2 -> V_6 ) ;
}
void F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_12 , * V_13 ;
F_11 (ns, safe, nsub_list, nodesub_list) {
if ( V_12 -> V_7 ) {
V_12 -> V_7 ( V_12 -> V_4 ) ;
V_12 -> V_7 = NULL ;
}
}
}
