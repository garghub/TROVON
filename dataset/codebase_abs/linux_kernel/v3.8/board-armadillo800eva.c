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
static void T_3 F_31 ( void )
{
struct V_29 * system = F_19 ( NULL , L_10 ) ;
struct V_29 * V_33 = F_19 ( NULL , L_11 ) ;
struct V_29 * V_34 = F_19 ( NULL , L_12 ) ;
struct V_29 * V_35 = F_19 ( NULL , L_13 ) ;
if ( F_14 ( system ) ||
F_14 ( V_33 ) ||
F_14 ( V_34 ) ||
F_14 ( V_35 ) ) {
F_32 ( L_14 ) ;
goto V_36;
}
F_25 ( V_33 , 24000000 ) ;
F_33 ( V_34 , system ) ;
F_25 ( V_35 , 12288000 ) ;
V_36:
if ( ! F_14 ( system ) )
F_15 ( system ) ;
if ( ! F_14 ( V_33 ) )
F_15 ( V_33 ) ;
if ( ! F_14 ( V_34 ) )
F_15 ( V_34 ) ;
if ( ! F_14 ( V_35 ) )
F_15 ( V_35 ) ;
}
static void T_3 F_34 ( void )
{
struct V_1 * V_37 = NULL ;
F_35 ( 0 , L_15 , V_38 ,
F_36 ( V_38 ) , 3300000 ) ;
F_37 () ;
F_38 () ;
F_39 ( V_39 , NULL ) ;
F_39 ( V_40 , NULL ) ;
F_39 ( V_41 , NULL ) ;
F_39 ( V_42 , NULL ) ;
F_39 ( V_43 , NULL ) ;
F_39 ( V_44 , NULL ) ;
F_39 ( V_45 , NULL ) ;
F_39 ( V_46 , NULL ) ;
F_39 ( V_47 , NULL ) ;
F_39 ( V_48 , NULL ) ;
F_39 ( V_49 , NULL ) ;
F_39 ( V_50 , NULL ) ;
F_39 ( V_51 , NULL ) ;
F_39 ( V_52 , NULL ) ;
F_39 ( V_53 , NULL ) ;
F_39 ( V_54 , NULL ) ;
F_39 ( V_55 , NULL ) ;
F_39 ( V_56 , NULL ) ;
F_39 ( V_57 , NULL ) ;
F_39 ( V_58 , NULL ) ;
F_39 ( V_59 , NULL ) ;
F_39 ( V_60 , NULL ) ;
F_39 ( V_61 , NULL ) ;
F_39 ( V_62 , NULL ) ;
F_39 ( V_63 , NULL ) ;
F_39 ( V_64 , NULL ) ;
F_39 ( V_65 , NULL ) ;
F_39 ( V_66 , NULL ) ;
F_39 ( V_67 , NULL ) ;
F_39 ( V_68 , NULL ) ;
F_39 ( V_69 , NULL ) ;
F_39 ( V_70 , NULL ) ;
F_39 ( V_71 , NULL ) ;
F_30 ( V_71 , 1 ) ;
F_39 ( V_72 , NULL ) ;
F_30 ( V_72 , 0 ) ;
F_39 ( V_73 , NULL ) ;
F_39 ( V_74 , NULL ) ;
F_30 ( V_74 , 1 ) ;
F_39 ( V_75 , NULL ) ;
F_39 ( V_76 , NULL ) ;
F_39 ( V_77 , NULL ) ;
F_39 ( V_78 , NULL ) ;
F_39 ( V_79 , NULL ) ;
F_39 ( V_80 , NULL ) ;
F_39 ( V_81 , NULL ) ;
F_39 ( V_82 , NULL ) ;
F_39 ( V_83 , NULL ) ;
F_39 ( V_84 , NULL ) ;
F_39 ( V_85 , NULL ) ;
F_39 ( V_86 , NULL ) ;
F_39 ( V_87 , NULL ) ;
F_39 ( V_88 , NULL ) ;
F_39 ( V_89 , NULL ) ;
F_39 ( V_90 , NULL ) ;
F_39 ( V_91 , NULL ) ;
F_39 ( V_92 , NULL ) ;
F_39 ( V_93 , NULL ) ;
F_39 ( V_94 , NULL ) ;
F_30 ( V_94 , 1 ) ;
F_39 ( V_95 , NULL ) ;
F_40 ( V_95 ) ;
if ( F_10 ( V_95 ) ) {
} else {
F_39 ( V_96 , NULL ) ;
F_39 ( V_16 , NULL ) ;
F_40 ( V_16 ) ;
F_41 ( & V_97 ) ;
V_37 = & V_97 ;
}
F_39 ( V_98 , NULL ) ;
F_39 ( V_99 , NULL ) ;
F_39 ( V_100 , NULL ) ;
F_39 ( V_101 , NULL ) ;
F_39 ( V_102 , NULL ) ;
F_39 ( V_103 , NULL ) ;
F_39 ( V_104 , NULL ) ;
F_39 ( V_105 , NULL ) ;
F_39 ( V_106 , NULL ) ;
F_39 ( V_107 , NULL ) ;
F_30 ( V_105 , 0 ) ;
F_30 ( V_106 , 1 ) ;
F_30 ( V_107 , 1 ) ;
F_39 ( V_108 , NULL ) ;
F_39 ( V_109 , NULL ) ;
F_39 ( V_110 , NULL ) ;
F_39 ( V_111 , NULL ) ;
F_39 ( V_112 , NULL ) ;
F_39 ( V_113 , NULL ) ;
F_39 ( V_114 , NULL ) ;
F_39 ( V_115 , NULL ) ;
F_39 ( V_116 , NULL ) ;
F_39 ( V_117 , NULL ) ;
F_39 ( V_118 , NULL ) ;
F_39 ( V_119 , NULL ) ;
F_39 ( V_120 , NULL ) ;
F_39 ( V_121 , NULL ) ;
F_39 ( V_122 , NULL ) ;
F_39 ( V_123 , NULL ) ;
F_39 ( V_124 , NULL ) ;
F_39 ( V_125 , NULL ) ;
F_39 ( V_126 , NULL ) ;
F_39 ( V_127 , NULL ) ;
F_39 ( V_128 , NULL ) ;
F_39 ( V_129 , NULL ) ;
F_39 ( V_130 , NULL ) ;
F_39 ( V_131 , NULL ) ;
F_39 ( V_132 , NULL ) ;
F_39 ( V_32 , NULL ) ;
F_30 ( V_131 , 0 ) ;
F_30 ( V_132 , 1 ) ;
F_30 ( V_32 , 0 ) ;
F_39 ( V_133 , NULL ) ;
F_39 ( V_134 , NULL ) ;
F_39 ( V_135 , NULL ) ;
F_39 ( V_136 , NULL ) ;
F_39 ( V_137 , NULL ) ;
F_39 ( V_138 , NULL ) ;
F_39 ( V_139 , NULL ) ;
F_42 ( V_140 ) ;
F_42 ( V_141 ) ;
F_39 ( V_142 , NULL ) ;
F_39 ( V_143 , NULL ) ;
F_39 ( V_144 , NULL ) ;
F_39 ( V_145 , NULL ) ;
F_30 ( V_145 , 1 ) ;
F_39 ( V_146 , NULL ) ;
F_40 ( V_146 ) ;
if ( F_10 ( V_146 ) ) {
} else {
F_39 ( V_147 , NULL ) ;
F_39 ( V_148 , NULL ) ;
F_39 ( V_149 , NULL ) ;
F_39 ( V_150 , NULL ) ;
F_39 ( V_151 , NULL ) ;
F_39 ( V_152 , NULL ) ;
F_39 ( V_153 , NULL ) ;
F_39 ( V_154 , NULL ) ;
F_39 ( V_155 , NULL ) ;
F_30 ( V_155 , 1 ) ;
F_41 ( & V_156 ) ;
}
#ifdef F_43
F_44 ( F_45 ( 0xf0002000 ) , 0x40440000 , 0x82000fff ) ;
#endif
F_46 ( 0 , V_157 , F_36 ( V_157 ) ) ;
F_46 ( 2 , V_158 , F_36 ( V_158 ) ) ;
F_47 () ;
F_48 ( V_159 ,
F_36 ( V_159 ) ) ;
F_31 () ;
F_49 ( L_16 , & V_160 ) ;
F_49 ( L_16 , & V_161 ) ;
if ( V_37 )
F_49 ( L_17 , V_37 ) ;
}
static void T_3 F_50 ( void )
{
F_51 ( V_162 | V_163 ) ;
F_52 () ;
}
static void T_3 F_53 ( void )
{
F_54 () ;
V_164 . V_165 = F_50 ;
}
static void F_55 ( char V_28 , const char * V_166 )
{
F_56 ( ( 1 << 31 ) , V_167 ) ;
}
