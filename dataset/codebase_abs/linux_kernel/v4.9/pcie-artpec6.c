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
struct V_5 * V_6 = & V_1 -> V_6 ;
T_1 V_3 ;
unsigned int V_7 ;
V_3 = F_1 ( V_1 , V_8 ) ;
V_3 |= V_9 ;
F_3 ( V_1 , V_8 , V_3 ) ;
V_3 = F_1 ( V_1 , V_8 ) ;
V_3 |= V_10 |
V_11 |
V_12 |
V_13 ;
V_3 |= V_14 ;
V_3 &= ~ V_15 ;
V_3 &= ~ V_16 ;
F_3 ( V_1 , V_8 , V_3 ) ;
F_6 ( 5000 , 6000 ) ;
V_3 = F_1 ( V_1 , V_17 ) ;
V_3 |= V_18 ;
F_3 ( V_1 , V_17 , V_3 ) ;
F_6 ( 20 , 30 ) ;
V_3 = F_1 ( V_1 , V_8 ) ;
V_3 |= V_19 | V_20 ;
F_3 ( V_1 , V_8 , V_3 ) ;
F_6 ( 6000 , 7000 ) ;
V_3 = F_1 ( V_1 , V_17 ) ;
V_3 &= ~ V_21 ;
F_3 ( V_1 , V_17 , V_3 ) ;
V_7 = 50 ;
do {
F_6 ( 1000 , 2000 ) ;
V_3 = F_1 ( V_1 , V_17 ) ;
V_7 -- ;
} while ( V_7 &&
( V_3 & ( V_22 | V_23 ) ) );
V_7 = 50 ;
do {
F_6 ( 1000 , 2000 ) ;
V_3 = F_7 ( V_1 -> V_24 + V_25 ) ;
V_7 -- ;
} while ( V_7 && ! ( V_3 & V_26 ) );
V_3 = F_1 ( V_1 , V_8 ) ;
V_3 &= ~ V_9 ;
F_3 ( V_1 , V_8 , V_3 ) ;
F_6 ( 100 , 200 ) ;
F_8 ( V_6 , V_27 , V_28 ) ;
V_6 -> V_29 &= V_30 ;
V_6 -> V_31 &= V_30 ;
V_6 -> V_32 &= V_30 ;
V_6 -> V_33 &= V_30 ;
F_9 ( V_6 ) ;
V_3 = F_1 ( V_1 , V_8 ) ;
V_3 |= V_34 ;
F_3 ( V_1 , V_8 , V_3 ) ;
if ( ! F_10 ( V_6 ) )
return 0 ;
F_11 ( V_6 -> V_35 , L_1 ,
F_12 ( V_6 , V_36 ) ,
F_12 ( V_6 , V_37 ) ) ;
return - V_38 ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = & V_1 -> V_6 ;
if ( F_14 ( V_39 ) )
F_15 ( V_6 ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_17 ( V_6 ) ;
F_5 ( V_1 ) ;
F_13 ( V_1 ) ;
}
static T_2 F_18 ( int V_40 , void * V_41 )
{
struct V_1 * V_1 = V_41 ;
struct V_5 * V_6 = & V_1 -> V_6 ;
return F_19 ( V_6 ) ;
}
static int F_20 ( struct V_1 * V_1 ,
struct V_42 * V_43 )
{
struct V_5 * V_6 = & V_1 -> V_6 ;
struct V_44 * V_35 = V_6 -> V_35 ;
int V_45 ;
if ( F_14 ( V_39 ) ) {
V_6 -> V_46 = F_21 ( V_43 , L_2 ) ;
if ( V_6 -> V_46 <= 0 ) {
F_22 ( V_35 , L_3 ) ;
return - V_47 ;
}
V_45 = F_23 ( V_35 , V_6 -> V_46 ,
F_18 ,
V_48 | V_49 ,
L_4 , V_1 ) ;
if ( V_45 ) {
F_22 ( V_35 , L_5 ) ;
return V_45 ;
}
}
V_6 -> V_50 = - 1 ;
V_6 -> V_51 = & V_52 ;
V_45 = F_24 ( V_6 ) ;
if ( V_45 ) {
F_22 ( V_35 , L_6 ) ;
return V_45 ;
}
return 0 ;
}
static int F_25 ( struct V_42 * V_43 )
{
struct V_44 * V_35 = & V_43 -> V_35 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
struct V_53 * V_54 ;
struct V_53 * V_24 ;
int V_45 ;
V_1 = F_26 ( V_35 , sizeof( * V_1 ) , V_55 ) ;
if ( ! V_1 )
return - V_56 ;
V_6 = & V_1 -> V_6 ;
V_6 -> V_35 = V_35 ;
V_54 = F_27 ( V_43 , V_57 , L_7 ) ;
V_6 -> V_54 = F_28 ( V_35 , V_54 ) ;
if ( F_29 ( V_6 -> V_54 ) )
return F_30 ( V_6 -> V_54 ) ;
V_24 = F_27 ( V_43 , V_57 , L_8 ) ;
V_1 -> V_24 = F_28 ( V_35 , V_24 ) ;
if ( F_29 ( V_1 -> V_24 ) )
return F_30 ( V_1 -> V_24 ) ;
V_1 -> V_4 =
F_31 ( V_35 -> V_58 ,
L_9 ) ;
if ( F_29 ( V_1 -> V_4 ) )
return F_30 ( V_1 -> V_4 ) ;
V_45 = F_20 ( V_1 , V_43 ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
