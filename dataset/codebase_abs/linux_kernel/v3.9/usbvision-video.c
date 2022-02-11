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
if ( ! F_49 ( & V_56 -> V_57 ) )
return - V_58 ;
V_43 = F_50 ( V_11 , V_56 -> V_56 & 0xff ) ;
if ( V_43 < 0 ) {
F_17 ( & V_11 -> V_5 -> V_6 ,
L_8 ,
V_41 , V_43 ) ;
return V_43 ;
}
V_56 -> V_59 = V_43 ;
V_56 -> V_60 = 1 ;
return 0 ;
}
static int F_51 ( struct V_42 * V_42 , void * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 ;
if ( ! F_49 ( & V_56 -> V_57 ) )
return - V_58 ;
V_43 = F_52 ( V_11 , V_56 -> V_56 & 0xff , V_56 -> V_59 ) ;
if ( V_43 < 0 ) {
F_17 ( & V_11 -> V_5 -> V_6 ,
L_9 ,
V_41 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_53 ( struct V_42 * V_42 , void * V_54 ,
struct V_61 * V_62 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_54 ( V_62 -> V_63 , L_10 , sizeof( V_62 -> V_63 ) ) ;
F_54 ( V_62 -> V_64 ,
V_12 [ V_11 -> V_13 ] . V_14 ,
sizeof( V_62 -> V_64 ) ) ;
F_55 ( V_11 -> V_6 , V_62 -> V_65 , sizeof( V_62 -> V_65 ) ) ;
V_62 -> V_66 = V_67 |
V_68 |
V_69 |
V_70 |
( V_11 -> V_71 ? V_72 : 0 ) ;
return 0 ;
}
static int F_56 ( struct V_42 * V_42 , void * V_54 ,
struct V_73 * V_74 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_75 ;
if ( V_74 -> V_76 >= V_11 -> V_77 )
return - V_58 ;
if ( V_11 -> V_71 )
V_75 = V_74 -> V_76 ;
else
V_75 = V_74 -> V_76 + 1 ;
switch ( V_75 ) {
case 0 :
if ( V_12 [ V_11 -> V_13 ] . V_78 == 4 ) {
strcpy ( V_74 -> V_79 , L_11 ) ;
} else {
strcpy ( V_74 -> V_79 , L_12 ) ;
V_74 -> type = V_80 ;
V_74 -> V_81 = 1 ;
V_74 -> V_82 = V_75 ;
V_74 -> V_83 = V_84 ;
}
break;
case 1 :
V_74 -> type = V_85 ;
if ( V_12 [ V_11 -> V_13 ] . V_78 == 4 )
strcpy ( V_74 -> V_79 , L_13 ) ;
else
strcpy ( V_74 -> V_79 , L_14 ) ;
V_74 -> V_83 = V_86 ;
break;
case 2 :
V_74 -> type = V_85 ;
if ( V_12 [ V_11 -> V_13 ] . V_78 == 4 )
strcpy ( V_74 -> V_79 , L_15 ) ;
else
strcpy ( V_74 -> V_79 , L_16 ) ;
V_74 -> V_83 = V_86 ;
break;
case 3 :
V_74 -> type = V_85 ;
strcpy ( V_74 -> V_79 , L_17 ) ;
V_74 -> V_83 = V_86 ;
break;
}
return 0 ;
}
static int F_57 ( struct V_42 * V_42 , void * V_54 , unsigned int * V_87 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
* V_87 = V_11 -> V_88 ;
return 0 ;
}
static int F_58 ( struct V_42 * V_42 , void * V_54 , unsigned int V_87 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_87 >= V_11 -> V_77 )
return - V_58 ;
F_34 ( V_11 , V_87 ) ;
F_59 ( V_11 ) ;
F_60 ( V_11 ,
V_11 -> V_89 ,
V_11 -> V_90 ) ;
return 0 ;
}
static int F_61 ( struct V_42 * V_42 , void * V_54 , T_2 * V_17 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_91 = * V_17 ;
F_7 ( V_11 , V_21 , V_92 , V_11 -> V_91 ) ;
F_34 ( V_11 , V_11 -> V_88 ) ;
return 0 ;
}
static int F_62 ( struct V_42 * V_42 , void * V_54 ,
struct V_93 * V_94 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_71 || V_94 -> V_76 )
return - V_58 ;
if ( V_11 -> V_95 ) {
strcpy ( V_94 -> V_79 , L_18 ) ;
V_94 -> type = V_96 ;
} else {
strcpy ( V_94 -> V_79 , L_12 ) ;
}
F_7 ( V_11 , V_82 , V_97 , V_94 ) ;
return 0 ;
}
static int F_63 ( struct V_42 * V_42 , void * V_54 ,
struct V_93 * V_94 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_71 || V_94 -> V_76 )
return - V_58 ;
F_7 ( V_11 , V_82 , V_98 , V_94 ) ;
return 0 ;
}
static int F_64 ( struct V_42 * V_42 , void * V_54 ,
struct V_99 * V_100 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_100 -> V_82 = 0 ;
if ( V_11 -> V_95 )
V_100 -> type = V_96 ;
else
V_100 -> type = V_101 ;
V_100 -> V_102 = V_11 -> V_100 ;
return 0 ;
}
static int F_65 ( struct V_42 * V_42 , void * V_54 ,
struct V_99 * V_100 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_71 || V_100 -> V_82 )
return - V_58 ;
V_11 -> V_100 = V_100 -> V_102 ;
F_7 ( V_11 , V_82 , V_103 , V_100 ) ;
return 0 ;
}
static int F_66 ( struct V_42 * V_42 , void * V_54 , struct V_104 * V_105 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_11 -> V_95 )
strcpy ( V_105 -> V_79 , L_18 ) ;
else
strcpy ( V_105 -> V_79 , L_19 ) ;
return 0 ;
}
static int F_67 ( struct V_42 * V_42 , void * V_106 ,
const struct V_104 * V_105 )
{
if ( V_105 -> V_76 )
return - V_58 ;
return 0 ;
}
static int F_68 ( struct V_42 * V_42 , void * V_54 ,
struct V_107 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_108 , V_16 ) ;
if ( ! V_16 -> type )
return - V_58 ;
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
F_7 ( V_11 , V_21 , V_109 , V_16 ) ;
return 0 ;
}
static int F_71 ( struct V_42 * V_42 ,
void * V_54 , struct V_110 * V_111 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_112 ;
F_72 ( V_111 -> V_113 , 1 , V_114 ) ;
if ( V_111 -> V_115 != V_116 )
return - V_58 ;
if ( V_11 -> V_26 == V_27 ) {
V_112 = F_73 ( V_11 ) ;
if ( V_112 )
return V_112 ;
}
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
V_111 -> V_113 = F_74 ( V_11 , V_111 -> V_113 ) ;
V_11 -> V_117 = NULL ;
return 0 ;
}
static int F_75 ( struct V_42 * V_42 ,
void * V_54 , struct V_118 * V_119 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_120 * V_121 ;
if ( V_119 -> V_76 >= V_11 -> V_122 )
return - V_58 ;
V_119 -> V_123 = V_124 ;
V_121 = & V_11 -> V_121 [ V_119 -> V_76 ] ;
if ( V_121 -> V_125 >= V_126 )
V_119 -> V_123 |= V_127 ;
if ( V_121 -> V_125 >= V_128 )
V_119 -> V_123 |= V_129 ;
if ( V_121 -> V_125 == V_130 )
V_119 -> V_123 |= V_131 ;
V_119 -> V_115 = V_116 ;
V_119 -> V_132 . V_133 = V_119 -> V_76 * F_76 ( V_11 -> V_134 ) ;
V_119 -> V_115 = V_116 ;
V_119 -> V_135 = V_136 ;
V_119 -> V_137 = V_11 -> V_89 *
V_11 -> V_90 *
V_11 -> V_138 . V_139 ;
V_119 -> V_140 = V_11 -> V_121 [ V_119 -> V_76 ] . V_140 ;
V_119 -> V_141 = V_11 -> V_121 [ V_119 -> V_76 ] . V_141 ;
return 0 ;
}
static int F_77 ( struct V_42 * V_42 , void * V_54 , struct V_118 * V_119 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_120 * V_121 ;
unsigned long V_142 ;
if ( V_119 -> V_76 >= V_11 -> V_122 )
return - V_58 ;
V_121 = & V_11 -> V_121 [ V_119 -> V_76 ] ;
if ( V_121 -> V_125 != V_130 )
return - V_143 ;
V_121 -> V_125 = V_126 ;
V_121 -> V_144 = V_145 ;
V_121 -> V_146 = 0 ;
V_119 -> V_123 &= ~ V_129 ;
V_121 -> V_147 = V_11 -> V_138 ;
F_78 ( & V_11 -> V_148 , V_142 ) ;
F_79 ( & V_11 -> V_121 [ V_119 -> V_76 ] . V_121 , & V_11 -> V_149 ) ;
F_80 ( & V_11 -> V_148 , V_142 ) ;
return 0 ;
}
static int F_81 ( struct V_42 * V_42 , void * V_54 , struct V_118 * V_119 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_112 ;
struct V_120 * V_150 ;
unsigned long V_142 ;
if ( F_82 ( & ( V_11 -> V_151 ) ) ) {
if ( V_11 -> V_26 == V_152 )
return - V_58 ;
V_112 = F_83
( V_11 -> V_153 ,
! F_82 ( & ( V_11 -> V_151 ) ) ) ;
if ( V_112 )
return V_112 ;
}
F_78 ( & V_11 -> V_148 , V_142 ) ;
V_150 = F_84 ( V_11 -> V_151 . V_154 ,
struct V_120 , V_121 ) ;
F_85 ( V_11 -> V_151 . V_154 ) ;
F_80 ( & V_11 -> V_148 , V_142 ) ;
V_150 -> V_125 = V_130 ;
V_119 -> V_115 = V_116 ;
V_119 -> V_123 = V_131 |
V_127 |
V_129 |
V_124 ;
V_119 -> V_76 = V_150 -> V_76 ;
V_119 -> V_141 = V_150 -> V_141 ;
V_119 -> V_140 = V_150 -> V_140 ;
V_119 -> V_135 = V_136 ;
V_119 -> V_155 = V_150 -> V_146 ;
return 0 ;
}
static int F_86 ( struct V_42 * V_42 , void * V_54 , enum V_156 V_157 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_158 , V_159 , 1 ) ;
return 0 ;
}
static int F_87 ( struct V_42 * V_42 ,
void * V_54 , enum V_156 type )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( type != V_160 )
return - V_58 ;
if ( V_11 -> V_26 == V_27 ) {
F_73 ( V_11 ) ;
F_7 ( V_11 , V_158 , V_159 , 0 ) ;
}
F_37 ( V_11 ) ;
return 0 ;
}
static int F_88 ( struct V_42 * V_42 , void * V_54 ,
struct V_161 * V_162 )
{
if ( V_162 -> V_76 >= V_163 - 1 )
return - V_58 ;
strcpy ( V_162 -> V_164 , V_165 [ V_162 -> V_76 ] . V_166 ) ;
V_162 -> V_167 = V_165 [ V_162 -> V_76 ] . V_168 ;
return 0 ;
}
static int F_89 ( struct V_42 * V_42 , void * V_54 ,
struct V_147 * V_169 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_169 -> V_170 . V_171 . V_172 = V_11 -> V_89 ;
V_169 -> V_170 . V_171 . V_173 = V_11 -> V_90 ;
V_169 -> V_170 . V_171 . V_167 = V_11 -> V_138 . V_168 ;
V_169 -> V_170 . V_171 . V_174 =
V_11 -> V_89 * V_11 -> V_138 . V_139 ;
V_169 -> V_170 . V_171 . V_175 = V_169 -> V_170 . V_171 . V_174 * V_11 -> V_90 ;
V_169 -> V_170 . V_171 . V_176 = V_177 ;
V_169 -> V_170 . V_171 . V_135 = V_136 ;
return 0 ;
}
static int F_90 ( struct V_42 * V_42 , void * V_54 ,
struct V_147 * V_169 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_178 ;
for ( V_178 = 0 ; V_178 < V_163 ; V_178 ++ ) {
if ( V_169 -> V_170 . V_171 . V_167 ==
V_165 [ V_178 ] . V_168 ) {
V_11 -> V_138 = V_165 [ V_178 ] ;
break;
}
}
if ( V_178 == V_163 )
return - V_58 ;
F_72 ( V_169 -> V_170 . V_171 . V_172 , V_179 , V_180 ) ;
F_72 ( V_169 -> V_170 . V_171 . V_173 , V_181 , V_182 ) ;
V_169 -> V_170 . V_171 . V_174 = V_169 -> V_170 . V_171 . V_172 *
V_11 -> V_138 . V_139 ;
V_169 -> V_170 . V_171 . V_175 = V_169 -> V_170 . V_171 . V_174 * V_169 -> V_170 . V_171 . V_173 ;
return 0 ;
}
static int F_91 ( struct V_42 * V_42 , void * V_54 ,
struct V_147 * V_169 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_112 ;
V_112 = F_90 ( V_42 , V_54 , V_169 ) ;
if ( V_112 )
return V_112 ;
if ( V_11 -> V_26 == V_27 ) {
V_112 = F_73 ( V_11 ) ;
if ( V_112 )
return V_112 ;
}
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
V_11 -> V_117 = NULL ;
F_60 ( V_11 , V_169 -> V_170 . V_171 . V_172 , V_169 -> V_170 . V_171 . V_173 ) ;
return 0 ;
}
static T_1 F_92 ( struct V_42 * V_42 , char T_3 * V_9 ,
T_4 V_113 , T_5 * V_183 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_184 = V_42 -> V_185 & V_186 ;
unsigned long V_142 ;
int V_112 , V_157 ;
struct V_120 * V_121 ;
F_22 ( V_44 , L_20 , V_41 ,
( unsigned long ) V_113 , V_184 ) ;
if ( ! F_93 ( V_11 ) || ( V_9 == NULL ) )
return - V_187 ;
if ( ! V_11 -> V_122 ) {
F_44 ( V_11 ) ;
F_37 ( V_11 ) ;
F_74 ( V_11 , V_114 ) ;
}
if ( V_11 -> V_26 != V_27 ) {
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_158 , V_159 , 1 ) ;
}
for ( V_157 = 0 ; V_157 < V_11 -> V_122 ; V_157 ++ ) {
V_121 = & V_11 -> V_121 [ V_157 ] ;
if ( V_121 -> V_125 == V_130 ) {
V_121 -> V_125 = V_126 ;
V_121 -> V_144 = V_145 ;
V_121 -> V_146 = 0 ;
V_121 -> V_147 = V_11 -> V_138 ;
F_78 ( & V_11 -> V_148 , V_142 ) ;
F_79 ( & V_121 -> V_121 , & V_11 -> V_149 ) ;
F_80 ( & V_11 -> V_148 ,
V_142 ) ;
}
}
if ( F_82 ( & ( V_11 -> V_151 ) ) ) {
if ( V_184 )
return - V_143 ;
V_112 = F_83
( V_11 -> V_153 ,
! F_82 ( & ( V_11 -> V_151 ) ) ) ;
if ( V_112 )
return V_112 ;
}
F_78 ( & V_11 -> V_148 , V_142 ) ;
V_121 = F_84 ( V_11 -> V_151 . V_154 ,
struct V_120 , V_121 ) ;
F_85 ( V_11 -> V_151 . V_154 ) ;
F_80 ( & V_11 -> V_148 , V_142 ) ;
if ( V_121 -> V_125 == V_188 ) {
V_121 -> V_189 = 0 ;
return 0 ;
}
F_22 ( V_44 , L_21 ,
V_41 ,
V_121 -> V_76 , V_121 -> V_189 , V_121 -> V_146 ) ;
if ( ( V_113 + V_121 -> V_189 ) > ( unsigned long ) V_121 -> V_146 )
V_113 = V_121 -> V_146 - V_121 -> V_189 ;
if ( F_94 ( V_9 , V_121 -> V_190 + V_121 -> V_189 , V_113 ) )
return - V_187 ;
V_121 -> V_189 += V_113 ;
F_22 ( V_44 , L_22 ,
V_41 ,
( unsigned long ) V_113 , V_121 -> V_189 ) ;
V_121 -> V_189 = 0 ;
V_121 -> V_125 = V_130 ;
return V_113 ;
}
static T_1 F_95 ( struct V_42 * V_42 , char T_3 * V_9 ,
T_4 V_113 , T_5 * V_183 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_31 ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
V_31 = F_92 ( V_42 , V_9 , V_113 , V_183 ) ;
F_38 ( & V_11 -> V_45 ) ;
return V_31 ;
}
static int F_96 ( struct V_42 * V_42 , struct V_191 * V_192 )
{
unsigned long V_60 = V_192 -> V_193 - V_192 -> V_194 ,
V_195 = V_192 -> V_194 ;
void * V_196 ;
T_6 V_157 ;
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_22 ( V_197 , L_23 ) ;
if ( ! F_93 ( V_11 ) )
return - V_187 ;
if ( ! ( V_192 -> V_198 & V_199 ) ||
V_60 != F_76 ( V_11 -> V_134 ) ) {
return - V_58 ;
}
for ( V_157 = 0 ; V_157 < V_11 -> V_122 ; V_157 ++ ) {
if ( ( ( F_76 ( V_11 -> V_134 ) * V_157 ) >> V_200 ) ==
V_192 -> V_201 )
break;
}
if ( V_157 == V_11 -> V_122 ) {
F_22 ( V_197 ,
L_24 ) ;
return - V_58 ;
}
V_192 -> V_198 |= V_202 | V_203 | V_204 ;
V_196 = V_11 -> V_121 [ V_157 ] . V_190 ;
while ( V_60 > 0 ) {
if ( F_97 ( V_192 , V_195 , F_98 ( V_196 ) ) ) {
F_22 ( V_197 , L_25 ) ;
return - V_143 ;
}
V_195 += V_205 ;
V_196 += V_205 ;
V_60 -= V_205 ;
}
return 0 ;
}
static int F_99 ( struct V_42 * V_42 , struct V_191 * V_192 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_31 ;
if ( F_23 ( & V_11 -> V_45 ) )
return - V_46 ;
V_31 = F_96 ( V_42 , V_192 ) ;
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
F_17 ( & V_11 -> V_206 -> V_6 ,
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
V_11 -> V_207 = V_43 ;
V_43 = - V_47 ;
goto V_208;
}
V_11 -> V_95 = 1 ;
F_7 ( V_11 , V_82 , V_209 ) ;
F_102 ( V_11 , V_210 ) ;
V_11 -> V_20 ++ ;
}
if ( V_43 ) {
if ( V_51 ) {
F_35 ( V_11 ) ;
F_36 ( V_11 ) ;
V_11 -> V_49 = 0 ;
}
}
V_208:
F_38 ( & V_11 -> V_45 ) ;
return V_43 ;
}
static int F_103 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_28 ) ;
F_40 ( & V_11 -> V_45 ) ;
V_11 -> V_211 = 0 ;
V_43 = F_104 ( V_11 -> V_6 , V_11 -> V_212 ,
V_11 -> V_211 ) ;
F_41 ( V_11 ) ;
V_11 -> V_95 = 0 ;
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
struct V_4 * V_213 ,
char * V_79 )
{
struct V_214 * V_215 = V_11 -> V_6 ;
struct V_4 * V_5 ;
if ( V_215 == NULL ) {
F_17 ( & V_11 -> V_6 -> V_6 ,
L_29 , V_41 ) ;
return NULL ;
}
V_5 = F_106 () ;
if ( NULL == V_5 )
return NULL ;
* V_5 = * V_213 ;
V_5 -> V_216 = & V_11 -> V_45 ;
V_5 -> V_217 = & V_11 -> V_217 ;
snprintf ( V_5 -> V_79 , sizeof( V_5 -> V_79 ) , L_30 , V_79 ) ;
F_107 ( V_5 , V_11 ) ;
return V_5 ;
}
static void F_108 ( struct V_1 * V_11 )
{
if ( V_11 -> V_206 ) {
F_22 ( V_218 , L_31 ,
F_109 ( V_11 -> V_206 ) ) ;
if ( F_110 ( V_11 -> V_206 ) )
F_111 ( V_11 -> V_206 ) ;
else
F_112 ( V_11 -> V_206 ) ;
V_11 -> V_206 = NULL ;
}
if ( V_11 -> V_5 ) {
F_22 ( V_218 , L_31 ,
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
& V_219 ,
L_32 ) ;
if ( V_11 -> V_5 == NULL )
goto V_220;
if ( F_114 ( V_11 -> V_5 , V_221 , V_222 ) < 0 )
goto V_220;
F_46 ( V_53 L_33 ,
V_11 -> V_223 , F_109 ( V_11 -> V_5 ) ) ;
if ( V_12 [ V_11 -> V_13 ] . V_95 ) {
V_11 -> V_206 = F_105 ( V_11 ,
& V_224 ,
L_34 ) ;
if ( V_11 -> V_206 == NULL )
goto V_220;
if ( F_114 ( V_11 -> V_206 , V_225 , V_226 ) < 0 )
goto V_220;
F_46 ( V_53 L_35 ,
V_11 -> V_223 , F_109 ( V_11 -> V_206 ) ) ;
}
return 0 ;
V_220:
F_17 ( & V_11 -> V_6 -> V_6 ,
L_36 ,
V_11 -> V_223 ) ;
F_108 ( V_11 ) ;
return - 1 ;
}
static struct V_1 * F_115 ( struct V_214 * V_6 ,
struct V_227 * V_228 )
{
struct V_1 * V_11 ;
V_11 = F_116 ( sizeof( struct V_1 ) , V_229 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_6 = V_6 ;
if ( F_117 ( & V_228 -> V_6 , & V_11 -> V_217 ) )
goto V_230;
F_118 ( & V_11 -> V_45 ) ;
V_11 -> V_231 = F_119 ( V_232 , V_229 ) ;
if ( V_11 -> V_231 == NULL )
goto V_233;
F_120 ( & V_11 -> V_234 ) ;
F_121 ( V_11 ) ;
return V_11 ;
V_233:
F_122 ( & V_11 -> V_217 ) ;
V_230:
F_123 ( V_11 ) ;
return NULL ;
}
static void F_47 ( struct V_1 * V_11 )
{
F_22 ( V_218 , L_28 ) ;
F_24 ( V_11 ) ;
V_11 -> V_49 = 0 ;
F_18 ( V_11 -> V_5 ) ;
F_108 ( V_11 ) ;
F_124 ( V_11 -> V_231 ) ;
F_122 ( & V_11 -> V_217 ) ;
F_123 ( V_11 ) ;
F_22 ( V_218 , L_5 ) ;
}
static void F_125 ( struct V_1 * V_11 )
{
int V_235 ;
if ( V_11 == NULL )
return;
V_235 = V_11 -> V_13 ;
V_11 -> V_138 = V_165 [ 2 ] ;
if ( V_12 [ V_11 -> V_13 ] . V_236 ) {
V_11 -> V_237 =
V_12 [ V_11 -> V_13 ] . V_238 ;
} else {
V_11 -> V_237 = 0 ;
}
V_11 -> V_91 = V_12 [ V_235 ] . V_239 ;
V_11 -> V_77 = V_12 [ V_235 ] . V_78 ;
V_11 -> V_88 = 0 ;
if ( V_12 [ V_235 ] . V_240 > 0 )
F_41 ( V_11 ) ;
if ( ! V_51 ) {
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
}
}
static int F_126 ( struct V_227 * V_228 ,
const struct V_241 * V_242 )
{
struct V_214 * V_6 = F_127 ( F_128 ( V_228 ) ) ;
struct V_227 * V_243 ;
T_7 V_244 = V_228 -> V_245 -> V_166 . V_246 ;
const struct V_247 * V_248 ;
struct V_1 * V_11 = NULL ;
const struct V_249 * V_250 ;
int V_235 , V_157 ;
F_22 ( V_218 , L_37 ,
V_6 -> V_251 . V_252 ,
V_6 -> V_251 . V_253 , V_244 ) ;
V_235 = V_242 -> V_254 ;
if ( V_235 < 0 || V_235 >= V_255 ) {
F_22 ( V_218 , L_38 , V_235 ) ;
return - V_256 ;
}
F_46 ( V_53 L_39 , V_41 ,
V_12 [ V_235 ] . V_14 ) ;
if ( V_12 [ V_235 ] . V_248 >= 0 )
V_248 = & V_6 -> V_257 -> V_248 [ V_12 [ V_235 ] . V_248 ] -> V_245 [ 0 ] ;
else
V_248 = & V_6 -> V_257 -> V_248 [ V_244 ] -> V_245 [ 0 ] ;
V_250 = & V_248 -> V_250 [ 1 ] . V_166 ;
if ( ! F_129 ( V_250 ) ) {
F_17 ( & V_228 -> V_6 , L_40 ,
V_41 , V_244 ) ;
F_17 ( & V_228 -> V_6 , L_41 ,
V_41 , V_250 -> V_258 ) ;
return - V_256 ;
}
if ( F_130 ( V_250 ) ) {
F_17 ( & V_228 -> V_6 , L_42 ,
V_41 , V_244 ) ;
return - V_256 ;
}
V_11 = F_115 ( V_6 , V_228 ) ;
if ( V_11 == NULL ) {
F_17 ( & V_228 -> V_6 , L_43 , V_41 ) ;
return - V_259 ;
}
if ( V_6 -> V_251 . V_260 > 1 )
V_11 -> V_30 = V_261 ;
else if ( V_235 == V_262 )
V_11 -> V_30 = V_263 ;
else
V_11 -> V_30 = V_264 ;
F_22 ( V_218 , L_44 , V_11 -> V_30 ) ;
V_243 = V_6 -> V_257 -> V_248 [ 0 ] ;
V_11 -> V_265 = V_243 -> V_266 ;
F_22 ( V_218 , L_45 , V_11 -> V_265 ) ;
V_11 -> V_267 = F_131 ( 32 * V_11 -> V_265 , V_229 ) ;
if ( V_11 -> V_267 == NULL ) {
F_17 ( & V_228 -> V_6 , L_46 ) ;
return - V_259 ;
}
for ( V_157 = 0 ; V_157 < V_11 -> V_265 ; V_157 ++ ) {
T_8 V_268 = F_132 ( V_243 -> V_245 [ V_157 ] . V_250 [ 1 ] . V_166 .
V_269 ) ;
V_11 -> V_267 [ V_157 ] =
( V_268 & 0x07ff ) * ( ( ( V_268 & 0x1800 ) >> 11 ) + 1 ) ;
F_22 ( V_218 , L_47 , V_157 ,
V_11 -> V_267 [ V_157 ] ) ;
}
V_11 -> V_223 = V_270 ++ ;
V_11 -> V_71 = V_12 [ V_235 ] . V_82 ;
if ( V_11 -> V_71 )
V_11 -> V_271 = V_12 [ V_235 ] . V_271 ;
V_11 -> V_13 = V_235 ;
V_11 -> V_52 = 0 ;
V_11 -> V_212 = V_244 ;
V_11 -> V_211 = 0 ;
V_11 -> V_272 = V_250 -> V_273 ;
V_11 -> V_274 = 0 ;
V_11 -> V_275 = 0 ;
V_11 -> V_20 = 0 ;
V_11 -> V_26 = V_276 ;
F_125 ( V_11 ) ;
F_113 ( V_11 ) ;
F_15 ( V_11 -> V_5 ) ;
F_22 ( V_218 , L_5 ) ;
return 0 ;
}
static void F_133 ( struct V_227 * V_228 )
{
struct V_1 * V_11 = F_134 ( F_135 ( V_228 ) ) ;
F_22 ( V_218 , L_28 ) ;
if ( V_11 == NULL ) {
F_136 ( L_48 , V_41 ) ;
return;
}
F_40 ( & V_11 -> V_45 ) ;
F_43 ( V_11 ) ;
F_137 ( & V_11 -> V_217 ) ;
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
F_139 ( & V_11 -> V_153 ) ;
F_139 ( & V_11 -> V_277 ) ;
} else {
F_47 ( V_11 ) ;
}
F_22 ( V_218 , L_5 ) ;
}
static int T_9 F_140 ( void )
{
int V_43 ;
F_22 ( V_218 , L_28 ) ;
F_22 ( V_44 , L_50 ) ;
F_22 ( V_218 , L_51 ) ;
F_22 ( V_197 , L_52 ) ;
if ( V_28 != V_29 ) {
V_165 [ 6 ] . V_278 = 0 ;
V_165 [ 7 ] . V_278 = 0 ;
}
V_43 = F_141 ( & V_279 ) ;
if ( V_43 == 0 ) {
F_46 (KERN_INFO DRIVER_DESC L_53 USBVISION_VERSION_STRING L_54 ) ;
F_22 ( V_218 , L_5 ) ;
}
return V_43 ;
}
static void T_10 F_142 ( void )
{
F_22 ( V_218 , L_28 ) ;
F_143 ( & V_279 ) ;
F_22 ( V_218 , L_5 ) ;
}
