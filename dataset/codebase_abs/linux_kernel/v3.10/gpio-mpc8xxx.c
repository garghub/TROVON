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
V_13 = F_5 ( V_5 -> V_9 + V_10 ) & ~ F_5 ( V_5 -> V_9 + V_14 ) ;
return ( V_13 | V_7 -> V_8 ) & F_1 ( V_1 ) ;
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
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
if ( V_13 )
V_7 -> V_8 |= F_1 ( V_1 ) ;
else
V_7 -> V_8 &= ~ F_1 ( V_1 ) ;
F_11 ( V_5 -> V_9 + V_10 , V_7 -> V_8 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static int F_13 ( struct V_11 * V_12 , unsigned int V_1 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_14 ( V_5 -> V_9 + V_14 , F_1 ( V_1 ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_15 ;
F_9 ( V_12 , V_1 , V_13 ) ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_16 ( V_5 -> V_9 + V_14 , F_1 ( V_1 ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_17 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
if ( V_1 >= 28 )
return - V_17 ;
return F_15 ( V_12 , V_1 , V_13 ) ;
}
static int F_18 ( struct V_11 * V_12 , unsigned V_18 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
if ( V_7 -> V_19 && V_18 < V_2 )
return F_19 ( V_7 -> V_19 , V_18 ) ;
else
return - V_20 ;
}
static void F_20 ( unsigned int V_19 , struct V_21 * V_22 )
{
struct V_3 * V_7 = F_21 ( V_22 ) ;
struct V_23 * V_24 = F_22 ( V_22 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned int V_25 ;
V_25 = F_5 ( V_5 -> V_9 + V_26 ) & F_5 ( V_5 -> V_9 + V_27 ) ;
if ( V_25 )
F_23 ( F_24 ( V_7 -> V_19 ,
32 - F_25 ( V_25 ) ) ) ;
if ( V_24 -> V_28 )
V_24 -> V_28 ( & V_22 -> V_29 ) ;
}
static void F_26 ( struct V_29 * V_30 )
{
struct V_3 * V_7 = F_27 ( V_30 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_16 ( V_5 -> V_9 + V_27 , F_1 ( F_28 ( V_30 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static void F_29 ( struct V_29 * V_30 )
{
struct V_3 * V_7 = F_27 ( V_30 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_14 ( V_5 -> V_9 + V_27 , F_1 ( F_28 ( V_30 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static void F_30 ( struct V_29 * V_30 )
{
struct V_3 * V_7 = F_27 ( V_30 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
F_11 ( V_5 -> V_9 + V_26 , F_1 ( F_28 ( V_30 ) ) ) ;
}
static int F_31 ( struct V_29 * V_30 , unsigned int V_31 )
{
struct V_3 * V_7 = F_27 ( V_30 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_15 ;
switch ( V_31 ) {
case V_32 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_16 ( V_5 -> V_9 + V_33 ,
F_1 ( F_28 ( V_30 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
case V_34 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_14 ( V_5 -> V_9 + V_33 ,
F_1 ( F_28 ( V_30 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_32 ( struct V_29 * V_30 , unsigned int V_31 )
{
struct V_3 * V_7 = F_27 ( V_30 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_1 = F_28 ( V_30 ) ;
void T_2 * V_35 ;
unsigned int V_36 ;
unsigned long V_15 ;
if ( V_1 < 16 ) {
V_35 = V_5 -> V_9 + V_33 ;
V_36 = ( 15 - V_1 ) * 2 ;
} else {
V_35 = V_5 -> V_9 + V_37 ;
V_36 = ( 15 - ( V_1 % 16 ) ) * 2 ;
}
switch ( V_31 ) {
case V_32 :
case V_38 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_33 ( V_35 , 3 << V_36 , 2 << V_36 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
case V_39 :
case V_40 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_33 ( V_35 , 3 << V_36 , 1 << V_36 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
case V_34 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_14 ( V_35 , 3 << V_36 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_34 ( struct V_41 * V_42 , unsigned int V_43 ,
T_3 V_44 )
{
struct V_3 * V_7 = V_42 -> V_45 ;
if ( V_7 -> V_46 )
V_47 . V_48 = V_7 -> V_46 ;
F_35 ( V_43 , V_42 -> V_45 ) ;
F_36 ( V_43 , & V_47 , V_49 ) ;
return 0 ;
}
static void T_4 F_37 ( struct V_50 * V_51 )
{
struct V_3 * V_7 ;
struct V_4 * V_6 ;
struct V_11 * V_12 ;
const struct V_52 * V_53 ;
unsigned V_54 ;
int V_55 ;
V_7 = F_38 ( sizeof( * V_7 ) , V_56 ) ;
if ( ! V_7 ) {
V_55 = - V_57 ;
goto V_58;
}
F_39 ( & V_7 -> V_16 ) ;
V_6 = & V_7 -> V_6 ;
V_12 = & V_6 -> V_12 ;
V_6 -> V_59 = F_4 ;
V_12 -> V_60 = V_2 ;
V_12 -> V_61 = F_13 ;
V_12 -> V_62 = F_40 ( V_51 , L_1 ) ?
F_17 : F_15 ;
V_12 -> V_63 = F_40 ( V_51 , L_2 ) ?
F_6 : F_8 ;
V_12 -> V_64 = F_9 ;
V_12 -> V_65 = F_18 ;
V_55 = F_41 ( V_51 , V_6 ) ;
if ( V_55 )
goto V_58;
V_54 = F_42 ( V_51 , 0 ) ;
if ( V_54 == V_66 )
goto V_67;
V_7 -> V_19 = F_43 ( V_51 , V_2 ,
& V_68 , V_7 ) ;
if ( ! V_7 -> V_19 )
goto V_67;
V_53 = F_44 ( V_69 , V_51 ) ;
if ( V_53 )
V_7 -> V_46 = V_53 -> V_8 ;
F_11 ( V_6 -> V_9 + V_26 , 0xffffffff ) ;
F_11 ( V_6 -> V_9 + V_27 , 0 ) ;
F_45 ( V_54 , V_7 ) ;
F_46 ( V_54 , F_20 ) ;
V_67:
return;
V_58:
F_47 ( L_3 ,
V_51 -> V_70 , V_55 ) ;
F_48 ( V_7 ) ;
return;
}
static int T_4 F_49 ( void )
{
struct V_50 * V_51 ;
F_50 (np, mpc8xxx_gpio_ids)
F_37 ( V_51 ) ;
return 0 ;
}
