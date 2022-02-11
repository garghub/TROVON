static void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned long V_4 , unsigned long V_5 )
{
V_4 &= V_6 ;
for (; V_4 < V_5 ; V_4 += V_7 ) {
T_1 * V_8 = V_3 + F_2 ( V_4 ) ;
if ( F_3 ( * V_8 ) )
continue;
F_4 ( V_8 , F_5 ( ( V_4 - V_2 -> V_9 ) | V_2 -> V_10 ) ) ;
}
}
static int F_6 ( struct V_1 * V_2 , T_2 * V_11 ,
unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_12 ;
for (; V_4 < V_5 ; V_4 = V_12 ) {
T_2 * V_13 = V_11 + F_7 ( V_4 ) ;
T_1 * V_8 ;
V_12 = ( V_4 & V_14 ) + V_15 ;
if ( V_12 > V_5 )
V_12 = V_5 ;
if ( F_8 ( * V_13 ) ) {
V_8 = F_9 ( V_13 , 0 ) ;
F_1 ( V_2 , V_8 , V_4 , V_12 ) ;
continue;
}
V_8 = ( T_1 * ) V_2 -> V_16 ( V_2 -> V_17 ) ;
if ( ! V_8 )
return - V_18 ;
F_1 ( V_2 , V_8 , V_4 , V_12 ) ;
F_10 ( V_13 , F_11 ( F_12 ( V_8 ) | V_19 ) ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_3 * V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
unsigned long V_4 = V_21 + V_2 -> V_9 ;
unsigned long V_5 = V_22 + V_2 -> V_9 ;
unsigned long V_12 ;
int V_23 ;
for (; V_4 < V_5 ; V_4 = V_12 ) {
T_3 * V_24 = V_20 + F_14 ( V_4 ) ;
T_2 * V_13 ;
V_12 = ( V_4 & V_25 ) + V_26 ;
if ( V_12 > V_5 )
V_12 = V_5 ;
if ( F_15 ( * V_24 ) ) {
V_13 = F_16 ( V_24 , 0 ) ;
V_23 = F_6 ( V_2 , V_13 , V_4 , V_12 ) ;
if ( V_23 )
return V_23 ;
continue;
}
V_13 = ( T_2 * ) V_2 -> V_16 ( V_2 -> V_17 ) ;
if ( ! V_13 )
return - V_18 ;
V_23 = F_6 ( V_2 , V_13 , V_4 , V_12 ) ;
if ( V_23 )
return V_23 ;
F_17 ( V_24 , F_18 ( F_12 ( V_13 ) | V_19 ) ) ;
}
return 0 ;
}
