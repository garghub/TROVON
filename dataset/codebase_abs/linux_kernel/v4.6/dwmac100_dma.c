static void F_1 ( void T_1 * V_1 , int V_2 , int V_3 , int V_4 ,
int V_5 , T_2 V_6 , T_2 V_7 , int V_8 )
{
F_2 ( V_9 | ( V_2 << V_10 ) ,
V_1 + V_11 ) ;
F_2 ( V_12 , V_1 + V_13 ) ;
F_2 ( V_6 , V_1 + V_14 ) ;
F_2 ( V_7 , V_1 + V_15 ) ;
}
static void F_3 ( void T_1 * V_1 , int V_16 ,
int V_17 , int V_18 )
{
T_2 V_19 = F_4 ( V_1 + V_20 ) ;
if ( V_16 <= 32 )
V_19 |= V_21 ;
else if ( V_16 <= 64 )
V_19 |= V_22 ;
else
V_19 |= V_23 ;
F_2 ( V_19 , V_1 + V_20 ) ;
}
static void F_5 ( void T_1 * V_1 )
{
int V_24 ;
F_6 ( L_1 ) ;
for ( V_24 = 0 ; V_24 < 9 ; V_24 ++ )
F_6 ( L_2 , V_24 ,
( V_11 + V_24 * 4 ) ,
F_4 ( V_1 + V_11 + V_24 * 4 ) ) ;
F_6 ( L_3 ,
V_25 , F_4 ( V_1 + V_25 ) ,
V_26 , F_4 ( V_1 + V_26 ) ) ;
}
static void F_7 ( void * V_27 , struct V_28 * V_29 ,
void T_1 * V_1 )
{
struct V_30 * V_31 = (struct V_30 * ) V_27 ;
T_2 V_32 = F_4 ( V_1 + V_33 ) ;
if ( F_8 ( V_32 ) ) {
if ( V_32 & V_34 ) {
V_31 -> V_35 += 0x800 ;
V_29 -> V_36 += 0x800 ;
} else {
unsigned int V_37 ;
V_37 = ( ( V_32 & V_38 ) >> 17 ) ;
V_31 -> V_35 += V_37 ;
V_29 -> V_36 += V_37 ;
}
if ( V_32 & V_39 ) {
V_31 -> V_40 += 0xffff ;
V_29 -> V_41 += 0xffff ;
} else {
unsigned int V_42 = ( V_32 & V_43 ) ;
V_31 -> V_40 += V_42 ;
V_29 -> V_41 += V_42 ;
}
}
}
