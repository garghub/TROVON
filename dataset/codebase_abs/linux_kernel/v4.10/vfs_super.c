static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
V_2 -> V_4 = V_3 ;
return F_2 ( V_2 , V_3 ) ;
}
static void
F_3 ( struct V_1 * V_5 , struct V_6 * V_7 ,
int V_8 , void * V_3 )
{
V_5 -> V_9 = V_10 ;
V_5 -> V_11 = F_4 ( V_7 -> V_12 - 1 ) ;
V_5 -> V_13 = 1 << V_5 -> V_11 ;
V_5 -> V_14 = V_15 ;
if ( F_5 ( V_7 ) ) {
V_5 -> V_16 = & V_17 ;
V_5 -> V_18 = V_19 ;
} else
V_5 -> V_16 = & V_20 ;
V_5 -> V_21 = & V_7 -> V_22 ;
if ( V_7 -> V_23 )
V_5 -> V_21 -> V_24 = ( V_25 * 1024 ) / V_26 ;
V_5 -> V_27 |= V_28 | V_29 | V_30 ;
if ( ! V_7 -> V_23 )
V_5 -> V_27 |= V_31 ;
#ifdef F_6
if ( ( V_7 -> V_8 & V_32 ) == V_33 )
V_5 -> V_27 |= V_34 ;
#endif
F_7 ( V_5 , V_3 ) ;
}
static struct V_35 * F_8 ( struct V_36 * V_37 , int V_8 ,
const char * V_38 , void * V_3 )
{
struct V_1 * V_5 = NULL ;
struct V_39 * V_39 = NULL ;
struct V_35 * V_40 = NULL ;
struct V_6 * V_7 = NULL ;
T_1 V_41 = V_42 | V_43 ;
struct V_44 * V_45 ;
int V_46 = 0 ;
F_9 ( V_47 , L_1 ) ;
V_7 = F_10 ( sizeof( struct V_6 ) , V_48 ) ;
if ( ! V_7 )
return F_11 ( - V_49 ) ;
V_45 = F_12 ( V_7 , V_38 , V_3 ) ;
if ( F_13 ( V_45 ) ) {
V_46 = F_14 ( V_45 ) ;
goto V_50;
}
V_5 = F_15 ( V_37 , NULL , F_1 , V_8 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_46 = F_14 ( V_5 ) ;
goto V_51;
}
F_3 ( V_5 , V_7 , V_8 , V_3 ) ;
if ( V_7 -> V_23 == V_52 || V_7 -> V_23 == V_53 )
V_5 -> V_54 = & V_55 ;
else
V_5 -> V_54 = & V_56 ;
V_39 = F_16 ( V_5 , V_57 | V_41 , 0 ) ;
if ( F_13 ( V_39 ) ) {
V_46 = F_14 ( V_39 ) ;
goto V_58;
}
V_40 = F_17 ( V_39 ) ;
if ( ! V_40 ) {
V_46 = - V_49 ;
goto V_58;
}
V_5 -> V_59 = V_40 ;
if ( F_5 ( V_7 ) ) {
struct V_60 * V_61 = NULL ;
V_61 = F_18 ( V_45 , V_62 ) ;
if ( F_13 ( V_61 ) ) {
V_46 = F_14 ( V_61 ) ;
goto V_58;
}
F_19 ( V_40 ) -> V_63 = F_20 ( & V_61 -> V_64 ) ;
F_21 ( V_61 , F_19 ( V_40 ) ) ;
F_22 ( V_61 ) ;
} else {
struct V_65 * V_61 = NULL ;
V_61 = F_23 ( V_45 ) ;
if ( F_13 ( V_61 ) ) {
V_46 = F_14 ( V_61 ) ;
goto V_58;
}
F_19 ( V_40 ) -> V_63 = F_20 ( & V_61 -> V_64 ) ;
F_24 ( V_61 , F_19 ( V_40 ) , V_5 ) ;
F_25 ( V_61 ) ;
F_22 ( V_61 ) ;
}
V_46 = F_26 ( V_39 , V_45 ) ;
if ( V_46 )
goto V_58;
F_27 ( V_40 , V_45 ) ;
F_9 ( V_47 , L_2 ) ;
return F_28 ( V_5 -> V_59 ) ;
V_51:
F_29 ( V_45 ) ;
F_30 ( V_7 ) ;
V_50:
F_22 ( V_7 ) ;
return F_11 ( V_46 ) ;
V_58:
F_29 ( V_45 ) ;
F_31 ( V_5 ) ;
return F_11 ( V_46 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_4 ;
F_9 ( V_47 , L_3 , V_2 ) ;
F_33 ( V_2 ) ;
F_34 ( V_7 ) ;
F_30 ( V_7 ) ;
F_22 ( V_7 ) ;
V_2 -> V_4 = NULL ;
F_9 ( V_47 , L_4 ) ;
}
static void
F_35 ( struct V_1 * V_5 )
{
struct V_6 * V_7 ;
V_7 = V_5 -> V_4 ;
F_36 ( V_7 ) ;
}
static int F_37 ( struct V_35 * V_35 , struct V_66 * V_67 )
{
struct V_6 * V_7 ;
struct V_44 * V_45 ;
struct V_68 V_69 ;
int V_70 ;
V_45 = F_38 ( V_35 ) ;
if ( F_13 ( V_45 ) ) {
V_70 = F_14 ( V_45 ) ;
goto V_71;
}
V_7 = F_39 ( V_35 ) ;
if ( F_5 ( V_7 ) ) {
V_70 = F_40 ( V_45 , & V_69 ) ;
if ( V_70 == 0 ) {
V_67 -> V_72 = V_69 . type ;
V_67 -> V_73 = V_69 . V_74 ;
V_67 -> V_75 = V_69 . V_76 ;
V_67 -> V_77 = V_69 . V_78 ;
V_67 -> V_79 = V_69 . V_80 ;
V_67 -> V_81 = V_69 . V_82 ;
V_67 -> V_83 = V_69 . V_84 ;
V_67 -> V_85 . V_86 [ 0 ] = V_69 . V_87 & 0xFFFFFFFFUL ;
V_67 -> V_85 . V_86 [ 1 ] = ( V_69 . V_87 >> 32 ) & 0xFFFFFFFFUL ;
V_67 -> V_88 = V_69 . V_89 ;
}
if ( V_70 != - V_90 )
goto V_71;
}
V_70 = F_41 ( V_35 , V_67 ) ;
V_71:
return V_70 ;
}
static int F_42 ( struct V_39 * V_39 )
{
struct V_6 * V_7 ;
V_7 = F_43 ( V_39 ) ;
if ( V_7 -> V_23 == V_52 || V_7 -> V_23 == V_53 )
return F_44 ( V_39 ) ;
return 1 ;
}
static int F_45 ( struct V_39 * V_39 ,
struct V_91 * V_92 )
{
int V_93 ;
struct V_65 V_94 ;
struct V_95 * V_96 ;
F_9 ( V_47 , L_5 , V_97 , V_39 ) ;
V_96 = F_46 ( V_39 ) ;
if ( ! V_96 -> V_98 )
return 0 ;
F_47 ( & V_94 ) ;
V_93 = F_48 ( V_96 -> V_98 , & V_94 ) ;
if ( V_93 < 0 ) {
F_49 ( V_39 , V_99 ) ;
return V_93 ;
}
return 0 ;
}
static int F_50 ( struct V_39 * V_39 ,
struct V_91 * V_92 )
{
int V_93 ;
struct V_95 * V_96 ;
V_96 = F_46 ( V_39 ) ;
F_9 ( V_47 , L_6 ,
V_97 , V_39 , V_96 -> V_98 ) ;
if ( ! V_96 -> V_98 )
return 0 ;
V_93 = F_51 ( V_96 -> V_98 , 0 ) ;
if ( V_93 < 0 ) {
F_49 ( V_39 , V_99 ) ;
return V_93 ;
}
return 0 ;
}
