struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_9 ;
struct V_10 * V_11 ;
unsigned int V_12 ;
unsigned int V_13 = 0 ;
unsigned int V_14 = 0 ;
V_12 = V_6 -> V_15 + V_6 -> V_16 + V_6 -> V_17 ;
V_13 = 4 ;
if ( F_2 ( V_8 ) ) {
V_13 += 8 ;
V_14 += 8 ;
}
V_9 = F_3 ( V_12 + V_13 + V_14 , V_4 ) ;
if ( ! V_9 )
return NULL ;
F_4 ( V_9 , V_13 ) ;
F_5 ( V_9 , V_12 ) ;
V_11 = F_6 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_3 = V_3 ;
if ( F_7 ( V_8 , V_18 ) ) {
T_2 V_19 ;
V_19 = F_8 ( V_8 -> V_20 , V_9 -> V_21 , V_9 -> V_22 ,
V_23 ) ;
if ( F_9 ( F_10 ( V_8 -> V_20 , V_19 ) ) ) {
F_11 ( V_9 ) ;
return NULL ;
}
V_11 -> V_19 = V_19 ;
V_11 -> V_24 |= V_25 ;
}
return V_9 ;
}
int F_12 ( struct V_2 * V_3 )
{
struct V_26 * V_20 = V_3 -> V_6 -> V_8 -> V_20 ;
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
V_11 -> V_19 =
F_8 ( V_20 , V_3 -> V_9 -> V_21 , V_3 -> V_9 -> V_22 , V_27 ) ;
if ( F_9 ( F_10 ( V_20 , V_11 -> V_19 ) ) )
return - V_28 ;
V_11 -> V_24 |= V_29 ;
return 0 ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_26 * V_20 = V_3 -> V_6 -> V_8 -> V_20 ;
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
if ( V_11 -> V_24 & V_25 ) {
F_14 ( V_20 , V_11 -> V_19 , V_3 -> V_9 -> V_22 ,
V_23 ) ;
V_11 -> V_24 &= ~ V_25 ;
} else if ( V_11 -> V_24 & V_29 ) {
F_14 ( V_20 , V_11 -> V_19 , V_3 -> V_9 -> V_22 ,
V_27 ) ;
V_11 -> V_24 &= ~ V_29 ;
}
}
void F_15 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_9 )
return;
F_13 ( V_3 ) ;
F_11 ( V_3 -> V_9 ) ;
V_3 -> V_9 = NULL ;
}
void F_16 ( struct V_1 * V_9 )
{
unsigned int V_30 = V_9 -> V_22 ;
unsigned int V_31 = F_17 ( V_9 , 0 ) ;
if ( ! V_31 )
return;
F_18 ( V_9 , V_31 ) ;
memmove ( V_9 -> V_21 , V_9 -> V_21 + V_31 , V_30 ) ;
F_19 ( V_9 , V_30 ) ;
}
void F_20 ( struct V_1 * V_9 , unsigned int V_32 )
{
unsigned int V_33 = ( V_9 -> V_22 > V_32 ) ? F_21 ( V_32 ) : 0 ;
if ( ! V_33 )
return;
F_18 ( V_9 , V_33 ) ;
memmove ( V_9 -> V_21 , V_9 -> V_21 + V_33 , V_32 ) ;
}
void F_22 ( struct V_1 * V_9 , unsigned int V_32 )
{
unsigned int V_33 = ( V_9 -> V_22 > V_32 ) ? F_21 ( V_32 ) : 0 ;
if ( ! V_33 )
return;
memmove ( V_9 -> V_21 + V_33 , V_9 -> V_21 , V_32 ) ;
F_23 ( V_9 , V_33 ) ;
}
static void F_24 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = F_25 ( V_9 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_9 -> V_21 ;
struct V_40 * V_41 = F_26 ( V_37 -> V_42 . V_43 ) ;
T_3 V_44 ;
if ( ! ( V_37 -> V_24 & V_45 ) )
return;
F_27 ( V_46 , & V_35 -> V_24 ) ;
if ( ! F_7 ( V_8 , V_47 ) ) {
if ( F_28 ( V_48 , & V_8 -> V_24 ) )
F_29 ( V_46 , & V_35 -> V_24 ) ;
else
return;
}
if ( F_28 ( V_49 , & V_35 -> V_24 ) )
V_44 = F_30 ( 0x10 , & V_41 -> V_44 ) ;
else
V_44 = F_31 ( & V_41 -> V_44 ) ;
V_39 -> V_50 &= F_32 ( V_51 ) ;
V_39 -> V_50 |= F_32 ( V_44 ) ;
}
static void F_33 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_34 * V_35 ,
const struct V_52 * V_53 )
{
struct V_36 * V_37 = F_25 ( V_9 ) ;
struct V_54 * V_55 = & V_37 -> V_42 . V_56 [ 0 ] ;
unsigned int V_57 ;
unsigned int V_58 ;
unsigned int V_59 ;
if ( F_28 ( V_49 , & V_35 -> V_24 ) )
V_35 -> V_60 . V_61 . V_62 = V_63 ;
else
V_35 -> V_60 . V_61 . V_62 = V_64 ;
V_57 = V_9 -> V_22 + 4 ;
V_57 += F_34 ( V_8 , V_9 ) ;
V_35 -> V_60 . V_61 . signal = V_53 -> V_61 ;
V_35 -> V_60 . V_61 . V_65 = 0x04 ;
if ( V_53 -> V_24 & V_66 ) {
V_35 -> V_60 . V_61 . V_67 = ( V_57 >> 6 ) & 0x3f ;
V_35 -> V_60 . V_61 . V_68 = V_57 & 0x3f ;
} else {
V_59 = F_35 ( V_57 , V_53 -> V_69 ) ;
V_58 = F_36 ( V_57 , V_53 -> V_69 ) ;
if ( V_59 != 0 ) {
V_58 ++ ;
if ( V_53 -> V_69 == 110 && V_59 <= 30 )
V_35 -> V_60 . V_61 . V_65 |= 0x80 ;
}
V_35 -> V_60 . V_61 . V_67 = ( V_58 >> 8 ) & 0xff ;
V_35 -> V_60 . V_61 . V_68 = V_58 & 0xff ;
if ( V_55 -> V_24 & V_70 )
V_35 -> V_60 . V_61 . signal |= 0x08 ;
}
}
static void F_37 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_34 * V_35 ,
struct V_71 * V_72 ,
const struct V_52 * V_53 )
{
struct V_36 * V_37 = F_25 ( V_9 ) ;
struct V_54 * V_55 = & V_37 -> V_42 . V_56 [ 0 ] ;
struct V_38 * V_39 = (struct V_38 * ) V_9 -> V_21 ;
struct V_73 * V_74 = NULL ;
if ( V_72 ) {
V_35 -> V_60 . V_75 . V_76 =
V_72 -> V_77 . V_78 ;
V_74 = F_38 ( V_72 ) ;
V_35 -> V_60 . V_75 . V_79 = V_74 -> V_79 ;
}
if ( V_55 -> V_24 & V_80 ) {
V_35 -> V_60 . V_75 . V_81 = V_55 -> V_82 ;
if ( V_72 && V_35 -> V_60 . V_75 . V_81 > 7 &&
V_72 -> V_83 == V_84 )
F_27 ( V_85 , & V_35 -> V_24 ) ;
} else {
V_35 -> V_60 . V_75 . V_81 = F_39 ( V_53 -> V_81 ) ;
if ( V_55 -> V_24 & V_70 )
V_35 -> V_60 . V_75 . V_81 |= 0x08 ;
}
if ( F_28 ( V_86 , & V_8 -> V_24 ) ) {
if ( ! ( V_37 -> V_24 & V_87 ) )
V_35 -> V_60 . V_75 . V_88 = V_89 ;
else
V_35 -> V_60 . V_75 . V_88 = V_90 ;
return;
}
V_35 -> V_60 . V_75 . V_91 = 7 ;
if ( V_37 -> V_24 & V_92 )
V_35 -> V_60 . V_75 . V_93 = 1 ;
if ( V_37 -> V_24 & V_94 &&
! ( V_37 -> V_24 & V_95 ) )
F_27 ( V_96 , & V_35 -> V_24 ) ;
if ( V_55 -> V_24 & V_97 ||
V_55 -> V_24 & V_98 )
F_27 ( V_99 , & V_35 -> V_24 ) ;
if ( V_55 -> V_24 & V_100 )
F_27 ( V_101 , & V_35 -> V_24 ) ;
if ( F_40 ( V_39 -> V_102 ) &&
! F_41 ( V_39 -> V_102 ) )
V_35 -> V_60 . V_75 . V_88 = V_90 ;
else if ( ! ( V_37 -> V_24 & V_87 ) )
V_35 -> V_60 . V_75 . V_88 = V_89 ;
else
V_35 -> V_60 . V_75 . V_88 = V_103 ;
}
static void F_42 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_34 * V_35 ,
struct V_71 * V_72 )
{
struct V_36 * V_37 = F_25 ( V_9 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_9 -> V_21 ;
struct V_54 * V_55 = & V_37 -> V_42 . V_56 [ 0 ] ;
struct V_104 * V_105 ;
const struct V_52 * V_53 = NULL ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_106 = V_9 -> V_22 ;
V_35 -> V_107 = F_43 ( V_9 ) ;
if ( ! ( V_37 -> V_24 & V_108 ) )
F_27 ( V_109 , & V_35 -> V_24 ) ;
if ( F_44 ( V_39 -> V_102 ) ||
F_45 ( V_39 -> V_102 ) ) {
F_27 ( V_110 , & V_35 -> V_24 ) ;
if ( F_44 ( V_39 -> V_102 ) )
F_27 ( V_111 , & V_35 -> V_24 ) ;
else
F_27 ( V_112 , & V_35 -> V_24 ) ;
if ( V_37 -> V_42 . V_113 >= 0 )
V_105 =
F_46 ( V_8 -> V_114 , V_37 ) ;
}
V_35 -> V_115 = V_37 -> V_42 . V_56 [ 0 ] . V_116 - 1 ;
if ( V_35 -> V_115 >= V_8 -> V_117 )
F_27 ( V_118 , & V_35 -> V_24 ) ;
if ( F_47 ( V_39 -> V_102 ) ) {
F_27 ( V_110 , & V_35 -> V_24 ) ;
F_27 ( V_119 , & V_35 -> V_24 ) ;
}
if ( V_37 -> V_24 & V_120 )
F_27 ( V_110 , & V_35 -> V_24 ) ;
if ( F_41 ( V_39 -> V_102 ) ||
F_48 ( V_39 -> V_102 ) )
F_27 ( V_121 , & V_35 -> V_24 ) ;
if ( ( V_37 -> V_24 & V_87 ) &&
! F_28 ( V_111 , & V_35 -> V_24 ) )
F_27 ( V_49 , & V_35 -> V_24 ) ;
if ( V_55 -> V_24 & V_122 )
V_35 -> V_123 = V_124 ;
else if ( V_55 -> V_24 & V_80 )
V_35 -> V_123 = V_125 ;
else {
V_105 = F_49 ( V_8 -> V_114 , V_37 ) ;
V_53 = F_50 ( V_105 -> V_126 ) ;
if ( V_53 -> V_24 & V_66 )
V_35 -> V_123 = V_127 ;
else
V_35 -> V_123 = V_128 ;
}
F_51 ( V_8 , V_9 , V_35 ) ;
F_24 ( V_8 , V_9 , V_35 ) ;
if ( F_7 ( V_8 , V_129 ) )
F_37 ( V_8 , V_9 , V_35 ,
V_72 , V_53 ) ;
else
F_33 ( V_8 , V_9 , V_35 ,
V_53 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_8 ;
if ( F_9 ( V_8 -> V_130 -> V_131 -> V_132 &&
V_8 -> V_130 -> V_131 -> V_132 ( V_3 ) ) ) {
F_53 ( V_8 ,
L_1
L_2 ,
V_3 -> V_6 -> V_133 , V_134 ) ;
return - V_135 ;
}
F_18 ( V_3 -> V_9 , V_8 -> V_136 ) ;
memset ( V_3 -> V_9 -> V_21 , 0 , V_8 -> V_136 ) ;
if ( V_8 -> V_130 -> V_131 -> V_137 )
V_8 -> V_130 -> V_131 -> V_137 ( V_3 , V_35 ) ;
if ( F_7 ( V_8 , V_18 ) &&
F_12 ( V_3 ) )
return - V_28 ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_8 -> V_130 -> V_131 -> V_138 ( V_3 , V_35 ) ;
F_55 ( V_6 -> V_8 , V_139 , V_3 -> V_9 ) ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_34 * V_35 )
{
if ( F_57 ( V_6 ) ||
! F_28 ( V_110 , & V_35 -> V_24 ) )
V_6 -> V_8 -> V_130 -> V_131 -> V_140 ( V_6 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_8 ;
struct V_141 * V_142 = ( void * ) ( V_3 -> V_9 -> V_21 +
V_8 -> V_136 ) ;
struct V_143 * V_144 ;
if ( F_59 ( ! F_60 ( V_142 -> V_102 ) ) )
return;
V_144 = F_61 ( sizeof( * V_144 ) , V_145 ) ;
if ( ! V_144 )
return;
V_144 -> V_3 = V_3 ;
V_144 -> V_146 = 0 ;
memcpy ( V_144 -> V_147 , V_142 -> V_147 , sizeof( V_142 -> V_147 ) ) ;
memcpy ( V_144 -> V_148 , V_142 -> V_148 , sizeof( V_142 -> V_148 ) ) ;
V_144 -> V_42 = V_142 -> V_42 ;
V_144 -> V_149 = V_142 -> V_149 ;
F_62 ( & V_8 -> V_150 ) ;
F_63 ( & V_144 -> V_151 , & V_8 -> V_152 ) ;
F_64 ( & V_8 -> V_150 ) ;
}
int F_65 ( struct V_5 * V_6 , struct V_1 * V_9 ,
struct V_71 * V_72 , bool V_153 )
{
struct V_36 * V_37 ;
struct V_2 * V_3 ;
struct V_34 V_35 ;
struct V_10 * V_11 ;
T_4 V_154 , V_155 ;
int V_156 = 0 ;
F_42 ( V_6 -> V_8 , V_9 , & V_35 , V_72 ) ;
V_37 = F_25 ( V_9 ) ;
V_154 = V_37 -> V_42 . V_56 [ 0 ] . V_82 ;
V_155 = V_37 -> V_42 . V_56 [ 0 ] . V_24 ;
V_11 = F_6 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_157 = V_154 ;
V_11 -> V_158 = V_155 ;
if ( V_153 )
V_11 -> V_24 |= V_159 ;
if ( F_28 ( V_160 , & V_35 . V_24 ) &&
! F_28 ( V_161 , & V_35 . V_24 ) ) {
if ( F_7 ( V_6 -> V_8 , V_162 ) )
F_66 ( V_9 , & V_35 ) ;
else
F_67 ( V_9 , & V_35 ) ;
}
if ( F_7 ( V_6 -> V_8 , V_163 ) )
F_20 ( V_9 , V_35 . V_107 ) ;
else if ( F_7 ( V_6 -> V_8 , V_18 ) )
F_16 ( V_9 ) ;
F_68 ( & V_6 -> V_164 ) ;
if ( F_9 ( F_69 ( V_6 ) ) ) {
F_53 ( V_6 -> V_8 , L_3 ,
V_6 -> V_133 ) ;
V_156 = - V_165 ;
goto V_166;
}
V_3 = F_70 ( V_6 , V_167 ) ;
if ( F_9 ( F_71 ( V_168 ,
& V_3 -> V_24 ) ) ) {
F_53 ( V_6 -> V_8 ,
L_4
L_2 ,
V_6 -> V_133 , V_134 ) ;
V_156 = - V_135 ;
goto V_166;
}
V_11 -> V_3 = V_3 ;
V_3 -> V_9 = V_9 ;
if ( F_9 ( F_52 ( V_3 , & V_35 ) ) ) {
F_72 ( V_168 , & V_3 -> V_24 ) ;
V_3 -> V_9 = NULL ;
V_156 = - V_169 ;
goto V_166;
}
F_58 ( V_3 ) ;
F_73 ( V_170 , & V_3 -> V_24 ) ;
F_74 ( V_3 , V_167 ) ;
F_54 ( V_3 , & V_35 ) ;
F_56 ( V_6 , & V_35 ) ;
V_166:
F_75 ( & V_6 -> V_164 ) ;
return V_156 ;
}
int F_76 ( struct V_7 * V_8 ,
struct V_171 * V_43 )
{
struct V_40 * V_41 = F_26 ( V_43 ) ;
if ( F_9 ( ! V_41 -> V_172 ) )
return - V_165 ;
F_15 ( V_41 -> V_172 ) ;
if ( V_8 -> V_130 -> V_131 -> V_173 )
V_8 -> V_130 -> V_131 -> V_173 ( V_41 -> V_172 ) ;
return 0 ;
}
int F_77 ( struct V_7 * V_8 ,
struct V_171 * V_43 )
{
struct V_40 * V_41 = F_26 ( V_43 ) ;
struct V_10 * V_11 ;
struct V_34 V_35 ;
if ( F_9 ( ! V_41 -> V_172 ) )
return - V_165 ;
F_15 ( V_41 -> V_172 ) ;
V_41 -> V_172 -> V_9 = F_78 ( V_8 -> V_114 , V_43 ) ;
if ( ! V_41 -> V_172 -> V_9 )
return - V_28 ;
F_42 ( V_8 , V_41 -> V_172 -> V_9 , & V_35 , NULL ) ;
V_11 = F_6 ( V_41 -> V_172 -> V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_3 = V_41 -> V_172 ;
V_8 -> V_130 -> V_131 -> V_174 ( V_41 -> V_172 , & V_35 ) ;
return 0 ;
}
bool F_79 ( struct V_5 * V_6 ,
enum V_175 V_176 ,
enum V_175 V_177 ,
void * V_21 ,
bool (* F_80)( struct V_2 * V_3 ,
void * V_21 ) )
{
unsigned long V_178 ;
unsigned int V_179 ;
unsigned int V_180 ;
unsigned int V_181 ;
if ( F_9 ( V_176 >= V_182 || V_177 >= V_182 ) ) {
F_53 ( V_6 -> V_8 ,
L_5 ,
V_176 , V_177 ) ;
return true ;
}
F_81 ( & V_6 -> V_183 , V_178 ) ;
V_179 = V_6 -> V_184 [ V_176 ] ;
V_180 = V_6 -> V_184 [ V_177 ] ;
F_82 ( & V_6 -> V_183 , V_178 ) ;
if ( V_179 < V_180 ) {
for ( V_181 = V_179 ; V_181 < V_180 ; V_181 ++ ) {
if ( F_80 ( & V_6 -> V_185 [ V_181 ] , V_21 ) )
return true ;
}
} else {
for ( V_181 = V_179 ; V_181 < V_6 -> V_186 ; V_181 ++ ) {
if ( F_80 ( & V_6 -> V_185 [ V_181 ] , V_21 ) )
return true ;
}
for ( V_181 = 0 ; V_181 < V_180 ; V_181 ++ ) {
if ( F_80 ( & V_6 -> V_185 [ V_181 ] , V_21 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_70 ( struct V_5 * V_6 ,
enum V_175 V_184 )
{
struct V_2 * V_3 ;
unsigned long V_178 ;
if ( F_9 ( V_184 >= V_182 ) ) {
F_53 ( V_6 -> V_8 , L_6 ,
V_184 ) ;
return NULL ;
}
F_81 ( & V_6 -> V_183 , V_178 ) ;
V_3 = & V_6 -> V_185 [ V_6 -> V_184 [ V_184 ] ] ;
F_82 ( & V_6 -> V_183 , V_178 ) ;
return V_3 ;
}
void F_74 ( struct V_2 * V_3 , enum V_175 V_184 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_178 ;
if ( F_9 ( V_184 >= V_182 ) ) {
F_53 ( V_6 -> V_8 ,
L_7 , V_184 ) ;
return;
}
F_81 ( & V_6 -> V_183 , V_178 ) ;
V_6 -> V_184 [ V_184 ] ++ ;
if ( V_6 -> V_184 [ V_184 ] >= V_6 -> V_186 )
V_6 -> V_184 [ V_184 ] = 0 ;
V_3 -> V_187 = V_188 ;
if ( V_184 == V_167 ) {
V_6 -> V_106 ++ ;
} else if ( V_184 == V_189 ) {
V_6 -> V_106 -- ;
V_6 -> V_116 ++ ;
}
F_82 ( & V_6 -> V_183 , V_178 ) ;
}
static void F_83 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_133 ) {
case V_190 :
case V_191 :
case V_192 :
case V_193 :
F_84 ( V_6 -> V_8 -> V_114 , V_6 -> V_133 ) ;
break;
default:
break;
}
}
void F_85 ( struct V_5 * V_6 )
{
if ( ! F_28 ( V_194 , & V_6 -> V_8 -> V_24 ) ||
! F_28 ( V_195 , & V_6 -> V_24 ) ||
F_71 ( V_196 , & V_6 -> V_24 ) )
return;
F_83 ( V_6 ) ;
}
void F_86 ( struct V_5 * V_6 )
{
if ( ! F_28 ( V_194 , & V_6 -> V_8 -> V_24 ) ||
! F_28 ( V_195 , & V_6 -> V_24 ) ||
! F_87 ( V_196 , & V_6 -> V_24 ) )
return;
switch ( V_6 -> V_133 ) {
case V_190 :
case V_191 :
case V_192 :
case V_193 :
F_88 ( V_6 -> V_8 -> V_114 , V_6 -> V_133 ) ;
break;
case V_197 :
V_6 -> V_8 -> V_130 -> V_131 -> V_140 ( V_6 ) ;
default:
break;
}
}
void F_89 ( struct V_5 * V_6 )
{
F_90 ( & V_6 -> V_198 ) ;
if ( ! F_28 ( V_194 , & V_6 -> V_8 -> V_24 ) ||
F_71 ( V_195 , & V_6 -> V_24 ) ) {
F_91 ( & V_6 -> V_198 ) ;
return;
}
F_73 ( V_196 , & V_6 -> V_24 ) ;
V_6 -> V_8 -> V_130 -> V_131 -> V_199 ( V_6 ) ;
F_86 ( V_6 ) ;
F_91 ( & V_6 -> V_198 ) ;
}
void F_92 ( struct V_5 * V_6 )
{
F_90 ( & V_6 -> V_198 ) ;
if ( ! F_87 ( V_195 , & V_6 -> V_24 ) ) {
F_91 ( & V_6 -> V_198 ) ;
return;
}
F_83 ( V_6 ) ;
V_6 -> V_8 -> V_130 -> V_131 -> V_200 ( V_6 ) ;
F_91 ( & V_6 -> V_198 ) ;
}
void F_93 ( struct V_5 * V_6 , bool V_201 )
{
bool V_202 =
( V_6 -> V_133 == V_190 ) ||
( V_6 -> V_133 == V_191 ) ||
( V_6 -> V_133 == V_192 ) ||
( V_6 -> V_133 == V_193 ) ;
if ( ! V_201 && V_202 )
V_6 -> V_8 -> V_130 -> V_131 -> V_140 ( V_6 ) ;
if ( F_59 ( V_6 -> V_8 -> V_130 -> V_131 -> V_203 ) )
V_6 -> V_8 -> V_130 -> V_131 -> V_203 ( V_6 , V_201 ) ;
if ( F_9 ( ! F_94 ( V_6 ) ) )
F_95 ( V_6 -> V_8 , L_8 ,
V_6 -> V_133 ) ;
}
void F_96 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_97 (rt2x00dev, queue)
F_89 ( V_6 ) ;
F_89 ( V_8 -> V_204 ) ;
}
void F_98 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_99 ( V_8 -> V_114 ) ;
F_97 (rt2x00dev, queue)
F_92 ( V_6 ) ;
F_92 ( V_8 -> V_204 ) ;
}
void F_100 ( struct V_7 * V_8 , bool V_201 )
{
struct V_5 * V_6 ;
F_97 (rt2x00dev, queue)
F_93 ( V_6 , V_201 ) ;
F_93 ( V_8 -> V_204 , V_201 ) ;
}
static void F_101 ( struct V_5 * V_6 )
{
unsigned long V_178 ;
unsigned int V_181 ;
F_81 ( & V_6 -> V_183 , V_178 ) ;
V_6 -> V_116 = 0 ;
V_6 -> V_106 = 0 ;
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ )
V_6 -> V_184 [ V_181 ] = 0 ;
F_82 ( & V_6 -> V_183 , V_178 ) ;
}
void F_102 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
unsigned int V_181 ;
F_103 (rt2x00dev, queue) {
F_101 ( V_6 ) ;
for ( V_181 = 0 ; V_181 < V_6 -> V_186 ; V_181 ++ )
V_8 -> V_130 -> V_131 -> V_205 ( & V_6 -> V_185 [ V_181 ] ) ;
}
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_2 * V_185 ;
unsigned int V_206 ;
unsigned int V_181 ;
F_101 ( V_6 ) ;
V_206 = sizeof( * V_185 ) + V_6 -> V_207 ;
V_185 = F_105 ( V_6 -> V_186 , V_206 , V_208 ) ;
if ( ! V_185 )
return - V_28 ;
#define F_106 ( T_5 , T_6 , T_7 , T_8 , T_9 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_181 = 0 ; V_181 < V_6 -> V_186 ; V_181 ++ ) {
V_185 [ V_181 ] . V_24 = 0 ;
V_185 [ V_181 ] . V_6 = V_6 ;
V_185 [ V_181 ] . V_9 = NULL ;
V_185 [ V_181 ] . V_209 = V_181 ;
V_185 [ V_181 ] . V_210 =
F_106 ( V_185 , V_181 , V_6 -> V_186 ,
sizeof( * V_185 ) , V_6 -> V_207 ) ;
}
#undef F_106
V_6 -> V_185 = V_185 ;
return 0 ;
}
static void F_107 ( struct V_5 * V_6 )
{
unsigned int V_181 ;
if ( ! V_6 -> V_185 )
return;
for ( V_181 = 0 ; V_181 < V_6 -> V_186 ; V_181 ++ ) {
F_15 ( & V_6 -> V_185 [ V_181 ] ) ;
}
}
static int F_108 ( struct V_5 * V_6 )
{
unsigned int V_181 ;
struct V_1 * V_9 ;
for ( V_181 = 0 ; V_181 < V_6 -> V_186 ; V_181 ++ ) {
V_9 = F_1 ( & V_6 -> V_185 [ V_181 ] , V_208 ) ;
if ( ! V_9 )
return - V_28 ;
V_6 -> V_185 [ V_181 ] . V_9 = V_9 ;
}
return 0 ;
}
int F_109 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
int V_211 ;
V_211 = F_104 ( V_8 -> V_204 ) ;
if ( V_211 )
goto exit;
F_97 (rt2x00dev, queue) {
V_211 = F_104 ( V_6 ) ;
if ( V_211 )
goto exit;
}
V_211 = F_104 ( V_8 -> V_212 ) ;
if ( V_211 )
goto exit;
if ( F_7 ( V_8 , V_213 ) ) {
V_211 = F_104 ( V_8 -> V_214 ) ;
if ( V_211 )
goto exit;
}
V_211 = F_108 ( V_8 -> V_204 ) ;
if ( V_211 )
goto exit;
return 0 ;
exit:
F_53 ( V_8 , L_9 ) ;
F_110 ( V_8 ) ;
return V_211 ;
}
void F_110 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_107 ( V_8 -> V_204 ) ;
F_103 (rt2x00dev, queue) {
F_111 ( V_6 -> V_185 ) ;
V_6 -> V_185 = NULL ;
}
}
static void F_112 ( struct V_7 * V_8 ,
struct V_5 * V_6 , enum V_215 V_133 )
{
F_113 ( & V_6 -> V_198 ) ;
F_114 ( & V_6 -> V_164 ) ;
F_114 ( & V_6 -> V_183 ) ;
V_6 -> V_8 = V_8 ;
V_6 -> V_133 = V_133 ;
V_6 -> V_88 = 0 ;
V_6 -> V_216 = 2 ;
V_6 -> V_217 = 5 ;
V_6 -> V_218 = 10 ;
V_8 -> V_130 -> V_219 ( V_6 ) ;
V_6 -> V_220 = F_115 ( V_6 -> V_186 , 10 ) ;
}
int F_116 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
enum V_215 V_133 ;
unsigned int V_221 =
F_7 ( V_8 , V_213 ) ;
V_8 -> V_222 = 2 + V_8 -> V_130 -> V_223 + V_221 ;
V_6 = F_105 ( V_8 -> V_222 , sizeof( * V_6 ) , V_208 ) ;
if ( ! V_6 ) {
F_53 ( V_8 , L_10 ) ;
return - V_28 ;
}
V_8 -> V_204 = V_6 ;
V_8 -> V_224 = & V_6 [ 1 ] ;
V_8 -> V_212 = & V_6 [ 1 + V_8 -> V_130 -> V_223 ] ;
V_8 -> V_214 = V_221 ? & V_6 [ 2 + V_8 -> V_130 -> V_223 ] : NULL ;
F_112 ( V_8 , V_8 -> V_204 , V_197 ) ;
V_133 = V_190 ;
F_97 (rt2x00dev, queue)
F_112 ( V_8 , V_6 , V_133 ++ ) ;
F_112 ( V_8 , V_8 -> V_212 , V_225 ) ;
if ( V_221 )
F_112 ( V_8 , V_8 -> V_214 , V_226 ) ;
return 0 ;
}
void F_117 ( struct V_7 * V_8 )
{
F_111 ( V_8 -> V_204 ) ;
V_8 -> V_204 = NULL ;
V_8 -> V_224 = NULL ;
V_8 -> V_212 = NULL ;
}
