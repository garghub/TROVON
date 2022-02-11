static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
F_2 ( V_1 -> V_4 , V_2 , & V_3 ) ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_1 -> V_4 , V_2 , V_3 ) ;
}
static T_2 F_5 ( T_2 V_5 )
{
return V_5 & V_6 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
T_1 V_3 ;
unsigned int V_11 ;
V_3 = F_1 ( V_1 , V_12 ) ;
V_3 |= V_13 ;
F_3 ( V_1 , V_12 , V_3 ) ;
V_3 = F_1 ( V_1 , V_12 ) ;
V_3 |= V_14 |
V_15 |
V_16 |
V_17 ;
V_3 |= V_18 ;
V_3 &= ~ V_19 ;
V_3 &= ~ V_20 ;
F_3 ( V_1 , V_12 , V_3 ) ;
F_7 ( 5000 , 6000 ) ;
V_3 = F_1 ( V_1 , V_21 ) ;
V_3 |= V_22 ;
F_3 ( V_1 , V_21 , V_3 ) ;
F_7 ( 20 , 30 ) ;
V_3 = F_1 ( V_1 , V_12 ) ;
V_3 |= V_23 | V_24 ;
F_3 ( V_1 , V_12 , V_3 ) ;
F_7 ( 6000 , 7000 ) ;
V_3 = F_1 ( V_1 , V_21 ) ;
V_3 &= ~ V_25 ;
F_3 ( V_1 , V_21 , V_3 ) ;
V_11 = 50 ;
do {
F_7 ( 1000 , 2000 ) ;
V_3 = F_1 ( V_1 , V_21 ) ;
V_11 -- ;
} while ( V_11 &&
( V_3 & ( V_26 | V_27 ) ) );
V_11 = 50 ;
do {
F_7 ( 1000 , 2000 ) ;
V_3 = F_8 ( V_1 -> V_28 + V_29 ) ;
V_11 -- ;
} while ( V_11 && ! ( V_3 & V_30 ) );
V_3 = F_1 ( V_1 , V_12 ) ;
V_3 &= ~ V_13 ;
F_3 ( V_1 , V_12 , V_3 ) ;
F_7 ( 100 , 200 ) ;
F_9 ( V_8 , V_31 , V_32 ) ;
F_10 ( V_10 ) ;
V_3 = F_1 ( V_1 , V_12 ) ;
V_3 |= V_33 ;
F_3 ( V_1 , V_12 , V_3 ) ;
if ( ! F_11 ( V_8 ) )
return 0 ;
F_12 ( V_8 -> V_34 , L_1 ,
F_13 ( V_8 , V_35 ) ,
F_13 ( V_8 , V_36 ) ) ;
return - V_37 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
if ( F_15 ( V_38 ) )
F_16 ( V_10 ) ;
}
static void F_17 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = F_18 ( V_10 ) ;
struct V_1 * V_1 = F_19 ( V_8 ) ;
F_6 ( V_1 ) ;
F_14 ( V_1 ) ;
}
static T_3 F_20 ( int V_39 , void * V_40 )
{
struct V_1 * V_1 = V_40 ;
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
return F_21 ( V_10 ) ;
}
static int F_22 ( struct V_1 * V_1 ,
struct V_41 * V_42 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_43 * V_34 = V_8 -> V_34 ;
int V_44 ;
if ( F_15 ( V_38 ) ) {
V_10 -> V_45 = F_23 ( V_42 , L_2 ) ;
if ( V_10 -> V_45 <= 0 ) {
F_24 ( V_34 , L_3 ) ;
return - V_46 ;
}
V_44 = F_25 ( V_34 , V_10 -> V_45 ,
F_20 ,
V_47 | V_48 ,
L_4 , V_1 ) ;
if ( V_44 ) {
F_24 ( V_34 , L_5 ) ;
return V_44 ;
}
}
V_10 -> V_49 = - 1 ;
V_10 -> V_50 = & V_51 ;
V_44 = F_26 ( V_10 ) ;
if ( V_44 ) {
F_24 ( V_34 , L_6 ) ;
return V_44 ;
}
return 0 ;
}
static int F_27 ( struct V_41 * V_42 )
{
struct V_43 * V_34 = & V_42 -> V_34 ;
struct V_7 * V_8 ;
struct V_1 * V_1 ;
struct V_52 * V_53 ;
struct V_52 * V_28 ;
int V_44 ;
V_1 = F_28 ( V_34 , sizeof( * V_1 ) , V_54 ) ;
if ( ! V_1 )
return - V_55 ;
V_8 = F_28 ( V_34 , sizeof( * V_8 ) , V_54 ) ;
if ( ! V_8 )
return - V_55 ;
V_8 -> V_34 = V_34 ;
V_8 -> V_50 = & V_56 ;
V_1 -> V_8 = V_8 ;
V_53 = F_29 ( V_42 , V_57 , L_7 ) ;
V_8 -> V_53 = F_30 ( V_34 , V_53 ) ;
if ( F_31 ( V_8 -> V_53 ) )
return F_32 ( V_8 -> V_53 ) ;
V_28 = F_29 ( V_42 , V_57 , L_8 ) ;
V_1 -> V_28 = F_30 ( V_34 , V_28 ) ;
if ( F_31 ( V_1 -> V_28 ) )
return F_32 ( V_1 -> V_28 ) ;
V_1 -> V_4 =
F_33 ( V_34 -> V_58 ,
L_9 ) ;
if ( F_31 ( V_1 -> V_4 ) )
return F_32 ( V_1 -> V_4 ) ;
F_34 ( V_42 , V_1 ) ;
V_44 = F_22 ( V_1 , V_42 ) ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
}
