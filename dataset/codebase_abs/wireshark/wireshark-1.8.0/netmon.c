int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ sizeof F_2 ] ;
struct V_6 V_7 ;
int V_8 ;
struct V_9 V_9 ;
T_3 V_10 ;
T_3 V_11 ;
T_3 V_12 ;
T_3 * V_13 ;
#ifdef F_3
unsigned int V_14 ;
#endif
T_4 * V_15 ;
V_16 = V_17 ;
V_4 = F_4 ( V_5 , sizeof V_5 , V_1 -> V_18 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_5 ( V_1 -> V_18 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , F_2 , sizeof F_2 ) != 0
&& memcmp ( V_5 , V_19 , sizeof F_2 ) != 0 ) {
return 0 ;
}
V_16 = V_17 ;
V_4 = F_4 ( & V_7 , sizeof V_7 , V_1 -> V_18 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_5 ( V_1 -> V_18 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
switch ( V_7 . V_20 ) {
case 1 :
V_8 = V_21 ;
break;
case 2 :
V_8 = V_22 ;
break;
default:
* V_2 = V_23 ;
* V_3 = F_6 ( L_1 , V_7 . V_20 ) ;
return - 1 ;
}
V_7 . V_24 = F_7 ( & V_7 . V_24 ) ;
if ( V_7 . V_24 >= V_25
|| V_26 [ V_7 . V_24 ] == V_27 ) {
* V_2 = V_28 ;
* V_3 = F_6 ( L_2 ,
V_7 . V_24 ) ;
return - 1 ;
}
V_1 -> V_8 = V_8 ;
V_15 = ( T_4 * ) F_8 ( sizeof( T_4 ) ) ;
V_1 -> V_29 = ( void * ) V_15 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
V_1 -> V_34 = V_35 ;
if( ( V_7 . V_20 == 2 && V_7 . V_36 >= 1 ) || V_7 . V_20 > 2 )
V_1 -> V_37 = V_38 ;
else
V_1 -> V_37 = V_26 [ V_7 . V_24 ] ;
V_1 -> V_39 = 0 ;
V_9 . V_40 = F_7 ( & V_7 . V_41 ) - 1900 ;
V_9 . V_42 = F_7 ( & V_7 . V_43 ) - 1 ;
V_9 . V_44 = F_7 ( & V_7 . V_45 ) ;
V_9 . V_46 = F_7 ( & V_7 . V_47 ) ;
V_9 . V_48 = F_7 ( & V_7 . V_49 ) ;
V_9 . V_50 = F_7 ( & V_7 . V_51 ) ;
V_9 . V_52 = - 1 ;
V_15 -> V_53 = mktime ( & V_9 ) ;
V_15 -> V_54 = F_7 ( & V_7 . V_55 ) * 1000000 ;
V_15 -> V_56 = V_7 . V_20 ;
V_15 -> V_57 = V_7 . V_36 ;
V_10 = F_9 ( & V_7 . V_58 ) ;
V_11 = F_9 ( & V_7 . V_59 ) ;
V_12 = V_11 / ( T_3 ) sizeof ( T_3 ) ;
if ( ( V_12 * sizeof ( T_3 ) ) != V_11 ) {
* V_2 = V_60 ;
* V_3 = F_6 ( L_3 ,
V_11 ) ;
F_10 ( V_15 ) ;
return - 1 ;
}
if ( V_12 == 0 ) {
* V_2 = V_60 ;
* V_3 = F_6 ( L_4 ,
V_11 ) ;
F_10 ( V_15 ) ;
return - 1 ;
}
if ( V_12 > 512 * 1024 * 1024 ) {
* V_2 = V_60 ;
* V_3 = F_6 ( L_5 ,
V_11 ) ;
F_10 ( V_15 ) ;
return - 1 ;
}
if ( F_11 ( V_1 -> V_18 , V_10 , V_61 , V_2 ) == - 1 ) {
F_10 ( V_15 ) ;
return - 1 ;
}
V_13 = ( T_3 * ) F_8 ( V_11 ) ;
V_16 = V_17 ;
V_4 = F_4 ( V_13 , V_11 , V_1 -> V_18 ) ;
if ( ( T_3 ) V_4 != V_11 ) {
* V_2 = F_5 ( V_1 -> V_18 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_62 ;
F_10 ( V_13 ) ;
F_10 ( V_15 ) ;
return - 1 ;
}
V_15 -> V_12 = V_12 ;
V_15 -> V_13 = V_13 ;
#ifdef F_3
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
V_13 [ V_14 ] = F_9 ( & V_13 [ V_14 ] ) ;
#endif
V_15 -> V_63 = 0 ;
switch ( V_15 -> V_56 ) {
case 1 :
V_1 -> V_64 = V_65 ;
break;
case 2 :
V_1 -> V_64 = V_66 ;
break;
}
return 1 ;
}
static T_5
F_12 ( T_4 * V_15 )
{
if ( ( V_15 -> V_56 == 2 && V_15 -> V_57 >= 1 ) ||
V_15 -> V_56 > 2 ) {
if ( V_15 -> V_56 > 2 ) {
return sizeof ( struct V_67 ) ;
} else {
switch ( V_15 -> V_57 ) {
case 1 :
return sizeof ( struct V_68 ) ;
case 2 :
return sizeof ( struct V_69 ) ;
default:
return sizeof ( struct V_67 ) ;
}
}
}
return 0 ;
}
static void
F_13 ( int V_70 ,
union V_71 * V_72 , T_6 * V_73 , int V_74 )
{
switch ( V_70 ) {
case V_75 :
F_14 ( V_73 , V_74 , V_72 ) ;
break;
case V_76 :
V_72 -> V_77 . V_78 = 0 ;
break;
case V_79 :
V_72 -> V_80 . V_78 = - 2 ;
break;
}
}
static T_7 V_31 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_8 * V_81 )
{
T_4 * V_15 = ( T_4 * ) V_1 -> V_29 ;
T_3 V_82 = 0 ;
T_3 V_83 = 0 ;
int V_4 ;
union {
struct V_84 V_85 ;
struct V_86 V_87 ;
} V_7 ;
int V_88 = 0 ;
int V_89 ;
T_8 V_90 ;
T_6 * V_91 ;
T_8 V_92 = 0 ;
T_8 V_93 ;
T_9 V_94 ;
T_3 V_95 ;
V_96:
if ( V_15 -> V_63 >= V_15 -> V_12 ) {
F_10 ( V_15 -> V_13 ) ;
V_15 -> V_13 = NULL ;
* V_2 = 0 ;
return FALSE ;
}
V_90 = V_15 -> V_13 [ V_15 -> V_63 ] ;
if ( F_15 ( V_1 -> V_18 ) != V_90 ) {
if ( F_11 ( V_1 -> V_18 , V_90 , V_61 , V_2 ) == - 1 )
return FALSE ;
}
V_15 -> V_63 ++ ;
switch ( V_15 -> V_56 ) {
case 1 :
V_88 = sizeof ( struct V_84 ) ;
break;
case 2 :
V_88 = sizeof ( struct V_86 ) ;
break;
}
V_16 = V_17 ;
V_4 = F_4 ( & V_7 , V_88 , V_1 -> V_18 ) ;
if ( V_4 != V_88 ) {
* V_2 = F_5 ( V_1 -> V_18 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_62 ;
}
return FALSE ;
}
switch ( V_15 -> V_56 ) {
case 1 :
V_83 = F_7 ( & V_7 . V_85 . V_97 ) ;
V_82 = F_7 ( & V_7 . V_85 . V_98 ) ;
break;
case 2 :
V_83 = F_9 ( & V_7 . V_87 . V_97 ) ;
V_82 = F_9 ( & V_7 . V_87 . V_98 ) ;
break;
}
if ( V_82 > V_99 ) {
* V_2 = V_60 ;
* V_3 = F_6 ( L_6 ,
V_82 , V_99 ) ;
return FALSE ;
}
* V_81 = F_15 ( V_1 -> V_18 ) ;
switch ( V_1 -> V_37 ) {
case V_75 :
if ( V_82 < sizeof ( struct V_100 ) ) {
* V_2 = V_60 ;
* V_3 = F_6 ( L_7 ,
V_82 ) ;
return FALSE ;
}
if ( ! F_16 ( V_1 -> V_18 , & V_1 -> V_72 ,
V_2 , V_3 ) )
return FALSE ;
V_83 -= ( V_101 ) sizeof ( struct V_100 ) ;
V_82 -= ( V_101 ) sizeof ( struct V_100 ) ;
break;
default:
break;
}
F_17 ( V_1 -> V_102 , V_82 ) ;
V_91 = F_18 ( V_1 -> V_102 ) ;
if ( ! F_19 ( V_1 -> V_18 , V_91 , V_82 , V_2 ,
V_3 ) )
return FALSE ;
switch ( V_15 -> V_56 ) {
case 1 :
V_92 = ( ( T_8 ) F_9 ( & V_7 . V_85 . V_103 ) ) * 1000000 ;
break;
case 2 :
V_92 = F_20 ( & V_7 . V_87 . V_103 ) * 10 ;
V_92 *= 100 ;
break;
}
V_94 = 0 ;
V_93 = V_15 -> V_54 + V_92 ;
while ( V_93 < 0 ) {
V_93 += 1000000000 ;
V_94 -- ;
}
V_94 += ( T_9 ) ( V_93 / 1000000000 ) ;
V_95 = ( T_3 ) ( V_93 % 1000000000 ) ;
V_1 -> V_104 . V_105 = V_106 | V_107 ;
V_1 -> V_104 . V_108 . V_94 = V_15 -> V_53 + V_94 ;
V_1 -> V_104 . V_108 . V_95 = V_95 ;
V_1 -> V_104 . V_109 = V_82 ;
V_1 -> V_104 . V_110 = V_83 ;
V_89 = ( int ) F_12 ( V_15 ) ;
if ( V_89 != 0 ) {
V_1 -> V_104 . V_70 = F_21 ( V_1 -> V_18 ,
V_89 , V_2 , V_3 ) ;
if ( V_1 -> V_104 . V_70 == - 1 )
return FALSE ;
if ( V_1 -> V_104 . V_70 == 0 )
goto V_96;
F_13 ( V_1 -> V_104 . V_70 ,
& V_1 -> V_72 , V_91 , V_82 ) ;
} else {
F_13 ( V_1 -> V_37 ,
& V_1 -> V_72 , V_91 , V_82 ) ;
}
return TRUE ;
}
static T_7
V_33 ( T_1 * V_1 , T_8 V_111 ,
union V_71 * V_72 , T_6 * V_73 , int V_74 ,
int * V_2 , T_2 * * V_3 )
{
T_4 * V_15 = ( T_4 * ) V_1 -> V_29 ;
int V_89 ;
int V_70 ;
if ( F_11 ( V_1 -> V_112 , V_111 , V_61 , V_2 ) == - 1 )
return FALSE ;
switch ( V_1 -> V_37 ) {
case V_75 :
if ( ! F_16 ( V_1 -> V_112 , V_72 ,
V_2 , V_3 ) ) {
return FALSE ;
}
break;
}
if ( ! F_19 ( V_1 -> V_112 , V_73 , V_74 , V_2 , V_3 ) )
return FALSE ;
V_89 = ( int ) F_12 ( V_15 ) ;
if ( V_89 != 0 ) {
V_70 = F_21 ( V_1 -> V_112 ,
V_89 , V_2 , V_3 ) ;
if ( V_70 == - 1 )
return FALSE ;
if ( V_70 == 0 ) {
* V_2 = V_60 ;
* V_3 = F_22 ( L_8 ) ;
return FALSE ;
}
F_13 ( V_70 , V_72 ,
V_73 , V_74 ) ;
} else {
F_13 ( V_1 -> V_37 , V_72 ,
V_73 , V_74 ) ;
}
return TRUE ;
}
static T_7
F_16 ( T_10 V_18 , union V_71 * V_72 ,
int * V_2 , T_2 * * V_3 )
{
struct V_100 V_113 ;
int V_4 ;
T_11 V_114 , V_115 ;
V_16 = V_17 ;
V_4 = F_4 ( & V_113 , sizeof ( struct V_100 ) , V_18 ) ;
if ( V_4 != sizeof ( struct V_100 ) ) {
* V_2 = F_5 ( V_18 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_62 ;
return FALSE ;
}
V_114 = F_23 ( V_113 . V_114 ) ;
V_115 = F_23 ( V_113 . V_115 ) ;
V_72 -> V_116 . V_114 = V_114 ;
V_72 -> V_116 . V_115 = V_115 ;
V_72 -> V_116 . V_117 = 0 ;
V_72 -> V_116 . V_118 = 0 ;
V_72 -> V_116 . V_119 = 0 ;
V_72 -> V_116 . V_120 = 0 ;
V_72 -> V_116 . V_121 = 0 ;
V_72 -> V_116 . V_122 = 0 ;
return TRUE ;
}
static T_7
F_19 ( T_10 V_18 , T_6 * V_73 , int V_74 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_16 = V_17 ;
V_4 = F_4 ( V_73 , V_74 , V_18 ) ;
if ( V_4 != V_74 ) {
* V_2 = F_5 ( V_18 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_62 ;
return FALSE ;
}
return TRUE ;
}
static int
F_21 ( T_10 V_18 , int V_89 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
union {
struct V_68 V_123 ;
struct V_69 V_124 ;
struct V_67 V_125 ;
} V_126 ;
T_11 V_24 ;
int V_70 ;
V_16 = V_17 ;
V_4 = F_4 ( & V_126 , V_89 , V_18 ) ;
if ( V_4 != V_89 ) {
* V_2 = F_5 ( V_18 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 ) {
* V_2 = V_62 ;
}
return - 1 ;
}
V_24 = F_7 ( V_126 . V_123 . V_24 ) ;
if ( ( V_24 & 0xF000 ) == V_127 ) {
V_24 &= 0x0FFF ;
V_70 = F_24 ( V_24 ) ;
if ( V_70 == V_27 ) {
* V_2 = V_28 ;
* V_3 = F_6 ( L_9 ,
V_24 ) ;
return - 1 ;
}
} else if ( V_24 < V_25 ) {
V_70 = V_26 [ V_24 ] ;
if ( V_70 == V_27 ) {
* V_2 = V_28 ;
* V_3 = F_6 ( L_2 ,
V_24 ) ;
return - 1 ;
}
} else {
switch ( V_24 ) {
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
return 0 ;
default:
* V_2 = V_28 ;
* V_3 = F_6 ( L_2 ,
V_24 ) ;
return - 1 ;
}
}
return V_70 ;
}
static void
V_35 ( T_1 * V_1 )
{
T_4 * V_15 = ( T_4 * ) V_1 -> V_29 ;
if ( V_15 -> V_13 != NULL ) {
F_10 ( V_15 -> V_13 ) ;
V_15 -> V_13 = NULL ;
}
}
int F_25 ( int V_134 )
{
if ( V_134 < 0 || ( unsigned ) V_134 >= V_135 || V_136 [ V_134 ] == - 1 )
return V_28 ;
return 0 ;
}
int F_26 ( int V_134 )
{
if ( V_134 == V_38 )
return 0 ;
if ( V_134 < 0 || ( unsigned ) V_134 >= V_135 || V_136 [ V_134 ] == - 1 )
return V_28 ;
return 0 ;
}
T_7 F_27 ( T_12 * V_137 , int * V_2 )
{
T_13 * V_15 ;
if ( fseek ( V_137 -> V_18 , V_138 , V_61 ) == - 1 ) {
* V_2 = V_16 ;
return FALSE ;
}
V_137 -> V_139 = V_140 ;
V_137 -> V_141 = V_142 ;
V_15 = ( T_13 * ) F_8 ( sizeof( T_13 ) ) ;
V_137 -> V_29 = ( void * ) V_15 ;
V_15 -> V_10 = V_138 ;
V_15 -> V_143 = FALSE ;
V_15 -> V_13 = NULL ;
V_15 -> V_144 = 0 ;
V_15 -> V_12 = 0 ;
V_15 -> V_145 = FALSE ;
return TRUE ;
}
static T_7 V_140 ( T_12 * V_137 , const struct V_146 * V_104 ,
const union V_71 * V_72 , const T_6 * V_73 , int * V_2 )
{
T_13 * V_15 = ( T_13 * ) V_137 -> V_29 ;
struct V_84 V_147 ;
struct V_86 V_148 ;
void * V_149 ;
T_5 V_150 ;
struct V_68 V_151 ;
T_5 V_88 ;
struct V_100 V_152 ;
int V_153 ;
T_8 V_94 ;
T_14 V_95 ;
if ( V_137 -> V_134 == V_38 ) {
if ( V_104 -> V_70 < 0 ||
( unsigned ) V_104 -> V_70 >= V_135 ||
V_136 [ V_104 -> V_70 ] == - 1 ) {
* V_2 = V_28 ;
return FALSE ;
}
F_28 ( V_151 . V_24 , V_136 [ V_104 -> V_70 ] ) ;
}
if ( V_15 -> V_145 ) {
* V_2 = V_154 ;
return FALSE ;
}
if ( ! V_15 -> V_143 ) {
V_15 -> V_155 . V_94 = V_104 -> V_108 . V_94 ;
V_15 -> V_155 . V_95 =
( V_104 -> V_108 . V_95 / 1000000 ) * 1000000 ;
V_15 -> V_143 = TRUE ;
}
if ( V_137 -> V_134 == V_75 )
V_153 = sizeof ( struct V_100 ) ;
else
V_153 = 0 ;
V_94 = ( T_8 ) ( V_104 -> V_108 . V_94 - V_15 -> V_155 . V_94 ) ;
V_95 = V_104 -> V_108 . V_95 - V_15 -> V_155 . V_95 ;
while ( V_95 < 0 ) {
V_95 += 1000000000 ;
V_94 -- ;
}
switch ( V_137 -> V_8 ) {
case V_21 :
V_147 . V_103 = F_29 ( V_94 * 1000 + ( V_95 + 500000 ) / 1000000 ) ;
V_147 . V_97 = F_30 ( V_104 -> V_110 + V_153 ) ;
V_147 . V_98 = F_30 ( V_104 -> V_109 + V_153 ) ;
V_149 = & V_147 ;
V_88 = sizeof V_147 ;
break;
case V_22 :
V_148 . V_103 = F_31 ( V_94 * 1000000 + ( V_95 + 500 ) / 1000 ) ;
V_148 . V_97 = F_29 ( V_104 -> V_110 + V_153 ) ;
V_148 . V_98 = F_29 ( V_104 -> V_109 + V_153 ) ;
V_149 = & V_148 ;
V_88 = sizeof V_148 ;
break;
default:
* V_2 = V_156 ;
return FALSE ;
}
V_150 = 0 ;
if ( ! F_32 ( V_137 , V_149 , V_88 , V_2 ) )
return FALSE ;
V_150 += V_88 ;
if ( V_137 -> V_134 == V_75 ) {
memset ( & V_152 . V_157 , 0 , sizeof V_152 . V_157 ) ;
memset ( & V_152 . V_158 , 0 , sizeof V_152 . V_158 ) ;
V_152 . V_114 = F_33 ( V_72 -> V_116 . V_114 ) ;
V_152 . V_115 = F_33 ( V_72 -> V_116 . V_115 ) ;
if ( ! F_32 ( V_137 , & V_152 , sizeof V_152 , V_2 ) )
return FALSE ;
V_150 += sizeof V_152 ;
}
if ( ! F_32 ( V_137 , V_73 , V_104 -> V_109 , V_2 ) )
return FALSE ;
V_150 += V_104 -> V_109 ;
if ( V_137 -> V_134 == V_38 ) {
if ( ! F_32 ( V_137 , & V_151 ,
sizeof V_151 , V_2 ) )
return FALSE ;
V_150 += sizeof V_151 ;
}
if ( V_15 -> V_12 == 0 ) {
V_15 -> V_13 = ( T_3 * ) F_8 ( 1024 * sizeof * V_15 -> V_13 ) ;
V_15 -> V_12 = 1024 ;
} else {
if ( V_15 -> V_144 >= V_15 -> V_12 ) {
V_15 -> V_12 *= 2 ;
V_15 -> V_13 = ( T_3 * ) F_34 ( V_15 -> V_13 ,
V_15 -> V_12 * sizeof * V_15 -> V_13 ) ;
}
}
V_15 -> V_13 [ V_15 -> V_144 ] =
F_29 ( V_15 -> V_10 ) ;
if ( ( V_159 ) V_15 -> V_10 + V_150 > V_160 ) {
V_15 -> V_145 = TRUE ;
}
V_15 -> V_144 ++ ;
V_15 -> V_10 += ( T_3 ) V_150 ;
return TRUE ;
}
static T_7 V_142 ( T_12 * V_137 , int * V_2 )
{
T_13 * V_15 = ( T_13 * ) V_137 -> V_29 ;
T_5 V_161 ;
struct V_6 V_162 ;
const char * V_163 ;
T_5 V_164 ;
struct V_9 * V_9 ;
V_161 = V_15 -> V_144 * sizeof * V_15 -> V_13 ;
if ( ! F_32 ( V_137 , V_15 -> V_13 , V_161 , V_2 ) )
return FALSE ;
fseek ( V_137 -> V_18 , 0 , V_61 ) ;
memset ( & V_162 , '\0' , sizeof V_162 ) ;
switch ( V_137 -> V_8 ) {
case V_21 :
V_163 = F_2 ;
V_164 = sizeof F_2 ;
V_162 . V_20 = 1 ;
V_162 . V_36 = 1 ;
break;
case V_22 :
V_163 = V_19 ;
V_164 = sizeof V_19 ;
V_162 . V_20 = 2 ;
V_162 . V_36 =
( V_137 -> V_134 == V_38 ) ? 1 : 0 ;
break;
default:
if ( V_2 != NULL )
* V_2 = V_156 ;
return FALSE ;
}
if ( ! F_32 ( V_137 , V_163 , V_164 , V_2 ) )
return FALSE ;
if ( V_137 -> V_134 == V_38 ) {
V_162 . V_24 = F_30 ( 1 ) ;
} else
V_162 . V_24 = F_30 ( V_136 [ V_137 -> V_134 ] ) ;
V_9 = localtime ( & V_15 -> V_155 . V_94 ) ;
if ( V_9 != NULL ) {
V_162 . V_41 = F_30 ( 1900 + V_9 -> V_40 ) ;
V_162 . V_43 = F_30 ( V_9 -> V_42 + 1 ) ;
V_162 . V_165 = F_30 ( V_9 -> V_166 ) ;
V_162 . V_45 = F_30 ( V_9 -> V_44 ) ;
V_162 . V_47 = F_30 ( V_9 -> V_46 ) ;
V_162 . V_49 = F_30 ( V_9 -> V_48 ) ;
V_162 . V_51 = F_30 ( V_9 -> V_50 ) ;
} else {
V_162 . V_41 = F_30 ( 1900 + 0 ) ;
V_162 . V_43 = F_30 ( 0 + 1 ) ;
V_162 . V_165 = F_30 ( 0 ) ;
V_162 . V_45 = F_30 ( 0 ) ;
V_162 . V_47 = F_30 ( 0 ) ;
V_162 . V_49 = F_30 ( 0 ) ;
V_162 . V_51 = F_30 ( 0 ) ;
}
V_162 . V_55 = F_30 ( V_15 -> V_155 . V_95 / 1000000 ) ;
V_162 . V_58 = F_29 ( V_15 -> V_10 ) ;
V_162 . V_59 =
F_29 ( V_15 -> V_144 * sizeof * V_15 -> V_13 ) ;
if ( ! F_32 ( V_137 , & V_162 , sizeof V_162 , V_2 ) )
return FALSE ;
return TRUE ;
}
