static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
strcpy ( V_4 -> V_7 , V_8 ) ;
strcpy ( V_4 -> V_9 , V_10 ) ;
strncpy ( V_4 -> V_11 , V_6 -> V_12 , V_13 ) ;
strcpy ( V_4 -> V_14 , F_3 ( V_6 -> V_15 ) ) ;
V_4 -> V_16 = 0 ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_19 = 0 ;
if ( F_5 ( V_6 ) )
F_6 ( V_6 , & V_19 ) ;
return V_19 ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_20 * V_21 , void * V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_5 ( V_6 ) ) {
memset ( V_22 , 0 , V_21 -> V_23 ) ;
F_8 ( V_6 , V_21 -> V_23 , V_22 ) ;
}
}
static int
F_9 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_26 * V_27 = & V_6 -> V_28 [ 0 ] . V_27 ;
struct V_26 * V_29 = & V_6 -> V_29 ;
V_25 -> V_30 = V_27 -> V_31 ;
V_25 -> V_32 = V_27 -> V_33 ;
V_25 -> V_34 = V_27 -> V_35 ;
V_25 -> V_36 = V_29 -> V_31 ;
V_25 -> V_37 = V_29 -> V_33 ;
V_25 -> V_38 = V_29 -> V_35 ;
V_25 -> V_39 = V_27 -> V_40 ;
V_25 -> V_41 = V_29 -> V_40 ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_42 * V_43 ;
struct V_26 * V_27 ;
struct V_26 * V_29 = & V_6 -> V_29 ;
T_1 V_44 , V_45 , V_46 ;
int V_47 = 0 , V_48 ;
T_1 V_49 ;
if ( V_25 -> V_41 == 1 )
return - V_50 ;
F_11 (adapter, rxo, i) {
V_27 = & V_43 -> V_27 ;
if ( ! V_27 -> V_40 && V_25 -> V_39 )
V_27 -> V_31 = 0 ;
V_27 -> V_40 = V_25 -> V_39 ;
V_44 = V_25 -> V_32 ;
V_45 = V_25 -> V_34 ;
V_46 = V_25 -> V_30 ;
if ( V_27 -> V_40 ) {
if ( V_44 > V_51 )
V_44 = V_51 ;
if ( V_45 > V_44 )
V_45 = V_44 ;
V_27 -> V_33 = V_44 ;
V_27 -> V_35 = V_45 ;
if ( V_27 -> V_31 > V_44 )
V_27 -> V_31 = V_44 ;
if ( V_27 -> V_31 < V_45 )
V_27 -> V_31 = V_45 ;
} else {
if ( V_46 > V_51 )
V_46 = V_51 ;
if ( V_27 -> V_31 != V_46 ) {
V_47 = F_12 ( V_6 , V_27 -> V_52 . V_53 ,
V_46 ) ;
if ( ! V_47 )
V_27 -> V_31 = V_46 ;
}
}
}
V_49 = V_25 -> V_36 ;
if ( V_49 > V_51 )
V_49 = V_51 ;
if ( V_29 -> V_31 != V_49 ) {
V_47 = F_12 ( V_6 , V_29 -> V_52 . V_53 , V_49 ) ;
if ( ! V_47 )
V_29 -> V_31 = V_49 ;
}
return 0 ;
}
static void
F_13 ( struct V_1 * V_2 ,
struct V_54 * V_55 , T_2 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_42 * V_43 ;
void * V_57 = NULL ;
int V_48 , V_58 ;
for ( V_48 = 0 ; V_48 < V_59 ; V_48 ++ ) {
switch ( V_60 [ V_48 ] . type ) {
case V_61 :
V_57 = & V_2 -> V_55 ;
break;
case V_62 :
V_57 = & V_6 -> V_63 ;
break;
case V_64 :
V_57 = & V_6 -> V_65 ;
break;
}
V_57 = ( V_66 * ) V_57 + V_60 [ V_48 ] . V_67 ;
V_56 [ V_48 ] = ( V_60 [ V_48 ] . V_68 == sizeof( V_69 ) ) ?
* ( V_69 * ) V_57 : * ( T_1 * ) V_57 ;
}
F_11 (adapter, rxo, j) {
for ( V_48 = 0 ; V_48 < V_70 ; V_48 ++ ) {
switch ( V_71 [ V_48 ] . type ) {
case V_72 :
V_57 = ( V_66 * ) & V_43 -> V_55 + V_71 [ V_48 ] . V_67 ;
break;
case V_73 :
V_57 = ( T_1 * ) F_14 ( V_6 ) +
V_43 -> V_52 . V_53 ;
break;
}
V_56 [ V_59 + V_58 * V_70 + V_48 ] =
( V_71 [ V_48 ] . V_68 == sizeof( V_69 ) ) ?
* ( V_69 * ) V_57 : * ( T_1 * ) V_57 ;
}
}
}
static void
F_15 ( struct V_1 * V_2 , T_3 V_74 ,
T_4 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_48 , V_58 ;
switch ( V_74 ) {
case V_75 :
for ( V_48 = 0 ; V_48 < V_59 ; V_48 ++ ) {
memcpy ( V_56 , V_60 [ V_48 ] . V_76 , V_77 ) ;
V_56 += V_77 ;
}
for ( V_48 = 0 ; V_48 < V_6 -> V_78 ; V_48 ++ ) {
for ( V_58 = 0 ; V_58 < V_70 ; V_58 ++ ) {
sprintf ( V_56 , L_1 , V_48 ,
V_71 [ V_58 ] . V_76 ) ;
V_56 += V_77 ;
}
}
break;
case V_79 :
for ( V_48 = 0 ; V_48 < V_80 ; V_48 ++ ) {
memcpy ( V_56 , V_81 [ V_48 ] , V_77 ) ;
V_56 += V_77 ;
}
break;
}
}
static int F_16 ( struct V_1 * V_2 , int V_74 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_74 ) {
case V_79 :
return V_80 ;
case V_75 :
return V_59 +
V_6 -> V_78 * V_70 ;
default:
return - V_50 ;
}
}
static int F_17 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_84 V_85 ;
struct V_86 * V_87 ;
V_66 V_88 = 0 ;
T_5 V_89 = 0 ;
bool V_90 = false ;
int V_47 ;
T_5 V_91 ;
if ( ( V_6 -> V_89 < 0 ) || ( ! ( V_2 -> V_92 & V_93 ) ) ) {
V_47 = F_18 ( V_6 , & V_90 ,
& V_88 , & V_89 , 0 ) ;
F_19 ( V_6 , V_90 ) ;
if ( V_89 ) {
F_20 ( V_83 , V_89 * 10 ) ;
} else {
switch ( V_88 ) {
case V_94 :
F_20 ( V_83 , V_95 ) ;
break;
case V_96 :
F_20 ( V_83 , V_97 ) ;
break;
case V_98 :
F_20 ( V_83 , V_99 ) ;
break;
case V_100 :
F_20 ( V_83 , V_101 ) ;
break;
case V_102 :
F_20 ( V_83 , 0 ) ;
break;
}
}
V_85 . V_68 = sizeof( struct V_103 ) ;
V_85 . V_104 = F_21 ( & V_6 -> V_15 -> V_105 ,
V_85 . V_68 , & V_85 . V_106 ,
V_107 ) ;
if ( ! V_85 . V_104 ) {
F_22 ( & V_6 -> V_15 -> V_105 , L_2 ) ;
return - V_108 ;
}
V_47 = F_23 ( V_6 , & V_85 ) ;
if ( ! V_47 ) {
V_87 = (struct V_86 * ) V_85 . V_104 ;
V_91 = F_24 ( V_87 -> V_109 ) ;
switch ( V_91 ) {
case V_110 :
case V_111 :
case V_112 :
V_83 -> V_113 = V_114 ;
break;
default:
V_83 -> V_113 = V_115 ;
break;
}
switch ( V_91 ) {
case V_116 :
case V_117 :
V_83 -> V_118 = V_119 ;
V_83 -> V_120 = V_121 ;
break;
default:
V_83 -> V_118 = V_122 ;
V_83 -> V_120 = V_123 ;
break;
}
}
V_6 -> V_89 = F_25 ( V_83 ) ;
V_6 -> V_124 = V_83 -> V_113 ;
V_6 -> V_120 = V_83 -> V_120 ;
V_6 -> V_118 = V_83 -> V_118 ;
F_26 ( & V_6 -> V_15 -> V_105 , V_85 . V_68 , V_85 . V_104 ,
V_85 . V_106 ) ;
} else {
F_20 ( V_83 , V_6 -> V_89 ) ;
V_83 -> V_113 = V_6 -> V_124 ;
V_83 -> V_120 = V_6 -> V_120 ;
V_83 -> V_118 = V_6 -> V_118 ;
}
V_83 -> V_125 = V_126 ;
V_83 -> V_127 = V_6 -> V_128 ;
switch ( V_83 -> V_113 ) {
case V_114 :
V_83 -> V_129 = ( V_130 | V_131 ) ;
break;
case V_115 :
V_83 -> V_129 = ( V_130 | V_132 ) ;
break;
case V_133 :
V_83 -> V_129 = ( V_130 | V_134 ) ;
break;
}
if ( V_83 -> V_118 ) {
V_83 -> V_129 |= V_135 ;
V_83 -> V_129 |= V_136 ;
V_83 -> V_137 |= ( V_138 |
V_139 ) ;
}
return 0 ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_140 * V_141 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_141 -> V_142 = V_6 -> V_28 [ 0 ] . V_52 . V_23 ;
V_141 -> V_143 = V_6 -> V_144 . V_52 . V_23 ;
V_141 -> V_145 = F_28 ( & V_6 -> V_28 [ 0 ] . V_52 . V_146 ) ;
V_141 -> V_147 = F_28 ( & V_6 -> V_144 . V_52 . V_146 ) ;
}
static void
F_29 ( struct V_1 * V_2 , struct V_148 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_30 ( V_6 , & V_83 -> V_149 , & V_83 -> V_150 ) ;
V_83 -> V_118 = 0 ;
}
static int
F_31 ( struct V_1 * V_2 , struct V_148 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_47 ;
if ( V_83 -> V_118 != 0 )
return - V_50 ;
V_6 -> V_151 = V_83 -> V_149 ;
V_6 -> V_152 = V_83 -> V_150 ;
V_47 = F_32 ( V_6 ,
V_6 -> V_151 , V_6 -> V_152 ) ;
if ( V_47 )
F_33 ( & V_6 -> V_15 -> V_105 , L_3 ) ;
return V_47 ;
}
static int
F_34 ( struct V_1 * V_2 ,
enum V_153 V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_154 ) {
case V_155 :
F_35 ( V_6 , V_6 -> V_156 ,
& V_6 -> V_157 ) ;
return 1 ;
case V_158 :
F_36 ( V_6 , V_6 -> V_156 , 0 , 0 ,
V_159 ) ;
break;
case V_160 :
F_36 ( V_6 , V_6 -> V_156 , 0 , 0 ,
V_161 ) ;
break;
case V_162 :
F_36 ( V_6 , V_6 -> V_156 , 0 , 0 ,
V_6 -> V_157 ) ;
}
return 0 ;
}
static bool
F_37 ( struct V_5 * V_6 )
{
if ( ! F_5 ( V_6 ) )
return false ;
else
return true ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( F_37 ( V_6 ) )
V_164 -> V_129 = V_165 ;
if ( V_6 -> V_164 )
V_164 -> V_166 = V_165 ;
else
V_164 -> V_166 = 0 ;
memset ( & V_164 -> V_167 , 0 , sizeof( V_164 -> V_167 ) ) ;
}
static int
F_39 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_164 -> V_166 & ~ V_165 )
return - V_50 ;
if ( ( V_164 -> V_166 & V_165 ) && F_37 ( V_6 ) )
V_6 -> V_164 = true ;
else
V_6 -> V_164 = false ;
return 0 ;
}
static int
F_40 ( struct V_5 * V_6 )
{
int V_168 , V_48 ;
struct V_84 V_169 ;
static const V_69 V_170 [ 2 ] = {
0x5a5a5a5a5a5a5a5aULL , 0xa5a5a5a5a5a5a5a5ULL
} ;
V_169 . V_68 = sizeof( struct V_171 ) ;
V_169 . V_104 = F_21 ( & V_6 -> V_15 -> V_105 , V_169 . V_68 ,
& V_169 . V_106 , V_107 ) ;
if ( ! V_169 . V_104 ) {
F_22 ( & V_6 -> V_15 -> V_105 , L_4 ) ;
return - V_108 ;
}
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
V_168 = F_41 ( V_6 , V_170 [ V_48 ] ,
4096 , & V_169 ) ;
if ( V_168 != 0 )
goto V_172;
}
V_172:
F_26 ( & V_6 -> V_15 -> V_105 , V_169 . V_68 , V_169 . V_104 ,
V_169 . V_106 ) ;
return V_168 ;
}
static V_69 F_42 ( struct V_5 * V_6 , V_66 V_173 ,
V_69 * V_47 )
{
F_43 ( V_6 , V_6 -> V_156 ,
V_173 , 1 ) ;
* V_47 = F_44 ( V_6 , V_6 -> V_156 ,
V_173 , 1500 ,
2 , 0xabc ) ;
F_43 ( V_6 , V_6 -> V_156 ,
V_174 , 1 ) ;
return * V_47 ;
}
static void
F_45 ( struct V_1 * V_2 , struct V_175 * V_176 , V_69 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_90 ;
V_66 V_88 = 0 ;
T_5 V_177 = 0 ;
memset ( V_56 , 0 , sizeof( V_69 ) * V_80 ) ;
if ( V_176 -> V_92 & V_178 ) {
if ( F_42 ( V_6 , V_179 ,
& V_56 [ 0 ] ) != 0 ) {
V_176 -> V_92 |= V_180 ;
}
if ( F_42 ( V_6 , V_181 ,
& V_56 [ 1 ] ) != 0 ) {
V_176 -> V_92 |= V_180 ;
}
if ( F_42 ( V_6 , V_182 ,
& V_56 [ 2 ] ) != 0 ) {
V_176 -> V_92 |= V_180 ;
}
}
if ( F_40 ( V_6 ) != 0 ) {
V_56 [ 3 ] = 1 ;
V_176 -> V_92 |= V_180 ;
}
if ( F_18 ( V_6 , & V_90 , & V_88 ,
& V_177 , 0 ) != 0 ) {
V_176 -> V_92 |= V_180 ;
V_56 [ 4 ] = - 1 ;
} else if ( ! V_88 ) {
V_176 -> V_92 |= V_180 ;
V_56 [ 4 ] = 1 ;
}
}
static int
F_46 ( struct V_1 * V_2 , struct V_183 * V_184 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
char V_185 [ V_186 ] ;
V_185 [ V_186 - 1 ] = 0 ;
strcpy ( V_185 , V_184 -> V_56 ) ;
return F_47 ( V_6 , V_185 ) ;
}
static int
F_48 ( struct V_1 * V_2 )
{
return V_187 ;
}
static int
F_49 ( struct V_1 * V_2 , struct V_188 * V_189 ,
T_4 * V_56 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_84 V_190 ;
struct V_191 * V_87 ;
int V_47 ;
if ( ! V_189 -> V_23 )
return - V_50 ;
V_189 -> V_192 = V_193 | ( V_6 -> V_15 -> V_194 << 16 ) ;
memset ( & V_190 , 0 , sizeof( struct V_84 ) ) ;
V_190 . V_68 = sizeof( struct V_195 ) ;
V_190 . V_104 = F_21 ( & V_6 -> V_15 -> V_105 , V_190 . V_68 ,
& V_190 . V_106 , V_107 ) ;
if ( ! V_190 . V_104 ) {
F_22 ( & V_6 -> V_15 -> V_105 ,
L_5 ) ;
return - V_108 ;
}
V_47 = F_50 ( V_6 , & V_190 ) ;
if ( ! V_47 ) {
V_87 = (struct V_191 * ) V_190 . V_104 ;
memcpy ( V_56 , V_87 -> V_196 + V_189 -> V_67 , V_189 -> V_23 ) ;
}
F_26 ( & V_6 -> V_15 -> V_105 , V_190 . V_68 , V_190 . V_104 ,
V_190 . V_106 ) ;
return V_47 ;
}
