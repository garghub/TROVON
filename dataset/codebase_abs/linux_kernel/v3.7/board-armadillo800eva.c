static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 ,
void T_1 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_5 ) {
F_4 ( V_7 -> V_8 ) ;
F_4 ( V_7 -> V_9 ) ;
F_4 ( V_7 -> V_10 ) ;
F_4 ( V_7 -> V_11 ) ;
F_4 ( V_7 -> V_12 ) ;
F_5 ( 0xd750 , V_13 ) ;
F_6 ( 1 ) ;
F_7 ( 0x0000000c , V_7 -> V_14 + V_15 ) ;
F_7 ( 0x00000008 , V_7 -> V_14 + V_15 ) ;
F_6 ( 10 ) ;
F_5 ( 0xd770 , V_13 ) ;
F_5 ( 0x4000 , V_4 + 0x102 ) ;
} else {
F_7 ( 0x0000010f , V_7 -> V_14 + V_15 ) ;
F_5 ( 0xd7c0 , V_13 ) ;
F_8 ( V_7 -> V_12 ) ;
F_8 ( V_7 -> V_11 ) ;
F_8 ( V_7 -> V_10 ) ;
F_8 ( V_7 -> V_9 ) ;
F_8 ( V_7 -> V_8 ) ;
}
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_16 ) ;
}
static T_2 F_11 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
F_12 ( V_2 ) ;
return V_19 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( ! F_14 ( V_7 -> V_12 ) )
F_15 ( V_7 -> V_12 ) ;
if ( ! F_14 ( V_7 -> V_8 ) )
F_15 ( V_7 -> V_8 ) ;
if ( ! F_14 ( V_7 -> V_9 ) )
F_15 ( V_7 -> V_9 ) ;
if ( ! F_14 ( V_7 -> V_10 ) )
F_15 ( V_7 -> V_10 ) ;
if ( ! F_14 ( V_7 -> V_11 ) )
F_15 ( V_7 -> V_11 ) ;
if ( V_7 -> V_14 )
F_16 ( V_7 -> V_14 ) ;
V_7 -> V_12 = NULL ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
V_7 -> V_10 = NULL ;
V_7 -> V_11 = NULL ;
V_7 -> V_14 = NULL ;
F_17 ( V_20 , V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_21 ;
V_7 -> V_12 = F_19 ( & V_2 -> V_22 , L_1 ) ;
V_7 -> V_8 = F_19 ( & V_2 -> V_22 , L_2 ) ;
V_7 -> V_9 = F_19 ( & V_2 -> V_22 , L_3 ) ;
V_7 -> V_11 = F_19 ( & V_2 -> V_22 , L_4 ) ;
V_7 -> V_10 = F_19 ( & V_2 -> V_22 , L_5 ) ;
V_7 -> V_14 = F_20 ( V_23 , 0x20000 ) ;
if ( F_14 ( V_7 -> V_12 ) ||
F_14 ( V_7 -> V_8 ) ||
F_14 ( V_7 -> V_9 ) ||
F_14 ( V_7 -> V_10 ) ||
F_14 ( V_7 -> V_11 ) ||
! V_7 -> V_14 ) {
F_21 ( & V_2 -> V_22 , L_6 ) ;
F_13 ( V_2 ) ;
return - V_24 ;
}
V_21 = F_22 ( V_20 , F_11 , V_25 ,
F_23 ( & V_2 -> V_22 ) , V_2 ) ;
if ( V_21 ) {
F_21 ( & V_2 -> V_22 , L_7 ) ;
return V_21 ;
}
F_24 ( V_20 , V_26 ) ;
F_25 ( V_7 -> V_8 ,
F_26 ( F_27 ( V_7 -> V_8 ) ) ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_22 , int V_28 )
{
struct V_29 * V_30 = F_19 ( NULL , L_8 ) ;
if ( F_14 ( V_30 ) ) {
F_21 ( V_22 , L_9 ) ;
return - V_31 ;
}
if ( V_28 ) {
F_25 ( V_30 , F_29 ( V_30 , 24000000 ) ) ;
F_4 ( V_30 ) ;
F_30 ( V_32 , 1 ) ;
} else {
F_30 ( V_32 , 0 ) ;
F_8 ( V_30 ) ;
}
F_15 ( V_30 ) ;
return 0 ;
}
static int F_31 ( struct V_27 * V_22 , int V_33 , int V_5 )
{
struct V_29 * V_34 ;
int V_21 ;
if ( 48000 != V_33 )
return - V_31 ;
V_34 = F_19 ( V_22 , L_10 ) ;
if ( F_14 ( V_34 ) )
return - V_31 ;
if ( V_5 ) {
V_21 = V_35 | V_36 ;
F_4 ( V_34 ) ;
} else {
V_21 = 0 ;
F_8 ( V_34 ) ;
}
F_15 ( V_34 ) ;
return V_21 ;
}
static void T_3 F_32 ( void )
{
struct V_29 * system = F_19 ( NULL , L_11 ) ;
struct V_29 * V_37 = F_19 ( NULL , L_12 ) ;
struct V_29 * V_38 = F_19 ( NULL , L_13 ) ;
struct V_29 * V_39 = F_19 ( NULL , L_14 ) ;
struct V_29 * V_34 = F_19 ( & V_40 . V_22 , L_10 ) ;
if ( F_14 ( system ) ||
F_14 ( V_37 ) ||
F_14 ( V_38 ) ||
F_14 ( V_39 ) ||
F_14 ( V_34 ) ) {
F_33 ( L_15 ) ;
goto V_41;
}
F_25 ( V_37 , 24000000 ) ;
F_34 ( V_38 , system ) ;
F_34 ( V_34 , V_39 ) ;
F_25 ( V_39 , 12288000 ) ;
F_25 ( V_34 , 12288000 ) ;
V_41:
if ( ! F_14 ( system ) )
F_15 ( system ) ;
if ( ! F_14 ( V_37 ) )
F_15 ( V_37 ) ;
if ( ! F_14 ( V_38 ) )
F_15 ( V_38 ) ;
if ( ! F_14 ( V_39 ) )
F_15 ( V_39 ) ;
if ( ! F_14 ( V_34 ) )
F_15 ( V_34 ) ;
}
static void T_3 F_35 ( void )
{
struct V_1 * V_42 = NULL ;
F_36 ( 0 , L_16 , V_43 ,
F_37 ( V_43 ) , 3300000 ) ;
F_38 () ;
F_39 () ;
F_40 ( V_44 , NULL ) ;
F_40 ( V_45 , NULL ) ;
F_40 ( V_46 , NULL ) ;
F_40 ( V_47 , NULL ) ;
F_40 ( V_48 , NULL ) ;
F_40 ( V_49 , NULL ) ;
F_40 ( V_50 , NULL ) ;
F_40 ( V_51 , NULL ) ;
F_40 ( V_52 , NULL ) ;
F_40 ( V_53 , NULL ) ;
F_40 ( V_54 , NULL ) ;
F_40 ( V_55 , NULL ) ;
F_40 ( V_56 , NULL ) ;
F_40 ( V_57 , NULL ) ;
F_40 ( V_58 , NULL ) ;
F_40 ( V_59 , NULL ) ;
F_40 ( V_60 , NULL ) ;
F_40 ( V_61 , NULL ) ;
F_40 ( V_62 , NULL ) ;
F_40 ( V_63 , NULL ) ;
F_40 ( V_64 , NULL ) ;
F_40 ( V_65 , NULL ) ;
F_40 ( V_66 , NULL ) ;
F_40 ( V_67 , NULL ) ;
F_40 ( V_68 , NULL ) ;
F_40 ( V_69 , NULL ) ;
F_40 ( V_70 , NULL ) ;
F_40 ( V_71 , NULL ) ;
F_40 ( V_72 , NULL ) ;
F_40 ( V_73 , NULL ) ;
F_40 ( V_74 , NULL ) ;
F_40 ( V_75 , NULL ) ;
F_40 ( V_76 , NULL ) ;
F_30 ( V_76 , 1 ) ;
F_40 ( V_77 , NULL ) ;
F_30 ( V_77 , 0 ) ;
F_40 ( V_78 , NULL ) ;
F_40 ( V_79 , NULL ) ;
F_30 ( V_79 , 1 ) ;
F_40 ( V_80 , NULL ) ;
F_40 ( V_81 , NULL ) ;
F_40 ( V_82 , NULL ) ;
F_40 ( V_83 , NULL ) ;
F_40 ( V_84 , NULL ) ;
F_40 ( V_85 , NULL ) ;
F_40 ( V_86 , NULL ) ;
F_40 ( V_87 , NULL ) ;
F_40 ( V_88 , NULL ) ;
F_40 ( V_89 , NULL ) ;
F_40 ( V_90 , NULL ) ;
F_40 ( V_91 , NULL ) ;
F_40 ( V_92 , NULL ) ;
F_40 ( V_93 , NULL ) ;
F_40 ( V_94 , NULL ) ;
F_40 ( V_95 , NULL ) ;
F_40 ( V_96 , NULL ) ;
F_40 ( V_97 , NULL ) ;
F_40 ( V_98 , NULL ) ;
F_40 ( V_99 , NULL ) ;
F_30 ( V_99 , 1 ) ;
F_40 ( V_100 , NULL ) ;
F_41 ( V_100 ) ;
if ( F_10 ( V_100 ) ) {
} else {
F_40 ( V_101 , NULL ) ;
F_40 ( V_16 , NULL ) ;
F_41 ( V_16 ) ;
F_42 ( & V_102 ) ;
V_42 = & V_102 ;
}
F_40 ( V_103 , NULL ) ;
F_40 ( V_104 , NULL ) ;
F_40 ( V_105 , NULL ) ;
F_40 ( V_106 , NULL ) ;
F_40 ( V_107 , NULL ) ;
F_40 ( V_108 , NULL ) ;
F_40 ( V_109 , NULL ) ;
F_40 ( V_110 , NULL ) ;
F_40 ( V_111 , NULL ) ;
F_40 ( V_112 , NULL ) ;
F_30 ( V_110 , 0 ) ;
F_30 ( V_111 , 1 ) ;
F_30 ( V_112 , 1 ) ;
F_40 ( V_113 , NULL ) ;
F_40 ( V_114 , NULL ) ;
F_40 ( V_115 , NULL ) ;
F_40 ( V_116 , NULL ) ;
F_40 ( V_117 , NULL ) ;
F_40 ( V_118 , NULL ) ;
F_40 ( V_119 , NULL ) ;
F_40 ( V_120 , NULL ) ;
F_40 ( V_121 , NULL ) ;
F_40 ( V_122 , NULL ) ;
F_40 ( V_123 , NULL ) ;
F_40 ( V_124 , NULL ) ;
F_40 ( V_125 , NULL ) ;
F_40 ( V_126 , NULL ) ;
F_40 ( V_127 , NULL ) ;
F_40 ( V_128 , NULL ) ;
F_40 ( V_129 , NULL ) ;
F_40 ( V_130 , NULL ) ;
F_40 ( V_131 , NULL ) ;
F_40 ( V_132 , NULL ) ;
F_40 ( V_133 , NULL ) ;
F_40 ( V_134 , NULL ) ;
F_40 ( V_135 , NULL ) ;
F_40 ( V_136 , NULL ) ;
F_40 ( V_137 , NULL ) ;
F_40 ( V_32 , NULL ) ;
F_30 ( V_136 , 0 ) ;
F_30 ( V_137 , 1 ) ;
F_30 ( V_32 , 0 ) ;
F_40 ( V_138 , NULL ) ;
F_40 ( V_139 , NULL ) ;
F_40 ( V_140 , NULL ) ;
F_40 ( V_141 , NULL ) ;
F_40 ( V_142 , NULL ) ;
F_40 ( V_143 , NULL ) ;
F_40 ( V_144 , NULL ) ;
F_43 ( V_145 ) ;
F_43 ( V_146 ) ;
F_40 ( V_147 , NULL ) ;
F_40 ( V_148 , NULL ) ;
F_40 ( V_149 , NULL ) ;
F_40 ( V_150 , NULL ) ;
F_30 ( V_150 , 1 ) ;
F_40 ( V_151 , NULL ) ;
F_41 ( V_151 ) ;
if ( F_10 ( V_151 ) ) {
} else {
F_40 ( V_152 , NULL ) ;
F_40 ( V_153 , NULL ) ;
F_40 ( V_154 , NULL ) ;
F_40 ( V_155 , NULL ) ;
F_40 ( V_156 , NULL ) ;
F_40 ( V_157 , NULL ) ;
F_40 ( V_158 , NULL ) ;
F_40 ( V_159 , NULL ) ;
F_40 ( V_160 , NULL ) ;
F_30 ( V_160 , 1 ) ;
F_42 ( & V_161 ) ;
}
#ifdef F_44
F_45 ( F_46 ( 0xf0002000 ) , 0x40440000 , 0x82000fff ) ;
#endif
F_47 ( 0 , V_162 , F_37 ( V_162 ) ) ;
F_47 ( 2 , V_163 , F_37 ( V_163 ) ) ;
F_48 () ;
F_49 ( V_164 ,
F_37 ( V_164 ) ) ;
F_32 () ;
F_50 ( L_17 , & V_165 ) ;
F_50 ( L_17 , & V_166 ) ;
if ( V_42 )
F_50 ( L_18 , V_42 ) ;
}
static void T_3 F_51 ( void )
{
F_52 ( V_167 | V_168 ) ;
F_53 () ;
}
static void T_3 F_54 ( void )
{
F_55 () ;
V_169 . V_170 = F_51 ;
}
