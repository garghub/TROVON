void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
T_1 V_9 ;
T_1 V_10 ;
if ( ! V_6 || ! F_2 ( V_6 , L_1 ) )
return;
if ( F_3 ( V_6 , L_2 , & V_10 ) == 0 )
V_4 -> V_11 = V_10 ;
if ( ! F_4 ( V_6 , L_3 , NULL ) )
return;
V_8 = F_5 ( V_6 , 0 ) ;
if ( ! V_8 ) {
F_6 ( L_4 ) ;
return;
}
V_9 = F_7 ( F_8 ( V_8 ) ) ;
V_4 -> V_12 = true ;
V_4 -> V_13 = V_8 ;
V_4 -> V_14 = V_9 ;
}
