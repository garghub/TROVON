static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
F_2 ( & V_6 -> V_6 ,
L_1 ,
V_8 , F_3 ( V_6 -> V_9 . V_10 ) ,
V_6 -> V_9 . V_11 ,
V_6 -> V_12 -> V_13 . V_14 ) ;
V_4 = F_4 ( sizeof( struct V_3 ) , V_15 ) ;
if ( ! V_4 )
return - V_16 ;
F_5 ( & V_4 -> V_17 ) ;
V_4 -> V_18 = V_2 ;
F_6 ( V_2 , V_4 ) ;
if ( V_2 -> type == & V_19 )
V_4 -> V_20 = 1 ;
F_2 ( & V_6 -> V_6 , L_2 , V_8 ,
V_4 -> V_20 ? L_3 : L_4 ) ;
if ( V_6 -> V_9 . V_11 == 1 ) {
V_7 = F_7 ( V_4 ) ;
if ( V_7 != 0 )
goto V_21;
if ( V_4 -> V_20 ) {
F_8 ( 100 ) ;
F_9 ( V_6 ) ;
}
V_7 = - V_22 ;
goto V_21;
}
if ( V_6 -> V_12 -> V_13 . V_14 == V_23 ) {
V_7 = F_10 ( V_6 , V_24 ) ;
V_7 = V_7 ? V_7 : - V_22 ;
goto V_21;
}
return 0 ;
V_21:
F_11 ( V_4 ) ;
F_6 ( V_2 , NULL ) ;
return V_7 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_13 ( V_2 ) ;
F_11 ( V_4 ) ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_4 ( sizeof( * V_28 ) , V_15 ) ;
if ( ! V_28 )
return - V_16 ;
F_15 ( & V_28 -> V_29 ) ;
if ( V_26 == V_26 -> V_2 -> V_26 [ 0 ] )
V_28 -> V_30 = V_31 ;
else
V_28 -> V_30 = V_32 ;
V_26 -> V_26 . V_33 = F_16 ( 10 * V_33 ) ;
V_28 -> V_34 = V_26 ;
V_28 -> V_35 = F_13 ( V_26 -> V_2 ) ;
V_28 -> V_36 = 0 ;
F_17 ( V_26 , V_28 ) ;
V_26 -> V_26 . V_37 = 3 ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_19 ( V_26 ) ;
F_11 ( V_28 ) ;
return 0 ;
}
static int F_20 ( struct V_38 * V_39 , struct V_25 * V_26 )
{
struct V_27 * V_28 = F_19 ( V_26 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_40 * V_40 ;
int V_41 ;
int V_7 ;
T_1 V_42 = ( V_43 ) ( V_44 |
V_45 |
( V_46 << 2 ) ) ;
if ( V_28 == NULL )
return - V_22 ;
V_6 = V_26 -> V_2 -> V_6 ;
V_4 = V_28 -> V_35 ;
if ( F_21 ( & V_4 -> V_17 ) )
return - V_47 ;
V_41 = V_26 -> V_41 ;
V_28 -> V_48 = 0 ;
V_28 -> V_49 |= ( V_50 | V_51 ) ;
if ( V_4 -> V_52 == 0 ) {
F_2 ( & V_26 -> V_6 , L_5 , V_8 ) ;
V_40 = V_4 -> V_18 -> V_26 [ 0 ] -> V_53 ;
if ( ! V_40 ) {
F_22 ( & V_26 -> V_6 , L_6 , V_8 ) ;
V_7 = - V_54 ;
goto V_55;
}
V_40 -> V_56 = V_4 ;
V_7 = F_23 ( V_40 , V_15 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_7 , V_8 , V_7 ) ;
goto V_55;
}
}
if ( V_39 )
F_24 ( V_39 , V_26 , & V_39 -> V_57 ) ;
F_2 ( & V_26 -> V_6 , L_8 , V_8 ) ;
V_7 = F_25 ( V_4 , V_58 ,
( V_43 ) ( V_59 + V_41 ) , V_42 , NULL , 0 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_9 ,
V_8 , V_7 ) ;
goto V_60;
}
F_2 ( & V_26 -> V_6 , L_10 , V_8 ) ;
V_7 = F_25 ( V_4 , V_61 ,
( V_43 ) ( V_59 + V_41 ) , 0 , NULL , 0 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_11 ,
V_8 , V_7 ) ;
goto V_60;
}
F_2 ( & V_26 -> V_6 , L_12 , V_8 ) ;
V_7 = F_25 ( V_4 , V_62 ,
( V_43 ) ( V_59 + V_41 ) , V_63 , NULL , 0 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_13 ,
V_8 , V_7 ) ;
goto V_60;
}
V_7 = F_25 ( V_4 , V_62 ,
( V_43 ) ( V_59 + V_41 ) , V_64 , NULL , 0 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_14 ,
V_8 , V_7 ) ;
goto V_60;
}
F_26 ( V_6 , V_26 -> V_65 -> V_66 ) ;
F_26 ( V_6 , V_26 -> V_67 -> V_66 ) ;
if ( V_39 )
F_24 ( V_39 , V_26 , & V_39 -> V_57 ) ;
F_2 ( & V_26 -> V_6 , L_15 , V_8 ) ;
V_7 = F_25 ( V_4 , V_58 ,
( V_43 ) ( V_59 + V_41 ) , V_42 , NULL , 0 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_16 ,
V_8 , V_7 ) ;
goto V_60;
}
F_2 ( & V_26 -> V_6 , L_17 , V_8 ) ;
V_7 = F_25 ( V_4 , V_61 ,
( V_43 ) ( V_59 + V_41 ) , 0 , NULL , 0 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_18 ,
V_8 , V_7 ) ;
goto V_60;
}
F_2 ( & V_26 -> V_6 , L_19 , V_8 ) ;
V_40 = V_26 -> V_67 ;
if ( ! V_40 ) {
F_22 ( & V_26 -> V_6 , L_20 , V_8 ) ;
V_7 = - V_54 ;
goto V_60;
}
V_28 -> V_68 = V_69 ;
V_40 -> V_56 = V_28 ;
V_7 = F_23 ( V_40 , V_15 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 , L_21 ,
V_8 , V_7 ) ;
goto V_60;
}
V_28 -> V_70 = 1 ;
++ V_4 -> V_52 ;
goto V_55;
V_60:
if ( V_4 -> V_52 == 0 )
F_27 ( V_26 -> V_2 -> V_26 [ 0 ] -> V_53 ) ;
V_55:
F_28 ( & V_4 -> V_17 ) ;
F_2 ( & V_26 -> V_6 , L_22 , V_8 , V_7 ) ;
return V_7 ;
}
static void F_29 ( struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_27 * V_28 ;
int V_41 ;
int V_7 ;
int V_71 ;
unsigned long V_72 ;
V_4 = F_13 ( V_26 -> V_2 ) ;
V_28 = F_19 ( V_26 ) ;
if ( V_4 == NULL || V_28 == NULL )
return;
V_28 -> V_70 = 0 ;
F_27 ( V_26 -> V_67 ) ;
F_27 ( V_26 -> V_65 ) ;
V_28 -> V_73 = 0 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
F_31 ( & V_26 -> V_74 ) ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
V_41 = V_26 -> V_41 ;
F_2 ( & V_26 -> V_6 , L_23 , V_8 ) ;
V_7 = F_25 ( V_4 , V_75 ,
( V_43 ) ( V_59 + V_41 ) , 0 , NULL , 0 ) ;
if ( V_7 )
F_22 ( & V_26 -> V_6 ,
L_24
, V_8 , V_7 ) ;
V_71 = ! F_21 ( & V_4 -> V_17 ) ;
-- V_28 -> V_35 -> V_52 ;
if ( V_28 -> V_35 -> V_52 <= 0 ) {
F_27 ( V_26 -> V_2 -> V_26 [ 0 ] -> V_53 ) ;
V_28 -> V_35 -> V_52 = 0 ;
}
if ( V_71 )
F_28 ( & V_4 -> V_17 ) ;
}
static int F_33 ( struct V_38 * V_39 , struct V_25 * V_26 ,
const unsigned char * V_76 , int V_77 )
{
struct V_27 * V_28 = F_19 ( V_26 ) ;
if ( V_77 == 0 ) {
F_2 ( & V_26 -> V_6 , L_25 , V_8 ) ;
return 0 ;
}
if ( V_28 == NULL || ! V_28 -> V_70 )
return - V_22 ;
V_77 = F_34 ( & V_26 -> V_74 , V_76 , V_77 ,
& V_28 -> V_29 ) ;
F_35 ( V_28 ) ;
return V_77 ;
}
static int F_36 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
int V_79 = 0 ;
unsigned long V_72 ;
if ( V_28 == NULL )
return 0 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
V_79 = F_37 ( & V_26 -> V_74 ) ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
F_2 ( & V_26 -> V_6 , L_26 , V_8 , V_79 ) ;
return V_79 ;
}
static int F_38 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
int V_80 = 0 ;
unsigned long V_72 ;
if ( V_28 == NULL )
return 0 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
V_80 = F_39 ( & V_26 -> V_74 ) ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
F_2 ( & V_26 -> V_6 , L_26 , V_8 , V_80 ) ;
return V_80 ;
}
static bool F_40 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_19 ( V_26 ) ;
int V_81 ;
T_2 V_82 ;
V_81 = F_41 ( V_28 , & V_82 ) ;
if ( ! V_81 && ! ( V_82 & V_83 ) )
return false ;
return true ;
}
static void F_42 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
if ( V_28 == NULL )
return;
if ( F_43 ( V_39 ) || F_44 ( V_39 ) )
F_45 ( V_28 , V_39 ) ;
}
static void F_46 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
int V_7 ;
if ( V_28 == NULL )
return;
if ( F_43 ( V_39 ) || F_44 ( V_39 ) ) {
V_7 = F_47 ( V_28 , V_39 ) ;
if ( V_7 )
F_22 ( & V_26 -> V_6 , L_27 ,
V_8 , V_7 ) ;
}
}
static int F_48 ( struct V_38 * V_39 ,
unsigned int V_84 , unsigned long V_85 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
if ( V_28 == NULL )
return - V_22 ;
switch ( V_84 ) {
case V_86 :
F_2 ( & V_26 -> V_6 , L_28 , V_8 ) ;
return F_49 ( V_28 ,
(struct V_87 V_88 * ) V_85 ) ;
case V_89 :
F_2 ( & V_26 -> V_6 , L_29 , V_8 ) ;
return F_50 ( V_39 , V_28 ,
(struct V_87 V_88 * ) V_85 ) ;
}
return - V_90 ;
}
static void F_24 ( struct V_38 * V_39 ,
struct V_25 * V_26 , struct V_91 * V_92 )
{
struct V_27 * V_28 = F_19 ( V_26 ) ;
struct V_93 * V_94 ;
T_3 V_95 , V_96 ;
int V_97 ;
int V_7 ;
int V_41 = V_26 -> V_41 ;
unsigned int V_98 ;
V_95 = V_39 -> V_57 . V_99 ;
V_96 = V_39 -> V_57 . V_100 ;
F_2 ( & V_26 -> V_6 , L_30 , V_8 , V_95 , V_96 ) ;
F_2 ( & V_26 -> V_6 , L_31 , V_8 ,
V_92 -> V_99 , V_92 -> V_100 ) ;
if ( V_28 == NULL )
return;
V_94 = F_51 ( sizeof( * V_94 ) , V_15 ) ;
if ( ! V_94 )
return;
V_94 -> V_101 = 0 ;
V_94 -> V_101 |= V_102 ;
V_94 -> V_101 |= V_103 ;
V_94 -> V_104 = ( V_43 ) ( V_28 -> V_36 ) ;
switch ( V_95 & V_105 ) {
case V_106 :
V_94 -> V_107 = V_108 ;
break;
case V_109 :
V_94 -> V_107 = V_110 ;
break;
case V_111 :
V_94 -> V_107 = V_112 ;
break;
default:
case V_113 :
V_94 -> V_107 = V_114 ;
break;
}
V_39 -> V_57 . V_99 &= ~ V_115 ;
if ( V_95 & V_116 ) {
if ( V_95 & V_117 ) {
V_94 -> V_101 |= V_118 ;
V_94 -> V_119 = V_120 ;
} else {
V_94 -> V_101 |= V_118 ;
V_94 -> V_119 = V_121 ;
}
} else {
V_94 -> V_101 &= ~ V_118 ;
V_94 -> V_119 = V_122 ;
}
if ( V_95 & V_123 )
V_94 -> V_124 = V_125 ;
else
V_94 -> V_124 = V_126 ;
if ( V_95 & V_127 ) {
if ( ( V_95 & V_128 ) != V_129 )
V_94 -> V_101 |= V_130 ;
V_94 -> V_101 |= V_131 ;
} else {
V_39 -> V_132 = 0 ;
F_47 ( V_28 , V_39 ) ;
}
if ( F_43 ( V_39 ) || F_52 ( V_39 ) ) {
V_94 -> V_133 = F_53 ( V_39 ) ;
V_94 -> V_134 = F_54 ( V_39 ) ;
if ( F_43 ( V_39 ) )
V_94 -> V_101 |= V_135 ;
else
F_47 ( V_28 , V_39 ) ;
if ( F_52 ( V_39 ) )
V_94 -> V_101 |= V_136 ;
}
V_97 = F_55 ( V_39 ) ;
if ( ! V_97 )
V_97 = 9600 ;
if ( V_28 -> V_35 -> V_20 )
V_94 -> V_137 = ( T_1 ) ( ( 923077 + V_97 / 2 ) / V_97 ) ;
else
V_94 -> V_137 = ( T_1 ) ( ( 461538 + V_97 / 2 ) / V_97 ) ;
if ( ( V_95 & V_128 ) != V_129 )
F_56 ( V_39 , V_97 , V_97 ) ;
F_2 ( & V_26 -> V_6 ,
L_32 ,
V_8 , V_97 , V_94 -> V_137 , V_94 -> V_101 ,
V_94 -> V_107 , V_94 -> V_119 , V_94 -> V_124 ,
V_94 -> V_133 , V_94 -> V_134 , V_94 -> V_104 ) ;
F_57 ( & V_94 -> V_137 ) ;
F_57 ( & V_94 -> V_101 ) ;
V_7 = F_25 ( V_28 -> V_35 , V_138 ,
( V_43 ) ( V_59 + V_41 ) , 0 , ( V_43 * ) V_94 ,
sizeof( * V_94 ) ) ;
if ( V_7 )
F_22 ( & V_26 -> V_6 , L_33 ,
V_8 , V_41 , V_7 ) ;
V_98 = V_28 -> V_49 ;
if ( ( V_95 & V_128 ) == V_129 )
V_98 &= ~ ( V_51 | V_50 ) ;
V_7 = F_58 ( V_28 , V_98 ) ;
if ( V_7 )
F_22 ( & V_26 -> V_6 ,
L_34 ,
V_8 , V_41 , V_7 ) ;
F_11 ( V_94 ) ;
}
static int F_59 ( struct V_38 * V_39 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
unsigned int V_139 ;
unsigned int V_140 ;
unsigned int V_98 ;
unsigned long V_72 ;
if ( V_28 == NULL )
return - V_22 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
V_140 = V_28 -> V_48 ;
V_98 = V_28 -> V_49 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
V_139 = ( ( V_98 & V_51 ) ? V_141 : 0 )
| ( ( V_98 & V_50 ) ? V_142 : 0 )
| ( ( V_98 & V_143 ) ? V_144 : 0 )
| ( ( V_140 & V_145 ) ? V_146 : 0 )
| ( ( V_140 & V_147 ) ? V_148 : 0 )
| ( ( V_140 & V_149 ) ? V_150 : 0 )
| ( ( V_140 & V_151 ) ? V_152 : 0 ) ;
F_2 ( & V_26 -> V_6 , L_35 , V_8 , V_139 ) ;
return V_139 ;
}
static int F_60 ( struct V_38 * V_39 ,
unsigned int V_153 , unsigned int V_154 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
unsigned int V_98 ;
unsigned long V_72 ;
if ( V_28 == NULL )
return - V_22 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
V_98 = V_28 -> V_49 ;
if ( V_153 & V_142 )
V_98 |= V_50 ;
if ( V_153 & V_141 )
V_98 |= V_51 ;
if ( V_153 & V_144 )
V_98 |= V_143 ;
if ( V_154 & V_142 )
V_98 &= ~ V_50 ;
if ( V_154 & V_141 )
V_98 &= ~ V_51 ;
if ( V_154 & V_144 )
V_98 &= ~ V_143 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
return F_58 ( V_28 , V_98 ) ;
}
static void F_61 ( struct V_38 * V_39 , int V_155 )
{
struct V_25 * V_26 = V_39 -> V_78 ;
struct V_27 * V_28 = F_19 ( V_26 ) ;
int V_7 ;
F_2 ( & V_26 -> V_6 , L_36 , V_8 , V_155 ) ;
if ( V_28 == NULL )
return;
V_7 = F_62 ( V_26 , V_28 -> V_35 ,
V_28 -> V_30 + V_156 ,
V_157 , V_155 == - 1 ? V_157 : 0 ) ;
if ( V_7 )
F_2 ( & V_26 -> V_6 , L_37 , V_8 , V_7 ) ;
}
static void F_63 ( struct V_40 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_56 ;
struct V_25 * V_26 ;
struct V_1 * V_2 = V_4 -> V_18 ;
struct V_27 * V_28 ;
struct V_158 * V_6 = & V_40 -> V_6 -> V_6 ;
unsigned char * V_76 = V_40 -> V_159 ;
int V_160 = V_40 -> V_161 ;
int V_41 ;
int V_162 ;
int V_7 = V_40 -> V_7 ;
int V_163 ;
V_43 V_140 ;
switch ( V_7 ) {
case 0 :
break;
case - V_164 :
case - V_165 :
case - V_166 :
F_2 ( V_6 , L_38 , V_8 , V_7 ) ;
V_4 -> V_167 = 1 ;
return;
default:
F_22 ( V_6 , L_39 , V_8 , V_7 ) ;
V_4 -> V_167 = 1 ;
goto exit;
}
if ( V_160 != 2 ) {
F_2 ( V_6 , L_40 , V_8 , V_160 ) ;
goto exit;
}
if ( V_76 [ 0 ] == V_168 ) {
F_22 ( V_6 , L_41 , V_8 , V_76 [ 1 ] ) ;
goto exit;
}
V_41 = F_64 ( V_76 [ 0 ] ) ;
V_162 = F_65 ( V_76 [ 0 ] ) ;
F_2 ( V_6 , L_42 ,
V_8 , V_41 , V_162 , V_76 [ 1 ] ) ;
if ( V_41 >= V_2 -> V_169 ) {
F_22 ( V_6 , L_43 ,
V_8 , V_41 ) ;
goto exit;
}
V_26 = V_2 -> V_26 [ V_41 ] ;
V_28 = F_19 ( V_26 ) ;
if ( ! V_28 )
goto exit;
switch ( V_162 ) {
case V_170 :
F_22 ( V_6 , L_44 ,
V_8 , V_41 , V_76 [ 1 ] ) ;
break;
case V_171 :
V_140 = V_76 [ 1 ] ;
F_2 ( V_6 , L_45 , V_8 , V_41 , V_140 ) ;
F_66 ( V_28 , V_140 ) ;
break;
default:
F_22 ( V_6 , L_46 ,
V_8 , V_76 [ 1 ] ) ;
break;
}
exit:
V_163 = F_23 ( V_40 , V_172 ) ;
if ( V_163 )
F_22 ( V_6 , L_47 ,
V_8 , V_163 ) ;
}
static void F_67 ( struct V_40 * V_40 )
{
struct V_27 * V_28 = V_40 -> V_56 ;
struct V_25 * V_26 = V_28 -> V_34 ;
struct V_158 * V_6 = & V_40 -> V_6 -> V_6 ;
int V_7 = V_40 -> V_7 ;
int V_163 = 0 ;
switch ( V_7 ) {
case 0 :
break;
case - V_164 :
case - V_165 :
case - V_166 :
F_2 ( V_6 , L_38 , V_8 , V_7 ) ;
V_28 -> V_35 -> V_167 = 1 ;
return;
default:
F_22 ( V_6 , L_39 ,
V_8 , V_7 ) ;
V_28 -> V_35 -> V_167 = 1 ;
}
if ( V_7 == - V_173 )
goto exit;
if ( V_7 ) {
F_22 ( V_6 , L_48 , V_8 ) ;
return;
}
if ( V_40 -> V_161 ) {
F_68 ( V_6 , V_8 , V_40 -> V_161 ,
V_40 -> V_159 ) ;
if ( ! V_28 -> V_70 )
F_2 ( V_6 , L_49 ,
V_8 ) ;
else
F_69 ( V_26 , V_40 -> V_159 , V_40 -> V_161 ) ;
F_70 ( & V_28 -> V_29 ) ;
V_26 -> V_174 . V_175 += V_40 -> V_161 ;
F_71 ( & V_28 -> V_29 ) ;
}
exit:
F_70 ( & V_28 -> V_29 ) ;
if ( V_28 -> V_68 == V_69 )
V_163 = F_23 ( V_40 , V_172 ) ;
else if ( V_28 -> V_68 == V_176 )
V_28 -> V_68 = V_177 ;
F_71 ( & V_28 -> V_29 ) ;
if ( V_163 )
F_22 ( V_6 , L_50 ,
V_8 , V_163 ) ;
}
static void F_72 ( struct V_40 * V_40 )
{
struct V_27 * V_28 = V_40 -> V_56 ;
struct V_25 * V_26 = V_28 -> V_34 ;
int V_7 = V_40 -> V_7 ;
V_28 -> V_73 = 0 ;
switch ( V_7 ) {
case 0 :
break;
case - V_164 :
case - V_165 :
case - V_166 :
F_2 ( & V_26 -> V_6 , L_38 , V_8 , V_7 ) ;
V_28 -> V_35 -> V_167 = 1 ;
return;
default:
F_73 ( V_26 , L_39 ,
V_8 , V_7 ) ;
V_28 -> V_35 -> V_167 = 1 ;
}
F_35 ( V_28 ) ;
}
static void F_69 ( struct V_25 * V_26 , unsigned char * V_76 ,
int V_160 )
{
int V_178 ;
do {
V_178 = F_74 ( & V_26 -> V_26 , V_76 , V_160 ) ;
if ( V_178 < V_160 ) {
F_22 ( & V_26 -> V_6 , L_51 ,
V_8 , V_160 - V_178 ) ;
if ( V_178 == 0 )
break;
}
F_75 ( & V_26 -> V_26 ) ;
V_76 += V_178 ;
V_160 -= V_178 ;
} while ( V_160 > 0 );
}
static void F_35 ( struct V_27 * V_28 )
{
int V_77 , V_139 ;
struct V_25 * V_26 = V_28 -> V_34 ;
unsigned long V_72 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
if ( V_28 -> V_73 )
goto V_179;
V_77 = F_76 ( & V_26 -> V_74 ,
V_26 -> V_65 -> V_159 ,
V_26 -> V_180 ) ;
if ( V_77 == 0 )
goto V_179;
V_28 -> V_73 = 1 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
F_68 ( & V_26 -> V_6 , V_8 , V_77 ,
V_26 -> V_65 -> V_159 ) ;
F_77 ( V_26 -> V_65 , V_26 -> V_2 -> V_6 ,
F_78 ( V_26 -> V_2 -> V_6 ,
V_26 -> V_181 ) ,
V_26 -> V_65 -> V_159 , V_77 ,
F_72 , V_28 ) ;
V_139 = F_23 ( V_26 -> V_65 , V_172 ) ;
if ( V_139 ) {
F_73 ( V_26 , L_52 ,
V_8 , V_139 ) ;
V_28 -> V_73 = 0 ;
} else {
F_30 ( & V_28 -> V_29 , V_72 ) ;
V_26 -> V_174 . V_182 += V_77 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
}
F_79 ( & V_26 -> V_26 ) ;
return;
V_179:
F_32 ( & V_28 -> V_29 , V_72 ) ;
return;
}
static int F_58 ( struct V_27 * V_28 , unsigned int V_98 )
{
unsigned long V_72 ;
int V_7 ;
V_7 = F_62 ( V_28 -> V_34 , V_28 -> V_35 ,
V_28 -> V_30 + V_183 ,
V_50 | V_51 | V_143 , V_98 ) ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
if ( ! V_7 )
V_28 -> V_49 = V_98 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
return V_7 ;
}
static int F_41 ( struct V_27 * V_28 , T_2 * V_82 )
{
int V_184 , V_7 ;
struct V_3 * V_4 = V_28 -> V_35 ;
struct V_25 * V_26 = V_28 -> V_34 ;
int V_41 = V_26 -> V_41 ;
struct V_185 * V_76 ;
V_184 = sizeof( struct V_185 ) ;
V_76 = F_51 ( V_184 , V_15 ) ;
if ( ! V_76 )
return - V_16 ;
V_7 = F_80 ( V_4 , V_186 ,
( V_43 ) ( V_59 + V_41 ) , 0 , ( V_43 * ) V_76 , V_184 ) ;
if ( V_7 ) {
F_22 ( & V_26 -> V_6 ,
L_53 ,
V_8 , V_7 ) ;
goto V_187;
}
F_2 ( & V_26 -> V_6 , L_54 , V_8 , V_76 -> V_188 ) ;
* V_82 = V_76 -> V_188 ;
V_187:
F_11 ( V_76 ) ;
return V_7 ;
}
static int F_49 ( struct V_27 * V_28 ,
struct V_87 V_88 * V_189 )
{
struct V_25 * V_26 = V_28 -> V_34 ;
struct V_87 V_190 ;
unsigned V_191 ;
if ( ! V_189 )
return - V_192 ;
V_191 = V_26 -> V_26 . V_33 ;
if ( V_191 != V_193 )
V_191 = F_81 ( V_191 ) / 10 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . type = V_194 ;
V_190 . line = V_26 -> V_195 ;
V_190 . V_26 = V_26 -> V_41 ;
V_190 . V_72 = V_28 -> V_196 ;
V_190 . V_197 = F_82 ( & V_26 -> V_74 ) ;
V_190 . V_198 = V_28 -> V_35 -> V_20 ? 921600 : 460800 ;
V_190 . V_33 = V_191 ;
if ( F_83 ( V_189 , & V_190 , sizeof( * V_189 ) ) )
return - V_192 ;
return 0 ;
}
static int F_50 ( struct V_38 * V_39 , struct V_27 * V_28 ,
struct V_87 V_88 * V_199 )
{
struct V_87 V_200 ;
unsigned V_191 ;
if ( F_84 ( & V_200 , V_199 , sizeof( V_200 ) ) )
return - V_192 ;
V_191 = V_200 . V_33 ;
if ( V_191 != V_193 )
V_191 = F_16 ( 10 * V_200 . V_33 ) ;
V_28 -> V_196 = V_200 . V_72 & V_201 ;
V_28 -> V_34 -> V_26 . V_33 = V_191 ;
return 0 ;
}
static void F_66 ( struct V_27 * V_28 , V_43 V_140 )
{
struct V_202 * V_174 ;
struct V_38 * V_39 ;
unsigned long V_72 ;
F_2 ( & V_28 -> V_34 -> V_6 , L_55 , V_8 , V_140 ) ;
if ( V_140 & V_203 ) {
F_30 ( & V_28 -> V_29 , V_72 ) ;
V_174 = & V_28 -> V_34 -> V_174 ;
if ( V_140 & V_204 )
V_174 -> V_205 ++ ;
if ( V_140 & V_206 )
V_174 -> V_207 ++ ;
if ( V_140 & V_208 )
V_174 -> V_209 ++ ;
if ( V_140 & V_210 )
V_174 -> V_211 ++ ;
F_85 ( & V_28 -> V_34 -> V_26 . V_212 ) ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
}
V_28 -> V_48 = V_140 & V_213 ;
V_39 = F_86 ( & V_28 -> V_34 -> V_26 ) ;
if ( V_39 && F_44 ( V_39 ) ) {
if ( V_140 & V_145 ) {
V_39 -> V_132 = 0 ;
F_87 ( V_39 ) ;
} else {
V_39 -> V_132 = 1 ;
}
}
F_88 ( V_39 ) ;
}
static void F_45 ( struct V_27 * V_28 , struct V_38 * V_39 )
{
unsigned long V_72 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
if ( V_28 -> V_68 == V_69 )
V_28 -> V_68 = V_176 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
}
static int F_47 ( struct V_27 * V_28 , struct V_38 * V_39 )
{
struct V_40 * V_40 ;
int V_7 = 0 ;
unsigned long V_72 ;
F_30 ( & V_28 -> V_29 , V_72 ) ;
if ( V_28 -> V_68 == V_177 ) {
V_28 -> V_68 = V_69 ;
V_40 = V_28 -> V_34 -> V_67 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
V_40 -> V_56 = V_28 ;
V_7 = F_23 ( V_40 , V_15 ) ;
} else {
V_28 -> V_68 = V_69 ;
F_32 ( & V_28 -> V_29 , V_72 ) ;
}
return V_7 ;
}
static int F_25 ( struct V_3 * V_4 , V_43 V_214 ,
T_1 V_215 , T_1 V_216 , V_43 * V_76 , int V_184 )
{
int V_7 ;
V_7 = F_89 ( V_4 -> V_18 -> V_6 ,
F_90 ( V_4 -> V_18 -> V_6 , 0 ) , V_214 ,
( V_217 | V_218 | V_219 ) ,
V_216 , V_215 , V_76 , V_184 , 1000 ) ;
if ( V_7 == V_184 )
V_7 = 0 ;
if ( V_7 > 0 )
V_7 = - V_220 ;
return V_7 ;
}
static int F_80 ( struct V_3 * V_4 , V_43 V_214 ,
T_1 V_215 , T_1 V_216 , V_43 * V_76 , int V_184 )
{
int V_7 ;
V_7 = F_89 ( V_4 -> V_18 -> V_6 ,
F_91 ( V_4 -> V_18 -> V_6 , 0 ) , V_214 ,
( V_217 | V_218 | V_221 ) ,
V_216 , V_215 , V_76 , V_184 , 1000 ) ;
if ( V_7 == V_184 )
V_7 = 0 ;
if ( V_7 > 0 )
V_7 = - V_220 ;
return V_7 ;
}
static int F_62 ( struct V_25 * V_26 ,
struct V_3 * V_4 , unsigned long V_222 ,
V_43 V_223 , V_43 V_224 )
{
int V_7 ;
unsigned int V_184 ;
struct V_225 * V_76 ;
F_2 ( & V_26 -> V_6 , L_56 , V_8 ,
V_222 , V_223 , V_224 ) ;
V_184 = sizeof( struct V_225 ) + 2 ;
V_76 = F_51 ( V_184 , V_15 ) ;
if ( ! V_76 )
return - V_16 ;
V_76 -> V_226 = V_227 ;
V_76 -> V_228 = V_229 ;
V_76 -> V_230 = 1 ;
V_76 -> V_231 = F_92 ( V_222 >> 16 ) ;
V_76 -> V_232 = F_92 ( V_222 ) ;
V_76 -> V_233 [ 0 ] = V_223 ;
V_76 -> V_233 [ 1 ] = V_224 ;
V_7 = F_25 ( V_4 , V_234 , V_235 , 0 ,
( V_43 * ) V_76 , V_184 ) ;
if ( V_7 < 0 )
F_22 ( & V_26 -> V_6 , L_57 , V_8 , V_7 ) ;
F_11 ( V_76 ) ;
return V_7 ;
}
static int F_93 ( struct V_5 * V_6 , int V_66 ,
T_2 * V_236 , int V_184 )
{
int V_237 ;
T_2 V_238 = 0 ;
int V_239 ;
struct V_240 * V_241 ;
int V_7 = 0 ;
int V_242 ;
for ( V_237 = sizeof( struct V_240 ) ; V_237 < V_184 ; V_237 ++ )
V_238 = ( V_43 ) ( V_238 + V_236 [ V_237 ] ) ;
V_241 = (struct V_240 * ) V_236 ;
V_241 -> V_243 = F_94 ( ( T_1 ) ( V_184
- sizeof( struct V_240 ) ) ) ;
V_241 -> V_244 = V_238 ;
F_2 ( & V_6 -> V_6 , L_58 , V_8 ) ;
for ( V_237 = 0 ; V_237 < V_184 ; V_237 += V_239 ) {
V_242 = F_95 ( V_184 - V_237 , V_245 ) ;
V_7 = F_96 ( V_6 , V_66 , V_236 + V_237 , V_242 ,
& V_239 , 1000 ) ;
if ( V_7 )
break;
}
return V_7 ;
}
static int F_7 ( struct V_3 * V_4 )
{
int V_7 ;
int V_246 ;
V_43 * V_236 ;
struct V_5 * V_6 = V_4 -> V_18 -> V_6 ;
unsigned int V_66 = F_78 ( V_6 ,
V_4 -> V_18 -> V_26 [ 0 ] -> V_181 ) ;
const struct V_247 * V_248 ;
char V_249 [ 32 ] ;
sprintf ( V_249 , L_59 ,
F_3 ( V_6 -> V_9 . V_250 ) ,
F_3 ( V_6 -> V_9 . V_10 ) ) ;
V_7 = F_97 ( & V_248 , V_249 , & V_6 -> V_6 ) ;
if ( V_7 != 0 ) {
V_249 [ 0 ] = '\0' ;
if ( F_3 ( V_6 -> V_9 . V_250 ) == V_251 ) {
switch ( F_3 ( V_6 -> V_9 . V_10 ) ) {
case V_252 :
strcpy ( V_249 , L_60 ) ;
break;
case V_253 :
strcpy ( V_249 , L_61 ) ;
break;
case V_254 :
strcpy ( V_249 , L_62 ) ;
break;
case V_255 :
strcpy ( V_249 , L_63 ) ;
break;
case V_256 :
strcpy ( V_249 , L_64 ) ;
break;
case V_257 :
strcpy ( V_249 , L_64 ) ;
break; }
}
if ( V_249 [ 0 ] == '\0' ) {
if ( V_4 -> V_20 )
strcpy ( V_249 , L_65 ) ;
else
strcpy ( V_249 , L_66 ) ;
}
V_7 = F_97 ( & V_248 , V_249 , & V_6 -> V_6 ) ;
}
if ( V_7 ) {
F_22 ( & V_6 -> V_6 , L_67 , V_8 ) ;
return - V_165 ;
}
if ( V_248 -> V_184 > V_258 ) {
F_22 ( & V_6 -> V_6 , L_68 , V_8 , V_248 -> V_184 ) ;
F_98 ( V_248 ) ;
return - V_165 ;
}
V_246 = V_258 + sizeof( struct V_240 ) ;
V_236 = F_51 ( V_246 , V_15 ) ;
if ( V_236 ) {
memcpy ( V_236 , V_248 -> V_76 , V_248 -> V_184 ) ;
memset ( V_236 + V_248 -> V_184 , 0xff , V_246 - V_248 -> V_184 ) ;
V_7 = F_93 ( V_6 , V_66 , V_236 , V_248 -> V_184 ) ;
F_11 ( V_236 ) ;
} else {
V_7 = - V_16 ;
}
F_98 ( V_248 ) ;
if ( V_7 ) {
F_22 ( & V_6 -> V_6 , L_69 ,
V_8 , V_7 ) ;
return V_7 ;
}
F_2 ( & V_6 -> V_6 , L_70 , V_8 ) ;
return 0 ;
}
