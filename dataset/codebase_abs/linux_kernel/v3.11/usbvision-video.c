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
F_17 ( & V_11 -> V_5 -> V_6 ,
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
F_17 ( & V_11 -> V_5 -> V_6 ,
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
return 0 ;
}
static int F_55 ( struct V_42 * V_42 , void * V_54 ,
struct V_71 * V_72 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_73 ;
if ( V_72 -> V_74 >= V_11 -> V_75 )
return - V_76 ;
if ( V_11 -> V_69 )
V_73 = V_72 -> V_74 ;
else
V_73 = V_72 -> V_74 + 1 ;
switch ( V_73 ) {
case 0 :
if ( V_12 [ V_11 -> V_13 ] . V_77 == 4 ) {
strcpy ( V_72 -> V_78 , L_11 ) ;
} else {
strcpy ( V_72 -> V_78 , L_12 ) ;
V_72 -> type = V_79 ;
V_72 -> V_80 = 1 ;
V_72 -> V_81 = V_73 ;
V_72 -> V_82 = V_83 ;
}
break;
case 1 :
V_72 -> type = V_84 ;
if ( V_12 [ V_11 -> V_13 ] . V_77 == 4 )
strcpy ( V_72 -> V_78 , L_13 ) ;
else
strcpy ( V_72 -> V_78 , L_14 ) ;
V_72 -> V_82 = V_85 ;
break;
case 2 :
V_72 -> type = V_84 ;
if ( V_12 [ V_11 -> V_13 ] . V_77 == 4 )
strcpy ( V_72 -> V_78 , L_15 ) ;
else
strcpy ( V_72 -> V_78 , L_16 ) ;
V_72 -> V_82 = V_85 ;
break;
case 3 :
V_72 -> type = V_84 ;
strcpy ( V_72 -> V_78 , L_17 ) ;
V_72 -> V_82 = V_85 ;
break;
}
return 0 ;
}
static int F_56 ( struct V_42 * V_42 , void * V_54 , unsigned int * V_86 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
* V_86 = V_11 -> V_87 ;
return 0 ;
}
static int F_57 ( struct V_42 * V_42 , void * V_54 , unsigned int V_86 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_86 >= V_11 -> V_75 )
return - V_76 ;
F_34 ( V_11 , V_86 ) ;
F_58 ( V_11 ) ;
F_59 ( V_11 ,
V_11 -> V_88 ,
V_11 -> V_89 ) ;
return 0 ;
}
static int F_60 ( struct V_42 * V_42 , void * V_54 , T_2 V_17 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_90 = V_17 ;
F_7 ( V_11 , V_21 , V_91 , V_11 -> V_90 ) ;
F_34 ( V_11 , V_11 -> V_87 ) ;
return 0 ;
}
static int F_61 ( struct V_42 * V_42 , void * V_54 , T_2 * V_17 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
* V_17 = V_11 -> V_90 ;
return 0 ;
}
static int F_62 ( struct V_42 * V_42 , void * V_54 ,
struct V_92 * V_93 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_93 -> V_74 )
return - V_76 ;
if ( V_11 -> V_94 ) {
strcpy ( V_93 -> V_78 , L_18 ) ;
V_93 -> type = V_95 ;
} else {
strcpy ( V_93 -> V_78 , L_12 ) ;
}
F_7 ( V_11 , V_81 , V_96 , V_93 ) ;
return 0 ;
}
static int F_63 ( struct V_42 * V_42 , void * V_54 ,
const struct V_92 * V_93 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_93 -> V_74 )
return - V_76 ;
F_7 ( V_11 , V_81 , V_97 , V_93 ) ;
return 0 ;
}
static int F_64 ( struct V_42 * V_42 , void * V_54 ,
struct V_98 * V_99 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_99 -> V_81 = 0 ;
if ( V_11 -> V_94 )
V_99 -> type = V_95 ;
else
V_99 -> type = V_100 ;
V_99 -> V_101 = V_11 -> V_99 ;
return 0 ;
}
static int F_65 ( struct V_42 * V_42 , void * V_54 ,
const struct V_98 * V_99 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_99 -> V_81 )
return - V_76 ;
V_11 -> V_99 = V_99 -> V_101 ;
F_7 ( V_11 , V_81 , V_102 , V_99 ) ;
return 0 ;
}
static int F_66 ( struct V_42 * V_42 , void * V_54 , struct V_103 * V_104 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_11 -> V_94 )
strcpy ( V_104 -> V_78 , L_18 ) ;
else
strcpy ( V_104 -> V_78 , L_19 ) ;
return 0 ;
}
static int F_67 ( struct V_42 * V_42 , void * V_105 ,
const struct V_103 * V_104 )
{
if ( V_104 -> V_74 )
return - V_76 ;
return 0 ;
}
static int F_68 ( struct V_42 * V_42 , void * V_54 ,
struct V_106 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_107 , V_16 ) ;
if ( ! V_16 -> type )
return - V_76 ;
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
F_7 ( V_11 , V_21 , V_108 , V_16 ) ;
return 0 ;
}
static int F_71 ( struct V_42 * V_42 ,
void * V_54 , struct V_109 * V_110 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_111 ;
F_72 ( V_110 -> V_112 , 1 , V_113 ) ;
if ( V_110 -> V_114 != V_115 )
return - V_76 ;
if ( V_11 -> V_26 == V_27 ) {
V_111 = F_73 ( V_11 ) ;
if ( V_111 )
return V_111 ;
}
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
V_110 -> V_112 = F_74 ( V_11 , V_110 -> V_112 ) ;
V_11 -> V_116 = NULL ;
return 0 ;
}
static int F_75 ( struct V_42 * V_42 ,
void * V_54 , struct V_117 * V_118 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_119 * V_120 ;
if ( V_118 -> V_74 >= V_11 -> V_121 )
return - V_76 ;
V_118 -> V_122 = V_123 ;
V_120 = & V_11 -> V_120 [ V_118 -> V_74 ] ;
if ( V_120 -> V_124 >= V_125 )
V_118 -> V_122 |= V_126 ;
if ( V_120 -> V_124 >= V_127 )
V_118 -> V_122 |= V_128 ;
if ( V_120 -> V_124 == V_129 )
V_118 -> V_122 |= V_130 ;
V_118 -> V_114 = V_115 ;
V_118 -> V_131 . V_132 = V_118 -> V_74 * F_76 ( V_11 -> V_133 ) ;
V_118 -> V_114 = V_115 ;
V_118 -> V_134 = V_135 ;
V_118 -> V_136 = V_11 -> V_88 *
V_11 -> V_89 *
V_11 -> V_137 . V_138 ;
V_118 -> V_139 = V_11 -> V_120 [ V_118 -> V_74 ] . V_139 ;
V_118 -> V_140 = V_11 -> V_120 [ V_118 -> V_74 ] . V_140 ;
return 0 ;
}
static int F_77 ( struct V_42 * V_42 , void * V_54 , struct V_117 * V_118 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_119 * V_120 ;
unsigned long V_141 ;
if ( V_118 -> V_74 >= V_11 -> V_121 )
return - V_76 ;
V_120 = & V_11 -> V_120 [ V_118 -> V_74 ] ;
if ( V_120 -> V_124 != V_129 )
return - V_142 ;
V_120 -> V_124 = V_125 ;
V_120 -> V_143 = V_144 ;
V_120 -> V_145 = 0 ;
V_118 -> V_122 &= ~ V_128 ;
V_120 -> V_146 = V_11 -> V_137 ;
F_78 ( & V_11 -> V_147 , V_141 ) ;
F_79 ( & V_11 -> V_120 [ V_118 -> V_74 ] . V_120 , & V_11 -> V_148 ) ;
F_80 ( & V_11 -> V_147 , V_141 ) ;
return 0 ;
}
static int F_81 ( struct V_42 * V_42 , void * V_54 , struct V_117 * V_118 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_111 ;
struct V_119 * V_149 ;
unsigned long V_141 ;
if ( F_82 ( & ( V_11 -> V_150 ) ) ) {
if ( V_11 -> V_26 == V_151 )
return - V_76 ;
V_111 = F_83
( V_11 -> V_152 ,
! F_82 ( & ( V_11 -> V_150 ) ) ) ;
if ( V_111 )
return V_111 ;
}
F_78 ( & V_11 -> V_147 , V_141 ) ;
V_149 = F_84 ( V_11 -> V_150 . V_153 ,
struct V_119 , V_120 ) ;
F_85 ( V_11 -> V_150 . V_153 ) ;
F_80 ( & V_11 -> V_147 , V_141 ) ;
V_149 -> V_124 = V_129 ;
V_118 -> V_114 = V_115 ;
V_118 -> V_122 = V_130 |
V_126 |
V_128 |
V_123 ;
V_118 -> V_74 = V_149 -> V_74 ;
V_118 -> V_140 = V_149 -> V_140 ;
V_118 -> V_139 = V_149 -> V_139 ;
V_118 -> V_134 = V_135 ;
V_118 -> V_154 = V_149 -> V_145 ;
return 0 ;
}
static int F_86 ( struct V_42 * V_42 , void * V_54 , enum V_155 V_156 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_157 , V_158 , 1 ) ;
return 0 ;
}
static int F_87 ( struct V_42 * V_42 ,
void * V_54 , enum V_155 type )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( type != V_159 )
return - V_76 ;
if ( V_11 -> V_26 == V_27 ) {
F_73 ( V_11 ) ;
F_7 ( V_11 , V_157 , V_158 , 0 ) ;
}
F_37 ( V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_42 * V_42 , void * V_54 ,
struct V_160 * V_161 )
{
if ( V_161 -> V_74 >= V_162 - 1 )
return - V_76 ;
strcpy ( V_161 -> V_163 , V_164 [ V_161 -> V_74 ] . V_165 ) ;
V_161 -> V_166 = V_164 [ V_161 -> V_74 ] . V_167 ;
return 0 ;
}
static int F_89 ( struct V_42 * V_42 , void * V_54 ,
struct V_146 * V_168 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_168 -> V_169 . V_170 . V_171 = V_11 -> V_88 ;
V_168 -> V_169 . V_170 . V_172 = V_11 -> V_89 ;
V_168 -> V_169 . V_170 . V_166 = V_11 -> V_137 . V_167 ;
V_168 -> V_169 . V_170 . V_173 =
V_11 -> V_88 * V_11 -> V_137 . V_138 ;
V_168 -> V_169 . V_170 . V_174 = V_168 -> V_169 . V_170 . V_173 * V_11 -> V_89 ;
V_168 -> V_169 . V_170 . V_175 = V_176 ;
V_168 -> V_169 . V_170 . V_134 = V_135 ;
return 0 ;
}
static int F_90 ( struct V_42 * V_42 , void * V_54 ,
struct V_146 * V_168 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_177 ;
for ( V_177 = 0 ; V_177 < V_162 ; V_177 ++ ) {
if ( V_168 -> V_169 . V_170 . V_166 ==
V_164 [ V_177 ] . V_167 ) {
V_11 -> V_137 = V_164 [ V_177 ] ;
break;
}
}
if ( V_177 == V_162 )
return - V_76 ;
F_72 ( V_168 -> V_169 . V_170 . V_171 , V_178 , V_179 ) ;
F_72 ( V_168 -> V_169 . V_170 . V_172 , V_180 , V_181 ) ;
V_168 -> V_169 . V_170 . V_173 = V_168 -> V_169 . V_170 . V_171 *
V_11 -> V_137 . V_138 ;
V_168 -> V_169 . V_170 . V_174 = V_168 -> V_169 . V_170 . V_173 * V_168 -> V_169 . V_170 . V_172 ;
return 0 ;
}
static int F_91 ( struct V_42 * V_42 , void * V_54 ,
struct V_146 * V_168 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_111 ;
V_111 = F_90 ( V_42 , V_54 , V_168 ) ;
if ( V_111 )
return V_111 ;
if ( V_11 -> V_26 == V_27 ) {
V_111 = F_73 ( V_11 ) ;
if ( V_111 )
return V_111 ;
}
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
V_11 -> V_116 = NULL ;
F_59 ( V_11 , V_168 -> V_169 . V_170 . V_171 , V_168 -> V_169 . V_170 . V_172 ) ;
return 0 ;
}
static T_1 F_92 ( struct V_42 * V_42 , char T_3 * V_9 ,
T_4 V_112 , T_5 * V_182 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_183 = V_42 -> V_184 & V_185 ;
unsigned long V_141 ;
int V_111 , V_156 ;
struct V_119 * V_120 ;
F_22 ( V_44 , L_20 , V_41 ,
( unsigned long ) V_112 , V_183 ) ;
if ( ! F_93 ( V_11 ) || ( V_9 == NULL ) )
return - V_186 ;
if ( ! V_11 -> V_121 ) {
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
F_74 ( V_11 , V_113 ) ;
}
if ( V_11 -> V_26 != V_27 ) {
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_157 , V_158 , 1 ) ;
}
for ( V_156 = 0 ; V_156 < V_11 -> V_121 ; V_156 ++ ) {
V_120 = & V_11 -> V_120 [ V_156 ] ;
if ( V_120 -> V_124 == V_129 ) {
V_120 -> V_124 = V_125 ;
V_120 -> V_143 = V_144 ;
V_120 -> V_145 = 0 ;
V_120 -> V_146 = V_11 -> V_137 ;
F_78 ( & V_11 -> V_147 , V_141 ) ;
F_79 ( & V_120 -> V_120 , & V_11 -> V_148 ) ;
F_80 ( & V_11 -> V_147 ,
V_141 ) ;
}
}
if ( F_82 ( & ( V_11 -> V_150 ) ) ) {
if ( V_183 )
return - V_142 ;
V_111 = F_83
( V_11 -> V_152 ,
! F_82 ( & ( V_11 -> V_150 ) ) ) ;
if ( V_111 )
return V_111 ;
}
F_78 ( & V_11 -> V_147 , V_141 ) ;
V_120 = F_84 ( V_11 -> V_150 . V_153 ,
struct V_119 , V_120 ) ;
F_85 ( V_11 -> V_150 . V_153 ) ;
F_80 ( & V_11 -> V_147 , V_141 ) ;
if ( V_120 -> V_124 == V_187 ) {
V_120 -> V_188 = 0 ;
return 0 ;
}
F_22 ( V_44 , L_21 ,
V_41 ,
V_120 -> V_74 , V_120 -> V_188 , V_120 -> V_145 ) ;
if ( ( V_112 + V_120 -> V_188 ) > ( unsigned long ) V_120 -> V_145 )
V_112 = V_120 -> V_145 - V_120 -> V_188 ;
if ( F_94 ( V_9 , V_120 -> V_189 + V_120 -> V_188 , V_112 ) )
return - V_186 ;
V_120 -> V_188 += V_112 ;
F_22 ( V_44 , L_22 ,
V_41 ,
( unsigned long ) V_112 , V_120 -> V_188 ) ;
V_120 -> V_188 = 0 ;
V_120 -> V_124 = V_129 ;
return V_112 ;
}
static T_1 F_95 ( struct V_42 * V_42 , char T_3 * V_9 ,
T_4 V_112 , T_5 * V_182 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_31 ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
V_31 = F_92 ( V_42 , V_9 , V_112 , V_182 ) ;
F_38 ( & V_11 -> V_45 ) ;
return V_31 ;
}
static int F_96 ( struct V_42 * V_42 , struct V_190 * V_191 )
{
unsigned long V_58 = V_191 -> V_192 - V_191 -> V_193 ,
V_194 = V_191 -> V_193 ;
void * V_195 ;
T_6 V_156 ;
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_22 ( V_196 , L_23 ) ;
if ( ! F_93 ( V_11 ) )
return - V_186 ;
if ( ! ( V_191 -> V_197 & V_198 ) ||
V_58 != F_76 ( V_11 -> V_133 ) ) {
return - V_76 ;
}
for ( V_156 = 0 ; V_156 < V_11 -> V_121 ; V_156 ++ ) {
if ( ( ( F_76 ( V_11 -> V_133 ) * V_156 ) >> V_199 ) ==
V_191 -> V_200 )
break;
}
if ( V_156 == V_11 -> V_121 ) {
F_22 ( V_196 ,
L_24 ) ;
return - V_76 ;
}
V_191 -> V_197 |= V_201 | V_202 | V_203 ;
V_195 = V_11 -> V_120 [ V_156 ] . V_189 ;
while ( V_58 > 0 ) {
if ( F_97 ( V_191 , V_194 , F_98 ( V_195 ) ) ) {
F_22 ( V_196 , L_25 ) ;
return - V_142 ;
}
V_194 += V_204 ;
V_195 += V_204 ;
V_58 -= V_204 ;
}
return 0 ;
}
static int F_99 ( struct V_42 * V_42 , struct V_190 * V_191 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_31 ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
V_31 = F_96 ( V_42 , V_191 ) ;
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
F_17 ( & V_11 -> V_205 -> V_6 ,
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
V_11 -> V_206 = V_43 ;
V_43 = - V_47 ;
goto V_207;
}
V_11 -> V_94 = 1 ;
F_7 ( V_11 , V_81 , V_208 ) ;
F_102 ( V_11 , V_209 ) ;
V_11 -> V_20 ++ ;
}
if ( V_43 ) {
if ( V_51 ) {
F_35 ( V_11 ) ;
F_36 ( V_11 ) ;
V_11 -> V_49 = 0 ;
}
}
V_207:
F_38 ( & V_11 -> V_45 ) ;
return V_43 ;
}
static int F_103 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_28 ) ;
F_40 ( & V_11 -> V_45 ) ;
V_11 -> V_210 = 0 ;
V_43 = F_104 ( V_11 -> V_6 , V_11 -> V_211 ,
V_11 -> V_210 ) ;
F_41 ( V_11 ) ;
V_11 -> V_94 = 0 ;
V_11 -> V_20 -- ;
if ( V_51 ) {
F_45 ( V_11 ) ;
V_11 -> V_49 = 0 ;
}
if ( V_11 -> V_52 ) {
F_46 ( V_53 L_7 , V_41 ) ;
F_47 ( V_11 ) ;
}
F_38 ( & V_11 -> V_45 ) ;
F_22 ( V_44 , L_5 ) ;
return V_43 ;
}
static struct V_4 * F_105 ( struct V_1 * V_11 ,
struct V_4 * V_212 ,
char * V_78 )
{
struct V_213 * V_214 = V_11 -> V_6 ;
struct V_4 * V_5 ;
if ( V_214 == NULL ) {
F_17 ( & V_11 -> V_6 -> V_6 ,
L_29 , V_41 ) ;
return NULL ;
}
V_5 = F_106 () ;
if ( NULL == V_5 )
return NULL ;
* V_5 = * V_212 ;
V_5 -> V_215 = & V_11 -> V_45 ;
V_5 -> V_216 = & V_11 -> V_216 ;
snprintf ( V_5 -> V_78 , sizeof( V_5 -> V_78 ) , L_30 , V_78 ) ;
F_107 ( V_5 , V_11 ) ;
return V_5 ;
}
static void F_108 ( struct V_1 * V_11 )
{
if ( V_11 -> V_205 ) {
F_22 ( V_217 , L_31 ,
F_109 ( V_11 -> V_205 ) ) ;
if ( F_110 ( V_11 -> V_205 ) )
F_111 ( V_11 -> V_205 ) ;
else
F_112 ( V_11 -> V_205 ) ;
V_11 -> V_205 = NULL ;
}
if ( V_11 -> V_5 ) {
F_22 ( V_217 , L_31 ,
F_109 ( V_11 -> V_5 ) ) ;
if ( F_110 ( V_11 -> V_5 ) )
F_111 ( V_11 -> V_5 ) ;
else
F_112 ( V_11 -> V_5 ) ;
V_11 -> V_5 = NULL ;
}
}
static int F_113 ( struct V_1 * V_11 )
{
V_11 -> V_5 = F_105 ( V_11 ,
& V_218 ,
L_32 ) ;
if ( V_11 -> V_5 == NULL )
goto V_219;
if ( F_114 ( V_11 -> V_5 , V_220 , V_221 ) < 0 )
goto V_219;
F_46 ( V_53 L_33 ,
V_11 -> V_222 , F_109 ( V_11 -> V_5 ) ) ;
if ( V_12 [ V_11 -> V_13 ] . V_94 ) {
V_11 -> V_205 = F_105 ( V_11 ,
& V_223 ,
L_34 ) ;
if ( V_11 -> V_205 == NULL )
goto V_219;
if ( F_114 ( V_11 -> V_205 , V_224 , V_225 ) < 0 )
goto V_219;
F_46 ( V_53 L_35 ,
V_11 -> V_222 , F_109 ( V_11 -> V_205 ) ) ;
}
return 0 ;
V_219:
F_17 ( & V_11 -> V_6 -> V_6 ,
L_36 ,
V_11 -> V_222 ) ;
F_108 ( V_11 ) ;
return - 1 ;
}
static struct V_1 * F_115 ( struct V_213 * V_6 ,
struct V_226 * V_227 )
{
struct V_1 * V_11 ;
V_11 = F_116 ( sizeof( struct V_1 ) , V_228 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_6 = V_6 ;
if ( F_117 ( & V_227 -> V_6 , & V_11 -> V_216 ) )
goto V_229;
F_118 ( & V_11 -> V_45 ) ;
V_11 -> V_230 = F_119 ( V_231 , V_228 ) ;
if ( V_11 -> V_230 == NULL )
goto V_232;
F_120 ( & V_11 -> V_233 ) ;
F_121 ( V_11 ) ;
return V_11 ;
V_232:
F_122 ( & V_11 -> V_216 ) ;
V_229:
F_123 ( V_11 ) ;
return NULL ;
}
static void F_47 ( struct V_1 * V_11 )
{
F_22 ( V_217 , L_28 ) ;
F_24 ( V_11 ) ;
V_11 -> V_49 = 0 ;
F_18 ( V_11 -> V_5 ) ;
F_108 ( V_11 ) ;
F_123 ( V_11 -> V_234 ) ;
F_124 ( V_11 -> V_230 ) ;
F_122 ( & V_11 -> V_216 ) ;
F_123 ( V_11 ) ;
F_22 ( V_217 , L_5 ) ;
}
static void F_125 ( struct V_1 * V_11 )
{
int V_235 ;
if ( V_11 == NULL )
return;
V_235 = V_11 -> V_13 ;
V_11 -> V_137 = V_164 [ 2 ] ;
if ( V_12 [ V_11 -> V_13 ] . V_236 ) {
V_11 -> V_237 =
V_12 [ V_11 -> V_13 ] . V_238 ;
} else {
V_11 -> V_237 = 0 ;
}
V_11 -> V_90 = V_12 [ V_235 ] . V_239 ;
V_11 -> V_75 = V_12 [ V_235 ] . V_77 ;
V_11 -> V_87 = 0 ;
if ( V_12 [ V_235 ] . V_240 > 0 )
F_41 ( V_11 ) ;
if ( ! V_51 ) {
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
}
}
static int F_126 ( struct V_226 * V_227 ,
const struct V_241 * V_242 )
{
struct V_213 * V_6 = F_127 ( F_128 ( V_227 ) ) ;
struct V_226 * V_243 ;
T_7 V_244 = V_227 -> V_245 -> V_165 . V_246 ;
const struct V_247 * V_248 ;
struct V_1 * V_11 = NULL ;
const struct V_249 * V_250 ;
int V_235 , V_156 ;
F_22 ( V_217 , L_37 ,
V_6 -> V_251 . V_252 ,
V_6 -> V_251 . V_253 , V_244 ) ;
V_235 = V_242 -> V_254 ;
if ( V_235 < 0 || V_235 >= V_255 ) {
F_22 ( V_217 , L_38 , V_235 ) ;
return - V_256 ;
}
F_46 ( V_53 L_39 , V_41 ,
V_12 [ V_235 ] . V_14 ) ;
if ( V_12 [ V_235 ] . V_248 >= 0 )
V_248 = & V_6 -> V_257 -> V_248 [ V_12 [ V_235 ] . V_248 ] -> V_245 [ 0 ] ;
else
V_248 = & V_6 -> V_257 -> V_248 [ V_244 ] -> V_245 [ 0 ] ;
V_250 = & V_248 -> V_250 [ 1 ] . V_165 ;
if ( ! F_129 ( V_250 ) ) {
F_17 ( & V_227 -> V_6 , L_40 ,
V_41 , V_244 ) ;
F_17 ( & V_227 -> V_6 , L_41 ,
V_41 , V_250 -> V_258 ) ;
return - V_256 ;
}
if ( F_130 ( V_250 ) ) {
F_17 ( & V_227 -> V_6 , L_42 ,
V_41 , V_244 ) ;
return - V_256 ;
}
V_11 = F_115 ( V_6 , V_227 ) ;
if ( V_11 == NULL ) {
F_17 ( & V_227 -> V_6 , L_43 , V_41 ) ;
return - V_259 ;
}
if ( V_6 -> V_251 . V_260 > 1 )
V_11 -> V_30 = V_261 ;
else if ( V_235 == V_262 )
V_11 -> V_30 = V_263 ;
else
V_11 -> V_30 = V_264 ;
F_22 ( V_217 , L_44 , V_11 -> V_30 ) ;
V_243 = V_6 -> V_257 -> V_248 [ 0 ] ;
V_11 -> V_265 = V_243 -> V_266 ;
F_22 ( V_217 , L_45 , V_11 -> V_265 ) ;
V_11 -> V_234 = F_131 ( 32 * V_11 -> V_265 , V_228 ) ;
if ( V_11 -> V_234 == NULL ) {
F_17 ( & V_227 -> V_6 , L_46 ) ;
F_47 ( V_11 ) ;
return - V_259 ;
}
for ( V_156 = 0 ; V_156 < V_11 -> V_265 ; V_156 ++ ) {
T_8 V_267 = F_132 ( V_243 -> V_245 [ V_156 ] . V_250 [ 1 ] . V_165 .
V_268 ) ;
V_11 -> V_234 [ V_156 ] =
( V_267 & 0x07ff ) * ( ( ( V_267 & 0x1800 ) >> 11 ) + 1 ) ;
F_22 ( V_217 , L_47 , V_156 ,
V_11 -> V_234 [ V_156 ] ) ;
}
V_11 -> V_222 = V_269 ++ ;
V_11 -> V_69 = V_12 [ V_235 ] . V_81 ;
if ( V_11 -> V_69 )
V_11 -> V_270 = V_12 [ V_235 ] . V_270 ;
V_11 -> V_13 = V_235 ;
V_11 -> V_52 = 0 ;
V_11 -> V_211 = V_244 ;
V_11 -> V_210 = 0 ;
V_11 -> V_271 = V_250 -> V_272 ;
V_11 -> V_273 = 0 ;
V_11 -> V_274 = 0 ;
V_11 -> V_20 = 0 ;
V_11 -> V_26 = V_275 ;
F_125 ( V_11 ) ;
F_113 ( V_11 ) ;
F_15 ( V_11 -> V_5 ) ;
F_22 ( V_217 , L_5 ) ;
return 0 ;
}
static void F_133 ( struct V_226 * V_227 )
{
struct V_1 * V_11 = F_134 ( F_135 ( V_227 ) ) ;
F_22 ( V_217 , L_28 ) ;
if ( V_11 == NULL ) {
F_136 ( L_48 , V_41 ) ;
return;
}
F_40 ( & V_11 -> V_45 ) ;
F_43 ( V_11 ) ;
F_137 ( & V_11 -> V_216 ) ;
if ( V_11 -> V_48 ) {
F_35 ( V_11 ) ;
F_36 ( V_11 ) ;
}
V_11 -> V_52 = 1 ;
F_138 ( V_11 -> V_6 ) ;
V_11 -> V_6 = NULL ;
F_38 ( & V_11 -> V_45 ) ;
if ( V_11 -> V_20 ) {
F_46 ( V_53 L_49 ,
V_41 ) ;
F_139 ( & V_11 -> V_152 ) ;
F_139 ( & V_11 -> V_276 ) ;
} else {
F_47 ( V_11 ) ;
}
F_22 ( V_217 , L_5 ) ;
}
static int T_9 F_140 ( void )
{
int V_43 ;
F_22 ( V_217 , L_28 ) ;
F_22 ( V_44 , L_50 ) ;
F_22 ( V_217 , L_51 ) ;
F_22 ( V_196 , L_52 ) ;
if ( V_28 != V_29 ) {
V_164 [ 6 ] . V_277 = 0 ;
V_164 [ 7 ] . V_277 = 0 ;
}
V_43 = F_141 ( & V_278 ) ;
if ( V_43 == 0 ) {
F_46 (KERN_INFO DRIVER_DESC L_53 USBVISION_VERSION_STRING L_54 ) ;
F_22 ( V_217 , L_5 ) ;
}
return V_43 ;
}
static void T_10 F_142 ( void )
{
F_22 ( V_217 , L_28 ) ;
F_143 ( & V_278 ) ;
F_22 ( V_217 , L_5 ) ;
}
