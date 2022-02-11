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
static int F_17 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_29 * V_30 ;
struct V_37 * V_38 ;
int V_39 ;
V_2 = F_18 ( V_35 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_40 ;
V_30 = F_19 ( V_35 , sizeof( * V_30 ) , V_41 ) ;
if ( ! V_30 )
return - V_40 ;
V_38 = F_19 ( V_35 , sizeof( * V_38 ) , V_41 ) ;
if ( ! V_38 )
return - V_40 ;
if ( ! F_20 ( V_35 , V_14 [ V_36 ] , V_42 ,
F_21 ( V_35 ) ) ) {
F_22 ( V_35 , L_1 ,
V_14 [ V_36 ] , V_14 [ V_36 ] + V_42 ) ;
return - V_43 ;
}
V_2 -> V_44 = & V_45 ;
V_2 -> V_46 = V_47 ;
if ( F_3 ( V_14 [ V_36 ] + 8 ) & F_5 ( 5 ) ) {
V_2 -> V_48 = F_23 ( V_49 ) ;
V_2 -> V_50 = V_49 ;
} else {
V_2 -> V_48 = F_23 ( V_51 ) ;
V_2 -> V_50 = V_51 ;
}
V_2 -> V_52 = F_21 ( V_35 ) ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_14 = V_14 [ V_36 ] ;
F_4 ( 0 , V_14 [ V_36 ] + 9 ) ;
F_4 ( 0 , V_14 [ V_36 ] + 11 ) ;
F_8 ( 0 , V_14 [ V_36 ] + 4 ) ;
F_8 ( 0 , V_14 [ V_36 ] + 6 ) ;
V_30 -> V_25 . V_53 = F_21 ( V_35 ) ;
V_30 -> V_25 . V_54 = V_35 ;
V_30 -> V_25 . V_55 = V_56 ;
V_30 -> V_25 . V_14 = - 1 ;
V_30 -> V_25 . V_57 = 8 ;
V_30 -> V_25 . V_58 = F_9 ;
V_30 -> V_25 . V_59 = F_10 ;
V_30 -> V_25 . V_60 = F_11 ;
V_30 -> V_25 . V_61 = F_12 ;
V_30 -> V_25 . V_28 = F_14 ;
V_30 -> V_14 = V_14 [ V_36 ] + 3 ;
V_30 -> V_33 = 0x0 ;
F_24 ( & V_30 -> V_32 ) ;
V_38 -> V_2 = V_2 ;
V_38 -> V_25 = & V_30 -> V_25 ;
F_25 ( V_35 , V_38 ) ;
V_39 = F_26 ( & V_30 -> V_25 , V_30 ) ;
if ( V_39 ) {
F_22 ( V_35 , L_2 , V_39 ) ;
return V_39 ;
}
V_39 = F_27 ( V_2 ) ;
if ( V_39 ) {
F_22 ( V_35 , L_3 , V_39 ) ;
F_28 ( & V_30 -> V_25 ) ;
return V_39 ;
}
return 0 ;
}
static int F_29 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_37 * const V_38 = F_30 ( V_35 ) ;
F_31 ( V_38 -> V_2 ) ;
F_28 ( V_38 -> V_25 ) ;
return 0 ;
}
