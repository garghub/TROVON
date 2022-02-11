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
return 0 ;
V_33:
F_11 ( V_4 ) ;
F_6 ( V_2 , NULL ) ;
return V_12 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_13 ( V_2 ) ;
F_11 ( V_4 ) ;
}
static int F_14 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_4 ( sizeof( * V_40 ) , V_20 ) ;
if ( ! V_40 )
return - V_21 ;
F_15 ( & V_40 -> V_41 ) ;
if ( V_38 == V_38 -> V_2 -> V_38 [ 0 ] )
V_40 -> V_42 = V_43 ;
else
V_40 -> V_42 = V_44 ;
V_38 -> V_38 . V_45 = F_16 ( 10 * V_45 ) ;
V_40 -> V_46 = V_38 ;
V_40 -> V_47 = F_13 ( V_38 -> V_2 ) ;
if ( V_40 -> V_47 -> V_30 )
V_40 -> V_48 = V_49 ;
else
V_40 -> V_48 = V_50 ;
F_17 ( V_38 , V_40 ) ;
V_38 -> V_38 . V_51 = 3 ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_19 ( V_38 ) ;
F_11 ( V_40 ) ;
return 0 ;
}
static int F_20 ( struct V_52 * V_53 , struct V_37 * V_38 )
{
struct V_39 * V_40 = F_19 ( V_38 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_54 * V_54 ;
int V_55 ;
int V_12 ;
T_2 V_56 = ( V_57 ) ( V_58 |
V_59 |
( V_60 << 2 ) ) ;
if ( V_40 == NULL )
return - V_34 ;
V_6 = V_38 -> V_2 -> V_6 ;
V_4 = V_40 -> V_47 ;
if ( F_21 ( & V_4 -> V_22 ) )
return - V_61 ;
V_55 = V_38 -> V_55 ;
V_40 -> V_62 = 0 ;
V_40 -> V_63 |= ( V_64 | V_65 ) ;
if ( V_4 -> V_66 == 0 ) {
F_2 ( & V_38 -> V_6 , L_5 , V_13 ) ;
V_54 = V_4 -> V_23 -> V_38 [ 0 ] -> V_67 ;
if ( ! V_54 ) {
F_22 ( & V_38 -> V_6 , L_6 , V_13 ) ;
V_12 = - V_68 ;
goto V_69;
}
V_54 -> V_70 = V_4 ;
V_12 = F_23 ( V_54 , V_20 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_7 , V_13 , V_12 ) ;
goto V_69;
}
}
if ( V_53 )
F_24 ( V_53 , V_38 , & V_53 -> V_71 ) ;
F_2 ( & V_38 -> V_6 , L_8 , V_13 ) ;
V_12 = F_25 ( V_4 , V_72 ,
( V_57 ) ( V_73 + V_55 ) , V_56 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_9 ,
V_13 , V_12 ) ;
goto V_74;
}
F_2 ( & V_38 -> V_6 , L_10 , V_13 ) ;
V_12 = F_25 ( V_4 , V_75 ,
( V_57 ) ( V_73 + V_55 ) , 0 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_11 ,
V_13 , V_12 ) ;
goto V_74;
}
F_2 ( & V_38 -> V_6 , L_12 , V_13 ) ;
V_12 = F_25 ( V_4 , V_76 ,
( V_57 ) ( V_73 + V_55 ) , V_77 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_13 ,
V_13 , V_12 ) ;
goto V_74;
}
V_12 = F_25 ( V_4 , V_76 ,
( V_57 ) ( V_73 + V_55 ) , V_78 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_14 ,
V_13 , V_12 ) ;
goto V_74;
}
F_26 ( V_6 , V_38 -> V_79 -> V_80 ) ;
F_26 ( V_6 , V_38 -> V_81 -> V_80 ) ;
if ( V_53 )
F_24 ( V_53 , V_38 , & V_53 -> V_71 ) ;
F_2 ( & V_38 -> V_6 , L_15 , V_13 ) ;
V_12 = F_25 ( V_4 , V_72 ,
( V_57 ) ( V_73 + V_55 ) , V_56 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_16 ,
V_13 , V_12 ) ;
goto V_74;
}
F_2 ( & V_38 -> V_6 , L_17 , V_13 ) ;
V_12 = F_25 ( V_4 , V_75 ,
( V_57 ) ( V_73 + V_55 ) , 0 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_18 ,
V_13 , V_12 ) ;
goto V_74;
}
F_2 ( & V_38 -> V_6 , L_19 , V_13 ) ;
V_54 = V_38 -> V_81 ;
if ( ! V_54 ) {
F_22 ( & V_38 -> V_6 , L_20 , V_13 ) ;
V_12 = - V_68 ;
goto V_74;
}
V_40 -> V_82 = V_83 ;
V_54 -> V_70 = V_40 ;
V_12 = F_23 ( V_54 , V_20 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_21 ,
V_13 , V_12 ) ;
goto V_74;
}
V_40 -> V_84 = 1 ;
++ V_4 -> V_66 ;
goto V_69;
V_74:
if ( V_4 -> V_66 == 0 )
F_27 ( V_38 -> V_2 -> V_38 [ 0 ] -> V_67 ) ;
V_69:
F_28 ( & V_4 -> V_22 ) ;
F_2 ( & V_38 -> V_6 , L_22 , V_13 , V_12 ) ;
return V_12 ;
}
static void F_29 ( struct V_37 * V_38 )
{
struct V_3 * V_4 ;
struct V_39 * V_40 ;
int V_55 ;
int V_12 ;
int V_85 ;
unsigned long V_86 ;
V_4 = F_13 ( V_38 -> V_2 ) ;
V_40 = F_19 ( V_38 ) ;
if ( V_4 == NULL || V_40 == NULL )
return;
V_40 -> V_84 = 0 ;
F_27 ( V_38 -> V_81 ) ;
F_27 ( V_38 -> V_79 ) ;
V_40 -> V_87 = 0 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
F_31 ( & V_38 -> V_88 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
V_55 = V_38 -> V_55 ;
F_2 ( & V_38 -> V_6 , L_23 , V_13 ) ;
V_12 = F_25 ( V_4 , V_89 ,
( V_57 ) ( V_73 + V_55 ) , 0 , NULL , 0 ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 ,
L_24
, V_13 , V_12 ) ;
V_85 = ! F_21 ( & V_4 -> V_22 ) ;
-- V_40 -> V_47 -> V_66 ;
if ( V_40 -> V_47 -> V_66 <= 0 ) {
F_27 ( V_38 -> V_2 -> V_38 [ 0 ] -> V_67 ) ;
V_40 -> V_47 -> V_66 = 0 ;
}
if ( V_85 )
F_28 ( & V_4 -> V_22 ) ;
}
static int F_33 ( struct V_52 * V_53 , struct V_37 * V_38 ,
const unsigned char * V_90 , int V_91 )
{
struct V_39 * V_40 = F_19 ( V_38 ) ;
if ( V_91 == 0 ) {
F_2 ( & V_38 -> V_6 , L_25 , V_13 ) ;
return 0 ;
}
if ( V_40 == NULL || ! V_40 -> V_84 )
return - V_34 ;
V_91 = F_34 ( & V_38 -> V_88 , V_90 , V_91 ,
& V_40 -> V_41 ) ;
F_35 ( V_40 ) ;
return V_91 ;
}
static int F_36 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_93 = 0 ;
unsigned long V_86 ;
if ( V_40 == NULL )
return 0 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_93 = F_37 ( & V_38 -> V_88 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
F_2 ( & V_38 -> V_6 , L_26 , V_13 , V_93 ) ;
return V_93 ;
}
static int F_38 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_94 = 0 ;
unsigned long V_86 ;
if ( V_40 == NULL )
return 0 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_94 = F_39 ( & V_38 -> V_88 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
F_2 ( & V_38 -> V_6 , L_26 , V_13 , V_94 ) ;
return V_94 ;
}
static bool F_40 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_95 ;
T_3 V_96 ;
V_95 = F_41 ( V_40 , & V_96 ) ;
if ( ! V_95 && ! ( V_96 & V_97 ) )
return false ;
return true ;
}
static void F_42 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
if ( V_40 == NULL )
return;
if ( F_43 ( V_53 ) || F_44 ( V_53 ) )
F_45 ( V_40 , V_53 ) ;
}
static void F_46 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_12 ;
if ( V_40 == NULL )
return;
if ( F_43 ( V_53 ) || F_44 ( V_53 ) ) {
V_12 = F_47 ( V_40 , V_53 ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 , L_27 ,
V_13 , V_12 ) ;
}
}
static int F_48 ( struct V_52 * V_53 ,
unsigned int V_98 , unsigned long V_99 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
if ( V_40 == NULL )
return - V_34 ;
switch ( V_98 ) {
case V_100 :
F_2 ( & V_38 -> V_6 , L_28 , V_13 ) ;
return F_49 ( V_40 ,
(struct V_101 V_102 * ) V_99 ) ;
case V_103 :
F_2 ( & V_38 -> V_6 , L_29 , V_13 ) ;
return F_50 ( V_53 , V_40 ,
(struct V_101 V_102 * ) V_99 ) ;
}
return - V_104 ;
}
static void F_24 ( struct V_52 * V_53 ,
struct V_37 * V_38 , struct V_105 * V_106 )
{
struct V_39 * V_40 = F_19 ( V_38 ) ;
struct V_107 * V_108 ;
T_4 V_109 , V_110 ;
int V_111 ;
int V_12 ;
int V_55 = V_38 -> V_55 ;
unsigned int V_112 ;
V_109 = V_53 -> V_71 . V_113 ;
V_110 = V_53 -> V_71 . V_114 ;
F_2 ( & V_38 -> V_6 , L_30 , V_13 , V_109 , V_110 ) ;
F_2 ( & V_38 -> V_6 , L_31 , V_13 ,
V_106 -> V_113 , V_106 -> V_114 ) ;
if ( V_40 == NULL )
return;
V_108 = F_51 ( sizeof( * V_108 ) , V_20 ) ;
if ( ! V_108 )
return;
V_108 -> V_115 = 0 ;
V_108 -> V_115 |= V_116 ;
V_108 -> V_115 |= V_117 ;
V_108 -> V_118 = ( V_57 ) ( V_40 -> V_48 ) ;
switch ( V_109 & V_119 ) {
case V_120 :
V_108 -> V_121 = V_122 ;
break;
case V_123 :
V_108 -> V_121 = V_124 ;
break;
case V_125 :
V_108 -> V_121 = V_126 ;
break;
default:
case V_127 :
V_108 -> V_121 = V_128 ;
break;
}
V_53 -> V_71 . V_113 &= ~ V_129 ;
if ( V_109 & V_130 ) {
if ( V_109 & V_131 ) {
V_108 -> V_115 |= V_132 ;
V_108 -> V_133 = V_134 ;
} else {
V_108 -> V_115 |= V_132 ;
V_108 -> V_133 = V_135 ;
}
} else {
V_108 -> V_115 &= ~ V_132 ;
V_108 -> V_133 = V_136 ;
}
if ( V_109 & V_137 )
V_108 -> V_138 = V_139 ;
else
V_108 -> V_138 = V_140 ;
if ( V_109 & V_141 ) {
if ( ( V_109 & V_142 ) != V_143 )
V_108 -> V_115 |= V_144 ;
V_108 -> V_115 |= V_145 ;
} else {
F_47 ( V_40 , V_53 ) ;
}
if ( F_43 ( V_53 ) || F_52 ( V_53 ) ) {
V_108 -> V_146 = F_53 ( V_53 ) ;
V_108 -> V_147 = F_54 ( V_53 ) ;
if ( F_43 ( V_53 ) )
V_108 -> V_115 |= V_148 ;
else
F_47 ( V_40 , V_53 ) ;
if ( F_52 ( V_53 ) )
V_108 -> V_115 |= V_149 ;
}
V_111 = F_55 ( V_53 ) ;
if ( ! V_111 )
V_111 = 9600 ;
if ( V_40 -> V_47 -> V_25 )
V_108 -> V_150 = ( T_2 ) ( ( 923077 + V_111 / 2 ) / V_111 ) ;
else
V_108 -> V_150 = ( T_2 ) ( ( 461538 + V_111 / 2 ) / V_111 ) ;
if ( ( V_109 & V_142 ) != V_143 )
F_56 ( V_53 , V_111 , V_111 ) ;
F_2 ( & V_38 -> V_6 ,
L_32 ,
V_13 , V_111 , V_108 -> V_150 , V_108 -> V_115 ,
V_108 -> V_121 , V_108 -> V_133 , V_108 -> V_138 ,
V_108 -> V_146 , V_108 -> V_147 , V_108 -> V_118 ) ;
F_57 ( & V_108 -> V_150 ) ;
F_57 ( & V_108 -> V_115 ) ;
V_12 = F_25 ( V_40 -> V_47 , V_151 ,
( V_57 ) ( V_73 + V_55 ) , 0 , ( V_57 * ) V_108 ,
sizeof( * V_108 ) ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 , L_33 ,
V_13 , V_55 , V_12 ) ;
V_112 = V_40 -> V_63 ;
if ( ( V_109 & V_142 ) == V_143 )
V_112 &= ~ ( V_65 | V_64 ) ;
V_12 = F_58 ( V_40 , V_112 ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 ,
L_34 ,
V_13 , V_55 , V_12 ) ;
F_11 ( V_108 ) ;
}
static int F_59 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
unsigned int V_152 ;
unsigned int V_153 ;
unsigned int V_112 ;
unsigned long V_86 ;
if ( V_40 == NULL )
return - V_34 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_153 = V_40 -> V_62 ;
V_112 = V_40 -> V_63 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
V_152 = ( ( V_112 & V_65 ) ? V_154 : 0 )
| ( ( V_112 & V_64 ) ? V_155 : 0 )
| ( ( V_112 & V_156 ) ? V_157 : 0 )
| ( ( V_153 & V_158 ) ? V_159 : 0 )
| ( ( V_153 & V_160 ) ? V_161 : 0 )
| ( ( V_153 & V_162 ) ? V_163 : 0 )
| ( ( V_153 & V_164 ) ? V_165 : 0 ) ;
F_2 ( & V_38 -> V_6 , L_35 , V_13 , V_152 ) ;
return V_152 ;
}
static int F_60 ( struct V_52 * V_53 ,
unsigned int V_166 , unsigned int V_167 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
unsigned int V_112 ;
unsigned long V_86 ;
if ( V_40 == NULL )
return - V_34 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_112 = V_40 -> V_63 ;
if ( V_166 & V_155 )
V_112 |= V_64 ;
if ( V_166 & V_154 )
V_112 |= V_65 ;
if ( V_166 & V_157 )
V_112 |= V_156 ;
if ( V_167 & V_155 )
V_112 &= ~ V_64 ;
if ( V_167 & V_154 )
V_112 &= ~ V_65 ;
if ( V_167 & V_157 )
V_112 &= ~ V_156 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
return F_58 ( V_40 , V_112 ) ;
}
static void F_61 ( struct V_52 * V_53 , int V_168 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_12 ;
F_2 ( & V_38 -> V_6 , L_36 , V_13 , V_168 ) ;
if ( V_40 == NULL )
return;
V_12 = F_62 ( V_38 , V_40 -> V_47 ,
V_40 -> V_42 + V_169 ,
V_170 , V_168 == - 1 ? V_170 : 0 ) ;
if ( V_12 )
F_2 ( & V_38 -> V_6 , L_37 , V_13 , V_12 ) ;
}
static void F_63 ( struct V_54 * V_54 )
{
struct V_3 * V_4 = V_54 -> V_70 ;
struct V_37 * V_38 ;
struct V_1 * V_2 = V_4 -> V_23 ;
struct V_39 * V_40 ;
struct V_171 * V_6 = & V_54 -> V_6 -> V_6 ;
unsigned char * V_90 = V_54 -> V_172 ;
int V_173 = V_54 -> V_174 ;
int V_55 ;
int V_175 ;
int V_12 = V_54 -> V_12 ;
int V_176 ;
V_57 V_153 ;
switch ( V_12 ) {
case 0 :
break;
case - V_177 :
case - V_178 :
case - V_179 :
F_2 ( V_6 , L_38 , V_13 , V_12 ) ;
V_4 -> V_180 = 1 ;
return;
default:
F_22 ( V_6 , L_39 , V_13 , V_12 ) ;
V_4 -> V_180 = 1 ;
goto exit;
}
if ( V_173 != 2 ) {
F_2 ( V_6 , L_40 , V_13 , V_173 ) ;
goto exit;
}
if ( V_90 [ 0 ] == V_181 ) {
F_22 ( V_6 , L_41 , V_13 , V_90 [ 1 ] ) ;
goto exit;
}
V_55 = F_64 ( V_90 [ 0 ] ) ;
V_175 = F_65 ( V_90 [ 0 ] ) ;
F_2 ( V_6 , L_42 ,
V_13 , V_55 , V_175 , V_90 [ 1 ] ) ;
if ( V_55 >= V_2 -> V_182 ) {
F_22 ( V_6 , L_43 ,
V_13 , V_55 ) ;
goto exit;
}
V_38 = V_2 -> V_38 [ V_55 ] ;
V_40 = F_19 ( V_38 ) ;
if ( ! V_40 )
goto exit;
switch ( V_175 ) {
case V_183 :
F_22 ( V_6 , L_44 ,
V_13 , V_55 , V_90 [ 1 ] ) ;
break;
case V_184 :
V_153 = V_90 [ 1 ] ;
F_2 ( V_6 , L_45 , V_13 , V_55 , V_153 ) ;
F_66 ( V_40 , V_153 ) ;
break;
default:
F_22 ( V_6 , L_46 ,
V_13 , V_90 [ 1 ] ) ;
break;
}
exit:
V_176 = F_23 ( V_54 , V_185 ) ;
if ( V_176 )
F_22 ( V_6 , L_47 ,
V_13 , V_176 ) ;
}
static void F_67 ( struct V_54 * V_54 )
{
struct V_39 * V_40 = V_54 -> V_70 ;
struct V_37 * V_38 = V_40 -> V_46 ;
struct V_171 * V_6 = & V_54 -> V_6 -> V_6 ;
int V_12 = V_54 -> V_12 ;
int V_176 = 0 ;
switch ( V_12 ) {
case 0 :
break;
case - V_177 :
case - V_178 :
case - V_179 :
F_2 ( V_6 , L_38 , V_13 , V_12 ) ;
V_40 -> V_47 -> V_180 = 1 ;
return;
default:
F_22 ( V_6 , L_39 ,
V_13 , V_12 ) ;
V_40 -> V_47 -> V_180 = 1 ;
}
if ( V_12 == - V_186 )
goto exit;
if ( V_12 ) {
F_22 ( V_6 , L_48 , V_13 ) ;
return;
}
if ( V_54 -> V_174 ) {
F_68 ( V_6 , V_13 , V_54 -> V_174 ,
V_54 -> V_172 ) ;
if ( ! V_40 -> V_84 )
F_2 ( V_6 , L_49 ,
V_13 ) ;
else
F_69 ( V_38 , V_54 -> V_172 , V_54 -> V_174 ) ;
F_70 ( & V_40 -> V_41 ) ;
V_38 -> V_187 . V_188 += V_54 -> V_174 ;
F_71 ( & V_40 -> V_41 ) ;
}
exit:
F_70 ( & V_40 -> V_41 ) ;
if ( V_40 -> V_82 == V_83 )
V_176 = F_23 ( V_54 , V_185 ) ;
else if ( V_40 -> V_82 == V_189 )
V_40 -> V_82 = V_190 ;
F_71 ( & V_40 -> V_41 ) ;
if ( V_176 )
F_22 ( V_6 , L_50 ,
V_13 , V_176 ) ;
}
static void F_72 ( struct V_54 * V_54 )
{
struct V_39 * V_40 = V_54 -> V_70 ;
struct V_37 * V_38 = V_40 -> V_46 ;
int V_12 = V_54 -> V_12 ;
V_40 -> V_87 = 0 ;
switch ( V_12 ) {
case 0 :
break;
case - V_177 :
case - V_178 :
case - V_179 :
F_2 ( & V_38 -> V_6 , L_38 , V_13 , V_12 ) ;
V_40 -> V_47 -> V_180 = 1 ;
return;
default:
F_73 ( V_38 , L_39 ,
V_13 , V_12 ) ;
V_40 -> V_47 -> V_180 = 1 ;
}
F_35 ( V_40 ) ;
}
static void F_69 ( struct V_37 * V_38 , unsigned char * V_90 ,
int V_173 )
{
int V_191 ;
do {
V_191 = F_74 ( & V_38 -> V_38 , V_90 , V_173 ) ;
if ( V_191 < V_173 ) {
F_22 ( & V_38 -> V_6 , L_51 ,
V_13 , V_173 - V_191 ) ;
if ( V_191 == 0 )
break;
}
F_75 ( & V_38 -> V_38 ) ;
V_90 += V_191 ;
V_173 -= V_191 ;
} while ( V_173 > 0 );
}
static void F_35 ( struct V_39 * V_40 )
{
int V_91 , V_152 ;
struct V_37 * V_38 = V_40 -> V_46 ;
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( V_40 -> V_87 )
goto V_192;
V_91 = F_76 ( & V_38 -> V_88 ,
V_38 -> V_79 -> V_172 ,
V_38 -> V_193 ) ;
if ( V_91 == 0 )
goto V_192;
V_40 -> V_87 = 1 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
F_68 ( & V_38 -> V_6 , V_13 , V_91 ,
V_38 -> V_79 -> V_172 ) ;
F_77 ( V_38 -> V_79 , V_38 -> V_2 -> V_6 ,
F_78 ( V_38 -> V_2 -> V_6 ,
V_38 -> V_194 ) ,
V_38 -> V_79 -> V_172 , V_91 ,
F_72 , V_40 ) ;
V_152 = F_23 ( V_38 -> V_79 , V_185 ) ;
if ( V_152 ) {
F_73 ( V_38 , L_52 ,
V_13 , V_152 ) ;
V_40 -> V_87 = 0 ;
} else {
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_38 -> V_187 . V_195 += V_91 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
F_79 ( & V_38 -> V_38 ) ;
return;
V_192:
F_32 ( & V_40 -> V_41 , V_86 ) ;
return;
}
static int F_58 ( struct V_39 * V_40 , unsigned int V_112 )
{
unsigned long V_86 ;
int V_12 ;
V_12 = F_62 ( V_40 -> V_46 , V_40 -> V_47 ,
V_40 -> V_42 + V_196 ,
V_64 | V_65 | V_156 , V_112 ) ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( ! V_12 )
V_40 -> V_63 = V_112 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
return V_12 ;
}
static int F_41 ( struct V_39 * V_40 , T_3 * V_96 )
{
int V_197 , V_12 ;
struct V_3 * V_4 = V_40 -> V_47 ;
struct V_37 * V_38 = V_40 -> V_46 ;
int V_55 = V_38 -> V_55 ;
struct V_198 * V_90 ;
V_197 = sizeof( struct V_198 ) ;
V_90 = F_51 ( V_197 , V_20 ) ;
if ( ! V_90 )
return - V_21 ;
V_12 = F_80 ( V_4 , V_199 ,
( V_57 ) ( V_73 + V_55 ) , 0 , ( V_57 * ) V_90 , V_197 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 ,
L_53 ,
V_13 , V_12 ) ;
goto V_200;
}
F_2 ( & V_38 -> V_6 , L_54 , V_13 , V_90 -> V_201 ) ;
* V_96 = V_90 -> V_201 ;
V_200:
F_11 ( V_90 ) ;
return V_12 ;
}
static int F_49 ( struct V_39 * V_40 ,
struct V_101 V_102 * V_202 )
{
struct V_37 * V_38 = V_40 -> V_46 ;
struct V_101 V_203 ;
unsigned V_204 ;
if ( ! V_202 )
return - V_205 ;
V_204 = V_38 -> V_38 . V_45 ;
if ( V_204 != V_206 )
V_204 = F_81 ( V_204 ) / 10 ;
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_203 . type = V_207 ;
V_203 . line = V_38 -> V_208 ;
V_203 . V_38 = V_38 -> V_55 ;
V_203 . V_86 = V_40 -> V_209 ;
V_203 . V_210 = F_82 ( & V_38 -> V_88 ) ;
V_203 . V_211 = V_40 -> V_47 -> V_25 ? 921600 : 460800 ;
V_203 . V_45 = V_204 ;
if ( F_83 ( V_202 , & V_203 , sizeof( * V_202 ) ) )
return - V_205 ;
return 0 ;
}
static int F_50 ( struct V_52 * V_53 , struct V_39 * V_40 ,
struct V_101 V_102 * V_212 )
{
struct V_101 V_213 ;
unsigned V_204 ;
if ( F_84 ( & V_213 , V_212 , sizeof( V_213 ) ) )
return - V_205 ;
V_204 = V_213 . V_45 ;
if ( V_204 != V_206 )
V_204 = F_16 ( 10 * V_213 . V_45 ) ;
V_40 -> V_209 = V_213 . V_86 & V_214 ;
V_40 -> V_46 -> V_38 . V_45 = V_204 ;
return 0 ;
}
static void F_66 ( struct V_39 * V_40 , V_57 V_153 )
{
struct V_215 * V_187 ;
struct V_52 * V_53 ;
unsigned long V_86 ;
F_2 ( & V_40 -> V_46 -> V_6 , L_55 , V_13 , V_153 ) ;
if ( V_153 & V_216 ) {
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_187 = & V_40 -> V_46 -> V_187 ;
if ( V_153 & V_217 )
V_187 -> V_218 ++ ;
if ( V_153 & V_219 )
V_187 -> V_220 ++ ;
if ( V_153 & V_221 )
V_187 -> V_222 ++ ;
if ( V_153 & V_223 )
V_187 -> V_224 ++ ;
F_85 ( & V_40 -> V_46 -> V_38 . V_225 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
V_40 -> V_62 = V_153 & V_226 ;
V_53 = F_86 ( & V_40 -> V_46 -> V_38 ) ;
if ( V_53 && F_44 ( V_53 ) ) {
if ( V_153 & V_158 )
F_87 ( V_53 ) ;
}
F_88 ( V_53 ) ;
}
static void F_45 ( struct V_39 * V_40 , struct V_52 * V_53 )
{
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( V_40 -> V_82 == V_83 )
V_40 -> V_82 = V_189 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
static int F_47 ( struct V_39 * V_40 , struct V_52 * V_53 )
{
struct V_54 * V_54 ;
int V_12 = 0 ;
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( V_40 -> V_82 == V_190 ) {
V_40 -> V_82 = V_83 ;
V_54 = V_40 -> V_46 -> V_81 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
V_54 -> V_70 = V_40 ;
V_12 = F_23 ( V_54 , V_20 ) ;
} else {
V_40 -> V_82 = V_83 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
return V_12 ;
}
static int F_25 ( struct V_3 * V_4 , V_57 V_227 ,
T_2 V_228 , T_2 V_229 , V_57 * V_90 , int V_197 )
{
int V_12 ;
V_12 = F_89 ( V_4 -> V_23 -> V_6 ,
F_90 ( V_4 -> V_23 -> V_6 , 0 ) , V_227 ,
( V_230 | V_231 | V_232 ) ,
V_229 , V_228 , V_90 , V_197 , 1000 ) ;
if ( V_12 == V_197 )
V_12 = 0 ;
if ( V_12 > 0 )
V_12 = - V_233 ;
return V_12 ;
}
static int F_80 ( struct V_3 * V_4 , V_57 V_227 ,
T_2 V_228 , T_2 V_229 , V_57 * V_90 , int V_197 )
{
int V_12 ;
V_12 = F_89 ( V_4 -> V_23 -> V_6 ,
F_91 ( V_4 -> V_23 -> V_6 , 0 ) , V_227 ,
( V_230 | V_231 | V_234 ) ,
V_229 , V_228 , V_90 , V_197 , 1000 ) ;
if ( V_12 == V_197 )
V_12 = 0 ;
if ( V_12 > 0 )
V_12 = - V_233 ;
return V_12 ;
}
static int F_62 ( struct V_37 * V_38 ,
struct V_3 * V_4 , unsigned long V_235 ,
V_57 V_236 , V_57 V_237 )
{
int V_12 ;
unsigned int V_197 ;
struct V_238 * V_90 ;
F_2 ( & V_38 -> V_6 , L_56 , V_13 ,
V_235 , V_236 , V_237 ) ;
V_197 = sizeof( struct V_238 ) + 2 ;
V_90 = F_51 ( V_197 , V_20 ) ;
if ( ! V_90 )
return - V_21 ;
V_90 -> V_239 = V_240 ;
V_90 -> V_241 = V_242 ;
V_90 -> V_243 = 1 ;
V_90 -> V_244 = F_92 ( V_235 >> 16 ) ;
V_90 -> V_245 = F_92 ( V_235 ) ;
V_90 -> V_246 [ 0 ] = V_236 ;
V_90 -> V_246 [ 1 ] = V_237 ;
V_12 = F_25 ( V_4 , V_247 , V_248 , 0 ,
( V_57 * ) V_90 , V_197 ) ;
if ( V_12 < 0 )
F_22 ( & V_38 -> V_6 , L_57 , V_13 , V_12 ) ;
F_11 ( V_90 ) ;
return V_12 ;
}
static int F_93 ( struct V_5 * V_6 , int V_80 ,
T_3 * V_249 , int V_197 )
{
int V_250 ;
T_3 V_251 = 0 ;
int V_252 ;
struct V_253 * V_254 ;
int V_12 = 0 ;
int V_255 ;
for ( V_250 = sizeof( struct V_253 ) ; V_250 < V_197 ; V_250 ++ )
V_251 = ( V_57 ) ( V_251 + V_249 [ V_250 ] ) ;
V_254 = (struct V_253 * ) V_249 ;
V_254 -> V_256 = F_94 ( ( T_2 ) ( V_197
- sizeof( struct V_253 ) ) ) ;
V_254 -> V_257 = V_251 ;
F_2 ( & V_6 -> V_6 , L_58 , V_13 ) ;
for ( V_250 = 0 ; V_250 < V_197 ; V_250 += V_252 ) {
V_255 = F_95 ( V_197 - V_250 , V_258 ) ;
V_12 = F_96 ( V_6 , V_80 , V_249 + V_250 , V_255 ,
& V_252 , 1000 ) ;
if ( V_12 )
break;
}
return V_12 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_12 ;
int V_259 ;
V_57 * V_249 ;
struct V_5 * V_6 = V_4 -> V_23 -> V_6 ;
unsigned int V_80 = F_78 ( V_6 ,
V_4 -> V_23 -> V_38 [ 0 ] -> V_194 ) ;
const struct V_260 * V_261 ;
char V_262 [ 32 ] ;
if ( F_3 ( V_6 -> V_14 . V_26 ) == V_27 ) {
snprintf ( V_262 ,
sizeof( V_262 ) ,
L_59 ,
F_3 ( V_6 -> V_14 . V_15 ) ) ;
V_12 = F_97 ( & V_261 , V_262 , & V_6 -> V_6 ) ;
goto V_263;
}
sprintf ( V_262 , L_60 ,
F_3 ( V_6 -> V_14 . V_26 ) ,
F_3 ( V_6 -> V_14 . V_15 ) ) ;
V_12 = F_97 ( & V_261 , V_262 , & V_6 -> V_6 ) ;
if ( V_12 != 0 ) {
V_262 [ 0 ] = '\0' ;
if ( F_3 ( V_6 -> V_14 . V_26 ) == V_264 ) {
switch ( F_3 ( V_6 -> V_14 . V_15 ) ) {
case V_265 :
strcpy ( V_262 , L_61 ) ;
break;
case V_266 :
strcpy ( V_262 , L_62 ) ;
break;
case V_267 :
strcpy ( V_262 , L_63 ) ;
break;
case V_268 :
strcpy ( V_262 , L_64 ) ;
break;
case V_269 :
strcpy ( V_262 , L_65 ) ;
break;
case V_270 :
strcpy ( V_262 , L_65 ) ;
break; }
}
if ( V_262 [ 0 ] == '\0' ) {
if ( V_4 -> V_25 )
strcpy ( V_262 , L_66 ) ;
else
strcpy ( V_262 , L_67 ) ;
}
V_12 = F_97 ( & V_261 , V_262 , & V_6 -> V_6 ) ;
}
V_263:
if ( V_12 ) {
F_22 ( & V_6 -> V_6 , L_68 , V_13 ) ;
return - V_178 ;
}
if ( V_261 -> V_197 > V_271 ) {
F_22 ( & V_6 -> V_6 , L_69 , V_13 , V_261 -> V_197 ) ;
F_98 ( V_261 ) ;
return - V_178 ;
}
V_259 = V_271 + sizeof( struct V_253 ) ;
V_249 = F_51 ( V_259 , V_20 ) ;
if ( V_249 ) {
memcpy ( V_249 , V_261 -> V_90 , V_261 -> V_197 ) ;
memset ( V_249 + V_261 -> V_197 , 0xff , V_259 - V_261 -> V_197 ) ;
V_12 = F_93 ( V_6 , V_80 , V_249 , V_261 -> V_197 ) ;
F_11 ( V_249 ) ;
} else {
V_12 = - V_21 ;
}
F_98 ( V_261 ) ;
if ( V_12 ) {
F_22 ( & V_6 -> V_6 , L_70 ,
V_13 , V_12 ) ;
return V_12 ;
}
F_2 ( & V_6 -> V_6 , L_71 , V_13 ) ;
return 0 ;
}
