static struct V_1 F_1 ( const struct V_2 * V_3 , int V_4 )
{
struct V_1 V_5 ;
T_1 V_6 = V_3 -> V_7 . V_8 . V_9 . V_1 [ V_4 ] ;
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
static void F_2 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
T_1 V_21 = ( V_5 . V_12 << V_13 ) | V_5 . V_10 ;
if ( V_5 . V_14 & V_16 )
V_21 |= V_15 ;
if ( V_5 . V_14 & V_18 )
V_21 |= V_17 ;
if ( V_5 . V_14 & V_20 )
V_21 |= V_19 ;
V_3 -> V_7 . V_8 . V_9 . V_1 [ V_4 ] = V_21 ;
}
static void F_3 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
if ( ! ( V_5 . V_14 & V_22 ) )
V_3 -> V_7 . V_8 . V_9 . V_23 |= ( 1ULL << V_4 ) ;
else
V_3 -> V_7 . V_8 . V_9 . V_23 &= ~ ( 1ULL << V_4 ) ;
}
static T_2 F_4 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_23 ;
}
static T_2 F_5 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_24 ;
}
static void F_6 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_24 = 0 ;
}
static T_1 F_7 ( const struct V_2 * V_3 )
{
T_1 V_25 = V_3 -> V_7 . V_8 . V_9 . V_26 ;
T_1 V_27 = 0 ;
if ( V_25 & V_28 )
V_27 |= V_29 ;
if ( V_25 & V_30 )
V_27 |= V_31 ;
return V_27 ;
}
static void F_8 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_32 |= V_33 ;
}
static void F_9 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_32 &= ~ V_33 ;
}
static void F_10 ( struct V_2 * V_3 , struct V_34 * V_35 )
{
T_1 V_36 = V_3 -> V_7 . V_8 . V_9 . V_34 ;
V_35 -> V_37 = ( V_36 & V_38 ) >> V_39 ;
V_35 -> V_40 = ( V_36 & V_41 ) >> V_42 ;
V_35 -> V_43 = ( V_36 & V_44 ) >> V_45 ;
V_35 -> V_46 = ( V_36 & V_47 ) >> V_48 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_34 * V_35 )
{
T_1 V_36 ;
V_36 = ( V_35 -> V_37 << V_39 ) & V_38 ;
V_36 |= ( V_35 -> V_40 << V_42 ) & V_41 ;
V_36 |= ( V_35 -> V_43 << V_45 ) & V_44 ;
V_36 |= ( V_35 -> V_46 << V_48 ) & V_47 ;
V_3 -> V_7 . V_8 . V_9 . V_34 = V_36 ;
}
static void F_12 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_34 = 0 ;
V_3 -> V_7 . V_8 . V_9 . V_32 = V_49 ;
}
int F_13 ( struct V_50 * V_51 ,
const struct V_52 * * V_53 ,
const struct V_54 * * V_55 )
{
int V_27 ;
struct V_56 V_57 ;
struct V_56 V_58 ;
struct V_54 * V_59 = & V_60 ;
V_59 -> V_61 = F_14 ( V_51 , 0 ) ;
if ( ! V_59 -> V_61 ) {
F_15 ( L_1 ) ;
V_27 = - V_62 ;
goto V_63;
}
V_27 = F_16 ( V_51 , 2 , & V_57 ) ;
if ( V_27 ) {
F_15 ( L_2 ) ;
goto V_63;
}
V_59 -> V_64 = F_17 ( V_51 , 2 ) ;
if ( ! V_59 -> V_64 ) {
F_15 ( L_3 ) ;
V_27 = - V_65 ;
goto V_63;
}
V_59 -> V_66 = F_18 ( V_59 -> V_64 + V_67 ) ;
V_59 -> V_66 = ( V_59 -> V_66 & 0x3f ) + 1 ;
V_27 = F_19 ( V_59 -> V_64 ,
V_59 -> V_64 + F_20 ( & V_57 ) ,
V_57 . V_68 ) ;
if ( V_27 ) {
F_15 ( L_4 ) ;
goto V_69;
}
if ( F_16 ( V_51 , 3 , & V_58 ) ) {
F_15 ( L_5 ) ;
V_27 = - V_62 ;
goto V_69;
}
if ( ! F_21 ( V_58 . V_68 ) ) {
F_15 ( L_6 ,
( unsigned long long ) V_58 . V_68 ) ;
V_27 = - V_62 ;
goto V_69;
}
if ( ! F_21 ( F_20 ( & V_58 ) ) ) {
F_15 ( L_7 ,
( unsigned long long ) F_20 ( & V_58 ) ,
V_70 ) ;
V_27 = - V_62 ;
goto V_69;
}
V_59 -> V_71 = true ;
F_22 ( & V_72 , V_73 ) ;
V_59 -> V_74 = V_58 . V_68 ;
F_23 ( L_8 , V_51 -> V_75 ,
V_57 . V_68 , V_59 -> V_61 ) ;
V_59 -> type = V_76 ;
V_59 -> V_77 = V_78 ;
* V_53 = & V_79 ;
* V_55 = V_59 ;
goto V_63;
V_69:
F_24 ( V_59 -> V_64 ) ;
V_63:
F_25 ( V_51 ) ;
return V_27 ;
}
