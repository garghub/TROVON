static unsigned long F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + V_3 ) ;
T_1 V_4 = V_1 & V_5 ;
T_1 V_6 = V_1 & V_7 ;
unsigned long V_8 ;
switch ( V_4 ) {
case V_9 :
F_3 ( V_6 != V_10 ) ;
V_8 = 12000000 ;
break;
case V_11 :
F_3 ( V_6 != V_10 ) ;
V_8 = 13000000 ;
break;
case V_12 :
F_3 ( V_6 != V_10 ) ;
V_8 = 19200000 ;
break;
case V_13 :
F_3 ( V_6 != V_10 ) ;
V_8 = 26000000 ;
break;
default:
F_4 ( L_1 ,
V_4 ) ;
F_5 () ;
return 0 ;
}
return V_8 ;
}
static unsigned int F_6 ( void )
{
T_1 V_6 = F_2 ( V_2 + V_3 ) &
V_7 ;
switch ( V_6 ) {
case V_10 :
return 1 ;
case V_14 :
return 2 ;
case V_15 :
return 4 ;
default:
F_4 ( L_2 , V_6 ) ;
F_5 () ;
}
return 0 ;
}
static void F_7 ( void )
{
struct V_16 * V_16 ;
V_16 = F_8 ( L_3 , L_4 , V_2 , NULL , 0 ,
0 , & V_17 , V_18 ,
V_19 , NULL ) ;
F_9 ( V_16 , L_3 , NULL ) ;
V_20 [ V_21 ] = V_16 ;
V_16 = F_10 ( L_5 , L_3 ,
V_2 + V_22 , 0 , V_23 ,
8 , 8 , 1 , NULL ) ;
V_16 = F_11 ( L_6 , L_5 ,
V_2 + V_22 , 1 , 0 , V_24 ,
0 , NULL ) ;
F_9 ( V_16 , L_6 , NULL ) ;
V_20 [ V_25 ] = V_16 ;
V_16 = F_8 ( L_7 , L_4 , V_2 , NULL , 0 ,
216000000 , & V_26 , V_27 |
V_18 , V_28 , NULL ) ;
F_9 ( V_16 , L_7 , NULL ) ;
V_20 [ V_29 ] = V_16 ;
V_16 = F_10 ( L_8 , L_7 ,
V_2 + V_30 , 0 ,
V_31 | V_23 ,
8 , 8 , 1 , & V_32 ) ;
V_16 = F_11 ( L_9 , L_8 ,
V_2 + V_30 , 1 , 0 ,
V_33 | V_24 , 0 ,
& V_32 ) ;
F_9 ( V_16 , L_9 , NULL ) ;
V_20 [ V_34 ] = V_16 ;
V_16 = F_10 ( L_10 , L_7 ,
V_2 + V_30 , 0 ,
V_31 | V_23 ,
24 , 8 , 1 , & V_32 ) ;
V_16 = F_11 ( L_11 , L_10 ,
V_2 + V_30 , 17 , 16 ,
V_33 | V_24 , 0 ,
& V_32 ) ;
F_9 ( V_16 , L_11 , NULL ) ;
V_20 [ V_35 ] = V_16 ;
V_16 = F_10 ( L_12 , L_7 ,
V_2 + V_36 , 0 ,
V_31 | V_23 ,
8 , 8 , 1 , & V_32 ) ;
V_16 = F_11 ( L_13 , L_12 ,
V_2 + V_36 , 1 , 0 ,
V_33 | V_24 , 0 ,
& V_32 ) ;
F_9 ( V_16 , L_13 , NULL ) ;
V_20 [ V_37 ] = V_16 ;
V_16 = F_10 ( L_14 , L_7 ,
V_2 + V_36 , 0 ,
V_31 | V_23 ,
24 , 8 , 1 , & V_32 ) ;
V_16 = F_11 ( L_15 , L_14 ,
V_2 + V_36 , 17 , 16 ,
V_33 | V_24 , 0 ,
& V_32 ) ;
F_9 ( V_16 , L_15 , NULL ) ;
V_20 [ V_38 ] = V_16 ;
V_16 = F_8 ( L_16 , L_4 , V_2 , NULL ,
V_33 | V_39 , 0 ,
& V_40 , V_18 ,
V_41 , NULL ) ;
F_9 ( V_16 , L_16 , NULL ) ;
V_20 [ V_42 ] = V_16 ;
V_16 = F_10 ( L_17 , L_16 ,
V_2 + V_43 , 0 , V_23 ,
8 , 8 , 1 , NULL ) ;
V_16 = F_11 ( L_18 , L_17 ,
V_2 + V_43 , 1 , 0 , V_33 |
V_24 , 0 , NULL ) ;
F_9 ( V_16 , L_18 , NULL ) ;
V_20 [ V_44 ] = V_16 ;
V_16 = F_8 ( L_19 , L_4 , V_2 , NULL , 0 ,
0 , & V_45 , V_18 ,
V_46 , NULL ) ;
F_9 ( V_16 , L_19 , NULL ) ;
V_20 [ V_47 ] = V_16 ;
V_16 = F_8 ( L_20 , L_4 , V_2 , NULL , 0 ,
0 , & V_48 , V_49 | V_18 ,
V_50 , NULL ) ;
F_9 ( V_16 , L_20 , NULL ) ;
V_20 [ V_51 ] = V_16 ;
V_16 = F_8 ( L_21 , L_4 , V_2 , NULL , 0 ,
0 , & V_52 , V_18 ,
V_53 , NULL ) ;
F_9 ( V_16 , L_21 , NULL ) ;
V_20 [ V_54 ] = V_16 ;
V_16 = F_12 ( NULL , L_22 , L_21 ,
V_24 , 1 , 2 ) ;
F_9 ( V_16 , L_22 , NULL ) ;
V_20 [ V_55 ] = V_16 ;
V_16 = F_8 ( L_23 , L_9 , V_2 , NULL , 0 ,
0 , & V_56 , V_18 ,
V_57 , NULL ) ;
F_9 ( V_16 , L_23 , NULL ) ;
V_20 [ V_58 ] = V_16 ;
V_16 = F_10 ( L_24 , L_23 ,
V_2 + V_59 , 0 , V_23 ,
8 , 8 , 1 , NULL ) ;
V_16 = F_11 ( L_25 , L_24 ,
V_2 + V_59 , 1 , 0 , V_33 |
V_24 , 0 , NULL ) ;
F_9 ( V_16 , L_25 , NULL ) ;
V_20 [ V_60 ] = V_16 ;
V_16 = F_13 ( L_26 , L_4 , V_2 , V_61 ,
0 , 100000000 , & V_62 ,
0 , V_63 , NULL ) ;
F_9 ( V_16 , L_26 , NULL ) ;
V_20 [ V_64 ] = V_16 ;
}
static void F_14 ( void )
{
struct V_16 * V_16 ;
V_16 = F_15 ( L_27 , V_65 ,
F_16 ( V_65 ) , V_24 ,
V_2 + V_66 , 0 , 4 , 0 , 0 , NULL ) ;
F_9 ( V_16 , L_27 , NULL ) ;
V_20 [ V_67 ] = V_16 ;
V_16 = F_15 ( L_28 , V_68 ,
F_16 ( V_68 ) , V_24 ,
V_2 + V_69 , 0 , 4 , 0 , 0 , NULL ) ;
F_9 ( V_16 , L_28 , NULL ) ;
V_20 [ V_70 ] = V_16 ;
V_16 = F_17 ( NULL , L_29 , L_28 , 0 ,
V_2 + V_71 , 4 , 2 , 0 ,
& V_72 ) ;
V_16 = F_18 ( NULL , L_30 , L_29 , V_24 ,
V_2 + V_71 , 7 ,
V_73 , & V_72 ) ;
F_9 ( V_16 , L_30 , NULL ) ;
V_20 [ V_74 ] = V_16 ;
V_16 = F_17 ( NULL , L_31 , L_30 , 0 ,
V_2 + V_71 , 0 , 2 , 0 ,
& V_72 ) ;
V_16 = F_18 ( NULL , L_32 , L_31 , V_24 ,
V_2 + V_71 , 3 ,
V_73 , & V_72 ) ;
F_9 ( V_16 , L_32 , NULL ) ;
V_20 [ V_75 ] = V_16 ;
V_16 = F_12 ( NULL , L_33 , L_27 , 0 , 1 , 4 ) ;
F_9 ( V_16 , L_33 , NULL ) ;
V_20 [ V_76 ] = V_16 ;
}
static void T_2 F_19 ( void )
{
struct V_16 * V_16 ;
V_16 = F_20 ( NULL , L_34 , V_77 ,
F_16 ( V_77 ) ,
V_78 ,
V_2 + V_79 , 0 , 3 , 0 , NULL ) ;
V_16 = F_18 ( NULL , L_35 , L_34 , 0 ,
V_2 + V_79 , 4 ,
V_73 , NULL ) ;
F_9 ( V_16 , L_35 , NULL ) ;
V_20 [ V_80 ] = V_16 ;
V_16 = F_12 ( NULL , L_36 , L_35 ,
V_24 , 2 , 1 ) ;
V_16 = F_21 ( L_37 , L_36 ,
V_81 , V_2 ,
V_24 , 89 , & V_82 ,
V_83 ) ;
F_9 ( V_16 , L_37 , NULL ) ;
V_20 [ V_84 ] = V_16 ;
}
static void T_2 F_22 ( void )
{
struct V_85 * V_86 ;
struct V_16 * V_16 ;
int V_87 ;
V_16 = F_21 ( L_38 , L_25 ,
V_88 ,
V_2 , 0 , 3 , & V_89 ,
V_83 ) ;
F_9 ( V_16 , NULL , L_39 ) ;
V_20 [ V_90 ] = V_16 ;
V_16 = F_21 ( L_40 , L_32 , 0 , V_2 ,
0 , 34 , & V_91 ,
V_83 ) ;
F_9 ( V_16 , NULL , L_41 ) ;
V_20 [ V_92 ] = V_16 ;
V_16 = F_21 ( L_42 , L_43 ,
V_81 ,
V_2 , 0 , 4 , & V_89 ,
V_83 ) ;
F_9 ( V_16 , NULL , L_44 ) ;
V_20 [ V_93 ] = V_16 ;
V_16 = F_21 ( L_45 , L_46 , 0 , V_2 ,
0 , 5 , & V_89 ,
V_83 ) ;
F_9 ( V_16 , NULL , L_45 ) ;
V_20 [ V_94 ] = V_16 ;
V_16 = F_21 ( L_47 , L_43 ,
V_81 | V_88 ,
V_2 , 0 , 36 , & V_91 ,
V_83 ) ;
F_9 ( V_16 , NULL , L_48 ) ;
V_20 [ V_95 ] = V_16 ;
V_16 = F_21 ( L_49 , L_46 ,
V_81 ,
V_2 , 0 , 92 , & V_82 ,
V_83 ) ;
F_9 ( V_16 , L_49 , L_50 ) ;
V_20 [ V_96 ] = V_16 ;
V_16 = F_21 ( L_51 , L_46 , 0 ,
V_2 , 0 , 29 , & V_89 ,
V_83 ) ;
F_9 ( V_16 , L_51 , L_52 ) ;
V_20 [ V_97 ] = V_16 ;
V_16 = F_21 ( L_53 , L_46 , 0 ,
V_2 , 0 , 62 , & V_91 ,
V_83 ) ;
F_9 ( V_16 , L_53 , L_52 ) ;
V_20 [ V_98 ] = V_16 ;
V_16 = F_21 ( L_54 , L_46 , 0 ,
V_2 , 0 , 63 , & V_91 ,
V_83 ) ;
F_9 ( V_16 , L_54 , L_55 ) ;
V_20 [ V_99 ] = V_16 ;
V_16 = F_20 ( NULL , L_56 , V_100 ,
F_16 ( V_100 ) ,
V_78 ,
V_2 + V_101 ,
30 , 2 , 0 , NULL ) ;
V_16 = F_21 ( L_57 , L_56 , 0 , V_2 , 0 ,
57 , & V_91 , V_83 ) ;
F_9 ( V_16 , L_57 , NULL ) ;
V_20 [ V_102 ] = V_16 ;
V_16 = F_21 ( L_58 , L_46 , 0 , V_2 , 0 ,
22 , & V_89 , V_83 ) ;
F_9 ( V_16 , NULL , L_59 ) ;
V_20 [ V_103 ] = V_16 ;
V_16 = F_21 ( L_60 , L_46 , 0 , V_2 , 0 ,
58 , & V_91 , V_83 ) ;
F_9 ( V_16 , NULL , L_61 ) ;
V_20 [ V_104 ] = V_16 ;
V_16 = F_21 ( L_62 , L_46 , 0 , V_2 , 0 ,
59 , & V_91 , V_83 ) ;
F_9 ( V_16 , NULL , L_63 ) ;
V_20 [ V_105 ] = V_16 ;
V_16 = F_21 ( L_64 , L_21 , 0 , V_2 , 0 ,
48 , & V_91 , V_83 ) ;
F_9 ( V_16 , NULL , L_64 ) ;
V_20 [ V_106 ] = V_16 ;
V_16 = F_21 ( L_65 , L_13 , 0 , V_2 ,
0 , 52 , & V_91 ,
V_83 ) ;
F_9 ( V_16 , L_65 , L_66 ) ;
V_20 [ V_107 ] = V_16 ;
V_16 = F_21 ( L_67 , L_46 , 0 , V_2 , 0 , 23 ,
& V_89 , V_83 ) ;
F_9 ( V_16 , L_67 , L_66 ) ;
V_20 [ V_108 ] = V_16 ;
V_16 = F_21 ( L_68 , L_46 , 0 , V_2 , 0 , 70 ,
& V_82 , V_83 ) ;
F_9 ( V_16 , L_68 , NULL ) ;
V_20 [ V_109 ] = V_16 ;
V_16 = F_21 ( L_69 , L_46 , 0 , V_2 , 0 , 72 ,
& V_82 , V_83 ) ;
F_9 ( V_16 , L_69 , NULL ) ;
V_20 [ V_110 ] = V_16 ;
V_16 = F_21 ( L_70 , L_46 , 0 , V_2 ,
0 , 74 , & V_82 ,
V_83 ) ;
F_9 ( V_16 , L_70 , NULL ) ;
V_20 [ V_111 ] = V_16 ;
V_16 = F_23 ( NULL , L_71 , NULL , V_112 ,
26000000 ) ;
V_16 = F_21 ( L_72 , L_71 , 0 ,
V_2 , 0 , 94 , & V_82 ,
V_83 ) ;
F_9 ( V_16 , L_72 , NULL ) ;
V_20 [ V_113 ] = V_16 ;
V_16 = F_23 ( NULL , L_73 , NULL , V_112 ,
26000000 ) ;
V_16 = F_21 ( L_74 , L_73 , 0 ,
V_2 , 0 , 93 , & V_82 ,
V_83 ) ;
F_9 ( V_16 , L_74 , NULL ) ;
V_20 [ V_114 ] = V_16 ;
for ( V_87 = 0 ; V_87 < F_16 ( V_115 ) ; V_87 ++ ) {
V_86 = & V_115 [ V_87 ] ;
V_16 = F_24 ( V_86 -> V_116 , V_86 -> V_117 ,
V_86 -> V_118 , & V_86 -> V_119 ,
V_2 , V_86 -> V_120 , V_86 -> V_121 ) ;
F_9 ( V_16 , V_86 -> V_122 , V_86 -> V_123 ) ;
V_20 [ V_86 -> V_124 ] = V_16 ;
}
for ( V_87 = 0 ; V_87 < F_16 ( V_125 ) ; V_87 ++ ) {
V_86 = & V_125 [ V_87 ] ;
V_16 = F_25 ( V_86 -> V_116 ,
V_86 -> V_117 ,
V_86 -> V_118 , & V_86 -> V_119 ,
V_2 , V_86 -> V_120 ) ;
F_9 ( V_16 , V_86 -> V_122 , V_86 -> V_123 ) ;
V_20 [ V_86 -> V_124 ] = V_16 ;
}
}
static void T_2 F_26 ( void )
{
struct V_16 * V_16 ;
V_16 = F_23 ( NULL , L_43 , NULL , V_112 ,
32768 ) ;
F_9 ( V_16 , L_43 , NULL ) ;
V_20 [ V_126 ] = V_16 ;
}
static void T_2 F_27 ( void )
{
struct V_16 * V_16 ;
F_28 ( 0 , V_61 + V_127 ) ;
V_16 = F_18 ( NULL , L_75 , L_43 , 0 ,
V_61 + V_128 ,
V_129 , 0 , NULL ) ;
V_16 = F_18 ( NULL , L_76 , L_75 , 0 ,
V_61 + V_130 ,
V_131 , 0 , NULL ) ;
F_9 ( V_16 , L_76 , NULL ) ;
V_20 [ V_132 ] = V_16 ;
}
static void T_2 F_29 ( void )
{
struct V_16 * V_16 ;
unsigned long V_8 ;
unsigned int V_6 ;
V_8 = F_1 () ;
V_16 = F_23 ( NULL , L_46 , NULL , V_112 |
V_33 , V_8 ) ;
F_9 ( V_16 , L_46 , NULL ) ;
V_20 [ V_133 ] = V_16 ;
V_6 = F_6 () ;
V_16 = F_12 ( NULL , L_4 , L_46 ,
V_24 , 1 , V_6 ) ;
F_9 ( V_16 , L_4 , NULL ) ;
V_20 [ V_134 ] = V_16 ;
}
static void F_30 ( T_1 V_135 )
{
unsigned int V_136 ;
do {
V_136 = F_31 ( V_2 +
V_137 ) ;
F_32 () ;
} while ( ! ( V_136 & ( 1 << V_135 ) ) );
return;
}
static void F_33 ( T_1 V_135 )
{
F_34 ( F_35 ( V_135 ) ,
V_2 + V_137 ) ;
F_36 () ;
}
static void F_37 ( T_1 V_135 )
{
F_34 ( F_35 ( V_135 ) ,
V_2 + V_138 ) ;
F_38 () ;
}
static void F_39 ( T_1 V_135 )
{
unsigned int V_136 ;
V_136 = F_31 ( V_2 + V_139 ) ;
F_34 ( V_136 & ~ F_40 ( V_135 ) ,
V_2 + V_139 ) ;
F_41 () ;
V_136 = F_31 ( V_2 + V_139 ) ;
}
static void F_42 ( T_1 V_135 )
{
unsigned int V_136 ;
V_136 = F_31 ( V_2 + V_139 ) ;
F_34 ( V_136 | F_40 ( V_135 ) ,
V_2 + V_139 ) ;
}
static bool F_43 ( void )
{
unsigned int V_140 ;
V_140 = F_31 ( V_2 +
V_137 ) ;
return ! ! ( V_140 & 0x2 ) ;
}
static void F_44 ( void )
{
V_141 . V_142 =
F_31 ( V_2 + V_143 ) ;
F_34 ( 3 << 30 , V_2 + V_143 ) ;
V_141 . V_144 =
F_31 ( V_2 + V_66 ) ;
V_141 . V_145 =
F_31 ( V_2 + V_146 ) ;
V_141 . V_147 =
F_31 ( V_2 + V_148 ) ;
V_141 . V_149 =
F_31 ( V_2 + V_150 ) ;
}
static void F_45 ( void )
{
unsigned int V_136 , V_151 ;
V_136 = F_31 ( V_2 + V_66 ) ;
V_151 = ( V_136 >> V_152 ) & 0xF ;
if ( V_151 == V_153 )
V_136 = ( V_136 >> V_154 ) & 0xF ;
else if ( V_151 == V_155 )
V_136 = ( V_136 >> V_156 ) & 0xF ;
else
F_5 () ;
if ( V_136 != V_157 ) {
F_34 ( V_141 . V_147 ,
V_2 + V_148 ) ;
F_34 ( V_141 . V_145 ,
V_2 + V_146 ) ;
if ( V_141 . V_145 & ( 1 << 30 ) )
F_46 ( 300 ) ;
}
F_34 ( V_141 . V_149 ,
V_2 + V_150 ) ;
F_34 ( V_141 . V_144 ,
V_2 + V_66 ) ;
F_34 ( V_141 . V_142 ,
V_2 + V_143 ) ;
}
static void T_2 F_47 ( void )
{
F_48 ( V_158 , V_20 , V_159 ) ;
}
static void T_2 F_49 ( struct V_160 * V_161 )
{
int V_87 ;
struct V_160 * V_162 ;
V_2 = F_50 ( V_161 , 0 ) ;
if ( ! V_2 ) {
F_4 ( L_77 ) ;
F_5 () ;
}
V_162 = F_51 ( NULL , V_163 ) ;
if ( ! V_162 ) {
F_4 ( L_78 ) ;
F_5 () ;
}
V_61 = F_50 ( V_162 , 0 ) ;
if ( ! V_61 ) {
F_4 ( L_79 ) ;
F_5 () ;
}
F_29 () ;
F_27 () ;
F_26 () ;
F_7 () ;
F_14 () ;
F_22 () ;
F_19 () ;
for ( V_87 = 0 ; V_87 < F_16 ( V_20 ) ; V_87 ++ ) {
if ( F_52 ( V_20 [ V_87 ] ) ) {
F_4 ( L_80 ,
V_87 , F_53 ( V_20 [ V_87 ] ) ) ;
F_5 () ;
}
if ( ! V_20 [ V_87 ] )
V_20 [ V_87 ] = F_54 ( - V_164 ) ;
}
F_55 ( V_165 , V_20 , V_159 ) ;
V_166 . V_20 = V_20 ;
V_166 . V_167 = F_16 ( V_20 ) ;
F_56 ( V_161 , V_168 , & V_166 ) ;
V_169 = F_47 ;
V_170 = & V_171 ;
}
