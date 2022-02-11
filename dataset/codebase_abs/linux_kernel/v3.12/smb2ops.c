static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 += V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_5 = V_2 -> V_4 = 0 ;
switch ( V_2 -> V_3 ) {
case 0 :
return - 1 ;
case 1 :
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
F_2 ( V_8 , L_1 ) ;
break;
case 2 :
V_2 -> V_6 = true ;
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
F_2 ( V_9 , L_2 ) ;
break;
default:
V_2 -> V_6 = true ;
V_2 -> V_7 = true ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = 1 ;
}
V_2 -> V_3 -= V_2 -> V_4 + V_2 -> V_5 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 , const unsigned int V_10 ,
const int V_11 )
{
int * V_12 , V_13 = 0 ;
F_4 ( & V_2 -> V_14 ) ;
V_12 = V_2 -> V_15 -> V_16 ( V_2 , V_11 ) ;
* V_12 += V_10 ;
V_2 -> V_17 -- ;
if ( V_2 -> V_17 == 0 && ( V_11 & V_18 ) != V_19 )
V_13 = F_1 ( V_2 ) ;
else if ( V_2 -> V_17 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
if ( V_13 )
F_7 ( V_2 ) ;
}
static void
F_8 ( struct V_1 * V_2 , const int V_12 )
{
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 = V_12 ;
F_5 ( & V_2 -> V_14 ) ;
}
static int *
F_9 ( struct V_1 * V_2 , const int V_11 )
{
switch ( V_11 ) {
case V_21 :
return & V_2 -> V_4 ;
case V_22 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_10 ( struct V_23 * V_24 )
{
return F_11 ( ( (struct V_25 * ) V_24 -> V_26 ) -> V_27 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_4 ( & V_28 ) ;
V_24 = V_2 -> V_29 ++ ;
F_5 ( & V_28 ) ;
return V_24 ;
}
static struct V_23 *
F_13 ( struct V_1 * V_2 , char * V_30 )
{
struct V_23 * V_24 ;
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
F_4 ( & V_28 ) ;
F_14 (mid, &server->pending_mid_q, qhead) {
if ( ( V_24 -> V_24 == V_31 -> V_32 ) &&
( V_24 -> V_33 == V_34 ) &&
( V_24 -> V_35 == V_31 -> V_36 ) ) {
F_5 ( & V_28 ) ;
return V_24 ;
}
}
F_5 ( & V_28 ) ;
return NULL ;
}
static void
F_15 ( void * V_30 )
{
#ifdef F_16
struct V_25 * V_37 = (struct V_25 * ) V_30 ;
F_2 ( V_8 , L_3 ,
V_37 -> V_36 , V_37 -> V_38 , V_37 -> V_39 , V_37 -> V_32 ,
V_37 -> V_40 ) ;
F_2 ( V_8 , L_4 , V_37 , F_17 ( V_37 ) ) ;
#endif
}
static bool
F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_41 == 0 ;
}
static int
F_19 ( const unsigned int V_42 , struct V_43 * V_44 )
{
int V_13 ;
V_44 -> V_2 -> V_29 = 0 ;
V_13 = F_20 ( V_42 , V_44 ) ;
if ( V_13 == - V_45 )
V_13 = - V_46 ;
return V_13 ;
}
static unsigned int
F_21 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_51 ;
V_51 = V_50 -> V_51 ? V_50 -> V_51 : V_52 ;
V_51 = F_22 (unsigned int, wsize, server->max_write) ;
V_51 = F_22 (unsigned int, wsize, 2 << 15 ) ;
return V_51 ;
}
static unsigned int
F_23 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_53 ;
V_53 = V_50 -> V_53 ? V_50 -> V_53 : V_52 ;
V_53 = F_22 (unsigned int, rsize, server->max_read) ;
V_53 = F_22 (unsigned int, rsize, 2 << 15 ) ;
return V_53 ;
}
static int
F_24 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_54 * V_55 , const char * V_56 )
{
int V_13 ;
T_2 * V_57 ;
T_3 V_58 = V_59 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
V_57 = F_25 ( V_56 , V_55 ) ;
if ( ! V_57 )
return - V_64 ;
V_61 . V_48 = V_48 ;
V_61 . V_65 = V_66 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_61 . V_63 = & V_63 ;
V_61 . V_70 = false ;
V_13 = F_26 ( V_42 , & V_61 , V_57 , & V_58 , NULL , NULL ) ;
if ( V_13 ) {
F_27 ( V_57 ) ;
return V_13 ;
}
V_13 = F_28 ( V_42 , V_48 , V_63 . V_71 , V_63 . V_72 ) ;
F_27 ( V_57 ) ;
return V_13 ;
}
static int
F_29 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_54 * V_55 , const char * V_56 ,
T_4 * V_73 , T_5 * V_74 )
{
* V_73 = F_30 ( V_74 -> V_75 ) ;
return 0 ;
}
static int
F_31 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 , T_5 * V_74 )
{
int V_13 ;
struct V_76 * V_77 ;
V_77 = F_32 ( sizeof( struct V_76 ) + V_78 * 2 ,
V_79 ) ;
if ( V_77 == NULL )
return - V_64 ;
V_13 = F_33 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ,
V_77 ) ;
if ( ! V_13 )
F_34 ( V_74 , V_77 ) ;
F_27 ( V_77 ) ;
return V_13 ;
}
static bool
F_35 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_36 ( struct V_47 * V_48 )
{
#ifdef F_37
int V_80 ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
F_38 ( & V_48 -> V_82 . V_83 . V_84 [ V_80 ] , 0 ) ;
F_38 ( & V_48 -> V_82 . V_83 . V_85 [ V_80 ] , 0 ) ;
}
#endif
}
static void
F_39 ( struct V_86 * V_87 , struct V_47 * V_48 )
{
F_40 ( V_87 , L_5 ) ;
if ( V_48 -> V_88 & V_89 )
F_40 ( V_87 , L_6 ) ;
if ( V_48 -> V_88 & V_90 )
F_40 ( V_87 , L_7 ) ;
if ( V_48 -> V_88 & V_91 )
F_40 ( V_87 , L_8 ) ;
if ( V_48 -> V_88 & V_92 )
F_40 ( V_87 , L_9 ) ;
if ( V_48 -> V_88 & V_93 )
F_40 ( V_87 , L_10 ) ;
if ( V_48 -> V_88 == 0 )
F_40 ( V_87 , L_11 ) ;
F_41 ( V_87 , L_12 , V_48 -> V_94 ) ;
}
static void
F_42 ( struct V_86 * V_87 , struct V_47 * V_48 )
{
#ifdef F_37
T_6 * V_95 = V_48 -> V_82 . V_83 . V_84 ;
T_6 * V_96 = V_48 -> V_82 . V_83 . V_85 ;
F_41 ( V_87 , L_13 ,
F_43 ( & V_95 [ V_97 ] ) ,
F_43 ( & V_96 [ V_97 ] ) ) ;
F_41 ( V_87 , L_14 ,
F_43 ( & V_95 [ V_98 ] ) ,
F_43 ( & V_96 [ V_98 ] ) ) ;
F_41 ( V_87 , L_15 ,
F_43 ( & V_95 [ V_99 ] ) ,
F_43 ( & V_96 [ V_99 ] ) ) ;
F_41 ( V_87 , L_16 ,
F_43 ( & V_95 [ V_100 ] ) ,
F_43 ( & V_96 [ V_100 ] ) ) ;
F_41 ( V_87 , L_17 ,
F_43 ( & V_95 [ V_101 ] ) ,
F_43 ( & V_96 [ V_101 ] ) ) ;
F_41 ( V_87 , L_18 ,
F_43 ( & V_95 [ V_102 ] ) ,
F_43 ( & V_96 [ V_102 ] ) ) ;
F_41 ( V_87 , L_19 ,
F_43 ( & V_95 [ V_103 ] ) ,
F_43 ( & V_96 [ V_103 ] ) ) ;
F_41 ( V_87 , L_20 ,
F_43 ( & V_95 [ V_104 ] ) ,
F_43 ( & V_96 [ V_104 ] ) ) ;
F_41 ( V_87 , L_21 ,
F_43 ( & V_95 [ V_105 ] ) ,
F_43 ( & V_96 [ V_105 ] ) ) ;
F_41 ( V_87 , L_22 ,
F_43 ( & V_95 [ V_106 ] ) ,
F_43 ( & V_96 [ V_106 ] ) ) ;
F_41 ( V_87 , L_23 ,
F_43 ( & V_95 [ V_107 ] ) ,
F_43 ( & V_96 [ V_107 ] ) ) ;
F_41 ( V_87 , L_24 ,
F_43 ( & V_95 [ V_108 ] ) ,
F_43 ( & V_96 [ V_108 ] ) ) ;
F_41 ( V_87 , L_25 ,
F_43 ( & V_95 [ V_109 ] ) ,
F_43 ( & V_96 [ V_109 ] ) ) ;
F_41 ( V_87 , L_26 ,
F_43 ( & V_95 [ V_110 ] ) ,
F_43 ( & V_96 [ V_110 ] ) ) ;
F_41 ( V_87 , L_27 ,
F_43 ( & V_95 [ V_111 ] ) ,
F_43 ( & V_96 [ V_111 ] ) ) ;
F_41 ( V_87 , L_28 ,
F_43 ( & V_95 [ V_112 ] ) ,
F_43 ( & V_96 [ V_112 ] ) ) ;
F_41 ( V_87 , L_29 ,
F_43 ( & V_95 [ V_113 ] ) ,
F_43 ( & V_96 [ V_113 ] ) ) ;
F_41 ( V_87 , L_30 ,
F_43 ( & V_95 [ V_114 ] ) ,
F_43 ( & V_96 [ V_114 ] ) ) ;
F_41 ( V_87 , L_31 ,
F_43 ( & V_95 [ V_115 ] ) ,
F_43 ( & V_96 [ V_115 ] ) ) ;
#endif
}
static void
F_44 ( struct V_116 * V_117 , struct V_62 * V_63 , T_7 V_58 )
{
struct V_118 * V_119 = F_45 ( V_117 -> V_120 -> V_121 ) ;
struct V_1 * V_2 = F_46 ( V_117 -> V_122 ) -> V_44 -> V_2 ;
V_117 -> V_63 . V_71 = V_63 -> V_71 ;
V_117 -> V_63 . V_72 = V_63 -> V_72 ;
V_2 -> V_15 -> V_123 ( V_119 , V_58 , V_63 -> V_124 ,
& V_63 -> V_125 ) ;
V_119 -> V_126 = F_47 ( V_119 ) ;
}
static void
F_48 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 )
{
F_28 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
static int
F_49 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 )
{
return F_50 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
static unsigned int
F_51 ( char * V_30 )
{
struct V_127 * V_128 = (struct V_127 * ) V_30 ;
return V_128 -> V_129 ;
}
static unsigned int
F_52 ( char * V_30 )
{
struct V_127 * V_128 = (struct V_127 * ) V_30 ;
return F_53 ( V_128 -> V_130 ) ;
}
static int
F_54 ( const unsigned int V_42 , struct V_116 * V_117 ,
struct V_131 * V_132 , unsigned int * V_133 ,
char * * V_30 , int * V_134 )
{
V_132 -> V_71 = V_117 -> V_63 . V_71 ;
V_132 -> V_72 = V_117 -> V_63 . V_72 ;
return F_55 ( V_42 , V_132 , V_133 , V_30 , V_134 ) ;
}
static int
F_56 ( const unsigned int V_42 , struct V_116 * V_117 ,
struct V_131 * V_132 , unsigned int * V_135 ,
struct V_136 * V_137 , unsigned long V_138 )
{
V_132 -> V_71 = V_117 -> V_63 . V_71 ;
V_132 -> V_72 = V_117 -> V_63 . V_72 ;
return F_57 ( V_42 , V_132 , V_135 , V_137 , V_138 ) ;
}
static int
F_58 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_116 * V_117 , T_1 V_139 , bool V_140 )
{
T_8 V_141 = F_59 ( V_139 ) ;
return F_60 ( V_42 , V_48 , V_117 -> V_63 . V_71 ,
V_117 -> V_63 . V_72 , V_117 -> V_142 , & V_141 ) ;
}
static int
F_61 ( const unsigned int V_42 , struct V_47 * V_48 ,
const char * V_143 , struct V_54 * V_55 ,
struct V_62 * V_63 , T_9 V_144 ,
struct V_145 * V_146 )
{
T_2 * V_57 ;
int V_13 ;
T_3 V_58 = V_59 ;
struct V_60 V_61 ;
V_57 = F_25 ( V_143 , V_55 ) ;
if ( ! V_57 )
return - V_64 ;
V_61 . V_48 = V_48 ;
V_61 . V_65 = V_66 | V_147 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_61 . V_63 = V_63 ;
V_61 . V_70 = false ;
V_13 = F_26 ( V_42 , & V_61 , V_57 , & V_58 , NULL , NULL ) ;
F_27 ( V_57 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_32 ) ;
return V_13 ;
}
V_146 -> V_148 = 0 ;
V_146 -> V_149 = 0 ;
V_13 = F_62 ( V_42 , V_48 , V_63 -> V_71 ,
V_63 -> V_72 , 0 , V_146 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_33 ) ;
F_28 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
return V_13 ;
}
static int
F_63 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 , T_9 V_144 ,
struct V_145 * V_146 )
{
return F_62 ( V_42 , V_48 , V_63 -> V_71 ,
V_63 -> V_72 , 0 , V_146 ) ;
}
static int
F_64 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_62 * V_63 )
{
return F_28 ( V_42 , V_48 , V_63 -> V_71 , V_63 -> V_72 ) ;
}
static bool
F_65 ( char * V_30 , struct V_1 * V_2 , int V_150 )
{
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
if ( V_31 -> V_38 != V_151 )
return false ;
if ( ! V_150 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_31 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_66 ( struct V_47 * V_48 , struct V_62 * V_63 ,
struct V_118 * V_119 )
{
if ( V_48 -> V_44 -> V_2 -> V_88 & V_152 )
return F_67 ( 0 , V_48 , V_119 -> V_153 ,
F_68 ( V_119 ) ) ;
return F_69 ( 0 , V_48 , V_63 -> V_71 ,
V_63 -> V_72 ,
F_70 ( V_119 ) ? 1 : 0 ) ;
}
static int
F_71 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_154 * V_30 )
{
int V_13 ;
T_2 V_155 = 0 ;
T_10 V_58 = V_59 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
V_61 . V_48 = V_48 ;
V_61 . V_65 = V_66 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_61 . V_63 = & V_63 ;
V_61 . V_70 = false ;
V_13 = F_26 ( V_42 , & V_61 , & V_155 , & V_58 , NULL , NULL ) ;
if ( V_13 )
return V_13 ;
V_30 -> V_156 = V_157 ;
V_13 = F_72 ( V_42 , V_48 , V_63 . V_71 , V_63 . V_72 ,
V_30 ) ;
F_28 ( V_42 , V_48 , V_63 . V_71 , V_63 . V_72 ) ;
return V_13 ;
}
static bool
F_73 ( struct V_116 * V_158 , struct V_116 * V_159 )
{
return V_158 -> V_63 . V_71 == V_159 -> V_63 . V_71 &&
V_158 -> V_63 . V_72 == V_159 -> V_63 . V_72 ;
}
static int
F_74 ( const unsigned int V_42 , struct V_116 * V_117 , T_1 V_160 ,
T_1 V_150 , T_7 type , int V_161 , int V_162 , bool V_163 )
{
if ( V_162 && ! V_161 )
type = V_164 ;
return F_75 ( V_42 , F_46 ( V_117 -> V_122 ) ,
V_117 -> V_63 . V_71 , V_117 -> V_63 . V_72 ,
V_165 -> V_166 , V_150 , V_160 , type , V_163 ) ;
}
static void
F_76 ( struct V_167 * V_167 , struct V_62 * V_63 )
{
memcpy ( V_63 -> V_153 , F_45 ( V_167 ) -> V_153 , V_168 ) ;
}
static void
F_77 ( struct V_167 * V_167 , struct V_62 * V_63 )
{
memcpy ( F_45 ( V_167 ) -> V_153 , V_63 -> V_153 , V_168 ) ;
}
static void
F_78 ( struct V_62 * V_63 )
{
F_79 ( V_63 -> V_153 , V_168 ) ;
}
static int
F_80 ( const unsigned int V_42 , struct V_47 * V_48 ,
const char * V_56 , char * * V_169 ,
struct V_54 * V_55 )
{
int V_13 ;
T_2 * V_57 ;
T_3 V_58 = V_59 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
struct V_170 * V_171 = NULL ;
struct V_172 * V_173 ;
unsigned int V_174 , V_175 ;
F_2 ( V_9 , L_34 , V_176 , V_56 ) ;
V_57 = F_25 ( V_56 , V_55 ) ;
if ( ! V_57 )
return - V_64 ;
V_61 . V_48 = V_48 ;
V_61 . V_65 = V_66 ;
V_61 . V_67 = V_68 ;
V_61 . V_69 = 0 ;
V_61 . V_63 = & V_63 ;
V_61 . V_70 = false ;
V_13 = F_26 ( V_42 , & V_61 , V_57 , & V_58 , NULL , & V_171 ) ;
if ( ! V_13 || ! V_171 ) {
F_27 ( V_57 ) ;
return - V_177 ;
}
V_13 = 0 ;
V_173 = (struct V_172 * ) V_171 -> V_178 ;
V_174 = F_11 ( V_173 -> V_179 ) ;
V_175 = F_11 ( V_173 -> V_180 ) ;
* V_169 = F_81 (
( char * ) V_173 -> V_181 + V_175 ,
V_174 , true , V_55 -> V_182 ) ;
if ( ! ( * V_169 ) ) {
F_27 ( V_57 ) ;
return - V_64 ;
}
F_82 ( * V_169 , '/' ) ;
F_2 ( V_9 , L_35 , V_176 , * V_169 ) ;
F_27 ( V_57 ) ;
return V_13 ;
}
static void
F_83 ( struct V_118 * V_119 , T_7 V_58 ,
unsigned int V_124 , bool * V_125 )
{
V_58 &= 0xFF ;
if ( V_58 == V_183 )
return;
if ( V_58 == V_184 ) {
V_119 -> V_58 = V_185 ;
F_2 ( V_9 , L_36 ,
& V_119 -> V_186 ) ;
} else if ( V_58 == V_187 ) {
V_119 -> V_58 = V_188 ;
F_2 ( V_9 , L_37 ,
& V_119 -> V_186 ) ;
} else if ( V_58 == V_189 ) {
V_119 -> V_58 = V_190 ;
F_2 ( V_9 , L_38 ,
& V_119 -> V_186 ) ;
} else
V_119 -> V_58 = 0 ;
}
static void
F_84 ( struct V_118 * V_119 , T_7 V_58 ,
unsigned int V_124 , bool * V_125 )
{
char V_191 [ 5 ] = { 0 } ;
V_58 &= 0xFF ;
if ( V_58 == V_183 )
return;
V_119 -> V_58 = 0 ;
if ( V_58 & V_192 ) {
V_119 -> V_58 |= V_190 ;
strcat ( V_191 , L_39 ) ;
}
if ( V_58 & V_193 ) {
V_119 -> V_58 |= V_194 ;
strcat ( V_191 , L_40 ) ;
}
if ( V_58 & V_195 ) {
V_119 -> V_58 |= V_196 ;
strcat ( V_191 , L_41 ) ;
}
if ( ! V_119 -> V_58 )
strcat ( V_191 , L_42 ) ;
F_2 ( V_9 , L_43 , V_191 ,
& V_119 -> V_186 ) ;
}
static void
F_85 ( struct V_118 * V_119 , T_7 V_58 ,
unsigned int V_124 , bool * V_125 )
{
unsigned int V_197 = V_119 -> V_58 ;
F_84 ( V_119 , V_58 , V_124 , V_125 ) ;
if ( V_125 ) {
* V_125 = false ;
if ( V_197 == V_190 ) {
if ( V_119 -> V_58 == V_190 &&
( V_124 - V_119 -> V_124 > 0 ) )
* V_125 = true ;
else if ( V_119 -> V_58 == V_198 &&
( V_124 - V_119 -> V_124 > 1 ) )
* V_125 = true ;
else if ( V_119 -> V_58 == V_185 &&
( V_124 - V_119 -> V_124 > 1 ) )
* V_125 = true ;
else if ( V_119 -> V_58 == 0 &&
( V_124 - V_119 -> V_124 > 0 ) )
* V_125 = true ;
} else if ( V_197 == V_198 ) {
if ( V_119 -> V_58 == V_198 &&
( V_124 - V_119 -> V_124 > 0 ) )
* V_125 = true ;
else if ( V_119 -> V_58 == V_185 &&
( V_124 - V_119 -> V_124 > 1 ) )
* V_125 = true ;
}
V_119 -> V_124 = V_124 ;
}
}
static bool
F_86 ( T_7 V_58 )
{
return V_58 == V_189 ;
}
static bool
F_87 ( T_7 V_58 )
{
return ( V_58 & V_192 ) &&
! ( V_58 & V_195 ) ;
}
static T_11
F_88 ( T_10 V_58 )
{
if ( V_58 == V_187 )
return V_199 | V_200 ;
else if ( V_58 == V_189 )
return V_200 ;
else if ( V_58 == V_184 )
return V_201 | V_200 |
V_199 ;
return 0 ;
}
static char *
F_89 ( T_10 * V_153 , T_10 V_58 )
{
struct V_202 * V_30 ;
V_30 = F_32 ( sizeof( struct V_202 ) , V_79 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_203 . V_204 = F_59 ( * ( ( T_4 * ) V_153 ) ) ;
V_30 -> V_203 . V_205 = F_59 ( * ( ( T_4 * ) ( V_153 + 8 ) ) ) ;
V_30 -> V_203 . V_206 = F_88 ( V_58 ) ;
V_30 -> V_207 . V_129 = F_90 ( F_91
( struct V_202 , V_203 ) ) ;
V_30 -> V_207 . V_130 = F_92 ( sizeof( struct V_208 ) ) ;
V_30 -> V_207 . V_209 = F_90 ( F_91
( struct V_202 , V_210 ) ) ;
V_30 -> V_207 . V_211 = F_90 ( 4 ) ;
V_30 -> V_210 [ 0 ] = 'R' ;
V_30 -> V_210 [ 1 ] = 'q' ;
V_30 -> V_210 [ 2 ] = 'L' ;
V_30 -> V_210 [ 3 ] = 's' ;
return ( char * ) V_30 ;
}
static char *
F_93 ( T_10 * V_153 , T_10 V_58 )
{
struct V_212 * V_30 ;
V_30 = F_32 ( sizeof( struct V_212 ) , V_79 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_203 . V_204 = F_59 ( * ( ( T_4 * ) V_153 ) ) ;
V_30 -> V_203 . V_205 = F_59 ( * ( ( T_4 * ) ( V_153 + 8 ) ) ) ;
V_30 -> V_203 . V_206 = F_88 ( V_58 ) ;
V_30 -> V_207 . V_129 = F_90 ( F_91
( struct V_212 , V_203 ) ) ;
V_30 -> V_207 . V_130 = F_92 ( sizeof( struct V_213 ) ) ;
V_30 -> V_207 . V_209 = F_90 ( F_91
( struct V_212 , V_210 ) ) ;
V_30 -> V_207 . V_211 = F_90 ( 4 ) ;
V_30 -> V_210 [ 0 ] = 'R' ;
V_30 -> V_210 [ 1 ] = 'q' ;
V_30 -> V_210 [ 2 ] = 'L' ;
V_30 -> V_210 [ 3 ] = 's' ;
return ( char * ) V_30 ;
}
static T_3
F_94 ( void * V_30 , unsigned int * V_124 )
{
struct V_202 * V_214 = (struct V_202 * ) V_30 ;
* V_124 = 0 ;
if ( V_214 -> V_203 . V_215 & V_216 )
return V_183 ;
return F_53 ( V_214 -> V_203 . V_206 ) ;
}
static T_3
F_95 ( void * V_30 , unsigned int * V_124 )
{
struct V_212 * V_214 = (struct V_212 * ) V_30 ;
* V_124 = F_11 ( V_214 -> V_203 . V_217 ) ;
if ( V_214 -> V_203 . V_215 & V_216 )
return V_183 ;
return F_53 ( V_214 -> V_203 . V_206 ) ;
}
