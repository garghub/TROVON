int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ V_5 ] ;
struct V_6 V_7 ;
int V_8 ;
struct V_9 V_9 ;
T_3 V_10 ;
T_3 V_11 ;
T_3 V_12 ;
T_3 * V_13 ;
#ifdef F_2
unsigned int V_14 ;
#endif
T_4 * V_15 ;
V_16 = V_17 ;
if ( ! F_3 ( V_1 -> V_18 , V_4 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 != V_19 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_4 , V_20 , V_5 ) != 0 &&
memcmp ( V_4 , V_21 , V_5 ) != 0 ) {
return 0 ;
}
V_16 = V_17 ;
if ( ! F_3 ( V_1 -> V_18 , & V_7 , sizeof V_7 , V_2 , V_3 ) )
return - 1 ;
switch ( V_7 . V_22 ) {
case 1 :
V_8 = V_23 ;
break;
case 2 :
V_8 = V_24 ;
break;
default:
* V_2 = V_25 ;
* V_3 = F_4 ( L_1 , V_7 . V_22 ) ;
return - 1 ;
}
V_7 . V_26 = F_5 ( & V_7 . V_26 ) ;
if ( V_7 . V_26 >= V_27
|| V_28 [ V_7 . V_26 ] == V_29 ) {
* V_2 = V_30 ;
* V_3 = F_4 ( L_2 ,
V_7 . V_26 ) ;
return - 1 ;
}
V_1 -> V_31 = V_8 ;
V_15 = ( T_4 * ) F_6 ( sizeof( T_4 ) ) ;
V_1 -> V_32 = ( void * ) V_15 ;
V_1 -> V_33 = V_34 ;
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = V_38 ;
if( ( V_7 . V_22 == 2 && V_7 . V_39 >= 1 ) || V_7 . V_22 > 2 )
V_1 -> V_40 = V_41 ;
else
V_1 -> V_40 = V_28 [ V_7 . V_26 ] ;
V_1 -> V_42 = 0 ;
V_9 . V_43 = F_5 ( & V_7 . V_44 ) - 1900 ;
V_9 . V_45 = F_5 ( & V_7 . V_46 ) - 1 ;
V_9 . V_47 = F_5 ( & V_7 . V_48 ) ;
V_9 . V_49 = F_5 ( & V_7 . V_50 ) ;
V_9 . V_51 = F_5 ( & V_7 . V_52 ) ;
V_9 . V_53 = F_5 ( & V_7 . V_54 ) ;
V_9 . V_55 = - 1 ;
V_15 -> V_56 = mktime ( & V_9 ) ;
V_15 -> V_57 = F_5 ( & V_7 . V_58 ) * 1000000 ;
V_15 -> V_59 = V_7 . V_22 ;
V_15 -> V_60 = V_7 . V_39 ;
V_15 -> V_12 = 0 ;
V_15 -> V_13 = NULL ;
V_10 = F_7 ( & V_7 . V_61 ) ;
V_11 = F_7 ( & V_7 . V_62 ) ;
V_12 = V_11 / ( T_3 ) sizeof ( T_3 ) ;
if ( ( V_12 * sizeof ( T_3 ) ) != V_11 ) {
* V_2 = V_63 ;
* V_3 = F_4 ( L_3 ,
V_11 ) ;
return - 1 ;
}
if ( V_12 == 0 ) {
* V_2 = V_63 ;
* V_3 = F_4 ( L_4 ,
V_11 ) ;
return - 1 ;
}
if ( V_12 > 512 * 1024 * 1024 ) {
* V_2 = V_63 ;
* V_3 = F_4 ( L_5 ,
V_11 ) ;
return - 1 ;
}
if ( F_8 ( V_1 -> V_18 , V_10 , V_64 , V_2 ) == - 1 ) {
return - 1 ;
}
V_13 = ( T_3 * ) F_9 ( V_11 ) ;
if ( V_11 != 0 && V_13 == NULL ) {
* V_2 = V_65 ;
return - 1 ;
}
V_16 = V_17 ;
if ( ! F_3 ( V_1 -> V_18 , V_13 , V_11 ,
V_2 , V_3 ) ) {
F_10 ( V_13 ) ;
return - 1 ;
}
V_15 -> V_12 = V_12 ;
V_15 -> V_13 = V_13 ;
#ifdef F_2
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
V_13 [ V_14 ] = F_7 ( & V_13 [ V_14 ] ) ;
#endif
V_15 -> V_66 = 0 ;
switch ( V_15 -> V_59 ) {
case 1 :
V_1 -> V_67 = V_68 ;
break;
case 2 :
V_1 -> V_67 = V_69 ;
break;
}
return 1 ;
}
static void
F_11 ( struct V_70 * V_71 , T_5 * V_72 )
{
switch ( V_71 -> V_73 ) {
case V_74 :
F_12 ( V_71 , F_13 ( V_72 ) ) ;
break;
case V_75 :
V_71 -> V_76 . V_77 . V_78 = 0 ;
break;
case V_79 :
V_71 -> V_76 . V_80 . V_78 = - 2 ;
V_71 -> V_76 . V_80 . V_81 = FALSE ;
break;
}
}
static T_6
F_14 ( T_1 * V_1 , T_7 V_18 , struct V_70 * V_71 ,
T_5 * V_72 , int * V_2 , T_2 * * V_3 )
{
T_4 * V_15 = ( T_4 * ) V_1 -> V_32 ;
int V_82 = 0 ;
union {
struct V_83 V_84 ;
struct V_85 V_86 ;
} V_7 ;
T_8 V_87 = 0 ;
T_8 V_88 ;
T_9 V_89 ;
int V_90 ;
T_3 V_91 = 0 ;
T_3 V_92 = 0 ;
int V_93 ;
union {
struct V_94 V_95 ;
struct V_96 V_97 ;
struct V_98 V_99 ;
} V_100 ;
T_10 V_26 ;
int V_73 ;
switch ( V_15 -> V_59 ) {
case 1 :
V_82 = sizeof ( struct V_83 ) ;
break;
case 2 :
V_82 = sizeof ( struct V_85 ) ;
break;
}
V_16 = V_17 ;
if ( ! F_15 ( V_18 , & V_7 , V_82 , V_2 , V_3 ) )
return V_101 ;
switch ( V_15 -> V_59 ) {
case 1 :
V_92 = F_5 ( & V_7 . V_84 . V_102 ) ;
V_91 = F_5 ( & V_7 . V_84 . V_103 ) ;
break;
case 2 :
V_92 = F_7 ( & V_7 . V_86 . V_102 ) ;
V_91 = F_7 ( & V_7 . V_86 . V_103 ) ;
break;
}
if ( V_91 > V_104 ) {
* V_2 = V_63 ;
* V_3 = F_4 ( L_6 ,
V_91 , V_104 ) ;
return V_101 ;
}
V_71 -> V_105 = V_106 ;
switch ( V_1 -> V_40 ) {
case V_74 :
if ( V_91 < sizeof ( struct V_107 ) ) {
* V_2 = V_63 ;
* V_3 = F_4 ( L_7 ,
V_91 ) ;
return V_101 ;
}
if ( ! F_16 ( V_18 , & V_71 -> V_76 ,
V_2 , V_3 ) )
return V_101 ;
V_92 -= ( V_108 ) sizeof ( struct V_107 ) ;
V_91 -= ( V_108 ) sizeof ( struct V_107 ) ;
break;
default:
break;
}
switch ( V_15 -> V_59 ) {
case 1 :
V_87 = ( ( T_8 ) F_7 ( & V_7 . V_84 . V_109 ) ) * 1000000 ;
break;
case 2 :
V_87 = F_17 ( & V_7 . V_86 . V_109 ) * 10 ;
V_87 *= 100 ;
break;
}
V_89 = 0 ;
V_88 = V_15 -> V_57 + V_87 ;
while ( V_88 < 0 ) {
V_88 += 1000000000 ;
V_89 -- ;
}
V_89 += ( T_9 ) ( V_88 / 1000000000 ) ;
V_90 = ( int ) ( V_88 % 1000000000 ) ;
V_71 -> V_110 = V_111 | V_112 ;
V_71 -> V_113 . V_89 = V_15 -> V_56 + V_89 ;
V_71 -> V_113 . V_90 = V_90 ;
V_71 -> V_114 = V_91 ;
V_71 -> V_115 = V_92 ;
if ( ! F_18 ( V_18 , V_72 , V_71 -> V_114 , V_2 , V_3 ) )
return V_101 ;
if ( ( V_15 -> V_59 == 2 && V_15 -> V_60 >= 1 ) ||
V_15 -> V_59 > 2 ) {
if ( V_15 -> V_59 > 2 ) {
V_93 = ( int ) sizeof ( struct V_98 ) ;
} else {
switch ( V_15 -> V_60 ) {
case 1 :
V_93 = ( int ) sizeof ( struct V_94 ) ;
break;
case 2 :
V_93 = ( int ) sizeof ( struct V_96 ) ;
break;
default:
V_93 = ( int ) sizeof ( struct V_98 ) ;
break;
}
}
V_16 = V_17 ;
if ( ! F_3 ( V_18 , & V_100 , V_93 , V_2 , V_3 ) )
return V_101 ;
V_26 = F_5 ( V_100 . V_95 . V_26 ) ;
if ( ( V_26 & 0xF000 ) == V_116 ) {
V_26 &= 0x0FFF ;
V_73 = F_19 ( V_26 ) ;
if ( V_73 == V_29 ) {
* V_2 = V_30 ;
* V_3 = F_4 ( L_8 ,
V_26 ) ;
return V_101 ;
}
} else if ( V_26 < V_27 ) {
V_73 = V_28 [ V_26 ] ;
if ( V_73 == V_29 ) {
* V_2 = V_30 ;
* V_3 = F_4 ( L_2 ,
V_26 ) ;
return V_101 ;
}
} else {
switch ( V_26 ) {
case V_117 :
return V_118 ;
case V_119 :
return V_118 ;
case V_120 :
return V_118 ;
case V_121 :
return V_118 ;
case V_122 :
return V_118 ;
case V_123 :
return V_118 ;
default:
* V_2 = V_30 ;
* V_3 = F_4 ( L_2 ,
V_26 ) ;
return V_101 ;
}
}
V_71 -> V_73 = V_73 ;
if ( V_15 -> V_59 > 2 || V_15 -> V_60 > 2 ) {
T_11 V_124 ;
T_8 V_125 ;
T_9 V_126 = V_127 ;
T_9 V_128 = V_129 ;
V_124 = F_17 ( V_100 . V_99 . V_130 ) ;
V_125 = V_124 / 10000000 ;
V_90 = ( int ) ( ( V_124 % 10000000 ) * 100 ) ;
V_125 -= V_131 ;
if ( ! ( V_126 <= V_89 && V_89 <= V_128 ) ) {
* V_2 = V_63 ;
* V_3 = F_4 ( L_9 ) ;
return V_101 ;
}
V_71 -> V_113 . V_89 = ( T_9 ) V_125 ;
V_71 -> V_113 . V_90 = V_90 ;
}
}
F_11 ( V_71 , V_72 ) ;
return V_132 ;
}
static T_12 V_34 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_8 * V_133 )
{
T_4 * V_15 = ( T_4 * ) V_1 -> V_32 ;
T_8 V_134 ;
for (; ; ) {
if ( V_15 -> V_66 >= V_15 -> V_12 ) {
F_10 ( V_15 -> V_13 ) ;
V_15 -> V_13 = NULL ;
* V_2 = 0 ;
return FALSE ;
}
V_134 = V_15 -> V_13 [ V_15 -> V_66 ] ;
if ( F_20 ( V_1 -> V_18 ) != V_134 ) {
if ( F_8 ( V_1 -> V_18 , V_134 , V_64 , V_2 ) == - 1 )
return FALSE ;
}
V_15 -> V_66 ++ ;
* V_133 = F_20 ( V_1 -> V_18 ) ;
switch ( F_14 ( V_1 , V_1 -> V_18 , & V_1 -> V_71 ,
V_1 -> V_135 , V_2 , V_3 ) ) {
case V_118 :
continue;
case V_132 :
return TRUE ;
case V_101 :
return FALSE ;
}
}
}
static T_12
V_36 ( T_1 * V_1 , T_8 V_136 ,
struct V_70 * V_71 , T_5 * V_72 , int * V_2 , T_2 * * V_3 )
{
if ( F_8 ( V_1 -> V_137 , V_136 , V_64 , V_2 ) == - 1 )
return FALSE ;
switch ( F_14 ( V_1 , V_1 -> V_137 , V_71 , V_72 , V_2 ,
V_3 ) ) {
default:
* V_2 = V_63 ;
* V_3 = F_21 ( L_10 ) ;
return FALSE ;
case V_132 :
return TRUE ;
case V_101 :
return FALSE ;
}
}
static T_12
F_16 ( T_7 V_18 , union V_138 * V_76 ,
int * V_2 , T_2 * * V_3 )
{
struct V_107 V_139 ;
T_10 V_140 , V_141 ;
V_16 = V_17 ;
if ( ! F_3 ( V_18 , & V_139 , sizeof ( struct V_107 ) ,
V_2 , V_3 ) )
return FALSE ;
V_140 = F_22 ( V_139 . V_140 ) ;
V_141 = F_22 ( V_139 . V_141 ) ;
V_76 -> V_142 . V_140 = V_140 ;
V_76 -> V_142 . V_141 = V_141 ;
V_76 -> V_142 . V_143 = 0 ;
V_76 -> V_142 . V_144 = 0 ;
V_76 -> V_142 . V_145 = 0 ;
V_76 -> V_142 . V_146 = 0 ;
V_76 -> V_142 . V_147 = 0 ;
V_76 -> V_142 . V_148 = 0 ;
return TRUE ;
}
static void
V_38 ( T_1 * V_1 )
{
T_4 * V_15 = ( T_4 * ) V_1 -> V_32 ;
if ( V_15 -> V_13 != NULL ) {
F_10 ( V_15 -> V_13 ) ;
V_15 -> V_13 = NULL ;
}
}
int F_23 ( int V_149 )
{
if ( V_149 < 0 || ( unsigned ) V_149 >= V_150 || V_151 [ V_149 ] == - 1 )
return V_30 ;
return 0 ;
}
int F_24 ( int V_149 )
{
if ( V_149 == V_41 )
return 0 ;
if ( V_149 < 0 || ( unsigned ) V_149 >= V_150 || V_151 [ V_149 ] == - 1 )
return V_30 ;
return 0 ;
}
T_12 F_25 ( T_13 * V_152 , int * V_2 )
{
T_14 * V_15 ;
if ( F_26 ( V_152 , V_153 , V_64 , V_2 ) == - 1 )
return FALSE ;
V_152 -> V_154 = V_155 ;
V_152 -> V_156 = V_157 ;
V_15 = ( T_14 * ) F_6 ( sizeof( T_14 ) ) ;
V_152 -> V_32 = ( void * ) V_15 ;
V_15 -> V_10 = V_153 ;
V_15 -> V_158 = FALSE ;
V_15 -> V_13 = NULL ;
V_15 -> V_159 = 0 ;
V_15 -> V_12 = 0 ;
V_15 -> V_160 = FALSE ;
return TRUE ;
}
static T_12 V_155 ( T_13 * V_152 , const struct V_70 * V_71 ,
const T_15 * V_161 , int * V_2 )
{
const union V_138 * V_76 = & V_71 -> V_76 ;
T_14 * V_15 = ( T_14 * ) V_152 -> V_32 ;
struct V_83 V_162 ;
struct V_85 V_163 ;
void * V_164 ;
T_16 V_165 ;
struct V_94 V_166 ;
T_16 V_82 ;
struct V_107 V_167 ;
int V_168 ;
T_8 V_89 ;
T_17 V_90 ;
if ( V_71 -> V_105 != V_106 ) {
* V_2 = V_169 ;
return FALSE ;
}
switch ( V_152 -> V_31 ) {
case V_23 :
if ( V_71 -> V_114 > 65535 ) {
* V_2 = V_170 ;
return FALSE ;
}
break;
case V_24 :
if ( V_71 -> V_114 > V_104 ) {
* V_2 = V_170 ;
return FALSE ;
}
break;
default:
* V_2 = V_171 ;
return FALSE ;
}
if ( V_152 -> V_149 == V_41 ) {
if ( V_71 -> V_73 < 0 ||
( unsigned ) V_71 -> V_73 >= V_150 ||
V_151 [ V_71 -> V_73 ] == - 1 ) {
* V_2 = V_30 ;
return FALSE ;
}
F_27 ( V_166 . V_26 , V_151 [ V_71 -> V_73 ] ) ;
}
if ( V_15 -> V_160 ) {
* V_2 = V_172 ;
return FALSE ;
}
if ( ! V_15 -> V_158 ) {
V_15 -> V_173 . V_89 = V_71 -> V_113 . V_89 ;
V_15 -> V_173 . V_90 =
( V_71 -> V_113 . V_90 / 1000000 ) * 1000000 ;
V_15 -> V_158 = TRUE ;
}
if ( V_152 -> V_149 == V_74 )
V_168 = sizeof ( struct V_107 ) ;
else
V_168 = 0 ;
V_89 = ( T_8 ) ( V_71 -> V_113 . V_89 - V_15 -> V_173 . V_89 ) ;
V_90 = V_71 -> V_113 . V_90 - V_15 -> V_173 . V_90 ;
while ( V_90 < 0 ) {
V_90 += 1000000000 ;
V_89 -- ;
}
switch ( V_152 -> V_31 ) {
case V_23 :
V_162 . V_109 = F_28 ( V_89 * 1000 + ( V_90 + 500000 ) / 1000000 ) ;
V_162 . V_102 = F_29 ( V_71 -> V_115 + V_168 ) ;
V_162 . V_103 = F_29 ( V_71 -> V_114 + V_168 ) ;
V_164 = & V_162 ;
V_82 = sizeof V_162 ;
break;
case V_24 :
V_163 . V_109 = F_30 ( V_89 * 1000000 + ( V_90 + 500 ) / 1000 ) ;
V_163 . V_102 = F_28 ( V_71 -> V_115 + V_168 ) ;
V_163 . V_103 = F_28 ( V_71 -> V_114 + V_168 ) ;
V_164 = & V_163 ;
V_82 = sizeof V_163 ;
break;
default:
* V_2 = V_171 ;
return FALSE ;
}
V_165 = 0 ;
if ( ! F_31 ( V_152 , V_164 , V_82 , V_2 ) )
return FALSE ;
V_165 += V_82 ;
if ( V_152 -> V_149 == V_74 ) {
memset ( & V_167 . V_174 , 0 , sizeof V_167 . V_174 ) ;
memset ( & V_167 . V_175 , 0 , sizeof V_167 . V_175 ) ;
V_167 . V_140 = F_32 ( V_76 -> V_142 . V_140 ) ;
V_167 . V_141 = F_32 ( V_76 -> V_142 . V_141 ) ;
if ( ! F_31 ( V_152 , & V_167 , sizeof V_167 , V_2 ) )
return FALSE ;
V_165 += sizeof V_167 ;
}
if ( ! F_31 ( V_152 , V_161 , V_71 -> V_114 , V_2 ) )
return FALSE ;
V_165 += V_71 -> V_114 ;
if ( V_152 -> V_149 == V_41 ) {
if ( ! F_31 ( V_152 , & V_166 ,
sizeof V_166 , V_2 ) )
return FALSE ;
V_165 += sizeof V_166 ;
}
if ( V_15 -> V_12 == 0 ) {
V_15 -> V_13 = ( T_3 * ) F_6 ( 1024 * sizeof * V_15 -> V_13 ) ;
V_15 -> V_12 = 1024 ;
} else {
if ( V_15 -> V_159 >= V_15 -> V_12 ) {
V_15 -> V_12 *= 2 ;
V_15 -> V_13 = ( T_3 * ) F_33 ( V_15 -> V_13 ,
V_15 -> V_12 * sizeof * V_15 -> V_13 ) ;
}
}
V_15 -> V_13 [ V_15 -> V_159 ] =
F_28 ( V_15 -> V_10 ) ;
if ( ( T_11 ) V_15 -> V_10 + V_165 > V_176 ) {
V_15 -> V_160 = TRUE ;
}
V_15 -> V_159 ++ ;
V_15 -> V_10 += ( T_3 ) V_165 ;
return TRUE ;
}
static T_12 V_157 ( T_13 * V_152 , int * V_2 )
{
T_14 * V_15 = ( T_14 * ) V_152 -> V_32 ;
T_16 V_177 ;
struct V_6 V_178 ;
const char * V_179 ;
T_16 V_180 ;
struct V_9 * V_9 ;
V_177 = V_15 -> V_159 * sizeof * V_15 -> V_13 ;
if ( ! F_31 ( V_152 , V_15 -> V_13 , V_177 , V_2 ) )
return FALSE ;
if ( F_26 ( V_152 , 0 , V_64 , V_2 ) == - 1 )
return FALSE ;
memset ( & V_178 , '\0' , sizeof V_178 ) ;
switch ( V_152 -> V_31 ) {
case V_23 :
V_179 = V_20 ;
V_180 = sizeof V_20 ;
V_178 . V_22 = 1 ;
V_178 . V_39 = 1 ;
break;
case V_24 :
V_179 = V_21 ;
V_180 = sizeof V_21 ;
V_178 . V_22 = 2 ;
V_178 . V_39 =
( V_152 -> V_149 == V_41 ) ? 1 : 0 ;
break;
default:
if ( V_2 != NULL )
* V_2 = V_171 ;
return FALSE ;
}
if ( ! F_31 ( V_152 , V_179 , V_180 , V_2 ) )
return FALSE ;
if ( V_152 -> V_149 == V_41 ) {
V_178 . V_26 = F_29 ( 1 ) ;
} else
V_178 . V_26 = F_29 ( V_151 [ V_152 -> V_149 ] ) ;
V_9 = localtime ( & V_15 -> V_173 . V_89 ) ;
if ( V_9 != NULL ) {
V_178 . V_44 = F_29 ( 1900 + V_9 -> V_43 ) ;
V_178 . V_46 = F_29 ( V_9 -> V_45 + 1 ) ;
V_178 . V_181 = F_29 ( V_9 -> V_182 ) ;
V_178 . V_48 = F_29 ( V_9 -> V_47 ) ;
V_178 . V_50 = F_29 ( V_9 -> V_49 ) ;
V_178 . V_52 = F_29 ( V_9 -> V_51 ) ;
V_178 . V_54 = F_29 ( V_9 -> V_53 ) ;
} else {
V_178 . V_44 = F_29 ( 1900 + 0 ) ;
V_178 . V_46 = F_29 ( 0 + 1 ) ;
V_178 . V_181 = F_29 ( 0 ) ;
V_178 . V_48 = F_29 ( 0 ) ;
V_178 . V_50 = F_29 ( 0 ) ;
V_178 . V_52 = F_29 ( 0 ) ;
V_178 . V_54 = F_29 ( 0 ) ;
}
V_178 . V_58 = F_29 ( V_15 -> V_173 . V_90 / 1000000 ) ;
V_178 . V_61 = F_28 ( V_15 -> V_10 ) ;
V_178 . V_62 =
F_28 ( V_15 -> V_159 * sizeof * V_15 -> V_13 ) ;
if ( ! F_31 ( V_152 , & V_178 , sizeof V_178 , V_2 ) )
return FALSE ;
return TRUE ;
}
