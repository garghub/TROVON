static inline T_1 F_1 ( void T_2 * V_1 )
{
if ( F_2 ( V_2 ) && F_2 ( V_3 ) )
return F_3 ( V_1 ) ;
else
return F_4 ( V_1 ) ;
}
static inline void F_5 ( T_1 V_4 , void T_2 * V_1 )
{
if ( F_2 ( V_2 ) && F_2 ( V_3 ) )
F_6 ( V_4 , V_1 ) ;
else
F_7 ( V_4 , V_1 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
T_1 V_10 , V_11 ;
int V_12 ;
V_11 = F_9 ( V_6 -> V_13 + V_14 ) ;
if ( ! ( V_11 & V_15 ) )
V_6 -> V_16 |= V_17 ;
for ( V_12 = 0 , V_10 = V_18 ;
V_12 < V_19 ;
V_12 ++ , V_10 += V_20 ) {
if ( V_8 -> V_21 & F_10 ( V_12 ) )
F_11 ( 0xff1003fc ,
V_6 -> V_13 + F_12 ( V_10 ) ) ;
}
}
static void F_13 ( struct V_7 * V_8 , int V_22 )
{
void T_2 * V_23 = V_8 -> V_24 + V_25 +
( V_22 * V_26 ) ;
void T_2 * V_27 ;
T_1 V_28 ;
if ( V_8 -> V_29 & V_30 )
return;
V_27 = V_23 + V_31 ;
V_28 = F_1 ( V_27 ) ;
V_28 &= ~ V_32 ;
F_5 ( V_28 , V_27 ) ;
V_27 = V_23 + V_33 ;
V_28 = F_1 ( V_27 ) ;
V_28 &= ~ ( V_34 | V_35 |
V_36 ) ;
V_28 |= V_37 ;
F_5 ( V_28 , V_27 ) ;
V_28 = F_1 ( V_27 ) ;
V_28 |= V_38 ;
F_5 ( V_28 , V_27 ) ;
V_28 = F_1 ( V_27 ) ;
V_28 &= ~ V_38 ;
F_5 ( V_28 , V_27 ) ;
( void ) F_1 ( V_27 ) ;
}
static void F_14 ( struct V_7 * V_8 , int V_22 )
{
void T_2 * V_23 = V_8 -> V_24 + V_25 +
( V_22 * V_26 ) ;
void T_2 * V_27 ;
T_1 V_28 ;
if ( V_8 -> V_29 & V_30 )
return;
V_27 = V_23 + V_33 ;
V_28 = F_1 ( V_27 ) ;
V_28 |= ( V_34 | V_35 |
V_36 | V_37 |
V_38 ) ;
F_5 ( V_28 , V_27 ) ;
V_27 = V_23 + V_31 ;
V_28 = F_1 ( V_27 ) ;
V_28 |= V_32 ;
F_5 ( V_28 , V_27 ) ;
}
static void F_15 ( struct V_7 * V_8 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_19 ; V_12 ++ )
if ( V_8 -> V_21 & F_10 ( V_12 ) )
F_13 ( V_8 , V_12 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_19 ; V_12 ++ )
if ( V_8 -> V_21 & F_10 ( V_12 ) )
F_14 ( V_8 , V_12 ) ;
}
static T_1 F_17 ( struct V_39 * V_40 ,
struct V_7 * V_8 )
{
void T_2 * V_41 ;
struct V_42 * V_43 ;
T_1 V_44 ;
V_43 = F_18 ( V_40 , V_45 , L_1 ) ;
V_41 = F_19 ( & V_40 -> V_46 , V_43 ) ;
if ( F_20 ( V_41 ) )
return 0 ;
V_44 = F_9 ( V_41 + V_47 ) ;
if ( F_21 ( V_44 ) > V_19 )
F_22 ( V_8 -> V_46 , L_2 ,
V_44 ) ;
else if ( ! V_44 )
F_23 ( V_8 -> V_46 , L_3 ) ;
F_24 ( & V_40 -> V_46 , V_41 ) ;
F_25 ( & V_40 -> V_46 , V_43 -> V_48 , F_26 ( V_43 ) ) ;
return V_44 ;
}
static void F_27 ( struct V_7 * V_8 )
{
void T_2 * V_49 = V_8 -> V_24 + V_50 ;
if ( V_8 -> V_51 == V_52 ) {
T_1 V_53 = F_1 ( V_49 ) ;
V_53 &= ~ ( ( 0x03 << V_54 ) |
( 0x03 << V_55 ) ) ;
V_53 |= ( 0x02 << V_54 ) |
( 0x02 << V_55 ) ;
F_5 ( V_53 , V_49 ) ;
} else
F_5 ( V_56 , V_49 ) ;
}
static int F_28 ( struct V_57 * V_46 )
{
struct V_58 * V_59 = F_29 ( V_46 ) ;
struct V_5 * V_6 = V_59 -> V_60 ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_61 ;
V_61 = F_30 ( V_46 ) ;
F_16 ( V_8 ) ;
return V_61 ;
}
static int F_31 ( struct V_57 * V_46 )
{
struct V_58 * V_59 = F_29 ( V_46 ) ;
struct V_5 * V_6 = V_59 -> V_60 ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_27 ( V_8 ) ;
F_15 ( V_8 ) ;
F_8 ( V_6 ) ;
return F_32 ( V_46 ) ;
}
static int F_33 ( struct V_39 * V_40 )
{
const struct V_62 * V_63 ;
struct V_57 * V_46 = & V_40 -> V_46 ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
int V_61 ;
V_8 = F_34 ( V_46 , sizeof( * V_8 ) , V_64 ) ;
if ( ! V_8 )
return - V_65 ;
V_63 = F_35 ( V_66 , V_40 -> V_46 . V_67 ) ;
if ( ! V_63 )
return - V_68 ;
V_8 -> V_51 = (enum V_69 ) V_63 -> V_53 ;
V_8 -> V_46 = V_46 ;
V_43 = F_18 ( V_40 , V_45 , L_4 ) ;
V_8 -> V_24 = F_19 ( V_46 , V_43 ) ;
if ( F_20 ( V_8 -> V_24 ) )
return F_36 ( V_8 -> V_24 ) ;
if ( ( V_8 -> V_51 == V_70 ) ||
( V_8 -> V_51 == V_52 ) ) {
V_8 -> V_29 |= V_71 ;
V_8 -> V_29 |= V_30 ;
}
F_27 ( V_8 ) ;
V_8 -> V_21 = F_17 ( V_40 , V_8 ) ;
if ( ! V_8 -> V_21 )
return - V_68 ;
F_15 ( V_8 ) ;
V_6 = F_37 ( V_40 ) ;
if ( F_20 ( V_6 ) )
return F_36 ( V_6 ) ;
V_6 -> V_9 = V_8 ;
V_6 -> V_16 = V_72 ;
F_8 ( V_6 ) ;
V_61 = F_38 ( V_6 ) ;
if ( V_61 )
return V_61 ;
if ( V_8 -> V_29 & V_71 )
V_6 -> V_16 |= V_73 ;
V_6 -> V_16 |= V_74 ;
V_61 = F_39 ( V_40 , V_6 , & V_75 ,
& V_76 ) ;
if ( V_61 )
return V_61 ;
F_23 ( V_46 , L_5 ) ;
return 0 ;
}
static int F_40 ( struct V_39 * V_40 )
{
struct V_58 * V_59 = F_29 ( & V_40 -> V_46 ) ;
struct V_5 * V_6 = V_59 -> V_60 ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_61 ;
V_61 = F_41 ( V_40 ) ;
if ( V_61 )
return V_61 ;
F_16 ( V_8 ) ;
return 0 ;
}
