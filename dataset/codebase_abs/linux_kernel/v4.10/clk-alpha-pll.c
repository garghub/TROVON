static int F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 ,
const char * V_5 )
{
T_1 V_6 , V_7 ;
int V_8 ;
int V_9 ;
const char * V_10 = F_2 ( & V_2 -> V_11 . V_12 ) ;
V_7 = V_2 -> V_13 ;
V_9 = F_3 ( V_2 -> V_11 . V_14 , V_7 + V_15 , & V_6 ) ;
if ( V_9 )
return V_9 ;
for ( V_8 = 100 ; V_8 > 0 ; V_8 -- ) {
V_9 = F_3 ( V_2 -> V_11 . V_14 , V_7 + V_15 , & V_6 ) ;
if ( V_9 )
return V_9 ;
if ( V_4 && ! ( V_6 & V_3 ) )
return 0 ;
else if ( ( V_6 & V_3 ) == V_3 )
return 0 ;
F_4 ( 1 ) ;
}
F_5 ( 1 , L_1 , V_10 , V_5 ) ;
return - V_16 ;
}
void F_6 ( struct V_1 * V_2 , struct V_14 * V_14 ,
const struct V_17 * V_18 )
{
T_1 V_6 , V_3 ;
T_1 V_7 = V_2 -> V_13 ;
F_7 ( V_14 , V_7 + V_19 , V_18 -> V_20 ) ;
F_7 ( V_14 , V_7 + V_21 , V_18 -> V_22 ) ;
F_7 ( V_14 , V_7 + V_23 , V_18 -> V_24 ) ;
F_7 ( V_14 , V_7 + V_25 , V_18 -> V_26 ) ;
V_6 = V_18 -> V_27 ;
V_6 |= V_18 -> V_28 ;
V_6 |= V_18 -> V_29 ;
V_6 |= V_18 -> V_30 ;
V_6 |= V_18 -> V_31 ;
V_6 |= V_18 -> V_32 ;
V_6 |= V_18 -> V_33 ;
V_3 = V_18 -> V_27 ;
V_3 |= V_18 -> V_28 ;
V_3 |= V_18 -> V_29 ;
V_3 |= V_18 -> V_30 ;
V_3 |= V_18 -> V_34 ;
V_3 |= V_18 -> V_35 ;
V_3 |= V_18 -> V_36 ;
F_8 ( V_14 , V_7 + V_37 , V_3 , V_6 ) ;
if ( V_2 -> V_38 & V_39 )
F_9 ( V_14 , V_7 + V_15 , 6 , 0 ) ;
}
static int F_10 ( struct V_40 * V_12 )
{
int V_9 ;
T_1 V_6 , V_7 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
V_7 = V_2 -> V_13 ;
V_9 = F_3 ( V_2 -> V_11 . V_14 , V_7 + V_15 , & V_6 ) ;
if ( V_9 )
return V_9 ;
V_6 |= V_41 ;
if ( V_2 -> V_38 & V_42 )
V_6 &= ~ V_43 ;
V_9 = F_7 ( V_2 -> V_11 . V_14 , V_7 + V_15 , V_6 ) ;
if ( V_9 )
return V_9 ;
F_12 () ;
return F_13 ( V_2 ) ;
}
static void F_14 ( struct V_40 * V_12 )
{
int V_9 ;
T_1 V_6 , V_7 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
V_7 = V_2 -> V_13 ;
V_9 = F_3 ( V_2 -> V_11 . V_14 , V_7 + V_15 , & V_6 ) ;
if ( V_9 )
return;
if ( V_2 -> V_38 & V_42 ) {
V_9 = F_8 ( V_2 -> V_11 . V_14 , V_7 + V_15 ,
V_43 , V_43 ) ;
if ( V_9 )
return;
V_9 = F_15 ( V_2 ) ;
if ( V_9 )
return;
}
V_9 = F_8 ( V_2 -> V_11 . V_14 , V_7 + V_15 ,
V_41 , 0 ) ;
if ( V_9 )
return;
F_16 ( V_2 ) ;
}
static int F_17 ( struct V_40 * V_12 , T_1 V_3 )
{
int V_9 ;
T_1 V_6 , V_7 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
V_7 = V_2 -> V_13 ;
V_9 = F_3 ( V_2 -> V_11 . V_14 , V_7 + V_15 , & V_6 ) ;
if ( V_9 )
return V_9 ;
return ! ! ( V_6 & V_3 ) ;
}
static int F_18 ( struct V_40 * V_12 )
{
return F_17 ( V_12 , V_44 ) ;
}
static int F_19 ( struct V_40 * V_12 )
{
return F_17 ( V_12 , V_45 ) ;
}
static int F_20 ( struct V_40 * V_12 )
{
int V_9 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_1 V_6 , V_3 , V_7 ;
V_7 = V_2 -> V_13 ;
V_3 = V_46 | V_47 | V_48 ;
V_9 = F_3 ( V_2 -> V_11 . V_14 , V_7 + V_15 , & V_6 ) ;
if ( V_9 )
return V_9 ;
if ( V_6 & V_49 ) {
V_9 = F_21 ( V_12 ) ;
if ( V_9 )
return V_9 ;
return F_13 ( V_2 ) ;
}
if ( ( V_6 & V_3 ) == V_3 )
return 0 ;
V_9 = F_8 ( V_2 -> V_11 . V_14 , V_7 + V_15 ,
V_48 , V_48 ) ;
if ( V_9 )
return V_9 ;
F_12 () ;
F_4 ( 5 ) ;
V_9 = F_8 ( V_2 -> V_11 . V_14 , V_7 + V_15 ,
V_47 , V_47 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_22 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_8 ( V_2 -> V_11 . V_14 , V_7 + V_15 ,
V_46 , V_46 ) ;
F_12 () ;
return V_9 ;
}
static void F_23 ( struct V_40 * V_12 )
{
int V_9 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_1 V_6 , V_3 , V_7 ;
V_7 = V_2 -> V_13 ;
V_9 = F_3 ( V_2 -> V_11 . V_14 , V_7 + V_15 , & V_6 ) ;
if ( V_9 )
return;
if ( V_6 & V_49 ) {
F_24 ( V_12 ) ;
return;
}
V_3 = V_46 ;
F_8 ( V_2 -> V_11 . V_14 , V_7 + V_15 , V_3 , 0 ) ;
F_12 () ;
F_4 ( 1 ) ;
V_3 = V_47 | V_48 ;
F_8 ( V_2 -> V_11 . V_14 , V_7 + V_15 , V_3 , 0 ) ;
}
static unsigned long F_25 ( T_2 V_50 , T_1 V_20 , T_1 V_51 )
{
return ( V_50 * V_20 ) + ( ( V_50 * V_51 ) >> V_52 ) ;
}
static unsigned long
F_26 ( unsigned long V_53 , unsigned long V_50 , T_1 * V_20 , T_2 * V_51 )
{
T_2 V_54 ;
T_2 V_55 ;
V_55 = V_53 ;
V_54 = F_27 ( V_55 , V_50 ) ;
* V_20 = V_55 ;
if ( ! V_54 ) {
* V_51 = 0 ;
return V_53 ;
}
V_55 = V_54 << V_52 ;
V_54 = F_27 ( V_55 , V_50 ) ;
if ( V_54 )
V_55 ++ ;
* V_51 = V_55 ;
return F_25 ( V_50 , * V_20 , * V_51 ) ;
}
static const struct V_56 *
F_28 ( const struct V_1 * V_2 , unsigned long V_53 )
{
const struct V_56 * V_57 = V_2 -> V_58 ;
const struct V_56 * V_59 = V_57 + V_2 -> V_60 ;
for (; V_57 < V_59 ; V_57 ++ )
if ( V_53 >= V_57 -> V_61 && V_53 <= V_57 -> V_62 )
return V_57 ;
return NULL ;
}
static unsigned long
F_29 ( struct V_40 * V_12 , unsigned long V_63 )
{
T_1 V_20 , V_64 , V_65 , V_66 ;
T_2 V_51 = 0 , V_50 = V_63 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_1 V_7 = V_2 -> V_13 ;
F_3 ( V_2 -> V_11 . V_14 , V_7 + V_19 , & V_20 ) ;
F_3 ( V_2 -> V_11 . V_14 , V_7 + V_37 , & V_66 ) ;
if ( V_66 & V_67 ) {
F_3 ( V_2 -> V_11 . V_14 , V_7 + V_21 , & V_64 ) ;
if ( V_2 -> V_38 & V_68 ) {
V_51 = V_64 & V_69 ;
} else {
F_3 ( V_2 -> V_11 . V_14 , V_7 + V_70 ,
& V_65 ) ;
V_51 = ( T_2 ) V_65 << 32 | V_64 ;
V_51 >>= V_71 - V_52 ;
}
}
return F_25 ( V_50 , V_20 , V_51 ) ;
}
static int F_30 ( struct V_40 * V_12 , unsigned long V_53 ,
unsigned long V_50 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
const struct V_56 * V_72 ;
T_1 V_20 , V_7 = V_2 -> V_13 ;
T_2 V_51 ;
V_53 = F_26 ( V_53 , V_50 , & V_20 , & V_51 ) ;
V_72 = F_28 ( V_2 , V_53 ) ;
if ( ! V_72 ) {
F_31 ( L_2 ) ;
return - V_73 ;
}
F_7 ( V_2 -> V_11 . V_14 , V_7 + V_19 , V_20 ) ;
if ( V_2 -> V_38 & V_68 ) {
F_7 ( V_2 -> V_11 . V_14 , V_7 + V_21 ,
V_51 & V_69 ) ;
} else {
V_51 <<= ( V_71 - V_52 ) ;
F_7 ( V_2 -> V_11 . V_14 , V_7 + V_70 , V_51 >> 32 ) ;
}
F_8 ( V_2 -> V_11 . V_14 , V_7 + V_37 ,
V_74 << V_75 ,
V_72 -> V_6 << V_75 ) ;
F_8 ( V_2 -> V_11 . V_14 , V_7 + V_37 , V_67 ,
V_67 ) ;
return 0 ;
}
static long F_32 ( struct V_40 * V_12 , unsigned long V_53 ,
unsigned long * V_50 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_1 V_20 ;
T_2 V_51 ;
unsigned long V_61 , V_62 ;
V_53 = F_26 ( V_53 , * V_50 , & V_20 , & V_51 ) ;
if ( F_28 ( V_2 , V_53 ) )
return V_53 ;
V_61 = V_2 -> V_58 [ 0 ] . V_61 ;
V_62 = V_2 -> V_58 [ V_2 -> V_60 - 1 ] . V_62 ;
return F_33 ( V_53 , V_61 , V_62 ) ;
}
static unsigned long
F_34 ( struct V_40 * V_12 , unsigned long V_63 )
{
struct V_76 * V_2 = F_35 ( V_12 ) ;
T_1 V_66 ;
F_3 ( V_2 -> V_11 . V_14 , V_2 -> V_13 + V_37 , & V_66 ) ;
V_66 >>= V_77 ;
V_66 &= V_78 ;
return V_63 >> F_36 ( V_66 ) ;
}
static long
F_37 ( struct V_40 * V_12 , unsigned long V_53 ,
unsigned long * V_50 )
{
struct V_76 * V_2 = F_35 ( V_12 ) ;
return F_38 ( V_12 , V_53 , V_50 , V_79 ,
V_2 -> V_80 , V_81 ) ;
}
static int F_39 ( struct V_40 * V_12 , unsigned long V_53 ,
unsigned long V_63 )
{
struct V_76 * V_2 = F_35 ( V_12 ) ;
int div ;
div = F_40 ( ( T_2 ) V_63 , V_53 ) - 1 ;
return F_8 ( V_2 -> V_11 . V_14 , V_2 -> V_13 + V_37 ,
V_78 << V_77 ,
div << V_77 ) ;
}
