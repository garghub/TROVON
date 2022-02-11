static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 & V_8 )
memcpy ( V_4 , V_9 , V_10 * V_11 ) ;
else
memcpy ( V_4 , V_9 ,
V_12 * V_11 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_13 * V_14 ,
T_3 * V_4 )
{
int V_15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_5 * V_19 = ( T_5 * ) & V_6 -> V_20 ;
for ( V_15 = 0 ; V_15 < V_12 ; V_15 ++ )
V_4 [ V_15 ] = F_4 ( & V_19 [ V_15 ] ) ;
if ( V_6 -> V_7 & V_8 ) {
T_1 T_4 * V_21 = ( T_1 T_4 * ) & V_17 -> V_21 ;
for (; V_15 < V_10 ; V_15 ++ , V_21 ++ )
V_4 [ V_15 ] = ( T_3 ) F_5 ( V_21 ) ;
}
}
static int F_6 ( struct V_1 * V_2 , int V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_22 ) {
case V_23 :
if ( V_6 -> V_7 & V_8 )
return V_10 ;
else
return V_12 ;
default:
return - V_24 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_8 ( V_26 -> V_27 , V_28 , sizeof( V_26 -> V_27 ) ) ;
F_8 ( V_26 -> V_29 , V_30 ,
sizeof( V_26 -> V_29 ) ) ;
F_8 ( V_26 -> V_31 , L_1 , sizeof( V_26 -> V_31 ) ) ;
F_8 ( V_26 -> V_32 , L_1 , sizeof( V_26 -> V_32 ) ) ;
V_26 -> V_33 = 0 ;
V_26 -> V_34 = 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = V_6 -> V_38 ;
if ( NULL == V_38 )
return - V_39 ;
return F_10 ( V_38 , V_36 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = V_6 -> V_38 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 = NULL ;
if ( NULL == V_38 )
return - V_39 ;
V_43 = V_6 -> V_43 [ 0 ] ;
V_41 = V_6 -> V_41 [ 0 ] ;
V_36 -> V_44 = F_12 ( V_43 -> V_45 ) ;
V_36 -> V_46 = F_12 ( V_41 -> V_47 ) ;
return F_13 ( V_38 , V_36 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return sizeof ( struct V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_48 * V_17 ,
void * V_49 )
{
int V_15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 T_4 * V_50 = ( T_1 T_4 * ) V_6 -> V_18 [ 0 ] . V_17 ;
T_1 * V_4 = ( T_1 * ) V_49 ;
for ( V_15 = 0 ; V_15 < sizeof ( struct V_16 ) / sizeof ( T_1 ) ; V_15 ++ )
V_4 [ V_15 ] = F_5 ( & V_50 [ V_15 ] ) ;
}
static unsigned int F_16 ( struct V_5 * V_6 ,
unsigned int V_51 )
{
unsigned int V_52 ;
switch ( V_6 -> V_38 -> V_53 ) {
case V_54 :
V_52 = V_55 ;
break;
case V_56 :
V_52 = V_57 ;
break;
case V_58 :
default:
V_52 = V_59 ;
break;
}
return ( V_51 * 1000 + V_52 - 1 ) / V_52 ;
}
static unsigned int F_17 ( struct V_5 * V_6 ,
unsigned int V_60 )
{
unsigned int V_52 ;
switch ( V_6 -> V_38 -> V_53 ) {
case V_54 :
V_52 = V_55 ;
break;
case V_56 :
V_52 = V_57 ;
break;
case V_58 :
default:
V_52 = V_59 ;
break;
}
return ( V_60 * V_52 ) / 1000 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 = NULL ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
unsigned long V_66 ;
if ( ! ( V_6 -> V_7 & V_67 ) )
return - V_24 ;
if ( NULL == V_6 -> V_38 )
return - V_39 ;
V_41 = V_6 -> V_41 [ 0 ] ;
V_43 = V_6 -> V_43 [ 0 ] ;
V_63 = F_19 ( V_41 -> V_47 ) ;
V_64 = F_12 ( V_41 -> V_47 ) ;
V_65 = F_19 ( V_43 -> V_45 ) ;
V_66 = F_12 ( V_43 -> V_45 ) ;
V_62 -> V_68 = F_17 ( V_6 , V_63 ) ;
V_62 -> V_69 = V_64 ;
V_62 -> V_70 = F_17 ( V_6 , V_65 ) ;
V_62 -> V_71 = V_66 ;
V_62 -> V_72 = 0 ;
V_62 -> V_73 = 0 ;
V_62 -> V_74 = 0 ;
V_62 -> V_75 = 0 ;
V_62 -> V_76 = 0 ;
V_62 -> V_77 = 0 ;
V_62 -> V_78 = 0 ;
V_62 -> V_79 = 0 ;
V_62 -> V_80 = 0 ;
V_62 -> V_81 = 0 ;
V_62 -> V_82 = 0 ;
V_62 -> V_83 = 0 ;
V_62 -> V_84 = 0 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 , V_85 = 0 ;
if ( ! ( V_6 -> V_7 & V_67 ) )
return - V_24 ;
if ( NULL == V_6 -> V_38 )
return - V_39 ;
if ( V_62 -> V_68 > V_86 ) {
F_21 ( V_2 , L_2 ,
V_86 ) ;
return - V_87 ;
}
if ( V_62 -> V_69 > V_88 ) {
F_21 ( V_2 , L_3 ,
V_88 ) ;
return - V_87 ;
}
if ( V_62 -> V_70 > V_86 ) {
F_21 ( V_2 , L_2 ,
V_86 ) ;
return - V_87 ;
}
if ( V_62 -> V_71 > V_88 ) {
F_21 ( V_2 , L_3 ,
V_88 ) ;
return - V_87 ;
}
while ( F_22 ( V_89 , & V_6 -> V_90 ) )
F_23 () ;
if ( ( V_62 -> V_68 == 0 ) ||
( V_62 -> V_69 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ )
V_6 -> V_41 [ V_15 ] -> V_92 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ )
V_6 -> V_41 [ V_15 ] -> V_92 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ ) {
V_6 -> V_41 [ V_15 ] -> V_47 = F_24 (
V_62 -> V_69 ,
F_16 ( V_6 , V_62 -> V_68 ) ) ;
}
if ( ( V_62 -> V_70 == 0 ) ||
( V_62 -> V_71 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_93 ; V_15 ++ )
V_6 -> V_43 [ V_15 ] -> V_94 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_93 ; V_15 ++ )
V_6 -> V_43 [ V_15 ] -> V_94 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_93 ; V_15 ++ ) {
V_6 -> V_43 [ V_15 ] -> V_45 = F_24 (
V_62 -> V_71 ,
F_16 ( V_6 , V_62 -> V_70 ) ) ;
}
if ( V_2 -> V_95 & V_96 ) {
F_25 ( V_2 ) ;
V_85 = F_26 ( V_2 ) ;
} else {
F_27 ( V_6 ) ;
}
F_28 ( V_89 , & V_6 -> V_90 ) ;
return V_85 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_42 * V_43 = NULL ;
struct V_40 * V_41 = NULL ;
V_43 = V_6 -> V_43 [ 0 ] ;
V_41 = V_6 -> V_41 [ 0 ] ;
V_98 -> V_99 = V_100 ;
V_98 -> V_101 = V_100 ;
V_98 -> V_102 = V_100 ;
V_98 -> V_103 = V_104 ;
V_98 -> V_105 = V_41 -> V_106 ;
V_98 -> V_107 = V_41 -> V_106 ;
V_98 -> V_108 = V_41 -> V_106 ;
V_98 -> V_109 = V_43 -> V_110 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_85 = 0 , V_15 ;
if ( V_98 -> V_105 > V_100 )
return - V_87 ;
if ( ! F_31 ( V_98 -> V_105 ) ) {
F_32 ( V_2 , L_4 ) ;
return - V_87 ;
}
if ( V_98 -> V_109 > V_104 )
return - V_87 ;
if ( ! F_31 ( V_98 -> V_109 ) ) {
F_32 ( V_2 , L_4 ) ;
return - V_87 ;
}
while ( F_22 ( V_89 , & V_6 -> V_90 ) )
F_23 () ;
if ( V_2 -> V_95 & V_96 )
F_25 ( V_2 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ )
V_6 -> V_41 [ V_15 ] -> V_106 = V_98 -> V_105 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_93 ; V_15 ++ )
V_6 -> V_43 [ V_15 ] -> V_110 = V_98 -> V_109 ;
if ( V_2 -> V_95 & V_96 )
V_85 = F_26 ( V_2 ) ;
F_28 ( V_89 , & V_6 -> V_90 ) ;
return V_85 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_112 -> V_113 = ! ! V_6 -> V_114 ;
V_112 -> V_115 = ! ! V_6 -> V_116 ;
V_112 -> V_117 = ! ! V_6 -> V_118 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_111 * V_112 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_37 * V_38 = V_6 -> V_38 ;
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_1 V_119 , V_120 ;
if ( ! V_38 )
return - V_39 ;
if ( ! ( V_38 -> V_121 & V_122 ) ||
( ! ( V_38 -> V_121 & V_123 ) &&
( V_112 -> V_115 != V_112 -> V_117 ) ) )
return - V_87 ;
V_6 -> V_116 = V_6 -> V_118 = 0 ;
if ( V_112 -> V_115 ) {
V_6 -> V_116 = 1 ;
if ( V_112 -> V_117 ) {
V_6 -> V_118 = 1 ;
V_120 = V_124 ;
} else
V_120 = V_124 | V_125 ;
} else if ( V_112 -> V_117 ) {
V_6 -> V_118 = 1 ;
V_120 = V_125 ;
} else
V_120 = 0 ;
if ( V_112 -> V_113 )
V_6 -> V_114 = 1 ;
else
V_6 -> V_114 = 0 ;
V_119 = V_38 -> V_126 &
( V_124 | V_125 ) ;
if ( V_119 != V_120 ) {
V_38 -> V_126 &=
~ ( V_124 | V_125 ) ;
V_38 -> V_126 |= V_120 ;
if ( V_38 -> V_113 )
return F_35 ( V_38 ) ;
if ( ! V_112 -> V_113 ) {
T_1 V_127 ;
V_127 = F_5 ( & V_17 -> V_128 ) ;
V_127 &= ~ ( V_129 | V_130 ) ;
V_6 -> V_131 = 0 ;
if ( V_6 -> V_118 ) {
V_6 -> V_131 = 1 ;
V_127 |= V_129 ;
}
if ( V_6 -> V_116 )
V_127 |= V_130 ;
F_36 ( & V_17 -> V_128 , V_127 ) ;
}
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 , T_6 V_132 )
{
T_6 V_133 = V_2 -> V_132 ^ V_132 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_85 = 0 ;
if ( ! ( V_133 & ( V_134 | V_135 |
V_136 ) ) )
return 0 ;
while ( F_22 ( V_89 , & V_6 -> V_90 ) )
F_23 () ;
V_2 -> V_132 = V_132 ;
if ( V_2 -> V_95 & V_96 ) {
F_25 ( V_2 ) ;
V_85 = F_26 ( V_2 ) ;
} else {
F_27 ( V_6 ) ;
}
F_28 ( V_89 , & V_6 -> V_90 ) ;
return V_85 ;
}
static T_7 F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_137 ;
}
static void F_39 ( struct V_1 * V_2 , T_7 V_138 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_137 = V_138 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 & V_141 ) {
V_140 -> V_121 = V_142 ;
V_140 -> V_143 = V_6 -> V_144 ? V_142 : 0 ;
} else {
V_140 -> V_121 = V_140 -> V_143 = 0 ;
}
}
static int F_41 ( struct V_1 * V_2 , struct V_139 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_7 & V_141 ) &&
V_140 -> V_143 != 0 )
return - V_87 ;
if ( V_140 -> V_143 & ~ V_142 )
return - V_87 ;
F_42 ( & V_2 -> V_2 , V_140 -> V_143 & V_142 ) ;
V_6 -> V_144 = ! ! F_43 ( & V_2 -> V_2 ) ;
return 0 ;
}
static void F_44 ( struct V_5 * V_6 , T_3 V_145 )
{
T_1 V_146 = 0x0 , V_147 = V_148 ;
if ( V_145 & V_149 ) {
V_146 = V_150 | V_151 |
V_152 | V_153 | V_154 ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
V_146 = V_158 | V_153 | V_151 |
V_152 | V_153 | V_154 ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
if ( V_145 & V_159 ) {
V_146 = V_160 | V_151 | V_152 |
V_153 | V_154 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
if ( V_145 & V_161 ) {
V_146 = V_162 | V_151 | V_152 |
V_153 | V_154 ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
if ( V_145 & ( V_163 ) ) {
V_146 = V_164 | V_151 | V_152 |
V_153 | V_154 ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
if ( V_145 & V_165 ) {
V_146 = V_166 | V_151 | V_152 |
V_153 | V_154 ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
if ( V_145 & V_167 ) {
V_146 = V_168 | V_151 | V_152 |
V_153 | V_154 ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
if ( V_145 & V_169 ) {
V_146 = V_170 | V_151 | V_152 |
V_153 | V_154 ;
V_6 -> V_155 [ V_6 -> V_156 ] = V_147 ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_146 ;
F_45 ( V_6 , V_6 -> V_156 , V_146 , V_147 ) ;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
}
static int F_46 ( struct V_5 * V_6 , T_3 V_145 ,
T_3 V_171 )
{
unsigned int V_172 = V_6 -> V_156 ;
unsigned int V_173 ;
unsigned int * V_174 ;
unsigned int * V_175 ;
int V_15 = 0x0 , V_176 = 0x0 ;
int V_177 = V_178 , V_179 = 0x0 ;
int V_180 = 1 ;
V_174 = F_47 ( V_178 + 1 , sizeof( unsigned int ) ,
V_181 ) ;
V_175 = F_47 ( V_178 + 1 , sizeof( unsigned int ) ,
V_181 ) ;
if ( ! V_174 || ! V_175 ) {
V_180 = 0 ;
goto V_85;
}
switch ( V_171 ) {
case V_182 :
V_173 = V_183 | V_184 ;
break;
case V_185 :
V_173 = V_183 | V_186 ;
break;
case V_187 :
V_173 = V_188 | V_184 ;
break;
case V_189 :
V_173 = V_188 | V_186 ;
break;
default:
F_32 ( V_6 -> V_190 ,
L_5 ) ;
V_180 = 0 ;
goto V_85;
}
for ( V_15 = 0 ; V_15 < V_178 + 1 ; V_15 ++ ) {
V_174 [ V_177 ] = V_6 -> V_155 [ V_15 ] ;
V_175 [ V_177 ] = V_6 -> V_157 [ V_15 ] ;
V_177 -- ;
if ( ( V_6 -> V_157 [ V_15 ] ==
( V_191 | V_192 | V_153 ) ) &&
( V_6 -> V_155 [ V_15 ] == V_173 ) )
break;
}
if ( V_15 == V_178 + 1 ) {
F_32 ( V_6 -> V_190 ,
L_6 ) ;
V_180 = 0 ;
goto V_85;
}
for ( V_179 = V_15 + 1 ; V_179 < V_178 ; V_179 ++ ) {
if ( ( V_6 -> V_157 [ V_179 ] & V_192 ) &&
! ( V_6 -> V_157 [ V_179 ] & V_153 ) ) {
V_6 -> V_157 [ V_179 ] = V_192 | V_193 |
V_154 | V_194 ;
V_6 -> V_155 [ V_179 ] = V_148 ;
F_45 ( V_6 , V_179 , V_6 -> V_157 [ V_179 ] ,
V_6 -> V_155 [ V_179 ] ) ;
break;
}
if ( ! ( V_6 -> V_157 [ V_179 ] & V_192 ) &&
( V_6 -> V_157 [ V_179 ] & V_153 ) )
continue;
else {
V_174 [ V_177 ] = V_6 -> V_155 [ V_179 ] ;
V_175 [ V_177 ] = V_6 -> V_157 [ V_179 ] ;
V_177 -- ;
}
}
V_6 -> V_156 = V_179 - 1 ;
V_172 = V_179 ;
F_44 ( V_6 , V_145 ) ;
for ( V_176 = V_177 + 1 ; V_176 < V_178 ; V_176 ++ ) {
V_6 -> V_155 [ V_6 -> V_156 ] = V_174 [ V_176 ] ;
V_6 -> V_157 [ V_6 -> V_156 ] = V_175 [ V_176 ] ;
F_45 ( V_6 , V_6 -> V_156 ,
V_175 [ V_176 ] , V_174 [ V_176 ] ) ;
if ( ! V_6 -> V_156 )
break;
V_6 -> V_156 = V_6 -> V_156 - 1 ;
}
V_85:
F_48 ( V_175 ) ;
F_48 ( V_174 ) ;
return V_180 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_195 * V_36 )
{
if ( ! F_46 ( V_6 , V_36 -> V_138 , V_36 -> V_196 ) )
return - V_87 ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_1 V_15 ;
V_15 = F_5 ( & V_17 -> V_197 ) ;
V_15 &= V_198 ;
if ( V_15 == V_198 ) {
F_51 ( V_6 -> V_190 , L_7 ) ;
V_15 = F_5 ( & V_17 -> V_199 ) ;
V_15 &= V_200 | V_201 ;
if ( V_15 == ( V_200 | V_201 ) ) {
F_21 ( V_6 -> V_190 ,
L_8 ) ;
} else {
F_52 ( V_6 -> V_190 ,
L_9 ) ;
return - V_24 ;
}
}
else {
V_15 = F_5 ( & V_17 -> V_199 ) ;
V_15 &= V_200 ;
if ( V_15 == V_200 ) {
F_21 ( V_6 -> V_190 ,
L_8 ) ;
} else {
F_52 ( V_6 -> V_190 ,
L_9 ) ;
return - V_24 ;
}
}
F_36 ( & V_17 -> V_202 , 0xC0C1C2C3 ) ;
return 0 ;
}
static void F_53 ( T_1 V_203 , struct V_204 * V_205 )
{
V_205 -> V_206 [ V_205 -> V_207 ] . V_208 = V_153 | V_194 | V_193 ;
V_205 -> V_206 [ V_205 -> V_207 ] . V_209 = V_203 ;
V_205 -> V_207 ++ ;
}
static void F_54 ( T_1 V_210 , T_1 V_203 , struct V_204 * V_205 )
{
F_53 ( V_203 , V_205 ) ;
V_205 -> V_206 [ V_205 -> V_207 ] . V_208 = V_193 | V_191 |
V_153 ;
V_205 -> V_206 [ V_205 -> V_207 ] . V_209 = V_210 ;
V_205 -> V_207 ++ ;
}
static void F_55 ( T_1 V_210 , T_1 V_203 , T_1 V_211 ,
struct V_204 * V_205 )
{
F_53 ( V_203 , V_205 ) ;
V_205 -> V_206 [ V_205 -> V_207 ] . V_208 = V_193 | V_153 | V_211 ;
V_205 -> V_206 [ V_205 -> V_207 ] . V_209 = V_210 ;
V_205 -> V_207 ++ ;
}
static void F_56 ( T_1 V_210 , T_1 V_203 , T_1 V_211 ,
struct V_204 * V_205 )
{
switch ( V_211 ) {
case V_212 :
if ( ! ( V_210 | V_203 ) )
return;
V_203 |= V_213 ;
break;
case V_166 :
case V_214 :
if ( ! ~ ( V_203 | V_215 ) )
return;
if ( ! V_203 )
V_203 = ~ 0 ;
else
V_203 |= V_215 ;
break;
case V_160 :
if ( ! ( V_210 | V_203 ) )
return;
V_203 |= V_216 ;
break;
case V_170 :
case V_168 :
case V_217 :
if ( ! ~ ( V_203 | V_218 ) )
return;
if ( ! V_203 )
V_203 = ~ 0 ;
else
V_203 |= V_218 ;
break;
case V_150 :
case V_158 :
case V_219 :
case V_220 :
if ( ! ( V_210 | V_203 ) )
return;
V_203 |= V_221 ;
break;
default:
if ( ! ~ V_203 )
return;
if ( ! V_203 )
V_203 = ~ 0 ;
break;
}
F_55 ( V_210 , V_203 , V_211 , V_205 ) ;
}
static void F_57 ( struct V_222 * V_210 ,
struct V_222 * V_203 ,
struct V_204 * V_205 )
{
F_56 ( F_58 ( V_210 -> V_223 ) ,
F_58 ( V_203 -> V_223 ) ,
V_162 , V_205 ) ;
F_56 ( F_58 ( V_210 -> V_224 ) ,
F_58 ( V_203 -> V_224 ) ,
V_164 , V_205 ) ;
F_56 ( F_59 ( V_210 -> V_225 ) ,
F_59 ( V_203 -> V_225 ) ,
V_170 , V_205 ) ;
F_56 ( F_59 ( V_210 -> V_226 ) ,
F_59 ( V_203 -> V_226 ) ,
V_168 , V_205 ) ;
F_56 ( V_210 -> V_227 , V_203 -> V_227 , V_214 , V_205 ) ;
}
static void F_60 ( struct V_228 * V_210 ,
struct V_228 * V_203 ,
struct V_204 * V_205 )
{
F_56 ( F_58 ( V_210 -> V_223 ) ,
F_58 ( V_203 -> V_223 ) ,
V_162 , V_205 ) ;
F_56 ( F_58 ( V_210 -> V_224 ) ,
F_58 ( V_203 -> V_224 ) ,
V_164 , V_205 ) ;
F_56 ( V_210 -> V_227 , V_203 -> V_227 , V_214 , V_205 ) ;
F_56 ( V_210 -> V_229 , V_203 -> V_229 , V_166 , V_205 ) ;
F_56 ( F_58 ( V_210 -> V_230 ) ,
F_58 ( V_203 -> V_230 ) ,
V_231 , V_205 ) ;
}
static void F_61 ( struct V_232 * V_210 , struct V_232 * V_203 ,
struct V_204 * V_205 )
{
T_1 V_233 = 0 ;
T_1 V_234 = 0 ;
if ( ! F_62 ( V_203 -> V_235 ) ) {
if ( F_63 ( V_203 -> V_235 ) ) {
V_233 = 0xFFFFFFFF ;
V_234 = 0xFFFFFFFF ;
} else {
V_233 = V_203 -> V_235 [ 0 ] << 16 |
V_203 -> V_235 [ 1 ] << 8 |
V_203 -> V_235 [ 2 ] ;
V_234 = V_203 -> V_235 [ 3 ] << 16 |
V_203 -> V_235 [ 4 ] << 8 |
V_203 -> V_235 [ 5 ] ;
}
F_56 ( V_210 -> V_235 [ 0 ] << 16 |
V_210 -> V_235 [ 1 ] << 8 |
V_210 -> V_235 [ 2 ] ,
V_233 , V_219 , V_205 ) ;
F_56 ( V_210 -> V_235 [ 3 ] << 16 |
V_210 -> V_235 [ 4 ] << 8 |
V_210 -> V_235 [ 5 ] ,
V_234 , V_220 , V_205 ) ;
}
if ( ! F_62 ( V_203 -> V_236 ) ) {
if ( ( F_62 ( V_210 -> V_236 ) &&
F_63 ( V_203 -> V_236 ) ) ) {
F_54 ( V_237 , V_237 , V_205 ) ;
} else {
if ( F_63 ( V_203 -> V_236 ) ) {
V_233 = 0xFFFFFFFF ;
V_234 = 0xFFFFFFFF ;
} else {
V_233 = V_203 -> V_236 [ 0 ] << 16 |
V_203 -> V_236 [ 1 ] << 8 |
V_203 -> V_236 [ 2 ] ;
V_234 = V_203 -> V_236 [ 3 ] << 16 |
V_203 -> V_236 [ 4 ] << 8 |
V_203 -> V_236 [ 5 ] ;
}
F_56 ( V_210 -> V_236 [ 0 ] << 16 |
V_210 -> V_236 [ 1 ] << 8 |
V_210 -> V_236 [ 2 ] ,
V_233 , V_150 , V_205 ) ;
F_56 ( V_210 -> V_236 [ 3 ] << 16 |
V_210 -> V_236 [ 4 ] << 8 |
V_210 -> V_236 [ 5 ] ,
V_234 , V_158 , V_205 ) ;
}
}
F_56 ( F_59 ( V_210 -> V_238 ) ,
F_59 ( V_203 -> V_238 ) ,
V_217 , V_205 ) ;
}
static inline T_1 F_64 ( struct V_239 * V_240 )
{
return F_59 ( V_240 -> V_241 . V_242 ) & V_243 ;
}
static inline T_1 F_65 ( struct V_239 * V_240 )
{
return F_59 ( V_240 -> V_244 . V_242 ) & V_243 ;
}
static inline T_1 F_66 ( struct V_239 * V_240 )
{
return F_59 ( V_240 -> V_241 . V_242 ) & V_245 ;
}
static inline T_1 F_67 ( struct V_239 * V_240 )
{
return F_59 ( V_240 -> V_244 . V_242 ) & V_245 ;
}
static inline T_1 F_68 ( struct V_239 * V_240 )
{
return ( F_59 ( V_240 -> V_241 . V_242 ) & V_246 ) >>
V_247 ;
}
static inline T_1 F_69 ( struct V_239 * V_240 )
{
return ( F_59 ( V_240 -> V_244 . V_242 ) & V_246 ) >>
V_247 ;
}
static int F_70 ( struct V_239 * V_240 ,
struct V_204 * V_205 )
{
T_1 V_248 = 0 , V_249 = 0 ;
T_1 V_250 = 0 , V_251 = 0 ;
T_1 V_252 = 0 , V_253 = 0 ;
T_1 V_254 = 0 , V_255 = 0 ;
T_1 V_256 = V_205 -> V_207 ;
if ( ( V_240 -> V_196 & V_257 ) &&
( V_240 -> V_244 . V_242 != F_71 ( 0xFFFF ) ) ) {
if ( ! V_240 -> V_244 . V_242 )
V_240 -> V_244 . V_242 = F_71 ( 0xFFFF ) ;
V_248 = V_258 ;
V_249 = V_258 ;
V_250 = F_64 ( V_240 ) ;
V_251 = F_65 ( V_240 ) ;
V_252 = F_66 ( V_240 ) ;
V_253 = F_67 ( V_240 ) ;
V_254 = F_68 ( V_240 ) ;
V_255 = F_69 ( V_240 ) ;
if ( V_252 == V_259 && V_253 == V_259 ) {
V_248 |= V_260 ;
V_249 |= V_260 ;
} else if ( V_252 != V_259 &&
V_253 == V_259 ) {
V_249 |= V_260 ;
}
}
switch ( V_240 -> V_196 & ~ V_257 ) {
case V_182 :
F_54 ( V_183 | V_184 | V_248 ,
V_183 | V_184 | V_249 , V_205 ) ;
F_57 ( & V_240 -> V_261 . V_262 ,
& V_240 -> V_263 . V_262 , V_205 ) ;
break;
case V_185 :
F_54 ( V_183 | V_186 | V_248 ,
V_183 | V_186 | V_249 , V_205 ) ;
F_57 ( & V_240 -> V_261 . V_264 ,
& V_240 -> V_263 . V_264 , V_205 ) ;
break;
case V_265 :
F_54 ( V_183 | V_248 , V_183 | V_249 ,
V_205 ) ;
F_56 ( 132 , 0 , V_166 , V_205 ) ;
F_57 ( (struct V_222 * ) & V_240 -> V_261 ,
(struct V_222 * ) & V_240 -> V_263 ,
V_205 ) ;
break;
case V_266 :
F_54 ( V_183 | V_248 , V_183 | V_249 ,
V_205 ) ;
F_60 ( (struct V_228 * ) & V_240 -> V_261 ,
(struct V_228 * ) & V_240 -> V_263 ,
V_205 ) ;
break;
case V_267 :
if ( V_248 )
F_54 ( V_248 , V_249 , V_205 ) ;
F_61 ( (struct V_232 * ) & V_240 -> V_261 ,
(struct V_232 * ) & V_240 -> V_263 , V_205 ) ;
break;
default:
return - 1 ;
}
if ( V_248 ) {
F_56 ( V_250 , V_251 , V_160 , V_205 ) ;
F_56 ( V_254 , V_255 , V_212 , V_205 ) ;
}
if ( V_205 -> V_207 == V_256 ) {
F_53 ( 0xFFFFFFFF , V_205 ) ;
V_205 -> V_206 [ V_205 -> V_207 ] . V_208 = 0x20 ;
V_205 -> V_206 [ V_205 -> V_207 ] . V_209 = 0x0 ;
V_205 -> V_207 ++ ;
}
V_205 -> V_206 [ V_205 -> V_207 - 1 ] . V_208 &= ( ~ V_153 ) ;
if ( V_240 -> V_268 == V_269 )
V_205 -> V_206 [ V_205 -> V_207 - 1 ] . V_208 |= V_270 ;
else
V_205 -> V_206 [ V_205 -> V_207 - 1 ] . V_208 |= ( V_240 -> V_268 << 10 ) ;
if ( V_205 -> V_207 > ( V_256 + 2 ) ) {
V_205 -> V_206 [ V_256 + 1 ] . V_208 |= V_192 ;
V_205 -> V_206 [ V_205 -> V_207 - 1 ] . V_208 |= V_192 ;
}
if ( V_205 -> V_207 > V_271 - 1 )
return - V_272 ;
return 0 ;
}
static int F_72 ( struct V_5 * V_6 ,
struct V_204 * V_205 )
{
T_1 V_15 = 0 ;
if ( V_205 -> V_207 > V_178 - 1 )
return - V_272 ;
for (; V_15 < V_178 && ( V_205 -> V_206 [ V_15 ] . V_208 | V_205 -> V_206 [ V_15 ] . V_209 ) ; V_15 ++ )
F_45 ( V_6 , V_15 , V_205 -> V_206 [ V_15 ] . V_208 , V_205 -> V_206 [ V_15 ] . V_209 ) ;
for (; V_15 < V_178 ; V_15 ++ )
F_45 ( V_6 , V_15 , 0x60 , 0xFFFFFFFF ) ;
F_45 ( V_6 , V_15 , 0x20 , 0x0 ) ;
return 0 ;
}
static int F_73 ( struct V_239 * V_273 ,
struct V_5 * V_6 )
{
if ( V_273 -> V_196 & V_257 ) {
if ( ~ V_273 -> V_244 . V_138 [ 0 ] || ~ V_273 -> V_244 . V_138 [ 1 ] )
F_52 ( V_6 -> V_190 ,
L_10 ) ;
if ( ~ V_273 -> V_244 . V_274 )
F_52 ( V_6 -> V_190 ,
L_11 ) ;
}
if ( V_273 -> V_196 == V_266 )
if ( V_273 -> V_261 . V_275 . V_276 != V_277 )
F_52 ( V_6 -> V_190 ,
L_12 ) ;
return 0 ;
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_278 * V_177 ;
struct V_204 * V_205 ;
T_8 V_180 = 0 ;
V_205 = F_75 ( sizeof( * V_205 ) , V_181 ) ;
if ( V_205 == NULL )
return - V_279 ;
F_76 (j, &priv->rx_list.list, list) {
V_180 = F_70 ( & V_177 -> V_280 , V_205 ) ;
if ( V_180 == - V_272 ) {
F_32 ( V_6 -> V_190 ,
L_13 ) ;
goto V_281;
}
if ( V_180 == - 1 ) {
F_32 ( V_6 -> V_190 ,
L_14 ) ;
goto V_281;
}
}
V_180 = F_72 ( V_6 , V_205 ) ;
if ( V_180 == - V_272 ) {
F_32 ( V_6 -> V_190 , L_13 ) ;
goto V_281;
}
V_281:
F_48 ( V_205 ) ;
return V_180 ;
}
static void F_77 ( struct V_239 * V_273 )
{
T_1 V_15 = 0 ;
for ( V_15 = 0 ; V_15 < sizeof( V_273 -> V_263 ) ; V_15 ++ )
V_273 -> V_263 . V_282 [ V_15 ] ^= 0xFF ;
V_273 -> V_244 . V_274 ^= F_71 ( 0xFFFF ) ;
V_273 -> V_244 . V_242 ^= F_71 ( 0xFFFF ) ;
V_273 -> V_244 . V_138 [ 0 ] ^= F_78 ( ~ 0 ) ;
V_273 -> V_244 . V_138 [ 1 ] ^= F_78 ( ~ 0 ) ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_239 * V_273 )
{
struct V_278 * V_283 , * V_284 ;
int V_180 = 0 ;
V_283 = F_80 ( sizeof( * V_283 ) , V_181 ) ;
if ( V_283 == NULL )
return - V_279 ;
memcpy ( & V_283 -> V_280 , V_273 , sizeof( V_283 -> V_280 ) ) ;
F_77 ( & V_283 -> V_280 ) ;
V_180 = F_73 ( & V_283 -> V_280 , V_6 ) ;
if ( V_180 )
goto V_285;
if ( F_81 ( & V_6 -> V_286 . V_287 ) ) {
V_180 = F_50 ( V_6 ) ;
if ( V_180 != 0 )
goto V_285;
F_82 ( & V_283 -> V_287 , & V_6 -> V_286 . V_287 ) ;
goto V_288;
} else {
F_76 (comp, &priv->rx_list.list, list) {
if ( V_284 -> V_280 . V_289 > V_273 -> V_289 ) {
F_83 ( & V_283 -> V_287 , & V_284 -> V_287 ) ;
goto V_288;
}
if ( V_284 -> V_280 . V_289 == V_273 -> V_289 ) {
F_32 ( V_6 -> V_190 ,
L_15 ,
V_273 -> V_289 ) ;
V_180 = - V_272 ;
goto V_285;
}
}
F_83 ( & V_283 -> V_287 , & V_6 -> V_286 . V_287 ) ;
}
V_288:
V_6 -> V_286 . V_52 ++ ;
V_180 = F_74 ( V_6 ) ;
if ( V_180 )
goto V_290;
return V_180 ;
V_290:
V_6 -> V_286 . V_52 -- ;
F_84 ( & V_283 -> V_287 ) ;
V_285:
F_48 ( V_283 ) ;
return V_180 ;
}
static int F_85 ( struct V_5 * V_6 , T_1 V_291 )
{
struct V_278 * V_284 ;
T_1 V_180 = - V_87 ;
if ( F_81 ( & V_6 -> V_286 . V_287 ) )
return V_180 ;
F_76 (comp, &priv->rx_list.list, list) {
if ( V_284 -> V_280 . V_289 == V_291 ) {
F_84 ( & V_284 -> V_287 ) ;
F_48 ( V_284 ) ;
V_6 -> V_286 . V_52 -- ;
F_74 ( V_6 ) ;
V_180 = 0 ;
break;
}
}
return V_180 ;
}
static int F_86 ( struct V_5 * V_6 , struct V_195 * V_36 )
{
struct V_278 * V_284 ;
T_1 V_180 = - V_87 ;
F_76 (comp, &priv->rx_list.list, list) {
if ( V_284 -> V_280 . V_289 == V_36 -> V_280 . V_289 ) {
memcpy ( & V_36 -> V_280 , & V_284 -> V_280 , sizeof( V_36 -> V_280 ) ) ;
F_77 ( & V_36 -> V_280 ) ;
V_180 = 0 ;
break;
}
}
return V_180 ;
}
static int F_87 ( struct V_5 * V_6 ,
struct V_195 * V_36 , T_1 * V_292 )
{
struct V_278 * V_284 ;
T_1 V_15 = 0 ;
F_76 (comp, &priv->rx_list.list, list) {
if ( V_15 == V_36 -> V_293 )
return - V_294 ;
V_292 [ V_15 ] = V_284 -> V_280 . V_289 ;
V_15 ++ ;
}
V_36 -> V_138 = V_178 ;
V_36 -> V_293 = V_15 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_195 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_180 = 0 ;
if ( F_89 ( V_89 , & V_6 -> V_90 ) )
return - V_272 ;
F_90 ( & V_6 -> V_295 ) ;
switch ( V_36 -> V_36 ) {
case V_296 :
V_180 = F_49 ( V_6 , V_36 ) ;
break;
case V_297 :
if ( ( V_36 -> V_280 . V_268 != V_269 &&
V_36 -> V_280 . V_268 >= V_6 -> V_91 ) ||
V_36 -> V_280 . V_289 >= V_178 ) {
V_180 = - V_87 ;
break;
}
V_180 = F_79 ( V_6 , & V_36 -> V_280 ) ;
break;
case V_298 :
V_180 = F_85 ( V_6 , V_36 -> V_280 . V_289 ) ;
break;
default:
V_180 = - V_87 ;
}
F_91 ( & V_6 -> V_295 ) ;
return V_180 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_195 * V_36 ,
T_1 * V_292 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_180 = 0 ;
switch ( V_36 -> V_36 ) {
case V_299 :
V_36 -> V_138 = V_6 -> V_91 ;
break;
case V_300 :
V_36 -> V_293 = V_6 -> V_286 . V_52 ;
break;
case V_301 :
V_180 = F_86 ( V_6 , V_36 ) ;
break;
case V_302 :
V_180 = F_87 ( V_6 , V_36 , V_292 ) ;
break;
default:
V_180 = - V_87 ;
break;
}
return V_180 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_303 * V_304 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_7 & V_305 ) ) {
V_304 -> V_306 = V_307 |
V_308 ;
V_304 -> V_309 = - 1 ;
return 0 ;
}
V_304 -> V_306 = V_310 |
V_311 |
V_312 ;
V_304 -> V_309 = V_313 ;
V_304 -> V_314 = ( 1 << V_315 ) |
( 1 << V_316 ) ;
V_304 -> V_317 = ( 1 << V_318 ) |
( 1 << V_319 ) ;
return 0 ;
}
