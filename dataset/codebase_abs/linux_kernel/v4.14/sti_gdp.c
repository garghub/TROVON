static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_2 , L_1 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_5 ) ; V_4 ++ ) {
if ( V_5 [ V_4 ] . V_6 == ( V_3 & 0x1F ) ) {
F_2 ( V_2 , V_5 [ V_4 ] . V_7 ) ;
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
struct V_24 * V_24 = & V_10 -> V_25 . V_24 ;
struct V_26 * V_27 = V_24 -> V_27 ;
F_4 ( V_2 , L_10 ,
F_12 ( & V_10 -> V_25 ) , V_10 -> V_28 ) ;
F_13 ( V_29 ) ;
F_1 ( V_2 , F_14 ( V_10 -> V_28 + V_30 ) ) ;
F_13 ( V_31 ) ;
F_13 ( V_32 ) ;
F_5 ( V_2 , F_14 ( V_10 -> V_28 + V_33 ) ) ;
F_13 ( V_34 ) ;
F_6 ( V_2 , F_14 ( V_10 -> V_28 + V_35 ) ) ;
F_13 ( V_36 ) ;
F_13 ( V_37 ) ;
F_13 ( V_38 ) ;
F_7 ( V_2 , F_14 ( V_10 -> V_28 + V_39 ) ) ;
F_13 ( V_40 ) ;
F_8 ( V_2 , V_10 , F_14 ( V_10 -> V_28 + V_41 ) ) ;
F_13 ( V_42 ) ;
F_13 ( V_43 ) ;
F_13 ( V_44 ) ;
F_9 ( V_2 , F_14 ( V_10 -> V_28 + V_45 ) ) ;
F_13 ( V_46 ) ;
F_13 ( V_47 ) ;
F_10 ( V_2 , F_14 ( V_10 -> V_28 + V_48 ) ) ;
F_2 ( V_2 , L_11 ) ;
if ( ! V_27 )
F_2 ( V_2 , L_12 ) ;
else
F_4 ( V_2 , L_13 ,
V_27 -> V_11 . V_49 , F_15 ( F_16 ( V_27 ) ) ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_50 * V_21 )
{
F_4 ( V_2 , L_14 , V_21 ) ;
F_4 ( V_2 , L_15 , V_21 -> V_51 ) ;
F_1 ( V_2 , V_21 -> V_51 ) ;
F_4 ( V_2 , L_16 , V_21 -> V_52 ) ;
F_4 ( V_2 , L_17 , V_21 -> V_53 ) ;
F_5 ( V_2 , V_21 -> V_53 ) ;
F_4 ( V_2 , L_18 , V_21 -> V_54 ) ;
F_6 ( V_2 , V_21 -> V_54 ) ;
F_4 ( V_2 , L_19 , V_21 -> V_55 ) ;
F_4 ( V_2 , L_20 , V_21 -> V_56 ) ;
F_4 ( V_2 , L_21 , V_21 -> V_57 ) ;
F_7 ( V_2 , V_21 -> V_57 ) ;
F_4 ( V_2 , L_22 , V_21 -> V_58 ) ;
F_4 ( V_2 , L_23 , V_21 -> V_59 ) ;
F_4 ( V_2 , L_24 , V_21 -> V_60 ) ;
F_4 ( V_2 , L_25 , V_21 -> V_61 ) ;
F_9 ( V_2 , V_21 -> V_61 ) ;
F_4 ( V_2 , L_26 , V_21 -> V_62 ) ;
}
static int F_18 ( struct V_1 * V_2 , void * V_63 )
{
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_9 * V_10 = (struct V_9 * ) V_21 -> V_23 -> V_19 ;
unsigned int V_64 ;
for ( V_64 = 0 ; V_64 < V_12 ; V_64 ++ ) {
F_4 ( V_2 , L_27 , F_12 ( & V_10 -> V_25 ) , V_64 ) ;
F_17 ( V_2 , V_10 -> V_13 [ V_64 ] . V_15 ) ;
F_4 ( V_2 , L_28 , F_12 ( & V_10 -> V_25 ) , V_64 ) ;
F_17 ( V_2 , V_10 -> V_13 [ V_64 ] . V_17 ) ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_10 , struct V_65 * V_66 )
{
unsigned int V_4 ;
struct V_67 * V_68 ;
int V_69 ;
switch ( V_10 -> V_25 . V_70 ) {
case V_71 :
V_68 = V_72 ;
V_69 = F_3 ( V_72 ) ;
break;
case V_73 :
V_68 = V_74 ;
V_69 = F_3 ( V_74 ) ;
break;
case V_75 :
V_68 = V_76 ;
V_69 = F_3 ( V_76 ) ;
break;
case V_77 :
V_68 = V_78 ;
V_69 = F_3 ( V_78 ) ;
break;
default:
return - V_79 ;
}
for ( V_4 = 0 ; V_4 < V_69 ; V_4 ++ )
V_68 [ V_4 ] . V_19 = V_10 ;
return F_20 ( V_68 ,
V_69 ,
V_66 -> V_80 , V_66 ) ;
}
static int F_21 ( int V_81 )
{
switch ( V_81 ) {
case V_82 :
return V_83 ;
case V_84 :
return V_85 ;
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
}
return - 1 ;
}
static int F_22 ( int V_6 )
{
switch ( V_6 ) {
case V_98 :
case V_87 :
case V_89 :
return V_99 ;
}
return 0 ;
}
static struct V_100 * F_23 ( struct V_9 * V_10 )
{
int V_101 ;
unsigned int V_4 ;
V_101 = F_14 ( V_10 -> V_28 + V_41 ) ;
if ( ! V_101 )
goto V_102;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ )
if ( ( V_101 != V_10 -> V_13 [ V_4 ] . V_16 ) &&
( V_101 != V_10 -> V_13 [ V_4 ] . V_14 ) )
return & V_10 -> V_13 [ V_4 ] ;
F_24 ( L_29 ,
F_12 ( & V_10 -> V_25 ) , V_101 ) ;
V_102:
return & V_10 -> V_13 [ 0 ] ;
}
static
struct V_100 * F_25 ( struct V_9 * V_10 )
{
int V_101 ;
unsigned int V_4 ;
V_101 = F_14 ( V_10 -> V_28 + V_41 ) ;
if ( ! V_101 )
goto V_102;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ )
if ( ( V_101 == V_10 -> V_13 [ V_4 ] . V_16 ) ||
( V_101 == V_10 -> V_13 [ V_4 ] . V_14 ) )
return & V_10 -> V_13 [ V_4 ] ;
V_102:
F_26 ( L_30 ,
V_101 , F_12 ( & V_10 -> V_25 ) ) ;
return NULL ;
}
static void F_27 ( struct V_9 * V_10 )
{
unsigned int V_4 ;
F_26 ( L_31 , F_12 ( & V_10 -> V_25 ) ) ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
V_10 -> V_13 [ V_4 ] . V_15 -> V_61 |= V_18 ;
V_10 -> V_13 [ V_4 ] . V_17 -> V_61 |= V_18 ;
}
if ( F_28 ( V_10 -> V_103 , & V_10 -> V_104 ) )
F_26 ( L_32 ) ;
if ( V_10 -> V_105 )
F_29 ( V_10 -> V_105 ) ;
V_10 -> V_25 . V_106 = V_107 ;
V_10 -> V_103 = NULL ;
}
static int F_30 ( struct V_108 * V_109 ,
unsigned long V_110 , void * V_19 )
{
struct V_9 * V_10 = F_31 ( V_109 , struct V_9 , V_104 ) ;
if ( V_10 -> V_25 . V_106 == V_111 ) {
F_26 ( L_33 ,
F_12 ( & V_10 -> V_25 ) ) ;
F_27 ( V_10 ) ;
}
switch ( V_110 ) {
case V_112 :
V_10 -> V_113 = true ;
break;
case V_114 :
V_10 -> V_113 = false ;
break;
default:
F_24 ( L_34 , V_110 ) ;
break;
}
return 0 ;
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_115 * V_116 = V_10 -> V_117 -> V_118 ;
T_1 V_119 ;
void * V_11 ;
unsigned int V_4 , V_120 ;
V_120 = sizeof( struct V_50 ) *
V_121 * V_12 ;
V_11 = F_33 ( V_10 -> V_117 , V_120 , & V_119 , V_122 | V_123 ) ;
if ( ! V_11 ) {
F_24 ( L_35 ) ;
return;
}
memset ( V_11 , 0 , V_120 ) ;
for ( V_4 = 0 ; V_4 < V_12 ; V_4 ++ ) {
if ( V_119 & 0xF ) {
F_24 ( L_36 ) ;
return;
}
V_10 -> V_13 [ V_4 ] . V_15 = V_11 ;
V_10 -> V_13 [ V_4 ] . V_14 = V_119 ;
F_26 ( L_37 , V_4 , V_11 ) ;
V_11 += sizeof( struct V_50 ) ;
V_119 += sizeof( struct V_50 ) ;
if ( V_119 & 0xF ) {
F_24 ( L_36 ) ;
return;
}
V_10 -> V_13 [ V_4 ] . V_17 = V_11 ;
V_10 -> V_13 [ V_4 ] . V_16 = V_119 ;
F_26 ( L_38 , V_4 , V_11 ) ;
V_11 += sizeof( struct V_50 ) ;
V_119 += sizeof( struct V_50 ) ;
}
if ( F_34 ( V_116 , L_39 ) ) {
char * V_124 ;
switch ( V_10 -> V_25 . V_70 ) {
case V_71 :
V_124 = L_40 ;
break;
case V_73 :
V_124 = L_41 ;
break;
case V_75 :
V_124 = L_42 ;
break;
case V_77 :
V_124 = L_43 ;
break;
default:
F_24 ( L_44 ) ;
return;
}
V_10 -> V_105 = F_35 ( V_10 -> V_117 , V_124 ) ;
if ( F_36 ( V_10 -> V_105 ) )
F_24 ( L_45 , V_124 ) ;
V_10 -> V_125 = F_35 ( V_10 -> V_117 , L_46 ) ;
if ( F_36 ( V_10 -> V_125 ) )
F_24 ( L_47 ) ;
V_10 -> V_126 = F_35 ( V_10 -> V_117 , L_48 ) ;
if ( F_36 ( V_10 -> V_126 ) )
F_24 ( L_49 ) ;
}
}
static int F_37 ( struct V_127 * V_117 , int V_128 , int V_129 )
{
if ( V_128 == V_129 )
return V_128 ;
if ( V_128 < V_129 ) {
F_38 ( V_117 , L_50 ) ;
return V_128 ;
}
F_38 ( V_117 , L_51 ) ;
return V_129 ;
}
static int F_39 ( struct V_24 * V_24 ,
struct V_130 * V_131 )
{
struct V_132 * V_25 = F_40 ( V_24 ) ;
struct V_9 * V_10 = F_41 ( V_25 ) ;
struct V_26 * V_27 = V_131 -> V_27 ;
struct V_133 * V_134 = V_131 -> V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
int V_141 , V_142 , V_143 , V_144 ;
int V_145 , V_146 , V_147 , V_148 ;
int V_6 ;
if ( ! V_27 || ! V_134 )
return 0 ;
V_138 = F_16 ( V_27 ) ;
V_136 = F_42 ( V_131 -> V_131 , V_27 ) ;
V_140 = & V_136 -> V_140 ;
V_141 = V_131 -> V_149 ;
V_142 = V_131 -> V_150 ;
V_143 = F_43 ( V_131 -> V_151 , 0 , V_140 -> V_152 - V_141 ) ;
V_144 = F_43 ( V_131 -> V_153 , 0 , V_140 -> V_154 - V_142 ) ;
V_145 = V_131 -> V_145 >> 16 ;
V_146 = V_131 -> V_146 >> 16 ;
V_147 = F_43 ( V_131 -> V_147 >> 16 , 0 , V_155 ) ;
V_148 = F_43 ( V_131 -> V_148 >> 16 , 0 , V_156 ) ;
V_6 = F_21 ( V_134 -> V_6 -> V_6 ) ;
if ( V_6 == - 1 ) {
F_24 ( L_52 ,
( char * ) & V_134 -> V_6 -> V_6 ) ;
return - V_79 ;
}
if ( ! F_44 ( V_134 , 0 ) ) {
F_24 ( L_53 ) ;
return - V_79 ;
}
if ( V_140 -> clock && V_10 -> V_105 ) {
struct V_157 * V_158 ;
int V_159 = V_140 -> clock * 1000 ;
int V_160 ;
if ( V_138 -> V_49 == V_161 )
V_158 = V_10 -> V_125 ;
else
V_158 = V_10 -> V_126 ;
if ( V_158 )
F_45 ( V_10 -> V_105 , V_158 ) ;
V_160 = F_46 ( V_10 -> V_105 , V_159 ) ;
if ( V_160 < 0 ) {
F_24 ( L_54 ,
V_159 ) ;
return - V_79 ;
}
}
F_47 ( L_55 ,
V_27 -> V_11 . V_49 , F_15 ( V_138 ) ,
V_24 -> V_11 . V_49 , F_12 ( V_25 ) ) ;
F_47 ( L_56 ,
F_12 ( V_25 ) ,
V_143 , V_144 , V_141 , V_142 ,
V_147 , V_148 , V_145 , V_146 ) ;
return 0 ;
}
static void F_48 ( struct V_24 * V_24 ,
struct V_130 * V_162 )
{
struct V_130 * V_131 = V_24 -> V_131 ;
struct V_132 * V_25 = F_40 ( V_24 ) ;
struct V_9 * V_10 = F_41 ( V_25 ) ;
struct V_26 * V_27 = V_131 -> V_27 ;
struct V_133 * V_134 = V_131 -> V_134 ;
struct V_139 * V_140 ;
int V_141 , V_142 , V_143 , V_144 ;
int V_145 , V_146 , V_147 , V_148 ;
struct V_163 * V_164 ;
struct V_100 * V_165 ;
struct V_100 * V_166 ;
struct V_50 * V_15 , * V_17 ;
T_2 V_167 ;
T_2 V_168 ;
int V_6 ;
unsigned int V_169 ;
T_2 V_170 , V_171 , V_172 , V_173 ;
if ( ! V_27 || ! V_134 )
return;
if ( ( V_162 -> V_134 == V_131 -> V_134 ) &&
( V_162 -> V_149 == V_131 -> V_149 ) &&
( V_162 -> V_150 == V_131 -> V_150 ) &&
( V_162 -> V_151 == V_131 -> V_151 ) &&
( V_162 -> V_153 == V_131 -> V_153 ) &&
( V_162 -> V_145 == V_131 -> V_145 ) &&
( V_162 -> V_146 == V_131 -> V_146 ) &&
( V_162 -> V_147 == V_131 -> V_147 ) &&
( V_162 -> V_148 == V_131 -> V_148 ) ) {
F_26 ( L_57 ) ;
V_25 -> V_106 = V_174 ;
return;
}
if ( ! V_10 -> V_103 ) {
struct V_175 * V_176 = F_49 ( V_10 -> V_117 ) ;
struct V_137 * V_138 = F_16 ( V_27 ) ;
V_10 -> V_103 = V_176 -> V_103 [ V_138 -> V_49 ] ;
F_50 ( V_10 -> V_103 , & V_10 -> V_104 , V_27 ) ;
F_51 ( V_10 -> V_105 ) ;
}
V_140 = & V_27 -> V_140 ;
V_141 = V_131 -> V_149 ;
V_142 = V_131 -> V_150 ;
V_143 = F_43 ( V_131 -> V_151 , 0 , V_140 -> V_152 - V_141 ) ;
V_144 = F_43 ( V_131 -> V_153 , 0 , V_140 -> V_154 - V_142 ) ;
V_145 = V_131 -> V_145 >> 16 ;
V_146 = V_131 -> V_146 >> 16 ;
V_147 = F_43 ( V_131 -> V_147 >> 16 , 0 , V_155 ) ;
V_148 = F_43 ( V_131 -> V_148 >> 16 , 0 , V_156 ) ;
V_165 = F_23 ( V_10 ) ;
V_15 = V_165 -> V_15 ;
V_17 = V_165 -> V_17 ;
F_38 ( V_10 -> V_117 , L_58 , V_177 ,
F_12 ( V_25 ) , V_15 , V_17 ) ;
V_15 -> V_52 = V_178 ;
V_15 -> V_51 = V_8 ;
V_6 = F_21 ( V_134 -> V_6 -> V_6 ) ;
V_15 -> V_51 |= V_6 ;
V_15 -> V_51 |= F_22 ( V_6 ) ;
V_15 -> V_61 &= ~ V_18 ;
V_164 = F_44 ( V_134 , 0 ) ;
F_26 ( L_59 , V_134 -> V_11 . V_49 ,
( char * ) & V_134 -> V_6 -> V_6 ,
( unsigned long ) V_164 -> V_179 ) ;
V_169 = V_134 -> V_6 -> V_180 [ 0 ] ;
V_15 -> V_55 = ( T_2 ) V_164 -> V_179 + V_134 -> V_181 [ 0 ] ;
V_15 -> V_55 += V_145 * V_169 ;
V_15 -> V_55 += V_146 * V_134 -> V_182 [ 0 ] ;
V_143 = F_37 ( V_10 -> V_117 , V_143 , V_147 ) ;
V_144 = F_37 ( V_10 -> V_117 , V_144 , V_148 ) ;
V_170 = F_52 ( * V_140 , V_142 ) ;
V_172 = F_52 ( * V_140 , V_142 + V_144 - 1 ) ;
V_171 = F_53 ( * V_140 , V_141 ) ;
V_173 = F_53 ( * V_140 , V_141 + V_143 - 1 ) ;
V_15 -> V_53 = ( V_170 << 16 ) | V_171 ;
V_15 -> V_54 = ( V_172 << 16 ) | V_173 ;
V_147 = V_143 ;
V_15 -> V_56 = V_134 -> V_182 [ 0 ] ;
V_15 -> V_57 = V_148 << 16 | V_147 ;
memcpy ( V_17 , V_15 , sizeof( * V_17 ) ) ;
V_15 -> V_58 = V_165 -> V_16 ;
V_17 -> V_58 = V_165 -> V_14 ;
if ( V_140 -> V_183 & V_184 )
V_17 -> V_55 = V_15 -> V_55 +
V_134 -> V_182 [ 0 ] ;
V_166 = F_25 ( V_10 ) ;
V_167 = V_165 -> V_14 ;
V_168 = V_165 -> V_16 ;
F_38 ( V_10 -> V_117 , L_60 ,
F_14 ( V_10 -> V_28 + V_41 ) ) ;
F_38 ( V_10 -> V_117 , L_61 ,
( unsigned long ) V_164 -> V_179 ,
F_14 ( V_10 -> V_28 + V_185 ) ) ;
if ( ! V_166 ) {
F_26 ( L_62 ,
F_12 ( V_25 ) ) ;
F_54 ( V_10 -> V_113 ?
V_168 : V_167 ,
V_10 -> V_28 + V_41 ) ;
goto V_102;
}
if ( V_140 -> V_183 & V_184 ) {
if ( V_10 -> V_113 ) {
V_166 -> V_17 -> V_58 = V_167 ;
} else {
F_54 ( V_167 ,
V_10 -> V_28 + V_41 ) ;
}
} else {
F_54 ( V_167 , V_10 -> V_28 + V_41 ) ;
}
V_102:
F_55 ( V_25 , true , false ) ;
V_25 -> V_106 = V_174 ;
}
static void F_56 ( struct V_24 * V_24 ,
struct V_130 * V_162 )
{
struct V_132 * V_25 = F_40 ( V_24 ) ;
if ( ! V_162 -> V_27 ) {
F_26 ( L_63 ,
V_24 -> V_11 . V_49 ) ;
return;
}
F_26 ( L_55 ,
V_162 -> V_27 -> V_11 . V_49 ,
F_15 ( F_16 ( V_162 -> V_27 ) ) ,
V_24 -> V_11 . V_49 , F_12 ( V_25 ) ) ;
V_25 -> V_106 = V_186 ;
}
static void F_57 ( struct V_24 * V_24 )
{
F_26 ( L_64 ) ;
F_58 ( V_24 ) ;
F_59 ( V_24 ) ;
}
static int F_60 ( struct V_24 * V_24 )
{
struct V_132 * V_25 = F_40 ( V_24 ) ;
struct V_9 * V_10 = F_41 ( V_25 ) ;
return F_19 ( V_10 , V_24 -> V_117 -> V_187 ) ;
}
struct V_24 * F_61 ( struct V_188 * V_189 ,
struct V_127 * V_117 , int V_70 ,
void T_3 * V_190 ,
unsigned int V_191 ,
enum V_192 type )
{
struct V_9 * V_10 ;
int V_160 ;
V_10 = F_62 ( V_117 , sizeof( * V_10 ) , V_122 ) ;
if ( ! V_10 ) {
F_24 ( L_65 ) ;
return NULL ;
}
V_10 -> V_117 = V_117 ;
V_10 -> V_28 = V_190 ;
V_10 -> V_25 . V_70 = V_70 ;
V_10 -> V_25 . V_106 = V_107 ;
V_10 -> V_104 . V_193 = F_30 ;
F_32 ( V_10 ) ;
V_160 = F_63 ( V_189 , & V_10 -> V_25 . V_24 ,
V_191 ,
& V_194 ,
V_195 ,
F_3 ( V_195 ) ,
NULL , type , NULL ) ;
if ( V_160 ) {
F_24 ( L_66 ) ;
goto V_196;
}
F_64 ( & V_10 -> V_25 . V_24 , & V_197 ) ;
F_65 ( & V_10 -> V_25 , type ) ;
return & V_10 -> V_25 . V_24 ;
V_196:
F_66 ( V_117 , V_10 ) ;
return NULL ;
}
