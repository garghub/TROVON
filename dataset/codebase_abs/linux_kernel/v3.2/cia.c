unsigned char F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned char V_4 ;
V_4 = ( V_2 -> V_5 |= V_2 -> V_6 -> V_7 ) ;
if ( V_3 & V_8 )
V_2 -> V_5 |= V_3 ;
else
V_2 -> V_5 &= ~ V_3 ;
if ( V_2 -> V_5 & V_2 -> V_9 )
V_10 . V_11 = V_12 | V_2 -> V_13 ;
return V_4 & V_2 -> V_9 ;
}
unsigned char F_2 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned char V_4 ;
V_4 = V_2 -> V_9 ;
V_2 -> V_5 |= V_2 -> V_6 -> V_7 ;
V_2 -> V_6 -> V_7 = V_3 ;
if ( V_3 & V_8 )
V_2 -> V_9 |= V_3 ;
else
V_2 -> V_9 &= ~ V_3 ;
V_2 -> V_9 &= V_14 ;
if ( V_2 -> V_5 & V_2 -> V_9 )
V_10 . V_11 = V_12 | V_2 -> V_13 ;
return V_4 ;
}
static T_1 F_3 ( int V_15 , void * V_16 )
{
struct V_1 * V_2 = V_16 ;
int V_17 ;
unsigned char V_18 ;
V_17 = V_2 -> V_19 ;
V_18 = F_1 ( V_2 , V_14 ) ;
V_10 . V_11 = V_2 -> V_13 ;
for (; V_18 ; V_17 ++ , V_18 >>= 1 ) {
if ( V_18 & 1 )
F_4 ( V_17 ) ;
}
return V_20 ;
}
static void F_5 ( struct V_21 * V_22 )
{
unsigned int V_15 = V_22 -> V_15 ;
unsigned char V_3 ;
if ( V_15 >= V_23 ) {
V_3 = 1 << ( V_15 - V_23 ) ;
F_1 ( & V_24 , V_3 ) ;
F_2 ( & V_24 , V_8 | V_3 ) ;
} else {
V_3 = 1 << ( V_15 - V_25 ) ;
F_1 ( & V_26 , V_3 ) ;
F_2 ( & V_26 , V_8 | V_3 ) ;
}
}
static void F_6 ( struct V_21 * V_22 )
{
unsigned int V_15 = V_22 -> V_15 ;
if ( V_15 >= V_23 )
F_2 ( & V_24 , 1 << ( V_15 - V_23 ) ) ;
else
F_2 ( & V_26 , 1 << ( V_15 - V_25 ) ) ;
}
static void F_7 ( struct V_21 * V_22 )
{
switch ( V_22 -> V_15 ) {
case V_27 :
V_10 . V_28 = V_12 | V_29 ;
break;
case V_30 :
V_10 . V_28 = V_12 | V_31 ;
break;
}
}
static void F_8 ( struct V_21 * V_22 )
{
switch ( V_22 -> V_15 ) {
case V_27 :
V_10 . V_28 = V_29 ;
break;
case V_30 :
V_10 . V_28 = V_31 ;
break;
}
}
void T_2 F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_32 , V_33 ,
V_2 -> V_19 , V_34 ) ;
F_1 ( V_2 , V_14 ) ;
F_2 ( V_2 , V_14 ) ;
F_10 ( & V_35 , V_33 ,
V_2 -> V_36 , 1 ) ;
F_11 ( V_2 -> V_36 ) ;
if ( F_12 ( V_2 -> V_36 , F_3 , V_37 ,
V_2 -> V_38 , V_2 ) )
F_13 ( L_1 , V_2 -> V_38 ) ;
}
