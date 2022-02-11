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
if ( V_27 -> V_32 & F_32 ( V_26 ) )
V_16 |= 0xf << F_33 ( V_26 ) ;
else
V_16 &= ~ ( 0xf << F_33 ( V_26 ) ) ;
F_3 ( V_16 , V_6 + V_31 ) ;
F_34 ( L_1 , V_33 , V_6 , V_16 ) ;
return 0 ;
}
static int F_35 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_16 ;
unsigned long V_30 ;
V_16 = F_2 ( V_6 + V_31 ) ;
V_16 &= ~ ( 0xf << F_33 ( V_26 ) ) ;
V_16 |= 0x1 << F_33 ( V_26 ) ;
V_30 = F_2 ( V_6 + V_34 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_3 ( V_16 , V_6 + V_31 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_34 ( L_2 , V_33 , V_6 , V_16 , V_30 ) ;
return 0 ;
}
static int F_36 ( struct V_25 * V_2 ,
unsigned int V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_35 = V_6 ;
unsigned long V_16 ;
if ( V_26 > 7 )
V_26 -= 8 ;
else
V_35 -= 4 ;
V_16 = F_2 ( V_35 ) ;
V_16 &= ~ ( 0xf << F_33 ( V_26 ) ) ;
F_3 ( V_16 , V_35 ) ;
F_34 ( L_3 , V_33 , V_6 , V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_35 = V_6 ;
unsigned long V_16 ;
unsigned long V_30 ;
unsigned V_36 = V_26 ;
if ( V_36 > 7 )
V_36 -= 8 ;
else
V_35 -= 4 ;
V_16 = F_2 ( V_35 ) ;
V_16 &= ~ ( 0xf << F_33 ( V_36 ) ) ;
V_16 |= 0x1 << F_33 ( V_36 ) ;
V_30 = F_2 ( V_6 + V_34 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_3 ( V_16 , V_35 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_34 ( L_2 , V_33 , V_6 , V_16 , V_30 ) ;
return 0 ;
}
static int F_38 ( struct V_25 * V_2 , unsigned V_26 )
{
return - V_14 ;
}
static int F_39 ( struct V_25 * V_2 ,
unsigned V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_30 ;
unsigned long V_16 ;
F_40 ( V_28 ) ;
V_16 = F_2 ( V_6 + 0x00 ) ;
V_30 = F_2 ( V_6 + 0x04 ) ;
V_30 &= ~ ( 1 << V_26 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
F_3 ( V_30 , V_6 + 0x04 ) ;
V_16 &= ~ ( 1 << V_26 ) ;
F_3 ( V_16 , V_6 + 0x00 ) ;
F_3 ( V_30 , V_6 + 0x04 ) ;
F_41 ( V_28 ) ;
return 0 ;
}
static int F_42 ( struct V_25 * V_2 ,
unsigned int V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_35 = V_6 ;
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
V_35 -= 4 ;
break;
default:
V_26 -= 7 ;
break;
}
F_28 ( V_27 , V_28 ) ;
V_16 = F_2 ( V_35 ) ;
V_16 &= ~ ( 0xf << F_33 ( V_26 ) ) ;
F_3 ( V_16 , V_35 ) ;
F_29 ( V_27 , V_28 ) ;
return 0 ;
}
static int F_43 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_35 = V_6 ;
unsigned long V_16 ;
unsigned long V_30 ;
unsigned long V_28 ;
unsigned V_36 = V_26 ;
switch ( V_36 ) {
case 6 :
V_36 += 1 ;
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
V_35 -= 4 ;
break;
default:
V_36 -= 7 ;
break;
}
F_28 ( V_27 , V_28 ) ;
V_16 = F_2 ( V_35 ) ;
V_16 &= ~ ( 0xf << F_33 ( V_36 ) ) ;
V_16 |= 0x1 << F_33 ( V_36 ) ;
V_30 = F_2 ( V_6 + V_34 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_16 , V_35 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_29 ( V_27 , V_28 ) ;
return 0 ;
}
static void F_44 ( struct V_25 * V_2 ,
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
static int F_45 ( struct V_25 * V_2 , unsigned V_26 )
{
struct V_1 * V_27 = F_27 ( V_2 ) ;
unsigned long V_37 ;
V_37 = F_2 ( V_27 -> V_6 + 0x04 ) ;
V_37 >>= V_26 ;
V_37 &= 1 ;
return V_37 ;
}
static T_4 void F_46 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
int V_39 ;
V_38 = V_2 -> V_2 . V_6 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_2 . V_17 ; V_39 ++ , V_38 ++ ) {
F_47 ( V_38 >= F_48 ( V_40 ) ) ;
V_40 [ V_38 ] = V_2 ;
}
}
static void T_4 F_49 ( struct V_1 * V_2 )
{
struct V_25 * V_41 = & V_2 -> V_2 ;
int V_42 ;
F_47 ( ! V_2 -> V_6 ) ;
F_47 ( ! V_41 -> V_43 ) ;
F_47 ( ! V_41 -> V_17 ) ;
F_50 ( & V_2 -> V_44 ) ;
if ( ! V_41 -> V_45 )
V_41 -> V_45 = F_26 ;
if ( ! V_41 -> V_46 )
V_41 -> V_46 = F_30 ;
if ( ! V_41 -> V_47 )
V_41 -> V_47 = F_44 ;
if ( ! V_41 -> V_48 )
V_41 -> V_48 = F_45 ;
#ifdef F_51
if ( V_2 -> V_49 != NULL ) {
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_51 )
F_52 ( L_4 ,
V_41 -> V_43 ) ;
} else
F_52 ( L_5 , V_41 -> V_43 ) ;
#endif
V_42 = F_53 ( V_41 ) ;
if ( V_42 >= 0 )
F_46 ( V_2 ) ;
}
static void T_4 F_54 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_39 ;
struct V_25 * V_41 = & V_2 -> V_2 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( V_2 -> V_2 . V_6 >= V_52 )
continue;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_54 ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_55 ( & V_55 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * 0x10 ) ;
if ( ! V_41 -> V_45 )
V_41 -> V_45 = F_26 ;
if ( ! V_41 -> V_46 )
V_41 -> V_46 = F_30 ;
F_49 ( V_2 ) ;
}
}
static void T_4 F_56 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 ,
unsigned int V_26 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_26 ;
V_2 -> V_2 . V_46 = F_30 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 7 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_55 ( & V_55 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * V_26 ) ;
F_49 ( V_2 ) ;
}
}
static void T_4 F_57 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_31 ;
V_2 -> V_2 . V_46 = F_35 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 2 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_55 ( & V_57 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * 0x20 ) ;
V_2 -> V_32 = 0 ;
F_49 ( V_2 ) ;
}
}
static void T_4 F_58 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_36 ;
V_2 -> V_2 . V_46 = F_37 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 2 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_55 ( & V_57 ) ;
F_49 ( V_2 ) ;
}
}
static void T_4 F_59 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_42 ;
V_2 -> V_2 . V_46 = F_43 ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_55 ( & V_57 ) ;
F_49 ( V_2 ) ;
}
}
int F_60 ( struct V_25 * V_2 , unsigned int V_26 )
{
struct V_1 * V_58 = F_61 ( V_2 , struct V_1 , V_2 ) ;
return V_58 -> V_59 + V_26 ;
}
static int F_62 ( struct V_25 * V_2 , unsigned V_26 )
{
if ( V_26 < 4 ) {
if ( F_63 () )
return V_60 + V_26 ;
else
return V_61 + V_26 ;
}
if ( V_26 < 8 )
return V_62 + V_26 - 4 ;
return - V_14 ;
}
static int F_64 ( struct V_25 * V_2 , unsigned V_63 )
{
return V_63 < 5 ? F_65 ( 23 ) + V_63 : - V_64 ;
}
static int F_66 ( struct V_25 * V_2 , unsigned V_63 )
{
return V_63 >= 8 ? F_65 ( 16 ) + V_63 - 8 : - V_64 ;
}
static int F_67 ( struct V_25 * V_41 ,
const struct V_65 * V_66 , T_3 * V_28 )
{
unsigned int V_63 ;
if ( F_68 ( V_41 -> V_67 < 4 ) )
return - V_14 ;
if ( F_68 ( V_66 -> V_68 < V_41 -> V_67 ) )
return - V_14 ;
if ( V_66 -> args [ 0 ] > V_41 -> V_17 )
return - V_14 ;
V_63 = V_41 -> V_6 + V_66 -> args [ 0 ] ;
if ( F_69 ( V_63 , F_23 ( V_66 -> args [ 1 ] ) ) )
F_70 ( L_6 ) ;
if ( F_71 ( V_63 , V_66 -> args [ 2 ] & 0xffff ) )
F_70 ( L_7 ) ;
if ( F_72 ( V_63 , V_66 -> args [ 3 ] ) )
F_70 ( L_8 ) ;
if ( V_28 )
* V_28 = V_66 -> args [ 2 ] >> 16 ;
return V_66 -> args [ 0 ] ;
}
static T_4 void F_73 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
struct V_25 * V_41 = & V_2 -> V_2 ;
T_5 V_69 ;
if ( ! F_74 () )
return;
V_69 = V_2 -> V_6 ? V_6 + ( ( T_3 ) V_2 -> V_6 & 0xfff ) : V_6 + V_26 ;
V_41 -> V_70 = F_75 ( NULL ,
V_71 , V_69 ) ;
if ( ! V_41 -> V_70 ) {
F_76 ( L_9
L_10 , V_69 ) ;
return;
}
V_41 -> V_67 = 4 ;
V_41 -> V_72 = F_67 ;
}
static T_4 void F_73 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
return;
}
static T_4 void F_77 ( void )
{
#ifdef F_78
struct V_1 * V_2 ;
int V_39 , V_20 ;
void T_2 * V_73 , * V_74 , * V_75 ;
int V_76 = 0 ;
void T_2 * V_77 ;
V_73 = F_79 ( V_78 , V_79 ) ;
if ( V_73 == NULL ) {
F_52 ( L_11 ) ;
goto V_80;
}
V_2 = V_81 ;
V_20 = F_48 ( V_81 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_82 ;
V_2 -> V_76 = V_76 ++ ;
}
F_73 ( V_2 ,
V_78 , V_39 * 0x20 ) ;
}
F_57 ( V_81 ,
V_20 , V_73 ) ;
V_74 = F_79 ( V_83 , V_79 ) ;
if ( V_74 == NULL ) {
F_52 ( L_12 ) ;
goto V_84;
}
V_2 = & V_85 [ 16 ] ;
V_77 = V_74 + 0xC00 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ , V_2 ++ , V_77 += 0x20 )
V_2 -> V_6 = V_77 ;
V_2 = V_85 ;
V_20 = F_48 ( V_85 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_82 ;
V_2 -> V_76 = V_76 ++ ;
}
F_73 ( V_2 ,
V_83 , V_39 * 0x20 ) ;
}
F_57 ( V_85 ,
V_20 , V_74 ) ;
V_75 = F_79 ( V_86 , V_87 ) ;
if ( V_75 == NULL ) {
F_52 ( L_13 ) ;
goto V_88;
}
V_2 = V_89 ;
V_20 = F_48 ( V_89 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_82 ;
V_2 -> V_76 = V_76 ++ ;
}
F_73 ( V_2 ,
V_86 , V_39 * 0x20 ) ;
}
F_57 ( V_89 ,
V_20 , V_75 ) ;
#if F_80 ( F_78 ) && F_80 ( V_90 )
F_81 ( V_91 , 0 , V_92 ) ;
F_81 ( V_93 , V_92 , V_94 ) ;
#endif
return;
V_88:
F_82 ( V_74 ) ;
V_84:
F_82 ( V_73 ) ;
V_80:
return;
#endif
}
static T_4 void F_83 ( void )
{
#ifdef F_84
struct V_1 * V_2 ;
int V_39 , V_20 ;
void T_2 * V_73 , * V_74 , * V_75 , * V_95 ;
int V_76 = 0 ;
void T_2 * V_77 ;
V_73 = F_79 ( V_96 , V_79 ) ;
if ( V_73 == NULL ) {
F_52 ( L_11 ) ;
goto V_80;
}
V_97 [ 20 ] . V_6 = V_73 + 0x2E0 ;
V_2 = & V_97 [ 21 ] ;
V_77 = V_73 + 0xC00 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ , V_2 ++ , V_77 += 0x20 )
V_2 -> V_6 = V_77 ;
V_2 = V_97 ;
V_20 = F_48 ( V_97 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_82 ;
V_2 -> V_76 = V_76 ++ ;
}
F_73 ( V_2 ,
V_96 , V_39 * 0x20 ) ;
}
F_57 ( V_97 ,
V_20 , V_73 ) ;
V_74 = F_79 ( V_98 , V_79 ) ;
if ( V_74 == NULL ) {
F_52 ( L_12 ) ;
goto V_84;
}
V_2 = V_99 ;
V_20 = F_48 ( V_99 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_82 ;
V_2 -> V_76 = V_76 ++ ;
}
F_73 ( V_2 ,
V_98 , V_39 * 0x20 ) ;
}
F_57 ( V_99 ,
V_20 , V_74 ) ;
V_75 = F_79 ( V_100 , V_79 ) ;
if ( V_75 == NULL ) {
F_52 ( L_13 ) ;
goto V_88;
}
V_101 [ 0 ] . V_6 = V_75 ;
V_101 [ 1 ] . V_6 = V_75 + 0x20 ;
V_101 [ 2 ] . V_6 = V_75 + 0x60 ;
V_101 [ 3 ] . V_6 = V_75 + 0x80 ;
V_101 [ 4 ] . V_6 = V_75 + 0xC0 ;
V_2 = V_101 ;
V_20 = F_48 ( V_101 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_82 ;
V_2 -> V_76 = V_76 ++ ;
}
F_73 ( V_2 ,
V_100 , V_39 * 0x20 ) ;
}
F_57 ( V_101 ,
V_20 , V_75 ) ;
V_95 = F_79 ( V_102 , V_79 ) ;
if ( V_95 == NULL ) {
F_52 ( L_14 ) ;
goto V_103;
}
V_2 = V_104 ;
V_20 = F_48 ( V_104 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_82 ;
V_2 -> V_76 = V_76 ++ ;
}
F_73 ( V_2 ,
V_102 , V_39 * 0x20 ) ;
}
F_57 ( V_104 ,
V_20 , V_95 ) ;
return;
V_103:
F_82 ( V_75 ) ;
V_88:
F_82 ( V_74 ) ;
V_84:
F_82 ( V_73 ) ;
V_80:
return;
#endif
}
static T_4 int F_85 ( void )
{
struct V_1 * V_2 ;
int V_39 , V_20 ;
int V_76 = 0 ;
#if F_80 ( V_105 ) || F_80 ( V_106 )
struct V_107 * V_108 ;
static const struct V_109 V_110 [] = {
{ . V_111 = L_15 , } ,
{ . V_111 = L_16 , } ,
{ . V_111 = L_17 , } ,
{ . V_111 = L_18 , } ,
{ . V_111 = L_19 , } ,
{ . V_111 = L_20 , } ,
{ . V_111 = L_21 , } ,
{ . V_111 = L_22 , } ,
{ }
} ;
F_86 (pctrl_np, exynos_pinctrl_ids)
if ( V_108 && F_87 ( V_108 ) )
return - V_112 ;
#endif
F_25 ( V_56 , F_48 ( V_56 ) ) ;
if ( F_88 () ) {
F_54 ( V_113 ,
F_48 ( V_113 ) , V_114 ) ;
} else if ( F_89 () ) {
F_56 ( V_115 ,
F_48 ( V_115 ) ,
V_116 + 0xE0 , 0x20 ) ;
F_57 ( V_117 ,
F_48 ( V_117 ) ,
V_116 ) ;
F_58 ( V_118 ,
F_48 ( V_118 ) ) ;
} else if ( F_90 () ) {
F_56 ( V_119 ,
F_48 ( V_119 ) , NULL , 0x0 ) ;
F_57 ( V_120 ,
F_48 ( V_120 ) , V_121 ) ;
F_58 ( V_122 ,
F_48 ( V_122 ) ) ;
F_59 ( V_123 ,
F_48 ( V_123 ) ) ;
} else if ( F_91 () ) {
F_56 ( V_124 ,
F_48 ( V_124 ) , NULL , 0x0 ) ;
F_57 ( V_125 ,
F_48 ( V_125 ) , V_121 ) ;
F_58 ( V_126 ,
F_48 ( V_126 ) ) ;
F_59 ( V_127 ,
F_48 ( V_127 ) ) ;
} else if ( F_92 () ) {
V_76 = 0 ;
V_2 = V_128 ;
V_20 = F_48 ( V_128 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_56 [ 3 ] ;
V_2 -> V_76 = V_76 ++ ;
}
}
F_57 ( V_128 , V_20 , V_121 ) ;
#if F_80 ( V_129 ) && F_80 ( V_90 )
F_81 ( V_130 , 0 , V_131 ) ;
#endif
} else if ( F_93 () ) {
V_76 = 0 ;
V_2 = V_132 ;
V_20 = F_48 ( V_132 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_53 ) {
V_2 -> V_53 = & V_56 [ 3 ] ;
V_2 -> V_76 = V_76 ++ ;
}
}
F_57 ( V_132 , V_20 , V_121 ) ;
#if F_80 ( V_133 ) && F_80 ( V_90 )
F_81 ( V_130 , 0 , V_131 ) ;
#endif
} else if ( F_94 () ) {
F_77 () ;
} else if ( F_95 () ) {
F_83 () ;
} else {
F_96 ( 1 , L_23 ) ;
return - V_112 ;
}
return 0 ;
}
int F_69 ( unsigned int V_63 , unsigned int V_53 )
{
struct V_1 * V_2 = F_97 ( V_63 ) ;
unsigned long V_28 ;
int V_26 ;
int V_42 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_42 = F_98 ( V_2 , V_26 , V_53 ) ;
F_29 ( V_2 , V_28 ) ;
return V_42 ;
}
int F_99 ( unsigned int V_134 , unsigned int V_135 ,
unsigned int V_15 )
{
int V_42 ;
for (; V_135 > 0 ; V_135 -- , V_134 ++ ) {
V_42 = F_69 ( V_134 , V_15 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
int F_100 ( unsigned int V_134 , unsigned int V_135 ,
unsigned int V_15 , T_1 V_4 )
{
int V_42 ;
for (; V_135 > 0 ; V_135 -- , V_134 ++ ) {
F_71 ( V_134 , V_4 ) ;
V_42 = F_69 ( V_134 , V_15 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
unsigned F_101 ( unsigned int V_63 )
{
struct V_1 * V_2 = F_97 ( V_63 ) ;
unsigned long V_28 ;
unsigned V_42 = 0 ;
int V_26 ;
if ( V_2 ) {
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_42 = F_102 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return V_42 ;
}
int F_71 ( unsigned int V_63 , T_1 V_4 )
{
struct V_1 * V_2 = F_97 ( V_63 ) ;
unsigned long V_28 ;
int V_26 , V_42 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_42 = F_103 ( V_2 , V_26 , V_4 ) ;
F_29 ( V_2 , V_28 ) ;
return V_42 ;
}
T_1 F_104 ( unsigned int V_63 )
{
struct V_1 * V_2 = F_97 ( V_63 ) ;
unsigned long V_28 ;
int V_26 ;
T_3 V_8 = 0 ;
if ( V_2 ) {
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_8 = F_105 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return ( V_9 T_1 ) V_8 ;
}
T_6 F_106 ( unsigned int V_63 )
{
struct V_1 * V_2 = F_97 ( V_63 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_136 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_63 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_136 = F_2 ( V_5 ) ;
V_136 = V_136 >> V_7 ;
V_136 &= 0x3 ;
return ( V_9 T_6 ) V_136 ;
}
int F_72 ( unsigned int V_63 , T_6 V_136 )
{
struct V_1 * V_2 = F_97 ( V_63 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_137 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_63 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_137 = F_2 ( V_5 ) ;
V_137 &= ~ ( 0x3 << V_7 ) ;
V_137 |= V_136 << V_7 ;
F_3 ( V_137 , V_5 ) ;
return 0 ;
}
unsigned int F_107 ( unsigned int V_138 , unsigned int V_139 )
{
unsigned long V_28 ;
unsigned long V_140 ;
F_40 ( V_28 ) ;
V_140 = F_2 ( V_141 ) ;
V_140 &= ~ V_138 ;
V_140 ^= V_139 ;
F_3 ( V_140 , V_141 ) ;
F_41 ( V_28 ) ;
return V_140 ;
}
