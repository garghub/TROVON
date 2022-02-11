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
}
static int F_9 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = V_6 -> V_36 ;
if ( NULL == V_36 )
return - V_37 ;
return F_10 ( V_36 , V_34 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = V_6 -> V_36 ;
struct V_38 * V_39 = NULL ;
struct V_40 * V_41 = NULL ;
if ( NULL == V_36 )
return - V_37 ;
V_41 = V_6 -> V_41 [ 0 ] ;
V_39 = V_6 -> V_39 [ 0 ] ;
V_34 -> V_42 = F_12 ( V_41 -> V_43 ) ;
V_34 -> V_44 = F_12 ( V_39 -> V_45 ) ;
return F_13 ( V_36 , V_34 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return sizeof ( struct V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 , struct V_46 * V_17 ,
void * V_47 )
{
int V_15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 T_4 * V_48 = ( T_1 T_4 * ) V_6 -> V_18 [ 0 ] . V_17 ;
T_1 * V_4 = ( T_1 * ) V_47 ;
for ( V_15 = 0 ; V_15 < sizeof ( struct V_16 ) / sizeof ( T_1 ) ; V_15 ++ )
V_4 [ V_15 ] = F_5 ( & V_48 [ V_15 ] ) ;
}
static unsigned int F_16 ( struct V_5 * V_6 ,
unsigned int V_49 )
{
unsigned int V_50 ;
switch ( V_6 -> V_36 -> V_51 ) {
case V_52 :
V_50 = V_53 ;
break;
case V_54 :
V_50 = V_55 ;
break;
case V_56 :
default:
V_50 = V_57 ;
break;
}
return ( V_49 * 1000 + V_50 - 1 ) / V_50 ;
}
static unsigned int F_17 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
unsigned int V_50 ;
switch ( V_6 -> V_36 -> V_51 ) {
case V_52 :
V_50 = V_53 ;
break;
case V_54 :
V_50 = V_55 ;
break;
case V_56 :
default:
V_50 = V_57 ;
break;
}
return ( V_58 * V_50 ) / 1000 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = NULL ;
struct V_40 * V_41 = NULL ;
unsigned long V_61 ;
unsigned long V_62 ;
unsigned long V_63 ;
unsigned long V_64 ;
if ( ! ( V_6 -> V_7 & V_65 ) )
return - V_24 ;
if ( NULL == V_6 -> V_36 )
return - V_37 ;
V_39 = V_6 -> V_39 [ 0 ] ;
V_41 = V_6 -> V_41 [ 0 ] ;
V_61 = F_19 ( V_39 -> V_45 ) ;
V_62 = F_12 ( V_39 -> V_45 ) ;
V_63 = F_19 ( V_41 -> V_43 ) ;
V_64 = F_12 ( V_41 -> V_43 ) ;
V_60 -> V_66 = F_17 ( V_6 , V_61 ) ;
V_60 -> V_67 = V_62 ;
V_60 -> V_68 = F_17 ( V_6 , V_63 ) ;
V_60 -> V_69 = V_64 ;
V_60 -> V_70 = 0 ;
V_60 -> V_71 = 0 ;
V_60 -> V_72 = 0 ;
V_60 -> V_73 = 0 ;
V_60 -> V_74 = 0 ;
V_60 -> V_75 = 0 ;
V_60 -> V_76 = 0 ;
V_60 -> V_77 = 0 ;
V_60 -> V_78 = 0 ;
V_60 -> V_79 = 0 ;
V_60 -> V_80 = 0 ;
V_60 -> V_81 = 0 ;
V_60 -> V_82 = 0 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 , V_83 = 0 ;
if ( ! ( V_6 -> V_7 & V_65 ) )
return - V_24 ;
if ( NULL == V_6 -> V_36 )
return - V_37 ;
if ( V_60 -> V_66 > V_84 ) {
F_21 ( V_2 , L_2 ,
V_84 ) ;
return - V_85 ;
}
if ( V_60 -> V_67 > V_86 ) {
F_21 ( V_2 , L_3 ,
V_86 ) ;
return - V_85 ;
}
if ( V_60 -> V_68 > V_84 ) {
F_21 ( V_2 , L_2 ,
V_84 ) ;
return - V_85 ;
}
if ( V_60 -> V_69 > V_86 ) {
F_21 ( V_2 , L_3 ,
V_86 ) ;
return - V_85 ;
}
while ( F_22 ( V_87 , & V_6 -> V_88 ) )
F_23 () ;
if ( ( V_60 -> V_66 == 0 ) ||
( V_60 -> V_67 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ )
V_6 -> V_39 [ V_15 ] -> V_90 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ )
V_6 -> V_39 [ V_15 ] -> V_90 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ ) {
V_6 -> V_39 [ V_15 ] -> V_45 = F_24 (
V_60 -> V_67 ,
F_16 ( V_6 , V_60 -> V_66 ) ) ;
}
if ( ( V_60 -> V_68 == 0 ) ||
( V_60 -> V_69 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ )
V_6 -> V_41 [ V_15 ] -> V_92 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ )
V_6 -> V_41 [ V_15 ] -> V_92 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ ) {
V_6 -> V_41 [ V_15 ] -> V_43 = F_24 (
V_60 -> V_69 ,
F_16 ( V_6 , V_60 -> V_68 ) ) ;
}
if ( V_2 -> V_93 & V_94 ) {
F_25 ( V_2 ) ;
V_83 = F_26 ( V_2 ) ;
} else {
F_27 ( V_6 ) ;
}
F_28 ( V_87 , & V_6 -> V_88 ) ;
return V_83 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_40 * V_41 = NULL ;
struct V_38 * V_39 = NULL ;
V_41 = V_6 -> V_41 [ 0 ] ;
V_39 = V_6 -> V_39 [ 0 ] ;
V_96 -> V_97 = V_98 ;
V_96 -> V_99 = V_98 ;
V_96 -> V_100 = V_98 ;
V_96 -> V_101 = V_102 ;
V_96 -> V_103 = V_39 -> V_104 ;
V_96 -> V_105 = V_39 -> V_104 ;
V_96 -> V_106 = V_39 -> V_104 ;
V_96 -> V_107 = V_41 -> V_108 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_83 = 0 , V_15 ;
if ( V_96 -> V_103 > V_98 )
return - V_85 ;
if ( ! F_31 ( V_96 -> V_103 ) ) {
F_32 ( V_2 , L_4 ) ;
return - V_85 ;
}
if ( V_96 -> V_107 > V_102 )
return - V_85 ;
if ( ! F_31 ( V_96 -> V_107 ) ) {
F_32 ( V_2 , L_4 ) ;
return - V_85 ;
}
while ( F_22 ( V_87 , & V_6 -> V_88 ) )
F_23 () ;
if ( V_2 -> V_93 & V_94 )
F_25 ( V_2 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_89 ; V_15 ++ )
V_6 -> V_39 [ V_15 ] -> V_104 = V_96 -> V_103 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_91 ; V_15 ++ )
V_6 -> V_41 [ V_15 ] -> V_108 = V_96 -> V_107 ;
if ( V_2 -> V_93 & V_94 )
V_83 = F_26 ( V_2 ) ;
F_28 ( V_87 , & V_6 -> V_88 ) ;
return V_83 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_110 -> V_111 = ! ! V_6 -> V_112 ;
V_110 -> V_113 = ! ! V_6 -> V_114 ;
V_110 -> V_115 = ! ! V_6 -> V_116 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_35 * V_36 = V_6 -> V_36 ;
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_1 V_117 , V_118 ;
if ( ! V_36 )
return - V_37 ;
if ( ! ( V_36 -> V_119 & V_120 ) ||
( ! ( V_36 -> V_119 & V_121 ) &&
( V_110 -> V_113 != V_110 -> V_115 ) ) )
return - V_85 ;
V_6 -> V_114 = V_6 -> V_116 = 0 ;
if ( V_110 -> V_113 ) {
V_6 -> V_114 = 1 ;
if ( V_110 -> V_115 ) {
V_6 -> V_116 = 1 ;
V_118 = V_122 ;
} else
V_118 = V_122 | V_123 ;
} else if ( V_110 -> V_115 ) {
V_6 -> V_116 = 1 ;
V_118 = V_123 ;
} else
V_118 = 0 ;
if ( V_110 -> V_111 )
V_6 -> V_112 = 1 ;
else
V_6 -> V_112 = 0 ;
V_117 = V_36 -> V_124 &
( V_122 | V_123 ) ;
if ( V_117 != V_118 ) {
V_36 -> V_124 &=
~ ( V_122 | V_123 ) ;
V_36 -> V_124 |= V_118 ;
if ( V_36 -> V_111 )
return F_35 ( V_36 ) ;
if ( ! V_110 -> V_111 ) {
T_1 V_125 ;
V_125 = F_5 ( & V_17 -> V_126 ) ;
V_125 &= ~ ( V_127 | V_128 ) ;
V_6 -> V_129 = 0 ;
if ( V_6 -> V_116 ) {
V_6 -> V_129 = 1 ;
V_125 |= V_127 ;
}
if ( V_6 -> V_114 )
V_125 |= V_128 ;
F_36 ( & V_17 -> V_126 , V_125 ) ;
}
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 , T_6 V_130 )
{
T_6 V_131 = V_2 -> V_130 ^ V_130 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_83 = 0 ;
if ( ! ( V_131 & ( V_132 | V_133 |
V_134 ) ) )
return 0 ;
while ( F_22 ( V_87 , & V_6 -> V_88 ) )
F_23 () ;
V_2 -> V_130 = V_130 ;
if ( V_2 -> V_93 & V_94 ) {
F_25 ( V_2 ) ;
V_83 = F_26 ( V_2 ) ;
} else {
F_27 ( V_6 ) ;
}
F_28 ( V_87 , & V_6 -> V_88 ) ;
return V_83 ;
}
static T_7 F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_135 ;
}
static void F_39 ( struct V_1 * V_2 , T_7 V_136 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_135 = V_136 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_137 * V_138 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_138 -> V_119 = 0 ;
V_138 -> V_139 = 0 ;
if ( V_6 -> V_140 & V_141 )
V_138 -> V_119 |= V_142 ;
if ( V_6 -> V_140 & V_143 )
V_138 -> V_119 |= V_144 ;
if ( V_6 -> V_145 & V_141 )
V_138 -> V_139 |= V_142 ;
if ( V_6 -> V_145 & V_143 )
V_138 -> V_139 |= V_144 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_137 * V_138 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_8 V_145 = 0 ;
int V_83 ;
if ( ! V_6 -> V_140 && V_138 -> V_139 )
return - V_85 ;
if ( V_138 -> V_139 & ~ ( V_142 | V_144 ) )
return - V_85 ;
if ( V_138 -> V_139 & V_142 ) {
V_145 |= V_141 ;
} else {
if ( V_138 -> V_139 & V_144 )
V_145 |= V_143 ;
}
V_145 &= V_6 -> V_140 ;
V_6 -> V_145 = 0 ;
V_83 = F_42 ( V_6 -> V_2 , V_145 ) ;
if ( V_83 )
return V_83 ;
V_6 -> V_145 = V_145 ;
return 0 ;
}
static void F_43 ( struct V_5 * V_6 , T_3 V_146 )
{
T_1 V_147 = 0x0 , V_148 = V_149 ;
if ( V_146 & V_150 ) {
V_147 = V_151 | V_152 |
V_153 | V_154 | V_155 ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
V_147 = V_159 | V_152 |
V_153 | V_154 | V_155 ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
if ( V_146 & V_160 ) {
V_147 = V_161 | V_152 | V_153 |
V_154 | V_155 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
if ( V_146 & V_162 ) {
V_147 = V_163 | V_152 | V_153 |
V_154 | V_155 ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
if ( V_146 & ( V_164 ) ) {
V_147 = V_165 | V_152 | V_153 |
V_154 | V_155 ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
if ( V_146 & V_166 ) {
V_147 = V_167 | V_152 | V_153 |
V_154 | V_155 ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
if ( V_146 & V_168 ) {
V_147 = V_169 | V_152 | V_153 |
V_154 | V_155 ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
if ( V_146 & V_170 ) {
V_147 = V_171 | V_152 | V_153 |
V_154 | V_155 ;
V_6 -> V_156 [ V_6 -> V_157 ] = V_148 ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_147 ;
F_44 ( V_6 , V_6 -> V_157 , V_147 , V_148 ) ;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
}
static int F_45 ( struct V_5 * V_6 , T_3 V_146 ,
T_3 V_172 )
{
unsigned int V_173 = V_6 -> V_157 ;
unsigned int V_174 ;
unsigned int * V_175 ;
unsigned int * V_176 ;
int V_15 = 0x0 , V_177 = 0x0 ;
int V_178 = V_179 , V_180 = 0x0 ;
int V_181 = 1 ;
V_175 = F_46 ( V_179 + 1 , sizeof( unsigned int ) ,
V_182 ) ;
V_176 = F_46 ( V_179 + 1 , sizeof( unsigned int ) ,
V_182 ) ;
if ( ! V_175 || ! V_176 ) {
V_181 = 0 ;
goto V_83;
}
switch ( V_172 ) {
case V_183 :
V_174 = V_184 | V_185 ;
break;
case V_186 :
V_174 = V_184 | V_187 ;
break;
case V_188 :
V_174 = V_189 | V_185 ;
break;
case V_190 :
V_174 = V_189 | V_187 ;
break;
default:
F_32 ( V_6 -> V_191 ,
L_5 ) ;
V_181 = 0 ;
goto V_83;
}
for ( V_15 = 0 ; V_15 < V_179 + 1 ; V_15 ++ ) {
V_175 [ V_178 ] = V_6 -> V_156 [ V_15 ] ;
V_176 [ V_178 ] = V_6 -> V_158 [ V_15 ] ;
V_178 -- ;
if ( ( V_6 -> V_158 [ V_15 ] ==
( V_192 | V_193 | V_154 ) ) &&
( V_6 -> V_156 [ V_15 ] == V_174 ) )
break;
}
if ( V_15 == V_179 + 1 ) {
F_32 ( V_6 -> V_191 ,
L_6 ) ;
V_181 = 0 ;
goto V_83;
}
for ( V_180 = V_15 + 1 ; V_180 < V_179 ; V_180 ++ ) {
if ( ( V_6 -> V_158 [ V_180 ] & V_193 ) &&
! ( V_6 -> V_158 [ V_180 ] & V_154 ) ) {
V_6 -> V_158 [ V_180 ] = V_193 | V_194 |
V_155 | V_195 ;
V_6 -> V_156 [ V_180 ] = V_149 ;
F_44 ( V_6 , V_180 , V_6 -> V_158 [ V_180 ] ,
V_6 -> V_156 [ V_180 ] ) ;
break;
}
if ( ! ( V_6 -> V_158 [ V_180 ] & V_193 ) &&
( V_6 -> V_158 [ V_180 ] & V_154 ) )
continue;
else {
V_175 [ V_178 ] = V_6 -> V_156 [ V_180 ] ;
V_176 [ V_178 ] = V_6 -> V_158 [ V_180 ] ;
V_178 -- ;
}
}
V_6 -> V_157 = V_180 - 1 ;
V_173 = V_180 ;
F_43 ( V_6 , V_146 ) ;
for ( V_177 = V_178 + 1 ; V_177 < V_179 ; V_177 ++ ) {
V_6 -> V_156 [ V_6 -> V_157 ] = V_175 [ V_177 ] ;
V_6 -> V_158 [ V_6 -> V_157 ] = V_176 [ V_177 ] ;
F_44 ( V_6 , V_6 -> V_157 ,
V_176 [ V_177 ] , V_175 [ V_177 ] ) ;
if ( ! V_6 -> V_157 )
break;
V_6 -> V_157 = V_6 -> V_157 - 1 ;
}
V_83:
F_47 ( V_176 ) ;
F_47 ( V_175 ) ;
return V_181 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_196 * V_34 )
{
if ( ! F_45 ( V_6 , V_34 -> V_136 , V_34 -> V_197 ) )
return - V_85 ;
return 0 ;
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_1 V_15 ;
V_15 = F_5 ( & V_17 -> V_198 ) ;
V_15 &= V_199 ;
if ( V_15 == V_199 ) {
F_50 ( V_6 -> V_191 , L_7 ) ;
V_15 = F_5 ( & V_17 -> V_200 ) ;
V_15 &= V_201 | V_202 ;
if ( V_15 == ( V_201 | V_202 ) ) {
F_21 ( V_6 -> V_191 ,
L_8 ) ;
} else {
F_51 ( V_6 -> V_191 ,
L_9 ) ;
return - V_24 ;
}
}
else {
V_15 = F_5 ( & V_17 -> V_200 ) ;
V_15 &= V_201 ;
if ( V_15 == V_201 ) {
F_21 ( V_6 -> V_191 ,
L_8 ) ;
} else {
F_51 ( V_6 -> V_191 ,
L_9 ) ;
return - V_24 ;
}
}
F_36 ( & V_17 -> V_203 , 0xC0C1C2C3 ) ;
return 0 ;
}
static void F_52 ( T_1 V_204 , struct V_205 * V_206 )
{
V_206 -> V_207 [ V_206 -> V_208 ] . V_209 = V_154 | V_195 | V_194 ;
V_206 -> V_207 [ V_206 -> V_208 ] . V_210 = V_204 ;
V_206 -> V_208 ++ ;
}
static void F_53 ( T_1 V_211 , T_1 V_204 , struct V_205 * V_206 )
{
F_52 ( V_204 , V_206 ) ;
V_206 -> V_207 [ V_206 -> V_208 ] . V_209 = V_194 | V_192 |
V_154 ;
V_206 -> V_207 [ V_206 -> V_208 ] . V_210 = V_211 ;
V_206 -> V_208 ++ ;
}
static void F_54 ( T_1 V_211 , T_1 V_204 , T_1 V_212 ,
struct V_205 * V_206 )
{
F_52 ( V_204 , V_206 ) ;
V_206 -> V_207 [ V_206 -> V_208 ] . V_209 = V_194 | V_154 | V_212 ;
V_206 -> V_207 [ V_206 -> V_208 ] . V_210 = V_211 ;
V_206 -> V_208 ++ ;
}
static void F_55 ( T_1 V_211 , T_1 V_204 , T_1 V_212 ,
struct V_205 * V_206 )
{
switch ( V_212 ) {
case V_213 :
if ( ! ( V_211 | V_204 ) )
return;
V_204 |= V_214 ;
break;
case V_167 :
case V_215 :
if ( ! ~ ( V_204 | V_216 ) )
return;
if ( ! V_204 )
V_204 = ~ 0 ;
else
V_204 |= V_216 ;
break;
case V_161 :
if ( ! ( V_211 | V_204 ) )
return;
V_204 |= V_217 ;
break;
case V_171 :
case V_169 :
case V_218 :
if ( ! ~ ( V_204 | V_219 ) )
return;
if ( ! V_204 )
V_204 = ~ 0 ;
else
V_204 |= V_219 ;
break;
case V_151 :
case V_159 :
case V_220 :
case V_221 :
if ( ! ( V_211 | V_204 ) )
return;
V_204 |= V_222 ;
break;
default:
if ( ! ~ V_204 )
return;
if ( ! V_204 )
V_204 = ~ 0 ;
break;
}
F_54 ( V_211 , V_204 , V_212 , V_206 ) ;
}
static void F_56 ( struct V_223 * V_211 ,
struct V_223 * V_204 ,
struct V_205 * V_206 )
{
F_55 ( F_57 ( V_211 -> V_224 ) ,
F_57 ( V_204 -> V_224 ) ,
V_163 , V_206 ) ;
F_55 ( F_57 ( V_211 -> V_225 ) ,
F_57 ( V_204 -> V_225 ) ,
V_165 , V_206 ) ;
F_55 ( F_58 ( V_211 -> V_226 ) ,
F_58 ( V_204 -> V_226 ) ,
V_171 , V_206 ) ;
F_55 ( F_58 ( V_211 -> V_227 ) ,
F_58 ( V_204 -> V_227 ) ,
V_169 , V_206 ) ;
F_55 ( V_211 -> V_228 , V_204 -> V_228 , V_215 , V_206 ) ;
}
static void F_59 ( struct V_229 * V_211 ,
struct V_229 * V_204 ,
struct V_205 * V_206 )
{
F_55 ( F_57 ( V_211 -> V_224 ) ,
F_57 ( V_204 -> V_224 ) ,
V_163 , V_206 ) ;
F_55 ( F_57 ( V_211 -> V_225 ) ,
F_57 ( V_204 -> V_225 ) ,
V_165 , V_206 ) ;
F_55 ( V_211 -> V_228 , V_204 -> V_228 , V_215 , V_206 ) ;
F_55 ( V_211 -> V_230 , V_204 -> V_230 , V_167 , V_206 ) ;
F_55 ( F_57 ( V_211 -> V_231 ) ,
F_57 ( V_204 -> V_231 ) ,
V_232 , V_206 ) ;
}
static void F_60 ( struct V_233 * V_211 , struct V_233 * V_204 ,
struct V_205 * V_206 )
{
T_1 V_234 = 0 ;
T_1 V_235 = 0 ;
if ( ! F_61 ( V_204 -> V_236 ) ) {
if ( F_62 ( V_204 -> V_236 ) ) {
V_234 = 0xFFFFFFFF ;
V_235 = 0xFFFFFFFF ;
} else {
V_234 = V_204 -> V_236 [ 0 ] << 16 |
V_204 -> V_236 [ 1 ] << 8 |
V_204 -> V_236 [ 2 ] ;
V_235 = V_204 -> V_236 [ 3 ] << 16 |
V_204 -> V_236 [ 4 ] << 8 |
V_204 -> V_236 [ 5 ] ;
}
F_55 ( V_211 -> V_236 [ 0 ] << 16 |
V_211 -> V_236 [ 1 ] << 8 |
V_211 -> V_236 [ 2 ] ,
V_234 , V_220 , V_206 ) ;
F_55 ( V_211 -> V_236 [ 3 ] << 16 |
V_211 -> V_236 [ 4 ] << 8 |
V_211 -> V_236 [ 5 ] ,
V_235 , V_221 , V_206 ) ;
}
if ( ! F_61 ( V_204 -> V_237 ) ) {
if ( ( F_61 ( V_211 -> V_237 ) &&
F_62 ( V_204 -> V_237 ) ) ) {
F_53 ( V_238 , V_238 , V_206 ) ;
} else {
if ( F_62 ( V_204 -> V_237 ) ) {
V_234 = 0xFFFFFFFF ;
V_235 = 0xFFFFFFFF ;
} else {
V_234 = V_204 -> V_237 [ 0 ] << 16 |
V_204 -> V_237 [ 1 ] << 8 |
V_204 -> V_237 [ 2 ] ;
V_235 = V_204 -> V_237 [ 3 ] << 16 |
V_204 -> V_237 [ 4 ] << 8 |
V_204 -> V_237 [ 5 ] ;
}
F_55 ( V_211 -> V_237 [ 0 ] << 16 |
V_211 -> V_237 [ 1 ] << 8 |
V_211 -> V_237 [ 2 ] ,
V_234 , V_151 , V_206 ) ;
F_55 ( V_211 -> V_237 [ 3 ] << 16 |
V_211 -> V_237 [ 4 ] << 8 |
V_211 -> V_237 [ 5 ] ,
V_235 , V_159 , V_206 ) ;
}
}
F_55 ( F_58 ( V_211 -> V_239 ) ,
F_58 ( V_204 -> V_239 ) ,
V_218 , V_206 ) ;
}
static inline T_1 F_63 ( struct V_240 * V_241 )
{
return F_58 ( V_241 -> V_242 . V_243 ) & V_244 ;
}
static inline T_1 F_64 ( struct V_240 * V_241 )
{
return F_58 ( V_241 -> V_245 . V_243 ) & V_244 ;
}
static inline T_1 F_65 ( struct V_240 * V_241 )
{
return F_58 ( V_241 -> V_242 . V_243 ) & V_246 ;
}
static inline T_1 F_66 ( struct V_240 * V_241 )
{
return F_58 ( V_241 -> V_245 . V_243 ) & V_246 ;
}
static inline T_1 F_67 ( struct V_240 * V_241 )
{
return ( F_58 ( V_241 -> V_242 . V_243 ) & V_247 ) >>
V_248 ;
}
static inline T_1 F_68 ( struct V_240 * V_241 )
{
return ( F_58 ( V_241 -> V_245 . V_243 ) & V_247 ) >>
V_248 ;
}
static int F_69 ( struct V_240 * V_241 ,
struct V_205 * V_206 )
{
T_1 V_249 = 0 , V_250 = 0 ;
T_1 V_251 = 0 , V_252 = 0 ;
T_1 V_253 = 0 , V_254 = 0 ;
T_1 V_255 = 0 , V_256 = 0 ;
T_1 V_257 = V_206 -> V_208 ;
if ( ( V_241 -> V_197 & V_258 ) &&
( V_241 -> V_245 . V_243 != F_70 ( 0xFFFF ) ) ) {
if ( ! V_241 -> V_245 . V_243 )
V_241 -> V_245 . V_243 = F_70 ( 0xFFFF ) ;
V_249 = V_259 ;
V_250 = V_259 ;
V_251 = F_63 ( V_241 ) ;
V_252 = F_64 ( V_241 ) ;
V_253 = F_65 ( V_241 ) ;
V_254 = F_66 ( V_241 ) ;
V_255 = F_67 ( V_241 ) ;
V_256 = F_68 ( V_241 ) ;
if ( V_253 == V_260 && V_254 == V_260 ) {
V_249 |= V_261 ;
V_250 |= V_261 ;
} else if ( V_253 != V_260 &&
V_254 == V_260 ) {
V_250 |= V_261 ;
}
}
switch ( V_241 -> V_197 & ~ V_258 ) {
case V_183 :
F_53 ( V_184 | V_185 | V_249 ,
V_184 | V_185 | V_250 , V_206 ) ;
F_56 ( & V_241 -> V_262 . V_263 ,
& V_241 -> V_264 . V_263 , V_206 ) ;
break;
case V_186 :
F_53 ( V_184 | V_187 | V_249 ,
V_184 | V_187 | V_250 , V_206 ) ;
F_56 ( & V_241 -> V_262 . V_265 ,
& V_241 -> V_264 . V_265 , V_206 ) ;
break;
case V_266 :
F_53 ( V_184 | V_249 , V_184 | V_250 ,
V_206 ) ;
F_55 ( 132 , 0 , V_167 , V_206 ) ;
F_56 ( (struct V_223 * ) & V_241 -> V_262 ,
(struct V_223 * ) & V_241 -> V_264 ,
V_206 ) ;
break;
case V_267 :
F_53 ( V_184 | V_249 , V_184 | V_250 ,
V_206 ) ;
F_59 ( (struct V_229 * ) & V_241 -> V_262 ,
(struct V_229 * ) & V_241 -> V_264 ,
V_206 ) ;
break;
case V_268 :
if ( V_249 )
F_53 ( V_249 , V_250 , V_206 ) ;
F_60 ( (struct V_233 * ) & V_241 -> V_262 ,
(struct V_233 * ) & V_241 -> V_264 , V_206 ) ;
break;
default:
return - 1 ;
}
if ( V_249 ) {
F_55 ( V_251 , V_252 , V_161 , V_206 ) ;
F_55 ( V_255 , V_256 , V_213 , V_206 ) ;
}
if ( V_206 -> V_208 == V_257 ) {
F_52 ( 0xFFFFFFFF , V_206 ) ;
V_206 -> V_207 [ V_206 -> V_208 ] . V_209 = 0x20 ;
V_206 -> V_207 [ V_206 -> V_208 ] . V_210 = 0x0 ;
V_206 -> V_208 ++ ;
}
V_206 -> V_207 [ V_206 -> V_208 - 1 ] . V_209 &= ( ~ V_154 ) ;
if ( V_241 -> V_269 == V_270 )
V_206 -> V_207 [ V_206 -> V_208 - 1 ] . V_209 |= V_271 ;
else
V_206 -> V_207 [ V_206 -> V_208 - 1 ] . V_209 |= ( V_241 -> V_269 << 10 ) ;
if ( V_206 -> V_208 > ( V_257 + 2 ) ) {
V_206 -> V_207 [ V_257 + 1 ] . V_209 |= V_193 ;
V_206 -> V_207 [ V_206 -> V_208 - 1 ] . V_209 |= V_193 ;
}
if ( V_206 -> V_208 > V_272 - 1 )
return - V_273 ;
return 0 ;
}
static int F_71 ( struct V_5 * V_6 ,
struct V_205 * V_206 )
{
T_1 V_15 = 0 ;
if ( V_206 -> V_208 > V_179 - 1 )
return - V_273 ;
for (; V_15 < V_179 && ( V_206 -> V_207 [ V_15 ] . V_209 | V_206 -> V_207 [ V_15 ] . V_210 ) ; V_15 ++ )
F_44 ( V_6 , V_15 , V_206 -> V_207 [ V_15 ] . V_209 , V_206 -> V_207 [ V_15 ] . V_210 ) ;
for (; V_15 < V_179 ; V_15 ++ )
F_44 ( V_6 , V_15 , 0x60 , 0xFFFFFFFF ) ;
F_44 ( V_6 , V_15 , 0x20 , 0x0 ) ;
return 0 ;
}
static int F_72 ( struct V_240 * V_274 ,
struct V_5 * V_6 )
{
if ( V_274 -> V_197 & V_258 ) {
if ( ~ V_274 -> V_245 . V_136 [ 0 ] || ~ V_274 -> V_245 . V_136 [ 1 ] )
F_51 ( V_6 -> V_191 ,
L_10 ) ;
if ( ~ V_274 -> V_245 . V_275 )
F_51 ( V_6 -> V_191 ,
L_11 ) ;
}
if ( V_274 -> V_197 == V_267 )
if ( V_274 -> V_262 . V_276 . V_277 != V_278 )
F_51 ( V_6 -> V_191 ,
L_12 ) ;
return 0 ;
}
static int F_73 ( struct V_5 * V_6 )
{
struct V_279 * V_178 ;
struct V_205 * V_206 ;
T_9 V_181 = 0 ;
V_206 = F_74 ( sizeof( * V_206 ) , V_182 ) ;
if ( V_206 == NULL )
return - V_280 ;
F_75 (j, &priv->rx_list.list, list) {
V_181 = F_69 ( & V_178 -> V_281 , V_206 ) ;
if ( V_181 == - V_273 ) {
F_32 ( V_6 -> V_191 ,
L_13 ) ;
goto V_282;
}
if ( V_181 == - 1 ) {
F_32 ( V_6 -> V_191 ,
L_14 ) ;
goto V_282;
}
}
V_181 = F_71 ( V_6 , V_206 ) ;
if ( V_181 == - V_273 ) {
F_32 ( V_6 -> V_191 , L_13 ) ;
goto V_282;
}
V_282:
F_47 ( V_206 ) ;
return V_181 ;
}
static void F_76 ( struct V_240 * V_274 )
{
T_1 V_15 = 0 ;
for ( V_15 = 0 ; V_15 < sizeof( V_274 -> V_264 ) ; V_15 ++ )
V_274 -> V_264 . V_283 [ V_15 ] ^= 0xFF ;
V_274 -> V_245 . V_275 ^= F_70 ( 0xFFFF ) ;
V_274 -> V_245 . V_243 ^= F_70 ( 0xFFFF ) ;
V_274 -> V_245 . V_136 [ 0 ] ^= F_77 ( ~ 0 ) ;
V_274 -> V_245 . V_136 [ 1 ] ^= F_77 ( ~ 0 ) ;
}
static int F_78 ( struct V_5 * V_6 ,
struct V_240 * V_274 )
{
struct V_279 * V_284 , * V_285 ;
int V_181 = 0 ;
V_284 = F_79 ( sizeof( * V_284 ) , V_182 ) ;
if ( V_284 == NULL )
return - V_280 ;
memcpy ( & V_284 -> V_281 , V_274 , sizeof( V_284 -> V_281 ) ) ;
F_76 ( & V_284 -> V_281 ) ;
V_181 = F_72 ( & V_284 -> V_281 , V_6 ) ;
if ( V_181 )
goto V_286;
if ( F_80 ( & V_6 -> V_287 . V_288 ) ) {
V_181 = F_49 ( V_6 ) ;
if ( V_181 != 0 )
goto V_286;
F_81 ( & V_284 -> V_288 , & V_6 -> V_287 . V_288 ) ;
goto V_289;
} else {
F_75 (comp, &priv->rx_list.list, list) {
if ( V_285 -> V_281 . V_290 > V_274 -> V_290 ) {
F_82 ( & V_284 -> V_288 , & V_285 -> V_288 ) ;
goto V_289;
}
if ( V_285 -> V_281 . V_290 == V_274 -> V_290 ) {
F_32 ( V_6 -> V_191 ,
L_15 ,
V_274 -> V_290 ) ;
V_181 = - V_273 ;
goto V_286;
}
}
F_82 ( & V_284 -> V_288 , & V_6 -> V_287 . V_288 ) ;
}
V_289:
V_6 -> V_287 . V_50 ++ ;
V_181 = F_73 ( V_6 ) ;
if ( V_181 )
goto V_291;
return V_181 ;
V_291:
V_6 -> V_287 . V_50 -- ;
F_83 ( & V_284 -> V_288 ) ;
V_286:
F_47 ( V_284 ) ;
return V_181 ;
}
static int F_84 ( struct V_5 * V_6 , T_1 V_292 )
{
struct V_279 * V_285 ;
T_1 V_181 = - V_85 ;
if ( F_80 ( & V_6 -> V_287 . V_288 ) )
return V_181 ;
F_75 (comp, &priv->rx_list.list, list) {
if ( V_285 -> V_281 . V_290 == V_292 ) {
F_83 ( & V_285 -> V_288 ) ;
F_47 ( V_285 ) ;
V_6 -> V_287 . V_50 -- ;
F_73 ( V_6 ) ;
V_181 = 0 ;
break;
}
}
return V_181 ;
}
static int F_85 ( struct V_5 * V_6 , struct V_196 * V_34 )
{
struct V_279 * V_285 ;
T_1 V_181 = - V_85 ;
F_75 (comp, &priv->rx_list.list, list) {
if ( V_285 -> V_281 . V_290 == V_34 -> V_281 . V_290 ) {
memcpy ( & V_34 -> V_281 , & V_285 -> V_281 , sizeof( V_34 -> V_281 ) ) ;
F_76 ( & V_34 -> V_281 ) ;
V_181 = 0 ;
break;
}
}
return V_181 ;
}
static int F_86 ( struct V_5 * V_6 ,
struct V_196 * V_34 , T_1 * V_293 )
{
struct V_279 * V_285 ;
T_1 V_15 = 0 ;
F_75 (comp, &priv->rx_list.list, list) {
if ( V_15 == V_34 -> V_294 )
return - V_295 ;
V_293 [ V_15 ] = V_285 -> V_281 . V_290 ;
V_15 ++ ;
}
V_34 -> V_136 = V_179 ;
V_34 -> V_294 = V_15 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_196 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_181 = 0 ;
if ( F_88 ( V_87 , & V_6 -> V_88 ) )
return - V_273 ;
F_89 ( & V_6 -> V_296 ) ;
switch ( V_34 -> V_34 ) {
case V_297 :
V_181 = F_48 ( V_6 , V_34 ) ;
break;
case V_298 :
if ( ( V_34 -> V_281 . V_269 != V_270 &&
V_34 -> V_281 . V_269 >= V_6 -> V_89 ) ||
V_34 -> V_281 . V_290 >= V_179 ) {
V_181 = - V_85 ;
break;
}
V_181 = F_78 ( V_6 , & V_34 -> V_281 ) ;
break;
case V_299 :
V_181 = F_84 ( V_6 , V_34 -> V_281 . V_290 ) ;
break;
default:
V_181 = - V_85 ;
}
F_90 ( & V_6 -> V_296 ) ;
return V_181 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_196 * V_34 ,
T_1 * V_293 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_181 = 0 ;
switch ( V_34 -> V_34 ) {
case V_300 :
V_34 -> V_136 = V_6 -> V_89 ;
break;
case V_301 :
V_34 -> V_294 = V_6 -> V_287 . V_50 ;
break;
case V_302 :
V_181 = F_85 ( V_6 , V_34 ) ;
break;
case V_303 :
V_181 = F_86 ( V_6 , V_34 , V_293 ) ;
break;
default:
V_181 = - V_85 ;
break;
}
return V_181 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_304 * V_305 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_7 & V_306 ) ) {
V_305 -> V_307 = V_308 |
V_309 ;
V_305 -> V_310 = - 1 ;
return 0 ;
}
V_305 -> V_307 = V_311 |
V_312 |
V_313 ;
V_305 -> V_310 = V_314 ;
V_305 -> V_315 = ( 1 << V_316 ) |
( 1 << V_317 ) ;
V_305 -> V_318 = ( 1 << V_319 ) |
( 1 << V_320 ) ;
return 0 ;
}
