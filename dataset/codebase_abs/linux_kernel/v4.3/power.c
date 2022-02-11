static
int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
F_2 ( V_2 , L_1 ,
F_3 ( V_4 -> V_6 ) ) ;
F_2 ( V_2 , L_2 ,
F_3 ( V_4 -> V_7 ) ) ;
F_2 ( V_2 , L_3 ,
F_3 ( V_4 -> V_8 ) ) ;
F_2 ( V_2 , L_4 ,
F_3 ( V_4 -> V_9 ) ) ;
F_2 ( V_2 , L_5 ,
F_3 ( V_4 -> V_10 ) ) ;
F_2 ( V_2 , L_6 ,
F_3 ( V_4 -> V_11 ) ) ;
F_2 ( V_2 , L_7 ,
F_3 ( V_4 -> V_12 ) ) ;
F_2 ( V_2 , L_8 ,
F_3 ( V_4 -> V_13 ) ) ;
F_2 ( V_2 , L_9 ,
F_3 ( V_4 -> V_14 ) ) ;
F_2 ( V_2 , L_10 ,
F_3 ( V_4 -> V_15 ) ) ;
F_2 ( V_2 , L_11 ,
F_3 ( V_4 -> V_16 ) ) ;
return F_4 ( V_2 , V_17 , V_5 ,
sizeof( struct V_3 ) , V_4 ) ;
}
static
void F_5 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 ,
bool V_20 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
if ( V_19 -> V_23 . V_24 && ! V_20 ) {
V_4 -> V_10 =
F_7 ( V_19 -> V_23 . V_25 ) ;
V_4 -> V_13 =
F_7 ( - V_19 -> V_23 . V_24 ) ;
}
V_4 -> V_6 = F_7 ( V_22 -> V_26 . V_27 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_28 * V_4 )
{
F_2 ( V_2 ,
L_12 ,
V_4 -> V_29 , V_30 . V_31 ,
F_9 ( V_4 -> V_5 ) ) ;
F_2 ( V_2 , L_13 ,
F_9 ( V_4 -> V_32 ) ) ;
if ( ! ( V_4 -> V_5 & F_10 ( V_33 ) ) ) {
F_2 ( V_2 , L_14 ) ;
return;
}
F_2 ( V_2 , L_15 ,
F_3 ( V_4 -> V_34 ) ) ;
F_2 ( V_2 , L_16 ,
F_3 ( V_4 -> V_35 ) ) ;
if ( V_4 -> V_5 & F_10 ( V_36 ) )
F_2 ( V_2 , L_17 ,
V_4 -> V_37 ) ;
if ( V_4 -> V_5 & F_10 ( V_38 ) )
F_2 ( V_2 , L_18 ,
V_4 -> V_39 ) ;
if ( V_4 -> V_5 & F_10 ( V_40 ) ) {
F_2 ( V_2 , L_19 ) ;
F_2 ( V_2 , L_20 ,
F_3 ( V_4 -> V_41 ) ) ;
F_2 ( V_2 , L_21 ,
F_3 ( V_4 -> V_42 ) ) ;
F_2 ( V_2 , L_22 , V_4 -> V_43 ) ;
F_2 ( V_2 , L_23 , V_4 -> V_44 ) ;
F_2 ( V_2 , L_24 , V_4 -> V_45 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_28 * V_4 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
enum V_46 V_47 ;
bool V_48 = false ;
for ( V_47 = V_49 ; V_47 <= V_50 ; V_47 ++ ) {
if ( ! V_22 -> V_51 [ V_47 ] . V_52 )
continue;
if ( V_2 -> V_53 != V_54 )
V_4 -> V_5 |=
F_10 ( V_40 ) ;
V_4 -> V_44 |= F_12 ( V_47 ) ;
if ( ! V_48 && ! V_22 -> V_51 [ V_47 ] . V_55 ) {
V_48 = true ;
switch ( V_47 ) {
case V_49 :
V_4 -> V_43 = 6 ;
break;
case V_56 :
V_4 -> V_43 = 5 ;
break;
case V_57 :
V_4 -> V_43 = 0 ;
break;
case V_50 :
V_4 -> V_43 = 1 ;
break;
}
}
}
if ( ! ( V_4 -> V_5 & F_10 ( V_40 ) ) ) {
#ifdef F_13
if ( V_22 -> V_58 . V_59 )
V_4 -> V_5 |=
F_10 ( V_40 ) ;
#endif
return;
}
V_4 -> V_5 |= F_10 ( V_60 ) ;
if ( V_4 -> V_44 == ( F_12 ( V_49 ) |
F_12 ( V_56 ) |
F_12 ( V_57 ) |
F_12 ( V_50 ) ) ) {
V_4 -> V_5 |= F_10 ( V_61 ) ;
V_4 -> V_62 = F_10 ( V_63 ) ;
V_4 -> V_64 = ( V_2 -> V_53 == V_54 ) ?
F_10 ( V_65 ) :
F_10 ( V_66 ) ;
}
V_4 -> V_45 = V_67 ;
if ( V_2 -> V_53 == V_54 || V_4 -> V_5 &
F_10 ( V_61 ) ) {
V_4 -> V_41 =
F_7 ( V_68 ) ;
V_4 -> V_42 =
F_7 ( V_69 ) ;
} else {
V_4 -> V_41 =
F_7 ( V_70 ) ;
V_4 -> V_42 =
F_7 ( V_71 ) ;
}
if ( V_4 -> V_5 & F_10 ( V_61 ) ) {
V_4 -> V_72 =
V_73 ;
V_4 -> V_74 =
V_75 ;
} else {
V_4 -> V_72 =
V_76 ;
V_4 -> V_74 =
V_77 ;
}
V_4 -> V_78 =
V_79 ;
V_4 -> V_80 =
V_81 ;
}
static bool F_14 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
if ( ! memcmp ( V_22 -> V_82 , V_19 -> V_23 . V_83 ,
V_84 ) )
return false ;
if ( V_19 -> V_85 &&
! ( V_2 -> V_86 -> V_87 . V_5 & V_88 ) )
return false ;
if ( V_19 -> V_85 &&
( V_19 -> V_23 . V_89 . V_90 &
V_91 ) )
return false ;
if ( F_15 ( V_2 ) >= 2 )
return false ;
return true ;
}
static bool F_16 ( struct V_18 * V_19 )
{
struct V_92 * V_93 ;
struct V_94 * V_95 ;
bool V_96 = false ;
F_17 () ;
V_93 = F_18 ( V_19 -> V_93 ) ;
F_19 ( ! V_93 ) ;
if ( V_93 ) {
V_95 = V_93 -> V_97 . V_95 ;
V_96 = V_95 -> V_5 & V_98 ;
}
F_20 () ;
return V_96 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_28 * V_4 )
{
int V_99 , V_100 ;
int V_101 ;
bool V_96 = false ;
struct V_21 * V_22 V_102 =
F_6 ( V_19 ) ;
V_4 -> V_29 = F_7 ( F_22 ( V_22 -> V_103 ,
V_22 -> V_104 ) ) ;
V_99 = V_19 -> V_23 . V_105 ;
V_100 = V_19 -> V_23 . V_106 ;
V_101 = F_23 ( F_24 ( 3 * V_99 * V_100 ) ,
V_107 ) ;
V_101 = F_25 ( V_101 , V_108 ) ;
V_4 -> V_32 = F_10 ( V_101 ) ;
if ( V_2 -> V_109 )
return;
V_4 -> V_5 |= F_10 ( V_110 ) ;
if ( ! V_19 -> V_23 . V_111 || ! V_22 -> V_112 ||
( F_26 ( V_22 ) && V_19 -> V_85 ) )
return;
V_4 -> V_5 |= F_10 ( V_33 ) ;
if ( V_19 -> V_23 . V_113 &&
( V_19 -> V_23 . V_113 -> V_114 == 10 ||
V_19 -> V_23 . V_113 -> V_114 == 60 ) ) {
V_4 -> V_5 |= F_10 ( V_38 ) ;
V_4 -> V_39 = V_115 ;
}
V_96 = F_16 ( V_19 ) ;
if ( ! V_96 && ( V_99 < 10 ) &&
( V_30 . V_31 == V_116 ||
V_2 -> V_53 == V_54 ) ) {
V_4 -> V_5 |= F_10 ( V_36 ) ;
V_4 -> V_37 = 3 ;
}
if ( V_2 -> V_53 != V_54 ) {
V_4 -> V_34 =
F_7 ( V_117 ) ;
V_4 -> V_35 =
F_7 ( V_118 ) ;
} else {
V_4 -> V_34 =
F_7 ( V_68 ) ;
V_4 -> V_35 =
F_7 ( V_69 ) ;
}
if ( F_14 ( V_2 , V_19 ) )
F_11 ( V_2 , V_19 , V_4 ) ;
#ifdef F_13
if ( V_22 -> V_58 . V_119 & V_120 )
V_4 -> V_32 =
F_10 ( V_22 -> V_58 . V_32 ) ;
if ( V_22 -> V_58 . V_119 & V_121 ) {
if ( V_22 -> V_58 . V_122 )
V_4 -> V_5 |=
F_10 ( V_36 ) ;
else
V_4 -> V_5 &=
F_10 ( ~ V_36 ) ;
}
if ( V_22 -> V_58 . V_119 & V_123 )
V_4 -> V_34 =
F_7 ( V_22 -> V_58 . V_34 ) ;
if ( V_22 -> V_58 . V_119 & V_124 )
V_4 -> V_35 =
F_7 ( V_22 -> V_58 . V_35 ) ;
if ( V_22 -> V_58 . V_119 & V_125 )
V_4 -> V_37 = V_22 -> V_58 . V_37 ;
if ( V_22 -> V_58 . V_119 & V_126 ) {
if ( V_22 -> V_58 . V_127 )
V_4 -> V_5 |= F_10 ( V_38 ) ;
else
V_4 -> V_5 &= F_10 ( ~ V_38 ) ;
}
if ( V_22 -> V_58 . V_119 & V_128 )
V_4 -> V_39 = V_22 -> V_58 . V_39 ;
if ( V_22 -> V_58 . V_119 & V_129 ) {
if ( V_22 -> V_58 . V_130 )
V_4 -> V_5 |=
F_10 ( V_61 ) ;
else
V_4 -> V_5 &=
F_10 ( ~ V_61 ) ;
}
if ( V_22 -> V_58 . V_119 & V_131 ) {
T_2 V_132 = V_60 ;
if ( V_22 -> V_58 . V_133 )
V_4 -> V_5 |= F_10 ( V_132 ) ;
else
V_4 -> V_5 &= F_10 ( V_132 ) ;
}
#endif
}
static int F_27 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_28 V_4 = {} ;
F_21 ( V_2 , V_19 , & V_4 ) ;
F_8 ( V_2 , & V_4 ) ;
#ifdef F_13
memcpy ( & F_6 ( V_19 ) -> V_134 , & V_4 , sizeof( V_4 ) ) ;
#endif
return F_4 ( V_2 , V_135 , 0 ,
sizeof( V_4 ) , & V_4 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_136 V_4 = {
. V_5 = F_10 ( V_137 ) ,
} ;
if ( V_30 . V_31 == V_138 )
V_2 -> V_109 = true ;
if ( V_2 -> V_109 )
V_4 . V_5 |= F_10 ( V_139 ) ;
#ifdef F_13
if ( ( V_2 -> V_53 == V_54 ) ? V_2 -> V_140 :
V_2 -> V_141 )
V_4 . V_5 &=
F_10 ( ~ V_137 ) ;
#endif
F_2 ( V_2 ,
L_25 ,
V_4 . V_5 ) ;
return F_4 ( V_2 , V_142 , 0 , sizeof( V_4 ) ,
& V_4 ) ;
}
void F_29 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
if ( memcmp ( V_19 -> V_23 . V_83 , V_22 -> V_82 ,
V_84 ) )
F_30 ( V_22 -> V_82 ) ;
}
static void F_31 ( void * V_143 , T_3 * V_144 ,
struct V_18 * V_19 )
{
T_3 * V_145 = V_143 ;
struct V_21 * V_22 = F_6 ( V_19 ) ;
if ( V_22 -> V_145 == * V_145 )
memcpy ( V_22 -> V_82 , V_19 -> V_23 . V_83 ,
V_84 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_148 * V_149 = F_33 ( V_147 ) ;
struct V_150 * V_151 = ( void * ) V_149 -> V_152 ;
T_3 V_145 = F_3 ( V_151 -> V_153 ) ;
F_34 (
V_2 -> V_154 , V_155 ,
F_31 , & V_145 ) ;
}
static void F_35 ( void * V_143 , T_3 * V_144 ,
struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
V_22 -> V_112 = false ;
}
static void F_36 ( void * V_143 , T_3 * V_144 ,
struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
bool * V_156 = V_143 ;
if ( V_22 -> V_157 )
if ( V_22 -> V_157 -> V_103 < V_158 )
* V_156 |= V_22 -> V_109 ;
}
static void F_37 ( void * V_143 , T_3 * V_144 ,
struct V_18 * V_19 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_159 * V_160 = V_143 ;
switch ( F_38 ( V_19 ) ) {
case V_161 :
break;
case V_162 :
case V_163 :
F_19 ( V_160 -> V_164 ) ;
V_160 -> V_164 = V_19 ;
if ( V_22 -> V_157 )
if ( V_22 -> V_157 -> V_103 < V_158 )
V_160 -> V_165 = true ;
break;
case V_166 :
F_19 ( V_160 -> V_167 ) ;
V_160 -> V_167 = V_19 ;
if ( V_22 -> V_157 )
if ( V_22 -> V_157 -> V_103 < V_158 )
V_160 -> V_168 = true ;
break;
case V_169 :
F_19 ( V_160 -> V_170 ) ;
V_160 -> V_170 = V_19 ;
if ( V_22 -> V_157 )
if ( V_22 -> V_157 -> V_103 < V_158 )
V_160 -> V_171 = true ;
break;
case V_172 :
F_19 ( V_160 -> V_173 ) ;
V_160 -> V_173 = V_19 ;
if ( V_22 -> V_157 )
if ( V_22 -> V_157 -> V_103 < V_158 )
V_160 -> V_174 = true ;
if ( V_22 -> V_26 . V_175 &&
! F_19 ( V_160 -> V_176 ) )
V_160 -> V_176 = V_19 ;
break;
default:
break;
}
}
static void F_39 ( struct V_1 * V_2 ,
struct V_159 * V_177 )
{
struct V_21 * V_178 = NULL ;
struct V_21 * V_179 = NULL ;
struct V_21 * V_180 = NULL ;
bool V_181 = false ;
bool V_182 = false ;
F_40 ( & V_2 -> V_183 ) ;
F_34 ( V_2 -> V_154 ,
V_155 ,
F_35 ,
NULL ) ;
if ( V_177 -> V_173 )
V_178 = F_6 ( V_177 -> V_173 ) ;
if ( V_177 -> V_170 )
V_179 = F_6 ( V_177 -> V_170 ) ;
if ( V_177 -> V_164 )
V_180 = F_6 ( V_177 -> V_164 ) ;
if ( F_41 ( V_2 , NULL ) )
return;
if ( V_177 -> V_174 && ! V_177 -> V_171 && ! V_177 -> V_165 ) {
V_178 -> V_112 = true ;
return;
}
if ( V_177 -> V_171 && ! V_177 -> V_174 && ! V_177 -> V_165 ) {
if ( V_2 -> V_86 -> V_87 . V_5 & V_184 )
V_179 -> V_112 = true ;
return;
}
if ( V_177 -> V_174 && V_177 -> V_171 )
V_181 = ( V_178 -> V_157 -> V_103 ==
V_179 -> V_157 -> V_103 ) ;
if ( V_177 -> V_174 && V_177 -> V_165 )
V_182 = ( V_178 -> V_157 -> V_103 ==
V_180 -> V_157 -> V_103 ) ;
if ( ! ( V_181 || V_182 ) &&
( V_2 -> V_86 -> V_87 . V_5 & V_185 ) ) {
if ( V_177 -> V_174 )
V_178 -> V_112 = true ;
if ( V_177 -> V_171 &&
( V_2 -> V_86 -> V_87 . V_5 & V_184 ) )
V_179 -> V_112 = true ;
return;
}
if ( V_181 && ! V_177 -> V_165 &&
( V_2 -> V_86 -> V_87 . V_5 & V_186 ) ) {
V_178 -> V_112 = true ;
if ( V_2 -> V_86 -> V_87 . V_5 & V_184 )
V_179 -> V_112 = true ;
}
}
int F_42 ( struct V_1 * V_2 ,
struct V_18 * V_19 , char * V_187 ,
int V_188 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_28 V_4 = {} ;
int V_189 = 0 ;
F_43 ( & V_2 -> V_183 ) ;
memcpy ( & V_4 , & V_22 -> V_134 , sizeof( V_4 ) ) ;
F_44 ( & V_2 -> V_183 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_26 ,
V_30 . V_31 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_27 ,
F_9 ( V_4 . V_5 ) ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_28 ,
F_9 ( V_4 . V_32 ) ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_33 ) ) )
return V_189 ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_29 ,
( V_4 . V_5 &
F_10 ( V_36 ) ) ? 1 : 0 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_30 ,
V_4 . V_37 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_40 ) ) ) {
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_31 ,
F_3 ( V_4 . V_34 ) ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_32 ,
F_3 ( V_4 . V_35 ) ) ;
}
if ( V_4 . V_5 & F_10 ( V_38 ) )
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 ,
L_33 ,
V_4 . V_39 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_40 ) ) )
return V_189 ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_34 ,
F_3 ( V_4 . V_41 ) ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_35 ,
F_3 ( V_4 . V_42 ) ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_36 , V_4 . V_43 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_37 ,
V_4 . V_44 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_38 ,
V_4 . V_45 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_39 ,
V_4 . V_72 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_40 ,
V_4 . V_74 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_41 ,
V_4 . V_78 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_42 ,
V_4 . V_80 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_43 ,
( V_4 . V_5 &
F_10 ( V_60 ) ) ?
1 : 0 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_61 ) ) )
return V_189 ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_44 ,
V_4 . V_62 ) ;
V_189 += F_45 ( V_187 + V_189 , V_188 - V_189 , L_45 ,
V_4 . V_64 ) ;
return V_189 ;
}
void
F_46 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_190 * V_191 = & V_22 -> V_191 ;
if ( V_191 -> V_119 & V_192 )
V_4 -> V_10 = F_7 ( V_191 -> V_10 ) ;
if ( V_191 -> V_119 & V_193 )
V_4 -> V_12 =
F_7 ( V_191 -> V_12 ) ;
if ( V_191 -> V_119 & V_194 )
V_4 -> V_13 = F_7 ( V_191 -> V_13 ) ;
if ( V_191 -> V_119 & V_195 )
V_4 -> V_14 =
F_7 ( V_191 -> V_14 ) ;
if ( V_191 -> V_119 & V_196 )
V_4 -> V_15 =
F_7 ( V_191 -> V_15 ) ;
if ( V_191 -> V_119 & V_197 )
V_4 -> V_16 =
F_7 ( V_191 -> V_16 ) ;
if ( V_191 -> V_119 & V_198 )
V_4 -> V_8 = F_7 ( V_191 -> V_8 ) ;
if ( V_191 -> V_119 & V_199 )
V_4 -> V_11 = F_7 ( V_191 -> V_11 ) ;
if ( V_191 -> V_119 & V_200 )
V_4 -> V_7 = F_7 ( V_191 -> V_7 ) ;
if ( V_191 -> V_119 & V_201 )
V_4 -> V_6 =
F_7 ( V_191 -> V_6 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_1 V_202 ,
bool V_20 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
int V_203 ;
if ( V_22 != V_2 -> V_204 || ! V_19 -> V_23 . V_105 ||
V_19 -> type != V_172 || V_19 -> V_85 )
return 0 ;
F_5 ( V_2 , V_19 , V_4 , V_20 ) ;
if ( ! V_20 )
F_46 ( V_19 , V_4 ) ;
V_203 = F_1 ( V_2 , V_4 , V_202 ) ;
if ( ! V_203 && ! V_20 )
V_22 -> V_26 . V_175 = true ;
return V_203 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
T_1 V_5 )
{
struct V_3 V_4 = {
V_205 ,
. V_9 = F_7 ( 1 ) ,
} ;
return F_47 ( V_2 , V_19 , & V_4 , V_5 , false ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
bool V_206 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_3 V_4 = {
V_205 ,
. V_9 = F_7 ( 1 ) ,
} ;
if ( ! V_22 -> V_26 . V_175 )
return 0 ;
if ( V_2 -> V_53 == V_54 )
V_4 . V_7 = F_7 ( V_207 ) ;
V_22 -> V_26 . V_27 = V_206 ;
return F_47 ( V_2 , V_19 , & V_4 , 0 , false ) ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
T_1 V_5 )
{
struct V_3 V_4 = {} ;
struct V_21 * V_22 = F_6 ( V_19 ) ;
int V_203 ;
if ( V_19 -> type != V_172 || V_19 -> V_85 )
return 0 ;
V_203 = F_1 ( V_2 , & V_4 , V_5 ) ;
if ( ! V_203 )
V_22 -> V_26 . V_175 = false ;
return V_203 ;
}
static int F_51 ( struct V_1 * V_2 )
{
bool V_156 ;
int V_203 ;
V_156 = ( V_30 . V_31 == V_138 ) ;
F_34 ( V_2 -> V_154 ,
V_155 ,
F_36 ,
& V_156 ) ;
if ( V_2 -> V_109 != V_156 ) {
bool V_208 = V_2 -> V_109 ;
V_2 -> V_109 = V_156 ;
V_203 = F_28 ( V_2 ) ;
if ( V_203 ) {
V_2 -> V_109 = V_208 ;
return V_203 ;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_159 * V_177 )
{
struct V_21 * V_22 ;
bool V_209 ;
if ( ! V_177 -> V_176 )
return 0 ;
V_22 = F_6 ( V_177 -> V_176 ) ;
V_209 = ! ( ! V_22 -> V_112 || V_2 -> V_109 ||
! V_177 -> V_176 -> V_23 . V_111 ||
F_26 ( V_22 ) ) ;
return F_49 ( V_2 , V_177 -> V_176 , V_209 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_159 V_177 = {
. V_2 = V_2 ,
} ;
int V_203 ;
F_40 ( & V_2 -> V_183 ) ;
F_34 ( V_2 -> V_154 ,
V_155 ,
F_37 , & V_177 ) ;
V_203 = F_51 ( V_2 ) ;
if ( V_203 )
return V_203 ;
return F_52 ( V_2 , & V_177 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_159 V_177 = {
. V_2 = V_2 ,
} ;
int V_203 ;
F_40 ( & V_2 -> V_183 ) ;
F_34 ( V_2 -> V_154 ,
V_155 ,
F_37 , & V_177 ) ;
F_39 ( V_2 , & V_177 ) ;
V_203 = F_51 ( V_2 ) ;
if ( V_203 )
return V_203 ;
if ( V_177 . V_173 ) {
V_203 = F_27 ( V_2 , V_177 . V_173 ) ;
if ( V_203 )
return V_203 ;
}
if ( V_177 . V_170 ) {
V_203 = F_27 ( V_2 , V_177 . V_170 ) ;
if ( V_203 )
return V_203 ;
}
return F_52 ( V_2 , & V_177 ) ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
bool V_206 , T_1 V_5 )
{
int V_203 ;
struct V_21 * V_22 = F_6 ( V_19 ) ;
struct V_28 V_4 = {} ;
if ( V_19 -> type != V_172 || V_19 -> V_85 )
return 0 ;
if ( ! V_19 -> V_23 . V_210 )
return 0 ;
F_21 ( V_2 , V_19 , & V_4 ) ;
if ( V_206 ) {
int V_99 = V_19 -> V_23 . V_105 ? : 1 ;
int V_211 = V_99 * V_19 -> V_23 . V_106 ;
bool V_96 = F_16 ( V_19 ) ;
if ( F_19 ( ! V_211 ) )
return 0 ;
if ( ! V_96 && ( V_99 < 10 ) ) {
V_4 . V_37 = 306 / V_211 ;
if ( V_4 . V_37 )
V_4 . V_5 |= F_10 (
V_36 ) ;
}
}
F_8 ( V_2 , & V_4 ) ;
#ifdef F_13
memcpy ( & V_22 -> V_134 , & V_4 , sizeof( V_4 ) ) ;
#endif
V_203 = F_4 ( V_2 , V_135 , V_5 ,
sizeof( V_4 ) , & V_4 ) ;
if ( V_203 )
return V_203 ;
if ( V_22 != V_2 -> V_204 )
return 0 ;
if ( V_206 ) {
struct V_3 V_212 = {
V_213 ,
. V_9 = F_7 ( 1 ) ,
} ;
V_203 = F_47 ( V_2 , V_19 , & V_212 ,
V_5 , true ) ;
} else {
if ( V_22 -> V_26 . V_175 )
V_203 = F_48 ( V_2 , V_19 , V_5 ) ;
else
V_203 = F_50 ( V_2 , V_19 , V_5 ) ;
}
return V_203 ;
}
