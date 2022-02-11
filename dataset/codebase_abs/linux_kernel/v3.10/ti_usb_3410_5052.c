static int T_1 F_1 ( void )
{
int V_1 , V_2 , V_3 ;
V_3 = F_2 ( V_4 ) - 2 * V_5 - 1 ;
V_2 = F_2 ( V_6 ) - V_5 - 1 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_7 , V_8 ) ; V_1 ++ , V_2 ++ , V_3 ++ ) {
V_6 [ V_2 ] . V_9 = V_10 [ V_1 ] ;
V_6 [ V_2 ] . V_11 = V_12 [ V_1 ] ;
V_6 [ V_2 ] . V_13 = V_14 ;
V_4 [ V_3 ] . V_9 = V_10 [ V_1 ] ;
V_4 [ V_3 ] . V_11 = V_12 [ V_1 ] ;
V_4 [ V_3 ] . V_13 = V_14 ;
}
V_2 = F_2 ( V_15 ) - V_5 - 1 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_16 , V_17 ) ; V_1 ++ , V_2 ++ , V_3 ++ ) {
V_15 [ V_2 ] . V_9 = V_18 [ V_1 ] ;
V_15 [ V_2 ] . V_11 = V_19 [ V_1 ] ;
V_15 [ V_2 ] . V_13 = V_14 ;
V_4 [ V_3 ] . V_9 = V_18 [ V_1 ] ;
V_4 [ V_3 ] . V_11 = V_19 [ V_1 ] ;
V_4 [ V_3 ] . V_13 = V_14 ;
}
return F_4 ( V_20 , V_21 , V_4 ) ;
}
static void T_2 F_5 ( void )
{
F_6 ( V_20 ) ;
}
static int F_7 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 = V_23 -> V_27 ;
int V_28 ;
F_8 ( & V_27 -> V_27 ,
L_1 ,
V_29 , F_9 ( V_27 -> V_30 . V_11 ) ,
V_27 -> V_30 . V_31 ,
V_27 -> V_32 -> V_33 . V_34 ) ;
V_25 = F_10 ( sizeof( struct V_24 ) , V_35 ) ;
if ( V_25 == NULL ) {
F_11 ( & V_27 -> V_27 , L_2 , V_29 ) ;
return - V_36 ;
}
F_12 ( & V_25 -> V_37 ) ;
V_25 -> V_38 = V_23 ;
F_13 ( V_23 , V_25 ) ;
if ( F_14 ( V_23 -> V_39 , V_6 ) )
V_25 -> V_40 = 1 ;
F_8 ( & V_27 -> V_27 , L_3 , V_29 ,
V_25 -> V_40 ? L_4 : L_5 ) ;
if ( V_27 -> V_30 . V_31 == 1 ) {
V_28 = F_15 ( V_25 ) ;
if ( V_28 != 0 )
goto V_41;
if ( V_25 -> V_40 ) {
F_16 ( 100 ) ;
F_17 ( V_27 ) ;
}
V_28 = - V_42 ;
goto V_41;
}
if ( V_27 -> V_32 -> V_33 . V_34 == V_43 ) {
V_28 = F_18 ( V_27 , V_44 ) ;
V_28 = V_28 ? V_28 : - V_42 ;
goto V_41;
}
return 0 ;
V_41:
F_19 ( V_25 ) ;
F_13 ( V_23 , NULL ) ;
return V_28 ;
}
static void F_20 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_21 ( V_23 ) ;
F_19 ( V_25 ) ;
}
static int F_22 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
V_48 = F_10 ( sizeof( * V_48 ) , V_35 ) ;
if ( ! V_48 )
return - V_36 ;
F_23 ( & V_48 -> V_49 ) ;
if ( V_46 == V_46 -> V_23 -> V_46 [ 0 ] )
V_48 -> V_50 = V_51 ;
else
V_48 -> V_50 = V_52 ;
V_46 -> V_46 . V_53 = F_24 ( 10 * V_53 ) ;
F_25 ( & V_48 -> V_54 ) ;
if ( F_26 ( & V_48 -> V_55 , V_56 , V_35 ) ) {
F_19 ( V_48 ) ;
return - V_36 ;
}
V_48 -> V_57 = V_46 ;
V_48 -> V_58 = F_21 ( V_46 -> V_23 ) ;
V_48 -> V_59 = 0 ;
F_27 ( V_46 , V_48 ) ;
return 0 ;
}
static int F_28 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
V_48 = F_29 ( V_46 ) ;
F_30 ( & V_48 -> V_55 ) ;
F_19 ( V_48 ) ;
return 0 ;
}
static int F_31 ( struct V_60 * V_61 , struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_62 * V_62 ;
int V_63 ;
int V_28 ;
T_3 V_64 = ( V_65 ) ( V_66 |
V_67 |
( V_68 << 2 ) ) ;
if ( V_48 == NULL )
return - V_42 ;
V_27 = V_46 -> V_23 -> V_27 ;
V_25 = V_48 -> V_58 ;
if ( F_32 ( & V_25 -> V_37 ) )
return - V_69 ;
V_63 = V_46 -> V_70 - V_46 -> V_23 -> V_71 ;
V_48 -> V_72 = 0 ;
V_48 -> V_73 |= ( V_74 | V_75 ) ;
if ( V_25 -> V_76 == 0 ) {
F_8 ( & V_46 -> V_27 , L_6 , V_29 ) ;
V_62 = V_25 -> V_38 -> V_46 [ 0 ] -> V_77 ;
if ( ! V_62 ) {
F_11 ( & V_46 -> V_27 , L_7 , V_29 ) ;
V_28 = - V_78 ;
goto V_79;
}
V_62 -> V_80 = V_25 ;
V_28 = F_33 ( V_62 , V_35 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_8 , V_29 , V_28 ) ;
goto V_79;
}
}
if ( V_61 )
F_34 ( V_61 , V_46 , & V_61 -> V_81 ) ;
F_8 ( & V_46 -> V_27 , L_9 , V_29 ) ;
V_28 = F_35 ( V_25 , V_82 ,
( V_65 ) ( V_83 + V_63 ) , V_64 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_10 ,
V_29 , V_28 ) ;
goto V_84;
}
F_8 ( & V_46 -> V_27 , L_11 , V_29 ) ;
V_28 = F_35 ( V_25 , V_85 ,
( V_65 ) ( V_83 + V_63 ) , 0 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_12 ,
V_29 , V_28 ) ;
goto V_84;
}
F_8 ( & V_46 -> V_27 , L_13 , V_29 ) ;
V_28 = F_35 ( V_25 , V_86 ,
( V_65 ) ( V_83 + V_63 ) , V_87 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_14 ,
V_29 , V_28 ) ;
goto V_84;
}
V_28 = F_35 ( V_25 , V_86 ,
( V_65 ) ( V_83 + V_63 ) , V_88 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_15 ,
V_29 , V_28 ) ;
goto V_84;
}
F_36 ( V_27 , V_46 -> V_89 -> V_90 ) ;
F_36 ( V_27 , V_46 -> V_91 -> V_90 ) ;
if ( V_61 )
F_34 ( V_61 , V_46 , & V_61 -> V_81 ) ;
F_8 ( & V_46 -> V_27 , L_16 , V_29 ) ;
V_28 = F_35 ( V_25 , V_82 ,
( V_65 ) ( V_83 + V_63 ) , V_64 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_17 ,
V_29 , V_28 ) ;
goto V_84;
}
F_8 ( & V_46 -> V_27 , L_18 , V_29 ) ;
V_28 = F_35 ( V_25 , V_85 ,
( V_65 ) ( V_83 + V_63 ) , 0 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_19 ,
V_29 , V_28 ) ;
goto V_84;
}
F_8 ( & V_46 -> V_27 , L_20 , V_29 ) ;
V_62 = V_46 -> V_91 ;
if ( ! V_62 ) {
F_11 ( & V_46 -> V_27 , L_21 , V_29 ) ;
V_28 = - V_78 ;
goto V_84;
}
V_48 -> V_92 = V_93 ;
V_62 -> V_80 = V_48 ;
V_28 = F_33 ( V_62 , V_35 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_22 ,
V_29 , V_28 ) ;
goto V_84;
}
V_48 -> V_94 = 1 ;
++ V_25 -> V_76 ;
V_46 -> V_46 . V_95 = 3 ;
goto V_79;
V_84:
if ( V_25 -> V_76 == 0 )
F_37 ( V_46 -> V_23 -> V_46 [ 0 ] -> V_77 ) ;
V_79:
F_38 ( & V_25 -> V_37 ) ;
F_8 ( & V_46 -> V_27 , L_23 , V_29 , V_28 ) ;
return V_28 ;
}
static void F_39 ( struct V_45 * V_46 )
{
struct V_24 * V_25 ;
struct V_47 * V_48 ;
int V_63 ;
int V_28 ;
int V_96 ;
unsigned long V_97 ;
V_25 = F_21 ( V_46 -> V_23 ) ;
V_48 = F_29 ( V_46 ) ;
if ( V_25 == NULL || V_48 == NULL )
return;
V_48 -> V_94 = 0 ;
F_37 ( V_46 -> V_91 ) ;
F_37 ( V_46 -> V_89 ) ;
V_48 -> V_98 = 0 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
F_41 ( & V_48 -> V_55 ) ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
V_63 = V_46 -> V_70 - V_46 -> V_23 -> V_71 ;
F_8 ( & V_46 -> V_27 , L_24 , V_29 ) ;
V_28 = F_35 ( V_25 , V_99 ,
( V_65 ) ( V_83 + V_63 ) , 0 , NULL , 0 ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 ,
L_25
, V_29 , V_28 ) ;
V_96 = ! F_32 ( & V_25 -> V_37 ) ;
-- V_48 -> V_58 -> V_76 ;
if ( V_48 -> V_58 -> V_76 <= 0 ) {
F_37 ( V_46 -> V_23 -> V_46 [ 0 ] -> V_77 ) ;
V_48 -> V_58 -> V_76 = 0 ;
}
if ( V_96 )
F_38 ( & V_25 -> V_37 ) ;
}
static int F_43 ( struct V_60 * V_61 , struct V_45 * V_46 ,
const unsigned char * V_100 , int V_101 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
if ( V_101 == 0 ) {
F_8 ( & V_46 -> V_27 , L_26 , V_29 ) ;
return 0 ;
}
if ( V_48 == NULL || ! V_48 -> V_94 )
return - V_42 ;
V_101 = F_44 ( & V_48 -> V_55 , V_100 , V_101 ,
& V_48 -> V_49 ) ;
F_45 ( V_48 ) ;
return V_101 ;
}
static int F_46 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
int V_103 = 0 ;
unsigned long V_97 ;
if ( V_48 == NULL )
return 0 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
V_103 = F_47 ( & V_48 -> V_55 ) ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
F_8 ( & V_46 -> V_27 , L_27 , V_29 , V_103 ) ;
return V_103 ;
}
static int F_48 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
int V_104 = 0 ;
unsigned long V_97 ;
if ( V_48 == NULL )
return 0 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
V_104 = F_49 ( & V_48 -> V_55 ) ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
F_8 ( & V_46 -> V_27 , L_27 , V_29 , V_104 ) ;
return V_104 ;
}
static bool F_50 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
int V_105 ;
T_4 V_106 ;
V_105 = F_51 ( V_48 , & V_106 ) ;
if ( ! V_105 && ! ( V_106 & V_107 ) )
return false ;
return true ;
}
static void F_52 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
if ( V_48 == NULL )
return;
if ( F_53 ( V_61 ) || F_54 ( V_61 ) )
F_55 ( V_48 , V_61 ) ;
}
static void F_56 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
int V_28 ;
if ( V_48 == NULL )
return;
if ( F_53 ( V_61 ) || F_54 ( V_61 ) ) {
V_28 = F_57 ( V_48 , V_61 ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 , L_28 ,
V_29 , V_28 ) ;
}
}
static int F_58 ( struct V_60 * V_61 ,
unsigned int V_108 , unsigned long V_109 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
F_8 ( & V_46 -> V_27 , L_29 , V_29 , V_108 ) ;
if ( V_48 == NULL )
return - V_42 ;
switch ( V_108 ) {
case V_110 :
F_8 ( & V_46 -> V_27 , L_30 , V_29 ) ;
return F_59 ( V_48 ,
(struct V_111 V_112 * ) V_109 ) ;
case V_113 :
F_8 ( & V_46 -> V_27 , L_31 , V_29 ) ;
return F_60 ( V_61 , V_48 ,
(struct V_111 V_112 * ) V_109 ) ;
}
return - V_114 ;
}
static void F_34 ( struct V_60 * V_61 ,
struct V_45 * V_46 , struct V_115 * V_116 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_117 * V_118 ;
T_5 V_119 , V_120 ;
int V_121 ;
int V_28 ;
int V_63 = V_46 -> V_70 - V_46 -> V_23 -> V_71 ;
unsigned int V_122 ;
V_119 = V_61 -> V_81 . V_123 ;
V_120 = V_61 -> V_81 . V_124 ;
F_8 ( & V_46 -> V_27 , L_32 , V_29 , V_119 , V_120 ) ;
F_8 ( & V_46 -> V_27 , L_33 , V_29 ,
V_116 -> V_123 , V_116 -> V_124 ) ;
if ( V_48 == NULL )
return;
V_118 = F_61 ( sizeof( * V_118 ) , V_35 ) ;
if ( ! V_118 ) {
F_11 ( & V_46 -> V_27 , L_2 , V_29 ) ;
return;
}
V_118 -> V_125 = 0 ;
V_118 -> V_125 |= V_126 ;
V_118 -> V_125 |= V_127 ;
V_118 -> V_128 = ( V_65 ) ( V_48 -> V_59 ) ;
switch ( V_119 & V_129 ) {
case V_130 :
V_118 -> V_131 = V_132 ;
break;
case V_133 :
V_118 -> V_131 = V_134 ;
break;
case V_135 :
V_118 -> V_131 = V_136 ;
break;
default:
case V_137 :
V_118 -> V_131 = V_138 ;
break;
}
V_61 -> V_81 . V_123 &= ~ V_139 ;
if ( V_119 & V_140 ) {
if ( V_119 & V_141 ) {
V_118 -> V_125 |= V_142 ;
V_118 -> V_143 = V_144 ;
} else {
V_118 -> V_125 |= V_142 ;
V_118 -> V_143 = V_145 ;
}
} else {
V_118 -> V_125 &= ~ V_142 ;
V_118 -> V_143 = V_146 ;
}
if ( V_119 & V_147 )
V_118 -> V_148 = V_149 ;
else
V_118 -> V_148 = V_150 ;
if ( V_119 & V_151 ) {
if ( ( V_119 & V_152 ) != V_153 )
V_118 -> V_125 |= V_154 ;
V_118 -> V_125 |= V_155 ;
} else {
V_61 -> V_156 = 0 ;
F_57 ( V_48 , V_61 ) ;
}
if ( F_53 ( V_61 ) || F_62 ( V_61 ) ) {
V_118 -> V_157 = F_63 ( V_61 ) ;
V_118 -> V_158 = F_64 ( V_61 ) ;
if ( F_53 ( V_61 ) )
V_118 -> V_125 |= V_159 ;
else
F_57 ( V_48 , V_61 ) ;
if ( F_62 ( V_61 ) )
V_118 -> V_125 |= V_160 ;
}
V_121 = F_65 ( V_61 ) ;
if ( ! V_121 )
V_121 = 9600 ;
if ( V_48 -> V_58 -> V_40 )
V_118 -> V_161 = ( T_3 ) ( ( 923077 + V_121 / 2 ) / V_121 ) ;
else
V_118 -> V_161 = ( T_3 ) ( ( 461538 + V_121 / 2 ) / V_121 ) ;
if ( ( V_119 & V_152 ) != V_153 )
F_66 ( V_61 , V_121 , V_121 ) ;
F_8 ( & V_46 -> V_27 ,
L_34 ,
V_29 , V_121 , V_118 -> V_161 , V_118 -> V_125 ,
V_118 -> V_131 , V_118 -> V_143 , V_118 -> V_148 ,
V_118 -> V_157 , V_118 -> V_158 , V_118 -> V_128 ) ;
F_67 ( & V_118 -> V_161 ) ;
F_67 ( & V_118 -> V_125 ) ;
V_28 = F_35 ( V_48 -> V_58 , V_162 ,
( V_65 ) ( V_83 + V_63 ) , 0 , ( V_65 * ) V_118 ,
sizeof( * V_118 ) ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 , L_35 ,
V_29 , V_63 , V_28 ) ;
V_122 = V_48 -> V_73 ;
if ( ( V_119 & V_152 ) == V_153 )
V_122 &= ~ ( V_75 | V_74 ) ;
V_28 = F_68 ( V_48 , V_122 ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 ,
L_36 ,
V_29 , V_63 , V_28 ) ;
F_19 ( V_118 ) ;
}
static int F_69 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
unsigned int V_163 ;
unsigned int V_164 ;
unsigned int V_122 ;
unsigned long V_97 ;
if ( V_48 == NULL )
return - V_42 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
V_164 = V_48 -> V_72 ;
V_122 = V_48 -> V_73 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
V_163 = ( ( V_122 & V_75 ) ? V_165 : 0 )
| ( ( V_122 & V_74 ) ? V_166 : 0 )
| ( ( V_122 & V_167 ) ? V_168 : 0 )
| ( ( V_164 & V_169 ) ? V_170 : 0 )
| ( ( V_164 & V_171 ) ? V_172 : 0 )
| ( ( V_164 & V_173 ) ? V_174 : 0 )
| ( ( V_164 & V_175 ) ? V_176 : 0 ) ;
F_8 ( & V_46 -> V_27 , L_37 , V_29 , V_163 ) ;
return V_163 ;
}
static int F_70 ( struct V_60 * V_61 ,
unsigned int V_177 , unsigned int V_178 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
unsigned int V_122 ;
unsigned long V_97 ;
if ( V_48 == NULL )
return - V_42 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
V_122 = V_48 -> V_73 ;
if ( V_177 & V_166 )
V_122 |= V_74 ;
if ( V_177 & V_165 )
V_122 |= V_75 ;
if ( V_177 & V_168 )
V_122 |= V_167 ;
if ( V_178 & V_166 )
V_122 &= ~ V_74 ;
if ( V_178 & V_165 )
V_122 &= ~ V_75 ;
if ( V_178 & V_168 )
V_122 &= ~ V_167 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
return F_68 ( V_48 , V_122 ) ;
}
static void F_71 ( struct V_60 * V_61 , int V_179 )
{
struct V_45 * V_46 = V_61 -> V_102 ;
struct V_47 * V_48 = F_29 ( V_46 ) ;
int V_28 ;
F_8 ( & V_46 -> V_27 , L_38 , V_29 , V_179 ) ;
if ( V_48 == NULL )
return;
V_28 = F_72 ( V_46 , V_48 -> V_58 ,
V_48 -> V_50 + V_180 ,
V_181 , V_179 == - 1 ? V_181 : 0 ) ;
if ( V_28 )
F_8 ( & V_46 -> V_27 , L_39 , V_29 , V_28 ) ;
}
static void F_73 ( struct V_62 * V_62 )
{
struct V_24 * V_25 = V_62 -> V_80 ;
struct V_45 * V_46 ;
struct V_22 * V_23 = V_25 -> V_38 ;
struct V_47 * V_48 ;
struct V_182 * V_27 = & V_62 -> V_27 -> V_27 ;
unsigned char * V_100 = V_62 -> V_183 ;
int V_184 = V_62 -> V_185 ;
int V_63 ;
int V_186 ;
int V_28 = V_62 -> V_28 ;
int V_187 ;
V_65 V_164 ;
switch ( V_28 ) {
case 0 :
break;
case - V_188 :
case - V_189 :
case - V_190 :
F_8 ( V_27 , L_40 , V_29 , V_28 ) ;
V_25 -> V_191 = 1 ;
return;
default:
F_11 ( V_27 , L_41 , V_29 , V_28 ) ;
V_25 -> V_191 = 1 ;
goto exit;
}
if ( V_184 != 2 ) {
F_8 ( V_27 , L_42 , V_29 , V_184 ) ;
goto exit;
}
if ( V_100 [ 0 ] == V_192 ) {
F_11 ( V_27 , L_43 , V_29 , V_100 [ 1 ] ) ;
goto exit;
}
V_63 = F_74 ( V_100 [ 0 ] ) ;
V_186 = F_75 ( V_100 [ 0 ] ) ;
F_8 ( V_27 , L_44 ,
V_29 , V_63 , V_186 , V_100 [ 1 ] ) ;
if ( V_63 >= V_23 -> V_193 ) {
F_11 ( V_27 , L_45 ,
V_29 , V_63 ) ;
goto exit;
}
V_46 = V_23 -> V_46 [ V_63 ] ;
V_48 = F_29 ( V_46 ) ;
if ( ! V_48 )
goto exit;
switch ( V_186 ) {
case V_194 :
F_11 ( V_27 , L_46 ,
V_29 , V_63 , V_100 [ 1 ] ) ;
break;
case V_195 :
V_164 = V_100 [ 1 ] ;
F_8 ( V_27 , L_47 , V_29 , V_63 , V_164 ) ;
F_76 ( V_48 , V_164 ) ;
break;
default:
F_11 ( V_27 , L_48 ,
V_29 , V_100 [ 1 ] ) ;
break;
}
exit:
V_187 = F_33 ( V_62 , V_196 ) ;
if ( V_187 )
F_11 ( V_27 , L_49 ,
V_29 , V_187 ) ;
}
static void F_77 ( struct V_62 * V_62 )
{
struct V_47 * V_48 = V_62 -> V_80 ;
struct V_45 * V_46 = V_48 -> V_57 ;
struct V_182 * V_27 = & V_62 -> V_27 -> V_27 ;
int V_28 = V_62 -> V_28 ;
int V_187 = 0 ;
switch ( V_28 ) {
case 0 :
break;
case - V_188 :
case - V_189 :
case - V_190 :
F_8 ( V_27 , L_40 , V_29 , V_28 ) ;
V_48 -> V_58 -> V_191 = 1 ;
F_78 ( & V_48 -> V_54 ) ;
return;
default:
F_11 ( V_27 , L_41 ,
V_29 , V_28 ) ;
V_48 -> V_58 -> V_191 = 1 ;
F_78 ( & V_48 -> V_54 ) ;
}
if ( V_28 == - V_197 )
goto exit;
if ( V_28 ) {
F_11 ( V_27 , L_50 , V_29 ) ;
return;
}
if ( V_62 -> V_185 ) {
F_79 ( V_27 , V_29 , V_62 -> V_185 ,
V_62 -> V_183 ) ;
if ( ! V_48 -> V_94 )
F_8 ( V_27 , L_51 ,
V_29 ) ;
else
F_80 ( V_46 , V_62 -> V_183 , V_62 -> V_185 ) ;
F_81 ( & V_48 -> V_49 ) ;
V_46 -> V_198 . V_199 += V_62 -> V_185 ;
F_82 ( & V_48 -> V_49 ) ;
}
exit:
F_81 ( & V_48 -> V_49 ) ;
if ( V_48 -> V_92 == V_93 )
V_187 = F_33 ( V_62 , V_196 ) ;
else if ( V_48 -> V_92 == V_200 )
V_48 -> V_92 = V_201 ;
F_82 ( & V_48 -> V_49 ) ;
if ( V_187 )
F_11 ( V_27 , L_52 ,
V_29 , V_187 ) ;
}
static void F_83 ( struct V_62 * V_62 )
{
struct V_47 * V_48 = V_62 -> V_80 ;
struct V_45 * V_46 = V_48 -> V_57 ;
int V_28 = V_62 -> V_28 ;
V_48 -> V_98 = 0 ;
switch ( V_28 ) {
case 0 :
break;
case - V_188 :
case - V_189 :
case - V_190 :
F_8 ( & V_46 -> V_27 , L_40 , V_29 , V_28 ) ;
V_48 -> V_58 -> V_191 = 1 ;
F_78 ( & V_48 -> V_54 ) ;
return;
default:
F_84 ( V_46 , L_41 ,
V_29 , V_28 ) ;
V_48 -> V_58 -> V_191 = 1 ;
F_78 ( & V_48 -> V_54 ) ;
}
F_45 ( V_48 ) ;
}
static void F_80 ( struct V_45 * V_46 , unsigned char * V_100 ,
int V_184 )
{
int V_202 ;
do {
V_202 = F_85 ( & V_46 -> V_46 , V_100 , V_184 ) ;
if ( V_202 < V_184 ) {
F_11 ( & V_46 -> V_27 , L_53 ,
V_29 , V_184 - V_202 ) ;
if ( V_202 == 0 )
break;
}
F_86 ( & V_46 -> V_46 ) ;
V_100 += V_202 ;
V_184 -= V_202 ;
} while ( V_184 > 0 );
}
static void F_45 ( struct V_47 * V_48 )
{
int V_101 , V_163 ;
struct V_45 * V_46 = V_48 -> V_57 ;
unsigned long V_97 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
if ( V_48 -> V_98 )
goto V_203;
V_101 = F_87 ( & V_48 -> V_55 ,
V_46 -> V_89 -> V_183 ,
V_46 -> V_204 ) ;
if ( V_101 == 0 )
goto V_203;
V_48 -> V_98 = 1 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
F_79 ( & V_46 -> V_27 , V_29 , V_101 ,
V_46 -> V_89 -> V_183 ) ;
F_88 ( V_46 -> V_89 , V_46 -> V_23 -> V_27 ,
F_89 ( V_46 -> V_23 -> V_27 ,
V_46 -> V_205 ) ,
V_46 -> V_89 -> V_183 , V_101 ,
F_83 , V_48 ) ;
V_163 = F_33 ( V_46 -> V_89 , V_196 ) ;
if ( V_163 ) {
F_84 ( V_46 , L_54 ,
V_29 , V_163 ) ;
V_48 -> V_98 = 0 ;
} else {
F_40 ( & V_48 -> V_49 , V_97 ) ;
V_46 -> V_198 . V_206 += V_101 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
}
F_90 ( & V_46 -> V_46 ) ;
F_78 ( & V_48 -> V_54 ) ;
return;
V_203:
F_42 ( & V_48 -> V_49 , V_97 ) ;
return;
}
static int F_68 ( struct V_47 * V_48 , unsigned int V_122 )
{
unsigned long V_97 ;
int V_28 ;
V_28 = F_72 ( V_48 -> V_57 , V_48 -> V_58 ,
V_48 -> V_50 + V_207 ,
V_74 | V_75 | V_167 , V_122 ) ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
if ( ! V_28 )
V_48 -> V_73 = V_122 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
return V_28 ;
}
static int F_51 ( struct V_47 * V_48 , T_4 * V_106 )
{
int V_208 , V_28 ;
struct V_24 * V_25 = V_48 -> V_58 ;
struct V_45 * V_46 = V_48 -> V_57 ;
int V_63 = V_46 -> V_70 - V_46 -> V_23 -> V_71 ;
struct V_209 * V_100 ;
V_208 = sizeof( struct V_209 ) ;
V_100 = F_61 ( V_208 , V_35 ) ;
if ( ! V_100 ) {
F_11 ( & V_46 -> V_27 , L_2 , V_29 ) ;
return - V_36 ;
}
V_28 = F_91 ( V_25 , V_210 ,
( V_65 ) ( V_83 + V_63 ) , 0 , ( V_65 * ) V_100 , V_208 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 ,
L_55 ,
V_29 , V_28 ) ;
goto V_211;
}
F_8 ( & V_46 -> V_27 , L_56 , V_29 , V_100 -> V_212 ) ;
* V_106 = V_100 -> V_212 ;
V_211:
F_19 ( V_100 ) ;
return V_28 ;
}
static int F_59 ( struct V_47 * V_48 ,
struct V_111 V_112 * V_213 )
{
struct V_45 * V_46 = V_48 -> V_57 ;
struct V_111 V_214 ;
unsigned V_215 ;
if ( ! V_213 )
return - V_216 ;
V_215 = V_46 -> V_46 . V_53 ;
if ( V_215 != V_217 )
V_215 = F_92 ( V_215 ) / 10 ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
V_214 . type = V_218 ;
V_214 . line = V_46 -> V_23 -> V_71 ;
V_214 . V_46 = V_46 -> V_70 - V_46 -> V_23 -> V_71 ;
V_214 . V_97 = V_48 -> V_219 ;
V_214 . V_220 = V_56 ;
V_214 . V_221 = V_48 -> V_58 -> V_40 ? 921600 : 460800 ;
V_214 . V_53 = V_215 ;
if ( F_93 ( V_213 , & V_214 , sizeof( * V_213 ) ) )
return - V_216 ;
return 0 ;
}
static int F_60 ( struct V_60 * V_61 , struct V_47 * V_48 ,
struct V_111 V_112 * V_222 )
{
struct V_111 V_223 ;
unsigned V_215 ;
if ( F_94 ( & V_223 , V_222 , sizeof( V_223 ) ) )
return - V_216 ;
V_215 = V_223 . V_53 ;
if ( V_215 != V_217 )
V_215 = F_24 ( 10 * V_223 . V_53 ) ;
V_48 -> V_219 = V_223 . V_97 & V_224 ;
V_48 -> V_57 -> V_46 . V_53 = V_215 ;
return 0 ;
}
static void F_76 ( struct V_47 * V_48 , V_65 V_164 )
{
struct V_225 * V_198 ;
struct V_60 * V_61 ;
unsigned long V_97 ;
F_8 ( & V_48 -> V_57 -> V_27 , L_57 , V_29 , V_164 ) ;
if ( V_164 & V_226 ) {
F_40 ( & V_48 -> V_49 , V_97 ) ;
V_198 = & V_48 -> V_57 -> V_198 ;
if ( V_164 & V_227 )
V_198 -> V_228 ++ ;
if ( V_164 & V_229 )
V_198 -> V_230 ++ ;
if ( V_164 & V_231 )
V_198 -> V_232 ++ ;
if ( V_164 & V_233 )
V_198 -> V_234 ++ ;
F_78 ( & V_48 -> V_57 -> V_46 . V_235 ) ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
}
V_48 -> V_72 = V_164 & V_236 ;
V_61 = F_95 ( & V_48 -> V_57 -> V_46 ) ;
if ( V_61 && F_54 ( V_61 ) ) {
if ( V_164 & V_169 ) {
V_61 -> V_156 = 0 ;
F_96 ( V_61 ) ;
} else {
V_61 -> V_156 = 1 ;
}
}
F_97 ( V_61 ) ;
}
static void F_55 ( struct V_47 * V_48 , struct V_60 * V_61 )
{
unsigned long V_97 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
if ( V_48 -> V_92 == V_93 )
V_48 -> V_92 = V_200 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
}
static int F_57 ( struct V_47 * V_48 , struct V_60 * V_61 )
{
struct V_62 * V_62 ;
int V_28 = 0 ;
unsigned long V_97 ;
F_40 ( & V_48 -> V_49 , V_97 ) ;
if ( V_48 -> V_92 == V_201 ) {
V_48 -> V_92 = V_93 ;
V_62 = V_48 -> V_57 -> V_91 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
V_62 -> V_80 = V_48 ;
V_28 = F_33 ( V_62 , V_35 ) ;
} else {
V_48 -> V_92 = V_93 ;
F_42 ( & V_48 -> V_49 , V_97 ) ;
}
return V_28 ;
}
static int F_35 ( struct V_24 * V_25 , V_65 V_237 ,
T_3 V_238 , T_3 V_239 , V_65 * V_100 , int V_208 )
{
int V_28 ;
V_28 = F_98 ( V_25 -> V_38 -> V_27 ,
F_99 ( V_25 -> V_38 -> V_27 , 0 ) , V_237 ,
( V_240 | V_241 | V_242 ) ,
V_239 , V_238 , V_100 , V_208 , 1000 ) ;
if ( V_28 == V_208 )
V_28 = 0 ;
if ( V_28 > 0 )
V_28 = - V_243 ;
return V_28 ;
}
static int F_91 ( struct V_24 * V_25 , V_65 V_237 ,
T_3 V_238 , T_3 V_239 , V_65 * V_100 , int V_208 )
{
int V_28 ;
V_28 = F_98 ( V_25 -> V_38 -> V_27 ,
F_100 ( V_25 -> V_38 -> V_27 , 0 ) , V_237 ,
( V_240 | V_241 | V_244 ) ,
V_239 , V_238 , V_100 , V_208 , 1000 ) ;
if ( V_28 == V_208 )
V_28 = 0 ;
if ( V_28 > 0 )
V_28 = - V_243 ;
return V_28 ;
}
static int F_72 ( struct V_45 * V_46 ,
struct V_24 * V_25 , unsigned long V_245 ,
V_65 V_246 , V_65 V_247 )
{
int V_28 ;
unsigned int V_208 ;
struct V_248 * V_100 ;
F_8 ( & V_46 -> V_27 , L_58 , V_29 ,
V_245 , V_246 , V_247 ) ;
V_208 = sizeof( struct V_248 ) + 2 ;
V_100 = F_61 ( V_208 , V_35 ) ;
if ( ! V_100 ) {
F_11 ( & V_46 -> V_27 , L_2 , V_29 ) ;
return - V_36 ;
}
V_100 -> V_249 = V_250 ;
V_100 -> V_251 = V_252 ;
V_100 -> V_253 = 1 ;
V_100 -> V_254 = F_101 ( V_245 >> 16 ) ;
V_100 -> V_255 = F_101 ( V_245 ) ;
V_100 -> V_256 [ 0 ] = V_246 ;
V_100 -> V_256 [ 1 ] = V_247 ;
V_28 = F_35 ( V_25 , V_257 , V_258 , 0 ,
( V_65 * ) V_100 , V_208 ) ;
if ( V_28 < 0 )
F_11 ( & V_46 -> V_27 , L_59 , V_29 , V_28 ) ;
F_19 ( V_100 ) ;
return V_28 ;
}
static int F_102 ( struct V_26 * V_27 , int V_90 ,
T_4 * V_259 , int V_208 )
{
int V_260 ;
T_4 V_261 = 0 ;
int V_262 ;
struct V_263 * V_264 ;
int V_28 = 0 ;
int V_265 ;
for ( V_260 = sizeof( struct V_263 ) ; V_260 < V_208 ; V_260 ++ )
V_261 = ( V_65 ) ( V_261 + V_259 [ V_260 ] ) ;
V_264 = (struct V_263 * ) V_259 ;
V_264 -> V_266 = F_103 ( ( T_3 ) ( V_208
- sizeof( struct V_263 ) ) ) ;
V_264 -> V_267 = V_261 ;
F_8 ( & V_27 -> V_27 , L_60 , V_29 ) ;
for ( V_260 = 0 ; V_260 < V_208 ; V_260 += V_262 ) {
V_265 = F_3 ( V_208 - V_260 , V_268 ) ;
V_28 = F_104 ( V_27 , V_90 , V_259 + V_260 , V_265 ,
& V_262 , 1000 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_15 ( struct V_24 * V_25 )
{
int V_28 ;
int V_269 ;
V_65 * V_259 ;
struct V_26 * V_27 = V_25 -> V_38 -> V_27 ;
unsigned int V_90 = F_89 ( V_27 ,
V_25 -> V_38 -> V_46 [ 0 ] -> V_205 ) ;
const struct V_270 * V_271 ;
char V_272 [ 32 ] ;
sprintf ( V_272 , L_61 , V_27 -> V_30 . V_9 ,
V_27 -> V_30 . V_11 ) ;
V_28 = F_105 ( & V_271 , V_272 , & V_27 -> V_27 ) ;
if ( V_28 != 0 ) {
V_272 [ 0 ] = '\0' ;
if ( V_27 -> V_30 . V_9 == V_273 ) {
switch ( V_27 -> V_30 . V_11 ) {
case V_274 :
strcpy ( V_272 , L_62 ) ;
break;
case V_275 :
strcpy ( V_272 , L_63 ) ;
break;
case V_276 :
strcpy ( V_272 , L_64 ) ;
break;
case V_277 :
strcpy ( V_272 , L_65 ) ;
break;
case V_278 :
strcpy ( V_272 , L_66 ) ;
break;
case V_279 :
strcpy ( V_272 , L_66 ) ;
break; }
}
if ( V_272 [ 0 ] == '\0' ) {
if ( V_25 -> V_40 )
strcpy ( V_272 , L_67 ) ;
else
strcpy ( V_272 , L_68 ) ;
}
V_28 = F_105 ( & V_271 , V_272 , & V_27 -> V_27 ) ;
}
if ( V_28 ) {
F_11 ( & V_27 -> V_27 , L_69 , V_29 ) ;
return - V_189 ;
}
if ( V_271 -> V_208 > V_280 ) {
F_11 ( & V_27 -> V_27 , L_70 , V_29 , V_271 -> V_208 ) ;
F_106 ( V_271 ) ;
return - V_189 ;
}
V_269 = V_280 + sizeof( struct V_263 ) ;
V_259 = F_61 ( V_269 , V_35 ) ;
if ( V_259 ) {
memcpy ( V_259 , V_271 -> V_100 , V_271 -> V_208 ) ;
memset ( V_259 + V_271 -> V_208 , 0xff , V_269 - V_271 -> V_208 ) ;
V_28 = F_102 ( V_27 , V_90 , V_259 , V_271 -> V_208 ) ;
F_19 ( V_259 ) ;
} else {
F_8 ( & V_27 -> V_27 , L_71 , V_29 ) ;
V_28 = - V_36 ;
}
F_106 ( V_271 ) ;
if ( V_28 ) {
F_11 ( & V_27 -> V_27 , L_72 ,
V_29 , V_28 ) ;
return V_28 ;
}
F_8 ( & V_27 -> V_27 , L_73 , V_29 ) ;
return 0 ;
}
