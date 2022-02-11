static void F_1 ( void T_1 * V_1 ,
struct V_2 * V_3 ,
T_2 V_4 , T_2 V_5 , int V_6 )
{
F_2 ( V_7 | ( V_3 -> V_8 << V_9 ) ,
V_1 + V_10 ) ;
F_2 ( V_11 , V_1 + V_12 ) ;
F_2 ( V_4 , V_1 + V_13 ) ;
F_2 ( V_5 , V_1 + V_14 ) ;
}
static void F_3 ( void T_1 * V_1 , int V_15 ,
int V_16 , int V_17 )
{
T_2 V_18 = F_4 ( V_1 + V_19 ) ;
if ( V_15 <= 32 )
V_18 |= V_20 ;
else if ( V_15 <= 64 )
V_18 |= V_21 ;
else
V_18 |= V_22 ;
F_2 ( V_18 , V_1 + V_19 ) ;
}
static void F_5 ( void T_1 * V_1 , T_2 * V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
V_23 [ V_10 / 4 + V_24 ] =
F_4 ( V_1 + V_10 + V_24 * 4 ) ;
V_23 [ V_26 / 4 ] =
F_4 ( V_1 + V_26 ) ;
V_23 [ V_27 / 4 ] =
F_4 ( V_1 + V_27 ) ;
}
static void F_6 ( void * V_28 , struct V_29 * V_30 ,
void T_1 * V_1 )
{
struct V_31 * V_32 = (struct V_31 * ) V_28 ;
T_2 V_33 = F_4 ( V_1 + V_34 ) ;
if ( F_7 ( V_33 ) ) {
if ( V_33 & V_35 ) {
V_32 -> V_36 += 0x800 ;
V_30 -> V_37 += 0x800 ;
} else {
unsigned int V_38 ;
V_38 = ( ( V_33 & V_39 ) >> 17 ) ;
V_32 -> V_36 += V_38 ;
V_30 -> V_37 += V_38 ;
}
if ( V_33 & V_40 ) {
V_32 -> V_41 += 0xffff ;
V_30 -> V_42 += 0xffff ;
} else {
unsigned int V_43 = ( V_33 & V_44 ) ;
V_32 -> V_41 += V_43 ;
V_30 -> V_42 += V_43 ;
}
}
}
