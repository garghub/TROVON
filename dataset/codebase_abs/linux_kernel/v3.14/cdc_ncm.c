static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
T_1 V_6 ;
T_2 V_7 ;
T_2 V_8 ;
int V_9 ;
int V_10 ;
T_3 V_11 ;
T_4 V_12 ;
V_8 = V_4 -> V_13 -> V_14 -> V_15 . V_16 ;
V_9 = F_2 ( V_2 , V_17 ,
V_18 | V_19
| V_20 ,
0 , V_8 , & V_4 -> V_21 ,
sizeof( V_4 -> V_21 ) ) ;
if ( V_9 < 0 ) {
F_3 ( & V_2 -> V_22 -> V_2 , L_1 ) ;
return V_9 ;
}
V_4 -> V_23 = F_4 ( V_4 -> V_21 . V_24 ) ;
V_4 -> V_25 = F_4 ( V_4 -> V_21 . V_26 ) ;
V_4 -> V_27 = F_5 ( V_4 -> V_21 . V_28 ) ;
V_4 -> V_29 = F_5 ( V_4 -> V_21 . V_30 ) ;
V_4 -> V_31 = F_5 ( V_4 -> V_21 . V_32 ) ;
V_4 -> V_33 = F_5 ( V_4 -> V_21 . V_34 ) ;
V_11 = F_5 ( V_4 -> V_21 . V_35 ) ;
if ( F_6 ( V_4 -> V_13 -> V_14 ) ) {
if ( ! V_4 -> V_36 )
return - V_37 ;
V_10 = 0 ;
V_7 = V_4 -> V_36 -> V_38 ;
V_4 -> V_12 = F_5 ( V_4 -> V_36 -> V_39 ) ;
if ( V_4 -> V_12 < V_40 )
V_4 -> V_12 = V_40 ;
} else {
if ( ! V_4 -> V_41 )
return - V_37 ;
V_10 = V_42 ;
V_7 = V_4 -> V_41 -> V_38 ;
V_4 -> V_12 = F_5 ( V_4 -> V_43 -> V_39 ) ;
if ( V_4 -> V_12 < V_44 )
V_4 -> V_12 = V_44 ;
}
if ( V_4 -> V_12 > V_45 )
V_4 -> V_12 = V_45 ;
F_7 ( & V_2 -> V_22 -> V_2 ,
L_2 ,
V_4 -> V_23 , V_4 -> V_25 , V_4 -> V_27 , V_4 -> V_29 ,
V_4 -> V_31 , V_4 -> V_33 , V_7 ) ;
if ( ( V_4 -> V_33 == 0 ) ||
( V_4 -> V_33 > V_46 ) )
V_4 -> V_33 = V_46 ;
if ( V_4 -> V_23 < V_47 ) {
F_7 ( & V_2 -> V_22 -> V_2 , L_3 ,
V_47 ) ;
V_4 -> V_23 = V_47 ;
}
if ( V_4 -> V_23 > V_48 ) {
F_7 ( & V_2 -> V_22 -> V_2 , L_4 ,
V_48 ) ;
V_4 -> V_23 = V_48 ;
}
if ( V_4 -> V_23 != F_4 ( V_4 -> V_21 . V_24 ) ) {
T_5 V_24 = F_8 ( V_4 -> V_23 ) ;
V_9 = F_9 ( V_2 , V_49 ,
V_18 | V_50
| V_20 ,
0 , V_8 , & V_24 , 4 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_22 -> V_2 , L_5 ) ;
}
if ( V_4 -> V_25 > V_51 ) {
F_7 ( & V_2 -> V_22 -> V_2 , L_6 ,
V_51 ) ;
V_4 -> V_25 = V_51 ;
}
V_6 = V_4 -> V_31 ;
if ( ( V_6 < V_52 ) ||
( V_6 != ( ( - V_6 ) & V_6 ) ) || ( V_6 >= V_4 -> V_25 ) ) {
F_7 ( & V_2 -> V_22 -> V_2 , L_7 ) ;
V_4 -> V_31 = V_52 ;
}
V_6 = V_4 -> V_29 ;
if ( ( V_6 < V_52 ) ||
( V_6 != ( ( - V_6 ) & V_6 ) ) || ( V_6 >= V_4 -> V_25 ) ) {
F_7 ( & V_2 -> V_22 -> V_2 , L_8 ) ;
V_4 -> V_29 = V_52 ;
}
if ( V_4 -> V_27 >= V_4 -> V_29 ) {
F_7 ( & V_2 -> V_22 -> V_2 , L_9 ) ;
V_4 -> V_27 = 0 ;
}
V_4 -> V_27 = ( ( V_4 -> V_27 - V_10 ) &
( V_4 -> V_29 - 1 ) ) ;
if ( V_7 & V_53 ) {
V_9 = F_9 ( V_2 , V_54 ,
V_18 | V_50
| V_20 ,
V_55 ,
V_8 , NULL , 0 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_22 -> V_2 , L_10 ) ;
}
if ( V_11 & V_56 ) {
V_9 = F_9 ( V_2 , V_57 ,
V_18 | V_50
| V_20 ,
V_58 ,
V_8 , NULL , 0 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_22 -> V_2 , L_11 ) ;
}
if ( ! ( V_7 & V_59 ) )
goto V_60;
V_9 = F_2 ( V_2 , V_61 ,
V_18 | V_19 | V_20 ,
0 , V_8 , & V_12 , 2 ) ;
if ( V_9 < 0 ) {
F_7 ( & V_2 -> V_22 -> V_2 , L_12 ) ;
goto V_60;
}
if ( F_5 ( V_12 ) == V_4 -> V_12 )
goto V_60;
V_12 = F_10 ( V_4 -> V_12 ) ;
V_9 = F_9 ( V_2 , V_62 ,
V_18 | V_50 | V_20 ,
0 , V_8 , & V_12 , 2 ) ;
if ( V_9 < 0 )
F_7 ( & V_2 -> V_22 -> V_2 , L_13 ) ;
V_60:
if ( V_2 -> V_63 -> V_64 > V_4 -> V_12 - V_10 )
V_2 -> V_63 -> V_64 = V_4 -> V_12 - V_10 ;
return 0 ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_65 * V_22 )
{
struct V_66 * V_67 , * V_68 = NULL , * V_60 = NULL ;
T_2 V_69 ;
for ( V_69 = 0 ; V_69 < V_22 -> V_14 -> V_15 . V_70 ; V_69 ++ ) {
V_67 = V_22 -> V_14 -> V_71 + V_69 ;
switch ( V_67 -> V_15 . V_72 & V_73 ) {
case V_74 :
if ( F_12 ( & V_67 -> V_15 ) ) {
if ( ! V_2 -> V_75 )
V_2 -> V_75 = V_67 ;
}
break;
case V_76 :
if ( F_12 ( & V_67 -> V_15 ) ) {
if ( ! V_68 )
V_68 = V_67 ;
} else {
if ( ! V_60 )
V_60 = V_67 ;
}
break;
default:
break;
}
}
if ( V_68 && ! V_2 -> V_68 )
V_2 -> V_68 = F_13 ( V_2 -> V_77 ,
V_68 -> V_15 . V_78 &
V_79 ) ;
if ( V_60 && ! V_2 -> V_60 )
V_2 -> V_60 = F_14 ( V_2 -> V_77 ,
V_60 -> V_15 . V_78 &
V_79 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
if ( V_4 == NULL )
return;
if ( V_4 -> V_80 != NULL ) {
F_16 ( V_4 -> V_80 ) ;
V_4 -> V_80 = NULL ;
}
if ( V_4 -> V_81 != NULL ) {
F_16 ( V_4 -> V_81 ) ;
V_4 -> V_81 = NULL ;
}
F_17 ( V_4 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_65 * V_22 , T_2 V_82 )
{
const struct V_83 * V_84 = NULL ;
struct V_3 * V_4 ;
struct V_85 * V_86 ;
T_2 * V_87 ;
int V_88 ;
int V_89 ;
T_2 V_8 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_90 ) ;
if ( ! V_4 )
return - V_91 ;
F_20 ( & V_4 -> V_92 , V_93 , V_94 ) ;
V_4 -> V_92 . V_95 = & V_96 ;
V_4 -> V_97 . V_5 = ( unsigned long ) V_2 ;
V_4 -> V_97 . V_98 = V_99 ;
F_21 ( & V_4 -> V_100 , 0 ) ;
F_22 ( & V_4 -> V_101 ) ;
V_2 -> V_5 [ 0 ] = ( unsigned long ) V_4 ;
V_4 -> V_13 = V_22 ;
V_86 = F_23 ( V_22 ) ;
V_87 = V_22 -> V_14 -> V_102 ;
V_88 = V_22 -> V_14 -> V_103 ;
while ( ( V_88 > 0 ) && ( V_87 [ 0 ] > 2 ) && ( V_87 [ 0 ] <= V_88 ) ) {
if ( V_87 [ 1 ] != V_104 )
goto V_105;
switch ( V_87 [ 2 ] ) {
case V_106 :
if ( V_87 [ 0 ] < sizeof( * V_84 ) )
break;
V_84 = ( const struct V_83 * ) V_87 ;
if ( V_22 -> V_14 -> V_15 . V_16 !=
V_84 -> V_107 ) {
F_7 ( & V_22 -> V_2 , L_14 ) ;
goto error;
}
V_4 -> V_5 = F_24 ( V_2 -> V_77 ,
V_84 -> V_108 ) ;
break;
case V_109 :
if ( V_87 [ 0 ] < sizeof( * ( V_4 -> V_43 ) ) )
break;
V_4 -> V_43 =
( const struct V_110 * ) V_87 ;
break;
case V_111 :
if ( V_87 [ 0 ] < sizeof( * ( V_4 -> V_41 ) ) )
break;
V_4 -> V_41 = ( const struct V_112 * ) V_87 ;
break;
case V_113 :
if ( V_87 [ 0 ] < sizeof( * ( V_4 -> V_36 ) ) )
break;
V_4 -> V_36 = ( const struct V_114 * ) V_87 ;
break;
default:
break;
}
V_105:
V_89 = V_87 [ 0 ] ;
V_87 += V_89 ;
V_88 -= V_89 ;
}
if ( ! V_84 && V_22 -> V_115 && V_22 -> V_115 -> V_116 == 2 ) {
V_4 -> V_5 = F_24 ( V_2 -> V_77 , V_22 -> V_14 -> V_15 . V_16 + 1 ) ;
F_7 ( & V_22 -> V_2 , L_15 ) ;
}
if ( ! V_4 -> V_5 || ( ! V_4 -> V_36 && ! V_4 -> V_43 ) ) {
F_7 ( & V_22 -> V_2 , L_16 ) ;
goto error;
}
if ( V_4 -> V_5 != V_4 -> V_13 ) {
V_89 = F_25 ( V_86 , V_4 -> V_5 , V_2 ) ;
if ( V_89 ) {
F_7 ( & V_22 -> V_2 , L_17 ) ;
goto error;
}
}
V_8 = V_4 -> V_5 -> V_14 -> V_15 . V_16 ;
V_89 = F_26 ( V_2 -> V_77 , V_8 , 0 ) ;
if ( V_89 ) {
F_7 ( & V_22 -> V_2 , L_18 ) ;
goto V_117;
}
if ( F_1 ( V_2 ) )
goto V_117;
V_89 = F_26 ( V_2 -> V_77 , V_8 , V_82 ) ;
if ( V_89 ) {
F_7 ( & V_22 -> V_2 , L_18 ) ;
goto V_117;
}
F_11 ( V_2 , V_4 -> V_5 ) ;
F_11 ( V_2 , V_4 -> V_13 ) ;
if ( ! V_2 -> V_68 || ! V_2 -> V_60 || ! V_2 -> V_75 ) {
F_7 ( & V_22 -> V_2 , L_19 ) ;
goto V_117;
}
F_27 ( V_4 -> V_5 , V_2 ) ;
F_27 ( V_4 -> V_13 , V_2 ) ;
if ( V_4 -> V_43 ) {
V_89 = F_28 ( V_2 , V_4 -> V_43 -> V_118 ) ;
if ( V_89 ) {
F_7 ( & V_22 -> V_2 , L_20 ) ;
goto V_117;
}
F_29 ( & V_22 -> V_2 , L_21 , V_2 -> V_63 -> V_119 ) ;
}
V_2 -> V_120 = V_4 -> V_25 ;
V_2 -> V_121 = V_4 -> V_23 ;
if ( V_4 -> V_25 != F_4 ( V_4 -> V_21 . V_26 ) &&
V_4 -> V_25 % F_30 ( V_2 -> V_77 , V_2 -> V_60 , 1 ) == 0 )
V_4 -> V_25 ++ ;
return 0 ;
V_117:
F_27 ( V_4 -> V_13 , NULL ) ;
F_27 ( V_4 -> V_5 , NULL ) ;
if ( V_4 -> V_5 != V_4 -> V_13 )
F_31 ( V_86 , V_4 -> V_5 ) ;
error:
F_15 ( (struct V_3 * ) V_2 -> V_5 [ 0 ] ) ;
V_2 -> V_5 [ 0 ] = 0 ;
F_29 ( & V_22 -> V_2 , L_22 ) ;
return - V_122 ;
}
void F_32 ( struct V_1 * V_2 , struct V_65 * V_22 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
struct V_85 * V_86 = F_23 ( V_22 ) ;
if ( V_4 == NULL )
return;
F_21 ( & V_4 -> V_100 , 1 ) ;
if ( F_33 ( & V_4 -> V_92 ) )
F_34 ( & V_4 -> V_92 ) ;
F_35 ( & V_4 -> V_97 ) ;
if ( V_4 -> V_13 == V_4 -> V_5 )
V_4 -> V_5 = NULL ;
if ( V_22 == V_4 -> V_13 && V_4 -> V_5 ) {
F_27 ( V_4 -> V_5 , NULL ) ;
F_31 ( V_86 , V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
} else if ( V_22 == V_4 -> V_5 && V_4 -> V_13 ) {
F_27 ( V_4 -> V_13 , NULL ) ;
F_31 ( V_86 , V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
}
F_27 ( V_22 , NULL ) ;
F_15 ( V_4 ) ;
}
T_2 F_36 ( struct V_1 * V_2 , struct V_65 * V_22 )
{
struct V_123 * V_124 ;
if ( V_125 && V_22 -> V_126 == 2 ) {
V_124 = F_37 ( V_22 , V_127 ) ;
if ( V_124 && F_6 ( V_124 ) &&
! F_26 ( V_2 -> V_77 ,
V_22 -> V_14 -> V_15 . V_16 ,
V_127 ) )
return V_128 ;
}
return V_129 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_65 * V_22 )
{
int V_130 ;
F_36 ( V_2 , V_22 ) ;
if ( F_6 ( V_22 -> V_14 ) )
return - V_122 ;
V_130 = F_18 ( V_2 , V_22 , 1 ) ;
F_39 ( V_2 , 0 , 0 ) ;
return V_130 ;
}
static void F_40 ( struct V_131 * V_132 , T_6 V_133 , T_6 V_134 , T_6 V_135 )
{
T_6 V_136 = F_41 ( V_132 -> V_88 , V_133 ) - V_132 -> V_88 + V_134 ;
if ( V_132 -> V_88 + V_136 > V_135 )
V_136 = V_135 - V_132 -> V_88 ;
if ( V_136 && F_42 ( V_132 ) >= V_136 )
memset ( F_43 ( V_132 , V_136 ) , 0 , V_136 ) ;
}
static struct V_137 * F_44 ( struct V_3 * V_4 , struct V_131 * V_132 , T_5 V_138 , T_6 V_139 )
{
struct V_137 * V_140 = NULL ;
struct V_141 * V_142 = ( void * ) V_132 -> V_5 ;
T_6 V_143 = F_5 ( V_142 -> V_144 ) ;
while ( V_143 ) {
V_140 = (struct V_137 * ) ( V_132 -> V_5 + V_143 ) ;
if ( V_140 -> V_145 == V_138 )
return V_140 ;
V_143 = F_5 ( V_140 -> V_146 ) ;
}
F_40 ( V_132 , V_4 -> V_31 , 0 , V_4 -> V_25 ) ;
if ( ( V_4 -> V_25 - V_132 -> V_88 - V_139 ) < V_147 )
return NULL ;
if ( V_140 )
V_140 -> V_146 = F_10 ( V_132 -> V_88 ) ;
else
V_142 -> V_144 = F_10 ( V_132 -> V_88 ) ;
V_140 = (struct V_137 * ) memset ( F_43 ( V_132 , V_147 ) , 0 , V_147 ) ;
V_140 -> V_145 = V_138 ;
V_140 -> V_148 = F_10 ( sizeof( struct V_137 ) + sizeof( struct V_149 ) ) ;
return V_140 ;
}
struct V_131 *
F_45 ( struct V_1 * V_2 , struct V_131 * V_132 , T_5 V_138 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
struct V_141 * V_142 ;
struct V_137 * V_140 ;
struct V_131 * V_150 ;
T_3 V_151 = 0 , V_152 , V_153 ;
T_2 V_154 = 0 ;
if ( V_132 != NULL ) {
F_46 ( V_132 , V_4 -> V_80 ) ;
F_46 ( V_138 , V_4 -> V_155 ) ;
} else {
V_154 = 1 ;
}
V_150 = V_4 -> V_81 ;
if ( ! V_150 ) {
V_150 = F_47 ( V_4 -> V_25 , V_156 ) ;
if ( V_150 == NULL ) {
if ( V_132 != NULL ) {
F_16 ( V_132 ) ;
V_2 -> V_63 -> V_157 . V_158 ++ ;
}
goto V_159;
}
V_142 = (struct V_141 * ) memset ( F_43 ( V_150 , sizeof( struct V_141 ) ) , 0 , sizeof( struct V_141 ) ) ;
V_142 -> V_145 = F_8 ( V_160 ) ;
V_142 -> V_161 = F_10 ( sizeof( struct V_141 ) ) ;
V_142 -> V_162 = F_10 ( V_4 -> V_163 ++ ) ;
V_4 -> V_164 = 0 ;
}
for ( V_151 = V_4 -> V_164 ; V_151 < V_4 -> V_33 ; V_151 ++ ) {
if ( V_132 == NULL ) {
V_132 = V_4 -> V_80 ;
V_138 = V_4 -> V_155 ;
V_4 -> V_80 = NULL ;
if ( V_132 == NULL )
break;
}
V_140 = F_44 ( V_4 , V_150 , V_138 , V_132 -> V_88 + V_4 -> V_29 + V_4 -> V_27 ) ;
F_40 ( V_150 , V_4 -> V_29 , V_4 -> V_27 , V_4 -> V_25 ) ;
if ( ! V_140 || V_150 -> V_88 + V_132 -> V_88 > V_4 -> V_25 ) {
if ( V_151 == 0 ) {
F_16 ( V_132 ) ;
V_132 = NULL ;
V_2 -> V_63 -> V_157 . V_158 ++ ;
} else {
if ( V_4 -> V_80 != NULL ) {
F_16 ( V_4 -> V_80 ) ;
V_2 -> V_63 -> V_157 . V_158 ++ ;
}
V_4 -> V_80 = V_132 ;
V_4 -> V_155 = V_138 ;
V_132 = NULL ;
V_154 = 1 ;
}
break;
}
V_153 = F_5 ( V_140 -> V_148 ) ;
V_152 = ( V_153 - sizeof( struct V_137 ) ) / sizeof( struct V_149 ) - 1 ;
V_140 -> V_165 [ V_152 ] . V_166 = F_10 ( V_132 -> V_88 ) ;
V_140 -> V_165 [ V_152 ] . V_167 = F_10 ( V_150 -> V_88 ) ;
V_140 -> V_148 = F_10 ( V_153 + sizeof( struct V_149 ) ) ;
memcpy ( F_43 ( V_150 , V_132 -> V_88 ) , V_132 -> V_5 , V_132 -> V_88 ) ;
F_16 ( V_132 ) ;
V_132 = NULL ;
if ( V_152 >= V_46 ) {
V_154 = 1 ;
break;
}
}
if ( V_132 != NULL ) {
F_16 ( V_132 ) ;
V_132 = NULL ;
V_2 -> V_63 -> V_157 . V_158 ++ ;
}
V_4 -> V_164 = V_151 ;
if ( V_151 == 0 ) {
V_4 -> V_81 = V_150 ;
goto V_159;
} else if ( ( V_151 < V_4 -> V_33 ) && ( V_154 == 0 ) ) {
V_4 -> V_81 = V_150 ;
if ( V_151 < V_168 )
V_4 -> V_169 = V_170 ;
goto V_159;
} else {
}
if ( ! ( V_2 -> V_171 -> V_7 & V_172 ) &&
V_150 -> V_88 > V_173 )
memset ( F_43 ( V_150 , V_4 -> V_25 - V_150 -> V_88 ) , 0 ,
V_4 -> V_25 - V_150 -> V_88 ) ;
else if ( ( V_150 -> V_88 % V_2 -> V_174 ) == 0 )
* F_43 ( V_150 , 1 ) = 0 ;
V_142 = (struct V_141 * ) V_150 -> V_5 ;
V_142 -> V_175 = F_10 ( V_150 -> V_88 ) ;
V_4 -> V_81 = NULL ;
V_2 -> V_63 -> V_157 . V_176 += V_4 -> V_164 ;
return V_150 ;
V_159:
if ( V_4 -> V_81 != NULL )
F_48 ( V_4 ) ;
return NULL ;
}
static void F_48 ( struct V_3 * V_4 )
{
if ( ! ( F_33 ( & V_4 -> V_92 ) || F_49 ( & V_4 -> V_100 ) ) )
F_50 ( & V_4 -> V_92 ,
F_51 ( 0 , V_177 ) ,
V_94 ) ;
}
static enum V_178 V_96 ( struct V_179 * V_180 )
{
struct V_3 * V_4 =
F_52 ( V_180 , struct V_3 , V_92 ) ;
if ( ! F_49 ( & V_4 -> V_100 ) )
F_53 ( & V_4 -> V_97 ) ;
return V_181 ;
}
static void V_99 ( unsigned long V_182 )
{
struct V_1 * V_2 = (struct V_1 * ) V_182 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
F_54 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_169 != 0 ) {
V_4 -> V_169 -- ;
F_48 ( V_4 ) ;
F_55 ( & V_4 -> V_101 ) ;
} else if ( V_2 -> V_63 != NULL ) {
F_55 ( & V_4 -> V_101 ) ;
F_56 ( V_2 -> V_63 ) ;
F_57 ( NULL , V_2 -> V_63 ) ;
F_58 ( V_2 -> V_63 ) ;
} else {
F_55 ( & V_4 -> V_101 ) ;
}
}
struct V_131 *
F_59 ( struct V_1 * V_2 , struct V_131 * V_132 , T_7 V_7 )
{
struct V_131 * V_150 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_4 == NULL )
goto error;
F_54 ( & V_4 -> V_101 ) ;
V_150 = F_45 ( V_2 , V_132 , F_8 ( V_183 ) ) ;
F_55 ( & V_4 -> V_101 ) ;
return V_150 ;
error:
if ( V_132 != NULL )
F_16 ( V_132 ) ;
return NULL ;
}
int F_60 ( struct V_3 * V_4 , struct V_131 * V_184 )
{
struct V_1 * V_2 = F_61 ( V_184 -> V_2 ) ;
struct V_141 * V_142 ;
int V_88 ;
int V_130 = - V_37 ;
if ( V_4 == NULL )
goto error;
if ( V_184 -> V_88 < ( sizeof( struct V_141 ) +
sizeof( struct V_137 ) ) ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 , L_23 ) ;
goto error;
}
V_142 = (struct V_141 * ) V_184 -> V_5 ;
if ( V_142 -> V_145 != F_8 ( V_160 ) ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 ,
L_24 ,
F_4 ( V_142 -> V_145 ) ) ;
goto error;
}
V_88 = F_5 ( V_142 -> V_175 ) ;
if ( V_88 > V_4 -> V_23 ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 ,
L_25 , V_88 ,
V_4 -> V_23 ) ;
goto error;
}
if ( ( V_4 -> V_186 + 1 ) != F_5 ( V_142 -> V_162 ) &&
( V_4 -> V_186 || F_5 ( V_142 -> V_162 ) ) &&
! ( ( V_4 -> V_186 == 0xffff ) && ! F_5 ( V_142 -> V_162 ) ) ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 ,
L_26 ,
V_4 -> V_186 , F_5 ( V_142 -> V_162 ) ) ;
}
V_4 -> V_186 = F_5 ( V_142 -> V_162 ) ;
V_130 = F_5 ( V_142 -> V_144 ) ;
error:
return V_130 ;
}
int F_63 ( struct V_131 * V_184 , int V_143 )
{
struct V_1 * V_2 = F_61 ( V_184 -> V_2 ) ;
struct V_137 * V_140 ;
int V_130 = - V_37 ;
if ( ( V_143 + sizeof( struct V_137 ) ) > V_184 -> V_88 ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 , L_27 ,
V_143 ) ;
goto error;
}
V_140 = (struct V_137 * ) ( V_184 -> V_5 + V_143 ) ;
if ( F_5 ( V_140 -> V_148 ) < V_187 ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 , L_28 ,
F_5 ( V_140 -> V_148 ) ) ;
goto error;
}
V_130 = ( ( F_5 ( V_140 -> V_148 ) -
sizeof( struct V_137 ) ) /
sizeof( struct V_149 ) ) ;
V_130 -- ;
if ( ( sizeof( struct V_137 ) +
V_130 * ( sizeof( struct V_149 ) ) ) > V_184 -> V_88 ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 , L_29 , V_130 ) ;
V_130 = - V_37 ;
}
error:
return V_130 ;
}
int F_64 ( struct V_1 * V_2 , struct V_131 * V_184 )
{
struct V_131 * V_132 ;
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
int V_88 ;
int V_188 ;
int V_189 ;
int V_190 ;
struct V_137 * V_140 ;
struct V_149 * V_165 ;
int V_143 ;
int V_191 = 50 ;
V_143 = F_60 ( V_4 , V_184 ) ;
if ( V_143 < 0 )
goto error;
V_192:
V_188 = F_63 ( V_184 , V_143 ) ;
if ( V_188 < 0 )
goto error;
V_140 = (struct V_137 * ) ( V_184 -> V_5 + V_143 ) ;
if ( V_140 -> V_145 != F_8 ( V_183 ) ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 ,
L_30 ,
F_4 ( V_140 -> V_145 ) ) ;
goto V_193;
}
V_165 = V_140 -> V_165 ;
for ( V_189 = 0 ; V_189 < V_188 ; V_189 ++ , V_165 ++ ) {
V_190 = F_5 ( V_165 -> V_167 ) ;
V_88 = F_5 ( V_165 -> V_166 ) ;
if ( ( V_190 == 0 ) || ( V_88 == 0 ) ) {
if ( ! V_189 )
goto V_193;
break;
}
if ( ( ( V_190 + V_88 ) > V_184 -> V_88 ) ||
( V_88 > V_4 -> V_23 ) || ( V_88 < V_42 ) ) {
F_62 ( V_2 , V_185 , V_2 -> V_63 ,
L_31 ,
V_189 , V_190 , V_88 , V_184 ) ;
if ( ! V_189 )
goto V_193;
break;
} else {
V_132 = F_65 ( V_184 , V_156 ) ;
if ( ! V_132 )
goto error;
V_132 -> V_88 = V_88 ;
V_132 -> V_5 = ( ( T_2 * ) V_184 -> V_5 ) + V_190 ;
F_66 ( V_132 , V_88 ) ;
F_67 ( V_2 , V_132 ) ;
}
}
V_193:
V_143 = F_5 ( V_140 -> V_146 ) ;
if ( V_143 && V_191 -- )
goto V_192;
return 1 ;
error:
return 0 ;
}
static void
F_68 ( struct V_1 * V_2 ,
struct V_194 * V_5 )
{
T_8 V_195 = F_4 ( V_5 -> V_196 ) ;
T_8 V_197 = F_4 ( V_5 -> V_198 ) ;
if ( ( V_197 > 1000000 ) && ( V_195 > 1000000 ) ) {
F_69 ( V_2 , V_199 , V_2 -> V_63 ,
L_32 ,
( unsigned int ) ( V_195 / 1000000U ) ,
( unsigned int ) ( V_197 / 1000000U ) ) ;
} else {
F_69 ( V_2 , V_199 , V_2 -> V_63 ,
L_33 ,
( unsigned int ) ( V_195 / 1000U ) ,
( unsigned int ) ( V_197 / 1000U ) ) ;
}
}
static void F_70 ( struct V_1 * V_2 , struct V_200 * V_200 )
{
struct V_3 * V_4 ;
struct V_201 * V_202 ;
V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_200 -> V_203 < sizeof( * V_202 ) )
return;
if ( F_71 ( V_204 , & V_2 -> V_7 ) ) {
F_68 ( V_2 ,
(struct V_194 * ) V_200 -> V_205 ) ;
return;
}
V_202 = V_200 -> V_205 ;
switch ( V_202 -> V_206 ) {
case V_207 :
V_4 -> V_208 = F_5 ( V_202 -> V_209 ) ;
F_69 ( V_2 , V_199 , V_2 -> V_63 ,
L_34 ,
V_4 -> V_208 ? L_35 : L_36 ) ;
F_39 ( V_2 , V_4 -> V_208 , 0 ) ;
break;
case V_210 :
if ( V_200 -> V_203 < ( sizeof( * V_202 ) +
sizeof( struct V_194 ) ) )
F_72 ( V_204 , & V_2 -> V_7 ) ;
else
F_68 ( V_2 ,
(struct V_194 * ) & V_202 [ 1 ] ) ;
break;
default:
F_7 ( & V_2 -> V_77 -> V_2 ,
L_37 ,
V_202 -> V_206 ) ;
break;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) V_2 -> V_5 [ 0 ] ;
if ( V_4 == NULL )
return 1 ;
return ! V_4 -> V_208 ;
}
