void F_1 ( struct V_1 * V_2 , char * V_3 )
{
unsigned long V_4 , V_5 ;
if ( ! V_6 )
return;
F_2 ( V_7 , V_8 , 0 ) ;
F_2 ( V_7 , V_8 , V_8 ) ;
V_4 = F_3 ( V_9 >> 2 ) & 0xfffffff ;
V_5 = F_3 ( V_10 >> 2 ) & 0xfffffff ;
F_4 ( V_11
L_1 ,
V_2 -> V_12 , V_4 , ( ~ V_4 ) & V_5 , V_4 & V_5 , V_3 ) ;
}
void F_5 ( struct V_1 * V_2 , int V_13 , int V_14 )
{
T_1 V_15 , V_16 ;
V_15 = 1 << V_13 ;
switch ( V_14 ) {
case 0 :
case 1 : F_6 ( L_2 , V_13 , V_14 ) ;
if ( V_15 & 0x00c00000 )
F_2 ( V_17 , 0x0f , 0x00 ) ;
if ( V_14 )
V_16 = V_15 ;
else
V_16 = 0 ;
F_7 ( V_9 >> 2 , V_15 , V_15 ) ;
F_7 ( V_10 >> 2 , V_15 , V_16 ) ;
break;
case 3 :
F_6 ( L_3 , V_13 ) ;
F_7 ( V_9 >> 2 , V_15 , 0 ) ;
break;
}
}
static void F_8 ( struct V_18 * V_19 ) {
struct V_1 * V_2 = F_9 ( V_19 , struct V_1 , V_20 ) ;
if ( F_10 ( V_2 ) )
F_11 ( L_4 ) ;
if ( F_12 ( V_2 ) )
F_11 ( L_5 ) ;
if ( V_21 ) {
if ( V_2 -> V_22 -> V_23 != V_24 )
F_11 ( L_6 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_20 , F_8 ) ;
F_15 ( & V_2 -> V_20 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_20 ) ;
}
static int F_18 ( int V_25 )
{
V_25 = F_19 ( V_25 ) ;
V_25 += V_26 ;
V_25 /= 4096 ;
return V_25 ;
}
int F_20 ( unsigned int V_25 , unsigned int V_27 )
{
unsigned int V_28 ;
V_28 = 1024 / F_18 ( V_25 ) ;
if ( V_27 > V_28 )
V_27 = V_28 ;
return V_27 ;
}
int F_21 ( struct V_29 * V_30 )
{
return F_18 ( V_30 -> V_31 . V_32 ) * V_30 -> V_31 . V_33 ;
}
unsigned long F_22 ( struct V_29 * V_30 )
{
unsigned long V_34 ;
struct V_35 * V_36 = F_23 ( & V_30 -> V_31 ) ;
V_34 = F_21 ( V_30 ) * 4096 ;
V_34 += V_36 -> V_37 [ 0 ] . V_38 ;
return V_34 ;
}
int F_24 ( struct V_39 * V_22 , struct V_40 * V_41 )
{
T_2 * V_42 ;
T_3 V_43 = 0 ;
V_42 = F_25 ( V_22 , V_44 , & V_43 ) ;
if ( NULL == V_42 )
return - V_45 ;
V_41 -> V_25 = V_44 ;
V_41 -> V_42 = V_42 ;
V_41 -> V_36 = V_43 ;
return 0 ;
}
int F_26 ( struct V_39 * V_22 , struct V_40 * V_41 ,
struct V_46 * V_47 , unsigned int V_48 ,
unsigned int V_49 )
{
T_2 * V_50 ;
unsigned int V_33 , V_51 ;
F_27 ( NULL == V_41 || NULL == V_41 -> V_42 ) ;
V_50 = V_41 -> V_42 + V_49 ;
for ( V_33 = 0 ; V_33 < V_48 ; V_33 ++ , V_47 ++ )
for ( V_51 = 0 ; V_51 * 4096 < V_47 -> V_48 ; V_51 ++ , V_50 ++ )
* V_50 = F_28 ( F_29 ( V_47 ) - V_47 -> V_38 ) ;
return 0 ;
}
void F_30 ( struct V_39 * V_22 , struct V_40 * V_41 )
{
if ( NULL == V_41 -> V_42 )
return;
F_31 ( V_22 , V_41 -> V_25 , V_41 -> V_42 , V_41 -> V_36 ) ;
V_41 -> V_42 = NULL ;
}
void F_32 ( struct V_52 * V_53 , struct V_29 * V_30 )
{
struct V_35 * V_36 = F_23 ( & V_30 -> V_31 ) ;
F_27 ( F_33 () ) ;
F_34 ( V_53 , & V_30 -> V_31 , 0 , 0 ) ;
F_35 ( V_53 -> V_2 , V_36 ) ;
F_36 ( V_36 ) ;
V_30 -> V_31 . V_54 = V_55 ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_56 * V_53 ,
struct V_29 * V_30 )
{
struct V_29 * V_57 = NULL ;
F_38 ( & V_2 -> V_58 ) ;
F_6 ( L_7 , V_30 ) ;
if ( NULL == V_53 -> V_59 ) {
if ( ! V_53 -> V_60 ) {
V_53 -> V_59 = V_30 ;
V_30 -> V_61 ( V_2 , V_30 , NULL ) ;
} else if ( F_39 ( & V_53 -> V_62 ) ) {
F_40 ( & V_30 -> V_31 . V_62 , & V_53 -> V_62 ) ;
V_30 -> V_31 . V_54 = V_63 ;
} else {
V_57 = F_41 ( V_53 -> V_62 . V_57 , struct V_29 ,
V_31 . V_62 ) ;
V_53 -> V_59 = V_30 ;
V_30 -> V_61 ( V_2 , V_30 , V_57 ) ;
}
} else {
F_40 ( & V_30 -> V_31 . V_62 , & V_53 -> V_62 ) ;
V_30 -> V_31 . V_54 = V_63 ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 ,
struct V_56 * V_53 ,
unsigned int V_54 )
{
F_38 ( & V_2 -> V_58 ) ;
F_6 ( L_8 , V_53 -> V_59 ) ;
V_53 -> V_59 -> V_31 . V_54 = V_54 ;
F_43 ( & V_53 -> V_59 -> V_31 . V_64 ) ;
F_44 ( & V_53 -> V_59 -> V_31 . V_65 ) ;
V_53 -> V_59 = NULL ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_56 * V_53 )
{
struct V_29 * V_30 , * V_57 = NULL ;
F_38 ( & V_2 -> V_58 ) ;
F_27 ( NULL != V_53 -> V_59 ) ;
if ( ! F_39 ( & V_53 -> V_62 ) ) {
V_30 = F_41 ( V_53 -> V_62 . V_57 , struct V_29 , V_31 . V_62 ) ;
F_6 ( L_9 ,
V_30 , V_53 -> V_62 . V_66 , V_53 -> V_62 . V_57 ) ;
F_46 ( & V_30 -> V_31 . V_62 ) ;
if ( ! F_39 ( & V_53 -> V_62 ) )
V_57 = F_41 ( V_53 -> V_62 . V_57 , struct V_29 ,
V_31 . V_62 ) ;
V_53 -> V_59 = V_30 ;
V_30 -> V_61 ( V_2 , V_30 , V_57 ) ;
F_6 ( L_10 ,
V_53 -> V_62 . V_66 , V_53 -> V_62 . V_57 ) ;
} else {
F_6 ( L_11 , NULL ) ;
F_47 ( V_2 ) ;
F_48 ( & V_53 -> V_67 ) ;
if ( F_49 ( V_2 ) )
if ( V_2 -> V_68 )
F_50 ( V_2 ) ;
}
}
void F_51 ( unsigned long V_69 )
{
struct V_56 * V_53 = (struct V_56 * ) V_69 ;
struct V_1 * V_2 = V_53 -> V_2 ;
unsigned long V_70 ;
F_52 ( & V_2 -> V_58 , V_70 ) ;
F_53 ( V_71 , 0x00 ) ;
F_53 ( V_71 , 0x80 ) ;
F_53 ( V_71 , 0x00 ) ;
if ( V_53 -> V_59 ) {
F_6 ( L_12 , V_53 -> V_59 ) ;
F_42 ( V_2 , V_53 , V_72 ) ;
}
F_45 ( V_2 , V_53 ) ;
F_54 ( & V_2 -> V_58 , V_70 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
T_1 V_73 , V_74 = 0 , V_75 = 0 , V_76 = 0 ;
enum V_77 V_78 = V_79 ;
enum V_77 V_80 = V_79 ;
F_38 ( & V_2 -> V_58 ) ;
if ( V_2 -> V_81 )
return 0 ;
if ( V_2 -> V_82 . V_59 ) {
V_74 |= 0x01 ;
V_75 |= V_83 ;
V_76 |= V_84 |
V_85 ;
V_78 = V_2 -> V_82 . V_59 -> V_31 . V_86 ;
}
if ( V_2 -> V_82 . V_59 &&
V_2 -> V_82 . V_59 -> V_87 -> V_88 ) {
V_75 |= V_89 |
V_90 ;
}
if ( V_2 -> V_91 ) {
V_74 |= 0x10 ;
V_75 |= V_92 ;
V_80 = V_2 -> V_93 ;
}
if ( V_2 -> V_94 . V_59 ) {
V_74 |= 0x22 ;
V_75 |= V_95 |
V_96 ;
V_76 |= V_97 |
V_98 |
V_99 |
V_100 ;
}
if ( V_2 -> V_101 . V_102 ) {
V_75 |= V_103 ;
V_76 |= V_104 |
V_105 ;
}
if ( V_2 -> V_106 . V_59 ) {
V_75 |= V_90 ;
V_76 |= V_107 |
V_108 ;
}
if ( F_55 ( V_78 ) || F_55 ( V_80 ) || V_78 == V_80 ) {
F_53 ( F_56 ( V_109 ) , 0x0d ) ;
F_53 ( F_56 ( V_110 ) , 0x0d ) ;
F_53 ( F_57 ( V_109 ) , 0x02 ) ;
F_53 ( F_57 ( V_110 ) , 0x02 ) ;
V_73 = 0 ;
} else {
if ( V_111 == V_78 ) {
F_53 ( F_56 ( V_109 ) , 0x0d ) ;
F_53 ( F_56 ( V_110 ) , 0x0e ) ;
} else {
F_53 ( F_56 ( V_109 ) , 0x0e ) ;
F_53 ( F_56 ( V_110 ) , 0x0d ) ;
}
F_53 ( F_57 ( V_109 ) , 0x01 ) ;
F_53 ( F_57 ( V_110 ) , 0x01 ) ;
V_73 = 1 ;
}
F_53 ( V_71 , V_74 ) ;
F_58 ( V_112 , V_76 ) ;
F_7 ( V_113 ,
V_83 |
V_92 |
V_95 |
V_96 |
V_89 |
V_90 |
V_103 ,
V_75 ) ;
F_6 ( L_13 ,
V_74 , V_75 , V_76 , V_73 ? L_14 : L_15 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , int V_114 ,
unsigned long V_115 , unsigned long V_5 )
{
unsigned int V_33 ;
F_4 ( V_11 L_16 ,
V_2 -> V_12 , V_114 , V_116 , V_115 , V_5 ) ;
for ( V_33 = 0 ; V_33 < V_117 ; V_33 ++ ) {
if ( ! ( V_115 & ( 1 << V_33 ) ) )
continue;
F_4 ( L_17 , V_118 [ V_33 ] ) ;
}
if ( V_115 & V_119 ) {
F_4 ( L_18 ,
( V_5 & 0x40 ) ? L_19 : L_20 ,
( V_5 & 0x20 ) ? L_21 : L_22 ,
( V_5 & 0x10 ) ? L_23 : L_24 ,
( V_5 & 0x0f ) ) ;
}
F_4 ( L_25 ) ;
}
static T_4 F_60 ( int V_76 , void * V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
unsigned long V_115 , V_5 ;
int V_114 , V_121 = 0 ;
if ( V_2 -> V_81 )
goto V_122;
for ( V_114 = 0 ; V_114 < 10 ; V_114 ++ ) {
V_115 = F_3 ( V_123 ) ;
V_5 = F_3 ( V_124 ) ;
if ( ( V_115 & V_125 ) &&
( V_2 -> V_101 . V_126 != NULL ) )
{
if ( V_127 > 1 )
F_4 ( V_11 L_26 ,
V_2 -> V_12 ) ;
V_115 &= ~ V_125 ;
}
if ( 0 == V_115 ) {
if ( V_127 > 1 )
F_4 ( V_11 L_27 ,
V_2 -> V_12 ) ;
goto V_122;
}
V_121 = 1 ;
F_58 ( V_123 , V_115 ) ;
if ( V_127 )
F_59 ( V_2 , V_114 , V_115 , V_5 ) ;
if ( ( V_115 & V_128 ) ||
( V_115 & V_129 ) )
F_61 ( V_2 ) ;
if ( ( V_115 & V_119 ) &&
( V_5 & 0x60 ) == 0 )
F_62 ( V_2 , V_5 ) ;
if ( ( V_115 & V_119 ) &&
( V_5 & 0x40 ) == 0x40 )
F_63 ( V_2 , V_5 ) ;
if ( ( V_115 & V_130 ) &&
F_49 ( V_2 ) )
F_64 ( V_2 , V_5 ) ;
if ( V_115 & V_131 ) {
switch ( V_2 -> V_132 ) {
case V_133 :
if ( ! V_2 -> V_134 )
break;
if ( V_2 -> V_134 -> V_135 & 0x10000 ) {
F_65 ( V_2 ) ;
}
break;
case V_136 :
break;
default:
break;
}
}
if ( V_115 & V_137 ) {
switch ( V_2 -> V_132 ) {
case V_133 :
if ( ! V_2 -> V_134 )
break;
if ( ( V_2 -> V_134 -> V_135 & 0x40000 ) ||
( V_2 -> V_134 -> V_138 & 0x40000 ) ) {
F_65 ( V_2 ) ;
}
break;
case V_136 :
break;
default:
break;
}
}
}
if ( 10 == V_114 ) {
F_59 ( V_2 , V_114 , V_115 , V_5 ) ;
if ( V_115 & V_139 ) {
F_4 ( V_140 L_28
L_29 , V_2 -> V_12 ) ;
F_66 ( V_141 , V_142 ) ;
} else if ( V_115 & V_131 ) {
F_4 ( V_140 L_28
L_30 , V_2 -> V_12 ) ;
F_66 ( V_141 , V_143 ) ;
F_66 ( V_141 , V_144 ) ;
} else if ( V_115 & V_137 ) {
F_4 ( V_140 L_28
L_31 , V_2 -> V_12 ) ;
F_66 ( V_141 , V_145 ) ;
F_66 ( V_141 , V_146 ) ;
} else {
F_4 ( V_140 L_28
L_32 , V_2 -> V_12 ) ;
F_58 ( V_112 , 0 ) ;
F_58 ( V_141 , 0 ) ;
}
}
V_122:
return F_67 ( V_121 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
F_58 ( V_147 , 0x08070503 ) ;
F_58 ( V_148 , 0x02020202 ) ;
F_58 ( V_113 ,
V_149 |
V_150 |
V_151 |
V_152 |
V_153 |
V_154 |
V_155 ) ;
F_53 ( V_156 , 0x01 ) ;
F_53 ( V_157 , 0x20 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
F_6 ( L_33 ) ;
F_58 ( V_112 , 0 ) ;
F_58 ( V_141 , 0 ) ;
F_58 ( V_123 , F_3 ( V_123 ) ) ;
F_70 ( & V_2 -> V_158 ) ;
F_71 ( & V_2 -> V_58 ) ;
F_1 ( V_2 , L_34 ) ;
F_72 ( V_2 ) ;
F_73 ( V_2 ) ;
if ( F_49 ( V_2 ) )
F_74 ( V_2 ) ;
F_75 ( V_2 ) ;
F_68 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
unsigned int V_159 ;
V_159 =
V_160 |
V_161 |
V_162 |
V_163 |
V_142 |
V_164 ;
if ( V_2 -> V_132 == V_133 && V_2 -> V_134 ) {
if ( V_2 -> V_134 -> V_135 & 0x10000 )
V_159 |= V_144 ;
else {
if ( V_2 -> V_134 -> V_135 & 0x40000 )
V_159 |= V_145 ;
if ( V_2 -> V_134 -> V_138 & 0x40000 )
V_159 |= V_146 ;
}
}
if ( V_2 -> V_132 == V_136 ) {
F_11 ( L_35 ) ;
}
F_58 ( V_112 , 0 ) ;
F_58 ( V_141 , V_159 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
F_6 ( L_36 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
F_6 ( L_37 ) ;
if ( F_49 ( V_2 ) )
F_81 ( V_2 ) ;
F_82 ( V_2 ) ;
F_83 ( V_2 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static void F_85 ( int V_165 )
{
unsigned int V_33 , V_51 ;
if ( ! V_165 )
F_4 ( V_140
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45 ) ;
else
F_4 ( V_140
L_46
L_47
L_48
L_49
L_50 ) ;
for ( V_33 = 0 ; V_33 < V_166 ; V_33 ++ ) {
F_4 ( V_140 L_51 ,
V_33 , V_167 [ V_33 ] . V_12 ) ;
for ( V_51 = 0 ; V_168 [ V_51 ] . V_169 ; V_51 ++ ) {
if ( V_168 [ V_51 ] . V_169 != V_33 )
continue;
F_4 ( L_52 ,
V_168 [ V_51 ] . V_170 ,
V_168 [ V_51 ] . V_171 ) ;
}
F_4 ( L_25 ) ;
}
}
static struct V_172 * F_86 ( struct V_1 * V_2 ,
struct V_172 * V_173 ,
char * type )
{
struct V_172 * V_174 ;
V_174 = F_87 () ;
if ( NULL == V_174 )
return NULL ;
* V_174 = * V_173 ;
V_174 -> V_175 = & V_2 -> V_175 ;
V_174 -> V_176 = V_177 ;
V_174 -> V_178 = V_179 ;
snprintf ( V_174 -> V_12 , sizeof( V_174 -> V_12 ) , L_53 ,
V_2 -> V_12 , type , V_167 [ V_2 -> V_180 ] . V_12 ) ;
F_88 ( V_181 , & V_174 -> V_70 ) ;
F_89 ( V_174 , V_2 ) ;
return V_174 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_182 ) {
if ( F_91 ( V_2 -> V_182 ) )
F_92 ( V_2 -> V_182 ) ;
else
V_177 ( V_2 -> V_182 ) ;
V_2 -> V_182 = NULL ;
}
if ( V_2 -> V_183 ) {
if ( F_91 ( V_2 -> V_183 ) )
F_92 ( V_2 -> V_183 ) ;
else
V_177 ( V_2 -> V_183 ) ;
V_2 -> V_183 = NULL ;
}
if ( V_2 -> V_184 ) {
if ( F_91 ( V_2 -> V_184 ) )
F_92 ( V_2 -> V_184 ) ;
else
V_177 ( V_2 -> V_184 ) ;
V_2 -> V_184 = NULL ;
}
}
static void F_93 ( struct V_185 * V_186 ,
struct V_1 * V_2 )
{
int V_187 ;
if ( NULL != V_2 -> V_188 )
return;
if ( V_167 [ V_2 -> V_180 ] . V_189 != V_186 -> type )
return;
V_187 = V_186 -> V_190 ( V_2 ) ;
if ( 0 != V_187 )
return;
V_2 -> V_188 = V_186 ;
}
static void F_94 ( struct V_185 * V_186 ,
struct V_1 * V_2 )
{
if ( NULL == V_2 -> V_188 )
return;
if ( V_2 -> V_188 != V_186 )
return;
V_2 -> V_188 -> V_191 ( V_2 ) ;
V_2 -> V_188 = NULL ;
}
static int F_95 ( struct V_39 * V_39 ,
const struct V_192 * V_193 )
{
struct V_1 * V_2 ;
struct V_185 * V_188 ;
int V_187 ;
if ( V_194 == V_195 )
return - V_45 ;
V_2 = F_96 ( sizeof( * V_2 ) , V_196 ) ;
if ( NULL == V_2 )
return - V_45 ;
V_187 = F_97 ( & V_39 -> V_2 , & V_2 -> V_175 ) ;
if ( V_187 )
goto V_197;
V_2 -> V_22 = V_39 ;
if ( F_98 ( V_39 ) ) {
V_187 = - V_198 ;
goto V_199;
}
V_2 -> V_200 = V_194 ;
sprintf ( V_2 -> V_12 , L_54 , V_39 -> V_23 , V_2 -> V_200 ) ;
if ( V_201 ) {
if ( V_201 & V_202 )
F_4 ( V_203 L_55 , V_2 -> V_12 ) ;
if ( V_201 & V_204 )
F_4 ( V_203 L_56 , V_2 -> V_12 ) ;
if ( V_201 & V_205 )
F_4 ( V_203 L_57 , V_2 -> V_12 ) ;
if ( V_201 & V_206 )
F_4 ( V_203 L_58 , V_2 -> V_12 ) ;
#ifdef F_99
if ( V_201 & F_99 ) {
F_4 ( V_203 L_59 ,
V_2 -> V_12 ) ;
V_207 = 0x0A ;
}
#endif
if ( V_201 & ( V_208 | V_209 ) ) {
F_4 ( V_203 L_60
L_61
L_62 , V_2 -> V_12 ) ;
if ( ! V_210 ) {
F_4 ( V_203 L_63
L_64 ,
V_2 -> V_12 ) ;
V_210 = 1 ;
} else {
F_4 ( V_203 L_63
L_65
L_66 ,
V_2 -> V_12 ) ;
}
}
}
if ( V_211 != V_207 ) {
F_4 ( V_203 L_67 ,
V_2 -> V_12 , V_207 ) ;
F_100 ( V_39 , V_212 , V_207 ) ;
}
V_2 -> V_213 = V_39 -> V_214 ;
F_101 ( V_39 , V_212 , & V_2 -> V_215 ) ;
F_4 ( V_203 L_68
L_69 , V_2 -> V_12 ,
F_102 ( V_39 ) , V_2 -> V_213 , V_39 -> V_76 ,
V_2 -> V_215 , ( unsigned long long ) F_103 ( V_39 , 0 ) ) ;
F_104 ( V_39 ) ;
if ( ! F_105 ( V_39 , F_106 ( 32 ) ) ) {
F_4 ( L_70 , V_2 -> V_12 ) ;
V_187 = - V_198 ;
goto V_199;
}
V_2 -> V_180 = V_193 -> V_169 ;
if ( ( unsigned ) V_216 [ V_2 -> V_200 ] < V_166 )
V_2 -> V_180 = V_216 [ V_2 -> V_200 ] ;
if ( V_217 == V_2 -> V_180 )
F_85 ( 0 ) ;
else if ( V_218 == V_2 -> V_180 ) {
F_85 ( 1 ) ;
V_2 -> V_180 = V_217 ;
}
V_2 -> V_219 = V_216 [ V_2 -> V_200 ] != V_2 -> V_180 ;
V_2 -> V_220 = V_167 [ V_2 -> V_180 ] . V_220 ;
V_2 -> V_221 = V_167 [ V_2 -> V_180 ] . V_221 ;
V_2 -> V_222 = V_167 [ V_2 -> V_180 ] . V_222 ;
V_2 -> V_223 = V_167 [ V_2 -> V_180 ] . V_223 ;
V_2 -> V_224 = V_167 [ V_2 -> V_180 ] . V_224 ;
if ( V_211 != V_225 [ V_2 -> V_200 ] )
V_2 -> V_220 = V_225 [ V_2 -> V_200 ] ;
F_4 ( V_203 L_71 ,
V_2 -> V_12 , V_39 -> V_226 ,
V_39 -> V_227 , V_167 [ V_2 -> V_180 ] . V_12 ,
V_2 -> V_180 , V_2 -> V_219 ?
L_72 : L_73 ) ;
if ( ! F_107 ( F_103 ( V_39 , 0 ) ,
F_108 ( V_39 , 0 ) ,
V_2 -> V_12 ) ) {
V_187 = - V_228 ;
F_4 ( V_229 L_74 ,
V_2 -> V_12 , ( unsigned long long ) F_103 ( V_39 , 0 ) ) ;
goto V_199;
}
V_2 -> V_230 = F_109 ( F_103 ( V_39 , 0 ) ,
F_108 ( V_39 , 0 ) ) ;
V_2 -> V_231 = ( V_232 V_233 * ) V_2 -> V_230 ;
if ( NULL == V_2 -> V_230 ) {
V_187 = - V_198 ;
F_4 ( V_229 L_75 ,
V_2 -> V_12 ) ;
goto V_234;
}
F_110 ( V_2 ) ;
F_69 ( V_2 ) ;
V_187 = F_111 ( V_39 -> V_76 , F_60 ,
V_235 | V_236 , V_2 -> V_12 , V_2 ) ;
if ( V_187 < 0 ) {
F_4 ( V_229 L_76 ,
V_2 -> V_12 , V_39 -> V_76 ) ;
goto V_237;
}
F_112 ( 100 ) ;
F_113 ( V_2 ) ;
F_114 ( V_2 ) ;
F_77 ( V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_238 * V_239 =
F_115 ( & V_2 -> V_175 , & V_2 -> V_240 ,
L_77 ,
V_167 [ V_2 -> V_180 ] . V_241 , NULL ) ;
if ( V_239 )
V_239 -> V_242 = V_243 ;
}
if ( V_167 [ V_2 -> V_180 ] . V_244 ) {
struct V_238 * V_239 ;
V_239 = F_115 ( & V_2 -> V_175 ,
& V_2 -> V_240 , L_78 ,
0 , F_116 ( V_167 [ V_2 -> V_180 ] . V_244 ) ) ;
if ( V_239 ) {
F_4 ( V_203 L_79 , V_2 -> V_12 ) ;
V_2 -> V_245 = 1 ;
}
}
F_117 ( & V_246 ) ;
F_118 (mops, &mops_list, next)
F_93 ( V_188 , V_2 ) ;
F_40 ( & V_2 -> V_247 , & V_248 ) ;
F_119 ( & V_246 ) ;
F_61 ( V_2 ) ;
if ( V_249 != V_2 -> V_220 )
F_120 ( V_2 , V_250 , V_251 , 0 ) ;
if ( V_210 > 0 )
F_4 ( V_203 L_80 , V_2 -> V_12 ) ;
V_2 -> V_182 = F_86 ( V_2 , & V_252 , L_20 ) ;
V_187 = F_121 ( V_2 -> V_182 , V_253 ,
V_254 [ V_2 -> V_200 ] ) ;
if ( V_187 < 0 ) {
F_4 ( V_203 L_81 ,
V_2 -> V_12 ) ;
goto V_255;
}
F_4 ( V_203 L_82 ,
V_2 -> V_12 , F_122 ( V_2 -> V_182 ) ) ;
V_2 -> V_183 = F_86 ( V_2 , & V_252 , L_19 ) ;
V_187 = F_121 ( V_2 -> V_183 , V_256 ,
V_257 [ V_2 -> V_200 ] ) ;
if ( V_187 < 0 )
goto V_255;
F_4 ( V_203 L_83 ,
V_2 -> V_12 , F_122 ( V_2 -> V_183 ) ) ;
if ( F_123 ( V_2 ) ) {
V_2 -> V_184 = F_86 ( V_2 , & V_258 , L_84 ) ;
V_187 = F_121 ( V_2 -> V_184 , V_259 ,
V_260 [ V_2 -> V_200 ] ) ;
if ( V_187 < 0 )
goto V_255;
F_4 ( V_203 L_83 ,
V_2 -> V_12 , F_122 ( V_2 -> V_184 ) ) ;
}
V_194 ++ ;
if ( V_261 && ! V_2 -> V_101 . V_126 )
V_261 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
V_255:
F_90 ( V_2 ) ;
F_124 ( V_2 ) ;
F_125 ( V_39 -> V_76 , V_2 ) ;
V_237:
F_80 ( V_2 ) ;
F_126 ( V_2 -> V_230 ) ;
V_234:
F_127 ( F_103 ( V_39 , 0 ) ,
F_108 ( V_39 , 0 ) ) ;
V_199:
F_128 ( & V_2 -> V_175 ) ;
V_197:
F_129 ( V_2 ) ;
return V_187 ;
}
static void F_130 ( struct V_39 * V_39 )
{
struct V_262 * V_175 = F_131 ( V_39 ) ;
struct V_1 * V_2 = F_9 ( V_175 , struct V_1 , V_175 ) ;
struct V_185 * V_188 ;
F_16 ( V_2 ) ;
if ( V_263 && V_2 -> V_101 . V_126 ) {
V_263 ( V_2 ) ;
}
if ( V_127 ) {
T_1 V_115 = F_3 ( V_123 ) ;
T_1 V_5 = F_3 ( V_124 ) ;
F_59 ( V_2 , 42 , V_115 , V_5 ) ;
}
F_53 ( V_156 , 0 ) ;
F_58 ( V_112 , 0 ) ;
F_58 ( V_141 , 0 ) ;
F_58 ( V_113 , 0 ) ;
F_80 ( V_2 ) ;
F_117 ( & V_246 ) ;
F_46 ( & V_2 -> V_247 ) ;
F_118 (mops, &mops_list, next)
F_94 ( V_188 , V_2 ) ;
F_119 ( & V_246 ) ;
V_194 -- ;
F_124 ( V_2 ) ;
F_90 ( V_2 ) ;
if ( V_2 -> V_101 . V_126 != NULL ) {
F_125 ( V_39 -> V_76 , & V_2 -> V_101 ) ;
V_2 -> V_101 . V_126 = NULL ;
}
F_125 ( V_39 -> V_76 , V_2 ) ;
F_126 ( V_2 -> V_230 ) ;
F_127 ( F_103 ( V_39 , 0 ) ,
F_108 ( V_39 , 0 ) ) ;
F_128 ( & V_2 -> V_175 ) ;
F_129 ( V_2 ) ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_56 * V_53 )
{
struct V_29 * V_30 , * V_57 ;
F_38 ( & V_2 -> V_58 ) ;
V_30 = V_53 -> V_59 ;
V_57 = V_30 ;
F_6 ( L_85 ) ;
if ( ! V_30 )
return 0 ;
F_6 ( L_86 ) ;
if ( ! F_39 ( & V_53 -> V_62 ) )
V_57 = F_41 ( V_53 -> V_62 . V_57 , struct V_29 ,
V_31 . V_62 ) ;
V_30 -> V_61 ( V_2 , V_30 , V_57 ) ;
return 0 ;
}
static int F_133 ( struct V_39 * V_39 , T_5 V_54 )
{
struct V_262 * V_175 = F_131 ( V_39 ) ;
struct V_1 * V_2 = F_9 ( V_175 , struct V_1 , V_175 ) ;
V_2 -> V_91 = 0 ;
F_58 ( V_112 , 0 ) ;
F_58 ( V_141 , 0 ) ;
F_58 ( V_113 , 0 ) ;
V_2 -> V_81 = 1 ;
F_134 ( V_39 -> V_76 ) ;
F_58 ( V_123 , F_3 ( V_123 ) ) ;
F_48 ( & V_2 -> V_82 . V_67 ) ;
F_48 ( & V_2 -> V_94 . V_67 ) ;
F_48 ( & V_2 -> V_106 . V_67 ) ;
if ( V_2 -> V_134 )
F_135 ( V_2 ) ;
F_136 ( V_39 ) ;
F_137 ( V_39 , F_138 ( V_39 , V_54 ) ) ;
return 0 ;
}
static int F_139 ( struct V_39 * V_39 )
{
struct V_262 * V_175 = F_131 ( V_39 ) ;
struct V_1 * V_2 = F_9 ( V_175 , struct V_1 , V_175 ) ;
unsigned long V_70 ;
F_137 ( V_39 , V_264 ) ;
F_140 ( V_39 ) ;
F_110 ( V_2 ) ;
if ( V_167 [ V_2 -> V_180 ] . V_265 )
F_141 ( V_2 ) ;
if ( F_49 ( V_2 ) )
F_142 ( V_2 ) ;
if ( V_2 -> V_134 )
F_143 ( V_2 ) ;
F_68 ( V_2 ) ;
F_112 ( 100 ) ;
F_114 ( V_2 ) ;
F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
F_146 ( V_2 , V_2 -> V_266 ) ;
F_147 ( V_2 ) ;
F_148 ( V_2 ) ;
F_76 ( V_2 ) ;
F_61 ( V_2 ) ;
F_52 ( & V_2 -> V_58 , V_70 ) ;
F_132 ( V_2 , & V_2 -> V_82 ) ;
F_132 ( V_2 , & V_2 -> V_94 ) ;
F_132 ( V_2 , & V_2 -> V_106 ) ;
V_2 -> V_101 . V_102 = 0 ;
V_2 -> V_81 = 0 ;
F_149 () ;
F_47 ( V_2 ) ;
F_54 ( & V_2 -> V_58 , V_70 ) ;
return 0 ;
}
int F_150 ( struct V_185 * V_186 )
{
struct V_1 * V_2 ;
F_117 ( & V_246 ) ;
F_118 (dev, &saa7134_devlist, devlist)
F_93 ( V_186 , V_2 ) ;
F_40 ( & V_186 -> V_57 , & V_267 ) ;
F_119 ( & V_246 ) ;
return 0 ;
}
void F_151 ( struct V_185 * V_186 )
{
struct V_1 * V_2 ;
F_117 ( & V_246 ) ;
F_46 ( & V_186 -> V_57 ) ;
F_118 (dev, &saa7134_devlist, devlist)
F_94 ( V_186 , V_2 ) ;
F_119 ( & V_246 ) ;
}
static int T_6 F_152 ( void )
{
F_153 ( & V_248 ) ;
F_4 ( V_203 L_87 ,
V_268 ) ;
return F_154 ( & V_269 ) ;
}
static void T_7 F_155 ( void )
{
F_156 ( & V_269 ) ;
}
