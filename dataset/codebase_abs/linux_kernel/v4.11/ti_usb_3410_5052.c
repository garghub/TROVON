static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_9 ;
T_1 V_10 , V_11 ;
int V_12 ;
F_2 ( & V_6 -> V_6 ,
L_1 ,
V_13 , F_3 ( V_6 -> V_14 . V_15 ) ,
V_6 -> V_14 . V_16 ,
V_6 -> V_17 -> V_18 . V_19 ) ;
V_4 = F_4 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
F_5 ( & V_4 -> V_22 ) ;
V_4 -> V_23 = V_2 ;
F_6 ( V_2 , V_4 ) ;
if ( V_2 -> type == & V_24 )
V_4 -> V_25 = 1 ;
F_2 ( & V_6 -> V_6 , L_2 , V_13 ,
V_4 -> V_25 ? L_3 : L_4 ) ;
V_10 = F_3 ( V_6 -> V_14 . V_26 ) ;
V_11 = F_3 ( V_6 -> V_14 . V_15 ) ;
if ( V_10 == V_27 ) {
switch ( V_11 ) {
case V_28 :
case V_29 :
V_4 -> V_30 = true ;
break;
}
}
V_8 = V_2 -> V_31 -> V_8 ;
V_9 = V_8 -> V_18 . V_32 ;
if ( V_6 -> V_14 . V_16 == 1 && V_9 == 1 ) {
V_12 = F_7 ( V_4 ) ;
if ( V_12 != 0 )
goto V_33;
if ( V_4 -> V_25 ) {
F_8 ( 100 ) ;
F_9 ( V_6 ) ;
}
V_12 = - V_34 ;
goto V_33;
}
if ( V_6 -> V_17 -> V_18 . V_19 == V_35 ) {
V_12 = F_10 ( V_6 , V_36 ) ;
V_12 = V_12 ? V_12 : - V_34 ;
goto V_33;
}
if ( V_2 -> V_37 < V_2 -> V_38 ||
V_2 -> V_39 < V_2 -> V_38 ) {
F_11 ( & V_2 -> V_31 -> V_6 , L_5 ) ;
V_12 = - V_34 ;
goto V_33;
}
return 0 ;
V_33:
F_12 ( V_4 ) ;
F_6 ( V_2 , NULL ) ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_14 ( V_2 ) ;
F_12 ( V_4 ) ;
}
static int F_15 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
V_43 = F_4 ( sizeof( * V_43 ) , V_20 ) ;
if ( ! V_43 )
return - V_21 ;
F_16 ( & V_43 -> V_44 ) ;
if ( V_41 == V_41 -> V_2 -> V_41 [ 0 ] )
V_43 -> V_45 = V_46 ;
else
V_43 -> V_45 = V_47 ;
V_41 -> V_41 . V_48 = F_17 ( 10 * V_48 ) ;
V_43 -> V_49 = V_41 ;
V_43 -> V_50 = F_14 ( V_41 -> V_2 ) ;
if ( V_43 -> V_50 -> V_30 )
V_43 -> V_51 = V_52 ;
else
V_43 -> V_51 = V_53 ;
F_18 ( V_41 , V_43 ) ;
V_41 -> V_41 . V_54 = 3 ;
return 0 ;
}
static int F_19 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
V_43 = F_20 ( V_41 ) ;
F_12 ( V_43 ) ;
return 0 ;
}
static int F_21 ( struct V_55 * V_56 , struct V_40 * V_41 )
{
struct V_42 * V_43 = F_20 ( V_41 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_57 * V_57 ;
int V_58 ;
int V_12 ;
T_1 V_59 ;
V_59 = ( V_60 |
V_61 |
( V_62 << 2 ) ) ;
V_6 = V_41 -> V_2 -> V_6 ;
V_4 = V_43 -> V_50 ;
if ( F_22 ( & V_4 -> V_22 ) )
return - V_63 ;
V_58 = V_41 -> V_58 ;
V_43 -> V_64 = 0 ;
V_43 -> V_65 |= ( V_66 | V_67 ) ;
if ( V_4 -> V_68 == 0 ) {
F_2 ( & V_41 -> V_6 , L_6 , V_13 ) ;
V_57 = V_4 -> V_23 -> V_41 [ 0 ] -> V_69 ;
if ( ! V_57 ) {
F_11 ( & V_41 -> V_6 , L_7 , V_13 ) ;
V_12 = - V_70 ;
goto V_71;
}
V_57 -> V_72 = V_4 ;
V_12 = F_23 ( V_57 , V_20 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_8 , V_13 , V_12 ) ;
goto V_71;
}
}
if ( V_56 )
F_24 ( V_56 , V_41 , & V_56 -> V_73 ) ;
V_12 = F_25 ( V_4 , V_74 ,
( V_75 ) ( V_76 + V_58 ) , V_59 , NULL , 0 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_9 ,
V_13 , V_12 ) ;
goto V_77;
}
V_12 = F_25 ( V_4 , V_78 ,
( V_75 ) ( V_76 + V_58 ) , 0 , NULL , 0 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_10 ,
V_13 , V_12 ) ;
goto V_77;
}
V_12 = F_25 ( V_4 , V_79 ,
( V_75 ) ( V_76 + V_58 ) , V_80 , NULL , 0 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_11 ,
V_13 , V_12 ) ;
goto V_77;
}
V_12 = F_25 ( V_4 , V_79 ,
( V_75 ) ( V_76 + V_58 ) , V_81 , NULL , 0 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_12 ,
V_13 , V_12 ) ;
goto V_77;
}
F_26 ( V_6 , V_41 -> V_82 -> V_83 ) ;
F_26 ( V_6 , V_41 -> V_84 -> V_83 ) ;
if ( V_56 )
F_24 ( V_56 , V_41 , & V_56 -> V_73 ) ;
V_12 = F_25 ( V_4 , V_74 ,
( V_75 ) ( V_76 + V_58 ) , V_59 , NULL , 0 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_13 ,
V_13 , V_12 ) ;
goto V_77;
}
V_12 = F_25 ( V_4 , V_78 ,
( V_75 ) ( V_76 + V_58 ) , 0 , NULL , 0 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_14 ,
V_13 , V_12 ) ;
goto V_77;
}
V_57 = V_41 -> V_84 ;
if ( ! V_57 ) {
F_11 ( & V_41 -> V_6 , L_15 , V_13 ) ;
V_12 = - V_70 ;
goto V_77;
}
V_43 -> V_85 = V_86 ;
V_57 -> V_72 = V_43 ;
V_12 = F_23 ( V_57 , V_20 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 , L_16 ,
V_13 , V_12 ) ;
goto V_77;
}
V_43 -> V_87 = 1 ;
++ V_4 -> V_68 ;
goto V_71;
V_77:
if ( V_4 -> V_68 == 0 )
F_27 ( V_41 -> V_2 -> V_41 [ 0 ] -> V_69 ) ;
V_71:
F_28 ( & V_4 -> V_22 ) ;
return V_12 ;
}
static void F_29 ( struct V_40 * V_41 )
{
struct V_3 * V_4 ;
struct V_42 * V_43 ;
int V_58 ;
int V_12 ;
int V_88 ;
unsigned long V_89 ;
V_4 = F_14 ( V_41 -> V_2 ) ;
V_43 = F_20 ( V_41 ) ;
V_43 -> V_87 = 0 ;
F_27 ( V_41 -> V_84 ) ;
F_27 ( V_41 -> V_82 ) ;
V_43 -> V_90 = 0 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
F_31 ( & V_41 -> V_91 ) ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
V_58 = V_41 -> V_58 ;
V_12 = F_25 ( V_4 , V_92 ,
( V_75 ) ( V_76 + V_58 ) , 0 , NULL , 0 ) ;
if ( V_12 )
F_11 ( & V_41 -> V_6 ,
L_17
, V_13 , V_12 ) ;
V_88 = ! F_22 ( & V_4 -> V_22 ) ;
-- V_43 -> V_50 -> V_68 ;
if ( V_43 -> V_50 -> V_68 <= 0 ) {
F_27 ( V_41 -> V_2 -> V_41 [ 0 ] -> V_69 ) ;
V_43 -> V_50 -> V_68 = 0 ;
}
if ( V_88 )
F_28 ( & V_4 -> V_22 ) ;
}
static int F_33 ( struct V_55 * V_56 , struct V_40 * V_41 ,
const unsigned char * V_93 , int V_94 )
{
struct V_42 * V_43 = F_20 ( V_41 ) ;
if ( V_94 == 0 ) {
return 0 ;
}
if ( ! V_43 -> V_87 )
return - V_34 ;
V_94 = F_34 ( & V_41 -> V_91 , V_93 , V_94 ,
& V_43 -> V_44 ) ;
F_35 ( V_43 ) ;
return V_94 ;
}
static int F_36 ( struct V_55 * V_56 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
int V_96 = 0 ;
unsigned long V_89 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
V_96 = F_37 ( & V_41 -> V_91 ) ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
F_2 ( & V_41 -> V_6 , L_18 , V_13 , V_96 ) ;
return V_96 ;
}
static int F_38 ( struct V_55 * V_56 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
int V_97 = 0 ;
unsigned long V_89 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
V_97 = F_39 ( & V_41 -> V_91 ) ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
F_2 ( & V_41 -> V_6 , L_18 , V_13 , V_97 ) ;
return V_97 ;
}
static bool F_40 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_20 ( V_41 ) ;
int V_98 ;
T_2 V_99 ;
V_98 = F_41 ( V_43 , & V_99 ) ;
if ( ! V_98 && ! ( V_99 & V_100 ) )
return false ;
return true ;
}
static void F_42 ( struct V_55 * V_56 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
if ( F_43 ( V_56 ) || F_44 ( V_56 ) )
F_45 ( V_43 , V_56 ) ;
}
static void F_46 ( struct V_55 * V_56 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
int V_12 ;
if ( F_43 ( V_56 ) || F_44 ( V_56 ) ) {
V_12 = F_47 ( V_43 , V_56 ) ;
if ( V_12 )
F_11 ( & V_41 -> V_6 , L_19 ,
V_13 , V_12 ) ;
}
}
static int F_48 ( struct V_55 * V_56 ,
unsigned int V_101 , unsigned long V_102 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
switch ( V_101 ) {
case V_103 :
return F_49 ( V_43 ,
(struct V_104 V_105 * ) V_102 ) ;
case V_106 :
return F_50 ( V_56 , V_43 ,
(struct V_104 V_105 * ) V_102 ) ;
}
return - V_107 ;
}
static void F_24 ( struct V_55 * V_56 ,
struct V_40 * V_41 , struct V_108 * V_109 )
{
struct V_42 * V_43 = F_20 ( V_41 ) ;
struct V_110 * V_111 ;
T_3 V_112 , V_113 ;
int V_114 ;
int V_12 ;
int V_58 = V_41 -> V_58 ;
unsigned int V_115 ;
T_1 V_116 ;
T_1 V_117 = 0 ;
V_112 = V_56 -> V_73 . V_118 ;
V_113 = V_56 -> V_73 . V_119 ;
F_2 ( & V_41 -> V_6 , L_20 , V_13 , V_112 , V_113 ) ;
F_2 ( & V_41 -> V_6 , L_21 , V_13 ,
V_109 -> V_118 , V_109 -> V_119 ) ;
V_111 = F_51 ( sizeof( * V_111 ) , V_20 ) ;
if ( ! V_111 )
return;
V_117 |= V_120 ;
V_117 |= V_121 ;
V_111 -> V_122 = V_43 -> V_51 ;
switch ( F_52 ( V_56 ) ) {
case V_123 :
V_111 -> V_124 = V_125 ;
break;
case V_126 :
V_111 -> V_124 = V_127 ;
break;
case V_128 :
V_111 -> V_124 = V_129 ;
break;
default:
case V_130 :
V_111 -> V_124 = V_131 ;
break;
}
V_56 -> V_73 . V_118 &= ~ V_132 ;
if ( F_53 ( V_56 ) ) {
if ( F_54 ( V_56 ) ) {
V_117 |= V_133 ;
V_111 -> V_134 = V_135 ;
} else {
V_117 |= V_133 ;
V_111 -> V_134 = V_136 ;
}
} else {
V_117 &= ~ V_133 ;
V_111 -> V_134 = V_137 ;
}
if ( F_55 ( V_56 ) )
V_111 -> V_138 = V_139 ;
else
V_111 -> V_138 = V_140 ;
if ( F_44 ( V_56 ) ) {
if ( ( F_56 ( V_56 ) ) != V_141 )
V_117 |= V_142 ;
V_117 |= V_143 ;
} else {
F_47 ( V_43 , V_56 ) ;
}
if ( F_43 ( V_56 ) || F_57 ( V_56 ) ) {
V_111 -> V_144 = F_58 ( V_56 ) ;
V_111 -> V_145 = F_59 ( V_56 ) ;
if ( F_43 ( V_56 ) )
V_117 |= V_146 ;
else
F_47 ( V_43 , V_56 ) ;
if ( F_57 ( V_56 ) )
V_117 |= V_147 ;
}
V_114 = F_60 ( V_56 ) ;
if ( ! V_114 )
V_114 = 9600 ;
if ( V_43 -> V_50 -> V_25 )
V_116 = ( 923077 + V_114 / 2 ) / V_114 ;
else
V_116 = ( 461538 + V_114 / 2 ) / V_114 ;
if ( ( F_56 ( V_56 ) ) != V_141 )
F_61 ( V_56 , V_114 , V_114 ) ;
F_2 ( & V_41 -> V_6 ,
L_22 ,
V_13 , V_114 , V_116 , V_117 ,
V_111 -> V_124 , V_111 -> V_134 , V_111 -> V_138 ,
V_111 -> V_144 , V_111 -> V_145 , V_111 -> V_122 ) ;
V_111 -> V_148 = F_62 ( V_116 ) ;
V_111 -> V_149 = F_62 ( V_117 ) ;
V_12 = F_25 ( V_43 -> V_50 , V_150 ,
( V_75 ) ( V_76 + V_58 ) , 0 , ( V_75 * ) V_111 ,
sizeof( * V_111 ) ) ;
if ( V_12 )
F_11 ( & V_41 -> V_6 , L_23 ,
V_13 , V_58 , V_12 ) ;
V_115 = V_43 -> V_65 ;
if ( F_56 ( V_56 ) == V_141 )
V_115 &= ~ ( V_67 | V_66 ) ;
V_12 = F_63 ( V_43 , V_115 ) ;
if ( V_12 )
F_11 ( & V_41 -> V_6 ,
L_24 ,
V_13 , V_58 , V_12 ) ;
F_12 ( V_111 ) ;
}
static int F_64 ( struct V_55 * V_56 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
unsigned int V_151 ;
unsigned int V_152 ;
unsigned int V_115 ;
unsigned long V_89 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
V_152 = V_43 -> V_64 ;
V_115 = V_43 -> V_65 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
V_151 = ( ( V_115 & V_67 ) ? V_153 : 0 )
| ( ( V_115 & V_66 ) ? V_154 : 0 )
| ( ( V_115 & V_155 ) ? V_156 : 0 )
| ( ( V_152 & V_157 ) ? V_158 : 0 )
| ( ( V_152 & V_159 ) ? V_160 : 0 )
| ( ( V_152 & V_161 ) ? V_162 : 0 )
| ( ( V_152 & V_163 ) ? V_164 : 0 ) ;
F_2 ( & V_41 -> V_6 , L_25 , V_13 , V_151 ) ;
return V_151 ;
}
static int F_65 ( struct V_55 * V_56 ,
unsigned int V_165 , unsigned int V_166 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
unsigned int V_115 ;
unsigned long V_89 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
V_115 = V_43 -> V_65 ;
if ( V_165 & V_154 )
V_115 |= V_66 ;
if ( V_165 & V_153 )
V_115 |= V_67 ;
if ( V_165 & V_156 )
V_115 |= V_155 ;
if ( V_166 & V_154 )
V_115 &= ~ V_66 ;
if ( V_166 & V_153 )
V_115 &= ~ V_67 ;
if ( V_166 & V_156 )
V_115 &= ~ V_155 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
return F_63 ( V_43 , V_115 ) ;
}
static void F_66 ( struct V_55 * V_56 , int V_167 )
{
struct V_40 * V_41 = V_56 -> V_95 ;
struct V_42 * V_43 = F_20 ( V_41 ) ;
int V_12 ;
F_2 ( & V_41 -> V_6 , L_26 , V_13 , V_167 ) ;
V_12 = F_67 ( V_41 , V_43 -> V_50 ,
V_43 -> V_45 + V_168 ,
V_169 , V_167 == - 1 ? V_169 : 0 ) ;
if ( V_12 )
F_2 ( & V_41 -> V_6 , L_27 , V_13 , V_12 ) ;
}
static int F_68 ( unsigned char V_170 )
{
return ( V_170 >> 4 ) - 3 ;
}
static int F_69 ( unsigned char V_170 )
{
return V_170 & 0x0f ;
}
static void F_70 ( struct V_57 * V_57 )
{
struct V_3 * V_4 = V_57 -> V_72 ;
struct V_40 * V_41 ;
struct V_1 * V_2 = V_4 -> V_23 ;
struct V_42 * V_43 ;
struct V_171 * V_6 = & V_57 -> V_6 -> V_6 ;
unsigned char * V_93 = V_57 -> V_172 ;
int V_173 = V_57 -> V_174 ;
int V_58 ;
int V_175 ;
int V_12 = V_57 -> V_12 ;
int V_176 ;
T_2 V_152 ;
switch ( V_12 ) {
case 0 :
break;
case - V_177 :
case - V_178 :
case - V_179 :
F_2 ( V_6 , L_28 , V_13 , V_12 ) ;
return;
default:
F_11 ( V_6 , L_29 , V_13 , V_12 ) ;
goto exit;
}
if ( V_173 != 2 ) {
F_2 ( V_6 , L_30 , V_13 , V_173 ) ;
goto exit;
}
if ( V_93 [ 0 ] == V_180 ) {
F_11 ( V_6 , L_31 , V_13 , V_93 [ 1 ] ) ;
goto exit;
}
V_58 = F_68 ( V_93 [ 0 ] ) ;
V_175 = F_69 ( V_93 [ 0 ] ) ;
F_2 ( V_6 , L_32 ,
V_13 , V_58 , V_175 , V_93 [ 1 ] ) ;
if ( V_58 >= V_2 -> V_38 ) {
F_11 ( V_6 , L_33 ,
V_13 , V_58 ) ;
goto exit;
}
V_41 = V_2 -> V_41 [ V_58 ] ;
V_43 = F_20 ( V_41 ) ;
if ( ! V_43 )
goto exit;
switch ( V_175 ) {
case V_181 :
F_11 ( V_6 , L_34 ,
V_13 , V_58 , V_93 [ 1 ] ) ;
break;
case V_182 :
V_152 = V_93 [ 1 ] ;
F_2 ( V_6 , L_35 , V_13 , V_58 , V_152 ) ;
F_71 ( V_43 , V_152 ) ;
break;
default:
F_11 ( V_6 , L_36 ,
V_13 , V_93 [ 1 ] ) ;
break;
}
exit:
V_176 = F_23 ( V_57 , V_183 ) ;
if ( V_176 )
F_11 ( V_6 , L_37 ,
V_13 , V_176 ) ;
}
static void F_72 ( struct V_57 * V_57 )
{
struct V_42 * V_43 = V_57 -> V_72 ;
struct V_40 * V_41 = V_43 -> V_49 ;
struct V_171 * V_6 = & V_57 -> V_6 -> V_6 ;
int V_12 = V_57 -> V_12 ;
int V_176 = 0 ;
switch ( V_12 ) {
case 0 :
break;
case - V_177 :
case - V_178 :
case - V_179 :
F_2 ( V_6 , L_28 , V_13 , V_12 ) ;
return;
default:
F_11 ( V_6 , L_29 ,
V_13 , V_12 ) ;
}
if ( V_12 == - V_184 )
goto exit;
if ( V_12 ) {
F_11 ( V_6 , L_38 , V_13 ) ;
return;
}
if ( V_57 -> V_174 ) {
F_73 ( V_6 , V_13 , V_57 -> V_174 ,
V_57 -> V_172 ) ;
if ( ! V_43 -> V_87 )
F_2 ( V_6 , L_39 ,
V_13 ) ;
else
F_74 ( V_41 , V_57 -> V_172 , V_57 -> V_174 ) ;
F_75 ( & V_43 -> V_44 ) ;
V_41 -> V_185 . V_186 += V_57 -> V_174 ;
F_76 ( & V_43 -> V_44 ) ;
}
exit:
F_75 ( & V_43 -> V_44 ) ;
if ( V_43 -> V_85 == V_86 )
V_176 = F_23 ( V_57 , V_183 ) ;
else if ( V_43 -> V_85 == V_187 )
V_43 -> V_85 = V_188 ;
F_76 ( & V_43 -> V_44 ) ;
if ( V_176 )
F_11 ( V_6 , L_40 ,
V_13 , V_176 ) ;
}
static void F_77 ( struct V_57 * V_57 )
{
struct V_42 * V_43 = V_57 -> V_72 ;
struct V_40 * V_41 = V_43 -> V_49 ;
int V_12 = V_57 -> V_12 ;
V_43 -> V_90 = 0 ;
switch ( V_12 ) {
case 0 :
break;
case - V_177 :
case - V_178 :
case - V_179 :
F_2 ( & V_41 -> V_6 , L_28 , V_13 , V_12 ) ;
return;
default:
F_78 ( V_41 , L_29 ,
V_13 , V_12 ) ;
}
F_35 ( V_43 ) ;
}
static void F_74 ( struct V_40 * V_41 , unsigned char * V_93 ,
int V_173 )
{
int V_189 ;
do {
V_189 = F_79 ( & V_41 -> V_41 , V_93 , V_173 ) ;
if ( V_189 < V_173 ) {
F_11 ( & V_41 -> V_6 , L_41 ,
V_13 , V_173 - V_189 ) ;
if ( V_189 == 0 )
break;
}
F_80 ( & V_41 -> V_41 ) ;
V_93 += V_189 ;
V_173 -= V_189 ;
} while ( V_173 > 0 );
}
static void F_35 ( struct V_42 * V_43 )
{
int V_94 , V_151 ;
struct V_40 * V_41 = V_43 -> V_49 ;
unsigned long V_89 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
if ( V_43 -> V_90 )
goto V_190;
V_94 = F_81 ( & V_41 -> V_91 ,
V_41 -> V_82 -> V_172 ,
V_41 -> V_191 ) ;
if ( V_94 == 0 )
goto V_190;
V_43 -> V_90 = 1 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
F_73 ( & V_41 -> V_6 , V_13 , V_94 ,
V_41 -> V_82 -> V_172 ) ;
F_82 ( V_41 -> V_82 , V_41 -> V_2 -> V_6 ,
F_83 ( V_41 -> V_2 -> V_6 ,
V_41 -> V_192 ) ,
V_41 -> V_82 -> V_172 , V_94 ,
F_77 , V_43 ) ;
V_151 = F_23 ( V_41 -> V_82 , V_183 ) ;
if ( V_151 ) {
F_78 ( V_41 , L_42 ,
V_13 , V_151 ) ;
V_43 -> V_90 = 0 ;
} else {
F_30 ( & V_43 -> V_44 , V_89 ) ;
V_41 -> V_185 . V_193 += V_94 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
}
F_84 ( & V_41 -> V_41 ) ;
return;
V_190:
F_32 ( & V_43 -> V_44 , V_89 ) ;
return;
}
static int F_63 ( struct V_42 * V_43 , unsigned int V_115 )
{
unsigned long V_89 ;
int V_12 ;
V_12 = F_67 ( V_43 -> V_49 , V_43 -> V_50 ,
V_43 -> V_45 + V_194 ,
V_66 | V_67 | V_155 , V_115 ) ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
if ( ! V_12 )
V_43 -> V_65 = V_115 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
return V_12 ;
}
static int F_41 ( struct V_42 * V_43 , T_2 * V_99 )
{
int V_195 , V_12 ;
struct V_3 * V_4 = V_43 -> V_50 ;
struct V_40 * V_41 = V_43 -> V_49 ;
int V_58 = V_41 -> V_58 ;
struct V_196 * V_93 ;
V_195 = sizeof( struct V_196 ) ;
V_93 = F_51 ( V_195 , V_20 ) ;
if ( ! V_93 )
return - V_21 ;
V_12 = F_85 ( V_4 , V_197 ,
( V_75 ) ( V_76 + V_58 ) , 0 , ( V_75 * ) V_93 , V_195 ) ;
if ( V_12 ) {
F_11 ( & V_41 -> V_6 ,
L_43 ,
V_13 , V_12 ) ;
goto V_198;
}
F_2 ( & V_41 -> V_6 , L_44 , V_13 , V_93 -> V_199 ) ;
* V_99 = V_93 -> V_199 ;
V_198:
F_12 ( V_93 ) ;
return V_12 ;
}
static int F_49 ( struct V_42 * V_43 ,
struct V_104 V_105 * V_200 )
{
struct V_40 * V_41 = V_43 -> V_49 ;
struct V_104 V_201 ;
unsigned V_202 ;
V_202 = V_41 -> V_41 . V_48 ;
if ( V_202 != V_203 )
V_202 = F_86 ( V_202 ) / 10 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . type = V_204 ;
V_201 . line = V_41 -> V_205 ;
V_201 . V_41 = V_41 -> V_58 ;
V_201 . V_206 = F_87 ( & V_41 -> V_91 ) ;
V_201 . V_207 = V_43 -> V_50 -> V_25 ? 921600 : 460800 ;
V_201 . V_48 = V_202 ;
if ( F_88 ( V_200 , & V_201 , sizeof( * V_200 ) ) )
return - V_208 ;
return 0 ;
}
static int F_50 ( struct V_55 * V_56 , struct V_42 * V_43 ,
struct V_104 V_105 * V_209 )
{
struct V_104 V_210 ;
unsigned V_202 ;
if ( F_89 ( & V_210 , V_209 , sizeof( V_210 ) ) )
return - V_208 ;
V_202 = V_210 . V_48 ;
if ( V_202 != V_203 )
V_202 = F_17 ( 10 * V_210 . V_48 ) ;
V_43 -> V_49 -> V_41 . V_48 = V_202 ;
return 0 ;
}
static void F_71 ( struct V_42 * V_43 , T_2 V_152 )
{
struct V_211 * V_185 ;
struct V_55 * V_56 ;
unsigned long V_89 ;
F_2 ( & V_43 -> V_49 -> V_6 , L_45 , V_13 , V_152 ) ;
if ( V_152 & V_212 ) {
F_30 ( & V_43 -> V_44 , V_89 ) ;
V_185 = & V_43 -> V_49 -> V_185 ;
if ( V_152 & V_213 )
V_185 -> V_214 ++ ;
if ( V_152 & V_215 )
V_185 -> V_216 ++ ;
if ( V_152 & V_217 )
V_185 -> V_218 ++ ;
if ( V_152 & V_219 )
V_185 -> V_220 ++ ;
F_90 ( & V_43 -> V_49 -> V_41 . V_221 ) ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
}
V_43 -> V_64 = V_152 & V_222 ;
V_56 = F_91 ( & V_43 -> V_49 -> V_41 ) ;
if ( V_56 && F_44 ( V_56 ) ) {
if ( V_152 & V_157 )
F_92 ( V_56 ) ;
}
F_93 ( V_56 ) ;
}
static void F_45 ( struct V_42 * V_43 , struct V_55 * V_56 )
{
unsigned long V_89 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
if ( V_43 -> V_85 == V_86 )
V_43 -> V_85 = V_187 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
}
static int F_47 ( struct V_42 * V_43 , struct V_55 * V_56 )
{
struct V_57 * V_57 ;
int V_12 = 0 ;
unsigned long V_89 ;
F_30 ( & V_43 -> V_44 , V_89 ) ;
if ( V_43 -> V_85 == V_188 ) {
V_43 -> V_85 = V_86 ;
V_57 = V_43 -> V_49 -> V_84 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
V_57 -> V_72 = V_43 ;
V_12 = F_23 ( V_57 , V_20 ) ;
} else {
V_43 -> V_85 = V_86 ;
F_32 ( & V_43 -> V_44 , V_89 ) ;
}
return V_12 ;
}
static int F_25 ( struct V_3 * V_4 , V_75 V_223 ,
T_4 V_224 , T_4 V_225 , V_75 * V_93 , int V_195 )
{
int V_12 ;
V_12 = F_94 ( V_4 -> V_23 -> V_6 ,
F_95 ( V_4 -> V_23 -> V_6 , 0 ) , V_223 ,
( V_226 | V_227 | V_228 ) ,
V_225 , V_224 , V_93 , V_195 , 1000 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_85 ( struct V_3 * V_4 , V_75 V_223 ,
T_4 V_224 , T_4 V_225 , V_75 * V_93 , int V_195 )
{
int V_12 ;
V_12 = F_94 ( V_4 -> V_23 -> V_6 ,
F_96 ( V_4 -> V_23 -> V_6 , 0 ) , V_223 ,
( V_226 | V_227 | V_229 ) ,
V_225 , V_224 , V_93 , V_195 , 1000 ) ;
if ( V_12 == V_195 )
V_12 = 0 ;
else if ( V_12 >= 0 )
V_12 = - V_230 ;
return V_12 ;
}
static int F_67 ( struct V_40 * V_41 ,
struct V_3 * V_4 , unsigned long V_231 ,
T_2 V_232 , T_2 V_233 )
{
int V_12 ;
unsigned int V_195 ;
struct V_234 * V_93 ;
F_2 ( & V_41 -> V_6 , L_46 , V_13 ,
V_231 , V_232 , V_233 ) ;
V_195 = sizeof( struct V_234 ) + 2 ;
V_93 = F_51 ( V_195 , V_20 ) ;
if ( ! V_93 )
return - V_21 ;
V_93 -> V_235 = V_236 ;
V_93 -> V_237 = V_238 ;
V_93 -> V_239 = 1 ;
V_93 -> V_240 = F_62 ( V_231 >> 16 ) ;
V_93 -> V_241 = F_62 ( V_231 ) ;
V_93 -> V_242 [ 0 ] = V_232 ;
V_93 -> V_242 [ 1 ] = V_233 ;
V_12 = F_25 ( V_4 , V_243 , V_244 , 0 ,
( V_75 * ) V_93 , V_195 ) ;
if ( V_12 < 0 )
F_11 ( & V_41 -> V_6 , L_47 , V_13 , V_12 ) ;
F_12 ( V_93 ) ;
return V_12 ;
}
static int F_97 ( struct V_5 * V_6 , int V_83 ,
T_2 * V_245 , int V_195 )
{
int V_246 ;
T_2 V_247 = 0 ;
int V_248 ;
struct V_249 * V_250 ;
int V_12 = 0 ;
int V_251 ;
for ( V_246 = sizeof( struct V_249 ) ; V_246 < V_195 ; V_246 ++ )
V_247 = ( T_2 ) ( V_247 + V_245 [ V_246 ] ) ;
V_250 = (struct V_249 * ) V_245 ;
V_250 -> V_252 = F_98 ( V_195 - sizeof( * V_250 ) ) ;
V_250 -> V_253 = V_247 ;
F_2 ( & V_6 -> V_6 , L_48 , V_13 ) ;
for ( V_246 = 0 ; V_246 < V_195 ; V_246 += V_248 ) {
V_251 = F_99 ( V_195 - V_246 , V_254 ) ;
V_12 = F_100 ( V_6 , V_83 , V_245 + V_246 , V_251 ,
& V_248 , 1000 ) ;
if ( V_12 )
break;
}
return V_12 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_12 ;
int V_255 ;
T_2 * V_245 ;
struct V_5 * V_6 = V_4 -> V_23 -> V_6 ;
unsigned int V_83 = F_83 ( V_6 ,
V_4 -> V_23 -> V_41 [ 0 ] -> V_192 ) ;
const struct V_256 * V_257 ;
char V_258 [ 32 ] ;
if ( F_3 ( V_6 -> V_14 . V_26 ) == V_27 ) {
snprintf ( V_258 ,
sizeof( V_258 ) ,
L_49 ,
F_3 ( V_6 -> V_14 . V_15 ) ) ;
V_12 = F_101 ( & V_257 , V_258 , & V_6 -> V_6 ) ;
goto V_259;
}
sprintf ( V_258 , L_50 ,
F_3 ( V_6 -> V_14 . V_26 ) ,
F_3 ( V_6 -> V_14 . V_15 ) ) ;
V_12 = F_101 ( & V_257 , V_258 , & V_6 -> V_6 ) ;
if ( V_12 != 0 ) {
V_258 [ 0 ] = '\0' ;
if ( F_3 ( V_6 -> V_14 . V_26 ) == V_260 ) {
switch ( F_3 ( V_6 -> V_14 . V_15 ) ) {
case V_261 :
strcpy ( V_258 , L_51 ) ;
break;
case V_262 :
strcpy ( V_258 , L_52 ) ;
break;
case V_263 :
strcpy ( V_258 , L_53 ) ;
break;
case V_264 :
strcpy ( V_258 , L_54 ) ;
break;
case V_265 :
strcpy ( V_258 , L_55 ) ;
break;
case V_266 :
strcpy ( V_258 , L_55 ) ;
break; }
}
if ( V_258 [ 0 ] == '\0' ) {
if ( V_4 -> V_25 )
strcpy ( V_258 , L_56 ) ;
else
strcpy ( V_258 , L_57 ) ;
}
V_12 = F_101 ( & V_257 , V_258 , & V_6 -> V_6 ) ;
}
V_259:
if ( V_12 ) {
F_11 ( & V_6 -> V_6 , L_58 , V_13 ) ;
return - V_178 ;
}
if ( V_257 -> V_195 > V_267 ) {
F_11 ( & V_6 -> V_6 , L_59 , V_13 , V_257 -> V_195 ) ;
F_102 ( V_257 ) ;
return - V_178 ;
}
V_255 = V_267 + sizeof( struct V_249 ) ;
V_245 = F_51 ( V_255 , V_20 ) ;
if ( V_245 ) {
memcpy ( V_245 , V_257 -> V_93 , V_257 -> V_195 ) ;
memset ( V_245 + V_257 -> V_195 , 0xff , V_255 - V_257 -> V_195 ) ;
V_12 = F_97 ( V_6 , V_83 , V_245 , V_257 -> V_195 ) ;
F_12 ( V_245 ) ;
} else {
V_12 = - V_21 ;
}
F_102 ( V_257 ) ;
if ( V_12 ) {
F_11 ( & V_6 -> V_6 , L_60 ,
V_13 , V_12 ) ;
return V_12 ;
}
F_2 ( & V_6 -> V_6 , L_61 , V_13 ) ;
return 0 ;
}
