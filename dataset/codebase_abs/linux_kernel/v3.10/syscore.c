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
F_8 ( L_1 ) ;
V_6 = F_9 () ;
if ( V_6 )
return V_6 ;
F_10 ( ! F_11 () ,
L_2 ) ;
F_12 (ops, &syscore_ops_list, node)
if ( V_2 -> V_7 ) {
if ( V_8 )
F_13 ( L_3 , V_2 -> V_7 ) ;
V_6 = V_2 -> V_7 () ;
if ( V_6 )
goto V_9;
F_10 ( ! F_11 () ,
L_4 , V_2 -> V_7 ) ;
}
return 0 ;
V_9:
F_14 ( L_5 , V_2 -> V_7 ) ;
F_15 (ops, &syscore_ops_list, node)
if ( V_2 -> V_10 )
V_2 -> V_10 () ;
return V_6 ;
}
void F_16 ( void )
{
struct V_1 * V_2 ;
F_10 ( ! F_11 () ,
L_6 ) ;
F_17 (ops, &syscore_ops_list, node)
if ( V_2 -> V_10 ) {
if ( V_8 )
F_13 ( L_3 , V_2 -> V_10 ) ;
V_2 -> V_10 () ;
F_10 ( ! F_11 () ,
L_4 , V_2 -> V_10 ) ;
}
}
void F_18 ( void )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_12 (ops, &syscore_ops_list, node)
if ( V_2 -> V_11 ) {
if ( V_8 )
F_13 ( L_3 , V_2 -> V_11 ) ;
V_2 -> V_11 () ;
}
F_4 ( & V_3 ) ;
}
