void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_4 L_1 ) ;
if ( V_3 )
F_2 ( V_4 L_2 , V_3 ) ;
else
F_2 ( V_4 L_3 ) ;
F_2 ( V_4 L_4 ) ;
F_2 ( V_4 L_5 , V_2 -> V_5 ) ;
F_2 ( V_4 L_6 ,
V_2 -> V_6 , V_2 -> V_7 , V_2 -> V_8 ) ;
F_2 ( V_4 L_7 ,
V_2 -> V_9 , V_2 -> V_10 ) ;
F_2 ( V_4 L_8 , V_2 -> V_11 ) ;
}
struct V_1 *
F_3 ( struct V_12 * V_13 , T_2 V_14 , T_1 V_3 )
{
struct V_15 * V_16 ;
T_2 V_17 , V_18 ;
V_17 = V_14 + ( ( V_3 * V_19 ) / V_13 -> V_20 ) ;
V_18 = ( ( V_3 % ( V_13 -> V_20 / V_19 ) ) * V_19 ) ;
V_16 = F_4 ( V_13 , V_17 ) ;
if ( V_16 && F_5 ( V_16 ) ) {
struct V_1 * V_2 ;
struct V_21 * V_22 ;
if ( ! ( V_2 = F_6 ( V_23 , V_24 ) ) )
goto V_25;
V_22 = (struct V_21 * ) ( V_16 -> V_26 + V_18 ) ;
memcpy ( V_2 , V_22 , sizeof( * V_2 ) ) ;
#ifdef F_7
F_1 ( V_2 , V_3 ) ;
#endif
F_8 ( V_16 ) ;
return ( V_2 ) ;
}
V_25:
F_2 ( V_27 L_9 , V_17 ) ;
F_8 ( V_16 ) ;
return NULL ;
}
static struct V_1 *
F_9 ( T_1 V_3 , struct V_28 * V_29 )
{
struct V_30 * V_31 ;
T_2 V_18 ;
V_18 = ( V_3 % ( V_32 / V_19 ) ) * V_19 ;
V_31 = F_10 ( V_29 -> V_33 , V_3 * V_19 / V_32 ) ;
if ( ! F_11 ( V_31 ) ) {
struct V_1 * V_2 ;
struct V_21 * V_22 ;
T_3 V_34 = ( char * ) F_12 ( V_31 ) ;
if ( ! ( V_2 = F_6 ( V_23 , V_24 ) ) )
goto V_25;
V_22 = (struct V_21 * ) ( V_34 + V_18 ) ;
memcpy ( V_2 , V_22 , sizeof( * V_2 ) ) ;
#ifdef F_7
F_1 ( V_2 , V_3 ) ;
#endif
F_13 ( V_31 ) ;
return ( V_2 ) ;
}
F_2 ( V_27 L_10 , V_31 ) ;
return F_14 ( V_31 ) ;
V_25:
F_2 ( V_27 L_11 , ( unsigned long ) V_3 ) ;
F_13 ( V_31 ) ;
return F_15 ( - V_35 ) ;
}
struct V_1 *
F_16 ( struct V_12 * V_13 , T_1 V_3 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_3 , F_17 ( V_13 ) -> V_36 ) ;
return F_11 ( V_2 ) ? NULL : V_2 ;
}
static T_4 T_5
F_18 ( struct V_1 * V_2 )
{
T_5 V_37 = V_2 -> V_5 & ~ V_38 ;
if ( F_19 ( V_2 ) )
V_37 |= V_39 ;
if ( F_20 ( V_2 ) )
V_37 |= V_40 ;
if ( F_21 ( V_2 ) )
V_37 |= V_41 ;
if ( F_22 ( V_2 ) )
V_37 |= V_42 ;
if ( F_23 ( V_2 ) )
V_37 |= V_43 ;
if ( F_24 ( V_2 ) )
V_37 |= V_44 ;
if ( F_25 ( V_2 ) )
V_37 |= V_45 ;
return ( V_37 ) ;
}
static void
F_26 ( struct V_28 * V_46 , struct V_1 * V_2 )
{
V_46 -> V_47 = F_18 ( V_2 ) ;
V_46 -> V_48 = ( V_49 ) V_2 -> V_7 ;
V_46 -> V_50 = ( V_51 ) V_2 -> V_8 ;
V_46 -> V_52 = V_2 -> V_6 ;
V_46 -> V_53 = V_2 -> V_9 ;
V_46 -> V_54 . V_55 = V_2 -> V_56 ;
V_46 -> V_57 . V_55 = V_2 -> V_58 ;
V_46 -> V_59 . V_55 = V_2 -> V_60 ;
V_46 -> V_54 . V_61 = 0 ;
V_46 -> V_57 . V_61 = 0 ;
V_46 -> V_59 . V_61 = 0 ;
V_46 -> V_62 = V_2 -> V_10 ;
V_46 -> V_63 = V_2 -> V_64 ;
V_46 -> V_65 = V_2 ;
}
struct V_28 *
F_27 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_28 * V_46 = NULL ;
if ( ( V_46 = F_28 ( V_13 ) ) ) {
V_46 -> V_66 = F_29 () ;
F_26 ( V_46 , V_2 ) ;
V_46 -> V_33 -> V_67 = & V_68 ;
}
return ( V_46 ) ;
}
void
F_30 ( struct V_28 * V_46 )
{
F_31 ( V_46 ) ;
}
struct V_28 *
F_32 ( struct V_12 * V_13 , T_1 V_3 )
{
struct V_1 * V_2 ;
const struct V_69 * V_70 ;
struct V_28 * V_46 ;
V_46 = F_33 ( V_13 , V_3 ) ;
if ( ! V_46 )
return F_15 ( - V_35 ) ;
if ( ! ( V_46 -> V_71 & V_72 ) )
return V_46 ;
V_2 = F_9 ( V_3 , F_17 ( V_13 ) -> V_73 ) ;
if ( F_11 ( V_2 ) ) {
F_34 ( V_46 ) ;
return F_14 ( V_2 ) ;
}
F_26 ( V_46 , V_2 ) ;
if ( F_35 ( V_2 ) )
V_70 = & V_74 ;
else
V_70 = & V_68 ;
if ( F_36 ( V_46 -> V_47 ) ) {
V_46 -> V_75 = & V_76 ;
V_46 -> V_33 -> V_67 = V_70 ;
} else if ( F_37 ( V_46 -> V_47 ) ) {
V_46 -> V_77 = & V_78 ;
V_46 -> V_75 = & V_79 ;
V_46 -> V_33 -> V_67 = V_70 ;
} else if ( F_38 ( V_46 -> V_47 ) ) {
if ( ! F_35 ( V_2 ) ) {
V_46 -> V_77 = & V_80 ;
V_46 -> V_33 -> V_67 = & V_68 ;
} else {
V_46 -> V_77 = & V_81 ;
V_2 -> V_82 . V_83 [ V_46 -> V_53 ] = '\0' ;
}
} else
F_39 ( V_46 , V_46 -> V_47 , F_40 ( V_2 -> V_84 ) ) ;
F_41 ( V_46 ) ;
return V_46 ;
}
static void F_42 ( struct V_85 * V_86 )
{
struct V_28 * V_28 = F_43 ( V_86 , struct V_28 , V_87 ) ;
F_44 ( & V_28 -> V_88 ) ;
F_45 ( V_23 , V_28 -> V_65 ) ;
}
void
F_46 ( struct V_28 * V_46 )
{
F_47 ( & V_46 -> V_89 , 0 ) ;
F_48 ( V_46 ) ;
F_49 ( & V_46 -> V_87 , F_42 ) ;
}
