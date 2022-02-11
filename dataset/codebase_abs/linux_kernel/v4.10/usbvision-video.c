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
T_2 V_14 = F_7 ( F_8 ( & V_10 -> V_15 ,
V_16 ) ) ;
return sprintf ( V_8 , L_2 , V_14 ) ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
T_2 V_14 = F_7 ( F_8 ( & V_10 -> V_15 ,
V_17 ) ) ;
return sprintf ( V_8 , L_2 , V_14 ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
T_2 V_14 = F_7 ( F_8 ( & V_10 -> V_15 ,
V_18 ) ) ;
return sprintf ( V_8 , L_2 , V_14 ) ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
T_2 V_14 = F_7 ( F_8 ( & V_10 -> V_15 ,
V_19 ) ) ;
return sprintf ( V_8 , L_2 , V_14 ) ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_1 ,
F_13 ( V_10 -> V_20 == V_21 ? 1 : 0 ) ) ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_1 ,
F_13 ( V_10 -> V_22 == V_23 ) ) ;
}
static T_1 F_15 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_10 = F_3 ( V_5 ) ;
return sprintf ( V_8 , L_2 , V_10 -> V_24 ) ;
}
static void F_16 ( struct V_4 * V_5 )
{
int V_25 ;
if ( ! V_5 )
return;
do {
V_25 = F_17 ( & V_5 -> V_26 , & V_27 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_28 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_29 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_30 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_31 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_32 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_33 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_34 ) ;
if ( V_25 < 0 )
break;
V_25 = F_17 ( & V_5 -> V_26 , & V_35 ) ;
if ( V_25 >= 0 )
return;
} while ( 0 );
F_18 ( & V_5 -> V_26 , L_3 , V_36 , V_25 ) ;
}
static void F_19 ( struct V_4 * V_5 )
{
if ( V_5 ) {
F_20 ( & V_5 -> V_26 , & V_27 ) ;
F_20 ( & V_5 -> V_26 , & V_28 ) ;
F_20 ( & V_5 -> V_26 , & V_29 ) ;
F_20 ( & V_5 -> V_26 , & V_30 ) ;
F_20 ( & V_5 -> V_26 , & V_31 ) ;
F_20 ( & V_5 -> V_26 , & V_32 ) ;
F_20 ( & V_5 -> V_26 , & V_33 ) ;
F_20 ( & V_5 -> V_26 , & V_34 ) ;
F_20 ( & V_5 -> V_26 , & V_35 ) ;
}
}
static int F_21 ( struct V_37 * V_37 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_38 = 0 ;
F_23 ( V_39 , L_4 ) ;
if ( F_24 ( & V_10 -> V_40 ) )
return - V_41 ;
if ( V_10 -> V_42 ) {
V_38 = - V_43 ;
} else {
V_38 = F_25 ( V_37 ) ;
if ( V_38 )
goto V_44;
V_38 = F_26 ( V_10 ) ;
if ( V_22 == V_23 ) {
V_38 = F_27 ( V_10 ) ;
}
if ( V_38 ) {
F_28 ( V_10 ) ;
F_29 ( V_10 ) ;
}
}
if ( ! V_38 ) {
if ( ! V_10 -> V_45 ) {
int V_46 = 0 ;
V_46 = F_30 ( V_10 , V_22 ) ;
if ( V_46 )
V_10 -> V_45 = 1 ;
else
V_38 = - V_43 ;
}
if ( ! V_38 ) {
F_31 ( V_10 ) ;
V_38 = F_32 ( V_10 ) ;
F_33 ( V_10 , 0 ) ;
F_34 ( V_10 ) ;
V_10 -> V_42 ++ ;
}
}
V_44:
F_35 ( & V_10 -> V_40 ) ;
F_23 ( V_39 , L_5 ) ;
return V_38 ;
}
static int F_36 ( struct V_37 * V_37 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
F_23 ( V_39 , L_6 ) ;
F_37 ( & V_10 -> V_40 ) ;
F_38 ( V_10 ) ;
F_39 ( V_10 ) ;
F_40 ( V_10 ) ;
F_29 ( V_10 ) ;
F_41 ( V_10 ) ;
F_34 ( V_10 ) ;
F_28 ( V_10 ) ;
V_10 -> V_42 -- ;
F_35 ( & V_10 -> V_40 ) ;
if ( V_10 -> V_47 ) {
F_42 ( V_48 L_7 , V_36 ) ;
F_43 ( V_10 ) ;
return 0 ;
}
F_23 ( V_39 , L_5 ) ;
return F_44 ( V_37 ) ;
}
static int F_45 ( struct V_37 * V_37 , void * V_49 ,
struct V_50 * V_51 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_38 ;
V_38 = F_46 ( V_10 , V_51 -> V_51 & 0xff ) ;
if ( V_38 < 0 ) {
F_18 ( & V_10 -> V_5 . V_26 ,
L_8 ,
V_36 , V_38 ) ;
return V_38 ;
}
V_51 -> V_14 = V_38 ;
V_51 -> V_52 = 1 ;
return 0 ;
}
static int F_47 ( struct V_37 * V_37 , void * V_49 ,
const struct V_50 * V_51 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_38 ;
V_38 = F_48 ( V_10 , V_51 -> V_51 & 0xff , V_51 -> V_14 ) ;
if ( V_38 < 0 ) {
F_18 ( & V_10 -> V_5 . V_26 ,
L_9 ,
V_36 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
static int F_49 ( struct V_37 * V_37 , void * V_49 ,
struct V_53 * V_54 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
struct V_4 * V_5 = F_50 ( V_37 ) ;
F_51 ( V_54 -> V_55 , L_10 , sizeof( V_54 -> V_55 ) ) ;
F_51 ( V_54 -> V_56 ,
V_11 [ V_10 -> V_12 ] . V_13 ,
sizeof( V_54 -> V_56 ) ) ;
F_52 ( V_10 -> V_26 , V_54 -> V_57 , sizeof( V_54 -> V_57 ) ) ;
V_54 -> V_58 = V_10 -> V_59 ? V_60 : 0 ;
if ( V_5 -> V_61 == V_62 )
V_54 -> V_58 |= V_63 |
V_64 | V_65 ;
else
V_54 -> V_58 |= V_66 ;
V_54 -> V_67 = V_54 -> V_58 | V_63 |
V_64 | V_65 | V_68 ;
if ( V_11 [ V_10 -> V_12 ] . V_69 )
V_54 -> V_67 |= V_66 ;
return 0 ;
}
static int F_53 ( struct V_37 * V_37 , void * V_49 ,
struct V_70 * V_71 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_72 ;
if ( V_71 -> V_73 >= V_10 -> V_74 )
return - V_75 ;
if ( V_10 -> V_59 )
V_72 = V_71 -> V_73 ;
else
V_72 = V_71 -> V_73 + 1 ;
switch ( V_72 ) {
case 0 :
if ( V_11 [ V_10 -> V_12 ] . V_76 == 4 ) {
strcpy ( V_71 -> V_77 , L_11 ) ;
} else {
strcpy ( V_71 -> V_77 , L_12 ) ;
V_71 -> type = V_78 ;
V_71 -> V_79 = V_72 ;
V_71 -> V_80 = V_81 ;
}
break;
case 1 :
V_71 -> type = V_82 ;
if ( V_11 [ V_10 -> V_12 ] . V_76 == 4 )
strcpy ( V_71 -> V_77 , L_13 ) ;
else
strcpy ( V_71 -> V_77 , L_14 ) ;
V_71 -> V_80 = V_81 ;
break;
case 2 :
V_71 -> type = V_82 ;
if ( V_11 [ V_10 -> V_12 ] . V_76 == 4 )
strcpy ( V_71 -> V_77 , L_15 ) ;
else
strcpy ( V_71 -> V_77 , L_16 ) ;
V_71 -> V_80 = V_81 ;
break;
case 3 :
V_71 -> type = V_82 ;
strcpy ( V_71 -> V_77 , L_17 ) ;
V_71 -> V_80 = V_81 ;
break;
}
return 0 ;
}
static int F_54 ( struct V_37 * V_37 , void * V_49 , unsigned int * V_83 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
* V_83 = V_10 -> V_84 ;
return 0 ;
}
static int F_55 ( struct V_37 * V_37 , void * V_49 , unsigned int V_83 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
if ( V_83 >= V_10 -> V_74 )
return - V_75 ;
F_33 ( V_10 , V_83 ) ;
F_56 ( V_10 ) ;
F_57 ( V_10 ,
V_10 -> V_85 ,
V_10 -> V_86 ) ;
return 0 ;
}
static int F_58 ( struct V_37 * V_37 , void * V_49 , T_3 V_87 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
V_10 -> V_88 = V_87 ;
F_59 ( V_10 , V_89 , V_90 , V_10 -> V_88 ) ;
F_33 ( V_10 , V_10 -> V_84 ) ;
return 0 ;
}
static int F_60 ( struct V_37 * V_37 , void * V_49 , T_3 * V_87 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
* V_87 = V_10 -> V_88 ;
return 0 ;
}
static int F_61 ( struct V_37 * V_37 , void * V_49 ,
struct V_91 * V_92 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
if ( V_92 -> V_73 )
return - V_75 ;
if ( V_92 -> type == V_93 )
strcpy ( V_92 -> V_77 , L_18 ) ;
else
strcpy ( V_92 -> V_77 , L_12 ) ;
F_59 ( V_10 , V_79 , V_94 , V_92 ) ;
return 0 ;
}
static int F_62 ( struct V_37 * V_37 , void * V_49 ,
const struct V_91 * V_92 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
if ( V_92 -> V_73 )
return - V_75 ;
F_59 ( V_10 , V_79 , V_95 , V_92 ) ;
return 0 ;
}
static int F_63 ( struct V_37 * V_37 , void * V_49 ,
struct V_96 * V_97 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
if ( V_97 -> V_79 )
return - V_75 ;
if ( V_97 -> type == V_93 )
V_97 -> V_98 = V_10 -> V_99 ;
else
V_97 -> V_98 = V_10 -> V_100 ;
return 0 ;
}
static int F_64 ( struct V_37 * V_37 , void * V_49 ,
const struct V_96 * V_97 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
struct V_96 V_101 = * V_97 ;
if ( V_97 -> V_79 )
return - V_75 ;
F_59 ( V_10 , V_79 , V_102 , V_97 ) ;
F_59 ( V_10 , V_79 , V_103 , & V_101 ) ;
if ( V_97 -> type == V_93 )
V_10 -> V_99 = V_101 . V_98 ;
else
V_10 -> V_100 = V_101 . V_98 ;
return 0 ;
}
static int F_65 ( struct V_37 * V_37 ,
void * V_49 , struct V_104 * V_105 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_106 ;
F_66 ( V_105 -> V_107 , 1 , V_108 ) ;
if ( V_105 -> V_109 != V_110 )
return - V_75 ;
if ( V_10 -> V_20 == V_21 ) {
V_106 = F_67 ( V_10 ) ;
if ( V_106 )
return V_106 ;
}
F_41 ( V_10 ) ;
F_34 ( V_10 ) ;
V_105 -> V_107 = F_68 ( V_10 , V_105 -> V_107 ) ;
V_10 -> V_111 = NULL ;
return 0 ;
}
static int F_69 ( struct V_37 * V_37 ,
void * V_49 , struct V_112 * V_113 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
struct V_114 * V_115 ;
if ( V_113 -> V_73 >= V_10 -> V_116 )
return - V_75 ;
V_113 -> V_117 = V_118 ;
V_115 = & V_10 -> V_115 [ V_113 -> V_73 ] ;
if ( V_115 -> V_119 >= V_120 )
V_113 -> V_117 |= V_121 ;
if ( V_115 -> V_119 >= V_122 )
V_113 -> V_117 |= V_123 ;
if ( V_115 -> V_119 == V_124 )
V_113 -> V_117 |= V_125 ;
V_113 -> V_109 = V_110 ;
V_113 -> V_126 . V_127 = V_113 -> V_73 * F_70 ( V_10 -> V_128 ) ;
V_113 -> V_109 = V_110 ;
V_113 -> V_129 = V_130 ;
V_113 -> V_131 = V_10 -> V_85 *
V_10 -> V_86 *
V_10 -> V_132 . V_133 ;
V_113 -> V_134 = V_10 -> V_115 [ V_113 -> V_73 ] . V_134 ;
V_113 -> V_135 = V_10 -> V_115 [ V_113 -> V_73 ] . V_135 ;
return 0 ;
}
static int F_71 ( struct V_37 * V_37 , void * V_49 , struct V_112 * V_113 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
struct V_114 * V_115 ;
unsigned long V_136 ;
if ( V_113 -> V_73 >= V_10 -> V_116 )
return - V_75 ;
V_115 = & V_10 -> V_115 [ V_113 -> V_73 ] ;
if ( V_115 -> V_119 != V_124 )
return - V_137 ;
V_115 -> V_119 = V_120 ;
V_115 -> V_138 = V_139 ;
V_115 -> V_140 = 0 ;
V_113 -> V_117 &= ~ V_123 ;
V_115 -> V_141 = V_10 -> V_132 ;
F_72 ( & V_10 -> V_142 , V_136 ) ;
F_73 ( & V_10 -> V_115 [ V_113 -> V_73 ] . V_115 , & V_10 -> V_143 ) ;
F_74 ( & V_10 -> V_142 , V_136 ) ;
return 0 ;
}
static int F_75 ( struct V_37 * V_37 , void * V_49 , struct V_112 * V_113 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_106 ;
struct V_114 * V_144 ;
unsigned long V_136 ;
if ( F_76 ( & ( V_10 -> V_145 ) ) ) {
if ( V_10 -> V_20 == V_146 )
return - V_75 ;
V_106 = F_77
( V_10 -> V_147 ,
! F_76 ( & ( V_10 -> V_145 ) ) ) ;
if ( V_106 )
return V_106 ;
}
F_72 ( & V_10 -> V_142 , V_136 ) ;
V_144 = F_78 ( V_10 -> V_145 . V_148 ,
struct V_114 , V_115 ) ;
F_79 ( V_10 -> V_145 . V_148 ) ;
F_74 ( & V_10 -> V_142 , V_136 ) ;
V_144 -> V_119 = V_124 ;
V_113 -> V_109 = V_110 ;
V_113 -> V_117 = V_125 |
V_121 |
V_123 |
V_118 ;
V_113 -> V_73 = V_144 -> V_73 ;
V_113 -> V_135 = V_144 -> V_135 ;
V_113 -> V_134 = V_144 -> V_134 ;
V_113 -> V_129 = V_130 ;
V_113 -> V_149 = V_144 -> V_140 ;
return 0 ;
}
static int F_80 ( struct V_37 * V_37 , void * V_49 , enum V_150 V_151 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
V_10 -> V_20 = V_21 ;
F_59 ( V_10 , V_89 , V_152 , 1 ) ;
return 0 ;
}
static int F_81 ( struct V_37 * V_37 ,
void * V_49 , enum V_150 type )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
if ( type != V_153 )
return - V_75 ;
if ( V_10 -> V_20 == V_21 ) {
F_67 ( V_10 ) ;
F_59 ( V_10 , V_89 , V_152 , 0 ) ;
}
F_34 ( V_10 ) ;
return 0 ;
}
static int F_82 ( struct V_37 * V_37 , void * V_49 ,
struct V_154 * V_155 )
{
if ( V_155 -> V_73 >= V_156 - 1 )
return - V_75 ;
strcpy ( V_155 -> V_157 , V_158 [ V_155 -> V_73 ] . V_159 ) ;
V_155 -> V_160 = V_158 [ V_155 -> V_73 ] . V_161 ;
return 0 ;
}
static int F_83 ( struct V_37 * V_37 , void * V_49 ,
struct V_141 * V_162 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
V_162 -> V_163 . V_164 . V_165 = V_10 -> V_85 ;
V_162 -> V_163 . V_164 . V_166 = V_10 -> V_86 ;
V_162 -> V_163 . V_164 . V_160 = V_10 -> V_132 . V_161 ;
V_162 -> V_163 . V_164 . V_167 =
V_10 -> V_85 * V_10 -> V_132 . V_133 ;
V_162 -> V_163 . V_164 . V_168 = V_162 -> V_163 . V_164 . V_167 * V_10 -> V_86 ;
V_162 -> V_163 . V_164 . V_169 = V_170 ;
V_162 -> V_163 . V_164 . V_129 = V_130 ;
return 0 ;
}
static int F_84 ( struct V_37 * V_37 , void * V_49 ,
struct V_141 * V_162 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_171 ;
for ( V_171 = 0 ; V_171 < V_156 ; V_171 ++ ) {
if ( V_162 -> V_163 . V_164 . V_160 ==
V_158 [ V_171 ] . V_161 ) {
V_10 -> V_132 = V_158 [ V_171 ] ;
break;
}
}
if ( V_171 == V_156 )
return - V_75 ;
F_66 ( V_162 -> V_163 . V_164 . V_165 , V_172 , V_173 ) ;
F_66 ( V_162 -> V_163 . V_164 . V_166 , V_174 , V_175 ) ;
V_162 -> V_163 . V_164 . V_167 = V_162 -> V_163 . V_164 . V_165 *
V_10 -> V_132 . V_133 ;
V_162 -> V_163 . V_164 . V_168 = V_162 -> V_163 . V_164 . V_167 * V_162 -> V_163 . V_164 . V_166 ;
V_162 -> V_163 . V_164 . V_169 = V_170 ;
V_162 -> V_163 . V_164 . V_129 = V_130 ;
return 0 ;
}
static int F_85 ( struct V_37 * V_37 , void * V_49 ,
struct V_141 * V_162 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_106 ;
V_106 = F_84 ( V_37 , V_49 , V_162 ) ;
if ( V_106 )
return V_106 ;
if ( V_10 -> V_20 == V_21 ) {
V_106 = F_67 ( V_10 ) ;
if ( V_106 )
return V_106 ;
}
F_41 ( V_10 ) ;
F_34 ( V_10 ) ;
V_10 -> V_111 = NULL ;
F_57 ( V_10 , V_162 -> V_163 . V_164 . V_165 , V_162 -> V_163 . V_164 . V_166 ) ;
return 0 ;
}
static T_1 F_86 ( struct V_37 * V_37 , char T_4 * V_8 ,
T_5 V_107 , T_6 * V_176 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_177 = V_37 -> V_178 & V_179 ;
unsigned long V_136 ;
int V_106 , V_151 ;
struct V_114 * V_115 ;
F_23 ( V_39 , L_19 , V_36 ,
( unsigned long ) V_107 , V_177 ) ;
if ( ! F_87 ( V_10 ) || ( V_8 == NULL ) )
return - V_180 ;
if ( ! V_10 -> V_116 ) {
F_41 ( V_10 ) ;
F_34 ( V_10 ) ;
F_68 ( V_10 , V_108 ) ;
}
if ( V_10 -> V_20 != V_21 ) {
V_10 -> V_20 = V_21 ;
F_59 ( V_10 , V_89 , V_152 , 1 ) ;
}
for ( V_151 = 0 ; V_151 < V_10 -> V_116 ; V_151 ++ ) {
V_115 = & V_10 -> V_115 [ V_151 ] ;
if ( V_115 -> V_119 == V_124 ) {
V_115 -> V_119 = V_120 ;
V_115 -> V_138 = V_139 ;
V_115 -> V_140 = 0 ;
V_115 -> V_141 = V_10 -> V_132 ;
F_72 ( & V_10 -> V_142 , V_136 ) ;
F_73 ( & V_115 -> V_115 , & V_10 -> V_143 ) ;
F_74 ( & V_10 -> V_142 ,
V_136 ) ;
}
}
if ( F_76 ( & ( V_10 -> V_145 ) ) ) {
if ( V_177 )
return - V_137 ;
V_106 = F_77
( V_10 -> V_147 ,
! F_76 ( & ( V_10 -> V_145 ) ) ) ;
if ( V_106 )
return V_106 ;
}
F_72 ( & V_10 -> V_142 , V_136 ) ;
V_115 = F_78 ( V_10 -> V_145 . V_148 ,
struct V_114 , V_115 ) ;
F_79 ( V_10 -> V_145 . V_148 ) ;
F_74 ( & V_10 -> V_142 , V_136 ) ;
if ( V_115 -> V_119 == V_181 ) {
V_115 -> V_182 = 0 ;
return 0 ;
}
F_23 ( V_39 , L_20 ,
V_36 ,
V_115 -> V_73 , V_115 -> V_182 , V_115 -> V_140 ) ;
if ( ( V_107 + V_115 -> V_182 ) > ( unsigned long ) V_115 -> V_140 )
V_107 = V_115 -> V_140 - V_115 -> V_182 ;
if ( F_88 ( V_8 , V_115 -> V_183 + V_115 -> V_182 , V_107 ) )
return - V_180 ;
V_115 -> V_182 += V_107 ;
F_23 ( V_39 , L_21 ,
V_36 ,
( unsigned long ) V_107 , V_115 -> V_182 ) ;
#if 1
V_115 -> V_182 = 0 ;
V_115 -> V_119 = V_124 ;
#else
if ( V_115 -> V_182 >= V_115 -> V_140 ) {
V_115 -> V_182 = 0 ;
V_115 -> V_119 = V_124 ;
}
#endif
return V_107 ;
}
static T_1 F_89 ( struct V_37 * V_37 , char T_4 * V_8 ,
T_5 V_107 , T_6 * V_176 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_25 ;
if ( F_24 ( & V_10 -> V_40 ) )
return - V_41 ;
V_25 = F_86 ( V_37 , V_8 , V_107 , V_176 ) ;
F_35 ( & V_10 -> V_40 ) ;
return V_25 ;
}
static int F_90 ( struct V_37 * V_37 , struct V_184 * V_185 )
{
unsigned long V_52 = V_185 -> V_186 - V_185 -> V_187 ,
V_188 = V_185 -> V_187 ;
void * V_189 ;
T_7 V_151 ;
struct V_1 * V_10 = F_22 ( V_37 ) ;
F_23 ( V_190 , L_22 ) ;
if ( ! F_87 ( V_10 ) )
return - V_180 ;
if ( ! ( V_185 -> V_191 & V_192 ) ||
V_52 != F_70 ( V_10 -> V_128 ) ) {
return - V_75 ;
}
for ( V_151 = 0 ; V_151 < V_10 -> V_116 ; V_151 ++ ) {
if ( ( ( F_70 ( V_10 -> V_128 ) * V_151 ) >> V_193 ) ==
V_185 -> V_194 )
break;
}
if ( V_151 == V_10 -> V_116 ) {
F_23 ( V_190 ,
L_23 ) ;
return - V_75 ;
}
V_185 -> V_191 |= V_195 | V_196 | V_197 ;
V_189 = V_10 -> V_115 [ V_151 ] . V_183 ;
while ( V_52 > 0 ) {
if ( F_91 ( V_185 , V_188 , F_92 ( V_189 ) ) ) {
F_23 ( V_190 , L_24 ) ;
return - V_137 ;
}
V_188 += V_198 ;
V_189 += V_198 ;
V_52 -= V_198 ;
}
return 0 ;
}
static int F_93 ( struct V_37 * V_37 , struct V_184 * V_185 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_25 ;
if ( F_24 ( & V_10 -> V_40 ) )
return - V_41 ;
V_25 = F_90 ( V_37 , V_185 ) ;
F_35 ( & V_10 -> V_40 ) ;
return V_25 ;
}
static int F_94 ( struct V_37 * V_37 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
int V_38 = 0 ;
F_23 ( V_39 , L_25 , V_36 ) ;
if ( F_24 ( & V_10 -> V_40 ) )
return - V_41 ;
V_38 = F_25 ( V_37 ) ;
if ( V_38 )
goto V_199;
if ( V_10 -> V_42 ) {
F_18 ( & V_10 -> V_200 . V_26 ,
L_26 ,
V_36 ) ;
V_38 = - V_43 ;
} else {
V_38 = F_95 ( V_10 ) ;
if ( V_38 < 0 ) {
V_10 -> V_201 = V_38 ;
V_38 = - V_43 ;
goto V_199;
}
V_10 -> V_69 = 1 ;
F_59 ( V_10 , V_79 , V_202 ) ;
F_96 ( V_10 , V_203 ) ;
V_10 -> V_42 ++ ;
}
V_199:
F_35 ( & V_10 -> V_40 ) ;
return V_38 ;
}
static int F_97 ( struct V_37 * V_37 )
{
struct V_1 * V_10 = F_22 ( V_37 ) ;
F_23 ( V_39 , L_27 ) ;
F_37 ( & V_10 -> V_40 ) ;
V_10 -> V_204 = 0 ;
F_98 ( V_10 -> V_26 , V_10 -> V_205 ,
V_10 -> V_204 ) ;
F_38 ( V_10 ) ;
V_10 -> V_69 = 0 ;
V_10 -> V_42 -- ;
F_35 ( & V_10 -> V_40 ) ;
if ( V_10 -> V_47 ) {
F_42 ( V_48 L_7 , V_36 ) ;
F_44 ( V_37 ) ;
F_43 ( V_10 ) ;
return 0 ;
}
F_23 ( V_39 , L_5 ) ;
return F_44 ( V_37 ) ;
}
static void F_99 ( struct V_1 * V_10 ,
struct V_4 * V_5 ,
const struct V_4 * V_206 ,
const char * V_77 )
{
struct V_207 * V_208 = V_10 -> V_26 ;
if ( V_208 == NULL ) {
F_18 ( & V_10 -> V_26 -> V_26 ,
L_28 , V_36 ) ;
return;
}
* V_5 = * V_206 ;
V_5 -> V_209 = & V_10 -> V_40 ;
V_5 -> V_210 = & V_10 -> V_210 ;
snprintf ( V_5 -> V_77 , sizeof( V_5 -> V_77 ) , L_29 , V_77 ) ;
F_100 ( V_5 , V_10 ) ;
}
static void F_101 ( struct V_1 * V_10 )
{
if ( F_102 ( & V_10 -> V_200 ) ) {
F_23 ( V_211 , L_30 ,
F_103 ( & V_10 -> V_200 ) ) ;
F_104 ( & V_10 -> V_200 ) ;
}
if ( F_102 ( & V_10 -> V_5 ) ) {
F_23 ( V_211 , L_30 ,
F_103 ( & V_10 -> V_5 ) ) ;
F_104 ( & V_10 -> V_5 ) ;
}
}
static int F_105 ( struct V_1 * V_10 )
{
int V_25 = - V_212 ;
F_99 ( V_10 , & V_10 -> V_5 ,
& V_213 , L_31 ) ;
if ( ! V_10 -> V_59 ) {
F_106 ( & V_10 -> V_5 , V_214 ) ;
F_106 ( & V_10 -> V_5 , V_215 ) ;
F_106 ( & V_10 -> V_5 , V_214 ) ;
F_106 ( & V_10 -> V_5 , V_215 ) ;
}
if ( F_107 ( & V_10 -> V_5 , V_62 , V_216 ) < 0 )
goto V_217;
F_42 ( V_48 L_32 ,
V_10 -> V_218 , F_103 ( & V_10 -> V_5 ) ) ;
if ( V_11 [ V_10 -> V_12 ] . V_69 ) {
F_99 ( V_10 , & V_10 -> V_200 ,
& V_219 , L_33 ) ;
if ( F_107 ( & V_10 -> V_200 , V_220 , V_221 ) < 0 )
goto V_217;
F_42 ( V_48 L_34 ,
V_10 -> V_218 , F_103 ( & V_10 -> V_200 ) ) ;
}
return 0 ;
V_217:
F_18 ( & V_10 -> V_26 -> V_26 ,
L_35 ,
V_10 -> V_218 ) ;
F_101 ( V_10 ) ;
return V_25 ;
}
static struct V_1 * F_108 ( struct V_207 * V_26 ,
struct V_222 * V_223 )
{
struct V_1 * V_10 ;
V_10 = F_109 ( sizeof( struct V_1 ) , V_224 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_26 = V_26 ;
if ( F_110 ( & V_223 -> V_26 , & V_10 -> V_210 ) )
goto V_225;
if ( F_111 ( & V_10 -> V_15 , 4 ) )
goto V_226;
V_10 -> V_210 . V_227 = & V_10 -> V_15 ;
F_112 ( & V_10 -> V_40 ) ;
V_10 -> V_228 = F_113 ( V_229 , V_224 ) ;
if ( V_10 -> V_228 == NULL )
goto V_226;
F_114 ( & V_10 -> V_230 ) ;
return V_10 ;
V_226:
F_115 ( & V_10 -> V_15 ) ;
F_116 ( & V_10 -> V_210 ) ;
V_225:
F_117 ( V_10 ) ;
return NULL ;
}
static void F_43 ( struct V_1 * V_10 )
{
F_23 ( V_211 , L_27 ) ;
V_10 -> V_45 = 0 ;
F_19 ( & V_10 -> V_5 ) ;
F_101 ( V_10 ) ;
F_117 ( V_10 -> V_231 ) ;
F_118 ( V_10 -> V_228 ) ;
F_115 ( & V_10 -> V_15 ) ;
F_116 ( & V_10 -> V_210 ) ;
F_117 ( V_10 ) ;
F_23 ( V_211 , L_5 ) ;
}
static void F_119 ( struct V_1 * V_10 )
{
int V_232 ;
if ( V_10 == NULL )
return;
V_232 = V_10 -> V_12 ;
V_10 -> V_132 = V_158 [ 2 ] ;
if ( V_11 [ V_10 -> V_12 ] . V_233 ) {
V_10 -> V_234 =
V_11 [ V_10 -> V_12 ] . V_235 ;
} else {
V_10 -> V_234 = 0 ;
}
V_10 -> V_88 = V_11 [ V_232 ] . V_236 ;
V_10 -> V_74 = V_11 [ V_232 ] . V_76 ;
V_10 -> V_84 = 0 ;
V_10 -> V_99 = 87.5 * 16000 ;
V_10 -> V_100 = 400 * 16 ;
if ( V_11 [ V_232 ] . V_237 > 0 )
F_38 ( V_10 ) ;
F_120 ( V_10 ) ;
F_121 ( V_10 ) ;
}
static int F_122 ( struct V_222 * V_223 ,
const struct V_238 * V_239 )
{
struct V_207 * V_26 = F_123 ( F_124 ( V_223 ) ) ;
struct V_222 * V_240 ;
T_8 V_241 = V_223 -> V_242 -> V_159 . V_243 ;
const struct V_244 * V_245 ;
struct V_1 * V_10 = NULL ;
const struct V_246 * V_247 ;
int V_232 , V_151 , V_106 ;
F_23 ( V_211 , L_36 ,
V_26 -> V_248 . V_249 ,
V_26 -> V_248 . V_250 , V_241 ) ;
V_232 = V_239 -> V_251 ;
if ( V_232 < 0 || V_232 >= V_252 ) {
F_23 ( V_211 , L_37 , V_232 ) ;
V_106 = - V_253 ;
goto V_254;
}
F_42 ( V_48 L_38 , V_36 ,
V_11 [ V_232 ] . V_13 ) ;
if ( V_11 [ V_232 ] . V_245 >= 0 )
V_245 = & V_26 -> V_255 -> V_245 [ V_11 [ V_232 ] . V_245 ] -> V_242 [ 0 ] ;
else if ( V_241 < V_26 -> V_255 -> V_159 . V_256 )
V_245 = & V_26 -> V_255 -> V_245 [ V_241 ] -> V_242 [ 0 ] ;
else {
F_18 ( & V_223 -> V_26 , L_39 ,
V_241 , V_26 -> V_255 -> V_159 . V_256 - 1 ) ;
V_106 = - V_253 ;
goto V_254;
}
if ( V_245 -> V_159 . V_257 < 2 ) {
F_18 ( & V_223 -> V_26 , L_40 ,
V_241 , V_245 -> V_159 . V_257 ) ;
V_106 = - V_253 ;
goto V_254;
}
V_247 = & V_245 -> V_247 [ 1 ] . V_159 ;
if ( ! F_125 ( V_247 ) ) {
F_18 ( & V_223 -> V_26 , L_41 ,
V_36 , V_241 ) ;
F_18 ( & V_223 -> V_26 , L_42 ,
V_36 , V_247 -> V_258 ) ;
V_106 = - V_253 ;
goto V_254;
}
if ( F_126 ( V_247 ) ) {
F_18 ( & V_223 -> V_26 , L_43 ,
V_36 , V_241 ) ;
V_106 = - V_253 ;
goto V_254;
}
V_10 = F_108 ( V_26 , V_223 ) ;
if ( V_10 == NULL ) {
F_18 ( & V_223 -> V_26 , L_44 , V_36 ) ;
V_106 = - V_212 ;
goto V_254;
}
if ( V_26 -> V_248 . V_259 > 1 )
V_10 -> V_24 = V_260 ;
else if ( V_232 == V_261 )
V_10 -> V_24 = V_262 ;
else
V_10 -> V_24 = V_263 ;
F_23 ( V_211 , L_45 , V_10 -> V_24 ) ;
V_240 = V_26 -> V_255 -> V_245 [ 0 ] ;
V_10 -> V_264 = V_240 -> V_265 ;
F_23 ( V_211 , L_46 , V_10 -> V_264 ) ;
V_10 -> V_231 = F_127 ( 32 * V_10 -> V_264 , V_224 ) ;
if ( V_10 -> V_231 == NULL ) {
F_18 ( & V_223 -> V_26 , L_47 ) ;
V_106 = - V_212 ;
goto V_266;
}
for ( V_151 = 0 ; V_151 < V_10 -> V_264 ; V_151 ++ ) {
T_9 V_267 = F_128 ( V_240 -> V_242 [ V_151 ] . V_247 [ 1 ] . V_159 .
V_268 ) ;
V_10 -> V_231 [ V_151 ] =
( V_267 & 0x07ff ) * ( ( ( V_267 & 0x1800 ) >> 11 ) + 1 ) ;
F_23 ( V_211 , L_48 , V_151 ,
V_10 -> V_231 [ V_151 ] ) ;
}
V_10 -> V_218 = V_269 ++ ;
F_129 ( & V_10 -> V_142 ) ;
F_114 ( & V_10 -> V_147 ) ;
F_114 ( & V_10 -> V_270 ) ;
V_10 -> V_59 = V_11 [ V_232 ] . V_79 ;
if ( V_10 -> V_59 )
V_10 -> V_271 = V_11 [ V_232 ] . V_271 ;
V_10 -> V_12 = V_232 ;
V_10 -> V_47 = 0 ;
V_10 -> V_205 = V_241 ;
V_10 -> V_204 = 0 ;
V_10 -> V_272 = V_247 -> V_273 ;
V_10 -> V_274 = 0 ;
V_10 -> V_275 = 0 ;
V_10 -> V_42 = 0 ;
V_10 -> V_20 = V_276 ;
F_119 ( V_10 ) ;
F_105 ( V_10 ) ;
F_16 ( & V_10 -> V_5 ) ;
F_23 ( V_211 , L_5 ) ;
return 0 ;
V_266:
F_43 ( V_10 ) ;
V_254:
F_130 ( V_26 ) ;
return V_106 ;
}
static void F_131 ( struct V_222 * V_223 )
{
struct V_1 * V_10 = F_132 ( F_133 ( V_223 ) ) ;
F_23 ( V_211 , L_27 ) ;
if ( V_10 == NULL ) {
F_134 ( L_49 , V_36 ) ;
return;
}
F_37 ( & V_10 -> V_40 ) ;
F_40 ( V_10 ) ;
F_135 ( & V_10 -> V_210 ) ;
F_136 ( V_10 ) ;
V_10 -> V_47 = 1 ;
F_130 ( V_10 -> V_26 ) ;
V_10 -> V_26 = NULL ;
F_35 ( & V_10 -> V_40 ) ;
if ( V_10 -> V_42 ) {
F_42 ( V_48 L_50 ,
V_36 ) ;
F_137 ( & V_10 -> V_147 ) ;
F_137 ( & V_10 -> V_270 ) ;
} else {
F_43 ( V_10 ) ;
}
F_23 ( V_211 , L_5 ) ;
}
static int T_10 F_138 ( void )
{
int V_38 ;
F_23 ( V_211 , L_27 ) ;
F_23 ( V_39 , L_51 ) ;
F_23 ( V_211 , L_52 ) ;
F_23 ( V_190 , L_53 ) ;
if ( V_22 != V_23 ) {
V_158 [ 6 ] . V_277 = 0 ;
V_158 [ 7 ] . V_277 = 0 ;
}
V_38 = F_139 ( & V_278 ) ;
if ( V_38 == 0 ) {
F_42 (KERN_INFO DRIVER_DESC L_54 USBVISION_VERSION_STRING L_55 ) ;
F_23 ( V_211 , L_5 ) ;
}
return V_38 ;
}
static void T_11 F_140 ( void )
{
F_23 ( V_211 , L_27 ) ;
F_141 ( & V_278 ) ;
F_23 ( V_211 , L_5 ) ;
}
