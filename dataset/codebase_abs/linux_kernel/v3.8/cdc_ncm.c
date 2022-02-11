static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
strncpy ( V_4 -> V_7 , V_6 -> V_8 , sizeof( V_4 -> V_7 ) ) ;
strncpy ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
strncpy ( V_4 -> V_11 , V_6 -> V_12 -> V_13 ,
sizeof( V_4 -> V_11 ) ) ;
F_3 ( V_6 -> V_14 , V_4 -> V_15 , sizeof( V_4 -> V_15 ) ) ;
}
static T_1 F_4 ( struct V_16 * V_17 )
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
V_21 = F_5 ( V_6 , V_31 ,
V_32 | V_33
| V_34 ,
0 , V_20 , & V_17 -> V_35 ,
sizeof( V_17 -> V_35 ) ) ;
if ( V_21 < 0 ) {
F_6 ( L_1 ) ;
return 1 ;
}
V_17 -> V_36 = F_7 ( V_17 -> V_35 . V_37 ) ;
V_17 -> V_38 = F_7 ( V_17 -> V_35 . V_39 ) ;
V_17 -> V_40 = F_8 ( V_17 -> V_35 . V_41 ) ;
V_17 -> V_42 = F_8 ( V_17 -> V_35 . V_43 ) ;
V_17 -> V_44 = F_8 ( V_17 -> V_35 . V_45 ) ;
V_17 -> V_46 = F_8 ( V_17 -> V_35 . V_47 ) ;
V_23 = F_8 ( V_17 -> V_35 . V_48 ) ;
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
F_6 ( L_2
L_3
L_4 ,
V_17 -> V_36 , V_17 -> V_38 , V_17 -> V_40 , V_17 -> V_42 ,
V_17 -> V_44 , V_17 -> V_46 , V_19 ) ;
if ( ( V_17 -> V_46 == 0 ) ||
( V_17 -> V_46 > V_56 ) )
V_17 -> V_46 = V_56 ;
if ( V_17 -> V_36 < V_57 ) {
F_6 ( L_5 ,
V_57 ) ;
V_17 -> V_36 = V_57 ;
}
if ( V_17 -> V_36 > V_58 ) {
F_6 ( L_6 ,
V_58 ) ;
V_17 -> V_36 = V_58 ;
}
if ( V_17 -> V_36 != F_7 ( V_17 -> V_35 . V_37 ) ) {
T_4 V_37 = F_9 ( V_17 -> V_36 ) ;
V_21 = F_10 ( V_6 , V_59 ,
V_32 | V_60
| V_34 ,
0 , V_20 , & V_37 , 4 ) ;
if ( V_21 < 0 )
F_6 ( L_7 ) ;
}
if ( ( V_17 -> V_38 <
( V_25 + V_24 ) ) ||
( V_17 -> V_38 > V_61 ) ) {
F_6 ( L_8 ,
V_61 ) ;
V_17 -> V_38 = V_61 ;
}
V_18 = V_17 -> V_44 ;
if ( ( V_18 < V_62 ) ||
( V_18 != ( ( - V_18 ) & V_18 ) ) || ( V_18 >= V_17 -> V_38 ) ) {
F_6 ( L_9 ) ;
V_17 -> V_44 = V_62 ;
}
V_18 = V_17 -> V_42 ;
if ( ( V_18 < V_62 ) ||
( V_18 != ( ( - V_18 ) & V_18 ) ) || ( V_18 >= V_17 -> V_38 ) ) {
F_6 ( L_10 ) ;
V_17 -> V_42 = V_62 ;
}
if ( V_17 -> V_40 >= V_17 -> V_42 ) {
F_6 ( L_11 ) ;
V_17 -> V_40 = 0 ;
}
V_17 -> V_40 = ( ( V_17 -> V_40 - V_22 ) &
( V_17 -> V_42 - 1 ) ) ;
if ( V_19 & V_63 ) {
V_21 = F_10 ( V_6 , V_64 ,
V_32 | V_60
| V_34 ,
V_65 ,
V_20 , NULL , 0 ) ;
if ( V_21 < 0 )
F_6 ( L_12 ) ;
}
if ( V_23 & V_66 ) {
V_21 = F_10 ( V_6 , V_67 ,
V_32 | V_60
| V_34 ,
V_68 ,
V_20 , NULL , 0 ) ;
if ( V_21 < 0 )
F_6 ( L_13 ) ;
}
V_17 -> V_69 = V_24 ;
if ( V_19 & V_70 ) {
T_5 V_69 ;
T_3 V_71 ;
if ( V_17 -> V_72 != NULL )
V_71 = F_8 ( V_17 -> V_72 -> V_73 ) ;
else if ( V_17 -> V_52 != NULL )
V_71 = F_8 ( V_17 -> V_52 -> V_73 ) ;
else
goto V_74;
V_21 = F_5 ( V_6 , V_75 ,
V_32 | V_33
| V_34 ,
0 , V_20 , & V_69 , 2 ) ;
if ( V_21 < 0 ) {
F_6 ( L_14 ,
V_24 ) ;
} else {
V_17 -> V_69 =
F_8 ( V_69 ) ;
if ( V_17 -> V_69 > V_71 )
V_17 -> V_69 = V_71 ;
if ( V_17 -> V_69 > V_76 )
V_17 -> V_69 = V_76 ;
if ( V_17 -> V_69 < V_24 )
V_17 -> V_69 = V_24 ;
if ( V_17 -> V_69 !=
F_8 ( V_69 ) ) {
V_21 = F_10 ( V_6 ,
V_77 ,
V_32 | V_60
| V_34 ,
0 ,
V_20 , & V_69 ,
2 ) ;
if ( V_21 < 0 )
F_6 ( L_15 ) ;
}
}
}
V_74:
if ( V_17 -> V_26 -> V_78 != ( V_17 -> V_69 - V_22 ) )
V_17 -> V_26 -> V_78 = V_17 -> V_69 - V_22 ;
return 0 ;
}
static void
F_11 ( struct V_16 * V_17 , struct V_79 * V_80 )
{
struct V_81 * V_82 ;
T_1 V_83 ;
for ( V_83 = 0 ; V_83 < V_80 -> V_28 -> V_29 . V_84 ; V_83 ++ ) {
V_82 = V_80 -> V_28 -> V_85 + V_83 ;
switch ( V_82 -> V_29 . V_86 & V_87 ) {
case V_88 :
if ( F_12 ( & V_82 -> V_29 ) ) {
if ( V_17 -> V_89 == NULL )
V_17 -> V_89 = V_82 ;
}
break;
case V_90 :
if ( F_12 ( & V_82 -> V_29 ) ) {
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
static void F_13 ( struct V_16 * V_17 )
{
if ( V_17 == NULL )
return;
if ( V_17 -> V_93 != NULL ) {
F_14 ( V_17 -> V_93 ) ;
V_17 -> V_93 = NULL ;
}
if ( V_17 -> V_94 != NULL ) {
F_14 ( V_17 -> V_94 ) ;
V_17 -> V_94 = NULL ;
}
F_15 ( V_17 ) ;
}
int F_16 ( struct V_5 * V_6 , struct V_79 * V_80 , T_1 V_95 )
{
struct V_16 * V_17 ;
struct V_96 * V_7 ;
T_1 * V_97 ;
int V_98 ;
int V_99 ;
T_1 V_20 ;
V_17 = F_17 ( sizeof( * V_17 ) , V_100 ) ;
if ( V_17 == NULL )
return - V_101 ;
F_18 ( & V_17 -> V_102 , V_103 , V_104 ) ;
V_17 -> V_102 . V_105 = & V_106 ;
V_17 -> V_107 . V_108 = ( unsigned long ) V_17 ;
V_17 -> V_107 . V_109 = V_110 ;
F_19 ( & V_17 -> V_111 , 0 ) ;
F_20 ( & V_17 -> V_112 ) ;
V_17 -> V_26 = V_6 -> V_2 ;
V_6 -> V_108 [ 0 ] = ( unsigned long ) V_17 ;
V_7 = F_21 ( V_80 ) ;
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
V_17 -> V_27 = F_22 ( V_6 -> V_14 ,
V_17 -> V_118 -> V_120 ) ;
V_17 -> V_108 = F_22 ( V_6 -> V_14 ,
V_17 -> V_118 -> V_121 ) ;
break;
case V_122 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_72 ) ) )
break;
V_17 -> V_72 =
( const struct V_123 * ) V_97 ;
V_6 -> V_124 =
F_8 ( V_17 -> V_72 -> V_73 ) ;
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
V_17 -> V_108 = F_22 ( V_6 -> V_14 , V_80 -> V_28 -> V_29 . V_30 + 1 ) ;
F_23 ( & V_80 -> V_6 , L_16 ) ;
}
if ( ( V_17 -> V_27 == NULL ) || ( V_17 -> V_108 == NULL ) ||
( ( ! V_17 -> V_52 ) && ( ( V_17 -> V_72 == NULL ) || ( V_17 -> V_27 != V_80 ) ) ) )
goto error;
if ( V_17 -> V_108 != V_17 -> V_27 ) {
V_99 = F_24 ( V_7 , V_17 -> V_108 , V_6 ) ;
if ( V_99 )
goto error;
}
V_20 = V_17 -> V_108 -> V_28 -> V_29 . V_30 ;
V_99 = F_25 ( V_6 -> V_14 , V_20 , 0 ) ;
if ( V_99 )
goto V_131;
if ( F_4 ( V_17 ) )
goto V_131;
V_99 = F_25 ( V_6 -> V_14 , V_20 , V_95 ) ;
if ( V_99 )
goto V_131;
F_11 ( V_17 , V_17 -> V_108 ) ;
F_11 ( V_17 , V_17 -> V_27 ) ;
if ( ( V_17 -> V_91 == NULL ) || ( V_17 -> V_92 == NULL ) ||
( V_17 -> V_89 == NULL ) )
goto V_131;
V_6 -> V_2 -> V_132 = & V_133 ;
F_26 ( V_17 -> V_108 , V_6 ) ;
F_26 ( V_17 -> V_27 , V_6 ) ;
F_26 ( V_17 -> V_80 , V_6 ) ;
if ( V_17 -> V_72 ) {
V_99 = F_27 ( V_6 , V_17 -> V_72 -> V_134 ) ;
if ( V_99 )
goto V_131;
F_28 ( & V_6 -> V_14 -> V_6 , L_17 , V_6 -> V_2 -> V_135 ) ;
}
V_6 -> V_136 = F_29 ( V_6 -> V_14 ,
V_17 -> V_91 -> V_29 . V_137 & V_138 ) ;
V_6 -> V_139 = F_30 ( V_6 -> V_14 ,
V_17 -> V_92 -> V_29 . V_137 & V_138 ) ;
V_6 -> V_140 = V_17 -> V_89 ;
V_6 -> V_141 = V_17 -> V_36 ;
V_17 -> V_142 = V_17 -> V_143 = 0 ;
return 0 ;
V_131:
F_26 ( V_17 -> V_27 , NULL ) ;
F_26 ( V_17 -> V_108 , NULL ) ;
if ( V_17 -> V_108 != V_17 -> V_27 )
F_31 ( V_7 , V_17 -> V_108 ) ;
error:
F_13 ( (struct V_16 * ) V_6 -> V_108 [ 0 ] ) ;
V_6 -> V_108 [ 0 ] = 0 ;
F_28 ( & V_6 -> V_14 -> V_6 , L_18 ) ;
return - V_101 ;
}
void F_32 ( struct V_5 * V_6 , struct V_79 * V_80 )
{
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
struct V_96 * V_7 = F_21 ( V_80 ) ;
if ( V_17 == NULL )
return;
F_19 ( & V_17 -> V_111 , 1 ) ;
if ( F_33 ( & V_17 -> V_102 ) )
F_34 ( & V_17 -> V_102 ) ;
F_35 ( & V_17 -> V_107 ) ;
if ( V_17 -> V_27 == V_17 -> V_108 )
V_17 -> V_108 = NULL ;
if ( V_80 == V_17 -> V_27 && V_17 -> V_108 ) {
F_26 ( V_17 -> V_108 , NULL ) ;
F_31 ( V_7 , V_17 -> V_108 ) ;
V_17 -> V_108 = NULL ;
} else if ( V_80 == V_17 -> V_108 && V_17 -> V_27 ) {
F_26 ( V_17 -> V_27 , NULL ) ;
F_31 ( V_7 , V_17 -> V_27 ) ;
V_17 -> V_27 = NULL ;
}
F_26 ( V_17 -> V_80 , NULL ) ;
F_13 ( V_17 ) ;
}
static int F_36 ( struct V_5 * V_6 , struct V_79 * V_80 )
{
int V_144 ;
#if F_37 ( V_145 )
if ( ( V_80 -> V_146 == 2 ) &&
! F_25 ( V_6 -> V_14 ,
V_80 -> V_28 -> V_29 . V_30 ,
V_147 ) &&
F_38 ( V_80 -> V_28 ) )
return - V_101 ;
#endif
V_144 = F_16 ( V_6 , V_80 , 1 ) ;
F_39 ( V_6 -> V_2 ) ;
return V_144 ;
}
static void F_40 ( struct V_148 * V_149 , T_6 V_150 , T_6 V_151 , T_6 V_152 )
{
T_6 V_153 = F_41 ( V_149 -> V_98 , V_150 ) - V_149 -> V_98 + V_151 ;
if ( V_149 -> V_98 + V_153 > V_152 )
V_153 = V_152 - V_149 -> V_98 ;
if ( V_153 && F_42 ( V_149 ) >= V_153 )
memset ( F_43 ( V_149 , V_153 ) , 0 , V_153 ) ;
}
static struct V_154 * F_44 ( struct V_16 * V_17 , struct V_148 * V_149 , T_4 V_155 , T_6 V_156 )
{
struct V_154 * V_157 = NULL ;
struct V_158 * V_159 = ( void * ) V_149 -> V_108 ;
T_6 V_160 = F_8 ( V_159 -> V_161 ) ;
while ( V_160 ) {
V_157 = (struct V_154 * ) ( V_149 -> V_108 + V_160 ) ;
if ( V_157 -> V_162 == V_155 )
return V_157 ;
V_160 = F_8 ( V_157 -> V_163 ) ;
}
F_40 ( V_149 , V_17 -> V_44 , 0 , V_17 -> V_38 ) ;
if ( ( V_17 -> V_38 - V_149 -> V_98 - V_156 ) < V_164 )
return NULL ;
if ( V_157 )
V_157 -> V_163 = F_45 ( V_149 -> V_98 ) ;
else
V_159 -> V_161 = F_45 ( V_149 -> V_98 ) ;
V_157 = (struct V_154 * ) memset ( F_43 ( V_149 , V_164 ) , 0 , V_164 ) ;
V_157 -> V_162 = V_155 ;
V_157 -> V_165 = F_45 ( sizeof( struct V_154 ) + sizeof( struct V_166 ) ) ;
return V_157 ;
}
struct V_148 *
F_46 ( struct V_16 * V_17 , struct V_148 * V_149 , T_4 V_155 )
{
struct V_158 * V_159 ;
struct V_154 * V_157 ;
struct V_148 * V_167 ;
T_3 V_168 = 0 , V_169 , V_170 ;
T_1 V_171 = 0 ;
if ( V_149 != NULL ) {
F_47 ( V_149 , V_17 -> V_93 ) ;
F_47 ( V_155 , V_17 -> V_172 ) ;
} else {
V_171 = 1 ;
}
V_167 = V_17 -> V_94 ;
if ( ! V_167 ) {
V_167 = F_48 ( ( V_17 -> V_38 + 1 ) , V_173 ) ;
if ( V_167 == NULL ) {
if ( V_149 != NULL ) {
F_14 ( V_149 ) ;
V_17 -> V_26 -> V_174 . V_175 ++ ;
}
goto V_176;
}
V_159 = (struct V_158 * ) memset ( F_43 ( V_167 , sizeof( struct V_158 ) ) , 0 , sizeof( struct V_158 ) ) ;
V_159 -> V_162 = F_9 ( V_177 ) ;
V_159 -> V_178 = F_45 ( sizeof( struct V_158 ) ) ;
V_159 -> V_179 = F_45 ( V_17 -> V_180 ++ ) ;
V_17 -> V_181 = 0 ;
}
for ( V_168 = V_17 -> V_181 ; V_168 < V_17 -> V_46 ; V_168 ++ ) {
if ( V_149 == NULL ) {
V_149 = V_17 -> V_93 ;
V_155 = V_17 -> V_172 ;
V_17 -> V_93 = NULL ;
if ( V_149 == NULL )
break;
}
V_157 = F_44 ( V_17 , V_167 , V_155 , V_149 -> V_98 + V_17 -> V_42 + V_17 -> V_40 ) ;
F_40 ( V_167 , V_17 -> V_42 , V_17 -> V_40 , V_17 -> V_38 ) ;
if ( ! V_157 || V_167 -> V_98 + V_149 -> V_98 > V_17 -> V_38 ) {
if ( V_168 == 0 ) {
F_14 ( V_149 ) ;
V_149 = NULL ;
V_17 -> V_26 -> V_174 . V_175 ++ ;
} else {
if ( V_17 -> V_93 != NULL ) {
F_14 ( V_17 -> V_93 ) ;
V_17 -> V_26 -> V_174 . V_175 ++ ;
}
V_17 -> V_93 = V_149 ;
V_17 -> V_172 = V_155 ;
V_149 = NULL ;
V_171 = 1 ;
}
break;
}
V_170 = F_8 ( V_157 -> V_165 ) ;
V_169 = ( V_170 - sizeof( struct V_154 ) ) / sizeof( struct V_166 ) - 1 ;
V_157 -> V_182 [ V_169 ] . V_183 = F_45 ( V_149 -> V_98 ) ;
V_157 -> V_182 [ V_169 ] . V_184 = F_45 ( V_167 -> V_98 ) ;
V_157 -> V_165 = F_45 ( V_170 + sizeof( struct V_166 ) ) ;
memcpy ( F_43 ( V_167 , V_149 -> V_98 ) , V_149 -> V_108 , V_149 -> V_98 ) ;
F_14 ( V_149 ) ;
V_149 = NULL ;
if ( V_169 >= V_56 ) {
V_171 = 1 ;
break;
}
}
if ( V_149 != NULL ) {
F_14 ( V_149 ) ;
V_149 = NULL ;
V_17 -> V_26 -> V_174 . V_175 ++ ;
}
V_17 -> V_181 = V_168 ;
if ( V_168 == 0 ) {
V_17 -> V_94 = V_167 ;
goto V_176;
} else if ( ( V_168 < V_17 -> V_46 ) && ( V_171 == 0 ) ) {
V_17 -> V_94 = V_167 ;
if ( V_168 < V_185 )
V_17 -> V_186 = V_187 ;
goto V_176;
} else {
}
if ( V_167 -> V_98 > V_188 )
memset ( F_43 ( V_167 , V_17 -> V_38 - V_167 -> V_98 ) , 0 , V_17 -> V_38 - V_167 -> V_98 ) ;
if ( ( ( V_167 -> V_98 % F_8 ( V_17 -> V_92 -> V_29 . V_189 ) ) == 0 ) &&
( V_167 -> V_98 < F_7 ( V_17 -> V_35 . V_39 ) ) && F_42 ( V_167 ) )
* F_43 ( V_167 , 1 ) = 0 ;
V_159 = (struct V_158 * ) V_167 -> V_108 ;
V_159 -> V_190 = F_45 ( V_167 -> V_98 ) ;
V_17 -> V_94 = NULL ;
V_17 -> V_26 -> V_174 . V_191 += V_17 -> V_181 ;
return V_167 ;
V_176:
if ( V_17 -> V_94 != NULL )
F_49 ( V_17 ) ;
return NULL ;
}
static void F_49 ( struct V_16 * V_17 )
{
if ( ! ( F_33 ( & V_17 -> V_102 ) || F_50 ( & V_17 -> V_111 ) ) )
F_51 ( & V_17 -> V_102 ,
F_52 ( 0 , V_192 ) ,
V_104 ) ;
}
static enum V_193 V_106 ( struct V_194 * V_195 )
{
struct V_16 * V_17 =
F_53 ( V_195 , struct V_16 , V_102 ) ;
if ( ! F_50 ( & V_17 -> V_111 ) )
F_54 ( & V_17 -> V_107 ) ;
return V_196 ;
}
static void V_110 ( unsigned long V_197 )
{
struct V_16 * V_17 = (struct V_16 * ) V_197 ;
F_55 ( & V_17 -> V_112 ) ;
if ( V_17 -> V_186 != 0 ) {
V_17 -> V_186 -- ;
F_49 ( V_17 ) ;
F_56 ( & V_17 -> V_112 ) ;
} else if ( V_17 -> V_26 != NULL ) {
F_56 ( & V_17 -> V_112 ) ;
F_57 ( V_17 -> V_26 ) ;
F_58 ( NULL , V_17 -> V_26 ) ;
F_59 ( V_17 -> V_26 ) ;
} else {
F_56 ( & V_17 -> V_112 ) ;
}
}
static struct V_148 *
F_60 ( struct V_5 * V_6 , struct V_148 * V_149 , T_7 V_19 )
{
struct V_148 * V_167 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_17 == NULL )
goto error;
F_55 ( & V_17 -> V_112 ) ;
V_167 = F_46 ( V_17 , V_149 , F_9 ( V_198 ) ) ;
F_56 ( & V_17 -> V_112 ) ;
return V_167 ;
error:
if ( V_149 != NULL )
F_14 ( V_149 ) ;
return NULL ;
}
int F_61 ( struct V_16 * V_17 , struct V_148 * V_199 )
{
struct V_158 * V_159 ;
int V_98 ;
int V_144 = - V_200 ;
if ( V_17 == NULL )
goto error;
if ( V_199 -> V_98 < ( sizeof( struct V_158 ) +
sizeof( struct V_154 ) ) ) {
F_6 ( L_19 ) ;
goto error;
}
V_159 = (struct V_158 * ) V_199 -> V_108 ;
if ( F_7 ( V_159 -> V_162 ) != V_177 ) {
F_6 ( L_20 ,
F_7 ( V_159 -> V_162 ) ) ;
goto error;
}
V_98 = F_8 ( V_159 -> V_190 ) ;
if ( V_98 > V_17 -> V_36 ) {
F_6 ( L_21 , V_98 ,
V_17 -> V_36 ) ;
goto error;
}
if ( ( V_17 -> V_201 + 1 ) != F_8 ( V_159 -> V_179 ) &&
( V_17 -> V_201 || F_8 ( V_159 -> V_179 ) ) &&
! ( ( V_17 -> V_201 == 0xffff ) && ! F_8 ( V_159 -> V_179 ) ) ) {
F_6 ( L_22 ,
V_17 -> V_201 , F_8 ( V_159 -> V_179 ) ) ;
}
V_17 -> V_201 = F_8 ( V_159 -> V_179 ) ;
V_144 = F_8 ( V_159 -> V_161 ) ;
error:
return V_144 ;
}
int F_62 ( struct V_148 * V_199 , int V_160 )
{
struct V_154 * V_157 ;
int V_144 = - V_200 ;
if ( ( V_160 + sizeof( struct V_154 ) ) > V_199 -> V_98 ) {
F_6 ( L_23 , V_160 ) ;
goto error;
}
V_157 = (struct V_154 * ) ( V_199 -> V_108 + V_160 ) ;
if ( F_8 ( V_157 -> V_165 ) < V_202 ) {
F_6 ( L_24 ,
F_7 ( V_157 -> V_162 ) ) ;
goto error;
}
V_144 = ( ( F_8 ( V_157 -> V_165 ) -
sizeof( struct V_154 ) ) /
sizeof( struct V_166 ) ) ;
V_144 -- ;
if ( ( sizeof( struct V_154 ) + V_144 * ( sizeof( struct V_166 ) ) ) >
V_199 -> V_98 ) {
F_6 ( L_25 , V_144 ) ;
V_144 = - V_200 ;
}
error:
return V_144 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_148 * V_199 )
{
struct V_148 * V_149 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
int V_98 ;
int V_203 ;
int V_204 ;
int V_205 ;
struct V_154 * V_157 ;
struct V_166 * V_182 ;
int V_160 ;
int V_206 = 50 ;
V_160 = F_61 ( V_17 , V_199 ) ;
if ( V_160 < 0 )
goto error;
V_207:
V_203 = F_62 ( V_199 , V_160 ) ;
if ( V_203 < 0 )
goto error;
V_157 = (struct V_154 * ) ( V_199 -> V_108 + V_160 ) ;
if ( F_7 ( V_157 -> V_162 ) != V_198 ) {
F_6 ( L_26 ,
F_7 ( V_157 -> V_162 ) ) ;
goto V_208;
}
V_182 = V_157 -> V_182 ;
for ( V_204 = 0 ; V_204 < V_203 ; V_204 ++ , V_182 ++ ) {
V_205 = F_8 ( V_182 -> V_184 ) ;
V_98 = F_8 ( V_182 -> V_183 ) ;
if ( ( V_205 == 0 ) || ( V_98 == 0 ) ) {
if ( ! V_204 )
goto V_208;
break;
}
if ( ( ( V_205 + V_98 ) > V_199 -> V_98 ) ||
( V_98 > V_17 -> V_36 ) || ( V_98 < V_49 ) ) {
F_6 ( L_27
L_28 ,
V_204 , V_205 , V_98 , V_199 ) ;
if ( ! V_204 )
goto V_208;
break;
} else {
V_149 = F_64 ( V_199 , V_173 ) ;
if ( ! V_149 )
goto error;
V_149 -> V_98 = V_98 ;
V_149 -> V_108 = ( ( T_1 * ) V_199 -> V_108 ) + V_205 ;
F_65 ( V_149 , V_98 ) ;
F_66 ( V_6 , V_149 ) ;
}
}
V_208:
V_160 = F_8 ( V_157 -> V_163 ) ;
if ( V_160 && V_206 -- )
goto V_207;
return 1 ;
error:
return 0 ;
}
static void
F_67 ( struct V_16 * V_17 ,
struct V_209 * V_108 )
{
T_8 V_143 = F_7 ( V_108 -> V_210 ) ;
T_8 V_142 = F_7 ( V_108 -> V_211 ) ;
if ( ( V_142 != V_17 -> V_142 ) || ( V_143 != V_17 -> V_143 ) ) {
V_17 -> V_142 = V_142 ;
V_17 -> V_143 = V_143 ;
if ( ( V_142 > 1000000 ) && ( V_143 > 1000000 ) ) {
F_68 (KERN_INFO KBUILD_MODNAME
L_29
L_30 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000000U),
(unsigned int)(tx_speed / 1000000U)) ;
} else {
F_68 (KERN_INFO KBUILD_MODNAME
L_31
L_32 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000U),
(unsigned int)(tx_speed / 1000U)) ;
}
}
}
static void F_69 ( struct V_5 * V_6 , struct V_212 * V_212 )
{
struct V_16 * V_17 ;
struct V_213 * V_214 ;
V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_212 -> V_215 < sizeof( * V_214 ) )
return;
if ( F_70 ( V_216 , & V_6 -> V_19 ) ) {
F_67 ( V_17 ,
(struct V_209 * ) V_212 -> V_217 ) ;
return;
}
V_214 = V_212 -> V_217 ;
switch ( V_214 -> V_218 ) {
case V_219 :
V_17 -> V_220 = F_8 ( V_214 -> V_221 ) ;
F_68 (KERN_INFO KBUILD_MODNAME L_33
L_34 ,
ctx->netdev->name, ctx->connected ? L_35 : L_36 ) ;
if ( V_17 -> V_220 )
F_71 ( V_6 -> V_2 ) ;
else {
F_39 ( V_6 -> V_2 ) ;
V_17 -> V_142 = V_17 -> V_143 = 0 ;
}
break;
case V_222 :
if ( V_212 -> V_215 < ( sizeof( * V_214 ) +
sizeof( struct V_209 ) ) )
F_72 ( V_216 , & V_6 -> V_19 ) ;
else
F_67 ( V_17 ,
(struct V_209 * ) & V_214 [ 1 ] ) ;
break;
default:
F_73 ( & V_6 -> V_14 -> V_6 , L_37
L_38 , V_214 -> V_218 ) ;
break;
}
}
static int F_74 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_6 -> V_108 [ 0 ] ;
if ( V_17 == NULL )
return 1 ;
return ! V_17 -> V_220 ;
}
static int
F_75 ( struct V_79 * V_14 , const struct V_223 * V_224 )
{
return F_76 ( V_14 , V_224 ) ;
}
static void F_77 ( struct V_79 * V_80 )
{
struct V_5 * V_6 = F_78 ( V_80 ) ;
if ( V_6 == NULL )
return;
F_79 ( V_80 ) ;
}
