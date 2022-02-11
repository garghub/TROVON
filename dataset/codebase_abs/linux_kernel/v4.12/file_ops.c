static inline int F_1 ( T_1 V_1 )
{
return ( F_2 ( V_2 , V_1 ) == V_3 ) ;
}
static int F_3 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = F_4 ( V_4 -> V_11 ,
struct V_9 ,
V_12 ) ;
if ( ! ( ( V_10 -> V_13 & V_14 ) && V_10 -> V_15 ) )
return - V_16 ;
if ( ! F_5 ( & V_10 -> V_17 ) )
return - V_18 ;
F_6 ( & V_10 -> V_19 ) ;
V_8 = F_7 ( sizeof( * V_8 ) , V_20 ) ;
if ( V_8 ) {
V_8 -> V_21 = - 1 ;
V_8 -> V_22 = V_23 -> V_22 ;
F_8 ( V_8 -> V_22 ) ;
V_8 -> V_10 = V_10 ;
V_6 -> V_24 = V_8 ;
} else {
V_6 -> V_24 = NULL ;
if ( F_9 ( & V_10 -> V_17 ) )
F_10 ( & V_10 -> V_25 ) ;
return - V_26 ;
}
return 0 ;
}
static long F_11 ( struct V_5 * V_6 , unsigned int V_27 ,
unsigned long V_28 )
{
struct V_7 * V_8 = V_6 -> V_24 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
int V_35 = 0 ;
unsigned long V_36 ;
int V_37 = 0 ;
unsigned long V_38 = 0 ;
T_2 V_39 = 0 ;
F_12 ( V_40 , L_1 , V_27 ) ;
if ( V_27 != V_41 &&
V_27 != V_42 &&
! V_30 )
return - V_16 ;
switch ( V_27 ) {
case V_41 :
if ( V_30 )
return - V_16 ;
if ( F_13 ( & V_32 ,
(struct V_31 V_43 * ) V_28 ,
sizeof( V_32 ) ) )
return - V_44 ;
V_35 = F_14 ( V_8 , & V_32 ) ;
break;
case V_45 :
V_35 = F_15 ( V_8 , ( void V_43 * ) ( unsigned long ) V_28 ,
sizeof( struct V_46 ) ) ;
break;
case V_47 :
V_35 = F_16 ( V_8 , ( void V_43 * ) ( unsigned long ) V_28 ,
sizeof( struct V_48 ) ) ;
break;
case V_49 :
if ( V_30 )
F_17 ( V_30 -> V_50 ) ;
break;
case V_51 :
if ( F_13 ( & V_34 ,
(struct V_52 V_43 * ) V_28 ,
sizeof( V_34 ) ) )
return - V_44 ;
V_35 = F_18 ( V_8 , & V_34 ) ;
if ( ! V_35 ) {
V_36 = V_28 + F_19 ( struct V_33 , V_53 ) ;
if ( F_20 ( ( void V_43 * ) V_36 , & V_34 . V_53 ,
sizeof( V_34 . V_53 ) +
sizeof( V_34 . V_54 ) ) )
V_35 = - V_44 ;
}
break;
case V_55 :
if ( F_13 ( & V_34 ,
(struct V_52 V_43 * ) V_28 ,
sizeof( V_34 ) ) )
return - V_44 ;
V_35 = F_21 ( V_8 , & V_34 ) ;
if ( V_35 )
break;
V_36 = V_28 + F_19 ( struct V_33 , V_53 ) ;
if ( F_20 ( ( void V_43 * ) V_36 , & V_34 . V_53 ,
sizeof( V_34 . V_53 ) ) )
V_35 = - V_44 ;
break;
case V_56 :
if ( F_13 ( & V_34 ,
(struct V_52 V_43 * ) V_28 ,
sizeof( V_34 ) ) )
return - V_44 ;
V_35 = F_22 ( V_8 , & V_34 ) ;
if ( V_35 )
break;
V_36 = V_28 + F_19 ( struct V_33 , V_53 ) ;
if ( F_20 ( ( void V_43 * ) V_36 , & V_34 . V_53 ,
sizeof( V_34 . V_53 ) ) )
V_35 = - V_44 ;
break;
case V_57 :
V_35 = F_23 ( V_37 , ( int V_43 * ) V_28 ) ;
if ( V_35 != 0 )
return - V_44 ;
V_35 = F_24 ( V_30 , V_8 -> V_58 , V_37 ) ;
break;
case V_59 :
V_35 = F_23 ( V_37 , ( int V_43 * ) V_28 ) ;
if ( V_35 != 0 )
return - V_44 ;
V_30 -> V_60 = ( F_25 ( V_30 -> V_60 ) ) V_37 ;
break;
case V_61 :
V_35 = F_23 ( V_38 , ( unsigned long V_43 * ) V_28 ) ;
if ( V_35 != 0 )
return - V_44 ;
V_35 = F_26 ( V_30 , V_8 -> V_58 , V_38 ) ;
break;
case V_62 :
V_35 = F_23 ( V_39 , ( T_2 V_43 * ) V_28 ) ;
if ( V_35 != 0 )
return - V_44 ;
if ( F_27 ( V_63 ) )
V_35 = F_28 ( V_30 , V_8 -> V_58 , V_39 ) ;
else
return - V_64 ;
break;
case V_65 : {
struct V_66 * V_50 ;
struct V_9 * V_10 ;
if ( ! V_30 || ! V_30 -> V_10 || ! V_30 -> V_50 )
return - V_16 ;
V_10 = V_30 -> V_10 ;
V_50 = V_30 -> V_50 ;
F_29 (
V_50 -> V_67 , ( V_50 -> V_13 & V_68 ) ,
F_30 ( V_69 ) ) ;
if ( ! ( V_50 -> V_13 & V_68 ) )
return - V_70 ;
if ( V_50 -> V_13 & V_71 ) {
F_29 (
V_10 -> V_72 ,
! ( F_31 ( V_10 -> V_13 ) & V_73 ) ,
F_30 ( V_69 ) ) ;
if ( V_10 -> V_13 & V_73 )
return - V_70 ;
if ( V_10 -> V_13 & V_74 )
return - V_75 ;
F_32 ( V_50 ) ;
V_35 = F_33 ( V_50 ) ;
F_34 ( V_10 , V_76 ,
V_30 -> V_77 ) ;
} else {
V_35 = F_35 ( V_50 ) ;
}
if ( ! V_35 )
F_17 ( V_50 ) ;
break;
}
case V_42 :
V_37 = V_78 ;
if ( F_36 ( V_37 , ( int V_43 * ) V_28 ) )
return - V_44 ;
break;
default:
return - V_16 ;
}
return V_35 ;
}
static T_3 F_37 ( struct V_79 * V_79 , struct V_80 * V_81 )
{
struct V_7 * V_8 = V_79 -> V_82 -> V_24 ;
struct V_83 * V_84 = V_8 -> V_84 ;
struct V_85 * V_86 = V_8 -> V_86 ;
int V_87 = 0 , V_88 = 0 ;
unsigned long V_89 = V_81 -> V_90 ;
if ( ! V_86 || ! V_84 )
return - V_91 ;
if ( ! F_38 ( V_81 ) || ! V_89 )
return - V_16 ;
F_12 ( V_92 , L_2 ,
V_8 -> V_30 -> V_77 , V_8 -> V_58 , V_89 ) ;
if ( F_39 ( & V_84 -> V_93 ) == V_84 -> V_94 )
return - V_95 ;
while ( V_89 ) {
int V_35 ;
unsigned long V_96 = 0 ;
V_35 = F_40 (
V_8 , (struct V_97 * ) ( V_81 -> V_98 + V_87 ) ,
V_89 , & V_96 ) ;
if ( V_35 ) {
V_88 = V_35 ;
break;
}
V_89 -= V_96 ;
V_87 += V_96 ;
V_88 ++ ;
}
return V_88 ;
}
static int F_41 ( struct V_5 * V_6 , struct V_99 * V_100 )
{
struct V_7 * V_8 = V_6 -> V_24 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 ;
unsigned long V_13 ;
T_1 V_1 = V_100 -> V_101 << V_102 ,
V_103 = 0 ;
void * V_104 = NULL ;
T_4 V_58 , V_105 = 0 , V_106 = 0 , type ;
T_3 V_107 = 0 ;
int V_35 = 0 ;
T_2 V_77 ;
if ( ! F_1 ( V_1 ) || ! V_30 ||
! ( V_100 -> V_108 & V_109 ) ) {
V_35 = - V_16 ;
goto V_87;
}
V_10 = V_30 -> V_10 ;
V_77 = F_2 ( V_110 , V_1 ) ;
V_58 = F_2 ( V_111 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_77 != V_30 -> V_77 || V_58 != V_8 -> V_58 ) {
V_35 = - V_16 ;
goto V_87;
}
V_13 = V_100 -> V_108 ;
switch ( type ) {
case V_112 :
case V_113 :
V_103 = ( ( V_10 -> V_114 + V_115 ) +
( V_30 -> V_50 -> V_116 * F_42 ( 16 ) ) ) +
( type == V_113 ?
( V_117 / 2 ) : 0 ) ;
V_107 = F_43 ( V_30 -> V_50 -> V_118 * V_119 ) ;
V_13 &= ~ V_120 ;
V_13 |= V_121 | V_122 ;
V_100 -> V_123 = F_44 ( V_100 -> V_123 ) ;
V_105 = 1 ;
break;
case V_124 :
if ( V_13 & V_125 ) {
V_35 = - V_64 ;
goto V_87;
}
V_104 = V_10 -> V_126 [ V_30 -> V_127 ] . V_128 ;
V_103 = F_45 ( V_104 ) +
( ( ( T_1 ) V_30 -> V_50 -> V_129 -
( T_1 ) V_10 -> V_126 [ V_30 -> V_127 ] . V_128 ) & V_130 ) ;
V_107 = V_131 ;
V_13 &= ~ V_132 ;
V_13 |= V_121 | V_122 ;
V_105 = 1 ;
break;
case V_133 :
V_107 = V_30 -> V_134 ;
V_104 = V_30 -> V_135 ;
break;
case V_136 : {
unsigned long V_36 ;
int V_137 ;
V_107 = V_30 -> V_138 . V_139 ;
if ( ( V_100 -> V_140 - V_100 -> V_141 ) != V_107 ) {
F_46 ( V_10 , L_3 ,
( V_100 -> V_140 - V_100 -> V_141 ) , V_107 ) ;
V_35 = - V_16 ;
goto V_87;
}
if ( V_100 -> V_108 & V_125 ) {
V_35 = - V_64 ;
goto V_87;
}
V_100 -> V_108 &= ~ V_132 ;
V_36 = V_100 -> V_141 ;
for ( V_137 = 0 ; V_137 < V_30 -> V_138 . V_142 ; V_137 ++ ) {
V_107 = V_30 -> V_138 . V_143 [ V_137 ] . V_144 ;
V_104 = V_30 -> V_138 . V_143 [ V_137 ] . V_36 ;
V_35 = F_47 (
V_100 , V_36 ,
F_48 ( F_49 ( V_104 ) ) ,
V_107 ,
V_100 -> V_123 ) ;
if ( V_35 < 0 )
goto V_87;
V_36 += V_107 ;
}
V_35 = 0 ;
goto V_87;
}
case V_145 :
V_103 = ( unsigned long )
( V_10 -> V_114 + V_146 )
+ ( V_30 -> V_77 * V_147 ) ;
V_107 = V_131 ;
V_13 |= V_121 | V_122 ;
V_100 -> V_123 = F_50 ( V_100 -> V_123 ) ;
V_105 = 1 ;
break;
case V_148 :
V_103 = ( unsigned long ) ( V_10 -> V_149 +
( ( V_30 -> V_77 - V_10 -> V_150 ) *
V_151 ) ) & V_130 ;
V_107 = V_131 ;
V_13 |= V_152 | V_122 ;
V_106 = 1 ;
break;
case V_153 :
if ( V_13 & ( unsigned long ) ( V_125 | V_154 ) ) {
V_35 = - V_64 ;
goto V_87;
}
V_103 = F_51 ( ( void * ) V_10 -> V_155 ) ;
V_107 = V_131 ;
V_13 |= V_152 | V_122 ;
break;
case V_156 :
if ( ! F_27 ( V_157 ) ) {
V_35 = - V_16 ;
goto V_87;
}
if ( V_13 & V_125 ) {
V_35 = - V_64 ;
goto V_87;
}
V_107 = V_131 ;
V_104 = ( void * ) V_30 -> V_158 ;
V_13 &= ~ V_132 ;
break;
case V_159 :
V_103 = ( T_1 ) V_30 -> V_160 ;
V_107 = V_131 ;
V_13 |= V_152 | V_122 ;
V_106 = 1 ;
break;
case V_161 :
V_103 = ( T_1 ) V_30 -> V_162 ;
V_107 = V_30 -> V_134 * V_30 -> V_163 ;
V_13 |= V_152 | V_122 ;
V_106 = 1 ;
break;
case V_164 :
V_103 = ( T_1 ) V_30 -> V_165 ;
V_107 = V_30 -> V_138 . V_139 * V_30 -> V_163 ;
V_13 |= V_152 | V_122 ;
V_13 &= ~ V_132 ;
V_106 = 1 ;
break;
case V_166 : {
struct V_85 * V_86 = V_8 -> V_86 ;
if ( ! V_86 ) {
V_35 = - V_44 ;
goto V_87;
}
V_103 = ( T_1 ) V_86 -> V_167 ;
V_107 = F_43 ( sizeof( * V_86 -> V_167 ) * V_86 -> V_168 ) ;
V_13 |= V_152 | V_122 ;
V_106 = 1 ;
break;
}
default:
V_35 = - V_16 ;
break;
}
if ( ( V_100 -> V_140 - V_100 -> V_141 ) != V_107 ) {
F_12 ( V_169 , L_4 ,
V_30 -> V_77 , V_8 -> V_58 ,
( V_100 -> V_140 - V_100 -> V_141 ) , V_107 ) ;
V_35 = - V_16 ;
goto V_87;
}
V_100 -> V_108 = V_13 ;
F_12 ( V_169 ,
L_5 ,
V_77 , V_58 , type , V_105 , V_106 , V_103 , V_107 ,
V_100 -> V_140 - V_100 -> V_141 , V_100 -> V_108 ) ;
if ( V_106 ) {
V_100 -> V_101 = F_48 ( V_103 ) ;
V_100 -> V_170 = & V_170 ;
V_35 = 0 ;
} else if ( V_105 ) {
V_35 = F_52 ( V_100 , V_100 -> V_141 ,
F_48 ( V_103 ) ,
V_107 ,
V_100 -> V_123 ) ;
} else if ( V_104 ) {
V_35 = F_47 ( V_100 , V_100 -> V_141 ,
F_48 ( F_49 ( V_104 ) ) ,
V_107 ,
V_100 -> V_123 ) ;
} else {
V_35 = F_47 ( V_100 , V_100 -> V_141 ,
F_48 ( V_103 ) ,
V_107 ,
V_100 -> V_123 ) ;
}
V_87:
return V_35 ;
}
static int F_53 ( struct V_171 * V_106 )
{
struct V_172 * V_172 ;
V_172 = F_54 ( ( void * ) ( V_106 -> V_173 << V_102 ) ) ;
if ( ! V_172 )
return V_174 ;
F_55 ( V_172 ) ;
V_106 -> V_172 = V_172 ;
return 0 ;
}
static unsigned int F_56 ( struct V_5 * V_6 , struct V_175 * V_176 )
{
struct V_29 * V_30 ;
unsigned V_177 ;
V_30 = ( (struct V_7 * ) V_6 -> V_24 ) -> V_30 ;
if ( ! V_30 )
V_177 = V_178 ;
else if ( V_30 -> V_60 == V_179 )
V_177 = F_57 ( V_6 , V_176 ) ;
else if ( V_30 -> V_60 == V_180 )
V_177 = F_58 ( V_6 , V_176 ) ;
else
V_177 = V_178 ;
return V_177 ;
}
static int F_59 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_181 = V_6 -> V_24 ;
struct V_29 * V_30 = V_181 -> V_30 ;
struct V_9 * V_10 = F_4 ( V_4 -> V_11 ,
struct V_9 ,
V_12 ) ;
unsigned long V_13 , * V_182 ;
V_6 -> V_24 = NULL ;
if ( ! V_30 )
goto V_87;
F_12 ( V_169 , L_6 , V_30 -> V_77 , V_181 -> V_58 ) ;
F_60 ( & V_183 ) ;
F_61 () ;
F_62 ( V_181 ) ;
F_63 ( V_181 -> V_21 ) ;
F_64 ( V_181 ) ;
V_182 = V_10 -> V_149 + ( ( V_30 -> V_77 - V_10 -> V_150 ) *
V_151 ) + V_181 -> V_58 ;
* V_182 = 0 ;
F_65 ( V_181 -> V_58 , V_30 -> V_184 ) ;
if ( ! F_66 ( V_30 -> V_184 , V_151 ) ) {
F_67 ( & V_183 ) ;
goto V_87;
}
F_68 ( & V_10 -> V_185 , V_13 ) ;
F_34 ( V_10 , V_186 |
V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 , V_30 -> V_77 ) ;
F_69 ( V_10 , V_30 -> V_77 ) ;
F_70 ( V_10 , V_30 -> V_50 -> V_116 , V_193 ,
F_71 ( V_10 , V_30 -> V_50 -> type ) ) ;
F_32 ( V_30 -> V_50 ) ;
F_72 ( & V_10 -> V_185 , V_13 ) ;
V_10 -> V_194 [ V_30 -> V_77 ] = NULL ;
F_73 ( V_30 ) ;
F_74 ( V_10 , V_30 ) ;
V_30 -> V_195 = 0 ;
V_30 -> V_196 = 0 ;
V_30 -> V_197 = 0 ;
V_30 -> V_198 = 0 ;
V_30 -> V_199 = 0 ;
V_200 . V_201 -- ;
if ( ++ V_10 -> V_202 == V_10 -> V_203 )
F_75 ( V_10 ) ;
F_67 ( & V_183 ) ;
F_76 ( V_10 , V_30 ) ;
V_87:
F_77 ( V_181 -> V_22 ) ;
F_78 ( & V_10 -> V_19 ) ;
if ( F_9 ( & V_10 -> V_17 ) )
F_10 ( & V_10 -> V_25 ) ;
F_79 ( V_181 ) ;
return 0 ;
}
static T_1 F_51 ( void * V_36 )
{
struct V_172 * V_172 ;
T_1 V_204 = 0 ;
V_172 = F_54 ( V_36 ) ;
if ( V_172 )
V_204 = F_80 ( V_172 ) << V_102 ;
return V_204 ;
}
static int F_14 ( struct V_7 * V_8 , struct V_31 * V_32 )
{
int V_35 ;
unsigned int V_205 , V_206 ;
V_205 = V_32 -> V_207 >> 16 ;
if ( V_205 != V_208 )
return - V_75 ;
V_206 = V_32 -> V_207 & 0xffff ;
F_60 ( & V_183 ) ;
V_35 = 0 ;
if ( V_32 -> V_163 ) {
V_35 = F_81 ( V_8 , V_32 ) ;
if ( V_35 > 0 )
V_8 -> V_21 =
F_82 ( V_8 -> V_30 -> V_127 ) ;
}
if ( ! V_35 )
V_35 = F_83 ( V_8 , V_8 -> V_10 , V_32 ) ;
F_67 ( & V_183 ) ;
if ( V_35 > 0 ) {
V_35 = F_84 ( V_8 -> V_30 -> V_209 , ! F_85 (
V_210 ,
& V_8 -> V_30 -> V_199 ) ) ;
if ( F_85 ( V_211 , & V_8 -> V_30 -> V_199 ) ) {
F_86 ( V_8 -> V_58 , V_8 -> V_30 -> V_184 ) ;
return - V_26 ;
}
if ( ! V_35 )
V_35 = F_87 ( V_8 ) ;
if ( V_35 )
F_86 ( V_8 -> V_58 , V_8 -> V_30 -> V_184 ) ;
} else if ( ! V_35 ) {
V_35 = F_88 ( V_8 ) ;
if ( V_8 -> V_30 -> V_163 ) {
if ( V_35 )
F_89 ( V_211 ,
& V_8 -> V_30 -> V_199 ) ;
F_86 ( V_210 ,
& V_8 -> V_30 -> V_199 ) ;
F_90 ( & V_8 -> V_30 -> V_209 ) ;
}
}
return V_35 ;
}
static int F_81 ( struct V_7 * V_8 ,
const struct V_31 * V_32 )
{
int V_137 ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_2 V_58 ;
for ( V_137 = V_10 -> V_150 ; V_137 < V_10 -> V_212 ; V_137 ++ ) {
struct V_29 * V_30 = V_10 -> V_194 [ V_137 ] ;
if ( ! V_30 ||
F_66 ( V_30 -> V_184 ,
V_151 ) )
continue;
if ( V_30 -> V_50 && ( V_30 -> V_50 -> type == V_213 ) )
continue;
if ( memcmp ( V_30 -> V_214 , V_32 -> V_214 ,
sizeof( V_30 -> V_214 ) ) ||
V_30 -> V_215 != F_91 ( F_92 () ) ||
V_30 -> V_216 != V_32 -> V_216 ||
V_30 -> V_163 != V_32 -> V_163 )
continue;
if ( V_30 -> V_207 != V_32 -> V_207 )
return - V_16 ;
V_58 = F_93 ( V_30 -> V_184 ,
V_151 ) ;
if ( V_58 >= V_30 -> V_163 )
return - V_217 ;
V_8 -> V_30 = V_30 ;
V_8 -> V_58 = V_58 ;
F_94 ( V_8 -> V_58 , V_30 -> V_184 ) ;
return 1 ;
}
return 0 ;
}
static int F_83 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_31 * V_32 )
{
struct V_29 * V_30 ;
unsigned int V_77 ;
int V_35 , V_218 ;
if ( V_10 -> V_13 & V_73 ) {
return - V_91 ;
}
if ( ! V_10 -> V_202 )
return - V_217 ;
for ( V_77 = V_10 -> V_150 ;
V_77 < V_10 -> V_212 ; V_77 ++ )
if ( ! V_10 -> V_194 [ V_77 ] )
break;
if ( V_77 == V_10 -> V_212 )
return - V_217 ;
V_8 -> V_21 = F_82 ( V_10 -> V_219 ) ;
if ( V_8 -> V_21 != - 1 )
V_218 = F_95 ( V_8 -> V_21 ) ;
else
V_218 = F_96 () ;
V_30 = F_97 ( V_10 -> V_220 , V_77 , V_218 ) ;
if ( ! V_30 ) {
F_46 ( V_10 ,
L_7 ) ;
return - V_26 ;
}
F_12 ( V_169 , L_8 ,
V_30 -> V_77 , V_8 -> V_58 , V_23 -> V_221 , V_8 -> V_21 ,
V_30 -> V_127 ) ;
V_30 -> V_50 = F_98 ( V_10 , V_222 , V_30 -> V_223 ,
V_30 -> V_10 -> V_219 ) ;
if ( ! V_30 -> V_50 ) {
V_35 = - V_26 ;
goto V_224;
}
F_12 ( V_169 , L_9 , V_30 -> V_50 -> V_225 ,
V_30 -> V_50 -> V_116 ) ;
V_35 = F_33 ( V_30 -> V_50 ) ;
if ( V_35 )
goto V_224;
if ( V_32 -> V_163 ) {
V_35 = F_99 ( V_30 , V_32 ) ;
if ( V_35 )
goto V_224;
}
V_30 -> V_207 = V_32 -> V_207 ;
V_30 -> V_13 = V_226 ;
F_100 ( & V_30 -> V_209 ) ;
F_101 ( V_30 -> V_227 , V_23 -> V_227 , sizeof( V_30 -> V_227 ) ) ;
memcpy ( V_30 -> V_214 , V_32 -> V_214 , sizeof( V_30 -> V_214 ) ) ;
V_30 -> V_215 = F_91 ( F_92 () ) ;
F_102 ( & V_30 -> V_228 ) ;
F_103 ( & V_30 -> V_229 ) ;
V_200 . V_201 ++ ;
if ( V_10 -> V_202 -- == V_10 -> V_203 )
F_104 ( V_10 ) ;
V_8 -> V_30 = V_30 ;
return 0 ;
V_224:
V_10 -> V_194 [ V_77 ] = NULL ;
F_76 ( V_10 , V_30 ) ;
return V_35 ;
}
static int F_99 ( struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
T_2 V_230 ;
V_230 = V_32 -> V_163 ;
if ( V_230 > V_151 )
return - V_16 ;
V_30 -> V_163 = V_32 -> V_163 ;
V_30 -> V_216 = V_32 -> V_216 ;
V_30 -> V_231 = 1 ;
F_89 ( V_210 , & V_30 -> V_199 ) ;
return 0 ;
}
static int F_105 ( struct V_29 * V_30 )
{
int V_35 = 0 ;
T_2 V_230 = V_30 -> V_163 ;
V_30 -> V_160 = F_106 ( V_131 ) ;
if ( ! V_30 -> V_160 )
return - V_26 ;
V_30 -> V_162 = F_106 ( V_30 -> V_134 *
V_230 ) ;
if ( ! V_30 -> V_162 ) {
V_35 = - V_26 ;
goto V_232;
}
V_30 -> V_165 = F_106 ( V_30 -> V_138 . V_139 *
V_230 ) ;
if ( ! V_30 -> V_165 ) {
V_35 = - V_26 ;
goto V_233;
}
return 0 ;
V_233:
F_107 ( V_30 -> V_162 ) ;
V_30 -> V_162 = NULL ;
V_232:
F_107 ( V_30 -> V_160 ) ;
V_30 -> V_160 = NULL ;
return V_35 ;
}
static void F_108 ( struct V_29 * V_30 )
{
unsigned int V_234 = 0 ;
V_30 -> V_235 = 0 ;
V_30 -> V_236 = 0 ;
if ( V_30 -> V_158 )
F_109 ( V_30 ) ;
F_110 ( V_30 -> V_10 , V_30 -> V_77 , V_30 -> V_215 ) ;
V_234 = V_76 ;
if ( F_111 ( V_30 -> V_13 , V_237 ) )
V_234 |= V_238 ;
if ( ! F_111 ( V_30 -> V_13 , V_239 ) )
V_234 |= V_240 ;
if ( F_111 ( V_30 -> V_13 , V_241 ) )
V_234 |= V_242 ;
if ( F_111 ( V_30 -> V_13 , V_243 ) )
V_234 |= V_244 ;
if ( F_111 ( V_30 -> V_13 , V_157 ) )
V_234 |= V_245 ;
else
V_234 |= V_189 ;
F_34 ( V_30 -> V_10 , V_234 , V_30 -> V_77 ) ;
}
static int F_15 ( struct V_7 * V_8 , void V_43 * V_246 ,
T_5 V_144 )
{
struct V_46 V_247 ;
struct V_29 * V_30 = V_8 -> V_30 ;
int V_35 = 0 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_248 = ( ( ( V_30 -> V_13 >> V_249 ) &
V_250 ) << V_251 ) |
F_111 ( V_30 -> V_13 , V_252 ) |
F_112 ( V_30 -> V_13 , V_253 ) ;
if ( ! V_8 -> V_254 )
V_247 . V_248 |= V_255 ;
V_247 . V_256 = F_113 () ;
V_247 . V_257 = V_30 -> V_10 -> V_257 ;
V_247 . V_77 = V_30 -> V_77 ;
V_247 . V_58 = V_8 -> V_58 ;
V_247 . V_258 = F_114 ( V_30 -> V_138 . V_259 ,
V_30 -> V_10 -> V_260 . V_261 ) +
V_30 -> V_262 ;
V_247 . V_118 = V_30 -> V_50 -> V_118 ;
V_247 . V_263 = V_30 -> V_127 ;
V_247 . V_264 = V_8 -> V_21 ;
V_247 . V_265 = V_30 -> V_50 -> V_116 ;
V_247 . V_266 = V_30 -> V_138 . V_259 ;
V_247 . V_267 = V_30 -> V_267 ;
V_247 . V_268 = V_30 -> V_223 << 2 ;
V_247 . V_269 = V_8 -> V_86 -> V_168 ;
V_247 . V_270 = V_30 -> V_138 . V_271 ;
F_115 ( V_30 -> V_10 , V_30 -> V_77 , V_8 -> V_58 , V_247 ) ;
if ( F_20 ( V_246 , & V_247 , sizeof( V_247 ) ) )
V_35 = - V_44 ;
return V_35 ;
}
static int F_87 ( struct V_7 * V_8 )
{
struct V_29 * V_30 = V_8 -> V_30 ;
int V_35 ;
V_35 = F_116 ( V_30 , V_8 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_117 ( V_8 ) ;
return V_35 ;
}
static int F_88 ( struct V_7 * V_8 )
{
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 = V_30 -> V_10 ;
int V_35 = 0 ;
F_118 ( V_30 -> V_50 ) ;
V_35 = F_119 ( V_10 , V_30 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_120 ( V_30 ) ;
if ( V_35 )
goto V_272;
if ( V_30 -> V_163 )
V_35 = F_105 ( V_30 ) ;
if ( V_35 )
goto V_272;
V_35 = F_121 ( V_8 ) ;
if ( V_35 )
goto V_272;
V_35 = F_87 ( V_8 ) ;
if ( V_35 )
goto V_272;
F_108 ( V_30 ) ;
return 0 ;
V_272:
F_76 ( V_10 , V_30 ) ;
return V_35 ;
}
static int F_16 ( struct V_7 * V_8 , void V_43 * V_246 ,
T_5 V_144 )
{
struct V_48 V_273 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 = V_30 -> V_10 ;
T_3 V_274 ;
unsigned V_275 ;
int V_35 = 0 ;
F_122 ( V_30 -> V_10 , V_30 , V_8 -> V_58 ) ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_276 = V_10 -> V_277 ;
V_273 . V_278 = V_279 ;
V_273 . V_280 = V_281 ;
V_273 . V_215 = V_30 -> V_215 ;
V_275 = ( ( T_1 ) V_30 -> V_50 -> V_129 -
( T_1 ) V_10 -> V_126 [ V_30 -> V_127 ] . V_128 ) % V_131 ;
V_273 . V_282 = F_123 ( V_124 , V_30 -> V_77 ,
V_8 -> V_58 , V_275 ) ;
V_273 . V_283 = F_123 ( V_112 , V_30 -> V_77 ,
V_8 -> V_58 ,
V_30 -> V_50 -> V_284 ) ;
V_273 . V_285 = F_123 ( V_113 ,
V_30 -> V_77 ,
V_8 -> V_58 ,
V_30 -> V_50 -> V_284 ) ;
V_273 . V_286 = F_123 ( V_133 , V_30 -> V_77 ,
V_8 -> V_58 ,
V_30 -> V_135 ) ;
V_273 . V_287 = F_123 ( V_136 , V_30 -> V_77 ,
V_8 -> V_58 ,
V_30 -> V_138 . V_258 [ 0 ] . V_288 ) ;
V_273 . V_289 = F_123 ( V_166 , V_30 -> V_77 ,
V_8 -> V_58 , 0 ) ;
V_273 . V_290 = F_123 ( V_145 , V_30 -> V_77 ,
V_8 -> V_58 , 0 ) ;
V_275 = F_124 ( ( ( ( V_30 -> V_77 - V_10 -> V_150 ) *
V_151 ) + V_8 -> V_58 ) *
sizeof( * V_10 -> V_149 ) ) ;
V_273 . V_291 = F_123 ( V_148 , V_30 -> V_77 ,
V_8 -> V_58 ,
V_275 ) ;
V_273 . V_292 = F_123 ( V_153 , V_30 -> V_77 ,
V_8 -> V_58 ,
V_10 -> V_155 ) ;
if ( F_27 ( V_157 ) )
V_273 . V_293 = F_123 ( V_156 , V_30 -> V_77 ,
V_8 -> V_58 , 0 ) ;
if ( V_30 -> V_163 ) {
V_273 . V_160 = F_123 ( V_159 ,
V_30 -> V_77 ,
V_8 -> V_58 , 0 ) ;
V_273 . V_294 = F_123 ( V_161 ,
V_30 -> V_77 ,
V_8 -> V_58 , 0 ) ;
V_273 . V_165 = F_123 ( V_164 ,
V_30 -> V_77 ,
V_8 -> V_58 , 0 ) ;
}
V_274 = ( V_144 < sizeof( V_273 ) ) ? V_144 : sizeof( V_273 ) ;
if ( F_20 ( V_246 , & V_273 , V_274 ) )
V_35 = - V_44 ;
return V_35 ;
}
static unsigned int F_57 ( struct V_5 * V_6 ,
struct V_175 * V_176 )
{
struct V_7 * V_8 = V_6 -> V_24 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned V_177 ;
F_125 ( V_6 , & V_30 -> V_209 , V_176 ) ;
F_126 ( & V_10 -> V_185 ) ;
if ( V_30 -> V_235 != V_30 -> V_236 ) {
V_177 = V_295 | V_296 ;
V_30 -> V_236 = V_30 -> V_235 ;
} else {
V_177 = 0 ;
F_89 ( V_297 , & V_30 -> V_199 ) ;
}
F_127 ( & V_10 -> V_185 ) ;
return V_177 ;
}
static unsigned int F_58 ( struct V_5 * V_6 ,
struct V_175 * V_176 )
{
struct V_7 * V_8 = V_6 -> V_24 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned V_177 ;
F_125 ( V_6 , & V_30 -> V_209 , V_176 ) ;
F_126 ( & V_10 -> V_185 ) ;
if ( F_128 ( V_30 ) ) {
F_89 ( V_298 , & V_30 -> V_199 ) ;
F_34 ( V_10 , V_299 , V_30 -> V_77 ) ;
V_177 = 0 ;
} else {
V_177 = V_295 | V_296 ;
}
F_127 ( & V_10 -> V_185 ) ;
return V_177 ;
}
int F_129 ( struct V_300 * V_301 , const int V_302 )
{
struct V_29 * V_30 ;
struct V_9 * V_10 = V_301 -> V_10 ;
unsigned V_77 ;
int V_35 = 0 ;
unsigned long V_13 ;
if ( ! V_10 -> V_149 ) {
V_35 = - V_16 ;
goto V_87;
}
F_68 ( & V_10 -> V_185 , V_13 ) ;
for ( V_77 = V_10 -> V_150 ; V_77 < V_10 -> V_212 ;
V_77 ++ ) {
V_30 = V_10 -> V_194 [ V_77 ] ;
if ( V_30 ) {
unsigned long * V_303 = V_10 -> V_149 +
( V_30 -> V_77 - V_10 -> V_150 ) *
V_151 ;
int V_137 ;
F_89 ( V_302 , V_303 ) ;
for ( V_137 = 1 ; V_137 < V_30 -> V_163 ; V_137 ++ )
F_89 ( V_302 , V_303 + V_137 ) ;
}
}
F_72 ( & V_10 -> V_185 , V_13 ) ;
V_87:
return V_35 ;
}
static int F_24 ( struct V_29 * V_30 , T_2 V_58 ,
int V_304 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned int V_305 ;
if ( V_58 )
goto V_306;
if ( V_304 ) {
if ( V_30 -> V_158 )
F_109 ( V_30 ) ;
V_305 = V_76 ;
} else {
V_305 = V_186 ;
}
F_34 ( V_10 , V_305 , V_30 -> V_77 ) ;
V_306:
return 0 ;
}
static int F_26 ( struct V_29 * V_30 , T_2 V_58 ,
unsigned long V_149 )
{
int V_137 ;
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned long * V_303 ;
if ( ! V_10 -> V_149 )
return 0 ;
V_303 = V_10 -> V_149 + ( ( V_30 -> V_77 - V_10 -> V_150 ) *
V_151 ) + V_58 ;
for ( V_137 = 0 ; V_137 <= V_307 ; V_137 ++ ) {
if ( ! F_85 ( V_137 , & V_149 ) )
continue;
F_86 ( V_137 , V_303 ) ;
}
return 0 ;
}
static int F_28 ( struct V_29 * V_30 , T_2 V_58 , T_2 V_308 )
{
int V_35 = - V_309 , V_137 , V_310 = 0 ;
struct V_300 * V_301 = V_30 -> V_301 ;
struct V_9 * V_10 = V_30 -> V_10 ;
if ( V_308 == V_311 || V_308 == V_312 ) {
V_35 = - V_16 ;
goto V_87;
}
for ( V_137 = 0 ; V_137 < F_130 ( V_301 -> V_313 ) ; V_137 ++ )
if ( V_308 == V_301 -> V_313 [ V_137 ] ) {
V_310 = 1 ;
break;
}
if ( V_310 )
V_35 = F_131 ( V_10 , V_30 -> V_77 , V_308 ) ;
V_87:
return V_35 ;
}
static void F_132 ( struct V_9 * V_10 )
{
F_133 ( & V_10 -> V_12 , & V_10 -> V_314 ) ;
}
static int F_134 ( struct V_9 * V_10 )
{
char V_315 [ 10 ] ;
int V_35 ;
snprintf ( V_315 , sizeof( V_315 ) , L_10 , F_135 () , V_10 -> V_257 ) ;
V_35 = F_136 ( V_10 -> V_257 , V_315 , & V_316 ,
& V_10 -> V_12 , & V_10 -> V_314 ,
true , & V_10 -> V_19 ) ;
if ( V_35 )
F_132 ( V_10 ) ;
return V_35 ;
}
int F_137 ( struct V_9 * V_10 )
{
return F_134 ( V_10 ) ;
}
void F_138 ( struct V_9 * V_10 )
{
F_132 ( V_10 ) ;
}
