static inline void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
static inline T_1 F_3 ( void T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static int F_5 ( struct V_3 * V_4 , unsigned V_5 )
{
return F_6 ( V_4 -> V_6 + V_5 ) ;
}
static void F_7 ( struct V_3 * V_4 , unsigned V_5 )
{
F_8 ( V_4 -> V_6 + V_5 ) ;
}
static int F_9 ( struct V_3 * V_7 , unsigned int V_8 )
{
struct V_9 * V_10 =
F_10 ( V_7 , struct V_9 , V_7 ) ;
return ! ! ( F_3 ( V_10 -> V_11 + V_12 ) & F_11 ( V_8 ) ) ;
}
static void F_12 ( struct V_3 * V_7 , unsigned int V_8 , int V_1 )
{
struct V_9 * V_10 =
F_10 ( V_7 , struct V_9 , V_7 ) ;
unsigned long V_13 = F_11 ( V_8 ) ;
if ( V_1 )
F_1 ( V_13 , V_10 -> V_11 + V_14 ) ;
else
F_1 ( V_13 , V_10 -> V_11 + V_15 ) ;
}
static int F_13 ( struct V_3 * V_4 , unsigned V_8 )
{
return F_14 ( V_4 -> V_6 + V_8 ) ;
}
static int F_15 ( struct V_3 * V_4 , unsigned V_8 ,
int V_16 )
{
F_12 ( V_4 , V_8 , V_16 ) ;
return F_16 ( V_4 -> V_6 + V_8 ) ;
}
static void F_17 ( T_1 V_17 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_18 ( V_17 ) ;
struct V_20 * V_4 = F_19 ( V_19 ) ;
int V_21 ;
unsigned long V_22 ;
F_20 ( V_4 , V_19 ) ;
V_22 = F_3 ( V_10 -> V_6 + V_23 ) ;
F_21 (pin, &irq_isfr, VF610_GPIO_PER_PORT) {
F_1 ( F_11 ( V_21 ) , V_10 -> V_6 + V_23 ) ;
F_22 ( F_23 ( V_10 -> V_7 . V_24 , V_21 ) ) ;
}
F_24 ( V_4 , V_19 ) ;
}
static void F_25 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_26 ( V_26 ) ;
int V_8 = V_26 -> V_27 ;
F_1 ( F_11 ( V_8 ) , V_10 -> V_6 + V_23 ) ;
}
static int F_27 ( struct V_25 * V_26 , T_1 type )
{
struct V_9 * V_10 = F_26 ( V_26 ) ;
T_3 V_28 ;
switch ( type ) {
case V_29 :
V_28 = V_30 ;
break;
case V_31 :
V_28 = V_32 ;
break;
case V_33 :
V_28 = V_34 ;
break;
case V_35 :
V_28 = V_36 ;
break;
case V_37 :
V_28 = V_38 ;
break;
default:
return - V_39 ;
}
V_10 -> V_28 [ V_26 -> V_27 ] = V_28 ;
return 0 ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_26 ( V_26 ) ;
void T_2 * V_40 = V_10 -> V_6 + F_29 ( V_26 -> V_27 ) ;
F_1 ( 0 , V_40 ) ;
}
static void F_30 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_26 ( V_26 ) ;
void T_2 * V_40 = V_10 -> V_6 + F_29 ( V_26 -> V_27 ) ;
F_1 ( V_10 -> V_28 [ V_26 -> V_27 ] << V_41 ,
V_40 ) ;
}
static int F_31 ( struct V_25 * V_26 , T_1 V_42 )
{
struct V_9 * V_10 = F_26 ( V_26 ) ;
if ( V_42 )
F_32 ( V_10 -> V_17 ) ;
else
F_33 ( V_10 -> V_17 ) ;
return 0 ;
}
static int F_34 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = & V_44 -> V_46 ;
struct V_47 * V_48 = V_46 -> V_49 ;
struct V_9 * V_10 ;
struct V_50 * V_51 ;
struct V_3 * V_7 ;
int V_52 ;
V_10 = F_35 ( & V_44 -> V_46 , sizeof( * V_10 ) , V_53 ) ;
if ( ! V_10 )
return - V_54 ;
V_51 = F_36 ( V_44 , V_55 , 0 ) ;
V_10 -> V_6 = F_37 ( V_46 , V_51 ) ;
if ( F_38 ( V_10 -> V_6 ) )
return F_39 ( V_10 -> V_6 ) ;
V_51 = F_36 ( V_44 , V_55 , 1 ) ;
V_10 -> V_11 = F_37 ( V_46 , V_51 ) ;
if ( F_38 ( V_10 -> V_11 ) )
return F_39 ( V_10 -> V_11 ) ;
V_10 -> V_17 = F_40 ( V_44 , 0 ) ;
if ( V_10 -> V_17 < 0 )
return V_10 -> V_17 ;
V_7 = & V_10 -> V_7 ;
V_7 -> V_49 = V_48 ;
V_7 -> V_46 = V_46 ;
V_7 -> V_56 = L_1 ;
V_7 -> V_57 = V_58 ;
V_7 -> V_6 = F_41 ( V_48 , L_2 ) * V_58 ;
V_7 -> V_59 = F_5 ;
V_7 -> free = F_7 ;
V_7 -> V_60 = F_13 ;
V_7 -> V_61 = F_9 ;
V_7 -> V_62 = F_15 ;
V_7 -> V_63 = F_12 ;
V_52 = F_42 ( V_7 ) ;
if ( V_52 < 0 )
return V_52 ;
F_1 ( ~ 0 , V_10 -> V_6 + V_23 ) ;
V_52 = F_43 ( V_7 , & V_64 , 0 ,
V_65 , V_66 ) ;
if ( V_52 ) {
F_44 ( V_46 , L_3 ) ;
F_45 ( V_7 ) ;
return V_52 ;
}
F_46 ( V_7 , & V_64 , V_10 -> V_17 ,
F_17 ) ;
return 0 ;
}
static int T_4 F_47 ( void )
{
return F_48 ( & V_67 ) ;
}
