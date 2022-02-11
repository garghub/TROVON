int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
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
V_1 -> V_84 = V_14 ;
V_25 = ( T_5 * ) F_8 ( sizeof( T_5 ) ) ;
V_1 -> V_85 = ( void * ) V_25 ;
V_1 -> V_86 = V_87 ;
V_1 -> V_88 = V_89 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_90 = 0 ;
V_25 -> V_91 = F_6 ( & V_9 . V_91 ) ;
V_25 -> V_11 = V_11 ;
V_25 -> V_15 = V_15 ;
V_25 -> V_12 = V_12 ;
V_25 -> V_92 = FALSE ;
switch ( V_23 ) {
case V_18 :
case V_22 :
case V_79 :
case V_78 :
if ( V_12 == 2 ) {
if ( V_9 . V_56 [ 1 ] == 0x34 && V_9 . V_56 [ 2 ] == 0x12 )
V_25 -> V_92 = TRUE ;
}
break;
}
V_25 -> V_24 = V_24 ;
V_25 -> V_93 = FALSE ;
V_25 -> V_94 = F_6 ( & V_9 . V_94 ) ;
V_25 -> V_95 = F_6 ( & V_9 . V_95 ) ;
V_25 -> V_96 = F_6 ( & V_9 . V_96 ) ;
if ( F_9 ( V_1 -> V_28 , V_25 -> V_95 , V_97 , V_2 ) == - 1 ) {
return - 1 ;
}
return 1 ;
}
static T_3
V_87 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_98 )
{
T_5 * V_25 = ( T_5 * ) V_1 -> V_85 ;
int V_99 ;
V_100:
* V_98 = F_10 ( V_1 -> V_28 ) ;
if ( * V_98 == V_25 -> V_96 ) {
* V_2 = 0 ;
return FALSE ;
}
V_99 = F_11 ( V_1 , V_1 -> V_28 , & V_1 -> V_101 , V_2 ,
V_3 ) ;
if ( V_99 < 0 ) {
if ( * V_2 != 0 ) {
return FALSE ;
}
if ( V_25 -> V_95 < V_25 -> V_96 ) {
* V_2 = V_29 ;
return FALSE ;
}
if ( ! V_25 -> V_93 ) {
V_25 -> V_93 = TRUE ;
if ( F_9 ( V_1 -> V_28 , V_102 ,
V_97 , V_2 ) == - 1 )
return FALSE ;
goto V_100;
}
return FALSE ;
}
if ( ! F_12 ( V_1 -> V_28 , V_1 -> V_103 ,
V_1 -> V_101 . V_104 , V_2 , V_3 ) )
return FALSE ;
if ( F_9 ( V_1 -> V_28 , V_99 , V_105 , V_2 ) == - 1 )
return FALSE ;
F_13 ( V_1 , & V_1 -> V_101 , V_1 -> V_103 ) ;
return TRUE ;
}
static T_3
V_89 ( T_1 * V_1 , T_6 V_106 ,
struct V_107 * V_101 , T_7 * V_108 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_9 ( V_1 -> V_109 , V_106 , V_97 , V_2 ) == - 1 )
return FALSE ;
if ( F_11 ( V_1 , V_1 -> V_109 , V_101 , V_2 ,
V_3 ) == - 1 ) {
if ( * V_2 == 0 ) {
* V_2 = V_29 ;
}
return FALSE ;
}
if ( ! F_12 ( V_1 -> V_109 , V_108 , V_101 -> V_104 , V_2 ,
V_3 ) )
return FALSE ;
F_13 ( V_1 , V_101 , V_108 ) ;
return TRUE ;
}
static int
F_11 ( T_1 * V_1 , T_8 V_28 , struct V_107 * V_101 ,
int * V_2 , T_2 * * V_3 )
{
T_5 * V_25 = ( T_5 * ) V_1 -> V_85 ;
union V_110 V_9 ;
int V_4 ;
int V_111 = 0 ;
double V_112 ;
int V_113 ;
int V_99 = 0 ;
switch ( V_25 -> V_12 ) {
case 0 :
V_111 = sizeof ( struct V_114 ) ;
break;
case 1 :
V_111 = sizeof ( struct V_115 ) ;
break;
case 2 :
V_111 = sizeof ( struct V_116 ) ;
break;
}
V_26 = V_27 ;
V_4 = F_3 ( ( void * ) & V_9 , V_111 , V_28 ) ;
if ( V_4 != V_111 ) {
* V_2 = F_4 ( V_1 -> V_28 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_29 ;
return - 1 ;
}
return - 1 ;
}
switch ( V_25 -> V_12 ) {
case 1 :
switch ( V_1 -> V_23 ) {
case V_18 :
V_101 -> V_117 . V_118 . V_119 = 0 ;
break;
}
break;
case 2 :
switch ( V_1 -> V_23 ) {
case V_18 :
if ( V_9 . V_120 . V_121 [ 2 ] == 0xff &&
V_9 . V_120 . V_121 [ 3 ] == 0xff ) {
if ( V_25 -> V_92 ) {
V_101 -> V_117 . V_118 . V_119 = 4 ;
} else {
V_99 = 4 ;
}
} else
V_101 -> V_117 . V_118 . V_119 = 0 ;
break;
case V_22 :
if ( V_9 . V_120 . V_121 [ 2 ] == 0xff &&
V_9 . V_120 . V_121 [ 3 ] == 0xff ) {
if ( V_25 -> V_92 ) {
V_101 -> V_117 . V_122 . V_119 = 4 ;
} else {
V_99 = 4 ;
}
} else
V_101 -> V_117 . V_122 . V_119 = 0 ;
V_101 -> V_117 . V_122 . V_123 = FALSE ;
V_101 -> V_117 . V_122 . V_124 =
V_9 . V_120 . V_121 [ 12 ] ;
V_101 -> V_117 . V_122 . V_125 =
V_9 . V_120 . V_121 [ 13 ] ;
V_101 -> V_117 . V_122 . V_126 =
V_9 . V_120 . V_121 [ 14 ] ;
break;
case V_79 :
V_101 -> V_117 . V_127 . V_128 =
( V_9 . V_120 . V_121 [ 12 ] & 0x01 ) ;
V_101 -> V_117 . V_127 . V_124 =
V_9 . V_120 . V_121 [ 13 ] & 0x1F ;
switch ( V_25 -> V_24 ) {
case 1 :
if ( V_101 -> V_117 . V_127 . V_124 == 16 )
V_101 -> V_117 . V_127 . V_124 = 0 ;
else if ( V_101 -> V_117 . V_127 . V_124 > 16 )
V_101 -> V_117 . V_127 . V_124 -= 1 ;
break;
case 2 :
if ( V_101 -> V_117 . V_127 . V_124 == 24 )
V_101 -> V_117 . V_127 . V_124 = 0 ;
else if ( V_101 -> V_117 . V_127 . V_124 > 24 )
V_101 -> V_117 . V_127 . V_124 -= 1 ;
break;
}
if ( V_9 . V_120 . V_121 [ 2 ] == 0xff &&
V_9 . V_120 . V_121 [ 3 ] == 0xff ) {
V_99 = 4 ;
}
break;
case V_78 :
case V_74 :
V_101 -> V_117 . V_129 . V_130 =
( V_9 . V_120 . V_121 [ 12 ] & 0x01 ) ? 0x00 : V_131 ;
if ( V_9 . V_120 . V_121 [ 2 ] == 0xff &&
V_9 . V_120 . V_121 [ 3 ] == 0xff ) {
V_99 = 4 ;
}
break;
case V_72 :
case V_81 :
case V_83 :
V_101 -> V_117 . V_132 . V_133 =
( V_9 . V_120 . V_121 [ 12 ] & 0x01 ) ? TRUE : FALSE ;
break;
case V_21 :
V_101 -> V_117 . V_134 . V_130 = 0 ;
if ( V_9 . V_120 . V_121 [ 8 ] & 0x01 )
V_101 -> V_117 . V_134 . V_130 |= V_135 ;
if ( V_9 . V_120 . V_121 [ 9 ] & 0x04 )
V_101 -> V_117 . V_134 . V_130 |= V_136 ;
V_101 -> V_117 . V_134 . V_137 = V_9 . V_120 . V_121 [ 11 ] ;
V_101 -> V_117 . V_134 . V_138 = F_14 ( & V_9 . V_120 . V_121 [ 12 ] ) ;
V_101 -> V_117 . V_134 . V_124 =
( V_9 . V_120 . V_121 [ 15 ] & 0x10 ) ? 1 : 0 ;
V_101 -> V_117 . V_134 . V_139 = 0 ;
switch ( V_9 . V_120 . V_121 [ 0 ] & 0x70 ) {
case 0x00 :
V_101 -> V_117 . V_134 . V_140 = V_141 ;
V_101 -> V_117 . V_134 . type = V_142 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x10 :
V_101 -> V_117 . V_134 . V_140 = V_141 ;
V_101 -> V_117 . V_134 . type = V_142 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x20 :
V_101 -> V_117 . V_134 . V_140 = V_141 ;
V_101 -> V_117 . V_134 . type = V_142 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x40 :
V_101 -> V_117 . V_134 . V_140 = V_141 ;
V_101 -> V_117 . V_134 . type = V_142 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x30 :
case 0x50 :
case 0x60 :
case 0x70 :
V_101 -> V_117 . V_134 . V_140 = V_145 ;
switch ( V_9 . V_120 . V_121 [ 0 ] & 0x07 ) {
case 0x01 :
case 0x02 :
V_101 -> V_117 . V_134 . V_140 = V_146 ;
V_101 -> V_117 . V_134 . type = V_142 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x03 :
V_101 -> V_117 . V_134 . type = V_147 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x00 :
case 0x04 :
case 0x05 :
V_101 -> V_117 . V_134 . type = V_148 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x06 :
V_101 -> V_117 . V_134 . type = V_142 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
case 0x07 :
V_101 -> V_117 . V_134 . type = V_149 ;
V_101 -> V_117 . V_134 . V_143 = V_144 ;
break;
}
break;
}
break;
}
break;
}
V_101 -> V_150 = V_151 ;
if ( V_25 -> V_12 == 0 ) {
V_101 -> V_152 = V_153 ;
V_112 = ( double ) F_6 ( & V_9 . V_154 . V_47 )
+ ( double ) F_6 ( & V_9 . V_154 . V_48 ) * 4294967296.0 ;
V_112 /= V_25 -> V_11 ;
V_112 -= V_25 -> V_15 ;
V_101 -> V_155 . V_156 = V_25 -> V_91 + ( long ) V_112 ;
V_101 -> V_155 . V_157 = ( int ) ( ( V_112 - ( double ) ( unsigned long ) ( V_112 ) )
* 1.0e9 ) ;
V_113 = F_14 ( & V_9 . V_154 . V_158 ) ;
V_101 -> V_104 = V_113 - V_99 ;
V_101 -> V_158 = V_101 -> V_104 ;
} else {
V_101 -> V_152 = V_153 | V_159 ;
V_112 = ( double ) F_6 ( & V_9 . V_160 . V_47 )
+ ( double ) F_6 ( & V_9 . V_160 . V_48 ) * 4294967296.0 ;
V_112 /= V_25 -> V_11 ;
V_112 -= V_25 -> V_15 ;
V_101 -> V_155 . V_156 = V_25 -> V_91 + ( V_161 ) V_112 ;
V_101 -> V_155 . V_157 = ( int ) ( ( V_112 - ( double ) ( unsigned long ) ( V_112 ) )
* 1.0e9 ) ;
V_113 = F_14 ( & V_9 . V_160 . V_162 ) ;
V_101 -> V_104 = V_113 - V_99 ;
V_101 -> V_158 = F_14 ( & V_9 . V_160 . V_163 ) - V_99 ;
}
return V_99 ;
}
static void
F_13 ( T_1 * V_1 , struct V_107 * V_101 , T_7 * V_108 )
{
const T_9 * V_164 ;
if ( V_1 -> V_23 == V_21 &&
! ( V_101 -> V_117 . V_134 . V_130 & V_135 ) ) {
if ( V_101 -> V_117 . V_134 . V_140 == V_141 ) {
V_164 = F_15 ( V_108 ) ;
F_16 ( V_101 , V_164 ) ;
} else if ( V_101 -> V_117 . V_134 . V_140 == V_145 &&
V_101 -> V_117 . V_134 . type == V_148 ) {
V_164 = F_15 ( V_108 ) ;
F_17 ( V_101 , V_164 ) ;
}
}
}
static int
F_18 ( int V_165 )
{
unsigned int V_166 ;
for ( V_166 = 0 ; V_166 < V_167 ; V_166 ++ ) {
if ( V_165 == V_168 [ V_166 ] . V_169 )
return V_168 [ V_166 ] . V_170 ;
}
return - 1 ;
}
int
F_19 ( int V_165 )
{
if ( V_165 == V_171 )
return V_172 ;
if ( F_18 ( V_165 ) == - 1 )
return V_46 ;
return 0 ;
}
T_3
F_20 ( T_10 * V_173 , int * V_2 )
{
T_11 * V_25 ;
V_173 -> V_174 = V_175 ;
V_173 -> V_176 = V_177 ;
if ( F_21 ( V_173 , V_102 , V_97 , V_2 ) == - 1 )
return FALSE ;
V_173 -> V_178 += V_102 ;
V_25 = ( T_11 * ) F_8 ( sizeof( T_11 ) ) ;
V_173 -> V_85 = ( void * ) V_25 ;
V_25 -> V_179 = TRUE ;
V_25 -> V_180 . V_156 = 0 ;
V_25 -> V_180 . V_157 = 0 ;
V_25 -> V_94 = 0 ;
return TRUE ;
}
static T_3
V_175 ( T_10 * V_173 ,
const struct V_107 * V_101 ,
const T_9 * V_164 , int * V_2 )
{
T_11 * V_25 = ( T_11 * ) V_173 -> V_85 ;
T_12 V_181 ;
T_13 V_182 ;
struct V_115 V_183 ;
if ( V_101 -> V_150 != V_151 ) {
* V_2 = V_184 ;
return FALSE ;
}
if ( V_101 -> V_104 > 65535 ) {
* V_2 = V_185 ;
return FALSE ;
}
if ( V_25 -> V_179 ) {
V_25 -> V_179 = FALSE ;
V_25 -> V_180 = V_101 -> V_155 ;
}
memset ( & V_183 , '\0' , sizeof( V_183 ) ) ;
V_181 = ( ( T_12 ) V_101 -> V_155 . V_156 - ( T_12 ) V_25 -> V_180 . V_156 ) * 1000000
+ ( ( T_12 ) V_101 -> V_155 . V_157 ) / 1000 ;
V_182 = ( T_13 ) ( V_181 % F_22 ( 4294967296 ) ) ;
V_183 . V_47 = F_23 ( V_182 ) ;
V_182 = ( T_13 ) ( V_181 / F_22 ( 4294967296 ) ) ;
V_183 . V_48 = F_23 ( V_182 ) ;
V_183 . V_163 = F_24 ( V_101 -> V_158 ) ;
V_183 . V_162 = F_24 ( V_101 -> V_104 ) ;
if ( ! F_25 ( V_173 , & V_183 , sizeof( V_183 ) , V_2 ) )
return FALSE ;
V_173 -> V_178 += sizeof( V_183 ) ;
if ( ! F_25 ( V_173 , V_164 , V_101 -> V_104 , V_2 ) )
return FALSE ;
V_173 -> V_178 += V_101 -> V_104 ;
V_25 -> V_94 ++ ;
return TRUE ;
}
static T_3
V_177 ( T_10 * V_173 , int * V_2 )
{
char V_186 [ V_102 - sizeof( V_30 ) ] ;
T_11 * V_25 = ( T_11 * ) V_173 -> V_85 ;
T_6 V_187 ;
struct V_8 V_188 ;
if ( - 1 == ( V_187 = F_26 ( V_173 , V_2 ) ) )
return FALSE ;
if ( F_21 ( V_173 , 0 , V_97 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_25 ( V_173 , V_30 , sizeof V_30 , V_2 ) )
return FALSE ;
memset ( & V_188 , '\0' , sizeof V_188 ) ;
memcpy ( V_188 . V_33 , V_36 , sizeof V_36 ) ;
V_188 . V_91 = F_23 ( V_25 -> V_180 . V_156 ) ;
V_188 . V_94 = F_23 ( V_25 -> V_94 ) ;
V_188 . V_95 = F_23 ( V_102 ) ;
V_188 . V_96 = F_23 ( ( T_13 ) V_187 ) ;
V_188 . V_45 = F_18 ( V_173 -> V_165 ) ;
V_188 . V_47 = F_23 ( 0 ) ;
V_188 . V_48 = F_23 ( 0 ) ;
memset ( V_186 , '\0' , sizeof V_186 ) ;
memcpy ( V_186 , & V_188 , sizeof( V_188 ) ) ;
if ( ! F_25 ( V_173 , V_186 , sizeof V_186 , V_2 ) )
return FALSE ;
return TRUE ;
}
static int
F_27 ( int V_165 )
{
unsigned int V_166 ;
for ( V_166 = 0 ; V_166 < V_189 ; V_166 ++ ) {
if ( V_165 == V_190 [ V_166 ] . V_169 )
return V_190 [ V_166 ] . V_170 ;
}
return - 1 ;
}
int
F_28 ( int V_165 )
{
if ( V_165 == V_171 )
return V_172 ;
if ( F_27 ( V_165 ) == - 1 )
return V_46 ;
return 0 ;
}
T_3
F_29 ( T_10 * V_173 , int * V_2 )
{
T_11 * V_25 ;
V_173 -> V_174 = V_191 ;
V_173 -> V_176 = V_192 ;
if ( F_21 ( V_173 , V_102 , V_97 , V_2 ) == - 1 )
return FALSE ;
V_173 -> V_178 += V_102 ;
V_25 = ( T_11 * ) F_8 ( sizeof( T_11 ) ) ;
V_173 -> V_85 = ( void * ) V_25 ;
V_25 -> V_179 = TRUE ;
V_25 -> V_180 . V_156 = 0 ;
V_25 -> V_180 . V_157 = 0 ;
V_25 -> V_94 = 0 ;
return TRUE ;
}
static T_3
V_191 ( T_10 * V_173 ,
const struct V_107 * V_101 ,
const T_9 * V_164 , int * V_2 )
{
const union V_193 * V_117 = & V_101 -> V_117 ;
T_11 * V_25 = ( T_11 * ) V_173 -> V_85 ;
T_12 V_181 ;
T_13 V_182 ;
struct V_116 V_183 ;
if ( V_101 -> V_150 != V_151 ) {
* V_2 = V_184 ;
return FALSE ;
}
if ( V_101 -> V_104 > V_194 ) {
* V_2 = V_185 ;
return FALSE ;
}
if ( V_25 -> V_179 ) {
V_25 -> V_179 = FALSE ;
V_25 -> V_180 = V_101 -> V_155 ;
}
memset ( & V_183 , '\0' , sizeof( V_183 ) ) ;
V_181 = ( ( T_12 ) V_101 -> V_155 . V_156 - ( T_12 ) V_25 -> V_180 . V_156 ) * 1000000
+ ( ( T_12 ) V_101 -> V_155 . V_157 ) / 1000 ;
V_182 = ( T_13 ) ( V_181 % F_22 ( 4294967296 ) ) ;
V_183 . V_47 = F_23 ( V_182 ) ;
V_182 = ( T_13 ) ( V_181 / F_22 ( 4294967296 ) ) ;
V_183 . V_48 = F_23 ( V_182 ) ;
V_183 . V_163 = F_24 ( V_101 -> V_158 ) ;
V_183 . V_162 = F_24 ( V_101 -> V_104 ) ;
switch ( V_101 -> V_195 ) {
case V_22 :
V_183 . V_121 [ 12 ] = V_117 -> V_122 . V_124 ;
V_183 . V_121 [ 13 ] = ( T_9 ) V_117 -> V_122 . V_125 ;
V_183 . V_121 [ 14 ] = V_117 -> V_122 . V_126 ;
break;
case V_72 :
case V_81 :
V_183 . V_121 [ 12 ] |= V_117 -> V_132 . V_133 ? 0x01 : 0x00 ;
break;
case V_74 :
V_183 . V_121 [ 12 ] |= ( V_117 -> V_129 . V_130 & V_131 ) ? 0x00 : 0x01 ;
break;
}
if ( ! F_25 ( V_173 , & V_183 , sizeof( V_183 ) , V_2 ) )
return FALSE ;
V_173 -> V_178 += sizeof( V_183 ) ;
if ( ! F_25 ( V_173 , V_164 , V_101 -> V_104 , V_2 ) )
return FALSE ;
V_173 -> V_178 += V_101 -> V_104 ;
V_25 -> V_94 ++ ;
return TRUE ;
}
static T_3
V_192 ( T_10 * V_173 , int * V_2 )
{
char V_186 [ V_102 - sizeof( V_30 ) ] ;
T_11 * V_25 = ( T_11 * ) V_173 -> V_85 ;
T_6 V_187 ;
struct V_8 V_188 ;
if ( - 1 == ( V_187 = F_26 ( V_173 , V_2 ) ) )
return FALSE ;
if ( F_21 ( V_173 , 0 , V_97 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_25 ( V_173 , V_30 , sizeof V_30 , V_2 ) )
return FALSE ;
memset ( & V_188 , '\0' , sizeof V_188 ) ;
memcpy ( V_188 . V_33 , V_40 , sizeof V_40 ) ;
V_188 . V_91 = F_23 ( V_25 -> V_180 . V_156 ) ;
V_188 . V_94 = F_23 ( V_25 -> V_94 ) ;
V_188 . V_95 = F_23 ( V_102 ) ;
V_188 . V_96 = F_23 ( ( T_13 ) V_187 ) ;
V_188 . V_45 = F_27 ( V_173 -> V_165 ) ;
V_188 . V_47 = F_23 ( 0 ) ;
V_188 . V_48 = F_23 ( 0 ) ;
switch ( V_173 -> V_165 ) {
case V_72 :
V_188 . V_52 = V_71 ;
break;
case V_74 :
V_188 . V_52 = V_73 ;
break;
case V_78 :
V_188 . V_52 = V_75 ;
V_188 . V_77 = 0 ;
break;
case V_81 :
V_188 . V_52 = V_80 ;
break;
default:
V_188 . V_52 = V_53 ;
break;
}
memset ( V_186 , '\0' , sizeof V_186 ) ;
memcpy ( V_186 , & V_188 , sizeof( V_188 ) ) ;
if ( ! F_25 ( V_173 , V_186 , sizeof V_186 , V_2 ) )
return FALSE ;
return TRUE ;
}
