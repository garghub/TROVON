static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 , T_1 V_6 )
{
T_2 V_7 ;
V_7 = F_4 ( V_5 -> V_8 + F_5 ( V_6 ) ) ;
F_6 ( V_7 & ~ V_9 , V_5 -> V_8 +
F_5 ( V_6 ) ) ;
}
static void F_7 ( struct V_1 * V_5 ,
unsigned long V_10 , T_1 V_6 )
{
F_6 ( V_10 , V_5 -> V_8 + F_8 ( V_6 ) ) ;
}
static void F_9 ( struct V_1 * V_5 ,
bool V_11 , T_1 V_6 )
{
T_2 V_7 ;
F_6 ( F_10 ( V_6 ) , V_5 -> V_8 + V_12 ) ;
V_7 = F_4 ( V_5 -> V_8 + F_5 ( V_6 ) ) ;
V_7 &= ~ F_11 ( 0x3 ) ;
if ( V_11 )
V_7 |= F_11 ( V_13 ) ;
else
V_7 |= F_11 ( V_14 ) ;
F_6 ( V_7 | V_9 | V_15 ,
V_5 -> V_8 + F_5 ( V_6 ) ) ;
}
static void F_12 ( enum V_16 V_17 ,
struct V_2 * V_18 )
{
struct V_1 * V_5 = F_1 ( V_18 ) ;
F_3 ( V_5 , V_19 ) ;
switch ( V_17 ) {
case V_20 :
F_7 ( V_5 , V_5 -> V_21 , V_19 ) ;
F_9 ( V_5 , true , V_19 ) ;
break;
case V_22 :
break;
case V_23 :
case V_24 :
default:
break;
}
}
static int F_13 ( unsigned long V_25 ,
struct V_2 * V_18 )
{
struct V_1 * V_5 = F_1 ( V_18 ) ;
F_3 ( V_5 , V_19 ) ;
F_7 ( V_5 , V_25 , V_19 ) ;
F_9 ( V_5 , false , V_19 ) ;
return 0 ;
}
static T_3 F_14 ( int V_26 , void * V_27 )
{
struct V_1 * V_5 = V_27 ;
F_6 ( F_10 ( V_19 ) , V_5 -> V_8 + V_12 ) ;
V_5 -> V_4 . V_28 ( & V_5 -> V_4 ) ;
return V_29 ;
}
static void F_15 ( struct V_1 * V_5 )
{
F_6 ( 0x0 , V_5 -> V_8 + V_30 ) ;
F_6 ( 0x3f , V_5 -> V_8 + V_12 ) ;
}
static void
F_16 ( struct V_1 * V_5 , T_1 V_6 , T_1 V_31 )
{
F_6 ( V_15 | V_32 ,
V_5 -> V_8 + F_5 ( V_6 ) ) ;
F_6 ( F_17 ( V_33 ) | V_34 ,
V_5 -> V_8 + F_18 ( V_6 ) ) ;
F_6 ( 0x0 , V_5 -> V_8 + F_8 ( V_6 ) ) ;
F_6 ( F_11 ( V_31 ) | V_9 ,
V_5 -> V_8 + F_5 ( V_6 ) ) ;
}
static void F_19 ( struct V_1 * V_5 , T_1 V_6 )
{
T_2 V_7 ;
V_7 = F_4 ( V_5 -> V_8 + V_30 ) ;
F_6 ( V_7 | F_20 ( V_6 ) ,
V_5 -> V_8 + V_30 ) ;
}
static void T_4 F_21 ( struct V_35 * V_36 )
{
struct V_1 * V_5 ;
struct V_37 V_38 ;
unsigned long V_39 = 0 ;
struct V_18 * V_18 ;
V_5 = F_22 ( sizeof( * V_5 ) , V_40 ) ;
if ( ! V_5 ) {
F_23 ( L_1 ) ;
return;
}
V_5 -> V_4 . V_41 = L_2 ;
V_5 -> V_4 . V_42 = 300 ;
V_5 -> V_4 . V_43 = V_44 | V_45 ;
V_5 -> V_4 . V_46 = F_12 ;
V_5 -> V_4 . V_47 = F_13 ;
V_5 -> V_4 . V_48 = V_49 ;
V_5 -> V_8 = F_24 ( V_36 , 0 , L_3 ) ;
if ( F_25 ( V_5 -> V_8 ) ) {
F_23 ( L_4 ) ;
return;
}
V_5 -> V_4 . V_26 = F_26 ( V_36 , 0 ) ;
if ( V_5 -> V_4 . V_26 <= 0 ) {
F_23 ( L_5 ) ;
goto V_50;
}
V_18 = F_27 ( V_36 , 0 ) ;
if ( F_25 ( V_18 ) ) {
F_23 ( L_6 ) ;
goto V_51;
}
if ( F_28 ( V_18 ) ) {
F_23 ( L_7 ) ;
goto V_52;
}
V_39 = F_29 ( V_18 ) ;
F_15 ( V_5 ) ;
if ( F_30 ( V_5 -> V_4 . V_26 , F_14 ,
V_53 | V_54 , L_8 , V_5 ) ) {
F_23 ( L_9 , V_5 -> V_4 . V_26 ) ;
goto V_55;
}
V_5 -> V_21 = F_31 ( V_39 , V_56 ) ;
F_16 ( V_5 , V_57 , V_58 ) ;
F_32 ( V_5 -> V_8 + F_33 ( V_57 ) ,
V_36 -> V_41 , V_39 , 300 , 32 , V_59 ) ;
F_16 ( V_5 , V_19 , V_13 ) ;
F_34 ( & V_5 -> V_4 , V_39 , 0x3 ,
0xffffffff ) ;
F_19 ( V_5 , V_19 ) ;
return;
V_55:
F_35 ( V_18 ) ;
V_52:
F_36 ( V_18 ) ;
V_51:
F_37 ( V_5 -> V_4 . V_26 ) ;
V_50:
F_38 ( V_5 -> V_8 ) ;
F_39 ( V_36 , 0 , & V_38 ) ;
F_40 ( V_38 . V_60 , F_41 ( & V_38 ) ) ;
}
