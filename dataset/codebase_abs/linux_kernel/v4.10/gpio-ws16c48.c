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
static void F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_13 ( V_17 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_14 ( V_17 ) ;
const unsigned V_6 = V_3 / 8 ;
const unsigned V_7 = F_3 ( V_3 % 8 ) ;
unsigned long V_9 ;
unsigned V_14 ;
if ( V_6 > 2 )
return;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_14 = V_5 -> V_18 >> ( 8 * V_6 ) ;
F_6 ( 0x80 , V_5 -> V_12 + 7 ) ;
F_6 ( V_14 & ~ V_7 , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( V_14 | V_7 , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
}
static void F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_13 ( V_17 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_14 ( V_17 ) ;
const unsigned long V_7 = F_3 ( V_3 ) ;
const unsigned V_6 = V_3 / 8 ;
unsigned long V_9 ;
if ( V_6 > 2 )
return;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_18 &= ~ V_7 ;
F_6 ( 0x80 , V_5 -> V_12 + 7 ) ;
F_6 ( V_5 -> V_18 >> ( 8 * V_6 ) , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_13 ( V_17 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_14 ( V_17 ) ;
const unsigned long V_7 = F_3 ( V_3 ) ;
const unsigned V_6 = V_3 / 8 ;
unsigned long V_9 ;
if ( V_6 > 2 )
return;
F_5 ( & V_5 -> V_10 , V_9 ) ;
V_5 -> V_18 |= V_7 ;
F_6 ( 0x80 , V_5 -> V_12 + 7 ) ;
F_6 ( V_5 -> V_18 >> ( 8 * V_6 ) , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
}
static int F_17 ( struct V_16 * V_17 , unsigned V_19 )
{
struct V_1 * V_2 = F_13 ( V_17 ) ;
struct V_4 * const V_5 = F_2 ( V_2 ) ;
const unsigned long V_3 = F_14 ( V_17 ) ;
const unsigned long V_7 = F_3 ( V_3 ) ;
const unsigned V_6 = V_3 / 8 ;
unsigned long V_9 ;
if ( V_6 > 2 )
return - V_15 ;
F_5 ( & V_5 -> V_10 , V_9 ) ;
switch ( V_19 ) {
case V_20 :
break;
case V_21 :
V_5 -> V_22 |= V_7 ;
break;
case V_23 :
V_5 -> V_22 &= ~ V_7 ;
break;
default:
F_7 ( & V_5 -> V_10 , V_9 ) ;
return - V_15 ;
}
F_6 ( 0x40 , V_5 -> V_12 + 7 ) ;
F_6 ( V_5 -> V_22 >> ( 8 * V_6 ) , V_5 -> V_12 + 8 + V_6 ) ;
F_6 ( 0xC0 , V_5 -> V_12 + 7 ) ;
F_7 ( & V_5 -> V_10 , V_9 ) ;
return 0 ;
}
static T_1 F_18 ( int V_24 , void * V_25 )
{
struct V_4 * const V_5 = V_25 ;
struct V_1 * const V_2 = & V_5 -> V_2 ;
unsigned long V_26 ;
unsigned long V_6 ;
unsigned long V_27 ;
unsigned long V_28 ;
V_26 = F_10 ( V_5 -> V_12 + 6 ) & 0x7 ;
if ( ! V_26 )
return V_29 ;
do {
F_19 (port, &int_pending, 3 ) {
V_27 = F_10 ( V_5 -> V_12 + 8 + V_6 ) ;
F_19 (gpio, &int_id, 8 )
F_20 ( F_21 (
V_2 -> V_30 , V_28 + 8 * V_6 ) ) ;
}
V_26 = F_10 ( V_5 -> V_12 + 6 ) & 0x7 ;
} while ( V_26 );
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
if ( ! F_25 ( V_33 , V_12 [ V_34 ] , V_39 , V_35 ) ) {
F_26 ( V_33 , L_1 ,
V_12 [ V_34 ] , V_12 [ V_34 ] + V_39 ) ;
return - V_40 ;
}
V_5 -> V_2 . V_41 = V_35 ;
V_5 -> V_2 . V_42 = V_33 ;
V_5 -> V_2 . V_43 = V_44 ;
V_5 -> V_2 . V_12 = - 1 ;
V_5 -> V_2 . V_45 = 48 ;
V_5 -> V_2 . V_46 = F_1 ;
V_5 -> V_2 . V_47 = F_4 ;
V_5 -> V_2 . V_48 = F_8 ;
V_5 -> V_2 . V_49 = F_9 ;
V_5 -> V_2 . V_50 = F_11 ;
V_5 -> V_12 = V_12 [ V_34 ] ;
V_5 -> V_24 = V_24 [ V_34 ] ;
F_27 ( & V_5 -> V_10 ) ;
F_28 ( V_33 , V_5 ) ;
V_36 = F_29 ( & V_5 -> V_2 , V_5 ) ;
if ( V_36 ) {
F_26 ( V_33 , L_2 , V_36 ) ;
return V_36 ;
}
F_6 ( 0x80 , V_12 [ V_34 ] + 7 ) ;
F_6 ( 0 , V_12 [ V_34 ] + 8 ) ;
F_6 ( 0 , V_12 [ V_34 ] + 9 ) ;
F_6 ( 0 , V_12 [ V_34 ] + 10 ) ;
F_6 ( 0xC0 , V_12 [ V_34 ] + 7 ) ;
V_36 = F_30 ( & V_5 -> V_2 , & V_51 , 0 ,
V_52 , V_20 ) ;
if ( V_36 ) {
F_26 ( V_33 , L_3 , V_36 ) ;
goto V_53;
}
V_36 = F_31 ( V_24 [ V_34 ] , F_18 , V_54 , V_35 ,
V_5 ) ;
if ( V_36 ) {
F_26 ( V_33 , L_4 , V_36 ) ;
goto V_53;
}
return 0 ;
V_53:
F_32 ( & V_5 -> V_2 ) ;
return V_36 ;
}
static int F_33 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_4 * const V_5 = F_34 ( V_33 ) ;
F_35 ( V_5 -> V_24 , V_5 ) ;
F_32 ( & V_5 -> V_2 ) ;
return 0 ;
}
