static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline void F_3 ( T_1 V_4 , void T_2 * V_5 )
{
F_4 ( V_4 , V_5 ) ;
}
static inline T_1 F_5 ( void T_2 * V_5 )
{
return F_6 ( V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 , unsigned int V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return ! ! ( F_5 ( V_7 -> V_8 + V_9 ) & F_8 ( V_6 ) ) ;
}
static void F_9 ( struct V_2 * V_3 , unsigned int V_6 , int V_4 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned long V_10 = F_8 ( V_6 ) ;
if ( V_4 )
F_3 ( V_10 , V_7 -> V_8 + V_11 ) ;
else
F_3 ( V_10 , V_7 -> V_8 + V_12 ) ;
}
static int F_10 ( struct V_2 * V_13 , unsigned V_6 )
{
return F_11 ( V_13 -> V_14 + V_6 ) ;
}
static int F_12 ( struct V_2 * V_13 , unsigned V_6 ,
int V_15 )
{
F_9 ( V_13 , V_6 , V_15 ) ;
return F_13 ( V_13 -> V_14 + V_6 ) ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_1 * V_7 =
F_1 ( F_15 ( V_17 ) ) ;
struct V_18 * V_13 = F_16 ( V_17 ) ;
int V_19 ;
unsigned long V_20 ;
F_17 ( V_13 , V_17 ) ;
V_20 = F_5 ( V_7 -> V_14 + V_21 ) ;
F_18 (pin, &irq_isfr, VF610_GPIO_PER_PORT) {
F_3 ( F_8 ( V_19 ) , V_7 -> V_14 + V_21 ) ;
F_19 ( F_20 ( V_7 -> V_3 . V_22 , V_19 ) ) ;
}
F_21 ( V_13 , V_17 ) ;
}
static void F_22 ( struct V_23 * V_24 )
{
struct V_1 * V_7 =
F_1 ( F_23 ( V_24 ) ) ;
int V_6 = V_24 -> V_25 ;
F_3 ( F_8 ( V_6 ) , V_7 -> V_14 + V_21 ) ;
}
static int F_24 ( struct V_23 * V_24 , T_1 type )
{
struct V_1 * V_7 =
F_1 ( F_23 ( V_24 ) ) ;
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
F_25 ( V_24 , V_39 ) ;
else
F_25 ( V_24 , V_40 ) ;
return 0 ;
}
static void F_26 ( struct V_23 * V_24 )
{
struct V_1 * V_7 =
F_1 ( F_23 ( V_24 ) ) ;
void T_2 * V_41 = V_7 -> V_14 + F_27 ( V_24 -> V_25 ) ;
F_3 ( 0 , V_41 ) ;
}
static void F_28 ( struct V_23 * V_24 )
{
struct V_1 * V_7 =
F_1 ( F_23 ( V_24 ) ) ;
void T_2 * V_41 = V_7 -> V_14 + F_27 ( V_24 -> V_25 ) ;
F_3 ( V_7 -> V_26 [ V_24 -> V_25 ] << V_42 ,
V_41 ) ;
}
static int F_29 ( struct V_23 * V_24 , T_1 V_43 )
{
struct V_1 * V_7 =
F_1 ( F_23 ( V_24 ) ) ;
if ( V_43 )
F_30 ( V_7 -> V_44 ) ;
else
F_31 ( V_7 -> V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_46 -> V_48 ;
struct V_49 * V_50 = V_48 -> V_51 ;
struct V_1 * V_7 ;
struct V_52 * V_53 ;
struct V_2 * V_3 ;
int V_54 ;
V_7 = F_33 ( & V_46 -> V_48 , sizeof( * V_7 ) , V_55 ) ;
if ( ! V_7 )
return - V_56 ;
V_53 = F_34 ( V_46 , V_57 , 0 ) ;
V_7 -> V_14 = F_35 ( V_48 , V_53 ) ;
if ( F_36 ( V_7 -> V_14 ) )
return F_37 ( V_7 -> V_14 ) ;
V_53 = F_34 ( V_46 , V_57 , 1 ) ;
V_7 -> V_8 = F_35 ( V_48 , V_53 ) ;
if ( F_36 ( V_7 -> V_8 ) )
return F_37 ( V_7 -> V_8 ) ;
V_7 -> V_44 = F_38 ( V_46 , 0 ) ;
if ( V_7 -> V_44 < 0 )
return V_7 -> V_44 ;
V_3 = & V_7 -> V_3 ;
V_3 -> V_51 = V_50 ;
V_3 -> V_48 = V_48 ;
V_3 -> V_58 = L_1 ;
V_3 -> V_59 = V_60 ;
V_3 -> V_14 = F_39 ( V_50 , L_2 ) * V_60 ;
V_3 -> V_61 = V_62 ;
V_3 -> free = V_63 ;
V_3 -> V_64 = F_10 ;
V_3 -> V_65 = F_7 ;
V_3 -> V_66 = F_12 ;
V_3 -> V_67 = F_9 ;
V_54 = F_40 ( V_3 ) ;
if ( V_54 < 0 )
return V_54 ;
F_3 ( ~ 0 , V_7 -> V_14 + V_21 ) ;
V_54 = F_41 ( V_3 , & V_68 , 0 ,
V_40 , V_69 ) ;
if ( V_54 ) {
F_42 ( V_48 , L_3 ) ;
F_43 ( V_3 ) ;
return V_54 ;
}
F_44 ( V_3 , & V_68 , V_7 -> V_44 ,
F_14 ) ;
return 0 ;
}
static int T_4 F_45 ( void )
{
return F_46 ( & V_70 ) ;
}
