static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
V_2 -> V_4 = V_3 ;
return F_2 ( V_2 , V_3 ) ;
}
static int
F_3 ( struct V_1 * V_5 , struct V_6 * V_7 ,
int V_8 , void * V_3 )
{
int V_9 ;
V_5 -> V_10 = V_11 ;
V_5 -> V_12 = F_4 ( V_7 -> V_13 - 1 ) ;
V_5 -> V_14 = 1 << V_5 -> V_12 ;
V_5 -> V_15 = V_16 ;
if ( F_5 ( V_7 ) ) {
V_5 -> V_17 = & V_18 ;
V_5 -> V_19 = V_20 ;
} else
V_5 -> V_17 = & V_21 ;
V_9 = F_6 ( V_5 ) ;
if ( V_9 )
return V_9 ;
if ( V_7 -> V_22 )
V_5 -> V_23 -> V_24 = ( V_25 * 1024 ) / V_26 ;
V_5 -> V_27 |= V_28 | V_29 | V_30 ;
if ( ! V_7 -> V_22 )
V_5 -> V_27 |= V_31 ;
#ifdef F_7
if ( ( V_7 -> V_8 & V_32 ) == V_33 )
V_5 -> V_27 |= V_34 ;
#endif
F_8 ( V_5 , V_3 ) ;
return 0 ;
}
static struct V_35 * F_9 ( struct V_36 * V_37 , int V_8 ,
const char * V_38 , void * V_3 )
{
struct V_1 * V_5 = NULL ;
struct V_39 * V_39 = NULL ;
struct V_35 * V_40 = NULL ;
struct V_6 * V_7 = NULL ;
T_1 V_41 = V_42 | V_43 ;
struct V_44 * V_45 ;
int V_46 = 0 ;
F_10 ( V_47 , L_1 ) ;
V_7 = F_11 ( sizeof( struct V_6 ) , V_48 ) ;
if ( ! V_7 )
return F_12 ( - V_49 ) ;
V_45 = F_13 ( V_7 , V_38 , V_3 ) ;
if ( F_14 ( V_45 ) ) {
V_46 = F_15 ( V_45 ) ;
goto V_50;
}
V_5 = F_16 ( V_37 , NULL , F_1 , V_8 , V_7 ) ;
if ( F_14 ( V_5 ) ) {
V_46 = F_15 ( V_5 ) ;
goto V_51;
}
V_46 = F_3 ( V_5 , V_7 , V_8 , V_3 ) ;
if ( V_46 )
goto V_52;
if ( V_7 -> V_22 == V_53 || V_7 -> V_22 == V_54 )
V_5 -> V_55 = & V_56 ;
else
V_5 -> V_55 = & V_57 ;
V_39 = F_17 ( V_5 , V_58 | V_41 , 0 ) ;
if ( F_14 ( V_39 ) ) {
V_46 = F_15 ( V_39 ) ;
goto V_52;
}
V_40 = F_18 ( V_39 ) ;
if ( ! V_40 ) {
V_46 = - V_49 ;
goto V_52;
}
V_5 -> V_59 = V_40 ;
if ( F_5 ( V_7 ) ) {
struct V_60 * V_61 = NULL ;
V_61 = F_19 ( V_45 , V_62 ) ;
if ( F_14 ( V_61 ) ) {
V_46 = F_15 ( V_61 ) ;
goto V_52;
}
F_20 ( V_40 ) -> V_63 = F_21 ( & V_61 -> V_64 ) ;
F_22 ( V_61 , F_20 ( V_40 ) ) ;
F_23 ( V_61 ) ;
} else {
struct V_65 * V_61 = NULL ;
V_61 = F_24 ( V_45 ) ;
if ( F_14 ( V_61 ) ) {
V_46 = F_15 ( V_61 ) ;
goto V_52;
}
F_20 ( V_40 ) -> V_63 = F_21 ( & V_61 -> V_64 ) ;
F_25 ( V_61 , F_20 ( V_40 ) , V_5 ) ;
F_26 ( V_61 ) ;
F_23 ( V_61 ) ;
}
V_46 = F_27 ( V_39 , V_45 ) ;
if ( V_46 )
goto V_52;
F_28 ( V_40 , V_45 ) ;
F_10 ( V_47 , L_2 ) ;
return F_29 ( V_5 -> V_59 ) ;
V_51:
F_30 ( V_45 ) ;
F_31 ( V_7 ) ;
V_50:
F_23 ( V_7 ) ;
return F_12 ( V_46 ) ;
V_52:
F_30 ( V_45 ) ;
F_32 ( V_5 ) ;
return F_12 ( V_46 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_4 ;
F_10 ( V_47 , L_3 , V_2 ) ;
F_34 ( V_2 ) ;
F_35 ( V_7 ) ;
F_31 ( V_7 ) ;
F_23 ( V_7 ) ;
V_2 -> V_4 = NULL ;
F_10 ( V_47 , L_4 ) ;
}
static void
F_36 ( struct V_1 * V_5 )
{
struct V_6 * V_7 ;
V_7 = V_5 -> V_4 ;
F_37 ( V_7 ) ;
}
static int F_38 ( struct V_35 * V_35 , struct V_66 * V_67 )
{
struct V_6 * V_7 ;
struct V_44 * V_45 ;
struct V_68 V_69 ;
int V_70 ;
V_45 = F_39 ( V_35 ) ;
if ( F_14 ( V_45 ) ) {
V_70 = F_15 ( V_45 ) ;
goto V_71;
}
V_7 = F_40 ( V_35 ) ;
if ( F_5 ( V_7 ) ) {
V_70 = F_41 ( V_45 , & V_69 ) ;
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
V_70 = F_42 ( V_35 , V_67 ) ;
V_71:
return V_70 ;
}
static int F_43 ( struct V_39 * V_39 )
{
struct V_6 * V_7 ;
V_7 = F_44 ( V_39 ) ;
if ( V_7 -> V_22 == V_53 || V_7 -> V_22 == V_54 )
return F_45 ( V_39 ) ;
return 1 ;
}
static int F_46 ( struct V_39 * V_39 ,
struct V_91 * V_92 )
{
int V_9 ;
struct V_65 V_93 ;
struct V_94 * V_95 ;
F_10 ( V_47 , L_5 , V_96 , V_39 ) ;
V_95 = F_47 ( V_39 ) ;
if ( ! V_95 -> V_97 )
return 0 ;
F_48 ( & V_93 ) ;
V_9 = F_49 ( V_95 -> V_97 , & V_93 ) ;
if ( V_9 < 0 ) {
F_50 ( V_39 , V_98 ) ;
return V_9 ;
}
return 0 ;
}
static int F_51 ( struct V_39 * V_39 ,
struct V_91 * V_92 )
{
int V_9 ;
struct V_94 * V_95 ;
V_95 = F_47 ( V_39 ) ;
F_10 ( V_47 , L_6 ,
V_96 , V_39 , V_95 -> V_97 ) ;
if ( ! V_95 -> V_97 )
return 0 ;
V_9 = F_52 ( V_95 -> V_97 , 0 ) ;
if ( V_9 < 0 ) {
F_50 ( V_39 , V_98 ) ;
return V_9 ;
}
return 0 ;
}
