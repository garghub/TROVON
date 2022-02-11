int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + 0x08 ;
int V_7 = V_3 * 2 ;
T_3 V_8 ;
V_8 = F_2 ( V_5 ) ;
V_8 &= ~ ( 3 << V_7 ) ;
V_8 |= V_4 << V_7 ;
F_3 ( V_8 , V_5 ) ;
return 0 ;
}
T_1 F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
void T_2 * V_5 = V_2 -> V_6 + 0x08 ;
int V_7 = V_3 * 2 ;
T_3 V_8 = F_2 ( V_5 ) ;
V_8 >>= V_7 ;
V_8 &= 0x3 ;
return ( V_9 T_1 ) V_8 ;
}
int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
switch ( V_4 ) {
case V_10 :
V_4 = 0x01 ;
break;
case V_11 :
V_4 = 0x00 ;
break;
case V_12 :
V_4 = 0x02 ;
break;
}
return F_1 ( V_2 , V_3 , V_4 ) ;
}
T_1 F_6 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 ;
V_4 = F_4 ( V_2 , V_3 ) ;
switch ( V_4 ) {
case 0x00 :
V_4 = V_11 ;
break;
case 0x01 :
case 0x03 :
V_4 = V_10 ;
break;
case 0x02 :
V_4 = V_12 ;
break;
}
return V_4 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 ,
T_1 V_13 )
{
void T_2 * V_5 = V_2 -> V_6 + 0x08 ;
T_3 V_8 = F_2 ( V_5 ) ;
if ( V_4 == V_13 )
V_8 &= ~ ( 1 << V_3 ) ;
else if ( V_4 == V_10 )
V_8 |= ( 1 << V_3 ) ;
else
return - V_14 ;
F_3 ( V_8 , V_5 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
unsigned int V_3 ,
T_1 V_13 )
{
void T_2 * V_5 = V_2 -> V_6 + 0x08 ;
T_3 V_8 = F_2 ( V_5 ) ;
V_8 &= ( 1 << V_3 ) ;
return V_8 ? V_10 : V_13 ;
}
T_1 F_9 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_8 ( V_2 , V_3 , V_11 ) ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
return F_7 ( V_2 , V_3 , V_4 , V_11 ) ;
}
T_1 F_11 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_8 ( V_2 , V_3 , V_12 ) ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
return F_7 ( V_2 , V_3 , V_4 , V_12 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
if ( V_4 == V_11 )
V_4 = 3 ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 ;
V_4 = F_4 ( V_2 , V_3 ) ;
if ( V_4 == 3 )
V_4 = V_11 ;
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_15 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = V_3 * 2 ;
T_3 V_16 ;
if ( F_16 ( V_15 ) ) {
V_15 &= 0xf ;
if ( V_15 > 3 )
return - V_14 ;
V_15 <<= V_7 ;
}
V_16 = F_2 ( V_5 ) ;
V_16 &= ~ ( 0x3 << V_7 ) ;
V_16 |= V_15 ;
F_3 ( V_16 , V_5 ) ;
return 0 ;
}
static unsigned int F_17 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_3 V_16 ;
V_16 = F_2 ( V_2 -> V_6 ) ;
V_16 >>= V_3 * 2 ;
V_16 &= 3 ;
return F_18 ( V_16 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_15 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = ( V_3 & 7 ) * 4 ;
T_3 V_16 ;
if ( V_3 < 8 && V_2 -> V_2 . V_17 > 8 )
V_5 -= 4 ;
if ( F_16 ( V_15 ) ) {
V_15 &= 0xf ;
V_15 <<= V_7 ;
}
V_16 = F_2 ( V_5 ) ;
V_16 &= ~ ( 0xf << V_7 ) ;
V_16 |= V_15 ;
F_3 ( V_16 , V_5 ) ;
return 0 ;
}
static unsigned F_20 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = ( V_3 & 7 ) * 4 ;
T_3 V_16 ;
if ( V_3 < 8 && V_2 -> V_2 . V_17 > 8 )
V_5 -= 4 ;
V_16 = F_2 ( V_5 ) ;
V_16 >>= V_7 ;
V_16 &= 0xf ;
return F_18 ( V_16 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_15 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = V_3 ;
T_3 V_16 ;
if ( F_16 ( V_15 ) ) {
V_15 &= 0xf ;
V_15 -= 1 ;
if ( V_15 > 1 )
return - V_14 ;
V_15 <<= V_7 ;
}
V_16 = F_2 ( V_5 ) ;
V_16 &= ~ ( 0x1 << V_7 ) ;
V_16 |= V_15 ;
F_3 ( V_16 , V_5 ) ;
return 0 ;
}
static unsigned F_22 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_3 V_16 ;
V_16 = F_2 ( V_2 -> V_6 ) ;
V_16 >>= V_3 ;
V_16 &= 1 ;
V_16 ++ ;
return F_23 ( V_16 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_15 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
T_3 V_16 ;
switch ( V_3 ) {
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
V_7 = ( V_3 & 7 ) * 4 ;
V_5 -= 4 ;
break;
case 6 :
V_7 = ( ( V_3 + 1 ) & 7 ) * 4 ;
V_5 -= 4 ;
default:
V_7 = ( ( V_3 + 1 ) & 7 ) * 4 ;
break;
}
if ( F_16 ( V_15 ) ) {
V_15 &= 0xf ;
V_15 <<= V_7 ;
}
V_16 = F_2 ( V_5 ) ;
V_16 &= ~ ( 0xf << V_7 ) ;
V_16 |= V_15 ;
F_3 ( V_16 , V_5 ) ;
return 0 ;
}
static void T_4 F_25 ( struct V_18 * V_19 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_19 ++ ) {
if ( ! V_19 -> V_21 )
V_19 -> V_21 = F_19 ;
if ( ! V_19 -> V_22 )
V_19 -> V_22 = F_20 ;
if ( ! V_19 -> V_23 )
V_19 -> V_23 = F_1 ;
if ( ! V_19 -> V_24 )
V_19 -> V_24 = F_4 ;
}
}
static int F_26 ( struct V_25 * V_2 , unsigned V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_16 ;
F_28 ( V_27 , V_28 ) ;
V_16 = F_2 ( V_6 + 0x00 ) ;
V_16 &= ~ ( 3 << ( V_26 * 2 ) ) ;
F_3 ( V_16 , V_6 + 0x00 ) ;
F_29 ( V_27 , V_28 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_2 ,
unsigned V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_30 ;
unsigned long V_16 ;
F_28 ( V_27 , V_28 ) ;
V_30 = F_2 ( V_6 + 0x04 ) ;
V_30 &= ~ ( 1 << V_26 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
F_3 ( V_30 , V_6 + 0x04 ) ;
V_16 = F_2 ( V_6 + 0x00 ) ;
V_16 &= ~ ( 3 << ( V_26 * 2 ) ) ;
V_16 |= 1 << ( V_26 * 2 ) ;
F_3 ( V_16 , V_6 + 0x00 ) ;
F_3 ( V_30 , V_6 + 0x04 ) ;
F_29 ( V_27 , V_28 ) ;
return 0 ;
}
static int F_31 ( struct V_25 * V_2 ,
unsigned int V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_16 ;
V_16 = F_2 ( V_6 + V_31 ) ;
V_16 &= ~ ( 0xf << F_32 ( V_26 ) ) ;
F_3 ( V_16 , V_6 + V_31 ) ;
F_33 ( L_1 , V_32 , V_6 , V_16 ) ;
return 0 ;
}
static int F_34 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_16 ;
unsigned long V_30 ;
V_16 = F_2 ( V_6 + V_31 ) ;
V_16 &= ~ ( 0xf << F_32 ( V_26 ) ) ;
V_16 |= 0x1 << F_32 ( V_26 ) ;
V_30 = F_2 ( V_6 + V_33 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_30 , V_6 + V_33 ) ;
F_3 ( V_16 , V_6 + V_31 ) ;
F_3 ( V_30 , V_6 + V_33 ) ;
F_33 ( L_2 , V_32 , V_6 , V_16 , V_30 ) ;
return 0 ;
}
static int F_35 ( struct V_25 * V_2 ,
unsigned int V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_34 = V_6 ;
unsigned long V_16 ;
if ( V_26 > 7 )
V_26 -= 8 ;
else
V_34 -= 4 ;
V_16 = F_2 ( V_34 ) ;
V_16 &= ~ ( 0xf << F_32 ( V_26 ) ) ;
F_3 ( V_16 , V_34 ) ;
F_33 ( L_3 , V_32 , V_6 , V_16 ) ;
return 0 ;
}
static int F_36 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_34 = V_6 ;
unsigned long V_16 ;
unsigned long V_30 ;
unsigned V_35 = V_26 ;
if ( V_35 > 7 )
V_35 -= 8 ;
else
V_34 -= 4 ;
V_16 = F_2 ( V_34 ) ;
V_16 &= ~ ( 0xf << F_32 ( V_35 ) ) ;
V_16 |= 0x1 << F_32 ( V_35 ) ;
V_30 = F_2 ( V_6 + V_33 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_30 , V_6 + V_33 ) ;
F_3 ( V_16 , V_34 ) ;
F_3 ( V_30 , V_6 + V_33 ) ;
F_33 ( L_2 , V_32 , V_6 , V_16 , V_30 ) ;
return 0 ;
}
static int F_37 ( struct V_25 * V_2 , unsigned V_26 )
{
return - V_14 ;
}
static int F_38 ( struct V_25 * V_2 ,
unsigned V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_30 ;
unsigned long V_16 ;
F_39 ( V_28 ) ;
V_16 = F_2 ( V_6 + 0x00 ) ;
V_30 = F_2 ( V_6 + 0x04 ) ;
V_30 &= ~ ( 1 << V_26 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
F_3 ( V_30 , V_6 + 0x04 ) ;
V_16 &= ~ ( 1 << V_26 ) ;
F_3 ( V_16 , V_6 + 0x00 ) ;
F_3 ( V_30 , V_6 + 0x04 ) ;
F_40 ( V_28 ) ;
return 0 ;
}
static int F_41 ( struct V_25 * V_2 ,
unsigned int V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_34 = V_6 ;
unsigned long V_16 ;
unsigned long V_28 ;
switch ( V_26 ) {
case 6 :
V_26 += 1 ;
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
V_34 -= 4 ;
break;
default:
V_26 -= 7 ;
break;
}
F_28 ( V_27 , V_28 ) ;
V_16 = F_2 ( V_34 ) ;
V_16 &= ~ ( 0xf << F_32 ( V_26 ) ) ;
F_3 ( V_16 , V_34 ) ;
F_29 ( V_27 , V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_34 = V_6 ;
unsigned long V_16 ;
unsigned long V_30 ;
unsigned long V_28 ;
unsigned V_35 = V_26 ;
switch ( V_35 ) {
case 6 :
V_35 += 1 ;
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
V_34 -= 4 ;
break;
default:
V_35 -= 7 ;
break;
}
F_28 ( V_27 , V_28 ) ;
V_16 = F_2 ( V_34 ) ;
V_16 &= ~ ( 0xf << F_32 ( V_35 ) ) ;
V_16 |= 0x1 << F_32 ( V_35 ) ;
V_30 = F_2 ( V_6 + V_33 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_16 , V_34 ) ;
F_3 ( V_30 , V_6 + V_33 ) ;
F_29 ( V_27 , V_28 ) ;
return 0 ;
}
static void F_43 ( struct V_25 * V_2 ,
unsigned V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_30 ;
F_28 ( V_27 , V_28 ) ;
V_30 = F_2 ( V_6 + 0x04 ) ;
V_30 &= ~ ( 1 << V_26 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
F_3 ( V_30 , V_6 + 0x04 ) ;
F_29 ( V_27 , V_28 ) ;
}
static int F_44 ( struct V_25 * V_2 , unsigned V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
unsigned long V_36 ;
V_36 = F_2 ( V_27 -> V_6 + 0x04 ) ;
V_36 >>= V_26 ;
V_36 &= 1 ;
return V_36 ;
}
static T_4 void F_45 ( struct V_1 * V_2 )
{
unsigned int V_37 ;
int V_38 ;
V_37 = V_2 -> V_2 . V_6 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_2 . V_17 ; V_38 ++ , V_37 ++ ) {
F_46 ( V_37 >= F_47 ( V_39 ) ) ;
V_39 [ V_37 ] = V_2 ;
}
}
static void T_4 F_48 ( struct V_1 * V_2 )
{
struct V_25 * V_40 = & V_2 -> V_2 ;
int V_41 ;
F_46 ( ! V_2 -> V_6 ) ;
F_46 ( ! V_40 -> V_42 ) ;
F_46 ( ! V_40 -> V_17 ) ;
F_49 ( & V_2 -> V_43 ) ;
if ( ! V_40 -> V_44 )
V_40 -> V_44 = F_26 ;
if ( ! V_40 -> V_45 )
V_40 -> V_45 = F_30 ;
if ( ! V_40 -> V_46 )
V_40 -> V_46 = F_43 ;
if ( ! V_40 -> V_47 )
V_40 -> V_47 = F_44 ;
#ifdef F_50
if ( V_2 -> V_48 != NULL ) {
if ( ! V_2 -> V_48 -> V_49 || ! V_2 -> V_48 -> V_50 )
F_51 ( V_51 L_4 ,
V_40 -> V_42 ) ;
} else
F_51 ( V_51 L_5 , V_40 -> V_42 ) ;
#endif
V_41 = F_52 ( V_40 ) ;
if ( V_41 >= 0 )
F_45 ( V_2 ) ;
}
static void T_4 F_53 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_38 ;
struct V_25 * V_40 = & V_2 -> V_2 ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( V_2 -> V_2 . V_6 >= V_52 )
continue;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_54 ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_54 ( & V_55 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_38 ) * 0x10 ) ;
if ( ! V_40 -> V_44 )
V_40 -> V_44 = F_26 ;
if ( ! V_40 -> V_45 )
V_40 -> V_45 = F_30 ;
F_48 ( V_2 ) ;
}
}
static void T_4 F_55 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 ,
unsigned int V_26 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_26 ;
V_2 -> V_2 . V_45 = F_30 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 7 ] ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_54 ( & V_55 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_38 ) * V_26 ) ;
F_48 ( V_2 ) ;
}
}
static void T_4 F_56 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_31 ;
V_2 -> V_2 . V_45 = F_34 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 2 ] ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_54 ( & V_57 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_38 ) * 0x20 ) ;
F_48 ( V_2 ) ;
}
}
static void T_4 F_57 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_35 ;
V_2 -> V_2 . V_45 = F_36 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 2 ] ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_54 ( & V_57 ) ;
F_48 ( V_2 ) ;
}
}
static void T_4 F_58 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_41 ;
V_2 -> V_2 . V_45 = F_42 ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_54 ( & V_57 ) ;
F_48 ( V_2 ) ;
}
}
int F_59 ( struct V_25 * V_2 , unsigned int V_26 )
{
struct V_1 * V_58 = F_60 ( V_2 , struct V_1 , V_2 ) ;
return V_58 -> V_59 + V_26 ;
}
static int F_61 ( struct V_25 * V_2 , unsigned V_26 )
{
if ( V_26 < 4 )
return V_60 + V_26 ;
if ( V_26 < 8 )
return V_61 + V_26 - 4 ;
return - V_14 ;
}
static int F_62 ( struct V_25 * V_2 , unsigned V_62 )
{
return V_62 < 5 ? F_63 ( 23 ) + V_62 : - V_63 ;
}
static int F_64 ( struct V_25 * V_2 , unsigned V_62 )
{
return V_62 >= 8 ? F_63 ( 16 ) + V_62 - 8 : - V_63 ;
}
static int F_65 ( struct V_25 * V_40 ,
const struct V_64 * V_65 , T_3 * V_28 )
{
unsigned int V_62 ;
if ( F_66 ( V_40 -> V_66 < 4 ) )
return - V_14 ;
if ( F_66 ( V_65 -> V_67 < V_40 -> V_66 ) )
return - V_14 ;
if ( V_65 -> args [ 0 ] > V_40 -> V_17 )
return - V_14 ;
V_62 = V_40 -> V_6 + V_65 -> args [ 0 ] ;
if ( F_67 ( V_62 , F_23 ( V_65 -> args [ 1 ] ) ) )
F_68 ( L_6 ) ;
if ( F_69 ( V_62 , V_65 -> args [ 2 ] ) )
F_68 ( L_7 ) ;
if ( F_70 ( V_62 , V_65 -> args [ 3 ] ) )
F_68 ( L_8 ) ;
return V_65 -> args [ 0 ] ;
}
static T_4 void F_71 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
struct V_25 * V_40 = & V_2 -> V_2 ;
T_5 V_68 ;
if ( ! F_72 () )
return;
V_68 = V_2 -> V_6 ? V_6 + ( ( T_3 ) V_2 -> V_6 & 0xfff ) : V_6 + V_26 ;
V_40 -> V_69 = F_73 ( NULL ,
V_70 , V_68 ) ;
if ( ! V_40 -> V_69 ) {
F_74 ( L_9
L_10 , V_68 ) ;
return;
}
V_40 -> V_66 = 4 ;
V_40 -> V_71 = F_65 ;
}
static T_4 void F_71 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
return;
}
static T_4 int F_75 ( void )
{
struct V_1 * V_2 ;
int V_38 , V_20 ;
int V_72 = 0 ;
F_25 ( V_56 , F_47 ( V_56 ) ) ;
if ( F_76 () ) {
F_53 ( V_73 ,
F_47 ( V_73 ) , V_74 ) ;
} else if ( F_77 () ) {
F_55 ( V_75 ,
F_47 ( V_75 ) ,
V_76 + 0xE0 , 0x20 ) ;
F_56 ( V_77 ,
F_47 ( V_77 ) ,
V_76 ) ;
F_57 ( V_78 ,
F_47 ( V_78 ) ) ;
} else if ( F_78 () ) {
F_55 ( V_79 ,
F_47 ( V_79 ) , NULL , 0x0 ) ;
F_56 ( V_80 ,
F_47 ( V_80 ) , V_81 ) ;
F_57 ( V_82 ,
F_47 ( V_82 ) ) ;
F_58 ( V_83 ,
F_47 ( V_83 ) ) ;
} else if ( F_79 () ) {
F_55 ( V_84 ,
F_47 ( V_84 ) , NULL , 0x0 ) ;
F_56 ( V_85 ,
F_47 ( V_85 ) , V_81 ) ;
F_57 ( V_86 ,
F_47 ( V_86 ) ) ;
F_58 ( V_87 ,
F_47 ( V_87 ) ) ;
} else if ( F_80 () ) {
V_72 = 0 ;
V_2 = V_88 ;
V_20 = F_47 ( V_88 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_56 [ 3 ] ;
V_2 -> V_72 = V_72 ++ ;
}
}
F_56 ( V_88 , V_20 , V_81 ) ;
#if F_81 ( V_89 ) && F_81 ( V_90 )
F_82 ( V_91 , 0 , V_92 ) ;
#endif
} else if ( F_83 () ) {
V_72 = 0 ;
V_2 = V_93 ;
V_20 = F_47 ( V_93 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_56 [ 3 ] ;
V_2 -> V_72 = V_72 ++ ;
}
}
F_56 ( V_93 , V_20 , V_81 ) ;
#if F_81 ( V_94 ) && F_81 ( V_90 )
F_82 ( V_91 , 0 , V_92 ) ;
#endif
} else if ( F_84 () ) {
V_72 = 0 ;
V_2 = V_95 ;
V_20 = F_47 ( V_95 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_96 ;
V_2 -> V_72 = V_72 ++ ;
}
#ifdef F_85
F_71 ( V_2 ,
V_97 , V_38 * 0x20 ) ;
#endif
}
F_56 ( V_95 , V_20 , V_98 ) ;
V_2 = V_99 ;
V_20 = F_47 ( V_99 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_96 ;
V_2 -> V_72 = V_72 ++ ;
}
#ifdef F_85
F_71 ( V_2 ,
V_100 , V_38 * 0x20 ) ;
#endif
}
F_56 ( V_99 , V_20 , V_101 ) ;
V_2 = V_102 ;
V_20 = F_47 ( V_102 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_96 ;
V_2 -> V_72 = V_72 ++ ;
}
#ifdef F_85
F_71 ( V_2 ,
V_103 , V_38 * 0x20 ) ;
#endif
}
F_56 ( V_102 , V_20 , V_104 ) ;
#if F_81 ( F_85 ) && F_81 ( V_90 )
F_82 ( V_105 , 0 , V_106 ) ;
F_82 ( V_107 , V_106 , V_108 ) ;
#endif
} else {
F_86 ( 1 , L_11 ) ;
return - V_109 ;
}
return 0 ;
}
int F_67 ( unsigned int V_62 , unsigned int V_53 )
{
struct V_1 * V_2 = F_87 ( V_62 ) ;
unsigned long V_28 ;
int V_26 ;
int V_41 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_62 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_41 = F_88 ( V_2 , V_26 , V_53 ) ;
F_29 ( V_2 , V_28 ) ;
return V_41 ;
}
int F_89 ( unsigned int V_110 , unsigned int V_111 ,
unsigned int V_15 )
{
int V_41 ;
for (; V_111 > 0 ; V_111 -- , V_110 ++ ) {
V_41 = F_67 ( V_110 , V_15 ) ;
if ( V_41 != 0 )
return V_41 ;
}
return 0 ;
}
int F_90 ( unsigned int V_110 , unsigned int V_111 ,
unsigned int V_15 , T_1 V_4 )
{
int V_41 ;
for (; V_111 > 0 ; V_111 -- , V_110 ++ ) {
F_69 ( V_110 , V_4 ) ;
V_41 = F_67 ( V_110 , V_15 ) ;
if ( V_41 != 0 )
return V_41 ;
}
return 0 ;
}
unsigned F_91 ( unsigned int V_62 )
{
struct V_1 * V_2 = F_87 ( V_62 ) ;
unsigned long V_28 ;
unsigned V_41 = 0 ;
int V_26 ;
if ( V_2 ) {
V_26 = V_62 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_41 = F_92 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return V_41 ;
}
int F_69 ( unsigned int V_62 , T_1 V_4 )
{
struct V_1 * V_2 = F_87 ( V_62 ) ;
unsigned long V_28 ;
int V_26 , V_41 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_62 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_41 = F_93 ( V_2 , V_26 , V_4 ) ;
F_29 ( V_2 , V_28 ) ;
return V_41 ;
}
T_1 F_94 ( unsigned int V_62 )
{
struct V_1 * V_2 = F_87 ( V_62 ) ;
unsigned long V_28 ;
int V_26 ;
T_3 V_8 = 0 ;
if ( V_2 ) {
V_26 = V_62 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_8 = F_95 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return ( V_9 T_1 ) V_8 ;
}
void F_96 ( unsigned int V_62 , unsigned int V_112 )
{
int V_41 ;
F_66 ( V_112 ) ;
if ( ! V_112 ) {
V_41 = F_69 ( V_62 , V_11 ) ;
if ( V_41 )
F_69 ( V_62 , V_12 ) ;
} else {
F_69 ( V_62 , V_10 ) ;
}
}
void F_97 ( unsigned int V_62 , unsigned int V_112 )
{
F_98 ( V_62 , L_12 ) ;
F_99 ( V_62 , V_112 ) ;
F_100 ( V_62 ) ;
}
unsigned int F_101 ( unsigned int V_62 )
{
struct V_1 * V_2 = F_87 ( V_62 ) ;
unsigned long V_113 = V_62 - V_2 -> V_2 . V_6 ;
return F_2 ( V_2 -> V_6 + 0x04 ) & ( 1 << V_113 ) ;
}
T_6 F_102 ( unsigned int V_62 )
{
struct V_1 * V_2 = F_87 ( V_62 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_114 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_62 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_114 = F_2 ( V_5 ) ;
V_114 = V_114 >> V_7 ;
V_114 &= 0x3 ;
return ( V_9 T_6 ) V_114 ;
}
int F_70 ( unsigned int V_62 , T_6 V_114 )
{
struct V_1 * V_2 = F_87 ( V_62 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_115 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_62 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_115 = F_2 ( V_5 ) ;
V_115 &= ~ ( 0x3 << V_7 ) ;
V_115 |= V_114 << V_7 ;
F_3 ( V_115 , V_5 ) ;
return 0 ;
}
unsigned int F_103 ( unsigned int V_116 , unsigned int V_117 )
{
unsigned long V_28 ;
unsigned long V_118 ;
F_39 ( V_28 ) ;
V_118 = F_2 ( V_119 ) ;
V_118 &= ~ V_116 ;
V_118 ^= V_117 ;
F_3 ( V_118 , V_119 ) ;
F_40 ( V_28 ) ;
return V_118 ;
}
