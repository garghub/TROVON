int
F_1 ( struct V_1 * V_2 , T_1 V_3 , struct F_1 * V_4 )
{
if ( F_2 ( V_2 -> V_5 ) ) {
T_1 V_6 = F_3 ( V_2 , V_2 -> V_5 + 10 ) ;
T_2 V_7 = V_2 -> V_5 + 12 ;
while ( V_6 -- ) {
if ( F_3 ( V_2 , V_7 + 0 ) == V_3 ) {
V_4 -> V_3 = F_3 ( V_2 , V_7 + 0 ) ;
V_4 -> V_8 = F_3 ( V_2 , V_7 + 1 ) ;
V_4 -> V_9 = F_4 ( V_2 , V_7 + 2 ) ;
V_4 -> V_10 = F_4 ( V_2 , V_7 + 4 ) ;
return 0 ;
}
V_7 += F_3 ( V_2 , V_2 -> V_5 + 9 ) ;
}
return - V_11 ;
}
return - V_12 ;
}
