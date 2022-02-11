static void T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
struct V_1 * V_6 , * V_7 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_6 = & V_2 [ V_4 ] ;
for ( V_5 = 0 ; V_5 < F_2 ( V_8 ) ; V_5 ++ ) {
V_7 = & V_8 [ V_5 ] ;
if ( V_6 -> V_9 == V_7 -> V_9 ) {
* V_7 = * V_6 ;
break;
}
}
}
}
void T_1 F_3 ( void )
{
if ( ! F_4 ( L_1 ) )
F_5 ( V_10 ,
F_2 ( V_10 ) ) ;
F_6 ( V_8 , F_2 ( V_8 ) ) ;
F_7 ( V_11 ,
F_2 ( V_11 ) ) ;
F_8 ( V_12 , F_2 ( V_12 ) ) ;
}
void T_1 F_9 ( void )
{
F_3 () ;
}
void T_1 F_10 ( void )
{
F_1 ( V_13 , F_2 ( V_13 ) ) ;
F_3 () ;
}
