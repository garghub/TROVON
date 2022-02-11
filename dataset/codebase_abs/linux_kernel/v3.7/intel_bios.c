static void * F_1 ( struct V_1 * V_2 , int V_3 )
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
static void
F_2 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_17 ;
T_3 V_18 ;
V_14 = F_1 ( V_2 , V_19 ) ;
V_12 -> V_14 . V_20 = 18 ;
if ( ! V_14 ) {
if ( V_12 -> V_14 . V_21 ) {
F_3 ( L_1 ,
V_12 -> V_14 . V_20 ) ;
}
return;
}
V_18 = V_12 -> V_18 ;
switch ( ( V_14 -> V_22 >> ( V_18 * 2 ) ) & 3 ) {
case V_23 :
V_12 -> V_14 . V_20 = 18 ;
break;
case V_24 :
V_12 -> V_14 . V_20 = 24 ;
break;
case V_25 :
V_12 -> V_14 . V_20 = 30 ;
break;
}
V_16 = & V_14 -> V_26 [ V_18 ] ;
V_17 = & V_14 -> V_27 [ V_18 ] ;
V_12 -> V_14 . V_28 = * V_16 ;
F_3 ( L_2 ,
V_12 -> V_14 . V_28 . V_29 , V_12 -> V_14 . V_28 . V_30 ,
V_12 -> V_14 . V_28 . V_31 , V_12 -> V_14 . V_28 . V_32 ,
V_12 -> V_14 . V_28 . V_33 ) ;
V_12 -> V_14 . V_34 = V_17 -> V_34 ? V_35 :
V_36 ;
switch ( V_17 -> V_37 ) {
case 0 :
V_12 -> V_14 . V_37 = 1 ;
break;
case 1 :
V_12 -> V_14 . V_37 = 2 ;
break;
case 3 :
default:
V_12 -> V_14 . V_37 = 4 ;
break;
}
F_3 ( L_3 ,
V_12 -> V_14 . V_37 , V_12 -> V_14 . V_34 , V_12 -> V_14 . V_20 ) ;
switch ( V_17 -> V_38 ) {
case 0 :
V_12 -> V_14 . V_38 = V_39 ;
break;
case 1 :
V_12 -> V_14 . V_38 = V_40 ;
break;
case 2 :
V_12 -> V_14 . V_38 = V_41 ;
break;
case 3 :
V_12 -> V_14 . V_38 = V_42 ;
break;
}
switch ( V_17 -> V_43 ) {
case 0 :
V_12 -> V_14 . V_43 = V_44 ;
break;
case 1 :
V_12 -> V_14 . V_43 = V_45 ;
break;
case 2 :
V_12 -> V_14 . V_43 = V_46 ;
break;
case 3 :
V_12 -> V_14 . V_43 = V_47 ;
break;
}
F_3 ( L_4 ,
V_12 -> V_14 . V_43 , V_12 -> V_14 . V_38 ) ;
}
static T_2
F_4 ( void * V_48 )
{
T_2 * V_49 , V_50 ;
V_49 = ( T_2 * ) ( ( char * ) V_48 - 2 ) ;
V_50 = * V_49 ;
return V_50 ;
}
static void F_5 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
V_52 -> V_55 = ( V_54 -> V_56 << 8 ) |
V_54 -> V_57 ;
V_52 -> V_58 = V_52 -> V_55 +
( ( V_54 -> V_59 << 8 ) | V_54 -> V_60 ) ;
V_52 -> V_61 = V_52 -> V_58 +
V_54 -> V_62 ;
V_52 -> V_63 = V_52 -> V_55 +
( ( V_54 -> V_64 << 8 ) | V_54 -> V_65 ) ;
V_52 -> V_66 = ( V_54 -> V_67 << 8 ) |
V_54 -> V_68 ;
V_52 -> V_69 = V_52 -> V_66 +
V_54 -> V_70 ;
V_52 -> V_71 = V_52 -> V_69 +
V_54 -> V_72 ;
V_52 -> V_73 = V_52 -> V_66 +
( ( V_54 -> V_74 << 8 ) | V_54 -> V_75 ) ;
V_52 -> clock = V_54 -> clock * 10 ;
V_52 -> type = V_76 ;
if ( V_54 -> V_77 )
V_52 -> V_78 |= V_79 ;
else
V_52 -> V_78 |= V_80 ;
if ( V_54 -> V_81 )
V_52 -> V_78 |= V_82 ;
else
V_52 -> V_78 |= V_83 ;
if ( V_52 -> V_61 > V_52 -> V_63 )
V_52 -> V_63 = V_52 -> V_61 + 1 ;
if ( V_52 -> V_71 > V_52 -> V_73 )
V_52 -> V_73 = V_52 -> V_71 + 1 ;
F_6 ( V_52 ) ;
}
static void F_7 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_84 * V_85 = NULL ;
struct V_84 * V_86 ;
T_1 V_87 = 0 ;
void * V_88 = NULL ;
struct V_89 * V_90
= F_1 ( V_2 , V_91 ) ;
V_12 -> V_86 = NULL ;
if ( V_90 )
V_87 = V_90 -> V_18 ;
else
return;
V_88 = F_1 ( V_2 , V_92 ) ;
V_85 = (struct V_84 * ) ( V_88 + 1 ) + V_87 ;
V_86 = F_8 ( sizeof( * V_85 ) , V_93 ) ;
if ( ! V_86 ) {
F_9 ( V_12 -> V_94 -> V_94 , L_5 ) ;
return;
}
memcpy ( V_86 , V_85 , sizeof( * V_85 ) ) ;
V_12 -> V_86 = V_86 ;
}
static void F_10 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_89 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_53 * V_54 ;
struct V_51 * V_52 ;
V_12 -> V_100 = 0 ;
V_12 -> V_101 = 0 ;
V_95 = F_1 ( V_2 , V_91 ) ;
if ( ! V_95 )
return;
V_12 -> V_100 = V_95 -> V_102 ;
V_12 -> V_18 = V_95 -> V_18 ;
if ( V_95 -> V_18 == 0xff )
return;
V_97 = F_1 ( V_2 , V_103 ) ;
if ( ! V_97 )
return;
V_99 = & V_97 -> V_104 [ V_95 -> V_18 ] ;
V_54 = & V_99 -> V_54 ;
V_52 = F_8 ( sizeof( * V_52 ) ,
V_93 ) ;
if ( V_52 == NULL ) {
F_9 ( V_12 -> V_94 -> V_94 , L_6 ) ;
return;
}
V_12 -> V_101 = 1 ;
F_5 ( V_52 , V_54 ) ;
if ( V_52 -> V_63 > 0 && V_52 -> V_73 > 0 ) {
V_12 -> V_105 = V_52 ;
F_11 ( V_52 ) ;
} else {
F_12 ( V_12 -> V_94 -> V_94 , L_7 ) ;
V_12 -> V_101 = 0 ;
F_13 ( V_52 ) ;
}
return;
}
static void F_14 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_106 * V_107 ;
struct V_53 * V_54 ;
struct V_51 * V_52 ;
V_12 -> V_108 = NULL ;
V_107 = F_1 ( V_2 , V_109 ) ;
if ( ! V_107 )
return;
V_54 = F_1 ( V_2 , V_110 ) ;
if ( ! V_54 )
return;
V_52 = F_8 ( sizeof( * V_52 ) , V_93 ) ;
if ( ! V_52 )
return;
F_5 ( V_52 ,
V_54 + V_107 -> V_18 ) ;
V_12 -> V_108 = V_52 ;
return;
}
static void F_15 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_111 * V_112 ;
V_12 -> V_113 = 1 ;
V_12 -> V_114 = 1 ;
V_112 = F_1 ( V_2 , V_115 ) ;
if ( V_112 ) {
V_12 -> V_113 = V_112 -> V_113 ;
V_12 -> V_114 = V_112 -> V_114 ;
V_12 -> V_116 = V_112 -> V_117 ;
if ( V_12 -> V_116 ) {
V_12 -> V_118
= V_112 -> V_119 ? 100 : 96 ;
}
}
}
static void
F_16 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
int V_126 , V_127 , V_128 ;
T_2 V_50 ;
V_123 = F_1 ( V_2 , V_129 ) ;
if ( ! V_123 ) {
F_3 ( L_8 ) ;
return;
}
if ( V_123 -> V_130 != sizeof( * V_125 ) ) {
F_3 ( L_9 ) ;
return;
}
V_50 = F_4 ( V_123 ) ;
V_127 = ( V_50 - sizeof( * V_123 ) ) /
sizeof( * V_125 ) ;
V_128 = 0 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
V_125 = & ( V_123 -> V_131 [ V_126 ] ) ;
if ( ! V_125 -> V_132 ) {
continue;
}
if ( V_125 -> V_133 != V_134 &&
V_125 -> V_133 != V_135 ) {
continue;
}
if ( V_125 -> V_136 != V_137 &&
V_125 -> V_136 != V_138 ) {
F_3 ( L_10 ) ;
continue;
}
F_3 ( L_11
L_12 ,
V_125 -> V_133 ,
( V_125 -> V_136 == V_137 ) ?
L_13 : L_14 ) ;
V_121 = & ( V_12 -> V_139 [ V_125 -> V_136 - 1 ] ) ;
if ( ! V_121 -> V_140 ) {
V_121 -> V_136 = V_125 -> V_136 ;
V_121 -> V_133 = V_125 -> V_133 ;
V_121 -> V_141 = V_125 -> V_141 ;
V_121 -> V_142 = V_125 -> V_142 ;
V_121 -> V_143 = V_125 -> V_143 ;
V_121 -> V_140 = 1 ;
F_3 ( L_15 ,
V_121 -> V_136 ,
V_121 -> V_133 ,
V_121 -> V_141 ,
V_121 -> V_142 ,
V_121 -> V_143 ) ;
} else {
F_3 ( L_16
L_17 ) ;
}
if ( V_125 -> V_144 ) {
F_3 ( L_18
L_19 ) ;
}
V_128 ++ ;
}
if ( ! V_128 ) {
F_3 ( L_20 ) ;
}
return;
}
static void
F_17 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_145 * V_146 ;
V_146 = F_1 ( V_2 , V_147 ) ;
if ( ! V_146 )
return;
if ( V_146 -> V_148 == V_149 )
V_12 -> V_14 . V_21 = 1 ;
if ( V_146 -> V_150 )
V_12 -> V_151 = true ;
else
V_12 -> V_151 = false ;
}
static void
F_18 ( struct V_11 * V_12 ,
struct V_1 * V_2 )
{
struct V_122 * V_123 ;
struct V_124 * V_125 , * V_152 ;
int V_126 , V_127 , V_128 ;
T_2 V_50 ;
V_123 = F_1 ( V_2 , V_129 ) ;
if ( ! V_123 ) {
F_3 ( L_21 ) ;
return;
}
if ( V_123 -> V_130 != sizeof( * V_125 ) ) {
F_3 ( L_9 ) ;
return;
}
V_50 = F_4 ( V_123 ) ;
V_127 = ( V_50 - sizeof( * V_123 ) ) /
sizeof( * V_125 ) ;
V_128 = 0 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
V_125 = & ( V_123 -> V_131 [ V_126 ] ) ;
if ( ! V_125 -> V_132 ) {
continue;
}
V_128 ++ ;
}
if ( ! V_128 ) {
F_3 ( L_22 ) ;
return;
}
V_12 -> V_153 = F_19 ( V_128 , sizeof( * V_125 ) , V_93 ) ;
if ( ! V_12 -> V_153 ) {
F_3 ( L_23 ) ;
return;
}
V_12 -> V_154 = V_128 ;
V_128 = 0 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
V_125 = & ( V_123 -> V_131 [ V_126 ] ) ;
if ( ! V_125 -> V_132 ) {
continue;
}
V_152 = V_12 -> V_153 + V_128 ;
V_128 ++ ;
memcpy ( ( void * ) V_152 , ( void * ) V_125 ,
sizeof( * V_125 ) ) ;
}
return;
}
int F_20 ( struct V_155 * V_94 )
{
struct V_11 * V_12 = V_94 -> V_156 ;
struct V_157 * V_158 = V_94 -> V_158 ;
struct V_159 * V_160 = NULL ;
struct V_1 * V_2 = NULL ;
T_1 T_4 * V_161 = NULL ;
T_5 V_162 ;
int V_126 ;
V_12 -> V_18 = 0xff ;
if ( V_12 -> V_163 . V_160 ) {
struct V_159 * V_160 = V_12 -> V_163 . V_160 ;
if ( memcmp ( V_160 -> V_164 , L_24 , 4 ) == 0 ) {
F_3 ( L_25 ,
V_160 -> V_164 ) ;
V_2 = (struct V_1 * ) ( ( char * ) V_160 + V_160 -> V_165 ) ;
} else
V_12 -> V_163 . V_160 = NULL ;
}
if ( V_2 == NULL ) {
V_161 = F_21 ( V_158 , & V_162 ) ;
if ( ! V_161 )
return - 1 ;
for ( V_126 = 0 ; V_126 + 4 < V_162 ; V_126 ++ ) {
if ( ! memcmp ( V_161 + V_126 , L_24 , 4 ) ) {
V_160 = (struct V_159 * ) ( V_161 + V_126 ) ;
break;
}
}
if ( ! V_160 ) {
F_9 ( V_94 -> V_94 , L_26 ) ;
F_22 ( V_158 , V_161 ) ;
return - 1 ;
}
V_2 = (struct V_1 * ) ( V_161 + V_126 + V_160 -> V_165 ) ;
}
F_15 ( V_12 , V_2 ) ;
F_17 ( V_12 , V_2 ) ;
F_10 ( V_12 , V_2 ) ;
F_14 ( V_12 , V_2 ) ;
F_16 ( V_12 , V_2 ) ;
F_18 ( V_12 , V_2 ) ;
F_7 ( V_12 , V_2 ) ;
F_2 ( V_12 , V_2 ) ;
if ( V_161 )
F_22 ( V_158 , V_161 ) ;
return 0 ;
}
void F_23 ( struct V_155 * V_94 )
{
struct V_11 * V_12 = V_94 -> V_156 ;
F_13 ( V_12 -> V_108 ) ;
F_13 ( V_12 -> V_105 ) ;
F_13 ( V_12 -> V_86 ) ;
}
