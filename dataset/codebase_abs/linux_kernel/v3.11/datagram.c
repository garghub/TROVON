static bool F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 ) && ( V_2 -> V_3 [ 3 ] == 0 ) ;
}
int F_3 ( struct V_4 * V_5 , struct V_6 * V_7 , int V_8 )
{
struct V_9 * V_10 = (struct V_9 * ) V_7 ;
struct V_11 * V_12 = F_4 ( V_5 ) ;
struct V_13 * V_14 = F_5 ( V_5 ) ;
struct V_1 * V_15 , * V_16 , V_17 ;
struct V_18 * V_19 ;
struct V_20 V_21 ;
struct V_22 * V_23 = NULL ;
struct V_24 * V_25 ;
int V_26 ;
int V_27 ;
if ( V_10 -> V_28 == V_29 ) {
if ( F_6 ( V_5 ) )
return - V_30 ;
V_27 = F_7 ( V_5 , V_7 , V_8 ) ;
goto V_31;
}
if ( V_8 < V_32 )
return - V_33 ;
if ( V_10 -> V_28 != V_34 )
return - V_30 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
if ( V_14 -> V_35 ) {
V_21 . V_23 = V_10 -> V_36 & V_37 ;
if ( V_21 . V_23 & V_38 ) {
V_23 = F_8 ( V_5 , V_21 . V_23 ) ;
if ( V_23 == NULL )
return - V_33 ;
V_10 -> V_39 = V_23 -> V_19 ;
}
}
V_26 = F_9 ( & V_10 -> V_39 ) ;
if ( V_26 == V_40 ) {
V_10 -> V_39 . V_41 [ 15 ] = 0x01 ;
}
V_15 = & V_10 -> V_39 ;
if ( V_26 == V_42 ) {
struct V_43 sin ;
if ( F_6 ( V_5 ) ) {
V_27 = - V_44 ;
goto V_45;
}
sin . V_46 = V_29 ;
sin . V_47 . V_48 = V_15 -> V_3 [ 3 ] ;
sin . V_49 = V_10 -> V_50 ;
V_27 = F_7 ( V_5 ,
(struct V_6 * ) & sin ,
sizeof( sin ) ) ;
V_31:
if ( V_27 )
goto V_45;
F_10 ( V_12 -> V_51 , & V_14 -> V_15 ) ;
if ( F_11 ( & V_14 -> V_52 ) ||
F_1 ( & V_14 -> V_52 ) )
F_10 ( V_12 -> V_53 , & V_14 -> V_52 ) ;
if ( F_11 ( & V_14 -> V_54 ) ||
F_1 ( & V_14 -> V_54 ) ) {
F_10 ( V_12 -> V_55 ,
& V_14 -> V_54 ) ;
if ( V_5 -> V_56 -> V_57 )
V_5 -> V_56 -> V_57 ( V_5 ) ;
}
goto V_45;
}
if ( F_12 ( V_26 ) ) {
if ( V_8 >= sizeof( struct V_9 ) &&
V_10 -> V_58 ) {
if ( V_5 -> V_59 &&
V_5 -> V_59 != V_10 -> V_58 ) {
V_27 = - V_33 ;
goto V_45;
}
V_5 -> V_59 = V_10 -> V_58 ;
}
if ( ! V_5 -> V_59 && ( V_26 & V_60 ) )
V_5 -> V_59 = V_14 -> V_61 ;
if ( ! V_5 -> V_59 ) {
V_27 = - V_33 ;
goto V_45;
}
}
V_14 -> V_15 = * V_15 ;
V_14 -> V_62 = V_21 . V_23 ;
V_12 -> V_63 = V_10 -> V_50 ;
V_21 . V_64 = V_5 -> V_65 ;
V_21 . V_15 = V_14 -> V_15 ;
V_21 . V_52 = V_14 -> V_52 ;
V_21 . V_66 = V_5 -> V_59 ;
V_21 . V_67 = V_5 -> V_68 ;
V_21 . V_69 = V_12 -> V_63 ;
V_21 . V_70 = V_12 -> V_71 ;
if ( ! V_21 . V_66 && ( V_26 & V_60 ) )
V_21 . V_66 = V_14 -> V_61 ;
F_13 ( V_5 , F_14 ( & V_21 ) ) ;
V_25 = V_23 ? V_23 -> V_25 : V_14 -> V_25 ;
V_16 = F_15 ( & V_21 , V_25 , & V_17 ) ;
V_19 = F_16 ( V_5 , & V_21 , V_16 , true ) ;
V_27 = 0 ;
if ( F_17 ( V_19 ) ) {
V_27 = F_18 ( V_19 ) ;
goto V_45;
}
if ( F_11 ( & V_14 -> V_52 ) )
V_14 -> V_52 = V_21 . V_52 ;
if ( F_11 ( & V_14 -> V_54 ) ) {
V_14 -> V_54 = V_21 . V_52 ;
V_12 -> V_55 = V_72 ;
if ( V_5 -> V_56 -> V_57 )
V_5 -> V_56 -> V_57 ( V_5 ) ;
}
F_19 ( V_5 , V_19 ,
F_20 ( & V_21 . V_15 , & V_14 -> V_15 ) ?
& V_14 -> V_15 : NULL ,
#ifdef F_21
F_20 ( & V_21 . V_52 , & V_14 -> V_52 ) ?
& V_14 -> V_52 :
#endif
NULL ) ;
V_5 -> V_73 = V_74 ;
V_45:
F_22 ( V_23 ) ;
return V_27 ;
}
void F_23 ( struct V_4 * V_5 , struct V_75 * V_76 , int V_27 ,
T_1 V_77 , T_2 V_78 , T_3 * V_79 )
{
struct V_13 * V_14 = F_5 ( V_5 ) ;
struct V_80 * V_81 = F_24 ( V_76 ) ;
struct V_82 * V_83 ;
if ( ! V_14 -> V_84 )
return;
V_76 = F_25 ( V_76 , V_85 ) ;
if ( ! V_76 )
return;
V_76 -> V_86 = F_26 ( V_87 ) ;
V_83 = F_27 ( V_76 ) ;
V_83 -> V_88 . V_89 = V_27 ;
V_83 -> V_88 . V_90 = V_91 ;
V_83 -> V_88 . V_92 = V_81 -> V_93 ;
V_83 -> V_88 . V_94 = V_81 -> V_95 ;
V_83 -> V_88 . V_96 = 0 ;
V_83 -> V_88 . V_97 = V_78 ;
V_83 -> V_88 . V_98 = 0 ;
V_83 -> V_99 = ( T_3 * ) & ( ( (struct V_100 * ) ( V_81 + 1 ) ) -> V_15 ) -
F_28 ( V_76 ) ;
V_83 -> V_77 = V_77 ;
F_29 ( V_76 , V_79 - V_76 -> V_101 ) ;
F_30 ( V_76 ) ;
if ( F_31 ( V_5 , V_76 ) )
F_32 ( V_76 ) ;
}
void F_33 ( struct V_4 * V_5 , int V_27 , struct V_20 * V_21 , T_2 V_78 )
{
struct V_13 * V_14 = F_5 ( V_5 ) ;
struct V_82 * V_83 ;
struct V_100 * V_102 ;
struct V_75 * V_76 ;
if ( ! V_14 -> V_84 )
return;
V_76 = F_34 ( sizeof( struct V_100 ) , V_85 ) ;
if ( ! V_76 )
return;
V_76 -> V_86 = F_26 ( V_87 ) ;
F_35 ( V_76 , sizeof( struct V_100 ) ) ;
F_36 ( V_76 ) ;
V_102 = F_37 ( V_76 ) ;
V_102 -> V_15 = V_21 -> V_15 ;
V_83 = F_27 ( V_76 ) ;
V_83 -> V_88 . V_89 = V_27 ;
V_83 -> V_88 . V_90 = V_103 ;
V_83 -> V_88 . V_92 = 0 ;
V_83 -> V_88 . V_94 = 0 ;
V_83 -> V_88 . V_96 = 0 ;
V_83 -> V_88 . V_97 = V_78 ;
V_83 -> V_88 . V_98 = 0 ;
V_83 -> V_99 = ( T_3 * ) & V_102 -> V_15 - F_28 ( V_76 ) ;
V_83 -> V_77 = V_21 -> V_69 ;
F_29 ( V_76 , F_38 ( V_76 ) - V_76 -> V_101 ) ;
F_30 ( V_76 ) ;
if ( F_31 ( V_5 , V_76 ) )
F_32 ( V_76 ) ;
}
void F_39 ( struct V_4 * V_5 , struct V_20 * V_21 , T_2 V_104 )
{
struct V_13 * V_14 = F_5 ( V_5 ) ;
struct V_100 * V_102 ;
struct V_75 * V_76 ;
struct V_105 * V_106 ;
if ( ! V_14 -> V_107 . V_108 . V_109 )
return;
V_76 = F_34 ( sizeof( struct V_100 ) , V_85 ) ;
if ( ! V_76 )
return;
F_35 ( V_76 , sizeof( struct V_100 ) ) ;
F_36 ( V_76 ) ;
V_102 = F_37 ( V_76 ) ;
V_102 -> V_15 = V_21 -> V_15 ;
V_106 = F_40 ( V_76 ) ;
V_106 -> V_110 = V_104 ;
V_106 -> V_111 . V_28 = V_34 ;
V_106 -> V_111 . V_50 = 0 ;
V_106 -> V_111 . V_36 = 0 ;
V_106 -> V_111 . V_58 = V_21 -> V_66 ;
V_106 -> V_111 . V_39 = F_37 ( V_76 ) -> V_15 ;
F_29 ( V_76 , F_38 ( V_76 ) - V_76 -> V_101 ) ;
F_30 ( V_76 ) ;
V_76 = F_41 ( & V_14 -> V_109 , V_76 ) ;
F_32 ( V_76 ) ;
}
int F_42 ( struct V_4 * V_5 , struct V_112 * V_113 , int V_114 )
{
struct V_13 * V_14 = F_5 ( V_5 ) ;
struct V_82 * V_83 ;
struct V_75 * V_76 , * V_115 ;
struct V_9 * sin ;
struct {
struct V_116 V_88 ;
struct V_9 V_117 ;
} V_118 ;
int V_27 ;
int V_119 ;
V_27 = - V_120 ;
V_76 = F_43 ( & V_5 -> V_121 ) ;
if ( V_76 == NULL )
goto V_45;
V_119 = V_76 -> V_114 ;
if ( V_119 > V_114 ) {
V_113 -> V_122 |= V_123 ;
V_119 = V_114 ;
}
V_27 = F_44 ( V_76 , 0 , V_113 -> V_124 , V_119 ) ;
if ( V_27 )
goto V_125;
F_45 ( V_113 , V_5 , V_76 ) ;
V_83 = F_27 ( V_76 ) ;
sin = (struct V_9 * ) V_113 -> V_126 ;
if ( sin ) {
const unsigned char * V_127 = F_28 ( V_76 ) ;
sin -> V_28 = V_34 ;
sin -> V_36 = 0 ;
sin -> V_50 = V_83 -> V_77 ;
if ( V_76 -> V_86 == F_26 ( V_87 ) ) {
const struct V_100 * V_128 = F_46 ( (struct V_1 * ) ( V_127 + V_83 -> V_99 ) ,
struct V_100 , V_15 ) ;
sin -> V_39 = V_128 -> V_15 ;
if ( V_14 -> V_35 )
sin -> V_36 = F_47 ( V_128 ) ;
sin -> V_58 =
F_48 ( & sin -> V_39 ,
F_49 ( V_76 ) -> V_129 ) ;
} else {
F_10 ( * ( V_130 * ) ( V_127 + V_83 -> V_99 ) ,
& sin -> V_39 ) ;
sin -> V_58 = 0 ;
}
}
memcpy ( & V_118 . V_88 , & V_83 -> V_88 , sizeof( struct V_116 ) ) ;
sin = & V_118 . V_117 ;
sin -> V_28 = V_131 ;
if ( V_83 -> V_88 . V_90 != V_103 ) {
sin -> V_28 = V_34 ;
sin -> V_36 = 0 ;
if ( V_76 -> V_86 == F_26 ( V_87 ) ) {
sin -> V_39 = F_37 ( V_76 ) -> V_52 ;
if ( V_14 -> V_107 . V_132 )
F_50 ( V_5 , V_113 , V_76 ) ;
sin -> V_58 =
F_48 ( & sin -> V_39 ,
F_49 ( V_76 ) -> V_129 ) ;
} else {
struct V_11 * V_12 = F_4 ( V_5 ) ;
F_10 ( F_51 ( V_76 ) -> V_52 ,
& sin -> V_39 ) ;
sin -> V_58 = 0 ;
if ( V_12 -> V_133 )
F_52 ( V_113 , V_76 ) ;
}
}
F_53 ( V_113 , V_134 , V_135 , sizeof( V_118 ) , & V_118 ) ;
V_113 -> V_122 |= V_136 ;
V_27 = V_119 ;
F_54 ( & V_5 -> V_121 . V_137 ) ;
V_5 -> V_138 = 0 ;
if ( ( V_115 = F_55 ( & V_5 -> V_121 ) ) != NULL ) {
V_5 -> V_138 = F_27 ( V_115 ) -> V_88 . V_89 ;
F_56 ( & V_5 -> V_121 . V_137 ) ;
V_5 -> V_139 ( V_5 ) ;
} else {
F_56 ( & V_5 -> V_121 . V_137 ) ;
}
V_125:
F_32 ( V_76 ) ;
V_45:
return V_27 ;
}
int F_57 ( struct V_4 * V_5 , struct V_112 * V_113 , int V_114 )
{
struct V_13 * V_14 = F_5 ( V_5 ) ;
struct V_75 * V_76 ;
struct V_9 * sin ;
struct V_105 V_106 ;
int V_27 ;
int V_119 ;
V_27 = - V_120 ;
V_76 = F_41 ( & V_14 -> V_109 , NULL ) ;
if ( V_76 == NULL )
goto V_45;
V_119 = V_76 -> V_114 ;
if ( V_119 > V_114 ) {
V_113 -> V_122 |= V_123 ;
V_119 = V_114 ;
}
V_27 = F_44 ( V_76 , 0 , V_113 -> V_124 , V_119 ) ;
if ( V_27 )
goto V_125;
F_45 ( V_113 , V_5 , V_76 ) ;
memcpy ( & V_106 , F_40 ( V_76 ) , sizeof( V_106 ) ) ;
sin = (struct V_9 * ) V_113 -> V_126 ;
if ( sin ) {
sin -> V_28 = V_34 ;
sin -> V_36 = 0 ;
sin -> V_50 = 0 ;
sin -> V_58 = V_106 . V_111 . V_58 ;
sin -> V_39 = V_106 . V_111 . V_39 ;
}
F_53 ( V_113 , V_134 , V_140 , sizeof( V_106 ) , & V_106 ) ;
V_27 = V_119 ;
V_125:
F_32 ( V_76 ) ;
V_45:
return V_27 ;
}
int F_50 ( struct V_4 * V_5 , struct V_112 * V_113 ,
struct V_75 * V_76 )
{
struct V_13 * V_14 = F_5 ( V_5 ) ;
struct V_141 * V_25 = F_49 ( V_76 ) ;
unsigned char * V_127 = F_28 ( V_76 ) ;
if ( V_14 -> V_107 . V_108 . V_142 ) {
struct V_143 V_144 ;
V_144 . V_145 = V_25 -> V_129 ;
V_144 . V_146 = F_37 ( V_76 ) -> V_15 ;
F_53 ( V_113 , V_134 , V_147 , sizeof( V_144 ) , & V_144 ) ;
}
if ( V_14 -> V_107 . V_108 . V_148 ) {
int V_149 = F_37 ( V_76 ) -> V_150 ;
F_53 ( V_113 , V_134 , V_151 , sizeof( V_149 ) , & V_149 ) ;
}
if ( V_14 -> V_107 . V_108 . V_152 ) {
int V_153 = F_58 ( F_37 ( V_76 ) ) ;
F_53 ( V_113 , V_134 , V_154 , sizeof( V_153 ) , & V_153 ) ;
}
if ( V_14 -> V_107 . V_108 . V_155 ) {
V_130 V_156 = F_47 ( (struct V_100 * ) V_127 ) ;
if ( V_156 )
F_53 ( V_113 , V_134 , V_157 , sizeof( V_156 ) , & V_156 ) ;
}
if ( V_14 -> V_107 . V_108 . V_158 && V_25 -> V_159 ) {
T_3 * V_160 = V_127 + V_25 -> V_159 ;
F_53 ( V_113 , V_134 , V_161 , ( V_160 [ 1 ] + 1 ) << 3 , V_160 ) ;
}
if ( V_25 -> V_162 &&
( V_14 -> V_107 . V_108 . V_163 || V_14 -> V_107 . V_108 . V_164 ) ) {
unsigned int V_165 = sizeof( struct V_100 ) ;
T_3 V_166 = F_37 ( V_76 ) -> V_166 ;
while ( V_165 <= V_25 -> V_162 ) {
unsigned int V_114 ;
T_3 * V_160 = V_127 + V_165 ;
switch ( V_166 ) {
case V_167 :
V_166 = V_160 [ 0 ] ;
V_114 = ( V_160 [ 1 ] + 1 ) << 3 ;
if ( V_14 -> V_107 . V_108 . V_163 )
F_53 ( V_113 , V_134 , V_168 , V_114 , V_160 ) ;
break;
case V_169 :
V_166 = V_160 [ 0 ] ;
V_114 = ( V_160 [ 1 ] + 1 ) << 3 ;
if ( V_14 -> V_107 . V_108 . V_164 )
F_53 ( V_113 , V_134 , V_170 , V_114 , V_160 ) ;
break;
case V_171 :
V_166 = V_160 [ 0 ] ;
V_114 = ( V_160 [ 1 ] + 2 ) << 2 ;
break;
default:
V_166 = V_160 [ 0 ] ;
V_114 = ( V_160 [ 1 ] + 1 ) << 3 ;
break;
}
V_165 += V_114 ;
}
}
if ( V_14 -> V_107 . V_108 . V_172 ) {
struct V_143 V_144 ;
V_144 . V_145 = V_25 -> V_129 ;
V_144 . V_146 = F_37 ( V_76 ) -> V_15 ;
F_53 ( V_113 , V_134 , V_173 , sizeof( V_144 ) , & V_144 ) ;
}
if ( V_14 -> V_107 . V_108 . V_174 ) {
int V_149 = F_37 ( V_76 ) -> V_150 ;
F_53 ( V_113 , V_134 , V_175 , sizeof( V_149 ) , & V_149 ) ;
}
if ( V_14 -> V_107 . V_108 . V_176 && V_25 -> V_159 ) {
T_3 * V_160 = V_127 + V_25 -> V_159 ;
F_53 ( V_113 , V_134 , V_177 , ( V_160 [ 1 ] + 1 ) << 3 , V_160 ) ;
}
if ( V_14 -> V_107 . V_108 . V_178 && V_25 -> V_179 ) {
T_3 * V_160 = V_127 + V_25 -> V_179 ;
F_53 ( V_113 , V_134 , V_180 , ( V_160 [ 1 ] + 1 ) << 3 , V_160 ) ;
}
if ( V_14 -> V_107 . V_108 . V_181 && V_25 -> V_164 ) {
struct V_182 * V_183 = (struct V_182 * ) ( V_127 + V_25 -> V_164 ) ;
F_53 ( V_113 , V_134 , V_184 , ( V_183 -> V_185 + 1 ) << 3 , V_183 ) ;
}
if ( V_14 -> V_107 . V_108 . V_178 && V_25 -> V_186 ) {
T_3 * V_160 = V_127 + V_25 -> V_186 ;
F_53 ( V_113 , V_134 , V_180 , ( V_160 [ 1 ] + 1 ) << 3 , V_160 ) ;
}
if ( V_14 -> V_107 . V_108 . V_187 ) {
struct V_9 V_188 ;
T_1 * V_189 = ( T_1 * ) F_59 ( V_76 ) ;
if ( F_60 ( V_76 ) + 4 <= V_76 -> V_114 ) {
V_188 . V_28 = V_34 ;
V_188 . V_39 = F_37 ( V_76 ) -> V_15 ;
V_188 . V_50 = V_189 [ 1 ] ;
V_188 . V_36 = 0 ;
V_188 . V_58 =
F_48 ( & F_37 ( V_76 ) -> V_15 ,
V_25 -> V_129 ) ;
F_53 ( V_113 , V_134 , V_190 , sizeof( V_188 ) , & V_188 ) ;
}
}
return 0 ;
}
int F_61 ( struct V_191 * V_191 , struct V_4 * V_5 ,
struct V_112 * V_113 , struct V_20 * V_21 ,
struct V_24 * V_25 ,
int * V_192 , int * V_153 , int * V_193 )
{
struct V_143 * V_144 ;
struct V_194 * V_195 ;
struct V_182 * V_183 ;
struct V_196 * V_197 ;
int V_114 ;
int V_27 = 0 ;
for ( V_195 = F_62 ( V_113 ) ; V_195 ; V_195 = F_63 ( V_113 , V_195 ) ) {
int V_26 ;
if ( ! F_64 ( V_113 , V_195 ) ) {
V_27 = - V_33 ;
goto V_198;
}
if ( V_195 -> V_199 != V_134 )
continue;
switch ( V_195 -> V_200 ) {
case V_147 :
case V_173 :
{
struct V_201 * V_202 = NULL ;
if ( V_195 -> V_203 < F_65 ( sizeof( struct V_143 ) ) ) {
V_27 = - V_33 ;
goto V_198;
}
V_144 = (struct V_143 * ) F_66 ( V_195 ) ;
if ( V_144 -> V_145 ) {
if ( V_21 -> V_66 &&
V_144 -> V_145 != V_21 -> V_66 )
return - V_33 ;
V_21 -> V_66 = V_144 -> V_145 ;
}
V_26 = F_67 ( & V_144 -> V_146 ) ;
F_68 () ;
if ( V_21 -> V_66 ) {
V_202 = F_69 ( V_191 , V_21 -> V_66 ) ;
if ( ! V_202 ) {
F_70 () ;
return - V_204 ;
}
} else if ( V_26 & V_205 ) {
F_70 () ;
return - V_33 ;
}
if ( V_26 != V_40 ) {
int V_206 = F_71 ( V_26 ) <= V_207 ;
if ( ! ( F_4 ( V_5 ) -> V_208 || F_4 ( V_5 ) -> V_209 ) &&
! F_72 ( V_191 , & V_144 -> V_146 ,
V_206 ? V_202 : NULL , 0 ) )
V_27 = - V_33 ;
else
V_21 -> V_52 = V_144 -> V_146 ;
}
F_70 () ;
if ( V_27 )
goto V_198;
break;
}
case V_157 :
if ( V_195 -> V_203 < F_65 ( 4 ) ) {
V_27 = - V_33 ;
goto V_198;
}
if ( V_21 -> V_23 & V_37 ) {
if ( ( V_21 -> V_23 ^ * ( V_130 * ) F_66 ( V_195 ) ) & ~ V_37 ) {
V_27 = - V_33 ;
goto V_198;
}
}
V_21 -> V_23 = V_37 & * ( V_130 * ) F_66 ( V_195 ) ;
break;
case V_177 :
case V_161 :
if ( V_25 -> V_210 || V_195 -> V_203 < F_65 ( sizeof( struct V_196 ) ) ) {
V_27 = - V_33 ;
goto V_198;
}
V_197 = (struct V_196 * ) F_66 ( V_195 ) ;
V_114 = ( ( V_197 -> V_185 + 1 ) << 3 ) ;
if ( V_195 -> V_203 < F_65 ( V_114 ) ) {
V_27 = - V_33 ;
goto V_198;
}
if ( ! F_73 ( V_191 -> V_211 , V_212 ) ) {
V_27 = - V_213 ;
goto V_198;
}
V_25 -> V_214 += V_114 ;
V_25 -> V_210 = V_197 ;
break;
case V_180 :
if ( V_195 -> V_203 < F_65 ( sizeof( struct V_196 ) ) ) {
V_27 = - V_33 ;
goto V_198;
}
V_197 = (struct V_196 * ) F_66 ( V_195 ) ;
V_114 = ( ( V_197 -> V_185 + 1 ) << 3 ) ;
if ( V_195 -> V_203 < F_65 ( V_114 ) ) {
V_27 = - V_33 ;
goto V_198;
}
if ( ! F_73 ( V_191 -> V_211 , V_212 ) ) {
V_27 = - V_213 ;
goto V_198;
}
if ( V_25 -> V_215 ) {
V_27 = - V_33 ;
goto V_198;
}
V_25 -> V_216 += V_114 ;
V_25 -> V_215 = V_197 ;
break;
case V_168 :
case V_217 :
if ( V_195 -> V_203 < F_65 ( sizeof( struct V_196 ) ) ) {
V_27 = - V_33 ;
goto V_198;
}
V_197 = (struct V_196 * ) F_66 ( V_195 ) ;
V_114 = ( ( V_197 -> V_185 + 1 ) << 3 ) ;
if ( V_195 -> V_203 < F_65 ( V_114 ) ) {
V_27 = - V_33 ;
goto V_198;
}
if ( ! F_73 ( V_191 -> V_211 , V_212 ) ) {
V_27 = - V_213 ;
goto V_198;
}
if ( V_195 -> V_200 == V_168 ) {
V_25 -> V_216 += V_114 ;
V_25 -> V_215 = V_197 ;
} else {
V_25 -> V_214 += V_114 ;
V_25 -> V_218 = V_197 ;
}
break;
case V_184 :
case V_170 :
if ( V_195 -> V_203 < F_65 ( sizeof( struct V_182 ) ) ) {
V_27 = - V_33 ;
goto V_198;
}
V_183 = (struct V_182 * ) F_66 ( V_195 ) ;
switch ( V_183 -> type ) {
#if F_74 ( V_219 )
case V_220 :
if ( V_183 -> V_185 != 2 ||
V_183 -> V_221 != 1 ) {
V_27 = - V_33 ;
goto V_198;
}
break;
#endif
default:
V_27 = - V_33 ;
goto V_198;
}
V_114 = ( ( V_183 -> V_185 + 1 ) << 3 ) ;
if ( V_195 -> V_203 < F_65 ( V_114 ) ) {
V_27 = - V_33 ;
goto V_198;
}
if ( ( V_183 -> V_185 >> 1 ) != V_183 -> V_221 ) {
V_27 = - V_33 ;
goto V_198;
}
V_25 -> V_214 += V_114 ;
V_25 -> V_164 = V_183 ;
if ( V_195 -> V_200 == V_184 && V_25 -> V_215 ) {
int V_222 = ( ( V_25 -> V_215 -> V_185 + 1 ) << 3 ) ;
V_25 -> V_214 += V_222 ;
V_25 -> V_218 = V_25 -> V_215 ;
V_25 -> V_215 = NULL ;
V_25 -> V_216 -= V_222 ;
}
break;
case V_175 :
case V_151 :
if ( V_195 -> V_203 != F_65 ( sizeof( int ) ) ) {
V_27 = - V_33 ;
goto V_198;
}
* V_192 = * ( int * ) F_66 ( V_195 ) ;
if ( * V_192 < - 1 || * V_192 > 0xff ) {
V_27 = - V_33 ;
goto V_198;
}
break;
case V_154 :
{
int V_223 ;
V_27 = - V_33 ;
if ( V_195 -> V_203 != F_65 ( sizeof( int ) ) )
goto V_198;
V_223 = * ( int * ) F_66 ( V_195 ) ;
if ( V_223 < - 1 || V_223 > 0xff )
goto V_198;
V_27 = 0 ;
* V_153 = V_223 ;
break;
}
case V_224 :
{
int V_225 ;
V_27 = - V_33 ;
if ( V_195 -> V_203 != F_65 ( sizeof( int ) ) )
goto V_198;
V_225 = * ( int * ) F_66 ( V_195 ) ;
if ( V_225 < 0 || V_225 > 1 )
goto V_198;
V_27 = 0 ;
* V_193 = V_225 ;
break;
}
default:
F_75 ( V_226 L_1 ,
V_195 -> V_200 ) ;
V_27 = - V_33 ;
goto V_198;
}
}
V_198:
return V_27 ;
}
void F_76 ( struct V_227 * V_228 , struct V_4 * V_229 ,
T_4 V_230 , T_4 V_231 , int V_232 )
{
struct V_13 * V_14 = F_5 ( V_229 ) ;
const struct V_1 * V_233 , * V_234 ;
V_233 = & V_14 -> V_15 ;
V_234 = & V_14 -> V_54 ;
F_77 ( V_228 ,
L_2
L_3 ,
V_232 ,
V_234 -> V_3 [ 0 ] , V_234 -> V_3 [ 1 ] ,
V_234 -> V_3 [ 2 ] , V_234 -> V_3 [ 3 ] , V_230 ,
V_233 -> V_3 [ 0 ] , V_233 -> V_3 [ 1 ] ,
V_233 -> V_3 [ 2 ] , V_233 -> V_3 [ 3 ] , V_231 ,
V_229 -> V_73 ,
F_78 ( V_229 ) ,
F_79 ( V_229 ) ,
0 , 0L , 0 ,
F_80 ( F_81 ( V_228 ) , F_82 ( V_229 ) ) ,
0 ,
F_83 ( V_229 ) ,
F_84 ( & V_229 -> V_235 ) , V_229 ,
F_84 ( & V_229 -> V_236 ) ) ;
}
