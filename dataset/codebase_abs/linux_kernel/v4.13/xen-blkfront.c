static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 ) ;
}
static int F_2 ( struct V_4 * V_5 )
{
unsigned long free = V_5 -> V_6 ;
F_3 ( free >= F_4 ( V_5 -> V_7 ) ) ;
V_5 -> V_6 = V_5 -> V_8 [ free ] . V_9 . V_10 . V_11 . V_12 ;
V_5 -> V_8 [ free ] . V_9 . V_10 . V_11 . V_12 = 0x0fffffee ;
return free ;
}
static int F_5 ( struct V_4 * V_5 ,
unsigned long V_12 )
{
if ( V_5 -> V_8 [ V_12 ] . V_9 . V_10 . V_11 . V_12 != V_12 )
return - V_13 ;
if ( V_5 -> V_8 [ V_12 ] . V_2 == NULL )
return - V_13 ;
V_5 -> V_8 [ V_12 ] . V_9 . V_10 . V_11 . V_12 = V_5 -> V_6 ;
V_5 -> V_8 [ V_12 ] . V_2 = NULL ;
V_5 -> V_6 = V_12 ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 , int V_14 )
{
struct V_15 * V_16 = V_5 -> V_7 ;
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_21 ;
int V_22 = 0 ;
while ( V_22 < V_14 ) {
V_20 = F_7 ( sizeof( struct V_19 ) , V_23 ) ;
if ( ! V_20 )
goto V_24;
if ( V_16 -> V_25 ) {
V_18 = F_8 ( V_23 ) ;
if ( ! V_18 ) {
F_9 ( V_20 ) ;
goto V_24;
}
V_20 -> V_17 = V_18 ;
}
V_20 -> V_26 = V_27 ;
F_10 ( & V_20 -> V_28 , & V_5 -> V_29 ) ;
V_22 ++ ;
}
return 0 ;
V_24:
F_11 (gnt_list_entry, n,
&rinfo->grants, node) {
F_12 ( & V_20 -> V_28 ) ;
if ( V_16 -> V_25 )
F_13 ( V_20 -> V_17 ) ;
F_9 ( V_20 ) ;
V_22 -- ;
}
F_3 ( V_22 != 0 ) ;
return - V_30 ;
}
static struct V_19 * F_14 ( struct V_4 * V_5 )
{
struct V_19 * V_20 ;
F_3 ( F_15 ( & V_5 -> V_29 ) ) ;
V_20 = F_16 ( & V_5 -> V_29 , struct V_19 ,
V_28 ) ;
F_12 ( & V_20 -> V_28 ) ;
if ( V_20 -> V_26 != V_27 )
V_5 -> V_31 -- ;
return V_20 ;
}
static inline void F_17 ( const struct V_19 * V_20 ,
const struct V_15 * V_16 )
{
F_18 ( V_20 -> V_26 ,
V_16 -> V_32 -> V_33 ,
V_20 -> V_17 ,
0 ) ;
}
static struct V_19 * F_19 ( T_1 * V_34 ,
unsigned long V_35 ,
struct V_4 * V_5 )
{
struct V_19 * V_20 = F_14 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_7 ;
if ( V_20 -> V_26 != V_27 )
return V_20 ;
V_20 -> V_26 = F_20 ( V_34 ) ;
F_3 ( V_20 -> V_26 == - V_36 ) ;
if ( V_16 -> V_25 )
F_17 ( V_20 , V_16 ) ;
else {
F_21 ( V_20 -> V_26 ,
V_16 -> V_32 -> V_33 ,
V_35 , 0 ) ;
}
return V_20 ;
}
static struct V_19 * F_22 ( T_1 * V_34 ,
struct V_4 * V_5 )
{
struct V_19 * V_20 = F_14 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_7 ;
if ( V_20 -> V_26 != V_27 )
return V_20 ;
V_20 -> V_26 = F_20 ( V_34 ) ;
F_3 ( V_20 -> V_26 == - V_36 ) ;
if ( ! V_16 -> V_25 ) {
struct V_17 * V_37 ;
F_3 ( F_15 ( & V_5 -> V_38 ) ) ;
V_37 = F_16 ( & V_5 -> V_38 ,
struct V_17 , V_39 ) ;
F_12 ( & V_37 -> V_39 ) ;
V_20 -> V_17 = V_37 ;
}
F_17 ( V_20 , V_16 ) ;
return V_20 ;
}
static const char * F_23 ( int V_40 )
{
static const char * const V_41 [] = {
[ V_42 ] = L_1 ,
[ V_43 ] = L_2 ,
[ V_44 ] = L_3 ,
[ V_45 ] = L_4 ,
[ V_46 ] = L_5 } ;
if ( V_40 < 0 || V_40 >= F_24 ( V_41 ) )
return L_6 ;
if ( ! V_41 [ V_40 ] )
return L_7 ;
return V_41 [ V_40 ] ;
}
static int F_25 ( unsigned int V_47 , unsigned int V_48 )
{
unsigned int V_49 = V_47 + V_48 ;
int V_50 ;
if ( V_49 > V_51 ) {
unsigned long * V_52 , * V_53 ;
V_52 = F_26 ( F_27 ( V_49 ) , sizeof( * V_52 ) ,
V_54 ) ;
if ( V_52 == NULL )
return - V_30 ;
F_28 ( & V_55 ) ;
if ( V_49 > V_51 ) {
V_53 = V_56 ;
memcpy ( V_52 , V_56 ,
F_27 ( V_51 ) * sizeof( * V_52 ) ) ;
V_56 = V_52 ;
V_51 = F_27 ( V_49 ) * V_57 ;
} else
V_53 = V_52 ;
F_29 ( & V_55 ) ;
F_9 ( V_53 ) ;
}
F_28 ( & V_55 ) ;
if ( F_30 ( V_56 , V_49 , V_47 ) >= V_49 ) {
F_31 ( V_56 , V_47 , V_48 ) ;
V_50 = 0 ;
} else
V_50 = - V_58 ;
F_29 ( & V_55 ) ;
return V_50 ;
}
static void F_32 ( unsigned int V_47 , unsigned int V_48 )
{
unsigned int V_49 = V_47 + V_48 ;
F_3 ( V_49 > V_51 ) ;
F_28 ( & V_55 ) ;
F_33 ( V_56 , V_47 , V_48 ) ;
F_29 ( & V_55 ) ;
}
static void F_34 ( void * V_59 )
{
struct V_4 * V_5 = (struct V_4 * ) V_59 ;
F_35 ( & V_5 -> V_60 ) ;
}
static int F_36 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
T_2 V_65 = F_37 ( V_62 -> V_66 ) ;
T_2 V_67 = V_65 ;
V_64 -> V_68 = 0xff ;
V_64 -> V_69 = 0x3f ;
F_38 ( V_67 , V_64 -> V_68 * V_64 -> V_69 ) ;
V_64 -> V_67 = V_67 ;
if ( ( T_2 ) ( V_64 -> V_67 + 1 ) * V_64 -> V_68 * V_64 -> V_69 < V_65 )
V_64 -> V_67 = 0xffff ;
return 0 ;
}
static int F_39 ( struct V_61 * V_70 , T_3 V_71 ,
unsigned V_72 , unsigned long V_73 )
{
struct V_15 * V_16 = V_70 -> V_66 -> V_74 ;
int V_22 ;
F_40 ( & V_16 -> V_32 -> V_75 , L_8 ,
V_72 , ( long ) V_73 ) ;
switch ( V_72 ) {
case V_76 :
F_40 ( & V_16 -> V_32 -> V_75 , L_9 ) ;
for ( V_22 = 0 ; V_22 < sizeof( struct V_77 ) ; V_22 ++ )
if ( F_41 ( 0 , ( char V_78 * ) ( V_73 + V_22 ) ) )
return - V_79 ;
return 0 ;
case V_80 : {
struct V_81 * V_82 = V_16 -> V_82 ;
if ( V_82 -> V_83 & V_84 )
return 0 ;
return - V_13 ;
}
default:
return - V_13 ;
}
return 0 ;
}
static unsigned long F_42 ( struct V_4 * V_5 ,
struct V_2 * V_9 ,
struct V_85 * * V_86 )
{
unsigned long V_12 ;
* V_86 = F_43 ( & V_5 -> V_87 , V_5 -> V_87 . V_88 ) ;
V_5 -> V_87 . V_88 ++ ;
V_12 = F_2 ( V_5 ) ;
V_5 -> V_8 [ V_12 ] . V_2 = V_9 ;
V_5 -> V_8 [ V_12 ] . V_89 = V_90 ;
V_5 -> V_8 [ V_12 ] . V_91 = V_92 ;
( * V_86 ) -> V_10 . V_11 . V_12 = V_12 ;
return V_12 ;
}
static int F_44 ( struct V_2 * V_9 , struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_7 ;
struct V_85 * V_86 ;
unsigned long V_12 ;
V_12 = F_42 ( V_5 , V_9 , & V_86 ) ;
V_86 -> V_93 = V_46 ;
V_86 -> V_10 . V_94 . V_95 = F_45 ( V_9 ) ;
V_86 -> V_10 . V_94 . V_12 = V_12 ;
V_86 -> V_10 . V_94 . V_96 = ( V_97 ) F_46 ( V_9 ) ;
if ( F_47 ( V_9 ) == V_98 && V_16 -> V_99 )
V_86 -> V_10 . V_94 . V_100 = V_101 ;
else
V_86 -> V_10 . V_94 . V_100 = 0 ;
V_5 -> V_8 [ V_12 ] . V_9 = * V_86 ;
return 0 ;
}
static void F_48 ( unsigned long V_35 , unsigned int V_102 ,
unsigned int V_103 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
int V_21 , V_107 ;
struct V_19 * V_20 ;
unsigned int V_108 , V_109 ;
unsigned int V_110 = V_106 -> V_110 ;
struct V_85 * V_86 = V_106 -> V_86 ;
struct V_4 * V_5 = V_106 -> V_5 ;
struct V_111 * V_8 = & V_5 -> V_8 [ V_106 -> V_12 ] ;
if ( F_49 ( V_106 -> V_112 &&
V_110 >= V_113 ) ) {
V_110 -= V_113 ;
V_86 = V_106 -> V_114 ;
}
if ( ( V_86 -> V_93 == V_115 ) &&
( V_110 % V_116 == 0 ) ) {
if ( V_106 -> V_117 )
F_50 ( V_106 -> V_117 ) ;
V_21 = V_110 / V_116 ;
V_20 = F_22 ( & V_106 -> V_34 , V_5 ) ;
V_8 -> V_118 [ V_21 ] = V_20 ;
V_106 -> V_117 = F_51 ( V_20 -> V_17 ) ;
V_86 -> V_10 . V_119 . V_120 [ V_21 ] = V_20 -> V_26 ;
}
V_20 = F_19 ( & V_106 -> V_34 , V_35 , V_5 ) ;
V_107 = V_20 -> V_26 ;
V_8 -> V_121 [ V_106 -> V_110 ] = V_20 ;
if ( V_106 -> V_122 ) {
void * V_123 ;
V_123 = F_51 ( V_20 -> V_17 ) ;
memcpy ( V_123 + V_102 ,
V_106 -> V_124 + V_106 -> V_125 ,
V_103 ) ;
F_50 ( V_123 ) ;
V_106 -> V_125 += V_103 ;
}
V_108 = V_102 >> 9 ;
V_109 = V_108 + ( V_103 >> 9 ) - 1 ;
if ( V_86 -> V_93 != V_115 ) {
V_86 -> V_10 . V_11 . V_126 [ V_110 ] =
(struct V_127 ) {
. V_26 = V_107 ,
. V_128 = V_108 ,
. V_129 = V_109 } ;
} else {
V_106 -> V_117 [ V_110 % V_116 ] =
(struct V_127 ) {
. V_26 = V_107 ,
. V_128 = V_108 ,
. V_129 = V_109 } ;
}
( V_106 -> V_110 ) ++ ;
}
static void F_52 ( struct V_85 * V_130 ,
struct V_85 * V_131 )
{
T_4 V_132 = V_130 -> V_10 . V_11 . V_132 ;
V_130 -> V_10 . V_11 . V_132 = V_113 ;
V_131 -> V_10 . V_11 . V_132 = V_132 - V_113 ;
V_131 -> V_10 . V_11 . V_96 = V_130 -> V_10 . V_11 . V_96 +
( V_113 * V_133 ) / 512 ;
V_131 -> V_10 . V_11 . V_134 = V_130 -> V_10 . V_11 . V_134 ;
V_131 -> V_93 = V_130 -> V_93 ;
}
static int F_53 ( struct V_2 * V_9 , struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_7 ;
struct V_85 * V_86 , * V_114 = NULL ;
unsigned long V_12 , V_135 = V_92 ;
bool V_112 = false ;
int V_22 ;
struct V_105 V_106 = {
. V_110 = 0 ,
. V_117 = NULL ,
. V_5 = V_5 ,
. V_122 = F_54 ( V_9 ) && V_16 -> V_25 ,
} ;
bool V_136 = false ;
struct V_137 * V_138 ;
int V_139 , V_140 , V_141 ;
V_140 = V_9 -> V_142 * V_143 ;
if ( V_140 > V_113 )
V_140 += F_55 ( V_140 ) ;
if ( V_5 -> V_31 < V_140 ) {
V_136 = true ;
if ( F_56 (
V_140 - V_5 -> V_31 ,
& V_106 . V_34 ) < 0 ) {
F_57 (
& V_5 -> V_144 ,
F_34 ,
V_5 ,
V_140 - V_5 -> V_31 ) ;
return 1 ;
}
}
V_12 = F_42 ( V_5 , V_9 , & V_86 ) ;
V_139 = F_58 ( V_9 -> V_145 , V_9 , V_5 -> V_8 [ V_12 ] . V_138 ) ;
V_141 = 0 ;
F_59 (rinfo->shadow[id].sg, sg, num_sg, i)
V_141 += F_60 ( V_138 -> V_102 , V_138 -> V_146 ) ;
V_112 = V_16 -> V_147 == 0 &&
V_141 > V_113 ;
F_3 ( ! V_148 && V_112 ) ;
V_5 -> V_8 [ V_12 ] . V_139 = V_139 ;
if ( V_141 > V_113 &&
F_61 ( ! V_112 ) ) {
F_3 ( F_47 ( V_9 ) == V_149 || V_9 -> V_150 & V_151 ) ;
V_86 -> V_93 = V_115 ;
V_86 -> V_10 . V_119 . V_152 = F_54 ( V_9 ) ?
V_43 : V_42 ;
V_86 -> V_10 . V_119 . V_96 = ( V_97 ) F_46 ( V_9 ) ;
V_86 -> V_10 . V_119 . V_134 = V_16 -> V_134 ;
V_86 -> V_10 . V_119 . V_132 = V_141 ;
} else {
V_86 -> V_10 . V_11 . V_96 = ( V_97 ) F_46 ( V_9 ) ;
V_86 -> V_10 . V_11 . V_134 = V_16 -> V_134 ;
V_86 -> V_93 = F_54 ( V_9 ) ?
V_43 : V_42 ;
if ( F_47 ( V_9 ) == V_149 || V_9 -> V_150 & V_151 ) {
if ( V_16 -> V_153 && V_16 -> V_154 )
V_86 -> V_93 =
V_44 ;
else if ( V_16 -> V_153 )
V_86 -> V_93 =
V_45 ;
else
V_86 -> V_93 = 0 ;
}
V_86 -> V_10 . V_11 . V_132 = V_141 ;
if ( F_49 ( V_112 ) ) {
V_135 = F_42 ( V_5 , V_9 ,
& V_114 ) ;
V_5 -> V_8 [ V_135 ] . V_139 = 0 ;
F_52 ( V_86 , V_114 ) ;
V_5 -> V_8 [ V_135 ] . V_91 = V_12 ;
V_5 -> V_8 [ V_12 ] . V_91 = V_135 ;
}
}
V_106 . V_86 = V_86 ;
V_106 . V_12 = V_12 ;
V_106 . V_112 = V_112 ;
if ( F_49 ( V_112 ) )
V_106 . V_114 = V_114 ;
F_59 (rinfo->shadow[id].sg, sg, num_sg, i) {
F_3 ( V_138 -> V_102 + V_138 -> V_146 > V_155 ) ;
if ( V_106 . V_122 ) {
V_106 . V_125 = V_138 -> V_102 ;
V_106 . V_124 = F_51 ( F_62 ( V_138 ) ) ;
}
F_63 ( F_62 ( V_138 ) ,
V_138 -> V_102 ,
V_138 -> V_146 ,
F_48 ,
& V_106 ) ;
if ( V_106 . V_122 )
F_50 ( V_106 . V_124 ) ;
}
if ( V_106 . V_117 )
F_50 ( V_106 . V_117 ) ;
V_5 -> V_8 [ V_12 ] . V_9 = * V_86 ;
if ( F_49 ( V_112 ) )
V_5 -> V_8 [ V_135 ] . V_9 = * V_114 ;
if ( V_136 )
F_64 ( V_106 . V_34 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_9 , struct V_4 * V_5 )
{
if ( F_49 ( V_5 -> V_7 -> V_156 != V_157 ) )
return 1 ;
if ( F_49 ( F_47 ( V_9 ) == V_158 ||
F_47 ( V_9 ) == V_98 ) )
return F_44 ( V_9 , V_5 ) ;
else
return F_53 ( V_9 , V_5 ) ;
}
static inline void F_66 ( struct V_4 * V_5 )
{
int V_159 ;
F_67 ( & V_5 -> V_87 , V_159 ) ;
if ( V_159 )
F_68 ( V_5 -> V_160 ) ;
}
static inline bool F_69 ( struct V_2 * V_9 ,
struct V_15 * V_16 )
{
return ( F_70 ( V_9 ) ||
( ( F_47 ( V_9 ) == V_149 ) &&
! V_16 -> V_153 ) ||
( ( V_9 -> V_150 & V_151 ) &&
! V_16 -> V_154 ) ) ;
}
static T_5 F_71 ( struct V_161 * V_162 ,
const struct V_163 * V_164 )
{
unsigned long V_83 ;
int V_165 = V_162 -> V_166 ;
struct V_15 * V_16 = V_162 -> V_167 -> V_168 ;
struct V_4 * V_5 = NULL ;
F_3 ( V_16 -> V_169 <= V_165 ) ;
V_5 = & V_16 -> V_5 [ V_165 ] ;
F_72 ( V_164 -> V_3 ) ;
F_73 ( & V_5 -> V_170 , V_83 ) ;
if ( F_74 ( & V_5 -> V_87 ) )
goto V_171;
if ( F_69 ( V_164 -> V_3 , V_5 -> V_7 ) )
goto V_172;
if ( F_65 ( V_164 -> V_3 , V_5 ) )
goto V_171;
F_66 ( V_5 ) ;
F_75 ( & V_5 -> V_170 , V_83 ) ;
return V_173 ;
V_172:
F_75 ( & V_5 -> V_170 , V_83 ) ;
return V_174 ;
V_171:
F_76 ( V_162 ) ;
F_75 ( & V_5 -> V_170 , V_83 ) ;
return V_175 ;
}
static void F_77 ( struct V_2 * V_3 )
{
F_78 ( V_3 , V_1 ( V_3 ) -> error ) ;
}
static void F_79 ( struct V_15 * V_16 )
{
struct V_176 * V_3 = V_16 -> V_3 ;
struct V_81 * V_82 = V_16 -> V_82 ;
unsigned int V_117 = V_16 -> V_147 ? :
V_113 ;
F_80 ( V_177 , V_3 ) ;
if ( V_16 -> V_178 ) {
F_80 ( V_179 , V_3 ) ;
F_81 ( V_3 , F_37 ( V_82 ) ) ;
V_3 -> V_180 . V_181 = V_16 -> V_181 ;
V_3 -> V_180 . V_182 = V_16 -> V_182 ;
if ( V_16 -> V_99 )
F_80 ( V_183 , V_3 ) ;
}
F_82 ( V_3 , V_16 -> V_184 ) ;
F_83 ( V_3 , V_16 -> V_185 ) ;
F_84 ( V_3 , ( V_117 * V_133 ) / 512 ) ;
F_85 ( V_3 , V_155 - 1 ) ;
F_86 ( V_3 , V_155 ) ;
F_87 ( V_3 , V_117 / V_143 ) ;
F_88 ( V_3 , 511 ) ;
}
static int F_89 ( struct V_81 * V_82 , T_6 V_184 ,
unsigned int V_185 )
{
struct V_176 * V_3 ;
struct V_15 * V_16 = V_82 -> V_74 ;
memset ( & V_16 -> V_186 , 0 , sizeof( V_16 -> V_186 ) ) ;
V_16 -> V_186 . V_187 = & V_188 ;
V_16 -> V_186 . V_189 = V_16 -> V_169 ;
if ( V_148 && V_16 -> V_147 == 0 ) {
V_16 -> V_186 . V_190 = F_4 ( V_16 ) / 2 ;
} else
V_16 -> V_186 . V_190 = F_4 ( V_16 ) ;
V_16 -> V_186 . V_191 = V_192 ;
V_16 -> V_186 . V_83 = V_193 | V_194 ;
V_16 -> V_186 . V_195 = sizeof( struct V_1 ) ;
V_16 -> V_186 . V_196 = V_16 ;
if ( F_90 ( & V_16 -> V_186 ) )
return - V_13 ;
V_3 = F_91 ( & V_16 -> V_186 ) ;
if ( F_92 ( V_3 ) ) {
F_93 ( & V_16 -> V_186 ) ;
return F_94 ( V_3 ) ;
}
V_3 -> V_168 = V_16 ;
V_16 -> V_3 = V_82 -> V_167 = V_3 ;
V_16 -> V_82 = V_82 ;
V_16 -> V_184 = V_184 ;
V_16 -> V_185 = V_185 ;
F_79 ( V_16 ) ;
return 0 ;
}
static const char * F_95 ( struct V_15 * V_16 )
{
if ( V_16 -> V_153 && V_16 -> V_154 )
return L_10 ;
else if ( V_16 -> V_153 )
return L_11 ;
else
return L_12 ;
}
static void F_96 ( struct V_15 * V_16 )
{
F_97 ( V_16 -> V_3 , V_16 -> V_153 ? true : false ,
V_16 -> V_154 ? true : false ) ;
F_98 ( L_13 ,
V_16 -> V_82 -> V_197 , F_95 ( V_16 ) ,
L_14 , V_16 -> V_25 ?
L_15 : L_16 , L_17 ,
V_16 -> V_147 ? L_15 : L_16 ) ;
}
static int F_99 ( int V_198 , int * V_47 , unsigned int * V_102 )
{
int V_199 ;
V_199 = F_100 ( V_198 ) ;
* V_47 = F_101 ( V_198 ) ;
switch ( V_199 ) {
case V_200 :
* V_102 = ( * V_47 / 64 ) + V_201 ;
* V_47 = ( ( * V_47 / 64 ) * V_202 ) +
V_203 ;
break;
case V_204 :
* V_102 = ( * V_47 / 64 ) + 2 + V_201 ;
* V_47 = ( ( ( * V_47 / 64 ) + 2 ) * V_202 ) +
V_203 ;
break;
case V_205 :
* V_102 = ( * V_47 / V_202 ) + V_206 ;
* V_47 = * V_47 + V_207 ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
* V_102 = ( * V_47 / V_202 ) +
( ( V_199 - V_208 + 1 ) * 16 ) +
V_206 ;
* V_47 = * V_47 +
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
* V_102 = ( * V_47 / V_202 ) +
( ( V_199 - V_215 + 8 ) * 16 ) +
V_206 ;
* V_47 = * V_47 +
( ( V_199 - V_215 + 8 ) * 16 * V_202 ) +
V_207 ;
break;
case V_223 :
* V_102 = * V_47 / V_202 ;
break;
default:
F_102 ( V_224 L_18
L_19 ) ;
return - V_225 ;
}
return 0 ;
}
static char * F_103 ( char * V_226 , unsigned int V_21 )
{
if ( V_21 >= 26 )
V_226 = F_103 ( V_226 , V_21 / 26 - 1 ) ;
* V_226 = 'a' + V_21 % 26 ;
return V_226 + 1 ;
}
static int F_104 ( V_97 V_227 ,
struct V_15 * V_16 ,
T_6 V_228 , T_6 V_184 ,
unsigned int V_185 )
{
struct V_81 * V_82 ;
int V_51 = 1 ;
int V_229 ;
unsigned int V_102 ;
int V_47 ;
int V_230 ;
char * V_226 ;
F_3 ( V_16 -> V_82 != NULL ) ;
F_3 ( V_16 -> V_3 != NULL ) ;
if ( ( V_16 -> V_198 >> V_231 ) > 1 ) {
F_102 ( V_224 L_20 , V_16 -> V_198 ) ;
return - V_225 ;
}
if ( ! F_105 ( V_16 -> V_198 ) ) {
V_229 = F_99 ( V_16 -> V_198 , & V_47 , & V_102 ) ;
if ( V_229 )
return V_229 ;
V_230 = V_202 ;
} else {
V_47 = F_106 ( V_16 -> V_198 ) ;
V_230 = V_232 ;
V_102 = V_47 / V_230 ;
if ( F_107 () && V_102 < V_201 + 4 )
F_102 ( V_224 L_21
L_22
L_23 , V_16 -> V_198 ) ;
}
if ( V_47 >> V_233 ) {
F_108 ( L_24 ,
V_16 -> V_198 , V_47 ) ;
return - V_225 ;
}
if ( ( V_47 % V_230 ) == 0 )
V_51 = V_230 ;
V_229 = F_25 ( V_47 , V_51 ) ;
if ( V_229 )
goto V_234;
V_229 = - V_225 ;
V_82 = F_109 ( V_51 ) ;
if ( V_82 == NULL )
goto V_235;
strcpy ( V_82 -> V_197 , V_236 ) ;
V_226 = F_103 ( V_82 -> V_197 + sizeof( V_236 ) - 1 , V_102 ) ;
F_3 ( V_226 >= V_82 -> V_197 + V_237 ) ;
if ( V_51 > 1 )
* V_226 = 0 ;
else
snprintf ( V_226 , V_82 -> V_197 + V_237 - V_226 ,
L_25 , V_47 & ( V_230 - 1 ) ) ;
V_82 -> V_199 = V_223 ;
V_82 -> V_238 = V_47 ;
V_82 -> V_239 = & V_240 ;
V_82 -> V_74 = V_16 ;
F_110 ( V_82 , V_227 ) ;
if ( F_89 ( V_82 , V_184 , V_185 ) ) {
F_111 ( V_82 ) ;
goto V_235;
}
F_96 ( V_16 ) ;
if ( V_228 & V_241 )
F_112 ( V_82 , 1 ) ;
if ( V_228 & V_242 )
V_82 -> V_83 |= V_243 ;
if ( V_228 & V_244 )
V_82 -> V_83 |= V_84 ;
return 0 ;
V_235:
F_32 ( V_47 , V_51 ) ;
V_234:
return V_229 ;
}
static void F_113 ( struct V_15 * V_16 )
{
unsigned int V_47 , V_51 , V_22 ;
if ( V_16 -> V_3 == NULL )
return;
F_114 ( V_16 -> V_3 ) ;
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ ) {
struct V_4 * V_5 = & V_16 -> V_5 [ V_22 ] ;
F_115 ( & V_5 -> V_144 ) ;
F_116 ( & V_5 -> V_60 ) ;
}
F_111 ( V_16 -> V_82 ) ;
V_47 = V_16 -> V_82 -> V_238 ;
V_51 = V_16 -> V_82 -> V_56 ;
F_32 ( V_47 , V_51 ) ;
F_117 ( V_16 -> V_3 ) ;
F_93 ( & V_16 -> V_186 ) ;
V_16 -> V_3 = NULL ;
F_118 ( V_16 -> V_82 ) ;
V_16 -> V_82 = NULL ;
}
static inline void F_119 ( struct V_4 * V_5 )
{
if ( ! F_74 ( & V_5 -> V_87 ) )
F_120 ( V_5 -> V_7 -> V_3 , true ) ;
}
static void F_121 ( struct V_4 * V_5 )
{
unsigned long V_83 ;
F_73 ( & V_5 -> V_170 , V_83 ) ;
F_119 ( V_5 ) ;
F_75 ( & V_5 -> V_170 , V_83 ) ;
}
static void F_122 ( struct V_245 * V_60 )
{
struct V_4 * V_5 = F_123 ( V_60 , struct V_4 , V_60 ) ;
if ( V_5 -> V_7 -> V_156 == V_157 )
F_121 ( V_5 ) ;
}
static void F_124 ( struct V_4 * V_5 )
{
struct V_19 * V_246 , * V_21 ;
struct V_15 * V_16 = V_5 -> V_7 ;
int V_22 , V_247 , V_248 ;
if ( ! F_15 ( & V_5 -> V_38 ) ) {
struct V_17 * V_37 , * V_21 ;
F_3 ( V_16 -> V_25 ) ;
F_11 (indirect_page, n, &rinfo->indirect_pages, lru) {
F_12 ( & V_37 -> V_39 ) ;
F_13 ( V_37 ) ;
}
}
if ( ! F_15 ( & V_5 -> V_29 ) ) {
F_11 (persistent_gnt, n,
&rinfo->grants, node) {
F_12 ( & V_246 -> V_28 ) ;
if ( V_246 -> V_26 != V_27 ) {
F_125 ( V_246 -> V_26 ,
0 , 0UL ) ;
V_5 -> V_31 -- ;
}
if ( V_16 -> V_25 )
F_13 ( V_246 -> V_17 ) ;
F_9 ( V_246 ) ;
}
}
F_3 ( V_5 -> V_31 != 0 ) ;
for ( V_22 = 0 ; V_22 < F_4 ( V_16 ) ; V_22 ++ ) {
if ( ! V_5 -> V_8 [ V_22 ] . V_2 )
goto V_249;
V_248 = V_5 -> V_8 [ V_22 ] . V_9 . V_93 == V_115 ?
V_5 -> V_8 [ V_22 ] . V_9 . V_10 . V_119 . V_132 :
V_5 -> V_8 [ V_22 ] . V_9 . V_10 . V_11 . V_132 ;
for ( V_247 = 0 ; V_247 < V_248 ; V_247 ++ ) {
V_246 = V_5 -> V_8 [ V_22 ] . V_121 [ V_247 ] ;
F_125 ( V_246 -> V_26 , 0 , 0UL ) ;
if ( V_16 -> V_25 )
F_13 ( V_246 -> V_17 ) ;
F_9 ( V_246 ) ;
}
if ( V_5 -> V_8 [ V_22 ] . V_9 . V_93 != V_115 )
goto V_249;
for ( V_247 = 0 ; V_247 < F_55 ( V_248 ) ; V_247 ++ ) {
V_246 = V_5 -> V_8 [ V_22 ] . V_118 [ V_247 ] ;
F_125 ( V_246 -> V_26 , 0 , 0UL ) ;
F_13 ( V_246 -> V_17 ) ;
F_9 ( V_246 ) ;
}
V_249:
F_9 ( V_5 -> V_8 [ V_22 ] . V_121 ) ;
V_5 -> V_8 [ V_22 ] . V_121 = NULL ;
F_9 ( V_5 -> V_8 [ V_22 ] . V_118 ) ;
V_5 -> V_8 [ V_22 ] . V_118 = NULL ;
F_9 ( V_5 -> V_8 [ V_22 ] . V_138 ) ;
V_5 -> V_8 [ V_22 ] . V_138 = NULL ;
}
F_115 ( & V_5 -> V_144 ) ;
F_116 ( & V_5 -> V_60 ) ;
for ( V_22 = 0 ; V_22 < V_16 -> V_250 ; V_22 ++ ) {
if ( V_5 -> V_251 [ V_22 ] != V_27 ) {
F_125 ( V_5 -> V_251 [ V_22 ] , 0 , 0 ) ;
V_5 -> V_251 [ V_22 ] = V_27 ;
}
}
F_126 ( ( unsigned long ) V_5 -> V_87 . V_252 , F_127 ( V_16 -> V_250 * V_133 ) ) ;
V_5 -> V_87 . V_252 = NULL ;
if ( V_5 -> V_160 )
F_128 ( V_5 -> V_160 , V_5 ) ;
V_5 -> V_253 = V_5 -> V_160 = 0 ;
}
static void F_129 ( struct V_15 * V_16 , int V_254 )
{
unsigned int V_22 ;
V_16 -> V_156 = V_254 ?
V_255 : V_256 ;
if ( V_16 -> V_3 )
F_114 ( V_16 -> V_3 ) ;
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ )
F_124 ( & V_16 -> V_5 [ V_22 ] ) ;
F_9 ( V_16 -> V_5 ) ;
V_16 -> V_5 = NULL ;
V_16 -> V_169 = 0 ;
}
static void F_130 ( unsigned long V_35 , unsigned int V_102 ,
unsigned int V_103 , void * V_104 )
{
struct V_257 * V_16 = V_104 ;
char * V_123 ;
const struct V_111 * V_258 = V_16 -> V_258 ;
V_123 = F_51 ( V_258 -> V_121 [ V_16 -> V_110 ] -> V_17 ) ;
memcpy ( V_16 -> V_124 + V_16 -> V_259 ,
V_123 + V_102 , V_103 ) ;
V_16 -> V_259 += V_103 ;
V_16 -> V_110 ++ ;
F_50 ( V_123 ) ;
}
static enum V_260 F_131 ( int V_261 )
{
switch ( V_261 )
{
case V_262 :
return V_263 ;
case V_264 :
return V_265 ;
case V_266 :
default:
return V_267 ;
}
}
static int F_132 ( enum V_260 V_268 ,
enum V_260 V_269 )
{
F_3 ( V_268 == V_90 ) ;
F_3 ( V_269 == V_90 ) ;
if ( V_268 == V_267 || V_269 == V_267 )
return V_266 ;
else if ( V_268 == V_265 || V_269 == V_265 )
return V_264 ;
return V_262 ;
}
static bool F_133 ( unsigned long * V_12 ,
struct V_4 * V_5 ,
struct V_270 * V_271 )
{
int V_22 = 0 ;
struct V_137 * V_138 ;
int V_139 , V_141 ;
struct V_15 * V_16 = V_5 -> V_7 ;
struct V_111 * V_258 = & V_5 -> V_8 [ * V_12 ] ;
struct V_257 V_104 = {
. V_110 = 0 ,
} ;
V_141 = V_258 -> V_9 . V_93 == V_115 ?
V_258 -> V_9 . V_10 . V_119 . V_132 : V_258 -> V_9 . V_10 . V_11 . V_132 ;
if ( F_49 ( V_258 -> V_91 != V_92 ) ) {
struct V_111 * V_269 = & V_5 -> V_8 [ V_258 -> V_91 ] ;
V_258 -> V_89 = F_131 ( V_271 -> V_89 ) ;
if ( V_269 -> V_89 == V_90 )
return 0 ;
V_271 -> V_89 = F_132 ( V_258 -> V_89 ,
V_269 -> V_89 ) ;
V_141 += V_269 -> V_9 . V_10 . V_11 . V_132 ;
if ( V_269 -> V_139 != 0 ) {
* V_12 = V_258 -> V_91 ;
V_258 = V_269 ;
}
if ( F_5 ( V_5 , V_258 -> V_91 ) )
F_134 ( 1 , L_26 ,
V_16 -> V_82 -> V_197 , V_258 -> V_91 ) ;
}
V_104 . V_258 = V_258 ;
V_139 = V_258 -> V_139 ;
if ( V_271 -> V_93 == V_42 && V_16 -> V_25 ) {
F_59 (s->sg, sg, num_sg, i) {
F_3 ( V_138 -> V_102 + V_138 -> V_146 > V_155 ) ;
V_104 . V_259 = V_138 -> V_102 ;
V_104 . V_124 = F_51 ( F_62 ( V_138 ) ) ;
F_63 ( F_62 ( V_138 ) ,
V_138 -> V_102 ,
V_138 -> V_146 ,
F_130 ,
& V_104 ) ;
F_50 ( V_104 . V_124 ) ;
}
}
for ( V_22 = 0 ; V_22 < V_141 ; V_22 ++ ) {
if ( F_135 ( V_258 -> V_121 [ V_22 ] -> V_26 ) ) {
if ( ! V_16 -> V_25 )
F_136 ( L_27 ,
V_258 -> V_121 [ V_22 ] -> V_26 ) ;
F_10 ( & V_258 -> V_121 [ V_22 ] -> V_28 , & V_5 -> V_29 ) ;
V_5 -> V_31 ++ ;
} else {
F_125 ( V_258 -> V_121 [ V_22 ] -> V_26 , 0 , 0UL ) ;
V_258 -> V_121 [ V_22 ] -> V_26 = V_27 ;
F_137 ( & V_258 -> V_121 [ V_22 ] -> V_28 , & V_5 -> V_29 ) ;
}
}
if ( V_258 -> V_9 . V_93 == V_115 ) {
for ( V_22 = 0 ; V_22 < F_55 ( V_141 ) ; V_22 ++ ) {
if ( F_135 ( V_258 -> V_118 [ V_22 ] -> V_26 ) ) {
if ( ! V_16 -> V_25 )
F_136 ( L_27 ,
V_258 -> V_118 [ V_22 ] -> V_26 ) ;
F_10 ( & V_258 -> V_118 [ V_22 ] -> V_28 , & V_5 -> V_29 ) ;
V_5 -> V_31 ++ ;
} else {
struct V_17 * V_37 ;
F_125 ( V_258 -> V_118 [ V_22 ] -> V_26 , 0 , 0UL ) ;
if ( ! V_16 -> V_25 ) {
V_37 = V_258 -> V_118 [ V_22 ] -> V_17 ;
F_10 ( & V_37 -> V_39 , & V_5 -> V_38 ) ;
}
V_258 -> V_118 [ V_22 ] -> V_26 = V_27 ;
F_137 ( & V_258 -> V_118 [ V_22 ] -> V_28 , & V_5 -> V_29 ) ;
}
}
}
return 1 ;
}
static T_7 F_138 ( int V_160 , void * V_272 )
{
struct V_2 * V_9 ;
struct V_270 * V_271 ;
T_8 V_22 , V_273 ;
unsigned long V_83 ;
struct V_4 * V_5 = (struct V_4 * ) V_272 ;
struct V_15 * V_16 = V_5 -> V_7 ;
if ( F_49 ( V_16 -> V_156 != V_157 ) )
return V_274 ;
F_73 ( & V_5 -> V_170 , V_83 ) ;
V_275:
V_273 = V_5 -> V_87 . V_252 -> V_276 ;
F_139 () ;
for ( V_22 = V_5 -> V_87 . V_277 ; V_22 != V_273 ; V_22 ++ ) {
unsigned long V_12 ;
V_271 = F_140 ( & V_5 -> V_87 , V_22 ) ;
V_12 = V_271 -> V_12 ;
if ( V_12 >= F_4 ( V_16 ) ) {
F_134 ( 1 , L_28 ,
V_16 -> V_82 -> V_197 , F_23 ( V_271 -> V_93 ) , V_12 ) ;
continue;
}
V_9 = V_5 -> V_8 [ V_12 ] . V_2 ;
if ( V_271 -> V_93 != V_46 ) {
if ( ! F_133 ( & V_12 , V_5 , V_271 ) )
continue;
}
if ( F_5 ( V_5 , V_12 ) ) {
F_134 ( 1 , L_29 ,
V_16 -> V_82 -> V_197 , F_23 ( V_271 -> V_93 ) , V_12 ) ;
continue;
}
if ( V_271 -> V_89 == V_262 )
V_1 ( V_9 ) -> error = V_173 ;
else
V_1 ( V_9 ) -> error = V_174 ;
switch ( V_271 -> V_93 ) {
case V_46 :
if ( F_49 ( V_271 -> V_89 == V_264 ) ) {
struct V_176 * V_3 = V_16 -> V_3 ;
F_102 ( V_224 L_30 ,
V_16 -> V_82 -> V_197 , F_23 ( V_271 -> V_93 ) ) ;
V_1 ( V_9 ) -> error = V_278 ;
V_16 -> V_178 = 0 ;
V_16 -> V_99 = 0 ;
F_141 ( V_179 , V_3 ) ;
F_141 ( V_183 , V_3 ) ;
}
break;
case V_45 :
case V_44 :
if ( F_49 ( V_271 -> V_89 == V_264 ) ) {
F_102 ( V_224 L_30 ,
V_16 -> V_82 -> V_197 , F_23 ( V_271 -> V_93 ) ) ;
V_1 ( V_9 ) -> error = V_278 ;
}
if ( F_49 ( V_271 -> V_89 == V_266 &&
V_5 -> V_8 [ V_12 ] . V_9 . V_10 . V_11 . V_132 == 0 ) ) {
F_102 ( V_224 L_31 ,
V_16 -> V_82 -> V_197 , F_23 ( V_271 -> V_93 ) ) ;
V_1 ( V_9 ) -> error = V_278 ;
}
if ( F_49 ( V_1 ( V_9 ) -> error ) ) {
if ( V_1 ( V_9 ) -> error == V_278 )
V_1 ( V_9 ) -> error = V_173 ;
V_16 -> V_154 = 0 ;
V_16 -> V_153 = 0 ;
F_96 ( V_16 ) ;
}
case V_42 :
case V_43 :
if ( F_49 ( V_271 -> V_89 != V_262 ) )
F_40 ( & V_16 -> V_32 -> V_75 , L_32
L_33 , V_271 -> V_89 ) ;
break;
default:
F_142 () ;
}
F_143 ( V_9 ) ;
}
V_5 -> V_87 . V_277 = V_22 ;
if ( V_22 != V_5 -> V_87 . V_88 ) {
int V_279 ;
F_144 ( & V_5 -> V_87 , V_279 ) ;
if ( V_279 )
goto V_275;
} else
V_5 -> V_87 . V_252 -> V_280 = V_22 + 1 ;
F_119 ( V_5 ) ;
F_75 ( & V_5 -> V_170 , V_83 ) ;
return V_274 ;
}
static int F_145 ( struct V_281 * V_75 ,
struct V_4 * V_5 )
{
struct V_282 * V_252 ;
int V_229 , V_22 ;
struct V_15 * V_16 = V_5 -> V_7 ;
unsigned long V_283 = V_16 -> V_250 * V_133 ;
T_1 V_26 [ V_284 ] ;
for ( V_22 = 0 ; V_22 < V_16 -> V_250 ; V_22 ++ )
V_5 -> V_251 [ V_22 ] = V_27 ;
V_252 = (struct V_282 * ) F_146 ( V_23 | V_285 ,
F_127 ( V_283 ) ) ;
if ( ! V_252 ) {
F_147 ( V_75 , - V_30 , L_34 ) ;
return - V_30 ;
}
F_148 ( V_252 ) ;
F_149 ( & V_5 -> V_87 , V_252 , V_283 ) ;
V_229 = F_150 ( V_75 , V_5 -> V_87 . V_252 , V_16 -> V_250 , V_26 ) ;
if ( V_229 < 0 ) {
F_126 ( ( unsigned long ) V_252 , F_127 ( V_283 ) ) ;
V_5 -> V_87 . V_252 = NULL ;
goto V_286;
}
for ( V_22 = 0 ; V_22 < V_16 -> V_250 ; V_22 ++ )
V_5 -> V_251 [ V_22 ] = V_26 [ V_22 ] ;
V_229 = F_151 ( V_75 , & V_5 -> V_253 ) ;
if ( V_229 )
goto V_286;
V_229 = F_152 ( V_5 -> V_253 , F_138 , 0 ,
L_35 , V_5 ) ;
if ( V_229 <= 0 ) {
F_147 ( V_75 , V_229 ,
L_36 ) ;
goto V_286;
}
V_5 -> V_160 = V_229 ;
return 0 ;
V_286:
F_129 ( V_16 , 0 ) ;
return V_229 ;
}
static int F_153 ( struct V_287 V_288 ,
struct V_4 * V_5 , const char * V_289 )
{
int V_229 ;
unsigned int V_22 ;
const char * V_290 = NULL ;
struct V_15 * V_16 = V_5 -> V_7 ;
if ( V_16 -> V_250 == 1 ) {
V_229 = F_154 ( V_288 , V_289 , L_37 , L_38 , V_5 -> V_251 [ 0 ] ) ;
if ( V_229 ) {
V_290 = L_39 ;
goto V_291;
}
} else {
for ( V_22 = 0 ; V_22 < V_16 -> V_250 ; V_22 ++ ) {
char V_292 [ V_293 ] ;
snprintf ( V_292 , V_293 , L_40 , V_22 ) ;
V_229 = F_154 ( V_288 , V_289 , V_292 ,
L_38 , V_5 -> V_251 [ V_22 ] ) ;
if ( V_229 ) {
V_290 = L_39 ;
goto V_291;
}
}
}
V_229 = F_154 ( V_288 , V_289 , L_41 , L_38 , V_5 -> V_253 ) ;
if ( V_229 ) {
V_290 = L_42 ;
goto V_291;
}
return 0 ;
V_291:
F_155 ( V_288 , 1 ) ;
if ( V_290 )
F_147 ( V_16 -> V_32 , V_229 , L_43 , V_290 ) ;
return V_229 ;
}
static int F_156 ( struct V_281 * V_75 ,
struct V_15 * V_16 )
{
const char * V_290 = NULL ;
struct V_287 V_288 ;
int V_229 ;
unsigned int V_22 , V_294 ;
unsigned int V_295 ;
V_294 = F_157 ( V_16 -> V_32 -> V_296 ,
L_44 , 0 ) ;
V_295 = F_158 ( V_297 , V_294 ) ;
V_16 -> V_250 = 1 << V_295 ;
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ ) {
struct V_4 * V_5 = & V_16 -> V_5 [ V_22 ] ;
V_229 = F_145 ( V_75 , V_5 ) ;
if ( V_229 )
goto V_298;
}
V_275:
V_229 = F_159 ( & V_288 ) ;
if ( V_229 ) {
F_147 ( V_75 , V_229 , L_45 ) ;
goto V_298;
}
if ( V_16 -> V_250 > 1 ) {
V_229 = F_154 ( V_288 , V_75 -> V_299 , L_46 , L_38 ,
V_295 ) ;
if ( V_229 ) {
V_290 = L_47 ;
goto V_291;
}
}
if ( V_16 -> V_169 == 1 ) {
V_229 = F_153 ( V_288 , & V_16 -> V_5 [ 0 ] , V_75 -> V_299 ) ;
if ( V_229 )
goto V_298;
} else {
char * V_300 ;
T_9 V_301 ;
V_229 = F_154 ( V_288 , V_75 -> V_299 , L_48 , L_38 ,
V_16 -> V_169 ) ;
if ( V_229 ) {
V_290 = L_49 ;
goto V_291;
}
V_301 = strlen ( V_75 -> V_299 ) + V_302 ;
V_300 = F_160 ( V_301 , V_54 ) ;
if ( ! V_300 ) {
V_229 = - V_30 ;
V_290 = L_50 ;
goto V_291;
}
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ ) {
memset ( V_300 , 0 , V_301 ) ;
snprintf ( V_300 , V_301 , L_51 , V_75 -> V_299 , V_22 ) ;
V_229 = F_153 ( V_288 , & V_16 -> V_5 [ V_22 ] , V_300 ) ;
if ( V_229 ) {
F_9 ( V_300 ) ;
goto V_298;
}
}
F_9 ( V_300 ) ;
}
V_229 = F_154 ( V_288 , V_75 -> V_299 , L_52 , L_43 ,
V_303 ) ;
if ( V_229 ) {
V_290 = L_53 ;
goto V_291;
}
V_229 = F_154 ( V_288 , V_75 -> V_299 ,
L_54 , L_38 , 1 ) ;
if ( V_229 )
F_161 ( & V_75 -> V_75 ,
L_55 ) ;
V_229 = F_155 ( V_288 , 0 ) ;
if ( V_229 ) {
if ( V_229 == - V_304 )
goto V_275;
F_147 ( V_75 , V_229 , L_56 ) ;
goto V_298;
}
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ ) {
unsigned int V_247 ;
struct V_4 * V_5 = & V_16 -> V_5 [ V_22 ] ;
for ( V_247 = 0 ; V_247 < F_4 ( V_16 ) ; V_247 ++ )
V_5 -> V_8 [ V_247 ] . V_9 . V_10 . V_11 . V_12 = V_247 + 1 ;
V_5 -> V_8 [ F_4 ( V_16 ) - 1 ] . V_9 . V_10 . V_11 . V_12 = 0x0fffffff ;
}
F_162 ( V_75 , V_305 ) ;
return 0 ;
V_291:
F_155 ( V_288 , 1 ) ;
if ( V_290 )
F_147 ( V_75 , V_229 , L_43 , V_290 ) ;
V_298:
F_129 ( V_16 , 0 ) ;
F_9 ( V_16 ) ;
F_163 ( & V_75 -> V_75 , NULL ) ;
return V_229 ;
}
static int F_164 ( struct V_15 * V_16 )
{
unsigned int V_306 ;
unsigned int V_22 ;
F_3 ( V_16 -> V_169 ) ;
V_306 = F_157 ( V_16 -> V_32 -> V_296 ,
L_57 , 1 ) ;
V_16 -> V_169 = F_158 ( V_306 , V_307 ) ;
if ( ! V_16 -> V_169 )
V_16 -> V_169 = 1 ;
V_16 -> V_5 = F_7 ( sizeof( struct V_4 ) * V_16 -> V_169 , V_54 ) ;
if ( ! V_16 -> V_5 ) {
F_147 ( V_16 -> V_32 , - V_30 , L_58 ) ;
return - V_30 ;
}
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ ) {
struct V_4 * V_5 ;
V_5 = & V_16 -> V_5 [ V_22 ] ;
F_165 ( & V_5 -> V_38 ) ;
F_165 ( & V_5 -> V_29 ) ;
V_5 -> V_7 = V_16 ;
F_166 ( & V_5 -> V_60 , F_122 ) ;
F_167 ( & V_5 -> V_170 ) ;
}
return 0 ;
}
static int F_168 ( struct V_281 * V_75 ,
const struct V_308 * V_12 )
{
int V_229 , V_198 ;
struct V_15 * V_16 ;
V_229 = F_169 ( V_309 , V_75 -> V_299 ,
L_59 , L_60 , & V_198 ) ;
if ( V_229 != 1 ) {
V_229 = F_169 ( V_309 , V_75 -> V_299 , L_61 ,
L_60 , & V_198 ) ;
if ( V_229 != 1 ) {
F_147 ( V_75 , V_229 , L_62 ) ;
return V_229 ;
}
}
if ( F_107 () ) {
char * type ;
int V_103 ;
if ( F_170 () ) {
int V_199 ;
if ( ! F_105 ( V_198 ) )
V_199 = F_100 ( V_198 ) ;
else
V_199 = V_223 ;
if ( V_199 != V_223 ) {
F_102 ( V_310
L_63 ,
V_311 , V_198 ) ;
return - V_225 ;
}
}
type = F_171 ( V_309 , V_75 -> V_299 , L_64 , & V_103 ) ;
if ( F_92 ( type ) )
return - V_225 ;
if ( strncmp ( type , L_65 , 5 ) == 0 ) {
F_9 ( type ) ;
return - V_225 ;
}
F_9 ( type ) ;
}
V_16 = F_7 ( sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
F_147 ( V_75 , - V_30 , L_66 ) ;
return - V_30 ;
}
V_16 -> V_32 = V_75 ;
V_229 = F_164 ( V_16 ) ;
if ( V_229 ) {
F_9 ( V_16 ) ;
return V_229 ;
}
F_172 ( & V_16 -> V_312 ) ;
V_16 -> V_198 = V_198 ;
V_16 -> V_156 = V_256 ;
V_16 -> V_134 = F_173 ( strrchr ( V_75 -> V_299 , '/' ) + 1 , NULL , 0 ) ;
F_163 ( & V_75 -> V_75 , V_16 ) ;
return 0 ;
}
static int F_174 ( struct V_15 * V_16 )
{
unsigned int V_313 ;
struct V_2 * V_9 , * V_21 ;
int V_50 ;
struct V_314 * V_314 ;
unsigned int V_248 ;
F_175 ( V_16 ) ;
F_79 ( V_16 ) ;
V_248 = V_16 -> V_147 ? : V_113 ;
F_87 ( V_16 -> V_3 , V_248 / V_143 ) ;
for ( V_313 = 0 ; V_313 < V_16 -> V_169 ; V_313 ++ ) {
struct V_4 * V_5 = & V_16 -> V_5 [ V_313 ] ;
V_50 = F_176 ( V_5 ) ;
if ( V_50 )
return V_50 ;
}
F_162 ( V_16 -> V_32 , V_315 ) ;
V_16 -> V_156 = V_157 ;
for ( V_313 = 0 ; V_313 < V_16 -> V_169 ; V_313 ++ ) {
struct V_4 * V_5 ;
V_5 = & V_16 -> V_5 [ V_313 ] ;
F_121 ( V_5 ) ;
}
F_11 (req, n, &info->requests, queuelist) {
F_177 ( & V_9 -> V_316 ) ;
F_3 ( V_9 -> V_142 > V_248 ) ;
F_178 ( V_9 , false ) ;
}
F_120 ( V_16 -> V_3 , true ) ;
F_179 ( V_16 -> V_3 ) ;
while ( ( V_314 = F_180 ( & V_16 -> V_317 ) ) != NULL ) {
F_181 ( V_314 ) ;
}
return 0 ;
}
static int F_182 ( struct V_281 * V_75 )
{
struct V_15 * V_16 = F_183 ( & V_75 -> V_75 ) ;
int V_229 = 0 ;
unsigned int V_22 , V_247 ;
F_40 ( & V_75 -> V_75 , L_67 , V_75 -> V_299 ) ;
F_184 ( & V_16 -> V_317 ) ;
F_165 ( & V_16 -> V_318 ) ;
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ ) {
struct V_4 * V_5 = & V_16 -> V_5 [ V_22 ] ;
struct V_317 V_319 ;
struct V_111 * V_8 = V_5 -> V_8 ;
for ( V_247 = 0 ; V_247 < F_4 ( V_16 ) ; V_247 ++ ) {
if ( ! V_8 [ V_247 ] . V_2 )
continue;
if ( F_47 ( V_8 [ V_247 ] . V_2 ) == V_149 ||
F_47 ( V_8 [ V_247 ] . V_2 ) == V_158 ||
F_47 ( V_8 [ V_247 ] . V_2 ) == V_98 ||
V_8 [ V_247 ] . V_2 -> V_150 & V_151 ) {
F_10 ( & V_8 [ V_247 ] . V_2 -> V_316 , & V_16 -> V_318 ) ;
continue;
}
V_319 . V_320 = V_8 [ V_247 ] . V_2 -> V_314 ;
V_319 . V_321 = V_8 [ V_247 ] . V_2 -> V_322 ;
F_185 ( & V_16 -> V_317 , & V_319 ) ;
V_8 [ V_247 ] . V_2 -> V_314 = NULL ;
F_78 ( V_8 [ V_247 ] . V_2 , V_173 ) ;
}
}
F_129 ( V_16 , V_16 -> V_156 == V_157 ) ;
V_229 = F_164 ( V_16 ) ;
if ( V_229 )
return V_229 ;
V_229 = F_156 ( V_75 , V_16 ) ;
if ( ! V_229 )
F_186 ( & V_16 -> V_186 , V_16 -> V_169 ) ;
return V_229 ;
}
static void F_187 ( struct V_15 * V_16 )
{
struct V_281 * V_32 = V_16 -> V_32 ;
struct V_61 * V_70 = NULL ;
F_188 ( & V_16 -> V_312 ) ;
if ( V_32 -> V_323 == V_324 ) {
F_189 ( & V_16 -> V_312 ) ;
return;
}
if ( V_16 -> V_82 )
V_70 = F_190 ( V_16 -> V_82 , 0 ) ;
F_189 ( & V_16 -> V_312 ) ;
if ( ! V_70 ) {
F_191 ( V_32 ) ;
return;
}
F_188 ( & V_70 -> V_325 ) ;
if ( V_70 -> V_326 ) {
F_192 ( V_32 , - V_58 ,
L_68 ) ;
F_162 ( V_32 , V_324 ) ;
} else {
F_113 ( V_16 ) ;
F_191 ( V_32 ) ;
}
F_189 ( & V_70 -> V_325 ) ;
F_193 ( V_70 ) ;
}
static void F_194 ( struct V_15 * V_16 )
{
int V_229 ;
unsigned int V_181 ;
unsigned int V_182 ;
V_16 -> V_178 = 1 ;
V_229 = F_195 ( V_309 , V_16 -> V_32 -> V_296 ,
L_69 , L_38 , & V_181 ,
L_70 , L_38 , & V_182 ,
NULL ) ;
if ( ! V_229 ) {
V_16 -> V_181 = V_181 ;
V_16 -> V_182 = V_182 ;
}
V_16 -> V_99 =
! ! F_157 ( V_16 -> V_32 -> V_296 , L_71 ,
0 ) ;
}
static int F_176 ( struct V_4 * V_5 )
{
unsigned int V_327 , V_29 ;
int V_229 , V_22 ;
struct V_15 * V_16 = V_5 -> V_7 ;
if ( V_16 -> V_147 == 0 ) {
if ( ! V_148 )
V_29 = V_113 ;
else {
V_29 = V_143 ;
}
}
else
V_29 = V_16 -> V_147 ;
V_327 = F_196 ( V_29 , V_143 ) ;
V_229 = F_6 ( V_5 ,
( V_29 + F_55 ( V_29 ) ) * F_4 ( V_16 ) ) ;
if ( V_229 )
goto V_24;
if ( ! V_16 -> V_25 && V_16 -> V_147 ) {
int V_14 = F_55 ( V_29 ) * F_4 ( V_16 ) ;
F_3 ( ! F_15 ( & V_5 -> V_38 ) ) ;
for ( V_22 = 0 ; V_22 < V_14 ; V_22 ++ ) {
struct V_17 * V_37 = F_8 ( V_23 ) ;
if ( ! V_37 )
goto V_24;
F_10 ( & V_37 -> V_39 , & V_5 -> V_38 ) ;
}
}
for ( V_22 = 0 ; V_22 < F_4 ( V_16 ) ; V_22 ++ ) {
V_5 -> V_8 [ V_22 ] . V_121 = F_7 (
sizeof( V_5 -> V_8 [ V_22 ] . V_121 [ 0 ] ) * V_29 ,
V_23 ) ;
V_5 -> V_8 [ V_22 ] . V_138 = F_7 ( sizeof( V_5 -> V_8 [ V_22 ] . V_138 [ 0 ] ) * V_327 , V_23 ) ;
if ( V_16 -> V_147 )
V_5 -> V_8 [ V_22 ] . V_118 = F_7 (
sizeof( V_5 -> V_8 [ V_22 ] . V_118 [ 0 ] ) *
F_55 ( V_29 ) ,
V_23 ) ;
if ( ( V_5 -> V_8 [ V_22 ] . V_121 == NULL ) ||
( V_5 -> V_8 [ V_22 ] . V_138 == NULL ) ||
( V_16 -> V_147 &&
( V_5 -> V_8 [ V_22 ] . V_118 == NULL ) ) )
goto V_24;
F_197 ( V_5 -> V_8 [ V_22 ] . V_138 , V_327 ) ;
}
return 0 ;
V_24:
for ( V_22 = 0 ; V_22 < F_4 ( V_16 ) ; V_22 ++ ) {
F_9 ( V_5 -> V_8 [ V_22 ] . V_121 ) ;
V_5 -> V_8 [ V_22 ] . V_121 = NULL ;
F_9 ( V_5 -> V_8 [ V_22 ] . V_138 ) ;
V_5 -> V_8 [ V_22 ] . V_138 = NULL ;
F_9 ( V_5 -> V_8 [ V_22 ] . V_118 ) ;
V_5 -> V_8 [ V_22 ] . V_118 = NULL ;
}
if ( ! F_15 ( & V_5 -> V_38 ) ) {
struct V_17 * V_37 , * V_21 ;
F_11 (indirect_page, n, &rinfo->indirect_pages, lru) {
F_12 ( & V_37 -> V_39 ) ;
F_13 ( V_37 ) ;
}
}
return - V_30 ;
}
static void F_175 ( struct V_15 * V_16 )
{
unsigned int V_328 ;
V_16 -> V_153 = 0 ;
V_16 -> V_154 = 0 ;
if ( F_157 ( V_16 -> V_32 -> V_296 , L_72 , 0 ) ) {
V_16 -> V_153 = 1 ;
V_16 -> V_154 = 1 ;
}
if ( F_157 ( V_16 -> V_32 -> V_296 , L_73 ,
0 ) ) {
V_16 -> V_153 = 1 ;
V_16 -> V_154 = 0 ;
}
if ( F_157 ( V_16 -> V_32 -> V_296 , L_74 , 0 ) )
F_194 ( V_16 ) ;
V_16 -> V_25 =
! ! F_157 ( V_16 -> V_32 -> V_296 ,
L_54 , 0 ) ;
V_328 = F_157 ( V_16 -> V_32 -> V_296 ,
L_75 , 0 ) ;
if ( V_328 > V_329 )
V_328 = V_329 ;
if ( V_328 <= V_113 )
V_328 = 0 ;
V_16 -> V_147 = V_328 ;
}
static void F_198 ( struct V_15 * V_16 )
{
unsigned long long V_69 ;
unsigned long V_184 ;
unsigned int V_185 ;
unsigned int V_330 ;
char * V_331 [] = { L_76 , NULL } ;
int V_229 , V_22 ;
switch ( V_16 -> V_156 ) {
case V_157 :
V_229 = F_169 ( V_309 , V_16 -> V_32 -> V_296 ,
L_77 , L_78 , & V_69 ) ;
if ( F_199 ( V_229 ) )
return;
F_102 ( V_310 L_79 ,
V_69 ) ;
F_110 ( V_16 -> V_82 , V_69 ) ;
F_200 ( V_16 -> V_82 ) ;
F_201 ( & F_202 ( V_16 -> V_82 ) -> V_332 ,
V_333 , V_331 ) ;
return;
case V_255 :
F_174 ( V_16 ) ;
return;
default:
break;
}
F_40 ( & V_16 -> V_32 -> V_75 , L_80 ,
V_311 , V_16 -> V_32 -> V_296 ) ;
V_229 = F_195 ( V_309 , V_16 -> V_32 -> V_296 ,
L_77 , L_81 , & V_69 ,
L_82 , L_38 , & V_330 ,
L_83 , L_84 , & V_184 ,
NULL ) ;
if ( V_229 ) {
F_147 ( V_16 -> V_32 , V_229 ,
L_85 ,
V_16 -> V_32 -> V_296 ) ;
return;
}
V_185 = F_157 ( V_16 -> V_32 -> V_296 ,
L_86 ,
V_184 ) ;
F_175 ( V_16 ) ;
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ ) {
V_229 = F_176 ( & V_16 -> V_5 [ V_22 ] ) ;
if ( V_229 ) {
F_147 ( V_16 -> V_32 , V_229 , L_87 ,
V_16 -> V_32 -> V_296 ) ;
F_129 ( V_16 , 0 ) ;
break;
}
}
V_229 = F_104 ( V_69 , V_16 , V_330 , V_184 ,
V_185 ) ;
if ( V_229 ) {
F_147 ( V_16 -> V_32 , V_229 , L_88 ,
V_16 -> V_32 -> V_296 ) ;
goto V_286;
}
F_162 ( V_16 -> V_32 , V_315 ) ;
V_16 -> V_156 = V_157 ;
for ( V_22 = 0 ; V_22 < V_16 -> V_169 ; V_22 ++ )
F_121 ( & V_16 -> V_5 [ V_22 ] ) ;
F_203 ( & V_16 -> V_32 -> V_75 , V_16 -> V_82 ) ;
V_16 -> V_334 = 1 ;
return;
V_286:
F_129 ( V_16 , 0 ) ;
return;
}
static void F_204 ( struct V_281 * V_75 ,
enum V_335 V_336 )
{
struct V_15 * V_16 = F_183 ( & V_75 -> V_75 ) ;
F_40 ( & V_75 -> V_75 , L_89 , V_336 ) ;
switch ( V_336 ) {
case V_337 :
if ( V_75 -> V_323 != V_338 )
break;
if ( F_156 ( V_75 , V_16 ) )
break;
case V_338 :
case V_305 :
case V_339 :
case V_340 :
case V_341 :
break;
case V_315 :
if ( ( V_75 -> V_323 != V_305 ) &&
( V_75 -> V_323 != V_315 ) ) {
if ( F_156 ( V_75 , V_16 ) )
break;
}
F_198 ( V_16 ) ;
break;
case V_342 :
if ( V_75 -> V_323 == V_342 )
break;
case V_324 :
if ( V_16 )
F_187 ( V_16 ) ;
break;
}
}
static int F_205 ( struct V_281 * V_32 )
{
struct V_15 * V_16 = F_183 ( & V_32 -> V_75 ) ;
struct V_61 * V_70 = NULL ;
struct V_81 * V_343 ;
F_40 ( & V_32 -> V_75 , L_90 , V_32 -> V_299 ) ;
F_129 ( V_16 , 0 ) ;
F_188 ( & V_16 -> V_312 ) ;
V_343 = V_16 -> V_82 ;
if ( V_343 )
V_70 = F_190 ( V_343 , 0 ) ;
V_16 -> V_32 = NULL ;
F_189 ( & V_16 -> V_312 ) ;
if ( ! V_70 ) {
F_9 ( V_16 ) ;
return 0 ;
}
F_188 ( & V_70 -> V_325 ) ;
V_16 = V_343 -> V_74 ;
F_161 ( F_202 ( V_343 ) ,
L_91 ,
V_32 -> V_299 , V_70 -> V_326 ) ;
if ( V_16 && ! V_70 -> V_326 ) {
F_113 ( V_16 ) ;
V_343 -> V_74 = NULL ;
F_9 ( V_16 ) ;
}
F_189 ( & V_70 -> V_325 ) ;
F_193 ( V_70 ) ;
return 0 ;
}
static int F_206 ( struct V_281 * V_75 )
{
struct V_15 * V_16 = F_183 ( & V_75 -> V_75 ) ;
return V_16 -> V_334 && V_16 -> V_32 ;
}
static int F_207 ( struct V_61 * V_70 , T_3 V_71 )
{
struct V_81 * V_343 = V_70 -> V_66 ;
struct V_15 * V_16 ;
int V_229 = 0 ;
F_188 ( & V_344 ) ;
V_16 = V_343 -> V_74 ;
if ( ! V_16 ) {
V_229 = - V_345 ;
goto V_234;
}
F_188 ( & V_16 -> V_312 ) ;
if ( ! V_16 -> V_82 )
V_229 = - V_345 ;
F_189 ( & V_16 -> V_312 ) ;
V_234:
F_189 ( & V_344 ) ;
return V_229 ;
}
static void F_208 ( struct V_81 * V_343 , T_3 V_71 )
{
struct V_15 * V_16 = V_343 -> V_74 ;
struct V_61 * V_70 ;
struct V_281 * V_32 ;
F_188 ( & V_344 ) ;
V_70 = F_190 ( V_343 , 0 ) ;
if ( ! V_70 ) {
F_134 ( 1 , L_92 , V_343 -> V_197 ) ;
goto V_346;
}
if ( V_70 -> V_326 )
goto V_234;
F_188 ( & V_16 -> V_312 ) ;
V_32 = V_16 -> V_32 ;
if ( V_32 && V_32 -> V_323 == V_324 ) {
V_7 ( F_202 ( V_70 -> V_66 ) , L_93 ) ;
F_113 ( V_16 ) ;
F_191 ( V_16 -> V_32 ) ;
}
F_189 ( & V_16 -> V_312 ) ;
if ( ! V_32 ) {
V_7 ( F_202 ( V_70 -> V_66 ) , L_93 ) ;
F_113 ( V_16 ) ;
V_343 -> V_74 = NULL ;
F_9 ( V_16 ) ;
}
V_234:
F_193 ( V_70 ) ;
V_346:
F_189 ( & V_344 ) ;
}
static int T_10 F_209 ( void )
{
int V_347 ;
int V_348 = F_210 () ;
if ( ! F_211 () )
return - V_225 ;
if ( V_329 < V_113 )
V_329 = V_113 ;
if ( V_297 > V_349 ) {
F_98 ( L_94 ,
V_297 , V_349 ) ;
V_297 = V_349 ;
}
if ( V_307 > V_348 ) {
F_98 ( L_95 ,
V_307 , V_348 ) ;
V_307 = V_348 ;
}
if ( ! F_212 () )
return - V_225 ;
if ( F_213 ( V_223 , V_236 ) ) {
F_102 ( V_224 L_96 ,
V_223 , V_236 ) ;
return - V_225 ;
}
V_347 = F_214 ( & V_350 ) ;
if ( V_347 ) {
F_215 ( V_223 , V_236 ) ;
return V_347 ;
}
return 0 ;
}
static void T_11 F_216 ( void )
{
F_217 ( & V_350 ) ;
F_215 ( V_223 , V_236 ) ;
F_9 ( V_56 ) ;
}
