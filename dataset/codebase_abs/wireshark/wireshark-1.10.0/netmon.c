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
V_14 = ( T_3 * ) F_7 ( V_12 ) ;
V_17 = V_18 ;
V_4 = F_3 ( V_14 , V_12 , V_1 -> V_19 ) ;
if ( ( T_3 ) V_4 != V_12 ) {
* V_2 = F_4 ( V_1 -> V_19 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_20 ;
F_10 ( V_14 ) ;
return - 1 ;
}
V_16 -> V_13 = V_13 ;
V_16 -> V_14 = V_14 ;
#ifdef F_2
for ( V_15 = 0 ; V_15 < V_13 ; V_15 ++ )
V_14 [ V_15 ] = F_8 ( & V_14 [ V_15 ] ) ;
#endif
V_16 -> V_65 = 0 ;
switch ( V_16 -> V_59 ) {
case 1 :
V_1 -> V_66 = V_67 ;
break;
case 2 :
V_1 -> V_66 = V_68 ;
break;
}
return 1 ;
}
static T_5
F_11 ( T_4 * V_16 )
{
if ( ( V_16 -> V_59 == 2 && V_16 -> V_60 >= 1 ) ||
V_16 -> V_59 > 2 ) {
if ( V_16 -> V_59 > 2 ) {
return sizeof ( struct V_69 ) ;
} else {
switch ( V_16 -> V_60 ) {
case 1 :
return sizeof ( struct V_70 ) ;
case 2 :
return sizeof ( struct V_71 ) ;
default:
return sizeof ( struct V_69 ) ;
}
}
}
return 0 ;
}
static void
F_12 ( int V_72 ,
union V_73 * V_74 , T_6 * V_75 , int V_76 )
{
switch ( V_72 ) {
case V_77 :
F_13 ( V_75 , V_76 , V_74 ) ;
break;
case V_78 :
V_74 -> V_79 . V_80 = 0 ;
break;
case V_81 :
V_74 -> V_82 . V_80 = - 2 ;
V_74 -> V_82 . V_83 = FALSE ;
break;
}
}
static T_7 V_34 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_8 * V_84 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_32 ;
T_3 V_85 = 0 ;
T_3 V_86 = 0 ;
int V_4 ;
union {
struct V_87 V_88 ;
struct V_89 V_90 ;
} V_8 ;
int V_91 = 0 ;
int V_92 ;
T_8 V_93 ;
T_6 * V_94 ;
T_8 V_95 = 0 ;
T_8 V_96 ;
T_9 V_97 ;
T_3 V_98 ;
V_99:
if ( V_16 -> V_65 >= V_16 -> V_13 ) {
F_10 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
* V_2 = 0 ;
return FALSE ;
}
V_93 = V_16 -> V_14 [ V_16 -> V_65 ] ;
if ( F_14 ( V_1 -> V_19 ) != V_93 ) {
if ( F_9 ( V_1 -> V_19 , V_93 , V_64 , V_2 ) == - 1 )
return FALSE ;
}
V_16 -> V_65 ++ ;
switch ( V_16 -> V_59 ) {
case 1 :
V_91 = sizeof ( struct V_87 ) ;
break;
case 2 :
V_91 = sizeof ( struct V_89 ) ;
break;
}
V_17 = V_18 ;
V_4 = F_3 ( & V_8 , V_91 , V_1 -> V_19 ) ;
if ( V_4 != V_91 ) {
* V_2 = F_4 ( V_1 -> V_19 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_20 ;
}
return FALSE ;
}
switch ( V_16 -> V_59 ) {
case 1 :
V_86 = F_6 ( & V_8 . V_88 . V_100 ) ;
V_85 = F_6 ( & V_8 . V_88 . V_101 ) ;
break;
case 2 :
V_86 = F_8 ( & V_8 . V_90 . V_100 ) ;
V_85 = F_8 ( & V_8 . V_90 . V_101 ) ;
break;
}
if ( V_85 > V_102 ) {
* V_2 = V_63 ;
* V_3 = F_5 ( L_6 ,
V_85 , V_102 ) ;
return FALSE ;
}
* V_84 = F_14 ( V_1 -> V_19 ) ;
switch ( V_1 -> V_40 ) {
case V_77 :
if ( V_85 < sizeof ( struct V_103 ) ) {
* V_2 = V_63 ;
* V_3 = F_5 ( L_7 ,
V_85 ) ;
return FALSE ;
}
if ( ! F_15 ( V_1 -> V_19 , & V_1 -> V_104 . V_74 ,
V_2 , V_3 ) )
return FALSE ;
V_86 -= ( V_105 ) sizeof ( struct V_103 ) ;
V_85 -= ( V_105 ) sizeof ( struct V_103 ) ;
break;
default:
break;
}
F_16 ( V_1 -> V_106 , V_85 ) ;
V_94 = F_17 ( V_1 -> V_106 ) ;
if ( ! F_18 ( V_1 -> V_19 , V_94 , V_85 , V_2 ,
V_3 ) )
return FALSE ;
switch ( V_16 -> V_59 ) {
case 1 :
V_95 = ( ( T_8 ) F_8 ( & V_8 . V_88 . V_107 ) ) * 1000000 ;
break;
case 2 :
V_95 = F_19 ( & V_8 . V_90 . V_107 ) * 10 ;
V_95 *= 100 ;
break;
}
V_97 = 0 ;
V_96 = V_16 -> V_57 + V_95 ;
while ( V_96 < 0 ) {
V_96 += 1000000000 ;
V_97 -- ;
}
V_97 += ( T_9 ) ( V_96 / 1000000000 ) ;
V_98 = ( T_3 ) ( V_96 % 1000000000 ) ;
V_1 -> V_104 . V_108 = V_109 | V_110 ;
V_1 -> V_104 . V_111 . V_97 = V_16 -> V_56 + V_97 ;
V_1 -> V_104 . V_111 . V_98 = V_98 ;
V_1 -> V_104 . V_112 = V_85 ;
V_1 -> V_104 . V_113 = V_86 ;
V_92 = ( int ) F_11 ( V_16 ) ;
if ( V_92 != 0 ) {
V_1 -> V_104 . V_72 = F_20 ( V_1 -> V_19 ,
V_92 , V_2 , V_3 ) ;
if ( V_1 -> V_104 . V_72 == - 1 )
return FALSE ;
if ( V_1 -> V_104 . V_72 == 0 )
goto V_99;
F_12 ( V_1 -> V_104 . V_72 ,
& V_1 -> V_104 . V_74 , V_94 , V_85 ) ;
} else {
F_12 ( V_1 -> V_40 ,
& V_1 -> V_104 . V_74 , V_94 , V_85 ) ;
}
return TRUE ;
}
static T_7
V_36 ( T_1 * V_1 , T_8 V_114 ,
struct V_115 * V_104 , T_6 * V_75 , int V_76 ,
int * V_2 , T_2 * * V_3 )
{
union V_73 * V_74 = & V_104 -> V_74 ;
T_4 * V_16 = ( T_4 * ) V_1 -> V_32 ;
int V_92 ;
int V_72 ;
if ( F_9 ( V_1 -> V_116 , V_114 , V_64 , V_2 ) == - 1 )
return FALSE ;
switch ( V_1 -> V_40 ) {
case V_77 :
if ( ! F_15 ( V_1 -> V_116 , V_74 ,
V_2 , V_3 ) ) {
return FALSE ;
}
break;
}
if ( ! F_18 ( V_1 -> V_116 , V_75 , V_76 , V_2 , V_3 ) )
return FALSE ;
V_92 = ( int ) F_11 ( V_16 ) ;
if ( V_92 != 0 ) {
V_72 = F_20 ( V_1 -> V_116 ,
V_92 , V_2 , V_3 ) ;
if ( V_72 == - 1 )
return FALSE ;
if ( V_72 == 0 ) {
* V_2 = V_63 ;
* V_3 = F_21 ( L_8 ) ;
return FALSE ;
}
F_12 ( V_72 , V_74 ,
V_75 , V_76 ) ;
} else {
F_12 ( V_1 -> V_40 , V_74 ,
V_75 , V_76 ) ;
}
return TRUE ;
}
static T_7
F_15 ( T_10 V_19 , union V_73 * V_74 ,
int * V_2 , T_2 * * V_3 )
{
struct V_103 V_117 ;
int V_4 ;
T_11 V_118 , V_119 ;
V_17 = V_18 ;
V_4 = F_3 ( & V_117 , sizeof ( struct V_103 ) , V_19 ) ;
if ( V_4 != sizeof ( struct V_103 ) ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_20 ;
return FALSE ;
}
V_118 = F_22 ( V_117 . V_118 ) ;
V_119 = F_22 ( V_117 . V_119 ) ;
V_74 -> V_120 . V_118 = V_118 ;
V_74 -> V_120 . V_119 = V_119 ;
V_74 -> V_120 . V_121 = 0 ;
V_74 -> V_120 . V_122 = 0 ;
V_74 -> V_120 . V_123 = 0 ;
V_74 -> V_120 . V_124 = 0 ;
V_74 -> V_120 . V_125 = 0 ;
V_74 -> V_120 . V_126 = 0 ;
return TRUE ;
}
static T_7
F_18 ( T_10 V_19 , T_6 * V_75 , int V_76 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_17 = V_18 ;
V_4 = F_3 ( V_75 , V_76 , V_19 ) ;
if ( V_4 != V_76 ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_20 ;
return FALSE ;
}
return TRUE ;
}
static int
F_20 ( T_10 V_19 , int V_92 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
union {
struct V_70 V_127 ;
struct V_71 V_128 ;
struct V_69 V_129 ;
} V_130 ;
T_11 V_27 ;
int V_72 ;
V_17 = V_18 ;
V_4 = F_3 ( & V_130 , V_92 , V_19 ) ;
if ( V_4 != V_92 ) {
* V_2 = F_4 ( V_19 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_20 ;
}
return - 1 ;
}
V_27 = F_6 ( V_130 . V_127 . V_27 ) ;
if ( ( V_27 & 0xF000 ) == V_131 ) {
V_27 &= 0x0FFF ;
V_72 = F_23 ( V_27 ) ;
if ( V_72 == V_30 ) {
* V_2 = V_31 ;
* V_3 = F_5 ( L_9 ,
V_27 ) ;
return - 1 ;
}
} else if ( V_27 < V_28 ) {
V_72 = V_29 [ V_27 ] ;
if ( V_72 == V_30 ) {
* V_2 = V_31 ;
* V_3 = F_5 ( L_2 ,
V_27 ) ;
return - 1 ;
}
} else {
switch ( V_27 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
return 0 ;
default:
* V_2 = V_31 ;
* V_3 = F_5 ( L_2 ,
V_27 ) ;
return - 1 ;
}
}
return V_72 ;
}
static void
V_38 ( T_1 * V_1 )
{
T_4 * V_16 = ( T_4 * ) V_1 -> V_32 ;
if ( V_16 -> V_14 != NULL ) {
F_10 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
}
}
int F_24 ( int V_138 )
{
if ( V_138 < 0 || ( unsigned ) V_138 >= V_139 || V_140 [ V_138 ] == - 1 )
return V_31 ;
return 0 ;
}
int F_25 ( int V_138 )
{
if ( V_138 == V_41 )
return 0 ;
if ( V_138 < 0 || ( unsigned ) V_138 >= V_139 || V_140 [ V_138 ] == - 1 )
return V_31 ;
return 0 ;
}
T_7 F_26 ( T_12 * V_141 , int * V_2 )
{
T_13 * V_16 ;
if ( F_27 ( V_141 , V_142 , V_64 , V_2 ) == - 1 )
return FALSE ;
V_141 -> V_143 = V_144 ;
V_141 -> V_145 = V_146 ;
V_16 = ( T_13 * ) F_7 ( sizeof( T_13 ) ) ;
V_141 -> V_32 = ( void * ) V_16 ;
V_16 -> V_11 = V_142 ;
V_16 -> V_147 = FALSE ;
V_16 -> V_14 = NULL ;
V_16 -> V_148 = 0 ;
V_16 -> V_13 = 0 ;
V_16 -> V_149 = FALSE ;
return TRUE ;
}
static T_7 V_144 ( T_12 * V_141 , const struct V_115 * V_104 ,
const T_6 * V_75 , int * V_2 )
{
const union V_73 * V_74 = & V_104 -> V_74 ;
T_13 * V_16 = ( T_13 * ) V_141 -> V_32 ;
struct V_87 V_150 ;
struct V_89 V_151 ;
void * V_152 ;
T_5 V_153 ;
struct V_70 V_154 ;
T_5 V_91 ;
struct V_103 V_155 ;
int V_156 ;
T_8 V_97 ;
T_14 V_98 ;
if ( V_141 -> V_138 == V_41 ) {
if ( V_104 -> V_72 < 0 ||
( unsigned ) V_104 -> V_72 >= V_139 ||
V_140 [ V_104 -> V_72 ] == - 1 ) {
* V_2 = V_31 ;
return FALSE ;
}
F_28 ( V_154 . V_27 , V_140 [ V_104 -> V_72 ] ) ;
}
if ( V_16 -> V_149 ) {
* V_2 = V_157 ;
return FALSE ;
}
if ( ! V_16 -> V_147 ) {
V_16 -> V_158 . V_97 = V_104 -> V_111 . V_97 ;
V_16 -> V_158 . V_98 =
( V_104 -> V_111 . V_98 / 1000000 ) * 1000000 ;
V_16 -> V_147 = TRUE ;
}
if ( V_141 -> V_138 == V_77 )
V_156 = sizeof ( struct V_103 ) ;
else
V_156 = 0 ;
V_97 = ( T_8 ) ( V_104 -> V_111 . V_97 - V_16 -> V_158 . V_97 ) ;
V_98 = V_104 -> V_111 . V_98 - V_16 -> V_158 . V_98 ;
while ( V_98 < 0 ) {
V_98 += 1000000000 ;
V_97 -- ;
}
switch ( V_141 -> V_9 ) {
case V_24 :
V_150 . V_107 = F_29 ( V_97 * 1000 + ( V_98 + 500000 ) / 1000000 ) ;
V_150 . V_100 = F_30 ( V_104 -> V_113 + V_156 ) ;
V_150 . V_101 = F_30 ( V_104 -> V_112 + V_156 ) ;
V_152 = & V_150 ;
V_91 = sizeof V_150 ;
break;
case V_25 :
V_151 . V_107 = F_31 ( V_97 * 1000000 + ( V_98 + 500 ) / 1000 ) ;
V_151 . V_100 = F_29 ( V_104 -> V_113 + V_156 ) ;
V_151 . V_101 = F_29 ( V_104 -> V_112 + V_156 ) ;
V_152 = & V_151 ;
V_91 = sizeof V_151 ;
break;
default:
* V_2 = V_159 ;
return FALSE ;
}
V_153 = 0 ;
if ( ! F_32 ( V_141 , V_152 , V_91 , V_2 ) )
return FALSE ;
V_153 += V_91 ;
if ( V_141 -> V_138 == V_77 ) {
memset ( & V_155 . V_160 , 0 , sizeof V_155 . V_160 ) ;
memset ( & V_155 . V_161 , 0 , sizeof V_155 . V_161 ) ;
V_155 . V_118 = F_33 ( V_74 -> V_120 . V_118 ) ;
V_155 . V_119 = F_33 ( V_74 -> V_120 . V_119 ) ;
if ( ! F_32 ( V_141 , & V_155 , sizeof V_155 , V_2 ) )
return FALSE ;
V_153 += sizeof V_155 ;
}
if ( ! F_32 ( V_141 , V_75 , V_104 -> V_112 , V_2 ) )
return FALSE ;
V_153 += V_104 -> V_112 ;
if ( V_141 -> V_138 == V_41 ) {
if ( ! F_32 ( V_141 , & V_154 ,
sizeof V_154 , V_2 ) )
return FALSE ;
V_153 += sizeof V_154 ;
}
if ( V_16 -> V_13 == 0 ) {
V_16 -> V_14 = ( T_3 * ) F_7 ( 1024 * sizeof * V_16 -> V_14 ) ;
V_16 -> V_13 = 1024 ;
} else {
if ( V_16 -> V_148 >= V_16 -> V_13 ) {
V_16 -> V_13 *= 2 ;
V_16 -> V_14 = ( T_3 * ) F_34 ( V_16 -> V_14 ,
V_16 -> V_13 * sizeof * V_16 -> V_14 ) ;
}
}
V_16 -> V_14 [ V_16 -> V_148 ] =
F_29 ( V_16 -> V_11 ) ;
if ( ( V_162 ) V_16 -> V_11 + V_153 > V_163 ) {
V_16 -> V_149 = TRUE ;
}
V_16 -> V_148 ++ ;
V_16 -> V_11 += ( T_3 ) V_153 ;
return TRUE ;
}
static T_7 V_146 ( T_12 * V_141 , int * V_2 )
{
T_13 * V_16 = ( T_13 * ) V_141 -> V_32 ;
T_5 V_164 ;
struct V_7 V_165 ;
const char * V_166 ;
T_5 V_167 ;
struct V_10 * V_10 ;
V_164 = V_16 -> V_148 * sizeof * V_16 -> V_14 ;
if ( ! F_32 ( V_141 , V_16 -> V_14 , V_164 , V_2 ) )
return FALSE ;
if ( F_27 ( V_141 , 0 , V_64 , V_2 ) == - 1 )
return FALSE ;
memset ( & V_165 , '\0' , sizeof V_165 ) ;
switch ( V_141 -> V_9 ) {
case V_24 :
V_166 = V_21 ;
V_167 = sizeof V_21 ;
V_165 . V_23 = 1 ;
V_165 . V_39 = 1 ;
break;
case V_25 :
V_166 = V_22 ;
V_167 = sizeof V_22 ;
V_165 . V_23 = 2 ;
V_165 . V_39 =
( V_141 -> V_138 == V_41 ) ? 1 : 0 ;
break;
default:
if ( V_2 != NULL )
* V_2 = V_159 ;
return FALSE ;
}
if ( ! F_32 ( V_141 , V_166 , V_167 , V_2 ) )
return FALSE ;
if ( V_141 -> V_138 == V_41 ) {
V_165 . V_27 = F_30 ( 1 ) ;
} else
V_165 . V_27 = F_30 ( V_140 [ V_141 -> V_138 ] ) ;
V_10 = localtime ( & V_16 -> V_158 . V_97 ) ;
if ( V_10 != NULL ) {
V_165 . V_44 = F_30 ( 1900 + V_10 -> V_43 ) ;
V_165 . V_46 = F_30 ( V_10 -> V_45 + 1 ) ;
V_165 . V_168 = F_30 ( V_10 -> V_169 ) ;
V_165 . V_48 = F_30 ( V_10 -> V_47 ) ;
V_165 . V_50 = F_30 ( V_10 -> V_49 ) ;
V_165 . V_52 = F_30 ( V_10 -> V_51 ) ;
V_165 . V_54 = F_30 ( V_10 -> V_53 ) ;
} else {
V_165 . V_44 = F_30 ( 1900 + 0 ) ;
V_165 . V_46 = F_30 ( 0 + 1 ) ;
V_165 . V_168 = F_30 ( 0 ) ;
V_165 . V_48 = F_30 ( 0 ) ;
V_165 . V_50 = F_30 ( 0 ) ;
V_165 . V_52 = F_30 ( 0 ) ;
V_165 . V_54 = F_30 ( 0 ) ;
}
V_165 . V_58 = F_30 ( V_16 -> V_158 . V_98 / 1000000 ) ;
V_165 . V_61 = F_29 ( V_16 -> V_11 ) ;
V_165 . V_62 =
F_29 ( V_16 -> V_148 * sizeof * V_16 -> V_14 ) ;
if ( ! F_32 ( V_141 , & V_165 , sizeof V_165 , V_2 ) )
return FALSE ;
return TRUE ;
}
