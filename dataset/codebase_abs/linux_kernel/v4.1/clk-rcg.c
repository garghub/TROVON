static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_3 >>= V_2 -> V_4 ;
V_3 &= V_5 ;
return V_3 ;
}
static T_1 F_2 ( struct V_1 * V_2 , T_2 V_6 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = V_5 ;
V_7 <<= V_2 -> V_4 ;
V_3 &= ~ V_7 ;
V_3 |= V_6 << V_2 -> V_4 ;
return V_3 ;
}
static T_2 F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_12 = F_5 ( V_9 -> V_13 ) ;
T_1 V_3 ;
int V_14 , V_15 ;
V_15 = F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , & V_3 ) ;
if ( V_15 )
goto V_19;
V_3 = F_1 ( & V_11 -> V_2 , V_3 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
if ( V_3 == V_11 -> V_2 . V_20 [ V_14 ] . V_21 )
return V_14 ;
V_19:
F_7 ( L_1 ,
V_22 , F_8 ( V_9 -> V_13 ) ) ;
return 0 ;
}
static int F_9 ( struct V_23 * V_11 , T_1 V_24 )
{
V_24 &= F_10 ( V_11 -> V_25 ) ;
return ! ! V_24 ;
}
static T_2 F_11 ( struct V_8 * V_9 )
{
struct V_23 * V_11 = F_12 ( V_9 ) ;
int V_12 = F_5 ( V_9 -> V_13 ) ;
T_1 V_3 , V_26 ;
int V_24 ;
int V_14 , V_15 ;
struct V_1 * V_2 ;
V_15 = F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_27 , & V_26 ) ;
if ( V_15 )
goto V_19;
V_24 = F_9 ( V_11 , V_26 ) ;
V_2 = & V_11 -> V_2 [ V_24 ] ;
V_15 = F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 [ V_24 ] , & V_3 ) ;
if ( V_15 )
goto V_19;
V_3 = F_1 ( V_2 , V_3 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
if ( V_3 == V_2 -> V_20 [ V_14 ] . V_21 )
return V_14 ;
V_19:
F_7 ( L_1 ,
V_22 , F_8 ( V_9 -> V_13 ) ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , T_2 V_28 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_3 ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , & V_3 ) ;
V_3 = F_2 ( & V_11 -> V_2 , V_11 -> V_2 . V_20 [ V_28 ] . V_21 , V_3 ) ;
F_14 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , V_3 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_29 * V_29 , T_1 V_30 )
{
V_30 >>= V_29 -> V_31 ;
V_30 &= F_10 ( V_29 -> V_32 ) - 1 ;
return V_30 ;
}
static T_1 F_16 ( struct V_33 * V_34 , T_1 V_3 )
{
V_3 >>= V_34 -> V_35 ;
V_3 &= F_10 ( V_34 -> V_36 ) - 1 ;
return V_3 ;
}
static T_1 F_17 ( struct V_33 * V_34 , T_2 V_33 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = F_10 ( V_34 -> V_36 ) - 1 ;
V_7 <<= V_34 -> V_35 ;
V_3 &= ~ V_7 ;
V_3 |= V_33 << V_34 -> V_35 ;
return V_3 ;
}
static T_1 F_18 ( struct V_29 * V_29 , T_1 V_37 , T_1 V_38 , T_1 V_30 )
{
T_1 V_7 , V_39 ;
V_39 = F_10 ( V_29 -> V_32 ) - 1 ;
V_7 = ( V_39 << V_29 -> V_31 ) | V_39 ;
V_30 &= ~ V_7 ;
if ( V_38 ) {
V_37 <<= V_29 -> V_31 ;
V_30 |= V_37 ;
V_30 |= ~ V_38 & V_39 ;
}
return V_30 ;
}
static T_1 F_19 ( struct V_29 * V_29 , T_1 V_3 , T_1 V_37 )
{
V_3 = ~ V_3 >> V_29 -> V_40 ;
V_3 &= F_10 ( V_29 -> V_32 ) - 1 ;
return V_3 + V_37 ;
}
static T_1 F_20 ( struct V_29 * V_29 , T_1 V_41 )
{
V_41 >>= V_29 -> V_42 ;
V_41 &= V_43 ;
return V_41 ;
}
static T_1 F_21 ( struct V_29 * V_29 , T_1 V_37 , T_1 V_38 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = F_10 ( V_29 -> V_32 ) - 1 ;
V_7 <<= V_29 -> V_40 ;
V_3 &= ~ V_7 ;
if ( V_38 ) {
V_38 = V_38 - V_37 ;
V_38 = ~ V_38 ;
V_38 &= F_10 ( V_29 -> V_32 ) - 1 ;
V_38 <<= V_29 -> V_40 ;
V_3 |= V_38 ;
}
return V_3 ;
}
static T_1 F_22 ( struct V_29 * V_29 , T_1 V_37 , T_1 V_38 , T_1 V_41 )
{
T_1 V_7 ;
V_7 = V_43 << V_29 -> V_42 ;
V_7 |= F_10 ( V_29 -> V_44 ) ;
V_41 &= ~ V_7 ;
if ( V_38 ) {
V_41 |= F_10 ( V_29 -> V_44 ) ;
V_41 |= V_45 << V_29 -> V_42 ;
}
return V_41 ;
}
static int F_23 ( struct V_23 * V_11 , const struct V_46 * V_47 )
{
T_1 V_3 , V_30 , V_26 ;
int V_24 , V_48 , V_15 , V_28 ;
struct V_29 * V_29 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
bool V_49 ;
T_1 V_50 , V_18 ;
bool V_51 = ! ! V_11 -> V_29 [ 1 ] . V_32 ;
bool V_52 = ! ! V_11 -> V_34 [ 1 ] . V_36 ;
struct V_8 * V_9 = & V_11 -> V_16 . V_9 ;
V_49 = F_24 ( V_9 -> V_13 ) ;
V_15 = F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_27 , & V_26 ) ;
if ( V_15 )
return V_15 ;
V_24 = F_9 ( V_11 , V_26 ) ;
V_48 = V_49 ? ! V_24 : V_24 ;
V_18 = V_11 -> V_18 [ V_48 ] ;
V_15 = F_6 ( V_11 -> V_16 . V_17 , V_18 , & V_3 ) ;
if ( V_15 )
return V_15 ;
if ( V_51 ) {
V_29 = & V_11 -> V_29 [ V_48 ] ;
V_50 = V_11 -> V_50 [ V_48 ] ;
V_3 |= F_10 ( V_29 -> V_53 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_18 , V_3 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_6 ( V_11 -> V_16 . V_17 , V_50 , & V_30 ) ;
if ( V_15 )
return V_15 ;
V_30 = F_18 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_30 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_50 , V_30 ) ;
if ( V_15 )
return V_15 ;
V_3 = F_21 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_3 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_18 , V_3 ) ;
if ( V_15 )
return V_15 ;
if ( V_11 -> V_18 [ 0 ] != V_11 -> V_18 [ 1 ] ) {
V_3 = F_22 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_3 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_18 , V_3 ) ;
if ( V_15 )
return V_15 ;
} else {
V_26 = F_22 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_26 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_11 -> V_27 ,
V_26 ) ;
if ( V_15 )
return V_15 ;
}
V_3 &= ~ F_10 ( V_29 -> V_53 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_18 , V_3 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_52 ) {
V_34 = & V_11 -> V_34 [ V_48 ] ;
V_3 = F_17 ( V_34 , V_47 -> V_33 - 1 , V_3 ) ;
}
V_2 = & V_11 -> V_2 [ V_48 ] ;
V_28 = F_25 ( V_9 , V_2 -> V_20 , V_47 -> V_6 ) ;
if ( V_28 < 0 )
return V_28 ;
V_3 = F_2 ( V_2 , V_2 -> V_20 [ V_28 ] . V_21 , V_3 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_18 , V_3 ) ;
if ( V_15 )
return V_15 ;
if ( V_49 ) {
V_15 = F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_27 , & V_26 ) ;
if ( V_15 )
return V_15 ;
V_26 ^= F_10 ( V_11 -> V_25 ) ;
V_15 = F_14 ( V_11 -> V_16 . V_17 , V_11 -> V_27 , V_26 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_26 ( struct V_8 * V_9 , T_2 V_28 )
{
struct V_23 * V_11 = F_12 ( V_9 ) ;
T_1 V_3 , V_30 , V_26 ;
int V_24 ;
struct V_46 V_47 = { 0 } ;
bool V_51 = ! ! V_11 -> V_29 [ 1 ] . V_32 ;
bool V_52 = ! ! V_11 -> V_34 [ 1 ] . V_36 ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_27 , & V_26 ) ;
V_24 = F_9 ( V_11 , V_26 ) ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 [ V_24 ] , & V_3 ) ;
if ( V_51 ) {
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_50 [ V_24 ] , & V_30 ) ;
V_47 . V_37 = F_15 ( & V_11 -> V_29 [ V_24 ] , V_30 ) ;
V_47 . V_38 = F_19 ( & V_11 -> V_29 [ V_24 ] , V_3 , V_47 . V_37 ) ;
}
if ( V_52 )
V_47 . V_33 = F_16 ( & V_11 -> V_34 [ V_24 ] , V_3 ) + 1 ;
V_47 . V_6 = F_25 ( V_9 , V_11 -> V_2 [ V_24 ] . V_20 , V_28 ) ;
return F_23 ( V_11 , & V_47 ) ;
}
static unsigned long
F_27 ( unsigned long V_54 , T_1 V_37 , T_1 V_38 , T_1 V_55 , T_1 V_33 )
{
if ( V_33 )
V_54 /= V_33 + 1 ;
if ( V_55 ) {
T_3 V_56 = V_54 ;
V_56 *= V_37 ;
F_28 ( V_56 , V_38 ) ;
V_54 = V_56 ;
}
return V_54 ;
}
static unsigned long
F_29 ( struct V_8 * V_9 , unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_33 , V_37 = 0 , V_38 = 0 , V_3 , V_30 , V_55 = 0 ;
struct V_29 * V_29 = & V_11 -> V_29 ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , & V_3 ) ;
V_33 = F_16 ( & V_11 -> V_34 , V_3 ) ;
if ( V_11 -> V_29 . V_32 ) {
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_50 , & V_30 ) ;
V_37 = F_15 ( V_29 , V_30 ) ;
V_38 = F_19 ( V_29 , V_3 , V_37 ) ;
if ( V_11 -> V_16 . V_58 != V_11 -> V_18 )
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_16 . V_58 , & V_55 ) ;
else
V_55 = V_3 ;
V_55 = F_20 ( V_29 , V_55 ) ;
}
return F_27 ( V_57 , V_37 , V_38 , V_55 , V_33 ) ;
}
static unsigned long
F_30 ( struct V_8 * V_9 , unsigned long V_57 )
{
struct V_23 * V_11 = F_12 ( V_9 ) ;
T_1 V_37 , V_38 , V_33 , V_3 , V_30 , V_55 , V_26 ;
int V_24 ;
struct V_29 * V_29 ;
bool V_52 = ! ! V_11 -> V_34 [ 1 ] . V_36 ;
bool V_51 = ! ! V_11 -> V_29 [ 1 ] . V_32 ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_27 , & V_26 ) ;
V_24 = F_9 ( V_11 , V_26 ) ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 [ V_24 ] , & V_3 ) ;
V_37 = V_38 = V_33 = V_55 = 0 ;
if ( V_51 ) {
V_29 = & V_11 -> V_29 [ V_24 ] ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_50 [ V_24 ] , & V_30 ) ;
V_37 = F_15 ( V_29 , V_30 ) ;
V_38 = F_19 ( V_29 , V_3 , V_37 ) ;
if ( V_11 -> V_18 [ 0 ] != V_11 -> V_18 [ 1 ] )
V_26 = V_3 ;
V_55 = F_20 ( V_29 , V_26 ) ;
}
if ( V_52 )
V_33 = F_16 ( & V_11 -> V_34 [ V_24 ] , V_3 ) ;
return F_27 ( V_57 , V_37 , V_38 , V_55 , V_33 ) ;
}
static long F_31 ( struct V_8 * V_9 ,
const struct V_46 * V_47 , unsigned long V_54 ,
unsigned long V_59 , unsigned long V_60 ,
unsigned long * V_61 , struct V_8 * * V_62 ,
const struct V_20 * V_20 )
{
unsigned long V_63 ;
struct V_13 * V_34 ;
int V_28 ;
V_47 = F_32 ( V_47 , V_54 ) ;
if ( ! V_47 )
return - V_64 ;
V_28 = F_25 ( V_9 , V_20 , V_47 -> V_6 ) ;
if ( V_28 < 0 )
return V_28 ;
V_63 = F_33 ( V_9 -> V_13 ) ;
V_34 = F_34 ( V_9 -> V_13 , V_28 ) ;
if ( V_63 & V_65 ) {
V_54 = V_54 * V_47 -> V_33 ;
if ( V_47 -> V_38 ) {
T_3 V_56 = V_54 ;
V_56 = V_56 * V_47 -> V_38 ;
F_28 ( V_56 , V_47 -> V_37 ) ;
V_54 = V_56 ;
}
} else {
V_54 = F_35 ( V_34 ) ;
}
* V_62 = F_36 ( V_34 ) ;
* V_61 = V_54 ;
return V_47 -> V_66 ;
}
static long F_37 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_59 , unsigned long V_60 ,
unsigned long * V_61 , struct V_8 * * V_34 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_31 ( V_9 , V_11 -> V_46 , V_54 , V_59 ,
V_60 , V_61 , V_34 , V_11 -> V_2 . V_20 ) ;
}
static long F_38 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_59 , unsigned long V_60 ,
unsigned long * V_61 , struct V_8 * * V_34 )
{
struct V_23 * V_11 = F_12 ( V_9 ) ;
T_1 V_26 ;
int V_24 ;
struct V_1 * V_2 ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_27 , & V_26 ) ;
V_24 = F_9 ( V_11 , V_26 ) ;
V_2 = & V_11 -> V_2 [ V_24 ] ;
return F_31 ( V_9 , V_11 -> V_46 , V_54 , V_59 ,
V_60 , V_61 , V_34 , V_2 -> V_20 ) ;
}
static long F_39 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_59 , unsigned long V_60 ,
unsigned long * V_61 , struct V_8 * * V_62 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_46 * V_47 = V_11 -> V_46 ;
struct V_13 * V_34 ;
int V_28 = F_25 ( V_9 , V_11 -> V_2 . V_20 , V_47 -> V_6 ) ;
V_34 = F_34 ( V_9 -> V_13 , V_28 ) ;
* V_62 = F_36 ( V_34 ) ;
* V_61 = F_40 ( V_34 , V_54 ) ;
return * V_61 ;
}
static int F_41 ( struct V_10 * V_11 , const struct V_46 * V_47 )
{
T_1 V_3 , V_30 , V_67 ;
struct V_29 * V_29 = & V_11 -> V_29 ;
T_1 V_7 = 0 ;
unsigned int V_68 ;
if ( V_11 -> V_29 . V_69 )
V_68 = V_11 -> V_16 . V_58 ;
else
V_68 = V_11 -> V_18 ;
if ( V_11 -> V_29 . V_32 ) {
V_7 = F_10 ( V_29 -> V_53 ) ;
F_42 ( V_11 -> V_16 . V_17 , V_68 , V_7 , V_7 ) ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_50 , & V_30 ) ;
V_30 = F_18 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_30 ) ;
F_14 ( V_11 -> V_16 . V_17 , V_11 -> V_50 , V_30 ) ;
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , & V_3 ) ;
if ( V_11 -> V_16 . V_58 != V_11 -> V_18 ) {
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_16 . V_58 , & V_67 ) ;
V_67 = F_22 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_67 ) ;
F_14 ( V_11 -> V_16 . V_17 , V_11 -> V_16 . V_58 , V_67 ) ;
} else {
V_3 = F_22 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_3 ) ;
}
V_3 = F_21 ( V_29 , V_47 -> V_37 , V_47 -> V_38 , V_3 ) ;
} else {
F_6 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , & V_3 ) ;
}
V_3 = F_17 ( & V_11 -> V_34 , V_47 -> V_33 - 1 , V_3 ) ;
F_14 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , V_3 ) ;
F_42 ( V_11 -> V_16 . V_17 , V_68 , V_7 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_46 * V_47 ;
V_47 = F_32 ( V_11 -> V_46 , V_54 ) ;
if ( ! V_47 )
return - V_64 ;
return F_41 ( V_11 , V_47 ) ;
}
static int F_44 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_41 ( V_11 , V_11 -> V_46 ) ;
}
static int F_45 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_46 * V_47 ;
int V_15 ;
T_1 V_70 = F_10 ( 10 ) ;
V_47 = F_32 ( V_11 -> V_46 , V_54 ) ;
if ( ! V_47 )
return - V_64 ;
F_42 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , V_70 , 0 ) ;
V_15 = F_41 ( V_11 , V_47 ) ;
if ( F_24 ( V_9 -> V_13 ) )
F_42 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , V_70 , V_70 ) ;
return V_15 ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_70 = F_10 ( 10 ) ;
return F_42 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , V_70 , V_70 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_70 = F_10 ( 10 ) ;
F_42 ( V_11 -> V_16 . V_17 , V_11 -> V_18 , V_70 , 0 ) ;
}
static int F_48 ( struct V_8 * V_9 , unsigned long V_54 )
{
struct V_23 * V_11 = F_12 ( V_9 ) ;
const struct V_46 * V_47 ;
V_47 = F_32 ( V_11 -> V_46 , V_54 ) ;
if ( ! V_47 )
return - V_64 ;
return F_23 ( V_11 , V_47 ) ;
}
static int F_49 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
return F_48 ( V_9 , V_54 ) ;
}
static int F_50 ( struct V_8 * V_9 ,
unsigned long V_54 , unsigned long V_57 , T_2 V_28 )
{
return F_48 ( V_9 , V_54 ) ;
}
