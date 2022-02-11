static inline void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
static inline T_1 F_3 ( void T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_3 * V_4 , unsigned int V_5 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
unsigned long V_8 = F_7 ( V_5 ) ;
void T_2 * V_9 ;
if ( V_7 -> V_10 && V_7 -> V_10 -> V_11 ) {
V_8 &= F_3 ( V_7 -> V_12 + V_13 ) ;
V_9 = V_8 ? V_7 -> V_12 + V_14 :
V_7 -> V_12 + V_15 ;
return ! ! ( F_3 ( V_9 ) & F_7 ( V_5 ) ) ;
} else {
return ! ! ( F_3 ( V_7 -> V_12 + V_15 )
& F_7 ( V_5 ) ) ;
}
}
static void F_8 ( struct V_3 * V_4 , unsigned int V_5 , int V_1 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
unsigned long V_8 = F_7 ( V_5 ) ;
if ( V_1 )
F_1 ( V_8 , V_7 -> V_12 + V_16 ) ;
else
F_1 ( V_8 , V_7 -> V_12 + V_17 ) ;
}
static int F_9 ( struct V_3 * V_18 , unsigned V_5 )
{
struct V_6 * V_7 = F_6 ( V_18 ) ;
unsigned long V_8 = F_7 ( V_5 ) ;
T_1 V_1 ;
if ( V_7 -> V_10 && V_7 -> V_10 -> V_11 ) {
V_1 = F_3 ( V_7 -> V_12 + V_13 ) ;
V_1 &= ~ V_8 ;
F_1 ( V_1 , V_7 -> V_12 + V_13 ) ;
}
return F_10 ( V_18 -> V_19 + V_5 ) ;
}
static int F_11 ( struct V_3 * V_18 , unsigned V_5 ,
int V_20 )
{
struct V_6 * V_7 = F_6 ( V_18 ) ;
unsigned long V_8 = F_7 ( V_5 ) ;
if ( V_7 -> V_10 && V_7 -> V_10 -> V_11 )
F_1 ( V_8 , V_7 -> V_12 + V_13 ) ;
F_8 ( V_18 , V_5 , V_20 ) ;
return F_12 ( V_18 -> V_19 + V_5 ) ;
}
static void F_13 ( struct V_21 * V_22 )
{
struct V_6 * V_7 =
F_6 ( F_14 ( V_22 ) ) ;
struct V_23 * V_18 = F_15 ( V_22 ) ;
int V_24 ;
unsigned long V_25 ;
F_16 ( V_18 , V_22 ) ;
V_25 = F_3 ( V_7 -> V_19 + V_26 ) ;
F_17 (pin, &irq_isfr, VF610_GPIO_PER_PORT) {
F_1 ( F_7 ( V_24 ) , V_7 -> V_19 + V_26 ) ;
F_18 ( F_19 ( V_7 -> V_4 . V_27 , V_24 ) ) ;
}
F_20 ( V_18 , V_22 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_29 ) ) ;
int V_5 = V_29 -> V_30 ;
F_1 ( F_7 ( V_5 ) , V_7 -> V_19 + V_26 ) ;
}
static int F_23 ( struct V_28 * V_29 , T_1 type )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_29 ) ) ;
T_3 V_31 ;
switch ( type ) {
case V_32 :
V_31 = V_33 ;
break;
case V_34 :
V_31 = V_35 ;
break;
case V_36 :
V_31 = V_37 ;
break;
case V_38 :
V_31 = V_39 ;
break;
case V_40 :
V_31 = V_41 ;
break;
default:
return - V_42 ;
}
V_7 -> V_31 [ V_29 -> V_30 ] = V_31 ;
if ( type & V_43 )
F_24 ( V_29 , V_44 ) ;
else
F_24 ( V_29 , V_45 ) ;
return 0 ;
}
static void F_25 ( struct V_28 * V_29 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_29 ) ) ;
void T_2 * V_46 = V_7 -> V_19 + F_26 ( V_29 -> V_30 ) ;
F_1 ( 0 , V_46 ) ;
}
static void F_27 ( struct V_28 * V_29 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_29 ) ) ;
void T_2 * V_46 = V_7 -> V_19 + F_26 ( V_29 -> V_30 ) ;
F_1 ( V_7 -> V_31 [ V_29 -> V_30 ] << V_47 ,
V_46 ) ;
}
static int F_28 ( struct V_28 * V_29 , T_1 V_48 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_29 ) ) ;
if ( V_48 )
F_29 ( V_7 -> V_49 ) ;
else
F_30 ( V_7 -> V_49 ) ;
return 0 ;
}
static int F_31 ( struct V_50 * V_51 )
{
const struct V_52 * V_53 = F_32 ( V_54 ,
& V_51 -> V_55 ) ;
struct V_56 * V_55 = & V_51 -> V_55 ;
struct V_57 * V_58 = V_55 -> V_59 ;
struct V_6 * V_7 ;
struct V_60 * V_61 ;
struct V_3 * V_4 ;
int V_62 ;
V_7 = F_33 ( & V_51 -> V_55 , sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 )
return - V_64 ;
V_7 -> V_10 = V_53 -> V_65 ;
V_61 = F_34 ( V_51 , V_66 , 0 ) ;
V_7 -> V_19 = F_35 ( V_55 , V_61 ) ;
if ( F_36 ( V_7 -> V_19 ) )
return F_37 ( V_7 -> V_19 ) ;
V_61 = F_34 ( V_51 , V_66 , 1 ) ;
V_7 -> V_12 = F_35 ( V_55 , V_61 ) ;
if ( F_36 ( V_7 -> V_12 ) )
return F_37 ( V_7 -> V_12 ) ;
V_7 -> V_49 = F_38 ( V_51 , 0 ) ;
if ( V_7 -> V_49 < 0 )
return V_7 -> V_49 ;
V_4 = & V_7 -> V_4 ;
V_4 -> V_59 = V_58 ;
V_4 -> V_67 = V_55 ;
V_4 -> V_68 = L_1 ;
V_4 -> V_69 = V_70 ;
V_4 -> V_19 = F_39 ( V_58 , L_2 ) * V_70 ;
V_4 -> V_71 = V_72 ;
V_4 -> free = V_73 ;
V_4 -> V_74 = F_9 ;
V_4 -> V_75 = F_5 ;
V_4 -> V_76 = F_11 ;
V_4 -> V_77 = F_8 ;
V_62 = F_40 ( V_4 , V_7 ) ;
if ( V_62 < 0 )
return V_62 ;
F_1 ( ~ 0 , V_7 -> V_19 + V_26 ) ;
V_62 = F_41 ( V_4 , & V_78 , 0 ,
V_45 , V_79 ) ;
if ( V_62 ) {
F_42 ( V_55 , L_3 ) ;
F_43 ( V_4 ) ;
return V_62 ;
}
F_44 ( V_4 , & V_78 , V_7 -> V_49 ,
F_13 ) ;
return 0 ;
}
