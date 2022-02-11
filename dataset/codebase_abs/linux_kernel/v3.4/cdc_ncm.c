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
T_3 V_22 ;
V_20 = V_17 -> V_23 -> V_24 -> V_25 . V_26 ;
V_21 = F_5 ( V_17 -> V_14 ,
F_6 ( V_17 -> V_14 , 0 ) ,
V_27 ,
V_28 | V_29
| V_30 ,
0 , V_20 , & V_17 -> V_31 ,
sizeof( V_17 -> V_31 ) , 10000 ) ;
if ( V_21 < 0 ) {
F_7 ( L_1 ) ;
return 1 ;
}
V_17 -> V_32 = F_8 ( V_17 -> V_31 . V_33 ) ;
V_17 -> V_34 = F_8 ( V_17 -> V_31 . V_35 ) ;
V_17 -> V_36 = F_9 ( V_17 -> V_31 . V_37 ) ;
V_17 -> V_38 = F_9 ( V_17 -> V_31 . V_39 ) ;
V_17 -> V_40 = F_9 ( V_17 -> V_31 . V_41 ) ;
V_17 -> V_42 = F_9 ( V_17 -> V_31 . V_43 ) ;
V_22 = F_9 ( V_17 -> V_31 . V_44 ) ;
if ( V_17 -> V_45 != NULL )
V_19 = V_17 -> V_45 -> V_46 ;
else
V_19 = 0 ;
F_7 ( L_2
L_3
L_4 ,
V_17 -> V_32 , V_17 -> V_34 , V_17 -> V_36 , V_17 -> V_38 ,
V_17 -> V_40 , V_17 -> V_42 , V_19 ) ;
if ( ( V_17 -> V_42 == 0 ) ||
( V_17 -> V_42 > V_47 ) )
V_17 -> V_42 = V_47 ;
if ( V_17 -> V_32 < V_48 ) {
F_7 ( L_5 ,
V_48 ) ;
V_17 -> V_32 = V_48 ;
}
if ( V_17 -> V_32 > V_49 ) {
F_7 ( L_6 ,
V_49 ) ;
V_17 -> V_32 = V_49 ;
}
if ( V_17 -> V_32 != F_8 ( V_17 -> V_31 . V_33 ) ) {
if ( V_19 & V_50 ) {
struct V_51 * V_52 ;
V_52 = F_10 ( sizeof( * V_52 ) , V_53 ) ;
if ( ! V_52 ) {
V_21 = - V_54 ;
goto V_55;
}
V_21 = F_5 ( V_17 -> V_14 ,
F_11 ( V_17 -> V_14 , 0 ) ,
V_56 ,
V_28 | V_57
| V_30 ,
0 , V_20 , V_52 , 8 , 1000 ) ;
F_12 ( V_52 ) ;
} else {
T_4 * V_33 ;
V_33 = F_10 ( sizeof( * V_33 ) ,
V_53 ) ;
if ( ! V_33 ) {
V_21 = - V_54 ;
goto V_55;
}
* V_33 = F_13 ( V_17 -> V_32 ) ;
V_21 = F_5 ( V_17 -> V_14 ,
F_11 ( V_17 -> V_14 , 0 ) ,
V_56 ,
V_28 | V_57
| V_30 ,
0 , V_20 , V_33 , 4 , 1000 ) ;
F_12 ( V_33 ) ;
}
V_55:
if ( V_21 < 0 )
F_7 ( L_7 ) ;
}
if ( ( V_17 -> V_34 <
( V_58 + V_59 ) ) ||
( V_17 -> V_34 > V_60 ) ) {
F_7 ( L_8 ,
V_60 ) ;
V_17 -> V_34 = V_60 ;
}
V_18 = V_17 -> V_40 ;
if ( ( V_18 < V_61 ) ||
( V_18 != ( ( - V_18 ) & V_18 ) ) || ( V_18 >= V_17 -> V_34 ) ) {
F_7 ( L_9 ) ;
V_17 -> V_40 = V_61 ;
}
V_18 = V_17 -> V_38 ;
if ( ( V_18 < V_61 ) ||
( V_18 != ( ( - V_18 ) & V_18 ) ) || ( V_18 >= V_17 -> V_34 ) ) {
F_7 ( L_10 ) ;
V_17 -> V_38 = V_61 ;
}
if ( V_17 -> V_36 >= V_17 -> V_38 ) {
F_7 ( L_11 ) ;
V_17 -> V_36 = 0 ;
}
V_17 -> V_36 = ( ( V_17 -> V_36 - V_62 ) &
( V_17 -> V_38 - 1 ) ) ;
if ( V_19 & V_63 ) {
V_21 = F_5 ( V_17 -> V_14 , F_11 ( V_17 -> V_14 , 0 ) ,
V_64 ,
V_28 | V_57
| V_30 ,
V_65 ,
V_20 , NULL , 0 , 1000 ) ;
if ( V_21 < 0 )
F_7 ( L_12 ) ;
}
if ( V_22 & V_66 ) {
V_21 = F_5 ( V_17 -> V_14 , F_11 ( V_17 -> V_14 , 0 ) ,
V_67 , V_28
| V_57 | V_30 ,
V_68 ,
V_20 , NULL , 0 , 1000 ) ;
if ( V_21 < 0 )
F_7 ( L_13 ) ;
}
V_17 -> V_69 = V_59 ;
if ( V_19 & V_70 ) {
T_5 * V_69 ;
T_3 V_71 = F_9 ( V_17 -> V_72 -> V_73 ) ;
V_69 = F_10 ( sizeof( * V_69 ) ,
V_53 ) ;
if ( ! V_69 ) {
V_21 = - V_54 ;
goto V_74;
}
V_21 = F_5 ( V_17 -> V_14 , F_6 ( V_17 -> V_14 , 0 ) ,
V_75 ,
V_28 | V_29
| V_30 ,
0 , V_20 , V_69 ,
2 , 1000 ) ;
if ( V_21 < 0 ) {
F_7 ( L_14 ,
V_59 ) ;
} else {
V_17 -> V_69 =
F_9 ( * V_69 ) ;
if ( V_17 -> V_69 > V_71 )
V_17 -> V_69 = V_71 ;
if ( V_17 -> V_69 > V_76 )
V_17 -> V_69 =
V_76 ;
if ( V_17 -> V_69 < V_59 )
V_17 -> V_69 =
V_59 ;
if ( V_17 -> V_69 !=
F_9 ( * V_69 ) ) {
V_21 = F_5 ( V_17 -> V_14 ,
F_11 ( V_17 -> V_14 , 0 ) ,
V_77 ,
V_28 | V_57
| V_30 ,
0 ,
V_20 , V_69 ,
2 , 1000 ) ;
if ( V_21 < 0 )
F_7 ( L_15 ) ;
}
}
F_12 ( V_69 ) ;
}
V_74:
if ( V_17 -> V_78 -> V_79 != ( V_17 -> V_69 - V_62 ) )
V_17 -> V_78 -> V_79 = V_17 -> V_69 - V_62 ;
return 0 ;
}
static void
F_14 ( struct V_16 * V_17 , struct V_80 * V_81 )
{
struct V_82 * V_83 ;
T_1 V_84 ;
for ( V_84 = 0 ; V_84 < V_81 -> V_24 -> V_25 . V_85 ; V_84 ++ ) {
V_83 = V_81 -> V_24 -> V_86 + V_84 ;
switch ( V_83 -> V_25 . V_87 & V_88 ) {
case V_89 :
if ( F_15 ( & V_83 -> V_25 ) ) {
if ( V_17 -> V_90 == NULL )
V_17 -> V_90 = V_83 ;
}
break;
case V_91 :
if ( F_15 ( & V_83 -> V_25 ) ) {
if ( V_17 -> V_92 == NULL )
V_17 -> V_92 = V_83 ;
} else {
if ( V_17 -> V_93 == NULL )
V_17 -> V_93 = V_83 ;
}
break;
default:
break;
}
}
}
static void F_16 ( struct V_16 * V_17 )
{
if ( V_17 == NULL )
return;
if ( V_17 -> V_94 != NULL ) {
F_17 ( V_17 -> V_94 ) ;
V_17 -> V_94 = NULL ;
}
if ( V_17 -> V_95 != NULL ) {
F_17 ( V_17 -> V_95 ) ;
V_17 -> V_95 = NULL ;
}
F_12 ( V_17 ) ;
}
static int F_18 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
struct V_16 * V_17 ;
struct V_96 * V_7 ;
T_1 * V_97 ;
int V_98 ;
int V_99 ;
T_1 V_20 ;
V_17 = F_10 ( sizeof( * V_17 ) , V_53 ) ;
if ( V_17 == NULL )
return - V_100 ;
F_19 ( & V_17 -> V_101 , V_102 , V_103 ) ;
V_17 -> V_101 . V_104 = & V_105 ;
V_17 -> V_106 . V_107 = ( unsigned long ) V_17 ;
V_17 -> V_106 . V_108 = V_109 ;
F_20 ( & V_17 -> V_110 , 0 ) ;
F_21 ( & V_17 -> V_111 ) ;
V_17 -> V_78 = V_6 -> V_2 ;
V_6 -> V_107 [ 0 ] = ( unsigned long ) V_17 ;
V_7 = F_22 ( V_81 ) ;
V_97 = V_81 -> V_24 -> V_112 ;
V_98 = V_81 -> V_24 -> V_113 ;
V_17 -> V_14 = V_6 -> V_14 ;
V_17 -> V_81 = V_81 ;
while ( ( V_98 > 0 ) && ( V_97 [ 0 ] > 2 ) && ( V_97 [ 0 ] <= V_98 ) ) {
if ( V_97 [ 1 ] != V_114 )
goto V_115;
switch ( V_97 [ 2 ] ) {
case V_116 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_117 ) ) )
break;
V_17 -> V_117 =
( const struct V_118 * ) V_97 ;
V_17 -> V_23 = F_23 ( V_6 -> V_14 ,
V_17 -> V_117 -> V_119 ) ;
V_17 -> V_107 = F_23 ( V_6 -> V_14 ,
V_17 -> V_117 -> V_120 ) ;
break;
case V_121 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_72 ) ) )
break;
V_17 -> V_72 =
( const struct V_122 * ) V_97 ;
V_6 -> V_123 =
F_9 ( V_17 -> V_72 -> V_73 ) ;
if ( V_6 -> V_123 < V_59 )
V_6 -> V_123 = V_59 ;
else if ( V_6 -> V_123 > V_76 )
V_6 -> V_123 = V_76 ;
break;
case V_124 :
if ( V_97 [ 0 ] < sizeof( * ( V_17 -> V_45 ) ) )
break;
V_17 -> V_45 = ( const struct V_125 * ) V_97 ;
break;
default:
break;
}
V_115:
V_99 = V_97 [ 0 ] ;
V_97 += V_99 ;
V_98 -= V_99 ;
}
if ( ( V_17 -> V_23 == NULL ) || ( V_17 -> V_107 == NULL ) ||
( V_17 -> V_72 == NULL ) || ( V_17 -> V_23 != V_81 ) )
goto error;
V_99 = F_24 ( V_7 , V_17 -> V_107 , V_6 ) ;
if ( V_99 )
goto error;
V_20 = V_17 -> V_107 -> V_24 -> V_25 . V_26 ;
V_99 = F_25 ( V_6 -> V_14 , V_20 , 0 ) ;
if ( V_99 )
goto V_126;
if ( F_4 ( V_17 ) )
goto V_126;
V_99 = F_25 ( V_6 -> V_14 , V_20 , 1 ) ;
if ( V_99 )
goto V_126;
F_14 ( V_17 , V_17 -> V_107 ) ;
F_14 ( V_17 , V_17 -> V_23 ) ;
if ( ( V_17 -> V_92 == NULL ) || ( V_17 -> V_93 == NULL ) ||
( V_17 -> V_90 == NULL ) )
goto V_126;
V_6 -> V_2 -> V_127 = & V_128 ;
F_26 ( V_17 -> V_107 , V_6 ) ;
F_26 ( V_17 -> V_23 , V_6 ) ;
F_26 ( V_17 -> V_81 , V_6 ) ;
V_99 = F_27 ( V_6 , V_17 -> V_72 -> V_129 ) ;
if ( V_99 )
goto V_126;
F_28 ( & V_6 -> V_14 -> V_6 , L_16 , V_6 -> V_2 -> V_130 ) ;
V_6 -> V_131 = F_29 ( V_6 -> V_14 ,
V_17 -> V_92 -> V_25 . V_132 & V_133 ) ;
V_6 -> V_134 = F_30 ( V_6 -> V_14 ,
V_17 -> V_93 -> V_25 . V_132 & V_133 ) ;
V_6 -> V_135 = V_17 -> V_90 ;
V_6 -> V_136 = V_17 -> V_32 ;
F_31 ( V_6 -> V_2 ) ;
V_17 -> V_137 = V_17 -> V_138 = 0 ;
return 0 ;
V_126:
F_26 ( V_17 -> V_23 , NULL ) ;
F_26 ( V_17 -> V_107 , NULL ) ;
F_32 ( V_7 , V_17 -> V_107 ) ;
error:
F_16 ( (struct V_16 * ) V_6 -> V_107 [ 0 ] ) ;
V_6 -> V_107 [ 0 ] = 0 ;
F_28 ( & V_6 -> V_14 -> V_6 , L_17 ) ;
return - V_100 ;
}
static void F_33 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_107 [ 0 ] ;
struct V_96 * V_7 = F_22 ( V_81 ) ;
if ( V_17 == NULL )
return;
F_20 ( & V_17 -> V_110 , 1 ) ;
if ( F_34 ( & V_17 -> V_101 ) )
F_35 ( & V_17 -> V_101 ) ;
F_36 ( & V_17 -> V_106 ) ;
if ( V_81 == V_17 -> V_23 && V_17 -> V_107 ) {
F_26 ( V_17 -> V_107 , NULL ) ;
F_32 ( V_7 , V_17 -> V_107 ) ;
V_17 -> V_107 = NULL ;
} else if ( V_81 == V_17 -> V_107 && V_17 -> V_23 ) {
F_26 ( V_17 -> V_23 , NULL ) ;
F_32 ( V_7 , V_17 -> V_23 ) ;
V_17 -> V_23 = NULL ;
}
F_26 ( V_17 -> V_81 , NULL ) ;
F_16 ( V_17 ) ;
}
static void F_37 ( T_1 * V_139 , T_2 V_140 , T_2 V_141 , T_2 V_142 )
{
if ( V_140 >= V_142 )
return;
if ( V_140 >= V_141 )
return;
if ( V_141 > V_142 )
V_141 = V_142 ;
memset ( V_139 + V_140 , 0 , V_141 - V_140 ) ;
}
static struct V_143 *
F_38 ( struct V_16 * V_17 , struct V_143 * V_144 )
{
struct V_143 * V_145 ;
T_2 V_146 ;
T_2 V_147 ;
T_2 V_148 ;
T_3 V_149 = 0 , V_150 ;
T_1 V_151 = 0 ;
if ( V_144 != NULL )
F_39 ( V_144 , V_17 -> V_94 ) ;
else
V_151 = 1 ;
if ( V_17 -> V_95 != NULL ) {
V_145 = V_17 -> V_95 ;
V_147 = V_17 -> V_152 ;
V_148 = V_17 -> V_153 ;
V_149 = V_17 -> V_154 ;
} else {
V_145 = F_40 ( ( V_17 -> V_34 + 1 ) , V_155 ) ;
if ( V_145 == NULL ) {
if ( V_144 != NULL ) {
F_17 ( V_144 ) ;
V_17 -> V_78 -> V_156 . V_157 ++ ;
}
goto V_158;
}
V_147 = F_41 ( sizeof( struct V_159 ) ,
V_17 -> V_40 ) +
sizeof( struct V_160 ) +
( V_17 -> V_42 + 1 ) *
sizeof( struct V_161 ) ;
V_148 = V_147 ;
V_147 = F_41 ( V_147 , V_17 -> V_38 ) + V_17 -> V_36 ;
F_37 ( V_145 -> V_107 , 0 , V_147 , V_147 ) ;
V_149 = 0 ;
V_17 -> V_154 = 0 ;
}
for (; V_149 < V_17 -> V_42 ; V_149 ++ ) {
if ( V_147 >= V_17 -> V_34 ) {
V_151 = 1 ;
break;
}
V_146 = V_17 -> V_34 - V_147 ;
if ( V_144 == NULL ) {
V_144 = V_17 -> V_94 ;
V_17 -> V_94 = NULL ;
if ( V_144 == NULL )
break;
}
if ( V_144 -> V_98 > V_146 ) {
if ( V_149 == 0 ) {
F_17 ( V_144 ) ;
V_144 = NULL ;
V_17 -> V_78 -> V_156 . V_157 ++ ;
} else {
if ( V_17 -> V_94 != NULL ) {
F_17 ( V_17 -> V_94 ) ;
V_17 -> V_78 -> V_156 . V_157 ++ ;
}
V_17 -> V_94 = V_144 ;
V_144 = NULL ;
V_151 = 1 ;
}
break;
}
memcpy ( ( ( T_1 * ) V_145 -> V_107 ) + V_147 , V_144 -> V_107 , V_144 -> V_98 ) ;
V_17 -> V_162 . V_163 [ V_149 ] . V_164 = F_42 ( V_144 -> V_98 ) ;
V_17 -> V_162 . V_163 [ V_149 ] . V_165 = F_42 ( V_147 ) ;
V_147 += V_144 -> V_98 ;
V_148 = V_147 ;
V_147 = F_41 ( V_147 , V_17 -> V_38 ) + V_17 -> V_36 ;
F_37 ( V_145 -> V_107 , V_148 , V_147 ,
V_17 -> V_34 ) ;
F_17 ( V_144 ) ;
V_144 = NULL ;
}
if ( V_144 != NULL ) {
F_17 ( V_144 ) ;
V_144 = NULL ;
V_17 -> V_78 -> V_156 . V_157 ++ ;
}
V_17 -> V_154 = V_149 ;
if ( V_149 == 0 ) {
V_17 -> V_95 = V_145 ;
V_17 -> V_152 = V_147 ;
V_17 -> V_153 = V_148 ;
goto V_158;
} else if ( ( V_149 < V_17 -> V_42 ) && ( V_151 == 0 ) ) {
V_17 -> V_95 = V_145 ;
V_17 -> V_152 = V_147 ;
V_17 -> V_153 = V_148 ;
if ( V_149 < V_166 )
V_17 -> V_167 = V_168 ;
goto V_158;
} else {
}
if ( V_148 > V_17 -> V_34 )
V_148 = V_17 -> V_34 ;
V_147 = V_148 ;
if ( V_147 > V_169 )
V_147 = V_17 -> V_34 ;
F_37 ( V_145 -> V_107 , V_148 , V_147 , V_17 -> V_34 ) ;
V_148 = V_147 ;
if ( ( ( V_148 < V_17 -> V_34 ) && ( ( V_148 %
F_9 ( V_17 -> V_93 -> V_25 . V_170 ) ) == 0 ) ) ||
( ( ( V_148 == V_17 -> V_34 ) && ( ( V_17 -> V_34 %
F_9 ( V_17 -> V_93 -> V_25 . V_170 ) ) == 0 ) ) &&
( V_17 -> V_34 < F_8 ( V_17 -> V_31 . V_35 ) ) ) ) {
* ( ( ( T_1 * ) V_145 -> V_107 ) + V_148 ) = 0 ;
V_148 ++ ;
}
for (; V_149 <= V_47 ; V_149 ++ ) {
V_17 -> V_162 . V_163 [ V_149 ] . V_164 = 0 ;
V_17 -> V_162 . V_163 [ V_149 ] . V_165 = 0 ;
}
V_17 -> V_162 . V_171 . V_172 = F_13 ( V_173 ) ;
V_17 -> V_162 . V_171 . V_174 =
F_42 ( sizeof( V_17 -> V_162 . V_171 ) ) ;
V_17 -> V_162 . V_171 . V_175 = F_42 ( V_17 -> V_176 ) ;
V_17 -> V_162 . V_171 . V_177 = F_42 ( V_148 ) ;
V_150 = F_41 ( sizeof( struct V_159 ) , V_17 -> V_40 ) ;
V_17 -> V_162 . V_171 . V_178 = F_42 ( V_150 ) ;
memcpy ( V_145 -> V_107 , & ( V_17 -> V_162 . V_171 ) , sizeof( V_17 -> V_162 . V_171 ) ) ;
V_17 -> V_176 ++ ;
V_17 -> V_162 . V_179 . V_172 =
F_13 ( V_180 ) ;
V_146 = sizeof( V_17 -> V_162 . V_179 ) + ( ( V_17 -> V_154 + 1 ) *
sizeof( struct V_161 ) ) ;
V_17 -> V_162 . V_179 . V_181 = F_42 ( V_146 ) ;
V_17 -> V_162 . V_179 . V_182 = 0 ;
memcpy ( ( ( T_1 * ) V_145 -> V_107 ) + V_150 ,
& ( V_17 -> V_162 . V_179 ) ,
sizeof( V_17 -> V_162 . V_179 ) ) ;
memcpy ( ( ( T_1 * ) V_145 -> V_107 ) + V_150 + sizeof( V_17 -> V_162 . V_179 ) ,
& ( V_17 -> V_162 . V_163 ) ,
( V_17 -> V_154 + 1 ) *
sizeof( struct V_161 ) ) ;
F_43 ( V_145 , V_148 ) ;
V_17 -> V_95 = NULL ;
V_17 -> V_78 -> V_156 . V_183 += V_17 -> V_154 ;
return V_145 ;
V_158:
if ( V_17 -> V_95 != NULL )
F_44 ( V_17 ) ;
return NULL ;
}
static void F_44 ( struct V_16 * V_17 )
{
if ( ! ( F_34 ( & V_17 -> V_101 ) || F_45 ( & V_17 -> V_110 ) ) )
F_46 ( & V_17 -> V_101 ,
F_47 ( 0 , V_184 ) ,
V_103 ) ;
}
static enum V_185 V_105 ( struct V_186 * V_187 )
{
struct V_16 * V_17 =
F_48 ( V_187 , struct V_16 , V_101 ) ;
if ( ! F_45 ( & V_17 -> V_110 ) )
F_49 ( & V_17 -> V_106 ) ;
return V_188 ;
}
static void V_109 ( unsigned long V_189 )
{
struct V_16 * V_17 = (struct V_16 * ) V_189 ;
F_50 ( & V_17 -> V_111 ) ;
if ( V_17 -> V_167 != 0 ) {
V_17 -> V_167 -- ;
F_44 ( V_17 ) ;
F_51 ( & V_17 -> V_111 ) ;
} else if ( V_17 -> V_78 != NULL ) {
F_51 ( & V_17 -> V_111 ) ;
F_52 ( V_17 -> V_78 ) ;
F_53 ( NULL , V_17 -> V_78 ) ;
F_54 ( V_17 -> V_78 ) ;
}
}
static struct V_143 *
F_55 ( struct V_5 * V_6 , struct V_143 * V_144 , T_6 V_19 )
{
struct V_143 * V_145 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_107 [ 0 ] ;
if ( V_17 == NULL )
goto error;
F_50 ( & V_17 -> V_111 ) ;
V_145 = F_38 ( V_17 , V_144 ) ;
F_51 ( & V_17 -> V_111 ) ;
return V_145 ;
error:
if ( V_144 != NULL )
F_17 ( V_144 ) ;
return NULL ;
}
static int F_56 ( struct V_5 * V_6 , struct V_143 * V_190 )
{
struct V_143 * V_144 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_107 [ 0 ] ;
int V_98 ;
int V_191 ;
int V_192 ;
int V_147 ;
struct V_159 * V_171 ;
struct V_160 * V_179 ;
struct V_161 * V_163 ;
if ( V_17 == NULL )
goto error;
if ( V_190 -> V_98 < ( sizeof( struct V_159 ) +
sizeof( struct V_160 ) ) ) {
F_7 ( L_18 ) ;
goto error;
}
V_171 = (struct V_159 * ) V_190 -> V_107 ;
if ( F_8 ( V_171 -> V_172 ) != V_173 ) {
F_7 ( L_19 ,
F_8 ( V_171 -> V_172 ) ) ;
goto error;
}
V_98 = F_9 ( V_171 -> V_177 ) ;
if ( V_98 > V_17 -> V_32 ) {
F_7 ( L_20 , V_98 ,
V_17 -> V_32 ) ;
goto error;
}
if ( ( V_17 -> V_193 + 1 ) != F_9 ( V_171 -> V_175 ) &&
( V_17 -> V_193 || F_9 ( V_171 -> V_175 ) ) &&
! ( ( V_17 -> V_193 == 0xffff ) && ! F_9 ( V_171 -> V_175 ) ) ) {
F_7 ( L_21 ,
V_17 -> V_193 , F_9 ( V_171 -> V_175 ) ) ;
}
V_17 -> V_193 = F_9 ( V_171 -> V_175 ) ;
V_98 = F_9 ( V_171 -> V_178 ) ;
if ( ( V_98 + sizeof( struct V_160 ) ) > V_190 -> V_98 ) {
F_7 ( L_22 ,
F_9 ( V_171 -> V_178 ) ) ;
goto error;
}
V_179 = (struct V_160 * ) ( ( ( T_1 * ) V_190 -> V_107 ) + V_98 ) ;
if ( F_8 ( V_179 -> V_172 ) != V_180 ) {
F_7 ( L_23 ,
F_8 ( V_179 -> V_172 ) ) ;
goto error;
}
if ( F_9 ( V_179 -> V_181 ) < V_194 ) {
F_7 ( L_24 ,
F_8 ( V_179 -> V_172 ) ) ;
goto error;
}
V_191 = ( ( F_9 ( V_179 -> V_181 ) -
sizeof( struct V_160 ) ) /
sizeof( struct V_161 ) ) ;
V_191 -- ;
V_98 += sizeof( struct V_160 ) ;
if ( ( V_98 + V_191 * ( sizeof( struct V_161 ) ) ) >
V_190 -> V_98 ) {
F_7 ( L_25 , V_191 ) ;
goto error;
}
V_163 = (struct V_161 * ) ( ( ( T_1 * ) V_190 -> V_107 ) + V_98 ) ;
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ , V_163 ++ ) {
V_147 = F_9 ( V_163 -> V_165 ) ;
V_98 = F_9 ( V_163 -> V_164 ) ;
if ( ( V_147 == 0 ) || ( V_98 == 0 ) ) {
if ( ! V_192 )
goto error;
break;
}
if ( ( ( V_147 + V_98 ) > V_190 -> V_98 ) ||
( V_98 > V_17 -> V_32 ) || ( V_98 < V_62 ) ) {
F_7 ( L_26
L_27 ,
V_192 , V_147 , V_98 , V_190 ) ;
if ( ! V_192 )
goto error;
break;
} else {
V_144 = F_57 ( V_190 , V_155 ) ;
if ( ! V_144 )
goto error;
V_144 -> V_98 = V_98 ;
V_144 -> V_107 = ( ( T_1 * ) V_190 -> V_107 ) + V_147 ;
F_58 ( V_144 , V_98 ) ;
F_59 ( V_6 , V_144 ) ;
}
}
return 1 ;
error:
return 0 ;
}
static void
F_60 ( struct V_16 * V_17 ,
struct V_195 * V_107 )
{
T_7 V_138 = F_8 ( V_107 -> V_196 ) ;
T_7 V_137 = F_8 ( V_107 -> V_197 ) ;
if ( ( V_137 != V_17 -> V_137 ) || ( V_138 != V_17 -> V_138 ) ) {
V_17 -> V_137 = V_137 ;
V_17 -> V_138 = V_138 ;
if ( ( V_137 > 1000000 ) && ( V_138 > 1000000 ) ) {
F_61 (KERN_INFO KBUILD_MODNAME
L_28
L_29 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000000U),
(unsigned int)(tx_speed / 1000000U)) ;
} else {
F_61 (KERN_INFO KBUILD_MODNAME
L_30
L_31 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000U),
(unsigned int)(tx_speed / 1000U)) ;
}
}
}
static void F_62 ( struct V_5 * V_6 , struct V_198 * V_198 )
{
struct V_16 * V_17 ;
struct V_199 * V_200 ;
V_17 = (struct V_16 * ) V_6 -> V_107 [ 0 ] ;
if ( V_198 -> V_201 < sizeof( * V_200 ) )
return;
if ( F_63 ( V_202 , & V_6 -> V_19 ) ) {
F_60 ( V_17 ,
(struct V_195 * ) V_198 -> V_203 ) ;
return;
}
V_200 = V_198 -> V_203 ;
switch ( V_200 -> V_204 ) {
case V_205 :
V_17 -> V_206 = V_200 -> V_207 ;
F_61 (KERN_INFO KBUILD_MODNAME L_32
L_33 ,
ctx->netdev->name, ctx->connected ? L_34 : L_35 ) ;
if ( V_17 -> V_206 )
F_64 ( V_6 -> V_2 ) ;
else {
F_31 ( V_6 -> V_2 ) ;
V_17 -> V_137 = V_17 -> V_138 = 0 ;
}
break;
case V_208 :
if ( V_198 -> V_201 < ( sizeof( * V_200 ) +
sizeof( struct V_195 ) ) )
F_65 ( V_202 , & V_6 -> V_19 ) ;
else
F_60 ( V_17 ,
(struct V_195 * ) & V_200 [ 1 ] ) ;
break;
default:
F_66 ( & V_6 -> V_14 -> V_6 , L_36
L_37 , V_200 -> V_204 ) ;
break;
}
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_6 -> V_107 [ 0 ] ;
if ( V_17 == NULL )
return 1 ;
return ! V_17 -> V_206 ;
}
static int
F_68 ( struct V_80 * V_14 , const struct V_209 * V_210 )
{
return F_69 ( V_14 , V_210 ) ;
}
static void F_70 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = F_71 ( V_81 ) ;
if ( V_6 == NULL )
return;
F_72 ( V_81 ) ;
}
static int F_73 ( struct V_5 * V_6 , int V_135 )
{
V_6 -> V_81 -> V_211 = V_135 ;
return 0 ;
}
