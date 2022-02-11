static void F_1 ( unsigned long V_1 )
{
if ( F_2 ( & V_2 . V_3 ) ) {
struct V_4 * V_5 ;
V_5 = V_2 . V_6 ;
if ( V_5 )
F_3 ( V_5 ) ;
}
}
static T_1 F_4 ( struct V_7 * V_8 )
{
unsigned char V_9 , V_10 ;
T_1 V_11 ;
struct V_4 * V_5 ;
struct V_12 * V_13 ;
unsigned long V_14 ;
if ( V_8 -> V_15 ) {
F_5 ( V_8 -> V_16 , 0x61 ) ;
V_8 -> V_15 = 0 ;
return V_8 -> V_17 ;
}
V_5 = V_8 -> V_6 ;
if ( ! V_5 )
return 0 ;
V_13 = V_5 -> V_13 ;
V_10 = V_13 -> V_18 [ V_8 -> V_19 + V_8 -> V_20 - 1 ] ;
if ( V_8 -> V_21 )
V_10 ^= 0x80 ;
V_9 = V_10 * F_6 () / 256 ;
if ( V_9 && V_8 -> V_22 ) {
F_7 ( & V_23 , V_14 ) ;
if ( ! V_24 ) {
F_8 ( V_8 -> V_16 , 0x61 ) ;
F_8 ( V_9 , 0x42 ) ;
F_5 ( V_8 -> V_16 ^ 1 , 0x61 ) ;
} else {
F_5 ( V_8 -> V_16 ^ 2 , 0x61 ) ;
V_8 -> V_15 = 1 ;
}
F_9 ( & V_23 , V_14 ) ;
}
V_8 -> V_17 = F_10 () ;
V_11 = ( V_8 -> V_15 ? F_11 ( V_9 ) : V_8 -> V_17 ) ;
V_8 -> V_17 -= V_11 ;
return V_11 ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_4 * V_5 ;
T_2 V_25 , V_26 ;
int V_27 ;
unsigned long V_14 ;
V_5 = V_8 -> V_6 ;
if ( ! V_5 )
return;
V_25 = F_13 ( V_5 ) ;
V_26 = F_14 ( V_5 ) ;
F_15 ( & V_8 -> V_28 , V_14 ) ;
V_8 -> V_19 += F_16 () * V_8 -> V_20 ;
V_27 = V_8 -> V_19 - V_8 -> V_29 ;
if ( V_27 < 0 ) {
#if V_30
F_17 ( V_31 L_1
L_2 ,
V_8 -> V_19 , V_25 , V_26 ) ;
#endif
V_27 += V_26 ;
}
V_27 /= V_25 ;
V_8 -> V_19 %= V_26 ;
if ( V_27 ) {
V_8 -> V_29 += V_27 * V_25 ;
V_8 -> V_29 %= V_26 ;
}
F_18 ( & V_8 -> V_28 , V_14 ) ;
if ( V_27 )
F_19 ( & V_32 ) ;
}
enum V_33 F_20 ( struct V_34 * V_35 )
{
struct V_7 * V_8 = F_21 ( V_35 , struct V_7 , V_36 ) ;
int V_37 ;
T_1 V_11 ;
if ( ! F_2 ( & V_8 -> V_3 ) || ! V_8 -> V_6 )
return V_38 ;
V_37 = ! V_8 -> V_15 ;
V_11 = F_4 ( V_8 ) ;
if ( ! V_11 ) {
F_17 ( V_39 L_3 ) ;
return V_38 ;
}
if ( V_37 )
F_12 ( V_8 ) ;
F_22 ( V_35 , F_23 ( V_35 ) , F_24 ( V_11 ) ) ;
return V_40 ;
}
static int F_25 ( struct V_7 * V_8 )
{
#if V_30
F_17 ( V_31 L_4 ) ;
#endif
if ( F_2 ( & V_8 -> V_3 ) ) {
F_17 ( V_41 L_5 ) ;
return - V_42 ;
}
F_26 ( & V_23 ) ;
V_8 -> V_16 = F_27 ( 0x61 ) | 0x03 ;
F_8 ( 0x92 , 0x43 ) ;
F_28 ( & V_23 ) ;
F_29 ( & V_8 -> V_3 , 1 ) ;
V_8 -> V_15 = 0 ;
F_30 ( & V_2 . V_36 , F_31 ( 0 , 0 ) , V_43 ) ;
return 0 ;
}
static void F_32 ( struct V_7 * V_8 )
{
#if V_30
F_17 ( V_31 L_6 ) ;
#endif
if ( ! F_2 ( & V_8 -> V_3 ) )
return;
F_29 ( & V_8 -> V_3 , 0 ) ;
F_26 ( & V_23 ) ;
F_8 ( 0xb6 , 0x43 ) ;
F_5 ( V_8 -> V_16 & 0xFC , 0x61 ) ;
F_28 ( & V_23 ) ;
}
void F_33 ( struct V_7 * V_8 )
{
F_34 () ;
F_32 ( V_8 ) ;
F_35 () ;
F_36 ( & V_8 -> V_36 ) ;
F_37 ( & V_32 ) ;
}
static int F_38 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_39 ( V_5 ) ;
#if V_30
F_17 ( V_31 L_7 ) ;
#endif
F_33 ( V_8 ) ;
V_8 -> V_6 = NULL ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 ,
struct V_44 * V_45 )
{
struct V_7 * V_8 = F_39 ( V_5 ) ;
int V_46 ;
F_33 ( V_8 ) ;
V_46 = F_41 ( V_5 ,
F_42 ( V_45 ) ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_39 ( V_5 ) ;
#if V_30
F_17 ( V_31 L_8 ) ;
#endif
F_33 ( V_8 ) ;
return F_44 ( V_5 ) ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_39 ( V_5 ) ;
F_33 ( V_8 ) ;
V_8 -> V_19 = 0 ;
V_8 -> V_29 = 0 ;
V_8 -> V_20 =
F_46 ( V_5 -> V_13 -> V_47 ) >> 3 ;
V_8 -> V_21 = F_47 ( V_5 -> V_13 -> V_47 ) ;
#if V_30
F_17 ( V_31 L_9
L_10 ,
F_14 ( V_5 ) ,
F_13 ( V_5 ) ,
F_14 ( V_5 ) /
F_13 ( V_5 ) ,
V_5 -> V_13 -> V_48 ,
V_8 -> V_20 ) ;
#endif
return 0 ;
}
static int F_48 ( struct V_4 * V_5 , int V_49 )
{
struct V_7 * V_8 = F_39 ( V_5 ) ;
#if V_30
F_17 ( V_31 L_11 ) ;
#endif
switch ( V_49 ) {
case V_50 :
case V_51 :
return F_25 ( V_8 ) ;
case V_52 :
case V_53 :
F_32 ( V_8 ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static T_3 F_49 ( struct V_4
* V_5 )
{
struct V_7 * V_8 = F_39 ( V_5 ) ;
unsigned int V_55 ;
F_50 ( & V_8 -> V_28 ) ;
V_55 = V_8 -> V_19 ;
F_51 ( & V_8 -> V_28 ) ;
return F_52 ( V_5 -> V_13 , V_55 ) ;
}
static int F_53 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_39 ( V_5 ) ;
struct V_12 * V_13 = V_5 -> V_13 ;
#if V_30
F_17 ( V_31 L_12 ) ;
#endif
if ( F_2 ( & V_8 -> V_3 ) ) {
F_17 ( V_41 L_13 ) ;
return - V_56 ;
}
V_13 -> V_57 = V_58 ;
V_8 -> V_6 = V_5 ;
return 0 ;
}
int T_4 F_54 ( struct V_7 * V_8 )
{
int V_46 ;
V_46 = F_55 ( V_8 -> V_59 , L_14 , 0 , 1 , 0 , & V_8 -> V_60 ) ;
if ( V_46 < 0 )
return V_46 ;
F_56 ( V_8 -> V_60 , V_61 ,
& V_62 ) ;
V_8 -> V_60 -> V_63 = V_8 ;
V_8 -> V_60 -> V_64 = V_65 ;
strcpy ( V_8 -> V_60 -> V_66 , L_15 ) ;
F_57 ( V_8 -> V_60 ,
V_67 ,
F_58
( V_68 ) , V_69 ,
V_69 ) ;
return 0 ;
}
