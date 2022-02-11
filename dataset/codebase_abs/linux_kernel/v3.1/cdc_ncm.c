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
F_12 ( V_69 ) ;
} else {
V_17 -> V_69 =
F_9 ( * V_69 ) ;
if ( V_71 < V_76 ) {
if ( V_17 -> V_69 > V_71 )
V_17 -> V_69 = V_71 ;
} else {
if ( V_17 -> V_69 >
V_76 )
V_17 -> V_69 =
V_76 ;
}
if ( V_17 -> V_69 < V_59 )
V_17 -> V_69 =
V_59 ;
V_21 = F_5 ( V_17 -> V_14 ,
F_11 ( V_17 -> V_14 , 0 ) ,
V_77 ,
V_28 | V_57
| V_30 ,
0 ,
V_20 , V_69 ,
2 , 1000 ) ;
F_12 ( V_69 ) ;
V_74:
if ( V_21 < 0 )
F_7 ( L_15 ) ;
}
}
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
F_17 ( & V_17 -> V_94 ) ;
if ( V_17 -> V_95 != NULL ) {
F_18 ( V_17 -> V_95 ) ;
V_17 -> V_95 = NULL ;
}
if ( V_17 -> V_96 != NULL ) {
F_18 ( V_17 -> V_96 ) ;
V_17 -> V_96 = NULL ;
}
F_12 ( V_17 ) ;
}
static int F_19 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
struct V_16 * V_17 ;
struct V_97 * V_7 ;
T_1 * V_98 ;
int V_99 ;
int V_100 ;
T_1 V_20 ;
V_17 = F_20 ( sizeof( * V_17 ) , V_53 ) ;
if ( V_17 == NULL )
return - V_101 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
F_21 ( & V_17 -> V_94 ) ;
F_22 ( & V_17 -> V_102 ) ;
V_17 -> V_78 = V_6 -> V_2 ;
V_6 -> V_103 [ 0 ] = ( unsigned long ) V_17 ;
V_7 = F_23 ( V_81 ) ;
V_98 = V_81 -> V_24 -> V_104 ;
V_99 = V_81 -> V_24 -> V_105 ;
V_17 -> V_14 = V_6 -> V_14 ;
V_17 -> V_81 = V_81 ;
while ( ( V_99 > 0 ) && ( V_98 [ 0 ] > 2 ) && ( V_98 [ 0 ] <= V_99 ) ) {
if ( V_98 [ 1 ] != V_106 )
goto V_107;
switch ( V_98 [ 2 ] ) {
case V_108 :
if ( V_98 [ 0 ] < sizeof( * ( V_17 -> V_109 ) ) )
break;
V_17 -> V_109 =
( const struct V_110 * ) V_98 ;
V_17 -> V_23 = F_24 ( V_6 -> V_14 ,
V_17 -> V_109 -> V_111 ) ;
V_17 -> V_103 = F_24 ( V_6 -> V_14 ,
V_17 -> V_109 -> V_112 ) ;
break;
case V_113 :
if ( V_98 [ 0 ] < sizeof( * ( V_17 -> V_72 ) ) )
break;
V_17 -> V_72 =
( const struct V_114 * ) V_98 ;
V_6 -> V_115 =
F_9 ( V_17 -> V_72 -> V_73 ) ;
if ( V_6 -> V_115 < V_59 )
V_6 -> V_115 = V_59 ;
else if ( V_6 -> V_115 > V_76 )
V_6 -> V_115 = V_76 ;
break;
case V_116 :
if ( V_98 [ 0 ] < sizeof( * ( V_17 -> V_45 ) ) )
break;
V_17 -> V_45 = ( const struct V_117 * ) V_98 ;
break;
default:
break;
}
V_107:
V_100 = V_98 [ 0 ] ;
V_98 += V_100 ;
V_99 -= V_100 ;
}
if ( ( V_17 -> V_23 == NULL ) || ( V_17 -> V_103 == NULL ) ||
( V_17 -> V_72 == NULL ) || ( V_17 -> V_23 != V_81 ) )
goto error;
V_100 = F_25 ( V_7 , V_17 -> V_103 , V_6 ) ;
if ( V_100 )
goto error;
V_20 = V_17 -> V_103 -> V_24 -> V_25 . V_26 ;
V_100 = F_26 ( V_6 -> V_14 , V_20 , 0 ) ;
if ( V_100 )
goto V_118;
if ( F_4 ( V_17 ) )
goto V_118;
V_100 = F_26 ( V_6 -> V_14 , V_20 , 1 ) ;
if ( V_100 )
goto V_118;
F_14 ( V_17 , V_17 -> V_103 ) ;
F_14 ( V_17 , V_17 -> V_23 ) ;
if ( ( V_17 -> V_92 == NULL ) || ( V_17 -> V_93 == NULL ) ||
( V_17 -> V_90 == NULL ) )
goto V_118;
V_6 -> V_2 -> V_119 = & V_120 ;
F_27 ( V_17 -> V_103 , V_6 ) ;
F_27 ( V_17 -> V_23 , V_6 ) ;
F_27 ( V_17 -> V_81 , V_6 ) ;
V_100 = F_28 ( V_6 , V_17 -> V_72 -> V_121 ) ;
if ( V_100 )
goto V_118;
F_29 ( & V_6 -> V_14 -> V_6 , L_16
L_17 ,
V_6 -> V_2 -> V_122 [ 0 ] , V_6 -> V_2 -> V_122 [ 1 ] ,
V_6 -> V_2 -> V_122 [ 2 ] , V_6 -> V_2 -> V_122 [ 3 ] ,
V_6 -> V_2 -> V_122 [ 4 ] , V_6 -> V_2 -> V_122 [ 5 ] ) ;
V_6 -> V_123 = F_30 ( V_6 -> V_14 ,
V_17 -> V_92 -> V_25 . V_124 & V_125 ) ;
V_6 -> V_126 = F_31 ( V_6 -> V_14 ,
V_17 -> V_93 -> V_25 . V_124 & V_125 ) ;
V_6 -> V_127 = V_17 -> V_90 ;
V_6 -> V_128 = V_17 -> V_32 ;
F_32 ( V_6 -> V_2 ) ;
V_17 -> V_129 = V_17 -> V_130 = 0 ;
return 0 ;
V_118:
F_27 ( V_17 -> V_23 , NULL ) ;
F_27 ( V_17 -> V_103 , NULL ) ;
F_33 ( V_7 , V_17 -> V_103 ) ;
error:
F_16 ( (struct V_16 * ) V_6 -> V_103 [ 0 ] ) ;
V_6 -> V_103 [ 0 ] = 0 ;
F_29 ( & V_6 -> V_14 -> V_6 , L_18 ) ;
return - V_101 ;
}
static void F_34 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_103 [ 0 ] ;
struct V_97 * V_7 = F_23 ( V_81 ) ;
if ( V_17 == NULL )
return;
if ( V_81 == V_17 -> V_23 && V_17 -> V_103 ) {
F_27 ( V_17 -> V_103 , NULL ) ;
F_33 ( V_7 , V_17 -> V_103 ) ;
V_17 -> V_103 = NULL ;
} else if ( V_81 == V_17 -> V_103 && V_17 -> V_23 ) {
F_27 ( V_17 -> V_23 , NULL ) ;
F_33 ( V_7 , V_17 -> V_23 ) ;
V_17 -> V_23 = NULL ;
}
F_27 ( V_17 -> V_81 , NULL ) ;
F_16 ( V_17 ) ;
}
static void F_35 ( T_1 * V_131 , T_2 V_132 , T_2 V_133 , T_2 V_134 )
{
if ( V_132 >= V_134 )
return;
if ( V_132 >= V_133 )
return;
if ( V_133 > V_134 )
V_133 = V_134 ;
memset ( V_131 + V_132 , 0 , V_133 - V_132 ) ;
}
static struct V_135 *
F_36 ( struct V_16 * V_17 , struct V_135 * V_136 )
{
struct V_135 * V_137 ;
T_2 V_138 ;
T_2 V_139 ;
T_2 V_140 ;
T_3 V_141 = 0 , V_142 ;
T_1 V_143 = 0 ;
if ( V_136 != NULL )
F_37 ( V_136 , V_17 -> V_95 ) ;
else
V_143 = 1 ;
if ( V_17 -> V_96 != NULL ) {
V_137 = V_17 -> V_96 ;
V_139 = V_17 -> V_144 ;
V_140 = V_17 -> V_145 ;
V_141 = V_17 -> V_146 ;
} else {
V_137 = F_38 ( ( V_17 -> V_34 + 1 ) , V_147 ) ;
if ( V_137 == NULL ) {
if ( V_136 != NULL ) {
F_18 ( V_136 ) ;
V_17 -> V_78 -> V_148 . V_149 ++ ;
}
goto V_150;
}
V_139 = F_39 ( sizeof( struct V_151 ) ,
V_17 -> V_40 ) +
sizeof( struct V_152 ) +
( V_17 -> V_42 + 1 ) *
sizeof( struct V_153 ) ;
V_140 = V_139 ;
V_139 = F_39 ( V_139 , V_17 -> V_38 ) + V_17 -> V_36 ;
F_35 ( V_137 -> V_103 , 0 , V_139 , V_139 ) ;
V_141 = 0 ;
V_17 -> V_146 = 0 ;
}
for (; V_141 < V_17 -> V_42 ; V_141 ++ ) {
if ( V_139 >= V_17 -> V_34 ) {
V_143 = 1 ;
break;
}
V_138 = V_17 -> V_34 - V_139 ;
if ( V_136 == NULL ) {
V_136 = V_17 -> V_95 ;
V_17 -> V_95 = NULL ;
if ( V_136 == NULL )
break;
}
if ( V_136 -> V_99 > V_138 ) {
if ( V_141 == 0 ) {
F_18 ( V_136 ) ;
V_136 = NULL ;
V_17 -> V_78 -> V_148 . V_149 ++ ;
} else {
if ( V_17 -> V_95 != NULL ) {
F_18 ( V_17 -> V_95 ) ;
V_17 -> V_78 -> V_148 . V_149 ++ ;
}
V_17 -> V_95 = V_136 ;
V_136 = NULL ;
V_143 = 1 ;
}
break;
}
memcpy ( ( ( T_1 * ) V_137 -> V_103 ) + V_139 , V_136 -> V_103 , V_136 -> V_99 ) ;
V_17 -> V_154 . V_155 [ V_141 ] . V_156 = F_40 ( V_136 -> V_99 ) ;
V_17 -> V_154 . V_155 [ V_141 ] . V_157 = F_40 ( V_139 ) ;
V_139 += V_136 -> V_99 ;
V_140 = V_139 ;
V_139 = F_39 ( V_139 , V_17 -> V_38 ) + V_17 -> V_36 ;
F_35 ( V_137 -> V_103 , V_140 , V_139 ,
V_17 -> V_34 ) ;
F_18 ( V_136 ) ;
V_136 = NULL ;
}
if ( V_136 != NULL ) {
F_18 ( V_136 ) ;
V_136 = NULL ;
V_17 -> V_78 -> V_148 . V_149 ++ ;
}
V_17 -> V_146 = V_141 ;
if ( V_141 == 0 ) {
V_17 -> V_96 = V_137 ;
V_17 -> V_144 = V_139 ;
V_17 -> V_145 = V_140 ;
goto V_150;
} else if ( ( V_141 < V_17 -> V_42 ) && ( V_143 == 0 ) ) {
V_17 -> V_96 = V_137 ;
V_17 -> V_144 = V_139 ;
V_17 -> V_145 = V_140 ;
if ( V_141 < V_158 )
V_17 -> V_159 = 2 ;
goto V_150;
} else {
}
if ( V_140 > V_17 -> V_34 )
V_140 = V_17 -> V_34 ;
V_139 = V_140 ;
if ( V_139 > V_160 )
V_139 = V_17 -> V_34 ;
F_35 ( V_137 -> V_103 , V_140 , V_139 , V_17 -> V_34 ) ;
V_140 = V_139 ;
if ( ( ( V_140 < V_17 -> V_34 ) && ( ( V_140 %
F_9 ( V_17 -> V_93 -> V_25 . V_161 ) ) == 0 ) ) ||
( ( ( V_140 == V_17 -> V_34 ) && ( ( V_17 -> V_34 %
F_9 ( V_17 -> V_93 -> V_25 . V_161 ) ) == 0 ) ) &&
( V_17 -> V_34 < F_8 ( V_17 -> V_31 . V_35 ) ) ) ) {
* ( ( ( T_1 * ) V_137 -> V_103 ) + V_140 ) = 0 ;
V_140 ++ ;
}
for (; V_141 <= V_47 ; V_141 ++ ) {
V_17 -> V_154 . V_155 [ V_141 ] . V_156 = 0 ;
V_17 -> V_154 . V_155 [ V_141 ] . V_157 = 0 ;
}
V_17 -> V_154 . V_162 . V_163 = F_13 ( V_164 ) ;
V_17 -> V_154 . V_162 . V_165 =
F_40 ( sizeof( V_17 -> V_154 . V_162 ) ) ;
V_17 -> V_154 . V_162 . V_166 = F_40 ( V_17 -> V_167 ) ;
V_17 -> V_154 . V_162 . V_168 = F_40 ( V_140 ) ;
V_142 = F_39 ( sizeof( struct V_151 ) , V_17 -> V_40 ) ;
V_17 -> V_154 . V_162 . V_169 = F_40 ( V_142 ) ;
memcpy ( V_137 -> V_103 , & ( V_17 -> V_154 . V_162 ) , sizeof( V_17 -> V_154 . V_162 ) ) ;
V_17 -> V_167 ++ ;
V_17 -> V_154 . V_170 . V_163 =
F_13 ( V_171 ) ;
V_138 = sizeof( V_17 -> V_154 . V_170 ) + ( ( V_17 -> V_146 + 1 ) *
sizeof( struct V_153 ) ) ;
V_17 -> V_154 . V_170 . V_172 = F_40 ( V_138 ) ;
V_17 -> V_154 . V_170 . V_173 = 0 ;
memcpy ( ( ( T_1 * ) V_137 -> V_103 ) + V_142 ,
& ( V_17 -> V_154 . V_170 ) ,
sizeof( V_17 -> V_154 . V_170 ) ) ;
memcpy ( ( ( T_1 * ) V_137 -> V_103 ) + V_142 + sizeof( V_17 -> V_154 . V_170 ) ,
& ( V_17 -> V_154 . V_155 ) ,
( V_17 -> V_146 + 1 ) *
sizeof( struct V_153 ) ) ;
F_41 ( V_137 , V_140 ) ;
V_17 -> V_96 = NULL ;
return V_137 ;
V_150:
return NULL ;
}
static void F_42 ( struct V_16 * V_17 )
{
if ( F_43 ( & V_17 -> V_94 ) == 0 ) {
V_17 -> V_94 . V_174 = & V_175 ;
V_17 -> V_94 . V_103 = ( unsigned long ) V_17 ;
V_17 -> V_94 . V_176 = V_177 + ( ( V_178 + 999 ) / 1000 ) ;
F_44 ( & V_17 -> V_94 ) ;
}
}
static void V_175 ( unsigned long V_179 )
{
struct V_16 * V_17 = (struct V_16 * ) V_179 ;
T_1 V_180 ;
F_45 ( & V_17 -> V_102 ) ;
if ( V_17 -> V_159 != 0 ) {
V_17 -> V_159 -- ;
V_180 = 1 ;
} else {
V_180 = 0 ;
}
F_46 ( & V_17 -> V_102 ) ;
if ( V_180 ) {
F_45 ( & V_17 -> V_102 ) ;
F_42 ( V_17 ) ;
F_46 ( & V_17 -> V_102 ) ;
} else if ( V_17 -> V_78 != NULL ) {
F_47 ( NULL , V_17 -> V_78 ) ;
}
}
static struct V_135 *
F_48 ( struct V_5 * V_6 , struct V_135 * V_136 , T_6 V_19 )
{
struct V_135 * V_137 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_103 [ 0 ] ;
T_1 V_181 = 0 ;
if ( V_17 == NULL )
goto error;
F_45 ( & V_17 -> V_102 ) ;
V_137 = F_36 ( V_17 , V_136 ) ;
if ( V_17 -> V_96 != NULL )
V_181 = 1 ;
if ( V_181 )
F_42 ( V_17 ) ;
if ( V_137 )
V_6 -> V_2 -> V_148 . V_182 += V_17 -> V_146 ;
F_46 ( & V_17 -> V_102 ) ;
return V_137 ;
error:
if ( V_136 != NULL )
F_18 ( V_136 ) ;
return NULL ;
}
static int F_49 ( struct V_5 * V_6 , struct V_135 * V_183 )
{
struct V_135 * V_136 ;
struct V_16 * V_17 ;
int V_184 ;
int V_185 ;
int V_100 ;
int V_186 ;
int V_187 ;
int V_139 ;
V_17 = (struct V_16 * ) V_6 -> V_103 [ 0 ] ;
if ( V_17 == NULL )
goto error;
V_185 = V_183 -> V_99 ;
V_184 = V_49 ;
if ( V_185 < ( sizeof( V_17 -> V_188 . V_162 ) + sizeof( V_17 -> V_188 . V_170 ) ) ) {
F_7 ( L_19 ) ;
goto error;
}
memcpy ( & ( V_17 -> V_188 . V_162 ) , ( ( T_1 * ) V_183 -> V_103 ) ,
sizeof( V_17 -> V_188 . V_162 ) ) ;
if ( F_8 ( V_17 -> V_188 . V_162 . V_163 ) !=
V_164 ) {
F_7 ( L_20 ,
F_8 ( V_17 -> V_188 . V_162 . V_163 ) ) ;
goto error;
}
V_100 = F_9 ( V_17 -> V_188 . V_162 . V_168 ) ;
if ( V_100 > V_184 ) {
F_7 ( L_21 , V_100 , V_184 ) ;
goto error;
}
V_100 = F_9 ( V_17 -> V_188 . V_162 . V_169 ) ;
if ( ( V_100 + sizeof( V_17 -> V_188 . V_170 ) ) > V_185 ) {
F_7 ( L_22 ) ;
goto error;
}
memcpy ( & ( V_17 -> V_188 . V_170 ) , ( ( T_1 * ) V_183 -> V_103 ) + V_100 ,
sizeof( V_17 -> V_188 . V_170 ) ) ;
if ( F_8 ( V_17 -> V_188 . V_170 . V_163 ) !=
V_171 ) {
F_7 ( L_23 ,
F_8 ( V_17 -> V_188 . V_170 . V_163 ) ) ;
goto error;
}
if ( F_9 ( V_17 -> V_188 . V_170 . V_172 ) <
V_189 ) {
F_7 ( L_24 ,
F_8 ( V_17 -> V_188 . V_170 . V_163 ) ) ;
goto error;
}
V_186 = ( ( F_9 ( V_17 -> V_188 . V_170 . V_172 ) -
sizeof( struct V_152 ) ) /
sizeof( struct V_153 ) ) ;
V_186 -- ;
F_7 ( L_25 , V_186 ) ;
V_100 += sizeof( V_17 -> V_188 . V_170 ) ;
if ( ( V_100 + V_186 * ( sizeof( struct V_153 ) ) ) > V_185 ) {
F_7 ( L_26 , V_186 ) ;
goto error;
}
if ( V_186 > V_47 ) {
F_7 ( L_27 ,
V_186 , V_47 ) ;
V_186 = V_47 ;
}
memcpy ( & ( V_17 -> V_188 . V_155 ) , ( ( T_1 * ) V_183 -> V_103 ) + V_100 ,
V_186 * ( sizeof( struct V_153 ) ) ) ;
for ( V_187 = 0 ; V_187 < V_186 ; V_187 ++ ) {
V_139 = F_9 ( V_17 -> V_188 . V_155 [ V_187 ] . V_157 ) ;
V_100 = F_9 ( V_17 -> V_188 . V_155 [ V_187 ] . V_156 ) ;
if ( ( V_139 == 0 ) || ( V_100 == 0 ) ) {
if ( ! V_187 )
goto error;
break;
}
if ( ( ( V_139 + V_100 ) > V_185 ) ||
( V_100 > V_76 ) || ( V_100 < V_62 ) ) {
F_7 ( L_28
L_29 ,
V_187 , V_139 , V_100 , V_183 ) ;
if ( ! V_187 )
goto error;
break;
} else {
V_136 = F_50 ( V_183 , V_147 ) ;
if ( ! V_136 )
goto error;
V_136 -> V_99 = V_100 ;
V_136 -> V_103 = ( ( T_1 * ) V_183 -> V_103 ) + V_139 ;
F_51 ( V_136 , V_100 ) ;
F_52 ( V_6 , V_136 ) ;
}
}
return 1 ;
error:
return 0 ;
}
static void
F_53 ( struct V_16 * V_17 ,
struct V_190 * V_103 )
{
T_7 V_130 = F_8 ( V_103 -> V_191 ) ;
T_7 V_129 = F_8 ( V_103 -> V_192 ) ;
if ( ( V_129 != V_17 -> V_129 ) || ( V_130 != V_17 -> V_130 ) ) {
V_17 -> V_129 = V_129 ;
V_17 -> V_130 = V_130 ;
if ( ( V_129 > 1000000 ) && ( V_130 > 1000000 ) ) {
F_54 (KERN_INFO KBUILD_MODNAME
L_30
L_31 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000000U),
(unsigned int)(tx_speed / 1000000U)) ;
} else {
F_54 (KERN_INFO KBUILD_MODNAME
L_32
L_33 ,
ctx->netdev->name,
(unsigned int)(rx_speed / 1000U),
(unsigned int)(tx_speed / 1000U)) ;
}
}
}
static void F_55 ( struct V_5 * V_6 , struct V_193 * V_193 )
{
struct V_16 * V_17 ;
struct V_194 * V_195 ;
V_17 = (struct V_16 * ) V_6 -> V_103 [ 0 ] ;
if ( V_193 -> V_196 < sizeof( * V_195 ) )
return;
if ( F_56 ( V_197 , & V_6 -> V_19 ) ) {
F_53 ( V_17 ,
(struct V_190 * ) V_193 -> V_198 ) ;
return;
}
V_195 = V_193 -> V_198 ;
switch ( V_195 -> V_199 ) {
case V_200 :
V_17 -> V_201 = V_195 -> V_202 ;
F_54 (KERN_INFO KBUILD_MODNAME L_34
L_35 ,
ctx->netdev->name, ctx->connected ? L_36 : L_37 ) ;
if ( V_17 -> V_201 )
F_57 ( V_6 -> V_2 ) ;
else {
F_32 ( V_6 -> V_2 ) ;
V_17 -> V_129 = V_17 -> V_130 = 0 ;
}
break;
case V_203 :
if ( V_193 -> V_196 < ( sizeof( * V_195 ) +
sizeof( struct V_190 ) ) )
F_58 ( V_197 , & V_6 -> V_19 ) ;
else
F_53 ( V_17 ,
(struct V_190 * ) & V_195 [ 1 ] ) ;
break;
default:
F_59 ( & V_6 -> V_14 -> V_6 , L_38
L_39 , V_195 -> V_199 ) ;
break;
}
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_6 -> V_103 [ 0 ] ;
if ( V_17 == NULL )
return 1 ;
return ! V_17 -> V_201 ;
}
static int
F_61 ( struct V_80 * V_14 , const struct V_204 * V_205 )
{
return F_62 ( V_14 , V_205 ) ;
}
static void F_63 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = F_64 ( V_81 ) ;
if ( V_6 == NULL )
return;
F_65 ( V_81 ) ;
}
static int F_66 ( struct V_5 * V_6 , int V_127 )
{
V_6 -> V_81 -> V_206 = V_127 ;
return 0 ;
}
static int T_8 F_67 ( void )
{
F_54 (KERN_INFO KBUILD_MODNAME L_40 DRIVER_VERSION L_41 ) ;
return F_68 ( & V_207 ) ;
}
static void T_9 F_69 ( void )
{
F_70 ( & V_207 ) ;
}
