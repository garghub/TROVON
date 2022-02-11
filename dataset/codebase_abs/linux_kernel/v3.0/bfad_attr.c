static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
T_1 V_11 = - 1 ;
unsigned long V_12 ;
V_4 = F_2 ( V_2 -> V_13 . V_14 ) ;
V_6 = (struct V_5 * ) V_4 -> V_15 [ 0 ] ;
V_8 = V_6 -> V_8 ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_10 = F_4 ( V_6 , V_2 -> V_17 ) ;
if ( V_10 )
V_11 = F_5 ( & V_10 -> V_18 ) ;
F_6 ( V_2 ) = V_11 ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
T_2 V_19 = 0 ;
unsigned long V_12 ;
V_4 = F_2 ( V_2 -> V_13 . V_14 ) ;
V_6 = (struct V_5 * ) V_4 -> V_15 [ 0 ] ;
V_8 = V_6 -> V_8 ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_10 = F_4 ( V_6 , V_2 -> V_17 ) ;
if ( V_10 )
V_19 = F_9 ( & V_10 -> V_18 ) ;
F_10 ( V_2 ) = F_11 ( V_19 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
}
static void
F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
T_2 V_20 = 0 ;
unsigned long V_12 ;
V_4 = F_2 ( V_2 -> V_13 . V_14 ) ;
V_6 = (struct V_5 * ) V_4 -> V_15 [ 0 ] ;
V_8 = V_6 -> V_8 ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_10 = F_4 ( V_6 , V_2 -> V_17 ) ;
if ( V_10 )
V_20 = F_13 ( & V_10 -> V_18 ) ;
F_14 ( V_2 ) = F_11 ( V_20 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
}
static void
F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_21 * V_22 = V_6 -> V_22 ;
F_16 ( V_4 ) =
F_17 ( F_18 ( V_22 -> V_23 ) ) ;
}
static void
F_19 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_24 V_25 ;
F_20 ( & V_8 -> V_26 . V_27 . V_28 , & V_25 ) ;
switch ( V_25 . V_29 ) {
case V_30 :
F_21 ( V_4 ) = V_31 ;
break;
case V_32 :
F_21 ( V_4 ) = V_33 ;
break;
case V_34 :
F_21 ( V_4 ) = V_35 ;
break;
case V_36 :
F_21 ( V_4 ) = V_37 ;
break;
default:
F_21 ( V_4 ) = V_38 ;
break;
}
}
static void
F_22 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_39 V_40 ;
F_23 ( & V_8 -> V_41 , & V_40 ) ;
switch ( V_40 . V_42 ) {
case V_43 :
F_24 ( V_4 ) = V_44 ;
break;
case V_45 :
F_24 ( V_4 ) = V_46 ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
F_24 ( V_4 ) = V_51 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
default:
F_24 ( V_4 ) = V_57 ;
break;
}
}
static void
F_25 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_21 * V_22 = V_6 -> V_22 ;
memset ( F_26 ( V_4 ) , 0 ,
sizeof( F_26 ( V_4 ) ) ) ;
if ( V_22 -> V_58 & V_59 )
F_26 ( V_4 ) [ 2 ] = 1 ;
F_26 ( V_4 ) [ 7 ] = 1 ;
}
static void
F_27 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_39 V_40 ;
F_23 ( & V_8 -> V_41 , & V_40 ) ;
switch ( V_40 . V_60 ) {
case V_61 :
F_28 ( V_4 ) = V_62 ;
break;
case V_63 :
F_28 ( V_4 ) = V_64 ;
break;
case V_65 :
F_28 ( V_4 ) = V_66 ;
break;
case V_67 :
F_28 ( V_4 ) = V_68 ;
break;
case V_69 :
F_28 ( V_4 ) = V_70 ;
break;
default:
F_28 ( V_4 ) = V_71 ;
break;
}
}
static void
F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_21 * V_22 = V_6 -> V_22 ;
T_3 V_72 = 0 ;
V_72 = F_30 ( V_22 -> V_23 ) ;
F_31 ( V_4 ) = F_11 ( V_72 ) ;
}
static struct V_73 *
F_32 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_74 V_75 ;
union V_76 * V_77 ;
struct V_73 * V_78 ;
T_4 V_79 ;
unsigned long V_12 ;
V_77 = F_33 ( sizeof( union V_76 ) , V_80 ) ;
if ( V_77 == NULL )
return NULL ;
V_78 = & V_8 -> V_81 ;
F_34 ( & V_75 . V_82 ) ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
memset ( V_78 , 0 , sizeof( struct V_73 ) ) ;
V_79 = F_35 ( F_36 ( & V_8 -> V_41 ) ,
V_77 , V_83 , & V_75 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
if ( V_79 != V_84 )
return NULL ;
F_37 ( & V_75 . V_82 ) ;
V_78 -> V_85 = V_77 -> V_86 . V_87 ;
V_78 -> V_88 = V_77 -> V_86 . V_88 ;
V_78 -> V_89 = V_77 -> V_86 . V_89 ;
V_78 -> V_90 = V_77 -> V_86 . V_90 ;
V_78 -> V_91 = V_77 -> V_86 . V_91 ;
V_78 -> V_92 = V_77 -> V_86 . V_92 ;
V_78 -> V_93 = V_77 -> V_86 . V_93 ;
V_78 -> V_94 = V_77 -> V_86 . V_94 ;
V_78 -> V_95 = V_77 -> V_86 . V_96 ;
V_78 -> V_97 = V_77 -> V_86 . V_98 ;
V_78 -> V_99 = V_77 -> V_86 . V_100 ;
V_78 -> V_101 = V_77 -> V_86 . V_102 ;
V_78 -> V_103 = V_77 -> V_86 . V_104 ;
V_78 -> V_105 = V_77 -> V_86 . V_106 ;
F_38 ( V_77 ) ;
return V_78 ;
}
static void
F_39 ( struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_74 V_75 ;
unsigned long V_12 ;
T_4 V_79 ;
F_34 ( & V_75 . V_82 ) ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_79 = F_40 ( F_36 ( & V_8 -> V_41 ) , V_83 ,
& V_75 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
if ( V_79 != V_84 )
return;
F_37 ( & V_75 . V_82 ) ;
return;
}
static void
F_41 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_9 * V_10 = V_110 -> V_10 ;
struct V_7 * V_8 = V_10 -> V_112 -> V_8 ;
unsigned long V_12 ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_108 -> V_113 = F_42 ( & V_8 -> V_41 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
}
static void
F_43 ( struct V_107 * V_108 , T_1 V_114 )
{
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_9 * V_10 = V_110 -> V_10 ;
struct V_7 * V_8 = V_10 -> V_112 -> V_8 ;
unsigned long V_12 ;
if ( V_114 > 0 ) {
F_3 ( & V_8 -> V_16 , V_12 ) ;
F_44 ( & V_8 -> V_41 , V_114 ) ;
V_108 -> V_113 = F_42 ( & V_8 -> V_41 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
}
}
static int
F_45 ( struct V_115 * V_115 , bool V_116 )
{
char * V_117 = V_115 -> V_118 ;
struct V_3 * V_4 = V_115 -> V_4 ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_119 V_120 ;
struct V_121 * V_122 ;
int V_123 = 0 , V_79 ;
unsigned long V_12 ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
F_46 ( V_115 -> V_19 , ( V_124 * ) & V_120 . V_125 ) ;
F_46 ( V_115 -> V_20 , ( V_124 * ) & V_120 . V_126 ) ;
if ( strlen ( V_117 ) > 0 )
strcpy ( ( char * ) & V_120 . V_127 , V_117 ) ;
V_120 . V_128 = V_59 ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
F_47 (vp, &bfad->pbc_vport_list, list_entry) {
if ( V_120 . V_126 ==
V_122 -> V_129 . V_130 . V_120 . V_126 ) {
V_120 . V_131 =
V_122 -> V_129 . V_130 . V_120 . V_131 ;
break;
}
}
F_7 ( & V_8 -> V_16 , V_12 ) ;
V_79 = F_48 ( V_8 , 0 , & V_120 , & V_115 -> V_13 ) ;
if ( V_79 == V_84 ) {
struct V_121 * V_132 ;
struct V_133 * V_129 ;
struct V_3 * V_134 ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_129 = F_49 ( & V_8 -> V_26 , 0 ,
V_120 . V_126 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
if ( V_129 == NULL )
return V_135 ;
F_50 ( V_115 , V_136 ) ;
if ( V_116 ) {
F_3 ( & V_8 -> V_16 , V_12 ) ;
F_51 ( V_129 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
F_50 ( V_115 , V_137 ) ;
}
V_132 = V_129 -> V_138 ;
V_134 = V_132 -> V_139 . V_6 -> V_4 ;
F_52 ( V_134 ) = F_53 ( ( V_124 * ) & V_120 . V_125 ) ;
F_54 ( V_134 ) = F_53 ( ( V_124 * ) & V_120 . V_126 ) ;
V_115 -> V_111 = V_132 ;
V_132 -> V_139 . V_6 -> V_115 = V_115 ;
} else if ( V_79 == V_140 )
return V_135 ;
else if ( V_79 == V_141 )
return V_135 ;
else if ( V_79 == V_142 )
return V_143 ;
else if ( V_79 == V_144 )
return V_135 ;
else
return V_145 ;
return V_123 ;
}
static int
F_55 ( struct V_115 * V_115 )
{
struct V_121 * V_132 = (struct V_121 * ) V_115 -> V_111 ;
struct V_5 * V_6 =
(struct V_5 * ) V_132 -> V_139 . V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_21 * V_22 ;
struct V_133 * V_129 ;
struct V_3 * V_134 ;
T_3 V_126 ;
int V_79 ;
unsigned long V_12 ;
struct V_146 V_75 ;
if ( V_6 -> V_12 & V_147 )
goto V_148;
V_22 = V_6 -> V_22 ;
V_134 = V_132 -> V_139 . V_6 -> V_4 ;
F_46 ( F_54 ( V_134 ) , ( V_124 * ) & V_126 ) ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_129 = F_49 ( & V_8 -> V_26 , 0 , V_126 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
if ( V_129 == NULL )
return V_135 ;
V_132 -> V_139 . V_12 |= V_147 ;
V_132 -> V_149 = & V_75 ;
F_34 ( V_132 -> V_149 ) ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_79 = F_56 ( & V_132 -> V_129 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
if ( V_79 == V_150 ) {
V_132 -> V_139 . V_12 &= ~ V_147 ;
V_132 -> V_149 = NULL ;
return - 1 ;
}
F_37 ( V_132 -> V_149 ) ;
V_148:
F_57 ( V_8 , V_6 ) ;
F_38 ( V_132 ) ;
return 0 ;
}
static int
F_58 ( struct V_115 * V_115 , bool V_116 )
{
struct V_121 * V_132 ;
struct V_7 * V_8 ;
struct V_133 * V_129 ;
struct V_3 * V_134 ;
T_3 V_126 ;
unsigned long V_12 ;
V_132 = (struct V_121 * ) V_115 -> V_111 ;
V_8 = V_132 -> V_139 . V_8 ;
V_134 = V_132 -> V_139 . V_6 -> V_4 ;
F_46 ( F_54 ( V_134 ) , ( V_124 * ) & V_126 ) ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
V_129 = F_49 ( & V_8 -> V_26 , 0 , V_126 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
if ( V_129 == NULL )
return V_135 ;
if ( V_116 ) {
F_51 ( V_129 ) ;
F_50 ( V_115 , V_137 ) ;
} else {
F_59 ( V_129 ) ;
F_50 ( V_115 , V_136 ) ;
}
return 0 ;
}
static T_5
F_60 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_154 [ V_155 ] ;
F_62 ( & V_8 -> V_41 , V_154 ) ;
return snprintf ( V_153 , V_156 , L_1 , V_154 ) ;
}
static T_5
F_63 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_157 [ V_158 ] ;
F_64 ( & V_8 -> V_41 , V_157 ) ;
return snprintf ( V_153 , V_156 , L_1 , V_157 ) ;
}
static T_5
F_65 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_157 [ V_158 ] ;
char V_159 [ V_160 ] ;
F_64 ( & V_8 -> V_41 , V_157 ) ;
if ( ! strcmp ( V_157 , L_2 ) )
snprintf ( V_159 , V_160 ,
L_3 ) ;
else if ( ! strcmp ( V_157 , L_4 ) )
snprintf ( V_159 , V_160 ,
L_5 ) ;
else if ( ! strcmp ( V_157 , L_6 ) )
snprintf ( V_159 , V_160 ,
L_7 ) ;
else if ( ! strcmp ( V_157 , L_8 ) )
snprintf ( V_159 , V_160 ,
L_9 ) ;
else if ( ! strcmp ( V_157 , L_10 ) )
snprintf ( V_159 , V_160 ,
L_11 ) ;
else if ( ! strcmp ( V_157 , L_12 ) )
snprintf ( V_159 , V_160 ,
L_13 ) ;
else if ( ! strcmp ( V_157 , L_14 ) )
snprintf ( V_159 , V_160 ,
L_15 ) ;
else if ( ! strcmp ( V_157 , L_16 ) )
snprintf ( V_159 , V_160 ,
L_17 ) ;
else if ( ! strcmp ( V_157 , L_18 ) )
snprintf ( V_159 , V_160 ,
L_19 ) ;
else if ( ! strcmp ( V_157 , L_20 ) )
snprintf ( V_159 , V_160 ,
L_21 ) ;
else if ( ! strcmp ( V_157 , L_22 ) )
snprintf ( V_159 , V_160 ,
L_23 ) ;
else if ( ! strcmp ( V_157 , L_24 ) )
snprintf ( V_159 , V_160 ,
L_25 ) ;
else if ( ! strcmp ( V_157 , L_26 ) )
snprintf ( V_159 , V_160 ,
L_15 ) ;
else
snprintf ( V_159 , V_160 ,
L_27 ) ;
return snprintf ( V_153 , V_156 , L_1 , V_159 ) ;
}
static T_5
F_66 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_21 * V_22 = V_6 -> V_22 ;
T_2 V_125 ;
V_125 = F_67 ( V_22 -> V_23 ) ;
return snprintf ( V_153 , V_156 , L_28 , F_11 ( V_125 ) ) ;
}
static T_5
F_68 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_24 V_25 ;
char V_161 [ V_162 ] ;
F_20 ( & V_8 -> V_26 . V_27 . V_28 , & V_25 ) ;
strncpy ( V_161 , V_25 . V_120 . V_127 . V_161 ,
V_162 ) ;
return snprintf ( V_153 , V_156 , L_1 , V_161 ) ;
}
static T_5
F_69 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_163 [ V_164 ] ;
F_70 ( & V_8 -> V_41 , V_163 ) ;
return snprintf ( V_153 , V_156 , L_1 , V_163 ) ;
}
static T_5
F_71 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
return snprintf ( V_153 , V_156 , L_1 , V_165 ) ;
}
static T_5
F_72 ( struct V_151 * V_13 ,
struct V_152 * V_40 , char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_166 [ V_164 ] ;
F_73 ( & V_8 -> V_41 , V_166 ) ;
return snprintf ( V_153 , V_156 , L_1 , V_166 ) ;
}
static T_5
F_74 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_167 [ V_164 ] ;
F_75 ( & V_8 -> V_41 , V_167 ) ;
return snprintf ( V_153 , V_156 , L_1 , V_167 ) ;
}
static T_5
F_76 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_7 * V_8 = V_6 -> V_8 ;
return snprintf ( V_153 , V_156 , L_29 ,
F_77 ( & V_8 -> V_41 ) ) ;
}
static T_5
F_78 ( struct V_151 * V_13 , struct V_152 * V_40 ,
char * V_153 )
{
return snprintf ( V_153 , V_156 , L_1 , V_168 ) ;
}
static T_5
F_79 ( struct V_151 * V_13 ,
struct V_152 * V_40 , char * V_153 )
{
struct V_3 * V_4 = F_61 ( V_13 ) ;
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_15 [ 0 ] ;
struct V_21 * V_22 = V_6 -> V_22 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_169 = 2048 ;
T_3 * V_170 = NULL ;
unsigned long V_12 ;
V_170 = F_33 ( sizeof( T_3 ) * V_169 , V_171 ) ;
if ( V_170 == NULL )
return snprintf ( V_153 , V_156 , L_30 ) ;
F_3 ( & V_8 -> V_16 , V_12 ) ;
F_80 ( V_22 -> V_23 , V_170 , & V_169 ) ;
F_7 ( & V_8 -> V_16 , V_12 ) ;
F_38 ( V_170 ) ;
return snprintf ( V_153 , V_156 , L_29 , V_169 ) ;
}
