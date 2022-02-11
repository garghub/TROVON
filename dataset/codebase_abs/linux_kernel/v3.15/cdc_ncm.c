static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
T_1 V_6 ;
T_2 V_7 ;
T_2 V_8 ;
int V_9 ;
int V_10 ;
T_3 V_11 ;
T_3 V_12 ;
T_4 V_13 ;
V_8 = V_4 -> V_14 -> V_15 -> V_16 . V_17 ;
V_9 = F_2 ( V_2 , V_18 ,
V_19 | V_20
| V_21 ,
0 , V_8 , & V_4 -> V_22 ,
sizeof( V_4 -> V_22 ) ) ;
if ( V_9 < 0 ) {
F_3 ( & V_2 -> V_23 -> V_2 , L_1 ) ;
return V_9 ;
}
V_4 -> V_24 = F_4 ( V_4 -> V_22 . V_25 ) ;
V_4 -> V_26 = F_4 ( V_4 -> V_22 . V_27 ) ;
V_4 -> V_28 = F_5 ( V_4 -> V_22 . V_29 ) ;
V_4 -> V_30 = F_5 ( V_4 -> V_22 . V_31 ) ;
V_4 -> V_32 = F_5 ( V_4 -> V_22 . V_33 ) ;
V_4 -> V_34 = F_5 ( V_4 -> V_22 . V_35 ) ;
V_12 = F_5 ( V_4 -> V_22 . V_36 ) ;
if ( F_6 ( V_4 -> V_14 -> V_15 ) ) {
if ( ! V_4 -> V_37 )
return - V_38 ;
V_10 = 0 ;
V_7 = V_4 -> V_37 -> V_39 ;
V_4 -> V_13 = F_5 ( V_4 -> V_37 -> V_40 ) ;
if ( V_4 -> V_13 < V_41 )
V_4 -> V_13 = V_41 ;
} else {
if ( ! V_4 -> V_42 )
return - V_38 ;
V_10 = V_43 ;
V_7 = V_4 -> V_42 -> V_39 ;
V_4 -> V_13 = F_5 ( V_4 -> V_44 -> V_40 ) ;
if ( V_4 -> V_13 < V_45 )
V_4 -> V_13 = V_45 ;
}
if ( V_4 -> V_13 > V_46 )
V_4 -> V_13 = V_46 ;
F_7 ( & V_2 -> V_23 -> V_2 ,
L_2 ,
V_4 -> V_24 , V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_30 ,
V_4 -> V_32 , V_4 -> V_34 , V_7 ) ;
if ( ( V_4 -> V_34 == 0 ) ||
( V_4 -> V_34 > V_47 ) )
V_4 -> V_34 = V_47 ;
if ( V_4 -> V_24 < V_48 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_3 ,
V_48 ) ;
V_4 -> V_24 = V_48 ;
}
if ( V_4 -> V_24 > V_49 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_4 ,
V_49 ) ;
V_4 -> V_24 = V_49 ;
}
if ( V_4 -> V_24 != F_4 ( V_4 -> V_22 . V_25 ) ) {
T_5 V_25 = F_8 ( V_4 -> V_24 ) ;
V_9 = F_9 ( V_2 , V_50 ,
V_19 | V_51
| V_21 ,
0 , V_8 , & V_25 , 4 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_5 ) ;
}
if ( V_4 -> V_26 > V_52 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_6 ,
V_52 ) ;
V_4 -> V_26 = V_52 ;
}
V_6 = V_4 -> V_32 ;
if ( ( V_6 < V_53 ) ||
( V_6 != ( ( - V_6 ) & V_6 ) ) || ( V_6 >= V_4 -> V_26 ) ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_7 ) ;
V_4 -> V_32 = V_53 ;
}
V_6 = V_4 -> V_30 ;
if ( ( V_6 < V_53 ) ||
( V_6 != ( ( - V_6 ) & V_6 ) ) || ( V_6 >= V_4 -> V_26 ) ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_8 ) ;
V_4 -> V_30 = V_53 ;
}
if ( V_4 -> V_28 >= V_4 -> V_30 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_9 ) ;
V_4 -> V_28 = 0 ;
}
V_4 -> V_28 = ( ( V_4 -> V_28 - V_10 ) &
( V_4 -> V_30 - 1 ) ) ;
if ( V_7 & V_54 ) {
V_9 = F_9 ( V_2 , V_55 ,
V_19 | V_51
| V_21 ,
V_56 ,
V_8 , NULL , 0 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_10 ) ;
}
if ( V_12 & V_57 ) {
V_9 = F_9 ( V_2 , V_58 ,
V_19 | V_51
| V_21 ,
V_59 ,
V_8 , NULL , 0 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_11 ) ;
}
if ( ! ( V_7 & V_60 ) )
goto V_61;
V_9 = F_2 ( V_2 , V_62 ,
V_19 | V_20 | V_21 ,
0 , V_8 , & V_13 , 2 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_12 ) ;
goto V_61;
}
if ( F_5 ( V_13 ) == V_4 -> V_13 )
goto V_61;
V_13 = F_10 ( V_4 -> V_13 ) ;
V_9 = F_9 ( V_2 , V_63 ,
V_19 | V_51 | V_21 ,
0 , V_8 , & V_13 , 2 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_13 ) ;
V_61:
if ( V_2 -> V_64 -> V_65 > V_4 -> V_13 - V_10 )
V_2 -> V_64 -> V_65 = V_4 -> V_13 - V_10 ;
if ( V_4 -> V_66 ) {
V_11 = F_5 ( V_4 -> V_66 -> V_67 ) ;
if ( V_11 != 0 && V_11 < V_2 -> V_64 -> V_65 )
V_2 -> V_64 -> V_65 = V_11 ;
}
return 0 ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_68 * V_23 )
{
struct V_69 * V_70 , * V_71 = NULL , * V_61 = NULL ;
T_2 V_72 ;
for ( V_72 = 0 ; V_72 < V_23 -> V_15 -> V_16 . V_73 ; V_72 ++ ) {
V_70 = V_23 -> V_15 -> V_74 + V_72 ;
switch ( V_70 -> V_16 . V_75 & V_76 ) {
case V_77 :
if ( F_12 ( & V_70 -> V_16 ) ) {
if ( ! V_2 -> V_78 )
V_2 -> V_78 = V_70 ;
}
break;
case V_79 :
if ( F_12 ( & V_70 -> V_16 ) ) {
if ( ! V_71 )
V_71 = V_70 ;
} else {
if ( ! V_61 )
V_61 = V_70 ;
}
break;
default:
break;
}
}
if ( V_71 && ! V_2 -> V_71 )
V_2 -> V_71 = F_13 ( V_2 -> V_80 ,
V_71 -> V_16 . V_81 &
V_82 ) ;
if ( V_61 && ! V_2 -> V_61 )
V_2 -> V_61 = F_14 ( V_2 -> V_80 ,
V_61 -> V_16 . V_81 &
V_82 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
if ( V_4 -> V_83 != NULL ) {
F_16 ( V_4 -> V_83 ) ;
V_4 -> V_83 = NULL ;
}
if ( V_4 -> V_84 != NULL ) {
F_16 ( V_4 -> V_84 ) ;
V_4 -> V_84 = NULL ;
}
F_17 ( V_4 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_68 * V_23 , T_2 V_85 )
{
const struct V_86 * V_87 = NULL ;
struct V_3 * V_4 ;
struct V_88 * V_89 ;
T_2 * V_90 ;
int V_91 ;
int V_92 ;
T_2 V_8 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_93 ) ;
if ( ! V_4 )
return - V_94 ;
F_20 ( & V_4 -> V_95 , V_96 , V_97 ) ;
V_4 -> V_95 . V_98 = & V_99 ;
V_4 -> V_100 . V_5 = ( unsigned long ) V_2 ;
V_4 -> V_100 . V_101 = V_102 ;
F_21 ( & V_4 -> V_103 , 0 ) ;
F_22 ( & V_4 -> V_104 ) ;
V_2 -> V_5 [ 0 ] = ( unsigned long ) V_4 ;
V_4 -> V_14 = V_23 ;
V_89 = F_23 ( V_23 ) ;
V_90 = V_23 -> V_15 -> V_105 ;
V_91 = V_23 -> V_15 -> V_106 ;
while ( ( V_91 > 0 ) && ( V_90 [ 0 ] > 2 ) && ( V_90 [ 0 ] <= V_91 ) ) {
if ( V_90 [ 1 ] != V_107 )
goto V_108;
switch ( V_90 [ 2 ] ) {
case V_109 :
if ( V_90 [ 0 ] < sizeof( * V_87 ) )
break;
V_87 = ( const struct V_86 * ) V_90 ;
if ( V_23 -> V_15 -> V_16 . V_17 !=
V_87 -> V_110 ) {
F_7 ( & V_23 -> V_2 , L_14 ) ;
goto error;
}
V_4 -> V_5 = F_24 ( V_2 -> V_80 ,
V_87 -> V_111 ) ;
break;
case V_112 :
if ( V_90 [ 0 ] < sizeof( * ( V_4 -> V_44 ) ) )
break;
V_4 -> V_44 =
( const struct V_113 * ) V_90 ;
break;
case V_114 :
if ( V_90 [ 0 ] < sizeof( * ( V_4 -> V_42 ) ) )
break;
V_4 -> V_42 = ( const struct V_115 * ) V_90 ;
break;
case V_116 :
if ( V_90 [ 0 ] < sizeof( * ( V_4 -> V_37 ) ) )
break;
V_4 -> V_37 = ( const struct V_117 * ) V_90 ;
break;
case V_118 :
if ( V_90 [ 0 ] < sizeof( * ( V_4 -> V_66 ) ) )
break;
V_4 -> V_66 =
( const struct V_119 * ) V_90 ;
break;
default:
break;
}
V_108:
V_92 = V_90 [ 0 ] ;
V_90 += V_92 ;
V_91 -= V_92 ;
}
if ( ! V_87 && V_23 -> V_120 && V_23 -> V_120 -> V_121 == 2 ) {
V_4 -> V_5 = F_24 ( V_2 -> V_80 , V_23 -> V_15 -> V_16 . V_17 + 1 ) ;
F_7 ( & V_23 -> V_2 , L_15 ) ;
}
if ( ! V_4 -> V_5 || ( ! V_4 -> V_37 && ! V_4 -> V_44 ) ) {
F_7 ( & V_23 -> V_2 , L_16 ) ;
goto error;
}
if ( V_4 -> V_5 != V_4 -> V_14 ) {
V_92 = F_25 ( V_89 , V_4 -> V_5 , V_2 ) ;
if ( V_92 ) {
F_7 ( & V_23 -> V_2 , L_17 ) ;
goto error;
}
}
V_8 = V_4 -> V_5 -> V_15 -> V_16 . V_17 ;
V_92 = F_26 ( V_2 -> V_80 , V_8 , 0 ) ;
if ( V_92 ) {
F_7 ( & V_23 -> V_2 , L_18 ) ;
goto V_122;
}
if ( F_1 ( V_2 ) )
goto V_122;
V_92 = F_26 ( V_2 -> V_80 , V_8 , V_85 ) ;
if ( V_92 ) {
F_7 ( & V_23 -> V_2 , L_18 ) ;
goto V_122;
}
F_11 ( V_2 , V_4 -> V_5 ) ;
F_11 ( V_2 , V_4 -> V_14 ) ;
if ( ! V_2 -> V_71 || ! V_2 -> V_61 || ! V_2 -> V_78 ) {
F_7 ( & V_23 -> V_2 , L_19 ) ;
goto V_122;
}
F_27 ( V_4 -> V_5 , V_2 ) ;
F_27 ( V_4 -> V_14 , V_2 ) ;
if ( V_4 -> V_44 ) {
V_92 = F_28 ( V_2 , V_4 -> V_44 -> V_123 ) ;
if ( V_92 ) {
F_7 ( & V_23 -> V_2 , L_20 ) ;
goto V_122;
}
F_29 ( & V_23 -> V_2 , L_21 , V_2 -> V_64 -> V_124 ) ;
}
V_2 -> V_125 = V_4 -> V_26 ;
V_2 -> V_126 = V_4 -> V_24 ;
if ( V_4 -> V_26 != F_4 ( V_4 -> V_22 . V_27 ) &&
V_4 -> V_26 % F_30 ( V_2 -> V_80 , V_2 -> V_61 , 1 ) == 0 )
V_4 -> V_26 ++ ;
return 0 ;
V_122:
F_27 ( V_4 -> V_14 , NULL ) ;
F_27 ( V_4 -> V_5 , NULL ) ;
if ( V_4 -> V_5 != V_4 -> V_14 )
F_31 ( V_89 , V_4 -> V_5 ) ;
error:
F_15 ( (struct V_3 * ) V_2 -> V_5 [ 0 ] ) ;
V_2 -> V_5 [ 0 ] = 0 ;
F_29 ( & V_23 -> V_2 , L_22 ) ;
return - V_127 ;
}
void F_32 ( struct V_1 * V_2 , struct V_68 * V_23 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
struct V_88 * V_89 = F_23 ( V_23 ) ;
if ( V_4 == NULL )
return;
F_21 ( & V_4 -> V_103 , 1 ) ;
if ( F_33 ( & V_4 -> V_95 ) )
F_34 ( & V_4 -> V_95 ) ;
F_35 ( & V_4 -> V_100 ) ;
if ( V_4 -> V_14 == V_4 -> V_5 )
V_4 -> V_5 = NULL ;
if ( V_23 == V_4 -> V_14 && V_4 -> V_5 ) {
F_27 ( V_4 -> V_5 , NULL ) ;
F_31 ( V_89 , V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
} else if ( V_23 == V_4 -> V_5 && V_4 -> V_14 ) {
F_27 ( V_4 -> V_14 , NULL ) ;
F_31 ( V_89 , V_4 -> V_14 ) ;
V_4 -> V_14 = NULL ;
}
F_27 ( V_23 , NULL ) ;
F_15 ( V_4 ) ;
}
T_2 F_36 ( struct V_1 * V_2 , struct V_68 * V_23 )
{
struct V_128 * V_129 ;
if ( V_130 && V_23 -> V_131 == 2 ) {
V_129 = F_37 ( V_23 , V_132 ) ;
if ( V_129 && F_6 ( V_129 ) &&
! F_26 ( V_2 -> V_80 ,
V_23 -> V_15 -> V_16 . V_17 ,
V_132 ) )
return V_133 ;
}
return V_134 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_68 * V_23 )
{
int V_135 ;
F_36 ( V_2 , V_23 ) ;
if ( F_6 ( V_23 -> V_15 ) )
return - V_127 ;
V_135 = F_18 ( V_2 , V_23 , 1 ) ;
F_39 ( V_2 , 0 , 0 ) ;
return V_135 ;
}
static void F_40 ( struct V_136 * V_137 , T_6 V_138 , T_6 V_139 , T_6 V_140 )
{
T_6 V_141 = F_41 ( V_137 -> V_91 , V_138 ) - V_137 -> V_91 + V_139 ;
if ( V_137 -> V_91 + V_141 > V_140 )
V_141 = V_140 - V_137 -> V_91 ;
if ( V_141 && F_42 ( V_137 ) >= V_141 )
memset ( F_43 ( V_137 , V_141 ) , 0 , V_141 ) ;
}
static struct V_142 * F_44 ( struct V_3 * V_4 , struct V_136 * V_137 , T_5 V_143 , T_6 V_144 )
{
struct V_142 * V_145 = NULL ;
struct V_146 * V_147 = ( void * ) V_137 -> V_5 ;
T_6 V_148 = F_5 ( V_147 -> V_149 ) ;
while ( V_148 ) {
V_145 = (struct V_142 * ) ( V_137 -> V_5 + V_148 ) ;
if ( V_145 -> V_150 == V_143 )
return V_145 ;
V_148 = F_5 ( V_145 -> V_151 ) ;
}
F_40 ( V_137 , V_4 -> V_32 , 0 , V_4 -> V_26 ) ;
if ( ( V_4 -> V_26 - V_137 -> V_91 - V_144 ) < V_152 )
return NULL ;
if ( V_145 )
V_145 -> V_151 = F_10 ( V_137 -> V_91 ) ;
else
V_147 -> V_149 = F_10 ( V_137 -> V_91 ) ;
V_145 = (struct V_142 * ) memset ( F_43 ( V_137 , V_152 ) , 0 , V_152 ) ;
V_145 -> V_150 = V_143 ;
V_145 -> V_153 = F_10 ( sizeof( struct V_142 ) + sizeof( struct V_154 ) ) ;
return V_145 ;
}
struct V_136 *
F_45 ( struct V_1 * V_2 , struct V_136 * V_137 , T_5 V_143 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
struct V_146 * V_147 ;
struct V_142 * V_145 ;
struct V_136 * V_155 ;
T_3 V_156 = 0 , V_157 , V_158 ;
T_2 V_159 = 0 ;
if ( V_137 != NULL ) {
F_46 ( V_137 , V_4 -> V_83 ) ;
F_46 ( V_143 , V_4 -> V_160 ) ;
} else {
V_159 = 1 ;
}
V_155 = V_4 -> V_84 ;
if ( ! V_155 ) {
V_155 = F_47 ( V_4 -> V_26 , V_161 ) ;
if ( V_155 == NULL ) {
if ( V_137 != NULL ) {
F_16 ( V_137 ) ;
V_2 -> V_64 -> V_162 . V_163 ++ ;
}
goto V_164;
}
V_147 = (struct V_146 * ) memset ( F_43 ( V_155 , sizeof( struct V_146 ) ) , 0 , sizeof( struct V_146 ) ) ;
V_147 -> V_150 = F_8 ( V_165 ) ;
V_147 -> V_166 = F_10 ( sizeof( struct V_146 ) ) ;
V_147 -> V_167 = F_10 ( V_4 -> V_168 ++ ) ;
V_4 -> V_169 = 0 ;
}
for ( V_156 = V_4 -> V_169 ; V_156 < V_4 -> V_34 ; V_156 ++ ) {
if ( V_137 == NULL ) {
V_137 = V_4 -> V_83 ;
V_143 = V_4 -> V_160 ;
V_4 -> V_83 = NULL ;
if ( V_137 == NULL )
break;
}
V_145 = F_44 ( V_4 , V_155 , V_143 , V_137 -> V_91 + V_4 -> V_30 + V_4 -> V_28 ) ;
F_40 ( V_155 , V_4 -> V_30 , V_4 -> V_28 , V_4 -> V_26 ) ;
if ( ! V_145 || V_155 -> V_91 + V_137 -> V_91 > V_4 -> V_26 ) {
if ( V_156 == 0 ) {
F_16 ( V_137 ) ;
V_137 = NULL ;
V_2 -> V_64 -> V_162 . V_163 ++ ;
} else {
if ( V_4 -> V_83 != NULL ) {
F_16 ( V_4 -> V_83 ) ;
V_2 -> V_64 -> V_162 . V_163 ++ ;
}
V_4 -> V_83 = V_137 ;
V_4 -> V_160 = V_143 ;
V_137 = NULL ;
V_159 = 1 ;
}
break;
}
V_158 = F_5 ( V_145 -> V_153 ) ;
V_157 = ( V_158 - sizeof( struct V_142 ) ) / sizeof( struct V_154 ) - 1 ;
V_145 -> V_170 [ V_157 ] . V_171 = F_10 ( V_137 -> V_91 ) ;
V_145 -> V_170 [ V_157 ] . V_172 = F_10 ( V_155 -> V_91 ) ;
V_145 -> V_153 = F_10 ( V_158 + sizeof( struct V_154 ) ) ;
memcpy ( F_43 ( V_155 , V_137 -> V_91 ) , V_137 -> V_5 , V_137 -> V_91 ) ;
F_16 ( V_137 ) ;
V_137 = NULL ;
if ( V_157 >= V_47 ) {
V_159 = 1 ;
break;
}
}
if ( V_137 != NULL ) {
F_16 ( V_137 ) ;
V_137 = NULL ;
V_2 -> V_64 -> V_162 . V_163 ++ ;
}
V_4 -> V_169 = V_156 ;
if ( V_156 == 0 ) {
V_4 -> V_84 = V_155 ;
goto V_164;
} else if ( ( V_156 < V_4 -> V_34 ) && ( V_159 == 0 ) ) {
V_4 -> V_84 = V_155 ;
if ( V_156 < V_173 )
V_4 -> V_174 = V_175 ;
goto V_164;
} else {
}
if ( ! ( V_2 -> V_176 -> V_7 & V_177 ) &&
V_155 -> V_91 > V_178 )
memset ( F_43 ( V_155 , V_4 -> V_26 - V_155 -> V_91 ) , 0 ,
V_4 -> V_26 - V_155 -> V_91 ) ;
else if ( V_155 -> V_91 < V_4 -> V_26 && ( V_155 -> V_91 % V_2 -> V_179 ) == 0 )
* F_43 ( V_155 , 1 ) = 0 ;
V_147 = (struct V_146 * ) V_155 -> V_5 ;
V_147 -> V_180 = F_10 ( V_155 -> V_91 ) ;
V_4 -> V_84 = NULL ;
V_2 -> V_64 -> V_162 . V_181 += V_4 -> V_169 ;
return V_155 ;
V_164:
if ( V_4 -> V_84 != NULL )
F_48 ( V_4 ) ;
return NULL ;
}
static void F_48 ( struct V_3 * V_4 )
{
if ( ! ( F_33 ( & V_4 -> V_95 ) || F_49 ( & V_4 -> V_103 ) ) )
F_50 ( & V_4 -> V_95 ,
F_51 ( 0 , V_182 ) ,
V_97 ) ;
}
static enum V_183 V_99 ( struct V_184 * V_185 )
{
struct V_3 * V_4 =
F_52 ( V_185 , struct V_3 , V_95 ) ;
if ( ! F_49 ( & V_4 -> V_103 ) )
F_53 ( & V_4 -> V_100 ) ;
return V_186 ;
}
static void V_102 ( unsigned long V_187 )
{
struct V_1 * V_2 = (struct V_1 * ) V_187 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
F_54 ( & V_4 -> V_104 ) ;
if ( V_4 -> V_174 != 0 ) {
V_4 -> V_174 -- ;
F_48 ( V_4 ) ;
F_55 ( & V_4 -> V_104 ) ;
} else if ( V_2 -> V_64 != NULL ) {
F_55 ( & V_4 -> V_104 ) ;
F_56 ( V_2 -> V_64 ) ;
F_57 ( NULL , V_2 -> V_64 ) ;
F_58 ( V_2 -> V_64 ) ;
} else {
F_55 ( & V_4 -> V_104 ) ;
}
}
struct V_136 *
F_59 ( struct V_1 * V_2 , struct V_136 * V_137 , T_7 V_7 )
{
struct V_136 * V_155 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_4 == NULL )
goto error;
F_54 ( & V_4 -> V_104 ) ;
V_155 = F_45 ( V_2 , V_137 , F_8 ( V_188 ) ) ;
F_55 ( & V_4 -> V_104 ) ;
return V_155 ;
error:
if ( V_137 != NULL )
F_16 ( V_137 ) ;
return NULL ;
}
int F_60 ( struct V_3 * V_4 , struct V_136 * V_189 )
{
struct V_1 * V_2 = F_61 ( V_189 -> V_2 ) ;
struct V_146 * V_147 ;
int V_91 ;
int V_135 = - V_38 ;
if ( V_4 == NULL )
goto error;
if ( V_189 -> V_91 < ( sizeof( struct V_146 ) +
sizeof( struct V_142 ) ) ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 , L_23 ) ;
goto error;
}
V_147 = (struct V_146 * ) V_189 -> V_5 ;
if ( V_147 -> V_150 != F_8 ( V_165 ) ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 ,
L_24 ,
F_4 ( V_147 -> V_150 ) ) ;
goto error;
}
V_91 = F_5 ( V_147 -> V_180 ) ;
if ( V_91 > V_4 -> V_24 ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 ,
L_25 , V_91 ,
V_4 -> V_24 ) ;
goto error;
}
if ( ( V_4 -> V_191 + 1 ) != F_5 ( V_147 -> V_167 ) &&
( V_4 -> V_191 || F_5 ( V_147 -> V_167 ) ) &&
! ( ( V_4 -> V_191 == 0xffff ) && ! F_5 ( V_147 -> V_167 ) ) ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 ,
L_26 ,
V_4 -> V_191 , F_5 ( V_147 -> V_167 ) ) ;
}
V_4 -> V_191 = F_5 ( V_147 -> V_167 ) ;
V_135 = F_5 ( V_147 -> V_149 ) ;
error:
return V_135 ;
}
int F_63 ( struct V_136 * V_189 , int V_148 )
{
struct V_1 * V_2 = F_61 ( V_189 -> V_2 ) ;
struct V_142 * V_145 ;
int V_135 = - V_38 ;
if ( ( V_148 + sizeof( struct V_142 ) ) > V_189 -> V_91 ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 , L_27 ,
V_148 ) ;
goto error;
}
V_145 = (struct V_142 * ) ( V_189 -> V_5 + V_148 ) ;
if ( F_5 ( V_145 -> V_153 ) < V_192 ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 , L_28 ,
F_5 ( V_145 -> V_153 ) ) ;
goto error;
}
V_135 = ( ( F_5 ( V_145 -> V_153 ) -
sizeof( struct V_142 ) ) /
sizeof( struct V_154 ) ) ;
V_135 -- ;
if ( ( sizeof( struct V_142 ) +
V_135 * ( sizeof( struct V_154 ) ) ) > V_189 -> V_91 ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 , L_29 , V_135 ) ;
V_135 = - V_38 ;
}
error:
return V_135 ;
}
int F_64 ( struct V_1 * V_2 , struct V_136 * V_189 )
{
struct V_136 * V_137 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
int V_91 ;
int V_193 ;
int V_194 ;
int V_195 ;
struct V_142 * V_145 ;
struct V_154 * V_170 ;
int V_148 ;
int V_196 = 50 ;
V_148 = F_60 ( V_4 , V_189 ) ;
if ( V_148 < 0 )
goto error;
V_197:
V_193 = F_63 ( V_189 , V_148 ) ;
if ( V_193 < 0 )
goto error;
V_145 = (struct V_142 * ) ( V_189 -> V_5 + V_148 ) ;
if ( V_145 -> V_150 != F_8 ( V_188 ) ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 ,
L_30 ,
F_4 ( V_145 -> V_150 ) ) ;
goto V_198;
}
V_170 = V_145 -> V_170 ;
for ( V_194 = 0 ; V_194 < V_193 ; V_194 ++ , V_170 ++ ) {
V_195 = F_5 ( V_170 -> V_172 ) ;
V_91 = F_5 ( V_170 -> V_171 ) ;
if ( ( V_195 == 0 ) || ( V_91 == 0 ) ) {
if ( ! V_194 )
goto V_198;
break;
}
if ( ( ( V_195 + V_91 ) > V_189 -> V_91 ) ||
( V_91 > V_4 -> V_24 ) || ( V_91 < V_43 ) ) {
F_62 ( V_2 , V_190 , V_2 -> V_64 ,
L_31 ,
V_194 , V_195 , V_91 , V_189 ) ;
if ( ! V_194 )
goto V_198;
break;
} else {
V_137 = F_65 ( V_189 , V_161 ) ;
if ( ! V_137 )
goto error;
V_137 -> V_91 = V_91 ;
V_137 -> V_5 = ( ( T_2 * ) V_189 -> V_5 ) + V_195 ;
F_66 ( V_137 , V_91 ) ;
F_67 ( V_2 , V_137 ) ;
}
}
V_198:
V_148 = F_5 ( V_145 -> V_151 ) ;
if ( V_148 && V_196 -- )
goto V_197;
return 1 ;
error:
return 0 ;
}
static void
F_68 ( struct V_1 * V_2 ,
struct V_199 * V_5 )
{
T_8 V_200 = F_4 ( V_5 -> V_201 ) ;
T_8 V_202 = F_4 ( V_5 -> V_203 ) ;
if ( ( V_202 > 1000000 ) && ( V_200 > 1000000 ) ) {
F_69 ( V_2 , V_204 , V_2 -> V_64 ,
L_32 ,
( unsigned int ) ( V_200 / 1000000U ) ,
( unsigned int ) ( V_202 / 1000000U ) ) ;
} else {
F_69 ( V_2 , V_204 , V_2 -> V_64 ,
L_33 ,
( unsigned int ) ( V_200 / 1000U ) ,
( unsigned int ) ( V_202 / 1000U ) ) ;
}
}
static void F_70 ( struct V_1 * V_2 , struct V_205 * V_205 )
{
struct V_3 * V_4 ;
struct V_206 * V_207 ;
V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_205 -> V_208 < sizeof( * V_207 ) )
return;
if ( F_71 ( V_209 , & V_2 -> V_7 ) ) {
F_68 ( V_2 ,
(struct V_199 * ) V_205 -> V_210 ) ;
return;
}
V_207 = V_205 -> V_210 ;
switch ( V_207 -> V_211 ) {
case V_212 :
V_4 -> V_213 = F_5 ( V_207 -> V_214 ) ;
F_69 ( V_2 , V_204 , V_2 -> V_64 ,
L_34 ,
V_4 -> V_213 ? L_35 : L_36 ) ;
F_39 ( V_2 , V_4 -> V_213 , 0 ) ;
break;
case V_215 :
if ( V_205 -> V_208 < ( sizeof( * V_207 ) +
sizeof( struct V_199 ) ) )
F_72 ( V_209 , & V_2 -> V_7 ) ;
else
F_68 ( V_2 ,
(struct V_199 * ) & V_207 [ 1 ] ) ;
break;
default:
F_7 ( & V_2 -> V_80 -> V_2 ,
L_37 ,
V_207 -> V_211 ) ;
break;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_4 == NULL )
return 1 ;
return ! V_4 -> V_213 ;
}
