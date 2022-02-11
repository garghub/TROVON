static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 V_5 ;
F_2 ( & V_5 , V_6 ) ;
if ( V_3 )
V_5 . V_7 [ 0 ] |= V_8 ;
return F_3 ( V_2 , & V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
F_2 ( & V_5 , V_9 ) ;
V_5 . V_7 [ 0 ] |= 1 << 0 ;
return F_3 ( V_2 , & V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_10 )
{
int V_11 ;
F_6 ( & V_2 -> V_12 ) ;
if ( V_2 -> type >= V_13 ) {
F_7 ( V_2 , V_14 , 1 ) ;
F_7 ( V_2 , V_15 , V_10 & V_16 ) ;
V_11 = ( F_8 ( V_2 , V_15 ) >> 7 ) & 0x01 ;
} else {
F_9 ( V_2 , V_14 , 1 ) ;
F_9 ( V_2 , V_15 , V_10 & V_16 ) ;
V_11 = ( F_10 ( V_2 , V_15 ) >> 7 ) & 0x01 ;
}
F_11 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static void F_12 ( struct V_1 * V_2 , int V_10 , int V_11 )
{
V_11 = ! ! V_11 ;
F_6 ( & V_2 -> V_12 ) ;
if ( F_13 ( V_2 ) ) {
F_7 ( V_2 , V_14 , 0 ) ;
F_7 ( V_2 , V_15 , ( V_11 << 7 ) | ( V_10 & V_16 ) ) ;
} else {
F_9 ( V_2 , V_14 , 0 ) ;
F_9 ( V_2 , V_15 , ( V_11 << 7 ) | ( V_10 & V_16 ) ) ;
}
F_11 ( & V_2 -> V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int * V_17 )
{
int V_11 , V_18 ;
V_18 = 0 ;
if ( F_13 ( V_2 ) )
V_11 = F_8 ( V_2 , V_14 ) ;
else
V_11 = F_10 ( V_2 , V_14 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 & V_19 ) {
switch ( V_11 & V_20 ) {
case V_21 :
V_18 = 32000 ;
break;
case V_22 :
V_18 = 44100 ;
break;
case V_23 :
V_18 = 48000 ;
break;
}
}
if ( V_11 & V_24 )
* V_17 = F_5 ( V_2 , 0 ) ?
V_25 : V_26 ;
else
* V_17 = V_27 ;
return V_18 ;
}
static int F_15 ( struct V_1 * V_2 , int V_18 )
{
int V_28 ;
if ( F_16 ( V_18 <= 0 ) )
return 0 ;
V_28 = ( 28224000 * 10 ) / V_18 ;
V_28 = ( V_28 + 5 ) / 10 ;
if ( F_16 ( V_28 <= 0x00000200 ) )
return 0 ;
if ( V_28 <= 0x03ff )
return V_28 - 0x00000201 ;
if ( V_28 <= 0x07ff )
return ( V_28 / 2 ) - 1 ;
if ( V_28 <= 0x0fff )
return ( V_28 / 4 ) + 0x000001ff ;
return 0x5fe ;
}
static void F_17 ( struct V_1 * V_2 , int V_29 )
{
F_18 ( V_2 , 1 ) ;
F_6 ( & V_2 -> V_12 ) ;
V_2 -> V_30 -> V_31 ( V_2 , V_29 ) ;
V_2 -> V_32 = V_29 ;
F_11 ( & V_2 -> V_12 ) ;
F_18 ( V_2 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_18 )
{
int clock ;
clock = F_15 ( V_2 , V_18 ) ;
F_20 ( V_33 L_1 , clock , V_18 ) ;
F_6 ( & V_2 -> V_12 ) ;
if ( F_13 ( V_2 ) ) {
F_7 ( V_2 , V_34 , ( clock >> 8 ) & 0x0f ) ;
F_7 ( V_2 , V_35 , clock & 0xff ) ;
} else {
F_9 ( V_2 , V_34 , ( clock >> 8 ) & 0x0f ) ;
F_9 ( V_2 , V_35 , clock & 0xff ) ;
}
F_11 ( & V_2 -> V_12 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned int V_36 )
{
int V_37 ;
if ( V_2 -> V_38 & V_39 )
return;
for ( V_37 = 0 ; V_37 < 32 ; V_37 ++ )
F_12 ( V_2 , V_37 , V_36 & ( 1 << V_37 ) ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_18 )
{
int V_40 = 0 ;
if ( V_2 -> V_38 & V_39 )
return 0 ;
F_23 ( V_2 ) ;
if ( V_2 -> V_41 == V_42 ||
( V_2 -> V_41 == V_43 &&
V_2 -> V_44 == V_45 ) ) {
if ( V_2 -> V_32 != V_46 ) {
F_17 ( V_2 , V_46 ) ;
F_24 ( 6 ) ;
V_40 = 1 ;
}
} else if ( V_2 -> V_41 == V_47 ||
( V_2 -> V_41 == V_43 &&
V_2 -> V_44 != V_45 ) ) {
if ( V_2 -> V_32 != V_48 ) {
F_17 ( V_2 , V_48 ) ;
V_40 = 1 ;
}
if ( V_2 -> V_18 == V_18 )
return 0 ;
F_19 ( V_2 , V_18 ) ;
if ( V_40 )
F_4 ( V_2 ) ;
}
if ( V_2 -> V_18 == V_18 )
return 0 ;
V_2 -> V_18 = V_18 ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_38 & V_39 )
return 0 ;
if ( V_2 -> V_32 == V_48 )
return 0 ;
V_18 = F_14 ( V_2 , & V_2 -> V_49 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 == 48000 || V_18 == 44100 || V_18 == 32000 )
V_2 -> V_50 = V_18 ;
return 0 ;
}
