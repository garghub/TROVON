static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_4 ;
unsigned int V_5 ;
F_3 ( V_3 -> V_6 , V_7 , & V_4 ) ;
V_4 |= V_8 ;
F_4 ( V_3 -> V_6 , V_7 , V_4 ) ;
F_3 ( V_3 -> V_6 , V_7 , & V_4 ) ;
V_4 |= V_9 |
V_10 |
V_11 |
V_12 ;
V_4 |= V_13 ;
V_4 &= ~ V_14 ;
V_4 &= ~ V_15 ;
F_4 ( V_3 -> V_6 , V_7 , V_4 ) ;
F_5 ( 5000 , 6000 ) ;
F_3 ( V_3 -> V_6 , V_16 , & V_4 ) ;
V_4 |= V_17 ;
F_4 ( V_3 -> V_6 , V_16 , V_4 ) ;
F_5 ( 20 , 30 ) ;
F_3 ( V_3 -> V_6 , V_7 , & V_4 ) ;
V_4 |= V_18 | V_19 ;
F_4 ( V_3 -> V_6 , V_7 , V_4 ) ;
F_5 ( 6000 , 7000 ) ;
F_3 ( V_3 -> V_6 , V_16 , & V_4 ) ;
V_4 &= ~ V_20 ;
F_4 ( V_3 -> V_6 , V_16 , V_4 ) ;
V_5 = 50 ;
do {
F_5 ( 1000 , 2000 ) ;
F_3 ( V_3 -> V_6 , V_16 , & V_4 ) ;
V_5 -- ;
} while ( V_5 &&
( V_4 & ( V_21 | V_22 ) ) );
V_5 = 50 ;
do {
F_5 ( 1000 , 2000 ) ;
V_4 = F_6 ( V_3 -> V_23 + V_24 ) ;
V_5 -- ;
} while ( V_5 && ! ( V_4 & V_25 ) );
F_3 ( V_3 -> V_6 , V_7 , & V_4 ) ;
V_4 &= ~ V_8 ;
F_4 ( V_3 -> V_6 , V_7 , V_4 ) ;
F_5 ( 100 , 200 ) ;
F_7 ( V_26 , V_2 -> V_27 + V_28 ) ;
V_2 -> V_29 &= V_30 ;
V_2 -> V_31 &= V_30 ;
V_2 -> V_32 &= V_30 ;
V_2 -> V_33 &= V_30 ;
F_8 ( V_2 ) ;
F_3 ( V_3 -> V_6 , V_7 , & V_4 ) ;
V_4 |= V_34 ;
F_4 ( V_3 -> V_6 , V_7 , V_4 ) ;
if ( ! F_9 ( V_2 ) )
return 0 ;
F_10 ( V_2 -> V_35 , L_1 ,
F_6 ( V_2 -> V_27 + V_36 ) ,
F_6 ( V_2 -> V_27 + V_37 ) ) ;
return - V_38 ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_39 ) )
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_40 ;
V_40 = F_6 ( V_2 -> V_27 + V_37 ) & ( 0x1 << ( 36 - 32 ) ) ;
if ( V_40 )
return 1 ;
return 0 ;
}
static T_2 F_16 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
return F_17 ( V_2 ) ;
}
static int T_3 F_18 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
int V_45 ;
if ( F_12 ( V_39 ) ) {
V_2 -> V_46 = F_19 ( V_44 , L_2 ) ;
if ( V_2 -> V_46 <= 0 ) {
F_20 ( & V_44 -> V_35 , L_3 ) ;
return - V_47 ;
}
V_45 = F_21 ( & V_44 -> V_35 , V_2 -> V_46 ,
F_16 ,
V_48 | V_49 ,
L_4 , V_2 ) ;
if ( V_45 ) {
F_20 ( & V_44 -> V_35 , L_5 ) ;
return V_45 ;
}
}
V_2 -> V_50 = - 1 ;
V_2 -> V_51 = & V_52 ;
V_45 = F_22 ( V_2 ) ;
if ( V_45 ) {
F_20 ( & V_44 -> V_35 , L_6 ) ;
return V_45 ;
}
return 0 ;
}
static int F_23 ( struct V_43 * V_44 )
{
struct V_3 * V_3 ;
struct V_1 * V_2 ;
struct V_53 * V_27 ;
struct V_53 * V_23 ;
int V_45 ;
V_3 = F_24 ( & V_44 -> V_35 , sizeof( * V_3 ) ,
V_54 ) ;
if ( ! V_3 )
return - V_55 ;
V_2 = & V_3 -> V_2 ;
V_2 -> V_35 = & V_44 -> V_35 ;
V_27 = F_25 ( V_44 , V_56 , L_7 ) ;
V_2 -> V_27 = F_26 ( & V_44 -> V_35 , V_27 ) ;
if ( F_27 ( V_2 -> V_27 ) )
return F_28 ( V_2 -> V_27 ) ;
V_23 = F_25 ( V_44 , V_56 , L_8 ) ;
V_3 -> V_23 = F_26 ( & V_44 -> V_35 , V_23 ) ;
if ( F_27 ( V_3 -> V_23 ) )
return F_28 ( V_3 -> V_23 ) ;
V_3 -> V_6 =
F_29 ( V_44 -> V_35 . V_57 ,
L_9 ) ;
if ( F_27 ( V_3 -> V_6 ) )
return F_28 ( V_3 -> V_6 ) ;
V_45 = F_18 ( V_2 , V_44 ) ;
if ( V_45 < 0 )
return V_45 ;
F_30 ( V_44 , V_3 ) ;
return 0 ;
}
