void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_2 V_5 )
{
if ( V_3 == V_6 ) {
V_2 -> V_7 = NULL ;
return;
}
V_2 -> V_7 = F_2 ( V_3 ) ;
if ( ! V_2 -> V_7 ) {
F_3 ( L_1 , V_3 ) ;
return;
}
V_2 -> V_8 = V_5 ;
V_2 -> V_4 = V_4 ;
F_4 ( V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_9 , & V_2 -> V_7 -> V_10 ) ;
F_6 ( V_2 -> V_7 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_7 )
return;
F_4 ( V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_9 ) ;
F_6 ( V_2 -> V_7 ) ;
}
void F_9 ( struct V_11 * V_7 )
{
struct V_1 * V_12 ;
F_10 (ns, &node->nsub, nodesub_list) {
if ( V_12 -> V_8 ) {
F_11 ( ( V_13 ) V_12 -> V_8 ,
( unsigned long ) V_12 -> V_4 ) ;
V_12 -> V_8 = NULL ;
}
}
}
