static int F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 ,
T_2 V_4 )
{
T_2 V_5 = F_2 ( V_1 + V_6 ) ;
int V_7 ;
V_5 |= V_8 ;
F_3 ( V_5 , V_1 + V_6 ) ;
V_7 = 10 ;
while ( V_7 -- ) {
if ( ! ( F_2 ( V_1 + V_6 ) & V_8 ) )
break;
F_4 ( 10 ) ;
}
if ( V_7 < 0 )
return - V_9 ;
F_3 ( V_10 | ( V_2 << V_11 ) ,
V_1 + V_6 ) ;
F_3 ( V_12 , V_1 + V_13 ) ;
F_3 ( V_3 , V_1 + V_14 ) ;
F_3 ( V_4 , V_1 + V_15 ) ;
return 0 ;
}
static void F_5 ( void T_1 * V_1 , int V_16 ,
int V_17 )
{
T_2 V_18 = F_2 ( V_1 + V_19 ) ;
if ( V_16 <= 32 )
V_18 |= V_20 ;
else if ( V_16 <= 64 )
V_18 |= V_21 ;
else
V_18 |= V_22 ;
F_3 ( V_18 , V_1 + V_19 ) ;
}
static void F_6 ( void T_1 * V_1 )
{
int V_23 ;
F_7 ( V_24 L_1 ) ;
for ( V_23 = 0 ; V_23 < 9 ; V_23 ++ )
F_8 ( L_2 , V_23 ,
( V_6 + V_23 * 4 ) ,
F_2 ( V_1 + V_6 + V_23 * 4 ) ) ;
F_7 ( V_24 L_3 ,
V_25 , F_2 ( V_1 + V_25 ) ) ;
F_7 ( V_24 L_4 ,
V_26 , F_2 ( V_1 + V_26 ) ) ;
}
static void F_9 ( void * V_27 , struct V_28 * V_29 ,
void T_1 * V_1 )
{
struct V_30 * V_31 = (struct V_30 * ) V_27 ;
T_2 V_32 = F_2 ( V_1 + V_33 ) ;
if ( F_10 ( V_32 ) ) {
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
