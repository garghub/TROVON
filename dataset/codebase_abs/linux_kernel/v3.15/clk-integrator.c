static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( - V_4 ) ;
const char * V_5 = V_2 -> V_6 ;
const struct V_7 * V_8 = & V_9 ;
const char * V_10 ;
if ( ! V_11 ) {
struct V_1 * V_12 ;
V_12 = F_3 ( V_2 ) ;
if ( ! V_2 ) {
F_4 ( L_1 ) ;
return;
}
V_11 = F_5 ( V_12 , 0 ) ;
if ( ! V_11 ) {
F_4 ( L_2 ) ;
return;
}
}
V_10 = F_6 ( V_2 , 0 ) ;
V_3 = F_7 ( NULL , V_8 , V_5 , V_10 , V_11 ) ;
if ( ! F_8 ( V_3 ) )
F_9 ( V_2 , V_13 , V_3 ) ;
}
