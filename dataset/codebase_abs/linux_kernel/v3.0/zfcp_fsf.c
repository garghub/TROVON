static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( V_3 ) ;
F_3 ( V_3 , V_4 ,
L_1 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
unsigned long V_7 )
{
V_6 -> V_8 . V_9 = F_1 ;
V_6 -> V_8 . V_1 = ( unsigned long ) V_6 -> V_3 ;
V_6 -> V_8 . V_10 = V_11 + V_7 ;
F_5 ( & V_6 -> V_8 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
F_7 ( ! V_6 -> V_12 ) ;
V_6 -> V_8 . V_9 = V_13 ;
V_6 -> V_8 . V_1 = ( unsigned long ) V_6 -> V_12 ;
V_6 -> V_8 . V_10 = V_11 + 30 * V_14 ;
F_5 ( & V_6 -> V_8 ) ;
}
static void F_8 ( struct V_5 * V_15 )
{
F_9 ( & V_15 -> V_3 -> V_16 -> V_17 , L_2
L_3 ) ;
F_10 ( V_15 -> V_3 , 0 , L_4 ) ;
V_15 -> V_18 |= V_19 ;
}
void F_11 ( struct V_5 * V_15 )
{
if ( F_12 ( V_15 -> V_20 ) ) {
if ( F_12 ( V_15 -> V_21 ) )
F_13 ( V_15 -> V_21 , V_15 -> V_3 -> V_20 . V_22 ) ;
F_13 ( V_15 , V_15 -> V_20 ) ;
return;
}
if ( F_12 ( V_15 -> V_21 ) )
F_14 ( V_23 , V_15 -> V_21 ) ;
F_15 ( V_15 ) ;
}
static void F_16 ( struct V_5 * V_15 )
{
unsigned long V_24 ;
struct V_25 * V_26 = V_15 -> V_1 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_27 * V_28 ;
int V_29 = F_17 ( V_26 -> V_29 ) ;
F_18 ( & V_3 -> V_30 , V_24 ) ;
F_19 (port, &adapter->port_list, list)
if ( V_28 -> V_29 == V_29 ) {
F_20 ( V_28 , 0 , L_5 ) ;
break;
}
F_21 ( & V_3 -> V_30 , V_24 ) ;
}
static void F_22 ( struct V_5 * V_15 ,
struct V_31 * V_32 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
if ( F_23 ( & V_3 -> V_18 ) & V_33 )
return;
F_24 ( V_33 , & V_3 -> V_18 ) ;
F_25 ( V_3 ) ;
if ( ! V_32 )
goto V_34;
switch ( V_32 -> V_35 ) {
case V_36 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_6
L_7 ) ;
break;
case V_37 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_8
L_9 ) ;
break;
case V_38 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_10
L_11 ) ;
break;
case V_39 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_12
L_13 ) ;
break;
case V_40 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_14
L_15 ) ;
break;
case V_41 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_16 ) ;
break;
case V_42 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_17 ) ;
break;
case V_43 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_18
L_19 ) ;
break;
case V_44 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_20
L_21 ) ;
break;
case V_45 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_22
L_23 ) ;
break;
case V_46 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_24
L_23 ) ;
break;
case V_47 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_25
L_26 ) ;
break;
default:
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_27
L_28 ) ;
}
V_34:
F_27 ( V_3 , V_4 ) ;
}
static void F_28 ( struct V_5 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_1 ;
struct V_31 * V_48 =
(struct V_31 * ) & V_26 -> V_49 ;
switch ( V_26 -> V_50 ) {
case V_51 :
F_22 ( V_15 , V_48 ) ;
break;
case V_52 :
F_22 ( V_15 , V_48 ) ;
break;
case V_53 :
F_22 ( V_15 , NULL ) ;
} ;
}
static void F_29 ( struct V_5 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_25 * V_26 = V_15 -> V_1 ;
if ( V_15 -> V_18 & V_54 ) {
F_30 ( L_29 , V_15 ) ;
F_13 ( F_31 ( V_26 ) , V_3 -> V_20 . V_55 ) ;
F_11 ( V_15 ) ;
return;
}
F_30 ( L_30 , V_15 ) ;
switch ( V_26 -> V_56 ) {
case V_57 :
F_16 ( V_15 ) ;
break;
case V_58 :
F_32 ( V_15 ) ;
break;
case V_59 :
break;
case V_60 :
F_26 ( & V_3 -> V_16 -> V_17 ,
L_31
L_32 ) ;
F_33 ( L_33 , V_15 ) ;
break;
case V_61 :
F_28 ( V_15 ) ;
F_34 ( V_3 , V_62 , 0 ) ;
break;
case V_63 :
F_35 ( & V_3 -> V_16 -> V_17 ,
L_34 ) ;
F_27 ( V_3 ,
V_64 ) ;
F_3 ( V_3 ,
V_33 |
V_4 ,
L_30 ) ;
F_34 ( V_3 , V_65 , 0 ) ;
break;
case V_66 :
if ( V_26 -> V_50 & V_67 )
F_36 ( V_3 ) ;
if ( V_26 -> V_50 & V_68 )
F_37 ( V_3 -> V_69 , & V_3 -> V_70 ) ;
break;
case V_71 :
F_36 ( V_3 ) ;
break;
case V_72 :
V_3 -> V_73 = V_26 -> V_49 . V_74 [ 0 ] ;
break;
}
F_13 ( F_31 ( V_26 ) , V_3 -> V_20 . V_55 ) ;
F_11 ( V_15 ) ;
F_38 ( & V_3 -> V_75 ) ;
F_37 ( V_3 -> V_69 , & V_3 -> V_76 ) ;
}
static void F_39 ( struct V_5 * V_15 )
{
switch ( V_15 -> V_21 -> V_77 . V_78 . V_74 [ 0 ] ) {
case V_79 :
case V_80 :
case V_81 :
case V_82 :
return;
case V_83 :
break;
case V_84 :
F_9 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_35
L_36 ) ;
F_2 ( V_15 -> V_3 ) ;
F_10 ( V_15 -> V_3 , 0 , L_37 ) ;
break;
}
V_15 -> V_18 |= V_19 ;
}
static void F_40 ( struct V_5 * V_15 )
{
if ( F_41 ( V_15 -> V_18 & V_19 ) )
return;
switch ( V_15 -> V_21 -> V_77 . V_85 ) {
case V_86 :
F_9 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_38 ,
V_15 -> V_21 -> V_77 . V_87 ) ;
F_10 ( V_15 -> V_3 , 0 , L_39 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
F_39 ( V_15 ) ;
break;
}
}
static void F_42 ( struct V_5 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_89 * V_21 = V_15 -> V_21 ;
union V_90 * V_91 = & V_21 -> V_92 . V_93 ;
F_43 ( V_15 ) ;
if ( V_15 -> V_18 & V_54 ) {
V_15 -> V_18 |= V_19 ;
return;
}
switch ( V_21 -> V_92 . V_94 ) {
case V_95 :
case V_96 :
return;
case V_97 :
F_9 ( & V_3 -> V_16 -> V_17 ,
L_40
L_41 , V_98 ,
V_91 -> V_74 [ 0 ] , V_91 -> V_74 [ 1 ] ) ;
F_10 ( V_3 , 0 , L_42 ) ;
break;
case V_99 :
case V_100 :
F_3 ( V_3 , 0 , L_43 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_101 :
F_9 ( & V_3 -> V_16 -> V_17 ,
L_44 ) ;
F_10 ( V_3 , 0 , L_45 ) ;
break;
case V_102 :
F_24 ( V_103 ,
& V_3 -> V_18 ) ;
break;
case V_104 :
F_9 ( & V_3 -> V_16 -> V_17 ,
L_46 ,
( unsigned long long ) V_21 -> V_105 . V_106 . V_107 ) ;
F_10 ( V_3 , 0 , L_47 ) ;
break;
case V_108 :
F_22 ( V_15 , & V_91 -> V_109 ) ;
F_3 ( V_3 , 0 , L_48 ) ;
break;
case V_110 :
F_27 ( V_3 ,
V_64 ) ;
F_3 ( V_3 ,
V_33 |
V_4 ,
L_49 ) ;
break;
default:
F_9 ( & V_3 -> V_16 -> V_17 ,
L_50 ,
V_21 -> V_92 . V_94 ) ;
F_2 ( V_3 ) ;
F_10 ( V_3 , 0 , L_51 ) ;
}
V_15 -> V_18 |= V_19 ;
}
static void F_44 ( struct V_5 * V_15 )
{
if ( F_41 ( V_15 -> V_87 == V_111 ) ) {
F_29 ( V_15 ) ;
return;
}
F_45 ( & V_15 -> V_8 ) ;
F_42 ( V_15 ) ;
F_40 ( V_15 ) ;
V_15 -> V_112 ( V_15 ) ;
if ( V_15 -> V_12 )
F_46 ( V_15 -> V_12 , 0 ) ;
if ( F_12 ( V_15 -> V_18 & V_113 ) )
F_11 ( V_15 ) ;
else
F_47 ( & V_15 -> V_114 ) ;
}
void F_48 ( struct V_2 * V_3 )
{
struct V_5 * V_15 , * V_115 ;
F_49 ( V_116 ) ;
F_7 ( F_23 ( & V_3 -> V_18 ) & V_117 ) ;
F_50 ( V_3 -> V_118 , & V_116 ) ;
F_51 (req, tmp, &remove_queue, list) {
F_52 ( & V_15 -> V_119 ) ;
V_15 -> V_18 |= V_54 ;
F_44 ( V_15 ) ;
}
}
static int F_53 ( struct V_5 * V_15 )
{
struct V_120 * V_105 = & V_15 -> V_21 -> V_105 . V_121 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_122 * V_123 = V_3 -> V_124 ;
struct V_125 * V_126 , * V_127 ;
V_126 = (struct V_125 * ) ( ( V_128 * ) & V_105 -> V_129
- sizeof( V_130 ) ) ;
V_127 = (struct V_125 * ) ( ( V_128 * ) & V_105 -> V_131
- sizeof( V_130 ) ) ;
if ( V_15 -> V_1 )
memcpy ( V_15 -> V_1 , V_105 , sizeof( * V_105 ) ) ;
F_54 ( V_123 ) = V_126 -> V_132 ;
F_55 ( V_123 ) = V_126 -> V_133 ;
F_56 ( V_123 ) = F_17 ( V_105 -> V_134 ) ;
F_57 ( V_123 ) = V_105 -> V_135 ;
F_58 ( V_123 ) = V_136 | V_137 ;
V_3 -> V_138 = V_105 -> V_139 ;
V_3 -> V_140 = V_105 -> V_141 & V_142 ;
V_3 -> V_143 = F_59 ( V_105 -> V_144 ,
( V_145 ) V_146 ) ;
if ( F_60 ( V_123 ) == - 1 )
F_60 ( V_123 ) = F_54 ( V_123 ) ;
switch ( V_105 -> V_147 ) {
case V_148 :
V_3 -> V_149 = F_17 ( V_105 -> V_149 ) ;
V_3 -> V_150 = V_127 -> V_132 ;
V_3 -> V_151 = V_127 -> V_133 ;
F_61 ( V_123 ) = V_152 ;
break;
case V_153 :
F_61 ( V_123 ) = V_154 ;
break;
case V_155 :
F_61 ( V_123 ) = V_156 ;
default:
F_9 ( & V_3 -> V_16 -> V_17 ,
L_52
L_53 ) ;
F_10 ( V_3 , 0 , L_54 ) ;
return - V_157 ;
}
F_62 ( V_3 ) ;
return 0 ;
}
static void F_63 ( struct V_5 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_89 * V_21 = V_15 -> V_21 ;
struct V_120 * V_105 = & V_21 -> V_105 . V_121 ;
struct V_122 * V_123 = V_3 -> V_124 ;
if ( V_15 -> V_18 & V_19 )
return;
V_3 -> V_158 = V_105 -> V_159 ;
V_3 -> V_73 = V_105 -> V_73 ;
V_3 -> V_160 = V_105 -> V_160 ;
V_3 -> V_150 = 0 ;
V_3 -> V_151 = 0 ;
V_3 -> V_149 = 0 ;
switch ( V_21 -> V_77 . V_85 ) {
case V_161 :
if ( F_53 ( V_15 ) )
return;
if ( V_105 -> V_162 < sizeof( struct V_89 ) ) {
F_9 ( & V_3 -> V_16 -> V_17 ,
L_55
L_56 ,
V_105 -> V_162 ) ;
F_10 ( V_3 , 0 , L_57 ) ;
return;
}
F_24 ( V_163 ,
& V_3 -> V_18 ) ;
break;
case V_164 :
F_55 ( V_123 ) = 0 ;
F_54 ( V_123 ) = 0 ;
F_56 ( V_123 ) = 0 ;
F_57 ( V_123 ) = V_165 ;
F_61 ( V_123 ) = V_166 ;
V_3 -> V_138 = 0 ;
F_22 ( V_15 ,
& V_21 -> V_77 . V_78 . V_109 ) ;
break;
default:
F_10 ( V_3 , 0 , L_58 ) ;
return;
}
if ( V_3 -> V_73 & V_167 ) {
V_3 -> V_168 = V_105 -> V_168 ;
memcpy ( F_64 ( V_123 ) , V_105 -> V_169 ,
F_65 ( V_170 , 17 ) ) ;
F_66 ( F_64 ( V_123 ) ,
F_65 ( V_170 , 17 ) ) ;
}
if ( V_98 < V_105 -> V_171 ) {
F_9 ( & V_3 -> V_16 -> V_17 ,
L_59
L_60 ) ;
F_10 ( V_3 , 0 , L_61 ) ;
return;
}
if ( V_98 > V_105 -> V_172 ) {
F_9 ( & V_3 -> V_16 -> V_17 ,
L_62
L_60 ) ;
F_10 ( V_3 , 0 , L_63 ) ;
}
}
static void F_67 ( struct V_5 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_173 * V_105 = & V_15 -> V_21 -> V_105 . V_28 ;
struct V_122 * V_123 = V_3 -> V_124 ;
if ( V_15 -> V_1 )
memcpy ( V_15 -> V_1 , V_105 , sizeof( * V_105 ) ) ;
if ( V_3 -> V_160 & V_174 ) {
F_60 ( V_123 ) = V_105 -> V_175 ;
F_61 ( V_123 ) = V_176 ;
} else
F_60 ( V_123 ) = F_54 ( V_123 ) ;
F_68 ( V_123 ) = V_105 -> V_177 ;
F_69 ( V_123 ) = V_105 -> V_178 ;
memcpy ( F_70 ( V_123 ) , V_105 -> V_179 ,
V_180 ) ;
memcpy ( F_71 ( V_123 ) , V_105 -> V_181 ,
V_180 ) ;
}
static void F_72 ( struct V_5 * V_15 )
{
struct V_89 * V_21 = V_15 -> V_21 ;
if ( V_15 -> V_18 & V_19 )
return;
switch ( V_21 -> V_77 . V_85 ) {
case V_161 :
F_67 ( V_15 ) ;
break;
case V_164 :
F_67 ( V_15 ) ;
F_22 ( V_15 ,
& V_21 -> V_77 . V_78 . V_109 ) ;
break;
}
}
static struct V_5 * F_73 ( T_1 * V_20 )
{
struct V_5 * V_15 ;
if ( F_12 ( V_20 ) )
V_15 = F_74 ( V_20 , V_182 ) ;
else
V_15 = F_75 ( sizeof( * V_15 ) , V_182 ) ;
if ( F_41 ( ! V_15 ) )
return NULL ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_20 = V_20 ;
return V_15 ;
}
static struct V_89 * F_76 ( T_1 * V_20 )
{
struct V_89 * V_21 ;
if ( F_12 ( V_20 ) )
V_21 = F_74 ( V_20 , V_182 ) ;
else
V_21 = F_77 ( V_23 , V_182 ) ;
if ( F_41 ( ! V_21 ) )
return NULL ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
return V_21 ;
}
static struct V_5 * F_78 ( struct V_183 * V_184 ,
V_130 V_185 , V_128 V_186 ,
T_1 * V_20 )
{
struct V_2 * V_3 = V_184 -> V_3 ;
struct V_5 * V_15 = F_73 ( V_20 ) ;
if ( F_41 ( ! V_15 ) )
return F_79 ( - V_187 ) ;
if ( V_3 -> V_188 == 0 )
V_3 -> V_188 ++ ;
F_80 ( & V_15 -> V_119 ) ;
F_81 ( & V_15 -> V_8 ) ;
F_82 ( & V_15 -> V_114 ) ;
V_15 -> V_3 = V_3 ;
V_15 -> V_87 = V_185 ;
V_15 -> V_189 = V_3 -> V_188 ;
if ( F_12 ( V_185 != V_111 ) ) {
if ( F_12 ( V_20 ) )
V_15 -> V_21 = F_76 ( V_3 -> V_20 . V_22 ) ;
else
V_15 -> V_21 = F_76 ( NULL ) ;
if ( F_41 ( ! V_15 -> V_21 ) ) {
F_11 ( V_15 ) ;
return F_79 ( - V_187 ) ;
}
V_15 -> V_190 = V_3 -> V_191 ;
V_15 -> V_21 -> V_92 . V_192 = V_3 -> V_191 ;
V_15 -> V_21 -> V_92 . V_189 = V_15 -> V_189 ;
V_15 -> V_21 -> V_92 . V_193 = 26 ;
V_15 -> V_21 -> V_92 . V_194 = V_195 [ V_15 -> V_87 ] ;
V_15 -> V_21 -> V_92 . V_196 = V_98 ;
V_15 -> V_21 -> V_77 . V_107 = V_15 -> V_189 ;
V_15 -> V_21 -> V_77 . V_87 = V_15 -> V_87 ;
}
F_83 ( V_3 -> V_184 , & V_15 -> V_197 , V_15 -> V_189 , V_186 ,
V_15 -> V_21 , sizeof( struct V_89 ) ) ;
return V_15 ;
}
static int F_84 ( struct V_5 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_183 * V_184 = V_3 -> V_184 ;
int V_198 = ( V_15 -> V_21 != NULL ) ;
int V_189 = V_15 -> V_189 ;
F_85 ( V_3 -> V_118 , V_15 ) ;
V_15 -> V_197 . V_199 = F_23 ( & V_184 -> V_200 ) ;
V_15 -> V_201 = F_86 () ;
if ( F_87 ( V_184 , & V_15 -> V_197 ) ) {
F_45 ( & V_15 -> V_8 ) ;
F_88 ( V_3 -> V_118 , V_189 ) ;
F_3 ( V_3 , 0 , L_64 ) ;
return - V_157 ;
}
if ( V_198 )
V_3 -> V_191 ++ ;
V_3 -> V_188 ++ ;
return 0 ;
}
int F_89 ( struct V_183 * V_184 )
{
struct V_2 * V_3 = V_184 -> V_3 ;
struct V_5 * V_15 ;
struct V_25 * V_26 ;
struct V_202 * V_202 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_111 , 0 ,
V_3 -> V_20 . V_205 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_202 = F_74 ( V_3 -> V_20 . V_55 , V_182 ) ;
if ( ! V_202 ) {
V_203 = - V_187 ;
goto V_206;
}
V_26 = F_94 ( V_202 ) ;
memset ( V_26 , 0 , sizeof( * V_26 ) ) ;
V_15 -> V_1 = V_26 ;
F_95 ( V_184 , & V_15 -> V_197 , V_26 , sizeof( * V_26 ) ) ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 )
goto V_207;
goto V_34;
V_207:
V_15 -> V_1 = NULL ;
F_13 ( F_31 ( V_26 ) , V_3 -> V_20 . V_55 ) ;
V_206:
F_30 ( L_65 , V_15 ) ;
F_11 ( V_15 ) ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_98 ( struct V_5 * V_15 )
{
struct V_208 * V_209 = V_15 -> V_1 ;
struct V_210 * V_211 = F_99 ( V_209 ) ;
union V_78 * V_212 = & V_15 -> V_21 -> V_77 . V_78 ;
if ( V_15 -> V_18 & V_19 )
return;
switch ( V_15 -> V_21 -> V_77 . V_85 ) {
case V_213 :
if ( V_212 -> V_74 [ 0 ] == V_212 -> V_74 [ 1 ] ) {
F_3 ( V_211 -> V_28 -> V_3 , 0 ,
L_66 ) ;
V_15 -> V_18 |= V_19 ;
}
break;
case V_214 :
if ( V_212 -> V_74 [ 0 ] == V_212 -> V_74 [ 1 ] ) {
F_20 ( V_211 -> V_28 , 0 , L_67 ) ;
V_15 -> V_18 |= V_19 ;
}
break;
case V_215 :
V_15 -> V_18 |= V_216 ;
break;
case V_217 :
F_100 ( V_211 -> V_28 ,
V_218 ) ;
F_20 ( V_211 -> V_28 ,
V_4 , L_68 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_219 :
F_101 ( V_209 , V_218 ) ;
F_102 ( V_209 , V_4 ,
L_69 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
switch ( V_212 -> V_74 [ 0 ] ) {
case V_80 :
F_103 ( V_211 -> V_28 ) ;
case V_82 :
V_15 -> V_18 |= V_19 ;
break;
}
break;
case V_161 :
V_15 -> V_18 |= V_220 ;
break;
}
}
struct V_5 * F_104 ( struct V_221 * V_222 )
{
struct V_5 * V_15 = NULL ;
struct V_208 * V_209 = V_222 -> V_223 ;
struct V_210 * V_211 = F_99 ( V_209 ) ;
struct V_183 * V_184 = V_211 -> V_28 -> V_3 -> V_184 ;
unsigned long V_224 = ( unsigned long ) V_222 -> V_225 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_226 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_228 ) ;
if ( F_92 ( V_15 ) ) {
V_15 = NULL ;
goto V_34;
}
if ( F_41 ( ! ( F_23 ( & V_211 -> V_18 ) &
V_229 ) ) )
goto V_230;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_1 = V_209 ;
V_15 -> V_112 = F_98 ;
V_15 -> V_21 -> V_77 . V_231 = V_211 -> V_231 ;
V_15 -> V_21 -> V_77 . V_232 = V_211 -> V_28 -> V_233 ;
V_15 -> V_21 -> V_105 . V_106 . V_107 = ( V_234 ) V_224 ;
F_4 ( V_15 , V_235 ) ;
if ( ! F_84 ( V_15 ) )
goto V_34;
V_230:
F_11 ( V_15 ) ;
V_15 = NULL ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_15 ;
}
static void F_105 ( struct V_5 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_236 * V_237 = V_15 -> V_1 ;
struct V_238 * V_77 = & V_15 -> V_21 -> V_77 ;
V_237 -> V_18 = - V_239 ;
if ( V_15 -> V_18 & V_19 )
goto V_240;
switch ( V_77 -> V_85 ) {
case V_161 :
F_106 ( L_70 , V_15 ) ;
V_237 -> V_18 = 0 ;
break;
case V_241 :
F_8 ( V_15 ) ;
break;
case V_88 :
switch ( V_77 -> V_78 . V_74 [ 0 ] ) {
case V_80 :
case V_82 :
V_15 -> V_18 |= V_19 ;
break;
}
break;
case V_242 :
break;
case V_217 :
V_15 -> V_18 |= V_19 ;
break;
case V_213 :
F_3 ( V_3 , 0 , L_70 ) ;
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
V_15 -> V_18 |= V_19 ;
break;
}
V_240:
if ( V_237 -> V_112 )
V_237 -> V_112 ( V_237 -> V_248 ) ;
}
static void F_107 ( struct V_183 * V_184 ,
struct V_249 * V_250 ,
struct V_251 * V_252 ,
struct V_251 * V_253 )
{
F_95 ( V_184 , V_250 , F_108 ( V_252 ) , V_252 -> V_254 ) ;
F_95 ( V_184 , V_250 , F_108 ( V_253 ) , V_253 -> V_254 ) ;
F_96 ( V_184 , V_250 ) ;
}
static int F_109 ( struct V_5 * V_15 ,
struct V_251 * V_252 ,
struct V_251 * V_253 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
V_130 V_255 = V_3 -> V_73 ;
int V_256 ;
if ( ! ( V_255 & V_257 ) ) {
if ( ! F_110 ( V_252 ) ||
! F_110 ( V_253 ) )
return - V_258 ;
F_107 ( V_3 -> V_184 , & V_15 -> V_197 ,
V_252 , V_253 ) ;
return 0 ;
}
if ( F_110 ( V_252 ) && F_110 ( V_253 ) ) {
F_107 ( V_3 -> V_184 , & V_15 -> V_197 ,
V_252 , V_253 ) ;
return 0 ;
}
V_256 = F_111 ( V_3 -> V_184 , & V_15 -> V_197 , V_252 ) ;
if ( V_256 <= 0 )
return - V_157 ;
F_96 ( V_3 -> V_184 , & V_15 -> V_197 ) ;
V_15 -> V_21 -> V_105 . V_106 . V_259 = V_256 ;
F_112 ( & V_15 -> V_197 ) ;
V_256 = F_111 ( V_3 -> V_184 , & V_15 -> V_197 ,
V_253 ) ;
V_15 -> V_21 -> V_105 . V_106 . V_260 = V_256 ;
if ( V_256 <= 0 )
return - V_157 ;
F_96 ( V_3 -> V_184 , & V_15 -> V_197 ) ;
return 0 ;
}
static int F_113 ( struct V_5 * V_15 ,
struct V_251 * V_252 ,
struct V_251 * V_253 ,
unsigned int V_7 )
{
int V_261 ;
V_261 = F_109 ( V_15 , V_252 , V_253 ) ;
if ( V_261 )
return V_261 ;
if ( V_7 > 255 )
V_7 = 255 ;
V_15 -> V_21 -> V_105 . V_106 . V_262 = V_263 ;
V_15 -> V_21 -> V_105 . V_106 . V_7 = V_7 ;
F_4 ( V_15 , ( V_7 + 10 ) * V_14 ) ;
return 0 ;
}
int F_114 ( struct V_264 * V_265 ,
struct V_236 * V_237 , T_1 * V_20 ,
unsigned int V_7 )
{
struct V_183 * V_184 = V_265 -> V_3 -> V_184 ;
struct V_5 * V_15 ;
int V_261 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_266 ,
V_267 , V_20 ) ;
if ( F_92 ( V_15 ) ) {
V_261 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
V_261 = F_113 ( V_15 , V_237 -> V_15 , V_237 -> V_268 , V_7 ) ;
if ( V_261 )
goto V_269;
V_15 -> V_112 = F_105 ;
V_15 -> V_21 -> V_77 . V_232 = V_265 -> V_233 ;
V_15 -> V_1 = V_237 ;
F_115 ( L_71 , V_15 , V_265 -> V_29 ) ;
V_261 = F_84 ( V_15 ) ;
if ( V_261 )
goto V_269;
goto V_34;
V_269:
F_11 ( V_15 ) ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_261 ;
}
static void F_116 ( struct V_5 * V_15 )
{
struct V_236 * V_270 = V_15 -> V_1 ;
struct V_27 * V_28 = V_270 -> V_28 ;
struct V_238 * V_77 = & V_15 -> V_21 -> V_77 ;
V_270 -> V_18 = - V_239 ;
if ( V_15 -> V_18 & V_19 )
goto V_240;
switch ( V_77 -> V_85 ) {
case V_161 :
F_106 ( L_72 , V_15 ) ;
V_270 -> V_18 = 0 ;
break;
case V_241 :
F_8 ( V_15 ) ;
break;
case V_88 :
switch ( V_77 -> V_78 . V_74 [ 0 ] ) {
case V_80 :
case V_82 :
case V_271 :
V_15 -> V_18 |= V_19 ;
break;
}
break;
case V_272 :
case V_244 :
case V_245 :
case V_246 :
break;
case V_242 :
if ( V_28 ) {
F_117 ( V_28 , & V_77 -> V_78 ) ;
V_15 -> V_18 |= V_19 ;
}
break;
case V_247 :
default:
V_15 -> V_18 |= V_19 ;
break;
}
V_240:
if ( V_270 -> V_112 )
V_270 -> V_112 ( V_270 -> V_248 ) ;
}
int F_118 ( struct V_2 * V_3 , V_130 V_29 ,
struct V_236 * V_273 , unsigned int V_7 )
{
struct V_5 * V_15 ;
struct V_183 * V_184 = V_3 -> V_184 ;
int V_261 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_274 ,
V_267 , NULL ) ;
if ( F_92 ( V_15 ) ) {
V_261 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_119 ( V_184 , & V_15 -> V_197 , 2 ) ;
V_261 = F_113 ( V_15 , V_273 -> V_15 , V_273 -> V_268 , V_7 ) ;
if ( V_261 )
goto V_269;
F_120 ( V_15 -> V_21 -> V_105 . V_106 . V_29 , V_29 ) ;
V_15 -> V_112 = F_116 ;
V_15 -> V_1 = V_273 ;
F_115 ( L_73 , V_15 , V_29 ) ;
V_261 = F_84 ( V_15 ) ;
if ( V_261 )
goto V_269;
goto V_34;
V_269:
F_11 ( V_15 ) ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_261 ;
}
int F_121 ( struct V_275 * V_12 )
{
struct V_5 * V_15 ;
struct V_183 * V_184 = V_12 -> V_3 -> V_184 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_276 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_21 -> V_105 . V_121 . V_278 =
V_279 |
V_280 |
V_281 |
V_282 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_112 = F_63 ;
V_12 -> V_283 = V_15 -> V_189 ;
F_6 ( V_15 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 ) {
F_11 ( V_15 ) ;
V_12 -> V_283 = 0 ;
}
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
int F_122 ( struct V_183 * V_184 ,
struct V_120 * V_1 )
{
struct V_5 * V_15 = NULL ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_284;
V_15 = F_78 ( V_184 , V_276 ,
V_227 , NULL ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_284;
}
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_112 = F_63 ;
V_15 -> V_21 -> V_105 . V_121 . V_278 =
V_279 |
V_280 |
V_281 |
V_282 ;
if ( V_1 )
V_15 -> V_1 = V_1 ;
F_4 ( V_15 , V_285 ) ;
V_203 = F_84 ( V_15 ) ;
F_97 ( & V_184 -> V_204 ) ;
if ( ! V_203 )
F_123 ( & V_15 -> V_114 ) ;
F_11 ( V_15 ) ;
return V_203 ;
V_284:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
int F_124 ( struct V_275 * V_12 )
{
struct V_183 * V_184 = V_12 -> V_3 -> V_184 ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
if ( ! ( V_184 -> V_3 -> V_73 & V_167 ) )
return - V_258 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_286 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_112 = F_72 ;
V_15 -> V_12 = V_12 ;
V_12 -> V_283 = V_15 -> V_189 ;
F_6 ( V_15 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 ) {
F_11 ( V_15 ) ;
V_12 -> V_283 = 0 ;
}
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
int F_125 ( struct V_183 * V_184 ,
struct V_173 * V_1 )
{
struct V_5 * V_15 = NULL ;
int V_203 = - V_157 ;
if ( ! ( V_184 -> V_3 -> V_73 & V_167 ) )
return - V_258 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_284;
V_15 = F_78 ( V_184 , V_286 ,
V_227 , NULL ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_284;
}
if ( V_1 )
V_15 -> V_1 = V_1 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_112 = F_72 ;
F_4 ( V_15 , V_285 ) ;
V_203 = F_84 ( V_15 ) ;
F_97 ( & V_184 -> V_204 ) ;
if ( ! V_203 )
F_123 ( & V_15 -> V_114 ) ;
F_11 ( V_15 ) ;
return V_203 ;
V_284:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_126 ( struct V_5 * V_15 )
{
struct V_27 * V_28 = V_15 -> V_1 ;
struct V_238 * V_77 = & V_15 -> V_21 -> V_77 ;
struct V_125 * V_127 ;
if ( V_15 -> V_18 & V_19 )
goto V_34;
switch ( V_77 -> V_85 ) {
case V_287 :
break;
case V_242 :
F_117 ( V_28 , & V_77 -> V_78 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_288 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_74
L_75 ,
( unsigned long long ) V_28 -> V_175 ) ;
F_100 ( V_28 ,
V_4 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
switch ( V_77 -> V_78 . V_74 [ 0 ] ) {
case V_80 :
case V_82 :
case V_81 :
V_15 -> V_18 |= V_19 ;
break;
}
break;
case V_161 :
V_28 -> V_233 = V_77 -> V_232 ;
F_24 ( V_289 |
V_290 , & V_28 -> V_18 ) ;
F_127 ( V_291 |
V_218 ,
& V_28 -> V_18 ) ;
V_127 = (struct V_125 * ) V_15 -> V_21 -> V_105 . V_106 . V_273 ;
if ( V_15 -> V_21 -> V_105 . V_106 . V_292 >=
V_293 )
F_128 ( V_28 , V_127 ) ;
break;
case V_294 :
V_15 -> V_18 |= V_19 ;
break;
}
V_34:
F_129 ( & V_28 -> V_17 ) ;
}
int F_130 ( struct V_275 * V_12 )
{
struct V_183 * V_184 = V_12 -> V_3 -> V_184 ;
struct V_27 * V_28 = V_12 -> V_28 ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_295 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_112 = F_126 ;
F_120 ( V_15 -> V_21 -> V_105 . V_106 . V_29 , V_28 -> V_29 ) ;
V_15 -> V_1 = V_28 ;
V_15 -> V_12 = V_12 ;
V_12 -> V_283 = V_15 -> V_189 ;
F_131 ( & V_28 -> V_17 ) ;
F_6 ( V_15 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 ) {
F_11 ( V_15 ) ;
V_12 -> V_283 = 0 ;
F_129 ( & V_28 -> V_17 ) ;
}
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_132 ( struct V_5 * V_15 )
{
struct V_27 * V_28 = V_15 -> V_1 ;
if ( V_15 -> V_18 & V_19 )
return;
switch ( V_15 -> V_21 -> V_77 . V_85 ) {
case V_213 :
F_3 ( V_28 -> V_3 , 0 , L_76 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
break;
case V_161 :
F_133 ( V_28 , V_289 ) ;
break;
}
}
int F_134 ( struct V_275 * V_12 )
{
struct V_183 * V_184 = V_12 -> V_3 -> V_184 ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_296 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_112 = F_132 ;
V_15 -> V_1 = V_12 -> V_28 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_21 -> V_77 . V_232 = V_12 -> V_28 -> V_233 ;
V_12 -> V_283 = V_15 -> V_189 ;
F_6 ( V_15 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 ) {
F_11 ( V_15 ) ;
V_12 -> V_283 = 0 ;
}
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_135 ( struct V_5 * V_15 )
{
struct V_264 * V_265 = V_15 -> V_1 ;
struct V_238 * V_77 = & V_15 -> V_21 -> V_77 ;
if ( V_15 -> V_18 & V_19 ) {
V_265 -> V_18 = V_297 ;
goto V_34;
}
switch ( V_77 -> V_85 ) {
case V_288 :
F_26 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_77 , V_265 -> V_29 ) ;
case V_88 :
V_15 -> V_18 |= V_19 ;
case V_242 :
V_265 -> V_18 = V_297 ;
break;
case V_161 :
V_265 -> V_233 = V_77 -> V_232 ;
case V_287 :
V_265 -> V_18 = V_298 ;
}
V_34:
F_136 ( & V_265 -> V_299 ) ;
}
int F_137 ( struct V_264 * V_265 )
{
struct V_183 * V_184 = V_265 -> V_3 -> V_184 ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_295 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_112 = F_135 ;
F_120 ( V_15 -> V_21 -> V_105 . V_106 . V_29 , V_265 -> V_29 ) ;
V_15 -> V_1 = V_265 ;
F_4 ( V_15 , V_285 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 )
F_11 ( V_15 ) ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_138 ( struct V_5 * V_15 )
{
struct V_264 * V_265 = V_15 -> V_1 ;
if ( V_15 -> V_21 -> V_77 . V_85 == V_213 ) {
V_15 -> V_18 |= V_19 ;
F_3 ( V_265 -> V_3 , 0 , L_78 ) ;
}
V_265 -> V_18 = V_297 ;
F_136 ( & V_265 -> V_299 ) ;
}
int F_139 ( struct V_264 * V_265 )
{
struct V_183 * V_184 = V_265 -> V_3 -> V_184 ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_296 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_112 = F_138 ;
V_15 -> V_1 = V_265 ;
V_15 -> V_21 -> V_77 . V_232 = V_265 -> V_233 ;
F_4 ( V_15 , V_285 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 )
F_11 ( V_15 ) ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_140 ( struct V_5 * V_15 )
{
struct V_27 * V_28 = V_15 -> V_1 ;
struct V_238 * V_77 = & V_15 -> V_21 -> V_77 ;
struct V_208 * V_209 ;
if ( V_15 -> V_18 & V_19 )
return;
switch ( V_77 -> V_85 ) {
case V_213 :
F_3 ( V_28 -> V_3 , 0 , L_79 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_242 :
F_117 ( V_28 , & V_77 -> V_78 ) ;
break;
case V_217 :
F_127 ( V_290 , & V_28 -> V_18 ) ;
F_141 (sdev, port->adapter->scsi_host)
if ( F_99 ( V_209 ) -> V_28 == V_28 )
F_127 ( V_289 ,
& F_99 ( V_209 ) -> V_18 ) ;
F_100 ( V_28 , V_218 ) ;
F_20 ( V_28 , V_4 ,
L_80 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
switch ( V_77 -> V_78 . V_74 [ 0 ] ) {
case V_80 :
case V_82 :
V_15 -> V_18 |= V_19 ;
break;
}
break;
case V_161 :
F_127 ( V_290 , & V_28 -> V_18 ) ;
F_141 (sdev, port->adapter->scsi_host)
if ( F_99 ( V_209 ) -> V_28 == V_28 )
F_127 ( V_289 ,
& F_99 ( V_209 ) -> V_18 ) ;
break;
}
}
int F_142 ( struct V_275 * V_12 )
{
struct V_183 * V_184 = V_12 -> V_3 -> V_184 ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_300 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_1 = V_12 -> V_28 ;
V_15 -> V_21 -> V_77 . V_232 = V_12 -> V_28 -> V_233 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_112 = F_140 ;
V_12 -> V_283 = V_15 -> V_189 ;
F_6 ( V_15 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 ) {
F_11 ( V_15 ) ;
V_12 -> V_283 = 0 ;
}
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_143 ( struct V_5 * V_15 )
{
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_208 * V_209 = V_15 -> V_1 ;
struct V_210 * V_211 = F_99 ( V_209 ) ;
struct V_238 * V_77 = & V_15 -> V_21 -> V_77 ;
struct V_301 * V_105 = & V_15 -> V_21 -> V_105 . V_106 ;
if ( V_15 -> V_18 & V_19 )
return;
F_127 ( V_291 |
V_218 |
V_302 |
V_303 ,
& V_211 -> V_18 ) ;
switch ( V_77 -> V_85 ) {
case V_213 :
F_3 ( V_3 , 0 , L_81 ) ;
case V_304 :
break;
case V_242 :
F_144 ( V_209 , & V_77 -> V_78 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_217 :
F_100 ( V_211 -> V_28 ,
V_218 ) ;
F_20 ( V_211 -> V_28 ,
V_4 , L_82 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_305 :
F_145 ( V_209 , & V_77 -> V_78 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_306 :
F_26 ( & V_3 -> V_16 -> V_17 ,
L_83
L_84 ,
( unsigned long long ) F_146 ( V_209 ) ,
( unsigned long long ) V_211 -> V_28 -> V_175 ) ;
F_101 ( V_209 , V_4 ) ;
case V_307 :
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
switch ( V_77 -> V_78 . V_74 [ 0 ] ) {
case V_80 :
F_103 ( V_211 -> V_28 ) ;
case V_82 :
V_15 -> V_18 |= V_19 ;
break;
}
break;
case V_161 :
V_211 -> V_231 = V_77 -> V_231 ;
F_24 ( V_289 , & V_211 -> V_18 ) ;
F_147 ( V_209 , V_105 ) ;
break;
}
}
int F_148 ( struct V_275 * V_12 )
{
struct V_2 * V_3 = V_12 -> V_3 ;
struct V_183 * V_184 = V_3 -> V_184 ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_308 ,
V_227 ,
V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_21 -> V_77 . V_232 = V_12 -> V_28 -> V_233 ;
V_15 -> V_21 -> V_105 . V_106 . V_309 = F_146 ( V_12 -> V_209 ) ;
V_15 -> V_112 = F_143 ;
V_15 -> V_1 = V_12 -> V_209 ;
V_15 -> V_12 = V_12 ;
V_12 -> V_283 = V_15 -> V_189 ;
if ( ! ( V_3 -> V_160 & V_174 ) )
V_15 -> V_21 -> V_105 . V_106 . V_310 = V_311 ;
F_6 ( V_15 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 ) {
F_11 ( V_15 ) ;
V_12 -> V_283 = 0 ;
}
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_149 ( struct V_5 * V_15 )
{
struct V_208 * V_209 = V_15 -> V_1 ;
struct V_210 * V_211 = F_99 ( V_209 ) ;
if ( V_15 -> V_18 & V_19 )
return;
switch ( V_15 -> V_21 -> V_77 . V_85 ) {
case V_213 :
F_3 ( V_211 -> V_28 -> V_3 , 0 , L_85 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_214 :
F_20 ( V_211 -> V_28 , 0 , L_86 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_217 :
F_100 ( V_211 -> V_28 ,
V_218 ) ;
F_20 ( V_211 -> V_28 ,
V_4 , L_87 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
switch ( V_15 -> V_21 -> V_77 . V_78 . V_74 [ 0 ] ) {
case V_80 :
F_103 ( V_211 -> V_28 ) ;
case V_82 :
V_15 -> V_18 |= V_19 ;
break;
}
break;
case V_161 :
F_127 ( V_289 , & V_211 -> V_18 ) ;
break;
}
}
int F_150 ( struct V_275 * V_12 )
{
struct V_183 * V_184 = V_12 -> V_3 -> V_184 ;
struct V_210 * V_211 = F_99 ( V_12 -> V_209 ) ;
struct V_5 * V_15 ;
int V_203 = - V_157 ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_312 ,
V_227 ,
V_184 -> V_3 -> V_20 . V_277 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_15 -> V_18 |= V_113 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_15 -> V_21 -> V_77 . V_232 = V_12 -> V_28 -> V_233 ;
V_15 -> V_21 -> V_77 . V_231 = V_211 -> V_231 ;
V_15 -> V_112 = F_149 ;
V_15 -> V_1 = V_12 -> V_209 ;
V_15 -> V_12 = V_12 ;
V_12 -> V_283 = V_15 -> V_189 ;
F_6 ( V_15 ) ;
V_203 = F_84 ( V_15 ) ;
if ( V_203 ) {
F_11 ( V_15 ) ;
V_12 -> V_283 = 0 ;
}
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_203 ;
}
static void F_151 ( struct V_313 * V_314 , V_130 V_315 )
{
V_314 -> V_316 += V_315 ;
V_314 -> F_65 = F_65 ( V_314 -> F_65 , V_315 ) ;
V_314 -> F_59 = F_59 ( V_314 -> F_59 , V_315 ) ;
}
static void F_152 ( struct V_5 * V_15 , struct V_221 * V_317 )
{
struct V_318 * V_319 ;
struct V_320 * V_315 = NULL ;
struct V_210 * V_211 = F_99 ( V_317 -> V_223 ) ;
struct V_321 V_322 ;
int V_323 = V_15 -> V_3 -> V_140 ;
V_319 = & V_15 -> V_21 -> V_92 . V_93 . V_324 ;
V_322 . V_24 = 0 ;
V_322 . V_325 = V_326 ;
if ( V_15 -> V_18 & V_19 )
V_322 . V_24 |= V_327 ;
V_322 . V_328 = 0 ;
V_322 . V_329 = V_15 -> V_197 . V_199 ;
if ( V_15 -> V_3 -> V_73 & V_330 &&
! ( V_15 -> V_18 & V_19 ) ) {
V_322 . V_24 |= V_331 ;
V_322 . V_332 = V_319 -> V_332 * V_323 ;
V_322 . V_333 = V_319 -> V_333 * V_323 ;
switch ( V_15 -> V_21 -> V_105 . V_334 . V_335 ) {
case V_336 :
case V_337 :
case V_338 :
V_315 = & V_211 -> V_339 . V_340 ;
break;
case V_341 :
case V_342 :
case V_343 :
V_315 = & V_211 -> V_339 . V_344 ;
break;
case V_345 :
V_315 = & V_211 -> V_339 . V_346 ;
break;
}
if ( V_315 ) {
F_153 ( & V_211 -> V_339 . V_347 ) ;
F_151 ( & V_315 -> V_348 , V_319 -> V_332 ) ;
F_151 ( & V_315 -> V_349 , V_319 -> V_333 ) ;
V_315 -> V_350 ++ ;
F_154 ( & V_211 -> V_339 . V_347 ) ;
}
}
F_155 ( V_317 -> V_351 -> V_352 , V_317 -> V_351 , & V_322 ,
sizeof( V_322 ) ) ;
}
static void F_156 ( struct V_5 * V_15 )
{
struct V_221 * V_222 = V_15 -> V_1 ;
struct V_208 * V_209 = V_222 -> V_223 ;
struct V_210 * V_211 = F_99 ( V_209 ) ;
struct V_238 * V_77 = & V_15 -> V_21 -> V_77 ;
if ( F_41 ( V_15 -> V_18 & V_19 ) )
return;
switch ( V_77 -> V_85 ) {
case V_353 :
case V_213 :
F_3 ( V_211 -> V_28 -> V_3 , 0 , L_88 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_354 :
case V_214 :
F_20 ( V_211 -> V_28 , 0 , L_89 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_241 :
F_8 ( V_15 ) ;
break;
case V_242 :
F_144 ( V_209 , & V_77 -> V_78 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_355 :
F_9 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_90
L_91 ,
V_15 -> V_21 -> V_105 . V_334 . V_335 ,
( unsigned long long ) F_146 ( V_209 ) ,
( unsigned long long ) V_211 -> V_28 -> V_175 ) ;
F_10 ( V_211 -> V_28 -> V_3 , 0 ,
L_92 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_356 :
F_9 ( & V_15 -> V_3 -> V_16 -> V_17 ,
L_93
L_94 ,
V_15 -> V_21 -> V_105 . V_334 . V_357 ,
( unsigned long long ) F_146 ( V_209 ) ,
( unsigned long long ) V_211 -> V_28 -> V_175 ) ;
F_10 ( V_211 -> V_28 -> V_3 , 0 ,
L_95 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_217 :
F_100 ( V_211 -> V_28 ,
V_218 ) ;
F_20 ( V_211 -> V_28 ,
V_4 , L_96 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_219 :
F_101 ( V_209 , V_218 ) ;
F_102 ( V_209 , V_4 ,
L_97 ) ;
V_15 -> V_18 |= V_19 ;
break;
case V_88 :
if ( V_77 -> V_78 . V_74 [ 0 ] ==
V_80 )
F_103 ( V_211 -> V_28 ) ;
V_15 -> V_18 |= V_19 ;
break;
}
}
static void F_157 ( struct V_5 * V_15 )
{
struct V_221 * V_358 ;
struct V_359 * V_360 ;
unsigned long V_24 ;
F_18 ( & V_15 -> V_3 -> V_361 , V_24 ) ;
V_358 = V_15 -> V_1 ;
if ( F_41 ( ! V_358 ) ) {
F_21 ( & V_15 -> V_3 -> V_361 , V_24 ) ;
return;
}
F_156 ( V_15 ) ;
if ( F_41 ( V_15 -> V_18 & V_19 ) ) {
F_158 ( V_358 , V_362 ) ;
goto V_240;
}
switch ( V_15 -> V_21 -> V_77 . V_85 ) {
case V_363 :
case V_364 :
F_158 ( V_358 , V_365 ) ;
goto V_240;
case V_366 :
F_159 ( V_358 , 0x1 ) ;
goto V_240;
case V_367 :
F_159 ( V_358 , 0x2 ) ;
goto V_240;
case V_368 :
F_159 ( V_358 , 0x3 ) ;
goto V_240;
}
V_360 = (struct V_359 * ) & V_15 -> V_21 -> V_105 . V_334 . V_360 ;
F_160 ( V_360 , V_358 ) ;
V_240:
F_152 ( V_15 , V_358 ) ;
F_161 ( V_358 , V_15 ) ;
V_358 -> V_225 = NULL ;
( V_358 -> V_369 ) ( V_358 ) ;
F_21 ( & V_15 -> V_3 -> V_361 , V_24 ) ;
}
static int F_162 ( struct V_221 * V_221 , V_130 * V_370 )
{
switch ( F_163 ( V_221 ) ) {
case V_371 :
switch ( V_221 -> V_372 ) {
case V_373 :
* V_370 = V_345 ;
break;
case V_374 :
* V_370 = V_338 ;
break;
case V_375 :
* V_370 = V_343 ;
break;
case V_376 :
return - V_239 ;
}
break;
case V_377 :
* V_370 = V_336 ;
break;
case V_378 :
* V_370 = V_341 ;
break;
case V_379 :
* V_370 = V_337 ;
break;
case V_380 :
* V_370 = V_342 ;
break;
default:
return - V_239 ;
}
return 0 ;
}
int F_164 ( struct V_221 * V_221 )
{
struct V_5 * V_15 ;
struct V_381 * V_381 ;
V_128 V_186 = V_227 ;
int V_382 , V_203 = - V_157 , V_383 = 0 ;
struct V_208 * V_209 = V_221 -> V_223 ;
struct V_210 * V_211 = F_99 ( V_209 ) ;
struct V_2 * V_3 = V_211 -> V_28 -> V_3 ;
struct V_183 * V_184 = V_3 -> V_184 ;
struct V_384 * V_334 ;
unsigned long V_24 ;
if ( F_41 ( ! ( F_23 ( & V_211 -> V_18 ) &
V_229 ) ) )
return - V_385 ;
F_165 ( & V_184 -> V_204 , V_24 ) ;
if ( F_23 ( & V_184 -> V_200 ) <= 0 ) {
F_38 ( & V_184 -> V_386 ) ;
goto V_34;
}
if ( V_221 -> V_372 == V_375 )
V_186 = V_387 ;
V_15 = F_78 ( V_184 , V_388 ,
V_186 , V_3 -> V_20 . V_389 ) ;
if ( F_92 ( V_15 ) ) {
V_203 = F_93 ( V_15 ) ;
goto V_34;
}
V_221 -> V_225 = ( unsigned char * ) V_15 -> V_189 ;
V_334 = & V_15 -> V_21 -> V_105 . V_334 ;
V_15 -> V_18 |= V_113 ;
V_15 -> V_1 = V_221 ;
V_15 -> V_112 = F_157 ;
V_15 -> V_21 -> V_77 . V_231 = V_211 -> V_231 ;
V_15 -> V_21 -> V_77 . V_232 = V_211 -> V_28 -> V_233 ;
V_334 -> V_262 = V_263 ;
V_334 -> V_357 = V_390 ;
if ( F_163 ( V_221 ) != V_371 ) {
V_334 -> V_391 = V_221 -> V_223 -> V_392 ;
V_334 -> V_393 = F_166 ( V_221 ) & 0xFFFFFFFF ;
}
F_162 ( V_221 , & V_334 -> V_335 ) ;
V_381 = (struct V_381 * ) & V_15 -> V_21 -> V_105 . V_334 . V_381 ;
F_167 ( V_381 , V_221 , 0 ) ;
if ( F_168 ( V_221 ) ) {
F_169 ( V_184 , & V_15 -> V_197 ,
F_168 ( V_221 ) ) ;
V_383 = F_111 ( V_184 , & V_15 -> V_197 ,
F_170 ( V_221 ) ) ;
V_334 -> V_394 = V_383 ;
}
V_382 = F_111 ( V_184 , & V_15 -> V_197 ,
F_171 ( V_221 ) ) ;
if ( F_41 ( V_382 < 0 ) || F_41 ( V_383 < 0 ) )
goto V_395;
F_96 ( V_3 -> V_184 , & V_15 -> V_197 ) ;
V_203 = F_84 ( V_15 ) ;
if ( F_41 ( V_203 ) )
goto V_395;
goto V_34;
V_395:
F_11 ( V_15 ) ;
V_221 -> V_225 = NULL ;
V_34:
F_172 ( & V_184 -> V_204 , V_24 ) ;
return V_203 ;
}
static void F_173 ( struct V_5 * V_15 )
{
struct V_359 * V_360 ;
struct V_396 * V_397 ;
F_156 ( V_15 ) ;
V_360 = (struct V_359 * ) & V_15 -> V_21 -> V_105 . V_334 . V_360 ;
V_397 = (struct V_396 * ) & V_360 [ 1 ] ;
if ( ( V_397 -> V_398 != V_399 ) ||
( V_15 -> V_18 & V_19 ) )
V_15 -> V_18 |= V_400 ;
}
struct V_5 * F_174 ( struct V_221 * V_222 ,
V_128 V_401 )
{
struct V_5 * V_15 = NULL ;
struct V_381 * V_381 ;
struct V_210 * V_211 = F_99 ( V_222 -> V_223 ) ;
struct V_183 * V_184 = V_211 -> V_28 -> V_3 -> V_184 ;
if ( F_41 ( ! ( F_23 ( & V_211 -> V_18 ) &
V_229 ) ) )
return NULL ;
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_388 ,
V_387 ,
V_184 -> V_3 -> V_20 . V_389 ) ;
if ( F_92 ( V_15 ) ) {
V_15 = NULL ;
goto V_34;
}
V_15 -> V_1 = V_222 ;
V_15 -> V_112 = F_173 ;
V_15 -> V_21 -> V_77 . V_231 = V_211 -> V_231 ;
V_15 -> V_21 -> V_77 . V_232 = V_211 -> V_28 -> V_233 ;
V_15 -> V_21 -> V_105 . V_334 . V_335 = V_345 ;
V_15 -> V_21 -> V_105 . V_334 . V_262 = V_263 ;
V_15 -> V_21 -> V_105 . V_334 . V_357 = V_390 ;
F_96 ( V_184 , & V_15 -> V_197 ) ;
V_381 = (struct V_381 * ) & V_15 -> V_21 -> V_105 . V_334 . V_381 ;
F_167 ( V_381 , V_222 , V_401 ) ;
F_4 ( V_15 , V_235 ) ;
if ( ! F_84 ( V_15 ) )
goto V_34;
F_11 ( V_15 ) ;
V_15 = NULL ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
return V_15 ;
}
static void F_175 ( struct V_5 * V_15 )
{
}
struct V_5 * F_176 ( struct V_2 * V_3 ,
struct V_402 * V_403 )
{
struct V_183 * V_184 = V_3 -> V_184 ;
struct V_5 * V_15 = NULL ;
struct V_301 * V_105 ;
int V_203 = - V_157 , V_256 ;
V_128 V_404 ;
if ( ! ( V_3 -> V_73 & V_279 ) )
return F_79 ( - V_258 ) ;
switch ( V_403 -> V_405 ) {
case V_406 :
V_404 = V_387 ;
break;
case V_407 :
V_404 = V_227 ;
break;
default:
return F_79 ( - V_239 ) ;
}
F_90 ( & V_184 -> V_204 ) ;
if ( F_91 ( V_184 ) )
goto V_34;
V_15 = F_78 ( V_184 , V_403 -> V_405 , V_404 , NULL ) ;
if ( F_92 ( V_15 ) ) {
V_203 = - V_408 ;
goto V_34;
}
V_15 -> V_112 = F_175 ;
V_105 = & V_15 -> V_21 -> V_105 . V_106 ;
V_105 -> V_409 = V_410 ;
V_105 -> V_310 = V_403 -> V_310 ;
V_256 = F_111 ( V_184 , & V_15 -> V_197 , V_403 -> V_411 ) ;
if ( V_256 != V_412 ) {
F_11 ( V_15 ) ;
goto V_34;
}
F_96 ( V_3 -> V_184 , & V_15 -> V_197 ) ;
F_4 ( V_15 , V_285 ) ;
V_203 = F_84 ( V_15 ) ;
V_34:
F_97 ( & V_184 -> V_204 ) ;
if ( ! V_203 ) {
F_123 ( & V_15 -> V_114 ) ;
return V_15 ;
}
return F_79 ( V_203 ) ;
}
void F_177 ( struct V_183 * V_184 , int V_413 )
{
struct V_2 * V_3 = V_184 -> V_3 ;
struct V_414 * V_415 = V_184 -> V_416 [ V_413 ] ;
struct V_417 * V_418 ;
struct V_5 * V_6 ;
unsigned long V_189 ;
int V_419 ;
for ( V_419 = 0 ; V_419 < V_420 ; V_419 ++ ) {
V_418 = & V_415 -> V_421 [ V_419 ] ;
V_189 = ( unsigned long ) V_418 -> V_422 ;
V_6 = F_88 ( V_3 -> V_118 , V_189 ) ;
if ( ! V_6 ) {
F_2 ( V_3 ) ;
F_178 ( L_98 ,
V_189 , F_179 ( & V_3 -> V_16 -> V_17 ) ) ;
}
V_6 -> V_197 . V_423 = V_413 ;
F_44 ( V_6 ) ;
if ( F_12 ( V_418 -> V_424 & V_425 ) )
break;
}
}
struct V_5 * F_180 ( struct V_183 * V_184 ,
struct V_414 * V_415 )
{
struct V_417 * V_418 = & V_415 -> V_421 [ 0 ] ;
V_234 V_189 = ( unsigned long ) V_418 -> V_422 ;
return F_181 ( V_184 -> V_3 -> V_118 , V_189 ) ;
}
