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
T_4 V_75 = 0 ;
if ( V_72 ) {
V_74 = F_38 ( V_72 ) ;
V_35 -> V_60 . V_76 . V_77 = V_74 -> V_77 ;
V_75 = V_72 -> V_78 . V_79 ;
}
if ( V_55 -> V_24 & V_80 ) {
V_35 -> V_60 . V_76 . V_81 = V_55 -> V_82 ;
if ( V_72 && V_35 -> V_60 . V_76 . V_81 > 7 &&
V_72 -> V_83 == V_84 )
F_27 ( V_85 , & V_35 -> V_24 ) ;
} else {
V_35 -> V_60 . V_76 . V_81 = F_39 ( V_53 -> V_81 ) ;
if ( V_55 -> V_24 & V_70 )
V_35 -> V_60 . V_76 . V_81 |= 0x08 ;
}
if ( F_28 ( V_86 , & V_8 -> V_24 ) ) {
if ( ! ( V_37 -> V_24 & V_87 ) )
V_35 -> V_60 . V_76 . V_88 = V_89 ;
else
V_35 -> V_60 . V_76 . V_88 = V_90 ;
return;
}
if ( V_37 -> V_24 & V_91 )
V_35 -> V_60 . V_76 . V_92 = 1 ;
if ( V_37 -> V_24 & V_93 &&
! ( V_37 -> V_24 & V_94 ) ) {
F_27 ( V_95 , & V_35 -> V_24 ) ;
V_35 -> V_60 . V_76 . V_96 = V_75 ;
V_35 -> V_60 . V_76 . V_97 = 7 ;
}
if ( V_55 -> V_24 & V_98 ||
V_55 -> V_24 & V_99 )
F_27 ( V_100 , & V_35 -> V_24 ) ;
if ( V_55 -> V_24 & V_101 )
F_27 ( V_102 , & V_35 -> V_24 ) ;
if ( F_40 ( V_39 -> V_103 ) &&
! F_41 ( V_39 -> V_103 ) )
V_35 -> V_60 . V_76 . V_88 = V_90 ;
else if ( ! ( V_37 -> V_24 & V_87 ) )
V_35 -> V_60 . V_76 . V_88 = V_89 ;
else
V_35 -> V_60 . V_76 . V_88 = V_104 ;
}
static void F_42 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_34 * V_35 ,
struct V_71 * V_72 )
{
struct V_36 * V_37 = F_25 ( V_9 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_9 -> V_21 ;
struct V_54 * V_55 = & V_37 -> V_42 . V_56 [ 0 ] ;
struct V_105 * V_106 ;
const struct V_52 * V_53 = NULL ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_107 = V_9 -> V_22 ;
V_35 -> V_108 = F_43 ( V_9 ) ;
if ( ! ( V_37 -> V_24 & V_109 ) )
F_27 ( V_110 , & V_35 -> V_24 ) ;
if ( F_44 ( V_39 -> V_103 ) ||
F_45 ( V_39 -> V_103 ) ) {
F_27 ( V_111 , & V_35 -> V_24 ) ;
if ( F_44 ( V_39 -> V_103 ) )
F_27 ( V_112 , & V_35 -> V_24 ) ;
else
F_27 ( V_113 , & V_35 -> V_24 ) ;
if ( V_37 -> V_42 . V_114 >= 0 )
V_106 =
F_46 ( V_8 -> V_115 , V_37 ) ;
}
V_35 -> V_116 = V_37 -> V_42 . V_56 [ 0 ] . V_117 - 1 ;
if ( V_35 -> V_116 >= V_8 -> V_118 )
F_27 ( V_119 , & V_35 -> V_24 ) ;
if ( F_47 ( V_39 -> V_103 ) ) {
F_27 ( V_111 , & V_35 -> V_24 ) ;
F_27 ( V_120 , & V_35 -> V_24 ) ;
}
if ( V_37 -> V_24 & V_121 )
F_27 ( V_111 , & V_35 -> V_24 ) ;
if ( F_41 ( V_39 -> V_103 ) ||
F_48 ( V_39 -> V_103 ) )
F_27 ( V_122 , & V_35 -> V_24 ) ;
if ( ( V_37 -> V_24 & V_87 ) &&
! F_28 ( V_112 , & V_35 -> V_24 ) )
F_27 ( V_49 , & V_35 -> V_24 ) ;
if ( V_55 -> V_24 & V_123 )
V_35 -> V_124 = V_125 ;
else if ( V_55 -> V_24 & V_80 )
V_35 -> V_124 = V_126 ;
else {
V_106 = F_49 ( V_8 -> V_115 , V_37 ) ;
V_53 = F_50 ( V_106 -> V_127 ) ;
if ( V_53 -> V_24 & V_66 )
V_35 -> V_124 = V_128 ;
else
V_35 -> V_124 = V_129 ;
}
F_51 ( V_8 , V_9 , V_35 ) ;
F_24 ( V_8 , V_9 , V_35 ) ;
if ( F_7 ( V_8 , V_130 ) )
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
if ( F_9 ( V_8 -> V_131 -> V_132 -> V_133 &&
V_8 -> V_131 -> V_132 -> V_133 ( V_3 ) ) ) {
F_53 ( V_8 ,
L_1
L_2 ,
V_3 -> V_6 -> V_134 , V_135 ) ;
return - V_136 ;
}
F_18 ( V_3 -> V_9 , V_8 -> V_137 ) ;
memset ( V_3 -> V_9 -> V_21 , 0 , V_8 -> V_137 ) ;
if ( V_8 -> V_131 -> V_132 -> V_138 )
V_8 -> V_131 -> V_132 -> V_138 ( V_3 , V_35 ) ;
if ( F_7 ( V_8 , V_18 ) &&
F_12 ( V_3 ) )
return - V_28 ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_8 -> V_131 -> V_132 -> V_139 ( V_3 , V_35 ) ;
F_55 ( V_6 -> V_8 , V_140 , V_3 ) ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_34 * V_35 )
{
if ( F_57 ( V_6 ) ||
! F_28 ( V_111 , & V_35 -> V_24 ) )
V_6 -> V_8 -> V_131 -> V_132 -> V_141 ( V_6 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_8 ;
struct V_142 * V_143 = ( void * ) ( V_3 -> V_9 -> V_21 +
V_8 -> V_137 ) ;
struct V_144 * V_145 ;
if ( F_59 ( ! F_60 ( V_143 -> V_103 ) ) )
return;
V_145 = F_61 ( sizeof( * V_145 ) , V_146 ) ;
if ( ! V_145 )
return;
V_145 -> V_3 = V_3 ;
V_145 -> V_147 = 0 ;
memcpy ( V_145 -> V_148 , V_143 -> V_148 , sizeof( V_143 -> V_148 ) ) ;
memcpy ( V_145 -> V_149 , V_143 -> V_149 , sizeof( V_143 -> V_149 ) ) ;
V_145 -> V_42 = V_143 -> V_42 ;
V_145 -> V_150 = V_143 -> V_150 ;
F_62 ( & V_8 -> V_151 ) ;
F_63 ( & V_145 -> V_152 , & V_8 -> V_153 ) ;
F_64 ( & V_8 -> V_151 ) ;
}
int F_65 ( struct V_5 * V_6 , struct V_1 * V_9 ,
struct V_71 * V_72 , bool V_154 )
{
struct V_36 * V_37 ;
struct V_2 * V_3 ;
struct V_34 V_35 ;
struct V_10 * V_11 ;
T_4 V_155 , V_156 ;
int V_157 = 0 ;
F_42 ( V_6 -> V_8 , V_9 , & V_35 , V_72 ) ;
V_37 = F_25 ( V_9 ) ;
V_155 = V_37 -> V_42 . V_56 [ 0 ] . V_82 ;
V_156 = V_37 -> V_42 . V_56 [ 0 ] . V_24 ;
V_11 = F_6 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_158 = V_155 ;
V_11 -> V_159 = V_156 ;
if ( V_154 )
V_11 -> V_24 |= V_160 ;
if ( F_28 ( V_161 , & V_35 . V_24 ) &&
! F_28 ( V_162 , & V_35 . V_24 ) ) {
if ( F_7 ( V_6 -> V_8 , V_163 ) )
F_66 ( V_9 , & V_35 ) ;
else
F_67 ( V_9 , & V_35 ) ;
}
if ( F_7 ( V_6 -> V_8 , V_164 ) )
F_20 ( V_9 , V_35 . V_108 ) ;
else if ( F_7 ( V_6 -> V_8 , V_18 ) )
F_16 ( V_9 ) ;
F_68 ( & V_6 -> V_165 ) ;
if ( F_9 ( F_69 ( V_6 ) ) ) {
F_53 ( V_6 -> V_8 , L_3 ,
V_6 -> V_134 ) ;
V_157 = - V_166 ;
goto V_167;
}
V_3 = F_70 ( V_6 , V_168 ) ;
if ( F_9 ( F_71 ( V_169 ,
& V_3 -> V_24 ) ) ) {
F_53 ( V_6 -> V_8 ,
L_4
L_2 ,
V_6 -> V_134 , V_135 ) ;
V_157 = - V_136 ;
goto V_167;
}
V_3 -> V_9 = V_9 ;
if ( F_9 ( F_52 ( V_3 , & V_35 ) ) ) {
F_72 ( V_169 , & V_3 -> V_24 ) ;
V_3 -> V_9 = NULL ;
V_157 = - V_170 ;
goto V_167;
}
F_58 ( V_3 ) ;
F_73 ( V_171 , & V_3 -> V_24 ) ;
F_74 ( V_3 , V_168 ) ;
F_54 ( V_3 , & V_35 ) ;
F_56 ( V_6 , & V_35 ) ;
V_167:
F_75 ( & V_6 -> V_165 ) ;
return V_157 ;
}
int F_76 ( struct V_7 * V_8 ,
struct V_172 * V_43 )
{
struct V_40 * V_41 = F_26 ( V_43 ) ;
if ( F_9 ( ! V_41 -> V_173 ) )
return - V_166 ;
F_15 ( V_41 -> V_173 ) ;
if ( V_8 -> V_131 -> V_132 -> V_174 )
V_8 -> V_131 -> V_132 -> V_174 ( V_41 -> V_173 ) ;
return 0 ;
}
int F_77 ( struct V_7 * V_8 ,
struct V_172 * V_43 )
{
struct V_40 * V_41 = F_26 ( V_43 ) ;
struct V_10 * V_11 ;
struct V_34 V_35 ;
if ( F_9 ( ! V_41 -> V_173 ) )
return - V_166 ;
F_15 ( V_41 -> V_173 ) ;
V_41 -> V_173 -> V_9 = F_78 ( V_8 -> V_115 , V_43 ) ;
if ( ! V_41 -> V_173 -> V_9 )
return - V_28 ;
F_42 ( V_8 , V_41 -> V_173 -> V_9 , & V_35 , NULL ) ;
V_11 = F_6 ( V_41 -> V_173 -> V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_8 -> V_131 -> V_132 -> V_175 ( V_41 -> V_173 , & V_35 ) ;
return 0 ;
}
bool F_79 ( struct V_5 * V_6 ,
enum V_176 V_177 ,
enum V_176 V_178 ,
void * V_21 ,
bool (* F_80)( struct V_2 * V_3 ,
void * V_21 ) )
{
unsigned long V_179 ;
unsigned int V_180 ;
unsigned int V_181 ;
unsigned int V_182 ;
if ( F_9 ( V_177 >= V_183 || V_178 >= V_183 ) ) {
F_53 ( V_6 -> V_8 ,
L_5 ,
V_177 , V_178 ) ;
return true ;
}
F_81 ( & V_6 -> V_184 , V_179 ) ;
V_180 = V_6 -> V_185 [ V_177 ] ;
V_181 = V_6 -> V_185 [ V_178 ] ;
F_82 ( & V_6 -> V_184 , V_179 ) ;
if ( V_180 < V_181 ) {
for ( V_182 = V_180 ; V_182 < V_181 ; V_182 ++ ) {
if ( F_80 ( & V_6 -> V_186 [ V_182 ] , V_21 ) )
return true ;
}
} else {
for ( V_182 = V_180 ; V_182 < V_6 -> V_187 ; V_182 ++ ) {
if ( F_80 ( & V_6 -> V_186 [ V_182 ] , V_21 ) )
return true ;
}
for ( V_182 = 0 ; V_182 < V_181 ; V_182 ++ ) {
if ( F_80 ( & V_6 -> V_186 [ V_182 ] , V_21 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_70 ( struct V_5 * V_6 ,
enum V_176 V_185 )
{
struct V_2 * V_3 ;
unsigned long V_179 ;
if ( F_9 ( V_185 >= V_183 ) ) {
F_53 ( V_6 -> V_8 , L_6 ,
V_185 ) ;
return NULL ;
}
F_81 ( & V_6 -> V_184 , V_179 ) ;
V_3 = & V_6 -> V_186 [ V_6 -> V_185 [ V_185 ] ] ;
F_82 ( & V_6 -> V_184 , V_179 ) ;
return V_3 ;
}
void F_74 ( struct V_2 * V_3 , enum V_176 V_185 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_179 ;
if ( F_9 ( V_185 >= V_183 ) ) {
F_53 ( V_6 -> V_8 ,
L_7 , V_185 ) ;
return;
}
F_81 ( & V_6 -> V_184 , V_179 ) ;
V_6 -> V_185 [ V_185 ] ++ ;
if ( V_6 -> V_185 [ V_185 ] >= V_6 -> V_187 )
V_6 -> V_185 [ V_185 ] = 0 ;
V_3 -> V_188 = V_189 ;
if ( V_185 == V_168 ) {
V_6 -> V_107 ++ ;
} else if ( V_185 == V_190 ) {
V_6 -> V_107 -- ;
V_6 -> V_117 ++ ;
}
F_82 ( & V_6 -> V_184 , V_179 ) ;
}
static void F_83 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_134 ) {
case V_191 :
case V_192 :
case V_193 :
case V_194 :
F_84 ( V_6 -> V_8 -> V_115 , V_6 -> V_134 ) ;
break;
default:
break;
}
}
void F_85 ( struct V_5 * V_6 )
{
if ( ! F_28 ( V_195 , & V_6 -> V_8 -> V_24 ) ||
! F_28 ( V_196 , & V_6 -> V_24 ) ||
F_71 ( V_197 , & V_6 -> V_24 ) )
return;
F_83 ( V_6 ) ;
}
void F_86 ( struct V_5 * V_6 )
{
if ( ! F_28 ( V_195 , & V_6 -> V_8 -> V_24 ) ||
! F_28 ( V_196 , & V_6 -> V_24 ) ||
! F_87 ( V_197 , & V_6 -> V_24 ) )
return;
switch ( V_6 -> V_134 ) {
case V_191 :
case V_192 :
case V_193 :
case V_194 :
F_88 ( V_6 -> V_8 -> V_115 , V_6 -> V_134 ) ;
break;
case V_198 :
V_6 -> V_8 -> V_131 -> V_132 -> V_141 ( V_6 ) ;
default:
break;
}
}
void F_89 ( struct V_5 * V_6 )
{
F_90 ( & V_6 -> V_199 ) ;
if ( ! F_28 ( V_195 , & V_6 -> V_8 -> V_24 ) ||
F_71 ( V_196 , & V_6 -> V_24 ) ) {
F_91 ( & V_6 -> V_199 ) ;
return;
}
F_73 ( V_197 , & V_6 -> V_24 ) ;
V_6 -> V_8 -> V_131 -> V_132 -> V_200 ( V_6 ) ;
F_86 ( V_6 ) ;
F_91 ( & V_6 -> V_199 ) ;
}
void F_92 ( struct V_5 * V_6 )
{
F_90 ( & V_6 -> V_199 ) ;
if ( ! F_87 ( V_196 , & V_6 -> V_24 ) ) {
F_91 ( & V_6 -> V_199 ) ;
return;
}
F_83 ( V_6 ) ;
V_6 -> V_8 -> V_131 -> V_132 -> V_201 ( V_6 ) ;
F_91 ( & V_6 -> V_199 ) ;
}
void F_93 ( struct V_5 * V_6 , bool V_202 )
{
bool V_203 =
( V_6 -> V_134 == V_191 ) ||
( V_6 -> V_134 == V_192 ) ||
( V_6 -> V_134 == V_193 ) ||
( V_6 -> V_134 == V_194 ) ;
if ( ! V_202 && V_203 )
V_6 -> V_8 -> V_131 -> V_132 -> V_141 ( V_6 ) ;
if ( F_59 ( V_6 -> V_8 -> V_131 -> V_132 -> V_204 ) )
V_6 -> V_8 -> V_131 -> V_132 -> V_204 ( V_6 , V_202 ) ;
if ( F_9 ( ! F_94 ( V_6 ) ) )
F_95 ( V_6 -> V_8 , L_8 ,
V_6 -> V_134 ) ;
}
void F_96 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_97 (rt2x00dev, queue)
F_89 ( V_6 ) ;
F_89 ( V_8 -> V_205 ) ;
}
void F_98 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_99 ( V_8 -> V_115 ) ;
F_97 (rt2x00dev, queue)
F_92 ( V_6 ) ;
F_92 ( V_8 -> V_205 ) ;
}
void F_100 ( struct V_7 * V_8 , bool V_202 )
{
struct V_5 * V_6 ;
F_97 (rt2x00dev, queue)
F_93 ( V_6 , V_202 ) ;
F_93 ( V_8 -> V_205 , V_202 ) ;
}
static void F_101 ( struct V_5 * V_6 )
{
unsigned long V_179 ;
unsigned int V_182 ;
F_81 ( & V_6 -> V_184 , V_179 ) ;
V_6 -> V_117 = 0 ;
V_6 -> V_107 = 0 ;
for ( V_182 = 0 ; V_182 < V_183 ; V_182 ++ )
V_6 -> V_185 [ V_182 ] = 0 ;
F_82 ( & V_6 -> V_184 , V_179 ) ;
}
void F_102 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
unsigned int V_182 ;
F_103 (rt2x00dev, queue) {
F_101 ( V_6 ) ;
for ( V_182 = 0 ; V_182 < V_6 -> V_187 ; V_182 ++ )
V_8 -> V_131 -> V_132 -> V_206 ( & V_6 -> V_186 [ V_182 ] ) ;
}
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_2 * V_186 ;
unsigned int V_207 ;
unsigned int V_182 ;
F_101 ( V_6 ) ;
V_207 = sizeof( * V_186 ) + V_6 -> V_208 ;
V_186 = F_105 ( V_6 -> V_187 , V_207 , V_209 ) ;
if ( ! V_186 )
return - V_28 ;
#define F_106 ( T_5 , T_6 , T_7 , T_8 , T_9 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_182 = 0 ; V_182 < V_6 -> V_187 ; V_182 ++ ) {
V_186 [ V_182 ] . V_24 = 0 ;
V_186 [ V_182 ] . V_6 = V_6 ;
V_186 [ V_182 ] . V_9 = NULL ;
V_186 [ V_182 ] . V_210 = V_182 ;
V_186 [ V_182 ] . V_211 =
F_106 ( V_186 , V_182 , V_6 -> V_187 ,
sizeof( * V_186 ) , V_6 -> V_208 ) ;
}
#undef F_106
V_6 -> V_186 = V_186 ;
return 0 ;
}
static void F_107 ( struct V_5 * V_6 )
{
unsigned int V_182 ;
if ( ! V_6 -> V_186 )
return;
for ( V_182 = 0 ; V_182 < V_6 -> V_187 ; V_182 ++ ) {
F_15 ( & V_6 -> V_186 [ V_182 ] ) ;
}
}
static int F_108 ( struct V_5 * V_6 )
{
unsigned int V_182 ;
struct V_1 * V_9 ;
for ( V_182 = 0 ; V_182 < V_6 -> V_187 ; V_182 ++ ) {
V_9 = F_1 ( & V_6 -> V_186 [ V_182 ] , V_209 ) ;
if ( ! V_9 )
return - V_28 ;
V_6 -> V_186 [ V_182 ] . V_9 = V_9 ;
}
return 0 ;
}
int F_109 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
int V_212 ;
V_212 = F_104 ( V_8 -> V_205 ) ;
if ( V_212 )
goto exit;
F_97 (rt2x00dev, queue) {
V_212 = F_104 ( V_6 ) ;
if ( V_212 )
goto exit;
}
V_212 = F_104 ( V_8 -> V_213 ) ;
if ( V_212 )
goto exit;
if ( F_7 ( V_8 , V_214 ) ) {
V_212 = F_104 ( V_8 -> V_215 ) ;
if ( V_212 )
goto exit;
}
V_212 = F_108 ( V_8 -> V_205 ) ;
if ( V_212 )
goto exit;
return 0 ;
exit:
F_53 ( V_8 , L_9 ) ;
F_110 ( V_8 ) ;
return V_212 ;
}
void F_110 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_107 ( V_8 -> V_205 ) ;
F_103 (rt2x00dev, queue) {
F_111 ( V_6 -> V_186 ) ;
V_6 -> V_186 = NULL ;
}
}
static void F_112 ( struct V_7 * V_8 ,
struct V_5 * V_6 , enum V_216 V_134 )
{
F_113 ( & V_6 -> V_199 ) ;
F_114 ( & V_6 -> V_165 ) ;
F_114 ( & V_6 -> V_184 ) ;
V_6 -> V_8 = V_8 ;
V_6 -> V_134 = V_134 ;
V_6 -> V_88 = 0 ;
V_6 -> V_217 = 2 ;
V_6 -> V_218 = 5 ;
V_6 -> V_219 = 10 ;
V_8 -> V_131 -> V_220 ( V_6 ) ;
V_6 -> V_221 = F_115 ( V_6 -> V_187 , 10 ) ;
}
int F_116 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
enum V_216 V_134 ;
unsigned int V_222 =
F_7 ( V_8 , V_214 ) ;
V_8 -> V_223 = 2 + V_8 -> V_131 -> V_224 + V_222 ;
V_6 = F_105 ( V_8 -> V_223 , sizeof( * V_6 ) , V_209 ) ;
if ( ! V_6 ) {
F_53 ( V_8 , L_10 ) ;
return - V_28 ;
}
V_8 -> V_205 = V_6 ;
V_8 -> V_225 = & V_6 [ 1 ] ;
V_8 -> V_213 = & V_6 [ 1 + V_8 -> V_131 -> V_224 ] ;
V_8 -> V_215 = V_222 ? & V_6 [ 2 + V_8 -> V_131 -> V_224 ] : NULL ;
F_112 ( V_8 , V_8 -> V_205 , V_198 ) ;
V_134 = V_191 ;
F_97 (rt2x00dev, queue)
F_112 ( V_8 , V_6 , V_134 ++ ) ;
F_112 ( V_8 , V_8 -> V_213 , V_226 ) ;
if ( V_222 )
F_112 ( V_8 , V_8 -> V_215 , V_227 ) ;
return 0 ;
}
void F_117 ( struct V_7 * V_8 )
{
F_111 ( V_8 -> V_205 ) ;
V_8 -> V_205 = NULL ;
V_8 -> V_225 = NULL ;
V_8 -> V_213 = NULL ;
}
