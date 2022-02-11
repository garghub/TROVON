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
unsigned int V_3 , unsigned int V_15 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = V_3 * 2 ;
T_3 V_16 ;
if ( F_14 ( V_15 ) ) {
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
static unsigned int F_15 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_3 V_16 ;
V_16 = F_2 ( V_2 -> V_6 ) ;
V_16 >>= V_3 * 2 ;
V_16 &= 3 ;
return F_16 ( V_16 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_15 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = ( V_3 & 7 ) * 4 ;
T_3 V_16 ;
if ( V_3 < 8 && V_2 -> V_2 . V_17 > 8 )
V_5 -= 4 ;
if ( F_14 ( V_15 ) ) {
V_15 &= 0xf ;
V_15 <<= V_7 ;
}
V_16 = F_2 ( V_5 ) ;
V_16 &= ~ ( 0xf << V_7 ) ;
V_16 |= V_15 ;
F_3 ( V_16 , V_5 ) ;
return 0 ;
}
static unsigned F_18 ( struct V_1 * V_2 ,
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
return F_16 ( V_16 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_15 )
{
void T_2 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = V_3 ;
T_3 V_16 ;
if ( F_14 ( V_15 ) ) {
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
static unsigned F_20 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_3 V_16 ;
V_16 = F_2 ( V_2 -> V_6 ) ;
V_16 >>= V_3 ;
V_16 &= 1 ;
V_16 ++ ;
return F_21 ( V_16 ) ;
}
static void T_4 F_22 ( struct V_18 * V_19 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_19 ++ ) {
if ( ! V_19 -> V_21 )
V_19 -> V_21 = F_17 ;
if ( ! V_19 -> V_22 )
V_19 -> V_22 = F_18 ;
if ( ! V_19 -> V_23 )
V_19 -> V_23 = F_1 ;
if ( ! V_19 -> V_24 )
V_19 -> V_24 = F_4 ;
}
}
static int F_23 ( struct V_25 * V_2 , unsigned V_26 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_16 ;
F_25 ( V_27 , V_28 ) ;
V_16 = F_2 ( V_6 + 0x00 ) ;
V_16 &= ~ ( 3 << ( V_26 * 2 ) ) ;
F_3 ( V_16 , V_6 + 0x00 ) ;
F_26 ( V_27 , V_28 ) ;
return 0 ;
}
static int F_27 ( struct V_25 * V_2 ,
unsigned V_26 , int V_29 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_30 ;
unsigned long V_16 ;
F_25 ( V_27 , V_28 ) ;
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
F_26 ( V_27 , V_28 ) ;
return 0 ;
}
static int F_28 ( struct V_25 * V_2 ,
unsigned int V_26 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_16 ;
V_16 = F_2 ( V_6 + V_31 ) ;
if ( V_27 -> V_32 & F_29 ( V_26 ) )
V_16 |= 0xf << F_30 ( V_26 ) ;
else
V_16 &= ~ ( 0xf << F_30 ( V_26 ) ) ;
F_3 ( V_16 , V_6 + V_31 ) ;
F_31 ( L_1 , V_33 , V_6 , V_16 ) ;
return 0 ;
}
static int F_32 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_16 ;
unsigned long V_30 ;
V_16 = F_2 ( V_6 + V_31 ) ;
V_16 &= ~ ( 0xf << F_30 ( V_26 ) ) ;
V_16 |= 0x1 << F_30 ( V_26 ) ;
V_30 = F_2 ( V_6 + V_34 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_3 ( V_16 , V_6 + V_31 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_31 ( L_2 , V_33 , V_6 , V_16 , V_30 ) ;
return 0 ;
}
static int F_33 ( struct V_25 * V_2 ,
unsigned int V_26 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
void T_2 * V_35 = V_6 ;
unsigned long V_16 ;
if ( V_26 > 7 )
V_26 -= 8 ;
else
V_35 -= 4 ;
V_16 = F_2 ( V_35 ) ;
V_16 &= ~ ( 0xf << F_30 ( V_26 ) ) ;
F_3 ( V_16 , V_35 ) ;
F_31 ( L_3 , V_33 , V_6 , V_16 ) ;
return 0 ;
}
static int F_34 ( struct V_25 * V_2 ,
unsigned int V_26 , int V_29 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
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
V_16 &= ~ ( 0xf << F_30 ( V_36 ) ) ;
V_16 |= 0x1 << F_30 ( V_36 ) ;
V_30 = F_2 ( V_6 + V_34 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
else
V_30 &= ~ ( 1 << V_26 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_3 ( V_16 , V_35 ) ;
F_3 ( V_30 , V_6 + V_34 ) ;
F_31 ( L_2 , V_33 , V_6 , V_16 , V_30 ) ;
return 0 ;
}
static int F_35 ( struct V_25 * V_2 , unsigned V_26 )
{
return - V_14 ;
}
static int F_36 ( struct V_25 * V_2 ,
unsigned V_26 , int V_29 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_30 ;
unsigned long V_16 ;
F_37 ( V_28 ) ;
V_16 = F_2 ( V_6 + 0x00 ) ;
V_30 = F_2 ( V_6 + 0x04 ) ;
V_30 &= ~ ( 1 << V_26 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
F_3 ( V_30 , V_6 + 0x04 ) ;
V_16 &= ~ ( 1 << V_26 ) ;
F_3 ( V_16 , V_6 + 0x00 ) ;
F_3 ( V_30 , V_6 + 0x04 ) ;
F_38 ( V_28 ) ;
return 0 ;
}
static void F_39 ( struct V_25 * V_2 ,
unsigned V_26 , int V_29 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
void T_2 * V_6 = V_27 -> V_6 ;
unsigned long V_28 ;
unsigned long V_30 ;
F_25 ( V_27 , V_28 ) ;
V_30 = F_2 ( V_6 + 0x04 ) ;
V_30 &= ~ ( 1 << V_26 ) ;
if ( V_29 )
V_30 |= 1 << V_26 ;
F_3 ( V_30 , V_6 + 0x04 ) ;
F_26 ( V_27 , V_28 ) ;
}
static int F_40 ( struct V_25 * V_2 , unsigned V_26 )
{
struct V_1 * V_27 = F_24 ( V_2 ) ;
unsigned long V_37 ;
V_37 = F_2 ( V_27 -> V_6 + 0x04 ) ;
V_37 >>= V_26 ;
V_37 &= 1 ;
return V_37 ;
}
static T_4 void F_41 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
int V_39 ;
V_38 = V_2 -> V_2 . V_6 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_2 . V_17 ; V_39 ++ , V_38 ++ ) {
F_42 ( V_38 >= F_43 ( V_40 ) ) ;
V_40 [ V_38 ] = V_2 ;
}
}
static void T_4 F_44 ( struct V_1 * V_2 )
{
struct V_25 * V_41 = & V_2 -> V_2 ;
int V_42 ;
F_42 ( ! V_2 -> V_6 ) ;
F_42 ( ! V_41 -> V_43 ) ;
F_42 ( ! V_41 -> V_17 ) ;
F_45 ( & V_2 -> V_44 ) ;
if ( ! V_41 -> V_45 )
V_41 -> V_45 = F_23 ;
if ( ! V_41 -> V_46 )
V_41 -> V_46 = F_27 ;
if ( ! V_41 -> V_47 )
V_41 -> V_47 = F_39 ;
if ( ! V_41 -> V_48 )
V_41 -> V_48 = F_40 ;
#ifdef F_46
if ( V_2 -> V_49 != NULL ) {
if ( ! V_2 -> V_49 -> V_50 || ! V_2 -> V_49 -> V_51 )
F_47 ( L_4 ,
V_41 -> V_43 ) ;
} else
F_47 ( L_5 , V_41 -> V_43 ) ;
#endif
V_42 = F_48 ( V_41 ) ;
if ( V_42 >= 0 )
F_41 ( V_2 ) ;
}
static void T_4 F_49 ( struct V_1 * V_2 ,
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
V_2 -> V_49 = F_50 ( & V_55 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * 0x10 ) ;
if ( ! V_41 -> V_45 )
V_41 -> V_45 = F_23 ;
if ( ! V_41 -> V_46 )
V_41 -> V_46 = F_27 ;
F_44 ( V_2 ) ;
}
}
static void T_4 F_51 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 ,
unsigned int V_26 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_23 ;
V_2 -> V_2 . V_46 = F_27 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 7 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_50 ( & V_55 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * V_26 ) ;
F_44 ( V_2 ) ;
}
}
static void T_4 F_52 ( struct V_1 * V_2 ,
int V_20 , void T_2 * V_6 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_20 ; V_39 ++ , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_28 ;
V_2 -> V_2 . V_46 = F_32 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 2 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_50 ( & V_57 ) ;
if ( ( V_6 != NULL ) && ( V_2 -> V_6 == NULL ) )
V_2 -> V_6 = V_6 + ( ( V_39 ) * 0x20 ) ;
V_2 -> V_32 = 0 ;
F_44 ( V_2 ) ;
}
}
static void T_4 F_53 ( struct V_1 * V_2 ,
int V_20 )
{
for (; V_20 > 0 ; V_20 -- , V_2 ++ ) {
V_2 -> V_2 . V_45 = F_33 ;
V_2 -> V_2 . V_46 = F_34 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = & V_56 [ 2 ] ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = F_50 ( & V_57 ) ;
F_44 ( V_2 ) ;
}
}
int F_54 ( struct V_25 * V_2 , unsigned int V_26 )
{
struct V_1 * V_58 = F_55 ( V_2 , struct V_1 , V_2 ) ;
return V_58 -> V_59 + V_26 ;
}
static int F_56 ( struct V_25 * V_2 , unsigned V_26 )
{
if ( V_26 < 4 ) {
if ( F_57 () )
return V_60 + V_26 ;
else
return V_61 + V_26 ;
}
if ( V_26 < 8 )
return V_62 + V_26 - 4 ;
return - V_14 ;
}
static int F_58 ( struct V_25 * V_2 , unsigned V_63 )
{
return V_63 < 5 ? F_59 ( 23 ) + V_63 : - V_64 ;
}
static int F_60 ( struct V_25 * V_2 , unsigned V_63 )
{
return V_63 >= 8 ? F_59 ( 16 ) + V_63 - 8 : - V_64 ;
}
static T_4 int F_61 ( void )
{
if ( F_62 () )
return - V_65 ;
F_22 ( V_56 , F_43 ( V_56 ) ) ;
if ( F_63 () ) {
F_49 ( V_66 ,
F_43 ( V_66 ) , V_67 ) ;
} else if ( F_64 () ) {
F_51 ( V_68 ,
F_43 ( V_68 ) ,
V_69 + 0xE0 , 0x20 ) ;
F_52 ( V_70 ,
F_43 ( V_70 ) ,
V_69 ) ;
F_53 ( V_71 ,
F_43 ( V_71 ) ) ;
} else {
F_65 ( 1 , L_6 ) ;
return - V_65 ;
}
return 0 ;
}
int F_66 ( unsigned int V_63 , unsigned int V_53 )
{
struct V_1 * V_2 = F_67 ( V_63 ) ;
unsigned long V_28 ;
int V_26 ;
int V_42 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_25 ( V_2 , V_28 ) ;
V_42 = F_68 ( V_2 , V_26 , V_53 ) ;
F_26 ( V_2 , V_28 ) ;
return V_42 ;
}
int F_69 ( unsigned int V_72 , unsigned int V_73 ,
unsigned int V_15 )
{
int V_42 ;
for (; V_73 > 0 ; V_73 -- , V_72 ++ ) {
V_42 = F_66 ( V_72 , V_15 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
int F_70 ( unsigned int V_72 , unsigned int V_73 ,
unsigned int V_15 , T_1 V_4 )
{
int V_42 ;
for (; V_73 > 0 ; V_73 -- , V_72 ++ ) {
F_71 ( V_72 , V_4 ) ;
V_42 = F_66 ( V_72 , V_15 ) ;
if ( V_42 != 0 )
return V_42 ;
}
return 0 ;
}
unsigned F_72 ( unsigned int V_63 )
{
struct V_1 * V_2 = F_67 ( V_63 ) ;
unsigned long V_28 ;
unsigned V_42 = 0 ;
int V_26 ;
if ( V_2 ) {
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_25 ( V_2 , V_28 ) ;
V_42 = F_73 ( V_2 , V_26 ) ;
F_26 ( V_2 , V_28 ) ;
}
return V_42 ;
}
int F_71 ( unsigned int V_63 , T_1 V_4 )
{
struct V_1 * V_2 = F_67 ( V_63 ) ;
unsigned long V_28 ;
int V_26 , V_42 ;
if ( ! V_2 )
return - V_14 ;
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_25 ( V_2 , V_28 ) ;
V_42 = F_74 ( V_2 , V_26 , V_4 ) ;
F_26 ( V_2 , V_28 ) ;
return V_42 ;
}
T_1 F_75 ( unsigned int V_63 )
{
struct V_1 * V_2 = F_67 ( V_63 ) ;
unsigned long V_28 ;
int V_26 ;
T_3 V_8 = 0 ;
if ( V_2 ) {
V_26 = V_63 - V_2 -> V_2 . V_6 ;
F_25 ( V_2 , V_28 ) ;
V_8 = F_76 ( V_2 , V_26 ) ;
F_26 ( V_2 , V_28 ) ;
}
return ( V_9 T_1 ) V_8 ;
}
unsigned int F_77 ( unsigned int V_74 , unsigned int V_75 )
{
unsigned long V_28 ;
unsigned long V_76 ;
F_37 ( V_28 ) ;
V_76 = F_2 ( V_77 ) ;
V_76 &= ~ V_74 ;
V_76 ^= V_75 ;
F_3 ( V_76 , V_77 ) ;
F_38 ( V_28 ) ;
return V_76 ;
}
