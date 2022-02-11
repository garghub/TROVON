static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
return ! ! ( V_5 -> V_8 [ V_6 ] & V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_9 = V_3 / 8 ;
const unsigned V_10 = V_9 / 2 ;
const unsigned V_11 = V_5 -> V_12 + 3 + V_10 * 4 ;
unsigned long V_13 ;
unsigned V_14 ;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( V_9 == 2 || V_9 == 5 ) {
if ( V_3 % 8 > 3 ) {
V_5 -> V_8 [ V_9 ] |= 0xF0 ;
V_5 -> V_14 [ V_10 ] |= F_3 ( 3 ) ;
} else {
V_5 -> V_8 [ V_9 ] |= 0x0F ;
V_5 -> V_14 [ V_10 ] |= F_3 ( 0 ) ;
}
} else {
V_5 -> V_8 [ V_9 ] |= 0xFF ;
if ( V_9 == 0 || V_9 == 3 )
V_5 -> V_14 [ V_10 ] |= F_3 ( 4 ) ;
else
V_5 -> V_14 [ V_10 ] |= F_3 ( 1 ) ;
}
V_14 = F_3 ( 7 ) | V_5 -> V_14 [ V_10 ] ;
F_6 ( V_14 , V_11 ) ;
V_14 &= ~ F_3 ( 7 ) ;
F_6 ( V_14 , V_11 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_16 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_9 = V_3 / 8 ;
const unsigned V_10 = V_9 / 2 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
const unsigned V_11 = V_5 -> V_12 + 3 + V_10 * 4 ;
const unsigned V_17 = ( V_9 > 2 ) ? V_9 + 1 : V_9 ;
unsigned long V_13 ;
unsigned V_14 ;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( V_9 == 2 || V_9 == 5 ) {
if ( V_3 % 8 > 3 ) {
V_5 -> V_8 [ V_9 ] &= 0x0F ;
V_5 -> V_14 [ V_10 ] &= ~ F_3 ( 3 ) ;
} else {
V_5 -> V_8 [ V_9 ] &= 0xF0 ;
V_5 -> V_14 [ V_10 ] &= ~ F_3 ( 0 ) ;
}
} else {
V_5 -> V_8 [ V_9 ] &= 0x00 ;
if ( V_9 == 0 || V_9 == 3 )
V_5 -> V_14 [ V_10 ] &= ~ F_3 ( 4 ) ;
else
V_5 -> V_14 [ V_10 ] &= ~ F_3 ( 1 ) ;
}
if ( V_16 )
V_5 -> V_18 [ V_9 ] |= V_7 ;
else
V_5 -> V_18 [ V_9 ] &= ~ V_7 ;
V_14 = F_3 ( 7 ) | V_5 -> V_14 [ V_10 ] ;
F_6 ( V_14 , V_11 ) ;
F_6 ( V_5 -> V_18 [ V_9 ] , V_5 -> V_12 + V_17 ) ;
V_14 &= ~ F_3 ( 7 ) ;
F_6 ( V_14 , V_11 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
const unsigned V_19 = ( V_6 > 2 ) ? V_6 + 1 : V_6 ;
unsigned long V_13 ;
unsigned V_20 ;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( ! ( V_5 -> V_8 [ V_6 ] & V_7 ) ) {
F_7 ( & V_5 -> V_15 , V_13 ) ;
return - V_21 ;
}
V_20 = F_10 ( V_5 -> V_12 + V_19 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
return ! ! ( V_20 & V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
const unsigned V_17 = ( V_6 > 2 ) ? V_6 + 1 : V_6 ;
unsigned long V_13 ;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( V_16 )
V_5 -> V_18 [ V_6 ] |= V_7 ;
else
V_5 -> V_18 [ V_6 ] &= ~ V_7 ;
F_6 ( V_5 -> V_18 [ V_6 ] , V_5 -> V_12 + V_17 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
}
static void F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_15 ( V_23 ) ;
unsigned long V_13 ;
if ( V_3 != 19 && V_3 != 43 )
return;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( V_3 == 19 )
V_5 -> V_24 &= ~ F_3 ( 0 ) ;
else
V_5 -> V_24 &= ~ F_3 ( 1 ) ;
if ( ! V_5 -> V_24 )
F_10 ( V_5 -> V_12 + 0xB ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_14 ( V_23 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_15 ( V_23 ) ;
unsigned long V_13 ;
if ( V_3 != 19 && V_3 != 43 )
return;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( ! V_5 -> V_24 ) {
F_6 ( 0x00 , V_5 -> V_12 + 0xF ) ;
F_6 ( 0x00 , V_5 -> V_12 + 0xB ) ;
}
if ( V_3 == 19 )
V_5 -> V_24 |= F_3 ( 0 ) ;
else
V_5 -> V_24 |= F_3 ( 1 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
}
static int F_17 ( struct V_22 * V_23 , unsigned V_25 )
{
const unsigned long V_3 = F_15 ( V_23 ) ;
if ( V_3 != 19 && V_3 != 43 )
return - V_21 ;
if ( V_25 != V_26 && V_25 != V_27 )
return - V_21 ;
return 0 ;
}
static T_1 F_18 ( int V_28 , void * V_29 )
{
struct V_4 * const V_5 = V_29 ;
struct V_1 * const V_2 = & V_5 -> V_2 ;
const unsigned long V_24 = V_5 -> V_24 ;
unsigned long V_30 ;
F_19 (gpio, &irq_mask, 2 )
F_20 ( F_21 ( V_2 -> V_31 ,
19 + V_30 * 24 ) ) ;
F_22 ( & V_5 -> V_15 ) ;
F_6 ( 0x00 , V_5 -> V_12 + 0xF ) ;
F_23 ( & V_5 -> V_15 ) ;
return V_32 ;
}
static int T_2 F_24 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = & V_34 -> V_36 ;
struct V_4 * V_5 ;
const unsigned V_12 = V_37 ;
const unsigned V_38 = 16 ;
const char * const V_39 = F_25 ( V_36 ) ;
int V_40 ;
const unsigned V_28 = V_41 ;
V_5 = F_26 ( V_36 , sizeof( * V_5 ) , V_42 ) ;
if ( ! V_5 )
return - V_43 ;
if ( ! F_27 ( V_36 , V_12 , V_38 , V_39 ) ) {
F_28 ( V_36 , L_1 ,
V_12 , V_12 + V_38 ) ;
return - V_44 ;
}
V_5 -> V_2 . V_45 = V_39 ;
V_5 -> V_2 . V_46 = V_36 ;
V_5 -> V_2 . V_47 = V_48 ;
V_5 -> V_2 . V_12 = - 1 ;
V_5 -> V_2 . V_49 = 48 ;
V_5 -> V_2 . V_50 = F_1 ;
V_5 -> V_2 . V_51 = F_4 ;
V_5 -> V_2 . V_52 = F_8 ;
V_5 -> V_2 . V_53 = F_9 ;
V_5 -> V_2 . V_54 = F_11 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_28 = V_28 ;
F_29 ( & V_5 -> V_15 ) ;
F_30 ( V_36 , V_5 ) ;
V_40 = F_31 ( & V_5 -> V_2 , V_5 ) ;
if ( V_40 ) {
F_28 ( V_36 , L_2 , V_40 ) ;
return V_40 ;
}
F_6 ( 0x80 , V_12 + 3 ) ;
F_6 ( 0x00 , V_12 ) ;
F_6 ( 0x00 , V_12 + 1 ) ;
F_6 ( 0x00 , V_12 + 2 ) ;
F_6 ( 0x00 , V_12 + 3 ) ;
F_6 ( 0x80 , V_12 + 7 ) ;
F_6 ( 0x00 , V_12 + 4 ) ;
F_6 ( 0x00 , V_12 + 5 ) ;
F_6 ( 0x00 , V_12 + 6 ) ;
F_6 ( 0x00 , V_12 + 7 ) ;
F_10 ( V_12 + 0xB ) ;
V_40 = F_32 ( & V_5 -> V_2 , & V_55 , 0 ,
V_56 , V_26 ) ;
if ( V_40 ) {
F_28 ( V_36 , L_3 , V_40 ) ;
goto V_57;
}
V_40 = F_33 ( V_28 , F_18 , 0 , V_39 , V_5 ) ;
if ( V_40 ) {
F_28 ( V_36 , L_4 , V_40 ) ;
goto V_57;
}
return 0 ;
V_57:
F_34 ( & V_5 -> V_2 ) ;
return V_40 ;
}
static int F_35 ( struct V_33 * V_34 )
{
struct V_4 * const V_5 = F_36 ( V_34 ) ;
F_37 ( V_5 -> V_28 , V_5 ) ;
F_34 ( & V_5 -> V_2 ) ;
return 0 ;
}
static void T_3 F_38 ( void )
{
F_39 ( V_58 ) ;
F_40 ( & V_59 ) ;
}
static int T_2 F_41 ( void )
{
int V_40 ;
V_58 = F_42 ( V_59 . V_60 . V_39 , - 1 ) ;
if ( ! V_58 )
return - V_43 ;
V_40 = F_43 ( V_58 ) ;
if ( V_40 )
goto V_61;
V_40 = F_44 ( & V_59 , F_24 ) ;
if ( V_40 )
goto V_62;
return 0 ;
V_62:
F_45 ( V_58 ) ;
V_61:
F_46 ( V_58 ) ;
return V_40 ;
}
