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
goto V_17;
V_14 &= V_18 ;
V_14 >>= V_19 ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
if ( V_14 == V_4 -> V_20 [ V_15 ] . V_14 )
return V_15 ;
V_17:
F_6 ( L_1 ,
V_21 , F_7 ( V_2 -> V_13 ) ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
int V_22 , V_6 ;
T_1 V_5 ;
struct V_1 * V_2 = & V_4 -> V_7 . V_2 ;
const char * V_23 = F_7 ( V_2 -> V_13 ) ;
V_6 = F_9 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 ,
V_24 , V_24 ) ;
if ( V_6 )
return V_6 ;
for ( V_22 = 500 ; V_22 > 0 ; V_22 -- ) {
V_6 = F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_10 , & V_5 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_5 & V_24 ) )
return 0 ;
F_10 ( 1 ) ;
}
F_11 ( 1 , L_2 , V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
T_1 V_14 = V_4 -> V_20 [ V_25 ] . V_14 << V_19 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
V_18 , V_14 ) ;
if ( V_6 )
return V_6 ;
return F_8 ( V_4 ) ;
}
static unsigned long
F_13 ( unsigned long V_26 , T_1 V_27 , T_1 V_28 , T_1 V_29 , T_1 V_30 )
{
if ( V_30 ) {
V_26 *= 2 ;
V_26 /= V_30 + 1 ;
}
if ( V_29 ) {
T_3 V_31 = V_26 ;
V_31 *= V_27 ;
F_14 ( V_31 , V_28 ) ;
V_26 = V_31 ;
}
return V_26 ;
}
static unsigned long
F_15 ( struct V_1 * V_2 , unsigned long V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_14 , V_30 , V_27 = 0 , V_28 = 0 , V_29 = 0 , V_33 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 , & V_14 ) ;
if ( V_4 -> V_34 ) {
V_33 = F_16 ( V_4 -> V_34 ) - 1 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_35 , & V_27 ) ;
V_27 &= V_33 ;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_36 , & V_28 ) ;
V_28 = ~ V_28 ;
V_28 &= V_33 ;
V_28 += V_27 ;
V_29 = V_14 & V_37 ;
V_29 >>= V_38 ;
}
V_33 = F_16 ( V_4 -> V_39 ) - 1 ;
V_30 = V_14 >> V_40 ;
V_30 &= V_33 ;
return F_13 ( V_32 , V_27 , V_28 , V_29 , V_30 ) ;
}
static long F_17 ( struct V_1 * V_2 ,
const struct V_41 * V_42 , unsigned long V_26 ,
unsigned long * V_43 , struct V_1 * * V_44 )
{
unsigned long V_45 ;
struct V_13 * V_46 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
V_42 = F_18 ( V_42 , V_26 ) ;
if ( ! V_42 )
return - V_47 ;
V_25 = F_19 ( V_2 , V_4 -> V_20 , V_42 -> V_48 ) ;
if ( V_25 < 0 )
return V_25 ;
V_45 = F_20 ( V_2 -> V_13 ) ;
V_46 = F_21 ( V_2 -> V_13 , V_25 ) ;
if ( V_45 & V_49 ) {
if ( V_42 -> V_50 ) {
V_26 /= 2 ;
V_26 *= V_42 -> V_50 + 1 ;
}
if ( V_42 -> V_28 ) {
T_3 V_31 = V_26 ;
V_31 = V_31 * V_42 -> V_28 ;
F_14 ( V_31 , V_42 -> V_27 ) ;
V_26 = V_31 ;
}
} else {
V_26 = F_22 ( V_46 ) ;
}
* V_44 = F_23 ( V_46 ) ;
* V_43 = V_26 ;
return V_42 -> V_51 ;
}
static long F_24 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_52 , unsigned long V_53 ,
unsigned long * V_43 , struct V_1 * * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_17 ( V_2 , V_4 -> V_41 , V_26 , V_43 , V_46 ) ;
}
static int F_25 ( struct V_3 * V_4 , const struct V_41 * V_42 )
{
T_1 V_14 , V_33 ;
struct V_1 * V_2 = & V_4 -> V_7 . V_2 ;
int V_6 , V_25 = F_19 ( V_2 , V_4 -> V_20 , V_42 -> V_48 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_4 -> V_34 && V_42 -> V_28 ) {
V_33 = F_16 ( V_4 -> V_34 ) - 1 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_35 , V_33 , V_42 -> V_27 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_36 , V_33 , ~ ( V_42 -> V_28 - V_42 -> V_27 ) ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_54 , V_33 , ~ V_42 -> V_28 ) ;
if ( V_6 )
return V_6 ;
}
V_33 = F_16 ( V_4 -> V_39 ) - 1 ;
V_33 |= V_18 | V_37 ;
V_14 = V_42 -> V_50 << V_40 ;
V_14 |= V_4 -> V_20 [ V_25 ] . V_14 << V_19 ;
if ( V_4 -> V_34 && V_42 -> V_28 && ( V_42 -> V_27 != V_42 -> V_28 ) )
V_14 |= V_55 ;
V_6 = F_9 ( V_4 -> V_7 . V_8 ,
V_4 -> V_9 + V_16 , V_33 , V_14 ) ;
if ( V_6 )
return V_6 ;
return F_8 ( V_4 ) ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long V_26 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_41 * V_42 ;
V_42 = F_18 ( V_4 -> V_41 , V_26 ) ;
if ( ! V_42 )
return - V_47 ;
return F_25 ( V_4 , V_42 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_32 )
{
return F_26 ( V_2 , V_26 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned long V_26 , unsigned long V_32 , T_2 V_25 )
{
return F_26 ( V_2 , V_26 ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_41 V_42 = * V_4 -> V_41 ;
const struct V_56 * V_57 ;
int V_58 = 100000 ;
T_4 V_59 = V_32 ;
T_4 V_60 ;
T_1 V_33 = F_16 ( V_4 -> V_39 ) - 1 ;
T_1 V_30 ;
if ( V_59 == 810000000 )
V_57 = V_61 ;
else
V_57 = V_62 ;
for (; V_57 -> V_63 ; V_57 ++ ) {
V_60 = V_26 ;
V_60 *= V_57 -> V_64 ;
V_60 = F_30 ( V_60 , V_57 -> V_63 ) ;
if ( ( V_59 < ( V_60 - V_58 ) ) ||
( V_59 > ( V_60 + V_58 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
& V_30 ) ;
V_42 . V_50 = V_30 ;
V_42 . V_50 >>= V_40 ;
V_42 . V_50 &= V_33 ;
V_42 . V_27 = V_57 -> V_63 ;
V_42 . V_28 = V_57 -> V_64 ;
return F_25 ( V_4 , & V_42 ) ;
}
return - V_47 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned long V_26 , unsigned long V_32 , T_2 V_25 )
{
return F_29 ( V_2 , V_26 , V_32 ) ;
}
static long F_32 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_52 ,
unsigned long V_53 ,
unsigned long * V_43 , struct V_1 * * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_41 * V_42 = V_4 -> V_41 ;
const struct V_56 * V_57 ;
int V_58 = 100000 ;
T_4 V_59 = * V_43 ;
T_4 V_60 ;
T_1 V_33 = F_16 ( V_4 -> V_39 ) - 1 ;
T_1 V_30 ;
int V_25 = F_19 ( V_2 , V_4 -> V_20 , V_42 -> V_48 ) ;
* V_46 = F_23 ( F_21 ( V_2 -> V_13 , V_25 ) ) ;
if ( V_59 == 810000000 )
V_57 = V_61 ;
else
V_57 = V_62 ;
for (; V_57 -> V_63 ; V_57 ++ ) {
V_60 = V_26 ;
V_60 *= V_57 -> V_64 ;
V_60 = F_30 ( V_60 , V_57 -> V_63 ) ;
if ( ( V_59 < ( V_60 - V_58 ) ) ||
( V_59 > ( V_60 + V_58 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
& V_30 ) ;
V_30 >>= V_40 ;
V_30 &= V_33 ;
return F_13 ( V_59 , V_57 -> V_63 , V_57 -> V_64 , ! ! V_57 -> V_64 ,
V_30 ) ;
}
return - V_47 ;
}
static long F_33 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_52 , unsigned long V_53 ,
unsigned long * V_43 , struct V_1 * * V_44 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_41 * V_42 = V_4 -> V_41 ;
int V_25 = F_19 ( V_2 , V_4 -> V_20 , V_42 -> V_48 ) ;
unsigned long V_32 , div ;
T_1 V_33 = F_16 ( V_4 -> V_39 ) - 1 ;
struct V_13 * V_46 ;
if ( V_26 == 0 )
return - V_47 ;
V_46 = F_21 ( V_2 -> V_13 , V_25 ) ;
* V_44 = F_23 ( V_46 ) ;
* V_43 = V_32 = F_34 ( V_46 , V_26 ) ;
div = F_35 ( ( 2 * V_32 ) , V_26 ) - 1 ;
div = F_36 ( T_1 , div , V_33 ) ;
return F_13 ( V_32 , 0 , 0 , 0 , div ) ;
}
static int F_37 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_41 V_42 = * V_4 -> V_41 ;
unsigned long div ;
T_1 V_33 = F_16 ( V_4 -> V_39 ) - 1 ;
div = F_35 ( ( 2 * V_32 ) , V_26 ) - 1 ;
div = F_36 ( T_1 , div , V_33 ) ;
V_42 . V_50 = div ;
return F_25 ( V_4 , & V_42 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned long V_26 , unsigned long V_32 , T_2 V_25 )
{
return F_37 ( V_2 , V_26 , V_32 ) ;
}
static long F_39 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_52 ,
unsigned long V_53 ,
unsigned long * V_43 , struct V_1 * * V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_60 , V_59 ;
int V_58 = 100000 ;
const struct V_41 * V_42 = V_4 -> V_41 ;
const struct V_56 * V_57 = V_65 ;
int V_25 = F_19 ( V_2 , V_4 -> V_20 , V_42 -> V_48 ) ;
struct V_13 * V_66 = F_21 ( V_2 -> V_13 , V_25 ) ;
* V_46 = F_23 ( V_66 ) ;
for (; V_57 -> V_63 ; V_57 ++ ) {
V_60 = ( V_26 * V_57 -> V_64 ) / V_57 -> V_63 ;
V_59 = F_34 ( V_66 , V_60 ) ;
if ( ( V_59 < ( V_60 - V_58 ) ) ||
( V_59 > ( V_60 + V_58 ) ) )
continue;
* V_43 = V_59 ;
return ( V_59 * V_57 -> V_63 ) / V_57 -> V_64 ;
}
return - V_47 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_41 V_42 = * V_4 -> V_41 ;
const struct V_56 * V_57 = V_65 ;
unsigned long V_60 ;
int V_58 = 100000 ;
T_1 V_33 = F_16 ( V_4 -> V_39 ) - 1 ;
T_1 V_30 ;
for (; V_57 -> V_63 ; V_57 ++ ) {
V_60 = ( V_26 * V_57 -> V_64 ) / V_57 -> V_63 ;
if ( ( V_32 < ( V_60 - V_58 ) ) ||
( V_32 > ( V_60 + V_58 ) ) )
continue;
F_3 ( V_4 -> V_7 . V_8 , V_4 -> V_9 + V_16 ,
& V_30 ) ;
V_42 . V_50 = V_30 ;
V_42 . V_50 >>= V_40 ;
V_42 . V_50 &= V_33 ;
V_42 . V_27 = V_57 -> V_63 ;
V_42 . V_28 = V_57 -> V_64 ;
return F_25 ( V_4 , & V_42 ) ;
}
return - V_47 ;
}
static int F_41 ( struct V_1 * V_2 , unsigned long V_26 ,
unsigned long V_32 , T_2 V_25 )
{
return F_40 ( V_2 , V_26 , V_32 ) ;
}
