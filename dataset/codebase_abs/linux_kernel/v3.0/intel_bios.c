static void *
F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 * V_4 = ( T_1 * ) V_2 ;
int V_5 = 0 ;
T_2 V_6 , V_7 ;
T_1 V_8 ;
V_5 += V_2 -> V_9 ;
V_6 = V_2 -> V_10 ;
while ( V_5 < V_6 ) {
V_8 = * ( V_4 + V_5 ) ;
V_5 ++ ;
V_7 = * ( ( T_2 * ) ( V_4 + V_5 ) ) ;
V_5 += 2 ;
if ( V_8 == V_3 )
return V_4 + V_5 ;
V_5 += V_7 ;
}
return NULL ;
}
static T_2
F_2 ( void * V_11 )
{
T_2 * V_12 , V_13 ;
V_12 = ( T_2 * ) ( ( char * ) V_11 - 2 ) ;
V_13 = * V_12 ;
return V_13 ;
}
static void
F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
V_15 -> V_18 = ( V_17 -> V_19 << 8 ) |
V_17 -> V_20 ;
V_15 -> V_21 = V_15 -> V_18 +
( ( V_17 -> V_22 << 8 ) | V_17 -> V_23 ) ;
V_15 -> V_24 = V_15 -> V_21 +
V_17 -> V_25 ;
V_15 -> V_26 = V_15 -> V_18 +
( ( V_17 -> V_27 << 8 ) | V_17 -> V_28 ) ;
V_15 -> V_29 = ( V_17 -> V_30 << 8 ) |
V_17 -> V_31 ;
V_15 -> V_32 = V_15 -> V_29 +
V_17 -> V_33 ;
V_15 -> V_34 = V_15 -> V_32 +
V_17 -> V_35 ;
V_15 -> V_36 = V_15 -> V_29 +
( ( V_17 -> V_37 << 8 ) | V_17 -> V_38 ) ;
V_15 -> clock = V_17 -> clock * 10 ;
V_15 -> type = V_39 ;
if ( V_17 -> V_40 )
V_15 -> V_41 |= V_42 ;
else
V_15 -> V_41 |= V_43 ;
if ( V_17 -> V_44 )
V_15 -> V_41 |= V_45 ;
else
V_15 -> V_41 |= V_46 ;
if ( V_15 -> V_24 > V_15 -> V_26 )
V_15 -> V_26 = V_15 -> V_24 + 1 ;
if ( V_15 -> V_34 > V_15 -> V_36 )
V_15 -> V_36 = V_15 -> V_34 + 1 ;
F_4 ( V_15 ) ;
}
static void
F_5 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
int V_57 , V_58 ;
int V_59 , V_60 ;
struct V_14 * V_61 ;
V_50 = F_1 ( V_2 , V_62 ) ;
if ( ! V_50 )
return;
V_48 -> V_63 = V_50 -> V_64 ;
if ( V_50 -> V_65 == 0xff )
return;
V_65 = V_50 -> V_65 ;
V_52 = F_1 ( V_2 , V_66 ) ;
if ( ! V_52 )
return;
V_54 = F_1 ( V_2 , V_67 ) ;
if ( ! V_54 )
return;
V_48 -> V_68 = 1 ;
V_57 = V_54 -> V_69 [ 1 ] . V_58 -
V_54 -> V_69 [ 0 ] . V_58 ;
V_56 = (struct V_55 * )
( ( V_70 * ) V_52 -> V_71 + ( V_57 *
V_50 -> V_65 ) ) ;
V_58 = V_54 -> V_69 [ 0 ] . V_58 -
V_54 -> V_69 [ 0 ] . V_72 ;
V_17 = (struct V_16 * )
( ( unsigned char * ) V_56 + V_58 ) ;
V_15 = F_6 ( sizeof( * V_15 ) , V_73 ) ;
if ( ! V_15 )
return;
F_3 ( V_15 , V_17 ) ;
V_48 -> V_74 = V_15 ;
F_7 ( L_1 ) ;
F_8 ( V_15 ) ;
V_61 = F_6 ( sizeof( * V_61 ) , V_73 ) ;
V_60 = V_15 -> clock ;
for ( V_59 = 0 ; V_59 < 16 ; V_59 ++ ) {
V_56 = (struct V_55 * )
( ( V_70 * ) V_52 -> V_71 + ( V_57 * V_59 ) ) ;
V_17 = (struct V_16 * )
( ( unsigned char * ) V_56 + V_58 ) ;
F_3 ( V_61 , V_17 ) ;
if ( V_61 -> V_18 == V_15 -> V_18 &&
V_61 -> V_21 == V_15 -> V_21 &&
V_61 -> V_24 == V_15 -> V_24 &&
V_61 -> V_26 == V_15 -> V_26 &&
V_61 -> V_29 == V_15 -> V_29 &&
V_61 -> V_32 == V_15 -> V_32 &&
V_61 -> V_34 == V_15 -> V_34 &&
V_61 -> V_36 == V_15 -> V_36 &&
V_61 -> clock < V_60 ) {
V_60 = V_61 -> clock ;
}
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
}
F_9 ( V_61 ) ;
if ( V_60 < V_15 -> clock &&
V_75 ) {
V_48 -> V_76 = 1 ;
V_48 -> V_77 = V_60 ;
F_7 ( L_2
L_3 ,
V_60 , V_15 -> clock ) ;
}
return;
}
static void
F_10 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_14 * V_15 ;
int V_5 ;
V_5 = V_78 ;
if ( V_5 == - 1 ) {
struct V_79 * V_80 ;
V_80 = F_1 ( V_2 , V_81 ) ;
if ( ! V_80 )
return;
V_5 = V_80 -> V_65 ;
}
V_17 = F_1 ( V_2 , V_82 ) ;
if ( ! V_17 )
return;
V_15 = F_6 ( sizeof( * V_15 ) , V_73 ) ;
if ( ! V_15 )
return;
F_3 ( V_15 , V_17 + V_5 ) ;
V_48 -> V_83 = V_15 ;
F_7 ( L_4 ) ;
F_8 ( V_15 ) ;
}
static int F_11 ( struct V_84 * V_85 ,
bool V_86 )
{
switch ( F_12 ( V_85 ) -> V_87 ) {
case 2 :
return V_86 ? 66 : 48 ;
case 3 :
case 4 :
return V_86 ? 100 : 96 ;
default:
return V_86 ? 100 : 120 ;
}
}
static void
F_13 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 = V_48 -> V_85 ;
struct V_88 * V_89 ;
V_89 = F_1 ( V_2 , V_90 ) ;
if ( V_89 ) {
V_48 -> V_91 = V_89 -> V_91 ;
V_48 -> V_92 = V_89 -> V_92 ;
V_48 -> V_93 = V_89 -> V_94 ;
V_48 -> V_95 =
F_11 ( V_85 , V_89 -> V_96 ) ;
}
}
static void
F_14 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_97 * V_89 ;
V_89 = F_1 ( V_2 , V_98 ) ;
if ( V_89 ) {
T_2 V_13 = F_2 ( V_89 ) ;
if ( V_13 >= sizeof( * V_89 ) ) {
int V_99 = V_89 -> V_100 ;
F_7 ( L_5 , V_99 ) ;
if ( V_99 >= 1 && V_99 <= 6 )
V_48 -> V_101 = V_99 ;
} else {
F_7 ( L_6 ,
V_13 ) ;
}
}
}
static void
F_15 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_102 * V_103 ;
struct V_97 * V_104 ;
struct V_105 * V_106 ;
int V_59 , V_107 , V_108 ;
T_2 V_13 ;
V_104 = F_1 ( V_2 , V_98 ) ;
if ( ! V_104 ) {
F_7 ( L_7 ) ;
return;
}
if ( V_104 -> V_109 != sizeof( * V_106 ) ) {
F_7 ( L_8 ) ;
return;
}
V_13 = F_2 ( V_104 ) ;
V_107 = ( V_13 - sizeof( * V_104 ) ) /
sizeof( * V_106 ) ;
V_108 = 0 ;
for ( V_59 = 0 ; V_59 < V_107 ; V_59 ++ ) {
V_106 = & ( V_104 -> V_110 [ V_59 ] ) ;
if ( ! V_106 -> V_111 ) {
continue;
}
if ( V_106 -> V_112 != V_113 &&
V_106 -> V_112 != V_114 ) {
continue;
}
if ( V_106 -> V_115 != V_116 &&
V_106 -> V_115 != V_117 ) {
F_7 ( L_9 ) ;
continue;
}
F_7 ( L_10
L_11 ,
V_106 -> V_112 ,
( V_106 -> V_115 == V_116 ) ?
L_12 : L_13 ) ;
V_103 = & ( V_48 -> V_118 [ V_106 -> V_115 - 1 ] ) ;
if ( ! V_103 -> V_119 ) {
V_103 -> V_115 = V_106 -> V_115 ;
V_103 -> V_112 = V_106 -> V_112 ;
V_103 -> V_120 = V_106 -> V_120 ;
V_103 -> V_121 = V_106 -> V_121 ;
V_103 -> V_122 = V_106 -> V_122 ;
V_103 -> V_123 = V_106 -> V_123 ;
V_103 -> V_119 = 1 ;
F_7 ( L_14 ,
V_103 -> V_115 ,
V_103 -> V_112 ,
V_103 -> V_120 ,
V_103 -> V_121 ,
V_103 -> V_122 ,
V_103 -> V_123 ) ;
} else {
F_7 ( L_15
L_16 ) ;
}
if ( V_106 -> V_124 ) {
F_7 ( L_17
L_18 ) ;
}
V_108 ++ ;
}
if ( ! V_108 ) {
F_7 ( L_19 ) ;
}
return;
}
static void
F_16 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 = V_48 -> V_85 ;
struct V_125 * V_126 ;
V_126 = F_1 ( V_2 , V_127 ) ;
if ( ! V_126 )
return;
if ( F_17 ( V_85 ) &&
V_126 -> V_128 == V_129 )
V_48 -> V_130 . V_131 = 1 ;
if ( V_126 -> V_132 )
V_48 -> V_133 = true ;
}
static void
F_18 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
struct V_134 * V_130 ;
struct V_135 * V_136 ;
struct V_137 * V_137 ;
V_130 = F_1 ( V_2 , V_138 ) ;
if ( ! V_130 ) {
if ( F_17 ( V_48 -> V_85 ) && V_48 -> V_130 . V_131 ) {
F_7 ( L_20
L_21
L_22 ,
V_48 -> V_130 . V_139 ) ;
}
return;
}
switch ( ( V_130 -> V_140 >> ( V_65 * 2 ) ) & 3 ) {
case V_141 :
V_48 -> V_130 . V_139 = 18 ;
break;
case V_142 :
V_48 -> V_130 . V_139 = 24 ;
break;
case V_143 :
V_48 -> V_130 . V_139 = 30 ;
break;
}
V_136 = & V_130 -> V_144 [ V_65 ] ;
V_137 = & V_130 -> V_145 [ V_65 ] ;
V_48 -> V_130 . V_146 = * V_136 ;
V_48 -> V_130 . V_147 = V_137 -> V_147 ? V_148 :
V_149 ;
switch ( V_137 -> V_150 ) {
case 0 :
V_48 -> V_130 . V_150 = 1 ;
break;
case 1 :
V_48 -> V_130 . V_150 = 2 ;
break;
case 3 :
default:
V_48 -> V_130 . V_150 = 4 ;
break;
}
switch ( V_137 -> V_151 ) {
case 0 :
V_48 -> V_130 . V_151 = V_152 ;
break;
case 1 :
V_48 -> V_130 . V_151 = V_153 ;
break;
case 2 :
V_48 -> V_130 . V_151 = V_154 ;
break;
case 3 :
V_48 -> V_130 . V_151 = V_155 ;
break;
}
switch ( V_137 -> V_156 ) {
case 0 :
V_48 -> V_130 . V_156 = V_157 ;
break;
case 1 :
V_48 -> V_130 . V_156 = V_158 ;
break;
case 2 :
V_48 -> V_130 . V_156 = V_159 ;
break;
case 3 :
V_48 -> V_130 . V_156 = V_160 ;
break;
}
}
static void
F_19 ( struct V_47 * V_48 ,
struct V_1 * V_2 )
{
struct V_97 * V_104 ;
struct V_105 * V_106 , * V_161 ;
int V_59 , V_107 , V_108 ;
T_2 V_13 ;
V_104 = F_1 ( V_2 , V_98 ) ;
if ( ! V_104 ) {
F_7 ( L_23 ) ;
return;
}
if ( V_104 -> V_109 != sizeof( * V_106 ) ) {
F_7 ( L_8 ) ;
return;
}
V_13 = F_2 ( V_104 ) ;
V_107 = ( V_13 - sizeof( * V_104 ) ) /
sizeof( * V_106 ) ;
V_108 = 0 ;
for ( V_59 = 0 ; V_59 < V_107 ; V_59 ++ ) {
V_106 = & ( V_104 -> V_110 [ V_59 ] ) ;
if ( ! V_106 -> V_111 ) {
continue;
}
V_108 ++ ;
}
if ( ! V_108 ) {
F_7 ( L_24 ) ;
return;
}
V_48 -> V_162 = F_6 ( sizeof( * V_106 ) * V_108 , V_73 ) ;
if ( ! V_48 -> V_162 ) {
F_7 ( L_25 ) ;
return;
}
V_48 -> V_163 = V_108 ;
V_108 = 0 ;
for ( V_59 = 0 ; V_59 < V_107 ; V_59 ++ ) {
V_106 = & ( V_104 -> V_110 [ V_59 ] ) ;
if ( ! V_106 -> V_111 ) {
continue;
}
V_161 = V_48 -> V_162 + V_108 ;
V_108 ++ ;
memcpy ( ( void * ) V_161 , ( void * ) V_106 ,
sizeof( * V_106 ) ) ;
}
return;
}
static void
F_20 ( struct V_47 * V_48 )
{
struct V_84 * V_85 = V_48 -> V_85 ;
V_48 -> V_101 = V_164 ;
V_48 -> V_63 = 1 ;
V_48 -> V_68 = 0 ;
V_48 -> V_83 = NULL ;
V_48 -> V_91 = 1 ;
V_48 -> V_92 = 1 ;
V_48 -> V_93 = 1 ;
V_48 -> V_95 = F_11 ( V_85 , 1 ) ;
F_21 ( L_26 , V_48 -> V_95 ) ;
V_48 -> V_130 . V_139 = 18 ;
}
bool
F_22 ( struct V_84 * V_85 )
{
struct V_47 * V_48 = V_85 -> V_165 ;
struct V_166 * V_167 = V_85 -> V_167 ;
struct V_1 * V_2 = NULL ;
T_1 T_3 * V_168 = NULL ;
F_20 ( V_48 ) ;
if ( V_48 -> V_169 . V_170 ) {
struct V_171 * V_170 = V_48 -> V_169 . V_170 ;
if ( memcmp ( V_170 -> V_172 , L_27 , 4 ) == 0 ) {
F_23 ( L_28 ,
V_170 -> V_172 ) ;
V_2 = (struct V_1 * ) ( ( char * ) V_170 + V_170 -> V_173 ) ;
} else
V_48 -> V_169 . V_170 = NULL ;
}
if ( V_2 == NULL ) {
struct V_171 * V_170 = NULL ;
T_4 V_174 ;
int V_59 ;
V_168 = F_24 ( V_167 , & V_174 ) ;
if ( ! V_168 )
return - 1 ;
for ( V_59 = 0 ; V_59 + 4 < V_174 ; V_59 ++ ) {
if ( ! memcmp ( V_168 + V_59 , L_27 , 4 ) ) {
V_170 = (struct V_171 * ) ( V_168 + V_59 ) ;
break;
}
}
if ( ! V_170 ) {
F_25 ( L_29 ) ;
F_26 ( V_167 , V_168 ) ;
return - 1 ;
}
V_2 = (struct V_1 * ) ( V_168 + V_59 + V_170 -> V_173 ) ;
}
F_13 ( V_48 , V_2 ) ;
F_14 ( V_48 , V_2 ) ;
F_5 ( V_48 , V_2 ) ;
F_10 ( V_48 , V_2 ) ;
F_15 ( V_48 , V_2 ) ;
F_19 ( V_48 , V_2 ) ;
F_16 ( V_48 , V_2 ) ;
F_18 ( V_48 , V_2 ) ;
if ( V_168 )
F_26 ( V_167 , V_168 ) ;
return 0 ;
}
void F_27 ( struct V_84 * V_85 )
{
struct V_47 * V_48 = V_85 -> V_165 ;
if ( ( F_28 ( V_175 ) == 0 ) && ( F_28 ( V_176 ) == 0 ) ) {
F_29 ( V_175 , 0x019007d0 ) ;
F_29 ( V_176 , 0x015e07d0 ) ;
}
}
