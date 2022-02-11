static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_7 , V_8 ;
if ( V_4 -> V_9 )
return - V_10 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 >= 0 )
return V_8 ;
V_7 = V_2 -> V_11 & V_12 ||
! ( F_4 ( V_6 -> V_13 + F_5 ( V_6 ) ) &
V_14 ) ;
if ( V_2 -> V_15 & V_16 )
V_7 = ! V_7 ;
return V_7 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_17 , V_18 ;
int V_8 ;
V_8 = F_7 ( V_6 -> V_13 ) ;
if ( V_8 )
return V_8 ;
V_17 = V_19 ;
V_18 = F_8 ( 0x3 , V_20 ) |
F_8 ( 0x7 , V_21 ) |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 ;
F_9 ( F_8 ( 0xffff , V_29 ) |
F_8 ( 2 , V_30 ) |
F_8 ( 0 , V_31 ) ,
V_6 -> V_13 + F_10 ( V_6 ) ) ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_18 |= V_34 ;
}
F_9 ( V_17 , V_6 -> V_13 + V_35 ) ;
F_9 ( V_18 , V_6 -> V_13 + F_11 ( V_6 ) ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( F_13 ( V_37 ) & V_42 ) {
if ( F_13 ( V_37 ) & V_43 ) {
V_37 -> V_44 [ 3 ] = F_4 ( V_6 -> V_13 + F_14 ( V_6 ) ) ;
V_37 -> V_44 [ 2 ] = F_4 ( V_6 -> V_13 + F_15 ( V_6 ) ) ;
V_37 -> V_44 [ 1 ] = F_4 ( V_6 -> V_13 + F_16 ( V_6 ) ) ;
V_37 -> V_44 [ 0 ] = F_4 ( V_6 -> V_13 + F_17 ( V_6 ) ) ;
} else {
V_37 -> V_44 [ 0 ] = F_4 ( V_6 -> V_13 + F_14 ( V_6 ) ) ;
}
}
if ( V_39 ) {
F_18 ( F_19 ( V_4 -> V_2 ) , V_39 -> V_45 ,
V_39 -> V_46 , V_6 -> V_47 ) ;
if ( ! V_39 -> error )
V_39 -> V_48 = V_39 -> V_49 * V_39 -> V_50 ;
else
V_39 -> V_48 = 0 ;
V_4 -> V_39 = NULL ;
if ( V_41 -> V_51 ) {
F_20 ( V_4 , V_41 -> V_51 ) ;
return;
}
}
V_4 -> V_41 = NULL ;
F_21 ( V_4 -> V_2 , V_41 ) ;
}
static void F_22 ( void * V_52 )
{
struct V_3 * V_4 = V_52 ;
F_12 ( V_4 ) ;
}
static T_2 F_23 ( int V_53 , void * V_54 )
{
struct V_3 * V_4 = V_54 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_55 ;
F_24 ( & V_4 -> V_56 ) ;
V_55 = F_4 ( V_6 -> V_13 + F_11 ( V_6 ) ) ;
F_9 ( V_55 & V_57 ,
V_6 -> V_13 + F_11 ( V_6 ) + V_58 ) ;
F_25 ( & V_4 -> V_56 ) ;
if ( ( V_55 & V_59 ) && ( V_55 & V_34 ) )
F_26 ( V_4 -> V_2 ) ;
if ( V_55 & V_60 )
V_37 -> error = - V_61 ;
else if ( V_55 & V_62 )
V_37 -> error = - V_63 ;
if ( V_39 ) {
if ( V_55 & ( V_64 |
V_65 ) )
V_39 -> error = - V_61 ;
else if ( V_55 & V_66 )
V_39 -> error = - V_67 ;
else if ( V_55 & ( V_68 |
V_69 ) )
V_39 -> error = - V_63 ;
}
return V_70 ;
}
static struct V_71 * F_27 (
struct V_3 * V_4 , unsigned long V_72 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_71 * V_73 ;
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_74 * V_75 ;
unsigned int V_46 ;
if ( V_39 ) {
F_28 ( F_19 ( V_4 -> V_2 ) , V_39 -> V_45 ,
V_39 -> V_46 , V_6 -> V_47 ) ;
V_75 = V_39 -> V_45 ;
V_46 = V_39 -> V_46 ;
} else {
V_75 = (struct V_74 * ) V_6 -> V_76 ;
V_46 = V_77 ;
}
V_73 = F_29 ( V_6 -> V_78 ,
V_75 , V_46 , V_6 -> V_79 , V_72 ) ;
if ( V_73 ) {
V_73 -> V_80 = F_22 ;
V_73 -> V_81 = V_4 ;
} else {
if ( V_39 )
F_18 ( F_19 ( V_4 -> V_2 ) , V_39 -> V_45 ,
V_39 -> V_46 , V_6 -> V_47 ) ;
}
return V_73 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_71 * V_73 ;
T_1 V_17 , V_82 , V_83 ;
V_17 = V_84 | V_19 ;
V_82 = F_8 ( V_37 -> V_85 , V_86 ) | V_87 ;
V_83 = V_37 -> V_88 ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_82 |= V_89 | V_90 ;
}
V_6 -> V_76 [ 0 ] = V_17 ;
V_6 -> V_76 [ 1 ] = V_82 ;
V_6 -> V_76 [ 2 ] = V_83 ;
V_6 -> V_47 = V_91 ;
V_6 -> V_79 = V_92 ;
V_73 = F_27 ( V_4 , V_93 ) ;
if ( ! V_73 )
goto V_94;
F_31 ( V_73 ) ;
F_32 ( V_6 -> V_78 ) ;
return;
V_94:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_95 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_71 * V_73 ;
T_1 V_96 , V_97 , V_98 ;
T_1 V_17 , V_82 , V_83 ;
V_96 = ( F_13 ( V_37 ) & V_99 ) ?
0 : V_19 ;
V_97 = ( F_13 ( V_37 ) & V_42 ) ?
V_100 : 0 ;
V_98 = ( F_13 ( V_37 ) & V_43 ) ?
V_101 : 0 ;
V_17 = V_84 | V_96 | V_97 | V_98 ;
V_82 = F_8 ( V_37 -> V_85 , V_86 ) ;
V_83 = V_37 -> V_88 ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_82 |= V_89 | V_90 ;
}
V_6 -> V_76 [ 0 ] = V_17 ;
V_6 -> V_76 [ 1 ] = V_82 ;
V_6 -> V_76 [ 2 ] = V_83 ;
V_6 -> V_47 = V_91 ;
V_6 -> V_79 = V_92 ;
V_73 = F_27 ( V_4 , V_93 ) ;
if ( ! V_73 )
goto V_94;
F_31 ( V_73 ) ;
F_32 ( V_6 -> V_78 ) ;
return;
V_94:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_95 ) ;
}
static unsigned short F_35 ( unsigned V_102 , unsigned V_103 )
{
const unsigned int V_104 = 4096 ;
const unsigned int V_105 = V_102 / 1000 ;
const unsigned int V_106 = V_103 / 1000 ;
const unsigned int V_107 = V_106 * V_105 ;
const unsigned int V_108 = V_107 / V_104 ;
F_36 ( V_108 == 0 ) ;
return V_108 ;
}
static void F_37 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_71 * V_73 ;
struct V_74 * V_75 = V_39 -> V_45 , * V_45 ;
unsigned int V_46 = V_39 -> V_46 ;
unsigned int V_109 ;
unsigned short V_110 , V_111 ;
enum V_112 V_79 ;
unsigned int V_113 = 0 , V_114 ;
unsigned int V_49 = V_39 -> V_49 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_96 , V_97 , V_98 , V_115 ;
T_1 V_17 , V_82 , V_83 , V_116 ;
V_96 = ( F_13 ( V_37 ) & V_99 ) ?
0 : V_19 ;
V_97 = ( F_13 ( V_37 ) & V_42 ) ?
V_100 : 0 ;
V_98 = ( F_13 ( V_37 ) & V_43 ) ?
V_101 : 0 ;
if ( V_39 -> V_72 & V_117 ) {
V_110 = V_118 ;
V_79 = V_119 ;
V_115 = 0 ;
} else {
V_110 = V_120 ;
V_79 = V_121 ;
V_115 = V_122 ;
}
V_17 = F_8 ( V_4 -> V_123 , V_124 ) |
V_96 | V_97 | V_98 |
V_125 | V_115 |
V_126 |
V_84 ;
V_82 = F_8 ( V_37 -> V_85 , V_86 ) ;
V_114 = F_38 ( V_39 -> V_50 ) ;
F_39 (sgl, sg, sg_len, i)
V_113 += V_45 -> V_127 ;
if ( V_113 != V_39 -> V_49 * V_39 -> V_50 )
V_49 = 1 ;
if ( F_40 ( V_6 ) ) {
V_17 |= F_8 ( V_113 , V_128 ) ;
V_82 |= F_8 ( V_114 , V_129 ) |
F_8 ( V_49 - 1 , V_130 ) ;
} else {
F_9 ( V_113 , V_6 -> V_13 + V_131 ) ;
F_9 ( F_8 ( V_114 , V_132 ) |
F_8 ( V_49 - 1 , V_133 ) ,
V_6 -> V_13 + V_134 ) ;
}
if ( ( V_37 -> V_85 == V_135 ) ||
( V_37 -> V_85 == V_136 ) )
V_82 |= V_87 ;
V_83 = V_37 -> V_88 ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_82 |= V_89 | V_90 ;
}
V_111 = F_35 ( V_6 -> V_137 , V_39 -> V_138 ) ;
V_116 = F_4 ( V_6 -> V_13 + F_10 ( V_6 ) ) ;
V_116 &= ~ ( V_139 ) ;
V_116 |= F_8 ( V_111 , V_29 ) ;
F_9 ( V_116 , V_6 -> V_13 + F_10 ( V_6 ) ) ;
V_6 -> V_76 [ 0 ] = V_17 ;
V_6 -> V_76 [ 1 ] = V_82 ;
V_6 -> V_76 [ 2 ] = V_83 ;
V_6 -> V_47 = V_91 ;
V_6 -> V_79 = V_92 ;
V_73 = F_27 ( V_4 , 0 ) ;
if ( ! V_73 )
goto V_94;
F_36 ( V_4 -> V_39 != NULL ) ;
V_4 -> V_39 = V_39 ;
V_6 -> V_47 = V_110 ;
V_6 -> V_79 = V_79 ;
V_73 = F_27 ( V_4 , V_140 | V_93 ) ;
if ( ! V_73 )
goto V_94;
F_31 ( V_73 ) ;
F_32 ( V_6 -> V_78 ) ;
return;
V_94:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_95 ) ;
}
static void F_20 ( struct V_3 * V_4 ,
struct V_36 * V_37 )
{
V_4 -> V_37 = V_37 ;
switch ( F_41 ( V_37 ) ) {
case V_141 :
F_30 ( V_4 ) ;
break;
case V_142 :
F_34 ( V_4 ) ;
break;
case V_143 :
F_34 ( V_4 ) ;
break;
case V_144 :
F_37 ( V_4 ) ;
break;
default:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_2 , V_95 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( V_4 -> V_41 != NULL ) ;
V_4 -> V_41 = V_41 ;
F_20 ( V_4 , V_41 -> V_37 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_145 * V_146 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_146 -> V_123 == V_147 )
V_4 -> V_123 = 2 ;
else if ( V_146 -> V_123 == V_148 )
V_4 -> V_123 = 1 ;
else
V_4 -> V_123 = 0 ;
if ( V_146 -> clock )
F_44 ( & V_4 -> V_6 , V_146 -> clock ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_149 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_72 ;
F_46 ( & V_4 -> V_56 , V_72 ) ;
V_4 -> V_32 = V_149 ;
if ( V_149 ) {
F_9 ( V_33 ,
V_6 -> V_13 + V_35 + V_150 ) ;
F_9 ( V_34 ,
V_6 -> V_13 + F_11 ( V_6 ) + V_150 ) ;
} else {
F_9 ( V_33 ,
V_6 -> V_13 + V_35 + V_58 ) ;
F_9 ( V_34 ,
V_6 -> V_13 + F_11 ( V_6 ) + V_58 ) ;
}
F_47 ( & V_4 -> V_56 , V_72 ) ;
if ( V_149 && F_4 ( V_6 -> V_13 + F_5 ( V_6 ) ) &
V_151 )
F_26 ( V_4 -> V_2 ) ;
}
static int F_48 ( struct V_152 * V_153 )
{
const struct V_154 * V_155 =
F_49 ( V_156 , & V_153 -> V_157 ) ;
struct V_158 * V_159 = V_153 -> V_157 . V_160 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_161 * V_162 ;
int V_8 = 0 , V_163 ;
struct V_164 * V_165 ;
struct V_5 * V_6 ;
V_163 = F_50 ( V_153 , 0 ) ;
if ( V_163 < 0 )
return V_163 ;
V_2 = F_51 ( sizeof( struct V_3 ) , & V_153 -> V_157 ) ;
if ( ! V_2 )
return - V_166 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_157 = & V_153 -> V_157 ;
V_162 = F_52 ( V_153 , V_167 , 0 ) ;
V_6 -> V_13 = F_53 ( & V_153 -> V_157 , V_162 ) ;
if ( F_54 ( V_6 -> V_13 ) ) {
V_8 = F_55 ( V_6 -> V_13 ) ;
goto V_168;
}
V_6 -> V_169 = (enum V_170 ) V_155 -> V_39 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_32 = 0 ;
V_165 = F_56 ( & V_153 -> V_157 , L_3 ) ;
if ( ! F_54 ( V_165 ) ) {
V_8 = F_57 ( V_165 ) ;
if ( V_8 ) {
F_58 ( & V_153 -> V_157 ,
L_4 , V_8 ) ;
goto V_168;
}
}
V_6 -> V_171 = F_59 ( & V_153 -> V_157 , NULL ) ;
if ( F_54 ( V_6 -> V_171 ) ) {
V_8 = F_55 ( V_6 -> V_171 ) ;
goto V_168;
}
V_8 = F_60 ( V_6 -> V_171 ) ;
if ( V_8 )
goto V_168;
V_8 = F_6 ( V_4 ) ;
if ( V_8 ) {
F_58 ( & V_153 -> V_157 , L_5 , V_8 ) ;
goto V_172;
}
V_6 -> V_78 = F_61 ( & V_153 -> V_157 , L_6 ) ;
if ( ! V_6 -> V_78 ) {
F_58 ( F_19 ( V_4 -> V_2 ) ,
L_7 , V_95 ) ;
V_8 = - V_173 ;
goto V_172;
}
V_2 -> V_174 = & V_175 ;
V_2 -> V_11 = V_176 | V_177 |
V_178 | V_12 ;
V_4 -> V_9 = F_62 ( V_159 , L_8 ) ;
V_2 -> V_179 = 400000 ;
V_2 -> V_180 = 288000000 ;
V_8 = F_63 ( V_2 ) ;
if ( V_8 )
goto V_172;
V_2 -> V_181 = V_182 | V_183 ;
V_2 -> V_184 = 52 ;
V_2 -> V_185 = 1 << 0xf ;
V_2 -> V_186 = ( F_40 ( V_6 ) ) ? 0xff : 0xffffff ;
V_2 -> V_187 = ( F_40 ( V_6 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_188 = F_64 ( V_6 -> V_78 -> V_189 -> V_157 ) ;
F_65 ( V_153 , V_2 ) ;
V_8 = F_66 ( & V_153 -> V_157 , V_163 , F_23 , 0 ,
F_67 ( & V_153 -> V_157 ) , V_4 ) ;
if ( V_8 )
goto V_190;
F_68 ( & V_4 -> V_56 ) ;
V_8 = F_69 ( V_2 ) ;
if ( V_8 )
goto V_190;
F_70 ( F_19 ( V_4 -> V_2 ) , L_9 ) ;
return 0 ;
V_190:
if ( V_6 -> V_78 )
F_71 ( V_6 -> V_78 ) ;
V_172:
F_72 ( V_6 -> V_171 ) ;
V_168:
F_73 ( V_2 ) ;
return V_8 ;
}
static int F_74 ( struct V_152 * V_153 )
{
struct V_1 * V_2 = F_75 ( V_153 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_76 ( V_2 ) ;
if ( V_6 -> V_78 )
F_71 ( V_6 -> V_78 ) ;
F_72 ( V_6 -> V_171 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_189 * V_157 )
{
struct V_1 * V_2 = F_78 ( V_157 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_72 ( V_6 -> V_171 ) ;
return 0 ;
}
static int F_79 ( struct V_189 * V_157 )
{
struct V_1 * V_2 = F_78 ( V_157 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
return F_60 ( V_6 -> V_171 ) ;
}
