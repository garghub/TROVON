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
static T_2 T_3
F_3 ( struct V_1 * V_2 )
{
T_3 V_12 = V_2 -> V_5 & ~ V_13 ;
if ( F_4 ( V_2 ) )
V_12 |= V_14 ;
if ( F_5 ( V_2 ) )
V_12 |= V_15 ;
if ( F_6 ( V_2 ) )
V_12 |= V_16 ;
if ( F_7 ( V_2 ) )
V_12 |= V_17 ;
if ( F_8 ( V_2 ) )
V_12 |= V_18 ;
if ( F_9 ( V_2 ) )
V_12 |= V_19 ;
if ( F_10 ( V_2 ) )
V_12 |= V_20 ;
return ( V_12 ) ;
}
static inline void F_11 ( struct V_21 * V_22 ,
struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_25 * V_25 = & V_2 -> V_26 ;
V_2 -> V_5 = F_12 ( V_22 , V_24 -> V_27 ) ;
V_2 -> V_6 = F_12 ( V_22 , V_24 -> V_28 ) ;
V_2 -> V_7 = F_12 ( V_22 , V_24 -> V_29 ) ;
V_2 -> V_8 = F_12 ( V_22 , V_24 -> V_30 ) ;
V_2 -> V_9 = F_13 ( V_22 , V_24 -> V_31 ) ;
V_2 -> V_32 = F_12 ( V_22 , V_24 -> V_33 ) ;
V_2 -> V_34 = F_12 ( V_22 , V_24 -> V_35 ) ;
V_2 -> V_36 = F_12 ( V_22 , V_24 -> V_37 ) ;
V_2 -> V_38 = F_12 ( V_22 , V_24 -> V_39 ) ;
V_2 -> V_40 = F_12 ( V_22 , V_24 -> V_41 ) ;
V_2 -> V_42 = F_12 ( V_22 , V_24 -> V_43 ) ;
V_2 -> V_11 = V_24 -> V_44 ;
V_2 -> V_10 = F_12 ( V_22 , V_24 -> V_45 ) ;
V_2 -> V_46 = F_12 ( V_22 , V_24 -> V_47 ) ;
if ( F_6 ( V_2 ) )
V_2 -> V_48 = F_12 ( V_22 , V_24 -> V_49 ) ;
else if ( ! F_9 ( V_2 ) && ! F_8 ( V_2 ) )
V_2 -> V_50 = F_12 ( V_22 , V_24 -> V_51 ) ;
memcpy ( & V_2 -> V_52 , & V_24 -> V_53 , sizeof( V_2 -> V_52 ) ) ;
V_25 -> V_54 = F_3 ( V_2 ) ;
F_14 ( V_25 , ( V_55 ) V_2 -> V_7 ) ;
F_15 ( V_25 , ( V_56 ) V_2 -> V_8 ) ;
F_16 ( V_25 , V_2 -> V_6 ) ;
V_25 -> V_57 = V_2 -> V_9 ;
V_25 -> V_58 . V_59 = V_2 -> V_32 ;
V_25 -> V_60 . V_59 = V_2 -> V_40 ;
V_25 -> V_61 . V_59 = V_2 -> V_36 ;
V_25 -> V_58 . V_62 = 0 ;
V_25 -> V_60 . V_62 = 0 ;
V_25 -> V_61 . V_62 = 0 ;
V_25 -> V_63 = V_2 -> V_10 ;
V_25 -> V_64 = V_2 -> V_46 ;
}
struct V_25 *
F_17 ( struct V_65 * V_66 , T_4 V_67 , T_1 V_3 )
{
struct V_68 * V_69 ;
struct V_25 * V_25 ;
T_4 V_70 , V_71 ;
V_25 = F_18 ( V_66 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_72 = F_19 () ;
V_70 = V_67 + ( ( V_3 * V_73 ) / V_66 -> V_74 ) ;
V_71 = ( ( V_3 % ( V_66 -> V_74 / V_73 ) ) * V_73 ) ;
V_69 = F_20 ( V_66 , V_70 ) ;
if ( V_69 && F_21 ( V_69 ) ) {
struct V_1 * V_2 = F_22 ( V_25 ) ;
struct V_23 * V_24 ;
V_24 = (struct V_23 * ) ( V_69 -> V_75 + V_71 ) ;
F_11 ( F_23 ( V_66 ) , V_2 , V_24 ) ;
V_2 -> V_26 . V_76 -> V_77 = & V_78 ;
#ifdef F_24
F_1 ( V_2 , V_3 ) ;
#endif
F_25 ( V_69 ) ;
return V_25 ;
}
F_2 ( V_79 L_9 , V_70 ) ;
F_25 ( V_69 ) ;
F_26 ( V_25 ) ;
return NULL ;
}
static int
F_27 ( struct V_25 * V_80 , struct V_1 * V_2 , T_1 V_3 )
{
struct V_81 * V_82 ;
T_4 V_71 ;
V_71 = ( V_3 % ( V_83 / V_73 ) ) * V_73 ;
V_82 = F_28 ( V_80 -> V_76 , V_3 * V_73 / V_83 ) ;
if ( ! F_29 ( V_82 ) ) {
struct V_23 * V_24 ;
T_5 V_84 = ( char * ) F_30 ( V_82 ) ;
V_24 = (struct V_23 * ) ( V_84 + V_71 ) ;
F_11 ( F_23 ( V_80 -> V_85 ) , V_2 , V_24 ) ;
V_2 -> V_26 . V_76 -> V_77 = & V_78 ;
#ifdef F_24
F_1 ( V_2 , V_3 ) ;
#endif
F_31 ( V_82 ) ;
return 0 ;
}
F_2 ( V_79 L_10 ,
V_82 , ( unsigned long ) V_3 ) ;
return F_32 ( V_82 ) ;
}
struct V_25 *
F_33 ( struct V_65 * V_66 , T_1 V_3 )
{
struct V_25 * V_25 ;
int error ;
V_25 = F_18 ( V_66 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_72 = F_19 () ;
error = F_27 ( F_23 ( V_66 ) -> V_86 , F_22 ( V_25 ) , V_3 ) ;
if ( error ) {
F_26 ( V_25 ) ;
return NULL ;
}
return V_25 ;
}
struct V_25 *
F_34 ( struct V_65 * V_66 , T_1 V_3 )
{
struct V_1 * V_2 ;
const struct V_87 * V_88 ;
struct V_25 * V_89 ;
int error ;
V_89 = F_35 ( V_66 , V_3 ) ;
if ( ! V_89 )
return F_36 ( - V_90 ) ;
if ( ! ( V_89 -> V_91 & V_92 ) )
return V_89 ;
V_2 = F_22 ( V_89 ) ;
error = F_27 ( F_23 ( V_66 ) -> V_93 , V_2 , V_3 ) ;
if ( error ) {
F_37 ( V_89 ) ;
return F_36 ( error ) ;
}
if ( F_38 ( V_2 ) )
V_88 = & V_94 ;
else
V_88 = & V_78 ;
if ( F_39 ( V_89 -> V_54 ) ) {
V_89 -> V_95 = & V_96 ;
V_89 -> V_76 -> V_77 = V_88 ;
} else if ( F_40 ( V_89 -> V_54 ) ) {
V_89 -> V_97 = & V_98 ;
V_89 -> V_95 = & V_99 ;
V_89 -> V_76 -> V_77 = V_88 ;
} else if ( F_41 ( V_89 -> V_54 ) ) {
if ( ! F_38 ( V_2 ) ) {
V_89 -> V_97 = & V_100 ;
F_42 ( V_89 ) ;
V_89 -> V_76 -> V_77 = & V_78 ;
} else {
V_89 -> V_97 = & V_101 ;
V_89 -> V_102 = V_2 -> V_103 . V_104 ;
F_43 ( V_89 -> V_102 , V_89 -> V_57 ,
sizeof( V_2 -> V_103 . V_104 ) - 1 ) ;
}
} else
F_44 ( V_89 , V_89 -> V_54 , F_45 ( V_2 -> V_50 ) ) ;
F_46 ( V_89 ) ;
return V_89 ;
}
void
F_47 ( struct V_25 * V_89 )
{
F_48 ( & V_89 -> V_105 ) ;
F_49 ( V_89 ) ;
}
