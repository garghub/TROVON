static void F_1 ( struct V_1 * V_2 ,
T_1 type , T_2 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned int V_8 ;
V_8 = F_2 ( 1 , & V_7 -> V_8 ) & V_9 ;
V_5 = & V_7 -> V_10 [ V_8 ] ;
V_5 -> time = V_11 ;
V_5 -> V_12 = V_2 -> V_13 . V_14 . V_15 [ 0 ] ;
V_5 -> type = type ;
if ( V_2 -> V_7 -> V_16 )
V_5 -> V_17 = V_2 -> V_18 . V_19 . V_20 . V_21 ;
else
V_5 -> V_17 = V_2 -> V_13 . V_22 . V_3 . V_22 . V_20 . V_21 ;
V_5 -> V_23 = V_2 -> V_23 & 0xff ;
V_5 -> V_24 = V_2 -> V_13 . V_24 ;
V_5 -> V_22 . V_3 = V_3 ;
F_3 () ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_2 -> V_28 ( V_2 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_30 * V_31 = & V_2 -> V_32 . V_31 ;
struct V_33 * V_34 = & V_2 -> V_32 . V_34 ;
T_3 V_35 = V_2 -> V_35 ;
int V_36 ;
V_36 = V_13 -> V_14 . V_36 ;
memset ( & V_13 -> V_14 , 0 , sizeof( struct V_37 ) ) ;
V_13 -> V_14 . V_36 = V_36 ;
V_13 -> V_38 = 0 ;
V_13 -> V_39 = 0 ;
V_13 -> V_40 = 0 ;
V_13 -> V_41 = 0 ;
if ( V_2 -> V_7 -> V_16 ) {
V_13 -> V_22 . V_42 . V_43 =
F_8 ( V_35 + F_9 ( struct V_1 , V_18 . V_44 ) ) ;
V_34 -> V_22 . V_45 . V_46 = 0 ;
} else {
V_13 -> V_47 =
F_10 ( V_35 + F_9 ( struct V_1 , V_18 . V_48 ) ) ;
V_13 -> V_49 = V_13 -> V_47 ;
V_31 -> V_22 . V_45 . V_46 = 0 ;
}
V_31 -> V_50 . V_51 = 0 ;
V_31 -> V_50 . V_52 = 0 ;
V_2 -> V_53 = NULL ;
V_2 -> V_54 = NULL ;
V_2 -> V_55 [ 0 ] = 0 ;
V_2 -> V_56 = 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
void (* F_12) ( struct V_1 * ) )
{
F_7 ( V_2 ) ;
V_2 -> V_22 . V_57 = 0 ;
V_2 -> V_58 = NULL ;
V_2 -> V_59 = NULL ;
V_2 -> F_12 = F_12 ;
F_13 ( & V_2 -> V_60 ) ;
}
static
struct V_1 * F_14 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = NULL ;
if ( F_15 ( ! F_16 ( & V_62 -> V_63 ) ) ) {
V_2 = F_17 ( V_62 -> V_63 . V_64 ,
struct V_1 , V_65 ) ;
F_18 ( & V_2 -> V_65 ) ;
}
return V_2 ;
}
static
struct V_1 * F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_2 =
F_14 ( & V_7 -> V_62 [ V_66 ] ) ;
F_11 ( V_2 , F_4 ) ;
return V_2 ;
}
static void F_20 ( struct V_6 * V_7 ,
T_2 V_67 )
{
volatile T_2 V_68 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_71 = 0 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
if ( V_7 -> V_16 )
F_23 ( ~ 0 , V_7 -> V_20 . V_72 ) ;
else
F_24 ( ~ 0 , V_7 -> V_20 . V_72 ) ;
if ( V_7 -> V_16 )
F_24 ( ~ 0 , V_7 -> V_20 . V_73 ) ;
F_24 ( V_67 , V_7 -> V_20 . V_74 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_75 ) ;
}
static int F_26 ( struct V_6 * V_7 )
{
int V_76 = F_27 ( V_7 -> V_77 , V_78 ) ;
if ( V_76 == 0 )
return 0 ;
if ( F_28 ( V_7 -> V_77 , V_76 + V_79 ,
& V_7 -> V_80 ) != V_81 ) {
F_29 ( & V_7 -> V_77 -> V_82 , L_1 ) ;
return - V_83 ;
}
V_7 -> V_80 |= V_84 | V_85 ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
int V_76 = F_27 ( V_7 -> V_77 , V_78 ) ;
if ( V_76 ) {
if ( F_31 ( V_7 -> V_77 , V_76 + V_79 ,
V_7 -> V_80 ) != V_81 ) {
F_29 ( & V_7 -> V_77 -> V_82 , L_2 ) ;
return - V_83 ;
}
}
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_86 * V_54 = V_2 -> V_54 ;
struct V_87 * V_88 = V_54 -> V_89 -> V_90 ;
V_54 -> V_91 |= V_92 ;
V_88 -> V_31 . V_46 |= V_93 ;
F_33 ( V_54 ) ;
if ( V_2 -> V_59 )
F_34 ( V_2 -> V_59 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
unsigned long V_94 ;
F_5 ( & V_62 -> V_70 , V_94 ) ;
F_32 ( V_2 ) ;
F_6 ( & V_62 -> V_70 , V_94 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_95 * V_53 = V_2 -> V_53 ;
V_53 -> V_96 |= ( V_97 << 16 ) ;
F_38 ( V_2 -> V_53 ) ;
V_53 -> V_98 ( V_53 ) ;
if ( V_2 -> V_59 )
F_34 ( V_2 -> V_59 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned long V_94 ;
struct V_61 * V_62 = V_2 -> V_62 ;
F_5 ( & V_62 -> V_70 , V_94 ) ;
F_37 ( V_2 ) ;
F_6 ( & V_62 -> V_70 , V_94 ) ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_99 ;
struct V_61 * V_62 ;
V_100 ;
F_41 (hrrq, ioa_cfg) {
F_21 ( & V_62 -> V_70 ) ;
F_42 (ipr_cmd,
temp, &hrrq->hrrq_pending_q, queue) {
F_18 ( & V_2 -> V_65 ) ;
V_2 -> V_32 . V_31 . V_50 . V_51 =
F_10 ( V_101 ) ;
V_2 -> V_32 . V_31 . V_50 . V_102 =
F_10 ( V_103 ) ;
if ( V_2 -> V_53 )
V_2 -> V_28 = F_37 ;
else if ( V_2 -> V_54 )
V_2 -> V_28 = F_32 ;
F_1 ( V_2 , V_104 ,
V_101 ) ;
F_43 ( & V_2 -> V_60 ) ;
V_2 -> V_28 ( V_2 ) ;
}
F_22 ( & V_62 -> V_70 ) ;
}
V_105 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_3 V_106 = V_2 -> V_35 ;
if ( V_7 -> V_16 ) {
V_106 |= 0x1 ;
if ( V_2 -> V_56 * sizeof( struct V_107 ) > 128 )
V_106 |= 0x4 ;
F_23 ( V_106 , V_7 -> V_20 . V_108 ) ;
} else
F_24 ( V_106 , V_7 -> V_20 . V_108 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
void (* V_28) ( struct V_1 * ) ,
void (* F_46) ( struct V_1 * ) , T_2 V_109 )
{
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_110 ) ;
V_2 -> V_28 = V_28 ;
V_2 -> V_60 . V_111 = ( unsigned long ) V_2 ;
V_2 -> V_60 . V_112 = V_11 + V_109 ;
V_2 -> V_60 . V_113 = ( void (*) ( unsigned long ) ) F_46 ;
F_47 ( & V_2 -> V_60 ) ;
F_1 ( V_2 , V_114 , 0 ) ;
F_44 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_58 )
V_2 -> V_58 = NULL ;
else
F_34 ( & V_2 -> V_115 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_3 V_35 ,
T_2 V_116 , int V_117 )
{
struct V_118 * V_48 = V_2 -> V_18 . V_48 ;
struct V_107 * V_44 = V_2 -> V_18 . V_44 ;
V_2 -> V_56 = 1 ;
if ( V_2 -> V_7 -> V_16 ) {
V_44 -> V_117 = F_10 ( V_117 ) ;
V_44 -> V_119 = F_10 ( V_116 ) ;
V_44 -> V_120 = F_8 ( V_35 ) ;
V_2 -> V_13 . V_40 =
F_10 ( sizeof( struct V_107 ) ) ;
V_2 -> V_13 . V_38 = F_10 ( V_116 ) ;
} else {
V_48 -> V_121 = F_10 ( V_117 | V_116 ) ;
V_48 -> V_120 = F_10 ( V_35 ) ;
if ( V_117 == V_122 ) {
V_2 -> V_13 . V_41 =
F_10 ( sizeof( struct V_118 ) ) ;
V_2 -> V_13 . V_39 = F_10 ( V_116 ) ;
} else {
V_2 -> V_13 . V_40 =
F_10 ( sizeof( struct V_118 ) ) ;
V_2 -> V_13 . V_38 = F_10 ( V_116 ) ;
}
}
}
static void F_50 ( struct V_1 * V_2 ,
void (* F_46) ( struct V_1 * V_2 ) ,
T_2 V_109 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_51 ( & V_2 -> V_115 ) ;
F_45 ( V_2 , F_48 , F_46 , V_109 ) ;
F_52 ( V_7 -> V_26 -> V_27 ) ;
F_53 ( & V_2 -> V_115 ) ;
F_54 ( V_7 -> V_26 -> V_27 ) ;
}
static int F_55 ( struct V_6 * V_7 )
{
unsigned int V_62 ;
if ( V_7 -> V_69 == 1 )
V_62 = 0 ;
else {
V_62 = F_2 ( 1 , & V_7 -> V_123 ) ;
V_62 = ( V_62 % ( V_7 -> V_69 - 1 ) ) + 1 ;
}
return V_62 ;
}
static void F_56 ( struct V_6 * V_7 , T_1 type ,
struct V_124 * V_125 )
{
struct V_1 * V_2 ;
struct V_29 * V_13 ;
if ( V_7 -> V_62 [ V_66 ] . V_126 ) {
V_2 = F_19 ( V_7 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_110 ) ;
F_35 ( & V_125 -> V_65 , & V_7 -> V_127 ) ;
V_2 -> V_22 . V_125 = V_125 ;
V_13 = & V_2 -> V_13 ;
V_13 -> V_24 = F_10 ( V_128 ) ;
V_13 -> V_14 . V_129 = V_130 ;
V_13 -> V_14 . V_15 [ 0 ] = V_131 ;
V_13 -> V_14 . V_15 [ 1 ] = type ;
V_13 -> V_14 . V_15 [ 7 ] = ( sizeof( V_125 -> V_132 ) >> 8 ) & 0xff ;
V_13 -> V_14 . V_15 [ 8 ] = sizeof( V_125 -> V_132 ) & 0xff ;
F_49 ( V_2 , V_125 -> V_133 ,
sizeof( V_125 -> V_132 ) , V_122 ) ;
if ( type == V_134 )
V_2 -> V_28 = V_135 ;
else
V_2 -> V_28 = V_136 ;
F_1 ( V_2 , V_114 , V_137 ) ;
F_44 ( V_2 ) ;
} else {
F_35 ( & V_125 -> V_65 , & V_7 -> V_138 ) ;
}
}
static void F_57 ( struct V_139 * V_140 , unsigned int V_141 )
{
switch ( V_141 ) {
case V_142 :
case V_143 :
V_140 -> V_144 = V_145 ;
break;
case V_146 :
case V_147 :
V_140 -> V_144 = V_148 ;
break;
default:
V_140 -> V_144 = V_149 ;
break;
} ;
}
static void F_58 ( struct V_139 * V_140 ,
struct V_150 * V_151 )
{
int V_152 = 0 ;
unsigned int V_141 ;
struct V_6 * V_7 = V_140 -> V_7 ;
struct V_139 * V_153 = NULL ;
V_140 -> V_154 = 0 ;
V_140 -> V_155 = 0 ;
V_140 -> V_156 = 0 ;
V_140 -> V_157 = 0 ;
V_140 -> V_158 = 0 ;
V_140 -> V_159 = 0 ;
V_140 -> V_160 = NULL ;
V_140 -> V_88 = NULL ;
if ( V_7 -> V_16 ) {
V_141 = V_151 -> V_22 . V_161 -> V_141 ;
V_140 -> V_117 = F_59 ( V_151 -> V_22 . V_161 -> V_117 ) ;
V_140 -> V_162 = F_59 ( V_151 -> V_22 . V_161 -> V_162 ) ;
V_140 -> V_163 = F_60 ( V_140 ) ;
V_140 -> type = V_151 -> V_22 . V_161 -> V_164 ;
memcpy ( V_140 -> V_165 , & V_151 -> V_22 . V_161 -> V_165 ,
sizeof( V_140 -> V_165 ) ) ;
V_140 -> V_166 = 0 ;
memcpy ( & V_140 -> V_167 . V_168 , & V_151 -> V_22 . V_161 -> V_169 ,
sizeof( V_140 -> V_167 . V_168 ) ) ;
V_140 -> V_169 = F_61 ( & V_140 -> V_167 ) ;
if ( V_140 -> type == V_170 ) {
F_62 (gscsi_res, &ioa_cfg->used_res_q, queue) {
if ( V_153 -> V_171 == V_151 -> V_22 . V_161 -> V_171 ) {
V_152 = 1 ;
V_140 -> V_172 = V_153 -> V_172 ;
break;
}
}
if ( ! V_152 ) {
V_140 -> V_172 = F_63 ( V_7 -> V_173 ,
V_7 -> V_174 ) ;
F_64 ( V_140 -> V_172 , V_7 -> V_173 ) ;
}
} else if ( V_140 -> type == V_175 ) {
V_140 -> V_166 = V_176 ;
V_140 -> V_172 = 0 ;
} else if ( V_140 -> type == V_177 ) {
V_140 -> V_166 = V_178 ;
V_140 -> V_172 = F_63 ( V_7 -> V_179 ,
V_7 -> V_174 ) ;
F_64 ( V_140 -> V_172 , V_7 -> V_179 ) ;
} else if ( V_140 -> type == V_180 ) {
V_140 -> V_166 = V_181 ;
V_140 -> V_172 = F_63 ( V_7 -> V_182 ,
V_7 -> V_174 ) ;
F_64 ( V_140 -> V_172 , V_7 -> V_182 ) ;
} else {
V_140 -> V_172 = F_63 ( V_7 -> V_173 ,
V_7 -> V_174 ) ;
F_64 ( V_140 -> V_172 , V_7 -> V_173 ) ;
}
} else {
V_141 = V_151 -> V_22 . V_183 -> V_141 ;
V_140 -> V_163 = F_65 ( V_140 ) ;
V_140 -> V_117 = V_151 -> V_22 . V_183 -> V_117 ;
if ( V_140 -> V_117 & V_184 )
V_140 -> type = V_175 ;
else
V_140 -> type = V_151 -> V_22 . V_183 -> V_185 & 0x0f ;
V_140 -> V_166 = V_151 -> V_22 . V_183 -> V_186 . V_166 ;
V_140 -> V_172 = V_151 -> V_22 . V_183 -> V_186 . V_172 ;
V_140 -> V_169 = V_151 -> V_22 . V_183 -> V_186 . V_169 ;
V_140 -> V_187 = F_66 ( V_151 -> V_22 . V_183 -> V_187 ) ;
}
F_57 ( V_140 , V_141 ) ;
}
static int F_67 ( struct V_139 * V_140 ,
struct V_150 * V_151 )
{
if ( V_140 -> V_7 -> V_16 ) {
if ( ! memcmp ( & V_140 -> V_171 , & V_151 -> V_22 . V_161 -> V_171 ,
sizeof( V_151 -> V_22 . V_161 -> V_171 ) ) &&
! memcmp ( & V_140 -> V_167 . V_168 , & V_151 -> V_22 . V_161 -> V_169 ,
sizeof( V_151 -> V_22 . V_161 -> V_169 ) ) ) {
return 1 ;
}
} else {
if ( V_140 -> V_166 == V_151 -> V_22 . V_183 -> V_186 . V_166 &&
V_140 -> V_172 == V_151 -> V_22 . V_183 -> V_186 . V_172 &&
V_140 -> V_169 == V_151 -> V_22 . V_183 -> V_186 . V_169 )
return 1 ;
}
return 0 ;
}
static char * F_68 ( T_1 * V_165 , char * V_188 , int V_116 )
{
int V_18 ;
char * V_189 = V_188 ;
* V_189 = '\0' ;
V_189 += snprintf ( V_189 , V_188 + V_116 - V_189 , L_3 , V_165 [ 0 ] ) ;
for ( V_18 = 1 ; V_165 [ V_18 ] != 0xff && ( ( V_18 * 3 ) < V_116 ) ; V_18 ++ )
V_189 += snprintf ( V_189 , V_188 + V_116 - V_189 , L_4 , V_165 [ V_18 ] ) ;
return V_188 ;
}
static char * F_69 ( struct V_6 * V_7 ,
T_1 * V_165 , char * V_188 , int V_116 )
{
char * V_189 = V_188 ;
* V_189 = '\0' ;
V_189 += snprintf ( V_189 , V_188 + V_116 - V_189 , L_5 , V_7 -> V_26 -> V_190 ) ;
F_68 ( V_165 , V_189 , V_116 - ( V_188 - V_189 ) ) ;
return V_188 ;
}
static void F_70 ( struct V_139 * V_140 ,
struct V_150 * V_151 )
{
char V_188 [ V_191 ] ;
unsigned int V_141 ;
int V_192 = 0 ;
if ( V_140 -> V_7 -> V_16 ) {
V_140 -> V_117 = F_59 ( V_151 -> V_22 . V_161 -> V_117 ) ;
V_140 -> V_162 = F_59 ( V_151 -> V_22 . V_161 -> V_162 ) ;
V_140 -> type = V_151 -> V_22 . V_161 -> V_164 ;
memcpy ( & V_140 -> V_193 , & V_151 -> V_22 . V_161 -> V_193 ,
sizeof( struct V_194 ) ) ;
V_140 -> V_163 = F_60 ( V_140 ) ;
V_141 = V_151 -> V_22 . V_161 -> V_141 ;
V_140 -> V_24 = V_151 -> V_22 . V_161 -> V_24 ;
V_140 -> V_171 = V_151 -> V_22 . V_161 -> V_171 ;
memcpy ( & V_140 -> V_167 . V_168 , & V_151 -> V_22 . V_161 -> V_169 ,
sizeof( V_140 -> V_167 . V_168 ) ) ;
if ( memcmp ( V_140 -> V_165 , & V_151 -> V_22 . V_161 -> V_165 ,
sizeof( V_140 -> V_165 ) ) ) {
memcpy ( V_140 -> V_165 , & V_151 -> V_22 . V_161 -> V_165 ,
sizeof( V_140 -> V_165 ) ) ;
V_192 = 1 ;
}
if ( V_140 -> V_160 && V_192 )
F_71 ( V_195 , V_140 -> V_160 , L_6 ,
F_69 ( V_140 -> V_7 ,
V_140 -> V_165 , V_188 , sizeof( V_188 ) ) ) ;
} else {
V_140 -> V_117 = V_151 -> V_22 . V_183 -> V_117 ;
if ( V_140 -> V_117 & V_184 )
V_140 -> type = V_175 ;
else
V_140 -> type = V_151 -> V_22 . V_183 -> V_185 & 0x0f ;
memcpy ( & V_140 -> V_193 , & V_151 -> V_22 . V_183 -> V_193 ,
sizeof( struct V_194 ) ) ;
V_140 -> V_163 = F_65 ( V_140 ) ;
V_141 = V_151 -> V_22 . V_183 -> V_141 ;
V_140 -> V_24 = V_151 -> V_22 . V_183 -> V_24 ;
}
F_57 ( V_140 , V_141 ) ;
}
static void F_72 ( struct V_139 * V_140 )
{
struct V_139 * V_153 = NULL ;
struct V_6 * V_7 = V_140 -> V_7 ;
if ( ! V_7 -> V_16 )
return;
if ( V_140 -> V_166 == V_178 )
F_73 ( V_140 -> V_172 , V_7 -> V_179 ) ;
else if ( V_140 -> V_166 == V_181 )
F_73 ( V_140 -> V_172 , V_7 -> V_182 ) ;
else if ( V_140 -> V_166 == 0 && V_140 -> type == V_170 ) {
F_62 (gscsi_res, &ioa_cfg->used_res_q, queue)
if ( V_153 -> V_171 == V_140 -> V_171 && V_153 != V_140 )
return;
F_73 ( V_140 -> V_172 , V_7 -> V_173 ) ;
} else if ( V_140 -> V_166 == 0 )
F_73 ( V_140 -> V_172 , V_7 -> V_173 ) ;
}
static void F_74 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_139 * V_140 = NULL ;
struct V_150 V_151 ;
T_4 V_196 ;
T_2 V_197 = 1 ;
if ( V_7 -> V_16 ) {
V_151 . V_22 . V_161 = & V_125 -> V_132 . V_22 . V_198 . V_22 . V_161 ;
V_196 = V_151 . V_22 . V_161 -> V_24 ;
} else {
V_151 . V_22 . V_183 = & V_125 -> V_132 . V_22 . V_198 . V_22 . V_183 ;
V_196 = V_151 . V_22 . V_183 -> V_24 ;
}
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( V_140 -> V_24 == V_196 ) {
V_197 = 0 ;
break;
}
}
if ( V_197 ) {
if ( F_16 ( & V_7 -> V_199 ) ) {
F_56 ( V_7 ,
V_134 ,
V_125 ) ;
return;
}
V_140 = F_17 ( V_7 -> V_199 . V_64 ,
struct V_139 , V_65 ) ;
F_18 ( & V_140 -> V_65 ) ;
F_58 ( V_140 , & V_151 ) ;
F_35 ( & V_140 -> V_65 , & V_7 -> V_200 ) ;
}
F_70 ( V_140 , & V_151 ) ;
if ( V_125 -> V_132 . V_201 == V_202 ) {
if ( V_140 -> V_160 ) {
V_140 -> V_157 = 1 ;
V_140 -> V_24 = V_203 ;
F_75 ( & V_7 -> V_204 ) ;
} else {
F_72 ( V_140 ) ;
F_76 ( & V_140 -> V_65 , & V_7 -> V_199 ) ;
}
} else if ( ! V_140 -> V_160 || V_140 -> V_157 ) {
V_140 -> V_156 = 1 ;
F_75 ( & V_7 -> V_204 ) ;
}
F_56 ( V_7 , V_134 , V_125 ) ;
}
static void V_135 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_124 * V_125 = V_2 -> V_22 . V_125 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
F_78 ( & V_125 -> V_65 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
if ( V_51 ) {
if ( V_51 != V_101 &&
V_51 != V_205 )
F_29 ( & V_7 -> V_77 -> V_82 ,
L_7 , V_51 ) ;
F_56 ( V_7 , V_134 , V_125 ) ;
} else {
F_74 ( V_7 , V_125 ) ;
}
}
static int F_79 ( int V_18 , char * V_206 )
{
while ( V_18 && V_206 [ V_18 ] == ' ' )
V_18 -- ;
V_206 [ V_18 + 1 ] = ' ' ;
V_206 [ V_18 + 2 ] = '\0' ;
return V_18 + 2 ;
}
static void F_80 ( char * V_207 , struct V_124 * V_125 ,
struct V_208 * V_209 )
{
char V_188 [ V_210 + V_211 + V_212 + 3 ] ;
int V_18 = 0 ;
memcpy ( V_188 , V_209 -> V_213 . V_214 , V_210 ) ;
V_18 = F_79 ( V_210 - 1 , V_188 ) ;
memcpy ( & V_188 [ V_18 ] , V_209 -> V_213 . V_215 , V_211 ) ;
V_18 = F_79 ( V_18 + V_211 - 1 , V_188 ) ;
memcpy ( & V_188 [ V_18 ] , V_209 -> V_216 , V_212 ) ;
V_188 [ V_212 + V_18 ] = '\0' ;
F_81 ( V_125 , L_8 , V_207 , V_188 ) ;
}
static void F_82 ( struct V_208 * V_209 )
{
char V_188 [ V_210 + V_211
+ V_212 ] ;
memcpy ( V_188 , V_209 -> V_213 . V_214 , V_210 ) ;
memcpy ( V_188 + V_210 , V_209 -> V_213 . V_215 ,
V_211 ) ;
V_188 [ V_210 + V_211 ] = '\0' ;
F_83 ( L_9 , V_188 ) ;
memcpy ( V_188 , V_209 -> V_216 , V_212 ) ;
V_188 [ V_212 ] = '\0' ;
F_83 ( L_10 , V_188 ) ;
}
static void F_84 ( char * V_207 , struct V_124 * V_125 ,
struct V_217 * V_209 )
{
F_80 ( V_207 , V_125 , & V_209 -> V_209 ) ;
F_81 ( V_125 , L_11 , V_207 ,
F_77 ( V_209 -> V_218 [ 0 ] ) , F_77 ( V_209 -> V_218 [ 1 ] ) ) ;
}
static void F_85 ( struct V_217 * V_209 )
{
F_82 ( & V_209 -> V_209 ) ;
F_83 ( L_12 , F_77 ( V_209 -> V_218 [ 0 ] ) ,
F_77 ( V_209 -> V_218 [ 1 ] ) ) ;
}
static void F_86 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_219 * error ;
if ( V_7 -> V_16 )
error = & V_125 -> V_132 . V_22 . V_220 . V_22 . V_221 ;
else
error = & V_125 -> V_132 . V_22 . error . V_22 . V_221 ;
F_83 ( L_13 ) ;
F_83 ( L_14 ) ;
F_85 ( & error -> V_222 ) ;
F_83 ( L_15 ) ;
F_85 ( & error -> V_223 ) ;
F_83 ( L_16 ) ;
F_83 ( L_14 ) ;
F_85 ( & error -> V_224 ) ;
F_83 ( L_15 ) ;
F_85 ( & error -> V_225 ) ;
F_83 ( L_17 ,
F_77 ( error -> V_226 [ 0 ] ) ,
F_77 ( error -> V_226 [ 1 ] ) ,
F_77 ( error -> V_226 [ 2 ] ) ) ;
}
static void F_87 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_227 * error =
& V_125 -> V_132 . V_22 . error . V_22 . V_228 ;
F_83 ( L_13 ) ;
F_83 ( L_14 ) ;
F_82 ( & error -> V_222 ) ;
F_83 ( L_15 ) ;
F_82 ( & error -> V_223 ) ;
F_83 ( L_16 ) ;
F_83 ( L_14 ) ;
F_82 ( & error -> V_224 ) ;
F_83 ( L_15 ) ;
F_82 ( & error -> V_225 ) ;
F_83 ( L_17 ,
F_77 ( error -> V_226 [ 0 ] ) ,
F_77 ( error -> V_226 [ 1 ] ) ,
F_77 ( error -> V_226 [ 2 ] ) ) ;
}
static void F_88 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
int V_229 , V_18 ;
struct V_230 * V_231 ;
struct V_232 * error ;
error = & V_125 -> V_132 . V_22 . error . V_22 . V_233 ;
V_229 = F_77 ( error -> V_229 ) ;
F_83 ( L_18 ,
F_77 ( error -> V_234 ) , V_229 ) ;
V_231 = error -> V_82 ;
for ( V_18 = 0 ; V_18 < V_229 ; V_18 ++ , V_231 ++ ) {
V_235 ;
F_89 ( V_7 , V_231 -> V_236 , L_19 , V_18 + 1 ) ;
F_85 ( & V_231 -> V_209 ) ;
F_83 ( L_20 ) ;
F_85 ( & V_231 -> V_237 ) ;
F_83 ( L_14 ) ;
F_85 ( & V_231 -> V_238 ) ;
F_83 ( L_15 ) ;
F_85 ( & V_231 -> V_239 ) ;
}
}
static void F_90 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
int V_229 , V_18 ;
struct V_240 * V_231 ;
struct V_241 * error ;
char V_188 [ V_191 ] ;
error = & V_125 -> V_132 . V_22 . V_220 . V_22 . V_242 ;
V_229 = F_77 ( error -> V_229 ) ;
F_83 ( L_18 ,
F_77 ( error -> V_234 ) , V_229 ) ;
V_231 = error -> V_82 ;
for ( V_18 = 0 ; V_18 < V_229 ; V_18 ++ , V_231 ++ ) {
V_235 ;
F_83 ( L_21 , V_18 + 1 ,
F_68 ( V_231 -> V_165 ,
V_188 , sizeof( V_188 ) ) ) ;
F_85 ( & V_231 -> V_209 ) ;
F_83 ( L_20 ) ;
F_85 ( & V_231 -> V_237 ) ;
F_83 ( L_14 ) ;
F_85 ( & V_231 -> V_238 ) ;
F_83 ( L_15 ) ;
F_85 ( & V_231 -> V_239 ) ;
}
}
static void F_91 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
int V_229 , V_18 ;
struct V_243 * V_231 ;
struct V_244 * error ;
error = & V_125 -> V_132 . V_22 . error . V_22 . V_245 ;
V_229 = F_77 ( error -> V_229 ) ;
F_83 ( L_18 ,
F_77 ( error -> V_234 ) , V_229 ) ;
V_231 = error -> V_82 ;
for ( V_18 = 0 ; V_18 < V_229 ; V_18 ++ , V_231 ++ ) {
V_235 ;
F_89 ( V_7 , V_231 -> V_236 , L_19 , V_18 + 1 ) ;
F_82 ( & V_231 -> V_209 ) ;
F_83 ( L_20 ) ;
F_82 ( & V_231 -> V_237 ) ;
F_83 ( L_14 ) ;
F_82 ( & V_231 -> V_238 ) ;
F_83 ( L_15 ) ;
F_82 ( & V_231 -> V_239 ) ;
F_83 ( L_22 ,
F_77 ( V_231 -> V_226 [ 0 ] ) ,
F_77 ( V_231 -> V_226 [ 1 ] ) ,
F_77 ( V_231 -> V_226 [ 2 ] ) ,
F_77 ( V_231 -> V_226 [ 3 ] ) ,
F_77 ( V_231 -> V_226 [ 4 ] ) ) ;
}
}
static void F_92 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
int V_18 , V_246 ;
struct V_247 * error ;
struct V_248 * V_249 ;
const T_1 V_250 [ V_212 ] = { [ 0 ... V_212 - 1 ] = '0' } ;
error = & V_125 -> V_132 . V_22 . error . V_22 . V_251 ;
V_235 ;
F_83 ( L_23 ,
error -> V_252 ,
V_7 -> V_26 -> V_190 ,
error -> V_253 . V_166 ,
error -> V_253 . V_172 ,
error -> V_253 . V_169 ) ;
V_235 ;
V_249 = error -> V_254 ;
V_246 = F_93 ( T_2 , F_77 ( error -> V_246 ) ,
F_94 ( error -> V_254 ) ) ;
for ( V_18 = 0 ; V_18 < V_246 ; V_18 ++ , V_249 ++ ) {
if ( ! memcmp ( V_249 -> V_209 . V_209 . V_216 , V_250 , V_212 ) )
continue;
if ( F_77 ( error -> V_255 ) == V_18 )
F_83 ( L_24 , V_18 ) ;
else
F_83 ( L_25 , V_18 ) ;
F_85 ( & V_249 -> V_209 ) ;
F_89 ( V_7 , V_249 -> V_236 , L_26 ) ;
F_89 ( V_7 , V_249 -> V_256 ,
L_27 ) ;
V_235 ;
}
}
static void F_95 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
int V_18 ;
struct V_257 * error ;
struct V_258 * V_249 ;
const T_1 V_250 [ V_212 ] = { [ 0 ... V_212 - 1 ] = '0' } ;
error = & V_125 -> V_132 . V_22 . error . V_22 . V_259 ;
V_235 ;
F_83 ( L_23 ,
error -> V_252 ,
V_7 -> V_26 -> V_190 ,
error -> V_253 . V_166 ,
error -> V_253 . V_172 ,
error -> V_253 . V_169 ) ;
V_235 ;
V_249 = error -> V_254 ;
for ( V_18 = 0 ; V_18 < 18 ; V_18 ++ ) {
if ( ! memcmp ( V_249 -> V_209 . V_216 , V_250 , V_212 ) )
continue;
if ( F_77 ( error -> V_255 ) == V_18 )
F_83 ( L_24 , V_18 ) ;
else
F_83 ( L_25 , V_18 ) ;
F_82 ( & V_249 -> V_209 ) ;
F_89 ( V_7 , V_249 -> V_236 , L_26 ) ;
F_89 ( V_7 , V_249 -> V_256 ,
L_27 ) ;
V_235 ;
if ( V_18 == 9 )
V_249 = error -> V_260 ;
else
V_249 ++ ;
}
}
static void F_96 ( struct V_6 * V_7 , T_4 * V_111 , int V_116 )
{
int V_18 ;
if ( V_116 == 0 )
return;
if ( V_7 -> V_261 <= V_262 )
V_116 = F_93 ( int , V_116 , V_263 ) ;
for ( V_18 = 0 ; V_18 < V_116 / 4 ; V_18 += 4 ) {
F_83 ( L_28 , V_18 * 4 ,
F_77 ( V_111 [ V_18 ] ) ,
F_77 ( V_111 [ V_18 + 1 ] ) ,
F_77 ( V_111 [ V_18 + 2 ] ) ,
F_77 ( V_111 [ V_18 + 3 ] ) ) ;
}
}
static void F_97 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_264 * error ;
if ( V_7 -> V_16 )
error = & V_125 -> V_132 . V_22 . V_220 . V_22 . V_265 ;
else
error = & V_125 -> V_132 . V_22 . error . V_22 . V_265 ;
error -> V_266 [ sizeof( error -> V_266 ) - 1 ] = '\0' ;
F_98 ( error -> V_266 ) ;
F_81 ( V_125 , L_29 , error -> V_266 ,
F_77 ( V_125 -> V_132 . V_22 . error . V_267 ) ) ;
F_84 ( L_30 , V_125 , & error -> V_209 ) ;
F_96 ( V_7 , error -> V_111 ,
F_77 ( V_125 -> V_132 . V_268 ) -
( F_9 ( struct V_269 , V_22 ) +
F_9 ( struct V_264 , V_111 ) ) ) ;
}
static void F_99 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_270 * error ;
error = & V_125 -> V_132 . V_22 . error . V_22 . V_271 ;
error -> V_266 [ sizeof( error -> V_266 ) - 1 ] = '\0' ;
F_98 ( error -> V_266 ) ;
F_81 ( V_125 , L_29 , error -> V_266 ,
F_77 ( V_125 -> V_132 . V_22 . error . V_267 ) ) ;
F_80 ( L_30 , V_125 , & error -> V_209 ) ;
F_96 ( V_7 , error -> V_111 ,
F_77 ( V_125 -> V_132 . V_268 ) -
( F_9 ( struct V_269 , V_22 ) +
F_9 ( struct V_270 , V_111 ) ) ) ;
}
static void F_100 ( struct V_124 * V_125 ,
struct V_272 * V_273 )
{
int V_18 , V_274 ;
T_1 V_275 = V_273 -> V_275 ;
T_1 V_276 = V_275 & V_277 ;
T_1 V_278 = V_275 & V_279 ;
for ( V_18 = 0 ; V_18 < F_94 ( V_280 ) ; V_18 ++ ) {
if ( V_280 [ V_18 ] . V_276 != V_276 )
continue;
for ( V_274 = 0 ; V_274 < F_94 ( V_281 ) ; V_274 ++ ) {
if ( V_281 [ V_274 ] . V_278 != V_278 )
continue;
if ( V_273 -> V_282 == 0xff && V_273 -> V_283 == 0xff ) {
F_81 ( V_125 , L_31 ,
V_280 [ V_18 ] . V_284 , V_281 [ V_274 ] . V_284 ,
V_273 -> V_285 ) ;
} else if ( V_273 -> V_282 == 0xff ) {
F_81 ( V_125 , L_32 ,
V_280 [ V_18 ] . V_284 , V_281 [ V_274 ] . V_284 ,
V_273 -> V_285 , V_273 -> V_283 ) ;
} else if ( V_273 -> V_283 == 0xff ) {
F_81 ( V_125 , L_33 ,
V_280 [ V_18 ] . V_284 , V_281 [ V_274 ] . V_284 ,
V_273 -> V_285 , V_273 -> V_282 ) ;
} else {
F_81 ( V_125 , L_34 ,
V_280 [ V_18 ] . V_284 , V_281 [ V_274 ] . V_284 ,
V_273 -> V_285 , V_273 -> V_282 , V_273 -> V_283 ) ;
}
return;
}
}
F_83 ( L_35 , V_275 ,
V_273 -> V_285 , V_273 -> V_282 , V_273 -> V_283 ) ;
}
static void F_101 ( struct V_124 * V_125 ,
struct V_286 * V_273 )
{
int V_18 , V_274 ;
T_1 V_275 = V_273 -> V_275 ;
T_1 V_276 = V_275 & V_277 ;
T_1 V_278 = V_275 & V_279 ;
char V_188 [ V_191 ] ;
for ( V_18 = 0 ; V_18 < F_94 ( V_280 ) ; V_18 ++ ) {
if ( V_280 [ V_18 ] . V_276 != V_276 )
continue;
for ( V_274 = 0 ; V_274 < F_94 ( V_281 ) ; V_274 ++ ) {
if ( V_281 [ V_274 ] . V_278 != V_278 )
continue;
F_81 ( V_125 , L_36 ,
V_280 [ V_18 ] . V_284 , V_281 [ V_274 ] . V_284 ,
F_69 ( V_125 -> V_7 ,
V_273 -> V_165 ,
V_188 , sizeof( V_188 ) ) ) ;
return;
}
}
F_83 ( L_37 , V_275 ,
F_69 ( V_125 -> V_7 , V_273 -> V_165 ,
V_188 , sizeof( V_188 ) ) ) ;
}
static void F_102 ( struct V_124 * V_125 ,
struct V_287 * V_288 )
{
int V_18 , V_274 ;
T_1 type = V_288 -> V_289 & V_290 ;
T_1 V_46 = V_288 -> V_289 & V_291 ;
if ( type == V_292 )
return;
for ( V_18 = 0 ; V_18 < F_94 ( V_293 ) ; V_18 ++ ) {
if ( V_293 [ V_18 ] . type != type )
continue;
for ( V_274 = 0 ; V_274 < F_94 ( V_294 ) ; V_274 ++ ) {
if ( V_294 [ V_274 ] . V_46 != V_46 )
continue;
if ( type == V_295 ) {
F_81 ( V_125 , L_38 ,
V_294 [ V_274 ] . V_284 , V_293 [ V_18 ] . V_284 ,
V_288 -> V_283 , V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) , F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
} else {
if ( V_288 -> V_282 == 0xff && V_288 -> V_283 == 0xff ) {
F_81 ( V_125 , L_39 ,
V_294 [ V_274 ] . V_284 , V_293 [ V_18 ] . V_284 ,
V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) , F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
} else if ( V_288 -> V_282 == 0xff ) {
F_81 ( V_125 , L_40
L_41 , V_294 [ V_274 ] . V_284 ,
V_293 [ V_18 ] . V_284 , V_288 -> V_283 ,
V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) , F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
} else if ( V_288 -> V_283 == 0xff ) {
F_81 ( V_125 , L_42
L_41 , V_294 [ V_274 ] . V_284 ,
V_293 [ V_18 ] . V_284 , V_288 -> V_282 ,
V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) , F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
} else {
F_81 ( V_125 , L_43
L_41 , V_294 [ V_274 ] . V_284 ,
V_293 [ V_18 ] . V_284 , V_288 -> V_282 , V_288 -> V_283 ,
V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) , F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
}
}
return;
}
}
F_81 ( V_125 , L_44
L_41 , V_288 -> V_289 , V_288 -> V_282 , V_288 -> V_283 ,
V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) , F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
}
static void F_103 ( struct V_124 * V_125 ,
struct V_298 * V_288 )
{
int V_18 , V_274 ;
T_1 V_299 = V_288 -> V_300 & V_301 ;
T_1 type = V_288 -> V_289 & V_290 ;
T_1 V_46 = V_288 -> V_289 & V_291 ;
char V_188 [ V_191 ] ;
if ( type == V_292 || V_299 != V_302 )
return;
for ( V_18 = 0 ; V_18 < F_94 ( V_293 ) ; V_18 ++ ) {
if ( V_293 [ V_18 ] . type != type )
continue;
for ( V_274 = 0 ; V_274 < F_94 ( V_294 ) ; V_274 ++ ) {
if ( V_294 [ V_274 ] . V_46 != V_46 )
continue;
F_81 ( V_125 , L_45 ,
V_294 [ V_274 ] . V_284 , V_293 [ V_18 ] . V_284 ,
F_69 ( V_125 -> V_7 ,
V_288 -> V_165 , V_188 , sizeof( V_188 ) ) ,
V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) ,
F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
return;
}
}
F_81 ( V_125 , L_46
L_41 , V_288 -> V_289 ,
F_69 ( V_125 -> V_7 ,
V_288 -> V_165 , V_188 , sizeof( V_188 ) ) ,
V_296 [ V_288 -> V_296 & V_297 ] ,
F_77 ( V_288 -> V_218 [ 0 ] ) , F_77 ( V_288 -> V_218 [ 1 ] ) ) ;
}
static void F_104 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_303 * error ;
struct V_272 * V_273 ;
struct V_287 * V_288 ;
int V_18 , V_304 ;
error = & V_125 -> V_132 . V_22 . error . V_22 . V_305 ;
error -> V_266 [ sizeof( error -> V_266 ) - 1 ] = '\0' ;
F_81 ( V_125 , L_47 , error -> V_266 ) ;
V_304 = F_77 ( V_125 -> V_132 . V_268 ) -
( F_9 ( struct V_269 , V_22 ) +
F_9 ( struct V_303 , V_284 ) ) ;
for ( V_18 = 0 , V_273 = error -> V_284 ; V_18 < error -> V_246 ; V_18 ++ ) {
F_100 ( V_125 , V_273 ) ;
F_105 (fabric, cfg)
F_102 ( V_125 , V_288 ) ;
V_304 -= F_59 ( V_273 -> V_268 ) ;
V_273 = (struct V_272 * )
( ( unsigned long ) V_273 + F_59 ( V_273 -> V_268 ) ) ;
}
F_96 ( V_7 , ( T_4 * ) V_273 , V_304 ) ;
}
static void F_106 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
int V_18 , V_246 ;
struct V_306 * error ;
struct V_307 * V_249 ;
char V_188 [ V_191 ] ;
const T_1 V_250 [ V_212 ] = { [ 0 ... V_212 - 1 ] = '0' } ;
error = & V_125 -> V_132 . V_22 . V_220 . V_22 . V_308 ;
V_235 ;
F_83 ( L_48 ,
error -> V_252 ,
F_69 ( V_7 , error -> V_309 ,
V_188 , sizeof( V_188 ) ) ) ;
V_235 ;
V_249 = error -> V_254 ;
V_246 = F_93 ( T_2 , error -> V_246 ,
F_94 ( error -> V_254 ) ) ;
for ( V_18 = 0 ; V_18 < V_246 ; V_18 ++ , V_249 ++ ) {
if ( ! memcmp ( V_249 -> V_209 . V_209 . V_216 , V_250 , V_212 ) )
continue;
if ( error -> V_255 == V_18 )
F_83 ( L_24 , V_18 ) ;
else
F_83 ( L_25 , V_18 ) ;
F_83 ( L_25 , V_18 ) ;
F_85 ( & V_249 -> V_209 ) ;
F_83 ( L_49 ,
F_69 ( V_7 , V_249 -> V_165 ,
V_188 , sizeof( V_188 ) ) ) ;
F_83 ( L_50 ,
F_69 ( V_7 ,
V_249 -> V_310 ,
V_188 , sizeof( V_188 ) ) ) ;
V_235 ;
}
}
static void F_107 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_311 * error ;
struct V_286 * V_273 ;
struct V_298 * V_288 ;
int V_18 , V_304 ;
error = & V_125 -> V_132 . V_22 . V_220 . V_22 . V_312 ;
error -> V_266 [ sizeof( error -> V_266 ) - 1 ] = '\0' ;
F_81 ( V_125 , L_47 , error -> V_266 ) ;
V_304 = F_77 ( V_125 -> V_132 . V_268 ) -
( F_9 ( struct V_313 , V_22 ) +
F_9 ( struct V_311 , V_284 ) ) ;
for ( V_18 = 0 , V_273 = error -> V_284 ; V_18 < error -> V_246 ; V_18 ++ ) {
F_101 ( V_125 , V_273 ) ;
F_105 (fabric, cfg)
F_103 ( V_125 , V_288 ) ;
V_304 -= F_59 ( V_273 -> V_268 ) ;
V_273 = (struct V_286 * )
( ( unsigned long ) V_273 + F_59 ( V_273 -> V_268 ) ) ;
}
F_96 ( V_7 , ( T_4 * ) V_273 , V_304 ) ;
}
static void F_108 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
F_96 ( V_7 , V_125 -> V_132 . V_22 . V_314 . V_111 ,
F_77 ( V_125 -> V_132 . V_268 ) ) ;
}
static void F_109 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
struct V_315 * error ;
char V_188 [ V_191 ] ;
error = & V_125 -> V_132 . V_22 . V_220 . V_22 . V_316 ;
F_83 ( L_51 ) ;
F_83 ( L_52 ,
F_77 ( error -> V_317 [ 0 ] ) , F_77 ( error -> V_317 [ 1 ] ) ,
F_77 ( error -> V_317 [ 2 ] ) , F_77 ( error -> V_317 [ 3 ] ) ) ;
F_83 ( L_53 ,
F_68 ( error -> V_165 ,
V_188 , sizeof( V_188 ) ) ) ;
error -> V_318 [ sizeof( error -> V_318 ) - 1 ] = '\0' ;
error -> V_319 [ sizeof( error -> V_319 ) - 1 ] = '\0' ;
F_83 ( L_54 , error -> V_318 ) ;
F_83 ( L_55 , error -> V_319 ) ;
F_83 ( L_56 ) ;
F_96 ( V_7 , error -> V_320 , sizeof( error -> V_320 ) ) ;
F_83 ( L_57 ) ;
F_96 ( V_7 , error -> V_15 , sizeof( error -> V_15 ) ) ;
F_83 ( L_58 ) ;
F_96 ( V_7 , error -> V_226 , F_77 ( error -> V_321 ) ) ;
}
static T_2 F_110 ( T_2 V_51 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_94 ( V_322 ) ; V_18 ++ )
if ( V_322 [ V_18 ] . V_51 == ( V_51 & V_323 ) )
return V_18 ;
return 0 ;
}
static void F_111 ( struct V_6 * V_7 ,
struct V_124 * V_125 )
{
T_2 V_51 ;
int V_324 ;
struct V_315 * error ;
if ( V_125 -> V_132 . V_201 != V_325 )
return;
if ( V_125 -> V_132 . V_326 == V_327 )
F_29 ( & V_7 -> V_77 -> V_82 , L_59 ) ;
if ( V_7 -> V_16 )
V_51 = F_77 ( V_125 -> V_132 . V_22 . V_220 . V_328 ) ;
else
V_51 = F_77 ( V_125 -> V_132 . V_22 . error . V_328 ) ;
if ( ! V_7 -> V_16 && ( V_51 == V_329 ||
V_51 == V_330 ) ) {
F_112 ( V_7 -> V_26 ,
V_125 -> V_132 . V_22 . error . V_331 . V_166 ) ;
}
V_324 = F_110 ( V_51 ) ;
if ( ! V_322 [ V_324 ] . V_332 )
return;
if ( V_51 == V_333 &&
V_125 -> V_132 . V_334 == V_335 ) {
error = & V_125 -> V_132 . V_22 . V_220 . V_22 . V_316 ;
if ( ( ( F_77 ( error -> V_320 [ 0 ] ) & 0x0000ff00 ) >> 8 ) == V_336 &&
V_7 -> V_261 <= V_262 )
return;
}
F_81 ( V_125 , L_47 , V_322 [ V_324 ] . error ) ;
V_7 -> V_229 ++ ;
if ( V_7 -> V_261 < V_322 [ V_324 ] . V_332 )
return;
if ( F_77 ( V_125 -> V_132 . V_268 ) > sizeof( V_125 -> V_132 . V_22 . V_314 ) )
V_125 -> V_132 . V_268 = F_10 ( sizeof( V_125 -> V_132 . V_22 . V_314 ) ) ;
switch ( V_125 -> V_132 . V_334 ) {
case V_337 :
F_87 ( V_7 , V_125 ) ;
break;
case V_338 :
F_91 ( V_7 , V_125 ) ;
break;
case V_339 :
case V_340 :
F_95 ( V_7 , V_125 ) ;
break;
case V_341 :
F_99 ( V_7 , V_125 ) ;
break;
case V_342 :
F_86 ( V_7 , V_125 ) ;
break;
case V_343 :
F_88 ( V_7 , V_125 ) ;
break;
case V_344 :
case V_345 :
F_92 ( V_7 , V_125 ) ;
break;
case V_346 :
F_97 ( V_7 , V_125 ) ;
break;
case V_347 :
F_104 ( V_7 , V_125 ) ;
break;
case V_335 :
F_109 ( V_7 , V_125 ) ;
break;
case V_348 :
F_90 ( V_7 , V_125 ) ;
break;
case V_349 :
case V_350 :
F_106 ( V_7 , V_125 ) ;
break;
case V_351 :
F_107 ( V_7 , V_125 ) ;
break;
case V_352 :
case V_353 :
default:
F_108 ( V_7 , V_125 ) ;
break;
}
}
static struct V_124 * F_113 ( struct V_6 * V_354 )
{
struct V_124 * V_125 ;
V_125 = F_114 ( & V_354 -> V_138 ,
struct V_124 , V_65 ) ;
if ( F_115 ( ! V_125 ) ) {
F_116 ( & V_354 -> V_77 -> V_82 , L_60 ) ;
V_125 = F_114 ( & V_354 -> V_355 ,
struct V_124 , V_65 ) ;
}
F_78 ( & V_125 -> V_65 ) ;
return V_125 ;
}
static void V_136 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_124 * V_125 = V_2 -> V_22 . V_125 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
T_2 V_328 ;
if ( V_7 -> V_16 )
V_328 = F_77 ( V_125 -> V_132 . V_22 . V_220 . V_328 ) ;
else
V_328 = F_77 ( V_125 -> V_132 . V_22 . error . V_328 ) ;
F_78 ( & V_125 -> V_65 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
if ( ! V_51 ) {
F_111 ( V_7 , V_125 ) ;
if ( V_328 == V_356 )
F_117 ( V_7 , V_357 ) ;
} else if ( V_51 != V_101 &&
V_51 != V_205 ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_7 , V_51 ) ;
}
F_35 ( & V_125 -> V_65 , & V_7 -> V_355 ) ;
F_75 ( & V_7 -> V_204 ) ;
V_125 = F_113 ( V_7 ) ;
F_56 ( V_7 , V_358 , V_125 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
unsigned long V_25 = 0 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_7 -> V_229 ++ ;
F_29 ( & V_7 -> V_77 -> V_82 ,
L_61 ) ;
if ( V_359 == V_7 -> V_360 )
V_7 -> V_360 = V_361 ;
if ( ! V_7 -> V_362 || V_7 -> V_363 == V_2 )
F_117 ( V_7 , V_364 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_105 ;
}
static void F_119 ( struct V_1 * V_2 )
{
unsigned long V_25 = 0 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_7 -> V_229 ++ ;
F_29 ( & V_7 -> V_77 -> V_82 ,
L_62 ) ;
if ( V_359 == V_7 -> V_360 )
V_7 -> V_360 = V_361 ;
if ( ! V_7 -> V_362 || V_7 -> V_363 == V_2 ) {
if ( V_365 )
V_7 -> V_366 += V_367 ;
F_117 ( V_7 , V_364 ) ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_105 ;
}
static const struct V_368 *
F_120 ( struct V_139 * V_140 )
{
int V_18 , V_274 , V_369 ;
struct V_370 * V_213 ;
const struct V_368 * V_371 = V_372 ;
for ( V_18 = 0 ; V_18 < F_94 ( V_372 ) ; V_18 ++ , V_371 ++ ) {
for ( V_274 = 0 , V_369 = 0 ; V_274 < V_211 ; V_274 ++ ) {
if ( V_371 -> V_373 [ V_274 ] == 'X' ) {
V_213 = & V_140 -> V_193 . V_213 ;
if ( V_213 -> V_215 [ V_274 ] == V_371 -> V_215 [ V_274 ] )
V_369 ++ ;
else
break;
} else
V_369 ++ ;
}
if ( V_369 == V_211 )
return V_371 ;
}
return NULL ;
}
static T_2 F_121 ( struct V_6 * V_7 , T_1 V_166 , T_1 V_374 )
{
struct V_139 * V_140 ;
const struct V_368 * V_371 ;
T_2 V_375 = F_122 ( V_374 ) ;
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( ! ( F_123 ( V_140 -> V_193 ) ) )
continue;
if ( V_166 != V_140 -> V_166 )
continue;
if ( ! ( V_371 = F_120 ( V_140 ) ) )
continue;
V_375 = ( V_371 -> V_376 * 10 ) / ( V_374 / 8 ) ;
}
return V_375 ;
}
static int F_124 ( struct V_6 * V_7 , int V_377 )
{
volatile T_2 V_378 ;
int V_379 = 1 ;
while ( V_379 < V_377 ) {
V_378 = F_25 ( V_7 -> V_20 . V_75 ) ;
if ( V_378 & V_380 )
return 0 ;
if ( ( V_379 / 1000 ) > V_381 )
F_125 ( V_379 / 1000 ) ;
else
F_126 ( V_379 ) ;
V_379 += V_379 ;
}
return - V_83 ;
}
static int F_127 ( struct V_6 * V_7 ,
T_2 V_382 ,
T_4 * V_383 , T_2 V_384 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_384 ; V_18 ++ ) {
F_24 ( V_382 + ( V_18 * 4 ) , V_7 -> V_20 . V_385 ) ;
* V_383 = F_10 ( F_25 ( V_7 -> V_20 . V_386 ) ) ;
V_383 ++ ;
}
return 0 ;
}
static int F_128 ( struct V_6 * V_7 ,
T_2 V_382 ,
T_4 * V_383 , T_2 V_384 )
{
volatile T_2 V_387 ;
int V_18 , V_379 = 0 ;
if ( V_7 -> V_16 )
return F_127 ( V_7 , V_382 ,
V_383 , V_384 ) ;
F_24 ( ( V_388 | V_389 ) ,
V_7 -> V_20 . V_390 ) ;
if ( F_124 ( V_7 ,
V_391 ) ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_63 ) ;
return - V_83 ;
}
F_24 ( V_380 ,
V_7 -> V_20 . V_73 ) ;
F_24 ( V_382 , V_7 -> V_392 ) ;
F_24 ( V_388 ,
V_7 -> V_20 . V_393 ) ;
for ( V_18 = 0 ; V_18 < V_384 ; V_18 ++ ) {
if ( F_124 ( V_7 ,
V_394 ) ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_64 ) ;
return - V_83 ;
}
* V_383 = F_10 ( F_25 ( V_7 -> V_392 ) ) ;
V_383 ++ ;
if ( V_18 < ( V_384 - 1 ) ) {
F_24 ( V_380 ,
V_7 -> V_20 . V_73 ) ;
}
}
F_24 ( V_388 ,
V_7 -> V_20 . V_390 ) ;
F_24 ( V_389 ,
V_7 -> V_20 . V_393 ) ;
F_24 ( V_380 ,
V_7 -> V_20 . V_73 ) ;
while ( V_379 < V_394 ) {
V_387 =
F_25 ( V_7 -> V_20 . V_395 ) ;
if ( ! ( V_387 & V_388 ) )
return 0 ;
F_126 ( 10 ) ;
V_379 += 10 ;
}
return 0 ;
}
static int F_129 ( struct V_6 * V_7 ,
unsigned long V_396 , T_2 V_268 )
{
int V_397 = 0 ;
int V_398 , V_399 , V_400 , V_401 , V_402 ;
T_4 * V_403 ;
unsigned long V_25 = 0 ;
struct V_404 * V_405 = & V_7 -> V_406 -> V_405 ;
if ( V_7 -> V_16 )
V_402 = V_407 ;
else
V_402 = V_408 ;
while ( V_397 < V_268 &&
( V_405 -> V_50 . V_116 + V_397 ) < V_402 ) {
if ( V_405 -> V_409 >= V_410 ||
V_405 -> V_409 == 0 ) {
V_403 = ( T_4 * ) F_130 ( V_411 ) ;
if ( ! V_403 ) {
V_412 ;
return V_397 ;
}
V_405 -> V_409 = 0 ;
V_405 -> V_226 [ V_405 -> V_413 ] = V_403 ;
V_405 -> V_413 ++ ;
} else
V_403 = V_405 -> V_226 [ V_405 -> V_413 - 1 ] ;
V_400 = V_268 - V_397 ;
V_401 = V_410 - V_405 -> V_409 ;
V_398 = F_131 ( V_400 , V_401 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_360 == V_414 ) {
V_399 = - V_83 ;
} else {
V_399 = F_128 ( V_7 ,
V_396 + V_397 ,
& V_403 [ V_405 -> V_409 / 4 ] ,
( V_398 / sizeof( T_2 ) ) ) ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( ! V_399 ) {
V_405 -> V_409 += V_398 ;
V_397 += V_398 ;
} else {
V_412 ;
break;
}
F_132 () ;
}
return V_397 ;
}
static void F_133 ( struct V_415 * V_50 )
{
V_50 -> V_416 = V_417 ;
V_50 -> V_418 = 1 ;
V_50 -> V_419 = sizeof( * V_50 ) ;
V_50 -> V_46 = V_420 ;
}
static void F_134 ( struct V_6 * V_7 ,
struct V_421 * V_422 )
{
struct V_423 * V_424 = & V_7 -> V_425 -> V_426 ;
F_133 ( & V_422 -> V_427 . V_50 ) ;
V_422 -> V_427 . V_50 . V_116 =
sizeof( struct V_428 ) -
sizeof( struct V_415 ) ;
V_422 -> V_427 . V_50 . V_429 = V_430 ;
V_422 -> V_427 . V_50 . V_431 = V_432 ;
V_422 -> V_427 . type = V_7 -> type ;
V_422 -> V_427 . V_433 = ( V_424 -> V_434 << 24 ) |
( V_424 -> V_435 << 16 ) | ( V_424 -> V_436 [ 0 ] << 8 ) |
V_424 -> V_436 [ 1 ] ;
V_422 -> V_50 . V_246 ++ ;
}
static void F_135 ( struct V_6 * V_7 ,
struct V_421 * V_422 )
{
F_133 ( & V_422 -> V_437 . V_50 ) ;
V_422 -> V_437 . V_50 . V_116 =
sizeof( struct V_438 ) -
sizeof( struct V_415 ) ;
V_422 -> V_437 . V_50 . V_429 = V_439 ;
V_422 -> V_437 . V_50 . V_431 = V_440 ;
strcpy ( V_422 -> V_437 . V_441 , V_442 ) ;
V_422 -> V_50 . V_246 ++ ;
}
static void F_136 ( struct V_6 * V_7 ,
struct V_421 * V_422 )
{
F_133 ( & V_422 -> V_5 . V_50 ) ;
V_422 -> V_5 . V_50 . V_116 =
sizeof( struct V_443 ) -
sizeof( struct V_415 ) ;
V_422 -> V_5 . V_50 . V_429 = V_430 ;
V_422 -> V_5 . V_50 . V_431 = V_444 ;
memcpy ( V_422 -> V_5 . V_10 , V_7 -> V_10 , V_445 ) ;
V_422 -> V_50 . V_246 ++ ;
}
static void F_137 ( struct V_6 * V_7 ,
struct V_421 * V_422 )
{
F_133 ( & V_422 -> V_446 . V_50 ) ;
V_422 -> V_446 . V_50 . V_116 =
sizeof( struct V_447 ) -
sizeof( struct V_415 ) ;
V_422 -> V_446 . V_50 . V_429 = V_439 ;
V_422 -> V_446 . V_50 . V_431 = V_448 ;
strcpy ( V_422 -> V_446 . V_449 , F_138 ( & V_7 -> V_77 -> V_82 ) ) ;
V_422 -> V_50 . V_246 ++ ;
}
static void F_139 ( struct V_6 * V_7 , struct V_450 * V_406 )
{
unsigned long V_382 , V_451 ;
unsigned long V_25 = 0 ;
struct V_421 * V_422 = & V_406 -> V_422 ;
struct V_404 * V_405 = & V_406 -> V_405 ;
T_2 V_246 , V_452 , V_453 , V_454 ;
T_2 V_402 , V_455 , V_397 , V_399 ;
struct V_456 * V_457 ;
int V_458 = 1 ;
int V_18 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_360 != V_459 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
if ( V_7 -> V_16 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_140 ( V_460 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
V_382 = F_25 ( V_7 -> V_392 ) ;
if ( ! V_7 -> V_16 && ! F_141 ( V_382 ) ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_65 , V_382 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
F_29 ( & V_7 -> V_77 -> V_82 , L_66 ) ;
V_422 -> V_50 . V_416 = V_417 ;
V_422 -> V_50 . V_116 = sizeof( struct V_421 ) ;
V_422 -> V_50 . V_246 = 1 ;
V_422 -> V_50 . V_461 = sizeof( struct V_462 ) ;
V_422 -> V_50 . V_46 = V_420 ;
V_422 -> V_50 . V_463 = V_464 ;
V_422 -> V_50 . V_465 = V_466 ;
F_135 ( V_7 , V_422 ) ;
F_137 ( V_7 , V_422 ) ;
F_134 ( V_7 , V_422 ) ;
F_136 ( V_7 , V_422 ) ;
V_422 -> V_50 . V_116 += sizeof( struct V_415 ) ;
F_133 ( & V_405 -> V_50 ) ;
V_405 -> V_50 . V_116 = 0 ;
V_405 -> V_50 . V_429 = V_430 ;
V_405 -> V_50 . V_431 = V_467 ;
V_457 = & V_405 -> V_457 ;
if ( V_7 -> V_16 ) {
V_452 = V_468 ;
V_402 = V_407 ;
} else {
V_452 = V_469 ;
V_402 = V_408 ;
}
V_455 = F_9 ( struct V_456 , V_470 ) +
( V_452 * sizeof( struct V_471 ) ) ;
V_399 = F_128 ( V_7 , V_382 , ( T_4 * ) V_457 ,
V_455 / sizeof( T_4 ) ) ;
if ( V_399 || ( ( F_77 ( V_457 -> V_50 . V_278 ) != V_472 ) &&
( F_77 ( V_457 -> V_50 . V_278 ) != V_473 ) ) ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_67 ,
V_399 , F_77 ( V_457 -> V_50 . V_278 ) ) ;
V_422 -> V_50 . V_46 = V_474 ;
V_7 -> V_360 = V_475 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
V_246 = F_77 ( V_457 -> V_50 . V_476 ) ;
if ( V_246 > V_452 )
V_246 = V_452 ;
V_406 -> V_422 . V_50 . V_116 += sizeof( struct V_477 ) ;
if ( V_7 -> V_16 )
V_406 -> V_422 . V_50 . V_116 += V_246 * sizeof( struct V_471 ) ;
else
V_406 -> V_422 . V_50 . V_116 += V_452 * sizeof( struct V_471 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
for ( V_18 = 0 ; V_18 < V_246 ; V_18 ++ ) {
if ( V_405 -> V_50 . V_116 > V_402 ) {
V_422 -> V_50 . V_46 = V_478 ;
break;
}
if ( V_457 -> V_470 [ V_18 ] . V_117 & V_479 ) {
V_451 = F_77 ( V_457 -> V_470 [ V_18 ] . V_480 ) ;
if ( V_7 -> V_16 )
V_455 = F_77 ( V_457 -> V_470 [ V_18 ] . V_481 ) ;
else {
V_453 = V_451 & V_482 ;
V_454 = F_77 ( V_457 -> V_470 [ V_18 ] . V_481 ) ;
if ( F_141 ( V_451 ) && V_451 )
V_455 = V_454 - V_453 ;
else
V_458 = 0 ;
}
if ( V_458 ) {
if ( V_455 > V_402 ) {
V_457 -> V_470 [ V_18 ] . V_117 &= ~ V_479 ;
continue;
}
V_397 = F_129 ( V_7 , V_451 ,
V_455 ) ;
V_405 -> V_50 . V_116 += V_397 ;
if ( V_397 != V_455 ) {
V_422 -> V_50 . V_46 = V_478 ;
break;
}
}
}
}
F_29 ( & V_7 -> V_77 -> V_82 , L_68 ) ;
V_422 -> V_50 . V_116 += V_405 -> V_50 . V_116 ;
F_3 () ;
V_7 -> V_360 = V_475 ;
V_105 ;
}
static void F_142 ( struct V_483 * V_483 )
{
struct V_450 * V_406 = F_143 ( V_483 , struct V_450 , V_483 ) ;
struct V_6 * V_7 = V_406 -> V_7 ;
unsigned long V_25 = 0 ;
int V_18 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_7 -> V_406 = NULL ;
V_7 -> V_360 = V_484 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
for ( V_18 = 0 ; V_18 < V_406 -> V_405 . V_413 ; V_18 ++ )
F_144 ( ( unsigned long ) V_406 -> V_405 . V_226 [ V_18 ] ) ;
F_145 ( V_406 -> V_405 . V_226 ) ;
F_146 ( V_406 ) ;
V_105 ;
}
static void F_147 ( struct V_485 * V_486 )
{
unsigned long V_25 ;
struct V_139 * V_140 ;
struct V_487 * V_160 ;
struct V_450 * V_406 ;
struct V_6 * V_7 =
F_143 ( V_486 , struct V_6 , V_204 ) ;
T_1 V_166 , V_172 , V_169 ;
int V_488 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_360 == V_459 ) {
V_406 = V_7 -> V_406 ;
if ( ! V_406 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
F_148 ( & V_406 -> V_483 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_139 ( V_7 , V_406 ) ;
F_149 ( & V_406 -> V_483 , F_142 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_360 == V_475 && ! V_7 -> V_489 )
F_117 ( V_7 , V_364 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
if ( V_7 -> V_490 ) {
V_7 -> V_490 = 0 ;
V_7 -> V_491 = 0 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_150 ( V_7 -> V_26 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_491 )
F_151 ( V_7 -> V_26 ) ;
}
if ( ! V_7 -> V_492 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
V_493:
do {
V_488 = 0 ;
if ( ! V_7 -> V_62 [ V_66 ] . V_126 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( V_140 -> V_157 && V_140 -> V_160 ) {
V_488 = 1 ;
V_160 = V_140 -> V_160 ;
if ( ! F_152 ( V_160 ) ) {
if ( ! V_140 -> V_156 )
F_76 ( & V_140 -> V_65 , & V_7 -> V_199 ) ;
else
V_140 -> V_157 = 0 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_153 ( V_160 ) ;
F_154 ( V_160 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
break;
}
}
} while ( V_488 );
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( V_140 -> V_156 ) {
V_166 = V_140 -> V_166 ;
V_172 = V_140 -> V_172 ;
V_169 = V_140 -> V_169 ;
V_140 -> V_156 = 0 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_155 ( V_7 -> V_26 , V_166 , V_172 , V_169 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
goto V_493;
}
}
V_7 -> V_494 = 1 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_156 ( & V_7 -> V_26 -> V_495 . V_496 , V_497 ) ;
V_105 ;
}
static T_5 F_157 ( struct V_498 * V_499 , struct V_500 * V_496 ,
struct V_501 * V_502 ,
char * V_206 , T_6 V_503 , T_7 V_504 )
{
struct V_505 * V_82 = F_143 ( V_496 , struct V_505 , V_496 ) ;
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 = 0 ;
T_5 V_509 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_509 = F_159 ( V_206 , V_504 , & V_503 , V_7 -> V_10 ,
V_445 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_509 ;
}
static T_5 F_160 ( struct V_505 * V_82 ,
struct V_510 * V_511 , char * V_206 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
struct V_423 * V_424 = & V_7 -> V_425 -> V_426 ;
unsigned long V_25 = 0 ;
int V_116 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_116 = snprintf ( V_206 , V_410 , L_69 ,
V_424 -> V_434 , V_424 -> V_435 ,
V_424 -> V_436 [ 0 ] ,
V_424 -> V_436 [ 1 ] ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_161 ( struct V_505 * V_82 ,
struct V_510 * V_511 , char * V_206 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 = 0 ;
int V_116 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_116 = snprintf ( V_206 , V_410 , L_70 , V_7 -> V_261 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_162 ( struct V_505 * V_82 ,
struct V_510 * V_511 ,
const char * V_206 , T_7 V_504 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 = 0 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_7 -> V_261 = F_163 ( V_206 , NULL , 10 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return strlen ( V_206 ) ;
}
static T_5 F_164 ( struct V_505 * V_82 ,
struct V_510 * V_511 ,
const char * V_206 , T_7 V_504 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 = 0 ;
int V_399 = V_504 ;
if ( ! F_165 ( V_512 ) )
return - V_513 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
while ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
V_7 -> V_229 = 0 ;
F_117 ( V_7 , V_515 ) ;
if ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_167 ( 1000 ) ;
} else {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return - V_83 ;
}
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_362 || V_7 -> V_229 )
V_399 = - V_83 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_399 ;
}
static T_5 F_168 ( struct V_505 * V_82 ,
struct V_510 * V_511 , char * V_206 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 = 0 ;
int V_116 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_62 [ V_66 ] . V_516 )
V_116 = snprintf ( V_206 , V_410 , L_71 ) ;
else
V_116 = snprintf ( V_206 , V_410 , L_72 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_169 ( struct V_505 * V_82 ,
struct V_510 * V_511 ,
const char * V_206 , T_7 V_504 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 ;
int V_96 = V_504 , V_18 ;
if ( ! F_165 ( V_512 ) )
return - V_513 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_62 [ V_66 ] . V_516 &&
! strncmp ( V_206 , L_73 , 6 ) ) {
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_516 = 0 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
V_7 -> V_366 = 0 ;
V_7 -> V_517 = 0 ;
F_117 ( V_7 , V_364 ) ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
return V_96 ;
}
static T_5 F_170 ( struct V_505 * V_82 ,
struct V_510 * V_511 ,
const char * V_206 , T_7 V_504 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 ;
int V_96 = V_504 ;
if ( ! F_165 ( V_512 ) )
return - V_513 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( ! V_7 -> V_362 )
F_117 ( V_7 , V_515 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
return V_96 ;
}
static T_5 F_171 ( struct V_505 * V_82 ,
struct V_510 * V_511 , char * V_206 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 = 0 ;
int V_116 ;
F_5 ( V_507 -> V_27 , V_25 ) ;
V_116 = snprintf ( V_206 , V_410 , L_70 , V_7 -> V_518 ) ;
F_6 ( V_507 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_172 ( struct V_505 * V_82 ,
struct V_510 * V_511 ,
const char * V_206 , T_7 V_504 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_519 ;
unsigned long V_25 = 0 ;
int V_18 ;
if ( ! V_7 -> V_16 ) {
F_116 ( & V_7 -> V_77 -> V_82 , L_74 ) ;
return - V_520 ;
}
if ( F_173 ( V_206 , 10 , & V_519 ) )
return - V_520 ;
if ( V_519 > 256 ) {
F_116 ( & V_7 -> V_77 -> V_82 , L_75 ) ;
return - V_520 ;
}
if ( V_519 == V_7 -> V_518 ) {
F_116 ( & V_7 -> V_77 -> V_82 , L_76 ) ;
return strlen ( V_206 ) ;
}
if ( V_7 -> V_518 && V_7 -> V_16 && V_7 -> V_521 > 1 ) {
for ( V_18 = 1 ; V_18 < V_7 -> V_69 ; V_18 ++ )
F_174 ( & V_7 -> V_62 [ V_18 ] . V_522 ) ;
}
F_5 ( V_507 -> V_27 , V_25 ) ;
V_7 -> V_518 = V_519 ;
if ( V_7 -> V_518 && V_7 -> V_16 && V_7 -> V_521 > 1 ) {
for ( V_18 = 1 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_175 ( & V_7 -> V_62 [ V_18 ] . V_522 ,
V_7 -> V_518 , V_523 ) ;
}
}
F_6 ( V_507 -> V_27 , V_25 ) ;
return strlen ( V_206 ) ;
}
static struct V_524 * F_176 ( int V_525 )
{
int V_526 , V_527 , V_528 , V_529 , V_18 , V_274 ;
struct V_524 * V_530 ;
struct V_531 * V_531 ;
struct V_403 * V_403 ;
V_526 = V_525 / ( V_532 - 1 ) ;
V_527 = F_177 ( V_526 ) ;
V_528 = V_410 * ( 1 << V_527 ) ;
if ( V_525 % V_528 )
V_529 = ( V_525 / V_528 ) + 1 ;
else
V_529 = V_525 / V_528 ;
V_530 = F_178 ( sizeof( struct V_524 ) +
( sizeof( struct V_531 ) * ( V_529 - 1 ) ) ,
V_533 ) ;
if ( V_530 == NULL ) {
V_412 ;
return NULL ;
}
V_531 = V_530 -> V_531 ;
F_179 ( V_531 , V_529 ) ;
V_530 -> V_527 = V_527 ;
V_530 -> V_534 = V_529 ;
for ( V_18 = 0 ; V_18 < V_529 ; V_18 ++ ) {
V_403 = F_180 ( V_533 , V_527 ) ;
if ( ! V_403 ) {
V_412 ;
for ( V_274 = V_18 - 1 ; V_274 >= 0 ; V_274 -- )
F_181 ( F_182 ( & V_531 [ V_274 ] ) , V_527 ) ;
F_146 ( V_530 ) ;
return NULL ;
}
F_183 ( & V_531 [ V_18 ] , V_403 , 0 , 0 ) ;
}
return V_530 ;
}
static void F_184 ( struct V_524 * V_530 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_530 -> V_534 ; V_18 ++ )
F_181 ( F_182 ( & V_530 -> V_531 [ V_18 ] ) , V_530 -> V_527 ) ;
F_146 ( V_530 ) ;
}
static int F_185 ( struct V_524 * V_530 ,
T_1 * V_188 , T_2 V_116 )
{
int V_528 , V_18 , V_96 = 0 ;
struct V_531 * V_531 ;
void * V_535 ;
V_528 = V_410 * ( 1 << V_530 -> V_527 ) ;
V_531 = V_530 -> V_531 ;
for ( V_18 = 0 ; V_18 < ( V_116 / V_528 ) ; V_18 ++ , V_188 += V_528 ) {
struct V_403 * V_403 = F_182 ( & V_531 [ V_18 ] ) ;
V_535 = F_186 ( V_403 ) ;
memcpy ( V_535 , V_188 , V_528 ) ;
F_187 ( V_403 ) ;
V_531 [ V_18 ] . V_268 = V_528 ;
if ( V_96 != 0 ) {
V_412 ;
return V_96 ;
}
}
if ( V_116 % V_528 ) {
struct V_403 * V_403 = F_182 ( & V_531 [ V_18 ] ) ;
V_535 = F_186 ( V_403 ) ;
memcpy ( V_535 , V_188 , V_116 % V_528 ) ;
F_187 ( V_403 ) ;
V_531 [ V_18 ] . V_268 = V_116 % V_528 ;
}
V_530 -> V_536 = V_116 ;
return V_96 ;
}
static void F_188 ( struct V_1 * V_2 ,
struct V_524 * V_530 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_107 * V_44 = V_2 -> V_18 . V_44 ;
struct V_531 * V_531 = V_530 -> V_531 ;
int V_18 ;
V_2 -> V_56 = V_530 -> V_537 ;
V_13 -> V_14 . V_538 |= V_539 ;
V_13 -> V_38 = F_10 ( V_530 -> V_536 ) ;
V_13 -> V_40 =
F_10 ( sizeof( struct V_107 ) * V_2 -> V_56 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_56 ; V_18 ++ ) {
V_44 [ V_18 ] . V_117 = F_10 ( V_540 ) ;
V_44 [ V_18 ] . V_119 = F_10 ( F_189 ( & V_531 [ V_18 ] ) ) ;
V_44 [ V_18 ] . V_120 = F_8 ( F_190 ( & V_531 [ V_18 ] ) ) ;
}
V_44 [ V_18 - 1 ] . V_117 |= F_10 ( V_541 ) ;
}
static void F_191 ( struct V_1 * V_2 ,
struct V_524 * V_530 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_118 * V_48 = V_2 -> V_18 . V_48 ;
struct V_531 * V_531 = V_530 -> V_531 ;
int V_18 ;
V_2 -> V_56 = V_530 -> V_537 ;
V_13 -> V_14 . V_538 |= V_539 ;
V_13 -> V_38 = F_10 ( V_530 -> V_536 ) ;
V_13 -> V_40 =
F_10 ( sizeof( struct V_118 ) * V_2 -> V_56 ) ;
for ( V_18 = 0 ; V_18 < V_2 -> V_56 ; V_18 ++ ) {
V_48 [ V_18 ] . V_121 =
F_10 ( V_540 | F_189 ( & V_531 [ V_18 ] ) ) ;
V_48 [ V_18 ] . V_120 =
F_10 ( F_190 ( & V_531 [ V_18 ] ) ) ;
}
V_48 [ V_18 - 1 ] . V_121 |=
F_10 ( V_541 ) ;
}
static int F_192 ( struct V_6 * V_7 ,
struct V_524 * V_530 )
{
unsigned long V_25 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
while ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
if ( V_7 -> V_542 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_29 ( & V_7 -> V_77 -> V_82 ,
L_77 ) ;
return - V_83 ;
}
V_530 -> V_537 = F_193 ( & V_7 -> V_77 -> V_82 ,
V_530 -> V_531 , V_530 -> V_534 ,
V_543 ) ;
if ( ! V_530 -> V_537 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_29 ( & V_7 -> V_77 -> V_82 ,
L_78 ) ;
return - V_83 ;
}
V_7 -> V_542 = V_530 ;
F_117 ( V_7 , V_515 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_7 -> V_542 = NULL ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return 0 ;
}
static T_5 F_194 ( struct V_505 * V_82 ,
struct V_510 * V_511 ,
const char * V_206 , T_7 V_504 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
struct V_544 * V_545 ;
const struct V_546 * V_547 ;
struct V_524 * V_530 ;
char V_548 [ 100 ] ;
char * V_549 ;
char * V_550 ;
int V_96 , V_551 ;
if ( ! F_165 ( V_512 ) )
return - V_513 ;
snprintf ( V_548 , sizeof( V_548 ) , L_79 , V_206 ) ;
V_550 = strchr ( V_548 , '\n' ) ;
if ( V_550 )
* V_550 = '\0' ;
if ( F_195 ( & V_547 , V_548 , & V_7 -> V_77 -> V_82 ) ) {
F_29 ( & V_7 -> V_77 -> V_82 , L_80 , V_548 ) ;
return - V_83 ;
}
V_545 = (struct V_544 * ) V_547 -> V_111 ;
V_549 = ( T_1 * ) V_545 + F_77 ( V_545 -> V_552 ) ;
V_551 = V_547 -> V_553 - F_77 ( V_545 -> V_552 ) ;
V_530 = F_176 ( V_551 ) ;
if ( ! V_530 ) {
F_29 ( & V_7 -> V_77 -> V_82 , L_81 ) ;
F_196 ( V_547 ) ;
return - V_554 ;
}
V_96 = F_185 ( V_530 , V_549 , V_551 ) ;
if ( V_96 ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_82 ) ;
goto V_555;
}
F_197 ( L_83 ) ;
V_96 = F_192 ( V_7 , V_530 ) ;
if ( ! V_96 )
V_96 = V_504 ;
V_555:
F_184 ( V_530 ) ;
F_196 ( V_547 ) ;
return V_96 ;
}
static T_5 F_198 ( struct V_505 * V_82 ,
struct V_510 * V_511 , char * V_206 )
{
struct V_506 * V_507 = F_158 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
unsigned long V_25 = 0 ;
int V_116 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_116 = snprintf ( V_206 , V_410 , L_70 , V_7 -> V_16 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_199 ( struct V_498 * V_556 , struct V_500 * V_496 ,
struct V_501 * V_502 , char * V_206 ,
T_6 V_503 , T_7 V_504 )
{
struct V_505 * V_557 = F_143 ( V_496 , struct V_505 , V_496 ) ;
struct V_506 * V_507 = F_158 ( V_557 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
struct V_124 * V_125 ;
unsigned long V_25 = 0 ;
int V_509 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_125 = F_114 ( & V_7 -> V_355 ,
struct V_124 , V_65 ) ;
if ( ! V_125 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return 0 ;
}
V_509 = F_159 ( V_206 , V_504 , & V_503 , & V_125 -> V_132 ,
sizeof( V_125 -> V_132 ) ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_509 ;
}
static T_5 F_200 ( struct V_498 * V_556 , struct V_500 * V_496 ,
struct V_501 * V_502 , char * V_206 ,
T_6 V_503 , T_7 V_504 )
{
struct V_505 * V_557 = F_143 ( V_496 , struct V_505 , V_496 ) ;
struct V_506 * V_507 = F_158 ( V_557 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
struct V_124 * V_125 ;
unsigned long V_25 = 0 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_125 = F_114 ( & V_7 -> V_355 ,
struct V_124 , V_65 ) ;
if ( ! V_125 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_504 ;
}
F_76 ( & V_125 -> V_65 , & V_7 -> V_138 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_504 ;
}
static T_5 F_201 ( struct V_498 * V_499 , struct V_500 * V_496 ,
struct V_501 * V_502 ,
char * V_206 , T_6 V_503 , T_7 V_504 )
{
struct V_505 * V_557 = F_143 ( V_496 , struct V_505 , V_496 ) ;
struct V_506 * V_507 = F_158 ( V_557 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
struct V_450 * V_406 ;
unsigned long V_25 = 0 ;
char * V_549 ;
int V_116 , V_558 ;
T_7 V_399 = V_504 ;
if ( ! F_165 ( V_512 ) )
return - V_513 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_406 = V_7 -> V_406 ;
if ( V_7 -> V_360 != V_475 || ! V_406 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return 0 ;
}
F_148 ( & V_406 -> V_483 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_503 > V_406 -> V_422 . V_50 . V_116 ) {
F_149 ( & V_406 -> V_483 , F_142 ) ;
return 0 ;
}
if ( V_503 + V_504 > V_406 -> V_422 . V_50 . V_116 ) {
V_504 = V_406 -> V_422 . V_50 . V_116 - V_503 ;
V_399 = V_504 ;
}
if ( V_504 && V_503 < sizeof( V_406 -> V_422 ) ) {
if ( V_503 + V_504 > sizeof( V_406 -> V_422 ) )
V_116 = sizeof( V_406 -> V_422 ) - V_503 ;
else
V_116 = V_504 ;
V_549 = ( T_1 * ) & V_406 -> V_422 + V_503 ;
memcpy ( V_206 , V_549 , V_116 ) ;
V_206 += V_116 ;
V_503 += V_116 ;
V_504 -= V_116 ;
}
V_503 -= sizeof( V_406 -> V_422 ) ;
if ( V_7 -> V_16 )
V_558 = F_9 ( struct V_404 , V_457 . V_470 ) +
( F_77 ( V_406 -> V_405 . V_457 . V_50 . V_476 ) *
sizeof( struct V_471 ) ) ;
else
V_558 = F_9 ( struct V_404 , V_457 . V_470 ) +
( V_469 * sizeof( struct V_471 ) ) ;
if ( V_504 && V_503 < V_558 ) {
if ( V_503 + V_504 > V_558 )
V_116 = V_558 - V_503 ;
else
V_116 = V_504 ;
V_549 = ( T_1 * ) & V_406 -> V_405 + V_503 ;
memcpy ( V_206 , V_549 , V_116 ) ;
V_206 += V_116 ;
V_503 += V_116 ;
V_504 -= V_116 ;
}
V_503 -= V_558 ;
while ( V_504 ) {
if ( ( V_503 & V_559 ) != ( ( V_503 + V_504 ) & V_559 ) )
V_116 = F_202 ( V_503 ) - V_503 ;
else
V_116 = V_504 ;
V_549 = ( T_1 * ) V_406 -> V_405 . V_226 [ ( V_503 & V_559 ) >> V_560 ] ;
V_549 += V_503 & ~ V_559 ;
memcpy ( V_206 , V_549 , V_116 ) ;
V_206 += V_116 ;
V_503 += V_116 ;
V_504 -= V_116 ;
}
F_149 ( & V_406 -> V_483 , F_142 ) ;
return V_399 ;
}
static int F_203 ( struct V_6 * V_7 )
{
struct V_450 * V_406 ;
T_4 * * V_226 ;
unsigned long V_25 = 0 ;
V_406 = F_178 ( sizeof( struct V_450 ) , V_533 ) ;
if ( ! V_406 ) {
F_83 ( L_84 ) ;
return - V_554 ;
}
if ( V_7 -> V_16 )
V_226 = F_204 ( V_561 * sizeof( T_4 * ) ) ;
else
V_226 = F_204 ( V_562 * sizeof( T_4 * ) ) ;
if ( ! V_226 ) {
F_83 ( L_84 ) ;
F_146 ( V_406 ) ;
return - V_554 ;
}
V_406 -> V_405 . V_226 = V_226 ;
F_205 ( & V_406 -> V_483 ) ;
V_406 -> V_7 = V_7 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_484 != V_7 -> V_360 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_145 ( V_406 -> V_405 . V_226 ) ;
F_146 ( V_406 ) ;
return 0 ;
}
V_7 -> V_406 = V_406 ;
V_7 -> V_360 = V_359 ;
if ( V_7 -> V_62 [ V_66 ] . V_516 && ! V_7 -> V_563 ) {
V_7 -> V_563 = 1 ;
F_75 ( & V_7 -> V_204 ) ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return 0 ;
}
static int F_206 ( struct V_6 * V_7 )
{
struct V_450 * V_406 ;
unsigned long V_25 = 0 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_406 = V_7 -> V_406 ;
if ( ! V_406 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return 0 ;
}
V_7 -> V_406 = NULL ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_149 ( & V_406 -> V_483 , F_142 ) ;
V_105 ;
return 0 ;
}
static T_5 F_207 ( struct V_498 * V_499 , struct V_500 * V_496 ,
struct V_501 * V_502 ,
char * V_206 , T_6 V_503 , T_7 V_504 )
{
struct V_505 * V_557 = F_143 ( V_496 , struct V_505 , V_496 ) ;
struct V_506 * V_507 = F_158 ( V_557 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
int V_399 ;
if ( ! F_165 ( V_512 ) )
return - V_513 ;
if ( V_206 [ 0 ] == '1' )
V_399 = F_203 ( V_7 ) ;
else if ( V_206 [ 0 ] == '0' )
V_399 = F_206 ( V_7 ) ;
else
return - V_520 ;
if ( V_399 )
return V_399 ;
else
return V_504 ;
}
static int F_206 ( struct V_6 * V_7 ) { return 0 ; }
static int F_208 ( struct V_487 * V_160 , int V_564 )
{
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 && F_209 ( V_140 ) && V_564 > V_565 )
V_564 = V_565 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_210 ( V_160 , V_564 ) ;
return V_160 -> V_566 ;
}
static T_5 F_211 ( struct V_505 * V_82 , struct V_510 * V_511 , char * V_206 )
{
struct V_487 * V_160 = F_212 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
T_5 V_116 = - V_567 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 )
V_116 = snprintf ( V_206 , V_410 , L_85 , V_140 -> V_24 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_213 ( struct V_505 * V_82 , struct V_510 * V_511 , char * V_206 )
{
struct V_487 * V_160 = F_212 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
T_5 V_116 = - V_567 ;
char V_188 [ V_191 ] ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 && V_7 -> V_16 )
V_116 = snprintf ( V_206 , V_410 , L_47 ,
F_68 ( V_140 -> V_165 , V_188 ,
sizeof( V_188 ) ) ) ;
else if ( V_140 )
V_116 = snprintf ( V_206 , V_410 , L_86 , V_7 -> V_26 -> V_190 ,
V_140 -> V_166 , V_140 -> V_172 , V_140 -> V_169 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_214 ( struct V_505 * V_82 , struct V_510 * V_511 , char * V_206 )
{
struct V_487 * V_160 = F_212 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
T_5 V_116 = - V_567 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 && V_7 -> V_16 )
V_116 = snprintf ( V_206 , V_410 , L_87 , F_215 ( V_140 -> V_171 ) ) ;
else if ( V_140 )
V_116 = snprintf ( V_206 , V_410 , L_87 , V_140 -> V_187 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_216 ( struct V_505 * V_82 , struct V_510 * V_511 , char * V_206 )
{
struct V_487 * V_160 = F_212 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
T_5 V_116 = - V_567 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 )
V_116 = snprintf ( V_206 , V_410 , L_88 , V_140 -> type ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_217 ( struct V_505 * V_82 ,
struct V_510 * V_511 , char * V_206 )
{
struct V_487 * V_160 = F_212 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
T_5 V_116 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 )
V_116 = snprintf ( V_206 , V_410 , L_70 , V_140 -> V_568 ) ;
else
V_116 = - V_567 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static T_5 F_218 ( struct V_505 * V_82 ,
struct V_510 * V_511 ,
const char * V_206 , T_7 V_504 )
{
struct V_487 * V_160 = F_212 ( V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
T_5 V_116 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 ) {
if ( F_219 ( V_140 ) ) {
V_140 -> V_568 = F_163 ( V_206 , NULL , 10 ) ;
V_116 = strlen ( V_206 ) ;
if ( V_140 -> V_160 )
F_71 ( V_195 , V_140 -> V_160 , L_89 ,
V_140 -> V_568 ? L_90 : L_91 ) ;
} else
V_116 = - V_520 ;
} else
V_116 = - V_567 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_116 ;
}
static int F_220 ( struct V_487 * V_160 ,
struct V_569 * V_569 ,
T_8 V_570 , int * V_571 )
{
int V_572 , V_573 ;
T_8 V_574 ;
V_572 = 128 ;
V_573 = 32 ;
V_574 = V_570 ;
F_221 ( V_574 , ( 128 * 32 ) ) ;
V_571 [ 0 ] = V_572 ;
V_571 [ 1 ] = V_573 ;
V_571 [ 2 ] = V_574 ;
return 0 ;
}
static struct V_139 * F_222 ( struct V_575 * V_576 )
{
struct V_506 * V_507 = F_223 ( & V_576 -> V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
struct V_139 * V_140 ;
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( ( V_140 -> V_166 == V_576 -> V_577 ) &&
( V_140 -> V_172 == V_576 -> V_431 ) ) {
return V_140 ;
}
}
return NULL ;
}
static int F_224 ( struct V_575 * V_576 )
{
struct V_506 * V_507 = F_223 ( & V_576 -> V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
struct V_87 * V_88 ;
struct V_578 * V_89 ;
struct V_139 * V_140 ;
unsigned long V_25 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = F_222 ( V_576 ) ;
V_576 -> V_508 = NULL ;
if ( V_140 && F_209 ( V_140 ) ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_88 = F_178 ( sizeof( * V_88 ) , V_533 ) ;
if ( ! V_88 )
return - V_554 ;
V_89 = F_225 ( & V_7 -> V_579 , & V_580 , V_507 ) ;
if ( V_89 ) {
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_88 -> V_7 = V_7 ;
V_88 -> V_89 = V_89 ;
V_88 -> V_140 = V_140 ;
V_140 -> V_88 = V_88 ;
V_89 -> V_90 = V_88 ;
V_576 -> V_508 = V_88 ;
} else {
F_146 ( V_88 ) ;
return - V_554 ;
}
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return 0 ;
}
static void F_226 ( struct V_575 * V_576 )
{
struct V_87 * V_88 = V_576 -> V_508 ;
struct V_506 * V_507 = F_223 ( & V_576 -> V_82 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
if ( V_7 -> V_16 ) {
if ( ! F_222 ( V_576 ) ) {
if ( V_576 -> V_577 == V_178 )
F_73 ( V_576 -> V_431 , V_7 -> V_179 ) ;
else if ( V_576 -> V_577 == V_181 )
F_73 ( V_576 -> V_431 , V_7 -> V_182 ) ;
else if ( V_576 -> V_577 == 0 )
F_73 ( V_576 -> V_431 , V_7 -> V_173 ) ;
}
}
if ( V_88 ) {
V_576 -> V_508 = NULL ;
F_227 ( V_88 -> V_89 ) ;
F_146 ( V_88 ) ;
}
}
static struct V_139 * F_228 ( struct V_487 * V_160 )
{
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( ( V_140 -> V_166 == V_160 -> V_577 ) &&
( V_140 -> V_172 == V_160 -> V_431 ) &&
( V_140 -> V_169 == V_160 -> V_169 ) )
return V_140 ;
}
return NULL ;
}
static void F_229 ( struct V_487 * V_160 )
{
struct V_139 * V_140 ;
struct V_6 * V_7 ;
unsigned long V_25 = 0 ;
V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 ) {
if ( V_140 -> V_88 )
V_140 -> V_88 -> V_89 -> V_581 . V_505 [ 0 ] . V_582 = V_583 ;
V_160 -> V_508 = NULL ;
V_140 -> V_160 = NULL ;
V_140 -> V_88 = NULL ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
static int F_230 ( struct V_487 * V_160 )
{
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
struct V_578 * V_89 = NULL ;
unsigned long V_25 = 0 ;
char V_188 [ V_191 ] ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = V_160 -> V_508 ;
if ( V_140 ) {
if ( F_219 ( V_140 ) )
V_160 -> type = V_584 ;
if ( F_219 ( V_140 ) || F_231 ( V_140 ) ) {
V_160 -> V_585 = 4 ;
V_160 -> V_586 = 1 ;
}
if ( F_232 ( V_140 ) ) {
V_160 -> V_585 = V_587 ;
V_160 -> V_588 = 1 ;
F_233 ( V_160 -> V_589 ,
V_590 ) ;
F_234 ( V_160 -> V_589 , V_591 ) ;
}
if ( F_209 ( V_140 ) && V_140 -> V_88 )
V_89 = V_140 -> V_88 -> V_89 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_89 ) {
F_210 ( V_160 , V_565 ) ;
F_235 ( V_160 , V_89 ) ;
}
if ( V_7 -> V_16 )
F_71 ( V_195 , V_160 , L_6 ,
F_69 ( V_7 ,
V_140 -> V_165 , V_188 , sizeof( V_188 ) ) ) ;
return 0 ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return 0 ;
}
static int F_236 ( struct V_487 * V_160 )
{
struct V_87 * V_88 = NULL ;
int V_399 = - V_567 ;
V_100 ;
if ( V_160 -> V_592 )
V_88 = V_160 -> V_592 -> V_508 ;
if ( V_88 ) {
V_399 = F_237 ( V_88 -> V_89 ) ;
if ( V_399 == 0 )
V_399 = F_238 ( V_88 -> V_89 ) ;
}
if ( V_399 )
F_229 ( V_160 ) ;
V_105 ;
return V_399 ;
}
static int F_239 ( struct V_487 * V_160 )
{
struct V_6 * V_7 = (struct V_6 * ) V_160 -> V_26 -> V_508 ;
struct V_139 * V_140 ;
unsigned long V_25 ;
int V_399 = - V_567 ;
V_160 -> V_508 = NULL ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_140 = F_228 ( V_160 ) ;
if ( V_140 ) {
V_140 -> V_160 = V_160 ;
V_140 -> V_156 = 0 ;
V_140 -> V_155 = 0 ;
V_160 -> V_508 = V_140 ;
if ( ! F_240 ( V_140 ) )
V_140 -> V_154 = 1 ;
V_399 = 0 ;
if ( F_209 ( V_140 ) ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return F_236 ( V_160 ) ;
}
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_399 ;
}
static int F_241 ( struct V_1 * V_2 , void * V_505 )
{
if ( V_2 -> V_53 && V_2 -> V_53 -> V_505 == V_505 )
return 1 ;
return 0 ;
}
static bool F_242 ( struct V_1 * V_2 )
{
struct V_1 * V_593 ;
F_62 (loop_cmd, &ipr_cmd->hrrq->hrrq_free_q, queue) {
if ( V_593 == V_2 )
return true ;
}
return false ;
}
static int F_243 ( struct V_1 * V_2 , void * V_594 )
{
struct V_139 * V_140 = V_594 ;
if ( V_140 && V_2 -> V_13 . V_24 == V_140 -> V_24 )
return 1 ;
return 0 ;
}
static int F_244 ( struct V_6 * V_7 , void * V_505 ,
int (* F_245)( struct V_1 * , void * ) )
{
struct V_1 * V_2 ;
int V_595 , V_18 ;
unsigned long V_117 ;
struct V_61 * V_62 ;
signed long V_109 = V_596 ;
F_246 ( V_597 ) ;
V_100 ;
do {
V_595 = 0 ;
F_41 (hrrq, ioa_cfg) {
F_5 ( V_62 -> V_598 , V_117 ) ;
for ( V_18 = V_62 -> V_599 ; V_18 <= V_62 -> V_600 ; V_18 ++ ) {
V_2 = V_7 -> V_601 [ V_18 ] ;
if ( ! F_242 ( V_2 ) ) {
if ( F_245 ( V_2 , V_505 ) ) {
V_2 -> V_59 = & V_597 ;
V_595 ++ ;
}
}
}
F_6 ( V_62 -> V_598 , V_117 ) ;
}
if ( V_595 ) {
V_109 = F_247 ( & V_597 , V_109 ) ;
if ( ! V_109 ) {
V_595 = 0 ;
F_41 (hrrq, ioa_cfg) {
F_5 ( V_62 -> V_598 , V_117 ) ;
for ( V_18 = V_62 -> V_599 ; V_18 <= V_62 -> V_600 ; V_18 ++ ) {
V_2 = V_7 -> V_601 [ V_18 ] ;
if ( ! F_242 ( V_2 ) ) {
if ( F_245 ( V_2 , V_505 ) ) {
V_2 -> V_59 = NULL ;
V_595 ++ ;
}
}
}
F_6 ( V_62 -> V_598 , V_117 ) ;
}
if ( V_595 )
F_29 ( & V_7 -> V_77 -> V_82 , L_92 ) ;
V_105 ;
return V_595 ? V_602 : V_603 ;
}
}
} while ( V_595 );
V_105 ;
return V_603 ;
}
static int F_248 ( struct V_95 * V_604 )
{
struct V_6 * V_7 ;
unsigned long V_25 = 0 ;
int V_399 = V_603 ;
V_100 ;
V_7 = (struct V_6 * ) V_604 -> V_505 -> V_26 -> V_508 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( ! V_7 -> V_362 && ! V_7 -> V_62 [ V_66 ] . V_516 ) {
F_117 ( V_7 , V_357 ) ;
F_29 ( & V_7 -> V_77 -> V_82 ,
L_93 ) ;
if ( V_359 == V_7 -> V_360 )
V_7 -> V_360 = V_361 ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_62 [ V_66 ] . V_516 ) {
V_412 ;
V_399 = V_602 ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_105 ;
return V_399 ;
}
static int F_249 ( struct V_6 * V_7 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 ;
struct V_29 * V_13 ;
struct V_37 * V_14 ;
struct V_605 * V_20 ;
T_2 V_51 ;
V_100 ;
V_2 = F_19 ( V_7 ) ;
V_13 = & V_2 -> V_13 ;
V_14 = & V_13 -> V_14 ;
if ( V_2 -> V_7 -> V_16 ) {
V_20 = & V_2 -> V_18 . V_19 . V_20 ;
V_13 -> V_606 = F_250 ( sizeof( * V_13 ) ) ;
} else
V_20 = & V_13 -> V_22 . V_3 . V_22 . V_20 ;
V_13 -> V_24 = V_140 -> V_24 ;
V_14 -> V_129 = V_607 ;
V_14 -> V_15 [ 0 ] = V_608 ;
if ( F_209 ( V_140 ) ) {
V_14 -> V_15 [ 2 ] = V_609 ;
V_13 -> V_610 = F_250 ( sizeof( V_20 -> V_117 ) ) ;
V_20 -> V_117 |= V_611 ;
}
F_50 ( V_2 , F_118 , V_612 ) ;
V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
if ( F_209 ( V_140 ) && V_140 -> V_88 && V_51 != V_101 ) {
if ( V_2 -> V_7 -> V_16 )
memcpy ( & V_140 -> V_88 -> V_31 , & V_2 -> V_32 . V_34 . V_22 . V_45 ,
sizeof( struct V_613 ) ) ;
else
memcpy ( & V_140 -> V_88 -> V_31 , & V_2 -> V_32 . V_31 . V_22 . V_45 ,
sizeof( struct V_613 ) ) ;
}
V_105 ;
return F_251 ( V_51 ) ? - V_83 : 0 ;
}
static int F_252 ( struct V_614 * V_581 , unsigned int * V_615 ,
unsigned long V_616 )
{
struct V_87 * V_88 = V_581 -> V_89 -> V_90 ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_139 * V_140 ;
unsigned long V_25 = 0 ;
int V_399 = - V_567 , V_509 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
while ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
V_140 = V_88 -> V_140 ;
if ( V_140 ) {
V_399 = F_249 ( V_7 , V_140 ) ;
* V_615 = V_140 -> V_144 ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_509 = F_244 ( V_7 , V_140 , F_243 ) ;
if ( V_509 != V_603 ) {
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_117 ( V_7 , V_357 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
}
} else
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_105 ;
return V_399 ;
}
static int F_253 ( struct V_95 * V_53 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_139 * V_140 ;
struct V_578 * V_89 ;
int V_399 = 0 , V_18 ;
struct V_61 * V_62 ;
V_100 ;
V_7 = (struct V_6 * ) V_53 -> V_505 -> V_26 -> V_508 ;
V_140 = V_53 -> V_505 -> V_508 ;
if ( V_7 -> V_362 )
return V_602 ;
if ( V_7 -> V_62 [ V_66 ] . V_516 )
return V_602 ;
F_41 (hrrq, ioa_cfg) {
F_21 ( & V_62 -> V_70 ) ;
for ( V_18 = V_62 -> V_599 ; V_18 <= V_62 -> V_600 ; V_18 ++ ) {
V_2 = V_7 -> V_601 [ V_18 ] ;
if ( V_2 -> V_13 . V_24 == V_140 -> V_24 ) {
if ( ! V_2 -> V_54 )
continue;
if ( F_242 ( V_2 ) )
continue;
V_2 -> V_28 = F_36 ;
if ( ! ( V_2 -> V_54 -> V_117 & V_617 ) ) {
V_2 -> V_54 -> V_91 |= V_618 ;
V_2 -> V_54 -> V_117 |= V_617 ;
}
}
}
F_22 ( & V_62 -> V_70 ) ;
}
V_140 -> V_158 = 1 ;
F_254 ( V_619 , V_53 , L_94 ) ;
if ( F_209 ( V_140 ) && V_140 -> V_88 ) {
V_89 = V_140 -> V_88 -> V_89 ;
F_52 ( V_53 -> V_505 -> V_26 -> V_27 ) ;
F_255 ( V_89 ) ;
F_54 ( V_53 -> V_505 -> V_26 -> V_27 ) ;
} else
V_399 = F_249 ( V_7 , V_140 ) ;
V_140 -> V_158 = 0 ;
V_140 -> V_159 = 1 ;
V_105 ;
return V_399 ? V_602 : V_603 ;
}
static int F_256 ( struct V_95 * V_604 )
{
int V_399 ;
struct V_6 * V_7 ;
struct V_139 * V_140 ;
V_7 = (struct V_6 * ) V_604 -> V_505 -> V_26 -> V_508 ;
V_140 = V_604 -> V_505 -> V_508 ;
if ( ! V_140 )
return V_602 ;
F_54 ( V_604 -> V_505 -> V_26 -> V_27 ) ;
V_399 = F_253 ( V_604 ) ;
F_52 ( V_604 -> V_505 -> V_26 -> V_27 ) ;
if ( V_399 == V_603 ) {
if ( F_209 ( V_140 ) && V_140 -> V_88 )
V_399 = F_244 ( V_7 , V_140 , F_243 ) ;
else
V_399 = F_244 ( V_7 , V_604 -> V_505 , F_241 ) ;
}
return V_399 ;
}
static void F_257 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_139 * V_140 ;
V_100 ;
if ( ! V_7 -> V_16 )
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( V_140 -> V_24 == V_2 -> V_13 . V_24 ) {
F_112 ( V_7 -> V_26 , V_140 -> V_166 ) ;
break;
}
}
if ( V_2 -> V_58 -> V_58 )
V_2 -> V_58 -> V_58 = NULL ;
else
V_2 -> V_58 -> V_28 ( V_2 -> V_58 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
V_105 ;
}
static void F_258 ( struct V_1 * V_2 )
{
struct V_1 * V_363 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_37 * V_14 ;
unsigned long V_25 = 0 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_2 -> V_115 . V_28 || V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return;
}
F_71 ( V_619 , V_2 -> V_22 . V_160 , L_95 ) ;
V_363 = F_19 ( V_7 ) ;
V_2 -> V_58 = V_363 ;
V_363 -> V_58 = V_2 ;
V_363 -> V_13 . V_24 = V_2 -> V_13 . V_24 ;
V_14 = & V_363 -> V_13 . V_14 ;
V_14 -> V_129 = V_607 ;
V_14 -> V_15 [ 0 ] = V_608 ;
V_14 -> V_15 [ 2 ] = V_620 | V_621 ;
F_45 ( V_363 , F_257 , F_118 , V_612 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_105 ;
}
static int F_259 ( struct V_95 * V_53 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_139 * V_140 ;
struct V_37 * V_14 ;
T_2 V_51 , V_68 ;
int V_18 , V_622 = 0 ;
struct V_61 * V_62 ;
V_100 ;
V_7 = (struct V_6 * ) V_53 -> V_505 -> V_26 -> V_508 ;
V_140 = V_53 -> V_505 -> V_508 ;
if ( V_7 -> V_362 ||
V_7 -> V_62 [ V_66 ] . V_516 )
return V_602 ;
if ( ! V_140 )
return V_602 ;
V_68 = F_25 ( V_7 -> V_20 . V_75 ) ;
if ( ! F_260 ( V_140 ) )
return V_602 ;
F_41 (hrrq, ioa_cfg) {
F_21 ( & V_62 -> V_70 ) ;
for ( V_18 = V_62 -> V_599 ; V_18 <= V_62 -> V_600 ; V_18 ++ ) {
if ( V_7 -> V_601 [ V_18 ] -> V_53 == V_53 ) {
if ( ! F_242 ( V_7 -> V_601 [ V_18 ] ) ) {
V_622 = 1 ;
break;
}
}
}
F_22 ( & V_62 -> V_70 ) ;
}
if ( ! V_622 )
return V_603 ;
V_2 = F_19 ( V_7 ) ;
V_2 -> V_13 . V_24 = V_140 -> V_24 ;
V_14 = & V_2 -> V_13 . V_14 ;
V_14 -> V_129 = V_607 ;
V_14 -> V_15 [ 0 ] = V_623 ;
V_2 -> V_22 . V_160 = V_53 -> V_505 ;
F_254 ( V_619 , V_53 , L_96 ,
V_53 -> V_624 [ 0 ] ) ;
F_50 ( V_2 , F_258 , V_625 ) ;
V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
if ( V_51 == V_329 || V_51 == V_626 ) {
V_51 = 0 ;
V_412 ;
}
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
if ( ! F_240 ( V_140 ) )
V_140 -> V_154 = 1 ;
V_105 ;
return F_251 ( V_51 ) ? V_602 : V_603 ;
}
static int F_261 ( struct V_506 * V_507 , unsigned long V_627 )
{
unsigned long V_25 ;
struct V_6 * V_7 = (struct V_6 * ) V_507 -> V_508 ;
int V_399 = 0 ;
F_5 ( V_507 -> V_27 , V_25 ) ;
if ( V_7 -> V_62 [ V_66 ] . V_516 || V_7 -> V_494 )
V_399 = 1 ;
if ( ( V_627 / V_628 ) > ( V_7 -> V_629 * 2 ) )
V_399 = 1 ;
F_6 ( V_507 -> V_27 , V_25 ) ;
return V_399 ;
}
static int F_262 ( struct V_95 * V_53 )
{
unsigned long V_117 ;
int V_399 ;
struct V_6 * V_7 ;
V_100 ;
V_7 = (struct V_6 * ) V_53 -> V_505 -> V_26 -> V_508 ;
F_5 ( V_53 -> V_505 -> V_26 -> V_27 , V_117 ) ;
V_399 = F_259 ( V_53 ) ;
F_6 ( V_53 -> V_505 -> V_26 -> V_27 , V_117 ) ;
if ( V_399 == V_603 )
V_399 = F_244 ( V_7 , V_53 -> V_505 , F_241 ) ;
V_105 ;
return V_399 ;
}
static T_9 F_263 ( struct V_6 * V_7 ,
T_2 V_68 )
{
T_9 V_399 = V_630 ;
T_2 V_631 ;
V_631 = F_25 ( V_7 -> V_20 . V_632 ) ;
V_68 &= ~ V_631 ;
if ( ( V_68 & V_633 ) == 0 ) {
if ( V_7 -> V_16 ) {
V_631 = F_25 ( V_7 -> V_20 . V_634 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_75 ) & ~ V_631 ;
if ( V_68 & V_635 ) {
F_24 ( V_635 , V_7 -> V_20 . V_73 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_75 ) & ~ V_631 ;
F_18 ( & V_7 -> V_363 -> V_65 ) ;
F_43 ( & V_7 -> V_363 -> V_60 ) ;
F_264 ( V_7 -> V_363 ) ;
return V_630 ;
}
}
return V_636 ;
}
if ( V_68 & V_637 ) {
F_24 ( V_637 , V_7 -> V_20 . V_72 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_75 ) ;
F_18 ( & V_7 -> V_363 -> V_65 ) ;
F_43 ( & V_7 -> V_363 -> V_60 ) ;
F_264 ( V_7 -> V_363 ) ;
} else if ( ( V_68 & V_638 ) == V_68 ) {
if ( V_7 -> V_639 ) {
if ( V_640 && F_265 () )
F_29 ( & V_7 -> V_77 -> V_82 ,
L_97 , V_68 ) ;
F_24 ( V_638 , V_7 -> V_20 . V_74 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_641 ) ;
return V_636 ;
}
} else {
if ( V_68 & V_642 )
V_7 -> V_643 = 1 ;
else if ( V_68 & V_644 )
F_29 ( & V_7 -> V_77 -> V_82 ,
L_98 , V_68 ) ;
else
F_29 ( & V_7 -> V_77 -> V_82 ,
L_99 , V_68 ) ;
if ( V_359 == V_7 -> V_360 )
V_7 -> V_360 = V_361 ;
F_20 ( V_7 , ~ 0 ) ;
F_117 ( V_7 , V_364 ) ;
}
return V_399 ;
}
static void F_266 ( struct V_6 * V_7 , char * V_645 , T_10 V_646 )
{
V_7 -> V_229 ++ ;
F_29 ( & V_7 -> V_77 -> V_82 , L_100 , V_645 , V_646 ) ;
if ( V_359 == V_7 -> V_360 )
V_7 -> V_360 = V_361 ;
F_117 ( V_7 , V_364 ) ;
}
static int F_267 ( struct V_61 * V_647 , int V_648 ,
struct V_649 * V_650 )
{
T_2 V_51 ;
T_10 V_23 ;
struct V_1 * V_2 ;
struct V_6 * V_7 = V_647 -> V_7 ;
int V_651 = 0 ;
if ( ! V_647 -> V_71 )
return 0 ;
while ( ( F_77 ( * V_647 -> V_652 ) & V_653 ) ==
V_647 -> V_654 ) {
V_23 = ( F_77 ( * V_647 -> V_652 ) &
V_655 ) >>
V_656 ;
if ( F_115 ( V_23 > V_647 -> V_600 ||
V_23 < V_647 -> V_599 ) ) {
F_266 ( V_7 ,
L_101 ,
V_23 ) ;
break;
}
V_2 = V_7 -> V_601 [ V_23 ] ;
V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
F_1 ( V_2 , V_104 , V_51 ) ;
F_76 ( & V_2 -> V_65 , V_650 ) ;
if ( V_647 -> V_652 < V_647 -> V_657 ) {
V_647 -> V_652 ++ ;
} else {
V_647 -> V_652 = V_647 -> V_658 ;
V_647 -> V_654 ^= 1u ;
}
V_651 ++ ;
if ( V_648 > 0 && V_651 >= V_648 )
break;
}
return V_651 ;
}
static int V_523 ( struct V_659 * V_660 , int V_648 )
{
struct V_6 * V_7 ;
struct V_61 * V_62 ;
struct V_1 * V_2 , * V_99 ;
unsigned long V_94 ;
int V_661 ;
F_268 ( V_650 ) ;
V_62 = F_143 ( V_660 , struct V_61 , V_522 ) ;
V_7 = V_62 -> V_7 ;
F_5 ( V_62 -> V_598 , V_94 ) ;
V_661 = F_267 ( V_62 , V_648 , & V_650 ) ;
if ( V_661 < V_648 )
F_269 ( V_660 ) ;
F_6 ( V_62 -> V_598 , V_94 ) ;
F_42 (ipr_cmd, temp, &doneq, queue) {
F_18 ( & V_2 -> V_65 ) ;
F_43 ( & V_2 -> V_60 ) ;
V_2 -> F_12 ( V_2 ) ;
}
return V_661 ;
}
static T_9 F_270 ( int V_662 , void * V_663 )
{
struct V_61 * V_62 = (struct V_61 * ) V_663 ;
struct V_6 * V_7 = V_62 -> V_7 ;
unsigned long V_94 = 0 ;
T_2 V_68 = 0 ;
int V_651 = 0 ;
int V_664 = 0 ;
struct V_1 * V_2 , * V_99 ;
T_9 V_399 = V_636 ;
F_268 ( V_650 ) ;
F_5 ( V_62 -> V_598 , V_94 ) ;
if ( ! V_62 -> V_71 ) {
F_6 ( V_62 -> V_598 , V_94 ) ;
return V_636 ;
}
while ( 1 ) {
if ( F_267 ( V_62 , - 1 , & V_650 ) ) {
V_399 = V_630 ;
if ( ! V_7 -> V_639 )
break;
V_651 = 0 ;
do {
F_24 ( V_638 ,
V_7 -> V_20 . V_74 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_641 ) ;
} while ( V_68 & V_638 &&
V_651 ++ < V_665 );
} else if ( V_399 == V_636 && V_664 == 0 ) {
V_68 = F_25 ( V_7 -> V_20 . V_641 ) ;
V_664 ++ ;
} else if ( V_651 == V_665 &&
V_68 & V_638 ) {
F_266 ( V_7 ,
L_102 , V_651 ) ;
V_399 = V_630 ;
break;
} else
break;
}
if ( F_115 ( V_399 == V_636 ) )
V_399 = F_263 ( V_7 , V_68 ) ;
F_6 ( V_62 -> V_598 , V_94 ) ;
F_42 (ipr_cmd, temp, &doneq, queue) {
F_18 ( & V_2 -> V_65 ) ;
F_43 ( & V_2 -> V_60 ) ;
V_2 -> F_12 ( V_2 ) ;
}
return V_399 ;
}
static T_9 F_271 ( int V_662 , void * V_663 )
{
struct V_61 * V_62 = (struct V_61 * ) V_663 ;
struct V_6 * V_7 = V_62 -> V_7 ;
unsigned long V_94 = 0 ;
struct V_1 * V_2 , * V_99 ;
T_9 V_399 = V_636 ;
F_268 ( V_650 ) ;
F_5 ( V_62 -> V_598 , V_94 ) ;
if ( ! V_62 -> V_71 ) {
F_6 ( V_62 -> V_598 , V_94 ) ;
return V_636 ;
}
if ( V_7 -> V_518 && V_7 -> V_16 && V_7 -> V_521 > 1 ) {
if ( ( F_77 ( * V_62 -> V_652 ) & V_653 ) ==
V_62 -> V_654 ) {
F_272 ( & V_62 -> V_522 ) ;
F_6 ( V_62 -> V_598 , V_94 ) ;
return V_630 ;
}
} else {
if ( ( F_77 ( * V_62 -> V_652 ) & V_653 ) ==
V_62 -> V_654 )
if ( F_267 ( V_62 , - 1 , & V_650 ) )
V_399 = V_630 ;
}
F_6 ( V_62 -> V_598 , V_94 ) ;
F_42 (ipr_cmd, temp, &doneq, queue) {
F_18 ( & V_2 -> V_65 ) ;
F_43 ( & V_2 -> V_60 ) ;
V_2 -> F_12 ( V_2 ) ;
}
return V_399 ;
}
static int F_273 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
int V_18 , V_666 ;
struct V_531 * V_667 ;
T_2 V_268 ;
T_2 V_668 = 0 ;
struct V_95 * V_53 = V_2 -> V_53 ;
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_107 * V_44 = V_2 -> V_18 . V_44 ;
V_268 = F_274 ( V_53 ) ;
if ( ! V_268 )
return 0 ;
V_666 = F_275 ( V_53 ) ;
if ( V_666 < 0 ) {
if ( F_265 () )
F_29 ( & V_7 -> V_77 -> V_82 , L_103 ) ;
return - 1 ;
}
V_2 -> V_56 = V_666 ;
V_13 -> V_38 = F_10 ( V_268 ) ;
V_13 -> V_40 =
F_10 ( sizeof( struct V_107 ) * V_2 -> V_56 ) ;
if ( V_53 -> V_669 == V_543 ) {
V_668 = V_540 ;
V_13 -> V_14 . V_538 |= V_539 ;
} else if ( V_53 -> V_669 == V_670 )
V_668 = V_671 ;
F_276 (scsi_cmd, sg, ipr_cmd->dma_use_sg, i) {
V_44 [ V_18 ] . V_117 = F_10 ( V_668 ) ;
V_44 [ V_18 ] . V_119 = F_10 ( F_189 ( V_667 ) ) ;
V_44 [ V_18 ] . V_120 = F_8 ( F_190 ( V_667 ) ) ;
}
V_44 [ V_18 - 1 ] . V_117 |= F_10 ( V_541 ) ;
return 0 ;
}
static int F_277 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
int V_18 , V_666 ;
struct V_531 * V_667 ;
T_2 V_268 ;
T_2 V_668 = 0 ;
struct V_95 * V_53 = V_2 -> V_53 ;
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_118 * V_48 = V_2 -> V_18 . V_48 ;
V_268 = F_274 ( V_53 ) ;
if ( ! V_268 )
return 0 ;
V_666 = F_275 ( V_53 ) ;
if ( V_666 < 0 ) {
F_29 ( & V_7 -> V_77 -> V_82 , L_103 ) ;
return - 1 ;
}
V_2 -> V_56 = V_666 ;
if ( V_53 -> V_669 == V_543 ) {
V_668 = V_540 ;
V_13 -> V_14 . V_538 |= V_539 ;
V_13 -> V_38 = F_10 ( V_268 ) ;
V_13 -> V_40 =
F_10 ( sizeof( struct V_118 ) * V_2 -> V_56 ) ;
} else if ( V_53 -> V_669 == V_670 ) {
V_668 = V_671 ;
V_13 -> V_39 = F_10 ( V_268 ) ;
V_13 -> V_41 =
F_10 ( sizeof( struct V_118 ) * V_2 -> V_56 ) ;
}
if ( V_2 -> V_56 <= F_94 ( V_13 -> V_22 . V_3 . V_22 . V_48 ) ) {
V_48 = V_13 -> V_22 . V_3 . V_22 . V_48 ;
V_13 -> V_47 = F_10 ( ( V_2 -> V_35 ) +
F_9 ( struct V_29 , V_22 . V_3 ) ) ;
V_13 -> V_49 = V_13 -> V_47 ;
}
F_276 (scsi_cmd, sg, ipr_cmd->dma_use_sg, i) {
V_48 [ V_18 ] . V_121 =
F_10 ( V_668 | F_189 ( V_667 ) ) ;
V_48 [ V_18 ] . V_120 = F_10 ( F_190 ( V_667 ) ) ;
}
V_48 [ V_18 - 1 ] . V_121 |= F_10 ( V_541 ) ;
return 0 ;
}
static void F_278 ( struct V_1 * V_2 )
{
struct V_95 * V_53 = V_2 -> V_53 ;
struct V_139 * V_140 = V_53 -> V_505 -> V_508 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
if ( F_251 ( V_51 ) > 0 ) {
V_53 -> V_96 |= ( V_97 << 16 ) ;
F_254 ( V_619 , V_53 ,
L_104 , V_51 ) ;
} else {
memcpy ( V_53 -> V_55 , V_2 -> V_55 ,
V_672 ) ;
}
if ( V_140 ) {
if ( ! F_240 ( V_140 ) )
V_140 -> V_154 = 1 ;
V_140 -> V_155 = 0 ;
}
F_38 ( V_2 -> V_53 ) ;
V_53 -> V_98 ( V_53 ) ;
if ( V_2 -> V_59 )
F_34 ( V_2 -> V_59 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
}
static void F_279 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
unsigned long V_94 ;
F_5 ( & V_62 -> V_70 , V_94 ) ;
F_278 ( V_2 ) ;
F_6 ( & V_62 -> V_70 , V_94 ) ;
}
static void F_280 ( struct V_1 * V_2 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_30 * V_31 = & V_2 -> V_32 . V_31 ;
T_3 V_35 = V_2 -> V_35 ;
memset ( & V_13 -> V_14 , 0 , sizeof( struct V_37 ) ) ;
V_13 -> V_38 = 0 ;
V_13 -> V_39 = 0 ;
V_13 -> V_40 = 0 ;
V_13 -> V_41 = 0 ;
V_31 -> V_50 . V_51 = 0 ;
V_31 -> V_50 . V_52 = 0 ;
if ( V_2 -> V_7 -> V_16 )
V_13 -> V_22 . V_42 . V_43 =
F_8 ( V_35 + F_9 ( struct V_1 , V_18 . V_44 ) ) ;
else {
V_13 -> V_47 =
F_10 ( V_35 + F_9 ( struct V_1 , V_18 . V_48 ) ) ;
V_13 -> V_49 = V_13 -> V_47 ;
}
}
static void F_281 ( struct V_1 * V_2 )
{
struct V_37 * V_14 = & V_2 -> V_13 . V_14 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
if ( F_251 ( V_51 ) > 0 ) {
F_278 ( V_2 ) ;
return;
}
F_280 ( V_2 ) ;
V_14 -> V_129 = V_673 ;
V_14 -> V_15 [ 0 ] = V_674 ;
V_14 -> V_15 [ 4 ] = V_672 ;
V_14 -> V_538 |= V_675 ;
V_14 -> V_538 |= V_676 ;
V_14 -> V_109 = F_250 ( V_677 / V_628 ) ;
F_49 ( V_2 , V_2 -> V_678 ,
V_672 , V_122 ) ;
F_45 ( V_2 , F_279 , F_118 ,
V_677 * 2 ) ;
}
static void F_282 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
unsigned long V_94 ;
F_5 ( & V_62 -> V_70 , V_94 ) ;
F_281 ( V_2 ) ;
F_6 ( & V_62 -> V_70 , V_94 ) ;
}
static void F_283 ( struct V_1 * V_2 )
{
struct V_95 * V_53 = V_2 -> V_53 ;
struct V_139 * V_140 = V_53 -> V_505 -> V_508 ;
struct V_37 * V_14 ;
V_140 -> V_155 = 1 ;
F_280 ( V_2 ) ;
if ( ! V_53 -> V_505 -> V_679 ) {
F_281 ( V_2 ) ;
return;
}
V_14 = & V_2 -> V_13 . V_14 ;
V_14 -> V_129 = V_607 ;
V_14 -> V_15 [ 0 ] = V_623 ;
F_45 ( V_2 , F_282 , F_118 ,
V_625 ) ;
}
static void F_284 ( struct V_6 * V_7 ,
struct V_1 * V_2 , struct V_139 * V_140 )
{
int V_18 ;
T_10 V_119 ;
T_2 V_51 , V_328 ;
struct V_30 * V_31 = & V_2 -> V_32 . V_31 ;
T_4 * V_680 = ( T_4 * ) V_31 ;
int V_324 ;
V_51 = F_77 ( V_31 -> V_50 . V_51 ) & V_323 ;
V_328 = F_77 ( V_31 -> V_50 . V_328 ) & V_323 ;
if ( 0 == V_51 )
return;
if ( V_7 -> V_261 < V_262 )
return;
if ( V_51 == V_329 && V_328 )
V_324 = F_110 ( V_328 ) ;
else
V_324 = F_110 ( V_51 ) ;
if ( V_7 -> V_261 < V_681 ) {
if ( V_31 -> V_50 . V_102 != 0 )
return;
if ( ! F_260 ( V_140 ) )
return;
if ( V_322 [ V_324 ] . V_682 == 0 )
return;
}
F_285 ( V_7 , V_140 , L_47 , V_322 [ V_324 ] . error ) ;
V_119 = F_59 ( V_31 -> V_50 . V_683 ) ;
if ( V_7 -> V_16 && sizeof( struct V_33 ) < V_119 )
V_119 = sizeof( struct V_33 ) ;
else if ( ! V_7 -> V_16 && sizeof( struct V_30 ) < V_119 )
V_119 = sizeof( struct V_30 ) ;
F_83 ( L_105 ) ;
for ( V_18 = 0 ; V_18 < V_119 / 4 ; V_18 += 4 ) {
F_83 ( L_28 , V_18 * 4 ,
F_77 ( V_680 [ V_18 ] ) ,
F_77 ( V_680 [ V_18 + 1 ] ) ,
F_77 ( V_680 [ V_18 + 2 ] ) ,
F_77 ( V_680 [ V_18 + 3 ] ) ) ;
}
}
static void F_286 ( struct V_1 * V_2 )
{
T_2 V_684 ;
T_1 * V_685 = V_2 -> V_53 -> V_55 ;
struct V_139 * V_140 = V_2 -> V_53 -> V_505 -> V_508 ;
struct V_30 * V_31 = & V_2 -> V_32 . V_31 ;
T_2 V_51 = F_77 ( V_31 -> V_50 . V_51 ) ;
memset ( V_685 , 0 , V_672 ) ;
if ( V_51 >= V_686 )
return;
V_2 -> V_53 -> V_96 = V_687 ;
if ( F_232 ( V_140 ) &&
V_51 == V_688 &&
V_31 -> V_22 . V_689 . V_690 != 0 ) {
V_685 [ 0 ] = 0x72 ;
V_685 [ 1 ] = F_251 ( V_51 ) ;
V_685 [ 2 ] = F_287 ( V_51 ) ;
V_685 [ 3 ] = F_288 ( V_51 ) ;
V_685 [ 7 ] = 12 ;
V_685 [ 8 ] = 0 ;
V_685 [ 9 ] = 0x0A ;
V_685 [ 10 ] = 0x80 ;
V_684 = F_77 ( V_31 -> V_22 . V_689 . V_690 ) ;
V_685 [ 12 ] = ( V_684 & 0xff000000 ) >> 24 ;
V_685 [ 13 ] = ( V_684 & 0x00ff0000 ) >> 16 ;
V_685 [ 14 ] = ( V_684 & 0x0000ff00 ) >> 8 ;
V_685 [ 15 ] = V_684 & 0x000000ff ;
V_684 = F_77 ( V_31 -> V_22 . V_689 . V_691 ) ;
V_685 [ 16 ] = ( V_684 & 0xff000000 ) >> 24 ;
V_685 [ 17 ] = ( V_684 & 0x00ff0000 ) >> 16 ;
V_685 [ 18 ] = ( V_684 & 0x0000ff00 ) >> 8 ;
V_685 [ 19 ] = V_684 & 0x000000ff ;
} else {
V_685 [ 0 ] = 0x70 ;
V_685 [ 2 ] = F_251 ( V_51 ) ;
V_685 [ 12 ] = F_287 ( V_51 ) ;
V_685 [ 13 ] = F_288 ( V_51 ) ;
if ( ( F_251 ( V_51 ) == 0x05 ) &&
( F_77 ( V_31 -> V_50 . V_692 ) & V_693 ) ) {
V_685 [ 7 ] = 10 ;
if ( F_287 ( V_51 ) == 0x24 )
V_685 [ 15 ] = 0xC0 ;
else
V_685 [ 15 ] = 0x80 ;
V_685 [ 16 ] =
( ( V_694 &
F_77 ( V_31 -> V_50 . V_692 ) ) >> 8 ) & 0xff ;
V_685 [ 17 ] =
( V_694 &
F_77 ( V_31 -> V_50 . V_692 ) ) & 0xff ;
} else {
if ( V_51 == V_688 ) {
if ( F_232 ( V_140 ) )
V_684 = F_77 ( V_31 -> V_22 . V_689 . V_691 ) ;
else
V_684 = F_77 ( V_31 -> V_22 . V_695 . V_684 ) ;
V_685 [ 0 ] |= 0x80 ;
V_685 [ 3 ] = ( V_684 & 0xff000000 ) >> 24 ;
V_685 [ 4 ] = ( V_684 & 0x00ff0000 ) >> 16 ;
V_685 [ 5 ] = ( V_684 & 0x0000ff00 ) >> 8 ;
V_685 [ 6 ] = V_684 & 0x000000ff ;
}
V_685 [ 7 ] = 6 ;
}
}
}
static int F_289 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_32 . V_31 ;
struct V_33 * V_34 = & V_2 -> V_32 . V_34 ;
if ( ( F_77 ( V_31 -> V_50 . V_692 ) & V_696 ) == 0 )
return 0 ;
if ( V_2 -> V_7 -> V_16 )
memcpy ( V_2 -> V_53 -> V_55 , V_34 -> V_697 . V_111 ,
F_93 ( T_10 , F_59 ( V_34 -> V_697 . V_698 ) ,
V_672 ) ) ;
else
memcpy ( V_2 -> V_53 -> V_55 , V_31 -> V_697 . V_111 ,
F_93 ( T_10 , F_59 ( V_31 -> V_697 . V_698 ) ,
V_672 ) ) ;
return 1 ;
}
static void F_290 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_95 * V_53 = V_2 -> V_53 ;
struct V_139 * V_140 = V_53 -> V_505 -> V_508 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
T_2 V_699 = V_51 & V_323 ;
if ( ! V_140 ) {
F_37 ( V_2 ) ;
return;
}
if ( ! F_260 ( V_140 ) && V_699 != V_700 )
F_286 ( V_2 ) ;
F_284 ( V_7 , V_2 , V_140 ) ;
switch ( V_699 ) {
case V_205 :
if ( F_240 ( V_140 ) )
V_53 -> V_96 |= ( V_701 << 16 ) ;
else
V_53 -> V_96 |= ( V_702 << 16 ) ;
break;
case V_703 :
case V_704 :
V_53 -> V_96 |= ( V_705 << 16 ) ;
break;
case V_706 :
V_53 -> V_96 |= ( V_705 << 16 ) ;
if ( ! F_240 ( V_140 ) )
V_140 -> V_154 = 1 ;
break;
case V_626 :
if ( ! V_140 -> V_155 )
V_140 -> V_154 = 1 ;
V_53 -> V_96 |= ( V_702 << 16 ) ;
break;
case V_688 :
case V_707 :
if ( V_53 -> V_96 != V_687 )
V_53 -> V_96 |= ( V_708 << 16 ) ;
break;
case V_329 :
case V_330 :
if ( ! V_140 -> V_158 )
F_112 ( V_7 -> V_26 , V_53 -> V_505 -> V_577 ) ;
V_53 -> V_96 |= ( V_97 << 16 ) ;
if ( ! F_240 ( V_140 ) )
V_140 -> V_154 = 1 ;
break;
case V_700 :
V_53 -> V_96 |= F_291 ( V_51 ) ;
if ( F_291 ( V_51 ) == V_687 ) {
if ( ! F_289 ( V_2 ) ) {
if ( ! F_240 ( V_140 ) ) {
F_283 ( V_2 ) ;
return;
}
}
}
if ( ! F_240 ( V_140 ) )
V_140 -> V_154 = 1 ;
break;
case V_709 :
break;
case V_710 :
if ( V_140 -> V_568 ) {
V_140 -> V_568 = 0 ;
V_53 -> V_96 |= ( V_702 << 16 ) ;
} else
V_53 -> V_96 |= ( V_97 << 16 ) ;
break;
default:
if ( F_251 ( V_51 ) > V_711 )
V_53 -> V_96 |= ( V_97 << 16 ) ;
if ( ! F_232 ( V_140 ) && ! F_240 ( V_140 ) )
V_140 -> V_154 = 1 ;
break;
}
F_38 ( V_2 -> V_53 ) ;
V_53 -> V_98 ( V_53 ) ;
if ( V_2 -> V_59 )
F_34 ( V_2 -> V_59 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
}
static void F_292 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_95 * V_53 = V_2 -> V_53 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
unsigned long V_25 ;
F_293 ( V_53 , F_77 ( V_2 -> V_32 . V_31 . V_50 . V_52 ) ) ;
if ( F_15 ( F_251 ( V_51 ) == 0 ) ) {
F_38 ( V_53 ) ;
F_5 ( V_2 -> V_62 -> V_598 , V_25 ) ;
V_53 -> V_98 ( V_53 ) ;
if ( V_2 -> V_59 )
F_34 ( V_2 -> V_59 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
F_6 ( V_2 -> V_62 -> V_598 , V_25 ) ;
} else {
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_21 ( & V_2 -> V_62 -> V_70 ) ;
F_290 ( V_7 , V_2 ) ;
F_22 ( & V_2 -> V_62 -> V_70 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
}
static int F_294 ( struct V_506 * V_507 ,
struct V_95 * V_53 )
{
struct V_6 * V_7 ;
struct V_139 * V_140 ;
struct V_29 * V_13 ;
struct V_1 * V_2 ;
unsigned long V_94 , V_25 ;
int V_399 ;
struct V_61 * V_62 ;
int V_36 ;
V_7 = (struct V_6 * ) V_507 -> V_508 ;
V_53 -> V_96 = ( V_712 << 16 ) ;
V_140 = V_53 -> V_505 -> V_508 ;
if ( F_209 ( V_140 ) && V_140 -> V_88 ) {
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_399 = F_295 ( V_53 , V_140 -> V_88 -> V_89 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_399 ;
}
V_36 = F_55 ( V_7 ) ;
V_62 = & V_7 -> V_62 [ V_36 ] ;
F_5 ( V_62 -> V_598 , V_94 ) ;
if ( F_115 ( ! V_62 -> V_126 && ! V_62 -> V_516 && ! V_62 -> V_713 ) ) {
F_6 ( V_62 -> V_598 , V_94 ) ;
return V_714 ;
}
if ( F_115 ( V_62 -> V_516 || V_62 -> V_713 || ! V_140 ) ) {
F_6 ( V_62 -> V_598 , V_94 ) ;
goto V_715;
}
V_2 = F_14 ( V_62 ) ;
if ( V_2 == NULL ) {
F_6 ( V_62 -> V_598 , V_94 ) ;
return V_714 ;
}
F_6 ( V_62 -> V_598 , V_94 ) ;
F_11 ( V_2 , F_292 ) ;
V_13 = & V_2 -> V_13 ;
memcpy ( V_13 -> V_14 . V_15 , V_53 -> V_624 , V_53 -> V_716 ) ;
V_2 -> V_53 = V_53 ;
V_2 -> V_28 = F_39 ;
if ( F_260 ( V_140 ) ) {
if ( V_53 -> V_717 == 0 )
V_13 -> V_14 . V_538 |= V_676 ;
if ( V_140 -> V_159 ) {
V_140 -> V_159 = 0 ;
V_13 -> V_14 . V_718 |= V_719 ;
}
}
if ( F_260 ( V_140 ) || F_232 ( V_140 ) ) {
V_13 -> V_14 . V_538 |= V_720 ;
V_13 -> V_14 . V_718 |= V_721 ;
if ( V_53 -> V_117 & V_722 )
V_13 -> V_14 . V_718 |= V_723 ;
else
V_13 -> V_14 . V_718 |= V_724 ;
}
if ( V_53 -> V_624 [ 0 ] >= 0xC0 &&
( ! F_260 ( V_140 ) || V_53 -> V_624 [ 0 ] == V_725 ) ) {
V_13 -> V_14 . V_129 = V_607 ;
}
if ( V_140 -> V_568 && F_219 ( V_140 ) ) {
V_13 -> V_14 . V_129 = V_726 ;
if ( V_53 -> V_717 == 0 )
V_13 -> V_14 . V_538 |= V_676 ;
}
if ( V_7 -> V_16 )
V_399 = F_273 ( V_7 , V_2 ) ;
else
V_399 = F_277 ( V_7 , V_2 ) ;
F_5 ( V_62 -> V_598 , V_94 ) ;
if ( F_115 ( V_399 || ( ! V_62 -> V_126 && ! V_62 -> V_516 ) ) ) {
F_35 ( & V_2 -> V_65 , & V_62 -> V_63 ) ;
F_6 ( V_62 -> V_598 , V_94 ) ;
if ( ! V_399 )
F_38 ( V_53 ) ;
return V_714 ;
}
if ( F_115 ( V_62 -> V_516 ) ) {
F_35 ( & V_2 -> V_65 , & V_62 -> V_63 ) ;
F_6 ( V_62 -> V_598 , V_94 ) ;
F_38 ( V_53 ) ;
goto V_715;
}
V_13 -> V_24 = V_140 -> V_24 ;
if ( V_140 -> V_154 ) {
V_13 -> V_14 . V_538 |= V_727 ;
V_140 -> V_154 = 0 ;
}
F_35 ( & V_2 -> V_65 , & V_62 -> V_110 ) ;
F_1 ( V_2 , V_114 , F_296 ( V_140 ) ) ;
F_44 ( V_2 ) ;
F_6 ( V_62 -> V_598 , V_94 ) ;
return 0 ;
V_715:
F_5 ( V_62 -> V_598 , V_94 ) ;
memset ( V_53 -> V_55 , 0 , V_672 ) ;
V_53 -> V_96 = ( V_705 << 16 ) ;
V_53 -> V_98 ( V_53 ) ;
F_6 ( V_62 -> V_598 , V_94 ) ;
return 0 ;
}
static int F_297 ( struct V_487 * V_160 , int V_604 , void T_11 * V_728 )
{
struct V_139 * V_140 ;
V_140 = (struct V_139 * ) V_160 -> V_508 ;
if ( V_140 && F_209 ( V_140 ) ) {
if ( V_604 == V_729 )
return - V_730 ;
return F_298 ( V_140 -> V_88 -> V_89 , V_160 , V_604 , V_728 ) ;
}
return - V_520 ;
}
static const char * F_299 ( struct V_506 * V_26 )
{
static char V_188 [ 512 ] ;
struct V_6 * V_7 ;
unsigned long V_25 = 0 ;
V_7 = (struct V_6 * ) V_26 -> V_508 ;
F_5 ( V_26 -> V_27 , V_25 ) ;
sprintf ( V_188 , L_106 , V_7 -> type ) ;
F_6 ( V_26 -> V_27 , V_25 ) ;
return V_188 ;
}
static void F_300 ( struct V_578 * V_89 )
{
unsigned long V_117 ;
struct V_87 * V_88 = V_89 -> V_90 ;
struct V_139 * V_140 = V_88 -> V_140 ;
struct V_6 * V_7 = V_88 -> V_7 ;
int V_399 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
while ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
}
if ( ! V_7 -> V_62 [ V_66 ] . V_126 )
goto V_731;
V_399 = F_249 ( V_7 , V_140 ) ;
if ( V_399 ) {
V_89 -> V_581 . V_505 [ 0 ] . V_582 = V_583 ;
goto V_731;
}
V_89 -> V_581 . V_505 [ 0 ] . V_582 = V_140 -> V_144 ;
if ( V_89 -> V_581 . V_505 [ 0 ] . V_582 == V_149 )
V_89 -> V_581 . V_505 [ 0 ] . V_582 = V_583 ;
V_731:
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
V_105 ;
}
static void F_301 ( struct V_86 * V_54 )
{
struct V_87 * V_88 = V_54 -> V_89 -> V_90 ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
unsigned long V_117 ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
while ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
}
F_41 (hrrq, ioa_cfg) {
F_21 ( & V_62 -> V_70 ) ;
F_62 (ipr_cmd, &hrrq->hrrq_pending_q, queue) {
if ( V_2 -> V_54 == V_54 ) {
F_249 ( V_7 , V_88 -> V_140 ) ;
break;
}
}
F_22 ( & V_62 -> V_70 ) ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
}
static void F_302 ( struct V_605 * V_20 ,
struct V_732 * V_733 )
{
V_20 -> V_734 = V_733 -> V_734 ;
V_20 -> V_735 = V_733 -> V_735 ;
V_20 -> V_736 = V_733 -> V_736 ;
V_20 -> V_737 = V_733 -> V_737 ;
V_20 -> V_738 = V_733 -> V_738 ;
V_20 -> V_505 = V_733 -> V_505 ;
V_20 -> V_21 = V_733 -> V_21 ;
V_20 -> V_739 = V_733 -> V_739 ;
V_20 -> V_740 = V_733 -> V_740 ;
V_20 -> V_741 = V_733 -> V_741 ;
V_20 -> V_742 = V_733 -> V_742 ;
V_20 -> V_743 = V_733 -> V_743 ;
V_20 -> V_744 = V_733 -> V_744 ;
}
static void F_303 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_86 * V_54 = V_2 -> V_54 ;
struct V_87 * V_88 = V_54 -> V_89 -> V_90 ;
struct V_139 * V_140 = V_88 -> V_140 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
F_21 ( & V_2 -> V_62 -> V_70 ) ;
if ( V_2 -> V_7 -> V_16 )
memcpy ( & V_88 -> V_31 , & V_2 -> V_32 . V_34 . V_22 . V_45 ,
sizeof( struct V_613 ) ) ;
else
memcpy ( & V_88 -> V_31 , & V_2 -> V_32 . V_31 . V_22 . V_45 ,
sizeof( struct V_613 ) ) ;
F_284 ( V_7 , V_2 , V_140 ) ;
if ( F_77 ( V_2 -> V_32 . V_31 . V_50 . V_692 ) & V_745 )
F_304 ( V_7 -> V_26 , V_140 -> V_166 , V_140 -> V_172 ) ;
if ( F_251 ( V_51 ) > V_711 )
V_54 -> V_91 |= F_305 ( V_88 -> V_31 . V_46 ) ;
else
V_54 -> V_91 |= F_306 ( V_88 -> V_31 . V_46 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
F_22 ( & V_2 -> V_62 -> V_70 ) ;
F_33 ( V_54 ) ;
}
static void F_307 ( struct V_1 * V_2 ,
struct V_86 * V_54 )
{
T_2 V_668 = 0 ;
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_107 * V_44 = V_2 -> V_18 . V_19 . V_44 ;
struct V_107 * V_746 = NULL ;
int V_116 = V_54 -> V_747 ;
struct V_531 * V_667 ;
unsigned int V_748 ;
T_3 V_35 = V_2 -> V_35 ;
if ( V_116 == 0 )
return;
if ( V_54 -> V_749 == V_543 ) {
V_668 = V_540 ;
V_13 -> V_14 . V_538 |= V_539 ;
} else if ( V_54 -> V_749 == V_670 )
V_668 = V_671 ;
V_13 -> V_38 = F_10 ( V_116 ) ;
V_13 -> V_40 =
F_10 ( sizeof( struct V_107 ) * V_2 -> V_56 ) ;
V_13 -> V_22 . V_42 . V_43 =
F_8 ( V_35 + F_9 ( struct V_1 , V_18 . V_19 . V_44 ) ) ;
F_308 (qc->sg, sg, qc->n_elem, si) {
V_44 -> V_117 = F_10 ( V_668 ) ;
V_44 -> V_119 = F_10 ( F_189 ( V_667 ) ) ;
V_44 -> V_120 = F_8 ( F_190 ( V_667 ) ) ;
V_746 = V_44 ;
V_44 ++ ;
}
if ( F_15 ( V_746 ) )
V_746 -> V_117 |= F_10 ( V_541 ) ;
}
static void F_309 ( struct V_1 * V_2 ,
struct V_86 * V_54 )
{
T_2 V_668 = 0 ;
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_118 * V_48 = V_2 -> V_18 . V_48 ;
struct V_118 * V_750 = NULL ;
int V_116 = V_54 -> V_747 ;
struct V_531 * V_667 ;
unsigned int V_748 ;
if ( V_116 == 0 )
return;
if ( V_54 -> V_749 == V_543 ) {
V_668 = V_540 ;
V_13 -> V_14 . V_538 |= V_539 ;
V_13 -> V_38 = F_10 ( V_116 ) ;
V_13 -> V_40 =
F_10 ( sizeof( struct V_118 ) * V_2 -> V_56 ) ;
} else if ( V_54 -> V_749 == V_670 ) {
V_668 = V_671 ;
V_13 -> V_39 = F_10 ( V_116 ) ;
V_13 -> V_41 =
F_10 ( sizeof( struct V_118 ) * V_2 -> V_56 ) ;
}
F_308 (qc->sg, sg, qc->n_elem, si) {
V_48 -> V_121 = F_10 ( V_668 | F_189 ( V_667 ) ) ;
V_48 -> V_120 = F_10 ( F_190 ( V_667 ) ) ;
V_750 = V_48 ;
V_48 ++ ;
}
if ( F_15 ( V_750 ) )
V_750 -> V_121 |= F_10 ( V_541 ) ;
}
static int F_310 ( struct V_86 * V_54 )
{
struct V_578 * V_89 = V_54 -> V_89 ;
struct V_87 * V_88 = V_89 -> V_90 ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
int V_36 ;
V_36 = F_55 ( V_7 ) ;
V_62 = & V_7 -> V_62 [ V_36 ] ;
V_54 -> V_751 = NULL ;
F_21 ( & V_62 -> V_70 ) ;
if ( F_115 ( V_62 -> V_516 ) ) {
F_22 ( & V_62 -> V_70 ) ;
return 0 ;
}
if ( F_115 ( ! V_62 -> V_126 ) ) {
F_22 ( & V_62 -> V_70 ) ;
return V_752 ;
}
V_2 = F_14 ( V_62 ) ;
if ( V_2 == NULL ) {
F_22 ( & V_62 -> V_70 ) ;
return V_752 ;
}
V_54 -> V_751 = V_2 ;
F_22 ( & V_62 -> V_70 ) ;
return 0 ;
}
static unsigned int F_311 ( struct V_86 * V_54 )
{
struct V_578 * V_89 = V_54 -> V_89 ;
struct V_87 * V_88 = V_89 -> V_90 ;
struct V_139 * V_140 = V_88 -> V_140 ;
struct V_6 * V_7 = V_88 -> V_7 ;
struct V_1 * V_2 ;
struct V_29 * V_13 ;
struct V_605 * V_20 ;
if ( V_54 -> V_751 == NULL )
F_310 ( V_54 ) ;
V_2 = V_54 -> V_751 ;
if ( V_2 == NULL )
return V_753 ;
V_54 -> V_751 = NULL ;
F_21 ( & V_2 -> V_62 -> V_70 ) ;
if ( F_115 ( ! V_2 -> V_62 -> V_126 ||
V_2 -> V_62 -> V_516 ) ) {
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
F_22 ( & V_2 -> V_62 -> V_70 ) ;
return V_753 ;
}
F_11 ( V_2 , F_4 ) ;
V_13 = & V_2 -> V_13 ;
if ( V_7 -> V_16 ) {
V_20 = & V_2 -> V_18 . V_19 . V_20 ;
V_13 -> V_606 = F_250 ( sizeof( * V_13 ) ) ;
} else
V_20 = & V_13 -> V_22 . V_3 . V_22 . V_20 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_13 -> V_610 = F_250 ( sizeof( * V_20 ) ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_110 ) ;
V_2 -> V_54 = V_54 ;
V_2 -> V_28 = F_303 ;
V_2 -> V_13 . V_24 = V_140 -> V_24 ;
V_13 -> V_14 . V_129 = V_754 ;
V_13 -> V_14 . V_538 |= V_720 ;
V_13 -> V_14 . V_538 |= V_676 ;
V_2 -> V_56 = V_54 -> V_755 ;
if ( V_7 -> V_16 )
F_307 ( V_2 , V_54 ) ;
else
F_309 ( V_2 , V_54 ) ;
V_20 -> V_117 |= V_611 ;
F_302 ( V_20 , & V_54 -> V_733 ) ;
memcpy ( V_13 -> V_14 . V_15 , V_54 -> V_15 , V_756 ) ;
F_1 ( V_2 , V_114 , F_296 ( V_140 ) ) ;
switch ( V_54 -> V_733 . V_757 ) {
case V_758 :
case V_759 :
break;
case V_760 :
V_20 -> V_117 |= V_761 ;
break;
case V_762 :
case V_763 :
V_20 -> V_117 |= V_764 ;
break;
case V_765 :
V_20 -> V_117 |= V_764 ;
V_20 -> V_117 |= V_761 ;
break;
default:
F_312 ( 1 ) ;
F_22 ( & V_2 -> V_62 -> V_70 ) ;
return V_766 ;
}
F_44 ( V_2 ) ;
F_22 ( & V_2 -> V_62 -> V_70 ) ;
return 0 ;
}
static bool F_313 ( struct V_86 * V_54 )
{
struct V_87 * V_88 = V_54 -> V_89 -> V_90 ;
struct V_613 * V_767 = & V_88 -> V_31 ;
struct V_732 * V_733 = & V_54 -> V_768 ;
V_733 -> V_734 = V_767 -> error ;
V_733 -> V_735 = V_767 -> V_735 ;
V_733 -> V_736 = V_767 -> V_736 ;
V_733 -> V_737 = V_767 -> V_737 ;
V_733 -> V_738 = V_767 -> V_738 ;
V_733 -> V_505 = V_767 -> V_505 ;
V_733 -> V_21 = V_767 -> V_46 ;
V_733 -> V_740 = V_767 -> V_740 ;
V_733 -> V_741 = V_767 -> V_741 ;
V_733 -> V_742 = V_767 -> V_742 ;
V_733 -> V_743 = V_767 -> V_743 ;
return true ;
}
static int F_314 ( struct V_6 * V_7 )
{
int V_18 ;
if ( ( V_7 -> type == 0x5702 ) && ( V_7 -> V_77 -> V_769 < 4 ) ) {
for ( V_18 = 0 ; V_18 < F_94 ( V_770 ) ; V_18 ++ ) {
if ( F_315 ( V_770 [ V_18 ] ) )
return 1 ;
}
}
return 0 ;
}
static int F_316 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_18 ;
V_100 ;
if ( ! V_7 -> V_62 [ V_66 ] . V_713 ) {
V_412 ;
V_7 -> V_490 = 1 ;
F_75 ( & V_7 -> V_204 ) ;
}
V_7 -> V_362 = 0 ;
V_7 -> V_366 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_516 = 1 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
F_317 ( & V_7 -> V_514 ) ;
V_105 ;
return V_771 ;
}
static int F_318 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_139 * V_140 ;
int V_274 ;
V_100 ;
V_7 -> V_362 = 0 ;
for ( V_274 = 0 ; V_274 < V_7 -> V_69 ; V_274 ++ ) {
F_21 ( & V_7 -> V_62 [ V_274 ] . V_70 ) ;
V_7 -> V_62 [ V_274 ] . V_126 = 1 ;
F_22 ( & V_7 -> V_62 [ V_274 ] . V_70 ) ;
}
F_3 () ;
V_7 -> V_363 = NULL ;
V_7 -> V_772 |= V_773 ;
F_62 (res, &ioa_cfg->used_res_q, queue) {
if ( V_140 -> V_156 || V_140 -> V_157 ) {
V_412 ;
break;
}
}
F_75 ( & V_7 -> V_204 ) ;
for ( V_274 = 0 ; V_274 < V_774 ; V_274 ++ ) {
F_78 ( & V_7 -> V_125 [ V_274 ] -> V_65 ) ;
if ( V_274 < V_775 )
F_56 ( V_7 ,
V_358 ,
V_7 -> V_125 [ V_274 ] ) ;
else
F_56 ( V_7 ,
V_134 ,
V_7 -> V_125 [ V_274 ] ) ;
}
F_112 ( V_7 -> V_26 , V_776 ) ;
F_116 ( & V_7 -> V_77 -> V_82 , L_107 ) ;
V_7 -> V_366 = 0 ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
F_317 ( & V_7 -> V_514 ) ;
V_7 -> V_490 = 1 ;
F_75 ( & V_7 -> V_204 ) ;
V_105 ;
return V_771 ;
}
static void F_319 ( struct V_777 * V_778 ,
struct V_370 * V_213 )
{
memset ( V_778 , 0 , sizeof( struct V_777 ) ) ;
memcpy ( & V_778 -> V_213 , V_213 , sizeof( struct V_370 ) ) ;
V_778 -> V_779 = 1 ;
V_778 -> V_780 =
F_250 ( sizeof( struct V_777 ) ) ;
V_778 -> V_781 = 0 ;
}
static int F_320 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_777 * V_782 = & V_7 -> V_425 -> V_782 ;
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_139 * V_140 = V_2 -> V_22 . V_140 ;
V_2 -> V_783 = F_318 ;
F_321 (res, &ioa_cfg->used_res_q, queue) {
if ( ! F_322 ( V_140 ) )
continue;
V_2 -> V_22 . V_140 = V_140 ;
F_319 ( V_782 , & V_140 -> V_193 . V_213 ) ;
V_13 -> V_24 = F_10 ( V_128 ) ;
V_13 -> V_14 . V_538 |= V_539 ;
V_13 -> V_14 . V_129 = V_607 ;
V_13 -> V_14 . V_15 [ 0 ] = V_784 ;
V_13 -> V_14 . V_15 [ 1 ] = V_785 ;
V_13 -> V_14 . V_15 [ 7 ] = ( sizeof( struct V_777 ) >> 8 ) & 0xff ;
V_13 -> V_14 . V_15 [ 8 ] = sizeof( struct V_777 ) & 0xff ;
F_49 ( V_2 ,
V_7 -> V_786 +
F_9 ( struct V_787 , V_782 ) ,
sizeof( struct V_777 ) ,
V_788 ) ;
F_45 ( V_2 , F_264 , F_118 ,
V_789 ) ;
if ( ! V_7 -> V_16 )
V_2 -> V_783 = F_320 ;
V_105 ;
return V_771 ;
}
V_105 ;
return V_790 ;
}
static void * F_323 ( struct V_791 * V_792 ,
T_2 V_793 , T_2 V_116 )
{
struct V_794 * V_795 ;
T_2 V_796 ;
T_2 V_268 ;
if ( ! V_792 || ( V_792 -> V_50 . V_268 == 0 ) )
return NULL ;
V_268 = ( V_792 -> V_50 . V_268 + 1 ) - 4 - V_792 -> V_50 . V_797 ;
V_795 = (struct V_794 * )
( V_792 -> V_111 + V_792 -> V_50 . V_797 ) ;
while ( V_268 ) {
if ( F_324 ( V_795 ) == V_793 ) {
if ( V_795 -> V_796 >= ( V_116 - sizeof( struct V_794 ) ) )
return V_795 ;
break;
} else {
V_796 = ( sizeof( struct V_794 ) +
V_795 -> V_796 ) ;
V_268 -= V_796 ;
V_795 = (struct V_794 * )
( ( unsigned long ) V_795 + V_796 ) ;
}
}
return NULL ;
}
static void F_325 ( struct V_6 * V_7 ,
struct V_791 * V_792 )
{
int V_18 ;
int V_798 ;
struct V_799 * V_166 ;
struct V_800 * V_801 ;
V_801 = F_323 ( V_792 , 0x28 ,
sizeof( struct V_800 ) ) ;
V_798 = V_801 -> V_798 ;
V_166 = V_801 -> V_166 ;
for ( V_18 = 0 ; V_18 < V_801 -> V_246 ; V_18 ++ ) {
if ( V_166 -> V_117 & V_802 ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_108 ,
V_166 -> V_186 . V_166 ) ;
}
V_166 = (struct V_799 * ) ( ( char * ) V_166 + V_798 ) ;
}
}
static void F_326 ( struct V_6 * V_7 )
{
T_2 V_375 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_803 ; V_18 ++ ) {
V_375 = F_121 ( V_7 , V_18 ,
V_7 -> V_804 [ V_18 ] . V_374 ) ;
if ( V_375 < V_7 -> V_804 [ V_18 ] . V_375 )
V_7 -> V_804 [ V_18 ] . V_375 = V_375 ;
}
}
static void F_327 ( struct V_6 * V_7 ,
struct V_791 * V_792 )
{
int V_18 , V_798 ;
struct V_799 * V_166 ;
struct V_805 * V_804 ;
struct V_800 * V_801 ;
V_801 = F_323 ( V_792 , 0x28 ,
sizeof( struct V_800 ) ) ;
V_798 = V_801 -> V_798 ;
for ( V_18 = 0 , V_166 = V_801 -> V_166 ;
V_18 < V_801 -> V_246 ;
V_18 ++ , V_166 = (struct V_799 * ) ( ( T_1 * ) V_166 + V_798 ) ) {
if ( V_166 -> V_186 . V_166 > V_803 ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_109 ,
F_328 ( V_166 -> V_186 ) ) ;
continue;
}
V_804 = & V_7 -> V_804 [ V_18 ] ;
V_166 -> V_806 = V_807 ;
V_166 -> V_374 = V_804 -> V_374 ;
V_166 -> V_375 = F_10 ( V_804 -> V_375 ) ;
V_166 -> V_117 &= ~ V_808 ;
if ( V_804 -> V_809 )
V_166 -> V_117 |= V_810 ;
else
V_166 -> V_117 |= V_811 ;
}
}
static void F_329 ( struct V_1 * V_2 ,
T_4 V_24 , T_1 V_571 ,
T_3 V_35 , T_1 V_812 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_14 . V_129 = V_673 ;
V_13 -> V_14 . V_538 |= V_539 ;
V_13 -> V_14 . V_15 [ 0 ] = V_813 ;
V_13 -> V_14 . V_15 [ 1 ] = V_571 ;
V_13 -> V_14 . V_15 [ 4 ] = V_812 ;
F_49 ( V_2 , V_35 , V_812 , V_788 ) ;
}
static int F_330 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_791 * V_792 = & V_7 -> V_425 -> V_792 ;
int V_268 ;
V_100 ;
F_326 ( V_7 ) ;
F_325 ( V_7 , V_792 ) ;
F_327 ( V_7 , V_792 ) ;
V_268 = V_792 -> V_50 . V_268 + 1 ;
V_792 -> V_50 . V_268 = 0 ;
F_329 ( V_2 , F_10 ( V_128 ) , 0x11 ,
V_7 -> V_786 + F_9 ( struct V_787 , V_792 ) ,
V_268 ) ;
V_2 -> V_783 = F_320 ;
V_2 -> V_22 . V_140 = F_17 ( V_7 -> V_200 . V_64 ,
struct V_139 , V_65 ) ;
F_45 ( V_2 , F_264 , F_118 , V_814 ) ;
V_105 ;
return V_771 ;
}
static void F_331 ( struct V_1 * V_2 ,
T_4 V_24 ,
T_1 V_571 , T_3 V_35 , T_1 V_812 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_14 . V_15 [ 0 ] = V_815 ;
V_13 -> V_14 . V_15 [ 2 ] = V_571 ;
V_13 -> V_14 . V_15 [ 4 ] = V_812 ;
V_13 -> V_14 . V_129 = V_673 ;
F_49 ( V_2 , V_35 , V_812 , V_122 ) ;
}
static int F_332 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
F_29 ( & V_7 -> V_77 -> V_82 ,
L_110 ,
V_2 -> V_13 . V_14 . V_15 [ 0 ] , V_51 ) ;
F_117 ( V_7 , V_364 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
return V_771 ;
}
static int F_333 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
if ( V_51 == V_816 ) {
V_2 -> V_783 = F_320 ;
V_2 -> V_22 . V_140 = F_17 ( V_7 -> V_200 . V_64 ,
struct V_139 , V_65 ) ;
return V_790 ;
}
return F_332 ( V_2 ) ;
}
static int F_334 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
F_331 ( V_2 , F_10 ( V_128 ) ,
0x28 , V_7 -> V_786 +
F_9 ( struct V_787 , V_792 ) ,
sizeof( struct V_791 ) ) ;
V_2 -> V_783 = F_330 ;
V_2 -> V_817 = F_333 ;
F_45 ( V_2 , F_264 , F_118 , V_814 ) ;
V_105 ;
return V_771 ;
}
static int F_335 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_791 * V_792 = & V_7 -> V_425 -> V_792 ;
struct V_818 * V_801 ;
int V_268 ;
V_100 ;
V_801 = F_323 ( V_792 , 0x24 ,
sizeof( struct V_818 ) ) ;
if ( V_801 )
V_801 -> V_117 |= V_819 ;
V_268 = V_792 -> V_50 . V_268 + 1 ;
V_792 -> V_50 . V_268 = 0 ;
F_329 ( V_2 , F_10 ( V_128 ) , 0x11 ,
V_7 -> V_786 + F_9 ( struct V_787 , V_792 ) ,
V_268 ) ;
V_2 -> V_783 = F_334 ;
F_45 ( V_2 , F_264 , F_118 , V_814 ) ;
V_105 ;
return V_771 ;
}
static int F_336 ( struct V_1 * V_2 )
{
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
if ( V_51 == V_816 ) {
V_2 -> V_783 = F_334 ;
return V_790 ;
}
return F_332 ( V_2 ) ;
}
static int F_337 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
F_331 ( V_2 , F_10 ( V_128 ) ,
0x24 , V_7 -> V_786 +
F_9 ( struct V_787 , V_792 ) ,
sizeof( struct V_791 ) ) ;
V_2 -> V_783 = F_335 ;
V_2 -> V_817 = F_336 ;
F_45 ( V_2 , F_264 , F_118 , V_814 ) ;
V_105 ;
return V_771 ;
}
static int F_338 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_139 * V_140 , * V_99 ;
struct V_150 V_151 ;
int V_820 , V_152 , V_821 , V_18 ;
F_268 ( V_822 ) ;
V_100 ;
if ( V_7 -> V_16 )
V_821 = V_7 -> V_22 . V_823 -> V_824 . V_117 ;
else
V_821 = V_7 -> V_22 . V_825 -> V_50 . V_117 ;
if ( V_821 & V_826 )
F_29 ( & V_7 -> V_77 -> V_82 , L_111 ) ;
F_42 (res, temp, &ioa_cfg->used_res_q, queue)
F_76 ( & V_140 -> V_65 , & V_822 ) ;
if ( V_7 -> V_16 )
V_820 = F_59 ( V_7 -> V_22 . V_823 -> V_824 . V_246 ) ;
else
V_820 = V_7 -> V_22 . V_825 -> V_50 . V_246 ;
for ( V_18 = 0 ; V_18 < V_820 ; V_18 ++ ) {
if ( V_7 -> V_16 )
V_151 . V_22 . V_161 = & V_7 -> V_22 . V_823 -> V_82 [ V_18 ] ;
else
V_151 . V_22 . V_183 = & V_7 -> V_22 . V_825 -> V_82 [ V_18 ] ;
V_152 = 0 ;
F_42 (res, temp, &old_res, queue) {
if ( F_67 ( V_140 , & V_151 ) ) {
F_76 ( & V_140 -> V_65 , & V_7 -> V_200 ) ;
V_152 = 1 ;
break;
}
}
if ( ! V_152 ) {
if ( F_16 ( & V_7 -> V_199 ) ) {
F_29 ( & V_7 -> V_77 -> V_82 , L_112 ) ;
break;
}
V_152 = 1 ;
V_140 = F_17 ( V_7 -> V_199 . V_64 ,
struct V_139 , V_65 ) ;
F_76 ( & V_140 -> V_65 , & V_7 -> V_200 ) ;
F_58 ( V_140 , & V_151 ) ;
V_140 -> V_156 = 1 ;
} else if ( V_140 -> V_160 && ( F_232 ( V_140 ) || F_322 ( V_140 ) ) )
V_140 -> V_160 -> V_827 = 1 ;
if ( V_152 )
F_70 ( V_140 , & V_151 ) ;
}
F_42 (res, temp, &old_res, queue) {
if ( V_140 -> V_160 ) {
V_140 -> V_157 = 1 ;
V_140 -> V_24 = V_203 ;
F_76 ( & V_140 -> V_65 , & V_7 -> V_200 ) ;
}
}
F_42 (res, temp, &old_res, queue) {
F_72 ( V_140 ) ;
F_76 ( & V_140 -> V_65 , & V_7 -> V_199 ) ;
}
if ( V_7 -> V_828 && V_829 )
V_2 -> V_783 = F_337 ;
else
V_2 -> V_783 = F_334 ;
V_105 ;
return V_790 ;
}
static int F_339 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_423 * V_424 = & V_7 -> V_425 -> V_426 ;
struct V_830 * V_831 = & V_7 -> V_425 -> V_831 ;
V_100 ;
if ( V_831 -> V_831 & V_832 )
V_7 -> V_828 = 1 ;
F_116 ( & V_7 -> V_77 -> V_82 , L_113 ,
V_424 -> V_434 , V_424 -> V_435 ,
V_424 -> V_436 [ 0 ] , V_424 -> V_436 [ 1 ] ) ;
V_13 -> V_14 . V_129 = V_607 ;
V_13 -> V_24 = F_10 ( V_128 ) ;
V_13 -> V_14 . V_15 [ 0 ] = V_833 ;
V_13 -> V_14 . V_15 [ 6 ] = ( V_7 -> V_834 >> 16 ) & 0xff ;
V_13 -> V_14 . V_15 [ 7 ] = ( V_7 -> V_834 >> 8 ) & 0xff ;
V_13 -> V_14 . V_15 [ 8 ] = V_7 -> V_834 & 0xff ;
F_49 ( V_2 , V_7 -> V_835 , V_7 -> V_834 ,
V_122 ) ;
V_2 -> V_783 = F_338 ;
F_45 ( V_2 , F_264 , F_118 , V_814 ) ;
V_105 ;
return V_771 ;
}
static int F_340 ( struct V_1 * V_2 )
{
T_2 V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
if ( V_51 == V_816 )
return V_790 ;
return F_332 ( V_2 ) ;
}
static void F_341 ( struct V_1 * V_2 ,
T_4 V_24 , T_1 V_836 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
V_13 -> V_24 = V_24 ;
V_13 -> V_14 . V_15 [ 0 ] = V_837 ;
V_13 -> V_14 . V_15 [ 1 ] = V_836 ;
V_13 -> V_14 . V_129 = V_607 ;
}
static int F_342 ( struct V_1 * V_2 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_838 * V_839 = & V_7 -> V_425 -> V_840 ;
V_100 ;
V_2 -> V_783 = F_339 ;
if ( V_839 -> V_841 [ 0 ] & V_842 ) {
F_341 ( V_2 ,
F_10 ( V_128 ) ,
V_843 ) ;
V_13 -> V_14 . V_15 [ 2 ] = 0x40 ;
V_2 -> V_817 = F_340 ;
F_45 ( V_2 , F_264 , F_118 ,
V_789 ) ;
V_105 ;
return V_771 ;
}
V_105 ;
return V_790 ;
}
static void F_343 ( struct V_1 * V_2 , T_1 V_117 , T_1 V_403 ,
T_3 V_35 , T_1 V_812 )
{
struct V_29 * V_13 = & V_2 -> V_13 ;
V_100 ;
V_13 -> V_14 . V_129 = V_673 ;
V_13 -> V_24 = F_10 ( V_128 ) ;
V_13 -> V_14 . V_15 [ 0 ] = V_844 ;
V_13 -> V_14 . V_15 [ 1 ] = V_117 ;
V_13 -> V_14 . V_15 [ 2 ] = V_403 ;
V_13 -> V_14 . V_15 [ 4 ] = V_812 ;
F_49 ( V_2 , V_35 , V_812 , V_122 ) ;
F_45 ( V_2 , F_264 , F_118 , V_814 ) ;
V_105 ;
}
static int F_344 ( struct V_845 * V_846 , T_1 V_403 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_93 ( T_1 , V_846 -> V_116 , V_847 ) ; V_18 ++ )
if ( V_846 -> V_403 [ V_18 ] == V_403 )
return 1 ;
return 0 ;
}
static int F_345 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_845 * V_846 = & V_7 -> V_425 -> V_848 ;
struct V_838 * V_839 = & V_7 -> V_425 -> V_840 ;
V_100 ;
V_2 -> V_783 = F_342 ;
memset ( V_839 , 0 , sizeof( * V_839 ) ) ;
if ( F_344 ( V_846 , 0xC4 ) ) {
F_343 ( V_2 , 1 , 0xC4 ,
( V_7 -> V_786
+ F_9 ( struct V_787 ,
V_840 ) ) ,
sizeof( struct V_838 ) ) ;
return V_771 ;
}
V_105 ;
return V_790 ;
}
static int F_346 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_845 * V_846 = & V_7 -> V_425 -> V_848 ;
struct V_830 * V_831 = & V_7 -> V_425 -> V_831 ;
V_100 ;
V_2 -> V_783 = F_345 ;
memset ( V_831 , 0 , sizeof( * V_831 ) ) ;
if ( F_344 ( V_846 , 0xD0 ) ) {
F_343 ( V_2 , 1 , 0xD0 ,
V_7 -> V_786 + F_9 ( struct V_787 , V_831 ) ,
sizeof( struct V_830 ) ) ;
return V_771 ;
}
V_105 ;
return V_790 ;
}
static int F_347 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
V_2 -> V_783 = F_346 ;
F_343 ( V_2 , 1 , 3 ,
V_7 -> V_786 + F_9 ( struct V_787 , V_426 ) ,
sizeof( struct V_423 ) ) ;
V_105 ;
return V_771 ;
}
static int F_348 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
char type [ 5 ] ;
V_100 ;
memcpy ( type , V_7 -> V_425 -> V_222 . V_193 . V_213 . V_215 , 4 ) ;
type [ 4 ] = '\0' ;
V_7 -> type = F_163 ( ( char * ) type , NULL , 16 ) ;
if ( F_314 ( V_7 ) ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_114 ) ;
if ( ! V_849 ) {
V_7 -> V_366 += V_367 ;
F_117 ( V_7 , V_364 ) ;
F_35 ( & V_2 -> V_65 ,
& V_7 -> V_62 -> V_63 ) ;
return V_771 ;
}
}
V_2 -> V_783 = F_347 ;
F_343 ( V_2 , 1 , 0 ,
V_7 -> V_786 + F_9 ( struct V_787 , V_848 ) ,
sizeof( struct V_845 ) ) ;
V_105 ;
return V_771 ;
}
static int F_349 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
V_2 -> V_783 = F_348 ;
F_343 ( V_2 , 0 , 0 ,
V_7 -> V_786 + F_9 ( struct V_787 , V_222 ) ,
sizeof( struct V_850 ) ) ;
V_105 ;
return V_771 ;
}
static int F_350 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_29 * V_13 = & V_2 -> V_13 ;
struct V_61 * V_62 ;
V_100 ;
V_2 -> V_783 = F_349 ;
if ( V_7 -> V_851 == 0 )
F_116 ( & V_7 -> V_77 -> V_82 , L_115 ) ;
if ( V_7 -> V_851 < V_7 -> V_69 ) {
V_62 = & V_7 -> V_62 [ V_7 -> V_851 ] ;
V_13 -> V_14 . V_15 [ 0 ] = V_852 ;
V_13 -> V_24 = F_10 ( V_128 ) ;
V_13 -> V_14 . V_129 = V_607 ;
if ( V_7 -> V_16 )
V_13 -> V_14 . V_15 [ 1 ] = 0x1 ;
if ( V_7 -> V_521 == 1 )
V_13 -> V_14 . V_15 [ 1 ] &= ~ V_853 ;
else
V_13 -> V_14 . V_15 [ 1 ] |= V_853 ;
V_13 -> V_14 . V_15 [ 2 ] =
( ( V_854 ) V_62 -> V_855 >> 24 ) & 0xff ;
V_13 -> V_14 . V_15 [ 3 ] =
( ( V_854 ) V_62 -> V_855 >> 16 ) & 0xff ;
V_13 -> V_14 . V_15 [ 4 ] =
( ( V_854 ) V_62 -> V_855 >> 8 ) & 0xff ;
V_13 -> V_14 . V_15 [ 5 ] =
( ( V_854 ) V_62 -> V_855 ) & 0xff ;
V_13 -> V_14 . V_15 [ 7 ] =
( ( sizeof( T_2 ) * V_62 -> V_553 ) >> 8 ) & 0xff ;
V_13 -> V_14 . V_15 [ 8 ] =
( sizeof( T_2 ) * V_62 -> V_553 ) & 0xff ;
if ( V_13 -> V_14 . V_15 [ 1 ] & V_853 )
V_13 -> V_14 . V_15 [ 9 ] =
V_7 -> V_851 ;
if ( V_7 -> V_16 ) {
V_13 -> V_14 . V_15 [ 10 ] =
( ( V_854 ) V_62 -> V_855 >> 56 ) & 0xff ;
V_13 -> V_14 . V_15 [ 11 ] =
( ( V_854 ) V_62 -> V_855 >> 48 ) & 0xff ;
V_13 -> V_14 . V_15 [ 12 ] =
( ( V_854 ) V_62 -> V_855 >> 40 ) & 0xff ;
V_13 -> V_14 . V_15 [ 13 ] =
( ( V_854 ) V_62 -> V_855 >> 32 ) & 0xff ;
}
if ( V_13 -> V_14 . V_15 [ 1 ] & V_853 )
V_13 -> V_14 . V_15 [ 14 ] =
V_7 -> V_851 ;
F_45 ( V_2 , F_264 , F_118 ,
V_814 ) ;
if ( ++ V_7 -> V_851 < V_7 -> V_69 )
V_2 -> V_783 = F_350 ;
V_105 ;
return V_771 ;
}
V_105 ;
return V_790 ;
}
static void F_351 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_25 = 0 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_363 == V_2 ) {
F_18 ( & V_2 -> V_65 ) ;
V_2 -> V_28 ( V_2 ) ;
}
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
static void F_352 ( struct V_1 * V_2 ,
unsigned long V_109 )
{
V_100 ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_110 ) ;
V_2 -> V_28 = F_264 ;
V_2 -> V_60 . V_111 = ( unsigned long ) V_2 ;
V_2 -> V_60 . V_112 = V_11 + V_109 ;
V_2 -> V_60 . V_113 = ( void (*) ( unsigned long ) ) F_351 ;
F_47 ( & V_2 -> V_60 ) ;
}
static void F_353 ( struct V_6 * V_7 )
{
struct V_61 * V_62 ;
F_41 (hrrq, ioa_cfg) {
F_21 ( & V_62 -> V_70 ) ;
memset ( V_62 -> V_856 , 0 , sizeof( T_2 ) * V_62 -> V_553 ) ;
V_62 -> V_658 = V_62 -> V_856 ;
V_62 -> V_657 = & V_62 -> V_856 [ V_62 -> V_553 - 1 ] ;
V_62 -> V_652 = V_62 -> V_658 ;
V_62 -> V_654 = 1 ;
F_22 ( & V_62 -> V_70 ) ;
}
F_3 () ;
V_7 -> V_851 = 0 ;
if ( V_7 -> V_69 == 1 )
F_354 ( & V_7 -> V_123 , 0 ) ;
else
F_354 ( & V_7 -> V_123 , 1 ) ;
memset ( V_7 -> V_22 . V_825 , 0 , V_7 -> V_834 ) ;
}
static int F_355 ( struct V_1 * V_2 )
{
unsigned long V_857 , V_858 ;
T_2 V_859 ;
volatile T_2 V_68 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_854 V_860 = 0 ;
V_859 = F_25 ( V_7 -> V_20 . V_861 ) ;
V_857 = V_859 & V_862 ;
V_858 = V_859 & V_863 ;
F_356 ( L_116 , V_857 , V_858 ) ;
if ( V_858 == 0 )
V_858 = V_864 ;
else if ( V_858 < V_865 )
V_858 = V_865 ;
else if ( V_858 > V_866 )
V_858 = V_866 ;
if ( V_857 == V_867 ) {
F_24 ( V_635 , V_7 -> V_20 . V_72 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_634 ) ;
V_858 = V_7 -> V_629 ;
V_2 -> V_783 = F_350 ;
} else if ( V_857 == V_868 ) {
V_68 = F_25 ( V_7 -> V_20 . V_641 ) ;
if ( V_68 & V_637 ) {
V_2 -> V_783 = F_350 ;
V_860 = V_635 ;
V_860 = ( V_860 << 32 ) | V_637 ;
F_23 ( V_860 , V_7 -> V_20 . V_72 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_634 ) ;
return V_790 ;
}
}
V_2 -> V_60 . V_111 = ( unsigned long ) V_2 ;
V_2 -> V_60 . V_112 = V_11 + V_858 * V_628 ;
V_2 -> V_60 . V_113 = ( void (*) ( unsigned long ) ) F_119 ;
V_2 -> V_28 = F_264 ;
F_47 ( & V_2 -> V_60 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_110 ) ;
return V_771 ;
}
static int F_357 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
volatile T_2 V_68 ;
volatile V_854 V_860 ;
int V_18 ;
V_100 ;
V_2 -> V_783 = F_350 ;
F_353 ( V_7 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_71 = 1 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
if ( V_7 -> V_16 ) {
F_24 ( V_869 , V_7 -> V_20 . V_870 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_870 ) ;
}
V_68 = F_25 ( V_7 -> V_20 . V_641 ) ;
if ( V_68 & V_637 ) {
F_24 ( ( V_871 | V_638 ) ,
V_7 -> V_20 . V_872 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_634 ) ;
return V_790 ;
}
F_24 ( V_7 -> V_772 , V_7 -> V_20 . V_390 ) ;
if ( V_7 -> V_16 ) {
V_860 = V_635 ;
V_860 = ( V_860 << 32 ) | V_633 ;
F_23 ( V_860 , V_7 -> V_20 . V_873 ) ;
} else
F_24 ( V_633 , V_7 -> V_20 . V_872 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_634 ) ;
F_116 ( & V_7 -> V_77 -> V_82 , L_117 ) ;
if ( V_7 -> V_16 ) {
V_2 -> V_783 = F_355 ;
return V_790 ;
}
V_2 -> V_60 . V_111 = ( unsigned long ) V_2 ;
V_2 -> V_60 . V_112 = V_11 + ( V_7 -> V_629 * V_628 ) ;
V_2 -> V_60 . V_113 = ( void (*) ( unsigned long ) ) F_119 ;
V_2 -> V_28 = F_264 ;
F_47 ( & V_2 -> V_60 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_110 ) ;
V_105 ;
return V_771 ;
}
static int F_358 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_7 -> V_360 == V_361 )
V_7 -> V_360 = V_359 ;
else if ( V_7 -> V_360 == V_459 )
V_7 -> V_360 = V_414 ;
V_7 -> V_489 = 1 ;
V_2 -> V_783 = V_874 ;
return V_790 ;
}
static void F_359 ( struct V_6 * V_7 )
{
V_7 -> V_229 ++ ;
F_29 ( & V_7 -> V_77 -> V_82 , L_118 ) ;
}
static void F_360 ( struct V_6 * V_7 )
{
unsigned long V_875 ;
struct V_124 * V_125 ;
struct V_876 V_457 ;
int V_399 , V_268 ;
T_2 V_51 ;
V_875 = F_25 ( V_7 -> V_392 ) ;
if ( ! V_7 -> V_16 && ! F_141 ( V_875 ) ) {
F_359 ( V_7 ) ;
return;
}
memset ( & V_457 , 0 , sizeof( struct V_876 ) ) ;
V_399 = F_128 ( V_7 , V_875 , ( T_4 * ) & V_457 ,
( sizeof( struct V_876 ) ) / sizeof( T_4 ) ) ;
if ( V_399 || ! ( V_457 . V_470 [ 0 ] . V_117 & V_479 ) ||
( ( F_77 ( V_457 . V_50 . V_278 ) != V_472 ) &&
( F_77 ( V_457 . V_50 . V_278 ) != V_473 ) ) ) {
F_359 ( V_7 ) ;
return;
}
if ( F_77 ( V_457 . V_50 . V_278 ) == V_472 )
V_268 = F_77 ( V_457 . V_470 [ 0 ] . V_481 ) ;
else
V_268 = ( F_77 ( V_457 . V_470 [ 0 ] . V_481 ) -
F_77 ( V_457 . V_470 [ 0 ] . V_480 ) ) &
V_482 ;
V_125 = F_17 ( V_7 -> V_138 . V_64 ,
struct V_124 , V_65 ) ;
F_78 ( & V_125 -> V_65 ) ;
memset ( & V_125 -> V_132 , 0 , sizeof( V_125 -> V_132 ) ) ;
V_399 = F_128 ( V_7 ,
F_77 ( V_457 . V_470 [ 0 ] . V_480 ) ,
( T_4 * ) & V_125 -> V_132 ,
F_131 ( V_268 , ( int ) sizeof( V_125 -> V_132 ) ) / sizeof( T_4 ) ) ;
if ( ! V_399 ) {
F_111 ( V_7 , V_125 ) ;
V_51 = F_77 ( V_125 -> V_132 . V_22 . error . V_328 ) ;
if ( V_51 == V_356 &&
V_7 -> V_360 == V_361 )
V_7 -> V_360 = V_359 ;
} else
F_359 ( V_7 ) ;
F_35 ( & V_125 -> V_65 , & V_7 -> V_138 ) ;
}
static int F_361 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
V_7 -> V_643 = 0 ;
F_360 ( V_7 ) ;
V_2 -> V_783 = V_874 ;
F_352 ( V_2 , 0 ) ;
V_105 ;
return V_771 ;
}
static int F_362 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
if ( V_7 -> V_360 != V_361 )
return V_771 ;
if ( ! V_7 -> V_16 || ! V_2 -> V_22 . V_877 ||
( F_25 ( V_7 -> V_20 . V_75 ) &
V_878 ) ) {
if ( ! V_2 -> V_22 . V_877 )
F_29 ( & V_7 -> V_77 -> V_82 ,
L_119 ) ;
V_7 -> V_360 = V_459 ;
V_7 -> V_489 = 0 ;
if ( V_7 -> V_16 )
F_352 ( V_2 , V_879 ) ;
else
F_352 ( V_2 , V_880 ) ;
V_2 -> V_783 = F_358 ;
F_75 ( & V_7 -> V_204 ) ;
} else {
V_2 -> V_22 . V_877 -= V_881 ;
F_352 ( V_2 ,
V_881 ) ;
}
V_105 ;
return V_771 ;
}
static int F_363 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 V_68 ;
V_100 ;
V_7 -> V_77 -> V_882 = true ;
F_364 ( V_7 -> V_77 ) ;
if ( F_30 ( V_7 ) ) {
V_2 -> V_32 . V_31 . V_50 . V_51 = F_10 ( V_883 ) ;
return V_790 ;
}
F_40 ( V_7 ) ;
if ( V_7 -> V_16 ) {
F_24 ( V_869 , V_7 -> V_20 . V_870 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_870 ) ;
}
if ( V_7 -> V_643 ) {
if ( V_7 -> V_16 ) {
V_2 -> V_783 = F_361 ;
F_352 ( V_2 , V_884 ) ;
return V_771 ;
} else {
V_7 -> V_643 = 0 ;
F_360 ( V_7 ) ;
V_2 -> V_783 = V_874 ;
F_352 ( V_2 , 0 ) ;
return V_771 ;
}
}
if ( V_7 -> V_517 ) {
V_2 -> V_783 = F_316 ;
} else if ( V_7 -> V_360 == V_361 ) {
V_2 -> V_783 = F_362 ;
V_2 -> V_22 . V_877 = V_885 ;
} else {
V_2 -> V_783 = F_357 ;
}
V_105 ;
return V_790 ;
}
static int F_365 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
if ( V_7 -> V_886 )
F_366 ( V_7 -> V_77 ) ;
V_7 -> V_886 = 0 ;
V_2 -> V_783 = F_363 ;
V_105 ;
return V_790 ;
}
static int F_367 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_399 = V_81 ;
V_100 ;
if ( V_7 -> V_887 -> V_888 == V_889 )
F_24 ( V_890 ,
V_7 -> V_20 . V_390 ) ;
else
V_399 = F_368 ( V_7 -> V_77 , V_891 , V_892 ) ;
if ( V_399 == V_81 ) {
V_2 -> V_783 = F_365 ;
F_352 ( V_2 , V_893 ) ;
V_399 = V_771 ;
} else {
if ( V_7 -> V_886 )
F_366 ( V_2 -> V_7 -> V_77 ) ;
V_7 -> V_886 = 0 ;
V_2 -> V_32 . V_31 . V_50 . V_51 = F_10 ( V_883 ) ;
V_399 = V_790 ;
}
V_105 ;
return V_399 ;
}
static int F_369 ( struct V_1 * V_2 )
{
V_100 ;
V_2 -> V_783 = F_365 ;
F_352 ( V_2 , V_893 ) ;
V_105 ;
return V_771 ;
}
static void F_370 ( struct V_485 * V_486 )
{
struct V_1 * V_2 = F_143 ( V_486 , struct V_1 , V_486 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_894 * V_77 = V_7 -> V_77 ;
unsigned long V_25 = 0 ;
V_100 ;
F_371 ( V_77 , V_895 ) ;
F_167 ( F_372 ( V_896 ) ) ;
F_371 ( V_77 , V_897 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_363 == V_2 )
F_264 ( V_2 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_105 ;
}
static int F_373 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
F_374 ( & V_2 -> V_486 , F_370 ) ;
F_375 ( V_7 -> V_898 , & V_2 -> V_486 ) ;
V_2 -> V_783 = F_369 ;
V_105 ;
return V_771 ;
}
static int F_376 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_399 = V_790 ;
if ( F_377 ( V_7 -> V_77 ) ) {
V_7 -> V_886 = 1 ;
V_2 -> V_783 = V_7 -> V_899 ;
} else {
if ( V_2 -> V_22 . V_877 ) {
V_399 = V_771 ;
V_2 -> V_22 . V_877 -= V_881 ;
F_352 ( V_2 ,
V_881 ) ;
} else {
V_2 -> V_783 = V_7 -> V_899 ;
F_29 ( & V_7 -> V_77 -> V_82 ,
L_120 ) ;
}
}
return V_399 ;
}
static int F_378 ( struct V_1 * V_2 )
{
V_2 -> V_7 -> V_886 = 0 ;
V_2 -> V_783 = F_376 ;
V_2 -> V_22 . V_877 = V_900 ;
return V_790 ;
}
static int F_379 ( struct V_6 * V_7 )
{
volatile T_2 V_901 ;
V_901 = F_25 ( V_7 -> V_20 . V_75 ) ;
return ( ( V_901 & V_902 ) == 0 ) ;
}
static int F_380 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_399 = V_771 ;
if ( ! F_379 ( V_7 ) && V_2 -> V_22 . V_877 ) {
V_2 -> V_22 . V_877 -= V_881 ;
F_352 ( V_2 , V_881 ) ;
} else {
V_2 -> V_783 = F_378 ;
V_399 = V_790 ;
}
return V_399 ;
}
static int V_874 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_10 V_903 ;
int V_399 ;
V_100 ;
V_399 = F_28 ( V_7 -> V_77 , V_904 , & V_903 ) ;
if ( ( V_399 == V_81 ) && ( V_903 & V_905 ) ) {
F_20 ( V_7 , ~ 0 ) ;
F_24 ( V_388 , V_7 -> V_20 . V_390 ) ;
V_2 -> V_783 = F_380 ;
} else {
V_2 -> V_783 = F_378 ;
}
V_2 -> V_22 . V_877 = V_900 ;
F_352 ( V_2 , V_881 ) ;
V_105 ;
return V_771 ;
}
static int F_381 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
V_100 ;
V_2 -> V_783 = F_316 ;
F_20 ( V_7 , ~ V_637 ) ;
V_105 ;
return V_790 ;
}
static int F_382 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_1 * V_593 ;
struct V_61 * V_62 ;
int V_399 = V_790 ;
int V_504 = 0 ;
V_100 ;
V_2 -> V_783 = F_381 ;
F_41 (hrrq, ioa_cfg) {
F_21 ( & V_62 -> V_70 ) ;
F_62 (loop_cmd, &hrrq->hrrq_pending_q, queue) {
V_504 ++ ;
F_117 ( V_7 , V_364 ) ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
V_399 = V_771 ;
break;
}
F_22 ( & V_62 -> V_70 ) ;
if ( V_504 )
break;
}
V_105 ;
return V_399 ;
}
static int F_383 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_399 = V_790 ;
struct V_37 * V_14 ;
struct V_1 * V_906 ;
struct V_61 * V_62 = & V_7 -> V_62 [ V_66 ] ;
V_100 ;
V_2 -> V_783 = F_382 ;
if ( ! V_62 -> V_516 ) {
if ( ! F_16 ( & V_7 -> V_127 ) ) {
F_62 (hcam_cmd, &hrrq->hrrq_pending_q, queue) {
if ( V_906 -> V_13 . V_14 . V_15 [ 0 ] != V_131 )
continue;
V_2 -> V_13 . V_24 = F_10 ( V_128 ) ;
V_2 -> V_13 . V_14 . V_129 = V_607 ;
V_14 = & V_2 -> V_13 . V_14 ;
V_14 -> V_129 = V_607 ;
V_14 -> V_15 [ 0 ] = V_907 ;
V_14 -> V_15 [ 1 ] = V_908 ;
V_14 -> V_15 [ 10 ] = ( ( V_854 ) V_906 -> V_35 >> 56 ) & 0xff ;
V_14 -> V_15 [ 11 ] = ( ( V_854 ) V_906 -> V_35 >> 48 ) & 0xff ;
V_14 -> V_15 [ 12 ] = ( ( V_854 ) V_906 -> V_35 >> 40 ) & 0xff ;
V_14 -> V_15 [ 13 ] = ( ( V_854 ) V_906 -> V_35 >> 32 ) & 0xff ;
V_14 -> V_15 [ 2 ] = ( ( V_854 ) V_906 -> V_35 >> 24 ) & 0xff ;
V_14 -> V_15 [ 3 ] = ( ( V_854 ) V_906 -> V_35 >> 16 ) & 0xff ;
V_14 -> V_15 [ 4 ] = ( ( V_854 ) V_906 -> V_35 >> 8 ) & 0xff ;
V_14 -> V_15 [ 5 ] = ( ( V_854 ) V_906 -> V_35 ) & 0xff ;
F_45 ( V_2 , F_264 , F_118 ,
V_909 ) ;
V_399 = V_771 ;
V_2 -> V_783 = F_383 ;
break;
}
}
} else
V_2 -> V_783 = V_874 ;
V_105 ;
return V_399 ;
}
static int F_384 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_524 * V_530 = V_7 -> V_542 ;
F_385 ( & V_7 -> V_77 -> V_82 , V_530 -> V_531 ,
V_530 -> V_534 , V_543 ) ;
V_2 -> V_783 = V_874 ;
return V_790 ;
}
static int F_386 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_524 * V_530 = V_7 -> V_542 ;
V_100 ;
V_2 -> V_783 = V_874 ;
if ( ! V_530 )
return V_790 ;
V_2 -> V_13 . V_24 = F_10 ( V_128 ) ;
V_2 -> V_13 . V_14 . V_129 = V_673 ;
V_2 -> V_13 . V_14 . V_15 [ 0 ] = V_910 ;
V_2 -> V_13 . V_14 . V_15 [ 1 ] = V_911 ;
V_2 -> V_13 . V_14 . V_15 [ 6 ] = ( V_530 -> V_536 & 0xff0000 ) >> 16 ;
V_2 -> V_13 . V_14 . V_15 [ 7 ] = ( V_530 -> V_536 & 0x00ff00 ) >> 8 ;
V_2 -> V_13 . V_14 . V_15 [ 8 ] = V_530 -> V_536 & 0x0000ff ;
if ( V_7 -> V_16 )
F_188 ( V_2 , V_530 ) ;
else
F_191 ( V_2 , V_530 ) ;
V_2 -> V_783 = F_384 ;
F_45 ( V_2 , F_264 , F_118 ,
V_912 ) ;
V_105 ;
return V_771 ;
}
static int F_387 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
enum V_913 V_914 = V_2 -> V_22 . V_914 ;
unsigned long V_109 ;
int V_399 = V_790 ;
V_100 ;
if ( V_914 == V_915 )
V_2 -> V_783 = F_383 ;
else if ( V_914 != V_364 &&
! V_7 -> V_62 [ V_66 ] . V_516 ) {
V_2 -> V_13 . V_24 = F_10 ( V_128 ) ;
V_2 -> V_13 . V_14 . V_129 = V_607 ;
V_2 -> V_13 . V_14 . V_15 [ 0 ] = V_916 ;
V_2 -> V_13 . V_14 . V_15 [ 1 ] = V_914 ;
if ( V_914 == V_515 )
V_109 = V_917 ;
else if ( V_914 == V_918 )
V_109 = V_814 ;
else if ( V_7 -> V_828 && V_829 )
V_109 = V_919 ;
else
V_109 = V_920 ;
F_45 ( V_2 , F_264 , F_118 , V_109 ) ;
V_399 = V_771 ;
V_2 -> V_783 = F_386 ;
} else
V_2 -> V_783 = V_874 ;
V_105 ;
return V_399 ;
}
static void F_264 ( struct V_1 * V_2 )
{
T_2 V_399 , V_51 ;
struct V_6 * V_7 = V_2 -> V_7 ;
do {
V_51 = F_77 ( V_2 -> V_32 . V_31 . V_50 . V_51 ) ;
if ( V_7 -> V_363 != V_2 ) {
F_35 ( & V_2 -> V_65 ,
& V_2 -> V_62 -> V_63 ) ;
return;
}
if ( F_251 ( V_51 ) ) {
V_399 = V_2 -> V_817 ( V_2 ) ;
if ( V_399 == V_771 )
return;
}
F_7 ( V_2 ) ;
V_2 -> V_817 = F_332 ;
V_399 = V_2 -> V_783 ( V_2 ) ;
} while ( V_399 == V_790 );
}
static void F_388 ( struct V_6 * V_7 ,
int (* V_783) ( struct V_1 * ) ,
enum V_913 V_914 )
{
struct V_1 * V_2 ;
int V_18 ;
V_7 -> V_362 = 1 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_126 = 0 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
if ( ! V_7 -> V_62 [ V_66 ] . V_713 ) {
V_7 -> V_490 = 0 ;
V_7 -> V_491 = 1 ;
F_151 ( V_7 -> V_26 ) ;
}
V_2 = F_19 ( V_7 ) ;
V_7 -> V_363 = V_2 ;
V_2 -> V_783 = V_783 ;
V_2 -> V_22 . V_914 = V_914 ;
F_264 ( V_2 ) ;
}
static void F_117 ( struct V_6 * V_7 ,
enum V_913 V_914 )
{
int V_18 ;
if ( V_7 -> V_62 [ V_66 ] . V_516 )
return;
if ( V_7 -> V_362 ) {
if ( V_7 -> V_360 == V_361 )
V_7 -> V_360 = V_359 ;
else if ( V_7 -> V_360 == V_459 )
V_7 -> V_360 = V_414 ;
}
if ( V_7 -> V_366 ++ >= V_367 ) {
F_29 ( & V_7 -> V_77 -> V_82 ,
L_121 ) ;
V_7 -> V_366 = 0 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_516 = 1 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
if ( V_7 -> V_517 ) {
V_7 -> V_363 = NULL ;
V_7 -> V_362 = 0 ;
F_40 ( V_7 ) ;
F_317 ( & V_7 -> V_514 ) ;
if ( ! V_7 -> V_62 [ V_66 ] . V_713 ) {
V_7 -> V_490 = 1 ;
F_75 ( & V_7 -> V_204 ) ;
}
return;
} else {
V_7 -> V_517 = 1 ;
V_914 = V_364 ;
}
}
F_388 ( V_7 , F_387 ,
V_914 ) ;
}
static int F_389 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_71 = 0 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_110 ) ;
V_2 -> V_28 = F_264 ;
return V_771 ;
}
static T_12 F_390 ( struct V_894 * V_77 )
{
unsigned long V_117 = 0 ;
struct V_6 * V_7 = F_391 ( V_77 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
if ( ! V_7 -> V_921 )
F_392 ( V_77 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
return V_922 ;
}
static void F_393 ( struct V_894 * V_77 )
{
unsigned long V_117 = 0 ;
struct V_6 * V_7 = F_391 ( V_77 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
if ( V_7 -> V_921 )
F_388 ( V_7 , F_389 , V_364 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
}
static T_12 F_394 ( struct V_894 * V_77 )
{
unsigned long V_117 = 0 ;
struct V_6 * V_7 = F_391 ( V_77 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
if ( V_7 -> V_921 ) {
if ( V_7 -> V_923 )
F_117 ( V_7 , V_364 ) ;
else
F_388 ( V_7 , F_363 ,
V_364 ) ;
} else
F_317 ( & V_7 -> V_924 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
return V_925 ;
}
static void F_395 ( struct V_894 * V_77 )
{
unsigned long V_117 = 0 ;
struct V_6 * V_7 = F_391 ( V_77 ) ;
int V_18 ;
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
if ( V_7 -> V_921 ) {
if ( V_7 -> V_360 == V_359 )
V_7 -> V_360 = V_414 ;
V_7 -> V_366 = V_367 - 1 ;
V_7 -> V_517 = 1 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_126 = 0 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
F_117 ( V_7 , V_364 ) ;
} else
F_317 ( & V_7 -> V_924 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
}
static T_12 F_396 ( struct V_894 * V_77 ,
T_13 V_278 )
{
switch ( V_278 ) {
case V_926 :
F_393 ( V_77 ) ;
return V_927 ;
case V_928 :
F_395 ( V_77 ) ;
return V_929 ;
break;
default:
break;
}
return V_922 ;
}
static int F_397 ( struct V_6 * V_7 )
{
int V_399 = 0 ;
unsigned long V_930 = 0 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_930 ) ;
F_398 ( & V_7 -> V_77 -> V_82 , L_122 , V_7 ) ;
V_7 -> V_921 = 1 ;
if ( V_7 -> V_931 ) {
V_7 -> V_931 = 0 ;
F_117 ( V_7 , V_364 ) ;
} else
F_388 ( V_7 , F_357 ,
V_364 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_930 ) ;
V_105 ;
return V_399 ;
}
static void F_399 ( struct V_6 * V_7 )
{
int V_18 ;
if ( V_7 -> V_601 ) {
for ( V_18 = 0 ; V_18 < V_932 ; V_18 ++ ) {
if ( V_7 -> V_601 [ V_18 ] )
F_400 ( V_7 -> V_933 ,
V_7 -> V_601 [ V_18 ] ,
V_7 -> V_934 [ V_18 ] ) ;
V_7 -> V_601 [ V_18 ] = NULL ;
}
}
if ( V_7 -> V_933 )
F_401 ( V_7 -> V_933 ) ;
F_146 ( V_7 -> V_601 ) ;
F_146 ( V_7 -> V_934 ) ;
V_7 -> V_601 = NULL ;
V_7 -> V_934 = NULL ;
V_7 -> V_933 = NULL ;
}
static void F_402 ( struct V_6 * V_7 )
{
int V_18 ;
F_146 ( V_7 -> V_935 ) ;
F_403 ( & V_7 -> V_77 -> V_82 , sizeof( struct V_787 ) ,
V_7 -> V_425 , V_7 -> V_786 ) ;
F_399 ( V_7 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ )
F_403 ( & V_7 -> V_77 -> V_82 ,
sizeof( T_2 ) * V_7 -> V_62 [ V_18 ] . V_553 ,
V_7 -> V_62 [ V_18 ] . V_856 ,
V_7 -> V_62 [ V_18 ] . V_855 ) ;
F_403 ( & V_7 -> V_77 -> V_82 , V_7 -> V_834 ,
V_7 -> V_22 . V_825 , V_7 -> V_835 ) ;
for ( V_18 = 0 ; V_18 < V_936 ; V_18 ++ ) {
F_403 ( & V_7 -> V_77 -> V_82 ,
sizeof( struct V_124 ) ,
V_7 -> V_125 [ V_18 ] ,
V_7 -> V_133 [ V_18 ] ) ;
}
F_206 ( V_7 ) ;
F_146 ( V_7 -> V_10 ) ;
}
static void F_404 ( struct V_6 * V_7 )
{
struct V_894 * V_77 = V_7 -> V_77 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_521 ; V_18 ++ )
F_405 ( F_406 ( V_77 , V_18 ) , & V_7 -> V_62 [ V_18 ] ) ;
F_407 ( V_77 ) ;
}
static void F_408 ( struct V_6 * V_7 )
{
struct V_894 * V_77 = V_7 -> V_77 ;
V_100 ;
F_404 ( V_7 ) ;
if ( V_7 -> V_898 )
F_409 ( V_7 -> V_898 ) ;
F_410 ( V_7 -> V_937 ) ;
F_411 ( V_77 ) ;
F_402 ( V_7 ) ;
F_412 ( V_7 -> V_26 ) ;
F_413 ( V_77 ) ;
V_105 ;
}
static int F_414 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_29 * V_13 ;
T_3 V_35 ;
int V_18 , V_938 , V_36 = 0 ;
V_7 -> V_933 = F_415 ( V_939 , & V_7 -> V_77 -> V_82 ,
sizeof( struct V_1 ) , 512 , 0 ) ;
if ( ! V_7 -> V_933 )
return - V_554 ;
V_7 -> V_601 = F_416 ( V_932 , sizeof( struct V_1 * ) , V_533 ) ;
V_7 -> V_934 = F_416 ( V_932 , sizeof( T_3 ) , V_533 ) ;
if ( ! V_7 -> V_601 || ! V_7 -> V_934 ) {
F_399 ( V_7 ) ;
return - V_554 ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
if ( V_7 -> V_69 > 1 ) {
if ( V_18 == 0 ) {
V_938 = V_940 ;
V_7 -> V_62 [ V_18 ] . V_599 = 0 ;
V_7 -> V_62 [ V_18 ] . V_600 =
( V_938 - 1 ) ;
} else {
V_938 =
V_941 /
( V_7 -> V_69 - 1 ) ;
V_7 -> V_62 [ V_18 ] . V_599 =
V_940 +
( V_18 - 1 ) * V_938 ;
V_7 -> V_62 [ V_18 ] . V_600 =
( V_940 +
V_18 * V_938 - 1 ) ;
}
} else {
V_938 = V_932 ;
V_7 -> V_62 [ V_18 ] . V_599 = 0 ;
V_7 -> V_62 [ V_18 ] . V_600 = ( V_938 - 1 ) ;
}
V_7 -> V_62 [ V_18 ] . V_553 = V_938 ;
}
F_417 ( V_7 -> V_69 == 0 ) ;
V_18 = V_932 -
V_7 -> V_62 [ V_7 -> V_69 - 1 ] . V_600 - 1 ;
if ( V_18 > 0 ) {
V_7 -> V_62 [ V_7 -> V_69 - 1 ] . V_553 += V_18 ;
V_7 -> V_62 [ V_7 -> V_69 - 1 ] . V_600 += V_18 ;
}
for ( V_18 = 0 ; V_18 < V_932 ; V_18 ++ ) {
V_2 = F_418 ( V_7 -> V_933 , V_533 , & V_35 ) ;
if ( ! V_2 ) {
F_399 ( V_7 ) ;
return - V_554 ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_7 -> V_601 [ V_18 ] = V_2 ;
V_7 -> V_934 [ V_18 ] = V_35 ;
V_13 = & V_2 -> V_13 ;
V_2 -> V_35 = V_35 ;
if ( V_7 -> V_16 )
V_13 -> V_942 . V_943 = F_8 ( V_35 ) ;
else
V_13 -> V_942 . V_944 = F_10 ( V_35 ) ;
V_13 -> V_945 = F_10 ( V_18 << 2 ) ;
if ( V_7 -> V_16 ) {
V_13 -> V_22 . V_42 . V_43 =
F_8 ( V_35 + F_9 ( struct V_1 , V_18 . V_44 ) ) ;
V_13 -> V_22 . V_42 . V_946 =
F_8 ( V_35 + F_9 ( struct V_1 , V_32 . V_34 ) ) ;
} else {
V_13 -> V_47 =
F_10 ( V_35 + F_9 ( struct V_1 , V_18 . V_48 ) ) ;
V_13 -> V_49 = V_13 -> V_47 ;
V_13 -> V_946 =
F_10 ( V_35 + F_9 ( struct V_1 , V_32 . V_31 ) ) ;
}
V_13 -> V_947 = F_250 ( sizeof( struct V_30 ) ) ;
V_2 -> V_23 = V_18 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_678 = V_35 +
F_9 ( struct V_1 , V_55 ) ;
V_2 -> V_13 . V_14 . V_36 = V_36 ;
V_2 -> V_62 = & V_7 -> V_62 [ V_36 ] ;
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
if ( V_18 >= V_7 -> V_62 [ V_36 ] . V_600 )
V_36 ++ ;
}
return 0 ;
}
static int F_419 ( struct V_6 * V_7 )
{
struct V_894 * V_77 = V_7 -> V_77 ;
int V_18 , V_399 = - V_554 ;
V_100 ;
V_7 -> V_935 = F_178 ( sizeof( struct V_139 ) *
V_7 -> V_174 , V_533 ) ;
if ( ! V_7 -> V_935 )
goto V_555;
for ( V_18 = 0 ; V_18 < V_7 -> V_174 ; V_18 ++ ) {
F_35 ( & V_7 -> V_935 [ V_18 ] . V_65 , & V_7 -> V_199 ) ;
V_7 -> V_935 [ V_18 ] . V_7 = V_7 ;
}
V_7 -> V_425 = F_420 ( & V_77 -> V_82 ,
sizeof( struct V_787 ) ,
& V_7 -> V_786 ,
V_533 ) ;
if ( ! V_7 -> V_425 )
goto V_948;
if ( F_414 ( V_7 ) )
goto V_949;
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
V_7 -> V_62 [ V_18 ] . V_856 = F_420 ( & V_77 -> V_82 ,
sizeof( T_2 ) * V_7 -> V_62 [ V_18 ] . V_553 ,
& V_7 -> V_62 [ V_18 ] . V_855 ,
V_533 ) ;
if ( ! V_7 -> V_62 [ V_18 ] . V_856 ) {
while ( -- V_18 > 0 )
F_403 ( & V_77 -> V_82 ,
sizeof( T_2 ) * V_7 -> V_62 [ V_18 ] . V_553 ,
V_7 -> V_62 [ V_18 ] . V_856 ,
V_7 -> V_62 [ V_18 ] . V_855 ) ;
goto V_950;
}
V_7 -> V_62 [ V_18 ] . V_7 = V_7 ;
}
V_7 -> V_22 . V_825 = F_420 ( & V_77 -> V_82 ,
V_7 -> V_834 ,
& V_7 -> V_835 ,
V_533 ) ;
if ( ! V_7 -> V_22 . V_825 )
goto V_951;
for ( V_18 = 0 ; V_18 < V_936 ; V_18 ++ ) {
V_7 -> V_125 [ V_18 ] = F_420 ( & V_77 -> V_82 ,
sizeof( struct V_124 ) ,
& V_7 -> V_133 [ V_18 ] ,
V_533 ) ;
if ( ! V_7 -> V_125 [ V_18 ] )
goto V_952;
V_7 -> V_125 [ V_18 ] -> V_133 =
V_7 -> V_133 [ V_18 ] + F_9 ( struct V_124 , V_132 ) ;
V_7 -> V_125 [ V_18 ] -> V_7 = V_7 ;
F_35 ( & V_7 -> V_125 [ V_18 ] -> V_65 , & V_7 -> V_138 ) ;
}
V_7 -> V_10 = F_178 ( sizeof( struct V_4 ) *
V_953 , V_533 ) ;
if ( ! V_7 -> V_10 )
goto V_952;
V_399 = 0 ;
V_555:
V_105 ;
return V_399 ;
V_952:
while ( V_18 -- > 0 ) {
F_403 ( & V_77 -> V_82 , sizeof( struct V_124 ) ,
V_7 -> V_125 [ V_18 ] ,
V_7 -> V_133 [ V_18 ] ) ;
}
F_403 ( & V_77 -> V_82 , V_7 -> V_834 ,
V_7 -> V_22 . V_825 , V_7 -> V_835 ) ;
V_951:
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_403 ( & V_77 -> V_82 ,
sizeof( T_2 ) * V_7 -> V_62 [ V_18 ] . V_553 ,
V_7 -> V_62 [ V_18 ] . V_856 ,
V_7 -> V_62 [ V_18 ] . V_855 ) ;
}
V_950:
F_399 ( V_7 ) ;
V_949:
F_403 ( & V_77 -> V_82 , sizeof( struct V_787 ) ,
V_7 -> V_425 , V_7 -> V_786 ) ;
V_948:
F_146 ( V_7 -> V_935 ) ;
goto V_555;
}
static void F_421 ( struct V_6 * V_7 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_803 ; V_18 ++ ) {
V_7 -> V_804 [ V_18 ] . V_166 = V_18 ;
V_7 -> V_804 [ V_18 ] . V_809 = 0 ;
V_7 -> V_804 [ V_18 ] . V_374 = V_954 ;
if ( V_955 < F_94 ( V_956 ) )
V_7 -> V_804 [ V_18 ] . V_375 = V_956 [ V_955 ] ;
else
V_7 -> V_804 [ V_18 ] . V_375 = V_957 ;
}
}
static void F_422 ( struct V_6 * V_7 )
{
const struct V_958 * V_189 ;
struct V_959 * V_960 ;
void T_14 * V_961 ;
V_189 = & V_7 -> V_962 -> V_20 ;
V_960 = & V_7 -> V_20 ;
V_961 = V_7 -> V_937 ;
V_960 -> V_72 = V_961 + V_189 -> V_72 ;
V_960 -> V_873 = V_961 + V_189 -> V_873 ;
V_960 -> V_872 = V_961 + V_189 -> V_872 ;
V_960 -> V_634 = V_961 + V_189 -> V_634 ;
V_960 -> V_632 = V_961 + V_189 -> V_632 ;
V_960 -> V_73 = V_961 + V_189 -> V_73 ;
V_960 -> V_74 = V_961 + V_189 -> V_74 ;
V_960 -> V_75 = V_961 + V_189 -> V_75 ;
V_960 -> V_641 = V_961 + V_189 -> V_641 ;
V_960 -> V_108 = V_961 + V_189 -> V_108 ;
V_960 -> V_963 = V_961 + V_189 -> V_963 ;
V_960 -> V_395 = V_961 + V_189 -> V_395 ;
V_960 -> V_964 = V_961 + V_189 -> V_964 ;
V_960 -> V_390 = V_961 + V_189 -> V_390 ;
V_960 -> V_965 = V_961 + V_189 -> V_965 ;
V_960 -> V_393 = V_961 + V_189 -> V_393 ;
if ( V_7 -> V_16 ) {
V_960 -> V_861 = V_961 + V_189 -> V_861 ;
V_960 -> V_385 = V_961 + V_189 -> V_385 ;
V_960 -> V_386 = V_961 + V_189 -> V_386 ;
V_960 -> V_870 = V_961 + V_189 -> V_870 ;
}
}
static void F_423 ( struct V_6 * V_7 ,
struct V_506 * V_26 , struct V_894 * V_77 )
{
int V_18 ;
V_7 -> V_26 = V_26 ;
V_7 -> V_77 = V_77 ;
V_7 -> V_261 = V_966 ;
V_7 -> V_772 = V_967 ;
sprintf ( V_7 -> V_416 , V_968 ) ;
sprintf ( V_7 -> V_969 , V_970 ) ;
sprintf ( V_7 -> V_971 , V_972 ) ;
sprintf ( V_7 -> V_973 , V_974 ) ;
sprintf ( V_7 -> V_975 , V_976 ) ;
sprintf ( V_7 -> V_977 , V_978 ) ;
F_424 ( & V_7 -> V_138 ) ;
F_424 ( & V_7 -> V_127 ) ;
F_424 ( & V_7 -> V_355 ) ;
F_424 ( & V_7 -> V_199 ) ;
F_424 ( & V_7 -> V_200 ) ;
F_374 ( & V_7 -> V_204 , F_147 ) ;
F_425 ( & V_7 -> V_514 ) ;
F_425 ( & V_7 -> V_979 ) ;
F_425 ( & V_7 -> V_924 ) ;
V_7 -> V_360 = V_484 ;
F_421 ( V_7 ) ;
V_7 -> V_174 = V_980 ;
if ( V_7 -> V_16 ) {
V_26 -> V_981 = V_982 ;
V_26 -> V_983 = V_984 ;
if ( V_980 > V_985 )
V_7 -> V_174 = V_985 ;
V_7 -> V_834 = ( sizeof( struct V_986 )
+ ( ( sizeof( struct V_987 )
* V_7 -> V_174 ) ) ) ;
} else {
V_26 -> V_981 = V_988 ;
V_26 -> V_983 = V_989 ;
if ( V_980 > V_990 )
V_7 -> V_174 = V_990 ;
V_7 -> V_834 = ( sizeof( struct V_991 )
+ ( ( sizeof( struct V_992 )
* V_7 -> V_174 ) ) ) ;
}
V_26 -> V_993 = V_776 ;
V_26 -> V_994 = V_26 -> V_190 ;
V_26 -> V_995 = V_756 ;
V_26 -> V_996 = V_7 -> V_997 ;
F_426 ( V_77 , V_7 ) ;
for ( V_18 = 0 ; V_18 < F_94 ( V_7 -> V_62 ) ; V_18 ++ ) {
F_424 ( & V_7 -> V_62 [ V_18 ] . V_63 ) ;
F_424 ( & V_7 -> V_62 [ V_18 ] . V_110 ) ;
F_427 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
if ( V_18 == 0 )
V_7 -> V_62 [ V_18 ] . V_598 = V_7 -> V_26 -> V_27 ;
else
V_7 -> V_62 [ V_18 ] . V_598 = & V_7 -> V_62 [ V_18 ] . V_70 ;
}
}
static const struct V_998 *
F_428 ( const struct V_999 * V_171 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_94 ( V_887 ) ; V_18 ++ )
if ( V_887 [ V_18 ] . V_1000 == V_171 -> V_1000 &&
V_887 [ V_18 ] . V_505 == V_171 -> V_505 )
return & V_887 [ V_18 ] ;
return NULL ;
}
static void F_429 ( struct V_6 * V_7 )
{
struct V_894 * V_77 = V_7 -> V_77 ;
if ( F_430 ( V_77 ) ) {
F_431 ( V_7 -> V_924 ,
! F_430 ( V_77 ) ,
V_1001 ) ;
F_364 ( V_77 ) ;
}
}
static void F_432 ( struct V_6 * V_7 )
{
int V_1002 , V_1003 = sizeof( V_7 -> V_1004 [ 0 ] . V_284 ) - 1 ;
for ( V_1002 = 0 ; V_1002 < V_7 -> V_521 ; V_1002 ++ ) {
snprintf ( V_7 -> V_1004 [ V_1002 ] . V_284 , V_1003 ,
L_123 , V_7 -> V_26 -> V_190 , V_1002 ) ;
V_7 -> V_1004 [ V_1002 ] .
V_284 [ strlen ( V_7 -> V_1004 [ V_1002 ] . V_284 ) ] = 0 ;
}
}
static int F_433 ( struct V_6 * V_7 ,
struct V_894 * V_77 )
{
int V_18 , V_399 ;
for ( V_18 = 1 ; V_18 < V_7 -> V_521 ; V_18 ++ ) {
V_399 = F_434 ( F_406 ( V_77 , V_18 ) ,
F_271 ,
0 ,
V_7 -> V_1004 [ V_18 ] . V_284 ,
& V_7 -> V_62 [ V_18 ] ) ;
if ( V_399 ) {
while ( -- V_18 >= 0 )
F_405 ( F_406 ( V_77 , V_18 ) ,
& V_7 -> V_62 [ V_18 ] ) ;
return V_399 ;
}
}
return 0 ;
}
static T_9 F_435 ( int V_662 , void * V_663 )
{
struct V_6 * V_7 = (struct V_6 * ) V_663 ;
unsigned long V_25 = 0 ;
T_9 V_399 = V_630 ;
F_116 ( & V_7 -> V_77 -> V_82 , L_124 , V_662 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_7 -> V_1005 = 1 ;
F_436 ( & V_7 -> V_979 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
return V_399 ;
}
static int F_437 ( struct V_6 * V_7 , struct V_894 * V_77 )
{
int V_399 ;
volatile T_2 V_68 ;
unsigned long V_25 = 0 ;
int V_662 = F_406 ( V_77 , 0 ) ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_425 ( & V_7 -> V_979 ) ;
V_7 -> V_1005 = 0 ;
F_20 ( V_7 , ~ V_637 ) ;
F_24 ( V_380 , V_7 -> V_20 . V_872 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_634 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
V_399 = F_434 ( V_662 , F_435 , 0 , V_939 , V_7 ) ;
if ( V_399 ) {
F_29 ( & V_77 -> V_82 , L_125 , V_662 ) ;
return V_399 ;
} else if ( V_640 )
F_116 ( & V_77 -> V_82 , L_126 , V_662 ) ;
F_24 ( V_380 , V_7 -> V_20 . V_641 ) ;
V_68 = F_25 ( V_7 -> V_20 . V_75 ) ;
F_431 ( V_7 -> V_979 , V_7 -> V_1005 , V_628 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_20 ( V_7 , ~ V_637 ) ;
if ( ! V_7 -> V_1005 ) {
F_116 ( & V_77 -> V_82 , L_127 ) ;
V_399 = - V_1006 ;
} else if ( V_640 )
F_116 ( & V_77 -> V_82 , L_128 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_405 ( V_662 , V_7 ) ;
V_105 ;
return V_399 ;
}
static int F_438 ( struct V_894 * V_77 ,
const struct V_999 * V_171 )
{
struct V_6 * V_7 ;
struct V_506 * V_26 ;
unsigned long V_1007 ;
void T_14 * V_1008 ;
int V_399 = V_81 ;
volatile T_2 V_1009 , V_1010 , V_1011 ;
unsigned long V_25 , V_1012 ;
unsigned int V_1013 ;
V_100 ;
F_116 ( & V_77 -> V_82 , L_129 , V_77 -> V_662 ) ;
V_26 = F_439 ( & V_1014 , sizeof( * V_7 ) ) ;
if ( ! V_26 ) {
F_29 ( & V_77 -> V_82 , L_130 ) ;
V_399 = - V_554 ;
goto V_555;
}
V_7 = (struct V_6 * ) V_26 -> V_508 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
F_440 ( & V_7 -> V_579 , & V_77 -> V_82 , & V_1015 ) ;
V_7 -> V_887 = F_428 ( V_171 ) ;
if ( ! V_7 -> V_887 ) {
F_29 ( & V_77 -> V_82 , L_131 ,
V_171 -> V_1000 , V_171 -> V_505 ) ;
goto V_1016;
}
V_7 -> V_16 = V_7 -> V_887 -> V_1017 == V_1018 ? 1 : 0 ;
V_7 -> V_962 = V_7 -> V_887 -> V_288 ;
V_7 -> V_639 = V_7 -> V_962 -> V_639 ;
V_7 -> V_997 = V_7 -> V_962 -> V_997 ;
if ( V_1019 )
V_7 -> V_629 = V_1019 ;
else if ( V_171 -> V_1020 & V_1021 )
V_7 -> V_629 = V_866 ;
else
V_7 -> V_629 = V_1022 ;
V_7 -> V_1023 = V_77 -> V_769 ;
F_423 ( V_7 , V_26 , V_77 ) ;
V_1007 = F_441 ( V_77 , 0 ) ;
V_399 = F_442 ( V_77 , V_939 ) ;
if ( V_399 < 0 ) {
F_29 ( & V_77 -> V_82 ,
L_132 ) ;
goto V_1016;
}
V_399 = F_443 ( V_77 ) ;
if ( V_399 || F_430 ( V_77 ) ) {
if ( F_430 ( V_77 ) ) {
F_429 ( V_7 ) ;
V_399 = F_443 ( V_77 ) ;
}
if ( V_399 ) {
F_29 ( & V_77 -> V_82 , L_133 ) ;
F_429 ( V_7 ) ;
goto V_1024;
}
}
V_1008 = F_444 ( V_77 , 0 ) ;
if ( ! V_1008 ) {
F_29 ( & V_77 -> V_82 ,
L_134 ) ;
V_399 = - V_554 ;
goto V_1025;
}
V_7 -> V_937 = V_1008 ;
V_7 -> V_1026 = V_1007 ;
V_7 -> V_392 = V_7 -> V_962 -> V_875 + V_1008 ;
F_422 ( V_7 ) ;
if ( V_7 -> V_16 ) {
V_399 = F_445 ( & V_77 -> V_82 , F_446 ( 64 ) ) ;
if ( V_399 < 0 ) {
F_398 ( & V_77 -> V_82 , L_135 ) ;
V_399 = F_445 ( & V_77 -> V_82 ,
F_446 ( 32 ) ) ;
}
} else
V_399 = F_445 ( & V_77 -> V_82 , F_446 ( 32 ) ) ;
if ( V_399 < 0 ) {
F_29 ( & V_77 -> V_82 , L_136 ) ;
goto V_1027;
}
V_399 = F_368 ( V_77 , V_1028 ,
V_7 -> V_962 -> V_1029 ) ;
if ( V_399 != V_81 ) {
F_29 ( & V_77 -> V_82 , L_137 ) ;
F_429 ( V_7 ) ;
V_399 = - V_83 ;
goto V_1027;
}
V_1011 = F_25 ( V_7 -> V_20 . V_75 ) ;
F_429 ( V_7 ) ;
if ( V_1030 > V_1031 ) {
F_29 ( & V_77 -> V_82 , L_138 ,
V_1031 ) ;
V_1030 = V_1031 ;
}
V_1013 = V_1032 ;
if ( V_7 -> V_887 -> V_1033 )
V_1013 |= V_1034 | V_1035 ;
V_399 = F_447 ( V_77 , 1 , V_1030 , V_1013 ) ;
if ( V_399 < 0 ) {
F_429 ( V_7 ) ;
goto V_1027;
}
V_7 -> V_521 = V_399 ;
if ( ! V_77 -> V_1036 && ! V_77 -> V_1037 )
V_7 -> V_639 = 1 ;
F_448 ( V_77 ) ;
if ( F_430 ( V_77 ) ) {
F_429 ( V_7 ) ;
F_448 ( V_77 ) ;
if ( F_430 ( V_77 ) ) {
V_399 = - V_83 ;
goto V_1038;
}
}
if ( V_77 -> V_1036 || V_77 -> V_1037 ) {
V_399 = F_437 ( V_7 , V_77 ) ;
switch ( V_399 ) {
case 0 :
F_116 ( & V_77 -> V_82 ,
L_139 , V_7 -> V_521 ,
V_77 -> V_1037 ? L_140 : L_141 ) ;
break;
case - V_1006 :
F_429 ( V_7 ) ;
F_407 ( V_77 ) ;
V_7 -> V_521 = 1 ;
V_7 -> V_639 = 1 ;
break;
default:
goto V_1038;
}
}
V_7 -> V_69 = F_449 ( V_7 -> V_521 ,
( unsigned int ) F_450 () ,
( unsigned int ) V_1039 ) ;
if ( ( V_399 = F_26 ( V_7 ) ) )
goto V_1038;
if ( ( V_399 = F_30 ( V_7 ) ) )
goto V_1038;
V_399 = F_419 ( V_7 ) ;
if ( V_399 < 0 ) {
F_29 ( & V_77 -> V_82 ,
L_142 ) ;
goto V_1038;
}
V_399 = F_392 ( V_77 ) ;
if ( V_399 != V_81 ) {
F_29 ( & V_77 -> V_82 , L_143 ) ;
V_399 = - V_83 ;
goto V_1040;
}
V_1009 = F_25 ( V_7 -> V_20 . V_632 ) ;
V_1011 = F_25 ( V_7 -> V_20 . V_641 ) ;
V_1010 = F_25 ( V_7 -> V_20 . V_395 ) ;
if ( ( V_1009 & V_638 ) == 0 || ( V_1010 & V_388 ) )
V_7 -> V_931 = 1 ;
if ( ( V_1011 & V_871 ) || V_1041 )
V_7 -> V_931 = 1 ;
if ( V_1011 & V_642 )
V_7 -> V_643 = 1 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_20 ( V_7 , ~ V_637 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_77 -> V_1036 || V_77 -> V_1037 ) {
F_432 ( V_7 ) ;
V_399 = F_434 ( F_406 ( V_77 , 0 ) , F_270 , 0 ,
V_7 -> V_1004 [ 0 ] . V_284 ,
& V_7 -> V_62 [ 0 ] ) ;
if ( ! V_399 )
V_399 = F_433 ( V_7 , V_77 ) ;
} else {
V_399 = F_434 ( V_77 -> V_662 , F_270 ,
V_1042 ,
V_939 , & V_7 -> V_62 [ 0 ] ) ;
}
if ( V_399 ) {
F_29 ( & V_77 -> V_82 , L_144 ,
V_77 -> V_662 , V_399 ) ;
goto V_1040;
}
if ( ( V_171 -> V_1020 & V_1043 ) ||
( V_171 -> V_505 == V_1044 && ! V_7 -> V_1023 ) ) {
V_7 -> V_923 = 1 ;
V_7 -> V_899 = F_373 ;
V_7 -> V_898 = F_451 ( L_145 ,
V_1045 , V_26 -> V_190 ) ;
if ( ! V_7 -> V_898 ) {
F_29 ( & V_77 -> V_82 , L_146 ) ;
V_399 = - V_554 ;
goto V_1046;
}
} else
V_7 -> V_899 = F_367 ;
F_5 ( & V_1047 , V_1012 ) ;
F_35 ( & V_7 -> V_65 , & V_1048 ) ;
F_6 ( & V_1047 , V_1012 ) ;
V_105 ;
V_555:
return V_399 ;
V_1046:
F_404 ( V_7 ) ;
V_1040:
F_402 ( V_7 ) ;
V_1038:
F_429 ( V_7 ) ;
F_407 ( V_77 ) ;
V_1027:
F_410 ( V_1008 ) ;
V_1025:
F_413 ( V_77 ) ;
V_1024:
F_411 ( V_77 ) ;
V_1016:
F_412 ( V_26 ) ;
goto V_555;
}
static void F_452 ( struct V_6 * V_7 ,
enum V_913 V_914 )
{
V_100 ;
if ( V_7 -> V_360 == V_359 )
V_7 -> V_360 = V_414 ;
V_7 -> V_366 = 0 ;
V_7 -> V_517 = 1 ;
F_117 ( V_7 , V_914 ) ;
V_105 ;
}
static void F_453 ( struct V_894 * V_77 )
{
unsigned long V_930 = 0 ;
struct V_6 * V_7 = F_391 ( V_77 ) ;
int V_18 ;
unsigned long V_1012 ;
V_100 ;
F_5 ( V_7 -> V_26 -> V_27 , V_930 ) ;
while ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_930 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_930 ) ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_21 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
V_7 -> V_62 [ V_18 ] . V_713 = 1 ;
F_22 ( & V_7 -> V_62 [ V_18 ] . V_70 ) ;
}
F_3 () ;
F_452 ( V_7 , V_515 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_930 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_454 ( & V_7 -> V_204 ) ;
if ( V_7 -> V_898 )
F_455 ( V_7 -> V_898 ) ;
F_424 ( & V_7 -> V_200 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_930 ) ;
F_5 ( & V_1047 , V_1012 ) ;
F_18 ( & V_7 -> V_65 ) ;
F_6 ( & V_1047 , V_1012 ) ;
if ( V_7 -> V_360 == V_414 )
V_7 -> V_360 = V_359 ;
F_6 ( V_7 -> V_26 -> V_27 , V_930 ) ;
F_408 ( V_7 ) ;
V_105 ;
}
static void F_456 ( struct V_894 * V_77 )
{
struct V_6 * V_7 = F_391 ( V_77 ) ;
V_100 ;
F_457 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1049 ) ;
F_458 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1050 ) ;
F_459 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1051 ) ;
F_460 ( V_7 -> V_26 ) ;
F_453 ( V_77 ) ;
V_105 ;
}
static int F_461 ( struct V_894 * V_77 , const struct V_999 * V_171 )
{
struct V_6 * V_7 ;
unsigned long V_117 ;
int V_399 , V_18 ;
V_399 = F_438 ( V_77 , V_171 ) ;
if ( V_399 )
return V_399 ;
V_7 = F_391 ( V_77 ) ;
V_399 = F_397 ( V_7 ) ;
if ( V_399 ) {
F_453 ( V_77 ) ;
return V_399 ;
}
V_399 = F_462 ( V_7 -> V_26 , & V_77 -> V_82 ) ;
if ( V_399 ) {
F_453 ( V_77 ) ;
return V_399 ;
}
V_399 = F_463 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1049 ) ;
if ( V_399 ) {
F_460 ( V_7 -> V_26 ) ;
F_453 ( V_77 ) ;
return V_399 ;
}
V_399 = F_464 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1051 ) ;
if ( V_399 ) {
F_458 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1050 ) ;
F_457 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1049 ) ;
F_460 ( V_7 -> V_26 ) ;
F_453 ( V_77 ) ;
return V_399 ;
}
V_399 = F_465 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1050 ) ;
if ( V_399 ) {
F_459 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1051 ) ;
F_457 ( & V_7 -> V_26 -> V_495 . V_496 ,
& V_1049 ) ;
F_460 ( V_7 -> V_26 ) ;
F_453 ( V_77 ) ;
return V_399 ;
}
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
V_7 -> V_492 = 1 ;
F_75 ( & V_7 -> V_204 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
V_7 -> V_518 = V_7 -> V_962 -> V_518 ;
if ( V_7 -> V_518 && V_7 -> V_16 && V_7 -> V_521 > 1 ) {
for ( V_18 = 1 ; V_18 < V_7 -> V_69 ; V_18 ++ ) {
F_175 ( & V_7 -> V_62 [ V_18 ] . V_522 ,
V_7 -> V_518 , V_523 ) ;
}
}
F_466 ( V_7 -> V_26 ) ;
return 0 ;
}
static void F_467 ( struct V_894 * V_77 )
{
struct V_6 * V_7 = F_391 ( V_77 ) ;
unsigned long V_25 = 0 ;
enum V_913 V_914 = V_515 ;
int V_18 ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
if ( V_7 -> V_518 && V_7 -> V_16 && V_7 -> V_521 > 1 ) {
V_7 -> V_518 = 0 ;
for ( V_18 = 1 ; V_18 < V_7 -> V_69 ; V_18 ++ )
F_174 ( & V_7 -> V_62 [ V_18 ] . V_522 ) ;
}
while ( V_7 -> V_362 ) {
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
F_5 ( V_7 -> V_26 -> V_27 , V_25 ) ;
}
if ( V_1052 && V_1053 == V_1054 && V_7 -> V_16 )
V_914 = V_915 ;
F_452 ( V_7 , V_914 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_25 ) ;
F_166 ( V_7 -> V_514 , ! V_7 -> V_362 ) ;
if ( V_1052 && V_1053 == V_1054 && V_7 -> V_16 ) {
F_404 ( V_7 ) ;
F_413 ( V_7 -> V_77 ) ;
}
}
static void F_468 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_65 , & V_2 -> V_62 -> V_63 ) ;
}
static int F_469 ( struct V_1055 * V_1056 , T_15 V_1057 , void * V_206 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
unsigned long V_117 = 0 , V_1012 ;
if ( V_1057 != V_1058 && V_1057 != V_1059 && V_1057 != V_1060 )
return V_1061 ;
F_5 ( & V_1047 , V_1012 ) ;
F_62 (ioa_cfg, &ipr_ioa_head, queue) {
F_5 ( V_7 -> V_26 -> V_27 , V_117 ) ;
if ( ! V_7 -> V_62 [ V_66 ] . V_126 ||
( V_1052 && V_1057 == V_1058 && V_7 -> V_16 ) ) {
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
continue;
}
V_2 = F_19 ( V_7 ) ;
V_2 -> V_13 . V_24 = F_10 ( V_128 ) ;
V_2 -> V_13 . V_14 . V_129 = V_607 ;
V_2 -> V_13 . V_14 . V_15 [ 0 ] = V_916 ;
V_2 -> V_13 . V_14 . V_15 [ 1 ] = V_918 ;
F_45 ( V_2 , F_468 , F_118 , V_612 ) ;
F_6 ( V_7 -> V_26 -> V_27 , V_117 ) ;
}
F_6 ( & V_1047 , V_1012 ) ;
return V_1062 ;
}
static int T_16 F_470 ( void )
{
F_197 ( L_147 ,
V_442 , V_1063 ) ;
F_471 ( & V_1064 ) ;
return F_472 ( & V_1065 ) ;
}
static void T_17 F_473 ( void )
{
F_474 ( & V_1064 ) ;
F_475 ( & V_1065 ) ;
}
