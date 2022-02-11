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
if ( V_2 -> V_16 ) {
T_2 V_17 ;
if ( F_8 ( * V_13 ) )
continue;
V_4 &= V_14 ;
V_17 = F_9 ( ( V_4 - V_2 -> V_9 ) | V_2 -> V_10 ) ;
F_10 ( V_13 , V_17 ) ;
continue;
}
if ( F_8 ( * V_13 ) ) {
V_8 = F_11 ( V_13 , 0 ) ;
F_1 ( V_2 , V_8 , V_4 , V_12 ) ;
continue;
}
V_8 = ( T_1 * ) V_2 -> V_18 ( V_2 -> V_19 ) ;
if ( ! V_8 )
return - V_20 ;
F_1 ( V_2 , V_8 , V_4 , V_12 ) ;
F_10 ( V_13 , F_9 ( F_12 ( V_8 ) | V_21 ) ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_3 * V_22 ,
unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_12 ;
for (; V_4 < V_5 ; V_4 = V_12 ) {
T_3 * V_23 = V_22 + F_14 ( V_4 ) ;
T_2 * V_13 ;
V_12 = ( V_4 & V_24 ) + V_25 ;
if ( V_12 > V_5 )
V_12 = V_5 ;
if ( F_15 ( * V_23 ) ) {
V_13 = F_16 ( V_23 , 0 ) ;
F_6 ( V_2 , V_13 , V_4 , V_12 ) ;
continue;
}
V_13 = ( T_2 * ) V_2 -> V_18 ( V_2 -> V_19 ) ;
if ( ! V_13 )
return - V_20 ;
F_6 ( V_2 , V_13 , V_4 , V_12 ) ;
F_17 ( V_23 , F_18 ( F_12 ( V_13 ) | V_21 ) ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_4 * V_26 ,
unsigned long V_27 , unsigned long V_28 )
{
unsigned long V_4 = V_27 + V_2 -> V_9 ;
unsigned long V_5 = V_28 + V_2 -> V_9 ;
unsigned long V_12 ;
int V_29 ;
for (; V_4 < V_5 ; V_4 = V_12 ) {
T_4 * V_30 = V_26 + F_20 ( V_4 ) ;
T_3 * V_23 ;
V_12 = ( V_4 & V_31 ) + V_32 ;
if ( V_12 > V_5 )
V_12 = V_5 ;
if ( F_21 ( * V_30 ) ) {
V_23 = F_22 ( V_30 , 0 ) ;
V_29 = F_13 ( V_2 , V_23 , V_4 , V_12 ) ;
if ( V_29 )
return V_29 ;
continue;
}
V_23 = ( T_3 * ) V_2 -> V_18 ( V_2 -> V_19 ) ;
if ( ! V_23 )
return - V_20 ;
V_29 = F_13 ( V_2 , V_23 , V_4 , V_12 ) ;
if ( V_29 )
return V_29 ;
if ( F_23 ( V_33 ) ) {
F_24 ( V_30 , F_25 ( F_12 ( V_23 ) | V_21 ) ) ;
} else {
T_2 * V_13 = F_16 ( V_23 , 0 ) ;
F_24 ( V_30 , F_25 ( F_12 ( V_13 ) | V_21 ) ) ;
}
}
return 0 ;
}
