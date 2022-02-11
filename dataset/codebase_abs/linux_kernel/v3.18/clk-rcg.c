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
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_24 , & V_23 ) ;
V_21 = F_7 ( V_11 , V_23 ) ;
V_2 = & V_11 -> V_2 [ V_21 ] ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 [ V_21 ] , & V_3 ) ;
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
T_1 V_3 , V_27 , V_23 ;
int V_21 , V_45 ;
struct V_26 * V_26 ;
struct V_30 * V_31 ;
struct V_1 * V_2 ;
bool V_46 ;
T_1 V_47 , V_17 ;
bool V_48 = ! ! V_11 -> V_26 [ 1 ] . V_29 ;
bool V_49 = ! ! V_11 -> V_31 [ 1 ] . V_33 ;
struct V_8 * V_9 = & V_11 -> V_15 . V_9 ;
V_46 = F_22 ( V_9 -> V_13 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_24 , & V_23 ) ;
V_21 = F_7 ( V_11 , V_23 ) ;
V_45 = V_46 ? ! V_21 : V_21 ;
V_17 = V_11 -> V_17 [ V_45 ] ;
F_6 ( V_11 -> V_15 . V_16 , V_17 , & V_3 ) ;
if ( V_48 ) {
V_26 = & V_11 -> V_26 [ V_45 ] ;
V_47 = V_11 -> V_47 [ V_45 ] ;
V_3 |= F_8 ( V_26 -> V_50 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_47 , & V_27 ) ;
V_27 = F_16 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_27 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_47 , V_27 ) ;
V_3 = F_19 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
if ( V_11 -> V_17 [ 0 ] != V_11 -> V_17 [ 1 ] ) {
V_3 = F_20 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
} else {
V_23 = F_20 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_23 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_24 , V_23 ) ;
}
V_3 &= ~ F_8 ( V_26 -> V_50 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
}
if ( V_49 ) {
V_31 = & V_11 -> V_31 [ V_45 ] ;
V_3 = F_15 ( V_31 , V_44 -> V_30 - 1 , V_3 ) ;
}
V_2 = & V_11 -> V_2 [ V_45 ] ;
V_3 = F_2 ( V_2 , V_2 -> V_18 [ V_44 -> V_6 ] , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
if ( V_46 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_24 , & V_23 ) ;
V_23 ^= F_8 ( V_11 -> V_22 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_24 , V_23 ) ;
}
}
static int F_23 ( struct V_8 * V_9 , T_2 V_25 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
T_1 V_3 , V_27 , V_23 ;
int V_21 ;
struct V_43 V_44 = { 0 } ;
bool V_48 = ! ! V_11 -> V_26 [ 1 ] . V_29 ;
bool V_49 = ! ! V_11 -> V_31 [ 1 ] . V_33 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_24 , & V_23 ) ;
V_21 = F_7 ( V_11 , V_23 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 [ V_21 ] , & V_3 ) ;
if ( V_48 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_47 [ V_21 ] , & V_27 ) ;
V_44 . V_34 = F_13 ( & V_11 -> V_26 [ V_21 ] , V_27 ) ;
V_44 . V_35 = F_17 ( & V_11 -> V_26 [ V_21 ] , V_3 , V_44 . V_34 ) ;
}
if ( V_49 )
V_44 . V_30 = F_14 ( & V_11 -> V_31 [ V_21 ] , V_3 ) + 1 ;
V_44 . V_6 = V_25 ;
F_21 ( V_11 , & V_44 ) ;
return 0 ;
}
static unsigned long
F_24 ( unsigned long V_51 , T_1 V_34 , T_1 V_35 , T_1 V_52 , T_1 V_30 )
{
if ( V_30 )
V_51 /= V_30 + 1 ;
if ( V_52 ) {
T_3 V_53 = V_51 ;
V_53 *= V_34 ;
F_25 ( V_53 , V_35 ) ;
V_51 = V_53 ;
}
return V_51 ;
}
static unsigned long
F_26 ( struct V_8 * V_9 , unsigned long V_54 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_30 , V_34 = 0 , V_35 = 0 , V_3 , V_27 , V_52 = 0 ;
struct V_26 * V_26 = & V_11 -> V_26 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
V_30 = F_14 ( & V_11 -> V_31 , V_3 ) ;
if ( V_11 -> V_26 . V_29 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_47 , & V_27 ) ;
V_34 = F_13 ( V_26 , V_27 ) ;
V_35 = F_17 ( V_26 , V_3 , V_34 ) ;
if ( V_11 -> V_15 . V_55 != V_11 -> V_17 )
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_55 , & V_52 ) ;
else
V_52 = V_3 ;
V_52 = F_18 ( V_26 , V_52 ) ;
}
return F_24 ( V_54 , V_34 , V_35 , V_52 , V_30 ) ;
}
static unsigned long
F_27 ( struct V_8 * V_9 , unsigned long V_54 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
T_1 V_34 , V_35 , V_30 , V_3 , V_27 , V_52 , V_23 ;
int V_21 ;
struct V_26 * V_26 ;
bool V_49 = ! ! V_11 -> V_31 [ 1 ] . V_33 ;
bool V_48 = ! ! V_11 -> V_26 [ 1 ] . V_29 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_24 , & V_23 ) ;
V_21 = F_7 ( V_11 , V_23 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 [ V_21 ] , & V_3 ) ;
V_34 = V_35 = V_30 = V_52 = 0 ;
if ( V_48 ) {
V_26 = & V_11 -> V_26 [ V_21 ] ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_47 [ V_21 ] , & V_27 ) ;
V_34 = F_13 ( V_26 , V_27 ) ;
V_35 = F_17 ( V_26 , V_3 , V_34 ) ;
if ( V_11 -> V_17 [ 0 ] != V_11 -> V_17 [ 1 ] )
V_23 = V_3 ;
V_52 = F_18 ( V_26 , V_23 ) ;
}
if ( V_49 )
V_30 = F_14 ( & V_11 -> V_31 [ V_21 ] , V_3 ) ;
return F_24 ( V_54 , V_34 , V_35 , V_52 , V_30 ) ;
}
static long F_28 ( struct V_8 * V_9 ,
const struct V_43 * V_44 , unsigned long V_51 ,
unsigned long * V_56 , struct V_13 * * V_31 )
{
unsigned long V_57 ;
V_44 = F_29 ( V_44 , V_51 ) ;
if ( ! V_44 )
return - V_19 ;
V_57 = F_30 ( V_9 -> V_13 ) ;
* V_31 = F_31 ( V_9 -> V_13 , V_44 -> V_6 ) ;
if ( V_57 & V_58 ) {
V_51 = V_51 * V_44 -> V_30 ;
if ( V_44 -> V_35 ) {
T_3 V_53 = V_51 ;
V_53 = V_53 * V_44 -> V_35 ;
F_25 ( V_53 , V_44 -> V_34 ) ;
V_51 = V_53 ;
}
} else {
V_51 = F_32 ( * V_31 ) ;
}
* V_56 = V_51 ;
return V_44 -> V_59 ;
}
static long F_33 ( struct V_8 * V_9 , unsigned long V_51 ,
unsigned long * V_56 , struct V_13 * * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_28 ( V_9 , V_11 -> V_43 , V_51 , V_56 , V_31 ) ;
}
static long F_34 ( struct V_8 * V_9 , unsigned long V_51 ,
unsigned long * V_56 , struct V_13 * * V_31 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
return F_28 ( V_9 , V_11 -> V_43 , V_51 , V_56 , V_31 ) ;
}
static long F_35 ( struct V_8 * V_9 , unsigned long V_51 ,
unsigned long * V_56 , struct V_13 * * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_43 * V_44 = V_11 -> V_43 ;
* V_31 = F_31 ( V_9 -> V_13 , V_44 -> V_6 ) ;
* V_56 = F_36 ( * V_31 , V_51 ) ;
return * V_56 ;
}
static int F_37 ( struct V_10 * V_11 , const struct V_43 * V_44 )
{
T_1 V_3 , V_27 , V_60 ;
struct V_26 * V_26 = & V_11 -> V_26 ;
T_1 V_7 = 0 ;
unsigned int V_61 ;
if ( V_11 -> V_26 . V_62 )
V_61 = V_11 -> V_15 . V_55 ;
else
V_61 = V_11 -> V_17 ;
if ( V_11 -> V_26 . V_29 ) {
V_7 = F_8 ( V_26 -> V_50 ) ;
F_38 ( V_11 -> V_15 . V_16 , V_61 , V_7 , V_7 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_47 , & V_27 ) ;
V_27 = F_16 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_27 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_47 , V_27 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
if ( V_11 -> V_15 . V_55 != V_11 -> V_17 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_55 , & V_60 ) ;
V_60 = F_20 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_60 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_55 , V_60 ) ;
} else {
V_3 = F_20 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_3 ) ;
}
V_3 = F_19 ( V_26 , V_44 -> V_34 , V_44 -> V_35 , V_3 ) ;
} else {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
}
V_3 = F_15 ( & V_11 -> V_31 , V_44 -> V_30 - 1 , V_3 ) ;
F_12 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
F_38 ( V_11 -> V_15 . V_16 , V_61 , V_7 , 0 ) ;
return 0 ;
}
static int F_39 ( struct V_8 * V_9 , unsigned long V_51 ,
unsigned long V_54 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_43 * V_44 ;
V_44 = F_29 ( V_11 -> V_43 , V_51 ) ;
if ( ! V_44 )
return - V_19 ;
return F_37 ( V_11 , V_44 ) ;
}
static int F_40 ( struct V_8 * V_9 , unsigned long V_51 ,
unsigned long V_54 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_37 ( V_11 , V_11 -> V_43 ) ;
}
static int F_41 ( struct V_8 * V_9 , unsigned long V_51 )
{
struct V_20 * V_11 = F_10 ( V_9 ) ;
const struct V_43 * V_44 ;
V_44 = F_29 ( V_11 -> V_43 , V_51 ) ;
if ( ! V_44 )
return - V_19 ;
F_21 ( V_11 , V_44 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , unsigned long V_51 ,
unsigned long V_54 )
{
return F_41 ( V_9 , V_51 ) ;
}
static int F_43 ( struct V_8 * V_9 ,
unsigned long V_51 , unsigned long V_54 , T_2 V_25 )
{
return F_41 ( V_9 , V_51 ) ;
}
