static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
F_2 () ;
if ( ! F_3 () ) {
while ( ! F_4 () )
F_5 () ;
}
F_6 () ;
return V_5 ;
}
void F_7 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = & V_4 -> V_8 [ 0 ] ;
snprintf ( V_7 -> V_9 , V_10 , L_1 ) ;
snprintf ( V_7 -> V_11 , V_12 , L_2 ) ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = 0 ;
V_7 -> V_15 = - 1 ;
V_7 -> V_16 = F_1 ;
V_7 -> V_17 = false ;
V_7 -> V_18 = V_19 ;
}
