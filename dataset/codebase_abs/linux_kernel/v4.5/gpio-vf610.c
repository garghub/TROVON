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
return ! ! ( F_3 ( V_7 -> V_8 + V_9 ) & F_7 ( V_5 ) ) ;
}
static void F_8 ( struct V_3 * V_4 , unsigned int V_5 , int V_1 )
{
struct V_6 * V_7 = F_6 ( V_4 ) ;
unsigned long V_10 = F_7 ( V_5 ) ;
if ( V_1 )
F_1 ( V_10 , V_7 -> V_8 + V_11 ) ;
else
F_1 ( V_10 , V_7 -> V_8 + V_12 ) ;
}
static int F_9 ( struct V_3 * V_13 , unsigned V_5 )
{
return F_10 ( V_13 -> V_14 + V_5 ) ;
}
static int F_11 ( struct V_3 * V_13 , unsigned V_5 ,
int V_15 )
{
F_8 ( V_13 , V_5 , V_15 ) ;
return F_12 ( V_13 -> V_14 + V_5 ) ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_6 * V_7 =
F_6 ( F_14 ( V_17 ) ) ;
struct V_18 * V_13 = F_15 ( V_17 ) ;
int V_19 ;
unsigned long V_20 ;
F_16 ( V_13 , V_17 ) ;
V_20 = F_3 ( V_7 -> V_14 + V_21 ) ;
F_17 (pin, &irq_isfr, VF610_GPIO_PER_PORT) {
F_1 ( F_7 ( V_19 ) , V_7 -> V_14 + V_21 ) ;
F_18 ( F_19 ( V_7 -> V_4 . V_22 , V_19 ) ) ;
}
F_20 ( V_13 , V_17 ) ;
}
static void F_21 ( struct V_23 * V_24 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_24 ) ) ;
int V_5 = V_24 -> V_25 ;
F_1 ( F_7 ( V_5 ) , V_7 -> V_14 + V_21 ) ;
}
static int F_23 ( struct V_23 * V_24 , T_1 type )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_24 ) ) ;
T_3 V_26 ;
switch ( type ) {
case V_27 :
V_26 = V_28 ;
break;
case V_29 :
V_26 = V_30 ;
break;
case V_31 :
V_26 = V_32 ;
break;
case V_33 :
V_26 = V_34 ;
break;
case V_35 :
V_26 = V_36 ;
break;
default:
return - V_37 ;
}
V_7 -> V_26 [ V_24 -> V_25 ] = V_26 ;
if ( type & V_38 )
F_24 ( V_24 , V_39 ) ;
else
F_24 ( V_24 , V_40 ) ;
return 0 ;
}
static void F_25 ( struct V_23 * V_24 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_24 ) ) ;
void T_2 * V_41 = V_7 -> V_14 + F_26 ( V_24 -> V_25 ) ;
F_1 ( 0 , V_41 ) ;
}
static void F_27 ( struct V_23 * V_24 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_24 ) ) ;
void T_2 * V_41 = V_7 -> V_14 + F_26 ( V_24 -> V_25 ) ;
F_1 ( V_7 -> V_26 [ V_24 -> V_25 ] << V_42 ,
V_41 ) ;
}
static int F_28 ( struct V_23 * V_24 , T_1 V_43 )
{
struct V_6 * V_7 =
F_6 ( F_22 ( V_24 ) ) ;
if ( V_43 )
F_29 ( V_7 -> V_44 ) ;
else
F_30 ( V_7 -> V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_46 -> V_48 ;
struct V_49 * V_50 = V_48 -> V_51 ;
struct V_6 * V_7 ;
struct V_52 * V_53 ;
struct V_3 * V_4 ;
int V_54 ;
V_7 = F_32 ( & V_46 -> V_48 , sizeof( * V_7 ) , V_55 ) ;
if ( ! V_7 )
return - V_56 ;
V_53 = F_33 ( V_46 , V_57 , 0 ) ;
V_7 -> V_14 = F_34 ( V_48 , V_53 ) ;
if ( F_35 ( V_7 -> V_14 ) )
return F_36 ( V_7 -> V_14 ) ;
V_53 = F_33 ( V_46 , V_57 , 1 ) ;
V_7 -> V_8 = F_34 ( V_48 , V_53 ) ;
if ( F_35 ( V_7 -> V_8 ) )
return F_36 ( V_7 -> V_8 ) ;
V_7 -> V_44 = F_37 ( V_46 , 0 ) ;
if ( V_7 -> V_44 < 0 )
return V_7 -> V_44 ;
V_4 = & V_7 -> V_4 ;
V_4 -> V_51 = V_50 ;
V_4 -> V_58 = V_48 ;
V_4 -> V_59 = L_1 ;
V_4 -> V_60 = V_61 ;
V_4 -> V_14 = F_38 ( V_50 , L_2 ) * V_61 ;
V_4 -> V_62 = V_63 ;
V_4 -> free = V_64 ;
V_4 -> V_65 = F_9 ;
V_4 -> V_66 = F_5 ;
V_4 -> V_67 = F_11 ;
V_4 -> V_68 = F_8 ;
V_54 = F_39 ( V_4 , V_7 ) ;
if ( V_54 < 0 )
return V_54 ;
F_1 ( ~ 0 , V_7 -> V_14 + V_21 ) ;
V_54 = F_40 ( V_4 , & V_69 , 0 ,
V_40 , V_70 ) ;
if ( V_54 ) {
F_41 ( V_48 , L_3 ) ;
F_42 ( V_4 ) ;
return V_54 ;
}
F_43 ( V_4 , & V_69 , V_7 -> V_44 ,
F_13 ) ;
return 0 ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_71 ) ;
}
