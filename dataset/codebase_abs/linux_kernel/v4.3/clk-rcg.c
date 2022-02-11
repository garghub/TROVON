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
int V_12 = F_5 ( V_9 ) ;
T_1 V_3 ;
int V_13 , V_14 ;
V_14 = F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
if ( V_14 )
goto V_18;
V_3 = F_1 ( & V_11 -> V_2 , V_3 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
if ( V_3 == V_11 -> V_2 . V_19 [ V_13 ] . V_20 )
return V_13 ;
V_18:
F_7 ( L_1 ,
V_21 , F_8 ( V_9 ) ) ;
return 0 ;
}
static int F_9 ( struct V_22 * V_11 , T_1 V_23 )
{
V_23 &= F_10 ( V_11 -> V_24 ) ;
return ! ! V_23 ;
}
static T_2 F_11 ( struct V_8 * V_9 )
{
struct V_22 * V_11 = F_12 ( V_9 ) ;
int V_12 = F_5 ( V_9 ) ;
T_1 V_3 , V_25 ;
int V_23 ;
int V_13 , V_14 ;
struct V_1 * V_2 ;
V_14 = F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_26 , & V_25 ) ;
if ( V_14 )
goto V_18;
V_23 = F_9 ( V_11 , V_25 ) ;
V_2 = & V_11 -> V_2 [ V_23 ] ;
V_14 = F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 [ V_23 ] , & V_3 ) ;
if ( V_14 )
goto V_18;
V_3 = F_1 ( V_2 , V_3 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
if ( V_3 == V_2 -> V_19 [ V_13 ] . V_20 )
return V_13 ;
V_18:
F_7 ( L_1 ,
V_21 , F_8 ( V_9 ) ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , T_2 V_27 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_3 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
V_3 = F_2 ( & V_11 -> V_2 , V_11 -> V_2 . V_19 [ V_27 ] . V_20 , V_3 ) ;
F_14 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_28 * V_28 , T_1 V_29 )
{
V_29 >>= V_28 -> V_30 ;
V_29 &= F_10 ( V_28 -> V_31 ) - 1 ;
return V_29 ;
}
static T_1 F_16 ( struct V_32 * V_33 , T_1 V_3 )
{
V_3 >>= V_33 -> V_34 ;
V_3 &= F_10 ( V_33 -> V_35 ) - 1 ;
return V_3 ;
}
static T_1 F_17 ( struct V_32 * V_33 , T_2 V_32 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = F_10 ( V_33 -> V_35 ) - 1 ;
V_7 <<= V_33 -> V_34 ;
V_3 &= ~ V_7 ;
V_3 |= V_32 << V_33 -> V_34 ;
return V_3 ;
}
static T_1 F_18 ( struct V_28 * V_28 , T_1 V_36 , T_1 V_37 , T_1 V_29 )
{
T_1 V_7 , V_38 ;
V_38 = F_10 ( V_28 -> V_31 ) - 1 ;
V_7 = ( V_38 << V_28 -> V_30 ) | V_38 ;
V_29 &= ~ V_7 ;
if ( V_37 ) {
V_36 <<= V_28 -> V_30 ;
V_29 |= V_36 ;
V_29 |= ~ V_37 & V_38 ;
}
return V_29 ;
}
static T_1 F_19 ( struct V_28 * V_28 , T_1 V_3 , T_1 V_36 )
{
V_3 = ~ V_3 >> V_28 -> V_39 ;
V_3 &= F_10 ( V_28 -> V_31 ) - 1 ;
return V_3 + V_36 ;
}
static T_1 F_20 ( struct V_28 * V_28 , T_1 V_40 )
{
V_40 >>= V_28 -> V_41 ;
V_40 &= V_42 ;
return V_40 ;
}
static T_1 F_21 ( struct V_28 * V_28 , T_1 V_36 , T_1 V_37 , T_1 V_3 )
{
T_1 V_7 ;
V_7 = F_10 ( V_28 -> V_31 ) - 1 ;
V_7 <<= V_28 -> V_39 ;
V_3 &= ~ V_7 ;
if ( V_37 ) {
V_37 = V_37 - V_36 ;
V_37 = ~ V_37 ;
V_37 &= F_10 ( V_28 -> V_31 ) - 1 ;
V_37 <<= V_28 -> V_39 ;
V_3 |= V_37 ;
}
return V_3 ;
}
static T_1 F_22 ( struct V_28 * V_28 , T_1 V_36 , T_1 V_37 , T_1 V_40 )
{
T_1 V_7 ;
V_7 = V_42 << V_28 -> V_41 ;
V_7 |= F_10 ( V_28 -> V_43 ) ;
V_40 &= ~ V_7 ;
if ( V_37 ) {
V_40 |= F_10 ( V_28 -> V_43 ) ;
V_40 |= V_44 << V_28 -> V_41 ;
}
return V_40 ;
}
static int F_23 ( struct V_22 * V_11 , const struct V_45 * V_46 )
{
T_1 V_3 , V_29 , V_25 ;
int V_23 , V_47 , V_14 , V_27 ;
struct V_28 * V_28 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
bool V_48 ;
T_1 V_49 , V_17 ;
bool V_50 = ! ! V_11 -> V_28 [ 1 ] . V_31 ;
bool V_51 = ! ! V_11 -> V_33 [ 1 ] . V_35 ;
struct V_8 * V_9 = & V_11 -> V_15 . V_9 ;
V_48 = F_24 ( V_9 -> V_52 ) ;
V_14 = F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_26 , & V_25 ) ;
if ( V_14 )
return V_14 ;
V_23 = F_9 ( V_11 , V_25 ) ;
V_47 = V_48 ? ! V_23 : V_23 ;
V_17 = V_11 -> V_17 [ V_47 ] ;
V_14 = F_6 ( V_11 -> V_15 . V_16 , V_17 , & V_3 ) ;
if ( V_14 )
return V_14 ;
if ( V_50 ) {
V_28 = & V_11 -> V_28 [ V_47 ] ;
V_49 = V_11 -> V_49 [ V_47 ] ;
V_3 |= F_10 ( V_28 -> V_53 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_6 ( V_11 -> V_15 . V_16 , V_49 , & V_29 ) ;
if ( V_14 )
return V_14 ;
V_29 = F_18 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_29 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_49 , V_29 ) ;
if ( V_14 )
return V_14 ;
V_3 = F_21 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_3 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
if ( V_14 )
return V_14 ;
if ( V_11 -> V_17 [ 0 ] != V_11 -> V_17 [ 1 ] ) {
V_3 = F_22 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_3 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
if ( V_14 )
return V_14 ;
} else {
V_25 = F_22 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_25 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_11 -> V_26 ,
V_25 ) ;
if ( V_14 )
return V_14 ;
}
V_3 &= ~ F_10 ( V_28 -> V_53 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
if ( V_14 )
return V_14 ;
}
if ( V_51 ) {
V_33 = & V_11 -> V_33 [ V_47 ] ;
V_3 = F_17 ( V_33 , V_46 -> V_32 - 1 , V_3 ) ;
}
V_2 = & V_11 -> V_2 [ V_47 ] ;
V_27 = F_25 ( V_9 , V_2 -> V_19 , V_46 -> V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
V_3 = F_2 ( V_2 , V_2 -> V_19 [ V_27 ] . V_20 , V_3 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_17 , V_3 ) ;
if ( V_14 )
return V_14 ;
if ( V_48 ) {
V_14 = F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_26 , & V_25 ) ;
if ( V_14 )
return V_14 ;
V_25 ^= F_10 ( V_11 -> V_24 ) ;
V_14 = F_14 ( V_11 -> V_15 . V_16 , V_11 -> V_26 , V_25 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
static int F_26 ( struct V_8 * V_9 , T_2 V_27 )
{
struct V_22 * V_11 = F_12 ( V_9 ) ;
T_1 V_3 , V_29 , V_25 ;
int V_23 ;
struct V_45 V_46 = { 0 } ;
bool V_50 = ! ! V_11 -> V_28 [ 1 ] . V_31 ;
bool V_51 = ! ! V_11 -> V_33 [ 1 ] . V_35 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_26 , & V_25 ) ;
V_23 = F_9 ( V_11 , V_25 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 [ V_23 ] , & V_3 ) ;
if ( V_50 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_49 [ V_23 ] , & V_29 ) ;
V_46 . V_36 = F_15 ( & V_11 -> V_28 [ V_23 ] , V_29 ) ;
V_46 . V_37 = F_19 ( & V_11 -> V_28 [ V_23 ] , V_3 , V_46 . V_36 ) ;
}
if ( V_51 )
V_46 . V_32 = F_16 ( & V_11 -> V_33 [ V_23 ] , V_3 ) + 1 ;
V_46 . V_6 = F_25 ( V_9 , V_11 -> V_2 [ V_23 ] . V_19 , V_27 ) ;
return F_23 ( V_11 , & V_46 ) ;
}
static unsigned long
F_27 ( unsigned long V_54 , T_1 V_36 , T_1 V_37 , T_1 V_55 , T_1 V_32 )
{
if ( V_32 )
V_54 /= V_32 + 1 ;
if ( V_55 ) {
T_3 V_56 = V_54 ;
V_56 *= V_36 ;
F_28 ( V_56 , V_37 ) ;
V_54 = V_56 ;
}
return V_54 ;
}
static unsigned long
F_29 ( struct V_8 * V_9 , unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_32 , V_36 = 0 , V_37 = 0 , V_3 , V_29 , V_55 = 0 ;
struct V_28 * V_28 = & V_11 -> V_28 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
V_32 = F_16 ( & V_11 -> V_33 , V_3 ) ;
if ( V_11 -> V_28 . V_31 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_49 , & V_29 ) ;
V_36 = F_15 ( V_28 , V_29 ) ;
V_37 = F_19 ( V_28 , V_3 , V_36 ) ;
if ( V_11 -> V_15 . V_58 != V_11 -> V_17 )
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_58 , & V_55 ) ;
else
V_55 = V_3 ;
V_55 = F_20 ( V_28 , V_55 ) ;
}
return F_27 ( V_57 , V_36 , V_37 , V_55 , V_32 ) ;
}
static unsigned long
F_30 ( struct V_8 * V_9 , unsigned long V_57 )
{
struct V_22 * V_11 = F_12 ( V_9 ) ;
T_1 V_36 , V_37 , V_32 , V_3 , V_29 , V_55 , V_25 ;
int V_23 ;
struct V_28 * V_28 ;
bool V_51 = ! ! V_11 -> V_33 [ 1 ] . V_35 ;
bool V_50 = ! ! V_11 -> V_28 [ 1 ] . V_31 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_26 , & V_25 ) ;
V_23 = F_9 ( V_11 , V_25 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 [ V_23 ] , & V_3 ) ;
V_36 = V_37 = V_32 = V_55 = 0 ;
if ( V_50 ) {
V_28 = & V_11 -> V_28 [ V_23 ] ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_49 [ V_23 ] , & V_29 ) ;
V_36 = F_15 ( V_28 , V_29 ) ;
V_37 = F_19 ( V_28 , V_3 , V_36 ) ;
if ( V_11 -> V_17 [ 0 ] != V_11 -> V_17 [ 1 ] )
V_25 = V_3 ;
V_55 = F_20 ( V_28 , V_25 ) ;
}
if ( V_51 )
V_32 = F_16 ( & V_11 -> V_33 [ V_23 ] , V_3 ) ;
return F_27 ( V_57 , V_36 , V_37 , V_55 , V_32 ) ;
}
static int F_31 ( struct V_8 * V_9 , const struct V_45 * V_46 ,
struct V_59 * V_60 ,
const struct V_19 * V_19 )
{
unsigned long V_61 , V_54 = V_60 -> V_54 ;
struct V_8 * V_33 ;
int V_27 ;
V_46 = F_32 ( V_46 , V_54 ) ;
if ( ! V_46 )
return - V_62 ;
V_27 = F_25 ( V_9 , V_19 , V_46 -> V_6 ) ;
if ( V_27 < 0 )
return V_27 ;
V_61 = F_33 ( V_9 ) ;
V_33 = F_34 ( V_9 , V_27 ) ;
if ( V_61 & V_63 ) {
V_54 = V_54 * V_46 -> V_32 ;
if ( V_46 -> V_37 ) {
T_3 V_56 = V_54 ;
V_56 = V_56 * V_46 -> V_37 ;
F_28 ( V_56 , V_46 -> V_36 ) ;
V_54 = V_56 ;
}
} else {
V_54 = F_35 ( V_33 ) ;
}
V_60 -> V_64 = V_33 ;
V_60 -> V_65 = V_54 ;
V_60 -> V_54 = V_46 -> V_66 ;
return 0 ;
}
static int F_36 ( struct V_8 * V_9 ,
struct V_59 * V_60 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_31 ( V_9 , V_11 -> V_45 , V_60 ,
V_11 -> V_2 . V_19 ) ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_59 * V_60 )
{
struct V_22 * V_11 = F_12 ( V_9 ) ;
T_1 V_25 ;
int V_23 ;
struct V_1 * V_2 ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_26 , & V_25 ) ;
V_23 = F_9 ( V_11 , V_25 ) ;
V_2 = & V_11 -> V_2 [ V_23 ] ;
return F_31 ( V_9 , V_11 -> V_45 , V_60 , V_2 -> V_19 ) ;
}
static int F_38 ( struct V_8 * V_9 ,
struct V_59 * V_60 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_45 * V_46 = V_11 -> V_45 ;
struct V_8 * V_33 ;
int V_27 = F_25 ( V_9 , V_11 -> V_2 . V_19 , V_46 -> V_6 ) ;
V_60 -> V_64 = V_33 = F_34 ( V_9 , V_27 ) ;
V_60 -> V_65 = F_39 ( V_33 , V_60 -> V_54 ) ;
V_60 -> V_54 = V_60 -> V_65 ;
return 0 ;
}
static int F_40 ( struct V_10 * V_11 , const struct V_45 * V_46 )
{
T_1 V_3 , V_29 , V_67 ;
struct V_28 * V_28 = & V_11 -> V_28 ;
T_1 V_7 = 0 ;
unsigned int V_68 ;
if ( V_11 -> V_28 . V_69 )
V_68 = V_11 -> V_15 . V_58 ;
else
V_68 = V_11 -> V_17 ;
if ( V_11 -> V_28 . V_31 ) {
V_7 = F_10 ( V_28 -> V_53 ) ;
F_41 ( V_11 -> V_15 . V_16 , V_68 , V_7 , V_7 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_49 , & V_29 ) ;
V_29 = F_18 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_29 ) ;
F_14 ( V_11 -> V_15 . V_16 , V_11 -> V_49 , V_29 ) ;
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
if ( V_11 -> V_15 . V_58 != V_11 -> V_17 ) {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_58 , & V_67 ) ;
V_67 = F_22 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_67 ) ;
F_14 ( V_11 -> V_15 . V_16 , V_11 -> V_15 . V_58 , V_67 ) ;
} else {
V_3 = F_22 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_3 ) ;
}
V_3 = F_21 ( V_28 , V_46 -> V_36 , V_46 -> V_37 , V_3 ) ;
} else {
F_6 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , & V_3 ) ;
}
V_3 = F_17 ( & V_11 -> V_33 , V_46 -> V_32 - 1 , V_3 ) ;
F_14 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_3 ) ;
F_41 ( V_11 -> V_15 . V_16 , V_68 , V_7 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_45 * V_46 ;
V_46 = F_32 ( V_11 -> V_45 , V_54 ) ;
if ( ! V_46 )
return - V_62 ;
return F_40 ( V_11 , V_46 ) ;
}
static int F_43 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_40 ( V_11 , V_11 -> V_45 ) ;
}
static int F_44 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
const struct V_45 * V_46 ;
int V_14 ;
T_1 V_70 = F_10 ( 10 ) ;
V_46 = F_32 ( V_11 -> V_45 , V_54 ) ;
if ( ! V_46 )
return - V_62 ;
F_41 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_70 , 0 ) ;
V_14 = F_40 ( V_11 , V_46 ) ;
if ( F_24 ( V_9 -> V_52 ) )
F_41 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_70 , V_70 ) ;
return V_14 ;
}
static int F_45 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_70 = F_10 ( 10 ) ;
return F_41 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_70 , V_70 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
T_1 V_70 = F_10 ( 10 ) ;
F_41 ( V_11 -> V_15 . V_16 , V_11 -> V_17 , V_70 , 0 ) ;
}
static int F_47 ( struct V_8 * V_9 , unsigned long V_54 )
{
struct V_22 * V_11 = F_12 ( V_9 ) ;
const struct V_45 * V_46 ;
V_46 = F_32 ( V_11 -> V_45 , V_54 ) ;
if ( ! V_46 )
return - V_62 ;
return F_23 ( V_11 , V_46 ) ;
}
static int F_48 ( struct V_8 * V_9 , unsigned long V_54 ,
unsigned long V_57 )
{
return F_47 ( V_9 , V_54 ) ;
}
static int F_49 ( struct V_8 * V_9 ,
unsigned long V_54 , unsigned long V_57 , T_2 V_27 )
{
return F_47 ( V_9 , V_54 ) ;
}
