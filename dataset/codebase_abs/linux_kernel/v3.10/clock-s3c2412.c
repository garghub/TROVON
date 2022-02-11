static int F_1 ( struct V_1 * V_1 , int V_2 )
{
unsigned int V_3 = V_1 -> V_4 ;
unsigned long V_5 ;
V_5 = F_2 ( V_6 ) ;
if ( V_2 )
V_5 |= V_3 ;
else
V_5 &= ~ V_3 ;
F_3 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_2 )
{
unsigned long V_7 = F_2 ( V_8 ) ;
unsigned long V_9 = V_7 ;
if ( ! V_2 )
V_7 |= V_10 ;
else
V_7 &= ~ V_10 ;
F_3 ( V_7 , V_8 ) ;
if ( V_2 && ( V_9 & V_10 ) )
F_5 ( 150 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , struct V_1 * V_11 )
{
unsigned long V_12 = F_2 ( V_13 ) ;
if ( V_11 == & V_14 )
V_12 &= ~ V_15 ;
else if ( V_11 == & V_16 )
V_12 |= V_15 ;
else
return - V_17 ;
V_1 -> V_11 = V_11 ;
F_3 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_1 * V_11 )
{
unsigned long V_12 = F_2 ( V_13 ) ;
if ( V_11 == & V_18 )
V_12 &= ~ V_19 ;
else if ( V_11 == & V_20 )
V_12 |= V_19 ;
else
return - V_17 ;
V_1 -> V_11 = V_11 ;
F_3 ( V_12 , V_13 ) ;
return 0 ;
}
static unsigned long F_8 ( struct V_1 * V_1 ,
unsigned long V_21 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
int div ;
if ( V_21 > V_22 )
return V_22 ;
div = V_22 / V_21 ;
if ( div > 2 )
div = 2 ;
return V_22 / div ;
}
static unsigned long F_10 ( struct V_1 * V_1 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long div = F_2 ( V_23 ) ;
return V_22 / ( ( div & V_24 ) ? 2 : 1 ) ;
}
static int F_11 ( struct V_1 * V_1 , unsigned long V_21 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long V_25 = F_2 ( V_23 ) ;
V_21 = F_8 ( V_1 , V_21 ) ;
if ( ( V_22 / V_21 ) == 2 )
V_25 |= V_24 ;
else
V_25 &= ~ V_24 ;
F_3 ( V_25 , V_23 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_1 * V_11 )
{
unsigned long V_12 = F_2 ( V_13 ) ;
if ( V_11 == & V_26 )
V_12 &= ~ V_27 ;
else if ( V_11 == & V_28 )
V_12 |= V_27 ;
else
return - V_17 ;
V_1 -> V_11 = V_11 ;
F_3 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , struct V_1 * V_11 )
{
unsigned long V_29 ;
unsigned long V_30 ;
unsigned long V_31 ;
if ( V_11 == & V_32 || V_11 == & V_33 )
V_31 = 0 ;
else if ( V_11 == & V_20 )
V_31 = V_34 ;
else
return - V_17 ;
V_1 -> V_11 = V_11 ;
F_14 ( V_29 ) ;
V_30 = F_2 ( V_23 ) ;
V_30 &= ~ V_34 ;
V_30 |= V_31 ;
F_3 ( V_30 , V_23 ) ;
F_15 ( V_29 ) ;
return 0 ;
}
static unsigned long F_16 ( struct V_1 * V_1 ,
unsigned long V_21 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
int div ;
if ( V_21 > V_22 )
return V_22 ;
div = ( V_21 / V_22 ) ;
if ( div < 1 )
div = 1 ;
else if ( div > 16 )
div = 16 ;
return V_22 / div ;
}
static int F_17 ( struct V_1 * V_1 , struct V_1 * V_11 )
{
unsigned long V_12 = F_2 ( V_13 ) ;
if ( V_11 == & V_35 )
V_12 &= ~ V_36 ;
else if ( V_11 == & V_28 )
V_12 |= V_36 ;
else
return - V_17 ;
V_1 -> V_11 = V_11 ;
F_3 ( V_12 , V_13 ) ;
return 0 ;
}
static unsigned long F_18 ( struct V_1 * V_1 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long div = F_2 ( V_23 ) ;
div &= V_37 ;
div >>= V_38 ;
return V_22 / ( div + 1 ) ;
}
static int F_19 ( struct V_1 * V_1 , unsigned long V_21 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long V_25 = F_2 ( V_23 ) ;
V_21 = F_16 ( V_1 , V_21 ) ;
V_25 &= ~ V_37 ;
V_25 |= ( ( V_22 / V_21 ) - 1 ) << V_38 ;
F_3 ( V_25 , V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , struct V_1 * V_11 )
{
unsigned long V_12 = F_2 ( V_13 ) ;
if ( V_11 == & V_35 )
V_12 &= ~ V_39 ;
else if ( V_11 == & V_28 )
V_12 |= V_39 ;
else
return - V_17 ;
V_1 -> V_11 = V_11 ;
F_3 ( V_12 , V_13 ) ;
return 0 ;
}
static unsigned long F_21 ( struct V_1 * V_1 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long div = F_2 ( V_23 ) ;
div &= V_40 ;
div >>= V_41 ;
return V_22 / ( div + 1 ) ;
}
static int F_22 ( struct V_1 * V_1 , unsigned long V_21 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long V_25 = F_2 ( V_23 ) ;
V_21 = F_16 ( V_1 , V_21 ) ;
V_25 &= ~ V_40 ;
V_25 |= ( ( V_22 / V_21 ) - 1 ) << V_41 ;
F_3 ( V_25 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , struct V_1 * V_11 )
{
unsigned long V_12 = F_2 ( V_13 ) ;
if ( V_11 == & V_18 )
V_12 &= ~ V_42 ;
else if ( V_11 == & V_20 )
V_12 |= V_42 ;
else
return - V_17 ;
V_1 -> V_11 = V_11 ;
F_3 ( V_12 , V_13 ) ;
return 0 ;
}
static unsigned long F_24 ( struct V_1 * V_1 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long div = F_2 ( V_23 ) ;
div &= V_43 ;
div >>= V_44 ;
return V_22 / ( div + 1 ) ;
}
static int F_25 ( struct V_1 * V_1 , unsigned long V_21 )
{
unsigned long V_22 = F_9 ( V_1 -> V_11 ) ;
unsigned long V_25 = F_2 ( V_23 ) ;
V_21 = F_16 ( V_1 , V_21 ) ;
V_25 &= ~ V_43 ;
V_25 |= ( ( V_22 / V_21 ) - 1 ) << V_44 ;
F_3 ( V_25 , V_23 ) ;
return 0 ;
}
static void T_1 F_26 ( void )
{
unsigned long V_12 = F_2 ( V_13 ) ;
struct V_45 * V_46 = V_47 ;
struct V_1 * V_48 ;
int V_49 ;
int V_50 ;
for ( V_49 = 0 ; V_49 < F_27 ( V_47 ) ; V_49 ++ , V_46 ++ ) {
V_50 = F_28 ( V_46 -> V_1 ) ;
if ( V_50 < 0 ) {
F_29 ( V_51 L_1 ,
V_46 -> V_1 -> V_52 , V_50 ) ;
}
V_48 = ( V_12 & V_46 -> V_53 ) ? V_46 -> V_54 : V_46 -> V_55 ;
F_29 ( V_56 L_2 , V_46 -> V_1 -> V_52 , V_48 -> V_52 ) ;
F_30 ( V_46 -> V_1 , V_48 ) ;
}
}
int T_1 F_31 ( void )
{
unsigned long V_5 = F_2 ( V_6 ) ;
unsigned int V_31 ;
struct V_1 * V_57 ;
int V_50 ;
int V_49 ;
V_16 . V_2 = F_4 ;
V_58 . V_11 = & V_59 ;
V_58 . V_21 = 0x0 ;
V_33 . V_11 = & V_32 ;
F_26 () ;
for ( V_49 = 0 ; V_49 < F_27 ( V_60 ) ; V_49 ++ ) {
V_57 = V_60 [ V_49 ] ;
V_50 = F_28 ( V_57 ) ;
if ( V_50 < 0 ) {
F_29 ( V_51 L_1 ,
V_57 -> V_52 , V_50 ) ;
}
}
V_31 = F_2 ( V_23 ) & V_34 ;
if ( V_31 )
V_61 . V_11 = & V_20 ;
F_29 ( V_56 L_3 , V_31 ? L_4 : L_5 ) ;
if ( F_9 ( & V_58 ) != ( 48 * 1000 * 1000 ) ) {
F_29 ( V_56 L_6 ) ;
F_30 ( & V_18 , & V_16 ) ;
F_30 ( & V_59 , & V_18 ) ;
F_32 ( & V_59 , 48 * 1000 * 1000 ) ;
}
F_29 ( L_7 ,
( F_2 ( V_8 ) & V_10 ) ? L_5 : L_4 ,
F_33 ( F_9 ( & V_16 ) ) ,
F_33 ( F_9 ( & V_58 ) ) ) ;
V_57 = V_62 ;
for ( V_49 = 0 ; V_49 < F_27 ( V_62 ) ; V_49 ++ , V_57 ++ ) {
V_57 -> V_63 = V_5 & V_57 -> V_4 ? 1 : 0 ;
V_50 = F_28 ( V_57 ) ;
if ( V_50 < 0 ) {
F_29 ( V_51 L_1 ,
V_57 -> V_52 , V_50 ) ;
}
}
V_57 = V_64 ;
for ( V_49 = 0 ; V_49 < F_27 ( V_64 ) ; V_49 ++ , V_57 ++ ) {
V_50 = F_28 ( V_57 ) ;
if ( V_50 < 0 ) {
F_29 ( V_51 L_1 ,
V_57 -> V_52 , V_50 ) ;
}
F_1 ( V_57 , 0 ) ;
}
F_34 ( V_65 , F_27 ( V_65 ) ) ;
F_35 () ;
return 0 ;
}
