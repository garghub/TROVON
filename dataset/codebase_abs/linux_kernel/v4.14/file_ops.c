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
sizeof( V_34 . V_53 ) ) )
return - V_44 ;
V_36 = V_28 + F_19 ( struct V_33 , V_54 ) ;
if ( F_20 ( ( void V_43 * ) V_36 , & V_34 . V_54 ,
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
F_34 ( V_10 , V_76 , V_30 ) ;
} else {
V_35 = F_35 ( V_50 ) ;
}
if ( ! V_35 )
F_17 ( V_50 ) ;
break;
}
case V_42 :
V_37 = V_77 ;
if ( F_36 ( V_37 , ( int V_43 * ) V_28 ) )
return - V_44 ;
break;
default:
return - V_16 ;
}
return V_35 ;
}
static T_3 F_37 ( struct V_78 * V_78 , struct V_79 * V_80 )
{
struct V_7 * V_8 = V_78 -> V_81 -> V_24 ;
struct V_82 * V_83 = V_8 -> V_83 ;
struct V_84 * V_85 = V_8 -> V_85 ;
int V_86 = 0 , V_87 = 0 ;
unsigned long V_88 = V_80 -> V_89 ;
if ( ! V_85 || ! V_83 )
return - V_90 ;
if ( ! F_38 ( V_80 ) || ! V_88 )
return - V_16 ;
F_39 ( V_8 -> V_10 , V_8 -> V_30 -> V_91 , V_8 -> V_58 , V_88 ) ;
if ( F_40 ( & V_83 -> V_92 ) == V_83 -> V_93 )
return - V_94 ;
while ( V_88 ) {
int V_35 ;
unsigned long V_95 = 0 ;
V_35 = F_41 (
V_8 , (struct V_96 * ) ( V_80 -> V_97 + V_86 ) ,
V_88 , & V_95 ) ;
if ( V_35 ) {
V_87 = V_35 ;
break;
}
V_88 -= V_95 ;
V_86 += V_95 ;
V_87 ++ ;
}
return V_87 ;
}
static int F_42 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
struct V_7 * V_8 = V_6 -> V_24 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 ;
unsigned long V_13 ;
T_1 V_1 = V_99 -> V_100 << V_101 ,
V_102 = 0 ;
void * V_103 = NULL ;
T_4 V_58 , V_104 = 0 , V_105 = 0 , type ;
T_3 V_106 = 0 ;
int V_35 = 0 ;
T_2 V_91 ;
if ( ! F_1 ( V_1 ) || ! V_30 ||
! ( V_99 -> V_107 & V_108 ) ) {
V_35 = - V_16 ;
goto V_86;
}
V_10 = V_30 -> V_10 ;
V_91 = F_2 ( V_109 , V_1 ) ;
V_58 = F_2 ( V_110 , V_1 ) ;
type = F_2 ( TYPE , V_1 ) ;
if ( V_91 != V_30 -> V_91 || V_58 != V_8 -> V_58 ) {
V_35 = - V_16 ;
goto V_86;
}
V_13 = V_99 -> V_107 ;
switch ( type ) {
case V_111 :
case V_112 :
V_102 = ( ( V_10 -> V_113 + V_114 ) +
( V_30 -> V_50 -> V_115 * F_43 ( 16 ) ) ) +
( type == V_112 ?
( V_116 / 2 ) : 0 ) ;
V_106 = F_44 ( V_30 -> V_50 -> V_117 * V_118 ) ;
V_13 &= ~ V_119 ;
V_13 |= V_120 | V_121 ;
V_99 -> V_122 = F_45 ( V_99 -> V_122 ) ;
V_104 = 1 ;
break;
case V_123 :
if ( V_13 & V_124 ) {
V_35 = - V_64 ;
goto V_86;
}
V_103 = V_10 -> V_125 [ V_30 -> V_126 ] . V_127 ;
V_102 = F_46 ( V_103 ) +
( ( ( T_1 ) V_30 -> V_50 -> V_128 -
( T_1 ) V_10 -> V_125 [ V_30 -> V_126 ] . V_127 ) & V_129 ) ;
V_106 = V_130 ;
V_13 &= ~ V_131 ;
V_13 |= V_120 | V_121 ;
V_104 = 1 ;
break;
case V_132 :
V_106 = V_30 -> V_133 ;
V_103 = V_30 -> V_134 ;
break;
case V_135 : {
unsigned long V_36 ;
int V_136 ;
V_106 = V_30 -> V_137 . V_138 ;
if ( ( V_99 -> V_139 - V_99 -> V_140 ) != V_106 ) {
F_47 ( V_10 , L_2 ,
( V_99 -> V_139 - V_99 -> V_140 ) , V_106 ) ;
V_35 = - V_16 ;
goto V_86;
}
if ( V_99 -> V_107 & V_124 ) {
V_35 = - V_64 ;
goto V_86;
}
V_99 -> V_107 &= ~ V_131 ;
V_36 = V_99 -> V_140 ;
for ( V_136 = 0 ; V_136 < V_30 -> V_137 . V_141 ; V_136 ++ ) {
V_106 = V_30 -> V_137 . V_142 [ V_136 ] . V_143 ;
V_103 = V_30 -> V_137 . V_142 [ V_136 ] . V_36 ;
V_35 = F_48 (
V_99 , V_36 ,
F_49 ( F_50 ( V_103 ) ) ,
V_106 ,
V_99 -> V_122 ) ;
if ( V_35 < 0 )
goto V_86;
V_36 += V_106 ;
}
V_35 = 0 ;
goto V_86;
}
case V_144 :
V_102 = ( unsigned long )
( V_10 -> V_113 + V_145 )
+ ( V_30 -> V_91 * V_146 ) ;
V_106 = V_130 ;
V_13 |= V_120 | V_121 ;
V_99 -> V_122 = F_51 ( V_99 -> V_122 ) ;
V_104 = 1 ;
break;
case V_147 :
V_102 = ( unsigned long ) ( V_10 -> V_148 +
( ( V_30 -> V_91 - V_10 -> V_149 ) *
V_150 ) ) & V_129 ;
V_106 = V_130 ;
V_13 |= V_151 | V_121 ;
V_105 = 1 ;
break;
case V_152 :
if ( V_13 & ( unsigned long ) ( V_124 | V_153 ) ) {
V_35 = - V_64 ;
goto V_86;
}
V_102 = F_52 ( ( void * ) V_10 -> V_154 ) ;
V_106 = V_130 ;
V_13 |= V_151 | V_121 ;
break;
case V_155 :
if ( ! F_27 ( V_156 ) ) {
V_35 = - V_16 ;
goto V_86;
}
if ( V_13 & V_124 ) {
V_35 = - V_64 ;
goto V_86;
}
V_106 = V_130 ;
V_103 = ( void * ) V_30 -> V_157 ;
V_13 &= ~ V_131 ;
break;
case V_158 :
V_102 = ( T_1 ) V_30 -> V_159 ;
V_106 = V_130 ;
V_13 |= V_151 | V_121 ;
V_105 = 1 ;
break;
case V_160 :
V_102 = ( T_1 ) V_30 -> V_161 ;
V_106 = V_30 -> V_133 * V_30 -> V_162 ;
V_13 |= V_151 | V_121 ;
V_105 = 1 ;
break;
case V_163 :
V_102 = ( T_1 ) V_30 -> V_164 ;
V_106 = V_30 -> V_137 . V_138 * V_30 -> V_162 ;
V_13 |= V_151 | V_121 ;
V_13 &= ~ V_131 ;
V_105 = 1 ;
break;
case V_165 : {
struct V_84 * V_85 = V_8 -> V_85 ;
if ( ! V_85 ) {
V_35 = - V_44 ;
goto V_86;
}
V_102 = ( T_1 ) V_85 -> V_166 ;
V_106 = F_44 ( sizeof( * V_85 -> V_166 ) * V_85 -> V_167 ) ;
V_13 |= V_151 | V_121 ;
V_105 = 1 ;
break;
}
default:
V_35 = - V_16 ;
break;
}
if ( ( V_99 -> V_139 - V_99 -> V_140 ) != V_106 ) {
F_12 ( V_168 , L_3 ,
V_30 -> V_91 , V_8 -> V_58 ,
( V_99 -> V_139 - V_99 -> V_140 ) , V_106 ) ;
V_35 = - V_16 ;
goto V_86;
}
V_99 -> V_107 = V_13 ;
F_12 ( V_168 ,
L_4 ,
V_91 , V_58 , type , V_104 , V_105 , V_102 , V_106 ,
V_99 -> V_139 - V_99 -> V_140 , V_99 -> V_107 ) ;
if ( V_105 ) {
V_99 -> V_100 = F_49 ( V_102 ) ;
V_99 -> V_169 = & V_169 ;
V_35 = 0 ;
} else if ( V_104 ) {
V_35 = F_53 ( V_99 , V_99 -> V_140 ,
F_49 ( V_102 ) ,
V_106 ,
V_99 -> V_122 ) ;
} else if ( V_103 ) {
V_35 = F_48 ( V_99 , V_99 -> V_140 ,
F_49 ( F_50 ( V_103 ) ) ,
V_106 ,
V_99 -> V_122 ) ;
} else {
V_35 = F_48 ( V_99 , V_99 -> V_140 ,
F_49 ( V_102 ) ,
V_106 ,
V_99 -> V_122 ) ;
}
V_86:
return V_35 ;
}
static int F_54 ( struct V_170 * V_105 )
{
struct V_171 * V_171 ;
V_171 = F_55 ( ( void * ) ( V_105 -> V_172 << V_101 ) ) ;
if ( ! V_171 )
return V_173 ;
F_56 ( V_171 ) ;
V_105 -> V_171 = V_171 ;
return 0 ;
}
static unsigned int F_57 ( struct V_5 * V_6 , struct V_174 * V_175 )
{
struct V_29 * V_30 ;
unsigned V_176 ;
V_30 = ( (struct V_7 * ) V_6 -> V_24 ) -> V_30 ;
if ( ! V_30 )
V_176 = V_177 ;
else if ( V_30 -> V_60 == V_178 )
V_176 = F_58 ( V_6 , V_175 ) ;
else if ( V_30 -> V_60 == V_179 )
V_176 = F_59 ( V_6 , V_175 ) ;
else
V_176 = V_177 ;
return V_176 ;
}
static int F_60 ( struct V_4 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_180 = V_6 -> V_24 ;
struct V_29 * V_30 = V_180 -> V_30 ;
struct V_9 * V_10 = F_4 ( V_4 -> V_11 ,
struct V_9 ,
V_12 ) ;
unsigned long V_13 , * V_181 ;
V_6 -> V_24 = NULL ;
if ( ! V_30 )
goto V_86;
F_12 ( V_168 , L_5 , V_30 -> V_91 , V_180 -> V_58 ) ;
F_61 () ;
F_62 ( V_180 , V_30 ) ;
F_63 ( V_180 -> V_21 ) ;
F_64 ( V_180 ) ;
V_180 -> V_30 = NULL ;
F_65 ( V_30 ) ;
V_181 = V_10 -> V_148 + ( ( V_30 -> V_91 - V_10 -> V_149 ) *
V_150 ) + V_180 -> V_58 ;
* V_181 = 0 ;
F_66 ( & V_10 -> V_182 , V_13 ) ;
F_67 ( V_180 -> V_58 , V_30 -> V_183 ) ;
if ( ! F_68 ( V_30 -> V_183 , V_150 ) ) {
F_69 ( & V_10 -> V_182 , V_13 ) ;
goto V_86;
}
F_69 ( & V_10 -> V_182 , V_13 ) ;
F_34 ( V_10 , V_184 |
V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 , V_30 ) ;
F_70 ( V_10 , V_30 ) ;
if ( V_30 -> V_50 ) {
F_71 ( V_30 -> V_50 ) ;
F_32 ( V_30 -> V_50 ) ;
}
F_72 ( V_30 ) ;
F_73 ( V_10 , V_30 ) ;
V_30 -> V_191 = 0 ;
F_74 ( V_30 ) ;
V_86:
F_75 ( V_180 -> V_22 ) ;
F_76 ( & V_10 -> V_19 ) ;
if ( F_9 ( & V_10 -> V_17 ) )
F_10 ( & V_10 -> V_25 ) ;
F_77 ( V_180 ) ;
return 0 ;
}
static T_1 F_52 ( void * V_36 )
{
struct V_171 * V_171 ;
T_1 V_192 = 0 ;
V_171 = F_55 ( V_36 ) ;
if ( V_171 )
V_192 = F_78 ( V_171 ) << V_101 ;
return V_192 ;
}
static int F_79 ( struct V_7 * V_8 )
{
int V_35 ;
unsigned long V_13 ;
V_35 = F_80 (
V_8 -> V_30 -> V_193 ,
! F_81 ( V_194 , & V_8 -> V_30 -> V_191 ) ) ;
if ( F_81 ( V_195 , & V_8 -> V_30 -> V_191 ) )
V_35 = - V_26 ;
if ( ! V_35 ) {
V_8 -> V_21 = F_82 ( V_8 -> V_30 -> V_126 ) ;
V_35 = F_83 ( V_8 , V_8 -> V_30 ) ;
}
if ( V_35 ) {
F_65 ( V_8 -> V_30 ) ;
V_8 -> V_30 = NULL ;
F_66 ( & V_8 -> V_10 -> V_182 , V_13 ) ;
F_67 ( V_8 -> V_58 , V_8 -> V_30 -> V_183 ) ;
F_69 ( & V_8 -> V_10 -> V_182 , V_13 ) ;
}
return V_35 ;
}
static int F_14 ( struct V_7 * V_8 , struct V_31 * V_32 )
{
int V_35 ;
unsigned int V_196 , V_197 ;
struct V_29 * V_30 = NULL ;
V_196 = V_32 -> V_198 >> 16 ;
if ( V_196 != V_199 )
return - V_75 ;
if ( V_32 -> V_162 > V_150 )
return - V_16 ;
V_197 = V_32 -> V_198 & 0xffff ;
F_84 ( & V_200 ) ;
V_35 = F_85 ( V_8 , V_32 ) ;
if ( ! V_35 )
V_35 = F_86 ( V_8 , V_8 -> V_10 , V_32 , & V_30 ) ;
F_87 ( & V_200 ) ;
switch ( V_35 ) {
case 0 :
V_35 = F_88 ( V_8 , V_30 ) ;
if ( V_35 )
F_74 ( V_30 ) ;
break;
case 1 :
V_35 = F_79 ( V_8 ) ;
break;
default:
break;
}
return V_35 ;
}
static int F_89 ( struct V_7 * V_8 ,
const struct V_31 * V_32 ,
struct V_29 * V_30 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
unsigned long V_13 ;
T_2 V_58 ;
if ( V_30 -> V_50 && ( V_30 -> V_50 -> type == V_201 ) )
return 0 ;
if ( memcmp ( V_30 -> V_202 , V_32 -> V_202 , sizeof( V_30 -> V_202 ) ) ||
V_30 -> V_203 != F_90 ( F_91 () ) ||
V_30 -> V_204 != V_32 -> V_204 ||
V_30 -> V_162 != V_32 -> V_162 )
return 0 ;
if ( V_30 -> V_198 != V_32 -> V_198 )
return - V_16 ;
F_66 ( & V_10 -> V_182 , V_13 ) ;
if ( F_68 ( V_30 -> V_183 , V_150 ) ) {
F_69 ( & V_10 -> V_182 , V_13 ) ;
return 0 ;
}
V_58 = F_92 ( V_30 -> V_183 ,
V_150 ) ;
if ( V_58 >= V_30 -> V_162 ) {
F_69 ( & V_10 -> V_182 , V_13 ) ;
return - V_205 ;
}
V_8 -> V_58 = V_58 ;
F_93 ( V_8 -> V_58 , V_30 -> V_183 ) ;
F_69 ( & V_10 -> V_182 , V_13 ) ;
V_8 -> V_30 = V_30 ;
F_94 ( V_30 ) ;
return 1 ;
}
static int F_85 ( struct V_7 * V_8 ,
const struct V_31 * V_32 )
{
struct V_29 * V_30 ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_2 V_136 ;
int V_35 ;
if ( ! V_32 -> V_162 )
return 0 ;
for ( V_136 = V_10 -> V_149 ; V_136 < V_10 -> V_206 ; V_136 ++ ) {
V_30 = F_95 ( V_10 , V_136 ) ;
if ( V_30 ) {
V_35 = F_89 ( V_8 , V_32 , V_30 ) ;
F_65 ( V_30 ) ;
if ( V_35 )
return V_35 ;
}
}
return 0 ;
}
static int F_86 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_31 * V_32 ,
struct V_29 * * V_207 )
{
struct V_29 * V_30 ;
int V_35 , V_208 ;
if ( V_10 -> V_13 & V_73 ) {
return - V_90 ;
}
if ( ! V_10 -> V_209 )
return - V_205 ;
V_8 -> V_21 = F_82 ( V_10 -> V_210 ) ;
if ( V_8 -> V_21 != - 1 )
V_208 = F_96 ( V_8 -> V_21 ) ;
else
V_208 = F_97 () ;
V_35 = F_98 ( V_10 -> V_211 , V_208 , & V_30 ) ;
if ( V_35 < 0 ) {
F_47 ( V_10 , L_6 ) ;
return V_35 ;
}
F_12 ( V_168 , L_7 ,
V_30 -> V_91 , V_8 -> V_58 , V_23 -> V_212 , V_8 -> V_21 ,
V_30 -> V_126 ) ;
V_30 -> V_50 = F_99 ( V_10 , V_213 , V_30 -> V_214 , V_10 -> V_210 ) ;
if ( ! V_30 -> V_50 ) {
V_35 = - V_26 ;
goto V_215;
}
F_12 ( V_168 , L_8 , V_30 -> V_50 -> V_216 ,
V_30 -> V_50 -> V_115 ) ;
V_35 = F_33 ( V_30 -> V_50 ) ;
if ( V_35 )
goto V_215;
if ( V_32 -> V_162 )
F_100 ( V_30 , V_32 ) ;
V_30 -> V_198 = V_32 -> V_198 ;
V_30 -> V_13 = V_217 ;
F_101 ( & V_30 -> V_193 ) ;
F_102 ( V_30 -> V_218 , V_23 -> V_218 , sizeof( V_30 -> V_218 ) ) ;
memcpy ( V_30 -> V_202 , V_32 -> V_202 , sizeof( V_30 -> V_202 ) ) ;
V_30 -> V_203 = F_90 ( F_91 () ) ;
V_219 . V_220 ++ ;
if ( V_10 -> V_209 -- == V_10 -> V_221 )
F_103 ( V_10 ) ;
* V_207 = V_30 ;
return 0 ;
V_215:
F_104 ( V_30 ) ;
return V_35 ;
}
static void F_74 ( struct V_29 * V_30 )
{
F_84 ( & V_200 ) ;
V_219 . V_220 -- ;
if ( ++ V_30 -> V_10 -> V_209 == V_30 -> V_10 -> V_221 )
F_105 ( V_30 -> V_10 ) ;
F_87 ( & V_200 ) ;
F_104 ( V_30 ) ;
}
static void F_100 ( struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
V_30 -> V_162 = V_32 -> V_162 ;
V_30 -> V_204 = V_32 -> V_204 ;
F_106 ( V_194 , & V_30 -> V_191 ) ;
}
static int F_107 ( struct V_29 * V_30 )
{
int V_35 = 0 ;
T_2 V_222 = V_30 -> V_162 ;
V_30 -> V_159 = F_108 ( V_130 ) ;
if ( ! V_30 -> V_159 )
return - V_26 ;
V_30 -> V_161 = F_108 ( V_30 -> V_133 *
V_222 ) ;
if ( ! V_30 -> V_161 ) {
V_35 = - V_26 ;
goto V_223;
}
V_30 -> V_164 = F_108 ( V_30 -> V_137 . V_138 *
V_222 ) ;
if ( ! V_30 -> V_164 ) {
V_35 = - V_26 ;
goto V_224;
}
return 0 ;
V_224:
F_109 ( V_30 -> V_161 ) ;
V_30 -> V_161 = NULL ;
V_223:
F_109 ( V_30 -> V_159 ) ;
V_30 -> V_159 = NULL ;
return V_35 ;
}
static void F_110 ( struct V_29 * V_30 )
{
unsigned int V_225 = 0 ;
V_30 -> V_226 = 0 ;
V_30 -> V_227 = 0 ;
if ( V_30 -> V_157 )
F_111 ( V_30 ) ;
F_112 ( V_30 -> V_10 , V_30 , V_30 -> V_203 ) ;
V_225 = V_76 ;
if ( F_113 ( V_30 -> V_13 , V_228 ) )
V_225 |= V_229 ;
if ( ! F_113 ( V_30 -> V_13 , V_230 ) )
V_225 |= V_231 ;
if ( F_113 ( V_30 -> V_13 , V_232 ) )
V_225 |= V_233 ;
if ( F_113 ( V_30 -> V_13 , V_234 ) )
V_225 |= V_235 ;
if ( F_113 ( V_30 -> V_13 , V_156 ) )
V_225 |= V_236 ;
else
V_225 |= V_187 ;
F_34 ( V_30 -> V_10 , V_225 , V_30 ) ;
}
static int F_15 ( struct V_7 * V_8 , void V_43 * V_237 ,
T_5 V_143 )
{
struct V_46 V_238 ;
struct V_29 * V_30 = V_8 -> V_30 ;
int V_35 = 0 ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_239 = ( ( ( V_30 -> V_13 >> V_240 ) &
V_241 ) << V_242 ) |
F_113 ( V_30 -> V_13 , V_243 ) |
F_114 ( V_30 -> V_13 , V_244 ) ;
if ( ! V_8 -> V_245 )
V_238 . V_239 |= V_246 ;
V_238 . V_247 = F_115 () ;
V_238 . V_248 = V_30 -> V_10 -> V_248 ;
V_238 . V_91 = V_30 -> V_91 ;
V_238 . V_58 = V_8 -> V_58 ;
V_238 . V_249 = F_116 ( V_30 -> V_137 . V_250 ,
V_30 -> V_10 -> V_251 . V_252 ) +
V_30 -> V_253 ;
V_238 . V_117 = V_30 -> V_50 -> V_117 ;
V_238 . V_254 = V_30 -> V_126 ;
V_238 . V_255 = V_8 -> V_21 ;
V_238 . V_256 = V_30 -> V_50 -> V_115 ;
V_238 . V_257 = V_30 -> V_137 . V_250 ;
V_238 . V_258 = V_30 -> V_258 ;
V_238 . V_259 = V_30 -> V_214 << 2 ;
V_238 . V_260 = V_8 -> V_85 -> V_167 ;
V_238 . V_261 = V_30 -> V_137 . V_262 ;
F_117 ( V_30 -> V_10 , V_30 -> V_91 , V_8 -> V_58 , V_238 ) ;
if ( F_20 ( V_237 , & V_238 , sizeof( V_238 ) ) )
V_35 = - V_44 ;
return V_35 ;
}
static int F_83 ( struct V_7 * V_8 ,
struct V_29 * V_30 )
{
int V_35 ;
V_35 = F_118 ( V_30 , V_8 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_119 ( V_8 , V_30 ) ;
if ( V_35 )
F_62 ( V_8 , V_30 ) ;
return V_35 ;
}
static int F_88 ( struct V_7 * V_8 ,
struct V_29 * V_30 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
int V_35 = 0 ;
F_120 ( V_30 -> V_50 ) ;
V_35 = F_121 ( V_10 , V_30 ) ;
if ( V_35 )
goto V_86;
V_35 = F_122 ( V_30 ) ;
if ( V_35 )
goto V_86;
if ( V_30 -> V_162 )
V_35 = F_107 ( V_30 ) ;
if ( V_35 )
goto V_86;
V_35 = F_123 ( V_30 ) ;
if ( V_35 )
goto V_86;
V_35 = F_83 ( V_8 , V_30 ) ;
if ( V_35 )
goto V_86;
F_110 ( V_30 ) ;
V_8 -> V_30 = V_30 ;
F_94 ( V_30 ) ;
V_86:
if ( V_30 -> V_162 ) {
if ( V_35 )
F_106 ( V_195 , & V_30 -> V_191 ) ;
F_124 ( V_194 , & V_30 -> V_191 ) ;
F_125 ( & V_30 -> V_193 ) ;
}
return V_35 ;
}
static int F_16 ( struct V_7 * V_8 , void V_43 * V_237 ,
T_5 V_143 )
{
struct V_48 V_263 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 = V_30 -> V_10 ;
T_3 V_264 ;
unsigned V_265 ;
int V_35 = 0 ;
F_126 ( V_30 -> V_10 , V_30 , V_8 -> V_58 ) ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_266 = V_10 -> V_267 ;
V_263 . V_268 = V_269 ;
V_263 . V_270 = V_271 ;
V_263 . V_203 = V_30 -> V_203 ;
V_265 = ( ( T_1 ) V_30 -> V_50 -> V_128 -
( T_1 ) V_10 -> V_125 [ V_30 -> V_126 ] . V_127 ) % V_130 ;
V_263 . V_272 = F_127 ( V_123 , V_30 -> V_91 ,
V_8 -> V_58 , V_265 ) ;
V_263 . V_273 = F_127 ( V_111 , V_30 -> V_91 ,
V_8 -> V_58 ,
V_30 -> V_50 -> V_274 ) ;
V_263 . V_275 = F_127 ( V_112 ,
V_30 -> V_91 ,
V_8 -> V_58 ,
V_30 -> V_50 -> V_274 ) ;
V_263 . V_276 = F_127 ( V_132 , V_30 -> V_91 ,
V_8 -> V_58 ,
V_30 -> V_134 ) ;
V_263 . V_277 = F_127 ( V_135 , V_30 -> V_91 ,
V_8 -> V_58 ,
V_30 -> V_137 . V_249 [ 0 ] . V_278 ) ;
V_263 . V_279 = F_127 ( V_165 , V_30 -> V_91 ,
V_8 -> V_58 , 0 ) ;
V_263 . V_280 = F_127 ( V_144 , V_30 -> V_91 ,
V_8 -> V_58 , 0 ) ;
V_265 = F_128 ( ( ( ( V_30 -> V_91 - V_10 -> V_149 ) *
V_150 ) + V_8 -> V_58 ) *
sizeof( * V_10 -> V_148 ) ) ;
V_263 . V_281 = F_127 ( V_147 , V_30 -> V_91 ,
V_8 -> V_58 ,
V_265 ) ;
V_263 . V_282 = F_127 ( V_152 , V_30 -> V_91 ,
V_8 -> V_58 ,
V_10 -> V_154 ) ;
if ( F_27 ( V_156 ) )
V_263 . V_283 = F_127 ( V_155 , V_30 -> V_91 ,
V_8 -> V_58 , 0 ) ;
if ( V_30 -> V_162 ) {
V_263 . V_159 = F_127 ( V_158 ,
V_30 -> V_91 ,
V_8 -> V_58 , 0 ) ;
V_263 . V_284 = F_127 ( V_160 ,
V_30 -> V_91 ,
V_8 -> V_58 , 0 ) ;
V_263 . V_164 = F_127 ( V_163 ,
V_30 -> V_91 ,
V_8 -> V_58 , 0 ) ;
}
V_264 = ( V_143 < sizeof( V_263 ) ) ? V_143 : sizeof( V_263 ) ;
if ( F_20 ( V_237 , & V_263 , V_264 ) )
V_35 = - V_44 ;
return V_35 ;
}
static unsigned int F_58 ( struct V_5 * V_6 ,
struct V_174 * V_175 )
{
struct V_7 * V_8 = V_6 -> V_24 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned V_176 ;
F_129 ( V_6 , & V_30 -> V_193 , V_175 ) ;
F_130 ( & V_10 -> V_182 ) ;
if ( V_30 -> V_226 != V_30 -> V_227 ) {
V_176 = V_285 | V_286 ;
V_30 -> V_227 = V_30 -> V_226 ;
} else {
V_176 = 0 ;
F_106 ( V_287 , & V_30 -> V_191 ) ;
}
F_131 ( & V_10 -> V_182 ) ;
return V_176 ;
}
static unsigned int F_59 ( struct V_5 * V_6 ,
struct V_174 * V_175 )
{
struct V_7 * V_8 = V_6 -> V_24 ;
struct V_29 * V_30 = V_8 -> V_30 ;
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned V_176 ;
F_129 ( V_6 , & V_30 -> V_193 , V_175 ) ;
F_130 ( & V_10 -> V_182 ) ;
if ( F_132 ( V_30 ) ) {
F_106 ( V_288 , & V_30 -> V_191 ) ;
F_34 ( V_10 , V_289 , V_30 ) ;
V_176 = 0 ;
} else {
V_176 = V_285 | V_286 ;
}
F_131 ( & V_10 -> V_182 ) ;
return V_176 ;
}
int F_133 ( struct V_290 * V_291 , const int V_292 )
{
struct V_29 * V_30 ;
struct V_9 * V_10 = V_291 -> V_10 ;
T_2 V_91 ;
if ( ! V_10 -> V_148 )
return - V_16 ;
for ( V_91 = V_10 -> V_149 ; V_91 < V_10 -> V_206 ;
V_91 ++ ) {
V_30 = F_95 ( V_10 , V_91 ) ;
if ( V_30 ) {
unsigned long * V_293 = V_10 -> V_148 +
( V_30 -> V_91 - V_10 -> V_149 ) *
V_150 ;
int V_136 ;
F_106 ( V_292 , V_293 ) ;
for ( V_136 = 1 ; V_136 < V_30 -> V_162 ; V_136 ++ )
F_106 ( V_292 , V_293 + V_136 ) ;
F_65 ( V_30 ) ;
}
}
return 0 ;
}
static int F_24 ( struct V_29 * V_30 , T_2 V_58 ,
int V_294 )
{
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned int V_295 ;
if ( V_58 )
goto V_296;
if ( V_294 ) {
if ( V_30 -> V_157 )
F_111 ( V_30 ) ;
V_295 = V_76 ;
} else {
V_295 = V_184 ;
}
F_34 ( V_10 , V_295 , V_30 ) ;
V_296:
return 0 ;
}
static int F_26 ( struct V_29 * V_30 , T_2 V_58 ,
unsigned long V_148 )
{
int V_136 ;
struct V_9 * V_10 = V_30 -> V_10 ;
unsigned long * V_293 ;
if ( ! V_10 -> V_148 )
return 0 ;
V_293 = V_10 -> V_148 + ( ( V_30 -> V_91 - V_10 -> V_149 ) *
V_150 ) + V_58 ;
for ( V_136 = 0 ; V_136 <= V_297 ; V_136 ++ ) {
if ( ! F_81 ( V_136 , & V_148 ) )
continue;
F_124 ( V_136 , V_293 ) ;
}
return 0 ;
}
static int F_28 ( struct V_29 * V_30 , T_2 V_58 , T_2 V_298 )
{
int V_35 = - V_299 , V_136 , V_300 = 0 ;
struct V_290 * V_291 = V_30 -> V_291 ;
struct V_9 * V_10 = V_30 -> V_10 ;
if ( V_298 == V_301 || V_298 == V_302 ) {
V_35 = - V_16 ;
goto V_86;
}
for ( V_136 = 0 ; V_136 < F_134 ( V_291 -> V_303 ) ; V_136 ++ )
if ( V_298 == V_291 -> V_303 [ V_136 ] ) {
V_300 = 1 ;
break;
}
if ( V_300 )
V_35 = F_135 ( V_10 , V_30 , V_298 ) ;
V_86:
return V_35 ;
}
static void F_136 ( struct V_9 * V_10 )
{
F_137 ( & V_10 -> V_12 , & V_10 -> V_304 ) ;
}
static int F_138 ( struct V_9 * V_10 )
{
char V_305 [ 10 ] ;
int V_35 ;
snprintf ( V_305 , sizeof( V_305 ) , L_9 , F_139 () , V_10 -> V_248 ) ;
V_35 = F_140 ( V_10 -> V_248 , V_305 , & V_306 ,
& V_10 -> V_12 , & V_10 -> V_304 ,
true , & V_10 -> V_19 ) ;
if ( V_35 )
F_136 ( V_10 ) ;
return V_35 ;
}
int F_141 ( struct V_9 * V_10 )
{
return F_138 ( V_10 ) ;
}
void F_142 ( struct V_9 * V_10 )
{
F_136 ( V_10 ) ;
}
