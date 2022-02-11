T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ V_5 ] ;
struct V_6 V_7 ;
int V_8 ;
struct V_9 V_9 ;
T_4 V_10 ;
T_4 V_11 ;
T_4 V_12 ;
T_4 * V_13 ;
#ifdef F_2
unsigned int V_14 ;
#endif
T_5 * V_15 ;
if ( ! F_3 ( V_1 -> V_16 , V_4 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 != V_17 )
return V_18 ;
return V_19 ;
}
if ( memcmp ( V_4 , V_20 , V_5 ) != 0 &&
memcmp ( V_4 , V_21 , V_5 ) != 0 ) {
return V_19 ;
}
if ( ! F_3 ( V_1 -> V_16 , & V_7 , sizeof V_7 , V_2 , V_3 ) )
return V_18 ;
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
return V_18 ;
}
V_7 . V_26 = F_5 ( & V_7 . V_26 ) ;
if ( V_7 . V_26 >= V_27
|| V_28 [ V_7 . V_26 ] == V_29 ) {
* V_2 = V_25 ;
* V_3 = F_4 ( L_2 ,
V_7 . V_26 ) ;
return V_18 ;
}
V_1 -> V_30 = V_8 ;
V_15 = ( T_5 * ) F_6 ( sizeof( T_5 ) ) ;
V_1 -> V_31 = ( void * ) V_15 ;
V_1 -> V_32 = V_33 ;
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = V_37 ;
if( ( V_7 . V_22 == 2 && V_7 . V_38 >= 1 ) || V_7 . V_22 > 2 )
V_1 -> V_39 = V_40 ;
else
V_1 -> V_39 = V_28 [ V_7 . V_26 ] ;
V_1 -> V_41 = 0 ;
V_9 . V_42 = F_5 ( & V_7 . V_43 ) - 1900 ;
V_9 . V_44 = F_5 ( & V_7 . V_45 ) - 1 ;
V_9 . V_46 = F_5 ( & V_7 . V_47 ) ;
V_9 . V_48 = F_5 ( & V_7 . V_49 ) ;
V_9 . V_50 = F_5 ( & V_7 . V_51 ) ;
V_9 . V_52 = F_5 ( & V_7 . V_53 ) ;
V_9 . V_54 = - 1 ;
V_15 -> V_55 = mktime ( & V_9 ) ;
V_15 -> V_56 = F_5 ( & V_7 . V_57 ) * 1000000 ;
V_15 -> V_58 = V_7 . V_22 ;
V_15 -> V_59 = V_7 . V_38 ;
V_15 -> V_12 = 0 ;
V_15 -> V_13 = NULL ;
V_10 = F_7 ( & V_7 . V_60 ) ;
V_11 = F_7 ( & V_7 . V_61 ) ;
V_12 = V_11 / ( T_4 ) sizeof ( T_4 ) ;
if ( ( V_12 * sizeof ( T_4 ) ) != V_11 ) {
* V_2 = V_62 ;
* V_3 = F_4 ( L_3 ,
V_11 ) ;
return V_18 ;
}
if ( V_12 == 0 ) {
* V_2 = V_62 ;
* V_3 = F_4 ( L_4 ,
V_11 ) ;
return V_18 ;
}
if ( V_12 > 512 * 1024 * 1024 ) {
* V_2 = V_62 ;
* V_3 = F_4 ( L_5 ,
V_11 ) ;
return V_18 ;
}
if ( F_8 ( V_1 -> V_16 , V_10 , V_63 , V_2 ) == - 1 ) {
return V_18 ;
}
V_13 = ( T_4 * ) F_9 ( V_11 ) ;
if ( V_11 != 0 && V_13 == NULL ) {
* V_2 = V_64 ;
return V_18 ;
}
if ( ! F_3 ( V_1 -> V_16 , V_13 , V_11 ,
V_2 , V_3 ) ) {
F_10 ( V_13 ) ;
return V_18 ;
}
V_15 -> V_12 = V_12 ;
V_15 -> V_13 = V_13 ;
#ifdef F_2
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
V_13 [ V_14 ] = F_7 ( & V_13 [ V_14 ] ) ;
#endif
V_15 -> V_65 = 0 ;
switch ( V_15 -> V_58 ) {
case 1 :
V_1 -> V_66 = V_67 ;
break;
case 2 :
V_1 -> V_66 = V_68 ;
break;
}
return V_69 ;
}
static void
F_11 ( struct V_70 * V_71 , T_6 * V_72 )
{
switch ( V_71 -> V_73 ) {
case V_74 :
F_12 ( V_71 , F_13 ( V_72 ) ) ;
break;
case V_75 :
V_71 -> V_76 . V_77 . V_78 = 0 ;
break;
case V_79 :
memset ( & V_71 -> V_76 . V_80 , 0 , sizeof( V_71 -> V_76 . V_80 ) ) ;
V_71 -> V_76 . V_80 . V_78 = - 2 ;
V_71 -> V_76 . V_80 . V_81 = FALSE ;
V_71 -> V_76 . V_80 . V_82 = FALSE ;
V_71 -> V_76 . V_80 . V_83 = V_84 ;
break;
}
}
static T_7
F_14 ( T_2 * V_1 , T_8 V_16 , struct V_70 * V_71 ,
T_6 * V_72 , int * V_2 , T_3 * * V_3 )
{
T_5 * V_15 = ( T_5 * ) V_1 -> V_31 ;
int V_85 = 0 ;
union {
struct V_86 V_87 ;
struct V_88 V_89 ;
} V_7 ;
T_9 V_90 = 0 ;
T_9 V_91 ;
T_10 V_92 ;
int V_93 ;
T_4 V_94 = 0 ;
T_4 V_95 = 0 ;
int V_96 ;
union {
struct V_97 V_98 ;
struct V_99 V_100 ;
struct V_101 V_102 ;
} V_103 ;
T_11 V_26 ;
int V_73 ;
switch ( V_15 -> V_58 ) {
case 1 :
V_85 = sizeof ( struct V_86 ) ;
break;
case 2 :
V_85 = sizeof ( struct V_88 ) ;
break;
}
if ( ! F_15 ( V_16 , & V_7 , V_85 , V_2 , V_3 ) )
return V_104 ;
switch ( V_15 -> V_58 ) {
case 1 :
V_95 = F_5 ( & V_7 . V_87 . V_105 ) ;
V_94 = F_5 ( & V_7 . V_87 . V_106 ) ;
break;
case 2 :
V_95 = F_7 ( & V_7 . V_89 . V_105 ) ;
V_94 = F_7 ( & V_7 . V_89 . V_106 ) ;
break;
}
if ( V_94 > V_107 ) {
* V_2 = V_62 ;
* V_3 = F_4 ( L_6 ,
V_94 , V_107 ) ;
return V_104 ;
}
V_71 -> V_108 = V_109 ;
switch ( V_1 -> V_39 ) {
case V_74 :
if ( V_94 < sizeof ( struct V_110 ) ) {
* V_2 = V_62 ;
* V_3 = F_4 ( L_7 ,
V_94 ) ;
return V_104 ;
}
if ( ! F_16 ( V_16 , & V_71 -> V_76 ,
V_2 , V_3 ) )
return V_104 ;
V_95 -= ( V_111 ) sizeof ( struct V_110 ) ;
V_94 -= ( V_111 ) sizeof ( struct V_110 ) ;
break;
default:
break;
}
switch ( V_15 -> V_58 ) {
case 1 :
V_90 = ( ( T_9 ) F_7 ( & V_7 . V_87 . V_112 ) ) * 1000000 ;
break;
case 2 :
V_90 = F_17 ( & V_7 . V_89 . V_112 ) * 10 ;
V_90 *= 100 ;
break;
}
V_92 = 0 ;
V_91 = V_15 -> V_56 + V_90 ;
while ( V_91 < 0 ) {
V_91 += 1000000000 ;
V_92 -- ;
}
V_92 += ( T_10 ) ( V_91 / 1000000000 ) ;
V_93 = ( int ) ( V_91 % 1000000000 ) ;
V_71 -> V_113 = V_114 | V_115 ;
V_71 -> V_116 . V_92 = V_15 -> V_55 + V_92 ;
V_71 -> V_116 . V_93 = V_93 ;
V_71 -> V_117 = V_94 ;
V_71 -> V_118 = V_95 ;
if ( ! F_18 ( V_16 , V_72 , V_71 -> V_117 , V_2 , V_3 ) )
return V_104 ;
if ( ( V_15 -> V_58 == 2 && V_15 -> V_59 >= 1 ) ||
V_15 -> V_58 > 2 ) {
if ( V_15 -> V_58 > 2 ) {
V_96 = ( int ) sizeof ( struct V_101 ) ;
} else {
switch ( V_15 -> V_59 ) {
case 1 :
V_96 = ( int ) sizeof ( struct V_97 ) ;
break;
case 2 :
V_96 = ( int ) sizeof ( struct V_99 ) ;
break;
default:
V_96 = ( int ) sizeof ( struct V_101 ) ;
break;
}
}
if ( ! F_3 ( V_16 , & V_103 , V_96 , V_2 , V_3 ) )
return V_104 ;
V_26 = F_5 ( V_103 . V_98 . V_26 ) ;
if ( ( V_26 & 0xF000 ) == V_119 ) {
V_26 &= 0x0FFF ;
V_73 = F_19 ( V_26 ) ;
if ( V_73 == V_29 ) {
* V_2 = V_25 ;
* V_3 = F_4 ( L_8 ,
V_26 ) ;
return V_104 ;
}
} else if ( V_26 < V_27 ) {
V_73 = V_28 [ V_26 ] ;
if ( V_73 == V_29 ) {
* V_2 = V_25 ;
* V_3 = F_4 ( L_2 ,
V_26 ) ;
return V_104 ;
}
} else {
switch ( V_26 ) {
case V_120 :
return V_121 ;
case V_122 :
return V_121 ;
case V_123 :
return V_121 ;
case V_124 :
return V_121 ;
case V_125 :
return V_121 ;
case V_126 :
return V_121 ;
default:
* V_2 = V_25 ;
* V_3 = F_4 ( L_2 ,
V_26 ) ;
return V_104 ;
}
}
V_71 -> V_73 = V_73 ;
if ( V_15 -> V_58 > 2 || V_15 -> V_59 > 2 ) {
T_12 V_127 ;
V_127 = F_17 ( V_103 . V_102 . V_128 ) ;
if ( ! F_20 ( & V_71 -> V_116 , V_127 ) ) {
* V_2 = V_62 ;
* V_3 = F_21 ( L_9 ) ;
return V_104 ;
}
}
}
F_11 ( V_71 , V_72 ) ;
return V_129 ;
}
static T_13 V_33 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_9 * V_130 )
{
T_5 * V_15 = ( T_5 * ) V_1 -> V_31 ;
T_9 V_131 ;
for (; ; ) {
if ( V_15 -> V_65 >= V_15 -> V_12 ) {
F_10 ( V_15 -> V_13 ) ;
V_15 -> V_13 = NULL ;
* V_2 = 0 ;
return FALSE ;
}
V_131 = V_15 -> V_13 [ V_15 -> V_65 ] ;
if ( F_22 ( V_1 -> V_16 ) != V_131 ) {
if ( F_8 ( V_1 -> V_16 , V_131 , V_63 , V_2 ) == - 1 )
return FALSE ;
}
V_15 -> V_65 ++ ;
* V_130 = F_22 ( V_1 -> V_16 ) ;
switch ( F_14 ( V_1 , V_1 -> V_16 , & V_1 -> V_71 ,
V_1 -> V_132 , V_2 , V_3 ) ) {
case V_121 :
continue;
case V_129 :
return TRUE ;
case V_104 :
return FALSE ;
}
}
}
static T_13
V_35 ( T_2 * V_1 , T_9 V_133 ,
struct V_70 * V_71 , T_6 * V_72 , int * V_2 , T_3 * * V_3 )
{
if ( F_8 ( V_1 -> V_134 , V_133 , V_63 , V_2 ) == - 1 )
return FALSE ;
switch ( F_14 ( V_1 , V_1 -> V_134 , V_71 , V_72 , V_2 ,
V_3 ) ) {
default:
* V_2 = V_62 ;
* V_3 = F_21 ( L_10 ) ;
return FALSE ;
case V_129 :
return TRUE ;
case V_104 :
return FALSE ;
}
}
static T_13
F_16 ( T_8 V_16 , union V_135 * V_76 ,
int * V_2 , T_3 * * V_3 )
{
struct V_110 V_136 ;
T_11 V_137 , V_138 ;
if ( ! F_3 ( V_16 , & V_136 , sizeof ( struct V_110 ) ,
V_2 , V_3 ) )
return FALSE ;
V_137 = F_23 ( V_136 . V_137 ) ;
V_138 = F_23 ( V_136 . V_138 ) ;
V_76 -> V_139 . V_137 = V_137 ;
V_76 -> V_139 . V_138 = V_138 ;
V_76 -> V_139 . V_140 = 0 ;
V_76 -> V_139 . V_141 = 0 ;
V_76 -> V_139 . V_142 = 0 ;
V_76 -> V_139 . V_143 = 0 ;
V_76 -> V_139 . V_144 = 0 ;
V_76 -> V_139 . V_145 = 0 ;
return TRUE ;
}
static void
V_37 ( T_2 * V_1 )
{
T_5 * V_15 = ( T_5 * ) V_1 -> V_31 ;
if ( V_15 -> V_13 != NULL ) {
F_10 ( V_15 -> V_13 ) ;
V_15 -> V_13 = NULL ;
}
}
int F_24 ( int V_146 )
{
if ( V_146 < 0 || ( unsigned ) V_146 >= V_147 || V_148 [ V_146 ] == - 1 )
return V_149 ;
return 0 ;
}
int F_25 ( int V_146 )
{
if ( V_146 == V_40 )
return 0 ;
if ( V_146 < 0 || ( unsigned ) V_146 >= V_147 || V_148 [ V_146 ] == - 1 )
return V_149 ;
return 0 ;
}
T_13 F_26 ( T_14 * V_150 , int * V_2 )
{
T_15 * V_15 ;
if ( F_27 ( V_150 , V_151 , V_63 , V_2 ) == - 1 )
return FALSE ;
V_150 -> V_152 = V_153 ;
V_150 -> V_154 = V_155 ;
V_15 = ( T_15 * ) F_6 ( sizeof( T_15 ) ) ;
V_150 -> V_31 = ( void * ) V_15 ;
V_15 -> V_10 = V_151 ;
V_15 -> V_156 = FALSE ;
V_15 -> V_13 = NULL ;
V_15 -> V_157 = 0 ;
V_15 -> V_12 = 0 ;
V_15 -> V_158 = FALSE ;
return TRUE ;
}
static T_13 V_153 ( T_14 * V_150 , const struct V_70 * V_71 ,
const T_16 * V_159 , int * V_2 , T_3 * * V_3 V_160 )
{
const union V_135 * V_76 = & V_71 -> V_76 ;
T_15 * V_15 = ( T_15 * ) V_150 -> V_31 ;
struct V_86 V_161 ;
struct V_88 V_162 ;
void * V_163 ;
T_17 V_164 ;
struct V_97 V_165 ;
T_17 V_85 ;
struct V_110 V_166 ;
int V_167 ;
T_9 V_92 ;
T_18 V_93 ;
if ( V_71 -> V_108 != V_109 ) {
* V_2 = V_168 ;
return FALSE ;
}
switch ( V_150 -> V_30 ) {
case V_23 :
if ( V_71 -> V_117 > 65535 ) {
* V_2 = V_169 ;
return FALSE ;
}
break;
case V_24 :
if ( V_71 -> V_117 > V_107 ) {
* V_2 = V_169 ;
return FALSE ;
}
break;
default:
* V_2 = V_170 ;
return FALSE ;
}
if ( V_150 -> V_146 == V_40 ) {
if ( V_71 -> V_73 < 0 ||
( unsigned ) V_71 -> V_73 >= V_147 ||
V_148 [ V_71 -> V_73 ] == - 1 ) {
* V_2 = V_149 ;
return FALSE ;
}
F_28 ( V_165 . V_26 , V_148 [ V_71 -> V_73 ] ) ;
}
if ( V_15 -> V_158 ) {
* V_2 = V_171 ;
return FALSE ;
}
if ( ! V_15 -> V_156 ) {
V_15 -> V_172 . V_92 = V_71 -> V_116 . V_92 ;
V_15 -> V_172 . V_93 =
( V_71 -> V_116 . V_93 / 1000000 ) * 1000000 ;
V_15 -> V_156 = TRUE ;
}
if ( V_150 -> V_146 == V_74 )
V_167 = sizeof ( struct V_110 ) ;
else
V_167 = 0 ;
V_92 = ( T_9 ) ( V_71 -> V_116 . V_92 - V_15 -> V_172 . V_92 ) ;
V_93 = V_71 -> V_116 . V_93 - V_15 -> V_172 . V_93 ;
while ( V_93 < 0 ) {
V_93 += 1000000000 ;
V_92 -- ;
}
switch ( V_150 -> V_30 ) {
case V_23 :
V_161 . V_112 = F_29 ( V_92 * 1000 + ( V_93 + 500000 ) / 1000000 ) ;
V_161 . V_105 = F_30 ( V_71 -> V_118 + V_167 ) ;
V_161 . V_106 = F_30 ( V_71 -> V_117 + V_167 ) ;
V_163 = & V_161 ;
V_85 = sizeof V_161 ;
break;
case V_24 :
V_162 . V_112 = F_31 ( V_92 * 1000000 + ( V_93 + 500 ) / 1000 ) ;
V_162 . V_105 = F_29 ( V_71 -> V_118 + V_167 ) ;
V_162 . V_106 = F_29 ( V_71 -> V_117 + V_167 ) ;
V_163 = & V_162 ;
V_85 = sizeof V_162 ;
break;
default:
* V_2 = V_170 ;
return FALSE ;
}
V_164 = 0 ;
if ( ! F_32 ( V_150 , V_163 , V_85 , V_2 ) )
return FALSE ;
V_164 += V_85 ;
if ( V_150 -> V_146 == V_74 ) {
memset ( & V_166 . V_173 , 0 , sizeof V_166 . V_173 ) ;
memset ( & V_166 . V_174 , 0 , sizeof V_166 . V_174 ) ;
V_166 . V_137 = F_33 ( V_76 -> V_139 . V_137 ) ;
V_166 . V_138 = F_33 ( V_76 -> V_139 . V_138 ) ;
if ( ! F_32 ( V_150 , & V_166 , sizeof V_166 , V_2 ) )
return FALSE ;
V_164 += sizeof V_166 ;
}
if ( ! F_32 ( V_150 , V_159 , V_71 -> V_117 , V_2 ) )
return FALSE ;
V_164 += V_71 -> V_117 ;
if ( V_150 -> V_146 == V_40 ) {
if ( ! F_32 ( V_150 , & V_165 ,
sizeof V_165 , V_2 ) )
return FALSE ;
V_164 += sizeof V_165 ;
}
if ( V_15 -> V_12 == 0 ) {
V_15 -> V_13 = ( T_4 * ) F_6 ( 1024 * sizeof * V_15 -> V_13 ) ;
V_15 -> V_12 = 1024 ;
} else {
if ( V_15 -> V_157 >= V_15 -> V_12 ) {
V_15 -> V_12 *= 2 ;
V_15 -> V_13 = ( T_4 * ) F_34 ( V_15 -> V_13 ,
V_15 -> V_12 * sizeof * V_15 -> V_13 ) ;
}
}
V_15 -> V_13 [ V_15 -> V_157 ] =
F_29 ( V_15 -> V_10 ) ;
if ( ( T_12 ) V_15 -> V_10 + V_164 > V_175 ) {
V_15 -> V_158 = TRUE ;
}
V_15 -> V_157 ++ ;
V_15 -> V_10 += ( T_4 ) V_164 ;
return TRUE ;
}
static T_13 V_155 ( T_14 * V_150 , int * V_2 )
{
T_15 * V_15 = ( T_15 * ) V_150 -> V_31 ;
T_17 V_176 ;
struct V_6 V_177 ;
const char * V_178 ;
T_17 V_179 ;
struct V_9 * V_9 ;
V_176 = V_15 -> V_157 * sizeof * V_15 -> V_13 ;
if ( ! F_32 ( V_150 , V_15 -> V_13 , V_176 , V_2 ) )
return FALSE ;
if ( F_27 ( V_150 , 0 , V_63 , V_2 ) == - 1 )
return FALSE ;
memset ( & V_177 , '\0' , sizeof V_177 ) ;
switch ( V_150 -> V_30 ) {
case V_23 :
V_178 = V_20 ;
V_179 = sizeof V_20 ;
V_177 . V_22 = 1 ;
V_177 . V_38 = 1 ;
break;
case V_24 :
V_178 = V_21 ;
V_179 = sizeof V_21 ;
V_177 . V_22 = 2 ;
V_177 . V_38 =
( V_150 -> V_146 == V_40 ) ? 1 : 0 ;
break;
default:
if ( V_2 != NULL )
* V_2 = V_170 ;
return FALSE ;
}
if ( ! F_32 ( V_150 , V_178 , V_179 , V_2 ) )
return FALSE ;
if ( V_150 -> V_146 == V_40 ) {
V_177 . V_26 = F_30 ( 1 ) ;
} else
V_177 . V_26 = F_30 ( V_148 [ V_150 -> V_146 ] ) ;
V_9 = localtime ( & V_15 -> V_172 . V_92 ) ;
if ( V_9 != NULL ) {
V_177 . V_43 = F_30 ( 1900 + V_9 -> V_42 ) ;
V_177 . V_45 = F_30 ( V_9 -> V_44 + 1 ) ;
V_177 . V_180 = F_30 ( V_9 -> V_181 ) ;
V_177 . V_47 = F_30 ( V_9 -> V_46 ) ;
V_177 . V_49 = F_30 ( V_9 -> V_48 ) ;
V_177 . V_51 = F_30 ( V_9 -> V_50 ) ;
V_177 . V_53 = F_30 ( V_9 -> V_52 ) ;
} else {
V_177 . V_43 = F_30 ( 1900 + 0 ) ;
V_177 . V_45 = F_30 ( 0 + 1 ) ;
V_177 . V_180 = F_30 ( 0 ) ;
V_177 . V_47 = F_30 ( 0 ) ;
V_177 . V_49 = F_30 ( 0 ) ;
V_177 . V_51 = F_30 ( 0 ) ;
V_177 . V_53 = F_30 ( 0 ) ;
}
V_177 . V_57 = F_30 ( V_15 -> V_172 . V_93 / 1000000 ) ;
V_177 . V_60 = F_29 ( V_15 -> V_10 ) ;
V_177 . V_61 =
F_29 ( V_15 -> V_157 * sizeof * V_15 -> V_13 ) ;
if ( ! F_32 ( V_150 , & V_177 , sizeof V_177 , V_2 ) )
return FALSE ;
return TRUE ;
}
