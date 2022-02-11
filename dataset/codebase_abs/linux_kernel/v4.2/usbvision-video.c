static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
return F_3 ( V_5 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
return sprintf ( V_9 , L_1 , V_10 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
return sprintf ( V_9 , L_1 ,
V_12 [ V_11 -> V_13 ] . V_14 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
struct V_15 V_16 ;
V_16 . V_17 = V_18 ;
V_16 . V_19 = 0 ;
if ( V_11 -> V_20 )
F_7 ( V_11 , V_21 , V_22 , & V_16 ) ;
return sprintf ( V_9 , L_2 , V_16 . V_19 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
struct V_15 V_16 ;
V_16 . V_17 = V_23 ;
V_16 . V_19 = 0 ;
if ( V_11 -> V_20 )
F_7 ( V_11 , V_21 , V_22 , & V_16 ) ;
return sprintf ( V_9 , L_2 , V_16 . V_19 ) ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
struct V_15 V_16 ;
V_16 . V_17 = V_24 ;
V_16 . V_19 = 0 ;
if ( V_11 -> V_20 )
F_7 ( V_11 , V_21 , V_22 , & V_16 ) ;
return sprintf ( V_9 , L_2 , V_16 . V_19 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
struct V_15 V_16 ;
V_16 . V_17 = V_25 ;
V_16 . V_19 = 0 ;
if ( V_11 -> V_20 )
F_7 ( V_11 , V_21 , V_22 , & V_16 ) ;
return sprintf ( V_9 , L_2 , V_16 . V_19 ) ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
return sprintf ( V_9 , L_1 ,
F_12 ( V_11 -> V_26 == V_27 ? 1 : 0 ) ) ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
return sprintf ( V_9 , L_1 ,
F_12 ( V_11 -> V_28 == V_29 ) ) ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_6 ) ;
struct V_1 * V_11 = F_3 ( V_5 ) ;
return sprintf ( V_9 , L_2 , V_11 -> V_30 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
int V_31 ;
if ( ! V_5 )
return;
do {
V_31 = F_16 ( & V_5 -> V_6 , & V_32 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_33 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_34 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_35 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_36 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_37 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_38 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_39 ) ;
if ( V_31 < 0 )
break;
V_31 = F_16 ( & V_5 -> V_6 , & V_40 ) ;
if ( V_31 >= 0 )
return;
} while ( 0 );
F_17 ( & V_5 -> V_6 , L_3 , V_41 , V_31 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
if ( V_5 ) {
F_19 ( & V_5 -> V_6 , & V_32 ) ;
F_19 ( & V_5 -> V_6 , & V_33 ) ;
F_19 ( & V_5 -> V_6 , & V_34 ) ;
F_19 ( & V_5 -> V_6 , & V_35 ) ;
F_19 ( & V_5 -> V_6 , & V_36 ) ;
F_19 ( & V_5 -> V_6 , & V_37 ) ;
F_19 ( & V_5 -> V_6 , & V_38 ) ;
F_19 ( & V_5 -> V_6 , & V_39 ) ;
F_19 ( & V_5 -> V_6 , & V_40 ) ;
}
}
static int F_20 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_4 ) ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
F_24 ( V_11 ) ;
if ( V_11 -> V_20 )
V_43 = - V_47 ;
else {
V_43 = F_25 ( V_11 ) ;
if ( V_28 == V_29 ) {
V_43 = F_26 ( V_11 ) ;
}
if ( V_43 ) {
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
}
}
if ( ! V_43 ) {
if ( V_11 -> V_48 == 0 ) {
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
}
if ( ! V_11 -> V_49 ) {
int V_50 = 0 ;
V_50 = F_31 ( V_11 , V_28 ) ;
if ( V_50 )
V_11 -> V_49 = 1 ;
else
V_43 = - V_47 ;
}
if ( ! V_43 ) {
F_32 ( V_11 ) ;
V_43 = F_33 ( V_11 ) ;
F_34 ( V_11 , 0 ) ;
V_11 -> V_20 ++ ;
} else {
if ( V_51 ) {
F_35 ( V_11 ) ;
F_36 ( V_11 ) ;
V_11 -> V_49 = 0 ;
}
}
}
F_37 ( V_11 ) ;
F_38 ( & V_11 -> V_45 ) ;
F_22 ( V_44 , L_5 ) ;
return V_43 ;
}
static int F_39 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_22 ( V_44 , L_6 ) ;
F_40 ( & V_11 -> V_45 ) ;
F_41 ( V_11 ) ;
F_42 ( V_11 ) ;
F_43 ( V_11 ) ;
F_28 ( V_11 ) ;
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
F_27 ( V_11 ) ;
V_11 -> V_20 -- ;
if ( V_51 ) {
F_45 ( V_11 ) ;
V_11 -> V_49 = 0 ;
}
if ( V_11 -> V_52 ) {
F_46 ( V_53 L_7 , V_41 ) ;
F_47 ( V_11 ) ;
return 0 ;
}
F_38 ( & V_11 -> V_45 ) ;
F_22 ( V_44 , L_5 ) ;
return 0 ;
}
static int F_48 ( struct V_42 * V_42 , void * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 ;
V_43 = F_49 ( V_11 , V_56 -> V_56 & 0xff ) ;
if ( V_43 < 0 ) {
F_17 ( & V_11 -> V_5 . V_6 ,
L_8 ,
V_41 , V_43 ) ;
return V_43 ;
}
V_56 -> V_57 = V_43 ;
V_56 -> V_58 = 1 ;
return 0 ;
}
static int F_50 ( struct V_42 * V_42 , void * V_54 ,
const struct V_55 * V_56 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 ;
V_43 = F_51 ( V_11 , V_56 -> V_56 & 0xff , V_56 -> V_57 ) ;
if ( V_43 < 0 ) {
F_17 ( & V_11 -> V_5 . V_6 ,
L_9 ,
V_41 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_52 ( struct V_42 * V_42 , void * V_54 ,
struct V_59 * V_60 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_53 ( V_60 -> V_61 , L_10 , sizeof( V_60 -> V_61 ) ) ;
F_53 ( V_60 -> V_62 ,
V_12 [ V_11 -> V_13 ] . V_14 ,
sizeof( V_60 -> V_62 ) ) ;
F_54 ( V_11 -> V_6 , V_60 -> V_63 , sizeof( V_60 -> V_63 ) ) ;
V_60 -> V_64 = V_65 |
V_66 |
V_67 |
V_68 |
( V_11 -> V_69 ? V_70 : 0 ) ;
V_60 -> V_71 = V_60 -> V_64 | V_72 ;
return 0 ;
}
static int F_55 ( struct V_42 * V_42 , void * V_54 ,
struct V_73 * V_74 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_75 ;
if ( V_74 -> V_76 >= V_11 -> V_77 )
return - V_78 ;
if ( V_11 -> V_69 )
V_75 = V_74 -> V_76 ;
else
V_75 = V_74 -> V_76 + 1 ;
switch ( V_75 ) {
case 0 :
if ( V_12 [ V_11 -> V_13 ] . V_79 == 4 ) {
strcpy ( V_74 -> V_80 , L_11 ) ;
} else {
strcpy ( V_74 -> V_80 , L_12 ) ;
V_74 -> type = V_81 ;
V_74 -> V_82 = 1 ;
V_74 -> V_83 = V_75 ;
V_74 -> V_84 = V_85 ;
}
break;
case 1 :
V_74 -> type = V_86 ;
if ( V_12 [ V_11 -> V_13 ] . V_79 == 4 )
strcpy ( V_74 -> V_80 , L_13 ) ;
else
strcpy ( V_74 -> V_80 , L_14 ) ;
V_74 -> V_84 = V_87 ;
break;
case 2 :
V_74 -> type = V_86 ;
if ( V_12 [ V_11 -> V_13 ] . V_79 == 4 )
strcpy ( V_74 -> V_80 , L_15 ) ;
else
strcpy ( V_74 -> V_80 , L_16 ) ;
V_74 -> V_84 = V_87 ;
break;
case 3 :
V_74 -> type = V_86 ;
strcpy ( V_74 -> V_80 , L_17 ) ;
V_74 -> V_84 = V_87 ;
break;
}
return 0 ;
}
static int F_56 ( struct V_42 * V_42 , void * V_54 , unsigned int * V_88 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
* V_88 = V_11 -> V_89 ;
return 0 ;
}
static int F_57 ( struct V_42 * V_42 , void * V_54 , unsigned int V_88 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_88 >= V_11 -> V_77 )
return - V_78 ;
F_34 ( V_11 , V_88 ) ;
F_58 ( V_11 ) ;
F_59 ( V_11 ,
V_11 -> V_90 ,
V_11 -> V_91 ) ;
return 0 ;
}
static int F_60 ( struct V_42 * V_42 , void * V_54 , T_2 V_17 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_92 = V_17 ;
F_7 ( V_11 , V_93 , V_94 , V_11 -> V_92 ) ;
F_34 ( V_11 , V_11 -> V_89 ) ;
return 0 ;
}
static int F_61 ( struct V_42 * V_42 , void * V_54 , T_2 * V_17 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
* V_17 = V_11 -> V_92 ;
return 0 ;
}
static int F_62 ( struct V_42 * V_42 , void * V_54 ,
struct V_95 * V_96 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_96 -> V_76 )
return - V_78 ;
if ( V_11 -> V_97 ) {
strcpy ( V_96 -> V_80 , L_18 ) ;
V_96 -> type = V_98 ;
} else {
strcpy ( V_96 -> V_80 , L_12 ) ;
}
F_7 ( V_11 , V_83 , V_99 , V_96 ) ;
return 0 ;
}
static int F_63 ( struct V_42 * V_42 , void * V_54 ,
const struct V_95 * V_96 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_96 -> V_76 )
return - V_78 ;
F_7 ( V_11 , V_83 , V_100 , V_96 ) ;
return 0 ;
}
static int F_64 ( struct V_42 * V_42 , void * V_54 ,
struct V_101 * V_102 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_102 -> V_83 = 0 ;
if ( V_11 -> V_97 )
V_102 -> type = V_98 ;
else
V_102 -> type = V_103 ;
V_102 -> V_104 = V_11 -> V_102 ;
return 0 ;
}
static int F_65 ( struct V_42 * V_42 , void * V_54 ,
const struct V_101 * V_102 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_102 -> V_83 )
return - V_78 ;
V_11 -> V_102 = V_102 -> V_104 ;
F_7 ( V_11 , V_83 , V_105 , V_102 ) ;
return 0 ;
}
static int F_66 ( struct V_42 * V_42 , void * V_54 , struct V_106 * V_107 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_11 -> V_97 )
strcpy ( V_107 -> V_80 , L_18 ) ;
else
strcpy ( V_107 -> V_80 , L_19 ) ;
return 0 ;
}
static int F_67 ( struct V_42 * V_42 , void * V_108 ,
const struct V_106 * V_107 )
{
if ( V_107 -> V_76 )
return - V_78 ;
return 0 ;
}
static int F_68 ( struct V_42 * V_42 , void * V_54 ,
struct V_109 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_110 , V_16 ) ;
if ( ! V_16 -> type )
return - V_78 ;
return 0 ;
}
static int F_69 ( struct V_42 * V_42 , void * V_54 ,
struct V_15 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_22 , V_16 ) ;
return 0 ;
}
static int F_70 ( struct V_42 * V_42 , void * V_54 ,
struct V_15 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_111 , V_16 ) ;
return 0 ;
}
static int F_71 ( struct V_42 * V_42 ,
void * V_54 , struct V_112 * V_113 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_114 ;
F_72 ( V_113 -> V_115 , 1 , V_116 ) ;
if ( V_113 -> V_117 != V_118 )
return - V_78 ;
if ( V_11 -> V_26 == V_27 ) {
V_114 = F_73 ( V_11 ) ;
if ( V_114 )
return V_114 ;
}
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
V_113 -> V_115 = F_74 ( V_11 , V_113 -> V_115 ) ;
V_11 -> V_119 = NULL ;
return 0 ;
}
static int F_75 ( struct V_42 * V_42 ,
void * V_54 , struct V_120 * V_121 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_122 * V_123 ;
if ( V_121 -> V_76 >= V_11 -> V_124 )
return - V_78 ;
V_121 -> V_125 = V_126 ;
V_123 = & V_11 -> V_123 [ V_121 -> V_76 ] ;
if ( V_123 -> V_127 >= V_128 )
V_121 -> V_125 |= V_129 ;
if ( V_123 -> V_127 >= V_130 )
V_121 -> V_125 |= V_131 ;
if ( V_123 -> V_127 == V_132 )
V_121 -> V_125 |= V_133 ;
V_121 -> V_117 = V_118 ;
V_121 -> V_134 . V_135 = V_121 -> V_76 * F_76 ( V_11 -> V_136 ) ;
V_121 -> V_117 = V_118 ;
V_121 -> V_137 = V_138 ;
V_121 -> V_139 = V_11 -> V_90 *
V_11 -> V_91 *
V_11 -> V_140 . V_141 ;
V_121 -> V_142 = V_11 -> V_123 [ V_121 -> V_76 ] . V_142 ;
V_121 -> V_143 = V_11 -> V_123 [ V_121 -> V_76 ] . V_143 ;
return 0 ;
}
static int F_77 ( struct V_42 * V_42 , void * V_54 , struct V_120 * V_121 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_122 * V_123 ;
unsigned long V_144 ;
if ( V_121 -> V_76 >= V_11 -> V_124 )
return - V_78 ;
V_123 = & V_11 -> V_123 [ V_121 -> V_76 ] ;
if ( V_123 -> V_127 != V_132 )
return - V_145 ;
V_123 -> V_127 = V_128 ;
V_123 -> V_146 = V_147 ;
V_123 -> V_148 = 0 ;
V_121 -> V_125 &= ~ V_131 ;
V_123 -> V_149 = V_11 -> V_140 ;
F_78 ( & V_11 -> V_150 , V_144 ) ;
F_79 ( & V_11 -> V_123 [ V_121 -> V_76 ] . V_123 , & V_11 -> V_151 ) ;
F_80 ( & V_11 -> V_150 , V_144 ) ;
return 0 ;
}
static int F_81 ( struct V_42 * V_42 , void * V_54 , struct V_120 * V_121 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_114 ;
struct V_122 * V_152 ;
unsigned long V_144 ;
if ( F_82 ( & ( V_11 -> V_153 ) ) ) {
if ( V_11 -> V_26 == V_154 )
return - V_78 ;
V_114 = F_83
( V_11 -> V_155 ,
! F_82 ( & ( V_11 -> V_153 ) ) ) ;
if ( V_114 )
return V_114 ;
}
F_78 ( & V_11 -> V_150 , V_144 ) ;
V_152 = F_84 ( V_11 -> V_153 . V_156 ,
struct V_122 , V_123 ) ;
F_85 ( V_11 -> V_153 . V_156 ) ;
F_80 ( & V_11 -> V_150 , V_144 ) ;
V_152 -> V_127 = V_132 ;
V_121 -> V_117 = V_118 ;
V_121 -> V_125 = V_133 |
V_129 |
V_131 |
V_126 ;
V_121 -> V_76 = V_152 -> V_76 ;
V_121 -> V_143 = V_152 -> V_143 ;
V_121 -> V_142 = V_152 -> V_142 ;
V_121 -> V_137 = V_138 ;
V_121 -> V_157 = V_152 -> V_148 ;
return 0 ;
}
static int F_86 ( struct V_42 * V_42 , void * V_54 , enum V_158 V_159 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_93 , V_160 , 1 ) ;
return 0 ;
}
static int F_87 ( struct V_42 * V_42 ,
void * V_54 , enum V_158 type )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( type != V_161 )
return - V_78 ;
if ( V_11 -> V_26 == V_27 ) {
F_73 ( V_11 ) ;
F_7 ( V_11 , V_93 , V_160 , 0 ) ;
}
F_37 ( V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_42 * V_42 , void * V_54 ,
struct V_162 * V_163 )
{
if ( V_163 -> V_76 >= V_164 - 1 )
return - V_78 ;
strcpy ( V_163 -> V_165 , V_166 [ V_163 -> V_76 ] . V_167 ) ;
V_163 -> V_168 = V_166 [ V_163 -> V_76 ] . V_169 ;
return 0 ;
}
static int F_89 ( struct V_42 * V_42 , void * V_54 ,
struct V_149 * V_170 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_170 -> V_171 . V_172 . V_173 = V_11 -> V_90 ;
V_170 -> V_171 . V_172 . V_174 = V_11 -> V_91 ;
V_170 -> V_171 . V_172 . V_168 = V_11 -> V_140 . V_169 ;
V_170 -> V_171 . V_172 . V_175 =
V_11 -> V_90 * V_11 -> V_140 . V_141 ;
V_170 -> V_171 . V_172 . V_176 = V_170 -> V_171 . V_172 . V_175 * V_11 -> V_91 ;
V_170 -> V_171 . V_172 . V_177 = V_178 ;
V_170 -> V_171 . V_172 . V_137 = V_138 ;
return 0 ;
}
static int F_90 ( struct V_42 * V_42 , void * V_54 ,
struct V_149 * V_170 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_179 ;
for ( V_179 = 0 ; V_179 < V_164 ; V_179 ++ ) {
if ( V_170 -> V_171 . V_172 . V_168 ==
V_166 [ V_179 ] . V_169 ) {
V_11 -> V_140 = V_166 [ V_179 ] ;
break;
}
}
if ( V_179 == V_164 )
return - V_78 ;
F_72 ( V_170 -> V_171 . V_172 . V_173 , V_180 , V_181 ) ;
F_72 ( V_170 -> V_171 . V_172 . V_174 , V_182 , V_183 ) ;
V_170 -> V_171 . V_172 . V_175 = V_170 -> V_171 . V_172 . V_173 *
V_11 -> V_140 . V_141 ;
V_170 -> V_171 . V_172 . V_176 = V_170 -> V_171 . V_172 . V_175 * V_170 -> V_171 . V_172 . V_174 ;
return 0 ;
}
static int F_91 ( struct V_42 * V_42 , void * V_54 ,
struct V_149 * V_170 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_114 ;
V_114 = F_90 ( V_42 , V_54 , V_170 ) ;
if ( V_114 )
return V_114 ;
if ( V_11 -> V_26 == V_27 ) {
V_114 = F_73 ( V_11 ) ;
if ( V_114 )
return V_114 ;
}
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
V_11 -> V_119 = NULL ;
F_59 ( V_11 , V_170 -> V_171 . V_172 . V_173 , V_170 -> V_171 . V_172 . V_174 ) ;
return 0 ;
}
static T_1 F_92 ( struct V_42 * V_42 , char T_3 * V_9 ,
T_4 V_115 , T_5 * V_184 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_185 = V_42 -> V_186 & V_187 ;
unsigned long V_144 ;
int V_114 , V_159 ;
struct V_122 * V_123 ;
F_22 ( V_44 , L_20 , V_41 ,
( unsigned long ) V_115 , V_185 ) ;
if ( ! F_93 ( V_11 ) || ( V_9 == NULL ) )
return - V_188 ;
if ( ! V_11 -> V_124 ) {
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
F_74 ( V_11 , V_116 ) ;
}
if ( V_11 -> V_26 != V_27 ) {
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_93 , V_160 , 1 ) ;
}
for ( V_159 = 0 ; V_159 < V_11 -> V_124 ; V_159 ++ ) {
V_123 = & V_11 -> V_123 [ V_159 ] ;
if ( V_123 -> V_127 == V_132 ) {
V_123 -> V_127 = V_128 ;
V_123 -> V_146 = V_147 ;
V_123 -> V_148 = 0 ;
V_123 -> V_149 = V_11 -> V_140 ;
F_78 ( & V_11 -> V_150 , V_144 ) ;
F_79 ( & V_123 -> V_123 , & V_11 -> V_151 ) ;
F_80 ( & V_11 -> V_150 ,
V_144 ) ;
}
}
if ( F_82 ( & ( V_11 -> V_153 ) ) ) {
if ( V_185 )
return - V_145 ;
V_114 = F_83
( V_11 -> V_155 ,
! F_82 ( & ( V_11 -> V_153 ) ) ) ;
if ( V_114 )
return V_114 ;
}
F_78 ( & V_11 -> V_150 , V_144 ) ;
V_123 = F_84 ( V_11 -> V_153 . V_156 ,
struct V_122 , V_123 ) ;
F_85 ( V_11 -> V_153 . V_156 ) ;
F_80 ( & V_11 -> V_150 , V_144 ) ;
if ( V_123 -> V_127 == V_189 ) {
V_123 -> V_190 = 0 ;
return 0 ;
}
F_22 ( V_44 , L_21 ,
V_41 ,
V_123 -> V_76 , V_123 -> V_190 , V_123 -> V_148 ) ;
if ( ( V_115 + V_123 -> V_190 ) > ( unsigned long ) V_123 -> V_148 )
V_115 = V_123 -> V_148 - V_123 -> V_190 ;
if ( F_94 ( V_9 , V_123 -> V_191 + V_123 -> V_190 , V_115 ) )
return - V_188 ;
V_123 -> V_190 += V_115 ;
F_22 ( V_44 , L_22 ,
V_41 ,
( unsigned long ) V_115 , V_123 -> V_190 ) ;
#if 1
V_123 -> V_190 = 0 ;
V_123 -> V_127 = V_132 ;
#else
if ( V_123 -> V_190 >= V_123 -> V_148 ) {
V_123 -> V_190 = 0 ;
V_123 -> V_127 = V_132 ;
}
#endif
return V_115 ;
}
static T_1 F_95 ( struct V_42 * V_42 , char T_3 * V_9 ,
T_4 V_115 , T_5 * V_184 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_31 ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
V_31 = F_92 ( V_42 , V_9 , V_115 , V_184 ) ;
F_38 ( & V_11 -> V_45 ) ;
return V_31 ;
}
static int F_96 ( struct V_42 * V_42 , struct V_192 * V_193 )
{
unsigned long V_58 = V_193 -> V_194 - V_193 -> V_195 ,
V_196 = V_193 -> V_195 ;
void * V_197 ;
T_6 V_159 ;
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_22 ( V_198 , L_23 ) ;
if ( ! F_93 ( V_11 ) )
return - V_188 ;
if ( ! ( V_193 -> V_199 & V_200 ) ||
V_58 != F_76 ( V_11 -> V_136 ) ) {
return - V_78 ;
}
for ( V_159 = 0 ; V_159 < V_11 -> V_124 ; V_159 ++ ) {
if ( ( ( F_76 ( V_11 -> V_136 ) * V_159 ) >> V_201 ) ==
V_193 -> V_202 )
break;
}
if ( V_159 == V_11 -> V_124 ) {
F_22 ( V_198 ,
L_24 ) ;
return - V_78 ;
}
V_193 -> V_199 |= V_203 | V_204 | V_205 ;
V_197 = V_11 -> V_123 [ V_159 ] . V_191 ;
while ( V_58 > 0 ) {
if ( F_97 ( V_193 , V_196 , F_98 ( V_197 ) ) ) {
F_22 ( V_198 , L_25 ) ;
return - V_145 ;
}
V_196 += V_206 ;
V_197 += V_206 ;
V_58 -= V_206 ;
}
return 0 ;
}
static int F_99 ( struct V_42 * V_42 , struct V_192 * V_193 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_31 ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
V_31 = F_96 ( V_42 , V_193 ) ;
F_38 ( & V_11 -> V_45 ) ;
return V_31 ;
}
static int F_100 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_26 , V_41 ) ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
if ( V_11 -> V_20 ) {
F_17 ( & V_11 -> V_207 . V_6 ,
L_27 ,
V_41 ) ;
V_43 = - V_47 ;
} else {
if ( V_51 ) {
F_24 ( V_11 ) ;
if ( V_11 -> V_48 == 0 ) {
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
}
}
V_43 = F_101 ( V_11 ) ;
if ( V_43 < 0 ) {
V_11 -> V_208 = V_43 ;
V_43 = - V_47 ;
goto V_209;
}
V_11 -> V_97 = 1 ;
F_7 ( V_11 , V_83 , V_210 ) ;
F_102 ( V_11 , V_211 ) ;
V_11 -> V_20 ++ ;
}
if ( V_43 ) {
if ( V_51 ) {
F_35 ( V_11 ) ;
F_36 ( V_11 ) ;
V_11 -> V_49 = 0 ;
}
}
V_209:
F_38 ( & V_11 -> V_45 ) ;
return V_43 ;
}
static int F_103 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_28 ) ;
F_40 ( & V_11 -> V_45 ) ;
V_11 -> V_212 = 0 ;
V_43 = F_104 ( V_11 -> V_6 , V_11 -> V_213 ,
V_11 -> V_212 ) ;
F_41 ( V_11 ) ;
V_11 -> V_97 = 0 ;
V_11 -> V_20 -- ;
if ( V_51 ) {
F_45 ( V_11 ) ;
V_11 -> V_49 = 0 ;
}
if ( V_11 -> V_52 ) {
F_46 ( V_53 L_7 , V_41 ) ;
F_47 ( V_11 ) ;
return V_43 ;
}
F_38 ( & V_11 -> V_45 ) ;
F_22 ( V_44 , L_5 ) ;
return V_43 ;
}
static void F_105 ( struct V_1 * V_11 ,
struct V_4 * V_5 ,
const struct V_4 * V_214 ,
const char * V_80 )
{
struct V_215 * V_216 = V_11 -> V_6 ;
if ( V_216 == NULL ) {
F_17 ( & V_11 -> V_6 -> V_6 ,
L_29 , V_41 ) ;
return;
}
* V_5 = * V_214 ;
V_5 -> V_217 = & V_11 -> V_45 ;
V_5 -> V_218 = & V_11 -> V_218 ;
snprintf ( V_5 -> V_80 , sizeof( V_5 -> V_80 ) , L_30 , V_80 ) ;
F_106 ( V_5 , V_11 ) ;
}
static void F_107 ( struct V_1 * V_11 )
{
if ( F_108 ( & V_11 -> V_207 ) ) {
F_22 ( V_219 , L_31 ,
F_109 ( & V_11 -> V_207 ) ) ;
F_110 ( & V_11 -> V_207 ) ;
}
if ( F_108 ( & V_11 -> V_5 ) ) {
F_22 ( V_219 , L_31 ,
F_109 ( & V_11 -> V_5 ) ) ;
F_110 ( & V_11 -> V_5 ) ;
}
}
static int F_111 ( struct V_1 * V_11 )
{
F_105 ( V_11 , & V_11 -> V_5 ,
& V_220 , L_32 ) ;
if ( F_112 ( & V_11 -> V_5 , V_221 , V_222 ) < 0 )
goto V_223;
F_46 ( V_53 L_33 ,
V_11 -> V_224 , F_109 ( & V_11 -> V_5 ) ) ;
if ( V_12 [ V_11 -> V_13 ] . V_97 ) {
F_105 ( V_11 , & V_11 -> V_207 ,
& V_225 , L_34 ) ;
if ( F_112 ( & V_11 -> V_207 , V_226 , V_227 ) < 0 )
goto V_223;
F_46 ( V_53 L_35 ,
V_11 -> V_224 , F_109 ( & V_11 -> V_207 ) ) ;
}
return 0 ;
V_223:
F_17 ( & V_11 -> V_6 -> V_6 ,
L_36 ,
V_11 -> V_224 ) ;
F_107 ( V_11 ) ;
return - 1 ;
}
static struct V_1 * F_113 ( struct V_215 * V_6 ,
struct V_228 * V_229 )
{
struct V_1 * V_11 ;
V_11 = F_114 ( sizeof( struct V_1 ) , V_230 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_6 = V_6 ;
if ( F_115 ( & V_229 -> V_6 , & V_11 -> V_218 ) )
goto V_231;
F_116 ( & V_11 -> V_45 ) ;
V_11 -> V_232 = F_117 ( V_233 , V_230 ) ;
if ( V_11 -> V_232 == NULL )
goto V_234;
F_118 ( & V_11 -> V_235 ) ;
F_119 ( V_11 ) ;
return V_11 ;
V_234:
F_120 ( & V_11 -> V_218 ) ;
V_231:
F_121 ( V_11 ) ;
return NULL ;
}
static void F_47 ( struct V_1 * V_11 )
{
F_22 ( V_219 , L_28 ) ;
F_24 ( V_11 ) ;
V_11 -> V_49 = 0 ;
F_18 ( & V_11 -> V_5 ) ;
F_107 ( V_11 ) ;
F_121 ( V_11 -> V_236 ) ;
F_122 ( V_11 -> V_232 ) ;
F_120 ( & V_11 -> V_218 ) ;
F_121 ( V_11 ) ;
F_22 ( V_219 , L_5 ) ;
}
static void F_123 ( struct V_1 * V_11 )
{
int V_237 ;
if ( V_11 == NULL )
return;
V_237 = V_11 -> V_13 ;
V_11 -> V_140 = V_166 [ 2 ] ;
if ( V_12 [ V_11 -> V_13 ] . V_238 ) {
V_11 -> V_239 =
V_12 [ V_11 -> V_13 ] . V_240 ;
} else {
V_11 -> V_239 = 0 ;
}
V_11 -> V_92 = V_12 [ V_237 ] . V_241 ;
V_11 -> V_77 = V_12 [ V_237 ] . V_79 ;
V_11 -> V_89 = 0 ;
if ( V_12 [ V_237 ] . V_242 > 0 )
F_41 ( V_11 ) ;
if ( ! V_51 ) {
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
}
}
static int F_124 ( struct V_228 * V_229 ,
const struct V_243 * V_244 )
{
struct V_215 * V_6 = F_125 ( F_126 ( V_229 ) ) ;
struct V_228 * V_245 ;
T_7 V_246 = V_229 -> V_247 -> V_167 . V_248 ;
const struct V_249 * V_250 ;
struct V_1 * V_11 = NULL ;
const struct V_251 * V_252 ;
int V_237 , V_159 , V_114 ;
F_22 ( V_219 , L_37 ,
V_6 -> V_253 . V_254 ,
V_6 -> V_253 . V_255 , V_246 ) ;
V_237 = V_244 -> V_256 ;
if ( V_237 < 0 || V_237 >= V_257 ) {
F_22 ( V_219 , L_38 , V_237 ) ;
V_114 = - V_258 ;
goto V_259;
}
F_46 ( V_53 L_39 , V_41 ,
V_12 [ V_237 ] . V_14 ) ;
if ( V_12 [ V_237 ] . V_250 >= 0 )
V_250 = & V_6 -> V_260 -> V_250 [ V_12 [ V_237 ] . V_250 ] -> V_247 [ 0 ] ;
else
V_250 = & V_6 -> V_260 -> V_250 [ V_246 ] -> V_247 [ 0 ] ;
V_252 = & V_250 -> V_252 [ 1 ] . V_167 ;
if ( ! F_127 ( V_252 ) ) {
F_17 ( & V_229 -> V_6 , L_40 ,
V_41 , V_246 ) ;
F_17 ( & V_229 -> V_6 , L_41 ,
V_41 , V_252 -> V_261 ) ;
V_114 = - V_258 ;
goto V_259;
}
if ( F_128 ( V_252 ) ) {
F_17 ( & V_229 -> V_6 , L_42 ,
V_41 , V_246 ) ;
V_114 = - V_258 ;
goto V_259;
}
V_11 = F_113 ( V_6 , V_229 ) ;
if ( V_11 == NULL ) {
F_17 ( & V_229 -> V_6 , L_43 , V_41 ) ;
V_114 = - V_262 ;
goto V_259;
}
if ( V_6 -> V_253 . V_263 > 1 )
V_11 -> V_30 = V_264 ;
else if ( V_237 == V_265 )
V_11 -> V_30 = V_266 ;
else
V_11 -> V_30 = V_267 ;
F_22 ( V_219 , L_44 , V_11 -> V_30 ) ;
V_245 = V_6 -> V_260 -> V_250 [ 0 ] ;
V_11 -> V_268 = V_245 -> V_269 ;
F_22 ( V_219 , L_45 , V_11 -> V_268 ) ;
V_11 -> V_236 = F_129 ( 32 * V_11 -> V_268 , V_230 ) ;
if ( V_11 -> V_236 == NULL ) {
F_17 ( & V_229 -> V_6 , L_46 ) ;
V_114 = - V_262 ;
goto V_270;
}
for ( V_159 = 0 ; V_159 < V_11 -> V_268 ; V_159 ++ ) {
T_8 V_271 = F_130 ( V_245 -> V_247 [ V_159 ] . V_252 [ 1 ] . V_167 .
V_272 ) ;
V_11 -> V_236 [ V_159 ] =
( V_271 & 0x07ff ) * ( ( ( V_271 & 0x1800 ) >> 11 ) + 1 ) ;
F_22 ( V_219 , L_47 , V_159 ,
V_11 -> V_236 [ V_159 ] ) ;
}
V_11 -> V_224 = V_273 ++ ;
V_11 -> V_69 = V_12 [ V_237 ] . V_83 ;
if ( V_11 -> V_69 )
V_11 -> V_274 = V_12 [ V_237 ] . V_274 ;
V_11 -> V_13 = V_237 ;
V_11 -> V_52 = 0 ;
V_11 -> V_213 = V_246 ;
V_11 -> V_212 = 0 ;
V_11 -> V_275 = V_252 -> V_276 ;
V_11 -> V_277 = 0 ;
V_11 -> V_278 = 0 ;
V_11 -> V_20 = 0 ;
V_11 -> V_26 = V_279 ;
F_123 ( V_11 ) ;
F_111 ( V_11 ) ;
F_15 ( & V_11 -> V_5 ) ;
F_22 ( V_219 , L_5 ) ;
return 0 ;
V_270:
F_47 ( V_11 ) ;
V_259:
F_131 ( V_6 ) ;
return V_114 ;
}
static void F_132 ( struct V_228 * V_229 )
{
struct V_1 * V_11 = F_133 ( F_134 ( V_229 ) ) ;
F_22 ( V_219 , L_28 ) ;
if ( V_11 == NULL ) {
F_135 ( L_48 , V_41 ) ;
return;
}
F_40 ( & V_11 -> V_45 ) ;
F_43 ( V_11 ) ;
F_136 ( & V_11 -> V_218 ) ;
if ( V_11 -> V_48 ) {
F_35 ( V_11 ) ;
F_36 ( V_11 ) ;
}
V_11 -> V_52 = 1 ;
F_131 ( V_11 -> V_6 ) ;
V_11 -> V_6 = NULL ;
F_38 ( & V_11 -> V_45 ) ;
if ( V_11 -> V_20 ) {
F_46 ( V_53 L_49 ,
V_41 ) ;
F_137 ( & V_11 -> V_155 ) ;
F_137 ( & V_11 -> V_280 ) ;
} else {
F_47 ( V_11 ) ;
}
F_22 ( V_219 , L_5 ) ;
}
static int T_9 F_138 ( void )
{
int V_43 ;
F_22 ( V_219 , L_28 ) ;
F_22 ( V_44 , L_50 ) ;
F_22 ( V_219 , L_51 ) ;
F_22 ( V_198 , L_52 ) ;
if ( V_28 != V_29 ) {
V_166 [ 6 ] . V_281 = 0 ;
V_166 [ 7 ] . V_281 = 0 ;
}
V_43 = F_139 ( & V_282 ) ;
if ( V_43 == 0 ) {
F_46 (KERN_INFO DRIVER_DESC L_53 USBVISION_VERSION_STRING L_54 ) ;
F_22 ( V_219 , L_5 ) ;
}
return V_43 ;
}
static void T_10 F_140 ( void )
{
F_22 ( V_219 , L_28 ) ;
F_141 ( & V_282 ) ;
F_22 ( V_219 , L_5 ) ;
}
