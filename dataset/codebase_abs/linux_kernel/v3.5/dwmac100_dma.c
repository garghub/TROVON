static int F_1 ( void T_1 * V_1 , int V_2 , int V_3 ,
int V_4 , int V_5 , T_2 V_6 , T_2 V_7 )
{
T_2 V_8 = F_2 ( V_1 + V_9 ) ;
int V_10 ;
V_8 |= V_11 ;
F_3 ( V_8 , V_1 + V_9 ) ;
V_10 = 10 ;
while ( V_10 -- ) {
if ( ! ( F_2 ( V_1 + V_9 ) & V_11 ) )
break;
F_4 ( 10 ) ;
}
if ( V_10 < 0 )
return - V_12 ;
F_3 ( V_13 | ( V_2 << V_14 ) ,
V_1 + V_9 ) ;
F_3 ( V_15 , V_1 + V_16 ) ;
F_3 ( V_6 , V_1 + V_17 ) ;
F_3 ( V_7 , V_1 + V_18 ) ;
return 0 ;
}
static void F_5 ( void T_1 * V_1 , int V_19 ,
int V_20 )
{
T_2 V_21 = F_2 ( V_1 + V_22 ) ;
if ( V_19 <= 32 )
V_21 |= V_23 ;
else if ( V_19 <= 64 )
V_21 |= V_24 ;
else
V_21 |= V_25 ;
F_3 ( V_21 , V_1 + V_22 ) ;
}
static void F_6 ( void T_1 * V_1 )
{
int V_26 ;
F_7 ( V_27 L_1 ) ;
for ( V_26 = 0 ; V_26 < 9 ; V_26 ++ )
F_8 ( L_2 , V_26 ,
( V_9 + V_26 * 4 ) ,
F_2 ( V_1 + V_9 + V_26 * 4 ) ) ;
F_7 ( V_27 L_3 ,
V_28 , F_2 ( V_1 + V_28 ) ) ;
F_7 ( V_27 L_4 ,
V_29 , F_2 ( V_1 + V_29 ) ) ;
}
static void F_9 ( void * V_30 , struct V_31 * V_32 ,
void T_1 * V_1 )
{
struct V_33 * V_34 = (struct V_33 * ) V_30 ;
T_2 V_35 = F_2 ( V_1 + V_36 ) ;
if ( F_10 ( V_35 ) ) {
if ( V_35 & V_37 ) {
V_34 -> V_38 += 0x800 ;
V_32 -> V_39 += 0x800 ;
} else {
unsigned int V_40 ;
V_40 = ( ( V_35 & V_41 ) >> 17 ) ;
V_34 -> V_38 += V_40 ;
V_32 -> V_39 += V_40 ;
}
if ( V_35 & V_42 ) {
V_34 -> V_43 += 0xffff ;
V_32 -> V_44 += 0xffff ;
} else {
unsigned int V_45 = ( V_35 & V_46 ) ;
V_34 -> V_43 += V_45 ;
V_32 -> V_44 += V_45 ;
}
}
}
