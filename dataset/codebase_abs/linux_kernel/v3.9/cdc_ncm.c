static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 , V_6 -> V_8 , sizeof( V_4 -> V_7 ) ) ;
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_11 , V_6 -> V_12 -> V_13 ,
sizeof( V_4 -> V_11 ) ) ;
F_4 ( V_6 -> V_14 , V_4 -> V_15 , sizeof( V_4 -> V_15 ) ) ;
}
static T_1 F_5 ( struct V_16 * V_17 )
{
T_2 V_18 ;
T_1 V_19 ;
T_1 V_20 ;
int V_21 ;
int V_22 ;
T_3 V_23 ;
T_2 V_24 ;
T_2 V_25 ;
struct V_5 * V_6 = F_2 ( V_17 -> V_26 ) ;
V_20 = V_17 -> V_27 -> V_28 -> V_29 . V_30 ;
V_21 = F_6 ( V_6 , V_31 ,
V_32 | V_33
| V_34 ,
0 , V_20 , & V_17 -> V_35 ,
sizeof( V_17 -> V_35 ) ) ;
if ( V_21 < 0 ) {
F_7 ( L_1 ) ;
return 1 ;
}
V_17 -> V_36 = F_8 ( V_17 -> V_35 . V_37 ) ;
V_17 -> V_38 = F_8 ( V_17 -> V_35 . V_39 ) ;
V_17 -> V_40 = F_9 ( V_17 -> V_35 . V_41 ) ;
V_17 -> V_42 = F_9 ( V_17 -> V_35 . V_43 ) ;
V_17 -> V_44 = F_9 ( V_17 -> V_35 . V_45 ) ;
V_17 -> V_46 = F_9 ( V_17 -> V_35 . V_47 ) ;
V_23 = F_9 ( V_17 -> V_35 . V_48 ) ;
V_22 = V_49 ;
V_24 = V_50 ;
V_25 = V_51 ;
if ( V_17 -> V_52 != NULL ) {
V_19 = V_17 -> V_52 -> V_53 ;
V_22 = 0 ;
V_24 = V_54 ;
V_25 = 0 ;
} else if ( V_17 -> V_55 != NULL ) {
V_19 = V_17 -> V_55 -> V_53 ;
} else {
V_19 = 0 ;
}
F_7 ( L_2
L_3
L_4 ,
V_17 -> V_36 , V_17 -> V_38 , V_17 -> V_40 , V_17 -> V_42 ,
V_17 -> V_44 , V_17 -> V_46 , V_19 ) ;
if ( ( V_17 -> V_46 == 0 ) ||
( V_17 -> V_46 > V_56 ) )
V_17 -> V_46 = V_56 ;
if ( V_17 -> V_36 < V_57 ) {
F_7 ( L_5 ,
V_57 ) ;
V_17 -> V_36 = V_57 ;
}
if ( V_17 -> V_36 > V_58 ) {
F_7 ( L_6 ,
V_58 ) ;
V_17 -> V_36 = V_58 ;
}
if ( V_17 -> V_36 != F_8 ( V_17 -> V_35 . V_37 ) ) {
T_4 V_37 = F_10 ( V_17 -> V_36 ) ;
V_21 = F_11 ( V_6 , V_59 ,
V_32 | V_60
| V_34 ,
0 , V_20 , & V_37 , 4 ) ;
if ( V_21 < 0 )
F_7 ( L_7 ) ;
}
if ( ( V_17 -> V_38 <
( V_25 + V_24 ) ) ||
( V_17 -> V_38 > V_61 ) ) {
F_7 ( L_8 ,
V_61 ) ;
V_17 -> V_38 = V_61 ;
}
V_18 = V_17 -> V_44 ;
if ( ( V_18 < V_62 ) ||
( V_18 != ( ( - V_18 ) & V_18 ) ) || ( V_18 >= V_17 -> V_38 ) ) {
F_7 ( L_9 ) ;
V_17 -> V_44 = V_62 ;
}
V_18 = V_17 -> V_42 ;
if ( ( V_18 < V_62 ) ||
( V_18 != ( ( - V_18 ) & V_18 ) ) || ( V_18 >= V_17 -> V_38 ) ) {
F_7 ( L_10 ) ;
V_17 -> V_42 = V_62 ;
}
if ( V_17 -> V_40 >= V_17 -> V_42 ) {
F_7 ( L_11 ) ;
V_17 -> V_40 = 0 ;
}
V_17 -> V_40 = ( ( V_17 -> V_40 - V_22 ) &
( V_17 -> V_42 - 1 ) ) ;
if ( V_19 & V_63 ) {
V_21 = F_11 ( V_6 , V_64 ,
V_32 | V_60
| V_34 ,
V_65 ,
V_20 , NULL , 0 ) ;
if ( V_21 < 0 )
F_7 ( L_12 ) ;
}
if ( V_23 & V_66 ) {
V_21 = F_11 ( V_6 , V_67 ,
V_32 | V_60
| V_34 ,
V_68 ,
V_20 , NULL , 0 ) ;
if ( V_21 < 0 )
F_7 ( L_13 ) ;
}
V_17 -> V_69 = V_24 ;
if ( V_19 & V_70 ) {
T_5 V_69 ;
T_3 V_71 ;
if ( V_17 -> V_72 != NULL )
V_71 = F_9 ( V_17 -> V_72 -> V_73 ) ;
else if ( V_17 -> V_52 != NULL )
V_71 = F_9 ( V_17 -> V_52 -> V_73 ) ;
else
goto V_74;
V_21 = F_6 ( V_6 , V_75 ,
V_32 | V_33
| V_34 ,
0 , V_20 , & V_69 , 2 ) ;
if ( V_21 < 0 ) {
F_7 ( L_14 ,
V_24 ) ;
} else {
V_17 -> V_69 =
F_9 ( V_69 ) ;
if ( V_17 -> V_69 > V_71 )
V_17 -> V_69 = V_71 ;
if ( V_17 -> V_69 > V_76 )
V_17 -> V_69 = V_76 ;
if ( V_17 -> V_69 < V_24 )
V_17 -> V_69 = V_24 ;
if ( V_17 -> V_69 !=
F_9 ( V_69 ) ) {
V_21 = F_11 ( V_6 ,
V_77 ,
V_32 | V_60
| V_34 ,
0 ,
V_20 , & V_69 ,
2 ) ;
if ( V_21 < 0 )
F_7 ( L_15 ) ;
}
}
}
V_74:
if ( V_17 -> V_26 -> V_78 != ( V_17 -> V_69 - V_22 ) )
V_17 -> V_26 -> V_78 = V_17 -> V_69 - V_22 ;
return 0 ;
}
static void
F_12 ( struct V_16 * V_17 , struct V_79 * V_80 )
{
struct V_81 * V_82 ;
T_1 V_83 ;
for ( V_83 = 0 ; V_83 < V_80 -> V_28 -> V_29 . V_84 ; V_83 ++ ) {
V_82 = V_80 -> V_28 -> V_85 + V_83 ;
switch ( V_82 -> V_29 . V_86 & V_87 ) {
case V_88 :
if ( F_13 ( & V_82 -> V_29 ) ) {
if ( V_17 -> V_89 == NULL )
V_17 -> V_89 = V_82 ;
}
break;
case V_90 :
if ( F_13 ( & V_82 -> V_29 ) ) {
if ( V_17 -> V_91 == NULL )
V_17 -> V_91 = V_82 ;
} else {
if ( V_17 -> V_92 == NULL )
V_17 -> V_92 = V_82 ;
}
break;
default:
break;
}
}
}
static void F_14 ( struct V_16 * V_17 )
{
if ( V_17 == NULL )
return;
if ( V_17 -> V_93 != NULL ) {
F_15 ( V_17 -> V_93 ) ;
V_17 -> V_93 = NULL ;
}
if ( V_17 -> V_94 != NULL ) {
F_15 ( V_17 -> V_94 ) ;
V_17 -> V_94 = NULL ;
}
F_16 ( V_17 ) ;
}
int F_17 ( struct V_5 * V_6 , struct V_79 * V_80 , T_1 V_95 )
{
struct V_16 * V_17 ;
struct V_96 * V_7 ;
T_1 * V_97 ;
int V_98 ;
int V_99 ;
T_1 V_20 ;
V_17 = F_18 ( sizeof( * V_17 ) , V_100 ) ;
if ( V_17 == NULL )
return - V_101 ;
F_19 ( & V_17 -> V_102 , V_103 , V_104 ) ;
V_17 -> V_102 . V_105 = & V_106 ;
V_17 -> V_107 . V_108 = ( unsigned long ) V_17 ;
V_17 -> V_107 . V_109 = V_110 ;
F_20 ( & V_17 -> V_111 , 0 ) ;
F_21 ( & V_17 -> V_112 ) ;
V_17 -> V_26 = V_6 -> V_2 ;
V_6 -> V_108 [ 0 ] = ( unsigned long ) V_17 ;
V_7 = F_22 ( V_80 ) ;
V_97 = V_80 -> V_28 -> V_113 ;
V_98 = V_80 -> V_28 -> V_114 ;
V_17 -> V_14 = V_6 -> V_14 ;
V_17 -> V_80 = V_80 ;
while ( ( V_98 > 0 ) && ( V_97 [ 0 ] > 2 ) && ( V_97 [ 0 ] <= V_98 ) ) {
if ( V_97 [ 1 ] != V_115 )
goto V_116;
switch ( V_97 [ 2 ] ) {
case V_117 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_118 ) ) )
break;
V_17 -> V_118 =
( const struct V_119 * ) V_97 ;
V_17 -> V_27 = F_23 ( V_6 -> V_14 ,
V_17 -> V_118 -> V_120 ) ;
V_17 -> V_108 = F_23 ( V_6 -> V_14 ,
V_17 -> V_118 -> V_121 ) ;
break;
case V_122 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_72 ) ) )
break;
V_17 -> V_72 =
( const struct V_123 * ) V_97 ;
V_6 -> V_124 =
F_9 ( V_17 -> V_72 -> V_73 ) ;
if ( V_6 -> V_124 < V_50 )
V_6 -> V_124 = V_50 ;
else if ( V_6 -> V_124 > V_76 )
V_6 -> V_124 = V_76 ;
break;
case V_125 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_55 ) ) )
break;
V_17 -> V_55 = ( const struct V_126 * ) V_97 ;
break;
case V_127 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_52 ) ) )
break;
V_17 -> V_52 = ( const struct V_128 * ) V_97 ;
break;
default:
break;
}
V_116:
V_99 = V_97 [ 0 ] ;
V_97 += V_99 ;
V_98 -= V_99 ;
}
if ( ! V_17 -> V_118 && V_80 -> V_129 && V_80 -> V_129 -> V_130 == 2 ) {
V_17 -> V_27 = V_80 ;
V_17 -> V_108 = F_23 ( V_6 -> V_14 , V_80 -> V_28 -> V_29 . V_30 + 1 ) ;
F_24 ( & V_80 -> V_6 , L_16 ) ;
}
if ( ( V_17 -> V_27 == NULL ) || ( V_17 -> V_108 == NULL ) ||
( ( ! V_17 -> V_52 ) && ( ( V_17 -> V_72 == NULL ) || ( V_17 -> V_27 != V_80 ) ) ) )
goto error;
if ( V_17 -> V_108 != V_17 -> V_27 ) {
V_99 = F_25 ( V_7 , V_17 -> V_108 , V_6 ) ;
if ( V_99 )
goto error;
}
V_20 = V_17 -> V_108 -> V_28 -> V_29 . V_30 ;
V_99 = F_26 ( V_6 -> V_14 , V_20 , 0 ) ;
if ( V_99 )
goto V_131;
if ( F_5 ( V_17 ) )
goto V_131;
V_99 = F_26 ( V_6 -> V_14 , V_20 , V_95 ) ;
if ( V_99 )
goto V_131;
F_12 ( V_17 , V_17 -> V_108 ) ;
F_12 ( V_17 , V_17 -> V_27 ) ;
if ( ( V_17 -> V_91 == NULL ) || ( V_17 -> V_92 == NULL ) ||
( V_17 -> V_89 == NULL ) )
goto V_131;
V_6 -> V_2 -> V_132 = & V_133 ;
F_27 ( V_17 -> V_108 , V_6 ) ;
F_27 ( V_17 -> V_27 , V_6 ) ;
F_27 ( V_17 -> V_80 , V_6 ) ;
if ( V_17 -> V_72 ) {
V_99 = F_28 ( V_6 , V_17 -> V_72 -> V_134 ) ;
if ( V_99 )
goto V_131;
F_29 ( & V_6 -> V_14 -> V_6 , L_17 , V_6 -> V_2 -> V_135 ) ;
}
V_6 -> V_136 = F_30 ( V_6 -> V_14 ,
V_17 -> V_91 -> V_29 . V_137 & V_138 ) ;
V_6 -> V_139 = F_31 ( V_6 -> V_14 ,
V_17 -> V_92 -> V_29 . V_137 & V_138 ) ;
V_6 -> V_140 = V_17 -> V_89 ;
V_6 -> V_141 = V_17 -> V_36 ;
V_17 -> V_142 = V_17 -> V_143 = 0 ;
return 0 ;
V_131:
F_27 ( V_17 -> V_27 , NULL ) ;
F_27 ( V_17 -> V_108 , NULL ) ;
if ( V_17 -> V_108 != V_17 -> V_27 )
F_32 ( V_7 , V_17 -> V_108 ) ;
error:
F_14 ( (struct V_16 * ) V_6 -> V_108 [ 0 ] ) ;
V_6 -> V_108 [ 0 ] = 0 ;
F_29 ( & V_6 -> V_14 -> V_6 , L_18 ) ;
return - V_101 ;
}
void F_33 ( struct V_5 * V_6 , struct V_79 * V_80 )
{
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
struct V_96 * V_7 = F_22 ( V_80 ) ;
if ( V_17 == NULL )
return;
F_20 ( & V_17 -> V_111 , 1 ) ;
if ( F_34 ( & V_17 -> V_102 ) )
F_35 ( & V_17 -> V_102 ) ;
F_36 ( & V_17 -> V_107 ) ;
if ( V_17 -> V_27 == V_17 -> V_108 )
V_17 -> V_108 = NULL ;
if ( V_80 == V_17 -> V_27 && V_17 -> V_108 ) {
F_27 ( V_17 -> V_108 , NULL ) ;
F_32 ( V_7 , V_17 -> V_108 ) ;
V_17 -> V_108 = NULL ;
} else if ( V_80 == V_17 -> V_108 && V_17 -> V_27 ) {
F_27 ( V_17 -> V_27 , NULL ) ;
F_32 ( V_7 , V_17 -> V_27 ) ;
V_17 -> V_27 = NULL ;
}
F_27 ( V_17 -> V_80 , NULL ) ;
F_14 ( V_17 ) ;
}
T_1 F_37 ( struct V_5 * V_6 , struct V_79 * V_80 )
{
struct V_144 * V_145 ;
if ( V_146 && V_80 -> V_147 == 2 ) {
V_145 = F_38 ( V_80 , V_148 ) ;
if ( V_145 && F_39 ( V_145 ) &&
! F_26 ( V_6 -> V_14 ,
V_80 -> V_28 -> V_29 . V_30 ,
V_148 ) )
return V_149 ;
}
return V_150 ;
}
static int F_40 ( struct V_5 * V_6 , struct V_79 * V_80 )
{
int V_151 ;
F_37 ( V_6 , V_80 ) ;
if ( F_39 ( V_80 -> V_28 ) )
return - V_101 ;
V_151 = F_17 ( V_6 , V_80 , 1 ) ;
F_41 ( V_6 -> V_2 ) ;
return V_151 ;
}
static void F_42 ( struct V_152 * V_153 , T_6 V_154 , T_6 V_155 , T_6 V_156 )
{
T_6 V_157 = F_43 ( V_153 -> V_98 , V_154 ) - V_153 -> V_98 + V_155 ;
if ( V_153 -> V_98 + V_157 > V_156 )
V_157 = V_156 - V_153 -> V_98 ;
if ( V_157 && F_44 ( V_153 ) >= V_157 )
memset ( F_45 ( V_153 , V_157 ) , 0 , V_157 ) ;
}
static struct V_158 * F_46 ( struct V_16 * V_17 , struct V_152 * V_153 , T_4 V_159 , T_6 V_160 )
{
struct V_158 * V_161 = NULL ;
struct V_162 * V_163 = ( void * ) V_153 -> V_108 ;
T_6 V_164 = F_9 ( V_163 -> V_165 ) ;
while ( V_164 ) {
V_161 = (struct V_158 * ) ( V_153 -> V_108 + V_164 ) ;
if ( V_161 -> V_166 == V_159 )
return V_161 ;
V_164 = F_9 ( V_161 -> V_167 ) ;
}
F_42 ( V_153 , V_17 -> V_44 , 0 , V_17 -> V_38 ) ;
if ( ( V_17 -> V_38 - V_153 -> V_98 - V_160 ) < V_168 )
return NULL ;
if ( V_161 )
V_161 -> V_167 = F_47 ( V_153 -> V_98 ) ;
else
V_163 -> V_165 = F_47 ( V_153 -> V_98 ) ;
V_161 = (struct V_158 * ) memset ( F_45 ( V_153 , V_168 ) , 0 , V_168 ) ;
V_161 -> V_166 = V_159 ;
V_161 -> V_169 = F_47 ( sizeof( struct V_158 ) + sizeof( struct V_170 ) ) ;
return V_161 ;
}
struct V_152 *
F_48 ( struct V_16 * V_17 , struct V_152 * V_153 , T_4 V_159 )
{
struct V_162 * V_163 ;
struct V_158 * V_161 ;
struct V_152 * V_171 ;
T_3 V_172 = 0 , V_173 , V_174 ;
T_1 V_175 = 0 ;
if ( V_153 != NULL ) {
F_49 ( V_153 , V_17 -> V_93 ) ;
F_49 ( V_159 , V_17 -> V_176 ) ;
} else {
V_175 = 1 ;
}
V_171 = V_17 -> V_94 ;
if ( ! V_171 ) {
V_171 = F_50 ( ( V_17 -> V_38 + 1 ) , V_177 ) ;
if ( V_171 == NULL ) {
if ( V_153 != NULL ) {
F_15 ( V_153 ) ;
V_17 -> V_26 -> V_178 . V_179 ++ ;
}
goto V_180;
}
V_163 = (struct V_162 * ) memset ( F_45 ( V_171 , sizeof( struct V_162 ) ) , 0 , sizeof( struct V_162 ) ) ;
V_163 -> V_166 = F_10 ( V_181 ) ;
V_163 -> V_182 = F_47 ( sizeof( struct V_162 ) ) ;
V_163 -> V_183 = F_47 ( V_17 -> V_184 ++ ) ;
V_17 -> V_185 = 0 ;
}
for ( V_172 = V_17 -> V_185 ; V_172 < V_17 -> V_46 ; V_172 ++ ) {
if ( V_153 == NULL ) {
V_153 = V_17 -> V_93 ;
V_159 = V_17 -> V_176 ;
V_17 -> V_93 = NULL ;
if ( V_153 == NULL )
break;
}
V_161 = F_46 ( V_17 , V_171 , V_159 , V_153 -> V_98 + V_17 -> V_42 + V_17 -> V_40 ) ;
F_42 ( V_171 , V_17 -> V_42 , V_17 -> V_40 , V_17 -> V_38 ) ;
if ( ! V_161 || V_171 -> V_98 + V_153 -> V_98 > V_17 -> V_38 ) {
if ( V_172 == 0 ) {
F_15 ( V_153 ) ;
V_153 = NULL ;
V_17 -> V_26 -> V_178 . V_179 ++ ;
} else {
if ( V_17 -> V_93 != NULL ) {
F_15 ( V_17 -> V_93 ) ;
V_17 -> V_26 -> V_178 . V_179 ++ ;
}
V_17 -> V_93 = V_153 ;
V_17 -> V_176 = V_159 ;
V_153 = NULL ;
V_175 = 1 ;
}
break;
}
V_174 = F_9 ( V_161 -> V_169 ) ;
V_173 = ( V_174 - sizeof( struct V_158 ) ) / sizeof( struct V_170 ) - 1 ;
V_161 -> V_186 [ V_173 ] . V_187 = F_47 ( V_153 -> V_98 ) ;
V_161 -> V_186 [ V_173 ] . V_188 = F_47 ( V_171 -> V_98 ) ;
V_161 -> V_169 = F_47 ( V_174 + sizeof( struct V_170 ) ) ;
memcpy ( F_45 ( V_171 , V_153 -> V_98 ) , V_153 -> V_108 , V_153 -> V_98 ) ;
F_15 ( V_153 ) ;
V_153 = NULL ;
if ( V_173 >= V_56 ) {
V_175 = 1 ;
break;
}
}
if ( V_153 != NULL ) {
F_15 ( V_153 ) ;
V_153 = NULL ;
V_17 -> V_26 -> V_178 . V_179 ++ ;
}
V_17 -> V_185 = V_172 ;
if ( V_172 == 0 ) {
V_17 -> V_94 = V_171 ;
goto V_180;
} else if ( ( V_172 < V_17 -> V_46 ) && ( V_175 == 0 ) ) {
V_17 -> V_94 = V_171 ;
if ( V_172 < V_189 )
V_17 -> V_190 = V_191 ;
goto V_180;
} else {
}
if ( V_171 -> V_98 > V_192 )
memset ( F_45 ( V_171 , V_17 -> V_38 - V_171 -> V_98 ) , 0 , V_17 -> V_38 - V_171 -> V_98 ) ;
if ( ( ( V_171 -> V_98 % F_9 ( V_17 -> V_92 -> V_29 . V_193 ) ) == 0 ) &&
( V_171 -> V_98 < F_8 ( V_17 -> V_35 . V_39 ) ) && F_44 ( V_171 ) )
* F_45 ( V_171 , 1 ) = 0 ;
V_163 = (struct V_162 * ) V_171 -> V_108 ;
V_163 -> V_194 = F_47 ( V_171 -> V_98 ) ;
V_17 -> V_94 = NULL ;
V_17 -> V_26 -> V_178 . V_195 += V_17 -> V_185 ;
return V_171 ;
V_180:
if ( V_17 -> V_94 != NULL )
F_51 ( V_17 ) ;
return NULL ;
}
static void F_51 ( struct V_16 * V_17 )
{
if ( ! ( F_34 ( & V_17 -> V_102 ) || F_52 ( & V_17 -> V_111 ) ) )
F_53 ( & V_17 -> V_102 ,
F_54 ( 0 , V_196 ) ,
V_104 ) ;
}
static enum V_197 V_106 ( struct V_198 * V_199 )
{
struct V_16 * V_17 =
F_55 ( V_199 , struct V_16 , V_102 ) ;
if ( ! F_52 ( & V_17 -> V_111 ) )
F_56 ( & V_17 -> V_107 ) ;
return V_200 ;
}
static void V_110 ( unsigned long V_201 )
{
struct V_16 * V_17 = (struct V_16 * ) V_201 ;
F_57 ( & V_17 -> V_112 ) ;
if ( V_17 -> V_190 != 0 ) {
V_17 -> V_190 -- ;
F_51 ( V_17 ) ;
F_58 ( & V_17 -> V_112 ) ;
} else if ( V_17 -> V_26 != NULL ) {
F_58 ( & V_17 -> V_112 ) ;
F_59 ( V_17 -> V_26 ) ;
F_60 ( NULL , V_17 -> V_26 ) ;
F_61 ( V_17 -> V_26 ) ;
} else {
F_58 ( & V_17 -> V_112 ) ;
}
}
static struct V_152 *
F_62 ( struct V_5 * V_6 , struct V_152 * V_153 , T_7 V_19 )
{
struct V_152 * V_171 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_17 == NULL )
goto error;
F_57 ( & V_17 -> V_112 ) ;
V_171 = F_48 ( V_17 , V_153 , F_10 ( V_202 ) ) ;
F_58 ( & V_17 -> V_112 ) ;
return V_171 ;
error:
if ( V_153 != NULL )
F_15 ( V_153 ) ;
return NULL ;
}
int F_63 ( struct V_16 * V_17 , struct V_152 * V_203 )
{
struct V_162 * V_163 ;
int V_98 ;
int V_151 = - V_204 ;
if ( V_17 == NULL )
goto error;
if ( V_203 -> V_98 < ( sizeof( struct V_162 ) +
sizeof( struct V_158 ) ) ) {
F_7 ( L_19 ) ;
goto error;
}
V_163 = (struct V_162 * ) V_203 -> V_108 ;
if ( F_8 ( V_163 -> V_166 ) != V_181 ) {
F_7 ( L_20 ,
F_8 ( V_163 -> V_166 ) ) ;
goto error;
}
V_98 = F_9 ( V_163 -> V_194 ) ;
if ( V_98 > V_17 -> V_36 ) {
F_7 ( L_21 , V_98 ,
V_17 -> V_36 ) ;
goto error;
}
if ( ( V_17 -> V_205 + 1 ) != F_9 ( V_163 -> V_183 ) &&
( V_17 -> V_205 || F_9 ( V_163 -> V_183 ) ) &&
! ( ( V_17 -> V_205 == 0xffff ) && ! F_9 ( V_163 -> V_183 ) ) ) {
F_7 ( L_22 ,
V_17 -> V_205 , F_9 ( V_163 -> V_183 ) ) ;
}
V_17 -> V_205 = F_9 ( V_163 -> V_183 ) ;
V_151 = F_9 ( V_163 -> V_165 ) ;
error:
return V_151 ;
}
int F_64 ( struct V_152 * V_203 , int V_164 )
{
struct V_158 * V_161 ;
int V_151 = - V_204 ;
if ( ( V_164 + sizeof( struct V_158 ) ) > V_203 -> V_98 ) {
F_7 ( L_23 , V_164 ) ;
goto error;
}
V_161 = (struct V_158 * ) ( V_203 -> V_108 + V_164 ) ;
if ( F_9 ( V_161 -> V_169 ) < V_206 ) {
F_7 ( L_24 ,
F_8 ( V_161 -> V_166 ) ) ;
goto error;
}
V_151 = ( ( F_9 ( V_161 -> V_169 ) -
sizeof( struct V_158 ) ) /
sizeof( struct V_170 ) ) ;
V_151 -- ;
if ( ( sizeof( struct V_158 ) + V_151 * ( sizeof( struct V_170 ) ) ) >
V_203 -> V_98 ) {
F_7 ( L_25 , V_151 ) ;
V_151 = - V_204 ;
}
error:
return V_151 ;
}
static int F_65 ( struct V_5 * V_6 , struct V_152 * V_203 )
{
struct V_152 * V_153 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
int V_98 ;
int V_207 ;
int V_208 ;
int V_209 ;
struct V_158 * V_161 ;
struct V_170 * V_186 ;
int V_164 ;
int V_210 = 50 ;
V_164 = F_63 ( V_17 , V_203 ) ;
if ( V_164 < 0 )
goto error;
V_211:
V_207 = F_64 ( V_203 , V_164 ) ;
if ( V_207 < 0 )
goto error;
V_161 = (struct V_158 * ) ( V_203 -> V_108 + V_164 ) ;
if ( F_8 ( V_161 -> V_166 ) != V_202 ) {
F_7 ( L_26 ,
F_8 ( V_161 -> V_166 ) ) ;
goto V_212;
}
V_186 = V_161 -> V_186 ;
for ( V_208 = 0 ; V_208 < V_207 ; V_208 ++ , V_186 ++ ) {
V_209 = F_9 ( V_186 -> V_188 ) ;
V_98 = F_9 ( V_186 -> V_187 ) ;
if ( ( V_209 == 0 ) || ( V_98 == 0 ) ) {
if ( ! V_208 )
goto V_212;
break;
}
if ( ( ( V_209 + V_98 ) > V_203 -> V_98 ) ||
( V_98 > V_17 -> V_36 ) || ( V_98 < V_49 ) ) {
F_7 ( L_27
L_28 ,
V_208 , V_209 , V_98 , V_203 ) ;
if ( ! V_208 )
goto V_212;
break;
} else {
V_153 = F_66 ( V_203 , V_177 ) ;
if ( ! V_153 )
goto error;
V_153 -> V_98 = V_98 ;
V_153 -> V_108 = ( ( T_1 * ) V_203 -> V_108 ) + V_209 ;
F_67 ( V_153 , V_98 ) ;
F_68 ( V_6 , V_153 ) ;
}
}
V_212:
V_164 = F_9 ( V_161 -> V_167 ) ;
if ( V_164 && V_210 -- )
goto V_211;
return 1 ;
error:
return 0 ;
}
static void
F_69 ( struct V_16 * V_17 ,
struct V_213 * V_108 )
{
T_8 V_143 = F_8 ( V_108 -> V_214 ) ;
T_8 V_142 = F_8 ( V_108 -> V_215 ) ;
if ( ( V_142 != V_17 -> V_142 ) || ( V_143 != V_17 -> V_143 ) ) {
V_17 -> V_142 = V_142 ;
V_17 -> V_143 = V_143 ;
if ( ( V_142 > 1000000 ) && ( V_143 > 1000000 ) ) {
F_70 (KERN_INFO KBUILD_MODNAME
L_29
L_30 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000000U),
(unsigned int)(tx_speed / 1000000U)) ;
} else {
F_70 (KERN_INFO KBUILD_MODNAME
L_31
L_32 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000U),
(unsigned int)(tx_speed / 1000U)) ;
}
}
}
static void F_71 ( struct V_5 * V_6 , struct V_216 * V_216 )
{
struct V_16 * V_17 ;
struct V_217 * V_218 ;
V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_216 -> V_219 < sizeof( * V_218 ) )
return;
if ( F_72 ( V_220 , & V_6 -> V_19 ) ) {
F_69 ( V_17 ,
(struct V_213 * ) V_216 -> V_221 ) ;
return;
}
V_218 = V_216 -> V_221 ;
switch ( V_218 -> V_222 ) {
case V_223 :
V_17 -> V_224 = F_9 ( V_218 -> V_225 ) ;
F_70 (KERN_INFO KBUILD_MODNAME L_33
L_34 ,
ctx->netdev->name, ctx->connected ? L_35 : L_36 ) ;
if ( V_17 -> V_224 )
F_73 ( V_6 -> V_2 ) ;
else {
F_41 ( V_6 -> V_2 ) ;
V_17 -> V_142 = V_17 -> V_143 = 0 ;
}
break;
case V_226 :
if ( V_216 -> V_219 < ( sizeof( * V_218 ) +
sizeof( struct V_213 ) ) )
F_74 ( V_220 , & V_6 -> V_19 ) ;
else
F_69 ( V_17 ,
(struct V_213 * ) & V_218 [ 1 ] ) ;
break;
default:
F_75 ( & V_6 -> V_14 -> V_6 , L_37
L_38 , V_218 -> V_222 ) ;
break;
}
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_17 == NULL )
return 1 ;
return ! V_17 -> V_224 ;
}
static int
F_77 ( struct V_79 * V_14 , const struct V_227 * V_228 )
{
return F_78 ( V_14 , V_228 ) ;
}
static void F_79 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = F_80 ( V_80 ) ;
if ( V_6 == NULL )
return;
F_81 ( V_80 ) ;
}
