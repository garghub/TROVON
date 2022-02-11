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
static int F_17 ( struct V_11 * V_12 , unsigned V_17 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
if ( V_7 -> V_18 && V_17 < V_2 )
return F_18 ( V_7 -> V_18 , V_17 ) ;
else
return - V_19 ;
}
static void F_19 ( unsigned int V_18 , struct V_20 * V_21 )
{
struct V_3 * V_7 = F_20 ( V_21 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned int V_22 ;
V_22 = F_5 ( V_5 -> V_9 + V_23 ) & F_5 ( V_5 -> V_9 + V_24 ) ;
if ( V_22 )
F_21 ( F_22 ( V_7 -> V_18 ,
32 - F_23 ( V_22 ) ) ) ;
}
static void F_24 ( struct V_25 * V_26 )
{
struct V_3 * V_7 = F_25 ( V_26 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_16 ( V_5 -> V_9 + V_24 , F_1 ( F_26 ( V_26 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static void F_27 ( struct V_25 * V_26 )
{
struct V_3 * V_7 = F_25 ( V_26 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_15 ;
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_14 ( V_5 -> V_9 + V_24 , F_1 ( F_26 ( V_26 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_3 * V_7 = F_25 ( V_26 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
F_11 ( V_5 -> V_9 + V_23 , F_1 ( F_26 ( V_26 ) ) ) ;
}
static int F_29 ( struct V_25 * V_26 , unsigned int V_27 )
{
struct V_3 * V_7 = F_25 ( V_26 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_15 ;
switch ( V_27 ) {
case V_28 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_16 ( V_5 -> V_9 + V_29 ,
F_1 ( F_26 ( V_26 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
case V_30 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_14 ( V_5 -> V_9 + V_29 ,
F_1 ( F_26 ( V_26 ) ) ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_30 ( struct V_25 * V_26 , unsigned int V_27 )
{
struct V_3 * V_7 = F_25 ( V_26 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_1 = F_26 ( V_26 ) ;
void T_2 * V_32 ;
unsigned int V_33 ;
unsigned long V_15 ;
if ( V_1 < 16 ) {
V_32 = V_5 -> V_9 + V_29 ;
V_33 = ( 15 - V_1 ) * 2 ;
} else {
V_32 = V_5 -> V_9 + V_34 ;
V_33 = ( 15 - ( V_1 % 16 ) ) * 2 ;
}
switch ( V_27 ) {
case V_28 :
case V_35 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_31 ( V_32 , 3 << V_33 , 2 << V_33 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
case V_36 :
case V_37 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_31 ( V_32 , 3 << V_33 , 1 << V_33 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
case V_30 :
F_10 ( & V_7 -> V_16 , V_15 ) ;
F_14 ( V_32 , 3 << V_33 ) ;
F_12 ( & V_7 -> V_16 , V_15 ) ;
break;
default:
return - V_31 ;
}
return 0 ;
}
static int F_32 ( struct V_38 * V_39 , unsigned int V_40 ,
T_3 V_41 )
{
struct V_3 * V_7 = V_39 -> V_42 ;
if ( V_7 -> V_43 )
V_44 . V_45 = V_7 -> V_43 ;
F_33 ( V_40 , V_39 -> V_42 ) ;
F_34 ( V_40 , & V_44 , V_46 ) ;
F_35 ( V_40 , V_47 ) ;
return 0 ;
}
static int F_36 ( struct V_38 * V_39 , struct V_48 * V_49 ,
const T_1 * V_50 , unsigned int V_51 ,
T_3 * V_52 ,
unsigned int * V_53 )
{
* V_52 = V_50 [ 0 ] ;
* V_53 = V_50 [ 1 ] ;
return 0 ;
}
static void T_4 F_37 ( struct V_48 * V_54 )
{
struct V_3 * V_7 ;
struct V_4 * V_6 ;
struct V_11 * V_12 ;
const struct V_55 * V_56 ;
unsigned V_57 ;
int V_58 ;
V_7 = F_38 ( sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 ) {
V_58 = - V_60 ;
goto V_61;
}
F_39 ( & V_7 -> V_16 ) ;
V_6 = & V_7 -> V_6 ;
V_12 = & V_6 -> V_12 ;
V_6 -> V_62 = F_4 ;
V_12 -> V_63 = V_2 ;
V_12 -> V_64 = F_13 ;
V_12 -> V_65 = F_15 ;
if ( F_40 ( V_54 , L_1 ) )
V_12 -> V_66 = F_6 ;
else
V_12 -> V_66 = F_8 ;
V_12 -> V_67 = F_9 ;
V_12 -> V_68 = F_17 ;
V_58 = F_41 ( V_54 , V_6 ) ;
if ( V_58 )
goto V_61;
V_57 = F_42 ( V_54 , 0 ) ;
if ( V_57 == V_69 )
goto V_70;
V_7 -> V_18 =
F_43 ( V_54 , V_71 , V_2 ,
& V_72 , V_2 ) ;
if ( ! V_7 -> V_18 )
goto V_70;
V_56 = F_44 ( V_73 , V_54 ) ;
if ( V_56 )
V_7 -> V_43 = V_56 -> V_8 ;
V_7 -> V_18 -> V_42 = V_7 ;
F_11 ( V_6 -> V_9 + V_23 , 0xffffffff ) ;
F_11 ( V_6 -> V_9 + V_24 , 0 ) ;
F_45 ( V_57 , V_7 ) ;
F_46 ( V_57 , F_19 ) ;
V_70:
return;
V_61:
F_47 ( L_2 ,
V_54 -> V_74 , V_58 ) ;
F_48 ( V_7 ) ;
return;
}
static int T_4 F_49 ( void )
{
struct V_48 * V_54 ;
F_50 (np, mpc8xxx_gpio_ids)
F_37 ( V_54 ) ;
return 0 ;
}
