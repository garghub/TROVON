void F_1 ( void T_1 * V_1 ,
const struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
T_2 V_7 ;
V_7 = F_2 ( V_1 ) ;
for (; V_4 > 0 ; V_4 -- , V_3 ++ ) {
if ( V_3 -> V_8 == V_9 ) {
V_7 |= V_3 -> V_10 ;
continue;
}
V_6 = F_3 ( V_3 -> V_8 ) ;
if ( F_4 ( V_6 ) )
V_7 &= ~ V_3 -> V_10 ;
else
V_7 |= V_3 -> V_10 ;
}
F_5 ( V_11 L_1 , F_2 ( V_1 ) , V_7 ) ;
F_6 ( V_7 , V_1 ) ;
}
