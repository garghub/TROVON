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
struct V_65 V_66 = { NULL } ;
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
T_5 V_96 = V_60 -> V_97 . V_96 ;
V_96 &= ~ V_98 ;
V_96 |= V_4 -> V_95 ;
V_19 = F_48 ( V_60 , V_99 ,
V_100 , V_96 ,
V_60 -> V_97 . V_101 ) ;
if ( V_19 )
return V_19 ;
V_60 -> V_97 . V_96 = V_96 ;
}
V_93 -> V_94 = V_4 -> V_95 ;
return 0 ;
}
static T_6 F_49 ( struct V_59 * V_60 )
{
int V_44 ;
T_6 V_102 ;
T_7 * V_53 ;
struct V_65 V_66 = { NULL } ;
struct V_61 V_62 = { 0 } ;
struct V_63 V_64 = { 0 } ;
unsigned int V_103 ;
struct V_67 V_68 ;
V_62 . V_72 = V_104 ;
V_62 . V_73 = V_60 -> V_105 << 16 ;
V_62 . V_74 = V_106 | V_107 | V_108 ;
V_44 = F_50 ( V_60 -> V_80 , & V_62 , 0 ) ;
if ( V_44 )
return ( T_6 ) - 1 ;
if ( ! F_51 ( V_60 -> V_80 ) && ! ( V_62 . V_91 [ 0 ] & V_109 ) )
return ( T_6 ) - 1 ;
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
return ( T_6 ) - 1 ;
F_32 ( & V_68 , V_53 , 4 ) ;
F_36 ( V_60 -> V_80 , & V_66 ) ;
V_102 = F_53 ( * V_53 ) ;
F_12 ( V_53 ) ;
if ( V_62 . error || V_64 . error )
V_102 = ( T_6 ) - 1 ;
return V_102 ;
}
static int F_54 ( struct V_59 * V_60 , T_6 * V_117 )
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
static int F_55 ( struct V_59 * V_60 , T_6 * V_117 , int V_120 )
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
bool V_126 , T_6 V_117 )
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
struct V_135 * V_136 , int * V_137 )
{
bool V_138 = true ;
T_6 V_117 , V_139 = 0 ;
int V_44 , V_140 ;
for ( V_140 = 2 ; V_140 >= 0 ; V_140 -- ) {
V_44 = F_55 ( V_60 , & V_117 , 0 ) ;
if ( ! V_44 )
break;
V_138 = false ;
F_57 ( L_8 ,
V_124 -> V_128 -> V_129 , V_44 , V_140 ? L_9 : L_10 ) ;
}
if ( V_44 )
return V_134 ;
if ( ( V_117 & V_141 ) ||
( V_136 -> V_142 . V_91 [ 0 ] & V_141 ) ||
( V_136 -> V_62 . V_91 [ 0 ] & V_141 ) )
* V_137 = 1 ;
if ( F_59 ( V_117 ) == V_143 ||
F_59 ( V_117 ) == V_144 ) {
V_44 = F_54 ( V_60 , & V_139 ) ;
if ( V_44 )
F_57 ( L_11 ,
V_124 -> V_128 -> V_129 , V_44 ) ;
if ( V_44 )
return V_134 ;
if ( V_139 & V_141 )
* V_137 = 1 ;
}
if ( V_136 -> V_145 . error )
return F_56 ( V_124 , L_12 , V_136 -> V_145 . error ,
V_138 , V_117 ) ;
if ( V_136 -> V_62 . error )
return F_56 ( V_124 , L_13 , V_136 -> V_62 . error ,
V_138 , V_117 ) ;
if ( ! V_136 -> V_142 . error )
return V_146 ;
F_57 ( L_14 ,
V_124 -> V_128 -> V_129 , V_136 -> V_142 . error ,
V_136 -> V_62 . V_91 [ 0 ] , V_117 ) ;
if ( V_139 ) {
V_136 -> V_142 . V_91 [ 0 ] = V_139 ;
V_136 -> V_142 . error = 0 ;
}
return V_146 ;
}
static int F_60 ( struct V_1 * V_4 , struct V_147 * V_80 ,
int type )
{
int V_44 ;
if ( V_4 -> V_148 & type )
return - V_149 ;
V_4 -> V_148 |= type ;
V_44 = F_61 ( V_80 ) ;
if ( V_44 != - V_150 ) {
struct V_1 * V_93 = F_46 ( V_80 -> V_60 ) ;
int V_151 ;
V_93 -> V_94 = V_93 -> V_95 ;
V_151 = F_45 ( V_80 -> V_60 , V_4 ) ;
if ( V_151 ) {
return - V_152 ;
}
}
return V_44 ;
}
static inline void F_62 ( struct V_1 * V_4 , int type )
{
V_4 -> V_148 &= ~ type ;
}
static int F_63 ( struct V_153 * V_154 , struct V_123 * V_124 )
{
struct V_1 * V_4 = V_154 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
unsigned int V_155 , V_156 , V_73 ;
int V_44 = 0 , type = V_157 ;
if ( ! F_64 ( V_60 ) ) {
V_44 = - V_150 ;
goto V_26;
}
V_155 = F_65 ( V_124 ) ;
V_156 = F_66 ( V_124 ) ;
if ( F_67 ( V_60 ) )
V_73 = V_158 ;
else if ( F_68 ( V_60 ) )
V_73 = V_159 ;
else
V_73 = V_160 ;
V_140:
if ( V_60 -> V_161 & V_162 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_163 ,
V_73 == V_159 ?
V_164 :
V_165 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_69 ( V_60 , V_155 , V_156 , V_73 ) ;
V_26:
if ( V_44 == - V_166 && ! F_60 ( V_4 , V_60 -> V_80 , type ) )
goto V_140;
if ( ! V_44 )
F_62 ( V_4 , type ) ;
F_70 ( & V_4 -> V_167 ) ;
F_71 ( V_124 , V_44 , F_72 ( V_124 ) ) ;
F_73 ( & V_4 -> V_167 ) ;
return V_44 ? 0 : 1 ;
}
static int F_74 ( struct V_153 * V_154 ,
struct V_123 * V_124 )
{
struct V_1 * V_4 = V_154 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
unsigned int V_155 , V_156 , V_73 ;
int V_44 = 0 , type = V_168 ;
if ( ! ( F_75 ( V_60 ) || F_76 ( V_60 ) ) ) {
V_44 = - V_150 ;
goto V_26;
}
if ( F_76 ( V_60 ) ) {
V_44 = F_48 ( V_60 , V_99 ,
V_169 , 1 , 0 ) ;
goto V_26;
}
V_155 = F_65 ( V_124 ) ;
V_156 = F_66 ( V_124 ) ;
if ( F_68 ( V_60 ) && ! F_77 ( V_60 , V_155 , V_156 ) )
V_73 = V_170 ;
else
V_73 = V_171 ;
V_140:
if ( V_60 -> V_161 & V_162 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_163 ,
V_73 == V_170 ?
V_172 :
V_173 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_69 ( V_60 , V_155 , V_156 , V_73 ) ;
if ( ! V_44 && V_73 == V_170 ) {
if ( V_60 -> V_161 & V_162 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_163 ,
V_174 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_69 ( V_60 , V_155 , V_156 , V_175 ) ;
}
V_26:
if ( V_44 == - V_166 && ! F_60 ( V_4 , V_60 -> V_80 , type ) )
goto V_140;
if ( ! V_44 )
F_62 ( V_4 , type ) ;
F_70 ( & V_4 -> V_167 ) ;
F_71 ( V_124 , V_44 , F_72 ( V_124 ) ) ;
F_73 ( & V_4 -> V_167 ) ;
return V_44 ? 0 : 1 ;
}
static int F_78 ( struct V_153 * V_154 , struct V_123 * V_124 )
{
struct V_1 * V_4 = V_154 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
int V_19 = 0 ;
V_19 = F_79 ( V_60 ) ;
if ( V_19 )
V_19 = - V_166 ;
F_70 ( & V_4 -> V_167 ) ;
F_80 ( V_124 , V_19 ) ;
F_73 ( & V_4 -> V_167 ) ;
return V_19 ? 0 : 1 ;
}
static inline void F_81 ( struct V_135 * V_136 ,
struct V_59 * V_60 ,
struct V_123 * V_124 )
{
if ( ! ( V_60 -> V_97 . V_176 & V_177 ) ) {
if ( ! F_82 ( V_136 -> V_62 . V_73 , V_60 -> V_97 . V_178 ) )
V_136 -> V_64 . V_53 = 1 ;
if ( V_136 -> V_64 . V_53 > V_60 -> V_97 . V_178 )
V_136 -> V_64 . V_53 = V_60 -> V_97 . V_178 ;
else if ( V_136 -> V_64 . V_53 < V_60 -> V_97 . V_178 )
V_136 -> V_64 . V_53 = 1 ;
}
}
static int F_83 ( struct V_59 * V_60 ,
struct V_179 * V_180 )
{
struct V_181 * V_182 = F_84 ( V_180 , struct V_181 ,
V_183 ) ;
struct V_135 * V_136 = & V_182 -> V_136 ;
struct V_123 * V_124 = V_182 -> V_124 ;
int V_137 = 0 ;
if ( V_136 -> V_145 . error || V_136 -> V_62 . error || V_136 -> V_142 . error ||
V_136 -> V_64 . error ) {
switch ( F_58 ( V_60 , V_124 , V_136 , & V_137 ) ) {
case V_130 :
return V_184 ;
case V_134 :
return V_185 ;
case V_146 :
break;
}
}
if ( V_136 -> V_62 . V_91 [ 0 ] & V_186 ) {
F_57 ( L_15 ,
V_124 -> V_128 -> V_129 , V_136 -> V_62 . V_91 [ 0 ] ) ;
return V_185 ;
}
if ( ! F_51 ( V_60 -> V_80 ) && F_85 ( V_124 ) != V_187 ) {
T_6 V_117 ;
do {
int V_44 = F_55 ( V_60 , & V_117 , 5 ) ;
if ( V_44 ) {
F_57 ( L_16 ,
V_124 -> V_128 -> V_129 , V_44 ) ;
return V_188 ;
}
} while ( ! ( V_117 & V_189 ) ||
( F_59 ( V_117 ) == V_190 ) );
}
if ( V_136 -> V_64 . error ) {
F_57 ( L_17 ,
V_124 -> V_128 -> V_129 , V_136 -> V_64 . error ,
( unsigned ) F_65 ( V_124 ) ,
( unsigned ) F_66 ( V_124 ) ,
V_136 -> V_62 . V_91 [ 0 ] , V_136 -> V_142 . V_91 [ 0 ] ) ;
if ( F_85 ( V_124 ) == V_187 ) {
if ( V_137 )
return V_191 ;
return V_192 ;
} else {
return V_188 ;
}
}
if ( ! V_136 -> V_64 . V_193 )
return V_184 ;
if ( F_72 ( V_124 ) != V_136 -> V_64 . V_193 )
return V_194 ;
return V_195 ;
}
static void F_86 ( struct V_181 * V_196 ,
struct V_59 * V_60 ,
int V_197 ,
struct V_153 * V_154 )
{
T_6 V_198 , V_199 ;
struct V_135 * V_136 = & V_196 -> V_136 ;
struct V_123 * V_124 = V_196 -> V_124 ;
struct V_1 * V_4 = V_154 -> V_64 ;
bool V_200 = ( ( V_124 -> V_201 & V_202 ) ||
( V_124 -> V_201 & V_203 ) ) &&
( F_85 ( V_124 ) == V_204 ) &&
( V_4 -> V_74 & V_205 ) ;
memset ( V_136 , 0 , sizeof( struct V_135 ) ) ;
V_136 -> V_66 . V_62 = & V_136 -> V_62 ;
V_136 -> V_66 . V_64 = & V_136 -> V_64 ;
V_136 -> V_62 . V_73 = F_65 ( V_124 ) ;
if ( ! F_87 ( V_60 ) )
V_136 -> V_62 . V_73 <<= 9 ;
V_136 -> V_62 . V_74 = V_106 | V_107 | V_111 ;
V_136 -> V_64 . V_52 = 512 ;
V_136 -> V_142 . V_72 = V_118 ;
V_136 -> V_142 . V_73 = 0 ;
V_136 -> V_142 . V_74 = V_119 | V_85 | V_108 ;
V_136 -> V_64 . V_53 = F_66 ( V_124 ) ;
if ( V_136 -> V_64 . V_53 > V_60 -> V_80 -> V_206 )
V_136 -> V_64 . V_53 = V_60 -> V_80 -> V_206 ;
if ( V_136 -> V_64 . V_53 > 1 ) {
if ( V_197 )
V_136 -> V_64 . V_53 = 1 ;
if ( V_60 -> V_80 -> V_207 & V_208 &&
F_85 ( V_124 ) == V_187 )
V_136 -> V_64 . V_53 = 1 ;
}
if ( V_136 -> V_64 . V_53 > 1 || V_200 ) {
if ( ! F_51 ( V_60 -> V_80 ) ||
F_85 ( V_124 ) == V_187 )
V_136 -> V_66 . V_142 = & V_136 -> V_142 ;
V_198 = V_209 ;
V_199 = V_210 ;
} else {
V_136 -> V_66 . V_142 = NULL ;
V_198 = V_211 ;
V_199 = V_212 ;
}
if ( F_85 ( V_124 ) == V_187 ) {
V_136 -> V_62 . V_72 = V_198 ;
V_136 -> V_64 . V_74 |= V_78 ;
} else {
V_136 -> V_62 . V_72 = V_199 ;
V_136 -> V_64 . V_74 |= V_77 ;
}
if ( V_200 )
F_81 ( V_136 , V_60 , V_124 ) ;
if ( ( V_4 -> V_74 & V_213 ) &&
F_88 ( V_136 -> V_62 . V_72 ) &&
( V_200 || ! ( V_60 -> V_161 & V_214 ) ) ) {
V_136 -> V_145 . V_72 = V_215 ;
V_136 -> V_145 . V_73 = V_136 -> V_64 . V_53 |
( V_200 ? ( 1 << 31 ) : 0 ) ;
V_136 -> V_145 . V_74 = V_107 | V_108 ;
V_136 -> V_66 . V_145 = & V_136 -> V_145 ;
}
F_35 ( & V_136 -> V_64 , V_60 ) ;
V_136 -> V_64 . V_68 = V_196 -> V_68 ;
V_136 -> V_64 . V_75 = F_89 ( V_154 , V_196 ) ;
if ( V_136 -> V_64 . V_53 != F_66 ( V_124 ) ) {
int V_216 , V_217 = V_136 -> V_64 . V_53 << 9 ;
struct V_67 * V_68 ;
F_90 (brq->data.sg, sg, brq->data.sg_len, i) {
V_217 -= V_68 -> V_218 ;
if ( V_217 <= 0 ) {
V_68 -> V_218 += V_217 ;
V_216 ++ ;
break;
}
}
V_136 -> V_64 . V_75 = V_216 ;
}
V_196 -> V_183 . V_66 = & V_136 -> V_66 ;
V_196 -> V_183 . V_219 = F_83 ;
F_91 ( V_196 ) ;
}
static int F_92 ( struct V_1 * V_4 , struct V_59 * V_60 ,
struct V_135 * V_136 , struct V_123 * V_124 ,
int V_19 )
{
if ( F_93 ( V_60 ) ) {
T_6 V_53 ;
V_53 = F_49 ( V_60 ) ;
if ( V_53 != ( T_6 ) - 1 ) {
F_70 ( & V_4 -> V_167 ) ;
V_19 = F_71 ( V_124 , 0 , V_53 << 9 ) ;
F_73 ( & V_4 -> V_167 ) ;
}
} else {
F_70 ( & V_4 -> V_167 ) ;
V_19 = F_71 ( V_124 , 0 , V_136 -> V_64 . V_193 ) ;
F_73 ( & V_4 -> V_167 ) ;
}
return V_19 ;
}
static int F_94 ( struct V_153 * V_154 , struct V_123 * V_220 )
{
struct V_1 * V_4 = V_154 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
struct V_135 * V_136 = & V_154 -> V_221 -> V_136 ;
int V_19 = 1 , V_197 = 0 , V_140 = 0 , type ;
enum V_222 V_117 ;
struct V_181 * V_223 ;
struct V_123 * V_124 ;
struct V_179 * V_180 ;
if ( ! V_220 && ! V_154 -> V_224 -> V_124 )
return 0 ;
do {
if ( V_220 ) {
F_86 ( V_154 -> V_221 , V_60 , 0 , V_154 ) ;
V_180 = & V_154 -> V_221 -> V_183 ;
} else
V_180 = NULL ;
V_180 = F_95 ( V_60 -> V_80 , V_180 , ( int * ) & V_117 ) ;
if ( ! V_180 )
return 0 ;
V_223 = F_84 ( V_180 , struct V_181 , V_183 ) ;
V_136 = & V_223 -> V_136 ;
V_124 = V_223 -> V_124 ;
type = F_85 ( V_124 ) == V_187 ? V_225 : V_226 ;
F_96 ( V_223 ) ;
switch ( V_117 ) {
case V_195 :
case V_194 :
F_62 ( V_4 , type ) ;
F_70 ( & V_4 -> V_167 ) ;
V_19 = F_71 ( V_124 , 0 ,
V_136 -> V_64 . V_193 ) ;
F_73 ( & V_4 -> V_167 ) ;
if ( V_117 == V_195 && V_19 ) {
F_57 ( L_18 ,
V_87 , F_72 ( V_124 ) ,
V_136 -> V_64 . V_193 ) ;
V_220 = NULL ;
goto V_227;
}
break;
case V_188 :
V_19 = F_92 ( V_4 , V_60 , V_136 , V_124 , V_19 ) ;
if ( ! F_60 ( V_4 , V_60 -> V_80 , type ) )
break;
goto V_227;
case V_184 :
if ( V_140 ++ < 5 )
break;
case V_185 :
if ( ! F_60 ( V_4 , V_60 -> V_80 , type ) )
break;
goto V_227;
case V_192 : {
int V_44 ;
V_44 = F_60 ( V_4 , V_60 -> V_80 , type ) ;
if ( ! V_44 )
break;
if ( V_44 == - V_152 )
goto V_227;
}
case V_191 :
if ( V_136 -> V_64 . V_53 > 1 ) {
F_97 ( L_19 ,
V_124 -> V_128 -> V_129 ) ;
V_197 = 1 ;
break;
}
F_70 ( & V_4 -> V_167 ) ;
V_19 = F_71 ( V_124 , - V_166 ,
V_136 -> V_64 . V_52 ) ;
F_73 ( & V_4 -> V_167 ) ;
if ( ! V_19 )
goto V_228;
break;
}
if ( V_19 ) {
F_86 ( V_223 , V_60 , V_197 , V_154 ) ;
F_95 ( V_60 -> V_80 , & V_223 -> V_183 , NULL ) ;
}
} while ( V_19 );
return 1 ;
V_227:
F_70 ( & V_4 -> V_167 ) ;
while ( V_19 )
V_19 = F_71 ( V_124 , - V_166 , F_98 ( V_124 ) ) ;
F_73 ( & V_4 -> V_167 ) ;
V_228:
if ( V_220 ) {
F_86 ( V_154 -> V_221 , V_60 , 0 , V_154 ) ;
F_95 ( V_60 -> V_80 , & V_154 -> V_221 -> V_183 , NULL ) ;
}
return 0 ;
}
static int F_99 ( struct V_153 * V_154 , struct V_123 * V_124 )
{
int V_19 ;
struct V_1 * V_4 = V_154 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
if ( V_124 && ! V_154 -> V_224 -> V_124 )
F_33 ( V_60 -> V_80 ) ;
V_19 = F_45 ( V_60 , V_4 ) ;
if ( V_19 ) {
if ( V_124 ) {
F_70 ( & V_4 -> V_167 ) ;
F_80 ( V_124 , - V_166 ) ;
F_73 ( & V_4 -> V_167 ) ;
}
V_19 = 0 ;
goto V_26;
}
if ( V_124 && V_124 -> V_201 & V_229 ) {
if ( V_60 -> V_80 -> V_180 )
F_94 ( V_154 , NULL ) ;
if ( V_124 -> V_201 & V_230 )
V_19 = F_74 ( V_154 , V_124 ) ;
else
V_19 = F_63 ( V_154 , V_124 ) ;
} else if ( V_124 && V_124 -> V_201 & V_231 ) {
if ( V_60 -> V_80 -> V_180 )
F_94 ( V_154 , NULL ) ;
V_19 = F_78 ( V_154 , V_124 ) ;
} else {
V_19 = F_94 ( V_154 , V_124 ) ;
}
V_26:
if ( ! V_124 )
F_41 ( V_60 -> V_80 ) ;
return V_19 ;
}
static inline int F_100 ( struct V_59 * V_60 )
{
return F_101 ( V_60 ) ||
! ( V_60 -> V_112 . V_232 & V_233 ) ;
}
static struct V_1 * F_102 ( struct V_59 * V_60 ,
struct V_14 * V_234 ,
T_8 V_235 ,
bool V_236 ,
const char * V_237 )
{
struct V_1 * V_4 ;
int V_9 , V_19 ;
V_9 = F_103 ( V_13 , V_238 ) ;
if ( V_9 >= V_238 )
return F_27 ( - V_239 ) ;
F_104 ( V_9 , V_13 ) ;
V_4 = F_25 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_4 ) {
V_19 = - V_46 ;
goto V_26;
}
if ( ! V_237 ) {
V_4 -> V_240 = F_103 ( V_241 , V_238 ) ;
F_104 ( V_4 -> V_240 , V_241 ) ;
}
else
V_4 -> V_240 = ( (struct V_1 * )
F_14 ( V_234 ) -> V_6 ) -> V_240 ;
V_4 -> V_21 = F_100 ( V_60 ) ;
V_4 -> V_3 = F_105 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_19 = - V_46 ;
goto V_242;
}
F_106 ( & V_4 -> V_167 ) ;
F_107 ( & V_4 -> V_243 ) ;
V_4 -> V_7 = 1 ;
V_19 = F_108 ( & V_4 -> V_12 , V_60 , & V_4 -> V_167 , V_237 ) ;
if ( V_19 )
goto V_244;
V_4 -> V_12 . V_245 = F_99 ;
V_4 -> V_12 . V_64 = V_4 ;
V_4 -> V_3 -> V_246 = V_247 ;
V_4 -> V_3 -> V_11 = V_9 * V_10 ;
V_4 -> V_3 -> V_248 = & V_249 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_12 = V_4 -> V_12 . V_12 ;
V_4 -> V_3 -> V_250 = V_234 ;
F_18 ( V_4 -> V_3 , V_4 -> V_21 || V_236 ) ;
snprintf ( V_4 -> V_3 -> V_129 , sizeof( V_4 -> V_3 -> V_129 ) ,
L_20 , V_4 -> V_240 , V_237 ? V_237 : L_21 ) ;
F_109 ( V_4 -> V_12 . V_12 , 512 ) ;
F_110 ( V_4 -> V_3 , V_235 ) ;
if ( F_111 ( V_60 -> V_80 ) ) {
if ( F_47 ( V_60 ) ||
( F_93 ( V_60 ) &&
V_60 -> V_251 . V_252 & V_253 ) )
V_4 -> V_74 |= V_213 ;
}
if ( F_47 ( V_60 ) &&
V_4 -> V_74 & V_213 &&
( ( V_60 -> V_97 . V_176 & V_177 ) ||
V_60 -> V_97 . V_178 ) ) {
V_4 -> V_74 |= V_205 ;
F_112 ( V_4 -> V_12 . V_12 , V_231 | V_202 ) ;
}
return V_4 ;
V_244:
F_11 ( V_4 -> V_3 ) ;
V_242:
F_12 ( V_4 ) ;
V_26:
return F_27 ( V_19 ) ;
}
static struct V_1 * F_113 ( struct V_59 * V_60 )
{
T_8 V_235 ;
struct V_1 * V_4 ;
if ( ! F_93 ( V_60 ) && F_87 ( V_60 ) ) {
V_235 = V_60 -> V_97 . V_39 ;
} else {
V_235 = V_60 -> V_112 . V_254 << ( V_60 -> V_112 . V_255 - 9 ) ;
}
V_4 = F_102 ( V_60 , & V_60 -> V_15 , V_235 , false , NULL ) ;
return V_4 ;
}
static int F_114 ( struct V_59 * V_60 ,
struct V_1 * V_4 ,
unsigned int V_95 ,
T_8 V_235 ,
bool V_236 ,
const char * V_237 )
{
char V_256 [ 10 ] ;
struct V_1 * V_257 ;
V_257 = F_102 ( V_60 , F_115 ( V_4 -> V_3 ) , V_235 , V_236 ,
V_237 ) ;
if ( F_30 ( V_257 ) )
return F_31 ( V_257 ) ;
V_257 -> V_95 = V_95 ;
F_116 ( & V_257 -> V_243 , & V_4 -> V_243 ) ;
F_117 ( ( V_51 ) F_23 ( V_257 -> V_3 ) << 9 , V_258 ,
V_256 , sizeof( V_256 ) ) ;
F_118 ( L_22 ,
V_257 -> V_3 -> V_129 , F_119 ( V_60 ) ,
F_120 ( V_60 ) , V_257 -> V_95 , V_256 ) ;
return 0 ;
}
static int F_121 ( struct V_59 * V_60 , struct V_1 * V_4 )
{
int V_259 , V_19 = 0 ;
if ( ! F_47 ( V_60 ) )
return 0 ;
for ( V_259 = 0 ; V_259 < V_60 -> V_260 ; V_259 ++ ) {
if ( V_60 -> V_243 [ V_259 ] . V_235 ) {
V_19 = F_114 ( V_60 , V_4 ,
V_60 -> V_243 [ V_259 ] . V_261 ,
V_60 -> V_243 [ V_259 ] . V_235 >> 9 ,
V_60 -> V_243 [ V_259 ] . V_262 ,
V_60 -> V_243 [ V_259 ] . V_125 ) ;
if ( V_19 )
return V_19 ;
}
}
return V_19 ;
}
static int
F_122 ( struct V_1 * V_4 , struct V_59 * V_60 )
{
int V_44 ;
F_33 ( V_60 -> V_80 ) ;
V_44 = F_123 ( V_60 , 512 ) ;
F_41 ( V_60 -> V_80 ) ;
if ( V_44 ) {
F_57 ( L_23 ,
V_4 -> V_3 -> V_129 , V_44 ) ;
return - V_25 ;
}
return 0 ;
}
static void F_124 ( struct V_1 * V_4 )
{
if ( V_4 ) {
if ( V_4 -> V_3 -> V_74 & V_263 ) {
F_125 ( F_115 ( V_4 -> V_3 ) , & V_4 -> V_262 ) ;
F_126 ( V_4 -> V_3 ) ;
}
F_127 ( & V_4 -> V_12 ) ;
F_8 ( V_4 ) ;
}
}
static void F_128 ( struct V_59 * V_60 ,
struct V_1 * V_4 )
{
struct V_264 * V_265 , * V_266 ;
struct V_1 * V_257 ;
F_10 ( V_4 -> V_240 , V_241 ) ;
F_129 (pos, q, &md->part) {
V_257 = F_130 ( V_265 , struct V_1 , V_243 ) ;
F_131 ( V_265 ) ;
F_124 ( V_257 ) ;
}
}
static int F_132 ( struct V_1 * V_4 )
{
int V_19 ;
F_133 ( V_4 -> V_3 ) ;
V_4 -> V_262 . V_267 = F_13 ;
V_4 -> V_262 . V_268 = F_16 ;
F_134 ( & V_4 -> V_262 . V_17 ) ;
V_4 -> V_262 . V_17 . V_125 = L_24 ;
V_4 -> V_262 . V_17 . V_29 = V_269 | V_270 ;
V_19 = F_135 ( F_115 ( V_4 -> V_3 ) , & V_4 -> V_262 ) ;
if ( V_19 )
F_126 ( V_4 -> V_3 ) ;
return V_19 ;
}
static int F_136 ( struct V_59 * V_60 )
{
struct V_1 * V_4 , * V_257 ;
int V_44 ;
char V_256 [ 10 ] ;
if ( ! ( V_60 -> V_112 . V_232 & V_271 ) )
return - V_152 ;
V_4 = F_113 ( V_60 ) ;
if ( F_30 ( V_4 ) )
return F_31 ( V_4 ) ;
V_44 = F_122 ( V_4 , V_60 ) ;
if ( V_44 )
goto V_26;
F_117 ( ( V_51 ) F_23 ( V_4 -> V_3 ) << 9 , V_258 ,
V_256 , sizeof( V_256 ) ) ;
F_118 ( L_25 ,
V_4 -> V_3 -> V_129 , F_119 ( V_60 ) , F_120 ( V_60 ) ,
V_256 , V_4 -> V_21 ? L_26 : L_21 ) ;
if ( F_121 ( V_60 , V_4 ) )
goto V_26;
F_137 ( V_60 , V_4 ) ;
F_138 ( V_60 , V_272 ) ;
if ( F_132 ( V_4 ) )
goto V_26;
F_139 (part_md, &md->part, part) {
if ( F_132 ( V_257 ) )
goto V_26;
}
return 0 ;
V_26:
F_128 ( V_60 , V_4 ) ;
F_124 ( V_4 ) ;
return V_44 ;
}
static void F_140 ( struct V_59 * V_60 )
{
struct V_1 * V_4 = F_46 ( V_60 ) ;
F_128 ( V_60 , V_4 ) ;
F_33 ( V_60 -> V_80 ) ;
F_45 ( V_60 , V_4 ) ;
F_41 ( V_60 -> V_80 ) ;
F_124 ( V_4 ) ;
F_137 ( V_60 , NULL ) ;
}
static int F_141 ( struct V_59 * V_60 , T_9 V_273 )
{
struct V_1 * V_257 ;
struct V_1 * V_4 = F_46 ( V_60 ) ;
if ( V_4 ) {
F_142 ( & V_4 -> V_12 ) ;
F_139 (part_md, &md->part, part) {
F_142 ( & V_257 -> V_12 ) ;
}
}
return 0 ;
}
static int F_143 ( struct V_59 * V_60 )
{
struct V_1 * V_257 ;
struct V_1 * V_4 = F_46 ( V_60 ) ;
if ( V_4 ) {
F_122 ( V_4 , V_60 ) ;
V_4 -> V_94 = V_4 -> V_95 ;
F_144 ( & V_4 -> V_12 ) ;
F_139 (part_md, &md->part, part) {
F_144 ( & V_257 -> V_12 ) ;
}
}
return 0 ;
}
static int T_10 F_145 ( void )
{
int V_274 ;
if ( V_10 != V_275 )
F_118 ( L_27 , V_10 ) ;
V_238 = 256 / V_10 ;
V_274 = F_146 ( V_247 , L_28 ) ;
if ( V_274 )
goto V_26;
V_274 = F_147 ( & V_276 ) ;
if ( V_274 )
goto V_277;
return 0 ;
V_277:
F_148 ( V_247 , L_28 ) ;
V_26:
return V_274 ;
}
static void T_11 F_149 ( void )
{
F_150 ( & V_276 ) ;
F_148 ( V_247 , L_28 ) ;
}
