void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
F_2 ( & V_2 -> V_6 . V_8 ) ;
if ( V_5 -> V_9 == V_2 && V_5 -> V_10 != V_11 &&
V_5 -> V_12 != V_13 ) {
V_5 -> V_14 += F_3 () - V_5 -> V_12 ;
V_5 -> V_12 = V_13 ;
}
if ( V_2 -> V_6 . V_15 == V_16 &&
V_2 -> V_6 . V_17 != V_13 ) {
V_2 -> V_6 . V_18 += F_3 () - V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_13 ;
}
F_4 ( & V_2 -> V_6 . V_8 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
F_2 ( & V_2 -> V_6 . V_8 ) ;
if ( V_5 -> V_9 == V_2 && V_5 -> V_10 != V_11 )
V_5 -> V_12 = F_3 () ;
if ( V_2 -> V_6 . V_15 == V_16 )
V_2 -> V_6 . V_17 = F_3 () ;
F_4 ( & V_2 -> V_6 . V_8 ) ;
}
void F_6 ( struct V_1 * V_2 , T_1 V_19 )
{
V_2 -> V_6 . V_20 . V_19 = V_19 ;
F_7 ( V_2 ) ;
}
void F_8 ( struct V_1 * V_2 , T_2 V_21 )
{
V_2 -> V_6 . V_21 = V_21 ;
}
void F_9 ( struct V_1 * V_2 )
{
int V_22 ;
F_10 ( L_1 , V_2 , V_2 -> V_23 ) ;
F_10 ( L_2 ,
V_2 -> V_6 . V_24 , V_2 -> V_6 . V_20 . V_19 , V_2 -> V_6 . V_25 ) ;
for ( V_22 = 0 ; V_22 < 16 ; ++ V_22 )
F_10 ( L_3 ,
V_22 , F_11 ( V_2 , V_22 ) ,
V_22 + 16 , F_11 ( V_2 , V_22 + 16 ) ) ;
F_10 ( L_4 ,
V_2 -> V_6 . V_26 , V_2 -> V_6 . V_27 ) ;
F_10 ( L_5 ,
V_2 -> V_6 . V_20 . V_28 , V_2 -> V_6 . V_20 . V_29 ) ;
F_10 ( L_6 ,
V_2 -> V_6 . V_20 . V_30 , V_2 -> V_6 . V_20 . V_31 ) ;
F_10 ( L_7 ,
V_2 -> V_6 . V_20 . V_32 , V_2 -> V_6 . V_20 . V_33 ) ;
F_10 ( L_8 ,
V_2 -> V_6 . V_34 , V_2 -> V_6 . V_35 , V_2 -> V_6 . V_20 . V_36 ) ;
F_10 ( L_9 , V_2 -> V_6 . V_20 . V_37 ) ;
F_10 ( L_10 ,
V_2 -> V_6 . V_38 , V_2 -> V_6 . V_39 ) ;
F_10 ( L_11 , V_2 -> V_6 . V_40 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_6 . V_40 ; ++ V_22 )
F_10 ( L_12 ,
V_2 -> V_6 . V_41 [ V_22 ] . V_42 , V_2 -> V_6 . V_41 [ V_22 ] . V_43 ) ;
F_10 ( L_13 ,
V_2 -> V_44 -> V_6 . V_45 , V_2 -> V_44 -> V_6 . V_46 ,
V_2 -> V_6 . V_47 ) ;
}
struct V_1 * F_12 ( struct V_44 * V_44 , int V_48 )
{
int V_22 ;
struct V_1 * V_49 , * V_50 = NULL ;
F_13 ( & V_44 -> V_51 ) ;
F_14 (r, v, kvm) {
if ( V_49 -> V_23 == V_48 ) {
V_50 = V_49 ;
break;
}
}
F_15 ( & V_44 -> V_51 ) ;
return V_50 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
V_53 -> V_54 = 1 ;
V_53 -> V_55 = 1 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_56 * V_49 ,
unsigned long V_57 , unsigned long V_58 )
{
if ( V_57 & ( V_59 - 1 ) )
return - V_60 ;
F_2 ( & V_2 -> V_6 . V_61 ) ;
if ( V_49 -> V_62 != V_57 || V_49 -> V_58 != V_58 ) {
V_49 -> V_62 = V_57 ;
V_49 -> V_58 = V_57 ? V_58 : 0 ;
V_49 -> V_63 = 1 ;
}
F_4 ( & V_2 -> V_6 . V_61 ) ;
return 0 ;
}
static int F_18 ( struct V_56 * V_64 )
{
if ( V_64 -> V_63 )
return V_64 -> V_62 != 0 ;
return V_64 -> V_65 != NULL ;
}
static unsigned long F_19 ( struct V_1 * V_2 ,
unsigned long V_66 ,
unsigned long V_67 , unsigned long V_53 )
{
struct V_44 * V_44 = V_2 -> V_44 ;
unsigned long V_58 , V_68 ;
void * V_69 ;
struct V_1 * V_70 ;
int V_71 ;
int V_72 ;
struct V_56 * V_64 ;
V_70 = F_12 ( V_44 , V_67 ) ;
if ( ! V_70 )
return V_73 ;
V_72 = ( V_66 >> V_74 ) & V_75 ;
if ( V_72 == V_76 || V_72 == V_77 ||
V_72 == V_78 ) {
if ( ( V_53 & ( V_59 - 1 ) ) || ! V_53 )
return V_73 ;
V_69 = F_20 ( V_44 , V_53 , & V_68 ) ;
if ( V_69 == NULL )
return V_73 ;
if ( V_72 == V_76 )
V_58 = ( (struct V_79 * ) V_69 ) -> V_80 . V_81 ;
else
V_58 = ( (struct V_79 * ) V_69 ) -> V_80 . V_82 ;
F_21 ( V_44 , V_69 ) ;
if ( V_58 > V_68 || V_58 < sizeof( struct V_79 ) )
return V_73 ;
} else {
V_53 = 0 ;
V_58 = 0 ;
}
V_71 = V_73 ;
V_64 = NULL ;
F_2 ( & V_70 -> V_6 . V_61 ) ;
switch ( V_72 ) {
case V_76 :
if ( V_58 < sizeof( struct V_52 ) )
break;
V_64 = & V_70 -> V_6 . V_53 ;
V_71 = 0 ;
break;
case V_77 :
if ( V_58 < sizeof( struct V_83 ) )
break;
V_58 -= V_58 % sizeof( struct V_83 ) ;
V_71 = V_84 ;
if ( ! F_18 ( & V_70 -> V_6 . V_53 ) )
break;
V_64 = & V_70 -> V_6 . V_85 ;
V_71 = 0 ;
break;
case V_78 :
V_71 = V_84 ;
if ( ! F_18 ( & V_70 -> V_6 . V_53 ) )
break;
V_64 = & V_70 -> V_6 . V_86 ;
V_71 = 0 ;
break;
case V_87 :
V_71 = V_84 ;
if ( F_18 ( & V_70 -> V_6 . V_85 ) ||
F_18 ( & V_70 -> V_6 . V_86 ) )
break;
V_64 = & V_70 -> V_6 . V_53 ;
V_71 = 0 ;
break;
case V_88 :
V_64 = & V_70 -> V_6 . V_85 ;
V_71 = 0 ;
break;
case V_89 :
V_64 = & V_70 -> V_6 . V_86 ;
V_71 = 0 ;
break;
}
if ( V_64 ) {
V_64 -> V_62 = V_53 ;
V_64 -> V_58 = V_58 ;
V_64 -> V_63 = 1 ;
}
F_4 ( & V_70 -> V_6 . V_61 ) ;
return V_71 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_56 * V_64 )
{
struct V_44 * V_44 = V_2 -> V_44 ;
void * V_69 ;
unsigned long V_68 ;
unsigned long V_90 ;
for (; ; ) {
V_90 = V_64 -> V_62 ;
F_4 ( & V_2 -> V_6 . V_61 ) ;
V_69 = NULL ;
V_68 = 0 ;
if ( V_90 )
V_69 = F_20 ( V_44 , V_64 -> V_62 , & V_68 ) ;
F_2 ( & V_2 -> V_6 . V_61 ) ;
if ( V_90 == V_64 -> V_62 )
break;
if ( V_69 )
F_21 ( V_44 , V_69 ) ;
}
V_64 -> V_63 = 0 ;
if ( V_69 && V_68 < V_64 -> V_58 ) {
F_21 ( V_44 , V_69 ) ;
V_69 = NULL ;
}
if ( V_64 -> V_65 )
F_21 ( V_44 , V_64 -> V_65 ) ;
V_64 -> V_65 = V_69 ;
if ( V_69 )
V_64 -> V_91 = V_69 + V_64 -> V_58 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_6 . V_53 . V_63 ||
V_2 -> V_6 . V_86 . V_63 ||
V_2 -> V_6 . V_85 . V_63 ) )
return;
F_2 ( & V_2 -> V_6 . V_61 ) ;
if ( V_2 -> V_6 . V_53 . V_63 ) {
F_22 ( V_2 , & V_2 -> V_6 . V_53 ) ;
if ( V_2 -> V_6 . V_53 . V_65 )
F_16 ( V_2 , V_2 -> V_6 . V_53 . V_65 ) ;
}
if ( V_2 -> V_6 . V_85 . V_63 ) {
F_22 ( V_2 , & V_2 -> V_6 . V_85 ) ;
V_2 -> V_6 . V_92 = V_2 -> V_6 . V_85 . V_65 ;
V_2 -> V_6 . V_93 = 0 ;
}
if ( V_2 -> V_6 . V_86 . V_63 )
F_22 ( V_2 , & V_2 -> V_6 . V_86 ) ;
F_4 ( & V_2 -> V_6 . V_61 ) ;
}
static T_1 F_24 ( struct V_4 * V_5 , T_1 V_94 )
{
T_1 V_95 ;
if ( V_5 -> V_10 != V_11 &&
V_5 -> V_9 -> V_6 . V_96 != V_97 ) {
F_2 ( & V_5 -> V_9 -> V_6 . V_8 ) ;
V_95 = V_5 -> V_14 ;
if ( V_5 -> V_12 != V_13 )
V_95 += V_94 - V_5 -> V_12 ;
F_4 ( & V_5 -> V_9 -> V_6 . V_8 ) ;
} else {
V_95 = V_5 -> V_14 ;
}
return V_95 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_83 * V_98 ;
struct V_52 * V_53 ;
unsigned long V_99 ;
unsigned long V_100 ;
T_1 V_94 ;
V_98 = V_2 -> V_6 . V_92 ;
V_53 = V_2 -> V_6 . V_53 . V_65 ;
V_94 = F_3 () ;
V_100 = F_24 ( V_5 , V_94 ) ;
V_99 = V_100 - V_2 -> V_6 . V_101 ;
V_2 -> V_6 . V_101 = V_100 ;
F_2 ( & V_2 -> V_6 . V_8 ) ;
V_99 += V_2 -> V_6 . V_18 ;
V_2 -> V_6 . V_18 = 0 ;
F_4 ( & V_2 -> V_6 . V_8 ) ;
if ( ! V_98 || ! V_53 )
return;
memset ( V_98 , 0 , sizeof( struct V_83 ) ) ;
V_98 -> V_102 = 7 ;
V_98 -> V_103 = V_5 -> V_104 + V_2 -> V_6 . V_105 ;
V_98 -> V_106 = V_94 ;
V_98 -> V_107 = V_99 ;
V_98 -> V_28 = F_26 ( V_2 ) ;
V_98 -> V_29 = V_2 -> V_6 . V_20 . V_19 ;
++ V_98 ;
if ( V_98 == V_2 -> V_6 . V_85 . V_91 )
V_98 = V_2 -> V_6 . V_85 . V_65 ;
V_2 -> V_6 . V_92 = V_98 ;
F_27 () ;
V_53 -> V_108 = ++ V_2 -> V_6 . V_93 ;
}
int F_28 ( struct V_1 * V_2 )
{
unsigned long V_109 = F_11 ( V_2 , 3 ) ;
unsigned long V_110 , V_50 = V_111 ;
struct V_1 * V_70 ;
int V_112 ;
switch ( V_109 ) {
case V_113 :
V_112 = F_29 ( & V_2 -> V_44 -> V_114 ) ;
V_50 = F_30 ( V_2 , F_11 ( V_2 , 4 ) ,
F_11 ( V_2 , 5 ) ,
F_11 ( V_2 , 6 ) ,
F_11 ( V_2 , 7 ) ) ;
F_31 ( & V_2 -> V_44 -> V_114 , V_112 ) ;
break;
case V_115 :
break;
case V_116 :
V_110 = F_11 ( V_2 , 4 ) ;
V_70 = F_12 ( V_2 -> V_44 , V_110 ) ;
if ( ! V_70 ) {
V_50 = V_73 ;
break;
}
V_70 -> V_6 . V_117 = 1 ;
F_32 () ;
if ( V_2 -> V_6 . V_118 ) {
if ( F_33 ( & V_2 -> V_119 ) ) {
F_34 ( & V_2 -> V_119 ) ;
V_2 -> V_120 . V_121 ++ ;
}
}
break;
case V_122 :
break;
case V_123 :
V_50 = F_19 ( V_2 , F_11 ( V_2 , 4 ) ,
F_11 ( V_2 , 5 ) ,
F_11 ( V_2 , 6 ) ) ;
break;
default:
return V_124 ;
}
F_35 ( V_2 , 3 , V_50 ) ;
V_2 -> V_6 . V_125 = 0 ;
return V_126 ;
}
static int F_36 ( struct V_127 * V_128 , struct V_1 * V_2 ,
struct V_129 * V_130 )
{
int V_22 = V_124 ;
V_2 -> V_120 . V_131 ++ ;
V_128 -> V_132 = V_133 ;
V_128 -> V_134 = 1 ;
switch ( V_2 -> V_6 . V_25 ) {
case V_135 :
V_2 -> V_120 . V_136 ++ ;
V_22 = V_126 ;
break;
case V_137 :
V_2 -> V_120 . V_138 ++ ;
V_22 = V_126 ;
break;
case V_139 :
V_22 = V_126 ;
break;
case V_140 :
F_37 ( V_2 ,
V_140 ) ;
V_22 = V_126 ;
break;
case V_141 :
{
T_3 V_66 ;
V_66 = V_2 -> V_6 . V_20 . V_19 & 0x1f0000ull ;
F_38 ( V_2 , V_66 ) ;
V_22 = V_126 ;
break;
}
case V_142 :
{
int V_143 ;
if ( V_2 -> V_6 . V_20 . V_19 & V_144 ) {
F_37 ( V_2 , V_142 ) ;
V_22 = V_126 ;
break;
}
V_128 -> V_145 . V_146 = F_11 ( V_2 , 3 ) ;
for ( V_143 = 0 ; V_143 < 9 ; ++ V_143 )
V_128 -> V_145 . args [ V_143 ] = F_11 ( V_2 , 4 + V_143 ) ;
V_128 -> V_132 = V_147 ;
V_2 -> V_6 . V_125 = 1 ;
V_22 = V_124 ;
break;
}
case V_148 :
V_22 = V_149 ;
break;
case V_150 :
V_2 -> V_6 . V_38 = F_26 ( V_2 ) ;
V_2 -> V_6 . V_39 = 0 ;
V_22 = V_149 ;
break;
case V_151 :
F_38 ( V_2 , 0x80000 ) ;
V_22 = V_126 ;
break;
default:
F_9 ( V_2 ) ;
F_39 ( V_152 L_14 ,
V_2 -> V_6 . V_25 , F_26 ( V_2 ) ,
V_2 -> V_6 . V_20 . V_19 ) ;
V_22 = V_124 ;
F_40 () ;
break;
}
return V_22 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
int V_143 ;
V_154 -> V_21 = V_2 -> V_6 . V_21 ;
memset ( V_154 , 0 , sizeof( struct V_153 ) ) ;
for ( V_143 = 0 ; V_143 < V_2 -> V_6 . V_40 ; V_143 ++ ) {
V_154 -> V_155 . V_156 . V_157 . V_41 [ V_143 ] . V_158 = V_2 -> V_6 . V_41 [ V_143 ] . V_42 ;
V_154 -> V_155 . V_156 . V_157 . V_41 [ V_143 ] . V_159 = V_2 -> V_6 . V_41 [ V_143 ] . V_43 ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
int V_143 , V_160 ;
F_8 ( V_2 , V_154 -> V_21 ) ;
V_160 = 0 ;
for ( V_143 = 0 ; V_143 < V_2 -> V_6 . V_161 ; V_143 ++ ) {
if ( V_154 -> V_155 . V_156 . V_157 . V_41 [ V_143 ] . V_158 & V_162 ) {
V_2 -> V_6 . V_41 [ V_160 ] . V_42 = V_154 -> V_155 . V_156 . V_157 . V_41 [ V_143 ] . V_158 ;
V_2 -> V_6 . V_41 [ V_160 ] . V_43 = V_154 -> V_155 . V_156 . V_157 . V_41 [ V_143 ] . V_159 ;
++ V_160 ;
}
}
V_2 -> V_6 . V_40 = V_160 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 , T_1 V_48 , union V_163 * V_164 )
{
int V_22 = 0 ;
long int V_143 ;
switch ( V_48 ) {
case V_165 :
* V_164 = F_44 ( V_48 , 0 ) ;
break;
case V_166 :
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_167 ) ;
break;
case V_168 :
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_169 ) ;
break;
case V_170 :
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_171 ) ;
break;
case V_172 :
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_173 ) ;
break;
case V_174 :
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_175 ) ;
break;
case V_176 :
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_177 ) ;
break;
case V_178 ... V_179 :
V_143 = V_48 - V_178 ;
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_180 [ V_143 ] ) ;
break;
case V_181 ... V_182 :
V_143 = V_48 - V_181 ;
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_183 [ V_143 ] ) ;
break;
#ifdef F_45
case V_184 ... V_185 :
if ( F_46 ( V_186 ) ) {
long int V_143 = V_48 - V_184 ;
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_187 [ 2 * V_143 ] ) ;
} else {
V_22 = - V_60 ;
}
break;
case V_188 ... V_189 :
if ( F_46 ( V_186 ) ) {
long int V_143 = V_48 - V_188 ;
V_164 -> V_190 [ 0 ] = V_2 -> V_6 . V_187 [ 2 * V_143 ] ;
V_164 -> V_190 [ 1 ] = V_2 -> V_6 . V_187 [ 2 * V_143 + 1 ] ;
} else {
V_22 = - V_191 ;
}
break;
#endif
case V_192 :
F_2 ( & V_2 -> V_6 . V_61 ) ;
* V_164 = F_44 ( V_48 , V_2 -> V_6 . V_53 . V_62 ) ;
F_4 ( & V_2 -> V_6 . V_61 ) ;
break;
case V_193 :
F_2 ( & V_2 -> V_6 . V_61 ) ;
V_164 -> V_194 . V_57 = V_2 -> V_6 . V_86 . V_62 ;
V_164 -> V_194 . V_80 = V_2 -> V_6 . V_86 . V_58 ;
F_4 ( & V_2 -> V_6 . V_61 ) ;
break;
case V_195 :
F_2 ( & V_2 -> V_6 . V_61 ) ;
V_164 -> V_194 . V_57 = V_2 -> V_6 . V_85 . V_62 ;
V_164 -> V_194 . V_80 = V_2 -> V_6 . V_85 . V_58 ;
F_4 ( & V_2 -> V_6 . V_61 ) ;
break;
default:
V_22 = - V_60 ;
break;
}
return V_22 ;
}
int F_47 ( struct V_1 * V_2 , T_1 V_48 , union V_163 * V_164 )
{
int V_22 = 0 ;
long int V_143 ;
unsigned long V_57 , V_58 ;
switch ( V_48 ) {
case V_165 :
if ( F_48 ( V_48 , * V_164 ) )
V_22 = - V_60 ;
break;
case V_166 :
V_2 -> V_6 . V_167 = F_48 ( V_48 , * V_164 ) ;
break;
case V_168 :
V_2 -> V_6 . V_169 = F_48 ( V_48 , * V_164 ) ;
break;
case V_170 :
V_2 -> V_6 . V_171 = F_48 ( V_48 , * V_164 ) ;
break;
case V_172 :
V_2 -> V_6 . V_173 = F_48 ( V_48 , * V_164 ) ;
break;
case V_174 :
V_2 -> V_6 . V_175 = F_48 ( V_48 , * V_164 ) ;
break;
case V_176 :
V_2 -> V_6 . V_177 = F_48 ( V_48 , * V_164 ) ;
break;
case V_178 ... V_179 :
V_143 = V_48 - V_178 ;
V_2 -> V_6 . V_180 [ V_143 ] = F_48 ( V_48 , * V_164 ) ;
break;
case V_181 ... V_182 :
V_143 = V_48 - V_181 ;
V_2 -> V_6 . V_183 [ V_143 ] = F_48 ( V_48 , * V_164 ) ;
break;
#ifdef F_45
case V_184 ... V_185 :
if ( F_46 ( V_186 ) ) {
long int V_143 = V_48 - V_184 ;
V_2 -> V_6 . V_187 [ 2 * V_143 ] = F_48 ( V_48 , * V_164 ) ;
} else {
V_22 = - V_60 ;
}
break;
case V_188 ... V_189 :
if ( F_46 ( V_186 ) ) {
long int V_143 = V_48 - V_188 ;
V_2 -> V_6 . V_187 [ 2 * V_143 ] = V_164 -> V_190 [ 0 ] ;
V_2 -> V_6 . V_187 [ 2 * V_143 + 1 ] = V_164 -> V_190 [ 1 ] ;
} else {
V_22 = - V_191 ;
}
break;
#endif
case V_192 :
V_57 = F_48 ( V_48 , * V_164 ) ;
V_22 = - V_60 ;
if ( ! V_57 && ( V_2 -> V_6 . V_86 . V_62 ||
V_2 -> V_6 . V_85 . V_62 ) )
break;
V_22 = F_17 ( V_2 , & V_2 -> V_6 . V_53 , V_57 , sizeof( struct V_52 ) ) ;
break;
case V_193 :
V_57 = V_164 -> V_194 . V_57 ;
V_58 = V_164 -> V_194 . V_80 ;
V_22 = - V_60 ;
if ( V_57 && ! V_2 -> V_6 . V_53 . V_62 )
break;
V_22 = F_17 ( V_2 , & V_2 -> V_6 . V_86 , V_57 , V_58 ) ;
break;
case V_195 :
V_57 = V_164 -> V_194 . V_57 ;
V_58 = V_164 -> V_194 . V_80 ;
V_22 = - V_60 ;
if ( V_57 && ( V_58 < sizeof( struct V_83 ) ||
! V_2 -> V_6 . V_53 . V_62 ) )
break;
V_58 -= V_58 % sizeof( struct V_83 ) ;
V_22 = F_17 ( V_2 , & V_2 -> V_6 . V_85 , V_57 , V_58 ) ;
break;
default:
V_22 = - V_60 ;
break;
}
return V_22 ;
}
int F_49 ( void )
{
if ( F_46 ( V_196 ) )
return 0 ;
return - V_197 ;
}
struct V_1 * F_50 ( struct V_44 * V_44 , unsigned int V_48 )
{
struct V_1 * V_2 ;
int V_71 = - V_60 ;
int V_198 ;
struct V_4 * V_7 ;
V_198 = V_48 / V_199 ;
if ( V_198 >= V_200 )
goto V_201;
V_71 = - V_202 ;
V_2 = F_51 ( V_203 , V_204 ) ;
if ( ! V_2 )
goto V_201;
V_71 = F_52 ( V_2 , V_44 , V_48 ) ;
if ( V_71 )
goto V_205;
V_2 -> V_6 . V_206 = & V_2 -> V_6 . V_20 ;
V_2 -> V_6 . V_180 [ 0 ] = V_207 ;
V_2 -> V_6 . V_208 = V_209 ;
V_2 -> V_6 . V_21 = F_53 ( V_210 ) ;
F_8 ( V_2 , V_2 -> V_6 . V_21 ) ;
F_54 ( & V_2 -> V_6 . V_61 ) ;
F_54 ( & V_2 -> V_6 . V_8 ) ;
V_2 -> V_6 . V_17 = V_13 ;
F_55 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_211 ;
F_56 ( & V_2 -> V_6 . V_212 ) ;
F_13 ( & V_44 -> V_51 ) ;
V_7 = V_44 -> V_6 . V_213 [ V_198 ] ;
if ( ! V_7 ) {
V_7 = F_57 ( sizeof( struct V_4 ) , V_204 ) ;
if ( V_7 ) {
F_58 ( & V_7 -> V_214 ) ;
F_54 ( & V_7 -> V_51 ) ;
F_56 ( & V_7 -> V_119 ) ;
V_7 -> V_12 = V_13 ;
}
V_44 -> V_6 . V_213 [ V_198 ] = V_7 ;
V_44 -> V_6 . V_215 ++ ;
}
F_15 ( & V_44 -> V_51 ) ;
if ( ! V_7 )
goto V_205;
F_2 ( & V_7 -> V_51 ) ;
++ V_7 -> V_216 ;
F_4 ( & V_7 -> V_51 ) ;
V_2 -> V_6 . V_7 = V_7 ;
V_2 -> V_6 . V_217 = V_218 ;
F_59 ( V_2 ) ;
return V_2 ;
V_205:
F_60 ( V_203 , V_2 ) ;
V_201:
return F_61 ( V_71 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_6 . V_61 ) ;
if ( V_2 -> V_6 . V_85 . V_65 )
F_21 ( V_2 -> V_44 , V_2 -> V_6 . V_85 . V_65 ) ;
if ( V_2 -> V_6 . V_86 . V_65 )
F_21 ( V_2 -> V_44 , V_2 -> V_6 . V_86 . V_65 ) ;
if ( V_2 -> V_6 . V_53 . V_65 )
F_21 ( V_2 -> V_44 , V_2 -> V_6 . V_53 . V_65 ) ;
F_4 ( & V_2 -> V_6 . V_61 ) ;
F_63 ( V_2 ) ;
F_60 ( V_203 , V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned long V_219 , V_94 ;
V_94 = F_65 () ;
if ( V_94 > V_2 -> V_6 . V_220 ) {
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
return;
}
V_219 = ( V_2 -> V_6 . V_220 - V_94 ) * V_221
/ V_222 ;
F_68 ( & V_2 -> V_6 . V_223 , F_69 ( 0 , V_219 ) ,
V_224 ) ;
V_2 -> V_6 . V_225 = 1 ;
}
static void F_7 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_118 = 0 ;
if ( V_2 -> V_6 . V_225 ) {
F_70 ( & V_2 -> V_6 . V_223 ) ;
V_2 -> V_6 . V_225 = 0 ;
}
}
static void F_71 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
T_1 V_94 ;
if ( V_2 -> V_6 . V_15 != V_226 )
return;
F_2 ( & V_2 -> V_6 . V_8 ) ;
V_94 = F_3 () ;
V_2 -> V_6 . V_18 += F_24 ( V_5 , V_94 ) -
V_2 -> V_6 . V_101 ;
V_2 -> V_6 . V_17 = V_94 ;
V_2 -> V_6 . V_15 = V_16 ;
F_4 ( & V_2 -> V_6 . V_8 ) ;
-- V_5 -> V_227 ;
F_72 ( & V_2 -> V_6 . V_228 ) ;
}
static int F_73 ( int V_3 )
{
struct V_229 * V_230 ;
long V_231 = 1000 ;
V_230 = & V_232 [ V_3 ] ;
V_230 -> V_233 . V_234 = 1 ;
V_230 -> V_233 . V_1 = NULL ;
F_32 () ;
while ( V_230 -> V_233 . V_235 == V_236 ) {
if ( -- V_231 <= 0 ) {
F_10 ( L_15 , V_3 ) ;
return - V_237 ;
}
F_74 ( 1 ) ;
}
return 0 ;
}
static void F_75 ( int V_3 )
{
struct V_229 * V_230 ;
V_230 = & V_232 [ V_3 ] ;
V_230 -> V_233 . V_234 = 0 ;
V_230 -> V_233 . V_1 = NULL ;
}
static void F_76 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_229 * V_230 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_2 -> V_6 . V_225 ) {
F_70 ( & V_2 -> V_6 . V_223 ) ;
V_2 -> V_6 . V_225 = 0 ;
}
V_3 = V_5 -> V_104 + V_2 -> V_6 . V_105 ;
V_230 = & V_232 [ V_3 ] ;
V_230 -> V_233 . V_1 = V_2 ;
V_230 -> V_233 . V_238 = V_5 ;
V_230 -> V_233 . V_239 = 0 ;
V_2 -> V_3 = V_5 -> V_104 ;
F_27 () ;
#if F_77 ( V_240 ) && F_77 ( V_241 )
if ( V_2 -> V_6 . V_105 ) {
F_78 ( V_3 ) ;
++ V_5 -> V_242 ;
}
#endif
}
static void F_79 ( struct V_4 * V_5 )
{
int V_143 ;
F_80 () ;
V_143 = 0 ;
while ( V_5 -> V_243 < V_5 -> V_242 ) {
if ( ++ V_143 >= 1000000 ) {
F_10 ( L_16 ,
V_5 -> V_243 , V_5 -> V_242 ) ;
break;
}
F_81 () ;
}
F_82 () ;
}
static int F_83 ( void )
{
int V_3 = F_84 () ;
int V_244 = F_85 ( V_3 ) ;
if ( V_244 )
return 0 ;
while ( ++ V_244 < V_199 )
if ( F_86 ( V_3 + V_244 ) )
return 0 ;
for ( V_244 = 1 ; V_244 < V_199 ; ++ V_244 ) {
if ( F_73 ( V_3 + V_244 ) ) {
do {
F_75 ( V_3 + V_244 ) ;
} while ( -- V_244 > 0 );
return 0 ;
}
}
return 1 ;
}
static void F_87 ( struct V_4 * V_5 )
{
struct V_1 * V_2 , * V_245 , * V_246 ;
long V_50 ;
T_1 V_94 ;
int V_105 , V_143 , V_247 ;
int V_248 ;
struct V_1 * V_249 [ V_199 ] ;
V_247 = 0 ;
F_88 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( F_89 ( V_2 -> V_6 . V_96 ) )
return;
if ( V_2 -> V_6 . V_53 . V_63 ||
V_2 -> V_6 . V_86 . V_63 ||
V_2 -> V_6 . V_85 . V_63 )
V_249 [ V_247 ++ ] = V_2 ;
}
V_5 -> V_242 = 0 ;
V_5 -> V_243 = 0 ;
V_5 -> V_250 = 0 ;
V_5 -> V_10 = V_251 ;
V_5 -> V_252 = 0 ;
V_5 -> V_253 = 0 ;
if ( V_247 ) {
F_4 ( & V_5 -> V_51 ) ;
for ( V_143 = 0 ; V_143 < V_247 ; ++ V_143 )
F_23 ( V_249 [ V_143 ] ) ;
F_2 ( & V_5 -> V_51 ) ;
}
V_105 = 0 ;
V_245 = NULL ;
F_88 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( ! V_2 -> V_6 . V_118 ) {
if ( ! V_105 )
V_245 = V_2 ;
V_2 -> V_6 . V_105 = V_105 ++ ;
}
}
if ( ! V_245 )
goto V_201;
F_88 (vcpu, &vc->runnable_threads, arch.run_list)
if ( V_2 -> V_6 . V_118 )
V_2 -> V_6 . V_105 = V_105 ++ ;
if ( V_199 > 1 && ! F_83 () ) {
F_88 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_6 . V_50 = - V_237 ;
goto V_201;
}
V_5 -> V_104 = F_84 () ;
F_88 (vcpu, &vc->runnable_threads, arch.run_list) {
F_76 ( V_2 ) ;
F_25 ( V_2 , V_5 ) ;
}
V_5 -> V_10 = V_254 ;
F_90 () ;
F_4 ( & V_5 -> V_51 ) ;
F_91 () ;
V_248 = F_29 ( & V_245 -> V_44 -> V_114 ) ;
F_92 ( NULL , V_245 ) ;
F_2 ( & V_5 -> V_51 ) ;
F_88 (vcpu, &vc->runnable_threads, arch.run_list)
V_2 -> V_3 = - 1 ;
if ( V_5 -> V_243 < V_5 -> V_242 )
F_79 ( V_5 ) ;
for ( V_143 = 0 ; V_143 < V_199 ; ++ V_143 )
F_75 ( V_5 -> V_104 + V_143 ) ;
V_5 -> V_10 = V_255 ;
F_4 ( & V_5 -> V_51 ) ;
F_31 ( & V_245 -> V_44 -> V_114 , V_248 ) ;
F_32 () ;
F_93 () ;
F_94 () ;
F_95 ( V_2 ) ;
F_2 ( & V_5 -> V_51 ) ;
V_94 = F_65 () ;
F_88 (vcpu, &vc->runnable_threads, arch.run_list) {
if ( V_94 < V_2 -> V_6 . V_220 &&
F_96 ( V_2 ) )
F_97 ( V_2 ) ;
V_50 = V_126 ;
if ( V_2 -> V_6 . V_25 )
V_50 = F_36 ( V_2 -> V_6 . V_127 , V_2 ,
V_2 -> V_6 . V_96 ) ;
V_2 -> V_6 . V_50 = V_50 ;
V_2 -> V_6 . V_25 = 0 ;
if ( V_2 -> V_6 . V_118 ) {
if ( V_50 != V_126 )
F_7 ( V_2 ) ;
else
F_64 ( V_2 ) ;
}
}
V_201:
V_5 -> V_10 = V_11 ;
F_98 (vcpu, vnext, &vc->runnable_threads,
arch.run_list) {
if ( V_2 -> V_6 . V_50 != V_126 ) {
F_71 ( V_5 , V_2 ) ;
F_99 ( & V_2 -> V_6 . V_212 ) ;
}
}
}
static void F_100 ( struct V_1 * V_2 , int V_256 )
{
F_101 ( V_257 ) ;
F_102 ( & V_2 -> V_6 . V_212 , & V_257 , V_256 ) ;
if ( V_2 -> V_6 . V_15 == V_226 )
F_103 () ;
F_104 ( & V_2 -> V_6 . V_212 , & V_257 ) ;
}
static void F_105 ( struct V_4 * V_5 )
{
F_101 ( V_257 ) ;
F_102 ( & V_5 -> V_119 , & V_257 , V_258 ) ;
V_5 -> V_10 = V_259 ;
F_4 ( & V_5 -> V_51 ) ;
F_103 () ;
F_104 ( & V_5 -> V_119 , & V_257 ) ;
F_2 ( & V_5 -> V_51 ) ;
V_5 -> V_10 = V_11 ;
}
static int F_106 ( struct V_127 * V_127 , struct V_1 * V_2 )
{
int V_260 ;
struct V_4 * V_5 ;
struct V_1 * V_49 , * V_261 ;
V_127 -> V_132 = 0 ;
V_2 -> V_6 . V_50 = V_126 ;
V_2 -> V_6 . V_25 = 0 ;
F_23 ( V_2 ) ;
V_5 = V_2 -> V_6 . V_7 ;
F_2 ( & V_5 -> V_51 ) ;
V_2 -> V_6 . V_118 = 0 ;
V_2 -> V_6 . V_96 = V_97 ;
V_2 -> V_6 . V_127 = V_127 ;
V_2 -> V_6 . V_101 = F_24 ( V_5 , F_3 () ) ;
V_2 -> V_6 . V_15 = V_226 ;
V_2 -> V_6 . V_17 = V_13 ;
F_107 ( & V_2 -> V_6 . V_228 , & V_5 -> V_214 ) ;
++ V_5 -> V_227 ;
if ( ! F_89 ( V_97 ) ) {
if ( V_5 -> V_10 == V_254 &&
F_108 ( V_5 ) == 0 ) {
V_2 -> V_6 . V_105 = V_5 -> V_227 - 1 ;
F_25 ( V_2 , V_5 ) ;
F_76 ( V_2 ) ;
} else if ( V_5 -> V_10 == V_259 ) {
F_99 ( & V_5 -> V_119 ) ;
}
}
while ( V_2 -> V_6 . V_15 == V_226 &&
! F_89 ( V_97 ) ) {
if ( V_5 -> V_10 != V_11 ) {
F_4 ( & V_5 -> V_51 ) ;
F_100 ( V_2 , V_258 ) ;
F_2 ( & V_5 -> V_51 ) ;
continue;
}
F_98 (v, vn, &vc->runnable_threads,
arch.run_list) {
F_67 ( V_49 ) ;
if ( F_89 ( V_49 -> V_6 . V_96 ) ) {
F_71 ( V_5 , V_49 ) ;
V_49 -> V_120 . V_262 ++ ;
V_49 -> V_6 . V_127 -> V_132 = V_263 ;
V_49 -> V_6 . V_50 = - V_264 ;
F_99 ( & V_49 -> V_6 . V_212 ) ;
}
}
if ( ! V_5 -> V_227 || V_2 -> V_6 . V_15 != V_226 )
break;
V_5 -> V_9 = V_2 ;
V_260 = 0 ;
F_88 (v, &vc->runnable_threads, arch.run_list)
if ( ! V_49 -> V_6 . V_265 )
V_260 += V_49 -> V_6 . V_118 ;
if ( V_260 == V_5 -> V_227 )
F_105 ( V_5 ) ;
else
F_87 ( V_5 ) ;
V_5 -> V_9 = NULL ;
}
while ( V_2 -> V_6 . V_15 == V_226 &&
( V_5 -> V_10 == V_254 ||
V_5 -> V_10 == V_255 ) ) {
F_4 ( & V_5 -> V_51 ) ;
F_100 ( V_2 , V_266 ) ;
F_2 ( & V_5 -> V_51 ) ;
}
if ( V_2 -> V_6 . V_15 == V_226 ) {
F_71 ( V_5 , V_2 ) ;
V_2 -> V_120 . V_262 ++ ;
V_127 -> V_132 = V_263 ;
V_2 -> V_6 . V_50 = - V_264 ;
}
if ( V_5 -> V_227 && V_5 -> V_10 == V_11 ) {
V_49 = F_109 ( & V_5 -> V_214 ,
struct V_1 , V_6 . V_228 ) ;
F_99 ( & V_49 -> V_6 . V_212 ) ;
}
F_4 ( & V_5 -> V_51 ) ;
return V_2 -> V_6 . V_50 ;
}
int F_110 ( struct V_127 * V_128 , struct V_1 * V_2 )
{
int V_22 ;
int V_248 ;
if ( ! V_2 -> V_6 . V_267 ) {
V_128 -> V_132 = V_268 ;
return - V_60 ;
}
F_67 ( V_2 ) ;
if ( F_89 ( V_97 ) ) {
V_128 -> V_132 = V_263 ;
return - V_264 ;
}
F_111 ( & V_2 -> V_44 -> V_6 . V_269 ) ;
F_32 () ;
if ( ! V_2 -> V_44 -> V_6 . V_270 ) {
V_22 = F_112 ( V_2 ) ;
if ( V_22 )
goto V_201;
}
F_113 ( V_97 ) ;
F_114 ( V_97 ) ;
F_115 ( V_97 ) ;
V_2 -> V_6 . V_271 = & V_2 -> V_6 . V_7 -> V_119 ;
V_2 -> V_6 . V_272 = V_97 -> V_273 -> V_274 ;
V_2 -> V_6 . V_15 = V_16 ;
do {
V_22 = F_106 ( V_128 , V_2 ) ;
if ( V_128 -> V_132 == V_147 &&
! ( V_2 -> V_6 . V_20 . V_19 & V_144 ) ) {
V_22 = F_28 ( V_2 ) ;
F_67 ( V_2 ) ;
} else if ( V_22 == V_149 ) {
V_248 = F_29 ( & V_2 -> V_44 -> V_114 ) ;
V_22 = F_116 ( V_128 , V_2 ,
V_2 -> V_6 . V_38 , V_2 -> V_6 . V_39 ) ;
F_31 ( & V_2 -> V_44 -> V_114 , V_248 ) ;
}
} while ( V_22 == V_126 );
V_201:
V_2 -> V_6 . V_15 = V_211 ;
F_117 ( & V_2 -> V_44 -> V_6 . V_269 ) ;
return V_22 ;
}
static inline int F_118 ( unsigned long V_275 )
{
switch ( V_275 ) {
case 32ul << 20 :
if ( F_46 ( V_276 ) )
return 8 ;
return - 1 ;
case 64ul << 20 :
return 3 ;
case 128ul << 20 :
return 7 ;
case 256ul << 20 :
return 4 ;
case 1ul << 30 :
return 2 ;
case 16ul << 30 :
return 1 ;
case 256ul << 30 :
return 0 ;
default:
return - 1 ;
}
}
static int F_119 ( struct V_277 * V_278 , struct V_279 * V_280 )
{
struct V_281 * V_282 = V_278 -> V_283 -> V_284 ;
struct V_285 * V_285 ;
if ( V_280 -> V_286 >= V_282 -> V_287 )
return V_288 ;
V_285 = F_120 ( V_282 -> V_289 + V_280 -> V_286 ) ;
F_121 ( V_285 ) ;
V_280 -> V_285 = V_285 ;
return 0 ;
}
static int F_122 ( struct V_290 * V_290 , struct V_277 * V_278 )
{
V_278 -> V_291 |= V_292 | V_293 ;
V_278 -> V_294 = & V_295 ;
return 0 ;
}
static int F_123 ( struct V_296 * V_296 , struct V_290 * V_297 )
{
struct V_281 * V_282 = V_297 -> V_284 ;
F_124 ( V_282 ) ;
return 0 ;
}
long F_125 ( struct V_44 * V_44 , struct V_298 * V_50 )
{
struct V_281 * V_282 ;
long V_299 ;
V_282 = F_126 () ;
if ( ! V_282 )
return - V_202 ;
V_299 = F_127 ( L_17 , & V_300 , V_282 , V_301 ) ;
if ( V_299 < 0 )
F_124 ( V_282 ) ;
V_50 -> V_275 = V_282 -> V_287 << V_302 ;
return V_299 ;
}
static void F_128 ( struct V_303 * * V_304 ,
int V_305 )
{
struct V_306 * V_307 = & V_308 [ V_305 ] ;
if ( ! V_307 -> V_309 )
return;
( * V_304 ) -> V_310 = V_307 -> V_309 ;
( * V_304 ) -> V_311 = V_307 -> V_312 ;
( * V_304 ) -> V_313 [ 0 ] . V_310 = V_307 -> V_309 ;
( * V_304 ) -> V_313 [ 0 ] . V_314 = V_307 -> V_315 ;
( * V_304 ) ++ ;
}
int F_129 ( struct V_44 * V_44 , struct V_316 * V_317 )
{
struct V_303 * V_304 ;
V_317 -> V_66 = V_318 ;
if ( F_130 ( V_319 ) )
V_317 -> V_66 |= V_320 ;
V_317 -> V_321 = V_322 ;
V_304 = & V_317 -> V_304 [ 0 ] ;
F_128 ( & V_304 , V_323 ) ;
F_128 ( & V_304 , V_324 ) ;
F_128 ( & V_304 , V_325 ) ;
return 0 ;
}
int F_131 ( struct V_44 * V_44 , struct V_326 * log )
{
struct V_327 * V_328 ;
int V_22 ;
unsigned long V_329 ;
F_13 ( & V_44 -> V_330 ) ;
V_22 = - V_60 ;
if ( log -> V_331 >= V_332 )
goto V_201;
V_328 = F_132 ( V_44 -> V_333 , log -> V_331 ) ;
V_22 = - V_334 ;
if ( ! V_328 -> V_335 )
goto V_201;
V_329 = F_133 ( V_328 ) ;
memset ( V_328 -> V_335 , 0 , V_329 ) ;
V_22 = F_134 ( V_44 , V_328 , V_328 -> V_335 ) ;
if ( V_22 )
goto V_201;
V_22 = - V_336 ;
if ( F_135 ( log -> V_335 , V_328 -> V_335 , V_329 ) )
goto V_201;
V_22 = 0 ;
V_201:
F_15 ( & V_44 -> V_330 ) ;
return V_22 ;
}
static void F_136 ( struct V_327 * V_328 )
{
unsigned long * V_337 ;
unsigned long V_160 , V_287 , V_338 ;
struct V_285 * V_285 ;
V_337 = V_328 -> V_6 . V_339 ;
V_287 = V_328 -> V_287 ;
if ( ! V_337 )
return;
for ( V_160 = 0 ; V_160 < V_287 ; V_160 ++ ) {
if ( ! ( V_337 [ V_160 ] & V_340 ) )
continue;
V_338 = V_337 [ V_160 ] >> V_302 ;
V_285 = F_120 ( V_338 ) ;
F_137 ( V_285 ) ;
F_138 ( V_285 ) ;
}
}
void F_139 ( struct V_327 * free ,
struct V_327 * V_341 )
{
if ( ! V_341 || free -> V_6 . V_342 != V_341 -> V_6 . V_342 ) {
F_140 ( free -> V_6 . V_342 ) ;
free -> V_6 . V_342 = NULL ;
}
if ( ! V_341 || free -> V_6 . V_339 != V_341 -> V_6 . V_339 ) {
F_136 ( free ) ;
F_140 ( free -> V_6 . V_339 ) ;
free -> V_6 . V_339 = NULL ;
}
}
int F_141 ( struct V_327 * V_331 ,
unsigned long V_287 )
{
V_331 -> V_6 . V_342 = F_142 ( V_287 * sizeof( * V_331 -> V_6 . V_342 ) ) ;
if ( ! V_331 -> V_6 . V_342 )
return - V_202 ;
V_331 -> V_6 . V_339 = NULL ;
return 0 ;
}
int F_143 ( struct V_44 * V_44 ,
struct V_327 * V_328 ,
struct V_343 * V_344 )
{
unsigned long * V_345 ;
V_345 = V_328 -> V_6 . V_339 ;
if ( ! V_44 -> V_6 . V_346 && ! V_345 && V_328 -> V_287 ) {
V_345 = F_142 ( V_328 -> V_287 * sizeof( unsigned long ) ) ;
if ( ! V_345 )
return - V_202 ;
V_328 -> V_6 . V_339 = V_345 ;
}
return 0 ;
}
void F_144 ( struct V_44 * V_44 ,
struct V_343 * V_344 ,
struct V_327 V_347 )
{
unsigned long V_287 = V_344 -> V_348 >> V_302 ;
struct V_327 * V_328 ;
if ( V_287 && V_347 . V_287 ) {
V_328 = F_132 ( V_44 -> V_333 , V_344 -> V_331 ) ;
F_134 ( V_44 , V_328 , NULL ) ;
}
}
static int F_112 ( struct V_1 * V_2 )
{
int V_71 = 0 ;
struct V_44 * V_44 = V_2 -> V_44 ;
struct V_281 * V_282 = NULL ;
unsigned long V_349 ;
struct V_327 * V_328 ;
struct V_277 * V_278 ;
unsigned long V_45 , V_350 ;
unsigned long V_351 , V_352 ;
unsigned long V_275 ;
unsigned long V_353 ;
unsigned long * V_337 ;
unsigned long V_143 , V_287 ;
int V_248 ;
F_13 ( & V_44 -> V_51 ) ;
if ( V_44 -> V_6 . V_270 )
goto V_201;
if ( ! V_44 -> V_6 . V_354 ) {
V_71 = F_145 ( V_44 , NULL ) ;
if ( V_71 ) {
F_10 ( L_18 ) ;
goto V_201;
}
}
V_248 = F_29 ( & V_44 -> V_114 ) ;
V_328 = F_146 ( V_44 , 0 ) ;
V_71 = - V_60 ;
if ( ! V_328 || ( V_328 -> V_66 & V_355 ) )
goto V_356;
V_349 = V_328 -> V_357 ;
F_147 ( & V_97 -> V_273 -> V_358 ) ;
V_278 = F_148 ( V_97 -> V_273 , V_349 ) ;
if ( ! V_278 || V_278 -> V_359 > V_349 || ( V_278 -> V_291 & V_360 ) )
goto V_361;
V_351 = F_149 ( V_278 ) ;
V_352 = F_150 ( V_351 ) ;
if ( V_278 -> V_283 && V_278 -> V_283 -> V_362 == & V_300 &&
V_349 == V_278 -> V_359 )
V_282 = V_278 -> V_283 -> V_284 ;
F_151 ( & V_97 -> V_273 -> V_358 ) ;
if ( ! V_282 ) {
V_71 = - V_363 ;
if ( F_46 ( V_364 ) ) {
F_10 ( L_19 ) ;
goto V_356;
}
V_71 = - V_60 ;
if ( ! ( V_351 == 0x1000 || V_351 == 0x10000 ||
V_351 == 0x1000000 ) )
goto V_356;
V_350 = F_152 ( V_351 ) ;
V_44 -> V_6 . V_365 = V_350 | V_366 |
( V_367 << V_368 ) ;
V_45 = V_44 -> V_6 . V_45 & ~ V_369 ;
V_45 |= V_350 << ( V_370 - 4 ) ;
V_44 -> V_6 . V_45 = V_45 ;
F_153 ( V_2 , V_328 , V_352 ) ;
} else {
V_275 = V_282 -> V_287 ;
if ( V_275 > V_328 -> V_287 )
V_275 = V_328 -> V_287 ;
V_275 <<= V_302 ;
V_353 = F_118 ( V_275 ) ;
V_71 = - V_60 ;
if ( V_353 < 0 ) {
F_10 ( L_20 , V_275 ) ;
goto V_356;
}
F_111 ( & V_282 -> V_371 ) ;
V_44 -> V_6 . V_372 = V_282 ;
V_45 = V_44 -> V_6 . V_45 ;
if ( F_46 ( V_364 ) ) {
V_45 &= ~ ( ( 1ul << V_373 ) |
( 3ul << V_374 ) ) ;
V_45 |= ( ( V_353 >> 2 ) << V_373 ) |
( ( V_353 & 3 ) << V_374 ) ;
V_45 |= ( ( V_282 -> V_289 >> ( 26 - V_302 ) ) & 0xffff )
<< V_375 ;
} else {
V_45 &= ~ ( V_376 | V_377 ) ;
V_45 |= V_353 << V_378 ;
V_44 -> V_6 . V_379 = V_44 -> V_6 . V_372 -> V_289 << V_302 ;
}
V_44 -> V_6 . V_45 = V_45 ;
F_154 ( L_21 ,
V_282 -> V_289 << V_302 , V_275 , V_45 ) ;
V_287 = V_282 -> V_287 ;
V_352 = F_150 ( V_287 ) ;
V_337 = V_328 -> V_6 . V_339 ;
if ( V_337 ) {
if ( V_287 > V_328 -> V_287 )
V_287 = V_328 -> V_287 ;
F_2 ( & V_44 -> V_6 . V_380 ) ;
for ( V_143 = 0 ; V_143 < V_287 ; ++ V_143 )
V_337 [ V_143 ] = ( ( V_282 -> V_289 + V_143 ) << V_302 ) +
V_352 ;
F_4 ( & V_44 -> V_6 . V_380 ) ;
}
}
F_27 () ;
V_44 -> V_6 . V_270 = 1 ;
V_71 = 0 ;
V_356:
F_31 ( & V_44 -> V_114 , V_248 ) ;
V_201:
F_15 ( & V_44 -> V_51 ) ;
return V_71 ;
V_361:
F_151 ( & V_97 -> V_273 -> V_358 ) ;
goto V_201;
}
int F_155 ( struct V_44 * V_44 )
{
unsigned long V_45 , V_381 ;
V_381 = F_156 () ;
if ( V_381 < 0 )
return - V_202 ;
V_44 -> V_6 . V_381 = V_381 ;
F_157 ( & V_44 -> V_6 . V_382 ) ;
F_58 ( & V_44 -> V_6 . V_383 ) ;
V_44 -> V_6 . V_372 = NULL ;
V_44 -> V_6 . V_384 = F_53 ( V_385 ) ;
if ( F_46 ( V_364 ) ) {
V_44 -> V_6 . V_386 = 0 ;
V_44 -> V_6 . V_387 = V_45 = F_53 ( V_388 ) ;
V_45 &= ~ ( ( 3 << V_389 ) | ( 0xful << V_390 ) ) ;
V_45 |= ( ( V_381 >> 4 ) << V_389 ) |
( ( V_381 & 0xf ) << V_390 ) ;
} else {
V_44 -> V_6 . V_386 = F_53 ( V_391 ) ;
V_44 -> V_6 . V_387 = V_45 = F_53 ( V_392 ) ;
V_45 &= V_393 | V_394 ;
V_45 |= ( 4UL << V_395 ) | V_396 |
V_376 | V_397 ;
V_44 -> V_6 . V_365 = V_366 |
( V_367 << V_368 ) ;
}
V_44 -> V_6 . V_45 = V_45 ;
V_44 -> V_6 . V_346 = ! ! F_46 ( V_276 ) ;
F_54 ( & V_44 -> V_6 . V_380 ) ;
F_158 () ;
return 0 ;
}
void F_159 ( struct V_44 * V_44 )
{
F_160 () ;
if ( V_44 -> V_6 . V_372 ) {
F_124 ( V_44 -> V_6 . V_372 ) ;
V_44 -> V_6 . V_372 = NULL ;
}
F_161 ( V_44 ) ;
F_162 ( ! F_163 ( & V_44 -> V_6 . V_383 ) ) ;
}
void F_164 ( struct V_1 * V_2 , T_3 V_398 , T_3 V_399 )
{
}
int F_165 ( struct V_127 * V_128 , struct V_1 * V_2 ,
unsigned int V_400 , int * V_401 )
{
return V_402 ;
}
int F_166 ( struct V_1 * V_2 , int V_403 , T_3 V_404 )
{
return V_402 ;
}
int F_167 ( struct V_1 * V_2 , int V_403 , T_3 * V_404 )
{
return V_402 ;
}
static int F_168 ( void )
{
int V_22 ;
V_22 = F_169 ( NULL , sizeof( struct V_1 ) , 0 , V_405 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_170 () ;
return V_22 ;
}
static void F_171 ( void )
{
F_172 () ;
}
