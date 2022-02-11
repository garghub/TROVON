static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_2 , L_1 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] . V_6 == ( V_3 & 0x1F ) ) {
F_4 ( V_2 , V_5 [ V_4 ] . V_7 ) ;
break;
}
}
if ( V_4 == F_3 ( V_5 ) )
F_2 ( V_2 , L_2 ) ;
F_4 ( V_2 , L_3 , V_3 & V_8 ? 1 : 0 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_2 , L_4 , V_3 & 0xFFFF , ( V_3 >> 16 ) & 0xFFFF ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_2 , L_5 , V_3 & 0xFFFF , ( V_3 >> 16 ) & 0xFFFF ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_2 , L_6 , V_3 & 0xFFFF , ( V_3 >> 16 ) & 0xFFFF ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_9 * V_10 , int V_3 )
{
void * V_11 = NULL ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
if ( V_10 -> V_13 [ V_4 ] . V_14 == V_3 ) {
V_11 = V_10 -> V_13 [ V_4 ] . V_15 ;
break;
}
if ( V_10 -> V_13 [ V_4 ] . V_16 == V_3 ) {
V_11 = V_10 -> V_13 [ V_4 ] . V_17 ;
break;
}
}
if ( V_11 )
F_4 ( V_2 , L_7 , V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 & V_18 )
F_2 ( V_2 , L_8 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 & 1 )
F_2 ( V_2 , L_9 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_19 )
{
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_9 * V_10 = (struct V_9 * ) V_21 -> V_23 -> V_19 ;
struct V_24 * V_25 = V_21 -> V_26 -> V_25 ;
struct V_27 * V_27 = & V_10 -> V_28 . V_27 ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_31 ;
V_31 = F_12 ( & V_25 -> V_32 ) ;
if ( V_31 )
return V_31 ;
F_4 ( V_2 , L_10 ,
F_13 ( & V_10 -> V_28 ) , V_10 -> V_33 ) ;
F_14 ( V_34 ) ;
F_1 ( V_2 , F_15 ( V_10 -> V_33 + V_35 ) ) ;
F_14 ( V_36 ) ;
F_14 ( V_37 ) ;
F_5 ( V_2 , F_15 ( V_10 -> V_33 + V_38 ) ) ;
F_14 ( V_39 ) ;
F_6 ( V_2 , F_15 ( V_10 -> V_33 + V_40 ) ) ;
F_14 ( V_41 ) ;
F_14 ( V_42 ) ;
F_14 ( V_43 ) ;
F_7 ( V_2 , F_15 ( V_10 -> V_33 + V_44 ) ) ;
F_14 ( V_45 ) ;
F_8 ( V_2 , V_10 , F_15 ( V_10 -> V_33 + V_46 ) ) ;
F_14 ( V_47 ) ;
F_14 ( V_48 ) ;
F_14 ( V_49 ) ;
F_9 ( V_2 , F_15 ( V_10 -> V_33 + V_50 ) ) ;
F_14 ( V_51 ) ;
F_14 ( V_52 ) ;
F_10 ( V_2 , F_15 ( V_10 -> V_33 + V_53 ) ) ;
F_2 ( V_2 , L_11 ) ;
if ( ! V_30 )
F_2 ( V_2 , L_12 ) ;
else
F_4 ( V_2 , L_13 ,
V_30 -> V_11 . V_54 , F_16 ( F_17 ( V_30 ) ) ) ;
F_18 ( & V_25 -> V_32 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_55 * V_21 )
{
F_4 ( V_2 , L_14 , V_21 ) ;
F_4 ( V_2 , L_15 , V_21 -> V_56 ) ;
F_1 ( V_2 , V_21 -> V_56 ) ;
F_4 ( V_2 , L_16 , V_21 -> V_57 ) ;
F_4 ( V_2 , L_17 , V_21 -> V_58 ) ;
F_5 ( V_2 , V_21 -> V_58 ) ;
F_4 ( V_2 , L_18 , V_21 -> V_59 ) ;
F_6 ( V_2 , V_21 -> V_59 ) ;
F_4 ( V_2 , L_19 , V_21 -> V_60 ) ;
F_4 ( V_2 , L_20 , V_21 -> V_61 ) ;
F_4 ( V_2 , L_21 , V_21 -> V_62 ) ;
F_7 ( V_2 , V_21 -> V_62 ) ;
F_4 ( V_2 , L_22 , V_21 -> V_63 ) ;
F_4 ( V_2 , L_23 , V_21 -> V_64 ) ;
F_4 ( V_2 , L_24 , V_21 -> V_65 ) ;
F_4 ( V_2 , L_25 , V_21 -> V_66 ) ;
F_9 ( V_2 , V_21 -> V_66 ) ;
F_4 ( V_2 , L_26 , V_21 -> V_67 ) ;
F_2 ( V_2 , L_27 ) ;
}
static int F_20 ( struct V_1 * V_2 , void * V_68 )
{
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_9 * V_10 = (struct V_9 * ) V_21 -> V_23 -> V_19 ;
struct V_24 * V_25 = V_21 -> V_26 -> V_25 ;
unsigned int V_69 ;
int V_31 ;
V_31 = F_12 ( & V_25 -> V_32 ) ;
if ( V_31 )
return V_31 ;
for ( V_69 = 0 ; V_69 < V_12 ; V_69 ++ ) {
F_4 ( V_2 , L_28 , F_13 ( & V_10 -> V_28 ) , V_69 ) ;
F_19 ( V_2 , V_10 -> V_13 [ V_69 ] . V_15 ) ;
F_4 ( V_2 , L_29 , F_13 ( & V_10 -> V_28 ) , V_69 ) ;
F_19 ( V_2 , V_10 -> V_13 [ V_69 ] . V_17 ) ;
}
F_18 ( & V_25 -> V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 , struct V_70 * V_26 )
{
unsigned int V_4 ;
struct V_71 * V_72 ;
int V_73 ;
switch ( V_10 -> V_28 . V_74 ) {
case V_75 :
V_72 = V_76 ;
V_73 = F_3 ( V_76 ) ;
break;
case V_77 :
V_72 = V_78 ;
V_73 = F_3 ( V_78 ) ;
break;
case V_79 :
V_72 = V_80 ;
V_73 = F_3 ( V_80 ) ;
break;
case V_81 :
V_72 = V_82 ;
V_73 = F_3 ( V_82 ) ;
break;
default:
return - V_83 ;
}
for ( V_4 = 0 ; V_4 < V_73 ; V_4 ++ )
V_72 [ V_4 ] . V_19 = V_10 ;
return F_22 ( V_72 ,
V_73 ,
V_26 -> V_84 , V_26 ) ;
}
static int F_23 ( int V_85 )
{
switch ( V_85 ) {
case V_86 :
return V_87 ;
case V_88 :
return V_89 ;
case V_90 :
return V_91 ;
case V_92 :
return V_93 ;
case V_94 :
return V_95 ;
case V_96 :
return V_97 ;
case V_98 :
return V_99 ;
case V_100 :
return V_101 ;
}
return - 1 ;
}
static int F_24 ( int V_6 )
{
switch ( V_6 ) {
case V_102 :
case V_91 :
case V_93 :
return V_103 ;
}
return 0 ;
}
static struct V_104 * F_25 ( struct V_9 * V_10 )
{
int V_105 ;
unsigned int V_4 ;
V_105 = F_15 ( V_10 -> V_33 + V_46 ) ;
if ( ! V_105 )
goto V_106;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ )
if ( ( V_105 != V_10 -> V_13 [ V_4 ] . V_16 ) &&
( V_105 != V_10 -> V_13 [ V_4 ] . V_14 ) )
return & V_10 -> V_13 [ V_4 ] ;
F_26 ( L_30 ,
F_13 ( & V_10 -> V_28 ) , V_105 ) ;
V_106:
return & V_10 -> V_13 [ 0 ] ;
}
static
struct V_104 * F_27 ( struct V_9 * V_10 )
{
int V_105 ;
unsigned int V_4 ;
V_105 = F_15 ( V_10 -> V_33 + V_46 ) ;
if ( ! V_105 )
goto V_106;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ )
if ( ( V_105 == V_10 -> V_13 [ V_4 ] . V_16 ) ||
( V_105 == V_10 -> V_13 [ V_4 ] . V_14 ) )
return & V_10 -> V_13 [ V_4 ] ;
V_106:
F_28 ( L_31 ,
V_105 , F_13 ( & V_10 -> V_28 ) ) ;
return NULL ;
}
static void F_29 ( struct V_9 * V_10 )
{
unsigned int V_4 ;
F_28 ( L_32 , F_13 ( & V_10 -> V_28 ) ) ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_10 -> V_13 [ V_4 ] . V_15 -> V_66 |= V_18 ;
V_10 -> V_13 [ V_4 ] . V_17 -> V_66 |= V_18 ;
}
if ( F_30 ( V_10 -> V_107 , & V_10 -> V_108 ) )
F_28 ( L_33 ) ;
if ( V_10 -> V_109 )
F_31 ( V_10 -> V_109 ) ;
V_10 -> V_28 . V_110 = V_111 ;
}
int F_32 ( struct V_112 * V_113 ,
unsigned long V_114 , void * V_19 )
{
struct V_9 * V_10 = F_33 ( V_113 , struct V_9 , V_108 ) ;
if ( V_10 -> V_28 . V_110 == V_115 ) {
F_28 ( L_34 ,
F_13 ( & V_10 -> V_28 ) ) ;
F_29 ( V_10 ) ;
}
switch ( V_114 ) {
case V_116 :
V_10 -> V_117 = true ;
break;
case V_118 :
V_10 -> V_117 = false ;
break;
default:
F_26 ( L_35 , V_114 ) ;
break;
}
return 0 ;
}
static void F_34 ( struct V_9 * V_10 )
{
struct V_119 * V_120 = V_10 -> V_25 -> V_121 ;
T_1 V_122 ;
void * V_11 ;
unsigned int V_4 , V_123 ;
V_123 = sizeof( struct V_55 ) *
V_124 * V_12 ;
V_11 = F_35 ( V_10 -> V_25 , V_123 , & V_122 , V_125 | V_126 ) ;
if ( ! V_11 ) {
F_26 ( L_36 ) ;
return;
}
memset ( V_11 , 0 , V_123 ) ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
if ( V_122 & 0xF ) {
F_26 ( L_37 ) ;
return;
}
V_10 -> V_13 [ V_4 ] . V_15 = V_11 ;
V_10 -> V_13 [ V_4 ] . V_14 = V_122 ;
F_28 ( L_38 , V_4 , V_11 ) ;
V_11 += sizeof( struct V_55 ) ;
V_122 += sizeof( struct V_55 ) ;
if ( V_122 & 0xF ) {
F_26 ( L_37 ) ;
return;
}
V_10 -> V_13 [ V_4 ] . V_17 = V_11 ;
V_10 -> V_13 [ V_4 ] . V_16 = V_122 ;
F_28 ( L_39 , V_4 , V_11 ) ;
V_11 += sizeof( struct V_55 ) ;
V_122 += sizeof( struct V_55 ) ;
}
if ( F_36 ( V_120 , L_40 ) ) {
char * V_127 ;
switch ( V_10 -> V_28 . V_74 ) {
case V_75 :
V_127 = L_41 ;
break;
case V_77 :
V_127 = L_42 ;
break;
case V_79 :
V_127 = L_43 ;
break;
case V_81 :
V_127 = L_44 ;
break;
default:
F_26 ( L_45 ) ;
return;
}
V_10 -> V_109 = F_37 ( V_10 -> V_25 , V_127 ) ;
if ( F_38 ( V_10 -> V_109 ) )
F_26 ( L_46 , V_127 ) ;
V_10 -> V_128 = F_37 ( V_10 -> V_25 , L_47 ) ;
if ( F_38 ( V_10 -> V_128 ) )
F_26 ( L_48 ) ;
V_10 -> V_129 = F_37 ( V_10 -> V_25 , L_49 ) ;
if ( F_38 ( V_10 -> V_129 ) )
F_26 ( L_50 ) ;
}
}
static int F_39 ( struct V_130 * V_25 , int V_131 , int V_132 )
{
if ( V_131 == V_132 )
return V_131 ;
if ( V_131 < V_132 ) {
F_40 ( V_25 , L_51 ) ;
return V_131 ;
}
F_40 ( V_25 , L_52 ) ;
return V_132 ;
}
static int F_41 ( struct V_27 * V_27 ,
struct V_133 * V_134 )
{
struct V_135 * V_28 = F_42 ( V_27 ) ;
struct V_9 * V_10 = F_43 ( V_28 ) ;
struct V_29 * V_30 = V_134 -> V_30 ;
struct V_136 * V_137 = F_44 ( V_10 -> V_25 ) ;
struct V_138 * V_139 = V_134 -> V_139 ;
bool V_140 = V_28 -> V_110 == V_111 ? true : false ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
int V_147 , V_148 , V_149 , V_150 ;
int V_151 , V_152 , V_153 , V_154 ;
int V_6 ;
if ( ! V_30 || ! V_139 )
return 0 ;
V_144 = F_17 ( V_30 ) ;
V_142 = F_45 ( V_134 -> V_134 , V_30 ) ;
V_146 = & V_142 -> V_146 ;
V_147 = V_134 -> V_155 ;
V_148 = V_134 -> V_156 ;
V_149 = F_46 ( V_134 -> V_157 , 0 , V_146 -> V_158 - V_147 ) ;
V_150 = F_46 ( V_134 -> V_159 , 0 , V_146 -> V_160 - V_148 ) ;
V_151 = V_134 -> V_151 >> 16 ;
V_152 = V_134 -> V_152 >> 16 ;
V_153 = F_46 ( V_134 -> V_153 >> 16 , 0 , V_161 ) ;
V_154 = F_46 ( V_134 -> V_154 >> 16 , 0 , V_161 ) ;
V_6 = F_23 ( V_139 -> V_162 ) ;
if ( V_6 == - 1 ) {
F_26 ( L_53 ,
( char * ) & V_139 -> V_162 ) ;
return - V_83 ;
}
if ( ! F_47 ( V_139 , 0 ) ) {
F_26 ( L_54 ) ;
return - V_83 ;
}
if ( V_140 ) {
V_10 -> V_107 = V_144 -> V_54 == V_163 ?
V_137 -> V_164 : V_137 -> V_165 ;
if ( F_48 ( V_10 -> V_107 ,
& V_10 -> V_108 , V_30 ) ) {
F_26 ( L_55 ) ;
return - V_83 ;
}
if ( V_10 -> V_109 ) {
struct V_166 * V_167 ;
int V_168 = V_146 -> clock * 1000 ;
int V_169 ;
if ( V_144 -> V_54 == V_163 )
V_167 = V_10 -> V_128 ;
else
V_167 = V_10 -> V_129 ;
if ( V_167 )
F_49 ( V_10 -> V_109 , V_167 ) ;
V_169 = F_50 ( V_10 -> V_109 , V_168 ) ;
if ( V_169 < 0 ) {
F_26 ( L_56 ,
V_168 ) ;
return - V_83 ;
}
if ( F_51 ( V_10 -> V_109 ) ) {
F_26 ( L_57 ) ;
return - V_83 ;
}
}
}
F_52 ( L_58 ,
V_30 -> V_11 . V_54 , F_16 ( V_144 ) ,
V_27 -> V_11 . V_54 , F_13 ( V_28 ) ) ;
F_52 ( L_59 ,
F_13 ( V_28 ) ,
V_149 , V_150 , V_147 , V_148 ,
V_153 , V_154 , V_151 , V_152 ) ;
return 0 ;
}
static void F_53 ( struct V_27 * V_27 ,
struct V_133 * V_170 )
{
struct V_133 * V_134 = V_27 -> V_134 ;
struct V_135 * V_28 = F_42 ( V_27 ) ;
struct V_9 * V_10 = F_43 ( V_28 ) ;
struct V_29 * V_30 = V_134 -> V_30 ;
struct V_138 * V_139 = V_134 -> V_139 ;
struct V_145 * V_146 ;
int V_147 , V_148 , V_149 , V_150 ;
int V_151 , V_152 , V_153 , V_154 ;
struct V_171 * V_172 ;
struct V_104 * V_173 ;
struct V_104 * V_174 ;
struct V_55 * V_15 , * V_17 ;
T_2 V_175 ;
T_2 V_176 ;
int V_6 ;
unsigned int V_177 , V_178 ;
T_2 V_179 , V_180 , V_181 , V_182 ;
if ( ! V_30 || ! V_139 )
return;
V_146 = & V_30 -> V_146 ;
V_147 = V_134 -> V_155 ;
V_148 = V_134 -> V_156 ;
V_149 = F_46 ( V_134 -> V_157 , 0 , V_146 -> V_158 - V_147 ) ;
V_150 = F_46 ( V_134 -> V_159 , 0 , V_146 -> V_160 - V_148 ) ;
V_151 = V_134 -> V_151 >> 16 ;
V_152 = V_134 -> V_152 >> 16 ;
V_153 = F_46 ( V_134 -> V_153 >> 16 , 0 , V_161 ) ;
V_154 = F_46 ( V_134 -> V_154 >> 16 , 0 , V_161 ) ;
V_173 = F_25 ( V_10 ) ;
V_15 = V_173 -> V_15 ;
V_17 = V_173 -> V_17 ;
F_40 ( V_10 -> V_25 , L_60 , V_183 ,
F_13 ( V_28 ) , V_15 , V_17 ) ;
V_15 -> V_57 = V_184 ;
V_15 -> V_56 = V_8 ;
V_6 = F_23 ( V_139 -> V_162 ) ;
V_15 -> V_56 |= V_6 ;
V_15 -> V_56 |= F_24 ( V_6 ) ;
V_15 -> V_66 &= ~ V_18 ;
V_172 = F_47 ( V_139 , 0 ) ;
F_28 ( L_61 , V_139 -> V_11 . V_54 ,
( char * ) & V_139 -> V_162 ,
( unsigned long ) V_172 -> V_185 ) ;
F_54 ( V_139 -> V_162 , & V_177 , & V_178 ) ;
V_15 -> V_60 = ( T_2 ) V_172 -> V_185 + V_139 -> V_186 [ 0 ] ;
V_15 -> V_60 += V_151 * ( V_178 >> 3 ) ;
V_15 -> V_60 += V_152 * V_139 -> V_187 [ 0 ] ;
V_149 = F_39 ( V_10 -> V_25 , V_149 , V_153 ) ;
V_150 = F_39 ( V_10 -> V_25 , V_150 , V_154 ) ;
V_179 = F_55 ( * V_146 , V_148 ) ;
V_181 = F_55 ( * V_146 , V_148 + V_150 - 1 ) ;
V_180 = F_56 ( * V_146 , V_147 ) ;
V_182 = F_56 ( * V_146 , V_147 + V_149 - 1 ) ;
V_15 -> V_58 = ( V_179 << 16 ) | V_180 ;
V_15 -> V_59 = ( V_181 << 16 ) | V_182 ;
V_153 = V_149 ;
V_15 -> V_61 = V_139 -> V_187 [ 0 ] ;
V_15 -> V_62 = V_154 << 16 | V_153 ;
memcpy ( V_17 , V_15 , sizeof( * V_17 ) ) ;
V_15 -> V_63 = V_173 -> V_16 ;
V_17 -> V_63 = V_173 -> V_14 ;
if ( V_146 -> V_188 & V_189 )
V_17 -> V_60 = V_15 -> V_60 +
V_139 -> V_187 [ 0 ] ;
V_174 = F_27 ( V_10 ) ;
V_175 = V_173 -> V_14 ;
V_176 = V_173 -> V_16 ;
F_40 ( V_10 -> V_25 , L_62 ,
F_15 ( V_10 -> V_33 + V_46 ) ) ;
F_40 ( V_10 -> V_25 , L_63 ,
( unsigned long ) V_172 -> V_185 ,
F_15 ( V_10 -> V_33 + V_190 ) ) ;
if ( ! V_174 ) {
F_28 ( L_64 ,
F_13 ( V_28 ) ) ;
F_57 ( V_10 -> V_117 ?
V_176 : V_175 ,
V_10 -> V_33 + V_46 ) ;
goto V_106;
}
if ( V_146 -> V_188 & V_189 ) {
if ( V_10 -> V_117 ) {
V_174 -> V_17 -> V_63 = V_175 ;
} else {
F_57 ( V_175 ,
V_10 -> V_33 + V_46 ) ;
}
} else {
F_57 ( V_175 , V_10 -> V_33 + V_46 ) ;
}
V_106:
F_58 ( V_28 , true , false ) ;
V_28 -> V_110 = V_191 ;
}
static void F_59 ( struct V_27 * V_27 ,
struct V_133 * V_170 )
{
struct V_135 * V_28 = F_42 ( V_27 ) ;
if ( ! V_27 -> V_30 ) {
F_28 ( L_65 ,
V_27 -> V_11 . V_54 ) ;
return;
}
F_28 ( L_58 ,
V_27 -> V_30 -> V_11 . V_54 ,
F_16 ( F_17 ( V_27 -> V_30 ) ) ,
V_27 -> V_11 . V_54 , F_13 ( V_28 ) ) ;
V_28 -> V_110 = V_192 ;
}
struct V_27 * F_60 ( struct V_24 * V_193 ,
struct V_130 * V_25 , int V_74 ,
void T_3 * V_194 ,
unsigned int V_195 ,
enum V_196 type )
{
struct V_9 * V_10 ;
int V_169 ;
V_10 = F_61 ( V_25 , sizeof( * V_10 ) , V_125 ) ;
if ( ! V_10 ) {
F_26 ( L_66 ) ;
return NULL ;
}
V_10 -> V_25 = V_25 ;
V_10 -> V_33 = V_194 ;
V_10 -> V_28 . V_74 = V_74 ;
V_10 -> V_28 . V_110 = V_111 ;
V_10 -> V_108 . V_197 = F_32 ;
F_34 ( V_10 ) ;
V_169 = F_62 ( V_193 , & V_10 -> V_28 . V_27 ,
V_195 ,
& V_198 ,
V_199 ,
F_3 ( V_199 ) ,
type , NULL ) ;
if ( V_169 ) {
F_26 ( L_67 ) ;
goto V_200;
}
F_63 ( & V_10 -> V_28 . V_27 , & V_201 ) ;
F_64 ( & V_10 -> V_28 , type ) ;
if ( F_21 ( V_10 , V_193 -> V_202 ) )
F_26 ( L_68 ) ;
return & V_10 -> V_28 . V_27 ;
V_200:
F_65 ( V_25 , V_10 ) ;
return NULL ;
}
