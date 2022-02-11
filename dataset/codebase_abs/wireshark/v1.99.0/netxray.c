int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ V_5 ] ;
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
#define F_2 (sizeof netxray_encap / sizeof netxray_encap[0])
int V_22 ;
T_4 V_23 = 0 ;
T_5 * V_24 ;
V_25 = V_26 ;
if ( ! F_3 ( V_1 -> V_27 , V_4 , V_5 , V_2 , V_3 ) ) {
if ( * V_2 != V_28 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_4 , V_29 , V_5 ) == 0 ) {
V_6 = FALSE ;
} else if ( memcmp ( V_4 , V_30 , V_5 ) == 0 ) {
V_6 = TRUE ;
} else {
return 0 ;
}
V_25 = V_26 ;
if ( ! F_3 ( V_1 -> V_27 , & V_8 , sizeof V_8 , V_2 , V_3 ) )
return - 1 ;
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
return - 1 ;
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
return - 1 ;
}
if ( V_9 >= F_2
|| V_15 [ V_9 ] == V_16 ) {
* V_2 = V_45 ;
* V_3 = F_4 ( L_3 ,
V_9 , V_8 . V_43 ) ;
return - 1 ;
}
V_14 = ( double ) F_5 ( & V_8 . V_46 )
+ ( double ) F_5 ( & V_8 . V_47 ) * 4294967296.0 ;
switch ( V_13 ) {
case V_31 :
V_10 = 1000.0 ;
V_1 -> V_48 = V_49 ;
break;
case V_34 :
V_10 = 1000.0 ;
V_1 -> V_48 = V_49 ;
break;
case V_36 :
V_10 = 1000000.0 ;
V_1 -> V_48 = V_50 ;
break;
case V_38 :
switch ( V_9 ) {
case 1 :
switch ( V_8 . V_51 ) {
case V_52 :
if ( V_8 . V_53 >= V_54 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_4 ,
V_8 . V_53 , V_8 . V_32 ) ;
return - 1 ;
}
if ( V_8 . V_53 == 2 ) {
V_10 = F_5 ( V_8 . V_55 ) ;
}
else {
V_10 = V_56 [ V_8 . V_53 ] ;
}
break;
case V_57 :
if ( V_8 . V_53 >= V_58
|| V_59 [ V_8 . V_53 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_5 ,
V_8 . V_53 , V_8 . V_32 ) ;
return - 1 ;
}
V_10 = V_59 [ V_8 . V_53 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_60 :
if ( V_8 . V_53 >= V_61
|| V_62 [ V_8 . V_53 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_6 ,
V_8 . V_53 , V_8 . V_32 ) ;
return - 1 ;
}
V_10 = V_62 [ V_8 . V_53 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_63 :
if ( V_8 . V_53 >= V_64
|| V_65 [ V_8 . V_53 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_7 ,
V_8 . V_53 , V_8 . V_32 ) ;
return - 1 ;
}
V_10 = V_65 [ V_8 . V_53 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
case V_66 :
if ( V_8 . V_53 >= V_67
|| V_68 [ V_8 . V_53 ] == 0.0 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_8 ,
V_8 . V_53 , V_8 . V_32 ) ;
return - 1 ;
}
V_10 = V_68 [ V_8 . V_53 ] ;
if ( V_12 == 2 || V_12 == 3 )
V_14 = 0.0 ;
break;
default:
* V_2 = V_42 ;
* V_3 = F_4 (
L_9 ,
V_8 . V_51 , V_8 . V_32 ) ;
return - 1 ;
}
break;
default:
if ( V_8 . V_53 >= V_54 ) {
* V_2 = V_42 ;
* V_3 = F_4 (
L_10 ,
V_8 . V_53 , V_9 , V_8 . V_51 ,
V_8 . V_32 ) ;
return - 1 ;
}
V_10 = V_56 [ V_8 . V_53 ] ;
break;
}
if ( V_10 >= 1e7 )
V_1 -> V_48 = V_69 ;
else
V_1 -> V_48 = V_50 ;
break;
default:
F_6 () ;
V_10 = 0.0 ;
}
V_14 = V_14 / V_10 ;
if ( V_9 == 4 ) {
if ( V_11 == 2 ) {
switch ( V_8 . V_51 ) {
case V_70 :
V_22 = V_71 ;
break;
case V_72 :
V_22 = V_73 ;
break;
case V_74 :
case V_75 :
switch ( V_8 . V_76 ) {
case 0 :
V_22 = V_77 ;
break;
case 1 :
case 2 :
case 3 :
V_22 = V_78 ;
V_23 = V_8 . V_76 ;
break;
default:
* V_2 = V_45 ;
* V_3 = F_4 ( L_11 ,
V_8 . V_76 ) ;
return - 1 ;
}
break;
case V_79 :
V_22 = V_80 ;
break;
case V_81 :
V_22 = V_82 ;
break;
default:
* V_2 = V_45 ;
* V_3 = F_4 ( L_12 ,
V_8 . V_51 ) ;
return - 1 ;
}
} else
V_22 = V_17 ;
} else
V_22 = V_15 [ V_9 ] ;
V_1 -> V_83 = V_13 ;
V_24 = ( T_5 * ) F_7 ( sizeof( T_5 ) ) ;
V_1 -> V_84 = ( void * ) V_24 ;
V_1 -> V_85 = V_86 ;
V_1 -> V_87 = V_88 ;
V_1 -> V_22 = V_22 ;
V_1 -> V_89 = 0 ;
V_24 -> V_90 = F_5 ( & V_8 . V_90 ) ;
V_24 -> V_10 = V_10 ;
V_24 -> V_14 = V_14 ;
V_24 -> V_11 = V_11 ;
V_24 -> V_91 = FALSE ;
switch ( V_22 ) {
case V_17 :
case V_21 :
case V_78 :
case V_77 :
if ( V_11 == 2 ) {
if ( V_8 . V_55 [ 1 ] == 0x34 && V_8 . V_55 [ 2 ] == 0x12 )
V_24 -> V_91 = TRUE ;
}
break;
}
V_24 -> V_23 = V_23 ;
V_24 -> V_92 = FALSE ;
V_24 -> V_93 = F_5 ( & V_8 . V_93 ) ;
V_24 -> V_94 = F_5 ( & V_8 . V_94 ) ;
V_24 -> V_95 = F_5 ( & V_8 . V_95 ) ;
if ( F_8 ( V_1 -> V_27 , V_24 -> V_94 , V_96 , V_2 ) == - 1 ) {
return - 1 ;
}
return 1 ;
}
static T_3
V_86 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_97 )
{
T_5 * V_24 = ( T_5 * ) V_1 -> V_84 ;
int V_98 ;
V_99:
* V_97 = F_9 ( V_1 -> V_27 ) ;
if ( * V_97 == V_24 -> V_95 ) {
* V_2 = 0 ;
return FALSE ;
}
V_98 = F_10 ( V_1 , V_1 -> V_27 , & V_1 -> V_100 , V_2 ,
V_3 ) ;
if ( V_98 < 0 ) {
if ( * V_2 != 0 ) {
return FALSE ;
}
if ( V_24 -> V_94 < V_24 -> V_95 ) {
* V_2 = V_28 ;
return FALSE ;
}
if ( ! V_24 -> V_92 ) {
V_24 -> V_92 = TRUE ;
if ( F_8 ( V_1 -> V_27 , V_101 ,
V_96 , V_2 ) == - 1 )
return FALSE ;
goto V_99;
}
return FALSE ;
}
if ( ! F_11 ( V_1 -> V_27 , V_1 -> V_102 ,
V_1 -> V_100 . V_103 , V_2 , V_3 ) )
return FALSE ;
if ( F_8 ( V_1 -> V_27 , V_98 , V_104 , V_2 ) == - 1 )
return FALSE ;
F_12 ( V_1 , & V_1 -> V_100 , V_1 -> V_102 ) ;
return TRUE ;
}
static T_3
V_88 ( T_1 * V_1 , T_6 V_105 ,
struct V_106 * V_100 , T_7 * V_107 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_8 ( V_1 -> V_108 , V_105 , V_96 , V_2 ) == - 1 )
return FALSE ;
if ( F_10 ( V_1 , V_1 -> V_108 , V_100 , V_2 ,
V_3 ) == - 1 ) {
if ( * V_2 == 0 ) {
* V_2 = V_28 ;
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
F_10 ( T_1 * V_1 , T_8 V_27 , struct V_106 * V_100 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_24 = ( T_5 * ) V_1 -> V_84 ;
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
V_25 = V_26 ;
if ( ! F_13 ( V_27 , ( void * ) & V_8 , V_110 , V_2 , V_3 ) ) {
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
if ( V_24 -> V_91 ) {
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
if ( V_24 -> V_91 ) {
V_100 -> V_116 . V_121 . V_118 = 4 ;
} else {
V_98 = 4 ;
}
} else
V_100 -> V_116 . V_121 . V_118 = 0 ;
V_100 -> V_116 . V_121 . V_122 = FALSE ;
V_100 -> V_116 . V_121 . V_123 =
V_8 . V_119 . V_120 [ 12 ] ;
V_100 -> V_116 . V_121 . V_124 =
V_8 . V_119 . V_120 [ 13 ] ;
V_100 -> V_116 . V_121 . V_125 =
V_8 . V_119 . V_120 [ 14 ] ;
break;
case V_78 :
V_100 -> V_116 . V_126 . V_127 =
( V_8 . V_119 . V_120 [ 12 ] & 0x01 ) ;
V_100 -> V_116 . V_126 . V_123 =
V_8 . V_119 . V_120 [ 13 ] & 0x1F ;
switch ( V_24 -> V_23 ) {
case 1 :
if ( V_100 -> V_116 . V_126 . V_123 == 16 )
V_100 -> V_116 . V_126 . V_123 = 0 ;
else if ( V_100 -> V_116 . V_126 . V_123 > 16 )
V_100 -> V_116 . V_126 . V_123 -= 1 ;
break;
case 2 :
if ( V_100 -> V_116 . V_126 . V_123 == 24 )
V_100 -> V_116 . V_126 . V_123 = 0 ;
else if ( V_100 -> V_116 . V_126 . V_123 > 24 )
V_100 -> V_116 . V_126 . V_123 -= 1 ;
break;
}
if ( V_8 . V_119 . V_120 [ 2 ] == 0xff &&
V_8 . V_119 . V_120 [ 3 ] == 0xff ) {
V_98 = 4 ;
}
break;
case V_77 :
case V_73 :
V_100 -> V_116 . V_128 . V_129 =
( V_8 . V_119 . V_120 [ 12 ] & 0x01 ) ? 0x00 : V_130 ;
if ( V_8 . V_119 . V_120 [ 2 ] == 0xff &&
V_8 . V_119 . V_120 [ 3 ] == 0xff ) {
V_98 = 4 ;
}
break;
case V_71 :
case V_80 :
case V_82 :
V_100 -> V_116 . V_131 . V_132 =
( V_8 . V_119 . V_120 [ 12 ] & 0x01 ) ? TRUE : FALSE ;
break;
case V_20 :
V_100 -> V_116 . V_133 . V_129 = 0 ;
if ( V_8 . V_119 . V_120 [ 8 ] & 0x01 )
V_100 -> V_116 . V_133 . V_129 |= V_134 ;
if ( V_8 . V_119 . V_120 [ 9 ] & 0x04 )
V_100 -> V_116 . V_133 . V_129 |= V_135 ;
V_100 -> V_116 . V_133 . V_136 = V_8 . V_119 . V_120 [ 11 ] ;
V_100 -> V_116 . V_133 . V_137 = F_14 ( & V_8 . V_119 . V_120 [ 12 ] ) ;
V_100 -> V_116 . V_133 . V_123 =
( V_8 . V_119 . V_120 [ 15 ] & 0x10 ) ? 1 : 0 ;
V_100 -> V_116 . V_133 . V_138 = 0 ;
switch ( V_8 . V_119 . V_120 [ 0 ] & 0x70 ) {
case 0x00 :
V_100 -> V_116 . V_133 . V_139 = V_140 ;
V_100 -> V_116 . V_133 . type = V_141 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x10 :
V_100 -> V_116 . V_133 . V_139 = V_140 ;
V_100 -> V_116 . V_133 . type = V_141 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x20 :
V_100 -> V_116 . V_133 . V_139 = V_140 ;
V_100 -> V_116 . V_133 . type = V_141 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x40 :
V_100 -> V_116 . V_133 . V_139 = V_140 ;
V_100 -> V_116 . V_133 . type = V_141 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x30 :
case 0x50 :
case 0x60 :
case 0x70 :
V_100 -> V_116 . V_133 . V_139 = V_144 ;
switch ( V_8 . V_119 . V_120 [ 0 ] & 0x07 ) {
case 0x01 :
case 0x02 :
V_100 -> V_116 . V_133 . V_139 = V_145 ;
V_100 -> V_116 . V_133 . type = V_141 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x03 :
V_100 -> V_116 . V_133 . type = V_146 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x00 :
case 0x04 :
case 0x05 :
V_100 -> V_116 . V_133 . type = V_147 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x06 :
V_100 -> V_116 . V_133 . type = V_141 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
case 0x07 :
V_100 -> V_116 . V_133 . type = V_148 ;
V_100 -> V_116 . V_133 . V_142 = V_143 ;
break;
}
break;
}
break;
}
break;
}
V_100 -> V_149 = V_150 ;
if ( V_24 -> V_11 == 0 ) {
V_100 -> V_151 = V_152 ;
V_111 = ( double ) F_5 ( & V_8 . V_153 . V_46 )
+ ( double ) F_5 ( & V_8 . V_153 . V_47 ) * 4294967296.0 ;
V_111 /= V_24 -> V_10 ;
V_111 -= V_24 -> V_14 ;
V_100 -> V_154 . V_155 = V_24 -> V_90 + ( long ) V_111 ;
V_100 -> V_154 . V_156 = ( int ) ( ( V_111 - ( double ) ( unsigned long ) ( V_111 ) )
* 1.0e9 ) ;
V_112 = F_14 ( & V_8 . V_153 . V_157 ) ;
V_100 -> V_103 = V_112 - V_98 ;
V_100 -> V_157 = V_100 -> V_103 ;
} else {
V_100 -> V_151 = V_152 | V_158 ;
V_111 = ( double ) F_5 ( & V_8 . V_159 . V_46 )
+ ( double ) F_5 ( & V_8 . V_159 . V_47 ) * 4294967296.0 ;
V_111 /= V_24 -> V_10 ;
V_111 -= V_24 -> V_14 ;
V_100 -> V_154 . V_155 = V_24 -> V_90 + ( V_160 ) V_111 ;
V_100 -> V_154 . V_156 = ( int ) ( ( V_111 - ( double ) ( unsigned long ) ( V_111 ) )
* 1.0e9 ) ;
V_112 = F_14 ( & V_8 . V_159 . V_161 ) ;
V_100 -> V_103 = V_112 - V_98 ;
V_100 -> V_157 = F_14 ( & V_8 . V_159 . V_162 ) - V_98 ;
}
return V_98 ;
}
static void
F_12 ( T_1 * V_1 , struct V_106 * V_100 , T_7 * V_107 )
{
const T_9 * V_163 ;
if ( V_1 -> V_22 == V_20 &&
! ( V_100 -> V_116 . V_133 . V_129 & V_134 ) ) {
if ( V_100 -> V_116 . V_133 . V_139 == V_140 ) {
V_163 = F_15 ( V_107 ) ;
F_16 ( V_100 , V_163 ) ;
} else if ( V_100 -> V_116 . V_133 . V_139 == V_144 &&
V_100 -> V_116 . V_133 . type == V_147 ) {
V_163 = F_15 ( V_107 ) ;
F_17 ( V_100 , V_163 ) ;
}
}
}
static int
F_18 ( int V_164 )
{
unsigned int V_165 ;
for ( V_165 = 0 ; V_165 < V_166 ; V_165 ++ ) {
if ( V_164 == V_167 [ V_165 ] . V_168 )
return V_167 [ V_165 ] . V_169 ;
}
return - 1 ;
}
int
F_19 ( int V_164 )
{
if ( V_164 == V_170 )
return V_171 ;
if ( F_18 ( V_164 ) == - 1 )
return V_45 ;
return 0 ;
}
T_3
F_20 ( T_10 * V_172 , int * V_2 )
{
T_11 * V_24 ;
V_172 -> V_173 = V_174 ;
V_172 -> V_175 = V_176 ;
if ( F_21 ( V_172 , V_101 , V_96 , V_2 ) == - 1 )
return FALSE ;
V_172 -> V_177 += V_101 ;
V_24 = ( T_11 * ) F_7 ( sizeof( T_11 ) ) ;
V_172 -> V_84 = ( void * ) V_24 ;
V_24 -> V_178 = TRUE ;
V_24 -> V_179 . V_155 = 0 ;
V_24 -> V_179 . V_156 = 0 ;
V_24 -> V_93 = 0 ;
return TRUE ;
}
static T_3
V_174 ( T_10 * V_172 ,
const struct V_106 * V_100 ,
const T_9 * V_163 , int * V_2 )
{
T_11 * V_24 = ( T_11 * ) V_172 -> V_84 ;
T_12 V_180 ;
T_13 V_181 ;
struct V_114 V_182 ;
if ( V_100 -> V_149 != V_150 ) {
* V_2 = V_183 ;
return FALSE ;
}
if ( V_100 -> V_103 > 65535 ) {
* V_2 = V_184 ;
return FALSE ;
}
if ( V_24 -> V_178 ) {
V_24 -> V_178 = FALSE ;
V_24 -> V_179 = V_100 -> V_154 ;
}
memset ( & V_182 , '\0' , sizeof( V_182 ) ) ;
V_180 = ( ( T_12 ) V_100 -> V_154 . V_155 - ( T_12 ) V_24 -> V_179 . V_155 ) * 1000000
+ ( ( T_12 ) V_100 -> V_154 . V_156 ) / 1000 ;
V_181 = ( T_13 ) ( V_180 % F_22 ( 4294967296 ) ) ;
V_182 . V_46 = F_23 ( V_181 ) ;
V_181 = ( T_13 ) ( V_180 / F_22 ( 4294967296 ) ) ;
V_182 . V_47 = F_23 ( V_181 ) ;
V_182 . V_162 = F_24 ( V_100 -> V_157 ) ;
V_182 . V_161 = F_24 ( V_100 -> V_103 ) ;
if ( ! F_25 ( V_172 , & V_182 , sizeof( V_182 ) , V_2 ) )
return FALSE ;
V_172 -> V_177 += sizeof( V_182 ) ;
if ( ! F_25 ( V_172 , V_163 , V_100 -> V_103 , V_2 ) )
return FALSE ;
V_172 -> V_177 += V_100 -> V_103 ;
V_24 -> V_93 ++ ;
return TRUE ;
}
static T_3
V_176 ( T_10 * V_172 , int * V_2 )
{
char V_185 [ V_101 - sizeof( V_29 ) ] ;
T_11 * V_24 = ( T_11 * ) V_172 -> V_84 ;
T_6 V_186 ;
struct V_7 V_187 ;
if ( - 1 == ( V_186 = F_26 ( V_172 , V_2 ) ) )
return FALSE ;
if ( F_21 ( V_172 , 0 , V_96 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_25 ( V_172 , V_29 , sizeof V_29 , V_2 ) )
return FALSE ;
memset ( & V_187 , '\0' , sizeof V_187 ) ;
memcpy ( V_187 . V_32 , V_35 , sizeof V_35 ) ;
V_187 . V_90 = F_23 ( V_24 -> V_179 . V_155 ) ;
V_187 . V_93 = F_23 ( V_24 -> V_93 ) ;
V_187 . V_94 = F_23 ( V_101 ) ;
V_187 . V_95 = F_23 ( ( T_13 ) V_186 ) ;
V_187 . V_44 = F_18 ( V_172 -> V_164 ) ;
V_187 . V_46 = F_23 ( 0 ) ;
V_187 . V_47 = F_23 ( 0 ) ;
memset ( V_185 , '\0' , sizeof V_185 ) ;
memcpy ( V_185 , & V_187 , sizeof( V_187 ) ) ;
if ( ! F_25 ( V_172 , V_185 , sizeof V_185 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_27 ( int V_164 )
{
unsigned int V_165 ;
for ( V_165 = 0 ; V_165 < V_188 ; V_165 ++ ) {
if ( V_164 == V_189 [ V_165 ] . V_168 )
return V_189 [ V_165 ] . V_169 ;
}
return - 1 ;
}
int
F_28 ( int V_164 )
{
if ( V_164 == V_170 )
return V_171 ;
if ( F_27 ( V_164 ) == - 1 )
return V_45 ;
return 0 ;
}
T_3
F_29 ( T_10 * V_172 , int * V_2 )
{
T_11 * V_24 ;
V_172 -> V_173 = V_190 ;
V_172 -> V_175 = V_191 ;
if ( F_21 ( V_172 , V_101 , V_96 , V_2 ) == - 1 )
return FALSE ;
V_172 -> V_177 += V_101 ;
V_24 = ( T_11 * ) F_7 ( sizeof( T_11 ) ) ;
V_172 -> V_84 = ( void * ) V_24 ;
V_24 -> V_178 = TRUE ;
V_24 -> V_179 . V_155 = 0 ;
V_24 -> V_179 . V_156 = 0 ;
V_24 -> V_93 = 0 ;
return TRUE ;
}
static T_3
V_190 ( T_10 * V_172 ,
const struct V_106 * V_100 ,
const T_9 * V_163 , int * V_2 )
{
const union V_192 * V_116 = & V_100 -> V_116 ;
T_11 * V_24 = ( T_11 * ) V_172 -> V_84 ;
T_12 V_180 ;
T_13 V_181 ;
struct V_115 V_182 ;
if ( V_100 -> V_149 != V_150 ) {
* V_2 = V_183 ;
return FALSE ;
}
if ( V_100 -> V_103 > V_193 ) {
* V_2 = V_184 ;
return FALSE ;
}
if ( V_24 -> V_178 ) {
V_24 -> V_178 = FALSE ;
V_24 -> V_179 = V_100 -> V_154 ;
}
memset ( & V_182 , '\0' , sizeof( V_182 ) ) ;
V_180 = ( ( T_12 ) V_100 -> V_154 . V_155 - ( T_12 ) V_24 -> V_179 . V_155 ) * 1000000
+ ( ( T_12 ) V_100 -> V_154 . V_156 ) / 1000 ;
V_181 = ( T_13 ) ( V_180 % F_22 ( 4294967296 ) ) ;
V_182 . V_46 = F_23 ( V_181 ) ;
V_181 = ( T_13 ) ( V_180 / F_22 ( 4294967296 ) ) ;
V_182 . V_47 = F_23 ( V_181 ) ;
V_182 . V_162 = F_24 ( V_100 -> V_157 ) ;
V_182 . V_161 = F_24 ( V_100 -> V_103 ) ;
switch ( V_100 -> V_194 ) {
case V_21 :
V_182 . V_120 [ 12 ] = V_116 -> V_121 . V_123 ;
V_182 . V_120 [ 13 ] = ( T_9 ) V_116 -> V_121 . V_124 ;
V_182 . V_120 [ 14 ] = V_116 -> V_121 . V_125 ;
break;
case V_71 :
case V_80 :
V_182 . V_120 [ 12 ] |= V_116 -> V_131 . V_132 ? 0x01 : 0x00 ;
break;
case V_73 :
V_182 . V_120 [ 12 ] |= ( V_116 -> V_128 . V_129 & V_130 ) ? 0x00 : 0x01 ;
break;
}
if ( ! F_25 ( V_172 , & V_182 , sizeof( V_182 ) , V_2 ) )
return FALSE ;
V_172 -> V_177 += sizeof( V_182 ) ;
if ( ! F_25 ( V_172 , V_163 , V_100 -> V_103 , V_2 ) )
return FALSE ;
V_172 -> V_177 += V_100 -> V_103 ;
V_24 -> V_93 ++ ;
return TRUE ;
}
static T_3
V_191 ( T_10 * V_172 , int * V_2 )
{
char V_185 [ V_101 - sizeof( V_29 ) ] ;
T_11 * V_24 = ( T_11 * ) V_172 -> V_84 ;
T_6 V_186 ;
struct V_7 V_187 ;
if ( - 1 == ( V_186 = F_26 ( V_172 , V_2 ) ) )
return FALSE ;
if ( F_21 ( V_172 , 0 , V_96 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_25 ( V_172 , V_29 , sizeof V_29 , V_2 ) )
return FALSE ;
memset ( & V_187 , '\0' , sizeof V_187 ) ;
memcpy ( V_187 . V_32 , V_39 , sizeof V_39 ) ;
V_187 . V_90 = F_23 ( V_24 -> V_179 . V_155 ) ;
V_187 . V_93 = F_23 ( V_24 -> V_93 ) ;
V_187 . V_94 = F_23 ( V_101 ) ;
V_187 . V_95 = F_23 ( ( T_13 ) V_186 ) ;
V_187 . V_44 = F_27 ( V_172 -> V_164 ) ;
V_187 . V_46 = F_23 ( 0 ) ;
V_187 . V_47 = F_23 ( 0 ) ;
switch ( V_172 -> V_164 ) {
case V_71 :
V_187 . V_51 = V_70 ;
break;
case V_73 :
V_187 . V_51 = V_72 ;
break;
case V_77 :
V_187 . V_51 = V_74 ;
V_187 . V_76 = 0 ;
break;
case V_80 :
V_187 . V_51 = V_79 ;
break;
default:
V_187 . V_51 = V_52 ;
break;
}
memset ( V_185 , '\0' , sizeof V_185 ) ;
memcpy ( V_185 , & V_187 , sizeof( V_187 ) ) ;
if ( ! F_25 ( V_172 , V_185 , sizeof V_185 , V_2 ) )
return FALSE ;
return TRUE ;
}
