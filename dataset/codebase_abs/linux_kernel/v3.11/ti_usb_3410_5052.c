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
if ( V_23 -> type == & V_39 )
V_25 -> V_40 = 1 ;
F_8 ( & V_27 -> V_27 , L_3 , V_29 ,
V_25 -> V_40 ? L_4 : L_5 ) ;
if ( V_27 -> V_30 . V_31 == 1 ) {
V_28 = F_14 ( V_25 ) ;
if ( V_28 != 0 )
goto V_41;
if ( V_25 -> V_40 ) {
F_15 ( 100 ) ;
F_16 ( V_27 ) ;
}
V_28 = - V_42 ;
goto V_41;
}
if ( V_27 -> V_32 -> V_33 . V_34 == V_43 ) {
V_28 = F_17 ( V_27 , V_44 ) ;
V_28 = V_28 ? V_28 : - V_42 ;
goto V_41;
}
return 0 ;
V_41:
F_18 ( V_25 ) ;
F_13 ( V_23 , NULL ) ;
return V_28 ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_20 ( V_23 ) ;
F_18 ( V_25 ) ;
}
static int F_21 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
V_48 = F_10 ( sizeof( * V_48 ) , V_35 ) ;
if ( ! V_48 )
return - V_36 ;
F_22 ( & V_48 -> V_49 ) ;
if ( V_46 == V_46 -> V_23 -> V_46 [ 0 ] )
V_48 -> V_50 = V_51 ;
else
V_48 -> V_50 = V_52 ;
V_46 -> V_46 . V_53 = F_23 ( 10 * V_53 ) ;
F_24 ( & V_48 -> V_54 ) ;
if ( F_25 ( & V_48 -> V_55 , V_56 , V_35 ) ) {
F_18 ( V_48 ) ;
return - V_36 ;
}
V_48 -> V_57 = V_46 ;
V_48 -> V_58 = F_20 ( V_46 -> V_23 ) ;
V_48 -> V_59 = 0 ;
F_26 ( V_46 , V_48 ) ;
return 0 ;
}
static int F_27 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
V_48 = F_28 ( V_46 ) ;
F_29 ( & V_48 -> V_55 ) ;
F_18 ( V_48 ) ;
return 0 ;
}
static int F_30 ( struct V_60 * V_61 , struct V_45 * V_46 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
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
if ( F_31 ( & V_25 -> V_37 ) )
return - V_69 ;
V_63 = V_46 -> V_63 ;
V_48 -> V_70 = 0 ;
V_48 -> V_71 |= ( V_72 | V_73 ) ;
if ( V_25 -> V_74 == 0 ) {
F_8 ( & V_46 -> V_27 , L_6 , V_29 ) ;
V_62 = V_25 -> V_38 -> V_46 [ 0 ] -> V_75 ;
if ( ! V_62 ) {
F_11 ( & V_46 -> V_27 , L_7 , V_29 ) ;
V_28 = - V_76 ;
goto V_77;
}
V_62 -> V_78 = V_25 ;
V_28 = F_32 ( V_62 , V_35 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_8 , V_29 , V_28 ) ;
goto V_77;
}
}
if ( V_61 )
F_33 ( V_61 , V_46 , & V_61 -> V_79 ) ;
F_8 ( & V_46 -> V_27 , L_9 , V_29 ) ;
V_28 = F_34 ( V_25 , V_80 ,
( V_65 ) ( V_81 + V_63 ) , V_64 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_10 ,
V_29 , V_28 ) ;
goto V_82;
}
F_8 ( & V_46 -> V_27 , L_11 , V_29 ) ;
V_28 = F_34 ( V_25 , V_83 ,
( V_65 ) ( V_81 + V_63 ) , 0 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_12 ,
V_29 , V_28 ) ;
goto V_82;
}
F_8 ( & V_46 -> V_27 , L_13 , V_29 ) ;
V_28 = F_34 ( V_25 , V_84 ,
( V_65 ) ( V_81 + V_63 ) , V_85 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_14 ,
V_29 , V_28 ) ;
goto V_82;
}
V_28 = F_34 ( V_25 , V_84 ,
( V_65 ) ( V_81 + V_63 ) , V_86 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_15 ,
V_29 , V_28 ) ;
goto V_82;
}
F_35 ( V_27 , V_46 -> V_87 -> V_88 ) ;
F_35 ( V_27 , V_46 -> V_89 -> V_88 ) ;
if ( V_61 )
F_33 ( V_61 , V_46 , & V_61 -> V_79 ) ;
F_8 ( & V_46 -> V_27 , L_16 , V_29 ) ;
V_28 = F_34 ( V_25 , V_80 ,
( V_65 ) ( V_81 + V_63 ) , V_64 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_17 ,
V_29 , V_28 ) ;
goto V_82;
}
F_8 ( & V_46 -> V_27 , L_18 , V_29 ) ;
V_28 = F_34 ( V_25 , V_83 ,
( V_65 ) ( V_81 + V_63 ) , 0 , NULL , 0 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_19 ,
V_29 , V_28 ) ;
goto V_82;
}
F_8 ( & V_46 -> V_27 , L_20 , V_29 ) ;
V_62 = V_46 -> V_89 ;
if ( ! V_62 ) {
F_11 ( & V_46 -> V_27 , L_21 , V_29 ) ;
V_28 = - V_76 ;
goto V_82;
}
V_48 -> V_90 = V_91 ;
V_62 -> V_78 = V_48 ;
V_28 = F_32 ( V_62 , V_35 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 , L_22 ,
V_29 , V_28 ) ;
goto V_82;
}
V_48 -> V_92 = 1 ;
++ V_25 -> V_74 ;
V_46 -> V_46 . V_93 = 3 ;
goto V_77;
V_82:
if ( V_25 -> V_74 == 0 )
F_36 ( V_46 -> V_23 -> V_46 [ 0 ] -> V_75 ) ;
V_77:
F_37 ( & V_25 -> V_37 ) ;
F_8 ( & V_46 -> V_27 , L_23 , V_29 , V_28 ) ;
return V_28 ;
}
static void F_38 ( struct V_45 * V_46 )
{
struct V_24 * V_25 ;
struct V_47 * V_48 ;
int V_63 ;
int V_28 ;
int V_94 ;
unsigned long V_95 ;
V_25 = F_20 ( V_46 -> V_23 ) ;
V_48 = F_28 ( V_46 ) ;
if ( V_25 == NULL || V_48 == NULL )
return;
V_48 -> V_92 = 0 ;
F_36 ( V_46 -> V_89 ) ;
F_36 ( V_46 -> V_87 ) ;
V_48 -> V_96 = 0 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
F_40 ( & V_48 -> V_55 ) ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
V_63 = V_46 -> V_63 ;
F_8 ( & V_46 -> V_27 , L_24 , V_29 ) ;
V_28 = F_34 ( V_25 , V_97 ,
( V_65 ) ( V_81 + V_63 ) , 0 , NULL , 0 ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 ,
L_25
, V_29 , V_28 ) ;
V_94 = ! F_31 ( & V_25 -> V_37 ) ;
-- V_48 -> V_58 -> V_74 ;
if ( V_48 -> V_58 -> V_74 <= 0 ) {
F_36 ( V_46 -> V_23 -> V_46 [ 0 ] -> V_75 ) ;
V_48 -> V_58 -> V_74 = 0 ;
}
if ( V_94 )
F_37 ( & V_25 -> V_37 ) ;
}
static int F_42 ( struct V_60 * V_61 , struct V_45 * V_46 ,
const unsigned char * V_98 , int V_99 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
if ( V_99 == 0 ) {
F_8 ( & V_46 -> V_27 , L_26 , V_29 ) ;
return 0 ;
}
if ( V_48 == NULL || ! V_48 -> V_92 )
return - V_42 ;
V_99 = F_43 ( & V_48 -> V_55 , V_98 , V_99 ,
& V_48 -> V_49 ) ;
F_44 ( V_48 ) ;
return V_99 ;
}
static int F_45 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
int V_101 = 0 ;
unsigned long V_95 ;
if ( V_48 == NULL )
return 0 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
V_101 = F_46 ( & V_48 -> V_55 ) ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
F_8 ( & V_46 -> V_27 , L_27 , V_29 , V_101 ) ;
return V_101 ;
}
static int F_47 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
int V_102 = 0 ;
unsigned long V_95 ;
if ( V_48 == NULL )
return 0 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
V_102 = F_48 ( & V_48 -> V_55 ) ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
F_8 ( & V_46 -> V_27 , L_27 , V_29 , V_102 ) ;
return V_102 ;
}
static bool F_49 ( struct V_45 * V_46 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
int V_103 ;
T_4 V_104 ;
V_103 = F_50 ( V_48 , & V_104 ) ;
if ( ! V_103 && ! ( V_104 & V_105 ) )
return false ;
return true ;
}
static void F_51 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
if ( V_48 == NULL )
return;
if ( F_52 ( V_61 ) || F_53 ( V_61 ) )
F_54 ( V_48 , V_61 ) ;
}
static void F_55 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
int V_28 ;
if ( V_48 == NULL )
return;
if ( F_52 ( V_61 ) || F_53 ( V_61 ) ) {
V_28 = F_56 ( V_48 , V_61 ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 , L_28 ,
V_29 , V_28 ) ;
}
}
static int F_57 ( struct V_60 * V_61 ,
unsigned int V_106 , unsigned long V_107 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
F_8 ( & V_46 -> V_27 , L_29 , V_29 , V_106 ) ;
if ( V_48 == NULL )
return - V_42 ;
switch ( V_106 ) {
case V_108 :
F_8 ( & V_46 -> V_27 , L_30 , V_29 ) ;
return F_58 ( V_48 ,
(struct V_109 V_110 * ) V_107 ) ;
case V_111 :
F_8 ( & V_46 -> V_27 , L_31 , V_29 ) ;
return F_59 ( V_61 , V_48 ,
(struct V_109 V_110 * ) V_107 ) ;
}
return - V_112 ;
}
static void F_33 ( struct V_60 * V_61 ,
struct V_45 * V_46 , struct V_113 * V_114 )
{
struct V_47 * V_48 = F_28 ( V_46 ) ;
struct V_115 * V_116 ;
T_5 V_117 , V_118 ;
int V_119 ;
int V_28 ;
int V_63 = V_46 -> V_63 ;
unsigned int V_120 ;
V_117 = V_61 -> V_79 . V_121 ;
V_118 = V_61 -> V_79 . V_122 ;
F_8 ( & V_46 -> V_27 , L_32 , V_29 , V_117 , V_118 ) ;
F_8 ( & V_46 -> V_27 , L_33 , V_29 ,
V_114 -> V_121 , V_114 -> V_122 ) ;
if ( V_48 == NULL )
return;
V_116 = F_60 ( sizeof( * V_116 ) , V_35 ) ;
if ( ! V_116 ) {
F_11 ( & V_46 -> V_27 , L_2 , V_29 ) ;
return;
}
V_116 -> V_123 = 0 ;
V_116 -> V_123 |= V_124 ;
V_116 -> V_123 |= V_125 ;
V_116 -> V_126 = ( V_65 ) ( V_48 -> V_59 ) ;
switch ( V_117 & V_127 ) {
case V_128 :
V_116 -> V_129 = V_130 ;
break;
case V_131 :
V_116 -> V_129 = V_132 ;
break;
case V_133 :
V_116 -> V_129 = V_134 ;
break;
default:
case V_135 :
V_116 -> V_129 = V_136 ;
break;
}
V_61 -> V_79 . V_121 &= ~ V_137 ;
if ( V_117 & V_138 ) {
if ( V_117 & V_139 ) {
V_116 -> V_123 |= V_140 ;
V_116 -> V_141 = V_142 ;
} else {
V_116 -> V_123 |= V_140 ;
V_116 -> V_141 = V_143 ;
}
} else {
V_116 -> V_123 &= ~ V_140 ;
V_116 -> V_141 = V_144 ;
}
if ( V_117 & V_145 )
V_116 -> V_146 = V_147 ;
else
V_116 -> V_146 = V_148 ;
if ( V_117 & V_149 ) {
if ( ( V_117 & V_150 ) != V_151 )
V_116 -> V_123 |= V_152 ;
V_116 -> V_123 |= V_153 ;
} else {
V_61 -> V_154 = 0 ;
F_56 ( V_48 , V_61 ) ;
}
if ( F_52 ( V_61 ) || F_61 ( V_61 ) ) {
V_116 -> V_155 = F_62 ( V_61 ) ;
V_116 -> V_156 = F_63 ( V_61 ) ;
if ( F_52 ( V_61 ) )
V_116 -> V_123 |= V_157 ;
else
F_56 ( V_48 , V_61 ) ;
if ( F_61 ( V_61 ) )
V_116 -> V_123 |= V_158 ;
}
V_119 = F_64 ( V_61 ) ;
if ( ! V_119 )
V_119 = 9600 ;
if ( V_48 -> V_58 -> V_40 )
V_116 -> V_159 = ( T_3 ) ( ( 923077 + V_119 / 2 ) / V_119 ) ;
else
V_116 -> V_159 = ( T_3 ) ( ( 461538 + V_119 / 2 ) / V_119 ) ;
if ( ( V_117 & V_150 ) != V_151 )
F_65 ( V_61 , V_119 , V_119 ) ;
F_8 ( & V_46 -> V_27 ,
L_34 ,
V_29 , V_119 , V_116 -> V_159 , V_116 -> V_123 ,
V_116 -> V_129 , V_116 -> V_141 , V_116 -> V_146 ,
V_116 -> V_155 , V_116 -> V_156 , V_116 -> V_126 ) ;
F_66 ( & V_116 -> V_159 ) ;
F_66 ( & V_116 -> V_123 ) ;
V_28 = F_34 ( V_48 -> V_58 , V_160 ,
( V_65 ) ( V_81 + V_63 ) , 0 , ( V_65 * ) V_116 ,
sizeof( * V_116 ) ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 , L_35 ,
V_29 , V_63 , V_28 ) ;
V_120 = V_48 -> V_71 ;
if ( ( V_117 & V_150 ) == V_151 )
V_120 &= ~ ( V_73 | V_72 ) ;
V_28 = F_67 ( V_48 , V_120 ) ;
if ( V_28 )
F_11 ( & V_46 -> V_27 ,
L_36 ,
V_29 , V_63 , V_28 ) ;
F_18 ( V_116 ) ;
}
static int F_68 ( struct V_60 * V_61 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
unsigned int V_161 ;
unsigned int V_162 ;
unsigned int V_120 ;
unsigned long V_95 ;
if ( V_48 == NULL )
return - V_42 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
V_162 = V_48 -> V_70 ;
V_120 = V_48 -> V_71 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
V_161 = ( ( V_120 & V_73 ) ? V_163 : 0 )
| ( ( V_120 & V_72 ) ? V_164 : 0 )
| ( ( V_120 & V_165 ) ? V_166 : 0 )
| ( ( V_162 & V_167 ) ? V_168 : 0 )
| ( ( V_162 & V_169 ) ? V_170 : 0 )
| ( ( V_162 & V_171 ) ? V_172 : 0 )
| ( ( V_162 & V_173 ) ? V_174 : 0 ) ;
F_8 ( & V_46 -> V_27 , L_37 , V_29 , V_161 ) ;
return V_161 ;
}
static int F_69 ( struct V_60 * V_61 ,
unsigned int V_175 , unsigned int V_176 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
unsigned int V_120 ;
unsigned long V_95 ;
if ( V_48 == NULL )
return - V_42 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
V_120 = V_48 -> V_71 ;
if ( V_175 & V_164 )
V_120 |= V_72 ;
if ( V_175 & V_163 )
V_120 |= V_73 ;
if ( V_175 & V_166 )
V_120 |= V_165 ;
if ( V_176 & V_164 )
V_120 &= ~ V_72 ;
if ( V_176 & V_163 )
V_120 &= ~ V_73 ;
if ( V_176 & V_166 )
V_120 &= ~ V_165 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
return F_67 ( V_48 , V_120 ) ;
}
static void F_70 ( struct V_60 * V_61 , int V_177 )
{
struct V_45 * V_46 = V_61 -> V_100 ;
struct V_47 * V_48 = F_28 ( V_46 ) ;
int V_28 ;
F_8 ( & V_46 -> V_27 , L_38 , V_29 , V_177 ) ;
if ( V_48 == NULL )
return;
V_28 = F_71 ( V_46 , V_48 -> V_58 ,
V_48 -> V_50 + V_178 ,
V_179 , V_177 == - 1 ? V_179 : 0 ) ;
if ( V_28 )
F_8 ( & V_46 -> V_27 , L_39 , V_29 , V_28 ) ;
}
static void F_72 ( struct V_62 * V_62 )
{
struct V_24 * V_25 = V_62 -> V_78 ;
struct V_45 * V_46 ;
struct V_22 * V_23 = V_25 -> V_38 ;
struct V_47 * V_48 ;
struct V_180 * V_27 = & V_62 -> V_27 -> V_27 ;
unsigned char * V_98 = V_62 -> V_181 ;
int V_182 = V_62 -> V_183 ;
int V_63 ;
int V_184 ;
int V_28 = V_62 -> V_28 ;
int V_185 ;
V_65 V_162 ;
switch ( V_28 ) {
case 0 :
break;
case - V_186 :
case - V_187 :
case - V_188 :
F_8 ( V_27 , L_40 , V_29 , V_28 ) ;
V_25 -> V_189 = 1 ;
return;
default:
F_11 ( V_27 , L_41 , V_29 , V_28 ) ;
V_25 -> V_189 = 1 ;
goto exit;
}
if ( V_182 != 2 ) {
F_8 ( V_27 , L_42 , V_29 , V_182 ) ;
goto exit;
}
if ( V_98 [ 0 ] == V_190 ) {
F_11 ( V_27 , L_43 , V_29 , V_98 [ 1 ] ) ;
goto exit;
}
V_63 = F_73 ( V_98 [ 0 ] ) ;
V_184 = F_74 ( V_98 [ 0 ] ) ;
F_8 ( V_27 , L_44 ,
V_29 , V_63 , V_184 , V_98 [ 1 ] ) ;
if ( V_63 >= V_23 -> V_191 ) {
F_11 ( V_27 , L_45 ,
V_29 , V_63 ) ;
goto exit;
}
V_46 = V_23 -> V_46 [ V_63 ] ;
V_48 = F_28 ( V_46 ) ;
if ( ! V_48 )
goto exit;
switch ( V_184 ) {
case V_192 :
F_11 ( V_27 , L_46 ,
V_29 , V_63 , V_98 [ 1 ] ) ;
break;
case V_193 :
V_162 = V_98 [ 1 ] ;
F_8 ( V_27 , L_47 , V_29 , V_63 , V_162 ) ;
F_75 ( V_48 , V_162 ) ;
break;
default:
F_11 ( V_27 , L_48 ,
V_29 , V_98 [ 1 ] ) ;
break;
}
exit:
V_185 = F_32 ( V_62 , V_194 ) ;
if ( V_185 )
F_11 ( V_27 , L_49 ,
V_29 , V_185 ) ;
}
static void F_76 ( struct V_62 * V_62 )
{
struct V_47 * V_48 = V_62 -> V_78 ;
struct V_45 * V_46 = V_48 -> V_57 ;
struct V_180 * V_27 = & V_62 -> V_27 -> V_27 ;
int V_28 = V_62 -> V_28 ;
int V_185 = 0 ;
switch ( V_28 ) {
case 0 :
break;
case - V_186 :
case - V_187 :
case - V_188 :
F_8 ( V_27 , L_40 , V_29 , V_28 ) ;
V_48 -> V_58 -> V_189 = 1 ;
F_77 ( & V_48 -> V_54 ) ;
return;
default:
F_11 ( V_27 , L_41 ,
V_29 , V_28 ) ;
V_48 -> V_58 -> V_189 = 1 ;
F_77 ( & V_48 -> V_54 ) ;
}
if ( V_28 == - V_195 )
goto exit;
if ( V_28 ) {
F_11 ( V_27 , L_50 , V_29 ) ;
return;
}
if ( V_62 -> V_183 ) {
F_78 ( V_27 , V_29 , V_62 -> V_183 ,
V_62 -> V_181 ) ;
if ( ! V_48 -> V_92 )
F_8 ( V_27 , L_51 ,
V_29 ) ;
else
F_79 ( V_46 , V_62 -> V_181 , V_62 -> V_183 ) ;
F_80 ( & V_48 -> V_49 ) ;
V_46 -> V_196 . V_197 += V_62 -> V_183 ;
F_81 ( & V_48 -> V_49 ) ;
}
exit:
F_80 ( & V_48 -> V_49 ) ;
if ( V_48 -> V_90 == V_91 )
V_185 = F_32 ( V_62 , V_194 ) ;
else if ( V_48 -> V_90 == V_198 )
V_48 -> V_90 = V_199 ;
F_81 ( & V_48 -> V_49 ) ;
if ( V_185 )
F_11 ( V_27 , L_52 ,
V_29 , V_185 ) ;
}
static void F_82 ( struct V_62 * V_62 )
{
struct V_47 * V_48 = V_62 -> V_78 ;
struct V_45 * V_46 = V_48 -> V_57 ;
int V_28 = V_62 -> V_28 ;
V_48 -> V_96 = 0 ;
switch ( V_28 ) {
case 0 :
break;
case - V_186 :
case - V_187 :
case - V_188 :
F_8 ( & V_46 -> V_27 , L_40 , V_29 , V_28 ) ;
V_48 -> V_58 -> V_189 = 1 ;
F_77 ( & V_48 -> V_54 ) ;
return;
default:
F_83 ( V_46 , L_41 ,
V_29 , V_28 ) ;
V_48 -> V_58 -> V_189 = 1 ;
F_77 ( & V_48 -> V_54 ) ;
}
F_44 ( V_48 ) ;
}
static void F_79 ( struct V_45 * V_46 , unsigned char * V_98 ,
int V_182 )
{
int V_200 ;
do {
V_200 = F_84 ( & V_46 -> V_46 , V_98 , V_182 ) ;
if ( V_200 < V_182 ) {
F_11 ( & V_46 -> V_27 , L_53 ,
V_29 , V_182 - V_200 ) ;
if ( V_200 == 0 )
break;
}
F_85 ( & V_46 -> V_46 ) ;
V_98 += V_200 ;
V_182 -= V_200 ;
} while ( V_182 > 0 );
}
static void F_44 ( struct V_47 * V_48 )
{
int V_99 , V_161 ;
struct V_45 * V_46 = V_48 -> V_57 ;
unsigned long V_95 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
if ( V_48 -> V_96 )
goto V_201;
V_99 = F_86 ( & V_48 -> V_55 ,
V_46 -> V_87 -> V_181 ,
V_46 -> V_202 ) ;
if ( V_99 == 0 )
goto V_201;
V_48 -> V_96 = 1 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
F_78 ( & V_46 -> V_27 , V_29 , V_99 ,
V_46 -> V_87 -> V_181 ) ;
F_87 ( V_46 -> V_87 , V_46 -> V_23 -> V_27 ,
F_88 ( V_46 -> V_23 -> V_27 ,
V_46 -> V_203 ) ,
V_46 -> V_87 -> V_181 , V_99 ,
F_82 , V_48 ) ;
V_161 = F_32 ( V_46 -> V_87 , V_194 ) ;
if ( V_161 ) {
F_83 ( V_46 , L_54 ,
V_29 , V_161 ) ;
V_48 -> V_96 = 0 ;
} else {
F_39 ( & V_48 -> V_49 , V_95 ) ;
V_46 -> V_196 . V_204 += V_99 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
}
F_89 ( & V_46 -> V_46 ) ;
F_77 ( & V_48 -> V_54 ) ;
return;
V_201:
F_41 ( & V_48 -> V_49 , V_95 ) ;
return;
}
static int F_67 ( struct V_47 * V_48 , unsigned int V_120 )
{
unsigned long V_95 ;
int V_28 ;
V_28 = F_71 ( V_48 -> V_57 , V_48 -> V_58 ,
V_48 -> V_50 + V_205 ,
V_72 | V_73 | V_165 , V_120 ) ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
if ( ! V_28 )
V_48 -> V_71 = V_120 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
return V_28 ;
}
static int F_50 ( struct V_47 * V_48 , T_4 * V_104 )
{
int V_206 , V_28 ;
struct V_24 * V_25 = V_48 -> V_58 ;
struct V_45 * V_46 = V_48 -> V_57 ;
int V_63 = V_46 -> V_63 ;
struct V_207 * V_98 ;
V_206 = sizeof( struct V_207 ) ;
V_98 = F_60 ( V_206 , V_35 ) ;
if ( ! V_98 ) {
F_11 ( & V_46 -> V_27 , L_2 , V_29 ) ;
return - V_36 ;
}
V_28 = F_90 ( V_25 , V_208 ,
( V_65 ) ( V_81 + V_63 ) , 0 , ( V_65 * ) V_98 , V_206 ) ;
if ( V_28 ) {
F_11 ( & V_46 -> V_27 ,
L_55 ,
V_29 , V_28 ) ;
goto V_209;
}
F_8 ( & V_46 -> V_27 , L_56 , V_29 , V_98 -> V_210 ) ;
* V_104 = V_98 -> V_210 ;
V_209:
F_18 ( V_98 ) ;
return V_28 ;
}
static int F_58 ( struct V_47 * V_48 ,
struct V_109 V_110 * V_211 )
{
struct V_45 * V_46 = V_48 -> V_57 ;
struct V_109 V_212 ;
unsigned V_213 ;
if ( ! V_211 )
return - V_214 ;
V_213 = V_46 -> V_46 . V_53 ;
if ( V_213 != V_215 )
V_213 = F_91 ( V_213 ) / 10 ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . type = V_216 ;
V_212 . line = V_46 -> V_217 ;
V_212 . V_46 = V_46 -> V_63 ;
V_212 . V_95 = V_48 -> V_218 ;
V_212 . V_219 = V_56 ;
V_212 . V_220 = V_48 -> V_58 -> V_40 ? 921600 : 460800 ;
V_212 . V_53 = V_213 ;
if ( F_92 ( V_211 , & V_212 , sizeof( * V_211 ) ) )
return - V_214 ;
return 0 ;
}
static int F_59 ( struct V_60 * V_61 , struct V_47 * V_48 ,
struct V_109 V_110 * V_221 )
{
struct V_109 V_222 ;
unsigned V_213 ;
if ( F_93 ( & V_222 , V_221 , sizeof( V_222 ) ) )
return - V_214 ;
V_213 = V_222 . V_53 ;
if ( V_213 != V_215 )
V_213 = F_23 ( 10 * V_222 . V_53 ) ;
V_48 -> V_218 = V_222 . V_95 & V_223 ;
V_48 -> V_57 -> V_46 . V_53 = V_213 ;
return 0 ;
}
static void F_75 ( struct V_47 * V_48 , V_65 V_162 )
{
struct V_224 * V_196 ;
struct V_60 * V_61 ;
unsigned long V_95 ;
F_8 ( & V_48 -> V_57 -> V_27 , L_57 , V_29 , V_162 ) ;
if ( V_162 & V_225 ) {
F_39 ( & V_48 -> V_49 , V_95 ) ;
V_196 = & V_48 -> V_57 -> V_196 ;
if ( V_162 & V_226 )
V_196 -> V_227 ++ ;
if ( V_162 & V_228 )
V_196 -> V_229 ++ ;
if ( V_162 & V_230 )
V_196 -> V_231 ++ ;
if ( V_162 & V_232 )
V_196 -> V_233 ++ ;
F_77 ( & V_48 -> V_57 -> V_46 . V_234 ) ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
}
V_48 -> V_70 = V_162 & V_235 ;
V_61 = F_94 ( & V_48 -> V_57 -> V_46 ) ;
if ( V_61 && F_53 ( V_61 ) ) {
if ( V_162 & V_167 ) {
V_61 -> V_154 = 0 ;
F_95 ( V_61 ) ;
} else {
V_61 -> V_154 = 1 ;
}
}
F_96 ( V_61 ) ;
}
static void F_54 ( struct V_47 * V_48 , struct V_60 * V_61 )
{
unsigned long V_95 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
if ( V_48 -> V_90 == V_91 )
V_48 -> V_90 = V_198 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
}
static int F_56 ( struct V_47 * V_48 , struct V_60 * V_61 )
{
struct V_62 * V_62 ;
int V_28 = 0 ;
unsigned long V_95 ;
F_39 ( & V_48 -> V_49 , V_95 ) ;
if ( V_48 -> V_90 == V_199 ) {
V_48 -> V_90 = V_91 ;
V_62 = V_48 -> V_57 -> V_89 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
V_62 -> V_78 = V_48 ;
V_28 = F_32 ( V_62 , V_35 ) ;
} else {
V_48 -> V_90 = V_91 ;
F_41 ( & V_48 -> V_49 , V_95 ) ;
}
return V_28 ;
}
static int F_34 ( struct V_24 * V_25 , V_65 V_236 ,
T_3 V_237 , T_3 V_238 , V_65 * V_98 , int V_206 )
{
int V_28 ;
V_28 = F_97 ( V_25 -> V_38 -> V_27 ,
F_98 ( V_25 -> V_38 -> V_27 , 0 ) , V_236 ,
( V_239 | V_240 | V_241 ) ,
V_238 , V_237 , V_98 , V_206 , 1000 ) ;
if ( V_28 == V_206 )
V_28 = 0 ;
if ( V_28 > 0 )
V_28 = - V_242 ;
return V_28 ;
}
static int F_90 ( struct V_24 * V_25 , V_65 V_236 ,
T_3 V_237 , T_3 V_238 , V_65 * V_98 , int V_206 )
{
int V_28 ;
V_28 = F_97 ( V_25 -> V_38 -> V_27 ,
F_99 ( V_25 -> V_38 -> V_27 , 0 ) , V_236 ,
( V_239 | V_240 | V_243 ) ,
V_238 , V_237 , V_98 , V_206 , 1000 ) ;
if ( V_28 == V_206 )
V_28 = 0 ;
if ( V_28 > 0 )
V_28 = - V_242 ;
return V_28 ;
}
static int F_71 ( struct V_45 * V_46 ,
struct V_24 * V_25 , unsigned long V_244 ,
V_65 V_245 , V_65 V_246 )
{
int V_28 ;
unsigned int V_206 ;
struct V_247 * V_98 ;
F_8 ( & V_46 -> V_27 , L_58 , V_29 ,
V_244 , V_245 , V_246 ) ;
V_206 = sizeof( struct V_247 ) + 2 ;
V_98 = F_60 ( V_206 , V_35 ) ;
if ( ! V_98 ) {
F_11 ( & V_46 -> V_27 , L_2 , V_29 ) ;
return - V_36 ;
}
V_98 -> V_248 = V_249 ;
V_98 -> V_250 = V_251 ;
V_98 -> V_252 = 1 ;
V_98 -> V_253 = F_100 ( V_244 >> 16 ) ;
V_98 -> V_254 = F_100 ( V_244 ) ;
V_98 -> V_255 [ 0 ] = V_245 ;
V_98 -> V_255 [ 1 ] = V_246 ;
V_28 = F_34 ( V_25 , V_256 , V_257 , 0 ,
( V_65 * ) V_98 , V_206 ) ;
if ( V_28 < 0 )
F_11 ( & V_46 -> V_27 , L_59 , V_29 , V_28 ) ;
F_18 ( V_98 ) ;
return V_28 ;
}
static int F_101 ( struct V_26 * V_27 , int V_88 ,
T_4 * V_258 , int V_206 )
{
int V_259 ;
T_4 V_260 = 0 ;
int V_261 ;
struct V_262 * V_263 ;
int V_28 = 0 ;
int V_264 ;
for ( V_259 = sizeof( struct V_262 ) ; V_259 < V_206 ; V_259 ++ )
V_260 = ( V_65 ) ( V_260 + V_258 [ V_259 ] ) ;
V_263 = (struct V_262 * ) V_258 ;
V_263 -> V_265 = F_102 ( ( T_3 ) ( V_206
- sizeof( struct V_262 ) ) ) ;
V_263 -> V_266 = V_260 ;
F_8 ( & V_27 -> V_27 , L_60 , V_29 ) ;
for ( V_259 = 0 ; V_259 < V_206 ; V_259 += V_261 ) {
V_264 = F_3 ( V_206 - V_259 , V_267 ) ;
V_28 = F_103 ( V_27 , V_88 , V_258 + V_259 , V_264 ,
& V_261 , 1000 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
static int F_14 ( struct V_24 * V_25 )
{
int V_28 ;
int V_268 ;
V_65 * V_258 ;
struct V_26 * V_27 = V_25 -> V_38 -> V_27 ;
unsigned int V_88 = F_88 ( V_27 ,
V_25 -> V_38 -> V_46 [ 0 ] -> V_203 ) ;
const struct V_269 * V_270 ;
char V_271 [ 32 ] ;
sprintf ( V_271 , L_61 ,
F_9 ( V_27 -> V_30 . V_9 ) ,
F_9 ( V_27 -> V_30 . V_11 ) ) ;
V_28 = F_104 ( & V_270 , V_271 , & V_27 -> V_27 ) ;
if ( V_28 != 0 ) {
V_271 [ 0 ] = '\0' ;
if ( F_9 ( V_27 -> V_30 . V_9 ) == V_272 ) {
switch ( F_9 ( V_27 -> V_30 . V_11 ) ) {
case V_273 :
strcpy ( V_271 , L_62 ) ;
break;
case V_274 :
strcpy ( V_271 , L_63 ) ;
break;
case V_275 :
strcpy ( V_271 , L_64 ) ;
break;
case V_276 :
strcpy ( V_271 , L_65 ) ;
break;
case V_277 :
strcpy ( V_271 , L_66 ) ;
break;
case V_278 :
strcpy ( V_271 , L_66 ) ;
break; }
}
if ( V_271 [ 0 ] == '\0' ) {
if ( V_25 -> V_40 )
strcpy ( V_271 , L_67 ) ;
else
strcpy ( V_271 , L_68 ) ;
}
V_28 = F_104 ( & V_270 , V_271 , & V_27 -> V_27 ) ;
}
if ( V_28 ) {
F_11 ( & V_27 -> V_27 , L_69 , V_29 ) ;
return - V_187 ;
}
if ( V_270 -> V_206 > V_279 ) {
F_11 ( & V_27 -> V_27 , L_70 , V_29 , V_270 -> V_206 ) ;
F_105 ( V_270 ) ;
return - V_187 ;
}
V_268 = V_279 + sizeof( struct V_262 ) ;
V_258 = F_60 ( V_268 , V_35 ) ;
if ( V_258 ) {
memcpy ( V_258 , V_270 -> V_98 , V_270 -> V_206 ) ;
memset ( V_258 + V_270 -> V_206 , 0xff , V_268 - V_270 -> V_206 ) ;
V_28 = F_101 ( V_27 , V_88 , V_258 , V_270 -> V_206 ) ;
F_18 ( V_258 ) ;
} else {
F_8 ( & V_27 -> V_27 , L_71 , V_29 ) ;
V_28 = - V_36 ;
}
F_105 ( V_270 ) ;
if ( V_28 ) {
F_11 ( & V_27 -> V_27 , L_72 ,
V_29 , V_28 ) ;
return V_28 ;
}
F_8 ( & V_27 -> V_27 , L_73 , V_29 ) ;
return 0 ;
}
