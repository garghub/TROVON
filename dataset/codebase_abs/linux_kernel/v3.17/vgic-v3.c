static struct V_1 F_1 ( const struct V_2 * V_3 , int V_4 )
{
struct V_1 V_5 ;
T_1 V_6 = V_3 -> V_7 . V_8 . V_9 . V_1 [ F_2 ( V_4 ) ] ;
V_5 . V_10 = V_6 & V_11 ;
if ( V_5 . V_10 <= 15 )
V_5 . V_12 = ( V_6 >> V_13 ) & 0x7 ;
else
V_5 . V_12 = 0 ;
V_5 . V_14 = 0 ;
if ( V_6 & V_15 )
V_5 . V_14 |= V_16 ;
if ( V_6 & V_17 )
V_5 . V_14 |= V_18 ;
if ( V_6 & V_19 )
V_5 . V_14 |= V_20 ;
return V_5 ;
}
static void F_3 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
T_1 V_21 = ( ( ( V_22 ) V_5 . V_12 << V_13 ) |
V_5 . V_10 ) ;
if ( V_5 . V_14 & V_16 )
V_21 |= V_15 ;
if ( V_5 . V_14 & V_18 )
V_21 |= V_17 ;
if ( V_5 . V_14 & V_20 )
V_21 |= V_19 ;
V_3 -> V_7 . V_8 . V_9 . V_1 [ F_2 ( V_4 ) ] = V_21 ;
}
static void F_4 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
if ( ! ( V_5 . V_14 & V_23 ) )
V_3 -> V_7 . V_8 . V_9 . V_24 |= ( 1U << V_4 ) ;
}
static T_1 F_5 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_24 ;
}
static T_1 F_6 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_25 ;
}
static V_22 F_7 ( const struct V_2 * V_3 )
{
V_22 V_26 = V_3 -> V_7 . V_8 . V_9 . V_27 ;
V_22 V_28 = 0 ;
if ( V_26 & V_29 )
V_28 |= V_30 ;
if ( V_26 & V_31 )
V_28 |= V_32 ;
return V_28 ;
}
static void F_8 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
V_22 V_35 = V_3 -> V_7 . V_8 . V_9 . V_33 ;
V_34 -> V_36 = ( V_35 & V_37 ) >> V_38 ;
V_34 -> V_39 = ( V_35 & V_40 ) >> V_41 ;
V_34 -> V_42 = ( V_35 & V_43 ) >> V_44 ;
V_34 -> V_45 = ( V_35 & V_46 ) >> V_47 ;
}
static void F_9 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_48 |= V_49 ;
}
static void F_10 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_48 &= ~ V_49 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
V_22 V_35 ;
V_35 = ( V_34 -> V_36 << V_38 ) & V_37 ;
V_35 |= ( V_34 -> V_39 << V_41 ) & V_40 ;
V_35 |= ( V_34 -> V_42 << V_44 ) & V_43 ;
V_35 |= ( V_34 -> V_45 << V_47 ) & V_46 ;
V_3 -> V_7 . V_8 . V_9 . V_33 = V_35 ;
}
static void F_12 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_33 = 0 ;
V_3 -> V_7 . V_8 . V_9 . V_48 = V_50 ;
}
int F_13 ( struct V_51 * V_52 ,
const struct V_53 * * V_54 ,
const struct V_55 * * V_56 )
{
int V_28 = 0 ;
V_22 V_57 ;
struct V_58 V_59 ;
struct V_55 * V_60 = & V_61 ;
V_60 -> V_62 = F_14 ( V_52 , 0 ) ;
if ( ! V_60 -> V_62 ) {
F_15 ( L_1 ) ;
V_28 = - V_63 ;
goto V_64;
}
V_65 = F_16 ( V_66 ) ;
V_60 -> V_67 = ( V_65 & 0xf ) + 1 ;
if ( F_17 ( V_52 , L_2 , & V_57 ) )
V_57 = 1 ;
V_57 += 3 ;
if ( F_18 ( V_52 , V_57 , & V_59 ) ) {
F_15 ( L_3 ) ;
V_28 = - V_63 ;
goto V_64;
}
if ( ! F_19 ( V_59 . V_68 ) ) {
F_15 ( L_4 ,
( unsigned long long ) V_59 . V_68 ) ;
V_28 = - V_63 ;
goto V_64;
}
if ( ! F_19 ( F_20 ( & V_59 ) ) ) {
F_15 ( L_5 ,
( unsigned long long ) F_20 ( & V_59 ) ,
V_69 ) ;
V_28 = - V_63 ;
goto V_64;
}
V_60 -> V_70 = V_59 . V_68 ;
V_60 -> V_71 = NULL ;
V_60 -> type = V_72 ;
F_21 ( L_6 , V_52 -> V_73 ,
V_59 . V_68 , V_60 -> V_62 ) ;
* V_54 = & V_74 ;
* V_56 = V_60 ;
V_64:
F_22 ( V_52 ) ;
return V_28 ;
}
