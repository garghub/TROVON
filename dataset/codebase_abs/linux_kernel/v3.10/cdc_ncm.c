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
if ( ! V_17 )
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
return - V_144 ;
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
struct V_145 * V_146 ;
if ( V_147 && V_80 -> V_148 == 2 ) {
V_146 = F_38 ( V_80 , V_149 ) ;
if ( V_146 && F_39 ( V_146 ) &&
! F_26 ( V_6 -> V_14 ,
V_80 -> V_28 -> V_29 . V_30 ,
V_149 ) )
return V_150 ;
}
return V_151 ;
}
static int F_40 ( struct V_5 * V_6 , struct V_79 * V_80 )
{
int V_152 ;
F_37 ( V_6 , V_80 ) ;
if ( F_39 ( V_80 -> V_28 ) )
return - V_144 ;
V_152 = F_17 ( V_6 , V_80 , 1 ) ;
F_41 ( V_6 , 0 , 0 ) ;
return V_152 ;
}
static void F_42 ( struct V_153 * V_154 , T_6 V_155 , T_6 V_156 , T_6 V_157 )
{
T_6 V_158 = F_43 ( V_154 -> V_98 , V_155 ) - V_154 -> V_98 + V_156 ;
if ( V_154 -> V_98 + V_158 > V_157 )
V_158 = V_157 - V_154 -> V_98 ;
if ( V_158 && F_44 ( V_154 ) >= V_158 )
memset ( F_45 ( V_154 , V_158 ) , 0 , V_158 ) ;
}
static struct V_159 * F_46 ( struct V_16 * V_17 , struct V_153 * V_154 , T_4 V_160 , T_6 V_161 )
{
struct V_159 * V_162 = NULL ;
struct V_163 * V_164 = ( void * ) V_154 -> V_108 ;
T_6 V_165 = F_9 ( V_164 -> V_166 ) ;
while ( V_165 ) {
V_162 = (struct V_159 * ) ( V_154 -> V_108 + V_165 ) ;
if ( V_162 -> V_167 == V_160 )
return V_162 ;
V_165 = F_9 ( V_162 -> V_168 ) ;
}
F_42 ( V_154 , V_17 -> V_44 , 0 , V_17 -> V_38 ) ;
if ( ( V_17 -> V_38 - V_154 -> V_98 - V_161 ) < V_169 )
return NULL ;
if ( V_162 )
V_162 -> V_168 = F_47 ( V_154 -> V_98 ) ;
else
V_164 -> V_166 = F_47 ( V_154 -> V_98 ) ;
V_162 = (struct V_159 * ) memset ( F_45 ( V_154 , V_169 ) , 0 , V_169 ) ;
V_162 -> V_167 = V_160 ;
V_162 -> V_170 = F_47 ( sizeof( struct V_159 ) + sizeof( struct V_171 ) ) ;
return V_162 ;
}
struct V_153 *
F_48 ( struct V_16 * V_17 , struct V_153 * V_154 , T_4 V_160 )
{
struct V_163 * V_164 ;
struct V_159 * V_162 ;
struct V_153 * V_172 ;
T_3 V_173 = 0 , V_174 , V_175 ;
T_1 V_176 = 0 ;
if ( V_154 != NULL ) {
F_49 ( V_154 , V_17 -> V_93 ) ;
F_49 ( V_160 , V_17 -> V_177 ) ;
} else {
V_176 = 1 ;
}
V_172 = V_17 -> V_94 ;
if ( ! V_172 ) {
V_172 = F_50 ( ( V_17 -> V_38 + 1 ) , V_178 ) ;
if ( V_172 == NULL ) {
if ( V_154 != NULL ) {
F_15 ( V_154 ) ;
V_17 -> V_26 -> V_179 . V_180 ++ ;
}
goto V_181;
}
V_164 = (struct V_163 * ) memset ( F_45 ( V_172 , sizeof( struct V_163 ) ) , 0 , sizeof( struct V_163 ) ) ;
V_164 -> V_167 = F_10 ( V_182 ) ;
V_164 -> V_183 = F_47 ( sizeof( struct V_163 ) ) ;
V_164 -> V_184 = F_47 ( V_17 -> V_185 ++ ) ;
V_17 -> V_186 = 0 ;
}
for ( V_173 = V_17 -> V_186 ; V_173 < V_17 -> V_46 ; V_173 ++ ) {
if ( V_154 == NULL ) {
V_154 = V_17 -> V_93 ;
V_160 = V_17 -> V_177 ;
V_17 -> V_93 = NULL ;
if ( V_154 == NULL )
break;
}
V_162 = F_46 ( V_17 , V_172 , V_160 , V_154 -> V_98 + V_17 -> V_42 + V_17 -> V_40 ) ;
F_42 ( V_172 , V_17 -> V_42 , V_17 -> V_40 , V_17 -> V_38 ) ;
if ( ! V_162 || V_172 -> V_98 + V_154 -> V_98 > V_17 -> V_38 ) {
if ( V_173 == 0 ) {
F_15 ( V_154 ) ;
V_154 = NULL ;
V_17 -> V_26 -> V_179 . V_180 ++ ;
} else {
if ( V_17 -> V_93 != NULL ) {
F_15 ( V_17 -> V_93 ) ;
V_17 -> V_26 -> V_179 . V_180 ++ ;
}
V_17 -> V_93 = V_154 ;
V_17 -> V_177 = V_160 ;
V_154 = NULL ;
V_176 = 1 ;
}
break;
}
V_175 = F_9 ( V_162 -> V_170 ) ;
V_174 = ( V_175 - sizeof( struct V_159 ) ) / sizeof( struct V_171 ) - 1 ;
V_162 -> V_187 [ V_174 ] . V_188 = F_47 ( V_154 -> V_98 ) ;
V_162 -> V_187 [ V_174 ] . V_189 = F_47 ( V_172 -> V_98 ) ;
V_162 -> V_170 = F_47 ( V_175 + sizeof( struct V_171 ) ) ;
memcpy ( F_45 ( V_172 , V_154 -> V_98 ) , V_154 -> V_108 , V_154 -> V_98 ) ;
F_15 ( V_154 ) ;
V_154 = NULL ;
if ( V_174 >= V_56 ) {
V_176 = 1 ;
break;
}
}
if ( V_154 != NULL ) {
F_15 ( V_154 ) ;
V_154 = NULL ;
V_17 -> V_26 -> V_179 . V_180 ++ ;
}
V_17 -> V_186 = V_173 ;
if ( V_173 == 0 ) {
V_17 -> V_94 = V_172 ;
goto V_181;
} else if ( ( V_173 < V_17 -> V_46 ) && ( V_176 == 0 ) ) {
V_17 -> V_94 = V_172 ;
if ( V_173 < V_190 )
V_17 -> V_191 = V_192 ;
goto V_181;
} else {
}
if ( V_172 -> V_98 > V_193 )
memset ( F_45 ( V_172 , V_17 -> V_38 - V_172 -> V_98 ) , 0 , V_17 -> V_38 - V_172 -> V_98 ) ;
if ( ( ( V_172 -> V_98 % F_9 ( V_17 -> V_92 -> V_29 . V_194 ) ) == 0 ) &&
( V_172 -> V_98 < F_8 ( V_17 -> V_35 . V_39 ) ) && F_44 ( V_172 ) )
* F_45 ( V_172 , 1 ) = 0 ;
V_164 = (struct V_163 * ) V_172 -> V_108 ;
V_164 -> V_195 = F_47 ( V_172 -> V_98 ) ;
V_17 -> V_94 = NULL ;
V_17 -> V_26 -> V_179 . V_196 += V_17 -> V_186 ;
return V_172 ;
V_181:
if ( V_17 -> V_94 != NULL )
F_51 ( V_17 ) ;
return NULL ;
}
static void F_51 ( struct V_16 * V_17 )
{
if ( ! ( F_34 ( & V_17 -> V_102 ) || F_52 ( & V_17 -> V_111 ) ) )
F_53 ( & V_17 -> V_102 ,
F_54 ( 0 , V_197 ) ,
V_104 ) ;
}
static enum V_198 V_106 ( struct V_199 * V_200 )
{
struct V_16 * V_17 =
F_55 ( V_200 , struct V_16 , V_102 ) ;
if ( ! F_52 ( & V_17 -> V_111 ) )
F_56 ( & V_17 -> V_107 ) ;
return V_201 ;
}
static void V_110 ( unsigned long V_202 )
{
struct V_16 * V_17 = (struct V_16 * ) V_202 ;
F_57 ( & V_17 -> V_112 ) ;
if ( V_17 -> V_191 != 0 ) {
V_17 -> V_191 -- ;
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
static struct V_153 *
F_62 ( struct V_5 * V_6 , struct V_153 * V_154 , T_7 V_19 )
{
struct V_153 * V_172 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_17 == NULL )
goto error;
F_57 ( & V_17 -> V_112 ) ;
V_172 = F_48 ( V_17 , V_154 , F_10 ( V_203 ) ) ;
F_58 ( & V_17 -> V_112 ) ;
return V_172 ;
error:
if ( V_154 != NULL )
F_15 ( V_154 ) ;
return NULL ;
}
int F_63 ( struct V_16 * V_17 , struct V_153 * V_204 )
{
struct V_163 * V_164 ;
int V_98 ;
int V_152 = - V_205 ;
if ( V_17 == NULL )
goto error;
if ( V_204 -> V_98 < ( sizeof( struct V_163 ) +
sizeof( struct V_159 ) ) ) {
F_7 ( L_19 ) ;
goto error;
}
V_164 = (struct V_163 * ) V_204 -> V_108 ;
if ( F_8 ( V_164 -> V_167 ) != V_182 ) {
F_7 ( L_20 ,
F_8 ( V_164 -> V_167 ) ) ;
goto error;
}
V_98 = F_9 ( V_164 -> V_195 ) ;
if ( V_98 > V_17 -> V_36 ) {
F_7 ( L_21 , V_98 ,
V_17 -> V_36 ) ;
goto error;
}
if ( ( V_17 -> V_206 + 1 ) != F_9 ( V_164 -> V_184 ) &&
( V_17 -> V_206 || F_9 ( V_164 -> V_184 ) ) &&
! ( ( V_17 -> V_206 == 0xffff ) && ! F_9 ( V_164 -> V_184 ) ) ) {
F_7 ( L_22 ,
V_17 -> V_206 , F_9 ( V_164 -> V_184 ) ) ;
}
V_17 -> V_206 = F_9 ( V_164 -> V_184 ) ;
V_152 = F_9 ( V_164 -> V_166 ) ;
error:
return V_152 ;
}
int F_64 ( struct V_153 * V_204 , int V_165 )
{
struct V_159 * V_162 ;
int V_152 = - V_205 ;
if ( ( V_165 + sizeof( struct V_159 ) ) > V_204 -> V_98 ) {
F_7 ( L_23 , V_165 ) ;
goto error;
}
V_162 = (struct V_159 * ) ( V_204 -> V_108 + V_165 ) ;
if ( F_9 ( V_162 -> V_170 ) < V_207 ) {
F_7 ( L_24 ,
F_8 ( V_162 -> V_167 ) ) ;
goto error;
}
V_152 = ( ( F_9 ( V_162 -> V_170 ) -
sizeof( struct V_159 ) ) /
sizeof( struct V_171 ) ) ;
V_152 -- ;
if ( ( sizeof( struct V_159 ) + V_152 * ( sizeof( struct V_171 ) ) ) >
V_204 -> V_98 ) {
F_7 ( L_25 , V_152 ) ;
V_152 = - V_205 ;
}
error:
return V_152 ;
}
static int F_65 ( struct V_5 * V_6 , struct V_153 * V_204 )
{
struct V_153 * V_154 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
int V_98 ;
int V_208 ;
int V_209 ;
int V_210 ;
struct V_159 * V_162 ;
struct V_171 * V_187 ;
int V_165 ;
int V_211 = 50 ;
V_165 = F_63 ( V_17 , V_204 ) ;
if ( V_165 < 0 )
goto error;
V_212:
V_208 = F_64 ( V_204 , V_165 ) ;
if ( V_208 < 0 )
goto error;
V_162 = (struct V_159 * ) ( V_204 -> V_108 + V_165 ) ;
if ( F_8 ( V_162 -> V_167 ) != V_203 ) {
F_7 ( L_26 ,
F_8 ( V_162 -> V_167 ) ) ;
goto V_213;
}
V_187 = V_162 -> V_187 ;
for ( V_209 = 0 ; V_209 < V_208 ; V_209 ++ , V_187 ++ ) {
V_210 = F_9 ( V_187 -> V_189 ) ;
V_98 = F_9 ( V_187 -> V_188 ) ;
if ( ( V_210 == 0 ) || ( V_98 == 0 ) ) {
if ( ! V_209 )
goto V_213;
break;
}
if ( ( ( V_210 + V_98 ) > V_204 -> V_98 ) ||
( V_98 > V_17 -> V_36 ) || ( V_98 < V_49 ) ) {
F_7 ( L_27
L_28 ,
V_209 , V_210 , V_98 , V_204 ) ;
if ( ! V_209 )
goto V_213;
break;
} else {
V_154 = F_66 ( V_204 , V_178 ) ;
if ( ! V_154 )
goto error;
V_154 -> V_98 = V_98 ;
V_154 -> V_108 = ( ( T_1 * ) V_204 -> V_108 ) + V_210 ;
F_67 ( V_154 , V_98 ) ;
F_68 ( V_6 , V_154 ) ;
}
}
V_213:
V_165 = F_9 ( V_162 -> V_168 ) ;
if ( V_165 && V_211 -- )
goto V_212;
return 1 ;
error:
return 0 ;
}
static void
F_69 ( struct V_16 * V_17 ,
struct V_214 * V_108 )
{
T_8 V_143 = F_8 ( V_108 -> V_215 ) ;
T_8 V_142 = F_8 ( V_108 -> V_216 ) ;
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
static void F_71 ( struct V_5 * V_6 , struct V_217 * V_217 )
{
struct V_16 * V_17 ;
struct V_218 * V_219 ;
V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_217 -> V_220 < sizeof( * V_219 ) )
return;
if ( F_72 ( V_221 , & V_6 -> V_19 ) ) {
F_69 ( V_17 ,
(struct V_214 * ) V_217 -> V_222 ) ;
return;
}
V_219 = V_217 -> V_222 ;
switch ( V_219 -> V_223 ) {
case V_224 :
V_17 -> V_225 = F_9 ( V_219 -> V_226 ) ;
F_70 (KERN_INFO KBUILD_MODNAME L_33
L_34 ,
ctx->netdev->name, ctx->connected ? L_35 : L_36 ) ;
F_41 ( V_6 , V_17 -> V_225 , 0 ) ;
if ( ! V_17 -> V_225 )
V_17 -> V_142 = V_17 -> V_143 = 0 ;
break;
case V_227 :
if ( V_217 -> V_220 < ( sizeof( * V_219 ) +
sizeof( struct V_214 ) ) )
F_73 ( V_221 , & V_6 -> V_19 ) ;
else
F_69 ( V_17 ,
(struct V_214 * ) & V_219 [ 1 ] ) ;
break;
default:
F_24 ( & V_6 -> V_14 -> V_6 ,
L_37 ,
V_219 -> V_223 ) ;
break;
}
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_17 == NULL )
return 1 ;
return ! V_17 -> V_225 ;
}
static int
F_75 ( struct V_79 * V_14 , const struct V_228 * V_229 )
{
return F_76 ( V_14 , V_229 ) ;
}
static void F_77 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = F_78 ( V_80 ) ;
if ( V_6 == NULL )
return;
F_79 ( V_80 ) ;
}
