static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 ;
F_2 ( V_4 , & V_5 , V_6 ) ;
F_3 ( V_5 , V_7 , ! V_2 ) ;
F_4 ( V_4 , & V_5 , V_6 ) ;
}
static void F_5 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 ;
F_2 ( V_4 , & V_5 , V_6 ) ;
F_3 ( V_5 , V_8 , ! V_2 ) ;
F_4 ( V_4 , & V_5 , V_6 ) ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 ;
F_2 ( V_4 , & V_5 , V_6 ) ;
return F_7 ( V_5 , V_9 ) ;
}
static int F_8 ( void * V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
T_1 V_5 ;
F_2 ( V_4 , & V_5 , V_6 ) ;
return F_7 ( V_5 , V_10 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
T_2 V_13 ;
struct V_3 * V_4 = V_12 -> V_4 ;
if ( V_12 -> V_14 ) {
F_10 ( V_13 ,
V_15 ,
V_16 ,
V_17 ,
V_12 -> V_14 - 1 ) ;
} else {
F_10 ( V_13 ,
V_15 ,
V_18 ,
V_17 , 0 ) ;
}
F_11 ( V_19 != V_20 ) ;
F_12 ( V_4 , & V_13 , V_20 ,
V_12 -> V_12 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_14 ( V_4 ) ;
F_15 ( 10 ) ;
}
static inline void F_16 ( struct V_3 * V_4 )
{
T_2 V_5 ;
F_17 ( V_5 , V_21 , 0xb7eb7e ) ;
F_18 ( V_4 , & V_5 , V_22 ) ;
F_19 ( V_4 , & V_5 , V_23 ) ;
}
static T_3 F_20 ( int V_24 , void * V_25 )
{
struct V_3 * V_4 = V_25 ;
T_1 * V_26 = V_4 -> V_27 . V_28 ;
int V_29 ;
int V_30 ;
if ( F_21 ( F_22 ( * V_26 ) ) ) {
F_23 ( V_4 , V_31 , V_4 -> V_32 ,
L_1 , V_24 ,
F_24 () ) ;
return V_33 ;
}
V_4 -> V_34 = F_24 () ;
F_23 ( V_4 , V_31 , V_4 -> V_32 ,
L_2 V_35 L_3 ,
V_24 , F_24 () , F_25 ( * V_26 ) ) ;
if ( ! F_26 ( F_27 ( V_4 -> V_36 ) ) )
return V_37 ;
V_29 = F_7 ( * V_26 , V_38 ) ;
if ( F_21 ( V_29 ) )
return F_28 ( V_4 ) ;
F_11 ( V_39 > V_40 ) ;
V_30 = F_7 ( * V_26 , V_41 ) ;
F_29 ( * V_26 ) ;
F_30 () ;
F_16 ( V_4 ) ;
if ( V_30 & 1 )
F_31 ( F_32 ( V_4 , 0 ) ) ;
if ( V_30 & 2 )
F_31 ( F_32 ( V_4 , 1 ) ) ;
return V_37 ;
}
static void F_33 ( struct V_3 * V_4 )
{
T_1 V_42 ;
memcpy ( & V_42 , V_4 -> V_43 , sizeof( V_42 ) ) ;
F_4 ( V_4 , & V_42 , V_44 ) ;
F_34 ( V_4 ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
T_1 V_5 ;
F_2 ( V_4 , & V_5 , V_45 ) ;
return F_7 ( V_5 , V_46 ) ? - V_47 : 0 ;
}
static int F_36 ( struct V_3 * V_4 )
{
unsigned long V_48 = V_49 + 1 + F_37 ( V_50 , 10 ) ;
int V_51 ;
for ( V_51 = 0 ; V_51 < 10 ; V_51 ++ ) {
if ( ! F_35 ( V_4 ) )
return 0 ;
F_38 ( 10 ) ;
}
for (; ; ) {
if ( ! F_35 ( V_4 ) )
return 0 ;
if ( F_39 ( V_49 , V_48 ) ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_4 ) ;
return - V_53 ;
}
F_41 ( 1 ) ;
}
}
static int
F_42 ( struct V_3 * V_4 , const struct V_54 * V_55 ,
unsigned int V_56 , int V_57 ,
const void * V_58 , void * V_59 , T_4 V_60 )
{
bool V_61 = ( V_57 >= 0 ) ;
bool V_62 = ( V_59 != NULL ) ;
T_1 V_5 ;
int V_63 ;
if ( V_60 > V_64 )
return - V_65 ;
V_63 = F_35 ( V_4 ) ;
if ( V_63 )
return V_63 ;
if ( V_61 ) {
F_43 ( V_5 , V_66 , V_57 ) ;
F_4 ( V_4 , & V_5 , V_67 ) ;
}
if ( V_58 != NULL ) {
memcpy ( & V_5 , V_58 , V_60 ) ;
F_4 ( V_4 , & V_5 , V_68 ) ;
}
F_44 ( V_5 ,
V_46 , 1 ,
V_69 , V_55 -> V_70 ,
V_71 , V_60 ,
V_72 , V_62 ,
V_73 , 0 ,
V_74 ,
( V_61 ? V_55 -> V_75 : 0 ) ,
V_76 , V_56 ) ;
F_4 ( V_4 , & V_5 , V_45 ) ;
V_63 = F_36 ( V_4 ) ;
if ( V_63 )
return V_63 ;
if ( V_59 != NULL ) {
F_2 ( V_4 , & V_5 , V_68 ) ;
memcpy ( V_59 , & V_5 , V_60 ) ;
}
return 0 ;
}
static inline T_5
F_45 ( const struct V_54 * V_55 ,
const T_5 V_56 , const unsigned int V_57 )
{
return V_56 | ( ( ( V_57 >> 8 ) & V_55 -> V_77 ) << 3 ) ;
}
static int
F_46 ( struct V_3 * V_4 , const struct V_54 * V_55 ,
T_6 V_78 , T_4 V_60 , T_4 * V_79 , T_5 * V_80 )
{
T_4 V_81 , V_82 = 0 ;
unsigned int V_56 ;
int V_63 = 0 ;
while ( V_82 < V_60 ) {
V_81 = F_47 ( V_60 - V_82 , V_64 ) ;
V_56 = F_45 ( V_55 , V_83 , V_78 + V_82 ) ;
V_63 = F_42 ( V_4 , V_55 , V_56 , V_78 + V_82 , NULL ,
V_80 + V_82 , V_81 ) ;
if ( V_63 )
break;
V_82 += V_81 ;
F_48 () ;
if ( F_49 ( V_84 ) ) {
V_63 = - V_85 ;
break;
}
}
if ( V_79 )
* V_79 = V_82 ;
return V_63 ;
}
static T_4
F_50 ( const struct V_54 * V_55 , T_4 V_78 )
{
return F_47 ( V_64 ,
( V_55 -> V_86 - ( V_78 & ( V_55 -> V_86 - 1 ) ) ) ) ;
}
static int
F_51 ( struct V_3 * V_4 , const struct V_54 * V_55 )
{
unsigned long V_48 = V_49 + 1 + F_37 ( V_50 , 100 ) ;
T_5 V_87 ;
int V_63 ;
for (; ; ) {
V_63 = F_42 ( V_4 , V_55 , V_88 , - 1 , NULL ,
& V_87 , sizeof( V_87 ) ) ;
if ( V_63 )
return V_63 ;
if ( ! ( V_87 & V_89 ) )
return 0 ;
if ( F_39 ( V_49 , V_48 ) ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_5
L_6 ,
V_55 -> V_70 , V_87 ) ;
return - V_53 ;
}
F_41 ( 1 ) ;
}
}
static int
F_52 ( struct V_3 * V_4 , const struct V_54 * V_55 ,
T_6 V_78 , T_4 V_60 , T_4 * V_79 , const T_5 * V_80 )
{
T_5 V_90 [ V_64 ] ;
T_4 V_81 , V_82 = 0 ;
unsigned int V_56 ;
int V_63 = 0 ;
while ( V_82 < V_60 ) {
V_63 = F_42 ( V_4 , V_55 , V_91 , - 1 , NULL , NULL , 0 ) ;
if ( V_63 )
break;
V_81 = F_47 ( V_60 - V_82 ,
F_50 ( V_55 , V_78 + V_82 ) ) ;
V_56 = F_45 ( V_55 , V_92 , V_78 + V_82 ) ;
V_63 = F_42 ( V_4 , V_55 , V_56 , V_78 + V_82 ,
V_80 + V_82 , NULL , V_81 ) ;
if ( V_63 )
break;
V_63 = F_51 ( V_4 , V_55 ) ;
if ( V_63 )
break;
V_56 = F_45 ( V_55 , V_83 , V_78 + V_82 ) ;
V_63 = F_42 ( V_4 , V_55 , V_56 , V_78 + V_82 ,
NULL , V_90 , V_81 ) ;
if ( memcmp ( V_90 , V_80 + V_82 , V_81 ) ) {
V_63 = - V_93 ;
break;
}
V_82 += V_81 ;
F_48 () ;
if ( F_49 ( V_84 ) ) {
V_63 = - V_85 ;
break;
}
}
if ( V_79 )
* V_79 = V_82 ;
return V_63 ;
}
static int
F_53 ( struct V_94 * V_95 , bool V_96 )
{
const struct V_54 * V_55 = V_95 -> V_55 ;
struct V_3 * V_4 = V_95 -> V_97 . V_98 . V_99 ;
T_5 V_87 ;
int V_63 , V_51 ;
for ( V_51 = 0 ; V_51 < 40 ; V_51 ++ ) {
F_54 ( V_96 ?
V_100 : V_101 ) ;
F_55 ( V_50 / 10 ) ;
V_63 = F_42 ( V_4 , V_55 , V_88 , - 1 , NULL ,
& V_87 , sizeof( V_87 ) ) ;
if ( V_63 )
return V_63 ;
if ( ! ( V_87 & V_89 ) )
return 0 ;
if ( F_49 ( V_84 ) )
return - V_85 ;
}
F_56 ( L_7 ,
V_95 -> V_97 . V_102 , V_95 -> V_97 . V_103 ) ;
return - V_53 ;
}
static int
F_57 ( struct V_3 * V_4 , const struct V_54 * V_55 )
{
const T_5 V_104 = ( V_105 | V_106 |
V_107 ) ;
T_5 V_87 ;
int V_63 ;
V_63 = F_42 ( V_4 , V_55 , V_88 , - 1 , NULL ,
& V_87 , sizeof( V_87 ) ) ;
if ( V_63 )
return V_63 ;
if ( ! ( V_87 & V_104 ) )
return 0 ;
V_63 = F_42 ( V_4 , V_55 , V_91 , - 1 , NULL , NULL , 0 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_42 ( V_4 , V_55 , V_108 , - 1 , NULL , NULL , 0 ) ;
if ( V_63 )
return V_63 ;
V_87 &= ~ V_104 ;
V_63 = F_42 ( V_4 , V_55 , V_109 , - 1 , & V_87 ,
NULL , sizeof( V_87 ) ) ;
if ( V_63 )
return V_63 ;
V_63 = F_51 ( V_4 , V_55 ) ;
if ( V_63 )
return V_63 ;
return 0 ;
}
static int
F_58 ( struct V_94 * V_95 , T_6 V_78 , T_4 V_60 )
{
const struct V_54 * V_55 = V_95 -> V_55 ;
struct V_3 * V_4 = V_95 -> V_97 . V_98 . V_99 ;
unsigned V_82 , V_81 ;
T_5 V_110 [ V_111 ] ;
T_5 V_80 [ V_111 ] ;
int V_63 ;
if ( V_60 != V_55 -> V_112 )
return - V_65 ;
if ( V_55 -> V_113 == 0 )
return - V_114 ;
V_63 = F_57 ( V_4 , V_55 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_42 ( V_4 , V_55 , V_91 , - 1 , NULL , NULL , 0 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_42 ( V_4 , V_55 , V_55 -> V_113 , V_78 , NULL ,
NULL , 0 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_53 ( V_95 , false ) ;
memset ( V_110 , 0xff , sizeof( V_110 ) ) ;
for ( V_82 = 0 ; V_82 < V_60 ; V_82 += V_81 ) {
V_81 = F_47 ( V_60 - V_82 , sizeof( V_80 ) ) ;
V_63 = F_46 ( V_4 , V_55 , V_78 + V_82 , V_81 ,
NULL , V_80 ) ;
if ( V_63 )
return V_63 ;
if ( memcmp ( V_110 , V_80 , V_81 ) )
return - V_93 ;
F_48 () ;
if ( F_49 ( V_84 ) )
return - V_85 ;
}
return V_63 ;
}
static void F_59 ( struct V_115 * V_95 )
{
struct V_3 * V_4 = V_95 -> V_98 . V_99 ;
snprintf ( V_95 -> V_102 , sizeof( V_95 -> V_102 ) , L_8 ,
V_4 -> V_102 , V_95 -> V_116 ) ;
}
static int F_60 ( struct V_117 * V_98 , T_6 V_78 ,
T_4 V_60 , T_4 * V_79 , T_5 * V_80 )
{
struct V_94 * V_95 = F_61 ( V_98 ) ;
struct V_3 * V_4 = V_98 -> V_99 ;
struct V_118 * V_119 = V_4 -> V_119 ;
int V_63 ;
V_63 = F_62 ( & V_119 -> V_120 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_46 ( V_4 , V_95 -> V_55 , V_95 -> V_121 + V_78 ,
V_60 , V_79 , V_80 ) ;
F_63 ( & V_119 -> V_120 ) ;
return V_63 ;
}
static int F_64 ( struct V_117 * V_98 , T_6 V_78 , T_4 V_60 )
{
struct V_94 * V_95 = F_61 ( V_98 ) ;
struct V_3 * V_4 = V_98 -> V_99 ;
struct V_118 * V_119 = V_4 -> V_119 ;
int V_63 ;
V_63 = F_62 ( & V_119 -> V_120 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_58 ( V_95 , V_95 -> V_121 + V_78 , V_60 ) ;
F_63 ( & V_119 -> V_120 ) ;
return V_63 ;
}
static int F_65 ( struct V_117 * V_98 , T_6 V_78 ,
T_4 V_60 , T_4 * V_79 , const T_5 * V_80 )
{
struct V_94 * V_95 = F_61 ( V_98 ) ;
struct V_3 * V_4 = V_98 -> V_99 ;
struct V_118 * V_119 = V_4 -> V_119 ;
int V_63 ;
V_63 = F_62 ( & V_119 -> V_120 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_52 ( V_4 , V_95 -> V_55 , V_95 -> V_121 + V_78 ,
V_60 , V_79 , V_80 ) ;
F_63 ( & V_119 -> V_120 ) ;
return V_63 ;
}
static int F_66 ( struct V_117 * V_98 )
{
struct V_94 * V_95 = F_61 ( V_98 ) ;
struct V_3 * V_4 = V_98 -> V_99 ;
struct V_118 * V_119 = V_4 -> V_119 ;
int V_63 ;
F_67 ( & V_119 -> V_120 ) ;
V_63 = F_53 ( V_95 , true ) ;
F_63 ( & V_119 -> V_120 ) ;
return V_63 ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
struct V_94 * V_122 ;
struct V_54 * V_55 ;
T_4 V_123 ;
int V_63 = - V_124 ;
F_69 () ;
V_122 = F_70 ( 2 , sizeof( * V_122 ) , V_125 ) ;
if ( ! V_122 )
return - V_126 ;
V_123 = 0 ;
V_55 = & V_119 -> V_127 ;
if ( F_71 ( V_55 ) && V_55 -> V_128 > V_129 ) {
V_122 [ V_123 ] . V_55 = V_55 ;
V_122 [ V_123 ] . V_121 = V_129 ;
V_122 [ V_123 ] . V_97 . V_103 = L_9 ;
V_122 [ V_123 ] . V_97 . V_116 = L_10 ;
V_122 [ V_123 ] . V_97 . V_98 . type = V_130 ;
V_122 [ V_123 ] . V_97 . V_98 . V_131 = V_132 ;
V_122 [ V_123 ] . V_97 . V_98 . V_128 = V_55 -> V_128 - V_129 ;
V_122 [ V_123 ] . V_97 . V_98 . V_133 = V_55 -> V_112 ;
V_123 ++ ;
}
V_55 = & V_119 -> V_134 ;
if ( F_71 ( V_55 ) && V_55 -> V_128 > V_135 ) {
V_122 [ V_123 ] . V_55 = V_55 ;
V_122 [ V_123 ] . V_121 = V_135 ;
V_122 [ V_123 ] . V_97 . V_103 = L_11 ;
V_122 [ V_123 ] . V_97 . V_116 = L_12 ;
V_122 [ V_123 ] . V_97 . V_98 . type = V_136 ;
V_122 [ V_123 ] . V_97 . V_98 . V_131 = V_137 ;
V_122 [ V_123 ] . V_97 . V_98 . V_128 =
F_47 ( V_55 -> V_128 , V_138 ) -
V_135 ;
V_122 [ V_123 ] . V_97 . V_98 . V_133 = V_55 -> V_112 ;
V_123 ++ ;
}
V_63 = F_72 ( V_4 , & V_122 [ 0 ] . V_97 , V_123 , sizeof( * V_122 ) ) ;
if ( V_63 )
F_73 ( V_122 ) ;
return V_63 ;
}
static void F_74 ( struct V_3 * V_4 )
{
T_1 V_139 , V_140 ;
if ( V_4 -> V_141 == V_142 )
return;
F_2 ( V_4 , & V_139 , V_143 ) ;
F_3 ( V_139 , V_144 , V_145 ) ;
F_3 ( V_139 , V_146 , V_145 ) ;
F_3 ( V_139 , V_147 , V_145 ) ;
F_3 ( V_139 , V_148 , V_145 ) ;
F_3 ( V_139 , V_149 , V_145 ) ;
F_3 ( V_139 , V_150 , V_145 ) ;
F_3 ( V_139 , V_151 , V_145 ) ;
F_3 ( V_139 , V_152 , V_145 ) ;
F_4 ( V_4 , & V_139 , V_143 ) ;
F_75 ( V_140 ,
V_153 , V_154 ,
V_155 , V_154 ,
V_156 , V_154 ,
V_157 , V_154 ,
V_158 , V_159 ,
V_160 , V_159 ,
V_161 , V_159 ,
V_162 , V_159 ) ;
F_4 ( V_4 , & V_140 , V_163 ) ;
}
int F_76 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_5 ;
int V_164 ;
F_77 ( V_119 -> V_165 == 0 ) ;
F_43 ( V_5 , V_166 , 1 ) ;
F_4 ( V_4 , & V_5 , V_167 ) ;
for ( V_164 = 0 ; V_164 < 1000 ; V_164 ++ ) {
F_2 ( V_4 , & V_5 , V_167 ) ;
if ( F_7 ( V_5 , V_166 ) == 0 &&
F_7 ( V_5 , V_168 ) == 0 ) {
F_74 ( V_4 ) ;
return 0 ;
}
F_38 ( 10 ) ;
}
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_13 ) ;
return - V_53 ;
}
static void F_78 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_5 ;
if ( ( F_79 ( V_4 ) != V_169 ) || F_80 ( V_4 ) )
return;
if ( ! V_4 -> V_170 . V_171 )
return;
if ( V_119 -> V_172 )
return;
F_2 ( V_4 , & V_5 , V_173 ) ;
}
static bool F_81 ( struct V_3 * V_4 )
{
T_1 V_5 ;
bool V_174 , V_175 = false ;
int V_176 ;
F_2 ( V_4 , & V_5 , V_177 ) ;
V_174 = F_7 ( V_5 , V_178 ) ;
V_176 = F_7 ( V_5 , V_179 ) ;
if ( V_174 && ( V_176 == V_180 ) )
V_175 = true ;
F_3 ( V_5 , V_181 , V_180 ) ;
F_3 ( V_5 , V_182 , V_180 ) ;
F_3 ( V_5 , V_183 , V_180 ) ;
F_4 ( V_4 , & V_5 , V_177 ) ;
return V_175 ;
}
static bool F_82 ( struct V_3 * V_4 )
{
return ( V_4 -> V_184 == V_185 ||
F_81 ( V_4 ) ) &&
( ! ( V_4 -> V_186 . V_187 & ( 1 << V_188 ) ) ||
F_80 ( V_4 ) ||
F_83 ( V_4 ) ) ;
}
static void F_84 ( struct V_3 * V_4 )
{
unsigned int V_189 ;
T_1 V_5 ;
bool V_190 = ! ! ( V_4 -> V_170 . V_191 & V_192 ) ;
bool V_193 = ! ! ( V_4 -> V_170 . V_191 & V_194 ) ;
F_85 ( V_5 ,
V_195 , 1 ,
V_196 , 1 ,
V_197 , 1 ) ;
F_4 ( V_4 , & V_5 , V_198 ) ;
F_86 ( V_5 ,
V_199 , 1 ,
V_200 , 1 ,
V_201 , 1 ,
V_202 , 1 ,
V_203 , V_193 ,
V_204 , 0x3 ) ;
F_4 ( V_4 , & V_5 , V_205 ) ;
F_87 ( V_5 ,
V_206 , 1 ,
V_207 , 0 ,
V_208 , 1 ,
V_209 , ! V_4 -> V_210 ,
V_211 , 1 ) ;
F_4 ( V_4 , & V_5 , V_212 ) ;
V_189 = F_88 ( V_4 -> V_32 -> V_213 ) ;
F_43 ( V_5 , V_214 , V_189 ) ;
F_4 ( V_4 , & V_5 , V_215 ) ;
F_89 ( V_5 ,
V_216 , V_189 ,
V_217 , 1 ) ;
F_4 ( V_4 , & V_5 , V_218 ) ;
F_89 ( V_5 ,
V_219 , 0xfffe ,
V_220 , ! V_190 ) ;
F_4 ( V_4 , & V_5 , V_221 ) ;
memcpy ( & V_5 , & V_4 -> V_32 -> V_222 [ 0 ] , 4 ) ;
F_4 ( V_4 , & V_5 , V_223 ) ;
memcpy ( & V_5 , & V_4 -> V_32 -> V_222 [ 4 ] , 2 ) ;
F_4 ( V_4 , & V_5 , V_224 ) ;
}
static void F_90 ( struct V_3 * V_4 )
{
T_1 V_5 ;
bool V_225 = ( V_4 -> V_184 == V_226 ) ;
bool V_227 = ( V_4 -> V_184 == V_228 ) ;
bool V_229 = ( V_4 -> V_184 == V_185 ) ;
bool V_230 , V_231 , V_232 ;
F_2 ( V_4 , & V_5 , V_177 ) ;
V_231 = F_7 ( V_5 , V_233 ) ;
V_230 = F_7 ( V_5 , V_234 ) ;
F_2 ( V_4 , & V_5 , V_143 ) ;
V_232 = F_7 ( V_5 , V_235 ) ;
if ( ( V_225 != V_231 ) ||
( V_227 != V_232 ) ||
( V_229 != V_230 ) )
F_76 ( V_4 ) ;
F_2 ( V_4 , & V_5 , V_177 ) ;
F_3 ( V_5 , V_236 ,
( V_225 || V_227 ) ?
V_237 : 0 ) ;
F_3 ( V_5 , V_233 , V_225 ) ;
F_3 ( V_5 , V_234 , V_229 ) ;
F_4 ( V_4 , & V_5 , V_177 ) ;
F_2 ( V_4 , & V_5 , V_143 ) ;
F_3 ( V_5 , V_238 , V_227 ) ;
F_3 ( V_5 , V_239 , V_227 ) ;
F_3 ( V_5 , V_240 , V_227 ) ;
F_3 ( V_5 , V_235 , V_227 ) ;
F_4 ( V_4 , & V_5 , V_143 ) ;
}
static bool F_91 ( struct V_3 * V_4 , int V_241 )
{
bool V_242 = F_82 ( V_4 ) ;
if ( F_92 ( V_4 ) & F_93 ( V_4 ) & V_243 ||
F_94 ( V_4 -> V_244 ) )
return V_242 ;
F_95 ( V_4 ) ;
while ( ! V_242 && V_241 ) {
F_96 ( V_4 , V_52 , V_4 -> V_32 , L_14 ) ;
F_76 ( V_4 ) ;
F_38 ( 200 ) ;
V_242 = F_82 ( V_4 ) ;
-- V_241 ;
}
F_97 ( V_4 ) ;
return V_242 ;
}
static bool F_98 ( struct V_3 * V_4 )
{
return ! F_91 ( V_4 , 5 ) ;
}
static int F_99 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
F_100 ( V_4 ) ;
F_90 ( V_4 ) ;
F_84 ( V_4 ) ;
F_101 ( V_4 ) ;
V_119 -> V_172 = ! F_91 ( V_4 , 5 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static void F_102 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
if ( ! V_4 -> V_170 . V_171 || ! V_119 -> V_172 )
return;
V_119 -> V_172 = ! F_91 ( V_4 , 1 ) ;
F_78 ( V_4 ) ;
}
static void F_103 ( struct V_3 * V_4 )
{
union V_245 * V_246 = & V_4 -> V_247 ;
F_77 ( ! F_104 ( & V_4 -> V_248 ) ) ;
F_4 ( V_4 , & V_246 -> V_249 [ 0 ] , V_250 ) ;
F_4 ( V_4 , & V_246 -> V_249 [ 1 ] , V_251 ) ;
}
static void F_105 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_5 , V_252 ;
int V_164 ;
if ( F_79 ( V_4 ) < V_169 ) {
F_43 ( V_5 , V_253 , 1 ) ;
F_4 ( V_4 , & V_5 , V_198 ) ;
for ( V_164 = 0 ; V_164 < 10000 ; V_164 ++ ) {
F_2 ( V_4 , & V_5 , V_198 ) ;
if ( F_7 ( V_5 , V_253 ) ==
0 )
return;
F_38 ( 10 ) ;
}
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_15 ) ;
}
F_77 ( V_119 -> V_165 == 0 ) ;
F_2 ( V_4 , & V_252 , V_254 ) ;
F_3 ( V_252 , V_255 , 1 ) ;
F_4 ( V_4 , & V_252 , V_254 ) ;
F_2 ( V_4 , & V_5 , V_256 ) ;
F_3 ( V_5 , V_257 , 1 ) ;
F_3 ( V_5 , V_258 , 1 ) ;
F_3 ( V_5 , V_259 , 1 ) ;
F_4 ( V_4 , & V_5 , V_256 ) ;
V_164 = 0 ;
while ( 1 ) {
F_2 ( V_4 , & V_5 , V_256 ) ;
if ( ! F_7 ( V_5 , V_257 ) &&
! F_7 ( V_5 , V_258 ) &&
! F_7 ( V_5 , V_259 ) ) {
F_96 ( V_4 , V_52 , V_4 -> V_32 ,
L_16 ,
V_164 ) ;
break;
}
if ( V_164 > 20 ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 , L_17 ) ;
break;
}
V_164 ++ ;
F_38 ( 10 ) ;
}
F_4 ( V_4 , & V_252 , V_254 ) ;
F_74 ( V_4 ) ;
}
static void F_106 ( struct V_3 * V_4 )
{
T_1 V_5 ;
if ( ( F_79 ( V_4 ) < V_169 ) ||
( V_4 -> V_184 != V_260 ) )
return;
F_2 ( V_4 , & V_5 , V_254 ) ;
if ( F_7 ( V_5 , V_255 ) )
return;
F_105 ( V_4 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
T_1 V_5 ;
if ( F_79 ( V_4 ) < V_169 )
return;
F_2 ( V_4 , & V_5 , V_261 ) ;
F_3 ( V_5 , V_262 , 0 ) ;
F_4 ( V_4 , & V_5 , V_261 ) ;
F_106 ( V_4 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
struct V_263 * V_170 = & V_4 -> V_170 ;
T_1 V_5 ;
int V_264 , V_265 ;
V_265 = ! ! F_27 ( V_4 -> V_266 ) ;
switch ( V_170 -> V_267 ) {
case 10000 : V_264 = 3 ; break;
case 1000 : V_264 = 2 ; break;
case 100 : V_264 = 1 ; break;
default: V_264 = 0 ; break;
}
F_87 ( V_5 ,
V_268 , 0xffff ,
V_269 , 1 ,
V_270 , ! V_4 -> V_210 ,
V_271 , 1 ,
V_272 , V_264 ) ;
if ( F_79 ( V_4 ) >= V_169 ) {
F_3 ( V_5 , V_255 ,
! V_170 -> V_171 || V_265 ) ;
}
F_4 ( V_4 , & V_5 , V_254 ) ;
F_103 ( V_4 ) ;
F_2 ( V_4 , & V_5 , V_261 ) ;
F_3 ( V_5 , V_273 , 1 ) ;
if ( F_79 ( V_4 ) >= V_169 )
F_3 ( V_5 , V_262 , ! V_265 ) ;
F_4 ( V_4 , & V_5 , V_261 ) ;
}
static void F_107 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_5 ;
F_77 ( V_119 -> V_274 ) ;
F_77 ( V_119 -> V_165 ) ;
F_108 ( V_4 ) = 0 ;
V_119 -> V_274 = true ;
F_30 () ;
F_89 ( V_5 ,
V_275 , 1 ,
V_276 ,
V_4 -> V_277 . V_278 ) ;
F_4 ( V_4 , & V_5 , V_279 ) ;
F_109 ( & V_119 -> V_280 , F_110 ( V_49 + V_50 / 2 ) ) ;
}
static void F_111 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
if ( ! V_119 -> V_274 )
return;
V_119 -> V_274 = false ;
if ( F_108 ( V_4 ) ) {
F_112 () ;
F_113 ( V_281 , V_282 ,
V_283 , V_119 -> V_284 ,
V_4 -> V_277 . V_28 , true ) ;
} else {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_18 ) ;
}
}
static void F_114 ( unsigned long V_285 )
{
struct V_3 * V_4 = (struct V_3 * ) V_285 ;
struct V_118 * V_119 = V_4 -> V_119 ;
F_115 ( & V_4 -> V_286 ) ;
F_111 ( V_4 ) ;
if ( V_119 -> V_165 == 0 )
F_107 ( V_4 ) ;
F_116 ( & V_4 -> V_286 ) ;
}
static bool F_117 ( struct V_3 * V_4 )
{
struct V_263 V_287 = V_4 -> V_170 ;
F_77 ( ! F_104 ( & V_4 -> V_248 ) ) ;
F_77 ( ! F_80 ( V_4 ) ) ;
V_4 -> V_170 . V_288 = true ;
V_4 -> V_170 . V_191 = V_4 -> V_289 ;
V_4 -> V_170 . V_171 = true ;
V_4 -> V_170 . V_267 = 10000 ;
return ! F_118 ( & V_4 -> V_170 , & V_287 ) ;
}
static int F_119 ( struct V_3 * V_4 )
{
int V_63 ;
F_77 ( F_79 ( V_4 ) > V_169 ) ;
if ( F_80 ( V_4 ) )
F_117 ( V_4 ) ;
else
V_4 -> V_290 -> V_291 ( V_4 ) ;
F_95 ( V_4 ) ;
F_14 ( V_4 ) ;
F_105 ( V_4 ) ;
V_4 -> V_290 -> V_292 ( V_4 ) ;
V_63 = F_99 ( V_4 ) ;
F_120 ( V_63 ) ;
F_97 ( V_4 ) ;
F_121 ( V_4 ) ;
return 0 ;
}
static void F_122 ( struct V_3 * V_4 )
{
F_123 ( V_4 , V_293 ) ;
}
static void F_124 ( struct V_3 * V_4 )
{
F_95 ( V_4 ) ;
F_106 ( V_4 ) ;
F_99 ( V_4 ) ;
F_97 ( V_4 ) ;
}
static int F_125 ( struct V_3 * V_4 )
{
T_1 V_294 ;
int V_164 ;
for ( V_164 = 0 ; V_164 < 5000 ; V_164 ++ ) {
F_2 ( V_4 , & V_294 , V_295 ) ;
if ( F_7 ( V_294 , V_296 ) == 0 ) {
if ( F_7 ( V_294 , V_297 ) != 0 ||
F_7 ( V_294 , V_298 ) != 0 ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_19
V_35 L_3 ,
F_25 ( V_294 ) ) ;
return - V_93 ;
}
return 0 ;
}
F_38 ( 10 ) ;
}
F_40 ( V_4 , V_52 , V_4 -> V_32 , L_20 ) ;
return - V_53 ;
}
static int F_126 ( struct V_299 * V_32 ,
int V_300 , int V_301 , T_7 V_28 , T_7 V_302 )
{
struct V_3 * V_4 = F_127 ( V_32 ) ;
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_5 ;
int V_63 ;
F_23 ( V_4 , V_52 , V_4 -> V_32 ,
L_21 ,
V_300 , V_301 , V_28 , V_302 ) ;
F_67 ( & V_119 -> V_303 ) ;
V_63 = F_125 ( V_4 ) ;
if ( V_63 )
goto V_59;
F_43 ( V_5 , V_304 , V_28 ) ;
F_4 ( V_4 , & V_5 , V_305 ) ;
F_89 ( V_5 , V_306 , V_300 ,
V_307 , V_301 ) ;
F_4 ( V_4 , & V_5 , V_308 ) ;
F_43 ( V_5 , V_309 , V_302 ) ;
F_4 ( V_4 , & V_5 , V_310 ) ;
F_89 ( V_5 ,
V_311 , 1 ,
V_312 , 0 ) ;
F_4 ( V_4 , & V_5 , V_313 ) ;
V_63 = F_125 ( V_4 ) ;
if ( V_63 ) {
F_89 ( V_5 ,
V_311 , 0 ,
V_312 , 1 ) ;
F_4 ( V_4 , & V_5 , V_313 ) ;
F_38 ( 10 ) ;
}
V_59:
F_63 ( & V_119 -> V_303 ) ;
return V_63 ;
}
static int F_128 ( struct V_299 * V_32 ,
int V_300 , int V_301 , T_7 V_28 )
{
struct V_3 * V_4 = F_127 ( V_32 ) ;
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_5 ;
int V_63 ;
F_67 ( & V_119 -> V_303 ) ;
V_63 = F_125 ( V_4 ) ;
if ( V_63 )
goto V_59;
F_43 ( V_5 , V_304 , V_28 ) ;
F_4 ( V_4 , & V_5 , V_305 ) ;
F_89 ( V_5 , V_306 , V_300 ,
V_307 , V_301 ) ;
F_4 ( V_4 , & V_5 , V_308 ) ;
F_89 ( V_5 , V_314 , 1 , V_312 , 0 ) ;
F_4 ( V_4 , & V_5 , V_313 ) ;
V_63 = F_125 ( V_4 ) ;
if ( V_63 == 0 ) {
F_2 ( V_4 , & V_5 , V_315 ) ;
V_63 = F_7 ( V_5 , V_316 ) ;
F_23 ( V_4 , V_52 , V_4 -> V_32 ,
L_22 ,
V_300 , V_301 , V_28 , V_63 ) ;
} else {
F_89 ( V_5 ,
V_317 , 0 ,
V_312 , 1 ) ;
F_4 ( V_4 , & V_5 , V_313 ) ;
F_96 ( V_4 , V_52 , V_4 -> V_32 ,
L_23 ,
V_300 , V_301 , V_28 , V_63 ) ;
}
V_59:
F_63 ( & V_119 -> V_303 ) ;
return V_63 ;
}
static int F_129 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
int V_63 ;
switch ( V_4 -> V_141 ) {
case V_318 :
V_4 -> V_290 = & V_319 ;
break;
case V_320 :
case V_321 :
V_4 -> V_290 = & V_322 ;
break;
case V_323 :
V_4 -> V_290 = & V_324 ;
break;
default:
F_40 ( V_4 , V_325 , V_4 -> V_32 , L_24 ,
V_4 -> V_141 ) ;
return - V_124 ;
}
F_130 ( & V_119 -> V_303 ) ;
V_4 -> V_186 . V_326 = F_128 ;
V_4 -> V_186 . V_327 = F_126 ;
V_63 = V_4 -> V_290 -> V_325 ( V_4 ) ;
if ( V_63 != 0 )
return V_63 ;
V_4 -> V_170 . V_267 = 10000 ;
V_4 -> V_170 . V_288 = true ;
if ( F_79 ( V_4 ) >= V_169 )
V_4 -> V_289 = V_192 | V_194 ;
else
V_4 -> V_289 = V_192 ;
if ( V_4 -> V_186 . V_187 & V_328 )
V_4 -> V_289 |= V_329 ;
V_63 = F_131 ( V_4 , & V_4 -> V_277 ,
V_330 , V_125 ) ;
if ( V_63 )
return V_63 ;
F_96 ( V_4 , V_325 , V_4 -> V_32 ,
L_25 ,
( V_331 ) V_4 -> V_277 . V_278 ,
V_4 -> V_277 . V_28 ,
( V_331 ) F_132 ( V_4 -> V_277 . V_28 ) ) ;
return 0 ;
}
static void F_133 ( struct V_3 * V_4 )
{
V_4 -> V_290 -> remove ( V_4 ) ;
F_134 ( V_4 , & V_4 -> V_277 ) ;
}
static bool
F_135 ( struct V_11 * V_12 , T_8 * V_332 )
{
struct V_3 * V_4 = V_12 -> V_4 ;
struct V_118 * V_119 = V_4 -> V_119 ;
if ( F_136 ( * V_332 , V_333 ) ||
F_136 ( * V_332 , V_334 ) ||
F_136 ( * V_332 , V_335 ) )
return true ;
if ( ( F_79 ( V_4 ) == V_169 ) &&
F_136 ( * V_332 , V_336 ) ) {
V_119 -> V_172 = true ;
return true ;
}
if ( F_79 ( V_4 ) <= V_337 ?
F_136 ( * V_332 , V_338 ) :
F_136 ( * V_332 , V_339 ) ) {
F_40 ( V_4 , V_340 , V_4 -> V_32 ,
L_26 ,
V_12 -> V_12 ) ;
F_137 ( & V_4 -> V_341 ) ;
F_123 ( V_4 , F_138 ( V_4 ) ?
V_342 : V_343 ) ;
return true ;
}
return false ;
}
static int
F_139 ( struct V_3 * V_4 , struct V_344 * V_345 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
struct V_344 * V_346 ;
struct V_54 * V_55 ;
void * V_347 ;
int V_63 , V_348 , V_349 ;
T_9 * V_350 , * V_351 ;
T_10 V_352 ;
if ( F_71 ( & V_119 -> V_127 ) )
V_55 = & V_119 -> V_127 ;
else if ( F_71 ( & V_119 -> V_134 ) )
V_55 = & V_119 -> V_134 ;
else
return - V_65 ;
V_347 = F_140 ( V_353 , V_125 ) ;
if ( ! V_347 )
return - V_126 ;
V_346 = V_347 + V_354 ;
F_67 ( & V_119 -> V_120 ) ;
V_63 = F_46 ( V_4 , V_55 , 0 , V_353 , NULL , V_347 ) ;
F_63 ( & V_119 -> V_120 ) ;
if ( V_63 ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 , L_27 ,
F_71 ( & V_119 -> V_127 ) ?
L_9 : L_11 ) ;
V_63 = - V_93 ;
goto V_59;
}
V_348 = F_141 ( V_346 -> V_355 ) ;
V_349 = F_141 ( V_346 -> V_356 ) ;
V_63 = - V_65 ;
if ( V_348 != V_357 ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_28 , V_348 ) ;
goto V_59;
}
if ( V_349 < 2 ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_29 , V_349 ) ;
goto V_59;
} else if ( V_349 < 4 ) {
V_350 = & V_346 -> V_355 ;
V_351 = ( T_9 * ) ( V_346 + 1 ) ;
} else {
V_350 = V_347 ;
V_351 = V_347 + V_353 ;
}
for ( V_352 = 0 ; V_350 < V_351 ; ++ V_350 )
V_352 += F_141 ( * V_350 ) ;
if ( ~ V_352 & 0xffff ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_30 ) ;
goto V_59;
}
V_63 = 0 ;
if ( V_345 )
memcpy ( V_345 , V_346 , sizeof( * V_346 ) ) ;
V_59:
F_73 ( V_347 ) ;
return V_63 ;
}
static int F_142 ( struct V_3 * V_4 )
{
return F_139 ( V_4 , NULL ) ;
}
static int
F_143 ( struct V_3 * V_4 , struct V_358 * V_359 )
{
enum V_360 V_361 = V_293 ;
int V_63 , V_362 ;
F_67 ( & V_4 -> V_248 ) ;
if ( V_4 -> V_363 ) {
if ( V_4 -> V_363 & ( 1 << V_185 ) )
V_4 -> V_184 = V_185 ;
else
V_4 -> V_184 = F_144 ( V_4 -> V_363 ) ;
}
F_145 ( V_4 ) ;
F_63 ( & V_4 -> V_248 ) ;
F_146 ( V_4 , V_361 ) ;
V_359 -> V_364 =
F_147 ( V_4 , V_365 ,
F_148 ( V_365 ) )
? - 1 : 1 ;
V_63 = F_149 ( V_4 , V_361 ) ;
V_362 = F_150 ( V_4 , V_361 , V_63 == 0 ) ;
return V_63 ? V_63 : V_362 ;
}
static enum V_360 F_151 ( enum V_360 V_366 )
{
switch ( V_366 ) {
case V_342 :
case V_367 :
case V_368 :
return V_293 ;
default:
return V_369 ;
}
}
static int F_152 ( T_10 * V_131 )
{
enum {
V_370 = ( V_371 | V_372 |
V_373 | V_374 ) ,
V_375 = V_370 | V_376 ,
V_377 = V_375 | V_378 ,
};
if ( ( * V_131 & V_377 ) == V_377 ) {
* V_131 &= ~ V_377 ;
return V_379 ;
}
if ( ( * V_131 & V_375 ) == V_375 ) {
* V_131 &= ~ V_375 ;
return V_369 ;
}
if ( ( * V_131 & V_370 ) == V_370 ) {
* V_131 &= ~ V_370 ;
return V_293 ;
}
return - V_65 ;
}
static int F_153 ( struct V_3 * V_4 , enum V_360 V_380 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_381 ;
int V_63 ;
F_96 ( V_4 , V_52 , V_4 -> V_32 , L_31 ,
F_154 ( V_380 ) ) ;
if ( V_380 == V_379 ) {
V_63 = F_155 ( V_4 -> V_382 ) ;
if ( V_63 ) {
F_40 ( V_4 , V_383 , V_4 -> V_32 ,
L_32
L_33 ) ;
goto V_384;
}
if ( F_156 ( V_4 ) ) {
V_63 = F_155 ( V_119 -> V_385 ) ;
if ( V_63 ) {
F_40 ( V_4 , V_383 , V_4 -> V_32 ,
L_34
L_35
L_36 ) ;
goto V_386;
}
}
F_89 ( V_381 ,
V_387 ,
V_388 ,
V_389 , 1 ) ;
} else {
F_44 ( V_381 ,
V_390 ,
V_380 == V_293 ,
V_391 , 1 ,
V_392 , 1 ,
V_393 , 1 ,
V_394 , 1 ,
V_387 ,
V_388 ,
V_389 , 1 ) ;
}
F_4 ( V_4 , & V_381 , V_256 ) ;
F_96 ( V_4 , V_52 , V_4 -> V_32 , L_37 ) ;
F_41 ( V_50 / 20 ) ;
if ( V_380 == V_379 ) {
if ( F_156 ( V_4 ) )
F_157 ( V_119 -> V_385 ) ;
F_157 ( V_4 -> V_382 ) ;
F_96 ( V_4 , V_383 , V_4 -> V_32 ,
L_38 ) ;
}
F_2 ( V_4 , & V_381 , V_256 ) ;
if ( F_7 ( V_381 , V_389 ) != 0 ) {
V_63 = - V_53 ;
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_39 ) ;
goto V_395;
}
F_96 ( V_4 , V_52 , V_4 -> V_32 , L_40 ) ;
return 0 ;
V_386:
F_157 ( V_4 -> V_382 ) ;
V_384:
V_395:
return V_63 ;
}
static int F_149 ( struct V_3 * V_4 , enum V_360 V_380 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
int V_63 ;
F_67 ( & V_119 -> V_120 ) ;
V_63 = F_153 ( V_4 , V_380 ) ;
F_63 ( & V_119 -> V_120 ) ;
return V_63 ;
}
static void F_158 ( struct V_3 * V_4 )
{
bool V_396 ;
int V_63 ;
F_120 ( ! F_104 ( & V_4 -> V_248 ) ) ;
V_63 = F_159 ( V_4 ) -> type -> V_397 ( V_4 ) ;
if ( V_63 ) {
F_40 ( V_4 , V_52 , V_4 -> V_32 ,
L_41 ,
( V_63 == - V_398 ) ? L_42 : L_43 ) ;
V_4 -> V_244 |= V_399 ;
V_63 = F_145 ( V_4 ) ;
F_77 ( V_63 ) ;
}
if ( F_80 ( V_4 ) )
V_396 = F_117 ( V_4 ) ;
else
V_396 = V_4 -> V_290 -> V_291 ( V_4 ) ;
if ( V_396 ) {
F_95 ( V_4 ) ;
F_14 ( V_4 ) ;
F_105 ( V_4 ) ;
V_63 = F_99 ( V_4 ) ;
F_120 ( V_63 ) ;
F_97 ( V_4 ) ;
F_121 ( V_4 ) ;
}
F_102 ( V_4 ) ;
}
static int F_160 ( struct V_3 * V_4 )
{
T_1 V_400 , V_401 ;
int V_164 ;
F_2 ( V_4 , & V_401 , V_6 ) ;
F_3 ( V_401 , V_402 , 1 ) ;
F_3 ( V_401 , V_403 , 1 ) ;
F_4 ( V_4 , & V_401 , V_6 ) ;
F_89 ( V_400 ,
V_404 , 1 ,
V_405 , 0 ) ;
F_4 ( V_4 , & V_400 , V_406 ) ;
V_164 = 0 ;
do {
F_96 ( V_4 , V_52 , V_4 -> V_32 ,
L_44 , V_164 ) ;
F_41 ( V_50 / 50 ) ;
F_2 ( V_4 , & V_400 , V_406 ) ;
if ( ! F_7 ( V_400 , V_404 ) ) {
F_96 ( V_4 , V_52 , V_4 -> V_32 ,
L_45 ) ;
return 0 ;
}
} while ( ++ V_164 < 20 );
F_40 ( V_4 , V_52 , V_4 -> V_32 , L_46 ) ;
return - V_53 ;
}
static void F_161 ( struct V_3 * V_4 ,
struct V_54 * V_407 ,
unsigned int V_70 , T_10 V_408 )
{
if ( V_408 != 0 ) {
V_407 -> V_70 = V_70 ;
V_407 -> V_128 =
1 << F_162 ( V_408 , V_409 ) ;
V_407 -> V_75 =
F_162 ( V_408 , V_410 ) ;
V_407 -> V_77 = ( V_407 -> V_128 == 1 << 9 &&
V_407 -> V_75 == 1 ) ;
V_407 -> V_113 =
F_162 ( V_408 , V_411 ) ;
V_407 -> V_112 =
1 << F_162 ( V_408 ,
V_412 ) ;
V_407 -> V_86 =
1 << F_162 ( V_408 ,
V_413 ) ;
} else {
V_407 -> V_128 = 0 ;
}
}
static int F_163 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
struct V_344 * V_346 ;
int V_63 ;
V_346 = F_140 ( sizeof( * V_346 ) , V_125 ) ;
if ( ! V_346 )
return - V_126 ;
V_63 = F_139 ( V_4 , V_346 ) ;
if ( V_63 )
goto V_59;
V_4 -> V_141 = V_346 -> V_414 . V_415 ;
V_4 -> V_186 . V_300 = V_346 -> V_414 . V_416 ;
if ( F_141 ( V_346 -> V_356 ) >= 3 ) {
F_161 (
V_4 , & V_119 -> V_127 , V_417 ,
F_164 ( V_346 -> V_418
. V_419 [ V_417 ] ) ) ;
F_161 (
V_4 , & V_119 -> V_134 , V_420 ,
F_164 ( V_346 -> V_418
. V_419 [ V_420 ] ) ) ;
}
F_165 ( V_4 -> V_32 -> V_421 , V_346 -> V_422 [ 0 ] ) ;
F_96 ( V_4 , V_325 , V_4 -> V_32 , L_47 ,
V_4 -> V_141 , V_4 -> V_186 . V_300 ) ;
V_63 = F_166 ( V_4 ,
F_141 ( V_346 -> V_414 . V_423 ) ) ;
V_59:
F_73 ( V_346 ) ;
return V_63 ;
}
static int F_167 ( struct V_3 * V_4 )
{
V_4 -> V_424 = 0x20000 ;
V_4 -> V_425 = 0x26000 ;
return 0 ;
}
static void F_168 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
T_1 V_426 , V_427 , V_428 ;
int V_429 ;
F_2 ( V_4 , & V_427 , V_6 ) ;
F_2 ( V_4 , & V_426 , V_430 ) ;
F_2 ( V_4 , & V_428 , V_431 ) ;
if ( F_7 ( V_427 , V_432 ) ) {
V_429 = ( F_7 ( V_426 , V_433 ) ?
V_417 : V_420 ) ;
F_96 ( V_4 , V_325 , V_4 -> V_32 , L_48 ,
V_429 == V_417 ?
L_9 : L_11 ) ;
} else {
V_429 = - 1 ;
F_96 ( V_4 , V_325 , V_4 -> V_32 ,
L_49
L_50 ) ;
F_85 ( V_428 , V_434 , 0 ,
V_435 , 7 ,
V_436 , 63 ) ;
F_4 ( V_4 , & V_428 , V_431 ) ;
}
F_130 ( & V_119 -> V_120 ) ;
if ( V_429 == V_417 )
F_161 ( V_4 , & V_119 -> V_127 ,
V_417 ,
V_437 ) ;
if ( V_429 == V_420 )
F_161 ( V_4 , & V_119 -> V_134 ,
V_420 ,
V_438 ) ;
}
static unsigned int F_169 ( struct V_3 * V_4 )
{
return 0x20000 ;
}
static unsigned int F_170 ( struct V_3 * V_4 )
{
return V_439 +
V_440 * V_441 ;
}
static int F_171 ( struct V_3 * V_4 )
{
struct V_118 * V_119 ;
struct F_159 * V_442 ;
int V_63 ;
V_4 -> V_443 = V_4 ;
V_119 = F_172 ( sizeof( * V_119 ) , V_125 ) ;
if ( ! V_119 )
return - V_126 ;
V_4 -> V_119 = V_119 ;
V_63 = - V_124 ;
if ( F_173 ( V_4 ) != 0 ) {
F_40 ( V_4 , V_325 , V_4 -> V_32 ,
L_51 ) ;
goto V_384;
}
if ( F_79 ( V_4 ) <= V_337 ) {
T_1 V_426 ;
struct V_382 * V_444 ;
T_5 V_445 = V_4 -> V_382 -> V_446 ;
if ( ( V_445 == 0xff ) || ( V_445 == 0 ) ) {
F_40 ( V_4 , V_325 , V_4 -> V_32 ,
L_52 ) ;
goto V_384;
}
F_2 ( V_4 , & V_426 , V_430 ) ;
if ( F_7 ( V_426 , V_447 ) == 0 ) {
F_40 ( V_4 , V_325 , V_4 -> V_32 ,
L_53 ) ;
goto V_384;
}
if ( F_7 ( V_426 , V_448 ) == 0 ) {
F_40 ( V_4 , V_325 , V_4 -> V_32 ,
L_54 ) ;
goto V_384;
}
V_444 = F_174 ( V_4 -> V_382 ) ;
while ( ( V_444 = F_175 ( V_449 ,
V_450 ,
V_444 ) ) ) {
if ( V_444 -> V_451 == V_4 -> V_382 -> V_451 &&
V_444 -> V_452 == V_4 -> V_382 -> V_452 + 1 ) {
V_119 -> V_385 = V_444 ;
break;
}
}
if ( ! V_119 -> V_385 ) {
F_40 ( V_4 , V_325 , V_4 -> V_32 ,
L_55 ) ;
V_63 = - V_124 ;
goto V_386;
}
}
V_63 = F_153 ( V_4 , V_369 ) ;
if ( V_63 ) {
F_40 ( V_4 , V_325 , V_4 -> V_32 , L_56 ) ;
goto V_395;
}
V_63 = F_131 ( V_4 , & V_4 -> V_27 , sizeof( T_1 ) ,
V_125 ) ;
if ( V_63 )
goto V_453;
F_120 ( V_4 -> V_27 . V_278 & 0x0f ) ;
F_96 ( V_4 , V_325 , V_4 -> V_32 ,
L_57 ,
( V_331 ) V_4 -> V_27 . V_278 ,
V_4 -> V_27 . V_28 ,
( V_331 ) F_132 ( V_4 -> V_27 . V_28 ) ) ;
F_168 ( V_4 ) ;
V_63 = F_163 ( V_4 ) ;
if ( V_63 ) {
if ( V_63 == - V_65 )
F_40 ( V_4 , V_325 , V_4 -> V_32 , L_58 ) ;
goto V_454;
}
V_4 -> V_455 = ( F_79 ( V_4 ) <= V_337 ? 4 :
V_40 ) ;
V_4 -> V_456 = 4968 ;
V_442 = F_159 ( V_4 ) ;
V_442 -> V_457 . V_458 = V_459 ;
V_442 -> V_460 = V_461 ;
V_442 -> V_460 . V_1 = V_4 ;
V_442 -> V_457 . V_462 = & V_442 -> V_460 ;
V_442 -> V_457 . V_444 . V_463 = & V_4 -> V_382 -> V_444 ;
F_176 ( V_442 -> V_457 . V_102 , L_59 ,
sizeof( V_442 -> V_457 . V_102 ) ) ;
V_63 = F_177 ( & V_442 -> V_457 ) ;
if ( V_63 )
goto V_454;
V_63 = F_159 ( V_4 ) -> type -> V_464 ( V_4 ) ;
if ( V_63 ) {
F_40 ( V_4 , V_325 , V_4 -> V_32 ,
L_60 ) ;
goto V_465;
}
V_119 -> V_165 = 1 ;
F_178 ( & V_119 -> V_280 , & F_114 ,
( unsigned long ) V_4 ) ;
return 0 ;
V_465:
F_179 ( & V_442 -> V_457 ) ;
memset ( & V_442 -> V_457 , 0 , sizeof( V_442 -> V_457 ) ) ;
V_454:
F_134 ( V_4 , & V_4 -> V_27 ) ;
V_453:
V_395:
if ( V_119 -> V_385 ) {
F_180 ( V_119 -> V_385 ) ;
V_119 -> V_385 = NULL ;
}
V_386:
V_384:
F_73 ( V_4 -> V_119 ) ;
return V_63 ;
}
static void F_181 ( struct V_3 * V_4 )
{
const unsigned V_466 = 20 ;
const unsigned V_467 = 25 ;
T_1 V_5 ;
F_2 ( V_4 , & V_5 , V_261 ) ;
if ( F_79 ( V_4 ) <= V_337 ) {
F_3 ( V_5 , V_468 , 0 ) ;
F_3 ( V_5 , V_469 ,
( 3 * 4096 ) >> 5 ) ;
F_3 ( V_5 , V_470 , 512 >> 8 ) ;
F_3 ( V_5 , V_471 , 2048 >> 8 ) ;
F_3 ( V_5 , V_472 , V_466 ) ;
F_3 ( V_5 , V_473 , V_467 ) ;
} else {
F_3 ( V_5 , V_474 , 0 ) ;
F_3 ( V_5 , V_475 ,
V_476 >> 5 ) ;
F_3 ( V_5 , V_477 , 27648 >> 8 ) ;
F_3 ( V_5 , V_478 , 54272 >> 8 ) ;
F_3 ( V_5 , V_479 , V_466 ) ;
F_3 ( V_5 , V_480 , V_467 ) ;
F_3 ( V_5 , V_262 , 1 ) ;
F_3 ( V_5 , V_481 , 1 ) ;
F_3 ( V_5 , V_482 , 1 ) ;
F_3 ( V_5 , V_483 , 1 ) ;
}
F_3 ( V_5 , V_273 , 1 ) ;
F_4 ( V_4 , & V_5 , V_261 ) ;
}
static int F_182 ( struct V_3 * V_4 )
{
T_1 V_42 ;
int V_63 ;
F_2 ( V_4 , & V_42 , V_430 ) ;
F_3 ( V_42 , V_484 , 1 ) ;
F_4 ( V_4 , & V_42 , V_430 ) ;
V_63 = F_160 ( V_4 ) ;
if ( V_63 )
return V_63 ;
if ( F_183 ( V_4 ) ) {
F_2 ( V_4 , & V_42 , V_485 ) ;
F_3 ( V_42 , V_486 , 0 ) ;
F_4 ( V_4 , & V_42 , V_485 ) ;
}
if ( F_184 ( V_4 ) ) {
F_2 ( V_4 , & V_42 , V_487 ) ;
F_3 ( V_42 , V_488 , 8 ) ;
F_3 ( V_42 , V_489 , 8 ) ;
F_3 ( V_42 , V_490 , 8 ) ;
F_3 ( V_42 , V_491 , 8 ) ;
F_4 ( V_4 , & V_42 , V_487 ) ;
}
F_2 ( V_4 , & V_42 , V_492 ) ;
F_3 ( V_42 , V_493 , 1 ) ;
F_3 ( V_42 , V_494 , 1 ) ;
if ( F_185 ( V_4 ) )
F_3 ( V_42 , V_495 , 1 ) ;
F_4 ( V_4 , & V_42 , V_492 ) ;
F_2 ( V_4 , & V_42 , V_496 ) ;
F_3 ( V_42 , V_497 , 0 ) ;
F_4 ( V_4 , & V_42 , V_496 ) ;
F_181 ( V_4 ) ;
if ( F_79 ( V_4 ) >= V_169 ) {
F_33 ( V_4 ) ;
F_43 ( V_42 , V_498 , 0 ) ;
F_4 ( V_4 , & V_42 , V_499 ) ;
}
F_186 ( V_4 ) ;
return 0 ;
}
static void F_187 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
struct F_159 * V_442 = F_159 ( V_4 ) ;
V_442 -> type -> V_500 ( V_4 ) ;
F_179 ( & V_442 -> V_457 ) ;
memset ( & V_442 -> V_457 , 0 , sizeof( V_442 -> V_457 ) ) ;
F_134 ( V_4 , & V_4 -> V_27 ) ;
F_153 ( V_4 , V_369 ) ;
if ( V_119 -> V_385 ) {
F_180 ( V_119 -> V_385 ) ;
V_119 -> V_385 = NULL ;
}
F_73 ( V_4 -> V_119 ) ;
V_4 -> V_119 = NULL ;
}
static T_4 F_188 ( struct V_3 * V_4 , T_5 * V_501 )
{
return F_189 ( V_281 , V_282 ,
V_283 , V_501 ) ;
}
static T_4 F_190 ( struct V_3 * V_4 , V_331 * V_502 ,
struct V_503 * V_504 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
V_331 * V_284 = V_119 -> V_284 ;
T_1 V_505 ;
if ( ! V_119 -> V_165 ) {
F_2 ( V_4 , & V_505 , V_506 ) ;
V_284 [ V_507 ] +=
F_7 ( V_505 , V_508 ) ;
if ( V_119 -> V_274 &&
F_108 ( V_4 ) ) {
V_119 -> V_274 = false ;
F_112 () ;
F_113 (
V_281 , V_282 ,
V_283 ,
V_284 , V_4 -> V_277 . V_28 , true ) ;
}
F_191 ( & V_284 [ V_509 ] ,
V_284 [ V_510 ] -
V_284 [ V_511 ] -
V_284 [ V_512 ] * 64 ) ;
}
if ( V_502 )
memcpy ( V_502 , V_284 , sizeof( V_331 ) * V_282 ) ;
if ( V_504 ) {
V_504 -> V_513 = V_284 [ V_514 ] ;
V_504 -> V_515 = V_284 [ V_516 ] ;
V_504 -> V_517 = V_284 [ V_510 ] ;
V_504 -> V_518 = V_284 [ V_519 ] ;
V_504 -> V_520 = V_284 [ V_507 ] ;
V_504 -> V_521 = V_284 [ V_522 ] ;
V_504 -> V_523 =
V_284 [ V_524 ] +
V_284 [ V_525 ] ;
V_504 -> V_526 = V_284 [ V_527 ] ;
V_504 -> V_528 = V_284 [ V_529 ] ;
V_504 -> V_530 = V_284 [ V_531 ] ;
V_504 -> V_532 = ( V_504 -> V_523 +
V_504 -> V_526 +
V_504 -> V_528 +
V_284 [ V_533 ] ) ;
}
return V_282 ;
}
void F_97 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
F_192 ( & V_4 -> V_286 ) ;
if ( -- V_119 -> V_165 == 0 )
F_107 ( V_4 ) ;
F_193 ( & V_4 -> V_286 ) ;
}
static void F_194 ( struct V_3 * V_4 )
{
F_15 ( 10 ) ;
}
void F_95 ( struct V_3 * V_4 )
{
struct V_118 * V_119 = V_4 -> V_119 ;
int V_51 ;
F_195 () ;
F_192 ( & V_4 -> V_286 ) ;
++ V_119 -> V_165 ;
F_193 ( & V_4 -> V_286 ) ;
F_196 ( & V_119 -> V_280 ) ;
for ( V_51 = 0 ; V_51 < 4 && V_119 -> V_274 ; V_51 ++ ) {
if ( F_108 ( V_4 ) )
break;
F_15 ( 1 ) ;
}
F_192 ( & V_4 -> V_286 ) ;
F_111 ( V_4 ) ;
F_193 ( & V_4 -> V_286 ) ;
}
static void F_197 ( struct V_3 * V_4 , enum V_534 V_535 )
{
F_159 ( V_4 ) -> type -> V_536 ( V_4 , V_535 ) ;
}
static void F_198 ( struct V_3 * V_4 , struct V_537 * V_538 )
{
V_538 -> V_539 = 0 ;
V_538 -> V_540 = 0 ;
memset ( & V_538 -> V_541 , 0 , sizeof( V_538 -> V_541 ) ) ;
}
static int F_199 ( struct V_3 * V_4 , T_10 type )
{
if ( type != 0 )
return - V_65 ;
return 0 ;
}
