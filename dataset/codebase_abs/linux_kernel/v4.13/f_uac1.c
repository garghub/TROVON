static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
int V_11 = - V_12 ;
T_1 V_13 = F_4 ( V_7 -> V_14 ) ;
T_1 V_15 = F_4 ( V_7 -> V_16 ) ;
T_1 V_17 = F_4 ( V_7 -> V_18 ) ;
F_5 ( V_9 , L_1 ,
V_7 -> V_19 , V_17 , V_15 , V_13 ) ;
switch ( V_7 -> V_19 ) {
case V_20 :
V_11 = V_15 ;
break;
case V_21 :
break;
case V_22 :
break;
case V_23 :
break;
case V_24 :
break;
default:
break;
}
return V_11 ;
}
static int F_6 ( struct V_2 * V_3 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
int V_11 = - V_12 ;
T_2 V_13 = ( ( F_4 ( V_7 -> V_14 ) >> 8 ) & 0xFF ) ;
T_1 V_15 = F_4 ( V_7 -> V_16 ) ;
T_1 V_17 = F_4 ( V_7 -> V_18 ) ;
F_5 ( V_9 , L_1 ,
V_7 -> V_19 , V_17 , V_15 , V_13 ) ;
switch ( V_7 -> V_19 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
V_11 = V_15 ;
break;
case V_29 :
break;
default:
break;
}
return V_11 ;
}
static int
F_7 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
struct V_30 * V_31 = V_9 -> V_31 ;
int V_11 = - V_12 ;
T_1 V_32 = F_4 ( V_7 -> V_14 ) ;
T_1 V_17 = F_4 ( V_7 -> V_18 ) ;
T_1 V_33 = F_4 ( V_7 -> V_16 ) ;
switch ( V_7 -> V_34 ) {
case V_35 | V_36 | V_37 :
V_11 = F_3 ( V_3 , V_7 ) ;
break;
case V_38 | V_36 | V_37 :
V_11 = F_6 ( V_3 , V_7 ) ;
break;
default:
ERROR ( V_9 , L_2 ,
V_7 -> V_34 , V_7 -> V_19 ,
V_17 , V_32 , V_33 ) ;
}
if ( V_11 >= 0 ) {
F_5 ( V_9 , L_3 ,
V_7 -> V_34 , V_7 -> V_19 ,
V_17 , V_32 , V_33 ) ;
V_31 -> V_39 = 0 ;
V_31 -> V_40 = V_11 ;
V_11 = F_8 ( V_9 -> V_41 -> V_42 , V_31 , V_43 ) ;
if ( V_11 < 0 )
ERROR ( V_9 , L_4 , V_11 ) ;
}
return V_11 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_44 , unsigned V_45 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
struct V_46 * V_41 = V_9 -> V_41 ;
struct V_47 * V_48 = & V_41 -> V_48 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
int V_50 = 0 ;
if ( V_45 > 1 ) {
F_10 ( V_48 , L_5 , V_51 , __LINE__ ) ;
return - V_52 ;
}
if ( V_44 == V_49 -> V_53 ) {
if ( V_45 ) {
F_10 ( V_48 , L_5 , V_51 , __LINE__ ) ;
return - V_52 ;
}
return 0 ;
}
if ( V_44 == V_49 -> V_54 ) {
V_49 -> V_55 = V_45 ;
if ( V_45 )
V_50 = F_11 ( & V_49 -> V_4 ) ;
else
F_12 ( & V_49 -> V_4 ) ;
} else if ( V_44 == V_49 -> V_56 ) {
V_49 -> V_57 = V_45 ;
if ( V_45 )
V_50 = F_13 ( & V_49 -> V_4 ) ;
else
F_14 ( & V_49 -> V_4 ) ;
} else {
F_10 ( V_48 , L_5 , V_51 , __LINE__ ) ;
return - V_52 ;
}
return V_50 ;
}
static int F_15 ( struct V_2 * V_3 , unsigned V_44 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
struct V_46 * V_41 = V_9 -> V_41 ;
struct V_47 * V_48 = & V_41 -> V_48 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
if ( V_44 == V_49 -> V_53 )
return V_49 -> V_58 ;
else if ( V_44 == V_49 -> V_54 )
return V_49 -> V_55 ;
else if ( V_44 == V_49 -> V_56 )
return V_49 -> V_57 ;
else
F_10 ( V_48 , L_6 ,
V_51 , __LINE__ , V_44 ) ;
return - V_52 ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
V_49 -> V_55 = 0 ;
V_49 -> V_57 = 0 ;
F_12 ( & V_49 -> V_4 ) ;
}
static int F_17 ( struct V_59 * V_60 , struct V_2 * V_3 )
{
struct V_8 * V_9 = V_60 -> V_9 ;
struct V_46 * V_41 = V_9 -> V_41 ;
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_4 * V_61 = F_18 ( V_3 ) ;
struct V_62 * V_63 ;
struct V_64 * V_13 = NULL ;
struct V_65 * V_66 ;
T_2 * V_67 ;
int V_68 ;
int V_69 ;
V_63 = F_2 ( V_3 -> V_70 , struct V_62 , V_71 ) ;
V_66 = F_19 ( V_9 , V_72 , F_20 ( V_73 ) ) ;
if ( F_21 ( V_66 ) )
return F_22 ( V_66 ) ;
V_74 . V_75 = V_66 [ V_76 ] . V_77 ;
V_78 . V_79 = V_66 [ V_80 ] . V_77 ;
V_78 . V_81 = V_66 [ V_82 ] . V_77 ;
V_83 . V_79 = V_66 [ V_84 ] . V_77 ;
V_85 . V_75 = V_66 [ V_86 ] . V_77 ;
V_87 . V_75 = V_66 [ V_88 ] . V_77 ;
V_89 . V_79 = V_66 [ V_90 ] . V_77 ;
V_89 . V_81 = V_66 [ V_91 ] . V_77 ;
V_92 . V_79 = V_66 [ V_93 ] . V_77 ;
V_94 . V_75 = V_66 [ V_95 ] . V_77 ;
V_96 . V_75 = V_66 [ V_97 ] . V_77 ;
V_78 . V_98 = F_23 ( V_63 -> V_99 ) ;
V_78 . V_100 = F_24 ( V_63 -> V_99 ) ;
V_101 . V_98 = F_23 ( V_63 -> V_99 ) ;
V_101 . V_102 = V_63 -> V_103 ;
V_101 . V_104 = V_63 -> V_103 * 8 ;
V_89 . V_98 = F_23 ( V_63 -> V_105 ) ;
V_89 . V_100 = F_24 ( V_63 -> V_105 ) ;
V_106 . V_98 = F_23 ( V_63 -> V_105 ) ;
V_106 . V_102 = V_63 -> V_107 ;
V_106 . V_104 = V_63 -> V_107 * 8 ;
V_68 = V_63 -> V_108 ;
V_67 = V_101 . V_109 [ 0 ] ;
memcpy ( V_67 , & V_68 , 3 ) ;
V_68 = V_63 -> V_110 ;
V_67 = V_106 . V_109 [ 0 ] ;
memcpy ( V_67 , & V_68 , 3 ) ;
V_69 = F_25 ( V_60 , V_3 ) ;
if ( V_69 < 0 )
goto V_111;
V_74 . V_112 = V_69 ;
V_49 -> V_53 = V_69 ;
V_49 -> V_58 = 0 ;
V_69 = F_25 ( V_60 , V_3 ) ;
if ( V_69 < 0 )
goto V_111;
V_85 . V_112 = V_69 ;
V_87 . V_112 = V_69 ;
V_49 -> V_54 = V_69 ;
V_49 -> V_55 = 0 ;
V_69 = F_25 ( V_60 , V_3 ) ;
if ( V_69 < 0 )
goto V_111;
V_94 . V_112 = V_69 ;
V_96 . V_112 = V_69 ;
V_49 -> V_56 = V_69 ;
V_49 -> V_57 = 0 ;
V_61 -> V_41 = V_41 ;
V_69 = - V_113 ;
V_13 = F_26 ( V_9 -> V_41 , & V_114 ) ;
if ( ! V_13 )
goto V_111;
V_61 -> V_115 = V_13 ;
V_61 -> V_115 -> V_116 = & V_114 ;
V_13 = F_26 ( V_9 -> V_41 , & V_117 ) ;
if ( ! V_13 )
goto V_111;
V_61 -> V_118 = V_13 ;
V_61 -> V_118 -> V_116 = & V_117 ;
V_69 = F_27 ( V_3 , V_119 , V_119 , NULL ,
NULL ) ;
if ( V_69 )
goto V_111;
V_61 -> V_120 = F_4 ( V_114 . V_121 ) ;
V_61 -> V_122 = F_4 ( V_117 . V_121 ) ;
V_61 -> V_123 . V_99 = V_63 -> V_99 ;
V_61 -> V_123 . V_108 = V_63 -> V_108 ;
V_61 -> V_123 . V_103 = V_63 -> V_103 ;
V_61 -> V_123 . V_105 = V_63 -> V_105 ;
V_61 -> V_123 . V_110 = V_63 -> V_110 ;
V_61 -> V_123 . V_107 = V_63 -> V_107 ;
V_61 -> V_123 . V_124 = V_63 -> V_124 ;
V_69 = F_28 ( V_61 , L_7 , L_8 ) ;
if ( V_69 )
goto V_125;
return 0 ;
V_125:
F_29 ( V_3 ) ;
V_111:
return V_69 ;
}
static inline struct V_62 * F_30 ( struct V_126 * V_127 )
{
return F_2 ( F_31 ( V_127 ) , struct V_62 ,
V_71 . V_128 ) ;
}
static void F_32 ( struct V_126 * V_127 )
{
struct V_62 * V_129 = F_30 ( V_127 ) ;
F_33 ( & V_129 -> V_71 ) ;
}
static void F_34 ( struct V_130 * V_3 )
{
struct V_62 * V_129 ;
V_129 = F_2 ( V_3 , struct V_62 , V_71 ) ;
F_35 ( V_129 ) ;
}
static struct V_130 * F_36 ( void )
{
struct V_62 * V_129 ;
V_129 = F_37 ( sizeof( * V_129 ) , V_131 ) ;
if ( ! V_129 )
return F_38 ( - V_132 ) ;
F_39 ( & V_129 -> V_133 ) ;
V_129 -> V_71 . V_134 = F_34 ;
F_40 ( & V_129 -> V_71 . V_128 , L_9 ,
& V_135 ) ;
V_129 -> V_99 = V_136 ;
V_129 -> V_108 = V_137 ;
V_129 -> V_103 = V_138 ;
V_129 -> V_105 = V_139 ;
V_129 -> V_110 = V_140 ;
V_129 -> V_107 = V_141 ;
V_129 -> V_124 = V_142 ;
return & V_129 -> V_71 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_4 * V_61 ;
struct V_62 * V_129 ;
V_61 = F_18 ( V_3 ) ;
V_129 = F_2 ( V_3 -> V_70 , struct V_62 , V_71 ) ;
F_35 ( V_61 ) ;
F_42 ( & V_129 -> V_133 ) ;
-- V_129 -> V_143 ;
F_43 ( & V_129 -> V_133 ) ;
}
static void F_44 ( struct V_59 * V_60 , struct V_2 * V_3 )
{
struct V_4 * V_61 = F_18 ( V_3 ) ;
F_45 ( V_61 ) ;
F_29 ( V_3 ) ;
V_61 -> V_41 = NULL ;
}
static struct V_2 * F_46 ( struct V_130 * V_70 )
{
struct V_1 * V_49 ;
struct V_62 * V_129 ;
V_49 = F_37 ( sizeof( * V_49 ) , V_131 ) ;
if ( ! V_49 )
return F_38 ( - V_132 ) ;
V_129 = F_2 ( V_70 , struct V_62 , V_71 ) ;
F_42 ( & V_129 -> V_133 ) ;
++ V_129 -> V_143 ;
F_43 ( & V_129 -> V_133 ) ;
V_49 -> V_4 . V_5 . V_144 = L_10 ;
V_49 -> V_4 . V_5 . V_145 = F_17 ;
V_49 -> V_4 . V_5 . V_146 = F_44 ;
V_49 -> V_4 . V_5 . V_147 = F_9 ;
V_49 -> V_4 . V_5 . V_148 = F_15 ;
V_49 -> V_4 . V_5 . V_149 = F_7 ;
V_49 -> V_4 . V_5 . V_150 = F_16 ;
V_49 -> V_4 . V_5 . V_151 = F_41 ;
return & V_49 -> V_4 . V_5 ;
}
