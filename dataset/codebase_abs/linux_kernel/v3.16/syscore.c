void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
int F_7 ( void )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
F_8 ( F_9 ( L_1 ) , 0 , true ) ;
F_10 ( L_2 ) ;
V_6 = F_11 () ;
if ( V_6 )
return V_6 ;
F_12 ( ! F_13 () ,
L_3 ) ;
F_14 (ops, &syscore_ops_list, node)
if ( V_2 -> V_7 ) {
if ( V_8 )
F_15 ( L_4 , V_2 -> V_7 ) ;
V_6 = V_2 -> V_7 () ;
if ( V_6 )
goto V_9;
F_12 ( ! F_13 () ,
L_5 , V_2 -> V_7 ) ;
}
F_8 ( F_9 ( L_1 ) , 0 , false ) ;
return 0 ;
V_9:
F_16 ( L_6 , V_2 -> V_7 ) ;
F_17 (ops, &syscore_ops_list, node)
if ( V_2 -> V_10 )
V_2 -> V_10 () ;
return V_6 ;
}
void F_18 ( void )
{
struct V_1 * V_2 ;
F_8 ( F_9 ( L_7 ) , 0 , true ) ;
F_12 ( ! F_13 () ,
L_8 ) ;
F_19 (ops, &syscore_ops_list, node)
if ( V_2 -> V_10 ) {
if ( V_8 )
F_15 ( L_4 , V_2 -> V_10 ) ;
V_2 -> V_10 () ;
F_12 ( ! F_13 () ,
L_5 , V_2 -> V_10 ) ;
}
F_8 ( F_9 ( L_7 ) , 0 , false ) ;
}
void F_20 ( void )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_14 (ops, &syscore_ops_list, node)
if ( V_2 -> V_11 ) {
if ( V_8 )
F_15 ( L_4 , V_2 -> V_11 ) ;
V_2 -> V_11 () ;
}
F_4 ( & V_3 ) ;
}
