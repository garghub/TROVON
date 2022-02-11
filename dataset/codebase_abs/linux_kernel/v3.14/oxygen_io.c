T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
T_2 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
T_3 F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
void F_7 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
V_2 -> V_6 . V_7 [ V_3 ] = V_5 ;
}
void F_9 ( struct V_1 * V_2 , unsigned int V_3 , T_2 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
V_2 -> V_6 . V_8 [ V_3 / 2 ] = F_11 ( V_5 ) ;
}
void F_12 ( struct V_1 * V_2 , unsigned int V_3 , T_3 V_5 )
{
F_13 ( V_5 , V_2 -> V_4 + V_3 ) ;
V_2 -> V_6 . V_9 [ V_3 / 4 ] = F_14 ( V_5 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_5 , T_1 V_10 )
{
T_1 V_11 = F_2 ( V_2 -> V_4 + V_3 ) ;
V_11 &= ~ V_10 ;
V_11 |= V_5 & V_10 ;
F_8 ( V_11 , V_2 -> V_4 + V_3 ) ;
V_2 -> V_6 . V_7 [ V_3 ] = V_11 ;
}
void F_16 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_5 , T_2 V_10 )
{
T_2 V_11 = F_4 ( V_2 -> V_4 + V_3 ) ;
V_11 &= ~ V_10 ;
V_11 |= V_5 & V_10 ;
F_10 ( V_11 , V_2 -> V_4 + V_3 ) ;
V_2 -> V_6 . V_8 [ V_3 / 2 ] = F_11 ( V_11 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned int V_3 ,
T_3 V_5 , T_3 V_10 )
{
T_3 V_11 = F_6 ( V_2 -> V_4 + V_3 ) ;
V_11 &= ~ V_10 ;
V_11 |= V_5 & V_10 ;
F_13 ( V_11 , V_2 -> V_4 + V_3 ) ;
V_2 -> V_6 . V_9 [ V_3 / 4 ] = F_14 ( V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_10 )
{
T_1 V_12 = 0 ;
F_19 (chip->ac97_waitqueue,
({ status |= oxygen_read8(chip, OXYGEN_AC97_INTERRUPT_STATUS);
status & mask; }),
msecs_to_jiffies(1) + 1 ) ;
V_12 |= F_1 ( V_2 , V_13 ) ;
return V_12 & V_10 ? 0 : - V_14 ;
}
void F_20 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 , T_2 V_17 )
{
unsigned int V_18 , V_19 ;
T_3 V_3 ;
V_3 = V_17 ;
V_3 |= V_16 << V_20 ;
V_3 |= V_21 ;
V_3 |= V_15 << V_22 ;
V_19 = 0 ;
for ( V_18 = 5 ; V_18 > 0 ; -- V_18 ) {
F_21 ( 5 ) ;
F_12 ( V_2 , V_23 , V_3 ) ;
if ( F_18 ( V_2 , V_24 ) >= 0 &&
++ V_19 >= 2 ) {
V_2 -> V_25 [ V_15 ] [ V_16 / 2 ] = V_17 ;
return;
}
}
F_22 ( V_26 L_1 ) ;
}
T_2 F_23 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 )
{
unsigned int V_18 ;
unsigned int V_27 = V_28 ;
T_3 V_3 ;
V_3 = V_16 << V_20 ;
V_3 |= V_29 ;
V_3 |= V_15 << V_22 ;
for ( V_18 = 5 ; V_18 > 0 ; -- V_18 ) {
F_21 ( 5 ) ;
F_12 ( V_2 , V_23 , V_3 ) ;
F_21 ( 10 ) ;
if ( F_18 ( V_2 , V_30 ) >= 0 ) {
T_2 V_5 = F_3 ( V_2 , V_23 ) ;
if ( V_5 == V_27 )
return V_5 ;
V_27 = V_5 ;
V_3 ^= 0xffff ;
}
}
F_22 ( V_26 L_2 , V_15 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 , unsigned int V_15 ,
unsigned int V_16 , T_2 V_17 , T_2 V_10 )
{
T_2 V_5 = F_23 ( V_2 , V_15 , V_16 ) ;
V_5 &= ~ V_10 ;
V_5 |= V_17 & V_10 ;
F_20 ( V_2 , V_15 , V_16 , V_5 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned int V_18 ;
for ( V_18 = 50 ; V_18 > 0 ; V_18 -- ) {
F_21 ( 4 ) ;
if ( ( F_1 ( V_2 , V_31 ) &
V_32 ) == 0 )
return 0 ;
}
F_22 ( V_26 L_3 ) ;
return - V_14 ;
}
int F_26 ( struct V_1 * V_2 , T_1 V_33 , unsigned int V_17 )
{
F_7 ( V_2 , V_34 , V_17 ) ;
F_7 ( V_2 , V_35 , V_17 >> 8 ) ;
if ( V_33 & V_36 )
F_7 ( V_2 , V_37 , V_17 >> 16 ) ;
F_7 ( V_2 , V_31 , V_33 ) ;
return F_25 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_38 , T_1 V_39 , T_1 V_17 )
{
F_28 ( 1 ) ;
F_7 ( V_2 , V_40 , V_39 ) ;
F_7 ( V_2 , V_41 , V_17 ) ;
F_7 ( V_2 , V_42 ,
V_38 | V_43 ) ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_44 , T_1 V_17 )
{
if ( F_1 ( V_2 , V_45 + 1 ) & V_46 )
F_28 ( 1 ) ;
F_7 ( V_2 , V_45 + V_44 , V_17 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
F_29 ( V_2 , 1 , V_47 ) ;
F_28 ( 1 ) ;
F_29 ( V_2 , 1 , V_48 ) ;
}
void F_31 ( struct V_1 * V_2 , T_1 V_17 )
{
F_29 ( V_2 , 0 , V_17 ) ;
}
T_2 F_32 ( struct V_1 * V_2 , unsigned int V_16 )
{
unsigned int V_49 ;
F_7 ( V_2 , V_50 ,
V_16 | V_51 ) ;
for ( V_49 = 0 ; V_49 < 100 ; ++ V_49 ) {
F_21 ( 1 ) ;
if ( ! ( F_1 ( V_2 , V_52 )
& V_53 ) )
break;
}
return F_3 ( V_2 , V_54 ) ;
}
void F_33 ( struct V_1 * V_2 , unsigned int V_16 , T_2 V_5 )
{
unsigned int V_49 ;
F_9 ( V_2 , V_54 , V_5 ) ;
F_7 ( V_2 , V_50 ,
V_16 | V_55 ) ;
for ( V_49 = 0 ; V_49 < 10 ; ++ V_49 ) {
F_28 ( 1 ) ;
if ( ! ( F_1 ( V_2 , V_52 )
& V_53 ) )
return;
}
F_22 ( V_26 L_4 ) ;
}
