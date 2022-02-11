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
if ( F_7 ( V_18 , & V_8 -> V_19 ) ) {
T_2 V_20 ;
V_20 = F_8 ( V_8 -> V_21 , V_9 -> V_22 , V_9 -> V_23 ,
V_24 ) ;
if ( F_9 ( F_10 ( V_8 -> V_21 , V_20 ) ) ) {
F_11 ( V_9 ) ;
return NULL ;
}
V_11 -> V_20 = V_20 ;
V_11 -> V_25 |= V_26 ;
}
return V_9 ;
}
int F_12 ( struct V_2 * V_3 )
{
struct V_27 * V_21 = V_3 -> V_6 -> V_8 -> V_21 ;
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
V_11 -> V_20 =
F_8 ( V_21 , V_3 -> V_9 -> V_22 , V_3 -> V_9 -> V_23 , V_28 ) ;
if ( F_9 ( F_10 ( V_21 , V_11 -> V_20 ) ) )
return - V_29 ;
V_11 -> V_25 |= V_30 ;
return 0 ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_27 * V_21 = V_3 -> V_6 -> V_8 -> V_21 ;
struct V_10 * V_11 = F_6 ( V_3 -> V_9 ) ;
if ( V_11 -> V_25 & V_26 ) {
F_14 ( V_21 , V_11 -> V_20 , V_3 -> V_9 -> V_23 ,
V_24 ) ;
V_11 -> V_25 &= ~ V_26 ;
} else if ( V_11 -> V_25 & V_30 ) {
F_14 ( V_21 , V_11 -> V_20 , V_3 -> V_9 -> V_23 ,
V_28 ) ;
V_11 -> V_25 &= ~ V_30 ;
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
unsigned int V_31 = V_9 -> V_23 ;
unsigned int V_32 = F_17 ( V_9 , 0 ) ;
if ( ! V_32 )
return;
F_18 ( V_9 , V_32 ) ;
memmove ( V_9 -> V_22 , V_9 -> V_22 + V_32 , V_31 ) ;
F_19 ( V_9 , V_31 ) ;
}
void F_20 ( struct V_1 * V_9 , unsigned int V_33 )
{
unsigned int V_34 = V_9 -> V_23 - V_33 ;
unsigned int V_35 = F_17 ( V_9 , 0 ) ;
unsigned int V_36 = F_17 ( V_9 , V_33 ) ;
unsigned int V_37 = V_34 ? F_21 ( V_33 ) : 0 ;
if ( V_36 > V_35 )
V_35 += 4 ;
if ( ! V_35 )
return;
F_18 ( V_9 , V_35 ) ;
memmove ( V_9 -> V_22 , V_9 -> V_22 + V_35 , V_33 ) ;
if ( V_34 && V_36 )
memmove ( V_9 -> V_22 + V_33 + V_37 ,
V_9 -> V_22 + V_33 + V_37 + V_36 ,
V_34 ) ;
F_19 ( V_9 , V_33 + V_37 + V_34 ) ;
}
void F_22 ( struct V_1 * V_9 , unsigned int V_33 )
{
unsigned int V_37 = ( V_9 -> V_23 > V_33 ) ?
F_21 ( V_33 ) : 0 ;
if ( ! V_37 )
return;
memmove ( V_9 -> V_22 + V_37 , V_9 -> V_22 , V_33 ) ;
F_23 ( V_9 , V_37 ) ;
}
static void F_24 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = F_25 ( V_9 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_9 -> V_22 ;
struct V_44 * V_45 = F_26 ( V_41 -> V_46 . V_47 ) ;
T_3 V_48 ;
if ( ! ( V_41 -> V_25 & V_49 ) )
return;
F_27 ( V_50 , & V_39 -> V_25 ) ;
if ( ! F_7 ( V_51 , & V_8 -> V_19 ) ) {
if ( F_7 ( V_52 , & V_8 -> V_25 ) )
F_28 ( V_50 , & V_39 -> V_25 ) ;
else
return;
}
if ( F_7 ( V_53 , & V_39 -> V_25 ) )
V_48 = F_29 ( 0x10 , & V_45 -> V_48 ) ;
else
V_48 = F_30 ( & V_45 -> V_48 ) ;
V_43 -> V_54 &= F_31 ( V_55 ) ;
V_43 -> V_54 |= F_31 ( V_48 ) ;
}
static void F_32 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_38 * V_39 ,
const struct V_56 * V_57 )
{
struct V_40 * V_41 = F_25 ( V_9 ) ;
struct V_58 * V_59 = & V_41 -> V_46 . V_60 [ 0 ] ;
unsigned int V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
if ( F_7 ( V_53 , & V_39 -> V_25 ) )
V_39 -> V_64 . V_65 . V_66 = V_67 ;
else
V_39 -> V_64 . V_65 . V_66 = V_68 ;
V_61 = V_9 -> V_23 + 4 ;
V_61 += F_33 ( V_8 , V_9 ) ;
V_39 -> V_64 . V_65 . signal = V_57 -> V_65 ;
V_39 -> V_64 . V_65 . V_69 = 0x04 ;
if ( V_57 -> V_25 & V_70 ) {
V_39 -> V_64 . V_65 . V_71 = ( V_61 >> 6 ) & 0x3f ;
V_39 -> V_64 . V_65 . V_72 = V_61 & 0x3f ;
} else {
V_63 = F_34 ( V_61 , V_57 -> V_73 ) ;
V_62 = F_35 ( V_61 , V_57 -> V_73 ) ;
if ( V_63 != 0 ) {
V_62 ++ ;
if ( V_57 -> V_73 == 110 && V_63 <= 30 )
V_39 -> V_64 . V_65 . V_69 |= 0x80 ;
}
V_39 -> V_64 . V_65 . V_71 = ( V_62 >> 8 ) & 0xff ;
V_39 -> V_64 . V_65 . V_72 = V_62 & 0xff ;
if ( V_59 -> V_25 & V_74 )
V_39 -> V_64 . V_65 . signal |= 0x08 ;
}
}
static void F_36 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_38 * V_39 ,
struct V_75 * V_76 ,
const struct V_56 * V_57 )
{
struct V_40 * V_41 = F_25 ( V_9 ) ;
struct V_58 * V_59 = & V_41 -> V_46 . V_60 [ 0 ] ;
struct V_42 * V_43 = (struct V_42 * ) V_9 -> V_22 ;
struct V_77 * V_78 = NULL ;
if ( V_76 ) {
V_39 -> V_64 . V_79 . V_80 =
V_76 -> V_81 . V_82 ;
V_78 = F_37 ( V_76 ) ;
V_39 -> V_64 . V_79 . V_83 = V_78 -> V_83 ;
}
if ( V_59 -> V_25 & V_84 ) {
V_39 -> V_64 . V_79 . V_85 = V_59 -> V_86 ;
if ( V_76 && V_39 -> V_64 . V_79 . V_85 > 7 &&
V_76 -> V_87 == V_88 )
F_27 ( V_89 , & V_39 -> V_25 ) ;
} else {
V_39 -> V_64 . V_79 . V_85 = F_38 ( V_57 -> V_85 ) ;
if ( V_59 -> V_25 & V_74 )
V_39 -> V_64 . V_79 . V_85 |= 0x08 ;
}
if ( F_7 ( V_90 , & V_8 -> V_25 ) ) {
if ( ! ( V_41 -> V_25 & V_91 ) )
V_39 -> V_64 . V_79 . V_92 = V_93 ;
else
V_39 -> V_64 . V_79 . V_92 = V_94 ;
return;
}
V_39 -> V_64 . V_79 . V_95 = 7 ;
if ( V_41 -> V_25 & V_96 )
V_39 -> V_64 . V_79 . V_97 = 1 ;
if ( V_41 -> V_25 & V_98 &&
! ( V_41 -> V_25 & V_99 ) )
F_27 ( V_100 , & V_39 -> V_25 ) ;
if ( V_59 -> V_25 & V_101 ||
V_59 -> V_25 & V_102 )
F_27 ( V_103 , & V_39 -> V_25 ) ;
if ( V_59 -> V_25 & V_104 )
F_27 ( V_105 , & V_39 -> V_25 ) ;
if ( F_39 ( V_43 -> V_106 ) &&
! F_40 ( V_43 -> V_106 ) )
V_39 -> V_64 . V_79 . V_92 = V_94 ;
else if ( ! ( V_41 -> V_25 & V_91 ) )
V_39 -> V_64 . V_79 . V_92 = V_93 ;
else
V_39 -> V_64 . V_79 . V_92 = V_107 ;
}
static void F_41 ( struct V_7 * V_8 ,
struct V_1 * V_9 ,
struct V_38 * V_39 ,
struct V_75 * V_76 )
{
struct V_40 * V_41 = F_25 ( V_9 ) ;
struct V_42 * V_43 = (struct V_42 * ) V_9 -> V_22 ;
struct V_58 * V_59 = & V_41 -> V_46 . V_60 [ 0 ] ;
struct V_108 * V_109 ;
const struct V_56 * V_57 = NULL ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_110 = V_9 -> V_23 ;
V_39 -> V_33 = F_42 ( V_9 ) ;
if ( ! ( V_41 -> V_25 & V_111 ) )
F_27 ( V_112 , & V_39 -> V_25 ) ;
if ( F_43 ( V_43 -> V_106 ) ||
F_44 ( V_43 -> V_106 ) ) {
F_27 ( V_113 , & V_39 -> V_25 ) ;
if ( F_43 ( V_43 -> V_106 ) )
F_27 ( V_114 , & V_39 -> V_25 ) ;
else
F_27 ( V_115 , & V_39 -> V_25 ) ;
if ( V_41 -> V_46 . V_116 >= 0 )
V_109 =
F_45 ( V_8 -> V_117 , V_41 ) ;
}
V_39 -> V_118 = V_41 -> V_46 . V_60 [ 0 ] . V_119 - 1 ;
if ( V_39 -> V_118 >= V_8 -> V_120 )
F_27 ( V_121 , & V_39 -> V_25 ) ;
if ( F_46 ( V_43 -> V_106 ) ) {
F_27 ( V_113 , & V_39 -> V_25 ) ;
F_27 ( V_122 , & V_39 -> V_25 ) ;
}
if ( V_41 -> V_25 & V_123 )
F_27 ( V_113 , & V_39 -> V_25 ) ;
if ( F_40 ( V_43 -> V_106 ) ||
F_47 ( V_43 -> V_106 ) )
F_27 ( V_124 , & V_39 -> V_25 ) ;
if ( ( V_41 -> V_25 & V_91 ) &&
! F_7 ( V_114 , & V_39 -> V_25 ) )
F_27 ( V_53 , & V_39 -> V_25 ) ;
if ( V_59 -> V_25 & V_125 )
V_39 -> V_126 = V_127 ;
else if ( V_59 -> V_25 & V_84 )
V_39 -> V_126 = V_128 ;
else {
V_109 = F_48 ( V_8 -> V_117 , V_41 ) ;
V_57 = F_49 ( V_109 -> V_129 ) ;
if ( V_57 -> V_25 & V_70 )
V_39 -> V_126 = V_130 ;
else
V_39 -> V_126 = V_131 ;
}
F_50 ( V_8 , V_9 , V_39 ) ;
F_24 ( V_8 , V_9 , V_39 ) ;
if ( F_7 ( V_132 , & V_8 -> V_19 ) )
F_36 ( V_8 , V_9 , V_39 ,
V_76 , V_57 ) ;
else
F_32 ( V_8 , V_9 , V_39 ,
V_57 ) ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_8 ;
if ( F_9 ( V_8 -> V_133 -> V_134 -> V_135 &&
V_8 -> V_133 -> V_134 -> V_135 ( V_3 ) ) ) {
F_52 ( V_8 ,
L_1
L_2 ,
V_3 -> V_6 -> V_136 , V_137 ) ;
return - V_138 ;
}
F_18 ( V_3 -> V_9 , V_8 -> V_139 ) ;
memset ( V_3 -> V_9 -> V_22 , 0 , V_8 -> V_139 ) ;
if ( V_8 -> V_133 -> V_134 -> V_140 )
V_8 -> V_133 -> V_134 -> V_140 ( V_3 , V_39 ) ;
if ( F_7 ( V_18 , & V_8 -> V_19 ) &&
F_12 ( V_3 ) )
return - V_29 ;
return 0 ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
V_6 -> V_8 -> V_133 -> V_134 -> V_141 ( V_3 , V_39 ) ;
F_54 ( V_6 -> V_8 , V_142 , V_3 -> V_9 ) ;
}
static void F_55 ( struct V_5 * V_6 ,
struct V_38 * V_39 )
{
if ( F_56 ( V_6 ) ||
! F_7 ( V_113 , & V_39 -> V_25 ) )
V_6 -> V_8 -> V_133 -> V_134 -> V_143 ( V_6 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_6 -> V_8 ;
struct V_144 * V_145 = ( void * ) ( V_3 -> V_9 -> V_22 +
V_8 -> V_139 ) ;
struct V_146 * V_147 ;
if ( F_58 ( ! F_59 ( V_145 -> V_106 ) ) )
return;
V_147 = F_60 ( sizeof( * V_147 ) , V_148 ) ;
if ( ! V_147 )
return;
V_147 -> V_3 = V_3 ;
V_147 -> V_149 = 0 ;
memcpy ( V_147 -> V_150 , V_145 -> V_150 , sizeof( V_145 -> V_150 ) ) ;
memcpy ( V_147 -> V_151 , V_145 -> V_151 , sizeof( V_145 -> V_151 ) ) ;
V_147 -> V_46 = V_145 -> V_46 ;
V_147 -> V_152 = V_145 -> V_152 ;
F_61 ( & V_8 -> V_153 ) ;
F_62 ( & V_147 -> V_154 , & V_8 -> V_155 ) ;
F_63 ( & V_8 -> V_153 ) ;
}
int F_64 ( struct V_5 * V_6 , struct V_1 * V_9 ,
struct V_75 * V_76 , bool V_156 )
{
struct V_40 * V_41 ;
struct V_2 * V_3 ;
struct V_38 V_39 ;
struct V_10 * V_11 ;
T_4 V_157 , V_158 ;
int V_159 = 0 ;
F_41 ( V_6 -> V_8 , V_9 , & V_39 , V_76 ) ;
V_41 = F_25 ( V_9 ) ;
V_157 = V_41 -> V_46 . V_60 [ 0 ] . V_86 ;
V_158 = V_41 -> V_46 . V_60 [ 0 ] . V_25 ;
V_11 = F_6 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_160 = V_157 ;
V_11 -> V_161 = V_158 ;
if ( V_156 )
V_11 -> V_25 |= V_162 ;
if ( F_7 ( V_163 , & V_39 . V_25 ) &&
! F_7 ( V_164 , & V_39 . V_25 ) ) {
if ( F_7 ( V_165 , & V_6 -> V_8 -> V_19 ) )
F_65 ( V_9 , & V_39 ) ;
else
F_66 ( V_9 , & V_39 ) ;
}
if ( F_7 ( V_166 , & V_6 -> V_8 -> V_19 ) )
F_20 ( V_9 , V_39 . V_33 ) ;
else if ( F_7 ( V_18 , & V_6 -> V_8 -> V_19 ) )
F_16 ( V_9 ) ;
F_67 ( & V_6 -> V_167 ) ;
if ( F_9 ( F_68 ( V_6 ) ) ) {
F_52 ( V_6 -> V_8 , L_3 ,
V_6 -> V_136 ) ;
V_159 = - V_168 ;
goto V_169;
}
V_3 = F_69 ( V_6 , V_170 ) ;
if ( F_9 ( F_70 ( V_171 ,
& V_3 -> V_25 ) ) ) {
F_52 ( V_6 -> V_8 ,
L_4
L_2 ,
V_6 -> V_136 , V_137 ) ;
V_159 = - V_138 ;
goto V_169;
}
V_11 -> V_3 = V_3 ;
V_3 -> V_9 = V_9 ;
if ( F_9 ( F_51 ( V_3 , & V_39 ) ) ) {
F_71 ( V_171 , & V_3 -> V_25 ) ;
V_3 -> V_9 = NULL ;
V_159 = - V_172 ;
goto V_169;
}
F_57 ( V_3 ) ;
F_72 ( V_173 , & V_3 -> V_25 ) ;
F_73 ( V_3 , V_170 ) ;
F_53 ( V_3 , & V_39 ) ;
F_55 ( V_6 , & V_39 ) ;
V_169:
F_74 ( & V_6 -> V_167 ) ;
return V_159 ;
}
int F_75 ( struct V_7 * V_8 ,
struct V_174 * V_47 )
{
struct V_44 * V_45 = F_26 ( V_47 ) ;
if ( F_9 ( ! V_45 -> V_175 ) )
return - V_168 ;
F_15 ( V_45 -> V_175 ) ;
if ( V_8 -> V_133 -> V_134 -> V_176 )
V_8 -> V_133 -> V_134 -> V_176 ( V_45 -> V_175 ) ;
return 0 ;
}
int F_76 ( struct V_7 * V_8 ,
struct V_174 * V_47 )
{
struct V_44 * V_45 = F_26 ( V_47 ) ;
struct V_10 * V_11 ;
struct V_38 V_39 ;
if ( F_9 ( ! V_45 -> V_175 ) )
return - V_168 ;
F_15 ( V_45 -> V_175 ) ;
V_45 -> V_175 -> V_9 = F_77 ( V_8 -> V_117 , V_47 ) ;
if ( ! V_45 -> V_175 -> V_9 )
return - V_29 ;
F_41 ( V_8 , V_45 -> V_175 -> V_9 , & V_39 , NULL ) ;
V_11 = F_6 ( V_45 -> V_175 -> V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_3 = V_45 -> V_175 ;
V_8 -> V_133 -> V_134 -> V_177 ( V_45 -> V_175 , & V_39 ) ;
return 0 ;
}
bool F_78 ( struct V_5 * V_6 ,
enum V_178 V_179 ,
enum V_178 V_180 ,
void * V_22 ,
bool (* F_79)( struct V_2 * V_3 ,
void * V_22 ) )
{
unsigned long V_181 ;
unsigned int V_182 ;
unsigned int V_183 ;
unsigned int V_184 ;
if ( F_9 ( V_179 >= V_185 || V_180 >= V_185 ) ) {
F_52 ( V_6 -> V_8 ,
L_5 ,
V_179 , V_180 ) ;
return true ;
}
F_80 ( & V_6 -> V_186 , V_181 ) ;
V_182 = V_6 -> V_187 [ V_179 ] ;
V_183 = V_6 -> V_187 [ V_180 ] ;
F_81 ( & V_6 -> V_186 , V_181 ) ;
if ( V_182 < V_183 ) {
for ( V_184 = V_182 ; V_184 < V_183 ; V_184 ++ ) {
if ( F_79 ( & V_6 -> V_188 [ V_184 ] , V_22 ) )
return true ;
}
} else {
for ( V_184 = V_182 ; V_184 < V_6 -> V_189 ; V_184 ++ ) {
if ( F_79 ( & V_6 -> V_188 [ V_184 ] , V_22 ) )
return true ;
}
for ( V_184 = 0 ; V_184 < V_183 ; V_184 ++ ) {
if ( F_79 ( & V_6 -> V_188 [ V_184 ] , V_22 ) )
return true ;
}
}
return false ;
}
struct V_2 * F_69 ( struct V_5 * V_6 ,
enum V_178 V_187 )
{
struct V_2 * V_3 ;
unsigned long V_181 ;
if ( F_9 ( V_187 >= V_185 ) ) {
F_52 ( V_6 -> V_8 , L_6 ,
V_187 ) ;
return NULL ;
}
F_80 ( & V_6 -> V_186 , V_181 ) ;
V_3 = & V_6 -> V_188 [ V_6 -> V_187 [ V_187 ] ] ;
F_81 ( & V_6 -> V_186 , V_181 ) ;
return V_3 ;
}
void F_73 ( struct V_2 * V_3 , enum V_178 V_187 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
unsigned long V_181 ;
if ( F_9 ( V_187 >= V_185 ) ) {
F_52 ( V_6 -> V_8 ,
L_7 , V_187 ) ;
return;
}
F_80 ( & V_6 -> V_186 , V_181 ) ;
V_6 -> V_187 [ V_187 ] ++ ;
if ( V_6 -> V_187 [ V_187 ] >= V_6 -> V_189 )
V_6 -> V_187 [ V_187 ] = 0 ;
V_3 -> V_190 = V_191 ;
if ( V_187 == V_170 ) {
V_6 -> V_110 ++ ;
} else if ( V_187 == V_192 ) {
V_6 -> V_110 -- ;
V_6 -> V_119 ++ ;
}
F_81 ( & V_6 -> V_186 , V_181 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_136 ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
F_83 ( V_6 -> V_8 -> V_117 , V_6 -> V_136 ) ;
break;
default:
break;
}
}
void F_84 ( struct V_5 * V_6 )
{
if ( ! F_7 ( V_197 , & V_6 -> V_8 -> V_25 ) ||
! F_7 ( V_198 , & V_6 -> V_25 ) ||
F_70 ( V_199 , & V_6 -> V_25 ) )
return;
F_82 ( V_6 ) ;
}
void F_85 ( struct V_5 * V_6 )
{
if ( ! F_7 ( V_197 , & V_6 -> V_8 -> V_25 ) ||
! F_7 ( V_198 , & V_6 -> V_25 ) ||
! F_86 ( V_199 , & V_6 -> V_25 ) )
return;
switch ( V_6 -> V_136 ) {
case V_193 :
case V_194 :
case V_195 :
case V_196 :
F_87 ( V_6 -> V_8 -> V_117 , V_6 -> V_136 ) ;
break;
case V_200 :
V_6 -> V_8 -> V_133 -> V_134 -> V_143 ( V_6 ) ;
default:
break;
}
}
void F_88 ( struct V_5 * V_6 )
{
F_89 ( & V_6 -> V_201 ) ;
if ( ! F_7 ( V_197 , & V_6 -> V_8 -> V_25 ) ||
F_70 ( V_198 , & V_6 -> V_25 ) ) {
F_90 ( & V_6 -> V_201 ) ;
return;
}
F_72 ( V_199 , & V_6 -> V_25 ) ;
V_6 -> V_8 -> V_133 -> V_134 -> V_202 ( V_6 ) ;
F_85 ( V_6 ) ;
F_90 ( & V_6 -> V_201 ) ;
}
void F_91 ( struct V_5 * V_6 )
{
F_89 ( & V_6 -> V_201 ) ;
if ( ! F_86 ( V_198 , & V_6 -> V_25 ) ) {
F_90 ( & V_6 -> V_201 ) ;
return;
}
F_82 ( V_6 ) ;
V_6 -> V_8 -> V_133 -> V_134 -> V_203 ( V_6 ) ;
F_90 ( & V_6 -> V_201 ) ;
}
void F_92 ( struct V_5 * V_6 , bool V_204 )
{
bool V_205 =
( V_6 -> V_136 == V_193 ) ||
( V_6 -> V_136 == V_194 ) ||
( V_6 -> V_136 == V_195 ) ||
( V_6 -> V_136 == V_196 ) ;
if ( ! V_204 && V_205 )
V_6 -> V_8 -> V_133 -> V_134 -> V_143 ( V_6 ) ;
if ( F_58 ( V_6 -> V_8 -> V_133 -> V_134 -> V_206 ) )
V_6 -> V_8 -> V_133 -> V_134 -> V_206 ( V_6 , V_204 ) ;
if ( F_9 ( ! F_93 ( V_6 ) ) )
F_94 ( V_6 -> V_8 , L_8 ,
V_6 -> V_136 ) ;
}
void F_95 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_96 (rt2x00dev, queue)
F_88 ( V_6 ) ;
F_88 ( V_8 -> V_207 ) ;
}
void F_97 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_98 ( V_8 -> V_117 ) ;
F_96 (rt2x00dev, queue)
F_91 ( V_6 ) ;
F_91 ( V_8 -> V_207 ) ;
}
void F_99 ( struct V_7 * V_8 , bool V_204 )
{
struct V_5 * V_6 ;
F_96 (rt2x00dev, queue)
F_92 ( V_6 , V_204 ) ;
F_92 ( V_8 -> V_207 , V_204 ) ;
}
static void F_100 ( struct V_5 * V_6 )
{
unsigned long V_181 ;
unsigned int V_184 ;
F_80 ( & V_6 -> V_186 , V_181 ) ;
V_6 -> V_119 = 0 ;
V_6 -> V_110 = 0 ;
for ( V_184 = 0 ; V_184 < V_185 ; V_184 ++ )
V_6 -> V_187 [ V_184 ] = 0 ;
F_81 ( & V_6 -> V_186 , V_181 ) ;
}
void F_101 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
unsigned int V_184 ;
F_102 (rt2x00dev, queue) {
F_100 ( V_6 ) ;
for ( V_184 = 0 ; V_184 < V_6 -> V_189 ; V_184 ++ )
V_8 -> V_133 -> V_134 -> V_208 ( & V_6 -> V_188 [ V_184 ] ) ;
}
}
static int F_103 ( struct V_5 * V_6 )
{
struct V_2 * V_188 ;
unsigned int V_209 ;
unsigned int V_184 ;
F_100 ( V_6 ) ;
V_209 = sizeof( * V_188 ) + V_6 -> V_210 ;
V_188 = F_104 ( V_6 -> V_189 , V_209 , V_211 ) ;
if ( ! V_188 )
return - V_29 ;
#define F_105 ( T_5 , T_6 , T_7 , T_8 , T_9 ) \
(((char *)(__base)) + ((__limit) * (__esize)) + \
((__index) * (__psize)))
for ( V_184 = 0 ; V_184 < V_6 -> V_189 ; V_184 ++ ) {
V_188 [ V_184 ] . V_25 = 0 ;
V_188 [ V_184 ] . V_6 = V_6 ;
V_188 [ V_184 ] . V_9 = NULL ;
V_188 [ V_184 ] . V_212 = V_184 ;
V_188 [ V_184 ] . V_213 =
F_105 ( V_188 , V_184 , V_6 -> V_189 ,
sizeof( * V_188 ) , V_6 -> V_210 ) ;
}
#undef F_105
V_6 -> V_188 = V_188 ;
return 0 ;
}
static void F_106 ( struct V_5 * V_6 )
{
unsigned int V_184 ;
if ( ! V_6 -> V_188 )
return;
for ( V_184 = 0 ; V_184 < V_6 -> V_189 ; V_184 ++ ) {
F_15 ( & V_6 -> V_188 [ V_184 ] ) ;
}
}
static int F_107 ( struct V_5 * V_6 )
{
unsigned int V_184 ;
struct V_1 * V_9 ;
for ( V_184 = 0 ; V_184 < V_6 -> V_189 ; V_184 ++ ) {
V_9 = F_1 ( & V_6 -> V_188 [ V_184 ] , V_211 ) ;
if ( ! V_9 )
return - V_29 ;
V_6 -> V_188 [ V_184 ] . V_9 = V_9 ;
}
return 0 ;
}
int F_108 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
int V_214 ;
V_214 = F_103 ( V_8 -> V_207 ) ;
if ( V_214 )
goto exit;
F_96 (rt2x00dev, queue) {
V_214 = F_103 ( V_6 ) ;
if ( V_214 )
goto exit;
}
V_214 = F_103 ( V_8 -> V_215 ) ;
if ( V_214 )
goto exit;
if ( F_7 ( V_216 , & V_8 -> V_19 ) ) {
V_214 = F_103 ( V_8 -> V_217 ) ;
if ( V_214 )
goto exit;
}
V_214 = F_107 ( V_8 -> V_207 ) ;
if ( V_214 )
goto exit;
return 0 ;
exit:
F_52 ( V_8 , L_9 ) ;
F_109 ( V_8 ) ;
return V_214 ;
}
void F_109 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
F_106 ( V_8 -> V_207 ) ;
F_102 (rt2x00dev, queue) {
F_110 ( V_6 -> V_188 ) ;
V_6 -> V_188 = NULL ;
}
}
static void F_111 ( struct V_7 * V_8 ,
struct V_5 * V_6 , enum V_218 V_136 )
{
F_112 ( & V_6 -> V_201 ) ;
F_113 ( & V_6 -> V_167 ) ;
F_113 ( & V_6 -> V_186 ) ;
V_6 -> V_8 = V_8 ;
V_6 -> V_136 = V_136 ;
V_6 -> V_92 = 0 ;
V_6 -> V_219 = 2 ;
V_6 -> V_220 = 5 ;
V_6 -> V_221 = 10 ;
V_8 -> V_133 -> V_222 ( V_6 ) ;
V_6 -> V_223 = F_114 ( V_6 -> V_189 , 10 ) ;
}
int F_115 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
enum V_218 V_136 ;
unsigned int V_224 =
! ! F_7 ( V_216 , & V_8 -> V_19 ) ;
V_8 -> V_225 = 2 + V_8 -> V_133 -> V_226 + V_224 ;
V_6 = F_104 ( V_8 -> V_225 , sizeof( * V_6 ) , V_211 ) ;
if ( ! V_6 ) {
F_52 ( V_8 , L_10 ) ;
return - V_29 ;
}
V_8 -> V_207 = V_6 ;
V_8 -> V_227 = & V_6 [ 1 ] ;
V_8 -> V_215 = & V_6 [ 1 + V_8 -> V_133 -> V_226 ] ;
V_8 -> V_217 = V_224 ? & V_6 [ 2 + V_8 -> V_133 -> V_226 ] : NULL ;
F_111 ( V_8 , V_8 -> V_207 , V_200 ) ;
V_136 = V_193 ;
F_96 (rt2x00dev, queue)
F_111 ( V_8 , V_6 , V_136 ++ ) ;
F_111 ( V_8 , V_8 -> V_215 , V_228 ) ;
if ( V_224 )
F_111 ( V_8 , V_8 -> V_217 , V_229 ) ;
return 0 ;
}
void F_116 ( struct V_7 * V_8 )
{
F_110 ( V_8 -> V_207 ) ;
V_8 -> V_207 = NULL ;
V_8 -> V_227 = NULL ;
V_8 -> V_215 = NULL ;
}
