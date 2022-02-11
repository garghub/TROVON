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
const unsigned int V_10 = V_9 / 3 ;
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
const unsigned int V_10 = V_9 / 3 ;
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
static int F_24 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_4 * V_5 ;
const char * const V_36 = F_25 ( V_34 ) ;
int V_37 ;
V_5 = F_26 ( V_34 , sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return - V_39 ;
if ( ! F_27 ( V_34 , V_12 [ V_35 ] , V_40 , V_36 ) ) {
F_28 ( V_34 , L_1 ,
V_12 [ V_35 ] , V_12 [ V_35 ] + V_40 ) ;
return - V_41 ;
}
V_5 -> V_2 . V_42 = V_36 ;
V_5 -> V_2 . V_43 = V_34 ;
V_5 -> V_2 . V_44 = V_45 ;
V_5 -> V_2 . V_12 = - 1 ;
V_5 -> V_2 . V_46 = 48 ;
V_5 -> V_2 . V_47 = F_1 ;
V_5 -> V_2 . V_48 = F_4 ;
V_5 -> V_2 . V_49 = F_8 ;
V_5 -> V_2 . V_50 = F_9 ;
V_5 -> V_2 . V_51 = F_11 ;
V_5 -> V_12 = V_12 [ V_35 ] ;
V_5 -> V_28 = V_28 [ V_35 ] ;
F_29 ( & V_5 -> V_15 ) ;
F_30 ( V_34 , V_5 ) ;
V_37 = F_31 ( & V_5 -> V_2 , V_5 ) ;
if ( V_37 ) {
F_28 ( V_34 , L_2 , V_37 ) ;
return V_37 ;
}
F_6 ( 0x80 , V_12 [ V_35 ] + 3 ) ;
F_6 ( 0x00 , V_12 [ V_35 ] ) ;
F_6 ( 0x00 , V_12 [ V_35 ] + 1 ) ;
F_6 ( 0x00 , V_12 [ V_35 ] + 2 ) ;
F_6 ( 0x00 , V_12 [ V_35 ] + 3 ) ;
F_6 ( 0x80 , V_12 [ V_35 ] + 7 ) ;
F_6 ( 0x00 , V_12 [ V_35 ] + 4 ) ;
F_6 ( 0x00 , V_12 [ V_35 ] + 5 ) ;
F_6 ( 0x00 , V_12 [ V_35 ] + 6 ) ;
F_6 ( 0x00 , V_12 [ V_35 ] + 7 ) ;
F_10 ( V_12 [ V_35 ] + 0xB ) ;
V_37 = F_32 ( & V_5 -> V_2 , & V_52 , 0 ,
V_53 , V_26 ) ;
if ( V_37 ) {
F_28 ( V_34 , L_3 , V_37 ) ;
goto V_54;
}
V_37 = F_33 ( V_28 [ V_35 ] , F_18 , 0 , V_36 , V_5 ) ;
if ( V_37 ) {
F_28 ( V_34 , L_4 , V_37 ) ;
goto V_54;
}
return 0 ;
V_54:
F_34 ( & V_5 -> V_2 ) ;
return V_37 ;
}
static int F_35 ( struct V_33 * V_34 , unsigned int V_35 )
{
struct V_4 * const V_5 = F_36 ( V_34 ) ;
F_37 ( V_5 -> V_28 , V_5 ) ;
F_34 ( & V_5 -> V_2 ) ;
return 0 ;
}
