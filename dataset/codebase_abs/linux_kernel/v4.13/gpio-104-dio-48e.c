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
static void F_12 ( struct V_1 * V_2 ,
unsigned long * V_7 , unsigned long * V_22 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
unsigned int V_23 ;
const unsigned int V_24 = 8 ;
unsigned int V_6 ;
unsigned int V_17 ;
unsigned int V_25 ;
unsigned long V_13 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_26 ; V_23 += V_24 ) {
if ( ! V_7 [ F_13 ( V_23 ) ] ) {
V_23 = ( F_13 ( V_23 ) + 1 ) * V_27 - V_24 ;
continue;
}
V_6 = V_23 / V_24 ;
V_17 = ( V_6 > 2 ) ? V_6 + 1 : V_6 ;
V_25 = V_7 [ F_13 ( V_23 ) ] & V_22 [ F_13 ( V_23 ) ] ;
F_5 ( & V_5 -> V_15 , V_13 ) ;
V_5 -> V_18 [ V_6 ] &= ~ V_7 [ F_13 ( V_23 ) ] ;
V_5 -> V_18 [ V_6 ] |= V_25 ;
F_6 ( V_5 -> V_18 [ V_6 ] , V_5 -> V_12 + V_17 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
V_7 [ F_13 ( V_23 ) ] >>= V_24 ;
V_22 [ F_13 ( V_23 ) ] >>= V_24 ;
}
}
static void F_14 ( struct V_28 * V_29 )
{
}
static void F_15 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_16 ( V_29 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_17 ( V_29 ) ;
unsigned long V_13 ;
if ( V_3 != 19 && V_3 != 43 )
return;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( V_3 == 19 )
V_5 -> V_30 &= ~ F_3 ( 0 ) ;
else
V_5 -> V_30 &= ~ F_3 ( 1 ) ;
if ( ! V_5 -> V_30 )
F_10 ( V_5 -> V_12 + 0xB ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
}
static void F_18 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_16 ( V_29 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_17 ( V_29 ) ;
unsigned long V_13 ;
if ( V_3 != 19 && V_3 != 43 )
return;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( ! V_5 -> V_30 ) {
F_6 ( 0x00 , V_5 -> V_12 + 0xF ) ;
F_6 ( 0x00 , V_5 -> V_12 + 0xB ) ;
}
if ( V_3 == 19 )
V_5 -> V_30 |= F_3 ( 0 ) ;
else
V_5 -> V_30 |= F_3 ( 1 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
}
static int F_19 ( struct V_28 * V_29 , unsigned V_31 )
{
const unsigned long V_3 = F_17 ( V_29 ) ;
if ( V_3 != 19 && V_3 != 43 )
return - V_21 ;
if ( V_31 != V_32 && V_31 != V_33 )
return - V_21 ;
return 0 ;
}
static T_1 F_20 ( int V_34 , void * V_35 )
{
struct V_4 * const V_5 = V_35 ;
struct V_1 * const V_2 = & V_5 -> V_2 ;
const unsigned long V_30 = V_5 -> V_30 ;
unsigned long V_36 ;
F_21 (gpio, &irq_mask, 2 )
F_22 ( F_23 ( V_2 -> V_37 ,
19 + V_36 * 24 ) ) ;
F_24 ( & V_5 -> V_15 ) ;
F_6 ( 0x00 , V_5 -> V_12 + 0xF ) ;
F_25 ( & V_5 -> V_15 ) ;
return V_38 ;
}
static int F_26 ( struct V_39 * V_40 , unsigned int V_41 )
{
struct V_4 * V_5 ;
const char * const V_42 = F_27 ( V_40 ) ;
int V_43 ;
V_5 = F_28 ( V_40 , sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
return - V_45 ;
if ( ! F_29 ( V_40 , V_12 [ V_41 ] , V_46 , V_42 ) ) {
F_30 ( V_40 , L_1 ,
V_12 [ V_41 ] , V_12 [ V_41 ] + V_46 ) ;
return - V_47 ;
}
V_5 -> V_2 . V_48 = V_42 ;
V_5 -> V_2 . V_49 = V_40 ;
V_5 -> V_2 . V_50 = V_51 ;
V_5 -> V_2 . V_12 = - 1 ;
V_5 -> V_2 . V_26 = V_52 ;
V_5 -> V_2 . V_53 = V_54 ;
V_5 -> V_2 . V_55 = F_1 ;
V_5 -> V_2 . V_56 = F_4 ;
V_5 -> V_2 . V_57 = F_8 ;
V_5 -> V_2 . V_58 = F_9 ;
V_5 -> V_2 . V_59 = F_11 ;
V_5 -> V_2 . V_60 = F_12 ;
V_5 -> V_12 = V_12 [ V_41 ] ;
F_31 ( & V_5 -> V_15 ) ;
V_43 = F_32 ( V_40 , & V_5 -> V_2 , V_5 ) ;
if ( V_43 ) {
F_30 ( V_40 , L_2 , V_43 ) ;
return V_43 ;
}
F_6 ( 0x80 , V_12 [ V_41 ] + 3 ) ;
F_6 ( 0x00 , V_12 [ V_41 ] ) ;
F_6 ( 0x00 , V_12 [ V_41 ] + 1 ) ;
F_6 ( 0x00 , V_12 [ V_41 ] + 2 ) ;
F_6 ( 0x00 , V_12 [ V_41 ] + 3 ) ;
F_6 ( 0x80 , V_12 [ V_41 ] + 7 ) ;
F_6 ( 0x00 , V_12 [ V_41 ] + 4 ) ;
F_6 ( 0x00 , V_12 [ V_41 ] + 5 ) ;
F_6 ( 0x00 , V_12 [ V_41 ] + 6 ) ;
F_6 ( 0x00 , V_12 [ V_41 ] + 7 ) ;
F_10 ( V_12 [ V_41 ] + 0xB ) ;
V_43 = F_33 ( & V_5 -> V_2 , & V_61 , 0 ,
V_62 , V_32 ) ;
if ( V_43 ) {
F_30 ( V_40 , L_3 , V_43 ) ;
return V_43 ;
}
V_43 = F_34 ( V_40 , V_34 [ V_41 ] , F_20 , 0 , V_42 ,
V_5 ) ;
if ( V_43 ) {
F_30 ( V_40 , L_4 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
