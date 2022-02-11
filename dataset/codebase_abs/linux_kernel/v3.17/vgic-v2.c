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
F_4 ( V_4 , ( unsigned long * ) V_3 -> V_7 . V_8 . V_9 . V_23 ) ;
}
static T_2 F_5 ( const struct V_2 * V_3 )
{
T_2 V_6 ;
#if V_24 == 64
V_6 = V_3 -> V_7 . V_8 . V_9 . V_23 [ 1 ] ;
V_6 <<= 32 ;
V_6 |= V_3 -> V_7 . V_8 . V_9 . V_23 [ 0 ] ;
#else
V_6 = * ( T_2 * ) V_3 -> V_7 . V_8 . V_9 . V_23 ;
#endif
return V_6 ;
}
static T_2 F_6 ( const struct V_2 * V_3 )
{
T_2 V_6 ;
#if V_24 == 64
V_6 = V_3 -> V_7 . V_8 . V_9 . V_25 [ 1 ] ;
V_6 <<= 32 ;
V_6 |= V_3 -> V_7 . V_8 . V_9 . V_25 [ 0 ] ;
#else
V_6 = * ( T_2 * ) V_3 -> V_7 . V_8 . V_9 . V_25 ;
#endif
return V_6 ;
}
static T_1 F_7 ( const struct V_2 * V_3 )
{
T_1 V_26 = V_3 -> V_7 . V_8 . V_9 . V_27 ;
T_1 V_28 = 0 ;
if ( V_26 & V_29 )
V_28 |= V_30 ;
if ( V_26 & V_31 )
V_28 |= V_32 ;
return V_28 ;
}
static void F_8 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_33 |= V_34 ;
}
static void F_9 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_33 &= ~ V_34 ;
}
static void F_10 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
T_1 V_37 = V_3 -> V_7 . V_8 . V_9 . V_35 ;
V_36 -> V_38 = ( V_37 & V_39 ) >> V_40 ;
V_36 -> V_41 = ( V_37 & V_42 ) >> V_43 ;
V_36 -> V_44 = ( V_37 & V_45 ) >> V_46 ;
V_36 -> V_47 = ( V_37 & V_48 ) >> V_49 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
T_1 V_37 ;
V_37 = ( V_36 -> V_38 << V_40 ) & V_39 ;
V_37 |= ( V_36 -> V_41 << V_43 ) & V_42 ;
V_37 |= ( V_36 -> V_44 << V_46 ) & V_45 ;
V_37 |= ( V_36 -> V_47 << V_49 ) & V_48 ;
V_3 -> V_7 . V_8 . V_9 . V_35 = V_37 ;
}
static void F_12 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_35 = 0 ;
V_3 -> V_7 . V_8 . V_9 . V_33 = V_50 ;
}
int F_13 ( struct V_51 * V_52 ,
const struct V_53 * * V_54 ,
const struct V_55 * * V_56 )
{
int V_28 ;
struct V_57 V_58 ;
struct V_57 V_59 ;
struct V_55 * V_60 = & V_61 ;
V_60 -> V_62 = F_14 ( V_52 , 0 ) ;
if ( ! V_60 -> V_62 ) {
F_15 ( L_1 ) ;
V_28 = - V_63 ;
goto V_64;
}
V_28 = F_16 ( V_52 , 2 , & V_58 ) ;
if ( V_28 ) {
F_15 ( L_2 ) ;
goto V_64;
}
V_60 -> V_65 = F_17 ( V_52 , 2 ) ;
if ( ! V_60 -> V_65 ) {
F_15 ( L_3 ) ;
V_28 = - V_66 ;
goto V_64;
}
V_60 -> V_67 = F_18 ( V_60 -> V_65 + V_68 ) ;
V_60 -> V_67 = ( V_60 -> V_67 & 0x3f ) + 1 ;
V_28 = F_19 ( V_60 -> V_65 ,
V_60 -> V_65 + F_20 ( & V_58 ) ,
V_58 . V_69 ) ;
if ( V_28 ) {
F_15 ( L_4 ) ;
goto V_70;
}
if ( F_16 ( V_52 , 3 , & V_59 ) ) {
F_15 ( L_5 ) ;
V_28 = - V_63 ;
goto V_70;
}
if ( ! F_21 ( V_59 . V_69 ) ) {
F_15 ( L_6 ,
( unsigned long long ) V_59 . V_69 ) ;
V_28 = - V_63 ;
goto V_70;
}
if ( ! F_21 ( F_20 ( & V_59 ) ) ) {
F_15 ( L_7 ,
( unsigned long long ) F_20 ( & V_59 ) ,
V_71 ) ;
V_28 = - V_63 ;
goto V_70;
}
V_60 -> V_72 = V_59 . V_69 ;
F_22 ( L_8 , V_52 -> V_73 ,
V_58 . V_69 , V_60 -> V_62 ) ;
V_60 -> type = V_74 ;
* V_54 = & V_75 ;
* V_56 = V_60 ;
goto V_64;
V_70:
F_23 ( V_60 -> V_65 ) ;
V_64:
F_24 ( V_52 ) ;
return V_28 ;
}
