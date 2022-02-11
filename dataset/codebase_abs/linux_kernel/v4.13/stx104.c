static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
unsigned int V_10 ;
int V_11 ;
int V_12 ;
switch ( V_7 ) {
case V_13 :
V_10 = F_3 ( V_9 -> V_14 + 11 ) ;
V_12 = V_10 & 0x3 ;
* V_5 = 1 << V_12 ;
return V_15 ;
case V_16 :
if ( V_4 -> V_17 ) {
* V_5 = V_9 -> V_18 [ V_4 -> V_19 ] ;
return V_15 ;
}
F_4 ( V_4 -> V_19 | ( V_4 -> V_19 << 4 ) , V_9 -> V_14 + 2 ) ;
F_4 ( 0 , V_9 -> V_14 ) ;
while ( F_3 ( V_9 -> V_14 + 8 ) & F_5 ( 7 ) ) ;
* V_5 = F_6 ( V_9 -> V_14 ) ;
return V_15 ;
case V_20 :
V_10 = F_3 ( V_9 -> V_14 + 11 ) ;
V_11 = ! ( V_10 & F_5 ( 2 ) ) ;
* V_5 = - 32768 * V_11 ;
return V_15 ;
case V_21 :
V_10 = F_3 ( V_9 -> V_14 + 11 ) ;
V_11 = ! ( V_10 & F_5 ( 2 ) ) ;
V_12 = V_10 & 0x3 ;
* V_5 = 5 ;
* V_6 = 15 - V_11 + V_12 ;
return V_22 ;
}
return - V_23 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int V_5 , int V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
switch ( V_7 ) {
case V_13 :
switch ( V_5 ) {
case 1 :
F_4 ( 0 , V_9 -> V_14 + 11 ) ;
break;
case 2 :
F_4 ( 1 , V_9 -> V_14 + 11 ) ;
break;
case 4 :
F_4 ( 2 , V_9 -> V_14 + 11 ) ;
break;
case 8 :
F_4 ( 3 , V_9 -> V_14 + 11 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
case V_16 :
if ( V_4 -> V_17 ) {
if ( ( unsigned int ) V_5 > 65535 )
return - V_23 ;
V_9 -> V_18 [ V_4 -> V_19 ] = V_5 ;
F_8 ( V_5 , V_9 -> V_14 + 4 + 2 * V_4 -> V_19 ) ;
return 0 ;
}
return - V_23 ;
}
return - V_23 ;
}
static int F_9 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
if ( V_26 < 4 )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_24 * V_25 ,
unsigned int V_26 )
{
if ( V_26 >= 4 )
return - V_23 ;
return 0 ;
}
static int F_11 ( struct V_24 * V_25 ,
unsigned int V_26 , int V_27 )
{
if ( V_26 < 4 )
return - V_23 ;
V_25 -> V_28 ( V_25 , V_26 , V_27 ) ;
return 0 ;
}
static int F_12 ( struct V_24 * V_25 , unsigned int V_26 )
{
struct V_29 * const V_30 = F_13 ( V_25 ) ;
if ( V_26 >= 4 )
return - V_23 ;
return ! ! ( F_3 ( V_30 -> V_14 ) & F_5 ( V_26 ) ) ;
}
static void F_14 ( struct V_24 * V_25 , unsigned int V_26 ,
int V_27 )
{
struct V_29 * const V_30 = F_13 ( V_25 ) ;
const unsigned int V_7 = F_5 ( V_26 ) >> 4 ;
unsigned long V_31 ;
if ( V_26 < 4 )
return;
F_15 ( & V_30 -> V_32 , V_31 ) ;
if ( V_27 )
V_30 -> V_33 |= V_7 ;
else
V_30 -> V_33 &= ~ V_7 ;
F_4 ( V_30 -> V_33 , V_30 -> V_14 ) ;
F_16 ( & V_30 -> V_32 , V_31 ) ;
}
static void F_17 ( struct V_24 * V_25 ,
unsigned long * V_7 , unsigned long * V_34 )
{
struct V_29 * const V_30 = F_13 ( V_25 ) ;
unsigned long V_31 ;
if ( ! ( * V_7 & 0xF0 ) )
return;
* V_7 >>= 4 ;
* V_34 >>= 4 ;
F_15 ( & V_30 -> V_32 , V_31 ) ;
V_30 -> V_33 &= ~ * V_7 ;
V_30 -> V_33 |= * V_7 & * V_34 ;
F_4 ( V_30 -> V_33 , V_30 -> V_14 ) ;
F_16 ( & V_30 -> V_32 , V_31 ) ;
}
static int F_18 ( struct V_35 * V_36 , unsigned int V_37 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_29 * V_30 ;
int V_38 ;
V_2 = F_19 ( V_36 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_39 ;
V_30 = F_20 ( V_36 , sizeof( * V_30 ) , V_40 ) ;
if ( ! V_30 )
return - V_39 ;
if ( ! F_21 ( V_36 , V_14 [ V_37 ] , V_41 ,
F_22 ( V_36 ) ) ) {
F_23 ( V_36 , L_1 ,
V_14 [ V_37 ] , V_14 [ V_37 ] + V_41 ) ;
return - V_42 ;
}
V_2 -> V_43 = & V_44 ;
V_2 -> V_45 = V_46 ;
if ( F_3 ( V_14 [ V_37 ] + 8 ) & F_5 ( 5 ) ) {
V_2 -> V_47 = F_24 ( V_48 ) ;
V_2 -> V_49 = V_48 ;
} else {
V_2 -> V_47 = F_24 ( V_50 ) ;
V_2 -> V_49 = V_50 ;
}
V_2 -> V_51 = F_22 ( V_36 ) ;
V_2 -> V_36 . V_52 = V_36 ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_14 = V_14 [ V_37 ] ;
F_4 ( 0 , V_14 [ V_37 ] + 9 ) ;
F_4 ( 0 , V_14 [ V_37 ] + 11 ) ;
F_8 ( 0 , V_14 [ V_37 ] + 4 ) ;
F_8 ( 0 , V_14 [ V_37 ] + 6 ) ;
V_30 -> V_25 . V_53 = F_22 ( V_36 ) ;
V_30 -> V_25 . V_52 = V_36 ;
V_30 -> V_25 . V_54 = V_55 ;
V_30 -> V_25 . V_14 = - 1 ;
V_30 -> V_25 . V_56 = V_57 ;
V_30 -> V_25 . V_58 = V_59 ;
V_30 -> V_25 . V_60 = F_9 ;
V_30 -> V_25 . V_61 = F_10 ;
V_30 -> V_25 . V_62 = F_11 ;
V_30 -> V_25 . V_63 = F_12 ;
V_30 -> V_25 . V_28 = F_14 ;
V_30 -> V_25 . V_64 = F_17 ;
V_30 -> V_14 = V_14 [ V_37 ] + 3 ;
V_30 -> V_33 = 0x0 ;
F_25 ( & V_30 -> V_32 ) ;
V_38 = F_26 ( V_36 , & V_30 -> V_25 , V_30 ) ;
if ( V_38 ) {
F_23 ( V_36 , L_2 , V_38 ) ;
return V_38 ;
}
return F_27 ( V_36 , V_2 ) ;
}
