static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( T_1 V_6 )
{
unsigned V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
if ( V_9 [ V_7 ] . V_6 == V_6 )
return V_9 + V_7 ;
return V_9 ;
}
static void F_4 ( struct V_1 * V_10 )
{
int V_7 ;
V_10 -> V_11 = - 1 ;
for ( V_7 = 0 ; V_7 < V_10 -> V_12 ; V_7 ++ )
F_5 ( V_7 , & V_10 -> V_13 ) ;
V_10 -> V_14 = 0 ;
}
static inline int F_6 ( struct V_1 * V_10 )
{
return F_7 ( V_15 , & V_10 -> V_13 ) ;
}
static void F_8 ( struct V_1 * V_10 , int V_16 )
{
if ( V_16 )
F_9 ( V_15 , & V_10 -> V_13 ) ;
else
F_5 ( V_15 , & V_10 -> V_13 ) ;
}
static inline void F_10 ( struct V_1 * V_10 , unsigned int V_17 ,
unsigned int V_18 )
{
F_11 ( V_18 , V_10 -> V_19 + V_17 ) ;
}
static inline unsigned int F_12 ( struct V_1 * V_10 ,
unsigned int V_17 )
{
return F_13 ( V_10 -> V_19 + V_17 ) ;
}
static inline void F_14 ( struct V_1 * V_10 , unsigned int V_17 ,
unsigned int V_18 , unsigned int V_20 )
{
unsigned int V_21 = F_12 ( V_10 , V_17 ) ;
V_21 = ( V_21 & ~ V_20 ) | ( V_18 & V_20 ) ;
F_10 ( V_10 , V_17 , V_21 ) ;
}
static inline void F_15 ( struct V_1 * V_10 ,
unsigned int V_17 , unsigned int V_18 )
{
F_14 ( V_10 , V_17 , 0 , V_18 ) ;
}
static inline void F_16 ( struct V_1 * V_10 ,
unsigned int V_17 , unsigned int V_18 )
{
F_14 ( V_10 , V_17 , V_18 , V_18 ) ;
}
static int F_17 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
int V_22 ;
F_18 ( 20 ) ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_22 = F_12 ( V_10 , V_24 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
return ( V_22 & ( V_25 | V_26 ) ) != V_25 ;
}
static int F_21 ( struct V_1 * V_10 ,
T_2 V_27 , T_3 V_28 , T_3 V_29 )
{
unsigned int V_30 ;
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_30 = V_31 | ( ( V_27 << V_32 ) & V_33 ) ;
V_30 |= V_34 ;
V_30 |= V_35 ;
F_10 ( V_10 , V_36 , V_30 ) ;
( void ) F_12 ( V_10 , V_24 ) ;
V_30 = V_29 | ( ( V_28 << V_37 ) & V_38 ) ;
F_10 ( V_10 , V_24 , V_30 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
F_22 ( 2 ) ;
F_23 ( V_10 -> V_39 , F_17 ( V_10 ) ,
V_40 ) ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_30 = F_12 ( V_10 , V_24 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
if ( V_30 & V_25 ) {
F_24 ( V_10 , L_1 , V_27 ,
V_28 , V_29 ) ;
return - V_41 ;
}
if ( V_30 & V_26 ) {
F_24 ( V_10 , L_2 , V_27 ,
V_28 , V_29 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
int V_22 ;
F_18 ( 20 ) ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_22 = F_12 ( V_10 , V_24 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
return V_22 & ( V_42 | V_26 ) ;
}
static int F_26 ( struct V_1 * V_10 ,
T_2 V_27 , T_3 V_28 , T_3 * V_29 )
{
unsigned int V_30 ;
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_30 = V_31 | ( ( V_27 << V_32 ) & V_33 ) ;
V_30 |= V_34 ;
V_30 |= V_35 ;
F_10 ( V_10 , V_36 , V_30 ) ;
( void ) F_12 ( V_10 , V_24 ) ;
V_30 = V_43 | ( ( V_28 << V_37 ) & V_38 ) ;
F_10 ( V_10 , V_24 , V_30 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
F_23 ( V_10 -> V_39 ,
F_25 ( V_10 ) , V_40 ) ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_30 = F_12 ( V_10 , V_24 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
if ( V_30 & V_26 ) {
F_24 ( V_10 , L_3 , V_27 , V_28 ) ;
return - V_41 ;
}
if ( ! ( V_30 & V_42 ) ) {
F_24 ( V_10 , L_4 , V_27 ,
V_28 ) ;
return - V_41 ;
}
* V_29 = V_30 & 0xff ;
return 0 ;
}
static int F_27 ( struct V_44 * V_45 , T_2 V_27 ,
unsigned short V_13 , char V_46 , T_3 V_28 ,
int V_47 , union V_48 * V_49 )
{
struct V_2 * V_4 = F_28 ( V_45 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_50 = - V_51 ;
if ( V_47 != V_52 ) {
F_24 ( V_10 , L_5 , V_47 ) ;
return - V_51 ;
}
if ( V_46 == V_53 )
V_50 = F_21 ( V_10 , V_27 , V_28 , V_49 -> V_54 ) ;
else if ( V_46 == V_55 )
V_50 = F_26 ( V_10 , V_27 , V_28 , & V_49 -> V_54 ) ;
return V_50 ;
}
static void F_29 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_16 ( V_10 , V_56 , V_57 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
}
static T_1 F_30 ( struct V_44 * V_45 )
{
return V_58 |
V_59 ;
}
static int F_31 ( struct V_1 * V_10 )
{
struct V_44 * V_60 = & V_10 -> V_44 ;
int V_50 ;
F_29 ( V_10 ) ;
V_60 -> V_61 = V_62 ;
V_60 -> V_63 = & V_64 ;
strcpy ( V_60 -> V_65 , L_6 ) ;
V_60 -> V_3 . V_66 = & V_10 -> V_67 -> V_3 ;
F_32 ( V_60 , & V_10 -> V_4 ) ;
V_50 = F_33 ( V_60 ) ;
if ( V_50 )
F_34 ( V_68 L_7 ) ;
return V_50 ;
}
static void F_35 ( struct V_1 * V_10 )
{
F_36 ( & V_10 -> V_44 ) ;
}
static void F_37 ( struct V_1 * V_10 )
{
F_10 ( V_10 , V_69 , V_10 -> V_70 [ 0 ] ) ;
F_10 ( V_10 , V_71 , V_10 -> V_70 [ 1 ] ) ;
if ( V_10 -> V_12 > 2 ) {
F_10 ( V_10 , V_72 , V_10 -> V_70 [ 2 ] ) ;
F_15 ( V_10 , V_73 , V_74 ) ;
}
else
F_16 ( V_10 , V_73 , V_74 ) ;
F_10 ( V_10 , V_75 , 0 ) ;
}
static void F_38 ( struct V_1 * V_10 )
{
int V_76 ;
struct V_77 * V_78 = & V_10 -> V_79 ;
V_76 = ( ( V_78 -> V_80 << V_81 ) & V_82 ) |
( V_78 -> V_83 & V_84 ) ;
F_10 ( V_10 , V_85 , V_76 ) ;
F_10 ( V_10 , V_86 , 0 ) ;
F_14 ( V_10 , V_87 , V_78 -> V_83 ,
V_88 ) ;
switch ( V_10 -> V_79 . V_6 ) {
case V_89 :
F_14 ( V_10 , V_90 ,
V_91 | V_92 | V_93 ,
V_94 ) ;
break;
case V_95 :
F_14 ( V_10 , V_90 ,
V_96 | V_97 | V_98 ,
V_94 ) ;
break;
case V_99 :
F_14 ( V_10 , V_90 ,
V_96 | V_100 | V_101 ,
V_94 ) ;
break;
default:
F_24 ( V_10 , L_8 , V_10 -> V_79 . V_6 ) ;
break;
}
F_14 ( V_10 , V_90 , V_102 ,
V_103 ) ;
}
static int F_39 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_37 ( V_10 ) ;
F_38 ( V_10 ) ;
F_8 ( V_10 , 0 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_10 )
{
F_10 ( V_10 , V_104 , V_105 ) ;
F_16 ( V_10 , V_56 , V_105 ) ;
}
static void F_41 ( struct V_1 * V_10 )
{
F_15 ( V_10 , V_56 , V_105 ) ;
}
static void F_42 ( struct V_1 * V_10 )
{
F_16 ( V_10 , V_90 , V_106 ) ;
}
static void F_43 ( struct V_1 * V_10 )
{
F_15 ( V_10 , V_90 , V_106 ) ;
}
static void F_44 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_10 ( V_10 , 0x3038 , 0x8 ) ;
F_10 ( V_10 , 0x315c , 0x80008 ) ;
F_10 ( V_10 , V_107 , V_108 | V_109 ) ;
F_10 ( V_10 , V_107 , V_110 | V_111 ) ;
F_10 ( V_10 , V_107 , V_110 | V_109 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
F_45 ( 5 ) ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_10 ( V_10 , V_107 , V_112 | V_110 | V_111 ) ;
F_16 ( V_10 , V_113 , V_114 ) ;
F_15 ( V_10 , V_73 , V_115 ) ;
F_15 ( V_10 , V_90 , V_106 ) ;
F_10 ( V_10 , V_56 , 0 ) ;
F_14 ( V_10 , V_116 , 2 , V_117 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
}
static void F_46 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_43 ( V_10 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
F_22 ( 1 ) ;
F_23 ( V_10 -> V_118 ,
! F_7 ( V_119 , & V_10 -> V_13 ) , V_120 ) ;
if ( F_7 ( V_119 , & V_10 -> V_13 ) )
F_24 ( V_10 , L_9 ) ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_10 -> V_121 = V_122 ;
F_41 ( V_10 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
}
static void F_47 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_15 ( V_10 , V_73 , V_115 ) ;
F_10 ( V_10 , V_123 , V_124 ) ;
F_10 ( V_10 , V_125 , V_126 | V_127 ) ;
F_10 ( V_10 , V_128 , V_129 | V_130 ) ;
F_10 ( V_10 , V_128 , V_129 | V_130 | V_131 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
F_45 ( 5 ) ;
}
static void F_48 ( struct V_1 * V_10 )
{
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_10 ( V_10 , V_128 , V_129 | V_130 | V_132 ) ;
F_10 ( V_10 , V_123 , V_124 ) ;
F_10 ( V_10 , V_125 , V_126 ) ;
F_16 ( V_10 , V_73 , V_115 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
}
static int F_49 ( struct V_1 * V_10 )
{
return F_50 ( V_10 , V_133 , V_134 , 0 ) ;
}
static int F_51 ( struct V_1 * V_10 )
{
struct V_135 V_136 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_121 != V_138 )
F_53 ( V_10 , L_10 ,
V_10 -> V_121 ) ;
V_50 = F_49 ( V_10 ) ;
if ( V_50 )
goto V_139;
V_136 . V_140 = V_141 ;
V_136 . V_142 . type = V_143 ;
V_136 . V_142 . V_27 = V_10 -> V_144 ;
V_50 = F_50 ( V_10 , V_133 , V_145 , & V_136 ) ;
if ( V_50 )
goto V_139;
V_10 -> V_146 = V_136 . V_140 ;
if ( V_10 -> V_146 != V_147 ) {
F_24 ( V_10 , L_11 , V_10 -> V_146 ) ;
V_50 = - V_51 ;
goto V_139;
}
V_50 = 0 ;
V_10 -> V_121 = V_122 ;
V_139:
F_48 ( V_10 ) ;
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_55 ( struct V_1 * V_10 )
{
struct V_148 V_149 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_149 . V_150 = V_151 ;
V_149 . V_29 = V_152 ;
return F_50 ( V_10 , V_133 , V_153 , & V_149 ) ;
}
static int F_56 ( struct V_1 * V_10 )
{
struct V_154 V_155 ;
int V_50 ;
F_57 ( & V_155 , & V_10 -> V_79 , V_10 -> V_156 ) ;
V_50 = F_50 ( V_10 , V_133 , V_157 , 0 ) ;
if ( V_50 == 0 )
V_50 = F_50 ( V_10 , V_158 , V_159 , & V_155 ) ;
V_50 += F_55 ( V_10 ) ;
return V_50 ;
}
static int F_58 ( struct V_1 * V_10 , int V_160 )
{
int V_7 ;
F_8 ( V_10 , 1 ) ;
if ( V_160 )
V_10 -> V_161 = V_161 ;
else
V_10 -> V_161 = V_10 -> V_79 . V_162 ;
if ( V_163 > 3 )
V_163 = 3 ;
V_10 -> V_12 = 0 ;
for ( V_7 = 0 ; V_7 < V_163 ; V_7 ++ ) {
V_10 -> V_164 [ V_7 ] = F_59 ( & V_10 -> V_67 -> V_3 ,
V_10 -> V_161 , V_10 -> V_70 + V_7 ,
V_165 ) ;
if ( V_10 -> V_164 [ V_7 ] == NULL ) {
F_53 ( V_10 , L_12 ) ;
break;
}
memset ( V_10 -> V_164 [ V_7 ] , 0xcc , V_10 -> V_161 ) ;
( V_10 -> V_12 ) ++ ;
}
switch ( V_10 -> V_12 ) {
case 1 :
F_60 ( & V_10 -> V_67 -> V_3 , V_10 -> V_161 ,
V_10 -> V_164 [ 0 ] , V_10 -> V_70 [ 0 ] ) ;
V_10 -> V_12 = 0 ;
case 0 :
F_24 ( V_10 , L_13 ) ;
return - V_166 ;
case 2 :
if ( V_163 > 2 )
F_53 ( V_10 , L_14 ) ;
break;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_10 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_10 -> V_12 ; V_7 ++ ) {
F_60 ( & V_10 -> V_67 -> V_3 , V_10 -> V_161 ,
V_10 -> V_164 [ V_7 ] , V_10 -> V_70 [ V_7 ] ) ;
V_10 -> V_164 [ V_7 ] = NULL ;
}
V_10 -> V_12 = 0 ;
}
static T_4 F_62 ( struct V_1 * V_10 ,
char T_5 * V_167 , T_6 V_168 , T_7 * V_169 )
{
int V_170 ;
unsigned long V_13 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
if ( V_10 -> V_11 < 0 ) {
F_24 ( V_10 , L_15 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
return - V_41 ;
}
V_170 = V_10 -> V_11 ;
F_5 ( V_170 , & V_10 -> V_13 ) ;
if ( ++ ( V_10 -> V_11 ) >= V_10 -> V_12 )
V_10 -> V_11 = 0 ;
if ( ! F_7 ( V_10 -> V_11 , & V_10 -> V_13 ) )
V_10 -> V_11 = - 1 ;
V_10 -> V_14 = 0 ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
if ( V_168 > V_10 -> V_79 . V_162 )
V_168 = V_10 -> V_79 . V_162 ;
if ( F_63 ( V_167 , V_10 -> V_164 [ V_170 ] , V_168 ) )
return - V_171 ;
( * V_169 ) += V_168 ;
return V_168 ;
}
static int F_64 ( struct V_1 * V_10 , enum V_172 V_121 )
{
int V_50 ;
unsigned long V_13 ;
if ( V_10 -> V_12 == 0 )
if ( F_58 ( V_10 , 0 ) )
return - V_166 ;
if ( F_6 ( V_10 ) ) {
F_56 ( V_10 ) ;
V_50 = F_39 ( V_10 ) ;
if ( V_50 )
return V_50 ;
}
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_4 ( V_10 ) ;
F_40 ( V_10 ) ;
V_10 -> V_121 = V_121 ;
F_42 ( V_10 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
return 0 ;
}
static T_4 F_65 ( struct V_173 * V_174 ,
char T_5 * V_167 , T_6 V_168 , T_7 * V_169 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
int V_50 = 0 ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_121 == V_176 ) {
if ( V_10 -> V_11 >= 0 ) {
V_50 = F_62 ( V_10 , V_167 , V_168 , V_169 ) ;
if ( V_50 != 0 )
goto V_177;
}
} else if ( V_10 -> V_121 == V_178 || V_10 -> V_121 == V_138 ) {
V_50 = - V_41 ;
goto V_177;
} else if ( V_10 -> V_121 != V_122 ) {
V_50 = - V_179 ;
goto V_177;
}
if ( V_10 -> V_61 && V_10 -> V_61 != V_174 ) {
V_50 = - V_179 ;
goto V_177;
}
V_10 -> V_61 = V_174 ;
if ( V_10 -> V_121 != V_176 ) {
V_50 = F_64 ( V_10 , V_180 ) ;
if ( V_50 )
goto V_177;
}
F_23 ( V_10 -> V_118 , V_10 -> V_11 >= 0 , V_120 ) ;
if ( V_10 -> V_11 < 0 ) {
F_24 ( V_10 , L_16 ) ;
F_46 ( V_10 ) ;
V_50 = - V_41 ;
goto V_177;
}
V_50 = F_62 ( V_10 , V_167 , V_168 , V_169 ) ;
V_177:
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_66 ( struct V_173 * V_174 , void * V_181 ,
enum V_182 type )
{
struct V_1 * V_10 = V_174 -> V_175 ;
int V_50 = - V_51 ;
if ( type != V_183 )
goto V_139;
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_121 != V_122 || V_10 -> V_184 == 0 )
goto V_177;
V_10 -> V_185 = 0 ;
V_50 = F_64 ( V_10 , V_186 ) ;
V_177:
F_54 ( & V_10 -> V_137 ) ;
V_139:
return V_50 ;
}
static int F_67 ( struct V_173 * V_174 , void * V_181 ,
enum V_182 type )
{
struct V_1 * V_10 = V_174 -> V_175 ;
int V_50 = - V_51 ;
if ( type != V_183 )
goto V_139;
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_121 != V_186 )
goto V_177;
F_46 ( V_10 ) ;
V_50 = 0 ;
V_177:
F_54 ( & V_10 -> V_137 ) ;
V_139:
return V_50 ;
}
static int F_68 ( struct V_1 * V_10 , int V_187 )
{
struct V_188 * V_189 = V_10 -> V_190 + V_187 ;
F_69 ( & V_189 -> V_191 ) ;
V_189 -> V_192 . V_193 = F_70 ( V_10 -> V_79 . V_162 ) ;
V_189 -> V_167 = F_71 ( V_189 -> V_192 . V_193 ) ;
if ( V_189 -> V_167 == NULL )
return - V_166 ;
V_189 -> V_194 = 0 ;
V_189 -> V_10 = V_10 ;
V_189 -> V_192 . V_187 = V_187 ;
V_189 -> V_192 . type = V_183 ;
V_189 -> V_192 . V_195 = V_196 ;
V_189 -> V_192 . V_197 = V_198 ;
V_189 -> V_192 . V_199 . V_200 = 2 * V_187 * V_189 -> V_192 . V_193 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_10 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_10 -> V_184 ; V_7 ++ )
if ( V_10 -> V_190 [ V_7 ] . V_194 > 0 )
return - V_179 ;
for ( V_7 = 0 ; V_7 < V_10 -> V_184 ; V_7 ++ )
F_73 ( V_10 -> V_190 [ V_7 ] . V_167 ) ;
V_10 -> V_184 = 0 ;
F_74 ( V_10 -> V_190 ) ;
V_10 -> V_190 = NULL ;
F_69 ( & V_10 -> V_201 ) ;
F_69 ( & V_10 -> V_202 ) ;
return 0 ;
}
static int F_75 ( struct V_173 * V_174 , void * V_181 ,
struct V_203 * V_204 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
int V_50 = 0 ;
if ( V_204 -> V_197 != V_198 )
return - V_51 ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_204 -> V_205 == 0 ) {
if ( V_10 -> V_121 == V_186 )
F_46 ( V_10 ) ;
V_50 = F_72 ( V_10 ) ;
goto V_139;
}
if ( V_10 -> V_121 != V_122 || ( V_10 -> V_61 && V_10 -> V_61 != V_174 ) ) {
V_50 = - V_179 ;
goto V_139;
}
V_10 -> V_61 = V_174 ;
if ( V_204 -> V_205 < V_206 )
V_204 -> V_205 = V_206 ;
else if ( V_204 -> V_205 > V_207 )
V_204 -> V_205 = V_207 ;
if ( V_10 -> V_184 > 0 ) {
V_50 = F_72 ( V_10 ) ;
if ( V_50 )
goto V_139;
}
V_10 -> V_190 = F_76 ( V_204 -> V_205 * sizeof( struct V_188 ) ,
V_165 ) ;
if ( V_10 -> V_190 == NULL ) {
V_50 = - V_166 ;
goto V_139;
}
for ( V_10 -> V_184 = 0 ; V_10 -> V_184 < V_204 -> V_205 ; ( V_10 -> V_184 ++ ) ) {
V_50 = F_68 ( V_10 , V_10 -> V_184 ) ;
if ( V_50 )
break;
}
if ( V_10 -> V_184 == 0 )
F_74 ( V_10 -> V_190 ) ;
V_204 -> V_205 = V_10 -> V_184 ;
V_139:
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_77 ( struct V_173 * V_174 , void * V_181 ,
struct V_208 * V_189 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
int V_50 = - V_51 ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_189 -> V_187 >= V_10 -> V_184 )
goto V_139;
* V_189 = V_10 -> V_190 [ V_189 -> V_187 ] . V_192 ;
V_50 = 0 ;
V_139:
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_78 ( struct V_173 * V_174 , void * V_181 ,
struct V_208 * V_189 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
struct V_188 * V_209 ;
int V_50 = - V_51 ;
unsigned long V_13 ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_189 -> V_187 >= V_10 -> V_184 )
goto V_139;
V_209 = V_10 -> V_190 + V_189 -> V_187 ;
if ( V_209 -> V_192 . V_13 & V_210 ) {
V_50 = 0 ;
goto V_139;
}
if ( V_209 -> V_192 . V_13 & V_211 ) {
V_50 = - V_179 ;
goto V_139;
}
V_209 -> V_192 . V_13 |= V_210 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_79 ( & V_209 -> V_191 , & V_10 -> V_201 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
V_50 = 0 ;
V_139:
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_80 ( struct V_173 * V_174 , void * V_181 ,
struct V_208 * V_189 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
struct V_188 * V_209 ;
int V_50 = - V_51 ;
unsigned long V_13 ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_121 != V_186 )
goto V_177;
if ( F_81 ( & V_10 -> V_202 ) && V_174 -> V_212 & V_213 ) {
V_50 = - V_214 ;
goto V_177;
}
while ( F_81 ( & V_10 -> V_202 ) && V_10 -> V_121 == V_186 ) {
F_54 ( & V_10 -> V_137 ) ;
if ( F_82 ( V_10 -> V_118 ,
! F_81 ( & V_10 -> V_202 ) ) ) {
V_50 = - V_215 ;
goto V_139;
}
F_52 ( & V_10 -> V_137 ) ;
}
if ( V_10 -> V_121 != V_186 )
V_50 = - V_216 ;
else {
F_19 ( & V_10 -> V_23 , V_13 ) ;
V_209 = F_83 ( V_10 -> V_202 . V_217 ,
struct V_188 , V_191 ) ;
F_84 ( & V_209 -> V_191 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
V_209 -> V_192 . V_13 &= ~ V_211 ;
* V_189 = V_209 -> V_192 ;
V_50 = 0 ;
}
V_177:
F_54 ( & V_10 -> V_137 ) ;
V_139:
return V_50 ;
}
static void F_85 ( struct V_218 * V_219 )
{
struct V_188 * V_209 = V_219 -> V_220 ;
V_209 -> V_194 ++ ;
}
static void F_86 ( struct V_218 * V_219 )
{
struct V_188 * V_209 = V_219 -> V_220 ;
F_52 ( & V_209 -> V_10 -> V_137 ) ;
V_209 -> V_194 -- ;
if ( V_209 -> V_194 == 0 )
V_209 -> V_192 . V_13 &= ~ V_221 ;
F_54 ( & V_209 -> V_10 -> V_137 ) ;
}
static int F_87 ( struct V_173 * V_174 , struct V_218 * V_219 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
unsigned long V_200 = V_219 -> V_222 << V_223 ;
int V_50 = - V_51 ;
int V_7 ;
struct V_188 * V_209 = NULL ;
if ( ! ( V_219 -> V_224 & V_225 ) || ! ( V_219 -> V_224 & V_226 ) )
return - V_51 ;
F_52 ( & V_10 -> V_137 ) ;
for ( V_7 = 0 ; V_7 < V_10 -> V_184 ; V_7 ++ )
if ( V_10 -> V_190 [ V_7 ] . V_192 . V_199 . V_200 == V_200 ) {
V_209 = V_10 -> V_190 + V_7 ;
break;
}
if ( V_209 == NULL )
goto V_139;
V_50 = F_88 ( V_219 , V_209 -> V_167 , 0 ) ;
if ( V_50 )
goto V_139;
V_219 -> V_224 |= V_227 ;
V_219 -> V_220 = V_209 ;
V_219 -> V_228 = & V_229 ;
V_209 -> V_192 . V_13 |= V_221 ;
F_85 ( V_219 ) ;
V_50 = 0 ;
V_139:
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_89 ( struct V_173 * V_174 )
{
struct V_1 * V_10 = F_90 ( V_174 ) ;
V_174 -> V_175 = V_10 ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_230 == 0 ) {
F_47 ( V_10 ) ;
F_49 ( V_10 ) ;
F_8 ( V_10 , 1 ) ;
}
( V_10 -> V_230 ) ++ ;
F_54 ( & V_10 -> V_137 ) ;
return 0 ;
}
static int F_91 ( struct V_173 * V_174 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
F_52 ( & V_10 -> V_137 ) ;
( V_10 -> V_230 ) -- ;
if ( V_174 == V_10 -> V_61 ) {
F_46 ( V_10 ) ;
F_72 ( V_10 ) ;
V_10 -> V_61 = NULL ;
}
if ( V_10 -> V_230 == 0 ) {
F_48 ( V_10 ) ;
if ( V_231 )
F_61 ( V_10 ) ;
}
F_54 ( & V_10 -> V_137 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_173 * V_174 ,
struct V_232 * V_233 )
{
struct V_1 * V_10 = V_174 -> V_175 ;
F_93 ( V_174 , & V_10 -> V_118 , V_233 ) ;
if ( V_10 -> V_11 >= 0 )
return V_234 | V_235 ;
return 0 ;
}
static int F_94 ( struct V_173 * V_174 , void * V_181 ,
struct V_236 * V_237 )
{
struct V_1 * V_10 = V_181 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_133 , V_238 , V_237 ) ;
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_95 ( struct V_173 * V_174 , void * V_181 ,
struct V_148 * V_149 )
{
struct V_1 * V_10 = V_181 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_133 , V_239 , V_149 ) ;
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_96 ( struct V_173 * V_174 , void * V_181 ,
struct V_148 * V_149 )
{
struct V_1 * V_10 = V_181 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_133 , V_153 , V_149 ) ;
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_97 ( struct V_173 * V_173 , void * V_181 ,
struct V_240 * V_241 )
{
strcpy ( V_241 -> V_242 , L_6 ) ;
strcpy ( V_241 -> V_243 , L_6 ) ;
V_241 -> V_244 = V_245 ;
V_241 -> V_246 = V_247 |
V_248 | V_249 ;
return 0 ;
}
static int F_98 ( struct V_173 * V_174 ,
void * V_181 , struct V_250 * V_78 )
{
if ( V_78 -> V_187 >= V_8 )
return - V_51 ;
F_99 ( V_78 -> V_251 , V_9 [ V_78 -> V_187 ] . V_252 ,
sizeof( V_78 -> V_251 ) ) ;
V_78 -> V_6 = V_9 [ V_78 -> V_187 ] . V_6 ;
return 0 ;
}
static int F_100 ( struct V_173 * V_174 , void * V_181 ,
struct V_253 * V_78 )
{
struct V_1 * V_10 = V_181 ;
struct V_5 * V_254 ;
struct V_77 * V_255 = & V_78 -> V_78 . V_255 ;
struct V_154 V_155 ;
int V_50 ;
V_254 = F_3 ( V_255 -> V_6 ) ;
V_255 -> V_6 = V_254 -> V_6 ;
F_57 ( & V_155 , V_255 , V_254 -> V_156 ) ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_158 , V_256 , & V_155 ) ;
F_54 ( & V_10 -> V_137 ) ;
F_101 ( V_255 , & V_155 ) ;
V_255 -> V_83 = V_255 -> V_257 * V_254 -> V_258 ;
V_255 -> V_162 = V_255 -> V_80 * V_255 -> V_83 ;
return V_50 ;
}
static int F_102 ( struct V_173 * V_174 , void * V_181 ,
struct V_253 * V_78 )
{
struct V_1 * V_10 = V_181 ;
struct V_5 * V_254 ;
int V_50 ;
if ( V_10 -> V_121 != V_122 || V_10 -> V_184 > 0 )
return - V_179 ;
V_254 = F_3 ( V_78 -> V_78 . V_255 . V_6 ) ;
V_50 = F_100 ( V_174 , V_181 , V_78 ) ;
if ( V_50 )
return V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_10 -> V_79 = V_78 -> V_78 . V_255 ;
V_10 -> V_156 = V_254 -> V_156 ;
V_50 = - V_166 ;
if ( V_10 -> V_12 > 0 && V_10 -> V_161 < V_10 -> V_79 . V_162 )
F_61 ( V_10 ) ;
if ( V_10 -> V_12 == 0 ) {
if ( F_58 ( V_10 , 0 ) )
goto V_139;
}
V_50 = F_56 ( V_10 ) ;
if ( ! V_50 )
V_50 = F_39 ( V_10 ) ;
V_139:
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_103 ( struct V_173 * V_174 , void * V_181 ,
struct V_253 * V_254 )
{
struct V_1 * V_10 = V_181 ;
V_254 -> V_78 . V_255 = V_10 -> V_79 ;
return 0 ;
}
static int F_104 ( struct V_173 * V_174 , void * V_181 ,
struct V_259 * V_260 )
{
if ( V_260 -> V_187 != 0 )
return - V_51 ;
V_260 -> type = V_261 ;
V_260 -> V_262 = V_263 ;
strcpy ( V_260 -> V_65 , L_17 ) ;
return 0 ;
}
static int F_105 ( struct V_173 * V_174 , void * V_181 , unsigned int * V_7 )
{
* V_7 = 0 ;
return 0 ;
}
static int F_106 ( struct V_173 * V_174 , void * V_181 , unsigned int V_7 )
{
if ( V_7 != 0 )
return - V_51 ;
return 0 ;
}
static int F_107 ( struct V_173 * V_174 , void * V_181 , T_8 * V_264 )
{
return 0 ;
}
static int F_108 ( struct V_173 * V_174 , void * V_181 ,
struct V_265 * V_266 )
{
struct V_1 * V_10 = V_181 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_158 , V_267 , V_266 ) ;
F_54 ( & V_10 -> V_137 ) ;
V_266 -> V_268 . V_269 . V_270 = V_163 ;
return V_50 ;
}
static int F_109 ( struct V_173 * V_174 , void * V_181 ,
struct V_265 * V_266 )
{
struct V_1 * V_10 = V_181 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_158 , V_271 , V_266 ) ;
F_54 ( & V_10 -> V_137 ) ;
V_266 -> V_268 . V_269 . V_270 = V_163 ;
return V_50 ;
}
static int F_110 ( struct V_173 * V_173 , void * V_181 ,
struct V_135 * V_136 )
{
struct V_1 * V_10 = V_181 ;
V_136 -> V_140 = V_141 ;
V_136 -> V_272 = 0 ;
if ( F_111 ( & V_136 -> V_142 ) ) {
V_136 -> V_140 = V_273 ;
return 0 ;
}
return F_50 ( V_10 , V_133 , V_145 , V_136 ) ;
}
static int F_112 ( struct V_173 * V_174 , void * V_181 ,
struct V_274 * V_275 )
{
struct V_1 * V_10 = V_181 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_158 , V_276 , V_275 ) ;
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_113 ( struct V_173 * V_174 , void * V_181 ,
struct V_277 * V_278 )
{
struct V_1 * V_10 = V_181 ;
int V_50 ;
F_52 ( & V_10 -> V_137 ) ;
V_50 = F_50 ( V_10 , V_158 , V_279 , V_278 ) ;
F_54 ( & V_10 -> V_137 ) ;
return V_50 ;
}
static int F_114 ( struct V_173 * V_173 , void * V_181 ,
struct V_280 * V_17 )
{
struct V_1 * V_10 = V_181 ;
if ( F_111 ( & V_17 -> V_142 ) ) {
V_17 -> V_18 = F_12 ( V_10 , V_17 -> V_17 ) ;
V_17 -> V_47 = 4 ;
return 0 ;
}
return F_50 ( V_10 , V_133 , V_281 , V_17 ) ;
}
static int F_115 ( struct V_173 * V_173 , void * V_181 ,
struct V_280 * V_17 )
{
struct V_1 * V_10 = V_181 ;
if ( F_111 ( & V_17 -> V_142 ) ) {
F_10 ( V_10 , V_17 -> V_17 , V_17 -> V_18 ) ;
return 0 ;
}
return F_50 ( V_10 , V_133 , V_282 , V_17 ) ;
}
static void F_116 ( unsigned long V_49 )
{
struct V_1 * V_10 = (struct V_1 * ) V_49 ;
int V_7 ;
unsigned long V_13 ;
struct V_188 * V_209 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
for ( V_7 = 0 ; V_7 < V_10 -> V_12 ; V_7 ++ ) {
int V_170 = V_10 -> V_11 ;
if ( V_170 < 0 ) {
F_24 ( V_10 , L_18 ) ;
break;
}
if ( ++ ( V_10 -> V_11 ) >= V_10 -> V_12 )
V_10 -> V_11 = 0 ;
if ( ! F_7 ( V_170 , & V_10 -> V_13 ) )
continue;
if ( F_81 ( & V_10 -> V_201 ) )
break;
F_5 ( V_170 , & V_10 -> V_13 ) ;
V_209 = F_83 ( V_10 -> V_201 . V_217 ,
struct V_188 , V_191 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
memcpy ( V_209 -> V_167 , V_10 -> V_164 [ V_170 ] ,
V_10 -> V_79 . V_162 ) ;
V_209 -> V_192 . V_283 = V_10 -> V_79 . V_162 ;
V_209 -> V_192 . V_185 = V_10 -> V_284 [ V_170 ] ;
V_209 -> V_192 . V_13 &= ~ V_210 ;
V_209 -> V_192 . V_13 |= V_211 ;
F_19 ( & V_10 -> V_23 , V_13 ) ;
F_117 ( & V_209 -> V_191 , & V_10 -> V_202 ) ;
}
if ( ! F_81 ( & V_10 -> V_202 ) )
F_118 ( & V_10 -> V_118 ) ;
F_20 ( & V_10 -> V_23 , V_13 ) ;
}
static void F_119 ( struct V_1 * V_10 , int V_285 )
{
if ( F_7 ( V_285 , & V_10 -> V_13 ) && F_120 () )
F_24 ( V_10 , L_19 , V_285 ) ;
F_9 ( V_285 , & V_10 -> V_13 ) ;
F_5 ( V_119 , & V_10 -> V_13 ) ;
if ( V_10 -> V_11 < 0 )
V_10 -> V_11 = V_285 ;
V_10 -> V_284 [ V_285 ] = ++ ( V_10 -> V_185 ) ;
switch ( V_10 -> V_121 ) {
case V_180 :
V_10 -> V_121 = V_176 ;
V_10 -> V_14 = 0 ;
F_118 ( & V_10 -> V_118 ) ;
break;
case V_176 :
if ( ++ ( V_10 -> V_14 ) >= V_10 -> V_12 ) {
F_43 ( V_10 ) ;
F_41 ( V_10 ) ;
V_10 -> V_121 = V_122 ;
}
F_118 ( & V_10 -> V_118 ) ;
break;
case V_186 :
F_121 ( & V_10 -> V_286 ) ;
break;
default:
F_24 ( V_10 , L_20 ) ;
break;
}
}
static void F_122 ( struct V_1 * V_10 , unsigned int V_287 )
{
unsigned int V_285 ;
F_10 ( V_10 , V_104 , V_105 ) ;
for ( V_285 = 0 ; V_285 < V_10 -> V_12 ; V_285 ++ )
if ( V_287 & ( V_288 << V_285 ) )
F_119 ( V_10 , V_285 ) ;
if ( V_287 & ( V_289 | V_290 | V_291 ) )
F_9 ( V_119 , & V_10 -> V_13 ) ;
}
static T_9 F_123 ( int V_292 , void * V_49 )
{
struct V_1 * V_10 = V_49 ;
unsigned int V_287 ;
F_124 ( & V_10 -> V_23 ) ;
V_287 = F_12 ( V_10 , V_104 ) ;
if ( ( V_287 & V_293 ) == 0 ) {
F_125 ( & V_10 -> V_23 ) ;
return V_294 ;
}
if ( V_287 & V_105 )
F_122 ( V_10 , V_287 ) ;
if ( V_287 & V_57 ) {
F_10 ( V_10 , V_104 , V_57 ) ;
F_118 ( & V_10 -> V_39 ) ;
}
F_125 ( & V_10 -> V_23 ) ;
return V_295 ;
}
static int F_126 ( struct V_296 * V_67 ,
const struct V_297 * V_150 )
{
int V_50 ;
struct V_1 * V_10 ;
struct V_298 V_299 = {
. V_300 = true ,
. V_301 = 320 ,
. V_302 = 240 ,
} ;
struct V_303 V_304 = {
. type = L_21 ,
. V_27 = 0x42 ,
. V_305 = & V_299 ,
} ;
V_50 = - V_166 ;
V_10 = F_76 ( sizeof( struct V_1 ) , V_165 ) ;
if ( V_10 == NULL )
goto V_139;
V_50 = F_127 ( & V_67 -> V_3 , & V_10 -> V_4 ) ;
if ( V_50 )
goto V_306;
F_128 ( & V_10 -> V_137 ) ;
F_129 ( & V_10 -> V_23 ) ;
V_10 -> V_121 = V_138 ;
F_8 ( V_10 , 1 ) ;
F_130 ( & V_10 -> V_39 ) ;
F_130 ( & V_10 -> V_118 ) ;
V_10 -> V_67 = V_67 ;
V_10 -> V_79 = V_307 ;
V_10 -> V_156 = V_308 ;
F_69 ( & V_10 -> V_309 ) ;
F_69 ( & V_10 -> V_201 ) ;
F_69 ( & V_10 -> V_202 ) ;
F_131 ( & V_10 -> V_286 , F_116 , ( unsigned long ) V_10 ) ;
V_50 = F_132 ( V_67 ) ;
if ( V_50 )
goto V_310;
F_133 ( V_67 ) ;
V_50 = - V_41 ;
V_10 -> V_19 = F_134 ( V_67 , 0 , 0 ) ;
if ( ! V_10 -> V_19 ) {
F_34 ( V_68 L_22 ) ;
goto V_310;
}
V_50 = F_135 ( V_67 -> V_292 , F_123 , V_311 , L_23 , V_10 ) ;
if ( V_50 )
goto V_312;
F_44 ( V_10 ) ;
F_47 ( V_10 ) ;
V_50 = F_31 ( V_10 ) ;
if ( V_50 )
goto V_313;
if ( F_136 ( V_314 ) )
V_299 . V_315 = 45 ;
V_10 -> V_144 = V_304 . V_27 ;
V_10 -> V_316 = F_137 ( & V_10 -> V_4 , & V_10 -> V_44 ,
& V_304 , NULL ) ;
if ( V_10 -> V_316 == NULL ) {
V_50 = - V_317 ;
goto V_318;
}
V_50 = F_51 ( V_10 ) ;
if ( V_50 )
goto V_318;
F_52 ( & V_10 -> V_137 ) ;
V_10 -> V_319 = V_320 ;
V_10 -> V_319 . V_321 = 0 ;
V_10 -> V_319 . V_4 = & V_10 -> V_4 ;
V_50 = F_138 ( & V_10 -> V_319 , V_322 , - 1 ) ;
if ( V_50 )
goto V_177;
F_139 ( & V_10 -> V_319 , V_10 ) ;
if ( ! V_231 ) {
if ( F_58 ( V_10 , 1 ) )
F_53 ( V_10 , L_24
L_25 ) ;
}
F_54 ( & V_10 -> V_137 ) ;
return 0 ;
V_177:
F_54 ( & V_10 -> V_137 ) ;
V_318:
F_35 ( V_10 ) ;
V_313:
F_48 ( V_10 ) ;
F_140 ( V_67 -> V_292 , V_10 ) ;
V_312:
F_141 ( V_67 , V_10 -> V_19 ) ;
V_306:
F_142 ( & V_10 -> V_4 ) ;
V_310:
F_74 ( V_10 ) ;
V_139:
return V_50 ;
}
static void F_143 ( struct V_1 * V_10 )
{
if ( V_10 -> V_184 > 0 )
F_72 ( V_10 ) ;
F_46 ( V_10 ) ;
F_48 ( V_10 ) ;
F_35 ( V_10 ) ;
F_61 ( V_10 ) ;
F_140 ( V_10 -> V_67 -> V_292 , V_10 ) ;
F_141 ( V_10 -> V_67 , V_10 -> V_19 ) ;
F_144 ( & V_10 -> V_319 ) ;
}
static void F_145 ( struct V_296 * V_67 )
{
struct V_2 * V_4 = F_146 ( & V_67 -> V_3 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
if ( V_10 == NULL ) {
F_34 ( V_323 L_26 , V_67 ) ;
return;
}
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_230 > 0 )
F_53 ( V_10 , L_27 ) ;
F_143 ( V_10 ) ;
F_142 ( & V_10 -> V_4 ) ;
F_74 ( V_10 ) ;
}
static int F_147 ( struct V_296 * V_67 , T_10 V_121 )
{
struct V_2 * V_4 = F_146 ( & V_67 -> V_3 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_50 ;
enum V_172 V_324 ;
V_50 = F_148 ( V_67 ) ;
if ( V_50 )
return V_50 ;
V_324 = V_10 -> V_121 ;
F_46 ( V_10 ) ;
F_48 ( V_10 ) ;
F_149 ( V_67 ) ;
V_10 -> V_121 = V_324 ;
return 0 ;
}
static int F_150 ( struct V_296 * V_67 )
{
struct V_2 * V_4 = F_146 ( & V_67 -> V_3 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
int V_50 = 0 ;
F_151 ( V_67 ) ;
V_50 = F_132 ( V_67 ) ;
if ( V_50 ) {
F_53 ( V_10 , L_28 ) ;
return V_50 ;
}
F_44 ( V_10 ) ;
F_52 ( & V_10 -> V_137 ) ;
if ( V_10 -> V_230 > 0 ) {
F_47 ( V_10 ) ;
F_49 ( V_10 ) ;
} else {
F_48 ( V_10 ) ;
}
F_54 ( & V_10 -> V_137 ) ;
F_9 ( V_15 , & V_10 -> V_13 ) ;
if ( V_10 -> V_121 == V_176 )
V_10 -> V_121 = V_122 ;
else if ( V_10 -> V_121 == V_180 || V_10 -> V_121 == V_186 )
V_50 = F_64 ( V_10 , V_10 -> V_121 ) ;
return V_50 ;
}
static int T_11 F_152 ( void )
{
int V_50 ;
F_34 ( V_325 L_29 ,
V_245 ) ;
V_50 = F_153 ( & V_326 ) ;
if ( V_50 ) {
F_34 ( V_68 L_30 ) ;
goto V_139;
}
V_50 = 0 ;
V_139:
return V_50 ;
}
static void T_12 F_154 ( void )
{
F_155 ( & V_326 ) ;
}
