int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ V_6 ] ;
T_3 V_7 ;
struct V_8 V_9 ;
T_4 V_10 ;
double V_11 ;
int V_12 , V_13 ;
int V_14 ;
double V_15 ;
static const int V_16 [] = {
V_17 ,
V_18 ,
V_19 ,
V_20 ,
V_18 ,
V_17 ,
V_17 ,
V_17 ,
V_17 ,
V_21 ,
V_22 ,
V_17
} ;
#define F_2 (sizeof netxray_encap / sizeof netxray_encap[0])
int V_23 ;
T_4 V_24 = 0 ;
T_5 * V_25 ;
V_26 = V_27 ;
V_4 = F_3 ( V_5 , V_6 , V_1 -> V_28 ) ;
if ( V_4 != V_6 ) {
* V_2 = F_4 ( V_1 -> V_28 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_29 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , V_30 , V_6 ) == 0 ) {
V_7 = FALSE ;
} else if ( memcmp ( V_5 , V_31 , V_6 ) == 0 ) {
V_7 = TRUE ;
} else {
return 0 ;
}
V_26 = V_27 ;
V_4 = F_3 ( & V_9 , sizeof V_9 , V_1 -> V_28 ) ;
if ( V_4 != sizeof V_9 ) {
* V_2 = F_4 ( V_1 -> V_28 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_29 ;
return - 1 ;
}
if ( V_7 ) {
V_12 = 0 ;
V_13 = 0 ;
V_14 = V_32 ;
} else {
if ( memcmp ( V_9 . V_33 , V_34 , sizeof V_34 ) == 0 ) {
V_12 = 1 ;
V_13 = 0 ;
V_14 = V_35 ;
} else if ( memcmp ( V_9 . V_33 , V_36 , sizeof V_36 ) == 0 ) {
V_12 = 1 ;
V_13 = 1 ;
V_14 = V_37 ;
} else if ( memcmp ( V_9 . V_33 , V_38 , sizeof V_38 ) == 0 ) {
V_12 = 2 ;
V_13 = 0 ;
V_14 = V_39 ;
} else if ( memcmp ( V_9 . V_33 , V_40 , sizeof V_40 ) == 0 ) {
V_12 = 2 ;
V_13 = 1 ;
V_14 = V_39 ;
} else if ( memcmp ( V_9 . V_33 , V_41 , sizeof V_41 ) == 0 ) {
V_12 = 2 ;
V_13 = 2 ;
V_14 = V_39 ;
} else if ( memcmp ( V_9 . V_33 , V_42 , sizeof V_42 ) == 0 ) {
V_12 = 2 ;
V_13 = 3 ;
V_14 = V_39 ;
} else {
* V_2 = V_43 ;
* V_3 = F_5 ( L_1 , V_9 . V_33 ) ;
return - 1 ;
}
}
switch ( V_9 . V_44 ) {
case 0 :
V_10 = V_9 . V_45 + 1 ;
break;
case 2 :
V_10 = V_9 . V_45 ;
break;
default:
* V_2 = V_43 ;
* V_3 = F_5 ( L_2 ,
V_9 . V_44 ) ;
return - 1 ;
}
if ( V_10 >= F_2
|| V_16 [ V_10 ] == V_17 ) {
* V_2 = V_46 ;
* V_3 = F_5 ( L_3 ,
V_10 , V_9 . V_44 ) ;
return - 1 ;
}
V_15 = ( double ) F_6 ( & V_9 . V_47 )
+ ( double ) F_6 ( & V_9 . V_48 ) * 4294967296.0 ;
switch ( V_14 ) {
case V_32 :
V_11 = 1000.0 ;
V_1 -> V_49 = V_50 ;
break;
case V_35 :
V_11 = 1000.0 ;
V_1 -> V_49 = V_50 ;
break;
case V_37 :
V_11 = 1000000.0 ;
V_1 -> V_49 = V_51 ;
break;
case V_39 :
switch ( V_10 ) {
case 1 :
switch ( V_9 . V_52 ) {
case V_53 :
if ( V_9 . V_54 >= V_55 ) {
* V_2 = V_43 ;
* V_3 = F_5 (
L_4 ,
V_9 . V_54 , V_9 . V_33 ) ;
return - 1 ;
}
if ( V_9 . V_54 == 2 ) {
V_11 = F_6 ( V_9 . V_56 ) ;
}
else {
V_11 = V_57 [ V_9 . V_54 ] ;
}
break;
case V_58 :
if ( V_9 . V_54 >= V_59
|| V_60 [ V_9 . V_54 ] == 0.0 ) {
* V_2 = V_43 ;
* V_3 = F_5 (
L_5 ,
V_9 . V_54 , V_9 . V_33 ) ;
return - 1 ;
}
V_11 = V_60 [ V_9 . V_54 ] ;
if ( V_13 == 2 || V_13 == 3 )
V_15 = 0.0 ;
break;
case V_61 :
if ( V_9 . V_54 >= V_62
|| V_63 [ V_9 . V_54 ] == 0.0 ) {
* V_2 = V_43 ;
* V_3 = F_5 (
L_6 ,
V_9 . V_54 , V_9 . V_33 ) ;
return - 1 ;
}
V_11 = V_63 [ V_9 . V_54 ] ;
if ( V_13 == 2 || V_13 == 3 )
V_15 = 0.0 ;
break;
case V_64 :
if ( V_9 . V_54 >= V_65
|| V_66 [ V_9 . V_54 ] == 0.0 ) {
* V_2 = V_43 ;
* V_3 = F_5 (
L_7 ,
V_9 . V_54 , V_9 . V_33 ) ;
return - 1 ;
}
V_11 = V_66 [ V_9 . V_54 ] ;
if ( V_13 == 2 || V_13 == 3 )
V_15 = 0.0 ;
break;
case V_67 :
if ( V_9 . V_54 >= V_68
|| V_69 [ V_9 . V_54 ] == 0.0 ) {
* V_2 = V_43 ;
* V_3 = F_5 (
L_8 ,
V_9 . V_54 , V_9 . V_33 ) ;
return - 1 ;
}
V_11 = V_69 [ V_9 . V_54 ] ;
if ( V_13 == 2 || V_13 == 3 )
V_15 = 0.0 ;
break;
default:
* V_2 = V_43 ;
* V_3 = F_5 (
L_9 ,
V_9 . V_52 , V_9 . V_33 ) ;
return - 1 ;
}
break;
default:
if ( V_9 . V_54 >= V_55 ) {
* V_2 = V_43 ;
* V_3 = F_5 (
L_10 ,
V_9 . V_54 , V_10 , V_9 . V_52 ,
V_9 . V_33 ) ;
return - 1 ;
}
V_11 = V_57 [ V_9 . V_54 ] ;
break;
}
if ( V_11 >= 1e7 )
V_1 -> V_49 = V_70 ;
else
V_1 -> V_49 = V_51 ;
break;
default:
F_7 () ;
V_11 = 0.0 ;
}
V_15 = V_15 / V_11 ;
if ( V_10 == 4 ) {
if ( V_12 == 2 ) {
switch ( V_9 . V_52 ) {
case V_71 :
V_23 = V_72 ;
break;
case V_73 :
V_23 = V_74 ;
break;
case V_75 :
case V_76 :
switch ( V_9 . V_77 ) {
case 0 :
V_23 = V_78 ;
break;
case 1 :
case 2 :
case 3 :
V_23 = V_79 ;
V_24 = V_9 . V_77 ;
break;
default:
* V_2 = V_46 ;
* V_3 = F_5 ( L_11 ,
V_9 . V_77 ) ;
return - 1 ;
}
break;
case V_80 :
V_23 = V_81 ;
break;
case V_82 :
V_23 = V_83 ;
break;
default:
* V_2 = V_46 ;
* V_3 = F_5 ( L_12 ,
V_9 . V_52 ) ;
return - 1 ;
}
} else
V_23 = V_18 ;
} else
V_23 = V_16 [ V_10 ] ;
V_1 -> V_14 = V_14 ;
V_25 = ( T_5 * ) F_8 ( sizeof( T_5 ) ) ;
V_1 -> V_84 = ( void * ) V_25 ;
V_1 -> V_85 = V_86 ;
V_1 -> V_87 = V_88 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_89 = 0 ;
V_25 -> V_90 = F_6 ( & V_9 . V_90 ) ;
V_25 -> V_11 = V_11 ;
V_25 -> V_15 = V_15 ;
V_25 -> V_12 = V_12 ;
V_25 -> V_91 = FALSE ;
switch ( V_23 ) {
case V_18 :
case V_22 :
case V_79 :
case V_78 :
if ( V_12 == 2 ) {
if ( V_9 . V_56 [ 1 ] == 0x34 && V_9 . V_56 [ 2 ] == 0x12 )
V_25 -> V_91 = TRUE ;
}
break;
}
V_25 -> V_24 = V_24 ;
V_25 -> V_92 = FALSE ;
V_25 -> V_93 = F_6 ( & V_9 . V_93 ) ;
V_25 -> V_94 = F_6 ( & V_9 . V_94 ) ;
V_25 -> V_95 = F_6 ( & V_9 . V_95 ) ;
if ( F_9 ( V_1 -> V_28 , V_25 -> V_94 , V_96 , V_2 ) == - 1 ) {
return - 1 ;
}
return 1 ;
}
static T_3 V_86 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_97 )
{
T_5 * V_25 = ( T_5 * ) V_1 -> V_84 ;
T_7 V_98 ;
union V_99 V_9 ;
int V_100 ;
double V_101 ;
T_8 * V_102 ;
T_4 V_103 ;
V_104:
* V_97 = F_10 ( V_1 -> V_28 ) ;
if ( * V_97 == V_25 -> V_95 ) {
* V_2 = 0 ;
return FALSE ;
}
V_100 = F_11 ( V_1 , V_1 -> V_28 , & V_9 , V_2 , V_3 ) ;
if ( V_100 == 0 ) {
if ( * V_2 != 0 ) {
return FALSE ;
}
if ( V_25 -> V_94 < V_25 -> V_95 ) {
* V_2 = V_29 ;
return FALSE ;
}
if ( ! V_25 -> V_92 ) {
V_25 -> V_92 = TRUE ;
if ( F_9 ( V_1 -> V_28 , V_105 ,
V_96 , V_2 ) == - 1 )
return FALSE ;
goto V_104;
}
return FALSE ;
}
if ( V_25 -> V_12 == 0 )
V_98 = F_12 ( & V_9 . V_106 . V_107 ) ;
else
V_98 = F_12 ( & V_9 . V_108 . V_109 ) ;
F_13 ( V_1 -> V_110 , V_98 ) ;
V_102 = F_14 ( V_1 -> V_110 ) ;
if ( ! F_15 ( V_1 -> V_28 , V_102 , V_98 , V_2 , V_3 ) )
return FALSE ;
V_103 = F_16 ( V_1 , V_102 , V_98 ,
& V_1 -> V_111 . V_112 , & V_9 ) ;
if ( V_25 -> V_12 == 0 ) {
V_1 -> V_111 . V_113 = V_114 ;
V_101 = ( double ) F_6 ( & V_9 . V_106 . V_47 )
+ ( double ) F_6 ( & V_9 . V_106 . V_48 ) * 4294967296.0 ;
V_101 /= V_25 -> V_11 ;
V_101 -= V_25 -> V_15 ;
V_1 -> V_111 . V_115 . V_116 = V_25 -> V_90 + ( long ) V_101 ;
V_1 -> V_111 . V_115 . V_117 = ( int ) ( ( V_101 - ( double ) ( unsigned long ) ( V_101 ) )
* 1.0e9 ) ;
V_1 -> V_111 . V_118 = V_98 - V_103 ;
V_1 -> V_111 . V_107 = V_1 -> V_111 . V_118 ;
} else {
V_1 -> V_111 . V_113 = V_114 | V_119 ;
V_101 = ( double ) F_6 ( & V_9 . V_108 . V_47 )
+ ( double ) F_6 ( & V_9 . V_108 . V_48 ) * 4294967296.0 ;
V_101 /= V_25 -> V_11 ;
V_101 -= V_25 -> V_15 ;
V_1 -> V_111 . V_115 . V_116 = V_25 -> V_90 + ( V_120 ) V_101 ;
V_1 -> V_111 . V_115 . V_117 = ( int ) ( ( V_101 - ( double ) ( unsigned long ) ( V_101 ) )
* 1.0e9 ) ;
V_1 -> V_111 . V_118 = V_98 - V_103 ;
V_1 -> V_111 . V_107 = F_12 ( & V_9 . V_108 . V_121 ) - V_103 ;
}
return TRUE ;
}
static T_3
V_88 ( T_1 * V_1 , T_6 V_122 ,
struct V_123 * V_111 , T_8 * V_102 , int V_124 ,
int * V_2 , T_2 * * V_3 )
{
union V_125 * V_112 = & V_111 -> V_112 ;
union V_99 V_9 ;
T_3 V_126 ;
if ( F_9 ( V_1 -> V_127 , V_122 , V_96 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_11 ( V_1 , V_1 -> V_127 , & V_9 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_29 ;
}
return FALSE ;
}
V_126 = F_15 ( V_1 -> V_127 , V_102 , V_124 , V_2 , V_3 ) ;
if ( ! V_126 )
return FALSE ;
F_16 ( V_1 , V_102 , V_124 , V_112 , & V_9 ) ;
return TRUE ;
}
static int
F_11 ( T_1 * V_1 , T_9 V_28 , union V_99 * V_9 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_25 = ( T_5 * ) V_1 -> V_84 ;
int V_4 ;
int V_100 = 0 ;
switch ( V_25 -> V_12 ) {
case 0 :
V_100 = sizeof ( struct V_128 ) ;
break;
case 1 :
V_100 = sizeof ( struct V_129 ) ;
break;
case 2 :
V_100 = sizeof ( struct V_130 ) ;
break;
}
V_26 = V_27 ;
V_4 = F_3 ( V_9 , V_100 , V_28 ) ;
if ( V_4 != V_100 ) {
* V_2 = F_4 ( V_1 -> V_28 , V_3 ) ;
if ( * V_2 != 0 )
return 0 ;
if ( V_4 != 0 ) {
* V_2 = V_29 ;
return 0 ;
}
return 0 ;
}
return V_100 ;
}
static T_4
F_16 ( T_1 * V_1 , const T_8 * V_102 , int V_107 ,
union V_125 * V_112 , union V_99 * V_9 )
{
T_5 * V_25 = ( T_5 * ) V_1 -> V_84 ;
T_4 V_103 = 0 ;
switch ( V_25 -> V_12 ) {
case 1 :
switch ( V_1 -> V_23 ) {
case V_18 :
V_112 -> V_131 . V_132 = 0 ;
break;
}
break;
case 2 :
switch ( V_1 -> V_23 ) {
case V_18 :
if ( V_9 -> V_133 . V_134 [ 2 ] == 0xff &&
V_9 -> V_133 . V_134 [ 3 ] == 0xff ) {
if ( V_25 -> V_91 ) {
V_112 -> V_131 . V_132 = 4 ;
} else {
V_103 = 4 ;
}
} else
V_112 -> V_131 . V_132 = 0 ;
break;
case V_22 :
if ( V_9 -> V_133 . V_134 [ 2 ] == 0xff &&
V_9 -> V_133 . V_134 [ 3 ] == 0xff ) {
if ( V_25 -> V_91 ) {
V_112 -> V_135 . V_132 = 4 ;
} else {
V_103 = 4 ;
}
} else
V_112 -> V_135 . V_132 = 0 ;
V_112 -> V_135 . V_136 = FALSE ;
V_112 -> V_135 . V_137 =
V_9 -> V_133 . V_134 [ 12 ] ;
V_112 -> V_135 . V_138 =
V_9 -> V_133 . V_134 [ 13 ] ;
V_112 -> V_135 . V_139 =
V_9 -> V_133 . V_134 [ 14 ] ;
break;
case V_79 :
V_112 -> V_140 . V_141 =
( V_9 -> V_133 . V_134 [ 12 ] & 0x01 ) ;
V_112 -> V_140 . V_137 =
V_9 -> V_133 . V_134 [ 13 ] & 0x1F ;
switch ( V_25 -> V_24 ) {
case 1 :
if ( V_112 -> V_140 . V_137 == 16 )
V_112 -> V_140 . V_137 = 0 ;
else if ( V_112 -> V_140 . V_137 > 16 )
V_112 -> V_140 . V_137 -= 1 ;
break;
case 2 :
if ( V_112 -> V_140 . V_137 == 24 )
V_112 -> V_140 . V_137 = 0 ;
else if ( V_112 -> V_140 . V_137 > 24 )
V_112 -> V_140 . V_137 -= 1 ;
break;
}
if ( V_9 -> V_133 . V_134 [ 2 ] == 0xff &&
V_9 -> V_133 . V_134 [ 3 ] == 0xff ) {
V_103 = 4 ;
}
break;
case V_78 :
case V_74 :
V_112 -> V_142 . V_143 =
( V_9 -> V_133 . V_134 [ 12 ] & 0x01 ) ? 0x00 : V_144 ;
if ( V_9 -> V_133 . V_134 [ 2 ] == 0xff &&
V_9 -> V_133 . V_134 [ 3 ] == 0xff ) {
V_103 = 4 ;
}
break;
case V_72 :
case V_81 :
case V_83 :
V_112 -> V_145 . V_146 =
( V_9 -> V_133 . V_134 [ 12 ] & 0x01 ) ? TRUE : FALSE ;
break;
case V_21 :
V_112 -> V_147 . V_143 = 0 ;
if ( V_9 -> V_133 . V_134 [ 9 ] & 0x04 )
V_112 -> V_147 . V_143 |= V_148 ;
V_112 -> V_147 . V_149 = V_9 -> V_133 . V_134 [ 11 ] ;
V_112 -> V_147 . V_150 = F_12 ( & V_9 -> V_133 . V_134 [ 12 ] ) ;
V_112 -> V_147 . V_137 =
( V_9 -> V_133 . V_134 [ 15 ] & 0x10 ) ? 1 : 0 ;
V_112 -> V_147 . V_151 = 0 ;
switch ( V_9 -> V_133 . V_134 [ 0 ] & 0xF0 ) {
case 0x00 :
F_17 ( V_102 , V_107 ,
V_112 ) ;
break;
case 0x50 :
V_112 -> V_147 . V_152 = V_153 ;
switch ( V_9 -> V_133 . V_134 [ 0 ] & 0x0F ) {
case 0x09 :
case 0x0a :
V_112 -> V_147 . V_152 = V_154 ;
V_112 -> V_147 . type = V_155 ;
V_112 -> V_147 . V_156 = V_157 ;
break;
case 0x0b :
V_112 -> V_147 . type = V_158 ;
V_112 -> V_147 . V_156 = V_157 ;
break;
case 0x0c :
V_112 -> V_147 . type = V_159 ;
V_112 -> V_147 . V_156 = V_160 ;
break;
case 0x0d :
V_112 -> V_147 . type = V_159 ;
F_18 ( V_102 , V_107 ,
V_112 ) ;
break;
case 0x0f :
V_112 -> V_147 . type = V_161 ;
V_112 -> V_147 . V_156 = V_157 ;
break;
default:
V_112 -> V_147 . type = V_155 ;
V_112 -> V_147 . V_156 = V_157 ;
break;
}
break;
default:
V_112 -> V_147 . V_152 = V_162 ;
V_112 -> V_147 . type = V_155 ;
V_112 -> V_147 . V_156 = V_157 ;
break;
}
break;
}
break;
}
return V_103 ;
}
static T_3
F_15 ( T_9 V_28 , T_8 * V_163 , T_7 V_98 ,
int * V_2 , T_2 * * V_3 )
{
int V_4 ;
V_26 = V_27 ;
V_4 = F_3 ( V_163 , V_98 , V_28 ) ;
if ( V_4 <= 0 || ( T_7 ) V_4 != V_98 ) {
* V_2 = F_4 ( V_28 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_29 ;
return FALSE ;
}
return TRUE ;
}
static int
F_19 ( int V_164 )
{
unsigned int V_165 ;
for ( V_165 = 0 ; V_165 < V_166 ; V_165 ++ ) {
if ( V_164 == V_167 [ V_165 ] . V_168 )
return V_167 [ V_165 ] . V_169 ;
}
return - 1 ;
}
int F_20 ( int V_164 )
{
if ( V_164 == V_170 )
return V_171 ;
if ( F_19 ( V_164 ) == - 1 )
return V_46 ;
return 0 ;
}
T_3 F_21 ( T_10 * V_172 , int * V_2 )
{
T_11 * V_25 ;
V_172 -> V_173 = V_174 ;
V_172 -> V_175 = V_176 ;
if ( F_22 ( V_172 , V_105 , V_96 , V_2 ) == - 1 )
return FALSE ;
V_172 -> V_177 += V_105 ;
V_25 = ( T_11 * ) F_8 ( sizeof( T_11 ) ) ;
V_172 -> V_84 = ( void * ) V_25 ;
V_25 -> V_178 = TRUE ;
V_25 -> V_179 . V_116 = 0 ;
V_25 -> V_179 . V_117 = 0 ;
V_25 -> V_93 = 0 ;
return TRUE ;
}
static T_3 V_174 ( T_10 * V_172 ,
const struct V_123 * V_111 ,
const T_8 * V_102 , int * V_2 )
{
T_11 * V_25 = ( T_11 * ) V_172 -> V_84 ;
T_12 V_180 ;
T_7 V_181 ;
struct V_129 V_182 ;
if ( V_25 -> V_178 ) {
V_25 -> V_178 = FALSE ;
V_25 -> V_179 = V_111 -> V_115 ;
}
memset ( & V_182 , '\0' , sizeof( V_182 ) ) ;
V_180 = ( ( T_12 ) V_111 -> V_115 . V_116 - ( T_12 ) V_25 -> V_179 . V_116 ) * 1000000
+ ( ( T_12 ) V_111 -> V_115 . V_117 ) / 1000 ;
V_181 = ( T_7 ) ( V_180 % F_23 ( 4294967296 ) ) ;
V_182 . V_47 = F_24 ( V_181 ) ;
V_181 = ( T_7 ) ( V_180 / F_23 ( 4294967296 ) ) ;
V_182 . V_48 = F_24 ( V_181 ) ;
V_182 . V_121 = F_25 ( V_111 -> V_107 ) ;
V_182 . V_109 = F_25 ( V_111 -> V_118 ) ;
if ( ! F_26 ( V_172 , & V_182 , sizeof( V_182 ) , V_2 ) )
return FALSE ;
V_172 -> V_177 += sizeof( V_182 ) ;
if ( ! F_26 ( V_172 , V_102 , V_111 -> V_118 , V_2 ) )
return FALSE ;
V_172 -> V_177 += V_111 -> V_118 ;
V_25 -> V_93 ++ ;
return TRUE ;
}
static T_3 V_176 ( T_10 * V_172 , int * V_2 )
{
char V_183 [ V_105 - sizeof( V_30 ) ] ;
T_11 * V_25 = ( T_11 * ) V_172 -> V_84 ;
T_6 V_184 ;
struct V_8 V_185 ;
if ( - 1 == ( V_184 = F_27 ( V_172 , V_2 ) ) )
return FALSE ;
if ( F_22 ( V_172 , 0 , V_96 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_26 ( V_172 , V_30 , sizeof V_30 , V_2 ) )
return FALSE ;
memset ( & V_185 , '\0' , sizeof V_185 ) ;
memcpy ( V_185 . V_33 , V_36 , sizeof V_36 ) ;
V_185 . V_90 = F_24 ( V_25 -> V_179 . V_116 ) ;
V_185 . V_93 = F_24 ( V_25 -> V_93 ) ;
V_185 . V_94 = F_24 ( V_105 ) ;
V_185 . V_95 = F_24 ( ( T_7 ) V_184 ) ;
V_185 . V_45 = F_19 ( V_172 -> V_164 ) ;
V_185 . V_47 = F_24 ( 0 ) ;
V_185 . V_48 = F_24 ( 0 ) ;
memset ( V_183 , '\0' , sizeof V_183 ) ;
memcpy ( V_183 , & V_185 , sizeof( V_185 ) ) ;
if ( ! F_26 ( V_172 , V_183 , sizeof V_183 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_28 ( int V_164 )
{
unsigned int V_165 ;
for ( V_165 = 0 ; V_165 < V_186 ; V_165 ++ ) {
if ( V_164 == V_187 [ V_165 ] . V_168 )
return V_187 [ V_165 ] . V_169 ;
}
return - 1 ;
}
int F_29 ( int V_164 )
{
if ( V_164 == V_170 )
return V_171 ;
if ( F_28 ( V_164 ) == - 1 )
return V_46 ;
return 0 ;
}
T_3 F_30 ( T_10 * V_172 , int * V_2 )
{
T_11 * V_25 ;
V_172 -> V_173 = V_188 ;
V_172 -> V_175 = V_189 ;
if ( F_22 ( V_172 , V_105 , V_96 , V_2 ) == - 1 )
return FALSE ;
V_172 -> V_177 += V_105 ;
V_25 = ( T_11 * ) F_8 ( sizeof( T_11 ) ) ;
V_172 -> V_84 = ( void * ) V_25 ;
V_25 -> V_178 = TRUE ;
V_25 -> V_179 . V_116 = 0 ;
V_25 -> V_179 . V_117 = 0 ;
V_25 -> V_93 = 0 ;
return TRUE ;
}
static T_3 V_188 ( T_10 * V_172 ,
const struct V_123 * V_111 ,
const T_8 * V_102 , int * V_2 )
{
const union V_125 * V_112 = & V_111 -> V_112 ;
T_11 * V_25 = ( T_11 * ) V_172 -> V_84 ;
T_12 V_180 ;
T_7 V_181 ;
struct V_130 V_182 ;
if ( V_25 -> V_178 ) {
V_25 -> V_178 = FALSE ;
V_25 -> V_179 = V_111 -> V_115 ;
}
memset ( & V_182 , '\0' , sizeof( V_182 ) ) ;
V_180 = ( ( T_12 ) V_111 -> V_115 . V_116 - ( T_12 ) V_25 -> V_179 . V_116 ) * 1000000
+ ( ( T_12 ) V_111 -> V_115 . V_117 ) / 1000 ;
V_181 = ( T_7 ) ( V_180 % F_23 ( 4294967296 ) ) ;
V_182 . V_47 = F_24 ( V_181 ) ;
V_181 = ( T_7 ) ( V_180 / F_23 ( 4294967296 ) ) ;
V_182 . V_48 = F_24 ( V_181 ) ;
V_182 . V_121 = F_25 ( V_111 -> V_107 ) ;
V_182 . V_109 = F_25 ( V_111 -> V_118 ) ;
switch ( V_111 -> V_190 ) {
case V_22 :
V_182 . V_134 [ 12 ] = V_112 -> V_135 . V_137 ;
V_182 . V_134 [ 13 ] = ( T_8 ) V_112 -> V_135 . V_138 ;
V_182 . V_134 [ 14 ] = V_112 -> V_135 . V_139 ;
break;
case V_72 :
case V_81 :
V_182 . V_134 [ 12 ] |= V_112 -> V_145 . V_146 ? 0x01 : 0x00 ;
break;
case V_74 :
V_182 . V_134 [ 12 ] |= ( V_112 -> V_142 . V_143 & V_144 ) ? 0x00 : 0x01 ;
break;
}
if ( ! F_26 ( V_172 , & V_182 , sizeof( V_182 ) , V_2 ) )
return FALSE ;
V_172 -> V_177 += sizeof( V_182 ) ;
if ( ! F_26 ( V_172 , V_102 , V_111 -> V_118 , V_2 ) )
return FALSE ;
V_172 -> V_177 += V_111 -> V_118 ;
V_25 -> V_93 ++ ;
return TRUE ;
}
static T_3 V_189 ( T_10 * V_172 , int * V_2 )
{
char V_183 [ V_105 - sizeof( V_30 ) ] ;
T_11 * V_25 = ( T_11 * ) V_172 -> V_84 ;
T_6 V_184 ;
struct V_8 V_185 ;
if ( - 1 == ( V_184 = F_27 ( V_172 , V_2 ) ) )
return FALSE ;
if ( F_22 ( V_172 , 0 , V_96 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_26 ( V_172 , V_30 , sizeof V_30 , V_2 ) )
return FALSE ;
memset ( & V_185 , '\0' , sizeof V_185 ) ;
memcpy ( V_185 . V_33 , V_40 , sizeof V_40 ) ;
V_185 . V_90 = F_24 ( V_25 -> V_179 . V_116 ) ;
V_185 . V_93 = F_24 ( V_25 -> V_93 ) ;
V_185 . V_94 = F_24 ( V_105 ) ;
V_185 . V_95 = F_24 ( ( T_7 ) V_184 ) ;
V_185 . V_45 = F_28 ( V_172 -> V_164 ) ;
V_185 . V_47 = F_24 ( 0 ) ;
V_185 . V_48 = F_24 ( 0 ) ;
switch ( V_172 -> V_164 ) {
case V_72 :
V_185 . V_52 = V_71 ;
break;
case V_74 :
V_185 . V_52 = V_73 ;
break;
case V_78 :
V_185 . V_52 = V_75 ;
V_185 . V_77 = 0 ;
break;
case V_81 :
V_185 . V_52 = V_80 ;
break;
default:
V_185 . V_52 = V_53 ;
break;
}
memset ( V_183 , '\0' , sizeof V_183 ) ;
memcpy ( V_183 , & V_185 , sizeof( V_185 ) ) ;
if ( ! F_26 ( V_172 , V_183 , sizeof V_183 , V_2 ) )
return FALSE ;
return TRUE ;
}
