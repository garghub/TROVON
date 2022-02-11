static unsigned short int F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 - V_2 -> V_3 . V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
const T_1 * V_6 = ( const T_1 * ) & V_2 -> V_7 ;
T_2 V_8 = sizeof( V_2 -> V_7 ) ;
T_2 V_9 , V_10 = 0 , V_11 = V_8 - 1 ;
for ( V_9 = 0 ; V_9 < sizeof( V_2 -> V_7 ) ; V_9 ++ ) {
if ( V_6 [ V_9 ] ) {
if ( ! V_10 && V_9 )
V_10 = V_9 ;
V_11 = V_9 ;
}
}
V_2 -> V_3 . V_5 = F_3 ( V_10 , sizeof( long ) ) ;
V_2 -> V_3 . V_4 = F_4 ( V_11 + 1 , sizeof( long ) ) ;
}
static void * F_5 ( struct V_12 * V_7 ,
const struct V_1 * V_2 )
{
return ( T_1 * ) V_7 + V_2 -> V_3 . V_5 ;
}
static void F_6 ( struct V_12 * V_13 , struct V_12 * V_7 ,
struct V_1 * V_2 )
{
const long * V_14 = F_5 ( V_7 , V_2 ) ;
const long * V_15 = F_5 ( & V_2 -> V_7 , V_2 ) ;
long * V_16 = F_5 ( V_13 , V_2 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_1 ( V_2 ) ; V_9 += sizeof( long ) )
* V_16 ++ = * V_14 ++ & * V_15 ++ ;
}
static void F_7 ( struct V_12 * V_7 ,
struct V_1 * V_2 )
{
memset ( F_5 ( V_7 , V_2 ) , 0 , F_1 ( V_2 ) ) ;
}
static int F_8 ( struct V_17 * V_18 , const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_9 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
struct V_12 V_28 ;
struct V_12 V_29 ;
struct V_30 * V_31 ;
if ( ! F_10 ( & V_24 -> V_32 . V_33 ) )
return - 1 ;
F_7 ( & V_28 , & V_24 -> V_2 ) ;
V_31 = F_11 ( V_18 ) ;
if ( V_31 ) {
struct V_34 * V_7 = & V_31 -> V_7 ;
switch ( F_12 ( V_31 ) ) {
case V_35 :
V_28 . V_36 . V_37 =
V_38 ;
V_28 . V_39 . V_40 = V_7 -> V_41 . V_42 . V_40 ;
V_28 . V_39 . V_43 = V_7 -> V_41 . V_42 . V_43 ;
break;
case V_44 :
V_28 . V_36 . V_37 =
V_45 ;
V_28 . V_46 . V_40 = V_7 -> V_41 . V_47 . V_40 ;
V_28 . V_46 . V_43 = V_7 -> V_41 . V_47 . V_43 ;
break;
}
V_28 . V_48 . V_49 = F_13 ( V_7 -> V_50 ) ;
V_28 . V_51 . V_40 = V_7 -> V_52 ;
V_28 . V_51 . V_43 = V_7 -> V_53 ;
}
V_28 . V_54 = V_18 -> V_55 ;
V_28 . V_56 . V_57 = V_18 -> V_58 ;
F_14 ( V_18 , & V_24 -> V_59 , & V_28 , 0 ) ;
F_6 ( & V_29 , & V_28 , & V_24 -> V_2 ) ;
V_27 = F_15 ( & V_24 -> V_32 ,
F_5 ( & V_29 , & V_24 -> V_2 ) ,
V_24 -> V_60 ) ;
if ( V_27 && ! F_16 ( V_27 -> V_61 ) ) {
* V_22 = V_27 -> V_22 ;
return F_17 ( V_18 , & V_27 -> V_62 , V_22 ) ;
}
return - 1 ;
}
static int F_18 ( struct V_19 * V_20 )
{
struct V_23 * V_24 ;
V_24 = F_19 ( sizeof( * V_24 ) , V_63 ) ;
if ( ! V_24 )
return - V_64 ;
F_20 ( & V_24 -> V_65 ) ;
F_21 ( V_20 -> V_25 , V_24 ) ;
return 0 ;
}
static void F_22 ( struct V_66 * V_24 )
{
struct V_26 * V_27 = F_23 ( V_24 , struct V_26 , V_67 ) ;
F_24 ( & V_27 -> V_62 ) ;
F_25 ( V_27 ) ;
}
static void F_26 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_68 V_69 = { 0 } ;
struct V_70 * V_71 = V_27 -> V_72 ;
struct V_73 * V_74 = & V_27 -> V_74 ;
if ( ! F_27 ( V_71 , V_20 ) )
return;
V_69 . V_75 = V_76 ;
V_69 . V_77 = ( unsigned long ) V_27 ;
V_74 -> type = V_78 ;
V_74 -> V_79 = & V_69 ;
V_71 -> V_80 -> V_81 ( V_71 , V_20 -> V_82 -> V_83 , V_20 -> V_58 , V_74 ) ;
}
static int F_28 ( struct V_19 * V_20 ,
struct V_84 * V_59 ,
struct V_12 * V_2 ,
struct V_26 * V_27 )
{
struct V_70 * V_71 = V_20 -> V_82 -> V_85 -> V_71 ;
struct V_68 V_69 = { 0 } ;
struct V_73 * V_74 = & V_27 -> V_74 ;
int V_86 ;
if ( ! F_27 ( V_71 , V_20 ) ) {
if ( F_29 ( V_71 , & V_27 -> V_62 , & V_27 -> V_72 ) ||
( V_27 -> V_72 && ! F_27 ( V_27 -> V_72 , V_20 ) ) ) {
V_27 -> V_72 = V_71 ;
return F_16 ( V_27 -> V_61 ) ? - V_87 : 0 ;
}
V_71 = V_27 -> V_72 ;
V_74 -> V_88 = true ;
} else {
V_27 -> V_72 = V_71 ;
}
V_69 . V_75 = V_89 ;
V_69 . V_77 = ( unsigned long ) V_27 ;
V_69 . V_59 = V_59 ;
V_69 . V_2 = V_2 ;
V_69 . V_7 = & V_27 -> V_13 ;
V_69 . V_62 = & V_27 -> V_62 ;
V_74 -> type = V_78 ;
V_74 -> V_79 = & V_69 ;
V_86 = V_71 -> V_80 -> V_81 ( V_71 , V_20 -> V_82 -> V_83 , V_20 -> V_58 ,
V_74 ) ;
if ( F_16 ( V_27 -> V_61 ) )
return V_86 ;
return 0 ;
}
static void F_30 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_68 V_69 = { 0 } ;
struct V_70 * V_71 = V_27 -> V_72 ;
struct V_73 * V_74 = & V_27 -> V_74 ;
if ( ! F_27 ( V_71 , V_20 ) )
return;
V_69 . V_75 = V_90 ;
V_69 . V_77 = ( unsigned long ) V_27 ;
V_69 . V_62 = & V_27 -> V_62 ;
V_74 -> type = V_78 ;
V_74 -> V_79 = & V_69 ;
V_71 -> V_80 -> V_81 ( V_71 , V_20 -> V_82 -> V_83 , V_20 -> V_58 , V_74 ) ;
}
static void F_31 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
F_32 ( & V_27 -> V_91 ) ;
if ( ! F_33 ( V_27 -> V_61 ) )
F_26 ( V_20 , V_27 ) ;
F_34 ( V_20 , & V_27 -> V_22 ) ;
F_35 ( & V_27 -> V_67 , F_22 ) ;
}
static void F_36 ( struct V_92 * V_93 )
{
struct V_23 * V_24 = F_23 ( V_93 , struct V_23 ,
V_93 ) ;
if ( V_24 -> V_94 )
F_37 ( & V_24 -> V_32 ) ;
F_25 ( V_24 ) ;
F_38 ( V_95 ) ;
}
static void F_39 ( struct V_66 * V_67 )
{
struct V_23 * V_24 = F_23 ( V_67 , struct V_23 , V_67 ) ;
F_40 ( & V_24 -> V_93 , F_36 ) ;
F_41 ( & V_24 -> V_93 ) ;
}
static bool F_42 ( struct V_19 * V_20 , bool V_96 )
{
struct V_23 * V_24 = F_43 ( V_20 -> V_25 ) ;
struct V_26 * V_27 , * V_97 ;
if ( ! V_96 && ! F_44 ( & V_24 -> V_65 ) )
return false ;
F_45 (f, next, &head->filters, list)
F_31 ( V_20 , V_27 ) ;
F_46 ( V_95 ) ;
F_35 ( & V_24 -> V_67 , F_39 ) ;
return true ;
}
static unsigned long F_47 ( struct V_19 * V_20 , T_3 V_83 )
{
struct V_23 * V_24 = F_43 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_48 (f, &head->filters, list)
if ( V_27 -> V_83 == V_83 )
return ( unsigned long ) V_27 ;
return 0 ;
}
static void F_49 ( struct V_98 * * V_99 ,
void * V_100 , int V_101 ,
void * V_2 , int V_102 , int V_103 )
{
if ( ! V_99 [ V_101 ] )
return;
memcpy ( V_100 , F_50 ( V_99 [ V_101 ] ) , V_103 ) ;
if ( V_102 == V_104 || ! V_99 [ V_102 ] )
memset ( V_2 , 0xff , V_103 ) ;
else
memcpy ( V_2 , F_50 ( V_99 [ V_102 ] ) , V_103 ) ;
}
static void F_51 ( struct V_98 * * V_99 ,
struct V_105 * V_106 ,
struct V_105 * V_107 )
{
#define F_52 0x7
if ( V_99 [ V_108 ] ) {
V_106 -> V_109 =
F_53 ( V_99 [ V_108 ] ) & V_110 ;
V_107 -> V_109 = V_110 ;
}
if ( V_99 [ V_111 ] ) {
V_106 -> V_112 =
F_54 ( V_99 [ V_111 ] ) &
F_52 ;
V_107 -> V_112 = F_52 ;
}
}
static void F_55 ( T_3 V_113 , T_3 V_114 ,
T_3 * V_115 , T_3 * V_116 ,
T_3 V_117 , T_3 V_118 )
{
if ( V_114 & V_117 ) {
* V_116 |= V_118 ;
if ( V_113 & V_117 )
* V_115 |= V_118 ;
}
}
static int F_56 ( struct V_98 * * V_99 ,
T_3 * V_119 , T_3 * V_120 )
{
T_3 V_7 , V_2 ;
if ( ! V_99 [ V_121 ] )
return - V_87 ;
V_7 = F_57 ( F_58 ( V_99 [ V_122 ] ) ) ;
V_2 = F_57 ( F_58 ( V_99 [ V_121 ] ) ) ;
* V_119 = 0 ;
* V_120 = 0 ;
F_55 ( V_7 , V_2 , V_119 , V_120 ,
V_123 , V_124 ) ;
return 0 ;
}
static int F_59 ( struct V_125 * V_125 , struct V_98 * * V_99 ,
struct V_12 * V_7 , struct V_12 * V_2 )
{
T_4 V_126 ;
int V_127 = 0 ;
#ifdef F_60
if ( V_99 [ V_128 ] ) {
int V_86 = F_61 ( V_125 , V_99 [ V_128 ] ) ;
if ( V_86 < 0 )
return V_86 ;
V_7 -> V_54 = V_86 ;
V_2 -> V_54 = 0xffffffff ;
}
#endif
F_49 ( V_99 , V_7 -> V_129 . V_43 , V_130 ,
V_2 -> V_129 . V_43 , V_131 ,
sizeof( V_7 -> V_129 . V_43 ) ) ;
F_49 ( V_99 , V_7 -> V_129 . V_40 , V_132 ,
V_2 -> V_129 . V_40 , V_133 ,
sizeof( V_7 -> V_129 . V_40 ) ) ;
if ( V_99 [ V_134 ] ) {
V_126 = F_62 ( V_99 [ V_134 ] ) ;
if ( V_126 == F_63 ( V_135 ) ) {
F_51 ( V_99 , & V_7 -> V_136 , & V_2 -> V_136 ) ;
F_49 ( V_99 , & V_7 -> V_56 . V_57 ,
V_137 ,
& V_2 -> V_56 . V_57 , V_104 ,
sizeof( V_7 -> V_56 . V_57 ) ) ;
} else {
V_7 -> V_56 . V_57 = V_126 ;
V_2 -> V_56 . V_57 = F_64 ( ~ 0 ) ;
}
}
if ( V_7 -> V_56 . V_57 == F_63 ( V_138 ) ||
V_7 -> V_56 . V_57 == F_63 ( V_139 ) ) {
F_49 ( V_99 , & V_7 -> V_56 . V_140 , V_141 ,
& V_2 -> V_56 . V_140 , V_104 ,
sizeof( V_7 -> V_56 . V_140 ) ) ;
}
if ( V_99 [ V_142 ] || V_99 [ V_143 ] ) {
V_7 -> V_144 . V_37 = V_38 ;
V_2 -> V_144 . V_37 = ~ 0 ;
F_49 ( V_99 , & V_7 -> V_42 . V_40 , V_142 ,
& V_2 -> V_42 . V_40 , V_145 ,
sizeof( V_7 -> V_42 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_42 . V_43 , V_143 ,
& V_2 -> V_42 . V_43 , V_146 ,
sizeof( V_7 -> V_42 . V_43 ) ) ;
} else if ( V_99 [ V_147 ] || V_99 [ V_148 ] ) {
V_7 -> V_144 . V_37 = V_45 ;
V_2 -> V_144 . V_37 = ~ 0 ;
F_49 ( V_99 , & V_7 -> V_47 . V_40 , V_147 ,
& V_2 -> V_47 . V_40 , V_149 ,
sizeof( V_7 -> V_47 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_47 . V_43 , V_148 ,
& V_2 -> V_47 . V_43 , V_150 ,
sizeof( V_7 -> V_47 . V_43 ) ) ;
}
if ( V_7 -> V_56 . V_140 == V_151 ) {
F_49 ( V_99 , & V_7 -> V_20 . V_40 , V_152 ,
& V_2 -> V_20 . V_40 , V_153 ,
sizeof( V_7 -> V_20 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_20 . V_43 , V_154 ,
& V_2 -> V_20 . V_43 , V_155 ,
sizeof( V_7 -> V_20 . V_43 ) ) ;
} else if ( V_7 -> V_56 . V_140 == V_156 ) {
F_49 ( V_99 , & V_7 -> V_20 . V_40 , V_157 ,
& V_2 -> V_20 . V_40 , V_158 ,
sizeof( V_7 -> V_20 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_20 . V_43 , V_159 ,
& V_2 -> V_20 . V_43 , V_160 ,
sizeof( V_7 -> V_20 . V_43 ) ) ;
} else if ( V_7 -> V_56 . V_140 == V_161 ) {
F_49 ( V_99 , & V_7 -> V_20 . V_40 , V_162 ,
& V_2 -> V_20 . V_40 , V_163 ,
sizeof( V_7 -> V_20 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_20 . V_43 , V_164 ,
& V_2 -> V_20 . V_43 , V_165 ,
sizeof( V_7 -> V_20 . V_43 ) ) ;
} else if ( V_7 -> V_56 . V_57 == F_63 ( V_138 ) &&
V_7 -> V_56 . V_140 == V_166 ) {
F_49 ( V_99 , & V_7 -> V_167 . type , V_168 ,
& V_2 -> V_167 . type ,
V_169 ,
sizeof( V_7 -> V_167 . type ) ) ;
F_49 ( V_99 , & V_7 -> V_167 . V_170 , V_171 ,
& V_2 -> V_167 . V_170 ,
V_172 ,
sizeof( V_7 -> V_167 . V_170 ) ) ;
} else if ( V_7 -> V_56 . V_57 == F_63 ( V_139 ) &&
V_7 -> V_56 . V_140 == V_173 ) {
F_49 ( V_99 , & V_7 -> V_167 . type , V_174 ,
& V_2 -> V_167 . type ,
V_175 ,
sizeof( V_7 -> V_167 . type ) ) ;
F_49 ( V_99 , & V_7 -> V_167 . V_170 , V_176 ,
& V_2 -> V_167 . V_170 ,
V_177 ,
sizeof( V_7 -> V_167 . V_170 ) ) ;
}
if ( V_99 [ V_178 ] ||
V_99 [ V_179 ] ) {
V_7 -> V_36 . V_37 = V_38 ;
V_2 -> V_36 . V_37 = ~ 0 ;
F_49 ( V_99 , & V_7 -> V_39 . V_40 ,
V_178 ,
& V_2 -> V_39 . V_40 ,
V_180 ,
sizeof( V_7 -> V_39 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_39 . V_43 ,
V_179 ,
& V_2 -> V_39 . V_43 ,
V_181 ,
sizeof( V_7 -> V_39 . V_43 ) ) ;
}
if ( V_99 [ V_182 ] ||
V_99 [ V_183 ] ) {
V_7 -> V_36 . V_37 = V_45 ;
V_2 -> V_36 . V_37 = ~ 0 ;
F_49 ( V_99 , & V_7 -> V_46 . V_40 ,
V_182 ,
& V_2 -> V_46 . V_40 ,
V_184 ,
sizeof( V_7 -> V_46 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_46 . V_43 ,
V_183 ,
& V_2 -> V_46 . V_43 ,
V_185 ,
sizeof( V_7 -> V_46 . V_43 ) ) ;
}
F_49 ( V_99 , & V_7 -> V_48 . V_49 , V_186 ,
& V_2 -> V_48 . V_49 , V_104 ,
sizeof( V_7 -> V_48 . V_49 ) ) ;
F_49 ( V_99 , & V_7 -> V_51 . V_40 , V_187 ,
& V_2 -> V_51 . V_40 , V_188 ,
sizeof( V_7 -> V_51 . V_40 ) ) ;
F_49 ( V_99 , & V_7 -> V_51 . V_43 , V_189 ,
& V_2 -> V_51 . V_43 , V_190 ,
sizeof( V_7 -> V_51 . V_43 ) ) ;
if ( V_99 [ V_122 ] )
V_127 = F_56 ( V_99 , & V_7 -> V_144 . V_61 , & V_2 -> V_144 . V_61 ) ;
return V_127 ;
}
static bool F_65 ( struct V_1 * V_191 ,
struct V_1 * V_192 )
{
const long * V_193 = F_5 ( & V_191 -> V_7 , V_191 ) ;
const long * V_194 = F_5 ( & V_192 -> V_7 , V_192 ) ;
return ! memcmp ( & V_191 -> V_3 , & V_192 -> V_3 , sizeof( V_191 -> V_3 ) ) &&
! memcmp ( V_193 , V_194 , F_1 ( V_191 ) ) ;
}
static int F_66 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
V_24 -> V_60 = V_195 ;
V_24 -> V_60 . V_196 = F_1 ( V_2 ) ;
V_24 -> V_60 . V_197 += V_2 -> V_3 . V_5 ;
return F_67 ( & V_24 -> V_32 , & V_24 -> V_60 ) ;
}
static void F_68 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_198 V_199 [ V_200 ] ;
T_2 V_201 = 0 ;
F_69 ( V_199 , V_201 , V_202 , V_144 ) ;
F_69 ( V_199 , V_201 , V_203 , V_56 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_204 , V_129 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_38 , V_42 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_45 , V_47 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_205 , V_20 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_206 , V_167 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_207 , V_136 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_208 , V_48 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_209 , V_39 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_210 , V_46 ) ;
if ( F_71 ( & V_2 -> V_7 , V_39 ) ||
F_71 ( & V_2 -> V_7 , V_46 ) )
F_69 ( V_199 , V_201 , V_211 ,
V_36 ) ;
F_70 ( & V_2 -> V_7 , V_199 , V_201 ,
V_212 , V_51 ) ;
F_72 ( & V_24 -> V_59 , V_199 , V_201 ) ;
}
static int F_73 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
int V_86 ;
if ( V_24 -> V_94 ) {
if ( ! F_65 ( & V_24 -> V_2 , V_2 ) )
return - V_87 ;
else
return 0 ;
}
V_86 = F_66 ( V_24 , V_2 ) ;
if ( V_86 )
return V_86 ;
memcpy ( & V_24 -> V_2 , V_2 , sizeof( V_24 -> V_2 ) ) ;
V_24 -> V_94 = true ;
F_68 ( V_24 , V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_125 * V_125 , struct V_19 * V_20 ,
struct V_26 * V_27 , struct V_1 * V_2 ,
unsigned long V_213 , struct V_98 * * V_99 ,
struct V_98 * V_214 , bool V_215 )
{
struct V_216 V_217 ;
int V_86 ;
V_86 = F_75 ( & V_217 , V_218 , 0 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_76 ( V_125 , V_20 , V_99 , V_214 , & V_217 , V_215 ) ;
if ( V_86 < 0 )
goto V_219;
if ( V_99 [ V_220 ] ) {
V_27 -> V_22 . V_221 = F_58 ( V_99 [ V_220 ] ) ;
F_77 ( V_20 , & V_27 -> V_22 , V_213 ) ;
}
V_86 = F_59 ( V_125 , V_99 , & V_27 -> V_7 , & V_2 -> V_7 ) ;
if ( V_86 )
goto V_219;
F_2 ( V_2 ) ;
F_6 ( & V_27 -> V_13 , & V_27 -> V_7 , V_2 ) ;
F_78 ( V_20 , & V_27 -> V_62 , & V_217 ) ;
return 0 ;
V_219:
F_24 ( & V_217 ) ;
return V_86 ;
}
static T_3 F_79 ( struct V_19 * V_20 ,
struct V_23 * V_24 )
{
unsigned int V_9 = 0x80000000 ;
T_3 V_83 ;
do {
if ( ++ V_24 -> V_222 == 0x7FFFFFFF )
V_24 -> V_222 = 1 ;
} while ( -- V_9 > 0 && F_47 ( V_20 , V_24 -> V_222 ) );
if ( F_80 ( V_9 == 0 ) ) {
F_81 ( L_1 ) ;
V_83 = 0 ;
} else {
V_83 = V_24 -> V_222 ;
}
return V_83 ;
}
static int F_82 ( struct V_125 * V_125 , struct V_17 * V_223 ,
struct V_19 * V_20 , unsigned long V_213 ,
T_3 V_83 , struct V_98 * * V_224 ,
unsigned long * V_225 , bool V_215 )
{
struct V_23 * V_24 = F_43 ( V_20 -> V_25 ) ;
struct V_26 * V_226 = (struct V_26 * ) * V_225 ;
struct V_26 * V_227 ;
struct V_98 * V_99 [ V_228 + 1 ] ;
struct V_1 V_2 = {} ;
int V_86 ;
if ( ! V_224 [ V_229 ] )
return - V_87 ;
V_86 = F_83 ( V_99 , V_228 , V_224 [ V_229 ] , V_230 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_226 && V_83 && V_226 -> V_83 != V_83 )
return - V_87 ;
V_227 = F_19 ( sizeof( * V_227 ) , V_63 ) ;
if ( ! V_227 )
return - V_64 ;
V_86 = F_75 ( & V_227 -> V_62 , V_218 , 0 ) ;
if ( V_86 < 0 )
goto V_219;
if ( ! V_83 ) {
V_83 = F_79 ( V_20 , V_24 ) ;
if ( ! V_83 ) {
V_86 = - V_87 ;
goto V_219;
}
}
V_227 -> V_83 = V_83 ;
if ( V_99 [ V_231 ] ) {
V_227 -> V_61 = F_58 ( V_99 [ V_231 ] ) ;
if ( ! F_84 ( V_227 -> V_61 ) ) {
V_86 = - V_87 ;
goto V_219;
}
}
V_86 = F_74 ( V_125 , V_20 , V_227 , & V_2 , V_213 , V_99 , V_224 [ V_232 ] , V_215 ) ;
if ( V_86 )
goto V_219;
V_86 = F_73 ( V_24 , & V_2 ) ;
if ( V_86 )
goto V_219;
if ( ! F_16 ( V_227 -> V_61 ) ) {
V_86 = F_85 ( & V_24 -> V_32 , & V_227 -> V_233 ,
V_24 -> V_60 ) ;
if ( V_86 )
goto V_219;
}
if ( ! F_33 ( V_227 -> V_61 ) ) {
V_86 = F_28 ( V_20 ,
& V_24 -> V_59 ,
& V_2 . V_7 ,
V_227 ) ;
if ( V_86 )
goto V_219;
}
if ( V_226 ) {
if ( ! F_16 ( V_226 -> V_61 ) )
F_86 ( & V_24 -> V_32 , & V_226 -> V_233 ,
V_24 -> V_60 ) ;
if ( ! F_33 ( V_226 -> V_61 ) )
F_26 ( V_20 , V_226 ) ;
}
* V_225 = ( unsigned long ) V_227 ;
if ( V_226 ) {
F_87 ( & V_226 -> V_91 , & V_227 -> V_91 ) ;
F_34 ( V_20 , & V_226 -> V_22 ) ;
F_35 ( & V_226 -> V_67 , F_22 ) ;
} else {
F_88 ( & V_227 -> V_91 , & V_24 -> V_65 ) ;
}
return 0 ;
V_219:
F_24 ( & V_227 -> V_62 ) ;
F_25 ( V_227 ) ;
return V_86 ;
}
static int F_89 ( struct V_19 * V_20 , unsigned long V_225 )
{
struct V_23 * V_24 = F_43 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_225 ;
if ( ! F_16 ( V_27 -> V_61 ) )
F_86 ( & V_24 -> V_32 , & V_27 -> V_233 ,
V_24 -> V_60 ) ;
F_31 ( V_20 , V_27 ) ;
return 0 ;
}
static void F_90 ( struct V_19 * V_20 , struct V_234 * V_225 )
{
struct V_23 * V_24 = F_43 ( V_20 -> V_25 ) ;
struct V_26 * V_27 ;
F_91 (f, &head->filters, list) {
if ( V_225 -> V_235 < V_225 -> V_236 )
goto V_236;
if ( V_225 -> V_237 ( V_20 , ( unsigned long ) V_27 , V_225 ) < 0 ) {
V_225 -> V_238 = 1 ;
break;
}
V_236:
V_225 -> V_235 ++ ;
}
}
static int F_92 ( struct V_17 * V_18 ,
void * V_100 , int V_101 ,
void * V_2 , int V_102 , int V_103 )
{
int V_86 ;
if ( ! F_93 ( V_2 , 0 , V_103 ) )
return 0 ;
V_86 = F_94 ( V_18 , V_101 , V_103 , V_100 ) ;
if ( V_86 )
return V_86 ;
if ( V_102 != V_104 ) {
V_86 = F_94 ( V_18 , V_102 , V_103 , V_2 ) ;
if ( V_86 )
return V_86 ;
}
return 0 ;
}
static int F_95 ( struct V_17 * V_18 ,
struct V_105 * V_239 ,
struct V_105 * V_240 )
{
int V_86 ;
if ( ! F_93 ( V_240 , 0 , sizeof( * V_240 ) ) )
return 0 ;
if ( V_240 -> V_109 ) {
V_86 = F_96 ( V_18 , V_108 ,
V_239 -> V_109 ) ;
if ( V_86 )
return V_86 ;
}
if ( V_240 -> V_112 ) {
V_86 = F_97 ( V_18 , V_111 ,
V_239 -> V_112 ) ;
if ( V_86 )
return V_86 ;
}
return 0 ;
}
static void F_98 ( T_3 V_115 , T_3 V_116 ,
T_3 * V_113 , T_3 * V_114 ,
T_3 V_117 , T_3 V_118 )
{
if ( V_116 & V_118 ) {
* V_114 |= V_117 ;
if ( V_115 & V_118 )
* V_113 |= V_117 ;
}
}
static int F_99 ( struct V_17 * V_18 , T_3 V_119 , T_3 V_120 )
{
T_3 V_7 , V_2 ;
T_5 V_241 , V_242 ;
int V_86 ;
if ( ! F_93 ( & V_120 , 0 , sizeof( V_120 ) ) )
return 0 ;
V_7 = 0 ;
V_2 = 0 ;
F_98 ( V_119 , V_120 , & V_7 , & V_2 ,
V_123 , V_124 ) ;
V_241 = F_100 ( V_7 ) ;
V_242 = F_100 ( V_2 ) ;
V_86 = F_94 ( V_18 , V_122 , 4 , & V_241 ) ;
if ( V_86 )
return V_86 ;
return F_94 ( V_18 , V_121 , 4 , & V_242 ) ;
}
static int F_101 ( struct V_125 * V_125 , struct V_19 * V_20 , unsigned long V_243 ,
struct V_17 * V_18 , struct V_244 * V_245 )
{
struct V_23 * V_24 = F_43 ( V_20 -> V_25 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_243 ;
struct V_98 * V_246 ;
struct V_12 * V_7 , * V_2 ;
if ( ! V_27 )
return V_18 -> V_103 ;
V_245 -> V_247 = V_27 -> V_83 ;
V_246 = F_102 ( V_18 , V_229 ) ;
if ( ! V_246 )
goto V_248;
if ( V_27 -> V_22 . V_221 &&
F_103 ( V_18 , V_220 , V_27 -> V_22 . V_221 ) )
goto V_248;
V_7 = & V_27 -> V_7 ;
V_2 = & V_24 -> V_2 . V_7 ;
if ( V_2 -> V_54 ) {
struct V_70 * V_71 ;
V_71 = F_104 ( V_125 , V_7 -> V_54 ) ;
if ( V_71 && F_105 ( V_18 , V_128 , V_71 -> V_249 ) )
goto V_248;
}
if ( ! F_33 ( V_27 -> V_61 ) )
F_30 ( V_20 , V_27 ) ;
if ( F_92 ( V_18 , V_7 -> V_129 . V_43 , V_130 ,
V_2 -> V_129 . V_43 , V_131 ,
sizeof( V_7 -> V_129 . V_43 ) ) ||
F_92 ( V_18 , V_7 -> V_129 . V_40 , V_132 ,
V_2 -> V_129 . V_40 , V_133 ,
sizeof( V_7 -> V_129 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_56 . V_57 , V_134 ,
& V_2 -> V_56 . V_57 , V_104 ,
sizeof( V_7 -> V_56 . V_57 ) ) )
goto V_248;
if ( F_95 ( V_18 , & V_7 -> V_136 , & V_2 -> V_136 ) )
goto V_248;
if ( ( V_7 -> V_56 . V_57 == F_63 ( V_138 ) ||
V_7 -> V_56 . V_57 == F_63 ( V_139 ) ) &&
F_92 ( V_18 , & V_7 -> V_56 . V_140 , V_141 ,
& V_2 -> V_56 . V_140 , V_104 ,
sizeof( V_7 -> V_56 . V_140 ) ) )
goto V_248;
if ( V_7 -> V_144 . V_37 == V_38 &&
( F_92 ( V_18 , & V_7 -> V_42 . V_40 , V_142 ,
& V_2 -> V_42 . V_40 , V_145 ,
sizeof( V_7 -> V_42 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_42 . V_43 , V_143 ,
& V_2 -> V_42 . V_43 , V_146 ,
sizeof( V_7 -> V_42 . V_43 ) ) ) )
goto V_248;
else if ( V_7 -> V_144 . V_37 == V_45 &&
( F_92 ( V_18 , & V_7 -> V_47 . V_40 , V_147 ,
& V_2 -> V_47 . V_40 , V_149 ,
sizeof( V_7 -> V_47 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_47 . V_43 , V_148 ,
& V_2 -> V_47 . V_43 , V_150 ,
sizeof( V_7 -> V_47 . V_43 ) ) ) )
goto V_248;
if ( V_7 -> V_56 . V_140 == V_151 &&
( F_92 ( V_18 , & V_7 -> V_20 . V_40 , V_152 ,
& V_2 -> V_20 . V_40 , V_153 ,
sizeof( V_7 -> V_20 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_20 . V_43 , V_154 ,
& V_2 -> V_20 . V_43 , V_155 ,
sizeof( V_7 -> V_20 . V_43 ) ) ) )
goto V_248;
else if ( V_7 -> V_56 . V_140 == V_156 &&
( F_92 ( V_18 , & V_7 -> V_20 . V_40 , V_157 ,
& V_2 -> V_20 . V_40 , V_158 ,
sizeof( V_7 -> V_20 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_20 . V_43 , V_159 ,
& V_2 -> V_20 . V_43 , V_160 ,
sizeof( V_7 -> V_20 . V_43 ) ) ) )
goto V_248;
else if ( V_7 -> V_56 . V_140 == V_161 &&
( F_92 ( V_18 , & V_7 -> V_20 . V_40 , V_162 ,
& V_2 -> V_20 . V_40 , V_163 ,
sizeof( V_7 -> V_20 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_20 . V_43 , V_164 ,
& V_2 -> V_20 . V_43 , V_165 ,
sizeof( V_7 -> V_20 . V_43 ) ) ) )
goto V_248;
else if ( V_7 -> V_56 . V_57 == F_63 ( V_138 ) &&
V_7 -> V_56 . V_140 == V_166 &&
( F_92 ( V_18 , & V_7 -> V_167 . type ,
V_168 , & V_2 -> V_167 . type ,
V_169 ,
sizeof( V_7 -> V_167 . type ) ) ||
F_92 ( V_18 , & V_7 -> V_167 . V_170 ,
V_171 , & V_2 -> V_167 . V_170 ,
V_172 ,
sizeof( V_7 -> V_167 . V_170 ) ) ) )
goto V_248;
else if ( V_7 -> V_56 . V_57 == F_63 ( V_139 ) &&
V_7 -> V_56 . V_140 == V_173 &&
( F_92 ( V_18 , & V_7 -> V_167 . type ,
V_174 , & V_2 -> V_167 . type ,
V_175 ,
sizeof( V_7 -> V_167 . type ) ) ||
F_92 ( V_18 , & V_7 -> V_167 . V_170 ,
V_176 , & V_2 -> V_167 . V_170 ,
V_177 ,
sizeof( V_7 -> V_167 . V_170 ) ) ) )
goto V_248;
if ( V_7 -> V_36 . V_37 == V_38 &&
( F_92 ( V_18 , & V_7 -> V_39 . V_40 ,
V_178 , & V_2 -> V_39 . V_40 ,
V_180 ,
sizeof( V_7 -> V_39 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_39 . V_43 ,
V_179 , & V_2 -> V_39 . V_43 ,
V_181 ,
sizeof( V_7 -> V_39 . V_43 ) ) ) )
goto V_248;
else if ( V_7 -> V_36 . V_37 == V_45 &&
( F_92 ( V_18 , & V_7 -> V_46 . V_40 ,
V_182 , & V_2 -> V_46 . V_40 ,
V_184 ,
sizeof( V_7 -> V_46 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_46 . V_43 ,
V_183 ,
& V_2 -> V_46 . V_43 ,
V_185 ,
sizeof( V_7 -> V_46 . V_43 ) ) ) )
goto V_248;
if ( F_92 ( V_18 , & V_7 -> V_48 , V_186 ,
& V_2 -> V_48 , V_104 ,
sizeof( V_7 -> V_48 ) ) ||
F_92 ( V_18 , & V_7 -> V_51 . V_40 ,
V_187 ,
& V_2 -> V_51 . V_40 ,
V_188 ,
sizeof( V_7 -> V_51 . V_40 ) ) ||
F_92 ( V_18 , & V_7 -> V_51 . V_43 ,
V_189 ,
& V_2 -> V_51 . V_43 ,
V_190 ,
sizeof( V_7 -> V_51 . V_43 ) ) )
goto V_248;
if ( F_99 ( V_18 , V_7 -> V_144 . V_61 , V_2 -> V_144 . V_61 ) )
goto V_248;
F_103 ( V_18 , V_231 , V_27 -> V_61 ) ;
if ( F_106 ( V_18 , & V_27 -> V_62 ) )
goto V_248;
F_107 ( V_18 , V_246 ) ;
if ( F_108 ( V_18 , & V_27 -> V_62 ) < 0 )
goto V_248;
return V_18 -> V_103 ;
V_248:
F_109 ( V_18 , V_246 ) ;
return - 1 ;
}
static int T_6 F_110 ( void )
{
return F_111 ( & V_250 ) ;
}
static void T_7 F_112 ( void )
{
F_113 ( & V_250 ) ;
}
