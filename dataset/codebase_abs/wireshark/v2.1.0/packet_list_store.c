T_1
F_1 ( void )
{
static T_1 V_1 = 0 ;
if( V_1 == 0 ) {
static const T_2 V_2 = {
sizeof( V_3 ) ,
NULL ,
NULL ,
( V_4 ) V_5 ,
NULL ,
NULL ,
sizeof( V_6 ) ,
0 ,
( V_7 ) V_8 ,
NULL
} ;
static const T_3 V_9 = {
( V_10 ) V_11 ,
NULL ,
NULL
} ;
static const T_3 V_12 = {
( V_10 ) V_13 ,
NULL ,
NULL
} ;
V_1 = F_2 ( V_14 ,
L_1 ,
& V_2 ,
( V_15 ) 0 ) ;
F_3 ( V_1 ,
V_16 ,
& V_9 ) ;
F_3 ( V_1 ,
V_17 ,
& V_12 ) ;
}
return V_1 ;
}
static void
V_13 ( T_4 * V_18 )
{
V_18 -> V_19 = V_20 ;
V_18 -> V_21 = V_22 ;
V_18 -> V_23 = V_24 ;
V_18 -> V_25 =
V_26 ;
V_18 -> V_27 =
V_28 ;
}
static void
V_5 ( V_3 * V_29 )
{
T_5 * V_30 ;
V_31 = ( T_5 * ) F_4 ( V_29 ) ;
V_30 = ( T_5 * ) V_29 ;
V_30 -> V_32 = V_33 ;
#if ! F_5 ( 3 , 0 , 0 )
F_6 (
L_2
L_3
L_4
L_5
L_6
L_7 ) ;
#endif
}
static void
V_11 ( T_6 * V_18 )
{
V_18 -> V_34 = V_35 ;
V_18 -> V_36 = V_37 ;
V_18 -> V_38 = V_39 ;
V_18 -> V_40 = V_41 ;
V_18 -> V_42 = V_43 ;
V_18 -> V_44 = V_45 ;
V_18 -> V_46 = V_47 ;
V_18 -> V_48 = V_49 ;
V_18 -> V_50 = V_51 ;
V_18 -> V_52 = V_53 ;
V_18 -> V_54 = V_55 ;
V_18 -> V_56 = V_57 ;
}
static void
V_8 ( V_6 * V_58 )
{
T_7 V_59 , V_60 ;
V_58 -> V_61 = F_7 () ;
V_58 -> V_62 = V_63 . V_64 . V_65 ;
V_58 -> V_66 = F_8 () ;
V_58 -> V_67 = F_8 () ;
V_58 -> V_68 = FALSE ;
V_58 -> V_69 = 0 ;
V_58 -> V_70 = V_71 ;
V_58 -> V_72 = F_9 ( int , V_58 -> V_62 ) ;
for ( V_59 = 0 , V_60 = 0 ; V_59 < V_58 -> V_62 ; V_59 ++ ) {
if ( ! F_10 ( & V_63 . V_64 , V_59 ) ) {
V_58 -> V_72 [ V_59 ] = V_60 ;
V_60 ++ ;
} else
V_58 -> V_72 [ V_59 ] = - 1 ;
}
V_58 -> V_73 = V_60 ;
#ifdef F_11
V_58 -> V_74 = 0 ;
#endif
}
static void
V_33 ( T_8 * V_75 )
{
(* V_31 -> V_32 ) ( V_75 ) ;
}
static T_9
V_35 ( T_10 * V_76 )
{
F_12 ( F_13 ( V_76 ) ,
( T_9 ) 0 ) ;
return ( T_9 ) ( V_77 | V_78 ) ;
}
static T_7
V_37 ( T_10 * V_76 )
{
V_6 * V_58 ;
F_12 ( F_13 ( V_76 ) , 0 ) ;
V_58 = ( V_6 * ) V_76 ;
return V_58 -> V_62 + 1 ;
}
static T_1
V_39 ( T_10 * V_76 , T_7 V_79 )
{
V_6 * V_58 ;
F_12 ( F_13 ( V_76 ) , V_80 ) ;
V_58 = ( V_6 * ) V_76 ;
F_12 ( V_79 >= 0 && V_79 < V_58 -> V_62 + 1 , V_80 ) ;
if ( V_79 >= 0 && V_79 < V_58 -> V_62 )
return V_81 ;
else if ( V_79 == V_58 -> V_62 )
return V_82 ;
else
return V_80 ;
}
static T_11
V_41 ( T_10 * V_76 , T_12 * V_83 ,
T_13 * V_84 )
{
T_7 * V_85 , V_86 ;
F_14 ( F_13 ( V_76 ) ) ;
F_14 ( V_84 != NULL ) ;
V_85 = F_15 ( V_84 ) ;
V_86 = F_16 ( V_84 ) ;
F_14 ( V_86 == 1 ) ;
return V_55 ( V_76 , V_83 , NULL , V_85 [ 0 ] ) ;
}
static T_13 *
V_43 ( T_10 * V_76 , T_12 * V_83 )
{
T_13 * V_84 ;
T_14 * V_87 ;
V_6 * V_58 ;
F_12 ( F_13 ( V_76 ) , NULL ) ;
V_58 = ( V_6 * ) V_76 ;
F_12 ( V_83 != NULL , NULL ) ;
F_12 ( V_83 -> V_61 == V_58 -> V_61 , NULL ) ;
F_12 ( V_83 -> V_88 != NULL , NULL ) ;
V_87 = ( T_14 * ) V_83 -> V_88 ;
V_84 = F_17 () ;
F_18 ( V_84 , V_87 -> V_89 ) ;
return V_84 ;
}
static void
V_45 ( T_10 * V_76 , T_12 * V_83 , T_7 V_90 ,
T_15 * V_91 )
{
T_14 * V_87 ;
V_6 * V_58 ;
F_19 ( F_13 ( V_76 ) ) ;
V_58 = ( V_6 * ) V_76 ;
F_19 ( V_83 != NULL ) ;
F_19 ( V_83 -> V_61 == V_58 -> V_61 ) ;
F_19 ( V_83 -> V_88 != NULL ) ;
F_19 ( V_90 >= 0 && V_90 < V_58 -> V_62 + 1 ) ;
V_87 = ( T_14 * ) V_83 -> V_88 ;
#ifdef F_20
F_19 ( F_21 ( V_58 -> V_66 , V_87 -> V_92 ) ) ;
#endif
F_19 ( F_21 ( V_58 -> V_67 , V_87 -> V_89 ) ) ;
if ( V_90 >= 0 && V_90 < V_58 -> V_62 ) {
int V_93 ;
F_22 ( V_91 , V_81 ) ;
if ( V_87 -> V_94 == NULL || ! V_87 -> V_95 )
F_23 ( V_58 , V_87 , ! V_87 -> V_95 ) ;
V_93 = V_58 -> V_72 [ V_90 ] ;
if ( V_93 == - 1 ) {
F_24 ( V_87 -> V_96 , & V_63 . V_64 , V_90 , FALSE ) ;
F_25 ( V_91 , V_63 . V_64 . V_97 [ V_90 ] . V_98 ) ;
} else {
F_19 ( V_87 -> V_94 ) ;
F_25 ( V_91 , V_87 -> V_94 [ V_93 ] ) ;
}
} else if ( V_90 == V_58 -> V_62 ) {
F_22 ( V_91 , V_82 ) ;
F_26 ( V_91 , V_87 -> V_96 ) ;
}
}
static T_14 *
F_27 ( V_6 * V_58 , T_14 * V_87 )
{
T_14 * V_99 ;
T_7 V_100 ;
F_14 ( V_87 -> V_89 >= 0 ) ;
V_100 = V_87 -> V_89 + 1 ;
if( ! F_21 ( V_58 -> V_67 , V_100 ) )
return NULL ;
V_99 = F_28 ( V_58 -> V_67 , V_100 ) ;
F_14 ( V_99 -> V_89 == ( V_87 -> V_89 + 1 ) ) ;
#ifdef F_20
F_14 ( V_99 -> V_92 >= ( V_87 -> V_92 + 1 ) ) ;
#endif
return V_99 ;
}
static T_11
V_47 ( T_10 * V_76 , T_12 * V_83 )
{
T_14 * V_87 , * V_99 ;
V_6 * V_58 ;
F_12 ( F_13 ( V_76 ) , FALSE ) ;
V_58 = ( V_6 * ) V_76 ;
if( V_83 == NULL )
return FALSE ;
F_12 ( V_83 -> V_61 == V_58 -> V_61 , FALSE ) ;
F_12 ( V_83 -> V_88 , FALSE ) ;
V_87 = ( T_14 * ) V_83 -> V_88 ;
V_99 = F_27 ( V_58 , V_87 ) ;
if ( ! V_99 )
return FALSE ;
V_83 -> V_88 = V_99 ;
return TRUE ;
}
static T_11
V_49 ( T_10 * V_76 , T_12 * V_83 ,
T_12 * V_101 )
{
return V_55 ( V_76 , V_83 , V_101 , 0 ) ;
}
static T_11
V_51 ( T_10 * V_76 V_102 , T_12 * V_83 V_102 )
{
return FALSE ;
}
static T_7
V_53 ( T_10 * V_76 , T_12 * V_83 )
{
V_6 * V_58 ;
F_12 ( F_13 ( V_76 ) , 0 ) ;
V_58 = ( V_6 * ) V_76 ;
if( ! V_83 ) {
return F_29 ( V_58 -> V_67 ) ;
}
else {
F_12 ( V_83 -> V_61 == V_58 -> V_61 , 0 ) ;
F_12 ( V_83 -> V_88 , 0 ) ;
return 0 ;
}
}
static T_11
V_55 ( T_10 * V_76 , T_12 * V_83 ,
T_12 * V_101 , T_7 V_103 )
{
T_14 * V_87 ;
V_6 * V_58 ;
F_12 ( F_13 ( V_76 ) , FALSE ) ;
V_58 = ( V_6 * ) V_76 ;
if( V_101 ) {
F_12 ( V_101 -> V_61 == V_58 -> V_61 , FALSE ) ;
F_12 ( V_101 -> V_88 , FALSE ) ;
return FALSE ;
}
if( ! F_21 ( V_58 -> V_67 , V_103 ) )
return FALSE ;
V_87 = F_28 ( V_58 -> V_67 , V_103 ) ;
F_14 ( V_87 -> V_89 == V_103 ) ;
V_83 -> V_61 = V_58 -> V_61 ;
V_83 -> V_88 = V_87 ;
return TRUE ;
}
static T_11
V_57 ( T_10 * V_76 V_102 , T_12 * V_83 V_102 ,
T_12 * T_16 V_102 )
{
return FALSE ;
}
V_6 *
F_30 ( void )
{
V_6 * V_104 ;
V_104 = ( V_6 * ) F_31 ( V_105 , NULL ) ;
F_14 ( V_104 != NULL ) ;
return V_104 ;
}
void
F_32 ( V_6 * V_58 )
{
F_19 ( V_58 != NULL ) ;
F_19 ( F_13 ( V_58 ) ) ;
if( V_58 -> V_66 )
F_33 ( V_58 -> V_66 , TRUE ) ;
if( V_58 -> V_67 )
F_33 ( V_58 -> V_67 , TRUE ) ;
V_58 -> V_66 = F_8 () ;
V_58 -> V_67 = F_8 () ;
V_58 -> V_68 = FALSE ;
V_58 -> V_61 = F_7 () ;
F_34 ( V_58 -> V_106 ) ;
#ifdef F_11
F_35 ( L_8 , V_58 -> V_74 ) ;
V_58 -> V_74 = 0 ;
#endif
}
T_7
F_36 ( V_6 * V_58 , T_17 * V_96 )
{
T_14 * V_107 ;
F_12 ( F_13 ( V_58 ) , - 1 ) ;
V_107 = F_37 ( F_38 () , T_14 ) ;
V_107 -> V_95 = FALSE ;
V_107 -> V_108 = NULL ;
V_107 -> V_94 = NULL ;
V_107 -> V_96 = V_96 ;
#ifdef F_20
V_107 -> V_92 = F_29 ( V_58 -> V_66 ) ;
#endif
if ( V_96 -> V_109 . V_110 || V_96 -> V_109 . V_111 ) {
V_107 -> V_89 = F_29 ( V_58 -> V_67 ) ;
F_39 ( V_58 -> V_67 , V_107 ) ;
}
else
V_107 -> V_89 = - 1 ;
F_39 ( V_58 -> V_66 , V_107 ) ;
V_58 -> V_68 = FALSE ;
if ( F_40 ( F_41 ( V_58 -> V_112 ) ) && V_107 -> V_89 != - 1 ) {
T_12 V_83 ;
T_13 * V_84 ;
V_84 = F_17 () ;
F_18 ( V_84 , V_107 -> V_89 ) ;
V_83 . V_61 = V_58 -> V_61 ;
V_83 . V_88 = V_107 ;
F_42 ( F_43 ( V_58 ) , V_84 , & V_83 ) ;
F_44 ( V_84 ) ;
}
return V_107 -> V_89 ;
}
static void
F_45 ( V_6 * V_58 , T_14 * V_87 , T_7 V_113 , T_18 * V_64 )
{
T_19 * V_114 ;
T_20 V_108 ;
int V_115 ;
T_21 * V_116 ;
V_115 = V_58 -> V_72 [ V_113 ] ;
if ( V_115 == - 1 || V_87 -> V_94 [ V_115 ] != NULL )
return;
V_116 = & V_63 . V_64 . V_97 [ V_113 ] ;
switch ( V_116 -> V_117 ) {
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
if ( V_116 -> V_98 && V_116 -> V_98 != V_116 -> V_125 ) {
V_108 = strlen ( V_116 -> V_98 ) ;
if ( V_108 > V_126 )
V_108 = V_126 ;
V_87 -> V_94 [ V_115 ] = ( T_19 * ) V_116 -> V_98 ;
V_87 -> V_108 [ V_115 ] = ( V_127 ) V_108 ;
#ifdef F_11
++ V_58 -> V_74 ;
#endif
break;
}
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
default:
if( V_116 -> V_98 ) {
V_108 = strlen ( V_116 -> V_98 ) ;
if ( V_108 > V_126 )
V_108 = V_126 ;
V_87 -> V_108 [ V_115 ] = ( V_127 ) V_108 ;
}
if ( ! V_87 -> V_108 [ V_115 ] ) {
V_87 -> V_94 [ V_115 ] = L_9 ;
#ifdef F_11
++ V_58 -> V_74 ;
#endif
break;
}
if( ! V_58 -> V_106 )
V_58 -> V_106 = F_46 ( V_146 ) ;
if ( ! F_47 ( V_113 ) && V_64 -> V_147 . V_148 [ V_113 ] ) {
V_114 = F_48 ( V_58 -> V_106 , ( const T_19 * ) V_64 -> V_147 . V_148 [ V_113 ] ) ;
} else {
V_114 = F_48 ( V_58 -> V_106 , ( const T_19 * ) V_116 -> V_98 ) ;
}
V_87 -> V_94 [ V_115 ] = V_114 ;
break;
}
}
static T_11
V_20 ( T_22 * V_149 ,
T_7 * V_150 ,
T_23 * V_151 )
{
V_6 * V_58 ;
F_12 ( V_149 != NULL , FALSE ) ;
F_12 ( F_13 ( V_149 ) , FALSE ) ;
V_58 = ( V_6 * ) V_149 ;
if( V_150 )
* V_150 = V_58 -> V_69 ;
if( V_151 )
* V_151 = V_58 -> V_70 ;
return TRUE ;
}
static T_11
F_49 ( V_6 * V_58 , T_7 V_150 )
{
if ( V_58 -> V_68 || F_10 ( & V_63 . V_64 , V_150 ) )
return TRUE ;
else
return FALSE ;
}
static T_11
F_50 ( V_6 * V_58 )
{
T_14 * V_87 ;
int V_152 ;
int V_153 ;
T_11 V_154 ;
T_24 V_155 ;
float V_156 ;
T_25 * V_157 = NULL ;
T_19 V_158 [ 100 ] ;
T_7 V_159 ;
T_7 V_160 ;
T_7 V_161 = 100 ;
F_14 ( V_58 -> V_68 == FALSE ) ;
V_159 = F_29 ( V_58 -> V_66 ) ;
V_152 = 0 ;
V_153 = V_159 / V_161 ;
V_156 = 0.0f ;
V_154 = FALSE ;
F_51 ( & V_155 ) ;
F_52 () ;
for ( V_160 = 0 ; V_160 < V_159 ; ++ V_160 ) {
V_87 = F_28 ( V_58 -> V_66 , V_160 ) ;
F_23 ( V_58 , V_87 , FALSE ) ;
if ( V_157 == NULL )
V_157 = F_53 ( F_54 ( V_58 -> V_112 ) ,
L_10 , L_11 ,
TRUE , & V_154 ,
& V_155 , V_156 ) ;
if ( V_160 >= V_152 ) {
F_14 ( V_159 > 0 ) ;
V_156 = ( V_162 ) V_160 / V_159 ;
if ( V_157 != NULL ) {
F_55 ( V_158 , sizeof( V_158 ) ,
L_12 , V_160 + 1 , V_159 ) ;
F_56 ( V_157 , V_156 , V_158 ) ;
}
V_152 += V_153 ;
}
if ( V_154 ) {
break;
}
}
if ( V_157 != NULL )
F_57 ( V_157 ) ;
if ( V_154 ) {
return FALSE ;
}
V_58 -> V_68 = TRUE ;
return TRUE ;
}
T_11
F_58 ( V_6 * V_58 , T_7 V_150 )
{
if ( ! F_49 ( V_58 , V_150 ) ) {
return F_50 ( V_58 ) ;
}
return TRUE ;
}
static void
V_22 ( T_22 * V_149 ,
T_7 V_150 ,
T_23 V_151 )
{
V_6 * V_58 ;
F_19 ( V_149 != NULL ) ;
F_19 ( F_13 ( V_149 ) ) ;
V_58 = ( V_6 * ) V_149 ;
if( V_58 -> V_69 == V_150 &&
V_58 -> V_70 == V_151 )
return;
V_58 -> V_69 = V_150 ;
V_58 -> V_70 = V_151 ;
if( F_29 ( V_58 -> V_66 ) == 0 )
return;
F_59 ( V_58 ) ;
F_60 ( V_149 ) ;
}
static void
V_24 ( T_22 * V_149 V_102 ,
T_7 V_150 V_102 ,
T_26 T_27 V_102 ,
T_28 V_88 V_102 ,
T_29 T_30 V_102 )
{
F_35 ( V_163 L_13 ) ;
}
static void
V_26 ( T_22 * V_149 V_102 ,
T_26 T_27 V_102 ,
T_28 V_88 V_102 ,
T_29 T_30 V_102 )
{
F_35 ( V_163 L_13 ) ;
}
static T_11
V_28 ( T_22 * V_149 V_102 )
{
return FALSE ;
}
static T_7
F_61 ( T_7 V_69 , T_7 V_164 , T_14 * V_165 , T_14 * V_166 )
{
T_31 * V_167 ;
V_167 = F_62 ( V_63 . V_64 . V_97 [ V_69 ] . V_168 ) ;
if ( V_167 == NULL ) {
return F_63 ( V_63 . V_169 , V_165 -> V_96 , V_166 -> V_96 , V_170 ) ;
} else if ( ( V_167 -> V_171 == NULL ) &&
( ( ( F_64 ( V_167 -> type ) || F_65 ( V_167 -> type ) ) &&
( ( V_167 -> V_172 == V_173 ) || ( V_167 -> V_172 == V_174 ) ||
( V_167 -> V_172 == V_175 ) ) ) ||
( V_167 -> type == V_176 ) || ( V_167 -> type == V_177 ) ||
( V_167 -> type == V_178 ) || ( V_167 -> type == V_179 ) ||
( V_167 -> type == V_180 ) ) )
{
double V_181 = F_66 ( V_165 -> V_94 [ V_164 ] , NULL ) ;
double V_182 = F_66 ( V_166 -> V_94 [ V_164 ] , NULL ) ;
if ( V_181 < V_182 )
return - 1 ;
else if ( V_181 > V_182 )
return 1 ;
else
return 0 ;
}
return strcmp ( V_165 -> V_94 [ V_164 ] , V_166 -> V_94 [ V_164 ] ) ;
}
static T_7
F_67 ( T_7 V_69 , T_7 V_164 , T_14 * V_165 , T_14 * V_166 )
{
F_14 ( V_165 -> V_94 ) ;
F_14 ( V_166 -> V_94 ) ;
F_14 ( V_165 -> V_94 [ V_164 ] ) ;
F_14 ( V_166 -> V_94 [ V_164 ] ) ;
if( V_165 -> V_94 [ V_164 ] == V_166 -> V_94 [ V_164 ] )
return 0 ;
if ( V_63 . V_64 . V_97 [ V_69 ] . V_117 == V_183 )
return F_61 ( V_69 , V_164 , V_165 , V_166 ) ;
return strcmp ( V_165 -> V_94 [ V_164 ] , V_166 -> V_94 [ V_164 ] ) ;
}
static T_7
F_68 ( T_7 V_69 , T_7 V_164 , T_14 * V_165 , T_14 * V_166 )
{
T_7 V_184 ;
if ( V_164 == - 1 )
return F_63 ( V_63 . V_169 , V_165 -> V_96 , V_166 -> V_96 , V_63 . V_64 . V_97 [ V_69 ] . V_117 ) ;
V_184 = F_67 ( V_69 , V_164 , V_165 , V_166 ) ;
if ( V_184 == 0 )
V_184 = F_63 ( V_63 . V_169 , V_165 -> V_96 , V_166 -> V_96 , V_170 ) ;
return V_184 ;
}
static T_7
F_69 ( T_14 * * V_165 , T_14 * * V_166 ,
V_6 * V_58 )
{
T_7 V_184 ;
T_7 V_69 = V_58 -> V_69 ;
F_14 ( ( V_165 ) && ( V_166 ) && ( V_58 ) ) ;
V_184 = F_68 ( V_69 , V_58 -> V_72 [ V_69 ] , * V_165 , * V_166 ) ;
if( V_184 != 0 && V_58 -> V_70 == V_185 )
V_184 = ( V_184 < 0 ) ? 1 : - 1 ;
return V_184 ;
}
static void
F_59 ( V_6 * V_58 )
{
T_14 * V_87 ;
T_13 * V_84 ;
T_7 * V_186 ;
T_32 V_187 ;
T_32 V_188 ;
F_19 ( V_58 != NULL ) ;
F_19 ( F_13 ( V_58 ) ) ;
if( F_29 ( V_58 -> V_67 ) == 0 )
return;
F_70 ( V_58 -> V_66 ,
( V_189 ) F_69 ,
V_58 ) ;
F_19 ( V_58 -> V_67 != NULL ) ;
V_186 = F_71 ( T_7 , F_29 ( V_58 -> V_67 ) ) ;
F_14 ( V_186 ) ;
for( V_187 = 0 , V_188 = 0 ; V_187 < F_29 ( V_58 -> V_66 ) ; ++ V_187 ) {
V_87 = F_28 ( V_58 -> V_66 , V_187 ) ;
#ifdef F_20
V_87 -> V_92 = V_187 ;
#endif
F_14 ( V_87 -> V_89 >= - 1 ) ;
if ( V_87 -> V_89 >= 0 ) {
F_14 ( V_87 -> V_96 -> V_109 . V_110 || V_87 -> V_96 -> V_109 . V_111 ) ;
V_186 [ V_188 ] = V_87 -> V_89 ;
F_72 ( V_58 -> V_67 , V_188 , V_87 ) ;
V_87 -> V_89 = V_188 ;
++ V_188 ;
}
}
F_14 ( V_188 == F_29 ( V_58 -> V_67 ) ) ;
V_84 = F_17 () ;
F_73 ( F_43 ( V_58 ) , V_84 , NULL ,
V_186 ) ;
F_44 ( V_84 ) ;
F_74 ( V_186 ) ;
}
T_32
F_75 ( V_6 * V_58 )
{
T_32 V_187 ;
T_32 V_188 ;
T_14 * V_87 ;
F_12 ( V_58 != NULL , 0 ) ;
F_12 ( F_13 ( V_58 ) , 0 ) ;
if( F_29 ( V_58 -> V_66 ) == 0 )
return 0 ;
if( V_58 -> V_67 )
F_33 ( V_58 -> V_67 , TRUE ) ;
V_58 -> V_67 = F_8 () ;
for( V_187 = 0 , V_188 = 0 ; V_187 < F_29 ( V_58 -> V_66 ) ; ++ V_187 ) {
V_87 = F_28 ( V_58 -> V_66 , V_187 ) ;
if ( V_87 -> V_96 -> V_109 . V_110 || V_87 -> V_96 -> V_109 . V_111 ) {
V_87 -> V_89 = V_188 ++ ;
F_39 ( V_58 -> V_67 , V_87 ) ;
}
else
V_87 -> V_89 = - 1 ;
}
return V_188 ;
}
static void
F_23 ( V_6 * V_58 , T_14 * V_87 , T_11 V_190 )
{
T_33 V_191 ;
T_17 * V_96 ;
T_18 * V_64 ;
T_7 V_113 ;
T_11 V_192 ;
struct V_193 V_194 ;
T_34 V_195 ;
T_11 V_196 = ( V_87 -> V_94 == NULL ) ;
F_19 ( V_58 ) ;
F_19 ( F_13 ( V_58 ) ) ;
F_76 ( & V_194 ) ;
V_96 = V_87 -> V_96 ;
if ( V_196 ) {
V_64 = & V_63 . V_64 ;
V_87 -> V_94 = ( const T_19 * * ) F_77 ( F_38 () , sizeof( * V_87 -> V_94 ) * V_58 -> V_73 ) ;
V_87 -> V_108 = ( V_127 * ) F_77 ( F_38 () , sizeof( * V_87 -> V_108 ) * V_58 -> V_73 ) ;
} else
V_64 = NULL ;
F_78 ( & V_195 , 1500 ) ;
if ( ! F_79 ( & V_63 , V_96 , & V_194 , & V_195 ) ) {
if ( V_196 ) {
F_80 ( V_64 , V_96 , FALSE , FALSE ) ;
for( V_113 = 0 ; V_113 < V_64 -> V_65 ; ++ V_113 )
F_45 ( V_58 , V_87 , V_113 , V_64 ) ;
}
if ( V_190 ) {
V_96 -> V_197 = NULL ;
V_87 -> V_95 = TRUE ;
}
F_81 ( & V_195 ) ;
return;
}
V_192 = ( V_190 && F_82 () ) ||
( V_196 && F_83 ( V_64 ) ) ;
F_84 ( & V_191 , V_63 . V_169 ,
V_192 ,
FALSE ) ;
if ( V_190 ) {
F_85 ( & V_191 ) ;
V_96 -> V_109 . V_198 = 1 ;
}
if ( V_196 )
F_86 ( & V_191 , V_64 ) ;
F_87 ( & V_191 , V_63 . V_199 , & V_194 , F_88 ( V_96 , & V_195 ) , V_96 , V_64 ) ;
if ( V_196 ) {
F_89 ( & V_191 , FALSE , FALSE ) ;
for( V_113 = 0 ; V_113 < V_64 -> V_65 ; ++ V_113 )
F_45 ( V_58 , V_87 , V_113 , V_64 ) ;
}
if ( V_190 )
V_87 -> V_95 = TRUE ;
F_90 ( & V_191 ) ;
F_91 ( & V_194 ) ;
F_81 ( & V_195 ) ;
}
void
F_92 ( V_6 * V_58 )
{
T_14 * V_87 ;
T_32 V_59 ;
for( V_59 = 0 ; V_59 < F_29 ( V_58 -> V_66 ) ; ++ V_59 ) {
V_87 = F_28 ( V_58 -> V_66 , V_59 ) ;
V_87 -> V_95 = FALSE ;
}
}
const char *
F_93 ( V_6 * V_58 , T_7 V_113 )
{
int V_115 ;
F_12 ( V_58 != NULL , NULL ) ;
F_12 ( F_13 ( V_58 ) , NULL ) ;
F_12 ( V_113 >= 0 && V_113 < V_58 -> V_62 , NULL ) ;
if ( F_29 ( V_58 -> V_67 ) == 0 )
return L_9 ;
V_115 = V_58 -> V_72 [ V_113 ] ;
if ( V_115 == - 1 ) {
T_14 * V_87 ;
T_32 V_188 ;
T_32 V_200 = 0 ;
T_7 V_201 = - 1 ;
for( V_188 = 0 ; V_188 < F_29 ( V_58 -> V_67 ) ; ++ V_188 ) {
T_7 V_202 ;
V_87 = F_28 ( V_58 -> V_67 , V_188 ) ;
F_24 ( V_87 -> V_96 , & V_63 . V_64 , V_113 , FALSE ) ;
V_202 = ( T_7 ) strlen ( V_63 . V_64 . V_97 [ V_113 ] . V_125 ) ;
if ( V_202 > V_201 ) {
V_201 = V_202 ;
V_200 = V_188 ;
}
}
if ( V_201 != - 1 ) {
V_87 = F_28 ( V_58 -> V_67 , V_200 ) ;
F_24 ( V_87 -> V_96 , & V_63 . V_64 , V_113 , FALSE ) ;
return V_63 . V_64 . V_97 [ V_113 ] . V_125 ;
} else
return L_9 ;
}
else {
T_14 * V_87 ;
T_32 V_188 ;
const T_19 * V_203 = NULL ;
T_32 V_201 = 0 ;
if ( ! V_58 -> V_68 )
F_50 ( V_58 ) ;
for( V_188 = 0 ; V_188 < F_29 ( V_58 -> V_67 ) ; ++ V_188 ) {
V_87 = F_28 ( V_58 -> V_67 , V_188 ) ;
if ( V_87 -> V_108 [ V_115 ] > V_201 ) {
V_203 = V_87 -> V_94 [ V_115 ] ;
V_201 = V_87 -> V_108 [ V_115 ] ;
}
}
return V_203 ;
}
}
