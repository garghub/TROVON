struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 -> V_6 ;
struct V_1 * V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 ;
unsigned int V_12 = 0 ;
unsigned int V_13 = 0 ;
V_11 = V_3 -> V_7 -> V_14 + V_3 -> V_7 -> V_15 ;
V_12 = 4 ;
if ( F_2 ( V_16 , & V_6 -> V_17 ) ) {
V_12 += 8 ;
V_13 += 8 ;
}
V_8 = F_3 ( V_11 + V_12 + V_13 , V_4 ) ;
if ( ! V_8 )
return NULL ;
F_4 ( V_8 , V_12 ) ;
F_5 ( V_8 , V_11 ) ;
V_10 = F_6 ( V_8 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_3 = V_3 ;
if ( F_2 ( V_18 , & V_6 -> V_17 ) ) {
V_10 -> V_19 = F_7 ( V_6 -> V_20 ,
V_8 -> V_21 ,
V_8 -> V_22 ,
V_23 ) ;
V_10 -> V_24 |= V_25 ;
}
return V_8 ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_26 * V_20 = V_3 -> V_7 -> V_6 -> V_20 ;
struct V_9 * V_10 = F_6 ( V_3 -> V_8 ) ;
V_10 -> V_19 =
F_7 ( V_20 , V_3 -> V_8 -> V_21 , V_3 -> V_8 -> V_22 , V_27 ) ;
V_10 -> V_24 |= V_28 ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_26 * V_20 = V_3 -> V_7 -> V_6 -> V_20 ;
struct V_9 * V_10 = F_6 ( V_3 -> V_8 ) ;
if ( V_10 -> V_24 & V_25 ) {
F_10 ( V_20 , V_10 -> V_19 , V_3 -> V_8 -> V_22 ,
V_23 ) ;
V_10 -> V_24 &= ~ V_25 ;
} else if ( V_10 -> V_24 & V_28 ) {
F_10 ( V_20 , V_10 -> V_19 , V_3 -> V_8 -> V_22 ,
V_27 ) ;
V_10 -> V_24 &= ~ V_28 ;
}
}
void F_11 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 )
return;
F_9 ( V_3 ) ;
F_12 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
}
void F_13 ( struct V_1 * V_8 )
{
unsigned int V_29 = V_8 -> V_22 ;
unsigned int V_30 = F_14 ( V_8 , 0 ) ;
if ( ! V_30 )
return;
F_15 ( V_8 , V_30 ) ;
memmove ( V_8 -> V_21 , V_8 -> V_21 + V_30 , V_29 ) ;
F_16 ( V_8 , V_29 ) ;
}
void F_17 ( struct V_1 * V_8 , unsigned int V_31 )
{
unsigned int V_32 = V_8 -> V_22 - V_31 ;
unsigned int V_33 = F_14 ( V_8 , 0 ) ;
unsigned int V_34 = F_14 ( V_8 , V_31 ) ;
unsigned int V_35 = V_32 ? F_18 ( V_31 ) : 0 ;
if ( V_34 > V_33 )
V_33 += 4 ;
if ( ! V_33 )
return;
F_15 ( V_8 , V_33 ) ;
memmove ( V_8 -> V_21 , V_8 -> V_21 + V_33 , V_31 ) ;
if ( V_32 && V_34 )
memmove ( V_8 -> V_21 + V_31 + V_35 ,
V_8 -> V_21 + V_31 + V_35 + V_34 ,
V_32 ) ;
F_16 ( V_8 , V_31 + V_35 + V_32 ) ;
}
void F_19 ( struct V_1 * V_8 , unsigned int V_31 )
{
unsigned int V_35 = ( V_8 -> V_22 > V_31 ) ?
F_18 ( V_31 ) : 0 ;
if ( ! V_35 )
return;
memmove ( V_8 -> V_21 + V_35 , V_8 -> V_21 , V_31 ) ;
F_20 ( V_8 , V_35 ) ;
}
static void F_21 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_22 ( V_8 ) ;
struct V_40 * V_41 = (struct V_40 * ) V_8 -> V_21 ;
struct V_42 * V_43 = F_23 ( V_39 -> V_44 . V_45 ) ;
T_2 V_46 ;
if ( ! ( V_39 -> V_24 & V_47 ) )
return;
F_24 ( V_48 , & V_37 -> V_24 ) ;
if ( ! F_2 ( V_49 , & V_6 -> V_17 ) ) {
if ( F_2 ( V_50 , & V_6 -> V_24 ) )
F_25 ( V_48 , & V_37 -> V_24 ) ;
else
return;
}
if ( F_2 ( V_51 , & V_37 -> V_24 ) )
V_46 = F_26 ( 0x10 , & V_43 -> V_46 ) ;
else
V_46 = F_27 ( & V_43 -> V_46 ) ;
V_41 -> V_52 &= F_28 ( V_53 ) ;
V_41 -> V_52 |= F_28 ( V_46 ) ;
}
static void F_29 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_36 * V_37 ,
const struct V_54 * V_55 )
{
struct V_38 * V_39 = F_22 ( V_8 ) ;
struct V_56 * V_57 = & V_39 -> V_44 . V_58 [ 0 ] ;
unsigned int V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
if ( F_2 ( V_51 , & V_37 -> V_24 ) )
V_37 -> V_62 . V_63 . V_64 = V_65 ;
else
V_37 -> V_62 . V_63 . V_64 = V_66 ;
V_59 = V_8 -> V_22 + 4 ;
V_59 += F_30 ( V_6 , V_8 ) ;
V_37 -> V_62 . V_63 . signal = V_55 -> V_63 ;
V_37 -> V_62 . V_63 . V_67 = 0x04 ;
if ( V_55 -> V_24 & V_68 ) {
V_37 -> V_62 . V_63 . V_69 = ( V_59 >> 6 ) & 0x3f ;
V_37 -> V_62 . V_63 . V_70 = V_59 & 0x3f ;
} else {
V_61 = F_31 ( V_59 , V_55 -> V_71 ) ;
V_60 = F_32 ( V_59 , V_55 -> V_71 ) ;
if ( V_61 != 0 ) {
V_60 ++ ;
if ( V_55 -> V_71 == 110 && V_61 <= 30 )
V_37 -> V_62 . V_63 . V_67 |= 0x80 ;
}
V_37 -> V_62 . V_63 . V_69 = ( V_60 >> 8 ) & 0xff ;
V_37 -> V_62 . V_63 . V_70 = V_60 & 0xff ;
if ( V_57 -> V_24 & V_72 )
V_37 -> V_62 . V_63 . signal |= 0x08 ;
}
}
static void F_33 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_36 * V_37 ,
struct V_73 * V_74 ,
const struct V_54 * V_55 )
{
struct V_38 * V_39 = F_22 ( V_8 ) ;
struct V_56 * V_57 = & V_39 -> V_44 . V_58 [ 0 ] ;
struct V_40 * V_41 = (struct V_40 * ) V_8 -> V_21 ;
struct V_75 * V_76 = NULL ;
if ( V_74 ) {
V_37 -> V_62 . V_77 . V_78 =
V_74 -> V_79 . V_80 ;
V_76 = F_34 ( V_74 ) ;
V_37 -> V_62 . V_77 . V_81 = V_76 -> V_81 ;
}
if ( V_57 -> V_24 & V_82 ) {
V_37 -> V_62 . V_77 . V_83 = V_57 -> V_84 ;
if ( V_74 && V_37 -> V_62 . V_77 . V_83 > 7 &&
( ( V_74 -> V_79 . V_85 &
V_86 ) >>
V_87 ) ==
V_88 )
F_24 ( V_89 , & V_37 -> V_24 ) ;
} else {
V_37 -> V_62 . V_77 . V_83 = F_35 ( V_55 -> V_83 ) ;
if ( V_57 -> V_24 & V_72 )
V_37 -> V_62 . V_77 . V_83 |= 0x08 ;
}
if ( F_2 ( V_90 , & V_6 -> V_24 ) ) {
if ( ! ( V_39 -> V_24 & V_91 ) )
V_37 -> V_62 . V_77 . V_92 = V_93 ;
else
V_37 -> V_62 . V_77 . V_92 = V_94 ;
return;
}
V_37 -> V_62 . V_77 . V_95 = 7 ;
if ( V_39 -> V_24 & V_96 )
V_37 -> V_62 . V_77 . V_97 = 1 ;
if ( V_39 -> V_24 & V_98 &&
! ( V_39 -> V_24 & V_99 ) )
F_24 ( V_100 , & V_37 -> V_24 ) ;
if ( V_57 -> V_24 & V_101 ||
V_57 -> V_24 & V_102 )
F_24 ( V_103 , & V_37 -> V_24 ) ;
if ( V_57 -> V_24 & V_104 )
F_24 ( V_105 , & V_37 -> V_24 ) ;
if ( F_36 ( V_41 -> V_106 ) &&
! F_37 ( V_41 -> V_106 ) )
V_37 -> V_62 . V_77 . V_92 = V_94 ;
else if ( ! ( V_39 -> V_24 & V_91 ) )
V_37 -> V_62 . V_77 . V_92 = V_93 ;
else
V_37 -> V_62 . V_77 . V_92 = V_107 ;
}
static void F_38 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_36 * V_37 ,
struct V_73 * V_74 )
{
struct V_38 * V_39 = F_22 ( V_8 ) ;
struct V_40 * V_41 = (struct V_40 * ) V_8 -> V_21 ;
struct V_56 * V_57 = & V_39 -> V_44 . V_58 [ 0 ] ;
struct V_108 * V_109 ;
const struct V_54 * V_55 = NULL ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_110 = V_8 -> V_22 ;
V_37 -> V_31 = F_39 ( V_8 ) ;
if ( ! ( V_39 -> V_24 & V_111 ) )
F_24 ( V_112 , & V_37 -> V_24 ) ;
if ( F_40 ( V_41 -> V_106 ) ||
F_41 ( V_41 -> V_106 ) ) {
F_24 ( V_113 , & V_37 -> V_24 ) ;
if ( F_40 ( V_41 -> V_106 ) )
F_24 ( V_114 , & V_37 -> V_24 ) ;
else
F_24 ( V_115 , & V_37 -> V_24 ) ;
if ( V_39 -> V_44 . V_116 >= 0 )
V_109 =
F_42 ( V_6 -> V_117 , V_39 ) ;
}
V_37 -> V_118 = V_39 -> V_44 . V_58 [ 0 ] . V_119 - 1 ;
if ( V_37 -> V_118 >= V_6 -> V_120 )
F_24 ( V_121 , & V_37 -> V_24 ) ;
if ( F_43 ( V_41 -> V_106 ) ) {
F_24 ( V_113 , & V_37 -> V_24 ) ;
F_24 ( V_122 , & V_37 -> V_24 ) ;
}
if ( V_39 -> V_24 & V_123 )
F_24 ( V_113 , & V_37 -> V_24 ) ;
if ( F_37 ( V_41 -> V_106 ) ||
F_44 ( V_41 -> V_106 ) )
F_24 ( V_124 , & V_37 -> V_24 ) ;
if ( ( V_39 -> V_24 & V_91 ) &&
! F_2 ( V_114 , & V_37 -> V_24 ) )
F_24 ( V_51 , & V_37 -> V_24 ) ;
if ( V_57 -> V_24 & V_125 )
V_37 -> V_126 = V_127 ;
else if ( V_57 -> V_24 & V_82 )
V_37 -> V_126 = V_128 ;
else {
V_109 = F_45 ( V_6 -> V_117 , V_39 ) ;
V_55 = F_46 ( V_109 -> V_129 ) ;
if ( V_55 -> V_24 & V_68 )
V_37 -> V_126 = V_130 ;
else
V_37 -> V_126 = V_131 ;
}
F_47 ( V_6 , V_8 , V_37 ) ;
F_21 ( V_6 , V_8 , V_37 ) ;
if ( F_2 ( V_132 , & V_6 -> V_17 ) )
F_33 ( V_6 , V_8 , V_37 ,
V_74 , V_55 ) ;
else
F_29 ( V_6 , V_8 , V_37 ,
V_55 ) ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_5 * V_6 = V_3 -> V_7 -> V_6 ;
if ( F_49 ( V_6 -> V_133 -> V_134 -> V_135 &&
V_6 -> V_133 -> V_134 -> V_135 ( V_3 ) ) ) {
ERROR ( V_6 ,
L_1
L_2 ,
V_3 -> V_7 -> V_136 , V_137 ) ;
return - V_138 ;
}
F_15 ( V_3 -> V_8 , V_6 -> V_133 -> V_139 ) ;
memset ( V_3 -> V_8 -> V_21 , 0 , V_6 -> V_133 -> V_139 ) ;
if ( V_6 -> V_133 -> V_134 -> V_140 )
V_6 -> V_133 -> V_134 -> V_140 ( V_3 , V_37 ) ;
if ( F_2 ( V_18 , & V_6 -> V_17 ) )
F_8 ( V_3 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_141 * V_7 = V_3 -> V_7 ;
V_7 -> V_6 -> V_133 -> V_134 -> V_142 ( V_3 , V_37 ) ;
F_51 ( V_7 -> V_6 , V_143 , V_3 -> V_8 ) ;
}
static void F_52 ( struct V_141 * V_7 ,
struct V_36 * V_37 )
{
if ( F_53 ( V_7 ) ||
! F_2 ( V_113 , & V_37 -> V_24 ) )
V_7 -> V_6 -> V_133 -> V_134 -> V_144 ( V_7 ) ;
}
int F_54 ( struct V_141 * V_7 , struct V_1 * V_8 ,
bool V_145 )
{
struct V_38 * V_39 ;
struct V_2 * V_3 ;
struct V_36 V_37 ;
struct V_9 * V_10 ;
T_3 V_146 , V_147 ;
int V_148 = 0 ;
F_38 ( V_7 -> V_6 , V_8 , & V_37 , NULL ) ;
V_39 = F_22 ( V_8 ) ;
V_146 = V_39 -> V_44 . V_58 [ 0 ] . V_84 ;
V_147 = V_39 -> V_44 . V_58 [ 0 ] . V_24 ;
V_10 = F_6 ( V_8 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_149 = V_146 ;
V_10 -> V_150 = V_147 ;
if ( V_145 )
V_10 -> V_24 |= V_151 ;
if ( F_2 ( V_152 , & V_37 . V_24 ) &&
! F_2 ( V_153 , & V_37 . V_24 ) ) {
if ( F_2 ( V_154 , & V_7 -> V_6 -> V_17 ) )
F_55 ( V_8 , & V_37 ) ;
else
F_56 ( V_8 , & V_37 ) ;
}
if ( F_2 ( V_155 , & V_7 -> V_6 -> V_17 ) )
F_17 ( V_8 , V_37 . V_31 ) ;
else if ( F_2 ( V_18 , & V_7 -> V_6 -> V_17 ) )
F_13 ( V_8 ) ;
F_57 ( & V_7 -> V_156 ) ;
if ( F_49 ( F_58 ( V_7 ) ) ) {
ERROR ( V_7 -> V_6 ,
L_3 , V_7 -> V_136 ) ;
V_148 = - V_157 ;
goto V_158;
}
V_3 = F_59 ( V_7 , V_159 ) ;
if ( F_49 ( F_60 ( V_160 ,
& V_3 -> V_24 ) ) ) {
ERROR ( V_7 -> V_6 ,
L_4
L_2 ,
V_7 -> V_136 , V_137 ) ;
V_148 = - V_138 ;
goto V_158;
}
V_10 -> V_3 = V_3 ;
V_3 -> V_8 = V_8 ;
if ( F_49 ( F_48 ( V_3 , & V_37 ) ) ) {
F_61 ( V_160 , & V_3 -> V_24 ) ;
V_3 -> V_8 = NULL ;
V_148 = - V_161 ;
goto V_158;
}
F_62 ( V_162 , & V_3 -> V_24 ) ;
F_63 ( V_3 , V_159 ) ;
F_50 ( V_3 , & V_37 ) ;
F_52 ( V_7 , & V_37 ) ;
V_158:
F_64 ( & V_7 -> V_156 ) ;
return V_148 ;
}
int F_65 ( struct V_5 * V_6 ,
struct V_163 * V_45 )
{
struct V_42 * V_43 = F_23 ( V_45 ) ;
if ( F_49 ( ! V_43 -> V_164 ) )
return - V_157 ;
F_66 ( & V_43 -> V_165 ) ;
F_11 ( V_43 -> V_164 ) ;
if ( V_6 -> V_133 -> V_134 -> V_166 )
V_6 -> V_133 -> V_134 -> V_166 ( V_43 -> V_164 ) ;
F_67 ( & V_43 -> V_165 ) ;
return 0 ;
}
int F_68 ( struct V_5 * V_6 ,
struct V_163 * V_45 )
{
struct V_42 * V_43 = F_23 ( V_45 ) ;
struct V_9 * V_10 ;
struct V_36 V_37 ;
if ( F_49 ( ! V_43 -> V_164 ) )
return - V_157 ;
F_11 ( V_43 -> V_164 ) ;
V_43 -> V_164 -> V_8 = F_69 ( V_6 -> V_117 , V_45 ) ;
if ( ! V_43 -> V_164 -> V_8 )
return - V_167 ;
F_38 ( V_6 , V_43 -> V_164 -> V_8 , & V_37 , NULL ) ;
V_10 = F_6 ( V_43 -> V_164 -> V_8 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_3 = V_43 -> V_164 ;
V_6 -> V_133 -> V_134 -> V_168 ( V_43 -> V_164 , & V_37 ) ;
return 0 ;
}
int F_70 ( struct V_5 * V_6 ,
struct V_163 * V_45 )
{
struct V_42 * V_43 = F_23 ( V_45 ) ;
int V_148 ;
F_66 ( & V_43 -> V_165 ) ;
V_148 = F_68 ( V_6 , V_45 ) ;
F_67 ( & V_43 -> V_165 ) ;
return V_148 ;
}
bool F_71 ( struct V_141 * V_7 ,
enum V_169 V_170 ,
enum V_169 V_171 ,
bool (* F_72)( struct V_2 * V_3 ) )
{
unsigned long V_172 ;
unsigned int V_173 ;
unsigned int V_174 ;
unsigned int V_175 ;
if ( F_49 ( V_170 >= V_176 || V_171 >= V_176 ) ) {
ERROR ( V_7 -> V_6 ,
L_5 ,
V_170 , V_171 ) ;
return true ;
}
F_73 ( & V_7 -> V_177 , V_172 ) ;
V_173 = V_7 -> V_178 [ V_170 ] ;
V_174 = V_7 -> V_178 [ V_171 ] ;
F_74 ( & V_7 -> V_177 , V_172 ) ;
if ( V_173 < V_174 ) {
for ( V_175 = V_173 ; V_175 < V_174 ; V_175 ++ ) {
if ( F_72 ( & V_7 -> V_179 [ V_175 ] ) )
return true ;
}
} else {
for ( V_175 = V_173 ; V_175 < V_7 -> V_180 ; V_175 ++ ) {
if ( F_72 ( & V_7 -> V_179 [ V_175 ] ) )
return true ;
}
for ( V_175 = 0 ; V_175 < V_174 ; V_175 ++ ) {
if ( F_72 ( & V_7 -> V_179 [ V_175 ] ) )
return true ;
}
}
return false ;
}
struct V_2 * F_59 ( struct V_141 * V_7 ,
enum V_169 V_178 )
{
struct V_2 * V_3 ;
unsigned long V_172 ;
if ( F_49 ( V_178 >= V_176 ) ) {
ERROR ( V_7 -> V_6 ,
L_6 , V_178 ) ;
return NULL ;
}
F_73 ( & V_7 -> V_177 , V_172 ) ;
V_3 = & V_7 -> V_179 [ V_7 -> V_178 [ V_178 ] ] ;
F_74 ( & V_7 -> V_177 , V_172 ) ;
return V_3 ;
}
void F_63 ( struct V_2 * V_3 , enum V_169 V_178 )
{
struct V_141 * V_7 = V_3 -> V_7 ;
unsigned long V_172 ;
if ( F_49 ( V_178 >= V_176 ) ) {
ERROR ( V_7 -> V_6 ,
L_7 , V_178 ) ;
return;
}
F_73 ( & V_7 -> V_177 , V_172 ) ;
V_7 -> V_178 [ V_178 ] ++ ;
if ( V_7 -> V_178 [ V_178 ] >= V_7 -> V_180 )
V_7 -> V_178 [ V_178 ] = 0 ;
V_3 -> V_181 = V_182 ;
if ( V_178 == V_159 ) {
V_7 -> V_110 ++ ;
} else if ( V_178 == V_183 ) {
V_7 -> V_110 -- ;
V_7 -> V_119 ++ ;
}
F_74 ( & V_7 -> V_177 , V_172 ) ;
}
void F_75 ( struct V_141 * V_7 )
{
if ( ! F_2 ( V_184 , & V_7 -> V_6 -> V_24 ) ||
! F_2 ( V_185 , & V_7 -> V_24 ) ||
F_60 ( V_186 , & V_7 -> V_24 ) )
return;
switch ( V_7 -> V_136 ) {
case V_187 :
case V_188 :
case V_189 :
case V_190 :
F_76 ( V_7 -> V_6 -> V_117 , V_7 -> V_136 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_141 * V_7 )
{
if ( ! F_2 ( V_184 , & V_7 -> V_6 -> V_24 ) ||
! F_2 ( V_185 , & V_7 -> V_24 ) ||
! F_78 ( V_186 , & V_7 -> V_24 ) )
return;
switch ( V_7 -> V_136 ) {
case V_187 :
case V_188 :
case V_189 :
case V_190 :
F_79 ( V_7 -> V_6 -> V_117 , V_7 -> V_136 ) ;
break;
case V_191 :
V_7 -> V_6 -> V_133 -> V_134 -> V_144 ( V_7 ) ;
default:
break;
}
}
void F_80 ( struct V_141 * V_7 )
{
F_66 ( & V_7 -> V_192 ) ;
if ( ! F_2 ( V_184 , & V_7 -> V_6 -> V_24 ) ||
F_60 ( V_185 , & V_7 -> V_24 ) ) {
F_67 ( & V_7 -> V_192 ) ;
return;
}
F_62 ( V_186 , & V_7 -> V_24 ) ;
V_7 -> V_6 -> V_133 -> V_134 -> V_193 ( V_7 ) ;
F_77 ( V_7 ) ;
F_67 ( & V_7 -> V_192 ) ;
}
void F_81 ( struct V_141 * V_7 )
{
F_66 ( & V_7 -> V_192 ) ;
if ( ! F_78 ( V_185 , & V_7 -> V_24 ) ) {
F_67 ( & V_7 -> V_192 ) ;
return;
}
F_75 ( V_7 ) ;
V_7 -> V_6 -> V_133 -> V_134 -> V_194 ( V_7 ) ;
F_67 ( & V_7 -> V_192 ) ;
}
void F_82 ( struct V_141 * V_7 , bool V_195 )
{
bool V_196 ;
bool V_197 =
( V_7 -> V_136 == V_187 ) ||
( V_7 -> V_136 == V_188 ) ||
( V_7 -> V_136 == V_189 ) ||
( V_7 -> V_136 == V_190 ) ;
F_66 ( & V_7 -> V_192 ) ;
V_196 = F_2 ( V_185 , & V_7 -> V_24 ) ;
if ( V_196 ) {
F_75 ( V_7 ) ;
if ( ! V_195 && V_197 )
V_7 -> V_6 -> V_133 -> V_134 -> V_144 ( V_7 ) ;
}
if ( F_83 ( V_7 -> V_6 -> V_133 -> V_134 -> V_198 ) )
V_7 -> V_6 -> V_133 -> V_134 -> V_198 ( V_7 , V_195 ) ;
if ( F_49 ( ! F_84 ( V_7 ) ) )
F_85 ( V_7 -> V_6 , L_8 , V_7 -> V_136 ) ;
if ( V_196 )
F_77 ( V_7 ) ;
F_67 ( & V_7 -> V_192 ) ;
}
void F_86 ( struct V_5 * V_6 )
{
struct V_141 * V_7 ;
F_87 (rt2x00dev, queue)
F_80 ( V_7 ) ;
F_80 ( V_6 -> V_199 ) ;
}
void F_88 ( struct V_5 * V_6 )
{
struct V_141 * V_7 ;
F_89 ( V_6 -> V_117 ) ;
F_87 (rt2x00dev, queue)
F_81 ( V_7 ) ;
F_81 ( V_6 -> V_199 ) ;
}
void F_90 ( struct V_5 * V_6 , bool V_195 )
{
struct V_141 * V_7 ;
F_87 (rt2x00dev, queue)
F_82 ( V_7 , V_195 ) ;
F_82 ( V_6 -> V_199 , V_195 ) ;
}
static void F_91 ( struct V_141 * V_7 )
{
unsigned long V_172 ;
unsigned int V_175 ;
F_73 ( & V_7 -> V_177 , V_172 ) ;
V_7 -> V_119 = 0 ;
V_7 -> V_110 = 0 ;
for ( V_175 = 0 ; V_175 < V_176 ; V_175 ++ )
V_7 -> V_178 [ V_175 ] = 0 ;
F_74 ( & V_7 -> V_177 , V_172 ) ;
}
void F_92 ( struct V_5 * V_6 )
{
struct V_141 * V_7 ;
unsigned int V_175 ;
F_93 (rt2x00dev, queue) {
F_91 ( V_7 ) ;
for ( V_175 = 0 ; V_175 < V_7 -> V_180 ; V_175 ++ )
V_6 -> V_133 -> V_134 -> V_200 ( & V_7 -> V_179 [ V_175 ] ) ;
}
}
static int F_94 ( struct V_141 * V_7 ,
const struct V_201 * V_202 )
{
struct V_2 * V_179 ;
unsigned int V_203 ;
unsigned int V_175 ;
F_91 ( V_7 ) ;
V_7 -> V_180 = V_202 -> V_204 ;
V_7 -> V_205 = F_95 ( V_202 -> V_204 , 10 ) ;
V_7 -> V_14 = V_202 -> V_14 ;
V_7 -> V_15 = V_202 -> V_15 ;
V_203 = sizeof( * V_179 ) + V_202 -> V_206 ;
V_179 = F_96 ( V_7 -> V_180 , V_203 , V_207 ) ;
if ( ! V_179 )
return - V_167 ;
#define F_97 ( T_4 , T_5 , T_6 , T_7 , T_8 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_175 = 0 ; V_175 < V_7 -> V_180 ; V_175 ++ ) {
V_179 [ V_175 ] . V_24 = 0 ;
V_179 [ V_175 ] . V_7 = V_7 ;
V_179 [ V_175 ] . V_8 = NULL ;
V_179 [ V_175 ] . V_208 = V_175 ;
V_179 [ V_175 ] . V_209 =
F_97 ( V_179 , V_175 , V_7 -> V_180 ,
sizeof( * V_179 ) , V_202 -> V_206 ) ;
}
#undef F_97
V_7 -> V_179 = V_179 ;
return 0 ;
}
static void F_98 ( struct V_141 * V_7 )
{
unsigned int V_175 ;
if ( ! V_7 -> V_179 )
return;
for ( V_175 = 0 ; V_175 < V_7 -> V_180 ; V_175 ++ ) {
F_11 ( & V_7 -> V_179 [ V_175 ] ) ;
}
}
static int F_99 ( struct V_141 * V_7 )
{
unsigned int V_175 ;
struct V_1 * V_8 ;
for ( V_175 = 0 ; V_175 < V_7 -> V_180 ; V_175 ++ ) {
V_8 = F_1 ( & V_7 -> V_179 [ V_175 ] , V_207 ) ;
if ( ! V_8 )
return - V_167 ;
V_7 -> V_179 [ V_175 ] . V_8 = V_8 ;
}
return 0 ;
}
int F_100 ( struct V_5 * V_6 )
{
struct V_141 * V_7 ;
int V_210 ;
V_210 = F_94 ( V_6 -> V_199 , V_6 -> V_133 -> V_199 ) ;
if ( V_210 )
goto exit;
F_87 (rt2x00dev, queue) {
V_210 = F_94 ( V_7 , V_6 -> V_133 -> V_211 ) ;
if ( V_210 )
goto exit;
}
V_210 = F_94 ( V_6 -> V_212 , V_6 -> V_133 -> V_212 ) ;
if ( V_210 )
goto exit;
if ( F_2 ( V_213 , & V_6 -> V_17 ) ) {
V_210 = F_94 ( V_6 -> V_214 ,
V_6 -> V_133 -> V_214 ) ;
if ( V_210 )
goto exit;
}
V_210 = F_99 ( V_6 -> V_199 ) ;
if ( V_210 )
goto exit;
return 0 ;
exit:
ERROR ( V_6 , L_9 ) ;
F_101 ( V_6 ) ;
return V_210 ;
}
void F_101 ( struct V_5 * V_6 )
{
struct V_141 * V_7 ;
F_98 ( V_6 -> V_199 ) ;
F_93 (rt2x00dev, queue) {
F_102 ( V_7 -> V_179 ) ;
V_7 -> V_179 = NULL ;
}
}
static void F_103 ( struct V_5 * V_6 ,
struct V_141 * V_7 , enum V_215 V_136 )
{
F_104 ( & V_7 -> V_192 ) ;
F_105 ( & V_7 -> V_156 ) ;
F_105 ( & V_7 -> V_177 ) ;
V_7 -> V_6 = V_6 ;
V_7 -> V_136 = V_136 ;
V_7 -> V_92 = 0 ;
V_7 -> V_216 = 2 ;
V_7 -> V_217 = 5 ;
V_7 -> V_218 = 10 ;
}
int F_106 ( struct V_5 * V_6 )
{
struct V_141 * V_7 ;
enum V_215 V_136 ;
unsigned int V_219 =
! ! F_2 ( V_213 , & V_6 -> V_17 ) ;
V_6 -> V_220 = 2 + V_6 -> V_133 -> V_221 + V_219 ;
V_7 = F_96 ( V_6 -> V_220 , sizeof( * V_7 ) , V_207 ) ;
if ( ! V_7 ) {
ERROR ( V_6 , L_10 ) ;
return - V_167 ;
}
V_6 -> V_199 = V_7 ;
V_6 -> V_211 = & V_7 [ 1 ] ;
V_6 -> V_212 = & V_7 [ 1 + V_6 -> V_133 -> V_221 ] ;
V_6 -> V_214 = V_219 ? & V_7 [ 2 + V_6 -> V_133 -> V_221 ] : NULL ;
F_103 ( V_6 , V_6 -> V_199 , V_191 ) ;
V_136 = V_187 ;
F_87 (rt2x00dev, queue)
F_103 ( V_6 , V_7 , V_136 ++ ) ;
F_103 ( V_6 , V_6 -> V_212 , V_222 ) ;
if ( V_219 )
F_103 ( V_6 , V_6 -> V_214 , V_223 ) ;
return 0 ;
}
void F_107 ( struct V_5 * V_6 )
{
F_102 ( V_6 -> V_199 ) ;
V_6 -> V_199 = NULL ;
V_6 -> V_211 = NULL ;
V_6 -> V_212 = NULL ;
}
