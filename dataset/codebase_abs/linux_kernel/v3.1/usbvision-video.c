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
F_23 ( V_11 ) ;
if ( V_11 -> V_20 )
V_43 = - V_45 ;
else {
V_43 = F_24 ( V_11 ) ;
if ( V_28 == V_29 ) {
V_43 = F_25 ( V_11 ) ;
}
if ( V_43 ) {
F_26 ( V_11 ) ;
F_27 ( V_11 ) ;
}
}
if ( ! V_43 ) {
if ( V_11 -> V_46 == 0 ) {
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
}
if ( ! V_11 -> V_47 ) {
int V_48 = 0 ;
V_48 = F_30 ( V_11 , V_28 ) ;
if ( V_48 )
V_11 -> V_47 = 1 ;
else
V_43 = - V_45 ;
}
if ( ! V_43 ) {
F_31 ( V_11 ) ;
V_43 = F_32 ( V_11 ) ;
F_33 ( V_11 , 0 ) ;
V_11 -> V_20 ++ ;
} else {
if ( V_49 ) {
F_34 ( V_11 ) ;
F_35 ( V_11 ) ;
V_11 -> V_47 = 0 ;
}
}
}
F_36 ( V_11 ) ;
F_22 ( V_44 , L_5 ) ;
return V_43 ;
}
static int F_37 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_22 ( V_44 , L_6 ) ;
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
F_40 ( V_11 ) ;
F_27 ( V_11 ) ;
F_41 ( V_11 ) ;
F_36 ( V_11 ) ;
F_26 ( V_11 ) ;
V_11 -> V_20 -- ;
if ( V_49 ) {
F_42 ( V_11 ) ;
V_11 -> V_47 = 0 ;
}
if ( V_11 -> V_50 ) {
F_43 ( V_51 L_7 , V_41 ) ;
F_44 ( V_11 ) ;
}
F_22 ( V_44 , L_5 ) ;
return 0 ;
}
static int F_45 ( struct V_42 * V_42 , void * V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 ;
if ( ! F_46 ( & V_54 -> V_55 ) )
return - V_56 ;
V_43 = F_47 ( V_11 , V_54 -> V_54 & 0xff ) ;
if ( V_43 < 0 ) {
F_17 ( & V_11 -> V_5 -> V_6 ,
L_8 ,
V_41 , V_43 ) ;
return V_43 ;
}
V_54 -> V_57 = V_43 ;
V_54 -> V_58 = 1 ;
return 0 ;
}
static int F_48 ( struct V_42 * V_42 , void * V_52 ,
struct V_53 * V_54 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 ;
if ( ! F_46 ( & V_54 -> V_55 ) )
return - V_56 ;
V_43 = F_49 ( V_11 , V_54 -> V_54 & 0xff , V_54 -> V_57 ) ;
if ( V_43 < 0 ) {
F_17 ( & V_11 -> V_5 -> V_6 ,
L_9 ,
V_41 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_50 ( struct V_42 * V_42 , void * V_52 ,
struct V_59 * V_60 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_51 ( V_60 -> V_61 , L_10 , sizeof( V_60 -> V_61 ) ) ;
F_51 ( V_60 -> V_62 ,
V_12 [ V_11 -> V_13 ] . V_14 ,
sizeof( V_60 -> V_62 ) ) ;
F_52 ( V_11 -> V_6 , V_60 -> V_63 , sizeof( V_60 -> V_63 ) ) ;
V_60 -> V_64 = V_65 |
V_66 |
V_67 |
V_68 |
( V_11 -> V_69 ? V_70 : 0 ) ;
return 0 ;
}
static int F_53 ( struct V_42 * V_42 , void * V_52 ,
struct V_71 * V_72 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_73 ;
if ( V_72 -> V_74 >= V_11 -> V_75 )
return - V_56 ;
if ( V_11 -> V_69 )
V_73 = V_72 -> V_74 ;
else
V_73 = V_72 -> V_74 + 1 ;
switch ( V_73 ) {
case 0 :
if ( V_12 [ V_11 -> V_13 ] . V_76 == 4 ) {
strcpy ( V_72 -> V_77 , L_11 ) ;
} else {
strcpy ( V_72 -> V_77 , L_12 ) ;
V_72 -> type = V_78 ;
V_72 -> V_79 = 1 ;
V_72 -> V_80 = V_73 ;
V_72 -> V_81 = V_82 ;
}
break;
case 1 :
V_72 -> type = V_83 ;
if ( V_12 [ V_11 -> V_13 ] . V_76 == 4 )
strcpy ( V_72 -> V_77 , L_13 ) ;
else
strcpy ( V_72 -> V_77 , L_14 ) ;
V_72 -> V_81 = V_84 ;
break;
case 2 :
V_72 -> type = V_83 ;
if ( V_12 [ V_11 -> V_13 ] . V_76 == 4 )
strcpy ( V_72 -> V_77 , L_15 ) ;
else
strcpy ( V_72 -> V_77 , L_16 ) ;
V_72 -> V_81 = V_84 ;
break;
case 3 :
V_72 -> type = V_83 ;
strcpy ( V_72 -> V_77 , L_17 ) ;
V_72 -> V_81 = V_84 ;
break;
}
return 0 ;
}
static int F_54 ( struct V_42 * V_42 , void * V_52 , unsigned int * V_85 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
* V_85 = V_11 -> V_86 ;
return 0 ;
}
static int F_55 ( struct V_42 * V_42 , void * V_52 , unsigned int V_85 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_85 >= V_11 -> V_75 )
return - V_56 ;
F_33 ( V_11 , V_85 ) ;
F_56 ( V_11 ) ;
F_57 ( V_11 ,
V_11 -> V_87 ,
V_11 -> V_88 ) ;
return 0 ;
}
static int F_58 ( struct V_42 * V_42 , void * V_52 , T_2 * V_17 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_89 = * V_17 ;
F_7 ( V_11 , V_21 , V_90 , V_11 -> V_89 ) ;
F_33 ( V_11 , V_11 -> V_86 ) ;
return 0 ;
}
static int F_59 ( struct V_42 * V_42 , void * V_52 ,
struct V_91 * V_92 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_92 -> V_74 )
return - V_56 ;
if ( V_11 -> V_93 ) {
strcpy ( V_92 -> V_77 , L_18 ) ;
V_92 -> type = V_94 ;
} else {
strcpy ( V_92 -> V_77 , L_12 ) ;
}
F_7 ( V_11 , V_80 , V_95 , V_92 ) ;
return 0 ;
}
static int F_60 ( struct V_42 * V_42 , void * V_52 ,
struct V_91 * V_92 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_92 -> V_74 )
return - V_56 ;
F_7 ( V_11 , V_80 , V_96 , V_92 ) ;
return 0 ;
}
static int F_61 ( struct V_42 * V_42 , void * V_52 ,
struct V_97 * V_98 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_98 -> V_80 = 0 ;
if ( V_11 -> V_93 )
V_98 -> type = V_94 ;
else
V_98 -> type = V_99 ;
V_98 -> V_100 = V_11 -> V_98 ;
return 0 ;
}
static int F_62 ( struct V_42 * V_42 , void * V_52 ,
struct V_97 * V_98 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( ! V_11 -> V_69 || V_98 -> V_80 )
return - V_56 ;
V_11 -> V_98 = V_98 -> V_100 ;
F_7 ( V_11 , V_80 , V_101 , V_98 ) ;
return 0 ;
}
static int F_63 ( struct V_42 * V_42 , void * V_52 , struct V_102 * V_103 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( V_11 -> V_93 )
strcpy ( V_103 -> V_77 , L_18 ) ;
else
strcpy ( V_103 -> V_77 , L_19 ) ;
return 0 ;
}
static int F_64 ( struct V_42 * V_42 , void * V_104 ,
struct V_102 * V_103 )
{
if ( V_103 -> V_74 )
return - V_56 ;
return 0 ;
}
static int F_65 ( struct V_42 * V_42 , void * V_52 ,
struct V_105 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_106 , V_16 ) ;
if ( ! V_16 -> type )
return - V_56 ;
return 0 ;
}
static int F_66 ( struct V_42 * V_42 , void * V_52 ,
struct V_15 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_22 , V_16 ) ;
return 0 ;
}
static int F_67 ( struct V_42 * V_42 , void * V_52 ,
struct V_15 * V_16 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_7 ( V_11 , V_21 , V_107 , V_16 ) ;
return 0 ;
}
static int F_68 ( struct V_42 * V_42 ,
void * V_52 , struct V_108 * V_109 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_110 ;
F_69 ( V_109 -> V_111 , 1 , V_112 ) ;
if ( V_109 -> V_113 != V_114 )
return - V_56 ;
if ( V_11 -> V_26 == V_27 ) {
V_110 = F_70 ( V_11 ) ;
if ( V_110 )
return V_110 ;
}
F_41 ( V_11 ) ;
F_36 ( V_11 ) ;
V_109 -> V_111 = F_71 ( V_11 , V_109 -> V_111 ) ;
V_11 -> V_115 = NULL ;
return 0 ;
}
static int F_72 ( struct V_42 * V_42 ,
void * V_52 , struct V_116 * V_117 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_118 * V_119 ;
if ( V_117 -> V_74 >= V_11 -> V_120 )
return - V_56 ;
V_117 -> V_121 = 0 ;
V_119 = & V_11 -> V_119 [ V_117 -> V_74 ] ;
if ( V_119 -> V_122 >= V_123 )
V_117 -> V_121 |= V_124 ;
if ( V_119 -> V_122 >= V_125 )
V_117 -> V_121 |= V_126 ;
if ( V_119 -> V_122 == V_127 )
V_117 -> V_121 |= V_128 ;
V_117 -> V_113 = V_114 ;
V_117 -> V_129 . V_130 = V_117 -> V_74 * F_73 ( V_11 -> V_131 ) ;
V_117 -> V_113 = V_114 ;
V_117 -> V_132 = V_133 ;
V_117 -> V_134 = V_11 -> V_87 *
V_11 -> V_88 *
V_11 -> V_135 . V_136 ;
V_117 -> V_137 = V_11 -> V_119 [ V_117 -> V_74 ] . V_137 ;
V_117 -> V_138 = V_11 -> V_119 [ V_117 -> V_74 ] . V_138 ;
return 0 ;
}
static int F_74 ( struct V_42 * V_42 , void * V_52 , struct V_116 * V_117 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
struct V_118 * V_119 ;
unsigned long V_139 ;
if ( V_117 -> V_74 >= V_11 -> V_120 )
return - V_56 ;
V_119 = & V_11 -> V_119 [ V_117 -> V_74 ] ;
if ( V_119 -> V_122 != V_127 )
return - V_140 ;
V_119 -> V_122 = V_123 ;
V_119 -> V_141 = V_142 ;
V_119 -> V_143 = 0 ;
V_117 -> V_121 &= ~ V_126 ;
V_119 -> V_144 = V_11 -> V_135 ;
F_75 ( & V_11 -> V_145 , V_139 ) ;
F_76 ( & V_11 -> V_119 [ V_117 -> V_74 ] . V_119 , & V_11 -> V_146 ) ;
F_77 ( & V_11 -> V_145 , V_139 ) ;
return 0 ;
}
static int F_78 ( struct V_42 * V_42 , void * V_52 , struct V_116 * V_117 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_110 ;
struct V_118 * V_147 ;
unsigned long V_139 ;
if ( F_79 ( & ( V_11 -> V_148 ) ) ) {
if ( V_11 -> V_26 == V_149 )
return - V_56 ;
V_110 = F_80
( V_11 -> V_150 ,
! F_79 ( & ( V_11 -> V_148 ) ) ) ;
if ( V_110 )
return V_110 ;
}
F_75 ( & V_11 -> V_145 , V_139 ) ;
V_147 = F_81 ( V_11 -> V_148 . V_151 ,
struct V_118 , V_119 ) ;
F_82 ( V_11 -> V_148 . V_151 ) ;
F_77 ( & V_11 -> V_145 , V_139 ) ;
V_147 -> V_122 = V_127 ;
V_117 -> V_113 = V_114 ;
V_117 -> V_121 = V_128 |
V_124 |
V_126 ;
V_117 -> V_74 = V_147 -> V_74 ;
V_117 -> V_138 = V_147 -> V_138 ;
V_117 -> V_137 = V_147 -> V_137 ;
V_117 -> V_132 = V_133 ;
V_117 -> V_152 = V_147 -> V_143 ;
return 0 ;
}
static int F_83 ( struct V_42 * V_42 , void * V_52 , enum V_153 V_154 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_155 , V_156 , 1 ) ;
return 0 ;
}
static int F_84 ( struct V_42 * V_42 ,
void * V_52 , enum V_153 type )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
if ( type != V_157 )
return - V_56 ;
if ( V_11 -> V_26 == V_27 ) {
F_70 ( V_11 ) ;
F_7 ( V_11 , V_155 , V_156 , 0 ) ;
}
F_36 ( V_11 ) ;
return 0 ;
}
static int F_85 ( struct V_42 * V_42 , void * V_52 ,
struct V_158 * V_159 )
{
if ( V_159 -> V_74 >= V_160 - 1 )
return - V_56 ;
strcpy ( V_159 -> V_161 , V_162 [ V_159 -> V_74 ] . V_163 ) ;
V_159 -> V_164 = V_162 [ V_159 -> V_74 ] . V_165 ;
return 0 ;
}
static int F_86 ( struct V_42 * V_42 , void * V_52 ,
struct V_144 * V_166 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
V_166 -> V_167 . V_168 . V_169 = V_11 -> V_87 ;
V_166 -> V_167 . V_168 . V_170 = V_11 -> V_88 ;
V_166 -> V_167 . V_168 . V_164 = V_11 -> V_135 . V_165 ;
V_166 -> V_167 . V_168 . V_171 =
V_11 -> V_87 * V_11 -> V_135 . V_136 ;
V_166 -> V_167 . V_168 . V_172 = V_166 -> V_167 . V_168 . V_171 * V_11 -> V_88 ;
V_166 -> V_167 . V_168 . V_173 = V_174 ;
V_166 -> V_167 . V_168 . V_132 = V_133 ;
return 0 ;
}
static int F_87 ( struct V_42 * V_42 , void * V_52 ,
struct V_144 * V_166 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_175 ;
for ( V_175 = 0 ; V_175 < V_160 ; V_175 ++ ) {
if ( V_166 -> V_167 . V_168 . V_164 ==
V_162 [ V_175 ] . V_165 ) {
V_11 -> V_135 = V_162 [ V_175 ] ;
break;
}
}
if ( V_175 == V_160 )
return - V_56 ;
F_69 ( V_166 -> V_167 . V_168 . V_169 , V_176 , V_177 ) ;
F_69 ( V_166 -> V_167 . V_168 . V_170 , V_178 , V_179 ) ;
V_166 -> V_167 . V_168 . V_171 = V_166 -> V_167 . V_168 . V_169 *
V_11 -> V_135 . V_136 ;
V_166 -> V_167 . V_168 . V_172 = V_166 -> V_167 . V_168 . V_171 * V_166 -> V_167 . V_168 . V_170 ;
return 0 ;
}
static int F_88 ( struct V_42 * V_42 , void * V_52 ,
struct V_144 * V_166 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_110 ;
V_110 = F_87 ( V_42 , V_52 , V_166 ) ;
if ( V_110 )
return V_110 ;
if ( V_11 -> V_26 == V_27 ) {
V_110 = F_70 ( V_11 ) ;
if ( V_110 )
return V_110 ;
}
F_41 ( V_11 ) ;
F_36 ( V_11 ) ;
V_11 -> V_115 = NULL ;
F_57 ( V_11 , V_166 -> V_167 . V_168 . V_169 , V_166 -> V_167 . V_168 . V_170 ) ;
return 0 ;
}
static T_1 F_89 ( struct V_42 * V_42 , char T_3 * V_9 ,
T_4 V_111 , T_5 * V_180 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_181 = V_42 -> V_182 & V_183 ;
unsigned long V_139 ;
int V_110 , V_154 ;
struct V_118 * V_119 ;
F_22 ( V_44 , L_20 , V_41 ,
( unsigned long ) V_111 , V_181 ) ;
if ( ! F_90 ( V_11 ) || ( V_9 == NULL ) )
return - V_184 ;
if ( ! V_11 -> V_120 ) {
F_41 ( V_11 ) ;
F_36 ( V_11 ) ;
F_71 ( V_11 , V_112 ) ;
}
if ( V_11 -> V_26 != V_27 ) {
V_11 -> V_26 = V_27 ;
F_7 ( V_11 , V_155 , V_156 , 1 ) ;
}
for ( V_154 = 0 ; V_154 < V_11 -> V_120 ; V_154 ++ ) {
V_119 = & V_11 -> V_119 [ V_154 ] ;
if ( V_119 -> V_122 == V_127 ) {
V_119 -> V_122 = V_123 ;
V_119 -> V_141 = V_142 ;
V_119 -> V_143 = 0 ;
V_119 -> V_144 = V_11 -> V_135 ;
F_75 ( & V_11 -> V_145 , V_139 ) ;
F_76 ( & V_119 -> V_119 , & V_11 -> V_146 ) ;
F_77 ( & V_11 -> V_145 ,
V_139 ) ;
}
}
if ( F_79 ( & ( V_11 -> V_148 ) ) ) {
if ( V_181 )
return - V_140 ;
V_110 = F_80
( V_11 -> V_150 ,
! F_79 ( & ( V_11 -> V_148 ) ) ) ;
if ( V_110 )
return V_110 ;
}
F_75 ( & V_11 -> V_145 , V_139 ) ;
V_119 = F_81 ( V_11 -> V_148 . V_151 ,
struct V_118 , V_119 ) ;
F_82 ( V_11 -> V_148 . V_151 ) ;
F_77 ( & V_11 -> V_145 , V_139 ) ;
if ( V_119 -> V_122 == V_185 ) {
V_119 -> V_186 = 0 ;
return 0 ;
}
F_22 ( V_44 , L_21 ,
V_41 ,
V_119 -> V_74 , V_119 -> V_186 , V_119 -> V_143 ) ;
if ( ( V_111 + V_119 -> V_186 ) > ( unsigned long ) V_119 -> V_143 )
V_111 = V_119 -> V_143 - V_119 -> V_186 ;
if ( F_91 ( V_9 , V_119 -> V_187 + V_119 -> V_186 , V_111 ) )
return - V_184 ;
V_119 -> V_186 += V_111 ;
F_22 ( V_44 , L_22 ,
V_41 ,
( unsigned long ) V_111 , V_119 -> V_186 ) ;
V_119 -> V_186 = 0 ;
V_119 -> V_122 = V_127 ;
return V_111 ;
}
static int F_92 ( struct V_42 * V_42 , struct V_188 * V_189 )
{
unsigned long V_58 = V_189 -> V_190 - V_189 -> V_191 ,
V_192 = V_189 -> V_191 ;
void * V_193 ;
T_6 V_154 ;
struct V_1 * V_11 = F_21 ( V_42 ) ;
F_22 ( V_194 , L_23 ) ;
if ( ! F_90 ( V_11 ) )
return - V_184 ;
if ( ! ( V_189 -> V_195 & V_196 ) ||
V_58 != F_73 ( V_11 -> V_131 ) ) {
return - V_56 ;
}
for ( V_154 = 0 ; V_154 < V_11 -> V_120 ; V_154 ++ ) {
if ( ( ( F_73 ( V_11 -> V_131 ) * V_154 ) >> V_197 ) ==
V_189 -> V_198 )
break;
}
if ( V_154 == V_11 -> V_120 ) {
F_22 ( V_194 ,
L_24 ) ;
return - V_56 ;
}
V_189 -> V_195 |= V_199 ;
V_189 -> V_195 |= V_200 ;
V_193 = V_11 -> V_119 [ V_154 ] . V_187 ;
while ( V_58 > 0 ) {
if ( F_93 ( V_189 , V_192 , F_94 ( V_193 ) ) ) {
F_22 ( V_194 , L_25 ) ;
return - V_140 ;
}
V_192 += V_201 ;
V_193 += V_201 ;
V_58 -= V_201 ;
}
return 0 ;
}
static int F_95 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_26 , V_41 ) ;
if ( V_11 -> V_20 ) {
F_17 ( & V_11 -> V_202 -> V_6 ,
L_27 ,
V_41 ) ;
V_43 = - V_45 ;
} else {
if ( V_49 ) {
F_23 ( V_11 ) ;
if ( V_11 -> V_46 == 0 ) {
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
}
}
V_43 = F_96 ( V_11 ) ;
if ( V_43 < 0 ) {
V_11 -> V_203 = V_43 ;
V_43 = - V_45 ;
goto V_204;
}
V_11 -> V_93 = 1 ;
F_7 ( V_11 , V_80 , V_205 ) ;
F_97 ( V_11 , V_206 ) ;
V_11 -> V_20 ++ ;
}
if ( V_43 ) {
if ( V_49 ) {
F_34 ( V_11 ) ;
F_35 ( V_11 ) ;
V_11 -> V_47 = 0 ;
}
}
V_204:
return V_43 ;
}
static int F_98 ( struct V_42 * V_42 )
{
struct V_1 * V_11 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_28 ) ;
V_11 -> V_207 = 0 ;
V_43 = F_99 ( V_11 -> V_6 , V_11 -> V_208 ,
V_11 -> V_207 ) ;
F_38 ( V_11 ) ;
V_11 -> V_93 = 0 ;
V_11 -> V_20 -- ;
if ( V_49 ) {
F_42 ( V_11 ) ;
V_11 -> V_47 = 0 ;
}
if ( V_11 -> V_50 ) {
F_43 ( V_51 L_7 , V_41 ) ;
F_44 ( V_11 ) ;
}
F_22 ( V_44 , L_5 ) ;
return V_43 ;
}
static struct V_4 * F_100 ( struct V_1 * V_11 ,
struct V_4 * V_209 ,
char * V_77 )
{
struct V_210 * V_211 = V_11 -> V_6 ;
struct V_4 * V_5 ;
if ( V_211 == NULL ) {
F_17 ( & V_11 -> V_6 -> V_6 ,
L_29 , V_41 ) ;
return NULL ;
}
V_5 = F_101 () ;
if ( NULL == V_5 )
return NULL ;
* V_5 = * V_209 ;
V_5 -> V_212 = & V_11 -> V_213 ;
V_5 -> V_214 = & V_11 -> V_214 ;
snprintf ( V_5 -> V_77 , sizeof( V_5 -> V_77 ) , L_30 , V_77 ) ;
F_102 ( V_5 , V_11 ) ;
return V_5 ;
}
static void F_103 ( struct V_1 * V_11 )
{
if ( V_11 -> V_202 ) {
F_22 ( V_215 , L_31 ,
F_104 ( V_11 -> V_202 ) ) ;
if ( F_105 ( V_11 -> V_202 ) )
F_106 ( V_11 -> V_202 ) ;
else
F_107 ( V_11 -> V_202 ) ;
V_11 -> V_202 = NULL ;
}
if ( V_11 -> V_5 ) {
F_22 ( V_215 , L_31 ,
F_104 ( V_11 -> V_5 ) ) ;
if ( F_105 ( V_11 -> V_5 ) )
F_106 ( V_11 -> V_5 ) ;
else
F_107 ( V_11 -> V_5 ) ;
V_11 -> V_5 = NULL ;
}
}
static int T_7 F_108 ( struct V_1 * V_11 )
{
V_11 -> V_5 = F_100 ( V_11 ,
& V_216 ,
L_32 ) ;
if ( V_11 -> V_5 == NULL )
goto V_217;
if ( F_109 ( V_11 -> V_5 , V_218 , V_219 ) < 0 )
goto V_217;
F_43 ( V_51 L_33 ,
V_11 -> V_220 , F_104 ( V_11 -> V_5 ) ) ;
if ( V_12 [ V_11 -> V_13 ] . V_93 ) {
V_11 -> V_202 = F_100 ( V_11 ,
& V_221 ,
L_34 ) ;
if ( V_11 -> V_202 == NULL )
goto V_217;
if ( F_109 ( V_11 -> V_202 , V_222 , V_223 ) < 0 )
goto V_217;
F_43 ( V_51 L_35 ,
V_11 -> V_220 , F_104 ( V_11 -> V_202 ) ) ;
}
return 0 ;
V_217:
F_17 ( & V_11 -> V_6 -> V_6 ,
L_36 ,
V_11 -> V_220 ) ;
F_103 ( V_11 ) ;
return - 1 ;
}
static struct V_1 * F_110 ( struct V_210 * V_6 ,
struct V_224 * V_225 )
{
struct V_1 * V_11 ;
V_11 = F_111 ( sizeof( struct V_1 ) , V_226 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_6 = V_6 ;
if ( F_112 ( & V_225 -> V_6 , & V_11 -> V_214 ) )
goto V_227;
F_113 ( & V_11 -> V_213 ) ;
V_11 -> V_228 = F_114 ( V_229 , V_226 ) ;
if ( V_11 -> V_228 == NULL )
goto V_230;
F_115 ( & V_11 -> V_231 ) ;
F_116 ( V_11 ) ;
return V_11 ;
V_230:
F_117 ( & V_11 -> V_214 ) ;
V_227:
F_118 ( V_11 ) ;
return NULL ;
}
static void F_44 ( struct V_1 * V_11 )
{
F_22 ( V_215 , L_28 ) ;
F_23 ( V_11 ) ;
V_11 -> V_47 = 0 ;
F_18 ( V_11 -> V_5 ) ;
F_103 ( V_11 ) ;
F_119 ( V_11 -> V_228 ) ;
F_117 ( & V_11 -> V_214 ) ;
F_118 ( V_11 ) ;
F_22 ( V_215 , L_5 ) ;
}
static void F_120 ( struct V_1 * V_11 )
{
int V_232 ;
if ( V_11 == NULL )
return;
V_232 = V_11 -> V_13 ;
V_11 -> V_135 = V_162 [ 2 ] ;
if ( V_12 [ V_11 -> V_13 ] . V_233 ) {
V_11 -> V_234 =
V_12 [ V_11 -> V_13 ] . V_235 ;
} else {
V_11 -> V_234 = 0 ;
}
V_11 -> V_89 = V_12 [ V_232 ] . V_236 ;
V_11 -> V_75 = V_12 [ V_232 ] . V_76 ;
V_11 -> V_86 = 0 ;
if ( V_12 [ V_232 ] . V_237 > 0 )
F_38 ( V_11 ) ;
if ( ! V_49 ) {
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
}
}
static int T_7 F_121 ( struct V_224 * V_225 ,
const struct V_238 * V_239 )
{
struct V_210 * V_6 = F_122 ( F_123 ( V_225 ) ) ;
struct V_224 * V_240 ;
T_8 V_241 = V_225 -> V_242 -> V_163 . V_243 ;
const struct V_244 * V_245 ;
struct V_1 * V_11 = NULL ;
const struct V_246 * V_247 ;
int V_232 , V_154 ;
F_22 ( V_215 , L_37 ,
V_6 -> V_248 . V_249 ,
V_6 -> V_248 . V_250 , V_241 ) ;
V_232 = V_239 -> V_251 ;
if ( V_232 < 0 || V_232 >= V_252 ) {
F_22 ( V_215 , L_38 , V_232 ) ;
return - V_253 ;
}
F_43 ( V_51 L_39 , V_41 ,
V_12 [ V_232 ] . V_14 ) ;
if ( V_12 [ V_232 ] . V_245 >= 0 )
V_245 = & V_6 -> V_254 -> V_245 [ V_12 [ V_232 ] . V_245 ] -> V_242 [ 0 ] ;
else
V_245 = & V_6 -> V_254 -> V_245 [ V_241 ] -> V_242 [ 0 ] ;
V_247 = & V_245 -> V_247 [ 1 ] . V_163 ;
if ( ! F_124 ( V_247 ) ) {
F_17 ( & V_225 -> V_6 , L_40 ,
V_41 , V_241 ) ;
F_17 ( & V_225 -> V_6 , L_41 ,
V_41 , V_247 -> V_255 ) ;
return - V_253 ;
}
if ( F_125 ( V_247 ) ) {
F_17 ( & V_225 -> V_6 , L_42 ,
V_41 , V_241 ) ;
return - V_253 ;
}
V_11 = F_110 ( V_6 , V_225 ) ;
if ( V_11 == NULL ) {
F_17 ( & V_225 -> V_6 , L_43 , V_41 ) ;
return - V_256 ;
}
if ( V_6 -> V_248 . V_257 > 1 )
V_11 -> V_30 = V_258 ;
else if ( V_232 == V_259 )
V_11 -> V_30 = V_260 ;
else
V_11 -> V_30 = V_261 ;
F_22 ( V_215 , L_44 , V_11 -> V_30 ) ;
V_240 = V_6 -> V_254 -> V_245 [ 0 ] ;
V_11 -> V_262 = V_240 -> V_263 ;
F_22 ( V_215 , L_45 , V_11 -> V_262 ) ;
V_11 -> V_264 = F_126 ( 32 * V_11 -> V_262 , V_226 ) ;
if ( V_11 -> V_264 == NULL ) {
F_17 ( & V_225 -> V_6 , L_46 ) ;
return - V_256 ;
}
for ( V_154 = 0 ; V_154 < V_11 -> V_262 ; V_154 ++ ) {
T_9 V_265 = F_127 ( V_240 -> V_242 [ V_154 ] . V_247 [ 1 ] . V_163 .
V_266 ) ;
V_11 -> V_264 [ V_154 ] =
( V_265 & 0x07ff ) * ( ( ( V_265 & 0x1800 ) >> 11 ) + 1 ) ;
F_22 ( V_215 , L_47 , V_154 ,
V_11 -> V_264 [ V_154 ] ) ;
}
V_11 -> V_220 = V_267 ++ ;
V_11 -> V_69 = V_12 [ V_232 ] . V_80 ;
if ( V_11 -> V_69 )
V_11 -> V_268 = V_12 [ V_232 ] . V_268 ;
V_11 -> V_13 = V_232 ;
V_11 -> V_50 = 0 ;
V_11 -> V_208 = V_241 ;
V_11 -> V_207 = 0 ;
V_11 -> V_269 = V_247 -> V_270 ;
V_11 -> V_271 = 0 ;
V_11 -> V_272 = 0 ;
V_11 -> V_20 = 0 ;
V_11 -> V_26 = V_273 ;
F_120 ( V_11 ) ;
F_108 ( V_11 ) ;
F_15 ( V_11 -> V_5 ) ;
F_22 ( V_215 , L_5 ) ;
return 0 ;
}
static void T_10 F_128 ( struct V_224 * V_225 )
{
struct V_1 * V_11 = F_129 ( F_130 ( V_225 ) ) ;
F_22 ( V_215 , L_28 ) ;
if ( V_11 == NULL ) {
F_131 ( L_48 , V_41 ) ;
return;
}
F_132 ( & V_11 -> V_213 ) ;
F_40 ( V_11 ) ;
F_133 ( & V_11 -> V_214 ) ;
if ( V_11 -> V_46 ) {
F_34 ( V_11 ) ;
F_35 ( V_11 ) ;
}
V_11 -> V_50 = 1 ;
F_134 ( V_11 -> V_6 ) ;
V_11 -> V_6 = NULL ;
F_135 ( & V_11 -> V_213 ) ;
if ( V_11 -> V_20 ) {
F_43 ( V_51 L_49 ,
V_41 ) ;
F_136 ( & V_11 -> V_150 ) ;
F_136 ( & V_11 -> V_274 ) ;
} else {
F_44 ( V_11 ) ;
}
F_22 ( V_215 , L_5 ) ;
}
static int T_11 F_137 ( void )
{
int V_43 ;
F_22 ( V_215 , L_28 ) ;
F_22 ( V_44 , L_50 ) ;
F_22 ( V_215 , L_51 ) ;
F_22 ( V_194 , L_52 ) ;
if ( V_28 != V_29 ) {
V_162 [ 6 ] . V_275 = 0 ;
V_162 [ 7 ] . V_275 = 0 ;
}
V_43 = F_138 ( & V_276 ) ;
if ( V_43 == 0 ) {
F_43 (KERN_INFO DRIVER_DESC L_53 USBVISION_VERSION_STRING L_54 ) ;
F_22 ( V_215 , L_5 ) ;
}
return V_43 ;
}
static void T_12 F_139 ( void )
{
F_22 ( V_215 , L_28 ) ;
F_140 ( & V_276 ) ;
F_22 ( V_215 , L_5 ) ;
}
