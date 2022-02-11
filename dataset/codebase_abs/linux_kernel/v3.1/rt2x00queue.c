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
if ( V_38 -> V_43 . V_72 )
V_36 -> V_61 . V_73 . V_74 =
V_38 -> V_43 . V_72 -> V_75 . V_76 ;
V_36 -> V_61 . V_73 . V_77 = 7 ;
if ( V_38 -> V_23 & V_78 )
V_36 -> V_61 . V_73 . V_79 = 1 ;
if ( V_56 -> V_23 & V_80 ) {
V_36 -> V_61 . V_73 . V_81 = V_56 -> V_82 ;
if ( V_38 -> V_43 . V_72 && V_36 -> V_61 . V_73 . V_81 > 7 &&
( ( V_38 -> V_43 . V_72 -> V_75 . V_83 &
V_84 ) >>
V_85 ) ==
V_86 )
F_24 ( V_87 , & V_36 -> V_23 ) ;
} else {
V_36 -> V_61 . V_73 . V_81 = F_33 ( V_54 -> V_81 ) ;
if ( V_56 -> V_23 & V_71 )
V_36 -> V_61 . V_73 . V_81 |= 0x08 ;
}
if ( V_38 -> V_23 & V_88 &&
! ( V_38 -> V_23 & V_89 ) )
F_24 ( V_90 , & V_36 -> V_23 ) ;
if ( V_56 -> V_23 & V_91 ||
V_56 -> V_23 & V_92 )
F_24 ( V_93 , & V_36 -> V_23 ) ;
if ( V_56 -> V_23 & V_94 )
F_24 ( V_95 , & V_36 -> V_23 ) ;
if ( F_34 ( V_40 -> V_96 ) &&
! F_35 ( V_40 -> V_96 ) )
V_36 -> V_61 . V_73 . V_97 = V_98 ;
else if ( ! ( V_38 -> V_23 & V_99 ) )
V_36 -> V_61 . V_73 . V_97 = V_100 ;
else
V_36 -> V_61 . V_73 . V_97 = V_101 ;
}
static void F_36 ( struct V_4 * V_5 ,
struct V_1 * V_7 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = F_22 ( V_7 ) ;
struct V_39 * V_40 = (struct V_39 * ) V_7 -> V_20 ;
struct V_55 * V_56 = & V_38 -> V_43 . V_57 [ 0 ] ;
struct V_102 * V_103 ;
const struct V_53 * V_54 = NULL ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_104 = V_7 -> V_21 ;
V_36 -> V_30 = F_37 ( V_7 ) ;
if ( ! ( V_38 -> V_23 & V_105 ) )
F_24 ( V_106 , & V_36 -> V_23 ) ;
if ( F_38 ( V_40 -> V_96 ) ||
F_39 ( V_40 -> V_96 ) ) {
F_24 ( V_107 , & V_36 -> V_23 ) ;
if ( F_38 ( V_40 -> V_96 ) )
F_24 ( V_108 , & V_36 -> V_23 ) ;
else
F_24 ( V_109 , & V_36 -> V_23 ) ;
if ( V_38 -> V_43 . V_110 >= 0 )
V_103 =
F_40 ( V_5 -> V_111 , V_38 ) ;
}
V_36 -> V_112 = V_38 -> V_43 . V_57 [ 0 ] . V_113 - 1 ;
if ( V_36 -> V_112 >= V_5 -> V_114 )
F_24 ( V_115 , & V_36 -> V_23 ) ;
if ( F_41 ( V_40 -> V_96 ) ) {
F_24 ( V_107 , & V_36 -> V_23 ) ;
F_24 ( V_116 , & V_36 -> V_23 ) ;
}
if ( V_38 -> V_23 & V_117 )
F_24 ( V_107 , & V_36 -> V_23 ) ;
if ( F_35 ( V_40 -> V_96 ) ||
F_42 ( V_40 -> V_96 ) )
F_24 ( V_118 , & V_36 -> V_23 ) ;
if ( ( V_38 -> V_23 & V_99 ) &&
! F_2 ( V_108 , & V_36 -> V_23 ) )
F_24 ( V_49 , & V_36 -> V_23 ) ;
if ( V_56 -> V_23 & V_119 )
V_36 -> V_120 = V_121 ;
else if ( V_56 -> V_23 & V_80 )
V_36 -> V_120 = V_122 ;
else {
V_103 = F_43 ( V_5 -> V_111 , V_38 ) ;
V_54 = F_44 ( V_103 -> V_123 ) ;
if ( V_54 -> V_23 & V_67 )
V_36 -> V_120 = V_124 ;
else
V_36 -> V_120 = V_125 ;
}
F_45 ( V_5 , V_7 , V_36 ) ;
F_21 ( V_5 , V_7 , V_36 ) ;
if ( F_2 ( V_126 , & V_5 -> V_16 ) )
F_32 ( V_5 , V_7 , V_36 ,
V_54 ) ;
else
F_28 ( V_5 , V_7 , V_36 ,
V_54 ) ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_5 ;
if ( F_47 ( V_5 -> V_127 -> V_128 -> V_129 &&
V_5 -> V_127 -> V_128 -> V_129 ( V_3 ) ) ) {
ERROR ( V_5 ,
L_1
L_2 ,
V_3 -> V_6 -> V_130 , V_131 ) ;
return - V_132 ;
}
F_15 ( V_3 -> V_7 , V_5 -> V_127 -> V_133 ) ;
memset ( V_3 -> V_7 -> V_20 , 0 , V_5 -> V_127 -> V_133 ) ;
if ( V_5 -> V_127 -> V_128 -> V_134 )
V_5 -> V_127 -> V_128 -> V_134 ( V_3 , V_36 ) ;
if ( F_2 ( V_17 , & V_5 -> V_16 ) )
F_8 ( V_3 ) ;
return 0 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_35 * V_36 )
{
struct V_135 * V_6 = V_3 -> V_6 ;
V_6 -> V_5 -> V_127 -> V_128 -> V_136 ( V_3 , V_36 ) ;
F_49 ( V_6 -> V_5 , V_137 , V_3 -> V_7 ) ;
}
static void F_50 ( struct V_135 * V_6 ,
struct V_35 * V_36 )
{
if ( F_51 ( V_6 ) ||
! F_2 ( V_107 , & V_36 -> V_23 ) )
V_6 -> V_5 -> V_127 -> V_128 -> V_138 ( V_6 ) ;
}
int F_52 ( struct V_135 * V_6 , struct V_1 * V_7 ,
bool V_139 )
{
struct V_37 * V_38 ;
struct V_2 * V_3 ;
struct V_35 V_36 ;
struct V_8 * V_9 ;
T_1 V_140 , V_141 ;
int V_142 = 0 ;
F_36 ( V_6 -> V_5 , V_7 , & V_36 ) ;
V_38 = F_22 ( V_7 ) ;
V_140 = V_38 -> V_43 . V_57 [ 0 ] . V_82 ;
V_141 = V_38 -> V_43 . V_57 [ 0 ] . V_23 ;
V_9 = F_6 ( V_7 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_143 = V_140 ;
V_9 -> V_144 = V_141 ;
if ( V_139 )
V_9 -> V_23 |= V_145 ;
if ( F_2 ( V_146 , & V_36 . V_23 ) &&
! F_2 ( V_147 , & V_36 . V_23 ) ) {
if ( F_2 ( V_148 , & V_6 -> V_5 -> V_16 ) )
F_53 ( V_7 , & V_36 ) ;
else
F_54 ( V_7 , & V_36 ) ;
}
if ( F_2 ( V_149 , & V_6 -> V_5 -> V_16 ) )
F_17 ( V_7 , V_36 . V_30 ) ;
else if ( F_2 ( V_17 , & V_6 -> V_5 -> V_16 ) )
F_13 ( V_7 ) ;
F_25 ( & V_6 -> V_150 ) ;
if ( F_47 ( F_55 ( V_6 ) ) ) {
ERROR ( V_6 -> V_5 ,
L_3 , V_6 -> V_130 ) ;
V_142 = - V_151 ;
goto V_152;
}
V_3 = F_56 ( V_6 , V_153 ) ;
if ( F_47 ( F_57 ( V_154 ,
& V_3 -> V_23 ) ) ) {
ERROR ( V_6 -> V_5 ,
L_4
L_2 ,
V_6 -> V_130 , V_131 ) ;
V_142 = - V_132 ;
goto V_152;
}
V_9 -> V_3 = V_3 ;
V_3 -> V_7 = V_7 ;
if ( F_47 ( F_46 ( V_3 , & V_36 ) ) ) {
F_58 ( V_154 , & V_3 -> V_23 ) ;
V_3 -> V_7 = NULL ;
V_142 = - V_155 ;
goto V_152;
}
F_59 ( V_156 , & V_3 -> V_23 ) ;
F_60 ( V_3 , V_153 ) ;
F_48 ( V_3 , & V_36 ) ;
F_50 ( V_6 , & V_36 ) ;
V_152:
F_27 ( & V_6 -> V_150 ) ;
return V_142 ;
}
int F_61 ( struct V_4 * V_5 ,
struct V_157 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
if ( F_47 ( ! V_42 -> V_158 ) )
return - V_151 ;
F_62 ( & V_42 -> V_159 ) ;
F_11 ( V_42 -> V_158 ) ;
if ( V_5 -> V_127 -> V_128 -> V_160 )
V_5 -> V_127 -> V_128 -> V_160 ( V_42 -> V_158 ) ;
F_63 ( & V_42 -> V_159 ) ;
return 0 ;
}
int F_64 ( struct V_4 * V_5 ,
struct V_157 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
struct V_8 * V_9 ;
struct V_35 V_36 ;
if ( F_47 ( ! V_42 -> V_158 ) )
return - V_151 ;
F_11 ( V_42 -> V_158 ) ;
V_42 -> V_158 -> V_7 = F_65 ( V_5 -> V_111 , V_44 ) ;
if ( ! V_42 -> V_158 -> V_7 )
return - V_161 ;
F_36 ( V_5 , V_42 -> V_158 -> V_7 , & V_36 ) ;
V_9 = F_6 ( V_42 -> V_158 -> V_7 ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_3 = V_42 -> V_158 ;
V_5 -> V_127 -> V_128 -> V_162 ( V_42 -> V_158 , & V_36 ) ;
return 0 ;
}
int F_66 ( struct V_4 * V_5 ,
struct V_157 * V_44 )
{
struct V_41 * V_42 = F_23 ( V_44 ) ;
int V_142 ;
F_62 ( & V_42 -> V_159 ) ;
V_142 = F_64 ( V_5 , V_44 ) ;
F_63 ( & V_42 -> V_159 ) ;
return V_142 ;
}
bool F_67 ( struct V_135 * V_6 ,
enum V_163 V_164 ,
enum V_163 V_165 ,
void * V_20 ,
bool (* F_68)( struct V_2 * V_3 ,
void * V_20 ) )
{
unsigned long V_166 ;
unsigned int V_167 ;
unsigned int V_168 ;
unsigned int V_169 ;
if ( F_47 ( V_164 >= V_170 || V_165 >= V_170 ) ) {
ERROR ( V_6 -> V_5 ,
L_5 ,
V_164 , V_165 ) ;
return true ;
}
F_69 ( & V_6 -> V_171 , V_166 ) ;
V_167 = V_6 -> V_172 [ V_164 ] ;
V_168 = V_6 -> V_172 [ V_165 ] ;
F_70 ( & V_6 -> V_171 , V_166 ) ;
if ( V_167 < V_168 ) {
for ( V_169 = V_167 ; V_169 < V_168 ; V_169 ++ ) {
if ( F_68 ( & V_6 -> V_173 [ V_169 ] , V_20 ) )
return true ;
}
} else {
for ( V_169 = V_167 ; V_169 < V_6 -> V_174 ; V_169 ++ ) {
if ( F_68 ( & V_6 -> V_173 [ V_169 ] , V_20 ) )
return true ;
}
for ( V_169 = 0 ; V_169 < V_168 ; V_169 ++ ) {
if ( F_68 ( & V_6 -> V_173 [ V_169 ] , V_20 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_56 ( struct V_135 * V_6 ,
enum V_163 V_172 )
{
struct V_2 * V_3 ;
unsigned long V_166 ;
if ( F_47 ( V_172 >= V_170 ) ) {
ERROR ( V_6 -> V_5 ,
L_6 , V_172 ) ;
return NULL ;
}
F_69 ( & V_6 -> V_171 , V_166 ) ;
V_3 = & V_6 -> V_173 [ V_6 -> V_172 [ V_172 ] ] ;
F_70 ( & V_6 -> V_171 , V_166 ) ;
return V_3 ;
}
void F_60 ( struct V_2 * V_3 , enum V_163 V_172 )
{
struct V_135 * V_6 = V_3 -> V_6 ;
unsigned long V_166 ;
if ( F_47 ( V_172 >= V_170 ) ) {
ERROR ( V_6 -> V_5 ,
L_7 , V_172 ) ;
return;
}
F_69 ( & V_6 -> V_171 , V_166 ) ;
V_6 -> V_172 [ V_172 ] ++ ;
if ( V_6 -> V_172 [ V_172 ] >= V_6 -> V_174 )
V_6 -> V_172 [ V_172 ] = 0 ;
V_3 -> V_175 = V_176 ;
if ( V_172 == V_153 ) {
V_6 -> V_104 ++ ;
} else if ( V_172 == V_177 ) {
V_6 -> V_104 -- ;
V_6 -> V_113 ++ ;
}
F_70 ( & V_6 -> V_171 , V_166 ) ;
}
void F_71 ( struct V_135 * V_6 )
{
if ( ! F_2 ( V_178 , & V_6 -> V_5 -> V_23 ) ||
! F_2 ( V_179 , & V_6 -> V_23 ) ||
F_57 ( V_180 , & V_6 -> V_23 ) )
return;
switch ( V_6 -> V_130 ) {
case V_181 :
case V_182 :
case V_183 :
case V_184 :
F_72 ( V_6 -> V_5 -> V_111 , V_6 -> V_130 ) ;
break;
default:
break;
}
}
void F_73 ( struct V_135 * V_6 )
{
if ( ! F_2 ( V_178 , & V_6 -> V_5 -> V_23 ) ||
! F_2 ( V_179 , & V_6 -> V_23 ) ||
! F_74 ( V_180 , & V_6 -> V_23 ) )
return;
switch ( V_6 -> V_130 ) {
case V_181 :
case V_182 :
case V_183 :
case V_184 :
F_75 ( V_6 -> V_5 -> V_111 , V_6 -> V_130 ) ;
break;
case V_185 :
V_6 -> V_5 -> V_127 -> V_128 -> V_138 ( V_6 ) ;
default:
break;
}
}
void F_76 ( struct V_135 * V_6 )
{
F_62 ( & V_6 -> V_186 ) ;
if ( ! F_2 ( V_178 , & V_6 -> V_5 -> V_23 ) ||
F_57 ( V_179 , & V_6 -> V_23 ) ) {
F_63 ( & V_6 -> V_186 ) ;
return;
}
F_59 ( V_180 , & V_6 -> V_23 ) ;
V_6 -> V_5 -> V_127 -> V_128 -> V_187 ( V_6 ) ;
F_73 ( V_6 ) ;
F_63 ( & V_6 -> V_186 ) ;
}
void F_77 ( struct V_135 * V_6 )
{
F_62 ( & V_6 -> V_186 ) ;
if ( ! F_74 ( V_179 , & V_6 -> V_23 ) ) {
F_63 ( & V_6 -> V_186 ) ;
return;
}
F_71 ( V_6 ) ;
V_6 -> V_5 -> V_127 -> V_128 -> V_188 ( V_6 ) ;
F_63 ( & V_6 -> V_186 ) ;
}
void F_78 ( struct V_135 * V_6 , bool V_189 )
{
bool V_190 ;
bool V_191 =
( V_6 -> V_130 == V_181 ) ||
( V_6 -> V_130 == V_182 ) ||
( V_6 -> V_130 == V_183 ) ||
( V_6 -> V_130 == V_184 ) ;
F_62 ( & V_6 -> V_186 ) ;
V_190 = F_2 ( V_179 , & V_6 -> V_23 ) ;
if ( V_190 ) {
F_71 ( V_6 ) ;
if ( ! V_189 && V_191 )
V_6 -> V_5 -> V_127 -> V_128 -> V_138 ( V_6 ) ;
}
if ( F_79 ( V_6 -> V_5 -> V_127 -> V_128 -> V_192 ) )
V_6 -> V_5 -> V_127 -> V_128 -> V_192 ( V_6 , V_189 ) ;
if ( F_47 ( ! F_80 ( V_6 ) ) )
F_81 ( V_6 -> V_5 , L_8 , V_6 -> V_130 ) ;
if ( V_190 )
F_73 ( V_6 ) ;
F_63 ( & V_6 -> V_186 ) ;
}
void F_82 ( struct V_4 * V_5 )
{
struct V_135 * V_6 ;
F_83 (rt2x00dev, queue)
F_76 ( V_6 ) ;
F_76 ( V_5 -> V_193 ) ;
}
void F_84 ( struct V_4 * V_5 )
{
struct V_135 * V_6 ;
F_85 ( V_5 -> V_111 ) ;
F_83 (rt2x00dev, queue)
F_77 ( V_6 ) ;
F_77 ( V_5 -> V_193 ) ;
}
void F_86 ( struct V_4 * V_5 , bool V_189 )
{
struct V_135 * V_6 ;
F_83 (rt2x00dev, queue)
F_78 ( V_6 , V_189 ) ;
F_78 ( V_5 -> V_193 , V_189 ) ;
}
static void F_87 ( struct V_135 * V_6 )
{
unsigned long V_166 ;
unsigned int V_169 ;
F_69 ( & V_6 -> V_171 , V_166 ) ;
V_6 -> V_113 = 0 ;
V_6 -> V_104 = 0 ;
for ( V_169 = 0 ; V_169 < V_170 ; V_169 ++ )
V_6 -> V_172 [ V_169 ] = 0 ;
F_70 ( & V_6 -> V_171 , V_166 ) ;
}
void F_88 ( struct V_4 * V_5 )
{
struct V_135 * V_6 ;
unsigned int V_169 ;
F_89 (rt2x00dev, queue) {
F_87 ( V_6 ) ;
for ( V_169 = 0 ; V_169 < V_6 -> V_174 ; V_169 ++ )
V_5 -> V_127 -> V_128 -> V_194 ( & V_6 -> V_173 [ V_169 ] ) ;
}
}
static int F_90 ( struct V_135 * V_6 ,
const struct V_195 * V_196 )
{
struct V_2 * V_173 ;
unsigned int V_197 ;
unsigned int V_169 ;
F_87 ( V_6 ) ;
V_6 -> V_174 = V_196 -> V_198 ;
V_6 -> V_199 = F_91 ( V_196 -> V_198 , 10 ) ;
V_6 -> V_13 = V_196 -> V_13 ;
V_6 -> V_14 = V_196 -> V_14 ;
V_197 = sizeof( * V_173 ) + V_196 -> V_200 ;
V_173 = F_92 ( V_6 -> V_174 , V_197 , V_201 ) ;
if ( ! V_173 )
return - V_161 ;
#define F_93 ( T_2 , T_3 , T_4 , T_5 , T_6 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_169 = 0 ; V_169 < V_6 -> V_174 ; V_169 ++ ) {
V_173 [ V_169 ] . V_23 = 0 ;
V_173 [ V_169 ] . V_6 = V_6 ;
V_173 [ V_169 ] . V_7 = NULL ;
V_173 [ V_169 ] . V_202 = V_169 ;
V_173 [ V_169 ] . V_203 =
F_93 ( V_173 , V_169 , V_6 -> V_174 ,
sizeof( * V_173 ) , V_196 -> V_200 ) ;
}
#undef F_93
V_6 -> V_173 = V_173 ;
return 0 ;
}
static void F_94 ( struct V_135 * V_6 )
{
unsigned int V_169 ;
if ( ! V_6 -> V_173 )
return;
for ( V_169 = 0 ; V_169 < V_6 -> V_174 ; V_169 ++ ) {
F_11 ( & V_6 -> V_173 [ V_169 ] ) ;
}
}
static int F_95 ( struct V_135 * V_6 )
{
unsigned int V_169 ;
struct V_1 * V_7 ;
for ( V_169 = 0 ; V_169 < V_6 -> V_174 ; V_169 ++ ) {
V_7 = F_1 ( & V_6 -> V_173 [ V_169 ] ) ;
if ( ! V_7 )
return - V_161 ;
V_6 -> V_173 [ V_169 ] . V_7 = V_7 ;
}
return 0 ;
}
int F_96 ( struct V_4 * V_5 )
{
struct V_135 * V_6 ;
int V_204 ;
V_204 = F_90 ( V_5 -> V_193 , V_5 -> V_127 -> V_193 ) ;
if ( V_204 )
goto exit;
F_83 (rt2x00dev, queue) {
V_204 = F_90 ( V_6 , V_5 -> V_127 -> V_205 ) ;
if ( V_204 )
goto exit;
}
V_204 = F_90 ( V_5 -> V_206 , V_5 -> V_127 -> V_206 ) ;
if ( V_204 )
goto exit;
if ( F_2 ( V_207 , & V_5 -> V_16 ) ) {
V_204 = F_90 ( V_5 -> V_208 ,
V_5 -> V_127 -> V_208 ) ;
if ( V_204 )
goto exit;
}
V_204 = F_95 ( V_5 -> V_193 ) ;
if ( V_204 )
goto exit;
return 0 ;
exit:
ERROR ( V_5 , L_9 ) ;
F_97 ( V_5 ) ;
return V_204 ;
}
void F_97 ( struct V_4 * V_5 )
{
struct V_135 * V_6 ;
F_94 ( V_5 -> V_193 ) ;
F_89 (rt2x00dev, queue) {
F_98 ( V_6 -> V_173 ) ;
V_6 -> V_173 = NULL ;
}
}
static void F_99 ( struct V_4 * V_5 ,
struct V_135 * V_6 , enum V_209 V_130 )
{
F_100 ( & V_6 -> V_186 ) ;
F_101 ( & V_6 -> V_150 ) ;
F_101 ( & V_6 -> V_171 ) ;
V_6 -> V_5 = V_5 ;
V_6 -> V_130 = V_130 ;
V_6 -> V_97 = 0 ;
V_6 -> V_210 = 2 ;
V_6 -> V_211 = 5 ;
V_6 -> V_212 = 10 ;
}
int F_102 ( struct V_4 * V_5 )
{
struct V_135 * V_6 ;
enum V_209 V_130 ;
unsigned int V_213 =
! ! F_2 ( V_207 , & V_5 -> V_16 ) ;
V_5 -> V_214 = 2 + V_5 -> V_127 -> V_215 + V_213 ;
V_6 = F_92 ( V_5 -> V_214 , sizeof( * V_6 ) , V_201 ) ;
if ( ! V_6 ) {
ERROR ( V_5 , L_10 ) ;
return - V_161 ;
}
V_5 -> V_193 = V_6 ;
V_5 -> V_205 = & V_6 [ 1 ] ;
V_5 -> V_206 = & V_6 [ 1 + V_5 -> V_127 -> V_215 ] ;
V_5 -> V_208 = V_213 ? & V_6 [ 2 + V_5 -> V_127 -> V_215 ] : NULL ;
F_99 ( V_5 , V_5 -> V_193 , V_185 ) ;
V_130 = V_181 ;
F_83 (rt2x00dev, queue)
F_99 ( V_5 , V_6 , V_130 ++ ) ;
F_99 ( V_5 , V_5 -> V_206 , V_216 ) ;
if ( V_213 )
F_99 ( V_5 , V_5 -> V_208 , V_217 ) ;
return 0 ;
}
void F_103 ( struct V_4 * V_5 )
{
F_98 ( V_5 -> V_193 ) ;
V_5 -> V_193 = NULL ;
V_5 -> V_205 = NULL ;
V_5 -> V_206 = NULL ;
}
