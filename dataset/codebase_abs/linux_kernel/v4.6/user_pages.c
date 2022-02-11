bool F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_5 = F_2 ( V_6 ) , V_7 , V_8 ,
V_9 = ( V_10 * ( 1UL << 20 ) ) ;
unsigned V_11 = V_2 -> V_12 - V_2 -> V_13 ;
bool V_14 = F_3 ( V_15 ) ;
V_8 = ( V_5 / V_11 ) / 4 ;
if ( V_5 != ( - 1UL ) && V_9 > V_8 )
V_9 = V_8 ;
V_9 = F_4 ( V_9 , V_16 ) ;
F_5 ( & V_17 -> V_18 -> V_19 ) ;
V_7 = V_17 -> V_18 -> V_20 ;
F_6 ( & V_17 -> V_18 -> V_19 ) ;
if ( V_7 + V_4 >= V_5 && ! V_14 )
return false ;
return ( ( V_3 + V_4 ) <= V_9 ) || V_14 ;
}
int F_7 ( unsigned long V_21 , T_2 V_4 , bool V_22 ,
struct V_23 * * V_24 )
{
int V_25 ;
V_25 = F_8 ( V_21 , V_4 , V_22 , V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
F_9 ( & V_17 -> V_18 -> V_19 ) ;
V_17 -> V_18 -> V_20 += V_25 ;
F_10 ( & V_17 -> V_18 -> V_19 ) ;
return V_25 ;
}
void F_11 ( struct V_26 * V_18 , struct V_23 * * V_27 ,
T_2 V_4 , bool V_28 )
{
T_2 V_29 ;
for ( V_29 = 0 ; V_29 < V_4 ; V_29 ++ ) {
if ( V_28 )
F_12 ( V_27 [ V_29 ] ) ;
F_13 ( V_27 [ V_29 ] ) ;
}
if ( V_18 ) {
F_9 ( & V_18 -> V_19 ) ;
V_18 -> V_20 -= V_4 ;
F_10 ( & V_18 -> V_19 ) ;
}
}
