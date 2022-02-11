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
static int F_16 ( int V_91 , int V_92 )
{
int V_93 ;
int V_94 = V_91 * V_92 ;
if ( F_17 ( ! V_94 ) )
return 0 ;
if ( V_91 == 1 ) {
if ( V_92 > 100 )
V_93 = 408 ;
else
V_93 = 510 ;
} else if ( V_91 < 10 ) {
V_93 = 612 ;
} else {
return 0 ;
}
return F_18 ( 1 , ( V_93 / V_94 ) ) ;
}
static bool F_19 ( struct V_18 * V_19 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
bool V_99 = false ;
F_20 () ;
V_96 = F_21 ( V_19 -> V_96 ) ;
F_17 ( ! V_96 ) ;
if ( V_96 ) {
V_98 = V_96 -> V_100 . V_98 ;
V_99 = V_98 -> V_5 & V_101 ;
}
F_22 () ;
return V_99 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_27 * V_4 )
{
int V_91 , V_92 ;
int V_102 ;
bool V_99 = false ;
struct V_20 * V_21 V_103 =
F_6 ( V_19 ) ;
V_4 -> V_28 = F_7 ( F_24 ( V_21 -> V_104 ,
V_21 -> V_105 ) ) ;
V_91 = V_19 -> V_22 . V_106 ;
V_92 = V_19 -> V_22 . V_107 ;
V_102 = F_25 ( F_26 ( 3 * V_91 * V_92 ) ,
V_108 ) ;
V_102 = F_18 ( V_102 , V_109 ) ;
V_4 -> V_31 = F_10 ( V_102 ) ;
if ( V_2 -> V_110 )
return;
V_4 -> V_5 |= F_10 ( V_111 ) ;
if ( ! V_19 -> V_22 . V_112 || F_27 ( V_21 ) ||
! V_21 -> V_113 )
return;
V_4 -> V_5 |= F_10 ( V_32 ) ;
if ( V_19 -> V_22 . V_114 &&
( V_19 -> V_22 . V_114 -> V_115 == 10 ||
V_19 -> V_22 . V_114 -> V_115 == 60 ) ) {
V_4 -> V_5 |= F_10 ( V_37 ) ;
V_4 -> V_38 = V_116 ;
}
V_99 = F_19 ( V_19 ) ;
if ( ! V_99 && ( V_91 < 10 ) &&
( V_29 . V_30 == V_117 ||
V_2 -> V_52 == V_53 ) ) {
V_4 -> V_36 =
F_16 ( V_91 , V_92 ) ;
if ( V_4 -> V_36 )
V_4 -> V_5 |=
F_10 ( V_35 ) ;
}
if ( V_2 -> V_52 != V_53 ) {
V_4 -> V_33 =
F_7 ( V_118 ) ;
V_4 -> V_34 =
F_7 ( V_119 ) ;
} else {
V_4 -> V_33 =
F_7 ( V_67 ) ;
V_4 -> V_34 =
F_7 ( V_68 ) ;
}
if ( F_14 ( V_2 , V_19 ) )
F_11 ( V_2 , V_19 , V_4 ) ;
#ifdef F_13
if ( V_21 -> V_57 . V_120 & V_121 )
V_4 -> V_31 =
F_10 ( V_21 -> V_57 . V_31 ) ;
if ( V_21 -> V_57 . V_120 & V_122 ) {
if ( V_21 -> V_57 . V_123 )
V_4 -> V_5 |=
F_10 ( V_35 ) ;
else
V_4 -> V_5 &=
F_10 ( ~ V_35 ) ;
}
if ( V_21 -> V_57 . V_120 & V_124 )
V_4 -> V_33 =
F_7 ( V_21 -> V_57 . V_33 ) ;
if ( V_21 -> V_57 . V_120 & V_125 )
V_4 -> V_34 =
F_7 ( V_21 -> V_57 . V_34 ) ;
if ( V_21 -> V_57 . V_120 & V_126 )
V_4 -> V_36 = V_21 -> V_57 . V_36 ;
if ( V_21 -> V_57 . V_120 & V_127 ) {
if ( V_21 -> V_57 . V_128 )
V_4 -> V_5 |= F_10 ( V_37 ) ;
else
V_4 -> V_5 &= F_10 ( ~ V_37 ) ;
}
if ( V_21 -> V_57 . V_120 & V_129 )
V_4 -> V_38 = V_21 -> V_57 . V_38 ;
if ( V_21 -> V_57 . V_120 & V_130 ) {
if ( V_21 -> V_57 . V_131 )
V_4 -> V_5 |=
F_10 ( V_60 ) ;
else
V_4 -> V_5 &=
F_10 ( ~ V_60 ) ;
}
if ( V_21 -> V_57 . V_120 & V_132 ) {
T_2 V_133 = V_59 ;
if ( V_21 -> V_57 . V_134 )
V_4 -> V_5 |= F_10 ( V_133 ) ;
else
V_4 -> V_5 &= F_10 ( V_133 ) ;
}
#endif
}
static int F_28 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_27 V_4 = {} ;
F_23 ( V_2 , V_19 , & V_4 ) ;
F_8 ( V_2 , & V_4 ) ;
#ifdef F_13
memcpy ( & F_6 ( V_19 ) -> V_135 , & V_4 , sizeof( V_4 ) ) ;
#endif
return F_4 ( V_2 , V_136 , 0 ,
sizeof( V_4 ) , & V_4 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_137 V_4 = {
. V_5 = F_10 ( V_138 ) ,
} ;
if ( V_29 . V_30 == V_139 )
V_2 -> V_110 = true ;
if ( V_2 -> V_110 )
V_4 . V_5 |= F_10 ( V_140 ) ;
#ifdef F_13
if ( ( V_2 -> V_52 == V_53 ) ? V_2 -> V_141 :
V_2 -> V_142 )
V_4 . V_5 &=
F_10 ( ~ V_138 ) ;
#endif
F_2 ( V_2 ,
L_25 ,
V_4 . V_5 ) ;
return F_4 ( V_2 , V_143 , 0 , sizeof( V_4 ) ,
& V_4 ) ;
}
void F_30 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
if ( memcmp ( V_19 -> V_22 . V_82 , V_21 -> V_81 ,
V_83 ) )
F_31 ( V_21 -> V_81 ) ;
}
static void F_32 ( void * V_144 , T_3 * V_145 ,
struct V_18 * V_19 )
{
T_3 * V_146 = V_144 ;
struct V_20 * V_21 = F_6 ( V_19 ) ;
if ( V_21 -> V_146 == * V_146 )
memcpy ( V_21 -> V_81 , V_19 -> V_22 . V_82 ,
V_83 ) ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_147 * V_148 ,
struct V_149 * V_4 )
{
struct V_150 * V_151 = F_34 ( V_148 ) ;
struct V_152 * V_153 = ( void * ) V_151 -> V_154 ;
T_3 V_146 = F_3 ( V_153 -> V_155 ) ;
F_35 (
V_2 -> V_156 , V_157 ,
F_32 , & V_146 ) ;
return 0 ;
}
static void F_36 ( void * V_144 , T_3 * V_145 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
V_21 -> V_113 = false ;
}
static void F_37 ( void * V_144 , T_3 * V_145 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
bool * V_158 = V_144 ;
if ( V_21 -> V_159 )
if ( V_21 -> V_159 -> V_104 < V_160 )
* V_158 |= V_21 -> V_110 ;
}
static void F_38 ( void * V_144 , T_3 * V_145 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_161 * V_162 = V_144 ;
switch ( F_39 ( V_19 ) ) {
case V_163 :
break;
case V_164 :
case V_165 :
F_17 ( V_162 -> V_166 ) ;
V_162 -> V_166 = V_19 ;
if ( V_21 -> V_159 )
if ( V_21 -> V_159 -> V_104 < V_160 )
V_162 -> V_167 = true ;
break;
case V_168 :
F_17 ( V_162 -> V_169 ) ;
V_162 -> V_169 = V_19 ;
if ( V_21 -> V_159 )
if ( V_21 -> V_159 -> V_104 < V_160 )
V_162 -> V_170 = true ;
break;
case V_171 :
F_17 ( V_162 -> V_172 ) ;
V_162 -> V_172 = V_19 ;
if ( V_21 -> V_159 )
if ( V_21 -> V_159 -> V_104 < V_160 )
V_162 -> V_173 = true ;
break;
case V_174 :
F_17 ( V_162 -> V_175 ) ;
V_162 -> V_175 = V_19 ;
if ( V_21 -> V_159 )
if ( V_21 -> V_159 -> V_104 < V_160 )
V_162 -> V_176 = true ;
if ( V_21 -> V_25 . V_177 &&
! F_17 ( V_162 -> V_178 ) )
V_162 -> V_178 = V_19 ;
break;
default:
break;
}
}
static void F_40 ( struct V_1 * V_2 ,
struct V_161 * V_179 )
{
struct V_20 * V_180 = NULL ;
struct V_20 * V_181 = NULL ;
struct V_20 * V_182 = NULL ;
bool V_183 = false ;
bool V_184 = false ;
F_41 ( & V_2 -> V_185 ) ;
F_35 ( V_2 -> V_156 ,
V_157 ,
F_36 ,
NULL ) ;
if ( V_179 -> V_175 )
V_180 = F_6 ( V_179 -> V_175 ) ;
if ( V_179 -> V_172 )
V_181 = F_6 ( V_179 -> V_172 ) ;
if ( V_179 -> V_166 )
V_182 = F_6 ( V_179 -> V_166 ) ;
if ( F_42 ( V_2 , NULL ) )
return;
if ( V_179 -> V_176 && ! V_179 -> V_173 && ! V_179 -> V_167 ) {
V_180 -> V_113 = true ;
return;
}
if ( V_179 -> V_173 && ! V_179 -> V_176 && ! V_179 -> V_167 ) {
if ( V_2 -> V_85 -> V_86 . V_5 & V_186 )
V_181 -> V_113 = true ;
return;
}
if ( V_179 -> V_176 && V_179 -> V_173 )
V_183 = ( V_180 -> V_159 -> V_104 ==
V_181 -> V_159 -> V_104 ) ;
if ( V_179 -> V_176 && V_179 -> V_167 )
V_184 = ( V_180 -> V_159 -> V_104 ==
V_182 -> V_159 -> V_104 ) ;
if ( ! ( V_183 || V_184 ) &&
( V_2 -> V_85 -> V_86 . V_5 & V_187 ) ) {
if ( V_179 -> V_176 )
V_180 -> V_113 = true ;
if ( V_179 -> V_173 &&
( V_2 -> V_85 -> V_86 . V_5 & V_186 ) )
V_181 -> V_113 = true ;
return;
}
if ( V_183 && ! V_179 -> V_167 &&
( V_2 -> V_85 -> V_86 . V_5 & V_188 ) ) {
V_180 -> V_113 = true ;
if ( V_2 -> V_85 -> V_86 . V_5 & V_186 )
V_181 -> V_113 = true ;
}
}
int F_43 ( struct V_1 * V_2 ,
struct V_18 * V_19 , char * V_189 ,
int V_190 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_27 V_4 = {} ;
int V_191 = 0 ;
F_44 ( & V_2 -> V_185 ) ;
memcpy ( & V_4 , & V_21 -> V_135 , sizeof( V_4 ) ) ;
F_45 ( & V_2 -> V_185 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_26 ,
V_29 . V_30 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_27 ,
F_9 ( V_4 . V_5 ) ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_28 ,
F_9 ( V_4 . V_31 ) ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_32 ) ) )
return V_191 ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_29 ,
( V_4 . V_5 &
F_10 ( V_35 ) ) ? 1 : 0 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_30 ,
V_4 . V_36 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_39 ) ) ) {
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_31 ,
F_3 ( V_4 . V_33 ) ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_32 ,
F_3 ( V_4 . V_34 ) ) ;
}
if ( V_4 . V_5 & F_10 ( V_37 ) )
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 ,
L_33 ,
V_4 . V_38 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_39 ) ) )
return V_191 ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_34 ,
F_3 ( V_4 . V_40 ) ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_35 ,
F_3 ( V_4 . V_41 ) ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_36 , V_4 . V_42 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_37 ,
V_4 . V_43 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_38 ,
V_4 . V_44 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_39 ,
V_4 . V_71 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_40 ,
V_4 . V_73 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_41 ,
V_4 . V_77 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_42 ,
V_4 . V_79 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_43 ,
( V_4 . V_5 &
F_10 ( V_59 ) ) ?
1 : 0 ) ;
if ( ! ( V_4 . V_5 & F_10 ( V_60 ) ) )
return V_191 ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_44 ,
V_4 . V_61 ) ;
V_191 += F_46 ( V_189 + V_191 , V_190 - V_191 , L_45 ,
V_4 . V_63 ) ;
return V_191 ;
}
void
F_47 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_192 * V_193 = & V_21 -> V_193 ;
if ( V_193 -> V_120 & V_194 )
V_4 -> V_10 = F_7 ( V_193 -> V_10 ) ;
if ( V_193 -> V_120 & V_195 )
V_4 -> V_12 =
F_7 ( V_193 -> V_12 ) ;
if ( V_193 -> V_120 & V_196 )
V_4 -> V_13 = F_7 ( V_193 -> V_13 ) ;
if ( V_193 -> V_120 & V_197 )
V_4 -> V_14 =
F_7 ( V_193 -> V_14 ) ;
if ( V_193 -> V_120 & V_198 )
V_4 -> V_15 =
F_7 ( V_193 -> V_15 ) ;
if ( V_193 -> V_120 & V_199 )
V_4 -> V_16 =
F_7 ( V_193 -> V_16 ) ;
if ( V_193 -> V_120 & V_200 )
V_4 -> V_8 = F_7 ( V_193 -> V_8 ) ;
if ( V_193 -> V_120 & V_201 )
V_4 -> V_11 = F_7 ( V_193 -> V_11 ) ;
if ( V_193 -> V_120 & V_202 )
V_4 -> V_7 = F_7 ( V_193 -> V_7 ) ;
if ( V_193 -> V_120 & V_203 )
V_4 -> V_6 =
F_7 ( V_193 -> V_6 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 ,
T_1 V_204 ,
bool V_205 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
int V_206 ;
if ( V_21 != V_2 -> V_207 || ! V_19 -> V_22 . V_106 ||
V_19 -> type != V_174 || V_19 -> V_84 )
return 0 ;
F_5 ( V_2 , V_19 , V_4 ) ;
if ( ! V_205 )
F_47 ( V_19 , V_4 ) ;
V_206 = F_1 ( V_2 , V_4 , V_204 ) ;
if ( ! V_206 && ! V_205 )
V_21 -> V_25 . V_177 = true ;
return V_206 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
T_1 V_5 )
{
struct V_3 V_4 = {
V_208 ,
. V_9 = F_7 ( 1 ) ,
} ;
return F_48 ( V_2 , V_19 , & V_4 , V_5 , false ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
bool V_209 )
{
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_3 V_4 = {
V_208 ,
. V_9 = F_7 ( 1 ) ,
} ;
if ( ! V_21 -> V_25 . V_177 )
return 0 ;
if ( V_2 -> V_52 == V_53 )
V_4 . V_7 = F_7 ( V_210 ) ;
V_21 -> V_25 . V_26 = V_209 ;
return F_48 ( V_2 , V_19 , & V_4 , 0 , false ) ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
T_1 V_5 )
{
struct V_3 V_4 = {} ;
struct V_20 * V_21 = F_6 ( V_19 ) ;
int V_206 ;
if ( V_19 -> type != V_174 || V_19 -> V_84 )
return 0 ;
V_206 = F_1 ( V_2 , & V_4 , V_5 ) ;
if ( ! V_206 )
V_21 -> V_25 . V_177 = false ;
return V_206 ;
}
static int F_52 ( struct V_1 * V_2 )
{
bool V_158 ;
int V_206 ;
V_158 = ( V_29 . V_30 == V_139 ) ;
F_35 ( V_2 -> V_156 ,
V_157 ,
F_37 ,
& V_158 ) ;
if ( V_2 -> V_110 != V_158 ) {
bool V_211 = V_2 -> V_110 ;
V_2 -> V_110 = V_158 ;
V_206 = F_29 ( V_2 ) ;
if ( V_206 ) {
V_2 -> V_110 = V_211 ;
return V_206 ;
}
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_161 * V_179 )
{
struct V_20 * V_21 ;
bool V_212 ;
if ( ! V_179 -> V_178 )
return 0 ;
V_21 = F_6 ( V_179 -> V_178 ) ;
V_212 = ! ( ! V_21 -> V_113 || V_2 -> V_110 ||
! V_179 -> V_178 -> V_22 . V_112 ||
F_27 ( V_21 ) ) ;
return F_50 ( V_2 , V_179 -> V_178 , V_212 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_161 V_179 = {
. V_2 = V_2 ,
} ;
int V_206 ;
F_41 ( & V_2 -> V_185 ) ;
F_35 ( V_2 -> V_156 ,
V_157 ,
F_38 , & V_179 ) ;
V_206 = F_52 ( V_2 ) ;
if ( V_206 )
return V_206 ;
return F_53 ( V_2 , & V_179 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_161 V_179 = {
. V_2 = V_2 ,
} ;
int V_206 ;
F_41 ( & V_2 -> V_185 ) ;
F_35 ( V_2 -> V_156 ,
V_157 ,
F_38 , & V_179 ) ;
F_40 ( V_2 , & V_179 ) ;
V_206 = F_52 ( V_2 ) ;
if ( V_206 )
return V_206 ;
if ( V_179 . V_175 ) {
V_206 = F_28 ( V_2 , V_179 . V_175 ) ;
if ( V_206 )
return V_206 ;
}
if ( V_179 . V_172 ) {
V_206 = F_28 ( V_2 , V_179 . V_172 ) ;
if ( V_206 )
return V_206 ;
}
return F_53 ( V_2 , & V_179 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
bool V_209 , T_1 V_5 )
{
int V_206 ;
struct V_20 * V_21 = F_6 ( V_19 ) ;
struct V_27 V_4 = {} ;
if ( V_19 -> type != V_174 || V_19 -> V_84 )
return 0 ;
if ( ! V_19 -> V_22 . V_213 )
return 0 ;
F_23 ( V_2 , V_19 , & V_4 ) ;
if ( V_209 ) {
int V_91 = V_19 -> V_22 . V_106 ? : 1 ;
int V_214 = V_91 * V_19 -> V_22 . V_107 ;
bool V_99 = F_19 ( V_19 ) ;
if ( F_17 ( ! V_214 ) )
return 0 ;
if ( ! V_99 && ( V_91 < 10 ) ) {
V_4 . V_36 = 306 / V_214 ;
if ( V_4 . V_36 )
V_4 . V_5 |= F_10 (
V_35 ) ;
}
}
F_8 ( V_2 , & V_4 ) ;
#ifdef F_13
memcpy ( & V_21 -> V_135 , & V_4 , sizeof( V_4 ) ) ;
#endif
V_206 = F_4 ( V_2 , V_136 , V_5 ,
sizeof( V_4 ) , & V_4 ) ;
if ( V_206 )
return V_206 ;
if ( V_21 != V_2 -> V_207 )
return 0 ;
if ( V_209 ) {
struct V_3 V_215 = {
V_216 ,
. V_9 = F_7 ( 1 ) ,
} ;
V_206 = F_48 ( V_2 , V_19 , & V_215 ,
V_5 , true ) ;
} else {
if ( V_21 -> V_25 . V_177 )
V_206 = F_49 ( V_2 , V_19 , V_5 ) ;
else
V_206 = F_51 ( V_2 , V_19 , V_5 ) ;
}
return V_206 ;
}
