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
T_2 V_19 ;
V_19 = F_7 ( V_6 -> V_20 , V_8 -> V_21 , V_8 -> V_22 ,
V_23 ) ;
if ( F_8 ( F_9 ( V_6 -> V_20 , V_19 ) ) ) {
F_10 ( V_8 ) ;
return NULL ;
}
V_10 -> V_19 = V_19 ;
V_10 -> V_24 |= V_25 ;
}
return V_8 ;
}
int F_11 ( struct V_2 * V_3 )
{
struct V_26 * V_20 = V_3 -> V_7 -> V_6 -> V_20 ;
struct V_9 * V_10 = F_6 ( V_3 -> V_8 ) ;
V_10 -> V_19 =
F_7 ( V_20 , V_3 -> V_8 -> V_21 , V_3 -> V_8 -> V_22 , V_27 ) ;
if ( F_8 ( F_9 ( V_20 , V_10 -> V_19 ) ) )
return - V_28 ;
V_10 -> V_24 |= V_29 ;
return 0 ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_26 * V_20 = V_3 -> V_7 -> V_6 -> V_20 ;
struct V_9 * V_10 = F_6 ( V_3 -> V_8 ) ;
if ( V_10 -> V_24 & V_25 ) {
F_13 ( V_20 , V_10 -> V_19 , V_3 -> V_8 -> V_22 ,
V_23 ) ;
V_10 -> V_24 &= ~ V_25 ;
} else if ( V_10 -> V_24 & V_29 ) {
F_13 ( V_20 , V_10 -> V_19 , V_3 -> V_8 -> V_22 ,
V_27 ) ;
V_10 -> V_24 &= ~ V_29 ;
}
}
void F_14 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 )
return;
F_12 ( V_3 ) ;
F_10 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
}
void F_15 ( struct V_1 * V_8 )
{
unsigned int V_30 = V_8 -> V_22 ;
unsigned int V_31 = F_16 ( V_8 , 0 ) ;
if ( ! V_31 )
return;
F_17 ( V_8 , V_31 ) ;
memmove ( V_8 -> V_21 , V_8 -> V_21 + V_31 , V_30 ) ;
F_18 ( V_8 , V_30 ) ;
}
void F_19 ( struct V_1 * V_8 , unsigned int V_32 )
{
unsigned int V_33 = V_8 -> V_22 - V_32 ;
unsigned int V_34 = F_16 ( V_8 , 0 ) ;
unsigned int V_35 = F_16 ( V_8 , V_32 ) ;
unsigned int V_36 = V_33 ? F_20 ( V_32 ) : 0 ;
if ( V_35 > V_34 )
V_34 += 4 ;
if ( ! V_34 )
return;
F_17 ( V_8 , V_34 ) ;
memmove ( V_8 -> V_21 , V_8 -> V_21 + V_34 , V_32 ) ;
if ( V_33 && V_35 )
memmove ( V_8 -> V_21 + V_32 + V_36 ,
V_8 -> V_21 + V_32 + V_36 + V_35 ,
V_33 ) ;
F_18 ( V_8 , V_32 + V_36 + V_33 ) ;
}
void F_21 ( struct V_1 * V_8 , unsigned int V_32 )
{
unsigned int V_36 = ( V_8 -> V_22 > V_32 ) ?
F_20 ( V_32 ) : 0 ;
if ( ! V_36 )
return;
memmove ( V_8 -> V_21 + V_36 , V_8 -> V_21 , V_32 ) ;
F_22 ( V_8 , V_36 ) ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_24 ( V_8 ) ;
struct V_41 * V_42 = (struct V_41 * ) V_8 -> V_21 ;
struct V_43 * V_44 = F_25 ( V_40 -> V_45 . V_46 ) ;
T_3 V_47 ;
if ( ! ( V_40 -> V_24 & V_48 ) )
return;
F_26 ( V_49 , & V_38 -> V_24 ) ;
if ( ! F_2 ( V_50 , & V_6 -> V_17 ) ) {
if ( F_2 ( V_51 , & V_6 -> V_24 ) )
F_27 ( V_49 , & V_38 -> V_24 ) ;
else
return;
}
if ( F_2 ( V_52 , & V_38 -> V_24 ) )
V_47 = F_28 ( 0x10 , & V_44 -> V_47 ) ;
else
V_47 = F_29 ( & V_44 -> V_47 ) ;
V_42 -> V_53 &= F_30 ( V_54 ) ;
V_42 -> V_53 |= F_30 ( V_47 ) ;
}
static void F_31 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_37 * V_38 ,
const struct V_55 * V_56 )
{
struct V_39 * V_40 = F_24 ( V_8 ) ;
struct V_57 * V_58 = & V_40 -> V_45 . V_59 [ 0 ] ;
unsigned int V_60 ;
unsigned int V_61 ;
unsigned int V_62 ;
if ( F_2 ( V_52 , & V_38 -> V_24 ) )
V_38 -> V_63 . V_64 . V_65 = V_66 ;
else
V_38 -> V_63 . V_64 . V_65 = V_67 ;
V_60 = V_8 -> V_22 + 4 ;
V_60 += F_32 ( V_6 , V_8 ) ;
V_38 -> V_63 . V_64 . signal = V_56 -> V_64 ;
V_38 -> V_63 . V_64 . V_68 = 0x04 ;
if ( V_56 -> V_24 & V_69 ) {
V_38 -> V_63 . V_64 . V_70 = ( V_60 >> 6 ) & 0x3f ;
V_38 -> V_63 . V_64 . V_71 = V_60 & 0x3f ;
} else {
V_62 = F_33 ( V_60 , V_56 -> V_72 ) ;
V_61 = F_34 ( V_60 , V_56 -> V_72 ) ;
if ( V_62 != 0 ) {
V_61 ++ ;
if ( V_56 -> V_72 == 110 && V_62 <= 30 )
V_38 -> V_63 . V_64 . V_68 |= 0x80 ;
}
V_38 -> V_63 . V_64 . V_70 = ( V_61 >> 8 ) & 0xff ;
V_38 -> V_63 . V_64 . V_71 = V_61 & 0xff ;
if ( V_58 -> V_24 & V_73 )
V_38 -> V_63 . V_64 . signal |= 0x08 ;
}
}
static void F_35 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_37 * V_38 ,
struct V_74 * V_75 ,
const struct V_55 * V_56 )
{
struct V_39 * V_40 = F_24 ( V_8 ) ;
struct V_57 * V_58 = & V_40 -> V_45 . V_59 [ 0 ] ;
struct V_41 * V_42 = (struct V_41 * ) V_8 -> V_21 ;
struct V_76 * V_77 = NULL ;
if ( V_75 ) {
V_38 -> V_63 . V_78 . V_79 =
V_75 -> V_80 . V_81 ;
V_77 = F_36 ( V_75 ) ;
V_38 -> V_63 . V_78 . V_82 = V_77 -> V_82 ;
}
if ( V_58 -> V_24 & V_83 ) {
V_38 -> V_63 . V_78 . V_84 = V_58 -> V_85 ;
if ( V_75 && V_38 -> V_63 . V_78 . V_84 > 7 &&
V_75 -> V_86 == V_87 )
F_26 ( V_88 , & V_38 -> V_24 ) ;
} else {
V_38 -> V_63 . V_78 . V_84 = F_37 ( V_56 -> V_84 ) ;
if ( V_58 -> V_24 & V_73 )
V_38 -> V_63 . V_78 . V_84 |= 0x08 ;
}
if ( F_2 ( V_89 , & V_6 -> V_24 ) ) {
if ( ! ( V_40 -> V_24 & V_90 ) )
V_38 -> V_63 . V_78 . V_91 = V_92 ;
else
V_38 -> V_63 . V_78 . V_91 = V_93 ;
return;
}
V_38 -> V_63 . V_78 . V_94 = 7 ;
if ( V_40 -> V_24 & V_95 )
V_38 -> V_63 . V_78 . V_96 = 1 ;
if ( V_40 -> V_24 & V_97 &&
! ( V_40 -> V_24 & V_98 ) )
F_26 ( V_99 , & V_38 -> V_24 ) ;
if ( V_58 -> V_24 & V_100 ||
V_58 -> V_24 & V_101 )
F_26 ( V_102 , & V_38 -> V_24 ) ;
if ( V_58 -> V_24 & V_103 )
F_26 ( V_104 , & V_38 -> V_24 ) ;
if ( F_38 ( V_42 -> V_105 ) &&
! F_39 ( V_42 -> V_105 ) )
V_38 -> V_63 . V_78 . V_91 = V_93 ;
else if ( ! ( V_40 -> V_24 & V_90 ) )
V_38 -> V_63 . V_78 . V_91 = V_92 ;
else
V_38 -> V_63 . V_78 . V_91 = V_106 ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_1 * V_8 ,
struct V_37 * V_38 ,
struct V_74 * V_75 )
{
struct V_39 * V_40 = F_24 ( V_8 ) ;
struct V_41 * V_42 = (struct V_41 * ) V_8 -> V_21 ;
struct V_57 * V_58 = & V_40 -> V_45 . V_59 [ 0 ] ;
struct V_107 * V_108 ;
const struct V_55 * V_56 = NULL ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_109 = V_8 -> V_22 ;
V_38 -> V_32 = F_41 ( V_8 ) ;
if ( ! ( V_40 -> V_24 & V_110 ) )
F_26 ( V_111 , & V_38 -> V_24 ) ;
if ( F_42 ( V_42 -> V_105 ) ||
F_43 ( V_42 -> V_105 ) ) {
F_26 ( V_112 , & V_38 -> V_24 ) ;
if ( F_42 ( V_42 -> V_105 ) )
F_26 ( V_113 , & V_38 -> V_24 ) ;
else
F_26 ( V_114 , & V_38 -> V_24 ) ;
if ( V_40 -> V_45 . V_115 >= 0 )
V_108 =
F_44 ( V_6 -> V_116 , V_40 ) ;
}
V_38 -> V_117 = V_40 -> V_45 . V_59 [ 0 ] . V_118 - 1 ;
if ( V_38 -> V_117 >= V_6 -> V_119 )
F_26 ( V_120 , & V_38 -> V_24 ) ;
if ( F_45 ( V_42 -> V_105 ) ) {
F_26 ( V_112 , & V_38 -> V_24 ) ;
F_26 ( V_121 , & V_38 -> V_24 ) ;
}
if ( V_40 -> V_24 & V_122 )
F_26 ( V_112 , & V_38 -> V_24 ) ;
if ( F_39 ( V_42 -> V_105 ) ||
F_46 ( V_42 -> V_105 ) )
F_26 ( V_123 , & V_38 -> V_24 ) ;
if ( ( V_40 -> V_24 & V_90 ) &&
! F_2 ( V_113 , & V_38 -> V_24 ) )
F_26 ( V_52 , & V_38 -> V_24 ) ;
if ( V_58 -> V_24 & V_124 )
V_38 -> V_125 = V_126 ;
else if ( V_58 -> V_24 & V_83 )
V_38 -> V_125 = V_127 ;
else {
V_108 = F_47 ( V_6 -> V_116 , V_40 ) ;
V_56 = F_48 ( V_108 -> V_128 ) ;
if ( V_56 -> V_24 & V_69 )
V_38 -> V_125 = V_129 ;
else
V_38 -> V_125 = V_130 ;
}
F_49 ( V_6 , V_8 , V_38 ) ;
F_23 ( V_6 , V_8 , V_38 ) ;
if ( F_2 ( V_131 , & V_6 -> V_17 ) )
F_35 ( V_6 , V_8 , V_38 ,
V_75 , V_56 ) ;
else
F_31 ( V_6 , V_8 , V_38 ,
V_56 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = V_3 -> V_7 -> V_6 ;
if ( F_8 ( V_6 -> V_132 -> V_133 -> V_134 &&
V_6 -> V_132 -> V_133 -> V_134 ( V_3 ) ) ) {
ERROR ( V_6 ,
L_1
L_2 ,
V_3 -> V_7 -> V_135 , V_136 ) ;
return - V_137 ;
}
F_17 ( V_3 -> V_8 , V_6 -> V_132 -> V_138 ) ;
memset ( V_3 -> V_8 -> V_21 , 0 , V_6 -> V_132 -> V_138 ) ;
if ( V_6 -> V_132 -> V_133 -> V_139 )
V_6 -> V_132 -> V_133 -> V_139 ( V_3 , V_38 ) ;
if ( F_2 ( V_18 , & V_6 -> V_17 ) &&
F_11 ( V_3 ) )
return - V_28 ;
return 0 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_140 * V_7 = V_3 -> V_7 ;
V_7 -> V_6 -> V_132 -> V_133 -> V_141 ( V_3 , V_38 ) ;
F_52 ( V_7 -> V_6 , V_142 , V_3 -> V_8 ) ;
}
static void F_53 ( struct V_140 * V_7 ,
struct V_37 * V_38 )
{
if ( F_54 ( V_7 ) ||
! F_2 ( V_112 , & V_38 -> V_24 ) )
V_7 -> V_6 -> V_132 -> V_133 -> V_143 ( V_7 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 -> V_6 ;
struct V_144 * V_145 = ( void * ) ( V_3 -> V_8 -> V_21 +
V_6 -> V_132 -> V_138 ) ;
struct V_146 * V_147 ;
if ( F_56 ( ! F_57 ( V_145 -> V_105 ) ) )
return;
V_147 = F_58 ( sizeof( * V_147 ) , V_148 ) ;
if ( ! V_147 )
return;
V_147 -> V_3 = V_3 ;
V_147 -> V_149 = 0 ;
memcpy ( V_147 -> V_150 , V_145 -> V_150 , sizeof( V_145 -> V_150 ) ) ;
memcpy ( V_147 -> V_151 , V_145 -> V_151 , sizeof( V_145 -> V_151 ) ) ;
V_147 -> V_45 = V_145 -> V_45 ;
V_147 -> V_152 = V_145 -> V_152 ;
F_59 ( & V_6 -> V_153 ) ;
F_60 ( & V_147 -> V_154 , & V_6 -> V_155 ) ;
F_61 ( & V_6 -> V_153 ) ;
}
int F_62 ( struct V_140 * V_7 , struct V_1 * V_8 ,
bool V_156 )
{
struct V_39 * V_40 ;
struct V_2 * V_3 ;
struct V_37 V_38 ;
struct V_9 * V_10 ;
T_4 V_157 , V_158 ;
int V_159 = 0 ;
F_40 ( V_7 -> V_6 , V_8 , & V_38 , NULL ) ;
V_40 = F_24 ( V_8 ) ;
V_157 = V_40 -> V_45 . V_59 [ 0 ] . V_85 ;
V_158 = V_40 -> V_45 . V_59 [ 0 ] . V_24 ;
V_10 = F_6 ( V_8 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_160 = V_157 ;
V_10 -> V_161 = V_158 ;
if ( V_156 )
V_10 -> V_24 |= V_162 ;
if ( F_2 ( V_163 , & V_38 . V_24 ) &&
! F_2 ( V_164 , & V_38 . V_24 ) ) {
if ( F_2 ( V_165 , & V_7 -> V_6 -> V_17 ) )
F_63 ( V_8 , & V_38 ) ;
else
F_64 ( V_8 , & V_38 ) ;
}
if ( F_2 ( V_166 , & V_7 -> V_6 -> V_17 ) )
F_19 ( V_8 , V_38 . V_32 ) ;
else if ( F_2 ( V_18 , & V_7 -> V_6 -> V_17 ) )
F_15 ( V_8 ) ;
F_65 ( & V_7 -> V_167 ) ;
if ( F_8 ( F_66 ( V_7 ) ) ) {
ERROR ( V_7 -> V_6 ,
L_3 , V_7 -> V_135 ) ;
V_159 = - V_168 ;
goto V_169;
}
V_3 = F_67 ( V_7 , V_170 ) ;
if ( F_8 ( F_68 ( V_171 ,
& V_3 -> V_24 ) ) ) {
ERROR ( V_7 -> V_6 ,
L_4
L_2 ,
V_7 -> V_135 , V_136 ) ;
V_159 = - V_137 ;
goto V_169;
}
V_10 -> V_3 = V_3 ;
V_3 -> V_8 = V_8 ;
if ( F_8 ( F_50 ( V_3 , & V_38 ) ) ) {
F_69 ( V_171 , & V_3 -> V_24 ) ;
V_3 -> V_8 = NULL ;
V_159 = - V_172 ;
goto V_169;
}
F_55 ( V_3 ) ;
F_70 ( V_173 , & V_3 -> V_24 ) ;
F_71 ( V_3 , V_170 ) ;
F_51 ( V_3 , & V_38 ) ;
F_53 ( V_7 , & V_38 ) ;
V_169:
F_72 ( & V_7 -> V_167 ) ;
return V_159 ;
}
int F_73 ( struct V_5 * V_6 ,
struct V_174 * V_46 )
{
struct V_43 * V_44 = F_25 ( V_46 ) ;
if ( F_8 ( ! V_44 -> V_175 ) )
return - V_168 ;
F_74 ( & V_44 -> V_176 ) ;
F_14 ( V_44 -> V_175 ) ;
if ( V_6 -> V_132 -> V_133 -> V_177 )
V_6 -> V_132 -> V_133 -> V_177 ( V_44 -> V_175 ) ;
F_75 ( & V_44 -> V_176 ) ;
return 0 ;
}
int F_76 ( struct V_5 * V_6 ,
struct V_174 * V_46 )
{
struct V_43 * V_44 = F_25 ( V_46 ) ;
struct V_9 * V_10 ;
struct V_37 V_38 ;
if ( F_8 ( ! V_44 -> V_175 ) )
return - V_168 ;
F_14 ( V_44 -> V_175 ) ;
V_44 -> V_175 -> V_8 = F_77 ( V_6 -> V_116 , V_46 ) ;
if ( ! V_44 -> V_175 -> V_8 )
return - V_28 ;
F_40 ( V_6 , V_44 -> V_175 -> V_8 , & V_38 , NULL ) ;
V_10 = F_6 ( V_44 -> V_175 -> V_8 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_3 = V_44 -> V_175 ;
V_6 -> V_132 -> V_133 -> V_178 ( V_44 -> V_175 , & V_38 ) ;
return 0 ;
}
int F_78 ( struct V_5 * V_6 ,
struct V_174 * V_46 )
{
struct V_43 * V_44 = F_25 ( V_46 ) ;
int V_159 ;
F_74 ( & V_44 -> V_176 ) ;
V_159 = F_76 ( V_6 , V_46 ) ;
F_75 ( & V_44 -> V_176 ) ;
return V_159 ;
}
bool F_79 ( struct V_140 * V_7 ,
enum V_179 V_180 ,
enum V_179 V_181 ,
bool (* F_80)( struct V_2 * V_3 ) )
{
unsigned long V_182 ;
unsigned int V_183 ;
unsigned int V_184 ;
unsigned int V_185 ;
if ( F_8 ( V_180 >= V_186 || V_181 >= V_186 ) ) {
ERROR ( V_7 -> V_6 ,
L_5 ,
V_180 , V_181 ) ;
return true ;
}
F_81 ( & V_7 -> V_187 , V_182 ) ;
V_183 = V_7 -> V_188 [ V_180 ] ;
V_184 = V_7 -> V_188 [ V_181 ] ;
F_82 ( & V_7 -> V_187 , V_182 ) ;
if ( V_183 < V_184 ) {
for ( V_185 = V_183 ; V_185 < V_184 ; V_185 ++ ) {
if ( F_80 ( & V_7 -> V_189 [ V_185 ] ) )
return true ;
}
} else {
for ( V_185 = V_183 ; V_185 < V_7 -> V_190 ; V_185 ++ ) {
if ( F_80 ( & V_7 -> V_189 [ V_185 ] ) )
return true ;
}
for ( V_185 = 0 ; V_185 < V_184 ; V_185 ++ ) {
if ( F_80 ( & V_7 -> V_189 [ V_185 ] ) )
return true ;
}
}
return false ;
}
struct V_2 * F_67 ( struct V_140 * V_7 ,
enum V_179 V_188 )
{
struct V_2 * V_3 ;
unsigned long V_182 ;
if ( F_8 ( V_188 >= V_186 ) ) {
ERROR ( V_7 -> V_6 ,
L_6 , V_188 ) ;
return NULL ;
}
F_81 ( & V_7 -> V_187 , V_182 ) ;
V_3 = & V_7 -> V_189 [ V_7 -> V_188 [ V_188 ] ] ;
F_82 ( & V_7 -> V_187 , V_182 ) ;
return V_3 ;
}
void F_71 ( struct V_2 * V_3 , enum V_179 V_188 )
{
struct V_140 * V_7 = V_3 -> V_7 ;
unsigned long V_182 ;
if ( F_8 ( V_188 >= V_186 ) ) {
ERROR ( V_7 -> V_6 ,
L_7 , V_188 ) ;
return;
}
F_81 ( & V_7 -> V_187 , V_182 ) ;
V_7 -> V_188 [ V_188 ] ++ ;
if ( V_7 -> V_188 [ V_188 ] >= V_7 -> V_190 )
V_7 -> V_188 [ V_188 ] = 0 ;
V_3 -> V_191 = V_192 ;
if ( V_188 == V_170 ) {
V_7 -> V_109 ++ ;
} else if ( V_188 == V_193 ) {
V_7 -> V_109 -- ;
V_7 -> V_118 ++ ;
}
F_82 ( & V_7 -> V_187 , V_182 ) ;
}
void F_83 ( struct V_140 * V_7 )
{
if ( ! F_2 ( V_194 , & V_7 -> V_6 -> V_24 ) ||
! F_2 ( V_195 , & V_7 -> V_24 ) ||
F_68 ( V_196 , & V_7 -> V_24 ) )
return;
switch ( V_7 -> V_135 ) {
case V_197 :
case V_198 :
case V_199 :
case V_200 :
F_84 ( V_7 -> V_6 -> V_116 , V_7 -> V_135 ) ;
break;
default:
break;
}
}
void F_85 ( struct V_140 * V_7 )
{
if ( ! F_2 ( V_194 , & V_7 -> V_6 -> V_24 ) ||
! F_2 ( V_195 , & V_7 -> V_24 ) ||
! F_86 ( V_196 , & V_7 -> V_24 ) )
return;
switch ( V_7 -> V_135 ) {
case V_197 :
case V_198 :
case V_199 :
case V_200 :
F_87 ( V_7 -> V_6 -> V_116 , V_7 -> V_135 ) ;
break;
case V_201 :
V_7 -> V_6 -> V_132 -> V_133 -> V_143 ( V_7 ) ;
default:
break;
}
}
void F_88 ( struct V_140 * V_7 )
{
F_74 ( & V_7 -> V_202 ) ;
if ( ! F_2 ( V_194 , & V_7 -> V_6 -> V_24 ) ||
F_68 ( V_195 , & V_7 -> V_24 ) ) {
F_75 ( & V_7 -> V_202 ) ;
return;
}
F_70 ( V_196 , & V_7 -> V_24 ) ;
V_7 -> V_6 -> V_132 -> V_133 -> V_203 ( V_7 ) ;
F_85 ( V_7 ) ;
F_75 ( & V_7 -> V_202 ) ;
}
void F_89 ( struct V_140 * V_7 )
{
F_74 ( & V_7 -> V_202 ) ;
if ( ! F_86 ( V_195 , & V_7 -> V_24 ) ) {
F_75 ( & V_7 -> V_202 ) ;
return;
}
F_83 ( V_7 ) ;
V_7 -> V_6 -> V_132 -> V_133 -> V_204 ( V_7 ) ;
F_75 ( & V_7 -> V_202 ) ;
}
void F_90 ( struct V_140 * V_7 , bool V_205 )
{
bool V_206 ;
bool V_207 =
( V_7 -> V_135 == V_197 ) ||
( V_7 -> V_135 == V_198 ) ||
( V_7 -> V_135 == V_199 ) ||
( V_7 -> V_135 == V_200 ) ;
F_74 ( & V_7 -> V_202 ) ;
V_206 = F_2 ( V_195 , & V_7 -> V_24 ) ;
if ( V_206 ) {
F_83 ( V_7 ) ;
if ( ! V_205 && V_207 )
V_7 -> V_6 -> V_132 -> V_133 -> V_143 ( V_7 ) ;
}
if ( F_56 ( V_7 -> V_6 -> V_132 -> V_133 -> V_208 ) )
V_7 -> V_6 -> V_132 -> V_133 -> V_208 ( V_7 , V_205 ) ;
if ( F_8 ( ! F_91 ( V_7 ) ) )
F_92 ( V_7 -> V_6 , L_8 , V_7 -> V_135 ) ;
if ( V_206 )
F_85 ( V_7 ) ;
F_75 ( & V_7 -> V_202 ) ;
}
void F_93 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
F_94 (rt2x00dev, queue)
F_88 ( V_7 ) ;
F_88 ( V_6 -> V_209 ) ;
}
void F_95 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
F_96 ( V_6 -> V_116 ) ;
F_94 (rt2x00dev, queue)
F_89 ( V_7 ) ;
F_89 ( V_6 -> V_209 ) ;
}
void F_97 ( struct V_5 * V_6 , bool V_205 )
{
struct V_140 * V_7 ;
F_94 (rt2x00dev, queue)
F_90 ( V_7 , V_205 ) ;
F_90 ( V_6 -> V_209 , V_205 ) ;
}
static void F_98 ( struct V_140 * V_7 )
{
unsigned long V_182 ;
unsigned int V_185 ;
F_81 ( & V_7 -> V_187 , V_182 ) ;
V_7 -> V_118 = 0 ;
V_7 -> V_109 = 0 ;
for ( V_185 = 0 ; V_185 < V_186 ; V_185 ++ )
V_7 -> V_188 [ V_185 ] = 0 ;
F_82 ( & V_7 -> V_187 , V_182 ) ;
}
void F_99 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
unsigned int V_185 ;
F_100 (rt2x00dev, queue) {
F_98 ( V_7 ) ;
for ( V_185 = 0 ; V_185 < V_7 -> V_190 ; V_185 ++ )
V_6 -> V_132 -> V_133 -> V_210 ( & V_7 -> V_189 [ V_185 ] ) ;
}
}
static int F_101 ( struct V_140 * V_7 ,
const struct V_211 * V_212 )
{
struct V_2 * V_189 ;
unsigned int V_213 ;
unsigned int V_185 ;
F_98 ( V_7 ) ;
V_7 -> V_190 = V_212 -> V_214 ;
V_7 -> V_215 = F_102 ( V_212 -> V_214 , 10 ) ;
V_7 -> V_14 = V_212 -> V_14 ;
V_7 -> V_15 = V_212 -> V_15 ;
V_213 = sizeof( * V_189 ) + V_212 -> V_216 ;
V_189 = F_103 ( V_7 -> V_190 , V_213 , V_217 ) ;
if ( ! V_189 )
return - V_28 ;
#define F_104 ( T_5 , T_6 , T_7 , T_8 , T_9 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_185 = 0 ; V_185 < V_7 -> V_190 ; V_185 ++ ) {
V_189 [ V_185 ] . V_24 = 0 ;
V_189 [ V_185 ] . V_7 = V_7 ;
V_189 [ V_185 ] . V_8 = NULL ;
V_189 [ V_185 ] . V_218 = V_185 ;
V_189 [ V_185 ] . V_219 =
F_104 ( V_189 , V_185 , V_7 -> V_190 ,
sizeof( * V_189 ) , V_212 -> V_216 ) ;
}
#undef F_104
V_7 -> V_189 = V_189 ;
return 0 ;
}
static void F_105 ( struct V_140 * V_7 )
{
unsigned int V_185 ;
if ( ! V_7 -> V_189 )
return;
for ( V_185 = 0 ; V_185 < V_7 -> V_190 ; V_185 ++ ) {
F_14 ( & V_7 -> V_189 [ V_185 ] ) ;
}
}
static int F_106 ( struct V_140 * V_7 )
{
unsigned int V_185 ;
struct V_1 * V_8 ;
for ( V_185 = 0 ; V_185 < V_7 -> V_190 ; V_185 ++ ) {
V_8 = F_1 ( & V_7 -> V_189 [ V_185 ] , V_217 ) ;
if ( ! V_8 )
return - V_28 ;
V_7 -> V_189 [ V_185 ] . V_8 = V_8 ;
}
return 0 ;
}
int F_107 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
int V_220 ;
V_220 = F_101 ( V_6 -> V_209 , V_6 -> V_132 -> V_209 ) ;
if ( V_220 )
goto exit;
F_94 (rt2x00dev, queue) {
V_220 = F_101 ( V_7 , V_6 -> V_132 -> V_221 ) ;
if ( V_220 )
goto exit;
}
V_220 = F_101 ( V_6 -> V_222 , V_6 -> V_132 -> V_222 ) ;
if ( V_220 )
goto exit;
if ( F_2 ( V_223 , & V_6 -> V_17 ) ) {
V_220 = F_101 ( V_6 -> V_224 ,
V_6 -> V_132 -> V_224 ) ;
if ( V_220 )
goto exit;
}
V_220 = F_106 ( V_6 -> V_209 ) ;
if ( V_220 )
goto exit;
return 0 ;
exit:
ERROR ( V_6 , L_9 ) ;
F_108 ( V_6 ) ;
return V_220 ;
}
void F_108 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
F_105 ( V_6 -> V_209 ) ;
F_100 (rt2x00dev, queue) {
F_109 ( V_7 -> V_189 ) ;
V_7 -> V_189 = NULL ;
}
}
static void F_110 ( struct V_5 * V_6 ,
struct V_140 * V_7 , enum V_225 V_135 )
{
F_111 ( & V_7 -> V_202 ) ;
F_112 ( & V_7 -> V_167 ) ;
F_112 ( & V_7 -> V_187 ) ;
V_7 -> V_6 = V_6 ;
V_7 -> V_135 = V_135 ;
V_7 -> V_91 = 0 ;
V_7 -> V_226 = 2 ;
V_7 -> V_227 = 5 ;
V_7 -> V_228 = 10 ;
}
int F_113 ( struct V_5 * V_6 )
{
struct V_140 * V_7 ;
enum V_225 V_135 ;
unsigned int V_229 =
! ! F_2 ( V_223 , & V_6 -> V_17 ) ;
V_6 -> V_230 = 2 + V_6 -> V_132 -> V_231 + V_229 ;
V_7 = F_103 ( V_6 -> V_230 , sizeof( * V_7 ) , V_217 ) ;
if ( ! V_7 ) {
ERROR ( V_6 , L_10 ) ;
return - V_28 ;
}
V_6 -> V_209 = V_7 ;
V_6 -> V_221 = & V_7 [ 1 ] ;
V_6 -> V_222 = & V_7 [ 1 + V_6 -> V_132 -> V_231 ] ;
V_6 -> V_224 = V_229 ? & V_7 [ 2 + V_6 -> V_132 -> V_231 ] : NULL ;
F_110 ( V_6 , V_6 -> V_209 , V_201 ) ;
V_135 = V_197 ;
F_94 (rt2x00dev, queue)
F_110 ( V_6 , V_7 , V_135 ++ ) ;
F_110 ( V_6 , V_6 -> V_222 , V_232 ) ;
if ( V_229 )
F_110 ( V_6 , V_6 -> V_224 , V_233 ) ;
return 0 ;
}
void F_114 ( struct V_5 * V_6 )
{
F_109 ( V_6 -> V_209 ) ;
V_6 -> V_209 = NULL ;
V_6 -> V_221 = NULL ;
V_6 -> V_222 = NULL ;
}
