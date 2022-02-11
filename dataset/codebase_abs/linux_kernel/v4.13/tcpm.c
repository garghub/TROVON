static enum V_1 F_1 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 == V_5 )
return V_6 ;
else if ( V_3 -> V_4 == V_7 )
return V_8 ;
else if ( V_3 -> V_9 -> V_10 -> V_11 == V_5 )
return V_6 ;
return V_8 ;
}
static inline
struct V_2 * F_2 ( const struct V_12 * V_13 )
{
return F_3 ( V_13 , struct V_2 , V_14 ) ;
}
static bool F_4 ( struct V_2 * V_3 )
{
return ( ! V_3 -> V_15 && V_3 -> V_16 == V_17 &&
V_3 -> V_18 == V_17 ) ||
( V_3 -> V_15 && ( ( V_3 -> V_19 == V_20 &&
V_3 -> V_16 == V_17 ) ||
( V_3 -> V_19 == V_21 &&
V_3 -> V_18 == V_17 ) ) ) ;
}
static bool F_5 ( struct V_2 * V_3 )
{
return V_3 -> V_22 ==
( V_3 -> V_23 + 1 ) % V_24 ;
}
static void F_6 ( struct V_2 * V_3 , const char * V_25 , T_1 args )
{
char V_26 [ V_27 ] ;
T_2 V_28 = F_7 () ;
unsigned long V_29 ;
if ( ! V_3 -> V_30 [ V_3 -> V_23 ] ) {
V_3 -> V_30 [ V_3 -> V_23 ] =
F_8 ( V_27 , V_31 ) ;
if ( ! V_3 -> V_30 [ V_3 -> V_23 ] )
return;
}
vsnprintf ( V_26 , sizeof( V_26 ) , V_25 , args ) ;
F_9 ( & V_3 -> V_32 ) ;
if ( F_5 ( V_3 ) ) {
V_3 -> V_23 = F_10 ( V_3 -> V_23 - 1 , 0 ) ;
strcpy ( V_26 , L_1 ) ;
}
if ( V_3 -> V_23 < 0 ||
V_3 -> V_23 >= V_24 ) {
F_11 ( V_3 -> V_33 ,
L_2 , V_3 -> V_23 ) ;
goto abort;
}
if ( ! V_3 -> V_30 [ V_3 -> V_23 ] ) {
F_11 ( V_3 -> V_33 ,
L_3 , V_3 -> V_23 ) ;
goto abort;
}
V_29 = F_12 ( V_28 , 1000000000 ) ;
F_13 ( V_3 -> V_30 [ V_3 -> V_23 ] ,
V_27 , L_4 ,
( unsigned long ) V_28 , V_29 / 1000 ,
V_26 ) ;
V_3 -> V_23 = ( V_3 -> V_23 + 1 ) % V_24 ;
abort:
F_14 ( & V_3 -> V_32 ) ;
}
static void F_15 ( struct V_2 * V_3 , const char * V_25 , ... )
{
T_1 args ;
if ( F_4 ( V_3 ) &&
( V_3 -> V_34 == V_8 || V_3 -> V_34 == V_6 ||
V_3 -> V_34 == V_35 ) )
return;
va_start ( args , V_25 ) ;
F_6 ( V_3 , V_25 , args ) ;
va_end ( args ) ;
}
static void F_16 ( struct V_2 * V_3 , const char * V_25 , ... )
{
T_1 args ;
va_start ( args , V_25 ) ;
F_6 ( V_3 , V_25 , args ) ;
va_end ( args ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_3 -> V_37 ; V_36 ++ ) {
T_3 V_38 = V_3 -> V_39 [ V_36 ] ;
enum V_40 type = F_18 ( V_38 ) ;
char V_41 [ 64 ] ;
switch ( type ) {
case V_42 :
F_13 ( V_41 , sizeof( V_41 ) ,
L_5 ,
F_19 ( V_38 ) ,
F_20 ( V_38 ) ,
( V_38 & V_43 ) ?
L_6 : L_7 ,
( V_38 & V_44 ) ?
L_8 : L_7 ,
( V_38 & V_45 ) ?
L_9 : L_7 ,
( V_38 & V_46 ) ?
L_10 : L_7 ,
( V_38 & V_47 ) ?
L_11 : L_7 ,
( V_38 & V_48 ) ?
L_12 : L_7 ) ;
break;
case V_49 :
F_13 ( V_41 , sizeof( V_41 ) ,
L_13 ,
F_21 ( V_38 ) ,
F_22 ( V_38 ) ,
F_20 ( V_38 ) ) ;
break;
case V_50 :
F_13 ( V_41 , sizeof( V_41 ) ,
L_14 ,
F_21 ( V_38 ) ,
F_22 ( V_38 ) ,
F_23 ( V_38 ) ) ;
break;
default:
strcpy ( V_41 , L_15 ) ;
break;
}
F_15 ( V_3 , L_16 ,
V_36 , type , V_41 ) ;
}
}
static int F_24 ( struct V_51 * V_52 , void * V_53 )
{
struct V_2 * V_3 = (struct V_2 * ) V_52 -> V_54 ;
int V_55 ;
F_9 ( & V_3 -> V_32 ) ;
V_55 = V_3 -> V_22 ;
while ( V_55 != V_3 -> V_23 ) {
F_25 ( V_52 , L_17 , V_3 -> V_30 [ V_55 ] ) ;
V_55 = ( V_55 + 1 ) % V_24 ;
}
if ( ! F_26 ( V_52 ) )
V_3 -> V_22 = V_55 ;
F_14 ( & V_3 -> V_32 ) ;
return 0 ;
}
static int F_27 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_28 ( V_57 , F_24 , V_56 -> V_58 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
F_30 ( & V_3 -> V_32 ) ;
if ( ! V_59 ) {
V_59 = F_31 ( L_18 , NULL ) ;
if ( ! V_59 )
return - V_60 ;
}
V_3 -> V_61 = F_32 ( F_33 ( V_3 -> V_33 ) ,
V_62 | 0444 , V_59 ,
V_3 , & V_63 ) ;
return 0 ;
}
static void F_34 ( struct V_2 * V_3 )
{
F_35 ( V_3 -> V_61 ) ;
}
static void F_15 ( const struct V_2 * V_3 , const char * V_25 , ... ) { }
static void F_16 ( struct V_2 * V_3 , const char * V_25 , ... ) { }
static void F_17 ( struct V_2 * V_3 ) { }
static int F_29 ( const struct V_2 * V_3 ) { return 0 ; }
static void F_34 ( const struct V_2 * V_3 ) { }
static int F_36 ( struct V_2 * V_3 ,
enum V_64 type ,
const struct V_65 * V_41 )
{
unsigned long V_66 ;
int V_67 ;
if ( V_41 )
F_15 ( V_3 , L_19 , F_37 ( V_41 -> V_68 ) ) ;
else
F_15 ( V_3 , L_20 , type ) ;
F_38 ( & V_3 -> V_69 ) ;
V_67 = V_3 -> V_9 -> V_70 ( V_3 -> V_9 , type , V_41 ) ;
if ( V_67 < 0 )
return V_67 ;
F_14 ( & V_3 -> V_71 ) ;
V_66 = F_39 ( & V_3 -> V_69 ,
F_40 ( V_72 ) ) ;
F_9 ( & V_3 -> V_71 ) ;
if ( ! V_66 )
return - V_73 ;
switch ( V_3 -> V_74 ) {
case V_75 :
V_3 -> V_76 = ( V_3 -> V_76 + 1 ) & V_77 ;
return 0 ;
case V_78 :
return - V_79 ;
case V_80 :
default:
return - V_81 ;
}
}
void F_41 ( struct V_2 * V_3 ,
enum V_82 V_83 )
{
F_15 ( V_3 , L_21 , V_83 ) ;
V_3 -> V_74 = V_83 ;
F_42 ( & V_3 -> V_69 ) ;
}
static int F_43 ( struct V_2 * V_3 , enum V_84 V_85 ,
enum V_86 V_10 )
{
int V_67 = 0 ;
F_15 ( V_3 , L_22 ,
V_85 , V_10 , V_3 -> V_19 ) ;
if ( V_3 -> V_9 -> V_87 )
V_67 = V_3 -> V_9 -> V_87 -> V_88 ( V_3 -> V_9 -> V_87 , V_85 , V_10 ,
V_3 -> V_19 ) ;
return V_67 ;
}
static int F_44 ( struct V_2 * V_3 ,
enum V_89 V_19 )
{
int V_67 ;
F_15 ( V_3 , L_23 , V_19 ) ;
V_67 = V_3 -> V_9 -> V_90 ( V_3 -> V_9 , V_19 ) ;
if ( V_67 < 0 )
return V_67 ;
V_3 -> V_19 = V_19 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , bool V_91 )
{
int V_67 ;
F_15 ( V_3 , L_24 , V_91 ) ;
V_67 = V_3 -> V_9 -> V_92 ( V_3 -> V_9 , V_91 ) ;
if ( ! V_67 ) {
V_3 -> V_93 = V_91 ? V_7 : V_5 ;
F_46 ( V_3 -> V_94 , V_3 -> V_93 ) ;
}
return V_67 ;
}
static T_3 F_47 ( struct V_2 * V_3 )
{
enum V_95 V_96 ;
T_3 V_97 ;
V_96 = V_3 -> V_19 ? V_3 -> V_18 : V_3 -> V_16 ;
switch ( V_96 ) {
case V_98 :
V_97 = 1500 ;
break;
case V_99 :
V_97 = 3000 ;
break;
case V_100 :
default:
V_97 = 0 ;
break;
}
return V_97 ;
}
static int F_48 ( struct V_2 * V_3 , T_3 V_101 , T_3 V_102 )
{
int V_67 = - V_103 ;
F_15 ( V_3 , L_25 , V_102 , V_101 ) ;
if ( V_3 -> V_9 -> V_104 )
V_67 = V_3 -> V_9 -> V_104 ( V_3 -> V_9 , V_101 , V_102 ) ;
return V_67 ;
}
static enum V_95 F_49 ( struct V_2 * V_3 )
{
const T_3 * V_105 = V_3 -> V_105 ;
int V_106 = V_3 -> V_107 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_106 ; V_36 ++ ) {
const T_3 V_38 = V_105 [ V_36 ] ;
if ( F_18 ( V_38 ) == V_42 &&
F_19 ( V_38 ) == 5000 ) {
unsigned int V_108 = F_20 ( V_38 ) ;
if ( V_108 >= 3000 )
return V_99 ;
else if ( V_108 >= 1500 )
return V_98 ;
return V_100 ;
}
}
return V_100 ;
}
static int F_50 ( struct V_2 * V_3 , bool V_15 )
{
return V_3 -> V_9 -> V_109 ( V_3 -> V_9 , V_15 , V_3 -> V_110 ,
V_3 -> V_111 ) ;
}
static int F_51 ( struct V_2 * V_3 , bool V_15 ,
enum V_112 V_113 , enum V_114 V_115 )
{
int V_67 ;
if ( V_115 == V_116 )
V_67 = F_43 ( V_3 , V_117 ,
V_118 ) ;
else
V_67 = F_43 ( V_3 , V_119 ,
V_120 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = V_3 -> V_9 -> V_109 ( V_3 -> V_9 , V_15 , V_113 , V_115 ) ;
if ( V_67 < 0 )
return V_67 ;
V_3 -> V_110 = V_113 ;
V_3 -> V_111 = V_115 ;
F_52 ( V_3 -> V_94 , V_115 ) ;
F_53 ( V_3 -> V_94 , V_113 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 , enum V_112 V_113 )
{
int V_67 ;
V_67 = V_3 -> V_9 -> V_109 ( V_3 -> V_9 , true , V_113 ,
V_3 -> V_111 ) ;
if ( V_67 < 0 )
return V_67 ;
V_3 -> V_110 = V_113 ;
F_53 ( V_3 -> V_94 , V_113 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_65 V_41 ;
int V_36 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
if ( ! V_3 -> V_107 ) {
V_41 . V_68 = F_56 ( V_121 ,
V_3 -> V_110 ,
V_3 -> V_111 ,
V_3 -> V_76 , 0 ) ;
} else {
V_41 . V_68 = F_56 ( V_122 ,
V_3 -> V_110 ,
V_3 -> V_111 ,
V_3 -> V_76 ,
V_3 -> V_107 ) ;
}
for ( V_36 = 0 ; V_36 < V_3 -> V_107 ; V_36 ++ )
V_41 . V_123 [ V_36 ] = F_57 ( V_3 -> V_105 [ V_36 ] ) ;
return F_36 ( V_3 , V_124 , & V_41 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_65 V_41 ;
int V_36 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
if ( ! V_3 -> V_125 ) {
V_41 . V_68 = F_56 ( V_121 ,
V_3 -> V_110 ,
V_3 -> V_111 ,
V_3 -> V_76 , 0 ) ;
} else {
V_41 . V_68 = F_56 ( V_126 ,
V_3 -> V_110 ,
V_3 -> V_111 ,
V_3 -> V_76 ,
V_3 -> V_125 ) ;
}
for ( V_36 = 0 ; V_36 < V_3 -> V_125 ; V_36 ++ )
V_41 . V_123 [ V_36 ] = F_57 ( V_3 -> V_127 [ V_36 ] ) ;
return F_36 ( V_3 , V_124 , & V_41 ) ;
}
static void F_59 ( struct V_2 * V_3 , enum V_1 V_34 ,
unsigned int V_128 )
{
if ( V_128 ) {
F_15 ( V_3 , L_26 ,
V_129 [ V_3 -> V_34 ] , V_129 [ V_34 ] ,
V_128 ) ;
V_3 -> V_130 = V_34 ;
F_60 ( V_3 -> V_131 , & V_3 -> V_132 ,
F_40 ( V_128 ) ) ;
V_3 -> V_133 = V_134 + F_40 ( V_128 ) ;
V_3 -> V_128 = V_128 ;
} else {
F_15 ( V_3 , L_27 ,
V_129 [ V_3 -> V_34 ] , V_129 [ V_34 ] ) ;
V_3 -> V_130 = V_135 ;
V_3 -> V_136 = V_3 -> V_34 ;
V_3 -> V_34 = V_34 ;
if ( ! V_3 -> V_137 )
F_60 ( V_3 -> V_131 , & V_3 -> V_132 , 0 ) ;
}
}
static void F_61 ( struct V_2 * V_3 , enum V_1 V_34 ,
unsigned int V_128 )
{
if ( V_3 -> V_138 == V_3 -> V_34 )
F_59 ( V_3 , V_34 , V_128 ) ;
else
F_15 ( V_3 ,
L_28 ,
V_128 ? L_29 : L_7 ,
V_129 [ V_3 -> V_34 ] , V_129 [ V_34 ] ,
V_128 , V_129 [ V_3 -> V_138 ] ) ;
}
static void F_62 ( struct V_2 * V_3 ,
enum V_139 V_140 )
{
V_3 -> V_141 = V_140 ;
F_60 ( V_3 -> V_131 , & V_3 -> V_132 , 0 ) ;
}
static void F_63 ( struct V_2 * V_3 , const T_3 V_68 ,
const T_3 * V_115 , int V_142 )
{
V_3 -> V_143 = V_142 + 1 ;
V_3 -> V_144 [ 0 ] = V_68 ;
memcpy ( & V_3 -> V_144 [ 1 ] , V_115 , sizeof( T_3 ) * V_142 ) ;
V_3 -> V_145 = 0 ;
V_3 -> V_146 = V_147 ;
}
static void F_64 ( struct V_2 * V_3 , const T_4 * V_123 ,
int V_142 )
{
T_3 V_148 = F_65 ( V_123 [ V_149 ] ) ;
T_3 V_150 = F_65 ( V_123 [ V_151 ] ) ;
memset ( & V_3 -> V_152 , 0 , sizeof( V_3 -> V_152 ) ) ;
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
V_3 -> V_153 . V_154 = V_148 ;
V_3 -> V_153 . V_155 = F_65 ( V_123 [ V_156 ] ) ;
V_3 -> V_153 . V_150 = V_150 ;
F_66 ( V_3 -> V_157 ) ;
F_15 ( V_3 , L_30 ,
F_67 ( V_148 ) ,
F_68 ( V_150 ) , V_150 & 0xffff ) ;
}
static bool F_69 ( struct V_2 * V_3 , const T_4 * V_123 ,
int V_142 )
{
struct V_158 * V_159 = & V_3 -> V_152 ;
int V_36 ;
for ( V_36 = 1 ; V_36 < V_142 ; V_36 ++ ) {
T_3 V_160 = F_65 ( V_123 [ V_36 ] ) ;
T_5 V_161 ;
V_161 = ( V_160 >> 16 ) & 0xffff ;
if ( ! V_161 )
return false ;
if ( V_159 -> V_162 >= V_163 )
goto abort;
V_159 -> V_164 [ V_159 -> V_162 ++ ] = V_161 ;
F_15 ( V_3 , L_31 , V_159 -> V_162 , V_161 ) ;
V_161 = V_160 & 0xffff ;
if ( ! V_161 )
return false ;
if ( V_159 -> V_162 >= V_163 )
goto abort;
V_159 -> V_164 [ V_159 -> V_162 ++ ] = V_161 ;
F_15 ( V_3 , L_31 , V_159 -> V_162 , V_161 ) ;
}
return true ;
abort:
F_15 ( V_3 , L_32 , V_163 ) ;
return false ;
}
static void F_70 ( struct V_2 * V_3 , const T_4 * V_123 ,
int V_142 )
{
struct V_158 * V_159 = & V_3 -> V_152 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
int V_36 ;
if ( V_159 -> V_169 >= F_71 ( V_3 -> V_170 ) ) {
return;
}
V_166 = & V_159 -> V_171 [ V_159 -> V_169 ] ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
V_166 -> V_161 = V_159 -> V_164 [ V_159 -> V_172 ] ;
F_15 ( V_3 , L_33 ,
V_159 -> V_169 , V_166 -> V_161 ) ;
for ( V_36 = 1 ; V_36 < V_142 && V_166 -> V_173 < V_174 ; V_36 ++ ) {
V_168 = & V_166 -> V_175 [ V_166 -> V_173 ] ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_148 = F_65 ( V_123 [ V_36 ] ) ;
V_168 -> V_176 = V_36 - 1 ;
V_166 -> V_173 ++ ;
F_15 ( V_3 , L_34 ,
V_168 -> V_176 , V_168 -> V_148 ) ;
}
V_3 -> V_170 [ V_159 -> V_169 ] =
F_72 ( V_3 -> V_157 , V_166 ) ;
if ( V_3 -> V_170 [ V_159 -> V_169 ] == NULL ) {
F_15 ( V_3 ,
L_35 ,
V_166 -> V_161 ) ;
return;
}
V_159 -> V_169 ++ ;
}
static int F_73 ( struct V_2 * V_3 , const T_4 * V_123 , int V_142 ,
T_3 * V_177 )
{
T_3 V_178 = F_65 ( V_123 [ 0 ] ) ;
int V_179 = F_74 ( V_178 ) ;
int V_180 = F_75 ( V_178 ) ;
struct V_158 * V_181 ;
int V_182 = 0 ;
T_5 V_161 ;
int V_36 ;
F_15 ( V_3 , L_36 ,
V_178 , V_179 , V_180 , V_142 ) ;
V_181 = & V_3 -> V_152 ;
switch ( V_179 ) {
case V_183 :
switch ( V_180 ) {
case V_184 :
if ( V_3 -> V_111 == V_185 &&
V_3 -> V_186 ) {
for ( V_36 = 0 ; V_36 < V_3 -> V_186 ; V_36 ++ )
V_177 [ V_36 + 1 ]
= F_57 ( V_3 -> V_187 [ V_36 ] ) ;
V_182 = V_3 -> V_186 + 1 ;
}
break;
case V_188 :
break;
case V_189 :
break;
case V_190 :
break;
case V_191 :
break;
case V_192 :
break;
default:
break;
}
if ( V_182 >= 1 ) {
V_177 [ 0 ] = V_178 | F_76 ( V_193 ) ;
} else if ( V_182 == 0 ) {
V_177 [ 0 ] = V_178 | F_76 ( V_194 ) ;
V_182 = 1 ;
} else {
V_177 [ 0 ] = V_178 | F_76 ( V_195 ) ;
V_182 = 1 ;
}
break;
case V_193 :
if ( ! V_3 -> V_157 )
break;
switch ( V_180 ) {
case V_184 :
F_64 ( V_3 , V_123 , V_142 ) ;
V_177 [ 0 ] = F_77 ( V_196 , 1 , V_188 ) ;
V_182 = 1 ;
break;
case V_188 :
if ( F_69 ( V_3 , V_123 , V_142 ) ) {
V_177 [ 0 ] = F_77 ( V_196 , 1 ,
V_188 ) ;
V_182 = 1 ;
} else if ( V_181 -> V_162 && F_78 ( V_3 ) ) {
V_177 [ 0 ] = F_77 ( V_181 -> V_164 [ 0 ] , 1 ,
V_189 ) ;
V_182 = 1 ;
}
break;
case V_189 :
F_70 ( V_3 , V_123 , V_142 ) ;
V_181 -> V_172 ++ ;
if ( V_181 -> V_172 < V_181 -> V_162 ) {
V_161 = V_181 -> V_164 [ V_181 -> V_172 ] ;
V_177 [ 0 ] = F_77 ( V_161 , 1 , V_189 ) ;
V_182 = 1 ;
} else {
#if 0
response[0] = pd_dfp_enter_mode(port, 0, 0);
if (response[0])
rlen = 1;
#endif
}
break;
case V_190 :
break;
default:
break;
}
break;
default:
break;
}
return V_182 ;
}
static void F_79 ( struct V_2 * V_3 ,
const T_4 * V_123 , int V_142 )
{
int V_182 = 0 ;
T_3 V_177 [ 8 ] = { } ;
T_3 V_178 = F_65 ( V_123 [ 0 ] ) ;
if ( V_3 -> V_146 == V_197 ) {
if ( F_74 ( V_178 ) == V_195 ) {
V_3 -> V_146 = V_198 ;
V_3 -> V_199 = ( V_178 & ~ V_200 ) |
V_183 ;
F_60 ( V_3 -> V_131 , & V_3 -> V_201 ,
F_40 ( V_202 ) ) ;
return;
}
V_3 -> V_146 = V_203 ;
}
if ( F_80 ( V_178 ) )
V_182 = F_73 ( V_3 , V_123 , V_142 , V_177 ) ;
#if 0
else
rlen = tcpm_pd_custom_vdm(port, cnt, payload, response);
#endif
if ( V_182 > 0 ) {
F_63 ( V_3 , V_177 [ 0 ] , & V_177 [ 1 ] , V_182 - 1 ) ;
F_60 ( V_3 -> V_131 , & V_3 -> V_201 , 0 ) ;
}
}
static void F_81 ( struct V_2 * V_3 , T_3 V_204 , int V_180 ,
const T_3 * V_115 , int V_205 )
{
T_3 V_68 ;
if ( F_82 ( V_205 > V_206 - 1 ) )
V_205 = V_206 - 1 ;
V_68 = F_77 ( V_204 , ( ( V_204 & V_196 ) == V_196 ) ?
1 : ( F_75 ( V_180 ) <= V_192 ) , V_180 ) ;
F_63 ( V_3 , V_68 , V_115 , V_205 ) ;
F_60 ( V_3 -> V_131 , & V_3 -> V_201 , 0 ) ;
}
static unsigned int F_83 ( T_3 V_207 )
{
unsigned int V_66 ;
int V_180 = F_75 ( V_207 ) ;
if ( ! F_80 ( V_207 ) )
return V_208 ;
switch ( F_74 ( V_207 ) ) {
case V_183 :
if ( V_180 == V_190 || V_180 == V_191 )
V_66 = V_209 ;
else
V_66 = V_210 ;
break;
default:
if ( V_180 == V_190 || V_180 == V_191 )
V_66 = V_211 ;
else
V_66 = V_212 ;
break;
}
return V_66 ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_65 V_41 ;
int V_36 , V_213 ;
switch ( V_3 -> V_146 ) {
case V_147 :
if ( ! V_3 -> V_15 ) {
V_3 -> V_146 = V_214 ;
break;
}
if ( V_3 -> V_34 != V_215 && V_3 -> V_34 != V_216 )
break;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_68 = F_56 ( V_217 ,
V_3 -> V_110 ,
V_3 -> V_111 ,
V_3 -> V_76 , V_3 -> V_143 ) ;
for ( V_36 = 0 ; V_36 < V_3 -> V_143 ; V_36 ++ )
V_41 . V_123 [ V_36 ] = F_57 ( V_3 -> V_144 [ V_36 ] ) ;
V_213 = F_36 ( V_3 , V_124 , & V_41 ) ;
if ( V_213 < 0 ) {
V_3 -> V_146 = V_218 ;
} else {
unsigned long V_66 ;
V_3 -> V_145 = 0 ;
V_3 -> V_146 = V_197 ;
V_66 = F_83 ( V_3 -> V_144 [ 0 ] ) ;
F_60 ( V_3 -> V_131 , & V_3 -> V_201 ,
V_66 ) ;
}
break;
case V_198 :
V_3 -> V_144 [ 0 ] = V_3 -> V_199 ;
V_3 -> V_143 = 1 ;
V_3 -> V_146 = V_147 ;
break;
case V_197 :
V_3 -> V_146 = V_219 ;
break;
case V_218 :
if ( V_3 -> V_145 < 3 ) {
F_15 ( V_3 , L_37 ) ;
V_3 -> V_145 ++ ;
V_3 -> V_146 = V_147 ;
}
break;
default:
break;
}
}
static void F_85 ( struct V_220 * V_221 )
{
struct V_2 * V_3 = F_3 ( V_221 , struct V_2 ,
V_201 . V_221 ) ;
enum V_222 V_136 ;
F_9 ( & V_3 -> V_71 ) ;
do {
V_136 = V_3 -> V_146 ;
F_84 ( V_3 ) ;
} while ( V_3 -> V_146 != V_136 &&
V_3 -> V_146 != V_197 );
F_14 ( & V_3 -> V_71 ) ;
}
static void F_86 ( struct V_2 * V_3 ,
const struct V_65 * V_41 )
{
enum V_223 type = F_87 ( V_41 -> V_68 ) ;
unsigned int V_142 = F_88 ( V_41 -> V_68 ) ;
unsigned int V_36 ;
switch ( type ) {
case V_122 :
if ( V_3 -> V_110 != V_5 )
break;
for ( V_36 = 0 ; V_36 < V_142 ; V_36 ++ )
V_3 -> V_39 [ V_36 ] = F_65 ( V_41 -> V_123 [ V_36 ] ) ;
V_3 -> V_37 = V_142 ;
F_17 ( V_3 ) ;
F_59 ( V_3 , V_224 , 0 ) ;
break;
case V_225 :
if ( V_3 -> V_110 != V_7 ||
V_142 != 1 ) {
F_62 ( V_3 , V_226 ) ;
break;
}
V_3 -> V_227 = F_65 ( V_41 -> V_123 [ 0 ] ) ;
F_59 ( V_3 , V_228 , 0 ) ;
break;
case V_126 :
for ( V_36 = 0 ; V_36 < V_142 ; V_36 ++ )
V_3 -> V_229 [ V_36 ] = F_65 ( V_41 -> V_123 [ V_36 ] ) ;
V_3 -> V_230 = V_142 ;
break;
case V_217 :
F_79 ( V_3 , V_41 -> V_123 , V_142 ) ;
break;
case V_231 :
if ( V_3 -> V_34 == V_215 || V_3 -> V_34 == V_216 ) {
V_3 -> V_232 = F_65 ( V_41 -> V_123 [ 0 ] ) ;
F_59 ( V_3 , V_233 , 0 ) ;
}
break;
default:
F_15 ( V_3 , L_38 , type ) ;
break;
}
}
static void F_89 ( struct V_2 * V_3 ,
const struct V_65 * V_41 )
{
enum V_234 type = F_87 ( V_41 -> V_68 ) ;
enum V_1 V_235 ;
switch ( type ) {
case V_236 :
case V_237 :
break;
case V_238 :
switch ( V_3 -> V_34 ) {
case V_215 :
case V_216 :
F_62 ( V_3 , V_239 ) ;
break;
default:
F_62 ( V_3 , V_226 ) ;
break;
}
break;
case V_240 :
switch ( V_3 -> V_34 ) {
case V_215 :
case V_216 :
F_62 ( V_3 , V_241 ) ;
break;
default:
F_62 ( V_3 , V_226 ) ;
break;
}
break;
case V_242 :
break;
case V_243 :
switch ( V_3 -> V_34 ) {
case V_244 :
if ( V_3 -> V_245 ) {
F_48 ( V_3 ,
V_3 -> V_246 ,
V_3 -> V_247 ) ;
F_59 ( V_3 , V_216 , 0 ) ;
} else {
F_59 ( V_3 ,
V_248 , 0 ) ;
}
break;
case V_249 :
F_59 ( V_3 , V_250 , 0 ) ;
break;
case V_251 :
F_59 ( V_3 , V_252 , 0 ) ;
break;
case V_253 :
F_59 ( V_3 , V_254 , 0 ) ;
break;
default:
break;
}
break;
case V_121 :
case V_255 :
switch ( V_3 -> V_34 ) {
case V_224 :
if ( V_3 -> V_256 )
V_235 = V_216 ;
else
V_235 = V_257 ;
F_59 ( V_3 , V_235 , 0 ) ;
break;
case V_258 :
V_3 -> V_259 = ( type == V_255 ?
- V_79 : - V_103 ) ;
F_59 ( V_3 , V_260 , 0 ) ;
break;
case V_261 :
V_3 -> V_259 = ( type == V_255 ?
- V_79 : - V_103 ) ;
F_59 ( V_3 , V_262 , 0 ) ;
break;
case V_263 :
V_3 -> V_259 = ( type == V_255 ?
- V_79 : - V_103 ) ;
F_59 ( V_3 , V_264 , 0 ) ;
break;
default:
break;
}
break;
case V_265 :
switch ( V_3 -> V_34 ) {
case V_224 :
F_59 ( V_3 , V_244 , 0 ) ;
break;
case V_266 :
V_3 -> V_76 = 0 ;
V_3 -> V_267 = - 1 ;
if ( V_3 -> V_110 == V_7 )
V_235 = V_268 ;
else
V_235 = V_257 ;
F_59 ( V_3 , V_235 , 0 ) ;
break;
case V_258 :
F_59 ( V_3 , V_269 , 0 ) ;
break;
case V_261 :
F_59 ( V_3 , V_270 , 0 ) ;
break;
case V_263 :
F_59 ( V_3 , V_271 , 0 ) ;
break;
default:
break;
}
break;
case V_272 :
F_59 ( V_3 , V_273 , 0 ) ;
break;
case V_274 :
if ( V_3 -> V_14 . type != V_275 ) {
F_62 ( V_3 , V_226 ) ;
break;
}
switch ( V_3 -> V_34 ) {
case V_215 :
case V_216 :
F_59 ( V_3 , V_276 , 0 ) ;
break;
default:
F_62 ( V_3 , V_277 ) ;
break;
}
break;
case V_278 :
if ( V_3 -> V_14 . type != V_275 ) {
F_62 ( V_3 , V_226 ) ;
break;
}
switch ( V_3 -> V_34 ) {
case V_215 :
case V_216 :
F_59 ( V_3 , V_279 , 0 ) ;
break;
default:
F_62 ( V_3 , V_277 ) ;
break;
}
break;
case V_280 :
switch ( V_3 -> V_34 ) {
case V_215 :
case V_216 :
F_59 ( V_3 , V_281 , 0 ) ;
break;
default:
F_62 ( V_3 , V_277 ) ;
break;
}
break;
default:
F_15 ( V_3 , L_39 , type ) ;
break;
}
}
static void F_90 ( struct V_220 * V_221 )
{
struct V_282 * V_283 = F_3 ( V_221 ,
struct V_282 , V_221 ) ;
const struct V_65 * V_41 = & V_283 -> V_41 ;
unsigned int V_142 = F_88 ( V_41 -> V_68 ) ;
struct V_2 * V_3 = V_283 -> V_3 ;
F_9 ( & V_3 -> V_71 ) ;
F_15 ( V_3 , L_40 , F_37 ( V_41 -> V_68 ) ,
V_3 -> V_15 ) ;
if ( V_3 -> V_15 ) {
enum V_234 type = F_87 ( V_41 -> V_68 ) ;
unsigned int V_284 = F_91 ( V_41 -> V_68 ) ;
if ( V_284 == V_3 -> V_267 && type != V_272 )
goto V_285;
V_3 -> V_267 = V_284 ;
if ( ! ! ( F_37 ( V_41 -> V_68 ) & V_286 ) ==
( V_3 -> V_111 == V_116 ) ) {
F_15 ( V_3 ,
L_41 ) ;
F_59 ( V_3 , V_287 , 0 ) ;
} else {
if ( V_142 )
F_86 ( V_3 , V_41 ) ;
else
F_89 ( V_3 , V_41 ) ;
}
}
V_285:
F_14 ( & V_3 -> V_71 ) ;
F_92 ( V_283 ) ;
}
void F_93 ( struct V_2 * V_3 , const struct V_65 * V_41 )
{
struct V_282 * V_283 ;
V_283 = F_8 ( sizeof( * V_283 ) , V_288 ) ;
if ( ! V_283 )
return;
F_94 ( & V_283 -> V_221 , F_90 ) ;
V_283 -> V_3 = V_3 ;
memcpy ( & V_283 -> V_41 , V_41 , sizeof( * V_41 ) ) ;
F_95 ( V_3 -> V_131 , & V_283 -> V_221 ) ;
}
static int F_96 ( struct V_2 * V_3 ,
enum V_234 type )
{
struct V_65 V_41 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_68 = F_56 ( type , V_3 -> V_110 ,
V_3 -> V_111 ,
V_3 -> V_76 , 0 ) ;
return F_36 ( V_3 , V_124 , & V_41 ) ;
}
static bool F_97 ( struct V_2 * V_3 )
{
enum V_139 V_141 ;
do {
V_141 = V_3 -> V_141 ;
V_3 -> V_141 = V_289 ;
switch ( V_141 ) {
case V_277 :
F_96 ( V_3 , V_255 ) ;
break;
case V_226 :
F_96 ( V_3 , V_121 ) ;
break;
case V_241 :
F_58 ( V_3 ) ;
break;
case V_239 :
F_55 ( V_3 ) ;
break;
default:
break;
}
} while ( V_3 -> V_141 != V_289 );
if ( V_3 -> V_130 != V_135 ) {
if ( F_98 ( V_3 -> V_133 ) ) {
F_60 ( V_3 -> V_131 , & V_3 -> V_132 ,
V_3 -> V_133 - V_134 ) ;
return true ;
}
V_3 -> V_130 = V_135 ;
}
return false ;
}
static int F_99 ( struct V_2 * V_3 )
{
T_3 V_38 , V_290 = V_3 -> V_227 ;
unsigned int F_10 , V_291 , V_292 , V_176 ;
enum V_40 type ;
V_176 = F_100 ( V_290 ) ;
if ( ! V_176 || V_176 > V_3 -> V_107 )
return - V_293 ;
V_38 = V_3 -> V_105 [ V_176 - 1 ] ;
type = F_18 ( V_38 ) ;
switch ( type ) {
case V_42 :
case V_49 :
F_10 = F_101 ( V_290 ) ;
V_291 = F_102 ( V_290 ) ;
V_292 = F_20 ( V_38 ) ;
if ( V_291 > V_292 )
return - V_293 ;
if ( F_10 > V_292 && ! ( V_290 & V_294 ) )
return - V_293 ;
if ( type == V_42 )
F_15 ( V_3 ,
L_42 ,
F_19 ( V_38 ) , V_292 , V_291 , F_10 ) ;
else
F_15 ( V_3 ,
L_43 ,
F_21 ( V_38 ) , F_22 ( V_38 ) ,
V_292 , V_291 , F_10 ) ;
break;
case V_50 :
F_10 = F_103 ( V_290 ) ;
V_291 = F_104 ( V_290 ) ;
V_292 = F_23 ( V_38 ) ;
if ( V_291 > V_292 )
return - V_293 ;
if ( F_10 > V_292 && ! ( V_290 & V_294 ) )
return - V_293 ;
F_15 ( V_3 ,
L_44 ,
F_21 ( V_38 ) , F_22 ( V_38 ) ,
V_292 , V_291 , F_10 ) ;
break;
default:
return - V_293 ;
}
V_3 -> V_295 = V_176 == 1 ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 )
{
unsigned int V_36 , V_296 = 0 , V_297 = 0 ;
int V_67 = - V_293 ;
for ( V_36 = 0 ; V_36 < V_3 -> V_37 ; V_36 ++ ) {
T_3 V_38 = V_3 -> V_39 [ V_36 ] ;
enum V_40 type = F_18 ( V_38 ) ;
unsigned int V_102 , V_298 , V_299 ;
if ( type == V_42 )
V_102 = F_19 ( V_38 ) ;
else
V_102 = F_21 ( V_38 ) ;
if ( type == V_50 ) {
V_299 = F_23 ( V_38 ) ;
} else {
V_298 = F_106 ( F_20 ( V_38 ) ,
V_3 -> V_300 ) ;
V_299 = V_298 * V_102 / 1000 ;
}
if ( ( V_299 > V_296 || ( V_299 == V_296 && V_102 > V_297 ) ) &&
V_102 <= V_3 -> V_301 ) {
V_67 = V_36 ;
V_296 = V_299 ;
V_297 = V_102 ;
}
}
return V_67 ;
}
static int F_107 ( struct V_2 * V_3 , T_3 * V_290 )
{
unsigned int V_102 , V_298 , V_299 , V_302 ;
unsigned int V_101 , V_296 ;
enum V_40 type ;
int V_176 ;
T_3 V_38 ;
V_176 = F_105 ( V_3 ) ;
if ( V_176 < 0 )
return - V_293 ;
V_38 = V_3 -> V_39 [ V_176 ] ;
type = F_18 ( V_38 ) ;
if ( type == V_42 )
V_102 = F_19 ( V_38 ) ;
else
V_102 = F_21 ( V_38 ) ;
if ( type == V_50 ) {
V_299 = F_23 ( V_38 ) ;
V_298 = 1000 * F_106 ( V_299 , V_3 -> V_303 ) / V_102 ;
} else {
V_298 = F_106 ( F_20 ( V_38 ) ,
1000 * V_3 -> V_303 / V_102 ) ;
}
V_298 = F_106 ( V_298 , V_3 -> V_300 ) ;
V_302 = V_304 | V_305 ;
V_299 = V_298 * V_102 / 1000 ;
V_101 = V_298 ;
V_296 = V_299 ;
if ( V_299 < V_3 -> V_306 ) {
V_302 |= V_294 ;
V_296 = V_3 -> V_306 ;
V_101 = V_296 * 1000 / V_102 ;
}
F_15 ( V_3 , L_45 ,
V_3 -> V_307 , V_3 -> V_16 , V_3 -> V_18 , V_3 -> V_308 ,
V_3 -> V_93 == V_7 ? L_46 : L_47 ,
V_3 -> V_19 ) ;
if ( type == V_50 ) {
* V_290 = F_108 ( V_176 + 1 , V_299 , V_296 , V_302 ) ;
F_15 ( V_3 , L_48 ,
V_176 , V_102 , V_299 ,
V_302 & V_294 ? L_49 : L_7 ) ;
} else {
* V_290 = F_109 ( V_176 + 1 , V_298 , V_101 , V_302 ) ;
F_15 ( V_3 , L_50 ,
V_176 , V_102 , V_298 ,
V_302 & V_294 ? L_49 : L_7 ) ;
}
V_3 -> V_246 = V_298 ;
V_3 -> V_247 = V_102 ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 )
{
struct V_65 V_41 ;
int V_67 ;
T_3 V_290 ;
V_67 = F_107 ( V_3 , & V_290 ) ;
if ( V_67 < 0 )
return V_67 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_68 = F_56 ( V_225 ,
V_3 -> V_110 ,
V_3 -> V_111 ,
V_3 -> V_76 , 1 ) ;
V_41 . V_123 [ 0 ] = F_57 ( V_290 ) ;
return F_36 ( V_3 , V_124 , & V_41 ) ;
}
static int F_111 ( struct V_2 * V_3 , bool V_91 )
{
int V_67 ;
if ( V_91 && V_3 -> V_309 )
return - V_293 ;
F_15 ( V_3 , L_51 , V_91 , V_3 -> V_309 ) ;
V_67 = V_3 -> V_9 -> V_310 ( V_3 -> V_9 , V_91 , V_3 -> V_309 ) ;
if ( V_67 < 0 )
return V_67 ;
V_3 -> V_308 = V_91 ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , bool V_311 )
{
int V_67 ;
if ( V_311 && V_3 -> V_308 )
return - V_293 ;
if ( V_311 != V_3 -> V_309 ) {
F_15 ( V_3 , L_52 , V_3 -> V_308 , V_311 ) ;
V_67 = V_3 -> V_9 -> V_310 ( V_3 -> V_9 , V_3 -> V_308 ,
V_311 ) ;
if ( V_67 < 0 )
return V_67 ;
}
V_3 -> V_309 = V_311 ;
return 0 ;
}
static bool F_113 ( struct V_2 * V_3 )
{
int V_67 ;
if ( V_3 -> V_9 -> V_312 &&
V_3 -> V_14 . type == V_275 ) {
F_16 ( V_3 , L_53 ) ;
V_67 = V_3 -> V_9 -> V_312 ( V_3 -> V_9 ,
F_49 ( V_3 ) ) ;
if ( ! V_67 )
return true ;
}
return false ;
}
static void F_114 ( struct V_2 * V_3 , enum V_95 V_96 )
{
F_15 ( V_3 , L_54 , V_96 ) ;
V_3 -> V_307 = V_96 ;
V_3 -> V_9 -> V_313 ( V_3 -> V_9 , V_96 ) ;
}
static int F_115 ( struct V_2 * V_3 )
{
int V_67 ;
V_67 = V_3 -> V_9 -> V_310 ( V_3 -> V_9 , false , false ) ;
V_3 -> V_308 = false ;
V_3 -> V_309 = false ;
return V_67 ;
}
static int F_116 ( struct V_2 * V_3 )
{
int V_67 ;
V_67 = V_3 -> V_9 -> V_92 ( V_3 -> V_9 , false ) ;
V_3 -> V_93 = V_5 ;
return V_67 ;
}
static void F_117 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_314 ) {
memset ( & V_3 -> V_153 , 0 , sizeof( V_3 -> V_153 ) ) ;
V_3 -> V_315 . V_316 = V_3 -> V_317 ;
if ( F_118 ( V_3 ) )
V_3 -> V_315 . V_318 = V_319 ;
else if ( F_119 ( V_3 ) )
V_3 -> V_315 . V_318 = V_320 ;
else
V_3 -> V_315 . V_318 = V_321 ;
V_3 -> V_157 = F_120 ( V_3 -> V_94 ,
& V_3 -> V_315 ) ;
V_3 -> V_314 = true ;
}
}
static int F_121 ( struct V_2 * V_3 )
{
enum V_89 V_19 =
V_3 -> V_18 == V_322 ? V_21
: V_20 ;
int V_67 ;
if ( V_3 -> V_15 )
return 0 ;
V_67 = F_44 ( V_3 , V_19 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_51 ( V_3 , true , V_7 , V_116 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = V_3 -> V_9 -> V_323 ( V_3 -> V_9 , true ) ;
if ( V_67 < 0 )
goto V_324;
if ( ( V_19 == V_20 && V_3 -> V_18 == V_325 ) ||
( V_19 == V_21 && V_3 -> V_16 == V_325 ) ) {
V_67 = F_45 ( V_3 , true ) ;
if ( V_67 < 0 )
goto V_326;
}
V_67 = F_111 ( V_3 , true ) ;
if ( V_67 < 0 )
goto V_327;
V_3 -> V_317 = false ;
V_3 -> V_157 = NULL ;
V_3 -> V_15 = true ;
V_3 -> V_328 = true ;
return 0 ;
V_327:
F_45 ( V_3 , false ) ;
V_326:
V_3 -> V_9 -> V_323 ( V_3 -> V_9 , false ) ;
V_324:
F_43 ( V_3 , V_119 , V_120 ) ;
return V_67 ;
}
static void F_122 ( struct V_2 * V_3 )
{
if ( V_3 -> V_314 ) {
F_123 ( V_3 -> V_157 ) ;
V_3 -> V_157 = NULL ;
V_3 -> V_314 = false ;
}
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_158 * V_181 = & V_3 -> V_152 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_181 -> V_169 ; V_36 ++ ) {
F_125 ( V_3 -> V_170 [ V_36 ] ) ;
V_3 -> V_170 [ V_36 ] = NULL ;
}
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
}
static void F_126 ( struct V_2 * V_3 )
{
F_124 ( V_3 ) ;
F_122 ( V_3 ) ;
V_3 -> V_15 = false ;
V_3 -> V_317 = false ;
V_3 -> V_267 = - 1 ;
V_3 -> V_9 -> V_323 ( V_3 -> V_9 , false ) ;
F_115 ( V_3 ) ;
F_116 ( V_3 ) ;
F_48 ( V_3 , 0 , 0 ) ;
F_44 ( V_3 , V_20 ) ;
F_50 ( V_3 , false ) ;
V_3 -> V_329 = 0 ;
V_3 -> V_330 = 0 ;
}
static void F_127 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_15 )
return;
if ( F_4 ( V_3 ) )
V_3 -> V_331 = 0 ;
F_126 ( V_3 ) ;
}
static void F_128 ( struct V_2 * V_3 )
{
F_127 ( V_3 ) ;
}
static int F_129 ( struct V_2 * V_3 )
{
int V_67 ;
if ( V_3 -> V_15 )
return 0 ;
V_67 = F_44 ( V_3 , V_3 -> V_18 != V_17 ?
V_21 : V_20 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_51 ( V_3 , true , V_5 , V_185 ) ;
if ( V_67 < 0 )
return V_67 ;
V_3 -> V_317 = false ;
V_3 -> V_157 = NULL ;
V_3 -> V_15 = true ;
V_3 -> V_328 = true ;
return 0 ;
}
static void F_130 ( struct V_2 * V_3 )
{
F_127 ( V_3 ) ;
}
static int F_131 ( struct V_2 * V_3 )
{
int V_67 ;
if ( V_3 -> V_15 )
return 0 ;
V_67 = F_51 ( V_3 , true , V_7 , V_116 ) ;
if ( V_67 < 0 )
return V_67 ;
V_3 -> V_157 = NULL ;
F_117 ( V_3 ) ;
V_3 -> V_15 = true ;
return 0 ;
}
static void F_132 ( struct V_2 * V_3 )
{
F_127 ( V_3 ) ;
}
static inline enum V_1 F_133 ( struct V_2 * V_3 )
{
if ( V_3 -> V_331 < V_332 )
return V_333 ;
if ( V_3 -> V_317 )
return V_287 ;
if ( V_3 -> V_110 == V_7 )
return V_8 ;
if ( V_3 -> V_34 == V_257 )
return V_216 ;
return V_6 ;
}
static inline enum V_1 F_134 ( struct V_2 * V_3 )
{
if ( V_3 -> V_110 == V_7 )
return V_215 ;
else
return V_216 ;
}
static inline enum V_1 F_135 ( struct V_2 * V_3 )
{
if ( V_3 -> V_110 == V_7 )
return V_8 ;
else
return V_6 ;
}
static void F_136 ( struct V_2 * V_3 )
{
if ( V_3 -> V_111 == V_116 && V_3 -> V_328 &&
V_3 -> V_317 ) {
F_81 ( V_3 , V_196 , V_184 , NULL , 0 ) ;
V_3 -> V_328 = false ;
}
}
static void F_137 ( struct V_2 * V_3 , int V_334 )
{
if ( V_3 -> V_335 ) {
V_3 -> V_259 = V_334 ;
V_3 -> V_335 = false ;
F_42 ( & V_3 -> V_336 ) ;
}
}
static void F_138 ( struct V_2 * V_3 )
{
int V_67 ;
V_3 -> V_138 = V_3 -> V_34 ;
switch ( V_3 -> V_34 ) {
case V_35 :
break;
case V_8 :
F_137 ( V_3 , - V_337 ) ;
F_128 ( V_3 ) ;
if ( F_113 ( V_3 ) ) {
F_59 ( V_3 , V_35 , 0 ) ;
break;
}
F_114 ( V_3 , F_49 ( V_3 ) ) ;
if ( V_3 -> V_14 . type == V_275 )
F_59 ( V_3 , V_6 , V_338 ) ;
break;
case V_339 :
if ( F_118 ( V_3 ) )
F_59 ( V_3 , V_340 ,
V_341 ) ;
else if ( F_119 ( V_3 ) )
F_59 ( V_3 , V_342 ,
V_341 ) ;
else if ( F_139 ( V_3 ) )
F_59 ( V_3 ,
F_140 ( V_3 ) ? V_343
: V_344 ,
V_341 ) ;
break;
case V_343 :
V_3 -> V_330 ++ ;
F_114 ( V_3 , V_322 ) ;
F_59 ( V_3 , V_345 , V_346 ) ;
break;
case V_345 :
if ( V_3 -> V_245 && F_141 ( V_3 ) ) {
F_59 ( V_3 , V_347 , 0 ) ;
break;
}
if ( ! F_141 ( V_3 ) ) {
F_59 ( V_3 , V_348 ,
V_349 ) ;
break;
}
F_59 ( V_3 , V_350 , V_351 ) ;
break;
case V_348 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
if ( ! V_3 -> V_245 && F_139 ( V_3 ) )
F_59 ( V_3 , V_344 , V_341 ) ;
else
F_59 ( V_3 , V_350 ,
V_346 ) ;
break;
case V_350 :
F_59 ( V_3 , V_6 , 0 ) ;
break;
case V_344 :
V_67 = F_121 ( V_3 ) ;
F_59 ( V_3 , V_8 ,
V_67 < 0 ? 0 : V_352 ) ;
break;
case V_353 :
F_142 ( V_3 -> V_94 , V_354 ) ;
V_3 -> V_355 = V_354 ;
V_3 -> V_356 = 0 ;
V_3 -> V_76 = 0 ;
V_3 -> V_267 = - 1 ;
V_3 -> V_256 = false ;
F_59 ( V_3 , V_268 , 0 ) ;
break;
case V_268 :
V_3 -> V_356 ++ ;
if ( V_3 -> V_356 > V_357 ) {
F_59 ( V_3 , V_215 , 0 ) ;
break;
}
V_67 = F_55 ( V_3 ) ;
if ( V_67 < 0 ) {
F_59 ( V_3 , V_268 ,
V_358 ) ;
} else {
V_3 -> V_356 = 0 ;
V_3 -> V_317 = true ;
F_61 ( V_3 , F_133 ( V_3 ) ,
V_358 ) ;
}
break;
case V_228 :
V_67 = F_99 ( V_3 ) ;
if ( V_67 < 0 ) {
F_96 ( V_3 , V_121 ) ;
if ( ! V_3 -> V_256 ) {
F_59 ( V_3 ,
V_359 , 0 ) ;
} else {
F_59 ( V_3 , V_215 , 0 ) ;
}
} else {
F_96 ( V_3 , V_265 ) ;
F_59 ( V_3 , V_360 ,
V_361 ) ;
}
break;
case V_360 :
F_96 ( V_3 , V_243 ) ;
V_3 -> V_256 = true ;
F_142 ( V_3 -> V_94 , V_362 ) ;
V_3 -> V_355 = V_362 ;
F_61 ( V_3 , V_215 , 0 ) ;
break;
case V_215 :
#if 1
V_3 -> V_331 = 0 ;
#endif
V_3 -> V_329 = 0 ;
F_117 ( V_3 ) ;
F_136 ( V_3 ) ;
if ( V_3 -> V_355 == V_362 &&
! V_3 -> V_295 ) {
F_96 ( V_3 , V_237 ) ;
F_61 ( V_3 , V_215 ,
V_363 ) ;
}
break;
case V_359 :
break;
case V_6 :
F_137 ( V_3 , - V_337 ) ;
F_130 ( V_3 ) ;
if ( F_113 ( V_3 ) ) {
F_59 ( V_3 , V_35 , 0 ) ;
break;
}
F_114 ( V_3 , V_322 ) ;
if ( V_3 -> V_14 . type == V_275 )
F_59 ( V_3 , V_8 , V_364 ) ;
break;
case V_365 :
if ( ( V_3 -> V_16 == V_17 &&
V_3 -> V_18 != V_17 ) ||
( V_3 -> V_16 != V_17 &&
V_3 -> V_18 == V_17 ) )
F_59 ( V_3 , V_366 ,
V_341 ) ;
else if ( F_4 ( V_3 ) )
F_59 ( V_3 , V_6 ,
V_349 ) ;
break;
case V_366 :
if ( F_4 ( V_3 ) )
F_59 ( V_3 , V_6 ,
V_349 ) ;
else if ( V_3 -> V_245 )
F_59 ( V_3 ,
F_143 ( V_3 ) ? V_367
: V_347 ,
0 ) ;
else
F_59 ( V_3 , V_6 , V_352 ) ;
break;
case V_367 :
V_3 -> V_329 ++ ;
F_114 ( V_3 , F_49 ( V_3 ) ) ;
F_59 ( V_3 , V_368 , V_346 ) ;
break;
case V_369 :
F_59 ( V_3 , V_344 , V_349 ) ;
break;
case V_368 :
F_114 ( V_3 , V_322 ) ;
F_59 ( V_3 , V_370 , V_341 ) ;
break;
case V_370 :
if ( V_3 -> V_245 ) {
F_59 ( V_3 , V_347 , 0 ) ;
break;
}
if ( F_4 ( V_3 ) ) {
F_59 ( V_3 , V_6 ,
V_349 ) ;
break;
}
if ( F_139 ( V_3 ) )
F_59 ( V_3 , V_344 , 0 ) ;
break;
case V_371 :
F_59 ( V_3 , V_347 , V_341 ) ;
break;
case V_347 :
V_67 = F_129 ( V_3 ) ;
if ( V_67 < 0 )
F_59 ( V_3 , V_6 , 0 ) ;
else
F_59 ( V_3 , V_372 , 0 ) ;
break;
case V_372 :
F_142 ( V_3 -> V_94 , V_354 ) ;
V_3 -> V_355 = V_354 ;
V_3 -> V_76 = 0 ;
V_3 -> V_267 = - 1 ;
V_3 -> V_256 = false ;
F_59 ( V_3 , V_373 , 0 ) ;
break;
case V_373 :
if ( V_3 -> V_245 ) {
F_48 ( V_3 ,
F_47 ( V_3 ) ,
5000 ) ;
F_112 ( V_3 , true ) ;
F_59 ( V_3 , V_257 , 0 ) ;
break;
}
F_59 ( V_3 , F_133 ( V_3 ) ,
V_3 -> V_14 . type == V_275 ?
V_374 : V_375 ) ;
break;
case V_376 :
F_59 ( V_3 , V_377 ,
V_341 ) ;
break;
case V_377 :
if ( ! F_4 ( V_3 ) &&
F_141 ( V_3 ) &&
F_98 ( V_3 -> V_133 ) ) {
F_59 ( V_3 , V_373 ,
V_3 -> V_133 - V_134 ) ;
break;
}
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
break;
case V_257 :
V_67 = V_3 -> V_9 -> V_323 ( V_3 -> V_9 , true ) ;
if ( V_67 < 0 ) {
F_59 ( V_3 , V_216 , 0 ) ;
break;
}
if ( V_3 -> V_378 ) {
V_3 -> V_378 = false ;
F_59 ( V_3 , V_266 ,
V_379 ) ;
} else {
F_59 ( V_3 , F_133 ( V_3 ) ,
V_379 ) ;
}
break;
case V_224 :
V_3 -> V_317 = true ;
V_3 -> V_331 = 0 ;
V_67 = F_110 ( V_3 ) ;
if ( V_67 < 0 ) {
F_59 ( V_3 , V_257 , 0 ) ;
} else {
F_61 ( V_3 , F_133 ( V_3 ) ,
V_380 ) ;
}
break;
case V_244 :
case V_248 :
F_59 ( V_3 , F_133 ( V_3 ) ,
V_381 ) ;
break;
case V_216 :
V_3 -> V_330 = 0 ;
V_3 -> V_256 = true ;
F_142 ( V_3 -> V_94 , V_362 ) ;
V_3 -> V_355 = V_362 ;
F_117 ( V_3 ) ;
F_136 ( V_3 ) ;
break;
case V_382 :
F_132 ( V_3 ) ;
F_59 ( V_3 , V_8 , 0 ) ;
break;
case V_340 :
case V_342 :
V_67 = F_131 ( V_3 ) ;
if ( V_67 < 0 )
F_59 ( V_3 , V_382 , 0 ) ;
break;
case V_383 :
F_59 ( V_3 , V_382 , V_341 ) ;
break;
case V_333 :
F_36 ( V_3 , V_384 , NULL ) ;
F_59 ( V_3 , V_385 , 0 ) ;
break;
case V_385 :
V_3 -> V_331 ++ ;
V_3 -> V_9 -> V_323 ( V_3 -> V_9 , false ) ;
F_124 ( V_3 ) ;
V_3 -> V_328 = true ;
if ( V_3 -> V_110 == V_7 )
F_59 ( V_3 , V_386 ,
V_387 ) ;
else
F_59 ( V_3 , V_388 , 0 ) ;
break;
case V_386 :
F_45 ( V_3 , true ) ;
F_111 ( V_3 , false ) ;
F_51 ( V_3 , false , V_7 , V_116 ) ;
F_59 ( V_3 , V_389 , V_390 ) ;
break;
case V_389 :
F_111 ( V_3 , true ) ;
V_3 -> V_9 -> V_323 ( V_3 -> V_9 , true ) ;
F_50 ( V_3 , true ) ;
F_59 ( V_3 , V_8 , V_352 ) ;
break;
case V_388 :
F_45 ( V_3 , false ) ;
F_112 ( V_3 , false ) ;
F_51 ( V_3 , false , V_5 , V_185 ) ;
F_59 ( V_3 , V_391 , V_392 ) ;
break;
case V_393 :
F_59 ( V_3 , V_6 ,
V_394 + V_395 ) ;
break;
case V_391 :
F_50 ( V_3 , true ) ;
F_59 ( V_3 , V_372 , 0 ) ;
break;
case V_273 :
V_3 -> V_76 = 0 ;
V_3 -> V_267 = - 1 ;
F_96 ( V_3 , V_265 ) ;
if ( V_3 -> V_110 == V_7 )
F_59 ( V_3 , V_268 , 0 ) ;
else
F_59 ( V_3 , V_257 , 0 ) ;
break;
case V_266 :
V_3 -> V_76 = 0 ;
V_3 -> V_267 = - 1 ;
if ( F_96 ( V_3 , V_272 ) )
F_61 ( V_3 , F_133 ( V_3 ) , 0 ) ;
else
F_61 ( V_3 , F_133 ( V_3 ) ,
V_380 ) ;
break;
case V_258 :
F_96 ( V_3 , V_274 ) ;
F_61 ( V_3 , V_396 ,
V_380 ) ;
break;
case V_276 :
F_96 ( V_3 , V_265 ) ;
F_61 ( V_3 , V_269 , 0 ) ;
break;
case V_396 :
F_137 ( V_3 , - V_73 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_269 :
if ( V_3 -> V_111 == V_116 ) {
F_124 ( V_3 ) ;
F_51 ( V_3 , true , V_3 -> V_110 ,
V_185 ) ;
} else {
F_51 ( V_3 , true , V_3 -> V_110 ,
V_116 ) ;
V_3 -> V_328 = true ;
}
F_137 ( V_3 , 0 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_279 :
F_96 ( V_3 , V_265 ) ;
F_59 ( V_3 , V_270 , 0 ) ;
break;
case V_261 :
F_96 ( V_3 , V_278 ) ;
F_61 ( V_3 , V_397 ,
V_380 ) ;
break;
case V_397 :
F_137 ( V_3 , - V_73 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_270 :
if ( V_3 -> V_110 == V_7 )
F_59 ( V_3 , V_398 ,
V_361 ) ;
else
F_59 ( V_3 , V_251 , 0 ) ;
break;
case V_398 :
F_111 ( V_3 , false ) ;
V_3 -> V_256 = false ;
F_59 ( V_3 , V_249 ,
V_399 ) ;
break;
case V_249 :
F_114 ( V_3 , V_322 ) ;
F_54 ( V_3 , V_5 ) ;
if ( F_96 ( V_3 , V_243 ) ) {
F_59 ( V_3 , V_287 , 0 ) ;
break;
}
F_61 ( V_3 , V_6 , V_352 ) ;
break;
case V_250 :
F_137 ( V_3 , 0 ) ;
F_59 ( V_3 , V_372 , 0 ) ;
break;
case V_251 :
F_112 ( V_3 , false ) ;
F_59 ( V_3 , F_133 ( V_3 ) ,
V_399 ) ;
break;
case V_252 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
F_111 ( V_3 , true ) ;
F_54 ( V_3 , V_7 ) ;
F_96 ( V_3 , V_243 ) ;
F_137 ( V_3 , 0 ) ;
F_59 ( V_3 , V_353 , 0 ) ;
break;
case V_281 :
F_96 ( V_3 , V_265 ) ;
F_59 ( V_3 , V_271 , 0 ) ;
break;
case V_263 :
F_96 ( V_3 , V_280 ) ;
F_59 ( V_3 , V_400 ,
V_380 ) ;
break;
case V_400 :
F_137 ( V_3 , - V_73 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_271 :
if ( V_3 -> V_93 == V_7 )
F_59 ( V_3 , V_253 , 0 ) ;
else
F_59 ( V_3 , V_401 , 0 ) ;
break;
case V_253 :
F_59 ( V_3 , F_133 ( V_3 ) ,
V_402 ) ;
break;
case V_401 :
F_45 ( V_3 , true ) ;
F_96 ( V_3 , V_243 ) ;
F_137 ( V_3 , 0 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_254 :
F_45 ( V_3 , false ) ;
F_137 ( V_3 , 0 ) ;
F_59 ( V_3 , F_134 ( V_3 ) , 0 ) ;
break;
case V_260 :
case V_262 :
case V_264 :
F_137 ( V_3 , V_3 -> V_259 ) ;
if ( V_3 -> V_110 == V_7 )
F_59 ( V_3 , V_215 , 0 ) ;
else
F_59 ( V_3 , V_216 , 0 ) ;
break;
case V_233 :
switch ( F_144 ( V_3 -> V_232 ) ) {
case V_403 :
F_36 ( V_3 , V_404 , NULL ) ;
break;
default:
break;
}
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
break;
case V_287 :
F_137 ( V_3 , - V_405 ) ;
F_126 ( V_3 ) ;
F_114 ( V_3 , V_17 ) ;
F_59 ( V_3 , V_406 ,
V_407 ) ;
break;
case V_406 :
F_59 ( V_3 ,
F_1 ( V_3 ) ,
V_3 -> V_245 ? V_399 : 0 ) ;
break;
default:
F_145 ( 1 , L_55 , V_3 -> V_34 ) ;
break;
}
}
static void F_146 ( struct V_220 * V_221 )
{
struct V_2 * V_3 = F_3 ( V_221 , struct V_2 ,
V_132 . V_221 ) ;
enum V_1 V_136 ;
F_9 ( & V_3 -> V_71 ) ;
V_3 -> V_137 = true ;
if ( V_3 -> V_141 && F_97 ( V_3 ) )
goto V_285;
if ( V_3 -> V_130 ) {
F_15 ( V_3 , L_56 ,
V_129 [ V_3 -> V_34 ] ,
V_129 [ V_3 -> V_130 ] , V_3 -> V_128 ) ;
V_3 -> V_136 = V_3 -> V_34 ;
V_3 -> V_34 = V_3 -> V_130 ;
V_3 -> V_130 = V_135 ;
}
do {
V_136 = V_3 -> V_34 ;
F_138 ( V_3 ) ;
if ( V_3 -> V_141 )
F_97 ( V_3 ) ;
} while ( V_3 -> V_34 != V_136 && ! V_3 -> V_130 );
V_285:
V_3 -> V_137 = false ;
F_14 ( & V_3 -> V_71 ) ;
}
static void F_147 ( struct V_2 * V_3 , enum V_95 V_16 ,
enum V_95 V_18 )
{
enum V_95 V_408 , V_409 ;
enum V_1 V_410 ;
V_408 = V_3 -> V_16 ;
V_409 = V_3 -> V_18 ;
V_3 -> V_16 = V_16 ;
V_3 -> V_18 = V_18 ;
F_16 ( V_3 ,
L_57 ,
V_408 , V_16 , V_409 , V_18 , V_129 [ V_3 -> V_34 ] ,
V_3 -> V_19 ,
F_4 ( V_3 ) ? L_58
: L_59 ) ;
switch ( V_3 -> V_34 ) {
case V_35 :
if ( F_118 ( V_3 ) || F_119 ( V_3 ) ||
F_139 ( V_3 ) )
F_59 ( V_3 , V_339 , 0 ) ;
else if ( F_141 ( V_3 ) )
F_59 ( V_3 , V_365 , 0 ) ;
break;
case V_8 :
case V_382 :
if ( F_118 ( V_3 ) || F_119 ( V_3 ) ||
F_139 ( V_3 ) )
F_59 ( V_3 , V_339 , 0 ) ;
break;
case V_339 :
if ( F_4 ( V_3 ) ||
F_148 ( V_3 ) )
F_59 ( V_3 , V_8 , 0 ) ;
else if ( V_16 != V_408 || V_18 != V_409 )
F_59 ( V_3 , V_339 , 0 ) ;
break;
case V_344 :
if ( F_4 ( V_3 ) )
F_59 ( V_3 , V_8 , 0 ) ;
break;
case V_6 :
if ( F_141 ( V_3 ) )
F_59 ( V_3 , V_365 , 0 ) ;
break;
case V_365 :
if ( ( V_3 -> V_16 == V_17 &&
V_3 -> V_18 != V_17 ) ||
( V_3 -> V_16 != V_17 &&
V_3 -> V_18 == V_17 ) )
V_410 = V_366 ;
else if ( F_4 ( V_3 ) )
V_410 = V_6 ;
else
break;
if ( V_410 != V_3 -> V_130 )
F_59 ( V_3 , V_365 , 0 ) ;
break;
case V_366 :
if ( F_4 ( V_3 ) )
V_410 = V_6 ;
else if ( V_3 -> V_245 )
V_410 = F_143 ( V_3 ) ? V_367 : V_347 ;
else
V_410 = V_6 ;
if ( V_410 != V_3 -> V_130 )
F_59 ( V_3 , V_366 , 0 ) ;
break;
case V_216 :
if ( F_4 ( V_3 ) )
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
else if ( ! V_3 -> V_317 &&
( V_16 != V_408 || V_18 != V_409 ) )
F_48 ( V_3 ,
F_47 ( V_3 ) ,
5000 ) ;
break;
case V_342 :
if ( V_16 == V_17 || V_18 == V_17 )
F_59 ( V_3 , V_383 , 0 ) ;
break;
case V_383 :
if ( F_119 ( V_3 ) )
F_59 ( V_3 , V_342 , 0 ) ;
break;
case V_340 :
if ( V_16 == V_17 || V_18 == V_17 )
F_59 ( V_3 , V_382 , 0 ) ;
break;
case V_343 :
break;
case V_373 :
if ( F_4 ( V_3 ) )
F_59 ( V_3 , V_376 , 0 ) ;
break;
case V_376 :
break;
case V_348 :
if ( ! V_3 -> V_245 && F_139 ( V_3 ) )
V_410 = V_344 ;
else
V_410 = V_350 ;
if ( V_410 != V_3 -> V_130 )
F_59 ( V_3 , V_348 , 0 ) ;
break;
case V_345 :
if ( V_3 -> V_245 && F_141 ( V_3 ) ) {
F_59 ( V_3 , V_347 , 0 ) ;
break;
}
if ( ! F_141 ( V_3 ) )
V_410 = V_348 ;
else
V_410 = V_350 ;
if ( V_410 != V_3 -> V_130 )
F_59 ( V_3 , V_345 , 0 ) ;
break;
case V_367 :
F_59 ( V_3 , V_369 , 0 ) ;
break;
case V_369 :
F_59 ( V_3 , V_367 , 0 ) ;
break;
case V_370 :
if ( V_3 -> V_245 ) {
F_59 ( V_3 , V_347 , 0 ) ;
break;
}
if ( F_139 ( V_3 ) ) {
F_59 ( V_3 , V_344 , 0 ) ;
break;
}
if ( F_4 ( V_3 ) &&
V_3 -> V_130 != V_6 )
F_59 ( V_3 , V_370 , 0 ) ;
break;
case V_251 :
case V_398 :
case V_249 :
break;
default:
if ( F_4 ( V_3 ) )
F_59 ( V_3 , F_135 ( V_3 ) , 0 ) ;
break;
}
}
static void F_149 ( struct V_2 * V_3 )
{
enum V_1 V_410 ;
F_16 ( V_3 , L_60 ) ;
V_3 -> V_245 = true ;
switch ( V_3 -> V_34 ) {
case V_248 :
F_59 ( V_3 , V_216 , 0 ) ;
break;
case V_373 :
F_59 ( V_3 , V_373 , 0 ) ;
break;
case V_366 :
F_59 ( V_3 , F_143 ( V_3 ) ? V_367
: V_347 ,
0 ) ;
break;
case V_393 :
F_59 ( V_3 , V_391 , 0 ) ;
break;
case V_344 :
F_59 ( V_3 , V_353 , 0 ) ;
break;
case V_389 :
F_59 ( V_3 , V_353 , 0 ) ;
break;
case V_343 :
break;
case V_348 :
if ( V_3 -> V_130 != V_350 )
F_59 ( V_3 , V_348 , 0 ) ;
break;
case V_345 :
if ( F_141 ( V_3 ) ) {
F_59 ( V_3 , V_347 , 0 ) ;
break;
}
if ( ! F_141 ( V_3 ) )
V_410 = V_348 ;
else
V_410 = V_350 ;
if ( V_410 != V_3 -> V_130 )
F_59 ( V_3 , V_345 , 0 ) ;
break;
case V_368 :
F_59 ( V_3 , V_371 , 0 ) ;
break;
default:
break;
}
}
static void F_150 ( struct V_2 * V_3 )
{
enum V_1 V_410 ;
F_16 ( V_3 , L_61 ) ;
V_3 -> V_245 = false ;
V_3 -> V_378 = false ;
switch ( V_3 -> V_34 ) {
case V_388 :
F_59 ( V_3 , V_393 , 0 ) ;
break;
case V_386 :
F_59 ( V_3 , V_389 , 0 ) ;
break;
case V_333 :
break;
case V_343 :
break;
case V_348 :
if ( F_139 ( V_3 ) )
V_410 = V_344 ;
else
V_410 = V_350 ;
if ( V_410 != V_3 -> V_130 )
F_59 ( V_3 , V_348 , 0 ) ;
break;
case V_345 :
if ( ! F_141 ( V_3 ) )
V_410 = V_348 ;
else
V_410 = V_350 ;
if ( V_410 != V_3 -> V_130 )
F_59 ( V_3 , V_345 , 0 ) ;
break;
case V_371 :
F_59 ( V_3 , V_368 , 0 ) ;
break;
case V_365 :
F_59 ( V_3 , V_6 , 0 ) ;
break;
case V_224 :
break;
case V_398 :
F_59 ( V_3 , V_249 , 0 ) ;
break;
case V_251 :
break;
case V_406 :
F_59 ( V_3 ,
V_3 -> V_110 == V_7 ?
V_8 : V_6 ,
0 ) ;
break;
default:
if ( V_3 -> V_110 == V_5 &&
V_3 -> V_15 )
F_59 ( V_3 , V_6 , 0 ) ;
break;
}
}
static void F_151 ( struct V_2 * V_3 )
{
F_16 ( V_3 , L_62 ) ;
F_59 ( V_3 ,
V_3 -> V_331 < V_332 ?
V_385 : V_287 ,
0 ) ;
}
static void F_152 ( struct V_220 * V_221 )
{
struct V_2 * V_3 = F_3 ( V_221 , struct V_2 ,
V_411 ) ;
T_3 V_412 ;
F_9 ( & V_3 -> V_71 ) ;
F_153 ( & V_3 -> V_413 ) ;
while ( V_3 -> V_414 ) {
V_412 = V_3 -> V_414 ;
V_3 -> V_414 = 0 ;
F_154 ( & V_3 -> V_413 ) ;
if ( V_412 & V_415 )
F_151 ( V_3 ) ;
if ( V_412 & V_416 ) {
bool V_417 ;
V_417 = V_3 -> V_9 -> V_418 ( V_3 -> V_9 ) ;
if ( V_417 )
F_149 ( V_3 ) ;
else
F_150 ( V_3 ) ;
}
if ( V_412 & V_419 ) {
enum V_95 V_16 , V_18 ;
if ( V_3 -> V_9 -> V_420 ( V_3 -> V_9 , & V_16 , & V_18 ) == 0 )
F_147 ( V_3 , V_16 , V_18 ) ;
}
F_153 ( & V_3 -> V_413 ) ;
}
F_154 ( & V_3 -> V_413 ) ;
F_14 ( & V_3 -> V_71 ) ;
}
void F_155 ( struct V_2 * V_3 )
{
F_153 ( & V_3 -> V_413 ) ;
V_3 -> V_414 |= V_419 ;
F_154 ( & V_3 -> V_413 ) ;
F_95 ( V_3 -> V_131 , & V_3 -> V_411 ) ;
}
void F_156 ( struct V_2 * V_3 )
{
F_153 ( & V_3 -> V_413 ) ;
V_3 -> V_414 |= V_416 ;
F_154 ( & V_3 -> V_413 ) ;
F_95 ( V_3 -> V_131 , & V_3 -> V_411 ) ;
}
void F_157 ( struct V_2 * V_3 )
{
F_153 ( & V_3 -> V_413 ) ;
V_3 -> V_414 = V_415 ;
F_154 ( & V_3 -> V_413 ) ;
F_95 ( V_3 -> V_131 , & V_3 -> V_411 ) ;
}
static int F_158 ( const struct V_12 * V_13 ,
enum V_114 V_115 )
{
struct V_2 * V_3 = F_2 ( V_13 ) ;
int V_67 ;
F_9 ( & V_3 -> V_421 ) ;
F_9 ( & V_3 -> V_71 ) ;
if ( V_3 -> V_14 . type != V_275 || ! V_3 -> V_317 ) {
V_67 = - V_293 ;
goto V_422;
}
if ( V_3 -> V_34 != V_215 && V_3 -> V_34 != V_216 ) {
V_67 = - V_79 ;
goto V_422;
}
if ( V_3 -> V_111 == V_115 ) {
V_67 = 0 ;
goto V_422;
}
V_3 -> V_259 = 0 ;
V_3 -> V_335 = true ;
F_38 ( & V_3 -> V_336 ) ;
F_59 ( V_3 , V_258 , 0 ) ;
F_14 ( & V_3 -> V_71 ) ;
F_159 ( & V_3 -> V_336 ) ;
V_67 = V_3 -> V_259 ;
goto V_423;
V_422:
F_14 ( & V_3 -> V_71 ) ;
V_423:
F_14 ( & V_3 -> V_421 ) ;
return V_67 ;
}
static int F_160 ( const struct V_12 * V_13 ,
enum V_112 V_113 )
{
struct V_2 * V_3 = F_2 ( V_13 ) ;
int V_67 ;
F_9 ( & V_3 -> V_421 ) ;
F_9 ( & V_3 -> V_71 ) ;
if ( V_3 -> V_14 . type != V_275 ) {
V_67 = - V_293 ;
goto V_422;
}
if ( V_3 -> V_34 != V_215 && V_3 -> V_34 != V_216 ) {
V_67 = - V_79 ;
goto V_422;
}
if ( V_113 == V_3 -> V_110 ) {
V_67 = 0 ;
goto V_422;
}
if ( ! V_3 -> V_317 ) {
if ( V_3 -> V_4 == V_424 ||
V_3 -> V_4 == V_3 -> V_110 ) {
V_67 = - V_293 ;
goto V_422;
}
F_59 ( V_3 , V_333 , 0 ) ;
V_67 = 0 ;
goto V_422;
}
V_3 -> V_259 = 0 ;
V_3 -> V_335 = true ;
F_38 ( & V_3 -> V_336 ) ;
F_59 ( V_3 , V_261 , 0 ) ;
F_14 ( & V_3 -> V_71 ) ;
F_159 ( & V_3 -> V_336 ) ;
V_67 = V_3 -> V_259 ;
goto V_423;
V_422:
F_14 ( & V_3 -> V_71 ) ;
V_423:
F_14 ( & V_3 -> V_421 ) ;
return V_67 ;
}
static int F_161 ( const struct V_12 * V_13 ,
enum V_112 V_113 )
{
struct V_2 * V_3 = F_2 ( V_13 ) ;
int V_67 ;
F_9 ( & V_3 -> V_421 ) ;
F_9 ( & V_3 -> V_71 ) ;
if ( V_3 -> V_34 != V_215 && V_3 -> V_34 != V_216 ) {
V_67 = - V_79 ;
goto V_422;
}
if ( V_113 == V_3 -> V_93 ) {
V_67 = 0 ;
goto V_422;
}
V_3 -> V_259 = 0 ;
V_3 -> V_335 = true ;
F_38 ( & V_3 -> V_336 ) ;
F_59 ( V_3 , V_263 , 0 ) ;
F_14 ( & V_3 -> V_71 ) ;
F_159 ( & V_3 -> V_336 ) ;
V_67 = V_3 -> V_259 ;
goto V_423;
V_422:
F_14 ( & V_3 -> V_71 ) ;
V_423:
F_14 ( & V_3 -> V_421 ) ;
return V_67 ;
}
static int F_162 ( const struct V_12 * V_13 , int V_113 )
{
struct V_2 * V_3 = F_2 ( V_13 ) ;
struct V_425 * V_9 = V_3 -> V_9 ;
int V_67 = 0 ;
F_9 ( & V_3 -> V_71 ) ;
if ( V_9 -> V_4 )
V_67 = V_9 -> V_4 ( V_9 , V_113 ) ;
if ( ! V_67 && ! V_9 -> V_10 -> V_426 )
V_3 -> V_4 = V_113 ;
V_3 -> V_329 = 0 ;
V_3 -> V_330 = 0 ;
F_14 ( & V_3 -> V_71 ) ;
return V_67 ;
}
static void F_163 ( struct V_2 * V_3 )
{
enum V_95 V_16 , V_18 ;
V_3 -> V_9 -> V_427 ( V_3 -> V_9 ) ;
F_126 ( V_3 ) ;
V_3 -> V_245 = V_3 -> V_9 -> V_418 ( V_3 -> V_9 ) ;
if ( V_3 -> V_245 )
V_3 -> V_378 = true ;
F_59 ( V_3 , F_1 ( V_3 ) , 0 ) ;
if ( V_3 -> V_9 -> V_420 ( V_3 -> V_9 , & V_16 , & V_18 ) == 0 )
F_147 ( V_3 , V_16 , V_18 ) ;
F_59 ( V_3 , V_287 , 0 ) ;
}
void F_164 ( struct V_2 * V_3 )
{
F_9 ( & V_3 -> V_71 ) ;
F_163 ( V_3 ) ;
F_14 ( & V_3 -> V_71 ) ;
}
static int F_165 ( T_3 * V_428 , const T_3 * V_105 ,
unsigned int V_106 )
{
unsigned int V_36 ;
if ( V_106 > V_429 )
V_106 = V_429 ;
for ( V_36 = 0 ; V_36 < V_106 ; V_36 ++ )
V_428 [ V_36 ] = V_105 [ V_36 ] ;
return V_106 ;
}
static int F_166 ( T_3 * V_430 , const T_3 * V_431 ,
unsigned int V_432 )
{
unsigned int V_36 ;
if ( V_432 > V_433 )
V_432 = V_433 ;
for ( V_36 = 0 ; V_36 < V_432 ; V_36 ++ )
V_430 [ V_36 ] = V_431 [ V_36 ] ;
return V_432 ;
}
void F_167 ( struct V_2 * V_3 , const T_3 * V_38 ,
unsigned int V_106 )
{
F_9 ( & V_3 -> V_71 ) ;
V_3 -> V_107 = F_165 ( V_3 -> V_105 , V_38 , V_106 ) ;
switch ( V_3 -> V_34 ) {
case V_8 :
case V_339 :
case V_348 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
break;
case V_268 :
case V_228 :
case V_215 :
case V_359 :
F_114 ( V_3 , F_49 ( V_3 ) ) ;
F_59 ( V_3 , V_268 , 0 ) ;
break;
default:
break;
}
F_14 ( & V_3 -> V_71 ) ;
}
void F_168 ( struct V_2 * V_3 , const T_3 * V_38 ,
unsigned int V_106 ,
unsigned int V_301 ,
unsigned int V_300 ,
unsigned int V_303 ,
unsigned int V_306 )
{
F_9 ( & V_3 -> V_71 ) ;
V_3 -> V_125 = F_165 ( V_3 -> V_127 , V_38 , V_106 ) ;
V_3 -> V_301 = V_301 ;
V_3 -> V_300 = V_300 ;
V_3 -> V_303 = V_303 ;
V_3 -> V_306 = V_306 ;
switch ( V_3 -> V_34 ) {
case V_224 :
case V_216 :
case V_244 :
case V_248 :
F_59 ( V_3 , V_224 , 0 ) ;
break;
default:
break;
}
F_14 ( & V_3 -> V_71 ) ;
}
struct V_2 * F_169 ( struct V_434 * V_33 , struct V_425 * V_9 )
{
struct V_2 * V_3 ;
int V_36 , V_435 ;
if ( ! V_33 || ! V_9 || ! V_9 -> V_10 ||
! V_9 -> V_418 || ! V_9 -> V_313 || ! V_9 -> V_420 ||
! V_9 -> V_90 || ! V_9 -> V_92 || ! V_9 -> V_310 ||
! V_9 -> V_323 || ! V_9 -> V_109 || ! V_9 -> V_70 )
return F_170 ( - V_293 ) ;
V_3 = F_171 ( V_33 , sizeof( * V_3 ) , V_31 ) ;
if ( ! V_3 )
return F_170 ( - V_60 ) ;
V_3 -> V_33 = V_33 ;
V_3 -> V_9 = V_9 ;
F_30 ( & V_3 -> V_71 ) ;
F_30 ( & V_3 -> V_421 ) ;
V_3 -> V_131 = F_172 ( F_33 ( V_33 ) ) ;
if ( ! V_3 -> V_131 )
return F_170 ( - V_60 ) ;
F_173 ( & V_3 -> V_132 , F_146 ) ;
F_173 ( & V_3 -> V_201 , F_85 ) ;
F_94 ( & V_3 -> V_411 , F_152 ) ;
F_174 ( & V_3 -> V_413 ) ;
F_175 ( & V_3 -> V_69 ) ;
F_175 ( & V_3 -> V_336 ) ;
V_3 -> V_107 = F_165 ( V_3 -> V_105 , V_9 -> V_10 -> V_105 ,
V_9 -> V_10 -> V_107 ) ;
V_3 -> V_125 = F_165 ( V_3 -> V_127 , V_9 -> V_10 -> V_127 ,
V_9 -> V_10 -> V_125 ) ;
V_3 -> V_186 = F_166 ( V_3 -> V_187 , V_9 -> V_10 -> V_187 ,
V_9 -> V_10 -> V_186 ) ;
V_3 -> V_301 = V_9 -> V_10 -> V_301 ;
V_3 -> V_300 = V_9 -> V_10 -> V_300 ;
V_3 -> V_303 = V_9 -> V_10 -> V_303 ;
V_3 -> V_306 = V_9 -> V_10 -> V_306 ;
if ( ! V_9 -> V_10 -> V_426 )
V_3 -> V_4 = V_9 -> V_10 -> V_11 ;
else
V_3 -> V_4 = V_424 ;
V_3 -> V_14 . V_436 = V_9 -> V_10 -> V_11 ;
V_3 -> V_14 . type = V_9 -> V_10 -> type ;
V_3 -> V_14 . V_437 = 0x0120 ;
V_3 -> V_14 . V_438 = 0x0200 ;
V_3 -> V_14 . V_439 = F_158 ;
V_3 -> V_14 . V_440 = F_160 ;
V_3 -> V_14 . V_441 = F_161 ;
V_3 -> V_14 . V_4 = F_162 ;
V_3 -> V_315 . V_442 = & V_3 -> V_153 ;
V_3 -> V_94 = F_176 ( V_3 -> V_33 , & V_3 -> V_14 ) ;
if ( ! V_3 -> V_94 ) {
V_435 = - V_60 ;
goto V_443;
}
if ( V_9 -> V_10 -> V_444 ) {
struct V_165 * V_166 = V_9 -> V_10 -> V_444 ;
V_36 = 0 ;
while ( V_166 -> V_161 && V_36 < F_71 ( V_3 -> V_445 ) ) {
V_3 -> V_445 [ V_36 ] =
F_177 ( V_3 -> V_94 ,
V_166 ) ;
if ( ! V_3 -> V_445 [ V_36 ] ) {
F_15 ( V_3 ,
L_63 ,
F_33 ( V_33 ) , V_166 -> V_161 ) ;
break;
}
V_36 ++ ;
V_166 ++ ;
}
}
F_29 ( V_3 ) ;
F_9 ( & V_3 -> V_71 ) ;
F_163 ( V_3 ) ;
F_14 ( & V_3 -> V_71 ) ;
F_15 ( V_3 , L_64 , F_33 ( V_33 ) ) ;
return V_3 ;
V_443:
F_178 ( V_3 -> V_131 ) ;
return F_170 ( V_435 ) ;
}
void F_179 ( struct V_2 * V_3 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_71 ( V_3 -> V_445 ) ; V_36 ++ )
F_125 ( V_3 -> V_445 [ V_36 ] ) ;
F_180 ( V_3 -> V_94 ) ;
F_34 ( V_3 ) ;
F_178 ( V_3 -> V_131 ) ;
}
