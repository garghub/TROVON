void F_1 ( struct V_1 * V_1 )
{
F_2 ( 3 , NULL , L_1 , V_1 ) ;
F_3 ( & V_2 ) ;
F_4 ( & V_1 -> V_3 , & V_4 ) ;
F_5 ( & V_2 ) ;
F_6 ( 3 , NULL , L_1 , V_1 ) ;
}
struct V_1 * F_7 (
struct V_5 * V_6 , int V_7 )
{
struct V_1 * V_1 = NULL ;
F_2 ( 3 , NULL , L_2 , V_6 , V_7 ) ;
F_3 ( & V_2 ) ;
F_8 (wimax_dev, &wimax_id_table, id_table_node) {
if ( V_1 -> V_8 -> V_7 == V_7 ) {
F_9 ( V_1 -> V_8 ) ;
goto V_9;
}
}
V_1 = NULL ;
F_10 ( 1 , NULL , L_3 ,
V_7 ) ;
V_9:
F_5 ( & V_2 ) ;
F_6 ( 3 , NULL , L_4 ,
V_6 , V_7 , V_1 ) ;
return V_1 ;
}
void F_11 ( struct V_1 * V_1 )
{
F_3 ( & V_2 ) ;
F_12 ( & V_1 -> V_3 ) ;
F_5 ( & V_2 ) ;
}
void F_13 ( void )
{
struct V_1 * V_1 ;
#ifndef F_14
return;
#endif
F_3 ( & V_2 ) ;
F_8 (wimax_dev, &wimax_id_table, id_table_node) {
F_15 ( L_5 ,
V_10 , V_1 , V_1 -> V_8 -> V_7 ) ;
F_16 ( 1 ) ;
}
F_5 ( & V_2 ) ;
}
