bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
unsigned long V_7 = F_2 ( V_8 ) , V_9 , V_10 ,
V_11 = ( V_12 * ( 1UL << 20 ) ) ;
unsigned V_13 = V_2 -> V_14 - V_2 -> V_15 ;
bool V_16 = F_3 ( V_17 ) ;
V_10 = ( V_7 / V_13 ) / 4 ;
if ( V_7 != ( - 1UL ) && V_11 > V_10 )
V_11 = V_10 ;
V_11 = F_4 ( V_11 , V_18 ) ;
F_5 ( & V_4 -> V_19 ) ;
V_9 = V_4 -> V_20 ;
F_6 ( & V_4 -> V_19 ) ;
if ( V_9 + V_6 >= V_7 && ! V_16 )
return false ;
return ( ( V_5 + V_6 ) <= V_11 ) || V_16 ;
}
int F_7 ( struct V_3 * V_4 , unsigned long V_21 , T_2 V_6 ,
bool V_22 , struct V_23 * * V_24 )
{
int V_25 ;
V_25 = F_8 ( V_21 , V_6 , V_22 , V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
F_9 ( & V_4 -> V_19 ) ;
V_4 -> V_20 += V_25 ;
F_10 ( & V_4 -> V_19 ) ;
return V_25 ;
}
void F_11 ( struct V_3 * V_4 , struct V_23 * * V_26 ,
T_2 V_6 , bool V_27 )
{
T_2 V_28 ;
for ( V_28 = 0 ; V_28 < V_6 ; V_28 ++ ) {
if ( V_27 )
F_12 ( V_26 [ V_28 ] ) ;
F_13 ( V_26 [ V_28 ] ) ;
}
if ( V_4 ) {
F_9 ( & V_4 -> V_19 ) ;
V_4 -> V_20 -= V_6 ;
F_10 ( & V_4 -> V_19 ) ;
}
}
