static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_6 != V_2 -> V_7 -> V_8 )
return false ;
V_2 -> V_9 = V_5 ;
return true ;
}
static int F_2 ( struct V_10 * V_11 )
{
struct V_12 * V_6 ;
struct V_4 * V_13 = V_11 -> V_14 ;
struct V_4 * V_15 = V_11 -> V_16 ;
T_1 V_17 ;
V_6 = F_3 ( V_18 , 0x0827 , NULL ) ;
if ( ! V_6 )
return - V_19 ;
F_4 ( V_17 ) ;
F_5 ( V_20 , V_17 ) ;
V_15 -> V_6 = & V_6 -> V_8 ;
V_11 -> V_21 = F_6 ( V_17 , F_1 , V_15 ) ;
if ( ! V_11 -> V_21 )
goto V_22;
V_11 -> V_23 -> V_16 = V_11 -> V_21 ;
V_13 -> V_6 = & V_6 -> V_8 ;
V_11 -> V_24 = F_6 ( V_17 , F_1 , V_13 ) ;
if ( ! V_11 -> V_24 )
goto V_25;
V_11 -> V_23 -> V_14 = V_11 -> V_24 ;
V_11 -> V_26 = 1 ;
return 0 ;
V_25:
F_7 ( V_11 -> V_21 ) ;
V_22:
return - V_27 ;
}
static void F_8 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_26 )
return;
F_9 ( V_11 -> V_24 ) ;
F_7 ( V_11 -> V_24 ) ;
F_9 ( V_11 -> V_21 ) ;
F_7 ( V_11 -> V_21 ) ;
}
static T_2 F_10 ( struct V_10 * V_11 )
{
T_3 V_28 = F_11 ( V_11 , V_29 ) ;
if ( ! V_28 )
return V_30 ;
F_11 ( V_11 , V_31 ) ;
F_12 ( V_11 ) ;
F_13 ( & V_11 -> V_23 -> V_8 , L_1 , V_32 ) ;
V_11 -> V_23 -> V_33 -> V_34 = - V_35 ;
F_14 ( V_11 -> V_23 ) ;
return V_36 ;
}
static bool F_15 ( struct V_37 * V_23 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_10 * V_11 = F_16 ( V_23 ) ;
if ( ! V_11 -> V_26 )
return false ;
return V_41 -> V_42 > V_11 -> V_43 ;
}
static enum V_44 F_17 ( T_4 V_45 ) {
if ( V_45 == 1 )
return V_46 ;
else if ( V_45 == 2 )
return V_47 ;
return V_48 ;
}
static void F_18 ( void * V_49 )
{
struct V_10 * V_11 = V_49 ;
F_19 ( V_50 , & V_11 -> V_51 ) ;
if ( F_20 ( V_52 , & V_11 -> V_51 ) )
return;
F_14 ( V_11 -> V_23 ) ;
}
static struct V_53 * F_21 ( struct V_10 * V_11 ,
struct V_40 * V_41 )
{
struct V_54 V_55 ;
struct V_53 * V_56 ;
if ( ! V_41 -> V_57 )
return NULL ;
V_55 . V_58 = V_59 ;
V_55 . V_60 = V_11 -> V_61 ;
V_55 . V_62 = 16 ;
V_55 . V_63 = V_64 ;
V_55 . V_65 = F_17 ( V_11 -> V_45 ) ;
V_55 . V_66 = false ;
F_22 ( V_11 -> V_24 , & V_55 ) ;
V_56 = F_23 ( V_11 -> V_24 ,
V_41 -> V_67 . V_68 ,
V_41 -> V_67 . V_69 ,
V_59 ,
V_70 | V_71 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_72 = F_18 ;
V_56 -> V_73 = V_11 ;
return V_56 ;
}
static void F_24 ( void * V_49 )
{
struct V_10 * V_11 = V_49 ;
F_19 ( V_52 , & V_11 -> V_51 ) ;
if ( F_20 ( V_50 , & V_11 -> V_51 ) )
return;
F_14 ( V_11 -> V_23 ) ;
}
static struct V_53 * F_25 ( struct V_10 * V_11 ,
struct V_40 * V_41 )
{
struct V_54 V_74 ;
struct V_53 * V_75 ;
if ( ! V_41 -> V_76 )
return NULL ;
V_74 . V_58 = V_77 ;
V_74 . V_78 = V_11 -> V_61 ;
V_74 . V_79 = 16 ;
V_74 . V_65 = V_64 ;
V_74 . V_63 = F_17 ( V_11 -> V_45 ) ;
V_74 . V_66 = false ;
F_22 ( V_11 -> V_21 , & V_74 ) ;
V_75 = F_23 ( V_11 -> V_21 ,
V_41 -> V_80 . V_68 ,
V_41 -> V_80 . V_69 ,
V_77 ,
V_70 | V_71 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> V_72 = F_24 ;
V_75 -> V_73 = V_11 ;
return V_75 ;
}
static int F_26 ( struct V_10 * V_11 , struct V_40 * V_41 )
{
T_3 V_81 = 0 ;
F_27 ( V_11 , V_82 , 0xf ) ;
F_27 ( V_11 , V_83 , 0x10 ) ;
if ( V_41 -> V_57 )
V_81 |= V_84 ;
if ( V_41 -> V_76 )
V_81 |= V_85 ;
F_27 ( V_11 , V_86 , V_81 ) ;
F_28 ( V_11 , V_87 | V_88 | V_89 ) ;
V_11 -> V_90 = F_10 ;
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , struct V_40 * V_41 )
{
struct V_53 * V_56 , * V_75 ;
V_56 = F_21 ( V_11 , V_41 ) ;
V_75 = F_25 ( V_11 , V_41 ) ;
if ( V_75 ) {
F_30 ( V_52 , & V_11 -> V_51 ) ;
F_31 ( V_75 ) ;
F_32 ( V_11 -> V_21 ) ;
}
if ( V_56 ) {
F_30 ( V_50 , & V_11 -> V_51 ) ;
F_31 ( V_56 ) ;
F_32 ( V_11 -> V_24 ) ;
}
return 0 ;
}
static void F_33 ( struct V_10 * V_11 )
{
if ( F_20 ( V_50 , & V_11 -> V_51 ) ) {
F_9 ( V_11 -> V_24 ) ;
F_19 ( V_50 , & V_11 -> V_51 ) ;
}
if ( F_20 ( V_52 , & V_11 -> V_51 ) ) {
F_9 ( V_11 -> V_21 ) ;
F_19 ( V_52 , & V_11 -> V_51 ) ;
}
}
int F_34 ( struct V_10 * V_11 )
{
void T_5 * V_91 ;
T_4 V_92 ;
V_91 = F_35 ( V_93 , 16 ) ;
if ( ! V_91 )
return - V_94 ;
V_92 = F_36 ( V_91 + V_11 -> V_95 * sizeof( T_4 ) ) ;
V_92 &= V_96 ;
V_92 >>= V_97 ;
V_11 -> V_98 = V_99 / ( V_92 + 1 ) ;
F_37 ( V_91 ) ;
#ifdef F_38
V_11 -> V_14 = & V_100 ;
V_11 -> V_16 = & V_101 ;
V_11 -> V_102 = & V_103 ;
#endif
return 0 ;
}
