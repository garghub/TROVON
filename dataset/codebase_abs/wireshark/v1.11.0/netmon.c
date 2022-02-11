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
V_1 -> V_9 = V_9 ;
V_16 = ( T_4 * ) F_7 ( sizeof( T_4 ) ) ;
V_1 -> V_32 = ( void * ) V_16 ;
V_1 -> V_33 = V_34 ;
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = V_38 ;
if( ( V_8 . V_23 == 2 && V_8 . V_39 >= 1 ) || V_8 . V_23 > 2 )
V_1 -> V_40 = V_41 ;
else
V_1 -> V_40 = V_29 [ V_8 . V_27 ] ;
V_1 -> V_42 = 0 ;
V_10 . V_43 = F_6 ( & V_8 . V_44 ) - 1900 ;
V_10 . V_45 = F_6 ( & V_8 . V_46 ) - 1 ;
V_10 . V_47 = F_6 ( & V_8 . V_48 ) ;
V_10 . V_49 = F_6 ( & V_8 . V_50 ) ;
V_10 . V_51 = F_6 ( & V_8 . V_52 ) ;
V_10 . V_53 = F_6 ( & V_8 . V_54 ) ;
V_10 . V_55 = - 1 ;
V_16 -> V_56 = mktime ( & V_10 ) ;
V_16 -> V_57 = F_6 ( & V_8 . V_58 ) * 1000000 ;
V_16 -> V_59 = V_8 . V_23 ;
V_16 -> V_60 = V_8 . V_39 ;
V_16 -> V_13 = 0 ;
V_16 -> V_14 = NULL ;
V_11 = F_8 ( & V_8 . V_61 ) ;
V_12 = F_8 ( & V_8 . V_62 ) ;
V_13 = V_12 / ( T_3 ) sizeof ( T_3 ) ;
if ( ( V_13 * sizeof ( T_3 ) ) != V_12 ) {
* V_2 = V_63 ;
* V_3 = F_5 ( L_3 ,
V_12 ) ;
return - 1 ;
}
if ( V_13 == 0 ) {
* V_2 = V_63 ;
* V_3 = F_5 ( L_4 ,
V_12 ) ;
return - 1 ;
}
if ( V_13 > 512 * 1024 * 1024 ) {
* V_2 = V_63 ;
* V_3 = F_5 ( L_5 ,
V_12 ) ;
return - 1 ;
}
if ( F_9 ( V_1 -> V_19 , V_11 , V_64 , V_2 ) == - 1 ) {
return - 1 ;
}
V_14 = ( T_3 * ) F_10 ( V_12 ) ;
if ( V_12 != 0 && V_14 == NULL ) {
* V_2 = V_65 ;
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
V_16 -> V_66 = 0 ;
switch ( V_16 -> V_59 ) {
case 1 :
V_1 -> V_67 = V_68 ;
break;
case 2 :
V_1 -> V_67 = V_69 ;
break;
}
return 1 ;
}
static T_5
F_12 ( T_4 * V_16 )
{
if ( ( V_16 -> V_59 == 2 && V_16 -> V_60 >= 1 ) ||
V_16 -> V_59 > 2 ) {
if ( V_16 -> V_59 > 2 ) {
return sizeof ( struct V_70 ) ;
} else {
switch ( V_16 -> V_60 ) {
case 1 :
return sizeof ( struct V_71 ) ;
case 2 :
return sizeof ( struct V_72 ) ;
default:
return sizeof ( struct V_70 ) ;
}
}
}
return 0 ;
}
static void
F_13 ( int V_73 ,
union V_74 * V_75 , T_6 * V_76 , int V_77 )
{
T_7 * V_78 = F_14 ( V_76 ) ;
switch ( V_73 ) {
case V_79 :
F_15 ( V_78 , V_77 , V_75 ) ;
break;
case V_80 :
V_75 -> V_81 . V_82 = 0 ;
break;
case V_83 :
V_75 -> V_84 . V_82 = - 2 ;
V_75 -> V_84 . V_85 = FALSE ;
break;
}
}
static T_8 F_16 ( T_1 * V_1 , T_9 V_19 ,
struct V_86 * V_87 , int * V_2 , T_2 * * V_3 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_32 ;
int V_88 = 0 ;
union {
struct V_89 V_90 ;
struct V_91 V_92 ;
} V_8 ;
int V_4 ;
T_10 V_93 = 0 ;
T_10 V_94 ;
T_11 V_95 ;
T_3 V_96 ;
T_3 V_97 = 0 ;
T_3 V_98 = 0 ;
switch ( V_16 -> V_59 ) {
case 1 :
V_88 = sizeof ( struct V_89 ) ;
break;
case 2 :
V_88 = sizeof ( struct V_91 ) ;
break;
}
V_17 = V_18 ;
V_4 = F_3 ( & V_8 , V_88 , V_19 ) ;
if ( V_4 != V_88 ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_20 ;
}
return FALSE ;
}
switch ( V_16 -> V_59 ) {
case 1 :
V_98 = F_6 ( & V_8 . V_90 . V_99 ) ;
V_97 = F_6 ( & V_8 . V_90 . V_100 ) ;
break;
case 2 :
V_98 = F_8 ( & V_8 . V_92 . V_99 ) ;
V_97 = F_8 ( & V_8 . V_92 . V_100 ) ;
break;
}
if ( V_97 > V_101 ) {
* V_2 = V_63 ;
* V_3 = F_5 ( L_6 ,
V_97 , V_101 ) ;
return FALSE ;
}
switch ( V_1 -> V_40 ) {
case V_79 :
if ( V_97 < sizeof ( struct V_102 ) ) {
* V_2 = V_63 ;
* V_3 = F_5 ( L_7 ,
V_97 ) ;
return FALSE ;
}
if ( ! F_17 ( V_19 , & V_87 -> V_75 ,
V_2 , V_3 ) )
return FALSE ;
V_98 -= ( V_103 ) sizeof ( struct V_102 ) ;
V_97 -= ( V_103 ) sizeof ( struct V_102 ) ;
break;
default:
break;
}
switch ( V_16 -> V_59 ) {
case 1 :
V_93 = ( ( T_10 ) F_8 ( & V_8 . V_90 . V_104 ) ) * 1000000 ;
break;
case 2 :
V_93 = F_18 ( & V_8 . V_92 . V_104 ) * 10 ;
V_93 *= 100 ;
break;
}
V_95 = 0 ;
V_94 = V_16 -> V_57 + V_93 ;
while ( V_94 < 0 ) {
V_94 += 1000000000 ;
V_95 -- ;
}
V_95 += ( T_11 ) ( V_94 / 1000000000 ) ;
V_96 = ( T_3 ) ( V_94 % 1000000000 ) ;
V_87 -> V_105 = V_106 | V_107 ;
V_87 -> V_108 . V_95 = V_16 -> V_56 + V_95 ;
V_87 -> V_108 . V_96 = V_96 ;
V_87 -> V_109 = V_97 ;
V_87 -> V_110 = V_98 ;
return TRUE ;
}
static T_12 F_19 ( T_4 * V_16 ,
T_9 V_19 , struct V_86 * V_87 , int * V_2 , T_2 * * V_3 )
{
int V_111 ;
V_111 = ( int ) F_12 ( V_16 ) ;
if ( V_111 != 0 ) {
V_87 -> V_73 = F_20 ( V_19 ,
V_111 , V_2 , V_3 ) ;
if ( V_87 -> V_73 == - 1 )
return V_112 ;
if ( V_87 -> V_73 == 0 )
return V_113 ;
}
return V_114 ;
}
static T_8 V_34 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_10 * V_115 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_32 ;
T_10 V_116 ;
V_117:
if ( V_16 -> V_66 >= V_16 -> V_13 ) {
F_11 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
* V_2 = 0 ;
return FALSE ;
}
V_116 = V_16 -> V_14 [ V_16 -> V_66 ] ;
if ( F_21 ( V_1 -> V_19 ) != V_116 ) {
if ( F_9 ( V_1 -> V_19 , V_116 , V_64 , V_2 ) == - 1 )
return FALSE ;
}
V_16 -> V_66 ++ ;
* V_115 = F_21 ( V_1 -> V_19 ) ;
if ( ! F_16 ( V_1 , V_1 -> V_19 , & V_1 -> V_87 ,
V_2 , V_3 ) )
return FALSE ;
if ( ! F_22 ( V_1 -> V_19 , V_1 -> V_118 ,
V_1 -> V_87 . V_109 , V_2 , V_3 ) )
return FALSE ;
switch ( F_19 ( V_16 , V_1 -> V_19 , & V_1 -> V_87 ,
V_2 , V_3 ) ) {
case V_113 :
goto V_117;
case V_114 :
break;
case V_112 :
return FALSE ;
}
F_13 ( V_1 -> V_87 . V_73 ,
& V_1 -> V_87 . V_75 , V_1 -> V_118 , V_1 -> V_87 . V_109 ) ;
return TRUE ;
}
static T_8
V_36 ( T_1 * V_1 , T_10 V_119 ,
struct V_86 * V_87 , T_6 * V_76 , int V_77 ,
int * V_2 , T_2 * * V_3 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_32 ;
if ( F_9 ( V_1 -> V_120 , V_119 , V_64 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_16 ( V_1 , V_1 -> V_120 , V_87 ,
V_2 , V_3 ) )
return FALSE ;
if ( ! F_22 ( V_1 -> V_120 , V_76 , V_77 , V_2 , V_3 ) )
return FALSE ;
switch ( F_19 ( V_16 , V_1 -> V_120 , V_87 ,
V_2 , V_3 ) ) {
case V_113 :
* V_2 = V_63 ;
* V_3 = F_23 ( L_8 ) ;
return FALSE ;
case V_114 :
break;
case V_112 :
return FALSE ;
}
F_13 ( V_87 -> V_73 ,
& V_87 -> V_75 , V_76 , V_87 -> V_109 ) ;
return TRUE ;
}
static T_8
F_17 ( T_9 V_19 , union V_74 * V_75 ,
int * V_2 , T_2 * * V_3 )
{
struct V_102 V_121 ;
int V_4 ;
T_13 V_122 , V_123 ;
V_17 = V_18 ;
V_4 = F_3 ( & V_121 , sizeof ( struct V_102 ) , V_19 ) ;
if ( V_4 != sizeof ( struct V_102 ) ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_20 ;
return FALSE ;
}
V_122 = F_24 ( V_121 . V_122 ) ;
V_123 = F_24 ( V_121 . V_123 ) ;
V_75 -> V_124 . V_122 = V_122 ;
V_75 -> V_124 . V_123 = V_123 ;
V_75 -> V_124 . V_125 = 0 ;
V_75 -> V_124 . V_126 = 0 ;
V_75 -> V_124 . V_127 = 0 ;
V_75 -> V_124 . V_128 = 0 ;
V_75 -> V_124 . V_129 = 0 ;
V_75 -> V_124 . V_130 = 0 ;
return TRUE ;
}
static int
F_20 ( T_9 V_19 , int V_111 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
union {
struct V_71 V_131 ;
struct V_72 V_132 ;
struct V_70 V_133 ;
} V_134 ;
T_13 V_27 ;
int V_73 ;
V_17 = V_18 ;
V_4 = F_3 ( & V_134 , V_111 , V_19 ) ;
if ( V_4 != V_111 ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_20 ;
}
return - 1 ;
}
V_27 = F_6 ( V_134 . V_131 . V_27 ) ;
if ( ( V_27 & 0xF000 ) == V_135 ) {
V_27 &= 0x0FFF ;
V_73 = F_25 ( V_27 ) ;
if ( V_73 == V_30 ) {
* V_2 = V_31 ;
* V_3 = F_5 ( L_9 ,
V_27 ) ;
return - 1 ;
}
} else if ( V_27 < V_28 ) {
V_73 = V_29 [ V_27 ] ;
if ( V_73 == V_30 ) {
* V_2 = V_31 ;
* V_3 = F_5 ( L_2 ,
V_27 ) ;
return - 1 ;
}
} else {
switch ( V_27 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
return 0 ;
default:
* V_2 = V_31 ;
* V_3 = F_5 ( L_2 ,
V_27 ) ;
return - 1 ;
}
}
return V_73 ;
}
static void
V_38 ( T_1 * V_1 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_32 ;
if ( V_16 -> V_14 != NULL ) {
F_11 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
}
}
int F_26 ( int V_142 )
{
if ( V_142 < 0 || ( unsigned ) V_142 >= V_143 || V_144 [ V_142 ] == - 1 )
return V_31 ;
return 0 ;
}
int F_27 ( int V_142 )
{
if ( V_142 == V_41 )
return 0 ;
if ( V_142 < 0 || ( unsigned ) V_142 >= V_143 || V_144 [ V_142 ] == - 1 )
return V_31 ;
return 0 ;
}
T_8 F_28 ( T_14 * V_145 , int * V_2 )
{
T_15 * V_16 ;
if ( F_29 ( V_145 , V_146 , V_64 , V_2 ) == - 1 )
return FALSE ;
V_145 -> V_147 = V_148 ;
V_145 -> V_149 = V_150 ;
V_16 = ( T_15 * ) F_7 ( sizeof( T_15 ) ) ;
V_145 -> V_32 = ( void * ) V_16 ;
V_16 -> V_11 = V_146 ;
V_16 -> V_151 = FALSE ;
V_16 -> V_14 = NULL ;
V_16 -> V_152 = 0 ;
V_16 -> V_13 = 0 ;
V_16 -> V_153 = FALSE ;
return TRUE ;
}
static T_8 V_148 ( T_14 * V_145 , const struct V_86 * V_87 ,
const T_7 * V_78 , int * V_2 )
{
const union V_74 * V_75 = & V_87 -> V_75 ;
T_15 * V_16 = ( T_15 * ) V_145 -> V_32 ;
struct V_89 V_154 ;
struct V_91 V_155 ;
void * V_156 ;
T_5 V_157 ;
struct V_71 V_158 ;
T_5 V_88 ;
struct V_102 V_159 ;
int V_160 ;
T_10 V_95 ;
T_16 V_96 ;
if ( V_145 -> V_142 == V_41 ) {
if ( V_87 -> V_73 < 0 ||
( unsigned ) V_87 -> V_73 >= V_143 ||
V_144 [ V_87 -> V_73 ] == - 1 ) {
* V_2 = V_31 ;
return FALSE ;
}
F_30 ( V_158 . V_27 , V_144 [ V_87 -> V_73 ] ) ;
}
if ( V_16 -> V_153 ) {
* V_2 = V_161 ;
return FALSE ;
}
if ( ! V_16 -> V_151 ) {
V_16 -> V_162 . V_95 = V_87 -> V_108 . V_95 ;
V_16 -> V_162 . V_96 =
( V_87 -> V_108 . V_96 / 1000000 ) * 1000000 ;
V_16 -> V_151 = TRUE ;
}
if ( V_145 -> V_142 == V_79 )
V_160 = sizeof ( struct V_102 ) ;
else
V_160 = 0 ;
V_95 = ( T_10 ) ( V_87 -> V_108 . V_95 - V_16 -> V_162 . V_95 ) ;
V_96 = V_87 -> V_108 . V_96 - V_16 -> V_162 . V_96 ;
while ( V_96 < 0 ) {
V_96 += 1000000000 ;
V_95 -- ;
}
switch ( V_145 -> V_9 ) {
case V_24 :
V_154 . V_104 = F_31 ( V_95 * 1000 + ( V_96 + 500000 ) / 1000000 ) ;
V_154 . V_99 = F_32 ( V_87 -> V_110 + V_160 ) ;
V_154 . V_100 = F_32 ( V_87 -> V_109 + V_160 ) ;
V_156 = & V_154 ;
V_88 = sizeof V_154 ;
break;
case V_25 :
V_155 . V_104 = F_33 ( V_95 * 1000000 + ( V_96 + 500 ) / 1000 ) ;
V_155 . V_99 = F_31 ( V_87 -> V_110 + V_160 ) ;
V_155 . V_100 = F_31 ( V_87 -> V_109 + V_160 ) ;
V_156 = & V_155 ;
V_88 = sizeof V_155 ;
break;
default:
* V_2 = V_163 ;
return FALSE ;
}
V_157 = 0 ;
if ( ! F_34 ( V_145 , V_156 , V_88 , V_2 ) )
return FALSE ;
V_157 += V_88 ;
if ( V_145 -> V_142 == V_79 ) {
memset ( & V_159 . V_164 , 0 , sizeof V_159 . V_164 ) ;
memset ( & V_159 . V_165 , 0 , sizeof V_159 . V_165 ) ;
V_159 . V_122 = F_35 ( V_75 -> V_124 . V_122 ) ;
V_159 . V_123 = F_35 ( V_75 -> V_124 . V_123 ) ;
if ( ! F_34 ( V_145 , & V_159 , sizeof V_159 , V_2 ) )
return FALSE ;
V_157 += sizeof V_159 ;
}
if ( ! F_34 ( V_145 , V_78 , V_87 -> V_109 , V_2 ) )
return FALSE ;
V_157 += V_87 -> V_109 ;
if ( V_145 -> V_142 == V_41 ) {
if ( ! F_34 ( V_145 , & V_158 ,
sizeof V_158 , V_2 ) )
return FALSE ;
V_157 += sizeof V_158 ;
}
if ( V_16 -> V_13 == 0 ) {
V_16 -> V_14 = ( T_3 * ) F_7 ( 1024 * sizeof * V_16 -> V_14 ) ;
V_16 -> V_13 = 1024 ;
} else {
if ( V_16 -> V_152 >= V_16 -> V_13 ) {
V_16 -> V_13 *= 2 ;
V_16 -> V_14 = ( T_3 * ) F_36 ( V_16 -> V_14 ,
V_16 -> V_13 * sizeof * V_16 -> V_14 ) ;
}
}
V_16 -> V_14 [ V_16 -> V_152 ] =
F_31 ( V_16 -> V_11 ) ;
if ( ( V_166 ) V_16 -> V_11 + V_157 > V_167 ) {
V_16 -> V_153 = TRUE ;
}
V_16 -> V_152 ++ ;
V_16 -> V_11 += ( T_3 ) V_157 ;
return TRUE ;
}
static T_8 V_150 ( T_14 * V_145 , int * V_2 )
{
T_15 * V_16 = ( T_15 * ) V_145 -> V_32 ;
T_5 V_168 ;
struct V_7 V_169 ;
const char * V_170 ;
T_5 V_171 ;
struct V_10 * V_10 ;
V_168 = V_16 -> V_152 * sizeof * V_16 -> V_14 ;
if ( ! F_34 ( V_145 , V_16 -> V_14 , V_168 , V_2 ) )
return FALSE ;
if ( F_29 ( V_145 , 0 , V_64 , V_2 ) == - 1 )
return FALSE ;
memset ( & V_169 , '\0' , sizeof V_169 ) ;
switch ( V_145 -> V_9 ) {
case V_24 :
V_170 = V_21 ;
V_171 = sizeof V_21 ;
V_169 . V_23 = 1 ;
V_169 . V_39 = 1 ;
break;
case V_25 :
V_170 = V_22 ;
V_171 = sizeof V_22 ;
V_169 . V_23 = 2 ;
V_169 . V_39 =
( V_145 -> V_142 == V_41 ) ? 1 : 0 ;
break;
default:
if ( V_2 != NULL )
* V_2 = V_163 ;
return FALSE ;
}
if ( ! F_34 ( V_145 , V_170 , V_171 , V_2 ) )
return FALSE ;
if ( V_145 -> V_142 == V_41 ) {
V_169 . V_27 = F_32 ( 1 ) ;
} else
V_169 . V_27 = F_32 ( V_144 [ V_145 -> V_142 ] ) ;
V_10 = localtime ( & V_16 -> V_162 . V_95 ) ;
if ( V_10 != NULL ) {
V_169 . V_44 = F_32 ( 1900 + V_10 -> V_43 ) ;
V_169 . V_46 = F_32 ( V_10 -> V_45 + 1 ) ;
V_169 . V_172 = F_32 ( V_10 -> V_173 ) ;
V_169 . V_48 = F_32 ( V_10 -> V_47 ) ;
V_169 . V_50 = F_32 ( V_10 -> V_49 ) ;
V_169 . V_52 = F_32 ( V_10 -> V_51 ) ;
V_169 . V_54 = F_32 ( V_10 -> V_53 ) ;
} else {
V_169 . V_44 = F_32 ( 1900 + 0 ) ;
V_169 . V_46 = F_32 ( 0 + 1 ) ;
V_169 . V_172 = F_32 ( 0 ) ;
V_169 . V_48 = F_32 ( 0 ) ;
V_169 . V_50 = F_32 ( 0 ) ;
V_169 . V_52 = F_32 ( 0 ) ;
V_169 . V_54 = F_32 ( 0 ) ;
}
V_169 . V_58 = F_32 ( V_16 -> V_162 . V_96 / 1000000 ) ;
V_169 . V_61 = F_31 ( V_16 -> V_11 ) ;
V_169 . V_62 =
F_31 ( V_16 -> V_152 * sizeof * V_16 -> V_14 ) ;
if ( ! F_34 ( V_145 , & V_169 , sizeof V_169 , V_2 ) )
return FALSE ;
return TRUE ;
}
