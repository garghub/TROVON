static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
V_4 -> V_6 . V_7 = V_8 ;
V_5 = ( F_2 ( V_4 ) ? V_9 : 0 ) ;
return V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
return V_13 [ V_11 -> V_14 ] . V_15 ;
}
struct V_16 * F_4 ( int V_17 )
{
return & V_13 [ V_17 ] ;
}
static int F_5 ( struct V_18 * V_19 , struct V_20 * V_21 ,
T_1 V_22 , int * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
unsigned char * V_26 ;
F_6 ( ( V_27 L_1 ) ) ;
if ( V_22 >= 2 * 1024 * 1024 ) {
if( V_22 >= 4 * 1024 * 1024 ) {
V_25 -> V_28 = 255 ;
V_25 -> V_29 = 63 ;
} else {
V_25 -> V_28 = 128 ;
V_25 -> V_29 = 32 ;
}
} else {
V_25 -> V_28 = 64 ;
V_25 -> V_29 = 32 ;
}
V_25 -> V_30 = F_7 ( V_22 , V_25 -> V_28 * V_25 -> V_29 ) ;
V_26 = F_8 ( V_21 ) ;
if ( ! V_26 )
return 0 ;
if( * ( V_31 * ) ( V_26 + 0x40 ) == F_9 ( 0xaa55 ) ) {
struct V_32 * V_33 = (struct V_32 * ) V_26 ;
struct V_32 * V_34 = V_33 ;
int V_35 = V_25 -> V_30 ;
int V_36 ;
unsigned char V_37 , V_38 ;
for( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_37 = V_34 -> V_37 ;
V_38 = V_34 -> V_39 & 0x3f ;
if( V_37 == 63 ) {
V_25 -> V_28 = 64 ;
V_25 -> V_29 = 32 ;
break;
} else if( V_37 == 127 ) {
V_25 -> V_28 = 128 ;
V_25 -> V_29 = 32 ;
break;
} else if( V_37 == 254 ) {
V_25 -> V_28 = 255 ;
V_25 -> V_29 = 63 ;
break;
}
V_34 ++ ;
}
if ( V_36 == 4 ) {
V_37 = V_33 -> V_37 ;
V_38 = V_33 -> V_39 & 0x3f ;
}
V_25 -> V_30 = F_7 ( V_22 , V_25 -> V_28 * V_25 -> V_29 ) ;
if ( V_36 < 4 && V_38 == V_25 -> V_29 ) {
if ( V_25 -> V_30 != V_35 )
F_6 ( ( V_27 L_2 ,
V_25 -> V_28 , V_25 -> V_29 , V_36 ) ) ;
} else if ( V_37 > 0 || V_38 > 0 ) {
F_6 ( ( V_27 L_3 ,
V_37 + 1 , V_38 , V_36 ) ) ;
F_6 ( ( V_27 L_4 ,
V_25 -> V_28 , V_25 -> V_29 ) ) ;
}
}
F_10 ( V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_10 * V_40 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
int V_42 , V_43 ;
unsigned int V_44 = 0 ;
unsigned int V_45 = 0 ;
bool V_46 = false ;
T_2 V_17 = 0 ;
V_42 = F_12 ( F_13 ( V_19 ) ) ;
V_43 = F_14 ( V_19 ) ;
if ( V_42 < V_47 && V_43 < V_48 && V_40 -> V_49 ) {
V_17 = V_40 -> V_50 [ V_42 ] [ V_43 ] . V_17 ;
if ( V_17 == V_51 )
V_44 = V_40 -> V_50 [ V_42 ] [ V_43 ] . V_52 ;
else if ( V_17 == V_53 )
V_46 = true ;
V_45 = 1 ;
goto V_54;
}
if ( V_40 -> V_55 && ( V_19 -> type == V_56 ) )
V_19 -> V_57 = 1 ;
if ( V_19 -> type == V_56
&& F_13 ( V_19 ) != V_58
&& ( ! V_40 -> V_55 || V_19 -> V_59 )
&& ( ! V_40 -> V_60 || ( F_13 ( V_19 ) != 2 ) ) ) {
if ( V_61 == 0 )
return - V_62 ;
if ( V_61 < 0 )
V_19 -> V_63 = 1 ;
}
if ( V_19 -> V_64
&& V_19 -> type == V_56
&& ( ! V_40 -> V_60 || ( F_13 ( V_19 ) != 2 ) )
&& ! V_19 -> V_63 ) {
struct V_18 * V_11 ;
struct V_1 * V_41 = V_19 -> V_41 ;
unsigned V_65 = 0 ;
unsigned V_66 = 0 ;
unsigned V_67 ;
V_45 = 1 ;
for ( V_67 = 0 ; V_67 < V_40 -> V_68 ; ++ V_67 )
if ( V_40 -> V_69 [ V_67 ] . V_70 )
++ V_65 ;
F_15 (dev, host) {
if ( V_11 -> V_64
&& V_11 -> type == V_56
&& ( ! V_40 -> V_60 || ( F_13 ( V_19 ) != 2 ) )
&& ! V_11 -> V_63 ) {
if ( ( F_13 ( V_11 ) != V_58 )
|| ! V_40 -> V_69 [ F_14 ( V_11 ) ] . V_70 ) {
++ V_65 ;
}
} else {
++ V_66 ;
}
}
if ( V_65 == 0 )
++ V_65 ;
V_44 = ( V_41 -> V_71 - V_66 ) / V_65 ;
if ( F_13 ( V_19 ) != V_72 )
goto V_54;
V_46 = true ;
}
V_54:
if ( V_46 ) {
if ( strncmp ( V_19 -> V_73 , L_5 , 3 ) == 0 )
V_44 = 32 ;
else
V_44 = 64 ;
}
if ( V_45 && V_19 -> V_74 -> V_75 < ( 45 * V_76 ) )
F_16 ( V_19 -> V_74 , 45 * V_76 ) ;
if ( V_44 > 256 )
V_44 = 256 ;
else if ( V_44 < 1 )
V_44 = 1 ;
F_17 ( V_19 , V_44 ) ;
V_19 -> V_64 = 1 ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , int V_44 )
{
struct V_10 * V_40 = (struct V_10 * ) ( V_19 -> V_41 -> V_12 ) ;
int V_42 , V_43 , V_77 = 0 ;
V_42 = F_12 ( F_13 ( V_19 ) ) ;
V_43 = F_14 ( V_19 ) ;
if ( V_42 < V_47 && V_43 < V_48 &&
V_40 -> V_50 [ V_42 ] [ V_43 ] . V_17 == V_51 )
V_77 = 1 ;
if ( V_19 -> V_64 && ( V_19 -> type == V_56 ) &&
( F_13 ( V_19 ) == V_58 ) ) {
struct V_18 * V_11 ;
struct V_1 * V_41 = V_19 -> V_41 ;
unsigned V_36 = 0 ;
F_15 (dev, host) {
if ( V_11 -> V_64 && ( V_11 -> type == V_56 ) &&
( F_13 ( V_11 ) == V_58 ) )
++ V_36 ;
++ V_36 ;
}
if ( V_36 >= V_41 -> V_71 )
V_36 = V_41 -> V_71 - 1 ;
if ( V_44 > ( V_41 -> V_71 - V_36 ) )
V_44 = V_41 -> V_71 - V_36 ;
if ( V_44 > 256 )
V_44 = 256 ;
else if ( V_44 < 2 )
V_44 = 2 ;
return F_17 ( V_19 , V_44 ) ;
} else if ( V_77 ) {
F_17 ( V_19 , V_40 -> V_50 [ V_42 ] [ V_43 ] . V_52 ) ;
} else {
F_17 ( V_19 , 1 ) ;
}
return V_19 -> V_78 ;
}
static T_3 F_19 ( struct V_79 * V_11 , struct V_80 * V_81 , char * V_26 )
{
struct V_18 * V_19 = F_20 ( V_11 ) ;
struct V_10 * V_40 = (struct V_10 * ) ( V_19 -> V_41 -> V_12 ) ;
if ( F_13 ( V_19 ) != V_58 )
return snprintf ( V_26 , V_82 , V_19 -> V_63
? L_6 :
( ( V_40 -> V_55 && ( V_19 -> type == V_56 ) ) ? L_7 : L_8 ) ) ;
return snprintf ( V_26 , V_82 , L_9 ,
F_21 ( V_40 -> V_69 [ F_14 ( V_19 ) ] . type ) ) ;
}
static T_3 F_22 ( struct V_79 * V_11 ,
struct V_80 * V_81 , char * V_26 )
{
struct V_18 * V_19 = F_20 ( V_11 ) ;
struct V_10 * V_40 = (struct V_10 * ) ( V_19 -> V_41 -> V_12 ) ;
unsigned char V_83 [ 16 ] ;
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
if ( F_13 ( V_19 ) == V_58 )
memcpy ( V_83 , V_40 -> V_69 [ F_14 ( V_19 ) ] . V_84 , sizeof( V_83 ) ) ;
return snprintf ( V_26 , 16 * 2 + 2 ,
L_10 ,
V_83 [ 0 ] , V_83 [ 1 ] , V_83 [ 2 ] , V_83 [ 3 ] ,
V_83 [ 4 ] , V_83 [ 5 ] , V_83 [ 6 ] , V_83 [ 7 ] ,
V_83 [ 8 ] , V_83 [ 9 ] , V_83 [ 10 ] , V_83 [ 11 ] ,
V_83 [ 12 ] , V_83 [ 13 ] , V_83 [ 14 ] , V_83 [ 15 ] ) ;
}
static int F_23 ( struct V_18 * V_19 , int V_4 , void T_4 * V_85 )
{
struct V_10 * V_11 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( ! F_24 ( V_86 ) )
return - V_87 ;
return F_25 ( V_11 , V_4 , V_85 ) ;
}
static int F_26 ( struct V_10 * V_40 )
{
unsigned long V_88 ;
struct V_18 * V_19 = NULL ;
struct V_1 * V_2 = V_40 -> V_89 ;
struct V_3 * V_90 = NULL ;
struct V_79 * V_91 ;
int V_92 = 0 ;
int V_93 = 0 ;
int V_94 = 0 ;
int V_95 = 0 ;
int V_96 = 0 ;
F_15 (sdev, shost) {
F_27 ( & V_19 -> V_97 , V_88 ) ;
F_28 (scmnd, &sdev->cmd_list, list) {
switch ( V_90 -> V_6 . V_7 ) {
case V_98 :
V_95 ++ ;
break;
case V_99 :
V_94 ++ ;
break;
case V_8 :
V_93 ++ ;
break;
case V_100 :
V_92 ++ ;
break;
default:
V_96 ++ ;
break;
}
}
F_29 ( & V_19 -> V_97 , V_88 ) ;
}
V_91 = & V_40 -> V_101 -> V_11 ;
F_30 ( V_91 , L_11 , V_92 ) ;
F_30 ( V_91 , L_12 , V_93 ) ;
F_30 ( V_91 , L_13 , V_94 ) ;
F_30 ( V_91 , L_14 , V_95 ) ;
F_30 ( V_91 , L_15 , V_96 ) ;
return V_92 + V_93 + V_94 + V_95 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_79 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
int V_102 , V_103 ;
T_5 V_104 , V_67 ;
int V_105 = V_9 ;
V_104 = F_12 ( F_32 ( V_4 ) ) ;
V_67 = F_33 ( V_4 ) ;
if ( V_40 -> V_50 [ V_104 ] [ V_67 ] . V_17 == V_51 ) {
struct V_106 * V_106 ;
struct V_107 * V_108 ;
int V_109 ;
T_6 V_110 ;
T_7 V_111 ;
F_34 ( L_16 ,
V_112 ,
V_41 -> V_113 , F_13 ( V_11 ) , F_14 ( V_11 ) , ( int ) V_11 -> V_114 ) ;
V_103 = 0 ;
for ( V_102 = 0 ; V_102 < ( V_41 -> V_71 + V_115 ) ; ++ V_102 ) {
V_106 = & V_40 -> V_116 [ V_102 ] ;
if ( * ( T_2 * ) V_106 -> V_117 != 0 &&
( V_106 -> V_88 & V_118 ) &&
( V_106 -> V_119 == V_4 ) ) {
V_103 = 1 ;
V_111 = ( (struct V_120 * )
V_106 -> V_117 ) -> V_121 ;
break;
}
}
if ( ! V_103 )
return V_105 ;
V_106 = F_35 ( V_40 ) ;
if ( ! V_106 )
return V_105 ;
V_108 = (struct V_107 * ) V_106 -> V_117 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_108 = V_122 ;
V_108 -> V_123 = V_40 -> V_50 [ V_104 ] [ V_67 ] . V_124 ;
V_108 -> V_114 [ 1 ] = V_4 -> V_79 -> V_114 ;
V_110 = ( T_6 ) V_106 -> V_125 ;
V_108 -> V_126 = F_36 ( ( T_5 ) ( V_110 >> 32 ) ) ;
V_108 -> V_127 = F_36 ( ( T_5 ) ( V_110 & 0xffffffff ) ) ;
V_108 -> V_128 = F_36 ( V_129 ) ;
V_106 -> V_130 = sizeof( * V_108 ) ;
V_4 -> V_6 . V_131 = 0 ;
V_109 = F_37 ( V_132 , V_106 ,
( V_133 ) V_134 ,
( void * ) V_4 ) ;
for ( V_102 = 0 ; V_102 < 15 ; ++ V_102 ) {
if ( V_4 -> V_6 . V_131 ) {
V_105 = V_135 ;
break;
}
F_38 ( 1000 ) ;
}
if ( V_105 != V_135 )
F_34 ( L_17 ,
V_112 ) ;
} else {
F_34 (
L_18
L_19 ,
V_112 , V_112 ,
V_41 -> V_113 , F_13 ( V_11 ) , F_14 ( V_11 ) ,
( int ) V_11 -> V_114 ) ;
switch ( V_4 -> V_136 [ 0 ] ) {
case V_137 :
if ( ! ( V_40 -> V_138 ) ||
! ( V_40 -> V_139 ) ||
( ( V_4 -> V_136 [ 1 ] & 0x1f ) != V_140 ) )
break;
case V_141 :
case V_142 :
for ( V_102 = 0 ;
V_102 < ( V_41 -> V_71 + V_115 ) ;
++ V_102 ) {
struct V_106 * V_106 = & V_40 -> V_116 [ V_102 ] ;
if ( V_106 -> V_117 -> V_143 . V_144 &&
( V_106 -> V_88 & V_145 ) &&
( V_106 -> V_119 == V_4 ) ) {
V_106 -> V_88 |=
V_146 ;
V_4 -> V_6 . V_7 =
V_99 ;
V_105 = V_135 ;
}
}
break;
case V_147 :
for ( V_102 = 0 ;
V_102 < ( V_41 -> V_71 + V_115 ) ;
++ V_102 ) {
struct V_3 * V_148 ;
struct V_106 * V_106 = & V_40 -> V_116 [ V_102 ] ;
V_148 = V_106 -> V_119 ;
if ( ( V_106 -> V_117 -> V_143 . V_144 &
F_36
( V_149 | V_150 ) ) &&
( V_106 -> V_88 & V_145 ) &&
( ( V_148 ) ) &&
( V_148 -> V_79 == V_4 -> V_79 ) ) {
V_106 -> V_88 |=
V_146 ;
V_148 -> V_6 . V_7 =
V_99 ;
if ( V_148 == V_4 )
V_105 = V_135 ;
}
}
break;
}
}
return V_105 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_79 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
int V_102 ;
T_5 V_104 , V_67 ;
int V_105 = V_9 ;
int V_109 = 0 ;
T_7 V_151 = 0 ;
bool V_152 ;
bool V_153 ;
bool V_154 ;
V_104 = F_12 ( F_32 ( V_4 ) ) ;
V_67 = F_33 ( V_4 ) ;
if ( V_104 < V_47 && V_67 < V_48 &&
V_40 -> V_50 [ V_104 ] [ V_67 ] . V_17 == V_51 ) {
struct V_106 * V_106 ;
int V_109 ;
T_6 V_110 ;
T_2 V_148 ;
F_34 ( L_20 ,
V_112 ) ;
V_106 = F_35 ( V_40 ) ;
if ( ! V_106 )
return V_105 ;
if ( V_40 -> V_50 [ V_104 ] [ V_67 ] . V_155 == 0 ) {
struct V_107 * V_108 ;
V_108 = (struct V_107 * ) V_106 -> V_117 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_108 = V_156 ;
V_108 -> V_123 = V_40 -> V_50 [ V_104 ] [ V_67 ] . V_124 ;
V_108 -> V_114 [ 1 ] = V_4 -> V_79 -> V_114 ;
V_110 = ( T_6 ) V_106 -> V_125 ;
V_108 -> V_126 = F_36
( ( T_5 ) ( V_110 >> 32 ) ) ;
V_108 -> V_127 = F_36
( ( T_5 ) ( V_110 & 0xffffffff ) ) ;
V_108 -> V_128 = F_36 ( V_129 ) ;
V_106 -> V_130 = sizeof( * V_108 ) ;
V_148 = V_132 ;
V_40 -> V_50 [ V_104 ] [ V_67 ] . V_155 ++ ;
} else if ( V_40 -> V_50 [ V_104 ] [ V_67 ] . V_155 >= 1 ) {
struct V_157 * V_158 ;
V_158 = (struct V_157 * ) V_106 -> V_117 ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
V_158 -> V_123 = V_40 -> V_50 [ V_104 ] [ V_67 ] . V_124 ;
V_110 = ( T_6 ) V_106 -> V_125 ;
V_158 -> V_126 = F_36 ( ( T_5 ) ( V_110 >> 32 ) ) ;
V_158 -> V_127 = F_36
( ( T_5 ) ( V_110 & 0xffffffff ) ) ;
V_158 -> V_128 = F_36 ( V_129 ) ;
V_106 -> V_130 = sizeof( * V_158 ) ;
V_148 = V_159 ;
V_40 -> V_50 [ V_104 ] [ V_67 ] . V_155 = 0 ;
}
V_4 -> V_6 . V_131 = 0 ;
V_109 = F_37 ( V_148 , V_106 ,
( V_133 ) V_134 ,
( void * ) V_4 ) ;
for ( V_102 = 0 ; V_102 < 15 ; ++ V_102 ) {
if ( V_4 -> V_6 . V_131 ) {
V_105 = V_135 ;
break;
}
F_38 ( 1000 ) ;
}
if ( V_105 == V_135 )
goto V_160;
} else {
for ( V_102 = 0 ;
V_102 < ( V_41 -> V_71 + V_115 ) ;
++ V_102 ) {
struct V_106 * V_106 = & V_40 -> V_116 [ V_102 ] ;
if ( V_106 -> V_117 -> V_143 . V_144 &&
( V_106 -> V_88 & V_145 ) &&
( V_106 -> V_119 == V_4 ) ) {
V_106 -> V_88 |= V_146 ;
V_4 -> V_6 . V_7 = V_99 ;
}
}
}
F_34 ( L_20 , V_112 ) ;
V_109 = F_40 ( V_40 ) ;
if ( V_109 )
F_41 ( & V_40 -> V_101 -> V_11 , L_21 , V_109 ) ;
V_102 = F_26 ( V_40 ) ;
if ( V_102 == 0 )
return V_135 ;
V_151 = V_40 -> V_161 . V_151 ;
V_152 = V_151 & V_162 ;
V_154 = V_151 & V_163 ;
V_153 = V_151 & V_164 ;
if ( ( V_152 || V_154 )
&& V_165
&& ( V_165 != - 1 || ! V_153 ) ) {
F_42 ( V_40 , 2 , V_166 ) ;
}
V_105 = V_135 ;
V_160:
return V_105 ;
}
static int F_43 ( struct V_167 * V_167 , struct V_168 * V_168 )
{
struct V_10 * V_40 ;
unsigned V_169 = F_44 ( V_167 ) ;
int V_170 = - V_171 ;
F_45 ( & V_172 ) ;
F_28 (aac, &aac_devices, entry) {
if ( V_40 -> V_173 == V_169 ) {
V_168 -> V_174 = V_40 ;
V_170 = 0 ;
break;
}
}
F_46 ( & V_172 ) ;
return V_170 ;
}
static long F_47 ( struct V_168 * V_168 ,
unsigned int V_4 , unsigned long V_85 )
{
struct V_10 * V_40 = (struct V_10 * ) V_168 -> V_174 ;
if ( ! F_24 ( V_86 ) )
return - V_87 ;
return F_25 ( V_40 , V_4 , ( void T_4 * ) V_85 ) ;
}
static long F_48 ( struct V_10 * V_11 , unsigned V_4 , unsigned long V_85 )
{
long V_105 ;
switch ( V_4 ) {
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
V_105 = F_25 ( V_11 , V_4 , ( void T_4 * ) V_85 ) ;
break;
case V_186 : {
struct V_187 T_4 * V_188 ;
V_188 = F_49 ( sizeof( * V_188 ) ) ;
V_105 = 0 ;
if ( F_50 ( V_188 , sizeof( * V_188 ) ) )
V_105 = - V_189 ;
if ( F_51 ( V_188 , ( void T_4 * ) V_85 , sizeof( struct V_187 ) - sizeof( T_5 ) ) )
V_105 = - V_189 ;
if ( ! V_105 )
V_105 = F_25 ( V_11 , V_4 , V_188 ) ;
break;
}
default:
V_105 = - V_190 ;
break;
}
return V_105 ;
}
static int F_52 ( struct V_18 * V_19 , int V_4 , void T_4 * V_85 )
{
struct V_10 * V_11 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( ! F_24 ( V_86 ) )
return - V_87 ;
return F_48 ( V_11 , V_4 , ( unsigned long ) V_85 ) ;
}
static long F_53 ( struct V_168 * V_168 , unsigned V_4 , unsigned long V_85 )
{
if ( ! F_24 ( V_86 ) )
return - V_87 ;
return F_48 ( V_168 -> V_174 , V_4 , V_85 ) ;
}
static T_3 F_54 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
int V_191 ;
if ( V_11 -> V_161 . V_192 [ 0 ] ) {
char * V_193 = V_11 -> V_161 . V_192 ;
while ( * V_193 && * V_193 != ' ' )
++ V_193 ;
while ( * V_193 == ' ' )
++ V_193 ;
V_191 = snprintf ( V_26 , V_82 , L_9 , V_193 ) ;
} else
V_191 = snprintf ( V_26 , V_82 , L_9 ,
V_13 [ V_11 -> V_14 ] . V_194 ) ;
return V_191 ;
}
static T_3 F_56 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
struct V_195 * V_196 ;
int V_191 ;
V_196 = & V_11 -> V_161 ;
if ( V_196 -> V_192 [ 0 ] ) {
char * V_193 = V_196 -> V_192 ;
while ( * V_193 && * V_193 != ' ' )
++ V_193 ;
V_191 = snprintf ( V_26 , V_82 , L_22 ,
( int ) ( V_193 - ( char * ) V_196 -> V_192 ) ,
V_196 -> V_192 ) ;
} else
V_191 = snprintf ( V_26 , V_82 , L_9 ,
V_13 [ V_11 -> V_14 ] . V_197 ) ;
return V_191 ;
}
static T_3 F_57 ( struct V_79 * V_198 ,
struct V_80 * V_81 , char * V_26 )
{
int V_191 = 0 ;
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_198 ) -> V_12 ;
if ( F_58 ( F_6 ( V_199 ) ) )
V_191 = snprintf ( V_26 , V_82 , L_23 ) ;
#ifdef F_59
V_191 += snprintf ( V_26 + V_191 , V_82 - V_191 ,
L_24 ) ;
#endif
if ( V_11 -> V_138 && V_11 -> V_139 )
V_191 += snprintf ( V_26 + V_191 , V_82 - V_191 ,
L_25 ) ;
if ( V_11 -> V_55 )
V_191 += snprintf ( V_26 + V_191 , V_82 - V_191 , L_26 ) ;
if ( V_11 -> V_161 . V_151 &
V_200 )
V_191 += snprintf ( V_26 + V_191 , V_82 - V_191 ,
L_27 ) ;
if ( V_11 -> V_201 )
V_191 += snprintf ( V_26 + V_191 , V_82 - V_191 , L_28 ) ;
return V_191 ;
}
static T_3 F_60 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
int V_191 , V_202 ;
V_202 = F_61 ( V_11 -> V_203 . V_204 ) ;
V_191 = snprintf ( V_26 , V_82 , L_29 ,
V_202 >> 24 , ( V_202 >> 16 ) & 0xff , V_202 & 0xff ,
F_61 ( V_11 -> V_203 . V_205 ) ) ;
return V_191 ;
}
static T_3 F_62 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
int V_191 , V_202 ;
V_202 = F_61 ( V_11 -> V_203 . V_206 ) ;
V_191 = snprintf ( V_26 , V_82 , L_29 ,
V_202 >> 24 , ( V_202 >> 16 ) & 0xff , V_202 & 0xff ,
F_61 ( V_11 -> V_203 . V_207 ) ) ;
return V_191 ;
}
static T_3 F_63 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
int V_191 , V_202 ;
V_202 = F_61 ( V_11 -> V_203 . V_208 ) ;
V_191 = snprintf ( V_26 , V_82 , L_29 ,
V_202 >> 24 , ( V_202 >> 16 ) & 0xff , V_202 & 0xff ,
F_61 ( V_11 -> V_203 . V_209 ) ) ;
return V_191 ;
}
static T_3 F_64 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
return snprintf ( V_26 , V_82 , L_9 , V_210 ) ;
}
static T_3 F_65 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
int V_191 = 0 ;
if ( F_61 ( V_11 -> V_203 . V_211 [ 0 ] ) != 0xBAD0 )
V_191 = snprintf ( V_26 , 16 , L_30 ,
F_61 ( V_11 -> V_203 . V_211 [ 0 ] ) ) ;
if ( V_191 &&
! memcmp ( & V_11 -> V_161 . V_212 [
sizeof( V_11 -> V_161 . V_212 ) - V_191 ] ,
V_26 , V_191 - 1 ) )
V_191 = snprintf ( V_26 , 16 , L_22 ,
( int ) sizeof( V_11 -> V_161 . V_212 ) ,
V_11 -> V_161 . V_212 ) ;
return F_66 ( V_191 , 16 ) ;
}
static T_3 F_67 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
return snprintf ( V_26 , V_82 , L_31 ,
F_55 ( V_79 ) -> V_213 ) ;
}
static T_3 F_68 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
return snprintf ( V_26 , V_82 , L_31 ,
F_55 ( V_79 ) -> V_214 ) ;
}
static T_3 F_69 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
const char * V_26 , T_8 V_102 )
{
int V_215 = - V_216 ;
int V_217 = 0 ;
struct V_10 * V_40 ;
if ( ! F_24 ( V_218 ) )
return V_215 ;
V_40 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
V_217 = V_26 [ 0 ] == '!' ? 1 : 0 ;
V_215 = F_42 ( V_40 , V_217 , V_166 ) ;
if ( V_215 >= 0 )
V_215 = V_102 ;
return V_215 ;
}
static T_3 F_70 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_55 ( V_79 ) -> V_12 ;
int V_191 , V_202 ;
V_202 = F_40 ( V_11 ) ;
if ( ( V_202 == 0 ) && V_11 -> V_219 )
V_202 = - V_220 ;
V_191 = snprintf ( V_26 , V_82 , L_32 , V_202 ) ;
return V_191 ;
}
T_3 F_71 ( struct V_79 * V_79 , char * V_26 )
{
return F_65 ( V_79 , & V_221 , V_26 ) ;
}
static void F_72 ( struct V_10 * V_40 )
{
int V_222 ;
V_40 -> V_223 = 1 ;
F_73 ( V_40 ) ;
if ( V_40 -> V_224 ) {
int V_222 ;
for ( V_222 = 0 ; V_222 < ( V_40 -> V_89 -> V_71 + V_115 ) ; V_222 ++ ) {
struct V_106 * V_106 = & V_40 -> V_116 [ V_222 ] ;
if ( ! ( V_106 -> V_117 -> V_143 . V_144 & F_36 ( V_150 | V_149 ) ) &&
( V_106 -> V_117 -> V_143 . V_144 & F_36 ( V_225 ) ) )
F_74 ( & V_106 -> V_226 ) ;
}
F_75 ( V_40 -> V_227 ) ;
}
F_76 ( V_40 ) ;
if ( F_77 ( V_40 ) ) {
if ( V_40 -> V_228 > 1 ) {
for ( V_222 = 0 ; V_222 < V_40 -> V_228 ; V_222 ++ ) {
F_78 ( F_79 ( V_40 -> V_101 , V_222 ) ,
& ( V_40 -> V_229 [ V_222 ] ) ) ;
}
} else {
F_78 ( V_40 -> V_101 -> V_230 ,
& ( V_40 -> V_229 [ 0 ] ) ) ;
}
} else {
F_78 ( V_40 -> V_101 -> V_230 , V_40 ) ;
}
if ( V_40 -> V_201 )
F_80 ( V_40 -> V_101 ) ;
else if ( V_40 -> V_228 > 1 )
F_81 ( V_40 -> V_101 ) ;
}
static void F_82 ( void )
{
V_231 = F_83 ( 0 , L_33 , & V_232 ) ;
if ( V_231 < 0 ) {
F_34 ( L_34 ) ;
}
}
static int F_84 ( struct V_233 * V_101 , const struct V_234 * V_173 )
{
unsigned V_235 = V_173 -> V_236 ;
struct V_1 * V_2 ;
struct V_10 * V_40 ;
struct V_237 * V_238 = & V_239 ;
int error = - V_171 ;
int V_240 = 0 ;
T_6 V_241 ;
int V_242 = 0 ;
extern int V_243 ;
if ( V_101 -> V_79 == V_244 )
V_101 -> V_245 = 1 ;
F_28 (aac, &aac_devices, entry) {
if ( V_40 -> V_173 > V_240 )
break;
V_238 = & V_40 -> V_34 ;
V_240 ++ ;
}
F_85 ( V_101 , V_246 | V_247 |
V_248 ) ;
error = F_86 ( V_101 ) ;
if ( error )
goto V_160;
error = - V_171 ;
if ( ! ( V_13 [ V_235 ] . V_249 & V_250 ) ) {
error = F_87 ( V_101 , F_88 ( 32 ) ) ;
if ( error ) {
F_41 ( & V_101 -> V_11 , L_35 ) ;
goto V_251;
}
}
if ( V_13 [ V_235 ] . V_249 & V_252 ) {
V_241 = F_88 ( 31 ) ;
V_242 = 31 ;
} else {
V_241 = F_88 ( 32 ) ;
V_242 = 32 ;
}
error = F_89 ( V_101 , V_241 ) ;
if ( error ) {
F_41 ( & V_101 -> V_11 , L_36
, V_242 ) ;
goto V_251;
}
F_90 ( V_101 ) ;
V_2 = F_91 ( & V_253 , sizeof( struct V_10 ) ) ;
if ( ! V_2 )
goto V_251;
V_2 -> V_230 = V_101 -> V_230 ;
V_2 -> V_240 = V_240 ;
V_2 -> V_254 = 16 ;
V_2 -> V_255 = 1 ;
if ( V_231 == V_256 )
F_82 () ;
V_40 = (struct V_10 * ) V_2 -> V_12 ;
V_40 -> V_257 = F_92 ( V_101 , 0 ) ;
V_40 -> V_89 = V_2 ;
V_40 -> V_101 = V_101 ;
V_40 -> V_15 = V_253 . V_15 ;
V_40 -> V_173 = V_2 -> V_240 ;
V_40 -> V_14 = V_235 ;
F_93 ( & V_40 -> V_34 ) ;
V_40 -> V_116 = F_94 ( sizeof( struct V_106 ) * ( V_2 -> V_71 + V_115 ) , V_258 ) ;
if ( ! V_40 -> V_116 )
goto V_259;
F_95 ( & V_40 -> V_260 ) ;
F_96 ( & V_40 -> V_261 ) ;
V_40 -> V_262 = V_263 ;
if ( ( * V_13 [ V_235 ] . V_264 ) ( V_40 ) )
goto V_265;
if ( V_40 -> V_266 ) {
if ( V_243 )
F_97 ( V_267 L_37
L_38
L_39 ,
V_40 -> V_15 ,
V_40 -> V_173 ) ;
else
F_97 ( V_267 L_40
L_41
L_42 ,
V_40 -> V_15 ,
V_40 -> V_173 ) ;
}
V_40 -> V_227 = F_98 ( V_268 , V_40 , V_112 ) ;
if ( F_99 ( V_40 -> V_227 ) ) {
F_97 ( V_269 L_43 ) ;
error = F_100 ( V_40 -> V_227 ) ;
V_40 -> V_227 = NULL ;
goto V_270;
}
V_40 -> V_271 = V_13 [ V_235 ] . V_272 ;
error = F_101 ( V_40 ) ;
if ( error < 0 )
goto V_270;
if ( ( V_13 [ V_235 ] . V_249 & V_273 ) &&
( V_2 -> V_274 > 34 ) ) {
V_2 -> V_274 = 34 ;
V_2 -> V_275 = ( V_2 -> V_274 * 8 ) + 112 ;
}
if ( ( V_13 [ V_235 ] . V_249 & V_276 ) &&
( V_2 -> V_274 > 17 ) ) {
V_2 -> V_274 = 17 ;
V_2 -> V_275 = ( V_2 -> V_274 * 8 ) + 112 ;
}
error = F_102 ( V_101 ,
( V_40 -> V_203 . V_277 & V_278 ) ?
( V_2 -> V_275 << 9 ) : 65536 ) ;
if ( error )
goto V_270;
if ( V_13 [ V_235 ] . V_249 & V_273 )
V_40 -> V_279 = 1 ;
else
V_40 -> V_279 = 0 ;
if ( V_40 -> V_280 || V_61 || V_40 -> V_55 )
V_2 -> V_213 = V_40 -> V_271 ;
else
V_2 -> V_213 = 0 ;
F_103 ( V_40 , 0 ) ;
F_104 ( V_40 ) ;
F_105 ( & V_40 -> V_34 , V_238 ) ;
V_2 -> V_214 = V_40 -> V_68 ;
if ( V_2 -> V_214 < V_40 -> V_281 )
V_2 -> V_214 = V_40 -> V_281 ;
if ( V_2 -> V_214 < V_282 )
V_2 -> V_214 = V_282 ;
else
V_2 -> V_283 = V_2 -> V_214 ;
if ( ! V_40 -> V_49 && V_13 [ V_235 ] . V_249 & V_250 )
F_106 ( V_40 , 0 , 2 , 0 , NULL ) ;
V_2 -> V_284 = V_285 ;
F_107 ( V_101 , V_2 ) ;
error = F_108 ( V_2 , & V_101 -> V_11 ) ;
if ( error )
goto V_270;
F_109 ( V_2 ) ;
F_110 ( V_101 ) ;
F_111 ( V_101 ) ;
return 0 ;
V_270:
F_72 ( V_40 ) ;
V_265:
F_112 ( V_40 ) ;
if ( V_40 -> V_286 )
F_113 ( & V_40 -> V_101 -> V_11 , V_40 -> V_287 ,
V_40 -> V_286 , V_40 -> V_288 ) ;
F_10 ( V_40 -> V_289 ) ;
F_114 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_116 ) ;
F_10 ( V_40 -> V_69 ) ;
V_259:
F_115 ( V_2 ) ;
V_251:
F_116 ( V_101 ) ;
V_160:
return error ;
}
static void F_117 ( struct V_10 * V_40 )
{
F_76 ( V_40 ) ;
F_118 ( V_40 ) ;
}
static int F_119 ( struct V_10 * V_11 )
{
unsigned long V_109 ;
while ( ! ( ( V_109 = F_120 ( V_11 , V_290 . V_291 ) ) & V_292 )
|| V_109 == 0xffffffff )
F_38 ( 20 ) ;
F_76 ( V_11 ) ;
F_121 ( V_11 ) ;
if ( F_77 ( V_11 ) )
F_122 ( V_11 ) ;
if ( V_11 -> V_293 )
F_123 ( V_11 , V_294 ) ;
if ( F_124 ( V_11 ) )
goto V_295;
F_121 ( V_11 ) ;
F_125 ( V_11 ) ;
if ( ! V_11 -> V_266 ) {
V_11 -> V_264 -> V_296 . V_297 = F_36 ( V_11 -> V_228 ) ;
F_126 ( V_11 ) ;
}
return 0 ;
V_295:
return - 1 ;
}
static int F_127 ( struct V_233 * V_101 , T_9 V_298 )
{
struct V_1 * V_2 = F_128 ( V_101 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_129 ( V_2 ) ;
F_73 ( V_40 ) ;
F_117 ( V_40 ) ;
F_107 ( V_101 , V_2 ) ;
F_111 ( V_101 ) ;
F_116 ( V_101 ) ;
F_130 ( V_101 , F_131 ( V_101 , V_298 ) ) ;
return 0 ;
}
static int F_132 ( struct V_233 * V_101 )
{
struct V_1 * V_2 = F_128 ( V_101 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
int V_5 ;
F_130 ( V_101 , V_299 ) ;
F_133 ( V_101 , V_299 , 0 ) ;
F_134 ( V_101 ) ;
V_5 = F_86 ( V_101 ) ;
if ( V_5 )
goto V_300;
F_90 ( V_101 ) ;
if ( F_119 ( V_40 ) )
goto V_300;
V_40 -> V_223 = 0 ;
F_135 ( V_2 ) ;
return 0 ;
V_300:
F_97 ( V_267 L_44 , V_40 -> V_15 , V_40 -> V_173 ) ;
F_115 ( V_2 ) ;
F_116 ( V_101 ) ;
return - V_171 ;
}
static void F_136 ( struct V_233 * V_11 )
{
struct V_1 * V_2 = F_128 ( V_11 ) ;
F_129 ( V_2 ) ;
F_72 ( (struct V_10 * ) V_2 -> V_12 ) ;
}
static void F_137 ( struct V_233 * V_101 )
{
struct V_1 * V_2 = F_128 ( V_101 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_138 ( V_2 ) ;
F_72 ( V_40 ) ;
F_112 ( V_40 ) ;
F_113 ( & V_40 -> V_101 -> V_11 , V_40 -> V_287 , V_40 -> V_286 ,
V_40 -> V_288 ) ;
F_10 ( V_40 -> V_289 ) ;
F_114 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_116 ) ;
F_10 ( V_40 -> V_69 ) ;
F_139 ( & V_40 -> V_34 ) ;
F_115 ( V_2 ) ;
F_116 ( V_101 ) ;
if ( F_140 ( & V_239 ) ) {
F_141 ( V_231 , L_33 ) ;
V_231 = V_256 ;
}
}
static void F_142 ( struct V_10 * V_40 )
{
int V_222 ;
struct V_3 * V_4 ;
for ( V_222 = 0 ; V_222 < V_40 -> V_89 -> V_71 ; V_222 ++ ) {
V_4 = (struct V_3 * ) V_40 -> V_116 [ V_222 ] . V_119 ;
if ( V_4 && ( V_4 -> V_6 . V_7 == V_98 ) ) {
F_143 ( V_4 ) ;
if ( V_40 -> V_301 )
V_4 -> V_302 = V_303 << 16 ;
else
V_4 -> V_302 = V_304 << 16 ;
V_4 -> V_305 ( V_4 ) ;
}
}
}
static T_10 F_144 ( struct V_233 * V_101 ,
enum V_306 error )
{
struct V_1 * V_2 = F_128 ( V_101 ) ;
struct V_10 * V_40 = F_145 ( V_2 ) ;
F_41 ( & V_101 -> V_11 , L_45 , error ) ;
switch ( error ) {
case V_307 :
return V_308 ;
case V_309 :
V_40 -> V_301 = 1 ;
F_129 ( V_40 -> V_89 ) ;
F_142 ( V_40 ) ;
F_117 ( V_40 ) ;
F_146 ( V_101 ) ;
F_114 ( V_40 , 0 ) ;
return V_310 ;
case V_311 :
V_40 -> V_301 = 1 ;
F_142 ( V_40 ) ;
return V_312 ;
}
return V_310 ;
}
static T_10 F_147 ( struct V_233 * V_101 )
{
F_41 ( & V_101 -> V_11 , L_46 ) ;
return V_310 ;
}
static T_10 F_148 ( struct V_233 * V_101 )
{
F_41 ( & V_101 -> V_11 , L_47 ) ;
F_134 ( V_101 ) ;
if ( F_86 ( V_101 ) ) {
F_149 ( & V_101 -> V_11 ,
L_48 ) ;
goto V_300;
}
F_90 ( V_101 ) ;
if ( F_150 ( V_101 ) ) {
F_41 ( & V_101 -> V_11 , L_49 ) ;
goto V_300;
}
return V_313 ;
V_300:
F_41 ( & V_101 -> V_11 , L_50 ) ;
return V_312 ;
}
static void F_151 ( struct V_233 * V_101 )
{
struct V_1 * V_2 = F_128 ( V_101 ) ;
struct V_18 * V_19 = NULL ;
struct V_10 * V_40 = (struct V_10 * ) F_145 ( V_2 ) ;
F_152 ( V_101 ) ;
if ( F_114 ( V_40 , V_40 -> V_262 ) ) {
F_41 ( & V_101 -> V_11 , L_51 ) ;
V_40 -> V_314 = V_315 ;
if ( F_114 ( V_40 , V_263 ) ) {
F_149 ( & V_101 -> V_11 ,
L_52 ) ;
return;
}
}
F_38 ( 10000 ) ;
F_119 ( V_40 ) ;
V_40 -> V_223 = 0 ;
V_40 -> V_301 = 0 ;
F_153 (sdev, shost)
if ( V_19 -> V_316 == V_317 )
V_19 -> V_316 = V_318 ;
F_135 ( V_40 -> V_89 ) ;
F_109 ( V_40 -> V_89 ) ;
F_111 ( V_101 ) ;
F_41 ( & V_101 -> V_11 , L_53 ) ;
}
static int T_11 F_154 ( void )
{
int error ;
F_97 ( V_267 L_54 ,
V_112 , V_210 ) ;
error = F_155 ( & V_319 ) ;
if ( error < 0 )
return error ;
F_82 () ;
return 0 ;
}
static void T_12 F_156 ( void )
{
if ( V_231 > - 1 )
F_141 ( V_231 , L_33 ) ;
F_157 ( & V_319 ) ;
}
