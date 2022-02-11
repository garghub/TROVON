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
static int
F_4 ( struct V_16 * V_17 , struct V_18 * V_19 ,
void * V_20 , T_1 V_21 , T_1 * V_22 , T_1 V_23 )
{
int V_24 ;
V_24 = F_5 ( V_17 -> V_14 , ( V_19 -> V_25 & V_26 ) ?
F_6 ( V_17 -> V_14 , 0 ) :
F_7 ( V_17 -> V_14 , 0 ) ,
V_19 -> V_27 , V_19 -> V_25 ,
V_19 -> V_28 ,
V_19 -> V_29 , V_20 ,
V_19 -> V_30 , V_23 ) ;
if ( V_24 < 0 ) {
if ( V_22 )
* V_22 = 0 ;
return V_24 ;
}
if ( V_22 )
* V_22 = V_24 ;
return 0 ;
}
static T_2 F_8 ( struct V_16 * V_17 )
{
struct V_18 V_19 ;
T_3 V_31 ;
T_2 V_21 ;
T_2 V_32 ;
int V_24 ;
T_1 V_33 ;
V_32 = V_17 -> V_34 -> V_35 -> V_36 . V_37 ;
V_19 . V_25 = V_38 | V_26 | V_39 ;
V_19 . V_27 = V_40 ;
V_19 . V_28 = 0 ;
V_19 . V_29 = F_9 ( V_32 ) ;
V_19 . V_30 = F_9 ( sizeof( V_17 -> V_41 ) ) ;
V_24 = F_4 ( V_17 , & V_19 , & V_17 -> V_41 , 0 , NULL , 1000 ) ;
if ( V_24 ) {
F_10 ( L_1 ) ;
return 1 ;
}
V_17 -> V_42 = F_11 ( V_17 -> V_41 . V_43 ) ;
V_17 -> V_44 = F_11 ( V_17 -> V_41 . V_45 ) ;
V_17 -> V_46 = F_12 ( V_17 -> V_41 . V_47 ) ;
V_17 -> V_48 = F_12 ( V_17 -> V_41 . V_49 ) ;
V_17 -> V_50 = F_12 ( V_17 -> V_41 . V_51 ) ;
V_17 -> V_52 = F_12 ( V_17 -> V_41 . V_53 ) ;
V_33 = F_12 ( V_17 -> V_41 . V_54 ) ;
if ( V_17 -> V_55 != NULL )
V_21 = V_17 -> V_55 -> V_56 ;
else
V_21 = 0 ;
F_10 ( L_2
L_3
L_4 ,
V_17 -> V_42 , V_17 -> V_44 , V_17 -> V_46 , V_17 -> V_48 ,
V_17 -> V_50 , V_17 -> V_52 , V_21 ) ;
if ( ( V_17 -> V_52 == 0 ) ||
( V_17 -> V_52 > V_57 ) )
V_17 -> V_52 = V_57 ;
if ( V_17 -> V_42 < V_58 ) {
F_10 ( L_5 ,
V_58 ) ;
V_17 -> V_42 = V_58 ;
}
if ( V_17 -> V_42 > V_59 ) {
F_10 ( L_6 ,
V_59 ) ;
V_17 -> V_42 = V_59 ;
}
if ( V_17 -> V_42 != F_11 ( V_17 -> V_41 . V_43 ) ) {
V_19 . V_25 = V_38 | V_60 |
V_39 ;
V_19 . V_27 = V_61 ;
V_19 . V_28 = 0 ;
V_19 . V_29 = F_9 ( V_32 ) ;
if ( V_21 & V_62 ) {
struct V_63 V_64 ;
V_19 . V_30 = 8 ;
V_64 . V_43 = F_13 ( V_17 -> V_42 ) ;
V_64 . V_65 =
F_9 ( V_57 ) ;
V_64 . V_66 = 0 ;
V_24 = F_4 ( V_17 , & V_19 , & V_64 , 0 , NULL ,
1000 ) ;
} else {
T_4 V_43 = F_13 ( V_17 -> V_42 ) ;
V_19 . V_30 = 4 ;
V_24 = F_4 ( V_17 , & V_19 , & V_43 , 0 ,
NULL , 1000 ) ;
}
if ( V_24 )
F_10 ( L_7 ) ;
}
if ( ( V_17 -> V_44 <
( V_67 + V_68 ) ) ||
( V_17 -> V_44 > V_69 ) ) {
F_10 ( L_8 ,
V_69 ) ;
V_17 -> V_44 = V_69 ;
}
V_31 = V_17 -> V_50 ;
if ( ( V_31 < V_70 ) ||
( V_31 != ( ( - V_31 ) & V_31 ) ) || ( V_31 >= V_17 -> V_44 ) ) {
F_10 ( L_9 ) ;
V_17 -> V_50 = V_70 ;
}
V_31 = V_17 -> V_48 ;
if ( ( V_31 < V_70 ) ||
( V_31 != ( ( - V_31 ) & V_31 ) ) || ( V_31 >= V_17 -> V_44 ) ) {
F_10 ( L_10 ) ;
V_17 -> V_48 = V_70 ;
}
if ( V_17 -> V_46 >= V_17 -> V_48 ) {
F_10 ( L_11 ) ;
V_17 -> V_46 = 0 ;
}
V_17 -> V_46 = ( ( V_17 -> V_46 - V_71 ) &
( V_17 -> V_48 - 1 ) ) ;
if ( V_21 & V_72 ) {
V_19 . V_25 = V_38 | V_60 |
V_39 ;
V_19 . V_27 = V_73 ;
V_19 . V_28 = F_9 ( V_74 ) ;
V_19 . V_29 = F_9 ( V_32 ) ;
V_19 . V_30 = 0 ;
V_24 = F_4 ( V_17 , & V_19 , NULL , 0 , NULL , 1000 ) ;
if ( V_24 )
F_10 ( L_12 ) ;
}
if ( V_33 & V_75 ) {
V_19 . V_25 = V_38 | V_60 |
V_39 ;
V_19 . V_27 = V_76 ;
V_19 . V_28 = F_9 ( V_77 ) ;
V_19 . V_29 = F_9 ( V_32 ) ;
V_19 . V_30 = 0 ;
V_24 = F_4 ( V_17 , & V_19 , NULL , 0 , NULL , 1000 ) ;
if ( V_24 )
F_10 ( L_13 ) ;
}
V_17 -> V_78 = V_68 ;
if ( V_21 & V_79 ) {
T_5 V_78 ;
T_1 V_80 = F_12 ( V_17 -> V_81 -> V_82 ) ;
V_19 . V_25 = V_38 | V_26 |
V_39 ;
V_19 . V_27 = V_83 ;
V_19 . V_28 = 0 ;
V_19 . V_29 = F_9 ( V_32 ) ;
V_19 . V_30 = F_9 ( 2 ) ;
V_24 = F_4 ( V_17 , & V_19 , & V_78 , 0 , NULL ,
1000 ) ;
if ( V_24 ) {
F_10 ( L_14 ,
V_68 ) ;
} else {
V_17 -> V_78 = F_12 ( V_78 ) ;
if ( V_80 < V_84 ) {
if ( V_17 -> V_78 > V_80 )
V_17 -> V_78 = V_80 ;
} else {
if ( V_17 -> V_78 >
V_84 )
V_17 -> V_78 =
V_84 ;
}
if ( V_17 -> V_78 < V_68 )
V_17 -> V_78 =
V_68 ;
V_19 . V_25 = V_38 | V_60 |
V_39 ;
V_19 . V_27 = V_85 ;
V_19 . V_28 = 0 ;
V_19 . V_29 = F_9 ( V_32 ) ;
V_19 . V_30 = 2 ;
V_78 = F_9 ( V_17 -> V_78 ) ;
V_24 = F_4 ( V_17 , & V_19 , & V_78 ,
0 , NULL , 1000 ) ;
if ( V_24 )
F_10 ( L_15 ) ;
}
}
if ( V_17 -> V_86 -> V_87 != ( V_17 -> V_78 - V_71 ) )
V_17 -> V_86 -> V_87 = V_17 -> V_78 - V_71 ;
return 0 ;
}
static void
F_14 ( struct V_16 * V_17 , struct V_88 * V_89 )
{
struct V_90 * V_91 ;
T_2 V_92 ;
for ( V_92 = 0 ; V_92 < V_89 -> V_35 -> V_36 . V_93 ; V_92 ++ ) {
V_91 = V_89 -> V_35 -> V_94 + V_92 ;
switch ( V_91 -> V_36 . V_95 & V_96 ) {
case V_97 :
if ( F_15 ( & V_91 -> V_36 ) ) {
if ( V_17 -> V_98 == NULL )
V_17 -> V_98 = V_91 ;
}
break;
case V_99 :
if ( F_15 ( & V_91 -> V_36 ) ) {
if ( V_17 -> V_100 == NULL )
V_17 -> V_100 = V_91 ;
} else {
if ( V_17 -> V_101 == NULL )
V_17 -> V_101 = V_91 ;
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
F_17 ( & V_17 -> V_102 ) ;
if ( V_17 -> V_103 != NULL ) {
F_18 ( V_17 -> V_103 ) ;
V_17 -> V_103 = NULL ;
}
if ( V_17 -> V_104 != NULL ) {
F_18 ( V_17 -> V_104 ) ;
V_17 -> V_104 = NULL ;
}
F_19 ( V_17 ) ;
}
static int F_20 ( struct V_5 * V_6 , struct V_88 * V_89 )
{
struct V_16 * V_17 ;
struct V_105 * V_7 ;
T_2 * V_106 ;
int V_107 ;
int V_108 ;
T_2 V_32 ;
V_17 = F_21 ( sizeof( * V_17 ) , V_109 ) ;
if ( V_17 == NULL )
return - V_110 ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
F_22 ( & V_17 -> V_102 ) ;
F_23 ( & V_17 -> V_111 ) ;
V_17 -> V_86 = V_6 -> V_2 ;
V_6 -> V_20 [ 0 ] = ( unsigned long ) V_17 ;
V_7 = F_24 ( V_89 ) ;
V_106 = V_89 -> V_35 -> V_112 ;
V_107 = V_89 -> V_35 -> V_113 ;
V_17 -> V_14 = V_6 -> V_14 ;
V_17 -> V_89 = V_89 ;
while ( ( V_107 > 0 ) && ( V_106 [ 0 ] > 2 ) && ( V_106 [ 0 ] <= V_107 ) ) {
if ( V_106 [ 1 ] != V_114 )
goto V_115;
switch ( V_106 [ 2 ] ) {
case V_116 :
if ( V_106 [ 0 ] < sizeof( * ( V_17 -> V_117 ) ) )
break;
V_17 -> V_117 =
( const struct V_118 * ) V_106 ;
V_17 -> V_34 = F_25 ( V_6 -> V_14 ,
V_17 -> V_117 -> V_119 ) ;
V_17 -> V_20 = F_25 ( V_6 -> V_14 ,
V_17 -> V_117 -> V_120 ) ;
break;
case V_121 :
if ( V_106 [ 0 ] < sizeof( * ( V_17 -> V_81 ) ) )
break;
V_17 -> V_81 =
( const struct V_122 * ) V_106 ;
V_6 -> V_123 =
F_12 ( V_17 -> V_81 -> V_82 ) ;
if ( V_6 -> V_123 < V_68 )
V_6 -> V_123 = V_68 ;
else if ( V_6 -> V_123 > V_84 )
V_6 -> V_123 = V_84 ;
break;
case V_124 :
if ( V_106 [ 0 ] < sizeof( * ( V_17 -> V_55 ) ) )
break;
V_17 -> V_55 = ( const struct V_125 * ) V_106 ;
break;
default:
break;
}
V_115:
V_108 = V_106 [ 0 ] ;
V_106 += V_108 ;
V_107 -= V_108 ;
}
if ( ( V_17 -> V_34 == NULL ) || ( V_17 -> V_20 == NULL ) ||
( V_17 -> V_81 == NULL ) || ( V_17 -> V_34 != V_89 ) )
goto error;
V_108 = F_26 ( V_7 , V_17 -> V_20 , V_6 ) ;
if ( V_108 )
goto error;
V_32 = V_17 -> V_20 -> V_35 -> V_36 . V_37 ;
V_108 = F_27 ( V_6 -> V_14 , V_32 , 0 ) ;
if ( V_108 )
goto V_126;
if ( F_8 ( V_17 ) )
goto V_126;
V_108 = F_27 ( V_6 -> V_14 , V_32 , 1 ) ;
if ( V_108 )
goto V_126;
F_14 ( V_17 , V_17 -> V_20 ) ;
F_14 ( V_17 , V_17 -> V_34 ) ;
if ( ( V_17 -> V_100 == NULL ) || ( V_17 -> V_101 == NULL ) ||
( V_17 -> V_98 == NULL ) )
goto V_126;
V_6 -> V_2 -> V_127 = & V_128 ;
F_28 ( V_17 -> V_20 , V_6 ) ;
F_28 ( V_17 -> V_34 , V_6 ) ;
F_28 ( V_17 -> V_89 , V_6 ) ;
V_108 = F_29 ( V_6 , V_17 -> V_81 -> V_129 ) ;
if ( V_108 )
goto V_126;
F_30 ( & V_6 -> V_14 -> V_6 , L_16
L_17 ,
V_6 -> V_2 -> V_130 [ 0 ] , V_6 -> V_2 -> V_130 [ 1 ] ,
V_6 -> V_2 -> V_130 [ 2 ] , V_6 -> V_2 -> V_130 [ 3 ] ,
V_6 -> V_2 -> V_130 [ 4 ] , V_6 -> V_2 -> V_130 [ 5 ] ) ;
V_6 -> V_131 = F_31 ( V_6 -> V_14 ,
V_17 -> V_100 -> V_36 . V_132 & V_133 ) ;
V_6 -> V_134 = F_32 ( V_6 -> V_14 ,
V_17 -> V_101 -> V_36 . V_132 & V_133 ) ;
V_6 -> V_135 = V_17 -> V_98 ;
V_6 -> V_136 = V_17 -> V_42 ;
F_33 ( V_6 -> V_2 ) ;
V_17 -> V_137 = V_17 -> V_138 = 0 ;
return 0 ;
V_126:
F_28 ( V_17 -> V_34 , NULL ) ;
F_28 ( V_17 -> V_20 , NULL ) ;
F_34 ( V_7 , V_17 -> V_20 ) ;
error:
F_16 ( (struct V_16 * ) V_6 -> V_20 [ 0 ] ) ;
V_6 -> V_20 [ 0 ] = 0 ;
F_30 ( & V_6 -> V_14 -> V_6 , L_18 ) ;
return - V_110 ;
}
static void F_35 ( struct V_5 * V_6 , struct V_88 * V_89 )
{
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_20 [ 0 ] ;
struct V_105 * V_7 = F_24 ( V_89 ) ;
if ( V_17 == NULL )
return;
if ( V_89 == V_17 -> V_34 && V_17 -> V_20 ) {
F_28 ( V_17 -> V_20 , NULL ) ;
F_34 ( V_7 , V_17 -> V_20 ) ;
V_17 -> V_20 = NULL ;
} else if ( V_89 == V_17 -> V_20 && V_17 -> V_34 ) {
F_28 ( V_17 -> V_34 , NULL ) ;
F_34 ( V_7 , V_17 -> V_34 ) ;
V_17 -> V_34 = NULL ;
}
F_28 ( V_17 -> V_89 , NULL ) ;
F_16 ( V_17 ) ;
}
static void F_36 ( T_2 * V_139 , T_3 V_140 , T_3 V_141 , T_3 V_142 )
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
F_37 ( struct V_16 * V_17 , struct V_143 * V_144 )
{
struct V_143 * V_145 ;
T_3 V_146 ;
T_3 V_147 ;
T_3 V_148 ;
T_1 V_149 = 0 ;
T_2 V_150 = 0 ;
if ( V_144 != NULL )
F_38 ( V_144 , V_17 -> V_103 ) ;
else
V_150 = 1 ;
if ( V_17 -> V_104 != NULL ) {
V_145 = V_17 -> V_104 ;
V_147 = V_17 -> V_151 ;
V_148 = V_17 -> V_152 ;
V_149 = V_17 -> V_153 ;
} else {
V_145 = F_39 ( ( V_17 -> V_44 + 1 ) , V_154 ) ;
if ( V_145 == NULL ) {
if ( V_144 != NULL ) {
F_18 ( V_144 ) ;
V_17 -> V_86 -> V_155 . V_156 ++ ;
}
goto V_157;
}
V_147 = F_40 ( sizeof( struct V_158 ) ,
V_17 -> V_50 ) +
sizeof( struct V_159 ) +
( V_17 -> V_52 + 1 ) *
sizeof( struct V_160 ) ;
V_148 = V_147 ;
V_147 = F_40 ( V_147 , V_17 -> V_48 ) + V_17 -> V_46 ;
F_36 ( V_145 -> V_20 , 0 , V_147 , V_147 ) ;
V_149 = 0 ;
V_17 -> V_153 = 0 ;
}
for (; V_149 < V_17 -> V_52 ; V_149 ++ ) {
if ( V_147 >= V_17 -> V_44 ) {
V_150 = 1 ;
break;
}
V_146 = V_17 -> V_44 - V_147 ;
if ( V_144 == NULL ) {
V_144 = V_17 -> V_103 ;
V_17 -> V_103 = NULL ;
if ( V_144 == NULL )
break;
}
if ( V_144 -> V_107 > V_146 ) {
if ( V_149 == 0 ) {
F_18 ( V_144 ) ;
V_144 = NULL ;
V_17 -> V_86 -> V_155 . V_156 ++ ;
} else {
if ( V_17 -> V_103 != NULL ) {
F_18 ( V_17 -> V_103 ) ;
V_17 -> V_86 -> V_155 . V_156 ++ ;
}
V_17 -> V_103 = V_144 ;
V_144 = NULL ;
V_150 = 1 ;
}
break;
}
memcpy ( ( ( T_2 * ) V_145 -> V_20 ) + V_147 , V_144 -> V_20 , V_144 -> V_107 ) ;
V_17 -> V_161 . V_162 [ V_149 ] . V_163 = F_9 ( V_144 -> V_107 ) ;
V_17 -> V_161 . V_162 [ V_149 ] . V_164 = F_9 ( V_147 ) ;
V_147 += V_144 -> V_107 ;
V_148 = V_147 ;
V_147 = F_40 ( V_147 , V_17 -> V_48 ) + V_17 -> V_46 ;
F_36 ( V_145 -> V_20 , V_148 , V_147 ,
V_17 -> V_44 ) ;
F_18 ( V_144 ) ;
V_144 = NULL ;
}
if ( V_144 != NULL ) {
F_18 ( V_144 ) ;
V_144 = NULL ;
V_17 -> V_86 -> V_155 . V_156 ++ ;
}
V_17 -> V_153 = V_149 ;
if ( V_149 == 0 ) {
V_17 -> V_104 = V_145 ;
V_17 -> V_151 = V_147 ;
V_17 -> V_152 = V_148 ;
goto V_157;
} else if ( ( V_149 < V_17 -> V_52 ) && ( V_150 == 0 ) ) {
V_17 -> V_104 = V_145 ;
V_17 -> V_151 = V_147 ;
V_17 -> V_152 = V_148 ;
if ( V_149 < V_165 )
V_17 -> V_166 = 2 ;
goto V_157;
} else {
}
if ( V_148 > V_17 -> V_44 )
V_148 = V_17 -> V_44 ;
V_147 = V_148 ;
if ( V_147 > V_167 )
V_147 = V_17 -> V_44 ;
F_36 ( V_145 -> V_20 , V_148 , V_147 , V_17 -> V_44 ) ;
V_148 = V_147 ;
if ( ( ( V_148 < V_17 -> V_44 ) && ( ( V_148 %
F_12 ( V_17 -> V_101 -> V_36 . V_168 ) ) == 0 ) ) ||
( ( ( V_148 == V_17 -> V_44 ) && ( ( V_17 -> V_44 %
F_12 ( V_17 -> V_101 -> V_36 . V_168 ) ) == 0 ) ) &&
( V_17 -> V_44 < F_11 ( V_17 -> V_41 . V_45 ) ) ) ) {
* ( ( ( T_2 * ) V_145 -> V_20 ) + V_148 ) = 0 ;
V_148 ++ ;
}
for (; V_149 <= V_57 ; V_149 ++ ) {
V_17 -> V_161 . V_162 [ V_149 ] . V_163 = 0 ;
V_17 -> V_161 . V_162 [ V_149 ] . V_164 = 0 ;
}
V_17 -> V_161 . V_169 . V_170 = F_13 ( V_171 ) ;
V_17 -> V_161 . V_169 . V_172 =
F_9 ( sizeof( V_17 -> V_161 . V_169 ) ) ;
V_17 -> V_161 . V_169 . V_173 = F_9 ( V_17 -> V_174 ) ;
V_17 -> V_161 . V_169 . V_175 = F_9 ( V_148 ) ;
V_17 -> V_161 . V_169 . V_176 = F_40 ( sizeof( struct V_158 ) ,
V_17 -> V_50 ) ;
memcpy ( V_145 -> V_20 , & ( V_17 -> V_161 . V_169 ) , sizeof( V_17 -> V_161 . V_169 ) ) ;
V_17 -> V_174 ++ ;
V_17 -> V_161 . V_177 . V_170 =
F_13 ( V_178 ) ;
V_146 = sizeof( V_17 -> V_161 . V_177 ) + ( ( V_17 -> V_153 + 1 ) *
sizeof( struct V_160 ) ) ;
V_17 -> V_161 . V_177 . V_30 = F_9 ( V_146 ) ;
V_17 -> V_161 . V_177 . V_179 = 0 ;
memcpy ( ( ( T_2 * ) V_145 -> V_20 ) + V_17 -> V_161 . V_169 . V_176 ,
& ( V_17 -> V_161 . V_177 ) ,
sizeof( V_17 -> V_161 . V_177 ) ) ;
memcpy ( ( ( T_2 * ) V_145 -> V_20 ) + V_17 -> V_161 . V_169 . V_176 +
sizeof( V_17 -> V_161 . V_177 ) ,
& ( V_17 -> V_161 . V_162 ) ,
( V_17 -> V_153 + 1 ) *
sizeof( struct V_160 ) ) ;
F_41 ( V_145 , V_148 ) ;
V_17 -> V_104 = NULL ;
return V_145 ;
V_157:
return NULL ;
}
static void F_42 ( struct V_16 * V_17 )
{
if ( F_43 ( & V_17 -> V_102 ) == 0 ) {
V_17 -> V_102 . V_180 = & V_181 ;
V_17 -> V_102 . V_20 = ( unsigned long ) V_17 ;
V_17 -> V_102 . V_182 = V_183 + ( ( V_184 + 999 ) / 1000 ) ;
F_44 ( & V_17 -> V_102 ) ;
}
}
static void V_181 ( unsigned long V_185 )
{
struct V_16 * V_17 = (struct V_16 * ) V_185 ;
T_2 V_186 ;
F_45 ( & V_17 -> V_111 ) ;
if ( V_17 -> V_166 != 0 ) {
V_17 -> V_166 -- ;
V_186 = 1 ;
} else {
V_186 = 0 ;
}
F_46 ( & V_17 -> V_111 ) ;
if ( V_186 ) {
F_45 ( & V_17 -> V_111 ) ;
F_42 ( V_17 ) ;
F_46 ( & V_17 -> V_111 ) ;
} else if ( V_17 -> V_86 != NULL ) {
F_47 ( NULL , V_17 -> V_86 ) ;
}
}
static struct V_143 *
F_48 ( struct V_5 * V_6 , struct V_143 * V_144 , T_6 V_21 )
{
struct V_143 * V_145 ;
struct V_16 * V_17 = (struct V_16 * ) V_6 -> V_20 [ 0 ] ;
T_2 V_187 = 0 ;
if ( V_17 == NULL )
goto error;
F_45 ( & V_17 -> V_111 ) ;
V_145 = F_37 ( V_17 , V_144 ) ;
if ( V_17 -> V_104 != NULL )
V_187 = 1 ;
if ( V_187 )
F_42 ( V_17 ) ;
if ( V_145 )
V_6 -> V_2 -> V_155 . V_188 += V_17 -> V_153 ;
F_46 ( & V_17 -> V_111 ) ;
return V_145 ;
error:
if ( V_144 != NULL )
F_18 ( V_144 ) ;
return NULL ;
}
static int F_49 ( struct V_5 * V_6 , struct V_143 * V_189 )
{
struct V_143 * V_144 ;
struct V_16 * V_17 ;
int V_190 ;
int V_22 ;
int V_108 ;
int V_191 ;
int V_192 ;
int V_147 ;
V_17 = (struct V_16 * ) V_6 -> V_20 [ 0 ] ;
if ( V_17 == NULL )
goto error;
V_22 = V_189 -> V_107 ;
V_190 = V_59 ;
if ( V_22 < ( sizeof( V_17 -> V_193 . V_169 ) + sizeof( V_17 -> V_193 . V_177 ) ) ) {
F_10 ( L_19 ) ;
goto error;
}
memcpy ( & ( V_17 -> V_193 . V_169 ) , ( ( T_2 * ) V_189 -> V_20 ) ,
sizeof( V_17 -> V_193 . V_169 ) ) ;
if ( F_11 ( V_17 -> V_193 . V_169 . V_170 ) !=
V_171 ) {
F_10 ( L_20 ,
F_11 ( V_17 -> V_193 . V_169 . V_170 ) ) ;
goto error;
}
V_108 = F_12 ( V_17 -> V_193 . V_169 . V_175 ) ;
if ( V_108 > V_190 ) {
F_10 ( L_21 , V_108 , V_190 ) ;
goto error;
}
V_108 = F_12 ( V_17 -> V_193 . V_169 . V_176 ) ;
if ( ( V_108 + sizeof( V_17 -> V_193 . V_177 ) ) > V_22 ) {
F_10 ( L_22 ) ;
goto error;
}
memcpy ( & ( V_17 -> V_193 . V_177 ) , ( ( T_2 * ) V_189 -> V_20 ) + V_108 ,
sizeof( V_17 -> V_193 . V_177 ) ) ;
if ( F_11 ( V_17 -> V_193 . V_177 . V_170 ) !=
V_178 ) {
F_10 ( L_23 ,
F_11 ( V_17 -> V_193 . V_177 . V_170 ) ) ;
goto error;
}
if ( F_12 ( V_17 -> V_193 . V_177 . V_30 ) <
V_194 ) {
F_10 ( L_24 ,
F_11 ( V_17 -> V_193 . V_177 . V_170 ) ) ;
goto error;
}
V_191 = ( ( F_12 ( V_17 -> V_193 . V_177 . V_30 ) -
sizeof( struct V_159 ) ) /
sizeof( struct V_160 ) ) ;
V_191 -- ;
F_10 ( L_25 , V_191 ) ;
V_108 += sizeof( V_17 -> V_193 . V_177 ) ;
if ( ( V_108 + V_191 * ( sizeof( struct V_160 ) ) ) > V_22 ) {
F_10 ( L_26 , V_191 ) ;
goto error;
}
if ( V_191 > V_57 ) {
F_10 ( L_27 ,
V_191 , V_57 ) ;
V_191 = V_57 ;
}
memcpy ( & ( V_17 -> V_193 . V_162 ) , ( ( T_2 * ) V_189 -> V_20 ) + V_108 ,
V_191 * ( sizeof( struct V_160 ) ) ) ;
for ( V_192 = 0 ; V_192 < V_191 ; V_192 ++ ) {
V_147 = F_12 ( V_17 -> V_193 . V_162 [ V_192 ] . V_164 ) ;
V_108 = F_12 ( V_17 -> V_193 . V_162 [ V_192 ] . V_163 ) ;
if ( ( V_147 == 0 ) || ( V_108 == 0 ) ) {
if ( ! V_192 )
goto error;
break;
}
if ( ( ( V_147 + V_108 ) > V_22 ) ||
( V_108 > V_84 ) || ( V_108 < V_71 ) ) {
F_10 ( L_28
L_29 ,
V_192 , V_147 , V_108 , V_189 ) ;
if ( ! V_192 )
goto error;
break;
} else {
V_144 = F_50 ( V_189 , V_154 ) ;
if ( ! V_144 )
goto error;
V_144 -> V_107 = V_108 ;
V_144 -> V_20 = ( ( T_2 * ) V_189 -> V_20 ) + V_147 ;
F_51 ( V_144 , V_108 ) ;
F_52 ( V_6 , V_144 ) ;
}
}
return 1 ;
error:
return 0 ;
}
static void
F_53 ( struct V_16 * V_17 ,
struct V_195 * V_20 )
{
T_7 V_138 = F_11 ( V_20 -> V_196 ) ;
T_7 V_137 = F_11 ( V_20 -> V_197 ) ;
if ( ( V_137 != V_17 -> V_137 ) || ( V_138 != V_17 -> V_138 ) ) {
V_17 -> V_137 = V_137 ;
V_17 -> V_138 = V_138 ;
if ( ( V_137 > 1000000 ) && ( V_138 > 1000000 ) ) {
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
static void F_55 ( struct V_5 * V_6 , struct V_198 * V_198 )
{
struct V_16 * V_17 ;
struct V_18 * V_199 ;
V_17 = (struct V_16 * ) V_6 -> V_20 [ 0 ] ;
if ( V_198 -> V_200 < sizeof( * V_199 ) )
return;
if ( F_56 ( V_201 , & V_6 -> V_21 ) ) {
F_53 ( V_17 ,
(struct V_195 * ) V_198 -> V_202 ) ;
return;
}
V_199 = V_198 -> V_202 ;
switch ( V_199 -> V_27 ) {
case V_203 :
V_17 -> V_204 = V_199 -> V_28 ;
F_54 (KERN_INFO KBUILD_MODNAME L_34
L_35 ,
ctx->netdev->name, ctx->connected ? L_36 : L_37 ) ;
if ( V_17 -> V_204 )
F_57 ( V_6 -> V_2 ) ;
else {
F_33 ( V_6 -> V_2 ) ;
V_17 -> V_137 = V_17 -> V_138 = 0 ;
}
break;
case V_205 :
if ( V_198 -> V_200 < ( sizeof( * V_199 ) +
sizeof( struct V_195 ) ) )
F_58 ( V_201 , & V_6 -> V_21 ) ;
else
F_53 ( V_17 ,
(struct V_195 * ) & V_199 [ 1 ] ) ;
break;
default:
F_59 ( & V_6 -> V_14 -> V_6 , L_38
L_39 , V_199 -> V_27 ) ;
break;
}
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_6 -> V_20 [ 0 ] ;
if ( V_17 == NULL )
return 1 ;
return ! V_17 -> V_204 ;
}
static int
F_61 ( struct V_88 * V_14 , const struct V_206 * V_207 )
{
return F_62 ( V_14 , V_207 ) ;
}
static void F_63 ( struct V_88 * V_89 )
{
struct V_5 * V_6 = F_64 ( V_89 ) ;
if ( V_6 == NULL )
return;
F_65 ( V_89 ) ;
}
static int F_66 ( struct V_5 * V_6 , int V_135 )
{
V_6 -> V_89 -> V_208 = V_135 ;
return 0 ;
}
static int T_8 F_67 ( void )
{
F_54 (KERN_INFO KBUILD_MODNAME L_40 DRIVER_VERSION L_41 ) ;
return F_68 ( & V_209 ) ;
}
static void T_9 F_69 ( void )
{
F_70 ( & V_209 ) ;
}
