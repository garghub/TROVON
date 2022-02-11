static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
V_4 = V_3 -> V_6 ;
if ( V_4 && V_4 -> V_7 == 0 )
V_4 = NULL ;
if ( V_4 )
V_4 -> V_7 ++ ;
F_3 ( & V_5 ) ;
return V_4 ;
}
static inline int F_4 ( struct V_2 * V_3 )
{
int V_8 = F_5 ( F_6 ( V_3 ) ) ;
int V_9 = F_7 ( F_6 ( V_3 ) ) / V_10 ;
if ( ! V_8 )
V_9 = V_3 -> V_11 / V_10 ;
return V_9 ;
}
static void F_8 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
V_4 -> V_7 -- ;
if ( V_4 -> V_7 == 0 ) {
int V_9 = F_4 ( V_4 -> V_3 ) ;
F_9 ( V_4 -> V_12 . V_12 ) ;
F_10 ( V_9 , V_13 ) ;
F_11 ( V_4 -> V_3 ) ;
F_12 ( V_4 ) ;
}
F_3 ( & V_5 ) ;
}
static T_1 F_13 ( struct V_14 * V_15 , struct V_16 * V_17 ,
char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
V_19 = snprintf ( V_18 , V_20 , L_1 ,
F_15 ( F_14 ( V_15 ) ) ^
V_4 -> V_21 ) ;
F_8 ( V_4 ) ;
return V_19 ;
}
static T_1 F_16 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const char * V_18 , T_2 V_22 )
{
int V_19 ;
char * V_23 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
unsigned long V_24 = F_17 ( V_18 , & V_23 , 0 ) ;
if ( V_23 == V_18 ) {
V_19 = - V_25 ;
goto V_26;
}
F_18 ( F_14 ( V_15 ) , V_24 || V_4 -> V_21 ) ;
V_19 = V_22 ;
V_26:
F_8 ( V_4 ) ;
return V_19 ;
}
static int F_19 ( struct V_27 * V_28 , T_3 V_29 )
{
struct V_1 * V_4 = F_1 ( V_28 -> V_30 ) ;
int V_19 = - V_31 ;
F_2 ( & V_32 ) ;
if ( V_4 ) {
if ( V_4 -> V_7 == 2 )
F_20 ( V_28 ) ;
V_19 = 0 ;
if ( ( V_29 & V_33 ) && V_4 -> V_21 ) {
F_8 ( V_4 ) ;
V_19 = - V_34 ;
}
}
F_3 ( & V_32 ) ;
return V_19 ;
}
static int F_21 ( struct V_2 * V_3 , T_3 V_29 )
{
struct V_1 * V_4 = V_3 -> V_6 ;
F_2 ( & V_32 ) ;
F_8 ( V_4 ) ;
F_3 ( & V_32 ) ;
return 0 ;
}
static int
F_22 ( struct V_27 * V_28 , struct V_35 * V_36 )
{
V_36 -> V_37 = F_23 ( V_28 -> V_30 ) / ( 4 * 16 ) ;
V_36 -> V_38 = 4 ;
V_36 -> V_39 = 16 ;
return 0 ;
}
static struct V_40 * F_24 (
struct V_41 T_4 * V_42 )
{
struct V_40 * V_43 ;
int V_44 ;
V_43 = F_25 ( sizeof( * V_43 ) , V_45 ) ;
if ( ! V_43 ) {
V_44 = - V_46 ;
goto V_26;
}
if ( F_26 ( & V_43 -> V_47 , V_42 , sizeof( V_43 -> V_47 ) ) ) {
V_44 = - V_48 ;
goto V_49;
}
V_43 -> V_50 = ( V_51 ) V_43 -> V_47 . V_52 * V_43 -> V_47 . V_53 ;
if ( V_43 -> V_50 > V_54 ) {
V_44 = - V_55 ;
goto V_49;
}
V_43 -> V_18 = F_25 ( V_43 -> V_50 , V_45 ) ;
if ( ! V_43 -> V_18 ) {
V_44 = - V_46 ;
goto V_49;
}
if ( F_26 ( V_43 -> V_18 , ( void T_4 * ) ( unsigned long )
V_43 -> V_47 . V_56 , V_43 -> V_50 ) ) {
V_44 = - V_48 ;
goto V_57;
}
return V_43 ;
V_57:
F_12 ( V_43 -> V_18 ) ;
V_49:
F_12 ( V_43 ) ;
V_26:
return F_27 ( V_44 ) ;
}
static int F_28 ( struct V_27 * V_28 ,
struct V_41 T_4 * V_58 )
{
struct V_40 * V_43 ;
struct V_1 * V_4 ;
struct V_59 * V_60 ;
struct V_61 V_62 = { 0 } ;
struct V_63 V_64 = { 0 } ;
struct V_65 V_66 = { 0 } ;
struct V_67 V_68 ;
int V_44 ;
if ( ( ! F_29 ( V_69 ) ) || ( V_28 != V_28 -> V_70 ) )
return - V_71 ;
V_43 = F_24 ( V_58 ) ;
if ( F_30 ( V_43 ) )
return F_31 ( V_43 ) ;
V_62 . V_72 = V_43 -> V_47 . V_72 ;
V_62 . V_73 = V_43 -> V_47 . V_73 ;
V_62 . V_74 = V_43 -> V_47 . V_74 ;
V_64 . V_68 = & V_68 ;
V_64 . V_75 = 1 ;
V_64 . V_52 = V_43 -> V_47 . V_52 ;
V_64 . V_53 = V_43 -> V_47 . V_53 ;
F_32 ( V_64 . V_68 , V_43 -> V_18 , V_43 -> V_50 ) ;
if ( V_43 -> V_47 . V_76 )
V_64 . V_74 = V_77 ;
else
V_64 . V_74 = V_78 ;
V_66 . V_62 = & V_62 ;
V_66 . V_64 = & V_64 ;
V_4 = F_1 ( V_28 -> V_30 ) ;
if ( ! V_4 ) {
V_44 = - V_25 ;
goto V_79;
}
V_60 = V_4 -> V_12 . V_60 ;
if ( F_30 ( V_60 ) ) {
V_44 = F_31 ( V_60 ) ;
goto V_79;
}
F_33 ( V_60 -> V_80 ) ;
if ( V_43 -> V_47 . V_81 ) {
V_44 = F_34 ( V_60 -> V_80 , V_60 ) ;
if ( V_44 )
goto V_82;
}
F_35 ( & V_64 , V_60 ) ;
if ( V_43 -> V_47 . V_83 )
V_64 . V_84 = V_43 -> V_47 . V_83 ;
if ( ( V_62 . V_74 & V_85 ) == V_85 ) {
V_64 . V_84 = V_43 -> V_47 . V_86 * 1000000 ;
}
F_36 ( V_60 -> V_80 , & V_66 ) ;
if ( V_62 . error ) {
F_37 ( F_38 ( V_60 -> V_80 ) , L_2 ,
V_87 , V_62 . error ) ;
V_44 = V_62 . error ;
goto V_82;
}
if ( V_64 . error ) {
F_37 ( F_38 ( V_60 -> V_80 ) , L_3 ,
V_87 , V_64 . error ) ;
V_44 = V_64 . error ;
goto V_82;
}
if ( V_43 -> V_47 . V_88 )
F_39 ( V_43 -> V_47 . V_88 , V_43 -> V_47 . V_89 ) ;
if ( F_40 ( & ( V_58 -> V_90 ) , V_62 . V_91 , sizeof( V_62 . V_91 ) ) ) {
V_44 = - V_48 ;
goto V_82;
}
if ( ! V_43 -> V_47 . V_76 ) {
if ( F_40 ( ( void T_4 * ) ( unsigned long ) V_43 -> V_47 . V_56 ,
V_43 -> V_18 , V_43 -> V_50 ) ) {
V_44 = - V_48 ;
goto V_82;
}
}
V_82:
F_41 ( V_60 -> V_80 ) ;
V_79:
F_8 ( V_4 ) ;
F_12 ( V_43 -> V_18 ) ;
F_12 ( V_43 ) ;
return V_44 ;
}
static int F_42 ( struct V_27 * V_28 , T_3 V_29 ,
unsigned int V_62 , unsigned long V_73 )
{
int V_19 = - V_25 ;
if ( V_62 == V_92 )
V_19 = F_28 ( V_28 , (struct V_41 T_4 * ) V_73 ) ;
return V_19 ;
}
static int F_43 ( struct V_27 * V_28 , T_3 V_29 ,
unsigned int V_62 , unsigned long V_73 )
{
return F_42 ( V_28 , V_29 , V_62 , ( unsigned long ) F_44 ( V_73 ) ) ;
}
static inline int F_45 ( struct V_59 * V_60 ,
struct V_1 * V_4 )
{
int V_19 ;
struct V_1 * V_93 = F_46 ( V_60 ) ;
if ( V_93 -> V_94 == V_4 -> V_95 )
return 0 ;
if ( F_47 ( V_60 ) ) {
V_60 -> V_96 . V_97 &= ~ V_98 ;
V_60 -> V_96 . V_97 |= V_4 -> V_95 ;
V_19 = F_48 ( V_60 , V_99 ,
V_100 , V_60 -> V_96 . V_97 ,
V_60 -> V_96 . V_101 ) ;
if ( V_19 )
return V_19 ;
}
V_93 -> V_94 = V_4 -> V_95 ;
return 0 ;
}
static T_5 F_49 ( struct V_59 * V_60 )
{
int V_44 ;
T_5 V_102 ;
T_6 * V_53 ;
struct V_65 V_66 = { 0 } ;
struct V_61 V_62 = { 0 } ;
struct V_63 V_64 = { 0 } ;
unsigned int V_103 ;
struct V_67 V_68 ;
V_62 . V_72 = V_104 ;
V_62 . V_73 = V_60 -> V_105 << 16 ;
V_62 . V_74 = V_106 | V_107 | V_108 ;
V_44 = F_50 ( V_60 -> V_80 , & V_62 , 0 ) ;
if ( V_44 )
return ( T_5 ) - 1 ;
if ( ! F_51 ( V_60 -> V_80 ) && ! ( V_62 . V_91 [ 0 ] & V_109 ) )
return ( T_5 ) - 1 ;
memset ( & V_62 , 0 , sizeof( struct V_61 ) ) ;
V_62 . V_72 = V_110 ;
V_62 . V_73 = 0 ;
V_62 . V_74 = V_106 | V_107 | V_111 ;
V_64 . V_84 = V_60 -> V_112 . V_113 * 100 ;
V_64 . V_114 = V_60 -> V_112 . V_115 * 100 ;
V_103 = V_64 . V_84 / 1000 ;
V_103 += V_64 . V_114 * 1000 /
( V_60 -> V_80 -> V_116 . clock / 1000 ) ;
if ( V_103 > 100000 ) {
V_64 . V_84 = 100000000 ;
V_64 . V_114 = 0 ;
}
V_64 . V_52 = 4 ;
V_64 . V_53 = 1 ;
V_64 . V_74 = V_78 ;
V_64 . V_68 = & V_68 ;
V_64 . V_75 = 1 ;
V_66 . V_62 = & V_62 ;
V_66 . V_64 = & V_64 ;
V_53 = F_52 ( 4 , V_45 ) ;
if ( ! V_53 )
return ( T_5 ) - 1 ;
F_32 ( & V_68 , V_53 , 4 ) ;
F_36 ( V_60 -> V_80 , & V_66 ) ;
V_102 = F_53 ( * V_53 ) ;
F_12 ( V_53 ) ;
if ( V_62 . error || V_64 . error )
V_102 = ( T_5 ) - 1 ;
return V_102 ;
}
static int F_54 ( struct V_59 * V_60 , T_5 * V_117 )
{
struct V_61 V_62 = { 0 } ;
int V_44 ;
V_62 . V_72 = V_118 ;
V_62 . V_74 = V_119 | V_85 | V_108 ;
V_44 = F_50 ( V_60 -> V_80 , & V_62 , 5 ) ;
if ( V_44 == 0 )
* V_117 = V_62 . V_91 [ 0 ] ;
return V_44 ;
}
static int F_55 ( struct V_59 * V_60 , T_5 * V_117 , int V_120 )
{
struct V_61 V_62 = { 0 } ;
int V_44 ;
V_62 . V_72 = V_121 ;
if ( ! F_51 ( V_60 -> V_80 ) )
V_62 . V_73 = V_60 -> V_105 << 16 ;
V_62 . V_74 = V_122 | V_107 | V_108 ;
V_44 = F_50 ( V_60 -> V_80 , & V_62 , V_120 ) ;
if ( V_44 == 0 )
* V_117 = V_62 . V_91 [ 0 ] ;
return V_44 ;
}
static int F_56 ( struct V_123 * V_124 , const char * V_125 , int error ,
bool V_126 , T_5 V_117 )
{
switch ( error ) {
case - V_127 :
F_57 ( L_4 ,
V_124 -> V_128 -> V_129 , L_5 ,
V_125 , V_117 ) ;
return V_130 ;
case - V_131 :
F_57 ( L_4 ,
V_124 -> V_128 -> V_129 , L_6 , V_125 , V_117 ) ;
if ( ! V_126 )
return V_130 ;
if ( V_117 & ( V_132 | V_133 ) )
return V_130 ;
return V_134 ;
default:
F_57 ( L_7 ,
V_124 -> V_128 -> V_129 , error , V_117 ) ;
return V_134 ;
}
}
static int F_58 ( struct V_59 * V_60 , struct V_123 * V_124 ,
struct V_135 * V_136 )
{
bool V_137 = true ;
T_5 V_117 , V_138 = 0 ;
int V_44 , V_139 ;
for ( V_139 = 2 ; V_139 >= 0 ; V_139 -- ) {
V_44 = F_55 ( V_60 , & V_117 , 0 ) ;
if ( ! V_44 )
break;
V_137 = false ;
F_57 ( L_8 ,
V_124 -> V_128 -> V_129 , V_44 , V_139 ? L_9 : L_10 ) ;
}
if ( V_44 )
return V_134 ;
if ( F_59 ( V_117 ) == V_140 ||
F_59 ( V_117 ) == V_141 ) {
V_44 = F_54 ( V_60 , & V_138 ) ;
if ( V_44 )
F_57 ( L_11 ,
V_124 -> V_128 -> V_129 , V_44 ) ;
if ( V_44 )
return V_134 ;
}
if ( V_136 -> V_142 . error )
return F_56 ( V_124 , L_12 , V_136 -> V_142 . error ,
V_137 , V_117 ) ;
if ( V_136 -> V_62 . error )
return F_56 ( V_124 , L_13 , V_136 -> V_62 . error ,
V_137 , V_117 ) ;
F_57 ( L_14 ,
V_124 -> V_128 -> V_129 , V_136 -> V_143 . error ,
V_136 -> V_62 . V_91 [ 0 ] , V_117 ) ;
if ( V_138 ) {
V_136 -> V_143 . V_91 [ 0 ] = V_138 ;
V_136 -> V_143 . error = 0 ;
}
return V_144 ;
}
static int F_60 ( struct V_145 * V_146 , struct V_123 * V_124 )
{
struct V_1 * V_4 = V_146 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
unsigned int V_147 , V_148 , V_73 ;
int V_44 = 0 ;
if ( ! F_61 ( V_60 ) ) {
V_44 = - V_149 ;
goto V_26;
}
V_147 = F_62 ( V_124 ) ;
V_148 = F_63 ( V_124 ) ;
if ( F_64 ( V_60 ) )
V_73 = V_150 ;
else
V_73 = V_151 ;
if ( V_60 -> V_152 & V_153 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_154 ,
V_73 == V_150 ?
V_155 :
V_156 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_65 ( V_60 , V_147 , V_148 , V_73 ) ;
V_26:
F_66 ( & V_4 -> V_157 ) ;
F_67 ( V_124 , V_44 , F_68 ( V_124 ) ) ;
F_69 ( & V_4 -> V_157 ) ;
return V_44 ? 0 : 1 ;
}
static int F_70 ( struct V_145 * V_146 ,
struct V_123 * V_124 )
{
struct V_1 * V_4 = V_146 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
unsigned int V_147 , V_148 , V_73 ;
int V_44 = 0 ;
if ( ! F_71 ( V_60 ) ) {
V_44 = - V_149 ;
goto V_26;
}
V_147 = F_62 ( V_124 ) ;
V_148 = F_63 ( V_124 ) ;
if ( F_64 ( V_60 ) && ! F_72 ( V_60 , V_147 , V_148 ) )
V_73 = V_158 ;
else
V_73 = V_159 ;
if ( V_60 -> V_152 & V_153 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_154 ,
V_73 == V_158 ?
V_160 :
V_161 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_65 ( V_60 , V_147 , V_148 , V_73 ) ;
if ( ! V_44 && V_73 == V_158 ) {
if ( V_60 -> V_152 & V_153 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_154 ,
V_162 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_65 ( V_60 , V_147 , V_148 , V_163 ) ;
}
V_26:
F_66 ( & V_4 -> V_157 ) ;
F_67 ( V_124 , V_44 , F_68 ( V_124 ) ) ;
F_69 ( & V_4 -> V_157 ) ;
return V_44 ? 0 : 1 ;
}
static int F_73 ( struct V_145 * V_146 , struct V_123 * V_124 )
{
struct V_1 * V_4 = V_146 -> V_64 ;
F_66 ( & V_4 -> V_157 ) ;
F_74 ( V_124 , 0 ) ;
F_69 ( & V_4 -> V_157 ) ;
return 1 ;
}
static inline void F_75 ( struct V_135 * V_136 ,
struct V_59 * V_60 ,
struct V_123 * V_124 )
{
if ( ! ( V_60 -> V_96 . V_164 & V_165 ) ) {
if ( ! F_76 ( V_136 -> V_62 . V_73 , V_60 -> V_96 . V_166 ) )
V_136 -> V_64 . V_53 = 1 ;
if ( V_136 -> V_64 . V_53 > V_60 -> V_96 . V_166 )
V_136 -> V_64 . V_53 = V_60 -> V_96 . V_166 ;
else if ( V_136 -> V_64 . V_53 < V_60 -> V_96 . V_166 )
V_136 -> V_64 . V_53 = 1 ;
}
}
static int F_77 ( struct V_59 * V_60 ,
struct V_167 * V_168 )
{
enum V_169 V_19 = V_170 ;
struct V_171 * V_172 = F_78 ( V_168 , struct V_171 ,
V_173 ) ;
struct V_135 * V_136 = & V_172 -> V_136 ;
struct V_123 * V_124 = V_172 -> V_124 ;
if ( V_136 -> V_142 . error || V_136 -> V_62 . error || V_136 -> V_143 . error ) {
switch ( F_58 ( V_60 , V_124 , V_136 ) ) {
case V_130 :
return V_174 ;
case V_134 :
return V_175 ;
case V_144 :
break;
}
}
if ( V_136 -> V_62 . V_91 [ 0 ] & V_176 ) {
F_57 ( L_15 ,
V_124 -> V_128 -> V_129 , V_136 -> V_62 . V_91 [ 0 ] ) ;
return V_175 ;
}
if ( ! F_51 ( V_60 -> V_80 ) && F_79 ( V_124 ) != V_177 ) {
T_5 V_117 ;
do {
int V_44 = F_55 ( V_60 , & V_117 , 5 ) ;
if ( V_44 ) {
F_80 ( V_178 L_16 ,
V_124 -> V_128 -> V_129 , V_44 ) ;
return V_179 ;
}
} while ( ! ( V_117 & V_180 ) ||
( F_59 ( V_117 ) == V_181 ) );
}
if ( V_136 -> V_64 . error ) {
F_57 ( L_17 ,
V_124 -> V_128 -> V_129 , V_136 -> V_64 . error ,
( unsigned ) F_62 ( V_124 ) ,
( unsigned ) F_63 ( V_124 ) ,
V_136 -> V_62 . V_91 [ 0 ] , V_136 -> V_143 . V_91 [ 0 ] ) ;
if ( F_79 ( V_124 ) == V_177 ) {
if ( V_136 -> V_64 . V_53 > 1 ) {
F_81 ( L_18 ,
V_124 -> V_128 -> V_129 ) ;
return V_182 ;
}
return V_183 ;
} else {
return V_179 ;
}
}
if ( V_19 == V_170 &&
F_68 ( V_124 ) != V_136 -> V_64 . V_184 )
V_19 = V_185 ;
return V_19 ;
}
static void F_82 ( struct V_171 * V_186 ,
struct V_59 * V_60 ,
int V_187 ,
struct V_145 * V_146 )
{
T_5 V_188 , V_189 ;
struct V_135 * V_136 = & V_186 -> V_136 ;
struct V_123 * V_124 = V_186 -> V_124 ;
struct V_1 * V_4 = V_146 -> V_64 ;
bool V_190 = ( ( V_124 -> V_191 & V_192 ) ||
( V_124 -> V_191 & V_193 ) ) &&
( F_79 ( V_124 ) == V_194 ) &&
( V_4 -> V_74 & V_195 ) ;
memset ( V_136 , 0 , sizeof( struct V_135 ) ) ;
V_136 -> V_66 . V_62 = & V_136 -> V_62 ;
V_136 -> V_66 . V_64 = & V_136 -> V_64 ;
V_136 -> V_62 . V_73 = F_62 ( V_124 ) ;
if ( ! F_83 ( V_60 ) )
V_136 -> V_62 . V_73 <<= 9 ;
V_136 -> V_62 . V_74 = V_106 | V_107 | V_111 ;
V_136 -> V_64 . V_52 = 512 ;
V_136 -> V_143 . V_72 = V_118 ;
V_136 -> V_143 . V_73 = 0 ;
V_136 -> V_143 . V_74 = V_119 | V_85 | V_108 ;
V_136 -> V_64 . V_53 = F_63 ( V_124 ) ;
if ( V_136 -> V_64 . V_53 > V_60 -> V_80 -> V_196 )
V_136 -> V_64 . V_53 = V_60 -> V_80 -> V_196 ;
if ( V_187 && V_136 -> V_64 . V_53 > 1 )
V_136 -> V_64 . V_53 = 1 ;
if ( V_136 -> V_64 . V_53 > 1 || V_190 ) {
if ( ! F_51 ( V_60 -> V_80 ) ||
F_79 ( V_124 ) == V_177 )
V_136 -> V_66 . V_143 = & V_136 -> V_143 ;
V_188 = V_197 ;
V_189 = V_198 ;
} else {
V_136 -> V_66 . V_143 = NULL ;
V_188 = V_199 ;
V_189 = V_200 ;
}
if ( F_79 ( V_124 ) == V_177 ) {
V_136 -> V_62 . V_72 = V_188 ;
V_136 -> V_64 . V_74 |= V_78 ;
} else {
V_136 -> V_62 . V_72 = V_189 ;
V_136 -> V_64 . V_74 |= V_77 ;
}
if ( V_190 )
F_75 ( V_136 , V_60 , V_124 ) ;
if ( ( V_4 -> V_74 & V_201 ) &&
F_84 ( V_136 -> V_62 . V_72 ) &&
( V_190 || ! ( V_60 -> V_152 & V_202 ) ) ) {
V_136 -> V_142 . V_72 = V_203 ;
V_136 -> V_142 . V_73 = V_136 -> V_64 . V_53 |
( V_190 ? ( 1 << 31 ) : 0 ) ;
V_136 -> V_142 . V_74 = V_107 | V_108 ;
V_136 -> V_66 . V_142 = & V_136 -> V_142 ;
}
F_35 ( & V_136 -> V_64 , V_60 ) ;
V_136 -> V_64 . V_68 = V_186 -> V_68 ;
V_136 -> V_64 . V_75 = F_85 ( V_146 , V_186 ) ;
if ( V_136 -> V_64 . V_53 != F_63 ( V_124 ) ) {
int V_204 , V_205 = V_136 -> V_64 . V_53 << 9 ;
struct V_67 * V_68 ;
F_86 (brq->data.sg, sg, brq->data.sg_len, i) {
V_205 -= V_68 -> V_206 ;
if ( V_205 <= 0 ) {
V_68 -> V_206 += V_205 ;
V_204 ++ ;
break;
}
}
V_136 -> V_64 . V_75 = V_204 ;
}
V_186 -> V_173 . V_66 = & V_136 -> V_66 ;
V_186 -> V_173 . V_207 = F_77 ;
F_87 ( V_186 ) ;
}
static int F_88 ( struct V_145 * V_146 , struct V_123 * V_208 )
{
struct V_1 * V_4 = V_146 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
struct V_135 * V_136 = & V_146 -> V_209 -> V_136 ;
int V_19 = 1 , V_187 = 0 , V_139 = 0 ;
enum V_169 V_117 ;
struct V_171 * V_210 ;
struct V_123 * V_124 ;
struct V_167 * V_168 ;
if ( ! V_208 && ! V_146 -> V_211 -> V_124 )
return 0 ;
do {
if ( V_208 ) {
F_82 ( V_146 -> V_209 , V_60 , 0 , V_146 ) ;
V_168 = & V_146 -> V_209 -> V_173 ;
} else
V_168 = NULL ;
V_168 = F_89 ( V_60 -> V_80 , V_168 , ( int * ) & V_117 ) ;
if ( ! V_168 )
return 0 ;
V_210 = F_78 ( V_168 , struct V_171 , V_173 ) ;
V_136 = & V_210 -> V_136 ;
V_124 = V_210 -> V_124 ;
F_90 ( V_210 ) ;
switch ( V_117 ) {
case V_170 :
case V_185 :
F_66 ( & V_4 -> V_157 ) ;
V_19 = F_67 ( V_124 , 0 ,
V_136 -> V_64 . V_184 ) ;
F_69 ( & V_4 -> V_157 ) ;
if ( V_117 == V_170 && V_19 ) {
F_80 ( V_178 L_19 ,
V_87 , F_68 ( V_124 ) ,
V_136 -> V_64 . V_184 ) ;
V_208 = NULL ;
goto V_212;
}
break;
case V_179 :
goto V_213;
case V_182 :
V_187 = 1 ;
break;
case V_174 :
if ( V_139 ++ < 5 )
break;
case V_175 :
goto V_212;
case V_183 :
F_66 ( & V_4 -> V_157 ) ;
V_19 = F_67 ( V_124 , - V_214 ,
V_136 -> V_64 . V_52 ) ;
F_69 ( & V_4 -> V_157 ) ;
if ( ! V_19 )
goto V_215;
break;
}
if ( V_19 ) {
F_82 ( V_210 , V_60 , V_187 , V_146 ) ;
F_89 ( V_60 -> V_80 , & V_210 -> V_173 , NULL ) ;
}
} while ( V_19 );
return 1 ;
V_213:
if ( F_91 ( V_60 ) ) {
T_5 V_53 ;
V_53 = F_49 ( V_60 ) ;
if ( V_53 != ( T_5 ) - 1 ) {
F_66 ( & V_4 -> V_157 ) ;
V_19 = F_67 ( V_124 , 0 , V_53 << 9 ) ;
F_69 ( & V_4 -> V_157 ) ;
}
} else {
F_66 ( & V_4 -> V_157 ) ;
V_19 = F_67 ( V_124 , 0 , V_136 -> V_64 . V_184 ) ;
F_69 ( & V_4 -> V_157 ) ;
}
V_212:
F_66 ( & V_4 -> V_157 ) ;
while ( V_19 )
V_19 = F_67 ( V_124 , - V_214 , F_92 ( V_124 ) ) ;
F_69 ( & V_4 -> V_157 ) ;
V_215:
if ( V_208 ) {
F_82 ( V_146 -> V_209 , V_60 , 0 , V_146 ) ;
F_89 ( V_60 -> V_80 , & V_146 -> V_209 -> V_173 , NULL ) ;
}
return 0 ;
}
static int F_93 ( struct V_145 * V_146 , struct V_123 * V_124 )
{
int V_19 ;
struct V_1 * V_4 = V_146 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
if ( V_124 && ! V_146 -> V_211 -> V_124 )
F_33 ( V_60 -> V_80 ) ;
V_19 = F_45 ( V_60 , V_4 ) ;
if ( V_19 ) {
V_19 = 0 ;
goto V_26;
}
if ( V_124 && V_124 -> V_191 & V_216 ) {
if ( V_60 -> V_80 -> V_168 )
F_88 ( V_146 , NULL ) ;
if ( V_124 -> V_191 & V_217 )
V_19 = F_70 ( V_146 , V_124 ) ;
else
V_19 = F_60 ( V_146 , V_124 ) ;
} else if ( V_124 && V_124 -> V_191 & V_218 ) {
if ( V_60 -> V_80 -> V_168 )
F_88 ( V_146 , NULL ) ;
V_19 = F_73 ( V_146 , V_124 ) ;
} else {
V_19 = F_88 ( V_146 , V_124 ) ;
}
V_26:
if ( ! V_124 )
F_41 ( V_60 -> V_80 ) ;
return V_19 ;
}
static inline int F_94 ( struct V_59 * V_60 )
{
return F_95 ( V_60 ) ||
! ( V_60 -> V_112 . V_219 & V_220 ) ;
}
static struct V_1 * F_96 ( struct V_59 * V_60 ,
struct V_14 * V_221 ,
T_7 V_222 ,
bool V_223 ,
const char * V_224 )
{
struct V_1 * V_4 ;
int V_9 , V_19 ;
V_9 = F_97 ( V_13 , V_225 ) ;
if ( V_9 >= V_225 )
return F_27 ( - V_226 ) ;
F_98 ( V_9 , V_13 ) ;
V_4 = F_25 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_4 ) {
V_19 = - V_46 ;
goto V_26;
}
if ( ! V_224 ) {
V_4 -> V_227 = F_97 ( V_228 , V_225 ) ;
F_98 ( V_4 -> V_227 , V_228 ) ;
}
else
V_4 -> V_227 = ( (struct V_1 * )
F_14 ( V_221 ) -> V_6 ) -> V_227 ;
V_4 -> V_21 = F_94 ( V_60 ) ;
V_4 -> V_3 = F_99 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_19 = - V_46 ;
goto V_229;
}
F_100 ( & V_4 -> V_157 ) ;
F_101 ( & V_4 -> V_230 ) ;
V_4 -> V_7 = 1 ;
V_19 = F_102 ( & V_4 -> V_12 , V_60 , & V_4 -> V_157 , V_224 ) ;
if ( V_19 )
goto V_231;
V_4 -> V_12 . V_232 = F_93 ;
V_4 -> V_12 . V_64 = V_4 ;
V_4 -> V_3 -> V_233 = V_234 ;
V_4 -> V_3 -> V_11 = V_9 * V_10 ;
V_4 -> V_3 -> V_235 = & V_236 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_12 = V_4 -> V_12 . V_12 ;
V_4 -> V_3 -> V_237 = V_221 ;
F_18 ( V_4 -> V_3 , V_4 -> V_21 || V_223 ) ;
snprintf ( V_4 -> V_3 -> V_129 , sizeof( V_4 -> V_3 -> V_129 ) ,
L_20 , V_4 -> V_227 , V_224 ? V_224 : L_21 ) ;
F_103 ( V_4 -> V_12 . V_12 , 512 ) ;
F_104 ( V_4 -> V_3 , V_222 ) ;
if ( F_105 ( V_60 -> V_80 ) ) {
if ( F_47 ( V_60 ) ||
( F_91 ( V_60 ) &&
V_60 -> V_238 . V_239 & V_240 ) )
V_4 -> V_74 |= V_201 ;
}
if ( F_47 ( V_60 ) &&
V_4 -> V_74 & V_201 &&
( ( V_60 -> V_96 . V_164 & V_165 ) ||
V_60 -> V_96 . V_166 ) ) {
V_4 -> V_74 |= V_195 ;
F_106 ( V_4 -> V_12 . V_12 , V_218 | V_192 ) ;
}
return V_4 ;
V_231:
F_11 ( V_4 -> V_3 ) ;
V_229:
F_12 ( V_4 ) ;
V_26:
return F_27 ( V_19 ) ;
}
static struct V_1 * F_107 ( struct V_59 * V_60 )
{
T_7 V_222 ;
struct V_1 * V_4 ;
if ( ! F_91 ( V_60 ) && F_83 ( V_60 ) ) {
V_222 = V_60 -> V_96 . V_39 ;
} else {
V_222 = V_60 -> V_112 . V_241 << ( V_60 -> V_112 . V_242 - 9 ) ;
}
V_4 = F_96 ( V_60 , & V_60 -> V_15 , V_222 , false , NULL ) ;
return V_4 ;
}
static int F_108 ( struct V_59 * V_60 ,
struct V_1 * V_4 ,
unsigned int V_95 ,
T_7 V_222 ,
bool V_223 ,
const char * V_224 )
{
char V_243 [ 10 ] ;
struct V_1 * V_244 ;
V_244 = F_96 ( V_60 , F_109 ( V_4 -> V_3 ) , V_222 , V_223 ,
V_224 ) ;
if ( F_30 ( V_244 ) )
return F_31 ( V_244 ) ;
V_244 -> V_95 = V_95 ;
F_110 ( & V_244 -> V_230 , & V_4 -> V_230 ) ;
F_111 ( ( V_51 ) F_23 ( V_244 -> V_3 ) << 9 , V_245 ,
V_243 , sizeof( V_243 ) ) ;
F_80 ( V_246 L_22 ,
V_244 -> V_3 -> V_129 , F_112 ( V_60 ) ,
F_113 ( V_60 ) , V_244 -> V_95 , V_243 ) ;
return 0 ;
}
static int F_114 ( struct V_59 * V_60 , struct V_1 * V_4 )
{
int V_19 = 0 ;
if ( ! F_47 ( V_60 ) )
return 0 ;
if ( V_60 -> V_96 . V_247 ) {
V_19 = F_108 ( V_60 , V_4 , V_248 ,
V_60 -> V_96 . V_247 >> 9 ,
true ,
L_23 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_108 ( V_60 , V_4 , V_249 ,
V_60 -> V_96 . V_247 >> 9 ,
true ,
L_24 ) ;
if ( V_19 )
return V_19 ;
}
return V_19 ;
}
static int
F_115 ( struct V_1 * V_4 , struct V_59 * V_60 )
{
int V_44 ;
F_33 ( V_60 -> V_80 ) ;
V_44 = F_116 ( V_60 , 512 ) ;
F_41 ( V_60 -> V_80 ) ;
if ( V_44 ) {
F_80 ( V_178 L_25 ,
V_4 -> V_3 -> V_129 , V_44 ) ;
return - V_25 ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_4 )
{
if ( V_4 ) {
if ( V_4 -> V_3 -> V_74 & V_250 ) {
F_118 ( F_109 ( V_4 -> V_3 ) , & V_4 -> V_251 ) ;
F_119 ( V_4 -> V_3 ) ;
}
F_120 ( & V_4 -> V_12 ) ;
F_8 ( V_4 ) ;
}
}
static void F_121 ( struct V_59 * V_60 ,
struct V_1 * V_4 )
{
struct V_252 * V_253 , * V_254 ;
struct V_1 * V_244 ;
F_10 ( V_4 -> V_227 , V_228 ) ;
F_122 (pos, q, &md->part) {
V_244 = F_123 ( V_253 , struct V_1 , V_230 ) ;
F_124 ( V_253 ) ;
F_117 ( V_244 ) ;
}
}
static int F_125 ( struct V_1 * V_4 )
{
int V_19 ;
F_126 ( V_4 -> V_3 ) ;
V_4 -> V_251 . V_255 = F_13 ;
V_4 -> V_251 . V_256 = F_16 ;
F_127 ( & V_4 -> V_251 . V_17 ) ;
V_4 -> V_251 . V_17 . V_125 = L_26 ;
V_4 -> V_251 . V_17 . V_29 = V_257 | V_258 ;
V_19 = F_128 ( F_109 ( V_4 -> V_3 ) , & V_4 -> V_251 ) ;
if ( V_19 )
F_119 ( V_4 -> V_3 ) ;
return V_19 ;
}
static int F_129 ( struct V_59 * V_60 )
{
struct V_1 * V_4 , * V_244 ;
int V_44 ;
char V_243 [ 10 ] ;
if ( ! ( V_60 -> V_112 . V_219 & V_259 ) )
return - V_260 ;
V_4 = F_107 ( V_60 ) ;
if ( F_30 ( V_4 ) )
return F_31 ( V_4 ) ;
V_44 = F_115 ( V_4 , V_60 ) ;
if ( V_44 )
goto V_26;
F_111 ( ( V_51 ) F_23 ( V_4 -> V_3 ) << 9 , V_245 ,
V_243 , sizeof( V_243 ) ) ;
F_80 ( V_246 L_27 ,
V_4 -> V_3 -> V_129 , F_112 ( V_60 ) , F_113 ( V_60 ) ,
V_243 , V_4 -> V_21 ? L_28 : L_21 ) ;
if ( F_114 ( V_60 , V_4 ) )
goto V_26;
F_130 ( V_60 , V_4 ) ;
F_131 ( V_60 , V_261 ) ;
if ( F_125 ( V_4 ) )
goto V_26;
F_132 (part_md, &md->part, part) {
if ( F_125 ( V_244 ) )
goto V_26;
}
return 0 ;
V_26:
F_121 ( V_60 , V_4 ) ;
F_117 ( V_4 ) ;
return V_44 ;
}
static void F_133 ( struct V_59 * V_60 )
{
struct V_1 * V_4 = F_46 ( V_60 ) ;
F_121 ( V_60 , V_4 ) ;
F_33 ( V_60 -> V_80 ) ;
F_45 ( V_60 , V_4 ) ;
F_41 ( V_60 -> V_80 ) ;
F_117 ( V_4 ) ;
F_130 ( V_60 , NULL ) ;
}
static int F_134 ( struct V_59 * V_60 , T_8 V_262 )
{
struct V_1 * V_244 ;
struct V_1 * V_4 = F_46 ( V_60 ) ;
if ( V_4 ) {
F_135 ( & V_4 -> V_12 ) ;
F_132 (part_md, &md->part, part) {
F_135 ( & V_244 -> V_12 ) ;
}
}
return 0 ;
}
static int F_136 ( struct V_59 * V_60 )
{
struct V_1 * V_244 ;
struct V_1 * V_4 = F_46 ( V_60 ) ;
if ( V_4 ) {
F_115 ( V_4 , V_60 ) ;
V_4 -> V_94 = V_4 -> V_95 ;
F_137 ( & V_4 -> V_12 ) ;
F_132 (part_md, &md->part, part) {
F_137 ( & V_244 -> V_12 ) ;
}
}
return 0 ;
}
static int T_9 F_138 ( void )
{
int V_263 ;
if ( V_10 != V_264 )
F_139 ( L_29 , V_10 ) ;
V_225 = 256 / V_10 ;
V_263 = F_140 ( V_234 , L_30 ) ;
if ( V_263 )
goto V_26;
V_263 = F_141 ( & V_265 ) ;
if ( V_263 )
goto V_266;
return 0 ;
V_266:
F_142 ( V_234 , L_30 ) ;
V_26:
return V_263 ;
}
static void T_10 F_143 ( void )
{
F_144 ( & V_265 ) ;
F_142 ( V_234 , L_30 ) ;
}
