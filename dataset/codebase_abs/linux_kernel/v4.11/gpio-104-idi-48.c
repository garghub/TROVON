static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned V_3 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * const V_5 = F_4 ( V_2 ) ;
unsigned V_6 ;
const unsigned V_7 [ 6 ] = { 0 , 1 , 2 , 4 , 5 , 6 } ;
unsigned V_8 ;
unsigned V_9 ;
for ( V_6 = 0 ; V_6 < 48 ; V_6 += 8 )
if ( V_3 < V_6 + 8 ) {
V_8 = V_7 [ V_6 / 8 ] ;
V_9 = F_5 ( V_3 - V_6 ) ;
return ! ! ( F_6 ( V_5 -> V_10 + V_8 ) & V_9 ) ;
}
return 0 ;
}
static void F_7 ( struct V_11 * V_12 )
{
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
struct V_4 * const V_5 = F_4 ( V_2 ) ;
const unsigned V_3 = F_10 ( V_12 ) ;
unsigned V_6 ;
unsigned V_9 ;
unsigned V_13 ;
unsigned long V_14 ;
for ( V_6 = 0 ; V_6 < 48 ; V_6 += 8 )
if ( V_3 < V_6 + 8 ) {
V_9 = F_5 ( V_3 - V_6 ) ;
V_13 = V_6 / 8 ;
V_5 -> V_15 [ V_13 ] &= ~ V_9 ;
if ( ! V_5 -> V_15 [ V_13 ] ) {
V_5 -> V_16 &= ~ F_5 ( V_13 ) ;
F_11 ( & V_5 -> V_17 , V_14 ) ;
F_12 ( V_5 -> V_16 , V_5 -> V_10 + 7 ) ;
F_13 ( & V_5 -> V_17 , V_14 ) ;
}
return;
}
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
struct V_4 * const V_5 = F_4 ( V_2 ) ;
const unsigned V_3 = F_10 ( V_12 ) ;
unsigned V_6 ;
unsigned V_9 ;
unsigned V_13 ;
unsigned V_18 ;
unsigned long V_14 ;
for ( V_6 = 0 ; V_6 < 48 ; V_6 += 8 )
if ( V_3 < V_6 + 8 ) {
V_9 = F_5 ( V_3 - V_6 ) ;
V_13 = V_6 / 8 ;
V_18 = V_5 -> V_15 [ V_13 ] ;
V_5 -> V_15 [ V_13 ] |= V_9 ;
if ( ! V_18 ) {
V_5 -> V_16 |= F_5 ( V_13 ) ;
F_11 ( & V_5 -> V_17 , V_14 ) ;
F_12 ( V_5 -> V_16 , V_5 -> V_10 + 7 ) ;
F_13 ( & V_5 -> V_17 , V_14 ) ;
}
return;
}
}
static int F_15 ( struct V_11 * V_12 , unsigned V_19 )
{
if ( V_19 != V_20 &&
( V_19 & V_21 ) != V_21 )
return - V_22 ;
return 0 ;
}
static T_1 F_16 ( int V_23 , void * V_24 )
{
struct V_4 * const V_5 = V_24 ;
unsigned long V_25 ;
unsigned long V_13 ;
unsigned long V_15 ;
unsigned long V_26 ;
unsigned long V_27 ;
struct V_1 * const V_2 = & V_5 -> V_2 ;
F_17 ( & V_5 -> V_28 ) ;
F_17 ( & V_5 -> V_17 ) ;
V_25 = F_6 ( V_5 -> V_10 + 7 ) ;
F_18 ( & V_5 -> V_17 ) ;
if ( V_25 & F_5 ( 6 ) ) {
F_18 ( & V_5 -> V_28 ) ;
return V_29 ;
}
V_25 &= 0x3F ;
F_19 (boundary, &cos_status, 6 ) {
V_15 = V_5 -> V_15 [ V_13 ] ;
F_19 (bit_num, &irq_mask, 8 ) {
V_27 = V_26 + V_13 * 8 ;
F_20 ( F_21 ( V_2 -> V_30 ,
V_27 ) ) ;
}
}
F_18 ( & V_5 -> V_28 ) ;
return V_31 ;
}
static int F_22 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_4 * V_5 ;
const char * const V_35 = F_23 ( V_33 ) ;
int V_36 ;
V_5 = F_24 ( V_33 , sizeof( * V_5 ) , V_37 ) ;
if ( ! V_5 )
return - V_38 ;
if ( ! F_25 ( V_33 , V_10 [ V_34 ] , V_39 , V_35 ) ) {
F_26 ( V_33 , L_1 ,
V_10 [ V_34 ] , V_10 [ V_34 ] + V_39 ) ;
return - V_40 ;
}
V_5 -> V_2 . V_41 = V_35 ;
V_5 -> V_2 . V_42 = V_33 ;
V_5 -> V_2 . V_43 = V_44 ;
V_5 -> V_2 . V_10 = - 1 ;
V_5 -> V_2 . V_45 = V_46 ;
V_5 -> V_2 . V_47 = V_48 ;
V_5 -> V_2 . V_49 = F_1 ;
V_5 -> V_2 . V_50 = F_2 ;
V_5 -> V_2 . V_51 = F_3 ;
V_5 -> V_10 = V_10 [ V_34 ] ;
F_27 ( & V_5 -> V_17 ) ;
F_27 ( & V_5 -> V_28 ) ;
V_36 = F_28 ( V_33 , & V_5 -> V_2 , V_5 ) ;
if ( V_36 ) {
F_26 ( V_33 , L_2 , V_36 ) ;
return V_36 ;
}
F_12 ( 0 , V_10 [ V_34 ] + 7 ) ;
F_6 ( V_10 [ V_34 ] + 7 ) ;
V_36 = F_29 ( & V_5 -> V_2 , & V_52 , 0 ,
V_53 , V_20 ) ;
if ( V_36 ) {
F_26 ( V_33 , L_3 , V_36 ) ;
return V_36 ;
}
V_36 = F_30 ( V_33 , V_23 [ V_34 ] , F_16 , V_54 ,
V_35 , V_5 ) ;
if ( V_36 ) {
F_26 ( V_33 , L_4 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
