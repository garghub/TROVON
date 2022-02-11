static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 == V_5 ||
V_2 -> V_3 -> V_4 == V_6 )
V_2 -> V_7 |= V_8 ;
return 0 ;
}
static int F_2 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_12 =
( ( 0x21 << V_13 )
& V_14 ) |
( ( 0x21 << V_15 )
& V_16 ) |
V_17 |
V_18 |
V_19 |
V_20 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( 500 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_23 = 1 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static T_1 F_8 ( int V_24 , void * V_25 )
{
struct V_9 * V_10 = V_25 ;
struct V_26 * V_11 = V_10 -> V_11 ;
F_9 ( V_11 -> V_21 , F_10 ( 200 ) ) ;
return V_27 ;
}
static void F_11 ( struct V_9 * V_10 )
{
int V_28 , V_24 , V_29 = V_10 -> V_30 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_32 = - V_31 ;
if ( ! F_12 ( V_29 ) )
return;
V_28 = F_13 ( V_29 , L_1 ) ;
if ( V_28 < 0 )
goto V_33;
V_28 = F_14 ( V_29 ) ;
if ( V_28 < 0 )
goto V_34;
V_24 = F_15 ( V_29 ) ;
if ( V_24 < 0 )
goto V_34;
V_28 = F_16 ( V_24 , F_8 , V_35 |
V_36 , L_1 , V_10 ) ;
if ( V_28 )
goto V_34;
V_10 -> V_30 = V_29 ;
V_10 -> V_32 = V_24 ;
return;
V_34:
F_17 ( V_29 ) ;
V_33:
F_18 ( & V_10 -> V_2 -> V_3 -> V_37 , L_2 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_32 >= 0 )
F_20 ( V_10 -> V_32 , V_10 ) ;
if ( F_12 ( V_10 -> V_30 ) )
F_17 ( V_10 -> V_30 ) ;
}
static inline void F_11 ( struct V_9 * V_10 )
{
}
static inline void F_19 ( struct V_9 * V_10 )
{
}
static int F_21 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_40 |
V_41 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static void F_23 ( struct V_26 * V_11 )
{
T_2 V_43 ;
V_43 = F_24 ( V_11 , V_44 ) ;
V_43 |= 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_26 ( 9 ) ;
V_43 &= ~ 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_27 ( 300 , 1000 ) ;
}
static int F_28 ( struct V_26 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 ,
int V_48 , int V_49 , int * V_50 )
{
int V_51 ;
if ( V_52 > 0 )
V_51 = V_52 & 0xf ;
else
V_51 = 0 ;
if ( ( F_29 ( V_51 ) & V_49 ) == 0 )
V_51 = 0 ;
return V_51 ;
}
static void F_30 ( struct V_26 * V_11 )
{
T_3 V_53 , V_54 , V_55 ;
T_4 V_56 ;
if ( V_52 )
return;
V_52 = - 1 ;
V_56 = F_31 ( V_11 , V_57 ) & 0x7 ;
if ( V_56 != 3 && V_56 != 5 )
return;
V_53 = F_32 ( V_11 , V_58 ) ;
if ( V_53 & 0x3 )
return;
F_33 ( V_11 , 0x007f0023 , V_59 ) ;
F_33 ( V_11 , 0 , V_60 ) ;
F_34 ( V_11 , 0x10 , V_61 ) ;
F_25 ( V_11 , 0xe , V_62 ) ;
F_34 ( V_11 , 512 , V_63 ) ;
F_34 ( V_11 , 1 , V_64 ) ;
F_33 ( V_11 , 0 , V_65 ) ;
F_34 ( V_11 , 0x83b , V_66 ) ;
for ( V_54 = 0 ; V_54 < 1000 ; V_54 ++ ) {
V_53 = F_32 ( V_11 , V_67 ) ;
if ( V_53 & 0xffff8000 )
return;
if ( V_53 & 0x20 )
break;
F_26 ( 1 ) ;
}
V_53 = F_32 ( V_11 , V_58 ) ;
if ( ! ( V_53 & 0x800 ) )
return;
for ( V_54 = 0 ; V_54 < 47 ; V_54 ++ )
V_53 = F_32 ( V_11 , V_68 ) ;
V_55 = V_53 & 0xf00 ;
if ( V_55 != 0x200 && V_55 != 0x300 )
return;
V_52 = 0x10 | ( ( V_53 >> 12 ) & 0xf ) ;
}
static int F_35 ( struct V_69 * V_21 )
{
int V_70 = F_36 ( V_21 ) ;
struct V_26 * V_11 = F_37 ( V_21 ) ;
unsigned long V_71 ;
int V_72 = 0 ;
if ( ! V_70 )
return 0 ;
F_38 ( & V_11 -> V_73 , V_71 ) ;
if ( V_11 -> V_71 & V_74 )
goto V_33;
V_72 = ! ! ( F_32 ( V_11 , V_58 ) & V_75 ) ;
V_33:
F_39 ( & V_11 -> V_73 , V_71 ) ;
return V_72 ;
}
static int F_40 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_76 | V_77 |
V_78 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_41 ;
V_10 -> V_79 = F_23 ;
if ( V_10 -> V_2 -> V_3 -> V_80 == V_81 )
V_10 -> V_11 -> V_82 = 1000 ;
if ( V_10 -> V_2 -> V_3 -> V_80 == V_83 ) {
F_30 ( V_10 -> V_11 ) ;
V_10 -> V_84 = F_28 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 |
V_78 ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_78 ;
V_10 -> V_85 = NULL ;
V_10 -> V_86 = 0 ;
V_10 -> V_87 = true ;
if ( V_10 -> V_2 -> V_3 -> V_80 == V_88 ||
V_10 -> V_2 -> V_3 -> V_80 == V_89 ||
V_10 -> V_2 -> V_3 -> V_80 == V_90 ) {
V_10 -> V_11 -> V_91 . V_92 = F_35 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_93 ;
}
return 0 ;
}
static int F_43 ( struct V_9 * V_10 )
{
if ( ( F_44 ( V_10 -> V_2 -> V_3 -> V_94 ) != V_95 ) &&
( F_44 ( V_10 -> V_2 -> V_3 -> V_94 ) != V_96 ) )
return - V_97 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_77 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , int V_98 )
{
T_2 V_99 ;
int V_72 ;
V_72 = F_46 ( V_2 -> V_3 , 0xAE , & V_99 ) ;
if ( V_72 )
return V_72 ;
if ( V_98 )
V_99 |= 0x47 ;
else
V_99 &= ~ 0x47 ;
return F_47 ( V_2 -> V_3 , 0xAE , V_99 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_72 ;
T_4 V_100 = 0 ;
if ( V_2 -> V_3 -> V_101 == 0 ) {
V_2 -> V_7 |= V_102 |
V_103 |
V_104 |
V_105 |
V_106 ;
}
if ( V_2 -> V_3 -> V_80 == V_107 )
V_100 = V_108 ;
else if ( V_2 -> V_3 -> V_80 == V_109 )
V_100 = V_110 ;
if ( V_100 ) {
struct V_111 * V_112 ;
V_112 = NULL ;
while ( ( V_112 = F_49 ( V_113 ,
V_100 , V_112 ) ) != NULL ) {
if ( ( F_50 ( V_2 -> V_3 -> V_94 ) ==
F_50 ( V_112 -> V_94 ) ) &&
( V_2 -> V_3 -> V_114 == V_112 -> V_114 ) )
break;
}
if ( V_112 ) {
F_51 ( V_112 ) ;
F_52 ( & V_2 -> V_3 -> V_37 , L_3
L_4 ) ;
return - V_97 ;
}
}
V_72 = F_45 ( V_2 , 1 ) ;
if ( V_72 ) {
F_53 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_72 ;
}
if ( V_2 -> V_3 -> V_80 == V_109 ||
V_2 -> V_3 -> V_80 == V_110 )
V_2 -> V_7 |= V_115 ;
return 0 ;
}
static void F_54 ( struct V_26 * V_11 , int V_98 )
{
T_2 V_99 ;
V_99 = F_55 ( V_11 -> V_116 + 0xC0 ) ;
if ( V_98 )
V_99 |= 0x01 ;
else
V_99 &= ~ 0x01 ;
F_56 ( V_99 , V_11 -> V_116 + 0xC0 ) ;
}
static int F_57 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_101 == 0 ) {
T_4 V_117 ;
V_117 = F_58 ( V_10 -> V_11 -> V_116 + V_118 ) ;
V_117 = ( V_117 & V_119 ) >>
V_120 ;
if ( V_117 < 0xAC )
V_10 -> V_11 -> V_7 |= V_121 ;
}
if ( V_10 -> V_2 -> V_3 -> V_80 == V_110 ) {
V_10 -> V_11 -> V_122 = V_123 | V_124 |
V_125 | V_126 |
V_127 ;
V_10 -> V_11 -> V_128 = V_123 | V_124 |
V_125 | V_126 ;
}
if ( V_10 -> V_2 -> V_3 -> V_80 == V_108 ||
V_10 -> V_2 -> V_3 -> V_80 == V_110 )
F_54 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_129 ;
return 0 ;
}
static void F_59 ( struct V_9 * V_10 , int V_130 )
{
if ( V_130 )
return;
if ( V_10 -> V_2 -> V_3 -> V_80 == V_108 ||
V_10 -> V_2 -> V_3 -> V_80 == V_110 )
F_54 ( V_10 -> V_11 , 0 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_54 ;
if ( V_2 -> V_3 -> V_80 == V_108 ||
V_2 -> V_3 -> V_80 == V_110 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_54 ( V_2 -> V_131 [ V_54 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_72 , V_54 ;
if ( V_2 -> V_3 -> V_80 == V_108 ||
V_2 -> V_3 -> V_80 == V_110 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_54 ( V_2 -> V_131 [ V_54 ] -> V_11 , 1 ) ;
}
V_72 = F_45 ( V_2 , 1 ) ;
if ( V_72 ) {
F_53 ( & V_2 -> V_3 -> V_37 , L_5 ) ;
return V_72 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_132 & 0x0000FF ) == V_133 ) {
V_2 -> V_3 -> V_132 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_132 |= V_134 ;
}
return 0 ;
}
static int F_63 ( struct V_9 * V_10 )
{
int V_135 , V_136 ;
T_2 V_137 = F_55 ( V_10 -> V_11 -> V_116 + V_138 ) ;
T_2 V_139 = F_55 ( V_10 -> V_11 -> V_116 + V_140 ) ;
F_52 ( & V_10 -> V_2 -> V_3 -> V_37 , L_6
L_7 ,
V_137 >> 4 , V_137 & 0xf ,
V_139 >> 4 , V_139 & 0xf ) ;
if ( V_139 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_141 ;
F_56 ( V_142 , V_10 -> V_11 -> V_116 + V_143 ) ;
F_56 ( V_144 , V_10 -> V_11 -> V_116 + V_145 ) ;
F_26 ( 50 ) ;
V_135 = 10 ;
do {
V_136 = F_64 ( V_10 -> V_11 -> V_116 + V_146 ) ;
if ( V_136 & V_147 )
break;
F_26 ( 100 ) ;
} while ( -- V_135 );
if ( ! V_135 ) {
F_53 ( & V_10 -> V_2 -> V_3 -> V_37 ,
L_8 ) ;
F_56 ( 0 , V_10 -> V_11 -> V_116 + V_145 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_101 == 0x10 )
V_2 -> V_7 |= V_148 ;
return 0 ;
}
static int F_66 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_39 |= V_149 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_111 * V_150 ;
enum V_151 V_152 ;
V_150 = F_49 ( V_153 ,
V_154 , NULL ) ;
if ( V_150 ) {
V_152 = V_155 ;
} else {
V_150 = F_49 ( V_153 ,
V_156 , NULL ) ;
if ( V_150 ) {
if ( V_150 -> V_101 < 0x51 )
V_152 = V_157 ;
else
V_152 = V_158 ;
} else {
V_152 = V_159 ;
}
}
if ( ( V_152 == V_155 ) || ( V_152 == V_157 ) ) {
V_2 -> V_160 |= V_161 ;
V_2 -> V_160 |= V_162 ;
}
return 0 ;
}
static int F_68 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_111 * V_3 ;
V_10 = F_69 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_132 & 0xFFFF00 ) == ( V_163 << 8 ) ) &&
( ( V_3 -> V_132 & 0x0000FF ) != V_134 ) &&
( V_11 -> V_71 & V_164 ) ) {
F_18 ( & V_3 -> V_37 , L_9
L_10 ) ;
}
F_70 ( V_3 ) ;
return 0 ;
}
static void F_71 ( struct V_26 * V_11 , int V_165 )
{
T_2 V_166 ;
V_166 = F_24 ( V_11 , V_167 ) ;
switch ( V_165 ) {
case V_168 :
V_166 |= V_169 ;
V_166 &= ~ V_170 ;
break;
case V_171 :
V_166 |= V_170 ;
V_166 &= ~ V_169 ;
break;
default:
V_166 &= ~ ( V_169 | V_170 ) ;
break;
}
F_25 ( V_11 , V_166 , V_167 ) ;
}
static void F_72 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_69 ( V_11 ) ;
int V_172 = V_10 -> V_172 ;
if ( ! F_12 ( V_172 ) )
return;
F_73 ( V_172 , 0 ) ;
F_26 ( 10 ) ;
F_73 ( V_172 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_74 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_69 ( V_11 ) ;
if ( V_10 -> V_79 )
V_10 -> V_79 ( V_11 ) ;
}
static int F_75 ( struct V_26 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 , int V_48 ,
int V_49 , int * V_50 )
{
struct V_9 * V_10 = F_69 ( V_11 ) ;
if ( ! V_10 -> V_84 )
return 0 ;
return V_10 -> V_84 ( V_11 , V_46 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
static int F_76 ( struct V_80 * V_37 )
{
struct V_111 * V_3 = F_77 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_5 V_173 ;
T_5 V_174 = 0 ;
int V_54 , V_72 ;
V_2 = F_78 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_131 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_79 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_175;
V_173 = V_10 -> V_11 -> V_21 -> V_174 ;
if ( V_173 & V_176 )
F_80 ( V_10 -> V_11 ) ;
V_174 |= V_173 ;
}
if ( V_2 -> V_177 && V_2 -> V_177 -> V_178 ) {
V_72 = V_2 -> V_177 -> V_178 ( V_2 ) ;
if ( V_72 )
goto V_175;
}
if ( V_174 & V_179 ) {
if ( V_174 & V_176 )
F_81 ( V_37 , true ) ;
else
F_81 ( V_37 , false ) ;
} else
F_81 ( V_37 , false ) ;
return 0 ;
V_175:
while ( -- V_54 >= 0 )
F_82 ( V_2 -> V_131 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_83 ( struct V_80 * V_37 )
{
struct V_111 * V_3 = F_77 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_78 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_177 && V_2 -> V_177 -> V_180 ) {
V_72 = V_2 -> V_177 -> V_180 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_131 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_82 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_84 ( struct V_80 * V_37 )
{
struct V_111 * V_3 = F_77 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_78 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_131 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_85 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_181;
}
if ( V_2 -> V_177 && V_2 -> V_177 -> V_178 ) {
V_72 = V_2 -> V_177 -> V_178 ( V_2 ) ;
if ( V_72 )
goto V_181;
}
return 0 ;
V_181:
while ( -- V_54 >= 0 )
F_86 ( V_2 -> V_131 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_87 ( struct V_80 * V_37 )
{
struct V_111 * V_3 = F_77 ( V_37 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_78 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_177 && V_2 -> V_177 -> V_180 ) {
V_72 = V_2 -> V_177 -> V_180 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_131 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_86 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static struct V_9 * F_88 (
struct V_111 * V_3 , struct V_1 * V_2 , int V_182 ,
int V_183 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_72 , V_184 = V_182 + V_183 ;
if ( ! ( F_89 ( V_3 , V_184 ) & V_185 ) ) {
F_53 ( & V_3 -> V_37 , L_11 , V_184 ) ;
return F_90 ( - V_97 ) ;
}
if ( F_91 ( V_3 , V_184 ) < 0x100 ) {
F_53 ( & V_3 -> V_37 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_132 & 0x0000FF ) == V_133 ) {
F_53 ( & V_3 -> V_37 , L_14 ) ;
return F_90 ( - V_97 ) ;
}
if ( ( V_3 -> V_132 & 0x0000FF ) > V_133 ) {
F_53 ( & V_3 -> V_37 , L_15 ) ;
return F_90 ( - V_97 ) ;
}
V_11 = F_92 ( & V_3 -> V_37 , sizeof( struct V_9 ) ) ;
if ( F_93 ( V_11 ) ) {
F_53 ( & V_3 -> V_37 , L_16 ) ;
return F_94 ( V_11 ) ;
}
V_10 = F_69 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_186 = V_184 ;
V_10 -> V_172 = - V_31 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_86 = - 1 ;
if ( * V_187 )
V_10 -> V_188 = V_187 ( V_3 , V_183 ) ;
if ( V_10 -> V_188 ) {
if ( V_10 -> V_188 -> V_189 ) {
V_72 = V_10 -> V_188 -> V_189 ( V_10 -> V_188 ) ;
if ( V_72 ) {
F_53 ( & V_3 -> V_37 , L_17 ) ;
goto free;
}
}
V_10 -> V_172 = V_10 -> V_188 -> V_172 ;
V_10 -> V_30 = V_10 -> V_188 -> V_30 ;
}
V_11 -> V_190 = L_18 ;
V_11 -> V_191 = & V_192 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_160 = V_2 -> V_160 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_72 = F_95 ( V_3 , V_184 , F_96 ( V_11 -> V_21 ) ) ;
if ( V_72 ) {
F_53 ( & V_3 -> V_37 , L_19 ) ;
goto V_193;
}
V_11 -> V_116 = F_97 ( V_3 , V_184 ) ;
if ( ! V_11 -> V_116 ) {
F_53 ( & V_3 -> V_37 , L_20 ) ;
V_72 = - V_194 ;
goto V_195;
}
if ( V_2 -> V_177 && V_2 -> V_177 -> V_196 ) {
V_72 = V_2 -> V_177 -> V_196 ( V_10 ) ;
if ( V_72 )
goto V_197;
}
if ( F_12 ( V_10 -> V_172 ) ) {
if ( ! F_13 ( V_10 -> V_172 , L_21 ) ) {
F_98 ( V_10 -> V_172 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_76 ;
V_10 -> V_79 = F_72 ;
} else {
F_18 ( & V_3 -> V_37 , L_22 ) ;
V_10 -> V_172 = - V_31 ;
}
}
V_11 -> V_21 -> V_198 = V_179 | V_176 ;
V_11 -> V_21 -> V_183 = V_183 ;
V_11 -> V_21 -> V_39 |= V_199 ;
if ( V_10 -> V_86 >= 0 &&
F_99 ( V_11 -> V_21 , V_10 -> V_85 , V_10 -> V_86 ,
V_10 -> V_87 , 0 , NULL ) ) {
F_18 ( & V_3 -> V_37 , L_23 ) ;
V_10 -> V_86 = - 1 ;
}
V_72 = F_100 ( V_11 ) ;
if ( V_72 )
goto remove;
F_11 ( V_10 ) ;
if ( V_2 -> V_177 && V_2 -> V_177 -> V_200 &&
! F_12 ( V_10 -> V_30 ) && V_10 -> V_86 < 0 )
V_2 -> V_201 = false ;
return V_10 ;
remove:
if ( F_12 ( V_10 -> V_172 ) )
F_17 ( V_10 -> V_172 ) ;
if ( V_2 -> V_177 && V_2 -> V_177 -> V_202 )
V_2 -> V_177 -> V_202 ( V_10 , 0 ) ;
V_197:
F_101 ( V_11 -> V_116 ) ;
V_195:
F_102 ( V_3 , V_184 ) ;
V_193:
if ( V_10 -> V_188 && V_10 -> V_188 -> V_193 )
V_10 -> V_188 -> V_193 ( V_10 -> V_188 ) ;
free:
F_103 ( V_11 ) ;
return F_90 ( V_72 ) ;
}
static void F_104 ( struct V_9 * V_10 )
{
int V_130 ;
T_3 V_99 ;
F_19 ( V_10 ) ;
V_130 = 0 ;
V_99 = F_58 ( V_10 -> V_11 -> V_116 + V_67 ) ;
if ( V_99 == ( T_3 ) - 1 )
V_130 = 1 ;
F_105 ( V_10 -> V_11 , V_130 ) ;
if ( F_12 ( V_10 -> V_172 ) )
F_17 ( V_10 -> V_172 ) ;
if ( V_10 -> V_2 -> V_177 && V_10 -> V_2 -> V_177 -> V_202 )
V_10 -> V_2 -> V_177 -> V_202 ( V_10 , V_130 ) ;
if ( V_10 -> V_188 && V_10 -> V_188 -> V_193 )
V_10 -> V_188 -> V_193 ( V_10 -> V_188 ) ;
F_102 ( V_10 -> V_2 -> V_3 , V_10 -> V_186 ) ;
F_103 ( V_10 -> V_11 ) ;
}
static void F_106 ( struct V_80 * V_37 )
{
F_107 ( V_37 , 1 ) ;
F_108 ( V_37 , 50 ) ;
F_109 ( V_37 ) ;
F_110 ( V_37 ) ;
F_111 ( V_37 ) ;
}
static void F_112 ( struct V_80 * V_37 )
{
F_113 ( V_37 ) ;
F_114 ( V_37 ) ;
}
static int F_115 ( struct V_111 * V_3 ,
const struct V_203 * V_204 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_131 , V_182 ;
int V_72 , V_54 ;
F_116 ( V_3 == NULL ) ;
F_116 ( V_204 == NULL ) ;
F_52 ( & V_3 -> V_37 , L_24 ,
( int ) V_3 -> V_205 , ( int ) V_3 -> V_80 , ( int ) V_3 -> V_101 ) ;
V_72 = F_46 ( V_3 , V_206 , & V_131 ) ;
if ( V_72 )
return V_72 ;
V_131 = F_117 ( V_131 ) + 1 ;
F_118 ( & V_3 -> V_37 , L_25 , V_131 ) ;
if ( V_131 == 0 )
return - V_97 ;
F_116 ( V_131 > V_207 ) ;
V_72 = F_46 ( V_3 , V_206 , & V_182 ) ;
if ( V_72 )
return V_72 ;
V_182 &= V_208 ;
if ( V_182 > 5 ) {
F_53 ( & V_3 -> V_37 , L_26 ) ;
return - V_97 ;
}
V_72 = F_119 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_2 = F_120 ( & V_3 -> V_37 , sizeof( * V_2 ) , V_209 ) ;
if ( ! V_2 )
return - V_194 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_177 = ( const struct V_210 * ) V_204 -> V_211 ;
if ( V_2 -> V_177 ) {
V_2 -> V_7 = V_2 -> V_177 -> V_7 ;
V_2 -> V_160 = V_2 -> V_177 -> V_160 ;
V_2 -> V_201 = V_2 -> V_177 -> V_201 ;
}
V_2 -> V_23 = V_131 ;
F_121 ( V_3 , V_2 ) ;
if ( V_2 -> V_177 && V_2 -> V_177 -> V_212 ) {
V_72 = V_2 -> V_177 -> V_212 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
V_131 = V_2 -> V_23 ;
for ( V_54 = 0 ; V_54 < V_131 ; V_54 ++ ) {
V_10 = F_88 ( V_3 , V_2 , V_182 , V_54 ) ;
if ( F_93 ( V_10 ) ) {
for ( V_54 -- ; V_54 >= 0 ; V_54 -- )
F_104 ( V_2 -> V_131 [ V_54 ] ) ;
return F_122 ( V_10 ) ;
}
V_2 -> V_131 [ V_54 ] = V_10 ;
}
if ( V_2 -> V_201 )
F_106 ( & V_3 -> V_37 ) ;
return 0 ;
}
static void F_123 ( struct V_111 * V_3 )
{
int V_54 ;
struct V_1 * V_2 = F_78 ( V_3 ) ;
if ( V_2 -> V_201 )
F_112 ( & V_3 -> V_37 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_104 ( V_2 -> V_131 [ V_54 ] ) ;
}
