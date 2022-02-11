int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ sizeof F_2 ] ;
T_3 V_6 ;
struct V_7 V_8 ;
T_4 V_9 ;
double V_10 ;
int V_11 , V_12 ;
int V_13 ;
double V_14 ;
static const int V_15 [] = {
V_16 ,
V_17 ,
V_18 ,
V_19 ,
V_17 ,
V_16 ,
V_16 ,
V_16 ,
V_16 ,
V_20 ,
V_21 ,
V_16
} ;
#define F_3 (sizeof netxray_encap / sizeof netxray_encap[0])
int V_22 ;
T_4 V_23 = 0 ;
T_5 * V_24 ;
V_25 = V_26 ;
V_4 = F_4 ( V_5 , sizeof V_5 , V_1 -> V_27 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_5 ( V_1 -> V_27 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , F_2 , sizeof V_5 ) == 0 ) {
V_6 = FALSE ;
} else if ( memcmp ( V_5 , V_28 , sizeof V_5 ) == 0 ) {
V_6 = TRUE ;
} else {
return 0 ;
}
V_25 = V_26 ;
V_4 = F_4 ( & V_8 , sizeof V_8 , V_1 -> V_27 ) ;
if ( V_4 != sizeof V_8 ) {
* V_2 = F_5 ( V_1 -> V_27 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if ( V_6 ) {
V_11 = 0 ;
V_12 = 0 ;
V_13 = V_29 ;
} else {
if ( memcmp ( V_8 . V_30 , V_31 , sizeof V_31 ) == 0 ) {
V_11 = 1 ;
V_12 = 0 ;
V_13 = V_32 ;
} else if ( memcmp ( V_8 . V_30 , V_33 , sizeof V_33 ) == 0 ) {
V_11 = 1 ;
V_12 = 1 ;
V_13 = V_34 ;
} else if ( memcmp ( V_8 . V_30 , V_35 , sizeof V_35 ) == 0 ) {
V_11 = 2 ;
V_12 = 0 ;
V_13 = V_36 ;
} else if ( memcmp ( V_8 . V_30 , V_37 , sizeof V_37 ) == 0 ) {
V_11 = 2 ;
V_12 = 1 ;
V_13 = V_36 ;
} else if ( memcmp ( V_8 . V_30 , V_38 , sizeof V_38 ) == 0 ) {
V_11 = 2 ;
V_12 = 2 ;
V_13 = V_36 ;
} else if ( memcmp ( V_8 . V_30 , V_39 , sizeof V_39 ) == 0 ) {
V_11 = 2 ;
V_12 = 3 ;
V_13 = V_36 ;
} else {
* V_2 = V_40 ;
* V_3 = F_6 ( L_1 , V_8 . V_30 ) ;
return - 1 ;
}
}
switch ( V_8 . V_41 ) {
case 0 :
V_9 = V_8 . V_42 + 1 ;
break;
case 2 :
V_9 = V_8 . V_42 ;
break;
default:
* V_2 = V_40 ;
* V_3 = F_6 ( L_2 ,
V_8 . V_41 ) ;
return - 1 ;
}
if ( V_9 >= F_3
|| V_15 [ V_9 ] == V_16 ) {
* V_2 = V_43 ;
* V_3 = F_6 ( L_3 ,
V_9 , V_8 . V_41 ) ;
return - 1 ;
}
V_14 = ( double ) F_7 ( & V_8 . V_44 )
+ ( double ) F_7 ( & V_8 . V_45 ) * 4294967296.0 ;
switch ( V_13 ) {
case V_29 :
V_10 = 1000.0 ;
V_1 -> V_46 = V_47 ;
break;
case V_32 :
V_10 = 1000.0 ;
V_1 -> V_46 = V_47 ;
break;
case V_34 :
V_10 = 1000000.0 ;
V_1 -> V_46 = V_48 ;
break;
case V_36 :
switch ( V_9 ) {
case 1 :
switch ( V_8 . V_49 ) {
case V_50 :
if ( V_8 . V_51 >= V_52 ) {
* V_2 = V_40 ;
* V_3 = F_6 (
L_4 ,
V_8 . V_51 , V_8 . V_30 ) ;
return - 1 ;
}
if ( V_8 . V_51 == 2 ) {
V_10 = F_7 ( V_8 . V_53 ) ;
}
else {
V_10 = V_54 [ V_8 . V_51 ] ;
}
break;
case V_55 :
if ( V_8 . V_51 >= V_56
|| V_57 [ V_8 . V_51 ] == 0.0 ) {
* V_2 = V_40 ;
* V_3 = F_6 (
L_5 ,
V_8 . V_51 , V_8 . V_30 ) ;
return - 1 ;
}
V_10 = V_57 [ V_8 . V_51 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_58 :
if ( V_8 . V_51 >= V_59
|| V_60 [ V_8 . V_51 ] == 0.0 ) {
* V_2 = V_40 ;
* V_3 = F_6 (
L_6 ,
V_8 . V_51 , V_8 . V_30 ) ;
return - 1 ;
}
V_10 = V_60 [ V_8 . V_51 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_61 :
if ( V_8 . V_51 >= V_62
|| V_63 [ V_8 . V_51 ] == 0.0 ) {
* V_2 = V_40 ;
* V_3 = F_6 (
L_7 ,
V_8 . V_51 , V_8 . V_30 ) ;
return - 1 ;
}
V_10 = V_63 [ V_8 . V_51 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_64 :
if ( V_8 . V_51 >= V_65
|| V_66 [ V_8 . V_51 ] == 0.0 ) {
* V_2 = V_40 ;
* V_3 = F_6 (
L_8 ,
V_8 . V_51 , V_8 . V_30 ) ;
return - 1 ;
}
V_10 = V_66 [ V_8 . V_51 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
default:
* V_2 = V_40 ;
* V_3 = F_6 (
L_9 ,
V_8 . V_49 , V_8 . V_30 ) ;
return - 1 ;
}
break;
default:
if ( V_8 . V_51 >= V_52 ) {
* V_2 = V_40 ;
* V_3 = F_6 (
L_10 ,
V_8 . V_51 , V_9 , V_8 . V_49 ,
V_8 . V_30 ) ;
return - 1 ;
}
V_10 = V_54 [ V_8 . V_51 ] ;
break;
}
if ( V_10 >= 1e7 )
V_1 -> V_46 = V_67 ;
else
V_1 -> V_46 = V_48 ;
break;
default:
F_8 () ;
V_10 = 0.0 ;
}
V_14 = V_14 / V_10 ;
if ( V_9 == 4 ) {
if ( V_11 == 2 ) {
switch ( V_8 . V_49 ) {
case V_68 :
V_22 = V_69 ;
break;
case V_70 :
V_22 = V_71 ;
break;
case V_72 :
case V_73 :
switch ( V_8 . V_74 ) {
case 0 :
V_22 = V_75 ;
break;
case 1 :
case 2 :
case 3 :
V_22 = V_76 ;
V_23 = V_8 . V_74 ;
break;
default:
* V_2 = V_43 ;
* V_3 = F_6 ( L_11 ,
V_8 . V_74 ) ;
return - 1 ;
}
break;
case V_77 :
V_22 = V_78 ;
break;
case V_79 :
V_22 = V_80 ;
break;
default:
* V_2 = V_43 ;
* V_3 = F_6 ( L_12 ,
V_8 . V_49 ) ;
return - 1 ;
}
} else
V_22 = V_17 ;
} else
V_22 = V_15 [ V_9 ] ;
V_1 -> V_13 = V_13 ;
V_24 = ( T_5 * ) F_9 ( sizeof( T_5 ) ) ;
V_1 -> V_81 = ( void * ) V_24 ;
V_1 -> V_82 = V_83 ;
V_1 -> V_84 = V_85 ;
V_1 -> V_22 = V_22 ;
V_1 -> V_86 = 0 ;
V_24 -> V_87 = F_7 ( & V_8 . V_87 ) ;
V_24 -> V_10 = V_10 ;
V_24 -> V_14 = V_14 ;
V_24 -> V_11 = V_11 ;
V_24 -> V_88 = FALSE ;
switch ( V_22 ) {
case V_17 :
case V_21 :
case V_76 :
case V_75 :
if ( V_11 == 2 ) {
if ( V_8 . V_53 [ 1 ] == 0x34 && V_8 . V_53 [ 2 ] == 0x12 )
V_24 -> V_88 = TRUE ;
}
break;
}
V_24 -> V_23 = V_23 ;
V_24 -> V_89 = FALSE ;
V_24 -> V_90 = F_7 ( & V_8 . V_90 ) ;
V_24 -> V_91 = F_7 ( & V_8 . V_91 ) ;
V_24 -> V_92 = F_7 ( & V_8 . V_92 ) ;
if ( F_10 ( V_1 -> V_27 , V_24 -> V_91 , V_93 , V_2 ) == - 1 ) {
F_11 ( V_24 ) ;
return - 1 ;
}
return 1 ;
}
static T_3 V_83 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_94 )
{
T_5 * V_24 = ( T_5 * ) V_1 -> V_81 ;
T_7 V_95 ;
union V_96 V_8 ;
int V_97 ;
double V_98 ;
T_8 * V_99 ;
T_4 V_100 ;
V_101:
* V_94 = F_12 ( V_1 -> V_27 ) ;
if ( * V_94 == V_24 -> V_92 ) {
* V_2 = 0 ;
return FALSE ;
}
V_97 = F_13 ( V_1 , V_1 -> V_27 , & V_8 , V_2 , V_3 ) ;
if ( V_97 == 0 ) {
if ( * V_2 != 0 ) {
return FALSE ;
}
if ( V_24 -> V_91 < V_24 -> V_92 ) {
* V_2 = V_102 ;
return FALSE ;
}
if ( ! V_24 -> V_89 ) {
V_24 -> V_89 = TRUE ;
if ( F_10 ( V_1 -> V_27 , V_103 ,
V_93 , V_2 ) == - 1 )
return FALSE ;
goto V_101;
}
return FALSE ;
}
if ( V_24 -> V_11 == 0 )
V_95 = F_14 ( & V_8 . V_104 . V_105 ) ;
else
V_95 = F_14 ( & V_8 . V_106 . V_107 ) ;
F_15 ( V_1 -> V_108 , V_95 ) ;
V_99 = F_16 ( V_1 -> V_108 ) ;
if ( ! F_17 ( V_1 -> V_27 , V_99 , V_95 , V_2 , V_3 ) )
return FALSE ;
V_100 = F_18 ( V_1 , V_99 , V_95 ,
& V_1 -> V_109 , & V_8 ) ;
if ( V_24 -> V_11 == 0 ) {
V_1 -> V_110 . V_111 = V_112 ;
V_98 = ( double ) F_7 ( & V_8 . V_104 . V_44 )
+ ( double ) F_7 ( & V_8 . V_104 . V_45 ) * 4294967296.0 ;
V_98 /= V_24 -> V_10 ;
V_98 -= V_24 -> V_14 ;
V_1 -> V_110 . V_113 . V_114 = V_24 -> V_87 + ( long ) V_98 ;
V_1 -> V_110 . V_113 . V_115 = ( int ) ( ( V_98 - ( double ) ( unsigned long ) ( V_98 ) )
* 1.0e9 ) ;
V_1 -> V_110 . V_116 = V_95 - V_100 ;
V_1 -> V_110 . V_105 = V_1 -> V_110 . V_116 ;
} else {
V_1 -> V_110 . V_111 = V_112 | V_117 ;
V_98 = ( double ) F_7 ( & V_8 . V_106 . V_44 )
+ ( double ) F_7 ( & V_8 . V_106 . V_45 ) * 4294967296.0 ;
V_98 /= V_24 -> V_10 ;
V_98 -= V_24 -> V_14 ;
V_1 -> V_110 . V_113 . V_114 = V_24 -> V_87 + ( V_118 ) V_98 ;
V_1 -> V_110 . V_113 . V_115 = ( int ) ( ( V_98 - ( double ) ( unsigned long ) ( V_98 ) )
* 1.0e9 ) ;
V_1 -> V_110 . V_116 = V_95 - V_100 ;
V_1 -> V_110 . V_105 = F_14 ( & V_8 . V_106 . V_119 ) - V_100 ;
}
return TRUE ;
}
static T_3
V_85 ( T_1 * V_1 , T_6 V_120 ,
union V_121 * V_109 , T_8 * V_99 , int V_122 ,
int * V_2 , T_2 * * V_3 )
{
union V_96 V_8 ;
T_3 V_123 ;
if ( F_10 ( V_1 -> V_124 , V_120 , V_93 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_13 ( V_1 , V_1 -> V_124 , & V_8 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 ) {
* V_2 = V_102 ;
}
return FALSE ;
}
V_123 = F_17 ( V_1 -> V_124 , V_99 , V_122 , V_2 , V_3 ) ;
if ( ! V_123 )
return FALSE ;
F_18 ( V_1 , V_99 , V_122 , V_109 , & V_8 ) ;
return TRUE ;
}
static int
F_13 ( T_1 * V_1 , T_9 V_27 , union V_96 * V_8 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_24 = ( T_5 * ) V_1 -> V_81 ;
int V_4 ;
int V_97 = 0 ;
switch ( V_24 -> V_11 ) {
case 0 :
V_97 = sizeof ( struct V_125 ) ;
break;
case 1 :
V_97 = sizeof ( struct V_126 ) ;
break;
case 2 :
V_97 = sizeof ( struct V_127 ) ;
break;
}
V_25 = V_26 ;
V_4 = F_4 ( V_8 , V_97 , V_27 ) ;
if ( V_4 != V_97 ) {
* V_2 = F_5 ( V_1 -> V_27 , V_3 ) ;
if ( * V_2 != 0 )
return 0 ;
if ( V_4 != 0 ) {
* V_2 = V_102 ;
return 0 ;
}
return 0 ;
}
return V_97 ;
}
static T_4
F_18 ( T_1 * V_1 , const T_8 * V_99 , int V_105 ,
union V_121 * V_109 , union V_96 * V_8 )
{
T_5 * V_24 = ( T_5 * ) V_1 -> V_81 ;
T_4 V_100 = 0 ;
switch ( V_24 -> V_11 ) {
case 1 :
switch ( V_1 -> V_22 ) {
case V_17 :
V_109 -> V_128 . V_129 = 0 ;
break;
}
break;
case 2 :
switch ( V_1 -> V_22 ) {
case V_17 :
if ( V_8 -> V_130 . V_131 [ 2 ] == 0xff &&
V_8 -> V_130 . V_131 [ 3 ] == 0xff ) {
if ( V_24 -> V_88 ) {
V_109 -> V_128 . V_129 = 4 ;
} else {
V_100 = 4 ;
}
} else
V_109 -> V_128 . V_129 = 0 ;
break;
case V_21 :
if ( V_8 -> V_130 . V_131 [ 2 ] == 0xff &&
V_8 -> V_130 . V_131 [ 3 ] == 0xff ) {
if ( V_24 -> V_88 ) {
V_109 -> V_132 . V_129 = 4 ;
} else {
V_100 = 4 ;
}
} else
V_109 -> V_132 . V_129 = 0 ;
V_109 -> V_132 . V_133 =
V_8 -> V_130 . V_131 [ 12 ] ;
V_109 -> V_132 . V_134 =
V_8 -> V_130 . V_131 [ 13 ] ;
V_109 -> V_132 . V_135 =
V_8 -> V_130 . V_131 [ 14 ] ;
break;
case V_76 :
V_109 -> V_136 . V_137 =
( V_8 -> V_130 . V_131 [ 12 ] & 0x01 ) ;
V_109 -> V_136 . V_133 =
V_8 -> V_130 . V_131 [ 13 ] & 0x1F ;
switch ( V_24 -> V_23 ) {
case 1 :
if ( V_109 -> V_136 . V_133 == 16 )
V_109 -> V_136 . V_133 = 0 ;
else if ( V_109 -> V_136 . V_133 > 16 )
V_109 -> V_136 . V_133 -= 1 ;
break;
case 2 :
if ( V_109 -> V_136 . V_133 == 24 )
V_109 -> V_136 . V_133 = 0 ;
else if ( V_109 -> V_136 . V_133 > 24 )
V_109 -> V_136 . V_133 -= 1 ;
break;
}
if ( V_8 -> V_130 . V_131 [ 2 ] == 0xff &&
V_8 -> V_130 . V_131 [ 3 ] == 0xff ) {
V_100 = 4 ;
}
break;
case V_75 :
case V_71 :
V_109 -> V_138 . V_139 =
( V_8 -> V_130 . V_131 [ 12 ] & 0x01 ) ? 0x00 : V_140 ;
if ( V_8 -> V_130 . V_131 [ 2 ] == 0xff &&
V_8 -> V_130 . V_131 [ 3 ] == 0xff ) {
V_100 = 4 ;
}
break;
case V_69 :
case V_78 :
case V_80 :
V_109 -> V_141 . V_142 =
( V_8 -> V_130 . V_131 [ 12 ] & 0x01 ) ? TRUE : FALSE ;
break;
case V_20 :
V_109 -> V_143 . V_139 = 0 ;
if ( V_8 -> V_130 . V_131 [ 9 ] & 0x04 )
V_109 -> V_143 . V_139 |= V_144 ;
V_109 -> V_143 . V_145 = V_8 -> V_130 . V_131 [ 11 ] ;
V_109 -> V_143 . V_146 = F_14 ( & V_8 -> V_130 . V_131 [ 12 ] ) ;
V_109 -> V_143 . V_133 =
( V_8 -> V_130 . V_131 [ 15 ] & 0x10 ) ? 1 : 0 ;
V_109 -> V_143 . V_147 = 0 ;
switch ( V_8 -> V_130 . V_131 [ 0 ] & 0xF0 ) {
case 0x00 :
F_19 ( V_99 , V_105 ,
V_109 ) ;
break;
case 0x50 :
V_109 -> V_143 . V_148 = V_149 ;
switch ( V_8 -> V_130 . V_131 [ 0 ] & 0x0F ) {
case 0x09 :
case 0x0a :
V_109 -> V_143 . V_148 = V_150 ;
V_109 -> V_143 . type = V_151 ;
V_109 -> V_143 . V_152 = V_153 ;
break;
case 0x0b :
V_109 -> V_143 . type = V_154 ;
V_109 -> V_143 . V_152 = V_153 ;
break;
case 0x0c :
V_109 -> V_143 . type = V_155 ;
V_109 -> V_143 . V_152 = V_156 ;
break;
case 0x0d :
V_109 -> V_143 . type = V_155 ;
F_20 ( V_99 , V_105 ,
V_109 ) ;
break;
case 0x0f :
V_109 -> V_143 . type = V_157 ;
V_109 -> V_143 . V_152 = V_153 ;
break;
default:
V_109 -> V_143 . type = V_151 ;
V_109 -> V_143 . V_152 = V_153 ;
break;
}
break;
default:
V_109 -> V_143 . V_148 = V_158 ;
V_109 -> V_143 . type = V_151 ;
V_109 -> V_143 . V_152 = V_153 ;
break;
}
break;
}
break;
}
return V_100 ;
}
static T_3
F_17 ( T_9 V_27 , T_8 * V_159 , T_7 V_95 ,
int * V_2 , T_2 * * V_3 )
{
int V_4 ;
V_25 = V_26 ;
V_4 = F_4 ( V_159 , V_95 , V_27 ) ;
if ( V_4 <= 0 || ( T_7 ) V_4 != V_95 ) {
* V_2 = F_5 ( V_27 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_102 ;
return FALSE ;
}
return TRUE ;
}
static int
F_21 ( int V_160 )
{
unsigned int V_161 ;
for ( V_161 = 0 ; V_161 < V_162 ; V_161 ++ ) {
if ( V_160 == V_163 [ V_161 ] . V_164 )
return V_163 [ V_161 ] . V_165 ;
}
return - 1 ;
}
int F_22 ( int V_160 )
{
if ( V_160 == V_166 )
return V_167 ;
if ( F_21 ( V_160 ) == - 1 )
return V_43 ;
return 0 ;
}
T_3 F_23 ( T_10 * V_168 , int * V_2 )
{
T_11 * V_24 ;
V_168 -> V_169 = V_170 ;
V_168 -> V_171 = V_172 ;
if ( fseek ( V_168 -> V_27 , V_103 , V_93 ) == - 1 ) {
* V_2 = V_25 ;
return FALSE ;
}
V_168 -> V_173 += V_103 ;
V_24 = ( T_11 * ) F_9 ( sizeof( T_11 ) ) ;
V_168 -> V_81 = ( void * ) V_24 ;
V_24 -> V_174 = TRUE ;
V_24 -> V_175 . V_114 = 0 ;
V_24 -> V_175 . V_115 = 0 ;
V_24 -> V_90 = 0 ;
return TRUE ;
}
static T_3 V_170 ( T_10 * V_168 ,
const struct V_176 * V_110 ,
const union V_121 * V_109 V_177 ,
const T_8 * V_99 , int * V_2 )
{
T_11 * V_24 = ( T_11 * ) V_168 -> V_81 ;
T_12 V_178 ;
T_7 V_179 ;
struct V_126 V_180 ;
if ( V_24 -> V_174 ) {
V_24 -> V_174 = FALSE ;
V_24 -> V_175 = V_110 -> V_113 ;
}
memset ( & V_180 , '\0' , sizeof( V_180 ) ) ;
V_178 = ( ( T_12 ) V_110 -> V_113 . V_114 - ( T_12 ) V_24 -> V_175 . V_114 ) * 1000000
+ ( ( T_12 ) V_110 -> V_113 . V_115 ) / 1000 ;
V_179 = ( T_7 ) ( V_178 % F_24 ( 4294967296 ) ) ;
V_180 . V_44 = F_25 ( V_179 ) ;
V_179 = ( T_7 ) ( V_178 / F_24 ( 4294967296 ) ) ;
V_180 . V_45 = F_25 ( V_179 ) ;
V_180 . V_119 = F_26 ( V_110 -> V_105 ) ;
V_180 . V_107 = F_26 ( V_110 -> V_116 ) ;
if ( ! F_27 ( V_168 , & V_180 , sizeof( V_180 ) , V_2 ) )
return FALSE ;
V_168 -> V_173 += sizeof( V_180 ) ;
if ( ! F_27 ( V_168 , V_99 , V_110 -> V_116 , V_2 ) )
return FALSE ;
V_168 -> V_173 += V_110 -> V_116 ;
V_24 -> V_90 ++ ;
return TRUE ;
}
static T_3 V_172 ( T_10 * V_168 , int * V_2 )
{
char V_181 [ V_103 - sizeof( F_2 ) ] ;
T_11 * V_24 = ( T_11 * ) V_168 -> V_81 ;
T_7 V_182 ;
struct V_7 V_183 ;
V_182 = ( T_7 ) ftell ( V_168 -> V_27 ) ;
fseek ( V_168 -> V_27 , 0 , V_93 ) ;
if ( ! F_27 ( V_168 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
memset ( & V_183 , '\0' , sizeof V_183 ) ;
memcpy ( V_183 . V_30 , V_33 , sizeof V_33 ) ;
V_183 . V_87 = F_25 ( V_24 -> V_175 . V_114 ) ;
V_183 . V_90 = F_25 ( V_24 -> V_90 ) ;
V_183 . V_91 = F_25 ( V_103 ) ;
V_183 . V_92 = F_25 ( V_182 ) ;
V_183 . V_42 = F_21 ( V_168 -> V_160 ) ;
V_183 . V_44 = F_25 ( 0 ) ;
V_183 . V_45 = F_25 ( 0 ) ;
memset ( V_181 , '\0' , sizeof V_181 ) ;
memcpy ( V_181 , & V_183 , sizeof( V_183 ) ) ;
if ( ! F_27 ( V_168 , V_181 , sizeof V_181 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_28 ( int V_160 )
{
unsigned int V_161 ;
for ( V_161 = 0 ; V_161 < V_184 ; V_161 ++ ) {
if ( V_160 == V_185 [ V_161 ] . V_164 )
return V_185 [ V_161 ] . V_165 ;
}
return - 1 ;
}
int F_29 ( int V_160 )
{
if ( V_160 == V_166 )
return V_167 ;
if ( F_28 ( V_160 ) == - 1 )
return V_43 ;
return 0 ;
}
T_3 F_30 ( T_10 * V_168 , int * V_2 )
{
T_11 * V_24 ;
V_168 -> V_169 = V_186 ;
V_168 -> V_171 = V_187 ;
if ( fseek ( V_168 -> V_27 , V_103 , V_93 ) == - 1 ) {
* V_2 = V_25 ;
return FALSE ;
}
V_168 -> V_173 += V_103 ;
V_24 = ( T_11 * ) F_9 ( sizeof( T_11 ) ) ;
V_168 -> V_81 = ( void * ) V_24 ;
V_24 -> V_174 = TRUE ;
V_24 -> V_175 . V_114 = 0 ;
V_24 -> V_175 . V_115 = 0 ;
V_24 -> V_90 = 0 ;
return TRUE ;
}
static T_3 V_186 ( T_10 * V_168 ,
const struct V_176 * V_110 ,
const union V_121 * V_109 V_177 ,
const T_8 * V_99 , int * V_2 )
{
T_11 * V_24 = ( T_11 * ) V_168 -> V_81 ;
T_12 V_178 ;
T_7 V_179 ;
struct V_127 V_180 ;
if ( V_24 -> V_174 ) {
V_24 -> V_174 = FALSE ;
V_24 -> V_175 = V_110 -> V_113 ;
}
memset ( & V_180 , '\0' , sizeof( V_180 ) ) ;
V_178 = ( ( T_12 ) V_110 -> V_113 . V_114 - ( T_12 ) V_24 -> V_175 . V_114 ) * 1000000
+ ( ( T_12 ) V_110 -> V_113 . V_115 ) / 1000 ;
V_179 = ( T_7 ) ( V_178 % F_24 ( 4294967296 ) ) ;
V_180 . V_44 = F_25 ( V_179 ) ;
V_179 = ( T_7 ) ( V_178 / F_24 ( 4294967296 ) ) ;
V_180 . V_45 = F_25 ( V_179 ) ;
V_180 . V_119 = F_26 ( V_110 -> V_105 ) ;
V_180 . V_107 = F_26 ( V_110 -> V_116 ) ;
switch ( V_110 -> V_188 ) {
case V_21 :
V_180 . V_131 [ 12 ] = V_109 -> V_132 . V_133 ;
V_180 . V_131 [ 13 ] = ( T_8 ) V_109 -> V_132 . V_134 ;
V_180 . V_131 [ 14 ] = V_109 -> V_132 . V_135 ;
break;
case V_69 :
case V_78 :
V_180 . V_131 [ 12 ] |= V_109 -> V_141 . V_142 ? 0x01 : 0x00 ;
break;
case V_71 :
V_180 . V_131 [ 12 ] |= ( V_109 -> V_138 . V_139 & V_140 ) ? 0x00 : 0x01 ;
break;
}
if ( ! F_27 ( V_168 , & V_180 , sizeof( V_180 ) , V_2 ) )
return FALSE ;
V_168 -> V_173 += sizeof( V_180 ) ;
if ( ! F_27 ( V_168 , V_99 , V_110 -> V_116 , V_2 ) )
return FALSE ;
V_168 -> V_173 += V_110 -> V_116 ;
V_24 -> V_90 ++ ;
return TRUE ;
}
static T_3 V_187 ( T_10 * V_168 , int * V_2 )
{
char V_181 [ V_103 - sizeof( F_2 ) ] ;
T_11 * V_24 = ( T_11 * ) V_168 -> V_81 ;
T_7 V_182 ;
struct V_7 V_183 ;
V_182 = ( T_7 ) ftell ( V_168 -> V_27 ) ;
fseek ( V_168 -> V_27 , 0 , V_93 ) ;
if ( ! F_27 ( V_168 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
memset ( & V_183 , '\0' , sizeof V_183 ) ;
memcpy ( V_183 . V_30 , V_37 , sizeof V_37 ) ;
V_183 . V_87 = F_25 ( V_24 -> V_175 . V_114 ) ;
V_183 . V_90 = F_25 ( V_24 -> V_90 ) ;
V_183 . V_91 = F_25 ( V_103 ) ;
V_183 . V_92 = F_25 ( V_182 ) ;
V_183 . V_42 = F_28 ( V_168 -> V_160 ) ;
V_183 . V_44 = F_25 ( 0 ) ;
V_183 . V_45 = F_25 ( 0 ) ;
switch ( V_168 -> V_160 ) {
case V_69 :
V_183 . V_49 = V_68 ;
break;
case V_71 :
V_183 . V_49 = V_70 ;
break;
case V_75 :
V_183 . V_49 = V_72 ;
V_183 . V_74 = 0 ;
break;
case V_78 :
V_183 . V_49 = V_77 ;
break;
default:
V_183 . V_49 = V_50 ;
break;
}
memset ( V_181 , '\0' , sizeof V_181 ) ;
memcpy ( V_181 , & V_183 , sizeof( V_183 ) ) ;
if ( ! F_27 ( V_168 , V_181 , sizeof V_181 , V_2 ) )
return FALSE ;
return TRUE ;
}
