static void F_1 ( struct V_1 * V_2 )
{
memcpy ( ( void * ) V_2 , ( void * ) V_3 ,
sizeof( struct V_1 ) * V_4 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
memcpy ( ( void * ) V_2 , ( void * ) V_5 ,
sizeof( struct V_1 ) * V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
memcpy ( V_8 , V_9 ,
sizeof( struct V_7 ) * V_10 ) ;
}
static void F_4 ( struct V_7 * V_8 )
{
memcpy ( V_8 , V_11 ,
sizeof( struct V_7 ) * V_12 ) ;
}
static struct V_13 *
F_5 ( enum V_14 V_15 )
{
struct V_13 * V_16 = NULL ;
int V_17 , V_18 ;
if ( V_15 == V_19 ) {
V_17 = V_4 ;
V_18 = V_10 ;
} else if ( V_15 == V_20 ) {
V_17 = V_6 ;
V_18 = V_12 ;
} else {
goto exit;
}
V_16 = F_6 ( sizeof( struct V_13 ) +
sizeof( struct V_1 ) * V_17 +
sizeof( struct V_7 ) * V_18 ,
V_21 ) ;
if ( ! V_16 )
goto exit;
V_16 -> V_2 =
(struct V_1 * ) ( ( ( V_22 * ) V_16 ) +
sizeof( struct
V_13 ) ) ;
V_16 -> V_23 =
(struct V_7 * ) ( ( ( V_22 * ) V_16 -> V_2 ) +
sizeof( struct V_1 ) *
V_17 ) ;
V_16 -> V_15 = V_15 ;
V_16 -> V_17 = V_17 ;
V_16 -> V_18 = V_18 ;
if ( V_15 == V_19 ) {
F_1 ( V_16 -> V_2 ) ;
F_3 ( V_16 -> V_23 ) ;
} else if ( V_15 == V_20 ) {
F_2 ( V_16 -> V_2 ) ;
F_4 ( V_16 -> V_23 ) ;
}
exit:
return V_16 ;
}
static int F_7 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
int V_28 = 0 ;
struct V_1 * V_29 ;
struct V_30 * V_31 ;
T_1 V_32 ;
T_2 V_33 ;
T_3 V_34 ;
T_1 V_35 ;
T_1 V_36 ;
V_22 * V_37 ;
T_4 V_38 ;
T_5 V_39 ;
V_22 V_40 [ V_41 ] , * V_42 ;
T_4 V_43 , V_44 = 0 ;
struct V_45 * V_46 ;
unsigned short * V_47 ;
V_22 V_48 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_49 * V_50 = V_25 -> V_51 ;
struct V_52 * V_52 = V_50 -> V_52 ;
struct V_53 * V_54 = & V_25 -> V_55 ;
V_44 =
V_27 -> V_56 . V_57 + sizeof( struct V_58 ) ;
if ( V_44 > V_41 ) {
F_8 ( L_1 , V_59 ,
V_41 ) ;
goto exit;
}
V_32 = V_27 -> V_56 . V_60 . V_61 ;
if ( V_32 <= V_62 )
V_33 = F_9 ( V_32 ,
V_19 ) ;
else
V_33 = F_9 ( V_32 ,
V_20 ) ;
V_29 = F_10 ( V_52 , V_33 ) ;
V_34 = F_11 ( V_63 ) * 1000 ;
V_36 =
F_12 ( * ( T_1 * )
F_13 ( V_27 -> V_56 . V_64 ) ) ;
V_35 =
F_12 ( * ( T_1 * )
F_14 ( V_27 -> V_56 . V_64 ) ) ;
V_37 = V_27 -> V_56 . V_64 + V_65 ;
V_38 = V_27 -> V_56 . V_57 - V_65 ;
if ( F_15 ( V_54 , V_66 ) &&
F_16 ( & V_54 -> V_67 . V_56 ,
& V_27 -> V_56 ) ) {
V_39 = 100 * F_17 ( V_25 -> V_68 . V_69 ) ;
} else {
V_39 = 100 * F_17 ( V_27 -> V_56 . V_70 . V_71 ) ;
}
V_42 = V_40 ;
V_46 = (struct V_45 * ) V_42 ;
V_47 = & V_46 -> V_72 ;
* ( V_47 ) = 0 ;
F_18 ( V_46 , 0 ) ;
if ( V_27 -> V_56 . V_73 == 1 ) {
memcpy ( V_46 -> V_74 , V_48 , V_75 ) ;
F_19 ( V_42 , V_76 ) ;
} else {
memcpy ( V_46 -> V_74 , F_20 ( & V_25 -> V_77 ) , V_75 ) ;
F_19 ( V_42 , V_78 ) ;
}
memcpy ( V_46 -> V_79 , V_27 -> V_56 . V_80 , V_75 ) ;
memcpy ( V_46 -> V_81 , V_27 -> V_56 . V_80 , V_75 ) ;
V_42 += sizeof( struct V_58 ) ;
V_43 = sizeof( struct V_58 ) ;
memcpy ( V_42 , V_27 -> V_56 . V_64 , V_27 -> V_56 . V_57 ) ;
V_43 += V_27 -> V_56 . V_57 ;
V_31 = F_21 ( V_52 , V_29 ,
(struct V_82 * ) V_40 , V_43 ,
V_39 , V_83 ) ;
if ( F_22 ( ! V_31 ) ) {
F_8 ( L_2 ) ;
return - V_84 ;
}
F_23 ( V_52 , V_31 ) ;
exit:
return V_28 ;
}
void F_24 ( struct V_24 * V_25 )
{
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_26 * V_67 = & V_54 -> V_67 ;
struct V_49 * V_85 = V_25 -> V_51 ;
#ifdef F_25
struct V_86 * V_87 = & V_25 -> V_88 ;
#endif
F_8 ( L_3 , V_59 , V_25 ) ;
if ( V_85 -> V_89 != V_90 &&
V_85 -> V_89 != V_91 )
return;
if ( F_15 ( V_54 , V_92 ) )
return;
#ifdef F_25
if ( ! F_26 ( V_87 , V_93 ) ) {
F_27 ( V_87 , F_28 ( V_87 ) ) ;
F_29 ( V_87 , V_94 ) ;
F_30 ( V_87 , V_95 ) ;
F_8 ( L_4 ,
V_59 , F_31 ( V_87 ) ,
F_28 ( V_87 ) , F_32 ( V_87 ) ) ;
}
#endif
if ( F_33 ( V_25 ) > 0 ) {
struct V_52 * V_52 = V_85 -> V_52 ;
struct V_1 * V_29 ;
T_2 V_33 ;
T_1 V_32 = V_67 -> V_56 . V_60 . V_61 ;
if ( V_32 <= V_62 )
V_33 =
F_9 ( V_32 ,
V_19 ) ;
else
V_33 =
F_9 ( V_32 ,
V_20 ) ;
V_29 = F_10 ( V_52 , V_33 ) ;
F_8 ( L_5 , V_59 ) ;
F_34 ( V_25 -> V_96 , V_29 ,
V_67 -> V_56 . V_80 ,
V_54 -> V_97 +
sizeof( struct V_58 ) + 2 ,
V_54 -> V_98 -
sizeof( struct V_58 ) - 2 ,
V_54 -> V_99 +
sizeof( struct V_58 ) + 6 ,
V_54 -> V_100 -
sizeof( struct V_58 ) - 6 ,
V_83 ) ;
} else {
F_35 ( V_25 -> V_96 ,
V_67 -> V_56 . V_80 ,
V_54 -> V_97 +
sizeof( struct V_58 ) + 2 ,
V_54 -> V_98 -
sizeof( struct V_58 ) - 2 ,
V_54 -> V_99 +
sizeof( struct V_58 ) + 6 ,
V_54 -> V_100 -
sizeof( struct V_58 ) - 6 ,
V_101 , V_83 ) ;
}
}
void F_36 ( struct V_24 * V_25 )
{
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_49 * V_85 = V_25 -> V_51 ;
#ifdef F_25
struct V_86 * V_87 = & V_25 -> V_88 ;
#endif
F_8 ( L_3 , V_59 , V_25 ) ;
if ( V_85 -> V_89 != V_90 &&
V_85 -> V_89 != V_91 )
return;
if ( F_15 ( V_54 , V_92 ) )
return;
#ifdef F_25
if ( ! F_26 ( V_87 , V_93 ) ) {
F_37 ( & V_87 -> V_102 ) ;
F_37 ( & V_87 -> V_103 ) ;
F_37 ( & V_87 -> V_104 ) ;
F_30 ( V_87 , F_32 ( V_87 ) ) ;
F_29 ( V_87 , V_105 ) ;
F_8 ( L_4 ,
V_59 , F_31 ( V_87 ) ,
F_28 ( V_87 ) , F_32 ( V_87 ) ) ;
}
#endif
if ( ! V_25 -> V_55 . V_106 ) {
if ( F_15 ( & V_25 -> V_55 , V_107 ) ) {
F_35 ( V_25 -> V_96 , NULL , NULL ,
0 , NULL , 0 ,
V_108 ,
V_83 ) ;
} else {
F_38 ( V_25 -> V_96 , 0 , NULL ,
0 , V_83 ) ;
}
}
}
static V_22 F_39 ( struct V_24 * V_25 , struct V_109 * V_110 )
{
struct V_111 * V_112 ;
struct V_113 * V_114 ;
struct V_115 * V_116 = & V_25 -> V_117 ;
V_22 V_118 = V_119 ;
V_112 = F_6 ( sizeof( struct V_111 ) , V_21 ) ;
if ( V_112 == NULL ) {
V_118 = V_120 ;
goto exit;
}
V_114 = F_6 ( sizeof( struct V_113 ) , V_21 ) ;
if ( V_114 == NULL ) {
F_40 ( V_112 ) ;
V_118 = V_120 ;
goto exit;
}
F_41 ( V_112 , V_114 , V_121 ) ;
V_114 -> V_122 = ( V_22 ) V_110 -> V_123 ;
memcpy ( V_114 -> V_124 , V_110 -> V_125 , V_75 ) ;
memcpy ( V_114 -> V_126 , & V_110 -> V_127 , 16 ) ;
V_118 = F_42 ( V_116 , V_112 ) ;
exit:
return V_118 ;
}
static int F_43 ( struct V_24 * V_25 , V_22 * V_126 , V_22 V_128 ,
int V_129 )
{
V_22 V_130 ;
struct V_111 * V_131 ;
struct V_132 * V_133 ;
struct V_115 * V_116 = & V_25 -> V_117 ;
int V_118 = V_119 ;
F_8 ( L_6 , V_59 ) ;
V_131 = F_6 ( sizeof( struct V_111 ) , V_21 ) ;
if ( ! V_131 ) {
V_118 = V_120 ;
goto exit;
}
V_133 = F_6 ( sizeof( struct V_132 ) , V_21 ) ;
if ( ! V_133 ) {
F_40 ( V_131 ) ;
V_118 = V_120 ;
goto exit;
}
V_133 -> V_129 = ( V_22 ) V_129 ;
if ( F_44 ( V_128 ) )
V_25 -> V_55 . V_134 |= F_45 ( V_133 -> V_129 ) ;
V_133 -> V_122 = V_128 ;
V_133 -> V_135 = 1 ;
switch ( V_128 ) {
case V_136 :
V_130 = 5 ;
break;
case V_137 :
V_130 = 13 ;
break;
case V_138 :
case V_139 :
case V_140 :
default:
V_130 = 16 ;
}
memcpy ( & V_133 -> V_126 [ 0 ] , V_126 , V_130 ) ;
V_131 -> V_141 = V_142 ;
V_131 -> V_143 = ( V_22 * ) V_133 ;
V_131 -> V_144 = ( sizeof( struct V_132 ) ) ;
V_131 -> V_145 = NULL ;
V_131 -> V_146 = 0 ;
F_46 ( & V_131 -> V_147 ) ;
V_118 = F_42 ( V_116 , V_131 ) ;
exit:
return V_118 ;
}
static int F_47 ( struct V_24 * V_25 , V_22 * V_126 , V_22 V_130 ,
int V_129 )
{
V_22 V_128 ;
switch ( V_130 ) {
case 5 :
V_128 = V_136 ;
break;
case 13 :
V_128 = V_137 ;
break;
default:
V_128 = V_148 ;
}
return F_43 ( V_25 , V_126 , V_128 , V_129 ) ;
}
static int F_48 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
T_2 V_153 )
{
int V_28 = 0 ;
T_2 V_154 , V_155 ;
struct V_109 * V_110 = NULL , * V_156 = NULL ;
struct V_24 * V_25 = F_49 ( V_150 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_157 * V_158 = & V_25 -> V_159 ;
struct V_160 * V_161 = & V_25 -> V_162 ;
F_8 ( L_6 , V_59 ) ;
V_152 -> V_163 . V_164 . V_165 = 0 ;
V_152 -> V_163 . V_164 . V_128 [ V_166 - 1 ] = '\0' ;
if ( V_153 != sizeof( struct V_151 ) + V_152 -> V_163 . V_164 . V_167 ) {
V_28 = - V_84 ;
goto exit;
}
if ( F_50 ( V_152 -> V_168 ) ) {
if ( V_152 -> V_163 . V_164 . V_169 >= V_170 ) {
V_28 = - V_84 ;
goto exit;
}
} else {
V_110 = F_51 ( V_161 , V_152 -> V_168 ) ;
if ( ! V_110 ) {
F_8 ( L_7
L_8 ) ;
goto exit;
}
}
if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_9 ) == 0 && ( V_110 == NULL ) ) {
F_8 ( L_10 ,
V_152 -> V_163 . V_164 . V_169 ) ;
goto exit;
}
if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_11 ) == 0 && ( V_110 == NULL ) ) {
F_8 ( L_12 ) ;
V_154 = V_152 -> V_163 . V_164 . V_169 ;
V_155 = V_152 -> V_163 . V_164 . V_167 ;
F_8 ( L_13 ,
V_154 , V_155 ) ;
if ( ( V_154 >= V_170 ) || ( V_155 <= 0 ) ) {
V_28 = - V_84 ;
goto exit;
}
if ( V_155 > 0 ) {
V_155 = V_155 <= 5 ? 5 : 13 ;
}
if ( V_158 -> V_171 == 0 ) {
V_158 -> V_172 =
V_173 ;
V_158 -> V_174 = V_136 ;
V_158 -> V_175 = V_136 ;
if ( V_155 == 13 ) {
V_158 -> V_174 = V_137 ;
V_158 -> V_175 = V_137 ;
}
V_158 -> V_176 = V_154 ;
}
memcpy ( & V_158 -> V_177 [ V_154 ] . V_178 [ 0 ] ,
V_152 -> V_163 . V_164 . V_126 , V_155 ) ;
V_158 -> V_179 [ V_154 ] = V_155 ;
F_47 ( V_25 , V_152 -> V_163 . V_164 . V_126 , V_155 ,
V_154 ) ;
goto exit;
}
if ( ! V_110 && F_15 ( V_54 , V_92 ) ) {
if ( V_152 -> V_163 . V_164 . V_135 == 0 ) {
if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_11 ) == 0 ) {
F_8 ( L_14 ,
V_59 ) ;
memcpy ( V_158 ->
V_180 [ V_152 -> V_163 . V_164 . V_169 ] .
V_178 , V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 . V_167 ) ) ;
V_158 -> V_175 = V_136 ;
if ( V_152 -> V_163 . V_164 . V_167 == 13 ) {
V_158 -> V_175 =
V_137 ;
}
} else if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_15 ) == 0 ) {
F_8 ( L_16 ,
V_59 ) ;
V_158 -> V_175 = V_138 ;
memcpy ( V_158 ->
V_180 [ V_152 -> V_163 . V_164 . V_169 ] .
V_178 , V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 . V_167 ) ) ;
memcpy ( V_158 ->
V_181 [ V_152 -> V_163 . V_164 .
V_169 ] . V_178 ,
& V_152 -> V_163 . V_164 . V_126 [ 16 ] , 8 ) ;
memcpy ( V_158 ->
V_182 [ V_152 -> V_163 . V_164 .
V_169 ] . V_178 ,
& V_152 -> V_163 . V_164 . V_126 [ 24 ] , 8 ) ;
V_158 -> V_183 = true ;
} else if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_17 ) == 0 ) {
F_8 ( L_18 ,
V_59 ) ;
V_158 -> V_175 = V_140 ;
memcpy ( V_158 ->
V_180 [ V_152 -> V_163 . V_164 . V_169 ] .
V_178 , V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 . V_167 ) ) ;
} else {
F_8 ( L_19 ,
V_59 ) ;
V_158 -> V_175 =
V_148 ;
}
V_158 -> V_184 = V_152 -> V_163 . V_164 . V_169 ;
V_158 -> V_185 = true ;
V_158 -> V_174 =
V_158 -> V_175 ;
F_43 ( V_25 , V_152 -> V_163 . V_164 . V_126 ,
V_158 -> V_175 ,
V_152 -> V_163 . V_164 . V_169 ) ;
V_156 = F_52 ( V_25 ) ;
if ( V_156 ) {
V_156 -> V_186 = false ;
V_156 -> V_123 =
V_158 -> V_175 ;
}
}
goto exit;
}
if ( V_158 -> V_187 ==
V_188 && V_110 ) {
if ( F_15 ( V_54 , V_92 ) ) {
if ( V_152 -> V_163 . V_164 . V_135 == 1 ) {
memcpy ( V_110 -> V_127 . V_178 ,
V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 . V_167 ) ) ;
if ( ! strcmp ( V_152 -> V_163 . V_164 . V_128 , L_11 ) ) {
F_8 ( L_20 ,
V_59 ) ;
V_110 -> V_123 = V_136 ;
if ( V_152 -> V_163 . V_164 . V_167 == 13 ) {
V_110 -> V_123 =
V_137 ;
}
} else if ( ! strcmp ( V_152 -> V_163 . V_164 . V_128 , L_15 ) ) {
F_8 ( L_21
L_22 , V_59 ) ;
V_110 -> V_123 = V_138 ;
memcpy ( V_110 -> V_189 . V_178 ,
& V_152 -> V_163 . V_164 . V_126 [ 16 ] , 8 ) ;
memcpy ( V_110 -> V_190 . V_178 ,
& V_152 -> V_163 . V_164 . V_126 [ 24 ] , 8 ) ;
V_158 -> V_183 = true ;
} else if ( ! strcmp ( V_152 -> V_163 . V_164 . V_128 , L_17 ) ) {
F_8 ( L_21
L_23 , V_59 ) ;
V_110 -> V_123 = V_140 ;
} else {
F_8 ( L_21
L_24 , V_59 ) ;
V_110 -> V_123 = V_148 ;
}
F_39 ( V_25 , V_110 ) ;
V_110 -> V_186 = false ;
V_110 -> V_191 = true ;
} else {
if ( ! strcmp ( V_152 -> V_163 . V_164 . V_128 , L_11 ) ) {
memcpy ( V_158 ->
V_180 [ V_152 -> V_163 . V_164 .
V_169 ] . V_178 ,
V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 .
V_167 ) ) ;
V_158 -> V_175 =
V_136 ;
if ( V_152 -> V_163 . V_164 . V_167 == 13 ) {
V_158 ->
V_175 =
V_137 ;
}
} else if ( ! strcmp ( V_152 -> V_163 . V_164 . V_128 , L_15 ) ) {
V_158 -> V_175 =
V_138 ;
memcpy ( V_158 ->
V_180 [ V_152 -> V_163 . V_164 .
V_169 ] . V_178 ,
V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 .
V_167 ) ) ;
memcpy ( V_158 ->
V_181 [ V_152 -> V_163 .
V_164 . V_169 ] .
V_178 , & V_152 -> V_163 . V_164 . V_126 [ 16 ] ,
8 ) ;
memcpy ( V_158 ->
V_182 [ V_152 -> V_163 .
V_164 . V_169 ] .
V_178 , & V_152 -> V_163 . V_164 . V_126 [ 24 ] ,
8 ) ;
V_158 -> V_183 = true ;
} else if ( ! strcmp ( V_152 -> V_163 . V_164 . V_128 , L_17 ) ) {
V_158 -> V_175 =
V_140 ;
memcpy ( V_158 ->
V_180 [ V_152 -> V_163 . V_164 .
V_169 ] . V_178 ,
V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 .
V_167 ) ) ;
} else {
V_158 -> V_175 =
V_148 ;
}
V_158 -> V_184 =
V_152 -> V_163 . V_164 . V_169 ;
V_158 -> V_185 = true ;
V_158 -> V_174 =
V_158 -> V_175 ;
F_43 ( V_25 , V_152 -> V_163 . V_164 . V_126 ,
V_158 ->
V_175 ,
V_152 -> V_163 . V_164 . V_169 ) ;
V_156 = F_52 ( V_25 ) ;
if ( V_156 ) {
V_156 -> V_186 = false ;
V_156 -> V_123 = V_158 -> V_175 ;
}
}
}
}
exit:
return V_28 ;
}
static int F_53 ( struct V_149 * V_150 ,
struct V_151 * V_152 , T_2 V_153 )
{
int V_28 = 0 ;
T_2 V_154 , V_155 ;
struct V_24 * V_25 = F_49 ( V_150 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_157 * V_158 = & V_25 -> V_159 ;
#ifdef F_25
struct V_86 * V_87 = & V_25 -> V_88 ;
#endif
F_8 ( L_6 , V_59 ) ;
V_152 -> V_163 . V_164 . V_165 = 0 ;
V_152 -> V_163 . V_164 . V_128 [ V_166 - 1 ] = '\0' ;
if ( V_153 <
( T_2 ) ( ( V_22 * ) V_152 -> V_163 . V_164 . V_126 - ( V_22 * ) V_152 ) +
V_152 -> V_163 . V_164 . V_167 ) {
V_28 = - V_84 ;
goto exit;
}
if ( F_50 ( V_152 -> V_168 ) ) {
if ( V_152 -> V_163 . V_164 . V_169 >= V_170 ) {
V_28 = - V_84 ;
goto exit;
}
} else {
V_28 = - V_84 ;
goto exit;
}
if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_11 ) == 0 ) {
F_54 ( V_192 , V_193 ,
( L_25 ) ) ;
F_8 ( L_25 ) ;
V_154 = V_152 -> V_163 . V_164 . V_169 ;
V_155 = V_152 -> V_163 . V_164 . V_167 ;
if ( ( V_154 > V_170 ) || ( V_155 <= 0 ) ) {
V_28 = - V_84 ;
goto exit;
}
if ( V_158 -> V_171 == 0 ) {
V_155 = V_155 <= 5 ? 5 : 13 ;
V_158 -> V_172 =
V_173 ;
V_158 -> V_174 = V_136 ;
V_158 -> V_175 = V_136 ;
if ( V_155 == 13 ) {
V_158 -> V_174 = V_137 ;
V_158 -> V_175 = V_137 ;
}
V_158 -> V_176 = V_154 ;
}
memcpy ( & V_158 -> V_177 [ V_154 ] . V_178 [ 0 ] ,
V_152 -> V_163 . V_164 . V_126 , V_155 ) ;
V_158 -> V_179 [ V_154 ] = V_155 ;
F_55 ( V_25 , V_158 , V_154 , 0 ) ;
goto exit;
}
if ( V_25 -> V_159 . V_187 ==
V_188 ) {
struct V_109 * V_110 , * V_156 ;
struct V_160 * V_161 = & V_25 -> V_162 ;
if ( F_15 ( V_54 ,
V_194 | V_195 ) ) {
V_110 = F_51 ( V_161 , F_56 ( V_54 ) ) ;
if ( V_110 == NULL ) {
F_8 ( L_26 ,
V_59 ) ;
} else {
if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_9 ) != 0 )
V_110 -> V_186 = false ;
if ( ( V_25 -> V_159 . V_172 ==
V_196 ) ||
( V_25 -> V_159 . V_172 ==
V_197 ) ) {
V_110 -> V_123 =
V_25 -> V_159 .
V_174 ;
}
if ( V_152 -> V_163 . V_164 . V_135 == 1 ) {
F_8 ( L_27
L_28 , V_59 ) ;
memcpy ( V_110 -> V_127 . V_178 ,
V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 .
V_167 ) ) ;
if ( strcmp ( V_152 -> V_163 . V_164 . V_128 ,
L_15 ) == 0 ) {
memcpy ( V_110 -> V_189 .
V_178 ,
& V_152 -> V_163 . V_164 . V_126 [ 16 ] ,
8 ) ;
memcpy ( V_110 -> V_190 .
V_178 ,
& V_152 -> V_163 . V_164 . V_126 [ 24 ] ,
8 ) ;
V_25 -> V_159 .
V_183 = false ;
}
F_8 ( L_29 ) ;
F_57 ( V_25 ,
( unsigned char * ) V_110 ,
true ) ;
} else {
memcpy ( V_25 -> V_159 .
V_180 [ V_152 -> V_163 . V_164 .
V_169 ] . V_178 ,
V_152 -> V_163 . V_164 . V_126 ,
( V_152 -> V_163 . V_164 . V_167 >
16 ? 16 : V_152 -> V_163 . V_164 .
V_167 ) ) ;
memcpy ( V_25 -> V_159 .
V_181 [ V_152 -> V_163 .
V_164 . V_169 ] .
V_178 , & V_152 -> V_163 . V_164 . V_126 [ 16 ] ,
8 ) ;
memcpy ( V_25 -> V_159 .
V_182 [ V_152 -> V_163 .
V_164 . V_169 ] .
V_178 , & V_152 -> V_163 . V_164 . V_126 [ 24 ] ,
8 ) ;
V_25 -> V_159 . V_185 =
true ;
F_8
( L_30 ) ;
V_25 -> V_159 .
V_184 =
V_152 -> V_163 . V_164 . V_169 ;
F_55 ( V_25 ,
& V_25 -> V_159 ,
V_152 -> V_163 . V_164 . V_169 , 1 ) ;
#ifdef F_25
if ( F_26
( V_87 ,
V_198 ) ) {
F_30 ( V_87 ,
V_199 ) ;
}
#endif
}
}
V_156 = F_52 ( V_25 ) ;
if ( V_156 ) {
if ( strcmp ( V_152 -> V_163 . V_164 . V_128 , L_9 ) != 0 )
V_156 -> V_186 = false ;
if ( ( V_25 -> V_159 . V_172 ==
V_196 ) ||
( V_25 -> V_159 . V_172 ==
V_197 ) ) {
V_156 -> V_123 =
V_25 -> V_159 .
V_174 ;
}
}
} else if ( F_15 ( V_54 , V_200 ) ) {
}
}
exit:
F_8 ( L_31 , V_59 , V_28 ) ;
return V_28 ;
}
static int F_58 ( struct V_52 * V_52 , struct V_149 * V_201 ,
V_22 V_202 , bool V_203 ,
const V_22 * V_204 , struct V_205 * V_206 )
{
char * V_207 ;
T_2 V_153 ;
struct V_151 * V_152 = NULL ;
int V_28 = 0 ;
struct V_49 * V_51 = F_59 ( V_52 ) ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
F_8 ( V_208 L_32 , F_61 ( V_201 ) ,
V_204 ) ;
F_8 ( L_33 , V_206 -> V_209 ) ;
F_8 ( L_34 , V_206 -> V_167 ) ;
F_8 ( L_35 , V_206 -> V_210 ) ;
F_8 ( L_36 , V_202 ) ;
F_8 ( L_37 , V_203 ) ;
V_153 = sizeof( struct V_151 ) + V_206 -> V_167 ;
V_152 = F_6 ( V_153 , V_21 ) ;
if ( V_152 == NULL )
return - 1 ;
V_152 -> V_211 = V_212 ;
memset ( V_152 -> V_168 , 0xff , V_75 ) ;
switch ( V_206 -> V_209 ) {
case V_213 :
V_207 = L_9 ;
break;
case V_214 :
case V_215 :
V_207 = L_11 ;
break;
case V_216 :
V_207 = L_15 ;
break;
case V_217 :
V_207 = L_17 ;
break;
default:
V_28 = - V_218 ;
goto V_219;
}
strncpy ( ( char * ) V_152 -> V_163 . V_164 . V_128 , V_207 , V_166 ) ;
if ( ! V_204 || F_50 ( V_204 ) ) {
V_152 -> V_163 . V_164 . V_135 = 0 ;
} else {
V_152 -> V_163 . V_164 . V_135 = 1 ;
}
V_152 -> V_163 . V_164 . V_169 = V_202 ;
if ( V_206 -> V_210 && V_206 -> V_220 ) {
memcpy ( V_152 -> V_163 . V_164 . V_220 , V_206 -> V_220 , V_206 -> V_210 ) ;
}
if ( V_206 -> V_167 && V_206 -> V_126 ) {
V_152 -> V_163 . V_164 . V_167 = V_206 -> V_167 ;
memcpy ( V_152 -> V_163 . V_164 . V_126 , V_206 -> V_126 , V_206 -> V_167 ) ;
}
if ( F_15 ( V_54 , V_194 ) ) {
V_28 = F_53 ( V_201 , V_152 , V_153 ) ;
} else if ( F_15 ( V_54 , V_92 ) ) {
#ifdef F_62
if ( V_204 )
memcpy ( V_152 -> V_168 , ( void * ) V_204 , V_75 ) ;
V_28 = F_48 ( V_201 , V_152 , V_153 ) ;
#endif
} else {
F_8 ( L_38 ,
V_54 -> V_221 , V_51 -> V_89 ) ;
}
V_219:
F_40 ( V_152 ) ;
return V_28 ;
}
static int
F_63 ( struct V_52 * V_52 , struct V_149 * V_201 ,
V_22 V_202 , bool V_203 , const V_22 * V_204 ,
void * V_222 ,
void (* F_64) ( void * V_222 , struct V_205 * ) )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return 0 ;
}
static int F_65 ( struct V_52 * V_52 , struct V_149 * V_201 ,
V_22 V_202 , bool V_203 ,
const V_22 * V_204 )
{
struct V_24 * V_25 = F_49 ( V_201 ) ;
struct V_157 * V_158 = & V_25 -> V_159 ;
F_8 ( V_208 L_40 , F_61 ( V_201 ) ,
V_202 ) ;
if ( V_202 == V_158 -> V_176 ) {
V_158 -> V_171 = 0 ;
}
return 0 ;
}
static int F_66 ( struct V_52 * V_52 ,
struct V_149 * V_201 , V_22 V_202 ,
bool V_223 , bool V_224 )
{
struct V_24 * V_25 = F_49 ( V_201 ) ;
struct V_157 * V_158 = & V_25 -> V_159 ;
F_8 ( V_208 L_41
L_42 , F_61 ( V_201 ) ,
V_202 , V_223 , V_224 ) ;
if ( ( V_202 < V_170 ) &&
( ( V_158 -> V_174 == V_136 ) ||
( V_158 -> V_174 == V_137 ) ) ) {
V_158 -> V_172 = V_173 ;
V_158 -> V_176 = V_202 ;
V_158 -> V_174 = V_136 ;
V_158 -> V_175 = V_136 ;
if ( V_158 -> V_179 [ V_202 ] == 13 ) {
V_158 -> V_174 = V_137 ;
V_158 -> V_175 = V_137 ;
}
V_158 -> V_171 = 1 ;
}
return 0 ;
}
static int F_67 ( struct V_52 * V_52 ,
struct V_149 * V_201 ,
V_22 * V_225 , struct V_226 * V_227 )
{
int V_28 = 0 ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_109 * V_110 = NULL ;
struct V_160 * V_161 = & V_25 -> V_162 ;
V_227 -> V_228 = 0 ;
if ( ! V_225 ) {
F_8 ( V_208 L_43 , F_61 ( V_201 ) , V_225 ) ;
V_28 = - V_229 ;
goto exit;
}
V_110 = F_51 ( V_161 , V_225 ) ;
if ( V_110 == NULL ) {
F_8 ( L_44 , V_59 ) ;
V_28 = - V_229 ;
goto exit;
}
#ifdef F_68
F_8 ( V_208 L_45 V_230 L_39 , F_61 ( V_201 ) ,
F_69 ( V_225 ) ) ;
#endif
if ( F_15 ( V_54 , V_194 ) &&
F_15 ( V_54 , V_66 ) ) {
struct V_26 * V_67 = & V_54 -> V_67 ;
if ( memcmp ( V_225 , V_67 -> V_56 . V_80 , V_75 ) ) {
F_8 ( L_46 V_230 L_39 , V_59 ,
F_69 ( V_67 -> V_56 . V_80 ) ) ;
V_28 = - V_229 ;
goto exit;
}
V_227 -> V_228 |= V_231 ;
V_227 -> signal = F_17 ( V_25 -> V_68 .
V_69 ) ;
V_227 -> V_228 |= V_232 ;
V_227 -> V_233 . V_234 = F_70 ( V_25 ) ;
V_227 -> V_228 |= V_235 ;
V_227 -> V_236 = F_71 ( V_110 ) ;
V_227 -> V_228 |= V_237 ;
V_227 -> V_238 = V_110 -> V_239 . V_240 ;
}
if ( ( F_15 ( V_54 , V_200 ) ||
F_15 ( V_54 , V_241 ) ||
F_15 ( V_54 , V_92 ) ) &&
F_15 ( V_54 , V_66 )
) {
}
exit:
return V_28 ;
}
static int F_72 ( struct V_52 * V_52 ,
struct V_149 * V_201 ,
enum V_242 type , T_2 * V_243 ,
struct V_244 * V_206 )
{
enum V_242 V_245 ;
enum V_246 V_247 ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_248 * V_249 = & V_25 -> V_250 ;
struct V_49 * V_51 = F_59 ( V_52 ) ;
#ifdef F_25
struct V_86 * V_87 = & V_25 -> V_88 ;
#endif
int V_28 = 0 ;
V_22 V_251 = false ;
F_8 ( V_208 L_47 , F_61 ( V_201 ) ) ;
if ( F_73 ( V_201 ) != 0 ) {
V_28 = - V_252 ;
goto exit;
}
if ( V_120 == F_74 ( V_25 ) ) {
V_28 = - V_252 ;
goto exit;
}
V_245 = V_51 -> V_89 ;
F_8 ( V_208 L_48 ,
F_61 ( V_201 ) , V_245 , type ) ;
if ( V_245 != type ) {
V_251 = true ;
V_249 -> V_253 = 0xffff ;
V_249 -> V_254 = 0xff ;
}
switch ( type ) {
case V_255 :
V_247 = V_256 ;
break;
case V_91 :
case V_90 :
V_247 = V_257 ;
#ifdef F_25
if ( V_251 && F_75 ( V_87 , V_258 ) ) {
F_37 ( & V_87 -> V_102 ) ;
F_37 ( & V_87 -> V_103 ) ;
F_37 ( & V_87 -> V_104 ) ;
F_29 ( V_87 , V_105 ) ;
F_30 ( V_87 , F_32 ( V_87 ) ) ;
F_8 ( L_49
L_50 , V_59 , F_31 ( V_87 ) ,
F_28 ( V_87 ) ,
F_32 ( V_87 ) ) ;
}
#endif
break;
case V_259 :
case V_260 :
V_247 = V_261 ;
#ifdef F_25
if ( V_251 && ! F_26 ( V_87 , V_93 ) ) {
F_29 ( V_87 , V_258 ) ;
}
#endif
break;
default:
return - V_262 ;
}
V_51 -> V_89 = type ;
if ( F_76 ( V_25 , V_247 ) == false ) {
V_51 -> V_89 = V_245 ;
V_28 = - V_252 ;
goto exit;
}
F_77 ( V_25 , V_247 ) ;
exit:
return V_28 ;
}
void F_78 ( struct V_263 * V_264 ,
bool V_265 )
{
F_79 ( & V_264 -> V_266 ) ;
if ( V_264 -> V_267 != NULL ) {
#ifdef F_68
F_8 ( L_51 , V_59 ) ;
#endif
if ( V_264 -> V_267 -> V_52 !=
V_264 -> V_51 -> V_52 )
F_8 ( L_52 ) ;
else
F_80 ( V_264 -> V_267 , V_265 ) ;
V_264 -> V_267 = NULL ;
} else {
#ifdef F_68
F_8 ( L_53 , V_59 ) ;
#endif
}
F_81 ( & V_264 -> V_266 ) ;
}
void F_82 ( struct V_24 * V_25 )
{
struct V_268 * V_269 , * V_270 , * V_271 ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_272 * V_273 = & V_54 -> V_274 ;
struct V_26 * V_27 ;
#ifdef F_68
F_8 ( L_6 , V_59 ) ;
#endif
F_79 ( & V_54 -> V_274 . V_275 ) ;
V_270 = F_83 ( V_273 ) ;
F_84 (plist, ptmp, phead) {
V_27 = F_85 ( V_269 , struct V_26 , V_147 ) ;
if ( F_86
( V_25 -> V_250 . V_276 ,
V_27 -> V_56 . V_60 . V_61 ) >= 0 )
F_7 ( V_25 , V_27 ) ;
}
F_81 ( & V_54 -> V_274 . V_275 ) ;
F_78 ( F_87 ( V_25 -> V_51 ) ,
false ) ;
}
static int F_88 ( struct V_24 * V_25 ,
char * V_40 , int V_43 )
{
int V_28 = 0 ;
T_6 V_277 = 0 ;
V_22 * V_278 ;
#ifdef F_25
T_2 V_279 = 0 ;
V_22 * V_280 ;
T_2 V_281 = 0 ;
#endif
struct V_53 * V_54 = & V_25 -> V_55 ;
#ifdef F_68
F_8 ( L_54 , V_59 , V_43 ) ;
#endif
if ( V_43 > 0 ) {
V_278 = F_89 ( V_40 , V_43 , NULL , & V_277 ) ;
if ( V_278 ) {
#ifdef F_68
F_8 ( L_55 , V_277 ) ;
#endif
if ( V_54 -> V_282 ) {
V_54 -> V_283 = 0 ;
F_40 ( V_54 -> V_282 ) ;
V_54 -> V_282 = NULL ;
}
V_54 -> V_282 =
F_90 ( V_277 , V_21 ) ;
if ( V_54 -> V_282 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
memcpy ( V_54 -> V_282 , V_278 , V_277 ) ;
V_54 -> V_283 = V_277 ;
}
#ifdef F_25
V_280 = F_91 ( V_40 , V_43 , NULL , & V_279 ) ;
if ( V_280 ) {
#ifdef F_68
F_8 ( L_57 , V_279 ) ;
#endif
if ( V_54 -> V_284 ) {
V_54 -> V_285 = 0 ;
F_40 ( V_54 -> V_284 ) ;
V_54 -> V_284 = NULL ;
}
V_54 -> V_284 =
F_90 ( V_279 , V_21 ) ;
if ( V_54 -> V_284 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
memcpy ( V_54 -> V_284 , V_280 , V_279 ) ;
V_54 -> V_285 = V_279 ;
}
#endif
#ifdef F_25
if ( F_92 ( V_40 , V_43 , NULL , & V_281 ) ) {
#ifdef F_68
F_8 ( L_58 , V_281 ) ;
#endif
if ( V_54 -> V_286 ) {
V_54 -> V_287 = 0 ;
F_40 ( V_54 -> V_286 ) ;
V_54 -> V_286 = NULL ;
}
V_54 -> V_286 =
F_90 ( V_281 , V_21 ) ;
if ( V_54 -> V_286 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
F_92 ( V_40 , V_43 , V_54 -> V_286 ,
& V_54 -> V_287 ) ;
}
#endif
}
return V_28 ;
}
static int F_93 ( struct V_52 * V_52 ,
struct V_288 * V_289 )
{
int V_290 ;
V_22 V_291 = false ;
int V_28 = 0 ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_292 V_293 [ V_294 ] ;
struct V_295 V_296 [ V_297 ] ;
struct V_263 * V_264 = F_87 ( V_25 -> V_51 ) ;
struct V_292 * V_298 = V_289 -> V_298 ;
#ifdef F_25
struct V_86 * V_87 = & V_25 -> V_88 ;
int V_299 = 0 ;
#endif
bool V_300 = false ;
#ifdef F_68
F_8 ( V_301 L_39 , F_94 ( V_25 ) ) ;
#endif
F_79 ( & V_264 -> V_266 ) ;
V_264 -> V_267 = V_289 ;
F_81 ( & V_264 -> V_266 ) ;
if ( F_15 ( V_54 , V_92 ) ) {
#ifdef F_68
F_8 ( L_59 , V_59 ) ;
#endif
}
if ( F_74 ( V_25 ) == V_120 ) {
V_300 = true ;
goto V_302;
}
#ifdef F_25
if ( ! memcmp ( V_298 -> V_293 , L_60 , 7 ) &&
F_91 ( ( V_22 * ) V_289 -> V_303 , V_289 -> V_304 , NULL , NULL ) ) {
if ( F_26 ( V_87 , V_93 ) ) {
F_95 ( V_25 , V_105 ) ;
F_87 ( V_25 -> V_51 ) -> V_305 = true ;
} else {
F_27 ( V_87 , F_28 ( V_87 ) ) ;
#ifdef F_68
F_8 ( L_61 , V_59 ,
F_31 ( V_87 ) ,
F_28 ( V_87 ) ) ;
#endif
}
F_30 ( V_87 , V_306 ) ;
if ( V_289 -> V_17 == 3 &&
V_289 -> V_2 [ 0 ] -> V_307 == 1 &&
V_289 -> V_2 [ 1 ] -> V_307 == 6 &&
V_289 -> V_2 [ 2 ] -> V_307 == 11 )
V_299 = 1 ;
}
#endif
if ( V_289 -> V_303 && V_289 -> V_304 > 0 ) {
F_88 ( V_25 ,
( V_22 * ) V_289 -> V_303 ,
V_289 -> V_304 ) ;
}
if ( V_54 -> V_308 . V_309 == true ) {
F_8 ( L_62 , V_59 ) ;
V_300 = true ;
goto V_302;
}
if ( F_96 ( V_25 ) ) {
F_8 ( V_301 L_63 ,
F_94 ( V_25 ) ) ;
V_300 = true ;
goto V_302;
}
if ( F_15 ( V_54 , V_310 | V_311 ) ==
true ) {
F_8 ( L_64 , V_59 , V_54 -> V_221 ) ;
V_300 = true ;
goto V_302;
}
#ifdef F_25
if ( ! F_26 ( V_87 , V_93 ) &&
! F_26 ( V_87 , V_312 ) ) {
F_30 ( V_87 , V_313 ) ;
F_97 ( V_25 , true ) ;
if ( V_299 == 0 )
F_98 ( V_87 ,
V_314 ) ;
else
F_98 ( V_87 ,
V_315 ) ;
}
#endif
memset ( V_293 , 0 , sizeof( struct V_292 ) * V_294 ) ;
for ( V_290 = 0 ; V_290 < V_289 -> V_316 && V_290 < V_294 ; V_290 ++ ) {
#ifdef F_68
F_8 ( L_65 , V_298 [ V_290 ] . V_293 ,
V_298 [ V_290 ] . V_317 ) ;
#endif
memcpy ( V_293 [ V_290 ] . V_293 , V_298 [ V_290 ] . V_293 , V_298 [ V_290 ] . V_317 ) ;
V_293 [ V_290 ] . V_317 = V_298 [ V_290 ] . V_317 ;
}
memset ( V_296 , 0 ,
sizeof( struct V_295 ) * V_297 ) ;
if ( V_289 -> V_17 == 1 ) {
for ( V_290 = 0 ; V_290 < V_289 -> V_17 &&
V_290 < V_297 ; V_290 ++ ) {
#ifdef F_68
F_8 (FUNC_ADPT_FMT CHAN_FMT L_39 ,
FUNC_ADPT_ARG(padapter),
CHAN_ARG(request->channels[i])) ;
#endif
V_296 [ V_290 ] . V_307 = V_289 -> V_2 [ V_290 ] -> V_307 ;
V_296 [ V_290 ] . V_243 = V_289 -> V_2 [ V_290 ] -> V_243 ;
}
}
F_79 ( & V_54 -> V_275 ) ;
if ( V_289 -> V_17 == 1 ) {
memcpy ( & V_296 [ 1 ] , & V_296 [ 0 ] , sizeof( struct V_295 ) ) ;
memcpy ( & V_296 [ 2 ] , & V_296 [ 0 ] , sizeof( struct V_295 ) ) ;
V_291 = F_99 ( V_25 , V_293 ,
V_294 , V_296 , 3 ) ;
} else {
V_291 = F_99 ( V_25 , V_293 ,
V_294 , NULL , 0 ) ;
}
F_81 ( & V_54 -> V_275 ) ;
if ( V_291 == false )
V_28 = - 1 ;
V_302:
if ( V_300 )
F_82 ( V_25 ) ;
return V_28 ;
}
static int F_100 ( struct V_52 * V_52 , T_2 V_318 )
{
F_8 ( L_6 , V_59 ) ;
return 0 ;
}
static int F_101 ( struct V_52 * V_52 , struct V_149 * V_201 ,
struct V_319 * V_206 )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return 0 ;
}
static int F_102 ( struct V_52 * V_52 , struct V_149 * V_201 )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return 0 ;
}
static int F_103 ( struct V_157 * V_158 ,
T_2 V_320 )
{
F_8 ( L_66 , V_59 , V_320 ) ;
if ( ! V_320 ) {
V_158 -> V_321 = V_322 ;
return 0 ;
}
if ( V_320 & ( V_323 | V_324 ) ) {
V_158 -> V_321 = V_325 ;
}
return 0 ;
}
static int F_104 ( struct V_157 * V_158 ,
enum V_326 V_327 )
{
F_8 ( L_67 , V_59 , V_327 ) ;
switch ( V_327 ) {
case V_328 :
V_158 -> V_187 = V_329 ;
break;
case V_330 :
V_158 -> V_187 = V_331 ;
if ( V_158 -> V_321 > V_332 )
V_158 -> V_187 =
V_188 ;
break;
case V_333 :
V_158 -> V_187 = V_334 ;
V_158 -> V_172 = V_173 ;
break;
default:
V_158 -> V_187 = V_331 ;
}
return 0 ;
}
static int F_105 ( struct V_157 * V_158 ,
T_2 V_209 , bool V_335 )
{
T_2 V_172 = V_336 ;
T_2 * V_337 = V_335 ? & V_158 -> V_174 :
& V_158 -> V_175 ;
F_8 ( L_68 , V_59 , V_335 , V_209 ) ;
if ( ! V_209 ) {
* V_337 = V_148 ;
V_158 -> V_172 = V_172 ;
return 0 ;
}
switch ( V_209 ) {
case V_213 :
* V_337 = V_148 ;
V_172 = V_336 ;
break;
case V_214 :
* V_337 = V_136 ;
V_172 = V_173 ;
break;
case V_215 :
* V_337 = V_137 ;
V_172 = V_173 ;
break;
case V_216 :
* V_337 = V_138 ;
V_172 = V_196 ;
break;
case V_217 :
* V_337 = V_140 ;
V_172 = V_197 ;
break;
default:
F_8 ( L_69 , V_209 ) ;
return - V_218 ;
}
if ( V_335 )
V_158 -> V_172 = V_172 ;
return 0 ;
}
static int F_106 ( struct V_157 * V_158 ,
T_2 V_338 )
{
F_8 ( L_70 , V_59 , V_338 ) ;
if ( V_338 == V_339 )
V_158 -> V_187 = V_188 ;
else if ( V_338 == V_340 )
V_158 -> V_187 = V_188 ;
else
F_8 ( L_71 , V_338 ) ;
return 0 ;
}
static int F_107 ( struct V_24 * V_25 , const V_22 * V_341 ,
T_4 V_342 )
{
V_22 * V_40 = NULL , * V_343 = NULL ;
int V_344 = 0 , V_345 = 0 ;
int V_28 = 0 ;
int V_346 = 0 ;
int V_347 = 0 ;
V_22 * V_348 , * V_349 ;
V_22 V_350 [] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_290 ;
if ( ! V_341 || ! V_342 ) {
F_108 ( & V_25 -> V_55 , V_351 ) ;
goto exit;
}
if ( V_342 > V_352 + V_353 + V_354 ) {
V_28 = - V_84 ;
goto exit;
}
V_40 = F_6 ( V_342 , V_21 ) ;
if ( V_40 == NULL ) {
V_28 = - V_355 ;
goto exit;
}
memcpy ( V_40 , V_341 , V_342 ) ;
F_8 ( L_72 , V_342 ) ;
for ( V_290 = 0 ; V_290 < V_342 ; V_290 = V_290 + 8 )
F_8 ( L_73 ,
V_40 [ V_290 ] , V_40 [ V_290 + 1 ] ,
V_40 [ V_290 + 2 ] , V_40 [ V_290 + 3 ] , V_40 [ V_290 + 4 ] ,
V_40 [ V_290 + 5 ] , V_40 [ V_290 + 6 ] , V_40 [ V_290 + 7 ] ) ;
V_343 = V_40 ;
if ( V_342 < V_356 ) {
F_54 ( V_192 , V_193 ,
( L_74 , ( int ) V_342 ) ) ;
V_28 = - 1 ;
goto exit;
}
V_348 = F_109 ( V_40 , & V_346 , V_342 ) ;
if ( V_348 && V_346 > 0 ) {
if ( F_110 ( V_348 , V_346 + 2 , & V_344 ,
& V_345 , NULL ) == V_119 ) {
V_25 -> V_159 . V_187 =
V_188 ;
V_25 -> V_159 . V_321 =
V_325 ;
memcpy ( V_25 -> V_159 . V_357 , & V_348 [ 0 ] ,
V_346 + 2 ) ;
F_8 ( L_75 , V_346 ) ;
}
}
V_349 = F_111 ( V_40 , & V_347 , V_342 ) ;
if ( V_349 && V_347 > 0 ) {
if ( F_112 ( V_349 , V_347 + 2 , & V_344 ,
& V_345 , NULL ) == V_119 ) {
V_25 -> V_159 . V_187 =
V_188 ;
V_25 -> V_159 . V_321 =
V_358 ;
memcpy ( V_25 -> V_159 . V_357 , & V_349 [ 0 ] ,
V_347 + 2 ) ;
F_8 ( L_76 , V_347 ) ;
}
}
if ( V_344 == 0 ) {
V_344 = V_359 ;
}
if ( V_345 == 0 ) {
V_345 = V_359 ;
}
switch ( V_344 ) {
case V_359 :
V_25 -> V_159 . V_175 = V_148 ;
V_25 -> V_159 . V_172 =
V_336 ;
break;
case V_360 :
V_25 -> V_159 . V_175 = V_136 ;
V_25 -> V_159 . V_172 =
V_173 ;
break;
case V_361 :
V_25 -> V_159 . V_175 = V_138 ;
V_25 -> V_159 . V_172 =
V_196 ;
break;
case V_362 :
V_25 -> V_159 . V_175 = V_140 ;
V_25 -> V_159 . V_172 =
V_197 ;
break;
case V_363 :
V_25 -> V_159 . V_175 = V_137 ;
V_25 -> V_159 . V_172 =
V_173 ;
break;
}
switch ( V_345 ) {
case V_359 :
V_25 -> V_159 . V_174 = V_148 ;
V_25 -> V_159 . V_172 =
V_336 ;
break;
case V_360 :
V_25 -> V_159 . V_174 = V_136 ;
V_25 -> V_159 . V_172 =
V_173 ;
break;
case V_361 :
V_25 -> V_159 . V_174 = V_138 ;
V_25 -> V_159 . V_172 =
V_196 ;
break;
case V_362 :
V_25 -> V_159 . V_174 = V_140 ;
V_25 -> V_159 . V_172 =
V_197 ;
break;
case V_363 :
V_25 -> V_159 . V_174 = V_137 ;
V_25 -> V_159 . V_172 =
V_173 ;
break;
}
{
T_6 V_277 ;
V_22 * V_278 ;
V_278 = F_89 ( V_40 , V_342 , NULL , & V_277 ) ;
if ( V_278 && V_277 > 0 ) {
F_8 ( L_77 , V_277 ) ;
V_25 -> V_159 . V_364 =
V_277 <
V_353 ? V_277 : V_353 ;
memcpy ( V_25 -> V_159 . V_278 , V_278 ,
V_25 -> V_159 . V_364 ) ;
F_113 ( & V_25 -> V_55 , V_351 ) ;
} else {
F_108 ( & V_25 -> V_55 , V_351 ) ;
}
}
#ifdef F_25
{
T_6 V_279 = 0 ;
V_22 * V_280 ;
struct V_53 * V_54 = & V_25 -> V_55 ;
V_280 = F_91 ( V_40 , V_342 , NULL , & V_279 ) ;
if ( V_280 ) {
#ifdef F_68
F_8 ( L_78 , V_59 ,
V_279 ) ;
#endif
if ( V_54 -> V_365 ) {
V_54 -> V_366 = 0 ;
F_40 ( V_54 -> V_365 ) ;
V_54 -> V_365 = NULL ;
}
V_54 -> V_365 =
F_90 ( V_279 , V_21 ) ;
if ( V_54 -> V_365 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
goto exit;
}
memcpy ( V_54 -> V_365 , V_280 , V_279 ) ;
V_54 -> V_366 = V_279 ;
}
}
#endif
#ifdef F_25
{
T_6 V_281 = 0 ;
struct V_53 * V_54 = & V_25 -> V_55 ;
if ( F_92 ( V_40 , V_342 , NULL , & V_281 ) ) {
#ifdef F_68
F_8 ( L_79 , V_59 ,
V_281 ) ;
#endif
if ( V_54 -> V_367 ) {
V_54 -> V_368 = 0 ;
F_40 ( V_54 -> V_367 ) ;
V_54 -> V_367 = NULL ;
}
V_54 -> V_367 =
F_90 ( V_281 , V_21 ) ;
if ( V_54 -> V_367 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
goto exit;
}
F_92 ( V_40 , V_342 , V_54 -> V_367 ,
& V_54 -> V_368 ) ;
}
}
#endif
if ( V_25 -> V_159 . V_174 == V_138 ||
V_25 -> V_159 . V_174 == V_139 ||
V_25 -> V_159 . V_174 == V_140 )
F_114 ( V_25 , V_369 , V_350 ) ;
F_54 ( V_192 , V_370 ,
( L_80
L_81
L_82 , V_345 ,
V_25 -> V_159 . V_172 ,
V_25 -> V_159 . V_321 ) ) ;
exit:
F_40 ( V_40 ) ;
if ( V_28 )
F_108 ( & V_25 -> V_55 , V_351 ) ;
return V_28 ;
}
static int F_115 ( struct V_52 * V_52 , struct V_149 * V_201 ,
struct V_371 * V_372 )
{
int V_28 = 0 ;
struct V_268 * V_270 , * V_269 , * V_271 ;
struct V_26 * V_27 = NULL ;
enum V_373 V_374 ;
struct V_292 V_375 ;
V_22 * V_376 ;
V_22 * V_377 ;
V_22 * V_378 ;
const V_22 * V_379 ;
V_22 V_380 = false ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_157 * V_158 = & V_25 -> V_159 ;
struct V_272 * V_273 = & V_54 -> V_274 ;
F_8 ( L_83 V_208 L_39 , F_61 ( V_201 ) ) ;
F_8 ( L_84 ,
V_372 -> V_381 , V_372 -> V_126 , V_372 -> V_167 , V_372 -> V_382 ) ;
if ( F_87 ( V_25 -> V_51 ) -> V_383 ) {
V_28 = - V_384 ;
F_8 ( L_85 , V_59 ) ;
goto exit;
}
if ( V_120 == F_74 ( V_25 ) ) {
V_28 = - V_252 ;
goto exit;
}
if ( F_15 ( V_54 , V_92 ) ) {
V_28 = - V_252 ;
goto exit;
}
if ( ! V_372 -> V_293 || ! V_372 -> V_317 ) {
V_28 = - V_84 ;
goto exit;
}
if ( V_372 -> V_317 > V_385 ) {
V_28 = - V_386 ;
goto exit;
}
memset ( & V_375 , 0 , sizeof( struct V_292 ) ) ;
V_375 . V_317 = V_372 -> V_317 ;
memcpy ( V_375 . V_293 , V_372 -> V_293 , V_372 -> V_317 ) ;
F_8 ( L_86 , V_375 . V_293 , V_372 -> V_317 ) ;
if ( V_372 -> V_387 )
F_8 ( L_87 V_230 L_39 , F_69 ( V_372 -> V_387 ) ) ;
if ( F_15 ( V_54 , V_311 ) ) {
V_28 = - V_384 ;
F_8 ( L_88 , V_59 ,
V_54 -> V_221 ) ;
goto exit;
}
if ( F_15 ( V_54 , V_310 ) ) {
F_116 ( V_25 ) ;
}
F_79 ( & V_273 -> V_275 ) ;
V_270 = F_83 ( V_273 ) ;
F_84 (plist, ptmp, phead) {
V_27 = F_85 ( V_269 , struct V_26 , V_147 ) ;
V_376 = V_27 -> V_56 . V_388 . V_293 ;
V_378 = V_27 -> V_56 . V_80 ;
if ( V_372 -> V_387 ) {
if ( memcmp ( V_27 -> V_56 . V_80 ,
V_372 -> V_387 , V_75 ) )
continue;
}
if ( V_372 -> V_293 && V_372 -> V_317 ) {
if ( V_27 -> V_56 . V_388 . V_317 != V_372 -> V_317 ||
memcmp ( V_27 -> V_56 . V_388 . V_293 , V_372 -> V_293 ,
V_372 -> V_317 ) )
continue;
}
if ( V_372 -> V_387 ) {
V_379 = V_372 -> V_387 ;
if ( ( ! memcmp ( V_378 , V_379 , V_75 ) ) ) {
F_8 ( L_89 ) ;
V_375 . V_317 =
V_27 -> V_56 . V_388 . V_317 ;
memcpy ( V_375 . V_293 ,
V_27 -> V_56 . V_388 . V_293 ,
V_27 -> V_56 . V_388 . V_317 ) ;
V_380 = true ;
break;
}
} else if ( V_372 -> V_293 && V_372 -> V_317 ) {
V_377 = V_375 . V_293 ;
if ( ( ! memcmp ( V_376 , V_377 , V_375 . V_317 ) ) &&
( V_27 -> V_56 . V_388 . V_317 ==
V_375 . V_317 ) ) {
F_8 ( L_90 ) ;
V_380 = true ;
break;
}
}
}
F_81 ( & V_273 -> V_275 ) ;
if ( ! V_380 || ( V_27 == NULL ) ) {
V_28 = - V_229 ;
F_8 ( L_91 ) ;
goto exit;
}
if ( F_76
( V_25 , V_27 -> V_56 . V_389 ) == false ) {
V_28 = - V_252 ;
goto exit;
}
V_158 -> V_172 = V_336 ;
V_158 -> V_174 = V_148 ;
V_158 -> V_175 = V_148 ;
V_158 -> V_187 = V_331 ;
V_158 -> V_321 = V_322 ;
V_28 =
F_103 ( V_158 ,
V_372 -> V_390 . V_391 ) ;
if ( V_28 < 0 )
goto exit;
V_28 = F_104 ( V_158 , V_372 -> V_392 ) ;
if ( V_28 < 0 )
goto exit;
F_8 ( L_92 , V_59 , V_372 -> V_304 ) ;
V_28 = F_107 ( V_25 , V_372 -> V_303 , V_372 -> V_304 ) ;
if ( V_28 < 0 )
goto exit;
if ( V_372 -> V_390 . V_393 ) {
V_28 = F_105 ( V_158 ,
V_372 -> V_390 . V_394 [ 0 ] ,
true ) ;
if ( V_28 < 0 )
goto exit;
}
if ( ( V_158 -> V_187 == V_334 ||
V_158 -> V_187 == V_329 ) &&
V_372 -> V_126 ) {
T_2 V_154 , V_155 , V_395 ;
struct V_396 * V_397 = NULL ;
F_8 ( L_93 , V_59 ) ;
V_154 = V_372 -> V_382 ;
V_155 = V_372 -> V_167 ;
if ( V_372 -> V_382 > V_170 ) {
V_28 = - V_84 ;
goto exit;
}
if ( V_155 > 0 ) {
V_155 = V_155 <= 5 ? 5 : 13 ;
V_395 =
V_155 +
F_117 ( struct V_396 , V_398 ) ;
V_397 = (struct V_396 * ) F_90 ( V_395 ,
V_21 ) ;
if ( V_397 == NULL ) {
F_8 ( L_94
L_95 ) ;
V_28 = - V_355 ;
goto exit;
}
memset ( V_397 , 0 , V_395 ) ;
V_397 -> V_399 = V_155 ;
V_397 -> V_400 = V_395 ;
if ( V_155 == 13 ) {
V_25 -> V_159 . V_174 =
V_137 ;
V_25 -> V_159 . V_175 =
V_137 ;
}
} else {
V_28 = - V_84 ;
goto exit;
}
V_397 -> V_401 = V_154 ;
V_397 -> V_401 |= 0x80000000 ;
memcpy ( V_397 -> V_398 , ( void * ) V_372 -> V_126 , V_397 -> V_399 ) ;
if ( F_118 ( V_25 , V_397 ) == ( V_22 ) V_120 ) {
V_28 = - V_262 ;
}
F_40 ( V_397 ) ;
if ( V_28 < 0 )
goto exit;
}
V_28 = F_105 ( V_158 ,
V_372 -> V_390 . V_402 , false ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_372 -> V_390 . V_403 ) {
V_28 = F_106 ( V_158 ,
V_372 -> V_390 . V_404 [ 0 ] ) ;
if ( V_28 < 0 )
goto exit;
}
V_374 = V_158 -> V_321 ;
F_119 ( V_25 , V_374 ) ;
if ( F_120 ( V_25 , & V_375 ) == false ) {
V_28 = - 1 ;
goto exit;
}
F_8 ( L_96
L_97 , V_158 -> V_187 ,
V_158 -> V_174 ,
V_158 -> V_175 ) ;
exit:
F_8 ( L_98 , V_59 , V_28 ) ;
return V_28 ;
}
static int F_121 ( struct V_52 * V_52 , struct V_149 * V_201 ,
T_1 V_405 )
{
struct V_24 * V_25 = F_60 ( V_52 ) ;
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
F_122 ( V_25 , 0 ) ;
if ( F_15 ( & V_25 -> V_55 , V_66 ) ) {
F_116 ( V_25 ) ;
F_123 ( V_25 ) ;
F_124 ( V_25 , 500 , false ) ;
F_8 ( L_99 , V_59 ) ;
V_25 -> V_55 . V_106 = true ;
F_125 ( V_25 ) ;
V_25 -> V_55 . V_106 = false ;
F_126 ( V_25 , 1 ) ;
}
return 0 ;
}
static int F_127 ( struct V_52 * V_52 ,
struct V_49 * V_50 ,
enum V_406 type , int V_407 )
{
F_8 ( L_6 , V_59 ) ;
return 0 ;
}
static int F_128 ( struct V_52 * V_52 ,
struct V_49 * V_50 , int * V_408 )
{
F_8 ( L_6 , V_59 ) ;
* V_408 = ( 12 ) ;
return 0 ;
}
inline bool F_129 ( struct V_24 * V_409 )
{
struct V_263 * V_263 = F_87 ( V_409 -> V_51 ) ;
return V_263 -> V_410 ;
}
static int F_130 ( struct V_52 * V_52 ,
struct V_149 * V_201 ,
bool V_411 , int V_412 )
{
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_263 * V_263 = F_87 ( V_25 -> V_51 ) ;
F_8 ( V_208 L_100 ,
F_61 ( V_201 ) , V_411 , V_412 ) ;
V_263 -> V_410 = V_411 ;
if ( ! V_411 )
F_131 ( V_25 ) ;
return 0 ;
}
static int F_132 ( struct V_52 * V_52 ,
struct V_149 * V_413 ,
struct V_414 * V_415 )
{
V_22 V_416 , V_417 = false ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_157 * V_158 = & V_25 -> V_159 ;
V_22 V_418 [ V_75 ] = { 0x00 } ;
F_8 ( V_208 L_39 , F_61 ( V_413 ) ) ;
if ( ! memcmp ( V_415 -> V_387 , V_418 , V_75 ) ) {
return - V_84 ;
}
V_417 = false ;
for ( V_416 = 0 ; V_416 < V_419 ; V_416 ++ ) {
if ( ! memcmp ( V_158 -> V_420 [ V_416 ] . V_421 ,
V_415 -> V_387 , V_75 ) ) {
F_8 ( V_208
L_101 ,
F_61 ( V_413 ) ) ;
memcpy ( V_158 -> V_420 [ V_416 ] . V_422 ,
V_415 -> V_423 , V_424 ) ;
V_158 -> V_420 [ V_416 ] . V_425 = true ;
V_158 -> V_426 = V_416 + 1 ;
V_417 = true ;
break;
}
}
if ( ! V_417 ) {
F_8 ( V_208
L_102 ,
F_61 ( V_413 ) , V_158 -> V_426 ) ;
memcpy ( V_158 -> V_420 [ V_158 -> V_426 ] .
V_421 , V_415 -> V_387 , V_75 ) ;
memcpy ( V_158 -> V_420 [ V_158 -> V_426 ] .
V_422 , V_415 -> V_423 , V_424 ) ;
V_158 -> V_420 [ V_158 -> V_426 ] . V_425 =
true ;
V_158 -> V_426 ++ ;
if ( V_158 -> V_426 == 16 ) {
V_158 -> V_426 = 0 ;
}
}
return 0 ;
}
static int F_133 ( struct V_52 * V_52 ,
struct V_149 * V_413 ,
struct V_414 * V_415 )
{
V_22 V_416 , V_427 = false ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_157 * V_158 = & V_25 -> V_159 ;
F_8 ( V_208 L_39 , F_61 ( V_413 ) ) ;
for ( V_416 = 0 ; V_416 < V_419 ; V_416 ++ ) {
if ( ! memcmp ( V_158 -> V_420 [ V_416 ] . V_421 ,
V_415 -> V_387 , V_75 ) ) {
memset ( V_158 -> V_420 [ V_416 ] . V_421 , 0x00 ,
V_75 ) ;
memset ( V_158 -> V_420 [ V_416 ] . V_422 , 0x00 ,
V_424 ) ;
V_158 -> V_420 [ V_416 ] . V_425 = false ;
V_427 = true ;
break;
}
}
if ( false == V_427 ) {
F_8 ( V_208 L_103 ,
F_61 ( V_413 ) ) ;
return - V_84 ;
}
return 0 ;
}
static int F_134 ( struct V_52 * V_52 ,
struct V_149 * V_413 )
{
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_157 * V_158 = & V_25 -> V_159 ;
F_8 ( V_208 L_39 , F_61 ( V_413 ) ) ;
memset ( & V_158 -> V_420 [ 0 ] , 0x00 ,
sizeof( struct V_428 ) * V_419 ) ;
V_158 -> V_426 = 0 ;
return 0 ;
}
void F_135 ( struct V_24 * V_25 ,
V_22 * V_429 , T_6 V_430 )
{
T_5 V_33 ;
int V_32 ;
struct V_248 * V_249 = & V_25 -> V_250 ;
struct V_149 * V_201 = V_25 -> V_96 ;
F_8 ( L_104 , V_59 , V_25 , V_201 -> V_431 ) ;
#if F_136 ( V_432 )
{
struct V_226 V_227 ;
V_22 V_433 ;
if ( F_137 ( V_434 -> V_72 ) )
V_433 = V_435 ;
else
V_433 = V_436 ;
V_227 . V_228 = 0 ;
V_227 . V_228 = V_437 ;
V_227 . V_438 = V_429 + V_439 + V_433 ;
V_227 . V_440 =
V_430 - V_439 - V_433 ;
F_138 ( V_201 , V_434 -> V_79 , & V_227 , V_83 ) ;
}
#else
V_32 = V_249 -> V_441 ;
if ( V_32 <= V_62 )
V_33 = F_9 ( V_32 ,
V_19 ) ;
else
V_33 = F_9 ( V_32 ,
V_20 ) ;
F_139 ( V_25 , V_33 , 0 , V_429 , V_430 ,
V_83 ) ;
#endif
}
void F_140 ( struct V_24 * V_25 ,
unsigned char * V_442 ,
unsigned short V_443 )
{
T_5 V_33 ;
int V_32 ;
V_22 * V_429 ;
T_6 V_430 ;
struct V_45 * V_46 ;
unsigned short * V_47 ;
V_22 V_444 [ 128 ] = { 0 } ;
struct V_248 * V_249 = & V_25 -> V_250 ;
struct V_445 * V_446 = & V_249 -> V_447 ;
struct V_149 * V_201 = V_25 -> V_96 ;
F_8 ( L_104 , V_59 , V_25 , V_201 -> V_431 ) ;
#if F_136 ( V_432 )
F_141 ( V_201 , V_442 , V_83 ) ;
#else
V_32 = V_249 -> V_441 ;
if ( V_32 <= V_62 )
V_33 = F_9 ( V_32 ,
V_19 ) ;
else
V_33 = F_9 ( V_32 ,
V_20 ) ;
V_429 = V_444 ;
V_46 = (struct V_45 * ) V_429 ;
V_47 = & V_46 -> V_72 ;
* ( V_47 ) = 0 ;
memcpy ( V_46 -> V_74 , F_20 ( & V_25 -> V_77 ) , V_75 ) ;
memcpy ( V_46 -> V_79 , V_442 , V_75 ) ;
memcpy ( V_46 -> V_81 , F_142 ( & V_446 -> V_56 ) , V_75 ) ;
F_18 ( V_46 , V_249 -> V_448 ) ;
V_249 -> V_448 ++ ;
F_19 ( V_429 , V_449 ) ;
V_429 += sizeof( struct V_58 ) ;
V_430 = sizeof( struct V_58 ) ;
V_443 = F_143 ( V_443 ) ;
V_429 = F_144 ( V_429 ,
V_450 ,
( unsigned char * ) & V_443 , & V_430 ) ;
F_139 ( V_25 , V_33 , 0 , V_444 , V_430 ,
V_83 ) ;
#endif
}
static int F_145 ( struct V_149 * V_201 )
{
int V_28 = 0 ;
F_8 ( L_6 , V_59 ) ;
return V_28 ;
}
static int F_146 ( struct V_149 * V_201 )
{
int V_28 = 0 ;
F_8 ( L_6 , V_59 ) ;
return V_28 ;
}
static int F_147 ( struct V_451 * V_452 ,
struct V_149 * V_201 )
{
int V_28 = 0 ;
int V_453 ;
int V_454 = 0 ;
int V_455 = 24 ;
int V_456 = 6 ;
unsigned char * V_457 ;
unsigned char V_458 [ 6 ] ;
unsigned char V_459 [ 6 ] ;
struct V_45 * V_460 ;
struct V_461 * V_462 ;
struct V_24 * V_25 = F_49 ( V_201 ) ;
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
if ( F_22 ( V_452 -> V_43 < sizeof( struct V_461 ) ) )
goto V_463;
V_462 = (struct V_461 * ) V_452 -> V_464 ;
if ( F_22 ( V_462 -> V_465 ) )
goto V_463;
V_453 = F_148 ( V_452 -> V_464 ) ;
if ( F_22 ( V_452 -> V_43 < V_453 ) )
goto V_463;
if ( V_453 != 14 ) {
F_8 ( L_105 , V_453 ) ;
goto V_463;
}
F_149 ( V_452 , V_453 ) ;
V_460 = (struct V_45 * ) V_452 -> V_464 ;
if ( F_150 ( V_460 -> V_72 ) ) {
if ( F_151 ( V_460 -> V_72 ) )
V_454 = V_466 ;
if ( F_152 ( V_460 -> V_72 ) )
V_455 += 6 ;
memcpy ( V_459 , V_460 -> V_74 , sizeof( V_459 ) ) ;
memcpy ( V_458 , V_460 -> V_79 , sizeof( V_458 ) ) ;
F_149 ( V_452 , V_455 + V_454 + V_456 -
V_75 * 2 ) ;
V_457 = ( unsigned char * ) V_452 -> V_464 ;
memcpy ( V_457 , V_459 , V_75 ) ;
memcpy ( V_457 + V_75 , V_458 , V_75 ) ;
F_8 ( L_106 ) ;
V_28 = F_153 ( V_452 , V_25 -> V_96 ) ;
return V_28 ;
} else if ( F_154 ( V_460 -> V_72 ) ) {
struct V_467 * V_468 ;
struct V_469 * V_470 ;
unsigned char * V_471 ;
struct V_472 * V_473 = & V_25 -> V_474 ;
struct V_248 * V_249 = & V_25 -> V_250 ;
T_2 V_43 = V_452 -> V_43 ;
V_22 V_475 , V_476 ;
#ifdef F_25
int type = - 1 ;
#endif
if ( F_155 ( V_452 -> V_464 , V_43 , & V_475 ,
& V_476 ) == false ) {
F_8 ( V_208 L_107 ,
F_61 ( V_201 ) ,
F_12 ( V_460 -> V_72 ) ) ;
goto V_463;
}
F_8 ( L_108 V_230 L_109 V_208 L_39 ,
F_69 ( V_460 -> V_74 ) , F_61 ( V_201 ) ) ;
#ifdef F_25
type = F_156 ( V_25 , V_452 -> V_464 , V_43 , true ) ;
if ( type >= 0 )
goto V_477;
#endif
if ( V_475 == V_478 )
F_8 ( L_110 , F_157 ( V_476 ) ) ;
else
F_8 ( L_111 , V_475 ,
V_476 ) ;
#ifdef F_25
V_477:
#endif
V_468 = F_158 ( V_473 ) ;
if ( V_468 == NULL )
goto V_463;
V_470 = & V_468 -> V_479 ;
F_159 ( V_25 , V_470 ) ;
V_470 -> V_480 = false ;
memset ( V_468 -> V_481 , 0 , V_482 + V_483 ) ;
V_471 = ( V_22 * ) ( V_468 -> V_481 ) + V_483 ;
memcpy ( V_471 , V_452 -> V_464 , V_43 ) ;
#ifdef F_25
if ( type >= 0 ) {
struct V_484 * V_485 ;
V_485 = V_25 -> V_88 . V_486 ;
if ( V_485 -> V_487 )
F_160 ( V_25 , V_471 , & V_43 ) ;
}
#endif
V_470 -> V_488 = V_43 ;
V_249 -> V_448 = F_12 ( V_460 -> V_489 ) >> 4 ;
V_470 -> V_490 = V_249 -> V_448 ;
V_249 -> V_448 ++ ;
V_470 -> V_491 = V_470 -> V_488 ;
F_161 ( V_25 , V_468 ) ;
}
V_463:
F_162 ( V_452 ) ;
return 0 ;
}
static int
F_163 ( struct V_149 * V_201 , void * V_124 )
{
int V_28 = 0 ;
F_8 ( L_6 , V_59 ) ;
return V_28 ;
}
static int F_164 ( struct V_24 * V_25 , char * V_431 ,
struct V_149 * * V_201 )
{
int V_28 = 0 ;
struct V_149 * V_492 = NULL ;
struct V_49 * V_493 = NULL ;
struct V_263 * V_264 = F_87 ( V_25 -> V_51 ) ;
if ( ! V_431 ) {
F_8 ( V_301 L_112 ,
F_94 ( V_25 ) ) ;
V_28 = - V_84 ;
goto V_494;
}
if ( V_264 -> V_495 ) {
F_8 ( V_301 L_113 V_496
L_39 , F_94 ( V_25 ) ,
F_165 ( V_264 -> V_495 ) ) ;
V_28 = - V_384 ;
goto V_494;
}
V_492 = F_166 ( sizeof( struct V_24 ) ) ;
if ( ! V_492 ) {
F_8 ( V_301 L_114 ,
F_94 ( V_25 ) ) ;
V_28 = - V_355 ;
goto V_494;
}
V_492 -> type = V_497 ;
strncpy ( V_492 -> V_431 , V_431 , V_498 ) ;
V_492 -> V_431 [ V_498 - 1 ] = 0 ;
V_492 -> V_499 = V_500 ;
V_492 -> V_501 = & V_502 ;
V_493 = F_6 ( sizeof( struct V_49 ) , V_21 ) ;
if ( ! V_493 ) {
F_8 ( V_301 L_115 ,
F_94 ( V_25 ) ) ;
V_28 = - V_355 ;
goto V_494;
}
V_493 -> V_52 = V_25 -> V_51 -> V_52 ;
V_493 -> V_413 = V_492 ;
V_493 -> V_89 = V_503 ;
V_492 -> V_504 = V_493 ;
V_28 = F_167 ( V_492 ) ;
if ( V_28 ) {
goto V_494;
}
* V_201 = V_264 -> V_495 = V_492 ;
memcpy ( V_264 -> V_505 , V_431 , V_498 + 1 ) ;
V_494:
if ( V_28 ) {
F_40 ( V_493 ) ;
V_493 = NULL ;
}
if ( V_28 && V_492 ) {
F_168 ( V_492 ) ;
* V_201 = V_492 = NULL ;
}
return V_28 ;
}
static struct V_49 *
F_169 ( struct V_52 * V_52 , const char * V_431 ,
enum V_242 type , T_2 * V_243 ,
struct V_244 * V_206 )
{
int V_28 = 0 ;
struct V_149 * V_201 = NULL ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
F_8 ( V_301 L_116 ,
F_94 ( V_25 ) , F_170 ( V_52 ) , V_431 , type ) ;
switch ( type ) {
case V_255 :
case V_506 :
case V_507 :
case V_508 :
V_28 = - V_509 ;
break;
case V_503 :
V_28 =
F_164 ( V_25 , ( char * ) V_431 , & V_201 ) ;
break;
case V_91 :
case V_90 :
V_28 = - V_509 ;
break;
case V_259 :
case V_260 :
V_28 = - V_509 ;
break;
default:
V_28 = - V_509 ;
F_8 ( L_117 ) ;
break;
}
F_8 ( V_301 L_118 , F_94 ( V_25 ) ,
V_201 , V_28 ) ;
return V_201 ? V_201 -> V_504 : F_171 ( V_28 ) ;
}
static int F_172 ( struct V_52 * V_52 ,
struct V_49 * V_50 )
{
struct V_263 * V_264 =
(struct V_263 * ) F_173 ( V_52 ) ;
struct V_149 * V_201 ;
V_201 = V_50 ? V_50 -> V_413 : NULL ;
if ( ! V_201 )
goto exit;
F_174 ( V_201 ) ;
if ( V_201 == V_264 -> V_495 ) {
V_264 -> V_495 = NULL ;
V_264 -> V_505 [ 0 ] = '\0' ;
F_8 ( V_208 L_119 ,
F_61 ( V_201 ) ) ;
}
exit:
return 0 ;
}
static int F_175 ( struct V_24 * V_409 , const V_22 * V_510 ,
T_4 V_511 , const V_22 * V_512 , T_4 V_513 )
{
int V_28 = 0 ;
V_22 * V_42 = NULL ;
T_6 V_43 , V_277 = 0 ;
#ifdef F_25
T_6 V_279 = 0 ;
V_22 V_514 = false ;
#endif
struct V_53 * V_54 = & V_409 -> V_55 ;
F_8 ( L_120 ,
V_59 , V_511 , V_513 ) ;
if ( F_15 ( V_54 , V_92 ) != true )
return - V_84 ;
if ( V_511 < 24 )
return - V_84 ;
V_42 = F_6 ( V_511 + V_513 , V_21 ) ;
if ( ! V_42 )
return - V_355 ;
memcpy ( V_42 , ( void * ) V_510 + 24 , V_511 - 24 ) ;
memcpy ( V_42 + V_511 - 24 , ( void * ) V_512 , V_513 ) ;
V_43 = V_511 + V_513 - 24 ;
if ( F_89
( V_42 + V_65 , V_43 - V_65 , NULL ,
& V_277 ) )
F_8 ( L_121 , V_277 ) ;
#ifdef F_25
if ( F_91
( V_42 + V_65 , V_43 - V_65 , NULL ,
& V_279 ) ) {
F_8 ( L_122 , V_279 ) ;
V_514 = true ;
}
#endif
F_176 ( V_42 , & V_43 , V_515 , V_516 ,
V_517 , 4 ) ;
F_176 ( V_42 , & V_43 , V_515 , V_516 ,
V_518 , 4 ) ;
if ( F_177 ( V_409 , V_42 , V_43 ) == V_119 ) {
#ifdef F_25
if ( V_514 == true ) {
struct V_248 * V_249 = & V_409 -> V_250 ;
struct V_86 * V_87 = & V_409 -> V_88 ;
if ( F_26 ( V_87 , V_93 ) ) {
F_8 ( L_123
L_124 ) ;
F_95 ( V_409 , V_258 ) ;
F_87 ( V_409 -> V_51 ) -> V_305 =
true ;
} else {
F_37 ( & V_87 -> V_102 ) ;
F_37 ( & V_87 ->
V_103 ) ;
F_37 ( & V_87 -> V_104 ) ;
F_8 ( L_125 ,
V_279 ) ;
F_29 ( V_87 , V_258 ) ;
F_30 ( V_87 , V_95 ) ;
V_87 -> V_519 = 15 ;
}
V_87 -> V_520 = V_249 -> V_441 ;
}
#endif
V_28 = 0 ;
} else {
V_28 = - V_84 ;
}
F_40 ( V_42 ) ;
return V_28 ;
}
static int F_178 ( struct V_52 * V_52 , struct V_149 * V_201 ,
struct V_521 * V_522 )
{
int V_28 = 0 ;
struct V_24 * V_409 = F_60 ( V_52 ) ;
F_8 ( V_208 L_126 ,
F_61 ( V_201 ) , V_522 -> V_523 ,
V_522 -> V_392 ) ;
V_28 = F_175 ( V_409 , V_522 -> V_524 . V_510 ,
V_522 -> V_524 . V_511 , V_522 -> V_524 . V_512 ,
V_522 -> V_524 . V_513 ) ;
V_409 -> V_250 . V_447 . V_525 =
V_522 -> V_523 ;
if ( V_522 -> V_293 && V_522 -> V_317 ) {
struct V_526 * V_527 =
& V_409 -> V_55 . V_67 . V_56 ;
struct V_526 * V_528 =
& V_409 -> V_250 . V_447 . V_56 ;
if ( 0 )
F_8 ( V_301
L_127 ,
F_94 ( V_409 ) , V_522 -> V_293 ,
( int ) V_522 -> V_317 ,
V_527 -> V_388 . V_293 ,
V_527 -> V_388 . V_317 ) ;
memcpy ( V_527 -> V_388 . V_293 , ( void * ) V_522 -> V_293 ,
V_522 -> V_317 ) ;
V_527 -> V_388 . V_317 = V_522 -> V_317 ;
memcpy ( V_528 -> V_388 . V_293 , ( void * ) V_522 -> V_293 ,
V_522 -> V_317 ) ;
V_528 -> V_388 . V_317 = V_522 -> V_317 ;
if ( 0 )
F_8 ( V_301
L_128 ,
F_94 ( V_409 ) ,
V_527 -> V_388 . V_293 ,
V_527 -> V_388 . V_317 ,
V_528 -> V_388 . V_293 ,
V_528 -> V_388 . V_317 ) ;
}
return V_28 ;
}
static int F_179 ( struct V_52 * V_52 ,
struct V_149 * V_201 ,
struct V_529 * V_530 )
{
int V_28 = 0 ;
struct V_24 * V_409 = F_60 ( V_52 ) ;
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
V_28 = F_175 ( V_409 , V_530 -> V_510 , V_530 -> V_511 , V_530 -> V_512 ,
V_530 -> V_513 ) ;
return V_28 ;
}
static int F_180 ( struct V_52 * V_52 , struct V_149 * V_201 )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return 0 ;
}
static int F_181 ( struct V_52 * V_52 ,
struct V_149 * V_201 , V_22 * V_225 ,
struct V_531 * V_206 )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return 0 ;
}
static int F_182 ( struct V_52 * V_52 ,
struct V_149 * V_201 , V_22 * V_225 )
{
int V_28 = 0 ;
struct V_268 * V_270 , * V_269 , * V_271 ;
V_22 V_532 = 0 ;
struct V_109 * V_110 ;
struct V_24 * V_25 = F_49 ( V_201 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_160 * V_161 = & V_25 -> V_162 ;
F_8 ( L_129 V_208 L_39 , F_61 ( V_201 ) ) ;
if ( F_15 ( V_54 , ( V_66 | V_92 ) ) != true ) {
F_8 ( L_130 ,
V_59 ) ;
return - V_84 ;
}
if ( ! V_225 ) {
F_8 ( L_131 ) ;
F_183 ( V_25 ) ;
V_28 = F_184 ( V_25 ) ;
return V_28 ;
}
F_8 ( L_132 V_230 L_39 , F_69 ( V_225 ) ) ;
if ( F_50 ( V_225 ) )
return - V_84 ;
F_79 ( & V_161 -> V_533 ) ;
V_270 = & V_161 -> V_534 ;
F_84 (plist, ptmp, phead) {
V_110 = F_85 ( V_269 , struct V_109 , V_534 ) ;
if ( ! memcmp ( V_225 , V_110 -> V_125 , V_75 ) ) {
if ( V_110 -> V_535 == 1 &&
V_110 -> V_191 == false ) {
F_8 ( L_133
L_134 , V_59 ) ;
} else {
F_8 ( L_135 , V_110 ,
V_110 -> V_536 ) ;
F_185 ( & V_110 -> V_534 ) ;
V_161 -> V_537 -- ;
V_532 =
F_186 ( V_25 , V_110 , true ,
V_538 ) ;
V_110 = NULL ;
break;
}
}
}
F_81 ( & V_161 -> V_533 ) ;
F_187 ( V_25 , V_532 ) ;
F_8 ( L_136 V_208 L_39 , F_61 ( V_201 ) ) ;
return V_28 ;
}
static int F_188 ( struct V_52 * V_52 ,
struct V_149 * V_201 , V_22 * V_225 ,
struct V_531 * V_206 )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return 0 ;
}
static int F_189 ( struct V_52 * V_52 ,
struct V_149 * V_201 , int V_169 , V_22 * V_225 ,
struct V_226 * V_227 )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return - V_229 ;
}
static int F_190 ( struct V_52 * V_52 , struct V_149 * V_201 ,
struct V_539 * V_206 )
{
F_8 ( V_208 L_39 , F_61 ( V_201 ) ) ;
return 0 ;
}
void F_191 ( struct V_24 * V_25 , V_22 * V_429 ,
T_6 V_430 )
{
#ifdef F_25
int type ;
#endif
T_5 V_33 ;
int V_32 ;
V_22 V_475 , V_476 ;
V_32 = F_192 ( V_25 ) ;
F_8 ( L_137 , V_32 ) ;
#ifdef F_25
type = F_156 ( V_25 , V_429 , V_430 , false ) ;
if ( type >= 0 )
goto V_540;
#endif
F_155 ( V_429 , V_430 , & V_475 , & V_476 ) ;
F_8 ( L_138 , V_475 , V_476 ) ;
#ifdef F_25
V_540:
#endif
if ( V_32 <= V_62 )
V_33 = F_9 ( V_32 ,
V_19 ) ;
else
V_33 = F_9 ( V_32 ,
V_20 ) ;
F_139 ( V_25 , V_33 , 0 , V_429 , V_430 ,
V_83 ) ;
}
void F_193 ( struct V_24 * V_25 ,
V_22 * V_429 , T_6 V_430 )
{
#ifdef F_25
int type ;
#endif
T_5 V_33 ;
int V_32 ;
V_22 V_475 , V_476 ;
V_32 = F_192 ( V_25 ) ;
F_8 ( L_137 , V_32 ) ;
#ifdef F_25
type = F_156 ( V_25 , V_429 , V_430 , false ) ;
if ( type >= 0 ) {
switch ( type ) {
case V_541 :
case V_542 :
F_194 ( V_25 ) ;
}
goto V_540;
}
#endif
F_155 ( V_429 , V_430 , & V_475 , & V_476 ) ;
F_8 ( L_138 , V_475 , V_476 ) ;
#ifdef F_25
V_540:
#endif
if ( V_32 <= V_62 )
V_33 = F_9 ( V_32 ,
V_19 ) ;
else
V_33 = F_9 ( V_32 ,
V_20 ) ;
F_139 ( V_25 , V_33 , 0 , V_429 , V_430 ,
V_83 ) ;
}
void F_195 ( struct V_24 * V_409 , V_22 * V_543 ,
T_6 V_430 , const char * V_544 )
{
T_5 V_33 ;
int V_32 ;
V_22 V_475 , V_476 ;
V_32 = F_192 ( V_409 ) ;
F_155 ( V_543 , V_430 , & V_475 , & V_476 ) ;
F_8 ( L_137 , V_32 ) ;
if ( V_544 )
F_8 ( L_139 , V_544 ) ;
else
F_8 ( L_138 , V_475 ,
V_476 ) ;
if ( V_32 <= V_62 )
V_33 = F_9 ( V_32 ,
V_19 ) ;
else
V_33 = F_9 ( V_32 ,
V_20 ) ;
F_139 ( V_409 , V_33 , 0 , V_543 , V_430 , V_83 ) ;
}
void F_196 ( struct V_24 * V_25 ,
const V_22 * V_40 , T_4 V_43 )
{
T_1 V_545 = 0x0000 ;
T_6 V_546 = 0 ;
V_22 V_547 [ 255 ] = { 0x00 } , V_280 [ 255 ] = { 0x00 } ;
T_6 V_279 = 0 ;
T_6 V_548 = 0 ;
T_2 V_549 = 0 ;
V_22 V_550 [ 64 ] = { 0x00 } ;
T_1 V_551 = 0 ;
T_6 V_552 = 0 ;
unsigned char V_475 = V_478 ;
V_22 V_476 = V_553 ;
V_22 V_554 = 1 ;
T_2 V_555 = F_197 ( V_556 ) ;
V_22 V_557 = V_558 ;
T_2 V_559 = 0 ;
#ifdef F_25
T_2 V_560 = 0 ;
#endif
struct V_467 * V_468 ;
struct V_469 * V_470 ;
unsigned char * V_471 ;
struct V_45 * V_46 , * V_434 ;
struct V_472 * V_473 = & V_25 -> V_474 ;
struct V_248 * V_249 = & V_25 -> V_250 ;
struct V_86 * V_87 = & V_25 -> V_88 ;
V_22 * V_561 =
( unsigned char * ) ( V_40 + sizeof( struct V_58 ) ) ;
T_4 V_562 = V_43 - sizeof( struct V_58 ) ;
F_8 ( L_140 , V_59 ) ;
V_434 = (struct V_45 * ) V_40 ;
memcpy ( V_87 -> V_563 . V_564 , V_434 -> V_74 , V_75 ) ;
memcpy ( V_87 -> V_563 . V_565 , V_434 -> V_74 , V_75 ) ;
V_87 -> V_563 . V_566 =
V_567 ;
F_89 ( V_561 + V_568 ,
V_562 - V_568 , V_547 ,
& V_548 ) ;
F_198 ( V_547 , V_548 , V_569 ,
( V_22 * ) & V_545 ,
& V_546 ) ;
V_545 = F_199 ( V_545 ) ;
switch ( V_545 ) {
case V_570 :
V_87 -> V_563 . V_566 =
V_571 ;
break;
case V_572 :
V_87 -> V_563 . V_566 =
V_573 ;
break;
case V_574 :
break;
case V_575 :
break;
case V_576 :
V_87 -> V_563 . V_566 =
V_567 ;
break;
case V_577 :
V_87 -> V_563 . V_566 =
V_578 ;
break;
default:
break;
}
if ( F_91 ( V_561 + V_568 ,
V_562 - V_568 ,
V_280 , & V_279 ) ) {
F_200 ( V_280 , V_279 ,
V_579 , V_550 ,
& V_549 ) ;
F_200 ( V_280 , V_279 , V_580 ,
( V_22 * ) & V_551 , & V_552 ) ;
}
memset ( V_547 , 0 , sizeof( V_547 ) ) ;
memset ( V_280 , 0 , sizeof( V_280 ) ) ;
V_279 = 0 ;
V_468 = F_158 ( V_473 ) ;
if ( V_468 == NULL )
return;
V_470 = & V_468 -> V_479 ;
F_159 ( V_25 , V_470 ) ;
memset ( V_468 -> V_481 , 0 , V_482 + V_483 ) ;
V_471 = ( V_22 * ) ( V_468 -> V_481 ) + V_483 ;
V_46 = (struct V_45 * ) V_471 ;
V_46 -> V_72 = 0 ;
memcpy ( V_46 -> V_74 , V_87 -> V_563 . V_565 ,
V_75 ) ;
memcpy ( V_46 -> V_79 , F_20 ( & V_25 -> V_77 ) , V_75 ) ;
memcpy ( V_46 -> V_81 , V_87 -> V_563 . V_565 ,
V_75 ) ;
F_18 ( V_46 , V_249 -> V_448 ) ;
V_249 -> V_448 ++ ;
F_19 ( V_471 , V_581 ) ;
V_471 += sizeof( struct V_58 ) ;
V_470 -> V_488 = sizeof( struct V_58 ) ;
V_471 = F_144 ( V_471 , 1 , & V_475 , & V_470 -> V_488 ) ;
V_471 = F_144 ( V_471 , 1 , & V_476 , & V_470 -> V_488 ) ;
V_471 = F_144 ( V_471 , 4 , ( unsigned char * ) & V_555 ,
& V_470 -> V_488 ) ;
V_471 = F_144 ( V_471 , 1 , & V_557 , & V_470 -> V_488 ) ;
V_471 = F_144 ( V_471 , 1 , & V_554 , & V_470 -> V_488 ) ;
V_559 = 0 ;
V_280 [ V_559 ++ ] = 0x50 ;
V_280 [ V_559 ++ ] = 0x6F ;
V_280 [ V_559 ++ ] = 0x9A ;
V_280 [ V_559 ++ ] = 0x09 ;
V_280 [ V_559 ++ ] = V_580 ;
F_201 ( 0x0002 , V_280 + V_559 ) ;
V_559 += 2 ;
memcpy ( V_280 + V_559 , & V_551 , 2 ) ;
V_559 += 2 ;
V_280 [ V_559 ++ ] = V_579 ;
F_201 ( V_549 , V_280 + V_559 ) ;
V_559 += 2 ;
memcpy ( V_280 + V_559 , V_550 , V_549 ) ;
V_559 += V_549 ;
V_471 = F_202 ( V_471 , V_516 , V_559 ,
( unsigned char * ) V_280 , & V_279 ) ;
V_470 -> V_488 += V_279 ;
V_548 = 0 ;
* ( T_2 * ) ( V_547 ) = F_197 ( V_582 ) ;
V_548 += 4 ;
* ( T_1 * ) ( V_547 + V_548 ) = F_203 ( V_583 ) ;
V_548 += 2 ;
* ( T_1 * ) ( V_547 + V_548 ) = F_203 ( 0x0001 ) ;
V_548 += 2 ;
V_547 [ V_548 ++ ] = V_584 ;
* ( T_1 * ) ( V_547 + V_548 ) = F_203 ( V_585 ) ;
V_548 += 2 ;
* ( T_1 * ) ( V_547 + V_548 ) = F_203 ( 0x0002 ) ;
V_548 += 2 ;
* ( T_1 * ) ( V_547 + V_548 ) =
F_203 ( V_87 -> V_563 . V_566 ) ;
V_548 += 2 ;
V_471 = F_202 ( V_471 , V_516 , V_548 ,
( unsigned char * ) V_547 , & V_470 -> V_488 ) ;
#ifdef F_25
V_560 = F_204 ( V_87 , V_471 ) ;
V_471 += V_560 ;
V_470 -> V_488 += V_560 ;
#endif
V_470 -> V_491 = V_470 -> V_488 ;
if ( F_205 ( V_25 , V_468 ) != V_119 )
F_8 ( L_141 , V_59 ) ;
}
static T_5 F_206 ( struct V_52 * V_52 ,
struct V_49 * V_50 ,
struct V_1 * V_32 ,
unsigned int V_586 , T_3 * V_222 )
{
T_5 V_165 = 0 ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_248 * V_249 = & V_25 -> V_250 ;
struct V_86 * V_87 = & V_25 -> V_88 ;
struct V_587 * V_588 =
& V_25 -> V_589 ;
V_22 V_590 =
( V_22 ) F_207 ( V_32 -> V_591 ) ;
V_22 V_592 = false ;
F_8 ( V_301 L_142 , F_94 ( V_25 ) ,
V_590 , V_586 ) ;
if ( V_588 -> V_593 == true ) {
F_8 ( L_143 , V_59 ) ;
F_37 ( & V_25 -> V_589 . V_594 ) ;
#ifdef F_25
F_208 ( V_25 , V_595 ) ;
#endif
}
V_588 -> V_593 = true ;
if ( V_120 == F_74 ( V_25 ) ) {
V_165 = - V_596 ;
goto exit;
}
memcpy ( & V_588 -> V_597 , V_32 ,
sizeof( struct V_1 ) ) ;
V_588 -> V_598 = * V_222 ;
F_116 ( V_25 ) ;
if ( F_26 ( V_87 , V_93 ) ) {
F_95 ( V_25 , V_105 ) ;
F_87 ( V_25 -> V_51 ) -> V_305 = true ;
} else {
F_27 ( V_87 , F_28 ( V_87 ) ) ;
#ifdef F_68
F_8 ( L_61 , V_59 ,
F_31 ( V_87 ) , F_28 ( V_87 ) ) ;
#endif
}
F_30 ( V_87 , V_306 ) ;
if ( V_586 < 400 )
V_586 = V_586 * 3 ;
V_588 -> V_599 = V_249 -> V_441 ;
if ( F_86 ( V_249 -> V_276 , V_590 ) >= 0 ) {
if ( V_590 != V_249 -> V_441 ) {
V_592 = true ;
}
} else {
F_8 ( L_144 ,
V_59 , V_590 ) ;
}
if ( V_592 == true ) {
if ( ! F_15 ( & V_25 -> V_55 , V_66 ) ) {
V_249 -> V_441 = V_590 ;
F_209 ( V_25 , V_590 ,
V_600 ,
V_601 ) ;
}
}
F_8 ( L_145 , V_59 , V_586 ) ;
F_210 ( & V_588 -> V_594 ,
V_63 + F_211 ( V_586 ) ) ;
F_212 ( V_25 , * V_222 , V_32 , V_602 ,
V_586 , V_21 ) ;
V_87 -> V_603 = V_249 -> V_441 ;
exit:
if ( V_165 )
V_588 -> V_593 = false ;
return V_165 ;
}
static T_5 F_213 ( struct V_52 * V_52 ,
struct V_49 * V_50 ,
T_3 V_222 )
{
T_5 V_165 = 0 ;
struct V_24 * V_25 = F_60 ( V_52 ) ;
struct V_86 * V_87 = & V_25 -> V_88 ;
struct V_587 * V_588 =
& V_25 -> V_589 ;
F_8 ( V_301 L_39 , F_94 ( V_25 ) ) ;
if ( V_588 -> V_593 == true ) {
F_8 ( L_143 , V_59 ) ;
F_37 ( & V_25 -> V_589 . V_594 ) ;
#ifdef F_25
F_208 ( V_25 , V_595 ) ;
#endif
}
F_30 ( V_87 , F_32 ( V_87 ) ) ;
#ifdef F_68
F_8 ( L_61 , V_59 ,
F_31 ( V_87 ) , F_28 ( V_87 ) ) ;
#endif
V_588 -> V_593 = false ;
return V_165 ;
}
static int F_214 ( struct V_24 * V_25 , V_22 V_604 ,
const V_22 * V_40 , T_4 V_43 )
{
struct V_467 * V_468 ;
struct V_469 * V_470 ;
unsigned char * V_471 ;
int V_28 = V_120 ;
bool V_605 = true ;
struct V_45 * V_46 ;
struct V_472 * V_473 = & V_25 -> V_474 ;
struct V_248 * V_249 = & V_25 -> V_250 ;
if ( V_120 == F_74 ( V_25 ) ) {
V_28 = - V_596 ;
goto exit;
}
F_215 ( V_25 , 1000 ) ;
F_116 ( V_25 ) ;
if ( V_604 != F_192 ( V_25 ) ) {
if ( ! F_15 ( & V_25 -> V_55 , V_66 ) )
V_249 -> V_441 = V_604 ;
F_209 ( V_25 , V_604 ,
V_600 ,
V_601 ) ;
}
V_468 = F_158 ( V_473 ) ;
if ( V_468 == NULL ) {
V_28 = V_120 ;
goto exit;
}
V_470 = & V_468 -> V_479 ;
F_159 ( V_25 , V_470 ) ;
V_470 -> V_480 = false ;
memset ( V_468 -> V_481 , 0 , V_482 + V_483 ) ;
V_471 = ( V_22 * ) ( V_468 -> V_481 ) + V_483 ;
memcpy ( V_471 , ( void * ) V_40 , V_43 ) ;
V_470 -> V_488 = V_43 ;
V_46 = (struct V_45 * ) V_471 ;
V_249 -> V_448 = F_12 ( V_46 -> V_489 ) >> 4 ;
V_470 -> V_490 = V_249 -> V_448 ;
V_249 -> V_448 ++ ;
#ifdef F_25
{
struct V_484 * V_485 ;
V_485 = V_25 -> V_88 . V_486 ;
if ( true == V_485 -> V_487 ) {
F_160 ( V_25 , V_471 , & V_470 -> V_488 ) ;
}
}
#endif
V_470 -> V_491 = V_470 -> V_488 ;
if ( F_205 ( V_25 , V_468 ) != V_119 ) {
V_605 = false ;
V_28 = V_120 ;
#ifdef F_68
F_8 ( L_146 , V_59 ) ;
#endif
} else {
#ifdef F_68
F_8 ( L_147 , V_59 , V_605 ) ;
#endif
V_28 = V_119 ;
}
exit:
#ifdef F_68
F_8 ( L_31 , V_59 , V_28 ) ;
#endif
return V_28 ;
}
static int F_216 ( struct V_52 * V_52 , struct V_49 * V_50 ,
#if ( V_606 < F_217 ( 3 , 14 , 0 ) )
struct V_1 * V_607 ,
bool V_608 ,
unsigned int V_609 ,
const V_22 * V_40 , T_4 V_43 ,
bool V_610 , bool V_611 ,
#else
struct V_612 * V_206 ,
#endif
T_3 * V_222 )
{
struct V_24 * V_25 =
(struct V_24 * ) F_60 ( V_52 ) ;
struct V_263 * V_264 = F_87 ( V_25 -> V_51 ) ;
int V_28 = 0 ;
int V_613 ;
T_2 V_614 = V_615 ;
T_2 V_616 = 0 ;
bool V_605 = true ;
V_22 V_475 , V_476 ;
int type = ( - 1 ) ;
unsigned long V_617 = V_63 ;
#if ( V_606 >= F_217 ( 3 , 14 , 0 ) )
T_4 V_43 = V_206 -> V_43 ;
struct V_1 * V_607 = V_206 -> V_607 ;
const V_22 * V_40 = V_206 -> V_40 ;
#endif
struct V_45 * V_434 = (struct V_45 * ) V_40 ;
V_22 V_604 = ( V_22 ) F_207 ( V_607 -> V_591 ) ;
* V_222 = ( unsigned long ) V_40 ;
#ifdef F_68
F_8 ( V_301 L_148
L_39 , F_94 ( V_25 ) , V_43 , V_604 ) ;
#endif
F_218 ( V_25 , * V_222 , V_40 , V_43 , V_605 ,
V_21 ) ;
if ( F_155 ( V_40 , V_43 , & V_475 , & V_476 ) == false ) {
F_8 ( V_301 L_107 ,
F_94 ( V_25 ) ,
F_12 ( V_434 -> V_72 ) ) ;
goto exit;
}
F_8 ( L_149 V_230 L_39 , V_604 ,
F_69 ( V_434 -> V_74 ) ) ;
#ifdef F_25
type = F_156 ( V_25 , V_40 , V_43 , true ) ;
if ( type >= 0 )
goto V_477;
#endif
if ( V_475 == V_478 )
F_8 ( L_110 , F_157 ( V_476 ) ) ;
else
F_8 ( L_111 ,
V_475 , V_476 ) ;
#ifdef F_25
V_477:
#endif
do {
V_616 ++ ;
V_613 = F_214 ( V_25 , V_604 , V_40 , V_43 ) ;
} while ( V_616 < V_614 && V_613 != V_119 );
if ( V_613 != V_119 || V_616 > 1 ) {
F_8 ( V_301 L_150 ,
F_94 ( V_25 ) ,
V_613 == V_119 ? L_151 : L_152 , V_616 ,
V_614 , F_11 ( V_63 - V_617 ) ) ;
}
switch ( type ) {
case V_541 :
F_194 ( V_25 ) ;
break;
case V_618 :
if ( V_264 -> V_619 . V_243 & F_219 ( 0 )
&& V_264 -> V_619 . V_620 == 0 ) {
F_8 ( V_301 L_153
L_154 ,
F_94 ( V_25 ) ) ;
F_215 ( V_25 , 5000 ) ;
F_220 ( V_25 , 5000 ) ;
F_194 ( V_25 ) ;
}
break;
}
exit:
return V_28 ;
}
static void F_221 ( struct V_52 * V_52 ,
struct V_49 * V_50 ,
T_1 V_621 , bool V_622 )
{
#ifdef F_68
F_8 ( V_301 L_155 ,
F_94 ( V_409 ) , V_621 , V_622 ) ;
#endif
if ( V_621 != ( V_623 | V_624 ) )
return;
return;
}
static int F_222 ( struct V_149 * V_201 , char * V_40 ,
int V_43 )
{
int V_28 = 0 ;
T_6 V_277 = 0 ;
V_22 * V_278 ;
#ifdef F_25
T_2 V_279 = 0 ;
T_2 V_281 = 0 ;
V_22 * V_280 ;
#endif
#ifdef F_62
V_22 V_625 [ 8 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
#endif
struct V_24 * V_25 = F_49 ( V_201 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
struct V_248 * V_249 = & V_25 -> V_250 ;
F_8 ( V_208 L_156 , F_61 ( V_201 ) , V_43 ) ;
if ( V_43 > 0 ) {
V_278 = F_89 ( V_40 , V_43 , NULL , & V_277 ) ;
if ( V_278 ) {
#ifdef F_68
F_8 ( L_157 , V_277 ) ;
#endif
if ( V_54 -> V_626 ) {
V_54 -> V_627 = 0 ;
F_40 ( V_54 -> V_626 ) ;
V_54 -> V_626 = NULL ;
}
V_54 -> V_626 =
F_90 ( V_277 , V_21 ) ;
if ( V_54 -> V_626 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
memcpy ( V_54 -> V_626 , V_278 , V_277 ) ;
V_54 -> V_627 = V_277 ;
#ifdef F_62
F_223 ( V_25 , V_516 , V_625 ,
true ) ;
#endif
}
#ifdef F_25
V_280 = F_91 ( V_40 , V_43 , NULL , & V_279 ) ;
if ( V_280 ) {
#ifdef F_68
F_8 ( L_158 , V_279 ) ;
#endif
if ( V_54 -> V_628 ) {
V_54 -> V_629 = 0 ;
F_40 ( V_54 -> V_628 ) ;
V_54 -> V_628 = NULL ;
}
V_54 -> V_628 =
F_90 ( V_279 , V_21 ) ;
if ( V_54 -> V_628 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
memcpy ( V_54 -> V_628 , V_280 , V_279 ) ;
V_54 -> V_629 = V_279 ;
}
#endif
#ifdef F_25
if ( F_92 ( V_40 , V_43 , NULL , & V_281 ) ) {
#ifdef F_68
F_8 ( L_159 , V_281 ) ;
#endif
if ( V_54 -> V_630 ) {
V_54 -> V_631 = 0 ;
F_40 ( V_54 -> V_630 ) ;
V_54 -> V_630 = NULL ;
}
V_54 -> V_630 =
F_90 ( V_281 , V_21 ) ;
if ( V_54 -> V_630 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
F_92 ( V_40 , V_43 , V_54 -> V_630 ,
& V_54 -> V_631 ) ;
}
#endif
V_249 -> V_632 = true ;
}
return V_28 ;
}
static int F_224 ( struct V_149 * V_633 ,
char * V_40 , int V_43 )
{
struct V_24 * V_25 = F_49 ( V_633 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
#ifdef F_25
T_2 V_279 = 0 ;
V_22 * V_280 ;
T_2 V_281 = 0 ;
#endif
int V_28 = 0 ;
T_6 V_277 = 0 ;
V_22 * V_278 ;
if ( V_43 > 0 ) {
V_278 = F_89 ( V_40 , V_43 , NULL , & V_277 ) ;
if ( V_278 ) {
T_6 V_634 = 0 ;
T_1 V_635 , * V_636 = NULL ;
if ( V_54 -> V_637 ) {
V_54 -> V_638 = 0 ;
F_40 ( V_54 -> V_637 ) ;
V_54 -> V_637 = NULL ;
}
V_54 -> V_637 =
F_90 ( V_277 , V_21 ) ;
if ( V_54 -> V_637 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
V_636 = ( T_1 * ) F_198 ( V_278 , V_277 ,
V_585 ,
NULL ,
& V_634 ) ;
if ( V_636 ) {
V_635 = V_567 ;
V_635 = F_203 ( V_635 ) ;
* V_636 |= V_635 ;
}
memcpy ( V_54 -> V_637 , V_278 , V_277 ) ;
V_54 -> V_638 = V_277 ;
}
#ifdef F_25
V_280 = F_91 ( V_40 , V_43 , NULL , & V_279 ) ;
if ( V_280 ) {
V_22 V_639 = false ;
T_2 V_634 = 0 ;
T_1 V_640 = 0 ;
#ifdef F_68
F_8 ( L_160 , V_279 ) ;
#endif
if ( F_200 ( V_280 , V_279 ,
V_580 ,
( V_22 * ) & V_640 ,
( T_6 * ) & V_634 ) ) {
V_22 V_641 = 0 ;
V_640 = F_12 ( V_640 ) ;
V_641 = ( V_22 ) ( ( V_640 >> 8 ) & 0xff ) ;
V_639 = ( V_641 & F_219 ( 0 ) ) ? true : false ;
if ( V_639 )
F_8
( L_161
L_162 , V_641 ) ;
}
if ( V_639 == false ) {
if ( V_54 -> V_642 ) {
V_54 -> V_643 = 0 ;
F_40 ( V_54 -> V_642 ) ;
V_54 -> V_642 = NULL ;
}
V_54 -> V_642 =
F_90 ( V_279 , V_21 ) ;
if ( V_54 -> V_642 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
memcpy ( V_54 -> V_642 , V_280 ,
V_279 ) ;
V_54 -> V_643 = V_279 ;
} else {
if ( V_54 -> V_644 ) {
V_54 -> V_645 = 0 ;
F_40 ( V_54 -> V_644 ) ;
V_54 -> V_644 = NULL ;
}
V_54 -> V_644 =
F_90 ( V_279 , V_21 ) ;
if ( V_54 -> V_644 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
memcpy ( V_54 -> V_644 ,
V_280 , V_279 ) ;
V_54 -> V_645 = V_279 ;
}
}
#endif
#ifdef F_25
if ( F_92 ( V_40 , V_43 , NULL , & V_281 ) ) {
#ifdef F_68
F_8 ( L_163 , V_281 ) ;
#endif
if ( V_54 -> V_646 ) {
V_54 -> V_647 = 0 ;
F_40 ( V_54 -> V_646 ) ;
V_54 -> V_646 = NULL ;
}
V_54 -> V_646 =
F_90 ( V_281 , V_21 ) ;
if ( V_54 -> V_646 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
F_92 ( V_40 , V_43 , V_54 -> V_646 ,
& V_54 -> V_647 ) ;
}
#endif
}
return V_28 ;
}
static int F_225 ( struct V_149 * V_633 ,
char * V_40 , int V_43 )
{
int V_28 = 0 ;
struct V_24 * V_25 = F_49 ( V_633 ) ;
struct V_53 * V_54 = & V_25 -> V_55 ;
F_8 ( L_54 , V_59 , V_43 ) ;
if ( V_43 > 0 ) {
if ( V_54 -> V_648 ) {
V_54 -> V_649 = 0 ;
F_40 ( V_54 -> V_648 ) ;
V_54 -> V_648 = NULL ;
}
V_54 -> V_648 = F_90 ( V_43 , V_21 ) ;
if ( V_54 -> V_648 == NULL ) {
F_8 ( L_56 ,
V_59 , __LINE__ ) ;
return - V_84 ;
}
memcpy ( V_54 -> V_648 , V_40 , V_43 ) ;
V_54 -> V_649 = V_43 ;
}
return V_28 ;
}
int F_226 ( struct V_149 * V_633 , char * V_40 , int V_43 ,
int type )
{
int V_28 = 0 ;
T_6 V_277 = 0 ;
#ifdef F_25
T_2 V_279 = 0 ;
#endif
#ifdef F_68
F_8 ( L_54 , V_59 , V_43 ) ;
#endif
if ( ( F_89 ( V_40 , V_43 , NULL , & V_277 ) && ( V_277 > 0 ) )
#ifdef F_25
|| ( F_91 ( V_40 , V_43 , NULL , & V_279 ) && ( V_279 > 0 ) )
#endif
) {
if ( V_633 ) {
switch ( type ) {
case 0x1 :
V_28 =
F_222 ( V_633 , V_40 ,
V_43 ) ;
break;
case 0x2 :
V_28 =
F_224 ( V_633 ,
V_40 ,
V_43 ) ;
break;
case 0x4 :
V_28 =
F_225 ( V_633 ,
V_40 ,
V_43 ) ;
break;
}
}
}
return V_28 ;
}
static void F_227 ( struct V_650 * V_651 ,
enum V_14 V_15 , V_22 V_652 )
{
#define F_228 300
#define F_229 150
V_651 -> V_653 = true ;
V_651 -> V_654 = V_655 |
V_656 | V_657 |
V_658 | V_659 ;
V_651 -> V_660 = V_661 ;
V_651 -> V_662 = V_663 ;
V_651 -> V_664 . V_665 = V_666 ;
if ( V_652 == V_667 ) {
V_651 -> V_664 . V_668 [ 0 ] = 0xFF ;
V_651 -> V_664 . V_668 [ 1 ] = 0x00 ;
V_651 -> V_664 . V_668 [ 4 ] = 0x01 ;
V_651 -> V_664 . V_669 = F_229 ;
} else if ( ( V_652 == V_670 ) || ( V_652 == V_671 ) ) {
V_651 -> V_664 . V_668 [ 0 ] = 0xFF ;
V_651 -> V_664 . V_668 [ 1 ] = 0xFF ;
V_651 -> V_664 . V_668 [ 4 ] = 0x01 ;
V_651 -> V_664 . V_669 = F_228 ;
} else {
F_8 ( L_164 , V_59 , V_652 ) ;
}
}
void F_230 ( struct V_24 * V_25 )
{
V_22 V_652 ;
struct V_13 * V_672 ;
struct V_49 * V_85 = V_25 -> V_51 ;
struct V_52 * V_52 = V_85 -> V_52 ;
F_231 ( V_25 , V_673 , ( V_22 * ) ( & V_652 ) ) ;
F_8 ( L_165 , V_59 , V_652 ) ;
{
V_672 = V_52 -> V_672 [ V_19 ] ;
if ( V_672 )
F_227 ( & V_672 -> V_651 ,
V_19 ,
V_652 ) ;
}
{
V_672 = V_52 -> V_672 [ V_20 ] ;
if ( V_672 )
F_227 ( & V_672 -> V_651 ,
V_20 ,
V_652 ) ;
}
}
static void F_232 ( struct V_24 * V_25 ,
struct V_52 * V_52 )
{
V_52 -> V_674 = V_675 ;
V_52 -> V_676 = V_294 ;
V_52 -> V_677 = V_678 ;
V_52 -> V_679 = V_680 ;
V_52 -> V_681 =
V_682 ;
V_52 -> V_683 = F_219 ( V_90 ) |
F_219 ( V_255 ) |
#ifdef F_62
F_219 ( V_260 ) | F_219 ( V_503 ) |
#endif
#if F_136 ( F_25 )
F_219 ( V_91 ) | F_219 ( V_259 ) |
#endif
0 ;
#ifdef F_62
V_52 -> V_684 = V_685 ;
#endif
V_52 -> V_686 |= F_219 ( V_503 ) ;
V_52 -> V_687 = V_688 ;
V_52 -> V_689 = F_233 ( V_688 ) ;
V_52 -> V_672 [ V_19 ] =
F_5 ( V_19 ) ;
V_52 -> V_672 [ V_20 ] =
F_5 ( V_20 ) ;
V_52 -> V_243 |= V_690 ;
V_52 -> V_243 |= V_691 | V_692 ;
if ( V_25 -> V_693 . V_694 != V_695 )
V_52 -> V_243 |= V_696 ;
else
V_52 -> V_243 &= ~ V_696 ;
}
int F_234 ( struct V_24 * V_25 , struct V_697 * V_150 )
{
int V_28 = 0 ;
struct V_52 * V_52 ;
struct V_49 * V_50 ;
struct V_263 * V_264 ;
struct V_149 * V_96 = V_25 -> V_96 ;
F_8 ( L_3 , V_59 , V_25 ) ;
V_52 = F_235 ( & V_698 , sizeof( struct V_263 ) ) ;
if ( ! V_52 ) {
F_8 ( L_166 ) ;
V_28 = - V_355 ;
goto exit;
}
F_236 ( V_52 , V_150 ) ;
F_232 ( V_25 , V_52 ) ;
V_28 = F_237 ( V_52 ) ;
if ( V_28 < 0 ) {
F_8 ( L_167 ) ;
goto V_699;
}
V_50 = F_6 ( sizeof( struct V_49 ) , V_21 ) ;
if ( ! V_50 ) {
F_8 ( L_168 ) ;
V_28 = - V_355 ;
goto V_700;
}
V_50 -> V_52 = V_52 ;
V_50 -> V_413 = V_96 ;
V_50 -> V_89 = V_503 ;
V_25 -> V_51 = V_50 ;
V_96 -> V_504 = V_50 ;
V_264 = F_87 ( V_50 ) ;
V_264 -> V_51 = V_50 ;
V_264 -> V_495 = NULL ;
V_264 -> V_505 [ 0 ] = '\0' ;
V_264 -> V_25 = V_25 ;
V_264 -> V_267 = NULL ;
F_238 ( & V_264 -> V_266 ) ;
V_264 -> V_305 = false ;
V_264 -> V_701 = false ;
F_239 ( & V_264 -> V_619 ) ;
if ( V_25 -> V_693 . V_694 != V_695 )
V_264 -> V_410 = true ;
else
V_264 -> V_410 = false ;
return V_28 ;
V_700:
F_240 ( V_52 ) ;
V_699:
F_241 ( V_52 ) ;
exit:
return V_28 ;
}
void F_242 ( struct V_49 * V_50 )
{
struct V_263 * V_264 ;
F_8 ( L_169 , V_59 , V_50 ) ;
if ( ! V_50 )
return;
V_264 = F_87 ( V_50 ) ;
F_40 ( V_50 -> V_52 -> V_672 [ V_19 ] ) ;
F_40 ( V_50 -> V_52 -> V_672 [ V_20 ] ) ;
F_241 ( V_50 -> V_52 ) ;
F_40 ( V_50 ) ;
}
void F_243 ( struct V_49 * V_50 )
{
struct V_263 * V_264 ;
F_8 ( L_169 , V_59 , V_50 ) ;
if ( ! V_50 )
return;
V_264 = F_87 ( V_50 ) ;
F_78 ( V_264 , true ) ;
if ( V_264 -> V_495 ) {
F_8 ( L_170 , V_59 ) ;
F_244 ( V_264 -> V_495 ) ;
}
F_240 ( V_50 -> V_52 ) ;
}
