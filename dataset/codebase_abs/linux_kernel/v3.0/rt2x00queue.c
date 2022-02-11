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
static void F_21 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_22 ( V_3 -> V_7 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_3 -> V_7 -> V_20 ;
struct V_41 * V_42 = F_23 ( V_38 -> V_43 . V_44 ) ;
unsigned long V_45 ;
if ( ! ( V_38 -> V_23 & V_46 ) )
return;
F_24 ( V_47 , & V_36 -> V_23 ) ;
if ( ! F_2 ( V_48 , & V_3 -> V_6 -> V_5 -> V_16 ) )
return;
F_25 ( & V_42 -> V_49 , V_45 ) ;
if ( F_2 ( V_50 , & V_36 -> V_23 ) )
V_42 -> V_51 += 0x10 ;
V_40 -> V_52 &= F_26 ( V_53 ) ;
V_40 -> V_52 |= F_26 ( V_42 -> V_51 ) ;
F_27 ( & V_42 -> V_49 , V_45 ) ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
const struct V_54 * V_55 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_5 ;
struct V_37 * V_38 = F_22 ( V_3 -> V_7 ) ;
struct V_56 * V_57 = & V_38 -> V_43 . V_58 [ 0 ] ;
unsigned int V_59 ;
unsigned int V_60 ;
unsigned int V_61 ;
if ( F_2 ( V_50 , & V_36 -> V_23 ) )
V_36 -> V_62 . V_63 . V_64 = V_65 ;
else
V_36 -> V_62 . V_63 . V_64 = V_66 ;
V_59 = V_3 -> V_7 -> V_21 + 4 ;
V_59 += F_29 ( V_5 , V_3 -> V_7 ) ;
V_36 -> V_62 . V_63 . signal = V_55 -> V_63 ;
V_36 -> V_62 . V_63 . V_67 = 0x04 ;
if ( V_55 -> V_23 & V_68 ) {
V_36 -> V_62 . V_63 . V_69 = ( V_59 >> 6 ) & 0x3f ;
V_36 -> V_62 . V_63 . V_70 = V_59 & 0x3f ;
} else {
V_61 = F_30 ( V_59 , V_55 -> V_71 ) ;
V_60 = F_31 ( V_59 , V_55 -> V_71 ) ;
if ( V_61 != 0 ) {
V_60 ++ ;
if ( V_55 -> V_71 == 110 && V_61 <= 30 )
V_36 -> V_62 . V_63 . V_67 |= 0x80 ;
}
V_36 -> V_62 . V_63 . V_69 = ( V_60 >> 8 ) & 0xff ;
V_36 -> V_62 . V_63 . V_70 = V_60 & 0xff ;
if ( V_57 -> V_23 & V_72 )
V_36 -> V_62 . V_63 . signal |= 0x08 ;
}
}
static void F_32 ( struct V_2 * V_3 ,
struct V_35 * V_36 ,
const struct V_54 * V_55 )
{
struct V_37 * V_38 = F_22 ( V_3 -> V_7 ) ;
struct V_56 * V_57 = & V_38 -> V_43 . V_58 [ 0 ] ;
struct V_39 * V_40 = (struct V_39 * ) V_3 -> V_7 -> V_20 ;
if ( V_38 -> V_43 . V_73 )
V_36 -> V_62 . V_74 . V_75 =
V_38 -> V_43 . V_73 -> V_76 . V_77 ;
V_36 -> V_62 . V_74 . V_78 = 7 ;
if ( V_38 -> V_23 & V_79 )
V_36 -> V_62 . V_74 . V_80 = 1 ;
if ( V_57 -> V_23 & V_81 ) {
V_36 -> V_62 . V_74 . V_82 = V_57 -> V_83 ;
if ( V_38 -> V_43 . V_73 && V_36 -> V_62 . V_74 . V_82 > 7 &&
( ( V_38 -> V_43 . V_73 -> V_76 . V_84 &
V_85 ) >>
V_86 ) ==
V_87 )
F_24 ( V_88 , & V_36 -> V_23 ) ;
} else {
V_36 -> V_62 . V_74 . V_82 = F_33 ( V_55 -> V_82 ) ;
if ( V_57 -> V_23 & V_72 )
V_36 -> V_62 . V_74 . V_82 |= 0x08 ;
}
if ( V_38 -> V_23 & V_89 &&
! ( V_38 -> V_23 & V_90 ) )
F_24 ( V_91 , & V_36 -> V_23 ) ;
if ( V_57 -> V_23 & V_92 ||
V_57 -> V_23 & V_93 )
F_24 ( V_94 , & V_36 -> V_23 ) ;
if ( V_57 -> V_23 & V_95 )
F_24 ( V_96 , & V_36 -> V_23 ) ;
if ( F_34 ( V_40 -> V_97 ) &&
! F_35 ( V_40 -> V_97 ) )
V_36 -> V_62 . V_74 . V_98 = V_99 ;
else if ( ! ( V_38 -> V_23 & V_100 ) )
V_36 -> V_62 . V_74 . V_98 = V_101 ;
else
V_36 -> V_62 . V_74 . V_98 = V_102 ;
}
static void F_36 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_5 ;
struct V_37 * V_38 = F_22 ( V_3 -> V_7 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_3 -> V_7 -> V_20 ;
struct V_56 * V_57 = & V_38 -> V_43 . V_58 [ 0 ] ;
struct V_103 * V_104 ;
const struct V_54 * V_55 = NULL ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_105 = V_3 -> V_7 -> V_21 ;
V_36 -> V_30 = F_37 ( V_3 -> V_7 ) ;
if ( ! ( V_38 -> V_23 & V_106 ) )
F_24 ( V_107 , & V_36 -> V_23 ) ;
if ( F_38 ( V_40 -> V_97 ) ||
F_39 ( V_40 -> V_97 ) ) {
F_24 ( V_108 , & V_36 -> V_23 ) ;
if ( F_38 ( V_40 -> V_97 ) )
F_24 ( V_109 , & V_36 -> V_23 ) ;
else
F_24 ( V_110 , & V_36 -> V_23 ) ;
if ( V_38 -> V_43 . V_111 >= 0 )
V_104 =
F_40 ( V_5 -> V_112 , V_38 ) ;
}
V_36 -> V_113 = V_38 -> V_43 . V_58 [ 0 ] . V_114 - 1 ;
if ( V_36 -> V_113 >= V_5 -> V_115 )
F_24 ( V_116 , & V_36 -> V_23 ) ;
if ( F_41 ( V_40 -> V_97 ) ) {
F_24 ( V_108 , & V_36 -> V_23 ) ;
F_24 ( V_117 , & V_36 -> V_23 ) ;
}
if ( V_38 -> V_23 & V_118 )
F_24 ( V_108 , & V_36 -> V_23 ) ;
if ( F_35 ( V_40 -> V_97 ) ||
F_42 ( V_40 -> V_97 ) )
F_24 ( V_119 , & V_36 -> V_23 ) ;
if ( ( V_38 -> V_23 & V_100 ) &&
! F_2 ( V_109 , & V_36 -> V_23 ) )
F_24 ( V_50 , & V_36 -> V_23 ) ;
if ( V_57 -> V_23 & V_120 )
V_36 -> V_121 = V_122 ;
else if ( V_57 -> V_23 & V_81 )
V_36 -> V_121 = V_123 ;
else {
V_104 = F_43 ( V_5 -> V_112 , V_38 ) ;
V_55 = F_44 ( V_104 -> V_124 ) ;
if ( V_55 -> V_23 & V_68 )
V_36 -> V_121 = V_125 ;
else
V_36 -> V_121 = V_126 ;
}
F_45 ( V_3 , V_36 ) ;
F_21 ( V_3 , V_36 ) ;
if ( F_2 ( V_127 , & V_5 -> V_16 ) )
F_32 ( V_3 , V_36 , V_55 ) ;
else
F_28 ( V_3 , V_36 , V_55 ) ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_5 ;
if ( F_47 ( V_5 -> V_128 -> V_129 -> V_130 &&
V_5 -> V_128 -> V_129 -> V_130 ( V_3 ) ) ) {
ERROR ( V_5 ,
L_1
L_2 ,
V_3 -> V_6 -> V_131 , V_132 ) ;
return - V_133 ;
}
F_15 ( V_3 -> V_7 , V_5 -> V_128 -> V_134 ) ;
memset ( V_3 -> V_7 -> V_20 , 0 , V_5 -> V_128 -> V_134 ) ;
if ( V_5 -> V_128 -> V_129 -> V_135 )
V_5 -> V_128 -> V_129 -> V_135 ( V_3 , V_36 ) ;
if ( F_2 ( V_17 , & V_5 -> V_16 ) )
F_8 ( V_3 ) ;
return 0 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_136 * V_6 = V_3 -> V_6 ;
V_6 -> V_5 -> V_128 -> V_129 -> V_137 ( V_3 , V_36 ) ;
F_49 ( V_6 -> V_5 , V_138 , V_3 -> V_7 ) ;
}
static void F_50 ( struct V_136 * V_6 ,
struct V_35 * V_36 )
{
if ( F_51 ( V_6 ) ||
! F_2 ( V_108 , & V_36 -> V_23 ) )
V_6 -> V_5 -> V_128 -> V_129 -> V_139 ( V_6 ) ;
}
int F_52 ( struct V_136 * V_6 , struct V_1 * V_7 ,
bool V_140 )
{
struct V_37 * V_38 ;
struct V_2 * V_3 = F_53 ( V_6 , V_141 ) ;
struct V_35 V_36 ;
struct V_8 * V_9 ;
T_1 V_142 , V_143 ;
if ( F_47 ( F_54 ( V_6 ) ) ) {
ERROR ( V_6 -> V_5 ,
L_3 , V_6 -> V_131 ) ;
return - V_144 ;
}
if ( F_47 ( F_55 ( V_145 ,
& V_3 -> V_23 ) ) ) {
ERROR ( V_6 -> V_5 ,
L_4
L_2 ,
V_6 -> V_131 , V_132 ) ;
return - V_133 ;
}
V_3 -> V_7 = V_7 ;
F_36 ( V_3 , & V_36 ) ;
V_38 = F_22 ( V_7 ) ;
V_142 = V_38 -> V_43 . V_58 [ 0 ] . V_83 ;
V_143 = V_38 -> V_43 . V_58 [ 0 ] . V_23 ;
V_9 = F_6 ( V_7 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_3 = V_3 ;
V_9 -> V_146 = V_142 ;
V_9 -> V_147 = V_143 ;
if ( V_140 )
V_9 -> V_23 |= V_148 ;
if ( F_2 ( V_149 , & V_36 . V_23 ) &&
! F_2 ( V_150 , & V_36 . V_23 ) ) {
if ( F_2 ( V_151 , & V_6 -> V_5 -> V_16 ) )
F_56 ( V_7 , & V_36 ) ;
else
F_57 ( V_7 , & V_36 ) ;
}
if ( F_2 ( V_152 , & V_6 -> V_5 -> V_16 ) )
F_17 ( V_3 -> V_7 , V_36 . V_30 ) ;
else if ( F_2 ( V_17 , & V_6 -> V_5 -> V_16 ) )
F_13 ( V_3 -> V_7 ) ;
if ( F_47 ( F_46 ( V_3 , & V_36 ) ) ) {
F_58 ( V_145 , & V_3 -> V_23 ) ;
V_3 -> V_7 = NULL ;
return - V_153 ;
}
F_59 ( V_154 , & V_3 -> V_23 ) ;
F_60 ( V_3 , V_141 ) ;
F_48 ( V_3 , & V_36 ) ;
F_50 ( V_6 , & V_36 ) ;
return 0 ;
}
int F_61 ( struct V_4 * V_5 ,
struct V_155 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
if ( F_47 ( ! V_42 -> V_156 ) )
return - V_144 ;
F_62 ( & V_42 -> V_157 ) ;
F_11 ( V_42 -> V_156 ) ;
if ( V_5 -> V_128 -> V_129 -> V_158 )
V_5 -> V_128 -> V_129 -> V_158 ( V_42 -> V_156 ) ;
F_63 ( & V_42 -> V_157 ) ;
return 0 ;
}
int F_64 ( struct V_4 * V_5 ,
struct V_155 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
struct V_8 * V_9 ;
struct V_35 V_36 ;
if ( F_47 ( ! V_42 -> V_156 ) )
return - V_144 ;
F_11 ( V_42 -> V_156 ) ;
V_42 -> V_156 -> V_7 = F_65 ( V_5 -> V_112 , V_44 ) ;
if ( ! V_42 -> V_156 -> V_7 )
return - V_159 ;
F_36 ( V_42 -> V_156 , & V_36 ) ;
V_9 = F_6 ( V_42 -> V_156 -> V_7 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_3 = V_42 -> V_156 ;
V_5 -> V_128 -> V_129 -> V_160 ( V_42 -> V_156 , & V_36 ) ;
return 0 ;
}
int F_66 ( struct V_4 * V_5 ,
struct V_155 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
int V_161 ;
F_62 ( & V_42 -> V_157 ) ;
V_161 = F_64 ( V_5 , V_44 ) ;
F_63 ( & V_42 -> V_157 ) ;
return V_161 ;
}
bool F_67 ( struct V_136 * V_6 ,
enum V_162 V_163 ,
enum V_162 V_164 ,
void * V_20 ,
bool (* F_68)( struct V_2 * V_3 ,
void * V_20 ) )
{
unsigned long V_45 ;
unsigned int V_165 ;
unsigned int V_166 ;
unsigned int V_167 ;
if ( F_47 ( V_163 >= V_168 || V_164 >= V_168 ) ) {
ERROR ( V_6 -> V_5 ,
L_5 ,
V_163 , V_164 ) ;
return true ;
}
F_25 ( & V_6 -> V_169 , V_45 ) ;
V_165 = V_6 -> V_170 [ V_163 ] ;
V_166 = V_6 -> V_170 [ V_164 ] ;
F_27 ( & V_6 -> V_169 , V_45 ) ;
if ( V_165 < V_166 ) {
for ( V_167 = V_165 ; V_167 < V_166 ; V_167 ++ ) {
if ( F_68 ( & V_6 -> V_171 [ V_167 ] , V_20 ) )
return true ;
}
} else {
for ( V_167 = V_165 ; V_167 < V_6 -> V_172 ; V_167 ++ ) {
if ( F_68 ( & V_6 -> V_171 [ V_167 ] , V_20 ) )
return true ;
}
for ( V_167 = 0 ; V_167 < V_166 ; V_167 ++ ) {
if ( F_68 ( & V_6 -> V_171 [ V_167 ] , V_20 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_53 ( struct V_136 * V_6 ,
enum V_162 V_170 )
{
struct V_2 * V_3 ;
unsigned long V_45 ;
if ( F_47 ( V_170 >= V_168 ) ) {
ERROR ( V_6 -> V_5 ,
L_6 , V_170 ) ;
return NULL ;
}
F_25 ( & V_6 -> V_169 , V_45 ) ;
V_3 = & V_6 -> V_171 [ V_6 -> V_170 [ V_170 ] ] ;
F_27 ( & V_6 -> V_169 , V_45 ) ;
return V_3 ;
}
void F_60 ( struct V_2 * V_3 , enum V_162 V_170 )
{
struct V_136 * V_6 = V_3 -> V_6 ;
unsigned long V_45 ;
if ( F_47 ( V_170 >= V_168 ) ) {
ERROR ( V_6 -> V_5 ,
L_7 , V_170 ) ;
return;
}
F_25 ( & V_6 -> V_169 , V_45 ) ;
V_6 -> V_170 [ V_170 ] ++ ;
if ( V_6 -> V_170 [ V_170 ] >= V_6 -> V_172 )
V_6 -> V_170 [ V_170 ] = 0 ;
V_3 -> V_173 = V_174 ;
if ( V_170 == V_141 ) {
V_6 -> V_105 ++ ;
} else if ( V_170 == V_175 ) {
V_6 -> V_105 -- ;
V_6 -> V_114 ++ ;
}
F_27 ( & V_6 -> V_169 , V_45 ) ;
}
void F_69 ( struct V_136 * V_6 )
{
if ( ! F_2 ( V_176 , & V_6 -> V_5 -> V_23 ) ||
! F_2 ( V_177 , & V_6 -> V_23 ) ||
F_55 ( V_178 , & V_6 -> V_23 ) )
return;
switch ( V_6 -> V_131 ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
F_70 ( V_6 -> V_5 -> V_112 , V_6 -> V_131 ) ;
break;
default:
break;
}
}
void F_71 ( struct V_136 * V_6 )
{
if ( ! F_2 ( V_176 , & V_6 -> V_5 -> V_23 ) ||
! F_2 ( V_177 , & V_6 -> V_23 ) ||
! F_72 ( V_178 , & V_6 -> V_23 ) )
return;
switch ( V_6 -> V_131 ) {
case V_179 :
case V_180 :
case V_181 :
case V_182 :
F_73 ( V_6 -> V_5 -> V_112 , V_6 -> V_131 ) ;
break;
case V_183 :
V_6 -> V_5 -> V_128 -> V_129 -> V_139 ( V_6 ) ;
default:
break;
}
}
void F_74 ( struct V_136 * V_6 )
{
F_62 ( & V_6 -> V_184 ) ;
if ( ! F_2 ( V_176 , & V_6 -> V_5 -> V_23 ) ||
F_55 ( V_177 , & V_6 -> V_23 ) ) {
F_63 ( & V_6 -> V_184 ) ;
return;
}
F_59 ( V_178 , & V_6 -> V_23 ) ;
V_6 -> V_5 -> V_128 -> V_129 -> V_185 ( V_6 ) ;
F_71 ( V_6 ) ;
F_63 ( & V_6 -> V_184 ) ;
}
void F_75 ( struct V_136 * V_6 )
{
F_62 ( & V_6 -> V_184 ) ;
if ( ! F_72 ( V_177 , & V_6 -> V_23 ) ) {
F_63 ( & V_6 -> V_184 ) ;
return;
}
F_69 ( V_6 ) ;
V_6 -> V_5 -> V_128 -> V_129 -> V_186 ( V_6 ) ;
F_63 ( & V_6 -> V_184 ) ;
}
void F_76 ( struct V_136 * V_6 , bool V_187 )
{
bool V_188 ;
bool V_189 =
( V_6 -> V_131 == V_179 ) ||
( V_6 -> V_131 == V_180 ) ||
( V_6 -> V_131 == V_181 ) ||
( V_6 -> V_131 == V_182 ) ;
F_62 ( & V_6 -> V_184 ) ;
V_188 = F_2 ( V_177 , & V_6 -> V_23 ) ;
if ( V_188 ) {
F_69 ( V_6 ) ;
if ( ! V_187 && V_189 )
V_6 -> V_5 -> V_128 -> V_129 -> V_139 ( V_6 ) ;
}
if ( F_77 ( V_6 -> V_5 -> V_128 -> V_129 -> V_190 ) )
V_6 -> V_5 -> V_128 -> V_129 -> V_190 ( V_6 , V_187 ) ;
if ( F_47 ( ! F_78 ( V_6 ) ) )
F_79 ( V_6 -> V_5 , L_8 , V_6 -> V_131 ) ;
if ( V_188 )
F_71 ( V_6 ) ;
F_63 ( & V_6 -> V_184 ) ;
}
void F_80 ( struct V_4 * V_5 )
{
struct V_136 * V_6 ;
F_81 (rt2x00dev, queue)
F_74 ( V_6 ) ;
F_74 ( V_5 -> V_191 ) ;
}
void F_82 ( struct V_4 * V_5 )
{
struct V_136 * V_6 ;
F_83 ( V_5 -> V_112 ) ;
F_81 (rt2x00dev, queue)
F_75 ( V_6 ) ;
F_75 ( V_5 -> V_191 ) ;
}
void F_84 ( struct V_4 * V_5 , bool V_187 )
{
struct V_136 * V_6 ;
F_81 (rt2x00dev, queue)
F_76 ( V_6 , V_187 ) ;
F_76 ( V_5 -> V_191 , V_187 ) ;
}
static void F_85 ( struct V_136 * V_6 )
{
unsigned long V_45 ;
unsigned int V_167 ;
F_25 ( & V_6 -> V_169 , V_45 ) ;
V_6 -> V_114 = 0 ;
V_6 -> V_105 = 0 ;
for ( V_167 = 0 ; V_167 < V_168 ; V_167 ++ )
V_6 -> V_170 [ V_167 ] = 0 ;
F_27 ( & V_6 -> V_169 , V_45 ) ;
}
void F_86 ( struct V_4 * V_5 )
{
struct V_136 * V_6 ;
unsigned int V_167 ;
F_87 (rt2x00dev, queue) {
F_85 ( V_6 ) ;
for ( V_167 = 0 ; V_167 < V_6 -> V_172 ; V_167 ++ )
V_5 -> V_128 -> V_129 -> V_192 ( & V_6 -> V_171 [ V_167 ] ) ;
}
}
static int F_88 ( struct V_136 * V_6 ,
const struct V_193 * V_194 )
{
struct V_2 * V_171 ;
unsigned int V_195 ;
unsigned int V_167 ;
F_85 ( V_6 ) ;
V_6 -> V_172 = V_194 -> V_196 ;
V_6 -> V_197 = F_89 ( V_194 -> V_196 , 10 ) ;
V_6 -> V_13 = V_194 -> V_13 ;
V_6 -> V_14 = V_194 -> V_14 ;
V_195 = sizeof( * V_171 ) + V_194 -> V_198 ;
V_171 = F_90 ( V_6 -> V_172 , V_195 , V_199 ) ;
if ( ! V_171 )
return - V_159 ;
#define F_91 ( T_2 , T_3 , T_4 , T_5 , T_6 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_167 = 0 ; V_167 < V_6 -> V_172 ; V_167 ++ ) {
V_171 [ V_167 ] . V_23 = 0 ;
V_171 [ V_167 ] . V_6 = V_6 ;
V_171 [ V_167 ] . V_7 = NULL ;
V_171 [ V_167 ] . V_200 = V_167 ;
V_171 [ V_167 ] . V_201 =
F_91 ( V_171 , V_167 , V_6 -> V_172 ,
sizeof( * V_171 ) , V_194 -> V_198 ) ;
}
#undef F_91
V_6 -> V_171 = V_171 ;
return 0 ;
}
static void F_92 ( struct V_136 * V_6 )
{
unsigned int V_167 ;
if ( ! V_6 -> V_171 )
return;
for ( V_167 = 0 ; V_167 < V_6 -> V_172 ; V_167 ++ ) {
F_11 ( & V_6 -> V_171 [ V_167 ] ) ;
}
}
static int F_93 ( struct V_136 * V_6 )
{
unsigned int V_167 ;
struct V_1 * V_7 ;
for ( V_167 = 0 ; V_167 < V_6 -> V_172 ; V_167 ++ ) {
V_7 = F_1 ( & V_6 -> V_171 [ V_167 ] ) ;
if ( ! V_7 )
return - V_159 ;
V_6 -> V_171 [ V_167 ] . V_7 = V_7 ;
}
return 0 ;
}
int F_94 ( struct V_4 * V_5 )
{
struct V_136 * V_6 ;
int V_202 ;
V_202 = F_88 ( V_5 -> V_191 , V_5 -> V_128 -> V_191 ) ;
if ( V_202 )
goto exit;
F_81 (rt2x00dev, queue) {
V_202 = F_88 ( V_6 , V_5 -> V_128 -> V_203 ) ;
if ( V_202 )
goto exit;
}
V_202 = F_88 ( V_5 -> V_204 , V_5 -> V_128 -> V_204 ) ;
if ( V_202 )
goto exit;
if ( F_2 ( V_205 , & V_5 -> V_16 ) ) {
V_202 = F_88 ( V_5 -> V_206 ,
V_5 -> V_128 -> V_206 ) ;
if ( V_202 )
goto exit;
}
V_202 = F_93 ( V_5 -> V_191 ) ;
if ( V_202 )
goto exit;
return 0 ;
exit:
ERROR ( V_5 , L_9 ) ;
F_95 ( V_5 ) ;
return V_202 ;
}
void F_95 ( struct V_4 * V_5 )
{
struct V_136 * V_6 ;
F_92 ( V_5 -> V_191 ) ;
F_87 (rt2x00dev, queue) {
F_96 ( V_6 -> V_171 ) ;
V_6 -> V_171 = NULL ;
}
}
static void F_97 ( struct V_4 * V_5 ,
struct V_136 * V_6 , enum V_207 V_131 )
{
F_98 ( & V_6 -> V_184 ) ;
F_99 ( & V_6 -> V_169 ) ;
V_6 -> V_5 = V_5 ;
V_6 -> V_131 = V_131 ;
V_6 -> V_98 = 0 ;
V_6 -> V_208 = 2 ;
V_6 -> V_209 = 5 ;
V_6 -> V_210 = 10 ;
}
int F_100 ( struct V_4 * V_5 )
{
struct V_136 * V_6 ;
enum V_207 V_131 ;
unsigned int V_211 =
! ! F_2 ( V_205 , & V_5 -> V_16 ) ;
V_5 -> V_212 = 2 + V_5 -> V_128 -> V_213 + V_211 ;
V_6 = F_90 ( V_5 -> V_212 , sizeof( * V_6 ) , V_199 ) ;
if ( ! V_6 ) {
ERROR ( V_5 , L_10 ) ;
return - V_159 ;
}
V_5 -> V_191 = V_6 ;
V_5 -> V_203 = & V_6 [ 1 ] ;
V_5 -> V_204 = & V_6 [ 1 + V_5 -> V_128 -> V_213 ] ;
V_5 -> V_206 = V_211 ? & V_6 [ 2 + V_5 -> V_128 -> V_213 ] : NULL ;
F_97 ( V_5 , V_5 -> V_191 , V_183 ) ;
V_131 = V_179 ;
F_81 (rt2x00dev, queue)
F_97 ( V_5 , V_6 , V_131 ++ ) ;
F_97 ( V_5 , V_5 -> V_204 , V_214 ) ;
if ( V_211 )
F_97 ( V_5 , V_5 -> V_206 , V_215 ) ;
return 0 ;
}
void F_101 ( struct V_4 * V_5 )
{
F_96 ( V_5 -> V_191 ) ;
V_5 -> V_191 = NULL ;
V_5 -> V_203 = NULL ;
V_5 -> V_204 = NULL ;
}
