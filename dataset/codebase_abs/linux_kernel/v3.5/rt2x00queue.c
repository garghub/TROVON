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
const struct V_54 * V_55 )
{
struct V_38 * V_39 = F_22 ( V_8 ) ;
struct V_56 * V_57 = & V_39 -> V_44 . V_58 [ 0 ] ;
struct V_40 * V_41 = (struct V_40 * ) V_8 -> V_21 ;
struct V_73 * V_74 = NULL ;
if ( V_39 -> V_44 . V_75 ) {
V_37 -> V_62 . V_76 . V_77 =
V_39 -> V_44 . V_75 -> V_78 . V_79 ;
V_74 = F_34 ( V_39 -> V_44 . V_75 ) ;
V_37 -> V_62 . V_76 . V_80 = V_74 -> V_80 ;
}
if ( V_57 -> V_24 & V_81 ) {
V_37 -> V_62 . V_76 . V_82 = V_57 -> V_83 ;
if ( V_39 -> V_44 . V_75 && V_37 -> V_62 . V_76 . V_82 > 7 &&
( ( V_39 -> V_44 . V_75 -> V_78 . V_84 &
V_85 ) >>
V_86 ) ==
V_87 )
F_24 ( V_88 , & V_37 -> V_24 ) ;
} else {
V_37 -> V_62 . V_76 . V_82 = F_35 ( V_55 -> V_82 ) ;
if ( V_57 -> V_24 & V_72 )
V_37 -> V_62 . V_76 . V_82 |= 0x08 ;
}
if ( F_2 ( V_89 , & V_6 -> V_24 ) ) {
if ( ! ( V_39 -> V_24 & V_90 ) )
V_37 -> V_62 . V_76 . V_91 = V_92 ;
else
V_37 -> V_62 . V_76 . V_91 = V_93 ;
return;
}
V_37 -> V_62 . V_76 . V_94 = 7 ;
if ( V_39 -> V_24 & V_95 )
V_37 -> V_62 . V_76 . V_96 = 1 ;
if ( V_39 -> V_24 & V_97 &&
! ( V_39 -> V_24 & V_98 ) )
F_24 ( V_99 , & V_37 -> V_24 ) ;
if ( V_57 -> V_24 & V_100 ||
V_57 -> V_24 & V_101 )
F_24 ( V_102 , & V_37 -> V_24 ) ;
if ( V_57 -> V_24 & V_103 )
F_24 ( V_104 , & V_37 -> V_24 ) ;
if ( F_36 ( V_41 -> V_105 ) &&
! F_37 ( V_41 -> V_105 ) )
V_37 -> V_62 . V_76 . V_91 = V_93 ;
else if ( ! ( V_39 -> V_24 & V_90 ) )
V_37 -> V_62 . V_76 . V_91 = V_92 ;
else
V_37 -> V_62 . V_76 . V_91 = V_106 ;
}
static void F_38 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = F_22 ( V_8 ) ;
struct V_40 * V_41 = (struct V_40 * ) V_8 -> V_21 ;
struct V_56 * V_57 = & V_39 -> V_44 . V_58 [ 0 ] ;
struct V_107 * V_108 ;
const struct V_54 * V_55 = NULL ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_109 = V_8 -> V_22 ;
V_37 -> V_31 = F_39 ( V_8 ) ;
if ( ! ( V_39 -> V_24 & V_110 ) )
F_24 ( V_111 , & V_37 -> V_24 ) ;
if ( F_40 ( V_41 -> V_105 ) ||
F_41 ( V_41 -> V_105 ) ) {
F_24 ( V_112 , & V_37 -> V_24 ) ;
if ( F_40 ( V_41 -> V_105 ) )
F_24 ( V_113 , & V_37 -> V_24 ) ;
else
F_24 ( V_114 , & V_37 -> V_24 ) ;
if ( V_39 -> V_44 . V_115 >= 0 )
V_108 =
F_42 ( V_6 -> V_116 , V_39 ) ;
}
V_37 -> V_117 = V_39 -> V_44 . V_58 [ 0 ] . V_118 - 1 ;
if ( V_37 -> V_117 >= V_6 -> V_119 )
F_24 ( V_120 , & V_37 -> V_24 ) ;
if ( F_43 ( V_41 -> V_105 ) ) {
F_24 ( V_112 , & V_37 -> V_24 ) ;
F_24 ( V_121 , & V_37 -> V_24 ) ;
}
if ( V_39 -> V_24 & V_122 )
F_24 ( V_112 , & V_37 -> V_24 ) ;
if ( F_37 ( V_41 -> V_105 ) ||
F_44 ( V_41 -> V_105 ) )
F_24 ( V_123 , & V_37 -> V_24 ) ;
if ( ( V_39 -> V_24 & V_90 ) &&
! F_2 ( V_113 , & V_37 -> V_24 ) )
F_24 ( V_51 , & V_37 -> V_24 ) ;
if ( V_57 -> V_24 & V_124 )
V_37 -> V_125 = V_126 ;
else if ( V_57 -> V_24 & V_81 )
V_37 -> V_125 = V_127 ;
else {
V_108 = F_45 ( V_6 -> V_116 , V_39 ) ;
V_55 = F_46 ( V_108 -> V_128 ) ;
if ( V_55 -> V_24 & V_68 )
V_37 -> V_125 = V_129 ;
else
V_37 -> V_125 = V_130 ;
}
F_47 ( V_6 , V_8 , V_37 ) ;
F_21 ( V_6 , V_8 , V_37 ) ;
if ( F_2 ( V_131 , & V_6 -> V_17 ) )
F_33 ( V_6 , V_8 , V_37 ,
V_55 ) ;
else
F_29 ( V_6 , V_8 , V_37 ,
V_55 ) ;
}
static int F_48 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_5 * V_6 = V_3 -> V_7 -> V_6 ;
if ( F_49 ( V_6 -> V_132 -> V_133 -> V_134 &&
V_6 -> V_132 -> V_133 -> V_134 ( V_3 ) ) ) {
ERROR ( V_6 ,
L_1
L_2 ,
V_3 -> V_7 -> V_135 , V_136 ) ;
return - V_137 ;
}
F_15 ( V_3 -> V_8 , V_6 -> V_132 -> V_138 ) ;
memset ( V_3 -> V_8 -> V_21 , 0 , V_6 -> V_132 -> V_138 ) ;
if ( V_6 -> V_132 -> V_133 -> V_139 )
V_6 -> V_132 -> V_133 -> V_139 ( V_3 , V_37 ) ;
if ( F_2 ( V_18 , & V_6 -> V_17 ) )
F_8 ( V_3 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_140 * V_7 = V_3 -> V_7 ;
V_7 -> V_6 -> V_132 -> V_133 -> V_141 ( V_3 , V_37 ) ;
F_51 ( V_7 -> V_6 , V_142 , V_3 -> V_8 ) ;
}
static void F_52 ( struct V_140 * V_7 ,
struct V_36 * V_37 )
{
if ( F_53 ( V_7 ) ||
! F_2 ( V_112 , & V_37 -> V_24 ) )
V_7 -> V_6 -> V_132 -> V_133 -> V_143 ( V_7 ) ;
}
int F_54 ( struct V_140 * V_7 , struct V_1 * V_8 ,
bool V_144 )
{
struct V_38 * V_39 ;
struct V_2 * V_3 ;
struct V_36 V_37 ;
struct V_9 * V_10 ;
T_3 V_145 , V_146 ;
int V_147 = 0 ;
F_38 ( V_7 -> V_6 , V_8 , & V_37 ) ;
V_39 = F_22 ( V_8 ) ;
V_145 = V_39 -> V_44 . V_58 [ 0 ] . V_83 ;
V_146 = V_39 -> V_44 . V_58 [ 0 ] . V_24 ;
V_10 = F_6 ( V_8 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_148 = V_145 ;
V_10 -> V_149 = V_146 ;
if ( V_144 )
V_10 -> V_24 |= V_150 ;
if ( F_2 ( V_151 , & V_37 . V_24 ) &&
! F_2 ( V_152 , & V_37 . V_24 ) ) {
if ( F_2 ( V_153 , & V_7 -> V_6 -> V_17 ) )
F_55 ( V_8 , & V_37 ) ;
else
F_56 ( V_8 , & V_37 ) ;
}
if ( F_2 ( V_154 , & V_7 -> V_6 -> V_17 ) )
F_17 ( V_8 , V_37 . V_31 ) ;
else if ( F_2 ( V_18 , & V_7 -> V_6 -> V_17 ) )
F_13 ( V_8 ) ;
F_57 ( & V_7 -> V_155 ) ;
if ( F_49 ( F_58 ( V_7 ) ) ) {
ERROR ( V_7 -> V_6 ,
L_3 , V_7 -> V_135 ) ;
V_147 = - V_156 ;
goto V_157;
}
V_3 = F_59 ( V_7 , V_158 ) ;
if ( F_49 ( F_60 ( V_159 ,
& V_3 -> V_24 ) ) ) {
ERROR ( V_7 -> V_6 ,
L_4
L_2 ,
V_7 -> V_135 , V_136 ) ;
V_147 = - V_137 ;
goto V_157;
}
V_10 -> V_3 = V_3 ;
V_3 -> V_8 = V_8 ;
if ( F_49 ( F_48 ( V_3 , & V_37 ) ) ) {
F_61 ( V_159 , & V_3 -> V_24 ) ;
V_3 -> V_8 = NULL ;
V_147 = - V_160 ;
goto V_157;
}
F_62 ( V_161 , & V_3 -> V_24 ) ;
F_63 ( V_3 , V_158 ) ;
F_50 ( V_3 , & V_37 ) ;
F_52 ( V_7 , & V_37 ) ;
V_157:
F_64 ( & V_7 -> V_155 ) ;
return V_147 ;
}
int F_65 ( struct V_5 * V_6 ,
struct V_162 * V_45 )
{
struct V_42 * V_43 = F_23 ( V_45 ) ;
if ( F_49 ( ! V_43 -> V_163 ) )
return - V_156 ;
F_66 ( & V_43 -> V_164 ) ;
F_11 ( V_43 -> V_163 ) ;
if ( V_6 -> V_132 -> V_133 -> V_165 )
V_6 -> V_132 -> V_133 -> V_165 ( V_43 -> V_163 ) ;
F_67 ( & V_43 -> V_164 ) ;
return 0 ;
}
int F_68 ( struct V_5 * V_6 ,
struct V_162 * V_45 )
{
struct V_42 * V_43 = F_23 ( V_45 ) ;
struct V_9 * V_10 ;
struct V_36 V_37 ;
if ( F_49 ( ! V_43 -> V_163 ) )
return - V_156 ;
F_11 ( V_43 -> V_163 ) ;
V_43 -> V_163 -> V_8 = F_69 ( V_6 -> V_116 , V_45 ) ;
if ( ! V_43 -> V_163 -> V_8 )
return - V_166 ;
F_38 ( V_6 , V_43 -> V_163 -> V_8 , & V_37 ) ;
V_10 = F_6 ( V_43 -> V_163 -> V_8 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_3 = V_43 -> V_163 ;
V_6 -> V_132 -> V_133 -> V_167 ( V_43 -> V_163 , & V_37 ) ;
return 0 ;
}
int F_70 ( struct V_5 * V_6 ,
struct V_162 * V_45 )
{
struct V_42 * V_43 = F_23 ( V_45 ) ;
int V_147 ;
F_66 ( & V_43 -> V_164 ) ;
V_147 = F_68 ( V_6 , V_45 ) ;
F_67 ( & V_43 -> V_164 ) ;
return V_147 ;
}
bool F_71 ( struct V_140 * V_7 ,
enum V_168 V_169 ,
enum V_168 V_170 ,
void * V_21 ,
bool (* F_72)( struct V_2 * V_3 ,
void * V_21 ) )
{
unsigned long V_171 ;
unsigned int V_172 ;
unsigned int V_173 ;
unsigned int V_174 ;
if ( F_49 ( V_169 >= V_175 || V_170 >= V_175 ) ) {
ERROR ( V_7 -> V_6 ,
L_5 ,
V_169 , V_170 ) ;
return true ;
}
F_73 ( & V_7 -> V_176 , V_171 ) ;
V_172 = V_7 -> V_177 [ V_169 ] ;
V_173 = V_7 -> V_177 [ V_170 ] ;
F_74 ( & V_7 -> V_176 , V_171 ) ;
if ( V_172 < V_173 ) {
for ( V_174 = V_172 ; V_174 < V_173 ; V_174 ++ ) {
if ( F_72 ( & V_7 -> V_178 [ V_174 ] , V_21 ) )
return true ;
}
} else {
for ( V_174 = V_172 ; V_174 < V_7 -> V_179 ; V_174 ++ ) {
if ( F_72 ( & V_7 -> V_178 [ V_174 ] , V_21 ) )
return true ;
}
for ( V_174 = 0 ; V_174 < V_173 ; V_174 ++ ) {
if ( F_72 ( & V_7 -> V_178 [ V_174 ] , V_21 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_59 ( struct V_140 * V_7 ,
enum V_168 V_177 )
{
struct V_2 * V_3 ;
unsigned long V_171 ;
if ( F_49 ( V_177 >= V_175 ) ) {
ERROR ( V_7 -> V_6 ,
L_6 , V_177 ) ;
return NULL ;
}
F_73 ( & V_7 -> V_176 , V_171 ) ;
V_3 = & V_7 -> V_178 [ V_7 -> V_177 [ V_177 ] ] ;
F_74 ( & V_7 -> V_176 , V_171 ) ;
return V_3 ;
}
void F_63 ( struct V_2 * V_3 , enum V_168 V_177 )
{
struct V_140 * V_7 = V_3 -> V_7 ;
unsigned long V_171 ;
if ( F_49 ( V_177 >= V_175 ) ) {
ERROR ( V_7 -> V_6 ,
L_7 , V_177 ) ;
return;
}
F_73 ( & V_7 -> V_176 , V_171 ) ;
V_7 -> V_177 [ V_177 ] ++ ;
if ( V_7 -> V_177 [ V_177 ] >= V_7 -> V_179 )
V_7 -> V_177 [ V_177 ] = 0 ;
V_3 -> V_180 = V_181 ;
if ( V_177 == V_158 ) {
V_7 -> V_109 ++ ;
} else if ( V_177 == V_182 ) {
V_7 -> V_109 -- ;
V_7 -> V_118 ++ ;
}
F_74 ( & V_7 -> V_176 , V_171 ) ;
}
void F_75 ( struct V_140 * V_7 )
{
if ( ! F_2 ( V_183 , & V_7 -> V_6 -> V_24 ) ||
! F_2 ( V_184 , & V_7 -> V_24 ) ||
F_60 ( V_185 , & V_7 -> V_24 ) )
return;
switch ( V_7 -> V_135 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
F_76 ( V_7 -> V_6 -> V_116 , V_7 -> V_135 ) ;
break;
default:
break;
}
}
void F_77 ( struct V_140 * V_7 )
{
if ( ! F_2 ( V_183 , & V_7 -> V_6 -> V_24 ) ||
! F_2 ( V_184 , & V_7 -> V_24 ) ||
! F_78 ( V_185 , & V_7 -> V_24 ) )
return;
switch ( V_7 -> V_135 ) {
case V_186 :
case V_187 :
case V_188 :
case V_189 :
F_79 ( V_7 -> V_6 -> V_116 , V_7 -> V_135 ) ;
break;
case V_190 :
V_7 -> V_6 -> V_132 -> V_133 -> V_143 ( V_7 ) ;
default:
break;
}
}
void F_80 ( struct V_140 * V_7 )
{
F_66 ( & V_7 -> V_191 ) ;
if ( ! F_2 ( V_183 , & V_7 -> V_6 -> V_24 ) ||
F_60 ( V_184 , & V_7 -> V_24 ) ) {
F_67 ( & V_7 -> V_191 ) ;
return;
}
F_62 ( V_185 , & V_7 -> V_24 ) ;
V_7 -> V_6 -> V_132 -> V_133 -> V_192 ( V_7 ) ;
F_77 ( V_7 ) ;
F_67 ( & V_7 -> V_191 ) ;
}
void F_81 ( struct V_140 * V_7 )
{
F_66 ( & V_7 -> V_191 ) ;
if ( ! F_78 ( V_184 , & V_7 -> V_24 ) ) {
F_67 ( & V_7 -> V_191 ) ;
return;
}
F_75 ( V_7 ) ;
V_7 -> V_6 -> V_132 -> V_133 -> V_193 ( V_7 ) ;
F_67 ( & V_7 -> V_191 ) ;
}
void F_82 ( struct V_140 * V_7 , bool V_194 )
{
bool V_195 ;
bool V_196 =
( V_7 -> V_135 == V_186 ) ||
( V_7 -> V_135 == V_187 ) ||
( V_7 -> V_135 == V_188 ) ||
( V_7 -> V_135 == V_189 ) ;
F_66 ( & V_7 -> V_191 ) ;
V_195 = F_2 ( V_184 , & V_7 -> V_24 ) ;
if ( V_195 ) {
F_75 ( V_7 ) ;
if ( ! V_194 && V_196 )
V_7 -> V_6 -> V_132 -> V_133 -> V_143 ( V_7 ) ;
}
if ( F_83 ( V_7 -> V_6 -> V_132 -> V_133 -> V_197 ) )
V_7 -> V_6 -> V_132 -> V_133 -> V_197 ( V_7 , V_194 ) ;
if ( F_49 ( ! F_84 ( V_7 ) ) )
F_85 ( V_7 -> V_6 , L_8 , V_7 -> V_135 ) ;
if ( V_195 )
F_77 ( V_7 ) ;
F_67 ( & V_7 -> V_191 ) ;
}
void F_86 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
F_87 (rt2x00dev, queue)
F_80 ( V_7 ) ;
F_80 ( V_6 -> V_198 ) ;
}
void F_88 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
F_89 ( V_6 -> V_116 ) ;
F_87 (rt2x00dev, queue)
F_81 ( V_7 ) ;
F_81 ( V_6 -> V_198 ) ;
}
void F_90 ( struct V_5 * V_6 , bool V_194 )
{
struct V_140 * V_7 ;
F_87 (rt2x00dev, queue)
F_82 ( V_7 , V_194 ) ;
F_82 ( V_6 -> V_198 , V_194 ) ;
}
static void F_91 ( struct V_140 * V_7 )
{
unsigned long V_171 ;
unsigned int V_174 ;
F_73 ( & V_7 -> V_176 , V_171 ) ;
V_7 -> V_118 = 0 ;
V_7 -> V_109 = 0 ;
for ( V_174 = 0 ; V_174 < V_175 ; V_174 ++ )
V_7 -> V_177 [ V_174 ] = 0 ;
F_74 ( & V_7 -> V_176 , V_171 ) ;
}
void F_92 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
unsigned int V_174 ;
F_93 (rt2x00dev, queue) {
F_91 ( V_7 ) ;
for ( V_174 = 0 ; V_174 < V_7 -> V_179 ; V_174 ++ )
V_6 -> V_132 -> V_133 -> V_199 ( & V_7 -> V_178 [ V_174 ] ) ;
}
}
static int F_94 ( struct V_140 * V_7 ,
const struct V_200 * V_201 )
{
struct V_2 * V_178 ;
unsigned int V_202 ;
unsigned int V_174 ;
F_91 ( V_7 ) ;
V_7 -> V_179 = V_201 -> V_203 ;
V_7 -> V_204 = F_95 ( V_201 -> V_203 , 10 ) ;
V_7 -> V_14 = V_201 -> V_14 ;
V_7 -> V_15 = V_201 -> V_15 ;
V_202 = sizeof( * V_178 ) + V_201 -> V_205 ;
V_178 = F_96 ( V_7 -> V_179 , V_202 , V_206 ) ;
if ( ! V_178 )
return - V_166 ;
#define F_97 ( T_4 , T_5 , T_6 , T_7 , T_8 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_174 = 0 ; V_174 < V_7 -> V_179 ; V_174 ++ ) {
V_178 [ V_174 ] . V_24 = 0 ;
V_178 [ V_174 ] . V_7 = V_7 ;
V_178 [ V_174 ] . V_8 = NULL ;
V_178 [ V_174 ] . V_207 = V_174 ;
V_178 [ V_174 ] . V_208 =
F_97 ( V_178 , V_174 , V_7 -> V_179 ,
sizeof( * V_178 ) , V_201 -> V_205 ) ;
}
#undef F_97
V_7 -> V_178 = V_178 ;
return 0 ;
}
static void F_98 ( struct V_140 * V_7 )
{
unsigned int V_174 ;
if ( ! V_7 -> V_178 )
return;
for ( V_174 = 0 ; V_174 < V_7 -> V_179 ; V_174 ++ ) {
F_11 ( & V_7 -> V_178 [ V_174 ] ) ;
}
}
static int F_99 ( struct V_140 * V_7 )
{
unsigned int V_174 ;
struct V_1 * V_8 ;
for ( V_174 = 0 ; V_174 < V_7 -> V_179 ; V_174 ++ ) {
V_8 = F_1 ( & V_7 -> V_178 [ V_174 ] , V_206 ) ;
if ( ! V_8 )
return - V_166 ;
V_7 -> V_178 [ V_174 ] . V_8 = V_8 ;
}
return 0 ;
}
int F_100 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
int V_209 ;
V_209 = F_94 ( V_6 -> V_198 , V_6 -> V_132 -> V_198 ) ;
if ( V_209 )
goto exit;
F_87 (rt2x00dev, queue) {
V_209 = F_94 ( V_7 , V_6 -> V_132 -> V_210 ) ;
if ( V_209 )
goto exit;
}
V_209 = F_94 ( V_6 -> V_211 , V_6 -> V_132 -> V_211 ) ;
if ( V_209 )
goto exit;
if ( F_2 ( V_212 , & V_6 -> V_17 ) ) {
V_209 = F_94 ( V_6 -> V_213 ,
V_6 -> V_132 -> V_213 ) ;
if ( V_209 )
goto exit;
}
V_209 = F_99 ( V_6 -> V_198 ) ;
if ( V_209 )
goto exit;
return 0 ;
exit:
ERROR ( V_6 , L_9 ) ;
F_101 ( V_6 ) ;
return V_209 ;
}
void F_101 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
F_98 ( V_6 -> V_198 ) ;
F_93 (rt2x00dev, queue) {
F_102 ( V_7 -> V_178 ) ;
V_7 -> V_178 = NULL ;
}
}
static void F_103 ( struct V_5 * V_6 ,
struct V_140 * V_7 , enum V_214 V_135 )
{
F_104 ( & V_7 -> V_191 ) ;
F_105 ( & V_7 -> V_155 ) ;
F_105 ( & V_7 -> V_176 ) ;
V_7 -> V_6 = V_6 ;
V_7 -> V_135 = V_135 ;
V_7 -> V_91 = 0 ;
V_7 -> V_215 = 2 ;
V_7 -> V_216 = 5 ;
V_7 -> V_217 = 10 ;
}
int F_106 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
enum V_214 V_135 ;
unsigned int V_218 =
! ! F_2 ( V_212 , & V_6 -> V_17 ) ;
V_6 -> V_219 = 2 + V_6 -> V_132 -> V_220 + V_218 ;
V_7 = F_96 ( V_6 -> V_219 , sizeof( * V_7 ) , V_206 ) ;
if ( ! V_7 ) {
ERROR ( V_6 , L_10 ) ;
return - V_166 ;
}
V_6 -> V_198 = V_7 ;
V_6 -> V_210 = & V_7 [ 1 ] ;
V_6 -> V_211 = & V_7 [ 1 + V_6 -> V_132 -> V_220 ] ;
V_6 -> V_213 = V_218 ? & V_7 [ 2 + V_6 -> V_132 -> V_220 ] : NULL ;
F_103 ( V_6 , V_6 -> V_198 , V_190 ) ;
V_135 = V_186 ;
F_87 (rt2x00dev, queue)
F_103 ( V_6 , V_7 , V_135 ++ ) ;
F_103 ( V_6 , V_6 -> V_211 , V_221 ) ;
if ( V_218 )
F_103 ( V_6 , V_6 -> V_213 , V_222 ) ;
return 0 ;
}
void F_107 ( struct V_5 * V_6 )
{
F_102 ( V_6 -> V_198 ) ;
V_6 -> V_198 = NULL ;
V_6 -> V_210 = NULL ;
V_6 -> V_211 = NULL ;
}
