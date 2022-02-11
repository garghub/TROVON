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
T_1 V_56 ;
V_56 = ( V_57 |
V_58 |
( V_59 << 2 ) ) ;
V_6 = V_38 -> V_2 -> V_6 ;
V_4 = V_40 -> V_47 ;
if ( F_21 ( & V_4 -> V_22 ) )
return - V_60 ;
V_55 = V_38 -> V_55 ;
V_40 -> V_61 = 0 ;
V_40 -> V_62 |= ( V_63 | V_64 ) ;
if ( V_4 -> V_65 == 0 ) {
F_2 ( & V_38 -> V_6 , L_5 , V_13 ) ;
V_54 = V_4 -> V_23 -> V_38 [ 0 ] -> V_66 ;
if ( ! V_54 ) {
F_22 ( & V_38 -> V_6 , L_6 , V_13 ) ;
V_12 = - V_67 ;
goto V_68;
}
V_54 -> V_69 = V_4 ;
V_12 = F_23 ( V_54 , V_20 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_7 , V_13 , V_12 ) ;
goto V_68;
}
}
if ( V_53 )
F_24 ( V_53 , V_38 , & V_53 -> V_70 ) ;
V_12 = F_25 ( V_4 , V_71 ,
( V_72 ) ( V_73 + V_55 ) , V_56 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_8 ,
V_13 , V_12 ) ;
goto V_74;
}
V_12 = F_25 ( V_4 , V_75 ,
( V_72 ) ( V_73 + V_55 ) , 0 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_9 ,
V_13 , V_12 ) ;
goto V_74;
}
V_12 = F_25 ( V_4 , V_76 ,
( V_72 ) ( V_73 + V_55 ) , V_77 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_10 ,
V_13 , V_12 ) ;
goto V_74;
}
V_12 = F_25 ( V_4 , V_76 ,
( V_72 ) ( V_73 + V_55 ) , V_78 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_11 ,
V_13 , V_12 ) ;
goto V_74;
}
F_26 ( V_6 , V_38 -> V_79 -> V_80 ) ;
F_26 ( V_6 , V_38 -> V_81 -> V_80 ) ;
if ( V_53 )
F_24 ( V_53 , V_38 , & V_53 -> V_70 ) ;
V_12 = F_25 ( V_4 , V_71 ,
( V_72 ) ( V_73 + V_55 ) , V_56 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_12 ,
V_13 , V_12 ) ;
goto V_74;
}
V_12 = F_25 ( V_4 , V_75 ,
( V_72 ) ( V_73 + V_55 ) , 0 , NULL , 0 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_13 ,
V_13 , V_12 ) ;
goto V_74;
}
V_54 = V_38 -> V_81 ;
if ( ! V_54 ) {
F_22 ( & V_38 -> V_6 , L_14 , V_13 ) ;
V_12 = - V_67 ;
goto V_74;
}
V_40 -> V_82 = V_83 ;
V_54 -> V_69 = V_40 ;
V_12 = F_23 ( V_54 , V_20 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 , L_15 ,
V_13 , V_12 ) ;
goto V_74;
}
V_40 -> V_84 = 1 ;
++ V_4 -> V_65 ;
goto V_68;
V_74:
if ( V_4 -> V_65 == 0 )
F_27 ( V_38 -> V_2 -> V_38 [ 0 ] -> V_66 ) ;
V_68:
F_28 ( & V_4 -> V_22 ) ;
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
V_40 -> V_84 = 0 ;
F_27 ( V_38 -> V_81 ) ;
F_27 ( V_38 -> V_79 ) ;
V_40 -> V_87 = 0 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
F_31 ( & V_38 -> V_88 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
V_55 = V_38 -> V_55 ;
V_12 = F_25 ( V_4 , V_89 ,
( V_72 ) ( V_73 + V_55 ) , 0 , NULL , 0 ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 ,
L_16
, V_13 , V_12 ) ;
V_85 = ! F_21 ( & V_4 -> V_22 ) ;
-- V_40 -> V_47 -> V_65 ;
if ( V_40 -> V_47 -> V_65 <= 0 ) {
F_27 ( V_38 -> V_2 -> V_38 [ 0 ] -> V_66 ) ;
V_40 -> V_47 -> V_65 = 0 ;
}
if ( V_85 )
F_28 ( & V_4 -> V_22 ) ;
}
static int F_33 ( struct V_52 * V_53 , struct V_37 * V_38 ,
const unsigned char * V_90 , int V_91 )
{
struct V_39 * V_40 = F_19 ( V_38 ) ;
if ( V_91 == 0 ) {
return 0 ;
}
if ( ! V_40 -> V_84 )
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
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_93 = F_37 ( & V_38 -> V_88 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
F_2 ( & V_38 -> V_6 , L_17 , V_13 , V_93 ) ;
return V_93 ;
}
static int F_38 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_94 = 0 ;
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_94 = F_39 ( & V_38 -> V_88 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
F_2 ( & V_38 -> V_6 , L_17 , V_13 , V_94 ) ;
return V_94 ;
}
static bool F_40 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_95 ;
T_2 V_96 ;
V_95 = F_41 ( V_40 , & V_96 ) ;
if ( ! V_95 && ! ( V_96 & V_97 ) )
return false ;
return true ;
}
static void F_42 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
if ( F_43 ( V_53 ) || F_44 ( V_53 ) )
F_45 ( V_40 , V_53 ) ;
}
static void F_46 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_12 ;
if ( F_43 ( V_53 ) || F_44 ( V_53 ) ) {
V_12 = F_47 ( V_40 , V_53 ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 , L_18 ,
V_13 , V_12 ) ;
}
}
static int F_48 ( struct V_52 * V_53 ,
unsigned int V_98 , unsigned long V_99 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
switch ( V_98 ) {
case V_100 :
return F_49 ( V_40 ,
(struct V_101 V_102 * ) V_99 ) ;
case V_103 :
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
T_3 V_109 , V_110 ;
int V_111 ;
int V_12 ;
int V_55 = V_38 -> V_55 ;
unsigned int V_112 ;
T_1 V_113 ;
T_1 V_114 = 0 ;
V_109 = V_53 -> V_70 . V_115 ;
V_110 = V_53 -> V_70 . V_116 ;
F_2 ( & V_38 -> V_6 , L_19 , V_13 , V_109 , V_110 ) ;
F_2 ( & V_38 -> V_6 , L_20 , V_13 ,
V_106 -> V_115 , V_106 -> V_116 ) ;
V_108 = F_51 ( sizeof( * V_108 ) , V_20 ) ;
if ( ! V_108 )
return;
V_114 |= V_117 ;
V_114 |= V_118 ;
V_108 -> V_119 = V_40 -> V_48 ;
switch ( F_52 ( V_53 ) ) {
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
V_53 -> V_70 . V_115 &= ~ V_129 ;
if ( F_53 ( V_53 ) ) {
if ( F_54 ( V_53 ) ) {
V_114 |= V_130 ;
V_108 -> V_131 = V_132 ;
} else {
V_114 |= V_130 ;
V_108 -> V_131 = V_133 ;
}
} else {
V_114 &= ~ V_130 ;
V_108 -> V_131 = V_134 ;
}
if ( F_55 ( V_53 ) )
V_108 -> V_135 = V_136 ;
else
V_108 -> V_135 = V_137 ;
if ( F_44 ( V_53 ) ) {
if ( ( F_56 ( V_53 ) ) != V_138 )
V_114 |= V_139 ;
V_114 |= V_140 ;
} else {
F_47 ( V_40 , V_53 ) ;
}
if ( F_43 ( V_53 ) || F_57 ( V_53 ) ) {
V_108 -> V_141 = F_58 ( V_53 ) ;
V_108 -> V_142 = F_59 ( V_53 ) ;
if ( F_43 ( V_53 ) )
V_114 |= V_143 ;
else
F_47 ( V_40 , V_53 ) ;
if ( F_57 ( V_53 ) )
V_114 |= V_144 ;
}
V_111 = F_60 ( V_53 ) ;
if ( ! V_111 )
V_111 = 9600 ;
if ( V_40 -> V_47 -> V_25 )
V_113 = ( 923077 + V_111 / 2 ) / V_111 ;
else
V_113 = ( 461538 + V_111 / 2 ) / V_111 ;
if ( ( F_56 ( V_53 ) ) != V_138 )
F_61 ( V_53 , V_111 , V_111 ) ;
F_2 ( & V_38 -> V_6 ,
L_21 ,
V_13 , V_111 , V_113 , V_114 ,
V_108 -> V_121 , V_108 -> V_131 , V_108 -> V_135 ,
V_108 -> V_141 , V_108 -> V_142 , V_108 -> V_119 ) ;
V_108 -> V_145 = F_62 ( V_113 ) ;
V_108 -> V_146 = F_62 ( V_114 ) ;
V_12 = F_25 ( V_40 -> V_47 , V_147 ,
( V_72 ) ( V_73 + V_55 ) , 0 , ( V_72 * ) V_108 ,
sizeof( * V_108 ) ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 , L_22 ,
V_13 , V_55 , V_12 ) ;
V_112 = V_40 -> V_62 ;
if ( F_56 ( V_53 ) == V_138 )
V_112 &= ~ ( V_64 | V_63 ) ;
V_12 = F_63 ( V_40 , V_112 ) ;
if ( V_12 )
F_22 ( & V_38 -> V_6 ,
L_23 ,
V_13 , V_55 , V_12 ) ;
F_11 ( V_108 ) ;
}
static int F_64 ( struct V_52 * V_53 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
unsigned int V_148 ;
unsigned int V_149 ;
unsigned int V_112 ;
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_149 = V_40 -> V_61 ;
V_112 = V_40 -> V_62 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
V_148 = ( ( V_112 & V_64 ) ? V_150 : 0 )
| ( ( V_112 & V_63 ) ? V_151 : 0 )
| ( ( V_112 & V_152 ) ? V_153 : 0 )
| ( ( V_149 & V_154 ) ? V_155 : 0 )
| ( ( V_149 & V_156 ) ? V_157 : 0 )
| ( ( V_149 & V_158 ) ? V_159 : 0 )
| ( ( V_149 & V_160 ) ? V_161 : 0 ) ;
F_2 ( & V_38 -> V_6 , L_24 , V_13 , V_148 ) ;
return V_148 ;
}
static int F_65 ( struct V_52 * V_53 ,
unsigned int V_162 , unsigned int V_163 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
unsigned int V_112 ;
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_112 = V_40 -> V_62 ;
if ( V_162 & V_151 )
V_112 |= V_63 ;
if ( V_162 & V_150 )
V_112 |= V_64 ;
if ( V_162 & V_153 )
V_112 |= V_152 ;
if ( V_163 & V_151 )
V_112 &= ~ V_63 ;
if ( V_163 & V_150 )
V_112 &= ~ V_64 ;
if ( V_163 & V_153 )
V_112 &= ~ V_152 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
return F_63 ( V_40 , V_112 ) ;
}
static void F_66 ( struct V_52 * V_53 , int V_164 )
{
struct V_37 * V_38 = V_53 -> V_92 ;
struct V_39 * V_40 = F_19 ( V_38 ) ;
int V_12 ;
F_2 ( & V_38 -> V_6 , L_25 , V_13 , V_164 ) ;
V_12 = F_67 ( V_38 , V_40 -> V_47 ,
V_40 -> V_42 + V_165 ,
V_166 , V_164 == - 1 ? V_166 : 0 ) ;
if ( V_12 )
F_2 ( & V_38 -> V_6 , L_26 , V_13 , V_12 ) ;
}
static int F_68 ( unsigned char V_167 )
{
return ( V_167 >> 4 ) - 3 ;
}
static int F_69 ( unsigned char V_167 )
{
return V_167 & 0x0f ;
}
static void F_70 ( struct V_54 * V_54 )
{
struct V_3 * V_4 = V_54 -> V_69 ;
struct V_37 * V_38 ;
struct V_1 * V_2 = V_4 -> V_23 ;
struct V_39 * V_40 ;
struct V_168 * V_6 = & V_54 -> V_6 -> V_6 ;
unsigned char * V_90 = V_54 -> V_169 ;
int V_170 = V_54 -> V_171 ;
int V_55 ;
int V_172 ;
int V_12 = V_54 -> V_12 ;
int V_173 ;
T_2 V_149 ;
switch ( V_12 ) {
case 0 :
break;
case - V_174 :
case - V_175 :
case - V_176 :
F_2 ( V_6 , L_27 , V_13 , V_12 ) ;
return;
default:
F_22 ( V_6 , L_28 , V_13 , V_12 ) ;
goto exit;
}
if ( V_170 != 2 ) {
F_2 ( V_6 , L_29 , V_13 , V_170 ) ;
goto exit;
}
if ( V_90 [ 0 ] == V_177 ) {
F_22 ( V_6 , L_30 , V_13 , V_90 [ 1 ] ) ;
goto exit;
}
V_55 = F_68 ( V_90 [ 0 ] ) ;
V_172 = F_69 ( V_90 [ 0 ] ) ;
F_2 ( V_6 , L_31 ,
V_13 , V_55 , V_172 , V_90 [ 1 ] ) ;
if ( V_55 >= V_2 -> V_178 ) {
F_22 ( V_6 , L_32 ,
V_13 , V_55 ) ;
goto exit;
}
V_38 = V_2 -> V_38 [ V_55 ] ;
V_40 = F_19 ( V_38 ) ;
if ( ! V_40 )
goto exit;
switch ( V_172 ) {
case V_179 :
F_22 ( V_6 , L_33 ,
V_13 , V_55 , V_90 [ 1 ] ) ;
break;
case V_180 :
V_149 = V_90 [ 1 ] ;
F_2 ( V_6 , L_34 , V_13 , V_55 , V_149 ) ;
F_71 ( V_40 , V_149 ) ;
break;
default:
F_22 ( V_6 , L_35 ,
V_13 , V_90 [ 1 ] ) ;
break;
}
exit:
V_173 = F_23 ( V_54 , V_181 ) ;
if ( V_173 )
F_22 ( V_6 , L_36 ,
V_13 , V_173 ) ;
}
static void F_72 ( struct V_54 * V_54 )
{
struct V_39 * V_40 = V_54 -> V_69 ;
struct V_37 * V_38 = V_40 -> V_46 ;
struct V_168 * V_6 = & V_54 -> V_6 -> V_6 ;
int V_12 = V_54 -> V_12 ;
int V_173 = 0 ;
switch ( V_12 ) {
case 0 :
break;
case - V_174 :
case - V_175 :
case - V_176 :
F_2 ( V_6 , L_27 , V_13 , V_12 ) ;
return;
default:
F_22 ( V_6 , L_28 ,
V_13 , V_12 ) ;
}
if ( V_12 == - V_182 )
goto exit;
if ( V_12 ) {
F_22 ( V_6 , L_37 , V_13 ) ;
return;
}
if ( V_54 -> V_171 ) {
F_73 ( V_6 , V_13 , V_54 -> V_171 ,
V_54 -> V_169 ) ;
if ( ! V_40 -> V_84 )
F_2 ( V_6 , L_38 ,
V_13 ) ;
else
F_74 ( V_38 , V_54 -> V_169 , V_54 -> V_171 ) ;
F_75 ( & V_40 -> V_41 ) ;
V_38 -> V_183 . V_184 += V_54 -> V_171 ;
F_76 ( & V_40 -> V_41 ) ;
}
exit:
F_75 ( & V_40 -> V_41 ) ;
if ( V_40 -> V_82 == V_83 )
V_173 = F_23 ( V_54 , V_181 ) ;
else if ( V_40 -> V_82 == V_185 )
V_40 -> V_82 = V_186 ;
F_76 ( & V_40 -> V_41 ) ;
if ( V_173 )
F_22 ( V_6 , L_39 ,
V_13 , V_173 ) ;
}
static void F_77 ( struct V_54 * V_54 )
{
struct V_39 * V_40 = V_54 -> V_69 ;
struct V_37 * V_38 = V_40 -> V_46 ;
int V_12 = V_54 -> V_12 ;
V_40 -> V_87 = 0 ;
switch ( V_12 ) {
case 0 :
break;
case - V_174 :
case - V_175 :
case - V_176 :
F_2 ( & V_38 -> V_6 , L_27 , V_13 , V_12 ) ;
return;
default:
F_78 ( V_38 , L_28 ,
V_13 , V_12 ) ;
}
F_35 ( V_40 ) ;
}
static void F_74 ( struct V_37 * V_38 , unsigned char * V_90 ,
int V_170 )
{
int V_187 ;
do {
V_187 = F_79 ( & V_38 -> V_38 , V_90 , V_170 ) ;
if ( V_187 < V_170 ) {
F_22 ( & V_38 -> V_6 , L_40 ,
V_13 , V_170 - V_187 ) ;
if ( V_187 == 0 )
break;
}
F_80 ( & V_38 -> V_38 ) ;
V_90 += V_187 ;
V_170 -= V_187 ;
} while ( V_170 > 0 );
}
static void F_35 ( struct V_39 * V_40 )
{
int V_91 , V_148 ;
struct V_37 * V_38 = V_40 -> V_46 ;
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( V_40 -> V_87 )
goto V_188;
V_91 = F_81 ( & V_38 -> V_88 ,
V_38 -> V_79 -> V_169 ,
V_38 -> V_189 ) ;
if ( V_91 == 0 )
goto V_188;
V_40 -> V_87 = 1 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
F_73 ( & V_38 -> V_6 , V_13 , V_91 ,
V_38 -> V_79 -> V_169 ) ;
F_82 ( V_38 -> V_79 , V_38 -> V_2 -> V_6 ,
F_83 ( V_38 -> V_2 -> V_6 ,
V_38 -> V_190 ) ,
V_38 -> V_79 -> V_169 , V_91 ,
F_77 , V_40 ) ;
V_148 = F_23 ( V_38 -> V_79 , V_181 ) ;
if ( V_148 ) {
F_78 ( V_38 , L_41 ,
V_13 , V_148 ) ;
V_40 -> V_87 = 0 ;
} else {
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_38 -> V_183 . V_191 += V_91 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
F_84 ( & V_38 -> V_38 ) ;
return;
V_188:
F_32 ( & V_40 -> V_41 , V_86 ) ;
return;
}
static int F_63 ( struct V_39 * V_40 , unsigned int V_112 )
{
unsigned long V_86 ;
int V_12 ;
V_12 = F_67 ( V_40 -> V_46 , V_40 -> V_47 ,
V_40 -> V_42 + V_192 ,
V_63 | V_64 | V_152 , V_112 ) ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( ! V_12 )
V_40 -> V_62 = V_112 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
return V_12 ;
}
static int F_41 ( struct V_39 * V_40 , T_2 * V_96 )
{
int V_193 , V_12 ;
struct V_3 * V_4 = V_40 -> V_47 ;
struct V_37 * V_38 = V_40 -> V_46 ;
int V_55 = V_38 -> V_55 ;
struct V_194 * V_90 ;
V_193 = sizeof( struct V_194 ) ;
V_90 = F_51 ( V_193 , V_20 ) ;
if ( ! V_90 )
return - V_21 ;
V_12 = F_85 ( V_4 , V_195 ,
( V_72 ) ( V_73 + V_55 ) , 0 , ( V_72 * ) V_90 , V_193 ) ;
if ( V_12 ) {
F_22 ( & V_38 -> V_6 ,
L_42 ,
V_13 , V_12 ) ;
goto V_196;
}
F_2 ( & V_38 -> V_6 , L_43 , V_13 , V_90 -> V_197 ) ;
* V_96 = V_90 -> V_197 ;
V_196:
F_11 ( V_90 ) ;
return V_12 ;
}
static int F_49 ( struct V_39 * V_40 ,
struct V_101 V_102 * V_198 )
{
struct V_37 * V_38 = V_40 -> V_46 ;
struct V_101 V_199 ;
unsigned V_200 ;
if ( ! V_198 )
return - V_201 ;
V_200 = V_38 -> V_38 . V_45 ;
if ( V_200 != V_202 )
V_200 = F_86 ( V_200 ) / 10 ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_199 . type = V_203 ;
V_199 . line = V_38 -> V_204 ;
V_199 . V_38 = V_38 -> V_55 ;
V_199 . V_205 = F_87 ( & V_38 -> V_88 ) ;
V_199 . V_206 = V_40 -> V_47 -> V_25 ? 921600 : 460800 ;
V_199 . V_45 = V_200 ;
if ( F_88 ( V_198 , & V_199 , sizeof( * V_198 ) ) )
return - V_201 ;
return 0 ;
}
static int F_50 ( struct V_52 * V_53 , struct V_39 * V_40 ,
struct V_101 V_102 * V_207 )
{
struct V_101 V_208 ;
unsigned V_200 ;
if ( F_89 ( & V_208 , V_207 , sizeof( V_208 ) ) )
return - V_201 ;
V_200 = V_208 . V_45 ;
if ( V_200 != V_202 )
V_200 = F_16 ( 10 * V_208 . V_45 ) ;
V_40 -> V_46 -> V_38 . V_45 = V_200 ;
return 0 ;
}
static void F_71 ( struct V_39 * V_40 , T_2 V_149 )
{
struct V_209 * V_183 ;
struct V_52 * V_53 ;
unsigned long V_86 ;
F_2 ( & V_40 -> V_46 -> V_6 , L_44 , V_13 , V_149 ) ;
if ( V_149 & V_210 ) {
F_30 ( & V_40 -> V_41 , V_86 ) ;
V_183 = & V_40 -> V_46 -> V_183 ;
if ( V_149 & V_211 )
V_183 -> V_212 ++ ;
if ( V_149 & V_213 )
V_183 -> V_214 ++ ;
if ( V_149 & V_215 )
V_183 -> V_216 ++ ;
if ( V_149 & V_217 )
V_183 -> V_218 ++ ;
F_90 ( & V_40 -> V_46 -> V_38 . V_219 ) ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
V_40 -> V_61 = V_149 & V_220 ;
V_53 = F_91 ( & V_40 -> V_46 -> V_38 ) ;
if ( V_53 && F_44 ( V_53 ) ) {
if ( V_149 & V_154 )
F_92 ( V_53 ) ;
}
F_93 ( V_53 ) ;
}
static void F_45 ( struct V_39 * V_40 , struct V_52 * V_53 )
{
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( V_40 -> V_82 == V_83 )
V_40 -> V_82 = V_185 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
static int F_47 ( struct V_39 * V_40 , struct V_52 * V_53 )
{
struct V_54 * V_54 ;
int V_12 = 0 ;
unsigned long V_86 ;
F_30 ( & V_40 -> V_41 , V_86 ) ;
if ( V_40 -> V_82 == V_186 ) {
V_40 -> V_82 = V_83 ;
V_54 = V_40 -> V_46 -> V_81 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
V_54 -> V_69 = V_40 ;
V_12 = F_23 ( V_54 , V_20 ) ;
} else {
V_40 -> V_82 = V_83 ;
F_32 ( & V_40 -> V_41 , V_86 ) ;
}
return V_12 ;
}
static int F_25 ( struct V_3 * V_4 , V_72 V_221 ,
T_4 V_222 , T_4 V_223 , V_72 * V_90 , int V_193 )
{
int V_12 ;
V_12 = F_94 ( V_4 -> V_23 -> V_6 ,
F_95 ( V_4 -> V_23 -> V_6 , 0 ) , V_221 ,
( V_224 | V_225 | V_226 ) ,
V_223 , V_222 , V_90 , V_193 , 1000 ) ;
if ( V_12 == V_193 )
V_12 = 0 ;
if ( V_12 > 0 )
V_12 = - V_227 ;
return V_12 ;
}
static int F_85 ( struct V_3 * V_4 , V_72 V_221 ,
T_4 V_222 , T_4 V_223 , V_72 * V_90 , int V_193 )
{
int V_12 ;
V_12 = F_94 ( V_4 -> V_23 -> V_6 ,
F_96 ( V_4 -> V_23 -> V_6 , 0 ) , V_221 ,
( V_224 | V_225 | V_228 ) ,
V_223 , V_222 , V_90 , V_193 , 1000 ) ;
if ( V_12 == V_193 )
V_12 = 0 ;
if ( V_12 > 0 )
V_12 = - V_227 ;
return V_12 ;
}
static int F_67 ( struct V_37 * V_38 ,
struct V_3 * V_4 , unsigned long V_229 ,
T_2 V_230 , T_2 V_231 )
{
int V_12 ;
unsigned int V_193 ;
struct V_232 * V_90 ;
F_2 ( & V_38 -> V_6 , L_45 , V_13 ,
V_229 , V_230 , V_231 ) ;
V_193 = sizeof( struct V_232 ) + 2 ;
V_90 = F_51 ( V_193 , V_20 ) ;
if ( ! V_90 )
return - V_21 ;
V_90 -> V_233 = V_234 ;
V_90 -> V_235 = V_236 ;
V_90 -> V_237 = 1 ;
V_90 -> V_238 = F_62 ( V_229 >> 16 ) ;
V_90 -> V_239 = F_62 ( V_229 ) ;
V_90 -> V_240 [ 0 ] = V_230 ;
V_90 -> V_240 [ 1 ] = V_231 ;
V_12 = F_25 ( V_4 , V_241 , V_242 , 0 ,
( V_72 * ) V_90 , V_193 ) ;
if ( V_12 < 0 )
F_22 ( & V_38 -> V_6 , L_46 , V_13 , V_12 ) ;
F_11 ( V_90 ) ;
return V_12 ;
}
static int F_97 ( struct V_5 * V_6 , int V_80 ,
T_2 * V_243 , int V_193 )
{
int V_244 ;
T_2 V_245 = 0 ;
int V_246 ;
struct V_247 * V_248 ;
int V_12 = 0 ;
int V_249 ;
for ( V_244 = sizeof( struct V_247 ) ; V_244 < V_193 ; V_244 ++ )
V_245 = ( T_2 ) ( V_245 + V_243 [ V_244 ] ) ;
V_248 = (struct V_247 * ) V_243 ;
V_248 -> V_250 = F_98 ( V_193 - sizeof( * V_248 ) ) ;
V_248 -> V_251 = V_245 ;
F_2 ( & V_6 -> V_6 , L_47 , V_13 ) ;
for ( V_244 = 0 ; V_244 < V_193 ; V_244 += V_246 ) {
V_249 = F_99 ( V_193 - V_244 , V_252 ) ;
V_12 = F_100 ( V_6 , V_80 , V_243 + V_244 , V_249 ,
& V_246 , 1000 ) ;
if ( V_12 )
break;
}
return V_12 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_12 ;
int V_253 ;
T_2 * V_243 ;
struct V_5 * V_6 = V_4 -> V_23 -> V_6 ;
unsigned int V_80 = F_83 ( V_6 ,
V_4 -> V_23 -> V_38 [ 0 ] -> V_190 ) ;
const struct V_254 * V_255 ;
char V_256 [ 32 ] ;
if ( F_3 ( V_6 -> V_14 . V_26 ) == V_27 ) {
snprintf ( V_256 ,
sizeof( V_256 ) ,
L_48 ,
F_3 ( V_6 -> V_14 . V_15 ) ) ;
V_12 = F_101 ( & V_255 , V_256 , & V_6 -> V_6 ) ;
goto V_257;
}
sprintf ( V_256 , L_49 ,
F_3 ( V_6 -> V_14 . V_26 ) ,
F_3 ( V_6 -> V_14 . V_15 ) ) ;
V_12 = F_101 ( & V_255 , V_256 , & V_6 -> V_6 ) ;
if ( V_12 != 0 ) {
V_256 [ 0 ] = '\0' ;
if ( F_3 ( V_6 -> V_14 . V_26 ) == V_258 ) {
switch ( F_3 ( V_6 -> V_14 . V_15 ) ) {
case V_259 :
strcpy ( V_256 , L_50 ) ;
break;
case V_260 :
strcpy ( V_256 , L_51 ) ;
break;
case V_261 :
strcpy ( V_256 , L_52 ) ;
break;
case V_262 :
strcpy ( V_256 , L_53 ) ;
break;
case V_263 :
strcpy ( V_256 , L_54 ) ;
break;
case V_264 :
strcpy ( V_256 , L_54 ) ;
break; }
}
if ( V_256 [ 0 ] == '\0' ) {
if ( V_4 -> V_25 )
strcpy ( V_256 , L_55 ) ;
else
strcpy ( V_256 , L_56 ) ;
}
V_12 = F_101 ( & V_255 , V_256 , & V_6 -> V_6 ) ;
}
V_257:
if ( V_12 ) {
F_22 ( & V_6 -> V_6 , L_57 , V_13 ) ;
return - V_175 ;
}
if ( V_255 -> V_193 > V_265 ) {
F_22 ( & V_6 -> V_6 , L_58 , V_13 , V_255 -> V_193 ) ;
F_102 ( V_255 ) ;
return - V_175 ;
}
V_253 = V_265 + sizeof( struct V_247 ) ;
V_243 = F_51 ( V_253 , V_20 ) ;
if ( V_243 ) {
memcpy ( V_243 , V_255 -> V_90 , V_255 -> V_193 ) ;
memset ( V_243 + V_255 -> V_193 , 0xff , V_253 - V_255 -> V_193 ) ;
V_12 = F_97 ( V_6 , V_80 , V_243 , V_255 -> V_193 ) ;
F_11 ( V_243 ) ;
} else {
V_12 = - V_21 ;
}
F_102 ( V_255 ) ;
if ( V_12 ) {
F_22 ( & V_6 -> V_6 , L_59 ,
V_13 , V_12 ) ;
return V_12 ;
}
F_2 ( & V_6 -> V_6 , L_60 , V_13 ) ;
return 0 ;
}
