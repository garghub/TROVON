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
void F_7 ( unsigned int V_11 , unsigned int V_1 ,
unsigned int V_2 , bool V_12 , T_3 V_13 )
{
T_3 V_14 , V_15 , V_16 , V_17 , V_18 , V_4 , V_19 ;
void T_2 * V_3 ;
struct V_5 * V_6 = & V_5 ;
T_3 V_20 = V_21 ;
if ( ! V_6 -> V_7 || ( V_1 >= V_6 -> V_8 ) ) {
F_2 ( L_1 ,
( int ) V_6 -> V_7 , V_1 ) ;
return;
}
V_3 = F_3 ( V_6 -> V_7 [ V_1 ] , V_9 ) ;
if ( ! V_12 ) {
if ( V_13 & V_22 )
V_20 = V_23 ;
else
V_20 = V_24 ;
}
V_19 = F_4 ( V_3 + V_25 + 4 * V_2 ) ;
V_19 &= ~ V_26 ;
V_19 |= V_20 ;
if ( V_13 & V_27 )
V_19 |= V_28 ;
F_8 ( V_19 , V_3 + V_25 + 4 * V_2 ) ;
V_17 = F_4 ( V_3 + V_29 ) ;
if ( ( V_17 & 0x00000001 ) == 0 ) {
V_18 = F_4 ( V_3 + V_30 ) ;
V_18 |= 0x1 ;
F_8 ( V_18 , V_3 + V_30 ) ;
V_15 = 1 << V_11 ;
F_8 ( V_15 , V_3 + V_31 ) ;
do {
V_14 = F_4 ( V_3 + V_32 ) ;
} while ( ( ( ( V_14 >> V_11 ) & 1 ) == 0 ) );
V_18 = F_4 ( V_3 + V_30 ) ;
V_18 |= 0x100 ;
F_8 ( V_18 , V_3 + V_30 ) ;
} else {
V_15 = 1 << V_11 ;
F_8 ( V_15 , V_3 + V_31 ) ;
}
do {
V_16 = F_4 ( V_3 + V_33 ) ;
} while ( ! ( ( ( V_16 >> V_11 ) & 1 ) == 0 ) );
do {
V_4 = F_4 ( V_3 + V_10 + 4 * V_2 ) ;
} while ( ! ( ( V_4 & V_26 ) == V_20 ) );
F_5 ( V_3 ) ;
}
