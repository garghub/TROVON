const char * F_1 ( unsigned int V_1 )
{
if ( V_1 >= F_2 ( V_2 ) || ! V_2 [ V_1 ] )
return L_1 ;
return V_2 [ V_1 ] ;
}
static const char * F_3 ( unsigned int V_1 )
{
if ( V_1 >= F_2 ( V_3 ) ||
! V_3 [ V_1 ] )
return L_1 ;
return V_3 [ V_1 ] ;
}
static const char * F_4 ( unsigned int V_4 )
{
if ( V_4 >= F_2 ( V_5 ) || ! V_5 [ V_4 ] )
return L_1 ;
return V_5 [ V_4 ] ;
}
static inline T_1 * F_5 ( struct V_6 * V_6 ,
struct V_7 * V_8 )
{
T_2 V_9 = V_8 -> V_10 -> V_11 & ( V_12 - 1 ) ;
return & V_6 -> V_13 [ V_9 ] ;
}
static void F_6 ( struct V_6 * V_6 ,
struct V_14 * V_15 ,
struct V_7 * V_8 )
{
if ( V_15 -> V_16 )
F_7 ( V_6 -> V_17 , V_15 -> V_16 ,
sizeof( V_15 -> V_18 [ 0 ] ) * V_15 -> V_19 ,
V_20 ) ;
F_8 ( V_8 ) ;
if ( V_15 -> V_19 )
F_9 ( V_15 -> V_21 ,
V_6 -> V_22 [ V_15 -> V_23 ] ) ;
if ( V_15 -> V_24 )
F_7 ( V_6 -> V_17 , V_15 -> V_24 ,
V_25 , V_26 ) ;
}
static int F_10 ( struct V_6 * V_6 , struct V_27 * V_28 )
{
if ( ! V_6 -> V_29 [ 0 ] )
return 1 ;
if ( V_28 -> V_30 <= V_6 -> V_31 [ 0 ] )
V_28 -> V_32 . V_33 += ( V_6 -> V_31 [ 0 ]
- V_28 -> V_30 + 1 ) ;
else
V_28 -> V_32 . V_33 += ( V_28 -> V_32 . V_34
- V_28 -> V_30
+ V_6 -> V_31 [ 0 ] + 1 ) ;
V_28 -> V_30 =
( V_6 -> V_31 [ 0 ] + 1 ) % V_28 -> V_32 . V_34 ;
V_6 -> V_29 [ 0 ] = 0 ;
return 0 ;
}
int F_11 ( struct V_6 * V_6 )
{
struct V_27 * V_28 = & V_6 -> V_35 [ 0 ] ;
int V_36 = 0 ;
unsigned long V_37 ;
F_12 ( & V_6 -> V_38 ) ;
F_12 ( & V_6 -> V_39 ) ;
F_13 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
if ( F_14 ( V_28 ) <= V_6 -> V_41 [ 0 ] )
F_10 ( V_6 , V_28 ) ;
if ( ! F_14 ( V_28 ) )
V_36 = - V_42 ;
else
F_15 ( V_28 , V_43 ) ;
F_16 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
if ( ! V_36 )
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_2 ) ;
else
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_3 ) ;
return V_36 ;
}
int F_18 ( struct V_6 * V_6 , T_2 V_47 )
{
struct V_27 * V_28 = & V_6 -> V_35 [ 0 ] ;
enum V_48 V_49 ;
struct V_50 * V_51 = V_6 -> V_45 ;
T_3 V_52 [ V_53 ] ;
int V_36 = 0 ;
unsigned long V_37 ;
F_13 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
if ( F_14 ( V_28 ) <= V_6 -> V_41 [ 0 ] )
F_10 ( V_6 , V_28 ) ;
if ( ! F_14 ( V_28 ) ) {
V_36 = - V_42 ;
goto V_54;
}
if ( V_6 -> V_55 . V_56 ) {
memset ( V_52 , 0xff , V_53 ) ;
V_49 = V_57 ;
} else {
memcpy ( V_52 , V_6 -> V_55 . V_58 , V_53 ) ;
V_49 = V_59 ;
}
if ( ( V_6 -> V_60 . V_37 & V_61 ) && ! V_6 -> V_55 . V_56 ) {
F_19 ( V_28 , V_43 ,
V_47 , V_52 ,
V_6 -> V_62 ,
V_51 -> V_63 , V_51 -> V_64 ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_4 ,
V_47 , V_6 -> V_62 , V_52 ) ;
} else {
F_20 ( V_28 , V_43 ,
V_49 , V_47 , V_52 ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_5 ,
V_47 , V_6 -> V_55 . V_56 , V_52 ) ;
}
V_54:
F_16 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
return V_36 ;
}
static inline int F_21 ( struct V_6 * V_6 ,
struct V_27 * V_28 ,
struct V_14 * V_15 ,
struct V_7 * V_8 ,
int V_65 )
{
struct V_66 * V_67 ;
struct V_68 * V_69 = F_22 ( F_23 ( V_8 -> V_70 ) ) ;
struct V_71 * V_72 = V_69 -> V_73 ;
struct V_74 * V_75 ;
T_3 V_76 = 0 ;
unsigned int V_77 ;
unsigned long V_78 ;
int V_37 ;
T_3 V_79 ;
struct V_80 V_81 ;
char V_82 [ 2 ] ;
if ( V_65 ) {
V_75 = V_15 -> V_18 ;
F_24 (scsi_sglist(sc), sg, sg_count, i) {
V_75 -> V_83 = F_25 ( F_26 ( V_67 ) ) ;
V_75 -> V_84 = F_27 ( F_28 ( V_67 ) ) ;
V_75 -> V_85 = 0 ;
V_75 ++ ;
}
V_15 -> V_16 = F_29
( V_6 -> V_17 ,
V_15 -> V_18 ,
sizeof( V_15 -> V_18 [ 0 ] ) * V_65 ,
V_20 ) ;
}
V_15 -> V_24 = F_29 ( V_6 -> V_17 ,
V_8 -> V_86 ,
V_25 ,
V_26 ) ;
F_30 ( V_8 -> V_70 -> V_87 , & V_81 ) ;
V_76 = V_88 ;
V_82 [ 0 ] = V_89 ;
F_31 ( V_8 , V_82 ) ;
if ( V_82 [ 0 ] == V_90 )
V_76 = V_91 ;
F_13 ( & V_6 -> V_40 [ 0 ] , V_78 ) ;
if ( F_14 ( V_28 ) <= V_6 -> V_41 [ 0 ] )
F_10 ( V_6 , V_28 ) ;
if ( F_32 ( ! F_14 ( V_28 ) ) ) {
F_16 ( & V_6 -> V_40 [ 0 ] , V_78 ) ;
return V_92 ;
}
V_37 = 0 ;
if ( V_8 -> V_93 == V_94 )
V_37 = V_95 ;
else if ( V_8 -> V_93 == V_96 )
V_37 = V_97 ;
V_79 = 0 ;
if ( ( V_6 -> V_60 . V_37 & V_98 ) &&
( V_72 -> V_37 & V_99 ) )
V_79 |= V_100 ;
F_33 ( V_28 , V_8 -> V_10 -> V_11 ,
0 , V_79 , V_15 -> V_19 ,
V_25 ,
V_15 -> V_16 ,
V_15 -> V_24 ,
0 ,
V_76 ,
V_37 ,
V_8 -> V_101 , V_8 -> V_102 ,
F_34 ( V_8 ) ,
V_81 . V_80 , V_15 -> V_103 ,
V_69 -> V_104 , V_72 -> V_63 ,
V_72 -> V_64 ) ;
F_16 ( & V_6 -> V_40 [ 0 ] , V_78 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 , void (* F_36)( struct V_7 * ) )
{
struct V_50 * V_51 ;
struct V_68 * V_69 ;
struct V_14 * V_15 ;
struct V_6 * V_6 ;
struct V_27 * V_28 ;
int V_36 ;
int V_65 ;
unsigned long V_37 ;
unsigned long V_105 ;
V_69 = F_22 ( F_23 ( V_8 -> V_70 ) ) ;
V_36 = F_37 ( V_69 ) ;
if ( V_36 ) {
V_8 -> V_106 = V_36 ;
F_36 ( V_8 ) ;
return 0 ;
}
V_51 = F_38 ( V_8 -> V_70 -> V_46 ) ;
if ( V_51 -> V_1 != V_107 || ! ( V_51 -> V_108 ) )
return V_92 ;
F_39 ( V_51 -> V_46 -> V_109 ) ;
V_6 = F_40 ( V_51 ) ;
V_15 = F_41 ( V_6 -> V_110 , V_111 ) ;
if ( ! V_15 ) {
V_36 = V_92 ;
goto V_112;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_65 = F_42 ( V_8 ) ;
if ( V_65 < 0 ) {
F_9 ( V_15 , V_6 -> V_110 ) ;
goto V_112;
}
V_15 -> V_19 = V_65 ;
V_15 -> V_23 = V_113 ;
if ( V_65 > V_114 )
V_15 -> V_23 = V_115 ;
if ( V_65 ) {
V_15 -> V_18 =
F_41 ( V_6 -> V_22 [ V_15 -> V_23 ] ,
V_111 | V_116 ) ;
if ( ! V_15 -> V_18 ) {
V_36 = V_92 ;
F_8 ( V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
goto V_112;
}
V_15 -> V_21 = V_15 -> V_18 ;
V_105 = ( unsigned long ) V_15 -> V_18 ;
if ( V_105 % V_117 ) {
V_15 -> V_18 = (struct V_74 * )
( ( ( unsigned long ) V_105
+ V_117 - 1 )
& ~ ( V_117 - 1 ) ) ;
}
}
V_15 -> V_103 = V_69 -> V_103 ;
F_43 ( V_8 ) = V_118 ;
F_44 ( V_8 ) = ( char * ) V_15 ;
V_8 -> V_119 = F_36 ;
V_28 = & V_6 -> V_35 [ 0 ] ;
V_36 = F_21 ( V_6 , V_28 , V_15 , V_8 , V_65 ) ;
if ( V_36 ) {
T_1 * V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
F_44 ( V_8 ) = NULL ;
F_43 ( V_8 ) = V_121 ;
F_16 ( V_120 , V_37 ) ;
if ( V_15 ) {
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
}
}
V_112:
F_45 ( V_51 -> V_46 -> V_109 ) ;
return V_36 ;
}
static int F_46 ( struct V_6 * V_6 ,
struct V_122 * V_75 )
{
T_3 type ;
T_3 V_123 ;
struct V_124 V_11 ;
int V_36 = 0 ;
unsigned long V_37 ;
F_47 ( & V_75 -> V_125 , & type , & V_123 , & V_11 ) ;
F_48 ( V_6 , V_43 ) ;
F_13 ( & V_6 -> V_126 , V_37 ) ;
if ( V_6 -> V_1 == V_127 ) {
if ( ! V_123 ) {
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_6 ) ;
V_6 -> V_1 = V_128 ;
} else {
F_17 ( V_44 ,
V_6 -> V_45 -> V_46 ,
L_7 ,
F_4 ( V_123 ) ) ;
V_6 -> V_1 = V_129 ;
V_36 = - 1 ;
}
} else {
F_17 ( V_44 ,
V_6 -> V_45 -> V_46 ,
L_8
L_9 , F_1 ( V_6 -> V_1 ) ) ;
V_36 = - 1 ;
}
if ( V_6 -> V_130 )
F_49 ( V_6 -> V_130 ) ;
if ( V_6 -> V_130 || V_36 ) {
F_16 ( & V_6 -> V_126 , V_37 ) ;
F_12 ( & V_6 -> V_39 ) ;
goto V_131;
}
F_16 ( & V_6 -> V_126 , V_37 ) ;
F_50 ( V_6 ) ;
V_131:
return V_36 ;
}
static int F_51 ( struct V_6 * V_6 ,
struct V_122 * V_75 )
{
T_3 type ;
T_3 V_123 ;
struct V_124 V_11 ;
int V_36 = 0 ;
unsigned long V_37 ;
F_47 ( & V_75 -> V_125 , & type , & V_123 , & V_11 ) ;
F_13 ( & V_6 -> V_126 , V_37 ) ;
if ( V_6 -> V_1 == V_132 ) {
if ( ! V_123 ) {
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_10 ) ;
V_6 -> V_1 = V_129 ;
} else {
F_17 ( V_44 ,
V_6 -> V_45 -> V_46 ,
L_11 ,
F_4 ( V_123 ) ) ;
V_6 -> V_1 = V_128 ;
V_36 = - 1 ;
}
} else {
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_12
L_13 ,
F_1 ( V_6 -> V_1 ) ) ;
V_36 = - 1 ;
}
if ( ! V_36 ) {
if ( V_6 -> V_133 ) {
F_16 ( & V_6 -> V_126 , V_37 ) ;
goto V_134;
}
F_16 ( & V_6 -> V_126 , V_37 ) ;
F_50 ( V_6 ) ;
F_52 ( V_135 , & V_6 -> V_136 ) ;
} else {
F_16 ( & V_6 -> V_126 , V_37 ) ;
}
V_134:
return V_36 ;
}
static inline int F_53 ( struct V_27 * V_28 ,
T_4 V_137 )
{
if ( V_28 -> V_30 <= V_28 -> V_138 ) {
if ( V_137 < V_28 -> V_30 ||
V_137 >= V_28 -> V_138 )
return 0 ;
} else {
if ( V_137 < V_28 -> V_30 &&
V_137 >= V_28 -> V_138 )
return 0 ;
}
return 1 ;
}
static inline void F_54 ( struct V_6 * V_6 ,
unsigned int V_139 ,
struct V_122 * V_75 )
{
struct V_27 * V_28 ;
T_4 V_137 = V_75 -> V_140 . V_141 . V_137 ;
unsigned long V_37 ;
V_28 = & V_6 -> V_35 [ V_139 - V_6 -> V_142 - V_6 -> V_143 ] ;
F_13 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
if ( F_53 ( V_28 , V_137 ) ) {
V_6 -> V_31 [ 0 ] = V_137 ;
V_6 -> V_29 [ 0 ] = 1 ;
}
F_16 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
}
static void F_55 ( struct V_6 * V_6 ,
struct V_122 * V_75 )
{
T_3 type ;
T_3 V_123 ;
struct V_124 V_11 ;
T_2 V_144 ;
T_5 V_145 = 0 ;
struct V_146 * V_147 ;
struct V_14 * V_15 ;
struct V_7 * V_8 ;
unsigned long V_37 ;
T_1 * V_120 ;
F_47 ( & V_75 -> V_125 , & type , & V_123 , & V_11 ) ;
F_56 ( & V_11 , & V_144 ) ;
if ( V_144 >= V_148 )
return;
V_8 = F_57 ( V_6 -> V_45 -> V_46 , V_144 ) ;
F_58 ( ! V_8 ) ;
if ( ! V_8 )
return;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
F_58 ( ! V_15 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
return;
}
V_15 -> V_149 = 1 ;
if ( F_43 ( V_8 ) == V_150 ) {
F_16 ( V_120 , V_37 ) ;
return;
}
F_43 ( V_8 ) = V_121 ;
V_147 = & V_75 -> V_140 . V_147 ;
switch ( V_123 ) {
case V_151 :
V_8 -> V_106 = ( V_152 << 16 ) | V_147 -> V_153 ;
V_145 = F_34 ( V_8 ) ;
F_59 ( V_8 , V_147 -> V_154 ) ;
if ( V_147 -> V_37 & V_155 )
V_145 -= V_147 -> V_154 ;
if ( V_147 -> V_153 == V_156 ) {
struct V_157 * V_158 ;
int V_159 = 0 ;
F_60 (t_sdev, sc->device->host) {
if ( V_158 -> V_144 != V_8 -> V_70 -> V_144 )
continue;
if ( V_158 -> V_160 > 1 ) {
V_159 = F_61
( V_158 ,
V_158 -> V_160 - 1 ) ;
if ( V_159 == - 1 )
V_159 = V_158 -> V_46 -> V_161 ;
F_62 ( V_162 ,
V_6 -> V_45 -> V_46 ,
L_14
L_15
L_16 ,
V_158 -> V_46 -> V_163 ,
V_158 -> V_164 ,
V_158 -> V_144 , V_158 -> V_87 ,
V_158 -> V_160 ) ;
}
}
}
break;
case V_165 :
V_8 -> V_106 = ( V_166 << 16 ) | V_147 -> V_153 ;
break;
case V_167 :
V_8 -> V_106 = ( V_168 << 16 ) | V_147 -> V_153 ;
break;
case V_169 :
F_59 ( V_8 , V_147 -> V_154 ) ;
V_8 -> V_106 = ( V_168 << 16 ) | V_147 -> V_153 ;
break;
case V_170 :
V_8 -> V_106 = ( V_171 << 16 ) | V_147 -> V_153 ;
break;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
default:
F_62 ( V_179 , V_6 -> V_45 -> V_46 , L_17 ,
F_4 ( V_123 ) ) ;
V_8 -> V_106 = ( V_168 << 16 ) | V_147 -> V_153 ;
break;
}
F_44 ( V_8 ) = NULL ;
F_16 ( V_120 , V_37 ) ;
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
if ( V_8 -> V_93 == V_94 ) {
V_6 -> V_45 -> V_180 . V_181 ++ ;
V_6 -> V_182 += V_145 ;
} else if ( V_8 -> V_93 == V_96 ) {
V_6 -> V_45 -> V_180 . V_183 ++ ;
V_6 -> V_184 += V_145 ;
} else
V_6 -> V_45 -> V_180 . V_185 ++ ;
if ( V_8 -> V_119 )
V_8 -> V_119 ( V_8 ) ;
}
static void F_63 ( struct V_6 * V_6 ,
struct V_122 * V_75 )
{
T_3 type ;
T_3 V_123 ;
struct V_124 V_11 ;
T_2 V_144 ;
struct V_7 * V_8 ;
struct V_14 * V_15 ;
unsigned long V_37 ;
T_1 * V_120 ;
F_47 ( & V_75 -> V_125 , & type , & V_123 , & V_11 ) ;
F_56 ( & V_11 , & V_144 ) ;
if ( ( V_144 & V_186 ) >= V_148 )
return;
V_8 = F_57 ( V_6 -> V_45 -> V_46 , V_144 & V_186 ) ;
F_58 ( ! V_8 ) ;
if ( ! V_8 )
return;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
F_58 ( ! V_15 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
return;
}
if ( V_144 & V_187 ) {
if ( F_43 ( V_8 ) != V_150 ) {
F_16 ( V_120 , V_37 ) ;
return;
}
F_43 ( V_8 ) = V_188 ;
F_64 ( V_8 ) = V_123 ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_18 ,
( int ) ( V_144 & V_186 ) ,
F_4 ( V_123 ) ) ;
if ( V_15 -> V_189 ) {
F_49 ( V_15 -> V_189 ) ;
F_16 ( V_120 , V_37 ) ;
} else {
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_19 ) ;
F_44 ( V_8 ) = NULL ;
V_8 -> V_106 = ( V_168 << 16 ) ;
F_16 ( V_120 , V_37 ) ;
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
if ( V_8 -> V_119 )
V_8 -> V_119 ( V_8 ) ;
}
} else if ( V_144 & V_190 ) {
F_65 ( V_8 ) = V_123 ;
F_43 ( V_8 ) = V_121 ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_20 ,
( int ) ( V_144 & V_186 ) ,
F_4 ( V_123 ) ) ;
if ( V_15 -> V_191 )
F_49 ( V_15 -> V_191 ) ;
F_16 ( V_120 , V_37 ) ;
} else {
F_62 ( V_179 , V_6 -> V_45 -> V_46 ,
L_21 ,
F_3 ( F_43 ( V_8 ) ) , V_144 ) ;
F_16 ( V_120 , V_37 ) ;
}
}
static int F_66 ( struct V_192 * V_193 ,
unsigned int V_139 ,
struct V_122 * V_75 )
{
struct V_6 * V_6 = F_67 ( V_193 ) ;
int V_36 = 0 ;
switch ( V_75 -> V_125 . type ) {
case V_194 :
F_54 ( V_6 , V_139 , V_75 ) ;
break;
case V_195 :
F_55 ( V_6 , V_75 ) ;
break;
case V_196 :
F_63 ( V_6 , V_75 ) ;
break;
case V_197 :
case V_198 :
V_36 = F_51 ( V_6 , V_75 ) ;
break;
case V_199 :
V_36 = F_46 ( V_6 , V_75 ) ;
break;
default:
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_22 ,
V_75 -> V_125 . type ) ;
break;
}
return V_36 ;
}
int F_68 ( struct V_6 * V_6 , int V_200 )
{
unsigned int V_201 = 0 ;
unsigned int V_77 , V_139 ;
unsigned int V_202 ;
for ( V_77 = 0 ; V_77 < V_6 -> V_203 ; V_77 ++ ) {
V_139 = V_77 + V_6 -> V_142 + V_6 -> V_143 ;
V_202 = F_69 ( & V_6 -> V_204 [ V_139 ] ,
F_66 ,
V_200 ) ;
V_201 += V_202 ;
}
return V_201 ;
}
static void F_48 ( struct V_6 * V_6 , int V_205 )
{
unsigned int V_77 ;
struct V_14 * V_15 ;
unsigned long V_37 = 0 ;
struct V_7 * V_8 ;
T_1 * V_120 ;
for ( V_77 = 0 ; V_77 < V_148 ; V_77 ++ ) {
if ( V_77 == V_205 )
continue;
V_8 = F_57 ( V_6 -> V_45 -> V_46 , V_77 ) ;
if ( ! V_8 )
continue;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
goto V_206;
}
F_44 ( V_8 ) = NULL ;
F_16 ( V_120 , V_37 ) ;
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
V_206:
V_8 -> V_106 = V_207 << 16 ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 , L_23
L_24 ) ;
if ( V_8 -> V_119 )
V_8 -> V_119 ( V_8 ) ;
}
}
void F_70 ( struct V_27 * V_28 ,
struct V_208 * V_75 )
{
T_2 V_144 ;
struct V_6 * V_6 = F_67 ( V_28 -> V_193 ) ;
struct V_14 * V_15 ;
struct V_7 * V_8 ;
unsigned long V_37 ;
T_1 * V_120 ;
F_56 ( & V_75 -> V_125 . V_11 , & V_144 ) ;
V_144 &= V_186 ;
if ( V_144 >= V_148 )
return;
V_8 = F_57 ( V_6 -> V_45 -> V_46 , V_144 ) ;
if ( ! V_8 )
return;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
goto V_209;
}
F_44 ( V_8 ) = NULL ;
F_16 ( V_120 , V_37 ) ;
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
V_209:
V_8 -> V_106 = V_210 << 16 ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 , L_25
L_26 ) ;
if ( V_8 -> V_119 )
V_8 -> V_119 ( V_8 ) ;
}
static inline int F_71 ( struct V_6 * V_6 , int V_11 ,
T_2 V_211 , T_3 * V_81 ,
struct V_14 * V_15 )
{
struct V_27 * V_28 = & V_6 -> V_35 [ 0 ] ;
unsigned long V_37 ;
F_13 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
if ( F_14 ( V_28 ) <= V_6 -> V_41 [ 0 ] )
F_10 ( V_6 , V_28 ) ;
if ( ! F_14 ( V_28 ) ) {
F_16 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
return 1 ;
}
F_72 ( V_28 , V_11 | V_187 ,
0 , V_211 , V_11 , V_81 , V_15 -> V_103 ,
V_6 -> V_60 . V_212 , V_6 -> V_60 . V_213 ) ;
F_16 ( & V_6 -> V_40 [ 0 ] , V_37 ) ;
return 0 ;
}
void F_73 ( struct V_6 * V_6 , T_2 V_103 )
{
int V_11 ;
struct V_14 * V_15 ;
T_1 * V_120 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
struct V_80 V_81 ;
enum V_214 V_215 ;
F_17 ( V_44 ,
V_6 -> V_45 -> V_46 ,
L_27 ,
V_103 ) ;
if ( V_6 -> V_216 )
return;
for ( V_11 = 0 ; V_11 < V_148 ; V_11 ++ ) {
V_8 = F_57 ( V_6 -> V_45 -> V_46 , V_11 ) ;
if ( ! V_8 )
continue;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 || V_15 -> V_103 != V_103 ) {
F_16 ( V_120 , V_37 ) ;
continue;
}
if ( F_43 ( V_8 ) == V_150 ) {
F_16 ( V_120 , V_37 ) ;
continue;
}
V_215 = F_43 ( V_8 ) ;
F_43 ( V_8 ) = V_150 ;
F_64 ( V_8 ) = V_217 ;
F_74 ( V_15 -> V_189 ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_28 ) ;
F_16 ( V_120 , V_37 ) ;
F_30 ( V_8 -> V_70 -> V_87 , & V_81 ) ;
if ( F_71 ( V_6 , V_11 ,
V_218 ,
V_81 . V_80 , V_15 ) ) {
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
if ( F_43 ( V_8 ) == V_150 )
F_43 ( V_8 ) = V_215 ;
F_16 ( V_120 , V_37 ) ;
}
}
}
void F_75 ( struct V_68 * V_69 )
{
int V_11 ;
struct V_14 * V_15 ;
T_1 * V_120 ;
unsigned long V_37 ;
struct V_7 * V_8 ;
struct V_80 V_81 ;
struct V_71 * V_219 = V_69 -> V_73 ;
struct V_50 * V_45 = V_219 -> V_220 ;
struct V_6 * V_6 = F_40 ( V_45 ) ;
struct V_68 * V_221 ;
enum V_214 V_215 ;
F_17 ( V_44 ,
V_6 -> V_45 -> V_46 , L_29
L_30 ,
V_69 -> V_222 , V_69 -> V_223 ,
V_69 -> V_103 ) ;
if ( V_6 -> V_216 )
return;
for ( V_11 = 0 ; V_11 < V_148 ; V_11 ++ ) {
V_8 = F_57 ( V_6 -> V_45 -> V_46 , V_11 ) ;
if ( ! V_8 )
continue;
V_221 = F_22 ( F_23 ( V_8 -> V_70 ) ) ;
if ( V_69 != V_221 )
continue;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 || V_69 != V_221 ) {
F_16 ( V_120 , V_37 ) ;
continue;
}
if ( F_43 ( V_8 ) == V_150 ) {
F_16 ( V_120 , V_37 ) ;
continue;
}
V_215 = F_43 ( V_8 ) ;
F_43 ( V_8 ) = V_150 ;
F_64 ( V_8 ) = V_217 ;
F_74 ( V_15 -> V_189 ) ;
F_17 ( V_44 ,
V_6 -> V_45 -> V_46 ,
L_31 ) ;
F_16 ( V_120 , V_37 ) ;
F_30 ( V_8 -> V_70 -> V_87 , & V_81 ) ;
if ( F_71 ( V_6 , V_11 ,
V_218 ,
V_81 . V_80 , V_15 ) ) {
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
if ( F_43 ( V_8 ) == V_150 )
F_43 ( V_8 ) = V_215 ;
F_16 ( V_120 , V_37 ) ;
}
}
}
int F_76 ( struct V_7 * V_8 )
{
struct V_50 * V_51 ;
struct V_6 * V_6 ;
struct V_14 * V_15 ;
struct V_68 * V_69 ;
T_1 * V_120 ;
unsigned long V_37 ;
int V_36 = V_224 ;
T_2 V_211 ;
struct V_80 V_81 ;
F_77 ( V_225 ) ;
F_78 ( V_8 ) ;
V_51 = F_38 ( V_8 -> V_70 -> V_46 ) ;
V_6 = F_40 ( V_51 ) ;
V_69 = F_22 ( F_23 ( V_8 -> V_70 ) ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_32 ,
V_69 -> V_103 , V_8 -> V_70 -> V_87 , V_8 -> V_10 -> V_11 ) ;
if ( V_51 -> V_1 != V_107 || ! ( V_51 -> V_108 ) ) {
V_36 = V_226 ;
goto V_227;
}
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
goto V_227;
}
V_15 -> V_189 = & V_225 ;
if ( F_43 ( V_8 ) == V_150 ) {
F_16 ( V_120 , V_37 ) ;
goto V_228;
}
F_43 ( V_8 ) = V_150 ;
F_64 ( V_8 ) = V_217 ;
F_16 ( V_120 , V_37 ) ;
if ( F_37 ( V_69 ) == 0 )
V_211 = V_229 ;
else
V_211 = V_218 ;
F_30 ( V_8 -> V_70 -> V_87 , & V_81 ) ;
if ( F_71 ( V_6 , V_8 -> V_10 -> V_11 , V_211 ,
V_81 . V_80 , V_15 ) ) {
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( V_15 )
V_15 -> V_189 = NULL ;
F_16 ( V_120 , V_37 ) ;
V_36 = V_226 ;
goto V_227;
}
V_228:
F_79 ( & V_225 ,
F_80
( 2 * V_6 -> V_60 . V_212 +
V_6 -> V_60 . V_213 ) ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
V_36 = V_226 ;
goto V_227;
}
V_15 -> V_189 = NULL ;
if ( F_43 ( V_8 ) == V_150 ) {
F_16 ( V_120 , V_37 ) ;
V_36 = V_226 ;
goto V_227;
}
if ( F_64 ( V_8 ) != V_151 )
V_36 = V_226 ;
F_44 ( V_8 ) = NULL ;
F_16 ( V_120 , V_37 ) ;
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
V_227:
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_33 ,
( V_36 == V_224 ) ?
L_34 : L_35 ) ;
return V_36 ;
}
static inline int F_81 ( struct V_6 * V_6 ,
struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_27 * V_28 = & V_6 -> V_35 [ 0 ] ;
struct V_80 V_81 ;
int V_36 = 0 ;
unsigned long V_78 ;
F_13 ( & V_6 -> V_40 [ 0 ] , V_78 ) ;
if ( F_14 ( V_28 ) <= V_6 -> V_41 [ 0 ] )
F_10 ( V_6 , V_28 ) ;
if ( ! F_14 ( V_28 ) ) {
V_36 = - V_42 ;
goto V_230;
}
F_30 ( V_8 -> V_70 -> V_87 , & V_81 ) ;
F_72 ( V_28 , V_8 -> V_10 -> V_11 | V_190 ,
0 , V_231 , V_43 ,
V_81 . V_80 , V_15 -> V_103 ,
V_6 -> V_60 . V_212 , V_6 -> V_60 . V_213 ) ;
V_230:
F_16 ( & V_6 -> V_40 [ 0 ] , V_78 ) ;
return V_36 ;
}
static int F_82 ( struct V_6 * V_6 ,
struct V_7 * V_232 )
{
int V_11 ;
struct V_14 * V_15 ;
T_1 * V_120 ;
unsigned long V_37 ;
int V_36 = 0 ;
struct V_7 * V_8 ;
struct V_80 V_81 ;
struct V_157 * V_233 = V_232 -> V_70 ;
F_77 ( V_225 ) ;
for ( V_11 = 0 ; V_11 < V_148 ; V_11 ++ ) {
V_8 = F_57 ( V_6 -> V_45 -> V_46 , V_11 ) ;
if ( ! V_8 || V_8 == V_232 || V_8 -> V_70 != V_233 )
continue;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 || V_8 -> V_70 != V_233 ) {
F_16 ( V_120 , V_37 ) ;
continue;
}
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_36 ,
F_3 ( F_43 ( V_8 ) ) ) ;
F_74 ( F_43 ( V_8 ) != V_150 ) ;
F_64 ( V_8 ) = V_217 ;
V_15 -> V_189 = & V_225 ;
F_16 ( V_120 , V_37 ) ;
F_30 ( V_8 -> V_70 -> V_87 , & V_81 ) ;
if ( F_71 ( V_6 , V_11 ,
V_218 ,
V_81 . V_80 , V_15 ) ) {
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( V_15 )
V_15 -> V_189 = NULL ;
F_16 ( V_120 , V_37 ) ;
V_36 = 1 ;
goto V_234;
}
F_79 ( & V_225 ,
F_80
( V_6 -> V_60 . V_213 ) ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
V_36 = 1 ;
goto V_234;
}
V_15 -> V_189 = NULL ;
if ( F_43 ( V_8 ) == V_150 ) {
F_16 ( V_120 , V_37 ) ;
V_36 = 1 ;
goto V_234;
}
F_44 ( V_8 ) = NULL ;
F_16 ( V_120 , V_37 ) ;
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
}
V_234:
return V_36 ;
}
int F_83 ( struct V_7 * V_8 )
{
struct V_50 * V_51 ;
struct V_6 * V_6 ;
struct V_14 * V_15 ;
struct V_68 * V_69 ;
int V_4 ;
int V_36 = V_226 ;
T_1 * V_120 ;
unsigned long V_37 ;
F_77 ( V_225 ) ;
F_78 ( V_8 ) ;
V_51 = F_38 ( V_8 -> V_70 -> V_46 ) ;
V_6 = F_40 ( V_51 ) ;
V_69 = F_22 ( F_23 ( V_8 -> V_70 ) ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_37 ,
V_69 -> V_103 , V_8 -> V_70 -> V_87 ) ;
if ( V_51 -> V_1 != V_107 || ! ( V_51 -> V_108 ) )
goto V_235;
if ( F_37 ( V_69 ) )
goto V_235;
V_120 = F_5 ( V_6 , V_8 ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 ) {
V_15 = F_41 ( V_6 -> V_110 , V_111 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
goto V_235;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_103 = V_69 -> V_103 ;
F_44 ( V_8 ) = ( char * ) V_15 ;
}
V_15 -> V_191 = & V_225 ;
F_43 ( V_8 ) = V_118 ;
F_65 ( V_8 ) = V_217 ;
F_16 ( V_120 , V_37 ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 , L_38 ,
V_8 -> V_10 -> V_11 ) ;
if ( F_81 ( V_6 , V_8 , V_15 ) ) {
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( V_15 )
V_15 -> V_191 = NULL ;
goto V_236;
}
F_79 ( & V_225 ,
F_80 ( V_237 ) ) ;
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( ! V_15 ) {
F_16 ( V_120 , V_37 ) ;
goto V_235;
}
V_15 -> V_191 = NULL ;
V_4 = F_65 ( V_8 ) ;
F_16 ( V_120 , V_37 ) ;
if ( V_4 == V_217 ) {
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_39 ) ;
goto V_235;
}
if ( V_4 != V_151 ) {
F_13 ( V_120 , V_37 ) ;
F_17 ( V_44 ,
V_6 -> V_45 -> V_46 ,
L_40 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
goto V_236;
}
if ( F_82 ( V_6 , V_8 ) ) {
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_41
L_42 ) ;
goto V_236;
}
F_13 ( V_120 , V_37 ) ;
V_15 = (struct V_14 * ) F_44 ( V_8 ) ;
if ( V_15 )
V_36 = V_224 ;
V_236:
if ( V_15 )
F_44 ( V_8 ) = NULL ;
F_16 ( V_120 , V_37 ) ;
if ( V_15 ) {
F_6 ( V_6 , V_15 , V_8 ) ;
F_9 ( V_15 , V_6 -> V_110 ) ;
}
V_235:
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_43 ,
( V_36 == V_224 ) ?
L_34 : L_35 ) ;
return V_36 ;
}
int F_84 ( struct V_238 * V_239 )
{
struct V_50 * V_51 ;
struct V_6 * V_6 ;
int V_36 = V_224 ;
V_51 = F_38 ( V_239 ) ;
V_6 = F_40 ( V_51 ) ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_44 ) ;
if ( V_51 -> V_240 . V_241 ( V_51 ) )
V_36 = V_226 ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_45 ,
( V_36 == V_224 ) ?
L_34 : L_35 ) ;
return V_36 ;
}
int F_85 ( struct V_7 * V_8 )
{
int V_36 ;
unsigned long V_242 ;
struct V_238 * V_239 = V_8 -> V_70 -> V_46 ;
struct V_50 * V_51 = F_38 ( V_239 ) ;
V_36 = F_84 ( V_239 ) ;
if ( V_36 == V_224 ) {
V_242 = V_243 + V_244 * V_245 ;
V_36 = V_226 ;
while ( F_86 ( V_243 , V_242 ) ) {
if ( ( V_51 -> V_1 == V_107 ) &&
( V_51 -> V_108 ) ) {
V_36 = V_224 ;
break;
}
F_87 ( 1 ) ;
}
}
return V_36 ;
}
void F_88 ( struct V_50 * V_51 )
{
int V_246 = 0 ;
unsigned long V_37 ;
enum V_247 V_248 ;
struct V_6 * V_6 = F_40 ( V_51 ) ;
F_77 ( V_130 ) ;
F_13 ( & V_6 -> V_126 , V_37 ) ;
V_6 -> V_130 = & V_130 ;
V_248 = V_6 -> V_1 ;
V_6 -> V_1 = V_127 ;
F_89 ( V_6 , V_6 -> V_55 . V_249 ) ;
F_16 ( & V_6 -> V_126 , V_37 ) ;
V_246 = F_11 ( V_6 ) ;
if ( V_246 ) {
F_13 ( & V_6 -> V_126 , V_37 ) ;
if ( V_6 -> V_1 == V_127 )
V_6 -> V_1 = V_248 ;
V_6 -> V_130 = NULL ;
F_16 ( & V_6 -> V_126 , V_37 ) ;
return;
}
F_79 ( & V_130 ,
F_80 ( V_250 ) ) ;
F_13 ( & V_6 -> V_126 , V_37 ) ;
V_6 -> V_130 = NULL ;
F_17 ( V_44 , V_6 -> V_45 -> V_46 ,
L_46 ,
( V_6 -> V_1 == V_128 ) ?
L_34 : L_35 ) ;
F_16 ( & V_6 -> V_126 , V_37 ) ;
}
void F_90 ( struct V_50 * V_51 )
{
unsigned long V_37 ;
enum V_247 V_248 ;
struct V_6 * V_6 = F_40 ( V_51 ) ;
F_13 ( & V_6 -> V_126 , V_37 ) ;
V_248 = V_6 -> V_1 ;
V_6 -> V_1 = V_127 ;
F_89 ( V_6 , V_6 -> V_55 . V_249 ) ;
F_16 ( & V_6 -> V_126 , V_37 ) ;
if ( F_11 ( V_6 ) ) {
F_13 ( & V_6 -> V_126 , V_37 ) ;
if ( V_6 -> V_1 == V_127 )
V_6 -> V_1 = V_248 ;
F_16 ( & V_6 -> V_126 , V_37 ) ;
}
}
void F_91 ( struct V_50 * V_51 )
{
}
void F_92 ( struct V_50 * V_51 , T_2 V_251 , T_2 V_252 )
{
struct V_6 * V_6 = F_40 ( V_51 ) ;
if ( V_251 )
goto V_253;
if ( V_252 ) {
F_73 ( V_6 , V_252 ) ;
goto V_253;
}
if ( ! V_6 -> V_216 )
F_90 ( V_51 ) ;
else
F_88 ( V_51 ) ;
V_253:
F_93 ( V_51 , V_251 , V_252 ) ;
}
