static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , int V_5 )
{
void T_2 * V_6 = V_2 -> V_7 + ( V_5 & ~ 0x3 ) ;
T_1 V_8 = ( V_5 & 0x3 ) * 8 ;
F_2 ( ( ( F_3 ( V_6 ) & ~ ( V_3 << V_8 ) ) | ( V_4 << V_8 ) ) , V_6 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , int V_5 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_4 = F_3 ( V_2 -> V_7 + V_5 ) ;
if ( F_6 ( ( V_5 == V_14 )
&& ( V_12 -> V_15 & V_16 ) ) ) {
struct V_17 * V_18 =
V_2 -> V_19 -> V_20 -> V_21 ;
if ( V_18 && F_7 ( V_18 -> V_22 )
&& F_8 ( V_18 -> V_22 ) )
V_4 &= V_23 ;
else
V_4 |= V_23 ;
}
return V_4 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_4 , int V_5 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( F_6 ( ( V_5 == V_24 || V_5 == V_25 )
&& ( V_12 -> V_15 & V_16 ) ) )
V_4 &= ~ ( V_26 | V_27 ) ;
if ( F_6 ( ( V_12 -> V_15 & V_28 )
&& ( V_5 == V_29 )
&& ( V_4 & V_30 ) ) ) {
T_1 V_31 ;
V_31 = F_3 ( V_2 -> V_7 + V_32 ) ;
V_31 &= ~ V_33 ;
F_2 ( V_31 , V_2 -> V_7 + V_32 ) ;
}
F_2 ( V_4 , V_2 -> V_7 + V_5 ) ;
}
static T_3 F_10 ( struct V_1 * V_2 , int V_5 )
{
if ( F_6 ( V_5 == V_34 ) )
V_5 ^= 2 ;
return F_11 ( V_2 -> V_7 + V_5 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_3 V_4 , int V_5 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
switch ( V_5 ) {
case V_35 :
if ( ( V_12 -> V_15 & V_28 )
&& ( V_2 -> V_36 -> V_37 == V_38 )
&& ( V_2 -> V_36 -> V_39 -> V_40 > 1 )
&& ( V_2 -> V_36 -> V_39 -> V_15 & V_41 ) ) {
T_1 V_31 ;
V_31 = F_3 ( V_2 -> V_7 + V_32 ) ;
V_31 |= V_33 ;
F_2 ( V_31 , V_2 -> V_7 + V_32 ) ;
}
V_12 -> V_42 = V_4 ;
return;
case V_43 :
if ( ( V_2 -> V_36 -> V_37 == V_44 )
&& ( V_12 -> V_15 & V_28 ) )
V_4 |= V_45 ;
F_2 ( V_4 << 16 | V_12 -> V_42 ,
V_2 -> V_7 + V_35 ) ;
return;
case V_46 :
V_4 &= ~ F_13 ( 0x7 , 0 ) ;
break;
}
F_1 ( V_2 , 0xffff , V_4 , V_5 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_4 V_4 , int V_5 )
{
T_1 V_47 ;
switch ( V_5 ) {
case V_48 :
return;
case V_49 :
V_47 = V_4 & ( V_50 | V_51 ) ;
V_47 |= V_52 ;
V_47 |= ( V_4 & V_53 ) << 5 ;
F_1 ( V_2 , 0xffff , V_47 , V_5 ) ;
return;
}
F_1 ( V_2 , 0xff , V_4 , V_5 ) ;
}
static unsigned int F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
return F_16 ( V_10 -> V_54 ) ;
}
static unsigned int F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
return F_16 ( V_10 -> V_54 ) / 256 / 16 ;
}
static unsigned int F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 -> V_20 -> V_21 ;
if ( V_18 && F_7 ( V_18 -> V_55 ) )
return F_8 ( V_18 -> V_55 ) ;
else
return - V_56 ;
}
static T_5 F_19 ( int V_57 , void * V_39 )
{
struct V_1 * V_58 = (struct V_1 * ) V_39 ;
F_20 ( & V_58 -> V_59 ) ;
return V_60 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_61 * V_62 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_19 -> V_20 -> V_21 ;
struct V_54 * V_54 ;
int V_63 ;
struct V_11 * V_12 ;
V_54 = F_22 ( F_23 ( V_2 -> V_19 ) , NULL ) ;
if ( F_24 ( V_54 ) ) {
F_25 ( F_23 ( V_2 -> V_19 ) , L_1 ) ;
return F_26 ( V_54 ) ;
}
F_27 ( V_54 ) ;
V_10 -> V_54 = V_54 ;
V_12 = F_28 ( sizeof( struct V_11 ) , V_64 ) ;
if ( ! V_12 ) {
F_29 ( V_10 -> V_54 ) ;
F_30 ( V_10 -> V_54 ) ;
return - V_65 ;
}
V_10 -> V_13 = V_12 ;
if ( ! F_31 () )
V_2 -> V_66 |= V_67 ;
if ( F_31 () || F_32 () ) {
V_2 -> V_66 |= V_68 ;
V_69 . V_70 = F_18 ;
}
if ( ! ( F_31 () || F_32 () || F_33 () ) )
V_12 -> V_15 |= V_28 ;
if ( V_18 ) {
V_63 = F_34 ( V_18 -> V_55 , V_71 , L_2 ) ;
if ( V_63 ) {
F_35 ( F_23 ( V_2 -> V_19 ) ,
L_3 ) ;
V_18 -> V_55 = V_63 ;
}
V_63 = F_34 ( V_18 -> V_22 , V_71 , L_4 ) ;
if ( V_63 ) {
F_35 ( F_23 ( V_2 -> V_19 ) ,
L_5 ) ;
goto V_72;
}
if ( ! F_31 () && ! F_32 () )
goto V_73;
V_63 = F_36 ( F_37 ( V_18 -> V_22 ) , F_19 ,
V_74 | V_75 ,
F_38 ( V_2 -> V_19 ) , V_2 ) ;
if ( V_63 ) {
F_35 ( F_23 ( V_2 -> V_19 ) , L_6 ) ;
goto V_76;
}
V_12 -> V_15 |= V_16 ;
V_2 -> V_66 &= ~ V_77 ;
}
return 0 ;
V_76:
F_39 ( V_18 -> V_22 ) ;
V_72:
V_18 -> V_22 = V_63 ;
V_73:
F_40 ( V_12 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_19 -> V_20 -> V_21 ;
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_18 && F_7 ( V_18 -> V_55 ) )
F_39 ( V_18 -> V_55 ) ;
if ( V_18 && F_7 ( V_18 -> V_22 ) ) {
F_39 ( V_18 -> V_22 ) ;
if ( ! ( V_2 -> V_66 & V_77 ) )
F_42 ( F_37 ( V_18 -> V_22 ) , V_2 ) ;
}
F_29 ( V_10 -> V_54 ) ;
F_30 ( V_10 -> V_54 ) ;
F_40 ( V_12 ) ;
}
