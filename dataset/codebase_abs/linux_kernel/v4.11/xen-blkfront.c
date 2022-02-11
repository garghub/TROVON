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
return ( F_69 ( V_6 ) ||
( ( F_46 ( V_6 ) == V_146 ) &&
! V_14 -> V_150 ) ||
( ( V_6 -> V_147 & V_148 ) &&
! V_14 -> V_151 ) ) ;
}
static int F_70 ( struct V_158 * V_159 ,
const struct V_160 * V_161 )
{
unsigned long V_81 ;
int V_162 = V_159 -> V_163 ;
struct V_13 * V_14 = V_159 -> V_164 -> V_165 ;
struct V_1 * V_2 = NULL ;
F_2 ( V_14 -> V_166 <= V_162 ) ;
V_2 = & V_14 -> V_2 [ V_162 ] ;
F_71 ( V_161 -> V_167 ) ;
F_72 ( & V_2 -> V_168 , V_81 ) ;
if ( F_73 ( & V_2 -> V_85 ) )
goto V_169;
if ( F_68 ( V_161 -> V_167 , V_2 -> V_4 ) )
goto V_170;
if ( F_64 ( V_161 -> V_167 , V_2 ) )
goto V_169;
F_65 ( V_2 ) ;
F_74 ( & V_2 -> V_168 , V_81 ) ;
return V_171 ;
V_170:
F_74 ( & V_2 -> V_168 , V_81 ) ;
return V_172 ;
V_169:
F_74 ( & V_2 -> V_168 , V_81 ) ;
F_75 ( V_159 ) ;
return V_173 ;
}
static void F_76 ( struct V_13 * V_14 )
{
struct V_174 * V_167 = V_14 -> V_167 ;
struct V_79 * V_80 = V_14 -> V_80 ;
unsigned int V_115 = V_14 -> V_144 ? :
V_111 ;
F_77 ( V_175 , V_167 ) ;
if ( V_14 -> V_176 ) {
F_77 ( V_177 , V_167 ) ;
F_78 ( V_167 , F_36 ( V_80 ) ) ;
V_167 -> V_178 . V_179 = V_14 -> V_179 ;
V_167 -> V_178 . V_180 = V_14 -> V_180 ;
if ( V_14 -> V_97 )
F_77 ( V_181 , V_167 ) ;
}
F_79 ( V_167 , V_14 -> V_182 ) ;
F_80 ( V_167 , V_14 -> V_183 ) ;
F_81 ( V_167 , ( V_115 * V_131 ) / 512 ) ;
F_82 ( V_167 , V_152 - 1 ) ;
F_83 ( V_167 , V_152 ) ;
F_84 ( V_167 , V_115 / V_140 ) ;
F_85 ( V_167 , 511 ) ;
F_86 ( V_167 , V_184 ) ;
}
static int F_87 ( struct V_79 * V_80 , T_5 V_182 ,
unsigned int V_183 )
{
struct V_174 * V_167 ;
struct V_13 * V_14 = V_80 -> V_72 ;
memset ( & V_14 -> V_185 , 0 , sizeof( V_14 -> V_185 ) ) ;
V_14 -> V_185 . V_186 = & V_187 ;
V_14 -> V_185 . V_188 = V_14 -> V_166 ;
if ( V_145 && V_14 -> V_144 == 0 ) {
V_14 -> V_185 . V_189 = F_3 ( V_14 ) / 2 ;
} else
V_14 -> V_185 . V_189 = F_3 ( V_14 ) ;
V_14 -> V_185 . V_190 = V_191 ;
V_14 -> V_185 . V_81 = V_192 | V_193 ;
V_14 -> V_185 . V_194 = 0 ;
V_14 -> V_185 . V_195 = V_14 ;
if ( F_88 ( & V_14 -> V_185 ) )
return - V_10 ;
V_167 = F_89 ( & V_14 -> V_185 ) ;
if ( F_90 ( V_167 ) ) {
F_91 ( & V_14 -> V_185 ) ;
return F_92 ( V_167 ) ;
}
V_167 -> V_165 = V_14 ;
V_14 -> V_167 = V_80 -> V_164 = V_167 ;
V_14 -> V_80 = V_80 ;
V_14 -> V_182 = V_182 ;
V_14 -> V_183 = V_183 ;
F_76 ( V_14 ) ;
return 0 ;
}
static const char * F_93 ( struct V_13 * V_14 )
{
if ( V_14 -> V_150 && V_14 -> V_151 )
return L_10 ;
else if ( V_14 -> V_150 )
return L_11 ;
else
return L_12 ;
}
static void F_94 ( struct V_13 * V_14 )
{
F_95 ( V_14 -> V_167 , V_14 -> V_150 ? true : false ,
V_14 -> V_151 ? true : false ) ;
F_96 ( L_13 ,
V_14 -> V_80 -> V_196 , F_93 ( V_14 ) ,
L_14 , V_14 -> V_23 ?
L_15 : L_16 , L_17 ,
V_14 -> V_144 ? L_15 : L_16 ) ;
}
static int F_97 ( int V_197 , int * V_45 , unsigned int * V_100 )
{
int V_198 ;
V_198 = F_98 ( V_197 ) ;
* V_45 = F_99 ( V_197 ) ;
switch ( V_198 ) {
case V_199 :
* V_100 = ( * V_45 / 64 ) + V_200 ;
* V_45 = ( ( * V_45 / 64 ) * V_201 ) +
V_202 ;
break;
case V_203 :
* V_100 = ( * V_45 / 64 ) + 2 + V_200 ;
* V_45 = ( ( ( * V_45 / 64 ) + 2 ) * V_201 ) +
V_202 ;
break;
case V_204 :
* V_100 = ( * V_45 / V_201 ) + V_205 ;
* V_45 = * V_45 + V_206 ;
break;
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
* V_100 = ( * V_45 / V_201 ) +
( ( V_198 - V_207 + 1 ) * 16 ) +
V_205 ;
* V_45 = * V_45 +
( ( V_198 - V_207 + 1 ) * 16 * V_201 ) +
V_206 ;
break;
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
* V_100 = ( * V_45 / V_201 ) +
( ( V_198 - V_214 + 8 ) * 16 ) +
V_205 ;
* V_45 = * V_45 +
( ( V_198 - V_214 + 8 ) * 16 * V_201 ) +
V_206 ;
break;
case V_222 :
* V_100 = * V_45 / V_201 ;
break;
default:
F_100 ( V_223 L_18
L_19 ) ;
return - V_224 ;
}
return 0 ;
}
static char * F_101 ( char * V_225 , unsigned int V_19 )
{
if ( V_19 >= 26 )
V_225 = F_101 ( V_225 , V_19 / 26 - 1 ) ;
* V_225 = 'a' + V_19 % 26 ;
return V_225 + 1 ;
}
static int F_102 ( V_95 V_226 ,
struct V_13 * V_14 ,
T_5 V_227 , T_5 V_182 ,
unsigned int V_183 )
{
struct V_79 * V_80 ;
int V_49 = 1 ;
int V_228 ;
unsigned int V_100 ;
int V_45 ;
int V_229 ;
char * V_225 ;
F_2 ( V_14 -> V_80 != NULL ) ;
F_2 ( V_14 -> V_167 != NULL ) ;
if ( ( V_14 -> V_197 >> V_230 ) > 1 ) {
F_100 ( V_223 L_20 , V_14 -> V_197 ) ;
return - V_224 ;
}
if ( ! F_103 ( V_14 -> V_197 ) ) {
V_228 = F_97 ( V_14 -> V_197 , & V_45 , & V_100 ) ;
if ( V_228 )
return V_228 ;
V_229 = V_201 ;
} else {
V_45 = F_104 ( V_14 -> V_197 ) ;
V_229 = V_231 ;
V_100 = V_45 / V_229 ;
if ( F_105 () && V_100 < V_200 + 4 )
F_100 ( V_223 L_21
L_22
L_23 , V_14 -> V_197 ) ;
}
if ( V_45 >> V_232 ) {
F_106 ( L_24 ,
V_14 -> V_197 , V_45 ) ;
return - V_224 ;
}
if ( ( V_45 % V_229 ) == 0 )
V_49 = V_229 ;
V_228 = F_24 ( V_45 , V_49 ) ;
if ( V_228 )
goto V_233;
V_228 = - V_224 ;
V_80 = F_107 ( V_49 ) ;
if ( V_80 == NULL )
goto V_234;
strcpy ( V_80 -> V_196 , V_235 ) ;
V_225 = F_101 ( V_80 -> V_196 + sizeof( V_235 ) - 1 , V_100 ) ;
F_2 ( V_225 >= V_80 -> V_196 + V_236 ) ;
if ( V_49 > 1 )
* V_225 = 0 ;
else
snprintf ( V_225 , V_80 -> V_196 + V_236 - V_225 ,
L_25 , V_45 & ( V_229 - 1 ) ) ;
V_80 -> V_198 = V_222 ;
V_80 -> V_237 = V_45 ;
V_80 -> V_238 = & V_239 ;
V_80 -> V_72 = V_14 ;
F_108 ( V_80 , V_226 ) ;
if ( F_87 ( V_80 , V_182 , V_183 ) ) {
F_109 ( V_80 ) ;
goto V_234;
}
F_94 ( V_14 ) ;
if ( V_227 & V_240 )
F_110 ( V_80 , 1 ) ;
if ( V_227 & V_241 )
V_80 -> V_81 |= V_242 ;
if ( V_227 & V_243 )
V_80 -> V_81 |= V_82 ;
return 0 ;
V_234:
F_31 ( V_45 , V_49 ) ;
V_233:
return V_228 ;
}
static void F_111 ( struct V_13 * V_14 )
{
unsigned int V_45 , V_49 , V_20 ;
if ( V_14 -> V_167 == NULL )
return;
F_112 ( V_14 -> V_167 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
F_113 ( & V_2 -> V_141 ) ;
F_114 ( & V_2 -> V_58 ) ;
}
F_109 ( V_14 -> V_80 ) ;
V_45 = V_14 -> V_80 -> V_237 ;
V_49 = V_14 -> V_80 -> V_54 ;
F_31 ( V_45 , V_49 ) ;
F_115 ( V_14 -> V_167 ) ;
F_91 ( & V_14 -> V_185 ) ;
V_14 -> V_167 = NULL ;
F_116 ( V_14 -> V_80 ) ;
V_14 -> V_80 = NULL ;
}
static inline void F_117 ( struct V_1 * V_2 )
{
if ( ! F_73 ( & V_2 -> V_85 ) )
F_118 ( V_2 -> V_4 -> V_167 , true ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
unsigned long V_81 ;
F_72 ( & V_2 -> V_168 , V_81 ) ;
F_117 ( V_2 ) ;
F_74 ( & V_2 -> V_168 , V_81 ) ;
}
static void F_120 ( struct V_244 * V_58 )
{
struct V_1 * V_2 = F_121 ( V_58 , struct V_1 , V_58 ) ;
if ( V_2 -> V_4 -> V_153 == V_154 )
F_119 ( V_2 ) ;
}
static void F_122 ( struct V_1 * V_2 )
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
F_123 ( V_245 -> V_24 ,
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
V_247 = V_2 -> V_5 [ V_20 ] . V_6 . V_91 == V_113 ?
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_117 . V_130 :
V_2 -> V_5 [ V_20 ] . V_6 . V_7 . V_8 . V_130 ;
for ( V_246 = 0 ; V_246 < V_247 ; V_246 ++ ) {
V_245 = V_2 -> V_5 [ V_20 ] . V_119 [ V_246 ] ;
F_123 ( V_245 -> V_24 , 0 , 0UL ) ;
if ( V_14 -> V_23 )
F_12 ( V_245 -> V_15 ) ;
F_8 ( V_245 ) ;
}
if ( V_2 -> V_5 [ V_20 ] . V_6 . V_91 != V_113 )
goto V_248;
for ( V_246 = 0 ; V_246 < F_54 ( V_247 ) ; V_246 ++ ) {
V_245 = V_2 -> V_5 [ V_20 ] . V_116 [ V_246 ] ;
F_123 ( V_245 -> V_24 , 0 , 0UL ) ;
F_12 ( V_245 -> V_15 ) ;
F_8 ( V_245 ) ;
}
V_248:
F_8 ( V_2 -> V_5 [ V_20 ] . V_119 ) ;
V_2 -> V_5 [ V_20 ] . V_119 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_116 ) ;
V_2 -> V_5 [ V_20 ] . V_116 = NULL ;
F_8 ( V_2 -> V_5 [ V_20 ] . V_135 ) ;
V_2 -> V_5 [ V_20 ] . V_135 = NULL ;
}
F_113 ( & V_2 -> V_141 ) ;
F_114 ( & V_2 -> V_58 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ ) {
if ( V_2 -> V_250 [ V_20 ] != V_25 ) {
F_123 ( V_2 -> V_250 [ V_20 ] , 0 , 0 ) ;
V_2 -> V_250 [ V_20 ] = V_25 ;
}
}
F_124 ( ( unsigned long ) V_2 -> V_85 . V_251 , F_125 ( V_14 -> V_249 * V_131 ) ) ;
V_2 -> V_85 . V_251 = NULL ;
if ( V_2 -> V_157 )
F_126 ( V_2 -> V_157 , V_2 ) ;
V_2 -> V_252 = V_2 -> V_157 = 0 ;
}
static void F_127 ( struct V_13 * V_14 , int V_253 )
{
unsigned int V_20 ;
V_14 -> V_153 = V_253 ?
V_254 : V_255 ;
if ( V_14 -> V_167 )
F_112 ( V_14 -> V_167 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ )
F_122 ( & V_14 -> V_2 [ V_20 ] ) ;
F_8 ( V_14 -> V_2 ) ;
V_14 -> V_2 = NULL ;
V_14 -> V_166 = 0 ;
}
static void F_128 ( unsigned long V_33 , unsigned int V_100 ,
unsigned int V_101 , void * V_102 )
{
struct V_256 * V_14 = V_102 ;
char * V_121 ;
const struct V_109 * V_257 = V_14 -> V_257 ;
V_121 = F_50 ( V_257 -> V_119 [ V_14 -> V_108 ] -> V_15 ) ;
memcpy ( V_14 -> V_122 + V_14 -> V_258 ,
V_121 + V_100 , V_101 ) ;
V_14 -> V_258 += V_101 ;
V_14 -> V_108 ++ ;
F_49 ( V_121 ) ;
}
static enum V_259 F_129 ( int V_260 )
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
static int F_130 ( enum V_259 V_267 ,
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
static bool F_131 ( unsigned long * V_9 ,
struct V_1 * V_2 ,
struct V_269 * V_270 )
{
int V_20 = 0 ;
struct V_134 * V_135 ;
int V_136 , V_138 ;
struct V_13 * V_14 = V_2 -> V_4 ;
struct V_109 * V_257 = & V_2 -> V_5 [ * V_9 ] ;
struct V_256 V_102 = {
. V_108 = 0 ,
} ;
V_138 = V_257 -> V_6 . V_91 == V_113 ?
V_257 -> V_6 . V_7 . V_117 . V_130 : V_257 -> V_6 . V_7 . V_8 . V_130 ;
if ( F_48 ( V_257 -> V_89 != V_90 ) ) {
struct V_109 * V_268 = & V_2 -> V_5 [ V_257 -> V_89 ] ;
V_257 -> V_87 = F_129 ( V_270 -> V_87 ) ;
if ( V_268 -> V_87 == V_88 )
return 0 ;
V_270 -> V_87 = F_130 ( V_257 -> V_87 ,
V_268 -> V_87 ) ;
V_138 += V_268 -> V_6 . V_7 . V_8 . V_130 ;
if ( V_268 -> V_136 != 0 ) {
* V_9 = V_257 -> V_89 ;
V_257 = V_268 ;
}
if ( F_4 ( V_2 , V_257 -> V_89 ) )
F_132 ( 1 , L_26 ,
V_14 -> V_80 -> V_196 , V_257 -> V_89 ) ;
}
V_102 . V_257 = V_257 ;
V_136 = V_257 -> V_136 ;
if ( V_270 -> V_91 == V_40 && V_14 -> V_23 ) {
F_58 (s->sg, sg, num_sg, i) {
F_2 ( V_135 -> V_100 + V_135 -> V_143 > V_152 ) ;
V_102 . V_258 = V_135 -> V_100 ;
V_102 . V_122 = F_50 ( F_61 ( V_135 ) ) ;
F_62 ( F_61 ( V_135 ) ,
V_135 -> V_100 ,
V_135 -> V_143 ,
F_128 ,
& V_102 ) ;
F_49 ( V_102 . V_122 ) ;
}
}
for ( V_20 = 0 ; V_20 < V_138 ; V_20 ++ ) {
if ( F_133 ( V_257 -> V_119 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_134 ( L_27 ,
V_257 -> V_119 [ V_20 ] -> V_24 ) ;
F_9 ( & V_257 -> V_119 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
F_123 ( V_257 -> V_119 [ V_20 ] -> V_24 , 0 , 0UL ) ;
V_257 -> V_119 [ V_20 ] -> V_24 = V_25 ;
F_135 ( & V_257 -> V_119 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
if ( V_257 -> V_6 . V_91 == V_113 ) {
for ( V_20 = 0 ; V_20 < F_54 ( V_138 ) ; V_20 ++ ) {
if ( F_133 ( V_257 -> V_116 [ V_20 ] -> V_24 ) ) {
if ( ! V_14 -> V_23 )
F_134 ( L_27 ,
V_257 -> V_116 [ V_20 ] -> V_24 ) ;
F_9 ( & V_257 -> V_116 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
V_2 -> V_29 ++ ;
} else {
struct V_15 * V_35 ;
F_123 ( V_257 -> V_116 [ V_20 ] -> V_24 , 0 , 0UL ) ;
if ( ! V_14 -> V_23 ) {
V_35 = V_257 -> V_116 [ V_20 ] -> V_15 ;
F_9 ( & V_35 -> V_37 , & V_2 -> V_36 ) ;
}
V_257 -> V_116 [ V_20 ] -> V_24 = V_25 ;
F_135 ( & V_257 -> V_116 [ V_20 ] -> V_26 , & V_2 -> V_27 ) ;
}
}
}
return 1 ;
}
static T_6 F_136 ( int V_157 , void * V_271 )
{
struct V_11 * V_6 ;
struct V_269 * V_270 ;
T_7 V_20 , V_272 ;
unsigned long V_81 ;
struct V_1 * V_2 = (struct V_1 * ) V_271 ;
struct V_13 * V_14 = V_2 -> V_4 ;
int error ;
if ( F_48 ( V_14 -> V_153 != V_154 ) )
return V_273 ;
F_72 ( & V_2 -> V_168 , V_81 ) ;
V_274:
V_272 = V_2 -> V_85 . V_251 -> V_275 ;
F_137 () ;
for ( V_20 = V_2 -> V_85 . V_276 ; V_20 != V_272 ; V_20 ++ ) {
unsigned long V_9 ;
V_270 = F_138 ( & V_2 -> V_85 , V_20 ) ;
V_9 = V_270 -> V_9 ;
if ( V_9 >= F_3 ( V_14 ) ) {
F_132 ( 1 , L_28 ,
V_14 -> V_80 -> V_196 , F_22 ( V_270 -> V_91 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_270 -> V_91 != V_44 ) {
if ( ! F_131 ( & V_9 , V_2 , V_270 ) )
continue;
}
if ( F_4 ( V_2 , V_9 ) ) {
F_132 ( 1 , L_29 ,
V_14 -> V_80 -> V_196 , F_22 ( V_270 -> V_91 ) , V_9 ) ;
continue;
}
error = ( V_270 -> V_87 == V_261 ) ? 0 : - V_277 ;
switch ( V_270 -> V_91 ) {
case V_44 :
if ( F_48 ( V_270 -> V_87 == V_263 ) ) {
struct V_174 * V_167 = V_14 -> V_167 ;
F_100 ( V_223 L_30 ,
V_14 -> V_80 -> V_196 , F_22 ( V_270 -> V_91 ) ) ;
error = - V_278 ;
V_14 -> V_176 = 0 ;
V_14 -> V_97 = 0 ;
F_139 ( V_177 , V_167 ) ;
F_139 ( V_181 , V_167 ) ;
}
F_140 ( V_6 , error ) ;
break;
case V_43 :
case V_42 :
if ( F_48 ( V_270 -> V_87 == V_263 ) ) {
F_100 ( V_223 L_30 ,
V_14 -> V_80 -> V_196 , F_22 ( V_270 -> V_91 ) ) ;
error = - V_278 ;
}
if ( F_48 ( V_270 -> V_87 == V_265 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_130 == 0 ) ) {
F_100 ( V_223 L_31 ,
V_14 -> V_80 -> V_196 , F_22 ( V_270 -> V_91 ) ) ;
error = - V_278 ;
}
if ( F_48 ( error ) ) {
if ( error == - V_278 )
error = 0 ;
V_14 -> V_151 = 0 ;
V_14 -> V_150 = 0 ;
F_94 ( V_14 ) ;
}
case V_40 :
case V_41 :
if ( F_48 ( V_270 -> V_87 != V_261 ) )
F_39 ( & V_14 -> V_30 -> V_73 , L_32
L_33 , V_270 -> V_87 ) ;
F_140 ( V_6 , error ) ;
break;
default:
F_141 () ;
}
}
V_2 -> V_85 . V_276 = V_20 ;
if ( V_20 != V_2 -> V_85 . V_86 ) {
int V_279 ;
F_142 ( & V_2 -> V_85 , V_279 ) ;
if ( V_279 )
goto V_274;
} else
V_2 -> V_85 . V_251 -> V_280 = V_20 + 1 ;
F_117 ( V_2 ) ;
F_74 ( & V_2 -> V_168 , V_81 ) ;
return V_273 ;
}
static int F_143 ( struct V_281 * V_73 ,
struct V_1 * V_2 )
{
struct V_282 * V_251 ;
int V_228 , V_20 ;
struct V_13 * V_14 = V_2 -> V_4 ;
unsigned long V_283 = V_14 -> V_249 * V_131 ;
T_1 V_24 [ V_284 ] ;
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ )
V_2 -> V_250 [ V_20 ] = V_25 ;
V_251 = (struct V_282 * ) F_144 ( V_21 | V_285 ,
F_125 ( V_283 ) ) ;
if ( ! V_251 ) {
F_145 ( V_73 , - V_28 , L_34 ) ;
return - V_28 ;
}
F_146 ( V_251 ) ;
F_147 ( & V_2 -> V_85 , V_251 , V_283 ) ;
V_228 = F_148 ( V_73 , V_2 -> V_85 . V_251 , V_14 -> V_249 , V_24 ) ;
if ( V_228 < 0 ) {
F_124 ( ( unsigned long ) V_251 , F_125 ( V_283 ) ) ;
V_2 -> V_85 . V_251 = NULL ;
goto V_286;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ )
V_2 -> V_250 [ V_20 ] = V_24 [ V_20 ] ;
V_228 = F_149 ( V_73 , & V_2 -> V_252 ) ;
if ( V_228 )
goto V_286;
V_228 = F_150 ( V_2 -> V_252 , F_136 , 0 ,
L_35 , V_2 ) ;
if ( V_228 <= 0 ) {
F_145 ( V_73 , V_228 ,
L_36 ) ;
goto V_286;
}
V_2 -> V_157 = V_228 ;
return 0 ;
V_286:
F_127 ( V_14 , 0 ) ;
return V_228 ;
}
static int F_151 ( struct V_287 V_288 ,
struct V_1 * V_2 , const char * V_289 )
{
int V_228 ;
unsigned int V_20 ;
const char * V_290 = NULL ;
struct V_13 * V_14 = V_2 -> V_4 ;
if ( V_14 -> V_249 == 1 ) {
V_228 = F_152 ( V_288 , V_289 , L_37 , L_38 , V_2 -> V_250 [ 0 ] ) ;
if ( V_228 ) {
V_290 = L_39 ;
goto V_291;
}
} else {
for ( V_20 = 0 ; V_20 < V_14 -> V_249 ; V_20 ++ ) {
char V_292 [ V_293 ] ;
snprintf ( V_292 , V_293 , L_40 , V_20 ) ;
V_228 = F_152 ( V_288 , V_289 , V_292 ,
L_38 , V_2 -> V_250 [ V_20 ] ) ;
if ( V_228 ) {
V_290 = L_39 ;
goto V_291;
}
}
}
V_228 = F_152 ( V_288 , V_289 , L_41 , L_38 , V_2 -> V_252 ) ;
if ( V_228 ) {
V_290 = L_42 ;
goto V_291;
}
return 0 ;
V_291:
F_153 ( V_288 , 1 ) ;
if ( V_290 )
F_145 ( V_14 -> V_30 , V_228 , L_43 , V_290 ) ;
return V_228 ;
}
static int F_154 ( struct V_281 * V_73 ,
struct V_13 * V_14 )
{
const char * V_290 = NULL ;
struct V_287 V_288 ;
int V_228 ;
unsigned int V_20 , V_294 ;
unsigned int V_295 ;
V_294 = F_155 ( V_14 -> V_30 -> V_296 ,
L_44 , 0 ) ;
V_295 = F_156 ( V_297 , V_294 ) ;
V_14 -> V_249 = 1 << V_295 ;
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
V_228 = F_143 ( V_73 , V_2 ) ;
if ( V_228 )
goto V_298;
}
V_274:
V_228 = F_157 ( & V_288 ) ;
if ( V_228 ) {
F_145 ( V_73 , V_228 , L_45 ) ;
goto V_298;
}
if ( V_14 -> V_249 > 1 ) {
V_228 = F_152 ( V_288 , V_73 -> V_299 , L_46 , L_38 ,
V_295 ) ;
if ( V_228 ) {
V_290 = L_47 ;
goto V_291;
}
}
if ( V_14 -> V_166 == 1 ) {
V_228 = F_151 ( V_288 , & V_14 -> V_2 [ 0 ] , V_73 -> V_299 ) ;
if ( V_228 )
goto V_298;
} else {
char * V_300 ;
T_8 V_301 ;
V_228 = F_152 ( V_288 , V_73 -> V_299 , L_48 , L_38 ,
V_14 -> V_166 ) ;
if ( V_228 ) {
V_290 = L_49 ;
goto V_291;
}
V_301 = strlen ( V_73 -> V_299 ) + V_302 ;
V_300 = F_158 ( V_301 , V_52 ) ;
if ( ! V_300 ) {
V_228 = - V_28 ;
V_290 = L_50 ;
goto V_291;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ ) {
memset ( V_300 , 0 , V_301 ) ;
snprintf ( V_300 , V_301 , L_51 , V_73 -> V_299 , V_20 ) ;
V_228 = F_151 ( V_288 , & V_14 -> V_2 [ V_20 ] , V_300 ) ;
if ( V_228 ) {
F_8 ( V_300 ) ;
goto V_298;
}
}
F_8 ( V_300 ) ;
}
V_228 = F_152 ( V_288 , V_73 -> V_299 , L_52 , L_43 ,
V_303 ) ;
if ( V_228 ) {
V_290 = L_53 ;
goto V_291;
}
V_228 = F_152 ( V_288 , V_73 -> V_299 ,
L_54 , L_38 , 1 ) ;
if ( V_228 )
F_159 ( & V_73 -> V_73 ,
L_55 ) ;
V_228 = F_153 ( V_288 , 0 ) ;
if ( V_228 ) {
if ( V_228 == - V_304 )
goto V_274;
F_145 ( V_73 , V_228 , L_56 ) ;
goto V_298;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ ) {
unsigned int V_246 ;
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
for ( V_246 = 0 ; V_246 < F_3 ( V_14 ) ; V_246 ++ )
V_2 -> V_5 [ V_246 ] . V_6 . V_7 . V_8 . V_9 = V_246 + 1 ;
V_2 -> V_5 [ F_3 ( V_14 ) - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
}
F_160 ( V_73 , V_305 ) ;
return 0 ;
V_291:
F_153 ( V_288 , 1 ) ;
if ( V_290 )
F_145 ( V_73 , V_228 , L_43 , V_290 ) ;
V_298:
F_127 ( V_14 , 0 ) ;
F_8 ( V_14 ) ;
F_161 ( & V_73 -> V_73 , NULL ) ;
return V_228 ;
}
static int F_162 ( struct V_13 * V_14 )
{
unsigned int V_306 ;
unsigned int V_20 ;
F_2 ( V_14 -> V_166 ) ;
V_306 = F_155 ( V_14 -> V_30 -> V_296 ,
L_57 , 1 ) ;
V_14 -> V_166 = F_156 ( V_306 , V_307 ) ;
if ( ! V_14 -> V_166 )
V_14 -> V_166 = 1 ;
V_14 -> V_2 = F_6 ( sizeof( struct V_1 ) * V_14 -> V_166 , V_52 ) ;
if ( ! V_14 -> V_2 ) {
F_145 ( V_14 -> V_30 , - V_28 , L_58 ) ;
return - V_28 ;
}
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_20 ] ;
F_163 ( & V_2 -> V_36 ) ;
F_163 ( & V_2 -> V_27 ) ;
V_2 -> V_4 = V_14 ;
F_164 ( & V_2 -> V_58 , F_120 ) ;
F_165 ( & V_2 -> V_168 ) ;
}
return 0 ;
}
static int F_166 ( struct V_281 * V_73 ,
const struct V_308 * V_9 )
{
int V_228 , V_197 ;
struct V_13 * V_14 ;
V_228 = F_167 ( V_309 , V_73 -> V_299 ,
L_59 , L_60 , & V_197 ) ;
if ( V_228 != 1 ) {
V_228 = F_167 ( V_309 , V_73 -> V_299 , L_61 ,
L_60 , & V_197 ) ;
if ( V_228 != 1 ) {
F_145 ( V_73 , V_228 , L_62 ) ;
return V_228 ;
}
}
if ( F_105 () ) {
char * type ;
int V_101 ;
if ( F_168 () ) {
int V_198 ;
if ( ! F_103 ( V_197 ) )
V_198 = F_98 ( V_197 ) ;
else
V_198 = V_222 ;
if ( V_198 != V_222 ) {
F_100 ( V_310
L_63 ,
V_311 , V_197 ) ;
return - V_224 ;
}
}
type = F_169 ( V_309 , V_73 -> V_299 , L_64 , & V_101 ) ;
if ( F_90 ( type ) )
return - V_224 ;
if ( strncmp ( type , L_65 , 5 ) == 0 ) {
F_8 ( type ) ;
return - V_224 ;
}
F_8 ( type ) ;
}
V_14 = F_6 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 ) {
F_145 ( V_73 , - V_28 , L_66 ) ;
return - V_28 ;
}
V_14 -> V_30 = V_73 ;
V_228 = F_162 ( V_14 ) ;
if ( V_228 ) {
F_8 ( V_14 ) ;
return V_228 ;
}
F_170 ( & V_14 -> V_312 ) ;
V_14 -> V_197 = V_197 ;
V_14 -> V_153 = V_255 ;
V_14 -> V_132 = F_171 ( strrchr ( V_73 -> V_299 , '/' ) + 1 , NULL , 0 ) ;
F_161 ( & V_73 -> V_73 , V_14 ) ;
return 0 ;
}
static void F_172 ( struct V_313 * V_313 )
{
struct V_314 * V_314 = V_313 -> V_315 ;
if ( F_173 ( & V_314 -> V_316 ) ) {
V_314 -> V_313 -> V_317 = 0 ;
V_314 -> V_313 -> V_318 = V_313 -> V_318 ;
F_174 ( V_314 -> V_313 ) ;
F_8 ( V_314 ) ;
}
F_175 ( V_313 ) ;
}
static int F_176 ( struct V_13 * V_14 )
{
unsigned int V_20 , V_319 ;
struct V_11 * V_6 , * V_19 ;
int V_48 ;
struct V_313 * V_313 , * V_320 ;
unsigned int V_247 , V_100 ;
int V_316 , V_321 ;
struct V_314 * V_314 ;
F_177 ( V_14 ) ;
F_76 ( V_14 ) ;
V_247 = V_14 -> V_144 ? : V_111 ;
F_84 ( V_14 -> V_167 , V_247 / V_140 ) ;
for ( V_319 = 0 ; V_319 < V_14 -> V_166 ; V_319 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_319 ] ;
V_48 = F_178 ( V_2 ) ;
if ( V_48 )
return V_48 ;
}
F_160 ( V_14 -> V_30 , V_322 ) ;
V_14 -> V_153 = V_154 ;
for ( V_319 = 0 ; V_319 < V_14 -> V_166 ; V_319 ++ ) {
struct V_1 * V_2 ;
V_2 = & V_14 -> V_2 [ V_319 ] ;
F_119 ( V_2 ) ;
}
F_10 (req, n, &info->requests, queuelist) {
F_179 ( & V_6 -> V_323 ) ;
F_2 ( V_6 -> V_139 > V_247 ) ;
F_180 ( V_6 , false ) ;
}
F_118 ( V_14 -> V_167 , true ) ;
F_181 ( V_14 -> V_167 ) ;
while ( ( V_313 = F_182 ( & V_14 -> V_324 ) ) != NULL ) {
if ( F_183 ( V_313 ) > V_247 ) {
V_316 = ( F_183 ( V_313 ) + V_247 - 1 ) / V_247 ;
V_314 = F_6 ( sizeof( * V_314 ) , V_21 ) ;
F_2 ( V_314 == NULL ) ;
F_184 ( & V_314 -> V_316 , V_316 ) ;
V_314 -> V_313 = V_313 ;
for ( V_20 = 0 ; V_20 < V_316 ; V_20 ++ ) {
V_100 = ( V_20 * V_247 * V_131 ) >> 9 ;
V_321 = F_156 ( ( unsigned int ) ( V_247 * V_131 ) >> 9 ,
( unsigned int ) F_185 ( V_313 ) - V_100 ) ;
V_320 = F_186 ( V_313 , V_21 ) ;
F_2 ( V_320 == NULL ) ;
F_187 ( V_320 , V_100 , V_321 ) ;
V_320 -> V_315 = V_314 ;
V_320 -> V_325 = F_172 ;
F_188 ( V_320 ) ;
}
continue;
}
F_188 ( V_313 ) ;
}
return 0 ;
}
static int F_189 ( struct V_281 * V_73 )
{
struct V_13 * V_14 = F_190 ( & V_73 -> V_73 ) ;
int V_228 = 0 ;
unsigned int V_20 , V_246 ;
F_39 ( & V_73 -> V_73 , L_67 , V_73 -> V_299 ) ;
F_191 ( & V_14 -> V_324 ) ;
F_163 ( & V_14 -> V_326 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_20 ] ;
struct V_324 V_327 ;
struct V_109 * V_5 = V_2 -> V_5 ;
for ( V_246 = 0 ; V_246 < F_3 ( V_14 ) ; V_246 ++ ) {
if ( ! V_5 [ V_246 ] . V_11 )
continue;
if ( F_46 ( V_5 [ V_20 ] . V_11 ) == V_146 ||
F_46 ( V_5 [ V_20 ] . V_11 ) == V_155 ||
F_46 ( V_5 [ V_20 ] . V_11 ) == V_96 ||
V_5 [ V_246 ] . V_11 -> V_147 & V_148 ) {
F_9 ( & V_5 [ V_246 ] . V_11 -> V_323 , & V_14 -> V_326 ) ;
continue;
}
V_327 . V_328 = V_5 [ V_246 ] . V_11 -> V_313 ;
V_327 . V_329 = V_5 [ V_246 ] . V_11 -> V_330 ;
F_192 ( & V_14 -> V_324 , & V_327 ) ;
V_5 [ V_246 ] . V_11 -> V_313 = NULL ;
F_193 ( V_5 [ V_246 ] . V_11 , 0 ) ;
}
}
F_127 ( V_14 , V_14 -> V_153 == V_154 ) ;
V_228 = F_162 ( V_14 ) ;
if ( V_228 )
return V_228 ;
V_228 = F_154 ( V_73 , V_14 ) ;
if ( ! V_228 )
F_194 ( & V_14 -> V_185 , V_14 -> V_166 ) ;
return V_228 ;
}
static void F_195 ( struct V_13 * V_14 )
{
struct V_281 * V_30 = V_14 -> V_30 ;
struct V_59 * V_68 = NULL ;
F_196 ( & V_14 -> V_312 ) ;
if ( V_30 -> V_331 == V_332 ) {
F_197 ( & V_14 -> V_312 ) ;
return;
}
if ( V_14 -> V_80 )
V_68 = F_198 ( V_14 -> V_80 , 0 ) ;
F_197 ( & V_14 -> V_312 ) ;
if ( ! V_68 ) {
F_199 ( V_30 ) ;
return;
}
F_196 ( & V_68 -> V_333 ) ;
if ( V_68 -> V_334 ) {
F_200 ( V_30 , - V_56 ,
L_68 ) ;
F_160 ( V_30 , V_332 ) ;
} else {
F_111 ( V_14 ) ;
F_199 ( V_30 ) ;
}
F_197 ( & V_68 -> V_333 ) ;
F_201 ( V_68 ) ;
}
static void F_202 ( struct V_13 * V_14 )
{
int V_228 ;
unsigned int V_179 ;
unsigned int V_180 ;
V_14 -> V_176 = 1 ;
V_228 = F_203 ( V_309 , V_14 -> V_30 -> V_296 ,
L_69 , L_38 , & V_179 ,
L_70 , L_38 , & V_180 ,
NULL ) ;
if ( ! V_228 ) {
V_14 -> V_179 = V_179 ;
V_14 -> V_180 = V_180 ;
}
V_14 -> V_97 =
! ! F_155 ( V_14 -> V_30 -> V_296 , L_71 ,
0 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
unsigned int V_335 , V_27 ;
int V_228 , V_20 ;
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
V_335 = F_204 ( V_27 , V_140 ) ;
V_228 = F_5 ( V_2 ,
( V_27 + F_54 ( V_27 ) ) * F_3 ( V_14 ) ) ;
if ( V_228 )
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
V_2 -> V_5 [ V_20 ] . V_135 = F_6 ( sizeof( V_2 -> V_5 [ V_20 ] . V_135 [ 0 ] ) * V_335 , V_21 ) ;
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
F_205 ( V_2 -> V_5 [ V_20 ] . V_135 , V_335 ) ;
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
static void F_177 ( struct V_13 * V_14 )
{
unsigned int V_336 ;
V_14 -> V_150 = 0 ;
V_14 -> V_151 = 0 ;
if ( F_155 ( V_14 -> V_30 -> V_296 , L_72 , 0 ) ) {
V_14 -> V_150 = 1 ;
V_14 -> V_151 = 1 ;
}
if ( F_155 ( V_14 -> V_30 -> V_296 , L_73 ,
0 ) ) {
V_14 -> V_150 = 1 ;
V_14 -> V_151 = 0 ;
}
if ( F_155 ( V_14 -> V_30 -> V_296 , L_74 , 0 ) )
F_202 ( V_14 ) ;
V_14 -> V_23 =
! ! F_155 ( V_14 -> V_30 -> V_296 ,
L_54 , 0 ) ;
V_336 = F_155 ( V_14 -> V_30 -> V_296 ,
L_75 , 0 ) ;
if ( V_336 > V_337 )
V_336 = V_337 ;
if ( V_336 <= V_111 )
V_336 = 0 ;
V_14 -> V_144 = V_336 ;
}
static void F_206 ( struct V_13 * V_14 )
{
unsigned long long V_67 ;
unsigned long V_182 ;
unsigned int V_183 ;
unsigned int V_338 ;
int V_228 , V_20 ;
switch ( V_14 -> V_153 ) {
case V_154 :
V_228 = F_167 ( V_309 , V_14 -> V_30 -> V_296 ,
L_76 , L_77 , & V_67 ) ;
if ( F_207 ( V_228 ) )
return;
F_100 ( V_310 L_78 ,
V_67 ) ;
F_108 ( V_14 -> V_80 , V_67 ) ;
F_208 ( V_14 -> V_80 ) ;
return;
case V_254 :
F_176 ( V_14 ) ;
return;
default:
break;
}
F_39 ( & V_14 -> V_30 -> V_73 , L_79 ,
V_311 , V_14 -> V_30 -> V_296 ) ;
V_228 = F_203 ( V_309 , V_14 -> V_30 -> V_296 ,
L_76 , L_80 , & V_67 ,
L_81 , L_38 , & V_338 ,
L_82 , L_83 , & V_182 ,
NULL ) ;
if ( V_228 ) {
F_145 ( V_14 -> V_30 , V_228 ,
L_84 ,
V_14 -> V_30 -> V_296 ) ;
return;
}
V_183 = F_155 ( V_14 -> V_30 -> V_296 ,
L_85 ,
V_182 ) ;
F_177 ( V_14 ) ;
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ ) {
V_228 = F_178 ( & V_14 -> V_2 [ V_20 ] ) ;
if ( V_228 ) {
F_145 ( V_14 -> V_30 , V_228 , L_86 ,
V_14 -> V_30 -> V_296 ) ;
F_127 ( V_14 , 0 ) ;
break;
}
}
V_228 = F_102 ( V_67 , V_14 , V_338 , V_182 ,
V_183 ) ;
if ( V_228 ) {
F_145 ( V_14 -> V_30 , V_228 , L_87 ,
V_14 -> V_30 -> V_296 ) ;
goto V_286;
}
F_160 ( V_14 -> V_30 , V_322 ) ;
V_14 -> V_153 = V_154 ;
for ( V_20 = 0 ; V_20 < V_14 -> V_166 ; V_20 ++ )
F_119 ( & V_14 -> V_2 [ V_20 ] ) ;
F_209 ( & V_14 -> V_30 -> V_73 , V_14 -> V_80 ) ;
V_14 -> V_339 = 1 ;
return;
V_286:
F_127 ( V_14 , 0 ) ;
return;
}
static void F_210 ( struct V_281 * V_73 ,
enum V_340 V_341 )
{
struct V_13 * V_14 = F_190 ( & V_73 -> V_73 ) ;
F_39 ( & V_73 -> V_73 , L_88 , V_341 ) ;
switch ( V_341 ) {
case V_342 :
if ( V_73 -> V_331 != V_343 )
break;
if ( F_154 ( V_73 , V_14 ) )
break;
case V_343 :
case V_305 :
case V_344 :
case V_345 :
case V_346 :
break;
case V_322 :
if ( ( V_73 -> V_331 != V_305 ) &&
( V_73 -> V_331 != V_322 ) ) {
if ( F_154 ( V_73 , V_14 ) )
break;
}
F_206 ( V_14 ) ;
break;
case V_347 :
if ( V_73 -> V_331 == V_347 )
break;
case V_332 :
if ( V_14 )
F_195 ( V_14 ) ;
break;
}
}
static int F_211 ( struct V_281 * V_30 )
{
struct V_13 * V_14 = F_190 ( & V_30 -> V_73 ) ;
struct V_59 * V_68 = NULL ;
struct V_79 * V_348 ;
F_39 ( & V_30 -> V_73 , L_89 , V_30 -> V_299 ) ;
F_127 ( V_14 , 0 ) ;
F_196 ( & V_14 -> V_312 ) ;
V_348 = V_14 -> V_80 ;
if ( V_348 )
V_68 = F_198 ( V_348 , 0 ) ;
V_14 -> V_30 = NULL ;
F_197 ( & V_14 -> V_312 ) ;
if ( ! V_68 ) {
F_8 ( V_14 ) ;
return 0 ;
}
F_196 ( & V_68 -> V_333 ) ;
V_14 = V_348 -> V_72 ;
F_159 ( F_212 ( V_348 ) ,
L_90 ,
V_30 -> V_299 , V_68 -> V_334 ) ;
if ( V_14 && ! V_68 -> V_334 ) {
F_111 ( V_14 ) ;
V_348 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
F_197 ( & V_68 -> V_333 ) ;
F_201 ( V_68 ) ;
return 0 ;
}
static int F_213 ( struct V_281 * V_73 )
{
struct V_13 * V_14 = F_190 ( & V_73 -> V_73 ) ;
return V_14 -> V_339 && V_14 -> V_30 ;
}
static int F_214 ( struct V_59 * V_68 , T_3 V_69 )
{
struct V_79 * V_348 = V_68 -> V_64 ;
struct V_13 * V_14 ;
int V_228 = 0 ;
F_196 ( & V_349 ) ;
V_14 = V_348 -> V_72 ;
if ( ! V_14 ) {
V_228 = - V_350 ;
goto V_233;
}
F_196 ( & V_14 -> V_312 ) ;
if ( ! V_14 -> V_80 )
V_228 = - V_350 ;
F_197 ( & V_14 -> V_312 ) ;
V_233:
F_197 ( & V_349 ) ;
return V_228 ;
}
static void F_215 ( struct V_79 * V_348 , T_3 V_69 )
{
struct V_13 * V_14 = V_348 -> V_72 ;
struct V_59 * V_68 ;
struct V_281 * V_30 ;
F_196 ( & V_349 ) ;
V_68 = F_198 ( V_348 , 0 ) ;
if ( ! V_68 ) {
F_132 ( 1 , L_91 , V_348 -> V_196 ) ;
goto V_351;
}
if ( V_68 -> V_334 )
goto V_233;
F_196 ( & V_14 -> V_312 ) ;
V_30 = V_14 -> V_30 ;
if ( V_30 && V_30 -> V_331 == V_332 ) {
V_4 ( F_212 ( V_68 -> V_64 ) , L_92 ) ;
F_111 ( V_14 ) ;
F_199 ( V_14 -> V_30 ) ;
}
F_197 ( & V_14 -> V_312 ) ;
if ( ! V_30 ) {
V_4 ( F_212 ( V_68 -> V_64 ) , L_92 ) ;
F_111 ( V_14 ) ;
V_348 -> V_72 = NULL ;
F_8 ( V_14 ) ;
}
V_233:
F_201 ( V_68 ) ;
V_351:
F_197 ( & V_349 ) ;
}
static int T_9 F_216 ( void )
{
int V_352 ;
int V_353 = F_217 () ;
if ( ! F_218 () )
return - V_224 ;
if ( V_337 < V_111 )
V_337 = V_111 ;
if ( V_297 > V_354 ) {
F_96 ( L_93 ,
V_297 , V_354 ) ;
V_297 = V_354 ;
}
if ( V_307 > V_353 ) {
F_96 ( L_94 ,
V_307 , V_353 ) ;
V_307 = V_353 ;
}
if ( ! F_219 () )
return - V_224 ;
if ( F_220 ( V_222 , V_235 ) ) {
F_100 ( V_223 L_95 ,
V_222 , V_235 ) ;
return - V_224 ;
}
V_352 = F_221 ( & V_355 ) ;
if ( V_352 ) {
F_222 ( V_222 , V_235 ) ;
return V_352 ;
}
return 0 ;
}
static void T_10 F_223 ( void )
{
F_224 ( & V_355 ) ;
F_222 ( V_222 , V_235 ) ;
F_8 ( V_54 ) ;
}
