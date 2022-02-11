static void T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_2 -> V_4 != V_5 ) {
F_2 ( V_6 L_1 , V_2 ) ;
F_3 ( 1 ) ;
return;
}
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_7 , V_3 ) ;
}
void T_1 F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_8 ) ;
}
void T_1 F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 != V_5 ) {
F_2 ( V_6 L_2 , V_2 ) ;
F_3 ( 1 ) ;
return;
}
F_8 ( & V_2 -> V_7 ) ;
F_9 ( V_2 ) ;
}
void T_1 F_10 ( struct V_1 * V_2 ,
struct V_1 * V_9 )
{
if ( V_2 < V_9 ) {
F_6 ( V_2 ) ;
F_1 ( V_9 , V_10 ) ;
} else {
if ( V_9 && V_9 != V_2 )
F_6 ( V_9 ) ;
F_1 ( V_2 , V_10 ) ;
}
}
void T_1 F_11 ( struct V_1 * V_2 ,
struct V_1 * V_9 )
{
F_7 ( V_2 ) ;
if ( V_9 && V_9 != V_2 )
F_7 ( V_9 ) ;
}
