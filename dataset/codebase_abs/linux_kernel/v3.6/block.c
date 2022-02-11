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
static T_1 F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
int V_22 = 0 ;
if ( V_21 -> V_23 . V_24 & V_25 )
V_22 = 2 ;
else if ( V_21 -> V_23 . V_24 & V_26 )
V_22 = 1 ;
V_19 = snprintf ( V_18 , V_27 , L_1 , V_22 ) ;
return V_19 ;
}
static T_1 F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_28 )
{
int V_19 ;
struct V_1 * V_4 , * V_29 ;
struct V_20 * V_21 ;
unsigned long V_30 ;
if ( F_16 ( V_18 , 0 , & V_30 ) )
return - V_31 ;
if ( V_30 != 1 )
return V_28 ;
V_4 = F_1 ( F_14 ( V_15 ) ) ;
V_21 = V_4 -> V_12 . V_21 ;
F_17 ( V_21 -> V_32 ) ;
V_19 = F_18 ( V_21 , V_33 , V_34 ,
V_21 -> V_23 . V_24 |
V_26 ,
V_21 -> V_23 . V_35 ) ;
if ( V_19 )
F_19 ( L_2 , V_4 -> V_3 -> V_36 , V_19 ) ;
else
V_21 -> V_23 . V_24 |= V_26 ;
F_20 ( V_21 -> V_32 ) ;
if ( ! V_19 ) {
F_21 ( L_3 ,
V_4 -> V_3 -> V_36 ) ;
F_22 ( V_4 -> V_3 , 1 ) ;
F_23 (part_md, &md->part, part)
if ( V_29 -> V_37 == V_38 ) {
F_21 ( L_3 , V_29 -> V_3 -> V_36 ) ;
F_22 ( V_29 -> V_3 , 1 ) ;
}
}
F_8 ( V_4 ) ;
return V_28 ;
}
static T_1 F_24 ( struct V_14 * V_15 , struct V_16 * V_17 ,
char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
V_19 = snprintf ( V_18 , V_27 , L_4 ,
F_25 ( F_14 ( V_15 ) ) ^
V_4 -> V_39 ) ;
F_8 ( V_4 ) ;
return V_19 ;
}
static T_1 F_26 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const char * V_18 , T_2 V_28 )
{
int V_19 ;
char * V_40 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
unsigned long V_30 = F_27 ( V_18 , & V_40 , 0 ) ;
if ( V_40 == V_18 ) {
V_19 = - V_31 ;
goto V_41;
}
F_22 ( F_14 ( V_15 ) , V_30 || V_4 -> V_39 ) ;
V_19 = V_28 ;
V_41:
F_8 ( V_4 ) ;
return V_19 ;
}
static int F_28 ( struct V_42 * V_43 , T_3 V_44 )
{
struct V_1 * V_4 = F_1 ( V_43 -> V_45 ) ;
int V_19 = - V_46 ;
F_2 ( & V_47 ) ;
if ( V_4 ) {
if ( V_4 -> V_7 == 2 )
F_29 ( V_43 ) ;
V_19 = 0 ;
if ( ( V_44 & V_48 ) && V_4 -> V_39 ) {
F_8 ( V_4 ) ;
V_19 = - V_49 ;
}
}
F_3 ( & V_47 ) ;
return V_19 ;
}
static int F_30 ( struct V_2 * V_3 , T_3 V_44 )
{
struct V_1 * V_4 = V_3 -> V_6 ;
F_2 ( & V_47 ) ;
F_8 ( V_4 ) ;
F_3 ( & V_47 ) ;
return 0 ;
}
static int
F_31 ( struct V_42 * V_43 , struct V_50 * V_51 )
{
V_51 -> V_52 = F_32 ( V_43 -> V_45 ) / ( 4 * 16 ) ;
V_51 -> V_53 = 4 ;
V_51 -> V_54 = 16 ;
return 0 ;
}
static struct V_55 * F_33 (
struct V_56 T_4 * V_57 )
{
struct V_55 * V_58 ;
int V_59 ;
V_58 = F_34 ( sizeof( * V_58 ) , V_60 ) ;
if ( ! V_58 ) {
V_59 = - V_61 ;
goto V_41;
}
if ( F_35 ( & V_58 -> V_62 , V_57 , sizeof( V_58 -> V_62 ) ) ) {
V_59 = - V_63 ;
goto V_64;
}
V_58 -> V_65 = ( V_66 ) V_58 -> V_62 . V_67 * V_58 -> V_62 . V_68 ;
if ( V_58 -> V_65 > V_69 ) {
V_59 = - V_70 ;
goto V_64;
}
if ( ! V_58 -> V_65 )
return V_58 ;
V_58 -> V_18 = F_34 ( V_58 -> V_65 , V_60 ) ;
if ( ! V_58 -> V_18 ) {
V_59 = - V_61 ;
goto V_64;
}
if ( F_35 ( V_58 -> V_18 , ( void T_4 * ) ( unsigned long )
V_58 -> V_62 . V_71 , V_58 -> V_65 ) ) {
V_59 = - V_63 ;
goto V_72;
}
return V_58 ;
V_72:
F_12 ( V_58 -> V_18 ) ;
V_64:
F_12 ( V_58 ) ;
V_41:
return F_36 ( V_59 ) ;
}
static int F_37 ( struct V_42 * V_43 ,
struct V_56 T_4 * V_73 )
{
struct V_55 * V_58 ;
struct V_1 * V_4 ;
struct V_20 * V_21 ;
struct V_74 V_75 = { 0 } ;
struct V_76 V_77 = { 0 } ;
struct V_78 V_79 = { NULL } ;
struct V_80 V_81 ;
int V_59 ;
if ( ( ! F_38 ( V_82 ) ) || ( V_43 != V_43 -> V_83 ) )
return - V_84 ;
V_58 = F_33 ( V_73 ) ;
if ( F_39 ( V_58 ) )
return F_40 ( V_58 ) ;
V_4 = F_1 ( V_43 -> V_45 ) ;
if ( ! V_4 ) {
V_59 = - V_31 ;
goto V_85;
}
V_21 = V_4 -> V_12 . V_21 ;
if ( F_39 ( V_21 ) ) {
V_59 = F_40 ( V_21 ) ;
goto V_86;
}
V_75 . V_87 = V_58 -> V_62 . V_87 ;
V_75 . V_88 = V_58 -> V_62 . V_88 ;
V_75 . V_89 = V_58 -> V_62 . V_89 ;
if ( V_58 -> V_65 ) {
V_77 . V_81 = & V_81 ;
V_77 . V_90 = 1 ;
V_77 . V_67 = V_58 -> V_62 . V_67 ;
V_77 . V_68 = V_58 -> V_62 . V_68 ;
F_41 ( V_77 . V_81 , V_58 -> V_18 , V_58 -> V_65 ) ;
if ( V_58 -> V_62 . V_91 )
V_77 . V_89 = V_92 ;
else
V_77 . V_89 = V_93 ;
F_42 ( & V_77 , V_21 ) ;
if ( V_58 -> V_62 . V_94 )
V_77 . V_95 = V_58 -> V_62 . V_94 ;
if ( ( V_75 . V_89 & V_96 ) == V_96 ) {
V_77 . V_95 = V_58 -> V_62 . V_97 * 1000000 ;
}
V_79 . V_77 = & V_77 ;
}
V_79 . V_75 = & V_75 ;
F_17 ( V_21 -> V_32 ) ;
if ( V_58 -> V_62 . V_98 ) {
V_59 = F_43 ( V_21 -> V_32 , V_21 ) ;
if ( V_59 )
goto V_99;
}
F_44 ( V_21 -> V_32 , & V_79 ) ;
if ( V_75 . error ) {
F_45 ( F_46 ( V_21 -> V_32 ) , L_5 ,
V_100 , V_75 . error ) ;
V_59 = V_75 . error ;
goto V_99;
}
if ( V_77 . error ) {
F_45 ( F_46 ( V_21 -> V_32 ) , L_6 ,
V_100 , V_77 . error ) ;
V_59 = V_77 . error ;
goto V_99;
}
if ( V_58 -> V_62 . V_101 )
F_47 ( V_58 -> V_62 . V_101 , V_58 -> V_62 . V_102 ) ;
if ( F_48 ( & ( V_73 -> V_103 ) , V_75 . V_104 , sizeof( V_75 . V_104 ) ) ) {
V_59 = - V_63 ;
goto V_99;
}
if ( ! V_58 -> V_62 . V_91 ) {
if ( F_48 ( ( void T_4 * ) ( unsigned long ) V_58 -> V_62 . V_71 ,
V_58 -> V_18 , V_58 -> V_65 ) ) {
V_59 = - V_63 ;
goto V_99;
}
}
V_99:
F_20 ( V_21 -> V_32 ) ;
V_86:
F_8 ( V_4 ) ;
V_85:
F_12 ( V_58 -> V_18 ) ;
F_12 ( V_58 ) ;
return V_59 ;
}
static int F_49 ( struct V_42 * V_43 , T_3 V_44 ,
unsigned int V_75 , unsigned long V_88 )
{
int V_19 = - V_31 ;
if ( V_75 == V_105 )
V_19 = F_37 ( V_43 , (struct V_56 T_4 * ) V_88 ) ;
return V_19 ;
}
static int F_50 ( struct V_42 * V_43 , T_3 V_44 ,
unsigned int V_75 , unsigned long V_88 )
{
return F_49 ( V_43 , V_44 , V_75 , ( unsigned long ) F_51 ( V_88 ) ) ;
}
static inline int F_52 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
int V_19 ;
struct V_1 * V_106 = F_53 ( V_21 ) ;
if ( V_106 -> V_107 == V_4 -> V_108 )
return 0 ;
if ( F_54 ( V_21 ) ) {
T_5 V_109 = V_21 -> V_23 . V_109 ;
V_109 &= ~ V_110 ;
V_109 |= V_4 -> V_108 ;
V_19 = F_18 ( V_21 , V_33 ,
V_111 , V_109 ,
V_21 -> V_23 . V_35 ) ;
if ( V_19 )
return V_19 ;
V_21 -> V_23 . V_109 = V_109 ;
}
V_106 -> V_107 = V_4 -> V_108 ;
return 0 ;
}
static T_6 F_55 ( struct V_20 * V_21 )
{
int V_59 ;
T_6 V_112 ;
T_7 * V_68 ;
struct V_78 V_79 = { NULL } ;
struct V_74 V_75 = { 0 } ;
struct V_76 V_77 = { 0 } ;
struct V_80 V_81 ;
V_75 . V_87 = V_113 ;
V_75 . V_88 = V_21 -> V_114 << 16 ;
V_75 . V_89 = V_115 | V_116 | V_117 ;
V_59 = F_56 ( V_21 -> V_32 , & V_75 , 0 ) ;
if ( V_59 )
return ( T_6 ) - 1 ;
if ( ! F_57 ( V_21 -> V_32 ) && ! ( V_75 . V_104 [ 0 ] & V_118 ) )
return ( T_6 ) - 1 ;
memset ( & V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 . V_87 = V_119 ;
V_75 . V_88 = 0 ;
V_75 . V_89 = V_115 | V_116 | V_120 ;
V_77 . V_67 = 4 ;
V_77 . V_68 = 1 ;
V_77 . V_89 = V_93 ;
V_77 . V_81 = & V_81 ;
V_77 . V_90 = 1 ;
F_42 ( & V_77 , V_21 ) ;
V_79 . V_75 = & V_75 ;
V_79 . V_77 = & V_77 ;
V_68 = F_58 ( 4 , V_60 ) ;
if ( ! V_68 )
return ( T_6 ) - 1 ;
F_41 ( & V_81 , V_68 , 4 ) ;
F_44 ( V_21 -> V_32 , & V_79 ) ;
V_112 = F_59 ( * V_68 ) ;
F_12 ( V_68 ) ;
if ( V_75 . error || V_77 . error )
V_112 = ( T_6 ) - 1 ;
return V_112 ;
}
static int F_60 ( struct V_20 * V_21 , T_6 * V_121 )
{
struct V_74 V_75 = { 0 } ;
int V_59 ;
V_75 . V_87 = V_122 ;
V_75 . V_89 = V_123 | V_96 | V_117 ;
V_59 = F_56 ( V_21 -> V_32 , & V_75 , 5 ) ;
if ( V_59 == 0 )
* V_121 = V_75 . V_104 [ 0 ] ;
return V_59 ;
}
static int F_61 ( struct V_20 * V_21 , T_6 * V_121 , int V_124 )
{
struct V_74 V_75 = { 0 } ;
int V_59 ;
V_75 . V_87 = V_125 ;
if ( ! F_57 ( V_21 -> V_32 ) )
V_75 . V_88 = V_21 -> V_114 << 16 ;
V_75 . V_89 = V_126 | V_116 | V_117 ;
V_59 = F_56 ( V_21 -> V_32 , & V_75 , V_124 ) ;
if ( V_59 == 0 )
* V_121 = V_75 . V_104 [ 0 ] ;
return V_59 ;
}
static int F_62 ( struct V_127 * V_128 , const char * V_129 , int error ,
bool V_130 , T_6 V_121 )
{
switch ( error ) {
case - V_131 :
F_19 ( L_7 ,
V_128 -> V_132 -> V_36 , L_8 ,
V_129 , V_121 ) ;
return V_133 ;
case - V_134 :
F_19 ( L_7 ,
V_128 -> V_132 -> V_36 , L_9 , V_129 , V_121 ) ;
if ( ! V_130 )
return V_133 ;
if ( V_121 & ( V_135 | V_136 ) )
return V_133 ;
return V_137 ;
default:
F_19 ( L_10 ,
V_128 -> V_132 -> V_36 , error , V_121 ) ;
return V_137 ;
}
}
static int F_63 ( struct V_20 * V_21 , struct V_127 * V_128 ,
struct V_138 * V_139 , int * V_140 )
{
bool V_141 = true ;
T_6 V_121 , V_142 = 0 ;
int V_59 , V_143 ;
if ( F_64 ( V_21 ) )
return V_144 ;
for ( V_143 = 2 ; V_143 >= 0 ; V_143 -- ) {
V_59 = F_61 ( V_21 , & V_121 , 0 ) ;
if ( ! V_59 )
break;
V_141 = false ;
F_19 ( L_11 ,
V_128 -> V_132 -> V_36 , V_59 , V_143 ? L_12 : L_13 ) ;
}
if ( V_59 ) {
if ( F_65 ( V_21 -> V_32 ) )
return V_144 ;
return V_137 ;
}
if ( ( V_121 & V_145 ) ||
( V_139 -> V_146 . V_104 [ 0 ] & V_145 ) ||
( V_139 -> V_75 . V_104 [ 0 ] & V_145 ) )
* V_140 = 1 ;
if ( F_66 ( V_121 ) == V_147 ||
F_66 ( V_121 ) == V_148 ) {
V_59 = F_60 ( V_21 , & V_142 ) ;
if ( V_59 )
F_19 ( L_14 ,
V_128 -> V_132 -> V_36 , V_59 ) ;
if ( V_59 )
return V_137 ;
if ( V_142 & V_145 )
* V_140 = 1 ;
}
if ( V_139 -> V_149 . error )
return F_62 ( V_128 , L_15 , V_139 -> V_149 . error ,
V_141 , V_121 ) ;
if ( V_139 -> V_75 . error )
return F_62 ( V_128 , L_16 , V_139 -> V_75 . error ,
V_141 , V_121 ) ;
if ( ! V_139 -> V_146 . error )
return V_150 ;
F_19 ( L_17 ,
V_128 -> V_132 -> V_36 , V_139 -> V_146 . error ,
V_139 -> V_75 . V_104 [ 0 ] , V_121 ) ;
if ( V_142 ) {
V_139 -> V_146 . V_104 [ 0 ] = V_142 ;
V_139 -> V_146 . error = 0 ;
}
return V_150 ;
}
static int F_67 ( struct V_1 * V_4 , struct V_151 * V_32 ,
int type )
{
int V_59 ;
if ( V_4 -> V_152 & type )
return - V_153 ;
V_4 -> V_152 |= type ;
V_59 = F_68 ( V_32 ) ;
if ( V_59 != - V_154 ) {
struct V_1 * V_106 = F_53 ( V_32 -> V_21 ) ;
int V_155 ;
V_106 -> V_107 = V_106 -> V_108 ;
V_155 = F_52 ( V_32 -> V_21 , V_4 ) ;
if ( V_155 ) {
return - V_156 ;
}
}
return V_59 ;
}
static inline void F_69 ( struct V_1 * V_4 , int type )
{
V_4 -> V_152 &= ~ type ;
}
static int F_70 ( struct V_157 * V_158 , struct V_127 * V_128 )
{
struct V_1 * V_4 = V_158 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
unsigned int V_159 , V_160 , V_88 ;
int V_59 = 0 , type = V_161 ;
if ( ! F_71 ( V_21 ) ) {
V_59 = - V_154 ;
goto V_41;
}
V_159 = F_72 ( V_128 ) ;
V_160 = F_73 ( V_128 ) ;
if ( F_74 ( V_21 ) )
V_88 = V_162 ;
else if ( F_75 ( V_21 ) )
V_88 = V_163 ;
else
V_88 = V_164 ;
V_143:
if ( V_21 -> V_165 & V_166 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_167 ,
V_88 == V_163 ?
V_168 :
V_169 ,
0 ) ;
if ( V_59 )
goto V_41;
}
V_59 = F_76 ( V_21 , V_159 , V_160 , V_88 ) ;
V_41:
if ( V_59 == - V_170 && ! F_67 ( V_4 , V_21 -> V_32 , type ) )
goto V_143;
if ( ! V_59 )
F_69 ( V_4 , type ) ;
F_77 ( V_128 , V_59 , F_78 ( V_128 ) ) ;
return V_59 ? 0 : 1 ;
}
static int F_79 ( struct V_157 * V_158 ,
struct V_127 * V_128 )
{
struct V_1 * V_4 = V_158 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
unsigned int V_159 , V_160 , V_88 , V_171 , V_172 ;
int V_59 = 0 , type = V_173 ;
if ( ! ( F_80 ( V_21 ) || F_81 ( V_21 ) ) ) {
V_59 = - V_154 ;
goto V_41;
}
V_159 = F_72 ( V_128 ) ;
V_160 = F_73 ( V_128 ) ;
if ( F_81 ( V_21 ) ) {
V_172 = V_164 ;
V_171 = V_163 ;
} else {
V_172 = V_174 ;
V_171 = V_175 ;
}
if ( F_82 ( V_21 , V_159 , V_160 ) )
V_88 = V_172 ;
else if ( F_75 ( V_21 ) )
V_88 = V_171 ;
else {
V_59 = - V_31 ;
goto V_41;
}
V_143:
if ( V_21 -> V_165 & V_166 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_167 ,
V_88 == V_175 ?
V_176 :
V_177 ,
0 ) ;
if ( V_59 )
goto V_178;
}
V_59 = F_76 ( V_21 , V_159 , V_160 , V_88 ) ;
if ( V_59 == - V_170 )
goto V_178;
if ( V_59 )
goto V_41;
if ( V_88 == V_175 ) {
if ( V_21 -> V_165 & V_166 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_167 ,
V_179 ,
0 ) ;
if ( V_59 )
goto V_178;
}
V_59 = F_76 ( V_21 , V_159 , V_160 , V_180 ) ;
if ( V_59 == - V_170 )
goto V_178;
if ( V_59 )
goto V_41;
}
if ( F_81 ( V_21 ) )
V_59 = F_18 ( V_21 , V_33 ,
V_181 , 1 , 0 ) ;
V_178:
if ( V_59 && ! F_67 ( V_4 , V_21 -> V_32 , type ) )
goto V_143;
if ( ! V_59 )
F_69 ( V_4 , type ) ;
V_41:
F_77 ( V_128 , V_59 , F_78 ( V_128 ) ) ;
return V_59 ? 0 : 1 ;
}
static int F_83 ( struct V_157 * V_158 , struct V_127 * V_128 )
{
struct V_1 * V_4 = V_158 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
int V_19 = 0 ;
V_19 = F_84 ( V_21 ) ;
if ( V_19 )
V_19 = - V_170 ;
F_85 ( V_128 , V_19 ) ;
return V_19 ? 0 : 1 ;
}
static inline void F_86 ( struct V_138 * V_139 ,
struct V_20 * V_21 ,
struct V_127 * V_128 )
{
if ( ! ( V_21 -> V_23 . V_182 & V_183 ) ) {
if ( ! F_87 ( V_139 -> V_75 . V_88 , V_21 -> V_23 . V_184 ) )
V_139 -> V_77 . V_68 = 1 ;
if ( V_139 -> V_77 . V_68 > V_21 -> V_23 . V_184 )
V_139 -> V_77 . V_68 = V_21 -> V_23 . V_184 ;
else if ( V_139 -> V_77 . V_68 < V_21 -> V_23 . V_184 )
V_139 -> V_77 . V_68 = 1 ;
}
}
static int F_88 ( struct V_20 * V_21 ,
struct V_185 * V_186 )
{
struct V_187 * V_188 = F_89 ( V_186 , struct V_187 ,
V_189 ) ;
struct V_138 * V_139 = & V_188 -> V_139 ;
struct V_127 * V_128 = V_188 -> V_128 ;
int V_140 = 0 ;
if ( V_139 -> V_149 . error || V_139 -> V_75 . error || V_139 -> V_146 . error ||
V_139 -> V_77 . error ) {
switch ( F_63 ( V_21 , V_128 , V_139 , & V_140 ) ) {
case V_133 :
return V_190 ;
case V_137 :
return V_191 ;
case V_144 :
return V_192 ;
case V_150 :
break;
}
}
if ( V_139 -> V_75 . V_104 [ 0 ] & V_193 ) {
F_19 ( L_18 ,
V_128 -> V_132 -> V_36 , V_139 -> V_75 . V_104 [ 0 ] ) ;
return V_191 ;
}
if ( ! F_57 ( V_21 -> V_32 ) && F_90 ( V_128 ) != V_194 ) {
T_6 V_121 ;
do {
int V_59 = F_61 ( V_21 , & V_121 , 5 ) ;
if ( V_59 ) {
F_19 ( L_19 ,
V_128 -> V_132 -> V_36 , V_59 ) ;
return V_195 ;
}
} while ( ! ( V_121 & V_196 ) ||
( F_66 ( V_121 ) == V_197 ) );
}
if ( V_139 -> V_77 . error ) {
F_19 ( L_20 ,
V_128 -> V_132 -> V_36 , V_139 -> V_77 . error ,
( unsigned ) F_72 ( V_128 ) ,
( unsigned ) F_73 ( V_128 ) ,
V_139 -> V_75 . V_104 [ 0 ] , V_139 -> V_146 . V_104 [ 0 ] ) ;
if ( F_90 ( V_128 ) == V_194 ) {
if ( V_140 )
return V_198 ;
return V_199 ;
} else {
return V_195 ;
}
}
if ( ! V_139 -> V_77 . V_200 )
return V_190 ;
if ( F_78 ( V_128 ) != V_139 -> V_77 . V_200 )
return V_201 ;
return V_202 ;
}
static void F_91 ( struct V_187 * V_203 ,
struct V_20 * V_21 ,
int V_204 ,
struct V_157 * V_158 )
{
T_6 V_205 , V_206 ;
struct V_138 * V_139 = & V_203 -> V_139 ;
struct V_127 * V_128 = V_203 -> V_128 ;
struct V_1 * V_4 = V_158 -> V_77 ;
bool V_207 ;
bool V_208 = ( ( V_128 -> V_209 & V_210 ) ||
( V_128 -> V_209 & V_211 ) ) &&
( F_90 ( V_128 ) == V_212 ) &&
( V_4 -> V_89 & V_213 ) ;
memset ( V_139 , 0 , sizeof( struct V_138 ) ) ;
V_139 -> V_79 . V_75 = & V_139 -> V_75 ;
V_139 -> V_79 . V_77 = & V_139 -> V_77 ;
V_139 -> V_75 . V_88 = F_72 ( V_128 ) ;
if ( ! F_92 ( V_21 ) )
V_139 -> V_75 . V_88 <<= 9 ;
V_139 -> V_75 . V_89 = V_115 | V_116 | V_120 ;
V_139 -> V_77 . V_67 = 512 ;
V_139 -> V_146 . V_87 = V_122 ;
V_139 -> V_146 . V_88 = 0 ;
V_139 -> V_146 . V_89 = V_123 | V_96 | V_117 ;
V_139 -> V_77 . V_68 = F_73 ( V_128 ) ;
if ( V_139 -> V_77 . V_68 > V_21 -> V_32 -> V_214 )
V_139 -> V_77 . V_68 = V_21 -> V_32 -> V_214 ;
if ( V_139 -> V_77 . V_68 > 1 ) {
if ( V_204 )
V_139 -> V_77 . V_68 = 1 ;
if ( V_21 -> V_32 -> V_215 & V_216 &&
F_90 ( V_128 ) == V_194 )
V_139 -> V_77 . V_68 = 1 ;
}
if ( V_139 -> V_77 . V_68 > 1 || V_208 ) {
if ( ! F_57 ( V_21 -> V_32 ) ||
F_90 ( V_128 ) == V_194 )
V_139 -> V_79 . V_146 = & V_139 -> V_146 ;
V_205 = V_217 ;
V_206 = V_218 ;
} else {
V_139 -> V_79 . V_146 = NULL ;
V_205 = V_219 ;
V_206 = V_220 ;
}
if ( F_90 ( V_128 ) == V_194 ) {
V_139 -> V_75 . V_87 = V_205 ;
V_139 -> V_77 . V_89 |= V_93 ;
} else {
V_139 -> V_75 . V_87 = V_206 ;
V_139 -> V_77 . V_89 |= V_92 ;
}
if ( V_208 )
F_86 ( V_139 , V_21 , V_128 ) ;
V_207 = ( V_21 -> V_23 . V_221 ) &&
( V_128 -> V_209 & V_211 ) &&
( F_90 ( V_128 ) == V_212 ) &&
( ( V_139 -> V_77 . V_68 * V_139 -> V_77 . V_67 ) >=
V_21 -> V_23 . V_221 ) ;
if ( ( V_4 -> V_89 & V_222 ) && F_93 ( V_139 -> V_75 . V_87 ) &&
( V_208 || ! ( V_21 -> V_165 & V_223 ) ||
V_207 ) ) {
V_139 -> V_149 . V_87 = V_224 ;
V_139 -> V_149 . V_88 = V_139 -> V_77 . V_68 |
( V_208 ? ( 1 << 31 ) : 0 ) |
( V_207 ? ( 1 << 29 ) : 0 ) ;
V_139 -> V_149 . V_89 = V_116 | V_117 ;
V_139 -> V_79 . V_149 = & V_139 -> V_149 ;
}
F_42 ( & V_139 -> V_77 , V_21 ) ;
V_139 -> V_77 . V_81 = V_203 -> V_81 ;
V_139 -> V_77 . V_90 = F_94 ( V_158 , V_203 ) ;
if ( V_139 -> V_77 . V_68 != F_73 ( V_128 ) ) {
int V_225 , V_226 = V_139 -> V_77 . V_68 << 9 ;
struct V_80 * V_81 ;
F_95 (brq->data.sg, sg, brq->data.sg_len, i) {
V_226 -= V_81 -> V_227 ;
if ( V_226 <= 0 ) {
V_81 -> V_227 += V_226 ;
V_225 ++ ;
break;
}
}
V_139 -> V_77 . V_90 = V_225 ;
}
V_203 -> V_189 . V_79 = & V_139 -> V_79 ;
V_203 -> V_189 . V_228 = F_88 ;
F_96 ( V_203 ) ;
}
static int F_97 ( struct V_1 * V_4 , struct V_20 * V_21 ,
struct V_138 * V_139 , struct V_127 * V_128 ,
int V_19 )
{
if ( F_98 ( V_21 ) ) {
T_6 V_68 ;
V_68 = F_55 ( V_21 ) ;
if ( V_68 != ( T_6 ) - 1 ) {
V_19 = F_77 ( V_128 , 0 , V_68 << 9 ) ;
}
} else {
V_19 = F_77 ( V_128 , 0 , V_139 -> V_77 . V_200 ) ;
}
return V_19 ;
}
static int F_99 ( struct V_157 * V_158 , struct V_127 * V_229 )
{
struct V_1 * V_4 = V_158 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
struct V_138 * V_139 = & V_158 -> V_230 -> V_139 ;
int V_19 = 1 , V_204 = 0 , V_143 = 0 , type ;
enum V_231 V_121 ;
struct V_187 * V_232 ;
struct V_127 * V_128 = V_229 ;
struct V_185 * V_186 ;
if ( ! V_229 && ! V_158 -> V_233 -> V_128 )
return 0 ;
do {
if ( V_229 ) {
if ( ( V_139 -> V_77 . V_68 & 0x07 ) &&
( V_21 -> V_23 . V_234 == 4096 ) ) {
F_19 ( L_21 ,
V_128 -> V_132 -> V_36 ) ;
goto V_235;
}
F_91 ( V_158 -> V_230 , V_21 , 0 , V_158 ) ;
V_186 = & V_158 -> V_230 -> V_189 ;
} else
V_186 = NULL ;
V_186 = F_100 ( V_21 -> V_32 , V_186 , ( int * ) & V_121 ) ;
if ( ! V_186 )
return 0 ;
V_232 = F_89 ( V_186 , struct V_187 , V_189 ) ;
V_139 = & V_232 -> V_139 ;
V_128 = V_232 -> V_128 ;
type = F_90 ( V_128 ) == V_194 ? V_236 : V_237 ;
F_101 ( V_232 ) ;
switch ( V_121 ) {
case V_202 :
case V_201 :
F_69 ( V_4 , type ) ;
V_19 = F_77 ( V_128 , 0 ,
V_139 -> V_77 . V_200 ) ;
if ( V_121 == V_202 && V_19 ) {
F_19 ( L_22 ,
V_100 , F_78 ( V_128 ) ,
V_139 -> V_77 . V_200 ) ;
V_229 = NULL ;
goto V_235;
}
break;
case V_195 :
V_19 = F_97 ( V_4 , V_21 , V_139 , V_128 , V_19 ) ;
if ( ! F_67 ( V_4 , V_21 -> V_32 , type ) )
break;
goto V_235;
case V_190 :
if ( V_143 ++ < 5 )
break;
case V_191 :
if ( ! F_67 ( V_4 , V_21 -> V_32 , type ) )
break;
goto V_235;
case V_199 : {
int V_59 ;
V_59 = F_67 ( V_4 , V_21 -> V_32 , type ) ;
if ( ! V_59 )
break;
if ( V_59 == - V_156 )
goto V_235;
}
case V_198 :
if ( V_139 -> V_77 . V_68 > 1 ) {
F_102 ( L_23 ,
V_128 -> V_132 -> V_36 ) ;
V_204 = 1 ;
break;
}
V_19 = F_77 ( V_128 , - V_170 ,
V_139 -> V_77 . V_67 ) ;
if ( ! V_19 )
goto V_238;
break;
case V_192 :
goto V_235;
}
if ( V_19 ) {
F_91 ( V_232 , V_21 , V_204 , V_158 ) ;
F_100 ( V_21 -> V_32 , & V_232 -> V_189 , NULL ) ;
}
} while ( V_19 );
return 1 ;
V_235:
if ( F_64 ( V_21 ) )
V_128 -> V_209 |= V_239 ;
while ( V_19 )
V_19 = F_77 ( V_128 , - V_170 , F_103 ( V_128 ) ) ;
V_238:
if ( V_229 ) {
F_91 ( V_158 -> V_230 , V_21 , 0 , V_158 ) ;
F_100 ( V_21 -> V_32 , & V_158 -> V_230 -> V_189 , NULL ) ;
}
return 0 ;
}
static int F_104 ( struct V_157 * V_158 , struct V_127 * V_128 )
{
int V_19 ;
struct V_1 * V_4 = V_158 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
if ( V_128 && ! V_158 -> V_233 -> V_128 )
F_17 ( V_21 -> V_32 ) ;
V_19 = F_52 ( V_21 , V_4 ) ;
if ( V_19 ) {
if ( V_128 ) {
F_85 ( V_128 , - V_170 ) ;
}
V_19 = 0 ;
goto V_41;
}
if ( V_128 && V_128 -> V_209 & V_240 ) {
if ( V_21 -> V_32 -> V_186 )
F_99 ( V_158 , NULL ) ;
if ( V_128 -> V_209 & V_241 &&
! ( V_21 -> V_165 & V_242 ) )
V_19 = F_79 ( V_158 , V_128 ) ;
else
V_19 = F_70 ( V_158 , V_128 ) ;
} else if ( V_128 && V_128 -> V_209 & V_243 ) {
if ( V_21 -> V_32 -> V_186 )
F_99 ( V_158 , NULL ) ;
V_19 = F_83 ( V_158 , V_128 ) ;
} else {
V_19 = F_99 ( V_158 , V_128 ) ;
}
V_41:
if ( ! V_128 )
F_20 ( V_21 -> V_32 ) ;
return V_19 ;
}
static inline int F_105 ( struct V_20 * V_21 )
{
return F_106 ( V_21 ) ||
! ( V_21 -> V_244 . V_245 & V_246 ) ;
}
static struct V_1 * F_107 ( struct V_20 * V_21 ,
struct V_14 * V_247 ,
T_8 V_248 ,
bool V_249 ,
const char * V_250 ,
int V_37 )
{
struct V_1 * V_4 ;
int V_9 , V_19 ;
V_9 = F_108 ( V_13 , V_251 ) ;
if ( V_9 >= V_251 )
return F_36 ( - V_252 ) ;
F_109 ( V_9 , V_13 ) ;
V_4 = F_34 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_4 ) {
V_19 = - V_61 ;
goto V_41;
}
if ( ! V_250 ) {
V_4 -> V_253 = F_108 ( V_254 , V_251 ) ;
F_109 ( V_4 -> V_253 , V_254 ) ;
} else
V_4 -> V_253 = ( (struct V_1 * )
F_14 ( V_247 ) -> V_6 ) -> V_253 ;
V_4 -> V_37 = V_37 ;
V_4 -> V_39 = F_105 ( V_21 ) ;
V_4 -> V_3 = F_110 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_19 = - V_61 ;
goto V_255;
}
F_111 ( & V_4 -> V_256 ) ;
F_112 ( & V_4 -> V_257 ) ;
V_4 -> V_7 = 1 ;
V_19 = F_113 ( & V_4 -> V_12 , V_21 , & V_4 -> V_256 , V_250 ) ;
if ( V_19 )
goto V_258;
V_4 -> V_12 . V_259 = F_104 ;
V_4 -> V_12 . V_77 = V_4 ;
V_4 -> V_3 -> V_260 = V_261 ;
V_4 -> V_3 -> V_11 = V_9 * V_10 ;
V_4 -> V_3 -> V_262 = & V_263 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_12 = V_4 -> V_12 . V_12 ;
V_4 -> V_3 -> V_264 = V_247 ;
F_22 ( V_4 -> V_3 , V_4 -> V_39 || V_249 ) ;
snprintf ( V_4 -> V_3 -> V_36 , sizeof( V_4 -> V_3 -> V_36 ) ,
L_24 , V_4 -> V_253 , V_250 ? V_250 : L_25 ) ;
if ( F_54 ( V_21 ) )
F_114 ( V_4 -> V_12 . V_12 ,
V_21 -> V_23 . V_234 ) ;
else
F_114 ( V_4 -> V_12 . V_12 , 512 ) ;
F_115 ( V_4 -> V_3 , V_248 ) ;
if ( F_116 ( V_21 -> V_32 ) ) {
if ( F_54 ( V_21 ) ||
( F_98 ( V_21 ) &&
V_21 -> V_265 . V_266 & V_267 ) )
V_4 -> V_89 |= V_222 ;
}
if ( F_54 ( V_21 ) &&
V_4 -> V_89 & V_222 &&
( ( V_21 -> V_23 . V_182 & V_183 ) ||
V_21 -> V_23 . V_184 ) ) {
V_4 -> V_89 |= V_213 ;
F_117 ( V_4 -> V_12 . V_12 , V_243 | V_210 ) ;
}
return V_4 ;
V_258:
F_11 ( V_4 -> V_3 ) ;
V_255:
F_12 ( V_4 ) ;
V_41:
return F_36 ( V_19 ) ;
}
static struct V_1 * F_118 ( struct V_20 * V_21 )
{
T_8 V_248 ;
struct V_1 * V_4 ;
if ( ! F_98 ( V_21 ) && F_92 ( V_21 ) ) {
V_248 = V_21 -> V_23 . V_54 ;
} else {
V_248 = V_21 -> V_244 . V_268 << ( V_21 -> V_244 . V_269 - 9 ) ;
}
V_4 = F_107 ( V_21 , & V_21 -> V_15 , V_248 , false , NULL ,
V_270 ) ;
return V_4 ;
}
static int F_119 ( struct V_20 * V_21 ,
struct V_1 * V_4 ,
unsigned int V_108 ,
T_8 V_248 ,
bool V_249 ,
const char * V_250 ,
int V_37 )
{
char V_271 [ 10 ] ;
struct V_1 * V_29 ;
V_29 = F_107 ( V_21 , F_120 ( V_4 -> V_3 ) , V_248 , V_249 ,
V_250 , V_37 ) ;
if ( F_39 ( V_29 ) )
return F_40 ( V_29 ) ;
V_29 -> V_108 = V_108 ;
F_121 ( & V_29 -> V_257 , & V_4 -> V_257 ) ;
F_122 ( ( V_66 ) F_32 ( V_29 -> V_3 ) << 9 , V_272 ,
V_271 , sizeof( V_271 ) ) ;
F_21 ( L_26 ,
V_29 -> V_3 -> V_36 , F_123 ( V_21 ) ,
F_124 ( V_21 ) , V_29 -> V_108 , V_271 ) ;
return 0 ;
}
static int F_125 ( struct V_20 * V_21 , struct V_1 * V_4 )
{
int V_273 , V_19 = 0 ;
if ( ! F_54 ( V_21 ) )
return 0 ;
for ( V_273 = 0 ; V_273 < V_21 -> V_274 ; V_273 ++ ) {
if ( V_21 -> V_257 [ V_273 ] . V_248 ) {
V_19 = F_119 ( V_21 , V_4 ,
V_21 -> V_257 [ V_273 ] . V_275 ,
V_21 -> V_257 [ V_273 ] . V_248 >> 9 ,
V_21 -> V_257 [ V_273 ] . V_276 ,
V_21 -> V_257 [ V_273 ] . V_129 ,
V_21 -> V_257 [ V_273 ] . V_37 ) ;
if ( V_19 )
return V_19 ;
}
}
return V_19 ;
}
static void F_126 ( struct V_1 * V_4 )
{
struct V_20 * V_21 ;
if ( V_4 ) {
V_21 = V_4 -> V_12 . V_21 ;
if ( V_4 -> V_3 -> V_89 & V_277 ) {
F_127 ( F_120 ( V_4 -> V_3 ) , & V_4 -> V_276 ) ;
if ( ( V_4 -> V_37 & V_38 ) &&
V_21 -> V_23 . V_278 )
F_127 ( F_120 ( V_4 -> V_3 ) ,
& V_4 -> V_279 ) ;
F_128 ( V_4 -> V_3 ) ;
}
F_129 ( & V_4 -> V_12 ) ;
F_8 ( V_4 ) ;
}
}
static void F_130 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
struct V_280 * V_281 , * V_282 ;
struct V_1 * V_29 ;
F_10 ( V_4 -> V_253 , V_254 ) ;
F_131 (pos, q, &md->part) {
V_29 = F_132 ( V_281 , struct V_1 , V_257 ) ;
F_133 ( V_281 ) ;
F_126 ( V_29 ) ;
}
}
static int F_134 ( struct V_1 * V_4 )
{
int V_19 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
F_135 ( V_4 -> V_3 ) ;
V_4 -> V_276 . V_283 = F_24 ;
V_4 -> V_276 . V_284 = F_26 ;
F_136 ( & V_4 -> V_276 . V_17 ) ;
V_4 -> V_276 . V_17 . V_129 = L_27 ;
V_4 -> V_276 . V_17 . V_44 = V_285 | V_286 ;
V_19 = F_137 ( F_120 ( V_4 -> V_3 ) , & V_4 -> V_276 ) ;
if ( V_19 )
goto V_287;
if ( ( V_4 -> V_37 & V_38 ) &&
V_21 -> V_23 . V_278 ) {
T_9 V_44 ;
if ( V_21 -> V_23 . V_24 & V_288 )
V_44 = V_285 ;
else
V_44 = V_285 | V_286 ;
V_4 -> V_279 . V_283 = F_13 ;
V_4 -> V_279 . V_284 = F_15 ;
F_136 ( & V_4 -> V_279 . V_17 ) ;
V_4 -> V_279 . V_17 . V_44 = V_44 ;
V_4 -> V_279 . V_17 . V_129 =
L_28 ;
V_19 = F_137 ( F_120 ( V_4 -> V_3 ) ,
& V_4 -> V_279 ) ;
if ( V_19 )
goto V_289;
}
return V_19 ;
V_289:
F_127 ( F_120 ( V_4 -> V_3 ) , & V_4 -> V_276 ) ;
V_287:
F_128 ( V_4 -> V_3 ) ;
return V_19 ;
}
static int F_138 ( struct V_20 * V_21 )
{
struct V_1 * V_4 , * V_29 ;
char V_271 [ 10 ] ;
if ( ! ( V_21 -> V_244 . V_245 & V_290 ) )
return - V_156 ;
V_4 = F_118 ( V_21 ) ;
if ( F_39 ( V_4 ) )
return F_40 ( V_4 ) ;
F_122 ( ( V_66 ) F_32 ( V_4 -> V_3 ) << 9 , V_272 ,
V_271 , sizeof( V_271 ) ) ;
F_21 ( L_29 ,
V_4 -> V_3 -> V_36 , F_123 ( V_21 ) , F_124 ( V_21 ) ,
V_271 , V_4 -> V_39 ? L_30 : L_25 ) ;
if ( F_125 ( V_21 , V_4 ) )
goto V_41;
F_139 ( V_21 , V_4 ) ;
F_140 ( V_21 , V_291 ) ;
if ( F_134 ( V_4 ) )
goto V_41;
F_23 (part_md, &md->part, part) {
if ( F_134 ( V_29 ) )
goto V_41;
}
return 0 ;
V_41:
F_130 ( V_21 , V_4 ) ;
F_126 ( V_4 ) ;
return 0 ;
}
static void F_141 ( struct V_20 * V_21 )
{
struct V_1 * V_4 = F_53 ( V_21 ) ;
F_130 ( V_21 , V_4 ) ;
F_17 ( V_21 -> V_32 ) ;
F_52 ( V_21 , V_4 ) ;
F_20 ( V_21 -> V_32 ) ;
F_126 ( V_4 ) ;
F_139 ( V_21 , NULL ) ;
}
static int F_142 ( struct V_20 * V_21 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_53 ( V_21 ) ;
if ( V_4 ) {
F_143 ( & V_4 -> V_12 ) ;
F_23 (part_md, &md->part, part) {
F_143 ( & V_29 -> V_12 ) ;
}
}
return 0 ;
}
static int F_144 ( struct V_20 * V_21 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_53 ( V_21 ) ;
if ( V_4 ) {
V_4 -> V_107 = V_4 -> V_108 ;
F_145 ( & V_4 -> V_12 ) ;
F_23 (part_md, &md->part, part) {
F_145 ( & V_29 -> V_12 ) ;
}
}
return 0 ;
}
static int T_10 F_146 ( void )
{
int V_292 ;
if ( V_10 != V_293 )
F_21 ( L_31 , V_10 ) ;
V_251 = 256 / V_10 ;
V_292 = F_147 ( V_261 , L_32 ) ;
if ( V_292 )
goto V_41;
V_292 = F_148 ( & V_294 ) ;
if ( V_292 )
goto V_295;
return 0 ;
V_295:
F_149 ( V_261 , L_32 ) ;
V_41:
return V_292 ;
}
static void T_11 F_150 ( void )
{
F_151 ( & V_294 ) ;
F_149 ( V_261 , L_32 ) ;
}
