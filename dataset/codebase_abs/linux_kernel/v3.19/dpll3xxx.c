static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
V_5 = V_2 -> V_4 ;
V_6 = F_2 ( V_2 , V_5 -> V_7 ) ;
V_6 &= ~ V_5 -> V_8 ;
V_6 |= V_3 << F_3 ( V_5 -> V_8 ) ;
F_4 ( V_6 , V_2 , V_5 -> V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
const struct V_4 * V_5 ;
int V_10 = 0 ;
int V_11 = - V_12 ;
const char * V_13 ;
V_5 = V_2 -> V_4 ;
V_13 = F_6 ( V_2 -> V_14 . V_2 ) ;
V_9 <<= F_3 ( V_5 -> V_15 ) ;
while ( ( ( F_2 ( V_2 , V_5 -> V_16 ) & V_5 -> V_15 )
!= V_9 ) && V_10 < V_17 ) {
V_10 ++ ;
F_7 ( 1 ) ;
}
if ( V_10 == V_17 ) {
F_8 ( V_18 L_1 ,
V_13 , ( V_9 ) ? L_2 : L_3 ) ;
} else {
F_9 ( L_4 ,
V_13 , ( V_9 ) ? L_2 : L_3 , V_10 ) ;
V_11 = 0 ;
}
return V_11 ;
}
static T_3 F_10 ( struct V_1 * V_2 , T_1 V_19 )
{
unsigned long V_20 ;
T_3 V_21 = 0 ;
V_20 = F_11 ( V_2 -> V_4 -> V_22 ) / V_19 ;
F_9 ( L_5 , V_20 ) ;
if ( V_20 >= 750000 && V_20 <= 1000000 )
V_21 = 0x3 ;
else if ( V_20 > 1000000 && V_20 <= 1250000 )
V_21 = 0x4 ;
else if ( V_20 > 1250000 && V_20 <= 1500000 )
V_21 = 0x5 ;
else if ( V_20 > 1500000 && V_20 <= 1750000 )
V_21 = 0x6 ;
else if ( V_20 > 1750000 && V_20 <= 2100000 )
V_21 = 0x7 ;
else if ( V_20 > 7500000 && V_20 <= 10000000 )
V_21 = 0xB ;
else if ( V_20 > 10000000 && V_20 <= 12500000 )
V_21 = 0xC ;
else if ( V_20 > 12500000 && V_20 <= 15000000 )
V_21 = 0xD ;
else if ( V_20 > 15000000 && V_20 <= 17500000 )
V_21 = 0xE ;
else if ( V_20 > 17500000 && V_20 <= 21000000 )
V_21 = 0xF ;
else
F_9 ( L_6 , V_19 ) ;
return V_21 ;
}
static int F_12 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_1 V_23 ;
T_1 V_9 = 1 ;
int V_24 = 0 ;
F_9 ( L_7 , F_6 ( V_2 -> V_14 . V_2 ) ) ;
V_5 = V_2 -> V_4 ;
V_9 <<= F_3 ( V_5 -> V_15 ) ;
if ( ( F_2 ( V_2 , V_5 -> V_16 ) & V_5 -> V_15 ) == V_9 )
goto V_25;
V_23 = F_13 ( V_2 ) ;
if ( V_23 )
F_14 ( V_2 ) ;
F_1 ( V_2 , V_26 ) ;
V_24 = F_5 ( V_2 , 1 ) ;
if ( V_23 )
F_15 ( V_2 ) ;
V_25:
return V_24 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_24 ;
T_1 V_23 ;
if ( ! ( V_2 -> V_4 -> V_27 & ( 1 << V_28 ) ) )
return - V_12 ;
F_9 ( L_8 ,
F_6 ( V_2 -> V_14 . V_2 ) ) ;
V_23 = F_13 ( V_2 ) ;
F_1 ( V_2 , V_28 ) ;
V_24 = F_5 ( V_2 , 0 ) ;
if ( V_23 )
F_15 ( V_2 ) ;
return V_24 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_23 ;
if ( ! ( V_2 -> V_4 -> V_27 & ( 1 << V_29 ) ) )
return - V_12 ;
F_9 ( L_9 , F_6 ( V_2 -> V_14 . V_2 ) ) ;
V_23 = F_13 ( V_2 ) ;
F_1 ( V_2 , V_29 ) ;
if ( V_23 )
F_15 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 * V_30 , T_3 V_31 , T_1 V_19 )
{
unsigned long V_20 , V_32 ;
V_32 = F_11 ( F_19 ( V_2 -> V_14 . V_2 ) ) ;
V_20 = ( V_32 / V_19 ) * V_31 ;
if ( V_20 < 1000000000 )
* V_30 = 2 ;
else
* V_30 = 4 ;
}
static void F_20 ( struct V_1 * V_2 , T_1 * V_33 , T_3 V_31 , T_1 V_19 )
{
unsigned long V_32 , V_34 ;
int V_35 , V_36 ;
V_32 = F_11 ( F_19 ( V_2 -> V_14 . V_2 ) ) ;
V_32 /= 100000 ;
V_35 = ( V_32 * V_31 ) % ( 250 * V_19 ) ;
V_34 = ( V_32 * V_31 ) / ( 250 * V_19 ) ;
V_36 = V_34 % 10 ;
V_34 /= 10 ;
if ( V_35 || V_36 )
V_34 ++ ;
* V_33 = V_34 ;
}
static int F_21 ( struct V_1 * V_2 , T_3 V_37 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
T_1 V_30 , V_33 ;
T_2 V_6 ;
F_16 ( V_2 ) ;
if ( V_38 . V_39 & V_40 ) {
V_6 = F_2 ( V_2 , V_5 -> V_7 ) ;
V_6 &= ~ V_5 -> V_41 ;
V_6 |= V_37 << F_3 ( V_5 -> V_41 ) ;
F_4 ( V_6 , V_2 , V_5 -> V_7 ) ;
}
V_6 = F_2 ( V_2 , V_5 -> V_42 ) ;
if ( V_5 -> V_43 ) {
if ( V_5 -> V_44 >= V_5 -> V_45 )
V_6 |= V_5 -> V_43 ;
else
V_6 &= ~ V_5 -> V_43 ;
}
V_6 &= ~ ( V_5 -> V_46 | V_5 -> V_47 ) ;
V_6 |= V_5 -> V_48 << F_3 ( V_5 -> V_46 ) ;
V_6 |= ( V_5 -> V_49 - 1 ) << F_3 ( V_5 -> V_47 ) ;
if ( V_5 -> V_50 ) {
F_18 ( V_2 , & V_30 , V_5 -> V_48 , V_5 -> V_49 ) ;
V_6 &= ~ ( V_5 -> V_50 ) ;
V_6 |= V_30 << F_3 ( V_5 -> V_50 ) ;
}
if ( V_5 -> V_51 ) {
F_20 ( V_2 , & V_33 , V_5 -> V_48 ,
V_5 -> V_49 ) ;
V_6 &= ~ ( V_5 -> V_51 ) ;
V_6 |= V_33 << F_3 ( V_5 -> V_51 ) ;
}
F_4 ( V_6 , V_2 , V_5 -> V_42 ) ;
if ( V_5 -> V_52 || V_5 -> V_53 ) {
V_6 = F_2 ( V_2 , V_5 -> V_7 ) ;
if ( V_5 -> V_52 ) {
if ( V_5 -> V_54 )
V_6 |= V_5 -> V_52 ;
else
V_6 &= ~ V_5 -> V_52 ;
}
if ( V_5 -> V_53 ) {
if ( V_5 -> V_55 )
V_6 |= V_5 -> V_53 ;
else
V_6 &= ~ V_5 -> V_53 ;
}
F_4 ( V_6 , V_2 , V_5 -> V_7 ) ;
}
F_12 ( V_2 ) ;
return 0 ;
}
unsigned long F_22 ( struct V_56 * V_14 , unsigned long V_57 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
return F_24 ( V_2 ) ;
}
int F_25 ( struct V_56 * V_14 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
int V_24 ;
struct V_4 * V_5 ;
struct V_2 * V_58 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_12 ;
if ( V_2 -> V_59 ) {
V_24 = F_26 ( V_2 -> V_59 , V_14 -> V_2 ) ;
if ( V_24 ) {
F_27 ( 1 ,
L_10 ,
V_60 , F_6 ( V_14 -> V_2 ) ,
V_2 -> V_59 -> V_61 , V_24 ) ;
return V_24 ;
}
}
V_58 = F_19 ( V_14 -> V_2 ) ;
if ( F_11 ( V_14 -> V_2 ) == F_11 ( V_5 -> V_62 ) ) {
F_28 ( V_58 != V_5 -> V_62 ) ;
V_24 = F_16 ( V_2 ) ;
} else {
F_28 ( V_58 != V_5 -> V_22 ) ;
V_24 = F_12 ( V_2 ) ;
}
return V_24 ;
}
void F_29 ( struct V_56 * V_14 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
F_17 ( V_2 ) ;
if ( V_2 -> V_59 )
F_30 ( V_2 -> V_59 , V_14 -> V_2 ) ;
}
long F_31 ( struct V_56 * V_14 , unsigned long V_63 ,
unsigned long * V_64 ,
struct V_56 * * V_65 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
struct V_4 * V_5 ;
if ( ! V_14 || ! V_63 )
return - V_12 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_12 ;
if ( F_11 ( V_5 -> V_62 ) == V_63 &&
( V_5 -> V_27 & ( 1 << V_28 ) ) ) {
* V_65 = F_32 ( V_5 -> V_62 ) ;
} else {
V_63 = F_33 ( V_14 , V_63 , V_64 ) ;
* V_65 = F_32 ( V_5 -> V_22 ) ;
}
* V_64 = V_63 ;
return V_63 ;
}
int F_34 ( struct V_56 * V_14 , T_1 V_66 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
int V_11 ;
if ( ! V_14 )
return - V_12 ;
if ( V_66 )
V_11 = F_16 ( V_2 ) ;
else
V_11 = F_12 ( V_2 ) ;
return V_11 ;
}
int F_35 ( struct V_56 * V_14 , unsigned long V_63 ,
unsigned long V_57 )
{
struct V_1 * V_2 = F_23 ( V_14 ) ;
struct V_4 * V_5 ;
T_3 V_37 = 0 ;
int V_11 ;
if ( ! V_14 || ! V_63 )
return - V_12 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_12 ;
if ( F_19 ( V_14 -> V_2 ) != V_5 -> V_22 )
return - V_12 ;
if ( V_5 -> V_44 == 0 )
return - V_12 ;
if ( V_38 . V_39 & V_40 ) {
V_37 = F_10 ( V_2 , V_5 -> V_49 ) ;
F_28 ( ! V_37 ) ;
}
F_9 ( L_11 , V_60 ,
F_6 ( V_14 -> V_2 ) , V_63 ) ;
V_11 = F_21 ( V_2 , V_37 ) ;
return V_11 ;
}
int F_36 ( struct V_56 * V_14 ,
unsigned long V_63 ,
unsigned long V_57 ,
T_1 V_66 )
{
int V_11 ;
if ( ! V_14 || ! V_63 )
return - V_12 ;
if ( V_66 )
V_11 = F_34 ( V_14 , V_66 ) ;
else
V_11 = F_35 ( V_14 , V_63 , V_57 ) ;
return V_11 ;
}
T_2 F_13 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_12 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 -> V_67 )
return - V_12 ;
V_6 = F_2 ( V_2 , V_5 -> V_67 ) ;
V_6 &= V_5 -> V_68 ;
V_6 >>= F_3 ( V_5 -> V_68 ) ;
return V_6 ;
}
void F_15 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_5 = V_2 -> V_4 ;
if ( ! V_5 -> V_67 )
return;
V_6 = F_2 ( V_2 , V_5 -> V_67 ) ;
V_6 &= ~ V_5 -> V_68 ;
V_6 |= V_69 << F_3 ( V_5 -> V_68 ) ;
F_4 ( V_6 , V_2 , V_5 -> V_67 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_5 = V_2 -> V_4 ;
if ( ! V_5 -> V_67 )
return;
V_6 = F_2 ( V_2 , V_5 -> V_67 ) ;
V_6 &= ~ V_5 -> V_68 ;
V_6 |= V_70 << F_3 ( V_5 -> V_68 ) ;
F_4 ( V_6 , V_2 , V_5 -> V_67 ) ;
}
static struct V_1 * F_37 ( struct V_56 * V_14 )
{
struct V_1 * V_71 = NULL ;
struct V_2 * V_58 ;
do {
do {
V_58 = F_19 ( V_14 -> V_2 ) ;
V_14 = F_32 ( V_58 ) ;
} while ( V_14 && ( F_38 ( V_14 -> V_2 ) & V_72 ) );
if ( ! V_14 )
break;
V_71 = F_23 ( V_14 ) ;
} while ( V_71 && ! V_71 -> V_4 );
if ( ! V_71 ) {
F_28 ( 1 ) ;
return NULL ;
}
return V_71 ;
}
unsigned long F_39 ( struct V_56 * V_14 ,
unsigned long V_57 )
{
const struct V_4 * V_5 ;
unsigned long V_63 ;
T_2 V_6 ;
struct V_1 * V_71 = NULL ;
if ( ! V_57 )
return 0 ;
V_71 = F_37 ( V_14 ) ;
if ( ! V_71 )
return 0 ;
V_5 = V_71 -> V_4 ;
F_28 ( ! V_5 -> V_8 ) ;
V_6 = F_2 ( V_71 , V_5 -> V_7 ) & V_5 -> V_8 ;
V_6 >>= F_3 ( V_5 -> V_8 ) ;
if ( ( V_6 != V_73 ) || ( V_5 -> V_39 & V_74 ) )
V_63 = V_57 ;
else
V_63 = V_57 * 2 ;
return V_63 ;
}
int F_40 ( struct V_56 * V_14 , unsigned long V_63 ,
unsigned long V_57 )
{
return 0 ;
}
long F_41 ( struct V_56 * V_14 , unsigned long V_63 ,
unsigned long * V_75 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
struct V_1 * V_71 = NULL ;
if ( ! * V_75 )
return 0 ;
V_71 = F_37 ( V_14 ) ;
if ( ! V_71 )
return 0 ;
V_5 = V_71 -> V_4 ;
if ( V_5 -> V_39 & V_74 ) {
* V_75 = F_42 ( F_19 ( V_71 -> V_14 . V_2 ) , V_63 ) ;
return * V_75 ;
}
F_28 ( ! V_5 -> V_8 ) ;
V_6 = F_2 ( V_71 , V_5 -> V_7 ) & V_5 -> V_8 ;
V_6 >>= F_3 ( V_5 -> V_8 ) ;
if ( V_6 != V_73 )
return * V_75 ;
if ( F_38 ( V_14 -> V_2 ) & V_76 ) {
unsigned long V_77 ;
V_77 = ( V_63 / 2 ) ;
* V_75 = F_42 ( F_19 ( V_14 -> V_2 ) ,
V_77 ) ;
}
return * V_75 * 2 ;
}
