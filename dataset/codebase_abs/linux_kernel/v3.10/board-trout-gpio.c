static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_6 = 1 << V_3 ;
return ! ! ( F_3 ( V_5 -> V_7 ) & V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 , int V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_6 = 1 << V_3 ;
if ( V_8 )
V_5 -> V_9 |= V_6 ;
else
V_5 -> V_9 &= ~ V_6 ;
F_5 ( V_5 -> V_9 , V_5 -> V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_3 )
{
F_4 ( V_2 , V_3 , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_8 )
{
F_4 ( V_2 , V_3 , V_8 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_9 ( V_3 + V_2 -> V_10 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
int V_13 = F_11 ( V_12 -> V_14 ) ;
T_1 V_6 = F_12 ( V_12 -> V_14 ) ;
int V_7 = F_13 ( V_13 ) ;
F_5 ( V_6 , V_15 + V_7 ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
unsigned long V_16 ;
T_1 V_17 ;
int V_13 = F_11 ( V_12 -> V_14 ) ;
T_1 V_6 = F_12 ( V_12 -> V_14 ) ;
int V_7 = F_15 ( V_13 ) ;
F_16 ( V_16 ) ;
V_17 = V_18 [ V_13 ] |= V_6 ;
F_5 ( V_17 , V_15 + V_7 ) ;
F_17 ( V_16 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
unsigned long V_16 ;
T_1 V_17 ;
int V_13 = F_11 ( V_12 -> V_14 ) ;
T_1 V_6 = F_12 ( V_12 -> V_14 ) ;
int V_7 = F_15 ( V_13 ) ;
F_16 ( V_16 ) ;
V_17 = V_18 [ V_13 ] &= ~ V_6 ;
F_5 ( V_17 , V_15 + V_7 ) ;
F_17 ( V_16 ) ;
}
int F_19 ( struct V_11 * V_12 , unsigned int V_19 )
{
unsigned long V_16 ;
int V_13 = F_11 ( V_12 -> V_14 ) ;
T_1 V_6 = F_12 ( V_12 -> V_14 ) ;
F_16 ( V_16 ) ;
if( V_19 )
V_20 [ V_13 ] &= ~ V_6 ;
else
V_20 [ V_13 ] |= V_6 ;
F_17 ( V_16 ) ;
return 0 ;
}
static void F_20 ( unsigned int V_14 , struct V_21 * V_22 )
{
int V_23 , V_24 ;
unsigned V_25 ;
int V_13 ;
int V_26 ;
int V_27 = V_28 ;
T_1 V_29 ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
V_26 = F_13 ( V_13 ) ;
V_25 = F_3 ( V_15 + V_26 ) ;
V_29 = V_18 [ V_13 ] ;
if ( V_25 & V_29 ) {
F_5 ( V_25 & V_29 , V_15 + V_26 ) ;
F_21 ( V_30 L_1
L_2 , V_13 , V_25 & V_29 ) ;
}
V_25 &= ~ V_29 ;
while ( V_25 ) {
V_24 = V_25 & - V_25 ;
V_23 = F_22 ( V_24 ) - 1 ;
V_25 &= ~ V_24 ;
F_23 ( V_27 + V_23 ) ;
}
V_27 += V_31 ;
}
V_22 -> V_11 . V_2 -> V_32 ( & V_22 -> V_11 ) ;
}
int T_2 F_24 ( void )
{
int V_33 ;
for( V_33 = V_28 ; V_33 <= V_34 ; V_33 ++ ) {
F_25 ( V_33 , & V_35 ,
V_36 ) ;
F_26 ( V_33 , V_37 ) ;
}
for ( V_33 = 0 ; V_33 < F_27 ( V_38 ) ; V_33 ++ )
F_28 ( & V_38 [ V_33 ] . V_2 ) ;
F_29 ( F_30 ( 17 ) , V_39 ) ;
F_31 ( F_30 ( 17 ) , F_20 ) ;
F_32 ( F_30 ( 17 ) , 1 ) ;
return 0 ;
}
