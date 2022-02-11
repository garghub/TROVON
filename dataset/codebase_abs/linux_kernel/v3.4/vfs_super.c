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
V_5 -> V_27 = V_8 | V_28 | V_29 | V_30 ;
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
V_5 = F_15 ( V_37 , NULL , F_1 , V_7 ) ;
if ( F_13 ( V_5 ) ) {
V_46 = F_14 ( V_5 ) ;
goto V_51;
}
F_3 ( V_5 , V_7 , V_8 , V_3 ) ;
if ( V_7 -> V_23 )
V_5 -> V_52 = & V_53 ;
else
V_5 -> V_52 = & V_54 ;
V_39 = F_16 ( V_5 , V_55 | V_41 , 0 ) ;
if ( F_13 ( V_39 ) ) {
V_46 = F_14 ( V_39 ) ;
goto V_56;
}
V_40 = F_17 ( V_39 ) ;
if ( ! V_40 ) {
V_46 = - V_49 ;
goto V_56;
}
V_5 -> V_57 = V_40 ;
if ( F_5 ( V_7 ) ) {
struct V_58 * V_59 = NULL ;
V_59 = F_18 ( V_45 , V_60 ) ;
if ( F_13 ( V_59 ) ) {
V_46 = F_14 ( V_59 ) ;
goto V_56;
}
V_40 -> V_61 -> V_62 = F_19 ( & V_59 -> V_63 ) ;
F_20 ( V_59 , V_40 -> V_61 ) ;
F_21 ( V_59 ) ;
} else {
struct V_64 * V_59 = NULL ;
V_59 = F_22 ( V_45 ) ;
if ( F_13 ( V_59 ) ) {
V_46 = F_14 ( V_59 ) ;
goto V_56;
}
V_40 -> V_61 -> V_62 = F_19 ( & V_59 -> V_63 ) ;
F_23 ( V_59 , V_40 -> V_61 , V_5 ) ;
F_24 ( V_59 ) ;
F_21 ( V_59 ) ;
}
V_46 = F_25 ( V_39 , V_45 ) ;
if ( V_46 )
goto V_56;
F_26 ( V_40 , V_45 ) ;
F_9 ( V_47 , L_2 ) ;
return F_27 ( V_5 -> V_57 ) ;
V_51:
F_28 ( V_45 ) ;
V_50:
F_29 ( V_7 ) ;
F_21 ( V_7 ) ;
return F_11 ( V_46 ) ;
V_56:
F_28 ( V_45 ) ;
F_30 ( V_5 ) ;
return F_11 ( V_46 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_4 ;
F_9 ( V_47 , L_3 , V_2 ) ;
F_32 ( V_2 ) ;
F_33 ( V_7 ) ;
F_29 ( V_7 ) ;
F_21 ( V_7 ) ;
V_2 -> V_4 = NULL ;
F_9 ( V_47 , L_4 ) ;
}
static void
F_34 ( struct V_1 * V_5 )
{
struct V_6 * V_7 ;
V_7 = V_5 -> V_4 ;
F_35 ( V_7 ) ;
}
static int F_36 ( struct V_35 * V_35 , struct V_65 * V_66 )
{
struct V_6 * V_7 ;
struct V_44 * V_45 ;
struct V_67 V_68 ;
int V_69 ;
V_45 = F_37 ( V_35 ) ;
if ( F_13 ( V_45 ) ) {
V_69 = F_14 ( V_45 ) ;
goto V_70;
}
V_7 = F_38 ( V_35 ) ;
if ( F_5 ( V_7 ) ) {
V_69 = F_39 ( V_45 , & V_68 ) ;
if ( V_69 == 0 ) {
V_66 -> V_71 = V_68 . type ;
V_66 -> V_72 = V_68 . V_73 ;
V_66 -> V_74 = V_68 . V_75 ;
V_66 -> V_76 = V_68 . V_77 ;
V_66 -> V_78 = V_68 . V_79 ;
V_66 -> V_80 = V_68 . V_81 ;
V_66 -> V_82 = V_68 . V_83 ;
V_66 -> V_84 . V_85 [ 0 ] = V_68 . V_86 & 0xFFFFFFFFUL ;
V_66 -> V_84 . V_85 [ 1 ] = ( V_68 . V_86 >> 32 ) & 0xFFFFFFFFUL ;
V_66 -> V_87 = V_68 . V_88 ;
}
if ( V_69 != - V_89 )
goto V_70;
}
V_69 = F_40 ( V_35 , V_66 ) ;
V_70:
return V_69 ;
}
static int F_41 ( struct V_39 * V_39 )
{
struct V_6 * V_7 ;
V_7 = F_42 ( V_39 ) ;
if ( V_7 -> V_23 )
return F_43 ( V_39 ) ;
return 1 ;
}
static int F_44 ( struct V_39 * V_39 ,
struct V_90 * V_91 )
{
int V_92 ;
struct V_64 V_93 ;
struct V_94 * V_95 ;
F_9 ( V_47 , L_5 , V_96 , V_39 ) ;
V_95 = F_45 ( V_39 ) ;
if ( ! V_95 -> V_97 )
return 0 ;
F_46 ( & V_93 ) ;
V_92 = F_47 ( V_95 -> V_97 , & V_93 ) ;
if ( V_92 < 0 ) {
F_48 ( V_39 , V_98 ) ;
return V_92 ;
}
return 0 ;
}
static int F_49 ( struct V_39 * V_39 ,
struct V_90 * V_91 )
{
int V_92 ;
struct V_94 * V_95 ;
F_9 ( V_47 , L_5 , V_96 , V_39 ) ;
V_95 = F_45 ( V_39 ) ;
if ( ! V_95 -> V_97 )
return 0 ;
V_92 = F_50 ( V_95 -> V_97 , 0 ) ;
if ( V_92 < 0 ) {
F_48 ( V_39 , V_98 ) ;
return V_92 ;
}
return 0 ;
}
