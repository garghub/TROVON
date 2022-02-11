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
static int F_54 ( struct V_25 * V_41 ,
const struct V_52 * V_53 , T_3 * V_28 )
{
unsigned int V_54 ;
if ( F_55 ( V_41 -> V_55 < 3 ) )
return - V_14 ;
if ( F_55 ( V_53 -> V_56 < V_41 -> V_55 ) )
return - V_14 ;
if ( V_53 -> args [ 0 ] > V_41 -> V_17 )
return - V_14 ;
V_54 = V_41 -> V_6 + V_53 -> args [ 0 ] ;
if ( F_56 ( V_54 , F_23 ( V_53 -> args [ 1 ] ) ) )
F_57 ( L_6 ) ;
if ( F_58 ( V_54 , V_53 -> args [ 2 ] & 0xffff ) )
F_57 ( L_7 ) ;
if ( V_28 )
* V_28 = V_53 -> args [ 2 ] >> 16 ;
return V_53 -> args [ 0 ] ;
}
static T_4 void F_59 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
struct V_25 * V_41 = & V_2 -> V_2 ;
T_5 V_57 ;
if ( ! F_60 () )
return;
V_57 = V_2 -> V_6 ? V_6 + ( ( T_3 ) V_2 -> V_6 & 0xfff ) : V_6 + V_26 ;
V_41 -> V_58 = F_61 ( NULL ,
V_59 , V_57 ) ;
if ( ! V_41 -> V_58 ) {
F_62 ( L_8
L_9 , V_57 ) ;
return;
}
V_41 -> V_55 = 3 ;
V_41 -> V_60 = F_54 ;
}
static T_4 void F_59 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
return;
}
static void T_4 F_63 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_39 ;
struct V_25 * V_41 = & V_2 -> V_2 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( V_2 -> V_2 . V_6 >= V_61 )
continue;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_63 ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_64 ( & V_64 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * 0x10 ) ;
if ( ! V_41 -> V_45 )
V_41 -> V_45 = F_26 ;
if ( ! V_41 -> V_46 )
V_41 -> V_46 = F_30 ;
F_49 ( V_2 ) ;
F_59 ( V_2 , V_65 , V_39 * 0x10 ) ;
}
}
static void T_4 F_65 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 ,
unsigned int V_26 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_26 ;
V_2 -> V_2 . V_46 = F_30 ;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_66 [ 7 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_64 ( & V_64 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * V_26 ) ;
F_49 ( V_2 ) ;
}
}
static void T_4 F_66 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_31 ;
V_2 -> V_2 . V_46 = F_35 ;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_66 [ 2 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_64 ( & V_67 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * 0x20 ) ;
V_2 -> V_32 = 0 ;
F_49 ( V_2 ) ;
}
}
static void T_4 F_67 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_36 ;
V_2 -> V_2 . V_46 = F_37 ;
if ( ! V_2 -> V_62 )
V_2 -> V_62 = & V_66 [ 2 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_64 ( & V_67 ) ;
F_49 ( V_2 ) ;
}
}
static void T_4 F_68 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_42 ;
V_2 -> V_2 . V_46 = F_43 ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_64 ( & V_67 ) ;
F_49 ( V_2 ) ;
}
}
int F_69 ( struct V_25 * V_2 , unsigned int V_26 )
{
struct V_1 * V_68 = F_70 ( V_2 , struct V_1 , V_2 ) ;
return V_68 -> V_69 + V_26 ;
}
static int F_71 ( struct V_25 * V_2 , unsigned V_26 )
{
if ( V_26 < 4 )
return V_70 + V_26 ;
if ( V_26 < 8 )
return V_71 + V_26 - 4 ;
return - V_14 ;
}
static int F_72 ( struct V_25 * V_2 , unsigned V_54 )
{
return V_54 < 5 ? F_73 ( 23 ) + V_54 : - V_72 ;
}
static int F_74 ( struct V_25 * V_2 , unsigned V_54 )
{
return V_54 >= 8 ? F_73 ( 16 ) + V_54 - 8 : - V_72 ;
}
static int F_75 ( struct V_25 * V_41 ,
const struct V_52 * V_53 , T_3 * V_28 )
{
unsigned int V_54 ;
if ( F_55 ( V_41 -> V_55 < 4 ) )
return - V_14 ;
if ( F_55 ( V_53 -> V_56 < V_41 -> V_55 ) )
return - V_14 ;
if ( V_53 -> args [ 0 ] > V_41 -> V_17 )
return - V_14 ;
V_54 = V_41 -> V_6 + V_53 -> args [ 0 ] ;
if ( F_56 ( V_54 , F_23 ( V_53 -> args [ 1 ] ) ) )
F_57 ( L_6 ) ;
if ( F_58 ( V_54 , V_53 -> args [ 2 ] & 0xffff ) )
F_57 ( L_7 ) ;
if ( F_76 ( V_54 , V_53 -> args [ 3 ] ) )
F_57 ( L_10 ) ;
if ( V_28 )
* V_28 = V_53 -> args [ 2 ] >> 16 ;
return V_53 -> args [ 0 ] ;
}
static T_4 void F_77 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
struct V_25 * V_41 = & V_2 -> V_2 ;
T_5 V_57 ;
if ( ! F_60 () )
return;
V_57 = V_2 -> V_6 ? V_6 + ( ( T_3 ) V_2 -> V_6 & 0xfff ) : V_6 + V_26 ;
V_41 -> V_58 = F_61 ( NULL ,
V_73 , V_57 ) ;
if ( ! V_41 -> V_58 ) {
F_62 ( L_8
L_9 , V_57 ) ;
return;
}
V_41 -> V_55 = 4 ;
V_41 -> V_60 = F_75 ;
}
static T_4 void F_77 ( struct V_1 * V_2 ,
T_5 V_6 , T_5 V_26 )
{
return;
}
static T_4 void F_78 ( void )
{
#ifdef F_79
struct V_1 * V_2 ;
int V_39 , V_20 ;
void T_2 * V_74 , * V_75 , * V_76 ;
int V_77 = 0 ;
void T_2 * V_78 ;
V_74 = F_80 ( V_79 , V_80 ) ;
if ( V_74 == NULL ) {
F_52 ( L_11 ) ;
goto V_81;
}
V_2 = V_82 ;
V_20 = F_48 ( V_82 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_83 ;
V_2 -> V_77 = V_77 ++ ;
}
F_77 ( V_2 ,
V_79 , V_39 * 0x20 ) ;
}
F_66 ( V_82 ,
V_20 , V_74 ) ;
V_75 = F_80 ( V_84 , V_80 ) ;
if ( V_75 == NULL ) {
F_52 ( L_12 ) ;
goto V_85;
}
V_2 = & V_86 [ 16 ] ;
V_78 = V_75 + 0xC00 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ , V_2 ++ , V_78 += 0x20 )
V_2 -> V_6 = V_78 ;
V_2 = V_86 ;
V_20 = F_48 ( V_86 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_83 ;
V_2 -> V_77 = V_77 ++ ;
}
F_77 ( V_2 ,
V_84 , V_39 * 0x20 ) ;
}
F_66 ( V_86 ,
V_20 , V_75 ) ;
V_76 = F_80 ( V_87 , V_88 ) ;
if ( V_76 == NULL ) {
F_52 ( L_13 ) ;
goto V_89;
}
V_2 = V_90 ;
V_20 = F_48 ( V_90 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_83 ;
V_2 -> V_77 = V_77 ++ ;
}
F_77 ( V_2 ,
V_87 , V_39 * 0x20 ) ;
}
F_66 ( V_90 ,
V_20 , V_76 ) ;
#if F_81 ( F_79 ) && F_81 ( V_91 )
F_82 ( V_92 , 0 , V_93 ) ;
F_82 ( V_94 , V_93 , V_95 ) ;
#endif
return;
V_89:
F_83 ( V_75 ) ;
V_85:
F_83 ( V_74 ) ;
V_81:
return;
#endif
}
static T_4 void F_84 ( void )
{
#ifdef F_85
struct V_1 * V_2 ;
int V_39 , V_20 ;
void T_2 * V_74 , * V_75 , * V_76 , * V_96 ;
int V_77 = 0 ;
void T_2 * V_78 ;
V_74 = F_80 ( V_97 , V_80 ) ;
if ( V_74 == NULL ) {
F_52 ( L_11 ) ;
goto V_81;
}
V_98 [ 20 ] . V_6 = V_74 + 0x2E0 ;
V_2 = & V_98 [ 21 ] ;
V_78 = V_74 + 0xC00 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ , V_2 ++ , V_78 += 0x20 )
V_2 -> V_6 = V_78 ;
V_2 = V_98 ;
V_20 = F_48 ( V_98 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_83 ;
V_2 -> V_77 = V_77 ++ ;
}
F_77 ( V_2 ,
V_97 , V_39 * 0x20 ) ;
}
F_66 ( V_98 ,
V_20 , V_74 ) ;
V_75 = F_80 ( V_99 , V_80 ) ;
if ( V_75 == NULL ) {
F_52 ( L_12 ) ;
goto V_85;
}
V_2 = V_100 ;
V_20 = F_48 ( V_100 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_83 ;
V_2 -> V_77 = V_77 ++ ;
}
F_77 ( V_2 ,
V_99 , V_39 * 0x20 ) ;
}
F_66 ( V_100 ,
V_20 , V_75 ) ;
V_76 = F_80 ( V_101 , V_80 ) ;
if ( V_76 == NULL ) {
F_52 ( L_13 ) ;
goto V_89;
}
V_102 [ 0 ] . V_6 = V_76 ;
V_102 [ 1 ] . V_6 = V_76 + 0x20 ;
V_102 [ 2 ] . V_6 = V_76 + 0x60 ;
V_102 [ 3 ] . V_6 = V_76 + 0x80 ;
V_102 [ 4 ] . V_6 = V_76 + 0xC0 ;
V_2 = V_102 ;
V_20 = F_48 ( V_102 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_83 ;
V_2 -> V_77 = V_77 ++ ;
}
F_77 ( V_2 ,
V_101 , V_39 * 0x20 ) ;
}
F_66 ( V_102 ,
V_20 , V_76 ) ;
V_96 = F_80 ( V_103 , V_80 ) ;
if ( V_96 == NULL ) {
F_52 ( L_14 ) ;
goto V_104;
}
V_2 = V_105 ;
V_20 = F_48 ( V_105 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_83 ;
V_2 -> V_77 = V_77 ++ ;
}
F_77 ( V_2 ,
V_103 , V_39 * 0x20 ) ;
}
F_66 ( V_105 ,
V_20 , V_96 ) ;
return;
V_104:
F_83 ( V_76 ) ;
V_89:
F_83 ( V_75 ) ;
V_85:
F_83 ( V_74 ) ;
V_81:
return;
#endif
}
static T_4 int F_86 ( void )
{
struct V_1 * V_2 ;
int V_39 , V_20 ;
int V_77 = 0 ;
#if F_81 ( V_106 ) || F_81 ( V_107 )
struct V_108 * V_109 ;
static const struct V_110 V_111 [] = {
{ . V_112 = L_15 , } ,
{ . V_112 = L_16 , } ,
{ . V_112 = L_17 , } ,
} ;
F_87 (pctrl_np, exynos_pinctrl_ids)
if ( V_109 && F_88 ( V_109 ) )
return - V_113 ;
#endif
F_25 ( V_66 , F_48 ( V_66 ) ) ;
if ( F_89 () ) {
F_63 ( V_114 ,
F_48 ( V_114 ) , V_115 ) ;
} else if ( F_90 () ) {
F_65 ( V_116 ,
F_48 ( V_116 ) ,
V_117 + 0xE0 , 0x20 ) ;
F_66 ( V_118 ,
F_48 ( V_118 ) ,
V_117 ) ;
F_67 ( V_119 ,
F_48 ( V_119 ) ) ;
} else if ( F_91 () ) {
F_65 ( V_120 ,
F_48 ( V_120 ) , NULL , 0x0 ) ;
F_66 ( V_121 ,
F_48 ( V_121 ) , V_122 ) ;
F_67 ( V_123 ,
F_48 ( V_123 ) ) ;
F_68 ( V_124 ,
F_48 ( V_124 ) ) ;
} else if ( F_92 () ) {
F_65 ( V_125 ,
F_48 ( V_125 ) , NULL , 0x0 ) ;
F_66 ( V_126 ,
F_48 ( V_126 ) , V_122 ) ;
F_67 ( V_127 ,
F_48 ( V_127 ) ) ;
F_68 ( V_128 ,
F_48 ( V_128 ) ) ;
} else if ( F_93 () ) {
V_77 = 0 ;
V_2 = V_129 ;
V_20 = F_48 ( V_129 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_66 [ 3 ] ;
V_2 -> V_77 = V_77 ++ ;
}
}
F_66 ( V_129 , V_20 , V_122 ) ;
#if F_81 ( V_130 ) && F_81 ( V_91 )
F_82 ( V_131 , 0 , V_132 ) ;
#endif
} else if ( F_94 () ) {
V_77 = 0 ;
V_2 = V_133 ;
V_20 = F_48 ( V_133 ) ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
if ( ! V_2 -> V_62 ) {
V_2 -> V_62 = & V_66 [ 3 ] ;
V_2 -> V_77 = V_77 ++ ;
}
}
F_66 ( V_133 , V_20 , V_122 ) ;
#if F_81 ( V_134 ) && F_81 ( V_91 )
F_82 ( V_131 , 0 , V_132 ) ;
#endif
} else if ( F_95 () ) {
F_78 () ;
} else if ( F_96 () ) {
F_84 () ;
} else {
F_97 ( 1 , L_18 ) ;
return - V_113 ;
}
return 0 ;
}
int F_56 ( unsigned int V_54 , unsigned int V_62 )
{
struct V_1 * V_2 = F_98 ( V_54 ) ;
unsigned long V_28 ;
int V_26 ;
int V_42 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_42 = F_99 ( V_2 , V_26 , V_62 ) ;
F_29 ( V_2 , V_28 ) ;
return V_42 ;
}
int F_100 ( unsigned int V_135 , unsigned int V_136 ,
unsigned int V_15 )
{
int V_42 ;
for (; V_136 > 0 ; V_136 -- , V_135 ++ ) {
V_42 = F_56 ( V_135 , V_15 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
int F_101 ( unsigned int V_135 , unsigned int V_136 ,
unsigned int V_15 , T_1 V_4 )
{
int V_42 ;
for (; V_136 > 0 ; V_136 -- , V_135 ++ ) {
F_58 ( V_135 , V_4 ) ;
V_42 = F_56 ( V_135 , V_15 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
unsigned F_102 ( unsigned int V_54 )
{
struct V_1 * V_2 = F_98 ( V_54 ) ;
unsigned long V_28 ;
unsigned V_42 = 0 ;
int V_26 ;
if ( V_2 ) {
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_42 = F_103 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return V_42 ;
}
int F_58 ( unsigned int V_54 , T_1 V_4 )
{
struct V_1 * V_2 = F_98 ( V_54 ) ;
unsigned long V_28 ;
int V_26 , V_42 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_42 = F_104 ( V_2 , V_26 , V_4 ) ;
F_29 ( V_2 , V_28 ) ;
return V_42 ;
}
T_1 F_105 ( unsigned int V_54 )
{
struct V_1 * V_2 = F_98 ( V_54 ) ;
unsigned long V_28 ;
int V_26 ;
T_3 V_8 = 0 ;
if ( V_2 ) {
V_26 = V_54 - V_2 -> V_2 . V_6 ;
F_28 ( V_2 , V_28 ) ;
V_8 = F_106 ( V_2 , V_26 ) ;
F_29 ( V_2 , V_28 ) ;
}
return ( V_9 T_1 ) V_8 ;
}
T_6 F_107 ( unsigned int V_54 )
{
struct V_1 * V_2 = F_98 ( V_54 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_137 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_54 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_137 = F_2 ( V_5 ) ;
V_137 = V_137 >> V_7 ;
V_137 &= 0x3 ;
return ( V_9 T_6 ) V_137 ;
}
int F_76 ( unsigned int V_54 , T_6 V_137 )
{
struct V_1 * V_2 = F_98 ( V_54 ) ;
unsigned int V_3 ;
void T_2 * V_5 ;
int V_7 ;
T_3 V_138 ;
if ( ! V_2 )
return - V_14 ;
V_3 = V_54 - V_2 -> V_2 . V_6 ;
V_7 = V_3 * 2 ;
V_5 = V_2 -> V_6 + 0x0C ;
V_138 = F_2 ( V_5 ) ;
V_138 &= ~ ( 0x3 << V_7 ) ;
V_138 |= V_137 << V_7 ;
F_3 ( V_138 , V_5 ) ;
return 0 ;
}
unsigned int F_108 ( unsigned int V_139 , unsigned int V_140 )
{
unsigned long V_28 ;
unsigned long V_141 ;
F_40 ( V_28 ) ;
V_141 = F_2 ( V_142 ) ;
V_141 &= ~ V_139 ;
V_141 ^= V_140 ;
F_3 ( V_141 , V_142 ) ;
F_41 ( V_28 ) ;
return V_141 ;
}
