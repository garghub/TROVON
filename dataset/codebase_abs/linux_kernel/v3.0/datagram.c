int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) V_4 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_2 ) ;
struct V_12 * V_13 , * V_14 , V_15 ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
struct V_20 * V_21 = NULL ;
struct V_22 * V_23 ;
int V_24 ;
int V_25 ;
if ( V_7 -> V_26 == V_27 ) {
if ( F_4 ( V_2 ) )
return - V_28 ;
V_25 = F_5 ( V_2 , V_4 , V_5 ) ;
goto V_29;
}
if ( V_5 < V_30 )
return - V_31 ;
if ( V_7 -> V_26 != V_32 )
return - V_28 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
if ( V_11 -> V_33 ) {
V_19 . V_21 = V_7 -> V_34 & V_35 ;
if ( V_19 . V_21 & V_36 ) {
V_21 = F_6 ( V_2 , V_19 . V_21 ) ;
if ( V_21 == NULL )
return - V_31 ;
F_7 ( & V_7 -> V_37 , & V_21 -> V_17 ) ;
}
}
V_24 = F_8 ( & V_7 -> V_37 ) ;
if ( V_24 == V_38 ) {
V_7 -> V_37 . V_39 [ 15 ] = 0x01 ;
}
V_13 = & V_7 -> V_37 ;
if ( V_24 == V_40 ) {
struct V_41 sin ;
if ( F_4 ( V_2 ) ) {
V_25 = - V_42 ;
goto V_43;
}
sin . V_44 = V_27 ;
sin . V_45 . V_46 = V_13 -> V_47 [ 3 ] ;
sin . V_48 = V_7 -> V_49 ;
V_25 = F_5 ( V_2 ,
(struct V_3 * ) & sin ,
sizeof( sin ) ) ;
V_29:
if ( V_25 )
goto V_43;
F_9 ( V_9 -> V_50 , & V_11 -> V_13 ) ;
if ( F_10 ( & V_11 -> V_51 ) )
F_9 ( V_9 -> V_52 , & V_11 -> V_51 ) ;
if ( F_10 ( & V_11 -> V_53 ) ) {
F_9 ( V_9 -> V_54 ,
& V_11 -> V_53 ) ;
if ( V_2 -> V_55 -> V_56 )
V_2 -> V_55 -> V_56 ( V_2 ) ;
}
goto V_43;
}
if ( V_24 & V_57 ) {
if ( V_5 >= sizeof( struct V_6 ) &&
V_7 -> V_58 ) {
if ( V_2 -> V_59 &&
V_2 -> V_59 != V_7 -> V_58 ) {
V_25 = - V_31 ;
goto V_43;
}
V_2 -> V_59 = V_7 -> V_58 ;
}
if ( ! V_2 -> V_59 && ( V_24 & V_60 ) )
V_2 -> V_59 = V_11 -> V_61 ;
if ( ! V_2 -> V_59 ) {
V_25 = - V_31 ;
goto V_43;
}
}
F_7 ( & V_11 -> V_13 , V_13 ) ;
V_11 -> V_62 = V_19 . V_21 ;
V_9 -> V_63 = V_7 -> V_49 ;
V_19 . V_64 = V_2 -> V_65 ;
F_7 ( & V_19 . V_13 , & V_11 -> V_13 ) ;
F_7 ( & V_19 . V_51 , & V_11 -> V_51 ) ;
V_19 . V_66 = V_2 -> V_59 ;
V_19 . V_67 = V_2 -> V_68 ;
V_19 . V_69 = V_9 -> V_63 ;
V_19 . V_70 = V_9 -> V_71 ;
if ( ! V_19 . V_66 && ( V_24 & V_60 ) )
V_19 . V_66 = V_11 -> V_61 ;
F_11 ( V_2 , F_12 ( & V_19 ) ) ;
V_23 = V_21 ? V_21 -> V_23 : V_11 -> V_23 ;
V_14 = F_13 ( & V_19 , V_23 , & V_15 ) ;
V_17 = F_14 ( V_2 , & V_19 , V_14 , true ) ;
V_25 = 0 ;
if ( F_15 ( V_17 ) ) {
V_25 = F_16 ( V_17 ) ;
goto V_43;
}
if ( F_10 ( & V_11 -> V_51 ) )
F_7 ( & V_11 -> V_51 , & V_19 . V_51 ) ;
if ( F_10 ( & V_11 -> V_53 ) ) {
F_7 ( & V_11 -> V_53 , & V_19 . V_51 ) ;
V_9 -> V_54 = V_72 ;
if ( V_2 -> V_55 -> V_56 )
V_2 -> V_55 -> V_56 ( V_2 ) ;
}
F_17 ( V_2 , V_17 ,
F_18 ( & V_19 . V_13 , & V_11 -> V_13 ) ?
& V_11 -> V_13 : NULL ,
#ifdef F_19
F_18 ( & V_19 . V_51 , & V_11 -> V_51 ) ?
& V_11 -> V_51 :
#endif
NULL ) ;
V_2 -> V_73 = V_74 ;
V_43:
F_20 ( V_21 ) ;
return V_25 ;
}
void F_21 ( struct V_1 * V_2 , struct V_75 * V_76 , int V_25 ,
T_1 V_77 , T_2 V_78 , T_3 * V_79 )
{
struct V_10 * V_11 = F_3 ( V_2 ) ;
struct V_80 * V_81 = F_22 ( V_76 ) ;
struct V_82 * V_83 ;
if ( ! V_11 -> V_84 )
return;
V_76 = F_23 ( V_76 , V_85 ) ;
if ( ! V_76 )
return;
V_76 -> V_86 = F_24 ( V_87 ) ;
V_83 = F_25 ( V_76 ) ;
V_83 -> V_88 . V_89 = V_25 ;
V_83 -> V_88 . V_90 = V_91 ;
V_83 -> V_88 . V_92 = V_81 -> V_93 ;
V_83 -> V_88 . V_94 = V_81 -> V_95 ;
V_83 -> V_88 . V_96 = 0 ;
V_83 -> V_88 . V_97 = V_78 ;
V_83 -> V_88 . V_98 = 0 ;
V_83 -> V_99 = ( T_3 * ) & ( ( (struct V_100 * ) ( V_81 + 1 ) ) -> V_13 ) -
F_26 ( V_76 ) ;
V_83 -> V_77 = V_77 ;
F_27 ( V_76 , V_79 - V_76 -> V_101 ) ;
F_28 ( V_76 ) ;
if ( F_29 ( V_2 , V_76 ) )
F_30 ( V_76 ) ;
}
void F_31 ( struct V_1 * V_2 , int V_25 , struct V_18 * V_19 , T_2 V_78 )
{
struct V_10 * V_11 = F_3 ( V_2 ) ;
struct V_82 * V_83 ;
struct V_100 * V_102 ;
struct V_75 * V_76 ;
if ( ! V_11 -> V_84 )
return;
V_76 = F_32 ( sizeof( struct V_100 ) , V_85 ) ;
if ( ! V_76 )
return;
V_76 -> V_86 = F_24 ( V_87 ) ;
F_33 ( V_76 , sizeof( struct V_100 ) ) ;
F_34 ( V_76 ) ;
V_102 = F_35 ( V_76 ) ;
F_7 ( & V_102 -> V_13 , & V_19 -> V_13 ) ;
V_83 = F_25 ( V_76 ) ;
V_83 -> V_88 . V_89 = V_25 ;
V_83 -> V_88 . V_90 = V_103 ;
V_83 -> V_88 . V_92 = 0 ;
V_83 -> V_88 . V_94 = 0 ;
V_83 -> V_88 . V_96 = 0 ;
V_83 -> V_88 . V_97 = V_78 ;
V_83 -> V_88 . V_98 = 0 ;
V_83 -> V_99 = ( T_3 * ) & V_102 -> V_13 - F_26 ( V_76 ) ;
V_83 -> V_77 = V_19 -> V_69 ;
F_27 ( V_76 , F_36 ( V_76 ) - V_76 -> V_101 ) ;
F_28 ( V_76 ) ;
if ( F_29 ( V_2 , V_76 ) )
F_30 ( V_76 ) ;
}
void F_37 ( struct V_1 * V_2 , struct V_18 * V_19 , T_2 V_104 )
{
struct V_10 * V_11 = F_3 ( V_2 ) ;
struct V_100 * V_102 ;
struct V_75 * V_76 ;
struct V_105 * V_106 ;
if ( ! V_11 -> V_107 . V_108 . V_109 )
return;
V_76 = F_32 ( sizeof( struct V_100 ) , V_85 ) ;
if ( ! V_76 )
return;
F_33 ( V_76 , sizeof( struct V_100 ) ) ;
F_34 ( V_76 ) ;
V_102 = F_35 ( V_76 ) ;
F_7 ( & V_102 -> V_13 , & V_19 -> V_13 ) ;
V_106 = F_38 ( V_76 ) ;
if ( ! V_106 ) {
F_30 ( V_76 ) ;
return;
}
V_106 -> V_110 = V_104 ;
V_106 -> V_111 . V_26 = V_32 ;
V_106 -> V_111 . V_49 = 0 ;
V_106 -> V_111 . V_34 = 0 ;
V_106 -> V_111 . V_58 = V_19 -> V_66 ;
F_7 ( & V_106 -> V_111 . V_37 , & F_35 ( V_76 ) -> V_13 ) ;
F_27 ( V_76 , F_36 ( V_76 ) - V_76 -> V_101 ) ;
F_28 ( V_76 ) ;
V_76 = F_39 ( & V_11 -> V_109 , V_76 ) ;
F_30 ( V_76 ) ;
}
int F_40 ( struct V_1 * V_2 , struct V_112 * V_113 , int V_114 )
{
struct V_10 * V_11 = F_3 ( V_2 ) ;
struct V_82 * V_83 ;
struct V_75 * V_76 , * V_115 ;
struct V_6 * sin ;
struct {
struct V_116 V_88 ;
struct V_6 V_117 ;
} V_118 ;
int V_25 ;
int V_119 ;
V_25 = - V_120 ;
V_76 = F_41 ( & V_2 -> V_121 ) ;
if ( V_76 == NULL )
goto V_43;
V_119 = V_76 -> V_114 ;
if ( V_119 > V_114 ) {
V_113 -> V_122 |= V_123 ;
V_119 = V_114 ;
}
V_25 = F_42 ( V_76 , 0 , V_113 -> V_124 , V_119 ) ;
if ( V_25 )
goto V_125;
F_43 ( V_113 , V_2 , V_76 ) ;
V_83 = F_25 ( V_76 ) ;
sin = (struct V_6 * ) V_113 -> V_126 ;
if ( sin ) {
const unsigned char * V_127 = F_26 ( V_76 ) ;
sin -> V_26 = V_32 ;
sin -> V_34 = 0 ;
sin -> V_49 = V_83 -> V_77 ;
sin -> V_58 = 0 ;
if ( V_76 -> V_86 == F_24 ( V_87 ) ) {
F_7 ( & sin -> V_37 ,
(struct V_12 * ) ( V_127 + V_83 -> V_99 ) ) ;
if ( V_11 -> V_33 )
sin -> V_34 =
( * ( V_128 * ) ( V_127 + V_83 -> V_99 - 24 ) &
V_35 ) ;
if ( F_8 ( & sin -> V_37 ) & V_57 )
sin -> V_58 = F_44 ( V_76 ) -> V_129 ;
} else {
F_9 ( * ( V_128 * ) ( V_127 + V_83 -> V_99 ) ,
& sin -> V_37 ) ;
}
}
memcpy ( & V_118 . V_88 , & V_83 -> V_88 , sizeof( struct V_116 ) ) ;
sin = & V_118 . V_117 ;
sin -> V_26 = V_130 ;
if ( V_83 -> V_88 . V_90 != V_103 ) {
sin -> V_26 = V_32 ;
sin -> V_34 = 0 ;
sin -> V_58 = 0 ;
if ( V_76 -> V_86 == F_24 ( V_87 ) ) {
F_7 ( & sin -> V_37 , & F_35 ( V_76 ) -> V_51 ) ;
if ( V_11 -> V_107 . V_131 )
F_45 ( V_2 , V_113 , V_76 ) ;
if ( F_8 ( & sin -> V_37 ) & V_57 )
sin -> V_58 = F_44 ( V_76 ) -> V_129 ;
} else {
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_9 ( F_46 ( V_76 ) -> V_51 ,
& sin -> V_37 ) ;
if ( V_9 -> V_132 )
F_47 ( V_113 , V_76 ) ;
}
}
F_48 ( V_113 , V_133 , V_134 , sizeof( V_118 ) , & V_118 ) ;
V_113 -> V_122 |= V_135 ;
V_25 = V_119 ;
F_49 ( & V_2 -> V_121 . V_136 ) ;
V_2 -> V_137 = 0 ;
if ( ( V_115 = F_50 ( & V_2 -> V_121 ) ) != NULL ) {
V_2 -> V_137 = F_25 ( V_115 ) -> V_88 . V_89 ;
F_51 ( & V_2 -> V_121 . V_136 ) ;
V_2 -> V_138 ( V_2 ) ;
} else {
F_51 ( & V_2 -> V_121 . V_136 ) ;
}
V_125:
F_30 ( V_76 ) ;
V_43:
return V_25 ;
}
int F_52 ( struct V_1 * V_2 , struct V_112 * V_113 , int V_114 )
{
struct V_10 * V_11 = F_3 ( V_2 ) ;
struct V_75 * V_76 ;
struct V_6 * sin ;
struct V_105 V_106 ;
int V_25 ;
int V_119 ;
V_25 = - V_120 ;
V_76 = F_39 ( & V_11 -> V_109 , NULL ) ;
if ( V_76 == NULL )
goto V_43;
V_119 = V_76 -> V_114 ;
if ( V_119 > V_114 ) {
V_113 -> V_122 |= V_123 ;
V_119 = V_114 ;
}
V_25 = F_42 ( V_76 , 0 , V_113 -> V_124 , V_119 ) ;
if ( V_25 )
goto V_125;
F_43 ( V_113 , V_2 , V_76 ) ;
memcpy ( & V_106 , F_38 ( V_76 ) , sizeof( V_106 ) ) ;
sin = (struct V_6 * ) V_113 -> V_126 ;
if ( sin ) {
sin -> V_26 = V_32 ;
sin -> V_34 = 0 ;
sin -> V_49 = 0 ;
sin -> V_58 = V_106 . V_111 . V_58 ;
F_7 ( & sin -> V_37 , & V_106 . V_111 . V_37 ) ;
}
F_48 ( V_113 , V_133 , V_139 , sizeof( V_106 ) , & V_106 ) ;
V_25 = V_119 ;
V_125:
F_30 ( V_76 ) ;
V_43:
return V_25 ;
}
int F_45 ( struct V_1 * V_2 , struct V_112 * V_113 , struct V_75 * V_76 )
{
struct V_10 * V_11 = F_3 ( V_2 ) ;
struct V_140 * V_23 = F_44 ( V_76 ) ;
unsigned char * V_127 = F_26 ( V_76 ) ;
if ( V_11 -> V_107 . V_108 . V_141 ) {
struct V_142 V_143 ;
V_143 . V_144 = V_23 -> V_129 ;
F_7 ( & V_143 . V_145 , & F_35 ( V_76 ) -> V_13 ) ;
F_48 ( V_113 , V_133 , V_146 , sizeof( V_143 ) , & V_143 ) ;
}
if ( V_11 -> V_107 . V_108 . V_147 ) {
int V_148 = F_35 ( V_76 ) -> V_149 ;
F_48 ( V_113 , V_133 , V_150 , sizeof( V_148 ) , & V_148 ) ;
}
if ( V_11 -> V_107 . V_108 . V_151 ) {
int V_152 = ( F_53 ( * ( V_128 * ) F_35 ( V_76 ) ) >> 20 ) & 0xff ;
F_48 ( V_113 , V_133 , V_153 , sizeof( V_152 ) , & V_152 ) ;
}
if ( V_11 -> V_107 . V_108 . V_154 && ( * ( V_128 * ) V_127 & V_35 ) ) {
V_128 V_155 = * ( V_128 * ) V_127 & V_35 ;
F_48 ( V_113 , V_133 , V_156 , sizeof( V_155 ) , & V_155 ) ;
}
if ( V_11 -> V_107 . V_108 . V_157 && V_23 -> V_158 ) {
T_3 * V_159 = V_127 + V_23 -> V_158 ;
F_48 ( V_113 , V_133 , V_160 , ( V_159 [ 1 ] + 1 ) << 3 , V_159 ) ;
}
if ( V_23 -> V_161 &&
( V_11 -> V_107 . V_108 . V_162 || V_11 -> V_107 . V_108 . V_163 ) ) {
unsigned int V_164 = sizeof( struct V_100 ) ;
T_3 V_165 = F_35 ( V_76 ) -> V_165 ;
while ( V_164 <= V_23 -> V_161 ) {
unsigned V_114 ;
T_3 * V_159 = V_127 + V_164 ;
switch( V_165 ) {
case V_166 :
V_165 = V_159 [ 0 ] ;
V_114 = ( V_159 [ 1 ] + 1 ) << 3 ;
if ( V_11 -> V_107 . V_108 . V_162 )
F_48 ( V_113 , V_133 , V_167 , V_114 , V_159 ) ;
break;
case V_168 :
V_165 = V_159 [ 0 ] ;
V_114 = ( V_159 [ 1 ] + 1 ) << 3 ;
if ( V_11 -> V_107 . V_108 . V_163 )
F_48 ( V_113 , V_133 , V_169 , V_114 , V_159 ) ;
break;
case V_170 :
V_165 = V_159 [ 0 ] ;
V_114 = ( V_159 [ 1 ] + 2 ) << 2 ;
break;
default:
V_165 = V_159 [ 0 ] ;
V_114 = ( V_159 [ 1 ] + 1 ) << 3 ;
break;
}
V_164 += V_114 ;
}
}
if ( V_11 -> V_107 . V_108 . V_171 ) {
struct V_142 V_143 ;
V_143 . V_144 = V_23 -> V_129 ;
F_7 ( & V_143 . V_145 , & F_35 ( V_76 ) -> V_13 ) ;
F_48 ( V_113 , V_133 , V_172 , sizeof( V_143 ) , & V_143 ) ;
}
if ( V_11 -> V_107 . V_108 . V_173 ) {
int V_148 = F_35 ( V_76 ) -> V_149 ;
F_48 ( V_113 , V_133 , V_174 , sizeof( V_148 ) , & V_148 ) ;
}
if ( V_11 -> V_107 . V_108 . V_175 && V_23 -> V_158 ) {
T_3 * V_159 = V_127 + V_23 -> V_158 ;
F_48 ( V_113 , V_133 , V_176 , ( V_159 [ 1 ] + 1 ) << 3 , V_159 ) ;
}
if ( V_11 -> V_107 . V_108 . V_177 && V_23 -> V_178 ) {
T_3 * V_159 = V_127 + V_23 -> V_178 ;
F_48 ( V_113 , V_133 , V_179 , ( V_159 [ 1 ] + 1 ) << 3 , V_159 ) ;
}
if ( V_11 -> V_107 . V_108 . V_180 && V_23 -> V_163 ) {
struct V_181 * V_182 = (struct V_181 * ) ( V_127 + V_23 -> V_163 ) ;
F_48 ( V_113 , V_133 , V_183 , ( V_182 -> V_184 + 1 ) << 3 , V_182 ) ;
}
if ( V_11 -> V_107 . V_108 . V_177 && V_23 -> V_185 ) {
T_3 * V_159 = V_127 + V_23 -> V_185 ;
F_48 ( V_113 , V_133 , V_179 , ( V_159 [ 1 ] + 1 ) << 3 , V_159 ) ;
}
if ( V_11 -> V_107 . V_108 . V_186 ) {
struct V_6 V_187 ;
T_4 * V_188 = ( T_4 * ) F_54 ( V_76 ) ;
if ( F_55 ( V_76 ) + 4 <= V_76 -> V_114 ) {
V_187 . V_26 = V_32 ;
F_7 ( & V_187 . V_37 , & F_35 ( V_76 ) -> V_13 ) ;
V_187 . V_49 = V_188 [ 1 ] ;
V_187 . V_34 = 0 ;
V_187 . V_58 = 0 ;
F_48 ( V_113 , V_133 , V_189 , sizeof( V_187 ) , & V_187 ) ;
}
}
return 0 ;
}
int F_56 ( struct V_190 * V_190 ,
struct V_112 * V_113 , struct V_18 * V_19 ,
struct V_22 * V_23 ,
int * V_191 , int * V_152 , int * V_192 )
{
struct V_142 * V_143 ;
struct V_193 * V_194 ;
struct V_181 * V_182 ;
struct V_195 * V_196 ;
int V_114 ;
int V_25 = 0 ;
for ( V_194 = F_57 ( V_113 ) ; V_194 ; V_194 = F_58 ( V_113 , V_194 ) ) {
int V_24 ;
if ( ! F_59 ( V_113 , V_194 ) ) {
V_25 = - V_31 ;
goto V_197;
}
if ( V_194 -> V_198 != V_133 )
continue;
switch ( V_194 -> V_199 ) {
case V_146 :
case V_172 :
{
struct V_200 * V_201 = NULL ;
if ( V_194 -> V_202 < F_60 ( sizeof( struct V_142 ) ) ) {
V_25 = - V_31 ;
goto V_197;
}
V_143 = (struct V_142 * ) F_61 ( V_194 ) ;
if ( V_143 -> V_144 ) {
if ( V_19 -> V_66 &&
V_143 -> V_144 != V_19 -> V_66 )
return - V_31 ;
V_19 -> V_66 = V_143 -> V_144 ;
}
V_24 = F_62 ( & V_143 -> V_145 ) ;
F_63 () ;
if ( V_19 -> V_66 ) {
V_201 = F_64 ( V_190 , V_19 -> V_66 ) ;
if ( ! V_201 ) {
F_65 () ;
return - V_203 ;
}
} else if ( V_24 & V_57 ) {
F_65 () ;
return - V_31 ;
}
if ( V_24 != V_38 ) {
int V_204 = F_66 ( V_24 ) <= V_205 ;
if ( ! F_67 ( V_190 , & V_143 -> V_145 ,
V_204 ? V_201 : NULL , 0 ) )
V_25 = - V_31 ;
else
F_7 ( & V_19 -> V_51 , & V_143 -> V_145 ) ;
}
F_65 () ;
if ( V_25 )
goto V_197;
break;
}
case V_156 :
if ( V_194 -> V_202 < F_60 ( 4 ) ) {
V_25 = - V_31 ;
goto V_197;
}
if ( V_19 -> V_21 & V_35 ) {
if ( ( V_19 -> V_21 ^ * ( V_128 * ) F_61 ( V_194 ) ) & ~ V_35 ) {
V_25 = - V_31 ;
goto V_197;
}
}
V_19 -> V_21 = V_35 & * ( V_128 * ) F_61 ( V_194 ) ;
break;
case V_176 :
case V_160 :
if ( V_23 -> V_206 || V_194 -> V_202 < F_60 ( sizeof( struct V_195 ) ) ) {
V_25 = - V_31 ;
goto V_197;
}
V_196 = (struct V_195 * ) F_61 ( V_194 ) ;
V_114 = ( ( V_196 -> V_184 + 1 ) << 3 ) ;
if ( V_194 -> V_202 < F_60 ( V_114 ) ) {
V_25 = - V_31 ;
goto V_197;
}
if ( ! F_68 ( V_207 ) ) {
V_25 = - V_208 ;
goto V_197;
}
V_23 -> V_209 += V_114 ;
V_23 -> V_206 = V_196 ;
break;
case V_179 :
if ( V_194 -> V_202 < F_60 ( sizeof( struct V_195 ) ) ) {
V_25 = - V_31 ;
goto V_197;
}
V_196 = (struct V_195 * ) F_61 ( V_194 ) ;
V_114 = ( ( V_196 -> V_184 + 1 ) << 3 ) ;
if ( V_194 -> V_202 < F_60 ( V_114 ) ) {
V_25 = - V_31 ;
goto V_197;
}
if ( ! F_68 ( V_207 ) ) {
V_25 = - V_208 ;
goto V_197;
}
if ( V_23 -> V_210 ) {
V_25 = - V_31 ;
goto V_197;
}
V_23 -> V_211 += V_114 ;
V_23 -> V_210 = V_196 ;
break;
case V_167 :
case V_212 :
if ( V_194 -> V_202 < F_60 ( sizeof( struct V_195 ) ) ) {
V_25 = - V_31 ;
goto V_197;
}
V_196 = (struct V_195 * ) F_61 ( V_194 ) ;
V_114 = ( ( V_196 -> V_184 + 1 ) << 3 ) ;
if ( V_194 -> V_202 < F_60 ( V_114 ) ) {
V_25 = - V_31 ;
goto V_197;
}
if ( ! F_68 ( V_207 ) ) {
V_25 = - V_208 ;
goto V_197;
}
if ( V_194 -> V_199 == V_167 ) {
V_23 -> V_211 += V_114 ;
V_23 -> V_210 = V_196 ;
} else {
V_23 -> V_209 += V_114 ;
V_23 -> V_213 = V_196 ;
}
break;
case V_183 :
case V_169 :
if ( V_194 -> V_202 < F_60 ( sizeof( struct V_181 ) ) ) {
V_25 = - V_31 ;
goto V_197;
}
V_182 = (struct V_181 * ) F_61 ( V_194 ) ;
switch ( V_182 -> type ) {
#if F_69 ( V_214 ) || F_69 ( V_215 )
case V_216 :
if ( V_182 -> V_184 != 2 ||
V_182 -> V_217 != 1 ) {
V_25 = - V_31 ;
goto V_197;
}
break;
#endif
default:
V_25 = - V_31 ;
goto V_197;
}
V_114 = ( ( V_182 -> V_184 + 1 ) << 3 ) ;
if ( V_194 -> V_202 < F_60 ( V_114 ) ) {
V_25 = - V_31 ;
goto V_197;
}
if ( ( V_182 -> V_184 >> 1 ) != V_182 -> V_217 ) {
V_25 = - V_31 ;
goto V_197;
}
V_23 -> V_209 += V_114 ;
V_23 -> V_163 = V_182 ;
if ( V_194 -> V_199 == V_183 && V_23 -> V_210 ) {
int V_218 = ( ( V_23 -> V_210 -> V_184 + 1 ) << 3 ) ;
V_23 -> V_209 += V_218 ;
V_23 -> V_213 = V_23 -> V_210 ;
V_23 -> V_210 = NULL ;
V_23 -> V_211 -= V_218 ;
}
break;
case V_174 :
case V_150 :
if ( V_194 -> V_202 != F_60 ( sizeof( int ) ) ) {
V_25 = - V_31 ;
goto V_197;
}
* V_191 = * ( int * ) F_61 ( V_194 ) ;
if ( * V_191 < - 1 || * V_191 > 0xff ) {
V_25 = - V_31 ;
goto V_197;
}
break;
case V_153 :
{
int V_219 ;
V_25 = - V_31 ;
if ( V_194 -> V_202 != F_60 ( sizeof( int ) ) ) {
goto V_197;
}
V_219 = * ( int * ) F_61 ( V_194 ) ;
if ( V_219 < - 1 || V_219 > 0xff )
goto V_197;
V_25 = 0 ;
* V_152 = V_219 ;
break;
}
case V_220 :
{
int V_221 ;
V_25 = - V_31 ;
if ( V_194 -> V_202 != F_60 ( sizeof( int ) ) ) {
goto V_197;
}
V_221 = * ( int * ) F_61 ( V_194 ) ;
if ( V_221 < 0 || V_221 > 1 )
goto V_197;
V_25 = 0 ;
* V_192 = V_221 ;
break;
}
default:
F_70 ( V_222 L_1 ,
V_194 -> V_199 ) ;
V_25 = - V_31 ;
goto V_197;
}
}
V_197:
return V_25 ;
}
