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
const char * V_12 ;
V_4 = V_1 -> V_3 ;
V_12 = F_6 ( V_1 ) ;
V_8 <<= F_3 ( V_4 -> V_13 ) ;
while ( ( ( F_2 ( V_4 -> V_14 ) & V_4 -> V_13 ) != V_8 ) &&
V_9 < V_15 ) {
V_9 ++ ;
F_7 ( 1 ) ;
}
if ( V_9 == V_15 ) {
F_8 ( V_16 L_1 ,
V_12 , ( V_8 ) ? L_2 : L_3 ) ;
} else {
F_9 ( L_4 ,
V_12 , ( V_8 ) ? L_2 : L_3 , V_9 ) ;
V_10 = 0 ;
}
return V_10 ;
}
static T_3 F_10 ( struct V_1 * V_1 , T_1 V_17 )
{
unsigned long V_18 ;
T_3 V_19 = 0 ;
V_18 = F_11 ( V_1 -> V_3 -> V_20 ) / V_17 ;
F_9 ( L_5 , V_18 ) ;
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
F_9 ( L_6 , V_17 ) ;
return V_19 ;
}
static int F_12 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_1 V_21 ;
T_1 V_8 = 1 ;
int V_22 = 0 ;
F_9 ( L_7 , F_6 ( V_1 ) ) ;
V_4 = V_1 -> V_3 ;
V_8 <<= F_3 ( V_4 -> V_13 ) ;
if ( ( F_2 ( V_4 -> V_14 ) & V_4 -> V_13 ) == V_8 )
goto V_23;
V_21 = F_13 ( V_1 ) ;
if ( V_21 )
F_14 ( V_1 ) ;
F_1 ( V_1 , V_24 ) ;
V_22 = F_5 ( V_1 , 1 ) ;
if ( V_21 )
F_15 ( V_1 ) ;
V_23:
return V_22 ;
}
static int F_16 ( struct V_1 * V_1 )
{
int V_22 ;
T_1 V_21 ;
if ( ! ( V_1 -> V_3 -> V_25 & ( 1 << V_26 ) ) )
return - V_11 ;
F_9 ( L_8 ,
F_6 ( V_1 ) ) ;
V_21 = F_13 ( V_1 ) ;
F_1 ( V_1 , V_26 ) ;
V_22 = F_5 ( V_1 , 0 ) ;
if ( V_21 )
F_15 ( V_1 ) ;
return V_22 ;
}
static int F_17 ( struct V_1 * V_1 )
{
T_1 V_21 ;
if ( ! ( V_1 -> V_3 -> V_25 & ( 1 << V_27 ) ) )
return - V_11 ;
F_9 ( L_9 , F_6 ( V_1 ) ) ;
V_21 = F_13 ( V_1 ) ;
F_1 ( V_1 , V_27 ) ;
if ( V_21 )
F_15 ( V_1 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_1 , T_1 * V_28 , T_3 V_29 , T_1 V_17 )
{
unsigned long V_18 , V_30 ;
V_30 = F_11 ( F_19 ( V_1 ) ) ;
V_18 = ( V_30 / V_17 ) * V_29 ;
if ( V_18 < 1000000000 )
* V_28 = 2 ;
else
* V_28 = 4 ;
}
static void F_20 ( struct V_1 * V_1 , T_1 * V_31 , T_3 V_29 , T_1 V_17 )
{
unsigned long V_30 , V_32 ;
int V_33 , V_34 ;
V_30 = F_11 ( F_19 ( V_1 ) ) ;
V_30 /= 100000 ;
V_33 = ( V_30 * V_29 ) % ( 250 * V_17 ) ;
V_32 = ( V_30 * V_29 ) / ( 250 * V_17 ) ;
V_34 = V_32 % 10 ;
V_32 /= 10 ;
if ( V_33 || V_34 )
V_32 ++ ;
* V_31 = V_32 ;
}
static int F_21 ( struct V_1 * V_1 , T_3 V_29 , T_1 V_17 , T_3 V_35 )
{
struct V_3 * V_4 = V_1 -> V_3 ;
T_1 V_28 , V_31 ;
T_2 V_5 ;
F_16 ( V_1 ) ;
if ( ! F_22 () && ! F_23 () && ! F_24 () ) {
V_5 = F_2 ( V_4 -> V_6 ) ;
V_5 &= ~ V_4 -> V_36 ;
V_5 |= V_35 << F_3 ( V_4 -> V_36 ) ;
F_4 ( V_5 , V_4 -> V_6 ) ;
}
V_5 = F_2 ( V_4 -> V_37 ) ;
V_5 &= ~ ( V_4 -> V_38 | V_4 -> V_39 ) ;
V_5 |= V_29 << F_3 ( V_4 -> V_38 ) ;
V_5 |= ( V_17 - 1 ) << F_3 ( V_4 -> V_39 ) ;
if ( V_4 -> V_40 ) {
F_18 ( V_1 , & V_28 , V_29 , V_17 ) ;
V_5 &= ~ ( V_4 -> V_40 ) ;
V_5 |= V_28 << F_3 ( V_4 -> V_40 ) ;
}
if ( V_4 -> V_41 ) {
F_20 ( V_1 , & V_31 , V_29 , V_17 ) ;
V_5 &= ~ ( V_4 -> V_41 ) ;
V_5 |= V_31 << F_3 ( V_4 -> V_41 ) ;
}
F_4 ( V_5 , V_4 -> V_37 ) ;
F_12 ( V_1 ) ;
return 0 ;
}
unsigned long F_25 ( struct V_1 * V_1 )
{
return F_26 ( V_1 ) ;
}
int F_27 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_3 * V_4 ;
struct V_1 * V_42 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return - V_11 ;
V_42 = F_19 ( V_1 ) ;
if ( F_11 ( V_1 ) == F_11 ( V_4 -> V_43 ) ) {
F_28 ( V_42 != V_4 -> V_43 ) ;
V_22 = F_16 ( V_1 ) ;
} else {
F_28 ( V_42 != V_4 -> V_20 ) ;
V_22 = F_12 ( V_1 ) ;
}
if ( ! V_22 )
V_1 -> V_44 = ( V_1 -> V_45 ) ? V_1 -> V_45 ( V_1 ) :
F_26 ( V_1 ) ;
return V_22 ;
}
void F_29 ( struct V_1 * V_1 )
{
F_17 ( V_1 ) ;
}
int F_30 ( struct V_1 * V_1 , unsigned long V_44 )
{
struct V_1 * V_46 = NULL ;
unsigned long V_47 , V_48 ;
T_3 V_35 = 0 ;
struct V_3 * V_4 ;
int V_10 ;
if ( ! V_1 || ! V_44 )
return - V_11 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 )
return - V_11 ;
V_47 = ( V_1 -> V_45 ) ? V_1 -> V_45 ( V_1 ) : F_26 ( V_1 ) ;
if ( V_44 == V_47 )
return 0 ;
F_31 ( V_4 -> V_43 ) ;
F_31 ( V_4 -> V_20 ) ;
V_48 = F_11 ( V_4 -> V_43 ) ;
if ( V_48 == V_44 &&
( V_1 -> V_3 -> V_25 & ( 1 << V_26 ) ) ) {
F_9 ( L_10 , V_1 -> V_49 ) ;
V_10 = F_16 ( V_1 ) ;
if ( ! V_10 )
V_46 = V_4 -> V_43 ;
} else {
if ( V_4 -> V_50 != V_44 )
V_44 = V_1 -> V_51 ( V_1 , V_44 ) ;
if ( V_4 -> V_50 == 0 )
return - V_11 ;
if ( ! F_22 () && ! F_23 () && ! F_24 () ) {
V_35 = F_10 ( V_1 ,
V_4 -> V_52 ) ;
if ( ! V_35 )
F_28 ( 1 ) ;
}
F_9 ( L_11 ,
F_6 ( V_1 ) , V_44 ) ;
V_10 = F_21 ( V_1 , V_4 -> V_53 ,
V_4 -> V_52 , V_35 ) ;
if ( ! V_10 )
V_46 = V_4 -> V_20 ;
}
if ( ! V_10 ) {
if ( V_1 -> V_54 ) {
F_31 ( V_46 ) ;
F_32 ( V_1 -> V_42 ) ;
}
F_33 ( V_1 , V_46 ) ;
V_1 -> V_44 = V_44 ;
}
F_32 ( V_4 -> V_20 ) ;
F_32 ( V_4 -> V_43 ) ;
return 0 ;
}
T_2 F_13 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
if ( ! V_1 || ! V_1 -> V_3 )
return - V_11 ;
V_4 = V_1 -> V_3 ;
if ( ! V_4 -> V_55 )
return - V_11 ;
V_5 = F_2 ( V_4 -> V_55 ) ;
V_5 &= V_4 -> V_56 ;
V_5 >>= F_3 ( V_4 -> V_56 ) ;
return V_5 ;
}
void F_15 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
if ( ! V_1 || ! V_1 -> V_3 )
return;
V_4 = V_1 -> V_3 ;
if ( ! V_4 -> V_55 ) {
F_9 ( L_12 ,
F_6 ( V_1 ) ) ;
return;
}
V_5 = F_2 ( V_4 -> V_55 ) ;
V_5 &= ~ V_4 -> V_56 ;
V_5 |= V_57 << F_3 ( V_4 -> V_56 ) ;
F_4 ( V_5 , V_4 -> V_55 ) ;
}
void F_14 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
if ( ! V_1 || ! V_1 -> V_3 )
return;
V_4 = V_1 -> V_3 ;
if ( ! V_4 -> V_55 ) {
F_9 ( L_12 ,
F_6 ( V_1 ) ) ;
return;
}
V_5 = F_2 ( V_4 -> V_55 ) ;
V_5 &= ~ V_4 -> V_56 ;
V_5 |= V_58 << F_3 ( V_4 -> V_56 ) ;
F_4 ( V_5 , V_4 -> V_55 ) ;
}
unsigned long F_34 ( struct V_1 * V_1 )
{
const struct V_3 * V_4 ;
unsigned long V_44 ;
T_2 V_5 ;
struct V_1 * V_59 ;
unsigned long V_60 ;
V_59 = F_19 ( V_1 ) ;
while ( V_59 && ! V_59 -> V_3 )
V_59 = F_19 ( V_59 ) ;
if ( ! V_59 ) {
F_28 ( 1 ) ;
return 0 ;
}
V_4 = V_59 -> V_3 ;
F_28 ( ! V_4 -> V_7 ) ;
V_60 = F_11 ( F_19 ( V_1 ) ) ;
V_5 = F_2 ( V_4 -> V_6 ) & V_4 -> V_7 ;
V_5 >>= F_3 ( V_4 -> V_7 ) ;
if ( ( V_5 != V_61 ) || ( V_4 -> V_62 & V_63 ) )
V_44 = V_60 ;
else
V_44 = V_60 * 2 ;
return V_44 ;
}
