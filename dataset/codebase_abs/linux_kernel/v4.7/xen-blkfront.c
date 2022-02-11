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
int V_163 = V_160 -> V_164 ;
struct V_13 * V_14 = V_160 -> V_165 -> V_166 ;
struct V_1 * V_2 = NULL ;
F_2 ( V_14 -> V_167 <= V_163 ) ;
V_2 = & V_14 -> V_2 [ V_163 ] ;
F_69 ( V_162 -> V_168 ) ;
F_70 ( & V_2 -> V_169 , V_81 ) ;
if ( F_71 ( & V_2 -> V_85 ) )
goto V_170;
if ( F_67 ( V_162 -> V_168 , V_2 -> V_4 ) )
goto V_171;
if ( F_63 ( V_162 -> V_168 , V_2 ) )
goto V_170;
F_64 ( V_2 ) ;
F_72 ( & V_2 -> V_169 , V_81 ) ;
return V_172 ;
V_171:
F_72 ( & V_2 -> V_169 , V_81 ) ;
return V_173 ;
V_170:
F_72 ( & V_2 -> V_169 , V_81 ) ;
F_73 ( V_160 ) ;
return V_174 ;
}
static int F_74 ( struct V_79 * V_80 , T_5 V_175 ,
unsigned int V_176 ,
unsigned int V_116 )
{
struct V_177 * V_168 ;
struct V_13 * V_14 = V_80 -> V_72 ;
memset ( & V_14 -> V_178 , 0 , sizeof( V_14 -> V_178 ) ) ;
V_14 -> V_178 . V_179 = & V_180 ;
V_14 -> V_178 . V_181 = V_14 -> V_167 ;
if ( V_146 && V_14 -> V_145 == 0 ) {
V_14 -> V_178 . V_182 = F_3 ( V_14 ) / 2 ;
} else
V_14 -> V_178 . V_182 = F_3 ( V_14 ) ;
V_14 -> V_178 . V_183 = V_184 ;
V_14 -> V_178 . V_81 = V_185 | V_186 ;
V_14 -> V_178 . V_187 = 0 ;
V_14 -> V_178 . V_188 = V_14 ;
if ( F_75 ( & V_14 -> V_178 ) )
return - V_10 ;
V_168 = F_76 ( & V_14 -> V_178 ) ;
if ( F_77 ( V_168 ) ) {
F_78 ( & V_14 -> V_178 ) ;
return F_79 ( V_168 ) ;
}
V_168 -> V_166 = V_14 ;
F_80 ( V_189 , V_168 ) ;
if ( V_14 -> V_190 ) {
F_80 ( V_191 , V_168 ) ;
F_81 ( V_168 , F_36 ( V_80 ) ) ;
V_168 -> V_192 . V_193 = V_14 -> V_193 ;
V_168 -> V_192 . V_194 = V_14 -> V_194 ;
if ( V_14 -> V_98 )
F_80 ( V_195 , V_168 ) ;
}
F_82 ( V_168 , V_175 ) ;
F_83 ( V_168 , V_176 ) ;
F_84 ( V_168 , ( V_116 * V_132 ) / 512 ) ;
F_85 ( V_168 , V_151 - 1 ) ;
F_86 ( V_168 , V_151 ) ;
F_87 ( V_168 , V_116 / V_141 ) ;
F_88 ( V_168 , 511 ) ;
F_89 ( V_168 , V_196 ) ;
V_80 -> V_165 = V_168 ;
return 0 ;
}
static const char * F_90 ( unsigned int V_150 )
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
static void F_91 ( struct V_13 * V_14 )
{
F_92 ( V_14 -> V_168 , V_14 -> V_150 & V_147 ,
V_14 -> V_150 & V_148 ) ;
F_93 ( L_13 ,
V_14 -> V_80 -> V_197 , F_90 ( V_14 -> V_150 ) ,
L_14 , V_14 -> V_23 ?
L_15 : L_16 , L_17 ,
V_14 -> V_145 ? L_15 : L_16 ) ;
}
static int F_94 ( int V_198 , int * V_45 , unsigned int * V_101 )
{
int V_199 ;
V_199 = F_95 ( V_198 ) ;
* V_45 = F_96 ( V_198 ) ;
switch ( V_199 ) {
case V_200 :
* V_101 = ( * V_45 / 64 ) + V_201 ;
* V_45 = ( ( * V_45 / 64 ) * V_202 ) +
V_203 ;
break;
case V_204 :
* V_101 = ( * V_45 / 64 ) + 2 + V_201 ;
* V_45 = ( ( ( * V_45 / 64 ) + 2 ) * V_202 ) +
V_203 ;
break;
case V_205 :
* V_101 = ( * V_45 / V_202 ) + V_206 ;
* V_45 = * V_45 + V_207 ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
* V_101 = ( * V_45 / V_202 ) +
( ( V_199 - V_208 + 1 ) * 16 ) +
V_206 ;
* V_45 = * V_45 +
( ( V_199 - V_208 + 1 ) * 16 * V_202 ) +
V_207 ;
break;
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
* V_101 = ( * V_45 / V_202 ) +
( ( V_199 - V_215 + 8 ) * 16 ) +
V_206 ;
* V_45 = * V_45 +
( ( V_199 - V_215 + 8 ) * 16 * V_202 ) +
V_207 ;
break;
case V_223 :
* V_101 = * V_45 / V_202 ;
break;
default:
F_97 ( V_224 L_18
L_19 ) ;
return - V_225 ;
}
return 0 ;
}
static char * F_98 ( char * V_226 , unsigned int V_19 )
{
if ( V_19 >= 26 )
V_226 = F_98 ( V_226 , V_19 / 26 - 1 ) ;
* V_226 = 'a' + V_19 % 26 ;
return V_226 + 1 ;
}
static int F_99 ( V_95 V_227 ,
struct V_13 * V_14 ,
T_5 V_228 , T_5 V_175 ,
unsigned int V_176 )
{
struct V_79 * V_80 ;
int V_49 = 1 ;
int V_229 ;
unsigned int V_101 ;
int V_45 ;
int V_230 ;
char * V_226 ;
F_2 ( V_14 -> V_80 != NULL ) ;
F_2 ( V_14 -> V_168 != NULL ) ;
if ( ( V_14 -> V_198 >> V_231 ) > 1 ) {
F_97 ( V_224 L_20 , V_14 -> V_198 ) ;
return - V_225 ;
}
if ( ! F_100 ( V_14 -> V_198 ) ) {
V_229 = F_94 ( V_14 -> V_198 , & V_45 , & V_101 ) ;
if ( V_229 )
return V_229 ;
V_230 = V_202 ;
} else {
V_45 = F_101 ( V_14 -> V_198 ) ;
V_230 = V_232 ;
V_101 = V_45 / V_230 ;
if ( F_102 () && V_101 < V_201 + 4 )
F_97 ( V_224 L_21
L_22
L_23 , V_14 -> V_198 ) ;
}
if ( V_45 >> V_233 ) {
F_103 ( L_24 ,
V_14 -> V_198 , V_45 ) ;
return - V_225 ;
}
if ( ( V_45 % V_230 ) == 0 )
V_49 = V_230 ;
V_229 = F_24 ( V_45 , V_49 ) ;
if ( V_229 )
goto V_234;
V_229 = - V_225 ;
V_80 = F_104 ( V_49 ) ;
if ( V_80 == NULL )
goto V_235;
strcpy ( V_80 -> V_197 , V_236 ) ;
V_226 = F_98 ( V_80 -> V_197 + sizeof( V_236 ) - 1 , V_101 ) ;
F_2 ( V_226 >= V_80 -> V_197 + V_237 ) ;
if ( V_49 > 1 )
* V_226 = 0 ;
else
snprintf ( V_226 , V_80 -> V_197 + V_237 - V_226 ,
L_25 , V_45 & ( V_230 - 1 ) ) ;
V_80 -> V_199 = V_223 ;
V_80 -> V_238 = V_45 ;
V_80 -> V_239 = & V_240 ;
V_80 -> V_72 = V_14 ;
V_80 -> V_241 = & ( V_14 -> V_30 -> V_73 ) ;
F_105 ( V_80 , V_227 ) ;
if ( F_74 ( V_80 , V_175 , V_176 ,
V_14 -> V_145 ? :
V_112 ) ) {
F_106 ( V_80 ) ;
goto V_235;
}
V_14 -> V_168 = V_80 -> V_165 ;
V_14 -> V_80 = V_80 ;
F_91 ( V_14 ) ;
if ( V_228 & V_242 )
F_107 ( V_80 , 1 ) ;
if ( V_228 & V_243 )
V_80 -> V_81 |= V_244 ;
if ( V_228 & V_245 )
V_80 -> V_81 |= V_82 ;
return 0 ;
V_235:
F_31 ( V_45 , V_49 ) ;
V_234:
return V_229 ;
}
static void F_108 ( struct V_13 * V_14 )
{
unsigned int V_45 , V_49 , V_20 ;
if ( V_14 -> V_168 == NULL )
return;
F_109 ( V_14 -> V_168 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
F_110 ( & V_2 -> V_142 ) ;
F_111 ( & V_2 -> V_58 ) ;
}
F_106 ( V_14 -> V_80 ) ;
V_45 = V_14 -> V_80 -> V_238 ;
V_49 = V_14 -> V_80 -> V_54 ;
F_31 ( V_45 , V_49 ) ;
F_112 ( V_14 -> V_168 ) ;
F_78 ( & V_14 -> V_178 ) ;
V_14 -> V_168 = NULL ;
F_113 ( V_14 -> V_80 ) ;
V_14 -> V_80 = NULL ;
}
static inline void F_114 ( struct V_1 * V_2 )
{
if ( ! F_71 ( & V_2 -> V_85 ) )
F_115 ( V_2 -> V_4 -> V_168 , true ) ;
}
static void F_116 ( struct V_1 * V_2 )
{
unsigned long V_81 ;
F_70 ( & V_2 -> V_169 , V_81 ) ;
F_114 ( V_2 ) ;
F_72 ( & V_2 -> V_169 , V_81 ) ;
}
static void F_117 ( struct V_246 * V_58 )
{
struct V_1 * V_2 = F_118 ( V_58 , struct V_1 , V_58 ) ;
if ( V_2 -> V_4 -> V_152 == V_153 )
F_116 ( V_2 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
struct V_17 * V_247 , * V_19 ;
struct V_13 * V_14 = V_2 -> V_4 ;
int V_20 , V_248 , V_249 ;
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
F_11 ( & V_247 -> V_26 ) ;
if ( V_247 -> V_24 != V_25 ) {
F_120 ( V_247 -> V_24 ,
0 , 0UL ) ;
V_2 -> V_29 -- ;
}
if ( V_14 -> V_23 )
F_12 ( V_247 -> V_15 ) ;
F_8 ( V_247 ) ;
}
}
F_2 ( V_2 -> V_29 != 0 ) ;
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ ) {
if ( ! V_2 -> V_5 [ V_20 ] . V_11 )
goto V_250;
V_249 = V_2 -> V_5 [ V_20 ] . V_6 . V_91 == V_114 ?
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_118 . V_131 :
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_8 . V_131 ;
for ( V_248 = 0 ; V_248 < V_249 ; V_248 ++ ) {
V_247 = V_2 -> V_5 [ V_20 ] . V_120 [ V_248 ] ;
F_120 ( V_247 -> V_24 , 0 , 0UL ) ;
if ( V_14 -> V_23 )
F_12 ( V_247 -> V_15 ) ;
F_8 ( V_247 ) ;
}
if ( V_2 -> V_5 [ V_20 ] . V_6 . V_91 != V_114 )
goto V_250;
for ( V_248 = 0 ; V_248 < F_53 ( V_249 ) ; V_248 ++ ) {
V_247 = V_2 -> V_5 [ V_20 ] . V_117 [ V_248 ] ;
F_120 ( V_247 -> V_24 , 0 , 0UL ) ;
F_12 ( V_247 -> V_15 ) ;
F_8 ( V_247 ) ;
}
V_250:
F_8 ( V_2 -> V_5 [ V_20 ] . V_120 ) ;
V_2 -> V_5 [ V_20 ] . V_120 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_117 ) ;
V_2 -> V_5 [ V_20 ] . V_117 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_136 ) ;
V_2 -> V_5 [ V_20 ] . V_136 = NULL ;
}
F_110 ( & V_2 -> V_142 ) ;
F_111 ( & V_2 -> V_58 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ ) {
if ( V_2 -> V_252 [ V_20 ] != V_25 ) {
F_120 ( V_2 -> V_252 [ V_20 ] , 0 , 0 ) ;
V_2 -> V_252 [ V_20 ] = V_25 ;
}
}
F_121 ( ( unsigned long ) V_2 -> V_85 . V_253 , F_122 ( V_14 -> V_251 * V_151 ) ) ;
V_2 -> V_85 . V_253 = NULL ;
if ( V_2 -> V_156 )
F_123 ( V_2 -> V_156 , V_2 ) ;
V_2 -> V_254 = V_2 -> V_156 = 0 ;
}
static void F_124 ( struct V_13 * V_14 , int V_255 )
{
unsigned int V_20 ;
V_14 -> V_152 = V_255 ?
V_256 : V_257 ;
if ( V_14 -> V_168 )
F_109 ( V_14 -> V_168 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ )
F_119 ( & V_14 -> V_2 [ V_20 ] ) ;
F_8 ( V_14 -> V_2 ) ;
V_14 -> V_2 = NULL ;
V_14 -> V_167 = 0 ;
}
static void F_125 ( unsigned long V_33 , unsigned int V_101 ,
unsigned int V_102 , void * V_103 )
{
struct V_258 * V_14 = V_103 ;
char * V_122 ;
const struct V_110 * V_259 = V_14 -> V_259 ;
V_122 = F_49 ( V_259 -> V_120 [ V_14 -> V_109 ] -> V_15 ) ;
memcpy ( V_14 -> V_123 + V_14 -> V_260 ,
V_122 + V_101 , V_102 ) ;
V_14 -> V_260 += V_102 ;
V_14 -> V_109 ++ ;
F_48 ( V_122 ) ;
}
static enum V_261 F_126 ( int V_262 )
{
switch ( V_262 )
{
case V_263 :
return V_264 ;
case V_265 :
return V_266 ;
case V_267 :
default:
return V_268 ;
}
}
static int F_127 ( enum V_261 V_269 ,
enum V_261 V_270 )
{
F_2 ( V_269 == V_88 ) ;
F_2 ( V_270 == V_88 ) ;
if ( V_269 == V_268 || V_270 == V_268 )
return V_267 ;
else if ( V_269 == V_266 || V_270 == V_266 )
return V_265 ;
return V_263 ;
}
static bool F_128 ( unsigned long * V_9 ,
struct V_1 * V_2 ,
struct V_271 * V_272 )
{
int V_20 = 0 ;
struct V_135 * V_136 ;
int V_137 , V_139 ;
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_110 * V_259 = & V_2 -> V_5 [ * V_9 ] ;
struct V_258 V_103 = {
. V_109 = 0 ,
} ;
V_139 = V_259 -> V_6 . V_91 == V_114 ?
V_259 -> V_6 . V_7 . V_118 . V_131 : V_259 -> V_6 . V_7 . V_8 . V_131 ;
if ( F_47 ( V_259 -> V_89 != V_90 ) ) {
struct V_110 * V_270 = & V_2 -> V_5 [ V_259 -> V_89 ] ;
V_259 -> V_87 = F_126 ( V_272 -> V_87 ) ;
if ( V_270 -> V_87 == V_88 )
return 0 ;
V_272 -> V_87 = F_127 ( V_259 -> V_87 ,
V_270 -> V_87 ) ;
V_139 += V_270 -> V_6 . V_7 . V_8 . V_131 ;
if ( V_270 -> V_137 != 0 ) {
* V_9 = V_259 -> V_89 ;
V_259 = V_270 ;
}
if ( F_4 ( V_2 , V_259 -> V_89 ) )
F_129 ( 1 , L_26 ,
V_14 -> V_80 -> V_197 , V_259 -> V_89 ) ;
}
V_103 . V_259 = V_259 ;
V_137 = V_259 -> V_137 ;
if ( V_272 -> V_91 == V_40 && V_14 -> V_23 ) {
F_57 (s->sg, sg, num_sg, i) {
F_2 ( V_136 -> V_101 + V_136 -> V_144 > V_151 ) ;
V_103 . V_260 = V_136 -> V_101 ;
V_103 . V_123 = F_49 ( F_60 ( V_136 ) ) ;
F_61 ( F_60 ( V_136 ) ,
V_136 -> V_101 ,
V_136 -> V_144 ,
F_125 ,
& V_103 ) ;
F_48 ( V_103 . V_123 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_139 ; V_20 ++ ) {
if ( F_130 ( V_259 -> V_120 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_131 ( L_27 ,
V_259 -> V_120 [ V_20 ] -> V_24 ) ;
F_9 ( & V_259 -> V_120 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
F_120 ( V_259 -> V_120 [ V_20 ] -> V_24 , 0 , 0UL ) ;
V_259 -> V_120 [ V_20 ] -> V_24 = V_25 ;
F_132 ( & V_259 -> V_120 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
if ( V_259 -> V_6 . V_91 == V_114 ) {
for ( V_20 = 0 ; V_20 < F_53 ( V_139 ) ; V_20 ++ ) {
if ( F_130 ( V_259 -> V_117 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_131 ( L_27 ,
V_259 -> V_117 [ V_20 ] -> V_24 ) ;
F_9 ( & V_259 -> V_117 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
struct V_15 * V_35 ;
F_120 ( V_259 -> V_117 [ V_20 ] -> V_24 , 0 , 0UL ) ;
if ( ! V_14 -> V_23 ) {
V_35 = V_259 -> V_117 [ V_20 ] -> V_15 ;
F_9 ( & V_35 -> V_37 , & V_2 -> V_36 ) ;
}
V_259 -> V_117 [ V_20 ] -> V_24 = V_25 ;
F_132 ( & V_259 -> V_117 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
}
return 1 ;
}
static T_6 F_133 ( int V_156 , void * V_273 )
{
struct V_11 * V_6 ;
struct V_271 * V_272 ;
T_7 V_20 , V_274 ;
unsigned long V_81 ;
struct V_1 * V_2 = (struct V_1 * ) V_273 ;
struct V_13 * V_14 = V_2 -> V_4 ;
int error ;
if ( F_47 ( V_14 -> V_152 != V_153 ) )
return V_275 ;
F_70 ( & V_2 -> V_169 , V_81 ) ;
V_276:
V_274 = V_2 -> V_85 . V_253 -> V_277 ;
F_134 () ;
for ( V_20 = V_2 -> V_85 . V_278 ; V_20 != V_274 ; V_20 ++ ) {
unsigned long V_9 ;
V_272 = F_135 ( & V_2 -> V_85 , V_20 ) ;
V_9 = V_272 -> V_9 ;
if ( V_9 >= F_3 ( V_14 ) ) {
F_129 ( 1 , L_28 ,
V_14 -> V_80 -> V_197 , F_22 ( V_272 -> V_91 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_272 -> V_91 != V_44 ) {
if ( ! F_128 ( & V_9 , V_2 , V_272 ) )
continue;
}
if ( F_4 ( V_2 , V_9 ) ) {
F_129 ( 1 , L_29 ,
V_14 -> V_80 -> V_197 , F_22 ( V_272 -> V_91 ) , V_9 ) ;
continue;
}
error = ( V_272 -> V_87 == V_263 ) ? 0 : - V_279 ;
switch ( V_272 -> V_91 ) {
case V_44 :
if ( F_47 ( V_272 -> V_87 == V_265 ) ) {
struct V_177 * V_168 = V_14 -> V_168 ;
F_97 ( V_224 L_30 ,
V_14 -> V_80 -> V_197 , F_22 ( V_272 -> V_91 ) ) ;
error = - V_280 ;
V_14 -> V_190 = 0 ;
V_14 -> V_98 = 0 ;
F_136 ( V_191 , V_168 ) ;
F_136 ( V_195 , V_168 ) ;
}
F_137 ( V_6 , error ) ;
break;
case V_43 :
case V_42 :
if ( F_47 ( V_272 -> V_87 == V_265 ) ) {
F_97 ( V_224 L_30 ,
V_14 -> V_80 -> V_197 , F_22 ( V_272 -> V_91 ) ) ;
error = - V_280 ;
}
if ( F_47 ( V_272 -> V_87 == V_267 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_131 == 0 ) ) {
F_97 ( V_224 L_31 ,
V_14 -> V_80 -> V_197 , F_22 ( V_272 -> V_91 ) ) ;
error = - V_280 ;
}
if ( F_47 ( error ) ) {
if ( error == - V_280 )
error = 0 ;
V_14 -> V_150 = 0 ;
F_91 ( V_14 ) ;
}
case V_40 :
case V_41 :
if ( F_47 ( V_272 -> V_87 != V_263 ) )
F_39 ( & V_14 -> V_30 -> V_73 , L_32
L_33 , V_272 -> V_87 ) ;
F_137 ( V_6 , error ) ;
break;
default:
F_138 () ;
}
}
V_2 -> V_85 . V_278 = V_20 ;
if ( V_20 != V_2 -> V_85 . V_86 ) {
int V_281 ;
F_139 ( & V_2 -> V_85 , V_281 ) ;
if ( V_281 )
goto V_276;
} else
V_2 -> V_85 . V_253 -> V_282 = V_20 + 1 ;
F_114 ( V_2 ) ;
F_72 ( & V_2 -> V_169 , V_81 ) ;
return V_275 ;
}
static int F_140 ( struct V_283 * V_73 ,
struct V_1 * V_2 )
{
struct V_284 * V_253 ;
int V_229 , V_20 ;
struct V_13 * V_14 = V_2 -> V_4 ;
unsigned long V_285 = V_14 -> V_251 * V_132 ;
T_1 V_24 [ V_286 ] ;
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ )
V_2 -> V_252 [ V_20 ] = V_25 ;
V_253 = (struct V_284 * ) F_141 ( V_21 | V_287 ,
F_122 ( V_285 ) ) ;
if ( ! V_253 ) {
F_142 ( V_73 , - V_28 , L_34 ) ;
return - V_28 ;
}
F_143 ( V_253 ) ;
F_144 ( & V_2 -> V_85 , V_253 , V_285 ) ;
V_229 = F_145 ( V_73 , V_2 -> V_85 . V_253 , V_14 -> V_251 , V_24 ) ;
if ( V_229 < 0 ) {
F_121 ( ( unsigned long ) V_253 , F_122 ( V_285 ) ) ;
V_2 -> V_85 . V_253 = NULL ;
goto V_288;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ )
V_2 -> V_252 [ V_20 ] = V_24 [ V_20 ] ;
V_229 = F_146 ( V_73 , & V_2 -> V_254 ) ;
if ( V_229 )
goto V_288;
V_229 = F_147 ( V_2 -> V_254 , F_133 , 0 ,
L_35 , V_2 ) ;
if ( V_229 <= 0 ) {
F_142 ( V_73 , V_229 ,
L_36 ) ;
goto V_288;
}
V_2 -> V_156 = V_229 ;
return 0 ;
V_288:
F_124 ( V_14 , 0 ) ;
return V_229 ;
}
static int F_148 ( struct V_289 V_290 ,
struct V_1 * V_2 , const char * V_291 )
{
int V_229 ;
unsigned int V_20 ;
const char * V_292 = NULL ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_14 -> V_251 == 1 ) {
V_229 = F_149 ( V_290 , V_291 , L_37 , L_38 , V_2 -> V_252 [ 0 ] ) ;
if ( V_229 ) {
V_292 = L_39 ;
goto V_293;
}
} else {
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ ) {
char V_294 [ V_295 ] ;
snprintf ( V_294 , V_295 , L_40 , V_20 ) ;
V_229 = F_149 ( V_290 , V_291 , V_294 ,
L_38 , V_2 -> V_252 [ V_20 ] ) ;
if ( V_229 ) {
V_292 = L_39 ;
goto V_293;
}
}
}
V_229 = F_149 ( V_290 , V_291 , L_41 , L_38 , V_2 -> V_254 ) ;
if ( V_229 ) {
V_292 = L_42 ;
goto V_293;
}
return 0 ;
V_293:
F_150 ( V_290 , 1 ) ;
if ( V_292 )
F_142 ( V_14 -> V_30 , V_229 , L_43 , V_292 ) ;
return V_229 ;
}
static int F_151 ( struct V_283 * V_73 ,
struct V_13 * V_14 )
{
const char * V_292 = NULL ;
struct V_289 V_290 ;
int V_229 ;
unsigned int V_20 , V_296 = 0 ;
unsigned int V_297 = 0 ;
V_229 = F_152 ( V_298 , V_14 -> V_30 -> V_299 ,
L_44 , L_38 , & V_296 ) ;
if ( V_229 != 1 )
V_14 -> V_251 = 1 ;
else {
V_297 = F_153 ( V_300 , V_296 ) ;
V_14 -> V_251 = 1 << V_297 ;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
V_229 = F_140 ( V_73 , V_2 ) ;
if ( V_229 )
goto V_301;
}
V_276:
V_229 = F_154 ( & V_290 ) ;
if ( V_229 ) {
F_142 ( V_73 , V_229 , L_45 ) ;
goto V_301;
}
if ( V_14 -> V_251 > 1 ) {
V_229 = F_149 ( V_290 , V_73 -> V_302 , L_46 , L_38 ,
V_297 ) ;
if ( V_229 ) {
V_292 = L_47 ;
goto V_293;
}
}
if ( V_14 -> V_167 == 1 ) {
V_229 = F_148 ( V_290 , & V_14 -> V_2 [ 0 ] , V_73 -> V_302 ) ;
if ( V_229 )
goto V_301;
} else {
char * V_303 ;
T_8 V_304 ;
V_229 = F_149 ( V_290 , V_73 -> V_302 , L_48 , L_38 ,
V_14 -> V_167 ) ;
if ( V_229 ) {
V_292 = L_49 ;
goto V_293;
}
V_304 = strlen ( V_73 -> V_302 ) + V_305 ;
V_303 = F_155 ( V_304 , V_52 ) ;
if ( ! V_303 ) {
V_229 = - V_28 ;
V_292 = L_50 ;
goto V_293;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ ) {
memset ( V_303 , 0 , V_304 ) ;
snprintf ( V_303 , V_304 , L_51 , V_73 -> V_302 , V_20 ) ;
V_229 = F_148 ( V_290 , & V_14 -> V_2 [ V_20 ] , V_303 ) ;
if ( V_229 ) {
F_8 ( V_303 ) ;
goto V_301;
}
}
F_8 ( V_303 ) ;
}
V_229 = F_149 ( V_290 , V_73 -> V_302 , L_52 , L_43 ,
V_306 ) ;
if ( V_229 ) {
V_292 = L_53 ;
goto V_293;
}
V_229 = F_149 ( V_290 , V_73 -> V_302 ,
L_54 , L_38 , 1 ) ;
if ( V_229 )
F_156 ( & V_73 -> V_73 ,
L_55 ) ;
V_229 = F_150 ( V_290 , 0 ) ;
if ( V_229 ) {
if ( V_229 == - V_307 )
goto V_276;
F_142 ( V_73 , V_229 , L_56 ) ;
goto V_301;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ ) {
unsigned int V_248 ;
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
for ( V_248 = 0 ; V_248 < F_3 ( V_14 ) ; V_248 ++ )
V_2 -> V_5 [ V_248 ] . V_6 . V_7 . V_8 . V_9 = V_248 + 1 ;
V_2 -> V_5 [ F_3 ( V_14 ) - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
}
F_157 ( V_73 , V_308 ) ;
return 0 ;
V_293:
F_150 ( V_290 , 1 ) ;
if ( V_292 )
F_142 ( V_73 , V_229 , L_43 , V_292 ) ;
V_301:
F_124 ( V_14 , 0 ) ;
F_8 ( V_14 ) ;
F_158 ( & V_73 -> V_73 , NULL ) ;
return V_229 ;
}
static int F_159 ( struct V_13 * V_14 )
{
unsigned int V_309 = 0 ;
int V_229 ;
unsigned int V_20 ;
F_2 ( V_14 -> V_167 ) ;
V_229 = F_152 ( V_298 , V_14 -> V_30 -> V_299 ,
L_57 , L_38 , & V_309 ) ;
if ( V_229 < 0 )
V_309 = 1 ;
V_14 -> V_167 = F_153 ( V_309 , V_310 ) ;
if ( ! V_14 -> V_167 )
V_14 -> V_167 = 1 ;
V_14 -> V_2 = F_6 ( sizeof( struct V_1 ) * V_14 -> V_167 , V_52 ) ;
if ( ! V_14 -> V_2 ) {
F_142 ( V_14 -> V_30 , - V_28 , L_58 ) ;
return - V_28 ;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_20 ] ;
F_160 ( & V_2 -> V_36 ) ;
F_160 ( & V_2 -> V_27 ) ;
V_2 -> V_4 = V_14 ;
F_161 ( & V_2 -> V_58 , F_117 ) ;
F_162 ( & V_2 -> V_169 ) ;
}
return 0 ;
}
static int F_163 ( struct V_283 * V_73 ,
const struct V_311 * V_9 )
{
int V_229 , V_198 ;
struct V_13 * V_14 ;
V_229 = F_152 ( V_298 , V_73 -> V_302 ,
L_59 , L_60 , & V_198 ) ;
if ( V_229 != 1 ) {
V_229 = F_152 ( V_298 , V_73 -> V_302 , L_61 ,
L_60 , & V_198 ) ;
if ( V_229 != 1 ) {
F_142 ( V_73 , V_229 , L_62 ) ;
return V_229 ;
}
}
if ( F_102 () ) {
char * type ;
int V_102 ;
if ( F_164 () ) {
int V_199 ;
if ( ! F_100 ( V_198 ) )
V_199 = F_95 ( V_198 ) ;
else
V_199 = V_223 ;
if ( V_199 != V_223 ) {
F_97 ( V_312
L_63 ,
V_313 , V_198 ) ;
return - V_225 ;
}
}
type = F_165 ( V_298 , V_73 -> V_302 , L_64 , & V_102 ) ;
if ( F_77 ( type ) )
return - V_225 ;
if ( strncmp ( type , L_65 , 5 ) == 0 ) {
F_8 ( type ) ;
return - V_225 ;
}
F_8 ( type ) ;
}
V_14 = F_6 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 ) {
F_142 ( V_73 , - V_28 , L_66 ) ;
return - V_28 ;
}
V_14 -> V_30 = V_73 ;
V_229 = F_159 ( V_14 ) ;
if ( V_229 ) {
F_8 ( V_14 ) ;
return V_229 ;
}
F_166 ( & V_14 -> V_314 ) ;
V_14 -> V_198 = V_198 ;
V_14 -> V_152 = V_257 ;
V_14 -> V_133 = F_167 ( strrchr ( V_73 -> V_302 , '/' ) + 1 , NULL , 0 ) ;
F_158 ( & V_73 -> V_73 , V_14 ) ;
return 0 ;
}
static void F_168 ( struct V_315 * V_315 )
{
struct V_316 * V_316 = V_315 -> V_317 ;
if ( F_169 ( & V_316 -> V_318 ) ) {
V_316 -> V_315 -> V_319 = 0 ;
V_316 -> V_315 -> V_320 = V_315 -> V_320 ;
F_170 ( V_316 -> V_315 ) ;
F_8 ( V_316 ) ;
}
F_171 ( V_315 ) ;
}
static int F_172 ( struct V_13 * V_14 )
{
unsigned int V_20 , V_321 ;
struct V_11 * V_6 , * V_19 ;
int V_48 ;
struct V_315 * V_315 , * V_322 ;
unsigned int V_249 , V_101 ;
int V_318 , V_323 ;
struct V_316 * V_316 ;
F_173 ( V_14 ) ;
V_249 = V_14 -> V_145 ? : V_112 ;
F_87 ( V_14 -> V_168 , V_249 ) ;
for ( V_321 = 0 ; V_321 < V_14 -> V_167 ; V_321 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_321 ] ;
V_48 = F_174 ( V_2 ) ;
if ( V_48 )
return V_48 ;
}
F_157 ( V_14 -> V_30 , V_324 ) ;
V_14 -> V_152 = V_153 ;
for ( V_321 = 0 ; V_321 < V_14 -> V_167 ; V_321 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_321 ] ;
F_116 ( V_2 ) ;
}
F_10 (req, n, &info->requests, queuelist) {
F_175 ( & V_6 -> V_325 ) ;
F_2 ( V_6 -> V_140 > V_249 ) ;
F_176 ( V_6 ) ;
}
F_177 ( V_14 -> V_168 ) ;
while ( ( V_315 = F_178 ( & V_14 -> V_326 ) ) != NULL ) {
if ( F_179 ( V_315 ) > V_249 ) {
V_318 = ( F_179 ( V_315 ) + V_249 - 1 ) / V_249 ;
V_316 = F_6 ( sizeof( * V_316 ) , V_21 ) ;
F_2 ( V_316 == NULL ) ;
F_180 ( & V_316 -> V_318 , V_318 ) ;
V_316 -> V_315 = V_315 ;
for ( V_20 = 0 ; V_20 < V_318 ; V_20 ++ ) {
V_101 = ( V_20 * V_249 * V_132 ) >> 9 ;
V_323 = F_153 ( ( unsigned int ) ( V_249 * V_132 ) >> 9 ,
( unsigned int ) F_181 ( V_315 ) - V_101 ) ;
V_322 = F_182 ( V_315 , V_21 ) ;
F_2 ( V_322 == NULL ) ;
F_183 ( V_322 , V_101 , V_323 ) ;
V_322 -> V_317 = V_316 ;
V_322 -> V_327 = F_168 ;
F_184 ( V_322 -> V_328 , V_322 ) ;
}
continue;
}
F_184 ( V_315 -> V_328 , V_315 ) ;
}
return 0 ;
}
static int F_185 ( struct V_283 * V_73 )
{
struct V_13 * V_14 = F_186 ( & V_73 -> V_73 ) ;
int V_229 = 0 ;
unsigned int V_20 , V_248 ;
F_39 ( & V_73 -> V_73 , L_67 , V_73 -> V_302 ) ;
F_187 ( & V_14 -> V_326 ) ;
F_160 ( & V_14 -> V_329 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
struct V_326 V_330 ;
struct V_110 * V_5 = V_2 -> V_5 ;
for ( V_248 = 0 ; V_248 < F_3 ( V_14 ) ; V_248 ++ ) {
if ( ! V_5 [ V_248 ] . V_11 )
continue;
if ( V_5 [ V_248 ] . V_11 -> V_96 &
( V_147 | V_148 | V_154 | V_97 ) ) {
F_9 ( & V_5 [ V_248 ] . V_11 -> V_325 , & V_14 -> V_329 ) ;
continue;
}
V_330 . V_331 = V_5 [ V_248 ] . V_11 -> V_315 ;
V_330 . V_332 = V_5 [ V_248 ] . V_11 -> V_333 ;
F_188 ( & V_14 -> V_326 , & V_330 ) ;
V_5 [ V_248 ] . V_11 -> V_315 = NULL ;
F_189 ( V_5 [ V_248 ] . V_11 , 0 ) ;
}
}
F_124 ( V_14 , V_14 -> V_152 == V_153 ) ;
V_229 = F_159 ( V_14 ) ;
if ( V_229 )
return V_229 ;
V_229 = F_151 ( V_73 , V_14 ) ;
if ( ! V_229 )
F_190 ( & V_14 -> V_178 , V_14 -> V_167 ) ;
return V_229 ;
}
static void F_191 ( struct V_13 * V_14 )
{
struct V_283 * V_30 = V_14 -> V_30 ;
struct V_59 * V_68 = NULL ;
F_192 ( & V_14 -> V_314 ) ;
if ( V_30 -> V_334 == V_335 ) {
F_193 ( & V_14 -> V_314 ) ;
return;
}
if ( V_14 -> V_80 )
V_68 = F_194 ( V_14 -> V_80 , 0 ) ;
F_193 ( & V_14 -> V_314 ) ;
if ( ! V_68 ) {
F_195 ( V_30 ) ;
return;
}
F_192 ( & V_68 -> V_336 ) ;
if ( V_68 -> V_337 ) {
F_196 ( V_30 , - V_56 ,
L_68 ) ;
F_157 ( V_30 , V_335 ) ;
} else {
F_108 ( V_14 ) ;
F_195 ( V_30 ) ;
}
F_193 ( & V_68 -> V_336 ) ;
F_197 ( V_68 ) ;
}
static void F_198 ( struct V_13 * V_14 )
{
int V_229 ;
unsigned int V_193 ;
unsigned int V_194 ;
unsigned int V_338 ;
V_14 -> V_190 = 1 ;
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_69 , L_38 , & V_193 ,
L_70 , L_38 , & V_194 ,
NULL ) ;
if ( ! V_229 ) {
V_14 -> V_193 = V_193 ;
V_14 -> V_194 = V_194 ;
}
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_71 , L_25 , & V_338 ,
NULL ) ;
if ( ! V_229 )
V_14 -> V_98 = ! ! V_338 ;
}
static int F_174 ( struct V_1 * V_2 )
{
unsigned int V_339 , V_27 ;
int V_229 , V_20 ;
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
V_339 = V_27 / V_141 ;
V_229 = F_5 ( V_2 ,
( V_27 + F_53 ( V_27 ) ) * F_3 ( V_14 ) ) ;
if ( V_229 )
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
V_2 -> V_5 [ V_20 ] . V_136 = F_6 ( sizeof( V_2 -> V_5 [ V_20 ] . V_136 [ 0 ] ) * V_339 , V_21 ) ;
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
F_200 ( V_2 -> V_5 [ V_20 ] . V_136 , V_339 ) ;
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
static void F_173 ( struct V_13 * V_14 )
{
int V_229 ;
int V_340 , V_341 , V_92 , V_342 ;
unsigned int V_343 ;
V_14 -> V_150 = 0 ;
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_72 , L_25 , & V_340 ,
NULL ) ;
if ( ! V_229 && V_340 )
V_14 -> V_150 = V_147 | V_148 ;
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_73 , L_25 , & V_341 ,
NULL ) ;
if ( ! V_229 && V_341 )
V_14 -> V_150 = V_147 ;
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_74 , L_25 , & V_92 ,
NULL ) ;
if ( ! V_229 && V_92 )
F_198 ( V_14 ) ;
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_54 , L_38 , & V_342 ,
NULL ) ;
if ( V_229 )
V_14 -> V_23 = 0 ;
else
V_14 -> V_23 = V_342 ;
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_75 , L_38 , & V_343 ,
NULL ) ;
if ( V_229 )
V_14 -> V_145 = 0 ;
else
V_14 -> V_145 = F_153 ( V_343 ,
V_344 ) ;
}
static void F_201 ( struct V_13 * V_14 )
{
unsigned long long V_67 ;
unsigned long V_175 ;
unsigned int V_176 ;
unsigned int V_345 ;
int V_229 , V_20 ;
switch ( V_14 -> V_152 ) {
case V_153 :
V_229 = F_152 ( V_298 , V_14 -> V_30 -> V_299 ,
L_76 , L_77 , & V_67 ) ;
if ( F_202 ( V_229 ) )
return;
F_97 ( V_312 L_78 ,
V_67 ) ;
F_105 ( V_14 -> V_80 , V_67 ) ;
F_203 ( V_14 -> V_80 ) ;
return;
case V_256 :
F_172 ( V_14 ) ;
return;
default:
break;
}
F_39 ( & V_14 -> V_30 -> V_73 , L_79 ,
V_313 , V_14 -> V_30 -> V_299 ) ;
V_229 = F_199 ( V_298 , V_14 -> V_30 -> V_299 ,
L_76 , L_80 , & V_67 ,
L_81 , L_38 , & V_345 ,
L_82 , L_83 , & V_175 ,
NULL ) ;
if ( V_229 ) {
F_142 ( V_14 -> V_30 , V_229 ,
L_84 ,
V_14 -> V_30 -> V_299 ) ;
return;
}
V_229 = F_152 ( V_298 , V_14 -> V_30 -> V_299 ,
L_85 , L_38 , & V_176 ) ;
if ( V_229 != 1 )
V_176 = V_175 ;
F_173 ( V_14 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ ) {
V_229 = F_174 ( & V_14 -> V_2 [ V_20 ] ) ;
if ( V_229 ) {
F_142 ( V_14 -> V_30 , V_229 , L_86 ,
V_14 -> V_30 -> V_299 ) ;
F_124 ( V_14 , 0 ) ;
break;
}
}
V_229 = F_99 ( V_67 , V_14 , V_345 , V_175 ,
V_176 ) ;
if ( V_229 ) {
F_142 ( V_14 -> V_30 , V_229 , L_87 ,
V_14 -> V_30 -> V_299 ) ;
return;
}
F_157 ( V_14 -> V_30 , V_324 ) ;
V_14 -> V_152 = V_153 ;
for ( V_20 = 0 ; V_20 < V_14 -> V_167 ; V_20 ++ )
F_116 ( & V_14 -> V_2 [ V_20 ] ) ;
F_204 ( V_14 -> V_80 ) ;
V_14 -> V_346 = 1 ;
}
static void F_205 ( struct V_283 * V_73 ,
enum V_347 V_348 )
{
struct V_13 * V_14 = F_186 ( & V_73 -> V_73 ) ;
F_39 ( & V_73 -> V_73 , L_88 , V_348 ) ;
switch ( V_348 ) {
case V_349 :
if ( V_73 -> V_334 != V_350 )
break;
if ( F_151 ( V_73 , V_14 ) )
break;
case V_350 :
case V_308 :
case V_351 :
case V_352 :
case V_353 :
break;
case V_324 :
if ( ( V_73 -> V_334 != V_308 ) &&
( V_73 -> V_334 != V_324 ) ) {
if ( F_151 ( V_73 , V_14 ) )
break;
}
F_201 ( V_14 ) ;
break;
case V_354 :
if ( V_73 -> V_334 == V_354 )
break;
case V_335 :
if ( V_14 )
F_191 ( V_14 ) ;
break;
}
}
static int F_206 ( struct V_283 * V_30 )
{
struct V_13 * V_14 = F_186 ( & V_30 -> V_73 ) ;
struct V_59 * V_68 = NULL ;
struct V_79 * V_355 ;
F_39 ( & V_30 -> V_73 , L_89 , V_30 -> V_302 ) ;
F_124 ( V_14 , 0 ) ;
F_192 ( & V_14 -> V_314 ) ;
V_355 = V_14 -> V_80 ;
if ( V_355 )
V_68 = F_194 ( V_355 , 0 ) ;
V_14 -> V_30 = NULL ;
F_193 ( & V_14 -> V_314 ) ;
if ( ! V_68 ) {
F_8 ( V_14 ) ;
return 0 ;
}
F_192 ( & V_68 -> V_336 ) ;
V_14 = V_355 -> V_72 ;
F_156 ( F_207 ( V_355 ) ,
L_90 ,
V_30 -> V_302 , V_68 -> V_337 ) ;
if ( V_14 && ! V_68 -> V_337 ) {
F_108 ( V_14 ) ;
V_355 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
F_193 ( & V_68 -> V_336 ) ;
F_197 ( V_68 ) ;
return 0 ;
}
static int F_208 ( struct V_283 * V_73 )
{
struct V_13 * V_14 = F_186 ( & V_73 -> V_73 ) ;
return V_14 -> V_346 && V_14 -> V_30 ;
}
static int F_209 ( struct V_59 * V_68 , T_3 V_69 )
{
struct V_79 * V_355 = V_68 -> V_64 ;
struct V_13 * V_14 ;
int V_229 = 0 ;
F_192 ( & V_356 ) ;
V_14 = V_355 -> V_72 ;
if ( ! V_14 ) {
V_229 = - V_357 ;
goto V_234;
}
F_192 ( & V_14 -> V_314 ) ;
if ( ! V_14 -> V_80 )
V_229 = - V_357 ;
F_193 ( & V_14 -> V_314 ) ;
V_234:
F_193 ( & V_356 ) ;
return V_229 ;
}
static void F_210 ( struct V_79 * V_355 , T_3 V_69 )
{
struct V_13 * V_14 = V_355 -> V_72 ;
struct V_59 * V_68 ;
struct V_283 * V_30 ;
F_192 ( & V_356 ) ;
V_68 = F_194 ( V_355 , 0 ) ;
if ( ! V_68 ) {
F_129 ( 1 , L_91 , V_355 -> V_197 ) ;
goto V_358;
}
if ( V_68 -> V_337 )
goto V_234;
F_192 ( & V_14 -> V_314 ) ;
V_30 = V_14 -> V_30 ;
if ( V_30 && V_30 -> V_334 == V_335 ) {
V_4 ( F_207 ( V_68 -> V_64 ) , L_92 ) ;
F_108 ( V_14 ) ;
F_195 ( V_14 -> V_30 ) ;
}
F_193 ( & V_14 -> V_314 ) ;
if ( ! V_30 ) {
V_4 ( F_207 ( V_68 -> V_64 ) , L_92 ) ;
F_108 ( V_14 ) ;
V_355 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
V_234:
F_197 ( V_68 ) ;
V_358:
F_193 ( & V_356 ) ;
}
static int T_9 F_211 ( void )
{
int V_359 ;
int V_360 = F_212 () ;
if ( ! F_213 () )
return - V_225 ;
if ( V_300 > V_361 ) {
F_93 ( L_93 ,
V_300 , V_361 ) ;
V_300 = V_361 ;
}
if ( V_310 > V_360 ) {
F_93 ( L_94 ,
V_310 , V_360 ) ;
V_310 = V_360 ;
}
if ( ! F_214 () )
return - V_225 ;
if ( F_215 ( V_223 , V_236 ) ) {
F_97 ( V_224 L_95 ,
V_223 , V_236 ) ;
return - V_225 ;
}
V_359 = F_216 ( & V_362 ) ;
if ( V_359 ) {
F_217 ( V_223 , V_236 ) ;
return V_359 ;
}
return 0 ;
}
static void T_10 F_218 ( void )
{
F_219 ( & V_362 ) ;
F_217 ( V_223 , V_236 ) ;
F_8 ( V_54 ) ;
}
