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
V_54 -> V_70 = true ;
V_41 = F_36 ( V_54 , V_19 , V_71 , & V_54 -> V_67 ) ;
if ( V_41 ) {
F_43 ( L_3 ,
F_44 ( V_14 ) , V_41 ) ;
return;
}
F_43 ( L_4 ,
F_44 ( V_14 ) , V_54 -> V_67 ) ;
V_41 = F_41 ( V_54 , V_19 , V_72 , & V_69 ) ;
V_54 -> V_73 = V_41 ? 0 : V_69 ;
V_41 = F_41 ( V_54 , V_19 , V_74 , & V_69 ) ;
V_54 -> V_70 = V_41 ? true : ! ! V_69 ;
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
return V_54 -> V_73 ;
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
static void F_63 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
struct V_54 * V_54 = F_53 ( V_7 ) ;
struct V_55 * V_19 = & V_7 -> V_2 -> V_18 -> V_19 ;
T_3 V_57 = 0 ;
int V_41 ;
V_41 = F_41 ( V_54 , V_19 , V_101 , & V_57 ) ;
F_43 ( L_5 ,
F_44 ( V_10 -> V_14 ) , V_102 , V_41 , V_57 ) ;
}
static void F_64 ( struct V_6 * V_7 )
{
struct V_54 * V_54 = F_53 ( V_7 ) ;
struct V_55 * V_19 = & V_7 -> V_2 -> V_18 -> V_19 ;
struct V_68 * V_14 = V_7 -> V_10 -> V_14 ;
F_42 ( V_54 , V_19 , V_14 ) ;
V_7 -> V_2 -> V_22 = V_54 -> V_70 ;
}
static int F_65 ( struct V_6 * V_7 )
{
F_64 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_37 | V_50 |
V_103 | V_104 |
V_105 |
V_106 ;
V_7 -> V_107 = F_45 ;
if ( V_7 -> V_2 -> V_18 -> V_55 == V_108 )
V_7 -> V_10 -> V_109 = 1000 ;
V_7 -> V_10 -> V_110 . V_111 =
F_50 ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
int V_4 = F_65 ( V_7 ) ;
if ( V_7 -> V_2 -> V_18 -> V_55 != V_112 ) {
V_7 -> V_10 -> V_14 -> V_51 |= V_113 ,
V_7 -> V_10 -> V_110 . V_114 =
F_61 ;
}
return V_4 ;
}
static int F_67 ( struct V_6 * V_7 )
{
T_6 V_115 ;
unsigned long long V_116 ;
V_115 = F_68 ( F_38 ( & V_7 -> V_2 -> V_18 -> V_19 ) ,
L_6 , NULL , & V_116 ) ;
if ( F_69 ( V_115 ) ) {
F_70 ( & V_7 -> V_2 -> V_18 -> V_19 ,
L_7 ) ;
return - V_44 ;
}
V_7 -> V_10 -> V_14 -> V_117 = V_116 * 1000000 ;
return 0 ;
}
static inline int F_67 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_71 ( struct V_6 * V_7 )
{
int V_41 ;
F_64 ( V_7 ) ;
V_41 = F_67 ( V_7 ) ;
if ( V_41 )
return V_41 ;
V_7 -> V_10 -> V_14 -> V_28 |= V_53 | V_50 |
V_106 ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 )
{
F_64 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_53 | V_50 |
V_106 ;
return 0 ;
}
static int F_73 ( struct V_6 * V_7 )
{
F_64 ( V_7 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_106 |
V_118 | V_119 ;
V_7 -> V_120 = 0 ;
V_7 -> V_121 = true ;
if ( V_7 -> V_2 -> V_18 -> V_55 == V_122 ||
V_7 -> V_2 -> V_18 -> V_55 == V_123 ||
V_7 -> V_2 -> V_18 -> V_55 == V_124 ||
V_7 -> V_2 -> V_18 -> V_55 == V_125 )
V_7 -> V_10 -> V_110 . V_126 = F_54 ;
return 0 ;
}
static void F_74 ( struct V_6 * V_7 )
{
struct V_127 * V_55 , * V_128 ;
V_55 = F_75 ( & V_7 -> V_2 -> V_18 -> V_19 ) ;
if ( ! V_55 )
return;
F_76 ( V_55 ) ;
F_77 (child, &device->children, node)
if ( V_128 -> V_115 . V_129 && V_128 -> V_115 . V_130 )
F_76 ( V_128 ) ;
}
static inline void F_74 ( struct V_6 * V_7 ) {}
static int F_78 ( struct V_6 * V_7 )
{
unsigned int V_131 = F_79 ( V_7 -> V_2 -> V_18 -> V_132 ) ;
switch ( V_131 ) {
case V_133 :
case V_134 :
V_7 -> V_10 -> V_14 -> V_28 |= V_50 |
V_37 |
V_104 ;
break;
case V_135 :
V_7 -> V_10 -> V_136 |= V_137 ;
break;
case V_138 :
V_7 -> V_10 -> V_14 -> V_28 |= V_50 |
V_53 ;
break;
default:
return - V_139 ;
}
F_74 ( V_7 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , int V_140 )
{
T_5 V_141 ;
int V_4 ;
V_4 = F_81 ( V_2 -> V_18 , 0xAE , & V_141 ) ;
if ( V_4 )
return V_4 ;
if ( V_140 )
V_141 |= 0x47 ;
else
V_141 &= ~ 0x47 ;
return F_82 ( V_2 -> V_18 , 0xAE , V_141 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
int V_4 ;
T_7 V_142 = 0 ;
if ( V_2 -> V_18 -> V_143 == 0 ) {
V_2 -> V_26 |= V_144 |
V_145 |
V_146 |
V_147 |
V_148 ;
}
if ( V_2 -> V_18 -> V_55 == V_149 )
V_142 = V_150 ;
else if ( V_2 -> V_18 -> V_55 == V_151 )
V_142 = V_152 ;
if ( V_142 ) {
struct V_153 * V_154 ;
V_154 = NULL ;
while ( ( V_154 = F_84 ( V_155 ,
V_142 , V_154 ) ) != NULL ) {
if ( ( F_85 ( V_2 -> V_18 -> V_132 ) ==
F_85 ( V_154 -> V_132 ) ) &&
( V_2 -> V_18 -> V_156 == V_154 -> V_156 ) )
break;
}
if ( V_154 ) {
F_86 ( V_154 ) ;
F_87 ( & V_2 -> V_18 -> V_19 , L_8
L_9 ) ;
return - V_139 ;
}
}
V_4 = F_80 ( V_2 , 1 ) ;
if ( V_4 ) {
F_70 ( & V_2 -> V_18 -> V_19 , L_10 ) ;
return V_4 ;
}
if ( V_2 -> V_18 -> V_55 == V_151 ||
V_2 -> V_18 -> V_55 == V_152 )
V_2 -> V_26 |= V_157 ;
return 0 ;
}
static void F_88 ( struct V_9 * V_10 , int V_140 )
{
T_5 V_141 ;
V_141 = F_89 ( V_10 -> V_158 + 0xC0 ) ;
if ( V_140 )
V_141 |= 0x01 ;
else
V_141 &= ~ 0x01 ;
F_90 ( V_141 , V_10 -> V_158 + 0xC0 ) ;
}
static int F_91 ( struct V_6 * V_7 )
{
if ( V_7 -> V_2 -> V_18 -> V_143 == 0 ) {
T_7 V_159 ;
V_159 = F_92 ( V_7 -> V_10 -> V_158 + V_160 ) ;
V_159 = ( V_159 & V_161 ) >>
V_162 ;
if ( V_159 < 0xAC )
V_7 -> V_10 -> V_26 |= V_163 ;
}
if ( V_7 -> V_2 -> V_18 -> V_55 == V_152 ) {
V_7 -> V_10 -> V_164 = V_165 | V_166 |
V_167 | V_168 |
V_169 ;
V_7 -> V_10 -> V_170 = V_165 | V_166 |
V_167 | V_168 ;
}
if ( V_7 -> V_2 -> V_18 -> V_55 == V_150 ||
V_7 -> V_2 -> V_18 -> V_55 == V_152 )
F_88 ( V_7 -> V_10 , 1 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_171 ;
return 0 ;
}
static void F_93 ( struct V_6 * V_7 , int V_172 )
{
if ( V_172 )
return;
if ( V_7 -> V_2 -> V_18 -> V_55 == V_150 ||
V_7 -> V_2 -> V_18 -> V_55 == V_152 )
F_88 ( V_7 -> V_10 , 0 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_18 -> V_55 == V_150 ||
V_2 -> V_18 -> V_55 == V_152 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_88 ( V_2 -> V_8 [ V_3 ] -> V_10 , 0 ) ;
}
F_6 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_4 , V_3 ;
if ( V_2 -> V_18 -> V_55 == V_150 ||
V_2 -> V_18 -> V_55 == V_152 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_88 ( V_2 -> V_8 [ V_3 ] -> V_10 , 1 ) ;
}
V_4 = F_80 ( V_2 , 1 ) ;
if ( V_4 ) {
F_70 ( & V_2 -> V_18 -> V_19 , L_10 ) ;
return V_4 ;
}
return F_9 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_18 -> V_173 & 0x0000FF ) == V_174 ) {
V_2 -> V_18 -> V_173 &= ~ 0x0000FF ;
V_2 -> V_18 -> V_173 |= V_175 ;
}
return 0 ;
}
static int F_97 ( struct V_6 * V_7 )
{
int V_176 , V_177 ;
T_5 V_178 = F_89 ( V_7 -> V_10 -> V_158 + V_179 ) ;
T_5 V_180 = F_89 ( V_7 -> V_10 -> V_158 + V_181 ) ;
F_87 ( & V_7 -> V_2 -> V_18 -> V_19 , L_11
L_12 ,
V_178 >> 4 , V_178 & 0xf ,
V_180 >> 4 , V_180 & 0xf ) ;
if ( V_180 >= 0x20 )
V_7 -> V_10 -> V_26 |= V_182 ;
F_90 ( V_183 , V_7 -> V_10 -> V_158 + V_184 ) ;
F_90 ( V_185 , V_7 -> V_10 -> V_158 + V_186 ) ;
F_48 ( 50 ) ;
V_176 = 10 ;
do {
V_177 = F_98 ( V_7 -> V_10 -> V_158 + V_187 ) ;
if ( V_177 & V_188 )
break;
F_48 ( 100 ) ;
} while ( -- V_176 );
if ( ! V_176 ) {
F_70 ( & V_7 -> V_2 -> V_18 -> V_19 ,
L_13 ) ;
F_90 ( 0 , V_7 -> V_10 -> V_158 + V_186 ) ;
return - V_139 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 -> V_143 == 0x10 )
V_2 -> V_26 |= V_189 ;
return 0 ;
}
static int F_100 ( struct V_6 * V_7 )
{
V_7 -> V_10 -> V_14 -> V_51 |= V_190 ;
return 0 ;
}
static void F_101 ( struct V_9 * V_10 )
{
unsigned int V_69 ;
V_69 = F_102 ( V_10 , V_191 ) ;
V_69 |= V_192 | V_193 ;
F_103 ( V_10 , V_69 , V_191 ) ;
V_69 = F_102 ( V_10 , V_191 ) ;
V_69 &= ~ V_193 ;
F_103 ( V_10 , V_69 , V_191 ) ;
}
static void F_104 ( struct V_153 * V_18 , T_5 V_194 )
{
unsigned int V_69 ;
F_105 ( V_18 , V_195 , & V_69 ) ;
V_69 &= ~ V_196 ;
V_69 |= ( V_197 | ( V_194 << 1 ) ) ;
F_106 ( V_18 , V_195 , V_69 ) ;
}
static void F_107 ( struct V_153 * V_18 )
{
unsigned int V_69 ;
F_105 ( V_18 , V_198 , & V_69 ) ;
V_69 |= V_199 ;
F_106 ( V_18 , V_198 , V_69 ) ;
}
static int F_108 ( struct V_9 * V_10 , T_3 V_200 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
struct V_153 * V_18 = V_7 -> V_2 -> V_18 ;
T_5 V_201 = 0 ;
T_5 V_202 = 0 ;
T_5 V_203 = 0 ;
T_5 V_204 , V_205 ;
F_101 ( V_10 ) ;
for ( V_205 = 0 ; V_205 < 12 ; V_205 ++ ) {
F_104 ( V_18 , V_205 ) ;
if ( F_109 ( V_10 -> V_14 , V_200 , NULL ) ) {
V_201 = 0 ;
F_17 ( V_206 ) ;
V_204 = V_207 | V_208 ;
F_47 ( V_10 , V_204 , V_209 ) ;
} else if ( ++ V_201 > V_202 ) {
V_202 = V_201 ;
V_203 = V_205 ;
}
}
if ( ! V_202 ) {
F_70 ( & V_18 -> V_19 , L_14 ) ;
return - V_210 ;
}
F_104 ( V_18 , V_203 - V_202 / 2 ) ;
F_107 ( V_18 ) ;
V_10 -> V_14 -> V_211 = 0 ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_153 * V_212 ;
enum V_213 V_214 ;
V_212 = F_84 ( V_215 ,
V_216 , NULL ) ;
if ( V_212 ) {
V_214 = V_217 ;
} else {
V_212 = F_84 ( V_215 ,
V_218 , NULL ) ;
if ( V_212 ) {
if ( V_212 -> V_143 < 0x51 )
V_214 = V_219 ;
else
V_214 = V_220 ;
} else {
V_214 = V_221 ;
}
}
if ( V_214 == V_217 || V_214 == V_219 )
V_2 -> V_136 |= V_222 ;
return 0 ;
}
static int F_111 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
struct V_153 * V_18 ;
V_7 = F_52 ( V_10 ) ;
V_18 = V_7 -> V_2 -> V_18 ;
if ( ( ( V_18 -> V_173 & 0xFFFF00 ) == ( V_223 << 8 ) ) &&
( ( V_18 -> V_173 & 0x0000FF ) != V_175 ) &&
( V_10 -> V_84 & V_224 ) ) {
F_31 ( & V_18 -> V_19 , L_15
L_16 ) ;
}
F_112 ( V_18 ) ;
return 0 ;
}
static void F_113 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
int V_225 = V_7 -> V_225 ;
if ( ! F_25 ( V_225 ) )
return;
F_114 ( V_225 , 0 ) ;
F_48 ( 10 ) ;
F_114 ( V_225 , 1 ) ;
F_49 ( 300 , 1000 ) ;
}
static void F_115 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_52 ( V_10 ) ;
if ( V_7 -> V_107 )
V_7 -> V_107 ( V_10 ) ;
}
static int F_116 ( struct V_55 * V_19 )
{
struct V_153 * V_18 = F_117 ( V_19 ) ;
struct V_1 * V_2 = F_118 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_227 )
return V_2 -> V_226 -> V_227 ( V_2 ) ;
return F_8 ( V_2 ) ;
}
static int F_119 ( struct V_55 * V_19 )
{
struct V_153 * V_18 = F_117 ( V_19 ) ;
struct V_1 * V_2 = F_118 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_228 )
return V_2 -> V_226 -> V_228 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_120 ( struct V_55 * V_19 )
{
struct V_153 * V_18 = F_117 ( V_19 ) ;
struct V_1 * V_2 = F_118 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_229 )
return V_2 -> V_226 -> V_229 ( V_2 ) ;
return F_10 ( V_2 ) ;
}
static int F_121 ( struct V_55 * V_19 )
{
struct V_153 * V_18 = F_117 ( V_19 ) ;
struct V_1 * V_2 = F_118 ( V_18 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_230 )
return V_2 -> V_226 -> V_230 ( V_2 ) ;
return F_13 ( V_2 ) ;
}
static struct V_6 * F_122 (
struct V_153 * V_18 , struct V_1 * V_2 , int V_231 ,
int V_232 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_4 , V_233 = V_231 + V_232 ;
T_4 V_234 = V_2 -> V_226 ? V_2 -> V_226 -> V_234 : 0 ;
if ( ! ( F_123 ( V_18 , V_233 ) & V_235 ) ) {
F_70 ( & V_18 -> V_19 , L_17 , V_233 ) ;
return F_124 ( - V_139 ) ;
}
if ( F_125 ( V_18 , V_233 ) < 0x100 ) {
F_70 ( & V_18 -> V_19 , L_18
L_19 ) ;
}
if ( ( V_18 -> V_173 & 0x0000FF ) == V_174 ) {
F_70 ( & V_18 -> V_19 , L_20 ) ;
return F_124 ( - V_139 ) ;
}
if ( ( V_18 -> V_173 & 0x0000FF ) > V_174 ) {
F_70 ( & V_18 -> V_19 , L_21 ) ;
return F_124 ( - V_139 ) ;
}
V_10 = F_126 ( & V_18 -> V_19 , sizeof( * V_7 ) + V_234 ) ;
if ( F_127 ( V_10 ) ) {
F_70 ( & V_18 -> V_19 , L_22 ) ;
return F_128 ( V_10 ) ;
}
V_7 = F_52 ( V_10 ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_225 = - V_44 ;
V_7 -> V_43 = - V_44 ;
V_7 -> V_120 = - 1 ;
if ( * V_236 )
V_7 -> V_237 = V_236 ( V_18 , V_232 ) ;
if ( V_7 -> V_237 ) {
if ( V_7 -> V_237 -> V_238 ) {
V_4 = V_7 -> V_237 -> V_238 ( V_7 -> V_237 ) ;
if ( V_4 ) {
F_70 ( & V_18 -> V_19 , L_23 ) ;
goto free;
}
}
V_7 -> V_225 = V_7 -> V_237 -> V_225 ;
V_7 -> V_43 = V_7 -> V_237 -> V_43 ;
}
V_10 -> V_239 = L_24 ;
V_10 -> V_240 = V_2 -> V_226 && V_2 -> V_226 -> V_240 ?
V_2 -> V_226 -> V_240 :
& V_241 ;
V_10 -> V_26 = V_2 -> V_26 ;
V_10 -> V_136 = V_2 -> V_136 ;
V_10 -> V_38 = V_18 -> V_38 ;
V_4 = F_129 ( V_18 , F_130 ( V_233 ) , F_44 ( V_10 -> V_14 ) ) ;
if ( V_4 ) {
F_70 ( & V_18 -> V_19 , L_25 ) ;
goto V_242;
}
V_10 -> V_158 = F_131 ( V_18 ) [ V_233 ] ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_243 ) {
V_4 = V_2 -> V_226 -> V_243 ( V_7 ) ;
if ( V_4 )
goto V_242;
}
if ( F_25 ( V_7 -> V_225 ) ) {
if ( ! F_26 ( & V_18 -> V_19 , V_7 -> V_225 , L_26 ) ) {
F_132 ( V_7 -> V_225 , 1 ) ;
V_7 -> V_10 -> V_14 -> V_28 |= V_103 ;
V_7 -> V_107 = F_113 ;
} else {
F_31 ( & V_18 -> V_19 , L_27 ) ;
V_7 -> V_225 = - V_44 ;
}
}
V_10 -> V_14 -> V_244 = V_20 | V_17 ;
V_10 -> V_14 -> V_232 = V_232 ;
V_10 -> V_14 -> V_51 |= V_245 ;
if ( V_7 -> V_120 >= 0 ) {
V_4 = F_133 ( V_10 -> V_14 , NULL , V_7 -> V_120 ,
V_7 -> V_121 , 0 , NULL ) ;
if ( V_4 == - V_246 )
goto remove;
if ( V_4 ) {
F_31 ( & V_18 -> V_19 , L_28 ) ;
V_7 -> V_120 = - 1 ;
}
}
if ( V_2 -> V_226 && V_2 -> V_226 -> V_247 )
V_4 = V_2 -> V_226 -> V_247 ( V_7 ) ;
else
V_4 = F_134 ( V_10 ) ;
if ( V_4 )
goto remove;
F_24 ( V_7 ) ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_248 &&
! F_25 ( V_7 -> V_43 ) && V_7 -> V_120 < 0 )
V_2 -> V_249 = false ;
return V_7 ;
remove:
if ( V_2 -> V_226 && V_2 -> V_226 -> V_250 )
V_2 -> V_226 -> V_250 ( V_7 , 0 ) ;
V_242:
if ( V_7 -> V_237 && V_7 -> V_237 -> V_242 )
V_7 -> V_237 -> V_242 ( V_7 -> V_237 ) ;
free:
F_135 ( V_10 ) ;
return F_124 ( V_4 ) ;
}
static void F_136 ( struct V_6 * V_7 )
{
int V_172 ;
T_3 V_141 ;
F_32 ( V_7 ) ;
V_172 = 0 ;
V_141 = F_92 ( V_7 -> V_10 -> V_158 + V_251 ) ;
if ( V_141 == ( T_3 ) - 1 )
V_172 = 1 ;
F_137 ( V_7 -> V_10 , V_172 ) ;
if ( V_7 -> V_2 -> V_226 && V_7 -> V_2 -> V_226 -> V_250 )
V_7 -> V_2 -> V_226 -> V_250 ( V_7 , V_172 ) ;
if ( V_7 -> V_237 && V_7 -> V_237 -> V_242 )
V_7 -> V_237 -> V_242 ( V_7 -> V_237 ) ;
F_135 ( V_7 -> V_10 ) ;
}
static void F_138 ( struct V_55 * V_19 )
{
F_139 ( V_19 , 1 ) ;
F_140 ( V_19 , 50 ) ;
F_141 ( V_19 ) ;
F_142 ( V_19 ) ;
F_143 ( V_19 ) ;
}
static void F_144 ( struct V_55 * V_19 )
{
F_145 ( V_19 ) ;
F_146 ( V_19 ) ;
}
static int F_147 ( struct V_153 * V_18 ,
const struct V_252 * V_253 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_5 V_8 , V_231 ;
int V_4 , V_3 ;
F_148 ( V_18 == NULL ) ;
F_148 ( V_253 == NULL ) ;
F_87 ( & V_18 -> V_19 , L_29 ,
( int ) V_18 -> V_254 , ( int ) V_18 -> V_55 , ( int ) V_18 -> V_143 ) ;
V_4 = F_81 ( V_18 , V_255 , & V_8 ) ;
if ( V_4 )
return V_4 ;
V_8 = F_149 ( V_8 ) + 1 ;
F_150 ( & V_18 -> V_19 , L_30 , V_8 ) ;
if ( V_8 == 0 )
return - V_139 ;
F_148 ( V_8 > V_256 ) ;
V_4 = F_81 ( V_18 , V_255 , & V_231 ) ;
if ( V_4 )
return V_4 ;
V_231 &= V_257 ;
if ( V_231 > 5 ) {
F_70 ( & V_18 -> V_19 , L_31 ) ;
return - V_139 ;
}
V_4 = F_151 ( V_18 ) ;
if ( V_4 )
return V_4 ;
V_2 = F_152 ( & V_18 -> V_19 , sizeof( * V_2 ) , V_258 ) ;
if ( ! V_2 )
return - V_259 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_226 = ( const struct V_260 * ) V_253 -> V_261 ;
if ( V_2 -> V_226 ) {
V_2 -> V_26 = V_2 -> V_226 -> V_26 ;
V_2 -> V_136 = V_2 -> V_226 -> V_136 ;
V_2 -> V_249 = V_2 -> V_226 -> V_249 ;
}
V_2 -> V_5 = V_8 ;
V_2 -> V_11 = true ;
V_2 -> V_22 = true ;
F_153 ( V_18 , V_2 ) ;
if ( V_2 -> V_226 && V_2 -> V_226 -> V_262 ) {
V_4 = V_2 -> V_226 -> V_262 ( V_2 ) ;
if ( V_4 )
return V_4 ;
}
V_8 = V_2 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
V_7 = F_122 ( V_18 , V_2 , V_231 , V_3 ) ;
if ( F_127 ( V_7 ) ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_136 ( V_2 -> V_8 [ V_3 ] ) ;
return F_154 ( V_7 ) ;
}
V_2 -> V_8 [ V_3 ] = V_7 ;
}
if ( V_2 -> V_249 )
F_138 ( & V_18 -> V_19 ) ;
return 0 ;
}
static void F_155 ( struct V_153 * V_18 )
{
int V_3 ;
struct V_1 * V_2 = F_118 ( V_18 ) ;
if ( V_2 -> V_249 )
F_144 ( & V_18 -> V_19 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_136 ( V_2 -> V_8 [ V_3 ] ) ;
}
