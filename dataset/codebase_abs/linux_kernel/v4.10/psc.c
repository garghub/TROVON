int T_1 F_1 ( unsigned int V_1 , unsigned int V_2 )
{
void T_2 * V_3 ;
T_3 V_4 ;
struct V_5 * V_6 = & V_5 ;
if ( ! V_6 -> V_7 || ( V_1 >= V_6 -> V_8 ) ) {
F_2 ( L_1 ,
( int ) V_6 -> V_7 , V_1 ) ;
return 0 ;
}
V_3 = F_3 ( V_6 -> V_7 [ V_1 ] , V_9 ) ;
V_4 = F_4 ( V_3 + V_10 + 4 * V_2 ) ;
F_5 ( V_3 ) ;
return V_4 & F_6 ( 12 ) ;
}
void F_7 ( unsigned int V_1 , unsigned int V_2 , bool V_11 )
{
T_3 V_12 ;
void T_2 * V_3 ;
struct V_5 * V_6 = & V_5 ;
if ( ! V_6 -> V_7 || ( V_1 >= V_6 -> V_8 ) ) {
F_2 ( L_1 ,
( int ) V_6 -> V_7 , V_1 ) ;
return;
}
V_3 = F_3 ( V_6 -> V_7 [ V_1 ] , V_9 ) ;
V_12 = F_8 ( V_3 + V_13 + 4 * V_2 ) ;
if ( V_11 )
V_12 &= ~ V_14 ;
else
V_12 |= V_14 ;
F_9 ( V_12 , V_3 + V_13 + 4 * V_2 ) ;
F_5 ( V_3 ) ;
}
void F_10 ( unsigned int V_15 , unsigned int V_1 ,
unsigned int V_2 , bool V_16 , T_3 V_17 )
{
T_3 V_18 , V_19 , V_20 , V_21 , V_22 , V_4 , V_12 ;
void T_2 * V_3 ;
struct V_5 * V_6 = & V_5 ;
T_3 V_23 = V_24 ;
if ( ! V_6 -> V_7 || ( V_1 >= V_6 -> V_8 ) ) {
F_2 ( L_1 ,
( int ) V_6 -> V_7 , V_1 ) ;
return;
}
V_3 = F_3 ( V_6 -> V_7 [ V_1 ] , V_9 ) ;
if ( ! V_16 ) {
if ( V_17 & V_25 )
V_23 = V_26 ;
else
V_23 = V_27 ;
}
V_12 = F_4 ( V_3 + V_13 + 4 * V_2 ) ;
V_12 &= ~ V_28 ;
V_12 |= V_23 ;
if ( V_17 & V_29 )
V_12 |= V_30 ;
F_11 ( V_12 , V_3 + V_13 + 4 * V_2 ) ;
V_21 = F_4 ( V_3 + V_31 + 4 * V_15 ) ;
if ( ( V_21 & V_32 ) == 0 ) {
V_22 = F_4 ( V_3 + V_33 + 4 * V_15 ) ;
V_22 |= V_34 ;
F_11 ( V_22 , V_3 + V_33 + 4 * V_15 ) ;
V_19 = 1 << V_15 ;
F_11 ( V_19 , V_3 + V_35 ) ;
do {
V_18 = F_4 ( V_3 + V_36 ) ;
} while ( ( ( ( V_18 >> V_15 ) & 1 ) == 0 ) );
V_22 = F_4 ( V_3 + V_33 + 4 * V_15 ) ;
V_22 |= V_37 ;
F_11 ( V_22 , V_3 + V_33 + 4 * V_15 ) ;
} else {
V_19 = 1 << V_15 ;
F_11 ( V_19 , V_3 + V_35 ) ;
}
do {
V_20 = F_4 ( V_3 + V_38 ) ;
} while ( ! ( ( ( V_20 >> V_15 ) & 1 ) == 0 ) );
do {
V_4 = F_4 ( V_3 + V_10 + 4 * V_2 ) ;
} while ( ! ( ( V_4 & V_28 ) == V_23 ) );
F_5 ( V_3 ) ;
}
