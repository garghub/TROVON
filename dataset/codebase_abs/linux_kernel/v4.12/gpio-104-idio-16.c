static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 > 15 )
return 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned V_3 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
V_2 -> V_5 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned V_8 = F_6 ( V_3 - 16 ) ;
if ( V_3 < 16 )
return - V_9 ;
if ( V_3 < 24 )
return ! ! ( F_7 ( V_7 -> V_10 + 1 ) & V_8 ) ;
return ! ! ( F_7 ( V_7 -> V_10 + 5 ) & ( V_8 >> 8 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned V_8 = F_6 ( V_3 ) ;
unsigned long V_11 ;
if ( V_3 > 15 )
return;
F_9 ( & V_7 -> V_12 , V_11 ) ;
if ( V_4 )
V_7 -> V_13 |= V_8 ;
else
V_7 -> V_13 &= ~ V_8 ;
if ( V_3 > 7 )
F_10 ( V_7 -> V_13 >> 8 , V_7 -> V_10 + 4 ) ;
else
F_10 ( V_7 -> V_13 , V_7 -> V_10 ) ;
F_11 ( & V_7 -> V_12 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned long * V_8 , unsigned long * V_14 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
unsigned long V_11 ;
F_9 ( & V_7 -> V_12 , V_11 ) ;
V_7 -> V_13 &= ~ * V_8 ;
V_7 -> V_13 |= * V_8 & * V_14 ;
if ( * V_8 & 0xFF )
F_10 ( V_7 -> V_13 , V_7 -> V_10 ) ;
if ( ( * V_8 >> 8 ) & 0xFF )
F_10 ( V_7 -> V_13 >> 8 , V_7 -> V_10 + 4 ) ;
F_11 ( & V_7 -> V_12 , V_11 ) ;
}
static void F_13 ( struct V_15 * V_16 )
{
}
static void F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned long V_8 = F_6 ( F_16 ( V_16 ) ) ;
unsigned long V_11 ;
V_7 -> V_17 &= ~ V_8 ;
if ( ! V_7 -> V_17 ) {
F_9 ( & V_7 -> V_12 , V_11 ) ;
F_10 ( 0 , V_7 -> V_10 + 2 ) ;
F_11 ( & V_7 -> V_12 , V_11 ) ;
}
}
static void F_17 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned long V_8 = F_6 ( F_16 ( V_16 ) ) ;
const unsigned long V_18 = V_7 -> V_17 ;
unsigned long V_11 ;
V_7 -> V_17 |= V_8 ;
if ( ! V_18 ) {
F_9 ( & V_7 -> V_12 , V_11 ) ;
F_7 ( V_7 -> V_10 + 2 ) ;
F_11 ( & V_7 -> V_12 , V_11 ) ;
}
}
static int F_18 ( struct V_15 * V_16 , unsigned V_19 )
{
if ( V_19 != V_20 &&
( V_19 & V_21 ) != V_21 )
return - V_9 ;
return 0 ;
}
static T_1 F_19 ( int V_22 , void * V_23 )
{
struct V_6 * const V_7 = V_23 ;
struct V_1 * const V_2 = & V_7 -> V_2 ;
int V_24 ;
F_20 (gpio, &idio16gpio->irq_mask, chip->ngpio)
F_21 ( F_22 ( V_2 -> V_25 , V_24 ) ) ;
F_23 ( & V_7 -> V_12 ) ;
F_10 ( 0 , V_7 -> V_10 + 1 ) ;
F_24 ( & V_7 -> V_12 ) ;
return V_26 ;
}
static int F_25 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_6 * V_7 ;
const char * const V_30 = F_26 ( V_28 ) ;
int V_31 ;
V_7 = F_27 ( V_28 , sizeof( * V_7 ) , V_32 ) ;
if ( ! V_7 )
return - V_33 ;
if ( ! F_28 ( V_28 , V_10 [ V_29 ] , V_34 , V_30 ) ) {
F_29 ( V_28 , L_1 ,
V_10 [ V_29 ] , V_10 [ V_29 ] + V_34 ) ;
return - V_35 ;
}
V_7 -> V_2 . V_36 = V_30 ;
V_7 -> V_2 . V_37 = V_28 ;
V_7 -> V_2 . V_38 = V_39 ;
V_7 -> V_2 . V_10 = - 1 ;
V_7 -> V_2 . V_40 = V_41 ;
V_7 -> V_2 . V_42 = V_43 ;
V_7 -> V_2 . V_44 = F_1 ;
V_7 -> V_2 . V_45 = F_2 ;
V_7 -> V_2 . V_46 = F_3 ;
V_7 -> V_2 . V_47 = F_4 ;
V_7 -> V_2 . V_5 = F_8 ;
V_7 -> V_2 . V_48 = F_12 ;
V_7 -> V_10 = V_10 [ V_29 ] ;
V_7 -> V_13 = 0xFFFF ;
F_30 ( & V_7 -> V_12 ) ;
V_31 = F_31 ( V_28 , & V_7 -> V_2 , V_7 ) ;
if ( V_31 ) {
F_29 ( V_28 , L_2 , V_31 ) ;
return V_31 ;
}
F_10 ( 0 , V_10 [ V_29 ] + 2 ) ;
F_10 ( 0 , V_10 [ V_29 ] + 1 ) ;
V_31 = F_32 ( & V_7 -> V_2 , & V_49 , 0 ,
V_50 , V_20 ) ;
if ( V_31 ) {
F_29 ( V_28 , L_3 , V_31 ) ;
return V_31 ;
}
V_31 = F_33 ( V_28 , V_22 [ V_29 ] , F_19 , 0 , V_30 ,
V_7 ) ;
if ( V_31 ) {
F_29 ( V_28 , L_4 , V_31 ) ;
return V_31 ;
}
return 0 ;
}
