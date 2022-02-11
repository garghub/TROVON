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
int V_14 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
V_3 = F_1 ( & V_11 -> V_2 , V_3 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
if ( V_3 == V_11 -> V_2 . V_18 [ V_14 ] )
return V_14 ;
return - V_19 ;
}
static int F_7 ( struct V_20 * V_11 , T_1 V_21 )
{
V_21 &= F_8 ( V_11 -> V_22 ) ;
return ! ! V_21 ;
}
static T_2 F_9 ( struct V_8 * V_9 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
int V_12 = F_5 ( V_9 -> V_13 ) ;
T_1 V_3 , V_23 ;
int V_21 ;
int V_14 ;
struct V_1 * V_2 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , & V_23 ) ;
V_21 = F_7 ( V_11 , V_23 ) ;
V_2 = & V_11 -> V_2 [ V_21 ] ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
V_3 = F_1 ( V_2 , V_3 ) ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
if ( V_3 == V_2 -> V_18 [ V_14 ] )
return V_14 ;
return - V_19 ;
}
static int F_11 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_3 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
V_3 = F_2 ( & V_11 -> V_2 , V_11 -> V_2 . V_18 [ V_25 ] , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_26 * V_26 , T_1 V_27 )
{
V_27 >>= V_26 -> V_28 ;
V_27 &= F_8 ( V_26 -> V_29 ) - 1 ;
return V_27 ;
}
static T_1 F_14 ( struct V_30 * V_31 , T_1 V_3 )
{
V_3 >>= V_31 -> V_32 ;
V_3 &= F_8 ( V_31 -> V_33 ) - 1 ;
return V_3 ;
}
static T_1 F_15 ( struct V_30 * V_31 , T_2 V_30 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = F_8 ( V_31 -> V_33 ) - 1 ;
V_7 <<= V_31 -> V_32 ;
V_3 &= ~ V_7 ;
V_3 |= V_30 << V_31 -> V_32 ;
return V_3 ;
}
static T_1 F_16 ( struct V_26 * V_26 , T_1 V_34 , T_1 V_35 , T_1 V_27 )
{
T_1 V_7 , V_36 ;
V_36 = F_8 ( V_26 -> V_29 ) - 1 ;
V_7 = ( V_36 << V_26 -> V_28 ) | V_36 ;
V_27 &= ~ V_7 ;
if ( V_35 ) {
V_34 <<= V_26 -> V_28 ;
V_27 |= V_34 ;
V_27 |= ~ V_35 & V_36 ;
}
return V_27 ;
}
static T_1 F_17 ( struct V_26 * V_26 , T_1 V_3 , T_1 V_34 )
{
V_3 = ~ V_3 >> V_26 -> V_37 ;
V_3 &= F_8 ( V_26 -> V_29 ) - 1 ;
return V_3 + V_34 ;
}
static T_1 F_18 ( struct V_26 * V_26 , T_1 V_38 )
{
V_38 >>= V_26 -> V_39 ;
V_38 &= V_40 ;
return V_38 ;
}
static T_1 F_19 ( struct V_26 * V_26 , T_1 V_34 , T_1 V_35 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = F_8 ( V_26 -> V_29 ) - 1 ;
V_7 <<= V_26 -> V_37 ;
V_3 &= ~ V_7 ;
if ( V_35 ) {
V_35 = V_35 - V_34 ;
V_35 = ~ V_35 ;
V_35 &= F_8 ( V_26 -> V_29 ) - 1 ;
V_35 <<= V_26 -> V_37 ;
V_3 |= V_35 ;
}
return V_3 ;
}
static T_1 F_20 ( struct V_26 * V_26 , T_1 V_34 , T_1 V_35 , T_1 V_38 )
{
T_1 V_7 ;
V_7 = V_40 << V_26 -> V_39 ;
V_7 |= F_8 ( V_26 -> V_41 ) ;
V_38 &= ~ V_7 ;
if ( V_35 ) {
V_38 |= F_8 ( V_26 -> V_41 ) ;
V_38 |= V_42 << V_26 -> V_39 ;
}
return V_38 ;
}
static void F_21 ( struct V_20 * V_11 , const struct V_43 * V_44 )
{
T_1 V_3 , V_27 , V_23 , * V_45 ;
int V_21 , V_46 ;
struct V_26 * V_26 ;
struct V_30 * V_31 ;
struct V_1 * V_2 ;
bool V_47 ;
T_1 V_48 ;
T_1 V_49 ;
bool V_50 = ! ! V_11 -> V_26 [ 1 ] . V_29 ;
struct V_8 * V_9 = & V_11 -> V_15 . V_9 ;
V_47 = F_22 ( V_9 -> V_13 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , & V_23 ) ;
if ( V_50 ) {
V_45 = & V_23 ;
V_49 = V_11 -> V_15 . V_24 ;
} else {
V_45 = & V_3 ;
V_49 = V_11 -> V_17 ;
}
V_21 = F_7 ( V_11 , * V_45 ) ;
V_46 = V_47 ? ! V_21 : V_21 ;
if ( V_50 ) {
V_26 = & V_11 -> V_26 [ V_46 ] ;
V_48 = V_11 -> V_48 [ V_46 ] ;
V_3 |= F_8 ( V_26 -> V_51 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_48 , & V_27 ) ;
V_27 = F_16 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_27 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_48 , V_27 ) ;
V_3 = F_19 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
V_23 = F_20 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_23 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , V_23 ) ;
V_3 &= ~ F_8 ( V_26 -> V_51 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
} else {
V_31 = & V_11 -> V_31 [ V_46 ] ;
V_3 = F_15 ( V_31 , V_44 -> V_30 - 1 , V_3 ) ;
}
V_2 = & V_11 -> V_2 [ V_46 ] ;
V_3 = F_2 ( V_2 , V_2 -> V_18 [ V_44 -> V_6 ] , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
if ( V_47 ) {
* V_45 ^= F_8 ( V_11 -> V_22 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_49 , * V_45 ) ;
}
}
static int F_23 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
T_1 V_3 , V_23 , V_27 , V_52 ;
int V_21 ;
struct V_43 V_44 = { 0 } ;
bool V_50 = ! ! V_11 -> V_26 [ 1 ] . V_29 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , & V_23 ) ;
V_52 = V_50 ? V_23 : V_3 ;
V_21 = F_7 ( V_11 , V_52 ) ;
if ( V_50 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_48 [ V_21 ] , & V_27 ) ;
V_44 . V_34 = F_13 ( & V_11 -> V_26 [ V_21 ] , V_27 ) ;
V_44 . V_35 = F_17 ( & V_11 -> V_26 [ V_21 ] , V_3 , V_44 . V_34 ) ;
} else {
V_44 . V_30 = F_14 ( & V_11 -> V_31 [ V_21 ] , V_3 ) + 1 ;
}
V_44 . V_6 = V_25 ;
F_21 ( V_11 , & V_44 ) ;
return 0 ;
}
static unsigned long
F_24 ( unsigned long V_53 , T_1 V_34 , T_1 V_35 , T_1 V_54 , T_1 V_30 )
{
if ( V_30 )
V_53 /= V_30 + 1 ;
if ( V_54 ) {
T_3 V_55 = V_53 ;
V_55 *= V_34 ;
F_25 ( V_55 , V_35 ) ;
V_53 = V_55 ;
}
return V_53 ;
}
static unsigned long
F_26 ( struct V_8 * V_9 , unsigned long V_56 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_30 , V_34 = 0 , V_35 = 0 , V_3 , V_27 , V_54 = 0 ;
struct V_26 * V_26 = & V_11 -> V_26 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
V_30 = F_14 ( & V_11 -> V_31 , V_3 ) ;
if ( V_11 -> V_26 . V_29 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_48 , & V_27 ) ;
V_34 = F_13 ( V_26 , V_27 ) ;
V_35 = F_17 ( V_26 , V_3 , V_34 ) ;
if ( V_11 -> V_15 . V_24 != V_11 -> V_17 )
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , & V_54 ) ;
else
V_54 = V_3 ;
V_54 = F_18 ( V_26 , V_54 ) ;
}
return F_24 ( V_56 , V_34 , V_35 , V_54 , V_30 ) ;
}
static unsigned long
F_27 ( struct V_8 * V_9 , unsigned long V_56 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
T_1 V_34 , V_35 , V_30 , V_3 , V_27 , V_54 , V_52 ;
int V_21 ;
struct V_26 * V_26 ;
bool V_50 = ! ! V_11 -> V_26 [ 1 ] . V_29 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
if ( V_50 )
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , & V_52 ) ;
else
V_52 = V_3 ;
V_21 = F_7 ( V_11 , V_52 ) ;
if ( V_50 ) {
V_26 = & V_11 -> V_26 [ V_21 ] ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_48 [ V_21 ] , & V_27 ) ;
V_34 = F_13 ( V_26 , V_27 ) ;
V_35 = F_17 ( V_26 , V_3 , V_34 ) ;
V_54 = F_18 ( V_26 , V_52 ) ;
return F_24 ( V_56 , V_34 , V_35 , V_54 , 0 ) ;
} else {
V_30 = F_14 ( & V_11 -> V_31 [ V_21 ] , V_3 ) ;
return F_24 ( V_56 , 0 , 0 , 0 , V_30 ) ;
}
}
static const
struct V_43 * F_28 ( const struct V_43 * V_44 , unsigned long V_53 )
{
if ( ! V_44 )
return NULL ;
for (; V_44 -> V_57 ; V_44 ++ )
if ( V_53 <= V_44 -> V_57 )
return V_44 ;
return NULL ;
}
static long F_29 ( struct V_8 * V_9 ,
const struct V_43 * V_44 , unsigned long V_53 ,
unsigned long * V_58 , struct V_13 * * V_31 )
{
unsigned long V_59 ;
V_44 = F_28 ( V_44 , V_53 ) ;
if ( ! V_44 )
return - V_19 ;
V_59 = F_30 ( V_9 -> V_13 ) ;
* V_31 = F_31 ( V_9 -> V_13 , V_44 -> V_6 ) ;
if ( V_59 & V_60 ) {
V_53 = V_53 * V_44 -> V_30 ;
if ( V_44 -> V_35 ) {
T_3 V_55 = V_53 ;
V_55 = V_55 * V_44 -> V_35 ;
F_25 ( V_55 , V_44 -> V_34 ) ;
V_53 = V_55 ;
}
} else {
V_53 = F_32 ( * V_31 ) ;
}
* V_58 = V_53 ;
return V_44 -> V_57 ;
}
static long F_33 ( struct V_8 * V_9 , unsigned long V_53 ,
unsigned long * V_58 , struct V_13 * * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_29 ( V_9 , V_11 -> V_43 , V_53 , V_58 , V_31 ) ;
}
static long F_34 ( struct V_8 * V_9 , unsigned long V_53 ,
unsigned long * V_58 , struct V_13 * * V_31 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
return F_29 ( V_9 , V_11 -> V_43 , V_53 , V_58 , V_31 ) ;
}
static int F_35 ( struct V_8 * V_9 , unsigned long V_53 ,
unsigned long V_56 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_43 * V_44 ;
T_1 V_3 , V_27 , V_23 ;
struct V_26 * V_26 = & V_11 -> V_26 ;
T_1 V_7 = 0 ;
unsigned int V_61 ;
V_44 = F_28 ( V_11 -> V_43 , V_53 ) ;
if ( ! V_44 )
return - V_19 ;
if ( V_11 -> V_26 . V_62 )
V_61 = V_11 -> V_15 . V_24 ;
else
V_61 = V_11 -> V_17 ;
if ( V_11 -> V_26 . V_29 ) {
V_7 = F_8 ( V_26 -> V_51 ) ;
F_36 ( V_11 -> V_15 . V_16 , V_61 , V_7 , V_7 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_48 , & V_27 ) ;
V_27 = F_16 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_27 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_48 , V_27 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
if ( V_11 -> V_15 . V_24 != V_11 -> V_17 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , & V_23 ) ;
V_23 = F_20 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_23 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_24 , V_23 ) ;
} else {
V_3 = F_20 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_3 ) ;
}
V_3 = F_19 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_3 ) ;
} else {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
}
V_3 = F_15 ( & V_11 -> V_31 , V_44 -> V_30 - 1 , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
F_36 ( V_11 -> V_15 . V_16 , V_61 , V_7 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_9 , unsigned long V_53 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
const struct V_43 * V_44 ;
V_44 = F_28 ( V_11 -> V_43 , V_53 ) ;
if ( ! V_44 )
return - V_19 ;
F_21 ( V_11 , V_44 ) ;
return 0 ;
}
static int F_38 ( struct V_8 * V_9 , unsigned long V_53 ,
unsigned long V_56 )
{
return F_37 ( V_9 , V_53 ) ;
}
static int F_39 ( struct V_8 * V_9 ,
unsigned long V_53 , unsigned long V_56 , T_2 V_25 )
{
return F_37 ( V_9 , V_53 ) ;
}
