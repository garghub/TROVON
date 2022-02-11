void T_1 F_1 ( int V_1 , int V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_8 ;
int V_9 ;
if ( V_5 && V_5 -> V_10 ) {
V_9 = F_2 ( V_2 , V_11 , L_1 ) ;
if ( V_9 ) {
F_3 ( L_2 , V_9 ) ;
return;
}
if ( V_3 )
F_4 ( V_2 , V_3 ) ;
F_5 ( V_2 , 0 ) ;
}
V_7 -> V_1 = V_1 ;
V_7 -> V_12 = F_6 ( V_2 ) ;
V_13 . V_2 = V_2 ;
if ( V_5 ) {
V_5 -> V_2 = V_2 ;
V_5 -> V_14 = V_3 ;
V_7 -> V_15 = V_5 ;
}
F_7 ( & V_8 , 1 ) ;
}
void T_1 F_1 ( int V_1 , int V_2 , int V_3 ,
struct V_4 * V_5 )
{
}
