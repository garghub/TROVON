static void F_1 ( struct V_1 * V_2 ,
struct V_3 * exp )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_3 (nf_nat_pptp_hook_expectfn) V_5 ;
F_4 ( L_1 ) ;
V_2 -> V_6 . V_7 . V_8 = V_9 ;
V_2 -> V_6 . V_7 . V_10 = V_11 ;
V_5 = F_5 ( V_12 ) ;
if ( V_5 && V_2 -> V_13 -> V_14 & V_15 )
V_5 ( V_2 , exp ) ;
else {
struct V_16 V_17 ;
struct V_3 * V_18 ;
F_6 ( & V_17 , & exp -> V_19 ) ;
F_4 ( L_2 ) ;
F_7 ( & V_17 ) ;
V_18 = F_8 ( V_4 , F_9 ( V_2 ) , & V_17 ) ;
if ( V_18 ) {
F_4 ( L_3 ) ;
F_10 ( V_18 ) ;
F_11 ( V_18 ) ;
} else {
F_4 ( L_4 ) ;
}
}
}
static int F_12 ( struct V_4 * V_4 , struct V_1 * V_2 ,
const struct V_16 * V_20 )
{
const struct V_21 * V_22 ;
const struct V_23 * V_24 ;
struct V_3 * exp ;
struct V_1 * V_25 ;
F_4 ( L_5 ) ;
F_7 ( V_20 ) ;
V_24 = F_9 ( V_2 ) ;
V_22 = F_13 ( V_4 , V_24 , V_20 ) ;
if ( V_22 ) {
V_25 = F_14 ( V_22 ) ;
F_4 ( L_6 , V_25 ) ;
V_25 -> V_6 . V_7 . V_8 = 0 ;
V_25 -> V_6 . V_7 . V_10 = 0 ;
F_15 ( V_25 ) ;
F_16 ( V_25 ) ;
return 1 ;
} else {
exp = F_8 ( V_4 , V_24 , V_20 ) ;
if ( exp ) {
F_4 ( L_7 , exp ) ;
F_10 ( exp ) ;
F_11 ( exp ) ;
return 1 ;
}
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
const struct V_26 * V_27 = F_18 ( V_2 ) ;
struct V_16 V_20 ;
F_19 ( V_2 ) ;
memcpy ( & V_20 , & V_2 -> V_28 [ V_29 ] . V_19 , sizeof( V_20 ) ) ;
V_20 . V_30 . V_31 = V_32 ;
V_20 . V_33 . V_34 . V_7 . V_35 = V_27 -> V_36 ;
V_20 . V_30 . V_34 . V_7 . V_35 = V_27 -> V_37 ;
if ( ! F_12 ( V_4 , V_2 , & V_20 ) )
F_4 ( L_8 ) ;
memcpy ( & V_20 , & V_2 -> V_28 [ V_38 ] . V_19 , sizeof( V_20 ) ) ;
V_20 . V_30 . V_31 = V_32 ;
V_20 . V_33 . V_34 . V_7 . V_35 = V_27 -> V_37 ;
V_20 . V_30 . V_34 . V_7 . V_35 = V_27 -> V_36 ;
if ( ! F_12 ( V_4 , V_2 , & V_20 ) )
F_4 ( L_9 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_40 )
{
struct V_3 * V_41 , * V_42 ;
enum V_43 V_44 ;
int V_45 = 1 ;
F_3 (nf_nat_pptp_hook_exp_gre) V_46 ;
V_41 = F_21 ( V_2 ) ;
if ( V_41 == NULL )
goto V_47;
V_42 = F_21 ( V_2 ) ;
if ( V_42 == NULL )
goto V_48;
V_44 = V_29 ;
F_22 ( V_41 , V_49 ,
F_23 ( V_2 ) ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_33 . V_50 ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_30 . V_50 ,
V_32 , & V_40 , & V_39 ) ;
V_41 -> V_51 = F_1 ;
V_44 = V_38 ;
F_22 ( V_42 , V_49 ,
F_23 ( V_2 ) ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_33 . V_50 ,
& V_2 -> V_28 [ V_44 ] . V_19 . V_30 . V_50 ,
V_32 , & V_39 , & V_40 ) ;
V_42 -> V_51 = F_1 ;
V_46 = F_5 ( V_52 ) ;
if ( V_46 && V_2 -> V_14 & V_15 )
V_46 ( V_41 , V_42 ) ;
if ( F_24 ( V_41 ) != 0 )
goto V_53;
if ( F_24 ( V_42 ) != 0 )
goto V_54;
if ( F_25 ( V_2 , V_29 , & V_41 -> V_19 ) != 0 )
goto V_55;
if ( F_25 ( V_2 , V_38 , & V_42 -> V_19 ) != 0 ) {
F_19 ( V_2 ) ;
goto V_55;
}
V_45 = 0 ;
V_53:
F_11 ( V_42 ) ;
V_48:
F_11 ( V_41 ) ;
V_47:
return V_45 ;
V_55:
F_10 ( V_42 ) ;
V_54:
F_10 ( V_41 ) ;
goto V_53;
}
static int
F_26 ( struct V_56 * V_57 , unsigned int V_58 ,
struct V_59 * V_60 ,
union V_61 * V_62 ,
unsigned int V_63 ,
struct V_1 * V_2 ,
enum V_64 V_65 )
{
struct V_26 * V_66 = F_18 ( V_2 ) ;
T_2 V_67 ;
T_1 V_68 = 0 , V_69 = 0 ;
F_3 (nf_nat_pptp_hook_inbound) V_70 ;
V_67 = F_27 ( V_60 -> V_71 ) ;
F_4 ( L_10 , V_72 [ V_67 ] ) ;
switch ( V_67 ) {
case V_73 :
if ( V_66 -> V_74 < V_75 )
goto V_76;
if ( V_62 -> V_77 . V_78 == V_79 )
V_66 -> V_74 = V_80 ;
else
V_66 -> V_74 = V_81 ;
break;
case V_82 :
if ( V_66 -> V_74 > V_83 )
goto V_76;
if ( V_62 -> V_84 . V_78 == V_85 )
V_66 -> V_74 = V_86 ;
else
V_66 -> V_74 = V_81 ;
break;
case V_87 :
if ( V_66 -> V_74 != V_80 )
goto V_76;
if ( V_66 -> V_88 != V_89 &&
V_66 -> V_88 != V_90 )
goto V_76;
V_68 = V_62 -> V_91 . V_92 ;
V_69 = V_62 -> V_91 . V_93 ;
if ( V_66 -> V_36 != V_69 )
goto V_76;
F_4 ( L_11 , V_72 [ V_67 ] ,
F_27 ( V_68 ) , F_27 ( V_69 ) ) ;
if ( V_62 -> V_91 . V_78 == V_94 ) {
V_66 -> V_88 = V_90 ;
V_66 -> V_37 = V_68 ;
F_20 ( V_2 , V_68 , V_69 ) ;
} else
V_66 -> V_88 = V_95 ;
break;
case V_96 :
if ( V_66 -> V_74 != V_80 )
goto V_76;
V_68 = V_62 -> V_97 . V_92 ;
F_4 ( L_12 , V_72 [ V_67 ] , F_27 ( V_68 ) ) ;
V_66 -> V_88 = V_98 ;
V_66 -> V_37 = V_68 ;
break;
case V_99 :
if ( V_66 -> V_74 != V_80 )
goto V_76;
if ( V_66 -> V_88 != V_100 &&
V_66 -> V_88 != V_101 )
goto V_76;
V_69 = V_62 -> V_102 . V_93 ;
V_68 = V_66 -> V_37 ;
if ( V_66 -> V_36 != V_69 )
goto V_76;
F_4 ( L_13 , V_72 [ V_67 ] , F_27 ( V_69 ) ) ;
V_66 -> V_88 = V_101 ;
F_20 ( V_2 , V_68 , V_69 ) ;
break;
case V_103 :
V_68 = V_62 -> V_104 . V_92 ;
F_4 ( L_12 , V_72 [ V_67 ] , F_27 ( V_68 ) ) ;
V_66 -> V_88 = V_95 ;
F_17 ( V_2 ) ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
break;
default:
goto V_76;
}
V_70 = F_5 ( V_109 ) ;
if ( V_70 && V_2 -> V_14 & V_15 )
return V_70 ( V_57 , V_2 , V_65 ,
V_58 , V_60 , V_62 ) ;
return V_110 ;
V_76:
F_4 ( L_14
L_15 ,
V_67 <= V_111 ? V_72 [ V_67 ] : V_72 [ 0 ] ,
V_67 , F_27 ( V_68 ) , F_27 ( V_69 ) , V_66 -> V_88 , V_66 -> V_74 ,
F_27 ( V_66 -> V_36 ) , F_27 ( V_66 -> V_37 ) ) ;
return V_110 ;
}
static int
F_28 ( struct V_56 * V_57 , unsigned int V_58 ,
struct V_59 * V_60 ,
union V_61 * V_62 ,
unsigned int V_63 ,
struct V_1 * V_2 ,
enum V_64 V_65 )
{
struct V_26 * V_66 = F_18 ( V_2 ) ;
T_2 V_67 ;
T_1 V_68 = 0 , V_69 = 0 ;
F_3 (nf_nat_pptp_hook_outbound) V_112 ;
V_67 = F_27 ( V_60 -> V_71 ) ;
F_4 ( L_16 , V_72 [ V_67 ] ) ;
switch ( V_67 ) {
case V_113 :
if ( V_66 -> V_74 != V_86 )
goto V_76;
V_66 -> V_74 = V_75 ;
break;
case V_114 :
V_66 -> V_74 = V_83 ;
break;
case V_115 :
if ( V_66 -> V_74 != V_80 )
goto V_76;
V_66 -> V_88 = V_89 ;
V_68 = V_62 -> V_116 . V_92 ;
F_4 ( L_12 , V_72 [ V_67 ] , F_27 ( V_68 ) ) ;
V_66 -> V_36 = V_68 ;
break;
case V_117 :
if ( V_66 -> V_88 != V_98 &&
V_66 -> V_88 != V_100 )
goto V_76;
V_68 = V_62 -> V_118 . V_92 ;
V_69 = V_62 -> V_118 . V_93 ;
if ( V_66 -> V_37 != V_69 )
goto V_76;
F_4 ( L_17 , V_72 [ V_67 ] ,
F_27 ( V_68 ) , F_27 ( V_69 ) ) ;
if ( V_62 -> V_118 . V_78 == V_119 ) {
V_66 -> V_88 = V_100 ;
V_66 -> V_36 = V_68 ;
} else
V_66 -> V_88 = V_95 ;
break;
case V_120 :
if ( V_66 -> V_74 != V_80 )
goto V_76;
V_66 -> V_88 = V_121 ;
break;
case V_106 :
case V_107 :
case V_108 :
break;
default:
goto V_76;
}
V_112 = F_5 ( V_122 ) ;
if ( V_112 && V_2 -> V_14 & V_15 )
return V_112 ( V_57 , V_2 , V_65 ,
V_58 , V_60 , V_62 ) ;
return V_110 ;
V_76:
F_4 ( L_14
L_15 ,
V_67 <= V_111 ? V_72 [ V_67 ] : V_72 [ 0 ] ,
V_67 , F_27 ( V_68 ) , F_27 ( V_69 ) , V_66 -> V_88 , V_66 -> V_74 ,
F_27 ( V_66 -> V_36 ) , F_27 ( V_66 -> V_37 ) ) ;
return V_110 ;
}
static int
F_29 ( struct V_56 * V_57 , unsigned int V_58 ,
struct V_1 * V_2 , enum V_64 V_65 )
{
int V_44 = F_30 ( V_65 ) ;
const struct V_26 * V_66 = F_18 ( V_2 ) ;
const struct V_123 * V_124 ;
struct V_123 V_125 ;
const struct V_126 * V_127 ;
struct V_126 V_128 ;
struct V_59 V_129 , * V_60 ;
union V_61 V_130 , * V_62 ;
unsigned int V_131 = V_57 -> V_132 - V_58 ;
unsigned int V_133 , V_63 , V_134 ;
int V_135 , V_136 ;
int V_45 ;
T_2 V_67 ;
#if F_31 ( V_137 )
if ( ! F_32 ( V_2 ) && ( V_2 -> V_14 & V_15 ) ) {
struct V_138 * V_139 = F_33 ( V_2 , V_140 ) ;
if ( ! V_139 && ! F_34 ( V_2 , V_140 , V_141 ) )
return V_142 ;
}
#endif
if ( V_65 != V_143 && V_65 != V_144 )
return V_110 ;
V_134 = V_58 ;
V_124 = F_35 ( V_57 , V_134 , sizeof( V_125 ) , & V_125 ) ;
F_36 ( ! V_124 ) ;
V_134 += V_124 -> V_145 * 4 ;
V_133 = V_131 - V_124 -> V_145 * 4 ;
V_127 = F_35 ( V_57 , V_134 , sizeof( V_128 ) , & V_128 ) ;
if ( ! V_127 ) {
F_4 ( L_18 ) ;
return V_110 ;
}
V_134 += sizeof( V_128 ) ;
V_133 -= sizeof( V_128 ) ;
if ( F_27 ( V_127 -> V_146 ) != V_147 ||
F_37 ( V_127 -> V_148 ) != V_149 ) {
F_4 ( L_19 ) ;
return V_110 ;
}
V_60 = F_35 ( V_57 , V_134 , sizeof( V_129 ) , & V_129 ) ;
if ( ! V_60 )
return V_110 ;
V_134 += sizeof( V_129 ) ;
V_133 -= sizeof( V_129 ) ;
V_63 = V_133 ;
V_67 = F_27 ( V_60 -> V_71 ) ;
if ( V_67 > 0 && V_67 <= V_111 && V_63 < V_150 [ V_67 ] )
return V_110 ;
if ( V_63 > sizeof( * V_62 ) )
V_63 = sizeof( * V_62 ) ;
V_62 = F_35 ( V_57 , V_134 , V_63 , & V_130 ) ;
if ( ! V_62 )
return V_110 ;
V_135 = V_66 -> V_74 ;
V_136 = V_66 -> V_88 ;
F_38 ( & V_151 ) ;
if ( V_44 == V_29 )
V_45 = F_28 ( V_57 , V_58 , V_60 , V_62 , V_63 , V_2 ,
V_65 ) ;
else
V_45 = F_26 ( V_57 , V_58 , V_60 , V_62 , V_63 , V_2 ,
V_65 ) ;
F_4 ( L_20 ,
V_135 , V_66 -> V_74 , V_136 , V_66 -> V_88 ) ;
F_39 ( & V_151 ) ;
return V_45 ;
}
static int T_3 F_40 ( void )
{
F_41 ( sizeof( struct V_26 ) ) ;
return F_42 ( & V_152 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_152 ) ;
}
