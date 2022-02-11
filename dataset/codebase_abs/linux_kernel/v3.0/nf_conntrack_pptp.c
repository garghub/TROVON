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
V_20 . V_33 . V_34 . V_7 . V_35 = V_27 -> V_27 . V_36 . V_37 ;
V_20 . V_30 . V_34 . V_7 . V_35 = V_27 -> V_27 . V_36 . V_38 ;
if ( ! F_14 ( V_4 , V_2 , & V_20 ) )
F_4 ( L_8 ) ;
memcpy ( & V_20 , & V_2 -> V_28 [ V_39 ] . V_19 , sizeof( V_20 ) ) ;
V_20 . V_30 . V_31 = V_32 ;
V_20 . V_33 . V_34 . V_7 . V_35 = V_27 -> V_27 . V_36 . V_38 ;
V_20 . V_30 . V_34 . V_7 . V_35 = V_27 -> V_27 . V_36 . V_37 ;
if ( ! F_14 ( V_4 , V_2 , & V_20 ) )
F_4 ( L_9 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_40 , T_2 V_41 )
{
struct V_3 * V_42 , * V_43 ;
enum V_44 V_45 ;
int V_46 = 1 ;
F_3 (nf_nat_pptp_hook_exp_gre) V_47 ;
V_42 = F_23 ( V_2 ) ;
if ( V_42 == NULL )
goto V_48;
V_43 = F_23 ( V_2 ) ;
if ( V_43 == NULL )
goto V_49;
V_45 = V_29 ;
F_24 ( V_42 , V_50 ,
F_25 ( V_2 ) ,
& V_2 -> V_28 [ V_45 ] . V_19 . V_33 . V_51 ,
& V_2 -> V_28 [ V_45 ] . V_19 . V_30 . V_51 ,
V_32 , & V_41 , & V_40 ) ;
V_42 -> V_52 = F_1 ;
V_45 = V_39 ;
F_24 ( V_43 , V_50 ,
F_25 ( V_2 ) ,
& V_2 -> V_28 [ V_45 ] . V_19 . V_33 . V_51 ,
& V_2 -> V_28 [ V_45 ] . V_19 . V_30 . V_51 ,
V_32 , & V_40 , & V_41 ) ;
V_43 -> V_52 = F_1 ;
V_47 = F_6 ( V_53 ) ;
if ( V_47 && V_2 -> V_14 & V_15 )
V_47 ( V_42 , V_43 ) ;
if ( F_26 ( V_42 ) != 0 )
goto V_54;
if ( F_26 ( V_43 ) != 0 )
goto V_55;
if ( F_27 ( V_2 , V_29 , & V_42 -> V_19 ) != 0 )
goto V_56;
if ( F_27 ( V_2 , V_39 , & V_43 -> V_19 ) != 0 ) {
F_21 ( V_2 ) ;
goto V_56;
}
V_46 = 0 ;
V_54:
F_12 ( V_43 ) ;
V_49:
F_12 ( V_42 ) ;
V_48:
return V_46 ;
V_56:
F_11 ( V_43 ) ;
V_55:
F_11 ( V_42 ) ;
goto V_54;
}
static inline int
F_28 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
union V_61 * V_62 ,
unsigned int V_63 ,
struct V_1 * V_2 ,
enum V_64 V_65 )
{
struct V_66 * V_67 = & F_20 ( V_2 ) -> V_27 . V_36 ;
T_3 V_68 ;
T_2 V_69 = 0 , V_70 = 0 ;
F_3 (nf_nat_pptp_hook_inbound) V_71 ;
V_68 = F_29 ( V_60 -> V_72 ) ;
F_4 ( L_10 , V_73 [ V_68 ] ) ;
switch ( V_68 ) {
case V_74 :
if ( V_67 -> V_75 < V_76 )
goto V_77;
if ( V_62 -> V_78 . V_79 == V_80 )
V_67 -> V_75 = V_81 ;
else
V_67 -> V_75 = V_82 ;
break;
case V_83 :
if ( V_67 -> V_75 > V_84 )
goto V_77;
if ( V_62 -> V_85 . V_79 == V_86 )
V_67 -> V_75 = V_87 ;
else
V_67 -> V_75 = V_82 ;
break;
case V_88 :
if ( V_67 -> V_75 != V_81 )
goto V_77;
if ( V_67 -> V_89 != V_90 &&
V_67 -> V_89 != V_91 )
goto V_77;
V_69 = V_62 -> V_92 . V_93 ;
V_70 = V_62 -> V_92 . V_94 ;
if ( V_67 -> V_37 != V_70 )
goto V_77;
F_4 ( L_11 , V_73 [ V_68 ] ,
F_29 ( V_69 ) , F_29 ( V_70 ) ) ;
if ( V_62 -> V_92 . V_79 == V_95 ) {
V_67 -> V_89 = V_91 ;
V_67 -> V_38 = V_69 ;
F_22 ( V_2 , V_69 , V_70 ) ;
} else
V_67 -> V_89 = V_96 ;
break;
case V_97 :
if ( V_67 -> V_75 != V_81 )
goto V_77;
V_69 = V_62 -> V_98 . V_93 ;
F_4 ( L_12 , V_73 [ V_68 ] , F_29 ( V_69 ) ) ;
V_67 -> V_89 = V_99 ;
V_67 -> V_38 = V_69 ;
break;
case V_100 :
if ( V_67 -> V_75 != V_81 )
goto V_77;
if ( V_67 -> V_89 != V_101 &&
V_67 -> V_89 != V_102 )
goto V_77;
V_70 = V_62 -> V_103 . V_94 ;
V_69 = V_67 -> V_38 ;
if ( V_67 -> V_37 != V_70 )
goto V_77;
F_4 ( L_13 , V_73 [ V_68 ] , F_29 ( V_70 ) ) ;
V_67 -> V_89 = V_102 ;
F_22 ( V_2 , V_69 , V_70 ) ;
break;
case V_104 :
V_69 = V_62 -> V_105 . V_93 ;
F_4 ( L_12 , V_73 [ V_68 ] , F_29 ( V_69 ) ) ;
V_67 -> V_89 = V_96 ;
F_19 ( V_2 ) ;
break;
case V_106 :
case V_107 :
case V_108 :
break;
default:
goto V_77;
}
V_71 = F_6 ( V_109 ) ;
if ( V_71 && V_2 -> V_14 & V_15 )
return V_71 ( V_58 , V_2 , V_65 , V_60 , V_62 ) ;
return V_110 ;
V_77:
F_4 ( L_14
L_15 ,
V_68 <= V_111 ? V_73 [ V_68 ] : V_73 [ 0 ] ,
V_68 , F_29 ( V_69 ) , F_29 ( V_70 ) , V_67 -> V_89 , V_67 -> V_75 ,
F_29 ( V_67 -> V_37 ) , F_29 ( V_67 -> V_38 ) ) ;
return V_110 ;
}
static inline int
F_30 ( struct V_57 * V_58 ,
struct V_59 * V_60 ,
union V_61 * V_62 ,
unsigned int V_63 ,
struct V_1 * V_2 ,
enum V_64 V_65 )
{
struct V_66 * V_67 = & F_20 ( V_2 ) -> V_27 . V_36 ;
T_3 V_68 ;
T_2 V_69 = 0 , V_70 = 0 ;
F_3 (nf_nat_pptp_hook_outbound) V_112 ;
V_68 = F_29 ( V_60 -> V_72 ) ;
F_4 ( L_16 , V_73 [ V_68 ] ) ;
switch ( V_68 ) {
case V_113 :
if ( V_67 -> V_75 != V_87 )
goto V_77;
V_67 -> V_75 = V_76 ;
break;
case V_114 :
V_67 -> V_75 = V_84 ;
break;
case V_115 :
if ( V_67 -> V_75 != V_81 )
goto V_77;
V_67 -> V_89 = V_90 ;
V_69 = V_62 -> V_116 . V_93 ;
F_4 ( L_12 , V_73 [ V_68 ] , F_29 ( V_69 ) ) ;
V_67 -> V_37 = V_69 ;
break;
case V_117 :
if ( V_67 -> V_89 != V_99 &&
V_67 -> V_89 != V_101 )
goto V_77;
V_69 = V_62 -> V_118 . V_93 ;
V_70 = V_62 -> V_118 . V_94 ;
if ( V_67 -> V_38 != V_70 )
goto V_77;
F_4 ( L_17 , V_73 [ V_68 ] ,
F_29 ( V_69 ) , F_29 ( V_70 ) ) ;
if ( V_62 -> V_118 . V_79 == V_119 ) {
V_67 -> V_89 = V_101 ;
V_67 -> V_37 = V_69 ;
} else
V_67 -> V_89 = V_96 ;
break;
case V_120 :
if ( V_67 -> V_75 != V_81 )
goto V_77;
V_67 -> V_89 = V_121 ;
break;
case V_122 :
case V_107 :
case V_108 :
break;
default:
goto V_77;
}
V_112 = F_6 ( V_123 ) ;
if ( V_112 && V_2 -> V_14 & V_15 )
return V_112 ( V_58 , V_2 , V_65 , V_60 , V_62 ) ;
return V_110 ;
V_77:
F_4 ( L_14
L_15 ,
V_68 <= V_111 ? V_73 [ V_68 ] : V_73 [ 0 ] ,
V_68 , F_29 ( V_69 ) , F_29 ( V_70 ) , V_67 -> V_89 , V_67 -> V_75 ,
F_29 ( V_67 -> V_37 ) , F_29 ( V_67 -> V_38 ) ) ;
return V_110 ;
}
static int
F_31 ( struct V_57 * V_58 , unsigned int V_124 ,
struct V_1 * V_2 , enum V_64 V_65 )
{
int V_45 = F_32 ( V_65 ) ;
const struct V_66 * V_67 = & F_20 ( V_2 ) -> V_27 . V_36 ;
const struct V_125 * V_126 ;
struct V_125 V_127 ;
const struct V_128 * V_129 ;
struct V_128 V_130 ;
struct V_59 V_131 , * V_60 ;
union V_61 V_132 , * V_62 ;
unsigned int V_133 = V_58 -> V_134 - V_124 ;
unsigned int V_135 , V_63 , V_136 ;
int V_137 , V_138 ;
int V_46 ;
T_3 V_68 ;
if ( V_65 != V_139 && V_65 != V_140 )
return V_110 ;
V_136 = V_124 ;
V_126 = F_33 ( V_58 , V_136 , sizeof( V_127 ) , & V_127 ) ;
F_34 ( ! V_126 ) ;
V_136 += V_126 -> V_141 * 4 ;
V_135 = V_133 - V_126 -> V_141 * 4 ;
V_129 = F_33 ( V_58 , V_136 , sizeof( V_130 ) , & V_130 ) ;
if ( ! V_129 ) {
F_4 ( L_18 ) ;
return V_110 ;
}
V_136 += sizeof( V_130 ) ;
V_135 -= sizeof( V_130 ) ;
if ( F_29 ( V_129 -> V_142 ) != V_143 ||
F_35 ( V_129 -> V_144 ) != V_145 ) {
F_4 ( L_19 ) ;
return V_110 ;
}
V_60 = F_33 ( V_58 , V_136 , sizeof( V_131 ) , & V_131 ) ;
if ( ! V_60 )
return V_110 ;
V_136 += sizeof( V_131 ) ;
V_135 -= sizeof( V_131 ) ;
V_63 = V_135 ;
V_68 = F_29 ( V_60 -> V_72 ) ;
if ( V_68 > 0 && V_68 <= V_111 && V_63 < V_146 [ V_68 ] )
return V_110 ;
if ( V_63 > sizeof( * V_62 ) )
V_63 = sizeof( * V_62 ) ;
V_62 = F_33 ( V_58 , V_136 , V_63 , & V_132 ) ;
if ( ! V_62 )
return V_110 ;
V_137 = V_67 -> V_75 ;
V_138 = V_67 -> V_89 ;
F_36 ( & V_147 ) ;
if ( V_45 == V_29 )
V_46 = F_30 ( V_58 , V_60 , V_62 , V_63 , V_2 ,
V_65 ) ;
else
V_46 = F_28 ( V_58 , V_60 , V_62 , V_63 , V_2 ,
V_65 ) ;
F_4 ( L_20 ,
V_137 , V_67 -> V_75 , V_138 , V_67 -> V_89 ) ;
F_37 ( & V_147 ) ;
return V_46 ;
}
static void F_38 ( struct V_4 * V_4 )
{
F_39 ( V_4 ) ;
}
static int T_4 F_40 ( void )
{
int V_148 ;
V_148 = F_41 ( & V_149 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_42 ( & V_150 ) ;
if ( V_148 < 0 )
F_43 ( & V_149 ) ;
return V_148 ;
}
static void T_5 F_44 ( void )
{
F_43 ( & V_149 ) ;
F_45 ( & V_150 ) ;
}
