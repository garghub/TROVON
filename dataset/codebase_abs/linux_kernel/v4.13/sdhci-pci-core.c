static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = V_2 -> V_8 [ V_3 ] ;
struct V_9 * V_10 ;
if ( ! V_7 )
continue;
V_10 = V_7 -> V_10 ;
if ( V_2 -> V_11 && V_10 -> V_12 != V_13 )
F_2 ( V_10 -> V_14 ) ;
V_4 = F_3 ( V_10 ) ;
if ( V_4 )
goto V_15;
if ( V_10 -> V_14 -> V_16 & V_17 )
F_4 ( V_10 ) ;
}
return 0 ;
V_15:
while ( -- V_3 >= 0 )
F_5 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_16 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
struct V_6 * V_7 = V_2 -> V_8 [ V_3 ] ;
if ( V_7 )
V_16 |= V_7 -> V_10 -> V_14 -> V_16 ;
}
return F_7 ( & V_2 -> V_18 -> V_19 ,
( V_16 & V_20 ) &&
( V_16 & V_17 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_6 ( V_2 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_7 = V_2 -> V_8 [ V_3 ] ;
if ( ! V_7 )
continue;
V_4 = F_5 ( V_7 -> V_10 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_7 = V_2 -> V_8 [ V_3 ] ;
if ( ! V_7 )
continue;
V_10 = V_7 -> V_10 ;
V_4 = F_11 ( V_10 ) ;
if ( V_4 )
goto V_21;
if ( V_2 -> V_22 &&
V_10 -> V_12 != V_13 )
F_2 ( V_10 -> V_14 ) ;
}
return 0 ;
V_21:
while ( -- V_3 >= 0 )
F_12 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_7 = V_2 -> V_8 [ V_3 ] ;
if ( ! V_7 )
continue;
V_4 = F_12 ( V_7 -> V_10 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 -> V_23 == V_24 ||
V_2 -> V_18 -> V_23 == V_25 )
V_2 -> V_26 |= V_27 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_28 =
( ( 0x21 << V_29 )
& V_30 ) |
( ( 0x21 << V_31 )
& V_32 ) |
V_33 |
V_34 |
V_35 |
V_36 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( 500 ) ;
return F_9 ( V_2 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_28 |= V_37 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
V_2 -> V_5 = 1 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_28 |= V_37 ;
return 0 ;
}
static T_2 F_21 ( int V_38 , void * V_39 )
{
struct V_6 * V_7 = V_39 ;
struct V_9 * V_10 = V_7 -> V_10 ;
F_22 ( V_10 -> V_14 , F_23 ( 200 ) ) ;
return V_40 ;
}
static void F_24 ( struct V_6 * V_7 )
{
int V_41 , V_38 , V_42 = V_7 -> V_43 ;
V_7 -> V_43 = - V_44 ;
V_7 -> V_45 = - V_44 ;
if ( ! F_25 ( V_42 ) )
return;
V_41 = F_26 ( & V_7 -> V_2 -> V_18 -> V_19 , V_42 , L_1 ) ;
if ( V_41 < 0 )
goto V_46;
V_41 = F_27 ( V_42 ) ;
if ( V_41 < 0 )
goto V_47;
V_38 = F_28 ( V_42 ) ;
if ( V_38 < 0 )
goto V_47;
V_41 = F_29 ( V_38 , F_21 , V_48 |
V_49 , L_1 , V_7 ) ;
if ( V_41 )
goto V_47;
V_7 -> V_43 = V_42 ;
V_7 -> V_45 = V_38 ;
return;
V_47:
F_30 ( & V_7 -> V_2 -> V_18 -> V_19 , V_42 ) ;
V_46:
F_31 ( & V_7 -> V_2 -> V_18 -> V_19 , L_2 ) ;
}
static void F_32 ( struct V_6 * V_7 )
{
if ( V_7 -> V_45 >= 0 )
F_33 ( V_7 -> V_45 , V_7 ) ;
}
static inline void F_24 ( struct V_6 * V_7 )
{
}
static inline void F_32 ( struct V_6 * V_7 )
{
}
static int F_34 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_28 |= V_37 | V_50 ;
V_7 -> V_10 -> V_14 -> V_51 |= V_52 ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_28 |= V_53 | V_50 ;
return 0 ;
}
static int F_36 ( struct V_54 * V_54 , struct V_55 * V_19 ,
unsigned int V_56 , T_3 * V_57 )
{
union V_58 * V_59 ;
int V_41 = 0 ;
T_4 V_60 ;
V_59 = F_37 ( F_38 ( V_19 ) , & V_61 , 0 , V_56 , NULL ) ;
if ( ! V_59 )
return - V_62 ;
if ( V_59 -> type != V_63 || V_59 -> V_64 . V_65 < 1 ) {
V_41 = - V_44 ;
goto V_46;
}
V_60 = F_39 ( T_4 , V_59 -> V_64 . V_65 , 4 ) ;
* V_57 = 0 ;
memcpy ( V_57 , V_59 -> V_64 . V_66 , V_60 ) ;
V_46:
F_40 ( V_59 ) ;
return V_41 ;
}
static int F_41 ( struct V_54 * V_54 , struct V_55 * V_19 ,
unsigned int V_56 , T_3 * V_57 )
{
if ( V_56 > 31 || ! ( V_54 -> V_67 & ( 1 << V_56 ) ) )
return - V_62 ;
return F_36 ( V_54 , V_19 , V_56 , V_57 ) ;
}
static void F_42 ( struct V_54 * V_54 , struct V_55 * V_19 ,
struct V_68 * V_14 )
{
int V_41 ;
T_3 V_69 ;
V_41 = F_36 ( V_54 , V_19 , V_70 , & V_54 -> V_67 ) ;
if ( V_41 ) {
F_43 ( L_3 ,
F_44 ( V_14 ) , V_41 ) ;
return;
}
F_43 ( L_4 ,
F_44 ( V_14 ) , V_54 -> V_67 ) ;
V_41 = F_41 ( V_54 , V_19 , V_71 , & V_69 ) ;
V_54 -> V_72 = V_41 ? 0 : V_69 ;
V_41 = F_41 ( V_54 , V_19 , V_73 , & V_69 ) ;
V_54 -> V_74 = V_41 ? true : ! ! V_69 ;
}
static void F_45 ( struct V_9 * V_10 )
{
T_5 V_75 ;
V_75 = F_46 ( V_10 , V_76 ) ;
V_75 |= 0x10 ;
F_47 ( V_10 , V_75 , V_76 ) ;
F_48 ( 9 ) ;
V_75 &= ~ 0x10 ;
F_47 ( V_10 , V_75 , V_76 ) ;
F_49 ( 300 , 1000 ) ;
}
static int F_50 ( struct V_77 * V_78 ,
unsigned int V_79 , int V_80 ,
int V_81 , int * V_82 )
{
struct V_9 * V_10 = F_51 ( V_78 -> V_10 ) ;
struct V_6 * V_7 = F_52 ( V_10 ) ;
struct V_54 * V_54 = F_53 ( V_7 ) ;
return V_54 -> V_72 ;
}
static int F_54 ( struct V_68 * V_14 )
{
int V_83 = F_55 ( V_14 ) ;
struct V_9 * V_10 = F_51 ( V_14 ) ;
unsigned long V_84 ;
int V_4 = 0 ;
if ( ! V_83 )
return 0 ;
F_56 ( & V_10 -> V_85 , V_84 ) ;
if ( V_10 -> V_84 & V_86 )
goto V_46;
V_4 = ! ! ( F_57 ( V_10 , V_87 ) & V_88 ) ;
V_46:
F_58 ( & V_10 -> V_85 , V_84 ) ;
return V_4 ;
}
static void F_59 ( struct V_9 * V_10 , unsigned char V_89 ,
unsigned short V_90 )
{
int V_91 ;
T_5 V_75 ;
F_60 ( V_10 , V_89 , V_90 ) ;
if ( V_89 == V_92 )
return;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
V_75 = F_46 ( V_10 , V_76 ) ;
if ( V_75 & V_94 )
break;
F_48 ( V_95 ) ;
V_75 |= V_94 ;
F_47 ( V_10 , V_75 , V_76 ) ;
}
}
static void F_61 ( struct V_68 * V_14 ,
struct V_96 * V_97 )
{
struct V_9 * V_10 = F_51 ( V_14 ) ;
T_3 V_69 ;
V_69 = F_57 ( V_10 , V_98 ) ;
if ( V_97 -> V_99 )
V_69 |= V_100 ;
else
V_69 &= ~ V_100 ;
F_62 ( V_10 , V_69 , V_98 ) ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_54 * V_54 = F_53 ( V_7 ) ;
struct V_55 * V_19 = & V_7 -> V_2 -> V_18 -> V_19 ;
struct V_68 * V_14 = V_7 -> V_10 -> V_14 ;
F_42 ( V_54 , V_19 , V_14 ) ;
V_7 -> V_2 -> V_22 = V_54 -> V_74 ;
}
static int F_64 ( struct V_6 * V_7 )
{
F_63 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_37 | V_50 |
V_101 | V_102 |
V_103 |
V_104 ;
V_7 -> V_105 = F_45 ;
if ( V_7 -> V_2 -> V_18 -> V_55 == V_106 )
V_7 -> V_10 -> V_107 = 1000 ;
V_7 -> V_10 -> V_108 . V_109 =
F_50 ;
return 0 ;
}
static int F_65 ( struct V_6 * V_7 )
{
int V_4 = F_64 ( V_7 ) ;
if ( V_7 -> V_2 -> V_18 -> V_55 != V_110 ) {
V_7 -> V_10 -> V_14 -> V_51 |= V_111 ,
V_7 -> V_10 -> V_108 . V_112 =
F_61 ;
}
return V_4 ;
}
static int F_66 ( struct V_6 * V_7 )
{
T_6 V_113 ;
unsigned long long V_114 ;
V_113 = F_67 ( F_38 ( & V_7 -> V_2 -> V_18 -> V_19 ) ,
L_5 , NULL , & V_114 ) ;
if ( F_68 ( V_113 ) ) {
F_69 ( & V_7 -> V_2 -> V_18 -> V_19 ,
L_6 ) ;
return - V_44 ;
}
V_7 -> V_10 -> V_14 -> V_115 = V_114 * 1000000 ;
return 0 ;
}
static inline int F_66 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_70 ( struct V_6 * V_7 )
{
int V_41 ;
F_63 ( V_7 ) ;
V_41 = F_66 ( V_7 ) ;
if ( V_41 )
return V_41 ;
V_7 -> V_10 -> V_14 -> V_28 |= V_53 | V_50 |
V_104 ;
return 0 ;
}
static int F_71 ( struct V_6 * V_7 )
{
F_63 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_53 | V_50 |
V_104 ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 )
{
F_63 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_104 |
V_116 | V_117 ;
V_7 -> V_118 = 0 ;
V_7 -> V_119 = true ;
if ( V_7 -> V_2 -> V_18 -> V_55 == V_120 ||
V_7 -> V_2 -> V_18 -> V_55 == V_121 ||
V_7 -> V_2 -> V_18 -> V_55 == V_122 ||
V_7 -> V_2 -> V_18 -> V_55 == V_123 )
V_7 -> V_10 -> V_108 . V_124 = F_54 ;
return 0 ;
}
static int F_73 ( struct V_6 * V_7 )
{
unsigned int V_125 = F_74 ( V_7 -> V_2 -> V_18 -> V_126 ) ;
switch ( V_125 ) {
case V_127 :
case V_128 :
V_7 -> V_10 -> V_14 -> V_28 |= V_50 |
V_37 |
V_102 ;
break;
case V_129 :
V_7 -> V_10 -> V_130 |= V_131 ;
break;
case V_132 :
V_7 -> V_10 -> V_14 -> V_28 |= V_50 |
V_53 ;
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , int V_134 )
{
T_5 V_135 ;
int V_4 ;
V_4 = F_76 ( V_2 -> V_18 , 0xAE , & V_135 ) ;
if ( V_4 )
return V_4 ;
if ( V_134 )
V_135 |= 0x47 ;
else
V_135 &= ~ 0x47 ;
return F_77 ( V_2 -> V_18 , 0xAE , V_135 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_4 ;
T_7 V_136 = 0 ;
if ( V_2 -> V_18 -> V_137 == 0 ) {
V_2 -> V_26 |= V_138 |
V_139 |
V_140 |
V_141 |
V_142 ;
}
if ( V_2 -> V_18 -> V_55 == V_143 )
V_136 = V_144 ;
else if ( V_2 -> V_18 -> V_55 == V_145 )
V_136 = V_146 ;
if ( V_136 ) {
struct V_147 * V_148 ;
V_148 = NULL ;
while ( ( V_148 = F_79 ( V_149 ,
V_136 , V_148 ) ) != NULL ) {
if ( ( F_80 ( V_2 -> V_18 -> V_126 ) ==
F_80 ( V_148 -> V_126 ) ) &&
( V_2 -> V_18 -> V_150 == V_148 -> V_150 ) )
break;
}
if ( V_148 ) {
F_81 ( V_148 ) ;
F_82 ( & V_2 -> V_18 -> V_19 , L_7
L_8 ) ;
return - V_133 ;
}
}
V_4 = F_75 ( V_2 , 1 ) ;
if ( V_4 ) {
F_69 ( & V_2 -> V_18 -> V_19 , L_9 ) ;
return V_4 ;
}
if ( V_2 -> V_18 -> V_55 == V_145 ||
V_2 -> V_18 -> V_55 == V_146 )
V_2 -> V_26 |= V_151 ;
return 0 ;
}
static void F_83 ( struct V_9 * V_10 , int V_134 )
{
T_5 V_135 ;
V_135 = F_84 ( V_10 -> V_152 + 0xC0 ) ;
if ( V_134 )
V_135 |= 0x01 ;
else
V_135 &= ~ 0x01 ;
F_85 ( V_135 , V_10 -> V_152 + 0xC0 ) ;
}
static int F_86 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 -> V_18 -> V_137 == 0 ) {
T_7 V_153 ;
V_153 = F_87 ( V_7 -> V_10 -> V_152 + V_154 ) ;
V_153 = ( V_153 & V_155 ) >>
V_156 ;
if ( V_153 < 0xAC )
V_7 -> V_10 -> V_26 |= V_157 ;
}
if ( V_7 -> V_2 -> V_18 -> V_55 == V_146 ) {
V_7 -> V_10 -> V_158 = V_159 | V_160 |
V_161 | V_162 |
V_163 ;
V_7 -> V_10 -> V_164 = V_159 | V_160 |
V_161 | V_162 ;
}
if ( V_7 -> V_2 -> V_18 -> V_55 == V_144 ||
V_7 -> V_2 -> V_18 -> V_55 == V_146 )
F_83 ( V_7 -> V_10 , 1 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_165 ;
return 0 ;
}
static void F_88 ( struct V_6 * V_7 , int V_166 )
{
if ( V_166 )
return;
if ( V_7 -> V_2 -> V_18 -> V_55 == V_144 ||
V_7 -> V_2 -> V_18 -> V_55 == V_146 )
F_83 ( V_7 -> V_10 , 0 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_18 -> V_55 == V_144 ||
V_2 -> V_18 -> V_55 == V_146 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_83 ( V_2 -> V_8 [ V_3 ] -> V_10 , 0 ) ;
}
F_6 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
int V_4 , V_3 ;
if ( V_2 -> V_18 -> V_55 == V_144 ||
V_2 -> V_18 -> V_55 == V_146 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_83 ( V_2 -> V_8 [ V_3 ] -> V_10 , 1 ) ;
}
V_4 = F_75 ( V_2 , 1 ) ;
if ( V_4 ) {
F_69 ( & V_2 -> V_18 -> V_19 , L_9 ) ;
return V_4 ;
}
return F_9 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 -> V_167 & 0x0000FF ) == V_168 ) {
V_2 -> V_18 -> V_167 &= ~ 0x0000FF ;
V_2 -> V_18 -> V_167 |= V_169 ;
}
return 0 ;
}
static int F_92 ( struct V_6 * V_7 )
{
int V_170 , V_171 ;
T_5 V_172 = F_84 ( V_7 -> V_10 -> V_152 + V_173 ) ;
T_5 V_174 = F_84 ( V_7 -> V_10 -> V_152 + V_175 ) ;
F_82 ( & V_7 -> V_2 -> V_18 -> V_19 , L_10
L_11 ,
V_172 >> 4 , V_172 & 0xf ,
V_174 >> 4 , V_174 & 0xf ) ;
if ( V_174 >= 0x20 )
V_7 -> V_10 -> V_26 |= V_176 ;
F_85 ( V_177 , V_7 -> V_10 -> V_152 + V_178 ) ;
F_85 ( V_179 , V_7 -> V_10 -> V_152 + V_180 ) ;
F_48 ( 50 ) ;
V_170 = 10 ;
do {
V_171 = F_93 ( V_7 -> V_10 -> V_152 + V_181 ) ;
if ( V_171 & V_182 )
break;
F_48 ( 100 ) ;
} while ( -- V_170 );
if ( ! V_170 ) {
F_69 ( & V_7 -> V_2 -> V_18 -> V_19 ,
L_12 ) ;
F_85 ( 0 , V_7 -> V_10 -> V_152 + V_180 ) ;
return - V_133 ;
}
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 -> V_137 == 0x10 )
V_2 -> V_26 |= V_183 ;
return 0 ;
}
static int F_95 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_51 |= V_184 ;
return 0 ;
}
static void F_96 ( struct V_9 * V_10 )
{
unsigned int V_69 ;
V_69 = F_97 ( V_10 , V_185 ) ;
V_69 |= V_186 | V_187 ;
F_98 ( V_10 , V_69 , V_185 ) ;
V_69 = F_97 ( V_10 , V_185 ) ;
V_69 &= ~ V_187 ;
F_98 ( V_10 , V_69 , V_185 ) ;
}
static void F_99 ( struct V_147 * V_18 , T_5 V_188 )
{
unsigned int V_69 ;
F_100 ( V_18 , V_189 , & V_69 ) ;
V_69 &= ~ V_190 ;
V_69 |= ( V_191 | ( V_188 << 1 ) ) ;
F_101 ( V_18 , V_189 , V_69 ) ;
}
static void F_102 ( struct V_147 * V_18 )
{
unsigned int V_69 ;
F_100 ( V_18 , V_192 , & V_69 ) ;
V_69 |= V_193 ;
F_101 ( V_18 , V_192 , V_69 ) ;
}
static int F_103 ( struct V_9 * V_10 , T_3 V_194 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
struct V_147 * V_18 = V_7 -> V_2 -> V_18 ;
T_5 V_195 = 0 ;
T_5 V_196 = 0 ;
T_5 V_197 = 0 ;
T_5 V_198 , V_199 ;
F_96 ( V_10 ) ;
for ( V_199 = 0 ; V_199 < 12 ; V_199 ++ ) {
F_99 ( V_18 , V_199 ) ;
if ( F_104 ( V_10 -> V_14 , V_194 , NULL ) ) {
V_195 = 0 ;
F_17 ( V_200 ) ;
V_198 = V_201 | V_202 ;
F_47 ( V_10 , V_198 , V_203 ) ;
} else if ( ++ V_195 > V_196 ) {
V_196 = V_195 ;
V_197 = V_199 ;
}
}
if ( ! V_196 ) {
F_69 ( & V_18 -> V_19 , L_13 ) ;
return - V_204 ;
}
F_99 ( V_18 , V_197 - V_196 / 2 ) ;
F_102 ( V_18 ) ;
V_10 -> V_14 -> V_205 = 0 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
struct V_147 * V_206 ;
enum V_207 V_208 ;
V_206 = F_79 ( V_209 ,
V_210 , NULL ) ;
if ( V_206 ) {
V_208 = V_211 ;
} else {
V_206 = F_79 ( V_209 ,
V_212 , NULL ) ;
if ( V_206 ) {
if ( V_206 -> V_137 < 0x51 )
V_208 = V_213 ;
else
V_208 = V_214 ;
} else {
V_208 = V_215 ;
}
}
if ( V_208 == V_211 || V_208 == V_213 )
V_2 -> V_130 |= V_216 ;
return 0 ;
}
static int F_106 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_147 * V_18 ;
V_7 = F_52 ( V_10 ) ;
V_18 = V_7 -> V_2 -> V_18 ;
if ( ( ( V_18 -> V_167 & 0xFFFF00 ) == ( V_217 << 8 ) ) &&
( ( V_18 -> V_167 & 0x0000FF ) != V_169 ) &&
( V_10 -> V_84 & V_218 ) ) {
F_31 ( & V_18 -> V_19 , L_14
L_15 ) ;
}
F_107 ( V_18 ) ;
return 0 ;
}
static void F_108 ( struct V_9 * V_10 , int V_219 )
{
T_5 V_198 ;
V_198 = F_46 ( V_10 , V_220 ) ;
switch ( V_219 ) {
case V_221 :
V_198 |= V_222 ;
V_198 &= ~ V_223 ;
break;
case V_224 :
V_198 |= V_223 ;
V_198 &= ~ V_222 ;
break;
default:
V_198 &= ~ ( V_222 | V_223 ) ;
break;
}
F_47 ( V_10 , V_198 , V_220 ) ;
}
static void F_109 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
int V_225 = V_7 -> V_225 ;
if ( ! F_25 ( V_225 ) )
return;
F_110 ( V_225 , 0 ) ;
F_48 ( 10 ) ;
F_110 ( V_225 , 1 ) ;
F_49 ( 300 , 1000 ) ;
}
static void F_111 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
if ( V_7 -> V_105 )
V_7 -> V_105 ( V_10 ) ;
}
static int F_112 ( struct V_55 * V_19 )
{
struct V_147 * V_18 = F_113 ( V_19 ) ;
struct V_1 * V_2 = F_114 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_227 )
return V_2 -> V_226 -> V_227 ( V_2 ) ;
return F_8 ( V_2 ) ;
}
static int F_115 ( struct V_55 * V_19 )
{
struct V_147 * V_18 = F_113 ( V_19 ) ;
struct V_1 * V_2 = F_114 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_228 )
return V_2 -> V_226 -> V_228 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_116 ( struct V_55 * V_19 )
{
struct V_147 * V_18 = F_113 ( V_19 ) ;
struct V_1 * V_2 = F_114 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_229 )
return V_2 -> V_226 -> V_229 ( V_2 ) ;
return F_10 ( V_2 ) ;
}
static int F_117 ( struct V_55 * V_19 )
{
struct V_147 * V_18 = F_113 ( V_19 ) ;
struct V_1 * V_2 = F_114 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_230 )
return V_2 -> V_226 -> V_230 ( V_2 ) ;
return F_13 ( V_2 ) ;
}
static struct V_6 * F_118 (
struct V_147 * V_18 , struct V_1 * V_2 , int V_231 ,
int V_232 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_4 , V_233 = V_231 + V_232 ;
T_4 V_234 = V_2 -> V_226 ? V_2 -> V_226 -> V_234 : 0 ;
if ( ! ( F_119 ( V_18 , V_233 ) & V_235 ) ) {
F_69 ( & V_18 -> V_19 , L_16 , V_233 ) ;
return F_120 ( - V_133 ) ;
}
if ( F_121 ( V_18 , V_233 ) < 0x100 ) {
F_69 ( & V_18 -> V_19 , L_17
L_18 ) ;
}
if ( ( V_18 -> V_167 & 0x0000FF ) == V_168 ) {
F_69 ( & V_18 -> V_19 , L_19 ) ;
return F_120 ( - V_133 ) ;
}
if ( ( V_18 -> V_167 & 0x0000FF ) > V_168 ) {
F_69 ( & V_18 -> V_19 , L_20 ) ;
return F_120 ( - V_133 ) ;
}
V_10 = F_122 ( & V_18 -> V_19 , sizeof( * V_7 ) + V_234 ) ;
if ( F_123 ( V_10 ) ) {
F_69 ( & V_18 -> V_19 , L_21 ) ;
return F_124 ( V_10 ) ;
}
V_7 = F_52 ( V_10 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_225 = - V_44 ;
V_7 -> V_43 = - V_44 ;
V_7 -> V_118 = - 1 ;
if ( * V_236 )
V_7 -> V_237 = V_236 ( V_18 , V_232 ) ;
if ( V_7 -> V_237 ) {
if ( V_7 -> V_237 -> V_238 ) {
V_4 = V_7 -> V_237 -> V_238 ( V_7 -> V_237 ) ;
if ( V_4 ) {
F_69 ( & V_18 -> V_19 , L_22 ) ;
goto free;
}
}
V_7 -> V_225 = V_7 -> V_237 -> V_225 ;
V_7 -> V_43 = V_7 -> V_237 -> V_43 ;
}
V_10 -> V_239 = L_23 ;
V_10 -> V_240 = V_2 -> V_226 && V_2 -> V_226 -> V_240 ?
V_2 -> V_226 -> V_240 :
& V_241 ;
V_10 -> V_26 = V_2 -> V_26 ;
V_10 -> V_130 = V_2 -> V_130 ;
V_10 -> V_38 = V_18 -> V_38 ;
V_4 = F_125 ( V_18 , F_126 ( V_233 ) , F_44 ( V_10 -> V_14 ) ) ;
if ( V_4 ) {
F_69 ( & V_18 -> V_19 , L_24 ) ;
goto V_242;
}
V_10 -> V_152 = F_127 ( V_18 ) [ V_233 ] ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_243 ) {
V_4 = V_2 -> V_226 -> V_243 ( V_7 ) ;
if ( V_4 )
goto V_242;
}
if ( F_25 ( V_7 -> V_225 ) ) {
if ( ! F_26 ( & V_18 -> V_19 , V_7 -> V_225 , L_25 ) ) {
F_128 ( V_7 -> V_225 , 1 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_101 ;
V_7 -> V_105 = F_109 ;
} else {
F_31 ( & V_18 -> V_19 , L_26 ) ;
V_7 -> V_225 = - V_44 ;
}
}
V_10 -> V_14 -> V_244 = V_20 | V_17 ;
V_10 -> V_14 -> V_232 = V_232 ;
V_10 -> V_14 -> V_51 |= V_245 ;
if ( V_7 -> V_118 >= 0 ) {
V_4 = F_129 ( V_10 -> V_14 , NULL , V_7 -> V_118 ,
V_7 -> V_119 , 0 , NULL ) ;
if ( V_4 == - V_246 )
goto remove;
if ( V_4 ) {
F_31 ( & V_18 -> V_19 , L_27 ) ;
V_7 -> V_118 = - 1 ;
}
}
if ( V_2 -> V_226 && V_2 -> V_226 -> V_247 )
V_4 = V_2 -> V_226 -> V_247 ( V_7 ) ;
else
V_4 = F_130 ( V_10 ) ;
if ( V_4 )
goto remove;
F_24 ( V_7 ) ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_248 &&
! F_25 ( V_7 -> V_43 ) && V_7 -> V_118 < 0 )
V_2 -> V_249 = false ;
return V_7 ;
remove:
if ( V_2 -> V_226 && V_2 -> V_226 -> V_250 )
V_2 -> V_226 -> V_250 ( V_7 , 0 ) ;
V_242:
if ( V_7 -> V_237 && V_7 -> V_237 -> V_242 )
V_7 -> V_237 -> V_242 ( V_7 -> V_237 ) ;
free:
F_131 ( V_10 ) ;
return F_120 ( V_4 ) ;
}
static void F_132 ( struct V_6 * V_7 )
{
int V_166 ;
T_3 V_135 ;
F_32 ( V_7 ) ;
V_166 = 0 ;
V_135 = F_87 ( V_7 -> V_10 -> V_152 + V_251 ) ;
if ( V_135 == ( T_3 ) - 1 )
V_166 = 1 ;
F_133 ( V_7 -> V_10 , V_166 ) ;
if ( V_7 -> V_2 -> V_226 && V_7 -> V_2 -> V_226 -> V_250 )
V_7 -> V_2 -> V_226 -> V_250 ( V_7 , V_166 ) ;
if ( V_7 -> V_237 && V_7 -> V_237 -> V_242 )
V_7 -> V_237 -> V_242 ( V_7 -> V_237 ) ;
F_131 ( V_7 -> V_10 ) ;
}
static void F_134 ( struct V_55 * V_19 )
{
F_135 ( V_19 , 1 ) ;
F_136 ( V_19 , 50 ) ;
F_137 ( V_19 ) ;
F_138 ( V_19 ) ;
F_139 ( V_19 ) ;
}
static void F_140 ( struct V_55 * V_19 )
{
F_141 ( V_19 ) ;
F_142 ( V_19 ) ;
}
static int F_143 ( struct V_147 * V_18 ,
const struct V_252 * V_253 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_5 V_8 , V_231 ;
int V_4 , V_3 ;
F_144 ( V_18 == NULL ) ;
F_144 ( V_253 == NULL ) ;
F_82 ( & V_18 -> V_19 , L_28 ,
( int ) V_18 -> V_254 , ( int ) V_18 -> V_55 , ( int ) V_18 -> V_137 ) ;
V_4 = F_76 ( V_18 , V_255 , & V_8 ) ;
if ( V_4 )
return V_4 ;
V_8 = F_145 ( V_8 ) + 1 ;
F_146 ( & V_18 -> V_19 , L_29 , V_8 ) ;
if ( V_8 == 0 )
return - V_133 ;
F_144 ( V_8 > V_256 ) ;
V_4 = F_76 ( V_18 , V_255 , & V_231 ) ;
if ( V_4 )
return V_4 ;
V_231 &= V_257 ;
if ( V_231 > 5 ) {
F_69 ( & V_18 -> V_19 , L_30 ) ;
return - V_133 ;
}
V_4 = F_147 ( V_18 ) ;
if ( V_4 )
return V_4 ;
V_2 = F_148 ( & V_18 -> V_19 , sizeof( * V_2 ) , V_258 ) ;
if ( ! V_2 )
return - V_259 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_226 = ( const struct V_260 * ) V_253 -> V_261 ;
if ( V_2 -> V_226 ) {
V_2 -> V_26 = V_2 -> V_226 -> V_26 ;
V_2 -> V_130 = V_2 -> V_226 -> V_130 ;
V_2 -> V_249 = V_2 -> V_226 -> V_249 ;
}
V_2 -> V_5 = V_8 ;
V_2 -> V_11 = true ;
V_2 -> V_22 = true ;
F_149 ( V_18 , V_2 ) ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_262 ) {
V_4 = V_2 -> V_226 -> V_262 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
V_8 = V_2 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
V_7 = F_118 ( V_18 , V_2 , V_231 , V_3 ) ;
if ( F_123 ( V_7 ) ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_132 ( V_2 -> V_8 [ V_3 ] ) ;
return F_150 ( V_7 ) ;
}
V_2 -> V_8 [ V_3 ] = V_7 ;
}
if ( V_2 -> V_249 )
F_134 ( & V_18 -> V_19 ) ;
return 0 ;
}
static void F_151 ( struct V_147 * V_18 )
{
int V_3 ;
struct V_1 * V_2 = F_114 ( V_18 ) ;
if ( V_2 -> V_249 )
F_140 ( & V_18 -> V_19 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_132 ( V_2 -> V_8 [ V_3 ] ) ;
}
