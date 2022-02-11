T_1
F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ V_5 ] ;
T_4 V_6 ;
struct V_7 V_8 ;
T_5 V_9 ;
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
#define F_2 (sizeof netxray_encap / sizeof netxray_encap[0])
int V_22 ;
T_5 V_23 = 0 ;
T_6 * V_24 ;
if ( ! F_3 ( V_1 -> V_25 , V_4 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 != V_26 )
return V_27 ;
return V_28 ;
}
if ( memcmp ( V_4 , V_29 , V_5 ) == 0 ) {
V_6 = FALSE ;
} else if ( memcmp ( V_4 , V_30 , V_5 ) == 0 ) {
V_6 = TRUE ;
} else {
return V_28 ;
}
if ( ! F_3 ( V_1 -> V_25 , & V_8 , sizeof V_8 , V_2 , V_3 ) )
return V_27 ;
if ( V_6 ) {
V_11 = 0 ;
V_12 = 0 ;
V_13 = V_31 ;
} else {
if ( memcmp ( V_8 . V_32 , V_33 , sizeof V_33 ) == 0 ) {
V_11 = 1 ;
V_12 = 0 ;
V_13 = V_34 ;
} else if ( memcmp ( V_8 . V_32 , V_35 , sizeof V_35 ) == 0 ) {
V_11 = 1 ;
V_12 = 1 ;
V_13 = V_36 ;
} else if ( memcmp ( V_8 . V_32 , V_37 , sizeof V_37 ) == 0 ) {
V_11 = 2 ;
V_12 = 0 ;
V_13 = V_38 ;
} else if ( memcmp ( V_8 . V_32 , V_39 , sizeof V_39 ) == 0 ) {
V_11 = 2 ;
V_12 = 1 ;
V_13 = V_38 ;
} else if ( memcmp ( V_8 . V_32 , V_40 , sizeof V_40 ) == 0 ) {
V_11 = 2 ;
V_12 = 2 ;
V_13 = V_38 ;
} else if ( memcmp ( V_8 . V_32 , V_41 , sizeof V_41 ) == 0 ) {
V_11 = 2 ;
V_12 = 3 ;
V_13 = V_38 ;
} else {
* V_2 = V_42 ;
* V_3 = F_4 ( L_1 , V_8 . V_32 ) ;
return V_27 ;
}
}
switch ( V_8 . V_43 ) {
case 0 :
V_9 = V_8 . V_44 + 1 ;
break;
case 2 :
V_9 = V_8 . V_44 ;
break;
default:
* V_2 = V_42 ;
* V_3 = F_4 ( L_2 ,
V_8 . V_43 ) ;
return V_27 ;
}
if ( V_9 >= F_2
|| V_15 [ V_9 ] == V_16 ) {
* V_2 = V_42 ;
* V_3 = F_4 ( L_3 ,
V_9 , V_8 . V_43 ) ;
return V_27 ;
}
V_14 = ( double ) F_5 ( & V_8 . V_45 )
+ ( double ) F_5 ( & V_8 . V_46 ) * 4294967296.0 ;
switch ( V_13 ) {
case V_31 :
V_10 = 1000.0 ;
V_1 -> V_47 = V_48 ;
break;
case V_34 :
V_10 = 1000.0 ;
V_1 -> V_47 = V_48 ;
break;
case V_36 :
V_10 = 1000000.0 ;
V_1 -> V_47 = V_49 ;
break;
case V_38 :
switch ( V_9 ) {
case 1 :
switch ( V_8 . V_50 ) {
case V_51 :
if ( V_8 . V_52 >= V_53 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_4 ,
V_8 . V_52 , V_8 . V_32 ) ;
return V_27 ;
}
if ( V_8 . V_52 == 2 ) {
V_10 = F_5 ( V_8 . V_54 ) ;
}
else {
V_10 = V_55 [ V_8 . V_52 ] ;
}
break;
case V_56 :
if ( V_8 . V_52 >= V_57
|| V_58 [ V_8 . V_52 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_5 ,
V_8 . V_52 , V_8 . V_32 ) ;
return V_27 ;
}
V_10 = V_58 [ V_8 . V_52 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_59 :
if ( V_8 . V_52 >= V_60
|| V_61 [ V_8 . V_52 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_6 ,
V_8 . V_52 , V_8 . V_32 ) ;
return V_27 ;
}
V_10 = V_61 [ V_8 . V_52 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_62 :
if ( V_8 . V_52 >= V_63
|| V_64 [ V_8 . V_52 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_7 ,
V_8 . V_52 , V_8 . V_32 ) ;
return V_27 ;
}
V_10 = V_64 [ V_8 . V_52 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_65 :
if ( V_8 . V_52 >= V_66
|| V_67 [ V_8 . V_52 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_8 ,
V_8 . V_52 , V_8 . V_32 ) ;
return V_27 ;
}
V_10 = V_67 [ V_8 . V_52 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
default:
* V_2 = V_42 ;
* V_3 = F_4 (
L_9 ,
V_8 . V_50 , V_8 . V_32 ) ;
return V_27 ;
}
break;
default:
if ( V_8 . V_52 >= V_53 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_10 ,
V_8 . V_52 , V_9 , V_8 . V_50 ,
V_8 . V_32 ) ;
return V_27 ;
}
V_10 = V_55 [ V_8 . V_52 ] ;
break;
}
if ( V_10 >= 1e7 )
V_1 -> V_47 = V_68 ;
else
V_1 -> V_47 = V_49 ;
break;
default:
F_6 () ;
V_10 = 0.0 ;
}
V_14 = V_14 / V_10 ;
if ( V_9 == 4 ) {
if ( V_11 == 2 ) {
switch ( V_8 . V_50 ) {
case V_69 :
V_22 = V_70 ;
break;
case V_71 :
V_22 = V_72 ;
break;
case V_73 :
case V_74 :
switch ( V_8 . V_75 ) {
case 0 :
V_22 = V_76 ;
break;
case 1 :
case 2 :
case 3 :
V_22 = V_77 ;
V_23 = V_8 . V_75 ;
break;
default:
* V_2 = V_42 ;
* V_3 = F_4 ( L_11 ,
V_8 . V_75 ) ;
return V_27 ;
}
break;
case V_78 :
V_22 = V_79 ;
break;
case V_80 :
V_22 = V_81 ;
break;
default:
* V_2 = V_42 ;
* V_3 = F_4 ( L_12 ,
V_8 . V_50 ) ;
return V_27 ;
}
} else
V_22 = V_17 ;
} else
V_22 = V_15 [ V_9 ] ;
V_1 -> V_82 = V_13 ;
V_24 = ( T_6 * ) F_7 ( sizeof( T_6 ) ) ;
V_1 -> V_83 = ( void * ) V_24 ;
V_1 -> V_84 = V_85 ;
V_1 -> V_86 = V_87 ;
V_1 -> V_22 = V_22 ;
V_1 -> V_88 = 0 ;
V_24 -> V_89 = F_5 ( & V_8 . V_89 ) ;
V_24 -> V_10 = V_10 ;
V_24 -> V_14 = V_14 ;
V_24 -> V_11 = V_11 ;
V_24 -> V_90 = FALSE ;
switch ( V_22 ) {
case V_17 :
case V_21 :
case V_77 :
case V_76 :
if ( V_11 == 2 ) {
if ( V_8 . V_54 [ 1 ] == 0x34 && V_8 . V_54 [ 2 ] == 0x12 )
V_24 -> V_90 = TRUE ;
}
break;
}
V_24 -> V_23 = V_23 ;
V_24 -> V_91 = FALSE ;
V_24 -> V_92 = F_5 ( & V_8 . V_92 ) ;
V_24 -> V_93 = F_5 ( & V_8 . V_93 ) ;
V_24 -> V_94 = F_5 ( & V_8 . V_94 ) ;
if ( F_8 ( V_1 -> V_25 , V_24 -> V_93 , V_95 , V_2 ) == - 1 ) {
return V_27 ;
}
return V_96 ;
}
static T_4
V_85 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_7 * V_97 )
{
T_6 * V_24 = ( T_6 * ) V_1 -> V_83 ;
int V_98 ;
V_99:
* V_97 = F_9 ( V_1 -> V_25 ) ;
if ( * V_97 == V_24 -> V_94 ) {
* V_2 = 0 ;
return FALSE ;
}
V_98 = F_10 ( V_1 , V_1 -> V_25 , & V_1 -> V_100 , V_2 ,
V_3 ) ;
if ( V_98 < 0 ) {
if ( * V_2 != 0 ) {
return FALSE ;
}
if ( V_24 -> V_93 < V_24 -> V_94 ) {
* V_2 = V_26 ;
return FALSE ;
}
if ( ! V_24 -> V_91 ) {
V_24 -> V_91 = TRUE ;
if ( F_8 ( V_1 -> V_25 , V_101 ,
V_95 , V_2 ) == - 1 )
return FALSE ;
goto V_99;
}
return FALSE ;
}
if ( ! F_11 ( V_1 -> V_25 , V_1 -> V_102 ,
V_1 -> V_100 . V_103 , V_2 , V_3 ) )
return FALSE ;
if ( F_8 ( V_1 -> V_25 , V_98 , V_104 , V_2 ) == - 1 )
return FALSE ;
F_12 ( V_1 , & V_1 -> V_100 , V_1 -> V_102 ) ;
return TRUE ;
}
static T_4
V_87 ( T_2 * V_1 , T_7 V_105 ,
struct V_106 * V_100 , T_8 * V_107 ,
int * V_2 , T_3 * * V_3 )
{
if ( F_8 ( V_1 -> V_108 , V_105 , V_95 , V_2 ) == - 1 )
return FALSE ;
if ( F_10 ( V_1 , V_1 -> V_108 , V_100 , V_2 ,
V_3 ) == - 1 ) {
if ( * V_2 == 0 ) {
* V_2 = V_26 ;
}
return FALSE ;
}
if ( ! F_11 ( V_1 -> V_108 , V_107 , V_100 -> V_103 , V_2 ,
V_3 ) )
return FALSE ;
F_12 ( V_1 , V_100 , V_107 ) ;
return TRUE ;
}
static int
F_10 ( T_2 * V_1 , T_9 V_25 , struct V_106 * V_100 ,
int * V_2 , T_3 * * V_3 )
{
T_6 * V_24 = ( T_6 * ) V_1 -> V_83 ;
union V_109 V_8 ;
int V_110 = 0 ;
double V_111 ;
int V_112 ;
int V_98 = 0 ;
switch ( V_24 -> V_11 ) {
case 0 :
V_110 = sizeof ( struct V_113 ) ;
break;
case 1 :
V_110 = sizeof ( struct V_114 ) ;
break;
case 2 :
V_110 = sizeof ( struct V_115 ) ;
break;
}
if ( ! F_13 ( V_25 , ( void * ) & V_8 , V_110 , V_2 , V_3 ) ) {
return - 1 ;
}
switch ( V_24 -> V_11 ) {
case 1 :
switch ( V_1 -> V_22 ) {
case V_17 :
V_100 -> V_116 . V_117 . V_118 = 0 ;
break;
}
break;
case 2 :
switch ( V_1 -> V_22 ) {
case V_17 :
if ( V_8 . V_119 . V_120 [ 2 ] == 0xff &&
V_8 . V_119 . V_120 [ 3 ] == 0xff ) {
if ( V_24 -> V_90 ) {
V_100 -> V_116 . V_117 . V_118 = 4 ;
} else {
V_98 = 4 ;
}
} else
V_100 -> V_116 . V_117 . V_118 = 0 ;
break;
case V_21 :
if ( V_8 . V_119 . V_120 [ 2 ] == 0xff &&
V_8 . V_119 . V_120 [ 3 ] == 0xff ) {
if ( V_24 -> V_90 ) {
V_100 -> V_116 . V_121 . V_118 = 4 ;
} else {
V_98 = 4 ;
}
} else
V_100 -> V_116 . V_121 . V_118 = 0 ;
V_100 -> V_116 . V_121 . V_122 = FALSE ;
V_100 -> V_116 . V_121 . V_123 = FALSE ;
V_100 -> V_116 . V_121 . V_124 = V_125 ;
V_100 -> V_116 . V_121 . V_126 =
V_8 . V_119 . V_120 [ 12 ] ;
V_100 -> V_116 . V_121 . V_127 =
V_8 . V_119 . V_120 [ 13 ] ;
V_100 -> V_116 . V_121 . V_128 =
V_8 . V_119 . V_120 [ 14 ] ;
if ( V_8 . V_119 . V_120 [ 15 ] == 0xFF ) {
V_100 -> V_116 . V_121 . V_129 =
V_130 |
V_131 |
V_132 ;
} else {
V_100 -> V_116 . V_121 . V_133 =
V_8 . V_119 . V_120 [ 15 ] * 100 / 127 ;
V_100 -> V_116 . V_121 . V_129 =
V_130 |
V_131 |
V_132 |
V_134 ;
}
break;
case V_77 :
V_100 -> V_116 . V_135 . V_136 =
( V_8 . V_119 . V_120 [ 12 ] & 0x01 ) ;
V_100 -> V_116 . V_135 . V_126 =
V_8 . V_119 . V_120 [ 13 ] & 0x1F ;
switch ( V_24 -> V_23 ) {
case 1 :
if ( V_100 -> V_116 . V_135 . V_126 == 16 )
V_100 -> V_116 . V_135 . V_126 = 0 ;
else if ( V_100 -> V_116 . V_135 . V_126 > 16 )
V_100 -> V_116 . V_135 . V_126 -= 1 ;
break;
case 2 :
if ( V_100 -> V_116 . V_135 . V_126 == 24 )
V_100 -> V_116 . V_135 . V_126 = 0 ;
else if ( V_100 -> V_116 . V_135 . V_126 > 24 )
V_100 -> V_116 . V_135 . V_126 -= 1 ;
break;
}
if ( V_8 . V_119 . V_120 [ 2 ] == 0xff &&
V_8 . V_119 . V_120 [ 3 ] == 0xff ) {
V_98 = 4 ;
}
break;
case V_76 :
case V_72 :
V_100 -> V_116 . V_137 . V_138 =
( V_8 . V_119 . V_120 [ 12 ] & 0x01 ) ? 0x00 : V_139 ;
if ( V_8 . V_119 . V_120 [ 2 ] == 0xff &&
V_8 . V_119 . V_120 [ 3 ] == 0xff ) {
V_98 = 4 ;
}
break;
case V_70 :
case V_79 :
case V_81 :
V_100 -> V_116 . V_140 . V_141 =
( V_8 . V_119 . V_120 [ 12 ] & 0x01 ) ? TRUE : FALSE ;
break;
case V_20 :
V_100 -> V_116 . V_142 . V_138 = 0 ;
if ( V_8 . V_119 . V_120 [ 8 ] & 0x01 )
V_100 -> V_116 . V_142 . V_138 |= V_143 ;
if ( V_8 . V_119 . V_120 [ 9 ] & 0x04 )
V_100 -> V_116 . V_142 . V_138 |= V_144 ;
V_100 -> V_116 . V_142 . V_145 = V_8 . V_119 . V_120 [ 11 ] ;
V_100 -> V_116 . V_142 . V_146 = F_14 ( & V_8 . V_119 . V_120 [ 12 ] ) ;
V_100 -> V_116 . V_142 . V_126 =
( V_8 . V_119 . V_120 [ 15 ] & 0x10 ) ? 1 : 0 ;
V_100 -> V_116 . V_142 . V_147 = 0 ;
switch ( V_8 . V_119 . V_120 [ 0 ] & 0x70 ) {
case 0x00 :
V_100 -> V_116 . V_142 . V_148 = V_149 ;
V_100 -> V_116 . V_142 . type = V_150 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x10 :
V_100 -> V_116 . V_142 . V_148 = V_149 ;
V_100 -> V_116 . V_142 . type = V_150 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x20 :
V_100 -> V_116 . V_142 . V_148 = V_149 ;
V_100 -> V_116 . V_142 . type = V_150 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x40 :
V_100 -> V_116 . V_142 . V_148 = V_149 ;
V_100 -> V_116 . V_142 . type = V_150 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x30 :
case 0x50 :
case 0x60 :
case 0x70 :
V_100 -> V_116 . V_142 . V_148 = V_153 ;
switch ( V_8 . V_119 . V_120 [ 0 ] & 0x07 ) {
case 0x01 :
case 0x02 :
V_100 -> V_116 . V_142 . V_148 = V_154 ;
V_100 -> V_116 . V_142 . type = V_150 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x03 :
V_100 -> V_116 . V_142 . type = V_155 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x00 :
case 0x04 :
case 0x05 :
V_100 -> V_116 . V_142 . type = V_156 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x06 :
V_100 -> V_116 . V_142 . type = V_150 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
case 0x07 :
V_100 -> V_116 . V_142 . type = V_157 ;
V_100 -> V_116 . V_142 . V_151 = V_152 ;
break;
}
break;
}
break;
}
break;
}
V_100 -> V_158 = V_159 ;
if ( V_24 -> V_11 == 0 ) {
V_100 -> V_129 = V_160 ;
V_111 = ( double ) F_5 ( & V_8 . V_161 . V_45 )
+ ( double ) F_5 ( & V_8 . V_161 . V_46 ) * 4294967296.0 ;
V_111 /= V_24 -> V_10 ;
V_111 -= V_24 -> V_14 ;
V_100 -> V_162 . V_163 = V_24 -> V_89 + ( long ) V_111 ;
V_100 -> V_162 . V_164 = ( int ) ( ( V_111 - ( double ) ( unsigned long ) ( V_111 ) )
* 1.0e9 ) ;
V_112 = F_14 ( & V_8 . V_161 . V_165 ) ;
V_100 -> V_103 = V_112 - V_98 ;
V_100 -> V_165 = V_100 -> V_103 ;
} else {
V_100 -> V_129 = V_160 | V_166 ;
V_111 = ( double ) F_5 ( & V_8 . V_167 . V_45 )
+ ( double ) F_5 ( & V_8 . V_167 . V_46 ) * 4294967296.0 ;
V_111 /= V_24 -> V_10 ;
V_111 -= V_24 -> V_14 ;
V_100 -> V_162 . V_163 = V_24 -> V_89 + ( V_168 ) V_111 ;
V_100 -> V_162 . V_164 = ( int ) ( ( V_111 - ( double ) ( unsigned long ) ( V_111 ) )
* 1.0e9 ) ;
V_112 = F_14 ( & V_8 . V_167 . V_169 ) ;
V_100 -> V_103 = V_112 - V_98 ;
V_100 -> V_165 = F_14 ( & V_8 . V_167 . V_170 ) - V_98 ;
}
return V_98 ;
}
static void
F_12 ( T_2 * V_1 , struct V_106 * V_100 , T_8 * V_107 )
{
const T_10 * V_171 ;
if ( V_1 -> V_22 == V_20 &&
! ( V_100 -> V_116 . V_142 . V_138 & V_143 ) ) {
if ( V_100 -> V_116 . V_142 . V_148 == V_149 ) {
V_171 = F_15 ( V_107 ) ;
F_16 ( V_100 , V_171 ) ;
} else if ( V_100 -> V_116 . V_142 . V_148 == V_153 &&
V_100 -> V_116 . V_142 . type == V_156 ) {
V_171 = F_15 ( V_107 ) ;
F_17 ( V_100 , V_171 ) ;
}
}
}
static int
F_18 ( int V_172 )
{
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_174 ; V_173 ++ ) {
if ( V_172 == V_175 [ V_173 ] . V_176 )
return V_175 [ V_173 ] . V_177 ;
}
return - 1 ;
}
int
F_19 ( int V_172 )
{
if ( V_172 == V_178 )
return V_179 ;
if ( F_18 ( V_172 ) == - 1 )
return V_180 ;
return 0 ;
}
T_4
F_20 ( T_11 * V_181 , int * V_2 )
{
T_12 * V_24 ;
V_181 -> V_182 = V_183 ;
V_181 -> V_184 = V_185 ;
if ( F_21 ( V_181 , V_101 , V_95 , V_2 ) == - 1 )
return FALSE ;
V_181 -> V_186 += V_101 ;
V_24 = ( T_12 * ) F_7 ( sizeof( T_12 ) ) ;
V_181 -> V_83 = ( void * ) V_24 ;
V_24 -> V_187 = TRUE ;
V_24 -> V_188 . V_163 = 0 ;
V_24 -> V_188 . V_164 = 0 ;
V_24 -> V_92 = 0 ;
return TRUE ;
}
static T_4
V_183 ( T_11 * V_181 ,
const struct V_106 * V_100 ,
const T_10 * V_171 , int * V_2 , T_3 * * V_3 V_189 )
{
T_12 * V_24 = ( T_12 * ) V_181 -> V_83 ;
T_13 V_190 ;
T_14 V_191 ;
struct V_114 V_192 ;
if ( V_100 -> V_158 != V_159 ) {
* V_2 = V_193 ;
return FALSE ;
}
if ( V_100 -> V_103 > 65535 ) {
* V_2 = V_194 ;
return FALSE ;
}
if ( V_24 -> V_187 ) {
V_24 -> V_187 = FALSE ;
V_24 -> V_188 = V_100 -> V_162 ;
}
memset ( & V_192 , '\0' , sizeof( V_192 ) ) ;
V_190 = ( ( T_13 ) V_100 -> V_162 . V_163 - ( T_13 ) V_24 -> V_188 . V_163 ) * 1000000
+ ( ( T_13 ) V_100 -> V_162 . V_164 ) / 1000 ;
V_191 = ( T_14 ) ( V_190 % F_22 ( 4294967296 ) ) ;
V_192 . V_45 = F_23 ( V_191 ) ;
V_191 = ( T_14 ) ( V_190 / F_22 ( 4294967296 ) ) ;
V_192 . V_46 = F_23 ( V_191 ) ;
V_192 . V_170 = F_24 ( V_100 -> V_165 ) ;
V_192 . V_169 = F_24 ( V_100 -> V_103 ) ;
if ( ! F_25 ( V_181 , & V_192 , sizeof( V_192 ) , V_2 ) )
return FALSE ;
V_181 -> V_186 += sizeof( V_192 ) ;
if ( ! F_25 ( V_181 , V_171 , V_100 -> V_103 , V_2 ) )
return FALSE ;
V_181 -> V_186 += V_100 -> V_103 ;
V_24 -> V_92 ++ ;
return TRUE ;
}
static T_4
V_185 ( T_11 * V_181 , int * V_2 )
{
char V_195 [ V_101 - sizeof( V_29 ) ] ;
T_12 * V_24 = ( T_12 * ) V_181 -> V_83 ;
T_7 V_196 ;
struct V_7 V_197 ;
if ( - 1 == ( V_196 = F_26 ( V_181 , V_2 ) ) )
return FALSE ;
if ( F_21 ( V_181 , 0 , V_95 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_25 ( V_181 , V_29 , sizeof V_29 , V_2 ) )
return FALSE ;
memset ( & V_197 , '\0' , sizeof V_197 ) ;
memcpy ( V_197 . V_32 , V_35 , sizeof V_35 ) ;
V_197 . V_89 = F_23 ( V_24 -> V_188 . V_163 ) ;
V_197 . V_92 = F_23 ( V_24 -> V_92 ) ;
V_197 . V_93 = F_23 ( V_101 ) ;
V_197 . V_94 = F_23 ( ( T_14 ) V_196 ) ;
V_197 . V_44 = F_18 ( V_181 -> V_172 ) ;
V_197 . V_45 = F_23 ( 0 ) ;
V_197 . V_46 = F_23 ( 0 ) ;
memset ( V_195 , '\0' , sizeof V_195 ) ;
memcpy ( V_195 , & V_197 , sizeof( V_197 ) ) ;
if ( ! F_25 ( V_181 , V_195 , sizeof V_195 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_27 ( int V_172 )
{
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_198 ; V_173 ++ ) {
if ( V_172 == V_199 [ V_173 ] . V_176 )
return V_199 [ V_173 ] . V_177 ;
}
return - 1 ;
}
int
F_28 ( int V_172 )
{
if ( V_172 == V_178 )
return V_179 ;
if ( F_27 ( V_172 ) == - 1 )
return V_180 ;
return 0 ;
}
T_4
F_29 ( T_11 * V_181 , int * V_2 )
{
T_12 * V_24 ;
V_181 -> V_182 = V_200 ;
V_181 -> V_184 = V_201 ;
if ( F_21 ( V_181 , V_101 , V_95 , V_2 ) == - 1 )
return FALSE ;
V_181 -> V_186 += V_101 ;
V_24 = ( T_12 * ) F_7 ( sizeof( T_12 ) ) ;
V_181 -> V_83 = ( void * ) V_24 ;
V_24 -> V_187 = TRUE ;
V_24 -> V_188 . V_163 = 0 ;
V_24 -> V_188 . V_164 = 0 ;
V_24 -> V_92 = 0 ;
return TRUE ;
}
static T_4
V_200 ( T_11 * V_181 ,
const struct V_106 * V_100 ,
const T_10 * V_171 , int * V_2 , T_3 * * V_3 V_189 )
{
const union V_202 * V_116 = & V_100 -> V_116 ;
T_12 * V_24 = ( T_12 * ) V_181 -> V_83 ;
T_13 V_190 ;
T_14 V_191 ;
struct V_115 V_192 ;
if ( V_100 -> V_158 != V_159 ) {
* V_2 = V_193 ;
return FALSE ;
}
if ( V_100 -> V_103 > V_203 ) {
* V_2 = V_194 ;
return FALSE ;
}
if ( V_24 -> V_187 ) {
V_24 -> V_187 = FALSE ;
V_24 -> V_188 = V_100 -> V_162 ;
}
memset ( & V_192 , '\0' , sizeof( V_192 ) ) ;
V_190 = ( ( T_13 ) V_100 -> V_162 . V_163 - ( T_13 ) V_24 -> V_188 . V_163 ) * 1000000
+ ( ( T_13 ) V_100 -> V_162 . V_164 ) / 1000 ;
V_191 = ( T_14 ) ( V_190 % F_22 ( 4294967296 ) ) ;
V_192 . V_45 = F_23 ( V_191 ) ;
V_191 = ( T_14 ) ( V_190 / F_22 ( 4294967296 ) ) ;
V_192 . V_46 = F_23 ( V_191 ) ;
V_192 . V_170 = F_24 ( V_100 -> V_165 ) ;
V_192 . V_169 = F_24 ( V_100 -> V_103 ) ;
switch ( V_100 -> V_204 ) {
case V_21 :
V_192 . V_120 [ 12 ] =
( V_116 -> V_121 . V_129 & V_130 ) ?
V_116 -> V_121 . V_126 :
0 ;
V_192 . V_120 [ 13 ] =
( V_116 -> V_121 . V_129 & V_131 ) ?
( T_10 ) V_116 -> V_121 . V_127 :
0 ;
V_192 . V_120 [ 14 ] =
( V_116 -> V_121 . V_129 & V_132 ) ?
V_116 -> V_121 . V_128 :
0 ;
V_192 . V_120 [ 15 ] =
( V_116 -> V_121 . V_129 & V_134 ) ?
V_116 -> V_121 . V_133 * 127 / 100 :
0xFF ;
break;
case V_70 :
case V_79 :
V_192 . V_120 [ 12 ] |= V_116 -> V_140 . V_141 ? 0x01 : 0x00 ;
break;
case V_72 :
V_192 . V_120 [ 12 ] |= ( V_116 -> V_137 . V_138 & V_139 ) ? 0x00 : 0x01 ;
break;
}
if ( ! F_25 ( V_181 , & V_192 , sizeof( V_192 ) , V_2 ) )
return FALSE ;
V_181 -> V_186 += sizeof( V_192 ) ;
if ( ! F_25 ( V_181 , V_171 , V_100 -> V_103 , V_2 ) )
return FALSE ;
V_181 -> V_186 += V_100 -> V_103 ;
V_24 -> V_92 ++ ;
return TRUE ;
}
static T_4
V_201 ( T_11 * V_181 , int * V_2 )
{
char V_195 [ V_101 - sizeof( V_29 ) ] ;
T_12 * V_24 = ( T_12 * ) V_181 -> V_83 ;
T_7 V_196 ;
struct V_7 V_197 ;
if ( - 1 == ( V_196 = F_26 ( V_181 , V_2 ) ) )
return FALSE ;
if ( F_21 ( V_181 , 0 , V_95 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_25 ( V_181 , V_29 , sizeof V_29 , V_2 ) )
return FALSE ;
memset ( & V_197 , '\0' , sizeof V_197 ) ;
memcpy ( V_197 . V_32 , V_39 , sizeof V_39 ) ;
V_197 . V_89 = F_23 ( V_24 -> V_188 . V_163 ) ;
V_197 . V_92 = F_23 ( V_24 -> V_92 ) ;
V_197 . V_93 = F_23 ( V_101 ) ;
V_197 . V_94 = F_23 ( ( T_14 ) V_196 ) ;
V_197 . V_44 = F_27 ( V_181 -> V_172 ) ;
V_197 . V_45 = F_23 ( 0 ) ;
V_197 . V_46 = F_23 ( 0 ) ;
switch ( V_181 -> V_172 ) {
case V_70 :
V_197 . V_50 = V_69 ;
break;
case V_72 :
V_197 . V_50 = V_71 ;
break;
case V_76 :
V_197 . V_50 = V_73 ;
V_197 . V_75 = 0 ;
break;
case V_79 :
V_197 . V_50 = V_78 ;
break;
default:
V_197 . V_50 = V_51 ;
break;
}
memset ( V_195 , '\0' , sizeof V_195 ) ;
memcpy ( V_195 , & V_197 , sizeof( V_197 ) ) ;
if ( ! F_25 ( V_181 , V_195 , sizeof V_195 , V_2 ) )
return FALSE ;
return TRUE ;
}
