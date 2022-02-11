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
static int F_9 ( struct V_1 * V_2 )
{
return sizeof ( struct V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_33 * V_17 ,
void * V_34 )
{
int V_15 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 T_4 * V_35 = ( T_1 T_4 * ) V_6 -> V_18 [ 0 ] . V_17 ;
T_1 * V_4 = ( T_1 * ) V_34 ;
for ( V_15 = 0 ; V_15 < sizeof ( struct V_16 ) / sizeof ( T_1 ) ; V_15 ++ )
V_4 [ V_15 ] = F_5 ( & V_35 [ V_15 ] ) ;
}
static unsigned int F_11 ( struct V_5 * V_6 ,
unsigned int V_36 )
{
struct V_1 * V_37 = V_6 -> V_37 ;
struct V_38 * V_39 = V_37 -> V_39 ;
unsigned int V_40 ;
switch ( V_39 -> V_41 ) {
case V_42 :
V_40 = V_43 ;
break;
case V_44 :
V_40 = V_45 ;
break;
case V_46 :
default:
V_40 = V_47 ;
break;
}
return ( V_36 * 1000 + V_40 - 1 ) / V_40 ;
}
static unsigned int F_12 ( struct V_5 * V_6 ,
unsigned int V_48 )
{
struct V_1 * V_37 = V_6 -> V_37 ;
struct V_38 * V_39 = V_37 -> V_39 ;
unsigned int V_40 ;
switch ( V_39 -> V_41 ) {
case V_42 :
V_40 = V_43 ;
break;
case V_44 :
V_40 = V_45 ;
break;
case V_46 :
default:
V_40 = V_47 ;
break;
}
return ( V_48 * V_40 ) / 1000 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_51 * V_52 = NULL ;
struct V_53 * V_54 = NULL ;
unsigned long V_55 ;
unsigned long V_56 ;
unsigned long V_57 ;
unsigned long V_58 ;
if ( ! ( V_6 -> V_7 & V_59 ) )
return - V_24 ;
if ( ! V_2 -> V_39 )
return - V_60 ;
V_52 = V_6 -> V_52 [ 0 ] ;
V_54 = V_6 -> V_54 [ 0 ] ;
V_55 = F_14 ( V_52 -> V_61 ) ;
V_56 = F_15 ( V_52 -> V_61 ) ;
V_57 = F_14 ( V_54 -> V_62 ) ;
V_58 = F_15 ( V_54 -> V_62 ) ;
V_50 -> V_63 = F_12 ( V_6 , V_55 ) ;
V_50 -> V_64 = V_56 ;
V_50 -> V_65 = F_12 ( V_6 , V_57 ) ;
V_50 -> V_66 = V_58 ;
V_50 -> V_67 = 0 ;
V_50 -> V_68 = 0 ;
V_50 -> V_69 = 0 ;
V_50 -> V_70 = 0 ;
V_50 -> V_71 = 0 ;
V_50 -> V_72 = 0 ;
V_50 -> V_73 = 0 ;
V_50 -> V_74 = 0 ;
V_50 -> V_75 = 0 ;
V_50 -> V_76 = 0 ;
V_50 -> V_77 = 0 ;
V_50 -> V_78 = 0 ;
V_50 -> V_79 = 0 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 , V_80 = 0 ;
if ( ! ( V_6 -> V_7 & V_59 ) )
return - V_24 ;
if ( ! V_2 -> V_39 )
return - V_60 ;
if ( V_50 -> V_63 > V_81 ) {
F_17 ( V_2 , L_2 ,
V_81 ) ;
return - V_82 ;
}
if ( V_50 -> V_64 > V_83 ) {
F_17 ( V_2 , L_3 ,
V_83 ) ;
return - V_82 ;
}
if ( V_50 -> V_65 > V_81 ) {
F_17 ( V_2 , L_2 ,
V_81 ) ;
return - V_82 ;
}
if ( V_50 -> V_66 > V_83 ) {
F_17 ( V_2 , L_3 ,
V_83 ) ;
return - V_82 ;
}
while ( F_18 ( V_84 , & V_6 -> V_85 ) )
F_19 () ;
if ( ( V_50 -> V_63 == 0 ) ||
( V_50 -> V_64 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_86 ; V_15 ++ )
V_6 -> V_52 [ V_15 ] -> V_87 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_86 ; V_15 ++ )
V_6 -> V_52 [ V_15 ] -> V_87 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_86 ; V_15 ++ ) {
V_6 -> V_52 [ V_15 ] -> V_61 = F_20 (
V_50 -> V_64 ,
F_11 ( V_6 , V_50 -> V_63 ) ) ;
}
if ( ( V_50 -> V_65 == 0 ) ||
( V_50 -> V_66 == 0 ) ) {
for ( V_15 = 0 ; V_15 < V_6 -> V_88 ; V_15 ++ )
V_6 -> V_54 [ V_15 ] -> V_89 = 0 ;
} else {
for ( V_15 = 0 ; V_15 < V_6 -> V_88 ; V_15 ++ )
V_6 -> V_54 [ V_15 ] -> V_89 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_6 -> V_88 ; V_15 ++ ) {
V_6 -> V_54 [ V_15 ] -> V_62 = F_20 (
V_50 -> V_66 ,
F_11 ( V_6 , V_50 -> V_65 ) ) ;
}
if ( V_2 -> V_90 & V_91 ) {
F_21 ( V_2 ) ;
V_80 = F_22 ( V_2 ) ;
} else {
F_23 ( V_6 ) ;
}
F_24 ( V_84 , & V_6 -> V_85 ) ;
return V_80 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_53 * V_54 = NULL ;
struct V_51 * V_52 = NULL ;
V_54 = V_6 -> V_54 [ 0 ] ;
V_52 = V_6 -> V_52 [ 0 ] ;
V_93 -> V_94 = V_95 ;
V_93 -> V_96 = V_95 ;
V_93 -> V_97 = V_95 ;
V_93 -> V_98 = V_99 ;
V_93 -> V_100 = V_52 -> V_101 ;
V_93 -> V_102 = V_52 -> V_101 ;
V_93 -> V_103 = V_52 -> V_101 ;
V_93 -> V_104 = V_54 -> V_105 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_80 = 0 , V_15 ;
if ( V_93 -> V_100 > V_95 )
return - V_82 ;
if ( ! F_27 ( V_93 -> V_100 ) ) {
F_28 ( V_2 , L_4 ) ;
return - V_82 ;
}
if ( V_93 -> V_104 > V_99 )
return - V_82 ;
if ( ! F_27 ( V_93 -> V_104 ) ) {
F_28 ( V_2 , L_4 ) ;
return - V_82 ;
}
while ( F_18 ( V_84 , & V_6 -> V_85 ) )
F_19 () ;
if ( V_2 -> V_90 & V_91 )
F_21 ( V_2 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_86 ; V_15 ++ )
V_6 -> V_52 [ V_15 ] -> V_101 = V_93 -> V_100 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_88 ; V_15 ++ )
V_6 -> V_54 [ V_15 ] -> V_105 = V_93 -> V_104 ;
if ( V_2 -> V_90 & V_91 )
V_80 = F_22 ( V_2 ) ;
F_24 ( V_84 , & V_6 -> V_85 ) ;
return V_80 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_107 -> V_108 = ! ! V_6 -> V_109 ;
V_107 -> V_110 = ! ! V_6 -> V_111 ;
V_107 -> V_112 = ! ! V_6 -> V_113 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_38 * V_39 = V_2 -> V_39 ;
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_1 V_114 , V_115 ;
if ( ! V_39 )
return - V_60 ;
if ( ! ( V_39 -> V_116 & V_117 ) ||
( ! ( V_39 -> V_116 & V_118 ) &&
( V_107 -> V_110 != V_107 -> V_112 ) ) )
return - V_82 ;
V_6 -> V_111 = V_6 -> V_113 = 0 ;
if ( V_107 -> V_110 ) {
V_6 -> V_111 = 1 ;
if ( V_107 -> V_112 ) {
V_6 -> V_113 = 1 ;
V_115 = V_119 ;
} else
V_115 = V_119 | V_120 ;
} else if ( V_107 -> V_112 ) {
V_6 -> V_113 = 1 ;
V_115 = V_120 ;
} else
V_115 = 0 ;
if ( V_107 -> V_108 )
V_6 -> V_109 = 1 ;
else
V_6 -> V_109 = 0 ;
V_114 = V_39 -> V_121 &
( V_119 | V_120 ) ;
if ( V_114 != V_115 ) {
V_39 -> V_121 &=
~ ( V_119 | V_120 ) ;
V_39 -> V_121 |= V_115 ;
if ( V_39 -> V_108 )
return F_31 ( V_39 ) ;
if ( ! V_107 -> V_108 ) {
T_1 V_122 ;
V_122 = F_5 ( & V_17 -> V_123 ) ;
V_122 &= ~ ( V_124 | V_125 ) ;
V_6 -> V_126 = 0 ;
if ( V_6 -> V_113 ) {
V_6 -> V_126 = 1 ;
V_122 |= V_124 ;
}
if ( V_6 -> V_111 )
V_122 |= V_125 ;
F_32 ( & V_17 -> V_123 , V_122 ) ;
}
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , T_6 V_127 )
{
T_6 V_128 = V_2 -> V_127 ^ V_127 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_80 = 0 ;
if ( ! ( V_128 & ( V_129 | V_130 |
V_131 ) ) )
return 0 ;
while ( F_18 ( V_84 , & V_6 -> V_85 ) )
F_19 () ;
V_2 -> V_127 = V_127 ;
if ( V_2 -> V_90 & V_91 ) {
F_21 ( V_2 ) ;
V_80 = F_22 ( V_2 ) ;
} else {
F_23 ( V_6 ) ;
}
F_24 ( V_84 , & V_6 -> V_85 ) ;
return V_80 ;
}
static T_7 F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_132 ;
}
static void F_35 ( struct V_1 * V_2 , T_7 V_133 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_132 = V_133 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_135 -> V_116 = 0 ;
V_135 -> V_136 = 0 ;
if ( V_6 -> V_137 & V_138 )
V_135 -> V_116 |= V_139 ;
if ( V_6 -> V_137 & V_140 )
V_135 -> V_116 |= V_141 ;
if ( V_6 -> V_142 & V_138 )
V_135 -> V_136 |= V_139 ;
if ( V_6 -> V_142 & V_140 )
V_135 -> V_136 |= V_141 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_8 V_142 = 0 ;
int V_80 ;
if ( ! V_6 -> V_137 && V_135 -> V_136 )
return - V_82 ;
if ( V_135 -> V_136 & ~ ( V_139 | V_141 ) )
return - V_82 ;
if ( V_135 -> V_136 & V_139 ) {
V_142 |= V_138 ;
} else {
if ( V_135 -> V_136 & V_141 )
V_142 |= V_140 ;
}
V_142 &= V_6 -> V_137 ;
V_6 -> V_142 = 0 ;
V_80 = F_38 ( V_6 -> V_2 , V_142 ) ;
if ( V_80 )
return V_80 ;
V_6 -> V_142 = V_142 ;
return 0 ;
}
static void F_39 ( struct V_5 * V_6 , T_3 V_143 )
{
T_1 V_144 = 0x0 , V_145 = V_146 ;
if ( V_143 & V_147 ) {
V_144 = V_148 | V_149 |
V_150 | V_151 | V_152 ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
V_144 = V_156 | V_149 |
V_150 | V_151 | V_152 ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
if ( V_143 & V_157 ) {
V_144 = V_158 | V_149 | V_150 |
V_151 | V_152 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
if ( V_143 & V_159 ) {
V_144 = V_160 | V_149 | V_150 |
V_151 | V_152 ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
if ( V_143 & ( V_161 ) ) {
V_144 = V_162 | V_149 | V_150 |
V_151 | V_152 ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
if ( V_143 & V_163 ) {
V_144 = V_164 | V_149 | V_150 |
V_151 | V_152 ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
if ( V_143 & V_165 ) {
V_144 = V_166 | V_149 | V_150 |
V_151 | V_152 ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
if ( V_143 & V_167 ) {
V_144 = V_168 | V_149 | V_150 |
V_151 | V_152 ;
V_6 -> V_153 [ V_6 -> V_154 ] = V_145 ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_144 ;
F_40 ( V_6 , V_6 -> V_154 , V_144 , V_145 ) ;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
}
static int F_41 ( struct V_5 * V_6 , T_3 V_143 ,
T_3 V_169 )
{
unsigned int V_170 = V_6 -> V_154 ;
unsigned int V_171 ;
unsigned int * V_172 ;
unsigned int * V_173 ;
int V_15 = 0x0 , V_174 = 0x0 ;
int V_175 = V_176 , V_177 = 0x0 ;
int V_178 = 1 ;
V_172 = F_42 ( V_176 + 1 , sizeof( unsigned int ) ,
V_179 ) ;
V_173 = F_42 ( V_176 + 1 , sizeof( unsigned int ) ,
V_179 ) ;
if ( ! V_172 || ! V_173 ) {
V_178 = 0 ;
goto V_80;
}
switch ( V_169 ) {
case V_180 :
V_171 = V_181 | V_182 ;
break;
case V_183 :
V_171 = V_181 | V_184 ;
break;
case V_185 :
V_171 = V_186 | V_182 ;
break;
case V_187 :
V_171 = V_186 | V_184 ;
break;
default:
F_28 ( V_6 -> V_37 ,
L_5 ) ;
V_178 = 0 ;
goto V_80;
}
for ( V_15 = 0 ; V_15 < V_176 + 1 ; V_15 ++ ) {
V_172 [ V_175 ] = V_6 -> V_153 [ V_15 ] ;
V_173 [ V_175 ] = V_6 -> V_155 [ V_15 ] ;
V_175 -- ;
if ( ( V_6 -> V_155 [ V_15 ] ==
( V_188 | V_189 | V_151 ) ) &&
( V_6 -> V_153 [ V_15 ] == V_171 ) )
break;
}
if ( V_15 == V_176 + 1 ) {
F_28 ( V_6 -> V_37 ,
L_6 ) ;
V_178 = 0 ;
goto V_80;
}
for ( V_177 = V_15 + 1 ; V_177 < V_176 ; V_177 ++ ) {
if ( ( V_6 -> V_155 [ V_177 ] & V_189 ) &&
! ( V_6 -> V_155 [ V_177 ] & V_151 ) ) {
V_6 -> V_155 [ V_177 ] = V_189 | V_190 |
V_152 | V_191 ;
V_6 -> V_153 [ V_177 ] = V_146 ;
F_40 ( V_6 , V_177 , V_6 -> V_155 [ V_177 ] ,
V_6 -> V_153 [ V_177 ] ) ;
break;
}
if ( ! ( V_6 -> V_155 [ V_177 ] & V_189 ) &&
( V_6 -> V_155 [ V_177 ] & V_151 ) )
continue;
else {
V_172 [ V_175 ] = V_6 -> V_153 [ V_177 ] ;
V_173 [ V_175 ] = V_6 -> V_155 [ V_177 ] ;
V_175 -- ;
}
}
V_6 -> V_154 = V_177 - 1 ;
V_170 = V_177 ;
F_39 ( V_6 , V_143 ) ;
for ( V_174 = V_175 + 1 ; V_174 < V_176 ; V_174 ++ ) {
V_6 -> V_153 [ V_6 -> V_154 ] = V_172 [ V_174 ] ;
V_6 -> V_155 [ V_6 -> V_154 ] = V_173 [ V_174 ] ;
F_40 ( V_6 , V_6 -> V_154 ,
V_173 [ V_174 ] , V_172 [ V_174 ] ) ;
if ( ! V_6 -> V_154 )
break;
V_6 -> V_154 = V_6 -> V_154 - 1 ;
}
V_80:
F_43 ( V_173 ) ;
F_43 ( V_172 ) ;
return V_178 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_192 * V_193 )
{
if ( ! F_41 ( V_6 , V_193 -> V_133 , V_193 -> V_194 ) )
return - V_82 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_16 T_4 * V_17 = V_6 -> V_18 [ 0 ] . V_17 ;
T_1 V_15 ;
V_15 = F_5 ( & V_17 -> V_195 ) ;
V_15 &= V_196 ;
if ( V_15 == V_196 ) {
F_46 ( V_6 -> V_37 , L_7 ) ;
V_15 = F_5 ( & V_17 -> V_197 ) ;
V_15 &= V_198 | V_199 ;
if ( V_15 == ( V_198 | V_199 ) ) {
F_17 ( V_6 -> V_37 ,
L_8 ) ;
} else {
F_47 ( V_6 -> V_37 ,
L_9 ) ;
return - V_24 ;
}
}
else {
V_15 = F_5 ( & V_17 -> V_197 ) ;
V_15 &= V_198 ;
if ( V_15 == V_198 ) {
F_17 ( V_6 -> V_37 ,
L_8 ) ;
} else {
F_47 ( V_6 -> V_37 ,
L_9 ) ;
return - V_24 ;
}
}
F_32 ( & V_17 -> V_200 , 0xC0C1C2C3 ) ;
return 0 ;
}
static void F_48 ( T_1 V_201 , struct V_202 * V_203 )
{
V_203 -> V_204 [ V_203 -> V_205 ] . V_206 = V_151 | V_191 | V_190 ;
V_203 -> V_204 [ V_203 -> V_205 ] . V_207 = V_201 ;
V_203 -> V_205 ++ ;
}
static void F_49 ( T_1 V_208 , T_1 V_201 , struct V_202 * V_203 )
{
F_48 ( V_201 , V_203 ) ;
V_203 -> V_204 [ V_203 -> V_205 ] . V_206 = V_190 | V_188 |
V_151 ;
V_203 -> V_204 [ V_203 -> V_205 ] . V_207 = V_208 ;
V_203 -> V_205 ++ ;
}
static void F_50 ( T_1 V_208 , T_1 V_201 , T_1 V_209 ,
struct V_202 * V_203 )
{
F_48 ( V_201 , V_203 ) ;
V_203 -> V_204 [ V_203 -> V_205 ] . V_206 = V_190 | V_151 | V_209 ;
V_203 -> V_204 [ V_203 -> V_205 ] . V_207 = V_208 ;
V_203 -> V_205 ++ ;
}
static void F_51 ( T_1 V_208 , T_1 V_201 , T_1 V_209 ,
struct V_202 * V_203 )
{
switch ( V_209 ) {
case V_210 :
if ( ! ( V_208 | V_201 ) )
return;
V_201 |= V_211 ;
break;
case V_164 :
case V_212 :
if ( ! ~ ( V_201 | V_213 ) )
return;
if ( ! V_201 )
V_201 = ~ 0 ;
else
V_201 |= V_213 ;
break;
case V_158 :
if ( ! ( V_208 | V_201 ) )
return;
V_201 |= V_214 ;
break;
case V_168 :
case V_166 :
case V_215 :
if ( ! ~ ( V_201 | V_216 ) )
return;
if ( ! V_201 )
V_201 = ~ 0 ;
else
V_201 |= V_216 ;
break;
case V_148 :
case V_156 :
case V_217 :
case V_218 :
if ( ! ( V_208 | V_201 ) )
return;
V_201 |= V_219 ;
break;
default:
if ( ! ~ V_201 )
return;
if ( ! V_201 )
V_201 = ~ 0 ;
break;
}
F_50 ( V_208 , V_201 , V_209 , V_203 ) ;
}
static void F_52 ( struct V_220 * V_208 ,
struct V_220 * V_201 ,
struct V_202 * V_203 )
{
F_51 ( F_53 ( V_208 -> V_221 ) ,
F_53 ( V_201 -> V_221 ) ,
V_160 , V_203 ) ;
F_51 ( F_53 ( V_208 -> V_222 ) ,
F_53 ( V_201 -> V_222 ) ,
V_162 , V_203 ) ;
F_51 ( F_54 ( V_208 -> V_223 ) ,
F_54 ( V_201 -> V_223 ) ,
V_168 , V_203 ) ;
F_51 ( F_54 ( V_208 -> V_224 ) ,
F_54 ( V_201 -> V_224 ) ,
V_166 , V_203 ) ;
F_51 ( V_208 -> V_225 , V_201 -> V_225 , V_212 , V_203 ) ;
}
static void F_55 ( struct V_226 * V_208 ,
struct V_226 * V_201 ,
struct V_202 * V_203 )
{
F_51 ( F_53 ( V_208 -> V_221 ) ,
F_53 ( V_201 -> V_221 ) ,
V_160 , V_203 ) ;
F_51 ( F_53 ( V_208 -> V_222 ) ,
F_53 ( V_201 -> V_222 ) ,
V_162 , V_203 ) ;
F_51 ( V_208 -> V_225 , V_201 -> V_225 , V_212 , V_203 ) ;
F_51 ( V_208 -> V_227 , V_201 -> V_227 , V_164 , V_203 ) ;
F_51 ( F_53 ( V_208 -> V_228 ) ,
F_53 ( V_201 -> V_228 ) ,
V_229 , V_203 ) ;
}
static void F_56 ( struct V_230 * V_208 , struct V_230 * V_201 ,
struct V_202 * V_203 )
{
T_1 V_231 = 0 ;
T_1 V_232 = 0 ;
if ( ! F_57 ( V_201 -> V_233 ) ) {
if ( F_58 ( V_201 -> V_233 ) ) {
V_231 = 0xFFFFFFFF ;
V_232 = 0xFFFFFFFF ;
} else {
V_231 = V_201 -> V_233 [ 0 ] << 16 |
V_201 -> V_233 [ 1 ] << 8 |
V_201 -> V_233 [ 2 ] ;
V_232 = V_201 -> V_233 [ 3 ] << 16 |
V_201 -> V_233 [ 4 ] << 8 |
V_201 -> V_233 [ 5 ] ;
}
F_51 ( V_208 -> V_233 [ 0 ] << 16 |
V_208 -> V_233 [ 1 ] << 8 |
V_208 -> V_233 [ 2 ] ,
V_231 , V_217 , V_203 ) ;
F_51 ( V_208 -> V_233 [ 3 ] << 16 |
V_208 -> V_233 [ 4 ] << 8 |
V_208 -> V_233 [ 5 ] ,
V_232 , V_218 , V_203 ) ;
}
if ( ! F_57 ( V_201 -> V_234 ) ) {
if ( ( F_57 ( V_208 -> V_234 ) &&
F_58 ( V_201 -> V_234 ) ) ) {
F_49 ( V_235 , V_235 , V_203 ) ;
} else {
if ( F_58 ( V_201 -> V_234 ) ) {
V_231 = 0xFFFFFFFF ;
V_232 = 0xFFFFFFFF ;
} else {
V_231 = V_201 -> V_234 [ 0 ] << 16 |
V_201 -> V_234 [ 1 ] << 8 |
V_201 -> V_234 [ 2 ] ;
V_232 = V_201 -> V_234 [ 3 ] << 16 |
V_201 -> V_234 [ 4 ] << 8 |
V_201 -> V_234 [ 5 ] ;
}
F_51 ( V_208 -> V_234 [ 0 ] << 16 |
V_208 -> V_234 [ 1 ] << 8 |
V_208 -> V_234 [ 2 ] ,
V_231 , V_148 , V_203 ) ;
F_51 ( V_208 -> V_234 [ 3 ] << 16 |
V_208 -> V_234 [ 4 ] << 8 |
V_208 -> V_234 [ 5 ] ,
V_232 , V_156 , V_203 ) ;
}
}
F_51 ( F_54 ( V_208 -> V_236 ) ,
F_54 ( V_201 -> V_236 ) ,
V_215 , V_203 ) ;
}
static inline T_1 F_59 ( struct V_237 * V_238 )
{
return F_54 ( V_238 -> V_239 . V_240 ) & V_241 ;
}
static inline T_1 F_60 ( struct V_237 * V_238 )
{
return F_54 ( V_238 -> V_242 . V_240 ) & V_241 ;
}
static inline T_1 F_61 ( struct V_237 * V_238 )
{
return F_54 ( V_238 -> V_239 . V_240 ) & V_243 ;
}
static inline T_1 F_62 ( struct V_237 * V_238 )
{
return F_54 ( V_238 -> V_242 . V_240 ) & V_243 ;
}
static inline T_1 F_63 ( struct V_237 * V_238 )
{
return ( F_54 ( V_238 -> V_239 . V_240 ) & V_244 ) >>
V_245 ;
}
static inline T_1 F_64 ( struct V_237 * V_238 )
{
return ( F_54 ( V_238 -> V_242 . V_240 ) & V_244 ) >>
V_245 ;
}
static int F_65 ( struct V_237 * V_238 ,
struct V_202 * V_203 )
{
T_1 V_246 = 0 , V_247 = 0 ;
T_1 V_248 = 0 , V_249 = 0 ;
T_1 V_250 = 0 , V_251 = 0 ;
T_1 V_252 = 0 , V_253 = 0 ;
T_1 V_254 = V_203 -> V_205 ;
if ( ( V_238 -> V_194 & V_255 ) &&
( V_238 -> V_242 . V_240 != F_66 ( 0xFFFF ) ) ) {
if ( ! V_238 -> V_242 . V_240 )
V_238 -> V_242 . V_240 = F_66 ( 0xFFFF ) ;
V_246 = V_256 ;
V_247 = V_256 ;
V_248 = F_59 ( V_238 ) ;
V_249 = F_60 ( V_238 ) ;
V_250 = F_61 ( V_238 ) ;
V_251 = F_62 ( V_238 ) ;
V_252 = F_63 ( V_238 ) ;
V_253 = F_64 ( V_238 ) ;
if ( V_250 == V_257 && V_251 == V_257 ) {
V_246 |= V_258 ;
V_247 |= V_258 ;
} else if ( V_250 != V_257 &&
V_251 == V_257 ) {
V_247 |= V_258 ;
}
}
switch ( V_238 -> V_194 & ~ V_255 ) {
case V_180 :
F_49 ( V_181 | V_182 | V_246 ,
V_181 | V_182 | V_247 , V_203 ) ;
F_52 ( & V_238 -> V_259 . V_260 ,
& V_238 -> V_261 . V_260 , V_203 ) ;
break;
case V_183 :
F_49 ( V_181 | V_184 | V_246 ,
V_181 | V_184 | V_247 , V_203 ) ;
F_52 ( & V_238 -> V_259 . V_262 ,
& V_238 -> V_261 . V_262 , V_203 ) ;
break;
case V_263 :
F_49 ( V_181 | V_246 , V_181 | V_247 ,
V_203 ) ;
F_51 ( 132 , 0 , V_164 , V_203 ) ;
F_52 ( (struct V_220 * ) & V_238 -> V_259 ,
(struct V_220 * ) & V_238 -> V_261 ,
V_203 ) ;
break;
case V_264 :
F_49 ( V_181 | V_246 , V_181 | V_247 ,
V_203 ) ;
F_55 ( (struct V_226 * ) & V_238 -> V_259 ,
(struct V_226 * ) & V_238 -> V_261 ,
V_203 ) ;
break;
case V_265 :
if ( V_246 )
F_49 ( V_246 , V_247 , V_203 ) ;
F_56 ( (struct V_230 * ) & V_238 -> V_259 ,
(struct V_230 * ) & V_238 -> V_261 , V_203 ) ;
break;
default:
return - 1 ;
}
if ( V_246 ) {
F_51 ( V_248 , V_249 , V_158 , V_203 ) ;
F_51 ( V_252 , V_253 , V_210 , V_203 ) ;
}
if ( V_203 -> V_205 == V_254 ) {
F_48 ( 0xFFFFFFFF , V_203 ) ;
V_203 -> V_204 [ V_203 -> V_205 ] . V_206 = 0x20 ;
V_203 -> V_204 [ V_203 -> V_205 ] . V_207 = 0x0 ;
V_203 -> V_205 ++ ;
}
V_203 -> V_204 [ V_203 -> V_205 - 1 ] . V_206 &= ( ~ V_151 ) ;
if ( V_238 -> V_266 == V_267 )
V_203 -> V_204 [ V_203 -> V_205 - 1 ] . V_206 |= V_268 ;
else
V_203 -> V_204 [ V_203 -> V_205 - 1 ] . V_206 |= ( V_238 -> V_266 << 10 ) ;
if ( V_203 -> V_205 > ( V_254 + 2 ) ) {
V_203 -> V_204 [ V_254 + 1 ] . V_206 |= V_189 ;
V_203 -> V_204 [ V_203 -> V_205 - 1 ] . V_206 |= V_189 ;
}
if ( V_203 -> V_205 > V_269 - 1 )
return - V_270 ;
return 0 ;
}
static int F_67 ( struct V_5 * V_6 ,
struct V_202 * V_203 )
{
T_1 V_15 = 0 ;
if ( V_203 -> V_205 > V_176 - 1 )
return - V_270 ;
for (; V_15 < V_176 && ( V_203 -> V_204 [ V_15 ] . V_206 | V_203 -> V_204 [ V_15 ] . V_207 ) ; V_15 ++ )
F_40 ( V_6 , V_15 , V_203 -> V_204 [ V_15 ] . V_206 , V_203 -> V_204 [ V_15 ] . V_207 ) ;
for (; V_15 < V_176 ; V_15 ++ )
F_40 ( V_6 , V_15 , 0x60 , 0xFFFFFFFF ) ;
F_40 ( V_6 , V_15 , 0x20 , 0x0 ) ;
return 0 ;
}
static int F_68 ( struct V_237 * V_271 ,
struct V_5 * V_6 )
{
if ( V_271 -> V_194 & V_255 ) {
if ( ~ V_271 -> V_242 . V_133 [ 0 ] || ~ V_271 -> V_242 . V_133 [ 1 ] )
F_47 ( V_6 -> V_37 ,
L_10 ) ;
if ( ~ V_271 -> V_242 . V_272 )
F_47 ( V_6 -> V_37 ,
L_11 ) ;
}
if ( V_271 -> V_194 == V_264 )
if ( V_271 -> V_259 . V_273 . V_274 != V_275 )
F_47 ( V_6 -> V_37 ,
L_12 ) ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_276 * V_175 ;
struct V_202 * V_203 ;
T_9 V_178 = 0 ;
V_203 = F_70 ( sizeof( * V_203 ) , V_179 ) ;
if ( V_203 == NULL )
return - V_277 ;
F_71 (j, &priv->rx_list.list, list) {
V_178 = F_65 ( & V_175 -> V_278 , V_203 ) ;
if ( V_178 == - V_270 ) {
F_28 ( V_6 -> V_37 ,
L_13 ) ;
goto V_279;
}
if ( V_178 == - 1 ) {
F_28 ( V_6 -> V_37 ,
L_14 ) ;
goto V_279;
}
}
V_178 = F_67 ( V_6 , V_203 ) ;
if ( V_178 == - V_270 ) {
F_28 ( V_6 -> V_37 , L_13 ) ;
goto V_279;
}
V_279:
F_43 ( V_203 ) ;
return V_178 ;
}
static void F_72 ( struct V_237 * V_271 )
{
T_1 V_15 = 0 ;
for ( V_15 = 0 ; V_15 < sizeof( V_271 -> V_261 ) ; V_15 ++ )
V_271 -> V_261 . V_280 [ V_15 ] ^= 0xFF ;
V_271 -> V_242 . V_272 ^= F_66 ( 0xFFFF ) ;
V_271 -> V_242 . V_240 ^= F_66 ( 0xFFFF ) ;
V_271 -> V_242 . V_133 [ 0 ] ^= F_73 ( ~ 0 ) ;
V_271 -> V_242 . V_133 [ 1 ] ^= F_73 ( ~ 0 ) ;
}
static int F_74 ( struct V_5 * V_6 ,
struct V_237 * V_271 )
{
struct V_276 * V_281 , * V_282 ;
int V_178 = 0 ;
V_281 = F_75 ( sizeof( * V_281 ) , V_179 ) ;
if ( V_281 == NULL )
return - V_277 ;
memcpy ( & V_281 -> V_278 , V_271 , sizeof( V_281 -> V_278 ) ) ;
F_72 ( & V_281 -> V_278 ) ;
V_178 = F_68 ( & V_281 -> V_278 , V_6 ) ;
if ( V_178 )
goto V_283;
if ( F_76 ( & V_6 -> V_284 . V_285 ) ) {
V_178 = F_45 ( V_6 ) ;
if ( V_178 != 0 )
goto V_283;
F_77 ( & V_281 -> V_285 , & V_6 -> V_284 . V_285 ) ;
goto V_286;
} else {
F_71 (comp, &priv->rx_list.list, list) {
if ( V_282 -> V_278 . V_287 > V_271 -> V_287 ) {
F_78 ( & V_281 -> V_285 , & V_282 -> V_285 ) ;
goto V_286;
}
if ( V_282 -> V_278 . V_287 == V_271 -> V_287 ) {
F_28 ( V_6 -> V_37 ,
L_15 ,
V_271 -> V_287 ) ;
V_178 = - V_270 ;
goto V_283;
}
}
F_78 ( & V_281 -> V_285 , & V_6 -> V_284 . V_285 ) ;
}
V_286:
V_6 -> V_284 . V_40 ++ ;
V_178 = F_69 ( V_6 ) ;
if ( V_178 )
goto V_288;
return V_178 ;
V_288:
V_6 -> V_284 . V_40 -- ;
F_79 ( & V_281 -> V_285 ) ;
V_283:
F_43 ( V_281 ) ;
return V_178 ;
}
static int F_80 ( struct V_5 * V_6 , T_1 V_289 )
{
struct V_276 * V_282 ;
T_1 V_178 = - V_82 ;
if ( F_76 ( & V_6 -> V_284 . V_285 ) )
return V_178 ;
F_71 (comp, &priv->rx_list.list, list) {
if ( V_282 -> V_278 . V_287 == V_289 ) {
F_79 ( & V_282 -> V_285 ) ;
F_43 ( V_282 ) ;
V_6 -> V_284 . V_40 -- ;
F_69 ( V_6 ) ;
V_178 = 0 ;
break;
}
}
return V_178 ;
}
static int F_81 ( struct V_5 * V_6 , struct V_192 * V_193 )
{
struct V_276 * V_282 ;
T_1 V_178 = - V_82 ;
F_71 (comp, &priv->rx_list.list, list) {
if ( V_282 -> V_278 . V_287 == V_193 -> V_278 . V_287 ) {
memcpy ( & V_193 -> V_278 , & V_282 -> V_278 , sizeof( V_193 -> V_278 ) ) ;
F_72 ( & V_193 -> V_278 ) ;
V_178 = 0 ;
break;
}
}
return V_178 ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_192 * V_193 , T_1 * V_290 )
{
struct V_276 * V_282 ;
T_1 V_15 = 0 ;
F_71 (comp, &priv->rx_list.list, list) {
if ( V_15 == V_193 -> V_291 )
return - V_292 ;
V_290 [ V_15 ] = V_282 -> V_278 . V_287 ;
V_15 ++ ;
}
V_193 -> V_133 = V_176 ;
V_193 -> V_291 = V_15 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_178 = 0 ;
if ( F_84 ( V_84 , & V_6 -> V_85 ) )
return - V_270 ;
F_85 ( & V_6 -> V_293 ) ;
switch ( V_193 -> V_193 ) {
case V_294 :
V_178 = F_44 ( V_6 , V_193 ) ;
break;
case V_295 :
if ( ( V_193 -> V_278 . V_266 != V_267 &&
V_193 -> V_278 . V_266 >= V_6 -> V_86 ) ||
V_193 -> V_278 . V_287 >= V_176 ) {
V_178 = - V_82 ;
break;
}
V_178 = F_74 ( V_6 , & V_193 -> V_278 ) ;
break;
case V_296 :
V_178 = F_80 ( V_6 , V_193 -> V_278 . V_287 ) ;
break;
default:
V_178 = - V_82 ;
}
F_86 ( & V_6 -> V_293 ) ;
return V_178 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_192 * V_193 ,
T_1 * V_290 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_178 = 0 ;
switch ( V_193 -> V_193 ) {
case V_297 :
V_193 -> V_133 = V_6 -> V_86 ;
break;
case V_298 :
V_193 -> V_291 = V_6 -> V_284 . V_40 ;
break;
case V_299 :
V_178 = F_81 ( V_6 , V_193 ) ;
break;
case V_300 :
V_178 = F_82 ( V_6 , V_193 , V_290 ) ;
break;
default:
V_178 = - V_82 ;
break;
}
return V_178 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_301 * V_302 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_7 & V_303 ) ) {
V_302 -> V_304 = V_305 |
V_306 ;
V_302 -> V_307 = - 1 ;
return 0 ;
}
V_302 -> V_304 = V_308 |
V_309 |
V_310 ;
V_302 -> V_307 = V_311 ;
V_302 -> V_312 = ( 1 << V_313 ) |
( 1 << V_314 ) ;
V_302 -> V_315 = ( 1 << V_316 ) |
( 1 << V_317 ) ;
return 0 ;
}
