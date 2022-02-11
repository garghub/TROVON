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
static void F_17 ( struct V_17 * V_18 )
{
struct V_9 * V_10 = F_18 ( V_18 ) ;
struct V_19 * V_4 = F_19 ( V_18 ) ;
int V_20 ;
unsigned long V_21 ;
F_20 ( V_4 , V_18 ) ;
V_21 = F_3 ( V_10 -> V_6 + V_22 ) ;
F_21 (pin, &irq_isfr, VF610_GPIO_PER_PORT) {
F_1 ( F_11 ( V_20 ) , V_10 -> V_6 + V_22 ) ;
F_22 ( F_23 ( V_10 -> V_7 . V_23 , V_20 ) ) ;
}
F_24 ( V_4 , V_18 ) ;
}
static void F_25 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
int V_8 = V_25 -> V_26 ;
F_1 ( F_11 ( V_8 ) , V_10 -> V_6 + V_22 ) ;
}
static int F_27 ( struct V_24 * V_25 , T_1 type )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
T_3 V_27 ;
switch ( type ) {
case V_28 :
V_27 = V_29 ;
break;
case V_30 :
V_27 = V_31 ;
break;
case V_32 :
V_27 = V_33 ;
break;
case V_34 :
V_27 = V_35 ;
break;
case V_36 :
V_27 = V_37 ;
break;
default:
return - V_38 ;
}
V_10 -> V_27 [ V_25 -> V_26 ] = V_27 ;
if ( type & V_39 )
F_28 ( V_25 , V_40 ) ;
else
F_28 ( V_25 , V_41 ) ;
return 0 ;
}
static void F_29 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
void T_2 * V_42 = V_10 -> V_6 + F_30 ( V_25 -> V_26 ) ;
F_1 ( 0 , V_42 ) ;
}
static void F_31 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
void T_2 * V_42 = V_10 -> V_6 + F_30 ( V_25 -> V_26 ) ;
F_1 ( V_10 -> V_27 [ V_25 -> V_26 ] << V_43 ,
V_42 ) ;
}
static int F_32 ( struct V_24 * V_25 , T_1 V_44 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
if ( V_44 )
F_33 ( V_10 -> V_45 ) ;
else
F_34 ( V_10 -> V_45 ) ;
return 0 ;
}
static int F_35 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_47 -> V_49 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_9 * V_10 ;
struct V_53 * V_54 ;
struct V_3 * V_7 ;
int V_55 ;
V_10 = F_36 ( & V_47 -> V_49 , sizeof( * V_10 ) , V_56 ) ;
if ( ! V_10 )
return - V_57 ;
V_54 = F_37 ( V_47 , V_58 , 0 ) ;
V_10 -> V_6 = F_38 ( V_49 , V_54 ) ;
if ( F_39 ( V_10 -> V_6 ) )
return F_40 ( V_10 -> V_6 ) ;
V_54 = F_37 ( V_47 , V_58 , 1 ) ;
V_10 -> V_11 = F_38 ( V_49 , V_54 ) ;
if ( F_39 ( V_10 -> V_11 ) )
return F_40 ( V_10 -> V_11 ) ;
V_10 -> V_45 = F_41 ( V_47 , 0 ) ;
if ( V_10 -> V_45 < 0 )
return V_10 -> V_45 ;
V_7 = & V_10 -> V_7 ;
V_7 -> V_52 = V_51 ;
V_7 -> V_49 = V_49 ;
V_7 -> V_59 = L_1 ;
V_7 -> V_60 = V_61 ;
V_7 -> V_6 = F_42 ( V_51 , L_2 ) * V_61 ;
V_7 -> V_62 = F_5 ;
V_7 -> free = F_7 ;
V_7 -> V_63 = F_13 ;
V_7 -> V_64 = F_9 ;
V_7 -> V_65 = F_15 ;
V_7 -> V_66 = F_12 ;
V_55 = F_43 ( V_7 ) ;
if ( V_55 < 0 )
return V_55 ;
F_1 ( ~ 0 , V_10 -> V_6 + V_22 ) ;
V_55 = F_44 ( V_7 , & V_67 , 0 ,
V_41 , V_68 ) ;
if ( V_55 ) {
F_45 ( V_49 , L_3 ) ;
F_46 ( V_7 ) ;
return V_55 ;
}
F_47 ( V_7 , & V_67 , V_10 -> V_45 ,
F_17 ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_69 ) ;
}
