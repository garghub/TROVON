static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 * V_6 ;
T_1 V_7 , V_8 ;
int V_9 ;
V_3 += 4 ;
V_7 = ( V_3 & 3 ) << 1 ;
V_6 = & V_5 -> V_10 [ V_3 >> 2 ] ;
if ( V_5 -> V_11 & F_3 ( V_3 ) )
V_8 = V_12 ;
else
V_8 = V_13 ;
F_4 ( & V_5 -> V_14 ) ;
* V_6 = ( * V_6 & ~ ( V_15 << V_7 ) )
| ( V_8 << V_7 ) ;
V_9 = V_5 -> V_16 ( V_5 -> V_17 , 0x08 + ( V_3 >> 2 ) , * V_6 ) ;
F_5 ( & V_5 -> V_14 ) ;
return V_9 ;
}
static int F_6 ( struct V_4 * V_5 , unsigned V_3 , int V_18 )
{
if ( V_18 ) {
V_5 -> V_19 |= 1 << V_3 ;
return V_5 -> V_16 ( V_5 -> V_17 , 0x20 + V_3 , 0x01 ) ;
} else {
V_5 -> V_19 &= ~ ( 1 << V_3 ) ;
return V_5 -> V_16 ( V_5 -> V_17 , 0x20 + V_3 , 0x00 ) ;
}
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 * V_6 ;
T_1 V_7 ;
int V_9 ;
V_3 += 4 ;
V_7 = ( V_3 & 3 ) << 1 ;
V_6 = & V_5 -> V_10 [ V_3 >> 2 ] ;
F_4 ( & V_5 -> V_14 ) ;
* V_6 = ( * V_6 & ~ ( V_15 << V_7 ) )
| ( V_20 << V_7 ) ;
V_9 = F_6 ( V_5 , V_3 , V_18 ) ;
if ( ! V_9 )
V_9 = V_5 -> V_16 ( V_5 -> V_17 , 0x08 + ( V_3 >> 2 ) , * V_6 ) ;
F_5 ( & V_5 -> V_14 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_6 , V_21 = - V_22 ;
V_3 += 4 ;
F_4 ( & V_5 -> V_14 ) ;
V_6 = ( V_5 -> V_10 [ V_3 >> 2 ] >> ( ( V_3 & 3 ) << 1 ) )
& V_15 ;
switch ( V_6 ) {
case V_20 :
V_21 = ! ! ( V_5 -> V_19 & ( 1 << V_3 ) ) ;
break;
case V_13 :
case V_12 :
V_21 = V_5 -> V_23 ( V_5 -> V_17 , 0x20 + V_3 ) & 0x01 ;
}
F_5 ( & V_5 -> V_14 ) ;
return V_21 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 , int V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
V_3 += 4 ;
F_4 ( & V_5 -> V_14 ) ;
F_6 ( V_5 , V_3 , V_18 ) ;
F_5 ( & V_5 -> V_14 ) ;
}
int F_10 ( struct V_4 * V_5 )
{
struct V_24 * V_17 = V_5 -> V_17 ;
struct V_25 * V_26 ;
int V_27 , V_9 ;
V_26 = F_11 ( V_17 ) ;
F_12 ( & V_5 -> V_14 ) ;
F_13 ( V_17 , V_5 ) ;
V_5 -> V_16 ( V_17 , 0x04 , 0x01 ) ;
if ( V_26 ) {
V_5 -> V_11 = V_26 -> V_11 ;
V_5 -> V_2 . V_28 = V_26 -> V_28 ;
} else {
V_5 -> V_2 . V_28 = - 1 ;
}
V_5 -> V_2 . V_29 = V_17 -> V_30 -> V_31 ;
V_5 -> V_2 . V_32 = F_1 ;
V_5 -> V_2 . V_33 = F_8 ;
V_5 -> V_2 . V_34 = F_7 ;
V_5 -> V_2 . V_35 = F_9 ;
V_5 -> V_2 . V_36 = V_37 ;
V_5 -> V_2 . V_38 = true ;
V_5 -> V_2 . V_17 = V_17 ;
V_5 -> V_2 . V_39 = V_40 ;
for ( V_27 = 1 ; V_27 < 8 ; V_27 ++ ) {
int V_41 ;
V_5 -> V_10 [ V_27 ] = 0xAA ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
int V_3 = ( V_27 - 1 ) * 4 + V_41 ;
V_9 = F_1 ( & V_5 -> V_2 , V_3 ) ;
if ( V_9 )
goto V_42;
}
}
V_9 = F_14 ( & V_5 -> V_2 ) ;
if ( V_9 )
goto V_42;
return V_9 ;
V_42:
F_15 ( & V_5 -> V_14 ) ;
return V_9 ;
}
int F_16 ( struct V_24 * V_17 )
{
struct V_4 * V_5 = F_17 ( V_17 ) ;
if ( V_5 == NULL )
return - V_43 ;
V_5 -> V_16 ( V_17 , 0x04 , 0x00 ) ;
F_18 ( & V_5 -> V_2 ) ;
F_15 ( & V_5 -> V_14 ) ;
return 0 ;
}
