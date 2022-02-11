static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
V_4 = V_1 -> V_3 ;
V_5 = F_2 ( V_4 -> V_6 ) ;
V_5 &= ~ V_4 -> V_7 ;
V_5 |= V_2 << F_3 ( V_4 -> V_7 ) ;
F_4 ( V_5 , V_4 -> V_6 ) ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_8 )
{
const struct V_3 * V_4 ;
int V_9 = 0 ;
int V_10 = - V_11 ;
V_4 = V_1 -> V_3 ;
V_8 <<= F_3 ( V_4 -> V_12 ) ;
while ( ( ( F_2 ( V_4 -> V_13 ) & V_4 -> V_12 ) != V_8 ) &&
V_9 < V_14 ) {
V_9 ++ ;
F_6 ( 1 ) ;
}
if ( V_9 == V_14 ) {
F_7 ( V_15 L_1 ,
V_1 -> V_16 , ( V_8 ) ? L_2 : L_3 ) ;
} else {
F_8 ( L_4 ,
V_1 -> V_16 , ( V_8 ) ? L_2 : L_3 , V_9 ) ;
V_10 = 0 ;
}
return V_10 ;
}
static T_3 F_9 ( struct V_1 * V_1 , T_1 V_17 )
{
unsigned long V_18 ;
T_3 V_19 = 0 ;
V_18 = V_1 -> V_3 -> V_20 -> V_21 / V_17 ;
F_8 ( L_5 , V_18 ) ;
if ( V_18 >= 750000 && V_18 <= 1000000 )
V_19 = 0x3 ;
else if ( V_18 > 1000000 && V_18 <= 1250000 )
V_19 = 0x4 ;
else if ( V_18 > 1250000 && V_18 <= 1500000 )
V_19 = 0x5 ;
else if ( V_18 > 1500000 && V_18 <= 1750000 )
V_19 = 0x6 ;
else if ( V_18 > 1750000 && V_18 <= 2100000 )
V_19 = 0x7 ;
else if ( V_18 > 7500000 && V_18 <= 10000000 )
V_19 = 0xB ;
else if ( V_18 > 10000000 && V_18 <= 12500000 )
V_19 = 0xC ;
else if ( V_18 > 12500000 && V_18 <= 15000000 )
V_19 = 0xD ;
else if ( V_18 > 15000000 && V_18 <= 17500000 )
V_19 = 0xE ;
else if ( V_18 > 17500000 && V_18 <= 21000000 )
V_19 = 0xF ;
else
F_8 ( L_6 , V_17 ) ;
return V_19 ;
}
static int F_10 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_1 V_22 ;
T_1 V_8 = 1 ;
int V_23 = 0 ;
F_8 ( L_7 , V_1 -> V_16 ) ;
V_4 = V_1 -> V_3 ;
V_8 <<= F_3 ( V_4 -> V_12 ) ;
if ( ( F_2 ( V_4 -> V_13 ) & V_4 -> V_12 ) == V_8 )
goto V_24;
V_22 = F_11 ( V_1 ) ;
if ( V_22 )
F_12 ( V_1 ) ;
F_1 ( V_1 , V_25 ) ;
V_23 = F_5 ( V_1 , 1 ) ;
if ( V_22 )
F_13 ( V_1 ) ;
V_24:
return V_23 ;
}
static int F_14 ( struct V_1 * V_1 )
{
int V_23 ;
T_1 V_22 ;
if ( ! ( V_1 -> V_3 -> V_26 & ( 1 << V_27 ) ) )
return - V_11 ;
F_8 ( L_8 ,
V_1 -> V_16 ) ;
V_22 = F_11 ( V_1 ) ;
F_1 ( V_1 , V_27 ) ;
V_23 = F_5 ( V_1 , 0 ) ;
if ( V_22 )
F_13 ( V_1 ) ;
return V_23 ;
}
static int F_15 ( struct V_1 * V_1 )
{
T_1 V_22 ;
if ( ! ( V_1 -> V_3 -> V_26 & ( 1 << V_28 ) ) )
return - V_11 ;
F_8 ( L_9 , V_1 -> V_16 ) ;
V_22 = F_11 ( V_1 ) ;
F_1 ( V_1 , V_28 ) ;
if ( V_22 )
F_13 ( V_1 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_1 , T_1 * V_29 , T_3 V_30 , T_1 V_17 )
{
unsigned long V_18 , V_31 ;
V_31 = V_1 -> V_32 -> V_21 ;
V_18 = ( V_31 / V_17 ) * V_30 ;
if ( V_18 < 1000000000 )
* V_29 = 2 ;
else
* V_29 = 4 ;
}
static void F_17 ( struct V_1 * V_1 , T_1 * V_33 , T_3 V_30 , T_1 V_17 )
{
unsigned long V_31 , V_34 ;
int V_35 , V_36 ;
V_31 = V_1 -> V_32 -> V_21 ;
V_31 /= 100000 ;
V_35 = ( V_31 * V_30 ) % ( 250 * V_17 ) ;
V_34 = ( V_31 * V_30 ) / ( 250 * V_17 ) ;
V_36 = V_34 % 10 ;
V_34 /= 10 ;
if ( V_35 || V_36 )
V_34 ++ ;
* V_33 = V_34 ;
}
static int F_18 ( struct V_1 * V_1 , T_3 V_30 , T_1 V_17 , T_3 V_37 )
{
struct V_3 * V_4 = V_1 -> V_3 ;
T_1 V_29 , V_33 ;
T_2 V_5 ;
F_14 ( V_1 ) ;
if ( ! F_19 () && ! F_20 () ) {
V_5 = F_2 ( V_4 -> V_6 ) ;
V_5 &= ~ V_4 -> V_38 ;
V_5 |= V_37 << F_3 ( V_4 -> V_38 ) ;
F_4 ( V_5 , V_4 -> V_6 ) ;
}
V_5 = F_2 ( V_4 -> V_39 ) ;
V_5 &= ~ ( V_4 -> V_40 | V_4 -> V_41 ) ;
V_5 |= V_30 << F_3 ( V_4 -> V_40 ) ;
V_5 |= ( V_17 - 1 ) << F_3 ( V_4 -> V_41 ) ;
if ( V_4 -> V_42 ) {
F_16 ( V_1 , & V_29 , V_30 , V_17 ) ;
V_5 &= ~ ( V_4 -> V_42 ) ;
V_5 |= V_29 << F_3 ( V_4 -> V_42 ) ;
}
if ( V_4 -> V_43 ) {
F_17 ( V_1 , & V_33 , V_30 , V_17 ) ;
V_5 &= ~ ( V_4 -> V_43 ) ;
V_5 |= V_33 << F_3 ( V_4 -> V_43 ) ;
}
F_4 ( V_5 , V_4 -> V_39 ) ;
F_10 ( V_1 ) ;
return 0 ;
}
unsigned long F_21 ( struct V_1 * V_1 )
{
return F_22 ( V_1 ) ;
}
int F_23 ( struct V_1 * V_1 )
{
int V_23 ;
struct V_3 * V_4 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return - V_11 ;
if ( V_1 -> V_21 == V_4 -> V_44 -> V_21 ) {
F_24 ( V_1 -> V_32 != V_4 -> V_44 ) ;
V_23 = F_14 ( V_1 ) ;
} else {
F_24 ( V_1 -> V_32 != V_4 -> V_20 ) ;
V_23 = F_10 ( V_1 ) ;
}
if ( ! V_23 )
V_1 -> V_21 = ( V_1 -> V_45 ) ? V_1 -> V_45 ( V_1 ) :
F_22 ( V_1 ) ;
return V_23 ;
}
void F_25 ( struct V_1 * V_1 )
{
F_15 ( V_1 ) ;
}
int F_26 ( struct V_1 * V_1 , unsigned long V_21 )
{
struct V_1 * V_46 = NULL ;
unsigned long V_47 ;
T_3 V_37 = 0 ;
struct V_3 * V_4 ;
int V_10 ;
if ( ! V_1 || ! V_21 )
return - V_11 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return - V_11 ;
V_47 = ( V_1 -> V_45 ) ? V_1 -> V_45 ( V_1 ) : F_22 ( V_1 ) ;
if ( V_21 == V_47 )
return 0 ;
F_27 ( V_4 -> V_44 ) ;
F_27 ( V_4 -> V_20 ) ;
if ( V_4 -> V_44 -> V_21 == V_21 &&
( V_1 -> V_3 -> V_26 & ( 1 << V_27 ) ) ) {
F_8 ( L_10 , V_1 -> V_16 ) ;
V_10 = F_14 ( V_1 ) ;
if ( ! V_10 )
V_46 = V_4 -> V_44 ;
} else {
if ( V_4 -> V_48 != V_21 )
V_21 = V_1 -> V_49 ( V_1 , V_21 ) ;
if ( V_4 -> V_48 == 0 )
return - V_11 ;
if ( ! F_19 () && ! F_20 () ) {
V_37 = F_9 ( V_1 ,
V_4 -> V_50 ) ;
if ( ! V_37 )
F_24 ( 1 ) ;
}
F_8 ( L_11 ,
V_1 -> V_16 , V_21 ) ;
V_10 = F_18 ( V_1 , V_4 -> V_51 ,
V_4 -> V_50 , V_37 ) ;
if ( ! V_10 )
V_46 = V_4 -> V_20 ;
}
if ( ! V_10 ) {
if ( V_1 -> V_52 ) {
F_27 ( V_46 ) ;
F_28 ( V_1 -> V_32 ) ;
}
F_29 ( V_1 , V_46 ) ;
V_1 -> V_21 = V_21 ;
}
F_28 ( V_4 -> V_20 ) ;
F_28 ( V_4 -> V_44 ) ;
return 0 ;
}
T_2 F_11 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
if ( ! V_1 || ! V_1 -> V_3 )
return - V_11 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 -> V_53 )
return - V_11 ;
V_5 = F_2 ( V_4 -> V_53 ) ;
V_5 &= V_4 -> V_54 ;
V_5 >>= F_3 ( V_4 -> V_54 ) ;
return V_5 ;
}
void F_13 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
if ( ! V_1 || ! V_1 -> V_3 )
return;
V_4 = V_1 -> V_3 ;
if ( ! V_4 -> V_53 ) {
F_8 ( L_12 ,
V_1 -> V_16 ) ;
return;
}
V_5 = F_2 ( V_4 -> V_53 ) ;
V_5 &= ~ V_4 -> V_54 ;
V_5 |= V_55 << F_3 ( V_4 -> V_54 ) ;
F_4 ( V_5 , V_4 -> V_53 ) ;
}
void F_12 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
if ( ! V_1 || ! V_1 -> V_3 )
return;
V_4 = V_1 -> V_3 ;
if ( ! V_4 -> V_53 ) {
F_8 ( L_12 ,
V_1 -> V_16 ) ;
return;
}
V_5 = F_2 ( V_4 -> V_53 ) ;
V_5 &= ~ V_4 -> V_54 ;
V_5 |= V_56 << F_3 ( V_4 -> V_54 ) ;
F_4 ( V_5 , V_4 -> V_53 ) ;
}
unsigned long F_30 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
unsigned long V_21 ;
T_2 V_5 ;
struct V_1 * V_57 ;
V_57 = V_1 -> V_32 ;
while ( V_57 && ! V_57 -> V_3 )
V_57 = V_57 -> V_32 ;
F_24 ( ! V_57 ) ;
V_4 = V_57 -> V_3 ;
F_24 ( ! V_4 -> V_7 ) ;
V_5 = F_2 ( V_4 -> V_6 ) & V_4 -> V_7 ;
V_5 >>= F_3 ( V_4 -> V_7 ) ;
if ( ( V_5 != V_58 ) || ( V_4 -> V_59 & V_60 ) )
V_21 = V_1 -> V_32 -> V_21 ;
else
V_21 = V_1 -> V_32 -> V_21 * 2 ;
return V_21 ;
}
