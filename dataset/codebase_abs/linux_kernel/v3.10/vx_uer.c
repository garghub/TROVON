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
unsigned long V_11 ;
int V_12 ;
F_6 ( & V_2 -> V_13 , V_11 ) ;
if ( V_2 -> type >= V_14 ) {
F_7 ( V_2 , V_15 , 1 ) ;
F_7 ( V_2 , V_16 , V_10 & V_17 ) ;
V_12 = ( F_8 ( V_2 , V_16 ) >> 7 ) & 0x01 ;
} else {
F_9 ( V_2 , V_15 , 1 ) ;
F_9 ( V_2 , V_16 , V_10 & V_17 ) ;
V_12 = ( F_10 ( V_2 , V_16 ) >> 7 ) & 0x01 ;
}
F_11 ( & V_2 -> V_13 , V_11 ) ;
return V_12 ;
}
static void F_12 ( struct V_1 * V_2 , int V_10 , int V_12 )
{
unsigned long V_11 ;
V_12 = ! ! V_12 ;
F_6 ( & V_2 -> V_13 , V_11 ) ;
if ( F_13 ( V_2 ) ) {
F_7 ( V_2 , V_15 , 0 ) ;
F_7 ( V_2 , V_16 , ( V_12 << 7 ) | ( V_10 & V_17 ) ) ;
} else {
F_9 ( V_2 , V_15 , 0 ) ;
F_9 ( V_2 , V_16 , ( V_12 << 7 ) | ( V_10 & V_17 ) ) ;
}
F_11 ( & V_2 -> V_13 , V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int * V_18 )
{
int V_12 , V_19 ;
V_19 = 0 ;
if ( F_13 ( V_2 ) )
V_12 = F_8 ( V_2 , V_15 ) ;
else
V_12 = F_10 ( V_2 , V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & V_20 ) {
switch ( V_12 & V_21 ) {
case V_22 :
V_19 = 32000 ;
break;
case V_23 :
V_19 = 44100 ;
break;
case V_24 :
V_19 = 48000 ;
break;
}
}
if ( V_12 & V_25 )
* V_18 = F_5 ( V_2 , 0 ) ?
V_26 : V_27 ;
else
* V_18 = V_28 ;
return V_19 ;
}
static int F_15 ( struct V_1 * V_2 , int V_19 )
{
int V_29 ;
if ( F_16 ( V_19 <= 0 ) )
return 0 ;
V_29 = ( 28224000 * 10 ) / V_19 ;
V_29 = ( V_29 + 5 ) / 10 ;
if ( F_16 ( V_29 <= 0x00000200 ) )
return 0 ;
if ( V_29 <= 0x03ff )
return V_29 - 0x00000201 ;
if ( V_29 <= 0x07ff )
return ( V_29 / 2 ) - 1 ;
if ( V_29 <= 0x0fff )
return ( V_29 / 4 ) + 0x000001ff ;
return 0x5fe ;
}
static void F_17 ( struct V_1 * V_2 , int V_30 )
{
unsigned long V_11 ;
F_18 ( V_2 , 1 ) ;
F_6 ( & V_2 -> V_13 , V_11 ) ;
V_2 -> V_31 -> V_32 ( V_2 , V_30 ) ;
V_2 -> V_33 = V_30 ;
F_11 ( & V_2 -> V_13 , V_11 ) ;
F_18 ( V_2 , 0 ) ;
}
void F_19 ( struct V_1 * V_2 , unsigned int V_19 )
{
int clock ;
unsigned long V_11 ;
clock = F_15 ( V_2 , V_19 ) ;
F_20 ( V_34 L_1 , clock , V_19 ) ;
F_6 ( & V_2 -> V_13 , V_11 ) ;
if ( F_13 ( V_2 ) ) {
F_7 ( V_2 , V_35 , ( clock >> 8 ) & 0x0f ) ;
F_7 ( V_2 , V_36 , clock & 0xff ) ;
} else {
F_9 ( V_2 , V_35 , ( clock >> 8 ) & 0x0f ) ;
F_9 ( V_2 , V_36 , clock & 0xff ) ;
}
F_11 ( & V_2 -> V_13 , V_11 ) ;
}
void F_21 ( struct V_1 * V_2 , unsigned int V_37 )
{
int V_38 ;
if ( V_2 -> V_39 & V_40 )
return;
for ( V_38 = 0 ; V_38 < 32 ; V_38 ++ )
F_12 ( V_2 , V_38 , V_37 & ( 1 << V_38 ) ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_19 )
{
int V_41 = 0 ;
if ( V_2 -> V_39 & V_40 )
return 0 ;
F_23 ( V_2 ) ;
if ( V_2 -> V_42 == V_43 ||
( V_2 -> V_42 == V_44 &&
V_2 -> V_45 == V_46 ) ) {
if ( V_2 -> V_33 != V_47 ) {
F_17 ( V_2 , V_47 ) ;
F_24 ( 6 ) ;
V_41 = 1 ;
}
} else if ( V_2 -> V_42 == V_48 ||
( V_2 -> V_42 == V_44 &&
V_2 -> V_45 != V_46 ) ) {
if ( V_2 -> V_33 != V_49 ) {
F_17 ( V_2 , V_49 ) ;
V_41 = 1 ;
}
if ( V_2 -> V_19 == V_19 )
return 0 ;
F_19 ( V_2 , V_19 ) ;
if ( V_41 )
F_4 ( V_2 ) ;
}
if ( V_2 -> V_19 == V_19 )
return 0 ;
V_2 -> V_19 = V_19 ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_19 ;
if ( V_2 -> V_39 & V_40 )
return 0 ;
if ( V_2 -> V_33 == V_49 )
return 0 ;
V_19 = F_14 ( V_2 , & V_2 -> V_50 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 == 48000 || V_19 == 44100 || V_19 == 32000 )
V_2 -> V_51 = V_19 ;
return 0 ;
}
