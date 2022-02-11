static int F_1 ( void T_1 * V_1 , int V_2 , int V_3 , int V_4 ,
int V_5 , T_2 V_6 , T_2 V_7 , int V_8 )
{
T_2 V_9 = F_2 ( V_1 + V_10 ) ;
int V_11 ;
V_9 |= V_12 ;
F_3 ( V_9 , V_1 + V_10 ) ;
V_11 = 10 ;
while ( V_11 -- ) {
if ( ! ( F_2 ( V_1 + V_10 ) & V_12 ) )
break;
F_4 ( 10 ) ;
}
if ( V_11 < 0 )
return - V_13 ;
F_3 ( V_14 | ( V_2 << V_15 ) ,
V_1 + V_10 ) ;
F_3 ( V_16 , V_1 + V_17 ) ;
F_3 ( V_6 , V_1 + V_18 ) ;
F_3 ( V_7 , V_1 + V_19 ) ;
return 0 ;
}
static void F_5 ( void T_1 * V_1 , int V_20 ,
int V_21 )
{
T_2 V_22 = F_2 ( V_1 + V_23 ) ;
if ( V_20 <= 32 )
V_22 |= V_24 ;
else if ( V_20 <= 64 )
V_22 |= V_25 ;
else
V_22 |= V_26 ;
F_3 ( V_22 , V_1 + V_23 ) ;
}
static void F_6 ( void T_1 * V_1 )
{
int V_27 ;
F_7 ( V_28 L_1 ) ;
for ( V_27 = 0 ; V_27 < 9 ; V_27 ++ )
F_8 ( L_2 , V_27 ,
( V_10 + V_27 * 4 ) ,
F_2 ( V_1 + V_10 + V_27 * 4 ) ) ;
F_7 ( V_28 L_3 ,
V_29 , F_2 ( V_1 + V_29 ) ) ;
F_7 ( V_28 L_4 ,
V_30 , F_2 ( V_1 + V_30 ) ) ;
}
static void F_9 ( void * V_31 , struct V_32 * V_33 ,
void T_1 * V_1 )
{
struct V_34 * V_35 = (struct V_34 * ) V_31 ;
T_2 V_36 = F_2 ( V_1 + V_37 ) ;
if ( F_10 ( V_36 ) ) {
if ( V_36 & V_38 ) {
V_35 -> V_39 += 0x800 ;
V_33 -> V_40 += 0x800 ;
} else {
unsigned int V_41 ;
V_41 = ( ( V_36 & V_42 ) >> 17 ) ;
V_35 -> V_39 += V_41 ;
V_33 -> V_40 += V_41 ;
}
if ( V_36 & V_43 ) {
V_35 -> V_44 += 0xffff ;
V_33 -> V_45 += 0xffff ;
} else {
unsigned int V_46 = ( V_36 & V_47 ) ;
V_35 -> V_44 += V_46 ;
V_33 -> V_45 += V_46 ;
}
}
}
