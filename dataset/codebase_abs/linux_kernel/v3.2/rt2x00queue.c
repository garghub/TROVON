struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_5 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
unsigned int V_10 ;
unsigned int V_11 = 0 ;
unsigned int V_12 = 0 ;
V_10 = V_3 -> V_6 -> V_13 + V_3 -> V_6 -> V_14 ;
V_11 = 4 ;
if ( F_2 ( V_15 , & V_5 -> V_16 ) ) {
V_11 += 8 ;
V_12 += 8 ;
}
V_7 = F_3 ( V_10 + V_11 + V_12 ) ;
if ( ! V_7 )
return NULL ;
F_4 ( V_7 , V_11 ) ;
F_5 ( V_7 , V_10 ) ;
V_9 = F_6 ( V_7 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_3 = V_3 ;
if ( F_2 ( V_17 , & V_5 -> V_16 ) ) {
V_9 -> V_18 = F_7 ( V_5 -> V_19 ,
V_7 -> V_20 ,
V_7 -> V_21 ,
V_22 ) ;
V_9 -> V_23 |= V_24 ;
}
return V_7 ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_25 * V_19 = V_3 -> V_6 -> V_5 -> V_19 ;
struct V_8 * V_9 = F_6 ( V_3 -> V_7 ) ;
V_9 -> V_18 =
F_7 ( V_19 , V_3 -> V_7 -> V_20 , V_3 -> V_7 -> V_21 , V_26 ) ;
V_9 -> V_23 |= V_27 ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_25 * V_19 = V_3 -> V_6 -> V_5 -> V_19 ;
struct V_8 * V_9 = F_6 ( V_3 -> V_7 ) ;
if ( V_9 -> V_23 & V_24 ) {
F_10 ( V_19 , V_9 -> V_18 , V_3 -> V_7 -> V_21 ,
V_22 ) ;
V_9 -> V_23 &= ~ V_24 ;
} else if ( V_9 -> V_23 & V_27 ) {
F_10 ( V_19 , V_9 -> V_18 , V_3 -> V_7 -> V_21 ,
V_26 ) ;
V_9 -> V_23 &= ~ V_27 ;
}
}
void F_11 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_7 )
return;
F_9 ( V_3 ) ;
F_12 ( V_3 -> V_7 ) ;
V_3 -> V_7 = NULL ;
}
void F_13 ( struct V_1 * V_7 )
{
unsigned int V_28 = V_7 -> V_21 ;
unsigned int V_29 = F_14 ( V_7 , 0 ) ;
if ( ! V_29 )
return;
F_15 ( V_7 , V_29 ) ;
memmove ( V_7 -> V_20 , V_7 -> V_20 + V_29 , V_28 ) ;
F_16 ( V_7 , V_28 ) ;
}
void F_17 ( struct V_1 * V_7 , unsigned int V_30 )
{
unsigned int V_31 = V_7 -> V_21 - V_30 ;
unsigned int V_32 = F_14 ( V_7 , 0 ) ;
unsigned int V_33 = F_14 ( V_7 , V_30 ) ;
unsigned int V_34 = V_31 ? F_18 ( V_30 ) : 0 ;
if ( V_33 > V_32 )
V_32 += 4 ;
if ( ! V_32 )
return;
F_15 ( V_7 , V_32 ) ;
memmove ( V_7 -> V_20 , V_7 -> V_20 + V_32 , V_30 ) ;
if ( V_31 && V_33 )
memmove ( V_7 -> V_20 + V_30 + V_34 ,
V_7 -> V_20 + V_30 + V_34 + V_33 ,
V_31 ) ;
F_16 ( V_7 , V_30 + V_34 + V_31 ) ;
}
void F_19 ( struct V_1 * V_7 , unsigned int V_30 )
{
unsigned int V_34 = ( V_7 -> V_21 > V_30 ) ?
F_18 ( V_30 ) : 0 ;
if ( ! V_34 )
return;
memmove ( V_7 -> V_20 + V_34 , V_7 -> V_20 , V_30 ) ;
F_20 ( V_7 , V_34 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
struct V_1 * V_7 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_22 ( V_7 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_7 -> V_20 ;
struct V_41 * V_42 = F_23 ( V_38 -> V_43 . V_44 ) ;
if ( ! ( V_38 -> V_23 & V_45 ) )
return;
F_24 ( V_46 , & V_36 -> V_23 ) ;
if ( ! F_2 ( V_47 , & V_5 -> V_16 ) )
return;
F_25 ( & V_42 -> V_48 ) ;
if ( F_2 ( V_49 , & V_36 -> V_23 ) )
V_42 -> V_50 += 0x10 ;
V_40 -> V_51 &= F_26 ( V_52 ) ;
V_40 -> V_51 |= F_26 ( V_42 -> V_50 ) ;
F_27 ( & V_42 -> V_48 ) ;
}
static void F_28 ( struct V_4 * V_5 ,
struct V_1 * V_7 ,
struct V_35 * V_36 ,
const struct V_53 * V_54 )
{
struct V_37 * V_38 = F_22 ( V_7 ) ;
struct V_55 * V_56 = & V_38 -> V_43 . V_57 [ 0 ] ;
unsigned int V_58 ;
unsigned int V_59 ;
unsigned int V_60 ;
if ( F_2 ( V_49 , & V_36 -> V_23 ) )
V_36 -> V_61 . V_62 . V_63 = V_64 ;
else
V_36 -> V_61 . V_62 . V_63 = V_65 ;
V_58 = V_7 -> V_21 + 4 ;
V_58 += F_29 ( V_5 , V_7 ) ;
V_36 -> V_61 . V_62 . signal = V_54 -> V_62 ;
V_36 -> V_61 . V_62 . V_66 = 0x04 ;
if ( V_54 -> V_23 & V_67 ) {
V_36 -> V_61 . V_62 . V_68 = ( V_58 >> 6 ) & 0x3f ;
V_36 -> V_61 . V_62 . V_69 = V_58 & 0x3f ;
} else {
V_60 = F_30 ( V_58 , V_54 -> V_70 ) ;
V_59 = F_31 ( V_58 , V_54 -> V_70 ) ;
if ( V_60 != 0 ) {
V_59 ++ ;
if ( V_54 -> V_70 == 110 && V_60 <= 30 )
V_36 -> V_61 . V_62 . V_66 |= 0x80 ;
}
V_36 -> V_61 . V_62 . V_68 = ( V_59 >> 8 ) & 0xff ;
V_36 -> V_61 . V_62 . V_69 = V_59 & 0xff ;
if ( V_56 -> V_23 & V_71 )
V_36 -> V_61 . V_62 . signal |= 0x08 ;
}
}
static void F_32 ( struct V_4 * V_5 ,
struct V_1 * V_7 ,
struct V_35 * V_36 ,
const struct V_53 * V_54 )
{
struct V_37 * V_38 = F_22 ( V_7 ) ;
struct V_55 * V_56 = & V_38 -> V_43 . V_57 [ 0 ] ;
struct V_39 * V_40 = (struct V_39 * ) V_7 -> V_20 ;
struct V_72 * V_73 = NULL ;
if ( V_38 -> V_43 . V_74 ) {
V_36 -> V_61 . V_75 . V_76 =
V_38 -> V_43 . V_74 -> V_77 . V_78 ;
V_73 = F_33 ( V_38 -> V_43 . V_74 ) ;
V_36 -> V_61 . V_75 . V_79 = V_73 -> V_79 ;
}
V_36 -> V_61 . V_75 . V_80 = 7 ;
if ( V_38 -> V_23 & V_81 )
V_36 -> V_61 . V_75 . V_82 = 1 ;
if ( V_56 -> V_23 & V_83 ) {
V_36 -> V_61 . V_75 . V_84 = V_56 -> V_85 ;
if ( V_38 -> V_43 . V_74 && V_36 -> V_61 . V_75 . V_84 > 7 &&
( ( V_38 -> V_43 . V_74 -> V_77 . V_86 &
V_87 ) >>
V_88 ) ==
V_89 )
F_24 ( V_90 , & V_36 -> V_23 ) ;
} else {
V_36 -> V_61 . V_75 . V_84 = F_34 ( V_54 -> V_84 ) ;
if ( V_56 -> V_23 & V_71 )
V_36 -> V_61 . V_75 . V_84 |= 0x08 ;
}
if ( V_38 -> V_23 & V_91 &&
! ( V_38 -> V_23 & V_92 ) )
F_24 ( V_93 , & V_36 -> V_23 ) ;
if ( V_56 -> V_23 & V_94 ||
V_56 -> V_23 & V_95 )
F_24 ( V_96 , & V_36 -> V_23 ) ;
if ( V_56 -> V_23 & V_97 )
F_24 ( V_98 , & V_36 -> V_23 ) ;
if ( F_35 ( V_40 -> V_99 ) &&
! F_36 ( V_40 -> V_99 ) )
V_36 -> V_61 . V_75 . V_100 = V_101 ;
else if ( ! ( V_38 -> V_23 & V_102 ) )
V_36 -> V_61 . V_75 . V_100 = V_103 ;
else
V_36 -> V_61 . V_75 . V_100 = V_104 ;
}
static void F_37 ( struct V_4 * V_5 ,
struct V_1 * V_7 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_22 ( V_7 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_7 -> V_20 ;
struct V_55 * V_56 = & V_38 -> V_43 . V_57 [ 0 ] ;
struct V_105 * V_106 ;
const struct V_53 * V_54 = NULL ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_107 = V_7 -> V_21 ;
V_36 -> V_30 = F_38 ( V_7 ) ;
if ( ! ( V_38 -> V_23 & V_108 ) )
F_24 ( V_109 , & V_36 -> V_23 ) ;
if ( F_39 ( V_40 -> V_99 ) ||
F_40 ( V_40 -> V_99 ) ) {
F_24 ( V_110 , & V_36 -> V_23 ) ;
if ( F_39 ( V_40 -> V_99 ) )
F_24 ( V_111 , & V_36 -> V_23 ) ;
else
F_24 ( V_112 , & V_36 -> V_23 ) ;
if ( V_38 -> V_43 . V_113 >= 0 )
V_106 =
F_41 ( V_5 -> V_114 , V_38 ) ;
}
V_36 -> V_115 = V_38 -> V_43 . V_57 [ 0 ] . V_116 - 1 ;
if ( V_36 -> V_115 >= V_5 -> V_117 )
F_24 ( V_118 , & V_36 -> V_23 ) ;
if ( F_42 ( V_40 -> V_99 ) ) {
F_24 ( V_110 , & V_36 -> V_23 ) ;
F_24 ( V_119 , & V_36 -> V_23 ) ;
}
if ( V_38 -> V_23 & V_120 )
F_24 ( V_110 , & V_36 -> V_23 ) ;
if ( F_36 ( V_40 -> V_99 ) ||
F_43 ( V_40 -> V_99 ) )
F_24 ( V_121 , & V_36 -> V_23 ) ;
if ( ( V_38 -> V_23 & V_102 ) &&
! F_2 ( V_111 , & V_36 -> V_23 ) )
F_24 ( V_49 , & V_36 -> V_23 ) ;
if ( V_56 -> V_23 & V_122 )
V_36 -> V_123 = V_124 ;
else if ( V_56 -> V_23 & V_83 )
V_36 -> V_123 = V_125 ;
else {
V_106 = F_44 ( V_5 -> V_114 , V_38 ) ;
V_54 = F_45 ( V_106 -> V_126 ) ;
if ( V_54 -> V_23 & V_67 )
V_36 -> V_123 = V_127 ;
else
V_36 -> V_123 = V_128 ;
}
F_46 ( V_5 , V_7 , V_36 ) ;
F_21 ( V_5 , V_7 , V_36 ) ;
if ( F_2 ( V_129 , & V_5 -> V_16 ) )
F_32 ( V_5 , V_7 , V_36 ,
V_54 ) ;
else
F_28 ( V_5 , V_7 , V_36 ,
V_54 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_5 ;
if ( F_48 ( V_5 -> V_130 -> V_131 -> V_132 &&
V_5 -> V_130 -> V_131 -> V_132 ( V_3 ) ) ) {
ERROR ( V_5 ,
L_1
L_2 ,
V_3 -> V_6 -> V_133 , V_134 ) ;
return - V_135 ;
}
F_15 ( V_3 -> V_7 , V_5 -> V_130 -> V_136 ) ;
memset ( V_3 -> V_7 -> V_20 , 0 , V_5 -> V_130 -> V_136 ) ;
if ( V_5 -> V_130 -> V_131 -> V_137 )
V_5 -> V_130 -> V_131 -> V_137 ( V_3 , V_36 ) ;
if ( F_2 ( V_17 , & V_5 -> V_16 ) )
F_8 ( V_3 ) ;
return 0 ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_138 * V_6 = V_3 -> V_6 ;
V_6 -> V_5 -> V_130 -> V_131 -> V_139 ( V_3 , V_36 ) ;
F_50 ( V_6 -> V_5 , V_140 , V_3 -> V_7 ) ;
}
static void F_51 ( struct V_138 * V_6 ,
struct V_35 * V_36 )
{
if ( F_52 ( V_6 ) ||
! F_2 ( V_110 , & V_36 -> V_23 ) )
V_6 -> V_5 -> V_130 -> V_131 -> V_141 ( V_6 ) ;
}
int F_53 ( struct V_138 * V_6 , struct V_1 * V_7 ,
bool V_142 )
{
struct V_37 * V_38 ;
struct V_2 * V_3 ;
struct V_35 V_36 ;
struct V_8 * V_9 ;
T_1 V_143 , V_144 ;
int V_145 = 0 ;
F_37 ( V_6 -> V_5 , V_7 , & V_36 ) ;
V_38 = F_22 ( V_7 ) ;
V_143 = V_38 -> V_43 . V_57 [ 0 ] . V_85 ;
V_144 = V_38 -> V_43 . V_57 [ 0 ] . V_23 ;
V_9 = F_6 ( V_7 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_146 = V_143 ;
V_9 -> V_147 = V_144 ;
if ( V_142 )
V_9 -> V_23 |= V_148 ;
if ( F_2 ( V_149 , & V_36 . V_23 ) &&
! F_2 ( V_150 , & V_36 . V_23 ) ) {
if ( F_2 ( V_151 , & V_6 -> V_5 -> V_16 ) )
F_54 ( V_7 , & V_36 ) ;
else
F_55 ( V_7 , & V_36 ) ;
}
if ( F_2 ( V_152 , & V_6 -> V_5 -> V_16 ) )
F_17 ( V_7 , V_36 . V_30 ) ;
else if ( F_2 ( V_17 , & V_6 -> V_5 -> V_16 ) )
F_13 ( V_7 ) ;
F_25 ( & V_6 -> V_153 ) ;
if ( F_48 ( F_56 ( V_6 ) ) ) {
ERROR ( V_6 -> V_5 ,
L_3 , V_6 -> V_133 ) ;
V_145 = - V_154 ;
goto V_155;
}
V_3 = F_57 ( V_6 , V_156 ) ;
if ( F_48 ( F_58 ( V_157 ,
& V_3 -> V_23 ) ) ) {
ERROR ( V_6 -> V_5 ,
L_4
L_2 ,
V_6 -> V_133 , V_134 ) ;
V_145 = - V_135 ;
goto V_155;
}
V_9 -> V_3 = V_3 ;
V_3 -> V_7 = V_7 ;
if ( F_48 ( F_47 ( V_3 , & V_36 ) ) ) {
F_59 ( V_157 , & V_3 -> V_23 ) ;
V_3 -> V_7 = NULL ;
V_145 = - V_158 ;
goto V_155;
}
F_60 ( V_159 , & V_3 -> V_23 ) ;
F_61 ( V_3 , V_156 ) ;
F_49 ( V_3 , & V_36 ) ;
F_51 ( V_6 , & V_36 ) ;
V_155:
F_27 ( & V_6 -> V_153 ) ;
return V_145 ;
}
int F_62 ( struct V_4 * V_5 ,
struct V_160 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
if ( F_48 ( ! V_42 -> V_161 ) )
return - V_154 ;
F_63 ( & V_42 -> V_162 ) ;
F_11 ( V_42 -> V_161 ) ;
if ( V_5 -> V_130 -> V_131 -> V_163 )
V_5 -> V_130 -> V_131 -> V_163 ( V_42 -> V_161 ) ;
F_64 ( & V_42 -> V_162 ) ;
return 0 ;
}
int F_65 ( struct V_4 * V_5 ,
struct V_160 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
struct V_8 * V_9 ;
struct V_35 V_36 ;
if ( F_48 ( ! V_42 -> V_161 ) )
return - V_154 ;
F_11 ( V_42 -> V_161 ) ;
V_42 -> V_161 -> V_7 = F_66 ( V_5 -> V_114 , V_44 ) ;
if ( ! V_42 -> V_161 -> V_7 )
return - V_164 ;
F_37 ( V_5 , V_42 -> V_161 -> V_7 , & V_36 ) ;
V_9 = F_6 ( V_42 -> V_161 -> V_7 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_3 = V_42 -> V_161 ;
V_5 -> V_130 -> V_131 -> V_165 ( V_42 -> V_161 , & V_36 ) ;
return 0 ;
}
int F_67 ( struct V_4 * V_5 ,
struct V_160 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
int V_145 ;
F_63 ( & V_42 -> V_162 ) ;
V_145 = F_65 ( V_5 , V_44 ) ;
F_64 ( & V_42 -> V_162 ) ;
return V_145 ;
}
bool F_68 ( struct V_138 * V_6 ,
enum V_166 V_167 ,
enum V_166 V_168 ,
void * V_20 ,
bool (* F_69)( struct V_2 * V_3 ,
void * V_20 ) )
{
unsigned long V_169 ;
unsigned int V_170 ;
unsigned int V_171 ;
unsigned int V_172 ;
if ( F_48 ( V_167 >= V_173 || V_168 >= V_173 ) ) {
ERROR ( V_6 -> V_5 ,
L_5 ,
V_167 , V_168 ) ;
return true ;
}
F_70 ( & V_6 -> V_174 , V_169 ) ;
V_170 = V_6 -> V_175 [ V_167 ] ;
V_171 = V_6 -> V_175 [ V_168 ] ;
F_71 ( & V_6 -> V_174 , V_169 ) ;
if ( V_170 < V_171 ) {
for ( V_172 = V_170 ; V_172 < V_171 ; V_172 ++ ) {
if ( F_69 ( & V_6 -> V_176 [ V_172 ] , V_20 ) )
return true ;
}
} else {
for ( V_172 = V_170 ; V_172 < V_6 -> V_177 ; V_172 ++ ) {
if ( F_69 ( & V_6 -> V_176 [ V_172 ] , V_20 ) )
return true ;
}
for ( V_172 = 0 ; V_172 < V_171 ; V_172 ++ ) {
if ( F_69 ( & V_6 -> V_176 [ V_172 ] , V_20 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_57 ( struct V_138 * V_6 ,
enum V_166 V_175 )
{
struct V_2 * V_3 ;
unsigned long V_169 ;
if ( F_48 ( V_175 >= V_173 ) ) {
ERROR ( V_6 -> V_5 ,
L_6 , V_175 ) ;
return NULL ;
}
F_70 ( & V_6 -> V_174 , V_169 ) ;
V_3 = & V_6 -> V_176 [ V_6 -> V_175 [ V_175 ] ] ;
F_71 ( & V_6 -> V_174 , V_169 ) ;
return V_3 ;
}
void F_61 ( struct V_2 * V_3 , enum V_166 V_175 )
{
struct V_138 * V_6 = V_3 -> V_6 ;
unsigned long V_169 ;
if ( F_48 ( V_175 >= V_173 ) ) {
ERROR ( V_6 -> V_5 ,
L_7 , V_175 ) ;
return;
}
F_70 ( & V_6 -> V_174 , V_169 ) ;
V_6 -> V_175 [ V_175 ] ++ ;
if ( V_6 -> V_175 [ V_175 ] >= V_6 -> V_177 )
V_6 -> V_175 [ V_175 ] = 0 ;
V_3 -> V_178 = V_179 ;
if ( V_175 == V_156 ) {
V_6 -> V_107 ++ ;
} else if ( V_175 == V_180 ) {
V_6 -> V_107 -- ;
V_6 -> V_116 ++ ;
}
F_71 ( & V_6 -> V_174 , V_169 ) ;
}
void F_72 ( struct V_138 * V_6 )
{
if ( ! F_2 ( V_181 , & V_6 -> V_5 -> V_23 ) ||
! F_2 ( V_182 , & V_6 -> V_23 ) ||
F_58 ( V_183 , & V_6 -> V_23 ) )
return;
switch ( V_6 -> V_133 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
F_73 ( V_6 -> V_5 -> V_114 , V_6 -> V_133 ) ;
break;
default:
break;
}
}
void F_74 ( struct V_138 * V_6 )
{
if ( ! F_2 ( V_181 , & V_6 -> V_5 -> V_23 ) ||
! F_2 ( V_182 , & V_6 -> V_23 ) ||
! F_75 ( V_183 , & V_6 -> V_23 ) )
return;
switch ( V_6 -> V_133 ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
F_76 ( V_6 -> V_5 -> V_114 , V_6 -> V_133 ) ;
break;
case V_188 :
V_6 -> V_5 -> V_130 -> V_131 -> V_141 ( V_6 ) ;
default:
break;
}
}
void F_77 ( struct V_138 * V_6 )
{
F_63 ( & V_6 -> V_189 ) ;
if ( ! F_2 ( V_181 , & V_6 -> V_5 -> V_23 ) ||
F_58 ( V_182 , & V_6 -> V_23 ) ) {
F_64 ( & V_6 -> V_189 ) ;
return;
}
F_60 ( V_183 , & V_6 -> V_23 ) ;
V_6 -> V_5 -> V_130 -> V_131 -> V_190 ( V_6 ) ;
F_74 ( V_6 ) ;
F_64 ( & V_6 -> V_189 ) ;
}
void F_78 ( struct V_138 * V_6 )
{
F_63 ( & V_6 -> V_189 ) ;
if ( ! F_75 ( V_182 , & V_6 -> V_23 ) ) {
F_64 ( & V_6 -> V_189 ) ;
return;
}
F_72 ( V_6 ) ;
V_6 -> V_5 -> V_130 -> V_131 -> V_191 ( V_6 ) ;
F_64 ( & V_6 -> V_189 ) ;
}
void F_79 ( struct V_138 * V_6 , bool V_192 )
{
bool V_193 ;
bool V_194 =
( V_6 -> V_133 == V_184 ) ||
( V_6 -> V_133 == V_185 ) ||
( V_6 -> V_133 == V_186 ) ||
( V_6 -> V_133 == V_187 ) ;
F_63 ( & V_6 -> V_189 ) ;
V_193 = F_2 ( V_182 , & V_6 -> V_23 ) ;
if ( V_193 ) {
F_72 ( V_6 ) ;
if ( ! V_192 && V_194 )
V_6 -> V_5 -> V_130 -> V_131 -> V_141 ( V_6 ) ;
}
if ( F_80 ( V_6 -> V_5 -> V_130 -> V_131 -> V_195 ) )
V_6 -> V_5 -> V_130 -> V_131 -> V_195 ( V_6 , V_192 ) ;
if ( F_48 ( ! F_81 ( V_6 ) ) )
F_82 ( V_6 -> V_5 , L_8 , V_6 -> V_133 ) ;
if ( V_193 )
F_74 ( V_6 ) ;
F_64 ( & V_6 -> V_189 ) ;
}
void F_83 ( struct V_4 * V_5 )
{
struct V_138 * V_6 ;
F_84 (rt2x00dev, queue)
F_77 ( V_6 ) ;
F_77 ( V_5 -> V_196 ) ;
}
void F_85 ( struct V_4 * V_5 )
{
struct V_138 * V_6 ;
F_86 ( V_5 -> V_114 ) ;
F_84 (rt2x00dev, queue)
F_78 ( V_6 ) ;
F_78 ( V_5 -> V_196 ) ;
}
void F_87 ( struct V_4 * V_5 , bool V_192 )
{
struct V_138 * V_6 ;
F_84 (rt2x00dev, queue)
F_79 ( V_6 , V_192 ) ;
F_79 ( V_5 -> V_196 , V_192 ) ;
}
static void F_88 ( struct V_138 * V_6 )
{
unsigned long V_169 ;
unsigned int V_172 ;
F_70 ( & V_6 -> V_174 , V_169 ) ;
V_6 -> V_116 = 0 ;
V_6 -> V_107 = 0 ;
for ( V_172 = 0 ; V_172 < V_173 ; V_172 ++ )
V_6 -> V_175 [ V_172 ] = 0 ;
F_71 ( & V_6 -> V_174 , V_169 ) ;
}
void F_89 ( struct V_4 * V_5 )
{
struct V_138 * V_6 ;
unsigned int V_172 ;
F_90 (rt2x00dev, queue) {
F_88 ( V_6 ) ;
for ( V_172 = 0 ; V_172 < V_6 -> V_177 ; V_172 ++ )
V_5 -> V_130 -> V_131 -> V_197 ( & V_6 -> V_176 [ V_172 ] ) ;
}
}
static int F_91 ( struct V_138 * V_6 ,
const struct V_198 * V_199 )
{
struct V_2 * V_176 ;
unsigned int V_200 ;
unsigned int V_172 ;
F_88 ( V_6 ) ;
V_6 -> V_177 = V_199 -> V_201 ;
V_6 -> V_202 = F_92 ( V_199 -> V_201 , 10 ) ;
V_6 -> V_13 = V_199 -> V_13 ;
V_6 -> V_14 = V_199 -> V_14 ;
V_200 = sizeof( * V_176 ) + V_199 -> V_203 ;
V_176 = F_93 ( V_6 -> V_177 , V_200 , V_204 ) ;
if ( ! V_176 )
return - V_164 ;
#define F_94 ( T_2 , T_3 , T_4 , T_5 , T_6 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_172 = 0 ; V_172 < V_6 -> V_177 ; V_172 ++ ) {
V_176 [ V_172 ] . V_23 = 0 ;
V_176 [ V_172 ] . V_6 = V_6 ;
V_176 [ V_172 ] . V_7 = NULL ;
V_176 [ V_172 ] . V_205 = V_172 ;
V_176 [ V_172 ] . V_206 =
F_94 ( V_176 , V_172 , V_6 -> V_177 ,
sizeof( * V_176 ) , V_199 -> V_203 ) ;
}
#undef F_94
V_6 -> V_176 = V_176 ;
return 0 ;
}
static void F_95 ( struct V_138 * V_6 )
{
unsigned int V_172 ;
if ( ! V_6 -> V_176 )
return;
for ( V_172 = 0 ; V_172 < V_6 -> V_177 ; V_172 ++ ) {
F_11 ( & V_6 -> V_176 [ V_172 ] ) ;
}
}
static int F_96 ( struct V_138 * V_6 )
{
unsigned int V_172 ;
struct V_1 * V_7 ;
for ( V_172 = 0 ; V_172 < V_6 -> V_177 ; V_172 ++ ) {
V_7 = F_1 ( & V_6 -> V_176 [ V_172 ] ) ;
if ( ! V_7 )
return - V_164 ;
V_6 -> V_176 [ V_172 ] . V_7 = V_7 ;
}
return 0 ;
}
int F_97 ( struct V_4 * V_5 )
{
struct V_138 * V_6 ;
int V_207 ;
V_207 = F_91 ( V_5 -> V_196 , V_5 -> V_130 -> V_196 ) ;
if ( V_207 )
goto exit;
F_84 (rt2x00dev, queue) {
V_207 = F_91 ( V_6 , V_5 -> V_130 -> V_208 ) ;
if ( V_207 )
goto exit;
}
V_207 = F_91 ( V_5 -> V_209 , V_5 -> V_130 -> V_209 ) ;
if ( V_207 )
goto exit;
if ( F_2 ( V_210 , & V_5 -> V_16 ) ) {
V_207 = F_91 ( V_5 -> V_211 ,
V_5 -> V_130 -> V_211 ) ;
if ( V_207 )
goto exit;
}
V_207 = F_96 ( V_5 -> V_196 ) ;
if ( V_207 )
goto exit;
return 0 ;
exit:
ERROR ( V_5 , L_9 ) ;
F_98 ( V_5 ) ;
return V_207 ;
}
void F_98 ( struct V_4 * V_5 )
{
struct V_138 * V_6 ;
F_95 ( V_5 -> V_196 ) ;
F_90 (rt2x00dev, queue) {
F_99 ( V_6 -> V_176 ) ;
V_6 -> V_176 = NULL ;
}
}
static void F_100 ( struct V_4 * V_5 ,
struct V_138 * V_6 , enum V_212 V_133 )
{
F_101 ( & V_6 -> V_189 ) ;
F_102 ( & V_6 -> V_153 ) ;
F_102 ( & V_6 -> V_174 ) ;
V_6 -> V_5 = V_5 ;
V_6 -> V_133 = V_133 ;
V_6 -> V_100 = 0 ;
V_6 -> V_213 = 2 ;
V_6 -> V_214 = 5 ;
V_6 -> V_215 = 10 ;
}
int F_103 ( struct V_4 * V_5 )
{
struct V_138 * V_6 ;
enum V_212 V_133 ;
unsigned int V_216 =
! ! F_2 ( V_210 , & V_5 -> V_16 ) ;
V_5 -> V_217 = 2 + V_5 -> V_130 -> V_218 + V_216 ;
V_6 = F_93 ( V_5 -> V_217 , sizeof( * V_6 ) , V_204 ) ;
if ( ! V_6 ) {
ERROR ( V_5 , L_10 ) ;
return - V_164 ;
}
V_5 -> V_196 = V_6 ;
V_5 -> V_208 = & V_6 [ 1 ] ;
V_5 -> V_209 = & V_6 [ 1 + V_5 -> V_130 -> V_218 ] ;
V_5 -> V_211 = V_216 ? & V_6 [ 2 + V_5 -> V_130 -> V_218 ] : NULL ;
F_100 ( V_5 , V_5 -> V_196 , V_188 ) ;
V_133 = V_184 ;
F_84 (rt2x00dev, queue)
F_100 ( V_5 , V_6 , V_133 ++ ) ;
F_100 ( V_5 , V_5 -> V_209 , V_219 ) ;
if ( V_216 )
F_100 ( V_5 , V_5 -> V_211 , V_220 ) ;
return 0 ;
}
void F_104 ( struct V_4 * V_5 )
{
F_99 ( V_5 -> V_196 ) ;
V_5 -> V_196 = NULL ;
V_5 -> V_208 = NULL ;
V_5 -> V_209 = NULL ;
}
