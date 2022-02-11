static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline unsigned F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( V_7 ) && V_7 -> V_8 == V_9 )
return 13 * 1024 * 8 * 1000 * 8 ;
else if ( F_5 ( V_7 ) && V_7 -> V_8 == V_10 )
return 13 * 512 * 8 * 1000 * 8 ;
else
return 19 * 64 * 1 * 1000 * 8 ;
}
static void F_6 ( struct V_1 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_11 -> V_4 . V_5 . V_19 -> V_18 ;
T_1 * V_20 ;
int V_21 ;
if ( ! V_13 )
return;
V_16 = V_13 -> V_22 ;
switch ( V_11 -> V_23 ) {
case V_24 :
return;
case V_25 :
V_16 -> V_26 = V_27 ;
if ( V_11 -> V_28 )
V_16 -> V_29 = F_7 ( 1 ) ;
else
V_16 -> V_29 = F_7 ( 0 ) ;
V_16 -> V_30 = 0 ;
V_13 -> V_31 = sizeof *V_16 ;
F_8 ( V_18 , L_1 ,
V_11 -> V_28 ? L_2 : L_3 ) ;
V_11 -> V_23 = V_32 ;
break;
case V_32 :
V_16 -> V_26 = V_33 ;
V_16 -> V_29 = F_7 ( 0 ) ;
V_16 -> V_30 = F_7 ( 8 ) ;
V_13 -> V_31 = V_34 ;
V_20 = V_13 -> V_22 + sizeof *V_16 ;
V_20 [ 0 ] = F_9 ( F_3 ( V_18 -> V_35 ) ) ;
V_20 [ 1 ] = V_20 [ 0 ] ;
F_8 ( V_18 , L_4 , F_3 ( V_18 -> V_35 ) ) ;
V_11 -> V_23 = V_24 ;
break;
}
V_16 -> V_36 = 0xA1 ;
V_16 -> V_37 = F_7 ( V_11 -> V_38 ) ;
V_11 -> V_14 = NULL ;
V_21 = F_10 ( V_11 -> V_39 , V_13 , V_40 ) ;
if ( V_21 < 0 ) {
V_11 -> V_14 = V_13 ;
F_8 ( V_18 , L_5 , V_21 ) ;
}
}
static void F_11 ( struct V_1 * V_11 )
{
V_11 -> V_23 = V_25 ;
F_6 ( V_11 ) ;
}
static void F_12 ( struct V_41 * V_42 , struct V_12 * V_13 )
{
struct V_1 * V_11 = V_13 -> V_43 ;
struct V_17 * V_18 = V_11 -> V_4 . V_5 . V_19 -> V_18 ;
struct V_15 * V_16 = V_13 -> V_22 ;
switch ( V_13 -> V_21 ) {
case 0 :
break;
case - V_44 :
case - V_45 :
V_11 -> V_23 = V_24 ;
break;
default:
F_8 ( V_18 , L_6 ,
V_16 -> V_26 , V_13 -> V_21 ) ;
break;
}
V_11 -> V_14 = V_13 ;
F_6 ( V_11 ) ;
}
static int F_13 ( struct V_2 * V_3 , const struct V_46 * V_47 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_17 * V_18 = V_3 -> V_19 -> V_18 ;
struct V_12 * V_13 = V_18 -> V_13 ;
int V_48 = - V_49 ;
T_2 V_50 = F_14 ( V_47 -> V_37 ) ;
T_2 V_51 = F_14 ( V_47 -> V_29 ) ;
T_2 V_52 = F_14 ( V_47 -> V_30 ) ;
switch ( ( V_47 -> V_53 << 8 ) | V_47 -> V_54 ) {
case ( ( V_55 | V_56 | V_57 ) << 8 )
| V_58 :
if ( V_52 != 0 || V_50 != V_11 -> V_38 )
goto V_59;
F_8 ( V_18 , L_7 , V_51 ) ;
V_11 -> V_4 . V_60 = V_51 ;
V_48 = 0 ;
break;
default:
V_59:
F_8 ( V_18 , L_8 ,
V_47 -> V_53 , V_47 -> V_54 ,
V_51 , V_50 , V_52 ) ;
}
if ( V_48 >= 0 ) {
F_8 ( V_18 , L_9 ,
V_47 -> V_53 , V_47 -> V_54 ,
V_51 , V_50 , V_52 ) ;
V_13 -> V_61 = 0 ;
V_13 -> V_31 = V_48 ;
V_48 = F_10 ( V_18 -> V_35 -> V_62 , V_13 , V_40 ) ;
if ( V_48 < 0 )
ERROR ( V_18 , L_10 ,
V_47 -> V_53 , V_47 -> V_54 ,
V_48 ) ;
}
return V_48 ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_63 , unsigned V_64 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_17 * V_18 = V_3 -> V_19 -> V_18 ;
if ( V_63 == V_11 -> V_38 ) {
if ( V_64 != 0 )
goto V_65;
if ( V_11 -> V_39 -> V_66 ) {
F_16 ( V_18 , L_11 , V_63 ) ;
F_17 ( V_11 -> V_39 ) ;
}
if ( ! ( V_11 -> V_39 -> V_67 ) ) {
F_16 ( V_18 , L_12 , V_63 ) ;
if ( F_18 ( V_18 -> V_35 , V_3 , V_11 -> V_39 ) )
goto V_65;
}
F_19 ( V_11 -> V_39 ) ;
V_11 -> V_39 -> V_66 = V_11 ;
} else if ( V_63 == V_11 -> V_68 ) {
if ( V_64 > 1 )
goto V_65;
if ( V_11 -> V_4 . V_69 -> V_66 ) {
F_8 ( V_18 , L_13 ) ;
F_20 ( & V_11 -> V_4 ) ;
}
if ( ! V_11 -> V_4 . V_69 -> V_67 ||
! V_11 -> V_4 . V_70 -> V_67 ) {
F_8 ( V_18 , L_14 ) ;
if ( F_18 ( V_18 -> V_35 , V_3 ,
V_11 -> V_4 . V_69 ) ||
F_18 ( V_18 -> V_35 , V_3 ,
V_11 -> V_4 . V_70 ) ) {
V_11 -> V_4 . V_69 -> V_67 = NULL ;
V_11 -> V_4 . V_70 -> V_67 = NULL ;
goto V_65;
}
}
if ( V_64 == 1 ) {
struct V_71 * V_72 ;
V_11 -> V_4 . V_73 = ! ( F_21 ( V_18 -> V_35 )
) ;
V_11 -> V_4 . V_60 = V_74 ;
F_8 ( V_18 , L_15 ) ;
V_72 = F_22 ( & V_11 -> V_4 ) ;
if ( F_23 ( V_72 ) )
return F_24 ( V_72 ) ;
}
F_11 ( V_11 ) ;
} else
goto V_65;
return 0 ;
V_65:
return - V_75 ;
}
static int F_25 ( struct V_2 * V_3 , unsigned V_63 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( V_63 == V_11 -> V_38 )
return 0 ;
return V_11 -> V_4 . V_69 -> V_66 ? 1 : 0 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_17 * V_18 = V_3 -> V_19 -> V_18 ;
F_8 ( V_18 , L_16 ) ;
if ( V_11 -> V_4 . V_69 -> V_66 )
F_20 ( & V_11 -> V_4 ) ;
if ( V_11 -> V_39 -> V_66 ) {
F_17 ( V_11 -> V_39 ) ;
V_11 -> V_39 -> V_66 = NULL ;
V_11 -> V_39 -> V_67 = NULL ;
}
}
static void F_27 ( struct V_76 * V_77 )
{
struct V_1 * V_11 = F_1 ( & V_77 -> V_5 ) ;
F_8 ( V_11 -> V_4 . V_5 . V_19 -> V_18 , L_17 , V_78 ) ;
V_11 -> V_28 = true ;
F_11 ( V_11 ) ;
}
static void F_28 ( struct V_76 * V_77 )
{
struct V_1 * V_11 = F_1 ( & V_77 -> V_5 ) ;
F_8 ( V_11 -> V_4 . V_5 . V_19 -> V_18 , L_17 , V_78 ) ;
V_11 -> V_28 = false ;
F_11 ( V_11 ) ;
}
static int
F_29 ( struct V_79 * V_80 , struct V_2 * V_3 )
{
struct V_17 * V_18 = V_80 -> V_18 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
int V_21 ;
struct V_41 * V_42 ;
V_21 = F_30 ( V_80 , V_3 ) ;
if ( V_21 < 0 )
goto V_65;
V_11 -> V_38 = V_21 ;
V_81 . V_82 = V_21 ;
V_83 . V_84 = V_21 ;
V_21 = F_30 ( V_80 , V_3 ) ;
if ( V_21 < 0 )
goto V_65;
V_11 -> V_68 = V_21 ;
V_85 . V_82 = V_21 ;
V_86 . V_82 = V_21 ;
V_83 . V_87 = V_21 ;
V_21 = - V_88 ;
V_42 = F_31 ( V_18 -> V_35 , & V_89 ) ;
if ( ! V_42 )
goto V_65;
V_11 -> V_4 . V_69 = V_42 ;
V_42 -> V_66 = V_18 ;
V_42 = F_31 ( V_18 -> V_35 , & V_90 ) ;
if ( ! V_42 )
goto V_65;
V_11 -> V_4 . V_70 = V_42 ;
V_42 -> V_66 = V_18 ;
V_42 = F_31 ( V_18 -> V_35 , & V_91 ) ;
if ( ! V_42 )
goto V_65;
V_11 -> V_39 = V_42 ;
V_42 -> V_66 = V_18 ;
V_21 = - V_92 ;
V_11 -> V_14 = F_32 ( V_42 , V_93 ) ;
if ( ! V_11 -> V_14 )
goto V_65;
V_11 -> V_14 -> V_22 = F_33 ( V_34 , V_93 ) ;
if ( ! V_11 -> V_14 -> V_22 )
goto V_65;
V_11 -> V_14 -> V_43 = V_11 ;
V_11 -> V_14 -> V_94 = F_12 ;
V_3 -> V_95 = F_34 ( V_96 ) ;
if ( ! V_3 -> V_95 )
goto V_65;
if ( F_5 ( V_80 -> V_18 -> V_35 ) ) {
V_97 . V_98 =
V_89 . V_98 ;
V_99 . V_98 =
V_90 . V_98 ;
V_100 . V_98 =
V_91 . V_98 ;
V_3 -> V_101 = F_34 ( V_102 ) ;
if ( ! V_3 -> V_101 )
goto V_65;
}
if ( F_4 ( V_80 -> V_18 -> V_35 ) ) {
V_103 . V_98 =
V_89 . V_98 ;
V_104 . V_98 =
V_90 . V_98 ;
V_105 . V_98 =
V_91 . V_98 ;
V_3 -> V_106 = F_34 ( V_107 ) ;
if ( ! V_3 -> V_106 )
goto V_65;
}
V_11 -> V_4 . V_108 = F_27 ;
V_11 -> V_4 . V_109 = F_28 ;
F_8 ( V_18 , L_18 ,
F_4 ( V_80 -> V_18 -> V_35 ) ? L_19 :
F_5 ( V_80 -> V_18 -> V_35 ) ? L_20 : L_21 ,
V_11 -> V_4 . V_69 -> V_110 , V_11 -> V_4 . V_70 -> V_110 ,
V_11 -> V_39 -> V_110 ) ;
return 0 ;
V_65:
if ( V_3 -> V_95 )
F_35 ( V_3 -> V_95 ) ;
if ( V_3 -> V_101 )
F_35 ( V_3 -> V_101 ) ;
if ( V_11 -> V_14 ) {
F_36 ( V_11 -> V_14 -> V_22 ) ;
F_37 ( V_11 -> V_39 , V_11 -> V_14 ) ;
}
if ( V_11 -> V_39 )
V_11 -> V_39 -> V_66 = NULL ;
if ( V_11 -> V_4 . V_70 -> V_67 )
V_11 -> V_4 . V_70 -> V_66 = NULL ;
if ( V_11 -> V_4 . V_69 -> V_67 )
V_11 -> V_4 . V_69 -> V_66 = NULL ;
ERROR ( V_18 , L_22 , V_3 -> V_110 , V_21 ) ;
return V_21 ;
}
static void
F_38 ( struct V_79 * V_80 , struct V_2 * V_3 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
F_8 ( V_80 -> V_18 , L_23 ) ;
if ( F_4 ( V_80 -> V_18 -> V_35 ) )
F_35 ( V_3 -> V_106 ) ;
if ( F_5 ( V_80 -> V_18 -> V_35 ) )
F_35 ( V_3 -> V_101 ) ;
F_35 ( V_3 -> V_95 ) ;
F_36 ( V_11 -> V_14 -> V_22 ) ;
F_37 ( V_11 -> V_39 , V_11 -> V_14 ) ;
V_111 [ 1 ] . V_112 = NULL ;
F_36 ( V_11 ) ;
}
int
F_39 ( struct V_79 * V_80 , T_3 V_113 [ V_114 ] )
{
struct V_1 * V_11 ;
int V_21 ;
if ( ! F_40 ( V_80 -> V_18 -> V_35 ) || ! V_113 )
return - V_75 ;
if ( V_111 [ 0 ] . V_115 == 0 ) {
V_21 = F_41 ( V_80 -> V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_111 [ 0 ] . V_115 = V_21 ;
V_81 . V_116 = V_21 ;
V_21 = F_41 ( V_80 -> V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_111 [ 2 ] . V_115 = V_21 ;
V_86 . V_116 = V_21 ;
V_21 = F_41 ( V_80 -> V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
V_111 [ 1 ] . V_115 = V_21 ;
V_117 . V_118 = V_21 ;
}
V_11 = F_42 ( sizeof *V_11 , V_93 ) ;
if ( ! V_11 )
return - V_92 ;
snprintf ( V_11 -> V_113 , sizeof V_11 -> V_113 ,
L_24 ,
V_113 [ 0 ] , V_113 [ 1 ] , V_113 [ 2 ] ,
V_113 [ 3 ] , V_113 [ 4 ] , V_113 [ 5 ] ) ;
V_111 [ 1 ] . V_112 = V_11 -> V_113 ;
V_11 -> V_4 . V_60 = V_74 ;
V_11 -> V_4 . V_5 . V_110 = L_25 ;
V_11 -> V_4 . V_5 . V_119 = V_120 ;
V_11 -> V_4 . V_5 . V_121 = F_29 ;
V_11 -> V_4 . V_5 . V_122 = F_38 ;
V_11 -> V_4 . V_5 . V_123 = F_15 ;
V_11 -> V_4 . V_5 . V_124 = F_25 ;
V_11 -> V_4 . V_5 . V_125 = F_13 ;
V_11 -> V_4 . V_5 . V_126 = F_26 ;
V_21 = F_43 ( V_80 , & V_11 -> V_4 . V_5 ) ;
if ( V_21 ) {
V_111 [ 1 ] . V_112 = NULL ;
F_36 ( V_11 ) ;
}
return V_21 ;
}
