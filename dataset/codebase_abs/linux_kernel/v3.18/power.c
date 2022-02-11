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
struct V_3 * V_4 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
if ( V_19 -> V_22 . V_23 ) {
V_4 -> V_10 =
F_7 ( V_19 -> V_22 . V_24 ) ;
V_4 -> V_13 =
F_7 ( - V_19 -> V_22 . V_23 ) ;
}
V_4 -> V_6 = F_7 ( V_21 -> V_25 . V_26 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_27 * V_4 )
{
F_2 ( V_2 ,
L_12 ,
V_4 -> V_28 , V_29 . V_30 ,
F_9 ( V_4 -> V_5 ) ) ;
F_2 ( V_2 , L_13 ,
F_9 ( V_4 -> V_31 ) ) ;
if ( ! ( V_4 -> V_5 & F_10 ( V_32 ) ) ) {
F_2 ( V_2 , L_14 ) ;
return;
}
F_2 ( V_2 , L_15 ,
F_3 ( V_4 -> V_33 ) ) ;
F_2 ( V_2 , L_16 ,
F_3 ( V_4 -> V_34 ) ) ;
if ( V_4 -> V_5 & F_10 ( V_35 ) )
F_2 ( V_2 , L_17 ,
V_4 -> V_36 ) ;
if ( V_4 -> V_5 & F_10 ( V_37 ) )
F_2 ( V_2 , L_18 ,
V_4 -> V_38 ) ;
if ( V_4 -> V_5 & F_10 ( V_39 ) ) {
F_2 ( V_2 , L_19 ) ;
F_2 ( V_2 , L_20 ,
F_3 ( V_4 -> V_40 ) ) ;
F_2 ( V_2 , L_21 ,
F_3 ( V_4 -> V_41 ) ) ;
F_2 ( V_2 , L_22 , V_4 -> V_42 ) ;
F_2 ( V_2 , L_23 , V_4 -> V_43 ) ;
F_2 ( V_2 , L_24 , V_4 -> V_44 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_27 * V_4 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
enum V_45 V_46 ;
bool V_47 = false ;
for ( V_46 = V_48 ; V_46 <= V_49 ; V_46 ++ ) {
if ( ! V_21 -> V_50 [ V_46 ] . V_51 )
continue;
if ( V_2 -> V_52 != V_53 )
V_4 -> V_5 |=
F_10 ( V_39 ) ;
V_4 -> V_43 |= F_12 ( V_46 ) ;
if ( ! V_47 && ! V_21 -> V_50 [ V_46 ] . V_54 ) {
V_47 = true ;
switch ( V_46 ) {
case V_48 :
V_4 -> V_42 = 6 ;
break;
case V_55 :
V_4 -> V_42 = 5 ;
break;
case V_56 :
V_4 -> V_42 = 0 ;
break;
case V_49 :
V_4 -> V_42 = 1 ;
break;
}
}
}
if ( ! ( V_4 -> V_5 & F_10 ( V_39 ) ) ) {
#ifdef F_13
if ( V_21 -> V_57 . V_58 )
V_4 -> V_5 |=
F_10 ( V_39 ) ;
#endif
return;
}
V_4 -> V_5 |= F_10 ( V_59 ) ;
if ( V_4 -> V_43 == ( F_12 ( V_48 ) |
F_12 ( V_55 ) |
F_12 ( V_56 ) |
F_12 ( V_49 ) ) ) {
V_4 -> V_5 |= F_10 ( V_60 ) ;
V_4 -> V_61 = F_10 ( V_62 ) ;
V_4 -> V_63 = ( V_2 -> V_52 == V_53 ) ?
F_10 ( V_64 ) :
F_10 ( V_65 ) ;
}
V_4 -> V_44 = V_66 ;
if ( V_2 -> V_52 == V_53 || V_4 -> V_5 &
F_10 ( V_60 ) ) {
V_4 -> V_40 =
F_7 ( V_67 ) ;
V_4 -> V_41 =
F_7 ( V_68 ) ;
} else {
V_4 -> V_40 =
F_7 ( V_69 ) ;
V_4 -> V_41 =
F_7 ( V_70 ) ;
}
if ( V_4 -> V_5 & F_10 ( V_60 ) ) {
V_4 -> V_71 =
V_72 ;
V_4 -> V_73 =
V_74 ;
} else {
V_4 -> V_71 =
V_75 ;
V_4 -> V_73 =
V_76 ;
}
V_4 -> V_77 =
V_78 ;
V_4 -> V_79 =
V_80 ;
}
static bool F_14 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
if ( ! memcmp ( V_21 -> V_81 , V_19 -> V_22 . V_82 ,
V_83 ) )
return false ;
if ( V_19 -> V_84 &&
! ( V_2 -> V_85 -> V_86 . V_5 & V_87 ) )
return false ;
if ( V_19 -> V_84 &&
( V_19 -> V_22 . V_88 . V_89 &
V_90 ) )
return false ;
if ( F_15 ( V_2 ) >= 2 )
return false ;
return true ;
}
static bool F_16 ( struct V_18 * V_19 )
{
struct V_91 * V_92 ;
struct V_93 * V_94 ;
bool V_95 = false ;
F_17 () ;
V_92 = F_18 ( V_19 -> V_92 ) ;
F_19 ( ! V_92 ) ;
if ( V_92 ) {
V_94 = V_92 -> V_96 . V_94 ;
V_95 = V_94 -> V_5 & V_97 ;
}
F_20 () ;
return V_95 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_27 * V_4 )
{
int V_98 , V_99 ;
int V_100 ;
bool V_95 = false ;
struct V_20 * V_21 V_101 =
F_6 ( V_19 ) ;
V_4 -> V_28 = F_7 ( F_22 ( V_21 -> V_102 ,
V_21 -> V_103 ) ) ;
V_98 = V_19 -> V_22 . V_104 ;
V_99 = V_98 * V_19 -> V_22 . V_105 ;
V_100 = F_23 ( int , 3 * V_99 ,
V_106 * V_107 ) ;
V_100 = F_24 ( V_100 , V_106 ) ;
V_4 -> V_31 = F_10 ( V_100 ) ;
if ( V_2 -> V_108 )
return;
V_4 -> V_5 |= F_10 ( V_109 ) ;
if ( ! V_19 -> V_22 . V_110 || F_25 ( V_21 ) ||
! V_21 -> V_111 || F_26 ( V_2 , V_19 ) )
return;
V_4 -> V_5 |= F_10 ( V_32 ) ;
if ( V_19 -> V_22 . V_112 &&
( V_19 -> V_22 . V_112 -> V_113 == 10 ||
V_19 -> V_22 . V_112 -> V_113 == 60 ) ) {
V_4 -> V_5 |= F_10 ( V_37 ) ;
V_4 -> V_38 = V_114 ;
}
V_95 = F_16 ( V_19 ) ;
if ( ! V_95 && ( V_98 <= 10 ) &&
( V_29 . V_30 == V_115 ||
V_2 -> V_52 == V_53 ) ) {
V_4 -> V_5 |= F_10 ( V_35 ) ;
V_4 -> V_36 = 3 ;
}
if ( V_2 -> V_52 != V_53 ) {
V_4 -> V_33 =
F_7 ( V_116 ) ;
V_4 -> V_34 =
F_7 ( V_117 ) ;
} else {
V_4 -> V_33 =
F_7 ( V_67 ) ;
V_4 -> V_34 =
F_7 ( V_68 ) ;
}
if ( F_14 ( V_2 , V_19 ) )
F_11 ( V_2 , V_19 , V_4 ) ;
#ifdef F_13
if ( V_21 -> V_57 . V_118 & V_119 )
V_4 -> V_31 =
F_10 ( V_21 -> V_57 . V_31 ) ;
if ( V_21 -> V_57 . V_118 & V_120 ) {
if ( V_21 -> V_57 . V_121 )
V_4 -> V_5 |=
F_10 ( V_35 ) ;
else
V_4 -> V_5 &=
F_10 ( ~ V_35 ) ;
}
if ( V_21 -> V_57 . V_118 & V_122 )
V_4 -> V_33 =
F_7 ( V_21 -> V_57 . V_33 ) ;
if ( V_21 -> V_57 . V_118 & V_123 )
V_4 -> V_34 =
F_7 ( V_21 -> V_57 . V_34 ) ;
if ( V_21 -> V_57 . V_118 & V_124 )
V_4 -> V_36 = V_21 -> V_57 . V_36 ;
if ( V_21 -> V_57 . V_118 & V_125 ) {
if ( V_21 -> V_57 . V_126 )
V_4 -> V_5 |= F_10 ( V_37 ) ;
else
V_4 -> V_5 &= F_10 ( ~ V_37 ) ;
}
if ( V_21 -> V_57 . V_118 & V_127 )
V_4 -> V_38 = V_21 -> V_57 . V_38 ;
if ( V_21 -> V_57 . V_118 & V_128 ) {
if ( V_21 -> V_57 . V_129 )
V_4 -> V_5 |=
F_10 ( V_60 ) ;
else
V_4 -> V_5 &=
F_10 ( ~ V_60 ) ;
}
if ( V_21 -> V_57 . V_118 & V_130 ) {
T_2 V_131 = V_59 ;
if ( V_21 -> V_57 . V_132 )
V_4 -> V_5 |= F_10 ( V_131 ) ;
else
V_4 -> V_5 &= F_10 ( V_131 ) ;
}
#endif
}
static int F_27 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_27 V_4 = {} ;
F_21 ( V_2 , V_19 , & V_4 ) ;
F_8 ( V_2 , & V_4 ) ;
#ifdef F_13
memcpy ( & F_6 ( V_19 ) -> V_133 , & V_4 , sizeof( V_4 ) ) ;
#endif
return F_4 ( V_2 , V_134 , 0 ,
sizeof( V_4 ) , & V_4 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_135 V_4 = {
. V_5 = F_10 ( V_136 ) ,
} ;
if ( V_29 . V_30 == V_137 )
V_2 -> V_108 = true ;
if ( V_2 -> V_108 )
V_4 . V_5 |= F_10 ( V_138 ) ;
#ifdef F_13
if ( ( V_2 -> V_52 == V_53 ) ? V_2 -> V_139 :
V_2 -> V_140 )
V_4 . V_5 &=
F_10 ( ~ V_136 ) ;
#endif
F_2 ( V_2 ,
L_25 ,
V_4 . V_5 ) ;
return F_4 ( V_2 , V_141 , 0 , sizeof( V_4 ) ,
& V_4 ) ;
}
void F_29 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
if ( memcmp ( V_19 -> V_22 . V_82 , V_21 -> V_81 ,
V_83 ) )
memset ( V_21 -> V_81 , 0 , V_83 ) ;
}
static void F_30 ( void * V_142 , T_3 * V_143 ,
struct V_18 * V_19 )
{
T_3 * V_144 = V_142 ;
struct V_20 * V_21 = F_6 ( V_19 ) ;
if ( V_21 -> V_144 == * V_144 )
memcpy ( V_21 -> V_81 , V_19 -> V_22 . V_82 ,
V_83 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
struct V_147 * V_4 )
{
struct V_148 * V_149 = F_32 ( V_146 ) ;
struct V_150 * V_151 = ( void * ) V_149 -> V_152 ;
T_3 V_144 = F_3 ( V_151 -> V_153 ) ;
F_33 (
V_2 -> V_154 , V_155 ,
F_30 , & V_144 ) ;
return 0 ;
}
static void F_34 ( void * V_142 , T_3 * V_143 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
V_21 -> V_111 = false ;
}
static void F_35 ( void * V_142 , T_3 * V_143 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
bool * V_156 = V_142 ;
if ( V_21 -> V_157 )
if ( V_21 -> V_157 -> V_102 < V_158 )
* V_156 |= V_21 -> V_108 ;
}
static void F_36 ( void * V_142 , T_3 * V_143 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_159 * V_160 = V_142 ;
switch ( F_37 ( V_19 ) ) {
case V_161 :
break;
case V_162 :
case V_163 :
F_19 ( V_160 -> V_164 ) ;
V_160 -> V_164 = V_19 ;
if ( V_21 -> V_157 )
if ( V_21 -> V_157 -> V_102 < V_158 )
V_160 -> V_165 = true ;
break;
case V_166 :
F_19 ( V_160 -> V_167 ) ;
V_160 -> V_167 = V_19 ;
if ( V_21 -> V_157 )
if ( V_21 -> V_157 -> V_102 < V_158 )
V_160 -> V_168 = true ;
break;
case V_169 :
F_19 ( V_160 -> V_170 ) ;
V_160 -> V_170 = V_19 ;
if ( V_21 -> V_157 )
if ( V_21 -> V_157 -> V_102 < V_158 )
V_160 -> V_171 = true ;
break;
case V_172 :
F_19 ( V_160 -> V_173 ) ;
V_160 -> V_173 = V_19 ;
if ( V_21 -> V_157 )
if ( V_21 -> V_157 -> V_102 < V_158 )
V_160 -> V_174 = true ;
if ( V_21 -> V_25 . V_175 &&
! F_19 ( V_160 -> V_176 ) )
V_160 -> V_176 = V_19 ;
break;
default:
break;
}
}
static void F_38 ( struct V_1 * V_2 ,
struct V_159 * V_177 )
{
struct V_20 * V_178 = NULL ;
struct V_20 * V_179 = NULL ;
struct V_20 * V_180 = NULL ;
bool V_181 = false ;
bool V_182 = false ;
F_39 ( & V_2 -> V_183 ) ;
F_33 ( V_2 -> V_154 ,
V_155 ,
F_34 ,
NULL ) ;
if ( V_177 -> V_173 )
V_178 = F_6 ( V_177 -> V_173 ) ;
if ( V_177 -> V_170 )
V_179 = F_6 ( V_177 -> V_170 ) ;
if ( V_177 -> V_164 )
V_180 = F_6 ( V_177 -> V_164 ) ;
if ( V_177 -> V_174 && ! V_177 -> V_171 && ! V_177 -> V_165 ) {
V_178 -> V_111 = true ;
return;
}
if ( V_177 -> V_171 && ! V_177 -> V_174 && ! V_177 -> V_165 ) {
if ( V_2 -> V_85 -> V_86 . V_5 & V_184 )
V_179 -> V_111 = true ;
return;
}
if ( V_177 -> V_174 && V_177 -> V_171 )
V_181 = ( V_178 -> V_157 -> V_102 ==
V_179 -> V_157 -> V_102 ) ;
if ( V_177 -> V_174 && V_177 -> V_165 )
V_182 = ( V_178 -> V_157 -> V_102 ==
V_180 -> V_157 -> V_102 ) ;
if ( ! ( V_181 || V_182 ) &&
( V_2 -> V_85 -> V_86 . V_5 & V_185 ) ) {
if ( V_177 -> V_174 )
V_178 -> V_111 = true ;
if ( V_177 -> V_171 &&
( V_2 -> V_85 -> V_86 . V_5 & V_184 ) )
V_179 -> V_111 = true ;
return;
}
if ( V_181 && ! V_177 -> V_165 &&
( V_2 -> V_85 -> V_86 . V_5 & V_186 ) ) {
V_178 -> V_111 = true ;
if ( V_2 -> V_85 -> V_86 . V_5 & V_184 )
V_179 -> V_111 = true ;
}
}
int F_40 ( struct V_1 * V_2 ,
struct V_18 * V_19 , char * V_187 ,
int V_188 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_27 V_4 = {} ;
int V_189 = 0 ;
F_41 ( & V_2 -> V_183 ) ;
memcpy ( & V_4 , & V_21 -> V_133 , sizeof( V_4 ) ) ;
F_42 ( & V_2 -> V_183 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_26 ,
V_29 . V_30 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_27 ,
F_9 ( V_4 . V_5 ) ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_28 ,
F_9 ( V_4 . V_31 ) ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_32 ) ) )
return V_189 ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_29 ,
( V_4 . V_5 &
F_10 ( V_35 ) ) ? 1 : 0 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_30 ,
V_4 . V_36 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_39 ) ) ) {
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_31 ,
F_3 ( V_4 . V_33 ) ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_32 ,
F_3 ( V_4 . V_34 ) ) ;
}
if ( V_4 . V_5 & F_10 ( V_37 ) )
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 ,
L_33 ,
V_4 . V_38 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_39 ) ) )
return V_189 ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_34 ,
F_3 ( V_4 . V_40 ) ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_35 ,
F_3 ( V_4 . V_41 ) ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_36 , V_4 . V_42 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_37 ,
V_4 . V_43 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_38 ,
V_4 . V_44 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_39 ,
V_4 . V_71 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_40 ,
V_4 . V_73 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_41 ,
V_4 . V_77 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_42 ,
V_4 . V_79 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_43 ,
( V_4 . V_5 &
F_10 ( V_59 ) ) ?
1 : 0 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_60 ) ) )
return V_189 ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_44 ,
V_4 . V_61 ) ;
V_189 += F_43 ( V_187 + V_189 , V_188 - V_189 , L_45 ,
V_4 . V_63 ) ;
return V_189 ;
}
void
F_44 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_190 * V_191 = & V_21 -> V_191 ;
if ( V_191 -> V_118 & V_192 )
V_4 -> V_10 = F_7 ( V_191 -> V_10 ) ;
if ( V_191 -> V_118 & V_193 )
V_4 -> V_12 =
F_7 ( V_191 -> V_12 ) ;
if ( V_191 -> V_118 & V_194 )
V_4 -> V_13 = F_7 ( V_191 -> V_13 ) ;
if ( V_191 -> V_118 & V_195 )
V_4 -> V_14 =
F_7 ( V_191 -> V_14 ) ;
if ( V_191 -> V_118 & V_196 )
V_4 -> V_15 =
F_7 ( V_191 -> V_15 ) ;
if ( V_191 -> V_118 & V_197 )
V_4 -> V_16 =
F_7 ( V_191 -> V_16 ) ;
if ( V_191 -> V_118 & V_198 )
V_4 -> V_8 = F_7 ( V_191 -> V_8 ) ;
if ( V_191 -> V_118 & V_199 )
V_4 -> V_11 = F_7 ( V_191 -> V_11 ) ;
if ( V_191 -> V_118 & V_200 )
V_4 -> V_7 = F_7 ( V_191 -> V_7 ) ;
if ( V_191 -> V_118 & V_201 )
V_4 -> V_6 =
F_7 ( V_191 -> V_6 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_1 V_202 ,
bool V_203 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
int V_204 ;
if ( V_21 != V_2 -> V_205 || ! V_19 -> V_22 . V_104 ||
V_19 -> type != V_172 || V_19 -> V_84 )
return 0 ;
F_5 ( V_2 , V_19 , V_4 ) ;
if ( ! V_203 )
F_44 ( V_19 , V_4 ) ;
V_204 = F_1 ( V_2 , V_4 , V_202 ) ;
if ( ! V_204 && ! V_203 )
V_21 -> V_25 . V_175 = true ;
return V_204 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
T_1 V_5 )
{
struct V_3 V_4 = {
V_206 ,
. V_9 = F_7 ( 1 ) ,
} ;
return F_45 ( V_2 , V_19 , & V_4 , V_5 , false ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
bool V_207 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_3 V_4 = {
V_206 ,
. V_9 = F_7 ( 1 ) ,
} ;
if ( ! V_21 -> V_25 . V_175 )
return 0 ;
if ( V_2 -> V_52 == V_53 )
V_4 . V_7 = F_7 ( V_208 ) ;
V_21 -> V_25 . V_26 = V_207 ;
return F_45 ( V_2 , V_19 , & V_4 , 0 , false ) ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
T_1 V_5 )
{
struct V_3 V_4 = {} ;
struct V_20 * V_21 = F_6 ( V_19 ) ;
int V_204 ;
if ( V_19 -> type != V_172 || V_19 -> V_84 )
return 0 ;
V_204 = F_1 ( V_2 , & V_4 , V_5 ) ;
if ( ! V_204 )
V_21 -> V_25 . V_175 = false ;
return V_204 ;
}
static int F_49 ( struct V_1 * V_2 )
{
bool V_156 ;
int V_204 ;
V_156 = ( V_29 . V_30 == V_137 ) ;
F_33 ( V_2 -> V_154 ,
V_155 ,
F_35 ,
& V_156 ) ;
if ( V_2 -> V_108 != V_156 ) {
bool V_209 = V_2 -> V_108 ;
V_2 -> V_108 = V_156 ;
V_204 = F_28 ( V_2 ) ;
if ( V_204 ) {
V_2 -> V_108 = V_209 ;
return V_204 ;
}
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_159 * V_177 )
{
struct V_20 * V_21 ;
bool V_210 ;
if ( ! V_177 -> V_176 )
return 0 ;
V_21 = F_6 ( V_177 -> V_176 ) ;
V_210 = ! ( ! V_21 -> V_111 || V_2 -> V_108 ||
! V_177 -> V_176 -> V_22 . V_110 ||
F_25 ( V_21 ) ) ;
return F_47 ( V_2 , V_177 -> V_176 , V_210 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_159 V_177 = {
. V_2 = V_2 ,
} ;
int V_204 ;
F_39 ( & V_2 -> V_183 ) ;
F_33 ( V_2 -> V_154 ,
V_155 ,
F_36 , & V_177 ) ;
V_204 = F_49 ( V_2 ) ;
if ( V_204 )
return V_204 ;
return F_50 ( V_2 , & V_177 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_159 V_177 = {
. V_2 = V_2 ,
} ;
int V_204 ;
F_39 ( & V_2 -> V_183 ) ;
F_33 ( V_2 -> V_154 ,
V_155 ,
F_36 , & V_177 ) ;
F_38 ( V_2 , & V_177 ) ;
V_204 = F_49 ( V_2 ) ;
if ( V_204 )
return V_204 ;
if ( V_177 . V_173 ) {
V_204 = F_27 ( V_2 , V_177 . V_173 ) ;
if ( V_204 )
return V_204 ;
}
if ( V_177 . V_170 ) {
V_204 = F_27 ( V_2 , V_177 . V_170 ) ;
if ( V_204 )
return V_204 ;
}
return F_50 ( V_2 , & V_177 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
bool V_207 , T_1 V_5 )
{
int V_204 ;
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_27 V_4 = {} ;
if ( V_19 -> type != V_172 || V_19 -> V_84 )
return 0 ;
if ( ! V_19 -> V_22 . V_211 )
return 0 ;
F_21 ( V_2 , V_19 , & V_4 ) ;
if ( V_207 ) {
int V_98 = V_19 -> V_22 . V_104 ? : 1 ;
int V_212 = V_98 * V_19 -> V_22 . V_105 ;
bool V_95 = F_16 ( V_19 ) ;
if ( F_19 ( ! V_212 ) )
return 0 ;
if ( ! V_95 && ( V_98 < 10 ) ) {
V_4 . V_36 = 306 / V_212 ;
if ( V_4 . V_36 )
V_4 . V_5 |= F_10 (
V_35 ) ;
}
}
F_8 ( V_2 , & V_4 ) ;
#ifdef F_13
memcpy ( & V_21 -> V_133 , & V_4 , sizeof( V_4 ) ) ;
#endif
V_204 = F_4 ( V_2 , V_134 , V_5 ,
sizeof( V_4 ) , & V_4 ) ;
if ( V_204 )
return V_204 ;
if ( V_21 != V_2 -> V_205 )
return 0 ;
if ( V_207 ) {
struct V_3 V_213 = {
V_214 ,
. V_9 = F_7 ( 1 ) ,
} ;
V_204 = F_45 ( V_2 , V_19 , & V_213 ,
V_5 , true ) ;
} else {
if ( V_21 -> V_25 . V_175 )
V_204 = F_46 ( V_2 , V_19 , V_5 ) ;
else
V_204 = F_48 ( V_2 , V_19 , V_5 ) ;
}
return V_204 ;
}
