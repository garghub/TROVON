static enum V_1 F_1 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 == V_5 ) {
if ( V_3 -> V_6 == V_7 )
return V_8 ;
else if ( V_3 -> V_6 == V_9 )
return V_10 ;
else if ( V_3 -> V_11 -> V_12 -> V_13 == V_7 )
return V_8 ;
} else if ( V_3 -> V_4 == V_14 ) {
return V_8 ;
}
return V_10 ;
}
static inline
struct V_2 * F_2 ( const struct V_15 * V_16 )
{
return F_3 ( V_16 , struct V_2 , V_17 ) ;
}
static bool F_4 ( struct V_2 * V_3 )
{
return ( ! V_3 -> V_18 && V_3 -> V_19 == V_20 &&
V_3 -> V_21 == V_20 ) ||
( V_3 -> V_18 && ( ( V_3 -> V_22 == V_23 &&
V_3 -> V_19 == V_20 ) ||
( V_3 -> V_22 == V_24 &&
V_3 -> V_21 == V_20 ) ) ) ;
}
static bool F_5 ( struct V_2 * V_3 )
{
return V_3 -> V_25 ==
( V_3 -> V_26 + 1 ) % V_27 ;
}
static void F_6 ( struct V_2 * V_3 , const char * V_28 , T_1 args )
{
char V_29 [ V_30 ] ;
T_2 V_31 = F_7 () ;
unsigned long V_32 ;
if ( ! V_3 -> V_33 [ V_3 -> V_26 ] ) {
V_3 -> V_33 [ V_3 -> V_26 ] =
F_8 ( V_30 , V_34 ) ;
if ( ! V_3 -> V_33 [ V_3 -> V_26 ] )
return;
}
vsnprintf ( V_29 , sizeof( V_29 ) , V_28 , args ) ;
F_9 ( & V_3 -> V_35 ) ;
if ( F_5 ( V_3 ) ) {
V_3 -> V_26 = F_10 ( V_3 -> V_26 - 1 , 0 ) ;
strcpy ( V_29 , L_1 ) ;
}
if ( V_3 -> V_26 < 0 ||
V_3 -> V_26 >= V_27 ) {
F_11 ( V_3 -> V_36 ,
L_2 , V_3 -> V_26 ) ;
goto abort;
}
if ( ! V_3 -> V_33 [ V_3 -> V_26 ] ) {
F_11 ( V_3 -> V_36 ,
L_3 , V_3 -> V_26 ) ;
goto abort;
}
V_32 = F_12 ( V_31 , 1000000000 ) ;
F_13 ( V_3 -> V_33 [ V_3 -> V_26 ] ,
V_30 , L_4 ,
( unsigned long ) V_31 , V_32 / 1000 ,
V_29 ) ;
V_3 -> V_26 = ( V_3 -> V_26 + 1 ) % V_27 ;
abort:
F_14 ( & V_3 -> V_35 ) ;
}
static void F_15 ( struct V_2 * V_3 , const char * V_28 , ... )
{
T_1 args ;
if ( F_4 ( V_3 ) &&
( V_3 -> V_37 == V_10 || V_3 -> V_37 == V_8 ||
V_3 -> V_37 == V_38 ) )
return;
va_start ( args , V_28 ) ;
F_6 ( V_3 , V_28 , args ) ;
va_end ( args ) ;
}
static void F_16 ( struct V_2 * V_3 , const char * V_28 , ... )
{
T_1 args ;
va_start ( args , V_28 ) ;
F_6 ( V_3 , V_28 , args ) ;
va_end ( args ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_40 ; V_39 ++ ) {
T_3 V_41 = V_3 -> V_42 [ V_39 ] ;
enum V_43 type = F_18 ( V_41 ) ;
char V_44 [ 64 ] ;
switch ( type ) {
case V_45 :
F_13 ( V_44 , sizeof( V_44 ) ,
L_5 ,
F_19 ( V_41 ) ,
F_20 ( V_41 ) ,
( V_41 & V_46 ) ?
L_6 : L_7 ,
( V_41 & V_47 ) ?
L_8 : L_7 ,
( V_41 & V_48 ) ?
L_9 : L_7 ,
( V_41 & V_49 ) ?
L_10 : L_7 ,
( V_41 & V_50 ) ?
L_11 : L_7 ,
( V_41 & V_51 ) ?
L_12 : L_7 ) ;
break;
case V_52 :
F_13 ( V_44 , sizeof( V_44 ) ,
L_13 ,
F_21 ( V_41 ) ,
F_22 ( V_41 ) ,
F_20 ( V_41 ) ) ;
break;
case V_53 :
F_13 ( V_44 , sizeof( V_44 ) ,
L_14 ,
F_21 ( V_41 ) ,
F_22 ( V_41 ) ,
F_23 ( V_41 ) ) ;
break;
default:
strcpy ( V_44 , L_15 ) ;
break;
}
F_15 ( V_3 , L_16 ,
V_39 , type , V_44 ) ;
}
}
static int F_24 ( struct V_54 * V_55 , void * V_56 )
{
struct V_2 * V_3 = (struct V_2 * ) V_55 -> V_57 ;
int V_58 ;
F_9 ( & V_3 -> V_35 ) ;
V_58 = V_3 -> V_25 ;
while ( V_58 != V_3 -> V_26 ) {
F_25 ( V_55 , L_17 , V_3 -> V_33 [ V_58 ] ) ;
V_58 = ( V_58 + 1 ) % V_27 ;
}
if ( ! F_26 ( V_55 ) )
V_3 -> V_25 = V_58 ;
F_14 ( & V_3 -> V_35 ) ;
return 0 ;
}
static int F_27 ( struct V_59 * V_59 , struct V_60 * V_60 )
{
return F_28 ( V_60 , F_24 , V_59 -> V_61 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
F_30 ( & V_3 -> V_35 ) ;
if ( ! V_62 ) {
V_62 = F_31 ( L_18 , NULL ) ;
if ( ! V_62 )
return - V_63 ;
}
V_3 -> V_64 = F_32 ( F_33 ( V_3 -> V_36 ) ,
V_65 | 0444 , V_62 ,
V_3 , & V_66 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 )
{
F_35 ( V_3 -> V_64 ) ;
}
static void F_15 ( const struct V_2 * V_3 , const char * V_28 , ... ) { }
static void F_16 ( struct V_2 * V_3 , const char * V_28 , ... ) { }
static void F_17 ( struct V_2 * V_3 ) { }
static int F_29 ( const struct V_2 * V_3 ) { return 0 ; }
static void F_34 ( const struct V_2 * V_3 ) { }
static int F_36 ( struct V_2 * V_3 ,
enum V_67 type ,
const struct V_68 * V_44 )
{
unsigned long V_69 ;
int V_70 ;
if ( V_44 )
F_15 ( V_3 , L_19 , F_37 ( V_44 -> V_71 ) ) ;
else
F_15 ( V_3 , L_20 , type ) ;
F_38 ( & V_3 -> V_72 ) ;
V_70 = V_3 -> V_11 -> V_73 ( V_3 -> V_11 , type , V_44 ) ;
if ( V_70 < 0 )
return V_70 ;
F_14 ( & V_3 -> V_74 ) ;
V_69 = F_39 ( & V_3 -> V_72 ,
F_40 ( V_75 ) ) ;
F_9 ( & V_3 -> V_74 ) ;
if ( ! V_69 )
return - V_76 ;
switch ( V_3 -> V_77 ) {
case V_78 :
V_3 -> V_79 = ( V_3 -> V_79 + 1 ) & V_80 ;
return 0 ;
case V_81 :
return - V_82 ;
case V_83 :
default:
return - V_84 ;
}
}
void F_41 ( struct V_2 * V_3 ,
enum V_85 V_86 )
{
F_15 ( V_3 , L_21 , V_86 ) ;
V_3 -> V_77 = V_86 ;
F_42 ( & V_3 -> V_72 ) ;
}
static int F_43 ( struct V_2 * V_3 , enum V_87 V_88 ,
enum V_89 V_12 )
{
int V_70 = 0 ;
F_15 ( V_3 , L_22 ,
V_88 , V_12 , V_3 -> V_22 ) ;
if ( V_3 -> V_11 -> V_90 )
V_70 = V_3 -> V_11 -> V_90 -> V_91 ( V_3 -> V_11 -> V_90 , V_88 , V_12 ,
V_3 -> V_22 ) ;
return V_70 ;
}
static int F_44 ( struct V_2 * V_3 ,
enum V_92 V_22 )
{
int V_70 ;
F_15 ( V_3 , L_23 , V_22 ) ;
V_70 = V_3 -> V_11 -> V_93 ( V_3 -> V_11 , V_22 ) ;
if ( V_70 < 0 )
return V_70 ;
V_3 -> V_22 = V_22 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , bool V_94 )
{
int V_70 ;
F_15 ( V_3 , L_24 , V_94 ) ;
V_70 = V_3 -> V_11 -> V_95 ( V_3 -> V_11 , V_94 ) ;
if ( ! V_70 ) {
V_3 -> V_96 = V_94 ? V_9 : V_7 ;
F_46 ( V_3 -> V_97 , V_3 -> V_96 ) ;
}
return V_70 ;
}
static T_3 F_47 ( struct V_2 * V_3 )
{
enum V_98 V_99 ;
T_3 V_100 ;
V_99 = V_3 -> V_22 ? V_3 -> V_21 : V_3 -> V_19 ;
switch ( V_99 ) {
case V_101 :
V_100 = 1500 ;
break;
case V_102 :
V_100 = 3000 ;
break;
case V_103 :
default:
if ( V_3 -> V_11 -> V_104 )
V_100 = V_3 -> V_11 -> V_104 ( V_3 -> V_11 ) ;
else
V_100 = 0 ;
break;
}
return V_100 ;
}
static int F_48 ( struct V_2 * V_3 , T_3 V_105 , T_3 V_106 )
{
int V_70 = - V_107 ;
F_15 ( V_3 , L_25 , V_106 , V_105 ) ;
if ( V_3 -> V_11 -> V_108 )
V_70 = V_3 -> V_11 -> V_108 ( V_3 -> V_11 , V_105 , V_106 ) ;
return V_70 ;
}
static enum V_98 F_49 ( struct V_2 * V_3 )
{
const T_3 * V_109 = V_3 -> V_109 ;
int V_110 = V_3 -> V_111 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_110 ; V_39 ++ ) {
const T_3 V_41 = V_109 [ V_39 ] ;
if ( F_18 ( V_41 ) == V_45 &&
F_19 ( V_41 ) == 5000 ) {
unsigned int V_112 = F_20 ( V_41 ) ;
if ( V_112 >= 3000 )
return V_102 ;
else if ( V_112 >= 1500 )
return V_101 ;
return V_103 ;
}
}
return V_103 ;
}
static int F_50 ( struct V_2 * V_3 , bool V_18 )
{
return V_3 -> V_11 -> V_113 ( V_3 -> V_11 , V_18 , V_3 -> V_114 ,
V_3 -> V_115 ) ;
}
static int F_51 ( struct V_2 * V_3 , bool V_18 ,
enum V_116 V_117 , enum V_118 V_119 )
{
int V_70 ;
if ( V_119 == V_120 )
V_70 = F_43 ( V_3 , V_121 ,
V_122 ) ;
else
V_70 = F_43 ( V_3 , V_123 ,
V_124 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = V_3 -> V_11 -> V_113 ( V_3 -> V_11 , V_18 , V_117 , V_119 ) ;
if ( V_70 < 0 )
return V_70 ;
V_3 -> V_114 = V_117 ;
V_3 -> V_115 = V_119 ;
F_52 ( V_3 -> V_97 , V_119 ) ;
F_53 ( V_3 -> V_97 , V_117 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 , enum V_116 V_117 )
{
int V_70 ;
V_70 = V_3 -> V_11 -> V_113 ( V_3 -> V_11 , true , V_117 ,
V_3 -> V_115 ) ;
if ( V_70 < 0 )
return V_70 ;
V_3 -> V_114 = V_117 ;
F_53 ( V_3 -> V_97 , V_117 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_68 V_44 ;
int V_39 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
if ( ! V_3 -> V_111 ) {
V_44 . V_71 = F_56 ( V_125 ,
V_3 -> V_114 ,
V_3 -> V_115 ,
V_3 -> V_79 , 0 ) ;
} else {
V_44 . V_71 = F_56 ( V_126 ,
V_3 -> V_114 ,
V_3 -> V_115 ,
V_3 -> V_79 ,
V_3 -> V_111 ) ;
}
for ( V_39 = 0 ; V_39 < V_3 -> V_111 ; V_39 ++ )
V_44 . V_127 [ V_39 ] = F_57 ( V_3 -> V_109 [ V_39 ] ) ;
return F_36 ( V_3 , V_128 , & V_44 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_68 V_44 ;
int V_39 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
if ( ! V_3 -> V_129 ) {
V_44 . V_71 = F_56 ( V_125 ,
V_3 -> V_114 ,
V_3 -> V_115 ,
V_3 -> V_79 , 0 ) ;
} else {
V_44 . V_71 = F_56 ( V_130 ,
V_3 -> V_114 ,
V_3 -> V_115 ,
V_3 -> V_79 ,
V_3 -> V_129 ) ;
}
for ( V_39 = 0 ; V_39 < V_3 -> V_129 ; V_39 ++ )
V_44 . V_127 [ V_39 ] = F_57 ( V_3 -> V_131 [ V_39 ] ) ;
return F_36 ( V_3 , V_128 , & V_44 ) ;
}
static void F_59 ( struct V_2 * V_3 , enum V_1 V_37 ,
unsigned int V_132 )
{
if ( V_132 ) {
F_15 ( V_3 , L_26 ,
V_133 [ V_3 -> V_37 ] , V_133 [ V_37 ] ,
V_132 ) ;
V_3 -> V_134 = V_37 ;
F_60 ( V_3 -> V_135 , & V_3 -> V_136 ,
F_40 ( V_132 ) ) ;
V_3 -> V_137 = V_138 + F_40 ( V_132 ) ;
V_3 -> V_132 = V_132 ;
} else {
F_15 ( V_3 , L_27 ,
V_133 [ V_3 -> V_37 ] , V_133 [ V_37 ] ) ;
V_3 -> V_134 = V_139 ;
V_3 -> V_140 = V_3 -> V_37 ;
V_3 -> V_37 = V_37 ;
if ( ! V_3 -> V_141 )
F_60 ( V_3 -> V_135 , & V_3 -> V_136 , 0 ) ;
}
}
static void F_61 ( struct V_2 * V_3 , enum V_1 V_37 ,
unsigned int V_132 )
{
if ( V_3 -> V_142 == V_3 -> V_37 )
F_59 ( V_3 , V_37 , V_132 ) ;
else
F_15 ( V_3 ,
L_28 ,
V_132 ? L_29 : L_7 ,
V_133 [ V_3 -> V_37 ] , V_133 [ V_37 ] ,
V_132 , V_133 [ V_3 -> V_142 ] ) ;
}
static void F_62 ( struct V_2 * V_3 ,
enum V_143 V_144 )
{
V_3 -> V_145 = V_144 ;
F_60 ( V_3 -> V_135 , & V_3 -> V_136 , 0 ) ;
}
static void F_63 ( struct V_2 * V_3 , const T_3 V_71 ,
const T_3 * V_119 , int V_146 )
{
V_3 -> V_147 = V_146 + 1 ;
V_3 -> V_148 [ 0 ] = V_71 ;
memcpy ( & V_3 -> V_148 [ 1 ] , V_119 , sizeof( T_3 ) * V_146 ) ;
V_3 -> V_149 = 0 ;
V_3 -> V_150 = V_151 ;
}
static void F_64 ( struct V_2 * V_3 , const T_4 * V_127 ,
int V_146 )
{
T_3 V_152 = F_65 ( V_127 [ V_153 ] ) ;
T_3 V_154 = F_65 ( V_127 [ V_155 ] ) ;
memset ( & V_3 -> V_156 , 0 , sizeof( V_3 -> V_156 ) ) ;
#if 0
switch (PD_IDH_PTYPE(vdo)) {
case IDH_PTYPE_UNDEF:
port->partner.type = TYPEC_PARTNER_NONE;
break;
case IDH_PTYPE_HUB:
break;
case IDH_PTYPE_PERIPH:
break;
case IDH_PTYPE_PCABLE:
break;
case IDH_PTYPE_ACABLE:
break;
case IDH_PTYPE_AMA:
port->partner.type = TYPEC_PARTNER_ALTMODE;
break;
default:
break;
}
#endif
V_3 -> V_157 . V_158 = V_152 ;
V_3 -> V_157 . V_159 = F_65 ( V_127 [ V_160 ] ) ;
V_3 -> V_157 . V_154 = V_154 ;
F_66 ( V_3 -> V_161 ) ;
F_15 ( V_3 , L_30 ,
F_67 ( V_152 ) ,
F_68 ( V_154 ) , V_154 & 0xffff ) ;
}
static bool F_69 ( struct V_2 * V_3 , const T_4 * V_127 ,
int V_146 )
{
struct V_162 * V_163 = & V_3 -> V_156 ;
int V_39 ;
for ( V_39 = 1 ; V_39 < V_146 ; V_39 ++ ) {
T_3 V_164 = F_65 ( V_127 [ V_39 ] ) ;
T_5 V_165 ;
V_165 = ( V_164 >> 16 ) & 0xffff ;
if ( ! V_165 )
return false ;
if ( V_163 -> V_166 >= V_167 )
goto abort;
V_163 -> V_168 [ V_163 -> V_166 ++ ] = V_165 ;
F_15 ( V_3 , L_31 , V_163 -> V_166 , V_165 ) ;
V_165 = V_164 & 0xffff ;
if ( ! V_165 )
return false ;
if ( V_163 -> V_166 >= V_167 )
goto abort;
V_163 -> V_168 [ V_163 -> V_166 ++ ] = V_165 ;
F_15 ( V_3 , L_31 , V_163 -> V_166 , V_165 ) ;
}
return true ;
abort:
F_15 ( V_3 , L_32 , V_167 ) ;
return false ;
}
static void F_70 ( struct V_2 * V_3 , const T_4 * V_127 ,
int V_146 )
{
struct V_162 * V_163 = & V_3 -> V_156 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
int V_39 ;
if ( V_163 -> V_173 >= F_71 ( V_3 -> V_174 ) ) {
return;
}
V_170 = & V_163 -> V_175 [ V_163 -> V_173 ] ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_170 -> V_165 = V_163 -> V_168 [ V_163 -> V_176 ] ;
F_15 ( V_3 , L_33 ,
V_163 -> V_173 , V_170 -> V_165 ) ;
for ( V_39 = 1 ; V_39 < V_146 && V_170 -> V_177 < V_178 ; V_39 ++ ) {
V_172 = & V_170 -> V_179 [ V_170 -> V_177 ] ;
memset ( V_172 , 0 , sizeof( * V_172 ) ) ;
V_172 -> V_152 = F_65 ( V_127 [ V_39 ] ) ;
V_172 -> V_180 = V_39 - 1 ;
V_170 -> V_177 ++ ;
F_15 ( V_3 , L_34 ,
V_172 -> V_180 , V_172 -> V_152 ) ;
}
V_3 -> V_174 [ V_163 -> V_173 ] =
F_72 ( V_3 -> V_161 , V_170 ) ;
if ( V_3 -> V_174 [ V_163 -> V_173 ] == NULL ) {
F_15 ( V_3 ,
L_35 ,
V_170 -> V_165 ) ;
return;
}
V_163 -> V_173 ++ ;
}
static int F_73 ( struct V_2 * V_3 , const T_4 * V_127 , int V_146 ,
T_3 * V_181 )
{
T_3 V_182 = F_65 ( V_127 [ 0 ] ) ;
int V_183 = F_74 ( V_182 ) ;
int V_184 = F_75 ( V_182 ) ;
struct V_162 * V_185 ;
int V_186 = 0 ;
T_5 V_165 ;
int V_39 ;
F_15 ( V_3 , L_36 ,
V_182 , V_183 , V_184 , V_146 ) ;
V_185 = & V_3 -> V_156 ;
switch ( V_183 ) {
case V_187 :
switch ( V_184 ) {
case V_188 :
if ( V_3 -> V_115 == V_189 &&
V_3 -> V_190 ) {
for ( V_39 = 0 ; V_39 < V_3 -> V_190 ; V_39 ++ )
V_181 [ V_39 + 1 ] = V_3 -> V_191 [ V_39 ] ;
V_186 = V_3 -> V_190 + 1 ;
}
break;
case V_192 :
break;
case V_193 :
break;
case V_194 :
break;
case V_195 :
break;
case V_196 :
break;
default:
break;
}
if ( V_186 >= 1 ) {
V_181 [ 0 ] = V_182 | F_76 ( V_197 ) ;
} else if ( V_186 == 0 ) {
V_181 [ 0 ] = V_182 | F_76 ( V_198 ) ;
V_186 = 1 ;
} else {
V_181 [ 0 ] = V_182 | F_76 ( V_199 ) ;
V_186 = 1 ;
}
break;
case V_197 :
if ( ! V_3 -> V_161 )
break;
switch ( V_184 ) {
case V_188 :
F_64 ( V_3 , V_127 , V_146 ) ;
V_181 [ 0 ] = F_77 ( V_200 , 1 , V_192 ) ;
V_186 = 1 ;
break;
case V_192 :
if ( F_69 ( V_3 , V_127 , V_146 ) ) {
V_181 [ 0 ] = F_77 ( V_200 , 1 ,
V_192 ) ;
V_186 = 1 ;
} else if ( V_185 -> V_166 && F_78 ( V_3 ) ) {
V_181 [ 0 ] = F_77 ( V_185 -> V_168 [ 0 ] , 1 ,
V_193 ) ;
V_186 = 1 ;
}
break;
case V_193 :
F_70 ( V_3 , V_127 , V_146 ) ;
V_185 -> V_176 ++ ;
if ( V_185 -> V_176 < V_185 -> V_166 ) {
V_165 = V_185 -> V_168 [ V_185 -> V_176 ] ;
V_181 [ 0 ] = F_77 ( V_165 , 1 , V_193 ) ;
V_186 = 1 ;
} else {
#if 0
response[0] = pd_dfp_enter_mode(port, 0, 0);
if (response[0])
rlen = 1;
#endif
}
break;
case V_194 :
break;
default:
break;
}
break;
default:
break;
}
return V_186 ;
}
static void F_79 ( struct V_2 * V_3 ,
const T_4 * V_127 , int V_146 )
{
int V_186 = 0 ;
T_3 V_181 [ 8 ] = { } ;
T_3 V_182 = F_65 ( V_127 [ 0 ] ) ;
if ( V_3 -> V_150 == V_201 ) {
if ( F_74 ( V_182 ) == V_199 ) {
V_3 -> V_150 = V_202 ;
V_3 -> V_203 = ( V_182 & ~ V_204 ) |
V_187 ;
F_60 ( V_3 -> V_135 , & V_3 -> V_205 ,
F_40 ( V_206 ) ) ;
return;
}
V_3 -> V_150 = V_207 ;
}
if ( F_80 ( V_182 ) )
V_186 = F_73 ( V_3 , V_127 , V_146 , V_181 ) ;
#if 0
else
rlen = tcpm_pd_custom_vdm(port, cnt, payload, response);
#endif
if ( V_186 > 0 ) {
F_63 ( V_3 , V_181 [ 0 ] , & V_181 [ 1 ] , V_186 - 1 ) ;
F_60 ( V_3 -> V_135 , & V_3 -> V_205 , 0 ) ;
}
}
static void F_81 ( struct V_2 * V_3 , T_3 V_208 , int V_184 ,
const T_3 * V_119 , int V_209 )
{
T_3 V_71 ;
if ( F_82 ( V_209 > V_210 - 1 ) )
V_209 = V_210 - 1 ;
V_71 = F_77 ( V_208 , ( ( V_208 & V_200 ) == V_200 ) ?
1 : ( F_75 ( V_184 ) <= V_196 ) , V_184 ) ;
F_63 ( V_3 , V_71 , V_119 , V_209 ) ;
F_60 ( V_3 -> V_135 , & V_3 -> V_205 , 0 ) ;
}
static unsigned int F_83 ( T_3 V_211 )
{
unsigned int V_69 ;
int V_184 = F_75 ( V_211 ) ;
if ( ! F_80 ( V_211 ) )
return V_212 ;
switch ( F_74 ( V_211 ) ) {
case V_187 :
if ( V_184 == V_194 || V_184 == V_195 )
V_69 = V_213 ;
else
V_69 = V_214 ;
break;
default:
if ( V_184 == V_194 || V_184 == V_195 )
V_69 = V_215 ;
else
V_69 = V_216 ;
break;
}
return V_69 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_68 V_44 ;
int V_39 , V_217 ;
switch ( V_3 -> V_150 ) {
case V_151 :
if ( ! V_3 -> V_18 ) {
V_3 -> V_150 = V_218 ;
break;
}
if ( V_3 -> V_37 != V_219 && V_3 -> V_37 != V_220 )
break;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_71 = F_56 ( V_221 ,
V_3 -> V_114 ,
V_3 -> V_115 ,
V_3 -> V_79 , V_3 -> V_147 ) ;
for ( V_39 = 0 ; V_39 < V_3 -> V_147 ; V_39 ++ )
V_44 . V_127 [ V_39 ] = F_57 ( V_3 -> V_148 [ V_39 ] ) ;
V_217 = F_36 ( V_3 , V_128 , & V_44 ) ;
if ( V_217 < 0 ) {
V_3 -> V_150 = V_222 ;
} else {
unsigned long V_69 ;
V_3 -> V_149 = 0 ;
V_3 -> V_150 = V_201 ;
V_69 = F_83 ( V_3 -> V_148 [ 0 ] ) ;
F_60 ( V_3 -> V_135 , & V_3 -> V_205 ,
V_69 ) ;
}
break;
case V_202 :
V_3 -> V_148 [ 0 ] = V_3 -> V_203 ;
V_3 -> V_147 = 1 ;
V_3 -> V_150 = V_151 ;
break;
case V_201 :
V_3 -> V_150 = V_223 ;
break;
case V_222 :
if ( V_3 -> V_149 < 3 ) {
F_15 ( V_3 , L_37 ) ;
V_3 -> V_149 ++ ;
V_3 -> V_150 = V_151 ;
}
break;
default:
break;
}
}
static void F_85 ( struct V_224 * V_225 )
{
struct V_2 * V_3 = F_3 ( V_225 , struct V_2 ,
V_205 . V_225 ) ;
enum V_226 V_140 ;
F_9 ( & V_3 -> V_74 ) ;
do {
V_140 = V_3 -> V_150 ;
F_84 ( V_3 ) ;
} while ( V_3 -> V_150 != V_140 &&
V_3 -> V_150 != V_201 );
F_14 ( & V_3 -> V_74 ) ;
}
static void F_86 ( struct V_2 * V_3 ,
const struct V_68 * V_44 )
{
enum V_227 type = F_87 ( V_44 -> V_71 ) ;
unsigned int V_146 = F_88 ( V_44 -> V_71 ) ;
unsigned int V_39 ;
switch ( type ) {
case V_126 :
if ( V_3 -> V_114 != V_7 )
break;
for ( V_39 = 0 ; V_39 < V_146 ; V_39 ++ )
V_3 -> V_42 [ V_39 ] = F_65 ( V_44 -> V_127 [ V_39 ] ) ;
V_3 -> V_40 = V_146 ;
F_17 ( V_3 ) ;
F_59 ( V_3 , V_228 , 0 ) ;
break;
case V_229 :
if ( V_3 -> V_114 != V_9 ||
V_146 != 1 ) {
F_62 ( V_3 , V_230 ) ;
break;
}
V_3 -> V_231 = F_65 ( V_44 -> V_127 [ 0 ] ) ;
F_59 ( V_3 , V_232 , 0 ) ;
break;
case V_130 :
for ( V_39 = 0 ; V_39 < V_146 ; V_39 ++ )
V_3 -> V_233 [ V_39 ] = F_65 ( V_44 -> V_127 [ V_39 ] ) ;
V_3 -> V_234 = V_146 ;
break;
case V_221 :
F_79 ( V_3 , V_44 -> V_127 , V_146 ) ;
break;
case V_235 :
if ( V_3 -> V_37 == V_219 || V_3 -> V_37 == V_220 ) {
V_3 -> V_236 = F_65 ( V_44 -> V_127 [ 0 ] ) ;
F_59 ( V_3 , V_237 , 0 ) ;
}
break;
default:
F_15 ( V_3 , L_38 , type ) ;
break;
}
}
static void F_89 ( struct V_2 * V_3 ,
const struct V_68 * V_44 )
{
enum V_238 type = F_87 ( V_44 -> V_71 ) ;
enum V_1 V_239 ;
switch ( type ) {
case V_240 :
case V_241 :
break;
case V_242 :
switch ( V_3 -> V_37 ) {
case V_219 :
case V_220 :
F_62 ( V_3 , V_243 ) ;
break;
default:
F_62 ( V_3 , V_230 ) ;
break;
}
break;
case V_244 :
switch ( V_3 -> V_37 ) {
case V_219 :
case V_220 :
F_62 ( V_3 , V_245 ) ;
break;
default:
F_62 ( V_3 , V_230 ) ;
break;
}
break;
case V_246 :
break;
case V_247 :
switch ( V_3 -> V_37 ) {
case V_248 :
if ( V_3 -> V_249 ) {
F_48 ( V_3 ,
V_3 -> V_250 ,
V_3 -> V_251 ) ;
V_3 -> V_252 = true ;
F_59 ( V_3 , V_220 , 0 ) ;
} else {
F_59 ( V_3 ,
V_253 , 0 ) ;
}
break;
case V_254 :
F_59 ( V_3 , V_255 , 0 ) ;
break;
case V_256 :
F_59 ( V_3 , V_257 , 0 ) ;
break;
case V_258 :
F_59 ( V_3 , V_259 , 0 ) ;
break;
default:
break;
}
break;
case V_125 :
case V_260 :
switch ( V_3 -> V_37 ) {
case V_228 :
if ( V_3 -> V_252 )
V_239 = V_220 ;
else
V_239 = V_261 ;
F_59 ( V_3 , V_239 , 0 ) ;
break;
case V_262 :
V_3 -> V_263 = ( type == V_260 ?
- V_82 : - V_107 ) ;
F_59 ( V_3 , V_264 , 0 ) ;
break;
case V_265 :
V_3 -> V_263 = ( type == V_260 ?
- V_82 : - V_107 ) ;
F_59 ( V_3 , V_266 , 0 ) ;
break;
case V_267 :
V_3 -> V_263 = ( type == V_260 ?
- V_82 : - V_107 ) ;
F_59 ( V_3 , V_268 , 0 ) ;
break;
default:
break;
}
break;
case V_269 :
switch ( V_3 -> V_37 ) {
case V_228 :
F_59 ( V_3 , V_248 , 0 ) ;
break;
case V_270 :
V_3 -> V_79 = 0 ;
V_3 -> V_271 = - 1 ;
if ( V_3 -> V_114 == V_9 )
V_239 = V_272 ;
else
V_239 = V_261 ;
F_59 ( V_3 , V_239 , 0 ) ;
break;
case V_262 :
F_59 ( V_3 , V_273 , 0 ) ;
break;
case V_265 :
F_59 ( V_3 , V_274 , 0 ) ;
break;
case V_267 :
F_59 ( V_3 , V_275 , 0 ) ;
break;
default:
break;
}
break;
case V_276 :
F_59 ( V_3 , V_277 , 0 ) ;
break;
case V_278 :
if ( V_3 -> V_4 != V_5 ) {
F_62 ( V_3 , V_230 ) ;
break;
}
switch ( V_3 -> V_37 ) {
case V_219 :
case V_220 :
F_59 ( V_3 , V_279 , 0 ) ;
break;
default:
F_62 ( V_3 , V_280 ) ;
break;
}
break;
case V_281 :
if ( V_3 -> V_4 != V_5 ) {
F_62 ( V_3 , V_230 ) ;
break;
}
switch ( V_3 -> V_37 ) {
case V_219 :
case V_220 :
F_59 ( V_3 , V_282 , 0 ) ;
break;
default:
F_62 ( V_3 , V_280 ) ;
break;
}
break;
case V_283 :
switch ( V_3 -> V_37 ) {
case V_219 :
case V_220 :
F_59 ( V_3 , V_284 , 0 ) ;
break;
default:
F_62 ( V_3 , V_280 ) ;
break;
}
break;
default:
F_15 ( V_3 , L_39 , type ) ;
break;
}
}
static void F_90 ( struct V_224 * V_225 )
{
struct V_285 * V_286 = F_3 ( V_225 ,
struct V_285 , V_225 ) ;
const struct V_68 * V_44 = & V_286 -> V_44 ;
unsigned int V_146 = F_88 ( V_44 -> V_71 ) ;
struct V_2 * V_3 = V_286 -> V_3 ;
F_9 ( & V_3 -> V_74 ) ;
F_15 ( V_3 , L_40 , F_37 ( V_44 -> V_71 ) ,
V_3 -> V_18 ) ;
if ( V_3 -> V_18 ) {
enum V_238 type = F_87 ( V_44 -> V_71 ) ;
unsigned int V_287 = F_91 ( V_44 -> V_71 ) ;
if ( V_287 == V_3 -> V_271 && type != V_276 )
goto V_288;
V_3 -> V_271 = V_287 ;
if ( ! ! ( F_37 ( V_44 -> V_71 ) & V_289 ) ==
( V_3 -> V_115 == V_120 ) ) {
F_15 ( V_3 ,
L_41 ) ;
F_59 ( V_3 , V_290 , 0 ) ;
} else {
if ( V_146 )
F_86 ( V_3 , V_44 ) ;
else
F_89 ( V_3 , V_44 ) ;
}
}
V_288:
F_14 ( & V_3 -> V_74 ) ;
F_92 ( V_286 ) ;
}
void F_93 ( struct V_2 * V_3 , const struct V_68 * V_44 )
{
struct V_285 * V_286 ;
V_286 = F_8 ( sizeof( * V_286 ) , V_291 ) ;
if ( ! V_286 )
return;
F_94 ( & V_286 -> V_225 , F_90 ) ;
V_286 -> V_3 = V_3 ;
memcpy ( & V_286 -> V_44 , V_44 , sizeof( * V_44 ) ) ;
F_95 ( V_3 -> V_135 , & V_286 -> V_225 ) ;
}
static int F_96 ( struct V_2 * V_3 ,
enum V_238 type )
{
struct V_68 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_71 = F_56 ( type , V_3 -> V_114 ,
V_3 -> V_115 ,
V_3 -> V_79 , 0 ) ;
return F_36 ( V_3 , V_128 , & V_44 ) ;
}
static bool F_97 ( struct V_2 * V_3 )
{
enum V_143 V_145 ;
do {
V_145 = V_3 -> V_145 ;
V_3 -> V_145 = V_292 ;
switch ( V_145 ) {
case V_280 :
F_96 ( V_3 , V_260 ) ;
break;
case V_230 :
F_96 ( V_3 , V_125 ) ;
break;
case V_245 :
F_58 ( V_3 ) ;
break;
case V_243 :
F_55 ( V_3 ) ;
break;
default:
break;
}
} while ( V_3 -> V_145 != V_292 );
if ( V_3 -> V_134 != V_139 ) {
if ( F_98 ( V_3 -> V_137 ) ) {
F_60 ( V_3 -> V_135 , & V_3 -> V_136 ,
V_3 -> V_137 - V_138 ) ;
return true ;
}
V_3 -> V_134 = V_139 ;
}
return false ;
}
static int F_99 ( struct V_2 * V_3 )
{
T_3 V_41 , V_293 = V_3 -> V_231 ;
unsigned int F_10 , V_294 , V_295 , V_180 ;
enum V_43 type ;
V_180 = F_100 ( V_293 ) ;
if ( ! V_180 || V_180 > V_3 -> V_111 )
return - V_296 ;
V_41 = V_3 -> V_109 [ V_180 - 1 ] ;
type = F_18 ( V_41 ) ;
switch ( type ) {
case V_45 :
case V_52 :
F_10 = F_101 ( V_293 ) ;
V_294 = F_102 ( V_293 ) ;
V_295 = F_20 ( V_41 ) ;
if ( V_294 > V_295 )
return - V_296 ;
if ( F_10 > V_295 && ! ( V_293 & V_297 ) )
return - V_296 ;
if ( type == V_45 )
F_15 ( V_3 ,
L_42 ,
F_19 ( V_41 ) , V_295 , V_294 , F_10 ) ;
else
F_15 ( V_3 ,
L_43 ,
F_21 ( V_41 ) , F_22 ( V_41 ) ,
V_295 , V_294 , F_10 ) ;
break;
case V_53 :
F_10 = F_103 ( V_293 ) ;
V_294 = F_104 ( V_293 ) ;
V_295 = F_23 ( V_41 ) ;
if ( V_294 > V_295 )
return - V_296 ;
if ( F_10 > V_295 && ! ( V_293 & V_297 ) )
return - V_296 ;
F_15 ( V_3 ,
L_44 ,
F_21 ( V_41 ) , F_22 ( V_41 ) ,
V_295 , V_294 , F_10 ) ;
break;
default:
return - V_296 ;
}
V_3 -> V_298 = V_180 == 1 ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 )
{
unsigned int V_39 , V_299 = 0 , V_300 = 0 ;
int V_70 = - V_296 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_40 ; V_39 ++ ) {
T_3 V_41 = V_3 -> V_42 [ V_39 ] ;
enum V_43 type = F_18 ( V_41 ) ;
unsigned int V_106 , V_301 , V_302 ;
if ( type == V_45 )
V_106 = F_19 ( V_41 ) ;
else
V_106 = F_21 ( V_41 ) ;
if ( type == V_53 ) {
V_302 = F_23 ( V_41 ) ;
} else {
V_301 = F_106 ( F_20 ( V_41 ) ,
V_3 -> V_303 ) ;
V_302 = V_301 * V_106 / 1000 ;
}
if ( ( V_302 > V_299 || ( V_302 == V_299 && V_106 > V_300 ) ) &&
V_106 <= V_3 -> V_304 ) {
V_70 = V_39 ;
V_299 = V_302 ;
V_300 = V_106 ;
}
}
return V_70 ;
}
static int F_107 ( struct V_2 * V_3 , T_3 * V_293 )
{
unsigned int V_106 , V_301 , V_302 , V_305 ;
unsigned int V_105 , V_299 ;
enum V_43 type ;
int V_180 ;
T_3 V_41 ;
V_180 = F_105 ( V_3 ) ;
if ( V_180 < 0 )
return - V_296 ;
V_41 = V_3 -> V_42 [ V_180 ] ;
type = F_18 ( V_41 ) ;
if ( type == V_45 )
V_106 = F_19 ( V_41 ) ;
else
V_106 = F_21 ( V_41 ) ;
if ( type == V_53 ) {
V_302 = F_23 ( V_41 ) ;
V_301 = 1000 * F_106 ( V_302 , V_3 -> V_306 ) / V_106 ;
} else {
V_301 = F_106 ( F_20 ( V_41 ) ,
1000 * V_3 -> V_306 / V_106 ) ;
}
V_301 = F_106 ( V_301 , V_3 -> V_303 ) ;
V_305 = V_307 | V_308 ;
V_302 = V_301 * V_106 / 1000 ;
V_105 = V_301 ;
V_299 = V_302 ;
if ( V_302 < V_3 -> V_309 ) {
V_305 |= V_297 ;
V_299 = V_3 -> V_309 ;
V_105 = V_299 * 1000 / V_106 ;
}
F_15 ( V_3 , L_45 ,
V_3 -> V_310 , V_3 -> V_19 , V_3 -> V_21 , V_3 -> V_311 ,
V_3 -> V_96 == V_9 ? L_46 : L_47 ,
V_3 -> V_22 ) ;
if ( type == V_53 ) {
* V_293 = F_108 ( V_180 + 1 , V_302 , V_299 , V_305 ) ;
F_15 ( V_3 , L_48 ,
V_180 , V_106 , V_302 ,
V_305 & V_297 ? L_49 : L_7 ) ;
} else {
* V_293 = F_109 ( V_180 + 1 , V_301 , V_105 , V_305 ) ;
F_15 ( V_3 , L_50 ,
V_180 , V_106 , V_301 ,
V_305 & V_297 ? L_49 : L_7 ) ;
}
V_3 -> V_250 = V_301 ;
V_3 -> V_251 = V_106 ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_68 V_44 ;
int V_70 ;
T_3 V_293 ;
V_70 = F_107 ( V_3 , & V_293 ) ;
if ( V_70 < 0 )
return V_70 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_71 = F_56 ( V_229 ,
V_3 -> V_114 ,
V_3 -> V_115 ,
V_3 -> V_79 , 1 ) ;
V_44 . V_127 [ 0 ] = F_57 ( V_293 ) ;
return F_36 ( V_3 , V_128 , & V_44 ) ;
}
static int F_111 ( struct V_2 * V_3 , bool V_94 )
{
int V_70 ;
if ( V_94 && V_3 -> V_312 )
return - V_296 ;
F_15 ( V_3 , L_51 , V_94 , V_3 -> V_312 ) ;
V_70 = V_3 -> V_11 -> V_313 ( V_3 -> V_11 , V_94 , V_3 -> V_312 ) ;
if ( V_70 < 0 )
return V_70 ;
V_3 -> V_311 = V_94 ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , bool V_314 )
{
int V_70 ;
if ( V_314 && V_3 -> V_311 )
return - V_296 ;
if ( V_314 != V_3 -> V_312 ) {
F_15 ( V_3 , L_52 , V_3 -> V_311 , V_314 ) ;
V_70 = V_3 -> V_11 -> V_313 ( V_3 -> V_11 , V_3 -> V_311 ,
V_314 ) ;
if ( V_70 < 0 )
return V_70 ;
}
V_3 -> V_312 = V_314 ;
return 0 ;
}
static bool F_113 ( struct V_2 * V_3 )
{
int V_70 ;
if ( V_3 -> V_11 -> V_315 &&
V_3 -> V_4 == V_5 ) {
F_16 ( V_3 , L_53 ) ;
V_70 = V_3 -> V_11 -> V_315 ( V_3 -> V_11 ,
F_49 ( V_3 ) ) ;
if ( ! V_70 )
return true ;
}
return false ;
}
static void F_114 ( struct V_2 * V_3 , enum V_98 V_99 )
{
F_15 ( V_3 , L_54 , V_99 ) ;
V_3 -> V_310 = V_99 ;
V_3 -> V_11 -> V_316 ( V_3 -> V_11 , V_99 ) ;
}
static int F_115 ( struct V_2 * V_3 )
{
int V_70 ;
V_70 = V_3 -> V_11 -> V_313 ( V_3 -> V_11 , false , false ) ;
V_3 -> V_311 = false ;
V_3 -> V_312 = false ;
return V_70 ;
}
static int F_116 ( struct V_2 * V_3 )
{
int V_70 ;
V_70 = V_3 -> V_11 -> V_95 ( V_3 -> V_11 , false ) ;
V_3 -> V_96 = V_7 ;
return V_70 ;
}
static void F_117 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_317 ) {
memset ( & V_3 -> V_157 , 0 , sizeof( V_3 -> V_157 ) ) ;
V_3 -> V_318 . V_319 = V_3 -> V_320 ;
if ( F_118 ( V_3 ) )
V_3 -> V_318 . V_321 = V_322 ;
else if ( F_119 ( V_3 ) )
V_3 -> V_318 . V_321 = V_323 ;
else
V_3 -> V_318 . V_321 = V_324 ;
V_3 -> V_161 = F_120 ( V_3 -> V_97 ,
& V_3 -> V_318 ) ;
V_3 -> V_317 = true ;
}
}
static int F_121 ( struct V_2 * V_3 )
{
enum V_92 V_22 =
V_3 -> V_21 == V_325 ? V_24
: V_23 ;
int V_70 ;
if ( V_3 -> V_18 )
return 0 ;
V_70 = F_44 ( V_3 , V_22 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_51 ( V_3 , true , V_9 , V_120 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = V_3 -> V_11 -> V_326 ( V_3 -> V_11 , true ) ;
if ( V_70 < 0 )
goto V_327;
if ( ( V_22 == V_23 && V_3 -> V_21 == V_328 ) ||
( V_22 == V_24 && V_3 -> V_19 == V_328 ) ) {
V_70 = F_45 ( V_3 , true ) ;
if ( V_70 < 0 )
goto V_329;
}
V_70 = F_111 ( V_3 , true ) ;
if ( V_70 < 0 )
goto V_330;
V_3 -> V_320 = false ;
V_3 -> V_161 = NULL ;
V_3 -> V_18 = true ;
V_3 -> V_331 = true ;
return 0 ;
V_330:
F_45 ( V_3 , false ) ;
V_329:
V_3 -> V_11 -> V_326 ( V_3 -> V_11 , false ) ;
V_327:
F_43 ( V_3 , V_123 , V_124 ) ;
return V_70 ;
}
static void F_122 ( struct V_2 * V_3 )
{
if ( V_3 -> V_317 ) {
F_123 ( V_3 -> V_161 ) ;
V_3 -> V_161 = NULL ;
V_3 -> V_317 = false ;
}
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_162 * V_185 = & V_3 -> V_156 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_185 -> V_173 ; V_39 ++ ) {
F_125 ( V_3 -> V_174 [ V_39 ] ) ;
V_3 -> V_174 [ V_39 ] = NULL ;
}
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
}
static void F_126 ( struct V_2 * V_3 )
{
F_124 ( V_3 ) ;
F_122 ( V_3 ) ;
V_3 -> V_18 = false ;
V_3 -> V_320 = false ;
V_3 -> V_271 = - 1 ;
V_3 -> V_11 -> V_326 ( V_3 -> V_11 , false ) ;
F_115 ( V_3 ) ;
F_116 ( V_3 ) ;
F_48 ( V_3 , 0 , 0 ) ;
F_44 ( V_3 , V_23 ) ;
F_50 ( V_3 , false ) ;
V_3 -> V_332 = 0 ;
V_3 -> V_333 = 0 ;
}
static void F_127 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_18 )
return;
if ( F_4 ( V_3 ) )
V_3 -> V_334 = 0 ;
F_126 ( V_3 ) ;
}
static void F_128 ( struct V_2 * V_3 )
{
F_127 ( V_3 ) ;
}
static int F_129 ( struct V_2 * V_3 )
{
int V_70 ;
if ( V_3 -> V_18 )
return 0 ;
V_70 = F_44 ( V_3 , V_3 -> V_21 != V_20 ?
V_24 : V_23 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_51 ( V_3 , true , V_7 , V_189 ) ;
if ( V_70 < 0 )
return V_70 ;
V_3 -> V_320 = false ;
V_3 -> V_161 = NULL ;
V_3 -> V_18 = true ;
V_3 -> V_331 = true ;
return 0 ;
}
static void F_130 ( struct V_2 * V_3 )
{
F_127 ( V_3 ) ;
}
static int F_131 ( struct V_2 * V_3 )
{
int V_70 ;
if ( V_3 -> V_18 )
return 0 ;
V_70 = F_51 ( V_3 , true , V_9 , V_120 ) ;
if ( V_70 < 0 )
return V_70 ;
V_3 -> V_161 = NULL ;
F_117 ( V_3 ) ;
V_3 -> V_18 = true ;
return 0 ;
}
static void F_132 ( struct V_2 * V_3 )
{
F_127 ( V_3 ) ;
}
static inline enum V_1 F_133 ( struct V_2 * V_3 )
{
if ( V_3 -> V_334 < V_335 )
return V_336 ;
if ( V_3 -> V_320 )
return V_290 ;
if ( V_3 -> V_114 == V_9 )
return V_10 ;
if ( V_3 -> V_37 == V_261 )
return V_220 ;
return V_8 ;
}
static inline enum V_1 F_134 ( struct V_2 * V_3 )
{
if ( V_3 -> V_114 == V_9 )
return V_219 ;
else
return V_220 ;
}
static inline enum V_1 F_135 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 == V_5 ) {
if ( V_3 -> V_114 == V_9 )
return V_10 ;
else
return V_8 ;
} else if ( V_3 -> V_4 == V_337 ) {
return V_10 ;
}
return V_8 ;
}
static void F_136 ( struct V_2 * V_3 )
{
if ( V_3 -> V_115 == V_120 && V_3 -> V_331 &&
V_3 -> V_320 ) {
F_81 ( V_3 , V_200 , V_188 , NULL , 0 ) ;
V_3 -> V_331 = false ;
}
}
static void F_137 ( struct V_2 * V_3 , int V_338 )
{
if ( V_3 -> V_339 ) {
V_3 -> V_263 = V_338 ;
V_3 -> V_339 = false ;
V_3 -> V_340 = false ;
F_42 ( & V_3 -> V_341 ) ;
}
}
static enum V_342 F_138 ( enum V_98 V_99 )
{
switch ( V_99 ) {
case V_101 :
return V_343 ;
case V_102 :
return V_344 ;
case V_103 :
default:
return V_345 ;
}
}
static void F_139 ( struct V_2 * V_3 )
{
int V_70 ;
enum V_342 V_346 ;
unsigned int V_347 ;
V_3 -> V_142 = V_3 -> V_37 ;
switch ( V_3 -> V_37 ) {
case V_38 :
break;
case V_10 :
if ( ! V_3 -> V_340 )
F_137 ( V_3 , - V_348 ) ;
F_128 ( V_3 ) ;
if ( F_113 ( V_3 ) ) {
F_59 ( V_3 , V_38 , 0 ) ;
break;
}
F_114 ( V_3 , F_49 ( V_3 ) ) ;
if ( V_3 -> V_4 == V_5 )
F_59 ( V_3 , V_8 , V_349 ) ;
break;
case V_350 :
if ( F_118 ( V_3 ) )
F_59 ( V_3 , V_351 ,
V_352 ) ;
else if ( F_119 ( V_3 ) )
F_59 ( V_3 , V_353 ,
V_352 ) ;
else if ( F_140 ( V_3 ) )
F_59 ( V_3 ,
F_141 ( V_3 ) ? V_354
: V_355 ,
V_352 ) ;
break;
case V_354 :
V_3 -> V_333 ++ ;
F_114 ( V_3 , V_325 ) ;
F_59 ( V_3 , V_356 , V_357 ) ;
break;
case V_356 :
if ( F_142 ( V_3 ) ) {
F_59 ( V_3 , V_358 , 0 ) ;
} else {
F_59 ( V_3 , V_359 , 0 ) ;
V_3 -> V_360 = 0 ;
}
break;
case V_358 :
F_59 ( V_3 , V_361 ,
V_362 ) ;
break;
case V_361 :
if ( V_3 -> V_249 && F_142 ( V_3 ) ) {
F_59 ( V_3 , V_363 , 0 ) ;
} else {
F_59 ( V_3 , V_359 , 0 ) ;
V_3 -> V_360 = 0 ;
}
break;
case V_359 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
if ( V_3 -> V_360 == 0 ) {
V_3 -> V_360 = V_138 +
F_40 ( V_357 ) ;
F_59 ( V_3 , V_364 ,
V_357 ) ;
} else {
if ( F_98 ( V_3 -> V_360 ) )
F_59 ( V_3 , V_364 ,
F_143 ( V_3 -> V_360 -
V_138 ) ) ;
else
F_59 ( V_3 , V_8 , 0 ) ;
}
break;
case V_365 :
F_59 ( V_3 , V_355 , V_352 ) ;
break;
case V_364 :
F_59 ( V_3 , V_8 , 0 ) ;
break;
case V_355 :
V_70 = F_121 ( V_3 ) ;
F_59 ( V_3 , V_10 ,
V_70 < 0 ? 0 : V_366 ) ;
break;
case V_367 :
V_346 = F_138 ( F_49 ( V_3 ) ) ;
F_144 ( V_3 -> V_97 , V_346 ) ;
V_3 -> V_368 = V_345 ;
V_3 -> V_369 = 0 ;
V_3 -> V_79 = 0 ;
V_3 -> V_271 = - 1 ;
V_3 -> V_252 = false ;
F_59 ( V_3 , V_272 , 0 ) ;
break;
case V_272 :
V_3 -> V_369 ++ ;
if ( V_3 -> V_369 > V_370 ) {
F_59 ( V_3 , V_219 , 0 ) ;
break;
}
V_70 = F_55 ( V_3 ) ;
if ( V_70 < 0 ) {
F_59 ( V_3 , V_272 ,
V_371 ) ;
} else {
V_3 -> V_369 = 0 ;
V_3 -> V_320 = true ;
F_61 ( V_3 , F_133 ( V_3 ) ,
V_371 ) ;
}
break;
case V_232 :
V_70 = F_99 ( V_3 ) ;
if ( V_70 < 0 ) {
F_96 ( V_3 , V_125 ) ;
if ( ! V_3 -> V_252 ) {
F_59 ( V_3 ,
V_372 , 0 ) ;
} else {
F_59 ( V_3 , V_219 , 0 ) ;
}
} else {
F_96 ( V_3 , V_269 ) ;
F_59 ( V_3 , V_373 ,
V_374 ) ;
}
break;
case V_373 :
F_96 ( V_3 , V_247 ) ;
V_3 -> V_252 = true ;
F_144 ( V_3 -> V_97 , V_375 ) ;
V_3 -> V_368 = V_375 ;
F_61 ( V_3 , V_219 , 0 ) ;
break;
case V_219 :
#if 1
V_3 -> V_334 = 0 ;
#endif
V_3 -> V_332 = 0 ;
F_137 ( V_3 , 0 ) ;
F_117 ( V_3 ) ;
F_136 ( V_3 ) ;
break;
case V_372 :
break;
case V_8 :
if ( ! V_3 -> V_340 )
F_137 ( V_3 , - V_348 ) ;
F_130 ( V_3 ) ;
if ( F_113 ( V_3 ) ) {
F_59 ( V_3 , V_38 , 0 ) ;
break;
}
F_114 ( V_3 , V_325 ) ;
if ( V_3 -> V_4 == V_5 )
F_59 ( V_3 , V_10 , V_376 ) ;
break;
case V_377 :
if ( ( V_3 -> V_19 == V_20 &&
V_3 -> V_21 != V_20 ) ||
( V_3 -> V_19 != V_20 &&
V_3 -> V_21 == V_20 ) )
F_59 ( V_3 , V_378 ,
V_352 ) ;
else if ( F_4 ( V_3 ) )
F_59 ( V_3 , V_8 ,
V_362 ) ;
break;
case V_378 :
if ( F_4 ( V_3 ) )
F_59 ( V_3 , V_8 ,
V_362 ) ;
else if ( V_3 -> V_249 )
F_59 ( V_3 ,
F_145 ( V_3 ) ? V_379
: V_363 ,
0 ) ;
else
F_59 ( V_3 , V_380 , V_366 ) ;
break;
case V_379 :
V_3 -> V_332 ++ ;
F_114 ( V_3 , F_49 ( V_3 ) ) ;
V_3 -> V_360 = 0 ;
F_59 ( V_3 , V_381 , 0 ) ;
break;
case V_381 :
if ( V_3 -> V_360 == 0 ) {
V_3 -> V_360 = V_138 +
F_40 ( V_357 ) ;
V_347 = V_357 ;
} else {
if ( F_98 ( V_3 -> V_360 ) )
V_347 = F_143 ( V_3 -> V_360 -
V_138 ) ;
else
V_347 = 0 ;
}
F_59 ( V_3 , V_382 , V_347 ) ;
break;
case V_383 :
F_59 ( V_3 , V_355 , V_362 ) ;
break;
case V_382 :
F_114 ( V_3 , V_325 ) ;
F_59 ( V_3 , V_384 , V_352 ) ;
break;
case V_384 :
if ( V_3 -> V_249 && F_142 ( V_3 ) ) {
F_59 ( V_3 , V_363 , 0 ) ;
break;
}
if ( ! F_142 ( V_3 ) )
F_59 ( V_3 , V_385 , 0 ) ;
break;
case V_385 :
F_59 ( V_3 , V_8 , V_362 ) ;
break;
case V_363 :
V_70 = F_129 ( V_3 ) ;
if ( V_70 < 0 )
F_59 ( V_3 , V_8 , 0 ) ;
else
F_59 ( V_3 , V_386 , 0 ) ;
break;
case V_386 :
V_346 = F_138 ( V_3 -> V_22 ?
V_3 -> V_21 : V_3 -> V_19 ) ;
F_144 ( V_3 -> V_97 , V_346 ) ;
V_3 -> V_368 = V_345 ;
V_3 -> V_79 = 0 ;
V_3 -> V_271 = - 1 ;
V_3 -> V_252 = false ;
F_59 ( V_3 , V_387 , 0 ) ;
break;
case V_387 :
if ( V_3 -> V_249 ) {
F_48 ( V_3 ,
F_47 ( V_3 ) ,
5000 ) ;
F_112 ( V_3 , true ) ;
F_59 ( V_3 , V_261 , 0 ) ;
break;
}
F_59 ( V_3 , F_133 ( V_3 ) ,
V_3 -> V_4 == V_5 ?
V_388 : V_389 ) ;
break;
case V_390 :
F_59 ( V_3 , V_391 ,
V_352 ) ;
break;
case V_391 :
if ( ! F_4 ( V_3 ) &&
F_142 ( V_3 ) &&
F_98 ( V_3 -> V_137 ) ) {
F_59 ( V_3 , V_387 ,
V_3 -> V_137 - V_138 ) ;
break;
}
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
break;
case V_261 :
V_70 = V_3 -> V_11 -> V_326 ( V_3 -> V_11 , true ) ;
if ( V_70 < 0 ) {
F_59 ( V_3 , V_220 , 0 ) ;
break;
}
if ( V_3 -> V_392 ) {
V_3 -> V_392 = false ;
F_59 ( V_3 , V_270 ,
V_393 ) ;
} else {
F_59 ( V_3 , F_133 ( V_3 ) ,
V_393 ) ;
}
break;
case V_228 :
V_3 -> V_320 = true ;
V_3 -> V_334 = 0 ;
V_70 = F_110 ( V_3 ) ;
if ( V_70 < 0 ) {
F_59 ( V_3 , V_261 , 0 ) ;
} else {
F_61 ( V_3 , F_133 ( V_3 ) ,
V_394 ) ;
}
break;
case V_248 :
case V_253 :
F_59 ( V_3 , F_133 ( V_3 ) ,
V_395 ) ;
break;
case V_220 :
V_3 -> V_333 = 0 ;
if ( V_3 -> V_252 ) {
F_144 ( V_3 -> V_97 ,
V_375 ) ;
V_3 -> V_368 = V_375 ;
}
F_137 ( V_3 , 0 ) ;
F_117 ( V_3 ) ;
F_136 ( V_3 ) ;
break;
case V_396 :
F_132 ( V_3 ) ;
F_59 ( V_3 , V_10 , 0 ) ;
break;
case V_351 :
case V_353 :
V_70 = F_131 ( V_3 ) ;
if ( V_70 < 0 )
F_59 ( V_3 , V_396 , 0 ) ;
break;
case V_397 :
F_59 ( V_3 , V_396 , V_352 ) ;
break;
case V_336 :
F_36 ( V_3 , V_398 , NULL ) ;
F_59 ( V_3 , V_399 , 0 ) ;
break;
case V_399 :
V_3 -> V_334 ++ ;
V_3 -> V_11 -> V_326 ( V_3 -> V_11 , false ) ;
F_124 ( V_3 ) ;
V_3 -> V_331 = true ;
if ( V_3 -> V_114 == V_9 )
F_59 ( V_3 , V_400 ,
V_401 ) ;
else
F_59 ( V_3 , V_402 , 0 ) ;
break;
case V_400 :
F_45 ( V_3 , true ) ;
F_111 ( V_3 , false ) ;
F_51 ( V_3 , false , V_9 , V_120 ) ;
F_59 ( V_3 , V_403 , V_404 ) ;
break;
case V_403 :
F_111 ( V_3 , true ) ;
V_3 -> V_11 -> V_326 ( V_3 -> V_11 , true ) ;
F_50 ( V_3 , true ) ;
F_59 ( V_3 , V_10 , V_366 ) ;
break;
case V_402 :
F_45 ( V_3 , false ) ;
F_112 ( V_3 , false ) ;
F_51 ( V_3 , false , V_7 , V_189 ) ;
F_59 ( V_3 , V_405 , V_406 ) ;
break;
case V_407 :
F_59 ( V_3 , V_8 ,
V_408 + V_409 ) ;
break;
case V_405 :
F_50 ( V_3 , true ) ;
F_59 ( V_3 , V_386 , 0 ) ;
break;
case V_277 :
V_3 -> V_79 = 0 ;
V_3 -> V_271 = - 1 ;
F_96 ( V_3 , V_269 ) ;
if ( V_3 -> V_114 == V_9 )
F_59 ( V_3 , V_272 , 0 ) ;
else
F_59 ( V_3 , V_261 , 0 ) ;
break;
case V_270 :
V_3 -> V_79 = 0 ;
V_3 -> V_271 = - 1 ;
if ( F_96 ( V_3 , V_276 ) )
F_61 ( V_3 , F_133 ( V_3 ) , 0 ) ;
else
F_61 ( V_3 , F_133 ( V_3 ) ,
V_394 ) ;
break;
case V_262 :
F_96 ( V_3 , V_278 ) ;
F_61 ( V_3 , V_410 ,
V_394 ) ;
break;
case V_279 :
F_96 ( V_3 , V_269 ) ;
F_61 ( V_3 , V_273 , 0 ) ;
break;
case V_410 :
F_137 ( V_3 , - V_76 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_273 :
if ( V_3 -> V_115 == V_120 ) {
F_124 ( V_3 ) ;
F_51 ( V_3 , true , V_3 -> V_114 ,
V_189 ) ;
} else {
F_51 ( V_3 , true , V_3 -> V_114 ,
V_120 ) ;
V_3 -> V_331 = true ;
}
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_282 :
F_96 ( V_3 , V_269 ) ;
F_59 ( V_3 , V_274 , 0 ) ;
break;
case V_265 :
F_96 ( V_3 , V_281 ) ;
F_61 ( V_3 , V_411 ,
V_394 ) ;
break;
case V_411 :
F_137 ( V_3 , - V_76 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_274 :
if ( V_3 -> V_114 == V_9 )
F_59 ( V_3 , V_412 ,
V_374 ) ;
else
F_59 ( V_3 , V_256 , 0 ) ;
break;
case V_412 :
F_111 ( V_3 , false ) ;
V_3 -> V_252 = false ;
F_59 ( V_3 , V_413 ,
V_414 ) ;
break;
case V_413 :
F_114 ( V_3 , V_325 ) ;
F_59 ( V_3 , V_254 ,
V_352 ) ;
break;
case V_254 :
F_54 ( V_3 , V_7 ) ;
if ( F_96 ( V_3 , V_247 ) ) {
F_59 ( V_3 , V_290 , 0 ) ;
break;
}
F_61 ( V_3 , V_8 , V_366 ) ;
break;
case V_255 :
F_59 ( V_3 , V_386 , 0 ) ;
break;
case V_256 :
F_112 ( V_3 , false ) ;
F_59 ( V_3 , F_133 ( V_3 ) ,
V_415 ) ;
break;
case V_257 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
F_111 ( V_3 , true ) ;
F_59 ( V_3 , V_416 ,
V_417 ) ;
break;
case V_416 :
F_54 ( V_3 , V_9 ) ;
F_96 ( V_3 , V_247 ) ;
F_59 ( V_3 , V_367 , 0 ) ;
break;
case V_284 :
F_96 ( V_3 , V_269 ) ;
F_59 ( V_3 , V_275 , 0 ) ;
break;
case V_267 :
F_96 ( V_3 , V_283 ) ;
F_59 ( V_3 , V_418 ,
V_394 ) ;
break;
case V_418 :
F_137 ( V_3 , - V_76 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_275 :
if ( V_3 -> V_96 == V_9 )
F_59 ( V_3 , V_258 , 0 ) ;
else
F_59 ( V_3 , V_419 , 0 ) ;
break;
case V_258 :
F_59 ( V_3 , F_133 ( V_3 ) ,
V_420 ) ;
break;
case V_419 :
F_45 ( V_3 , true ) ;
F_96 ( V_3 , V_247 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_259 :
F_45 ( V_3 , false ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_264 :
case V_266 :
case V_268 :
F_137 ( V_3 , V_3 -> V_263 ) ;
if ( V_3 -> V_114 == V_9 )
F_59 ( V_3 , V_219 , 0 ) ;
else
F_59 ( V_3 , V_220 , 0 ) ;
break;
case V_237 :
switch ( F_146 ( V_3 -> V_236 ) ) {
case V_421 :
F_36 ( V_3 , V_422 , NULL ) ;
break;
default:
break;
}
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
break;
case V_290 :
F_137 ( V_3 , - V_423 ) ;
F_59 ( V_3 , V_380 , 0 ) ;
break;
case V_380 :
F_126 ( V_3 ) ;
F_114 ( V_3 , V_20 ) ;
F_59 ( V_3 , V_424 ,
V_425 ) ;
break;
case V_424 :
F_59 ( V_3 ,
F_1 ( V_3 ) ,
V_3 -> V_249 ? V_415 : 0 ) ;
break;
default:
F_147 ( 1 , L_55 , V_3 -> V_37 ) ;
break;
}
}
static void F_148 ( struct V_224 * V_225 )
{
struct V_2 * V_3 = F_3 ( V_225 , struct V_2 ,
V_136 . V_225 ) ;
enum V_1 V_140 ;
F_9 ( & V_3 -> V_74 ) ;
V_3 -> V_141 = true ;
if ( V_3 -> V_145 && F_97 ( V_3 ) )
goto V_288;
if ( V_3 -> V_134 ) {
F_15 ( V_3 , L_56 ,
V_133 [ V_3 -> V_37 ] ,
V_133 [ V_3 -> V_134 ] , V_3 -> V_132 ) ;
V_3 -> V_140 = V_3 -> V_37 ;
V_3 -> V_37 = V_3 -> V_134 ;
V_3 -> V_134 = V_139 ;
}
do {
V_140 = V_3 -> V_37 ;
F_139 ( V_3 ) ;
if ( V_3 -> V_145 )
F_97 ( V_3 ) ;
} while ( V_3 -> V_37 != V_140 && ! V_3 -> V_134 );
V_288:
V_3 -> V_141 = false ;
F_14 ( & V_3 -> V_74 ) ;
}
static void F_149 ( struct V_2 * V_3 , enum V_98 V_19 ,
enum V_98 V_21 )
{
enum V_98 V_426 , V_427 ;
enum V_1 V_428 ;
V_426 = V_3 -> V_19 ;
V_427 = V_3 -> V_21 ;
V_3 -> V_19 = V_19 ;
V_3 -> V_21 = V_21 ;
F_16 ( V_3 ,
L_57 ,
V_426 , V_19 , V_427 , V_21 , V_133 [ V_3 -> V_37 ] ,
V_3 -> V_22 ,
F_4 ( V_3 ) ? L_58
: L_59 ) ;
switch ( V_3 -> V_37 ) {
case V_38 :
if ( F_118 ( V_3 ) || F_119 ( V_3 ) ||
F_140 ( V_3 ) )
F_59 ( V_3 , V_350 , 0 ) ;
else if ( F_142 ( V_3 ) )
F_59 ( V_3 , V_377 , 0 ) ;
break;
case V_10 :
case V_396 :
if ( F_118 ( V_3 ) || F_119 ( V_3 ) ||
F_140 ( V_3 ) )
F_59 ( V_3 , V_350 , 0 ) ;
break;
case V_350 :
if ( F_4 ( V_3 ) ||
F_150 ( V_3 ) )
F_59 ( V_3 , V_10 , 0 ) ;
else if ( V_19 != V_426 || V_21 != V_427 )
F_59 ( V_3 , V_350 , 0 ) ;
break;
case V_355 :
case V_272 :
case V_219 :
if ( F_4 ( V_3 ) ||
! F_140 ( V_3 ) )
F_59 ( V_3 , V_10 , 0 ) ;
break;
case V_8 :
if ( F_142 ( V_3 ) )
F_59 ( V_3 , V_377 , 0 ) ;
break;
case V_377 :
if ( ( V_3 -> V_19 == V_20 &&
V_3 -> V_21 != V_20 ) ||
( V_3 -> V_19 != V_20 &&
V_3 -> V_21 == V_20 ) )
V_428 = V_378 ;
else if ( F_4 ( V_3 ) )
V_428 = V_8 ;
else
break;
if ( V_428 != V_3 -> V_134 )
F_59 ( V_3 , V_377 , 0 ) ;
break;
case V_378 :
if ( F_4 ( V_3 ) )
V_428 = V_8 ;
else if ( V_3 -> V_249 )
V_428 = F_145 ( V_3 ) ? V_379 : V_363 ;
else
V_428 = V_8 ;
if ( V_428 != V_3 -> V_134 )
F_59 ( V_3 , V_378 , 0 ) ;
break;
case V_220 :
if ( F_4 ( V_3 ) )
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
else if ( ! V_3 -> V_320 &&
( V_19 != V_426 || V_21 != V_427 ) )
F_48 ( V_3 ,
F_47 ( V_3 ) ,
5000 ) ;
break;
case V_353 :
if ( V_19 == V_20 || V_21 == V_20 )
F_59 ( V_3 , V_397 , 0 ) ;
break;
case V_397 :
if ( F_119 ( V_3 ) )
F_59 ( V_3 , V_353 , 0 ) ;
break;
case V_351 :
if ( V_19 == V_20 || V_21 == V_20 )
F_59 ( V_3 , V_396 , 0 ) ;
break;
case V_354 :
break;
case V_387 :
if ( F_4 ( V_3 ) )
F_59 ( V_3 , V_390 , 0 ) ;
break;
case V_390 :
break;
case V_359 :
if ( ! V_3 -> V_249 && F_140 ( V_3 ) )
F_59 ( V_3 , V_365 , 0 ) ;
break;
case V_365 :
if ( V_3 -> V_249 || ! F_140 ( V_3 ) )
F_59 ( V_3 , V_359 , 0 ) ;
break;
case V_358 :
if ( ! F_142 ( V_3 ) ) {
V_3 -> V_360 = 0 ;
F_59 ( V_3 , V_359 , 0 ) ;
}
break;
case V_381 :
if ( F_140 ( V_3 ) )
F_59 ( V_3 , V_383 , 0 ) ;
break;
case V_383 :
F_59 ( V_3 , V_381 , 0 ) ;
break;
case V_385 :
if ( F_142 ( V_3 ) )
F_59 ( V_3 , V_384 , 0 ) ;
break;
case V_384 :
if ( ! F_142 ( V_3 ) )
F_59 ( V_3 , V_385 , 0 ) ;
break;
case V_382 :
break;
case V_256 :
case V_412 :
case V_413 :
case V_254 :
case V_257 :
break;
default:
if ( F_4 ( V_3 ) )
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
break;
}
}
static void F_151 ( struct V_2 * V_3 )
{
F_16 ( V_3 , L_60 ) ;
V_3 -> V_249 = true ;
switch ( V_3 -> V_37 ) {
case V_253 :
V_3 -> V_252 = true ;
F_59 ( V_3 , V_220 , 0 ) ;
break;
case V_387 :
F_59 ( V_3 , V_387 , 0 ) ;
break;
case V_378 :
F_59 ( V_3 , F_145 ( V_3 ) ? V_379
: V_363 ,
0 ) ;
break;
case V_407 :
F_59 ( V_3 , V_405 , 0 ) ;
break;
case V_355 :
F_59 ( V_3 , V_367 , 0 ) ;
break;
case V_403 :
F_59 ( V_3 , V_367 , 0 ) ;
break;
case V_354 :
break;
case V_359 :
break;
case V_365 :
F_59 ( V_3 , V_359 , 0 ) ;
break;
case V_358 :
break;
case V_382 :
break;
case V_384 :
if ( F_142 ( V_3 ) )
F_59 ( V_3 , V_363 , 0 ) ;
break;
case V_385 :
break;
case V_381 :
case V_383 :
break;
default:
break;
}
}
static void F_152 ( struct V_2 * V_3 )
{
F_16 ( V_3 , L_61 ) ;
V_3 -> V_249 = false ;
V_3 -> V_392 = false ;
switch ( V_3 -> V_37 ) {
case V_402 :
F_59 ( V_3 , V_407 , 0 ) ;
break;
case V_400 :
F_59 ( V_3 , V_403 , 0 ) ;
break;
case V_336 :
break;
case V_354 :
break;
case V_359 :
if ( F_140 ( V_3 ) )
F_59 ( V_3 , V_365 , 0 ) ;
break;
case V_358 :
break;
case V_382 :
case V_384 :
case V_385 :
break;
case V_377 :
F_59 ( V_3 , V_8 , 0 ) ;
break;
case V_228 :
break;
case V_412 :
F_59 ( V_3 , V_413 , 0 ) ;
break;
case V_256 :
break;
case V_424 :
F_59 ( V_3 , F_1 ( V_3 ) , 0 ) ;
break;
case V_381 :
case V_383 :
break;
default:
if ( V_3 -> V_114 == V_7 &&
V_3 -> V_18 )
F_59 ( V_3 , V_8 , 0 ) ;
break;
}
}
static void F_153 ( struct V_2 * V_3 )
{
F_16 ( V_3 , L_62 ) ;
F_59 ( V_3 ,
V_3 -> V_334 < V_335 ?
V_399 : V_290 ,
0 ) ;
}
static void F_154 ( struct V_224 * V_225 )
{
struct V_2 * V_3 = F_3 ( V_225 , struct V_2 ,
V_429 ) ;
T_3 V_430 ;
F_9 ( & V_3 -> V_74 ) ;
F_155 ( & V_3 -> V_431 ) ;
while ( V_3 -> V_432 ) {
V_430 = V_3 -> V_432 ;
V_3 -> V_432 = 0 ;
F_156 ( & V_3 -> V_431 ) ;
if ( V_430 & V_433 )
F_153 ( V_3 ) ;
if ( V_430 & V_434 ) {
bool V_435 ;
V_435 = V_3 -> V_11 -> V_436 ( V_3 -> V_11 ) ;
if ( V_435 )
F_151 ( V_3 ) ;
else
F_152 ( V_3 ) ;
}
if ( V_430 & V_437 ) {
enum V_98 V_19 , V_21 ;
if ( V_3 -> V_11 -> V_438 ( V_3 -> V_11 , & V_19 , & V_21 ) == 0 )
F_149 ( V_3 , V_19 , V_21 ) ;
}
F_155 ( & V_3 -> V_431 ) ;
}
F_156 ( & V_3 -> V_431 ) ;
F_14 ( & V_3 -> V_74 ) ;
}
void F_157 ( struct V_2 * V_3 )
{
F_155 ( & V_3 -> V_431 ) ;
V_3 -> V_432 |= V_437 ;
F_156 ( & V_3 -> V_431 ) ;
F_95 ( V_3 -> V_135 , & V_3 -> V_429 ) ;
}
void F_158 ( struct V_2 * V_3 )
{
F_155 ( & V_3 -> V_431 ) ;
V_3 -> V_432 |= V_434 ;
F_156 ( & V_3 -> V_431 ) ;
F_95 ( V_3 -> V_135 , & V_3 -> V_429 ) ;
}
void F_159 ( struct V_2 * V_3 )
{
F_155 ( & V_3 -> V_431 ) ;
V_3 -> V_432 = V_433 ;
F_156 ( & V_3 -> V_431 ) ;
F_95 ( V_3 -> V_135 , & V_3 -> V_429 ) ;
}
static int F_160 ( const struct V_15 * V_16 ,
enum V_118 V_119 )
{
struct V_2 * V_3 = F_2 ( V_16 ) ;
int V_70 ;
F_9 ( & V_3 -> V_439 ) ;
F_9 ( & V_3 -> V_74 ) ;
if ( V_3 -> V_4 != V_5 ) {
V_70 = - V_296 ;
goto V_440;
}
if ( V_3 -> V_37 != V_219 && V_3 -> V_37 != V_220 ) {
V_70 = - V_82 ;
goto V_440;
}
if ( V_3 -> V_115 == V_119 ) {
V_70 = 0 ;
goto V_440;
}
if ( ! V_3 -> V_320 ) {
if ( V_3 -> V_6 == V_441 ||
V_3 -> V_6 == V_3 -> V_114 ) {
V_70 = - V_296 ;
goto V_440;
}
V_3 -> V_340 = true ;
F_59 ( V_3 , V_380 , 0 ) ;
} else {
F_59 ( V_3 , V_262 , 0 ) ;
}
V_3 -> V_263 = 0 ;
V_3 -> V_339 = true ;
F_38 ( & V_3 -> V_341 ) ;
F_14 ( & V_3 -> V_74 ) ;
if ( ! F_39 ( & V_3 -> V_341 ,
F_40 ( V_442 ) ) )
V_70 = - V_76 ;
else
V_70 = V_3 -> V_263 ;
V_3 -> V_340 = false ;
goto V_443;
V_440:
F_14 ( & V_3 -> V_74 ) ;
V_443:
F_14 ( & V_3 -> V_439 ) ;
return V_70 ;
}
static int F_161 ( const struct V_15 * V_16 ,
enum V_116 V_117 )
{
struct V_2 * V_3 = F_2 ( V_16 ) ;
int V_70 ;
F_9 ( & V_3 -> V_439 ) ;
F_9 ( & V_3 -> V_74 ) ;
if ( V_3 -> V_4 != V_5 ) {
V_70 = - V_296 ;
goto V_440;
}
if ( V_3 -> V_37 != V_219 && V_3 -> V_37 != V_220 ) {
V_70 = - V_82 ;
goto V_440;
}
if ( V_117 == V_3 -> V_114 ) {
V_70 = 0 ;
goto V_440;
}
V_3 -> V_263 = 0 ;
V_3 -> V_339 = true ;
F_38 ( & V_3 -> V_341 ) ;
F_59 ( V_3 , V_265 , 0 ) ;
F_14 ( & V_3 -> V_74 ) ;
if ( ! F_39 ( & V_3 -> V_341 ,
F_40 ( V_442 ) ) )
V_70 = - V_76 ;
else
V_70 = V_3 -> V_263 ;
goto V_443;
V_440:
F_14 ( & V_3 -> V_74 ) ;
V_443:
F_14 ( & V_3 -> V_439 ) ;
return V_70 ;
}
static int F_162 ( const struct V_15 * V_16 ,
enum V_116 V_117 )
{
struct V_2 * V_3 = F_2 ( V_16 ) ;
int V_70 ;
F_9 ( & V_3 -> V_439 ) ;
F_9 ( & V_3 -> V_74 ) ;
if ( V_3 -> V_37 != V_219 && V_3 -> V_37 != V_220 ) {
V_70 = - V_82 ;
goto V_440;
}
if ( V_117 == V_3 -> V_96 ) {
V_70 = 0 ;
goto V_440;
}
V_3 -> V_263 = 0 ;
V_3 -> V_339 = true ;
F_38 ( & V_3 -> V_341 ) ;
F_59 ( V_3 , V_267 , 0 ) ;
F_14 ( & V_3 -> V_74 ) ;
if ( ! F_39 ( & V_3 -> V_341 ,
F_40 ( V_442 ) ) )
V_70 = - V_76 ;
else
V_70 = V_3 -> V_263 ;
goto V_443;
V_440:
F_14 ( & V_3 -> V_74 ) ;
V_443:
F_14 ( & V_3 -> V_439 ) ;
return V_70 ;
}
static int F_163 ( const struct V_15 * V_16 , int V_117 )
{
struct V_2 * V_3 = F_2 ( V_16 ) ;
struct V_444 * V_11 = V_3 -> V_11 ;
int V_70 = 0 ;
F_9 ( & V_3 -> V_74 ) ;
if ( V_11 -> V_6 )
V_70 = V_11 -> V_6 ( V_11 , V_117 ) ;
if ( ! V_70 && ! V_11 -> V_12 -> V_445 )
V_3 -> V_6 = V_117 ;
V_3 -> V_332 = 0 ;
V_3 -> V_333 = 0 ;
F_14 ( & V_3 -> V_74 ) ;
return V_70 ;
}
static void F_164 ( struct V_2 * V_3 )
{
enum V_98 V_19 , V_21 ;
V_3 -> V_11 -> V_446 ( V_3 -> V_11 ) ;
F_126 ( V_3 ) ;
V_3 -> V_249 = V_3 -> V_11 -> V_436 ( V_3 -> V_11 ) ;
if ( V_3 -> V_249 )
V_3 -> V_392 = true ;
F_59 ( V_3 , F_1 ( V_3 ) , 0 ) ;
if ( V_3 -> V_11 -> V_438 ( V_3 -> V_11 , & V_19 , & V_21 ) == 0 )
F_149 ( V_3 , V_19 , V_21 ) ;
F_59 ( V_3 , V_380 , 0 ) ;
}
static int F_165 ( const struct V_15 * V_16 ,
enum V_447 type )
{
struct V_2 * V_3 = F_2 ( V_16 ) ;
F_9 ( & V_3 -> V_74 ) ;
if ( type == V_3 -> V_4 )
goto V_440;
V_3 -> V_4 = type ;
if ( ! V_3 -> V_317 ) {
F_59 ( V_3 , V_380 , 0 ) ;
} else if ( type == V_14 ) {
if ( ! ( V_3 -> V_114 == V_7 &&
V_3 -> V_115 == V_189 ) )
F_59 ( V_3 , V_380 , 0 ) ;
} else if ( type == V_337 ) {
if ( ! ( V_3 -> V_114 == V_9 &&
V_3 -> V_115 == V_120 ) )
F_59 ( V_3 , V_380 , 0 ) ;
}
V_440:
F_14 ( & V_3 -> V_74 ) ;
return 0 ;
}
void F_166 ( struct V_2 * V_3 )
{
F_9 ( & V_3 -> V_74 ) ;
F_164 ( V_3 ) ;
F_14 ( & V_3 -> V_74 ) ;
}
static int F_167 ( T_3 * V_448 , const T_3 * V_109 ,
unsigned int V_110 )
{
unsigned int V_39 ;
if ( V_110 > V_449 )
V_110 = V_449 ;
for ( V_39 = 0 ; V_39 < V_110 ; V_39 ++ )
V_448 [ V_39 ] = V_109 [ V_39 ] ;
return V_110 ;
}
static int F_168 ( T_3 * V_450 , const T_3 * V_451 ,
unsigned int V_452 )
{
unsigned int V_39 ;
if ( V_452 > V_453 )
V_452 = V_453 ;
for ( V_39 = 0 ; V_39 < V_452 ; V_39 ++ )
V_450 [ V_39 ] = V_451 [ V_39 ] ;
return V_452 ;
}
void F_169 ( struct V_2 * V_3 , const T_3 * V_41 ,
unsigned int V_110 )
{
F_9 ( & V_3 -> V_74 ) ;
V_3 -> V_111 = F_167 ( V_3 -> V_109 , V_41 , V_110 ) ;
switch ( V_3 -> V_37 ) {
case V_10 :
case V_350 :
case V_359 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
break;
case V_272 :
case V_232 :
case V_219 :
case V_372 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
F_59 ( V_3 , V_272 , 0 ) ;
break;
default:
break;
}
F_14 ( & V_3 -> V_74 ) ;
}
void F_170 ( struct V_2 * V_3 , const T_3 * V_41 ,
unsigned int V_110 ,
unsigned int V_304 ,
unsigned int V_303 ,
unsigned int V_306 ,
unsigned int V_309 )
{
F_9 ( & V_3 -> V_74 ) ;
V_3 -> V_129 = F_167 ( V_3 -> V_131 , V_41 , V_110 ) ;
V_3 -> V_304 = V_304 ;
V_3 -> V_303 = V_303 ;
V_3 -> V_306 = V_306 ;
V_3 -> V_309 = V_309 ;
switch ( V_3 -> V_37 ) {
case V_228 :
case V_220 :
case V_248 :
case V_253 :
F_59 ( V_3 , V_228 , 0 ) ;
break;
default:
break;
}
F_14 ( & V_3 -> V_74 ) ;
}
struct V_2 * F_171 ( struct V_454 * V_36 , struct V_444 * V_11 )
{
struct V_2 * V_3 ;
int V_39 , V_455 ;
if ( ! V_36 || ! V_11 || ! V_11 -> V_12 ||
! V_11 -> V_436 || ! V_11 -> V_316 || ! V_11 -> V_438 ||
! V_11 -> V_93 || ! V_11 -> V_95 || ! V_11 -> V_313 ||
! V_11 -> V_326 || ! V_11 -> V_113 || ! V_11 -> V_73 )
return F_172 ( - V_296 ) ;
V_3 = F_173 ( V_36 , sizeof( * V_3 ) , V_34 ) ;
if ( ! V_3 )
return F_172 ( - V_63 ) ;
V_3 -> V_36 = V_36 ;
V_3 -> V_11 = V_11 ;
F_30 ( & V_3 -> V_74 ) ;
F_30 ( & V_3 -> V_439 ) ;
V_3 -> V_135 = F_174 ( F_33 ( V_36 ) ) ;
if ( ! V_3 -> V_135 )
return F_172 ( - V_63 ) ;
F_175 ( & V_3 -> V_136 , F_148 ) ;
F_175 ( & V_3 -> V_205 , F_85 ) ;
F_94 ( & V_3 -> V_429 , F_154 ) ;
F_176 ( & V_3 -> V_431 ) ;
F_177 ( & V_3 -> V_72 ) ;
F_177 ( & V_3 -> V_341 ) ;
V_3 -> V_111 = F_167 ( V_3 -> V_109 , V_11 -> V_12 -> V_109 ,
V_11 -> V_12 -> V_111 ) ;
V_3 -> V_129 = F_167 ( V_3 -> V_131 , V_11 -> V_12 -> V_131 ,
V_11 -> V_12 -> V_129 ) ;
V_3 -> V_190 = F_168 ( V_3 -> V_191 , V_11 -> V_12 -> V_191 ,
V_11 -> V_12 -> V_190 ) ;
V_3 -> V_304 = V_11 -> V_12 -> V_304 ;
V_3 -> V_303 = V_11 -> V_12 -> V_303 ;
V_3 -> V_306 = V_11 -> V_12 -> V_306 ;
V_3 -> V_309 = V_11 -> V_12 -> V_309 ;
if ( ! V_11 -> V_12 -> V_445 )
V_3 -> V_6 = V_11 -> V_12 -> V_13 ;
else
V_3 -> V_6 = V_441 ;
V_3 -> V_17 . V_456 = V_11 -> V_12 -> V_13 ;
V_3 -> V_17 . type = V_11 -> V_12 -> type ;
V_3 -> V_17 . V_457 = 0x0120 ;
V_3 -> V_17 . V_458 = 0x0200 ;
V_3 -> V_17 . V_459 = F_160 ;
V_3 -> V_17 . V_460 = F_161 ;
V_3 -> V_17 . V_461 = F_162 ;
V_3 -> V_17 . V_6 = F_163 ;
V_3 -> V_17 . V_462 = F_165 ;
V_3 -> V_318 . V_463 = & V_3 -> V_157 ;
V_3 -> V_4 = V_11 -> V_12 -> type ;
V_3 -> V_97 = F_178 ( V_3 -> V_36 , & V_3 -> V_17 ) ;
if ( ! V_3 -> V_97 ) {
V_455 = - V_63 ;
goto V_464;
}
if ( V_11 -> V_12 -> V_465 ) {
const struct V_169 * V_170 = V_11 -> V_12 -> V_465 ;
V_39 = 0 ;
while ( V_170 -> V_165 && V_39 < F_71 ( V_3 -> V_466 ) ) {
V_3 -> V_466 [ V_39 ] =
F_179 ( V_3 -> V_97 ,
V_170 ) ;
if ( ! V_3 -> V_466 [ V_39 ] ) {
F_15 ( V_3 ,
L_63 ,
F_33 ( V_36 ) , V_170 -> V_165 ) ;
break;
}
V_39 ++ ;
V_170 ++ ;
}
}
F_29 ( V_3 ) ;
F_9 ( & V_3 -> V_74 ) ;
F_164 ( V_3 ) ;
F_14 ( & V_3 -> V_74 ) ;
F_15 ( V_3 , L_64 , F_33 ( V_36 ) ) ;
return V_3 ;
V_464:
F_180 ( V_3 -> V_135 ) ;
return F_172 ( V_455 ) ;
}
void F_181 ( struct V_2 * V_3 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_71 ( V_3 -> V_466 ) ; V_39 ++ )
F_125 ( V_3 -> V_466 [ V_39 ] ) ;
F_182 ( V_3 -> V_97 ) ;
F_34 ( V_3 ) ;
F_180 ( V_3 -> V_135 ) ;
}
