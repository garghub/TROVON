static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
int V_6 ;
V_6 = F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return ( V_5 & V_11 ) == 0 ;
}
static T_2 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_12 = F_5 ( V_2 -> V_13 ) ;
T_1 V_14 ;
int V_15 , V_6 ;
V_6 = F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 , & V_14 ) ;
if ( V_6 )
return V_6 ;
V_14 &= V_17 ;
V_14 >>= V_18 ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
if ( V_14 == V_4 -> V_19 [ V_15 ] )
return V_15 ;
return - V_20 ;
}
static int F_6 ( struct V_3 * V_4 )
{
int V_21 , V_6 ;
T_1 V_5 ;
struct V_1 * V_2 = & V_4 -> V_7 . V_2 ;
const char * V_22 = F_7 ( V_2 -> V_13 ) ;
V_6 = F_8 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 ,
V_23 , V_23 ) ;
if ( V_6 )
return V_6 ;
for ( V_21 = 500 ; V_21 > 0 ; V_21 -- ) {
V_6 = F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_5 & V_23 ) )
return 0 ;
F_9 ( 1 ) ;
}
F_10 ( 1 , L_1 , V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
V_6 = F_8 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
V_17 ,
V_4 -> V_19 [ V_24 ] << V_18 ) ;
if ( V_6 )
return V_6 ;
return F_6 ( V_4 ) ;
}
static unsigned long
F_12 ( unsigned long V_25 , T_1 V_26 , T_1 V_27 , T_1 V_28 , T_1 V_29 )
{
if ( V_29 ) {
V_25 *= 2 ;
V_25 /= V_29 + 1 ;
}
if ( V_28 ) {
T_3 V_30 = V_25 ;
V_30 *= V_26 ;
F_13 ( V_30 , V_27 ) ;
V_25 = V_30 ;
}
return V_25 ;
}
static unsigned long
F_14 ( struct V_1 * V_2 , unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_14 , V_29 , V_26 = 0 , V_27 = 0 , V_28 = 0 , V_32 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 , & V_14 ) ;
if ( V_4 -> V_33 ) {
V_32 = F_15 ( V_4 -> V_33 ) - 1 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_34 , & V_26 ) ;
V_26 &= V_32 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_35 , & V_27 ) ;
V_27 = ~ V_27 ;
V_27 &= V_32 ;
V_27 += V_26 ;
V_28 = V_14 & V_36 ;
V_28 >>= V_37 ;
}
V_32 = F_15 ( V_4 -> V_38 ) - 1 ;
V_29 = V_14 >> V_39 ;
V_29 &= V_32 ;
return F_12 ( V_31 , V_26 , V_27 , V_28 , V_29 ) ;
}
static long F_16 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , unsigned long V_25 ,
unsigned long * V_42 , struct V_1 * * V_43 )
{
unsigned long V_44 ;
struct V_13 * V_45 ;
V_41 = F_17 ( V_41 , V_25 ) ;
if ( ! V_41 )
return - V_20 ;
V_44 = F_18 ( V_2 -> V_13 ) ;
V_45 = F_19 ( V_2 -> V_13 , V_41 -> V_46 ) ;
if ( V_44 & V_47 ) {
if ( V_41 -> V_48 ) {
V_25 /= 2 ;
V_25 *= V_41 -> V_48 + 1 ;
}
if ( V_41 -> V_27 ) {
T_3 V_30 = V_25 ;
V_30 = V_30 * V_41 -> V_27 ;
F_13 ( V_30 , V_41 -> V_26 ) ;
V_25 = V_30 ;
}
} else {
V_25 = F_20 ( V_45 ) ;
}
* V_43 = F_21 ( V_45 ) ;
* V_42 = V_25 ;
return V_41 -> V_49 ;
}
static long F_22 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long * V_42 , struct V_1 * * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_16 ( V_2 , V_4 -> V_40 , V_25 , V_42 , V_45 ) ;
}
static int F_23 ( struct V_3 * V_4 , const struct V_40 * V_41 )
{
T_1 V_14 , V_32 ;
int V_6 ;
if ( V_4 -> V_33 && V_41 -> V_27 ) {
V_32 = F_15 ( V_4 -> V_33 ) - 1 ;
V_6 = F_8 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_34 , V_32 , V_41 -> V_26 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_8 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_35 , V_32 , ~ ( V_41 -> V_27 - V_41 -> V_26 ) ) ;
if ( V_6 )
return V_6 ;
V_6 = F_8 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_50 , V_32 , ~ V_41 -> V_27 ) ;
if ( V_6 )
return V_6 ;
}
V_32 = F_15 ( V_4 -> V_38 ) - 1 ;
V_32 |= V_17 | V_36 ;
V_14 = V_41 -> V_48 << V_39 ;
V_14 |= V_4 -> V_19 [ V_41 -> V_46 ] << V_18 ;
if ( V_4 -> V_33 && V_41 -> V_27 )
V_14 |= V_51 ;
V_6 = F_8 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_16 , V_32 , V_14 ) ;
if ( V_6 )
return V_6 ;
return F_6 ( V_4 ) ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_40 * V_41 ;
V_41 = F_17 ( V_4 -> V_40 , V_25 ) ;
if ( ! V_41 )
return - V_20 ;
return F_23 ( V_4 , V_41 ) ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
return F_24 ( V_2 , V_25 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_24 ( V_2 , V_25 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 V_41 = * V_4 -> V_40 ;
const struct V_52 * V_53 ;
int V_54 = 100000 ;
T_4 V_55 = V_31 ;
T_4 V_56 ;
T_1 V_32 = F_15 ( V_4 -> V_38 ) - 1 ;
T_1 V_29 ;
if ( V_55 == 810000000 )
V_53 = V_57 ;
else
V_53 = V_58 ;
for (; V_53 -> V_59 ; V_53 ++ ) {
V_56 = V_25 ;
V_56 *= V_53 -> V_60 ;
V_56 = F_28 ( V_56 , V_53 -> V_59 ) ;
if ( ( V_55 < ( V_56 - V_54 ) ) ||
( V_55 > ( V_56 + V_54 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
& V_29 ) ;
V_41 . V_48 = V_29 ;
V_41 . V_48 >>= V_39 ;
V_41 . V_48 &= V_32 ;
V_41 . V_26 = V_53 -> V_59 ;
V_41 . V_27 = V_53 -> V_60 ;
return F_23 ( V_4 , & V_41 ) ;
}
return - V_20 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_27 ( V_2 , V_25 , V_31 ) ;
}
static long F_30 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long * V_42 , struct V_1 * * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_40 * V_41 = V_4 -> V_40 ;
const struct V_52 * V_53 ;
int V_54 = 100000 ;
T_4 V_55 = * V_42 ;
T_4 V_56 ;
T_1 V_32 = F_15 ( V_4 -> V_38 ) - 1 ;
T_1 V_29 ;
* V_45 = F_21 ( F_19 ( V_2 -> V_13 , V_41 -> V_46 ) ) ;
if ( V_55 == 810000000 )
V_53 = V_57 ;
else
V_53 = V_58 ;
for (; V_53 -> V_59 ; V_53 ++ ) {
V_56 = V_25 ;
V_56 *= V_53 -> V_60 ;
V_56 = F_28 ( V_56 , V_53 -> V_59 ) ;
if ( ( V_55 < ( V_56 - V_54 ) ) ||
( V_55 > ( V_56 + V_54 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
& V_29 ) ;
V_29 >>= V_39 ;
V_29 &= V_32 ;
return F_12 ( V_55 , V_53 -> V_59 , V_53 -> V_60 , ! ! V_53 -> V_60 ,
V_29 ) ;
}
return - V_20 ;
}
static long F_31 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long * V_42 , struct V_1 * * V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_40 * V_41 = V_4 -> V_40 ;
unsigned long V_31 , div ;
T_1 V_32 = F_15 ( V_4 -> V_38 ) - 1 ;
struct V_13 * V_45 ;
if ( V_25 == 0 )
return - V_20 ;
V_45 = F_19 ( V_2 -> V_13 , V_41 -> V_46 ) ;
* V_43 = F_21 ( V_45 ) ;
* V_42 = V_31 = F_32 ( V_45 , V_25 ) ;
div = F_33 ( ( 2 * V_31 ) , V_25 ) - 1 ;
div = F_34 ( T_1 , div , V_32 ) ;
return F_12 ( V_31 , 0 , 0 , 0 , div ) ;
}
static int F_35 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 V_41 = * V_4 -> V_40 ;
unsigned long div ;
T_1 V_32 = F_15 ( V_4 -> V_38 ) - 1 ;
div = F_33 ( ( 2 * V_31 ) , V_25 ) - 1 ;
div = F_34 ( T_1 , div , V_32 ) ;
V_41 . V_48 = div ;
return F_23 ( V_4 , & V_41 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
unsigned long V_25 , unsigned long V_31 , T_2 V_24 )
{
return F_35 ( V_2 , V_25 , V_31 ) ;
}
static long F_37 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long * V_42 , struct V_1 * * V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_56 , V_55 ;
int V_54 = 100000 ;
const struct V_40 * V_41 = V_4 -> V_40 ;
const struct V_52 * V_53 = V_61 ;
struct V_13 * V_62 = F_19 ( V_2 -> V_13 , V_41 -> V_46 ) ;
* V_45 = F_21 ( V_62 ) ;
for (; V_53 -> V_59 ; V_53 ++ ) {
V_56 = ( V_25 * V_53 -> V_60 ) / V_53 -> V_59 ;
V_55 = F_32 ( V_62 , V_56 ) ;
if ( ( V_55 < ( V_56 - V_54 ) ) ||
( V_55 > ( V_56 + V_54 ) ) )
continue;
* V_42 = V_55 ;
return ( V_55 * V_53 -> V_59 ) / V_53 -> V_60 ;
}
return - V_20 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_40 V_41 = * V_4 -> V_40 ;
const struct V_52 * V_53 = V_61 ;
unsigned long V_56 , V_55 ;
int V_54 = 100000 ;
T_1 V_32 = F_15 ( V_4 -> V_38 ) - 1 ;
T_1 V_29 ;
struct V_13 * V_62 = F_19 ( V_2 -> V_13 , V_41 . V_46 ) ;
for (; V_53 -> V_59 ; V_53 ++ ) {
V_56 = ( V_25 * V_53 -> V_60 ) / V_53 -> V_59 ;
V_55 = F_32 ( V_62 , V_56 ) ;
if ( ( V_55 < ( V_56 - V_54 ) ) ||
( V_55 > ( V_56 + V_54 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
& V_29 ) ;
V_41 . V_48 = V_29 ;
V_41 . V_48 >>= V_39 ;
V_41 . V_48 &= V_32 ;
V_41 . V_26 = V_53 -> V_59 ;
V_41 . V_27 = V_53 -> V_60 ;
return F_23 ( V_4 , & V_41 ) ;
}
return - V_20 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned long V_25 ,
unsigned long V_31 , T_2 V_24 )
{
return F_38 ( V_2 , V_25 , V_31 ) ;
}
