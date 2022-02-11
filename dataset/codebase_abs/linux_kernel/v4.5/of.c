void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 ;
T_1 V_9 ;
T_1 V_10 ;
if ( ! V_6 || ! F_2 ( V_6 , L_1 ) )
return;
V_2 -> V_11 = F_3 ( V_4 , sizeof( * V_2 -> V_11 ) , V_12 ) ;
if ( ! V_2 -> V_11 )
return;
if ( F_4 ( V_6 , L_2 , & V_10 ) == 0 )
V_2 -> V_11 -> V_13 = V_10 ;
if ( ! F_5 ( V_6 , L_3 , NULL ) )
return;
V_8 = F_6 ( V_6 , 0 ) ;
if ( ! V_8 ) {
F_7 ( L_4 ) ;
return;
}
V_9 = F_8 ( F_9 ( V_8 ) ) ;
V_2 -> V_11 -> V_14 = true ;
V_2 -> V_11 -> V_15 = V_8 ;
V_2 -> V_11 -> V_16 = V_9 ;
}
