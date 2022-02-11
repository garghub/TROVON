T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned long V_4 , T_2 V_5 , int V_6 )
{
T_1 V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return V_7 ;
}
int F_3 ( unsigned long V_8 , T_2 V_9 , bool V_10 ,
struct V_3 * * V_11 )
{
unsigned long V_12 , V_13 = F_4 ( V_14 ) >> V_15 ;
bool V_16 = F_5 ( V_17 ) ;
int V_18 ;
F_6 ( & V_19 -> V_20 -> V_21 ) ;
V_12 = V_19 -> V_20 -> V_22 ;
F_7 ( & V_19 -> V_20 -> V_21 ) ;
if ( V_12 + V_9 > V_13 && ! V_16 )
return - V_23 ;
V_18 = F_8 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( V_18 < 0 )
return V_18 ;
F_9 ( & V_19 -> V_20 -> V_21 ) ;
V_19 -> V_20 -> V_22 += V_18 ;
F_10 ( & V_19 -> V_20 -> V_21 ) ;
return V_18 ;
}
void F_11 ( struct V_3 * * V_24 , T_2 V_9 , bool V_25 )
{
T_2 V_26 ;
for ( V_26 = 0 ; V_26 < V_9 ; V_26 ++ ) {
if ( V_25 )
F_12 ( V_24 [ V_26 ] ) ;
F_13 ( V_24 [ V_26 ] ) ;
}
if ( V_19 -> V_20 ) {
F_9 ( & V_19 -> V_20 -> V_21 ) ;
V_19 -> V_20 -> V_22 -= V_9 ;
F_10 ( & V_19 -> V_20 -> V_21 ) ;
}
}
