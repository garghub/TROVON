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
if ( F_46 ( V_6 ) == V_96 && V_14 -> V_97 )
V_84 -> V_7 . V_92 . V_98 = V_99 ;
else
V_84 -> V_7 . V_92 . V_98 = 0 ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_84 ;
return 0 ;
}
static void F_47 ( unsigned long V_33 , unsigned int V_100 ,
unsigned int V_101 , void * V_102 )
{
struct V_103 * V_104 = V_102 ;
int V_19 , V_105 ;
struct V_17 * V_18 ;
unsigned int V_106 , V_107 ;
unsigned int V_108 = V_104 -> V_108 ;
struct V_83 * V_84 = V_104 -> V_84 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_109 * V_5 = & V_2 -> V_5 [ V_104 -> V_9 ] ;
if ( F_48 ( V_104 -> V_110 &&
V_108 >= V_111 ) ) {
V_108 -= V_111 ;
V_84 = V_104 -> V_112 ;
}
if ( ( V_84 -> V_91 == V_113 ) &&
( V_108 % V_114 == 0 ) ) {
if ( V_104 -> V_115 )
F_49 ( V_104 -> V_115 ) ;
V_19 = V_108 / V_114 ;
V_18 = F_21 ( & V_104 -> V_32 , V_2 ) ;
V_5 -> V_116 [ V_19 ] = V_18 ;
V_104 -> V_115 = F_50 ( V_18 -> V_15 ) ;
V_84 -> V_7 . V_117 . V_118 [ V_19 ] = V_18 -> V_24 ;
}
V_18 = F_18 ( & V_104 -> V_32 , V_33 , V_2 ) ;
V_105 = V_18 -> V_24 ;
V_5 -> V_119 [ V_104 -> V_108 ] = V_18 ;
if ( V_104 -> V_120 ) {
void * V_121 ;
V_121 = F_50 ( V_18 -> V_15 ) ;
memcpy ( V_121 + V_100 ,
V_104 -> V_122 + V_104 -> V_123 ,
V_101 ) ;
F_49 ( V_121 ) ;
V_104 -> V_123 += V_101 ;
}
V_106 = V_100 >> 9 ;
V_107 = V_106 + ( V_101 >> 9 ) - 1 ;
if ( V_84 -> V_91 != V_113 ) {
V_84 -> V_7 . V_8 . V_124 [ V_108 ] =
(struct V_125 ) {
. V_24 = V_105 ,
. V_126 = V_106 ,
. V_127 = V_107 } ;
} else {
V_104 -> V_115 [ V_108 % V_114 ] =
(struct V_125 ) {
. V_24 = V_105 ,
. V_126 = V_106 ,
. V_127 = V_107 } ;
}
( V_104 -> V_108 ) ++ ;
}
static void F_51 ( struct V_83 * V_128 ,
struct V_83 * V_129 )
{
T_4 V_130 = V_128 -> V_7 . V_8 . V_130 ;
V_128 -> V_7 . V_8 . V_130 = V_111 ;
V_129 -> V_7 . V_8 . V_130 = V_130 - V_111 ;
V_129 -> V_7 . V_8 . V_94 = V_128 -> V_7 . V_8 . V_94 +
( V_111 * V_131 ) / 512 ;
V_129 -> V_7 . V_8 . V_132 = V_128 -> V_7 . V_8 . V_132 ;
V_129 -> V_91 = V_128 -> V_91 ;
}
static int F_52 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_83 * V_84 , * V_112 = NULL ;
unsigned long V_9 , V_133 = V_90 ;
bool V_110 = false ;
int V_20 ;
struct V_103 V_104 = {
. V_108 = 0 ,
. V_115 = NULL ,
. V_2 = V_2 ,
. V_120 = F_53 ( V_6 ) && V_14 -> V_23 ,
} ;
struct V_134 * V_135 ;
int V_136 , V_137 , V_138 ;
V_137 = V_6 -> V_139 * V_140 ;
if ( V_137 > V_111 )
V_137 += F_54 ( V_137 ) ;
if ( V_137 > 0 )
if ( F_55 ( V_137 , & V_104 . V_32 ) < 0 ) {
F_56 (
& V_2 -> V_141 ,
F_33 ,
V_2 ,
V_137 ) ;
return 1 ;
}
V_9 = F_41 ( V_2 , V_6 , & V_84 ) ;
V_136 = F_57 ( V_6 -> V_142 , V_6 , V_2 -> V_5 [ V_9 ] . V_135 ) ;
V_138 = 0 ;
F_58 (rinfo->shadow[id].sg, sg, num_sg, i)
V_138 += F_59 ( V_135 -> V_100 , V_135 -> V_143 ) ;
V_110 = V_14 -> V_144 == 0 &&
V_138 > V_111 ;
F_2 ( ! V_145 && V_110 ) ;
V_2 -> V_5 [ V_9 ] . V_136 = V_136 ;
if ( V_138 > V_111 &&
F_60 ( ! V_110 ) ) {
F_2 ( F_46 ( V_6 ) == V_146 || V_6 -> V_147 & V_148 ) ;
V_84 -> V_91 = V_113 ;
V_84 -> V_7 . V_117 . V_149 = F_53 ( V_6 ) ?
V_41 : V_40 ;
V_84 -> V_7 . V_117 . V_94 = ( V_95 ) F_45 ( V_6 ) ;
V_84 -> V_7 . V_117 . V_132 = V_14 -> V_132 ;
V_84 -> V_7 . V_117 . V_130 = V_138 ;
} else {
V_84 -> V_7 . V_8 . V_94 = ( V_95 ) F_45 ( V_6 ) ;
V_84 -> V_7 . V_8 . V_132 = V_14 -> V_132 ;
V_84 -> V_91 = F_53 ( V_6 ) ?
V_41 : V_40 ;
if ( F_46 ( V_6 ) == V_146 || V_6 -> V_147 & V_148 ) {
if ( V_14 -> V_150 && V_14 -> V_151 )
V_84 -> V_91 =
V_42 ;
else if ( V_14 -> V_150 )
V_84 -> V_91 =
V_43 ;
else
V_84 -> V_91 = 0 ;
}
V_84 -> V_7 . V_8 . V_130 = V_138 ;
if ( F_48 ( V_110 ) ) {
V_133 = F_41 ( V_2 , V_6 ,
& V_112 ) ;
V_2 -> V_5 [ V_133 ] . V_136 = 0 ;
F_51 ( V_84 , V_112 ) ;
V_2 -> V_5 [ V_133 ] . V_89 = V_9 ;
V_2 -> V_5 [ V_9 ] . V_89 = V_133 ;
}
}
V_104 . V_84 = V_84 ;
V_104 . V_9 = V_9 ;
V_104 . V_110 = V_110 ;
if ( F_48 ( V_110 ) )
V_104 . V_112 = V_112 ;
F_58 (rinfo->shadow[id].sg, sg, num_sg, i) {
F_2 ( V_135 -> V_100 + V_135 -> V_143 > V_152 ) ;
if ( V_104 . V_120 ) {
V_104 . V_123 = V_135 -> V_100 ;
V_104 . V_122 = F_50 ( F_61 ( V_135 ) ) ;
}
F_62 ( F_61 ( V_135 ) ,
V_135 -> V_100 ,
V_135 -> V_143 ,
F_47 ,
& V_104 ) ;
if ( V_104 . V_120 )
F_49 ( V_104 . V_122 ) ;
}
if ( V_104 . V_115 )
F_49 ( V_104 . V_115 ) ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_84 ;
if ( F_48 ( V_110 ) )
V_2 -> V_5 [ V_133 ] . V_6 = * V_112 ;
if ( V_137 > 0 )
F_63 ( V_104 . V_32 ) ;
return 0 ;
}
static int F_64 ( struct V_11 * V_6 , struct V_1 * V_2 )
{
if ( F_48 ( V_2 -> V_4 -> V_153 != V_154 ) )
return 1 ;
if ( F_48 ( F_46 ( V_6 ) == V_155 ||
F_46 ( V_6 ) == V_96 ) )
return F_43 ( V_6 , V_2 ) ;
else
return F_52 ( V_6 , V_2 ) ;
}
static inline void F_65 ( struct V_1 * V_2 )
{
int V_156 ;
F_66 ( & V_2 -> V_85 , V_156 ) ;
if ( V_156 )
F_67 ( V_2 -> V_157 ) ;
}
static inline bool F_68 ( struct V_11 * V_6 ,
struct V_13 * V_14 )
{
return ( ( V_6 -> V_158 != V_159 ) ||
( ( F_46 ( V_6 ) == V_146 ) &&
! V_14 -> V_150 ) ||
( ( V_6 -> V_147 & V_148 ) &&
! V_14 -> V_151 ) ) ;
}
static int F_69 ( struct V_160 * V_161 ,
const struct V_162 * V_163 )
{
unsigned long V_81 ;
int V_164 = V_161 -> V_165 ;
struct V_13 * V_14 = V_161 -> V_166 -> V_167 ;
struct V_1 * V_2 = NULL ;
F_2 ( V_14 -> V_168 <= V_164 ) ;
V_2 = & V_14 -> V_2 [ V_164 ] ;
F_70 ( V_163 -> V_169 ) ;
F_71 ( & V_2 -> V_170 , V_81 ) ;
if ( F_72 ( & V_2 -> V_85 ) )
goto V_171;
if ( F_68 ( V_163 -> V_169 , V_2 -> V_4 ) )
goto V_172;
if ( F_64 ( V_163 -> V_169 , V_2 ) )
goto V_171;
F_65 ( V_2 ) ;
F_73 ( & V_2 -> V_170 , V_81 ) ;
return V_173 ;
V_172:
F_73 ( & V_2 -> V_170 , V_81 ) ;
return V_174 ;
V_171:
F_73 ( & V_2 -> V_170 , V_81 ) ;
F_74 ( V_161 ) ;
return V_175 ;
}
static void F_75 ( struct V_13 * V_14 )
{
struct V_176 * V_169 = V_14 -> V_169 ;
struct V_79 * V_80 = V_14 -> V_80 ;
unsigned int V_115 = V_14 -> V_144 ? :
V_111 ;
F_76 ( V_177 , V_169 ) ;
if ( V_14 -> V_178 ) {
F_76 ( V_179 , V_169 ) ;
F_77 ( V_169 , F_36 ( V_80 ) ) ;
V_169 -> V_180 . V_181 = V_14 -> V_181 ;
V_169 -> V_180 . V_182 = V_14 -> V_182 ;
if ( V_14 -> V_97 )
F_76 ( V_183 , V_169 ) ;
}
F_78 ( V_169 , V_14 -> V_184 ) ;
F_79 ( V_169 , V_14 -> V_185 ) ;
F_80 ( V_169 , ( V_115 * V_131 ) / 512 ) ;
F_81 ( V_169 , V_152 - 1 ) ;
F_82 ( V_169 , V_152 ) ;
F_83 ( V_169 , V_115 / V_140 ) ;
F_84 ( V_169 , 511 ) ;
F_85 ( V_169 , V_186 ) ;
}
static int F_86 ( struct V_79 * V_80 , T_5 V_184 ,
unsigned int V_185 )
{
struct V_176 * V_169 ;
struct V_13 * V_14 = V_80 -> V_72 ;
memset ( & V_14 -> V_187 , 0 , sizeof( V_14 -> V_187 ) ) ;
V_14 -> V_187 . V_188 = & V_189 ;
V_14 -> V_187 . V_190 = V_14 -> V_168 ;
if ( V_145 && V_14 -> V_144 == 0 ) {
V_14 -> V_187 . V_191 = F_3 ( V_14 ) / 2 ;
} else
V_14 -> V_187 . V_191 = F_3 ( V_14 ) ;
V_14 -> V_187 . V_192 = V_193 ;
V_14 -> V_187 . V_81 = V_194 | V_195 ;
V_14 -> V_187 . V_196 = 0 ;
V_14 -> V_187 . V_197 = V_14 ;
if ( F_87 ( & V_14 -> V_187 ) )
return - V_10 ;
V_169 = F_88 ( & V_14 -> V_187 ) ;
if ( F_89 ( V_169 ) ) {
F_90 ( & V_14 -> V_187 ) ;
return F_91 ( V_169 ) ;
}
V_169 -> V_167 = V_14 ;
V_14 -> V_169 = V_80 -> V_166 = V_169 ;
V_14 -> V_80 = V_80 ;
V_14 -> V_184 = V_184 ;
V_14 -> V_185 = V_185 ;
F_75 ( V_14 ) ;
return 0 ;
}
static const char * F_92 ( struct V_13 * V_14 )
{
if ( V_14 -> V_150 && V_14 -> V_151 )
return L_10 ;
else if ( V_14 -> V_150 )
return L_11 ;
else
return L_12 ;
}
static void F_93 ( struct V_13 * V_14 )
{
F_94 ( V_14 -> V_169 , V_14 -> V_150 ? true : false ,
V_14 -> V_151 ? true : false ) ;
F_95 ( L_13 ,
V_14 -> V_80 -> V_198 , F_92 ( V_14 ) ,
L_14 , V_14 -> V_23 ?
L_15 : L_16 , L_17 ,
V_14 -> V_144 ? L_15 : L_16 ) ;
}
static int F_96 ( int V_199 , int * V_45 , unsigned int * V_100 )
{
int V_200 ;
V_200 = F_97 ( V_199 ) ;
* V_45 = F_98 ( V_199 ) ;
switch ( V_200 ) {
case V_201 :
* V_100 = ( * V_45 / 64 ) + V_202 ;
* V_45 = ( ( * V_45 / 64 ) * V_203 ) +
V_204 ;
break;
case V_205 :
* V_100 = ( * V_45 / 64 ) + 2 + V_202 ;
* V_45 = ( ( ( * V_45 / 64 ) + 2 ) * V_203 ) +
V_204 ;
break;
case V_206 :
* V_100 = ( * V_45 / V_203 ) + V_207 ;
* V_45 = * V_45 + V_208 ;
break;
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
* V_100 = ( * V_45 / V_203 ) +
( ( V_200 - V_209 + 1 ) * 16 ) +
V_207 ;
* V_45 = * V_45 +
( ( V_200 - V_209 + 1 ) * 16 * V_203 ) +
V_208 ;
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
* V_100 = ( * V_45 / V_203 ) +
( ( V_200 - V_216 + 8 ) * 16 ) +
V_207 ;
* V_45 = * V_45 +
( ( V_200 - V_216 + 8 ) * 16 * V_203 ) +
V_208 ;
break;
case V_224 :
* V_100 = * V_45 / V_203 ;
break;
default:
F_99 ( V_225 L_18
L_19 ) ;
return - V_226 ;
}
return 0 ;
}
static char * F_100 ( char * V_227 , unsigned int V_19 )
{
if ( V_19 >= 26 )
V_227 = F_100 ( V_227 , V_19 / 26 - 1 ) ;
* V_227 = 'a' + V_19 % 26 ;
return V_227 + 1 ;
}
static int F_101 ( V_95 V_228 ,
struct V_13 * V_14 ,
T_5 V_229 , T_5 V_184 ,
unsigned int V_185 )
{
struct V_79 * V_80 ;
int V_49 = 1 ;
int V_230 ;
unsigned int V_100 ;
int V_45 ;
int V_231 ;
char * V_227 ;
F_2 ( V_14 -> V_80 != NULL ) ;
F_2 ( V_14 -> V_169 != NULL ) ;
if ( ( V_14 -> V_199 >> V_232 ) > 1 ) {
F_99 ( V_225 L_20 , V_14 -> V_199 ) ;
return - V_226 ;
}
if ( ! F_102 ( V_14 -> V_199 ) ) {
V_230 = F_96 ( V_14 -> V_199 , & V_45 , & V_100 ) ;
if ( V_230 )
return V_230 ;
V_231 = V_203 ;
} else {
V_45 = F_103 ( V_14 -> V_199 ) ;
V_231 = V_233 ;
V_100 = V_45 / V_231 ;
if ( F_104 () && V_100 < V_202 + 4 )
F_99 ( V_225 L_21
L_22
L_23 , V_14 -> V_199 ) ;
}
if ( V_45 >> V_234 ) {
F_105 ( L_24 ,
V_14 -> V_199 , V_45 ) ;
return - V_226 ;
}
if ( ( V_45 % V_231 ) == 0 )
V_49 = V_231 ;
V_230 = F_24 ( V_45 , V_49 ) ;
if ( V_230 )
goto V_235;
V_230 = - V_226 ;
V_80 = F_106 ( V_49 ) ;
if ( V_80 == NULL )
goto V_236;
strcpy ( V_80 -> V_198 , V_237 ) ;
V_227 = F_100 ( V_80 -> V_198 + sizeof( V_237 ) - 1 , V_100 ) ;
F_2 ( V_227 >= V_80 -> V_198 + V_238 ) ;
if ( V_49 > 1 )
* V_227 = 0 ;
else
snprintf ( V_227 , V_80 -> V_198 + V_238 - V_227 ,
L_25 , V_45 & ( V_231 - 1 ) ) ;
V_80 -> V_200 = V_224 ;
V_80 -> V_239 = V_45 ;
V_80 -> V_240 = & V_241 ;
V_80 -> V_72 = V_14 ;
F_107 ( V_80 , V_228 ) ;
if ( F_86 ( V_80 , V_184 , V_185 ) ) {
F_108 ( V_80 ) ;
goto V_236;
}
F_93 ( V_14 ) ;
if ( V_229 & V_242 )
F_109 ( V_80 , 1 ) ;
if ( V_229 & V_243 )
V_80 -> V_81 |= V_244 ;
if ( V_229 & V_245 )
V_80 -> V_81 |= V_82 ;
return 0 ;
V_236:
F_31 ( V_45 , V_49 ) ;
V_235:
return V_230 ;
}
static void F_110 ( struct V_13 * V_14 )
{
unsigned int V_45 , V_49 , V_20 ;
if ( V_14 -> V_169 == NULL )
return;
F_111 ( V_14 -> V_169 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
F_112 ( & V_2 -> V_141 ) ;
F_113 ( & V_2 -> V_58 ) ;
}
F_108 ( V_14 -> V_80 ) ;
V_45 = V_14 -> V_80 -> V_239 ;
V_49 = V_14 -> V_80 -> V_54 ;
F_31 ( V_45 , V_49 ) ;
F_114 ( V_14 -> V_169 ) ;
F_90 ( & V_14 -> V_187 ) ;
V_14 -> V_169 = NULL ;
F_115 ( V_14 -> V_80 ) ;
V_14 -> V_80 = NULL ;
}
static inline void F_116 ( struct V_1 * V_2 )
{
if ( ! F_72 ( & V_2 -> V_85 ) )
F_117 ( V_2 -> V_4 -> V_169 , true ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
unsigned long V_81 ;
F_71 ( & V_2 -> V_170 , V_81 ) ;
F_116 ( V_2 ) ;
F_73 ( & V_2 -> V_170 , V_81 ) ;
}
static void F_119 ( struct V_246 * V_58 )
{
struct V_1 * V_2 = F_120 ( V_58 , struct V_1 , V_58 ) ;
if ( V_2 -> V_4 -> V_153 == V_154 )
F_118 ( V_2 ) ;
}
static void F_121 ( struct V_1 * V_2 )
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
F_122 ( V_247 -> V_24 ,
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
V_249 = V_2 -> V_5 [ V_20 ] . V_6 . V_91 == V_113 ?
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_117 . V_130 :
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_8 . V_130 ;
for ( V_248 = 0 ; V_248 < V_249 ; V_248 ++ ) {
V_247 = V_2 -> V_5 [ V_20 ] . V_119 [ V_248 ] ;
F_122 ( V_247 -> V_24 , 0 , 0UL ) ;
if ( V_14 -> V_23 )
F_12 ( V_247 -> V_15 ) ;
F_8 ( V_247 ) ;
}
if ( V_2 -> V_5 [ V_20 ] . V_6 . V_91 != V_113 )
goto V_250;
for ( V_248 = 0 ; V_248 < F_54 ( V_249 ) ; V_248 ++ ) {
V_247 = V_2 -> V_5 [ V_20 ] . V_116 [ V_248 ] ;
F_122 ( V_247 -> V_24 , 0 , 0UL ) ;
F_12 ( V_247 -> V_15 ) ;
F_8 ( V_247 ) ;
}
V_250:
F_8 ( V_2 -> V_5 [ V_20 ] . V_119 ) ;
V_2 -> V_5 [ V_20 ] . V_119 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_116 ) ;
V_2 -> V_5 [ V_20 ] . V_116 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_135 ) ;
V_2 -> V_5 [ V_20 ] . V_135 = NULL ;
}
F_112 ( & V_2 -> V_141 ) ;
F_113 ( & V_2 -> V_58 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ ) {
if ( V_2 -> V_252 [ V_20 ] != V_25 ) {
F_122 ( V_2 -> V_252 [ V_20 ] , 0 , 0 ) ;
V_2 -> V_252 [ V_20 ] = V_25 ;
}
}
F_123 ( ( unsigned long ) V_2 -> V_85 . V_253 , F_124 ( V_14 -> V_251 * V_131 ) ) ;
V_2 -> V_85 . V_253 = NULL ;
if ( V_2 -> V_157 )
F_125 ( V_2 -> V_157 , V_2 ) ;
V_2 -> V_254 = V_2 -> V_157 = 0 ;
}
static void F_126 ( struct V_13 * V_14 , int V_255 )
{
unsigned int V_20 ;
V_14 -> V_153 = V_255 ?
V_256 : V_257 ;
if ( V_14 -> V_169 )
F_111 ( V_14 -> V_169 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ )
F_121 ( & V_14 -> V_2 [ V_20 ] ) ;
F_8 ( V_14 -> V_2 ) ;
V_14 -> V_2 = NULL ;
V_14 -> V_168 = 0 ;
}
static void F_127 ( unsigned long V_33 , unsigned int V_100 ,
unsigned int V_101 , void * V_102 )
{
struct V_258 * V_14 = V_102 ;
char * V_121 ;
const struct V_109 * V_259 = V_14 -> V_259 ;
V_121 = F_50 ( V_259 -> V_119 [ V_14 -> V_108 ] -> V_15 ) ;
memcpy ( V_14 -> V_122 + V_14 -> V_260 ,
V_121 + V_100 , V_101 ) ;
V_14 -> V_260 += V_101 ;
V_14 -> V_108 ++ ;
F_49 ( V_121 ) ;
}
static enum V_261 F_128 ( int V_262 )
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
static int F_129 ( enum V_261 V_269 ,
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
static bool F_130 ( unsigned long * V_9 ,
struct V_1 * V_2 ,
struct V_271 * V_272 )
{
int V_20 = 0 ;
struct V_134 * V_135 ;
int V_136 , V_138 ;
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_109 * V_259 = & V_2 -> V_5 [ * V_9 ] ;
struct V_258 V_102 = {
. V_108 = 0 ,
} ;
V_138 = V_259 -> V_6 . V_91 == V_113 ?
V_259 -> V_6 . V_7 . V_117 . V_130 : V_259 -> V_6 . V_7 . V_8 . V_130 ;
if ( F_48 ( V_259 -> V_89 != V_90 ) ) {
struct V_109 * V_270 = & V_2 -> V_5 [ V_259 -> V_89 ] ;
V_259 -> V_87 = F_128 ( V_272 -> V_87 ) ;
if ( V_270 -> V_87 == V_88 )
return 0 ;
V_272 -> V_87 = F_129 ( V_259 -> V_87 ,
V_270 -> V_87 ) ;
V_138 += V_270 -> V_6 . V_7 . V_8 . V_130 ;
if ( V_270 -> V_136 != 0 ) {
* V_9 = V_259 -> V_89 ;
V_259 = V_270 ;
}
if ( F_4 ( V_2 , V_259 -> V_89 ) )
F_131 ( 1 , L_26 ,
V_14 -> V_80 -> V_198 , V_259 -> V_89 ) ;
}
V_102 . V_259 = V_259 ;
V_136 = V_259 -> V_136 ;
if ( V_272 -> V_91 == V_40 && V_14 -> V_23 ) {
F_58 (s->sg, sg, num_sg, i) {
F_2 ( V_135 -> V_100 + V_135 -> V_143 > V_152 ) ;
V_102 . V_260 = V_135 -> V_100 ;
V_102 . V_122 = F_50 ( F_61 ( V_135 ) ) ;
F_62 ( F_61 ( V_135 ) ,
V_135 -> V_100 ,
V_135 -> V_143 ,
F_127 ,
& V_102 ) ;
F_49 ( V_102 . V_122 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_138 ; V_20 ++ ) {
if ( F_132 ( V_259 -> V_119 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_133 ( L_27 ,
V_259 -> V_119 [ V_20 ] -> V_24 ) ;
F_9 ( & V_259 -> V_119 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
F_122 ( V_259 -> V_119 [ V_20 ] -> V_24 , 0 , 0UL ) ;
V_259 -> V_119 [ V_20 ] -> V_24 = V_25 ;
F_134 ( & V_259 -> V_119 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
if ( V_259 -> V_6 . V_91 == V_113 ) {
for ( V_20 = 0 ; V_20 < F_54 ( V_138 ) ; V_20 ++ ) {
if ( F_132 ( V_259 -> V_116 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_133 ( L_27 ,
V_259 -> V_116 [ V_20 ] -> V_24 ) ;
F_9 ( & V_259 -> V_116 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
struct V_15 * V_35 ;
F_122 ( V_259 -> V_116 [ V_20 ] -> V_24 , 0 , 0UL ) ;
if ( ! V_14 -> V_23 ) {
V_35 = V_259 -> V_116 [ V_20 ] -> V_15 ;
F_9 ( & V_35 -> V_37 , & V_2 -> V_36 ) ;
}
V_259 -> V_116 [ V_20 ] -> V_24 = V_25 ;
F_134 ( & V_259 -> V_116 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
}
return 1 ;
}
static T_6 F_135 ( int V_157 , void * V_273 )
{
struct V_11 * V_6 ;
struct V_271 * V_272 ;
T_7 V_20 , V_274 ;
unsigned long V_81 ;
struct V_1 * V_2 = (struct V_1 * ) V_273 ;
struct V_13 * V_14 = V_2 -> V_4 ;
int error ;
if ( F_48 ( V_14 -> V_153 != V_154 ) )
return V_275 ;
F_71 ( & V_2 -> V_170 , V_81 ) ;
V_276:
V_274 = V_2 -> V_85 . V_253 -> V_277 ;
F_136 () ;
for ( V_20 = V_2 -> V_85 . V_278 ; V_20 != V_274 ; V_20 ++ ) {
unsigned long V_9 ;
V_272 = F_137 ( & V_2 -> V_85 , V_20 ) ;
V_9 = V_272 -> V_9 ;
if ( V_9 >= F_3 ( V_14 ) ) {
F_131 ( 1 , L_28 ,
V_14 -> V_80 -> V_198 , F_22 ( V_272 -> V_91 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_272 -> V_91 != V_44 ) {
if ( ! F_130 ( & V_9 , V_2 , V_272 ) )
continue;
}
if ( F_4 ( V_2 , V_9 ) ) {
F_131 ( 1 , L_29 ,
V_14 -> V_80 -> V_198 , F_22 ( V_272 -> V_91 ) , V_9 ) ;
continue;
}
error = ( V_272 -> V_87 == V_263 ) ? 0 : - V_279 ;
switch ( V_272 -> V_91 ) {
case V_44 :
if ( F_48 ( V_272 -> V_87 == V_265 ) ) {
struct V_176 * V_169 = V_14 -> V_169 ;
F_99 ( V_225 L_30 ,
V_14 -> V_80 -> V_198 , F_22 ( V_272 -> V_91 ) ) ;
error = - V_280 ;
V_14 -> V_178 = 0 ;
V_14 -> V_97 = 0 ;
F_138 ( V_179 , V_169 ) ;
F_138 ( V_183 , V_169 ) ;
}
F_139 ( V_6 , error ) ;
break;
case V_43 :
case V_42 :
if ( F_48 ( V_272 -> V_87 == V_265 ) ) {
F_99 ( V_225 L_30 ,
V_14 -> V_80 -> V_198 , F_22 ( V_272 -> V_91 ) ) ;
error = - V_280 ;
}
if ( F_48 ( V_272 -> V_87 == V_267 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_130 == 0 ) ) {
F_99 ( V_225 L_31 ,
V_14 -> V_80 -> V_198 , F_22 ( V_272 -> V_91 ) ) ;
error = - V_280 ;
}
if ( F_48 ( error ) ) {
if ( error == - V_280 )
error = 0 ;
V_14 -> V_151 = 0 ;
V_14 -> V_150 = 0 ;
F_93 ( V_14 ) ;
}
case V_40 :
case V_41 :
if ( F_48 ( V_272 -> V_87 != V_263 ) )
F_39 ( & V_14 -> V_30 -> V_73 , L_32
L_33 , V_272 -> V_87 ) ;
F_139 ( V_6 , error ) ;
break;
default:
F_140 () ;
}
}
V_2 -> V_85 . V_278 = V_20 ;
if ( V_20 != V_2 -> V_85 . V_86 ) {
int V_281 ;
F_141 ( & V_2 -> V_85 , V_281 ) ;
if ( V_281 )
goto V_276;
} else
V_2 -> V_85 . V_253 -> V_282 = V_20 + 1 ;
F_116 ( V_2 ) ;
F_73 ( & V_2 -> V_170 , V_81 ) ;
return V_275 ;
}
static int F_142 ( struct V_283 * V_73 ,
struct V_1 * V_2 )
{
struct V_284 * V_253 ;
int V_230 , V_20 ;
struct V_13 * V_14 = V_2 -> V_4 ;
unsigned long V_285 = V_14 -> V_251 * V_131 ;
T_1 V_24 [ V_286 ] ;
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ )
V_2 -> V_252 [ V_20 ] = V_25 ;
V_253 = (struct V_284 * ) F_143 ( V_21 | V_287 ,
F_124 ( V_285 ) ) ;
if ( ! V_253 ) {
F_144 ( V_73 , - V_28 , L_34 ) ;
return - V_28 ;
}
F_145 ( V_253 ) ;
F_146 ( & V_2 -> V_85 , V_253 , V_285 ) ;
V_230 = F_147 ( V_73 , V_2 -> V_85 . V_253 , V_14 -> V_251 , V_24 ) ;
if ( V_230 < 0 ) {
F_123 ( ( unsigned long ) V_253 , F_124 ( V_285 ) ) ;
V_2 -> V_85 . V_253 = NULL ;
goto V_288;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ )
V_2 -> V_252 [ V_20 ] = V_24 [ V_20 ] ;
V_230 = F_148 ( V_73 , & V_2 -> V_254 ) ;
if ( V_230 )
goto V_288;
V_230 = F_149 ( V_2 -> V_254 , F_135 , 0 ,
L_35 , V_2 ) ;
if ( V_230 <= 0 ) {
F_144 ( V_73 , V_230 ,
L_36 ) ;
goto V_288;
}
V_2 -> V_157 = V_230 ;
return 0 ;
V_288:
F_126 ( V_14 , 0 ) ;
return V_230 ;
}
static int F_150 ( struct V_289 V_290 ,
struct V_1 * V_2 , const char * V_291 )
{
int V_230 ;
unsigned int V_20 ;
const char * V_292 = NULL ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_14 -> V_251 == 1 ) {
V_230 = F_151 ( V_290 , V_291 , L_37 , L_38 , V_2 -> V_252 [ 0 ] ) ;
if ( V_230 ) {
V_292 = L_39 ;
goto V_293;
}
} else {
for ( V_20 = 0 ; V_20 < V_14 -> V_251 ; V_20 ++ ) {
char V_294 [ V_295 ] ;
snprintf ( V_294 , V_295 , L_40 , V_20 ) ;
V_230 = F_151 ( V_290 , V_291 , V_294 ,
L_38 , V_2 -> V_252 [ V_20 ] ) ;
if ( V_230 ) {
V_292 = L_39 ;
goto V_293;
}
}
}
V_230 = F_151 ( V_290 , V_291 , L_41 , L_38 , V_2 -> V_254 ) ;
if ( V_230 ) {
V_292 = L_42 ;
goto V_293;
}
return 0 ;
V_293:
F_152 ( V_290 , 1 ) ;
if ( V_292 )
F_144 ( V_14 -> V_30 , V_230 , L_43 , V_292 ) ;
return V_230 ;
}
static int F_153 ( struct V_283 * V_73 ,
struct V_13 * V_14 )
{
const char * V_292 = NULL ;
struct V_289 V_290 ;
int V_230 ;
unsigned int V_20 , V_296 = 0 ;
unsigned int V_297 = 0 ;
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_44 , L_38 , & V_296 ) ;
if ( V_230 != 1 )
V_14 -> V_251 = 1 ;
else {
V_297 = F_155 ( V_300 , V_296 ) ;
V_14 -> V_251 = 1 << V_297 ;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
V_230 = F_142 ( V_73 , V_2 ) ;
if ( V_230 )
goto V_301;
}
V_276:
V_230 = F_156 ( & V_290 ) ;
if ( V_230 ) {
F_144 ( V_73 , V_230 , L_45 ) ;
goto V_301;
}
if ( V_14 -> V_251 > 1 ) {
V_230 = F_151 ( V_290 , V_73 -> V_302 , L_46 , L_38 ,
V_297 ) ;
if ( V_230 ) {
V_292 = L_47 ;
goto V_293;
}
}
if ( V_14 -> V_168 == 1 ) {
V_230 = F_150 ( V_290 , & V_14 -> V_2 [ 0 ] , V_73 -> V_302 ) ;
if ( V_230 )
goto V_301;
} else {
char * V_303 ;
T_8 V_304 ;
V_230 = F_151 ( V_290 , V_73 -> V_302 , L_48 , L_38 ,
V_14 -> V_168 ) ;
if ( V_230 ) {
V_292 = L_49 ;
goto V_293;
}
V_304 = strlen ( V_73 -> V_302 ) + V_305 ;
V_303 = F_157 ( V_304 , V_52 ) ;
if ( ! V_303 ) {
V_230 = - V_28 ;
V_292 = L_50 ;
goto V_293;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ ) {
memset ( V_303 , 0 , V_304 ) ;
snprintf ( V_303 , V_304 , L_51 , V_73 -> V_302 , V_20 ) ;
V_230 = F_150 ( V_290 , & V_14 -> V_2 [ V_20 ] , V_303 ) ;
if ( V_230 ) {
F_8 ( V_303 ) ;
goto V_301;
}
}
F_8 ( V_303 ) ;
}
V_230 = F_151 ( V_290 , V_73 -> V_302 , L_52 , L_43 ,
V_306 ) ;
if ( V_230 ) {
V_292 = L_53 ;
goto V_293;
}
V_230 = F_151 ( V_290 , V_73 -> V_302 ,
L_54 , L_38 , 1 ) ;
if ( V_230 )
F_158 ( & V_73 -> V_73 ,
L_55 ) ;
V_230 = F_152 ( V_290 , 0 ) ;
if ( V_230 ) {
if ( V_230 == - V_307 )
goto V_276;
F_144 ( V_73 , V_230 , L_56 ) ;
goto V_301;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ ) {
unsigned int V_248 ;
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
for ( V_248 = 0 ; V_248 < F_3 ( V_14 ) ; V_248 ++ )
V_2 -> V_5 [ V_248 ] . V_6 . V_7 . V_8 . V_9 = V_248 + 1 ;
V_2 -> V_5 [ F_3 ( V_14 ) - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
}
F_159 ( V_73 , V_308 ) ;
return 0 ;
V_293:
F_152 ( V_290 , 1 ) ;
if ( V_292 )
F_144 ( V_73 , V_230 , L_43 , V_292 ) ;
V_301:
F_126 ( V_14 , 0 ) ;
F_8 ( V_14 ) ;
F_160 ( & V_73 -> V_73 , NULL ) ;
return V_230 ;
}
static int F_161 ( struct V_13 * V_14 )
{
unsigned int V_309 = 0 ;
int V_230 ;
unsigned int V_20 ;
F_2 ( V_14 -> V_168 ) ;
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_57 , L_38 , & V_309 ) ;
if ( V_230 < 0 )
V_309 = 1 ;
V_14 -> V_168 = F_155 ( V_309 , V_310 ) ;
if ( ! V_14 -> V_168 )
V_14 -> V_168 = 1 ;
V_14 -> V_2 = F_6 ( sizeof( struct V_1 ) * V_14 -> V_168 , V_52 ) ;
if ( ! V_14 -> V_2 ) {
F_144 ( V_14 -> V_30 , - V_28 , L_58 ) ;
return - V_28 ;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_20 ] ;
F_162 ( & V_2 -> V_36 ) ;
F_162 ( & V_2 -> V_27 ) ;
V_2 -> V_4 = V_14 ;
F_163 ( & V_2 -> V_58 , F_119 ) ;
F_164 ( & V_2 -> V_170 ) ;
}
return 0 ;
}
static int F_165 ( struct V_283 * V_73 ,
const struct V_311 * V_9 )
{
int V_230 , V_199 ;
struct V_13 * V_14 ;
V_230 = F_154 ( V_298 , V_73 -> V_302 ,
L_59 , L_60 , & V_199 ) ;
if ( V_230 != 1 ) {
V_230 = F_154 ( V_298 , V_73 -> V_302 , L_61 ,
L_60 , & V_199 ) ;
if ( V_230 != 1 ) {
F_144 ( V_73 , V_230 , L_62 ) ;
return V_230 ;
}
}
if ( F_104 () ) {
char * type ;
int V_101 ;
if ( F_166 () ) {
int V_200 ;
if ( ! F_102 ( V_199 ) )
V_200 = F_97 ( V_199 ) ;
else
V_200 = V_224 ;
if ( V_200 != V_224 ) {
F_99 ( V_312
L_63 ,
V_313 , V_199 ) ;
return - V_226 ;
}
}
type = F_167 ( V_298 , V_73 -> V_302 , L_64 , & V_101 ) ;
if ( F_89 ( type ) )
return - V_226 ;
if ( strncmp ( type , L_65 , 5 ) == 0 ) {
F_8 ( type ) ;
return - V_226 ;
}
F_8 ( type ) ;
}
V_14 = F_6 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 ) {
F_144 ( V_73 , - V_28 , L_66 ) ;
return - V_28 ;
}
V_14 -> V_30 = V_73 ;
V_230 = F_161 ( V_14 ) ;
if ( V_230 ) {
F_8 ( V_14 ) ;
return V_230 ;
}
F_168 ( & V_14 -> V_314 ) ;
V_14 -> V_199 = V_199 ;
V_14 -> V_153 = V_257 ;
V_14 -> V_132 = F_169 ( strrchr ( V_73 -> V_302 , '/' ) + 1 , NULL , 0 ) ;
F_160 ( & V_73 -> V_73 , V_14 ) ;
return 0 ;
}
static void F_170 ( struct V_315 * V_315 )
{
struct V_316 * V_316 = V_315 -> V_317 ;
if ( F_171 ( & V_316 -> V_318 ) ) {
V_316 -> V_315 -> V_319 = 0 ;
V_316 -> V_315 -> V_320 = V_315 -> V_320 ;
F_172 ( V_316 -> V_315 ) ;
F_8 ( V_316 ) ;
}
F_173 ( V_315 ) ;
}
static int F_174 ( struct V_13 * V_14 )
{
unsigned int V_20 , V_321 ;
struct V_11 * V_6 , * V_19 ;
int V_48 ;
struct V_315 * V_315 , * V_322 ;
unsigned int V_249 , V_100 ;
int V_318 , V_323 ;
struct V_316 * V_316 ;
F_175 ( V_14 ) ;
F_75 ( V_14 ) ;
V_249 = V_14 -> V_144 ? : V_111 ;
F_83 ( V_14 -> V_169 , V_249 / V_140 ) ;
for ( V_321 = 0 ; V_321 < V_14 -> V_168 ; V_321 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_321 ] ;
V_48 = F_176 ( V_2 ) ;
if ( V_48 )
return V_48 ;
}
F_159 ( V_14 -> V_30 , V_324 ) ;
V_14 -> V_153 = V_154 ;
for ( V_321 = 0 ; V_321 < V_14 -> V_168 ; V_321 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_321 ] ;
F_118 ( V_2 ) ;
}
F_10 (req, n, &info->requests, queuelist) {
F_177 ( & V_6 -> V_325 ) ;
F_2 ( V_6 -> V_139 > V_249 ) ;
F_178 ( V_6 ) ;
}
F_179 ( V_14 -> V_169 ) ;
while ( ( V_315 = F_180 ( & V_14 -> V_326 ) ) != NULL ) {
if ( F_181 ( V_315 ) > V_249 ) {
V_318 = ( F_181 ( V_315 ) + V_249 - 1 ) / V_249 ;
V_316 = F_6 ( sizeof( * V_316 ) , V_21 ) ;
F_2 ( V_316 == NULL ) ;
F_182 ( & V_316 -> V_318 , V_318 ) ;
V_316 -> V_315 = V_315 ;
for ( V_20 = 0 ; V_20 < V_318 ; V_20 ++ ) {
V_100 = ( V_20 * V_249 * V_131 ) >> 9 ;
V_323 = F_155 ( ( unsigned int ) ( V_249 * V_131 ) >> 9 ,
( unsigned int ) F_183 ( V_315 ) - V_100 ) ;
V_322 = F_184 ( V_315 , V_21 ) ;
F_2 ( V_322 == NULL ) ;
F_185 ( V_322 , V_100 , V_323 ) ;
V_322 -> V_317 = V_316 ;
V_322 -> V_327 = F_170 ;
F_186 ( V_322 ) ;
}
continue;
}
F_186 ( V_315 ) ;
}
return 0 ;
}
static int F_187 ( struct V_283 * V_73 )
{
struct V_13 * V_14 = F_188 ( & V_73 -> V_73 ) ;
int V_230 = 0 ;
unsigned int V_20 , V_248 ;
F_39 ( & V_73 -> V_73 , L_67 , V_73 -> V_302 ) ;
F_189 ( & V_14 -> V_326 ) ;
F_162 ( & V_14 -> V_328 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
struct V_326 V_329 ;
struct V_109 * V_5 = V_2 -> V_5 ;
for ( V_248 = 0 ; V_248 < F_3 ( V_14 ) ; V_248 ++ ) {
if ( ! V_5 [ V_248 ] . V_11 )
continue;
if ( F_46 ( V_5 [ V_20 ] . V_11 ) == V_146 ||
F_46 ( V_5 [ V_20 ] . V_11 ) == V_155 ||
F_46 ( V_5 [ V_20 ] . V_11 ) == V_96 ||
V_5 [ V_248 ] . V_11 -> V_147 & V_148 ) {
F_9 ( & V_5 [ V_248 ] . V_11 -> V_325 , & V_14 -> V_328 ) ;
continue;
}
V_329 . V_330 = V_5 [ V_248 ] . V_11 -> V_315 ;
V_329 . V_331 = V_5 [ V_248 ] . V_11 -> V_332 ;
F_190 ( & V_14 -> V_326 , & V_329 ) ;
V_5 [ V_248 ] . V_11 -> V_315 = NULL ;
F_191 ( V_5 [ V_248 ] . V_11 , 0 ) ;
}
}
F_126 ( V_14 , V_14 -> V_153 == V_154 ) ;
V_230 = F_161 ( V_14 ) ;
if ( V_230 )
return V_230 ;
V_230 = F_153 ( V_73 , V_14 ) ;
if ( ! V_230 )
F_192 ( & V_14 -> V_187 , V_14 -> V_168 ) ;
return V_230 ;
}
static void F_193 ( struct V_13 * V_14 )
{
struct V_283 * V_30 = V_14 -> V_30 ;
struct V_59 * V_68 = NULL ;
F_194 ( & V_14 -> V_314 ) ;
if ( V_30 -> V_333 == V_334 ) {
F_195 ( & V_14 -> V_314 ) ;
return;
}
if ( V_14 -> V_80 )
V_68 = F_196 ( V_14 -> V_80 , 0 ) ;
F_195 ( & V_14 -> V_314 ) ;
if ( ! V_68 ) {
F_197 ( V_30 ) ;
return;
}
F_194 ( & V_68 -> V_335 ) ;
if ( V_68 -> V_336 ) {
F_198 ( V_30 , - V_56 ,
L_68 ) ;
F_159 ( V_30 , V_334 ) ;
} else {
F_110 ( V_14 ) ;
F_197 ( V_30 ) ;
}
F_195 ( & V_68 -> V_335 ) ;
F_199 ( V_68 ) ;
}
static void F_200 ( struct V_13 * V_14 )
{
int V_230 ;
unsigned int V_181 ;
unsigned int V_182 ;
unsigned int V_337 ;
V_14 -> V_178 = 1 ;
V_230 = F_201 ( V_298 , V_14 -> V_30 -> V_299 ,
L_69 , L_38 , & V_181 ,
L_70 , L_38 , & V_182 ,
NULL ) ;
if ( ! V_230 ) {
V_14 -> V_181 = V_181 ;
V_14 -> V_182 = V_182 ;
}
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_71 , L_38 , & V_337 ) ;
if ( V_230 > 0 )
V_14 -> V_97 = ! ! V_337 ;
}
static int F_176 ( struct V_1 * V_2 )
{
unsigned int V_338 , V_27 ;
int V_230 , V_20 ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_14 -> V_144 == 0 ) {
if ( ! V_145 )
V_27 = V_111 ;
else {
V_27 = V_140 ;
}
}
else
V_27 = V_14 -> V_144 ;
V_338 = V_27 / V_140 ;
V_230 = F_5 ( V_2 ,
( V_27 + F_54 ( V_27 ) ) * F_3 ( V_14 ) ) ;
if ( V_230 )
goto V_22;
if ( ! V_14 -> V_23 && V_14 -> V_144 ) {
int V_12 = F_54 ( V_27 ) * F_3 ( V_14 ) ;
F_2 ( ! F_14 ( & V_2 -> V_36 ) ) ;
for ( V_20 = 0 ; V_20 < V_12 ; V_20 ++ ) {
struct V_15 * V_35 = F_7 ( V_21 ) ;
if ( ! V_35 )
goto V_22;
F_9 ( & V_35 -> V_37 , & V_2 -> V_36 ) ;
}
}
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ ) {
V_2 -> V_5 [ V_20 ] . V_119 = F_6 (
sizeof( V_2 -> V_5 [ V_20 ] . V_119 [ 0 ] ) * V_27 ,
V_21 ) ;
V_2 -> V_5 [ V_20 ] . V_135 = F_6 ( sizeof( V_2 -> V_5 [ V_20 ] . V_135 [ 0 ] ) * V_338 , V_21 ) ;
if ( V_14 -> V_144 )
V_2 -> V_5 [ V_20 ] . V_116 = F_6 (
sizeof( V_2 -> V_5 [ V_20 ] . V_116 [ 0 ] ) *
F_54 ( V_27 ) ,
V_21 ) ;
if ( ( V_2 -> V_5 [ V_20 ] . V_119 == NULL ) ||
( V_2 -> V_5 [ V_20 ] . V_135 == NULL ) ||
( V_14 -> V_144 &&
( V_2 -> V_5 [ V_20 ] . V_116 == NULL ) ) )
goto V_22;
F_202 ( V_2 -> V_5 [ V_20 ] . V_135 , V_338 ) ;
}
return 0 ;
V_22:
for ( V_20 = 0 ; V_20 < F_3 ( V_14 ) ; V_20 ++ ) {
F_8 ( V_2 -> V_5 [ V_20 ] . V_119 ) ;
V_2 -> V_5 [ V_20 ] . V_119 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_135 ) ;
V_2 -> V_5 [ V_20 ] . V_135 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_116 ) ;
V_2 -> V_5 [ V_20 ] . V_116 = NULL ;
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
static void F_175 ( struct V_13 * V_14 )
{
int V_230 ;
int V_339 , V_340 , V_92 , V_341 ;
unsigned int V_342 ;
V_14 -> V_150 = 0 ;
V_14 -> V_151 = 0 ;
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_72 , L_25 , & V_339 ) ;
if ( V_230 > 0 && V_339 ) {
V_14 -> V_150 = 1 ;
V_14 -> V_151 = 1 ;
}
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_73 , L_25 , & V_340 ) ;
if ( V_230 > 0 && V_340 ) {
V_14 -> V_150 = 1 ;
V_14 -> V_151 = 0 ;
}
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_74 , L_25 , & V_92 ) ;
if ( V_230 > 0 && V_92 )
F_200 ( V_14 ) ;
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_54 , L_25 , & V_341 ) ;
if ( V_230 <= 0 )
V_14 -> V_23 = 0 ;
else
V_14 -> V_23 = V_341 ;
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_75 , L_38 ,
& V_342 ) ;
if ( V_230 <= 0 )
V_14 -> V_144 = 0 ;
else
V_14 -> V_144 = F_155 ( V_342 ,
V_343 ) ;
}
static void F_203 ( struct V_13 * V_14 )
{
unsigned long long V_67 ;
unsigned long V_184 ;
unsigned int V_185 ;
unsigned int V_344 ;
int V_230 , V_20 ;
switch ( V_14 -> V_153 ) {
case V_154 :
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_76 , L_77 , & V_67 ) ;
if ( F_204 ( V_230 ) )
return;
F_99 ( V_312 L_78 ,
V_67 ) ;
F_107 ( V_14 -> V_80 , V_67 ) ;
F_205 ( V_14 -> V_80 ) ;
return;
case V_256 :
F_174 ( V_14 ) ;
return;
default:
break;
}
F_39 ( & V_14 -> V_30 -> V_73 , L_79 ,
V_313 , V_14 -> V_30 -> V_299 ) ;
V_230 = F_201 ( V_298 , V_14 -> V_30 -> V_299 ,
L_76 , L_80 , & V_67 ,
L_81 , L_38 , & V_344 ,
L_82 , L_83 , & V_184 ,
NULL ) ;
if ( V_230 ) {
F_144 ( V_14 -> V_30 , V_230 ,
L_84 ,
V_14 -> V_30 -> V_299 ) ;
return;
}
V_230 = F_154 ( V_298 , V_14 -> V_30 -> V_299 ,
L_85 , L_38 , & V_185 ) ;
if ( V_230 != 1 )
V_185 = V_184 ;
F_175 ( V_14 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ ) {
V_230 = F_176 ( & V_14 -> V_2 [ V_20 ] ) ;
if ( V_230 ) {
F_144 ( V_14 -> V_30 , V_230 , L_86 ,
V_14 -> V_30 -> V_299 ) ;
F_126 ( V_14 , 0 ) ;
break;
}
}
V_230 = F_101 ( V_67 , V_14 , V_344 , V_184 ,
V_185 ) ;
if ( V_230 ) {
F_144 ( V_14 -> V_30 , V_230 , L_87 ,
V_14 -> V_30 -> V_299 ) ;
goto V_288;
}
F_159 ( V_14 -> V_30 , V_324 ) ;
V_14 -> V_153 = V_154 ;
for ( V_20 = 0 ; V_20 < V_14 -> V_168 ; V_20 ++ )
F_118 ( & V_14 -> V_2 [ V_20 ] ) ;
F_206 ( & V_14 -> V_30 -> V_73 , V_14 -> V_80 ) ;
V_14 -> V_345 = 1 ;
return;
V_288:
F_126 ( V_14 , 0 ) ;
return;
}
static void F_207 ( struct V_283 * V_73 ,
enum V_346 V_347 )
{
struct V_13 * V_14 = F_188 ( & V_73 -> V_73 ) ;
F_39 ( & V_73 -> V_73 , L_88 , V_347 ) ;
switch ( V_347 ) {
case V_348 :
if ( V_73 -> V_333 != V_349 )
break;
if ( F_153 ( V_73 , V_14 ) )
break;
case V_349 :
case V_308 :
case V_350 :
case V_351 :
case V_352 :
break;
case V_324 :
if ( ( V_73 -> V_333 != V_308 ) &&
( V_73 -> V_333 != V_324 ) ) {
if ( F_153 ( V_73 , V_14 ) )
break;
}
F_203 ( V_14 ) ;
break;
case V_353 :
if ( V_73 -> V_333 == V_353 )
break;
case V_334 :
if ( V_14 )
F_193 ( V_14 ) ;
break;
}
}
static int F_208 ( struct V_283 * V_30 )
{
struct V_13 * V_14 = F_188 ( & V_30 -> V_73 ) ;
struct V_59 * V_68 = NULL ;
struct V_79 * V_354 ;
F_39 ( & V_30 -> V_73 , L_89 , V_30 -> V_302 ) ;
F_126 ( V_14 , 0 ) ;
F_194 ( & V_14 -> V_314 ) ;
V_354 = V_14 -> V_80 ;
if ( V_354 )
V_68 = F_196 ( V_354 , 0 ) ;
V_14 -> V_30 = NULL ;
F_195 ( & V_14 -> V_314 ) ;
if ( ! V_68 ) {
F_8 ( V_14 ) ;
return 0 ;
}
F_194 ( & V_68 -> V_335 ) ;
V_14 = V_354 -> V_72 ;
F_158 ( F_209 ( V_354 ) ,
L_90 ,
V_30 -> V_302 , V_68 -> V_336 ) ;
if ( V_14 && ! V_68 -> V_336 ) {
F_110 ( V_14 ) ;
V_354 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
F_195 ( & V_68 -> V_335 ) ;
F_199 ( V_68 ) ;
return 0 ;
}
static int F_210 ( struct V_283 * V_73 )
{
struct V_13 * V_14 = F_188 ( & V_73 -> V_73 ) ;
return V_14 -> V_345 && V_14 -> V_30 ;
}
static int F_211 ( struct V_59 * V_68 , T_3 V_69 )
{
struct V_79 * V_354 = V_68 -> V_64 ;
struct V_13 * V_14 ;
int V_230 = 0 ;
F_194 ( & V_355 ) ;
V_14 = V_354 -> V_72 ;
if ( ! V_14 ) {
V_230 = - V_356 ;
goto V_235;
}
F_194 ( & V_14 -> V_314 ) ;
if ( ! V_14 -> V_80 )
V_230 = - V_356 ;
F_195 ( & V_14 -> V_314 ) ;
V_235:
F_195 ( & V_355 ) ;
return V_230 ;
}
static void F_212 ( struct V_79 * V_354 , T_3 V_69 )
{
struct V_13 * V_14 = V_354 -> V_72 ;
struct V_59 * V_68 ;
struct V_283 * V_30 ;
F_194 ( & V_355 ) ;
V_68 = F_196 ( V_354 , 0 ) ;
if ( ! V_68 ) {
F_131 ( 1 , L_91 , V_354 -> V_198 ) ;
goto V_357;
}
if ( V_68 -> V_336 )
goto V_235;
F_194 ( & V_14 -> V_314 ) ;
V_30 = V_14 -> V_30 ;
if ( V_30 && V_30 -> V_333 == V_334 ) {
V_4 ( F_209 ( V_68 -> V_64 ) , L_92 ) ;
F_110 ( V_14 ) ;
F_197 ( V_14 -> V_30 ) ;
}
F_195 ( & V_14 -> V_314 ) ;
if ( ! V_30 ) {
V_4 ( F_209 ( V_68 -> V_64 ) , L_92 ) ;
F_110 ( V_14 ) ;
V_354 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
V_235:
F_199 ( V_68 ) ;
V_357:
F_195 ( & V_355 ) ;
}
static int T_9 F_213 ( void )
{
int V_358 ;
int V_359 = F_214 () ;
if ( ! F_215 () )
return - V_226 ;
if ( V_300 > V_360 ) {
F_95 ( L_93 ,
V_300 , V_360 ) ;
V_300 = V_360 ;
}
if ( V_310 > V_359 ) {
F_95 ( L_94 ,
V_310 , V_359 ) ;
V_310 = V_359 ;
}
if ( ! F_216 () )
return - V_226 ;
if ( F_217 ( V_224 , V_237 ) ) {
F_99 ( V_225 L_95 ,
V_224 , V_237 ) ;
return - V_226 ;
}
V_358 = F_218 ( & V_361 ) ;
if ( V_358 ) {
F_219 ( V_224 , V_237 ) ;
return V_358 ;
}
return 0 ;
}
static void T_10 F_220 ( void )
{
F_221 ( & V_361 ) ;
F_219 ( V_224 , V_237 ) ;
F_8 ( V_54 ) ;
}
