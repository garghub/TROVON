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
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
unsigned long V_9 ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_8 [ V_6 ] |= V_7 ;
V_5 -> V_11 [ V_6 ] &= ~ V_7 ;
F_6 ( V_5 -> V_11 [ V_6 ] , V_5 -> V_12 + V_6 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_13 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
unsigned long V_9 ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_8 [ V_6 ] &= ~ V_7 ;
if ( V_13 )
V_5 -> V_11 [ V_6 ] |= V_7 ;
else
V_5 -> V_11 [ V_6 ] &= ~ V_7 ;
F_6 ( V_5 -> V_11 [ V_6 ] , V_5 -> V_12 + V_6 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
unsigned long V_9 ;
unsigned V_14 ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
if ( ! ( V_5 -> V_8 [ V_6 ] & V_7 ) ) {
F_7 ( & V_5 -> V_10 , V_9 ) ;
return - V_15 ;
}
V_14 = F_10 ( V_5 -> V_12 + V_6 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
return ! ! ( V_14 & V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 , int V_13 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
unsigned long V_9 ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
if ( V_5 -> V_8 [ V_6 ] & V_7 ) {
F_7 ( & V_5 -> V_10 , V_9 ) ;
return;
}
if ( V_13 )
V_5 -> V_11 [ V_6 ] |= V_7 ;
else
V_5 -> V_11 [ V_6 ] &= ~ V_7 ;
F_6 ( V_5 -> V_11 [ V_6 ] , V_5 -> V_12 + V_6 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned long * V_7 , unsigned long * V_16 )
{
struct V_4 * const V_5 = F_2 ( V_2 ) ;
unsigned int V_17 ;
const unsigned int V_18 = 8 ;
unsigned int V_6 ;
unsigned int V_19 ;
unsigned int V_20 ;
unsigned long V_9 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_21 ; V_17 += V_18 ) {
if ( ! V_7 [ F_13 ( V_17 ) ] ) {
V_17 = ( F_13 ( V_17 ) + 1 ) * V_22 - V_18 ;
continue;
}
V_6 = V_17 / V_18 ;
V_19 = V_7 [ F_13 ( V_17 ) ] & ~ V_5 -> V_8 [ V_6 ] ;
V_20 = V_19 & V_16 [ F_13 ( V_17 ) ] ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_11 [ V_6 ] &= ~ V_19 ;
V_5 -> V_11 [ V_6 ] |= V_20 ;
F_6 ( V_5 -> V_11 [ V_6 ] , V_5 -> V_12 + V_6 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
V_7 [ F_13 ( V_17 ) ] >>= V_18 ;
V_16 [ F_13 ( V_17 ) ] >>= V_18 ;
}
}
static void F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_16 ( V_24 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
unsigned long V_9 ;
unsigned V_14 ;
if ( V_6 > 2 )
return;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_14 = V_5 -> V_25 >> ( 8 * V_6 ) ;
F_6 ( 0x80 , V_5 -> V_12 + 7 ) ;
F_6 ( V_14 & ~ V_7 , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( V_14 | V_7 , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_16 ( V_24 ) ;
const unsigned long V_7 = F_3 ( V_3 ) ;
const unsigned V_6 = V_3 / 8 ;
unsigned long V_9 ;
if ( V_6 > 2 )
return;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_25 &= ~ V_7 ;
F_6 ( 0x80 , V_5 -> V_12 + 7 ) ;
F_6 ( V_5 -> V_25 >> ( 8 * V_6 ) , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
}
static void F_18 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_16 ( V_24 ) ;
const unsigned long V_7 = F_3 ( V_3 ) ;
const unsigned V_6 = V_3 / 8 ;
unsigned long V_9 ;
if ( V_6 > 2 )
return;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_25 |= V_7 ;
F_6 ( 0x80 , V_5 -> V_12 + 7 ) ;
F_6 ( V_5 -> V_25 >> ( 8 * V_6 ) , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
}
static int F_19 ( struct V_23 * V_24 , unsigned V_26 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_16 ( V_24 ) ;
const unsigned long V_7 = F_3 ( V_3 ) ;
const unsigned V_6 = V_3 / 8 ;
unsigned long V_9 ;
if ( V_6 > 2 )
return - V_15 ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
switch ( V_26 ) {
case V_27 :
break;
case V_28 :
V_5 -> V_29 |= V_7 ;
break;
case V_30 :
V_5 -> V_29 &= ~ V_7 ;
break;
default:
F_7 ( & V_5 -> V_10 , V_9 ) ;
return - V_15 ;
}
F_6 ( 0x40 , V_5 -> V_12 + 7 ) ;
F_6 ( V_5 -> V_29 >> ( 8 * V_6 ) , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
return 0 ;
}
static T_1 F_20 ( int V_31 , void * V_32 )
{
struct V_4 * const V_5 = V_32 ;
struct V_1 * const V_2 = & V_5 -> V_2 ;
unsigned long V_33 ;
unsigned long V_6 ;
unsigned long V_34 ;
unsigned long V_35 ;
V_33 = F_10 ( V_5 -> V_12 + 6 ) & 0x7 ;
if ( ! V_33 )
return V_36 ;
do {
F_21 (port, &int_pending, 3 ) {
V_34 = F_10 ( V_5 -> V_12 + 8 + V_6 ) ;
F_21 (gpio, &int_id, 8 )
F_22 ( F_23 (
V_2 -> V_37 , V_35 + 8 * V_6 ) ) ;
}
V_33 = F_10 ( V_5 -> V_12 + 6 ) & 0x7 ;
} while ( V_33 );
return V_38 ;
}
static int F_24 ( struct V_39 * V_40 , unsigned int V_41 )
{
struct V_4 * V_5 ;
const char * const V_42 = F_25 ( V_40 ) ;
int V_43 ;
V_5 = F_26 ( V_40 , sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
return - V_45 ;
if ( ! F_27 ( V_40 , V_12 [ V_41 ] , V_46 , V_42 ) ) {
F_28 ( V_40 , L_1 ,
V_12 [ V_41 ] , V_12 [ V_41 ] + V_46 ) ;
return - V_47 ;
}
V_5 -> V_2 . V_48 = V_42 ;
V_5 -> V_2 . V_49 = V_40 ;
V_5 -> V_2 . V_50 = V_51 ;
V_5 -> V_2 . V_12 = - 1 ;
V_5 -> V_2 . V_21 = V_52 ;
V_5 -> V_2 . V_53 = V_54 ;
V_5 -> V_2 . V_55 = F_1 ;
V_5 -> V_2 . V_56 = F_4 ;
V_5 -> V_2 . V_57 = F_8 ;
V_5 -> V_2 . V_58 = F_9 ;
V_5 -> V_2 . V_59 = F_11 ;
V_5 -> V_2 . V_60 = F_12 ;
V_5 -> V_12 = V_12 [ V_41 ] ;
F_29 ( & V_5 -> V_10 ) ;
V_43 = F_30 ( V_40 , & V_5 -> V_2 , V_5 ) ;
if ( V_43 ) {
F_28 ( V_40 , L_2 , V_43 ) ;
return V_43 ;
}
F_6 ( 0x80 , V_12 [ V_41 ] + 7 ) ;
F_6 ( 0 , V_12 [ V_41 ] + 8 ) ;
F_6 ( 0 , V_12 [ V_41 ] + 9 ) ;
F_6 ( 0 , V_12 [ V_41 ] + 10 ) ;
F_6 ( 0xC0 , V_12 [ V_41 ] + 7 ) ;
V_43 = F_31 ( & V_5 -> V_2 , & V_61 , 0 ,
V_62 , V_27 ) ;
if ( V_43 ) {
F_28 ( V_40 , L_3 , V_43 ) ;
return V_43 ;
}
V_43 = F_32 ( V_40 , V_31 [ V_41 ] , F_20 , V_63 ,
V_42 , V_5 ) ;
if ( V_43 ) {
F_28 ( V_40 , L_4 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
