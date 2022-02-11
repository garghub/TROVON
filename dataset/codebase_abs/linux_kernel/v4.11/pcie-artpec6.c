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
static int F_5 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
T_1 V_3 ;
unsigned int V_9 ;
V_3 = F_1 ( V_1 , V_10 ) ;
V_3 |= V_11 ;
F_3 ( V_1 , V_10 , V_3 ) ;
V_3 = F_1 ( V_1 , V_10 ) ;
V_3 |= V_12 |
V_13 |
V_14 |
V_15 ;
V_3 |= V_16 ;
V_3 &= ~ V_17 ;
V_3 &= ~ V_18 ;
F_3 ( V_1 , V_10 , V_3 ) ;
F_6 ( 5000 , 6000 ) ;
V_3 = F_1 ( V_1 , V_19 ) ;
V_3 |= V_20 ;
F_3 ( V_1 , V_19 , V_3 ) ;
F_6 ( 20 , 30 ) ;
V_3 = F_1 ( V_1 , V_10 ) ;
V_3 |= V_21 | V_22 ;
F_3 ( V_1 , V_10 , V_3 ) ;
F_6 ( 6000 , 7000 ) ;
V_3 = F_1 ( V_1 , V_19 ) ;
V_3 &= ~ V_23 ;
F_3 ( V_1 , V_19 , V_3 ) ;
V_9 = 50 ;
do {
F_6 ( 1000 , 2000 ) ;
V_3 = F_1 ( V_1 , V_19 ) ;
V_9 -- ;
} while ( V_9 &&
( V_3 & ( V_24 | V_25 ) ) );
V_9 = 50 ;
do {
F_6 ( 1000 , 2000 ) ;
V_3 = F_7 ( V_1 -> V_26 + V_27 ) ;
V_9 -- ;
} while ( V_9 && ! ( V_3 & V_28 ) );
V_3 = F_1 ( V_1 , V_10 ) ;
V_3 &= ~ V_11 ;
F_3 ( V_1 , V_10 , V_3 ) ;
F_6 ( 100 , 200 ) ;
F_8 ( V_6 , V_29 , V_30 ) ;
V_8 -> V_31 &= V_32 ;
V_8 -> V_33 &= V_32 ;
V_8 -> V_34 &= V_32 ;
V_8 -> V_35 &= V_32 ;
F_9 ( V_8 ) ;
V_3 = F_1 ( V_1 , V_10 ) ;
V_3 |= V_36 ;
F_3 ( V_1 , V_10 , V_3 ) ;
if ( ! F_10 ( V_6 ) )
return 0 ;
F_11 ( V_6 -> V_37 , L_1 ,
F_12 ( V_6 , V_38 ) ,
F_12 ( V_6 , V_39 ) ) ;
return - V_40 ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
if ( F_14 ( V_41 ) )
F_15 ( V_8 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = F_17 ( V_8 ) ;
struct V_1 * V_1 = F_18 ( V_6 ) ;
F_5 ( V_1 ) ;
F_13 ( V_1 ) ;
}
static T_2 F_19 ( int V_42 , void * V_43 )
{
struct V_1 * V_1 = V_43 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
return F_20 ( V_8 ) ;
}
static int F_21 ( struct V_1 * V_1 ,
struct V_44 * V_45 )
{
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_46 * V_37 = V_6 -> V_37 ;
int V_47 ;
if ( F_14 ( V_41 ) ) {
V_8 -> V_48 = F_22 ( V_45 , L_2 ) ;
if ( V_8 -> V_48 <= 0 ) {
F_23 ( V_37 , L_3 ) ;
return - V_49 ;
}
V_47 = F_24 ( V_37 , V_8 -> V_48 ,
F_19 ,
V_50 | V_51 ,
L_4 , V_1 ) ;
if ( V_47 ) {
F_23 ( V_37 , L_5 ) ;
return V_47 ;
}
}
V_8 -> V_52 = - 1 ;
V_8 -> V_53 = & V_54 ;
V_47 = F_25 ( V_8 ) ;
if ( V_47 ) {
F_23 ( V_37 , L_6 ) ;
return V_47 ;
}
return 0 ;
}
static int F_26 ( struct V_44 * V_45 )
{
struct V_46 * V_37 = & V_45 -> V_37 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_55 * V_56 ;
struct V_55 * V_26 ;
int V_47 ;
V_1 = F_27 ( V_37 , sizeof( * V_1 ) , V_57 ) ;
if ( ! V_1 )
return - V_58 ;
V_6 = F_27 ( V_37 , sizeof( * V_6 ) , V_57 ) ;
if ( ! V_6 )
return - V_58 ;
V_6 -> V_37 = V_37 ;
V_6 -> V_53 = & V_59 ;
V_1 -> V_6 = V_6 ;
V_56 = F_28 ( V_45 , V_60 , L_7 ) ;
V_6 -> V_56 = F_29 ( V_37 , V_56 ) ;
if ( F_30 ( V_6 -> V_56 ) )
return F_31 ( V_6 -> V_56 ) ;
V_26 = F_28 ( V_45 , V_60 , L_8 ) ;
V_1 -> V_26 = F_29 ( V_37 , V_26 ) ;
if ( F_30 ( V_1 -> V_26 ) )
return F_31 ( V_1 -> V_26 ) ;
V_1 -> V_4 =
F_32 ( V_37 -> V_61 ,
L_9 ) ;
if ( F_30 ( V_1 -> V_4 ) )
return F_31 ( V_1 -> V_4 ) ;
F_33 ( V_45 , V_1 ) ;
V_47 = F_21 ( V_1 , V_45 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
