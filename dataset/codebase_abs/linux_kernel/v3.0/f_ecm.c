static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline unsigned F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( V_7 ) && V_7 -> V_8 == V_9 )
return 13 * 512 * 8 * 1000 * 8 ;
else
return 19 * 64 * 1 * 1000 * 8 ;
}
static void F_5 ( struct V_1 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = V_10 -> V_4 . V_5 . V_18 -> V_17 ;
T_1 * V_19 ;
int V_20 ;
if ( ! V_12 )
return;
V_15 = V_12 -> V_21 ;
switch ( V_10 -> V_22 ) {
case V_23 :
return;
case V_24 :
V_15 -> V_25 = V_26 ;
if ( V_10 -> V_27 )
V_15 -> V_28 = F_6 ( 1 ) ;
else
V_15 -> V_28 = F_6 ( 0 ) ;
V_15 -> V_29 = 0 ;
V_12 -> V_30 = sizeof *V_15 ;
F_7 ( V_17 , L_1 ,
V_10 -> V_27 ? L_2 : L_3 ) ;
V_10 -> V_22 = V_31 ;
break;
case V_31 :
V_15 -> V_25 = V_32 ;
V_15 -> V_28 = F_6 ( 0 ) ;
V_15 -> V_29 = F_6 ( 8 ) ;
V_12 -> V_30 = V_33 ;
V_19 = V_12 -> V_21 + sizeof *V_15 ;
V_19 [ 0 ] = F_8 ( F_3 ( V_17 -> V_34 ) ) ;
V_19 [ 1 ] = V_19 [ 0 ] ;
F_7 ( V_17 , L_4 , F_3 ( V_17 -> V_34 ) ) ;
V_10 -> V_22 = V_23 ;
break;
}
V_15 -> V_35 = 0xA1 ;
V_15 -> V_36 = F_6 ( V_10 -> V_37 ) ;
V_10 -> V_13 = NULL ;
V_20 = F_9 ( V_10 -> V_38 , V_12 , V_39 ) ;
if ( V_20 < 0 ) {
V_10 -> V_13 = V_12 ;
F_7 ( V_17 , L_5 , V_20 ) ;
}
}
static void F_10 ( struct V_1 * V_10 )
{
V_10 -> V_22 = V_24 ;
F_5 ( V_10 ) ;
}
static void F_11 ( struct V_40 * V_41 , struct V_11 * V_12 )
{
struct V_1 * V_10 = V_12 -> V_42 ;
struct V_16 * V_17 = V_10 -> V_4 . V_5 . V_18 -> V_17 ;
struct V_14 * V_15 = V_12 -> V_21 ;
switch ( V_12 -> V_20 ) {
case 0 :
break;
case - V_43 :
case - V_44 :
V_10 -> V_22 = V_23 ;
break;
default:
F_7 ( V_17 , L_6 ,
V_15 -> V_25 , V_12 -> V_20 ) ;
break;
}
V_10 -> V_13 = V_12 ;
F_5 ( V_10 ) ;
}
static int F_12 ( struct V_2 * V_3 , const struct V_45 * V_46 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_17 ;
struct V_11 * V_12 = V_17 -> V_12 ;
int V_47 = - V_48 ;
T_2 V_49 = F_13 ( V_46 -> V_36 ) ;
T_2 V_50 = F_13 ( V_46 -> V_28 ) ;
T_2 V_51 = F_13 ( V_46 -> V_29 ) ;
switch ( ( V_46 -> V_52 << 8 ) | V_46 -> V_53 ) {
case ( ( V_54 | V_55 | V_56 ) << 8 )
| V_57 :
if ( V_51 != 0 || V_49 != V_10 -> V_37 )
goto V_58;
F_7 ( V_17 , L_7 , V_50 ) ;
V_10 -> V_4 . V_59 = V_50 ;
V_47 = 0 ;
break;
default:
V_58:
F_7 ( V_17 , L_8 ,
V_46 -> V_52 , V_46 -> V_53 ,
V_50 , V_49 , V_51 ) ;
}
if ( V_47 >= 0 ) {
F_7 ( V_17 , L_9 ,
V_46 -> V_52 , V_46 -> V_53 ,
V_50 , V_49 , V_51 ) ;
V_12 -> V_60 = 0 ;
V_12 -> V_30 = V_47 ;
V_47 = F_9 ( V_17 -> V_34 -> V_61 , V_12 , V_39 ) ;
if ( V_47 < 0 )
ERROR ( V_17 , L_10 ,
V_46 -> V_52 , V_46 -> V_53 ,
V_47 ) ;
}
return V_47 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned V_62 , unsigned V_63 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_17 ;
if ( V_62 == V_10 -> V_37 ) {
if ( V_63 != 0 )
goto V_64;
if ( V_10 -> V_38 -> V_65 ) {
F_15 ( V_17 , L_11 , V_62 ) ;
F_16 ( V_10 -> V_38 ) ;
} else {
F_15 ( V_17 , L_12 , V_62 ) ;
V_10 -> V_66 = F_17 ( V_17 -> V_34 ,
V_10 -> V_67 . V_38 ,
V_10 -> V_68 . V_38 ) ;
}
F_18 ( V_10 -> V_38 , V_10 -> V_66 ) ;
V_10 -> V_38 -> V_65 = V_10 ;
} else if ( V_62 == V_10 -> V_69 ) {
if ( V_63 > 1 )
goto V_64;
if ( V_10 -> V_4 . V_70 -> V_65 ) {
F_7 ( V_17 , L_13 ) ;
F_19 ( & V_10 -> V_4 ) ;
}
if ( ! V_10 -> V_4 . V_71 ) {
F_7 ( V_17 , L_14 ) ;
V_10 -> V_4 . V_71 = F_17 ( V_17 -> V_34 ,
V_10 -> V_67 . V_71 , V_10 -> V_68 . V_71 ) ;
V_10 -> V_4 . V_72 = F_17 ( V_17 -> V_34 ,
V_10 -> V_67 . V_72 , V_10 -> V_68 . V_72 ) ;
}
if ( V_63 == 1 ) {
struct V_73 * V_74 ;
V_10 -> V_4 . V_75 = ! ( F_20 ( V_17 -> V_34 )
) ;
V_10 -> V_4 . V_59 = V_76 ;
F_7 ( V_17 , L_15 ) ;
V_74 = F_21 ( & V_10 -> V_4 ) ;
if ( F_22 ( V_74 ) )
return F_23 ( V_74 ) ;
}
F_10 ( V_10 ) ;
} else
goto V_64;
return 0 ;
V_64:
return - V_77 ;
}
static int F_24 ( struct V_2 * V_3 , unsigned V_62 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_62 == V_10 -> V_37 )
return 0 ;
return V_10 -> V_4 . V_70 -> V_65 ? 1 : 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_16 * V_17 = V_3 -> V_18 -> V_17 ;
F_7 ( V_17 , L_16 ) ;
if ( V_10 -> V_4 . V_70 -> V_65 )
F_19 ( & V_10 -> V_4 ) ;
if ( V_10 -> V_38 -> V_65 ) {
F_16 ( V_10 -> V_38 ) ;
V_10 -> V_38 -> V_65 = NULL ;
V_10 -> V_66 = NULL ;
}
}
static void F_26 ( struct V_78 * V_79 )
{
struct V_1 * V_10 = F_1 ( & V_79 -> V_5 ) ;
F_7 ( V_10 -> V_4 . V_5 . V_18 -> V_17 , L_17 , V_80 ) ;
V_10 -> V_27 = true ;
F_10 ( V_10 ) ;
}
static void F_27 ( struct V_78 * V_79 )
{
struct V_1 * V_10 = F_1 ( & V_79 -> V_5 ) ;
F_7 ( V_10 -> V_4 . V_5 . V_18 -> V_17 , L_17 , V_80 ) ;
V_10 -> V_27 = false ;
F_10 ( V_10 ) ;
}
static int
F_28 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
struct V_16 * V_17 = V_82 -> V_17 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_20 ;
struct V_40 * V_41 ;
V_20 = F_29 ( V_82 , V_3 ) ;
if ( V_20 < 0 )
goto V_64;
V_10 -> V_37 = V_20 ;
V_83 . V_84 = V_20 ;
V_85 . V_86 = V_20 ;
V_20 = F_29 ( V_82 , V_3 ) ;
if ( V_20 < 0 )
goto V_64;
V_10 -> V_69 = V_20 ;
V_87 . V_84 = V_20 ;
V_88 . V_84 = V_20 ;
V_85 . V_89 = V_20 ;
V_20 = - V_90 ;
V_41 = F_30 ( V_17 -> V_34 , & V_91 ) ;
if ( ! V_41 )
goto V_64;
V_10 -> V_4 . V_70 = V_41 ;
V_41 -> V_65 = V_17 ;
V_41 = F_30 ( V_17 -> V_34 , & V_92 ) ;
if ( ! V_41 )
goto V_64;
V_10 -> V_4 . V_93 = V_41 ;
V_41 -> V_65 = V_17 ;
V_41 = F_30 ( V_17 -> V_34 , & V_94 ) ;
if ( ! V_41 )
goto V_64;
V_10 -> V_38 = V_41 ;
V_41 -> V_65 = V_17 ;
V_20 = - V_95 ;
V_10 -> V_13 = F_31 ( V_41 , V_96 ) ;
if ( ! V_10 -> V_13 )
goto V_64;
V_10 -> V_13 -> V_21 = F_32 ( V_33 , V_96 ) ;
if ( ! V_10 -> V_13 -> V_21 )
goto V_64;
V_10 -> V_13 -> V_42 = V_10 ;
V_10 -> V_13 -> V_97 = F_11 ;
V_3 -> V_98 = F_33 ( V_99 ) ;
if ( ! V_3 -> V_98 )
goto V_64;
V_10 -> V_68 . V_71 = F_34 ( V_99 ,
V_3 -> V_98 , & V_91 ) ;
V_10 -> V_68 . V_72 = F_34 ( V_99 ,
V_3 -> V_98 , & V_92 ) ;
V_10 -> V_68 . V_38 = F_34 ( V_99 ,
V_3 -> V_98 , & V_94 ) ;
if ( F_4 ( V_82 -> V_17 -> V_34 ) ) {
V_100 . V_101 =
V_91 . V_101 ;
V_102 . V_101 =
V_92 . V_101 ;
V_103 . V_101 =
V_94 . V_101 ;
V_3 -> V_104 = F_33 ( V_105 ) ;
if ( ! V_3 -> V_104 )
goto V_64;
V_10 -> V_67 . V_71 = F_34 ( V_105 ,
V_3 -> V_104 , & V_100 ) ;
V_10 -> V_67 . V_72 = F_34 ( V_105 ,
V_3 -> V_104 , & V_102 ) ;
V_10 -> V_67 . V_38 = F_34 ( V_105 ,
V_3 -> V_104 , & V_103 ) ;
}
V_10 -> V_4 . V_106 = F_26 ;
V_10 -> V_4 . V_107 = F_27 ;
F_7 ( V_17 , L_18 ,
F_4 ( V_82 -> V_17 -> V_34 ) ? L_19 : L_20 ,
V_10 -> V_4 . V_70 -> V_108 , V_10 -> V_4 . V_93 -> V_108 ,
V_10 -> V_38 -> V_108 ) ;
return 0 ;
V_64:
if ( V_3 -> V_98 )
F_35 ( V_3 -> V_98 ) ;
if ( V_10 -> V_13 ) {
F_36 ( V_10 -> V_13 -> V_21 ) ;
F_37 ( V_10 -> V_38 , V_10 -> V_13 ) ;
}
if ( V_10 -> V_38 )
V_10 -> V_38 -> V_65 = NULL ;
if ( V_10 -> V_4 . V_72 )
V_10 -> V_4 . V_93 -> V_65 = NULL ;
if ( V_10 -> V_4 . V_71 )
V_10 -> V_4 . V_70 -> V_65 = NULL ;
ERROR ( V_17 , L_21 , V_3 -> V_108 , V_20 ) ;
return V_20 ;
}
static void
F_38 ( struct V_81 * V_82 , struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_7 ( V_82 -> V_17 , L_22 ) ;
if ( F_4 ( V_82 -> V_17 -> V_34 ) )
F_35 ( V_3 -> V_104 ) ;
F_35 ( V_3 -> V_98 ) ;
F_36 ( V_10 -> V_13 -> V_21 ) ;
F_37 ( V_10 -> V_38 , V_10 -> V_13 ) ;
V_109 [ 1 ] . V_110 = NULL ;
F_36 ( V_10 ) ;
}
int
F_39 ( struct V_81 * V_82 , T_3 V_111 [ V_112 ] )
{
struct V_1 * V_10 ;
int V_20 ;
if ( ! F_40 ( V_82 -> V_17 -> V_34 ) || ! V_111 )
return - V_77 ;
if ( V_109 [ 0 ] . V_113 == 0 ) {
V_20 = F_41 ( V_82 -> V_17 ) ;
if ( V_20 < 0 )
return V_20 ;
V_109 [ 0 ] . V_113 = V_20 ;
V_83 . V_114 = V_20 ;
V_20 = F_41 ( V_82 -> V_17 ) ;
if ( V_20 < 0 )
return V_20 ;
V_109 [ 2 ] . V_113 = V_20 ;
V_88 . V_114 = V_20 ;
V_20 = F_41 ( V_82 -> V_17 ) ;
if ( V_20 < 0 )
return V_20 ;
V_109 [ 1 ] . V_113 = V_20 ;
V_115 . V_116 = V_20 ;
}
V_10 = F_42 ( sizeof *V_10 , V_96 ) ;
if ( ! V_10 )
return - V_95 ;
snprintf ( V_10 -> V_111 , sizeof V_10 -> V_111 ,
L_23 ,
V_111 [ 0 ] , V_111 [ 1 ] , V_111 [ 2 ] ,
V_111 [ 3 ] , V_111 [ 4 ] , V_111 [ 5 ] ) ;
V_109 [ 1 ] . V_110 = V_10 -> V_111 ;
V_10 -> V_4 . V_59 = V_76 ;
V_10 -> V_4 . V_5 . V_108 = L_24 ;
V_10 -> V_4 . V_5 . V_117 = V_118 ;
V_10 -> V_4 . V_5 . V_119 = F_28 ;
V_10 -> V_4 . V_5 . V_120 = F_38 ;
V_10 -> V_4 . V_5 . V_121 = F_14 ;
V_10 -> V_4 . V_5 . V_122 = F_24 ;
V_10 -> V_4 . V_5 . V_123 = F_12 ;
V_10 -> V_4 . V_5 . V_124 = F_25 ;
V_20 = F_43 ( V_82 , & V_10 -> V_4 . V_5 ) ;
if ( V_20 ) {
V_109 [ 1 ] . V_110 = NULL ;
F_36 ( V_10 ) ;
}
return V_20 ;
}
