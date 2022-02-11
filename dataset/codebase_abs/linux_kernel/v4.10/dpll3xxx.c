static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
V_5 = V_2 -> V_4 ;
V_6 = V_7 -> V_8 ( V_5 -> V_9 ) ;
V_6 &= ~ V_5 -> V_10 ;
V_6 |= V_3 << F_2 ( V_5 -> V_10 ) ;
V_7 -> V_11 ( V_6 , V_5 -> V_9 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_12 )
{
const struct V_4 * V_5 ;
int V_13 = 0 ;
int V_14 = - V_15 ;
const char * V_16 ;
V_5 = V_2 -> V_4 ;
V_16 = F_4 ( & V_2 -> V_17 ) ;
V_12 <<= F_2 ( V_5 -> V_18 ) ;
while ( ( ( V_7 -> V_8 ( V_5 -> V_19 ) & V_5 -> V_18 )
!= V_12 ) && V_13 < V_20 ) {
V_13 ++ ;
F_5 ( 1 ) ;
}
if ( V_13 == V_20 ) {
F_6 ( L_1 ,
V_16 , ( V_12 ) ? L_2 : L_3 ) ;
} else {
F_7 ( L_4 ,
V_16 , ( V_12 ) ? L_2 : L_3 , V_13 ) ;
V_14 = 0 ;
}
return V_14 ;
}
static T_3 F_8 ( struct V_1 * V_2 , T_1 V_21 )
{
unsigned long V_22 ;
T_3 V_23 = 0 ;
V_22 = F_9 ( V_2 -> V_4 -> V_24 ) / V_21 ;
F_7 ( L_5 , V_22 ) ;
if ( V_22 >= 750000 && V_22 <= 1000000 )
V_23 = 0x3 ;
else if ( V_22 > 1000000 && V_22 <= 1250000 )
V_23 = 0x4 ;
else if ( V_22 > 1250000 && V_22 <= 1500000 )
V_23 = 0x5 ;
else if ( V_22 > 1500000 && V_22 <= 1750000 )
V_23 = 0x6 ;
else if ( V_22 > 1750000 && V_22 <= 2100000 )
V_23 = 0x7 ;
else if ( V_22 > 7500000 && V_22 <= 10000000 )
V_23 = 0xB ;
else if ( V_22 > 10000000 && V_22 <= 12500000 )
V_23 = 0xC ;
else if ( V_22 > 12500000 && V_22 <= 15000000 )
V_23 = 0xD ;
else if ( V_22 > 15000000 && V_22 <= 17500000 )
V_23 = 0xE ;
else if ( V_22 > 17500000 && V_22 <= 21000000 )
V_23 = 0xF ;
else
F_7 ( L_6 , V_21 ) ;
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_1 V_25 ;
T_1 V_12 = 1 ;
int V_26 = 0 ;
F_7 ( L_7 , F_4 ( & V_2 -> V_17 ) ) ;
V_5 = V_2 -> V_4 ;
V_12 <<= F_2 ( V_5 -> V_18 ) ;
if ( ( V_7 -> V_8 ( V_5 -> V_19 ) & V_5 -> V_18 ) ==
V_12 )
goto V_27;
V_25 = F_11 ( V_2 ) ;
if ( V_25 )
F_12 ( V_2 ) ;
F_1 ( V_2 , V_28 ) ;
V_26 = F_3 ( V_2 , 1 ) ;
if ( V_25 )
F_13 ( V_2 ) ;
V_27:
return V_26 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_26 ;
T_1 V_25 ;
if ( ! ( V_2 -> V_4 -> V_29 & ( 1 << V_30 ) ) )
return - V_15 ;
F_7 ( L_8 ,
F_4 ( & V_2 -> V_17 ) ) ;
V_25 = F_11 ( V_2 ) ;
F_1 ( V_2 , V_30 ) ;
V_26 = F_3 ( V_2 , 0 ) ;
if ( V_25 )
F_13 ( V_2 ) ;
return V_26 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_25 ;
if ( ! ( V_2 -> V_4 -> V_29 & ( 1 << V_31 ) ) )
return - V_15 ;
F_7 ( L_9 , F_4 ( & V_2 -> V_17 ) ) ;
V_25 = F_11 ( V_2 ) ;
F_1 ( V_2 , V_31 ) ;
if ( V_25 )
F_13 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 * V_32 , T_3 V_33 , T_1 V_21 )
{
unsigned long V_22 , V_34 ;
V_34 = F_9 ( F_17 ( & V_2 -> V_17 ) ) ;
V_22 = ( V_34 / V_21 ) * V_33 ;
if ( V_22 < 1000000000 )
* V_32 = 2 ;
else
* V_32 = 4 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 * V_35 , T_3 V_33 , T_1 V_21 )
{
unsigned long V_34 , V_36 ;
int V_37 , V_38 ;
V_34 = F_9 ( F_17 ( & V_2 -> V_17 ) ) ;
V_34 /= 100000 ;
V_37 = ( V_34 * V_33 ) % ( 250 * V_21 ) ;
V_36 = ( V_34 * V_33 ) / ( 250 * V_21 ) ;
V_38 = V_36 % 10 ;
V_36 /= 10 ;
if ( V_37 || V_38 )
V_36 ++ ;
* V_35 = V_36 ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_39 )
{
struct V_4 * V_5 = V_2 -> V_4 ;
T_1 V_32 , V_35 , V_25 = 0 ;
T_2 V_6 ;
bool V_40 ;
F_14 ( V_2 ) ;
if ( F_20 () -> V_41 & V_42 ) {
V_6 = V_7 -> V_8 ( V_5 -> V_9 ) ;
V_6 &= ~ V_5 -> V_43 ;
V_6 |= V_39 << F_2 ( V_5 -> V_43 ) ;
V_7 -> V_11 ( V_6 , V_5 -> V_9 ) ;
}
V_6 = V_7 -> V_8 ( V_5 -> V_44 ) ;
if ( V_5 -> V_45 ) {
if ( V_5 -> V_46 >= V_5 -> V_47 )
V_6 |= V_5 -> V_45 ;
else
V_6 &= ~ V_5 -> V_45 ;
}
V_6 &= ~ ( V_5 -> V_48 | V_5 -> V_49 ) ;
V_6 |= V_5 -> V_50 << F_2 ( V_5 -> V_48 ) ;
V_6 |= ( V_5 -> V_51 - 1 ) << F_2 ( V_5 -> V_49 ) ;
if ( V_5 -> V_52 ) {
F_16 ( V_2 , & V_32 , V_5 -> V_50 , V_5 -> V_51 ) ;
V_6 &= ~ ( V_5 -> V_52 ) ;
V_6 |= V_32 << F_2 ( V_5 -> V_52 ) ;
}
if ( V_5 -> V_53 ) {
F_18 ( V_2 , & V_35 , V_5 -> V_50 ,
V_5 -> V_51 ) ;
V_6 &= ~ ( V_5 -> V_53 ) ;
V_6 |= V_35 << F_2 ( V_5 -> V_53 ) ;
}
V_40 = F_20 () -> V_41 & V_54 ;
if ( V_40 ) {
V_25 = F_11 ( V_2 ) ;
if ( V_25 ) {
F_12 ( V_2 ) ;
F_11 ( V_2 ) ;
}
}
V_7 -> V_11 ( V_6 , V_5 -> V_44 ) ;
if ( V_5 -> V_55 || V_5 -> V_56 ) {
V_6 = V_7 -> V_8 ( V_5 -> V_9 ) ;
if ( V_5 -> V_55 ) {
if ( V_5 -> V_57 )
V_6 |= V_5 -> V_55 ;
else
V_6 &= ~ V_5 -> V_55 ;
}
if ( V_5 -> V_56 ) {
if ( V_5 -> V_58 )
V_6 |= V_5 -> V_56 ;
else
V_6 &= ~ V_5 -> V_56 ;
}
V_7 -> V_11 ( V_6 , V_5 -> V_9 ) ;
}
F_10 ( V_2 ) ;
if ( V_40 && V_25 )
F_13 ( V_2 ) ;
return 0 ;
}
unsigned long F_21 ( struct V_59 * V_17 , unsigned long V_60 )
{
struct V_1 * V_2 = F_22 ( V_17 ) ;
return F_23 ( V_2 ) ;
}
int F_24 ( struct V_59 * V_17 )
{
struct V_1 * V_2 = F_22 ( V_17 ) ;
int V_26 ;
struct V_4 * V_5 ;
struct V_59 * V_61 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_15 ;
if ( V_2 -> V_62 ) {
V_26 = V_7 -> V_63 ( V_2 -> V_62 , V_17 -> V_2 ) ;
if ( V_26 ) {
F_25 ( 1 ,
L_10 ,
V_64 , F_4 ( V_17 ) ,
V_2 -> V_65 , V_26 ) ;
return V_26 ;
}
}
V_61 = F_17 ( V_17 ) ;
if ( F_9 ( V_17 ) == F_9 ( V_5 -> V_66 ) ) {
F_26 ( V_61 != V_5 -> V_66 ) ;
V_26 = F_14 ( V_2 ) ;
} else {
F_26 ( V_61 != V_5 -> V_24 ) ;
V_26 = F_10 ( V_2 ) ;
}
return V_26 ;
}
void F_27 ( struct V_59 * V_17 )
{
struct V_1 * V_2 = F_22 ( V_17 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_62 )
V_7 -> V_67 ( V_2 -> V_62 , V_17 -> V_2 ) ;
}
int F_28 ( struct V_59 * V_17 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_22 ( V_17 ) ;
struct V_4 * V_5 ;
if ( ! V_69 -> V_70 )
return - V_15 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_15 ;
if ( F_9 ( V_5 -> V_66 ) == V_69 -> V_70 &&
( V_5 -> V_29 & ( 1 << V_30 ) ) ) {
V_69 -> V_71 = V_5 -> V_66 ;
} else {
V_69 -> V_70 = F_29 ( V_17 , V_69 -> V_70 ,
& V_69 -> V_72 ) ;
V_69 -> V_71 = V_5 -> V_24 ;
}
V_69 -> V_72 = V_69 -> V_70 ;
return 0 ;
}
int F_30 ( struct V_59 * V_17 , T_1 V_73 )
{
struct V_1 * V_2 = F_22 ( V_17 ) ;
int V_14 ;
if ( ! V_17 )
return - V_15 ;
if ( V_73 )
V_14 = F_14 ( V_2 ) ;
else
V_14 = F_10 ( V_2 ) ;
return V_14 ;
}
int F_31 ( struct V_59 * V_17 , unsigned long V_70 ,
unsigned long V_60 )
{
struct V_1 * V_2 = F_22 ( V_17 ) ;
struct V_4 * V_5 ;
T_3 V_39 = 0 ;
int V_14 ;
if ( ! V_17 || ! V_70 )
return - V_15 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 )
return - V_15 ;
if ( F_17 ( V_17 ) != V_5 -> V_24 )
return - V_15 ;
if ( V_5 -> V_46 == 0 )
return - V_15 ;
if ( F_20 () -> V_41 & V_42 ) {
V_39 = F_8 ( V_2 , V_5 -> V_51 ) ;
F_26 ( ! V_39 ) ;
}
F_7 ( L_11 , V_64 ,
F_4 ( V_17 ) , V_70 ) ;
V_14 = F_19 ( V_2 , V_39 ) ;
return V_14 ;
}
int F_32 ( struct V_59 * V_17 ,
unsigned long V_70 ,
unsigned long V_60 ,
T_1 V_73 )
{
int V_14 ;
if ( ! V_17 || ! V_70 )
return - V_15 ;
if ( V_73 )
V_14 = F_30 ( V_17 , V_73 ) ;
else
V_14 = F_31 ( V_17 , V_70 , V_60 ) ;
return V_14 ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
if ( ! V_2 || ! V_2 -> V_4 )
return - V_15 ;
V_5 = V_2 -> V_4 ;
if ( ! V_5 -> V_74 )
return - V_15 ;
V_6 = V_7 -> V_8 ( V_5 -> V_74 ) ;
V_6 &= V_5 -> V_75 ;
V_6 >>= F_2 ( V_5 -> V_75 ) ;
return V_6 ;
}
static void F_13 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_5 = V_2 -> V_4 ;
if ( ! V_5 -> V_74 )
return;
V_6 = V_7 -> V_8 ( V_5 -> V_74 ) ;
V_6 &= ~ V_5 -> V_75 ;
V_6 |= V_76 << F_2 ( V_5 -> V_75 ) ;
V_7 -> V_11 ( V_6 , V_5 -> V_74 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
const struct V_4 * V_5 ;
T_2 V_6 ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_5 = V_2 -> V_4 ;
if ( ! V_5 -> V_74 )
return;
V_6 = V_7 -> V_8 ( V_5 -> V_74 ) ;
V_6 &= ~ V_5 -> V_75 ;
V_6 |= V_77 << F_2 ( V_5 -> V_75 ) ;
V_7 -> V_11 ( V_6 , V_5 -> V_74 ) ;
}
static struct V_1 * F_33 ( struct V_59 * V_17 )
{
struct V_1 * V_78 = NULL ;
do {
do {
V_17 = F_17 ( V_17 ) ;
} while ( V_17 && ( F_34 ( V_17 ) & V_79 ) );
if ( ! V_17 )
break;
V_78 = F_22 ( V_17 ) ;
} while ( V_78 && ! V_78 -> V_4 );
if ( ! V_78 ) {
F_26 ( 1 ) ;
return NULL ;
}
return V_78 ;
}
unsigned long F_35 ( struct V_59 * V_17 ,
unsigned long V_60 )
{
const struct V_4 * V_5 ;
unsigned long V_70 ;
T_2 V_6 ;
struct V_1 * V_78 = NULL ;
if ( ! V_60 )
return 0 ;
V_78 = F_33 ( V_17 ) ;
if ( ! V_78 )
return 0 ;
V_5 = V_78 -> V_4 ;
F_26 ( ! V_5 -> V_10 ) ;
V_6 = V_7 -> V_8 ( V_5 -> V_9 ) & V_5 -> V_10 ;
V_6 >>= F_2 ( V_5 -> V_10 ) ;
if ( ( V_6 != V_80 ) || ( V_5 -> V_41 & V_81 ) )
V_70 = V_60 ;
else
V_70 = V_60 * 2 ;
return V_70 ;
}
int F_36 ( struct V_59 * V_17 , unsigned long V_70 ,
unsigned long V_60 )
{
if ( F_20 () -> V_41 & V_82 ) {
F_6 ( L_12 ) ;
return - V_15 ;
}
return F_31 ( V_17 , V_70 , V_60 ) ;
}
int F_37 ( struct V_59 * V_17 , unsigned long V_70 ,
unsigned long V_60 , T_1 V_73 )
{
if ( F_20 () -> V_41 & V_82 ) {
F_6 ( L_12 ) ;
return - V_15 ;
}
return F_32 ( V_17 , V_70 , V_60 ,
V_73 ) ;
}
static bool F_38 ( struct V_59 * V_17 ,
unsigned long V_60 )
{
struct V_83 {
unsigned int V_70 , V_33 , V_21 ;
};
static const struct V_83 V_84 [] = {
{ 12000000 , 80 , 0 + 1 } ,
{ 13000000 , 443 , 5 + 1 } ,
{ 19200000 , 50 , 0 + 1 } ,
{ 26000000 , 443 , 11 + 1 } ,
{ 38400000 , 25 , 0 + 1 }
} ;
const struct V_83 * V_85 ;
struct V_1 * V_2 = F_22 ( V_17 ) ;
struct V_4 * V_5 ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_39 ( V_84 ) ; ++ V_13 ) {
if ( V_60 == V_84 [ V_13 ] . V_70 )
break;
}
if ( V_13 == F_39 ( V_84 ) )
return false ;
V_85 = & V_84 [ V_13 ] ;
V_5 = V_2 -> V_4 ;
V_5 -> V_50 = V_85 -> V_33 ;
V_5 -> V_51 = V_85 -> V_21 ;
V_5 -> V_46 = F_40 ( ( V_86 ) V_60 * V_85 -> V_33 , V_85 -> V_21 ) ;
F_19 ( V_2 , 0 ) ;
return true ;
}
int F_41 ( struct V_59 * V_17 , unsigned long V_70 ,
unsigned long V_60 )
{
if ( V_70 == V_87 * 8 ) {
if ( F_38 ( V_17 , V_60 ) )
return 0 ;
}
return F_31 ( V_17 , V_70 , V_60 ) ;
}
