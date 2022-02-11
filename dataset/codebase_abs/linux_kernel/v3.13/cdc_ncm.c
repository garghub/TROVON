static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
struct V_6 V_7 ;
T_1 V_8 ;
T_2 V_9 ;
T_2 V_10 ;
int V_11 ;
int V_12 ;
T_3 V_13 ;
T_4 V_14 ;
V_10 = V_4 -> V_15 -> V_16 -> V_17 . V_18 ;
V_11 = F_2 ( V_2 , V_19 ,
V_20 | V_21
| V_22 ,
0 , V_10 , & V_7 ,
sizeof( V_7 ) ) ;
if ( V_11 < 0 ) {
F_3 ( & V_2 -> V_23 -> V_2 , L_1 ) ;
return V_11 ;
}
V_4 -> V_24 = F_4 ( V_7 . V_25 ) ;
V_4 -> V_26 = F_4 ( V_7 . V_27 ) ;
V_4 -> V_28 = F_5 ( V_7 . V_29 ) ;
V_4 -> V_30 = F_5 ( V_7 . V_31 ) ;
V_4 -> V_32 = F_5 ( V_7 . V_33 ) ;
V_4 -> V_34 = F_5 ( V_7 . V_35 ) ;
V_13 = F_5 ( V_7 . V_36 ) ;
if ( F_6 ( V_4 -> V_15 -> V_16 ) ) {
if ( ! V_4 -> V_37 )
return - V_38 ;
V_12 = 0 ;
V_9 = V_4 -> V_37 -> V_39 ;
V_4 -> V_14 = F_5 ( V_4 -> V_37 -> V_40 ) ;
if ( V_4 -> V_14 < V_41 )
V_4 -> V_14 = V_41 ;
} else {
if ( ! V_4 -> V_42 )
return - V_38 ;
V_12 = V_43 ;
V_9 = V_4 -> V_42 -> V_39 ;
V_4 -> V_14 = F_5 ( V_4 -> V_44 -> V_40 ) ;
if ( V_4 -> V_14 < V_45 )
V_4 -> V_14 = V_45 ;
}
if ( V_4 -> V_14 > V_46 )
V_4 -> V_14 = V_46 ;
F_7 ( & V_2 -> V_23 -> V_2 ,
L_2 ,
V_4 -> V_24 , V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_30 ,
V_4 -> V_32 , V_4 -> V_34 , V_9 ) ;
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
if ( V_4 -> V_24 != F_4 ( V_7 . V_25 ) ) {
T_5 V_25 = F_8 ( V_4 -> V_24 ) ;
V_11 = F_9 ( V_2 , V_50 ,
V_20 | V_51
| V_22 ,
0 , V_10 , & V_25 , 4 ) ;
if ( V_11 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_5 ) ;
}
if ( V_4 -> V_26 > V_52 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_6 ,
V_52 ) ;
V_4 -> V_26 = V_52 ;
if ( V_4 -> V_26 % F_10 ( V_2 -> V_53 , V_2 -> V_54 , 1 ) == 0 )
V_4 -> V_26 ++ ;
}
V_8 = V_4 -> V_32 ;
if ( ( V_8 < V_55 ) ||
( V_8 != ( ( - V_8 ) & V_8 ) ) || ( V_8 >= V_4 -> V_26 ) ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_7 ) ;
V_4 -> V_32 = V_55 ;
}
V_8 = V_4 -> V_30 ;
if ( ( V_8 < V_55 ) ||
( V_8 != ( ( - V_8 ) & V_8 ) ) || ( V_8 >= V_4 -> V_26 ) ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_8 ) ;
V_4 -> V_30 = V_55 ;
}
if ( V_4 -> V_28 >= V_4 -> V_30 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_9 ) ;
V_4 -> V_28 = 0 ;
}
V_4 -> V_28 = ( ( V_4 -> V_28 - V_12 ) &
( V_4 -> V_30 - 1 ) ) ;
if ( V_9 & V_56 ) {
V_11 = F_9 ( V_2 , V_57 ,
V_20 | V_51
| V_22 ,
V_58 ,
V_10 , NULL , 0 ) ;
if ( V_11 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_10 ) ;
}
if ( V_13 & V_59 ) {
V_11 = F_9 ( V_2 , V_60 ,
V_20 | V_51
| V_22 ,
V_61 ,
V_10 , NULL , 0 ) ;
if ( V_11 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_11 ) ;
}
if ( ! ( V_9 & V_62 ) )
goto V_54;
V_11 = F_2 ( V_2 , V_63 ,
V_20 | V_21 | V_22 ,
0 , V_10 , & V_14 , 2 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_2 -> V_23 -> V_2 , L_12 ) ;
goto V_54;
}
if ( F_5 ( V_14 ) == V_4 -> V_14 )
goto V_54;
V_14 = F_11 ( V_4 -> V_14 ) ;
V_11 = F_9 ( V_2 , V_64 ,
V_20 | V_51 | V_22 ,
0 , V_10 , & V_14 , 2 ) ;
if ( V_11 < 0 )
F_7 ( & V_2 -> V_23 -> V_2 , L_13 ) ;
V_54:
if ( V_2 -> V_65 -> V_66 > V_4 -> V_14 - V_12 )
V_2 -> V_65 -> V_66 = V_4 -> V_14 - V_12 ;
return 0 ;
}
static void
F_12 ( struct V_1 * V_2 , struct V_67 * V_23 )
{
struct V_68 * V_69 , * V_70 = NULL , * V_54 = NULL ;
T_2 V_71 ;
for ( V_71 = 0 ; V_71 < V_23 -> V_16 -> V_17 . V_72 ; V_71 ++ ) {
V_69 = V_23 -> V_16 -> V_73 + V_71 ;
switch ( V_69 -> V_17 . V_74 & V_75 ) {
case V_76 :
if ( F_13 ( & V_69 -> V_17 ) ) {
if ( ! V_2 -> V_77 )
V_2 -> V_77 = V_69 ;
}
break;
case V_78 :
if ( F_13 ( & V_69 -> V_17 ) ) {
if ( ! V_70 )
V_70 = V_69 ;
} else {
if ( ! V_54 )
V_54 = V_69 ;
}
break;
default:
break;
}
}
if ( V_70 && ! V_2 -> V_70 )
V_2 -> V_70 = F_14 ( V_2 -> V_53 ,
V_70 -> V_17 . V_79 &
V_80 ) ;
if ( V_54 && ! V_2 -> V_54 )
V_2 -> V_54 = F_15 ( V_2 -> V_53 ,
V_54 -> V_17 . V_79 &
V_80 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
if ( V_4 -> V_81 != NULL ) {
F_17 ( V_4 -> V_81 ) ;
V_4 -> V_81 = NULL ;
}
if ( V_4 -> V_82 != NULL ) {
F_17 ( V_4 -> V_82 ) ;
V_4 -> V_82 = NULL ;
}
F_18 ( V_4 ) ;
}
int F_19 ( struct V_1 * V_2 , struct V_67 * V_23 , T_2 V_83 )
{
const struct V_84 * V_85 = NULL ;
struct V_3 * V_4 ;
struct V_86 * V_87 ;
T_2 * V_88 ;
int V_89 ;
int V_90 ;
T_2 V_10 ;
V_4 = F_20 ( sizeof( * V_4 ) , V_91 ) ;
if ( ! V_4 )
return - V_92 ;
F_21 ( & V_4 -> V_93 , V_94 , V_95 ) ;
V_4 -> V_93 . V_96 = & V_97 ;
V_4 -> V_98 . V_5 = ( unsigned long ) V_2 ;
V_4 -> V_98 . V_99 = V_100 ;
F_22 ( & V_4 -> V_101 , 0 ) ;
F_23 ( & V_4 -> V_102 ) ;
V_2 -> V_5 [ 0 ] = ( unsigned long ) V_4 ;
V_4 -> V_15 = V_23 ;
V_87 = F_24 ( V_23 ) ;
V_88 = V_23 -> V_16 -> V_103 ;
V_89 = V_23 -> V_16 -> V_104 ;
while ( ( V_89 > 0 ) && ( V_88 [ 0 ] > 2 ) && ( V_88 [ 0 ] <= V_89 ) ) {
if ( V_88 [ 1 ] != V_105 )
goto V_106;
switch ( V_88 [ 2 ] ) {
case V_107 :
if ( V_88 [ 0 ] < sizeof( * V_85 ) )
break;
V_85 = ( const struct V_84 * ) V_88 ;
if ( V_23 -> V_16 -> V_17 . V_18 !=
V_85 -> V_108 ) {
F_7 ( & V_23 -> V_2 , L_14 ) ;
goto error;
}
V_4 -> V_5 = F_25 ( V_2 -> V_53 ,
V_85 -> V_109 ) ;
break;
case V_110 :
if ( V_88 [ 0 ] < sizeof( * ( V_4 -> V_44 ) ) )
break;
V_4 -> V_44 =
( const struct V_111 * ) V_88 ;
break;
case V_112 :
if ( V_88 [ 0 ] < sizeof( * ( V_4 -> V_42 ) ) )
break;
V_4 -> V_42 = ( const struct V_113 * ) V_88 ;
break;
case V_114 :
if ( V_88 [ 0 ] < sizeof( * ( V_4 -> V_37 ) ) )
break;
V_4 -> V_37 = ( const struct V_115 * ) V_88 ;
break;
default:
break;
}
V_106:
V_90 = V_88 [ 0 ] ;
V_88 += V_90 ;
V_89 -= V_90 ;
}
if ( ! V_85 && V_23 -> V_116 && V_23 -> V_116 -> V_117 == 2 ) {
V_4 -> V_5 = F_25 ( V_2 -> V_53 , V_23 -> V_16 -> V_17 . V_18 + 1 ) ;
F_7 ( & V_23 -> V_2 , L_15 ) ;
}
if ( ! V_4 -> V_5 || ( ! V_4 -> V_37 && ! V_4 -> V_44 ) ) {
F_7 ( & V_23 -> V_2 , L_16 ) ;
goto error;
}
if ( V_4 -> V_5 != V_4 -> V_15 ) {
V_90 = F_26 ( V_87 , V_4 -> V_5 , V_2 ) ;
if ( V_90 ) {
F_7 ( & V_23 -> V_2 , L_17 ) ;
goto error;
}
}
V_10 = V_4 -> V_5 -> V_16 -> V_17 . V_18 ;
V_90 = F_27 ( V_2 -> V_53 , V_10 , 0 ) ;
if ( V_90 ) {
F_7 ( & V_23 -> V_2 , L_18 ) ;
goto V_118;
}
V_90 = F_27 ( V_2 -> V_53 , V_10 , V_83 ) ;
if ( V_90 ) {
F_7 ( & V_23 -> V_2 , L_18 ) ;
goto V_118;
}
F_12 ( V_2 , V_4 -> V_5 ) ;
F_12 ( V_2 , V_4 -> V_15 ) ;
if ( ! V_2 -> V_70 || ! V_2 -> V_54 || ! V_2 -> V_77 ) {
F_7 ( & V_23 -> V_2 , L_19 ) ;
goto V_118;
}
if ( F_1 ( V_2 ) ) {
F_7 ( & V_23 -> V_2 , L_20 ) ;
goto V_118;
}
F_28 ( V_4 -> V_5 , V_2 ) ;
F_28 ( V_4 -> V_15 , V_2 ) ;
if ( V_4 -> V_44 ) {
V_90 = F_29 ( V_2 , V_4 -> V_44 -> V_119 ) ;
if ( V_90 ) {
F_7 ( & V_23 -> V_2 , L_21 ) ;
goto V_118;
}
F_30 ( & V_23 -> V_2 , L_22 , V_2 -> V_65 -> V_120 ) ;
}
V_2 -> V_121 = V_4 -> V_26 ;
V_2 -> V_122 = V_4 -> V_24 ;
return 0 ;
V_118:
F_28 ( V_4 -> V_15 , NULL ) ;
F_28 ( V_4 -> V_5 , NULL ) ;
if ( V_4 -> V_5 != V_4 -> V_15 )
F_31 ( V_87 , V_4 -> V_5 ) ;
error:
F_16 ( (struct V_3 * ) V_2 -> V_5 [ 0 ] ) ;
V_2 -> V_5 [ 0 ] = 0 ;
F_30 ( & V_23 -> V_2 , L_23 ) ;
return - V_123 ;
}
void F_32 ( struct V_1 * V_2 , struct V_67 * V_23 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
struct V_86 * V_87 = F_24 ( V_23 ) ;
if ( V_4 == NULL )
return;
F_22 ( & V_4 -> V_101 , 1 ) ;
if ( F_33 ( & V_4 -> V_93 ) )
F_34 ( & V_4 -> V_93 ) ;
F_35 ( & V_4 -> V_98 ) ;
if ( V_4 -> V_15 == V_4 -> V_5 )
V_4 -> V_5 = NULL ;
if ( V_23 == V_4 -> V_15 && V_4 -> V_5 ) {
F_28 ( V_4 -> V_5 , NULL ) ;
F_31 ( V_87 , V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
} else if ( V_23 == V_4 -> V_5 && V_4 -> V_15 ) {
F_28 ( V_4 -> V_15 , NULL ) ;
F_31 ( V_87 , V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
}
F_28 ( V_23 , NULL ) ;
F_16 ( V_4 ) ;
}
T_2 F_36 ( struct V_1 * V_2 , struct V_67 * V_23 )
{
struct V_124 * V_125 ;
if ( V_126 && V_23 -> V_127 == 2 ) {
V_125 = F_37 ( V_23 , V_128 ) ;
if ( V_125 && F_6 ( V_125 ) &&
! F_27 ( V_2 -> V_53 ,
V_23 -> V_16 -> V_17 . V_18 ,
V_128 ) )
return V_129 ;
}
return V_130 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_67 * V_23 )
{
int V_131 ;
F_36 ( V_2 , V_23 ) ;
if ( F_6 ( V_23 -> V_16 ) )
return - V_123 ;
V_131 = F_19 ( V_2 , V_23 , 1 ) ;
F_39 ( V_2 , 0 , 0 ) ;
return V_131 ;
}
static void F_40 ( struct V_132 * V_133 , T_6 V_134 , T_6 V_135 , T_6 V_136 )
{
T_6 V_137 = F_41 ( V_133 -> V_89 , V_134 ) - V_133 -> V_89 + V_135 ;
if ( V_133 -> V_89 + V_137 > V_136 )
V_137 = V_136 - V_133 -> V_89 ;
if ( V_137 && F_42 ( V_133 ) >= V_137 )
memset ( F_43 ( V_133 , V_137 ) , 0 , V_137 ) ;
}
static struct V_138 * F_44 ( struct V_3 * V_4 , struct V_132 * V_133 , T_5 V_139 , T_6 V_140 )
{
struct V_138 * V_141 = NULL ;
struct V_142 * V_143 = ( void * ) V_133 -> V_5 ;
T_6 V_144 = F_5 ( V_143 -> V_145 ) ;
while ( V_144 ) {
V_141 = (struct V_138 * ) ( V_133 -> V_5 + V_144 ) ;
if ( V_141 -> V_146 == V_139 )
return V_141 ;
V_144 = F_5 ( V_141 -> V_147 ) ;
}
F_40 ( V_133 , V_4 -> V_32 , 0 , V_4 -> V_26 ) ;
if ( ( V_4 -> V_26 - V_133 -> V_89 - V_140 ) < V_148 )
return NULL ;
if ( V_141 )
V_141 -> V_147 = F_11 ( V_133 -> V_89 ) ;
else
V_143 -> V_145 = F_11 ( V_133 -> V_89 ) ;
V_141 = (struct V_138 * ) memset ( F_43 ( V_133 , V_148 ) , 0 , V_148 ) ;
V_141 -> V_146 = V_139 ;
V_141 -> V_149 = F_11 ( sizeof( struct V_138 ) + sizeof( struct V_150 ) ) ;
return V_141 ;
}
struct V_132 *
F_45 ( struct V_1 * V_2 , struct V_132 * V_133 , T_5 V_139 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
struct V_142 * V_143 ;
struct V_138 * V_141 ;
struct V_132 * V_151 ;
T_3 V_152 = 0 , V_153 , V_154 ;
T_2 V_155 = 0 ;
if ( V_133 != NULL ) {
F_46 ( V_133 , V_4 -> V_81 ) ;
F_46 ( V_139 , V_4 -> V_156 ) ;
} else {
V_155 = 1 ;
}
V_151 = V_4 -> V_82 ;
if ( ! V_151 ) {
V_151 = F_47 ( V_4 -> V_26 , V_157 ) ;
if ( V_151 == NULL ) {
if ( V_133 != NULL ) {
F_17 ( V_133 ) ;
V_2 -> V_65 -> V_158 . V_159 ++ ;
}
goto V_160;
}
V_143 = (struct V_142 * ) memset ( F_43 ( V_151 , sizeof( struct V_142 ) ) , 0 , sizeof( struct V_142 ) ) ;
V_143 -> V_146 = F_8 ( V_161 ) ;
V_143 -> V_162 = F_11 ( sizeof( struct V_142 ) ) ;
V_143 -> V_163 = F_11 ( V_4 -> V_164 ++ ) ;
V_4 -> V_165 = 0 ;
}
for ( V_152 = V_4 -> V_165 ; V_152 < V_4 -> V_34 ; V_152 ++ ) {
if ( V_133 == NULL ) {
V_133 = V_4 -> V_81 ;
V_139 = V_4 -> V_156 ;
V_4 -> V_81 = NULL ;
if ( V_133 == NULL )
break;
}
V_141 = F_44 ( V_4 , V_151 , V_139 , V_133 -> V_89 + V_4 -> V_30 + V_4 -> V_28 ) ;
F_40 ( V_151 , V_4 -> V_30 , V_4 -> V_28 , V_4 -> V_26 ) ;
if ( ! V_141 || V_151 -> V_89 + V_133 -> V_89 > V_4 -> V_26 ) {
if ( V_152 == 0 ) {
F_17 ( V_133 ) ;
V_133 = NULL ;
V_2 -> V_65 -> V_158 . V_159 ++ ;
} else {
if ( V_4 -> V_81 != NULL ) {
F_17 ( V_4 -> V_81 ) ;
V_2 -> V_65 -> V_158 . V_159 ++ ;
}
V_4 -> V_81 = V_133 ;
V_4 -> V_156 = V_139 ;
V_133 = NULL ;
V_155 = 1 ;
}
break;
}
V_154 = F_5 ( V_141 -> V_149 ) ;
V_153 = ( V_154 - sizeof( struct V_138 ) ) / sizeof( struct V_150 ) - 1 ;
V_141 -> V_166 [ V_153 ] . V_167 = F_11 ( V_133 -> V_89 ) ;
V_141 -> V_166 [ V_153 ] . V_168 = F_11 ( V_151 -> V_89 ) ;
V_141 -> V_149 = F_11 ( V_154 + sizeof( struct V_150 ) ) ;
memcpy ( F_43 ( V_151 , V_133 -> V_89 ) , V_133 -> V_5 , V_133 -> V_89 ) ;
F_17 ( V_133 ) ;
V_133 = NULL ;
if ( V_153 >= V_47 ) {
V_155 = 1 ;
break;
}
}
if ( V_133 != NULL ) {
F_17 ( V_133 ) ;
V_133 = NULL ;
V_2 -> V_65 -> V_158 . V_159 ++ ;
}
V_4 -> V_165 = V_152 ;
if ( V_152 == 0 ) {
V_4 -> V_82 = V_151 ;
goto V_160;
} else if ( ( V_152 < V_4 -> V_34 ) && ( V_155 == 0 ) ) {
V_4 -> V_82 = V_151 ;
if ( V_152 < V_169 )
V_4 -> V_170 = V_171 ;
goto V_160;
} else {
}
if ( ! ( V_2 -> V_172 -> V_9 & V_173 ) &&
V_151 -> V_89 > V_174 )
memset ( F_43 ( V_151 , V_4 -> V_26 - V_151 -> V_89 ) , 0 ,
V_4 -> V_26 - V_151 -> V_89 ) ;
else if ( ( V_151 -> V_89 % V_2 -> V_175 ) == 0 )
* F_43 ( V_151 , 1 ) = 0 ;
V_143 = (struct V_142 * ) V_151 -> V_5 ;
V_143 -> V_176 = F_11 ( V_151 -> V_89 ) ;
V_4 -> V_82 = NULL ;
V_2 -> V_65 -> V_158 . V_177 += V_4 -> V_165 ;
return V_151 ;
V_160:
if ( V_4 -> V_82 != NULL )
F_48 ( V_4 ) ;
return NULL ;
}
static void F_48 ( struct V_3 * V_4 )
{
if ( ! ( F_33 ( & V_4 -> V_93 ) || F_49 ( & V_4 -> V_101 ) ) )
F_50 ( & V_4 -> V_93 ,
F_51 ( 0 , V_178 ) ,
V_95 ) ;
}
static enum V_179 V_97 ( struct V_180 * V_181 )
{
struct V_3 * V_4 =
F_52 ( V_181 , struct V_3 , V_93 ) ;
if ( ! F_49 ( & V_4 -> V_101 ) )
F_53 ( & V_4 -> V_98 ) ;
return V_182 ;
}
static void V_100 ( unsigned long V_183 )
{
struct V_1 * V_2 = (struct V_1 * ) V_183 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
F_54 ( & V_4 -> V_102 ) ;
if ( V_4 -> V_170 != 0 ) {
V_4 -> V_170 -- ;
F_48 ( V_4 ) ;
F_55 ( & V_4 -> V_102 ) ;
} else if ( V_2 -> V_65 != NULL ) {
F_55 ( & V_4 -> V_102 ) ;
F_56 ( V_2 -> V_65 ) ;
F_57 ( NULL , V_2 -> V_65 ) ;
F_58 ( V_2 -> V_65 ) ;
} else {
F_55 ( & V_4 -> V_102 ) ;
}
}
struct V_132 *
F_59 ( struct V_1 * V_2 , struct V_132 * V_133 , T_7 V_9 )
{
struct V_132 * V_151 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_4 == NULL )
goto error;
F_54 ( & V_4 -> V_102 ) ;
V_151 = F_45 ( V_2 , V_133 , F_8 ( V_184 ) ) ;
F_55 ( & V_4 -> V_102 ) ;
return V_151 ;
error:
if ( V_133 != NULL )
F_17 ( V_133 ) ;
return NULL ;
}
int F_60 ( struct V_3 * V_4 , struct V_132 * V_185 )
{
struct V_1 * V_2 = F_61 ( V_185 -> V_2 ) ;
struct V_142 * V_143 ;
int V_89 ;
int V_131 = - V_38 ;
if ( V_4 == NULL )
goto error;
if ( V_185 -> V_89 < ( sizeof( struct V_142 ) +
sizeof( struct V_138 ) ) ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 , L_24 ) ;
goto error;
}
V_143 = (struct V_142 * ) V_185 -> V_5 ;
if ( V_143 -> V_146 != F_8 ( V_161 ) ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 ,
L_25 ,
F_4 ( V_143 -> V_146 ) ) ;
goto error;
}
V_89 = F_5 ( V_143 -> V_176 ) ;
if ( V_89 > V_4 -> V_24 ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 ,
L_26 , V_89 ,
V_4 -> V_24 ) ;
goto error;
}
if ( ( V_4 -> V_187 + 1 ) != F_5 ( V_143 -> V_163 ) &&
( V_4 -> V_187 || F_5 ( V_143 -> V_163 ) ) &&
! ( ( V_4 -> V_187 == 0xffff ) && ! F_5 ( V_143 -> V_163 ) ) ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 ,
L_27 ,
V_4 -> V_187 , F_5 ( V_143 -> V_163 ) ) ;
}
V_4 -> V_187 = F_5 ( V_143 -> V_163 ) ;
V_131 = F_5 ( V_143 -> V_145 ) ;
error:
return V_131 ;
}
int F_63 ( struct V_132 * V_185 , int V_144 )
{
struct V_1 * V_2 = F_61 ( V_185 -> V_2 ) ;
struct V_138 * V_141 ;
int V_131 = - V_38 ;
if ( ( V_144 + sizeof( struct V_138 ) ) > V_185 -> V_89 ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 , L_28 ,
V_144 ) ;
goto error;
}
V_141 = (struct V_138 * ) ( V_185 -> V_5 + V_144 ) ;
if ( F_5 ( V_141 -> V_149 ) < V_188 ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 , L_29 ,
F_5 ( V_141 -> V_149 ) ) ;
goto error;
}
V_131 = ( ( F_5 ( V_141 -> V_149 ) -
sizeof( struct V_138 ) ) /
sizeof( struct V_150 ) ) ;
V_131 -- ;
if ( ( sizeof( struct V_138 ) +
V_131 * ( sizeof( struct V_150 ) ) ) > V_185 -> V_89 ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 , L_30 , V_131 ) ;
V_131 = - V_38 ;
}
error:
return V_131 ;
}
int F_64 ( struct V_1 * V_2 , struct V_132 * V_185 )
{
struct V_132 * V_133 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
int V_89 ;
int V_189 ;
int V_190 ;
int V_191 ;
struct V_138 * V_141 ;
struct V_150 * V_166 ;
int V_144 ;
int V_192 = 50 ;
V_144 = F_60 ( V_4 , V_185 ) ;
if ( V_144 < 0 )
goto error;
V_193:
V_189 = F_63 ( V_185 , V_144 ) ;
if ( V_189 < 0 )
goto error;
V_141 = (struct V_138 * ) ( V_185 -> V_5 + V_144 ) ;
if ( V_141 -> V_146 != F_8 ( V_184 ) ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 ,
L_31 ,
F_4 ( V_141 -> V_146 ) ) ;
goto V_194;
}
V_166 = V_141 -> V_166 ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ , V_166 ++ ) {
V_191 = F_5 ( V_166 -> V_168 ) ;
V_89 = F_5 ( V_166 -> V_167 ) ;
if ( ( V_191 == 0 ) || ( V_89 == 0 ) ) {
if ( ! V_190 )
goto V_194;
break;
}
if ( ( ( V_191 + V_89 ) > V_185 -> V_89 ) ||
( V_89 > V_4 -> V_24 ) || ( V_89 < V_43 ) ) {
F_62 ( V_2 , V_186 , V_2 -> V_65 ,
L_32 ,
V_190 , V_191 , V_89 , V_185 ) ;
if ( ! V_190 )
goto V_194;
break;
} else {
V_133 = F_65 ( V_185 , V_157 ) ;
if ( ! V_133 )
goto error;
V_133 -> V_89 = V_89 ;
V_133 -> V_5 = ( ( T_2 * ) V_185 -> V_5 ) + V_191 ;
F_66 ( V_133 , V_89 ) ;
F_67 ( V_2 , V_133 ) ;
}
}
V_194:
V_144 = F_5 ( V_141 -> V_147 ) ;
if ( V_144 && V_192 -- )
goto V_193;
return 1 ;
error:
return 0 ;
}
static void
F_68 ( struct V_1 * V_2 ,
struct V_195 * V_5 )
{
T_8 V_196 = F_4 ( V_5 -> V_197 ) ;
T_8 V_198 = F_4 ( V_5 -> V_199 ) ;
if ( ( V_198 > 1000000 ) && ( V_196 > 1000000 ) ) {
F_69 ( V_2 , V_200 , V_2 -> V_65 ,
L_33 ,
( unsigned int ) ( V_196 / 1000000U ) ,
( unsigned int ) ( V_198 / 1000000U ) ) ;
} else {
F_69 ( V_2 , V_200 , V_2 -> V_65 ,
L_34 ,
( unsigned int ) ( V_196 / 1000U ) ,
( unsigned int ) ( V_198 / 1000U ) ) ;
}
}
static void F_70 ( struct V_1 * V_2 , struct V_201 * V_201 )
{
struct V_3 * V_4 ;
struct V_202 * V_203 ;
V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_201 -> V_204 < sizeof( * V_203 ) )
return;
if ( F_71 ( V_205 , & V_2 -> V_9 ) ) {
F_68 ( V_2 ,
(struct V_195 * ) V_201 -> V_206 ) ;
return;
}
V_203 = V_201 -> V_206 ;
switch ( V_203 -> V_207 ) {
case V_208 :
V_4 -> V_209 = F_5 ( V_203 -> V_210 ) ;
F_69 ( V_2 , V_200 , V_2 -> V_65 ,
L_35 ,
V_4 -> V_209 ? L_36 : L_37 ) ;
F_39 ( V_2 , V_4 -> V_209 , 0 ) ;
break;
case V_211 :
if ( V_201 -> V_204 < ( sizeof( * V_203 ) +
sizeof( struct V_195 ) ) )
F_72 ( V_205 , & V_2 -> V_9 ) ;
else
F_68 ( V_2 ,
(struct V_195 * ) & V_203 [ 1 ] ) ;
break;
default:
F_7 ( & V_2 -> V_53 -> V_2 ,
L_38 ,
V_203 -> V_207 ) ;
break;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_4 == NULL )
return 1 ;
return ! V_4 -> V_209 ;
}
