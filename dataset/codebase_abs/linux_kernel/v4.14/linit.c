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
static T_2 F_39 ( struct V_151 * V_152 ,
struct V_106 * V_106 , T_6 V_153 )
{
struct V_107 * V_108 ;
T_6 V_110 ;
V_108 = (struct V_107 * ) V_106 -> V_117 ;
memset ( V_108 , 0 , sizeof( * V_108 ) ) ;
V_108 -> V_108 = V_154 ;
V_108 -> V_123 = V_152 -> V_124 ;
F_40 ( V_153 , (struct V_155 * ) V_108 -> V_114 ) ;
V_110 = ( T_6 ) V_106 -> V_125 ;
V_108 -> V_126 = F_36
( ( T_5 ) ( V_110 >> 32 ) ) ;
V_108 -> V_127 = F_36
( ( T_5 ) ( V_110 & 0xffffffff ) ) ;
V_108 -> V_128 = F_36 ( V_129 ) ;
V_106 -> V_130 = sizeof( * V_108 ) ;
return V_132 ;
}
static T_2 F_41 ( struct V_151 * V_152 ,
struct V_106 * V_106 )
{
struct V_156 * V_157 ;
T_6 V_110 ;
V_157 = (struct V_156 * ) V_106 -> V_117 ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
V_157 -> V_123 = V_152 -> V_124 ;
V_110 = ( T_6 ) V_106 -> V_125 ;
V_157 -> V_126 = F_36 ( ( T_5 ) ( V_110 >> 32 ) ) ;
V_157 -> V_127 = F_36
( ( T_5 ) ( V_110 & 0xffffffff ) ) ;
V_157 -> V_128 = F_36 ( V_129 ) ;
V_106 -> V_130 = sizeof( * V_157 ) ;
return V_158 ;
}
void F_42 ( void * V_159 , struct V_106 * V_160 )
{
struct V_161 * V_162 =
& ( (struct V_163 * ) V_160 -> V_117 ) -> V_164 . V_162 ;
struct V_151 * V_152 = V_159 ;
int V_165 ;
switch ( V_162 -> V_166 ) {
case V_167 :
V_165 = - 1 ;
break;
case V_168 :
V_165 = 0 ;
break;
case V_169 :
case V_170 :
V_165 = 0 ;
break;
default:
V_165 = - 2 ;
break;
}
F_43 ( V_160 ) ;
V_152 -> V_171 = V_165 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_79 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
struct V_151 * V_152 ;
int V_102 ;
T_5 V_104 , V_67 ;
struct V_106 * V_106 ;
int V_105 = V_9 ;
int V_109 ;
T_2 V_148 ;
V_104 = F_12 ( F_32 ( V_4 ) ) ;
V_67 = F_33 ( V_4 ) ;
if ( V_104 >= V_47 || V_67 >= V_48 )
return V_9 ;
V_152 = & V_40 -> V_50 [ V_104 ] [ V_67 ] ;
if ( V_152 -> V_17 != V_51 &&
V_152 -> V_171 > 0 )
return V_9 ;
F_34 ( L_20 ,
V_112 ) ;
V_106 = F_35 ( V_40 ) ;
if ( ! V_106 )
return V_105 ;
V_148 = F_39 ( V_152 , V_106 , V_11 -> V_114 ) ;
V_152 -> V_171 = 1 ;
V_109 = F_37 ( V_148 , V_106 ,
( V_133 ) F_42 ,
( void * ) V_152 ) ;
for ( V_102 = 0 ; V_102 < 15 ; ++ V_102 ) {
if ( V_152 -> V_171 == 0 ) {
V_105 = V_152 -> V_171 == 0 ? V_135 : V_9 ;
break;
}
F_38 ( 1000 ) ;
}
return V_105 ;
}
static int F_45 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_79 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
struct V_151 * V_152 ;
int V_102 ;
T_5 V_104 , V_67 ;
int V_105 = V_9 ;
struct V_106 * V_106 ;
int V_109 ;
T_2 V_148 ;
V_104 = F_12 ( F_32 ( V_4 ) ) ;
V_67 = F_33 ( V_4 ) ;
if ( V_104 >= V_47 || V_67 >= V_48 )
return V_9 ;
V_152 = & V_40 -> V_50 [ V_104 ] [ V_67 ] ;
if ( V_152 -> V_17 != V_51 &&
V_152 -> V_171 > 0 )
return V_9 ;
F_34 ( L_20 ,
V_112 ) ;
V_106 = F_35 ( V_40 ) ;
if ( ! V_106 )
return V_105 ;
V_148 = F_41 ( V_152 , V_106 ) ;
V_152 -> V_171 = 2 ;
V_109 = F_37 ( V_148 , V_106 ,
( V_133 ) F_42 ,
( void * ) V_152 ) ;
for ( V_102 = 0 ; V_102 < 15 ; ++ V_102 ) {
if ( V_152 -> V_171 <= 0 ) {
V_105 = V_152 -> V_171 == 0 ? V_135 : V_9 ;
break;
}
F_38 ( 1000 ) ;
}
return V_105 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_79 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
int V_102 ;
T_5 V_172 ;
int V_109 = 0 ;
V_172 = F_12 ( F_32 ( V_4 ) ) ;
for ( V_102 = 0 ; V_102 < ( V_41 -> V_71 + V_115 ) ; ++ V_102 ) {
struct V_106 * V_106 = & V_40 -> V_116 [ V_102 ] ;
if ( V_106 -> V_117 -> V_143 . V_144 &&
( V_106 -> V_88 & V_145 ) &&
( V_106 -> V_88 & V_173 ) ) {
struct V_151 * V_152 ;
T_5 V_104 , V_67 ;
V_4 = (struct V_3 * ) V_106 -> V_119 ;
V_104 = F_12 ( F_32 ( V_4 ) ) ;
if ( V_104 != V_172 )
continue;
V_67 = F_33 ( V_4 ) ;
V_152 = & V_40 -> V_50 [ V_104 ] [ V_67 ] ;
if ( V_104 >= V_47 || V_67 >= V_48 ||
V_152 -> V_17 != V_51 ) {
V_106 -> V_88 |= V_146 ;
V_4 -> V_6 . V_7 = V_99 ;
}
}
}
F_34 ( L_20 , V_112 ) ;
V_109 = F_47 ( V_40 ) ;
if ( V_109 )
F_48 ( & V_40 -> V_101 -> V_11 , L_21 , V_109 ) ;
V_102 = F_26 ( V_40 ) ;
return ( V_102 == 0 ) ? V_135 : V_9 ;
}
int F_49 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_79 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
int V_105 = V_9 ;
T_7 V_174 = 0 ;
bool V_175 ;
bool V_176 ;
bool V_177 ;
V_174 = V_40 -> V_178 . V_174 ;
V_175 = V_174 & V_179 ;
V_177 = V_174 & V_180 ;
V_176 = V_174 & V_181 ;
if ( ( V_175 || V_177 )
&& V_182
&& ( V_182 != - 1 || ! V_176 ) ) {
if ( F_50 ( V_40 , 2 , V_183 ) == 0 )
V_105 = V_135 ;
}
if ( V_105 == V_135 ) {
int V_104 , V_67 ;
struct V_151 * V_152 ;
for ( V_104 = 0 ; V_104 < V_47 ; V_104 ++ ) {
for ( V_67 = 0 ; V_67 < V_48 ; V_67 ++ ) {
V_152 = & V_40 -> V_50 [ V_104 ] [ V_67 ] ;
if ( V_152 -> V_17 == V_51 )
V_152 -> V_171 = 0 ;
}
}
}
return V_105 ;
}
static int F_51 ( struct V_184 * V_184 , struct V_185 * V_185 )
{
struct V_10 * V_40 ;
unsigned V_186 = F_52 ( V_184 ) ;
int V_162 = - V_187 ;
F_53 ( & V_188 ) ;
F_28 (aac, &aac_devices, entry) {
if ( V_40 -> V_189 == V_186 ) {
V_185 -> V_190 = V_40 ;
V_162 = 0 ;
break;
}
}
F_54 ( & V_188 ) ;
return V_162 ;
}
static long F_55 ( struct V_185 * V_185 ,
unsigned int V_4 , unsigned long V_85 )
{
struct V_10 * V_40 = (struct V_10 * ) V_185 -> V_190 ;
if ( ! F_24 ( V_86 ) )
return - V_87 ;
return F_25 ( V_40 , V_4 , ( void T_4 * ) V_85 ) ;
}
static long F_56 ( struct V_10 * V_11 , unsigned V_4 , unsigned long V_85 )
{
long V_105 ;
switch ( V_4 ) {
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
V_105 = F_25 ( V_11 , V_4 , ( void T_4 * ) V_85 ) ;
break;
case V_202 : {
struct V_203 T_4 * V_204 ;
V_204 = F_57 ( sizeof( * V_204 ) ) ;
V_105 = 0 ;
if ( F_58 ( V_204 , sizeof( * V_204 ) ) )
V_105 = - V_205 ;
if ( F_59 ( V_204 , ( void T_4 * ) V_85 , sizeof( struct V_203 ) - sizeof( T_5 ) ) )
V_105 = - V_205 ;
if ( ! V_105 )
V_105 = F_25 ( V_11 , V_4 , V_204 ) ;
break;
}
default:
V_105 = - V_206 ;
break;
}
return V_105 ;
}
static int F_60 ( struct V_18 * V_19 , int V_4 , void T_4 * V_85 )
{
struct V_10 * V_11 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( ! F_24 ( V_86 ) )
return - V_87 ;
return F_56 ( V_11 , V_4 , ( unsigned long ) V_85 ) ;
}
static long F_61 ( struct V_185 * V_185 , unsigned V_4 , unsigned long V_85 )
{
if ( ! F_24 ( V_86 ) )
return - V_87 ;
return F_56 ( V_185 -> V_190 , V_4 , V_85 ) ;
}
static T_3 F_62 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
int V_207 ;
if ( V_11 -> V_178 . V_208 [ 0 ] ) {
char * V_209 = V_11 -> V_178 . V_208 ;
while ( * V_209 && * V_209 != ' ' )
++ V_209 ;
while ( * V_209 == ' ' )
++ V_209 ;
V_207 = snprintf ( V_26 , V_82 , L_9 , V_209 ) ;
} else
V_207 = snprintf ( V_26 , V_82 , L_9 ,
V_13 [ V_11 -> V_14 ] . V_210 ) ;
return V_207 ;
}
static T_3 F_64 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
struct V_211 * V_212 ;
int V_207 ;
V_212 = & V_11 -> V_178 ;
if ( V_212 -> V_208 [ 0 ] ) {
char * V_209 = V_212 -> V_208 ;
while ( * V_209 && * V_209 != ' ' )
++ V_209 ;
V_207 = snprintf ( V_26 , V_82 , L_22 ,
( int ) ( V_209 - ( char * ) V_212 -> V_208 ) ,
V_212 -> V_208 ) ;
} else
V_207 = snprintf ( V_26 , V_82 , L_9 ,
V_13 [ V_11 -> V_14 ] . V_213 ) ;
return V_207 ;
}
static T_3 F_65 ( struct V_79 * V_214 ,
struct V_80 * V_81 , char * V_26 )
{
int V_207 = 0 ;
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_214 ) -> V_12 ;
if ( F_66 ( F_6 ( V_215 ) ) )
V_207 = snprintf ( V_26 , V_82 , L_23 ) ;
#ifdef F_67
V_207 += snprintf ( V_26 + V_207 , V_82 - V_207 ,
L_24 ) ;
#endif
if ( V_11 -> V_138 && V_11 -> V_139 )
V_207 += snprintf ( V_26 + V_207 , V_82 - V_207 ,
L_25 ) ;
if ( V_11 -> V_55 )
V_207 += snprintf ( V_26 + V_207 , V_82 - V_207 , L_26 ) ;
if ( V_11 -> V_178 . V_174 &
V_216 )
V_207 += snprintf ( V_26 + V_207 , V_82 - V_207 ,
L_27 ) ;
if ( V_11 -> V_217 )
V_207 += snprintf ( V_26 + V_207 , V_82 - V_207 , L_28 ) ;
return V_207 ;
}
static T_3 F_68 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
int V_207 , V_218 ;
V_218 = F_69 ( V_11 -> V_219 . V_220 ) ;
V_207 = snprintf ( V_26 , V_82 , L_29 ,
V_218 >> 24 , ( V_218 >> 16 ) & 0xff , V_218 & 0xff ,
F_69 ( V_11 -> V_219 . V_221 ) ) ;
return V_207 ;
}
static T_3 F_70 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
int V_207 , V_218 ;
V_218 = F_69 ( V_11 -> V_219 . V_222 ) ;
V_207 = snprintf ( V_26 , V_82 , L_29 ,
V_218 >> 24 , ( V_218 >> 16 ) & 0xff , V_218 & 0xff ,
F_69 ( V_11 -> V_219 . V_223 ) ) ;
return V_207 ;
}
static T_3 F_71 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
int V_207 , V_218 ;
V_218 = F_69 ( V_11 -> V_219 . V_224 ) ;
V_207 = snprintf ( V_26 , V_82 , L_29 ,
V_218 >> 24 , ( V_218 >> 16 ) & 0xff , V_218 & 0xff ,
F_69 ( V_11 -> V_219 . V_225 ) ) ;
return V_207 ;
}
static T_3 F_72 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
return snprintf ( V_26 , V_82 , L_9 , V_226 ) ;
}
static T_3 F_73 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
int V_207 = 0 ;
if ( F_69 ( V_11 -> V_219 . V_227 [ 0 ] ) != 0xBAD0 )
V_207 = snprintf ( V_26 , 16 , L_30 ,
F_69 ( V_11 -> V_219 . V_227 [ 0 ] ) ) ;
if ( V_207 &&
! memcmp ( & V_11 -> V_178 . V_228 [
sizeof( V_11 -> V_178 . V_228 ) - V_207 ] ,
V_26 , V_207 - 1 ) )
V_207 = snprintf ( V_26 , 16 , L_22 ,
( int ) sizeof( V_11 -> V_178 . V_228 ) ,
V_11 -> V_178 . V_228 ) ;
return F_74 ( V_207 , 16 ) ;
}
static T_3 F_75 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
return snprintf ( V_26 , V_82 , L_31 ,
F_63 ( V_79 ) -> V_229 ) ;
}
static T_3 F_76 ( struct V_79 * V_79 ,
struct V_80 * V_81 , char * V_26 )
{
return snprintf ( V_26 , V_82 , L_31 ,
F_63 ( V_79 ) -> V_230 ) ;
}
static T_3 F_77 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
const char * V_26 , T_8 V_102 )
{
int V_231 = - V_232 ;
int V_233 = 0 ;
struct V_10 * V_40 ;
if ( ! F_24 ( V_234 ) )
return V_231 ;
V_40 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
V_233 = V_26 [ 0 ] == '!' ? 1 : 0 ;
V_231 = F_50 ( V_40 , V_233 , V_183 ) ;
if ( V_231 >= 0 )
V_231 = V_102 ;
return V_231 ;
}
static T_3 F_78 ( struct V_79 * V_79 ,
struct V_80 * V_81 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_63 ( V_79 ) -> V_12 ;
int V_207 , V_218 ;
V_218 = F_47 ( V_11 ) ;
if ( ( V_218 == 0 ) && V_11 -> V_235 )
V_218 = - V_236 ;
V_207 = snprintf ( V_26 , V_82 , L_32 , V_218 ) ;
return V_207 ;
}
T_3 F_79 ( struct V_79 * V_79 , char * V_26 )
{
return F_73 ( V_79 , & V_237 , V_26 ) ;
}
static void F_80 ( struct V_10 * V_40 )
{
int V_238 ;
F_53 ( & V_40 -> V_239 ) ;
V_40 -> V_240 = 1 ;
F_54 ( & V_40 -> V_239 ) ;
if ( V_40 -> V_241 ) {
int V_238 ;
for ( V_238 = 0 ; V_238 < ( V_40 -> V_89 -> V_71 + V_115 ) ; V_238 ++ ) {
struct V_106 * V_106 = & V_40 -> V_116 [ V_238 ] ;
if ( ! ( V_106 -> V_117 -> V_143 . V_144 & F_36 ( V_150 | V_149 ) ) &&
( V_106 -> V_117 -> V_143 . V_144 & F_36 ( V_242 ) ) )
F_81 ( & V_106 -> V_243 ) ;
}
F_82 ( V_40 -> V_244 ) ;
}
F_83 ( V_40 ) ;
F_84 ( V_40 ) ;
if ( F_85 ( V_40 ) ) {
if ( V_40 -> V_245 > 1 ) {
for ( V_238 = 0 ; V_238 < V_40 -> V_245 ; V_238 ++ ) {
F_86 ( F_87 ( V_40 -> V_101 , V_238 ) ,
& ( V_40 -> V_246 [ V_238 ] ) ) ;
}
} else {
F_86 ( V_40 -> V_101 -> V_247 ,
& ( V_40 -> V_246 [ 0 ] ) ) ;
}
} else {
F_86 ( V_40 -> V_101 -> V_247 , V_40 ) ;
}
if ( V_40 -> V_217 )
F_88 ( V_40 -> V_101 ) ;
else if ( V_40 -> V_245 > 1 )
F_89 ( V_40 -> V_101 ) ;
}
static void F_90 ( void )
{
V_248 = F_91 ( 0 , L_33 , & V_249 ) ;
if ( V_248 < 0 ) {
F_34 ( L_34 ) ;
}
}
static int F_92 ( struct V_250 * V_101 , const struct V_251 * V_189 )
{
unsigned V_252 = V_189 -> V_253 ;
struct V_1 * V_2 ;
struct V_10 * V_40 ;
struct V_254 * V_255 = & V_256 ;
int error = - V_187 ;
int V_257 = 0 ;
T_6 V_258 ;
int V_259 = 0 ;
extern int V_260 ;
if ( V_101 -> V_79 == V_261 )
V_101 -> V_262 = 1 ;
F_28 (aac, &aac_devices, entry) {
if ( V_40 -> V_189 > V_257 )
break;
V_255 = & V_40 -> V_34 ;
V_257 ++ ;
}
F_93 ( V_101 , V_263 | V_264 |
V_265 ) ;
error = F_94 ( V_101 ) ;
if ( error )
goto V_266;
error = - V_187 ;
if ( ! ( V_13 [ V_252 ] . V_267 & V_268 ) ) {
error = F_95 ( V_101 , F_96 ( 32 ) ) ;
if ( error ) {
F_48 ( & V_101 -> V_11 , L_35 ) ;
goto V_269;
}
}
if ( V_13 [ V_252 ] . V_267 & V_270 ) {
V_258 = F_96 ( 31 ) ;
V_259 = 31 ;
} else {
V_258 = F_96 ( 32 ) ;
V_259 = 32 ;
}
error = F_97 ( V_101 , V_258 ) ;
if ( error ) {
F_48 ( & V_101 -> V_11 , L_36
, V_259 ) ;
goto V_269;
}
F_98 ( V_101 ) ;
V_2 = F_99 ( & V_271 , sizeof( struct V_10 ) ) ;
if ( ! V_2 )
goto V_269;
V_2 -> V_247 = V_101 -> V_247 ;
V_2 -> V_257 = V_257 ;
V_2 -> V_272 = 16 ;
V_2 -> V_273 = 1 ;
if ( V_248 == V_274 )
F_90 () ;
V_40 = (struct V_10 * ) V_2 -> V_12 ;
V_40 -> V_275 = F_100 ( V_101 , 0 ) ;
V_40 -> V_89 = V_2 ;
V_40 -> V_101 = V_101 ;
V_40 -> V_15 = V_271 . V_15 ;
V_40 -> V_189 = V_2 -> V_257 ;
V_40 -> V_14 = V_252 ;
F_101 ( & V_40 -> V_34 ) ;
V_40 -> V_116 = F_102 ( sizeof( struct V_106 ) * ( V_2 -> V_71 + V_115 ) , V_276 ) ;
if ( ! V_40 -> V_116 )
goto V_277;
F_103 ( & V_40 -> V_278 ) ;
F_104 ( & V_40 -> V_239 ) ;
V_40 -> V_279 = V_280 ;
if ( ( * V_13 [ V_252 ] . V_281 ) ( V_40 ) )
goto V_282;
if ( V_40 -> V_283 ) {
if ( V_260 )
F_105 ( V_284 L_37
L_38
L_39 ,
V_40 -> V_15 ,
V_40 -> V_189 ) ;
else
F_105 ( V_284 L_40
L_41
L_42 ,
V_40 -> V_15 ,
V_40 -> V_189 ) ;
}
V_40 -> V_244 = F_106 ( V_285 , V_40 , V_112 ) ;
if ( F_107 ( V_40 -> V_244 ) ) {
F_105 ( V_286 L_43 ) ;
error = F_108 ( V_40 -> V_244 ) ;
V_40 -> V_244 = NULL ;
goto V_287;
}
V_40 -> V_288 = V_13 [ V_252 ] . V_289 ;
error = F_109 ( V_40 ) ;
if ( error < 0 )
goto V_287;
if ( ( V_13 [ V_252 ] . V_267 & V_290 ) &&
( V_2 -> V_291 > 34 ) ) {
V_2 -> V_291 = 34 ;
V_2 -> V_292 = ( V_2 -> V_291 * 8 ) + 112 ;
}
if ( ( V_13 [ V_252 ] . V_267 & V_293 ) &&
( V_2 -> V_291 > 17 ) ) {
V_2 -> V_291 = 17 ;
V_2 -> V_292 = ( V_2 -> V_291 * 8 ) + 112 ;
}
error = F_110 ( V_101 ,
( V_40 -> V_219 . V_294 & V_295 ) ?
( V_2 -> V_292 << 9 ) : 65536 ) ;
if ( error )
goto V_287;
if ( V_13 [ V_252 ] . V_267 & V_290 )
V_40 -> V_296 = 1 ;
else
V_40 -> V_296 = 0 ;
if ( V_40 -> V_297 || V_61 || V_40 -> V_55 )
V_2 -> V_229 = V_40 -> V_288 ;
else
V_2 -> V_229 = 0 ;
F_111 ( V_40 , 0 ) ;
F_112 ( V_40 ) ;
F_113 ( & V_40 -> V_34 , V_255 ) ;
V_2 -> V_230 = V_40 -> V_68 ;
if ( V_2 -> V_230 < V_40 -> V_298 )
V_2 -> V_230 = V_40 -> V_298 ;
if ( V_2 -> V_230 < V_299 )
V_2 -> V_230 = V_299 ;
else
V_2 -> V_300 = V_2 -> V_230 ;
if ( ! V_40 -> V_49 && V_13 [ V_252 ] . V_267 & V_268 )
F_114 ( V_40 , 0 , 2 , 0 , NULL ) ;
V_2 -> V_301 = V_302 ;
F_115 ( V_101 , V_2 ) ;
error = F_116 ( V_2 , & V_101 -> V_11 ) ;
if ( error )
goto V_287;
F_117 ( V_2 ) ;
F_118 ( V_101 ) ;
F_119 ( V_101 ) ;
return 0 ;
V_287:
F_80 ( V_40 ) ;
V_282:
F_120 ( V_40 ) ;
if ( V_40 -> V_303 )
F_121 ( & V_40 -> V_101 -> V_11 , V_40 -> V_304 ,
V_40 -> V_303 , V_40 -> V_305 ) ;
F_10 ( V_40 -> V_306 ) ;
F_122 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_116 ) ;
F_10 ( V_40 -> V_69 ) ;
V_277:
F_123 ( V_2 ) ;
V_269:
F_124 ( V_101 ) ;
V_266:
return error ;
}
static void F_125 ( struct V_10 * V_40 )
{
F_84 ( V_40 ) ;
F_126 ( V_40 ) ;
}
static int F_127 ( struct V_10 * V_11 )
{
unsigned long V_109 ;
while ( ! ( ( V_109 = F_128 ( V_11 , V_307 . V_308 ) ) & V_309 )
|| V_109 == 0xffffffff )
F_38 ( 20 ) ;
F_84 ( V_11 ) ;
F_129 ( V_11 ) ;
if ( F_85 ( V_11 ) )
F_130 ( V_11 ) ;
if ( V_11 -> V_310 )
F_131 ( V_11 , V_311 ) ;
if ( F_132 ( V_11 ) )
goto V_312;
F_129 ( V_11 ) ;
F_133 ( V_11 ) ;
if ( ! V_11 -> V_283 ) {
V_11 -> V_281 -> V_313 . V_314 = F_36 ( V_11 -> V_245 ) ;
F_134 ( V_11 ) ;
}
return 0 ;
V_312:
return - 1 ;
}
static int F_135 ( struct V_250 * V_101 , T_9 V_315 )
{
struct V_1 * V_2 = F_136 ( V_101 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_137 ( V_2 ) ;
F_83 ( V_40 ) ;
F_125 ( V_40 ) ;
F_115 ( V_101 , V_2 ) ;
F_119 ( V_101 ) ;
F_124 ( V_101 ) ;
F_138 ( V_101 , F_139 ( V_101 , V_315 ) ) ;
return 0 ;
}
static int F_140 ( struct V_250 * V_101 )
{
struct V_1 * V_2 = F_136 ( V_101 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
int V_5 ;
F_138 ( V_101 , V_316 ) ;
F_141 ( V_101 , V_316 , 0 ) ;
F_142 ( V_101 ) ;
V_5 = F_94 ( V_101 ) ;
if ( V_5 )
goto V_317;
F_98 ( V_101 ) ;
if ( F_127 ( V_40 ) )
goto V_317;
V_40 -> V_240 = 0 ;
F_143 ( V_2 ) ;
return 0 ;
V_317:
F_105 ( V_284 L_44 , V_40 -> V_15 , V_40 -> V_189 ) ;
F_123 ( V_2 ) ;
F_124 ( V_101 ) ;
return - V_187 ;
}
static void F_144 ( struct V_250 * V_11 )
{
struct V_1 * V_2 = F_136 ( V_11 ) ;
F_137 ( V_2 ) ;
F_80 ( (struct V_10 * ) V_2 -> V_12 ) ;
}
static void F_145 ( struct V_250 * V_101 )
{
struct V_1 * V_2 = F_136 ( V_101 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_146 ( V_2 ) ;
F_80 ( V_40 ) ;
F_120 ( V_40 ) ;
F_121 ( & V_40 -> V_101 -> V_11 , V_40 -> V_304 , V_40 -> V_303 ,
V_40 -> V_305 ) ;
F_10 ( V_40 -> V_306 ) ;
F_122 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_116 ) ;
F_10 ( V_40 -> V_69 ) ;
F_147 ( & V_40 -> V_34 ) ;
F_123 ( V_2 ) ;
F_124 ( V_101 ) ;
if ( F_148 ( & V_256 ) ) {
F_149 ( V_248 , L_33 ) ;
V_248 = V_274 ;
}
}
static void F_150 ( struct V_10 * V_40 )
{
int V_238 ;
struct V_3 * V_4 ;
for ( V_238 = 0 ; V_238 < V_40 -> V_89 -> V_71 ; V_238 ++ ) {
V_4 = (struct V_3 * ) V_40 -> V_116 [ V_238 ] . V_119 ;
if ( V_4 && ( V_4 -> V_6 . V_7 == V_98 ) ) {
F_151 ( V_4 ) ;
if ( V_40 -> V_318 )
V_4 -> V_319 = V_320 << 16 ;
else
V_4 -> V_319 = V_321 << 16 ;
V_4 -> V_322 ( V_4 ) ;
}
}
}
static T_10 F_152 ( struct V_250 * V_101 ,
enum V_323 error )
{
struct V_1 * V_2 = F_136 ( V_101 ) ;
struct V_10 * V_40 = F_153 ( V_2 ) ;
F_48 ( & V_101 -> V_11 , L_45 , error ) ;
switch ( error ) {
case V_324 :
return V_325 ;
case V_326 :
V_40 -> V_318 = 1 ;
F_137 ( V_40 -> V_89 ) ;
F_150 ( V_40 ) ;
F_125 ( V_40 ) ;
F_154 ( V_101 ) ;
F_122 ( V_40 , 0 ) ;
return V_327 ;
case V_328 :
V_40 -> V_318 = 1 ;
F_150 ( V_40 ) ;
return V_329 ;
}
return V_327 ;
}
static T_10 F_155 ( struct V_250 * V_101 )
{
F_48 ( & V_101 -> V_11 , L_46 ) ;
return V_327 ;
}
static T_10 F_156 ( struct V_250 * V_101 )
{
F_48 ( & V_101 -> V_11 , L_47 ) ;
F_142 ( V_101 ) ;
if ( F_94 ( V_101 ) ) {
F_157 ( & V_101 -> V_11 ,
L_48 ) ;
goto V_317;
}
F_98 ( V_101 ) ;
if ( F_158 ( V_101 ) ) {
F_48 ( & V_101 -> V_11 , L_49 ) ;
goto V_317;
}
return V_330 ;
V_317:
F_48 ( & V_101 -> V_11 , L_50 ) ;
return V_329 ;
}
static void F_159 ( struct V_250 * V_101 )
{
struct V_1 * V_2 = F_136 ( V_101 ) ;
struct V_18 * V_19 = NULL ;
struct V_10 * V_40 = (struct V_10 * ) F_153 ( V_2 ) ;
F_160 ( V_101 ) ;
if ( F_122 ( V_40 , V_40 -> V_279 ) ) {
F_48 ( & V_101 -> V_11 , L_51 ) ;
V_40 -> V_331 = V_332 ;
if ( F_122 ( V_40 , V_280 ) ) {
F_157 ( & V_101 -> V_11 ,
L_52 ) ;
return;
}
}
F_38 ( 10000 ) ;
F_127 ( V_40 ) ;
V_40 -> V_240 = 0 ;
V_40 -> V_318 = 0 ;
F_161 (sdev, shost)
if ( V_19 -> V_333 == V_334 )
V_19 -> V_333 = V_335 ;
F_143 ( V_40 -> V_89 ) ;
F_117 ( V_40 -> V_89 ) ;
F_119 ( V_101 ) ;
F_48 ( & V_101 -> V_11 , L_53 ) ;
}
static int T_11 F_162 ( void )
{
int error ;
F_105 ( V_284 L_54 ,
V_112 , V_226 ) ;
error = F_163 ( & V_336 ) ;
if ( error < 0 )
return error ;
F_90 () ;
return 0 ;
}
static void T_12 F_164 ( void )
{
if ( V_248 > - 1 )
F_149 ( V_248 , L_33 ) ;
F_165 ( & V_336 ) ;
}
