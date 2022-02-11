static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( V_3 > 15 )
return 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
V_2 -> V_5 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
unsigned long V_8 = F_6 ( V_3 ) ;
if ( V_3 < 8 )
return ! ! ( F_7 ( & V_7 -> V_9 -> V_10 ) & V_8 ) ;
if ( V_3 < 16 )
return ! ! ( F_7 ( & V_7 -> V_9 -> V_11 ) & ( V_8 >> 8 ) ) ;
if ( V_3 < 24 )
return ! ! ( F_7 ( & V_7 -> V_9 -> V_12 ) & ( V_8 >> 16 ) ) ;
return ! ! ( F_7 ( & V_7 -> V_9 -> V_13 ) & ( V_8 >> 24 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
unsigned int V_8 = F_6 ( V_3 ) ;
void T_1 * V_14 ;
unsigned long V_15 ;
unsigned int V_16 ;
if ( V_3 > 15 )
return;
if ( V_3 > 7 ) {
V_8 >>= 8 ;
V_14 = & V_7 -> V_9 -> V_11 ;
} else
V_14 = & V_7 -> V_9 -> V_10 ;
F_9 ( & V_7 -> V_17 , V_15 ) ;
if ( V_4 )
V_16 = F_7 ( V_14 ) | V_8 ;
else
V_16 = F_7 ( V_14 ) & ~ V_8 ;
F_10 ( V_16 , V_14 ) ;
F_11 ( & V_7 -> V_17 , V_15 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned long * V_8 , unsigned long * V_18 )
{
struct V_6 * const V_7 = F_5 ( V_2 ) ;
unsigned long V_15 ;
unsigned int V_16 ;
F_9 ( & V_7 -> V_17 , V_15 ) ;
if ( * V_8 & 0xFF ) {
V_16 = F_7 ( & V_7 -> V_9 -> V_10 ) & ~ * V_8 ;
V_16 |= * V_8 & * V_18 ;
F_10 ( V_16 , & V_7 -> V_9 -> V_10 ) ;
}
* V_8 >>= 8 ;
if ( * V_8 & 0xFF ) {
* V_18 >>= 8 ;
V_16 = F_7 ( & V_7 -> V_9 -> V_11 ) & ~ * V_8 ;
V_16 |= * V_8 & * V_18 ;
F_10 ( V_16 , & V_7 -> V_9 -> V_11 ) ;
}
F_11 ( & V_7 -> V_17 , V_15 ) ;
}
static void F_13 ( struct V_19 * V_20 )
{
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_15 ( V_20 ) ;
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned long V_8 = F_6 ( F_16 ( V_20 ) ) ;
unsigned long V_15 ;
V_7 -> V_21 &= ~ V_8 ;
if ( ! V_7 -> V_21 ) {
F_9 ( & V_7 -> V_17 , V_15 ) ;
F_10 ( 0 , & V_7 -> V_9 -> V_22 ) ;
F_11 ( & V_7 -> V_17 , V_15 ) ;
}
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_15 ( V_20 ) ;
struct V_6 * const V_7 = F_5 ( V_2 ) ;
const unsigned long V_8 = F_6 ( F_16 ( V_20 ) ) ;
const unsigned long V_23 = V_7 -> V_21 ;
unsigned long V_15 ;
V_7 -> V_21 |= V_8 ;
if ( ! V_23 ) {
F_9 ( & V_7 -> V_17 , V_15 ) ;
F_7 ( & V_7 -> V_9 -> V_22 ) ;
F_11 ( & V_7 -> V_17 , V_15 ) ;
}
}
static int F_18 ( struct V_19 * V_20 , unsigned int V_24 )
{
if ( V_24 != V_25 &&
( V_24 & V_26 ) != V_26 )
return - V_27 ;
return 0 ;
}
static T_2 F_19 ( int V_28 , void * V_29 )
{
struct V_6 * const V_7 = V_29 ;
unsigned int V_30 ;
struct V_1 * const V_2 = & V_7 -> V_2 ;
int V_31 ;
F_20 ( & V_7 -> V_17 ) ;
V_30 = F_7 ( & V_7 -> V_9 -> V_30 ) ;
F_21 ( & V_7 -> V_17 ) ;
if ( ! ( V_30 & 0x3 ) || ! ( V_30 & 0x4 ) )
return V_32 ;
F_22 (gpio, &idio16gpio->irq_mask, chip->ngpio)
F_23 ( F_24 ( V_2 -> V_33 , V_31 ) ) ;
F_20 ( & V_7 -> V_17 ) ;
F_10 ( 0 , & V_7 -> V_9 -> V_12 ) ;
F_21 ( & V_7 -> V_17 ) ;
return V_34 ;
}
static int F_25 ( struct V_35 * V_36 , const struct V_37 * V_38 )
{
struct V_39 * const V_40 = & V_36 -> V_40 ;
struct V_6 * V_7 ;
int V_41 ;
const T_3 V_42 = 2 ;
const char * const V_43 = F_26 ( V_36 ) ;
V_7 = F_27 ( V_40 , sizeof( * V_7 ) , V_44 ) ;
if ( ! V_7 )
return - V_45 ;
V_41 = F_28 ( V_36 ) ;
if ( V_41 ) {
F_29 ( V_40 , L_1 , V_41 ) ;
return V_41 ;
}
V_41 = F_30 ( V_36 , F_6 ( V_42 ) , V_43 ) ;
if ( V_41 ) {
F_29 ( V_40 , L_2 , V_41 ) ;
return V_41 ;
}
V_7 -> V_9 = F_31 ( V_36 ) [ V_42 ] ;
F_10 ( 0 , & V_7 -> V_9 -> V_46 ) ;
V_7 -> V_2 . V_47 = V_43 ;
V_7 -> V_2 . V_48 = V_40 ;
V_7 -> V_2 . V_49 = V_50 ;
V_7 -> V_2 . V_14 = - 1 ;
V_7 -> V_2 . V_51 = V_52 ;
V_7 -> V_2 . V_53 = V_54 ;
V_7 -> V_2 . V_55 = F_1 ;
V_7 -> V_2 . V_56 = F_2 ;
V_7 -> V_2 . V_57 = F_3 ;
V_7 -> V_2 . V_58 = F_4 ;
V_7 -> V_2 . V_5 = F_8 ;
V_7 -> V_2 . V_59 = F_12 ;
F_32 ( & V_7 -> V_17 ) ;
V_41 = F_33 ( V_40 , & V_7 -> V_2 , V_7 ) ;
if ( V_41 ) {
F_29 ( V_40 , L_3 , V_41 ) ;
return V_41 ;
}
F_10 ( 0 , & V_7 -> V_9 -> V_22 ) ;
F_10 ( 0 , & V_7 -> V_9 -> V_12 ) ;
V_41 = F_34 ( & V_7 -> V_2 , & V_60 , 0 ,
V_61 , V_25 ) ;
if ( V_41 ) {
F_29 ( V_40 , L_4 , V_41 ) ;
return V_41 ;
}
V_41 = F_35 ( V_40 , V_36 -> V_28 , F_19 , V_62 ,
V_43 , V_7 ) ;
if ( V_41 ) {
F_29 ( V_40 , L_5 , V_41 ) ;
return V_41 ;
}
return 0 ;
}
