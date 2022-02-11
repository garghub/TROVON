static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
return sprintf ( V_8 , L_1 , V_9 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_1 ,
V_11 [ V_10 -> V_12 ] . V_13 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
struct V_14 V_15 ;
V_15 . V_16 = V_17 ;
V_15 . V_18 = 0 ;
if ( V_10 -> V_19 )
F_7 ( V_10 , V_20 , V_21 , & V_15 ) ;
return sprintf ( V_8 , L_2 , V_15 . V_18 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
struct V_14 V_15 ;
V_15 . V_16 = V_22 ;
V_15 . V_18 = 0 ;
if ( V_10 -> V_19 )
F_7 ( V_10 , V_20 , V_21 , & V_15 ) ;
return sprintf ( V_8 , L_2 , V_15 . V_18 ) ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
struct V_14 V_15 ;
V_15 . V_16 = V_23 ;
V_15 . V_18 = 0 ;
if ( V_10 -> V_19 )
F_7 ( V_10 , V_20 , V_21 , & V_15 ) ;
return sprintf ( V_8 , L_2 , V_15 . V_18 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
struct V_14 V_15 ;
V_15 . V_16 = V_24 ;
V_15 . V_18 = 0 ;
if ( V_10 -> V_19 )
F_7 ( V_10 , V_20 , V_21 , & V_15 ) ;
return sprintf ( V_8 , L_2 , V_15 . V_18 ) ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_1 ,
F_12 ( V_10 -> V_25 == V_26 ? 1 : 0 ) ) ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_1 ,
F_12 ( V_10 -> V_27 == V_28 ) ) ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_2 , V_10 -> V_29 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
int V_30 ;
if ( ! V_5 )
return;
do {
V_30 = F_16 ( & V_5 -> V_31 , & V_32 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_33 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_34 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_35 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_36 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_37 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_38 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_39 ) ;
if ( V_30 < 0 )
break;
V_30 = F_16 ( & V_5 -> V_31 , & V_40 ) ;
if ( V_30 >= 0 )
return;
} while ( 0 );
F_17 ( & V_5 -> V_31 , L_3 , V_41 , V_30 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
if ( V_5 ) {
F_19 ( & V_5 -> V_31 , & V_32 ) ;
F_19 ( & V_5 -> V_31 , & V_33 ) ;
F_19 ( & V_5 -> V_31 , & V_34 ) ;
F_19 ( & V_5 -> V_31 , & V_35 ) ;
F_19 ( & V_5 -> V_31 , & V_36 ) ;
F_19 ( & V_5 -> V_31 , & V_37 ) ;
F_19 ( & V_5 -> V_31 , & V_38 ) ;
F_19 ( & V_5 -> V_31 , & V_39 ) ;
F_19 ( & V_5 -> V_31 , & V_40 ) ;
}
}
static int F_20 ( struct V_42 * V_42 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_4 ) ;
if ( F_23 ( & V_10 -> V_45 ) )
return - V_46 ;
if ( V_10 -> V_19 ) {
V_43 = - V_47 ;
} else {
V_43 = F_24 ( V_42 ) ;
if ( V_43 )
goto V_48;
V_43 = F_25 ( V_10 ) ;
if ( V_27 == V_28 ) {
V_43 = F_26 ( V_10 ) ;
}
if ( V_43 ) {
F_27 ( V_10 ) ;
F_28 ( V_10 ) ;
}
}
if ( ! V_43 ) {
if ( ! V_10 -> V_49 ) {
int V_50 = 0 ;
V_50 = F_29 ( V_10 , V_27 ) ;
if ( V_50 )
V_10 -> V_49 = 1 ;
else
V_43 = - V_47 ;
}
if ( ! V_43 ) {
F_30 ( V_10 ) ;
V_43 = F_31 ( V_10 ) ;
F_32 ( V_10 , 0 ) ;
F_33 ( V_10 ) ;
V_10 -> V_19 ++ ;
}
}
V_48:
F_34 ( & V_10 -> V_45 ) ;
F_22 ( V_44 , L_5 ) ;
return V_43 ;
}
static int F_35 ( struct V_42 * V_42 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
F_22 ( V_44 , L_6 ) ;
F_36 ( & V_10 -> V_45 ) ;
F_37 ( V_10 ) ;
F_38 ( V_10 ) ;
F_39 ( V_10 ) ;
F_28 ( V_10 ) ;
F_40 ( V_10 ) ;
F_33 ( V_10 ) ;
F_27 ( V_10 ) ;
V_10 -> V_19 -- ;
F_34 ( & V_10 -> V_45 ) ;
if ( V_10 -> V_51 ) {
F_41 ( V_52 L_7 , V_41 ) ;
F_42 ( V_10 ) ;
return 0 ;
}
F_22 ( V_44 , L_5 ) ;
return F_43 ( V_42 ) ;
}
static int F_44 ( struct V_42 * V_42 , void * V_53 ,
struct V_54 * V_55 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_43 ;
V_43 = F_45 ( V_10 , V_55 -> V_55 & 0xff ) ;
if ( V_43 < 0 ) {
F_17 ( & V_10 -> V_5 . V_31 ,
L_8 ,
V_41 , V_43 ) ;
return V_43 ;
}
V_55 -> V_56 = V_43 ;
V_55 -> V_57 = 1 ;
return 0 ;
}
static int F_46 ( struct V_42 * V_42 , void * V_53 ,
const struct V_54 * V_55 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_43 ;
V_43 = F_47 ( V_10 , V_55 -> V_55 & 0xff , V_55 -> V_56 ) ;
if ( V_43 < 0 ) {
F_17 ( & V_10 -> V_5 . V_31 ,
L_9 ,
V_41 , V_43 ) ;
return V_43 ;
}
return 0 ;
}
static int F_48 ( struct V_42 * V_42 , void * V_53 ,
struct V_58 * V_59 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
struct V_4 * V_5 = F_49 ( V_42 ) ;
F_50 ( V_59 -> V_60 , L_10 , sizeof( V_59 -> V_60 ) ) ;
F_50 ( V_59 -> V_61 ,
V_11 [ V_10 -> V_12 ] . V_13 ,
sizeof( V_59 -> V_61 ) ) ;
F_51 ( V_10 -> V_31 , V_59 -> V_62 , sizeof( V_59 -> V_62 ) ) ;
V_59 -> V_63 = V_10 -> V_64 ? V_65 : 0 ;
if ( V_5 -> V_66 == V_67 )
V_59 -> V_63 |= V_68 |
V_69 | V_70 ;
else
V_59 -> V_63 |= V_71 ;
V_59 -> V_72 = V_59 -> V_63 | V_68 |
V_69 | V_70 | V_73 ;
if ( V_11 [ V_10 -> V_12 ] . V_74 )
V_59 -> V_72 |= V_71 ;
return 0 ;
}
static int F_52 ( struct V_42 * V_42 , void * V_53 ,
struct V_75 * V_76 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_77 ;
if ( V_76 -> V_78 >= V_10 -> V_79 )
return - V_80 ;
if ( V_10 -> V_64 )
V_77 = V_76 -> V_78 ;
else
V_77 = V_76 -> V_78 + 1 ;
switch ( V_77 ) {
case 0 :
if ( V_11 [ V_10 -> V_12 ] . V_81 == 4 ) {
strcpy ( V_76 -> V_82 , L_11 ) ;
} else {
strcpy ( V_76 -> V_82 , L_12 ) ;
V_76 -> type = V_83 ;
V_76 -> V_84 = V_77 ;
V_76 -> V_85 = V_86 ;
}
break;
case 1 :
V_76 -> type = V_87 ;
if ( V_11 [ V_10 -> V_12 ] . V_81 == 4 )
strcpy ( V_76 -> V_82 , L_13 ) ;
else
strcpy ( V_76 -> V_82 , L_14 ) ;
V_76 -> V_85 = V_86 ;
break;
case 2 :
V_76 -> type = V_87 ;
if ( V_11 [ V_10 -> V_12 ] . V_81 == 4 )
strcpy ( V_76 -> V_82 , L_15 ) ;
else
strcpy ( V_76 -> V_82 , L_16 ) ;
V_76 -> V_85 = V_86 ;
break;
case 3 :
V_76 -> type = V_87 ;
strcpy ( V_76 -> V_82 , L_17 ) ;
V_76 -> V_85 = V_86 ;
break;
}
return 0 ;
}
static int F_53 ( struct V_42 * V_42 , void * V_53 , unsigned int * V_88 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
* V_88 = V_10 -> V_89 ;
return 0 ;
}
static int F_54 ( struct V_42 * V_42 , void * V_53 , unsigned int V_88 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
if ( V_88 >= V_10 -> V_79 )
return - V_80 ;
F_32 ( V_10 , V_88 ) ;
F_55 ( V_10 ) ;
F_56 ( V_10 ,
V_10 -> V_90 ,
V_10 -> V_91 ) ;
return 0 ;
}
static int F_57 ( struct V_42 * V_42 , void * V_53 , T_2 V_16 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
V_10 -> V_92 = V_16 ;
F_7 ( V_10 , V_93 , V_94 , V_10 -> V_92 ) ;
F_32 ( V_10 , V_10 -> V_89 ) ;
return 0 ;
}
static int F_58 ( struct V_42 * V_42 , void * V_53 , T_2 * V_16 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
* V_16 = V_10 -> V_92 ;
return 0 ;
}
static int F_59 ( struct V_42 * V_42 , void * V_53 ,
struct V_95 * V_96 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
if ( V_96 -> V_78 )
return - V_80 ;
if ( V_96 -> type == V_97 )
strcpy ( V_96 -> V_82 , L_18 ) ;
else
strcpy ( V_96 -> V_82 , L_12 ) ;
F_7 ( V_10 , V_84 , V_98 , V_96 ) ;
return 0 ;
}
static int F_60 ( struct V_42 * V_42 , void * V_53 ,
const struct V_95 * V_96 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
if ( V_96 -> V_78 )
return - V_80 ;
F_7 ( V_10 , V_84 , V_99 , V_96 ) ;
return 0 ;
}
static int F_61 ( struct V_42 * V_42 , void * V_53 ,
struct V_100 * V_101 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
if ( V_101 -> V_84 )
return - V_80 ;
if ( V_101 -> type == V_97 )
V_101 -> V_102 = V_10 -> V_103 ;
else
V_101 -> V_102 = V_10 -> V_104 ;
return 0 ;
}
static int F_62 ( struct V_42 * V_42 , void * V_53 ,
const struct V_100 * V_101 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
struct V_100 V_105 = * V_101 ;
if ( V_101 -> V_84 )
return - V_80 ;
F_7 ( V_10 , V_84 , V_106 , V_101 ) ;
F_7 ( V_10 , V_84 , V_107 , & V_105 ) ;
if ( V_101 -> type == V_97 )
V_10 -> V_103 = V_105 . V_102 ;
else
V_10 -> V_104 = V_105 . V_102 ;
return 0 ;
}
static int F_63 ( struct V_42 * V_42 ,
void * V_53 , struct V_108 * V_109 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_110 ;
F_64 ( V_109 -> V_111 , 1 , V_112 ) ;
if ( V_109 -> V_113 != V_114 )
return - V_80 ;
if ( V_10 -> V_25 == V_26 ) {
V_110 = F_65 ( V_10 ) ;
if ( V_110 )
return V_110 ;
}
F_40 ( V_10 ) ;
F_33 ( V_10 ) ;
V_109 -> V_111 = F_66 ( V_10 , V_109 -> V_111 ) ;
V_10 -> V_115 = NULL ;
return 0 ;
}
static int F_67 ( struct V_42 * V_42 ,
void * V_53 , struct V_116 * V_117 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
struct V_118 * V_119 ;
if ( V_117 -> V_78 >= V_10 -> V_120 )
return - V_80 ;
V_117 -> V_121 = V_122 ;
V_119 = & V_10 -> V_119 [ V_117 -> V_78 ] ;
if ( V_119 -> V_123 >= V_124 )
V_117 -> V_121 |= V_125 ;
if ( V_119 -> V_123 >= V_126 )
V_117 -> V_121 |= V_127 ;
if ( V_119 -> V_123 == V_128 )
V_117 -> V_121 |= V_129 ;
V_117 -> V_113 = V_114 ;
V_117 -> V_130 . V_131 = V_117 -> V_78 * F_68 ( V_10 -> V_132 ) ;
V_117 -> V_113 = V_114 ;
V_117 -> V_133 = V_134 ;
V_117 -> V_135 = V_10 -> V_90 *
V_10 -> V_91 *
V_10 -> V_136 . V_137 ;
V_117 -> V_138 = V_10 -> V_119 [ V_117 -> V_78 ] . V_138 ;
V_117 -> V_139 = V_10 -> V_119 [ V_117 -> V_78 ] . V_139 ;
return 0 ;
}
static int F_69 ( struct V_42 * V_42 , void * V_53 , struct V_116 * V_117 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
struct V_118 * V_119 ;
unsigned long V_140 ;
if ( V_117 -> V_78 >= V_10 -> V_120 )
return - V_80 ;
V_119 = & V_10 -> V_119 [ V_117 -> V_78 ] ;
if ( V_119 -> V_123 != V_128 )
return - V_141 ;
V_119 -> V_123 = V_124 ;
V_119 -> V_142 = V_143 ;
V_119 -> V_144 = 0 ;
V_117 -> V_121 &= ~ V_127 ;
V_119 -> V_145 = V_10 -> V_136 ;
F_70 ( & V_10 -> V_146 , V_140 ) ;
F_71 ( & V_10 -> V_119 [ V_117 -> V_78 ] . V_119 , & V_10 -> V_147 ) ;
F_72 ( & V_10 -> V_146 , V_140 ) ;
return 0 ;
}
static int F_73 ( struct V_42 * V_42 , void * V_53 , struct V_116 * V_117 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_110 ;
struct V_118 * V_148 ;
unsigned long V_140 ;
if ( F_74 ( & ( V_10 -> V_149 ) ) ) {
if ( V_10 -> V_25 == V_150 )
return - V_80 ;
V_110 = F_75
( V_10 -> V_151 ,
! F_74 ( & ( V_10 -> V_149 ) ) ) ;
if ( V_110 )
return V_110 ;
}
F_70 ( & V_10 -> V_146 , V_140 ) ;
V_148 = F_76 ( V_10 -> V_149 . V_152 ,
struct V_118 , V_119 ) ;
F_77 ( V_10 -> V_149 . V_152 ) ;
F_72 ( & V_10 -> V_146 , V_140 ) ;
V_148 -> V_123 = V_128 ;
V_117 -> V_113 = V_114 ;
V_117 -> V_121 = V_129 |
V_125 |
V_127 |
V_122 ;
V_117 -> V_78 = V_148 -> V_78 ;
V_117 -> V_139 = V_148 -> V_139 ;
V_117 -> V_138 = V_148 -> V_138 ;
V_117 -> V_133 = V_134 ;
V_117 -> V_153 = V_148 -> V_144 ;
return 0 ;
}
static int F_78 ( struct V_42 * V_42 , void * V_53 , enum V_154 V_155 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
V_10 -> V_25 = V_26 ;
F_7 ( V_10 , V_93 , V_156 , 1 ) ;
return 0 ;
}
static int F_79 ( struct V_42 * V_42 ,
void * V_53 , enum V_154 type )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
if ( type != V_157 )
return - V_80 ;
if ( V_10 -> V_25 == V_26 ) {
F_65 ( V_10 ) ;
F_7 ( V_10 , V_93 , V_156 , 0 ) ;
}
F_33 ( V_10 ) ;
return 0 ;
}
static int F_80 ( struct V_42 * V_42 , void * V_53 ,
struct V_158 * V_159 )
{
if ( V_159 -> V_78 >= V_160 - 1 )
return - V_80 ;
strcpy ( V_159 -> V_161 , V_162 [ V_159 -> V_78 ] . V_163 ) ;
V_159 -> V_164 = V_162 [ V_159 -> V_78 ] . V_165 ;
return 0 ;
}
static int F_81 ( struct V_42 * V_42 , void * V_53 ,
struct V_145 * V_166 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
V_166 -> V_167 . V_168 . V_169 = V_10 -> V_90 ;
V_166 -> V_167 . V_168 . V_170 = V_10 -> V_91 ;
V_166 -> V_167 . V_168 . V_164 = V_10 -> V_136 . V_165 ;
V_166 -> V_167 . V_168 . V_171 =
V_10 -> V_90 * V_10 -> V_136 . V_137 ;
V_166 -> V_167 . V_168 . V_172 = V_166 -> V_167 . V_168 . V_171 * V_10 -> V_91 ;
V_166 -> V_167 . V_168 . V_173 = V_174 ;
V_166 -> V_167 . V_168 . V_133 = V_134 ;
return 0 ;
}
static int F_82 ( struct V_42 * V_42 , void * V_53 ,
struct V_145 * V_166 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_175 ;
for ( V_175 = 0 ; V_175 < V_160 ; V_175 ++ ) {
if ( V_166 -> V_167 . V_168 . V_164 ==
V_162 [ V_175 ] . V_165 ) {
V_10 -> V_136 = V_162 [ V_175 ] ;
break;
}
}
if ( V_175 == V_160 )
return - V_80 ;
F_64 ( V_166 -> V_167 . V_168 . V_169 , V_176 , V_177 ) ;
F_64 ( V_166 -> V_167 . V_168 . V_170 , V_178 , V_179 ) ;
V_166 -> V_167 . V_168 . V_171 = V_166 -> V_167 . V_168 . V_169 *
V_10 -> V_136 . V_137 ;
V_166 -> V_167 . V_168 . V_172 = V_166 -> V_167 . V_168 . V_171 * V_166 -> V_167 . V_168 . V_170 ;
V_166 -> V_167 . V_168 . V_173 = V_174 ;
V_166 -> V_167 . V_168 . V_133 = V_134 ;
return 0 ;
}
static int F_83 ( struct V_42 * V_42 , void * V_53 ,
struct V_145 * V_166 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_110 ;
V_110 = F_82 ( V_42 , V_53 , V_166 ) ;
if ( V_110 )
return V_110 ;
if ( V_10 -> V_25 == V_26 ) {
V_110 = F_65 ( V_10 ) ;
if ( V_110 )
return V_110 ;
}
F_40 ( V_10 ) ;
F_33 ( V_10 ) ;
V_10 -> V_115 = NULL ;
F_56 ( V_10 , V_166 -> V_167 . V_168 . V_169 , V_166 -> V_167 . V_168 . V_170 ) ;
return 0 ;
}
static T_1 F_84 ( struct V_42 * V_42 , char T_3 * V_8 ,
T_4 V_111 , T_5 * V_180 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_181 = V_42 -> V_182 & V_183 ;
unsigned long V_140 ;
int V_110 , V_155 ;
struct V_118 * V_119 ;
F_22 ( V_44 , L_19 , V_41 ,
( unsigned long ) V_111 , V_181 ) ;
if ( ! F_85 ( V_10 ) || ( V_8 == NULL ) )
return - V_184 ;
if ( ! V_10 -> V_120 ) {
F_40 ( V_10 ) ;
F_33 ( V_10 ) ;
F_66 ( V_10 , V_112 ) ;
}
if ( V_10 -> V_25 != V_26 ) {
V_10 -> V_25 = V_26 ;
F_7 ( V_10 , V_93 , V_156 , 1 ) ;
}
for ( V_155 = 0 ; V_155 < V_10 -> V_120 ; V_155 ++ ) {
V_119 = & V_10 -> V_119 [ V_155 ] ;
if ( V_119 -> V_123 == V_128 ) {
V_119 -> V_123 = V_124 ;
V_119 -> V_142 = V_143 ;
V_119 -> V_144 = 0 ;
V_119 -> V_145 = V_10 -> V_136 ;
F_70 ( & V_10 -> V_146 , V_140 ) ;
F_71 ( & V_119 -> V_119 , & V_10 -> V_147 ) ;
F_72 ( & V_10 -> V_146 ,
V_140 ) ;
}
}
if ( F_74 ( & ( V_10 -> V_149 ) ) ) {
if ( V_181 )
return - V_141 ;
V_110 = F_75
( V_10 -> V_151 ,
! F_74 ( & ( V_10 -> V_149 ) ) ) ;
if ( V_110 )
return V_110 ;
}
F_70 ( & V_10 -> V_146 , V_140 ) ;
V_119 = F_76 ( V_10 -> V_149 . V_152 ,
struct V_118 , V_119 ) ;
F_77 ( V_10 -> V_149 . V_152 ) ;
F_72 ( & V_10 -> V_146 , V_140 ) ;
if ( V_119 -> V_123 == V_185 ) {
V_119 -> V_186 = 0 ;
return 0 ;
}
F_22 ( V_44 , L_20 ,
V_41 ,
V_119 -> V_78 , V_119 -> V_186 , V_119 -> V_144 ) ;
if ( ( V_111 + V_119 -> V_186 ) > ( unsigned long ) V_119 -> V_144 )
V_111 = V_119 -> V_144 - V_119 -> V_186 ;
if ( F_86 ( V_8 , V_119 -> V_187 + V_119 -> V_186 , V_111 ) )
return - V_184 ;
V_119 -> V_186 += V_111 ;
F_22 ( V_44 , L_21 ,
V_41 ,
( unsigned long ) V_111 , V_119 -> V_186 ) ;
#if 1
V_119 -> V_186 = 0 ;
V_119 -> V_123 = V_128 ;
#else
if ( V_119 -> V_186 >= V_119 -> V_144 ) {
V_119 -> V_186 = 0 ;
V_119 -> V_123 = V_128 ;
}
#endif
return V_111 ;
}
static T_1 F_87 ( struct V_42 * V_42 , char T_3 * V_8 ,
T_4 V_111 , T_5 * V_180 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_30 ;
if ( F_23 ( & V_10 -> V_45 ) )
return - V_46 ;
V_30 = F_84 ( V_42 , V_8 , V_111 , V_180 ) ;
F_34 ( & V_10 -> V_45 ) ;
return V_30 ;
}
static int F_88 ( struct V_42 * V_42 , struct V_188 * V_189 )
{
unsigned long V_57 = V_189 -> V_190 - V_189 -> V_191 ,
V_192 = V_189 -> V_191 ;
void * V_193 ;
T_6 V_155 ;
struct V_1 * V_10 = F_21 ( V_42 ) ;
F_22 ( V_194 , L_22 ) ;
if ( ! F_85 ( V_10 ) )
return - V_184 ;
if ( ! ( V_189 -> V_195 & V_196 ) ||
V_57 != F_68 ( V_10 -> V_132 ) ) {
return - V_80 ;
}
for ( V_155 = 0 ; V_155 < V_10 -> V_120 ; V_155 ++ ) {
if ( ( ( F_68 ( V_10 -> V_132 ) * V_155 ) >> V_197 ) ==
V_189 -> V_198 )
break;
}
if ( V_155 == V_10 -> V_120 ) {
F_22 ( V_194 ,
L_23 ) ;
return - V_80 ;
}
V_189 -> V_195 |= V_199 | V_200 | V_201 ;
V_193 = V_10 -> V_119 [ V_155 ] . V_187 ;
while ( V_57 > 0 ) {
if ( F_89 ( V_189 , V_192 , F_90 ( V_193 ) ) ) {
F_22 ( V_194 , L_24 ) ;
return - V_141 ;
}
V_192 += V_202 ;
V_193 += V_202 ;
V_57 -= V_202 ;
}
return 0 ;
}
static int F_91 ( struct V_42 * V_42 , struct V_188 * V_189 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_30 ;
if ( F_23 ( & V_10 -> V_45 ) )
return - V_46 ;
V_30 = F_88 ( V_42 , V_189 ) ;
F_34 ( & V_10 -> V_45 ) ;
return V_30 ;
}
static int F_92 ( struct V_42 * V_42 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
int V_43 = 0 ;
F_22 ( V_44 , L_25 , V_41 ) ;
if ( F_23 ( & V_10 -> V_45 ) )
return - V_46 ;
V_43 = F_24 ( V_42 ) ;
if ( V_43 )
goto V_203;
if ( V_10 -> V_19 ) {
F_17 ( & V_10 -> V_204 . V_31 ,
L_26 ,
V_41 ) ;
V_43 = - V_47 ;
} else {
V_43 = F_93 ( V_10 ) ;
if ( V_43 < 0 ) {
V_10 -> V_205 = V_43 ;
V_43 = - V_47 ;
goto V_203;
}
V_10 -> V_74 = 1 ;
F_7 ( V_10 , V_84 , V_206 ) ;
F_94 ( V_10 , V_207 ) ;
V_10 -> V_19 ++ ;
}
V_203:
F_34 ( & V_10 -> V_45 ) ;
return V_43 ;
}
static int F_95 ( struct V_42 * V_42 )
{
struct V_1 * V_10 = F_21 ( V_42 ) ;
F_22 ( V_44 , L_27 ) ;
F_36 ( & V_10 -> V_45 ) ;
V_10 -> V_208 = 0 ;
F_96 ( V_10 -> V_31 , V_10 -> V_209 ,
V_10 -> V_208 ) ;
F_37 ( V_10 ) ;
V_10 -> V_74 = 0 ;
V_10 -> V_19 -- ;
F_34 ( & V_10 -> V_45 ) ;
if ( V_10 -> V_51 ) {
F_41 ( V_52 L_7 , V_41 ) ;
F_43 ( V_42 ) ;
F_42 ( V_10 ) ;
return 0 ;
}
F_22 ( V_44 , L_5 ) ;
return F_43 ( V_42 ) ;
}
static void F_97 ( struct V_1 * V_10 ,
struct V_4 * V_5 ,
const struct V_4 * V_210 ,
const char * V_82 )
{
struct V_211 * V_212 = V_10 -> V_31 ;
if ( V_212 == NULL ) {
F_17 ( & V_10 -> V_31 -> V_31 ,
L_28 , V_41 ) ;
return;
}
* V_5 = * V_210 ;
V_5 -> V_213 = & V_10 -> V_45 ;
V_5 -> V_214 = & V_10 -> V_214 ;
snprintf ( V_5 -> V_82 , sizeof( V_5 -> V_82 ) , L_29 , V_82 ) ;
F_98 ( V_5 , V_10 ) ;
}
static void F_99 ( struct V_1 * V_10 )
{
if ( F_100 ( & V_10 -> V_204 ) ) {
F_22 ( V_215 , L_30 ,
F_101 ( & V_10 -> V_204 ) ) ;
F_102 ( & V_10 -> V_204 ) ;
}
if ( F_100 ( & V_10 -> V_5 ) ) {
F_22 ( V_215 , L_30 ,
F_101 ( & V_10 -> V_5 ) ) ;
F_102 ( & V_10 -> V_5 ) ;
}
}
static int F_103 ( struct V_1 * V_10 )
{
int V_30 = - V_216 ;
F_97 ( V_10 , & V_10 -> V_5 ,
& V_217 , L_31 ) ;
if ( ! V_10 -> V_64 ) {
F_104 ( & V_10 -> V_5 , V_218 ) ;
F_104 ( & V_10 -> V_5 , V_219 ) ;
F_104 ( & V_10 -> V_5 , V_218 ) ;
F_104 ( & V_10 -> V_5 , V_219 ) ;
}
if ( F_105 ( & V_10 -> V_5 , V_67 , V_220 ) < 0 )
goto V_221;
F_41 ( V_52 L_32 ,
V_10 -> V_222 , F_101 ( & V_10 -> V_5 ) ) ;
if ( V_11 [ V_10 -> V_12 ] . V_74 ) {
F_97 ( V_10 , & V_10 -> V_204 ,
& V_223 , L_33 ) ;
if ( F_105 ( & V_10 -> V_204 , V_224 , V_225 ) < 0 )
goto V_221;
F_41 ( V_52 L_34 ,
V_10 -> V_222 , F_101 ( & V_10 -> V_204 ) ) ;
}
return 0 ;
V_221:
F_17 ( & V_10 -> V_31 -> V_31 ,
L_35 ,
V_10 -> V_222 ) ;
F_99 ( V_10 ) ;
return V_30 ;
}
static struct V_1 * F_106 ( struct V_211 * V_31 ,
struct V_226 * V_227 )
{
struct V_1 * V_10 ;
V_10 = F_107 ( sizeof( struct V_1 ) , V_228 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_31 = V_31 ;
if ( F_108 ( & V_227 -> V_31 , & V_10 -> V_214 ) )
goto V_229;
if ( F_109 ( & V_10 -> V_230 , 4 ) )
goto V_231;
V_10 -> V_214 . V_232 = & V_10 -> V_230 ;
F_110 ( & V_10 -> V_45 ) ;
V_10 -> V_233 = F_111 ( V_234 , V_228 ) ;
if ( V_10 -> V_233 == NULL )
goto V_231;
F_112 ( & V_10 -> V_235 ) ;
return V_10 ;
V_231:
F_113 ( & V_10 -> V_230 ) ;
F_114 ( & V_10 -> V_214 ) ;
V_229:
F_115 ( V_10 ) ;
return NULL ;
}
static void F_42 ( struct V_1 * V_10 )
{
F_22 ( V_215 , L_27 ) ;
V_10 -> V_49 = 0 ;
F_18 ( & V_10 -> V_5 ) ;
F_99 ( V_10 ) ;
F_115 ( V_10 -> V_236 ) ;
F_116 ( V_10 -> V_233 ) ;
F_113 ( & V_10 -> V_230 ) ;
F_114 ( & V_10 -> V_214 ) ;
F_115 ( V_10 ) ;
F_22 ( V_215 , L_5 ) ;
}
static void F_117 ( struct V_1 * V_10 )
{
int V_237 ;
if ( V_10 == NULL )
return;
V_237 = V_10 -> V_12 ;
V_10 -> V_136 = V_162 [ 2 ] ;
if ( V_11 [ V_10 -> V_12 ] . V_238 ) {
V_10 -> V_239 =
V_11 [ V_10 -> V_12 ] . V_240 ;
} else {
V_10 -> V_239 = 0 ;
}
V_10 -> V_92 = V_11 [ V_237 ] . V_241 ;
V_10 -> V_79 = V_11 [ V_237 ] . V_81 ;
V_10 -> V_89 = 0 ;
V_10 -> V_103 = 87.5 * 16000 ;
V_10 -> V_104 = 400 * 16 ;
if ( V_11 [ V_237 ] . V_242 > 0 )
F_37 ( V_10 ) ;
F_118 ( V_10 ) ;
F_119 ( V_10 ) ;
}
static int F_120 ( struct V_226 * V_227 ,
const struct V_243 * V_244 )
{
struct V_211 * V_31 = F_121 ( F_122 ( V_227 ) ) ;
struct V_226 * V_245 ;
T_7 V_246 = V_227 -> V_247 -> V_163 . V_248 ;
const struct V_249 * V_250 ;
struct V_1 * V_10 = NULL ;
const struct V_251 * V_252 ;
int V_237 , V_155 , V_110 ;
F_22 ( V_215 , L_36 ,
V_31 -> V_253 . V_254 ,
V_31 -> V_253 . V_255 , V_246 ) ;
V_237 = V_244 -> V_256 ;
if ( V_237 < 0 || V_237 >= V_257 ) {
F_22 ( V_215 , L_37 , V_237 ) ;
V_110 = - V_258 ;
goto V_259;
}
F_41 ( V_52 L_38 , V_41 ,
V_11 [ V_237 ] . V_13 ) ;
if ( V_11 [ V_237 ] . V_250 >= 0 )
V_250 = & V_31 -> V_260 -> V_250 [ V_11 [ V_237 ] . V_250 ] -> V_247 [ 0 ] ;
else if ( V_246 < V_31 -> V_260 -> V_163 . V_261 )
V_250 = & V_31 -> V_260 -> V_250 [ V_246 ] -> V_247 [ 0 ] ;
else {
F_17 ( & V_227 -> V_31 , L_39 ,
V_246 , V_31 -> V_260 -> V_163 . V_261 - 1 ) ;
V_110 = - V_258 ;
goto V_259;
}
if ( V_250 -> V_163 . V_262 < 2 ) {
F_17 ( & V_227 -> V_31 , L_40
L_41 , V_246 , V_250 -> V_163 . V_262 ) ;
V_110 = - V_258 ;
goto V_259;
}
V_252 = & V_250 -> V_252 [ 1 ] . V_163 ;
if ( ! F_123 ( V_252 ) ) {
F_17 ( & V_227 -> V_31 , L_42 ,
V_41 , V_246 ) ;
F_17 ( & V_227 -> V_31 , L_43 ,
V_41 , V_252 -> V_263 ) ;
V_110 = - V_258 ;
goto V_259;
}
if ( F_124 ( V_252 ) ) {
F_17 ( & V_227 -> V_31 , L_44 ,
V_41 , V_246 ) ;
V_110 = - V_258 ;
goto V_259;
}
V_10 = F_106 ( V_31 , V_227 ) ;
if ( V_10 == NULL ) {
F_17 ( & V_227 -> V_31 , L_45 , V_41 ) ;
V_110 = - V_216 ;
goto V_259;
}
if ( V_31 -> V_253 . V_264 > 1 )
V_10 -> V_29 = V_265 ;
else if ( V_237 == V_266 )
V_10 -> V_29 = V_267 ;
else
V_10 -> V_29 = V_268 ;
F_22 ( V_215 , L_46 , V_10 -> V_29 ) ;
V_245 = V_31 -> V_260 -> V_250 [ 0 ] ;
V_10 -> V_269 = V_245 -> V_270 ;
F_22 ( V_215 , L_47 , V_10 -> V_269 ) ;
V_10 -> V_236 = F_125 ( 32 * V_10 -> V_269 , V_228 ) ;
if ( V_10 -> V_236 == NULL ) {
F_17 ( & V_227 -> V_31 , L_48 ) ;
V_110 = - V_216 ;
goto V_271;
}
for ( V_155 = 0 ; V_155 < V_10 -> V_269 ; V_155 ++ ) {
T_8 V_272 = F_126 ( V_245 -> V_247 [ V_155 ] . V_252 [ 1 ] . V_163 .
V_273 ) ;
V_10 -> V_236 [ V_155 ] =
( V_272 & 0x07ff ) * ( ( ( V_272 & 0x1800 ) >> 11 ) + 1 ) ;
F_22 ( V_215 , L_49 , V_155 ,
V_10 -> V_236 [ V_155 ] ) ;
}
V_10 -> V_222 = V_274 ++ ;
F_127 ( & V_10 -> V_146 ) ;
F_112 ( & V_10 -> V_151 ) ;
F_112 ( & V_10 -> V_275 ) ;
V_10 -> V_64 = V_11 [ V_237 ] . V_84 ;
if ( V_10 -> V_64 )
V_10 -> V_276 = V_11 [ V_237 ] . V_276 ;
V_10 -> V_12 = V_237 ;
V_10 -> V_51 = 0 ;
V_10 -> V_209 = V_246 ;
V_10 -> V_208 = 0 ;
V_10 -> V_277 = V_252 -> V_278 ;
V_10 -> V_279 = 0 ;
V_10 -> V_280 = 0 ;
V_10 -> V_19 = 0 ;
V_10 -> V_25 = V_281 ;
F_117 ( V_10 ) ;
F_103 ( V_10 ) ;
F_15 ( & V_10 -> V_5 ) ;
F_22 ( V_215 , L_5 ) ;
return 0 ;
V_271:
F_42 ( V_10 ) ;
V_259:
F_128 ( V_31 ) ;
return V_110 ;
}
static void F_129 ( struct V_226 * V_227 )
{
struct V_1 * V_10 = F_130 ( F_131 ( V_227 ) ) ;
F_22 ( V_215 , L_27 ) ;
if ( V_10 == NULL ) {
F_132 ( L_50 , V_41 ) ;
return;
}
F_36 ( & V_10 -> V_45 ) ;
F_39 ( V_10 ) ;
F_133 ( & V_10 -> V_214 ) ;
F_134 ( V_10 ) ;
V_10 -> V_51 = 1 ;
F_128 ( V_10 -> V_31 ) ;
V_10 -> V_31 = NULL ;
F_34 ( & V_10 -> V_45 ) ;
if ( V_10 -> V_19 ) {
F_41 ( V_52 L_51 ,
V_41 ) ;
F_135 ( & V_10 -> V_151 ) ;
F_135 ( & V_10 -> V_275 ) ;
} else {
F_42 ( V_10 ) ;
}
F_22 ( V_215 , L_5 ) ;
}
static int T_9 F_136 ( void )
{
int V_43 ;
F_22 ( V_215 , L_27 ) ;
F_22 ( V_44 , L_52 ) ;
F_22 ( V_215 , L_53 ) ;
F_22 ( V_194 , L_54 ) ;
if ( V_27 != V_28 ) {
V_162 [ 6 ] . V_282 = 0 ;
V_162 [ 7 ] . V_282 = 0 ;
}
V_43 = F_137 ( & V_283 ) ;
if ( V_43 == 0 ) {
F_41 (KERN_INFO DRIVER_DESC L_55 USBVISION_VERSION_STRING L_56 ) ;
F_22 ( V_215 , L_5 ) ;
}
return V_43 ;
}
static void T_10 F_138 ( void )
{
F_22 ( V_215 , L_27 ) ;
F_139 ( & V_283 ) ;
F_22 ( V_215 , L_5 ) ;
}
