static inline T_1 F_1 ( const struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_2 -> V_3 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_4 , int V_5 ,
T_2 * V_6 , const T_2 * V_7 )
{
T_2 V_8 ;
int V_9 = V_2 -> V_10 ;
int V_11 = V_2 -> V_12 ;
int V_13 = V_5 + V_9 ;
int V_14 = V_4 + V_11 ;
int V_15 ;
V_8 = * V_6 ;
* V_6 = * V_7 ;
if ( V_2 -> V_16 ) {
const T_3 * V_17 = V_2 -> V_16 ;
unsigned V_18 = ( V_2 -> V_19 . V_20 + 7 ) / 8 ;
V_5 -= V_2 -> V_19 . V_9 ;
V_4 -= V_2 -> V_19 . V_11 ;
if ( ! ( V_17 [ V_18 * V_4 + V_5 / 8 ] & ( 1 << ( V_5 & 7 ) ) ) )
return;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_21 ; V_15 ++ ) {
struct V_22 * V_23 = & V_2 -> V_24 [ V_15 ] . V_25 ;
if ( V_14 >= V_23 -> V_11 && V_14 < V_23 -> V_11 + V_23 -> V_26 &&
V_13 >= V_23 -> V_9 && V_13 < V_23 -> V_9 + V_23 -> V_20 )
return;
}
if ( ( V_2 -> V_27 & V_28 ) &&
* V_7 != V_2 -> V_29 )
return;
if ( ( V_2 -> V_27 & V_30 ) &&
V_8 == V_2 -> V_29 )
return;
if ( V_2 -> V_31 -> V_32 ) {
if ( ( V_2 -> V_27 & V_33 ) &&
V_2 -> V_34 )
return;
if ( ( V_2 -> V_27 & V_35 ) &&
* V_6 & V_2 -> V_31 -> V_32 )
return;
if ( ( V_2 -> V_27 & V_36 ) &&
! ( * V_6 & V_2 -> V_31 -> V_32 ) )
return;
}
* V_6 = V_8 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_37 , unsigned V_38 ,
T_3 * V_39 , const T_3 * V_40 ,
unsigned V_20 , unsigned V_41 )
{
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_20 ; V_42 ++ , V_39 += V_41 , V_40 += V_41 ) {
F_3 ( V_2 , V_37 , V_38 + V_42 ,
( T_2 * ) V_39 , ( const T_2 * ) V_40 ) ;
}
}
static void F_5 ( const T_3 * V_43 , T_3 * V_44 , unsigned V_45 , unsigned V_46 , unsigned V_47 )
{
unsigned V_48 ;
unsigned V_49 ;
unsigned V_50 = 0 ;
unsigned error = 0 ;
unsigned V_42 ;
V_45 /= 2 ;
V_46 /= 2 ;
V_48 = V_45 / V_46 ;
V_49 = V_45 % V_46 ;
for ( V_42 = 0 ; V_42 < V_46 ; V_42 ++ , V_44 += V_47 ) {
memcpy ( V_44 , V_43 + V_50 * V_47 , V_47 ) ;
V_50 += V_48 ;
error += V_49 ;
if ( error >= V_46 ) {
error -= V_46 ;
V_50 ++ ;
}
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_22 V_51 = {
0 , 0 , V_2 -> V_52 , V_2 -> V_53
} ;
struct V_22 V_54 = {
V_2 -> V_10 , V_2 -> V_12 ,
V_2 -> V_19 . V_20 , V_2 -> V_19 . V_26
} ;
V_2 -> V_55 = F_7 ( & V_2 -> V_56 , & V_2 -> V_19 ) ;
V_2 -> V_57 = V_2 -> V_55 ;
F_8 ( & V_2 -> V_57 , & V_2 -> V_19 , & V_2 -> V_58 ) ;
V_2 -> V_57 . V_9 += V_2 -> V_58 . V_9 ;
V_2 -> V_57 . V_11 += V_2 -> V_58 . V_11 ;
V_2 -> V_59 = V_2 -> V_55 ;
F_8 ( & V_2 -> V_59 , & V_2 -> V_56 , & V_2 -> V_60 ) ;
F_9 ( V_2 , 1 ,
L_1 ,
V_2 -> V_55 . V_20 , V_2 -> V_55 . V_26 ,
V_2 -> V_55 . V_9 , V_2 -> V_55 . V_11 ,
V_2 -> V_57 . V_20 , V_2 -> V_57 . V_26 ,
V_2 -> V_57 . V_9 , V_2 -> V_57 . V_11 ,
V_2 -> V_59 . V_20 , V_2 -> V_59 . V_26 ,
V_2 -> V_59 . V_9 , V_2 -> V_59 . V_11 ) ;
V_54 = F_7 ( & V_51 , & V_54 ) ;
V_54 . V_9 += V_2 -> V_19 . V_9 - V_2 -> V_10 ;
V_54 . V_11 += V_2 -> V_19 . V_11 - V_2 -> V_12 ;
V_2 -> V_61 = F_7 ( & V_54 , & V_2 -> V_55 ) ;
V_2 -> V_62 = V_2 -> V_61 ;
V_2 -> V_62 . V_9 -= V_2 -> V_19 . V_9 - V_2 -> V_10 ;
V_2 -> V_62 . V_11 -= V_2 -> V_19 . V_11 - V_2 -> V_12 ;
V_2 -> V_63 = V_2 -> V_61 ;
F_8 ( & V_2 -> V_63 , & V_2 -> V_56 , & V_2 -> V_60 ) ;
F_9 ( V_2 , 1 ,
L_2 ,
V_2 -> V_62 . V_20 , V_2 -> V_62 . V_26 ,
V_2 -> V_62 . V_9 , V_2 -> V_62 . V_11 ,
V_2 -> V_61 . V_20 , V_2 -> V_61 . V_26 ,
V_2 -> V_61 . V_9 , V_2 -> V_61 . V_11 ,
V_2 -> V_63 . V_20 , V_2 -> V_63 . V_26 ,
V_2 -> V_63 . V_9 , V_2 -> V_63 . V_11 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_17 , T_3 * V_39 ,
struct V_64 * V_65 )
{
bool V_66 = V_2 -> V_67 [ V_65 -> V_68 . V_69 . V_70 ] ;
struct V_71 * V_72 = & V_2 -> V_72 ;
struct V_64 * V_73 = NULL ;
unsigned V_41 = F_11 ( V_72 , V_17 ) / 2 ;
unsigned V_74 = V_2 -> V_60 . V_20 ;
unsigned V_75 = V_2 -> V_60 . V_26 ;
unsigned V_76 = V_72 -> V_77 [ V_17 ] ;
unsigned V_78 = V_2 -> V_79 [ V_17 ] ;
unsigned V_80 = V_2 -> V_81 ;
unsigned V_82 = ( V_75 * V_72 -> V_83 ) / 100 ;
T_3 * V_84 ;
T_3 * V_40 = NULL ;
unsigned V_85 ;
bool V_86 = V_2 -> V_16 || V_2 -> V_21 || V_2 -> V_27 ;
unsigned V_87 ;
unsigned V_88 ;
unsigned V_89 = 0 ;
unsigned V_90 = 0 ;
unsigned V_91 = 0 ;
unsigned V_92 = 0 ;
unsigned V_93 = 0 ;
unsigned V_94 = 0 ;
unsigned V_95 ;
bool V_96 ;
V_87 = V_2 -> V_57 . V_26 / V_2 -> V_59 . V_26 ;
V_88 = V_2 -> V_57 . V_26 % V_2 -> V_59 . V_26 ;
if ( ! F_12 ( & V_2 -> V_97 ) )
V_73 = F_13 ( V_2 -> V_97 . V_98 ,
struct V_64 , V_99 ) ;
if ( V_73 == NULL )
return - V_100 ;
V_65 -> V_68 . V_69 . V_101 = V_73 -> V_68 . V_69 . V_101 ;
V_84 = F_14 ( & V_73 -> V_68 , V_17 ) +
V_73 -> V_68 . V_102 [ V_17 ] . V_103 ;
V_84 += V_2 -> V_57 . V_9 * V_41 + V_2 -> V_57 . V_11 * V_78 ;
V_39 += V_2 -> V_60 . V_9 * V_41 + V_2 -> V_60 . V_11 * V_76 ;
if ( V_2 -> V_55 . V_20 == 0 || V_2 -> V_55 . V_26 == 0 ) {
for ( V_85 = 0 ; V_85 < V_82 ; V_85 ++ , V_39 += V_76 )
memcpy ( V_39 , V_72 -> V_104 [ V_17 ] , V_74 * V_41 ) ;
return 0 ;
}
if ( V_2 -> V_105 &&
V_2 -> V_61 . V_20 && V_2 -> V_61 . V_26 ) {
V_40 = V_2 -> V_106 ;
V_40 += V_2 -> V_62 . V_9 * V_41 +
V_2 -> V_62 . V_11 * V_80 ;
V_91 = V_2 -> V_61 . V_26 /
V_2 -> V_63 . V_26 ;
V_92 = V_2 -> V_61 . V_26 %
V_2 -> V_63 . V_26 ;
}
V_95 = V_2 -> V_59 . V_9 + V_2 -> V_59 . V_20 ;
V_96 = V_2 -> V_57 . V_20 == V_2 -> V_59 . V_20 ;
V_2 -> V_107 = V_2 -> V_57 . V_26 ;
for ( V_85 = 0 ; V_85 < V_82 ; V_85 ++ , V_39 += V_76 ) {
bool V_108 = V_40 && V_85 >= V_2 -> V_63 . V_11 &&
V_85 < V_2 -> V_63 . V_11 + V_2 -> V_63 . V_26 ;
if ( V_85 < V_2 -> V_59 . V_11 ||
V_85 >= V_2 -> V_59 . V_11 + V_2 -> V_59 . V_26 ) {
memcpy ( V_39 , V_72 -> V_104 [ V_17 ] , V_74 * V_41 ) ;
continue;
}
if ( V_2 -> V_59 . V_9 )
memcpy ( V_39 , V_72 -> V_104 [ V_17 ] , V_2 -> V_59 . V_9 * V_41 ) ;
if ( V_95 < V_74 )
memcpy ( V_39 + V_95 * V_41 ,
V_72 -> V_104 [ V_17 ] , ( V_74 - V_95 ) * V_41 ) ;
if ( V_96 && ! V_108 ) {
memcpy ( V_39 + V_2 -> V_59 . V_9 * V_41 ,
V_84 + V_89 * V_78 ,
V_2 -> V_59 . V_20 * V_41 ) ;
goto V_109;
}
if ( V_2 -> V_107 == V_89 ) {
memcpy ( V_39 + V_2 -> V_59 . V_9 * V_41 ,
V_2 -> V_110 ,
V_2 -> V_59 . V_20 * V_41 ) ;
goto V_109;
}
if ( ! V_108 ) {
F_5 ( V_84 + V_89 * V_78 , V_2 -> V_110 ,
V_2 -> V_57 . V_20 , V_2 -> V_59 . V_20 ,
F_11 ( V_72 , V_17 ) ) ;
} else {
unsigned V_111 =
( V_2 -> V_61 . V_9 - V_2 -> V_55 . V_9 ) * V_41 ;
T_3 * V_7 = V_40 + V_93 * V_80 ;
F_5 ( V_84 + V_89 * V_78 , V_2 -> V_112 ,
V_2 -> V_57 . V_20 , V_2 -> V_55 . V_20 ,
F_11 ( V_72 , V_17 ) ) ;
if ( V_86 )
F_4 ( V_2 , V_93 + V_2 -> V_61 . V_11 ,
V_2 -> V_61 . V_9 ,
V_2 -> V_112 + V_111 , V_7 ,
V_2 -> V_61 . V_20 , V_41 ) ;
else
memcpy ( V_2 -> V_112 + V_111 ,
V_7 , V_2 -> V_61 . V_20 * V_41 ) ;
F_5 ( V_2 -> V_112 , V_2 -> V_110 ,
V_2 -> V_55 . V_20 , V_2 -> V_59 . V_20 ,
F_11 ( V_72 , V_17 ) ) ;
}
V_2 -> V_107 = V_89 ;
memcpy ( V_39 + V_2 -> V_59 . V_9 * V_41 ,
V_2 -> V_110 ,
V_2 -> V_59 . V_20 * V_41 ) ;
V_109:
if ( V_108 ) {
V_93 += V_91 ;
V_94 += V_92 ;
if ( V_94 >= V_2 -> V_63 . V_26 ) {
V_94 -= V_2 -> V_63 . V_26 ;
V_93 ++ ;
}
}
V_89 += V_87 ;
V_90 += V_88 ;
if ( V_90 >= V_2 -> V_59 . V_26 ) {
V_90 -= V_2 -> V_59 . V_26 ;
V_89 ++ ;
}
}
if ( ! V_66 )
return 0 ;
for (; V_85 < V_75 ; V_85 ++ , V_39 += V_76 )
memcpy ( V_39 , V_72 -> V_113 [ V_17 ] , V_74 * V_41 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_64 * V_114 )
{
unsigned V_115 = F_16 ( V_2 -> V_116 ) ? 2 : 1 ;
unsigned V_117 = 16 / V_115 ;
bool V_118 = F_2 ( V_2 ) ;
bool V_119 = V_118 && ( V_2 -> V_3 & V_120 ) ;
unsigned V_17 ;
int line = 1 ;
T_3 * V_121 [ V_122 ] [ 2 ] ;
unsigned V_123 ;
char V_124 [ 100 ] ;
T_4 V_125 ;
bool V_126 = false ;
if ( V_2 -> V_127 && V_2 -> V_128 &&
( ( F_17 ( V_2 ) && ! F_18 ( V_2 -> V_129 ) ) ||
( F_19 ( V_2 ) && ! F_18 ( V_2 -> V_130 ) ) ) )
V_126 = true ;
V_114 -> V_68 . V_69 . V_131 = V_2 -> V_132 ;
if ( V_2 -> V_133 )
F_20 ( & V_114 -> V_68 . V_69 . V_134 ) ;
if ( V_2 -> V_116 == V_135 ) {
V_114 -> V_68 . V_69 . V_101 = ( ( V_2 -> V_132 & 1 ) ^ V_119 ) ?
V_136 : V_137 ;
V_114 -> V_68 . V_69 . V_131 /= 2 ;
} else {
V_114 -> V_68 . V_69 . V_101 = V_2 -> V_116 ;
}
F_21 ( & V_2 -> V_72 , V_114 -> V_68 . V_69 . V_101 ) ;
F_22 ( & V_2 -> V_72 , V_2 -> V_67 [ V_114 -> V_68 . V_69 . V_70 ] ) ;
F_6 ( V_2 ) ;
for ( V_17 = 0 ; V_17 < F_23 ( & V_2 -> V_72 ) ; V_17 ++ ) {
void * V_138 = F_14 ( & V_114 -> V_68 , V_17 ) ;
if ( V_2 -> V_31 -> V_103 [ V_17 ] ) {
memset ( V_138 , V_2 -> V_31 -> V_103 [ V_17 ] & 0xff ,
V_2 -> V_31 -> V_103 [ V_17 ] ) ;
V_138 += V_2 -> V_31 -> V_103 [ V_17 ] ;
}
F_24 ( & V_2 -> V_72 , V_121 , V_17 , V_138 ) ;
if ( ! V_126 || F_10 ( V_2 , V_17 , V_138 , V_114 ) )
F_25 ( & V_2 -> V_72 , F_1 ( V_2 ) , V_17 , V_138 ) ;
}
V_2 -> V_67 [ V_114 -> V_68 . V_69 . V_70 ] = false ;
if ( V_2 -> V_116 != V_135 || ( V_114 -> V_68 . V_69 . V_131 & 1 ) == 0 )
V_2 -> V_139 = F_26 ( V_140 - V_2 -> V_141 ) ;
V_123 = V_2 -> V_139 ;
if ( V_2 -> V_142 <= 1 ) {
snprintf ( V_124 , sizeof( V_124 ) , L_3 ,
( V_123 / ( 60 * 60 * 1000 ) ) % 24 ,
( V_123 / ( 60 * 1000 ) ) % 60 ,
( V_123 / 1000 ) % 60 ,
V_123 % 1000 ,
V_114 -> V_68 . V_69 . V_131 ,
( V_2 -> V_116 == V_135 ) ?
( V_114 -> V_68 . V_69 . V_101 == V_136 ?
L_4 : L_5 ) : L_6 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
}
if ( V_2 -> V_142 == 0 ) {
snprintf ( V_124 , sizeof( V_124 ) , L_7 ,
V_2 -> V_143 . V_20 , V_2 -> V_143 . V_26 , V_2 -> V_144 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
V_125 = F_28 ( V_2 -> V_125 ) ;
F_29 ( V_2 -> V_145 . V_146 ) ;
snprintf ( V_124 , sizeof( V_124 ) ,
L_8 ,
V_2 -> V_147 -> V_148 . V_149 ,
V_2 -> V_150 -> V_148 . V_149 ,
V_2 -> V_151 -> V_148 . V_149 ,
V_2 -> V_152 -> V_148 . V_149 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
snprintf ( V_124 , sizeof( V_124 ) ,
L_9 ,
V_2 -> V_153 -> V_148 . V_149 , V_125 , V_2 -> V_154 -> V_148 . V_149 ) ;
F_30 ( V_2 -> V_145 . V_146 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
F_29 ( V_2 -> V_155 . V_146 ) ;
snprintf ( V_124 , sizeof( V_124 ) ,
L_10 ,
V_2 -> V_156 -> V_148 . V_149 , V_2 -> V_157 -> V_148 . V_149 ) ;
F_30 ( V_2 -> V_155 . V_146 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
F_29 ( V_2 -> V_158 . V_146 ) ;
snprintf ( V_124 , sizeof( V_124 ) , L_11 ,
V_2 -> V_159 -> V_148 . V_149 ,
* V_2 -> V_160 -> V_161 . V_162 ,
V_2 -> V_163 -> V_148 . V_149 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
snprintf ( V_124 , sizeof( V_124 ) , L_12 ,
V_2 -> boolean -> V_148 . V_149 ,
V_2 -> V_164 -> V_165 [ V_2 -> V_164 -> V_148 . V_149 ] ,
V_2 -> string -> V_161 . V_166 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
snprintf ( V_124 , sizeof( V_124 ) , L_13 ,
V_2 -> V_167 -> V_168 [ V_2 -> V_167 -> V_148 . V_149 ] ,
V_2 -> V_167 -> V_148 . V_149 ) ;
F_30 ( V_2 -> V_158 . V_146 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
if ( V_2 -> V_169 ) {
V_2 -> V_169 -- ;
snprintf ( V_124 , sizeof( V_124 ) , L_14 ) ;
F_27 ( & V_2 -> V_72 , V_121 , line ++ * V_117 , 16 , V_124 ) ;
}
}
if ( ! V_2 -> V_133 )
F_20 ( & V_114 -> V_68 . V_69 . V_134 ) ;
V_114 -> V_68 . V_69 . V_134 . V_170 += V_2 -> V_171 ;
}
static bool F_31 ( struct V_1 * V_2 , int V_4 , int V_5 , int V_14 , int V_13 )
{
int V_15 ;
if ( V_2 -> V_172 ) {
const T_3 * V_17 = V_2 -> V_172 ;
unsigned V_18 = ( V_2 -> V_60 . V_20 + 7 ) / 8 ;
if ( ! ( V_17 [ V_18 * V_4 + V_5 / 8 ] & ( 1 << ( V_5 & 7 ) ) ) )
return false ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_173 ; V_15 ++ ) {
struct V_22 * V_23 = & V_2 -> V_174 [ V_15 ] . V_25 ;
if ( V_14 >= V_23 -> V_11 && V_14 < V_23 -> V_11 + V_23 -> V_26 &&
V_13 >= V_23 -> V_9 && V_13 < V_23 -> V_9 + V_23 -> V_20 )
return false ;
}
return true ;
}
static void F_32 ( struct V_1 * V_2 , struct V_64 * V_114 )
{
struct V_71 * V_72 = & V_2 -> V_72 ;
unsigned V_41 = F_11 ( V_72 , 0 ) / 2 ;
void * V_175 = V_2 -> V_176 ;
void * V_138 = F_14 ( & V_114 -> V_68 , 0 ) ;
unsigned V_74 = V_2 -> V_60 . V_20 ;
unsigned V_75 = V_2 -> V_60 . V_26 ;
unsigned V_18 = V_72 -> V_77 [ 0 ] ;
bool V_96 = V_2 -> V_172 == NULL && V_2 -> V_173 == 0 ;
int V_42 , V_85 , V_177 , V_178 = 0 ;
if ( ( V_2 -> V_179 == V_136 ||
V_2 -> V_179 == V_137 ) &&
V_2 -> V_179 != V_114 -> V_68 . V_69 . V_101 )
return;
V_138 += V_2 -> V_60 . V_9 * V_41 + V_2 -> V_60 . V_11 * V_18 ;
V_42 = V_2 -> V_180 ;
V_177 = V_74 ;
if ( V_42 < 0 ) {
V_178 = - V_42 ;
V_177 = V_177 - V_178 ;
V_42 = 0 ;
} else {
V_177 = V_2 -> V_181 . V_182 . V_20 - V_42 ;
if ( V_177 > V_74 )
V_177 = V_74 ;
}
if ( V_177 <= 0 )
return;
if ( V_2 -> V_183 >= 0 )
V_175 += V_2 -> V_183 * V_2 -> V_181 . V_182 . V_77 ;
for ( V_85 = V_2 -> V_183 ;
V_85 < V_2 -> V_183 + ( int ) V_75 ;
V_85 ++ , V_138 += V_18 ) {
int V_184 ;
if ( V_85 < 0 || V_85 > V_2 -> V_181 . V_182 . V_26 )
continue;
if ( V_96 ) {
memcpy ( V_175 + V_42 * V_41 ,
V_138 + V_178 * V_41 , V_177 * V_41 ) ;
V_175 += V_2 -> V_181 . V_182 . V_77 ;
continue;
}
for ( V_184 = 0 ; V_184 < V_177 ; V_184 ++ ) {
if ( ! F_31 ( V_2 , V_85 - V_2 -> V_183 ,
V_184 + V_178 , V_85 , V_184 + V_42 ) )
continue;
memcpy ( V_175 + ( V_184 + V_42 ) * V_41 ,
V_138 + ( V_184 + V_178 ) * V_41 ,
V_41 ) ;
}
V_175 += V_2 -> V_181 . V_182 . V_77 ;
}
}
static void F_33 ( struct V_1 * V_2 , int V_185 )
{
struct V_64 * V_65 = NULL ;
struct V_64 * V_186 = NULL ;
F_9 ( V_2 , 1 , L_15 ) ;
while ( V_185 -- > 1 )
F_34 ( & V_2 -> V_72 ,
V_2 -> V_116 == V_187 ||
V_2 -> V_116 == V_135 ) ;
if ( V_2 -> V_188 &&
F_35 ( 100 ) < V_2 -> V_188 )
goto V_189;
F_36 ( & V_2 -> V_190 ) ;
if ( ! F_12 ( & V_2 -> V_191 ) ) {
V_65 = F_13 ( V_2 -> V_191 . V_98 , struct V_64 , V_99 ) ;
F_37 ( & V_65 -> V_99 ) ;
}
if ( ! F_12 ( & V_2 -> V_192 ) ) {
if ( V_2 -> V_116 != V_135 ||
( V_2 -> V_193 & 1 ) ) {
V_186 = F_13 ( V_2 -> V_192 . V_98 ,
struct V_64 , V_99 ) ;
F_37 ( & V_186 -> V_99 ) ;
}
}
F_38 ( & V_2 -> V_190 ) ;
if ( ! V_65 && ! V_186 )
goto V_189;
if ( V_65 ) {
F_15 ( V_2 , V_65 ) ;
F_9 ( V_2 , 1 , L_16 ,
V_65 -> V_68 . V_69 . V_70 ) ;
if ( V_2 -> V_194 && V_2 -> V_181 . V_195 &&
V_2 -> V_181 . V_182 . V_196 == V_2 -> V_31 -> V_197 )
F_32 ( V_2 , V_65 ) ;
F_39 ( & V_65 -> V_68 , V_2 -> V_198 ?
V_199 : V_200 ) ;
F_9 ( V_2 , 2 , L_17 ,
V_65 -> V_68 . V_69 . V_70 ) ;
}
if ( V_186 ) {
if ( V_2 -> V_201 )
F_40 ( V_2 , V_186 ) ;
else
F_41 ( V_2 , V_186 ) ;
F_39 ( & V_186 -> V_68 , V_2 -> V_198 ?
V_199 : V_200 ) ;
F_9 ( V_2 , 2 , L_18 ,
V_186 -> V_68 . V_69 . V_70 ) ;
}
V_2 -> V_198 = false ;
V_189:
F_34 ( & V_2 -> V_72 , V_2 -> V_116 == V_187 ||
V_2 -> V_116 == V_135 ) ;
}
static int F_42 ( void * V_202 )
{
struct V_1 * V_2 = V_202 ;
T_5 V_203 ;
T_5 V_204 ;
T_5 V_205 ;
unsigned long V_206 ;
unsigned long V_207 ;
unsigned V_208 ;
unsigned V_209 ;
unsigned V_210 ;
int V_185 ;
F_9 ( V_2 , 1 , L_19 ) ;
F_43 () ;
V_2 -> V_211 = 0 ;
V_2 -> V_212 = 0 ;
V_2 -> V_213 = false ;
V_2 -> V_141 = V_140 ;
for (; ; ) {
F_44 () ;
if ( F_45 () )
break;
F_29 ( & V_2 -> V_214 ) ;
V_207 = V_140 ;
if ( V_2 -> V_213 ) {
V_2 -> V_141 = V_207 ;
V_2 -> V_211 = V_2 -> V_212 + 1 ;
V_2 -> V_212 = 0 ;
V_2 -> V_213 = false ;
}
V_209 = V_2 -> V_215 . V_209 ;
V_210 = V_2 -> V_215 . V_210 ;
if ( V_2 -> V_116 == V_135 )
V_210 *= 2 ;
V_206 = V_207 - V_2 -> V_141 ;
V_204 = ( T_5 ) V_206 * V_210 +
( V_216 * V_209 ) / 2 ;
F_46 ( V_204 , V_216 * V_209 ) ;
if ( V_206 > V_217 ) {
V_2 -> V_141 = V_207 ;
V_2 -> V_211 = V_204 ;
V_204 = 0 ;
}
V_185 = V_204 + V_2 -> V_211 - V_2 -> V_212 ;
V_2 -> V_212 = V_204 + V_2 -> V_211 ;
V_2 -> V_132 = V_2 -> V_212 - V_2 -> V_218 ;
V_2 -> V_193 = V_2 -> V_212 - V_2 -> V_219 ;
F_33 ( V_2 , V_185 ) ;
V_203 = ++ V_204 * V_209 ;
V_206 = V_140 - V_2 -> V_141 ;
F_30 ( & V_2 -> V_214 ) ;
V_205 = V_203 * V_216 +
V_210 / 2 ;
F_46 ( V_205 , V_210 ) ;
if ( V_205 < V_206 )
V_205 = V_206 ;
V_208 = V_205 - V_206 ;
F_47 ( V_208 ? V_208 : 1 ) ;
}
F_9 ( V_2 , 1 , L_20 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 , bool V_220 )
{
F_49 ( V_2 -> V_221 , V_220 ) ;
F_49 ( V_2 -> V_222 , V_220 ) ;
F_49 ( V_2 -> V_223 , V_220 ) ;
}
int F_50 ( struct V_1 * V_2 , bool * V_224 )
{
F_9 ( V_2 , 1 , L_21 , V_225 ) ;
if ( V_2 -> V_226 ) {
T_6 V_227 = V_2 -> V_212 + V_2 -> V_228 * 128 ;
if ( V_224 == & V_2 -> V_229 )
V_2 -> V_218 = V_227 ;
else
V_2 -> V_219 = V_227 ;
* V_224 = true ;
return 0 ;
}
F_51 ( & V_2 -> V_72 ) ;
V_2 -> V_218 = V_2 -> V_228 * 128 ;
V_2 -> V_219 = V_2 -> V_228 * 128 ;
V_2 -> V_226 = F_52 ( F_42 , V_2 ,
L_22 , V_2 -> V_230 . V_231 ) ;
if ( F_53 ( V_2 -> V_226 ) ) {
F_54 ( & V_2 -> V_230 , L_23 ) ;
return F_55 ( V_2 -> V_226 ) ;
}
* V_224 = true ;
F_48 ( V_2 , true ) ;
F_9 ( V_2 , 1 , L_24 , V_225 ) ;
return 0 ;
}
void F_56 ( struct V_1 * V_2 , bool * V_224 )
{
F_9 ( V_2 , 1 , L_21 , V_225 ) ;
if ( V_2 -> V_226 == NULL )
return;
* V_224 = false ;
if ( V_224 == & V_2 -> V_229 ) {
while ( ! F_12 ( & V_2 -> V_191 ) ) {
struct V_64 * V_114 ;
V_114 = F_13 ( V_2 -> V_191 . V_98 ,
struct V_64 , V_99 ) ;
F_37 ( & V_114 -> V_99 ) ;
F_39 ( & V_114 -> V_68 , V_199 ) ;
F_9 ( V_2 , 2 , L_17 ,
V_114 -> V_68 . V_69 . V_70 ) ;
}
}
if ( V_224 == & V_2 -> V_232 ) {
while ( ! F_12 ( & V_2 -> V_192 ) ) {
struct V_64 * V_114 ;
V_114 = F_13 ( V_2 -> V_192 . V_98 ,
struct V_64 , V_99 ) ;
F_37 ( & V_114 -> V_99 ) ;
F_39 ( & V_114 -> V_68 , V_199 ) ;
F_9 ( V_2 , 2 , L_25 ,
V_114 -> V_68 . V_69 . V_70 ) ;
}
}
if ( V_2 -> V_229 || V_2 -> V_232 )
return;
F_48 ( V_2 , false ) ;
F_30 ( & V_2 -> V_214 ) ;
F_57 ( V_2 -> V_226 ) ;
V_2 -> V_226 = NULL ;
F_29 ( & V_2 -> V_214 ) ;
}
