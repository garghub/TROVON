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
static void F_5 ( void T_1 * V_1 )
{
int V_23 ;
F_6 ( L_1 ) ;
for ( V_23 = 0 ; V_23 < 9 ; V_23 ++ )
F_6 ( L_2 , V_23 ,
( V_10 + V_23 * 4 ) ,
F_4 ( V_1 + V_10 + V_23 * 4 ) ) ;
F_6 ( L_3 ,
V_24 , F_4 ( V_1 + V_24 ) ,
V_25 , F_4 ( V_1 + V_25 ) ) ;
}
static void F_7 ( void * V_26 , struct V_27 * V_28 ,
void T_1 * V_1 )
{
struct V_29 * V_30 = (struct V_29 * ) V_26 ;
T_2 V_31 = F_4 ( V_1 + V_32 ) ;
if ( F_8 ( V_31 ) ) {
if ( V_31 & V_33 ) {
V_30 -> V_34 += 0x800 ;
V_28 -> V_35 += 0x800 ;
} else {
unsigned int V_36 ;
V_36 = ( ( V_31 & V_37 ) >> 17 ) ;
V_30 -> V_34 += V_36 ;
V_28 -> V_35 += V_36 ;
}
if ( V_31 & V_38 ) {
V_30 -> V_39 += 0xffff ;
V_28 -> V_40 += 0xffff ;
} else {
unsigned int V_41 = ( V_31 & V_42 ) ;
V_30 -> V_39 += V_41 ;
V_28 -> V_40 += V_41 ;
}
}
}
