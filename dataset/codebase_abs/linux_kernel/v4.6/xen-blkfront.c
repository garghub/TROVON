static int F_1 ( struct V_1 * V_2 )
{
unsigned long free = V_2 -> V_3 ;
F_2 ( free >= F_3 ( V_2 -> V_4 ) ) ;
V_2 -> V_3 = V_2 -> V_5 [ free ] . V_6 . V_7 . V_8 . V_9 ;
V_2 -> V_5 [ free ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffee ;
return free ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
if ( V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_9 != V_9 )
return - V_10 ;
if ( V_2 -> V_5 [ V_9 ] . V_11 == NULL )
return - V_10 ;
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_9 = V_2 -> V_3 ;
V_2 -> V_5 [ V_9 ] . V_11 = NULL ;
V_2 -> V_3 = V_9 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_15 * V_16 ;
struct V_17 * V_18 , * V_19 ;
int V_20 = 0 ;
while ( V_20 < V_12 ) {
V_18 = F_6 ( sizeof( struct V_17 ) , V_21 ) ;
if ( ! V_18 )
goto V_22;
if ( V_14 -> V_23 ) {
V_16 = F_7 ( V_21 ) ;
if ( ! V_16 ) {
F_8 ( V_18 ) ;
goto V_22;
}
V_18 -> V_15 = V_16 ;
}
V_18 -> V_24 = V_25 ;
F_9 ( & V_18 -> V_26 , & V_2 -> V_27 ) ;
V_20 ++ ;
}
return 0 ;
V_22:
F_10 (gnt_list_entry, n,
&rinfo->grants, node) {
F_11 ( & V_18 -> V_26 ) ;
if ( V_14 -> V_23 )
F_12 ( V_18 -> V_15 ) ;
F_8 ( V_18 ) ;
V_20 -- ;
}
F_2 ( V_20 != 0 ) ;
return - V_28 ;
}
static struct V_17 * F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
F_2 ( F_14 ( & V_2 -> V_27 ) ) ;
V_18 = F_15 ( & V_2 -> V_27 , struct V_17 ,
V_26 ) ;
F_11 ( & V_18 -> V_26 ) ;
if ( V_18 -> V_24 != V_25 )
V_2 -> V_29 -- ;
return V_18 ;
}
static inline void F_16 ( const struct V_17 * V_18 ,
const struct V_13 * V_14 )
{
F_17 ( V_18 -> V_24 ,
V_14 -> V_30 -> V_31 ,
V_18 -> V_15 ,
0 ) ;
}
static struct V_17 * F_18 ( T_1 * V_32 ,
unsigned long V_33 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 = F_13 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_18 -> V_24 != V_25 )
return V_18 ;
V_18 -> V_24 = F_19 ( V_32 ) ;
F_2 ( V_18 -> V_24 == - V_34 ) ;
if ( V_14 -> V_23 )
F_16 ( V_18 , V_14 ) ;
else {
F_20 ( V_18 -> V_24 ,
V_14 -> V_30 -> V_31 ,
V_33 , 0 ) ;
}
return V_18 ;
}
static struct V_17 * F_21 ( T_1 * V_32 ,
struct V_1 * V_2 )
{
struct V_17 * V_18 = F_13 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_18 -> V_24 != V_25 )
return V_18 ;
V_18 -> V_24 = F_19 ( V_32 ) ;
F_2 ( V_18 -> V_24 == - V_34 ) ;
if ( ! V_14 -> V_23 ) {
struct V_15 * V_35 ;
F_2 ( F_14 ( & V_2 -> V_36 ) ) ;
V_35 = F_15 ( & V_2 -> V_36 ,
struct V_15 , V_37 ) ;
F_11 ( & V_35 -> V_37 ) ;
V_18 -> V_15 = V_35 ;
}
F_16 ( V_18 , V_14 ) ;
return V_18 ;
}
static const char * F_22 ( int V_38 )
{
static const char * const V_39 [] = {
[ V_40 ] = L_1 ,
[ V_41 ] = L_2 ,
[ V_42 ] = L_3 ,
[ V_43 ] = L_4 ,
[ V_44 ] = L_5 } ;
if ( V_38 < 0 || V_38 >= F_23 ( V_39 ) )
return L_6 ;
if ( ! V_39 [ V_38 ] )
return L_7 ;
return V_39 [ V_38 ] ;
}
static int F_24 ( unsigned int V_45 , unsigned int V_46 )
{
unsigned int V_47 = V_45 + V_46 ;
int V_48 ;
if ( V_47 > V_49 ) {
unsigned long * V_50 , * V_51 ;
V_50 = F_25 ( F_26 ( V_47 ) , sizeof( * V_50 ) ,
V_52 ) ;
if ( V_50 == NULL )
return - V_28 ;
F_27 ( & V_53 ) ;
if ( V_47 > V_49 ) {
V_51 = V_54 ;
memcpy ( V_50 , V_54 ,
F_26 ( V_49 ) * sizeof( * V_50 ) ) ;
V_54 = V_50 ;
V_49 = F_26 ( V_47 ) * V_55 ;
} else
V_51 = V_50 ;
F_28 ( & V_53 ) ;
F_8 ( V_51 ) ;
}
F_27 ( & V_53 ) ;
if ( F_29 ( V_54 , V_47 , V_45 ) >= V_47 ) {
F_30 ( V_54 , V_45 , V_46 ) ;
V_48 = 0 ;
} else
V_48 = - V_56 ;
F_28 ( & V_53 ) ;
return V_48 ;
}
static void F_31 ( unsigned int V_45 , unsigned int V_46 )
{
unsigned int V_47 = V_45 + V_46 ;
F_2 ( V_47 > V_49 ) ;
F_27 ( & V_53 ) ;
F_32 ( V_54 , V_45 , V_46 ) ;
F_28 ( & V_53 ) ;
}
static void F_33 ( void * V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_57 ;
F_34 ( & V_2 -> V_58 ) ;
}
static int F_35 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
T_2 V_63 = F_36 ( V_60 -> V_64 ) ;
T_2 V_65 = V_63 ;
V_62 -> V_66 = 0xff ;
V_62 -> V_67 = 0x3f ;
F_37 ( V_65 , V_62 -> V_66 * V_62 -> V_67 ) ;
V_62 -> V_65 = V_65 ;
if ( ( T_2 ) ( V_62 -> V_65 + 1 ) * V_62 -> V_66 * V_62 -> V_67 < V_63 )
V_62 -> V_65 = 0xffff ;
return 0 ;
}
static int F_38 ( struct V_59 * V_68 , T_3 V_69 ,
unsigned V_70 , unsigned long V_71 )
{
struct V_13 * V_14 = V_68 -> V_64 -> V_72 ;
int V_20 ;
F_39 ( & V_14 -> V_30 -> V_73 , L_8 ,
V_70 , ( long ) V_71 ) ;
switch ( V_70 ) {
case V_74 :
F_39 ( & V_14 -> V_30 -> V_73 , L_9 ) ;
for ( V_20 = 0 ; V_20 < sizeof( struct V_75 ) ; V_20 ++ )
if ( F_40 ( 0 , ( char V_76 * ) ( V_71 + V_20 ) ) )
return - V_77 ;
return 0 ;
case V_78 : {
struct V_79 * V_80 = V_14 -> V_80 ;
if ( V_80 -> V_81 & V_82 )
return 0 ;
return - V_10 ;
}
default:
return - V_10 ;
}
return 0 ;
}
static unsigned long F_41 ( struct V_1 * V_2 ,
struct V_11 * V_6 ,
struct V_83 * * V_84 )
{
unsigned long V_9 ;
* V_84 = F_42 ( & V_2 -> V_85 , V_2 -> V_85 . V_86 ) ;
V_2 -> V_85 . V_86 ++ ;
V_9 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_11 = V_6 ;
V_2 -> V_5 [ V_9 ] . V_87 = V_88 ;
V_2 -> V_5 [ V_9 ] . V_89 = V_90 ;
( * V_84 ) -> V_7 . V_8 . V_9 = V_9 ;
return V_9 ;
}
static int F_43 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_83 * V_84 ;
unsigned long V_9 ;
V_9 = F_41 ( V_2 , V_6 , & V_84 ) ;
V_84 -> V_91 = V_44 ;
V_84 -> V_7 . V_92 . V_93 = F_44 ( V_6 ) ;
V_84 -> V_7 . V_92 . V_9 = V_9 ;
V_84 -> V_7 . V_92 . V_94 = ( V_95 ) F_45 ( V_6 ) ;
if ( ( V_6 -> V_96 & V_97 ) && V_14 -> V_98 )
V_84 -> V_7 . V_92 . V_99 = V_100 ;
else
V_84 -> V_7 . V_92 . V_99 = 0 ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_84 ;
return 0 ;
}
static void F_46 ( unsigned long V_33 , unsigned int V_101 ,
unsigned int V_102 , void * V_103 )
{
struct V_104 * V_105 = V_103 ;
int V_19 , V_106 ;
struct V_17 * V_18 ;
unsigned int V_107 , V_108 ;
unsigned int V_109 = V_105 -> V_109 ;
struct V_83 * V_84 = V_105 -> V_84 ;
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_110 * V_5 = & V_2 -> V_5 [ V_105 -> V_9 ] ;
if ( F_47 ( V_105 -> V_111 &&
V_109 >= V_112 ) ) {
V_109 -= V_112 ;
V_84 = V_105 -> V_113 ;
}
if ( ( V_84 -> V_91 == V_114 ) &&
( V_109 % V_115 == 0 ) ) {
if ( V_105 -> V_116 )
F_48 ( V_105 -> V_116 ) ;
V_19 = V_109 / V_115 ;
V_18 = F_21 ( & V_105 -> V_32 , V_2 ) ;
V_5 -> V_117 [ V_19 ] = V_18 ;
V_105 -> V_116 = F_49 ( V_18 -> V_15 ) ;
V_84 -> V_7 . V_118 . V_119 [ V_19 ] = V_18 -> V_24 ;
}
V_18 = F_18 ( & V_105 -> V_32 , V_33 , V_2 ) ;
V_106 = V_18 -> V_24 ;
V_5 -> V_120 [ V_105 -> V_109 ] = V_18 ;
if ( V_105 -> V_121 ) {
void * V_122 ;
V_122 = F_49 ( V_18 -> V_15 ) ;
memcpy ( V_122 + V_101 ,
V_105 -> V_123 + V_105 -> V_124 ,
V_102 ) ;
F_48 ( V_122 ) ;
V_105 -> V_124 += V_102 ;
}
V_107 = V_101 >> 9 ;
V_108 = V_107 + ( V_102 >> 9 ) - 1 ;
if ( V_84 -> V_91 != V_114 ) {
V_84 -> V_7 . V_8 . V_125 [ V_109 ] =
(struct V_126 ) {
. V_24 = V_106 ,
. V_127 = V_107 ,
. V_128 = V_108 } ;
} else {
V_105 -> V_116 [ V_109 % V_115 ] =
(struct V_126 ) {
. V_24 = V_106 ,
. V_127 = V_107 ,
. V_128 = V_108 } ;
}
( V_105 -> V_109 ) ++ ;
}
static void F_50 ( struct V_83 * V_129 ,
struct V_83 * V_130 )
{
T_4 V_131 = V_129 -> V_7 . V_8 . V_131 ;
V_129 -> V_7 . V_8 . V_131 = V_112 ;
V_130 -> V_7 . V_8 . V_131 = V_131 - V_112 ;
V_130 -> V_7 . V_8 . V_94 = V_129 -> V_7 . V_8 . V_94 +
( V_112 * V_132 ) / 512 ;
V_130 -> V_7 . V_8 . V_133 = V_129 -> V_7 . V_8 . V_133 ;
V_130 -> V_91 = V_129 -> V_91 ;
}
static int F_51 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_83 * V_84 , * V_113 = NULL ;
unsigned long V_9 , V_134 = V_90 ;
bool V_111 = false ;
int V_20 ;
struct V_104 V_105 = {
. V_109 = 0 ,
. V_116 = NULL ,
. V_2 = V_2 ,
. V_121 = F_52 ( V_6 ) && V_14 -> V_23 ,
} ;
struct V_135 * V_136 ;
int V_137 , V_138 , V_139 ;
V_138 = V_6 -> V_140 * V_141 ;
if ( V_138 > V_112 )
V_138 += F_53 ( V_138 ) ;
if ( V_138 > 0 )
if ( F_54 ( V_138 , & V_105 . V_32 ) < 0 ) {
F_55 (
& V_2 -> V_142 ,
F_33 ,
V_2 ,
V_138 ) ;
return 1 ;
}
V_9 = F_41 ( V_2 , V_6 , & V_84 ) ;
V_137 = F_56 ( V_6 -> V_143 , V_6 , V_2 -> V_5 [ V_9 ] . V_136 ) ;
V_139 = 0 ;
F_57 (rinfo->shadow[id].sg, sg, num_sg, i)
V_139 += F_58 ( V_136 -> V_101 , V_136 -> V_144 ) ;
V_111 = V_14 -> V_145 == 0 &&
V_139 > V_112 ;
F_2 ( ! V_146 && V_111 ) ;
V_2 -> V_5 [ V_9 ] . V_137 = V_137 ;
if ( V_139 > V_112 &&
F_59 ( ! V_111 ) ) {
F_2 ( V_6 -> V_96 & ( V_147 | V_148 ) ) ;
V_84 -> V_91 = V_114 ;
V_84 -> V_7 . V_118 . V_149 = F_52 ( V_6 ) ?
V_41 : V_40 ;
V_84 -> V_7 . V_118 . V_94 = ( V_95 ) F_45 ( V_6 ) ;
V_84 -> V_7 . V_118 . V_133 = V_14 -> V_133 ;
V_84 -> V_7 . V_118 . V_131 = V_139 ;
} else {
V_84 -> V_7 . V_8 . V_94 = ( V_95 ) F_45 ( V_6 ) ;
V_84 -> V_7 . V_8 . V_133 = V_14 -> V_133 ;
V_84 -> V_91 = F_52 ( V_6 ) ?
V_41 : V_40 ;
if ( V_6 -> V_96 & ( V_147 | V_148 ) ) {
switch ( V_14 -> V_150 &
( ( V_147 | V_148 ) ) ) {
case V_147 | V_148 :
V_84 -> V_91 =
V_42 ;
break;
case V_147 :
V_84 -> V_91 =
V_43 ;
break;
default:
V_84 -> V_91 = 0 ;
}
}
V_84 -> V_7 . V_8 . V_131 = V_139 ;
if ( F_47 ( V_111 ) ) {
V_134 = F_41 ( V_2 , V_6 ,
& V_113 ) ;
V_2 -> V_5 [ V_134 ] . V_137 = 0 ;
F_50 ( V_84 , V_113 ) ;
V_2 -> V_5 [ V_134 ] . V_89 = V_9 ;
V_2 -> V_5 [ V_9 ] . V_89 = V_134 ;
}
}
V_105 . V_84 = V_84 ;
V_105 . V_9 = V_9 ;
V_105 . V_111 = V_111 ;
if ( F_47 ( V_111 ) )
V_105 . V_113 = V_113 ;
F_57 (rinfo->shadow[id].sg, sg, num_sg, i) {
F_2 ( V_136 -> V_101 + V_136 -> V_144 > V_151 ) ;
if ( V_105 . V_121 ) {
V_105 . V_124 = V_136 -> V_101 ;
V_105 . V_123 = F_49 ( F_60 ( V_136 ) ) ;
}
F_61 ( F_60 ( V_136 ) ,
V_136 -> V_101 ,
V_136 -> V_144 ,
F_46 ,
& V_105 ) ;
if ( V_105 . V_121 )
F_48 ( V_105 . V_123 ) ;
}
if ( V_105 . V_116 )
F_48 ( V_105 . V_116 ) ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_84 ;
if ( F_47 ( V_111 ) )
V_2 -> V_5 [ V_134 ] . V_6 = * V_113 ;
if ( V_138 > 0 )
F_62 ( V_105 . V_32 ) ;
return 0 ;
}
static int F_63 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
if ( F_47 ( V_2 -> V_4 -> V_152 != V_153 ) )
return 1 ;
if ( F_47 ( V_6 -> V_96 & ( V_154 | V_97 ) ) )
return F_43 ( V_6 , V_2 ) ;
else
return F_51 ( V_6 , V_2 ) ;
}
static inline void F_64 ( struct V_1 * V_2 )
{
int V_155 ;
F_65 ( & V_2 -> V_85 , V_155 ) ;
if ( V_155 )
F_66 ( V_2 -> V_156 ) ;
}
static inline bool F_67 ( struct V_11 * V_6 ,
struct V_13 * V_14 )
{
return ( ( V_6 -> V_157 != V_158 ) ||
( ( V_6 -> V_96 & V_147 ) &&
! ( V_14 -> V_150 & V_147 ) ) ||
( ( V_6 -> V_96 & V_148 ) &&
! ( V_14 -> V_150 & V_148 ) ) ) ;
}
static int F_68 ( struct V_159 * V_160 ,
const struct V_161 * V_162 )
{
unsigned long V_81 ;
struct V_1 * V_2 = (struct V_1 * ) V_160 -> V_163 ;
F_69 ( V_162 -> V_164 ) ;
F_70 ( & V_2 -> V_165 , V_81 ) ;
if ( F_71 ( & V_2 -> V_85 ) )
goto V_166;
if ( F_67 ( V_162 -> V_164 , V_2 -> V_4 ) )
goto V_167;
if ( F_63 ( V_162 -> V_164 , V_2 ) )
goto V_166;
F_64 ( V_2 ) ;
F_72 ( & V_2 -> V_165 , V_81 ) ;
return V_168 ;
V_167:
F_72 ( & V_2 -> V_165 , V_81 ) ;
return V_169 ;
V_166:
F_72 ( & V_2 -> V_165 , V_81 ) ;
F_73 ( V_160 ) ;
return V_170 ;
}
static int F_74 ( struct V_159 * V_160 , void * V_103 ,
unsigned int V_171 )
{
struct V_13 * V_14 = (struct V_13 * ) V_103 ;
F_2 ( V_14 -> V_172 <= V_171 ) ;
V_160 -> V_163 = & V_14 -> V_2 [ V_171 ] ;
return 0 ;
}
static int F_75 ( struct V_79 * V_80 , T_5 V_173 ,
unsigned int V_174 ,
unsigned int V_116 )
{
struct V_175 * V_164 ;
struct V_13 * V_14 = V_80 -> V_72 ;
memset ( & V_14 -> V_176 , 0 , sizeof( V_14 -> V_176 ) ) ;
V_14 -> V_176 . V_177 = & V_178 ;
V_14 -> V_176 . V_179 = V_14 -> V_172 ;
if ( V_146 && V_14 -> V_145 == 0 ) {
V_14 -> V_176 . V_180 = F_3 ( V_14 ) / 2 ;
} else
V_14 -> V_176 . V_180 = F_3 ( V_14 ) ;
V_14 -> V_176 . V_181 = V_182 ;
V_14 -> V_176 . V_81 = V_183 | V_184 ;
V_14 -> V_176 . V_185 = 0 ;
V_14 -> V_176 . V_163 = V_14 ;
if ( F_76 ( & V_14 -> V_176 ) )
return - V_10 ;
V_164 = F_77 ( & V_14 -> V_176 ) ;
if ( F_78 ( V_164 ) ) {
F_79 ( & V_14 -> V_176 ) ;
return F_80 ( V_164 ) ;
}
F_81 ( V_186 , V_164 ) ;
if ( V_14 -> V_187 ) {
F_81 ( V_188 , V_164 ) ;
F_82 ( V_164 , F_36 ( V_80 ) ) ;
V_164 -> V_189 . V_190 = V_14 -> V_190 ;
V_164 -> V_189 . V_191 = V_14 -> V_191 ;
if ( V_14 -> V_98 )
F_81 ( V_192 , V_164 ) ;
}
F_83 ( V_164 , V_173 ) ;
F_84 ( V_164 , V_174 ) ;
F_85 ( V_164 , ( V_116 * V_132 ) / 512 ) ;
F_86 ( V_164 , V_151 - 1 ) ;
F_87 ( V_164 , V_151 ) ;
F_88 ( V_164 , V_116 / V_141 ) ;
F_89 ( V_164 , 511 ) ;
F_90 ( V_164 , V_193 ) ;
V_80 -> V_194 = V_164 ;
return 0 ;
}
static const char * F_91 ( unsigned int V_150 )
{
switch ( V_150 & ( ( V_147 | V_148 ) ) ) {
case V_147 | V_148 :
return L_10 ;
case V_147 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_92 ( struct V_13 * V_14 )
{
F_93 ( V_14 -> V_164 , V_14 -> V_150 ) ;
F_94 ( L_13 ,
V_14 -> V_80 -> V_195 , F_91 ( V_14 -> V_150 ) ,
L_14 , V_14 -> V_23 ?
L_15 : L_16 , L_17 ,
V_14 -> V_145 ? L_15 : L_16 ) ;
}
static int F_95 ( int V_196 , int * V_45 , unsigned int * V_101 )
{
int V_197 ;
V_197 = F_96 ( V_196 ) ;
* V_45 = F_97 ( V_196 ) ;
switch ( V_197 ) {
case V_198 :
* V_101 = ( * V_45 / 64 ) + V_199 ;
* V_45 = ( ( * V_45 / 64 ) * V_200 ) +
V_201 ;
break;
case V_202 :
* V_101 = ( * V_45 / 64 ) + 2 + V_199 ;
* V_45 = ( ( ( * V_45 / 64 ) + 2 ) * V_200 ) +
V_201 ;
break;
case V_203 :
* V_101 = ( * V_45 / V_200 ) + V_204 ;
* V_45 = * V_45 + V_205 ;
break;
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
* V_101 = ( * V_45 / V_200 ) +
( ( V_197 - V_206 + 1 ) * 16 ) +
V_204 ;
* V_45 = * V_45 +
( ( V_197 - V_206 + 1 ) * 16 * V_200 ) +
V_205 ;
break;
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
* V_101 = ( * V_45 / V_200 ) +
( ( V_197 - V_213 + 8 ) * 16 ) +
V_204 ;
* V_45 = * V_45 +
( ( V_197 - V_213 + 8 ) * 16 * V_200 ) +
V_205 ;
break;
case V_221 :
* V_101 = * V_45 / V_200 ;
break;
default:
F_98 ( V_222 L_18
L_19 ) ;
return - V_223 ;
}
return 0 ;
}
static char * F_99 ( char * V_224 , unsigned int V_19 )
{
if ( V_19 >= 26 )
V_224 = F_99 ( V_224 , V_19 / 26 - 1 ) ;
* V_224 = 'a' + V_19 % 26 ;
return V_224 + 1 ;
}
static int F_100 ( V_95 V_225 ,
struct V_13 * V_14 ,
T_5 V_226 , T_5 V_173 ,
unsigned int V_174 )
{
struct V_79 * V_80 ;
int V_49 = 1 ;
int V_227 ;
unsigned int V_101 ;
int V_45 ;
int V_228 ;
char * V_224 ;
F_2 ( V_14 -> V_80 != NULL ) ;
F_2 ( V_14 -> V_164 != NULL ) ;
if ( ( V_14 -> V_196 >> V_229 ) > 1 ) {
F_98 ( V_222 L_20 , V_14 -> V_196 ) ;
return - V_223 ;
}
if ( ! F_101 ( V_14 -> V_196 ) ) {
V_227 = F_95 ( V_14 -> V_196 , & V_45 , & V_101 ) ;
if ( V_227 )
return V_227 ;
V_228 = V_200 ;
} else {
V_45 = F_102 ( V_14 -> V_196 ) ;
V_228 = V_230 ;
V_101 = V_45 / V_228 ;
if ( F_103 () && V_101 < V_199 + 4 )
F_98 ( V_222 L_21
L_22
L_23 , V_14 -> V_196 ) ;
}
if ( V_45 >> V_231 ) {
F_104 ( L_24 ,
V_14 -> V_196 , V_45 ) ;
return - V_223 ;
}
if ( ( V_45 % V_228 ) == 0 )
V_49 = V_228 ;
V_227 = F_24 ( V_45 , V_49 ) ;
if ( V_227 )
goto V_232;
V_227 = - V_223 ;
V_80 = F_105 ( V_49 ) ;
if ( V_80 == NULL )
goto V_233;
strcpy ( V_80 -> V_195 , V_234 ) ;
V_224 = F_99 ( V_80 -> V_195 + sizeof( V_234 ) - 1 , V_101 ) ;
F_2 ( V_224 >= V_80 -> V_195 + V_235 ) ;
if ( V_49 > 1 )
* V_224 = 0 ;
else
snprintf ( V_224 , V_80 -> V_195 + V_235 - V_224 ,
L_25 , V_45 & ( V_228 - 1 ) ) ;
V_80 -> V_197 = V_221 ;
V_80 -> V_236 = V_45 ;
V_80 -> V_237 = & V_238 ;
V_80 -> V_72 = V_14 ;
V_80 -> V_239 = & ( V_14 -> V_30 -> V_73 ) ;
F_106 ( V_80 , V_225 ) ;
if ( F_75 ( V_80 , V_173 , V_174 ,
V_14 -> V_145 ? :
V_112 ) ) {
F_107 ( V_80 ) ;
goto V_233;
}
V_14 -> V_164 = V_80 -> V_194 ;
V_14 -> V_80 = V_80 ;
F_92 ( V_14 ) ;
if ( V_226 & V_240 )
F_108 ( V_80 , 1 ) ;
if ( V_226 & V_241 )
V_80 -> V_81 |= V_242 ;
if ( V_226 & V_243 )
V_80 -> V_81 |= V_82 ;
return 0 ;
V_233:
F_31 ( V_45 , V_49 ) ;
V_232:
return V_227 ;
}
static void F_109 ( struct V_13 * V_14 )
{
unsigned int V_45 , V_49 , V_20 ;
if ( V_14 -> V_164 == NULL )
return;
F_110 ( V_14 -> V_164 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
F_111 ( & V_2 -> V_142 ) ;
F_112 ( & V_2 -> V_58 ) ;
}
F_107 ( V_14 -> V_80 ) ;
V_45 = V_14 -> V_80 -> V_236 ;
V_49 = V_14 -> V_80 -> V_54 ;
F_31 ( V_45 , V_49 ) ;
F_113 ( V_14 -> V_164 ) ;
F_79 ( & V_14 -> V_176 ) ;
V_14 -> V_164 = NULL ;
F_114 ( V_14 -> V_80 ) ;
V_14 -> V_80 = NULL ;
}
static inline void F_115 ( struct V_1 * V_2 )
{
if ( ! F_71 ( & V_2 -> V_85 ) )
F_116 ( V_2 -> V_4 -> V_164 , true ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
unsigned long V_81 ;
F_70 ( & V_2 -> V_165 , V_81 ) ;
F_115 ( V_2 ) ;
F_72 ( & V_2 -> V_165 , V_81 ) ;
}
static void F_118 ( struct V_244 * V_58 )
{
struct V_1 * V_2 = F_119 ( V_58 , struct V_1 , V_58 ) ;
if ( V_2 -> V_4 -> V_152 == V_153 )
F_117 ( V_2 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_17 * V_245 , * V_19 ;
struct V_13 * V_14 = V_2 -> V_4 ;
int V_20 , V_246 , V_247 ;
if ( ! F_14 ( & V_2 -> V_36 ) ) {
struct V_15 * V_35 , * V_19 ;
F_2 ( V_14 -> V_23 ) ;
F_10 (indirect_page, n, &rinfo->indirect_pages, lru) {
F_11 ( & V_35 -> V_37 ) ;
F_12 ( V_35 ) ;
}
}
if ( ! F_14 ( & V_2 -> V_27 ) ) {
F_10 (persistent_gnt, n,
&rinfo->grants, node) {
F_11 ( & V_245 -> V_26 ) ;
if ( V_245 -> V_24 != V_25 ) {
F_121 ( V_245 -> V_24 ,
0 , 0UL ) ;
V_2 -> V_29 -- ;
}
if ( V_14 -> V_23 )
F_12 ( V_245 -> V_15 ) ;
F_8 ( V_245 ) ;
}
}
F_2 ( V_2 -> V_29 != 0 ) ;
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ ) {
if ( ! V_2 -> V_5 [ V_20 ] . V_11 )
goto V_248;
V_247 = V_2 -> V_5 [ V_20 ] . V_6 . V_91 == V_114 ?
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_118 . V_131 :
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_8 . V_131 ;
for ( V_246 = 0 ; V_246 < V_247 ; V_246 ++ ) {
V_245 = V_2 -> V_5 [ V_20 ] . V_120 [ V_246 ] ;
F_121 ( V_245 -> V_24 , 0 , 0UL ) ;
if ( V_14 -> V_23 )
F_12 ( V_245 -> V_15 ) ;
F_8 ( V_245 ) ;
}
if ( V_2 -> V_5 [ V_20 ] . V_6 . V_91 != V_114 )
goto V_248;
for ( V_246 = 0 ; V_246 < F_53 ( V_247 ) ; V_246 ++ ) {
V_245 = V_2 -> V_5 [ V_20 ] . V_117 [ V_246 ] ;
F_121 ( V_245 -> V_24 , 0 , 0UL ) ;
F_12 ( V_245 -> V_15 ) ;
F_8 ( V_245 ) ;
}
V_248:
F_8 ( V_2 -> V_5 [ V_20 ] . V_120 ) ;
V_2 -> V_5 [ V_20 ] . V_120 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_117 ) ;
V_2 -> V_5 [ V_20 ] . V_117 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_136 ) ;
V_2 -> V_5 [ V_20 ] . V_136 = NULL ;
}
F_111 ( & V_2 -> V_142 ) ;
F_112 ( & V_2 -> V_58 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ ) {
if ( V_2 -> V_250 [ V_20 ] != V_25 ) {
F_121 ( V_2 -> V_250 [ V_20 ] , 0 , 0 ) ;
V_2 -> V_250 [ V_20 ] = V_25 ;
}
}
F_122 ( ( unsigned long ) V_2 -> V_85 . V_251 , F_123 ( V_14 -> V_249 * V_151 ) ) ;
V_2 -> V_85 . V_251 = NULL ;
if ( V_2 -> V_156 )
F_124 ( V_2 -> V_156 , V_2 ) ;
V_2 -> V_252 = V_2 -> V_156 = 0 ;
}
static void F_125 ( struct V_13 * V_14 , int V_253 )
{
unsigned int V_20 ;
V_14 -> V_152 = V_253 ?
V_254 : V_255 ;
if ( V_14 -> V_164 )
F_110 ( V_14 -> V_164 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ )
F_120 ( & V_14 -> V_2 [ V_20 ] ) ;
F_8 ( V_14 -> V_2 ) ;
V_14 -> V_2 = NULL ;
V_14 -> V_172 = 0 ;
}
static void F_126 ( unsigned long V_33 , unsigned int V_101 ,
unsigned int V_102 , void * V_103 )
{
struct V_256 * V_14 = V_103 ;
char * V_122 ;
const struct V_110 * V_257 = V_14 -> V_257 ;
V_122 = F_49 ( V_257 -> V_120 [ V_14 -> V_109 ] -> V_15 ) ;
memcpy ( V_14 -> V_123 + V_14 -> V_258 ,
V_122 + V_101 , V_102 ) ;
V_14 -> V_258 += V_102 ;
V_14 -> V_109 ++ ;
F_48 ( V_122 ) ;
}
static enum V_259 F_127 ( int V_260 )
{
switch ( V_260 )
{
case V_261 :
return V_262 ;
case V_263 :
return V_264 ;
case V_265 :
default:
return V_266 ;
}
}
static int F_128 ( enum V_259 V_267 ,
enum V_259 V_268 )
{
F_2 ( V_267 == V_88 ) ;
F_2 ( V_268 == V_88 ) ;
if ( V_267 == V_266 || V_268 == V_266 )
return V_265 ;
else if ( V_267 == V_264 || V_268 == V_264 )
return V_263 ;
return V_261 ;
}
static bool F_129 ( unsigned long * V_9 ,
struct V_1 * V_2 ,
struct V_269 * V_270 )
{
int V_20 = 0 ;
struct V_135 * V_136 ;
int V_137 , V_139 ;
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_110 * V_257 = & V_2 -> V_5 [ * V_9 ] ;
struct V_256 V_103 = {
. V_109 = 0 ,
} ;
V_139 = V_257 -> V_6 . V_91 == V_114 ?
V_257 -> V_6 . V_7 . V_118 . V_131 : V_257 -> V_6 . V_7 . V_8 . V_131 ;
if ( F_47 ( V_257 -> V_89 != V_90 ) ) {
struct V_110 * V_268 = & V_2 -> V_5 [ V_257 -> V_89 ] ;
V_257 -> V_87 = F_127 ( V_270 -> V_87 ) ;
if ( V_268 -> V_87 == V_88 )
return 0 ;
V_270 -> V_87 = F_128 ( V_257 -> V_87 ,
V_268 -> V_87 ) ;
V_139 += V_268 -> V_6 . V_7 . V_8 . V_131 ;
if ( V_268 -> V_137 != 0 ) {
* V_9 = V_257 -> V_89 ;
V_257 = V_268 ;
}
if ( F_4 ( V_2 , V_257 -> V_89 ) )
F_130 ( 1 , L_26 ,
V_14 -> V_80 -> V_195 , V_257 -> V_89 ) ;
}
V_103 . V_257 = V_257 ;
V_137 = V_257 -> V_137 ;
if ( V_270 -> V_91 == V_40 && V_14 -> V_23 ) {
F_57 (s->sg, sg, num_sg, i) {
F_2 ( V_136 -> V_101 + V_136 -> V_144 > V_151 ) ;
V_103 . V_258 = V_136 -> V_101 ;
V_103 . V_123 = F_49 ( F_60 ( V_136 ) ) ;
F_61 ( F_60 ( V_136 ) ,
V_136 -> V_101 ,
V_136 -> V_144 ,
F_126 ,
& V_103 ) ;
F_48 ( V_103 . V_123 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_139 ; V_20 ++ ) {
if ( F_131 ( V_257 -> V_120 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_132 ( L_27 ,
V_257 -> V_120 [ V_20 ] -> V_24 ) ;
F_9 ( & V_257 -> V_120 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
F_121 ( V_257 -> V_120 [ V_20 ] -> V_24 , 0 , 0UL ) ;
V_257 -> V_120 [ V_20 ] -> V_24 = V_25 ;
F_133 ( & V_257 -> V_120 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
if ( V_257 -> V_6 . V_91 == V_114 ) {
for ( V_20 = 0 ; V_20 < F_53 ( V_139 ) ; V_20 ++ ) {
if ( F_131 ( V_257 -> V_117 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_132 ( L_27 ,
V_257 -> V_117 [ V_20 ] -> V_24 ) ;
F_9 ( & V_257 -> V_117 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
struct V_15 * V_35 ;
F_121 ( V_257 -> V_117 [ V_20 ] -> V_24 , 0 , 0UL ) ;
if ( ! V_14 -> V_23 ) {
V_35 = V_257 -> V_117 [ V_20 ] -> V_15 ;
F_9 ( & V_35 -> V_37 , & V_2 -> V_36 ) ;
}
V_257 -> V_117 [ V_20 ] -> V_24 = V_25 ;
F_133 ( & V_257 -> V_117 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
}
return 1 ;
}
static T_6 F_134 ( int V_156 , void * V_271 )
{
struct V_11 * V_6 ;
struct V_269 * V_270 ;
T_7 V_20 , V_272 ;
unsigned long V_81 ;
struct V_1 * V_2 = (struct V_1 * ) V_271 ;
struct V_13 * V_14 = V_2 -> V_4 ;
int error ;
if ( F_47 ( V_14 -> V_152 != V_153 ) )
return V_273 ;
F_70 ( & V_2 -> V_165 , V_81 ) ;
V_274:
V_272 = V_2 -> V_85 . V_251 -> V_275 ;
F_135 () ;
for ( V_20 = V_2 -> V_85 . V_276 ; V_20 != V_272 ; V_20 ++ ) {
unsigned long V_9 ;
V_270 = F_136 ( & V_2 -> V_85 , V_20 ) ;
V_9 = V_270 -> V_9 ;
if ( V_9 >= F_3 ( V_14 ) ) {
F_130 ( 1 , L_28 ,
V_14 -> V_80 -> V_195 , F_22 ( V_270 -> V_91 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_270 -> V_91 != V_44 ) {
if ( ! F_129 ( & V_9 , V_2 , V_270 ) )
continue;
}
if ( F_4 ( V_2 , V_9 ) ) {
F_130 ( 1 , L_29 ,
V_14 -> V_80 -> V_195 , F_22 ( V_270 -> V_91 ) , V_9 ) ;
continue;
}
error = ( V_270 -> V_87 == V_261 ) ? 0 : - V_277 ;
switch ( V_270 -> V_91 ) {
case V_44 :
if ( F_47 ( V_270 -> V_87 == V_263 ) ) {
struct V_175 * V_164 = V_14 -> V_164 ;
F_98 ( V_222 L_30 ,
V_14 -> V_80 -> V_195 , F_22 ( V_270 -> V_91 ) ) ;
error = - V_278 ;
V_14 -> V_187 = 0 ;
V_14 -> V_98 = 0 ;
F_137 ( V_188 , V_164 ) ;
F_137 ( V_192 , V_164 ) ;
}
F_138 ( V_6 , error ) ;
break;
case V_43 :
case V_42 :
if ( F_47 ( V_270 -> V_87 == V_263 ) ) {
F_98 ( V_222 L_30 ,
V_14 -> V_80 -> V_195 , F_22 ( V_270 -> V_91 ) ) ;
error = - V_278 ;
}
if ( F_47 ( V_270 -> V_87 == V_265 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_131 == 0 ) ) {
F_98 ( V_222 L_31 ,
V_14 -> V_80 -> V_195 , F_22 ( V_270 -> V_91 ) ) ;
error = - V_278 ;
}
if ( F_47 ( error ) ) {
if ( error == - V_278 )
error = 0 ;
V_14 -> V_150 = 0 ;
F_92 ( V_14 ) ;
}
case V_40 :
case V_41 :
if ( F_47 ( V_270 -> V_87 != V_261 ) )
F_39 ( & V_14 -> V_30 -> V_73 , L_32
L_33 , V_270 -> V_87 ) ;
F_138 ( V_6 , error ) ;
break;
default:
F_139 () ;
}
}
V_2 -> V_85 . V_276 = V_20 ;
if ( V_20 != V_2 -> V_85 . V_86 ) {
int V_279 ;
F_140 ( & V_2 -> V_85 , V_279 ) ;
if ( V_279 )
goto V_274;
} else
V_2 -> V_85 . V_251 -> V_280 = V_20 + 1 ;
F_115 ( V_2 ) ;
F_72 ( & V_2 -> V_165 , V_81 ) ;
return V_273 ;
}
static int F_141 ( struct V_281 * V_73 ,
struct V_1 * V_2 )
{
struct V_282 * V_251 ;
int V_227 , V_20 ;
struct V_13 * V_14 = V_2 -> V_4 ;
unsigned long V_283 = V_14 -> V_249 * V_132 ;
T_1 V_24 [ V_284 ] ;
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ )
V_2 -> V_250 [ V_20 ] = V_25 ;
V_251 = (struct V_282 * ) F_142 ( V_21 | V_285 ,
F_123 ( V_283 ) ) ;
if ( ! V_251 ) {
F_143 ( V_73 , - V_28 , L_34 ) ;
return - V_28 ;
}
F_144 ( V_251 ) ;
F_145 ( & V_2 -> V_85 , V_251 , V_283 ) ;
V_227 = F_146 ( V_73 , V_2 -> V_85 . V_251 , V_14 -> V_249 , V_24 ) ;
if ( V_227 < 0 ) {
F_122 ( ( unsigned long ) V_251 , F_123 ( V_283 ) ) ;
V_2 -> V_85 . V_251 = NULL ;
goto V_286;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ )
V_2 -> V_250 [ V_20 ] = V_24 [ V_20 ] ;
V_227 = F_147 ( V_73 , & V_2 -> V_252 ) ;
if ( V_227 )
goto V_286;
V_227 = F_148 ( V_2 -> V_252 , F_134 , 0 ,
L_35 , V_2 ) ;
if ( V_227 <= 0 ) {
F_143 ( V_73 , V_227 ,
L_36 ) ;
goto V_286;
}
V_2 -> V_156 = V_227 ;
return 0 ;
V_286:
F_125 ( V_14 , 0 ) ;
return V_227 ;
}
static int F_149 ( struct V_287 V_288 ,
struct V_1 * V_2 , const char * V_289 )
{
int V_227 ;
unsigned int V_20 ;
const char * V_290 = NULL ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_14 -> V_249 == 1 ) {
V_227 = F_150 ( V_288 , V_289 , L_37 , L_38 , V_2 -> V_250 [ 0 ] ) ;
if ( V_227 ) {
V_290 = L_39 ;
goto V_291;
}
} else {
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ ) {
char V_292 [ V_293 ] ;
snprintf ( V_292 , V_293 , L_40 , V_20 ) ;
V_227 = F_150 ( V_288 , V_289 , V_292 ,
L_38 , V_2 -> V_250 [ V_20 ] ) ;
if ( V_227 ) {
V_290 = L_39 ;
goto V_291;
}
}
}
V_227 = F_150 ( V_288 , V_289 , L_41 , L_38 , V_2 -> V_252 ) ;
if ( V_227 ) {
V_290 = L_42 ;
goto V_291;
}
return 0 ;
V_291:
F_151 ( V_288 , 1 ) ;
if ( V_290 )
F_143 ( V_14 -> V_30 , V_227 , L_43 , V_290 ) ;
return V_227 ;
}
static int F_152 ( struct V_281 * V_73 ,
struct V_13 * V_14 )
{
const char * V_290 = NULL ;
struct V_287 V_288 ;
int V_227 ;
unsigned int V_20 , V_294 = 0 ;
unsigned int V_295 = 0 ;
V_227 = F_153 ( V_296 , V_14 -> V_30 -> V_297 ,
L_44 , L_38 , & V_294 ) ;
if ( V_227 != 1 )
V_14 -> V_249 = 1 ;
else {
V_295 = F_154 ( V_298 , V_294 ) ;
V_14 -> V_249 = 1 << V_295 ;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
V_227 = F_141 ( V_73 , V_2 ) ;
if ( V_227 )
goto V_299;
}
V_274:
V_227 = F_155 ( & V_288 ) ;
if ( V_227 ) {
F_143 ( V_73 , V_227 , L_45 ) ;
goto V_299;
}
if ( V_14 -> V_249 > 1 ) {
V_227 = F_150 ( V_288 , V_73 -> V_300 , L_46 , L_38 ,
V_295 ) ;
if ( V_227 ) {
V_290 = L_47 ;
goto V_291;
}
}
if ( V_14 -> V_172 == 1 ) {
V_227 = F_149 ( V_288 , & V_14 -> V_2 [ 0 ] , V_73 -> V_300 ) ;
if ( V_227 )
goto V_299;
} else {
char * V_301 ;
T_8 V_302 ;
V_227 = F_150 ( V_288 , V_73 -> V_300 , L_48 , L_38 ,
V_14 -> V_172 ) ;
if ( V_227 ) {
V_290 = L_49 ;
goto V_291;
}
V_302 = strlen ( V_73 -> V_300 ) + V_303 ;
V_301 = F_156 ( V_302 , V_52 ) ;
if ( ! V_301 ) {
V_227 = - V_28 ;
V_290 = L_50 ;
goto V_291;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ ) {
memset ( V_301 , 0 , V_302 ) ;
snprintf ( V_301 , V_302 , L_51 , V_73 -> V_300 , V_20 ) ;
V_227 = F_149 ( V_288 , & V_14 -> V_2 [ V_20 ] , V_301 ) ;
if ( V_227 ) {
F_8 ( V_301 ) ;
goto V_299;
}
}
F_8 ( V_301 ) ;
}
V_227 = F_150 ( V_288 , V_73 -> V_300 , L_52 , L_43 ,
V_304 ) ;
if ( V_227 ) {
V_290 = L_53 ;
goto V_291;
}
V_227 = F_150 ( V_288 , V_73 -> V_300 ,
L_54 , L_38 , 1 ) ;
if ( V_227 )
F_157 ( & V_73 -> V_73 ,
L_55 ) ;
V_227 = F_151 ( V_288 , 0 ) ;
if ( V_227 ) {
if ( V_227 == - V_305 )
goto V_274;
F_143 ( V_73 , V_227 , L_56 ) ;
goto V_299;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ ) {
unsigned int V_246 ;
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
for ( V_246 = 0 ; V_246 < F_3 ( V_14 ) ; V_246 ++ )
V_2 -> V_5 [ V_246 ] . V_6 . V_7 . V_8 . V_9 = V_246 + 1 ;
V_2 -> V_5 [ F_3 ( V_14 ) - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
}
F_158 ( V_73 , V_306 ) ;
return 0 ;
V_291:
F_151 ( V_288 , 1 ) ;
if ( V_290 )
F_143 ( V_73 , V_227 , L_43 , V_290 ) ;
V_299:
F_125 ( V_14 , 0 ) ;
F_8 ( V_14 ) ;
F_159 ( & V_73 -> V_73 , NULL ) ;
return V_227 ;
}
static int F_160 ( struct V_13 * V_14 )
{
unsigned int V_307 = 0 ;
int V_227 ;
unsigned int V_20 ;
F_2 ( V_14 -> V_172 ) ;
V_227 = F_153 ( V_296 , V_14 -> V_30 -> V_297 ,
L_57 , L_38 , & V_307 ) ;
if ( V_227 < 0 )
V_307 = 1 ;
V_14 -> V_172 = F_154 ( V_307 , V_308 ) ;
if ( ! V_14 -> V_172 )
V_14 -> V_172 = 1 ;
V_14 -> V_2 = F_6 ( sizeof( struct V_1 ) * V_14 -> V_172 , V_52 ) ;
if ( ! V_14 -> V_2 ) {
F_143 ( V_14 -> V_30 , - V_28 , L_58 ) ;
return - V_28 ;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_20 ] ;
F_161 ( & V_2 -> V_36 ) ;
F_161 ( & V_2 -> V_27 ) ;
V_2 -> V_4 = V_14 ;
F_162 ( & V_2 -> V_58 , F_118 ) ;
F_163 ( & V_2 -> V_165 ) ;
}
return 0 ;
}
static int F_164 ( struct V_281 * V_73 ,
const struct V_309 * V_9 )
{
int V_227 , V_196 ;
struct V_13 * V_14 ;
V_227 = F_153 ( V_296 , V_73 -> V_300 ,
L_59 , L_60 , & V_196 ) ;
if ( V_227 != 1 ) {
V_227 = F_153 ( V_296 , V_73 -> V_300 , L_61 ,
L_60 , & V_196 ) ;
if ( V_227 != 1 ) {
F_143 ( V_73 , V_227 , L_62 ) ;
return V_227 ;
}
}
if ( F_103 () ) {
char * type ;
int V_102 ;
if ( F_165 () ) {
int V_197 ;
if ( ! F_101 ( V_196 ) )
V_197 = F_96 ( V_196 ) ;
else
V_197 = V_221 ;
if ( V_197 != V_221 ) {
F_98 ( V_310
L_63 ,
V_311 , V_196 ) ;
return - V_223 ;
}
}
type = F_166 ( V_296 , V_73 -> V_300 , L_64 , & V_102 ) ;
if ( F_78 ( type ) )
return - V_223 ;
if ( strncmp ( type , L_65 , 5 ) == 0 ) {
F_8 ( type ) ;
return - V_223 ;
}
F_8 ( type ) ;
}
V_14 = F_6 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 ) {
F_143 ( V_73 , - V_28 , L_66 ) ;
return - V_28 ;
}
V_14 -> V_30 = V_73 ;
V_227 = F_160 ( V_14 ) ;
if ( V_227 ) {
F_8 ( V_14 ) ;
return V_227 ;
}
F_167 ( & V_14 -> V_312 ) ;
V_14 -> V_196 = V_196 ;
V_14 -> V_152 = V_255 ;
V_14 -> V_133 = F_168 ( strrchr ( V_73 -> V_300 , '/' ) + 1 , NULL , 0 ) ;
F_159 ( & V_73 -> V_73 , V_14 ) ;
return 0 ;
}
static void F_169 ( struct V_313 * V_313 )
{
struct V_314 * V_314 = V_313 -> V_315 ;
if ( F_170 ( & V_314 -> V_316 ) ) {
V_314 -> V_313 -> V_317 = 0 ;
V_314 -> V_313 -> V_318 = V_313 -> V_318 ;
F_171 ( V_314 -> V_313 ) ;
F_8 ( V_314 ) ;
}
F_172 ( V_313 ) ;
}
static int F_173 ( struct V_13 * V_14 )
{
unsigned int V_20 , V_319 ;
struct V_11 * V_6 , * V_19 ;
struct V_110 * V_320 ;
int V_48 ;
struct V_313 * V_313 , * V_321 ;
struct V_322 V_322 , V_323 ;
unsigned int V_247 , V_101 ;
int V_316 , V_324 ;
struct V_314 * V_314 ;
struct V_325 V_326 ;
F_174 ( V_14 ) ;
V_247 = V_14 -> V_145 ? : V_112 ;
F_88 ( V_14 -> V_164 , V_247 ) ;
F_175 ( & V_322 ) ;
F_161 ( & V_326 ) ;
for ( V_319 = 0 ; V_319 < V_14 -> V_172 ; V_319 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_319 ] ;
V_320 = F_176 ( V_2 -> V_5 , sizeof( V_2 -> V_5 ) ,
V_21 | V_327 | V_285 ) ;
if ( ! V_320 )
return - V_28 ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ )
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_8 . V_9 = V_20 + 1 ;
V_2 -> V_3 = V_2 -> V_85 . V_86 ;
V_2 -> V_5 [ F_3 ( V_14 ) - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_48 = F_177 ( V_2 ) ;
if ( V_48 ) {
F_8 ( V_320 ) ;
return V_48 ;
}
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ ) {
if ( ! V_320 [ V_20 ] . V_11 )
continue;
if ( V_320 [ V_20 ] . V_11 -> V_96 &
( V_147 | V_148 | V_154 | V_97 ) ) {
F_9 ( & V_320 [ V_20 ] . V_11 -> V_328 , & V_326 ) ;
continue;
}
V_323 . V_329 = V_320 [ V_20 ] . V_11 -> V_313 ;
V_323 . V_330 = V_320 [ V_20 ] . V_11 -> V_331 ;
F_178 ( & V_322 , & V_323 ) ;
V_320 [ V_20 ] . V_11 -> V_313 = NULL ;
F_179 ( V_320 [ V_20 ] . V_11 , 0 ) ;
}
F_8 ( V_320 ) ;
}
F_158 ( V_14 -> V_30 , V_332 ) ;
V_14 -> V_152 = V_153 ;
for ( V_319 = 0 ; V_319 < V_14 -> V_172 ; V_319 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_319 ] ;
F_117 ( V_2 ) ;
}
F_10 (req, n, &requests, queuelist) {
F_180 ( & V_6 -> V_328 ) ;
F_2 ( V_6 -> V_140 > V_247 ) ;
F_181 ( V_6 ) ;
}
F_182 ( V_14 -> V_164 ) ;
while ( ( V_313 = F_183 ( & V_322 ) ) != NULL ) {
if ( F_184 ( V_313 ) > V_247 ) {
V_316 = ( F_184 ( V_313 ) + V_247 - 1 ) / V_247 ;
V_314 = F_6 ( sizeof( * V_314 ) , V_21 ) ;
F_2 ( V_314 == NULL ) ;
F_185 ( & V_314 -> V_316 , V_316 ) ;
V_314 -> V_313 = V_313 ;
for ( V_20 = 0 ; V_20 < V_316 ; V_20 ++ ) {
V_101 = ( V_20 * V_247 * V_132 ) >> 9 ;
V_324 = F_154 ( ( unsigned int ) ( V_247 * V_132 ) >> 9 ,
( unsigned int ) F_186 ( V_313 ) - V_101 ) ;
V_321 = F_187 ( V_313 , V_21 ) ;
F_2 ( V_321 == NULL ) ;
F_188 ( V_321 , V_101 , V_324 ) ;
V_321 -> V_315 = V_314 ;
V_321 -> V_333 = F_169 ;
F_189 ( V_321 -> V_334 , V_321 ) ;
}
continue;
}
F_189 ( V_313 -> V_334 , V_313 ) ;
}
return 0 ;
}
static int F_190 ( struct V_281 * V_73 )
{
struct V_13 * V_14 = F_191 ( & V_73 -> V_73 ) ;
int V_227 = 0 ;
F_39 ( & V_73 -> V_73 , L_67 , V_73 -> V_300 ) ;
F_125 ( V_14 , V_14 -> V_152 == V_153 ) ;
V_227 = F_160 ( V_14 ) ;
if ( V_227 )
return V_227 ;
V_227 = F_152 ( V_73 , V_14 ) ;
return V_227 ;
}
static void F_192 ( struct V_13 * V_14 )
{
struct V_281 * V_30 = V_14 -> V_30 ;
struct V_59 * V_68 = NULL ;
F_193 ( & V_14 -> V_312 ) ;
if ( V_30 -> V_335 == V_336 ) {
F_194 ( & V_14 -> V_312 ) ;
return;
}
if ( V_14 -> V_80 )
V_68 = F_195 ( V_14 -> V_80 , 0 ) ;
F_194 ( & V_14 -> V_312 ) ;
if ( ! V_68 ) {
F_196 ( V_30 ) ;
return;
}
F_193 ( & V_68 -> V_337 ) ;
if ( V_68 -> V_338 ) {
F_197 ( V_30 , - V_56 ,
L_68 ) ;
F_158 ( V_30 , V_336 ) ;
} else {
F_109 ( V_14 ) ;
F_196 ( V_30 ) ;
}
F_194 ( & V_68 -> V_337 ) ;
F_198 ( V_68 ) ;
}
static void F_199 ( struct V_13 * V_14 )
{
int V_227 ;
unsigned int V_190 ;
unsigned int V_191 ;
unsigned int V_339 ;
V_14 -> V_187 = 1 ;
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_69 , L_38 , & V_190 ,
L_70 , L_38 , & V_191 ,
NULL ) ;
if ( ! V_227 ) {
V_14 -> V_190 = V_190 ;
V_14 -> V_191 = V_191 ;
}
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_71 , L_25 , & V_339 ,
NULL ) ;
if ( ! V_227 )
V_14 -> V_98 = ! ! V_339 ;
}
static int F_177 ( struct V_1 * V_2 )
{
unsigned int V_340 , V_27 ;
int V_227 , V_20 ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_14 -> V_145 == 0 ) {
if ( ! V_146 )
V_27 = V_112 ;
else {
V_27 = V_141 ;
}
}
else
V_27 = V_14 -> V_145 ;
V_340 = V_27 / V_141 ;
V_227 = F_5 ( V_2 ,
( V_27 + F_53 ( V_27 ) ) * F_3 ( V_14 ) ) ;
if ( V_227 )
goto V_22;
if ( ! V_14 -> V_23 && V_14 -> V_145 ) {
int V_12 = F_53 ( V_27 ) * F_3 ( V_14 ) ;
F_2 ( ! F_14 ( & V_2 -> V_36 ) ) ;
for ( V_20 = 0 ; V_20 < V_12 ; V_20 ++ ) {
struct V_15 * V_35 = F_7 ( V_21 ) ;
if ( ! V_35 )
goto V_22;
F_9 ( & V_35 -> V_37 , & V_2 -> V_36 ) ;
}
}
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ ) {
V_2 -> V_5 [ V_20 ] . V_120 = F_6 (
sizeof( V_2 -> V_5 [ V_20 ] . V_120 [ 0 ] ) * V_27 ,
V_21 ) ;
V_2 -> V_5 [ V_20 ] . V_136 = F_6 ( sizeof( V_2 -> V_5 [ V_20 ] . V_136 [ 0 ] ) * V_340 , V_21 ) ;
if ( V_14 -> V_145 )
V_2 -> V_5 [ V_20 ] . V_117 = F_6 (
sizeof( V_2 -> V_5 [ V_20 ] . V_117 [ 0 ] ) *
F_53 ( V_27 ) ,
V_21 ) ;
if ( ( V_2 -> V_5 [ V_20 ] . V_120 == NULL ) ||
( V_2 -> V_5 [ V_20 ] . V_136 == NULL ) ||
( V_14 -> V_145 &&
( V_2 -> V_5 [ V_20 ] . V_117 == NULL ) ) )
goto V_22;
F_201 ( V_2 -> V_5 [ V_20 ] . V_136 , V_340 ) ;
}
return 0 ;
V_22:
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ ) {
F_8 ( V_2 -> V_5 [ V_20 ] . V_120 ) ;
V_2 -> V_5 [ V_20 ] . V_120 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_136 ) ;
V_2 -> V_5 [ V_20 ] . V_136 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_117 ) ;
V_2 -> V_5 [ V_20 ] . V_117 = NULL ;
}
if ( ! F_14 ( & V_2 -> V_36 ) ) {
struct V_15 * V_35 , * V_19 ;
F_10 (indirect_page, n, &rinfo->indirect_pages, lru) {
F_11 ( & V_35 -> V_37 ) ;
F_12 ( V_35 ) ;
}
}
return - V_28 ;
}
static void F_174 ( struct V_13 * V_14 )
{
int V_227 ;
int V_341 , V_342 , V_92 , V_343 ;
unsigned int V_344 ;
V_14 -> V_150 = 0 ;
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_72 , L_25 , & V_341 ,
NULL ) ;
if ( ! V_227 && V_341 )
V_14 -> V_150 = V_147 | V_148 ;
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_73 , L_25 , & V_342 ,
NULL ) ;
if ( ! V_227 && V_342 )
V_14 -> V_150 = V_147 ;
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_74 , L_25 , & V_92 ,
NULL ) ;
if ( ! V_227 && V_92 )
F_199 ( V_14 ) ;
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_54 , L_38 , & V_343 ,
NULL ) ;
if ( V_227 )
V_14 -> V_23 = 0 ;
else
V_14 -> V_23 = V_343 ;
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_75 , L_38 , & V_344 ,
NULL ) ;
if ( V_227 )
V_14 -> V_145 = 0 ;
else
V_14 -> V_145 = F_154 ( V_344 ,
V_345 ) ;
}
static void F_202 ( struct V_13 * V_14 )
{
unsigned long long V_67 ;
unsigned long V_173 ;
unsigned int V_174 ;
unsigned int V_346 ;
int V_227 , V_20 ;
switch ( V_14 -> V_152 ) {
case V_153 :
V_227 = F_153 ( V_296 , V_14 -> V_30 -> V_297 ,
L_76 , L_77 , & V_67 ) ;
if ( F_203 ( V_227 ) )
return;
F_98 ( V_310 L_78 ,
V_67 ) ;
F_106 ( V_14 -> V_80 , V_67 ) ;
F_204 ( V_14 -> V_80 ) ;
return;
case V_254 :
F_173 ( V_14 ) ;
return;
default:
break;
}
F_39 ( & V_14 -> V_30 -> V_73 , L_79 ,
V_311 , V_14 -> V_30 -> V_297 ) ;
V_227 = F_200 ( V_296 , V_14 -> V_30 -> V_297 ,
L_76 , L_80 , & V_67 ,
L_81 , L_38 , & V_346 ,
L_82 , L_83 , & V_173 ,
NULL ) ;
if ( V_227 ) {
F_143 ( V_14 -> V_30 , V_227 ,
L_84 ,
V_14 -> V_30 -> V_297 ) ;
return;
}
V_227 = F_153 ( V_296 , V_14 -> V_30 -> V_297 ,
L_85 , L_38 , & V_174 ) ;
if ( V_227 != 1 )
V_174 = V_173 ;
F_174 ( V_14 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ ) {
V_227 = F_177 ( & V_14 -> V_2 [ V_20 ] ) ;
if ( V_227 ) {
F_143 ( V_14 -> V_30 , V_227 , L_86 ,
V_14 -> V_30 -> V_297 ) ;
F_125 ( V_14 , 0 ) ;
break;
}
}
V_227 = F_100 ( V_67 , V_14 , V_346 , V_173 ,
V_174 ) ;
if ( V_227 ) {
F_143 ( V_14 -> V_30 , V_227 , L_87 ,
V_14 -> V_30 -> V_297 ) ;
return;
}
F_158 ( V_14 -> V_30 , V_332 ) ;
V_14 -> V_152 = V_153 ;
for ( V_20 = 0 ; V_20 < V_14 -> V_172 ; V_20 ++ )
F_117 ( & V_14 -> V_2 [ V_20 ] ) ;
F_205 ( V_14 -> V_80 ) ;
V_14 -> V_347 = 1 ;
}
static void F_206 ( struct V_281 * V_73 ,
enum V_348 V_349 )
{
struct V_13 * V_14 = F_191 ( & V_73 -> V_73 ) ;
F_39 ( & V_73 -> V_73 , L_88 , V_349 ) ;
switch ( V_349 ) {
case V_350 :
if ( V_73 -> V_335 != V_351 )
break;
if ( F_152 ( V_73 , V_14 ) )
break;
case V_351 :
case V_306 :
case V_352 :
case V_353 :
case V_354 :
break;
case V_332 :
if ( V_73 -> V_335 != V_306 ) {
if ( F_152 ( V_73 , V_14 ) )
break;
}
F_202 ( V_14 ) ;
break;
case V_355 :
if ( V_73 -> V_335 == V_355 )
break;
case V_336 :
if ( V_14 )
F_192 ( V_14 ) ;
break;
}
}
static int F_207 ( struct V_281 * V_30 )
{
struct V_13 * V_14 = F_191 ( & V_30 -> V_73 ) ;
struct V_59 * V_68 = NULL ;
struct V_79 * V_356 ;
F_39 ( & V_30 -> V_73 , L_89 , V_30 -> V_300 ) ;
F_125 ( V_14 , 0 ) ;
F_193 ( & V_14 -> V_312 ) ;
V_356 = V_14 -> V_80 ;
if ( V_356 )
V_68 = F_195 ( V_356 , 0 ) ;
V_14 -> V_30 = NULL ;
F_194 ( & V_14 -> V_312 ) ;
if ( ! V_68 ) {
F_8 ( V_14 ) ;
return 0 ;
}
F_193 ( & V_68 -> V_337 ) ;
V_14 = V_356 -> V_72 ;
F_157 ( F_208 ( V_356 ) ,
L_90 ,
V_30 -> V_300 , V_68 -> V_338 ) ;
if ( V_14 && ! V_68 -> V_338 ) {
F_109 ( V_14 ) ;
V_356 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
F_194 ( & V_68 -> V_337 ) ;
F_198 ( V_68 ) ;
return 0 ;
}
static int F_209 ( struct V_281 * V_73 )
{
struct V_13 * V_14 = F_191 ( & V_73 -> V_73 ) ;
return V_14 -> V_347 && V_14 -> V_30 ;
}
static int F_210 ( struct V_59 * V_68 , T_3 V_69 )
{
struct V_79 * V_356 = V_68 -> V_64 ;
struct V_13 * V_14 ;
int V_227 = 0 ;
F_193 ( & V_357 ) ;
V_14 = V_356 -> V_72 ;
if ( ! V_14 ) {
V_227 = - V_358 ;
goto V_232;
}
F_193 ( & V_14 -> V_312 ) ;
if ( ! V_14 -> V_80 )
V_227 = - V_358 ;
F_194 ( & V_14 -> V_312 ) ;
V_232:
F_194 ( & V_357 ) ;
return V_227 ;
}
static void F_211 ( struct V_79 * V_356 , T_3 V_69 )
{
struct V_13 * V_14 = V_356 -> V_72 ;
struct V_59 * V_68 ;
struct V_281 * V_30 ;
F_193 ( & V_357 ) ;
V_68 = F_195 ( V_356 , 0 ) ;
if ( ! V_68 ) {
F_130 ( 1 , L_91 , V_356 -> V_195 ) ;
goto V_359;
}
if ( V_68 -> V_338 )
goto V_232;
F_193 ( & V_14 -> V_312 ) ;
V_30 = V_14 -> V_30 ;
if ( V_30 && V_30 -> V_335 == V_336 ) {
V_4 ( F_208 ( V_68 -> V_64 ) , L_92 ) ;
F_109 ( V_14 ) ;
F_196 ( V_14 -> V_30 ) ;
}
F_194 ( & V_14 -> V_312 ) ;
if ( ! V_30 ) {
V_4 ( F_208 ( V_68 -> V_64 ) , L_92 ) ;
F_109 ( V_14 ) ;
V_356 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
V_232:
F_198 ( V_68 ) ;
V_359:
F_194 ( & V_357 ) ;
}
static int T_9 F_212 ( void )
{
int V_360 ;
int V_361 = F_213 () ;
if ( ! F_214 () )
return - V_223 ;
if ( V_298 > V_362 ) {
F_94 ( L_93 ,
V_298 , V_362 ) ;
V_298 = V_362 ;
}
if ( V_308 > V_361 ) {
F_94 ( L_94 ,
V_308 , V_361 ) ;
V_308 = V_361 ;
}
if ( ! F_215 () )
return - V_223 ;
if ( F_216 ( V_221 , V_234 ) ) {
F_98 ( V_222 L_95 ,
V_221 , V_234 ) ;
return - V_223 ;
}
V_360 = F_217 ( & V_363 ) ;
if ( V_360 ) {
F_218 ( V_221 , V_234 ) ;
return V_360 ;
}
return 0 ;
}
static void T_10 F_219 ( void )
{
F_220 ( & V_363 ) ;
F_218 ( V_221 , V_234 ) ;
F_8 ( V_54 ) ;
}
