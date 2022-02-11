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
if ( F_2 ( V_18 , & V_8 -> V_19 ) ) {
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
if ( F_2 ( V_20 , & V_8 -> V_19 ) ) {
T_2 V_21 ;
V_21 = F_7 ( V_8 -> V_22 , V_9 -> V_23 , V_9 -> V_24 ,
V_25 ) ;
if ( F_8 ( F_9 ( V_8 -> V_22 , V_21 ) ) ) {
F_10 ( V_9 ) ;
return NULL ;
}
V_11 -> V_21 = V_21 ;
V_11 -> V_26 |= V_27 ;
}
return V_9 ;
}
int F_11 ( struct V_2 * V_3 )
{
struct V_28 * V_22 = V_3 -> V_6 -> V_8 -> V_22 ;
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
V_11 -> V_21 =
F_7 ( V_22 , V_3 -> V_9 -> V_23 , V_3 -> V_9 -> V_24 , V_29 ) ;
if ( F_8 ( F_9 ( V_22 , V_11 -> V_21 ) ) )
return - V_30 ;
V_11 -> V_26 |= V_31 ;
return 0 ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_28 * V_22 = V_3 -> V_6 -> V_8 -> V_22 ;
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
if ( V_11 -> V_26 & V_27 ) {
F_13 ( V_22 , V_11 -> V_21 , V_3 -> V_9 -> V_24 ,
V_25 ) ;
V_11 -> V_26 &= ~ V_27 ;
} else if ( V_11 -> V_26 & V_31 ) {
F_13 ( V_22 , V_11 -> V_21 , V_3 -> V_9 -> V_24 ,
V_29 ) ;
V_11 -> V_26 &= ~ V_31 ;
}
}
void F_14 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_9 )
return;
F_12 ( V_3 ) ;
F_10 ( V_3 -> V_9 ) ;
V_3 -> V_9 = NULL ;
}
void F_15 ( struct V_1 * V_9 )
{
unsigned int V_32 = V_9 -> V_24 ;
unsigned int V_33 = F_16 ( V_9 , 0 ) ;
if ( ! V_33 )
return;
F_17 ( V_9 , V_33 ) ;
memmove ( V_9 -> V_23 , V_9 -> V_23 + V_33 , V_32 ) ;
F_18 ( V_9 , V_32 ) ;
}
void F_19 ( struct V_1 * V_9 , unsigned int V_34 )
{
unsigned int V_35 = V_9 -> V_24 - V_34 ;
unsigned int V_36 = F_16 ( V_9 , 0 ) ;
unsigned int V_37 = F_16 ( V_9 , V_34 ) ;
unsigned int V_38 = V_35 ? F_20 ( V_34 ) : 0 ;
if ( V_37 > V_36 )
V_36 += 4 ;
if ( ! V_36 )
return;
F_17 ( V_9 , V_36 ) ;
memmove ( V_9 -> V_23 , V_9 -> V_23 + V_36 , V_34 ) ;
if ( V_35 && V_37 )
memmove ( V_9 -> V_23 + V_34 + V_38 ,
V_9 -> V_23 + V_34 + V_38 + V_37 ,
V_35 ) ;
F_18 ( V_9 , V_34 + V_38 + V_35 ) ;
}
void F_21 ( struct V_1 * V_9 , unsigned int V_34 )
{
unsigned int V_38 = ( V_9 -> V_24 > V_34 ) ?
F_20 ( V_34 ) : 0 ;
if ( ! V_38 )
return;
memmove ( V_9 -> V_23 + V_38 , V_9 -> V_23 , V_34 ) ;
F_22 ( V_9 , V_38 ) ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_24 ( V_9 ) ;
struct V_43 * V_44 = (struct V_43 * ) V_9 -> V_23 ;
struct V_45 * V_46 = F_25 ( V_42 -> V_47 . V_48 ) ;
T_3 V_49 ;
if ( ! ( V_42 -> V_26 & V_50 ) )
return;
F_26 ( V_51 , & V_40 -> V_26 ) ;
if ( ! F_2 ( V_52 , & V_8 -> V_19 ) ) {
if ( F_2 ( V_53 , & V_8 -> V_26 ) )
F_27 ( V_51 , & V_40 -> V_26 ) ;
else
return;
}
if ( F_2 ( V_54 , & V_40 -> V_26 ) )
V_49 = F_28 ( 0x10 , & V_46 -> V_49 ) ;
else
V_49 = F_29 ( & V_46 -> V_49 ) ;
V_44 -> V_55 &= F_30 ( V_56 ) ;
V_44 -> V_55 |= F_30 ( V_49 ) ;
}
static void F_31 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_39 * V_40 ,
const struct V_57 * V_58 )
{
struct V_41 * V_42 = F_24 ( V_9 ) ;
struct V_59 * V_60 = & V_42 -> V_47 . V_61 [ 0 ] ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned int V_64 ;
if ( F_2 ( V_54 , & V_40 -> V_26 ) )
V_40 -> V_65 . V_66 . V_67 = V_68 ;
else
V_40 -> V_65 . V_66 . V_67 = V_69 ;
V_62 = V_9 -> V_24 + 4 ;
V_62 += F_32 ( V_8 , V_9 ) ;
V_40 -> V_65 . V_66 . signal = V_58 -> V_66 ;
V_40 -> V_65 . V_66 . V_70 = 0x04 ;
if ( V_58 -> V_26 & V_71 ) {
V_40 -> V_65 . V_66 . V_72 = ( V_62 >> 6 ) & 0x3f ;
V_40 -> V_65 . V_66 . V_73 = V_62 & 0x3f ;
} else {
V_64 = F_33 ( V_62 , V_58 -> V_74 ) ;
V_63 = F_34 ( V_62 , V_58 -> V_74 ) ;
if ( V_64 != 0 ) {
V_63 ++ ;
if ( V_58 -> V_74 == 110 && V_64 <= 30 )
V_40 -> V_65 . V_66 . V_70 |= 0x80 ;
}
V_40 -> V_65 . V_66 . V_72 = ( V_63 >> 8 ) & 0xff ;
V_40 -> V_65 . V_66 . V_73 = V_63 & 0xff ;
if ( V_60 -> V_26 & V_75 )
V_40 -> V_65 . V_66 . signal |= 0x08 ;
}
}
static void F_35 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_39 * V_40 ,
struct V_76 * V_77 ,
const struct V_57 * V_58 )
{
struct V_41 * V_42 = F_24 ( V_9 ) ;
struct V_59 * V_60 = & V_42 -> V_47 . V_61 [ 0 ] ;
struct V_43 * V_44 = (struct V_43 * ) V_9 -> V_23 ;
struct V_78 * V_79 = NULL ;
if ( V_77 ) {
V_40 -> V_65 . V_80 . V_81 =
V_77 -> V_82 . V_83 ;
V_79 = F_36 ( V_77 ) ;
V_40 -> V_65 . V_80 . V_84 = V_79 -> V_84 ;
}
if ( V_60 -> V_26 & V_85 ) {
V_40 -> V_65 . V_80 . V_86 = V_60 -> V_87 ;
if ( V_77 && V_40 -> V_65 . V_80 . V_86 > 7 &&
V_77 -> V_88 == V_89 )
F_26 ( V_90 , & V_40 -> V_26 ) ;
} else {
V_40 -> V_65 . V_80 . V_86 = F_37 ( V_58 -> V_86 ) ;
if ( V_60 -> V_26 & V_75 )
V_40 -> V_65 . V_80 . V_86 |= 0x08 ;
}
if ( F_2 ( V_91 , & V_8 -> V_26 ) ) {
if ( ! ( V_42 -> V_26 & V_92 ) )
V_40 -> V_65 . V_80 . V_93 = V_94 ;
else
V_40 -> V_65 . V_80 . V_93 = V_95 ;
return;
}
V_40 -> V_65 . V_80 . V_96 = 7 ;
if ( V_42 -> V_26 & V_97 )
V_40 -> V_65 . V_80 . V_98 = 1 ;
if ( V_42 -> V_26 & V_99 &&
! ( V_42 -> V_26 & V_100 ) )
F_26 ( V_101 , & V_40 -> V_26 ) ;
if ( V_60 -> V_26 & V_102 ||
V_60 -> V_26 & V_103 )
F_26 ( V_104 , & V_40 -> V_26 ) ;
if ( V_60 -> V_26 & V_105 )
F_26 ( V_106 , & V_40 -> V_26 ) ;
if ( F_38 ( V_44 -> V_107 ) &&
! F_39 ( V_44 -> V_107 ) )
V_40 -> V_65 . V_80 . V_93 = V_95 ;
else if ( ! ( V_42 -> V_26 & V_92 ) )
V_40 -> V_65 . V_80 . V_93 = V_94 ;
else
V_40 -> V_65 . V_80 . V_93 = V_108 ;
}
static void F_40 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_39 * V_40 ,
struct V_76 * V_77 )
{
struct V_41 * V_42 = F_24 ( V_9 ) ;
struct V_43 * V_44 = (struct V_43 * ) V_9 -> V_23 ;
struct V_59 * V_60 = & V_42 -> V_47 . V_61 [ 0 ] ;
struct V_109 * V_110 ;
const struct V_57 * V_58 = NULL ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> V_111 = V_9 -> V_24 ;
V_40 -> V_34 = F_41 ( V_9 ) ;
if ( ! ( V_42 -> V_26 & V_112 ) )
F_26 ( V_113 , & V_40 -> V_26 ) ;
if ( F_42 ( V_44 -> V_107 ) ||
F_43 ( V_44 -> V_107 ) ) {
F_26 ( V_114 , & V_40 -> V_26 ) ;
if ( F_42 ( V_44 -> V_107 ) )
F_26 ( V_115 , & V_40 -> V_26 ) ;
else
F_26 ( V_116 , & V_40 -> V_26 ) ;
if ( V_42 -> V_47 . V_117 >= 0 )
V_110 =
F_44 ( V_8 -> V_118 , V_42 ) ;
}
V_40 -> V_119 = V_42 -> V_47 . V_61 [ 0 ] . V_120 - 1 ;
if ( V_40 -> V_119 >= V_8 -> V_121 )
F_26 ( V_122 , & V_40 -> V_26 ) ;
if ( F_45 ( V_44 -> V_107 ) ) {
F_26 ( V_114 , & V_40 -> V_26 ) ;
F_26 ( V_123 , & V_40 -> V_26 ) ;
}
if ( V_42 -> V_26 & V_124 )
F_26 ( V_114 , & V_40 -> V_26 ) ;
if ( F_39 ( V_44 -> V_107 ) ||
F_46 ( V_44 -> V_107 ) )
F_26 ( V_125 , & V_40 -> V_26 ) ;
if ( ( V_42 -> V_26 & V_92 ) &&
! F_2 ( V_115 , & V_40 -> V_26 ) )
F_26 ( V_54 , & V_40 -> V_26 ) ;
if ( V_60 -> V_26 & V_126 )
V_40 -> V_127 = V_128 ;
else if ( V_60 -> V_26 & V_85 )
V_40 -> V_127 = V_129 ;
else {
V_110 = F_47 ( V_8 -> V_118 , V_42 ) ;
V_58 = F_48 ( V_110 -> V_130 ) ;
if ( V_58 -> V_26 & V_71 )
V_40 -> V_127 = V_131 ;
else
V_40 -> V_127 = V_132 ;
}
F_49 ( V_8 , V_9 , V_40 ) ;
F_23 ( V_8 , V_9 , V_40 ) ;
if ( F_2 ( V_133 , & V_8 -> V_19 ) )
F_35 ( V_8 , V_9 , V_40 ,
V_77 , V_58 ) ;
else
F_31 ( V_8 , V_9 , V_40 ,
V_58 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_8 ;
if ( F_8 ( V_8 -> V_134 -> V_135 -> V_136 &&
V_8 -> V_134 -> V_135 -> V_136 ( V_3 ) ) ) {
F_51 ( V_8 ,
L_1
L_2 ,
V_3 -> V_6 -> V_137 , V_138 ) ;
return - V_139 ;
}
F_17 ( V_3 -> V_9 , V_8 -> V_140 ) ;
memset ( V_3 -> V_9 -> V_23 , 0 , V_8 -> V_140 ) ;
if ( V_8 -> V_134 -> V_135 -> V_141 )
V_8 -> V_134 -> V_135 -> V_141 ( V_3 , V_40 ) ;
if ( F_2 ( V_20 , & V_8 -> V_19 ) &&
F_11 ( V_3 ) )
return - V_30 ;
return 0 ;
}
static void F_52 ( struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_8 -> V_134 -> V_135 -> V_142 ( V_3 , V_40 ) ;
F_53 ( V_6 -> V_8 , V_143 , V_3 -> V_9 ) ;
}
static void F_54 ( struct V_5 * V_6 ,
struct V_39 * V_40 )
{
if ( F_55 ( V_6 ) ||
! F_2 ( V_114 , & V_40 -> V_26 ) )
V_6 -> V_8 -> V_134 -> V_135 -> V_144 ( V_6 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_8 ;
struct V_145 * V_146 = ( void * ) ( V_3 -> V_9 -> V_23 +
V_8 -> V_140 ) ;
struct V_147 * V_148 ;
if ( F_57 ( ! F_58 ( V_146 -> V_107 ) ) )
return;
V_148 = F_59 ( sizeof( * V_148 ) , V_149 ) ;
if ( ! V_148 )
return;
V_148 -> V_3 = V_3 ;
V_148 -> V_150 = 0 ;
memcpy ( V_148 -> V_151 , V_146 -> V_151 , sizeof( V_146 -> V_151 ) ) ;
memcpy ( V_148 -> V_152 , V_146 -> V_152 , sizeof( V_146 -> V_152 ) ) ;
V_148 -> V_47 = V_146 -> V_47 ;
V_148 -> V_153 = V_146 -> V_153 ;
F_60 ( & V_8 -> V_154 ) ;
F_61 ( & V_148 -> V_155 , & V_8 -> V_156 ) ;
F_62 ( & V_8 -> V_154 ) ;
}
int F_63 ( struct V_5 * V_6 , struct V_1 * V_9 ,
bool V_157 )
{
struct V_41 * V_42 ;
struct V_2 * V_3 ;
struct V_39 V_40 ;
struct V_10 * V_11 ;
T_4 V_158 , V_159 ;
int V_160 = 0 ;
F_40 ( V_6 -> V_8 , V_9 , & V_40 , NULL ) ;
V_42 = F_24 ( V_9 ) ;
V_158 = V_42 -> V_47 . V_61 [ 0 ] . V_87 ;
V_159 = V_42 -> V_47 . V_61 [ 0 ] . V_26 ;
V_11 = F_6 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_161 = V_158 ;
V_11 -> V_162 = V_159 ;
if ( V_157 )
V_11 -> V_26 |= V_163 ;
if ( F_2 ( V_164 , & V_40 . V_26 ) &&
! F_2 ( V_165 , & V_40 . V_26 ) ) {
if ( F_2 ( V_166 , & V_6 -> V_8 -> V_19 ) )
F_64 ( V_9 , & V_40 ) ;
else
F_65 ( V_9 , & V_40 ) ;
}
if ( F_2 ( V_167 , & V_6 -> V_8 -> V_19 ) )
F_19 ( V_9 , V_40 . V_34 ) ;
else if ( F_2 ( V_20 , & V_6 -> V_8 -> V_19 ) )
F_15 ( V_9 ) ;
F_66 ( & V_6 -> V_168 ) ;
if ( F_8 ( F_67 ( V_6 ) ) ) {
F_51 ( V_6 -> V_8 , L_3 ,
V_6 -> V_137 ) ;
V_160 = - V_169 ;
goto V_170;
}
V_3 = F_68 ( V_6 , V_171 ) ;
if ( F_8 ( F_69 ( V_172 ,
& V_3 -> V_26 ) ) ) {
F_51 ( V_6 -> V_8 ,
L_4
L_2 ,
V_6 -> V_137 , V_138 ) ;
V_160 = - V_139 ;
goto V_170;
}
V_11 -> V_3 = V_3 ;
V_3 -> V_9 = V_9 ;
if ( F_8 ( F_50 ( V_3 , & V_40 ) ) ) {
F_70 ( V_172 , & V_3 -> V_26 ) ;
V_3 -> V_9 = NULL ;
V_160 = - V_173 ;
goto V_170;
}
F_56 ( V_3 ) ;
F_71 ( V_174 , & V_3 -> V_26 ) ;
F_72 ( V_3 , V_171 ) ;
F_52 ( V_3 , & V_40 ) ;
F_54 ( V_6 , & V_40 ) ;
V_170:
F_73 ( & V_6 -> V_168 ) ;
return V_160 ;
}
int F_74 ( struct V_7 * V_8 ,
struct V_175 * V_48 )
{
struct V_45 * V_46 = F_25 ( V_48 ) ;
if ( F_8 ( ! V_46 -> V_176 ) )
return - V_169 ;
F_75 ( & V_46 -> V_177 ) ;
F_14 ( V_46 -> V_176 ) ;
if ( V_8 -> V_134 -> V_135 -> V_178 )
V_8 -> V_134 -> V_135 -> V_178 ( V_46 -> V_176 ) ;
F_76 ( & V_46 -> V_177 ) ;
return 0 ;
}
int F_77 ( struct V_7 * V_8 ,
struct V_175 * V_48 )
{
struct V_45 * V_46 = F_25 ( V_48 ) ;
struct V_10 * V_11 ;
struct V_39 V_40 ;
if ( F_8 ( ! V_46 -> V_176 ) )
return - V_169 ;
F_14 ( V_46 -> V_176 ) ;
V_46 -> V_176 -> V_9 = F_78 ( V_8 -> V_118 , V_48 ) ;
if ( ! V_46 -> V_176 -> V_9 )
return - V_30 ;
F_40 ( V_8 , V_46 -> V_176 -> V_9 , & V_40 , NULL ) ;
V_11 = F_6 ( V_46 -> V_176 -> V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_3 = V_46 -> V_176 ;
V_8 -> V_134 -> V_135 -> V_179 ( V_46 -> V_176 , & V_40 ) ;
return 0 ;
}
int F_79 ( struct V_7 * V_8 ,
struct V_175 * V_48 )
{
struct V_45 * V_46 = F_25 ( V_48 ) ;
int V_160 ;
F_75 ( & V_46 -> V_177 ) ;
V_160 = F_77 ( V_8 , V_48 ) ;
F_76 ( & V_46 -> V_177 ) ;
return V_160 ;
}
bool F_80 ( struct V_5 * V_6 ,
enum V_180 V_181 ,
enum V_180 V_182 ,
void * V_23 ,
bool (* F_81)( struct V_2 * V_3 ,
void * V_23 ) )
{
unsigned long V_183 ;
unsigned int V_184 ;
unsigned int V_185 ;
unsigned int V_186 ;
if ( F_8 ( V_181 >= V_187 || V_182 >= V_187 ) ) {
F_51 ( V_6 -> V_8 ,
L_5 ,
V_181 , V_182 ) ;
return true ;
}
F_82 ( & V_6 -> V_188 , V_183 ) ;
V_184 = V_6 -> V_189 [ V_181 ] ;
V_185 = V_6 -> V_189 [ V_182 ] ;
F_83 ( & V_6 -> V_188 , V_183 ) ;
if ( V_184 < V_185 ) {
for ( V_186 = V_184 ; V_186 < V_185 ; V_186 ++ ) {
if ( F_81 ( & V_6 -> V_190 [ V_186 ] , V_23 ) )
return true ;
}
} else {
for ( V_186 = V_184 ; V_186 < V_6 -> V_191 ; V_186 ++ ) {
if ( F_81 ( & V_6 -> V_190 [ V_186 ] , V_23 ) )
return true ;
}
for ( V_186 = 0 ; V_186 < V_185 ; V_186 ++ ) {
if ( F_81 ( & V_6 -> V_190 [ V_186 ] , V_23 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_68 ( struct V_5 * V_6 ,
enum V_180 V_189 )
{
struct V_2 * V_3 ;
unsigned long V_183 ;
if ( F_8 ( V_189 >= V_187 ) ) {
F_51 ( V_6 -> V_8 , L_6 ,
V_189 ) ;
return NULL ;
}
F_82 ( & V_6 -> V_188 , V_183 ) ;
V_3 = & V_6 -> V_190 [ V_6 -> V_189 [ V_189 ] ] ;
F_83 ( & V_6 -> V_188 , V_183 ) ;
return V_3 ;
}
void F_72 ( struct V_2 * V_3 , enum V_180 V_189 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_183 ;
if ( F_8 ( V_189 >= V_187 ) ) {
F_51 ( V_6 -> V_8 ,
L_7 , V_189 ) ;
return;
}
F_82 ( & V_6 -> V_188 , V_183 ) ;
V_6 -> V_189 [ V_189 ] ++ ;
if ( V_6 -> V_189 [ V_189 ] >= V_6 -> V_191 )
V_6 -> V_189 [ V_189 ] = 0 ;
V_3 -> V_192 = V_193 ;
if ( V_189 == V_171 ) {
V_6 -> V_111 ++ ;
} else if ( V_189 == V_194 ) {
V_6 -> V_111 -- ;
V_6 -> V_120 ++ ;
}
F_83 ( & V_6 -> V_188 , V_183 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_137 ) {
case V_195 :
case V_196 :
case V_197 :
case V_198 :
F_85 ( V_6 -> V_8 -> V_118 , V_6 -> V_137 ) ;
break;
default:
break;
}
}
void F_86 ( struct V_5 * V_6 )
{
if ( ! F_2 ( V_199 , & V_6 -> V_8 -> V_26 ) ||
! F_2 ( V_200 , & V_6 -> V_26 ) ||
F_69 ( V_201 , & V_6 -> V_26 ) )
return;
F_84 ( V_6 ) ;
}
void F_87 ( struct V_5 * V_6 )
{
if ( ! F_2 ( V_199 , & V_6 -> V_8 -> V_26 ) ||
! F_2 ( V_200 , & V_6 -> V_26 ) ||
! F_88 ( V_201 , & V_6 -> V_26 ) )
return;
switch ( V_6 -> V_137 ) {
case V_195 :
case V_196 :
case V_197 :
case V_198 :
F_89 ( V_6 -> V_8 -> V_118 , V_6 -> V_137 ) ;
break;
case V_202 :
V_6 -> V_8 -> V_134 -> V_135 -> V_144 ( V_6 ) ;
default:
break;
}
}
void F_90 ( struct V_5 * V_6 )
{
F_75 ( & V_6 -> V_203 ) ;
if ( ! F_2 ( V_199 , & V_6 -> V_8 -> V_26 ) ||
F_69 ( V_200 , & V_6 -> V_26 ) ) {
F_76 ( & V_6 -> V_203 ) ;
return;
}
F_71 ( V_201 , & V_6 -> V_26 ) ;
V_6 -> V_8 -> V_134 -> V_135 -> V_204 ( V_6 ) ;
F_87 ( V_6 ) ;
F_76 ( & V_6 -> V_203 ) ;
}
void F_91 ( struct V_5 * V_6 )
{
F_75 ( & V_6 -> V_203 ) ;
if ( ! F_88 ( V_200 , & V_6 -> V_26 ) ) {
F_76 ( & V_6 -> V_203 ) ;
return;
}
F_84 ( V_6 ) ;
V_6 -> V_8 -> V_134 -> V_135 -> V_205 ( V_6 ) ;
F_76 ( & V_6 -> V_203 ) ;
}
void F_92 ( struct V_5 * V_6 , bool V_206 )
{
bool V_207 ;
bool V_208 =
( V_6 -> V_137 == V_195 ) ||
( V_6 -> V_137 == V_196 ) ||
( V_6 -> V_137 == V_197 ) ||
( V_6 -> V_137 == V_198 ) ;
F_75 ( & V_6 -> V_203 ) ;
V_207 = F_2 ( V_200 , & V_6 -> V_26 ) ;
if ( V_207 ) {
F_86 ( V_6 ) ;
if ( ! V_206 && V_208 )
V_6 -> V_8 -> V_134 -> V_135 -> V_144 ( V_6 ) ;
}
if ( F_57 ( V_6 -> V_8 -> V_134 -> V_135 -> V_209 ) )
V_6 -> V_8 -> V_134 -> V_135 -> V_209 ( V_6 , V_206 ) ;
if ( F_8 ( ! F_93 ( V_6 ) ) )
F_94 ( V_6 -> V_8 , L_8 ,
V_6 -> V_137 ) ;
if ( V_207 )
F_87 ( V_6 ) ;
F_76 ( & V_6 -> V_203 ) ;
}
void F_95 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_96 (rt2x00dev, queue)
F_90 ( V_6 ) ;
F_90 ( V_8 -> V_210 ) ;
}
void F_97 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_98 ( V_8 -> V_118 ) ;
F_96 (rt2x00dev, queue)
F_91 ( V_6 ) ;
F_91 ( V_8 -> V_210 ) ;
}
void F_99 ( struct V_7 * V_8 , bool V_206 )
{
struct V_5 * V_6 ;
F_96 (rt2x00dev, queue)
F_92 ( V_6 , V_206 ) ;
F_92 ( V_8 -> V_210 , V_206 ) ;
}
static void F_100 ( struct V_5 * V_6 )
{
unsigned long V_183 ;
unsigned int V_186 ;
F_82 ( & V_6 -> V_188 , V_183 ) ;
V_6 -> V_120 = 0 ;
V_6 -> V_111 = 0 ;
for ( V_186 = 0 ; V_186 < V_187 ; V_186 ++ )
V_6 -> V_189 [ V_186 ] = 0 ;
F_83 ( & V_6 -> V_188 , V_183 ) ;
}
void F_101 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
unsigned int V_186 ;
F_102 (rt2x00dev, queue) {
F_100 ( V_6 ) ;
for ( V_186 = 0 ; V_186 < V_6 -> V_191 ; V_186 ++ )
V_8 -> V_134 -> V_135 -> V_211 ( & V_6 -> V_190 [ V_186 ] ) ;
}
}
static int F_103 ( struct V_5 * V_6 )
{
struct V_2 * V_190 ;
unsigned int V_212 ;
unsigned int V_186 ;
F_100 ( V_6 ) ;
V_212 = sizeof( * V_190 ) + V_6 -> V_213 ;
V_190 = F_104 ( V_6 -> V_191 , V_212 , V_214 ) ;
if ( ! V_190 )
return - V_30 ;
#define F_105 ( T_5 , T_6 , T_7 , T_8 , T_9 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_186 = 0 ; V_186 < V_6 -> V_191 ; V_186 ++ ) {
V_190 [ V_186 ] . V_26 = 0 ;
V_190 [ V_186 ] . V_6 = V_6 ;
V_190 [ V_186 ] . V_9 = NULL ;
V_190 [ V_186 ] . V_215 = V_186 ;
V_190 [ V_186 ] . V_216 =
F_105 ( V_190 , V_186 , V_6 -> V_191 ,
sizeof( * V_190 ) , V_6 -> V_213 ) ;
}
#undef F_105
V_6 -> V_190 = V_190 ;
return 0 ;
}
static void F_106 ( struct V_5 * V_6 )
{
unsigned int V_186 ;
if ( ! V_6 -> V_190 )
return;
for ( V_186 = 0 ; V_186 < V_6 -> V_191 ; V_186 ++ ) {
F_14 ( & V_6 -> V_190 [ V_186 ] ) ;
}
}
static int F_107 ( struct V_5 * V_6 )
{
unsigned int V_186 ;
struct V_1 * V_9 ;
for ( V_186 = 0 ; V_186 < V_6 -> V_191 ; V_186 ++ ) {
V_9 = F_1 ( & V_6 -> V_190 [ V_186 ] , V_214 ) ;
if ( ! V_9 )
return - V_30 ;
V_6 -> V_190 [ V_186 ] . V_9 = V_9 ;
}
return 0 ;
}
int F_108 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
int V_217 ;
V_217 = F_103 ( V_8 -> V_210 ) ;
if ( V_217 )
goto exit;
F_96 (rt2x00dev, queue) {
V_217 = F_103 ( V_6 ) ;
if ( V_217 )
goto exit;
}
V_217 = F_103 ( V_8 -> V_218 ) ;
if ( V_217 )
goto exit;
if ( F_2 ( V_219 , & V_8 -> V_19 ) ) {
V_217 = F_103 ( V_8 -> V_220 ) ;
if ( V_217 )
goto exit;
}
V_217 = F_107 ( V_8 -> V_210 ) ;
if ( V_217 )
goto exit;
return 0 ;
exit:
F_51 ( V_8 , L_9 ) ;
F_109 ( V_8 ) ;
return V_217 ;
}
void F_109 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_106 ( V_8 -> V_210 ) ;
F_102 (rt2x00dev, queue) {
F_110 ( V_6 -> V_190 ) ;
V_6 -> V_190 = NULL ;
}
}
static void F_111 ( struct V_7 * V_8 ,
struct V_5 * V_6 , enum V_221 V_137 )
{
F_112 ( & V_6 -> V_203 ) ;
F_113 ( & V_6 -> V_168 ) ;
F_113 ( & V_6 -> V_188 ) ;
V_6 -> V_8 = V_8 ;
V_6 -> V_137 = V_137 ;
V_6 -> V_93 = 0 ;
V_6 -> V_222 = 2 ;
V_6 -> V_223 = 5 ;
V_6 -> V_224 = 10 ;
V_8 -> V_134 -> V_225 ( V_6 ) ;
V_6 -> V_226 = F_114 ( V_6 -> V_191 , 10 ) ;
}
int F_115 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
enum V_221 V_137 ;
unsigned int V_227 =
! ! F_2 ( V_219 , & V_8 -> V_19 ) ;
V_8 -> V_228 = 2 + V_8 -> V_134 -> V_229 + V_227 ;
V_6 = F_104 ( V_8 -> V_228 , sizeof( * V_6 ) , V_214 ) ;
if ( ! V_6 ) {
F_51 ( V_8 , L_10 ) ;
return - V_30 ;
}
V_8 -> V_210 = V_6 ;
V_8 -> V_230 = & V_6 [ 1 ] ;
V_8 -> V_218 = & V_6 [ 1 + V_8 -> V_134 -> V_229 ] ;
V_8 -> V_220 = V_227 ? & V_6 [ 2 + V_8 -> V_134 -> V_229 ] : NULL ;
F_111 ( V_8 , V_8 -> V_210 , V_202 ) ;
V_137 = V_195 ;
F_96 (rt2x00dev, queue)
F_111 ( V_8 , V_6 , V_137 ++ ) ;
F_111 ( V_8 , V_8 -> V_218 , V_231 ) ;
if ( V_227 )
F_111 ( V_8 , V_8 -> V_220 , V_232 ) ;
return 0 ;
}
void F_116 ( struct V_7 * V_8 )
{
F_110 ( V_8 -> V_210 ) ;
V_8 -> V_210 = NULL ;
V_8 -> V_230 = NULL ;
V_8 -> V_218 = NULL ;
}
