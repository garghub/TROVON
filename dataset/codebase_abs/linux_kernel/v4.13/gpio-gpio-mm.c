static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned int V_6 = V_3 / 8 ;
const unsigned int V_7 = F_3 ( V_3 % 8 ) ;
return ! ! ( V_5 -> V_8 [ V_6 ] & V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned int V_9 = V_3 / 8 ;
const unsigned int V_10 = V_9 / 3 ;
const unsigned int V_11 = V_5 -> V_12 + 3 + V_10 * 4 ;
unsigned long V_13 ;
unsigned int V_14 ;
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
F_7 ( & V_5 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_16 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned int V_9 = V_3 / 8 ;
const unsigned int V_10 = V_9 / 3 ;
const unsigned int V_7 = F_3 ( V_3 % 8 ) ;
const unsigned int V_11 = V_5 -> V_12 + 3 + V_10 * 4 ;
const unsigned int V_17 = ( V_9 > 2 ) ? V_9 + 1 : V_9 ;
unsigned long V_13 ;
unsigned int V_14 ;
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
F_7 ( & V_5 -> V_15 , V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned int V_6 = V_3 / 8 ;
const unsigned int V_7 = F_3 ( V_3 % 8 ) ;
const unsigned int V_19 = ( V_6 > 2 ) ? V_6 + 1 : V_6 ;
unsigned long V_13 ;
unsigned int V_20 ;
F_5 ( & V_5 -> V_15 , V_13 ) ;
if ( ! ( V_5 -> V_8 [ V_6 ] & V_7 ) ) {
F_7 ( & V_5 -> V_15 , V_13 ) ;
return - V_21 ;
}
V_20 = F_10 ( V_5 -> V_12 + V_19 ) ;
F_7 ( & V_5 -> V_15 , V_13 ) ;
return ! ! ( V_20 & V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_16 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned int V_6 = V_3 / 8 ;
const unsigned int V_7 = F_3 ( V_3 % 8 ) ;
const unsigned int V_17 = ( V_6 > 2 ) ? V_6 + 1 : V_6 ;
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
static int F_14 ( struct V_28 * V_29 , unsigned int V_30 )
{
struct V_4 * V_5 ;
const char * const V_31 = F_15 ( V_29 ) ;
int V_32 ;
V_5 = F_16 ( V_29 , sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 )
return - V_34 ;
if ( ! F_17 ( V_29 , V_12 [ V_30 ] , V_35 , V_31 ) ) {
F_18 ( V_29 , L_1 ,
V_12 [ V_30 ] , V_12 [ V_30 ] + V_35 ) ;
return - V_36 ;
}
V_5 -> V_2 . V_37 = V_31 ;
V_5 -> V_2 . V_38 = V_29 ;
V_5 -> V_2 . V_39 = V_40 ;
V_5 -> V_2 . V_12 = - 1 ;
V_5 -> V_2 . V_26 = V_41 ;
V_5 -> V_2 . V_42 = V_43 ;
V_5 -> V_2 . V_44 = F_1 ;
V_5 -> V_2 . V_45 = F_4 ;
V_5 -> V_2 . V_46 = F_8 ;
V_5 -> V_2 . V_47 = F_9 ;
V_5 -> V_2 . V_48 = F_11 ;
V_5 -> V_2 . V_49 = F_12 ;
V_5 -> V_12 = V_12 [ V_30 ] ;
F_19 ( & V_5 -> V_15 ) ;
V_32 = F_20 ( V_29 , & V_5 -> V_2 , V_5 ) ;
if ( V_32 ) {
F_18 ( V_29 , L_2 , V_32 ) ;
return V_32 ;
}
F_6 ( 0x80 , V_12 [ V_30 ] + 3 ) ;
F_6 ( 0x00 , V_12 [ V_30 ] ) ;
F_6 ( 0x00 , V_12 [ V_30 ] + 1 ) ;
F_6 ( 0x00 , V_12 [ V_30 ] + 2 ) ;
F_6 ( 0x80 , V_12 [ V_30 ] + 7 ) ;
F_6 ( 0x00 , V_12 [ V_30 ] + 4 ) ;
F_6 ( 0x00 , V_12 [ V_30 ] + 5 ) ;
F_6 ( 0x00 , V_12 [ V_30 ] + 6 ) ;
return 0 ;
}
