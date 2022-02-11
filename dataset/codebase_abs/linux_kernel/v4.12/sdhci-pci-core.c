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
V_7 -> V_10 -> V_14 -> V_51 |= V_52 |
V_53 ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_28 |= V_54 | V_50 ;
return 0 ;
}
static int F_36 ( struct V_55 * V_55 , struct V_56 * V_19 ,
unsigned int V_57 , T_3 * V_58 )
{
union V_59 * V_60 ;
int V_41 = 0 ;
T_4 V_61 ;
V_60 = F_37 ( F_38 ( V_19 ) , V_62 , 0 , V_57 , NULL ) ;
if ( ! V_60 )
return - V_63 ;
if ( V_60 -> type != V_64 || V_60 -> V_65 . V_66 < 1 ) {
V_41 = - V_44 ;
goto V_46;
}
V_61 = F_39 ( T_4 , V_60 -> V_65 . V_66 , 4 ) ;
* V_58 = 0 ;
memcpy ( V_58 , V_60 -> V_65 . V_67 , V_61 ) ;
V_46:
F_40 ( V_60 ) ;
return V_41 ;
}
static int F_41 ( struct V_55 * V_55 , struct V_56 * V_19 ,
unsigned int V_57 , T_3 * V_58 )
{
if ( V_57 > 31 || ! ( V_55 -> V_68 & ( 1 << V_57 ) ) )
return - V_63 ;
return F_36 ( V_55 , V_19 , V_57 , V_58 ) ;
}
static void F_42 ( struct V_55 * V_55 , struct V_56 * V_19 ,
struct V_69 * V_14 )
{
int V_41 ;
T_3 V_70 ;
V_41 = F_36 ( V_55 , V_19 , V_71 , & V_55 -> V_68 ) ;
if ( V_41 ) {
F_43 ( L_3 ,
F_44 ( V_14 ) , V_41 ) ;
return;
}
F_43 ( L_4 ,
F_44 ( V_14 ) , V_55 -> V_68 ) ;
V_41 = F_41 ( V_55 , V_19 , V_72 , & V_70 ) ;
V_55 -> V_73 = V_41 ? 0 : V_70 ;
V_41 = F_41 ( V_55 , V_19 , V_74 , & V_70 ) ;
V_55 -> V_75 = V_41 ? true : ! ! V_70 ;
}
static void F_45 ( struct V_9 * V_10 )
{
T_5 V_76 ;
V_76 = F_46 ( V_10 , V_77 ) ;
V_76 |= 0x10 ;
F_47 ( V_10 , V_76 , V_77 ) ;
F_48 ( 9 ) ;
V_76 &= ~ 0x10 ;
F_47 ( V_10 , V_76 , V_77 ) ;
F_49 ( 300 , 1000 ) ;
}
static int F_50 ( struct V_78 * V_79 ,
unsigned int V_80 , int V_81 ,
int V_82 , int * V_83 )
{
struct V_9 * V_10 = F_51 ( V_79 -> V_10 ) ;
struct V_6 * V_7 = F_52 ( V_10 ) ;
struct V_55 * V_55 = F_53 ( V_7 ) ;
return V_55 -> V_73 ;
}
static int F_54 ( struct V_69 * V_14 )
{
int V_84 = F_55 ( V_14 ) ;
struct V_9 * V_10 = F_51 ( V_14 ) ;
unsigned long V_85 ;
int V_4 = 0 ;
if ( ! V_84 )
return 0 ;
F_56 ( & V_10 -> V_86 , V_85 ) ;
if ( V_10 -> V_85 & V_87 )
goto V_46;
V_4 = ! ! ( F_57 ( V_10 , V_88 ) & V_89 ) ;
V_46:
F_58 ( & V_10 -> V_86 , V_85 ) ;
return V_4 ;
}
static void F_59 ( struct V_9 * V_10 , unsigned char V_90 ,
unsigned short V_91 )
{
int V_92 ;
T_5 V_76 ;
F_60 ( V_10 , V_90 , V_91 ) ;
if ( V_90 == V_93 )
return;
for ( V_92 = 0 ; V_92 < V_94 ; V_92 ++ ) {
V_76 = F_46 ( V_10 , V_77 ) ;
if ( V_76 & V_95 )
break;
F_48 ( V_96 ) ;
V_76 |= V_95 ;
F_47 ( V_10 , V_76 , V_77 ) ;
}
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_55 * V_55 = F_53 ( V_7 ) ;
struct V_56 * V_19 = & V_7 -> V_2 -> V_18 -> V_19 ;
struct V_69 * V_14 = V_7 -> V_10 -> V_14 ;
F_42 ( V_55 , V_19 , V_14 ) ;
V_7 -> V_2 -> V_22 = V_55 -> V_75 ;
}
static int F_62 ( struct V_6 * V_7 )
{
F_61 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_37 | V_50 |
V_97 | V_98 |
V_99 |
V_100 ;
V_7 -> V_10 -> V_14 -> V_51 |= V_53 ;
V_7 -> V_101 = F_45 ;
if ( V_7 -> V_2 -> V_18 -> V_56 == V_102 )
V_7 -> V_10 -> V_103 = 1000 ;
V_7 -> V_10 -> V_104 . V_105 =
F_50 ;
return 0 ;
}
static int F_63 ( struct V_6 * V_7 )
{
T_6 V_106 ;
unsigned long long V_107 ;
V_106 = F_64 ( F_38 ( & V_7 -> V_2 -> V_18 -> V_19 ) ,
L_5 , NULL , & V_107 ) ;
if ( F_65 ( V_106 ) ) {
F_66 ( & V_7 -> V_2 -> V_18 -> V_19 ,
L_6 ) ;
return - V_44 ;
}
V_7 -> V_10 -> V_14 -> V_108 = V_107 * 1000000 ;
return 0 ;
}
static inline int F_63 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_67 ( struct V_6 * V_7 )
{
int V_41 ;
F_61 ( V_7 ) ;
V_41 = F_63 ( V_7 ) ;
if ( V_41 )
return V_41 ;
V_7 -> V_10 -> V_14 -> V_28 |= V_54 | V_50 |
V_100 ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 )
{
F_61 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_54 | V_50 |
V_100 ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 )
{
F_61 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_100 |
V_109 ;
V_7 -> V_110 = 0 ;
V_7 -> V_111 = true ;
if ( V_7 -> V_2 -> V_18 -> V_56 == V_112 ||
V_7 -> V_2 -> V_18 -> V_56 == V_113 ||
V_7 -> V_2 -> V_18 -> V_56 == V_114 ||
V_7 -> V_2 -> V_18 -> V_56 == V_115 )
V_7 -> V_10 -> V_104 . V_116 = F_54 ;
return 0 ;
}
static int F_70 ( struct V_6 * V_7 )
{
unsigned int V_117 = F_71 ( V_7 -> V_2 -> V_18 -> V_118 ) ;
switch ( V_117 ) {
case V_119 :
case V_120 :
V_7 -> V_10 -> V_14 -> V_28 |= V_50 |
V_37 |
V_98 ;
break;
case V_121 :
V_7 -> V_10 -> V_122 |= V_123 ;
break;
case V_124 :
V_7 -> V_10 -> V_14 -> V_28 |= V_50 |
V_54 ;
break;
default:
return - V_125 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , int V_126 )
{
T_5 V_127 ;
int V_4 ;
V_4 = F_73 ( V_2 -> V_18 , 0xAE , & V_127 ) ;
if ( V_4 )
return V_4 ;
if ( V_126 )
V_127 |= 0x47 ;
else
V_127 &= ~ 0x47 ;
return F_74 ( V_2 -> V_18 , 0xAE , V_127 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_4 ;
T_7 V_128 = 0 ;
if ( V_2 -> V_18 -> V_129 == 0 ) {
V_2 -> V_26 |= V_130 |
V_131 |
V_132 |
V_133 |
V_134 ;
}
if ( V_2 -> V_18 -> V_56 == V_135 )
V_128 = V_136 ;
else if ( V_2 -> V_18 -> V_56 == V_137 )
V_128 = V_138 ;
if ( V_128 ) {
struct V_139 * V_140 ;
V_140 = NULL ;
while ( ( V_140 = F_76 ( V_141 ,
V_128 , V_140 ) ) != NULL ) {
if ( ( F_77 ( V_2 -> V_18 -> V_118 ) ==
F_77 ( V_140 -> V_118 ) ) &&
( V_2 -> V_18 -> V_142 == V_140 -> V_142 ) )
break;
}
if ( V_140 ) {
F_78 ( V_140 ) ;
F_79 ( & V_2 -> V_18 -> V_19 , L_7
L_8 ) ;
return - V_125 ;
}
}
V_4 = F_72 ( V_2 , 1 ) ;
if ( V_4 ) {
F_66 ( & V_2 -> V_18 -> V_19 , L_9 ) ;
return V_4 ;
}
if ( V_2 -> V_18 -> V_56 == V_137 ||
V_2 -> V_18 -> V_56 == V_138 )
V_2 -> V_26 |= V_143 ;
return 0 ;
}
static void F_80 ( struct V_9 * V_10 , int V_126 )
{
T_5 V_127 ;
V_127 = F_81 ( V_10 -> V_144 + 0xC0 ) ;
if ( V_126 )
V_127 |= 0x01 ;
else
V_127 &= ~ 0x01 ;
F_82 ( V_127 , V_10 -> V_144 + 0xC0 ) ;
}
static int F_83 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 -> V_18 -> V_129 == 0 ) {
T_7 V_145 ;
V_145 = F_84 ( V_7 -> V_10 -> V_144 + V_146 ) ;
V_145 = ( V_145 & V_147 ) >>
V_148 ;
if ( V_145 < 0xAC )
V_7 -> V_10 -> V_26 |= V_149 ;
}
if ( V_7 -> V_2 -> V_18 -> V_56 == V_138 ) {
V_7 -> V_10 -> V_150 = V_151 | V_152 |
V_153 | V_154 |
V_155 ;
V_7 -> V_10 -> V_156 = V_151 | V_152 |
V_153 | V_154 ;
}
if ( V_7 -> V_2 -> V_18 -> V_56 == V_136 ||
V_7 -> V_2 -> V_18 -> V_56 == V_138 )
F_80 ( V_7 -> V_10 , 1 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_157 ;
return 0 ;
}
static void F_85 ( struct V_6 * V_7 , int V_158 )
{
if ( V_158 )
return;
if ( V_7 -> V_2 -> V_18 -> V_56 == V_136 ||
V_7 -> V_2 -> V_18 -> V_56 == V_138 )
F_80 ( V_7 -> V_10 , 0 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_18 -> V_56 == V_136 ||
V_2 -> V_18 -> V_56 == V_138 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_80 ( V_2 -> V_8 [ V_3 ] -> V_10 , 0 ) ;
}
F_6 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_4 , V_3 ;
if ( V_2 -> V_18 -> V_56 == V_136 ||
V_2 -> V_18 -> V_56 == V_138 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_80 ( V_2 -> V_8 [ V_3 ] -> V_10 , 1 ) ;
}
V_4 = F_72 ( V_2 , 1 ) ;
if ( V_4 ) {
F_66 ( & V_2 -> V_18 -> V_19 , L_9 ) ;
return V_4 ;
}
return F_9 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 -> V_159 & 0x0000FF ) == V_160 ) {
V_2 -> V_18 -> V_159 &= ~ 0x0000FF ;
V_2 -> V_18 -> V_159 |= V_161 ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_7 )
{
int V_162 , V_163 ;
T_5 V_164 = F_81 ( V_7 -> V_10 -> V_144 + V_165 ) ;
T_5 V_166 = F_81 ( V_7 -> V_10 -> V_144 + V_167 ) ;
F_79 ( & V_7 -> V_2 -> V_18 -> V_19 , L_10
L_11 ,
V_164 >> 4 , V_164 & 0xf ,
V_166 >> 4 , V_166 & 0xf ) ;
if ( V_166 >= 0x20 )
V_7 -> V_10 -> V_26 |= V_168 ;
F_82 ( V_169 , V_7 -> V_10 -> V_144 + V_170 ) ;
F_82 ( V_171 , V_7 -> V_10 -> V_144 + V_172 ) ;
F_48 ( 50 ) ;
V_162 = 10 ;
do {
V_163 = F_90 ( V_7 -> V_10 -> V_144 + V_173 ) ;
if ( V_163 & V_174 )
break;
F_48 ( 100 ) ;
} while ( -- V_162 );
if ( ! V_162 ) {
F_66 ( & V_7 -> V_2 -> V_18 -> V_19 ,
L_12 ) ;
F_82 ( 0 , V_7 -> V_10 -> V_144 + V_172 ) ;
return - V_125 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 -> V_129 == 0x10 )
V_2 -> V_26 |= V_175 ;
return 0 ;
}
static int F_92 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_51 |= V_176 ;
return 0 ;
}
static void F_93 ( struct V_9 * V_10 )
{
unsigned int V_70 ;
V_70 = F_94 ( V_10 , V_177 ) ;
V_70 |= V_178 | V_179 ;
F_95 ( V_10 , V_70 , V_177 ) ;
V_70 = F_94 ( V_10 , V_177 ) ;
V_70 &= ~ V_179 ;
F_95 ( V_10 , V_70 , V_177 ) ;
}
static void F_96 ( struct V_139 * V_18 , T_5 V_180 )
{
unsigned int V_70 ;
F_97 ( V_18 , V_181 , & V_70 ) ;
V_70 &= ~ V_182 ;
V_70 |= ( V_183 | ( V_180 << 1 ) ) ;
F_98 ( V_18 , V_181 , V_70 ) ;
}
static void F_99 ( struct V_139 * V_18 )
{
unsigned int V_70 ;
F_97 ( V_18 , V_184 , & V_70 ) ;
V_70 |= V_185 ;
F_98 ( V_18 , V_184 , V_70 ) ;
}
static int F_100 ( struct V_9 * V_10 , T_3 V_186 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
struct V_139 * V_18 = V_7 -> V_2 -> V_18 ;
T_5 V_187 = 0 ;
T_5 V_188 = 0 ;
T_5 V_189 = 0 ;
T_5 V_190 , V_191 ;
F_93 ( V_10 ) ;
for ( V_191 = 0 ; V_191 < 12 ; V_191 ++ ) {
F_96 ( V_18 , V_191 ) ;
if ( F_101 ( V_10 -> V_14 , V_186 , NULL ) ) {
V_187 = 0 ;
F_17 ( V_192 ) ;
V_190 = V_193 | V_194 ;
F_47 ( V_10 , V_190 , V_195 ) ;
} else if ( ++ V_187 > V_188 ) {
V_188 = V_187 ;
V_189 = V_191 ;
}
}
if ( ! V_188 ) {
F_66 ( & V_18 -> V_19 , L_13 ) ;
return - V_196 ;
}
F_96 ( V_18 , V_189 - V_188 / 2 ) ;
F_99 ( V_18 ) ;
V_10 -> V_14 -> V_197 = 0 ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_139 * V_198 ;
enum V_199 V_200 ;
V_198 = F_76 ( V_201 ,
V_202 , NULL ) ;
if ( V_198 ) {
V_200 = V_203 ;
} else {
V_198 = F_76 ( V_201 ,
V_204 , NULL ) ;
if ( V_198 ) {
if ( V_198 -> V_129 < 0x51 )
V_200 = V_205 ;
else
V_200 = V_206 ;
} else {
V_200 = V_207 ;
}
}
if ( V_200 == V_203 || V_200 == V_205 )
V_2 -> V_122 |= V_208 ;
return 0 ;
}
static int F_103 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_139 * V_18 ;
V_7 = F_52 ( V_10 ) ;
V_18 = V_7 -> V_2 -> V_18 ;
if ( ( ( V_18 -> V_159 & 0xFFFF00 ) == ( V_209 << 8 ) ) &&
( ( V_18 -> V_159 & 0x0000FF ) != V_161 ) &&
( V_10 -> V_85 & V_210 ) ) {
F_31 ( & V_18 -> V_19 , L_14
L_15 ) ;
}
F_104 ( V_18 ) ;
return 0 ;
}
static void F_105 ( struct V_9 * V_10 , int V_211 )
{
T_5 V_190 ;
V_190 = F_46 ( V_10 , V_212 ) ;
switch ( V_211 ) {
case V_213 :
V_190 |= V_214 ;
V_190 &= ~ V_215 ;
break;
case V_216 :
V_190 |= V_215 ;
V_190 &= ~ V_214 ;
break;
default:
V_190 &= ~ ( V_214 | V_215 ) ;
break;
}
F_47 ( V_10 , V_190 , V_212 ) ;
}
static void F_106 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
int V_217 = V_7 -> V_217 ;
if ( ! F_25 ( V_217 ) )
return;
F_107 ( V_217 , 0 ) ;
F_48 ( 10 ) ;
F_107 ( V_217 , 1 ) ;
F_49 ( 300 , 1000 ) ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
if ( V_7 -> V_101 )
V_7 -> V_101 ( V_10 ) ;
}
static int F_109 ( struct V_56 * V_19 )
{
struct V_139 * V_18 = F_110 ( V_19 ) ;
struct V_1 * V_2 = F_111 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_218 && V_2 -> V_218 -> V_219 )
return V_2 -> V_218 -> V_219 ( V_2 ) ;
return F_8 ( V_2 ) ;
}
static int F_112 ( struct V_56 * V_19 )
{
struct V_139 * V_18 = F_110 ( V_19 ) ;
struct V_1 * V_2 = F_111 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_218 && V_2 -> V_218 -> V_220 )
return V_2 -> V_218 -> V_220 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_113 ( struct V_56 * V_19 )
{
struct V_139 * V_18 = F_110 ( V_19 ) ;
struct V_1 * V_2 = F_111 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_218 && V_2 -> V_218 -> V_221 )
return V_2 -> V_218 -> V_221 ( V_2 ) ;
return F_10 ( V_2 ) ;
}
static int F_114 ( struct V_56 * V_19 )
{
struct V_139 * V_18 = F_110 ( V_19 ) ;
struct V_1 * V_2 = F_111 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_218 && V_2 -> V_218 -> V_222 )
return V_2 -> V_218 -> V_222 ( V_2 ) ;
return F_13 ( V_2 ) ;
}
static struct V_6 * F_115 (
struct V_139 * V_18 , struct V_1 * V_2 , int V_223 ,
int V_224 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_4 , V_225 = V_223 + V_224 ;
T_4 V_226 = V_2 -> V_218 ? V_2 -> V_218 -> V_226 : 0 ;
if ( ! ( F_116 ( V_18 , V_225 ) & V_227 ) ) {
F_66 ( & V_18 -> V_19 , L_16 , V_225 ) ;
return F_117 ( - V_125 ) ;
}
if ( F_118 ( V_18 , V_225 ) < 0x100 ) {
F_66 ( & V_18 -> V_19 , L_17
L_18 ) ;
}
if ( ( V_18 -> V_159 & 0x0000FF ) == V_160 ) {
F_66 ( & V_18 -> V_19 , L_19 ) ;
return F_117 ( - V_125 ) ;
}
if ( ( V_18 -> V_159 & 0x0000FF ) > V_160 ) {
F_66 ( & V_18 -> V_19 , L_20 ) ;
return F_117 ( - V_125 ) ;
}
V_10 = F_119 ( & V_18 -> V_19 , sizeof( * V_7 ) + V_226 ) ;
if ( F_120 ( V_10 ) ) {
F_66 ( & V_18 -> V_19 , L_21 ) ;
return F_121 ( V_10 ) ;
}
V_7 = F_52 ( V_10 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_217 = - V_44 ;
V_7 -> V_43 = - V_44 ;
V_7 -> V_110 = - 1 ;
if ( * V_228 )
V_7 -> V_229 = V_228 ( V_18 , V_224 ) ;
if ( V_7 -> V_229 ) {
if ( V_7 -> V_229 -> V_230 ) {
V_4 = V_7 -> V_229 -> V_230 ( V_7 -> V_229 ) ;
if ( V_4 ) {
F_66 ( & V_18 -> V_19 , L_22 ) ;
goto free;
}
}
V_7 -> V_217 = V_7 -> V_229 -> V_217 ;
V_7 -> V_43 = V_7 -> V_229 -> V_43 ;
}
V_10 -> V_231 = L_23 ;
V_10 -> V_232 = V_2 -> V_218 && V_2 -> V_218 -> V_232 ?
V_2 -> V_218 -> V_232 :
& V_233 ;
V_10 -> V_26 = V_2 -> V_26 ;
V_10 -> V_122 = V_2 -> V_122 ;
V_10 -> V_38 = V_18 -> V_38 ;
V_4 = F_122 ( V_18 , F_123 ( V_225 ) , F_44 ( V_10 -> V_14 ) ) ;
if ( V_4 ) {
F_66 ( & V_18 -> V_19 , L_24 ) ;
goto V_234;
}
V_10 -> V_144 = F_124 ( V_18 ) [ V_225 ] ;
if ( V_2 -> V_218 && V_2 -> V_218 -> V_235 ) {
V_4 = V_2 -> V_218 -> V_235 ( V_7 ) ;
if ( V_4 )
goto V_234;
}
if ( F_25 ( V_7 -> V_217 ) ) {
if ( ! F_26 ( & V_18 -> V_19 , V_7 -> V_217 , L_25 ) ) {
F_125 ( V_7 -> V_217 , 1 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_97 ;
V_7 -> V_101 = F_106 ;
} else {
F_31 ( & V_18 -> V_19 , L_26 ) ;
V_7 -> V_217 = - V_44 ;
}
}
V_10 -> V_14 -> V_236 = V_20 | V_17 ;
V_10 -> V_14 -> V_224 = V_224 ;
V_10 -> V_14 -> V_51 |= V_237 ;
if ( V_7 -> V_110 >= 0 ) {
V_4 = F_126 ( V_10 -> V_14 , NULL , V_7 -> V_110 ,
V_7 -> V_111 , 0 , NULL ) ;
if ( V_4 == - V_238 )
goto remove;
if ( V_4 ) {
F_31 ( & V_18 -> V_19 , L_27 ) ;
V_7 -> V_110 = - 1 ;
}
}
if ( V_2 -> V_218 && V_2 -> V_218 -> V_239 )
V_4 = V_2 -> V_218 -> V_239 ( V_7 ) ;
else
V_4 = F_127 ( V_10 ) ;
if ( V_4 )
goto remove;
F_24 ( V_7 ) ;
if ( V_2 -> V_218 && V_2 -> V_218 -> V_240 &&
! F_25 ( V_7 -> V_43 ) && V_7 -> V_110 < 0 )
V_2 -> V_241 = false ;
return V_7 ;
remove:
if ( V_2 -> V_218 && V_2 -> V_218 -> V_242 )
V_2 -> V_218 -> V_242 ( V_7 , 0 ) ;
V_234:
if ( V_7 -> V_229 && V_7 -> V_229 -> V_234 )
V_7 -> V_229 -> V_234 ( V_7 -> V_229 ) ;
free:
F_128 ( V_10 ) ;
return F_117 ( V_4 ) ;
}
static void F_129 ( struct V_6 * V_7 )
{
int V_158 ;
T_3 V_127 ;
F_32 ( V_7 ) ;
V_158 = 0 ;
V_127 = F_84 ( V_7 -> V_10 -> V_144 + V_243 ) ;
if ( V_127 == ( T_3 ) - 1 )
V_158 = 1 ;
F_130 ( V_7 -> V_10 , V_158 ) ;
if ( V_7 -> V_2 -> V_218 && V_7 -> V_2 -> V_218 -> V_242 )
V_7 -> V_2 -> V_218 -> V_242 ( V_7 , V_158 ) ;
if ( V_7 -> V_229 && V_7 -> V_229 -> V_234 )
V_7 -> V_229 -> V_234 ( V_7 -> V_229 ) ;
F_128 ( V_7 -> V_10 ) ;
}
static void F_131 ( struct V_56 * V_19 )
{
F_132 ( V_19 , 1 ) ;
F_133 ( V_19 , 50 ) ;
F_134 ( V_19 ) ;
F_135 ( V_19 ) ;
F_136 ( V_19 ) ;
}
static void F_137 ( struct V_56 * V_19 )
{
F_138 ( V_19 ) ;
F_139 ( V_19 ) ;
}
static int F_140 ( struct V_139 * V_18 ,
const struct V_244 * V_245 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_5 V_8 , V_223 ;
int V_4 , V_3 ;
F_141 ( V_18 == NULL ) ;
F_141 ( V_245 == NULL ) ;
F_79 ( & V_18 -> V_19 , L_28 ,
( int ) V_18 -> V_246 , ( int ) V_18 -> V_56 , ( int ) V_18 -> V_129 ) ;
V_4 = F_73 ( V_18 , V_247 , & V_8 ) ;
if ( V_4 )
return V_4 ;
V_8 = F_142 ( V_8 ) + 1 ;
F_143 ( & V_18 -> V_19 , L_29 , V_8 ) ;
if ( V_8 == 0 )
return - V_125 ;
F_141 ( V_8 > V_248 ) ;
V_4 = F_73 ( V_18 , V_247 , & V_223 ) ;
if ( V_4 )
return V_4 ;
V_223 &= V_249 ;
if ( V_223 > 5 ) {
F_66 ( & V_18 -> V_19 , L_30 ) ;
return - V_125 ;
}
V_4 = F_144 ( V_18 ) ;
if ( V_4 )
return V_4 ;
V_2 = F_145 ( & V_18 -> V_19 , sizeof( * V_2 ) , V_250 ) ;
if ( ! V_2 )
return - V_251 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_218 = ( const struct V_252 * ) V_245 -> V_253 ;
if ( V_2 -> V_218 ) {
V_2 -> V_26 = V_2 -> V_218 -> V_26 ;
V_2 -> V_122 = V_2 -> V_218 -> V_122 ;
V_2 -> V_241 = V_2 -> V_218 -> V_241 ;
}
V_2 -> V_5 = V_8 ;
V_2 -> V_11 = true ;
V_2 -> V_22 = true ;
F_146 ( V_18 , V_2 ) ;
if ( V_2 -> V_218 && V_2 -> V_218 -> V_254 ) {
V_4 = V_2 -> V_218 -> V_254 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
V_8 = V_2 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
V_7 = F_115 ( V_18 , V_2 , V_223 , V_3 ) ;
if ( F_120 ( V_7 ) ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_129 ( V_2 -> V_8 [ V_3 ] ) ;
return F_147 ( V_7 ) ;
}
V_2 -> V_8 [ V_3 ] = V_7 ;
}
if ( V_2 -> V_241 )
F_131 ( & V_18 -> V_19 ) ;
return 0 ;
}
static void F_148 ( struct V_139 * V_18 )
{
int V_3 ;
struct V_1 * V_2 = F_111 ( V_18 ) ;
if ( V_2 -> V_241 )
F_137 ( & V_18 -> V_19 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_129 ( V_2 -> V_8 [ V_3 ] ) ;
}
