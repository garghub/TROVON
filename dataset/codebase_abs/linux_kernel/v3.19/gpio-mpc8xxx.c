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
static void F_13 ( struct V_11 * V_12 ,
unsigned long * V_19 , unsigned long * V_20 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_17 ;
int V_21 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
for ( V_21 = 0 ; V_21 < V_12 -> V_22 ; V_21 ++ ) {
if ( * V_19 == 0 )
break;
if ( F_14 ( V_21 , V_19 ) ) {
if ( F_15 ( V_21 , V_20 ) )
V_7 -> V_8 |= F_1 ( V_21 ) ;
else
V_7 -> V_8 &= ~ F_1 ( V_21 ) ;
}
}
F_11 ( V_5 -> V_9 + V_10 , V_7 -> V_8 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
}
static int F_16 ( struct V_11 * V_12 , unsigned int V_1 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_17 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_17 ( V_5 -> V_9 + V_16 , F_1 ( V_1 ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
unsigned long V_17 ;
F_9 ( V_12 , V_1 , V_13 ) ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_19 ( V_5 -> V_9 + V_16 , F_1 ( V_1 ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
return 0 ;
}
static int F_20 ( struct V_11 * V_12 , unsigned int V_1 , int V_13 )
{
if ( V_1 >= 28 )
return - V_23 ;
return F_18 ( V_12 , V_1 , V_13 ) ;
}
static int F_21 ( struct V_11 * V_12 , unsigned V_24 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_3 * V_7 = F_2 ( V_5 ) ;
if ( V_7 -> V_25 && V_24 < V_2 )
return F_22 ( V_7 -> V_25 , V_24 ) ;
else
return - V_26 ;
}
static void F_23 ( unsigned int V_25 , struct V_27 * V_28 )
{
struct V_3 * V_7 = F_24 ( V_28 ) ;
struct V_29 * V_30 = F_25 ( V_28 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned int V_19 ;
V_19 = F_5 ( V_5 -> V_9 + V_31 ) & F_5 ( V_5 -> V_9 + V_32 ) ;
if ( V_19 )
F_26 ( F_27 ( V_7 -> V_25 ,
32 - F_28 ( V_19 ) ) ) ;
if ( V_30 -> V_33 )
V_30 -> V_33 ( & V_28 -> V_34 ) ;
}
static void F_29 ( struct V_34 * V_35 )
{
struct V_3 * V_7 = F_30 ( V_35 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_17 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_19 ( V_5 -> V_9 + V_32 , F_1 ( F_31 ( V_35 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
}
static void F_32 ( struct V_34 * V_35 )
{
struct V_3 * V_7 = F_30 ( V_35 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_17 ;
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_17 ( V_5 -> V_9 + V_32 , F_1 ( F_31 ( V_35 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
}
static void F_33 ( struct V_34 * V_35 )
{
struct V_3 * V_7 = F_30 ( V_35 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
F_11 ( V_5 -> V_9 + V_31 , F_1 ( F_31 ( V_35 ) ) ) ;
}
static int F_34 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_3 * V_7 = F_30 ( V_35 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_17 ;
switch ( V_36 ) {
case V_37 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_19 ( V_5 -> V_9 + V_38 ,
F_1 ( F_31 ( V_35 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
case V_39 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_17 ( V_5 -> V_9 + V_38 ,
F_1 ( F_31 ( V_35 ) ) ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_35 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_3 * V_7 = F_30 ( V_35 ) ;
struct V_4 * V_5 = & V_7 -> V_6 ;
unsigned long V_1 = F_31 ( V_35 ) ;
void T_2 * V_40 ;
unsigned int V_41 ;
unsigned long V_17 ;
if ( V_1 < 16 ) {
V_40 = V_5 -> V_9 + V_38 ;
V_41 = ( 15 - V_1 ) * 2 ;
} else {
V_40 = V_5 -> V_9 + V_42 ;
V_41 = ( 15 - ( V_1 % 16 ) ) * 2 ;
}
switch ( V_36 ) {
case V_37 :
case V_43 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_36 ( V_40 , 3 << V_41 , 2 << V_41 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
case V_44 :
case V_45 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_36 ( V_40 , 3 << V_41 , 1 << V_41 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
case V_39 :
F_10 ( & V_7 -> V_18 , V_17 ) ;
F_17 ( V_40 , 3 << V_41 ) ;
F_12 ( & V_7 -> V_18 , V_17 ) ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_37 ( struct V_46 * V_47 , unsigned int V_25 ,
T_3 V_48 )
{
struct V_3 * V_7 = V_47 -> V_49 ;
if ( V_7 -> V_50 )
V_51 . V_52 = V_7 -> V_50 ;
F_38 ( V_25 , V_47 -> V_49 ) ;
F_39 ( V_25 , & V_51 , V_53 ) ;
return 0 ;
}
static void T_4 F_40 ( struct V_54 * V_55 )
{
struct V_3 * V_7 ;
struct V_4 * V_6 ;
struct V_11 * V_12 ;
const struct V_56 * V_57 ;
unsigned V_48 ;
int V_58 ;
V_7 = F_41 ( sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 ) {
V_58 = - V_60 ;
goto V_61;
}
F_42 ( & V_7 -> V_18 ) ;
V_6 = & V_7 -> V_6 ;
V_12 = & V_6 -> V_12 ;
V_6 -> V_62 = F_4 ;
V_12 -> V_22 = V_2 ;
V_12 -> V_63 = F_16 ;
V_12 -> V_64 = F_43 ( V_55 , L_1 ) ?
F_20 : F_18 ;
V_12 -> V_65 = F_43 ( V_55 , L_2 ) ?
F_6 : F_8 ;
V_12 -> V_66 = F_9 ;
V_12 -> V_67 = F_13 ;
V_12 -> V_68 = F_21 ;
V_58 = F_44 ( V_55 , V_6 ) ;
if ( V_58 )
goto V_61;
V_48 = F_45 ( V_55 , 0 ) ;
if ( V_48 == V_69 )
goto V_70;
V_7 -> V_25 = F_46 ( V_55 , V_2 ,
& V_71 , V_7 ) ;
if ( ! V_7 -> V_25 )
goto V_70;
V_57 = F_47 ( V_72 , V_55 ) ;
if ( V_57 )
V_7 -> V_50 = V_57 -> V_8 ;
F_11 ( V_6 -> V_9 + V_31 , 0xffffffff ) ;
F_11 ( V_6 -> V_9 + V_32 , 0 ) ;
F_48 ( V_48 , V_7 ) ;
F_49 ( V_48 , F_23 ) ;
V_70:
return;
V_61:
F_50 ( L_3 ,
V_55 -> V_73 , V_58 ) ;
F_51 ( V_7 ) ;
return;
}
static int T_4 F_52 ( void )
{
struct V_54 * V_55 ;
F_53 (np, mpc8xxx_gpio_ids)
F_40 ( V_55 ) ;
return 0 ;
}
