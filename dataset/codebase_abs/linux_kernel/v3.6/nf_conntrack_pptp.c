static void F_1 ( struct V_1 * V_2 ,
struct V_3 * exp )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_3 (nf_nat_pptp_hook_expectfn) V_5 ;
F_4 ( L_1 ) ;
V_2 -> V_6 . V_7 . V_8 = V_9 ;
V_2 -> V_6 . V_7 . V_10 = V_11 ;
F_5 () ;
V_5 = F_6 ( V_12 ) ;
if ( V_5 && V_2 -> V_13 -> V_14 & V_15 )
V_5 ( V_2 , exp ) ;
else {
struct V_16 V_17 ;
struct V_3 * V_18 ;
F_7 ( & V_17 , & exp -> V_19 ) ;
F_4 ( L_2 ) ;
F_8 ( & V_17 ) ;
V_18 = F_9 ( V_4 , F_10 ( V_2 ) , & V_17 ) ;
if ( V_18 ) {
F_4 ( L_3 ) ;
F_11 ( V_18 ) ;
F_12 ( V_18 ) ;
} else {
F_4 ( L_4 ) ;
}
}
F_13 () ;
}
static int F_14 ( struct V_4 * V_4 , struct V_1 * V_2 ,
const struct V_16 * V_20 )
{
const struct V_21 * V_22 ;
struct V_3 * exp ;
struct V_1 * V_23 ;
T_1 V_24 = F_10 ( V_2 ) ;
F_4 ( L_5 ) ;
F_8 ( V_20 ) ;
V_22 = F_15 ( V_4 , V_24 , V_20 ) ;
if ( V_22 ) {
V_23 = F_16 ( V_22 ) ;
F_4 ( L_6 , V_23 ) ;
V_23 -> V_6 . V_7 . V_8 = 0 ;
V_23 -> V_6 . V_7 . V_10 = 0 ;
if ( F_17 ( & V_23 -> V_8 ) )
V_23 -> V_8 . V_25 ( ( unsigned long ) V_23 ) ;
F_18 ( V_23 ) ;
return 1 ;
} else {
exp = F_9 ( V_4 , V_24 , V_20 ) ;
if ( exp ) {
F_4 ( L_7 , exp ) ;
F_11 ( exp ) ;
F_12 ( exp ) ;
return 1 ;
}
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
const struct V_26 * V_27 = F_20 ( V_2 ) ;
struct V_16 V_20 ;
F_21 ( V_2 ) ;
memcpy ( & V_20 , & V_2 -> V_28 [ V_29 ] . V_19 , sizeof( V_20 ) ) ;
V_20 . V_30 . V_31 = V_32 ;
V_20 . V_33 . V_34 . V_7 . V_35 = V_27 -> V_36 ;
V_20 . V_30 . V_34 . V_7 . V_35 = V_27 -> V_37 ;
if ( ! F_14 ( V_4 , V_2 , & V_20 ) )
F_4 ( L_8 ) ;
memcpy ( & V_20 , & V_2 -> V_28 [ V_38 ] . V_19 , sizeof( V_20 ) ) ;
V_20 . V_30 . V_31 = V_32 ;
V_20 . V_33 . V_34 . V_7 . V_35 = V_27 -> V_37 ;
V_20 . V_30 . V_34 . V_7 . V_35 = V_27 -> V_36 ;
if ( ! F_14 ( V_4 , V_2 , & V_20 ) )
F_4 ( L_9 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_39 , T_2 V_40 )
{
struct V_3 * V_41 , * V_42 ;
enum V_43 V_44 ;
int V_45 = 1 ;
F_3 (nf_nat_pptp_hook_exp_gre) V_46 ;
V_41 = F_23 ( V_2 ) ;
if ( V_41 == NULL )
goto V_47;
V_42 = F_23 ( V_2 ) ;
if ( V_42 == NULL )
goto V_48;
V_44 = V_29 ;
F_24 ( V_41 , V_49 ,
F_25 ( V_2 ) ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_33 . V_50 ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_30 . V_50 ,
V_32 , & V_40 , & V_39 ) ;
V_41 -> V_51 = F_1 ;
V_44 = V_38 ;
F_24 ( V_42 , V_49 ,
F_25 ( V_2 ) ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_33 . V_50 ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_30 . V_50 ,
V_32 , & V_39 , & V_40 ) ;
V_42 -> V_51 = F_1 ;
V_46 = F_6 ( V_52 ) ;
if ( V_46 && V_2 -> V_14 & V_15 )
V_46 ( V_41 , V_42 ) ;
if ( F_26 ( V_41 ) != 0 )
goto V_53;
if ( F_26 ( V_42 ) != 0 )
goto V_54;
if ( F_27 ( V_2 , V_29 , & V_41 -> V_19 ) != 0 )
goto V_55;
if ( F_27 ( V_2 , V_38 , & V_42 -> V_19 ) != 0 ) {
F_21 ( V_2 ) ;
goto V_55;
}
V_45 = 0 ;
V_53:
F_12 ( V_42 ) ;
V_48:
F_12 ( V_41 ) ;
V_47:
return V_45 ;
V_55:
F_11 ( V_42 ) ;
V_54:
F_11 ( V_41 ) ;
goto V_53;
}
static inline int
F_28 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
union V_60 * V_61 ,
unsigned int V_62 ,
struct V_1 * V_2 ,
enum V_63 V_64 )
{
struct V_26 * V_65 = F_20 ( V_2 ) ;
T_3 V_66 ;
T_2 V_67 = 0 , V_68 = 0 ;
F_3 (nf_nat_pptp_hook_inbound) V_69 ;
V_66 = F_29 ( V_59 -> V_70 ) ;
F_4 ( L_10 , V_71 [ V_66 ] ) ;
switch ( V_66 ) {
case V_72 :
if ( V_65 -> V_73 < V_74 )
goto V_75;
if ( V_61 -> V_76 . V_77 == V_78 )
V_65 -> V_73 = V_79 ;
else
V_65 -> V_73 = V_80 ;
break;
case V_81 :
if ( V_65 -> V_73 > V_82 )
goto V_75;
if ( V_61 -> V_83 . V_77 == V_84 )
V_65 -> V_73 = V_85 ;
else
V_65 -> V_73 = V_80 ;
break;
case V_86 :
if ( V_65 -> V_73 != V_79 )
goto V_75;
if ( V_65 -> V_87 != V_88 &&
V_65 -> V_87 != V_89 )
goto V_75;
V_67 = V_61 -> V_90 . V_91 ;
V_68 = V_61 -> V_90 . V_92 ;
if ( V_65 -> V_36 != V_68 )
goto V_75;
F_4 ( L_11 , V_71 [ V_66 ] ,
F_29 ( V_67 ) , F_29 ( V_68 ) ) ;
if ( V_61 -> V_90 . V_77 == V_93 ) {
V_65 -> V_87 = V_89 ;
V_65 -> V_37 = V_67 ;
F_22 ( V_2 , V_67 , V_68 ) ;
} else
V_65 -> V_87 = V_94 ;
break;
case V_95 :
if ( V_65 -> V_73 != V_79 )
goto V_75;
V_67 = V_61 -> V_96 . V_91 ;
F_4 ( L_12 , V_71 [ V_66 ] , F_29 ( V_67 ) ) ;
V_65 -> V_87 = V_97 ;
V_65 -> V_37 = V_67 ;
break;
case V_98 :
if ( V_65 -> V_73 != V_79 )
goto V_75;
if ( V_65 -> V_87 != V_99 &&
V_65 -> V_87 != V_100 )
goto V_75;
V_68 = V_61 -> V_101 . V_92 ;
V_67 = V_65 -> V_37 ;
if ( V_65 -> V_36 != V_68 )
goto V_75;
F_4 ( L_13 , V_71 [ V_66 ] , F_29 ( V_68 ) ) ;
V_65 -> V_87 = V_100 ;
F_22 ( V_2 , V_67 , V_68 ) ;
break;
case V_102 :
V_67 = V_61 -> V_103 . V_91 ;
F_4 ( L_12 , V_71 [ V_66 ] , F_29 ( V_67 ) ) ;
V_65 -> V_87 = V_94 ;
F_19 ( V_2 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
break;
default:
goto V_75;
}
V_69 = F_6 ( V_108 ) ;
if ( V_69 && V_2 -> V_14 & V_15 )
return V_69 ( V_57 , V_2 , V_64 , V_59 , V_61 ) ;
return V_109 ;
V_75:
F_4 ( L_14
L_15 ,
V_66 <= V_110 ? V_71 [ V_66 ] : V_71 [ 0 ] ,
V_66 , F_29 ( V_67 ) , F_29 ( V_68 ) , V_65 -> V_87 , V_65 -> V_73 ,
F_29 ( V_65 -> V_36 ) , F_29 ( V_65 -> V_37 ) ) ;
return V_109 ;
}
static inline int
F_30 ( struct V_56 * V_57 ,
struct V_58 * V_59 ,
union V_60 * V_61 ,
unsigned int V_62 ,
struct V_1 * V_2 ,
enum V_63 V_64 )
{
struct V_26 * V_65 = F_20 ( V_2 ) ;
T_3 V_66 ;
T_2 V_67 = 0 , V_68 = 0 ;
F_3 (nf_nat_pptp_hook_outbound) V_111 ;
V_66 = F_29 ( V_59 -> V_70 ) ;
F_4 ( L_16 , V_71 [ V_66 ] ) ;
switch ( V_66 ) {
case V_112 :
if ( V_65 -> V_73 != V_85 )
goto V_75;
V_65 -> V_73 = V_74 ;
break;
case V_113 :
V_65 -> V_73 = V_82 ;
break;
case V_114 :
if ( V_65 -> V_73 != V_79 )
goto V_75;
V_65 -> V_87 = V_88 ;
V_67 = V_61 -> V_115 . V_91 ;
F_4 ( L_12 , V_71 [ V_66 ] , F_29 ( V_67 ) ) ;
V_65 -> V_36 = V_67 ;
break;
case V_116 :
if ( V_65 -> V_87 != V_97 &&
V_65 -> V_87 != V_99 )
goto V_75;
V_67 = V_61 -> V_117 . V_91 ;
V_68 = V_61 -> V_117 . V_92 ;
if ( V_65 -> V_37 != V_68 )
goto V_75;
F_4 ( L_17 , V_71 [ V_66 ] ,
F_29 ( V_67 ) , F_29 ( V_68 ) ) ;
if ( V_61 -> V_117 . V_77 == V_118 ) {
V_65 -> V_87 = V_99 ;
V_65 -> V_36 = V_67 ;
} else
V_65 -> V_87 = V_94 ;
break;
case V_119 :
if ( V_65 -> V_73 != V_79 )
goto V_75;
V_65 -> V_87 = V_120 ;
break;
case V_105 :
case V_106 :
case V_107 :
break;
default:
goto V_75;
}
V_111 = F_6 ( V_121 ) ;
if ( V_111 && V_2 -> V_14 & V_15 )
return V_111 ( V_57 , V_2 , V_64 , V_59 , V_61 ) ;
return V_109 ;
V_75:
F_4 ( L_14
L_15 ,
V_66 <= V_110 ? V_71 [ V_66 ] : V_71 [ 0 ] ,
V_66 , F_29 ( V_67 ) , F_29 ( V_68 ) , V_65 -> V_87 , V_65 -> V_73 ,
F_29 ( V_65 -> V_36 ) , F_29 ( V_65 -> V_37 ) ) ;
return V_109 ;
}
static int
F_31 ( struct V_56 * V_57 , unsigned int V_122 ,
struct V_1 * V_2 , enum V_63 V_64 )
{
int V_44 = F_32 ( V_64 ) ;
const struct V_26 * V_65 = F_20 ( V_2 ) ;
const struct V_123 * V_124 ;
struct V_123 V_125 ;
const struct V_126 * V_127 ;
struct V_126 V_128 ;
struct V_58 V_129 , * V_59 ;
union V_60 V_130 , * V_61 ;
unsigned int V_131 = V_57 -> V_132 - V_122 ;
unsigned int V_133 , V_62 , V_134 ;
int V_135 , V_136 ;
int V_45 ;
T_3 V_66 ;
if ( V_64 != V_137 && V_64 != V_138 )
return V_109 ;
V_134 = V_122 ;
V_124 = F_33 ( V_57 , V_134 , sizeof( V_125 ) , & V_125 ) ;
F_34 ( ! V_124 ) ;
V_134 += V_124 -> V_139 * 4 ;
V_133 = V_131 - V_124 -> V_139 * 4 ;
V_127 = F_33 ( V_57 , V_134 , sizeof( V_128 ) , & V_128 ) ;
if ( ! V_127 ) {
F_4 ( L_18 ) ;
return V_109 ;
}
V_134 += sizeof( V_128 ) ;
V_133 -= sizeof( V_128 ) ;
if ( F_29 ( V_127 -> V_140 ) != V_141 ||
F_35 ( V_127 -> V_142 ) != V_143 ) {
F_4 ( L_19 ) ;
return V_109 ;
}
V_59 = F_33 ( V_57 , V_134 , sizeof( V_129 ) , & V_129 ) ;
if ( ! V_59 )
return V_109 ;
V_134 += sizeof( V_129 ) ;
V_133 -= sizeof( V_129 ) ;
V_62 = V_133 ;
V_66 = F_29 ( V_59 -> V_70 ) ;
if ( V_66 > 0 && V_66 <= V_110 && V_62 < V_144 [ V_66 ] )
return V_109 ;
if ( V_62 > sizeof( * V_61 ) )
V_62 = sizeof( * V_61 ) ;
V_61 = F_33 ( V_57 , V_134 , V_62 , & V_130 ) ;
if ( ! V_61 )
return V_109 ;
V_135 = V_65 -> V_73 ;
V_136 = V_65 -> V_87 ;
F_36 ( & V_145 ) ;
if ( V_44 == V_29 )
V_45 = F_30 ( V_57 , V_59 , V_61 , V_62 , V_2 ,
V_64 ) ;
else
V_45 = F_28 ( V_57 , V_59 , V_61 , V_62 , V_2 ,
V_64 ) ;
F_4 ( L_20 ,
V_135 , V_65 -> V_73 , V_136 , V_65 -> V_87 ) ;
F_37 ( & V_145 ) ;
return V_45 ;
}
static void F_38 ( struct V_4 * V_4 )
{
F_39 ( V_4 ) ;
}
static int T_4 F_40 ( void )
{
int V_146 ;
V_146 = F_41 ( & V_147 ) ;
if ( V_146 < 0 )
return V_146 ;
V_146 = F_42 ( & V_148 ) ;
if ( V_146 < 0 )
F_43 ( & V_147 ) ;
return V_146 ;
}
static void T_5 F_44 ( void )
{
F_43 ( & V_147 ) ;
F_45 ( & V_148 ) ;
}
