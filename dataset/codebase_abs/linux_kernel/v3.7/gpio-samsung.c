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
static int F_53 ( struct V_25 * V_40 ,
const struct V_52 * V_53 , T_3 * V_28 )
{
unsigned int V_54 ;
if ( F_54 ( V_40 -> V_55 < 3 ) )
return - V_14 ;
if ( F_54 ( V_53 -> V_56 < V_40 -> V_55 ) )
return - V_14 ;
if ( V_53 -> args [ 0 ] > V_40 -> V_17 )
return - V_14 ;
V_54 = V_40 -> V_6 + V_53 -> args [ 0 ] ;
if ( F_55 ( V_54 , F_23 ( V_53 -> args [ 1 ] ) ) )
F_56 ( L_6 ) ;
if ( F_57 ( V_54 , V_53 -> args [ 2 ] & 0xffff ) )
F_56 ( L_7 ) ;
if ( V_28 )
* V_28 = V_53 -> args [ 2 ] >> 16 ;
return V_53 -> args [ 0 ] ;
}
static T_4 void F_58 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
struct V_25 * V_40 = & V_2 -> V_2 ;
T_5 V_57 ;
if ( ! F_59 () )
return;
V_57 = V_2 -> V_6 ? V_6 + ( ( T_3 ) V_2 -> V_6 & 0xfff ) : V_6 + V_26 ;
V_40 -> V_58 = F_60 ( NULL ,
V_59 , V_57 ) ;
if ( ! V_40 -> V_58 ) {
F_61 ( L_8
L_9 , V_57 ) ;
return;
}
V_40 -> V_55 = 3 ;
V_40 -> V_60 = F_53 ;
}
static T_4 void F_58 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
return;
}
static void T_4 F_62 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_38 ;
struct V_25 * V_40 = & V_2 -> V_2 ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( V_2 -> V_2 . V_6 >= V_61 )
continue;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_63 ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_63 ( & V_64 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_38 ) * 0x10 ) ;
if ( ! V_40 -> V_44 )
V_40 -> V_44 = F_26 ;
if ( ! V_40 -> V_45 )
V_40 -> V_45 = F_30 ;
F_48 ( V_2 ) ;
F_58 ( V_2 , V_65 , V_38 * 0x10 ) ;
}
}
static void T_4 F_64 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 ,
unsigned int V_26 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_26 ;
V_2 -> V_2 . V_45 = F_30 ;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_66 [ 7 ] ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_63 ( & V_64 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_38 ) * V_26 ) ;
F_48 ( V_2 ) ;
}
}
static void T_4 F_65 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_31 ;
V_2 -> V_2 . V_45 = F_34 ;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_66 [ 2 ] ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_63 ( & V_67 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_38 ) * 0x20 ) ;
F_48 ( V_2 ) ;
}
}
static void T_4 F_66 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_35 ;
V_2 -> V_2 . V_45 = F_36 ;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_66 [ 2 ] ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_63 ( & V_67 ) ;
F_48 ( V_2 ) ;
}
}
static void T_4 F_67 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_44 = F_41 ;
V_2 -> V_2 . V_45 = F_42 ;
if ( ! V_2 -> V_48 )
V_2 -> V_48 = F_63 ( & V_67 ) ;
F_48 ( V_2 ) ;
}
}
int F_68 ( struct V_25 * V_2 , unsigned int V_26 )
{
struct V_1 * V_68 = F_69 ( V_2 , struct V_1 , V_2 ) ;
return V_68 -> V_69 + V_26 ;
}
static int F_70 ( struct V_25 * V_2 , unsigned V_26 )
{
if ( V_26 < 4 )
return V_70 + V_26 ;
if ( V_26 < 8 )
return V_71 + V_26 - 4 ;
return - V_14 ;
}
static int F_71 ( struct V_25 * V_2 , unsigned V_54 )
{
return V_54 < 5 ? F_72 ( 23 ) + V_54 : - V_72 ;
}
static int F_73 ( struct V_25 * V_2 , unsigned V_54 )
{
return V_54 >= 8 ? F_72 ( 16 ) + V_54 - 8 : - V_72 ;
}
static int F_74 ( struct V_25 * V_40 ,
const struct V_52 * V_53 , T_3 * V_28 )
{
unsigned int V_54 ;
if ( F_54 ( V_40 -> V_55 < 4 ) )
return - V_14 ;
if ( F_54 ( V_53 -> V_56 < V_40 -> V_55 ) )
return - V_14 ;
if ( V_53 -> args [ 0 ] > V_40 -> V_17 )
return - V_14 ;
V_54 = V_40 -> V_6 + V_53 -> args [ 0 ] ;
if ( F_55 ( V_54 , F_23 ( V_53 -> args [ 1 ] ) ) )
F_56 ( L_6 ) ;
if ( F_57 ( V_54 , V_53 -> args [ 2 ] & 0xffff ) )
F_56 ( L_7 ) ;
if ( F_75 ( V_54 , V_53 -> args [ 3 ] ) )
F_56 ( L_10 ) ;
if ( V_28 )
* V_28 = V_53 -> args [ 2 ] >> 16 ;
return V_53 -> args [ 0 ] ;
}
static T_4 void F_76 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
struct V_25 * V_40 = & V_2 -> V_2 ;
T_5 V_57 ;
if ( ! F_59 () )
return;
V_57 = V_2 -> V_6 ? V_6 + ( ( T_3 ) V_2 -> V_6 & 0xfff ) : V_6 + V_26 ;
V_40 -> V_58 = F_60 ( NULL ,
V_73 , V_57 ) ;
if ( ! V_40 -> V_58 ) {
F_61 ( L_8
L_9 , V_57 ) ;
return;
}
V_40 -> V_55 = 4 ;
V_40 -> V_60 = F_74 ;
}
static T_4 void F_76 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
return;
}
static T_4 void F_77 ( void )
{
#ifdef F_78
struct V_1 * V_2 ;
int V_38 , V_20 ;
void T_2 * V_74 , * V_75 , * V_76 ;
int V_77 = 0 ;
void T_2 * V_78 ;
#ifdef F_79
struct V_79 * V_80 ;
const char * V_81 = L_11 ;
V_80 = F_80 ( NULL , NULL , V_81 ) ;
if ( V_80 )
if ( F_81 ( V_80 ) )
return;
#endif
V_74 = F_82 ( V_82 , V_83 ) ;
if ( V_74 == NULL ) {
F_83 ( L_12 ) ;
goto V_84;
}
V_2 = V_85 ;
V_20 = F_47 ( V_85 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_86 ;
V_2 -> V_77 = V_77 ++ ;
}
F_76 ( V_2 ,
V_82 , V_38 * 0x20 ) ;
}
F_65 ( V_85 ,
V_20 , V_74 ) ;
V_75 = F_82 ( V_87 , V_83 ) ;
if ( V_75 == NULL ) {
F_83 ( L_13 ) ;
goto V_88;
}
V_2 = & V_89 [ 16 ] ;
V_78 = V_75 + 0xC00 ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ , V_2 ++ , V_78 += 0x20 )
V_2 -> V_6 = V_78 ;
V_2 = V_89 ;
V_20 = F_47 ( V_89 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_86 ;
V_2 -> V_77 = V_77 ++ ;
}
F_76 ( V_2 ,
V_87 , V_38 * 0x20 ) ;
}
F_65 ( V_89 ,
V_20 , V_75 ) ;
V_76 = F_82 ( V_90 , V_91 ) ;
if ( V_76 == NULL ) {
F_83 ( L_14 ) ;
goto V_92;
}
V_2 = V_93 ;
V_20 = F_47 ( V_93 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_86 ;
V_2 -> V_77 = V_77 ++ ;
}
F_76 ( V_2 ,
V_90 , V_38 * 0x20 ) ;
}
F_65 ( V_93 ,
V_20 , V_76 ) ;
#if F_84 ( F_78 ) && F_84 ( V_94 )
F_85 ( V_95 , 0 , V_96 ) ;
F_85 ( V_97 , V_96 , V_98 ) ;
#endif
return;
V_92:
F_86 ( V_75 ) ;
V_88:
F_86 ( V_74 ) ;
V_84:
return;
#endif
}
static T_4 void F_87 ( void )
{
#ifdef F_88
struct V_1 * V_2 ;
int V_38 , V_20 ;
void T_2 * V_74 , * V_75 , * V_76 , * V_99 ;
int V_77 = 0 ;
void T_2 * V_78 ;
V_74 = F_82 ( V_100 , V_83 ) ;
if ( V_74 == NULL ) {
F_83 ( L_12 ) ;
goto V_84;
}
V_101 [ 20 ] . V_6 = V_74 + 0x2E0 ;
V_2 = & V_101 [ 21 ] ;
V_78 = V_74 + 0xC00 ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ , V_2 ++ , V_78 += 0x20 )
V_2 -> V_6 = V_78 ;
V_2 = V_101 ;
V_20 = F_47 ( V_101 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_86 ;
V_2 -> V_77 = V_77 ++ ;
}
F_76 ( V_2 ,
V_100 , V_38 * 0x20 ) ;
}
F_65 ( V_101 ,
V_20 , V_74 ) ;
V_75 = F_82 ( V_102 , V_83 ) ;
if ( V_75 == NULL ) {
F_83 ( L_13 ) ;
goto V_88;
}
V_2 = V_103 ;
V_20 = F_47 ( V_103 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_86 ;
V_2 -> V_77 = V_77 ++ ;
}
F_76 ( V_2 ,
V_102 , V_38 * 0x20 ) ;
}
F_65 ( V_103 ,
V_20 , V_75 ) ;
V_76 = F_82 ( V_104 , V_83 ) ;
if ( V_76 == NULL ) {
F_83 ( L_14 ) ;
goto V_92;
}
V_105 [ 0 ] . V_6 = V_76 ;
V_105 [ 1 ] . V_6 = V_76 + 0x20 ;
V_105 [ 2 ] . V_6 = V_76 + 0x60 ;
V_105 [ 3 ] . V_6 = V_76 + 0x80 ;
V_105 [ 4 ] . V_6 = V_76 + 0xC0 ;
V_2 = V_105 ;
V_20 = F_47 ( V_105 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_86 ;
V_2 -> V_77 = V_77 ++ ;
}
F_76 ( V_2 ,
V_104 , V_38 * 0x20 ) ;
}
F_65 ( V_105 ,
V_20 , V_76 ) ;
V_99 = F_82 ( V_106 , V_83 ) ;
if ( V_99 == NULL ) {
F_83 ( L_15 ) ;
goto V_107;
}
V_2 = V_108 ;
V_20 = F_47 ( V_108 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_86 ;
V_2 -> V_77 = V_77 ++ ;
}
F_76 ( V_2 ,
V_106 , V_38 * 0x20 ) ;
}
F_65 ( V_108 ,
V_20 , V_99 ) ;
return;
V_107:
F_86 ( V_76 ) ;
V_92:
F_86 ( V_75 ) ;
V_88:
F_86 ( V_74 ) ;
V_84:
return;
#endif
}
static T_4 int F_89 ( void )
{
struct V_1 * V_2 ;
int V_38 , V_20 ;
int V_77 = 0 ;
F_25 ( V_66 , F_47 ( V_66 ) ) ;
if ( F_90 () ) {
F_62 ( V_109 ,
F_47 ( V_109 ) , V_110 ) ;
} else if ( F_91 () ) {
F_64 ( V_111 ,
F_47 ( V_111 ) ,
V_112 + 0xE0 , 0x20 ) ;
F_65 ( V_113 ,
F_47 ( V_113 ) ,
V_112 ) ;
F_66 ( V_114 ,
F_47 ( V_114 ) ) ;
} else if ( F_92 () ) {
F_64 ( V_115 ,
F_47 ( V_115 ) , NULL , 0x0 ) ;
F_65 ( V_116 ,
F_47 ( V_116 ) , V_117 ) ;
F_66 ( V_118 ,
F_47 ( V_118 ) ) ;
F_67 ( V_119 ,
F_47 ( V_119 ) ) ;
} else if ( F_93 () ) {
F_64 ( V_120 ,
F_47 ( V_120 ) , NULL , 0x0 ) ;
F_65 ( V_121 ,
F_47 ( V_121 ) , V_117 ) ;
F_66 ( V_122 ,
F_47 ( V_122 ) ) ;
F_67 ( V_123 ,
F_47 ( V_123 ) ) ;
} else if ( F_94 () ) {
V_77 = 0 ;
V_2 = V_124 ;
V_20 = F_47 ( V_124 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_66 [ 3 ] ;
V_2 -> V_77 = V_77 ++ ;
}
}
F_65 ( V_124 , V_20 , V_117 ) ;
#if F_84 ( V_125 ) && F_84 ( V_94 )
F_85 ( V_126 , 0 , V_127 ) ;
#endif
} else if ( F_95 () ) {
V_77 = 0 ;
V_2 = V_128 ;
V_20 = F_47 ( V_128 ) ;
for ( V_38 = 0 ; V_38 < V_20 ; V_38 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_66 [ 3 ] ;
V_2 -> V_77 = V_77 ++ ;
}
}
F_65 ( V_128 , V_20 , V_117 ) ;
#if F_84 ( V_129 ) && F_84 ( V_94 )
F_85 ( V_126 , 0 , V_127 ) ;
#endif
} else if ( F_96 () ) {
F_77 () ;
} else if ( F_97 () ) {
F_87 () ;
} else {
F_98 ( 1 , L_16 ) ;
return - V_130 ;
}
return 0 ;
}
int F_55 ( unsigned int V_54 , unsigned int V_62 )
{
struct V_1 * V_2 = F_99 ( V_54 ) ;
unsigned long V_28 ;
int V_26 ;
int V_41 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_41 = F_100 ( V_2 , V_26 , V_62 ) ;
F_29 ( V_2 , V_28 ) ;
return V_41 ;
}
int F_101 ( unsigned int V_131 , unsigned int V_132 ,
unsigned int V_15 )
{
int V_41 ;
for (; V_132 > 0 ; V_132 -- , V_131 ++ ) {
V_41 = F_55 ( V_131 , V_15 ) ;
if ( V_41 != 0 )
return V_41 ;
}
return 0 ;
}
int F_102 ( unsigned int V_131 , unsigned int V_132 ,
unsigned int V_15 , T_1 V_4 )
{
int V_41 ;
for (; V_132 > 0 ; V_132 -- , V_131 ++ ) {
F_57 ( V_131 , V_4 ) ;
V_41 = F_55 ( V_131 , V_15 ) ;
if ( V_41 != 0 )
return V_41 ;
}
return 0 ;
}
unsigned F_103 ( unsigned int V_54 )
{
struct V_1 * V_2 = F_99 ( V_54 ) ;
unsigned long V_28 ;
unsigned V_41 = 0 ;
int V_26 ;
if ( V_2 ) {
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_41 = F_104 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return V_41 ;
}
int F_57 ( unsigned int V_54 , T_1 V_4 )
{
struct V_1 * V_2 = F_99 ( V_54 ) ;
unsigned long V_28 ;
int V_26 , V_41 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_41 = F_105 ( V_2 , V_26 , V_4 ) ;
F_29 ( V_2 , V_28 ) ;
return V_41 ;
}
T_1 F_106 ( unsigned int V_54 )
{
struct V_1 * V_2 = F_99 ( V_54 ) ;
unsigned long V_28 ;
int V_26 ;
T_3 V_8 = 0 ;
if ( V_2 ) {
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_8 = F_107 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return ( V_9 T_1 ) V_8 ;
}
T_6 F_108 ( unsigned int V_54 )
{
struct V_1 * V_2 = F_99 ( V_54 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_133 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_54 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_133 = F_2 ( V_5 ) ;
V_133 = V_133 >> V_7 ;
V_133 &= 0x3 ;
return ( V_9 T_6 ) V_133 ;
}
int F_75 ( unsigned int V_54 , T_6 V_133 )
{
struct V_1 * V_2 = F_99 ( V_54 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_134 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_54 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_134 = F_2 ( V_5 ) ;
V_134 &= ~ ( 0x3 << V_7 ) ;
V_134 |= V_133 << V_7 ;
F_3 ( V_134 , V_5 ) ;
return 0 ;
}
unsigned int F_109 ( unsigned int V_135 , unsigned int V_136 )
{
unsigned long V_28 ;
unsigned long V_137 ;
F_39 ( V_28 ) ;
V_137 = F_2 ( V_138 ) ;
V_137 &= ~ V_135 ;
V_137 ^= V_136 ;
F_3 ( V_137 , V_138 ) ;
F_40 ( V_28 ) ;
return V_137 ;
}
