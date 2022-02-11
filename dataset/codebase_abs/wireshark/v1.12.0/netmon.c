int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ V_6 ] ;
struct V_7 V_8 ;
int V_9 ;
struct V_10 V_10 ;
T_3 V_11 ;
T_3 V_12 ;
T_3 V_13 ;
T_3 * V_14 ;
#ifdef F_2
unsigned int V_15 ;
#endif
T_4 * V_16 ;
V_17 = V_18 ;
V_4 = F_3 ( V_5 , V_6 , V_1 -> V_19 ) ;
if ( V_4 != V_6 ) {
* V_2 = F_4 ( V_1 -> V_19 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_20 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , V_21 , V_6 ) != 0 &&
memcmp ( V_5 , V_22 , V_6 ) != 0 ) {
return 0 ;
}
V_17 = V_18 ;
V_4 = F_3 ( & V_8 , sizeof V_8 , V_1 -> V_19 ) ;
if ( V_4 != sizeof V_8 ) {
* V_2 = F_4 ( V_1 -> V_19 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_20 ;
return - 1 ;
}
switch ( V_8 . V_23 ) {
case 1 :
V_9 = V_24 ;
break;
case 2 :
V_9 = V_25 ;
break;
default:
* V_2 = V_26 ;
* V_3 = F_5 ( L_1 , V_8 . V_23 ) ;
return - 1 ;
}
V_8 . V_27 = F_6 ( & V_8 . V_27 ) ;
if ( V_8 . V_27 >= V_28
|| V_29 [ V_8 . V_27 ] == V_30 ) {
* V_2 = V_31 ;
* V_3 = F_5 ( L_2 ,
V_8 . V_27 ) ;
return - 1 ;
}
V_1 -> V_32 = V_9 ;
V_16 = ( T_4 * ) F_7 ( sizeof( T_4 ) ) ;
V_1 -> V_33 = ( void * ) V_16 ;
V_1 -> V_34 = V_35 ;
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = V_39 ;
if( ( V_8 . V_23 == 2 && V_8 . V_40 >= 1 ) || V_8 . V_23 > 2 )
V_1 -> V_41 = V_42 ;
else
V_1 -> V_41 = V_29 [ V_8 . V_27 ] ;
V_1 -> V_43 = 0 ;
V_10 . V_44 = F_6 ( & V_8 . V_45 ) - 1900 ;
V_10 . V_46 = F_6 ( & V_8 . V_47 ) - 1 ;
V_10 . V_48 = F_6 ( & V_8 . V_49 ) ;
V_10 . V_50 = F_6 ( & V_8 . V_51 ) ;
V_10 . V_52 = F_6 ( & V_8 . V_53 ) ;
V_10 . V_54 = F_6 ( & V_8 . V_55 ) ;
V_10 . V_56 = - 1 ;
V_16 -> V_57 = mktime ( & V_10 ) ;
V_16 -> V_58 = F_6 ( & V_8 . V_59 ) * 1000000 ;
V_16 -> V_60 = V_8 . V_23 ;
V_16 -> V_61 = V_8 . V_40 ;
V_16 -> V_13 = 0 ;
V_16 -> V_14 = NULL ;
V_11 = F_8 ( & V_8 . V_62 ) ;
V_12 = F_8 ( & V_8 . V_63 ) ;
V_13 = V_12 / ( T_3 ) sizeof ( T_3 ) ;
if ( ( V_13 * sizeof ( T_3 ) ) != V_12 ) {
* V_2 = V_64 ;
* V_3 = F_5 ( L_3 ,
V_12 ) ;
return - 1 ;
}
if ( V_13 == 0 ) {
* V_2 = V_64 ;
* V_3 = F_5 ( L_4 ,
V_12 ) ;
return - 1 ;
}
if ( V_13 > 512 * 1024 * 1024 ) {
* V_2 = V_64 ;
* V_3 = F_5 ( L_5 ,
V_12 ) ;
return - 1 ;
}
if ( F_9 ( V_1 -> V_19 , V_11 , V_65 , V_2 ) == - 1 ) {
return - 1 ;
}
V_14 = ( T_3 * ) F_10 ( V_12 ) ;
if ( V_12 != 0 && V_14 == NULL ) {
* V_2 = V_66 ;
return - 1 ;
}
V_17 = V_18 ;
V_4 = F_3 ( V_14 , V_12 , V_1 -> V_19 ) ;
if ( ( T_3 ) V_4 != V_12 ) {
* V_2 = F_4 ( V_1 -> V_19 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_20 ;
F_11 ( V_14 ) ;
return - 1 ;
}
V_16 -> V_13 = V_13 ;
V_16 -> V_14 = V_14 ;
#ifdef F_2
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ )
V_14 [ V_15 ] = F_8 ( & V_14 [ V_15 ] ) ;
#endif
V_16 -> V_67 = 0 ;
switch ( V_16 -> V_60 ) {
case 1 :
V_1 -> V_68 = V_69 ;
break;
case 2 :
V_1 -> V_68 = V_70 ;
break;
}
return 1 ;
}
static void
F_12 ( struct V_71 * V_72 , T_5 * V_73 )
{
switch ( V_72 -> V_74 ) {
case V_75 :
F_13 ( V_72 , F_14 ( V_73 ) ) ;
break;
case V_76 :
V_72 -> V_77 . V_78 . V_79 = 0 ;
break;
case V_80 :
V_72 -> V_77 . V_81 . V_79 = - 2 ;
V_72 -> V_77 . V_81 . V_82 = FALSE ;
break;
}
}
static T_6
F_15 ( T_1 * V_1 , T_7 V_19 , struct V_71 * V_72 ,
T_5 * V_73 , int * V_2 , T_2 * * V_3 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_33 ;
int V_83 = 0 ;
union {
struct V_84 V_85 ;
struct V_86 V_87 ;
} V_8 ;
int V_4 ;
T_8 V_88 = 0 ;
T_8 V_89 ;
T_9 V_90 ;
int V_91 ;
T_3 V_92 = 0 ;
T_3 V_93 = 0 ;
int V_94 ;
union {
struct V_95 V_96 ;
struct V_97 V_98 ;
struct V_99 V_100 ;
} V_101 ;
T_10 V_27 ;
int V_74 ;
switch ( V_16 -> V_60 ) {
case 1 :
V_83 = sizeof ( struct V_84 ) ;
break;
case 2 :
V_83 = sizeof ( struct V_86 ) ;
break;
}
V_17 = V_18 ;
V_4 = F_3 ( & V_8 , V_83 , V_19 ) ;
if ( V_4 != V_83 ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_20 ;
}
return V_102 ;
}
switch ( V_16 -> V_60 ) {
case 1 :
V_93 = F_6 ( & V_8 . V_85 . V_103 ) ;
V_92 = F_6 ( & V_8 . V_85 . V_104 ) ;
break;
case 2 :
V_93 = F_8 ( & V_8 . V_87 . V_103 ) ;
V_92 = F_8 ( & V_8 . V_87 . V_104 ) ;
break;
}
if ( V_92 > V_105 ) {
* V_2 = V_64 ;
* V_3 = F_5 ( L_6 ,
V_92 , V_105 ) ;
return V_102 ;
}
V_72 -> V_106 = V_107 ;
switch ( V_1 -> V_41 ) {
case V_75 :
if ( V_92 < sizeof ( struct V_108 ) ) {
* V_2 = V_64 ;
* V_3 = F_5 ( L_7 ,
V_92 ) ;
return V_102 ;
}
if ( ! F_16 ( V_19 , & V_72 -> V_77 ,
V_2 , V_3 ) )
return V_102 ;
V_93 -= ( V_109 ) sizeof ( struct V_108 ) ;
V_92 -= ( V_109 ) sizeof ( struct V_108 ) ;
break;
default:
break;
}
switch ( V_16 -> V_60 ) {
case 1 :
V_88 = ( ( T_8 ) F_8 ( & V_8 . V_85 . V_110 ) ) * 1000000 ;
break;
case 2 :
V_88 = F_17 ( & V_8 . V_87 . V_110 ) * 10 ;
V_88 *= 100 ;
break;
}
V_90 = 0 ;
V_89 = V_16 -> V_58 + V_88 ;
while ( V_89 < 0 ) {
V_89 += 1000000000 ;
V_90 -- ;
}
V_90 += ( T_9 ) ( V_89 / 1000000000 ) ;
V_91 = ( int ) ( V_89 % 1000000000 ) ;
V_72 -> V_111 = V_112 | V_113 ;
V_72 -> V_114 . V_90 = V_16 -> V_57 + V_90 ;
V_72 -> V_114 . V_91 = V_91 ;
V_72 -> V_115 = V_92 ;
V_72 -> V_116 = V_93 ;
if ( ! F_18 ( V_19 , V_73 , V_72 -> V_115 , V_2 , V_3 ) )
return V_102 ;
if ( ( V_16 -> V_60 == 2 && V_16 -> V_61 >= 1 ) ||
V_16 -> V_60 > 2 ) {
if ( V_16 -> V_60 > 2 ) {
V_94 = ( int ) sizeof ( struct V_99 ) ;
} else {
switch ( V_16 -> V_61 ) {
case 1 :
V_94 = ( int ) sizeof ( struct V_95 ) ;
break;
case 2 :
V_94 = ( int ) sizeof ( struct V_97 ) ;
break;
default:
V_94 = ( int ) sizeof ( struct V_99 ) ;
break;
}
}
V_17 = V_18 ;
V_4 = F_3 ( & V_101 , V_94 , V_19 ) ;
if ( V_4 != V_94 ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_20 ;
}
return V_102 ;
}
V_27 = F_6 ( V_101 . V_96 . V_27 ) ;
if ( ( V_27 & 0xF000 ) == V_117 ) {
V_27 &= 0x0FFF ;
V_74 = F_19 ( V_27 ) ;
if ( V_74 == V_30 ) {
* V_2 = V_31 ;
* V_3 = F_5 ( L_8 ,
V_27 ) ;
return V_102 ;
}
} else if ( V_27 < V_28 ) {
V_74 = V_29 [ V_27 ] ;
if ( V_74 == V_30 ) {
* V_2 = V_31 ;
* V_3 = F_5 ( L_2 ,
V_27 ) ;
return V_102 ;
}
} else {
switch ( V_27 ) {
case V_118 :
return V_119 ;
case V_120 :
return V_119 ;
case V_121 :
return V_119 ;
case V_122 :
return V_119 ;
case V_123 :
return V_119 ;
case V_124 :
return V_119 ;
default:
* V_2 = V_31 ;
* V_3 = F_5 ( L_2 ,
V_27 ) ;
return V_102 ;
}
}
V_72 -> V_74 = V_74 ;
if ( V_16 -> V_60 > 2 || V_16 -> V_61 > 2 ) {
T_11 V_125 ;
T_8 V_126 ;
T_9 V_127 = V_128 ;
T_9 V_129 = V_130 ;
V_125 = F_17 ( V_101 . V_100 . V_131 ) ;
V_126 = V_125 / 10000000 ;
V_91 = ( int ) ( ( V_125 % 10000000 ) * 100 ) ;
V_126 -= V_132 ;
if ( ! ( V_127 <= V_90 && V_90 <= V_129 ) ) {
* V_2 = V_64 ;
* V_3 = F_5 ( L_9 ) ;
return V_102 ;
}
V_72 -> V_114 . V_90 = ( T_9 ) V_126 ;
V_72 -> V_114 . V_91 = V_91 ;
}
}
F_12 ( V_72 , V_73 ) ;
return V_133 ;
}
static T_12 V_35 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_8 * V_134 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_33 ;
T_8 V_135 ;
for (; ; ) {
if ( V_16 -> V_67 >= V_16 -> V_13 ) {
F_11 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
* V_2 = 0 ;
return FALSE ;
}
V_135 = V_16 -> V_14 [ V_16 -> V_67 ] ;
if ( F_20 ( V_1 -> V_19 ) != V_135 ) {
if ( F_9 ( V_1 -> V_19 , V_135 , V_65 , V_2 ) == - 1 )
return FALSE ;
}
V_16 -> V_67 ++ ;
* V_134 = F_20 ( V_1 -> V_19 ) ;
switch ( F_15 ( V_1 , V_1 -> V_19 , & V_1 -> V_72 ,
V_1 -> V_136 , V_2 , V_3 ) ) {
case V_119 :
continue;
case V_133 :
return TRUE ;
case V_102 :
return FALSE ;
}
}
}
static T_12
V_37 ( T_1 * V_1 , T_8 V_137 ,
struct V_71 * V_72 , T_5 * V_73 , int * V_2 , T_2 * * V_3 )
{
if ( F_9 ( V_1 -> V_138 , V_137 , V_65 , V_2 ) == - 1 )
return FALSE ;
switch ( F_15 ( V_1 , V_1 -> V_138 , V_72 , V_73 , V_2 ,
V_3 ) ) {
default:
* V_2 = V_64 ;
* V_3 = F_21 ( L_10 ) ;
return FALSE ;
case V_133 :
return TRUE ;
case V_102 :
return FALSE ;
}
}
static T_12
F_16 ( T_7 V_19 , union V_139 * V_77 ,
int * V_2 , T_2 * * V_3 )
{
struct V_108 V_140 ;
int V_4 ;
T_10 V_141 , V_142 ;
V_17 = V_18 ;
V_4 = F_3 ( & V_140 , sizeof ( struct V_108 ) , V_19 ) ;
if ( V_4 != sizeof ( struct V_108 ) ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_20 ;
return FALSE ;
}
V_141 = F_22 ( V_140 . V_141 ) ;
V_142 = F_22 ( V_140 . V_142 ) ;
V_77 -> V_143 . V_141 = V_141 ;
V_77 -> V_143 . V_142 = V_142 ;
V_77 -> V_143 . V_144 = 0 ;
V_77 -> V_143 . V_145 = 0 ;
V_77 -> V_143 . V_146 = 0 ;
V_77 -> V_143 . V_147 = 0 ;
V_77 -> V_143 . V_148 = 0 ;
V_77 -> V_143 . V_149 = 0 ;
return TRUE ;
}
static void
V_39 ( T_1 * V_1 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_33 ;
if ( V_16 -> V_14 != NULL ) {
F_11 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
}
}
int F_23 ( int V_150 )
{
if ( V_150 < 0 || ( unsigned ) V_150 >= V_151 || V_152 [ V_150 ] == - 1 )
return V_31 ;
return 0 ;
}
int F_24 ( int V_150 )
{
if ( V_150 == V_42 )
return 0 ;
if ( V_150 < 0 || ( unsigned ) V_150 >= V_151 || V_152 [ V_150 ] == - 1 )
return V_31 ;
return 0 ;
}
T_12 F_25 ( T_13 * V_153 , int * V_2 )
{
T_14 * V_16 ;
if ( F_26 ( V_153 , V_154 , V_65 , V_2 ) == - 1 )
return FALSE ;
V_153 -> V_155 = V_156 ;
V_153 -> V_157 = V_158 ;
V_16 = ( T_14 * ) F_7 ( sizeof( T_14 ) ) ;
V_153 -> V_33 = ( void * ) V_16 ;
V_16 -> V_11 = V_154 ;
V_16 -> V_159 = FALSE ;
V_16 -> V_14 = NULL ;
V_16 -> V_160 = 0 ;
V_16 -> V_13 = 0 ;
V_16 -> V_161 = FALSE ;
return TRUE ;
}
static T_12 V_156 ( T_13 * V_153 , const struct V_71 * V_72 ,
const T_15 * V_162 , int * V_2 )
{
const union V_139 * V_77 = & V_72 -> V_77 ;
T_14 * V_16 = ( T_14 * ) V_153 -> V_33 ;
struct V_84 V_163 ;
struct V_86 V_164 ;
void * V_165 ;
T_16 V_166 ;
struct V_95 V_167 ;
T_16 V_83 ;
struct V_108 V_168 ;
int V_169 ;
T_8 V_90 ;
T_17 V_91 ;
if ( V_72 -> V_106 != V_107 ) {
* V_2 = V_170 ;
return FALSE ;
}
switch ( V_153 -> V_32 ) {
case V_24 :
if ( V_72 -> V_115 > 65535 ) {
* V_2 = V_171 ;
return FALSE ;
}
break;
case V_25 :
if ( V_72 -> V_115 > V_105 ) {
* V_2 = V_171 ;
return FALSE ;
}
break;
default:
* V_2 = V_172 ;
return FALSE ;
}
if ( V_153 -> V_150 == V_42 ) {
if ( V_72 -> V_74 < 0 ||
( unsigned ) V_72 -> V_74 >= V_151 ||
V_152 [ V_72 -> V_74 ] == - 1 ) {
* V_2 = V_31 ;
return FALSE ;
}
F_27 ( V_167 . V_27 , V_152 [ V_72 -> V_74 ] ) ;
}
if ( V_16 -> V_161 ) {
* V_2 = V_173 ;
return FALSE ;
}
if ( ! V_16 -> V_159 ) {
V_16 -> V_174 . V_90 = V_72 -> V_114 . V_90 ;
V_16 -> V_174 . V_91 =
( V_72 -> V_114 . V_91 / 1000000 ) * 1000000 ;
V_16 -> V_159 = TRUE ;
}
if ( V_153 -> V_150 == V_75 )
V_169 = sizeof ( struct V_108 ) ;
else
V_169 = 0 ;
V_90 = ( T_8 ) ( V_72 -> V_114 . V_90 - V_16 -> V_174 . V_90 ) ;
V_91 = V_72 -> V_114 . V_91 - V_16 -> V_174 . V_91 ;
while ( V_91 < 0 ) {
V_91 += 1000000000 ;
V_90 -- ;
}
switch ( V_153 -> V_32 ) {
case V_24 :
V_163 . V_110 = F_28 ( V_90 * 1000 + ( V_91 + 500000 ) / 1000000 ) ;
V_163 . V_103 = F_29 ( V_72 -> V_116 + V_169 ) ;
V_163 . V_104 = F_29 ( V_72 -> V_115 + V_169 ) ;
V_165 = & V_163 ;
V_83 = sizeof V_163 ;
break;
case V_25 :
V_164 . V_110 = F_30 ( V_90 * 1000000 + ( V_91 + 500 ) / 1000 ) ;
V_164 . V_103 = F_28 ( V_72 -> V_116 + V_169 ) ;
V_164 . V_104 = F_28 ( V_72 -> V_115 + V_169 ) ;
V_165 = & V_164 ;
V_83 = sizeof V_164 ;
break;
default:
* V_2 = V_172 ;
return FALSE ;
}
V_166 = 0 ;
if ( ! F_31 ( V_153 , V_165 , V_83 , V_2 ) )
return FALSE ;
V_166 += V_83 ;
if ( V_153 -> V_150 == V_75 ) {
memset ( & V_168 . V_175 , 0 , sizeof V_168 . V_175 ) ;
memset ( & V_168 . V_176 , 0 , sizeof V_168 . V_176 ) ;
V_168 . V_141 = F_32 ( V_77 -> V_143 . V_141 ) ;
V_168 . V_142 = F_32 ( V_77 -> V_143 . V_142 ) ;
if ( ! F_31 ( V_153 , & V_168 , sizeof V_168 , V_2 ) )
return FALSE ;
V_166 += sizeof V_168 ;
}
if ( ! F_31 ( V_153 , V_162 , V_72 -> V_115 , V_2 ) )
return FALSE ;
V_166 += V_72 -> V_115 ;
if ( V_153 -> V_150 == V_42 ) {
if ( ! F_31 ( V_153 , & V_167 ,
sizeof V_167 , V_2 ) )
return FALSE ;
V_166 += sizeof V_167 ;
}
if ( V_16 -> V_13 == 0 ) {
V_16 -> V_14 = ( T_3 * ) F_7 ( 1024 * sizeof * V_16 -> V_14 ) ;
V_16 -> V_13 = 1024 ;
} else {
if ( V_16 -> V_160 >= V_16 -> V_13 ) {
V_16 -> V_13 *= 2 ;
V_16 -> V_14 = ( T_3 * ) F_33 ( V_16 -> V_14 ,
V_16 -> V_13 * sizeof * V_16 -> V_14 ) ;
}
}
V_16 -> V_14 [ V_16 -> V_160 ] =
F_28 ( V_16 -> V_11 ) ;
if ( ( T_11 ) V_16 -> V_11 + V_166 > V_177 ) {
V_16 -> V_161 = TRUE ;
}
V_16 -> V_160 ++ ;
V_16 -> V_11 += ( T_3 ) V_166 ;
return TRUE ;
}
static T_12 V_158 ( T_13 * V_153 , int * V_2 )
{
T_14 * V_16 = ( T_14 * ) V_153 -> V_33 ;
T_16 V_178 ;
struct V_7 V_179 ;
const char * V_180 ;
T_16 V_181 ;
struct V_10 * V_10 ;
V_178 = V_16 -> V_160 * sizeof * V_16 -> V_14 ;
if ( ! F_31 ( V_153 , V_16 -> V_14 , V_178 , V_2 ) )
return FALSE ;
if ( F_26 ( V_153 , 0 , V_65 , V_2 ) == - 1 )
return FALSE ;
memset ( & V_179 , '\0' , sizeof V_179 ) ;
switch ( V_153 -> V_32 ) {
case V_24 :
V_180 = V_21 ;
V_181 = sizeof V_21 ;
V_179 . V_23 = 1 ;
V_179 . V_40 = 1 ;
break;
case V_25 :
V_180 = V_22 ;
V_181 = sizeof V_22 ;
V_179 . V_23 = 2 ;
V_179 . V_40 =
( V_153 -> V_150 == V_42 ) ? 1 : 0 ;
break;
default:
if ( V_2 != NULL )
* V_2 = V_172 ;
return FALSE ;
}
if ( ! F_31 ( V_153 , V_180 , V_181 , V_2 ) )
return FALSE ;
if ( V_153 -> V_150 == V_42 ) {
V_179 . V_27 = F_29 ( 1 ) ;
} else
V_179 . V_27 = F_29 ( V_152 [ V_153 -> V_150 ] ) ;
V_10 = localtime ( & V_16 -> V_174 . V_90 ) ;
if ( V_10 != NULL ) {
V_179 . V_45 = F_29 ( 1900 + V_10 -> V_44 ) ;
V_179 . V_47 = F_29 ( V_10 -> V_46 + 1 ) ;
V_179 . V_182 = F_29 ( V_10 -> V_183 ) ;
V_179 . V_49 = F_29 ( V_10 -> V_48 ) ;
V_179 . V_51 = F_29 ( V_10 -> V_50 ) ;
V_179 . V_53 = F_29 ( V_10 -> V_52 ) ;
V_179 . V_55 = F_29 ( V_10 -> V_54 ) ;
} else {
V_179 . V_45 = F_29 ( 1900 + 0 ) ;
V_179 . V_47 = F_29 ( 0 + 1 ) ;
V_179 . V_182 = F_29 ( 0 ) ;
V_179 . V_49 = F_29 ( 0 ) ;
V_179 . V_51 = F_29 ( 0 ) ;
V_179 . V_53 = F_29 ( 0 ) ;
V_179 . V_55 = F_29 ( 0 ) ;
}
V_179 . V_59 = F_29 ( V_16 -> V_174 . V_91 / 1000000 ) ;
V_179 . V_62 = F_28 ( V_16 -> V_11 ) ;
V_179 . V_63 =
F_28 ( V_16 -> V_160 * sizeof * V_16 -> V_14 ) ;
if ( ! F_31 ( V_153 , & V_179 , sizeof V_179 , V_2 ) )
return FALSE ;
return TRUE ;
}
