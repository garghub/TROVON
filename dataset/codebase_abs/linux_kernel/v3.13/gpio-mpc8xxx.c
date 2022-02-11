static inline T_1 F_1 ( unsigned int V_1 )
{
return 1u << ( V_2 - 1 - V_1 ) ;
}
static inline struct V_3 *
F_2 ( struct V_4 * V_5 )
{
return F_3 ( V_5 , struct V_3 , V_6 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_3 * V_7 = F_2 ( V_5 ) ;
V_7 -> V_8 = F_5 ( V_5 -> V_9 + V_10 ) ;
}
static int F_6 ( struct V_11 * V_12 , unsigned int V_1 )
{
T_1 V_13 ;
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
T_1 V_14 , V_15 ;
V_14 = F_5 ( V_5 -> V_9 + V_16 ) ;
V_13 = F_5 ( V_5 -> V_9 + V_10 ) & ~ V_14 ;
V_15 = V_7 -> V_8 & V_14 ;
return ( V_13 | V_15 ) & F_1 ( V_1 ) ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_1 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
return F_5 ( V_5 -> V_9 + V_10 ) & F_1 ( V_1 ) ;
}
static void F_9 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_17 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
if ( V_13 )
V_7 -> V_8 |= F_1 ( V_1 ) ;
else
V_7 -> V_8 &= ~ F_1 ( V_1 ) ;
F_11 ( V_5 -> V_9 + V_10 , V_7 -> V_8 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
}
static int F_13 ( struct V_11 * V_12 , unsigned int V_1 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_17 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_14 ( V_5 -> V_9 + V_16 , F_1 ( V_1 ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_17 ;
F_9 ( V_12 , V_1 , V_13 ) ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_16 ( V_5 -> V_9 + V_16 , F_1 ( V_1 ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
if ( V_1 >= 28 )
return - V_19 ;
return F_15 ( V_12 , V_1 , V_13 ) ;
}
static int F_18 ( struct V_11 * V_12 , unsigned V_20 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
if ( V_7 -> V_21 && V_20 < V_2 )
return F_19 ( V_7 -> V_21 , V_20 ) ;
else
return - V_22 ;
}
static void F_20 ( unsigned int V_21 , struct V_23 * V_24 )
{
struct V_3 * V_7 = F_21 ( V_24 ) ;
struct V_25 * V_26 = F_22 ( V_24 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned int V_27 ;
V_27 = F_5 ( V_5 -> V_9 + V_28 ) & F_5 ( V_5 -> V_9 + V_29 ) ;
if ( V_27 )
F_23 ( F_24 ( V_7 -> V_21 ,
32 - F_25 ( V_27 ) ) ) ;
if ( V_26 -> V_30 )
V_26 -> V_30 ( & V_24 -> V_31 ) ;
}
static void F_26 ( struct V_31 * V_32 )
{
struct V_3 * V_7 = F_27 ( V_32 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_17 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_16 ( V_5 -> V_9 + V_29 , F_1 ( F_28 ( V_32 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
}
static void F_29 ( struct V_31 * V_32 )
{
struct V_3 * V_7 = F_27 ( V_32 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_17 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_14 ( V_5 -> V_9 + V_29 , F_1 ( F_28 ( V_32 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
}
static void F_30 ( struct V_31 * V_32 )
{
struct V_3 * V_7 = F_27 ( V_32 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
F_11 ( V_5 -> V_9 + V_28 , F_1 ( F_28 ( V_32 ) ) ) ;
}
static int F_31 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_3 * V_7 = F_27 ( V_32 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_17 ;
switch ( V_33 ) {
case V_34 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_16 ( V_5 -> V_9 + V_35 ,
F_1 ( F_28 ( V_32 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
case V_36 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_14 ( V_5 -> V_9 + V_35 ,
F_1 ( F_28 ( V_32 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_32 ( struct V_31 * V_32 , unsigned int V_33 )
{
struct V_3 * V_7 = F_27 ( V_32 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_1 = F_28 ( V_32 ) ;
void T_2 * V_37 ;
unsigned int V_38 ;
unsigned long V_17 ;
if ( V_1 < 16 ) {
V_37 = V_5 -> V_9 + V_35 ;
V_38 = ( 15 - V_1 ) * 2 ;
} else {
V_37 = V_5 -> V_9 + V_39 ;
V_38 = ( 15 - ( V_1 % 16 ) ) * 2 ;
}
switch ( V_33 ) {
case V_34 :
case V_40 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_33 ( V_37 , 3 << V_38 , 2 << V_38 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
case V_41 :
case V_42 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_33 ( V_37 , 3 << V_38 , 1 << V_38 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
case V_36 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_14 ( V_37 , 3 << V_38 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_34 ( struct V_43 * V_44 , unsigned int V_21 ,
T_3 V_45 )
{
struct V_3 * V_7 = V_44 -> V_46 ;
if ( V_7 -> V_47 )
V_48 . V_49 = V_7 -> V_47 ;
F_35 ( V_21 , V_44 -> V_46 ) ;
F_36 ( V_21 , & V_48 , V_50 ) ;
return 0 ;
}
static void T_4 F_37 ( struct V_51 * V_52 )
{
struct V_3 * V_7 ;
struct V_4 * V_6 ;
struct V_11 * V_12 ;
const struct V_53 * V_54 ;
unsigned V_45 ;
int V_55 ;
V_7 = F_38 ( sizeof( * V_7 ) , V_56 ) ;
if ( ! V_7 ) {
V_55 = - V_57 ;
goto V_58;
}
F_39 ( & V_7 -> V_18 ) ;
V_6 = & V_7 -> V_6 ;
V_12 = & V_6 -> V_12 ;
V_6 -> V_59 = F_4 ;
V_12 -> V_60 = V_2 ;
V_12 -> V_61 = F_13 ;
V_12 -> V_62 = F_40 ( V_52 , L_1 ) ?
F_17 : F_15 ;
V_12 -> V_63 = F_40 ( V_52 , L_2 ) ?
F_6 : F_8 ;
V_12 -> V_64 = F_9 ;
V_12 -> V_65 = F_18 ;
V_55 = F_41 ( V_52 , V_6 ) ;
if ( V_55 )
goto V_58;
V_45 = F_42 ( V_52 , 0 ) ;
if ( V_45 == V_66 )
goto V_67;
V_7 -> V_21 = F_43 ( V_52 , V_2 ,
& V_68 , V_7 ) ;
if ( ! V_7 -> V_21 )
goto V_67;
V_54 = F_44 ( V_69 , V_52 ) ;
if ( V_54 )
V_7 -> V_47 = V_54 -> V_8 ;
F_11 ( V_6 -> V_9 + V_28 , 0xffffffff ) ;
F_11 ( V_6 -> V_9 + V_29 , 0 ) ;
F_45 ( V_45 , V_7 ) ;
F_46 ( V_45 , F_20 ) ;
V_67:
return;
V_58:
F_47 ( L_3 ,
V_52 -> V_70 , V_55 ) ;
F_48 ( V_7 ) ;
return;
}
static int T_4 F_49 ( void )
{
struct V_51 * V_52 ;
F_50 (np, mpc8xxx_gpio_ids)
F_37 ( V_52 ) ;
return 0 ;
}
